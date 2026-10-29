#include "classes/cUnk00adb418.h"

#include <stddef.h>

// A rectangle as four ints: left, top, right, bottom.
struct Rect_adb418 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
};

// The fields of the primary subobject (cUnk00ac1400 names only some of them), seen from this class.
struct Primary_adb418 {
    void* mpVtbl0;
    void* mpVtbl1;
    uint8_t mb8;
    uint8_t mPad9[3];
    uint32_t mn0c;
    uint32_t mn10;
    Rect_adb418 mRect14;
    uint32_t mn24;
    uint32_t mn28;
    uint32_t mnRef;
    uint32_t mn30;
    uint32_t mn34;
    uint16_t mnCount38;
    uint16_t mPad3a;
    uint32_t mn3c;
    uint32_t mn40;
    uint32_t mnFlags;
    uint32_t mn48;
};

// The first slots of the primary vtable, for the two forwarding slots of the second base.
struct PrimaryCalls_adb418 {
    virtual void Fn0();
    virtual void Fn1();
    virtual void Fn2();
    virtual void Fn3();
    virtual void Fn4();
    virtual void Fn5();
    virtual void Fn6();
    virtual void Fn7();
};

// The drawing object the surface's slot 3 hands out (colour, clip and viewport calls).
struct Pen_adb418 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03();
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07();
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11(uint32_t flags);
    virtual void Fn12(float r, float g, float b, float a);
    virtual void Fn13();
    virtual void Fn14();
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18();
    virtual void Fn19();
    virtual void Fn20();
    virtual void Fn21();
    virtual void Fn22();
    virtual void Fn23();
    virtual void Fn24();
    virtual void Fn25();
    virtual void Fn26();
    virtual void Fn27();
    virtual void Fn28();
    virtual void Fn29();
    virtual void Fn30();
    virtual void Fn31();
    virtual void Fn32();
    virtual void Fn33();
    virtual void Fn34();
    virtual void Fn35();
    virtual void Fn36();
    virtual void Fn37();
    virtual void Fn38();
    virtual void Fn39();
    virtual void Fn40();
    virtual void Fn41();
    virtual void Fn42();
    virtual void Fn43();
    virtual void Fn44();
    virtual void Fn45();
    virtual void Fn46();
    virtual void Fn47();
    virtual void Fn48();
    virtual void Fn49();
    virtual void Fn50();
    virtual void Fn51();
    virtual void Fn52();
    virtual void Fn53();
    virtual void Fn54();
    virtual void Fn55();
    virtual void Fn56();
    virtual void Fn57();
    virtual void Fn58();
    virtual void Fn59();
    virtual void Fn60();
    virtual void Fn61();
    virtual void Fn62();
    virtual void Fn63();
    virtual void Fn64();
    virtual void Fn65();
    virtual void Fn66();
    virtual void Fn67();
    virtual void Fn68();
    virtual void Fn69();
    virtual void Fn70();
    virtual void Fn71();
    virtual void Fn72();
    virtual void Fn73();
    virtual void Fn74(int32_t x, int32_t y, int32_t w, int32_t h);
    virtual void Fn75();
    virtual void Fn76(Rect_adb418* pOut);
};

// The surface (+0x78): a counted object whose slot 3 gives the pen.
struct Surface_adb418 {
    virtual bool QueryInterface(uint32_t iid, void* ppOut);
    virtual void AddRef();
    virtual void Release();
    virtual Pen_adb418* Fn03();
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07();
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13(void* a, void* b, void* c);
    virtual void Fn14();
    virtual void Fn15();
    virtual void Fn16();
};

// The service object at +0x74 (and the one the global accessor returns).
struct Service_adb418 {
    virtual bool QueryInterface(uint32_t iid, void* ppOut);
    virtual void AddRef();
    virtual void Release();
    virtual bool Fn03(void* ppOut);
};

