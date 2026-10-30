#include "classes/cUnk00adc1ec.h"

#include <new>

#include "classes/cGZWin.h"

// The child interface the manager forwards to: the slots used.
struct Child_adc1ec {
    virtual void C0();
    virtual void C1();
    virtual void C2();
    virtual void C3();
    virtual void Forward4(uint32_t a);
    virtual uint32_t Forward5();
    virtual uint32_t Forward6(uint32_t a);
    virtual void Forward7(uint32_t a, uint32_t b);
};

// A table node: the value sits at +8.
struct Node_adc1ec {
    uint32_t next;
    uint32_t key;
    uint32_t value;
};

// The hash table (the original's standard library): bucket vector at +4, element count at +0x10.
struct Table_adc1ec {
    uint32_t pad;
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t unknownC;
    uint32_t mnCount;

    // STUB: 0x00968cd9
    Node_adc1ec* Find(uint32_t* key);
    // STUB: 0x009978af
    void Fn009978af(uint32_t count);
    // STUB: 0x00968cb6
    Node_adc1ec* Fn00968cb6(uint32_t* key);
};

// A found position: the node and its table.
struct Iter_adc1ec {
    Node_adc1ec* node;
    Table_adc1ec* table;
};

// FUNCTION: 0x00996cfb
bool cUnk00adc1ec::QueryInterface(uint32_t iid, void** out)
{
    if (iid == 0x22c2eb1f) {
        *reinterpret_cast<cUnk00adc078**>(out) = this;
        AddRef();
        return true;
    }
    return cRZSystemService::QueryInterface(iid, reinterpret_cast<void**>(out));
}

// FUNCTION: 0x009975dc
void cUnk00adc1ec::Slot27_adc078(uint32_t a)
{
    Child_adc1ec* child = static_cast<Child_adc1ec*>(mpChild);
    if (child) {
        child->Forward4(a);
    }
}

// FUNCTION: 0x009975eb
uint32_t cUnk00adc1ec::Slot28_adc078()
{
    Child_adc1ec* child = static_cast<Child_adc1ec*>(mpChild);
    if (child) {
        return child->Forward5();
    }
    return 0;
}

// FUNCTION: 0x009975fa
uint32_t cUnk00adc1ec::Slot29_adc078(uint32_t a)
{
    Child_adc1ec* child = static_cast<Child_adc1ec*>(mpChild);
    if (child) {
        return child->Forward6(a);
    }
    return 0;
}

// FUNCTION: 0x0099760b
void cUnk00adc1ec::Slot30_adc078(uint32_t a, uint32_t b)
{
    Child_adc1ec* child = static_cast<Child_adc1ec*>(mpChild);
    if (child) {
        child->Forward7(a, b);
    }
}

// FUNCTION: 0x00997b55
uint32_t cUnk00adc1ec::Slot05_adc078(uint32_t key)
{
    Node_adc1ec* node = reinterpret_cast<Table_adc1ec*>(mMapA)->Find(&key);
    if (node) {
        return node->value;
    }
    return 0;
}

// FUNCTION: 0x00997b70
uint32_t cUnk00adc1ec::Slot07_adc078(uint32_t key)
{
    Node_adc1ec* node = reinterpret_cast<Table_adc1ec*>(mMapB)->Find(&key);
    if (node) {
        return node->value;
    }
    return 0;
}

// FUNCTION: 0x00997bc4
uint32_t cUnk00adc1ec::Slot35_adc078(uint32_t key)
{
    Node_adc1ec* node = reinterpret_cast<Table_adc1ec*>(mMapC)->Find(&key);
    if (node) {
        return node->value;
    }
    return 0;
}

// FUNCTION: 0x00997bdf
uint32_t cUnk00adc1ec::Slot37_adc078(uint32_t key)
{
    Node_adc1ec* node = reinterpret_cast<Table_adc1ec*>(mMapD)->Find(&key);
    if (node) {
        return node->value;
    }
    return 0;
}

// FUNCTION: 0x00996e39
void cUnk00adc1ec::Slot09_adc078(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Slot10_adc078(2, a, b, c, d, e);
}

// FUNCTION: 0x00996e56
void cUnk00adc1ec::Slot11_adc078(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Slot10_adc078(3, a, b, c, d, e);
}

// FUNCTION: 0x00996e73
void cUnk00adc1ec::Slot12_adc078(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Slot10_adc078(4, a, b, c, d, e);
}

// FUNCTION: 0x00996d25
uint32_t cUnk00adc1ec::getFontOrSystemFont(uint32_t id)
{
    uint32_t font = Slot05_adc078(id);
    if (font == 0) {
        font = Slot05_adc078(0x68963c4c);
    }
    return font;
}

// A reference slot: assigned through the helper at 0x005447b0.
struct RefSlot_adc1ec {
    void* p;
    // STUB: 0x005447b0
    void Fn005447b0(void* value);
    RefSlot_adc1ec* Fn00997392(const RefSlot_adc1ec* other);
};

