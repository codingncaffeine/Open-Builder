// The macOS audio backend of GameAudio: AVAudioPlayer voices over PCM (wrapped as WAV) and MP3 files.
#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>

#include <cstring>
#include <vector>

#include "app/GameAudio.h"
#include "audio/platform/AudioPlatform.h"

namespace {

std::vector<std::uint8_t> MakeWav(const std::uint8_t* pcm, std::uint32_t size, std::uint16_t channels,
                                  std::uint32_t rate, std::uint16_t bits) {
    std::vector<std::uint8_t> w(44 + size);
    auto put32 = [&](std::size_t at, std::uint32_t v) { std::memcpy(&w[at], &v, 4); };
    auto put16 = [&](std::size_t at, std::uint16_t v) { std::memcpy(&w[at], &v, 2); };
    std::memcpy(&w[0], "RIFF", 4); put32(4, 36 + size); std::memcpy(&w[8], "WAVEfmt ", 8);
    put32(16, 16); put16(20, 1); put16(22, channels); put32(24, rate);
    put32(28, rate * channels * bits / 8); put16(32, static_cast<std::uint16_t>(channels * bits / 8)); put16(34, bits);
    std::memcpy(&w[36], "data", 4); put32(40, size);
    std::memcpy(&w[44], pcm, size);
    return w;
}

class AVVoice final : public AudioPlatform::IVoice {
public:
    explicit AVVoice(NSData* data, NSString* typeHint = nil) {
        NSError* err = nil;
        player_ = typeHint ? [[AVAudioPlayer alloc] initWithData:data fileTypeHint:typeHint error:&err]
                           : [[AVAudioPlayer alloc] initWithData:data error:&err];
        if (player_) [player_ prepareToPlay];
    }
    bool ok() const { return player_ != nil; }
    void Play(std::int32_t loops) override { player_.numberOfLoops = loops; [player_ play]; }
    void Stop() override { [player_ stop]; }
    bool IsPlaying() const override { return player_.playing; }
    void SetVolume(float v) override { player_.volume = v; }
    void SetPan(float p) override { player_.pan = p; }

private:
    AVAudioPlayer* player_ = nil;
};

class AVBackend final : public AudioPlatform::IBackend {
public:
    AudioPlatform::IVoice* CreatePcmVoice(const std::uint8_t* data, std::int32_t size, std::uint16_t channels,
                                          std::uint32_t rate, std::uint16_t bits) override {
        auto wav = MakeWav(data, static_cast<std::uint32_t>(size), channels, rate, bits);
        auto* voice = new AVVoice([NSData dataWithBytes:wav.data() length:wav.size()]);
        if (!voice->ok()) { delete voice; return nullptr; }
        return voice;
    }
    AudioPlatform::IVoice* CreateFileVoice(const char* path) override {
        NSData* data = [NSData dataWithContentsOfFile:[NSString stringWithUTF8String:path]];
        if (!data) return nullptr;
        auto* voice = new AVVoice(data, @"public.mp3");
        if (!voice->ok()) { delete voice; return nullptr; }
        return voice;
    }
    std::uint32_t AddTimer(std::uint32_t, AudioPlatform::TimerCallback, void*) override { return 0; }
    void RemoveTimer(std::uint32_t) override {}
};

}  // namespace

AudioPlatform::IBackend* CreatePlatformAudioBackend() { return new AVBackend(); }
