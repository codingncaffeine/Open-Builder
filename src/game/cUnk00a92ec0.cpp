#include "classes/cUnk00a92ec0.h"
#include "gzcom/cRZString.h"

struct cLockGuardObj_a92ec0 {
    virtual void Fn0();
    virtual void Lock();
    virtual void Unlock();
};
static inline cLockGuardObj_a92ec0* LockOf(cUnk00a92ec0* p)
{
    return reinterpret_cast<cLockGuardObj_a92ec0*>(reinterpret_cast<char*>(p) + 0xc);
}

// FUNCTION: 0x004de2e0
bool cUnk00a92ec0::Slot00_a92ec0(uint32_t riid, uint32_t ppv)
{
    if (riid == 1 || riid == 0x6a43347d || riid == 0x8a433690) {
        *reinterpret_cast<cUnk00a92ec0**>(ppv) = this;
        Slot01_a92ec0();
        return true;
    }
    return false;
}

// FUNCTION: 0x004de310
bool cUnk00a92ec0::Slot04_a92ec0()
{
    if (mbInitialized) {
        mbInitialized = false;
        Slot06_a92ec0();
    }
    return true;
}

// FUNCTION: 0x004de4b0
uint32_t cUnk00a92ec0::Slot01_a92ec0()
{
    cLockGuardObj_a92ec0* lock = LockOf(this);
    lock->Lock();
    uint32_t n = ++mnRefCount;
    lock->Unlock();
    return n;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004de4e0 score 2
uint32_t cUnk00a92ec0::Slot02_a92ec0()
{
    cLockGuardObj_a92ec0* lock = LockOf(this);
    lock->Lock();
    uint32_t n = mnRefCount;
    if (n > 1) {
        mnRefCount = n - 1;
        lock->Unlock();
        return n - 1;
    }
    lock->Unlock();
    Slot04_a92ec0();
    delete this;
    return 0;
}
#endif

// FUNCTION: 0x004de530
bool cUnk00a92ec0::Slot06_a92ec0()
{
    Fn004de330();
    mbReady = false;
    return true;
}

// FUNCTION: 0x004de540
bool cUnk00a92ec0::Slot07_a92ec0()
{
    cLockGuardObj_a92ec0* lock = LockOf(this);
    lock->Lock();
    bool ready = mbReady;
    lock->Unlock();
    return ready;
}

// FUNCTION: 0x004de560
uint32_t cUnk00a92ec0::Slot10_a92ec0(uint32_t up)
{
    cLockGuardObj_a92ec0* lock = LockOf(this);
    lock->Lock();
    uint32_t n;
    if (*reinterpret_cast<bool*>(&up)) {
        n = ++mnCounter;
    } else {
        n = --mnCounter;
    }
    lock->Unlock();
    return n;
}

// FUNCTION: 0x004de5b0
uint32_t cUnk00a92ec0::Slot11_a92ec0()
{
    cLockGuardObj_a92ec0* lock = LockOf(this);
    lock->Lock();
    uint32_t n = mnPercent;
    lock->Unlock();
    return n;
}

// FUNCTION: 0x004de5d0
void cUnk00a92ec0::Slot12_a92ec0(uint32_t value)
{
    cLockGuardObj_a92ec0* lock = LockOf(this);
    lock->Lock();
    if (value > 100) {
        value = 100;
    }
    mnPercent = value;
    lock->Unlock();
}


struct cGameSettings {
    char pad[0x4ed];
    bool mbFlag;
};
// GLOBAL: 0x00b43cd8
extern cGameSettings* gpSettings;
struct cGameNotify {
    virtual void F00(); virtual void F01(); virtual void F02(); virtual void F03();
    virtual void F04(); virtual void F05(); virtual void F06(); virtual void F07();
    virtual void F08(); virtual void F09(); virtual void F10(); virtual void F11();
    virtual void F12(); virtual void F13(); virtual void F14(); virtual void F15(); virtual void F16();
    virtual void Refresh();
};
// GLOBAL: 0x00b43c94
extern cGameNotify* gpNotify;

#ifdef OB_DRAFTS
// CLOSE: 0x004de600 score 10
void cUnk00a92ec0::Slot09_a92ec0(uint32_t flag)
{
    bool on = *reinterpret_cast<char*>(&flag) != 0;
    gpSettings->mbFlag = on;
    gpNotify->Refresh();
}
#endif

// FUNCTION: 0x004def60
void cUnk00a92ec0::Slot14_a92ec0(void* other)
{
    cRZString* str = reinterpret_cast<cRZString*>(reinterpret_cast<char*>(this) + 0x2c);
    *str = *static_cast<cRZString*>(other);
}

inline cRZString& StrAt(cUnk00a92ec0* p, uint32_t off)
{
    return *reinterpret_cast<cRZString*>(reinterpret_cast<char*>(p) + off);
}
struct cStringService {
    virtual void F00(); virtual void F01(); virtual void F02(); virtual void F03(); virtual void F04();
    virtual bool Query(uint32_t clsid, uint32_t iid, void* out);
    virtual void F06();
    virtual const char* GetA();
    virtual void F08(); virtual void F09(); virtual void F10();
    virtual const char* GetB();
};
struct cServiceRef {
    cStringService* mp;
    // STUB: 0x004de460
    void Fn004de460();
};
// STUB: 0x008793ec
cStringService* Fn008793ec();

// FUNCTION: 0x004ded20
bool cUnk00a92ec0::Slot03_a92ec0()
{
    if (!mbInitialized) {
        mbInitialized = true;
        cServiceRef ref;
        ref.mp = 0;
        cStringService* mgr = Fn008793ec();
        if (mgr) {
            mgr->Query(0x2073215d, 0xe0203660, &ref.mp);
        }
        if (StrAt(this, 0x48).empty()) {
            const char* s = ref.mp->GetA();
            if (s) {
                cRZString tmp(s);
                StrAt(this, 0x48) = tmp;
            }
        }
        if (StrAt(this, 0x5c).empty()) {
            const char* s = ref.mp->GetB();
            if (s) {
                cRZString tmp(s);
                StrAt(this, 0x5c) = tmp;
            }
        }
        ref.Fn004de460();
    }
    return true;
}

// STUB: 0x00454bb0
bool Fn00454bb0(const cRZString& a, const cRZString& b);
// STUB: 0x00919e96
bool Fn00919e96(cRZString* s);

// FUNCTION: 0x004e0830
bool cUnk00a92ec0::Slot05_a92ec0()
{
    cLockGuardObj_a92ec0* lock = LockOf(this);
    lock->Lock();
    if (mbInitialized && !mbReady && Slot08_a92ec0()) {
        if (Fn00454bb0(StrAt(this, 0x5c), StrAt(this, 0x48))) {
            cRZString* name = &StrAt(this, 0x2c);
            if (Slot13_a92ec0(name) && Fn00919e96(name) && Fn004e05a0() &&
                *mpList != mpList) {
                mbReady = true;
                Fn004de630();
            }
        }
    }
    lock->Unlock();
    return true;
}

// STUB: 0x00602210
void Fn00602210(cRZString* out);
// GLOBAL: 0x00b097d8
extern const char* gpFileListName;


struct cLockScope {
    cLockGuardObj_a92ec0* mpLock;
    explicit cLockScope(cLockGuardObj_a92ec0* lock)
        : mpLock(lock)
    {
        mpLock->Lock();
    }
    ~cLockScope() { mpLock->Unlock(); }
};


#ifdef OB_DRAFTS
// CLOSE: 0x004def90 score 51 (scored against the whole function, size 0x10b; the map cuts it at 0x18; the original keeps a zero in ebx)
bool cUnk00a92ec0::Slot08_a92ec0()
{
    bool ok = gpSettings->mbFlag != 0;
    if (ok != false) {
        if (StrAt(this, 0x48).empty() || StrAt(this, 0x5c).empty()) {
            cServiceRef ref;
            cStringService* mgr = Fn008793ec();
            ref.mp = 0;
            if (0 != mgr) {
                mgr->Query(0x2073215d, 0xe0203660, &ref.mp);
            }
            if (StrAt(this, 0x48).empty()) {
                const char* s = ref.mp->GetA();
                if (s != 0) {
                    cRZString tmp(s);
                    StrAt(this, 0x48) = tmp;
                }
            }
            if (StrAt(this, 0x5c).empty() != 0) {
                const char* s = ref.mp->GetB();
                if (s != 0) {
                    cRZString tmp(s);
                    StrAt(this, 0x5c) = tmp;
                }
            }
            ref.Fn004de460();
        }
        if (!Fn00454bb0(StrAt(this, 0x48), StrAt(this, 0x5c)) || StrAt(this, 0x48).empty() || StrAt(this, 0x5c).empty()) {
            ok = false;
        }
    }
    return ok;
}
#endif
#ifdef OB_DRAFTS
// CLOSE: 0x004dedf0 score 16 (the std::string temporary of dir + name must outlive the copy)
bool cUnk00a92ec0::Slot13_a92ec0(void* out)
{
    cLockScope scope(LockOf(this));
    cRZString* dest = static_cast<cRZString*>(out);
    if (StrAt(this, 0x2c).empty()) {
        cRZString dir;
        Fn00602210(&dir);
        if (!dir.empty()) {
            cRZString full(dir + gpFileListName);
            *dest = full;
            return true;
        }
        return false;
    }
    *dest = StrAt(this, 0x2c);
    return true;
}
#endif
