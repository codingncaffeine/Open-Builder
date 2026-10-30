#include <string.h>
#include <string>

#include "classes/cUnk00ac2e28.h"
#include "gzcom/cRZString.h"

// STUB: 0x00949ade
bool Fn00949ade(uint32_t value);

#ifdef _MSC_VER
#define OB_STDCALL_AC2E28 __stdcall
#else
#define OB_STDCALL_AC2E28
#endif

// The object at field 0xd0, seen through the one slot used here.
struct cOwner_ac2e28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual bool IsReady();
};

// The object the original reaches through a global, seen through the one slot used here.
struct cHost_ac2e28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05();
};

// The sound device's 3D buffer interface (every method takes the buffer first, the callee pops).
struct cDs3D_ac2e28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual uint32_t OB_STDCALL_AC2E28 GetMaxDistance(float* out);
    virtual uint32_t OB_STDCALL_AC2E28 GetMinDistance(float* out);
    virtual void Pad09();
    virtual uint32_t OB_STDCALL_AC2E28 GetPosition(float* out);
    virtual uint32_t OB_STDCALL_AC2E28 GetVelocity(float* out);
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual uint32_t OB_STDCALL_AC2E28 SetMaxDistance(float value, uint32_t apply);
    virtual uint32_t OB_STDCALL_AC2E28 SetMinDistance(float value, uint32_t apply);
    virtual uint32_t OB_STDCALL_AC2E28 SetMode(uint32_t mode, uint32_t apply);
    virtual uint32_t OB_STDCALL_AC2E28 SetPosition(float x, float y, float z, uint32_t apply);
    virtual uint32_t OB_STDCALL_AC2E28 SetVelocity(float x, float y, float z, uint32_t apply);
};

// This object seen through the two slots of the 3D-sound side that the original calls with a real float.
struct cDist_ac2e28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void SetMinF(float value);
    virtual void Pad13();
    virtual void SetMaxF(float value);
};

// The device that holds the sound-volume settings (global 0xb540a0), seen through the one slot used here.
struct cSettings_ac2e28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void GetFloat(float* out);
};

// The object at field 0xd4, and what its slot 12 returns.
struct cSink_ac2e28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Set(void* buffer, float value);
};

struct cSinkHolder_ac2e28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual cSink_ac2e28* Fn12();
};

// The 3D-sound side's own slots 12 and 14 (the minimum and maximum distance) with their real float argument.
inline cDist_ac2e28* DistOf_ac2e28(cUnk00ac2e28* p)
{
    return reinterpret_cast<cDist_ac2e28*>(reinterpret_cast<char*>(p) + 0xd8);
}

inline cOwner_ac2e28* OwnerOf_ac2e28(cUnk00ac2e28* p)
{
    return *reinterpret_cast<cOwner_ac2e28**>(reinterpret_cast<char*>(p) + 0xd0);
}

inline cSinkHolder_ac2e28* SinkHolderOf_ac2e28(cUnk00ac2e28* p)
{
    return *reinterpret_cast<cSinkHolder_ac2e28**>(reinterpret_cast<char*>(p) + 0xd4);
}

inline float AsFloat_ac2e28(const uint32_t& v)
{
    return *reinterpret_cast<const float*>(&v);
}

inline float* FloatOut_ac2e28(uint32_t p)
{
    return reinterpret_cast<float*>(p);
}

// GLOBAL: 0x00b540a4
extern cHost_ac2e28* gpB540a4;

// GLOBAL: 0x00b540a0
extern cSettings_ac2e28* gpB540a0;

// GLOBAL: 0x00b11de0
extern float gB11de0[11];

// FUNCTION: 0x008781b7
bool cUnk00ac2e28::QueryInterface(uint32_t iid, void** out)
{
    if (iid == 0x306077d2) {
        *reinterpret_cast<cUnk00ac2d78**>(out) = this;
        AddRef();
        return true;
    }
    return cUnk00ac2c88::QueryInterface(iid, out);
}

// FUNCTION: 0x008781fe
bool cUnk00ac2e28::Slot06_ac2c88(uint32_t a, uint32_t b, uint32_t c)
{
    if (!OwnerOf_ac2e28(this)->IsReady()) {
        return true;
    }
    if (gpB540a4) {
        gpB540a4->Fn05();
    }
    return cUnk00ac2c88::Slot06_ac2c88(a, b, c);
}

