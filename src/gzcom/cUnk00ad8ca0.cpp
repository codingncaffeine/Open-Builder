#include "classes/cUnk00ad8ca0.h"
#include "gzcom/cIGZUnknown.h"

// The lock object embedded at offset 8 (a vtable and one word); only the slots used here are named.
struct Lock_ad8ca0 {
    virtual void Pad0_ad8ca0();
    virtual void Enter_ad8ca0();
    virtual void Leave_ad8ca0();
};

// A scope guard over the embedded lock: the constructor takes the lock, the destructor lets it go.
struct Guard_ad8ca0 {
    uint32_t mPad;
    Lock_ad8ca0* mpLock;

    // STUB: 0x0048c9f0
    Guard_ad8ca0(Lock_ad8ca0* lock);
    ~Guard_ad8ca0() { mpLock->Leave_ad8ca0(); }
};

// FUNCTION: 0x009756aa
bool cUnk00ad8ca0::Slot00_ad8fc8(uint32_t a, void* b)
{
    bool found;
    if ((a == 0x656b8f0c || a == 1) != 0) {
        *static_cast<cUnk00ad8ca0**>(b) = this;
        Slot01_ad8fc8();
        found = true;
    } else {
        found = false;
    }
    return found;
}

// FUNCTION: 0x009756cf
uint32_t cUnk00ad8ca0::Slot01_ad8fc8()
{
    Guard_ad8ca0 guard(reinterpret_cast<Lock_ad8ca0*>(&mLock[0]));
    return ++mnRefCount;
}

// FUNCTION: 0x009756f6
uint32_t cUnk00ad8ca0::Slot02_ad8fc8()
{
    Lock_ad8ca0* lock = reinterpret_cast<Lock_ad8ca0*>(&mLock[0]);
    lock->Enter_ad8ca0();
    uint32_t n;
    if (mnRefCount > 1) {
        n = --mnRefCount;
        lock->Leave_ad8ca0();
    } else {
        lock->Leave_ad8ca0();
        Slot31_ad8ca0();
        n = 0;
    }
    return n;
}

// FUNCTION: 0x0097572e
void cUnk00ad8ca0::Slot31_ad8ca0()
{
    delete this;
}

// FUNCTION: 0x0097573a
bool cUnk00ad8ca0::Slot19_ad8ca0(uint32_t a)
{
    Guard_ad8ca0 guard(reinterpret_cast<Lock_ad8ca0*>(&mLock[0]));
    return Slot32_ad8ca0(a);
}

// FUNCTION: 0x0097576e
uint32_t cUnk00ad8ca0::Slot20_ad8ca0(uint32_t a)
{
    Guard_ad8ca0 guard(reinterpret_cast<Lock_ad8ca0*>(&mLock[0]));
    return Slot33_ad8ca0(a);
}

// FUNCTION: 0x009757a0
bool cUnk00ad8ca0::Slot21_ad8ca0(uint32_t a, uint32_t b, uint32_t c)
{
    Guard_ad8ca0 guard(reinterpret_cast<Lock_ad8ca0*>(&mLock[0]));
    return Slot34_ad8ca0(a, b, c);
}

// FUNCTION: 0x009757da
bool cUnk00ad8ca0::Slot22_ad8ca0(uint32_t a, uint32_t b)
{
    Guard_ad8ca0 guard(reinterpret_cast<Lock_ad8ca0*>(&mLock[0]));
    return Slot35_ad8ca0(a, b);
}

// FUNCTION: 0x00975811
bool cUnk00ad8ca0::Slot24_ad8ca0(void* a)
{
    Guard_ad8ca0 guard(reinterpret_cast<Lock_ad8ca0*>(&mLock[0]));
    return Slot36_ad8ca0(a);
}

// FUNCTION: 0x00975845
bool cUnk00ad8ca0::Slot23_ad8ca0(void* a)
{
    cIGZUnknown* item = *reinterpret_cast<cIGZUnknown**>(a);
    if (Slot24_ad8ca0(item)) {
        item->Release();
        return true;
    }
    return false;
}

// FUNCTION: 0x00975867
bool cUnk00ad8ca0::Slot26_ad8ca0(void* a)
{
    Guard_ad8ca0 guard(reinterpret_cast<Lock_ad8ca0*>(&mLock[0]));
    return Slot37_ad8ca0(a);
}

// FUNCTION: 0x0097589b
bool cUnk00ad8ca0::Slot25_ad8ca0(void* a)
{
    cIGZUnknown* item = *reinterpret_cast<cIGZUnknown**>(a);
    if (Slot26_ad8ca0(item)) {
        item->Release();
        return true;
    }
    return false;
}

// FUNCTION: 0x009758bd
bool cUnk00ad8ca0::Slot27_ad8ca0(uint32_t a)
{
    Guard_ad8ca0 guard(reinterpret_cast<Lock_ad8ca0*>(&mLock[0]));
    return Slot38_ad8ca0(a);
}

// FUNCTION: 0x009758f1
uint32_t cUnk00ad8ca0::Slot28_ad8ca0(uint32_t a, uint32_t b, uint32_t c)
{
    Guard_ad8ca0 guard(reinterpret_cast<Lock_ad8ca0*>(&mLock[0]));
    return Slot39_ad8ca0(a, b, c);
}

// FUNCTION: 0x00975929
bool cUnk00ad8ca0::Slot29_ad8ca0(uint32_t a, uint32_t b, uint32_t c)
{
    Guard_ad8ca0 guard(reinterpret_cast<Lock_ad8ca0*>(&mLock[0]));
    return Slot40_ad8ca0(a, b, c);
}

// FUNCTION: 0x00975963
uint32_t cUnk00ad8ca0::Slot17_ad8ca0(uint32_t a)
{
    return Slot18_ad8ca0(a, 0) != 0;
}

// FUNCTION: 0x00975977
bool cUnk00ad8ca0::Slot12_ad8ca0()
{
    reinterpret_cast<Lock_ad8ca0*>(&mLock[0])->Enter_ad8ca0();
    return true;
}

// FUNCTION: 0x00975982
bool cUnk00ad8ca0::Slot13_ad8ca0()
{
    reinterpret_cast<Lock_ad8ca0*>(&mLock[0])->Leave_ad8ca0();
    return true;
}
