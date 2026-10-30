#include "classes/cRZRadio.h"
#include <stdlib.h>
#include <list>
#include "classes/cRZDiskRadioStation.h"

// Views of the objects the radio talks to (slots by their vtable offsets; only the ones used here are named).
struct Sound_acc3c0 {
    virtual bool QueryInterface(uint32_t riid, void* ppv);   // 0x0
    virtual void Pad01_Sound_acc3c0();
    virtual uint32_t Release();   // 0x8
    virtual void Pad03_Sound_acc3c0();
    virtual void Pad04_Sound_acc3c0();
    virtual void Pad05_Sound_acc3c0();
    virtual void V06(uint32_t a, uint32_t b, uint32_t c);   // 0x18
    virtual bool IsPlaying();   // 0x1c
    virtual void Stop();   // 0x20
    virtual void Pad09_Sound_acc3c0();
    virtual void Pad10_Sound_acc3c0();
    virtual void Pad11_Sound_acc3c0();
    virtual void Pad12_Sound_acc3c0();
    virtual void Pad13_Sound_acc3c0();
    virtual void Pad14_Sound_acc3c0();
    virtual void Pad15_Sound_acc3c0();
    virtual void Pad16_Sound_acc3c0();
    virtual void Pad17_Sound_acc3c0();
    virtual void Pad18_Sound_acc3c0();
    virtual void Pad19_Sound_acc3c0();
    virtual uint32_t V20();   // 0x50
    virtual void SetVolume(uint32_t volume);   // 0x54
    virtual void V22(uint32_t a, uint32_t b, uint32_t c);   // 0x58
    virtual bool V23();   // 0x5c
    virtual void Pad24_Sound_acc3c0();
    virtual void Pad25_Sound_acc3c0();
    virtual void Pad26_Sound_acc3c0();
    virtual void Pad27_Sound_acc3c0();
    virtual void Pad28_Sound_acc3c0();
    virtual void Pad29_Sound_acc3c0();
    virtual void Pad30_Sound_acc3c0();
    virtual void Pad31_Sound_acc3c0();
    virtual void Pad32_Sound_acc3c0();
    virtual void Pad33_Sound_acc3c0();
    virtual void Pad34_Sound_acc3c0();
    virtual void Pad35_Sound_acc3c0();
    virtual void V36(void* song, uint32_t flag);   // 0x90
};
struct Station_acc3c0 {
    virtual void Pad00_Station_acc3c0();
    virtual void Pad01_Station_acc3c0();
    virtual void Pad02_Station_acc3c0();
    virtual void V03();   // 0xc
    virtual void Pad04_Station_acc3c0();
    virtual bool OnIdle();   // 0x14
    virtual void V06(void* radio);   // 0x18
    virtual void Start();   // 0x1c
    virtual void Stop();   // 0x20
    virtual void V09(void* a);   // 0x24
    virtual void Pad10_Station_acc3c0();
    virtual void Pad11_Station_acc3c0();
    virtual void Pad12_Station_acc3c0();
    virtual void Pad13_Station_acc3c0();
    virtual void Pad14_Station_acc3c0();
    virtual void Pad15_Station_acc3c0();
    virtual void Pad16_Station_acc3c0();
    virtual void Pad17_Station_acc3c0();
    virtual void Pad18_Station_acc3c0();
    virtual void Pad19_Station_acc3c0();
    virtual void Pad20_Station_acc3c0();
    virtual void Pad21_Station_acc3c0();
    virtual void Pad22_Station_acc3c0();
    virtual void V23(uint32_t a);   // 0x5c
    uint8_t mPad04[0x20];
    bool mbTimerRunning;
};
struct Messages_acc3c0 {
    virtual void Pad00_Messages_acc3c0();
    virtual void Pad01_Messages_acc3c0();
    virtual void Pad02_Messages_acc3c0();
    virtual void Pad03_Messages_acc3c0();
    virtual void Pad04_Messages_acc3c0();
    virtual void V05(uint32_t id, void* a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);   // 0x14
    virtual void Pad06_Messages_acc3c0();
    virtual void Post(uint32_t id, uint32_t a, uint32_t b, uint32_t c, uint32_t d);   // 0x1c
    virtual void Pad08_Messages_acc3c0();
    virtual void Pad09_Messages_acc3c0();
    virtual void Pad10_Messages_acc3c0();
    virtual void Pad11_Messages_acc3c0();
    virtual void Pad12_Messages_acc3c0();
    virtual void Pad13_Messages_acc3c0();
    virtual void Pad14_Messages_acc3c0();
    virtual void V15(void* a);   // 0x3c
    virtual void V16(void* a);   // 0x40
};
struct Server_acc3c0 {
    virtual void Pad00_Server_acc3c0();
    virtual void Pad01_Server_acc3c0();
    virtual void Pad02_Server_acc3c0();
    virtual void Pad03_Server_acc3c0();
    virtual void Pad04_Server_acc3c0();
    virtual void Pad05_Server_acc3c0();
    virtual void Pad06_Server_acc3c0();
    virtual void Pad07_Server_acc3c0();
    virtual void Pad08_Server_acc3c0();
    virtual void V09(void* a);   // 0x24
    virtual void V10(void* a);   // 0x28
    virtual void V11(void* a);   // 0x2c
    virtual void V12(void* a);   // 0x30
};
struct Unknown_acc3c0 {
    virtual void Pad00_Unknown_acc3c0();
    virtual void Pad01_Unknown_acc3c0();
    virtual uint32_t Release();   // 0x8
    virtual void V03(uint32_t a, uint32_t b);   // 0xc
};
struct RadioView_acc3c0 {
    virtual void Pad00_RadioView_acc3c0();
    virtual void Pad01_RadioView_acc3c0();
    virtual void Pad02_RadioView_acc3c0();
    virtual void Pad03_RadioView_acc3c0();
    virtual void Pad04_RadioView_acc3c0();
    virtual void Pad05_RadioView_acc3c0();
    virtual void Pad06_RadioView_acc3c0();
    virtual void Pad07_RadioView_acc3c0();
    virtual void Pad08_RadioView_acc3c0();
    virtual void Pad09_RadioView_acc3c0();
    virtual void Pad10_RadioView_acc3c0();
    virtual void Pad11_RadioView_acc3c0();
    virtual void Pad12_RadioView_acc3c0();
    virtual void Pad13_RadioView_acc3c0();
    virtual void Pad14_RadioView_acc3c0();
    virtual void Pad15_RadioView_acc3c0();
    virtual void Pad16_RadioView_acc3c0();
    virtual void Pad17_RadioView_acc3c0();
    virtual void Pad18_RadioView_acc3c0();
    virtual void Pad19_RadioView_acc3c0();
    virtual void Pad20_RadioView_acc3c0();
    virtual void Pad21_RadioView_acc3c0();
    virtual void Pad22_RadioView_acc3c0();
    virtual void Pad23_RadioView_acc3c0();
    virtual void Pad24_RadioView_acc3c0();
    virtual void Pad25_RadioView_acc3c0();
    virtual void Pad26_RadioView_acc3c0();
    virtual void Pad27_RadioView_acc3c0();
    virtual void Pad28_RadioView_acc3c0();
    virtual void Pad29_RadioView_acc3c0();
    virtual void Pad30_RadioView_acc3c0();
    virtual void Pad31_RadioView_acc3c0();
    virtual void Pad32_RadioView_acc3c0();
    virtual void V33(void* song);   // 0x84
};

