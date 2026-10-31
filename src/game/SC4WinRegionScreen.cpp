#include "gzcom/cIGZUnknown.h"
#include <string.h>
#include "game/Globals.h"
#include <stddef.h>
#include "classes/cSC4RegionalTerrainMap.h"
#include "classes/cUnk00ab8cd0.h"
#include "classes/cSC4WinRegionScreen.h"
#include "classes/cSC4WinRegionView.h"
#include "classes/cUnk00ab8f50.h"
#include "classes/cUnk00ab8cb8.h"

#ifdef _MSC_VER
#define OB_FASTCALL_AB9260 __fastcall
#else
#define OB_FASTCALL_AB9260
#endif

// The window manager seen through its slots 29, 30 and 34.
struct WinMgr_ab9260 {
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
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void SetCapture(void* win);
    virtual void ReleaseCapture(void* win);
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void GetCursorPos(void* win, int32_t* x, int32_t* y);
};

// The command server (global 0xb43cb0), its slot 20.
struct CmdServer_ab9260 {
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
    virtual void Pad18();
    virtual void Pad19();
    virtual void Run(uint32_t command, uint32_t a, uint32_t b);
};

// The hit test object of the screen (field 0x108), its slot 10.
struct HitTest_ab9260 {
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
    virtual bool Hit(uint32_t x, uint32_t z, bool select, uint32_t* command);
};

// The draw context (field 0x6c of a window), slots 42 and 43.
struct DrawCtx_ab8f50 {
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
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Begin();
    virtual void End();
};

// The renderer (global 0xb43dd0), its slot 21.
struct Renderer_ab8f50 {
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
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Draw();
};

