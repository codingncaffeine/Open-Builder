#include "classes/cUnk00ab3b00.h"
#include <algorithm>
#include <new>
#include "game/Globals.h"
#include "gzcom/cRZString.h"

// The grid object the class keeps at +0x14 (the global at 0x00b43cf4 hands it out): only what is used here is named.
struct Grid_ab3b00 {
    virtual void Pad00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual int32_t Cell09(uint32_t a, uint32_t b);
    virtual void Coords10(int32_t cell, int32_t* x, int32_t* y);
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
    virtual float Fn29();
    uint8_t mPad04[0x34];
    int32_t mnWidth;       // 0x38
    int32_t mnHeight;      // 0x3c
    uint8_t mField40[0x1c];
    int32_t mnCount5c;     // 0x5c
    uint8_t mPad60[0xc];
    float* mpDelta;        // 0x6c
    uint8_t mPad70[0xc];
    float mfLimit;         // 0x7c
    uint8_t mPad80[4];
    int32_t mnStep[8];     // 0x84
    // STUB: 0x00741710
    uint8_t Fn00741710(int32_t x, int32_t y);
};

// A service with a register (slot 5) and an unregister (slot 6) call for an object under an id.
struct Svc_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05(void* object, uint32_t id);
    virtual void Fn06(void* object, uint32_t id);
};

struct Obj50_ab3b00 {
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
    virtual void Fn20(void* object);
};

struct With4c_ab3b00 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Fn03();
    virtual void Fn04();
    virtual void Pad05();
    virtual void Fn06(uint32_t id);
    virtual void Pad07();
    virtual void Pad08();
    virtual void Fn09(uint32_t flag);
};

// STUB: 0x00602600
Svc_ab3b00* Fn00602600();

// The world object at 0x00b43cec: only the slots used here.
struct World_ab3b00 {
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
    virtual bool Fn22();
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
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual Obj50_ab3b00* Fn50();
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
    virtual void Pad68();
    virtual void Pad69();
    virtual void Pad70();
    virtual void Pad71();
    virtual void Pad72();
    virtual void Pad73();
    virtual void Pad74();
    virtual void Pad75();
    virtual void Pad76();
    virtual void Pad77();
    virtual void Pad78();
    virtual void Pad79();
    virtual void Pad80();
    virtual void Pad81();
    virtual void Pad82();
    virtual void Pad83();
    virtual void Pad84();
    virtual void Pad85();
    virtual void Pad86();
    virtual void Pad87();
    virtual void Pad88();
    virtual void Pad89();
    virtual void Pad90();
    virtual void Pad91();
    virtual void Pad92();
    virtual int32_t Fn93();
    virtual int32_t Fn94();
    virtual void Fn95(uint32_t a, uint32_t b, uint32_t* x, uint32_t* y);
    virtual void Pad96();
    virtual void Fn97(uint32_t a, uint32_t b, uint32_t* x, uint32_t* y);
    virtual void Pad98();
    virtual bool Fn99(uint32_t a, uint32_t b);
};
// GLOBAL: 0x00b43cec
extern World_ab3b00* gpB43cec;

static inline Grid_ab3b00* GridOf_ab3b00(cUnk00ab3b00* p)
{
    return static_cast<Grid_ab3b00*>(p->mpGrid);
}

