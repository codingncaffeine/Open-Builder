#include "classes/cUnk00ac0f80.h"

#include <new>

#include "common/winapi.h"

// The 64-bit result of the error translator.
struct Error64_ac0f80 {
    uint32_t mnLo;
    uint32_t mnHi;
};

// A copy of a 16-byte socket address.
struct SockAddr_ac0f80 {
    uint32_t mn0;
    uint32_t mn4;
    uint32_t mn8;
    uint32_t mnC;
};

// The select() time value and descriptor set.
struct TimeVal_ac0f80 {
    int32_t mnSeconds;
    int32_t mnMicroseconds;
};

struct FdSet_ac0f80 {
    uint32_t mnCount;
    uint32_t mnSockets[64];
};

struct Linger_ac0f80 {
    uint16_t mnOnOff;
    uint16_t mnSeconds;
};

// The reference-counted object the owner/listener is.
struct Ref_ac0f80 {
    virtual bool QueryInterface(uint32_t iid, void** out) = 0;
    virtual void AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Slot03(void* a) = 0;
};

// The event objects Slot53 builds.
struct Event_ac0f80 {
    virtual bool QueryInterface(uint32_t iid, void** out) = 0;
    virtual void AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void SetId(uint32_t id) = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void SetSource(void* source) = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void SetFailed(bool failed) = 0;

    // STUB: 0x009134d6
    Event_ac0f80* Fn009134d6();
};

struct WndClass_ac0f80 {
    uint32_t mnStyle;
    void* mpProc;
    int32_t mnClassExtra;
    int32_t mnWindowExtra;
    void* mpInstance;
    void* mpIcon;
    void* mpCursor;
    void* mpBackground;
    const char* mpMenuName;
    const char* mpClassName;
};

// The winsock functions the original reached through its import thunks.
// STUB: 0x00823efa
int32_t OB_STDCALL Fn00823efa();
// STUB: 0x00823f12
int32_t OB_STDCALL Fn00823f12(int32_t s);
// STUB: 0x00823f18
int32_t OB_STDCALL Fn00823f18(int32_t family, int32_t type, int32_t protocol);
// STUB: 0x00823f1e
int32_t OB_STDCALL Fn00823f1e(int32_t s, const void* set);
// STUB: 0x00823f24
int32_t OB_STDCALL Fn00823f24(int32_t n, void* r, void* w, void* e, const void* timeout);
// STUB: 0x00823f2a
int32_t OB_STDCALL Fn00823f2a(int32_t s, void* window, uint32_t message, uint32_t events);
// STUB: 0x00823f30
int32_t OB_STDCALL Fn00823f30(int32_t s, int32_t backlog);
// STUB: 0x00823f36
int32_t OB_STDCALL Fn00823f36(int32_t s, const void* addr, int32_t len);
// STUB: 0x00823f3c
int32_t OB_STDCALL Fn00823f3c(int32_t s, void* addr, int32_t* len);
// STUB: 0x00823f42
int32_t OB_STDCALL Fn00823f42(int32_t s, void* addr, int32_t* len);
// STUB: 0x00823f48
int32_t OB_STDCALL Fn00823f48(int32_t s, int32_t command, void* arg);
// STUB: 0x00823f4e
int32_t OB_STDCALL Fn00823f4e(int32_t s, int32_t level, int32_t option, const void* value, int32_t len);
// STUB: 0x00823f54
int32_t OB_STDCALL Fn00823f54(int32_t s, int32_t level, int32_t option, void* value, int32_t* len);
// STUB: 0x0081fed0
uint64_t Fn0081fed0(int32_t code);
// STUB: 0x009133da
void* Fn009133da(uint32_t size);
// STUB: 0x0081f770
int32_t OB_STDCALL Fn0081f770(void* window, uint32_t message, uint32_t wparam, int32_t lparam);

