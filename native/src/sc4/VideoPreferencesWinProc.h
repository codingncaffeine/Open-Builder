// cSC4VideoPreferencesWinProc — the "Graphic Options" dialog (13 functions; Mac i386 0x002bfa30..0x002c42f8, written from
// that decompilation, not byte-matched). Script {0, 0x96a006b0, 0x8a7e052f} (_sVideoWindowInfo), window id 0x2a57cb82; its
// two pages are 0x2a57cb84 (the options) and 0x2a57cb83 (the restart notice).
//
// The controls edit the SC4VideoPreferences block of the preference blob (+0xf0c, 0x20 bytes): Low / Medium / High rows
// (values 1..3) for visual effects +0xf0d, cars / sims +0xf0e, shadows +0xf0f, texture quality +0xf10, city detail +0xf16
// and building draw speed +0xf28; check boxes clouds / fog +0xf11, waves +0xf12, colour cursor +0xf14, UI translucency
// +0xf15, variable speed automata +0xf18; renderer +0xf13 (1 hardware), resolution +0xf1c / +0xf20, colour depth +0xf24.
// The resolution buttons offer the host's four choices (their labels come from the same list, LegacyControl's
// resolution captions); the original's fixed 800x600..1600x1200 do not fit modern windows.
// Accept writes the block, saves the preferences and has the application apply it (cISC4App::ApplyVideoPreferences);
// when a setting that only takes effect at the next start changed (renderer, resolution, colour depth, city detail, UI
// translucency, colour cursor), the restart notice page shows first and its own Accept finishes. Default Settings loads
// the application's automatic choice (GetAutoVideoPreferences). Cancel leaves the preferences alone.
#pragma once
#include <cstdint>
#include <functional>

#include "gz/WinGen.h"
#include "gz/WinProc.h"

namespace sc4 {

struct VideoPreferencesServices {
    std::function<cIGZWinMgr*()> windowManager;
    std::function<std::uint8_t*()> preferences;                 // SL::spPreferences (the 0x1734-byte blob)
    std::function<void()> savePreferences;                      // cISC4App::SavePreferences
    std::function<void(std::uint8_t* block)> applyVideo;        // cISC4App::ApplyVideoPreferences(blob + 0xf0c)
    std::function<void(std::uint8_t* block)> automaticVideo;    // cISC4App::GetAutoVideoPreferences(blob + 0xf0c)
    std::function<void(std::uint32_t type)> postMessage;        // SL::spMS2->MessagePost
    std::function<void(bool begin)> gamePause;
    // The resolution buttons: choice 0..3 (false when there is none) and the resolution running now (preselected).
    std::function<bool(int index, int& width, int& height)> resolution;
    std::function<int()> currentHeight;
};
VideoPreferencesServices& GetVideoPreferencesServices();

class cSC4VideoPreferencesWinProc final : public gz::cIGZWinProc {
public:
    bool QueryInterface(std::uint32_t iid, void** out) override;
    std::uint32_t AddRef() override { return ++refCount_; }
    std::uint32_t Release() override;
    bool DoWinProcMessage(cIGZWin* window, cGZMessage& message) override;

    bool ShowDialog();                                           // false when the script did not load or it is already up
    bool DoModalWin();
    void EndDialog();
    static bool Displayed();

private:
    void SetButtonsBasedOnPreferences();
    void SetPreferenceOptions();
    bool HandleControlMessage(std::uint32_t id);
    void Finish();

    std::uint32_t refCount_ = 0;
    gz::cIGZWinGen* dialog_ = nullptr;
    std::uint8_t opened_[0x20] = {};                             // the block as the dialog found it (the restart test)
    bool restartNeeded_ = false;
};

}  // namespace sc4
