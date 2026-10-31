// Shape families of packet shaped08_game (pairs), written by hand.
#include <new>
#include "common/compiler.h"
#include "common/types.h"

struct View_007ff3c0_shaped08_game {
    uint8_t pad[0x28];
    uint8_t mbFlag;
    uint32_t Fn007ff3c0();
};

// FUNCTION: 0x007ff3c0
uint32_t View_007ff3c0_shaped08_game::Fn007ff3c0()
{
    return mbFlag;
}

struct View_007fb1c0_shaped08_game {
    uint8_t pad[0x9f];
    uint8_t mbFlag;
    uint32_t Fn007fb1c0();
};

// FUNCTION: 0x007fb1c0
uint32_t View_007fb1c0_shaped08_game::Fn007fb1c0()
{
    return mbFlag;
}

struct View_007ff070_shaped08_game {
    uint8_t pad[0x10];
    uint32_t mnValue;
    uint8_t pad14[0x17c - 0x14];
    uint32_t mnVersion;
    void SetDepthSize(uint32_t v);
};

// FUNCTION: 0x007ff070
void View_007ff070_shaped08_game::SetDepthSize(uint32_t v)
{
    mnVersion++;
    mnValue = v;
}

struct View_007ff0f0_shaped08_game {
    uint8_t pad[0x17c];
    uint32_t mnVersion;
    uint8_t pad180[0x1a4 - 0x180];
    uint32_t mnValue;
    void SetDepthOffset(uint32_t v);
};

// FUNCTION: 0x007ff0f0
void View_007ff0f0_shaped08_game::SetDepthOffset(uint32_t v)
{
    mnVersion++;
    mnValue = v;
}

struct Target_007b62f0_shaped08_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual uint32_t Slot09();
    virtual uint32_t Slot0A();
};

struct View_007b62f0_shaped08_game {
    uint32_t mpOwnerAtMinus20() const;
    uint32_t Fn007b62f0();
    uint32_t Fn007b6310();
};

#ifdef OB_DRAFTS
// CLOSE: 0x007b62f0 score 7
uint32_t View_007b62f0_shaped08_game::Fn007b62f0()
{
    Target_007b62f0_shaped08_game* p = *reinterpret_cast<Target_007b62f0_shaped08_game**>(reinterpret_cast<uint8_t*>(this) - 0x20);
    if (p) {
        return p->Slot09();
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007b6310 score 7
uint32_t View_007b62f0_shaped08_game::Fn007b6310()
{
    Target_007b62f0_shaped08_game* p = *reinterpret_cast<Target_007b62f0_shaped08_game**>(reinterpret_cast<uint8_t*>(this) - 0x20);
    if (p) {
        return p->Slot0A();
    }
    return 0;
}
#endif

struct Dtor_00817790_shaped08_game {
    virtual void Destroy(uint32_t flag);
};

struct View_00817790_shaped08_game : Dtor_00817790_shaped08_game {
    uint32_t mnRefs;
    uint32_t Fn00817790();
};

// FUNCTION: 0x00817790
uint32_t View_00817790_shaped08_game::Fn00817790()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_0081d7d0_shaped08_game : Dtor_00817790_shaped08_game {
    uint32_t pad4;
    uint32_t mnRefs;
    uint32_t Fn0081d7d0();
};

// FUNCTION: 0x0081d7d0
uint32_t View_0081d7d0_shaped08_game::Fn0081d7d0()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_007a98c0_shaped08_game {
    uint8_t pad[0x110];
    uint8_t mnLow;
    uint8_t mnHigh;
    void SetOpacityRange(uint8_t lo, uint8_t hi);
};

// FUNCTION: 0x007a98c0
void View_007a98c0_shaped08_game::SetOpacityRange(uint8_t lo, uint8_t hi)
{
    mnLow = lo;
    mnHigh = hi;
}

struct View_007b2410_shaped08_game {
    uint8_t pad[0x111];
    uint8_t mnLow;
    uint8_t mnHigh;
    void Fn007b2410(uint8_t lo, uint8_t hi);
};

// FUNCTION: 0x007b2410
void View_007b2410_shaped08_game::Fn007b2410(uint8_t lo, uint8_t hi)
{
    mnLow = lo;
    mnHigh = hi;
}

struct Vec3_shaped08_game {
    uint32_t x;
    uint32_t y;
    uint32_t z;
};

struct View_00800f10_shaped08_game {
    uint8_t pad[0x18];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    View_00800f10_shaped08_game* Fn00800f10(const Vec3_shaped08_game* p);
};

// FUNCTION: 0x00800f10
View_00800f10_shaped08_game* View_00800f10_shaped08_game::Fn00800f10(const Vec3_shaped08_game* p)
{
    mX = p->x;
    mY = p->y;
    mZ = p->z;
    return this;
}

struct View_00800f80_shaped08_game {
    uint8_t pad[0xc];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    View_00800f80_shaped08_game* Fn00800f80(const Vec3_shaped08_game* p);
};

// FUNCTION: 0x00800f80
View_00800f80_shaped08_game* View_00800f80_shaped08_game::Fn00800f80(const Vec3_shaped08_game* p)
{
    mX = p->x;
    mY = p->y;
    mZ = p->z;
    return this;
}

struct View_0079a5e0_shaped08_game {
    uint8_t pad[0xdc];
    uint32_t* mpItems;
    uint8_t pade0[0xe8 - 0xe0];
    int32_t mnCount;
    uint8_t padec[0xf0 - 0xec];
    int32_t mnHighlighted;
    int32_t mnSelected;
    uint32_t GetHighlightedItem();
    uint32_t GetSelectedItem();
};

// FUNCTION: 0x0079a5e0
uint32_t View_0079a5e0_shaped08_game::GetHighlightedItem()
{
    int32_t i = mnHighlighted;
    if (i >= 0 && i < mnCount) {
        return mpItems[i];
    }
    return 0;
}

// FUNCTION: 0x0079a600
uint32_t View_0079a5e0_shaped08_game::GetSelectedItem()
{
    int32_t i = mnSelected;
    if (i >= 0 && i < mnCount) {
        return mpItems[i];
    }
    return 0;
}

struct Source_007e3b10_shaped08_game {
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
    virtual uint32_t Slot0A();
};

struct Sink_007e3b10_shaped08_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Slot04(uint32_t a, uint32_t b);
    virtual void Slot05(uint32_t a, uint32_t b);
};

struct Sink_007e3be0_shaped08_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Slot03(uint32_t a, uint32_t b);
};

struct View_007e3b10_shaped08_game : Sink_007e3b10_shaped08_game {
    void Fn007e3b10(uint32_t a, Source_007e3b10_shaped08_game* pSource);
};

// FUNCTION: 0x007e3b10
void View_007e3b10_shaped08_game::Fn007e3b10(uint32_t a, Source_007e3b10_shaped08_game* pSource)
{
    Slot05(a, pSource->Slot0A());
}

struct View_007e3be0_shaped08_game : Sink_007e3be0_shaped08_game {
    void Fn007e3be0(uint32_t a, Source_007e3b10_shaped08_game* pSource);
};

// FUNCTION: 0x007e3be0
void View_007e3be0_shaped08_game::Fn007e3be0(uint32_t a, Source_007e3b10_shaped08_game* pSource)
{
    Slot03(a, pSource->Slot0A());
}

struct Sub_00811f00_shaped08_game {
    virtual void Pad00();
    virtual bool Slot01();
    virtual void Pad02();
    virtual void Slot03();
};

struct View_00811f00_shaped08_game {
    uint8_t pad[0xf0];
    Sub_00811f00_shaped08_game mSub;
    bool Fn00811f00();
};

// FUNCTION: 0x00811f00
bool View_00811f00_shaped08_game::Fn00811f00()
{
    if (mSub.Slot01()) {
        mSub.Slot03();
    }
    return true;
}

struct View_00811f90_shaped08_game {
    uint8_t pad[0x150];
    Sub_00811f00_shaped08_game mSub;
    bool Fn00811f90();
};

