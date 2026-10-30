#include <math.h>
#include <stdio.h>
#include <string.h>
#include "classes/cUnk00ac2c88.h"
#include "gzcom/cRZString.h"

#ifdef _MSC_VER
#define OB_STDCALL_AC2C88 __stdcall
#else
#define OB_STDCALL_AC2C88
#endif

// The lock embedded at offset 0x64; only the slots used here are named.
struct Lock_ac2c88 {
    virtual void Pad0();
    virtual void Enter();
    virtual void Leave();
};

// A scope guard over the lock: the constructor takes it, the destructor lets it go.
struct Guard_ac2c88 {
    uint32_t mPad;
    Lock_ac2c88* mpLock;
    // STUB: 0x0048c9f0
    Guard_ac2c88(Lock_ac2c88* lock);
    ~Guard_ac2c88() { mpLock->Leave(); }
};

// The sound buffer (a component-model COM object); slots by their vtable offset.
struct DSBuf_ac2c88 {
    virtual long OB_STDCALL_AC2C88 QueryInterface(uint32_t, void**);
    virtual uint32_t OB_STDCALL_AC2C88 AddRef();
    virtual uint32_t OB_STDCALL_AC2C88 Release();
    virtual long OB_STDCALL_AC2C88 GetCaps(void*);
    virtual long OB_STDCALL_AC2C88 GetCurrentPosition(uint32_t* play, uint32_t* write);
    virtual long OB_STDCALL_AC2C88 GetFormat(void*, uint32_t, uint32_t*);
    virtual long OB_STDCALL_AC2C88 GetVolume(int32_t*);
    virtual long OB_STDCALL_AC2C88 GetPan(int32_t*);
    virtual long OB_STDCALL_AC2C88 GetFrequency(uint32_t*);
    virtual long OB_STDCALL_AC2C88 GetStatus(uint32_t*);
    virtual long OB_STDCALL_AC2C88 Initialize(void*, void*);
    virtual long OB_STDCALL_AC2C88 Lock(uint32_t offset, uint32_t bytes, void** p1, uint32_t* s1, void** p2, uint32_t* s2, uint32_t flags);
    virtual long OB_STDCALL_AC2C88 Play(uint32_t, uint32_t, uint32_t flags);
    virtual long OB_STDCALL_AC2C88 SetCurrentPosition(uint32_t pos);
    virtual long OB_STDCALL_AC2C88 SetFormat(const void* format);
    virtual long OB_STDCALL_AC2C88 SetVolume(int32_t volume);
    virtual long OB_STDCALL_AC2C88 SetPan(int32_t pan);
    virtual long OB_STDCALL_AC2C88 SetFrequency(uint32_t frequency);
    virtual long OB_STDCALL_AC2C88 Stop();
    virtual long OB_STDCALL_AC2C88 Unlock(void* p1, uint32_t s1, void* p2, uint32_t s2);
    virtual long OB_STDCALL_AC2C88 Restore();
};

// The sound device.
struct DSDev_ac2c88 {
    virtual long OB_STDCALL_AC2C88 QueryInterface(uint32_t, void**);
    virtual uint32_t OB_STDCALL_AC2C88 AddRef();
    virtual uint32_t OB_STDCALL_AC2C88 Release();
    virtual long OB_STDCALL_AC2C88 CreateSoundBuffer(const void* desc, uint32_t* out, void* outer);
    virtual long OB_STDCALL_AC2C88 GetCaps(void*);
    virtual long OB_STDCALL_AC2C88 DuplicateSoundBuffer(uint32_t src, uint32_t* out);
};

// The buffer description handed to CreateSoundBuffer.
struct DSDesc_ac2c88 {
    uint32_t mSize;
    uint32_t mFlags;
    uint32_t mBytes;
    uint32_t mReserved;
    const void* mpFormat;
    uint32_t mGuid[4];
};

// The 18-byte wave format copied around.
struct Wave_ac2c88 {
    uint16_t mTag;
    uint16_t mChannels;
    uint32_t mRate;
    uint32_t mAvg;
    uint16_t mBlock;
    uint16_t mBits;
    uint16_t mExtra;
};

// The sink holder at +0xd4.
struct Sink_ac2c88 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual bool Fn03();
    virtual DSDev_ac2c88* Fn04();
};

// The owner at +0xd0; slots by their vtable index.
struct Owner_ac2c88 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual bool Fn18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual bool Fn24(const cRZString* key, uint32_t* out);
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual uint32_t Fn28();
    virtual void P29();
    virtual void Fn30(void* group, uint32_t size);
    virtual void Fn31(void* group);
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
    virtual void P38();
    virtual void P39();
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual void P48();
    virtual bool Fn49();
};

// The source object at +0x18 (the file or stream the data comes from).
struct Handle_ac2c88 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual bool Fn04(cRZString* out);
    virtual void P5();
    virtual bool Fn06(void* out);
    virtual bool Fn07();
    virtual void Fn08();
    virtual bool Fn09();
    virtual uint32_t Fn10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual uint32_t Fn14(void* buffer, uint32_t size);
    virtual void P15();
    virtual const uint32_t* Fn16();
};

// A reference-counting pointer holder (assignment at 0x0094909a).
struct AutoRef_ac2c88 {
    void* mp;
    // STUB: 0x00969fea
    void Fn00969fea(void* src);
    // STUB: 0x0094909a
    AutoRef_ac2c88& Assign(void* p);
};