// FUNCTION: 0x004f7ba0
unsigned int cUnk00ab3b00::AddRef()
{
    return ++mnRefCount;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0073cd50 score 17 (the original is a three-way switch compiled as cmp max/ja/je/dec/je/sub; every spelling tried gives an ascending compare chain)
bool cUnk00ab3b00::QueryInterface(unsigned int iid, void** ppv)
{
    if (iid == 0xab8da759 || iid == 1) {
        *ppv = static_cast<cUnk00ab3b00_0*>(this);
        AddRef();
        return true;
    }
    if (iid == 0x452294aa) {
        *ppv = static_cast<cUnk00aaaa9c*>(this);
        AddRef();
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x0073cdb0
uint32_t cUnk00ab3b00::Slot13_ab3b00(uint32_t a, uint32_t b)
{
    if (Slot06_ab3b00(a, b) > 5.0f) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x0073cec0
unsigned int cUnk00ab3b00::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04_ab3b00();
    delete this;
    return 0;
}

// FUNCTION: 0x0073d200
float cUnk00ab3b00::Slot05_ab3b00(uint32_t a)
{
    return mpEntries[a * 9];
}

// FUNCTION: 0x0073d210
float cUnk00ab3b00::Slot06_ab3b00(uint32_t a, uint32_t b)
{
    Grid_ab3b00* g = GridOf_ab3b00(this);
    int32_t cell = g->Cell09(a, b);
    float m = mpEntries[cell * 9];
    ++cell;
    float t = mpEntries[cell * 9];
    if (t < m) {
        m = t;
    }
    cell += GridOf_ab3b00(this)->mnWidth;
    t = mpEntries[cell * 9];
    if (t < m) {
        m = t;
    }
    t = mpEntries[(cell - 1) * 9];
    if (t < m) {
        m = t;
    }
    return std::max(0.0f, m);
}

// FUNCTION: 0x0073d7c0
void* cUnk00ab3b00::Slot11_ab3b00(uint32_t a, uint32_t b)
{
    int32_t cell = GridOf_ab3b00(this)->Cell09(a, b);
    return mpEntries + cell * 9 + 4;
}

// FUNCTION: 0x0073d7f0
uint32_t cUnk00ab3b00::Slot12_ab3b00(uint32_t a, uint32_t b)
{
    int32_t cell = GridOf_ab3b00(this)->Cell09(a, b);
    float v = mpEntries[cell * 9];
    if (v <= 0.0f) {
        return 0;
    }
    Grid_ab3b00* g = GridOf_ab3b00(this);
    if (v + g->mpDelta[cell * 9] <= g->mfLimit) {
        return 3;
    }
    return 2;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0073cef0 score 18 (the original keeps one output in a fresh stack slot and the other in the dead first argument slot; here both reuse dead argument slots)
void cUnk00ab3b00::Slot07_ab3b00(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t y;
    uint32_t x;
    gpB43cec->Fn95(a, c, &x, &y);
    Slot08_ab3b00(x, y, d, e);
}
#endif

// The streams the two Slot..._a80784 methods read or write.
struct Res_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void* Fn03();
};

struct Q_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
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
    virtual Res_ab3b00* Fn25();
};

struct OutStream_ab3b00 {
    virtual bool QueryInterface(uint32_t iid, Q_ab3b00** out);
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Wr07(uint32_t value);
};

struct InStream_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Rd07(uint16_t* value);
};

// STUB: 0x005d99a0
void Fn005d99a0(void* stream, void* object);

// STUB: 0x005d9730
void Fn005d9730(void* stream, uint32_t id, void** field, uint32_t flag);

// STUB: 0x0045ba70
uint32_t Fn0045ba70(void* stream);

// FUNCTION: 0x0073dd40
bool cUnk00ab3b00::Slot03_a80784(void* pv)
{
    OutStream_ab3b00* p = static_cast<OutStream_ab3b00*>(pv);
    p->Wr07(1);
    Fn005d99a0(p, mpGrid ? static_cast<char*>(mpGrid) + 8 : 0);
    Q_ab3b00* q = 0;
    p->QueryInterface(0x6999a8fb, &q);
    Q_ab3b00* t = q;
    Res_ab3b00* r = 0;
    if (t) {
        t->Release();
        r = t->Fn25();
    }
    return Fn0073d090(r ? r->Fn03() : 0);
}

// FUNCTION: 0x00740490
bool cUnk00ab3b00::Slot04_a80784(void* pv)
{
    InStream_ab3b00* p = static_cast<InStream_ab3b00*>(pv);
    uint16_t v;
    p->Rd07(&v);
    if (v > 1) {
        return false;
    }
    Fn005d9730(p, 0xc70bd37e, &mpGrid, 0);
    return Fn00740060(Fn0045ba70(p));
}

// FUNCTION: 0x0073d4f0
float cUnk00ab3b00::Slot10_ab3b00(uint32_t a, uint32_t b)
{
    int32_t cell = GridOf_ab3b00(this)->Cell09(a, b);
    float limit = GridOf_ab3b00(this)->mfLimit;
    float h = mpEntries[cell * 9];
    float s = h + GridOf_ab3b00(this)->mpDelta[cell * 9];
    if (h > 0.0f && limit < s) {
        limit = s;
    }
    int32_t y;
    int32_t x;
    GridOf_ab3b00(this)->Coords10(cell, &x, &y);
    uint8_t flags = GridOf_ab3b00(this)->Fn00741710(x, y);
    if (flags & 1) {
        int32_t n = GridOf_ab3b00(this)->mnStep[0] + cell;
        h = mpEntries[n * 9];
        s = h + GridOf_ab3b00(this)->mpDelta[n * 9];
        if (h > 0.0f && limit < s) {
            limit = s;
        }
    }
    if (flags & 2) {
        int32_t n = GridOf_ab3b00(this)->mnStep[1] + cell;
        h = mpEntries[n * 9];
        s = h + GridOf_ab3b00(this)->mpDelta[n * 9];
        if (h > 0.0f && limit < s) {
            limit = s;
        }
    }
    if (flags & 4) {
        int32_t n = GridOf_ab3b00(this)->mnStep[2] + cell;
        h = mpEntries[n * 9];
        s = h + GridOf_ab3b00(this)->mpDelta[n * 9];
        if (h > 0.0f && limit < s) {
            limit = s;
        }
    }
    if (flags & 8) {
        int32_t n = GridOf_ab3b00(this)->mnStep[3] + cell;
        h = mpEntries[n * 9];
        s = h + GridOf_ab3b00(this)->mpDelta[n * 9];
        if (h > 0.0f && limit < s) {
            limit = s;
        }
    }
    if (flags & 0x10) {
        int32_t n = GridOf_ab3b00(this)->mnStep[4] + cell;
        h = mpEntries[n * 9];
        s = h + GridOf_ab3b00(this)->mpDelta[n * 9];
        if (h > 0.0f && limit < s) {
            limit = s;
        }
    }
    if (flags & 0x20) {
        int32_t n = GridOf_ab3b00(this)->mnStep[5] + cell;
        h = mpEntries[n * 9];
        s = h + GridOf_ab3b00(this)->mpDelta[n * 9];
        if (h > 0.0f && limit < s) {
            limit = s;
        }
    }
    if (flags & 0x40) {
        int32_t n = GridOf_ab3b00(this)->mnStep[6] + cell;
        h = mpEntries[n * 9];
        s = h + GridOf_ab3b00(this)->mpDelta[n * 9];
        if (h > 0.0f && limit < s) {
            limit = s;
        }
    }
    if (flags & 0x80) {
        int32_t n = GridOf_ab3b00(this)->mnStep[7] + cell;
        h = mpEntries[n * 9];
        s = h + GridOf_ab3b00(this)->mpDelta[n * 9];
        if (h > 0.0f && limit < s) {
            limit = s;
        }
    }
    return limit;
}

// An empty allocator the vector helper takes by address.
struct Alloc_ab3b00 {
};

// A part the object owns at +0x3c: the sub-object at +0x10 is destroyed by the original's out-of-line routine.
struct Part_ab3b00 {
    virtual ~Part_ab3b00()
    {
        Tail();
    }
    // STUB: 0x00441a60
    void Tail();
};

struct Item_ab3b00 {
    uint8_t mPad00[0x10];
    Part_ab3b00 mSub;
    uint8_t mPad14[0x10];
};

// STUB: 0x0073d010
float* Fn0073d010(float* a, float* b, float* c, Alloc_ab3b00* alloc, uint32_t d);

#ifdef OB_DRAFTS
// CLOSE: 0x0073e990 score 9 (store of the new end pointer comes after the grid load here, before it in the original; the not-ready path has its own epilogue there)
bool cUnk00ab3b00::Slot04_ab3b00()
{
    if (mbReady) {
        mbReady = 0;
        Svc_ab3b00* svc = Fn00602600();
        if (svc) {
            svc->Fn06(static_cast<cUnk00aaaa9c*>(this), 0xc0);
        }
        Obj50_ab3b00* w = gpB43cec->Fn50();
        if (w) {
            w->Fn20(static_cast<cUnk00aaaa9c*>(this));
        }
        cB43ccc* reg = gpB43ccc;
        if (reg) {
            cUnk00aaaa9c* sub = static_cast<cUnk00aaaa9c*>(this);
            reg->Fn06(sub, 0x26d31ec1);
            reg->Fn06(sub, 0x26d31ec4);
            reg->Fn06(sub, 0x26d31ec5);
            reg->Fn06(sub, 0x89d3e9f3);
            reg->Fn06(sub, 0x99ef1142);
            reg->Fn06(sub, 0x99ef1143);
        }
        Alloc_ab3b00 alloc;
        float* first = mpEntries;
        float* last = mpEntriesEnd;
        mpEntriesEnd = Fn0073d010(last, last, first, &alloc, 0);
        Grid_ab3b00* grid = GridOf_ab3b00(this);
        if (grid) {
            mpGrid = 0;
            grid->Release();
        }
        if (mpObj4c) {
            static_cast<With4c_ab3b00*>(mpObj4c)->Fn04();
            static_cast<With4c_ab3b00*>(mpObj4c)->Release();
            mpObj4c = 0;
        }
        Item_ab3b00* item = static_cast<Item_ab3b00*>(mpItem);
        if (item) {
            delete item;
            mpItem = 0;
        }
        return true;
    }
    return true;
}
#endif

// The vector of entries at +0x18.
struct EntryVec_ab3b00 {
    float* mpBegin;
    float* mpEnd;
    float* mpCap;
    // STUB: 0x0073fe20
    void Resize(uint32_t count);
};

struct Vec40_ab3b00 {
    float* mpBegin;
    float* mpEnd;
    float* mpCap;
    // STUB: 0x00464130
    void Fill(uint32_t count, const float& value);
};

struct Rect_ab3b00 {
    Rect_ab3b00(int32_t l, int32_t t, int32_t r, int32_t b)
        : mnLeft(l), mnTop(t), mnRight(r), mnBottom(b)
    {
    }
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
};

struct Region_ab3b00 {
    uint8_t mData[0x24];
    // STUB: 0x00442640
    Region_ab3b00(const Rect_ab3b00& rect, uint32_t flag);
};

struct Surface_ab3b00 {
    uint8_t mData[0x44];
    // STUB: 0x0045f9b0
    Surface_ab3b00(uint32_t id);
};

struct Names_ab3b00 {
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
    virtual void Fn19(void* owner, uint32_t kind, cRZString* name, uint32_t flag);
};
// GLOBAL: 0x00b43d5c
extern Names_ab3b00* gpB43d5c;

// GLOBAL: 0x00b43cf4
extern Grid_ab3b00* gpB43cf4;

#ifdef OB_DRAFTS
// CLOSE: 0x0073fe70 score 36 (register choice for the grid pointers and the order of the rectangle stores)
bool cUnk00ab3b00::Slot03_ab3b00()
{
    if (!mbReady) {
        Grid_ab3b00* old = GridOf_ab3b00(this);
        Grid_ab3b00* g = gpB43cf4;
        if (g != old) {
            if (g) {
                g->AddRef();
            }
            mpGrid = g;
            if (old) {
                old->Release();
            }
        }
        if (!mpGrid) {
            return false;
        }
        uint32_t count = GridOf_ab3b00(this)->mnCount5c;
        reinterpret_cast<EntryVec_ab3b00*>(&mpEntries)->Resize(count);
        reinterpret_cast<Vec40_ab3b00*>(mVec40)->Fill(count, 0.0f);
        if (!mpItem) {
            int32_t bottom = GridOf_ab3b00(this)->mnHeight - 1;
            int32_t right = GridOf_ab3b00(this)->mnWidth - 1;
            mpItem = new Region_ab3b00(Rect_ab3b00(0, 0, right, bottom), 0);
        }
        mbFlag34 = 0;
        mnCount38 = 0;
        if (!mpObj4c) {
            mpObj4c = new Surface_ab3b00(0x49b9e600);
            static_cast<With4c_ab3b00*>(mpObj4c)->AddRef();
            static_cast<With4c_ab3b00*>(mpObj4c)->Fn03();
            static_cast<With4c_ab3b00*>(mpObj4c)->Fn09(1);
            static_cast<With4c_ab3b00*>(mpObj4c)->Fn06(0x4be3618b);
        }
        Svc_ab3b00* reg = reinterpret_cast<Svc_ab3b00*>(gpB43ccc);
        if (reg) {
            cUnk00aaaa9c* sub = static_cast<cUnk00aaaa9c*>(this);
            reg->Fn05(sub, 0x26d31ec1);
            reg->Fn05(sub, 0x26d31ec4);
            reg->Fn05(sub, 0x26d31ec5);
            reg->Fn05(sub, 0x89d3e9f3);
            reg->Fn05(sub, 0x99ef1142);
            reg->Fn05(sub, 0x99ef1143);
        }
        Names_ab3b00* names = gpB43d5c;
        if (names) {
            cRZString name("cSTESurfaceWater");
            names->Fn19(static_cast<cUnk00aaaa9c*>(this), 4, &name, 2);
        }
        Svc_ab3b00* svc = Fn00602600();
        if (svc) {
            svc->Fn05(static_cast<cUnk00aaaa9c*>(this), 0xc0);
        }
        Fn0073d180(GridOf_ab3b00(this)->mField40);
        gpB43cec->Fn22();
        mbReady = 1;
    }
    return true;
}
#endif

// The cell objects and the lookups the event handler uses.
struct Tile_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual bool Fn08(uint32_t flags);
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
    virtual bool Fn19();
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
    virtual bool Fn67(float* out);
};

