// The game's SDL clock and timer as the recovered code sees them: the test stub SDL.h (scripts/tests/stubs), whose timers never
// fire by themselves. The frame loop drives them through these two functions; this file is apart from game_main_linux.cpp
// because the stub's names clash with the real SDL3 the window uses.
#include <SDL.h>

#include <chrono>
#include <cstdio>
#include <cstdlib>

namespace linuxapp {

double NowMs() {
    using namespace std::chrono;
    return duration<double, std::milli>(steady_clock::now().time_since_epoch()).count();
}

// SDL_GetTicks for the stub SDL clock: milliseconds since start-up, never 0 (a cRZTimer started at tick 0 counts as stopped).
void UpdateStubTicks() {
    static const double start = NowMs();
    g_ticks = 1u + static_cast<std::uint32_t>(static_cast<std::uint64_t>(NowMs() - start));
}

// Fires the armed timer when its period has passed.
void PumpTimers() {
    static double armedAt = -1; static int armedId = 0;
    const double now = NowMs();
    UpdateStubTicks();
    if (g_activeTimerId != armedId) { armedId = g_activeTimerId; armedAt = armedId ? now : -1; }
    if (armedId && g_timerCallback && now - armedAt >= g_timerInterval) {
        if (std::getenv("SC4_DEBUG")) std::printf("debug: timer %d fires\n", armedId);
        auto cb = g_timerCallback; void* param = g_timerParam;
        armedId = 0; armedAt = -1;
        cb(g_timerInterval, param);
    }
}

}  // namespace linuxapp