// The stream behind the record (its first word).
struct Reader_ac2c88 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual uint32_t Fn14(void* buffer, uint32_t size);
    virtual void Fn15();
    virtual const uint32_t* Fn16();
};

// The record at +0xb8: the stream, then the playback state.
struct Rec_ac2c88 {
    Reader_ac2c88* mpSrc;
    uint32_t mn04;
    uint32_t mn08;
    uint32_t mn0c;
    uint32_t mn10;
    uint32_t mn14;
    uint32_t mn18;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
    uint32_t mn28;
    uint32_t mn2c;
    uint32_t mn30;
    uint32_t mn34;
    uint32_t mn38;
    uint32_t mn3c;
    uint32_t mn40;
    // STUB: 0x0094909a
    void Assign(void* p);
    // STUB: 0x008762d1
    Rec_ac2c88* Fn008762d1();
};

// The timer used to pace a fade.
struct Timer_ac2c88 {
    // STUB: 0x0088fedf
    Timer_ac2c88(uint32_t resolution);
    // STUB: 0x0089058f
    void Restart();
    // STUB: 0x00890198
    uint32_t GetElapsedTime();
    // STUB: 0x00a6d837
    void Destroy();
};

// The listener at +0x78.
struct Listener_ac2c88 {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Notify(void* source);
};

// A source object another one is read from (slots 6 and 7 are the two values copied).
struct Src_ac2c88 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual uint32_t Fn06();
    virtual uint32_t Fn07();
};

// A path split into parts (the constructor takes the name).
struct Path_ac2c88 {
    uint8_t mData[0x6c];
    // STUB: 0x0091c2c5
    Path_ac2c88(const cRZString* name);
    // STUB: 0x0091c31f
    uint32_t Fn0091c31f(uint32_t a, uint32_t b);
    // STUB: 0x0043af80
    ~Path_ac2c88();
};

// The member object at +0x1c, and the peer it is handed to.
struct Member1c_ac2c88 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void Fn14(uint32_t a);
};
struct Peer_ac2c88 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void Fn14(void* member);
};

// The registry of live objects and the lock around it.
struct Registry_ac2c88 {
    uint32_t mEnd;
    // STUB: 0x0098129c
    uint32_t Find(void* const* key);
};

// GLOBAL: 0x00b54098
extern Lock_ac2c88 gB54098;
// GLOBAL: 0x00b5408c
extern Registry_ac2c88 gB5408c;

// GLOBAL: 0x00b54088
extern DSDev_ac2c88* gpB54088;
// GLOBAL: 0x00b11dd8
extern uint32_t gB11dd8;

// The service object that opens a source by key.
struct Svc_ac2c88 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void Fn03(uint32_t key, uint32_t iid, void** out);
};

// The opened source (reference counted, with an Open at slot 3).
struct Opened_ac2c88 {
    virtual void P0();
    virtual void P1();
    virtual uint32_t Release();
    virtual bool Fn03(const void* name);
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void Fn07();
};

// STUB: 0x0090ddf1
Svc_ac2c88* Fn0090ddf1();
// STUB: 0x0091a3e2
uint32_t Fn0091a3e2(const cRZString* name);
// STUB: 0x009205a0
void Fn009205a0(uint32_t ms);
// STUB: 0x00418a40
uint32_t Fn00418a40(const char* a, const char* b);

// FUNCTION: 0x00875fff
int32_t Fn00875fff(int32_t v)
{
    if (v == 0) {
        return -10000;
    }
    if (v == 0x400) {
        return 0;
    }
    return v * 6000 / 0x400 - 6000;
}

// FUNCTION: 0x008762d1
Rec_ac2c88* Rec_ac2c88::Fn008762d1()
{
    mpSrc = 0;
    mn04 = 0;
    mn08 = 0;
    mn0c = 0;
    mn10 = 0;
    mn14 = 0;
    mn18 = 0;
    mn1c = 0;
    mn20 = 0;
    mn24 = 0;
    mn28 = 0;
    mn2c = 1;
    mn30 = 0;
    mn34 = 0;
    mn38 = 0;
    mn3c = 0;
    mn40 = 0;
    return this;
}