struct Names2_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual Tile_ab3b00* Fn08(int32_t x, int32_t y, uint32_t kind, uint32_t flag);
};
// GLOBAL: 0x00b43d54
extern Names2_ab3b00* gpB43d54;

struct Pos_ab3b00 {
    uint32_t mnX;
    float mfY;
    uint32_t mnZ;
};

struct Locator_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn08(Pos_ab3b00* pos);
};

struct Target_ab3b00 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual bool Fn08(uint32_t flags);
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
    virtual uint8_t Fn40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual Locator_ab3b00* Fn48();
};

struct Spot_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn08(int32_t* x, int32_t* y);
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual bool Fn13();
};

struct Source_ab3b00 {
    virtual bool QueryInterface(uint32_t iid, void** out);
};

struct Message_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual uint32_t Fn04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual uint32_t Fn09();
    virtual Source_ab3b00* Fn10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual uint32_t Fn19();
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
    virtual Source_ab3b00* Fn32();
};

// A counted pointer to a Spot, the way the original wraps its interface pointers.
struct SpotRef_ab3b00 {
    Spot_ab3b00* mp;
    SpotRef_ab3b00() : mp(0) {}
    ~SpotRef_ab3b00()
    {
        if (mp) {
            mp->Release();
        }
    }
    // STUB: 0x004f20a0
    void** Addr();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00740160 score 180 (the original saves ebx/ebp only inside the cases that need them; here they are saved in the prologue)
bool cUnk00ab3b00::Slot03_aaaa9c(void* pv)
{
    Message_ab3b00* msg = static_cast<Message_ab3b00*>(pv);
    switch (msg->Fn04()) {
    case 0x86ad10ee:
        if (mbFlag34) {
            Fn0073fdd0();
            return true;
        }
        break;
    case 0x26d31ec1:
        if (!gpB43cec->Fn22()) {
            break;
        }
    case 0x26d31ec4:
        Fn0073d850();
        Fn0073eaf0();
        return true;
    case 0x66956814:
        if (mbFlag50) {
            Fn0073eaf0();
            mbFlag50 = 0;
            return true;
        }
        break;
    case 0x89d3e9f3: {
        Target_ab3b00* tmp = 0;
        msg->Fn32()->QueryInterface(0xa821ef94, reinterpret_cast<void**>(&tmp));
        Target_ab3b00* t = tmp;
        if (t) {
            t->AddRef();
        }
        if (tmp) {
            tmp->Release();
        }
        bool flag = msg->Fn09() != 0;
        if (t) {
            if (flag && t->Fn08(0x40000)) {
                Names2_ab3b00* names = gpB43d54;
                if (!names) {
                    t->Release();
                    return true;
                }
                Pos_ab3b00 pos;
                t->Fn48()->Fn08(&pos);
                int32_t cx;
                int32_t cy;
                gpB43cec->Fn95(pos.mnX, pos.mnZ, reinterpret_cast<uint32_t*>(&cx), reinterpret_cast<uint32_t*>(&cy));
                bool found = false;
                uint8_t mask = t->Fn40();
                int32_t dx[4] = {-1, 0, 1, 0};
                int32_t dy[4] = {0, -1, 0, 1};
                for (int32_t i = 0; i < 4; i++) {
                    if (mask & (1 << i)) {
                        int32_t x = dx[i] + cx;
                        int32_t y = dy[i] + cy;
                        if (x >= 0 && y >= 0 && x < gpB43cec->Fn93() - 1 && y < gpB43cec->Fn94() - 1) {
                            Tile_ab3b00* tile = names->Fn08(x, y, 0x1f4f, 1);
                            if (tile && tile->Fn08(0x40000) && !tile->Fn19()) {
                                found = true;
                            }
                        }
                    }
                }
                if (!found) {
                    Fn0073eaf0();
                }
            }
            t->Release();
        }
        break;
    }
    case 0x99ef1142:
    case 0x99ef1143:
        if (msg->Fn19() == 0x2890d4de) {
            SpotRef_ab3b00 spot;
            if (msg->Fn10()->QueryInterface(0xa8c86142, spot.Addr()) && !spot.mp->Fn13()) {
                int32_t x;
                int32_t y;
                spot.mp->Fn08(&x, &y);
                if (Slot06_ab3b00(x, y) > 0.0f) {
                    mbFlag50 = 1;
                }
            }
        }
        break;
    }
    return true;
}
#endif

// Who owns a spot, by position.
struct Owners_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual uint32_t Fn05(Pos_ab3b00* pos);
};
// GLOBAL: 0x00b43d08
extern Owners_ab3b00* gpB43d08;