// The settings record the radio reads and writes (Slot35 / Slot36).
struct RadioSettings_acc3c0 {
    uint32_t mnVolume;
    uint32_t mnOn;
    uint32_t mnStation;
    uint32_t mnFlag0;
    uint32_t mnFlag1;
    uint32_t mnPad14;
    uint32_t mnFlag3;
    uint32_t mnValue;
};

// STUB: 0x008793ec
Server_acc3c0* Fn008793ec();

// FUNCTION: 0x008d2a09
bool cRZRadio::Slot04_ae1d24()
{
    if (mbInitialised) {
        Slot22_acc1f8(1);
        if (mpSoundSystem) {
            if (static_cast<Sound_acc3c0*>(mpSoundSystem)->IsPlaying()) {
                static_cast<Sound_acc3c0*>(mpSoundSystem)->Stop();
            }
            static_cast<Sound_acc3c0*>(mpSoundSystem)->Release();
        }
        Fn008793ec()->V10(this);
        Fn008793ec()->V12(this);
        if (mpMessages) {
            static_cast<Messages_acc3c0*>(mpMessages)->V16(static_cast<cUnk00a931c4*>(this));
        }
        mbInitialised = false;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008d2a6e score 14
bool cRZRadio::QueryInterface(uint32_t riid, void** ppv)
{
    if (riid == 1 || riid == 0xe0510260) {
        *ppv = static_cast<cUnk00acc1f8*>(this);
    } else if (riid == 0x287fb697) {
        *ppv = this;
    } else {
        return false;
    }
    AddRef();
    return true;
}
#endif

// FUNCTION: 0x008d2aaf
uint32_t cRZRadio::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x008d2ab6
unsigned int cRZRadio::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    FinalRelease();
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008d2acb score 4
void cRZRadio::FinalRelease()
{
    Slot04_ae1d24();
    delete static_cast<cUnk0090da1e*>(this);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008d2adf score 41
void cRZRadio::Slot35_acc1f8(uint32_t settings)
{
    RadioSettings_acc3c0* s = OB_PTR(RadioSettings_acc3c0, settings);
    bool on = s->mnOn != 0;
    mbFlag4c = s->mnFlag0 != 0;
    mbFlag4d = s->mnFlag1 != 0;
    mbFlag4e = s->mnFlag3 != 0;
    mnSettingValue = s->mnValue;
    Slot16_acc1f8(s->mnVolume);
    Slot14_acc1f8(s->mnStation);
    Slot23_acc1f8(on);
}
#endif

// FUNCTION: 0x008d2b3c
void cRZRadio::Slot36_acc1f8(uint32_t settings)
{
    RadioSettings_acc3c0* s = OB_PTR(RadioSettings_acc3c0, settings);
    s->mnVolume = mnVolume;
    s->mnOn = mbOn;
    s->mnStation = mnStation;
    s->mnFlag0 = mbFlag4c;
    s->mnFlag1 = mbFlag4d;
    s->mnFlag3 = mbFlag4e;
    s->mnValue = mnSettingValue;
}

// FUNCTION: 0x008d2b74
void cRZRadio::Slot27_acc1f8(uint32_t value, uint32_t which)
{
    if (which == 0) {
        mbFlag4c = *reinterpret_cast<bool*>(&value);
    } else if (which == 1) {
        mbFlag4d = *reinterpret_cast<bool*>(&value);
    } else if (which == 3) {
        mbFlag4e = *reinterpret_cast<bool*>(&value);
    }
}

// FUNCTION: 0x008d2ba3
bool cRZRadio::Slot26_acc1f8(uint32_t which)
{
    if (which == 0) {
        return mbFlag4c;
    }
    if (which == 1) {
        return mbFlag4d;
    }
    if (which == 3) {
        return mbFlag4e;
    }
    return false;
}

// FUNCTION: 0x008d2bc9
bool cRZRadio::Slot20_acc1f8(uint32_t name, uint32_t release)
{
    uint32_t station = Slot11_acc1f8(name);
    if (station) {
        return Slot21_acc1f8(station, release);
    }
    return false;
}

// FUNCTION: 0x008d2bed
uint32_t cRZRadio::Slot18_acc1f8(uint32_t name)
{
    return Slot11_acc1f8(name) != 0;
}

// FUNCTION: 0x008d2bff
void cRZRadio::Fn008d2bff(uint32_t a, uint32_t b)
{
    if (mpMessages) {
        static_cast<Messages_acc3c0*>(mpMessages)->Post(0x4ab186e9, a, b, 0, 0);
    }
}

// FUNCTION: 0x008d2c5f
void cRZRadio::Fn008d2c5f(uint32_t volume)
{
    if (mpMessages) {
        static_cast<Messages_acc3c0*>(mpMessages)->Post(0xab1a61e, volume, 0, 0, 0);
    }
}

// FUNCTION: 0x008d2c7d
void cRZRadio::Fn008d2c7d()
{
    if (mpMessages) {
        static_cast<Messages_acc3c0*>(mpMessages)->Post(0xeab1a483, 0, 0, 0, 0);
    }
}

// std::find over the station pointers (random access, unrolled four times).
// FUNCTION: 0x008d2c96
void** Fn008d2c96(void** first, void** last, void* const* value, void* /*tag*/)
{
    for (int trip = (last - first) >> 2; trip > 0; --trip) {
        if (*first == *value) {
            return first;
        }
        ++first;
        if (*first == *value) {
            return first;
        }
        ++first;
        if (*first == *value) {
            return first;
        }
        ++first;
        if (*first == *value) {
            return first;
        }
        ++first;
    }
    switch (last - first) {
    case 3:
        if (*first == *value) {
            return first;
        }
        ++first;
    case 2:
        if (*first == *value) {
            return first;
        }
        ++first;
    case 1:
        if (*first == *value) {
            return first;
        }
    }
    return last;
}

// FUNCTION: 0x008d335b
void** Fn008d335b(void** first, void** last, void* const* value)
{
    char tag;
    return Fn008d2c96(first, last, value, &tag);
}

#ifdef OB_DRAFTS
// CLOSE: 0x008d2f21 score 21
bool cRZRadio::Slot23_acc1f8(uint32_t on)
{
    if (static_cast<uint8_t>(on)) {
        if (!mbOn) {
            mbOn = true;
            if (mpStationsBegin == mpStationsEnd) {
                SetupDiskStations();
            }
            if (mpStationsBegin != mpStationsEnd && mpSoundSystem) {
                static_cast<Station_acc3c0*>(mpStationsBegin[mnStation])->Start();
                static_cast<Station_acc3c0*>(mpStationsBegin[mnStation])->OnIdle();
                static_cast<Sound_acc3c0*>(mpSoundSystem)->SetVolume(mnVolume);
            }
        }
    } else if (mbOn) {
        mbOn = false;
        if (mpSoundSystem) {
            Slot31_acc1f8();
        }
    }
    return true;
}
#endif

// FUNCTION: 0x008d2f97
void cRZRadio::Slot25_acc1f8(uint32_t mute)
{
    if (static_cast<uint8_t>(mute)) {
        ++mnMuteCount;
        if (mnMuteCount == 1 && mnVolume > 0 && mpSoundSystem) {
            Fn008d2c5f(0);
        }
    } else if (mnMuteCount > 0) {
        --mnMuteCount;
        if (mnMuteCount == 0 && mnMaxVolume > 0 && mpSoundSystem) {
            Fn008d2c5f(mnMaxVolume);
        }
    }
}

// FUNCTION: 0x008d2fdc
bool cRZRadio::Slot16_acc1f8(uint32_t volume)
{
    if (volume > 0x400) {
        volume = 0x400;
    }
    mnVolume = volume;
    mnMaxVolume = volume;
    if (mpSoundSystem && mnMuteCount <= 0) {
        Fn008d2c5f(volume);
    }
    return true;
}

// FUNCTION: 0x008d300b
bool cRZRadio::Slot10_acc1f8(uint32_t out)
{
    if (mpStationsBegin != mpStationsEnd) {
        *OB_PTR(uint32_t, out) = mnStation;
        return true;
    }
    return false;
}

// FUNCTION: 0x008d3025
bool cRZRadio::Slot09_acc1f8(uint32_t arg)
{
    if (mpStationsBegin != mpStationsEnd) {
        static_cast<Station_acc3c0*>(mpStationsBegin[mnStation])->V09(OB_PTR(void, arg));
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008d3048 score 12
uint32_t cRZRadio::Slot12_acc1f8(uint32_t index)
{
    if (static_cast<uint32_t>(mpStationsEnd - mpStationsBegin) > index) {
        return OB_ADDR(mpStationsBegin[index]);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008d3066 score 22
bool cRZRadio::Slot14_acc1f8(uint32_t index)
{
    if (index != mnStation) {
        static_cast<Station_acc3c0*>(mpStationsBegin[mnStation])->Stop();
        if (!mbFlag89) {
            Slot31_acc1f8();
        }
        if (mpStationsBegin != mpStationsEnd) {
            if (index >= static_cast<uint32_t>(mpStationsEnd - mpStationsBegin)) {
                index = (mpStationsEnd - mpStationsBegin) - 1;
            }
            mnStation = index;
            if (mbOn) {
                static_cast<Station_acc3c0*>(mpStationsBegin[index])->Start();
            }
        }
    }
    return true;
}
#endif

// FUNCTION: 0x008d30c7
uint32_t cRZRadio::Slot17_acc1f8()
{
    return mpStationsEnd - mpStationsBegin;
}

// FUNCTION: 0x008d30d1
bool cRZRadio::Slot05_acc1f8()
{
    if (mbOn && mpStationsBegin != mpStationsEnd) {
        Fn008d2c7d();
        if (!mbFading && !IsFading()) {
            if (mbFlag71) {
                mbFlag71 = false;
                Slot31_acc1f8();
            }
            return static_cast<Station_acc3c0*>(mpStationsBegin[mnStation])->OnIdle();
        }
    }
    return false;
}

// Views for the second half.
struct StationList_acc3c0 {
    void** mpBegin;
    void** mpEnd;
    void** mpCap;
    // STUB: 0x008d3333
    void Fn008d3333(void** position);
    // STUB: 0x008ff785
    void Fn008ff785(void* const* value);
};

// The station's refcount-and-timer part, as far as the two list helpers touch it.
struct Timer_acc3c0 {
    // STUB: 0x0088fedf
    void Fn0088fedf(uint32_t units);
};
struct Cycle_acc3c0 {
    uint32_t m00;
    uint32_t m04;
    uint32_t m08;
    uint8_t mPad0c[0xc];
    Timer_acc3c0 mTimer;
    Cycle_acc3c0* Fn008d34d1();
};

// STUB: 0x009a1add
void OB_STDCALL Fn009a1add(void** first, void** last);
// STUB: 0x00919e96
bool Fn00919e96(uint32_t name);
// STUB: 0x0091b312
bool Fn0091b312(const cRZString* pattern);

// GLOBAL: 0x00b16064
extern const char* gpB16064;

struct Event_acc3c0 {
    virtual void Pad00_Event_acc3c0();
    virtual void Pad01_Event_acc3c0();
    virtual void Pad02_Event_acc3c0();
    virtual void Pad03_Event_acc3c0();
    virtual uint32_t GetId();   // 0x10
    virtual void Pad05_Event_acc3c0();
    virtual void* GetPayload();   // 0x18
};
struct Payload_acc3c0 {
    virtual void Pad00_Payload_acc3c0();
    virtual void Pad01_Payload_acc3c0();
    virtual void Pad02_Payload_acc3c0();
    virtual void Pad03_Payload_acc3c0();
    virtual void Pad04_Payload_acc3c0();
    virtual void Pad05_Payload_acc3c0();
    virtual void Pad06_Payload_acc3c0();
    virtual void Pad07_Payload_acc3c0();
    virtual void Pad08_Payload_acc3c0();
    virtual uint32_t V09();   // 0x24
    virtual void Pad10_Payload_acc3c0();
    virtual void Pad11_Payload_acc3c0();
    virtual void Pad12_Payload_acc3c0();
    virtual void Pad13_Payload_acc3c0();
    virtual uint32_t V14(uint32_t a);   // 0x38
    virtual void Pad15_Payload_acc3c0();
    virtual void Pad16_Payload_acc3c0();
    virtual void Pad17_Payload_acc3c0();
    virtual void Pad18_Payload_acc3c0();
    virtual void Pad19_Payload_acc3c0();
    virtual void Pad20_Payload_acc3c0();
    virtual void Pad21_Payload_acc3c0();
    virtual void Pad22_Payload_acc3c0();
    virtual void Pad23_Payload_acc3c0();
    virtual void Pad24_Payload_acc3c0();
    virtual void Pad25_Payload_acc3c0();
    virtual void Pad26_Payload_acc3c0();
    virtual void Pad27_Payload_acc3c0();
    virtual bool V28();   // 0x70
    virtual void V29(uint32_t id, void* out);   // 0x74
};
struct LangMgr_acc3c0 {
    virtual void Pad00_LangMgr_acc3c0();
    virtual void Pad01_LangMgr_acc3c0();
    virtual void Pad02_LangMgr_acc3c0();
    virtual void Pad03_LangMgr_acc3c0();
    virtual void Pad04_LangMgr_acc3c0();
    virtual void Pad05_LangMgr_acc3c0();
    virtual void Pad06_LangMgr_acc3c0();
    virtual void Pad07_LangMgr_acc3c0();
    virtual void Pad08_LangMgr_acc3c0();
    virtual void Pad09_LangMgr_acc3c0();
    virtual void Pad10_LangMgr_acc3c0();
    virtual void Pad11_LangMgr_acc3c0();
    virtual void Pad12_LangMgr_acc3c0();
    virtual void Pad13_LangMgr_acc3c0();
    virtual void Pad14_LangMgr_acc3c0();
    virtual bool GetDirName(void* str, uint32_t language);   // 0x3c
};

// FUNCTION: 0x008d3132
void cRZRadio::PlaySong_Internal(void* song)
{
    Unknown_acc3c0* extra = 0;
    if (static_cast<Sound_acc3c0*>(mpSoundSystem)->QueryInterface(0x9d002d2, &extra)) {
        extra->V03(0, 2);
    }
    static_cast<Sound_acc3c0*>(mpSoundSystem)->V36(song, 1);
    static_cast<Sound_acc3c0*>(mpSoundSystem)->V06(mnVolume, 0, 1);
    reinterpret_cast<RadioView_acc3c0*>(static_cast<cUnk00acc1f8*>(this))->V33(song);
    if (extra) {
        extra->Release();
    }
}

// The radio's event handler: dispatches on the id of the event.
#ifdef OB_DRAFTS
// CLOSE: 0x008d319b score 47
bool cRZRadio::Slot03_a931c4(uint32_t event)
{
    Event_acc3c0* ev = OB_PTR(Event_acc3c0, event);
    bool result = false;
    Payload_acc3c0* payload = static_cast<Payload_acc3c0*>(ev->GetPayload());
    uint32_t id = ev->GetId();
    switch (id) {
    case 0xeab1a483:
        if (mpSoundSystem) {
            mbFlag88 = static_cast<Sound_acc3c0*>(mpSoundSystem)->IsPlaying();
            mbFlag89 = static_cast<Sound_acc3c0*>(mpSoundSystem)->V23();
        }
        result = true;
        break;
    case 0xeab186df:
        if (payload->V28()) {
            static_cast<Sound_acc3c0*>(mpSoundSystem)->Stop();
            Unknown_acc3c0* song = 0;
            payload->V29(0x89b7dc8, &song);
            PlaySong_Internal(song);
            if (song) {
                song->Release();
            }
        }
        result = true;
        break;
    case 0x6ab1a480:
        if (mpSoundSystem) {
            if (payload->V09() != 0 || !static_cast<Sound_acc3c0*>(mpSoundSystem)->IsPlaying()) {
                static_cast<Sound_acc3c0*>(mpSoundSystem)->Stop();
                if (mpStationsBegin != mpStationsEnd) {
                    Station_acc3c0* station = static_cast<Station_acc3c0*>(mpStationsBegin[mnStation]);
                    station->mbTimerRunning = false;
                    station->V23(0);
                }
                result = true;
            }
        }
        break;
    case 0x4ab186e9:
        if (mpSoundSystem && static_cast<Sound_acc3c0*>(mpSoundSystem)->IsPlaying()) {
            uint32_t current = static_cast<Sound_acc3c0*>(mpSoundSystem)->V20();
            static_cast<Sound_acc3c0*>(mpSoundSystem)->V22(current, payload->V09(), payload->V14(1));
            mbFlag71 = true;
        }
        result = true;
        break;
    case 0xab1a61e:
        mnVolume = payload->V09();
        if (mpSoundSystem && !mbFlag89) {
            static_cast<Sound_acc3c0*>(mpSoundSystem)->SetVolume(mnVolume);
        }
        result = true;
        break;
    case 0xab186e5:
        static_cast<Sound_acc3c0*>(mpSoundSystem)->Stop();
        result = true;
        break;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008d33ff score 25
bool cRZRadio::Slot21_acc1f8(uint32_t station, uint32_t release)
{
    void* key = OB_PTR(void, station);
    void** last = mpStationsEnd;
    void** found = Fn008d335b(mpStationsBegin, last, &key);
    if (found != last) {
        if (static_cast<uint8_t>(release)) {
            static_cast<Unknown_acc3c0*>(key)->Release();
        }
        reinterpret_cast<StationList_acc3c0*>(&mpStationsBegin)->Fn008d3333(found);
        return true;
    }
    return false;
}
#endif

// The random shuffle of the station list.
// FUNCTION: 0x008d3442
void Fn008d3442(void** first, void** last)
{
    if (first != last) {
        for (void** i = first + 1; i != last; ++i) {
            void** j = first + rand() % ((i - first) + 1);
            void* tmp = *i;
            *i = *j;
            *j = tmp;
        }
    }
}

// FUNCTION: 0x008d365b
bool cRZRadio::Slot09_ad1a98(uint32_t /*arg*/)
{
    Slot05_acc1f8();
    return true;
}

// 0x008d3673 (Slot29_acc1f8) is a jump to mInfo's slot 13 with the caller's argument: the slot lacks its argument.

// FUNCTION: 0x008d36d3
bool cRZRadio::Slot28_acc1f8(uint32_t out)
{
    OB_PTR(cIGZString, out)->FromChar(mInfo.data(), mInfo.size());
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008d3733 score 5
bool cRZRadio::Slot22_acc1f8(uint32_t releaseStations)
{
    if (static_cast<uint8_t>(releaseStations)) {
        void** last = mpStationsEnd;
        for (void** p = mpStationsBegin; p != last; ++p) {
            if (*p) {
                static_cast<Unknown_acc3c0*>(*p)->Release();
            }
        }
    }
    StationList_acc3c0* list = reinterpret_cast<StationList_acc3c0*>(&mpStationsBegin);
    Fn009a1add(list->mpBegin, list->mpEnd);
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008d34d1 score 4
Cycle_acc3c0* Cycle_acc3c0::Fn008d34d1()
{
    m00 = 0;
    m04 = 0;
    m08 = 0;
    mTimer.Fn0088fedf(4);
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008d38e5 score 38
bool cRZRadio::Slot19_acc1f8(uint32_t station)
{
    void* key = OB_PTR(void, station);
    StationList_acc3c0* list = reinterpret_cast<StationList_acc3c0*>(&mpStationsBegin);
    void** last = mpStationsEnd;
    if (Fn008d335b(list->mpBegin, last, &key) == last) {
        Station_acc3c0* added = static_cast<Station_acc3c0*>(key);
        cRZRadio* radio = this;
        added->V06(static_cast<cUnk00acc1f8*>(radio));
        added->V03();
        list->Fn008ff785(&key);
        if (((list->mpEnd - list->mpBegin) & ~3) == 1 && Slot24_acc1f8()) {
            Slot12_acc1f8(0);
            Slot05_acc1f8();
        }
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x008d3bf8
void cRZRadio::Fn008d3bf8(void* song)
{
    if (mpMessages) {
        cRZString* copy = new cRZString(*static_cast<cRZString*>(song));
        static_cast<Messages_acc3c0*>(mpMessages)->V05(0xeab186df, copy, 0, 0, 0, 0);
    }
}

// FUNCTION: 0x008d3d33
bool cRZRadio::GetLanguageDirectoryName(uint32_t language, uint32_t out)
{
    if (static_cast<LangMgr_acc3c0*>(mpLanguageManager)->GetDirName(OB_PTR(void, out), language)) {
        OB_PTR(cRZString, out)->push_back('\\');
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008d3d5d score 5
bool cRZRadio::DoesAtLeastOneSoundEntryExistForTheGivenDirectory(uint32_t directory)
{
    std::string path = *static_cast<const std::string*>(OB_PTR(cRZString, directory)) + gpB16064;
    cRZString pattern(path);
    return Fn0091b312(&pattern);
}
#endif

// FUNCTION: 0x008d3dc6
bool cRZRadio::Slot07_acc1f8(uint32_t song)
{
    bool ok = false;
    if (Fn00919e96(song)) {
        Fn008d3bf8(OB_PTR(void, song));
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x008d5092
bool cRZRadio::Slot32_acc1f8(uint32_t out)
{
    if (mbFlag88) {
        *OB_PTR(cRZString, out) = mSongName;
    }
    return true;
}

// Smart pointers the initialisation fetches (their constructors and destructors are the original's).
struct SmartA_acc3c0 {
    void* mp;
    // STUB: 0x004302e0
    void Fn004302e0();
    // STUB: 0x00430310
    void Fn00430310();
};
struct SmartB_acc3c0 {
    void* mp;
    // STUB: 0x00610800
    void Fn00610800();
    // STUB: 0x00610830
    void Fn00610830();
};
struct SmartC_acc3c0 {
    void* mp;
    // STUB: 0x004edfd0
    void Fn004edfd0();
    // STUB: 0x004edf00
    void Fn004edf00();
};
struct SmartD_acc3c0 {
    void* mp;
    // STUB: 0x004de430
    void Fn004de430();
    // STUB: 0x004de460
    void Fn004de460();
};
struct Provider_acc3c0 {
    virtual void Pad00_Provider_acc3c0();
    virtual void Pad01_Provider_acc3c0();
    virtual void Pad02_Provider_acc3c0();
    virtual void Pad03_Provider_acc3c0();
    virtual void Pad04_Provider_acc3c0();
    virtual void Pad05_Provider_acc3c0();
    virtual void Pad06_Provider_acc3c0();
    virtual const char* GetName();   // 0x1c
    virtual void Pad08_Provider_acc3c0();
    virtual bool GetId(uint32_t* out);   // 0x24
};
struct Registry_acc3c0 {
    virtual void Pad00_Registry_acc3c0();
    virtual void Pad01_Registry_acc3c0();
    virtual void Pad02_Registry_acc3c0();
    virtual bool GetInterface(uint32_t id, uint32_t iid, void* out);   // 0xc
};
struct RadioView2_acc3c0 {
    virtual void Pad00_RadioView2_acc3c0();
    virtual void Pad01_RadioView2_acc3c0();
    virtual void Pad02_RadioView2_acc3c0();
    virtual void Pad03_RadioView2_acc3c0();
    virtual void Pad04_RadioView2_acc3c0();
    virtual void Pad05_RadioView2_acc3c0();
    virtual void Pad06_RadioView2_acc3c0();
    virtual void Pad07_RadioView2_acc3c0();
    virtual void Pad08_RadioView2_acc3c0();
    virtual void Pad09_RadioView2_acc3c0();
    virtual void Pad10_RadioView2_acc3c0();
    virtual void Pad11_RadioView2_acc3c0();
    virtual void Pad12_RadioView2_acc3c0();
    virtual void Pad13_RadioView2_acc3c0();
    virtual void Pad14_RadioView2_acc3c0();
    virtual void Pad15_RadioView2_acc3c0();
    virtual void Pad16_RadioView2_acc3c0();
    virtual void Pad17_RadioView2_acc3c0();
    virtual void Pad18_RadioView2_acc3c0();
    virtual void Pad19_RadioView2_acc3c0();
    virtual void Pad20_RadioView2_acc3c0();
    virtual void Pad21_RadioView2_acc3c0();
    virtual void Pad22_RadioView2_acc3c0();
    virtual void Pad23_RadioView2_acc3c0();
    virtual void Pad24_RadioView2_acc3c0();
    virtual void Pad25_RadioView2_acc3c0();
    virtual void Pad26_RadioView2_acc3c0();
    virtual void Pad27_RadioView2_acc3c0();
    virtual void Pad28_RadioView2_acc3c0();
    virtual void V29(void* info);   // 0x74
};
// STUB: 0x0090ddf1
Registry_acc3c0* Fn0090ddf1();

// FUNCTION: 0x008d484a
uint32_t cRZRadio::Slot11_acc1f8(uint32_t callSign)
{
    cRZString wanted;
    cRZString current;
    const char* text = OB_PTR(const char, callSign);
    wanted.assign(text, text + 4);
    current.assign("????", "????" + 4);
    int count = mpStationsEnd - mpStationsBegin;
    for (int i = 0; i < count; ++i) {
        static_cast<Station_acc3c0*>(mpStationsBegin[i])->V09(const_cast<char*>(current.data()));
        if (static_cast<const std::string&>(wanted) == static_cast<const std::string&>(current)) {
            return OB_ADDR(mpStationsBegin[i]);
        }
    }
    return 0;
}

// FUNCTION: 0x008d490b
bool cRZRadio::Slot13_acc1f8(uint32_t callSign, uint32_t info)
{
    cRZString wanted;
    cRZString current;
    uint32_t* pair = OB_PTR(uint32_t, info);
    if (pair) {
        mbFlag89 = true;
        Fn008d2bff(pair[0], pair[1]);
    }
    if (mpStationsBegin == mpStationsEnd) {
        SetupDiskStations();
    }
    const char* text = OB_PTR(const char, callSign);
    wanted.assign(text, text + 4);
    current.assign("????", "????" + 4);
    int count = mpStationsEnd - mpStationsBegin;
    for (int i = 0; i < count; ++i) {
        static_cast<Station_acc3c0*>(mpStationsBegin[i])->V09(const_cast<char*>(current.data()));
        if (static_cast<const std::string&>(wanted) == static_cast<const std::string&>(current)) {
            return Slot14_acc1f8(i);
        }
    }
    return false;
}

// The initialisation: fetches the sound system and the language manager, finds the radio directory, sets the stations up.
#ifdef OB_DRAFTS
// CLOSE: 0x008d4687 score 101
bool cRZRadio::Slot03_ae1d24()
{
    SmartA_acc3c0 sound;
    sound.Fn004302e0();
    bool ok = false;
    if (sound.mp != 0) {
        SetSoundSystem(OB_ADDR(sound.mp));
        SmartB_acc3c0 language;
        language.Fn00610800();
        SetLanguageManager(OB_ADDR(language.mp));
        bool proceed = true;
        if (!mbInitialised) {
            if (mpSoundSystem == 0 && mpMessages != 0) {
                SmartC_acc3c0 holder;
                holder.Fn004edfd0();
                proceed = false;
                if (holder.mp != 0) {
                    uint32_t id;
                    if (static_cast<Provider_acc3c0*>(holder.mp)->GetId(&id)) {
                        proceed = Fn0090ddf1()->GetInterface(id, 0x206077d2, &mpSoundSystem);
                    }
                }
                if (proceed) {
                    static_cast<Unknown_acc3c0*>(mpSoundSystem)->V03(0, 0);
                }
                holder.Fn004edf00();
            }
            if (proceed) {
                SmartD_acc3c0 dir;
                dir.Fn004de430();
                if (dir.mp != 0) {
                    cRZString name(static_cast<Provider_acc3c0*>(dir.mp)->GetName());
                    cRZString suffix("Res\\Music\\Radio\\");
                    std::string joined = static_cast<std::string&>(name) + static_cast<std::string&>(suffix);
                    cRZString joinedName(joined);
                    name = joinedName;
                    reinterpret_cast<RadioView2_acc3c0*>(static_cast<cUnk00acc1f8*>(this))->V29(&name);
                    SetupDiskStations();
                    mbInitialised = true;
                    if (mbOn) {
                        mbOn = false;
                        Slot23_acc1f8(1);
                    }
                }
                if (mpMessages) {
                    static_cast<Messages_acc3c0*>(mpMessages)->V15(static_cast<cUnk00a931c4*>(this));
                }
                dir.Fn004de460();
            }
        }
        if (proceed) {
            Fn008793ec()->V09(this);
            Fn008793ec()->V11(this);
            ok = true;
        }
        language.Fn00610830();
    }
    sound.Fn00430310();
    return ok;
}
#endif

#ifdef OB_DRAFTS
// The directory reader the disk radio uses.
struct Directory_acc3c0 {
    uint8_t mData[0x100];
    // STUB: 0x0091bd31
    void Fn0091bd31(const cRZString& path, bool a, bool b, bool c);
    // STUB: 0x0091b2f7
    void Fn0091b2f7();
    // STUB: 0x0091bcad
    void Fn0091bcad(const cRZString& path, bool a);
    // STUB: 0x0091b9d5
    void Fn0091b9d5(std::list<cRZString>* out, int a);
};

// The station constructor (0x008d376e, thiscall, returns this).
struct StationCtor_acc3c0 {
    // STUB: 0x008d376e
    StationCtor_acc3c0* Fn008d376e();
};

// GLOBAL: 0x00b16044
extern const char* gpB16044;
// GLOBAL: 0x00b16048
extern const char* gpB16048;
// GLOBAL: 0x00b1604c
extern const char* gpB1604c;
// GLOBAL: 0x00b16050
extern const char* gpB16050;
// GLOBAL: 0x00b16054
extern const char* gpB16054;
// GLOBAL: 0x00b16058
extern const char* gpB16058;

// Extends a play-list directory with the language directory when that one exists.
inline void LanguagePath_acc3c0(cRZRadio* radio, cRZString* path, cRZString* langDir, cRZString* entry)
{
    radio->GetLanguageDirectoryName(0, OB_ADDR(langDir));
    std::string joined = static_cast<std::string&>(*path) + static_cast<std::string&>(*langDir);
    *entry = cRZString(joined);
    if (radio->DoesAtLeastOneSoundEntryExistForTheGivenDirectory(OB_ADDR(entry))) {
        radio->GetLanguageDirectoryName(1, OB_ADDR(langDir));
    } else {
        langDir->erase(0, std::string::npos);
    }
    path->append(*langDir);
}

// Reads the radio directory and makes a disk station of every sub-directory that holds sound entries.
// CLOSE: 0x008d49f8 score 517
bool cRZRadio::SetupDiskStations()
{
    cRZString baseDir;
    cRZString radioDir;
    cRZString entry;
    cRZString langDir;
    std::list<cRZString> subdirs;
    cRZString empty;
    Directory_acc3c0 directory;
    directory.Fn0091bd31(empty, false, false, false);
    int count = 0;
    std::string* info = static_cast<std::string*>(&mInfo);
    baseDir = cRZString(*info + gpB16048);
    radioDir = cRZString(*info + gpB16044);
    directory.Fn0091bcad(baseDir, false);
    directory.Fn0091b9d5(&subdirs, 0);
    if (!subdirs.empty()) {
        Slot22_acc1f8(1);
        for (std::list<cRZString>::iterator it = subdirs.begin(); it != subdirs.end(); ++it) {
            entry = baseDir;
            entry.append(*it);
            entry.push_back('\\');
            entry.append(gpB16058);
            if (!Fn0091b312(&entry)) {
                continue;
            }
            void* memory = operator new(0x100);
            cRZDiskRadioStation* station = 0;
            if (memory) {
                station = reinterpret_cast<cRZDiskRadioStation*>(static_cast<StationCtor_acc3c0*>(memory)->Fn008d376e());
            }
            static_cast<Unknown_acc3c0*>(static_cast<void*>(station))->Release();
            Slot19_acc1f8(OB_ADDR(station));
            ++count;
            static_cast<Station_acc3c0*>(static_cast<void*>(station))->V23((mnSettingValue & 1) != 0);
            it->push_back('\\');
            station->mBasePath = cRZString(static_cast<std::string&>(baseDir) + static_cast<std::string&>(*it));
            station->mPath0 = cRZString(static_cast<std::string&>(station->mBasePath) + gpB1604c);
            station->mPath1 = cRZString(static_cast<std::string&>(station->mBasePath) + gpB16050);
            LanguagePath_acc3c0(this, &station->mPath1, &langDir, &entry);
            station->mPath2 = cRZString(static_cast<std::string&>(radioDir) + gpB16044);
            LanguagePath_acc3c0(this, &station->mPath2, &langDir, &entry);
            station->mPath3 = cRZString(static_cast<std::string&>(station->mBasePath) + gpB16054);
            LanguagePath_acc3c0(this, &station->mPath3, &langDir, &entry);
            static_cast<Station_acc3c0*>(static_cast<void*>(station))->OnIdle();
        }
        if (mpStationsEnd - mpStationsBegin <= static_cast<int>(mnStation)) {
            mnStation = 0;
        }
    }
    bool any = count != 0;
    directory.Fn0091b2f7();
    return any;
}
#endif