// FUNCTION: 0x0087823a
bool cUnk00ac2e28::Slot21_ac2c88(uint32_t a)
{
    if (!OwnerOf_ac2e28(this)->IsReady()) {
        return true;
    }
    return cUnk00ac2c88::Slot21_ac2c88(a);
}

// FUNCTION: 0x0087825f
void cUnk00ac2e28::Slot04_ac2d78(uint32_t a, uint32_t b, uint32_t c)
{
    if (mpDs3D[0]) {
        float v[3];
        Fn00949ade(static_cast<cDs3D_ac2e28*>(mpDs3D[0])->GetPosition(v));
        *FloatOut_ac2e28(a) = v[0];
        *FloatOut_ac2e28(b) = v[1];
        *FloatOut_ac2e28(c) = v[2];
    }
}

// FUNCTION: 0x0087829b
bool cUnk00ac2e28::Slot05_ac2d78(uint32_t a, uint32_t b, uint32_t c)
{
    if (mpDs3D[0]) {
        uint32_t r = static_cast<cDs3D_ac2e28*>(mpDs3D[0])->SetPosition(AsFloat_ac2e28(a), AsFloat_ac2e28(b), AsFloat_ac2e28(c), 0);
        Fn00949ade(r);
        return r == 0;
    }
    return false;
}

// FUNCTION: 0x008782df
void cUnk00ac2e28::Slot06_ac2d78(uint32_t a, uint32_t b, uint32_t c)
{
    if (mpDs3D[0]) {
        float v[3];
        Fn00949ade(static_cast<cDs3D_ac2e28*>(mpDs3D[0])->GetVelocity(v));
        *FloatOut_ac2e28(a) = v[0];
        *FloatOut_ac2e28(b) = v[1];
        *FloatOut_ac2e28(c) = v[2];
    }
}