struct Cell_ab3b00 {
    int32_t mnX;
    int32_t mnY;
};

struct Node_ab3b00;

// The list head the finder fills, destroyed by the original's out-of-line routine.
struct Found_ab3b00 {
    Node_ab3b00* mpHead;
    // STUB: 0x00413fe0
    void Destroy();
};

struct Finder_ab3b00 {
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
    virtual bool Fn41(Found_ab3b00* found, Cell_ab3b00* from, Cell_ab3b00* to, uint32_t kind, int32_t flags);
};
// GLOBAL: 0x00b43d0c
extern Finder_ab3b00* gpB43d0c;

struct Member_ab3b00 {
    virtual bool QueryInterface(uint32_t iid, void** out);
    virtual void AddRef();
    virtual void Release();
};

struct Node_ab3b00 {
    Node_ab3b00* mpNext;
    Node_ab3b00* mpPrev;
    Member_ab3b00* mpValue;
};

struct Pool_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual Node_ab3b00* Alloc(uint32_t size);
};
// GLOBAL: 0x00b207e4
extern Pool_ab3b00* gpB207e4;

struct PoolRef_ab3b00 {
    Pool_ab3b00* mp;
    // STUB: 0x00411870
    void Drop();
};

struct Provider_ab3b00 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05(uint32_t a, uint32_t b, PoolRef_ab3b00* out);
};