#ifdef OB_DRAFTS
// CLOSE: 0x007aa2a0 score 10
bool cSC4RegionalTerrainMap::Slot00_ab3be8(uint32_t iid, uint32_t out)
{
    if (iid == 1) {
        *OB_PTR(void*, out) = this;
    } else if (iid == 0xab953253) {
        *OB_PTR(void*, out) = this;
    } else {
        return false;
    }
    AddRef();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007aa2e0 score 3
void cSC4RegionalTerrainMap::Slot03_ab3be8()
{
    mbInitialized = 1;
}
#endif

// FUNCTION: 0x007aa2f0
bool cSC4RegionalTerrainMap::Slot04_ab3be8()
{
    mbInitialized = 0;
    return true;
}

// FUNCTION: 0x007aa310
uint32_t cSC4RegionalTerrainMap::Slot09_ab3be8(uint32_t x, uint32_t z)
{
    return mnVertsPerRow * z + x;
}

// FUNCTION: 0x007aa320
void cSC4RegionalTerrainMap::Slot10_ab3be8(uint32_t index, uint32_t x, uint32_t z)
{
    int32_t i = static_cast<int32_t>(index);
    *OB_PTR(int32_t, x) = i % mnVertsPerRow;
    *OB_PTR(int32_t, z) = i / mnVertsPerRow;
}

// FUNCTION: 0x007aa350
uint32_t cSC4RegionalTerrainMap::Slot11_ab3be8(uint32_t x, uint32_t z)
{
    float fx = *reinterpret_cast<float*>(&x);
    float fz = *reinterpret_cast<float*>(&z);
    if (fx >= 0.0f && fz >= 0.0f) {
        float inv = 1.0f / mfCellWidth;
        if (fx * inv < static_cast<float>(mnCellsX) && fz * inv < static_cast<float>(mnCellsZ)) {
            return 1;
        }
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007aa3c0 score 40
void cSC4RegionalTerrainMap::Slot15_ab3be8(uint32_t rect, uint32_t out, uint32_t rowStride, uint32_t colStride)
{
    int32_t* r = OB_PTR(int32_t, rect);
    float* p = OB_PTR(float, out);
    for (int32_t y = r[1]; y < r[3]; y++) {
        float* next = p + rowStride;
        for (int32_t x = r[0]; x <= r[2]; x++) {
            *p = mfAltitude;
            p += colStride;
        }
        p = next;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007aa430 score 53
void cSC4RegionalTerrainMap::Slot16_ab3be8(uint32_t rect, uint32_t out, uint32_t rowStride, uint32_t colStride)
{
    int32_t* r = OB_PTR(int32_t, rect);
    float* p = OB_PTR(float, out);
    for (int32_t y = r[1]; y < r[3]; y++) {
        float* next = p + rowStride;
        for (int32_t x = r[0]; x <= r[2]; x++) {
            *p = 0.0f;
            p += colStride;
        }
        p = next;
    }
}
#endif

// FUNCTION: 0x007aa490
void cSC4RegionalTerrainMap::Slot17_ab3be8(uint32_t x, uint32_t z, uint32_t corners)
{
    float* c = OB_PTR(float, corners);
    c[0] = c[1] = c[2] = c[3] = mfAltitude;
}

// FUNCTION: 0x007aa520
bool cUnk00ab8cd0::Slot03_ae1d24()
{
    if (!get_init_flag()) {
        cGZWin::Slot03_ae1d24();
        mnCursorId = 0xc2a676ac;
        Slot68_adc8d8(0x10000, 0);
        Slot68_adc8d8(0x8000, 0);
    }
    return true;
}

// FUNCTION: 0x007aa570
bool cUnk00ab8cd0::Slot04_ae1d24()
{
    if (get_init_flag()) {
        if (mpOriginImage) {
            static_cast<cIGZUnknown*>(mpOriginImage)->Release();
            mpOriginImage = 0;
        }
        cGZWin::Slot04_ae1d24();
    }
    return true;
}

// FUNCTION: 0x007aa600
bool cSC4WinRegionScreen::GZOnMouseEnter(uint32_t win)
{
    int32_t x;
    int32_t y;
    OB_PTR(WinMgr_ab9260, field4)->GetCursorPos(this, &x, &y);
    GZOnMouseMove(x, y, 0);
    return true;
}

// GLOBAL: 0x00b43cb0
extern CmdServer_ab9260* gpB43cb0;

// GLOBAL: 0x00b43dd0
extern cIGZUnknown* gpB43dd0;

struct Msg_ab9260 {
    uint32_t mnId;
    int32_t mnA;
    int32_t mnB;
    uint32_t* mpData;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007aa640 score 24
bool cSC4WinRegionScreen::QueryInterface(unsigned int iid, void** ppv)
{
    if (iid == 1 || iid == 0x22ba0121) {
        *ppv = this;
    } else if (iid == 0xc6ae7085) {
        *ppv = static_cast<cUnk00a86864*>(this);
    } else {
        return false;
    }
    AddRef();
    return true;
}
#endif

// FUNCTION: 0x007aadf0
void cSC4RegionalTerrainMap::Slot28_ab3be8(uint32_t x, uint32_t z, uint32_t normal)
{
    float* n = OB_PTR(float, normal);
    n[0] = 0.0f;
    n[1] = 1.0f;
    n[2] = 0.0f;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007ab520 score 24
bool cUnk00ab8f50::Slot03_ae1d24()
{
    cIGZUnknown* r = gpB43dd0;
    cIGZUnknown* old = static_cast<cIGZUnknown*>(mpRenderer);
    if (r != old) {
        if (r) {
            r->AddRef();
        }
        mpRenderer = r;
        if (old) {
            old->Release();
        }
    }
    return cGZWin::Slot03_ae1d24();
}
#endif

// FUNCTION: 0x007ab560
bool cUnk00ab8f50::Slot04_ae1d24()
{
    cIGZUnknown* r = static_cast<cIGZUnknown*>(mpRenderer);
    if (r) {
        mpRenderer = 0;
        r->Release();
    }
    return cGZWin::Slot04_ae1d24();
}

// FUNCTION: 0x007ab590
bool cUnk00ab8f50::GZPaint()
{
    OB_PTR(DrawCtx_ab8f50, field6c)->Begin();
    static_cast<Renderer_ab8f50*>(mpRenderer)->Draw();
    OB_PTR(DrawCtx_ab8f50, field6c)->End();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007ab5e0 score 2
cUnk00ab8f50::~cUnk00ab8f50()
{
    if (mpRenderer) {
        static_cast<cIGZUnknown*>(mpRenderer)->Release();
    }
}
#endif

// FUNCTION: 0x007ab760
bool cSC4WinRegionScreen::GZOnMouseMove(uint32_t x, uint32_t z, uint32_t flags)
{
    if (!mbBlocked) {
        static_cast<cSC4WinRegionView*>(mpView)->SelectCity(x, z);
    }
    return true;
}

// FUNCTION: 0x007ab790
bool cSC4WinRegionScreen::GZOnMouseDownR(uint32_t x, uint32_t z, uint32_t flags)
{
    static_cast<cUnk00ab8cd0*>(mpScroll)->GZOnMouseDownR(x, z, flags);
    return true;
}

// FUNCTION: 0x007abb60
bool cSC4WinRegionScreen::GZOnMouseExit(uint32_t win)
{
    if (!mbBlocked) {
        static_cast<cSC4WinRegionView*>(mpView)->ClearSelection();
    }
    return true;
}

// A node of the region's search order: a position and a level.
struct Item_ab9260 {
    int32_t mnX;
    int32_t mnY;
    int32_t mnLevel;
};

// The order of the items (a functor: `this` in ecx stays unused).
struct Less_ab9260 {
    // STUB: 0x007aa5a0
    bool operator()(const Item_ab9260* a, const Item_ab9260* b) const;
};

// The same order with its body in view (the original inlines it into the sorting routines).
struct LessI_ab9260 {
    bool operator()(const Item_ab9260* a, const Item_ab9260* b) const
    {
        int32_t d = (1 << a->mnLevel) - (1 << b->mnLevel) - b->mnY + a->mnY - b->mnX + a->mnX;
        return d < 0 || (d == 0 && a->mnX < b->mnX);
    }
};

#ifdef OB_DRAFTS
// CLOSE: 0x007aa920 score 26
Item_ab9260* Fn007aa920(Item_ab9260* a, Item_ab9260* b, Item_ab9260* c)
{
    Less_ab9260 less;
    if (less(a, b)) {
        if (less(b, c)) {
            return b;
        }
        if (less(a, c)) {
            return c;
        }
        return a;
    }
    if (less(a, c)) {
        return a;
    }
    if (less(b, c)) {
        return c;
    }
    return b;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007aa9c0 score 74
void Fn007aa9c0(Item_ab9260* hole, Item_ab9260 key, LessI_ab9260 less)
{
    for (;;) {
        Item_ab9260* prev = hole - 1;
        if (!less(&key, prev)) {
            break;
        }
        *hole = *prev;
        hole = prev;
    }
    *hole = key;
}
#endif

// FUNCTION: 0x007aa5a0
uint32_t OB_STDCALL Fn007aa5a0(const int32_t* a, const int32_t* b)
{
    int32_t d = (1 << a[2]) - (1 << b[2]) - b[1] + a[1] - b[0] + a[0];
    if (d < 0 || (d == 0 && a[0] < b[0])) {
        return 1;
    }
    return 0;
}

// Clamps a fixed-point channel to 0..255.
inline uint32_t Clamp_ab9260(int32_t v)
{
    if (static_cast<uint32_t>(v) < 0x100) {
        return static_cast<uint32_t>(v);
    }
    return static_cast<uint32_t>(~(v >> 31)) & 0xff;
}

struct Blend_ab9260 {
    const uint32_t* mpA;
    uint32_t mnPad[2];
    const uint32_t* mpB;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007aabb0 score 161
void Fn007aabb0(uint32_t* dst, Blend_ab9260* src, int32_t count, const int32_t* weights)
{
    for (int32_t i = 0; i < count; i++) {
        uint32_t a = src->mpA[i];
        int32_t w0 = weights[0];
        int32_t c2 = ((a >> 16) & 0xff) * w0;
        int32_t c1 = ((a >> 8) & 0xff) * w0;
        int32_t c0 = (a & 0xff) * w0;
        int32_t c3 = (a >> 24) * w0;
        uint32_t b = src->mpB[i];
        int32_t w1 = weights[1];
        c3 += (b >> 24) * w1;
        c2 += ((b >> 16) & 0xff) * w1;
        c1 += ((b >> 8) & 0xff) * w1;
        c0 += (b & 0xff) * w1;
        uint32_t r3 = Clamp_ab9260((c3 + 0x2000) >> 14);
        uint32_t r2 = Clamp_ab9260((c2 + 0x2000) >> 14);
        uint32_t r1 = Clamp_ab9260((c1 + 0x2000) >> 14);
        uint32_t r0 = Clamp_ab9260((c0 + 0x2000) >> 14);
        *dst = (((((r3 << 8) + r2) << 8) + r1) << 8) + r0;
        dst++;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007aab10 score 19
bool Fn007aab10(uint32_t, uint32_t, cGZWin* win, uint32_t target)
{
    win->Slot68_adc8d8(0x8000, 0);
    cIGZUnknown* p;
    if (win->QueryInterface(0x8810, reinterpret_cast<void**>(&p))) {
        win->SetNotificationTarget(target);
        p->Release();
    }
    cIGZUnknown* q = 0;
    if (win->QueryInterface(0xa1336cc0, reinterpret_cast<void**>(&q))) {
        win->SetNotificationTarget(target);
    } else {
        win->EnumChildren(0x22ba0121, reinterpret_cast<void*>(&Fn007aab10), reinterpret_cast<void*>(target));
    }
    if (q) {
        q->Release();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007ab9f0 score 62
bool cSC4WinRegionScreen::DoMessage(uint32_t message)
{
    Msg_ab9260* m = OB_PTR(Msg_ab9260, message);
    switch (m->mnId) {
    case 0x8a4bac53: {
        cSC4WinRegionView* view = static_cast<cSC4WinRegionView*>(mpView);
        view->mbScrolling = 1;
        view->InvalidateSelfAndParents();
        return true;
    }
    case 0x1b: {
        int32_t sub = m->mnB;
        if (sub == 5 || sub == 6) {
            uint32_t* data = m->mpData;
            uint32_t command = 0;
            if (!static_cast<HitTest_ab9260*>(mpHitTest)->Hit(data[1], data[2], sub == 5, &command)) {
                return false;
            }
            gpB43cb0->Run(command, 0, 0);
            return true;
        }
        break;
    }
    case 0x8a4bac5b:
        static_cast<cSC4WinRegionView*>(mpView)->mbScrolling = 0;
        return true;
    case 0xaaa1cdf2: {
        int32_t dz = m->mnB;
        mfScrollX += static_cast<float>(m->mnA) * 0.00390625f;
        mfScrollZ += static_cast<float>(dz) * 0.00390625f;
        return true;
    }
    default:
        break;
    }
    return cGZWin::DoMessage(message);
}
#endif

// A 0x80-byte record copied by the original's copy routine.
struct Rec_ab9260 {
    uint8_t mData[0x80];
    // STUB: 0x007ae7b0
    void Copy(const Rec_ab9260* src);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007aeda0 score 12
Rec_ab9260* Fn007aeda0(Rec_ab9260* dst, uint32_t count, const Rec_ab9260* value)
{
    if (count > 0) {
        for (uint32_t i = count; i != 0; i--) {
            if (dst) {
                dst->Copy(value);
            }
            dst++;
        }
    }
    return dst;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007aed60 score 6
Rec_ab9260* Fn007aed60(const Rec_ab9260* first, const Rec_ab9260* last, Rec_ab9260* dst)
{
    for (; first != last; first++) {
        if (dst) {
            dst->Copy(first);
        }
        dst++;
    }
    return dst;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007ac490 score 2
void Fn007ac490(Item_ab9260* first, Item_ab9260* last, LessI_ab9260 less)
{
    for (; first != last; first++) {
        Fn007aa9c0(first, *first, less);
    }
}
#endif

// A node of a list of owned interfaces.
struct Node_ab9260 {
    Node_ab9260* mpNext;
    Node_ab9260* mpPrev;
    cIGZUnknown* mpValue;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

#ifdef OB_DRAFTS
// CLOSE: 0x007ad2c0 score 30
void OB_STDCALL Fn007ad2c0(Node_ab9260** out, Node_ab9260* first, Node_ab9260* last)
{
    while (first != last) {
        Node_ab9260* node = first;
        first = first->mpNext;
        node->mpPrev->mpNext = node->mpNext;
        node->mpNext->mpPrev = node->mpPrev;
        if (node->mpValue) {
            node->mpValue->Release();
        }
        Fn0090cf63(node);
    }
    *out = last;
}
#endif

// FUNCTION: 0x007ad3b0
bool cUnk00ab8cd0::GZOnMouseDownR(uint32_t x, uint32_t z, uint32_t flags)
{
    void* marker = GetChildWindowFromID(0x48e945b4);
    if (marker) {
        Slot16_adc8d8(OB_ADDR(marker));
    }
    Slot68_adc8d8(0x200000, 0);
    OB_PTR(WinMgr_ab9260, field4)->SetCapture(this);
    SetMouseScroll(x, z);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007aaec0 score 2
bool cUnk00ab8cd0::GZOnMouseUpR(uint32_t x, uint32_t z, uint32_t flags)
{
    void* marker = GetChildWindowFromID(0x48e945b4);
    if (marker) {
        Slot16_adc8d8(OB_ADDR(marker));
    }
    mbMouseScroll = 0;
    mfMouseX = 0.0f;
    mfMouseZ = 0.0f;
    OB_PTR(WinMgr_ab9260, field4)->ReleaseCapture(this);
    Slot68_adc8d8(0x200000, 1);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007aace0 score 36
cSC4RegionalTerrainMap::cSC4RegionalTerrainMap(int32_t x, int32_t z)
{
    mfAltitude = 270.0f;
    field10 = 0.0f;
    mnCellsX = x;
    mnCellsZ = z;
    mnVertsPerRow = x + 1;
    mfCellWidth = 64.0f;
    mbInitialized = 0;
}
#endif

// STUB: 0x009133da
void* Fn009133da_ab9260(uint32_t size);

// The 0x2c-byte message object the allocator hands out.
struct cMade_ab9260 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetValue(uint32_t value);
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    cMade_ab9260();
    static void* operator new(size_t size) { return Fn009133da_ab9260(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

#ifdef OB_DRAFTS
// CLOSE: 0x007abb00 score 9
void Fn007abb00(uint32_t value)
{
    cIGZMessageServer2* server = gpB43ccc;
    if (server) {
        cMade_ab9260* m = new cMade_ab9260;
        if (m) {
            m->AddRef();
        }
        m->SetValue(value);
        server->MessagePost(m, false);
        m->Release();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007aad60 score 26
uint32_t cSC4RegionalTerrainMap::Slot25_ab3be8(uint32_t x, uint32_t z)
{
    float fx = *reinterpret_cast<float*>(&x);
    float fz = *reinterpret_cast<float*>(&z);
    float inv = 1.0f / mfCellWidth;
    float tz = fz * inv;
    float bz = tz - 0.5f + 12582912.0f;
    int32_t lowZ = *reinterpret_cast<int32_t*>(&bz) - 0x4b400000;
    int32_t zi = lowZ + 1;
    if (tz != static_cast<float>(zi)) {
        zi = lowZ;
    }
    float tx = fx * inv;
    float bx = tx - 0.5f + 12582912.0f;
    int32_t lowX = *reinterpret_cast<int32_t*>(&bx) - 0x4b400000;
    int32_t xi = lowX + 1;
    if (tx != static_cast<float>(xi)) {
        xi = lowX;
    }
    return mnVertsPerRow * zi + xi;
}
#endif

// The render state stored in two words, packed by the original's routine.
struct PackedState_ab9260 {
    // STUB: 0x007d2b50
    void Pack(bool a, bool b, bool c, bool d, bool e, int32_t f, bool g, int32_t h, int32_t i, int32_t j, int32_t k, float l, int32_t m, int32_t n);
};

#ifdef OB_DRAFTS
// Draft of 0x007ac7d0 (score 4), the constructor of cUnk00ab8cb8, on a view until the class is written.
// The constructor of cUnk00ab8cb8 (its two render-state words at +0xc and +0x10), on a view until the class is written.
struct Ctor_ab8cb8_ab9260 {
    uint8_t unknown0[0xc];
    uint32_t mnRenderStateA;
    uint32_t mnRenderStateB;
    void Construct();
};
void Ctor_ab8cb8_ab9260::Construct()
{
    mnRenderStateA = 0;
    mnRenderStateB = 0;
    reinterpret_cast<PackedState_ab9260*>(&mnRenderStateA)->Pack(true, true, true, false, true, 0, false, 7, 0, 1, -1, -1.0f, -1, -1);
}
#endif

// STUB: 0x007ae8d0
void Fn007ae8d0(Item_ab9260* first, Item_ab9260* last, uint32_t zero, int32_t limit, LessI_ab9260 less);

// STUB: 0x007adf40
void Fn007adf40(Item_ab9260* first, Item_ab9260* last, LessI_ab9260 less);

#ifdef OB_DRAFTS
// CLOSE: 0x007aed00 score 43
void Fn007aed00(Item_ab9260* first, Item_ab9260* last, LessI_ab9260 less)
{
    if (first != last) {
        int32_t ideal = 0;
        for (int32_t n = static_cast<int32_t>(last - first); n > 1; n >>= 1) {
            ideal++;
        }
        Fn007ae8d0(first, last, 0, ideal * 2, less);
        Fn007adf40(first, last, less);
    }
}
#endif

// STUB: 0x007aaa40
void Fn007aaa40(Item_ab9260* first, int32_t hole, int32_t top, Item_ab9260 value, LessI_ab9260 less);

#ifdef OB_DRAFTS
// CLOSE: 0x007ac4d0 score 44
void Fn007ac4d0Draft_ab9260(Item_ab9260* first, int32_t hole, int32_t bottom, Item_ab9260 value, LessI_ab9260 less)
{
    int32_t top = hole;
    int32_t idx = 2 * hole + 2;
    while (idx < bottom) {
        if (less(&first[idx], &first[idx - 1])) {
            idx--;
        }
        first[hole] = first[idx];
        hole = idx;
        idx = 2 * idx + 2;
    }
    if (idx == bottom) {
        first[hole] = first[bottom - 1];
        hole = bottom - 1;
    }
    Fn007aaa40(first, hole, top, value, less);
}
#endif

// STUB: 0x007ac4d0
void Fn007ac4d0(Item_ab9260* first, int32_t hole, int32_t bottom, Item_ab9260 value, LessI_ab9260 less);

// FUNCTION: 0x007ad310
void Fn007ad310(Item_ab9260* first, Item_ab9260* last, LessI_ab9260 less)
{
    int32_t n = static_cast<int32_t>(last - first);
    if (n >= 2) {
        int32_t hole = (n - 2) / 2;
        Fn007ac4d0(first, hole, n, first[hole], less);
        while (hole != 0) {
            hole--;
            Fn007ac4d0(first, hole, n, first[hole], less);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x007ad1f0 score 118
Item_ab9260* Fn007ad1f0(Item_ab9260* first, Item_ab9260* last, Item_ab9260 pivot, LessI_ab9260 less)
{
    for (;; first++) {
        while (less(first, &pivot)) {
            first++;
        }
        do {
            last--;
        } while (less(&pivot, last));
        if (first >= last) {
            return first;
        }
        Item_ab9260 tmp = *first;
        *first = *last;
        *last = tmp;
    }
}
#endif

// A name holder: slot 5 returns the text.
struct Str_ab9260 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual const char* GetText();
};

// Slot 3 returns the name holder.
struct Names_ab9260 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual Str_ab9260* GetNames();
};

// Slot 8 returns the names object.
struct Info_ab9260 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual Names_ab9260* GetInfo();
};

// The application object (global 0xb43c94): slot 17 finishes, slot 34 gives the info, slot 38 the settings record.
struct App_ab9260 {
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
    virtual uint32_t Finish();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual Info_ab9260* GetInfo();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual uint8_t* GetSettings();
};

// GLOBAL: 0x00b43c94
extern App_ab9260* gpB43c94;

#ifdef OB_DRAFTS
// CLOSE: 0x007ac270 score 14
uint32_t Fn007ac270()
{
    App_ab9260* app = gpB43c94;
    const char* text = app->GetInfo()->GetInfo()->GetNames()->GetText();
    uint8_t* rec = app->GetSettings() + 0xebc;
    strncpy(reinterpret_cast<char*>(rec), text, 0x40);
    *reinterpret_cast<uint32_t*>(rec + 0x40) = 0x80000000;
    *reinterpret_cast<uint32_t*>(rec + 0x44) = 0x80000000;
    return app->Finish();
}
#endif

// FUNCTION: 0x007ac2d0
uint32_t cSC4WinRegionScreen::Fn007ac2d0()
{
    App_ab9260* app = gpB43c94;
    app->GetInfo()->GetInfo()->GetNames();
    uint8_t* rec = app->GetSettings() + 0xebc;
    float z = static_cast<float>(static_cast<int32_t>(GetH())) * 0.5f + mfScrollZ;
    float x = static_cast<float>(static_cast<int32_t>(GetW())) * 0.5f + mfScrollX;
    *reinterpret_cast<int32_t*>(rec + 0x40) = static_cast<int32_t>(x * 256.0f);
    *reinterpret_cast<int32_t*>(rec + 0x44) = static_cast<int32_t>(z * 256.0f);
    return app->Finish();
}

// A service held by the screen: interface slots 3 and 4 are Init and Shutdown.
struct Svc_ab9260 {
    virtual bool QueryInterface(uint32_t iid, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Init();
    virtual void Shutdown();
};

// A service the original shuts down through a direct call (not a slot).
struct SvcDirect_ab9260 {
    virtual bool QueryInterface(uint32_t iid, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

struct CamCtl_ab9260 : SvcDirect_ab9260 {
    // STUB: 0x007cb970
    void Shutdown();
};

struct Camera_ab9260 : SvcDirect_ab9260 {
    // STUB: 0x00648f00
    void Shutdown();
};

// GLOBAL: 0x00b43d1c
extern void* gpB43d1c;
// GLOBAL: 0x00b43ddc
extern void* gpB43ddc;
// GLOBAL: 0x00b43dd8
extern void* gpB43dd8;
// GLOBAL: 0x00b43cf8
extern void* gpB43cf8;

#ifdef OB_DRAFTS
// CLOSE: 0x007ac380 score 12
void cSC4WinRegionScreen::Fn007ac380()
{
    gpB43d1c = 0;
    if (mpEffects) {
        static_cast<Svc_ab9260*>(mpEffects)->Shutdown();
    }
    if (mpEffects) {
        Svc_ab9260* t = static_cast<Svc_ab9260*>(mpEffects);
        mpEffects = 0;
        t->Release();
    }
    gpB43ddc = 0;
    gpB43dd8 = 0;
    gpB43dd0 = 0;
    if (mpRenderer) {
        static_cast<Svc_ab9260*>(mpRenderer)->Shutdown();
    }
    if (mpRenderer) {
        Svc_ab9260* t = static_cast<Svc_ab9260*>(mpRenderer);
        mpRenderer = 0;
        t->Release();
    }
    if (mpCameraControl) {
        static_cast<CamCtl_ab9260*>(mpCameraControl)->Shutdown();
    }
    if (mpCameraControl) {
        CamCtl_ab9260* t = static_cast<CamCtl_ab9260*>(mpCameraControl);
        mpCameraControl = 0;
        t->Release();
    }
    if (mpCamera) {
        static_cast<Camera_ab9260*>(mpCamera)->Shutdown();
    }
    if (mpCamera) {
        Camera_ab9260* t = static_cast<Camera_ab9260*>(mpCamera);
        mpCamera = 0;
        t->Release();
    }
    gpB43cf8 = 0;
    if (mpTerrainMap) {
        static_cast<Svc_ab9260*>(mpTerrainMap)->Shutdown();
    }
    if (mpTerrainMap) {
        Svc_ab9260* t = static_cast<Svc_ab9260*>(mpTerrainMap);
        mpTerrainMap = 0;
        t->Release();
    }
    if (mpFrameService) {
        static_cast<Svc_ab9260*>(mpFrameService)->Shutdown();
    }
    if (mpFrameService) {
        Svc_ab9260* t = static_cast<Svc_ab9260*>(mpFrameService);
        mpFrameService = 0;
        t->Release();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007ac110 score 32
void cSC4WinRegionScreen::RestoreSignposts()
{
    cSC4WinRegionView* view = static_cast<cSC4WinRegionView*>(mpView);
    view->EnableTutorialArrow(true);
    if (mnSignpostMode == 0) {
        view = static_cast<cSC4WinRegionView*>(mpView);
        view->SetSignpostMode(false, true);
        view->SetSignpostType(0, 0);
        view->EnableLabels(false, true);
    } else if (mnSignpostMode == 1) {
        view = static_cast<cSC4WinRegionView*>(mpView);
        view->SetSignpostMode(true, false);
        view->SetSignpostType(0, 0);
        view->EnableLabels(true, true);
    }
    mbBlocked = 0;
    static_cast<cSC4WinRegionView*>(mpView)->ClearSelection();
}
#endif

// What the renderer's slot 8 hands out: the camera basis.
struct Basis_ab9260 {
    uint8_t mPad0[0x60];
    float mfRight[3];
    float mfUp[3];
    uint8_t mPad1[0xd8];
    float mfScale;
};

struct RenderBasis_ab9260 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual Basis_ab9260* GetBasis();
};

struct Vec3_ab9260 {
    float mfX;
    float mfY;
    float mfZ;
};

struct CamTarget_ab9260 {
    // STUB: 0x007cd810
    void SetViewTargetPosition(const Vec3_ab9260* position);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007ac1a0 score 21
void cSC4WinRegionScreen::UpdateRendererPosition()
{
    Basis_ab9260* basis = static_cast<RenderBasis_ab9260*>(mpRenderer)->GetBasis();
    float z = (static_cast<float>(static_cast<int32_t>(GetH())) * 0.5f + mfScrollZ) * basis->mfScale;
    float u0 = z * basis->mfUp[0];
    float u1 = z * basis->mfUp[1];
    float u2 = z * basis->mfUp[2];
    float x = (static_cast<float>(static_cast<int32_t>(GetW())) * 0.5f + mfScrollX) * basis->mfScale;
    Vec3_ab9260 position;
    position.mfX = x * basis->mfRight[0] - u0;
    position.mfY = x * basis->mfRight[1] - u1;
    position.mfZ = x * basis->mfRight[2] - u2;
    static_cast<CamTarget_ab9260*>(mpCameraControl)->SetViewTargetPosition(&position);
}
#endif

// The container at field 0x120, built by the original's routine.
struct List_ab9260 {
    // STUB: 0x0088fedf
    void Construct(uint32_t size);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007aae10 score 4
cUnk00ab8cd0::cUnk00ab8cd0()
{
    mnZeroDC = 0;
    mnZeroE0 = 0;
    mnZeroE4 = 0;
    mnZeroE8 = 0;
    mnZeroEC = 0;
    mnZeroF0 = 0;
    mfMouseX = 0;
    mfMouseZ = 0;
    mnZeroFC = 0;
    mnZero100 = 0;
    mfLimit = 300.0f;
    mbFlag108 = 0;
    mbMouseScroll = 0;
    mpOriginImage = 0;
    mnCount110 = 10;
    mnCount114 = 32;
    mfSpeed = 5.0f;
    mfAccel = 3.0f;
    reinterpret_cast<List_ab9260*>(mUnk120)->Construct(4);
}
#endif

// A pixel buffer: lock (6), unlock (7), rectangle (12), get pixel (21), set pixel (22).
struct Buf_ab9260 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual bool Lock(uint32_t flags);
    virtual void Unlock(uint32_t flags);
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual const int32_t* GetRect();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual uint32_t GetPixel(int32_t x, int32_t y);
    virtual void SetPixel(int32_t x, int32_t y, uint32_t value);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007abcd0 score 133
void Fn007abcd0(Buf_ab9260* dst, Buf_ab9260* src)
{
    if (!dst->Lock(0x8080)) {
        return;
    }
    if (src->Lock(0x800)) {
        const int32_t* ra = src->GetRect();
        const int32_t* rb = src->GetRect();
        int32_t w1 = ra[2] - ra[0];
        int32_t w2 = rb[2] - rb[0];
        int32_t w = w1 < w2 ? w1 : w2;
        int32_t h1 = ra[3] - ra[1];
        int32_t h2 = rb[3] - rb[1];
        int32_t h = h1 < h2 ? h1 : h2;
        for (int32_t y = 0; y < h; y++) {
            for (int32_t x = 0; x < w; x++) {
                uint32_t rgb = dst->GetPixel(x, y) & 0xffffff;
                uint32_t alpha = src->GetPixel(x, y);
                dst->SetPixel(x, y, rgb + (alpha << 24));
            }
        }
        src->Unlock(0x800);
    }
    dst->Unlock(0x8080);
}
#endif

// Assigns an interface pointer slot from another, with the counts kept.
inline void AssignRef_ab9260(cIGZUnknown** dst, cIGZUnknown** src)
{
    if (src != dst) {
        cIGZUnknown* p = *src;
        cIGZUnknown* old = *dst;
        if (p != old) {
            if (p) {
                p->AddRef();
            }
            *dst = p;
            if (old) {
                old->Release();
            }
        }
    }
}

// The record of one city view, as far as the screen touches it.
struct CityRec_ab9260 {
    uint8_t mPad[0x18];
    uint8_t mnIndex;
    uint8_t mPad1[3];
    cIGZUnknown* mpImageA;
    cIGZUnknown* mpImageB;
    cIGZUnknown* mpImageC;
    cIGZUnknown* mpImageD;
};

// The region options object seen through slot 18 (the image set to use).
struct Mode_ab9260 {
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
    virtual int32_t GetMode();
};

struct ModeInfo_ab9260 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual Mode_ab9260* GetOptions();
};

#ifdef OB_DRAFTS
// CLOSE: 0x007abb80 score 139
void cSC4WinRegionScreen::Fn007abb80(void* record)
{
    uint8_t* self = reinterpret_cast<uint8_t*>(this);
    CityRec_ab9260* r = static_cast<CityRec_ab9260*>(record);
    int32_t mode = reinterpret_cast<ModeInfo_ab9260*>(gpB43c94->GetInfo())->GetOptions()->GetMode();
    uint32_t base = (mode == 1) ? 0x13c : 0x124;
    AssignRef_ab9260(&r->mpImageA, reinterpret_cast<cIGZUnknown**>(self + base + r->mnIndex * 8));
    AssignRef_ab9260(&r->mpImageB, reinterpret_cast<cIGZUnknown**>(self + base + 4 + r->mnIndex * 8));
    if (r->mpImageC) {
        cIGZUnknown* c = r->mpImageC;
        r->mpImageC = 0;
        c->Release();
    }
    if (r->mpImageD) {
        cIGZUnknown* d = r->mpImageD;
        r->mpImageD = 0;
        d->Release();
    }
}
#endif

// A window through the slots this screen uses: 8 (child lookup by id), 30 (move), 37 (typed child), 68 (flag), 69 (show), 70 (hide), 71 (visible).
struct WinView_ab9260 {
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
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void MoveRelativeTo(void* win, uint32_t how);
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual void Pad55();
    virtual void Pad56();
    virtual void Pad57();
    virtual void Pad58();
    virtual void Pad59();
    virtual void Pad60();
    virtual void Pad61();
    virtual void Pad62();
    virtual void Pad63();
    virtual void Pad64();
    virtual void Pad65();
    virtual void Pad66();
    virtual void Pad67();
    virtual void SetFlag(uint32_t flag, bool on);
    virtual void Show();
    virtual void Hide();
    virtual bool IsVisible();
};

// The ids of the three tab windows.
// GLOBAL: 0x00ab91ac
extern const uint32_t kTabIds_ab9260[3];

// The check box interface (iid 0x8810), slot 9.
struct CheckBox_ab9260 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void SetChecked(bool on);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007abdf0 score 97
void cSC4WinRegionScreen::Fn007abdf0(int32_t selected)
{
    void* ctrl = GetChildWindowFromID(0x9ebe9ee);
    uint32_t* tabs = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) + 0xec);
    uint32_t* panels = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) + 0xf8);
    int32_t sel = selected;
    if (sel >= 0 && tabs[sel] && OB_PTR(WinView_ab9260, tabs[sel])->IsVisible()) {
        if (tabs[sel]) {
            OB_PTR(WinView_ab9260, tabs[sel])->Hide();
        }
        if (panels[sel]) {
            OB_PTR(WinView_ab9260, panels[sel])->Hide();
        }
    } else {
        for (int32_t i = 0; i < 3; i++) {
            if (tabs[i]) {
                OB_PTR(WinView_ab9260, tabs[i])->SetFlag(1, i == sel);
            }
            if (panels[i]) {
                if (i == sel) {
                    OB_PTR(WinView_ab9260, panels[i])->MoveRelativeTo(ctrl, 1);
                    OB_PTR(WinView_ab9260, panels[i])->Show();
                } else {
                    OB_PTR(WinView_ab9260, panels[i])->Hide();
                }
            }
        }
    }
    for (uint32_t i = 0; i < 3; i++) {
        cIGZUnknown* p = 0;
        if (GetChildAsRecursive(kTabIds_ab9260[i], 0x8810, OB_ADDR(&p))) {
            reinterpret_cast<CheckBox_ab9260*>(p)->SetChecked(i == static_cast<uint32_t>(sel));
            if (p) {
                p->Release();
            }
        }
    }
}
#endif

// A message object: QueryInterface (0), type (4), first datum (10), second datum (15).
struct Msg2_ab9260 {
    virtual bool QueryInterface(uint32_t iid, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad03();
    virtual uint32_t GetType();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void* GetFirst();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void* GetSecond();
};

// The camera control's own shutdown of its last frame (a direct call).
struct CamCtl2_ab9260 {
    // STUB: 0x007cc5b0
    void Fn007cc5b0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x007b0af0 score 56
bool cSC4WinRegionScreen::Slot03_aaaa9c(void* message)
{
    Msg2_ab9260* m = static_cast<Msg2_ab9260*>(message);
    uint32_t id = m->GetType();
    cIGZUnknown* p = 0;
    if (m->QueryInterface(0x4b99446a, reinterpret_cast<void**>(&p))) {
        void* first = m->GetFirst();
        void* second = m->GetSecond();
        ProcessCommand(id, first, second);
    } else if (id == 0x231bbf91) {
        uint8_t* settings = gpB43c94->GetSettings();
        if (mpWinE4) {
            static_cast<WinView_ab9260*>(mpWinE4)->SetFlag(1, settings[0xf11] != 0);
        }
    } else if (id == 0x2b96b3ea) {
        static_cast<CamCtl2_ab9260*>(mpCameraControl)->Fn007cc5b0();
        static_cast<WinView_ab9260*>(mpWinE8)->SetFlag(1, true);
    }
    if (p) {
        p->Release();
    }
    return true;
}
#endif

// A 0x80-byte record's destructor and the copy-down routine of the original's vector.
struct Rec2_ab9260 {
    uint8_t mData[0x80];
    // STUB: 0x007ada00
    void Destroy();
};

// STUB: 0x007ae9b0
Rec2_ab9260* Fn007ae9b0(Rec2_ab9260* first, Rec2_ab9260* last, Rec2_ab9260* dest, uint8_t* flag, uint32_t zero);

struct RecVec_ab9260 {
    Rec2_ab9260* mpBegin;
    Rec2_ab9260* mpEnd;
    Rec2_ab9260* mpCap;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007b0bb0 score 33
Rec2_ab9260* OB_FASTCALL_AB9260 Fn007b0bb0(RecVec_ab9260* self, void* unused, Rec2_ab9260* first, Rec2_ab9260* last)
{
    uint8_t tmp;
    Rec2_ab9260* newEnd = Fn007ae9b0(last, self->mpEnd, first, &tmp, 0);
    for (Rec2_ab9260* p = newEnd; p != self->mpEnd; p++) {
        p->Destroy();
    }
    self->mpEnd = newEnd;
    return first;
}
#endif

// The double-click timer inside the screen (field 0x1d0).
struct Timer_ab9260 {
    // STUB: 0x00890198
    uint32_t GetElapsedTime() const;
    // STUB: 0x0089058f
    void Restart();
};

// The window-class manager singleton: slot 40 is the double-click time.
struct Wcm_ab9260 {
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
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual uint32_t GetDoubleClickTime();
};

// STUB: 0x00913c72
Wcm_ab9260* Fn00913c72();

// The sound server (global 0xb43cb8): slot 11 plays a sound.
struct Sound_ab9260 {
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
    virtual void Play(uint32_t a, uint32_t id, uint32_t b, uint32_t c, uint32_t d);
};

// GLOBAL: 0x00b43cb8
extern Sound_ab9260* gpB43cb8;

// A city reference object: slot 43 tells whether the place is occupied.
struct City_ab9260 {
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
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual bool IsOccupied();
};

struct CityRef_ab9260 {
    City_ab9260* mpCity;
};

// The region object: slot 11 finds the city at a position.
struct Region_ab9260 {
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
    virtual CityRef_ab9260* FindCity(uint32_t x, uint32_t z);
};

struct CityPlace_ab9260 {
    uint8_t mPad[8];
    uint32_t mnX;
    uint32_t mnZ;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007acad0 score 118
bool cSC4WinRegionScreen::GZOnMouseDownL(uint32_t x, uint32_t z, uint32_t flags)
{
    cSC4WinRegionView* view = static_cast<cSC4WinRegionView*>(mpView);
    if (mbBlocked) {
        CityPlace_ab9260* hit = static_cast<CityPlace_ab9260*>(view->GetCityAtPoint(x, z));
        if (hit && hit == view->GetSelectedCity()) {
            Wcm_ab9260* wcm = Fn00913c72();
            uint32_t elapsed = reinterpret_cast<Timer_ab9260*>(mDoubleClickTimer)->GetElapsedTime();
            if (elapsed < wcm->GetDoubleClickTime()) {
                GZOnCommand(0x287259f6, 0x4a560000);
                return true;
            }
        }
        view->SelectCity(x, z);
        if (!view->GetSelectedCity()) {
            RestoreSignposts();
            return true;
        }
    }
    CityPlace_ab9260* city = static_cast<CityPlace_ab9260*>(view->GetSelectedCity());
    if (!city) {
        return true;
    }
    if (gpB43cb8) {
        gpB43cb8->Play(1, 0x2a5c322b, 0, 0, 0);
    }
    Region_ab9260* region = reinterpret_cast<Region_ab9260*>(gpB43c94->GetInfo()->GetInfo());
    Fn007abdf0(-1);
    view->EnableTutorialArrow(true);
    view->SetSignpostMode(false, true);
    view->EnableLabels(mnSignpostMode == 1, false);
    CityRef_ab9260* ref = region->FindCity(city->mnX, city->mnZ);
    if (ref && ref->mpCity && ref->mpCity->IsOccupied()) {
        view->SetSignpostType(0xca539340, 0xa551c50);
    } else {
        view->SetSignpostType(0xa8cd184, 0xa551c50);
    }
    mbBlocked = 1;
    reinterpret_cast<Timer_ab9260*>(mDoubleClickTimer)->Restart();
    int32_t rect[4];
    view->GetPlayfieldRect(city, rect);
    return true;
}
#endif
