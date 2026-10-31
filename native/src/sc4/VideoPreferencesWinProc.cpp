#include "sc4/VideoPreferencesWinProc.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "gz/WinBtn.h"
#include "sc4/DialogWinProcs.h"

namespace sc4 {

namespace {
constexpr std::uint32_t kDialogInstance = 0x8a7e052f, kDialogWindowId = 0x2a57cb82;
constexpr std::uint32_t kNoticePage = 0x2a57cb83, kOptionsPage = 0x2a57cb84;
constexpr std::uint32_t kAccept = 0xea57da59, kNoticeAccept = 0xea57da6f, kCancel = 0x6a57da48, kDefaults = 0xea5e99d9;
constexpr std::uint32_t kBtnActivated = 0x287259f6, kMessagePreferencesChanged = 0x231bbf91;
constexpr std::uint32_t kWinFlagKeepFocus = 0x1000, kWinFlagVisible = 1, kEndDialogCode = 0xf;
constexpr std::size_t kBlock = 0xf0c, kBlockSize = 0x20;   // SC4VideoPreferences in the preference blob

bool g_displayed = false;
VideoPreferencesServices g_services;

// The Low / Medium / High rows and the other radio groups: the byte (absolute offset) and the value of each button.
struct Choice { std::uint32_t id; std::size_t offset; std::uint32_t value; };
constexpr Choice kChoices[] = {
    {0x6a57da49, 0xf0d, 1}, {0x6a57da4a, 0xf0d, 2}, {0x6a57da4b, 0xf0d, 3},        // visual effects
    {0x6a57da4c, 0xf0e, 1}, {0x6a57da4d, 0xf0e, 2}, {0x6a57da4e, 0xf0e, 3},        // cars / sims
    {0x6a57da4f, 0xf0f, 1}, {0x6a57da50, 0xf0f, 2}, {0x6a57da51, 0xf0f, 3},        // shadows
    {0xab81ded5, 0xf28, 1}, {0xab81ded6, 0xf28, 2}, {0xab81ded7, 0xf28, 3},        // building draw speed
    {0x0b85cf92, 0xf10, 1}, {0x2b85cf9f, 0xf10, 2}, {0x2b85cfaa, 0xf10, 3},        // texture quality
    {0x2ab6c373, 0xf16, 1}, {0x2ab6c374, 0xf16, 2}, {0x2ab6c375, 0xf16, 3},        // city detail
    {0x2ab6c376, 0xf24, 16}, {0x2ab6c377, 0xf24, 32},                              // colour quality (a u32)
    {0x6a57da57, 0xf13, 1}, {0x6a57da58, 0xf13, 0},                                // renderer: hardware, software
};
// The resolution buttons (+0xf1c width, +0xf20 height, u32 each): the host's choices 0..3.
constexpr std::uint32_t kResolutionIds[4] = {0x6a57da5a, 0x6a57da5b, 0x6a57da5c, 0x6a57da5d};
bool ResolutionAt(int index, std::uint32_t& width, std::uint32_t& height) {
    int w = 0, h = 0;
    if (!g_services.resolution || !g_services.resolution(index, w, h)) return false;
    width = static_cast<std::uint32_t>(w);
    height = static_cast<std::uint32_t>(h);
    return true;
}
// The check boxes: on = 1.
struct Check { std::uint32_t id; std::size_t offset; };
constexpr Check kChecks[] = {{0x6a57da54, 0xf11}, {0x6a57da55, 0xf12}, {0x6a57da60, 0xf14}, {0x6a57da56, 0xf15}, {0x0a8b7e00, 0xf18}};
// The settings that only take effect at the next start (the dialog's notice says so).
constexpr std::size_t kRestartFields[] = {0xf13, 0xf14, 0xf15, 0xf16, 0xf1c, 0xf20, 0xf24};


std::uint32_t Read(const std::uint8_t* p, std::size_t at, bool wide) {
    if (!wide) return p[at];
    std::uint32_t v = 0;
    std::memcpy(&v, p + at, 4);
    return v;
}
void Write(std::uint8_t* p, std::size_t at, bool wide, std::uint32_t v) {
    if (!wide) p[at] = static_cast<std::uint8_t>(v);
    else std::memcpy(p + at, &v, 4);
}
bool Wide(std::size_t at) { return at == 0xf24 || at == 0xf1c || at == 0xf20; }

gz::cIGZWinBtn* Button(cIGZWin* window, std::uint32_t id) {
    gz::cIGZWinBtn* out = nullptr;
    if (!window || !window->GetChildAsRecursive(id, gz::kGZIID_cIGZWinBtn, reinterpret_cast<void**>(&out)) || !out) return nullptr;
    out->Release();   // borrowed: the window keeps it
    return out;
}
void SetOn(cIGZWin* window, std::uint32_t id, bool on) {
    if (gz::cIGZWinBtn* button = Button(window, id)) on ? button->ToggleOn() : button->ToggleOff();
}
bool IsOn(cIGZWin* window, std::uint32_t id) {
    gz::cIGZWinBtn* button = Button(window, id);
    return button && button->IsOn();
}
}  // namespace

VideoPreferencesServices& GetVideoPreferencesServices() { return g_services; }
bool cSC4VideoPreferencesWinProc::Displayed() { return g_displayed; }

bool cSC4VideoPreferencesWinProc::QueryInterface(std::uint32_t iid, void** out) {
    if (iid != 1 && iid != 0x22e85d8e) return false;
    *out = this;
    AddRef();
    return true;
}

std::uint32_t cSC4VideoPreferencesWinProc::Release() {
    if (refCount_ > 1) return --refCount_;
    if (dialog_) dialog_->Release();
    delete this;
    return 0;
}

bool cSC4VideoPreferencesWinProc::ShowDialog() {
    if (g_displayed) return false;
    if (dialog_) {
        gz::cIGZWinGen* old = dialog_;
        dialog_ = nullptr;
        old->Release();
    }
    const cGZPersistResourceKey key{0, kUIScriptGroup, kDialogInstance};
    if (!SC4CreateWindowFromScript(key, nullptr, kDialogWindowId, gz::kGZIID_cIGZWinGen, reinterpret_cast<void**>(&dialog_)) || !dialog_)
        return false;
    g_displayed = true;
    cIGZWin* window = dialog_->AsIGZWin();
    if (cIGZWin* parent = window->GetParentWin()) {   // the dialog covers its parent (the original: 640 x 480 without one)
        window->SetW(parent->GetW());
        window->SetH(parent->GetH());
    }
    dialog_->SetWinProc(this);
    SetButtonsBasedOnPreferences();
    for (const Choice& c : kChoices) if (cIGZWin* w = window->GetChildWindowFromIDRecursive(c.id)) w->SetNotificationTarget(window);
    for (int i = 0; i < 4; ++i) {
        cIGZWin* w = window->GetChildWindowFromIDRecursive(kResolutionIds[i]);
        std::uint32_t width = 0, height = 0;
        if (!w) continue;
        w->SetNotificationTarget(window);
        if (!ResolutionAt(i, width, height)) w->SetFlag(2, false);   // no such choice for this window: disabled
    }
    for (const Check& c : kChecks) if (cIGZWin* w = window->GetChildWindowFromIDRecursive(c.id)) w->SetNotificationTarget(window);
    for (std::uint32_t id : {kAccept, kNoticeAccept, kCancel, kDefaults})
        if (cIGZWin* w = window->GetChildWindowFromIDRecursive(id)) w->SetNotificationTarget(window);
    if (cIGZWin* notice = window->GetChildWindowFromIDRecursive(kNoticePage)) notice->SetFlag(kWinFlagVisible, false);
    if (cIGZWin* options = window->GetChildWindowFromIDRecursive(kOptionsPage)) options->SetFlag(kWinFlagVisible, true);
    return true;
}

// The buttons from the block (Mac i386 0x002c0a86); remembers the block for the restart test.
void cSC4VideoPreferencesWinProc::SetButtonsBasedOnPreferences() {
    const std::uint8_t* p = g_services.preferences ? g_services.preferences() : nullptr;
    cIGZWin* window = dialog_ ? dialog_->AsIGZWin() : nullptr;
    if (!p || !window) return;
    std::memcpy(opened_, p + kBlock, kBlockSize);
    for (const Choice& c : kChoices) SetOn(window, c.id, Read(p, c.offset, Wide(c.offset)) == c.value);
    for (const Check& c : kChecks) SetOn(window, c.id, p[c.offset] != 0);
    const std::uint32_t running = g_services.currentHeight ? static_cast<std::uint32_t>(g_services.currentHeight()) : Read(p, 0xf20, true);
    for (int i = 0; i < 4; ++i) {   // the choice the game runs at now
        std::uint32_t width = 0, height = 0;
        SetOn(window, kResolutionIds[i], ResolutionAt(i, width, height) && height == running);
    }
}

// The block from the buttons (Mac i386 0x002bfd7c); notes whether a next-start setting changed.
void cSC4VideoPreferencesWinProc::SetPreferenceOptions() {
    std::uint8_t* p = g_services.preferences ? g_services.preferences() : nullptr;
    cIGZWin* window = dialog_ ? dialog_->AsIGZWin() : nullptr;
    if (!p || !window) return;
    for (const Choice& c : kChoices) if (IsOn(window, c.id)) Write(p, c.offset, Wide(c.offset), c.value);
    for (const Check& c : kChecks) p[c.offset] = IsOn(window, c.id) ? 1 : 0;
    for (int i = 0; i < 4; ++i) {
        std::uint32_t width = 0, height = 0;
        if (IsOn(window, kResolutionIds[i]) && ResolutionAt(i, width, height)) { Write(p, 0xf1c, true, width); Write(p, 0xf20, true, height); }
    }
    restartNeeded_ = false;
    for (std::size_t at : kRestartFields)
        if (Read(p, at, Wide(at)) != Read(opened_, at - kBlock, Wide(at))) restartNeeded_ = true;
    if (restartNeeded_) p[kBlock] = 1;   // the original's "changed" byte (+0xf0c) when the renderer switches
}

// Saves, applies, tells everyone and closes (the Accept tail of HandleControlMessage).
void cSC4VideoPreferencesWinProc::Finish() {
    std::uint8_t* p = g_services.preferences ? g_services.preferences() : nullptr;
    if (g_services.savePreferences) g_services.savePreferences();
    if (p && g_services.applyVideo) g_services.applyVideo(p + kBlock);
    if (g_services.postMessage) g_services.postMessage(kMessagePreferencesChanged);
    EndDialog();
}

bool cSC4VideoPreferencesWinProc::HandleControlMessage(std::uint32_t id) {   // Mac i386 0x002c24b8
    cIGZWin* window = dialog_ ? dialog_->AsIGZWin() : nullptr;
    if (!window) return true;
    if (std::getenv("SC4_DEBUG")) std::printf("graphic options: control %08x\n", id);
    if (id == kCancel) { EndDialog(); return true; }
    if (id == kNoticeAccept) { Finish(); return true; }
    if (id == kDefaults) {
        std::uint8_t* p = g_services.preferences ? g_services.preferences() : nullptr;
        if (p && g_services.automaticVideo) {
            std::uint8_t saved[kBlockSize];
            std::memcpy(saved, opened_, kBlockSize);
            g_services.automaticVideo(p + kBlock);
            SetButtonsBasedOnPreferences();
            std::memcpy(opened_, saved, kBlockSize);   // the restart test still compares with the block the dialog opened on
        }
        return true;
    }
    if (id == kAccept) {
        SetPreferenceOptions();
        if (restartNeeded_) {   // the notice first: its Accept finishes
            if (cIGZWin* options = window->GetChildWindowFromIDRecursive(kOptionsPage)) options->SetFlag(kWinFlagVisible, false);
            if (cIGZWin* notice = window->GetChildWindowFromIDRecursive(kNoticePage)) notice->SetFlag(kWinFlagVisible, true);
            return true;
        }
        Finish();
        return true;
    }
    // a radio button: it on, the rest of its group off
    auto group = [&](std::size_t offset) {
        for (const Choice& c : kChoices) if (c.offset == offset) SetOn(window, c.id, c.id == id);
    };
    for (const Choice& c : kChoices) if (c.id == id) { group(c.offset); return true; }
    for (std::uint32_t resolutionId : kResolutionIds)
        if (resolutionId == id) {
            for (std::uint32_t other : kResolutionIds) SetOn(window, other, other == id);
            return true;
        }
    return true;   // the check boxes toggle themselves
}

bool cSC4VideoPreferencesWinProc::DoWinProcMessage(cIGZWin* window, cGZMessage& message) {
    if (!dialog_ || window != dialog_->AsIGZWin() || !window->IsVisible()) return false;
    if (message.type == kGZMsgKeyDown && message.param1 == 0x1b) { HandleControlMessage(kCancel); return true; }
    if (message.type != kGZMsgCommand || static_cast<std::uint32_t>(message.param1) != kBtnActivated) return false;
    HandleControlMessage(static_cast<std::uint32_t>(message.param2));
    return true;
}

bool cSC4VideoPreferencesWinProc::DoModalWin() {
    VideoPreferencesServices& s = g_services;
    cIGZWinMgr* manager = s.windowManager ? s.windowManager() : nullptr;
    cIGZWin* window = dialog_ ? dialog_->AsIGZWin() : nullptr;
    if (!manager || !window) return false;
    if (s.gamePause) s.gamePause(true);
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

void cSC4VideoPreferencesWinProc::EndDialog() {
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
        dialog->Release();
    }
    g_displayed = false;
    Release();
}

}  // namespace sc4