// FUNCTION: 0x00811f90
bool View_00811f90_shaped08_game::Fn00811f90()
{
    if (mSub.Slot01()) {
        mSub.Slot03();
    }
    return true;
}

struct Base_0090d957_shaped08_game {
    uint32_t mnVtable;
    uint32_t mnField;
    // STUB: 0x0090d957
    Base_0090d957_shaped08_game* Fn0090d957();
};

struct View_007a7900_shaped08_game {
    uint32_t mnVtable;
    Base_0090d957_shaped08_game mBase;
    View_007a7900_shaped08_game* Fn007a7900();
};

// FUNCTION: 0x007a7900
View_007a7900_shaped08_game* View_007a7900_shaped08_game::Fn007a7900()
{
    mnVtable = 0xa93628;
    mBase.Fn0090d957();
    mBase.mnVtable = 0xab8358;
    mnVtable = 0xab8340;
    return this;
}

struct View_00991e50_shaped08_game {
    uint32_t mnVtable;
    Base_0090d957_shaped08_game mBase;
    View_00991e50_shaped08_game* Fn00991e50();
};

// FUNCTION: 0x00991e50
View_00991e50_shaped08_game* View_00991e50_shaped08_game::Fn00991e50()
{
    mnVtable = 0xac161c;
    mBase.Fn0090d957();
    mBase.mnVtable = 0xadb4ec;
    mnVtable = 0xadb4dc;
    return this;
}