OB_WINAPI void* OB_STDCALL GetModuleHandleA(const char* name);
OB_WINAPI int32_t OB_STDCALL DestroyWindow(void* window);
OB_WINAPI int32_t OB_STDCALL GetClassInfoA(void* instance, const char* className, void* wc);
OB_WINAPI void* OB_STDCALL LoadCursorA(void* instance, uint32_t name);
OB_WINAPI void* OB_STDCALL LoadIconA(void* instance, uint32_t name);
OB_WINAPI void* OB_STDCALL GetStockObject(int32_t index);
OB_WINAPI uint32_t OB_STDCALL RegisterClassA(const void* wc);
OB_WINAPI void* OB_STDCALL CreateWindowExA(uint32_t exStyle, const char* className, const char* title, uint32_t style, int32_t x, int32_t y, int32_t width, int32_t height, void* parent, void* menu, void* instance, void* param);
OB_WINAPI int32_t OB_STDCALL SetWindowLongA(void* window, int32_t index, int32_t value);

// Stores a winsock error, translated, in the object.
inline void SetError_ac0f80(cUnk00ac0f80* c, int32_t code)
{
    uint64_t e = Fn0081fed0(code);
    c->mnLastErrorLo = static_cast<uint32_t>(e);
    c->mnLastErrorHi = static_cast<uint32_t>(e >> 32);
}

#define OB_SET_LAST_ERROR_ac0f80() SetError_ac0f80(this, Fn00823efa())

// FUNCTION: 0x0081f8d0
bool cUnk00ac0f80::Slot56_ac0f80()
{
    if (mpWindow) {
        DestroyWindow(*static_cast<void**>(mpWindow));
        ::operator delete(mpWindow);
        mpWindow = 0;
    }
    return true;
}

// FUNCTION: 0x0081f920
bool cUnk00ac0f80::Slot17_ac0f80(void* owner)
{
    if (mpOwner != owner) {
        Ref_ac0f80* p = static_cast<Ref_ac0f80*>(owner);
        if (p) {
            p->AddRef();
        }
        Ref_ac0f80* old = static_cast<Ref_ac0f80*>(mpOwner);
        if (old) {
            old->Release();
        }
        mpOwner = owner;
    }
    return true;
}

// FUNCTION: 0x0081f950
void cUnk00ac0f80::Slot18_ac0f80()
{
    Slot20_ac0f80(0x37);
}

// FUNCTION: 0x0081f960
void cUnk00ac0f80::Slot19_ac0f80()
{
    Slot20_ac0f80(8);
}

// FUNCTION: 0x0081f970
void cUnk00ac0f80::Slot21_ac0f80()
{
    Slot20_ac0f80(0);
}

// FUNCTION: 0x0081f980
bool cUnk00ac0f80::Slot08_ac0f80(uint32_t family, uint32_t type, uint32_t protocol)
{
    mnFamily = family;
    mnType = type;
    mnProtocol = protocol;
    return true;
}

// FUNCTION: 0x0081f9a0
bool cUnk00ac0f80::Slot01_ac0f80()
{
    return mnSocket != -1;
}

// FUNCTION: 0x0081f9b0
void cUnk00ac0f80::Slot06_ac0f80()
{
    Slot07_ac0f80(mLocalAddr);
}

// FUNCTION: 0x0081f9c0
void cUnk00ac0f80::Slot11_ac0f80(void* addr)
{
    Slot10_ac0f80(addr, &mnSocket);
}

// FUNCTION: 0x0081f9e0
void cUnk00ac0f80::Slot14_ac0f80(void* addr)
{
    Slot13_ac0f80(addr, &mnSocket);
}

// FUNCTION: 0x0081fa00
bool cUnk00ac0f80::Slot12_ac0f80(const void* addr)
{
    *reinterpret_cast<SockAddr_ac0f80*>(mLocalAddr) = *static_cast<const SockAddr_ac0f80*>(addr);
    return true;
}

