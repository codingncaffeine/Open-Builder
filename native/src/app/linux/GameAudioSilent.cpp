// GameAudio on Linux, for now: no output device, so Open() fails and the game runs silent (the Mac build plays through
// AVFoundation in GameAudio.mm). The rest are no-ops in case a caller holds an unopened instance.
#include "app/GameAudio.h"

GameAudio::~GameAudio() = default;
bool GameAudio::Open(const std::string&, std::string& error) { error = "no audio output on Linux yet"; return false; }
void GameAudio::NextAmbient() {}
void GameAudio::PlayClick() {}
bool GameAudio::PlayTrack(std::uint32_t) { return false; }
void GameAudio::SetStation(const std::string&) {}
void GameAudio::SetMuted(bool muted) { muted_ = muted; }
void GameAudio::Tick() {}
