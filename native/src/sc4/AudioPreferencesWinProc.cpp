#include "sc4/AudioPreferencesWinProc.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <vector>

#include "gz/WinBtn.h"
#include "gz/WinGrid.h"
#include "gz/WinSlider.h"
#include "sc4/DialogWinProcs.h"
#include "sc4/Exemplar.h"
#include "sc4/SCPropertyHelp.h"
#include "sc4/SLBuffer.h"
#include "sc4/SLString.h"
#include "sc4/ServiceLocator.h"

namespace sc4 {

namespace {
constexpr std::uint32_t kDialogInstance = 0xca53f06e, kDialogWindowId = 0xea53f5db;
constexpr std::uint32_t kMusicCheck = 0x8a550c50, kMusicSlider = 0x8a550c51, kSoundCheck = 0x8a550c52, kSoundSlider = 0x8a550c53;
constexpr std::uint32_t kPlaylist = 0x8a550c56, kPreview = 0x8a550c57, kStop = 0x8a550c58, kCustomTunes = 0x8a550c5a;
constexpr std::uint32_t kCancel = 0xea5509e3, kAccept = 0xea5509e4;
constexpr std::uint32_t kBtnActivated = 0x287259f6, kBtnOnChanged = 0x287259f7, kBtnPressedChanged = 0x287259f8;
constexpr std::uint32_t kComboChanged = 0xe8711255, kGridSelectionChanged = 0x9a1552d2;
constexpr std::uint32_t kMessagePreferencesChanged = 0x231bbf91, kEndDialogCode = 0xf;
constexpr std::uint32_t kWinFlagKeepFocus = 0x1000, kWinFlagEnabled = 2;
constexpr std::uint32_t kSongStringGroup = 0x8a635d24, kButtonSound = 0x8a5c324a;
// The playlist rows' check boxes: built here (no script), one id per song. The original's two base ids are data
// (_sBaseControlID, DAT_00ab9ac0) that the decompilations do not show; any ids outside the script's own serve.
constexpr std::uint32_t kRowBaseId[2] = {0x8a5c3300, 0x8a5c3340};
constexpr int kMaxSongs = 30;

// The preference blob (absolute offsets; SC4AudioPreferences is the 0x67 bytes at +4).
constexpr std::size_t kAudioPrefs = 0x04, kAudioPrefsSize = 0x67;
constexpr std::size_t kSoundOn = 0x04, kSoundVolume = 0x08, kMusicVolume = 0x0c, kMusicOn = 0x10, kCustomTunesOn = 0x68;
constexpr std::size_t kEnableList[2] = {0x4a, 0x2c};   // GetMusicEnableList(mode)

struct PlaylistEntry {   // tSC4PlaylistEntry
    std::uint32_t controlId = 0, fileString = 0, nameString = 0;
    bool enabledByDefault = true;
    std::string file;    // the resolved file name (the file string)
};
struct AudioMode {       // __sAudioModeData, 0x2c bytes each
    std::uint32_t exemplar = 0;
    std::vector<PlaylistEntry> songs;
    std::string directory;   // "<GameData>/Radio/Stations/<station>/Music/"
};
AudioMode g_modes[2];

// Tuning ({0x6534284a, 0xca25875d, 0x6a359c5d}); kMinMusicVolume is never read from it.
std::uint32_t g_minSound = 0, g_maxSound = 1000, g_minMusic = 0, g_maxMusic = 1000, g_fadeOutMs = 0;

bool g_staticInitialized = false;
bool g_displayed = false;
AudioPreferencesServices g_services;

template <typename T> T Get(const std::uint8_t* p, std::size_t at) { T v; std::memcpy(&v, p + at, sizeof v); return v; }
template <typename T> void Put(std::uint8_t* p, std::size_t at, T v) { std::memcpy(p + at, &v, sizeof v); }

std::uint8_t* Prefs() { return g_services.preferences ? g_services.preferences() : nullptr; }

std::string Lower(std::string s) {
    for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s;
}

cISCPropertyHolder* AcquireExemplar(std::uint32_t instance, cISCResExemplar*& exemplar) {
    exemplar = nullptr;
    if (!SL::spRM) return nullptr;
    void* raw = nullptr;
    const cGZPersistResourceKey key{0x6534284a, 0xca25875d, instance};
    if (!SL::spRM->GetResource(key, 0xa52160f5, &raw, 0, nullptr) || !raw) return nullptr;
    exemplar = static_cast<cISCResExemplar*>(raw);
    return exemplar->AsISCPropertyHolder();
}

void ReadTunerVariables() {
    cISCResExemplar* exemplar = nullptr;
    if (cISCPropertyHolder* holder = AcquireExemplar(0x6a359c5d, exemplar)) {
        cSCPropertyHelp::GetPropertyValue(holder, 0x4a7cb3bb, g_minSound);
        cSCPropertyHelp::GetPropertyValue(holder, 0x4a7cb3bc, g_maxMusic);
        cSCPropertyHelp::GetPropertyValue(holder, 0x4a7cb3bd, g_maxSound);
        cSCPropertyHelp::GetPropertyValue(holder, 0x4a7cb3bf, g_fadeOutMs);
        exemplar->Release();
    }
}

void ReadPlaylistInfoFromExemplar(int mode) {
    AudioMode& m = g_modes[mode];
    m.songs.clear();
    cISCResExemplar* exemplar = nullptr;
    cISCPropertyHolder* holder = AcquireExemplar(m.exemplar, exemplar);
    if (!holder) return;
    for (int i = 0; i < kMaxSongs; ++i) {
        std::vector<std::uint32_t> values;
        if (!cSCPropertyHelp::GetPropertyValue(holder, 0x8a5e7b50u + static_cast<std::uint32_t>(i), values) || values.size() < 2) continue;
        PlaylistEntry e;
        e.controlId = kRowBaseId[mode] + static_cast<std::uint32_t>(i);
        e.nameString = values[0];
        e.fileString = values[1];
        e.enabledByDefault = values.size() < 3 || values[2] != 0;
        e.file = cSLString(kSongStringGroup, e.fileString, true).ToChar();
        m.songs.push_back(e);
    }
    exemplar->Release();
}

// The station folder whose Music holds the playlist's songs (the original joins literal path pieces; they are not in
// the decompilations, so the folder is the one where the first song's file is).
std::string FindStationDirectory(const AudioMode& m, const std::string& data) {
    for (const char* station : {"Region", "Mayor"}) {
        const std::string dir = data + "Radio/Stations/" + station + "/Music/";
        std::error_code error;
        for (const PlaylistEntry& e : m.songs)
            if (std::filesystem::exists(dir + e.file, error)) return dir;
    }
    return {};
}

// The playlists' station folders, once the data folder is known (the radio's song filter can ask before the dialog binds
// its services; the folders are then looked up on a later call).
void ResolveDirectories() {
    if (!g_services.dataDirectory) return;
    const std::string data = g_services.dataDirectory();
    for (AudioMode& m : g_modes)
        if (m.directory.empty() && !m.songs.empty()) {
            m.directory = FindStationDirectory(m, data);
            if (std::getenv("SC4_DEBUG")) std::printf("audio options: playlist folder \"%s\"\n", m.directory.c_str());
        }
}

void StaticInit() {
    if (g_staticInitialized) return;
    g_staticInitialized = true;
    g_displayed = false;
    ReadTunerVariables();
    g_modes[0].exemplar = 0x2a5e5854;
    g_modes[1].exemplar = 0x2a5e5855;
    for (int mode = 0; mode < 2; ++mode) {
        ReadPlaylistInfoFromExemplar(mode);
        if (std::getenv("SC4_DEBUG")) {
            std::printf("audio options: playlist %d: %zu songs in \"%s\"\n", mode, g_modes[mode].songs.size(), g_modes[mode].directory.c_str());
            for (const PlaylistEntry& e : g_modes[mode].songs)
                std::printf("  %08x \"%s\" / %08x \"%s\"\n", e.nameString, cSLString(kSongStringGroup, e.nameString, true).ToChar(), e.fileString, e.file.c_str());
        }
    }
    if (std::getenv("SC4_DEBUG"))
        std::printf("audio options: sound %u..%u music %u..%u fade %u ms\n", g_minSound, g_maxSound, g_minMusic, g_maxMusic, g_fadeOutMs);
}

// GetVolumeFromSliderValue: 0 and 1000 are the ends; between them the range scales linearly.
std::uint32_t VolumeFromSlider(std::uint32_t value, bool music) {
    const std::uint32_t lo = music ? g_minMusic : g_minSound, hi = music ? g_maxMusic : g_maxSound;
    if (value >= 1000) return hi;
    if (value == 0) return lo;
    const float scaled = std::max(0.0f, float(hi - lo) * float(value) / 1000.0f);
    return std::clamp(lo + static_cast<std::uint32_t>(scaled), lo, hi);
}
// InitDialog's inverse: the slider position of a stored volume (one below the minimum stores as 0).
std::uint32_t SliderFromVolume(std::uint32_t volume, bool music) {
    const std::uint32_t lo = music ? g_minMusic : g_minSound, hi = music ? g_maxMusic : g_maxSound;
    volume = std::min(volume, hi);
    if (volume <= lo) return 0;
    if (volume >= 1000) return 1000;
    return static_cast<std::uint32_t>(std::max(0.0f, float(volume - lo) * 1000.0f / float(hi - lo)));
}

template <typename T> T* Child(cIGZWin* window, std::uint32_t id, std::uint32_t iid) {
    T* out = nullptr;
    if (!window || !window->GetChildAsRecursive(id, iid, reinterpret_cast<void**>(&out)) || !out) return nullptr;
    out->Release();   // borrowed: the window keeps it alive
    return out;
}
gz::cIGZWinBtn* Button(cIGZWin* window, std::uint32_t id) { return Child<gz::cIGZWinBtn>(window, id, gz::kGZIID_cIGZWinBtn); }
void EnableChild(cIGZWin* window, std::uint32_t id, bool on) {
    if (cIGZWin* child = window ? window->GetChildWindowFromIDRecursive(id) : nullptr) child->SetFlag(kWinFlagEnabled, on);
}
}  // namespace

AudioPreferencesServices& GetAudioPreferencesServices() { return g_services; }
bool cSC4AudioPreferencesWinProc::Displayed() { return g_displayed; }

float cSC4AudioPreferencesWinProc::MusicGain(const std::uint8_t* p) {
    if (!p || !Get<std::uint32_t>(p, kMusicOn)) return 0.0f;
    return g_maxMusic ? std::min(1.0f, float(Get<std::uint32_t>(p, kMusicVolume)) / float(g_maxMusic)) : 1.0f;
}
float cSC4AudioPreferencesWinProc::SoundGain(const std::uint8_t* p) {
    if (!p || !p[kSoundOn]) return 0.0f;
    return g_maxSound ? std::min(1.0f, float(Get<std::uint32_t>(p, kSoundVolume)) / float(g_maxSound)) : 1.0f;
}

bool cSC4AudioPreferencesWinProc::IsSongEnabled(const std::string& path) {
    StaticInit();
    const std::uint8_t* p = Prefs();
    if (!p) return true;
    const std::string name = Lower(std::filesystem::path(path).filename().string());
    for (int mode = 0; mode < 2; ++mode) {
        const AudioMode& m = g_modes[mode];
        for (std::size_t i = 0; i < m.songs.size() && i < kMaxSongs; ++i)
            if (Lower(m.songs[i].file) == name) return p[kEnableList[mode] + i] != 0;
    }
    return true;
}

bool cSC4AudioPreferencesWinProc::QueryInterface(std::uint32_t iid, void** out) {
    if (iid != 1 && iid != 0x22e85d8e) return false;
    *out = this;
    AddRef();
    return true;
}

std::uint32_t cSC4AudioPreferencesWinProc::Release() {
    if (refCount_ > 1) return --refCount_;
    if (dialog_) dialog_->Release();
    delete this;
    return 0;
}

bool cSC4AudioPreferencesWinProc::ShowDialog() {
    StaticInit();
    ResolveDirectories();
    if (g_displayed) return true;
    ReadTunerVariables();
    if (dialog_) {
        gz::cIGZWinGen* old = dialog_;
        dialog_ = nullptr;
        old->Release();
    }
    const cGZPersistResourceKey key{0, kUIScriptGroup, kDialogInstance};
    if (!SC4CreateWindowFromScript(key, nullptr, kDialogWindowId, gz::kGZIID_cIGZWinGen, reinterpret_cast<void**>(&dialog_)) || !dialog_)
        return false;
    InitDialog();
    dialog_->SetWinProc(this);
    return true;
}

void cSC4AudioPreferencesWinProc::InitDialog() {
    g_displayed = true;
    std::uint8_t* p = Prefs();
    if (p) std::memcpy(saved_, p + kAudioPrefs, kAudioPrefsSize);
    cIGZWin* window = dialog_->AsIGZWin();
    EnableChild(window, kPreview, false);
    for (std::uint32_t id : {kPreview, kStop})
        if (cIGZWin* child = window->GetChildWindowFromIDRecursive(id)) child->SetNotificationTarget(window);
    if (gz::cIGZWinBtn* custom = Button(window, kCustomTunes)) {   // no custom tunes folder natively: shown off and disabled
        custom->SetChecked(false);
        custom->AsIGZWin()->SetFlag(kWinFlagEnabled, false);
    }
    if (gz::cIGZWinBtn* sound = Button(window, kSoundCheck)) {
        sound->SetChecked(p && p[kSoundOn] != 0);
        sound->AsIGZWin()->SetNotificationTarget(window);
    }
    if (gz::cIGZWinBtn* music = Button(window, kMusicCheck)) {
        music->SetChecked(p && Get<std::uint32_t>(p, kMusicOn) != 0);
        music->AsIGZWin()->SetNotificationTarget(window);
    }
    for (bool isMusic : {true, false}) {
        auto* slider = Child<gz::cIGZWinSlider>(window, isMusic ? kMusicSlider : kSoundSlider, gz::kGZIID_cIGZWinSlider);
        if (!slider) continue;
        slider->SetMinimumValue(0);
        slider->SetMaximumValue(1000);
        slider->AsIGZWin()->SetNotificationTarget(window);
        std::uint32_t volume = p ? Get<std::uint32_t>(p, isMusic ? kMusicVolume : kSoundVolume) : 0;
        const std::uint32_t lo = isMusic ? g_minMusic : g_minSound;
        if (p && volume < lo) Put<std::uint32_t>(p, isMusic ? kMusicVolume : kSoundVolume, volume = 0);
        slider->SetValue(static_cast<int>(SliderFromVolume(volume, isMusic)));
    }
    if (auto* grid = Child<gz::cIGZWinGrid>(window, kPlaylist, gz::kGZIID_cIGZWinGrid)) {
        grid_ = grid->AsIGZWin();
        grid->ClearSelection();
        grid->ClearAllCells();
        grid->ClearFlag(2);
        grid->ClearFlag(0x8000);
        grid->SetFlag(0x2000);
        grid->SetFlag(0x80000);
        grid->SetSelectionRules(2, 1);
        // the list's look (InitDialog, non-iTunes branch): a pale green-grey background, the selected song white on blue
        grid_->SetFillColor(0xed, 0xf3, 0xf0);
        grid_->SetFlag(0x20000, true);
        grid->SetDefaultFontColor(0xffedf3f0u, 1);
        grid->SetDefaultFontColor(0xff0000ffu, 5);
        grid->SetDefaultFontColor(0xffffffffu, 4);
        grid->SetColumnWidth(0, 1, 0xff);
        InsertMusicList(0, 0);
        InsertMusicList(1, static_cast<int>(g_modes[0].songs.size()));
        grid->ClearSelection();
        grid_->SetNotificationTarget(window);
    }
}

void cSC4AudioPreferencesWinProc::InsertMusicList(int mode, int firstRow) {
    const std::uint8_t* p = Prefs();
    auto* grid = Child<gz::cIGZWinGrid>(dialog_->AsIGZWin(), kPlaylist, gz::kGZIID_cIGZWinGrid);
    if (!p || !grid) return;
    cSLBuffer checkImage(cGZPersistResourceKey{0x856ddbac, 0x46a006b0, 0x14416244}, 1, false);
    checkImage.Load();
    const AudioMode& m = g_modes[mode];
    int row = firstRow;
    for (std::size_t i = 0; i < m.songs.size() && i < kMaxSongs; ++i, ++row) {
        const PlaylistEntry& e = m.songs[i];
        std::error_code error;
        const bool exists = !m.directory.empty() && std::filesystem::exists(m.directory + e.file, error);
        const cSLString name(kSongStringGroup, e.nameString, true);
        auto* button = new gz::cGZWinBtn(g_services.windowManager ? g_services.windowManager() : nullptr);
        button->AddRef();
        button->SetStyle(4, nullptr, nullptr);
        button->SetID(e.controlId);
        button->SetChecked(p[kEnableList[mode] + i] != 0);
        if (checkImage.GetBuffer()) button->SetBuffer(checkImage.GetBuffer());
        button->SetBtnFlag(gz::kBtnHasCaption, false);
        button->AsIGZWin()->SetNotificationTarget(dialog_->AsIGZWin());
        button->AsIGZWin()->SetFlag(kWinFlagEnabled, exists);
        button->SetSoundID(2, kButtonSound);
        grid->SetCellTextValue(0, row, name.ToChar(), name.Strlen(), 1, false);
        grid->SetCellWindow(1, row, button->AsIGZWin(), false, true, 1);
        button->Release();
    }
}

// The selected row's playlist and song (GetMusicSelectionIndex + GetPlayEntryFromSelection).
bool cSC4AudioPreferencesWinProc::SelectedSong(int& mode, int& index) {
    auto* grid = grid_ ? Child<gz::cIGZWinGrid>(dialog_->AsIGZWin(), kPlaylist, gz::kGZIID_cIGZWinGrid) : nullptr;
    if (!grid || grid->GetSelectionCount() <= 0) return false;
    gz::cIGZWinGrid::CellCoordinates cell;
    int count = 1;
    if (!grid->GetSelection(&cell, count) || count <= 0) return false;
    int row = cell.row;
    for (mode = 0; mode < 2; ++mode) {
        if (row < static_cast<int>(g_modes[mode].songs.size())) { index = row; return true; }
        row -= static_cast<int>(g_modes[mode].songs.size());
    }
    return false;
}

bool cSC4AudioPreferencesWinProc::DoModalWin() {
    AudioPreferencesServices& s = g_services;
    if (s.gamePause) s.gamePause(true);
    cIGZWinMgr* manager = s.windowManager ? s.windowManager() : nullptr;
    cIGZWin* window = dialog_ ? dialog_->AsIGZWin() : nullptr;
    if (!manager || !window) return false;
    cIGZWin* previousFocus = manager->GZGetFocus();
    window->AddRef();
    manager->GZSetFocus(window);
    manager->RunPopup(window);
    if (manager->IsWindowValid(previousFocus)) manager->GZSetFocus(previousFocus);
    EndDialog();
    window->Release();
    if (s.gamePause) s.gamePause(false);
    return true;
}

void cSC4AudioPreferencesWinProc::EndDialog() {
    if (!g_displayed) return;
    AddRef();
    if (dialog_) {
        cIGZWin* window = dialog_->AsIGZWin();
        if (cIGZWinMgr* manager = window->GetWindowManager()) {
            if (window->GetFlag(kWinFlagKeepFocus)) manager->EndDialog(kEndDialogCode, window, 1);
            manager->DestroyWindow(window);
        }
        gz::cIGZWinGen* dialog = dialog_;
        dialog_ = nullptr;
        grid_ = nullptr;
        dialog->Release();
    }
    g_displayed = false;
    if (g_services.resumeRadio) g_services.resumeRadio();
    Release();
}

bool cSC4AudioPreferencesWinProc::DoWinProcMessage(cIGZWin* window, cGZMessage& message) {
    if (!dialog_ || !window->IsVisible()) return false;
    if (window != dialog_->AsIGZWin() && window != grid_) return false;
    cIGZWin* dialog = dialog_->AsIGZWin();
    if (message.type == kGZMsgKeyDown) {
        if (message.param1 == 0x1b) HandleControlMessage(kCancel, dialog, 0);
        return false;
    }
    if (message.type == kGridSelectionChanged) {
        HandleControlMessage(kPlaylist, dialog, static_cast<std::uint32_t>(message.param3));
        return false;
    }
    if (message.type != kGZMsgCommand) return false;
    const auto id = static_cast<std::uint32_t>(message.param2);
    const auto value = static_cast<std::uint32_t>(message.param3);
    switch (static_cast<std::uint32_t>(message.param1)) {
    case kBtnPressedChanged:   // the sound box acts when released (so its own click is heard at the new setting)
        if (id == kSoundCheck && value == 0)
            if (gz::cIGZWinBtn* sound = Button(dialog, kSoundCheck)) HandleControlMessage(kSoundCheck, dialog, sound->IsOn() ? 1 : 0);
        return true;
    case kBtnActivated:
        if (id == kPreview || id == kStop || id == kCancel || id == kAccept) HandleControlMessage(id, dialog, value);
        return true;
    case kBtnOnChanged:
        if (id != kSoundCheck && id != kPreview && id != kStop && id != kCancel && id != kAccept) HandleControlMessage(id, dialog, value);
        return true;
    case gz::kGZSliderValueChanged:
        if (id == kMusicSlider || id == kSoundSlider) HandleControlMessage(id, dialog, value);
        return true;
    case kComboChanged:
        HandleControlMessage(id, dialog, value);
        return true;
    default:
        return true;
    }
}

bool cSC4AudioPreferencesWinProc::HandleControlMessage(std::uint32_t id, cIGZWin* window, std::uint32_t value) {
    AudioPreferencesServices& s = g_services;
    std::uint8_t* p = Prefs();
    if (!p) return true;
    auto apply = [&] { if (s.applyAudio) s.applyAudio(); };
    if (std::getenv("SC4_DEBUG")) std::printf("audio options: control %08x value %u\n", id, value);
    switch (id) {
    case kPlaylist: {   // a row was picked: Preview works for songs whose file is there
        EnableChild(window, kPreview, false);
        int mode = 0, index = 0;
        if (SelectedSong(mode, index)) {
            std::error_code error;
            const AudioMode& m = g_modes[mode];
            if (!m.directory.empty() && std::filesystem::exists(m.directory + m.songs[std::size_t(index)].file, error)) EnableChild(window, kPreview, true);
        }
        return true;
    }
    case kMusicSlider:
    case kSoundSlider: {
        auto* slider = Child<gz::cIGZWinSlider>(window, id, gz::kGZIID_cIGZWinSlider);
        if (!slider) return true;
        const bool music = id == kMusicSlider;
        const std::uint32_t volume = VolumeFromSlider(static_cast<std::uint32_t>(std::max(0, slider->GetValue())), music);
        Put<std::uint32_t>(p, music ? kMusicVolume : kSoundVolume, volume > (music ? g_minMusic : g_minSound) ? volume : 0);
        apply();
        return true;
    }
    case kMusicCheck:
        Put<std::uint32_t>(p, kMusicOn, value);
        apply();
        return true;
    case kSoundCheck:
        p[kSoundOn] = static_cast<std::uint8_t>(value);
        apply();
        return true;
    case kCustomTunes:
        p[kCustomTunesOn] = static_cast<std::uint8_t>(value);
        return true;
    case kPreview: {
        int mode = 0, index = 0;
        if (SelectedSong(mode, index) && s.playSong) s.playSong(g_modes[mode].directory + g_modes[mode].songs[std::size_t(index)].file);
        return true;
    }
    case kStop:
        if (s.stopRadio) s.stopRadio();
        return true;
    case kCancel:   // the audio preferences go back to what the dialog opened with
        std::memcpy(p + kAudioPrefs, saved_, kAudioPrefsSize);
        apply();
        if (s.postMessage) s.postMessage(kMessagePreferencesChanged);
        EndDialog();
        return true;
    case kAccept: {
        if (s.savePreferences) s.savePreferences();
        const std::string playing = s.currentSong ? s.currentSong() : std::string();
        if (!playing.empty() && !IsSongEnabled(playing) && s.stopRadio) s.stopRadio();
        apply();
        if (s.postMessage) s.postMessage(kMessagePreferencesChanged);
        EndDialog();
        return true;
    }
    default:
        break;
    }
    for (int mode = 0; mode < 2; ++mode) {   // a song's box: its byte in the playlist's enable list
        if (id >= kRowBaseId[mode] && id < kRowBaseId[mode] + kMaxSongs) {
            p[kEnableList[mode] + (id - kRowBaseId[mode])] = static_cast<std::uint8_t>(value);
            return true;
        }
    }
    return true;
}

}  // namespace sc4