// The object at +0x7c.
struct Texture_adb418 {
    virtual bool QueryInterface(uint32_t iid, void* ppOut);
    virtual void AddRef();
    virtual void Release();
    virtual bool Fn03(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
    virtual void Fn04();
    virtual void Fn05();
    virtual bool Fn06(uint32_t a);
    virtual void Fn07(uint32_t a);
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13();
    virtual void Fn14();
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18(uint32_t a, uint32_t b);
};

// A counted object (QueryInterface, AddRef, Release in slots 0 to 2).
struct Ref_adb418 {
    virtual bool QueryInterface(uint32_t iid, void* ppOut);
    virtual void AddRef();
    virtual void Release();
    virtual void* Fn03();
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07(void* a, void* b);
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13();
    virtual void Fn14();
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18();
    virtual void Fn19();
    virtual void Fn20();
    virtual void Fn21();
    virtual void Fn22(uint32_t a);
    virtual void Fn23(uint32_t a);
};

// The primary vtable as calls with typed arguments (the base class declares them with integer arguments).
struct PrimaryApi_adb418 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03();
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07();
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13();
    virtual void Fn14();
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18();
    virtual void Fn19();
    virtual void Fn20();
    virtual void Fn21();
    virtual void Fn22();
    virtual void Fn23();
    virtual void Fn24();
    virtual void Fn25();
    virtual void Fn26();
    virtual void Fn27();
    virtual void Fn28();
    virtual void Fn29();
    virtual void Fn30();
    virtual bool Fn31(uint32_t color, uint8_t* pFirst, uint8_t* pSecond, uint8_t* pThird);
    virtual void Fn32();
    virtual void Fn33();
    virtual void Fn34();
    virtual void Fn35();
    virtual void Fn36();
    virtual void Fn37();
    virtual void Fn38();
    virtual void Fn39();
    virtual void Fn40();
    virtual bool Fn41(void* self, void* pExtent, void* pArea, uint32_t flags);
};

// STUB: 0x00913c1a
Service_adb418* Fn00913c1a();

// The registry the second global accessor returns (slot 3 registers an object under two ids).
struct Registry_adb418 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03(uint32_t a, uint32_t b, void* ppOut);
};

// STUB: 0x0090ddf1
Registry_adb418* Fn0090ddf1();

// A counted pointer that releases on destruction; the address-of is the original out-of-line function.
struct OutRef_adb418 {
    Ref_adb418* mp;
    OutRef_adb418() : mp(0) {}
    ~OutRef_adb418()
    {
        if (mp) {
            mp->Release();
        }
    }
    // STUB: 0x004f20a0
    Ref_adb418** operator&();
};

// The holder the object at +0x74 hands its helper to (constructed and destroyed by two out-of-line functions).
struct Node_adb418;
struct Adopter_adb418 {
    virtual bool QueryInterface(uint32_t iid, void* ppOut);
    virtual void AddRef();
    virtual void Release();
    virtual void Fn03(Node_adb418* p);
};

struct Holder_adb418 {
    Adopter_adb418* mp;
    Holder_adb418() { Init(); }
    ~Holder_adb418() { Done(); }
    // STUB: 0x00449720
    void Init();
    // STUB: 0x004495c0
    void Done();
};

// The smart pointer member at +0x84: assignment is an out-of-line function.
struct Slot_adb418 {
    Ref_adb418* mp;
    // STUB: 0x005447b0
    void Assign(void* p);
};

// A twelve-byte record the holder takes.
struct Node_adb418 {
    uint32_t mData[3];
    // STUB: 0x00991e50
    Node_adb418* Fn00991e50();
};

static inline Primary_adb418* Prim(cUnk00adb418* p)
{
    return reinterpret_cast<Primary_adb418*>(p);
}