// FUNCTION: 0x008760c3
void cUnk00ac2c88::Fn008760c3()
{
    uint8_t zero = 0;
    if (mbF4e == zero) {
        if (mbF4a != zero || static_cast<uint8_t>(mbF4b) != zero || mbF4c != zero) {
            Owner_ac2c88* o = static_cast<Owner_ac2c88*>(mpOwner);
            mbF4e = 1;
            o->Fn30(static_cast<cUnk00a943c0*>(this), 0x14);
        }
    } else if (mbF4a == zero && static_cast<uint8_t>(mbF4b) == zero && mbF4c == zero) {
        static_cast<Owner_ac2c88*>(mpOwner)->Fn31(static_cast<cUnk00a943c0*>(this));
        mbF4e = zero;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x008769cc score 12
uint32_t cUnk00ac2c88::Fn008769cc()
{
    int32_t i;
    uint32_t status;
    for (i = 0; i < 8; ++i) {
        if (maBuffers[i]) {
            DSBuf_ac2c88* b = OB_PTR(DSBuf_ac2c88, maBuffers[i]);
            if (b->GetStatus(&status) == 0) {
                if (status & 1) {
                    return maBuffers[i];
                }
            }
        }
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00877102 score 13
void cUnk00ac2c88::Fn00877102()
{
    Guard_ac2c88 guard(&gB54098);
    void* key = this;
    if (gB5408c.Find(&key) != gB5408c.mEnd) {
        int32_t step = mnPlayStep;
        int32_t pos = mnVolume + step;
        if ((step < 0 && pos <= mnPlayEnd) || (step > 0 && pos >= mnPlayEnd)) {
            if (pos == 0) {
                Slot08_ac2c88();
            }
            mbF4b = 0;
            Fn008760c3();
            Slot21_ac2c88(mnPlayEnd);
        }
    }
}
#endif

// FUNCTION: 0x00877585
void cUnk00ac2c88::Fn00877585()
{
    {
        Guard_ac2c88 wait(&gB54098);
    }
    if (!Slot07_ac2c88()) {
        if (mpListener) {
            static_cast<Listener_ac2c88*>(mpListener)->Notify(this);
        }
        mbF4c = 0;
    } else {
        mbF4d = static_cast<cUnk00ac2bf0*>(this)->Slot05_ac2bf0() <= 250;
        mbF4c = 1;
    }
    Fn008760c3();
}

// FUNCTION: 0x00876097
unsigned int cUnk00ac2c88::Release()
{
    if (mnRefCount > 1) {
        --mnRefCount;
        return mnRefCount;
    }
    Slot04_ac2c88();
    delete this;
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00876028 score 39
bool cUnk00ac2c88::QueryInterface(uint32_t iid, void** outp)
{
    void** out = outp;
    if (iid == 1 || iid == 0x206077d2) {
        *out = this;
    } else {
        void* p;
        if (iid == 0x49d28669) {
            p = static_cast<cUnk00ac2bac*>(this);
        } else if (iid == 0x3b143f0a) {
            p = static_cast<cUnk00ac2bc0*>(this);
        } else if (iid == 0x5b34f0af) {
            p = static_cast<cUnk00a943c0*>(this);
        } else if (iid == 0x09d002d2) {
            p = static_cast<cUnk00ac2bdc*>(this);
        } else if (iid == 0xe9d00a9a) {
            p = static_cast<cUnk00ac2bf0*>(this);
        } else {
            return false;
        }
        *out = p;
    }
    AddRef();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876118 score 4
uint32_t cUnk00ac2c88::Slot11_ac2c88()
{
    int32_t i = 0;
    do {
        if (maBuffers[i] == 0) {
            return i;
        }
        ++i;
    } while (i < 8);
    return i;
}
#endif

// FUNCTION: 0x00876133
uint32_t cUnk00ac2c88::Slot03_ac2bc0()
{
    return gB11dd8;
}

// FUNCTION: 0x00876139
bool cUnk00ac2c88::Slot04_ac2bc0(uint32_t a)
{
    gB11dd8 = a;
    return true;
}

// FUNCTION: 0x00876153
void cUnk00ac2c88::Slot36_ac2c88(uint32_t a, uint32_t b)
{
    Src_ac2c88* s = OB_PTR(Src_ac2c88, a);
    Slot35_ac2c88(s->Fn06(), s->Fn07(), b);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00876180 score 27
bool cUnk00ac2c88::Slot14_ac2c88()
{
    if (!static_cast<Owner_ac2c88*>(mpOwner)->Fn18()) {
        return true;
    }
    bool r;
    Guard_ac2c88 guard(reinterpret_cast<Lock_ac2c88*>(&mLock[0]));
    bool f = Slot16_ac2c88();
    uint8_t zero = 0;
    if (f) {
        if (mbF49 == zero) {
            r = true;
            goto done;
        }
    } else if (mbF49 == zero) {
        r = Slot43_ac2c88();
        goto done;
    }
    if (mbBC != zero) {
        r = true;
    } else {
        r = Slot44_ac2c88(1);
    }
done:
    return r;
}
#endif

// FUNCTION: 0x008761f3
bool cUnk00ac2c88::Slot16_ac2c88()
{
    return maBuffers[0] != 0;
}

// FUNCTION: 0x008761ff
bool cUnk00ac2c88::Slot42_ac2c88()
{
    Guard_ac2c88 guard(reinterpret_cast<Lock_ac2c88*>(&mLock[0]));
    while (maBuffers[0]) {
        OB_PTR(DSBuf_ac2c88, maBuffers[0])->Release();
        maBuffers[0] = 0;
    }
    return true;
}

// FUNCTION: 0x00876238
void cUnk00ac2c88::Slot06_ac2bc0(uint32_t a)
{
    if (a < 1) {
        a = 1;
    }
    if (a > 6) {
        a = 6;
    }
    mnC0 = a;
}

// FUNCTION: 0x00876255
uint32_t cUnk00ac2c88::Slot05_ac2bf0()
{
    const Wave_ac2c88* w = reinterpret_cast<const Wave_ac2c88*>(&mFormat[0]);
    if (!Slot07_ac2c88()) {
        return mnBufferBytes / w->mBits * 8000 / w->mRate * 1000;
    }
    if (mbF48) {
        return 0xffffffff;
    }
    uint32_t play;
    uint32_t write;
    OB_PTR(DSBuf_ac2c88, maBuffers[0])->GetCurrentPosition(&play, &write);
    return (mnBufferBytes - play) / w->mBits * 8000 / w->mRate;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0087630c score 45
bool cUnk00ac2c88::Slot22_ac2c88(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    if (!static_cast<Owner_ac2c88*>(mpOwner)->Fn18()) {
        return true;
    }
    if (b == a) {
        return true;
    }
    if (static_cast<uint8_t>(d) != 0) {
        if (Slot23_ac2c88()) {
            return false;
        }
        int32_t n = c / 20;
        int32_t step = static_cast<int32_t>(b - a) / n;
        mnPlayStep = step;
        if (step != 0) {
            mnPlayEnd = b;
            Slot21_ac2c88(a);
            mbF4b = 1;
            Fn008760c3();
        } else {
            Slot21_ac2c88(b);
        }
    } else {
        Timer_ac2c88 timer(4);
        int32_t step = static_cast<int32_t>(b - a) / 10;
        uint32_t period = c / 10;
        int32_t n = 10;
        Slot21_ac2c88(a);
        do {
            timer.Restart();
            while (timer.GetElapsedTime() < period) {
                Fn009205a0(0);
            }
            a += step;
            Slot21_ac2c88(a);
        } while (--n);
        timer.Destroy();
    }
    return true;
}
#endif

// FUNCTION: 0x00876400
uint32_t cUnk00ac2c88::Slot04_ac2bdc()
{
    Guard_ac2c88 guard(reinterpret_cast<Lock_ac2c88*>(&mLock[0]));
    return OB_ADDR(mpHandle);
}

// FUNCTION: 0x00876424
bool cUnk00ac2c88::Slot03_ac2bdc(uint32_t a, uint32_t b)
{
    Guard_ac2c88 guard(reinterpret_cast<Lock_ac2c88*>(&mLock[0]));
    if (OB_PTR(void, a) != mpHandle) {
        bool wasPlaying = Slot16_ac2c88();
        if (wasPlaying) {
            Slot15_ac2c88();
        }
        reinterpret_cast<AutoRef_ac2c88*>(&mpHandle)->Assign(OB_PTR(void, a));
        if (b == 1) {
            mbF49 = 1;
        } else if (b == 2) {
            mbF49 = Slot45_ac2c88();
        } else {
            mbF49 = 0;
        }
        if (!mbF49 && wasPlaying) {
            Slot14_ac2c88();
        }
        mbF54 = mbF49;
    }
    return true;
}

// FUNCTION: 0x008764b6
bool cUnk00ac2c88::Slot15_ac2c88()
{
    Guard_ac2c88 guard(reinterpret_cast<Lock_ac2c88*>(&mLock[0]));
    if (Slot07_ac2c88()) {
        Slot08_ac2c88();
    }
    if (mpRecord) {
        static_cast<Rec_ac2c88*>(mpRecord)->Assign(0);
    }
    Slot42_ac2c88();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00876504 score 99
bool cUnk00ac2c88::Slot43_ac2c88()
{
    void* p1 = 0;
    void* p2 = 0;
    uint32_t s2;
    uint32_t s1;
    if (static_cast<Sink_ac2c88*>(mpSinkHolder)->Fn03()) {
        if (mpHandle == 0) {
            if (!Slot38_ac2c88()) {
                return false;
            }
        }
        Handle_ac2c88* h = static_cast<Handle_ac2c88*>(mpHandle);
        if (!h->Fn09() && !h->Fn07()) {
            return false;
        }
        mnBufferBytes = h->Fn10();
        const uint32_t* fmt = h->Fn16();
        memcpy(mFormat, fmt, 20);
        if (Slot49_ac2c88(0)) {
            DSBuf_ac2c88* b = OB_PTR(DSBuf_ac2c88, maBuffers[0]);
            if (b->Lock(0, mnBufferBytes, &p1, &s1, &p2, &s2, 0) == 0) {
                static_cast<Handle_ac2c88*>(mpHandle)->Fn14(p1, mnBufferBytes);
                if (OB_PTR(DSBuf_ac2c88, maBuffers[0])->Unlock(p1, s1, p2, s2) == 0) {
                    static_cast<Handle_ac2c88*>(mpHandle)->Fn08();
                    return true;
                }
            }
        }
        Slot42_ac2c88();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876603 score 4
bool cUnk00ac2c88::Slot04_ac2bac(uint32_t a)
{
    DSDesc_ac2c88 desc;
    gpB54088 = OB_PTR(Sink_ac2c88, a)->Fn04();
    memset(&desc, 0, 0x24);
    desc.mSize = 0x24;
    desc.mBytes = 0;
    desc.mpFormat = 0;
    desc.mFlags = 0x11;
    if (gpB54088->CreateSoundBuffer(&desc, &maBuffers[0], 0) != 0) {
        desc.mFlags = 1;
        if (gpB54088->CreateSoundBuffer(&desc, &maBuffers[0], 0) != 0) {
            return false;
        }
    }
    Wave_ac2c88 wf;
    DSBuf_ac2c88* b = OB_PTR(DSBuf_ac2c88, maBuffers[0]);
    const Wave_ac2c88* w = reinterpret_cast<const Wave_ac2c88*>(&mFormat[0]);
    wf.mTag = w->mTag;
    wf.mChannels = w->mChannels;
    wf.mRate = w->mRate;
    wf.mAvg = w->mAvg;
    wf.mBlock = w->mBlock;
    wf.mBits = w->mBits;
    wf.mExtra = w->mExtra;
    return !b->SetFormat(&wf);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008766d8 score 52
bool cUnk00ac2c88::Slot49_ac2c88(uint32_t a)
{
    DSDesc_ac2c88 local;
    DSDev_ac2c88* ds = static_cast<Sink_ac2c88*>(mpSinkHolder)->Fn04();
    DSDesc_ac2c88* d;
    if (static_cast<Owner_ac2c88*>(mpOwner)->Fn18()) {
        if (a == 0) {
            goto fail;
        }
        d = OB_PTR(DSDesc_ac2c88, a);
        if (mnBits < 0x40) {
            d->mFlags = (d->mFlags & ~4u) | 8u;
        } else {
            d->mFlags &= ~8u;
        }
    } else {
        uint32_t flags;
        local.mReserved = 0;
        flags = mnFlags;
        local.mBytes = mnBufferBytes;
        local.mSize = 0x24;
        local.mpFormat = &mFormat[0];
        if (mnBits < 0x40) {
            flags = (flags & ~4u) | 8u;
        } else {
            flags &= ~8u;
        }
        local.mFlags = flags;
        d = &local;
    }
    if (ds->CreateSoundBuffer(d, &maBuffers[0], 0) == 0) {
        return true;
    }
fail:
    if (maBuffers[0]) {
        OB_PTR(DSBuf_ac2c88, maBuffers[0])->Release();
        maBuffers[0] = 0;
    }
    return false;
}
#endif

// FUNCTION: 0x00876798
uint32_t cUnk00ac2c88::Slot24_ac2c88()
{
    int32_t v;
    if (maBuffers[0]) {
        if (OB_PTR(DSBuf_ac2c88, maBuffers[0])->GetPan(&v) == 0) {
            return v;
        }
    }
    return 0x200;
}

// FUNCTION: 0x008767c1
bool cUnk00ac2c88::Slot25_ac2c88(uint32_t a)
{
    if (maBuffers[0]) {
        int32_t p = a;
        if (p < 0) {
            p = 0;
        }
        if (p > 0x400) {
            p = 0x400;
        }
        return OB_PTR(DSBuf_ac2c88, maBuffers[0])->SetPan(p * 20000 / 0x400 - 10000) ? false : true;
    }
    return false;
}

// FUNCTION: 0x0087680b
uint32_t cUnk00ac2c88::Slot26_ac2c88()
{
    uint32_t v;
    if (maBuffers[0]) {
        if (OB_PTR(DSBuf_ac2c88, maBuffers[0])->GetFrequency(&v) == 0) {
            return v;
        }
    }
    return Slot28_ac2c88();
}

#ifdef OB_DRAFTS
// CLOSE: 0x0087683c score 4
bool cUnk00ac2c88::Slot27_ac2c88(uint32_t a)
{
    if (!static_cast<Owner_ac2c88*>(mpOwner)->Fn18()) {
        return true;
    }
    if (maBuffers[0]) {
        int32_t f = a;
        if (f != 0 && f < 1000) {
            f = 1000;
        }
        if (f > 100000) {
            f = 100000;
        }
        return !OB_PTR(DSBuf_ac2c88, maBuffers[0])->SetFrequency(f);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876894 score 39
bool cUnk00ac2c88::Slot21_ac2c88(uint32_t a)
{
    int32_t v = a;
    if (v < 0) {
        v = 0;
    }
    if (v > 0x400) {
        v = 0x400;
    }
    mnVolume = v;
    double d = sqrt(v * 0.0009765625) * 1024.0;
    if (maBuffers[0]) {
        uint32_t base = static_cast<Owner_ac2c88*>(mpOwner)->Fn28();
        int32_t t = static_cast<int32_t>(d) * base / 0x400;
        if (OB_PTR(DSBuf_ac2c88, maBuffers[0])->SetVolume(Fn00875fff(t)) != 0) {
            return false;
        }
    }
    return true;
}
#endif

// FUNCTION: 0x00876926
uint32_t cUnk00ac2c88::Slot40_ac2c88()
{
    uint32_t play;
    uint32_t write;
    if (maBuffers[0]) {
        if (OB_PTR(DSBuf_ac2c88, maBuffers[0])->GetCurrentPosition(&play, &write) == 0) {
            return play;
        }
        return 0;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00876955 score 4
bool cUnk00ac2c88::Slot41_ac2c88(uint32_t a)
{
    if (!static_cast<Owner_ac2c88*>(mpOwner)->Fn18()) {
        return true;
    }
    if (maBuffers[0]) {
        return !OB_PTR(DSBuf_ac2c88, maBuffers[0])->SetCurrentPosition(a);
    }
    return false;
}
#endif

// FUNCTION: 0x00876990
bool cUnk00ac2c88::Slot07_ac2c88()
{
    int32_t i;
    uint32_t status;
    for (i = 0; i < 8; ++i) {
        if (maBuffers[i] == 0) {
            break;
        }
        if (OB_PTR(DSBuf_ac2c88, maBuffers[i])->GetStatus(&status) == 0 && (status & 1)) {
            return true;
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00876a11 score 18
bool cUnk00ac2c88::Slot48_ac2c88(uint32_t out)
{
    int32_t i;
    uint32_t status;
    for (i = 0; i < 8; ++i) {
        if (maBuffers[i] == 0) {
            return gpB54088->DuplicateSoundBuffer(maBuffers[i], OB_PTR(uint32_t, out)) == 0;
        }
        if (OB_PTR(DSBuf_ac2c88, maBuffers[i])->GetStatus(&status) == 0 && status == 0) {
            *OB_PTR(uint32_t, out) = maBuffers[i];
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876a7b score 52
bool cUnk00ac2c88::Slot08_ac2c88()
{
    Guard_ac2c88 guard(reinterpret_cast<Lock_ac2c88*>(&mLock[0]));
    bool r = false;
    uint32_t status;
    if (Slot23_ac2c88()) {
        mbF4b = 0;
        Fn008760c3();
    }
    if (mbF49) {
        r = Slot47_ac2c88();
    } else {
        if (maBuffers[0]) {
            int32_t i = 0;
            uint32_t* p = &maBuffers[0];
            do {
                if (i >= 8) {
                    break;
                }
                DSBuf_ac2c88* b = OB_PTR(DSBuf_ac2c88, *p);
                if (b->GetStatus(&status) == 0 && (status & 1)) {
                    b->Stop();
                    if (mpListener) {
                        mbF4c = 0;
                        Fn008760c3();
                        static_cast<Listener_ac2c88*>(mpListener)->Notify(this);
                    }
                }
                ++i;
                ++p;
            } while (*p != 0);
        }
        r = true;
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876b22 score 48
bool cUnk00ac2c88::Slot10_ac2c88()
{
    bool playing = Slot07_ac2c88();
    if (mbF49) {
        return Slot47_ac2c88();
    }
    int32_t i = 0;
    uint32_t* p = &maBuffers[0];
    do {
        if (i >= 8) {
            break;
        }
        OB_PTR(DSBuf_ac2c88, *p)->Stop();
        ++i;
        ++p;
    } while (*p != 0);
    mbF4c = 0;
    Fn008760c3();
    if (playing && mpListener) {
        static_cast<Listener_ac2c88*>(mpListener)->Notify(this);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876b8c score 17
bool cUnk00ac2c88::Slot45_ac2c88()
{
    uint32_t v;
    if (mpHandle) {
        v = static_cast<Handle_ac2c88*>(mpHandle)->Fn10();
    } else {
        v = Fn0091a3e2(&mName);
    }
    return v >= gB11dd8;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876bb1 score 40
bool cUnk00ac2c88::Slot46_ac2c88(uint32_t a, uint32_t b)
{
    if (!static_cast<Owner_ac2c88*>(mpOwner)->Fn18()) {
        return true;
    }
    if (static_cast<uint8_t>(a) != 0) {
        mbF48 = 1;
    }
    if (mnF5c == 1) {
        Slot47_ac2c88();
    }
    if (mbBC == 0) {
        Slot44_ac2c88(b);
    }
    static_cast<Rec_ac2c88*>(mpRecord)->mn30 = 1;
    if (maBuffers[0] == 0) {
        return false;
    }
    DSBuf_ac2c88* buf = OB_PTR(DSBuf_ac2c88, maBuffers[0]);
    while (buf->SetCurrentPosition(0) != 0) {
        static_cast<Rec_ac2c88*>(mpRecord)->Assign(0);
        return false;
    }
    if (mnVolume != 0x400) {
        Slot21_ac2c88(mnVolume);
    }
    buf = OB_PTR(DSBuf_ac2c88, maBuffers[0]);
    buf->Play(0, 0, static_cast<Rec_ac2c88*>(mpRecord)->mn34 != 0 ? 1 : 0);
    mbF4a = 1;
    Fn008760c3();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876e76 score 9
bool cUnk00ac2c88::Slot47_ac2c88()
{
    mbF4a = 0;
    Fn008760c3();
    if (mpHandle) {
        if (static_cast<Handle_ac2c88*>(mpHandle)->Fn09()) {
            static_cast<Handle_ac2c88*>(mpHandle)->Fn08();
        }
    }
    mbBC = 0;
    if (maBuffers[0] && mpRecord) {
        Rec_ac2c88* r = static_cast<Rec_ac2c88*>(mpRecord);
        r->mn1c = 1;
        if (r->mn30) {
            r->mn30 = 0;
            OB_PTR(DSBuf_ac2c88, maBuffers[0])->Stop();
            static_cast<Rec_ac2c88*>(mpRecord)->Assign(0);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876ee6 score 2
bool cUnk00ac2c88::Slot03_ac2bf0(uint32_t a)
{
    mpListener = OB_PTR(void, a);
    static_cast<Listener_ac2c88*>(mpListener)->AddRef();
    mbF4c = 1;
    Fn008760c3();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876f07 score 2
bool cUnk00ac2c88::Slot04_ac2bf0()
{
    if (mpListener) {
        static_cast<Listener_ac2c88*>(mpListener)->Release();
        mpListener = 0;
    }
    mbF4c = 0;
    Fn008760c3();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00877008 score 9
bool cUnk00ac2c88::Slot04_ac2c88()
{
    Slot08_ac2c88();
    Slot15_ac2c88();
    if (mpRecord) {
        delete static_cast<Rec_ac2c88*>(mpRecord);
        mpRecord = 0;
    }
    reinterpret_cast<AutoRef_ac2c88*>(&mpHandle)->Assign(0);
    return true;
}
#endif

// FUNCTION: 0x00877620
void cUnk00ac2c88::Slot13_ad3e48(uint32_t)
{
    if (!Slot07_ac2c88() && mbCC) {
        mbCC = 0;
        Release();
    }
    if (mbF4a) {
        Fn00877177();
    }
    if (mbF4b) {
        Fn00877102();
    }
    if (mbF4c) {
        Fn00877585();
    }
}

// FUNCTION: 0x008777e5
void cUnk00ac2c88::Slot17_ac2c88(uint32_t)
{
    Slot08_ac2c88();
}

// FUNCTION: 0x008777ed
void cUnk00ac2c88::Slot18_ac2c88()
{
    Slot06_ac2c88(Slot20_ac2c88(), 0, 1);
}

// FUNCTION: 0x00877803
uint32_t cUnk00ac2c88::Slot19_ac2c88()
{
    return !Slot07_ac2c88();
}

// FUNCTION: 0x00877819
bool cUnk00ac2c88::Slot33_ac2c88(uint32_t a)
{
    reinterpret_cast<Member1c_ac2c88*>(unknown1c)->Fn14(a);
    return true;
}

// FUNCTION: 0x009d41b1
bool cUnk00ac2c88::Slot34_ac2c88(uint32_t a)
{
    OB_PTR(Peer_ac2c88, a)->Fn14(unknown1c);
    return true;
}

// FUNCTION: 0x00878142
bool cUnk00ac2c88::Slot35_ac2c88(uint32_t a, uint32_t b, uint32_t c)
{
    Guard_ac2c88 guard(reinterpret_cast<Lock_ac2c88*>(&mLock[0]));
    mName.assign(OB_PTR(const char, a), OB_PTR(const char, a + b));
    field7c = c;
    mbF48 = 0;
    if (c == 1) {
        mbF49 = 1;
    } else if (c == 2) {
        mbF49 = Slot45_ac2c88();
    } else {
        mbF49 = 0;
    }
    mbF54 = mbF49;
    bool r = Slot38_ac2c88();
    return r;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00878041 score 88
bool cUnk00ac2c88::Slot38_ac2c88()
{
    Path_ac2c88 path(&mName);
    bool r = false;
    cRZString ext(*reinterpret_cast<cRZString*>(path.Fn0091c31f(0, 0xffffffff)));
    ext.MakeUpper();
    if (mpOwner) {
        uint32_t key;
        if (static_cast<Owner_ac2c88*>(mpOwner)->Fn24(&ext, &key)) {
            Opened_ac2c88* ref = 0;
            Svc_ac2c88* svc = Fn0090ddf1();
            if (ref) {
                ref = 0;
            }
            svc->Fn03(key, 0x3afd825f, reinterpret_cast<void**>(&ref));
            if (ref) {
                if (ref->Fn03(mName.c_str())) {
                    ref->Fn07();
                    reinterpret_cast<AutoRef_ac2c88*>(&mpHandle)->Fn00969fea(&ref);
                    if (ref) {
                        ref->Release();
                    }
                    r = true;
                } else {
                    ref->Release();
                }
            }
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00876c73 score 121
bool cUnk00ac2c88::Slot44_ac2c88(uint32_t a)
{
    if (!static_cast<Sink_ac2c88*>(mpSinkHolder)->Fn03()) {
        return true;
    }
    uint32_t one = 1;
    uint32_t zero = 0;
    void* p1;
    uint32_t s1;
    void* p2;
    uint32_t s2;
    if (static_cast<uint8_t>(a) != 0) {
        if (!Slot50_ac2c88(one)) {
            goto fail;
        }
    }
    mbF54 = 0;
    if (mpHandle == 0) {
        goto fail;
    }
    if (!static_cast<Handle_ac2c88*>(mpHandle)->Fn09() && !static_cast<Handle_ac2c88*>(mpHandle)->Fn07()) {
        goto fail;
    }
    {
        Rec_ac2c88* r = static_cast<Rec_ac2c88*>(mpRecord);
        r->mn1c = 0;
        r->mn20 = 0;
        r->mn24 = 0;
        r->mn34 = 1;
        r->mn18 = 0;
        r->mn14 = 0;
        if (OB_PTR(DSBuf_ac2c88, maBuffers[0])->Lock(0, r->mn04, &p1, &s1, &p2, &s2, 0) != 0) {
            goto fail;
        }
        if (s1 != 0) {
            uint32_t n = static_cast<Rec_ac2c88*>(mpRecord)->mpSrc->Fn14(p1, s1);
            static_cast<Rec_ac2c88*>(mpRecord)->mn14 += n;
            if (n == 0) {
                OB_PTR(DSBuf_ac2c88, maBuffers[0])->Unlock(p1, s1, p2, s2);
                goto fail;
            }
            if (n < s1) {
                if (mbF48 == zero) {
                    static_cast<Rec_ac2c88*>(mpRecord)->mn34 = 0;
                    static_cast<Rec_ac2c88*>(mpRecord)->mn20 = 1;
                    Rec_ac2c88* q = static_cast<Rec_ac2c88*>(mpRecord);
                    q->mn24 = n / q->mn08;
                    const Wave_ac2c88* w = reinterpret_cast<const Wave_ac2c88*>(&mFormat[0]);
                    memset(static_cast<uint8_t*>(p1) + n, w->mBits == 8 ? 0x80 : 0, s1 - n);
                    if (OB_PTR(DSBuf_ac2c88, maBuffers[0])->Unlock(p1, s1, p2, s2) != 0) {
                        static_cast<Rec_ac2c88*>(mpRecord)->Assign(0);
                        return false;
                    }
                } else {
                    do {
                        uint8_t* q = static_cast<uint8_t*>(p1) + n;
                        s1 -= n;
                        static_cast<Rec_ac2c88*>(mpRecord)->mpSrc->Fn15();
                        n = static_cast<Rec_ac2c88*>(mpRecord)->mpSrc->Fn14(q, s1);
                        static_cast<Rec_ac2c88*>(mpRecord)->mn14 += n;
                        p1 = q;
                    } while (n < s1);
                }
            }
        }
        r = static_cast<Rec_ac2c88*>(mpRecord);
        r->mn0c = 0;
        r->mn10 = 0;
        r->mn18 = 0;
        r->mn1c = 0;
        mbBC = 1;
        return true;
    }
fail:
    static_cast<Rec_ac2c88*>(mpRecord)->Assign(0);
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00877ad4 score 199
bool cUnk00ac2c88::Slot06_ac2c88(uint32_t a, uint32_t b, uint32_t c)
{
    if (static_cast<Owner_ac2c88*>(mpOwner)->Fn49()) {
        if (mpHandle) {
            cRZString s;
            if (static_cast<Handle_ac2c88*>(mpHandle)->Fn04(&s)) {
                FILE* f = fopen("log", "a");
                fprintf(f, "%s\n", s.c_str());
                fclose(f);
            }
        }
        return true;
    }
    if (!static_cast<Owner_ac2c88*>(mpOwner)->Fn18()) {
        return true;
    }
    uint32_t buf;
    mnVolume = a;
    if (mbF54) {
        mbF54 = 0;
        Slot15_ac2c88();
    }
    if (mbF49) {
        return Slot46_ac2c88(b, 1);
    }
    if (!Slot16_ac2c88()) {
        if (!Slot14_ac2c88()) {
            return false;
        }
    }
    uint32_t mode = c;
    if (mode == 0) {
        mode = mnF5c;
    }
    if (Slot07_ac2c88()) {
        buf = Fn008769cc();
        if (buf == 0) {
            buf = maBuffers[0];
        }
        if (mode == 1) {
            OB_PTR(DSBuf_ac2c88, buf)->SetCurrentPosition(0);
            Slot21_ac2c88(a);
            goto done;
        }
        if (mode == 2) {
            goto done;
        }
        if (mode == 3) {
            if (!Slot48_ac2c88(OB_ADDR(&buf))) {
                return false;
            }
        }
    } else {
        buf = maBuffers[0];
    }
    {
        Slot21_ac2c88(mnVolume);
        uint32_t flags = b != 0 ? 1 : 0;
        DSBuf_ac2c88* d = OB_PTR(DSBuf_ac2c88, buf);
        d->SetCurrentPosition(0);
        long hr = d->Play(0, 0, flags);
        if (hr != 0) {
            if (hr != static_cast<long>(0x88780096)) {
                return false;
            }
            if (d->Restore() != 0) {
                return false;
            }
            if (d->Play(0, 0, flags) != 0) {
                return false;
            }
        }
    }
done:
    if (mpListener) {
        mbF4c = 1;
        Fn008760c3();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00877d7a score 231
bool cUnk00ac2c88::Slot50_ac2c88(uint32_t a)
{
    if (!static_cast<Sink_ac2c88*>(mpSinkHolder)->Fn03()) {
        return false;
    }
    if (Slot07_ac2c88()) {
        if (static_cast<uint8_t>(a) == 0) {
            return false;
        }
        Slot08_ac2c88();
    }
    if (mpRecord == 0) {
        Rec_ac2c88* n = new Rec_ac2c88;
        n->Fn008762d1();
        mpRecord = n;
    }
    Rec_ac2c88* r = static_cast<Rec_ac2c88*>(mpRecord);
    r->mn04 = 0;
    r->mn08 = 0;
    r->mn0c = 0;
    r->mn10 = 0;
    r->mn18 = 0;
    r->mn1c = 1;
    r->mn20 = 0;
    r->mn24 = 0;
    r->mn28 = 0;
    r->mn38 = 0;
    r->mn30 = 0;
    r->mn2c = 0;
    r->mn34 = 0;
    if (mpHandle == 0) {
        if (!Slot38_ac2c88()) {
            return false;
        }
    }
    reinterpret_cast<AutoRef_ac2c88*>(&static_cast<Rec_ac2c88*>(mpRecord)->mpSrc)->Fn00969fea(&mpHandle);
    memcpy(mFormat, static_cast<Rec_ac2c88*>(mpRecord)->mpSrc->Fn16(), 20);
    if (maBuffers[0]) {
        Slot42_ac2c88();
    }
    r = static_cast<Rec_ac2c88*>(mpRecord);
    r->mn04 = (mFormat[2] / 8 * 512 / 128) * mnC0 * 6;
    r->mn08 = r->mn04 / (mnC0 * 6);
    cRZString tail(mName.Right(4));
    tail.MakeUpper();
    bool match = Fn00418a40(tail.Right(2).c_str(), "FD") != 0;
    r = static_cast<Rec_ac2c88*>(mpRecord);
    if (match && (r->mn08 & 3)) {
        r->mn08 = (r->mn08 - (r->mn08 & 3)) + 4;
    }
    r = static_cast<Rec_ac2c88*>(mpRecord);
    r->mn04 = r->mn08 * mnC0 * 6;
    mnBufferBytes = r->mn04;
    DSDesc_ac2c88 d;
    memset(&d, 0, 0x24);
    d.mSize = 0x24;
    d.mBytes = static_cast<Rec_ac2c88*>(mpRecord)->mn04;
    d.mpFormat = &mFormat[0];
    d.mFlags = (mnBits < 0x40 ? 8 : 0) + 0x100e0;
    if (gpB54088->CreateSoundBuffer(&d, &maBuffers[0], 0) != 0) {
        return false;
    }
    return true;
}
#endif
