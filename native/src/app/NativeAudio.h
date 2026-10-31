// The game's sound ids on the native application: every `PlaySound(id)` of the recovered UI and tools ends here.
#pragma once
#include <cstdint>

class GameAudio;

namespace native {

void SetGameAudio(GameAudio* audio);          // the running sound output (null: silent)
GameAudio* CurrentGameAudio();
// The preference blob's audio settings (music / sound switches and volumes, the playlists' song boxes) onto the running
// sound output; called when the sound starts and by the Audio Options dialog as its controls change.
void ApplyAudioPreferences(const std::uint8_t* preferences);
void PlayGameSound(std::uint32_t soundId);    // a Hit track id of Sound.dat
void InstallButtonSounds();                   // the window buttons' sound service

}  // namespace native