// STUB: 0x008793ec
Provider_ab3b00* Fn008793ec();

struct Bounds_ab3b00 {
    uint8_t mPad00[0x10];
    int32_t mnMinX;
    int32_t mnMinY;
    int32_t mnMaxX;
    int32_t mnMaxY;
    uint8_t mbFlag;
    uint8_t mPad21[0xb];
    uint32_t mnState;
    Bounds_ab3b00()
        : mnMinX(static_cast<int32_t>(0x80000000)), mnMinY(static_cast<int32_t>(0x80000000)), mnMaxX(0x7fffffff), mnMaxY(0x7fffffff), mbFlag(1), mnState(0)
    {
    }
    // STUB: 0x0043fe10
    void Include(int32_t x, int32_t y);
    // STUB: 0x00440850
    bool Next(int32_t* x, int32_t* y);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0073ebf0 score 215 (frame is 4 bytes smaller and the loop variables are kept in memory here)
bool cUnk00ab3b00::Slot08_ab3b00(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Bounds_ab3b00 bounds;
    bounds.Include(0, 0);
    bounds.Include(a, b);
    bounds.mnMinX = a - c;
    bounds.mnMinY = b - c;
    bounds.mnMaxX = a + c;
    bounds.mnMaxY = b + c;
    if (bounds.mnMaxX < bounds.mnMinX) {
        bounds.mnMaxX = bounds.mnMinX;
    }
    if (bounds.mnMaxY < bounds.mnMinY) {
        bounds.mnMaxY = bounds.mnMinY;
    }
    int32_t cy;
    int32_t cx;
    while (bounds.Next(&cx, &cy)) {
        int32_t x = cx;
        int32_t y = cy;
        if (!gpB43cec->Fn99(x, y)) {
            return false;
        }
        if (!static_cast<uint8_t>(Slot13_ab3b00(x, y))) {
            return false;
        }
        if (d) {
            Pos_ab3b00 pos;
            pos.mfY = gpB43cf4->Fn29();
            pos.mnX = 0;
            pos.mnZ = 0;
            gpB43cec->Fn97(x, y, &pos.mnX, &pos.mnZ);
            uint32_t owner = gpB43d08->Fn05(&pos);
            if (owner && owner != d) {
                return false;
            }
        }
        Tile_ab3b00* tile = gpB43d54->Fn08(x, y, 0x1f4f, 1);
        if (tile && tile->Fn08(0x40000)) {
            float h;
            if (!tile->Fn67(&h)) {
                return false;
            }
            Grid_ab3b00* g = GridOf_ab3b00(this);
            int32_t cell = g->Cell09(x, y);
            if (h - (GridOf_ab3b00(this)->mpDelta[cell * 9] + mpEntries[cell * 9]) < 20.0f) {
                return false;
            }
            return true;
        }
        if (!gpB207e4) {
            PoolRef_ab3b00 ref;
            ref.mp = 0;
            Provider_ab3b00* provider = Fn008793ec();
            if (provider) {
                provider->Fn05(0x3ae4bea3, 0x3ae4beab, &ref);
            }
            gpB207e4 = ref.mp;
            ref.Drop();
        }
        Found_ab3b00 found;
        found.mpHead = gpB207e4->Alloc(0xc);
        found.mpHead->mpNext = found.mpHead;
        found.mpHead->mpPrev = found.mpHead;
        Cell_ab3b00 cellPos;
        cellPos.mnX = x;
        cellPos.mnY = y;
        if (gpB43d0c->Fn41(&found, &cellPos, &cellPos, 0x2890d4de, -1)) {
            bool hit = false;
            Node_ab3b00* node = found.mpHead->mpNext;
            Node_ab3b00* head = found.mpHead;
            while (node != head) {
                Member_ab3b00* member = node->mpValue;
                Spot_ab3b00* spot = 0;
                if (member->QueryInterface(0xa8c86142, reinterpret_cast<void**>(&spot))) {
                    int32_t sx;
                    int32_t sy;
                    spot->Fn08(&sx, &sy);
                    if (sx == x && sy == y) {
                        hit = true;
                    }
                }
                member->Release();
                if (spot) {
                    spot->Release();
                }
                node = node->mpNext;
            }
            if (hit) {
                found.Destroy();
                return false;
            }
        }
        found.Destroy();
    }
    return true;
}
#endif