// FUNCTION: 0x0087831b
bool cUnk00ac2e28::Slot07_ac2d78(uint32_t a, uint32_t b, uint32_t c)
{
    if (!OwnerOf_ac2e28(this)->IsReady()) {
        return true;
    }
    if (mpDs3D[0]) {
        uint32_t r = static_cast<cDs3D_ac2e28*>(mpDs3D[0])->SetVelocity(AsFloat_ac2e28(a), AsFloat_ac2e28(b), AsFloat_ac2e28(c), 1);
        Fn00949ade(r);
        return r == 0;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00878371 score 4 (the original compares the field in memory and reloads it; with a local for the pointer the compiler tests the loaded register instead; without the local the register allocation of the second call differs)
void cUnk00ac2e28::Slot08_ac2d78(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    if (mpDs3D[0]) {
        float v[3];
        cDs3D_ac2e28* p = static_cast<cDs3D_ac2e28*>(mpDs3D[0]);
        Fn00949ade(p->GetPosition(v));
        *FloatOut_ac2e28(a) = v[0];
        *FloatOut_ac2e28(b) = v[1];
        *FloatOut_ac2e28(c) = v[2];
        cDs3D_ac2e28* q = static_cast<cDs3D_ac2e28*>(mpDs3D[0]);
        Fn00949ade(q->GetVelocity(v));
        *FloatOut_ac2e28(d) = v[0];
        *FloatOut_ac2e28(e) = v[1];
        *FloatOut_ac2e28(f) = v[2];
    }
}
#endif

// FUNCTION: 0x008783dd
bool cUnk00ac2e28::Slot09_ac2d78(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    if (!OwnerOf_ac2e28(this)->IsReady()) {
        return true;
    }
    if (mpDs3D[0]) {
        Fn00949ade(static_cast<cDs3D_ac2e28*>(mpDs3D[0])->SetPosition(AsFloat_ac2e28(a), AsFloat_ac2e28(b), AsFloat_ac2e28(c), 0));
        uint32_t r = static_cast<cDs3D_ac2e28*>(mpDs3D[0])->SetVelocity(AsFloat_ac2e28(d), AsFloat_ac2e28(e), AsFloat_ac2e28(f), 1);
        Fn00949ade(r);
        return r == 0;
    }
    return false;
}

// FUNCTION: 0x0087845d
void cUnk00ac2e28::Slot10_ac2d78(uint32_t a)
{
    if (a < 1) {
        a = 1;
    }
    if (a > 10) {
        a = 10;
    }
    float unit;
    gpB540a0->GetFloat(&unit);
    float v = gB11de0[a] / unit;
    DistOf_ac2e28(this)->SetMinF(v);
    DistOf_ac2e28(this)->SetMaxF(v * 100.0f);
}

// FUNCTION: 0x008784bc
void cUnk00ac2e28::Slot11_ac2d78(uint32_t a)
{
    if (mpDs3D[0]) {
        Fn00949ade(static_cast<cDs3D_ac2e28*>(mpDs3D[0])->GetMinDistance(FloatOut_ac2e28(a)));
    }
}

// FUNCTION: 0x008784d9
bool cUnk00ac2e28::Slot12_ac2d78(uint32_t a)
{
    float& f = *reinterpret_cast<float*>(&a);
    if (f < 1.0f) {
        f = 1.0f;
    }
    if (mpDs3D[0]) {
        uint32_t r = static_cast<cDs3D_ac2e28*>(mpDs3D[0])->SetMinDistance(f, 0);
        Fn00949ade(r);
        return r == 0;
    }
    return true;
}

// FUNCTION: 0x00878522
void cUnk00ac2e28::Slot13_ac2d78(uint32_t a)
{
    if (mpDs3D[0]) {
        static_cast<cDs3D_ac2e28*>(mpDs3D[0])->GetMaxDistance(FloatOut_ac2e28(a));
    }
}

// FUNCTION: 0x00878538
bool cUnk00ac2e28::Slot14_ac2d78(uint32_t a)
{
    if (mpDs3D[0]) {
        uint32_t r = static_cast<cDs3D_ac2e28*>(mpDs3D[0])->SetMaxDistance(AsFloat_ac2e28(a), 0);
        Fn00949ade(r);
        return r == 0;
    }
    return true;
}

// FUNCTION: 0x00878762
bool cUnk00ac2e28::Slot30_ac2c88(uint32_t a, uint32_t)
{
    cSink_ac2e28* sink = SinkHolderOf_ac2e28(this)->Fn12();
    if (mpDs3D[0]) {
        sink->Set(mpDs3D[0], static_cast<float>(static_cast<int32_t>(a)) * 0.007874016f);
    }
    return true;
}

// The sound device's buffer description.
struct DsDesc_ac2e28 {
    uint32_t dwSize;
    uint32_t dwFlags;
    uint32_t dwBufferBytes;
    uint32_t dwReserved;
    const void* lpwfxFormat;
    uint32_t guid3DAlgorithm[4];
};

// A COM object released through its third slot.
struct cCom_ac2e28 {
    virtual uint32_t OB_STDCALL_AC2E28 QueryInterface(const void* iid, void** out);
    virtual uint32_t OB_STDCALL_AC2E28 AddRef();
    virtual uint32_t OB_STDCALL_AC2E28 Release();
};

// The sound device (global 0xb54088).
struct cDs_ac2e28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual uint32_t OB_STDCALL_AC2E28 CreateSoundBuffer(DsDesc_ac2e28* desc, void** out, void* outer);
};

// The lock object embedded at offset 0x64.
struct Lock_ac2e28 {
    virtual void Pad0_ac2e28();
    virtual void Enter_ac2e28();
    virtual void Leave_ac2e28();
};

// A scope guard over that lock: the constructor takes it, the destructor lets it go.
struct Guard_ac2e28 {
    uint32_t mPad;
    Lock_ac2e28* mpLock;

    // STUB: 0x0048c9f0
    Guard_ac2e28(Lock_ac2e28* lock);
    ~Guard_ac2e28() { mpLock->Leave_ac2e28(); }
};

// GLOBAL: 0x00b54088
extern cDs_ac2e28* gpB54088;

// The interface id the original passes by address.
// GLOBAL: 0x00aed040
extern const uint32_t g00aed040[4];

inline uint32_t& U32At_ac2e28(cUnk00ac2e28* p, uint32_t offset)
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(p) + offset);
}