// 0x00825d60 is the base class's own AddRef (cUnk00ac1400): the original does not override it here (its secondary
// vtable holds the base's thunk), so it belongs in cUnk00ac1400. This body scores 0 there too.
#ifdef OB_DRAFTS
// CLOSE: 0x00825d60 score 0 (belongs to cUnk00ac1400)
uint32_t cUnk00adb418::Slot01_ac1400()
{
    return ++Prim(this)->mnRef;
}
#endif

// FUNCTION: 0x009917b0
bool cUnk00adb418::Slot00_ac1400(uint32_t iid, uint32_t pOut)
{
    if (iid != 0xe3094dc8) {
        return cUnk00ac1400::Slot00_ac1400(iid, pOut);
    }
    cUnk00adb310** out = reinterpret_cast<cUnk00adb310**>(static_cast<uintptr_t>(pOut));
    *out = this;
    Slot01_ac1400();
    return true;
}

// FUNCTION: 0x009917f0
uint32_t cUnk00adb418::Slot02_ac1400()
{
    if (Prim(this)->mnRef > 1) {
        return --Prim(this)->mnRef;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x00991810
bool cUnk00adb418::Slot05_ac1400()
{
    if (!field50) {
        return false;
    }
    Prim(this)->mb8 = 0;
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00991830 score 4
bool cUnk00adb418::Slot06_ac1400(uint32_t flags)
{
    if (flags & 0xfe0) {
        return false;
    }
    if (flags & 0x8000) {
        Fn00826640();
    }
    Prim(this)->mnFlags |= flags;
    ++Prim(this)->mnCount38;
    return true;
}
#endif

// FUNCTION: 0x00991870
bool cUnk00adb418::Slot07_ac1400(uint32_t flags)
{
    if (flags & 0xfe0) {
        return false;
    }
    return cUnk00ac1400::Slot07_ac1400(flags);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00991890 score 2
void cUnk00adb418::Slot23_adb310()
{
    cUnk00ac1400* p = this;
    reinterpret_cast<PrimaryCalls_adb418*>(p)->Fn6();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009918a0 score 2
void cUnk00adb418::Slot24_adb310()
{
    cUnk00ac1400* p = this;
    reinterpret_cast<PrimaryCalls_adb418*>(p)->Fn7();
}
#endif

// FUNCTION: 0x009918b0
bool cUnk00adb418::Slot12_adb310()
{
    if (Slot39_ac1400()) {
        static_cast<Surface_adb418*>(mpSurface78)->Fn13(this, &Prim(this)->mRect14, &Prim(this)->mRect14);
        static_cast<Surface_adb418*>(mpSurface78)->Fn16();
        return true;
    }
    return false;
}

// FUNCTION: 0x00991900
void cUnk00adb418::Slot25_adb310(uint32_t pRect)
{
    Rect_adb418* r = reinterpret_cast<Rect_adb418*>(static_cast<uintptr_t>(pRect));
    r->mnLeft += mnRectA[0];
    r->mnTop += mnRectA[1];
    r->mnRight += mnRectA[0];
    r->mnBottom += mnRectA[1];
}

// FUNCTION: 0x00991930
void cUnk00adb418::Slot26_adb310(uint32_t pPoint)
{
    int32_t* p = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(pPoint));
    p[0] += mnRectA[0];
    p[1] += mnRectA[1];
}

// FUNCTION: 0x00991970
void* cUnk00adb418::Slot03_adb310()
{
    return this;
}

// FUNCTION: 0x00991980
void cUnk00adb418::Slot09_adb310(uint32_t pOut)
{
    Rect_adb418* out = reinterpret_cast<Rect_adb418*>(static_cast<uintptr_t>(pOut));
    *out = *reinterpret_cast<Rect_adb418*>(mnRectA);
}

// FUNCTION: 0x009919b0
void cUnk00adb418::Slot11_ac1400(uint32_t pOut)
{
    Rect_adb418* out = reinterpret_cast<Rect_adb418*>(static_cast<uintptr_t>(pOut));
    *out = *reinterpret_cast<Rect_adb418*>(mnRectB);
}

// FUNCTION: 0x00991a40
uint32_t cUnk00adb418::Slot18_adb310()
{
    return mnRectA[2] - mnRectA[0];
}

// FUNCTION: 0x00991a50
uint32_t cUnk00adb418::Slot19_adb310()
{
    return mnRectA[3] - mnRectA[1];
}

// FUNCTION: 0x00991a60
bool cUnk00adb418::Slot04_ac1400()
{
    if (mpUnk84 != 0) {
        Ref_adb418* r = static_cast<Ref_adb418*>(mpUnk84);
        mpUnk84 = 0;
        r->Release();
    }
    if (mpUnk74 != 0) {
        static_cast<Service_adb418*>(mpUnk74)->Release();
        mpUnk74 = 0;
    }
    if (mpSurface78 != 0) {
        static_cast<Surface_adb418*>(mpSurface78)->Release();
        mpSurface78 = 0;
    }
    if (mpUnk7c != 0) {
        static_cast<Texture_adb418*>(mpUnk7c)->Fn04();
        static_cast<Texture_adb418*>(mpUnk7c)->Release();
        mpUnk7c = 0;
    }
    Prim(this)->mb8 = 0;
    field50 = false;
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00991ba0 score 1
bool cUnk00adb418::Slot29_ac1400(uint32_t a, uint32_t pRect, uint32_t c, uint32_t d)
{
    if (Prim(this)->mn3c != 0) {
        return cUnk00ac1400::Slot29_ac1400(a, pRect, c, d);
    }
    Rect_adb418* r = reinterpret_cast<Rect_adb418*>(static_cast<uintptr_t>(pRect));
    if (r->mnRight > r->mnLeft && r->mnBottom > r->mnTop) {
        static_cast<Surface_adb418*>(mpSurface78)->Fn13(reinterpret_cast<void*>(static_cast<uintptr_t>(a)), r, reinterpret_cast<void*>(static_cast<uintptr_t>(c)));
        static_cast<Surface_adb418*>(mpSurface78)->Fn16();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00991b10 score 2
bool cUnk00adb418::Slot10_adb310(uint32_t pRect)
{
    Rect_adb418* r = reinterpret_cast<Rect_adb418*>(static_cast<uintptr_t>(pRect));
    *reinterpret_cast<Rect_adb418*>(mnRectA) = *r;
    Primary_adb418* p = Prim(this);
    p->mRect14.mnRight = r->mnRight - r->mnLeft;
    p->mRect14.mnBottom = r->mnBottom - r->mnTop;
    *reinterpret_cast<Rect_adb418*>(mnRectB) = p->mRect14;
    Ref_adb418* local = 0;
    if (mpUnk84 != 0) {
        if (static_cast<Ref_adb418*>(mpUnk84)->QueryInterface(0xab300b2b, &local)) {
            local->Fn08();
        }
        if (local != 0) {
            local->Release();
        }
    }
    return true;
}
#endif

// FUNCTION: 0x00991c00
bool cUnk00adb418::Slot20_ac1400(uint32_t color, uint32_t pRect, uint32_t flags)
{
    Rect_adb418* rect = reinterpret_cast<Rect_adb418*>(static_cast<uintptr_t>(pRect));
    Rect_adb418 extent;
    extent.mnLeft = 0;
    extent.mnTop = 0;
    extent.mnRight = rect->mnRight - rect->mnLeft;
    extent.mnBottom = rect->mnBottom - rect->mnTop;
    Rect_adb418 area = *rect;
    if (reinterpret_cast<PrimaryApi_adb418*>(this)->Fn41(this, &extent, &area, flags)) {
        Service_adb418* service = Fn00913c1a();
        Surface_adb418* surface = 0;
        if (service->QueryInterface(0xc47b747c, &surface)) {
            Pen_adb418* pen = surface->Fn03();
            Rect_adb418 saved;
            pen->Fn76(&saved);
            pen->Fn74(rect->mnLeft, Prim(this)->mRect14.mnBottom - rect->mnBottom, rect->mnRight - rect->mnLeft, rect->mnBottom - rect->mnTop);
            uint8_t first;
            uint8_t second;
            uint8_t third;
            reinterpret_cast<PrimaryApi_adb418*>(this)->Fn31(color, &first, &second, &third);
            pen->Fn12(static_cast<float>(first) * 0.003921569f, static_cast<float>(second) * 0.003921569f, static_cast<float>(third) * 0.003921569f, 1.0f);
            pen->Fn11(0x4000);
            pen->Fn74(saved.mnLeft, saved.mnTop, saved.mnRight - saved.mnLeft, saved.mnBottom - saved.mnTop);
        }
        if (surface) {
            surface->Release();
        }
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00991ec0 score 4
bool cUnk00adb418::Slot04_adb310(uint32_t width, uint32_t height, uint32_t c, uint32_t a4, uint32_t a5)
{
    if (field50) {
        return true;
    }
    if (Prim(this)->mb8) {
        return false;
    }
    if (width == 0 || height == 0) {
        return false;
    }
    if (mpUnk74 == 0) {
        mpUnk74 = Fn00913c1a();
        static_cast<Service_adb418*>(mpUnk74)->AddRef();
    }
    if (mpSurface78 == 0) {
        static_cast<Service_adb418*>(mpUnk74)->QueryInterface(0xc47b747c, &mpSurface78);
    }
    Rect_adb418* rb = reinterpret_cast<Rect_adb418*>(mnRectB);
    rb->mnRight = width;
    rb->mnLeft = 0;
    rb->mnTop = 0;
    rb->mnBottom = height;
    *reinterpret_cast<Rect_adb418*>(mnRectA) = *rb;
    Prim(this)->mRect14 = *rb;
    Prim(this)->mn0c = a4;
    Prim(this)->mn10 = a5;
    Slot45_ac1400();
    if (mpUnk7c == 0 && static_cast<Service_adb418*>(mpUnk74)->Fn03(&mpUnk7c)) {
        if (static_cast<Texture_adb418*>(mpUnk7c)->Fn03(4, 4, Prim(this)->mn0c, Prim(this)->mn10)) {
            if (static_cast<Texture_adb418*>(mpUnk7c)->Fn06(0x8001)) {
                static_cast<Texture_adb418*>(mpUnk7c)->Fn18(mn80, 0);
                static_cast<Texture_adb418*>(mpUnk7c)->Fn07(0x8001);
            }
        } else {
            static_cast<Texture_adb418*>(mpUnk7c)->Release();
            mpUnk7c = 0;
        }
    }
    Prim(this)->mb8 = 1;
    field50 = true;
    Holder_adb418 holder;
    if (holder.mp) {
        Node_adb418* raw = static_cast<Node_adb418*>(operator new(sizeof(Node_adb418)));
        Node_adb418* node = raw ? raw->Fn00991e50() : 0;
        holder.mp->Fn03(node);
        OutRef_adb418 refB;
        OutRef_adb418 refA;
        Fn0090ddf1()->Fn03(0xab300b20, 0xab300b2b, &refA);
        Fn0090ddf1()->Fn03(0xae6320e, 0x2ae63219, &refB);
        refA.mp->Fn07(refB.mp, this);
        refB.mp->Fn22(1);
        refB.mp->Fn23(1);
        reinterpret_cast<Slot_adb418*>(&mpUnk84)->Assign(refA.mp->Fn03());
    }
    return true;
}
#endif

// NOT ATTEMPTED: 0x00991ac0 (Slot15_adb310) hands back a counted pointer (the member at +0x84, else the object itself
// with a reference taken and dropped) as uint32_t; that needs the slot's return type corrected to void* first.
