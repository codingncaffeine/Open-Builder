#include "classes/cGZSnd3DListener.h"

// STUB: 0x00949ade
bool Fn00949ade(uint32_t value);

// The object this class wraps (field 0x10); only the calls used here are named.
#ifdef _MSC_VER
#define OB_STDCALL_AC2F70 __stdcall
#else
#define OB_STDCALL_AC2F70
#endif

struct cInner_ac2f70 {
    virtual void OB_STDCALL_AC2F70 Pad00();
    virtual void OB_STDCALL_AC2F70 Pad01();
    virtual void OB_STDCALL_AC2F70 Pad02();
    virtual void OB_STDCALL_AC2F70 Pad03();
    virtual void OB_STDCALL_AC2F70 Pad04();
    virtual void OB_STDCALL_AC2F70 Fn05(float* out);
    virtual void OB_STDCALL_AC2F70 Fn06(float* a, float* b);
    virtual void OB_STDCALL_AC2F70 Fn07(float* out);
    virtual void OB_STDCALL_AC2F70 Fn08(float* out);
    virtual void OB_STDCALL_AC2F70 Fn09(float* out);
    virtual void OB_STDCALL_AC2F70 Pad10();
    virtual uint32_t OB_STDCALL_AC2F70 Fn11(float a, uint32_t flag);
    virtual uint32_t OB_STDCALL_AC2F70 Fn12(float a, uint32_t flag);
    virtual uint32_t OB_STDCALL_AC2F70 Fn13(float a, float b, float c, float d, float e, float f, uint32_t flag);
    virtual uint32_t OB_STDCALL_AC2F70 Fn14(float a, float b, float c, uint32_t flag);
    virtual uint32_t OB_STDCALL_AC2F70 Fn15(float a, uint32_t flag);
    virtual uint32_t OB_STDCALL_AC2F70 Fn16(float a, float b, float c, uint32_t flag);
    virtual uint32_t OB_STDCALL_AC2F70 Fn17();
};

static inline cInner_ac2f70* Inner_ac2f70(void* p)
{
    return static_cast<cInner_ac2f70*>(p);
}

static inline float GetValue_ac2f70(const float* p)
{
    return *p;
}

// FUNCTION: 0x0094c4b1
uint32_t cGZSnd3DListener::Init()
{
    ++mnRefCount;
    return mnRefCount;
}

// FUNCTION: 0x009cfa36
void* cGZSnd3DListener::AsIGZSnd3DListenerEx()
{
    return static_cast<cUnk00ac2ad8*>(this);
}

// FUNCTION: 0x00878e43
uint32_t cGZSnd3DListener::Shutdown()
{
    if (--mnRefCount == 0) {
        Fn00878ced(1);
        return 0;
    }
    return mnRefCount;
}

// FUNCTION: 0x00878cd9
void cGZSnd3DListener::Slot11_ac2ad8(uint32_t a)
{
    *reinterpret_cast<float*>(a) = GetValue_ac2f70(&mfValue);
}

static inline float AsFloat_ac2f70(const uint32_t& v)
{
    return *reinterpret_cast<const float*>(&v);
}

static inline float* FloatOut_ac2f70(uint32_t p)
{
    return reinterpret_cast<float*>(p);
}