// FUNCTION: 0x008786fc
bool cUnk00ac2e28::Slot42_ac2c88()
{
    Guard_ac2e28 guard(reinterpret_cast<Lock_ac2e28*>(reinterpret_cast<char*>(this) + 0x64));
    void** p = &mpDs3D[0];
    for (int32_t n = 8; n != 0; --n, ++p) {
        if (*p) {
            static_cast<cCom_ac2e28*>(*p)->Release();
            *p = 0;
        }
    }
    void** q = reinterpret_cast<void**>(&field80);
    for (int32_t n = 8; n != 0; --n, ++q) {
        if (*q) {
            static_cast<cCom_ac2e28*>(*q)->Release();
            *q = 0;
        }
    }
    return true;
}

// FUNCTION: 0x0087856a
bool cUnk00ac2e28::Slot49_ac2c88(uint32_t a)
{
    if (!OwnerOf_ac2e28(this)->IsReady()) {
        return true;
    }
    DsDesc_ac2e28* d = reinterpret_cast<DsDesc_ac2e28*>(a);
    if (d) {
        if (static_cast<int32_t>(field60) < 0x40) {
            d->dwFlags = (d->dwFlags & ~4u) | 8u;
        } else {
            d->dwFlags &= ~8u;
        }
        d->dwFlags = (d->dwFlags & ~0x40u) | 0x20010u;
        void** bufs = reinterpret_cast<void**>(&field80);
        uint32_t hr = gpB54088->CreateSoundBuffer(d, bufs, 0);
        Fn00949ade(hr);
        if (hr != 0) {
            d->dwFlags &= 0xfffdffefu;
            return Fn008766d8(d);
        } else {
            hr = static_cast<cCom_ac2e28*>(bufs[0])->QueryInterface(g00aed040, &mpDs3D[0]);
            Fn00949ade(hr);
            if (hr != 0) {
                d->dwFlags = (d->dwFlags & 0xfffdffefu) | 0x40u;
                return Fn008766d8(d);
            } else {
                if (fieldfc) {
                    Fn00949ade(static_cast<cDs3D_ac2e28*>(mpDs3D[0])->SetMode(1, 0));
                }
                return true;
            }
        }
    }
    DsDesc_ac2e28 local;
    uint32_t flags = U32At_ac2e28(this, 0xc4) | 0x20090u;
    local.dwBufferBytes = U32At_ac2e28(this, 0xa0);
    local.dwSize = 0x24;
    local.dwReserved = 0;
    local.lpwfxFormat = &fielda4;
    if (static_cast<int32_t>(field60) < 0x40) {
        flags = (flags & ~4u) | 8u;
    } else {
        flags &= ~8u;
    }
    local.dwFlags = flags;
    void** bufs = reinterpret_cast<void**>(&field80);
    uint32_t hr = gpB54088->CreateSoundBuffer(&local, bufs, 0);
    Fn00949ade(hr);
    if (hr == 0) {
        hr = static_cast<cCom_ac2e28*>(bufs[0])->QueryInterface(g00aed040, &mpDs3D[0]);
        Fn00949ade(hr);
    }
    if (hr != 0) {
        local.dwFlags = (local.dwFlags & 0xfffdffefu) | 0x40u;
        return Fn008766d8(&local);
    }
    if (fieldfc) {
        Fn00949ade(static_cast<cDs3D_ac2e28*>(mpDs3D[0])->SetMode(1, 0));
    }
    return true;
}

// STUB: 0x00418a40
bool Fn00418a40(const std::string& text, const char* other);

// A 20-byte wave format record, copied as a whole.
struct Fmt_ac2e28 {
    uint32_t v[5];
};

// The object a record reads the wave format from.
struct cFmtSrc_ac2e28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual Fmt_ac2e28* GetFormat();
};

// The object at field 0x18, seen through the one slot used here.
struct cHandle_ac2e28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Fn15();
};

// The 0x44-byte record at field 0xb8.
struct Rec_ac2e28 {
    cFmtSrc_ac2e28* mpSource;
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

    // STUB: 0x008762d1
    Rec_ac2e28();
    // STUB: 0x00969fea
    void Fn00969fea(void** handle);
};

inline Rec_ac2e28*& RecOf_ac2e28(cUnk00ac2e28* p)
{
    return *reinterpret_cast<Rec_ac2e28**>(reinterpret_cast<char*>(p) + 0xb8);
}