// FUNCTION: 0x00997392
RefSlot_adc1ec* RefSlot_adc1ec::Fn00997392(const RefSlot_adc1ec* other)
{
    if (other != this) {
        Fn005447b0(other->p);
    }
    return this;
}

// Views of the control objects the creators build, through the slots each creator uses.
struct Font_adc1ec {
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8();
    virtual void F9();
    virtual void F10();
    virtual void F11();
    virtual uint32_t GetHeight();
};

struct View13_adc1ec {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual void P2();
    virtual cGZWin* GetWin();
    virtual void P4();
    virtual void SetE(uint32_t a, uint32_t b);
    virtual void P6();
    virtual void SetD(uint32_t a, uint32_t b);
    virtual void P8();
    virtual void P9();
    virtual void SetA(uint32_t a);
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void SetC(uint32_t a);
    virtual void P17();
    virtual void SetFont(uint32_t a);
    virtual void P19();
    virtual void P20();
    virtual void SetB(uint32_t a);
};

struct View10_adc1ec {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual void P2();
    virtual cGZWin* GetWin();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void SetF(uint32_t a, uint32_t b, uint32_t c);
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void SetFont(uint32_t a);
};

struct View18_adc1ec {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual void P2();
    virtual cGZWin* GetWin();
    virtual void SetE(uint32_t a);
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void SetC(uint32_t a);
    virtual void SetB(uint32_t a);
    virtual void P11();
    virtual void SetD(uint32_t a);
    virtual void P13();
    virtual void SetA(uint32_t a, uint32_t b);
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void SetG(uint32_t a, uint32_t b);
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void SetF(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
};

struct View14_adc1ec {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual void P2();
    virtual cGZWin* GetWin();
    virtual void P4();
    virtual void SetA(uint32_t a, uint32_t b);
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
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void SetB(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void SetC(uint32_t a, uint32_t b);
};

struct View15_adc1ec {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual void P2();
    virtual cGZWin* GetWin();
    virtual void SetA(uint32_t a);
};

struct View17_adc1ec {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual void P2();
    virtual cGZWin* GetWin();
    virtual cGZWin* GetWin2();
    virtual void SetE(uint32_t a);
};

struct View17b_adc1ec {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void SetD(uint32_t a);
    virtual void P7();
    virtual void SetE(uint32_t a);
    virtual void P9();
    virtual void SetB(uint32_t a);
    virtual void P11();
    virtual void SetC(uint32_t a, uint32_t b);
};

struct View16_adc1ec {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual void P2();
    virtual cGZWin* GetWin();
    virtual void P4();
    virtual void SetF(uint32_t a);
    virtual void SetD(uint32_t a);
    virtual void P7();
    virtual void SetE(uint32_t a);
    virtual void P9();
    virtual void SetB(uint32_t a);
    virtual void P11();
    virtual void SetC(uint32_t a, uint32_t b);
};

struct View19_adc1ec {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual void P2();
    virtual cGZWin* GetWin();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void SetB(uint32_t a);
    virtual void P12();
    virtual void P13();
    virtual void SetC(uint32_t a, uint32_t b);
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void SetA(uint32_t a);
};

struct SubView_adc1ec {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual uint32_t Slot05(uint32_t a);
    virtual void P6();
    virtual uint32_t Slot07(uint32_t a);
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
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual uint32_t Slot32(uint32_t a);
};

// The framework's component manager (the accessor 0x0090ddf1): slot 3 creates a registered class.
struct GZCOM_adc1ec {
    virtual void G0();
    virtual void G1();
    virtual void G2();
    virtual bool Create(uint32_t clsid, uint32_t iid, void* out);
};

// STUB: 0x0090ddf1
GZCOM_adc1ec* Fn0090ddf1();

// The control classes the creators build when the manager has no registered one: constructors in place.
struct Ctl9c19c8_adc1ec {
    // STUB: 0x009c19c8
    Ctl9c19c8_adc1ec* Fn009c19c8();
};
struct Ctl9c46af_adc1ec {
    // STUB: 0x009c46af
    Ctl9c46af_adc1ec* Fn009c46af();
};
struct Ctl9c3836_adc1ec {
    // STUB: 0x009c3836
    Ctl9c3836_adc1ec* Fn009c3836();
};
struct Ctl9b1c27_adc1ec {
    // STUB: 0x009b1c27
    Ctl9b1c27_adc1ec* Fn009b1c27();
};
struct Ctl9bc4ba_adc1ec {
    // STUB: 0x009bc4ba
    Ctl9bc4ba_adc1ec* Fn009bc4ba();
};
// The bitmap object: width and height.
struct Bitmap_adc1ec {
    virtual void B0();
    virtual void B1();
    virtual void B2();
    virtual void B3();
    virtual void B4();
    virtual void B5();
    virtual void B6();
    virtual void B7();
    virtual void B8();
    virtual uint32_t GetWidth();
    virtual uint32_t GetHeight();
};
struct Ctl9c68ac_adc1ec {
    // STUB: 0x009c68ac
    Ctl9c68ac_adc1ec* Fn009c68ac(bool flag);
};
struct Ctl9c5327_adc1ec {
    // STUB: 0x009c5327
    Ctl9c5327_adc1ec* Fn009c5327();
};
struct Ctl9c7bb8_adc1ec {
    // STUB: 0x009c7bb8
    Ctl9c7bb8_adc1ec* Fn009c7bb8();
};

// The rectangle record the sizing creators take.
struct Rect_adc1ec {
    int32_t l;
    int32_t t;
    int32_t r;
    int32_t b;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00996e90 score 9
uint32_t cUnk00adc1ec::Slot13_adc078(uint32_t id, uint32_t arg)
{
    View13_adc1ec* p = 0;
    if (!Fn0090ddf1()->Create(0x592, 0x212cdc1f, &p)) {
        void* mem = ::operator new(0x114);
        Ctl9c19c8_adc1ec* obj = mem ? static_cast<Ctl9c19c8_adc1ec*>(mem)->Fn009c19c8() : 0;
        p = obj ? reinterpret_cast<View13_adc1ec*>(reinterpret_cast<char*>(obj) + 0xd8) : 0;
        p->AddRef();
    }
    cGZWin* win = p->GetWin();
    SubView_adc1ec* sv = reinterpret_cast<SubView_adc1ec*>(static_cast<cUnk00adc078*>(this));
    uint32_t font = sv->Slot05(0x68963c4c);
    uint32_t height = 0;
    if (font) {
        height = reinterpret_cast<Font_adc1ec*>(font)->GetHeight();
    }
    win->Slot47_adda20(id);
    win->Slot49_adda20(arg);
    p->SetFont(font);
    p->SetA(height);
    p->SetB(1);
    p->SetC(0);
    p->SetD(2, 0);
    p->SetE(0, 0);
    return OB_ADDR(p);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00996d52 score 37
uint32_t cUnk00adc1ec::Slot10_adc078(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    View10_adc1ec* p = 0;
    if (!Fn0090ddf1()->Create(0x22ecfc47, 0x8810, &p)) {
        void* mem = ::operator new(0x1b4);
        Ctl9b1c27_adc1ec* obj = mem ? static_cast<Ctl9b1c27_adc1ec*>(mem)->Fn009b1c27() : 0;
        p = reinterpret_cast<View10_adc1ec*>(obj);
        p->AddRef();
    }
    cGZWin* win = p->GetWin();
    uint32_t font = Slot05_adc078(0x68963c54);
    if (e == 0) {
        e = Slot07_adc078(0xe8963ef1);
    }
    win->Slot47_adda20(b);
    win->Slot49_adda20(c);
    win->Slot08_ae1a28(reinterpret_cast<SubView_adc1ec*>(static_cast<cUnk00adc078*>(this))->Slot32(0x28963f93));
    p->SetFont(font);
    p->SetF(a, e, f);
    win->SetKeyEquivalent(0);
    return OB_ADDR(p);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009971ae score 11
uint32_t cUnk00adc1ec::Slot18_adc078(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    View18_adc1ec* p = 0;
    if (!Fn0090ddf1()->Create(0x612ce0c4, 0x612ce0c3, &p)) {
        void* mem = ::operator new(0x170);
        Ctl9c5327_adc1ec* obj = mem ? static_cast<Ctl9c5327_adc1ec*>(mem)->Fn009c5327() : 0;
        p = obj ? reinterpret_cast<View18_adc1ec*>(reinterpret_cast<char*>(obj) + 0xd8) : 0;
        p->AddRef();
    }
    cGZWin* win = p->GetWin();
    SubView_adc1ec* sv = reinterpret_cast<SubView_adc1ec*>(static_cast<cUnk00adc078*>(this));
    uint32_t t7 = sv->Slot07(0x68963ed6);
    uint32_t c0 = sv->Slot32(0xa8963fad);
    uint32_t c1 = sv->Slot32(0x8963faf);
    p->SetA(t7, 0);
    p->SetB(e);
    p->SetC(f);
    p->SetD(d);
    p->SetE(b);
    p->SetF(c0, c0, c1, c1);
    p->SetG(2, sv->Slot32(0x28963f93));
    win->Slot47_adda20(a);
    return OB_ADDR(p);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00997667 score 65
uint32_t cUnk00adc1ec::Slot14_adc078(uint32_t id, uint32_t arg, uint32_t rect)
{
    View14_adc1ec* p = 0;
    if (!Fn0090ddf1()->Create(0xa1336cc1, 0xa1336cc0, &p)) {
        void* mem = ::operator new(0x11c);
        Ctl9c7bb8_adc1ec* obj = mem ? static_cast<Ctl9c7bb8_adc1ec*>(mem)->Fn009c7bb8() : 0;
        p = obj ? reinterpret_cast<View14_adc1ec*>(reinterpret_cast<char*>(obj) + 0xd8) : 0;
        p->AddRef();
    }
    cGZWin* win = p->GetWin();
    win->Slot47_adda20(id);
    win->Slot49_adda20(arg);
    const Rect_adc1ec* r = OB_PTR(const Rect_adc1ec, rect);
    if (r) {
        win->Slot07_add348(r->l, r->t, r->r, r->b);
    }
    p->SetA(1, 1);
    p->SetA(4, 0);
    p->SetA(8, 1);
    SubView_adc1ec* sv = reinterpret_cast<SubView_adc1ec*>(static_cast<cUnk00adc078*>(this));
    uint32_t k = 0xa8963fad;
    uint32_t v0 = sv->Slot32(k);
    uint32_t v1 = sv->Slot32(0x8963faf);
    uint32_t v2 = sv->Slot32(k);
    uint32_t v3 = sv->Slot32(k);
    p->SetB(v3, v2, v1, v0);
    int32_t width = r ? r->r - r->l : 0x80;
    p->SetC(0, width);
    return OB_ADDR(p);
}
#endif

// FUNCTION: 0x00996f75
uint32_t cUnk00adc1ec::Slot15_adc078(uint32_t id, uint32_t size, uint32_t resize)
{
    View15_adc1ec* p = 0;
    if (!Fn0090ddf1()->Create(0x82fe68c4, 0xc12cea13, &p)) {
        void* mem = ::operator new(0xfc);
        Ctl9bc4ba_adc1ec* obj = mem ? static_cast<Ctl9bc4ba_adc1ec*>(mem)->Fn009bc4ba() : 0;
        p = obj ? reinterpret_cast<View15_adc1ec*>(reinterpret_cast<char*>(obj) + 0xd8) : 0;
        p->AddRef();
    }
    cGZWin* win = p->GetWin();
    win->Slot47_adda20(id);
    p->SetA(size);
    Bitmap_adc1ec* bmp = OB_PTR(Bitmap_adc1ec, size);
    if ((resize & 0xff) && bmp) {
        win->SetSize_2(bmp->GetWidth(), bmp->GetHeight());
    }
    return OB_ADDR(p);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009970e8 score 7
uint32_t cUnk00adc1ec::Slot17_adc078(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    View17_adc1ec* p = 0;
    if (!Fn0090ddf1()->Create(0x61325a2e, 0x61325a2d, &p)) {
        void* mem = ::operator new(0x150);
        Ctl9c46af_adc1ec* obj = mem ? static_cast<Ctl9c46af_adc1ec*>(mem)->Fn009c46af() : 0;
        p = obj ? reinterpret_cast<View17_adc1ec*>(reinterpret_cast<char*>(obj) + 0x124) : 0;
        p->AddRef();
    }
    cGZWin* win = p->GetWin();
    View17b_adc1ec* q = reinterpret_cast<View17b_adc1ec*>(p->GetWin2());
    uint32_t t = reinterpret_cast<SubView_adc1ec*>(static_cast<cUnk00adc078*>(this))->Slot07(0xe8963ec7);
    win->Slot47_adda20(a);
    q->SetB(b);
    q->SetC(t, 0);
    q->SetD(c);
    q->SetE(d);
    p->SetE(e);
    return OB_ADDR(p);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099701e score 34
uint32_t cUnk00adc1ec::Slot16_adc078(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    View16_adc1ec* p = 0;
    if (!Fn0090ddf1()->Create(0x21325208, 0x21325207, &p)) {
        void* mem = ::operator new(0x124);
        Ctl9c3836_adc1ec* obj = mem ? static_cast<Ctl9c3836_adc1ec*>(mem)->Fn009c3836() : 0;
        p = obj ? reinterpret_cast<View16_adc1ec*>(reinterpret_cast<char*>(obj) + 0xd8) : 0;
        p->AddRef();
    }
    p->GetWin()->Slot47_adda20(a);
    p->SetB(b);
    uint32_t t = reinterpret_cast<SubView_adc1ec*>(static_cast<cUnk00adc078*>(this))->Slot07(b == 1 ? 0x88963ec1 : 0xa8963ec4);
    p->SetC(t, 0);
    p->SetD(c);
    p->SetE(d);
    p->SetF(e);
    return OB_ADDR(p);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009972c6 score 6
uint32_t cUnk00adc1ec::Slot19_adc078(uint32_t id, uint32_t flag)
{
    View19_adc1ec* p = 0;
    if (!Fn0090ddf1()->Create(0x21335c5a, 0x21335c59, &p)) {
        void* mem = ::operator new(0x150);
        Ctl9c68ac_adc1ec* obj = mem ? static_cast<Ctl9c68ac_adc1ec*>(mem)->Fn009c68ac(true) : 0;
        p = obj ? reinterpret_cast<View19_adc1ec*>(reinterpret_cast<char*>(obj) + 0xd8) : 0;
        p->AddRef();
    }
    cGZWin* win = p->GetWin();
    p->SetA(flag);
    p->SetB(2);
    SubView_adc1ec* sv = reinterpret_cast<SubView_adc1ec*>(static_cast<cUnk00adc078*>(this));
    p->SetC(0, sv->Slot32(0xa8963fad));
    p->SetC(1, sv->Slot32(0x8963faf));
    win->Slot47_adda20(id);
    return OB_ADDR(p);
}
#endif

// The table's remaining members the manager uses (positions, erase, insert, iteration).
struct Pair_adc1ec {
    uint32_t key;
    uint32_t value;
};

struct TableOps_adc1ec {
    uint32_t pad;
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t unknownC;
    uint32_t mnCount;

    // STUB: 0x00968cd9
    Node_adc1ec* Find(uint32_t* key);
    // STUB: 0x0092dc3a
    void Erase(Iter_adc1ec position);
    // STUB: 0x0092fdd8
    void Insert(uint32_t* out, Pair_adc1ec* pair);
    // STUB: 0x0097c081
    void Begin(Iter_adc1ec* out);
    // STUB: 0x0097c1a2
    void Clear();
    // STUB: 0x00968cb6
    Node_adc1ec* Fn00968cb6(uint32_t* key);
    // STUB: 0x009978af
    void Fn009978af(uint32_t count);
    Iter_adc1ec* Fn00968ed8(Iter_adc1ec* out, uint32_t* key);
    // STUB: 0x00997866
    uint32_t* Fn00997866(Pair_adc1ec* pair);
    uint32_t* Fn00997c95(uint32_t* key);
};

// An iterator's advance.
struct IterOps_adc1ec {
    Node_adc1ec* node;
    Table_adc1ec* table;
    // STUB: 0x00969127
    void Advance();
};

// A released/added object.
struct Obj_adc1ec {
    virtual void O0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

// A creator in the list.
struct Creator_adc1ec {
    virtual bool QueryInterface(uint32_t iid, void* out);
    virtual void C1();
    virtual void C2();
    virtual void C3();
    virtual bool Init();
    virtual void C5();
    virtual bool TryCreate(uint32_t a, uint32_t b, uint32_t c);
};

// A list node.
struct ListNode_adc1ec {
    ListNode_adc1ec* next;
    ListNode_adc1ec* prev;
    Creator_adc1ec* value;
};

// The creator list.
struct List_adc1ec {
    // STUB: 0x009d74d9
    void PushFront(Creator_adc1ec** value);
    // STUB: 0x00949259
    void Erase(ListNode_adc1ec* position, ListNode_adc1ec** out);
};

// STUB: 0x009d07a0
void Fn009d07a0(ListNode_adc1ec** out, ListNode_adc1ec* first, ListNode_adc1ec* last, uint32_t* value);

// A smart pointer temporary the original builds around an argument.
struct Smart_adc1ec {
    void* p;
    // STUB: 0x004f20c0
    Smart_adc1ec* Fn004f20c0(void* raw);
};

// FUNCTION: 0x00968ed8
Iter_adc1ec* TableOps_adc1ec::Fn00968ed8(Iter_adc1ec* out, uint32_t* key)
{
    out->node = Find(key);
    out->table = reinterpret_cast<Table_adc1ec*>(this);
    return out;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00997866 score 16
uint32_t* TableOps_adc1ec::Fn00997866(Pair_adc1ec* pair)
{
    Fn009978af(mnCount + 1);
    uint32_t bucket = pair->key % static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t head = mpBegin[bucket];
    Node_adc1ec* node = Fn00968cb6(reinterpret_cast<uint32_t*>(pair));
    node->next = head;
    mpBegin[bucket] = OB_ADDR(node);
    mnCount++;
    return &node->key;
}
#endif

// FUNCTION: 0x00997c95
uint32_t* TableOps_adc1ec::Fn00997c95(uint32_t* key)
{
    Iter_adc1ec it;
    Fn00968ed8(&it, key);
    if (it.node == 0) {
        Pair_adc1ec pair;
        pair.key = *key;
        pair.value = 0;
        return Fn00997866(&pair) + 1;
    }
    return &it.node->value;
}

struct Colors_adc1ec {
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
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual uint32_t SetRgb(uint32_t a, uint32_t b, uint32_t c);
};

struct Probe_adc1ec {
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
    virtual bool Accept(uint32_t value, uint32_t flag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00997b8b score 6
void cUnk00adc1ec::Slot32_adc078(uint32_t key)
{
    Node_adc1ec* node = reinterpret_cast<Table_adc1ec*>(mMapE)->Find(&key);
    if (node) {
        Colors_adc1ec* p = static_cast<Colors_adc1ec*>(mpColors);
        if (p) {
            uint32_t rgb = node->value;
            p->SetRgb(rgb >> 16, rgb >> 8, rgb);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009977a9 score 26
void cUnk00adc1ec::Slot26_adc078(uint32_t a, uint32_t b, uint32_t c)
{
    ListNode_adc1ec* head = static_cast<ListNode_adc1ec*>(mpCreators);
    ListNode_adc1ec* n = head->next;
    while (n != head) {
        if (n->value->TryCreate(a, b, c)) {
            return;
        }
        n = n->next;
    }
    Slot42_adc078(a, b, c);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009977f2 score 38
bool cUnk00adc1ec::Slot25_adc078(uint32_t creator)
{
    ListNode_adc1ec* head = static_cast<ListNode_adc1ec*>(mpCreators);
    ListNode_adc1ec* found;
    Fn009d07a0(&found, head, head->next, &creator);
    if (found == head) {
        return false;
    }
    reinterpret_cast<Obj_adc1ec*>(found->value)->Release();
    reinterpret_cast<Obj_adc1ec*>(found->value)->Release();
    ListNode_adc1ec* out;
    reinterpret_cast<List_adc1ec*>(&mpCreators)->Erase(found, &out);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00997c44 score 15
bool cUnk00adc1ec::Slot24_adc078(uint32_t creator)
{
    Creator_adc1ec* c = OB_PTR(Creator_adc1ec, creator);
    if (c) {
        uint32_t tmp = 0;
        if (c->QueryInterface(0xa2ed067f, &tmp)) {
            Slot25_adc078(creator);
            if (c->Init()) {
                reinterpret_cast<List_adc1ec*>(&mpCreators)->PushFront(&c);
                return true;
            }
            return false;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00997bfa score 31
uint32_t cUnk00adc1ec::Slot38_adc078(uint32_t probe)
{
    Iter_adc1ec it;
    reinterpret_cast<TableOps_adc1ec*>(mMapD)->Begin(&it);
    while (it.node) {
        Probe_adc1ec* p = OB_PTR(Probe_adc1ec, probe);
        if (p->Accept(it.node->value, 1)) {
            return it.node->key;
        }
        reinterpret_cast<IterOps_adc1ec*>(&it)->Advance();
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099876a score 21
void cUnk00adc1ec::Slot33_adc078(uint32_t key, uint32_t r, uint32_t g, uint32_t b)
{
    TableOps_adc1ec* t = reinterpret_cast<TableOps_adc1ec*>(mMapE);
    uint32_t packed = (((static_cast<uint8_t>(r) << 8) | static_cast<uint8_t>(g)) << 8) | static_cast<uint8_t>(b);
    Node_adc1ec* node = t->Find(&key);
    if (node) {
        Iter_adc1ec it;
        it.node = node;
        it.table = reinterpret_cast<Table_adc1ec*>(t);
        t->Erase(it);
    }
    uint32_t out[5];
    Pair_adc1ec pair;
    pair.key = key;
    pair.value = packed;
    t->Insert(out, &pair);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00997d6b score 19
void cUnk00adc1ec::Slot31_adc078(uint32_t key, uint32_t pr, uint32_t pg, uint32_t pb)
{
    TableOps_adc1ec* t = reinterpret_cast<TableOps_adc1ec*>(mMapE);
    if (t->Find(&key)) {
        *OB_PTR(uint8_t, pr) = reinterpret_cast<uint8_t*>(t->Fn00997c95(&key))[2];
        *OB_PTR(uint8_t, pg) = reinterpret_cast<uint8_t*>(t->Fn00997c95(&key))[1];
        *OB_PTR(uint8_t, pb) = reinterpret_cast<uint8_t*>(t->Fn00997c95(&key))[0];
    } else {
        *OB_PTR(uint8_t, pb) = 0;
        *OB_PTR(uint8_t, pg) = 0;
        *OB_PTR(uint8_t, pr) = 0;
    }
}
#endif

struct Source_adc1ec {
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
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void GetRgb(uint32_t id, uint8_t* r, uint8_t* g, uint8_t* b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0099761a score 31
void cUnk00adc1ec::Slot34_adc078(uint32_t key, uint32_t id)
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    if (mpColors) {
        static_cast<Source_adc1ec*>(mpColors)->GetRgb(id, &r, &g, &b);
    }
    Slot33_adc078(key, r, g, b);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00997a30 score 24
bool cUnk00adc1ec::Slot04_ae1d24()
{
    reinterpret_cast<TableOps_adc1ec*>(mMapE)->Clear();
    Iter_adc1ec it;
    TableOps_adc1ec* t = reinterpret_cast<TableOps_adc1ec*>(mMapA);
    for (t->Begin(&it); it.node; reinterpret_cast<IterOps_adc1ec*>(&it)->Advance()) {
        Obj_adc1ec* o = OB_PTR(Obj_adc1ec, it.node->value);
        if (o) {
            o->Release();
        }
    }
    t->Clear();
    t = reinterpret_cast<TableOps_adc1ec*>(mMapB);
    for (t->Begin(&it); it.node; reinterpret_cast<IterOps_adc1ec*>(&it)->Advance()) {
        Obj_adc1ec* o = OB_PTR(Obj_adc1ec, it.node->value);
        if (o) {
            o->Release();
        }
    }
    t->Clear();
    t = reinterpret_cast<TableOps_adc1ec*>(mMapC);
    for (t->Begin(&it); it.node; reinterpret_cast<IterOps_adc1ec*>(&it)->Advance()) {
        Obj_adc1ec* o = OB_PTR(Obj_adc1ec, it.node->value);
        if (o) {
            o->Release();
        }
    }
    t->Clear();
    t = reinterpret_cast<TableOps_adc1ec*>(mMapD);
    for (t->Begin(&it); it.node; reinterpret_cast<IterOps_adc1ec*>(&it)->Advance()) {
        Obj_adc1ec* o = OB_PTR(Obj_adc1ec, it.node->value);
        if (o) {
            o->Release();
        }
    }
    t->Clear();
    ListNode_adc1ec* head = static_cast<ListNode_adc1ec*>(mpCreators);
    while (head->next != head) {
        Slot25_adc078(OB_ADDR(head->next->value));
    }
    reinterpret_cast<RefSlot_adc1ec*>(&mpColors)->Fn005447b0(0);
    reinterpret_cast<RefSlot_adc1ec*>(&mpChild)->Fn005447b0(0);
    mbInitialized = false;
    return true;
}
#endif

// Locals of the setup: reference-counted holders.
struct Holder449560_adc1ec {
    void* p;
    // STUB: 0x00449560
    Holder449560_adc1ec* Fn00449560();
    // STUB: 0x004495c0
    void Fn004495c0();
};
struct Holder4edfd0_adc1ec {
    void* p;
    // STUB: 0x004edfd0
    Holder4edfd0_adc1ec* Fn004edfd0();
    // STUB: 0x004edf00
    void Fn004edf00();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009973aa score 28
bool cUnk00adc1ec::Slot03_ae1d24()
{
    if (!mbInitialized) {
        mbInitialized = true;
        Holder449560_adc1ec first;
        Holder4edfd0_adc1ec second;
        first.Fn00449560();
        Smart_adc1ec tmp;
        tmp.Fn004f20c0(first.p);
        reinterpret_cast<RefSlot_adc1ec*>(&mpColors)->Fn00997392(reinterpret_cast<RefSlot_adc1ec*>(&tmp));
        if (tmp.p) {
            static_cast<Obj_adc1ec*>(tmp.p)->Release();
        }
        second.Fn004edfd0();
        tmp.Fn004f20c0(second.p);
        reinterpret_cast<RefSlot_adc1ec*>(&mpChild)->Fn00997392(reinterpret_cast<RefSlot_adc1ec*>(&tmp));
        if (tmp.p) {
            static_cast<Obj_adc1ec*>(tmp.p)->Release();
        }
        Slot33_adc078(0x68963f7d, 0, 0, 0);
        Slot33_adc078(0x28963fc5, 0x80, 0, 0);
        Slot33_adc078(0xa8963f82, 0, 0x80, 0);
        Slot33_adc078(0x48963f84, 0x80, 0x80, 0x40);
        Slot33_adc078(0x68963f8a, 0, 0, 0x80);
        Slot33_adc078(0xa8963f8c, 0x80, 0, 0x80);
        Slot33_adc078(0x68963f8f, 0, 0x80, 0x80);
        Slot33_adc078(0x8963f91, 0x80, 0x80, 0x80);
        Slot33_adc078(0x28963f93, 0xc0, 0xc0, 0xc0);
        Slot33_adc078(0xe8963f95, 0xff, 0, 0);
        Slot33_adc078(0x28963f98, 0, 0xff, 0);
        Slot33_adc078(0xe8963f9a, 0xff, 0xff, 0);
        Slot33_adc078(0xc8963fa2, 0, 0, 0xff);
        Slot33_adc078(0x8963fa5, 0, 0xff, 0xff);
        Slot33_adc078(0x28963fa8, 0xff, 0xff, 0xff);
        Slot33_adc078(0x88963fab, 0x40, 0x40, 0x40);
        Slot33_adc078(0xa8963fad, 0x40, 0x40, 0x40);
        Slot33_adc078(0x8963faf, 0xc0, 0xc0, 0xc0);
        Slot33_adc078(0xa8963fb2, 0xff, 0xff, 0xff);
        Slot33_adc078(0x88963fb4, 0xc0, 0xc0, 0xc0);
        Slot33_adc078(0x8963fb9, 0xa0, 0xa0, 0xa0);
        Slot33_adc078(0x28963fbc, 0xff, 0xff, 0xff);
        second.Fn004edf00();
        first.Fn004495c0();
    }
    return true;
}
#endif

// Slots 6, 8, 36 and 39 replace the entry of one of the four tables with a new object.
#ifdef OB_DRAFTS
// CLOSE: 0x00998670 score 55
void cUnk00adc1ec::Slot06_adc078(uint32_t key, uint32_t object)
{
    Smart_adc1ec hold;
    hold.p = OB_PTR(void, object);
    TableOps_adc1ec* t = reinterpret_cast<TableOps_adc1ec*>(mMapA);
    Node_adc1ec* node = t->Find(&key);
    if (node) {
        Obj_adc1ec* old = OB_PTR(Obj_adc1ec, node->value);
        if (old) {
            old->Release();
        }
        Iter_adc1ec it;
        it.node = node;
        it.table = reinterpret_cast<Table_adc1ec*>(t);
        t->Erase(it);
    }
    if (object) {
        OB_PTR(Obj_adc1ec, object)->AddRef();
    }
    uint32_t out[5];
    Pair_adc1ec pair;
    pair.key = key;
    pair.value = object;
    t->Insert(out, &pair);
    if (hold.p) {
        static_cast<Obj_adc1ec*>(hold.p)->Release();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009986ed score 55
void cUnk00adc1ec::Slot08_adc078(uint32_t key, uint32_t object)
{
    Smart_adc1ec hold;
    hold.p = OB_PTR(void, object);
    TableOps_adc1ec* t = reinterpret_cast<TableOps_adc1ec*>(mMapB);
    Node_adc1ec* node = t->Find(&key);
    if (node) {
        Obj_adc1ec* old = OB_PTR(Obj_adc1ec, node->value);
        if (old) {
            old->Release();
        }
        Iter_adc1ec it;
        it.node = node;
        it.table = reinterpret_cast<Table_adc1ec*>(t);
        t->Erase(it);
    }
    if (object) {
        OB_PTR(Obj_adc1ec, object)->AddRef();
    }
    uint32_t out[5];
    Pair_adc1ec pair;
    pair.key = key;
    pair.value = object;
    t->Insert(out, &pair);
    if (hold.p) {
        static_cast<Obj_adc1ec*>(hold.p)->Release();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009987c5 score 55
void cUnk00adc1ec::Slot36_adc078(uint32_t key, uint32_t object)
{
    Smart_adc1ec hold;
    hold.p = OB_PTR(void, object);
    TableOps_adc1ec* t = reinterpret_cast<TableOps_adc1ec*>(mMapC);
    Node_adc1ec* node = t->Find(&key);
    if (node) {
        Obj_adc1ec* old = OB_PTR(Obj_adc1ec, node->value);
        if (old) {
            old->Release();
        }
        Iter_adc1ec it;
        it.node = node;
        it.table = reinterpret_cast<Table_adc1ec*>(t);
        t->Erase(it);
    }
    if (object) {
        OB_PTR(Obj_adc1ec, object)->AddRef();
    }
    uint32_t out[5];
    Pair_adc1ec pair;
    pair.key = key;
    pair.value = object;
    t->Insert(out, &pair);
    if (hold.p) {
        static_cast<Obj_adc1ec*>(hold.p)->Release();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00998842 score 55
void cUnk00adc1ec::Slot39_adc078(uint32_t key, uint32_t object)
{
    Smart_adc1ec hold;
    hold.p = OB_PTR(void, object);
    TableOps_adc1ec* t = reinterpret_cast<TableOps_adc1ec*>(mMapD);
    Node_adc1ec* node = t->Find(&key);
    if (node) {
        Obj_adc1ec* old = OB_PTR(Obj_adc1ec, node->value);
        if (old) {
            old->Release();
        }
        Iter_adc1ec it;
        it.node = node;
        it.table = reinterpret_cast<Table_adc1ec*>(t);
        t->Erase(it);
    }
    if (object) {
        OB_PTR(Obj_adc1ec, object)->AddRef();
    }
    uint32_t out[5];
    Pair_adc1ec pair;
    pair.key = key;
    pair.value = object;
    t->Insert(out, &pair);
    if (hold.p) {
        static_cast<Obj_adc1ec*>(hold.p)->Release();
    }
}
#endif

// A finished control asked to initialise itself from the request.
struct Created_adc1ec {
    virtual bool InitFrom(uint32_t a, uint32_t b);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00997dd1 score 741
// Partial draft: only the cases that forward to another creator slot are written (the other classes of control
// build their object inline, with the settings of the Mac build's CreateDefaultCtrl).
bool cUnk00adc1ec::Slot42_adc078(uint32_t clsid, uint32_t a, uint32_t b)
{
    uint32_t made;
    switch (clsid) {
    case 0x48963e30:
        made = Slot17_adc078(0, 2, 0, 200, 100);
        break;
    case 0x28963e2c:
        made = Slot17_adc078(0, 1, 0, 200, 100);
        break;
    case 0x48963e28:
        made = Slot19_adc078(0, 1);
        break;
    default:
        return false;
    }
    Created_adc1ec* c = OB_PTR(Created_adc1ec, made);
    bool ok = c->InitFrom(a, b);
    c->Release();
    return ok;
}
#endif