struct View_007fb680_shaped08_game {
    uint8_t pad[0x34];
    uint8_t mnVersion;
    uint8_t mFlags;
    uint8_t pad36[0x5c - 0x36];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    void SetFlag(uint32_t f) { mFlags = static_cast<uint8_t>(mFlags | f); }
    void Fn007fb680(const Vec3_shaped08_game* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007fb680 score 9
void View_007fb680_shaped08_game::Fn007fb680(const Vec3_shaped08_game* p)
{
    mX = p->x;
    mY = p->y;
    mZ = p->z;
    SetFlag(1);
    mnVersion++;
}
#endif

struct View_007fc480_shaped08_game {
    uint8_t pad[0x38];
    uint8_t mnVersion;
    uint8_t mFlags;
    uint8_t pad3a[0x60 - 0x3a];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    void SetFlag(uint32_t f) { mFlags = static_cast<uint8_t>(mFlags | f); }
    void Fn007fc480(const Vec3_shaped08_game* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007fc480 score 9
void View_007fc480_shaped08_game::Fn007fc480(const Vec3_shaped08_game* p)
{
    mX = p->x;
    mY = p->y;
    mZ = p->z;
    SetFlag(1);
    mnVersion++;
}
#endif

struct Rec_00801e10_shaped08_game {
    uint8_t mA;
    uint8_t mB;
    uint16_t mC;
    uint32_t mD;
    uint32_t mE;
    uint32_t mF;
    uint32_t mG;
};

struct View_00801e10_shaped08_game {
    uint8_t pad[0x18];
    Rec_00801e10_shaped08_game* RecOf() { return reinterpret_cast<Rec_00801e10_shaped08_game*>(reinterpret_cast<uint8_t*>(this) - 0x18); }
    void Fn00801e10(Rec_00801e10_shaped08_game* pOut);
    void Fn00801e50(const Rec_00801e10_shaped08_game* pIn);
};

// FUNCTION: 0x00801e10
void View_00801e10_shaped08_game::Fn00801e10(Rec_00801e10_shaped08_game* pOut)
{
    Rec_00801e10_shaped08_game* r = RecOf();
    pOut->mA = r->mA;
    pOut->mB = r->mB;
    pOut->mC = r->mC;
    pOut->mD = r->mD;
    pOut->mE = r->mE;
    pOut->mF = r->mF;
    pOut->mG = r->mG;
}

// FUNCTION: 0x00801e50
void View_00801e10_shaped08_game::Fn00801e50(const Rec_00801e10_shaped08_game* pIn)
{
    Rec_00801e10_shaped08_game* r = RecOf();
    r->mA = pIn->mA;
    r->mB = pIn->mB;
    r->mC = pIn->mC;
    r->mD = pIn->mD;
    r->mE = pIn->mE;
    r->mF = pIn->mF;
    r->mG = pIn->mG;
}

struct View_00801f00_shaped08_game {
    uint8_t RecPad() { return 0; }
    Rec_00801e10_shaped08_game* RecOf() { return reinterpret_cast<Rec_00801e10_shaped08_game*>(reinterpret_cast<uint8_t*>(this) - 0x24); }
    void Fn00801f00(Rec_00801e10_shaped08_game* pOut);
    void Fn00801f40(const Rec_00801e10_shaped08_game* pIn);
};

// FUNCTION: 0x00801f00
void View_00801f00_shaped08_game::Fn00801f00(Rec_00801e10_shaped08_game* pOut)
{
    Rec_00801e10_shaped08_game* r = RecOf();
    pOut->mA = r->mA;
    pOut->mB = r->mB;
    pOut->mC = r->mC;
    pOut->mD = r->mD;
    pOut->mE = r->mE;
    pOut->mF = r->mF;
    pOut->mG = r->mG;
}

// FUNCTION: 0x00801f40
void View_00801f00_shaped08_game::Fn00801f40(const Rec_00801e10_shaped08_game* pIn)
{
    Rec_00801e10_shaped08_game* r = RecOf();
    r->mA = pIn->mA;
    r->mB = pIn->mB;
    r->mC = pIn->mC;
    r->mD = pIn->mD;
    r->mE = pIn->mE;
    r->mF = pIn->mF;
    r->mG = pIn->mG;
}

struct View_007fb410_shaped08_game {
    uint8_t pad[0x20];
    uint8_t mFlags;
    uint32_t Fn007fb410(uint8_t on);
};

// FUNCTION: 0x007fb410
uint32_t View_007fb410_shaped08_game::Fn007fb410(uint8_t on)
{
    uint8_t cur = static_cast<uint8_t>((mFlags >> 2) & 1);
    if (on != cur) {
        if (on) {
            mFlags |= 4;
        } else {
            mFlags &= 0xfb;
        }
        return 2;
    }
    return 0;
}

struct View_007fb0c0_shaped08_game {
    uint8_t pad[0x84];
    uint8_t mFlags;
    uint32_t Fn007fb0c0(uint8_t on);
};

// FUNCTION: 0x007fb0c0
uint32_t View_007fb0c0_shaped08_game::Fn007fb0c0(uint8_t on)
{
    uint8_t cur = static_cast<uint8_t>((mFlags >> 2) & 1);
    if (on != cur) {
        if (on) {
            mFlags |= 4;
        } else {
            mFlags &= 0xfb;
        }
        return 2;
    }
    return 0;
}

struct Rel_0080c190_shaped08_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
};

struct View_0080c190_shaped08_game {
    uint8_t pad[0xa0];
    Rel_0080c190_shaped08_game* mpB;
    Rel_0080c190_shaped08_game* mpA;
    // STUB: 0x0080c9d0
    bool Fn0080c9d0();
    bool Fn0080c190();
};

// FUNCTION: 0x0080c190
bool View_0080c190_shaped08_game::Fn0080c190()
{
    if (mpA) {
        Rel_0080c190_shaped08_game* p = mpA;
        mpA = 0;
        p->Release();
    }
    if (mpB) {
        Rel_0080c190_shaped08_game* p = mpB;
        mpB = 0;
        p->Release();
    }
    return Fn0080c9d0();
}

struct View_0080eba0_shaped08_game {
    uint8_t pad[0xa0];
    Rel_0080c190_shaped08_game* mpA;
    Rel_0080c190_shaped08_game* mpB;
    // STUB: 0x0080c9d0
    bool Fn0080c9d0();
    bool Fn0080eba0();
};

// FUNCTION: 0x0080eba0
bool View_0080eba0_shaped08_game::Fn0080eba0()
{
    if (mpA) {
        Rel_0080c190_shaped08_game* p = mpA;
        mpA = 0;
        p->Release();
    }
    if (mpB) {
        Rel_0080c190_shaped08_game* p = mpB;
        mpB = 0;
        p->Release();
    }
    return Fn0080c9d0();
}

struct View_00821630_shaped08_game {
    uint32_t mnVtable;
    uint8_t pad4[0x34 - 4];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    uint8_t pad40[0x5c - 0x40];
    uint32_t mnD;
    // STUB: 0x008201e0
    void Fn008201e0();
    View_00821630_shaped08_game* Fn00821630();
};

// FUNCTION: 0x00821630
View_00821630_shaped08_game* View_00821630_shaped08_game::Fn00821630()
{
    Fn008201e0();
    mnD = 0;
    mnC = 0;
    mnVtable = 0xac1068;
    mnA = 2;
    mnB = 1;
    return this;
}

struct View_0079c6a0_shaped08_game {
    uint32_t mnVtable;
    uint32_t mnVtable4;
    uint8_t pad8[0xdc - 8];
    uint32_t mnVtableDc;
    uint8_t padE0[0x154 - 0xe0];
    uint32_t mnA;
    uint32_t mnB;
    // STUB: 0x00994d12
    void Fn00994d12();
    View_0079c6a0_shaped08_game* Fn0079c6a0();
};

// FUNCTION: 0x0079c6a0
View_0079c6a0_shaped08_game* View_0079c6a0_shaped08_game::Fn0079c6a0()
{
    Fn00994d12();
    mnA = 0;
    mnB = 0;
    mnVtable = 0xab78a0;
    mnVtable4 = 0xab7640;
    mnVtableDc = 0xab75c0;
    return this;
}

struct Obj_0080c2c0_shaped08_game {
    uint32_t w[0xa8 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080c2c0
Obj_0080c2c0_shaped08_game* Fn0080c2c0()
{
    void* p = ::operator new(0xa8);
    if (p) {
        Obj_0080c2c0_shaped08_game* o = static_cast<Obj_0080c2c0_shaped08_game*>(p);
        o->Ctor();
        o->w[0] = 0xabdf78;
        o->w[1] = 0xabdf5c;
        o->w[2] = 0xabdef8;
        o->w[7] = 0xabdee0;
        o->w[0xa0 / 4] = 0;
        o->w[0xa4 / 4] = 0;
        return o;
    }
    return 0;
}

struct Obj_0080ed10_shaped08_game {
    uint32_t w[0xa8 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080ed10
Obj_0080ed10_shaped08_game* Fn0080ed10()
{
    void* p = ::operator new(0xa8);
    if (p) {
        Obj_0080ed10_shaped08_game* o = static_cast<Obj_0080ed10_shaped08_game*>(p);
        o->Ctor();
        o->w[0] = 0xabee08;
        o->w[1] = 0xabedec;
        o->w[2] = 0xabed88;
        o->w[7] = 0xabed70;
        o->w[0xa0 / 4] = 0;
        o->w[0xa4 / 4] = 0;
        return o;
    }
    return 0;
}

struct Tmp_00811e10_shaped08_game {
    uint32_t w[4];
    // STUB: 0x0081e7d0
    Tmp_00811e10_shaped08_game* Fn0081e7d0(uint32_t a, uint32_t b);
};

struct Sub_00811e10_shaped08_game {
    virtual void Pad00();
    virtual bool Slot01();
    virtual void Pad02();
    virtual void Slot03();
    virtual void Pad04();
    virtual bool Slot05();
    virtual void Pad06();
    virtual bool Slot07(const Tmp_00811e10_shaped08_game* pTmp);
};

struct View_00811e10_shaped08_game {
    uint8_t pad[0x90];
    Sub_00811e10_shaped08_game mSub;
    bool Fn00811e10();
};

// FUNCTION: 0x00811e10
bool View_00811e10_shaped08_game::Fn00811e10()
{
    if (mSub.Slot01()) {
        return true;
    }
    if (mSub.Slot05()) {
        Tmp_00811e10_shaped08_game t;
        if (mSub.Slot07(t.Fn0081e7d0(0, 0))) {
            return true;
        }
        mSub.Slot03();
    }
    return false;
}

struct View_00811f30_shaped08_game {
    uint8_t pad[0x150];
    Sub_00811e10_shaped08_game mSub;
    bool Fn00811f30();
};

// FUNCTION: 0x00811f30
bool View_00811f30_shaped08_game::Fn00811f30()
{
    if (mSub.Slot01()) {
        return true;
    }
    if (mSub.Slot05()) {
        Tmp_00811e10_shaped08_game t;
        if (mSub.Slot07(t.Fn0081e7d0(0, 0))) {
            return true;
        }
        mSub.Slot03();
    }
    return false;
}

struct NetObj_0079e980_shaped08_game {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};

struct NetMgr_0079e980_shaped08_game {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void P05();
    virtual void P06();
    virtual void P07();
    virtual void P08();
    virtual void P09();
    virtual void P0A();
    virtual void P0B();
    virtual void P0C();
    virtual void P0D();
    virtual void P0E();
    virtual void P0F();
    virtual void P10();
    virtual void P11();
    virtual NetObj_0079e980_shaped08_game* Slot12();
    virtual NetObj_0079e980_shaped08_game* Slot13();
};

// STUB: 0x00602680
NetMgr_0079e980_shaped08_game* Fn00602680_shaped08_game();

struct View_0079e980_shaped08_game {
    uint8_t pad[0x24];
    NetObj_0079e980_shaped08_game* mpA;
    NetObj_0079e980_shaped08_game* mpB;
    void Fn0079e980(bool on);
    void Fn0079e9e0(bool on);
};

// FUNCTION: 0x0079e980
void View_0079e980_shaped08_game::Fn0079e980(bool on)
{
    if (!on) {
        if (mpA) {
            NetObj_0079e980_shaped08_game* p = mpA;
            mpA = 0;
            p->Release();
        }
        return;
    }
    NetObj_0079e980_shaped08_game* pNew = Fn00602680_shaped08_game()->Slot12();
    NetObj_0079e980_shaped08_game* pOld = mpA;
    if (pNew != pOld) {
        if (pNew) {
            pNew->AddRef();
        }
        mpA = pNew;
        if (pOld) {
            pOld->Release();
        }
    }
}

// FUNCTION: 0x0079e9e0
void View_0079e980_shaped08_game::Fn0079e9e0(bool on)
{
    if (!on) {
        if (mpB) {
            NetObj_0079e980_shaped08_game* p = mpB;
            mpB = 0;
            p->Release();
        }
        return;
    }
    NetObj_0079e980_shaped08_game* pNew = Fn00602680_shaped08_game()->Slot13();
    NetObj_0079e980_shaped08_game* pOld = mpB;
    if (pNew != pOld) {
        if (pNew) {
            pNew->AddRef();
        }
        mpB = pNew;
        if (pOld) {
            pOld->Release();
        }
    }
}

struct Dev_007d3e90_shaped08_game {
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
    virtual void Pad0A();
    virtual void Pad0B();
    virtual void Pad0C();
    virtual void Pad0D();
    virtual void Pad0E();
    virtual void Pad0F();
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
    virtual void Pad1A();
    virtual void Pad1B();
    virtual void Pad1C();
    virtual void Pad1D();
    virtual void Pad1E();
    virtual void Pad1F();
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
    virtual void Pad2A();
    virtual void Pad2B();
    virtual void Slot2C(uint32_t v);
    virtual void Slot2D(uint32_t v);
};

struct Inner_007d3e90_shaped08_game {
    uint8_t pad[0x11c];
    uint8_t mbDisabled;
};

struct Holder_007d3e90_shaped08_game {
    uint32_t pad0;
    uint32_t pad4;
    uint32_t pad8;
    Inner_007d3e90_shaped08_game* mpInner;
};

struct View_007d3e90_shaped08_game {
    uint8_t pad[0x30];
    Dev_007d3e90_shaped08_game* mpDev;
    uint32_t pad34;
    Holder_007d3e90_shaped08_game* mpHolder;
    uint8_t pad3c[0x80 - 0x3c];
    uint32_t mnFlags;
    void EnableAlphaTestFlag(bool on);
};

// FUNCTION: 0x007d3e90
void View_007d3e90_shaped08_game::EnableAlphaTestFlag(bool on)
{
    if (on && !mpHolder->mpInner->mbDisabled) {
        if (!(mnFlags & 8)) {
            mpDev->Slot2C(0);
            mnFlags |= 8;
        }
    } else if (mnFlags & 8) {
        mpDev->Slot2D(0);
        mnFlags &= ~8u;
    }
}

struct Inner_007d4010_shaped08_game {
    uint8_t pad[0xfc];
    uint8_t mbDisabled;
};

struct Holder_007d4010_shaped08_game {
    uint32_t pad0;
    uint32_t pad4;
    uint32_t pad8;
    Inner_007d4010_shaped08_game* mpInner;
};

struct View_007d4010_shaped08_game {
    uint8_t pad[0x30];
    Dev_007d3e90_shaped08_game* mpDev;
    uint32_t pad34;
    Holder_007d4010_shaped08_game* mpHolder;
    uint8_t pad3c[0x80 - 0x3c];
    uint32_t mnFlags;
    void EnableBlendStateFlag(bool on);
};

// FUNCTION: 0x007d4010
void View_007d4010_shaped08_game::EnableBlendStateFlag(bool on)
{
    if (on && !mpHolder->mpInner->mbDisabled) {
        if (!(mnFlags & 0x10)) {
            mpDev->Slot2C(4);
            mnFlags |= 0x10;
        }
    } else if (mnFlags & 0x10) {
        mpDev->Slot2D(4);
        mnFlags &= ~0x10u;
    }
}

struct View_007fbfc0_shaped08_game {
    uint8_t pad[0x38];
    float m[9];
    void Fn007fbfc0(float* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007fbfc0 score 18
void View_007fbfc0_shaped08_game::Fn007fbfc0(float* v)
{
    float r[3];
    r[0] = m[1] * v[1] + m[2] * v[2] + m[0] * v[0];
    r[1] = m[4] * v[1] + m[5] * v[2] + m[3] * v[0];
    r[2] = m[7] * v[1] + m[8] * v[2] + v[0] * m[6];
    v[0] = r[0];
    v[1] = r[1];
    v[2] = r[2];
}
#endif

struct View_007fcdc0_shaped08_game {
    uint8_t pad[0x3c];
    float m[9];
    void Fn007fcdc0(float* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007fcdc0 score 18
void View_007fcdc0_shaped08_game::Fn007fcdc0(float* v)
{
    float r[3];
    r[0] = m[1] * v[1] + m[2] * v[2] + m[0] * v[0];
    r[1] = m[4] * v[1] + m[5] * v[2] + m[3] * v[0];
    r[2] = m[7] * v[1] + m[8] * v[2] + v[0] * m[6];
    v[0] = r[0];
    v[1] = r[1];
    v[2] = r[2];
}
#endif

struct Str_00813c50_shaped08_game {
    union {
        uint16_t* mpStart;
        char* mpBegin;
    };
    union {
        uint16_t* mpFinish;
        char* mpEnd;
    };
    uint32_t pad8;
    uint32_t Size() const { return static_cast<uint32_t>(mpEnd - mpBegin); }
    char At(uint32_t i) const { return mpBegin[i]; }
    // STUB: 0x00408a70
    Str_00813c50_shaped08_game& AssignDispatch(uint16_t* pFirst, uint16_t* pLast, const void* pTag);
    // STUB: 0x00417a70
    void PushBack(char c);
};

struct StrHolder_00813c50_shaped08_game {
    uint32_t pad0;
    Str_00813c50_shaped08_game mStr;
};

struct View_00813c50_shaped08_game {
    uint8_t pad[0x20];
    Str_00813c50_shaped08_game mStr;
    void Fn00813c50(StrHolder_00813c50_shaped08_game* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00813c50 score 41
void View_00813c50_shaped08_game::Fn00813c50(StrHolder_00813c50_shaped08_game* pOther)
{
    Str_00813c50_shaped08_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
    if (mStr.Size() != 0) {
        char last = mStr.At(mStr.Size() - 1);
        if (last != '\\' && last != '/') {
            mStr.PushBack('\\');
        }
    }
}
#endif

struct View_00819650_shaped08_game {
    uint8_t pad[0x44];
    Str_00813c50_shaped08_game mStr;
    void Fn00819650(StrHolder_00813c50_shaped08_game* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00819650 score 41
void View_00819650_shaped08_game::Fn00819650(StrHolder_00813c50_shaped08_game* pOther)
{
    Str_00813c50_shaped08_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
    if (mStr.Size() != 0) {
        char last = mStr.At(mStr.Size() - 1);
        if (last != '\\' && last != '/') {
            mStr.PushBack('\\');
        }
    }
}
#endif

struct Obj_00798380_shaped08_game {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};

struct Factory_00798380_shaped08_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Obj_00798380_shaped08_game* Slot05(uint32_t style);
};

// STUB: 0x00913c72
Factory_00798380_shaped08_game* Fn00913c72_shaped08_game();

struct Sub_00798380_shaped08_game {
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
    virtual void Pad0A();
    virtual void Pad0B();
    virtual void Pad0C();
    virtual void Pad0D();
    virtual void Pad0E();
    virtual void Pad0F();
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
    virtual void Pad1A();
    virtual void Pad1B();
    virtual void Pad1C();
    virtual void Pad1D();
    virtual void Pad1E();
    virtual void Pad1F();
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
    virtual void Pad2A();
    virtual void Pad2B();
    virtual void Pad2C();
    virtual void Pad2D();
    virtual void Pad2E();
    virtual void Pad2F();
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
    virtual void Pad3A();
    virtual void Pad3B();
    virtual void Pad3C();
    virtual void Pad3D();
    virtual void Pad3E();
    virtual void Pad3F();
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
    virtual void Pad4A();
    virtual void Pad4B();
    virtual void Pad4C();
    virtual void Pad4D();
    virtual void Pad4E();
    virtual void Pad4F();
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
    virtual void Pad5A();
    virtual void Pad5B();
    virtual void Slot5C();
};

struct View_00798380_shaped08_game {
    uint32_t pad0;
    Sub_00798380_shaped08_game mSub;
    uint8_t pad8[0x12c - 8];
    uint32_t mnFlags;
    uint8_t pad130[0x138 - 0x130];
    Obj_00798380_shaped08_game* mpTitle;
    Obj_00798380_shaped08_game* mpText;
    void Fn00798380(uint32_t style);
    void Fn007983e0(uint32_t style);
};

// FUNCTION: 0x00798380
void View_00798380_shaped08_game::Fn00798380(uint32_t style)
{
    Obj_00798380_shaped08_game* pNew = Fn00913c72_shaped08_game()->Slot05(style);
    Obj_00798380_shaped08_game* pOld = mpTitle;
    if (pNew != pOld) {
        if (pNew) {
            pNew->AddRef();
        }
        mpTitle = pNew;
        if (pOld) {
            pOld->Release();
        }
    }
    mnFlags |= 1;
    mSub.Slot5C();
}

// FUNCTION: 0x007983e0
void View_00798380_shaped08_game::Fn007983e0(uint32_t style)
{
    Obj_00798380_shaped08_game* pNew = Fn00913c72_shaped08_game()->Slot05(style);
    Obj_00798380_shaped08_game* pOld = mpText;
    if (pNew != pOld) {
        if (pNew) {
            pNew->AddRef();
        }
        mpText = pNew;
        if (pOld) {
            pOld->Release();
        }
    }
    mnFlags |= 1;
    mSub.Slot5C();
}

struct Node_0080dae0_shaped08_game;

struct Item_0080dae0_shaped08_game {
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
    virtual void Pad0A();
    virtual void Pad0B();
    virtual void Pad0C();
    virtual void Pad0D();
    virtual void Pad0E();
    virtual void Pad0F();
    virtual void Pad10();
    virtual bool Slot11();
    virtual bool Slot12();
};

struct Node_0080dae0_shaped08_game {
    uint32_t mnColor;
    Node_0080dae0_shaped08_game* mpParent;
    Node_0080dae0_shaped08_game* mpLeft;
    Node_0080dae0_shaped08_game* mpRight;
    uint32_t mnKey;
    Item_0080dae0_shaped08_game* mpValue;
};

inline Node_0080dae0_shaped08_game* NextNode_0080dae0(Node_0080dae0_shaped08_game* pNode)
{
    if (pNode->mpRight) {
        pNode = pNode->mpRight;
        while (pNode->mpLeft) {
            pNode = pNode->mpLeft;
        }
    } else {
        Node_0080dae0_shaped08_game* pUp = pNode->mpParent;
        while (pNode == pUp->mpRight) {
            pNode = pUp;
            pUp = pUp->mpParent;
        }
        if (pNode->mpRight != pUp) {
            pNode = pUp;
        }
    }
    return pNode;
}

struct View_0080dae0_shaped08_game {
    uint8_t pad[0x30];
    Node_0080dae0_shaped08_game* mpHeader;
    uint32_t Fn0080dae0();
    uint32_t Fn0080dbe0();
};

// FUNCTION: 0x0080dae0
uint32_t View_0080dae0_shaped08_game::Fn0080dae0()
{
    Node_0080dae0_shaped08_game* pEnd = mpHeader;
    Node_0080dae0_shaped08_game* pNode = pEnd->mpLeft;
    uint32_t n = 0;
    while (pNode != pEnd) {
        if (pNode->mpValue->Slot11()) {
            n++;
        }
        pNode = NextNode_0080dae0(pNode);
    }
    return n;
}

// FUNCTION: 0x0080dbe0
uint32_t View_0080dae0_shaped08_game::Fn0080dbe0()
{
    Node_0080dae0_shaped08_game* pEnd = mpHeader;
    Node_0080dae0_shaped08_game* pNode = pEnd->mpLeft;
    uint32_t n = 0;
    while (pNode != pEnd) {
        if (pNode->mpValue->Slot12()) {
            n++;
        }
        pNode = NextNode_0080dae0(pNode);
    }
    return n;
}

struct Rect_00798630_shaped08_game {
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
};

struct Sub_00798630_shaped08_game {
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
    virtual void Pad0A();
    virtual void Pad0B();
    virtual void Pad0C();
    virtual void Pad0D();
    virtual void Pad0E();
    virtual void Pad0F();
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
    virtual void Pad1A();
    virtual void Pad1B();
    virtual void Pad1C();
    virtual void Pad1D();
    virtual void Pad1E();
    virtual void Pad1F();
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
    virtual void Pad2A();
    virtual void Pad2B();
    virtual void Pad2C();
    virtual void Pad2D();
    virtual void Pad2E();
    virtual void Pad2F();
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
    virtual void Pad3A();
    virtual void Pad3B();
    virtual void Pad3C();
    virtual void Pad3D();
    virtual void Pad3E();
    virtual void Pad3F();
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
    virtual void Pad4A();
    virtual void Pad4B();
    virtual void Pad4C();
    virtual void Pad4D();
    virtual void Pad4E();
    virtual void Pad4F();
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
    virtual void Pad5A();
    virtual void Pad5B();
    virtual void Slot5C();
};

struct View_00798630_shaped08_game {
    uint32_t pad0;
    Sub_00798630_shaped08_game mSub;
    uint8_t pad8[0x11c - 8];
    uint32_t mA;
    uint32_t mB;
    uint32_t mC;
    uint32_t mD;
    uint32_t mnFlags;
    void SetAvoidanceRect(const Rect_00798630_shaped08_game* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00798630 score 25
void View_00798630_shaped08_game::SetAvoidanceRect(const Rect_00798630_shaped08_game* p)
{
    if (mA != p->a || mB != p->b || mC != p->c || mD != p->d) {
        mA = p->a;
        mB = p->b;
        mC = p->c;
        mD = p->d;
        mnFlags |= 2;
        mSub.Slot5C();
    }
}
#endif

struct View_007986a0_shaped08_game {
    uint32_t pad0;
    Sub_00798630_shaped08_game mSub;
    uint8_t pad8[0xdc - 8];
    uint32_t mA;
    uint32_t mB;
    uint32_t mC;
    uint32_t mD;
    uint8_t padec[0x12c - 0xec];
    uint32_t mnFlags;
    void Fn007986a0(const Rect_00798630_shaped08_game* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007986a0 score 25
void View_007986a0_shaped08_game::Fn007986a0(const Rect_00798630_shaped08_game* p)
{
    if (mA != p->a || mB != p->b || mC != p->c || mD != p->d) {
        mA = p->a;
        mB = p->b;
        mC = p->c;
        mD = p->d;
        mnFlags |= 2;
        mSub.Slot5C();
    }
}
#endif

// STUB: 0x0090cf54
void* Fn0090cf54_shaped08_game(uint32_t size);

struct Buf_00812840_shaped08_game {
    uint32_t mnTag;
    char* mpBegin;
    char* mpEnd;
    char* mpCap;
    uint32_t mnFlag;
    Buf_00812840_shaped08_game()
    {
        mpBegin = 0;
        mpEnd = 0;
        mpCap = 0;
        char* p = static_cast<char*>(Fn0090cf54_shaped08_game(8));
        mpBegin = p;
        mpEnd = p;
        mpCap = p + 8;
        *p = 0;
        mnTag = 0xa80810;
        mnFlag = 0;
    }
};

struct View_00812840_shaped08_game {
    uint8_t pad[8];
    Buf_00812840_shaped08_game mA;
    Buf_00812840_shaped08_game mB;
    View_00812840_shaped08_game();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00812840 score 6
View_00812840_shaped08_game::View_00812840_shaped08_game()
{
}
#endif

struct View_008b5e70_shaped08_game {
    uint32_t pad0;
    Buf_00812840_shaped08_game mA;
    Buf_00812840_shaped08_game mB;
    View_008b5e70_shaped08_game();
};

#ifdef OB_DRAFTS
// CLOSE: 0x008b5e70 score 6
View_008b5e70_shaped08_game::View_008b5e70_shaped08_game()
{
}
#endif

struct View_007fc020_shaped08_game {
    uint8_t pad[0x38];
    float m[9];
    void Fn007fc020(float* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007fc020 score 38
void View_007fc020_shaped08_game::Fn007fc020(float* v)
{
    float x = v[0];
    float t[3];
    t[1] = v[1];
    t[2] = v[2];
    v[0] = t[2] * m[2] + t[1] * m[1] + x * m[0];
    v[1] = t[2] * m[5] + t[1] * m[4] + x * m[3];
    v[2] = t[2] * m[8] + t[1] * m[7] + x * m[6];
}
#endif

struct View_007fce20_shaped08_game {
    uint8_t pad[0x3c];
    float m[9];
    void Fn007fce20(float* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007fce20 score 38
void View_007fce20_shaped08_game::Fn007fce20(float* v)
{
    float x = v[0];
    float t[3];
    t[1] = v[1];
    t[2] = v[2];
    v[0] = t[2] * m[2] + t[1] * m[1] + x * m[0];
    v[1] = t[2] * m[5] + t[1] * m[4] + x * m[3];
    v[2] = t[2] * m[8] + t[1] * m[7] + x * m[6];
}
#endif

// STUB: 0x0090cf54
void* Fn0090cf54_shaped08_game(uint32_t size);

struct Elem_007a1310_shaped08_game {
    uint32_t a;
    uint32_t b;
    uint32_t c;
    // STUB: 0x00459e80
    Elem_007a1310_shaped08_game(const Elem_007a1310_shaped08_game& o);
    Elem_007a1310_shaped08_game(uint32_t x, uint32_t y, uint32_t z) : a(x), b(y), c(z) {}
};

struct Vec_007a1310_shaped08_game {
    Elem_007a1310_shaped08_game* mpBegin;
    Elem_007a1310_shaped08_game* mpEnd;
    Elem_007a1310_shaped08_game* mpCap;
    Vec_007a1310_shaped08_game* Fn007a1310(uint32_t n);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007a1310 score 2
Vec_007a1310_shaped08_game* Vec_007a1310_shaped08_game::Fn007a1310(uint32_t n)
{
    mpBegin = 0;
    mpEnd = 0;
    mpCap = 0;
    Elem_007a1310_shaped08_game* pBase = n ? static_cast<Elem_007a1310_shaped08_game*>(Fn0090cf54_shaped08_game(n * 12)) : 0;
    mpBegin = pBase;
    mpEnd = pBase;
    mpCap = pBase + n;
    Elem_007a1310_shaped08_game init(0, 0, 0);
    Elem_007a1310_shaped08_game* p = pBase;
    for (; n > 0; --n) {
        if (p) {
            new (p) Elem_007a1310_shaped08_game(init);
        }
        ++p;
    }
    mpEnd = p;
    return this;
}
#endif

struct Elem_007c0e70_shaped08_game {
    uint32_t a;
    uint32_t b;
    uint32_t c;
    // STUB: 0x00462f00
    Elem_007c0e70_shaped08_game(const Elem_007c0e70_shaped08_game& o);
    Elem_007c0e70_shaped08_game(uint32_t x, uint32_t y, uint32_t z) : a(x), b(y), c(z) {}
};

struct Vec_007c0e70_shaped08_game {
    Elem_007c0e70_shaped08_game* mpBegin;
    Elem_007c0e70_shaped08_game* mpEnd;
    Elem_007c0e70_shaped08_game* mpCap;
    Vec_007c0e70_shaped08_game* Fn007c0e70(uint32_t n);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c0e70 score 2
Vec_007c0e70_shaped08_game* Vec_007c0e70_shaped08_game::Fn007c0e70(uint32_t n)
{
    mpBegin = 0;
    mpEnd = 0;
    mpCap = 0;
    Elem_007c0e70_shaped08_game* pBase = n ? static_cast<Elem_007c0e70_shaped08_game*>(Fn0090cf54_shaped08_game(n * 12)) : 0;
    mpBegin = pBase;
    mpEnd = pBase;
    mpCap = pBase + n;
    Elem_007c0e70_shaped08_game init(0, 0, 0);
    Elem_007c0e70_shaped08_game* p = pBase;
    for (; n > 0; --n) {
        if (p) {
            new (p) Elem_007c0e70_shaped08_game(init);
        }
        ++p;
    }
    mpEnd = p;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008287b0 score 65
void Fn008287b0(uint32_t width, uint32_t height, uint16_t* pDst, uint32_t dstPitch, uint32_t /*a5*/, uint32_t /*a6*/, uint32_t /*a7*/, uint32_t /*a8*/, const uint8_t* pSrc, uint32_t srcPitch)
{
    do {
        const uint16_t* s = reinterpret_cast<const uint16_t*>(pSrc);
        uint16_t* d = pDst;
        uint32_t i = width;
        do {
            uint32_t v = *s++;
            uint32_t r = (v >> 3) & 0xf00;
            uint32_t g = (v >> 2) & 0xf0;
            uint32_t b = (v >> 1) & 0xf;
            r &= 0xf00;
            g &= 0xf0;
            b &= 0xf;
            *d++ = static_cast<uint16_t>(r + g + b - 0x1000);
        } while (--i != 0);
        pDst = reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(pDst) + dstPitch);
        pSrc += srcPitch;
    } while (--height != 0);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008288e0 score 65
void Fn008288e0(uint32_t width, uint32_t height, uint16_t* pDst, uint32_t dstPitch, uint32_t /*a5*/, uint32_t /*a6*/, uint32_t /*a7*/, uint32_t /*a8*/, const uint8_t* pSrc, uint32_t srcPitch)
{
    do {
        const uint16_t* s = reinterpret_cast<const uint16_t*>(pSrc);
        uint16_t* d = pDst;
        uint32_t i = width;
        do {
            uint32_t v = *s++;
            uint32_t r = (v >> 4) & 0xf00;
            uint32_t g = (v >> 3) & 0xf0;
            uint32_t b = (v >> 1) & 0xf;
            r &= 0xf00;
            g &= 0xf0;
            b &= 0xf;
            *d++ = static_cast<uint16_t>(r + g + b - 0x1000);
        } while (--i != 0);
        pDst = reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(pDst) + dstPitch);
        pSrc += srcPitch;
    } while (--height != 0);
}
#endif

struct View_007fbf30_shaped08_game {
    uint8_t pad[0x38];
    float m[13];
    void Fn007fbf30(float* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007fbf30 score 57
void View_007fbf30_shaped08_game::Fn007fbf30(float* v)
{
    float x = v[0];
    float y = v[1];
    float z = v[2];
    float px = z * m[2] + y * m[1] + x * m[0];
    float py = z * m[5] + y * m[4] + x * m[3];
    float pz = z * m[8] + y * m[7] + x * m[6];
    float sc = m[12];
    float rx = px * sc;
    float ry = py * sc;
    float rz = pz * sc;
    v[0] = rx + m[9];
    v[1] = ry + m[10];
    v[2] = rz + m[11];
}
#endif

struct View_007fcd30_shaped08_game {
    uint8_t pad[0x3c];
    float m[13];
    void Fn007fcd30(float* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007fcd30 score 57
void View_007fcd30_shaped08_game::Fn007fcd30(float* v)
{
    float x = v[0];
    float y = v[1];
    float z = v[2];
    float px = z * m[2] + y * m[1] + x * m[0];
    float py = z * m[5] + y * m[4] + x * m[3];
    float pz = z * m[8] + y * m[7] + x * m[6];
    float sc = m[12];
    float rx = px * sc;
    float ry = py * sc;
    float rz = pz * sc;
    v[0] = rx + m[9];
    v[1] = ry + m[10];
    v[2] = rz + m[11];
}
#endif


struct Item_0080db40_shaped08_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual uint32_t Slot06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad0A();
    virtual void Pad0B();
    virtual void Pad0C();
    virtual void Pad0D();
    virtual void Pad0E();
    virtual void Pad0F();
    virtual void Pad10();
    virtual bool Slot11();
    virtual bool Slot12();
};

struct Node_0080db40_shaped08_game {
    uint32_t mnColor;
    Node_0080db40_shaped08_game* mpParent;
    Node_0080db40_shaped08_game* mpLeft;
    Node_0080db40_shaped08_game* mpRight;
    uint32_t mnKey;
    Item_0080db40_shaped08_game* mpValue;
};

inline Node_0080db40_shaped08_game* NextNode_0080db40(Node_0080db40_shaped08_game* pNode)
{
    if (pNode->mpRight) {
        pNode = pNode->mpRight;
        while (pNode->mpLeft) {
            pNode = pNode->mpLeft;
        }
    } else {
        Node_0080db40_shaped08_game* pUp = pNode->mpParent;
        while (pNode == pUp->mpRight) {
            pNode = pUp;
            pUp = pUp->mpParent;
        }
        if (pNode->mpRight != pUp) {
            pNode = pUp;
        }
    }
    return pNode;
}

struct View_0080db40_shaped08_game {
    uint8_t pad[0x30];
    Node_0080db40_shaped08_game* mpHeader;
    uint32_t Fn0080db40(uint32_t* pOut, uint32_t* pCap);
    uint32_t Fn0080dc40(uint32_t* pOut, uint32_t* pCap);
};

// FUNCTION: 0x0080db40
uint32_t View_0080db40_shaped08_game::Fn0080db40(uint32_t* pOut, uint32_t* pCap)
{
    Node_0080db40_shaped08_game* pEnd = mpHeader;
    Node_0080db40_shaped08_game* pNode = pEnd->mpLeft;
    uint32_t nMatch = 0;
    uint32_t nStored = 0;
    while (pNode != pEnd) {
        Item_0080db40_shaped08_game* pItem = pNode->mpValue;
        if (pItem->Slot11()) {
            nMatch++;
            if (nStored < *pCap) {
                pOut[nStored] = pItem->Slot06();
                nStored++;
            }
        }
        pNode = NextNode_0080db40(pNode);
    }
    *pCap = nStored;
    return nMatch;
}

// FUNCTION: 0x0080dc40
uint32_t View_0080db40_shaped08_game::Fn0080dc40(uint32_t* pOut, uint32_t* pCap)
{
    Node_0080db40_shaped08_game* pEnd = mpHeader;
    Node_0080db40_shaped08_game* pNode = pEnd->mpLeft;
    uint32_t nMatch = 0;
    uint32_t nStored = 0;
    while (pNode != pEnd) {
        Item_0080db40_shaped08_game* pItem = pNode->mpValue;
        if (pItem->Slot12()) {
            nMatch++;
            if (nStored < *pCap) {
                pOut[nStored] = pItem->Slot06();
                nStored++;
            }
        }
        pNode = NextNode_0080db40(pNode);
    }
    *pCap = nStored;
    return nMatch;
}

// STUB: 0x009afcfe
void Fn009afcfe_shaped08_game(void* pWin, uint32_t id, uint32_t a, uint32_t b);

struct Sub_0079df10_shaped08_game {
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
    virtual void Pad0A();
    virtual void* Slot0B();
};

struct View_0079df10_shaped08_game {
    uint32_t pad0;
    uint32_t pad4;
    Sub_0079df10_shaped08_game mSub;
    void Fn0079df10();
    void Fn0079dfb0();
};

// FUNCTION: 0x0079df10
void View_0079df10_shaped08_game::Fn0079df10()
{
    void* p = mSub.Slot0B();
    Fn009afcfe_shaped08_game(p, 0xaa32bcd5, 1, 0);
    Fn009afcfe_shaped08_game(p, 0x8a2871b2, 1, 0);
    Fn009afcfe_shaped08_game(p, 0x8a2871c3, 1, 0);
    Fn009afcfe_shaped08_game(p, 0x8a2871b1, 0, 0);
    Fn009afcfe_shaped08_game(p, 0xaa32bcd4, 0, 0);
    Fn009afcfe_shaped08_game(p, 0x8a2871c4, 0, 0);
    Fn009afcfe_shaped08_game(p, 0xcb72f247, 0, 0);
    Fn009afcfe_shaped08_game(p, 0x8100, 0, 0);
    Fn009afcfe_shaped08_game(p, 0x8101, 0, 0);
}

// FUNCTION: 0x0079dfb0
void View_0079df10_shaped08_game::Fn0079dfb0()
{
    void* p = mSub.Slot0B();
    Fn009afcfe_shaped08_game(p, 0xaa32bcd5, 1, 0);
    Fn009afcfe_shaped08_game(p, 0x8a2871b2, 1, 0);
    Fn009afcfe_shaped08_game(p, 0x8a2871c3, 1, 0);
    Fn009afcfe_shaped08_game(p, 0x8a2871b1, 0, 0);
    Fn009afcfe_shaped08_game(p, 0xaa32bcd4, 0, 0);
    Fn009afcfe_shaped08_game(p, 0x8a2871c4, 0, 0);
    Fn009afcfe_shaped08_game(p, 0xcb72f247, 1, 0);
    Fn009afcfe_shaped08_game(p, 0x8100, 1, 0);
    Fn009afcfe_shaped08_game(p, 0x8101, 1, 0);
}

struct Owner_00817560_shaped08_game;

struct Info_00817560_shaped08_game {
    Owner_00817560_shaped08_game* mpOwner;
};

struct Owner_00817560_shaped08_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    // STUB: 0x00816ee0
    uint32_t Work(Info_00817560_shaped08_game* pInfo);
};

// FUNCTION: 0x00817560
uint32_t OB_STDCALL Fn00817560(Info_00817560_shaped08_game* pInfo)
{
    Owner_00817560_shaped08_game* pOwner = pInfo->mpOwner;
    uint32_t r = pOwner->Work(pInfo);
    pOwner->Release();
    return r;
}

struct Owner_0081c9b0_shaped08_game;

struct Info_0081c9b0_shaped08_game {
    Owner_0081c9b0_shaped08_game* mpOwner;
};

struct Owner_0081c9b0_shaped08_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    // STUB: 0x0081ba80
    uint32_t Work(Info_0081c9b0_shaped08_game* pInfo);
};

// FUNCTION: 0x0081c9b0
uint32_t OB_STDCALL Fn0081c9b0(Info_0081c9b0_shaped08_game* pInfo)
{
    Owner_0081c9b0_shaped08_game* pOwner = pInfo->mpOwner;
    uint32_t r = pOwner->Work(pInfo);
    pOwner->Release();
    return r;
}

struct Blob13_0087c190_shaped08_game {
    uint32_t w[13];
};

struct View_0087c190_shaped08_game {
    uint8_t pad[0xc0];
    Blob13_0087c190_shaped08_game mBlob;
    void GetVideoModeInfo(Blob13_0087c190_shaped08_game* pOut);
};

// FUNCTION: 0x0087c190
void View_0087c190_shaped08_game::GetVideoModeInfo(Blob13_0087c190_shaped08_game* pOut)
{
    *pOut = mBlob;
}

struct Blob16_007d2730_shaped08_game {
    uint32_t w[16];
};

struct View_007d2730_shaped08_game {
    uint8_t pad[0x1ac];
    Blob16_007d2730_shaped08_game mBlob;
    void Fn007d2730(Blob16_007d2730_shaped08_game* pOut);
};

// FUNCTION: 0x007d2730
void View_007d2730_shaped08_game::Fn007d2730(Blob16_007d2730_shaped08_game* pOut)
{
    *pOut = mBlob;
}

struct Vec_007ceed0_shaped08_game {
    uint32_t w[3];
    // STUB: 0x007ced60
    Vec_007ceed0_shaped08_game(const Vec_007ceed0_shaped08_game& o);
    // STUB: 0x00611b00
    Vec_007ceed0_shaped08_game& operator=(const Vec_007ceed0_shaped08_game& o);
};

struct Head_007ceed0_shaped08_game {
    uint32_t w[3];
    // STUB: 0x007cece0
    Head_007ceed0_shaped08_game(const Head_007ceed0_shaped08_game& o);
    // STUB: 0x007cede0
    Head_007ceed0_shaped08_game& operator=(const Head_007ceed0_shaped08_game& o);
};

struct Rule_007ceed0_shaped08_game {
    Head_007ceed0_shaped08_game mHead;
    Vec_007ceed0_shaped08_game mA;
    Vec_007ceed0_shaped08_game mB;
    Rule_007ceed0_shaped08_game(const Rule_007ceed0_shaped08_game& o);
    Rule_007ceed0_shaped08_game& operator=(const Rule_007ceed0_shaped08_game& o);
};

// FUNCTION: 0x007ceed0
Rule_007ceed0_shaped08_game::Rule_007ceed0_shaped08_game(const Rule_007ceed0_shaped08_game& o)
    : mHead(o.mHead), mA(o.mA), mB(o.mB)
{
}

// FUNCTION: 0x007cf490
Rule_007ceed0_shaped08_game& Rule_007ceed0_shaped08_game::operator=(const Rule_007ceed0_shaped08_game& o)
{
    mHead = o.mHead;
    mA = o.mA;
    mB = o.mB;
    return *this;
}

struct Elem_007e3480_shaped08_game {
    uint32_t w[8];
};

struct Tag_007e3480_shaped08_game {
    uint32_t pad;
};

struct View_007e3480_shaped08_game {
    Elem_007e3480_shaped08_game* mpBegin;
    Elem_007e3480_shaped08_game* mpEnd;
    // STUB: 0x007dec40
    void Insert_007e3480(Elem_007e3480_shaped08_game* pAt, uint32_t n, uint32_t val);
    void Fn007e3480(uint32_t n, uint32_t val);
};

// STUB: 0x007de810
Elem_007e3480_shaped08_game* Fn007de810_shaped08_game(Elem_007e3480_shaped08_game* pA, Elem_007e3480_shaped08_game* pB, Elem_007e3480_shaped08_game* pC, uint32_t* pVal, uint32_t zero);

// STUB: 0x007de170
void Fn007de170_shaped08_game(Elem_007e3480_shaped08_game* pDst, Elem_007e3480_shaped08_game* pEnd, Tag_007e3480_shaped08_game* pTag);

#ifdef OB_DRAFTS
// CLOSE: 0x007e3480 score 4
void View_007e3480_shaped08_game::Fn007e3480(uint32_t n, uint32_t val)
{
    Elem_007e3480_shaped08_game* pEnd = mpEnd;
    Elem_007e3480_shaped08_game* pBegin = mpBegin;
    uint32_t size = static_cast<uint32_t>(pEnd - pBegin);
    if (n < size) {
        Tag_007e3480_shaped08_game tag;
        Elem_007e3480_shaped08_game* p = Fn007de810_shaped08_game(pEnd, pEnd, pBegin + n, &val, 0);
        Fn007de170_shaped08_game(p, mpEnd, &tag);
        mpEnd = p;
    } else {
        Insert_007e3480(pEnd, n - size, val);
    }
}
#endif

struct Elem_007d0fd0_shaped08_game {
    uint32_t w[4];
};

struct Tag_007d0fd0_shaped08_game {
    uint32_t pad;
};

struct View_007d0fd0_shaped08_game {
    Elem_007d0fd0_shaped08_game* mpBegin;
    Elem_007d0fd0_shaped08_game* mpEnd;
    // STUB: 0x007d0b40
    void Insert_007d0fd0(Elem_007d0fd0_shaped08_game* pAt, uint32_t n, uint32_t val);
    void Fn007d0fd0(uint32_t n, uint32_t val);
};

// STUB: 0x007d0750
Elem_007d0fd0_shaped08_game* Fn007d0750_shaped08_game(Elem_007d0fd0_shaped08_game* pA, Elem_007d0fd0_shaped08_game* pB, Elem_007d0fd0_shaped08_game* pC, uint32_t* pVal, uint32_t zero);

// STUB: 0x007d07a0
void Fn007d07a0_shaped08_game(Elem_007d0fd0_shaped08_game* pDst, Elem_007d0fd0_shaped08_game* pEnd, Tag_007d0fd0_shaped08_game* pTag);

#ifdef OB_DRAFTS
// CLOSE: 0x007d0fd0 score 4
void View_007d0fd0_shaped08_game::Fn007d0fd0(uint32_t n, uint32_t val)
{
    Elem_007d0fd0_shaped08_game* pEnd = mpEnd;
    Elem_007d0fd0_shaped08_game* pBegin = mpBegin;
    uint32_t size = static_cast<uint32_t>(pEnd - pBegin);
    if (n < size) {
        Tag_007d0fd0_shaped08_game tag;
        Elem_007d0fd0_shaped08_game* p = Fn007d0750_shaped08_game(pEnd, pEnd, pBegin + n, &val, 0);
        Fn007d07a0_shaped08_game(p, mpEnd, &tag);
        mpEnd = p;
    } else {
        Insert_007d0fd0(pEnd, n - size, val);
    }
}
#endif


// STUB: 0x00823f5a
int32_t OB_STDCALL Fn00823f5a_shaped08_game(uint32_t owner, uint32_t arg, uint32_t sock, uint32_t how);

// STUB: 0x00823efa
uint32_t OB_STDCALL Fn00823efa_shaped08_game();

// STUB: 0x0081fed0
uint32_t Fn0081fed0_shaped08_game(uint32_t code);

struct View_008210a0_shaped08_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Slot03();
    uint32_t pad4;
    uint32_t mnSocket;
    uint8_t padC[0x44 - 0xc];
    uint32_t mnErrText;
    uint32_t mnErrCode;
    bool Fn008210a0(uint32_t arg, uint32_t* pSock);
    bool Fn008211a0(uint32_t arg, uint32_t* pSock);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008210a0 score 54
bool View_008210a0_shaped08_game::Fn008210a0(uint32_t arg, uint32_t* pSock)
{
    uint32_t sock = *pSock;
    if (sock != 0) {
        int32_t r = Fn00823f5a_shaped08_game(mnSocket, arg, sock, 2);
        if (r == -1) {
            uint32_t e = Fn00823efa_shaped08_game();
            *pSock = 0;
            mnErrText = Fn0081fed0_shaped08_game(e);
            mnErrCode = e;
            if (e == 0x2733) {
                return true;
            }
            return e == 0x2734;
        }
        if (r == 0) {
            *pSock = 0;
            mnErrText = Fn0081fed0_shaped08_game(0x2749);
            mnErrCode = 0x2749;
            Slot03();
            return false;
        }
        *pSock = static_cast<uint32_t>(r);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008211a0 score 54
bool View_008210a0_shaped08_game::Fn008211a0(uint32_t arg, uint32_t* pSock)
{
    uint32_t sock = *pSock;
    if (sock != 0) {
        int32_t r = Fn00823f5a_shaped08_game(mnSocket, arg, sock, 1);
        if (r == -1) {
            uint32_t e = Fn00823efa_shaped08_game();
            *pSock = 0;
            mnErrText = Fn0081fed0_shaped08_game(e);
            mnErrCode = e;
            if (e == 0x2733) {
                return true;
            }
            return e == 0x2734;
        }
        if (r == 0) {
            *pSock = 0;
            mnErrText = Fn0081fed0_shaped08_game(0x2749);
            mnErrCode = 0x2749;
            Slot03();
            return false;
        }
        *pSock = static_cast<uint32_t>(r);
    }
    return true;
}
#endif

struct View_007fbe90_shaped08_game {
    uint8_t pad[0x38];
    float m[13];
    void Fn007fbe90(float* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007fbe90 score 43
void View_007fbe90_shaped08_game::Fn007fbe90(float* v)
{
    float nx = m[2] * v[2] + m[1] * v[1] + m[0] * v[0];
    float ny = m[5] * v[2] + m[4] * v[1] + m[3] * v[0];
    float nz = m[8] * v[2] + m[7] * v[1] + m[6] * v[0];
    v[0] = nx;
    v[1] = ny;
    v[2] = nz;
    float sc = m[12];
    v[0] = nx * sc;
    v[1] = ny * sc;
    v[2] = nz * sc;
    v[0] = v[0] + m[9];
    v[1] = v[1] + m[10];
    v[2] = v[2] + m[11];
}
#endif

struct View_007fcc90_shaped08_game {
    uint8_t pad[0x3c];
    float m[13];
    void Fn007fcc90(float* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007fcc90 score 43
void View_007fcc90_shaped08_game::Fn007fcc90(float* v)
{
    float nx = m[2] * v[2] + m[1] * v[1] + m[0] * v[0];
    float ny = m[5] * v[2] + m[4] * v[1] + m[3] * v[0];
    float nz = m[8] * v[2] + m[7] * v[1] + m[6] * v[0];
    v[0] = nx;
    v[1] = ny;
    v[2] = nz;
    float sc = m[12];
    v[0] = nx * sc;
    v[1] = ny * sc;
    v[2] = nz * sc;
    v[0] = v[0] + m[9];
    v[1] = v[1] + m[10];
    v[2] = v[2] + m[11];
}
#endif