inline void*& PtrAt_ac2e28(cUnk00ac2e28* p, uint32_t offset)
{
    return *reinterpret_cast<void**>(reinterpret_cast<char*>(p) + offset);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00878e5d score 38 (the original keeps zero in edi and takes the buffer array address late; ours hoists that address into edi because of the early test of the field, which moves the other constants)
bool cUnk00ac2e28::Slot50_ac2c88(uint32_t a)
{
    if (!OwnerOf_ac2e28(this)->IsReady()) {
        return true;
    }
    if (Slot07_ac2c88()) {
        if (static_cast<uint8_t>(a) != 0) {
            Slot08_ac2c88();
        } else {
            return false;
        }
    }
    if (RecOf_ac2e28(this) == 0) {
        RecOf_ac2e28(this) = new Rec_ac2e28;
    }
    if (RecOf_ac2e28(this) == 0) {
        return false;
    }
    RecOf_ac2e28(this)->mn04 = 0;
    RecOf_ac2e28(this)->mn08 = 0;
    RecOf_ac2e28(this)->mn0c = 0;
    RecOf_ac2e28(this)->mn10 = 0;
    RecOf_ac2e28(this)->mn18 = 0;
    RecOf_ac2e28(this)->mn14 = 0;
    RecOf_ac2e28(this)->mn1c = 1;
    RecOf_ac2e28(this)->mn20 = 0;
    RecOf_ac2e28(this)->mn24 = 0;
    RecOf_ac2e28(this)->mn28 = 0;
    RecOf_ac2e28(this)->mn38 = 0;
    RecOf_ac2e28(this)->mn30 = 0;
    RecOf_ac2e28(this)->mn2c = 0;
    void*& handle = PtrAt_ac2e28(this, 0x18);
    RecOf_ac2e28(this)->mn34 = 0;
    if (handle) {
        static_cast<cHandle_ac2e28*>(handle)->Fn15();
    }
    if (handle == 0) {
        if (!Slot38_ac2c88()) {
            return false;
        }
    }
    RecOf_ac2e28(this)->Fn00969fea(&handle);
    *reinterpret_cast<Fmt_ac2e28*>(&fielda4) = *RecOf_ac2e28(this)->mpSource->GetFormat();
    if (field80 != 0) {
        Slot42_ac2c88();
    }
    RecOf_ac2e28(this)->mn04 = (U32At_ac2e28(this, 0xac) / 8 * 512 / 128) * U32At_ac2e28(this, 0xc0) * 6;
    RecOf_ac2e28(this)->mn08 = RecOf_ac2e28(this)->mn04 / (U32At_ac2e28(this, 0xc0) * 6);
    cRZString upper(reinterpret_cast<cRZString*>(reinterpret_cast<char*>(this) + 0x34)->Right(4), 0, 0xffffffffu);
    upper.MakeUpper();
    bool isXA = Fn00418a40(upper.Right(2), "XA");
    if (isXA && (RecOf_ac2e28(this)->mn08 & 3) != 0) {
        RecOf_ac2e28(this)->mn08 = RecOf_ac2e28(this)->mn08 - (RecOf_ac2e28(this)->mn08 & 3) + 4;
    }
    RecOf_ac2e28(this)->mn04 = RecOf_ac2e28(this)->mn08 * U32At_ac2e28(this, 0xc0) * 6;
    U32At_ac2e28(this, 0xa0) = RecOf_ac2e28(this)->mn04;
    DsDesc_ac2e28 desc;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 0x100e0;
    desc.dwBufferBytes = RecOf_ac2e28(this)->mn04;
    desc.lpwfxFormat = &fielda4;
    desc.dwFlags = ((static_cast<uint32_t>(static_cast<int32_t>(field60) < 0x40) * 8u + 0x100e0u) & ~0x40u) | 0x20010u;
    void** bufs = &mpDs3D[0] - 23;
    uint32_t hr = gpB54088->CreateSoundBuffer(&desc, bufs, 0);
    if (hr != 0) {
        Fn00949ade(hr);
        return false;
    }
    hr = static_cast<cCom_ac2e28*>(bufs[0])->QueryInterface(g00aed040, &mpDs3D[0]);
    if (hr != 0) {
        mpDs3D[0] = 0;
    }
    if (fieldfc) {
        Fn00949ade(static_cast<cDs3D_ac2e28*>(mpDs3D[0])->SetMode(1, 0));
    }
    return true;
}
#endif