#ifdef OB_DRAFTS
// CLOSE: 0x008787d7 score 4 (the original compares the field in memory, then reloads it; the spelling that gets there is not found)
void cGZSnd3DListener::Slot05_ac2f70()
{
    if (mpInner) {
        Fn00949ade(Inner_ac2f70(mpInner)->Fn17());
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008787ee score 4 (the original compares the field in memory, then reloads it; the spelling that gets there is not found)
void cGZSnd3DListener::GetPosition(uint32_t a, uint32_t b, uint32_t c)
{
    if (mpInner) {
        float v[3];
        Inner_ac2f70(mpInner)->Fn07(v);
        *FloatOut_ac2f70(a) = v[0];
        *FloatOut_ac2f70(b) = v[1];
        *FloatOut_ac2f70(c) = v[2];
    }
}
#endif

// FUNCTION: 0x00878823
uint32_t cGZSnd3DListener::SetPosition(uint32_t a, uint32_t b, uint32_t c)
{
    Inner_ac2f70(mpInner)->Fn14(AsFloat_ac2f70(a), AsFloat_ac2f70(b), AsFloat_ac2f70(c), 0);
    return Inner_ac2f70(mpInner)->Fn17() == 0;
}

// FUNCTION: 0x0087885d
void cGZSnd3DListener::Slot03_ac2ad8(uint32_t a, uint32_t b, uint32_t c)
{
    float v[3];
    Inner_ac2f70(mpInner)->Fn09(v);
    *FloatOut_ac2f70(a) = v[0];
    *FloatOut_ac2f70(b) = v[1];
    *FloatOut_ac2f70(c) = v[2];
}

// FUNCTION: 0x0087888c
uint32_t cGZSnd3DListener::Slot04_ac2ad8(uint32_t a, uint32_t b, uint32_t c)
{
    return Inner_ac2f70(mpInner)->Fn16(AsFloat_ac2f70(a), AsFloat_ac2f70(b), AsFloat_ac2f70(c), 1) == 0;
}

// FUNCTION: 0x008788b9
void cGZSnd3DListener::GetOrientation(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    float p[3];
    float q[3];
    Inner_ac2f70(mpInner)->Fn06(p, q);
    *FloatOut_ac2f70(a) = p[0];
    *FloatOut_ac2f70(b) = p[1];
    *FloatOut_ac2f70(c) = p[2];
    *FloatOut_ac2f70(d) = q[0];
    *FloatOut_ac2f70(e) = q[1];
    *FloatOut_ac2f70(f) = q[2];
}

// FUNCTION: 0x00878904
uint32_t cGZSnd3DListener::SetOrientation(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    return Inner_ac2f70(mpInner)->Fn13(AsFloat_ac2f70(a), AsFloat_ac2f70(b), AsFloat_ac2f70(c), AsFloat_ac2f70(d), AsFloat_ac2f70(e), AsFloat_ac2f70(f), 1) == 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00878a74 score 6 (the original compares the field in memory, then reloads it; the spelling that gets there is not found)
void cGZSnd3DListener::Slot07_ac2ad8(uint32_t a)
{
    if (mpInner) {
        Inner_ac2f70(mpInner)->Fn05(FloatOut_ac2f70(a));
    } else {
        *FloatOut_ac2f70(a) = 0.0f;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00878ae3 score 6 (the original compares the field in memory, then reloads it; the spelling that gets there is not found)
void cGZSnd3DListener::Slot09_ac2ad8(uint32_t a)
{
    if (mpInner) {
        Inner_ac2f70(mpInner)->Fn08(FloatOut_ac2f70(a));
    } else {
        *FloatOut_ac2f70(a) = 0.0f;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00878a94 score 8 (the original compares the field in memory, then reloads it; the spelling that gets there is not found)
bool cGZSnd3DListener::Slot08_ac2ad8(uint32_t a)
{
    if (mpInner) {
        return Inner_ac2f70(mpInner)->Fn12(AsFloat_ac2f70(a), 0) == 0;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00878b03 score 8 (the original compares the field in memory, then reloads it; the spelling that gets there is not found)
bool cGZSnd3DListener::Slot10_ac2ad8(uint32_t a)
{
    if (mpInner) {
        return Inner_ac2f70(mpInner)->Fn15(AsFloat_ac2f70(a), 0) == 0;
    }
    return true;
}
#endif

// FUNCTION: 0x00878ab9
bool cGZSnd3DListener::Slot12_ac2ad8(uint32_t a)
{
    mfValue = AsFloat_ac2f70(a);
    cInner_ac2f70* inner = Inner_ac2f70(mpInner);
    if (inner) {
        return inner->Fn11(AsFloat_ac2f70(a), 0) == 0;
    }
    return true;
}

// FUNCTION: 0x00878947
void cGZSnd3DListener::Slot05_ac2ad8(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h, uint32_t i, uint32_t j, uint32_t k, uint32_t l)
{
    float p[3];
    float q[3];
    Inner_ac2f70(mpInner)->Fn07(p);
    *FloatOut_ac2f70(a) = p[0];
    *FloatOut_ac2f70(b) = p[1];
    *FloatOut_ac2f70(c) = p[2];
    Inner_ac2f70(mpInner)->Fn09(p);
    *FloatOut_ac2f70(d) = p[0];
    *FloatOut_ac2f70(e) = p[1];
    *FloatOut_ac2f70(f) = p[2];
    Inner_ac2f70(mpInner)->Fn06(p, q);
    *FloatOut_ac2f70(g) = p[0];
    *FloatOut_ac2f70(h) = p[1];
    *FloatOut_ac2f70(i) = p[2];
    *FloatOut_ac2f70(j) = q[0];
    *FloatOut_ac2f70(k) = q[1];
    *FloatOut_ac2f70(l) = q[2];
}

// FUNCTION: 0x008789e0
uint32_t cGZSnd3DListener::Slot06_ac2ad8(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h, uint32_t i, uint32_t j, uint32_t k, uint32_t l)
{
    Inner_ac2f70(mpInner)->Fn14(AsFloat_ac2f70(a), AsFloat_ac2f70(b), AsFloat_ac2f70(c), 1);
    Inner_ac2f70(mpInner)->Fn16(AsFloat_ac2f70(d), AsFloat_ac2f70(e), AsFloat_ac2f70(f), 1);
    Inner_ac2f70(mpInner)->Fn13(AsFloat_ac2f70(g), AsFloat_ac2f70(h), AsFloat_ac2f70(i), AsFloat_ac2f70(j), AsFloat_ac2f70(k), AsFloat_ac2f70(l), 1);
    return Inner_ac2f70(mpInner)->Fn17() == 0;
}

// FUNCTION: 0x00878796
bool cGZSnd3DListener::QueryInterface(uint32_t iid, uint32_t out)
{
    void** pp = reinterpret_cast<void**>(out);
    if (iid == 1) {
        *pp = this;
    } else if (iid == 0x406077d2) {
        *pp = this;
    } else if (iid == 0x5b30e7b3) {
        *pp = static_cast<cUnk00ac2ad8*>(this);
    } else {
        return false;
    }
    Init();
    return true;
}

// The interface id the original passes by address.
// GLOBAL: 0x00aed050
extern const uint32_t g00aed050[4];

struct cIface_ac2f70 {
    virtual uint32_t OB_STDCALL_AC2F70 QueryInterface(const void* iid, void** out);
};

struct cSvc_ac2f70 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual cIface_ac2f70* Fn05();
};

// The base subobject seen with its twelfth slot taking a real float.
struct cBaseView_ac2f70 {
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
    virtual bool Fn12(float value);
};

inline cBaseView_ac2f70* ViewOfBase_ac2f70(cGZSnd3DListener* p)
{
    return reinterpret_cast<cBaseView_ac2f70*>(reinterpret_cast<char*>(p) + sizeof(cGZSnd3DListener_0));
}

struct cHolderA_ac2f70 {
    cSvc_ac2f70* mp;
    // STUB: 0x007ce170
    cHolderA_ac2f70();
    // STUB: 0x007ce1a0
    ~cHolderA_ac2f70();
};

struct cHolderB_ac2f70 {
    cSvc_ac2f70* mp;
    // STUB: 0x00878b28
    cHolderB_ac2f70();
    // STUB: 0x00878b4d
    ~cHolderB_ac2f70();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00878d11 score 20
bool cGZSnd3DListener::CommitDeferredSettings()
{
    cHolderA_ac2f70 a;
    if (a.mp) {
        cHolderB_ac2f70 b;
        if (b.mp && a.mp->Fn05()) {
            uint32_t r = a.mp->Fn05()->QueryInterface(g00aed050, &mpInner);
            if (r) {
                mpInner = 0;
            }
            ViewOfBase_ac2f70(this)->Fn12(mfValue);
            return r == 0;
        }
    }
    return true;
}
#endif