// FUNCTION: 0x0081fa30
bool cUnk00ac0f80::Slot15_ac0f80(const void* addr)
{
    *reinterpret_cast<SockAddr_ac0f80*>(mRemoteAddr) = *static_cast<const SockAddr_ac0f80*>(addr);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00820410 score 5
bool cUnk00ac0f80::Slot05_ac0f80()
{
    mnSocket = Fn00823f18(mnFamily, mnType, mnProtocol);
    if (mnSocket == -1) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820450 score 11
bool cUnk00ac0f80::Slot03_ac0f80()
{
    if (mnSocket != -1) {
        int32_t r = Fn00823f12(mnSocket);
        mnSocket = -1;
        if (r) {
            OB_SET_LAST_ERROR_ac0f80();
            mbBound = 0;
            return false;
        }
    }
    mbBound = 0;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008204a0 score 7
bool cUnk00ac0f80::Slot04_ac0f80(uint32_t backlog)
{
    if (mnSocket != -1) {
        if (Fn00823f30(mnSocket, backlog)) {
            OB_SET_LAST_ERROR_ac0f80();
            return false;
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008204e0 score 5
bool cUnk00ac0f80::Slot07_ac0f80(const void* addr)
{
    *reinterpret_cast<SockAddr_ac0f80*>(mLocalAddr) = *static_cast<const SockAddr_ac0f80*>(addr);
    if (Fn00823f36(mnSocket, mLocalAddr, 16)) {
        mbBound = 0;
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    mbBound = 1;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820540 score 5
bool cUnk00ac0f80::Slot10_ac0f80(void* addr, const void* socketHolder)
{
    int32_t len = 16;
    if (Fn00823f3c(*static_cast<const int32_t*>(socketHolder), addr, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820590 score 5
bool cUnk00ac0f80::Slot13_ac0f80(void* addr, const void* socketHolder)
{
    int32_t len = 16;
    if (Fn00823f42(*static_cast<const int32_t*>(socketHolder), addr, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008207f0 score 5
bool cUnk00ac0f80::Slot41_ac0f80(bool on)
{
    int32_t value = on;
    if (Fn00823f4e(mnSocket, 0xffff, 0x20, &value, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820840 score 5
bool cUnk00ac0f80::Slot42_ac0f80(bool on)
{
    int32_t value = on;
    if (Fn00823f4e(mnSocket, 0xffff, 1, &value, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008208f0 score 5
bool cUnk00ac0f80::Slot44_ac0f80(bool on)
{
    int32_t value = on == false;
    if (Fn00823f4e(mnSocket, 0xffff, 0x10, &value, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820940 score 5
bool cUnk00ac0f80::Slot45_ac0f80(bool on)
{
    int32_t value = on;
    if (Fn00823f4e(mnSocket, 0xffff, 8, &value, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820990 score 5
bool cUnk00ac0f80::Slot46_ac0f80(bool on)
{
    int32_t value = on;
    if (Fn00823f4e(mnSocket, 0xffff, 0x100, &value, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820a80 score 5
bool cUnk00ac0f80::Slot49_ac0f80(bool on)
{
    int32_t value = on;
    if (Fn00823f4e(mnSocket, 0xffff, 4, &value, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008209e0 score 5
bool cUnk00ac0f80::Slot47_ac0f80(uint32_t value)
{
    if (Fn00823f4e(mnSocket, 0xffff, 0x1002, &value, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820a30 score 5
bool cUnk00ac0f80::Slot48_ac0f80(uint32_t value)
{
    if (Fn00823f4e(mnSocket, 0xffff, 0x1001, &value, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820ad0 score 5
bool cUnk00ac0f80::Slot51_ac0f80(uint32_t value)
{
    if (Fn00823f4e(mnSocket, 0xffff, 0x1005, &value, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820b20 score 5
bool cUnk00ac0f80::Slot52_ac0f80(uint32_t value)
{
    if (Fn00823f4e(mnSocket, 0xffff, 0x1006, &value, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820b70 score 5
bool cUnk00ac0f80::Slot29_ac0f80(void* out)
{
    int32_t value;
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 0x20, &value, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    *static_cast<bool*>(out) = value != 0;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820c60 score 5
bool cUnk00ac0f80::Slot32_ac0f80(void* out)
{
    int32_t value;
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 0x10, &value, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    *static_cast<bool*>(out) = value == 0;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820cd0 score 5
bool cUnk00ac0f80::Slot33_ac0f80(void* out)
{
    int32_t value;
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 8, &value, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    *static_cast<bool*>(out) = value != 0;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820d40 score 5
bool cUnk00ac0f80::Slot34_ac0f80(void* out)
{
    int32_t value;
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 0x100, &value, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    *static_cast<bool*>(out) = value != 0;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820e70 score 5
bool cUnk00ac0f80::Slot37_ac0f80(void* out)
{
    int32_t value;
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 4, &value, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    *static_cast<bool*>(out) = value != 0;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820ee0 score 5
bool cUnk00ac0f80::Slot30_ac0f80(void* out)
{
    int32_t value;
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 1, &value, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    *static_cast<bool*>(out) = value != 0;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820db0 score 5
bool cUnk00ac0f80::Slot35_ac0f80(void* out)
{
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 0x1002, out, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820e10 score 5
bool cUnk00ac0f80::Slot36_ac0f80(void* out)
{
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 0x1001, out, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820f50 score 5
bool cUnk00ac0f80::Slot39_ac0f80(void* out)
{
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 0x1005, out, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820fb0 score 5
bool cUnk00ac0f80::Slot40_ac0f80(void* out)
{
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 0x1006, out, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820890 score 5
bool cUnk00ac0f80::Slot43_ac0f80(bool on, uint16_t seconds)
{
    Linger_ac0f80 linger;
    linger.mnOnOff = on != false;
    linger.mnSeconds = seconds;
    if (Fn00823f4e(mnSocket, 0xffff, 0x80, &linger, 4)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820be0 score 5
bool cUnk00ac0f80::Slot31_ac0f80(void* onOut, void* secondsOut)
{
    Linger_ac0f80 linger;
    int32_t len = 4;
    if (Fn00823f54(mnSocket, 0xffff, 0x80, &linger, &len)) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    *static_cast<bool*>(onOut) = linger.mnOnOff != 0;
    *static_cast<uint32_t*>(secondsOut) = linger.mnSeconds;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008203a0 score 9
bool cUnk00ac0f80::Slot20_ac0f80(uint32_t events)
{
    if (Slot55_ac0f80()) {
        mnEvents = events;
        if (Fn00823f2a(mnSocket, *static_cast<void**>(mpWindow), 0x52d, events)) {
            OB_SET_LAST_ERROR_ac0f80();
            return false;
        }
        if (events == 0) {
            Slot56_ac0f80();
        }
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008205e0 score 20
bool cUnk00ac0f80::Slot25_ac0f80(uint32_t timeout, void* out)
{
    uint32_t* available = static_cast<uint32_t*>(out);
    if (timeout != 0) {
        const TimeVal_ac0f80* ptv = 0;
        TimeVal_ac0f80 tv;
        FdSet_ac0f80 fds;
        if (timeout != 0xffffffff) {
            tv.mnSeconds = timeout / 1000;
            tv.mnMicroseconds = (timeout % 1000) * 1000;
            ptv = &tv;
        }
        fds.mnSockets[0] = mnSocket;
        fds.mnCount = 1;
        int32_t r = Fn00823f24(1, &fds, 0, 0, ptv);
        if (r == -1) {
            OB_SET_LAST_ERROR_ac0f80();
            return false;
        }
        if (r == 0) {
            *available = 0;
            return true;
        }
    }
    if (Fn00823f48(mnSocket, 0x4004667f, available)) {
        *available = 0;
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008206d0 score 11
bool cUnk00ac0f80::Slot26_ac0f80(uint32_t timeout)
{
    const TimeVal_ac0f80* ptv = 0;
    TimeVal_ac0f80 tv;
    FdSet_ac0f80 fds;
    if (timeout != 0xffffffff) {
        tv.mnSeconds = timeout / 1000;
        tv.mnMicroseconds = (timeout % 1000) * 1000;
        ptv = &tv;
    }
    fds.mnSockets[0] = mnSocket;
    fds.mnCount = 1;
    int32_t r = Fn00823f24(1, &fds, 0, 0, ptv);
    if (r == -1) {
        OB_SET_LAST_ERROR_ac0f80();
        mnSocket = -1;
        return false;
    }
    return r != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820760 score 9
bool cUnk00ac0f80::Slot27_ac0f80(uint32_t timeout)
{
    const TimeVal_ac0f80* ptv = 0;
    TimeVal_ac0f80 tv;
    FdSet_ac0f80 fds;
    if (timeout != 0xffffffff) {
        tv.mnSeconds = timeout / 1000;
        tv.mnMicroseconds = (timeout % 1000) * 1000;
        ptv = &tv;
    }
    fds.mnSockets[0] = mnSocket;
    fds.mnCount = 1;
    int32_t r = Fn00823f24(1, 0, &fds, 0, ptv);
    if (r == -1) {
        OB_SET_LAST_ERROR_ac0f80();
        return false;
    }
    return r != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0081fa60 score 36
uint32_t cUnk00ac0f80::Slot28_ac0f80(uint32_t flags, uint32_t timeout)
{
    uint32_t result = 0;
    TimeVal_ac0f80 tv;
    TimeVal_ac0f80* ptv = 0;
    if (timeout != 0xffffffff) {
        tv.mnSeconds = timeout / 1000;
        tv.mnMicroseconds = (timeout % 1000) * 1000;
        ptv = &tv;
    }
    FdSet_ac0f80 readSet;
    FdSet_ac0f80 writeSet;
    readSet.mnCount = 0;
    if (flags & 1) {
        readSet.mnSockets[0] = mnSocket;
        readSet.mnCount = 1;
    }
    writeSet.mnCount = 0;
    if (flags & 2) {
        writeSet.mnSockets[0] = mnSocket;
        writeSet.mnCount = 1;
    }
    if (Fn00823f24(0, (flags & 1) ? &readSet : 0, (flags & 2) ? &writeSet : 0, 0, ptv) == -1) {
        return 0xfffffffc;
    }
    if (Fn00823f1e(mnSocket, &readSet)) {
        result = 1;
    }
    if (Fn00823f1e(mnSocket, &writeSet)) {
        result |= 2;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00820260 score 29
bool cUnk00ac0f80::Slot53_ac0f80(uint32_t socket, uint32_t event, uint32_t error)
{
    if (error) {
        uint64_t e = Fn0081fed0(error);
        mnLastErrorLo = static_cast<uint32_t>(e);
        mnLastErrorHi = error;
    }
    Event_ac0f80* ev = 0;
    void* mem = Fn009133da(0x2c);
    if (mem) {
        ev = static_cast<Event_ac0f80*>(mem)->Fn009134d6();
    }
    if (ev) {
        ev->AddRef();
    }
    ev->SetSource(this);
    ev->SetFailed(error != 0);
    if (socket != static_cast<uint32_t>(mnSocket)) {
        ev->Release();
        return false;
    }
    switch (event) {
    case 1:
        ev->SetId(0xab2045c3);
        break;
    case 2:
        ev->SetId(0xab2045c4);
        break;
    case 4:
        ev->SetId(0xab2045c6);
        break;
    case 8:
        ev->SetId(0xab2045ca);
        break;
    case 16:
        ev->SetId(0xab2045d2);
        break;
    case 32:
        ev->SetId(0xab2045e2);
        break;
    }
    Slot54_ac0f80(ev);
    if (mpOwner) {
        static_cast<Ref_ac0f80*>(mpOwner)->Slot03(ev);
    }
    ev->Release();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0081f7d0 score 6
bool cUnk00ac0f80::Slot55_ac0f80()
{
    if (!mpWindow) {
        mpWindow = ::operator new(4);
        void* instance = GetModuleHandleA(0);
        WndClass_ac0f80 wc;
        if (!GetClassInfoA(instance, "cls", &wc)) {
            wc.mpCursor = LoadCursorA(0, 0x7f00);
            wc.mpIcon = LoadIconA(0, 0x7f03);
            wc.mpBackground = GetStockObject(0);
            wc.mpMenuName = 0;
            wc.mpClassName = "cls";
            wc.mpInstance = instance;
            wc.mnStyle = 0;
            wc.mpProc = reinterpret_cast<void*>(Fn0081f770);
            wc.mnClassExtra = 0;
            wc.mnWindowExtra = 4;
            RegisterClassA(&wc);
        }
        void* window = CreateWindowExA(0, "cls", "title", 0, 0, 0, 16, 16, 0, 0, instance, 0);
        if (!window) {
            return false;
        }
        SetWindowLongA(window, -21, reinterpret_cast<intptr_t>(this));
        *static_cast<void**>(mpWindow) = window;
    }
    return true;
}
#endif
