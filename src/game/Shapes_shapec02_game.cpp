// Shape families of packet shapec02_game, written by scratch/s17/gen/shapec02_game/*.py.
#include "common/types.h"

struct View_006a9770_shapec02_game {
    uint8_t pad[0x40];
    uint32_t mA;
    uint32_t mB;
    void Fn006a9770(uint32_t a, uint32_t b);
};

// FUNCTION: 0x006a9770
void View_006a9770_shapec02_game::Fn006a9770(uint32_t a, uint32_t b)
{
    mA = a;
    mB = b;
}

struct View_0079bc10_shapec02_game {
    uint8_t pad[0x28];
    uint32_t mA;
    uint32_t mB;
    void Fn0079bc10(uint32_t a, uint32_t b);
};

// FUNCTION: 0x0079bc10
void View_0079bc10_shapec02_game::Fn0079bc10(uint32_t a, uint32_t b)
{
    mA = a;
    mB = b;
}

struct View_00604e20_shapec02_game {
    uint8_t pad[0x170];
    uint32_t mA;
    uint32_t mB;
    void Fn00604e20(uint32_t a, uint32_t b);
};

// FUNCTION: 0x00604e20
void View_00604e20_shapec02_game::Fn00604e20(uint32_t a, uint32_t b)
{
    mA = a;
    mB = b;
}

struct View_00575630_shapec02_game {
    uint8_t pad[0x10];
    uint8_t* mpObj;
    void* Fn00575630();
};

// FUNCTION: 0x00575630
void* View_00575630_shapec02_game::Fn00575630()
{
    if (mpObj) {
        return mpObj + 0x8;
    }
    return 0;
}

struct View_00576ef0_shapec02_game {
    uint8_t pad[0x1c];
    uint8_t* mpObj;
    void* Fn00576ef0();
};

// FUNCTION: 0x00576ef0
void* View_00576ef0_shapec02_game::Fn00576ef0()
{
    if (mpObj) {
        return mpObj + 0x8;
    }
    return 0;
}

struct View_00741810_shapec02_game {
    uint8_t pad[0xe8];
    uint8_t* mpObj;
    void* Fn00741810();
};

// FUNCTION: 0x00741810
void* View_00741810_shapec02_game::Fn00741810()
{
    if (mpObj) {
        return mpObj + 0xc;
    }
    return 0;
}

struct View_0057c040_shapec02_game {
    uint8_t pad[0xc];
    uint8_t* mpObj;
    void* Fn0057c040();
};

// FUNCTION: 0x0057c040
void* View_0057c040_shapec02_game::Fn0057c040()
{
    if (mpObj) {
        return mpObj + 0x8;
    }
    return 0;
}

struct View_00579100_shapec02_game {
    void* Fn00579100();
};

// FUNCTION: 0x00579100
void* View_00579100_shapec02_game::Fn00579100()
{
    uint8_t* pBase = reinterpret_cast<uint8_t*>(this) - 0x24;
    if (pBase) {
        return reinterpret_cast<uint8_t*>(this) - 0x1c;
    }
    return 0;
}

struct View_00880a50_shapec02_game {
    void* Fn00880a50();
};

// FUNCTION: 0x00880a50
void* View_00880a50_shapec02_game::Fn00880a50()
{
    uint8_t* pBase = reinterpret_cast<uint8_t*>(this) - 0x40;
    if (pBase) {
        return reinterpret_cast<uint8_t*>(this) - 0x24;
    }
    return 0;
}

struct View_008b59b0_shapec02_game {
    void* Fn008b59b0();
};

// FUNCTION: 0x008b59b0
void* View_008b59b0_shapec02_game::Fn008b59b0()
{
    uint8_t* pBase = reinterpret_cast<uint8_t*>(this) - 0xc;
    if (pBase) {
        return reinterpret_cast<uint8_t*>(this) - 0x4;
    }
    return 0;
}

struct View_0098ad40_shapec02_game {
    void* Fn0098ad40();
};

// FUNCTION: 0x0098ad40
void* View_0098ad40_shapec02_game::Fn0098ad40()
{
    uint8_t* pBase = reinterpret_cast<uint8_t*>(this) - 0x170;
    if (pBase) {
        return reinterpret_cast<uint8_t*>(this) - 0x154;
    }
    return 0;
}

struct View_00595850_shapec02_game {
    uint32_t mVtbl;
    // STUB: 0x00677290
    void Base00677290();
    View_00595850_shapec02_game* Fn00595850();
};

// FUNCTION: 0x00595850
View_00595850_shapec02_game* View_00595850_shapec02_game::Fn00595850()
{
    Base00677290();
    mVtbl = 0xa9f7b4;
    return this;
}

struct View_00596f20_shapec02_game {
    uint32_t mVtbl;
    // STUB: 0x00677290
    void Base00677290();
    View_00596f20_shapec02_game* Fn00596f20();
};

// FUNCTION: 0x00596f20
View_00596f20_shapec02_game* View_00596f20_shapec02_game::Fn00596f20()
{
    Base00677290();
    mVtbl = 0xa9fed4;
    return this;
}

struct View_00675ad0_shapec02_game {
    uint32_t mVtbl;
    // STUB: 0x0099d938
    void Base0099d938();
    View_00675ad0_shapec02_game* Fn00675ad0();
};

// FUNCTION: 0x00675ad0
View_00675ad0_shapec02_game* View_00675ad0_shapec02_game::Fn00675ad0()
{
    Base0099d938();
    mVtbl = 0xaae630;
    return this;
}

struct View_00808900_shapec02_game {
    uint32_t mVtbl;
    // STUB: 0x0097564d
    void Base0097564d();
    View_00808900_shapec02_game* Fn00808900();
};

// FUNCTION: 0x00808900
View_00808900_shapec02_game* View_00808900_shapec02_game::Fn00808900()
{
    Base0097564d();
    mVtbl = 0xabd714;
    return this;
}

// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t nBytes);

struct Obj_005a3bd0_shapec02_game {
    uint32_t mVtbl;
    uint32_t pad[3];
    // STUB: 0x0097564d
    void Base0097564d();
};

// FUNCTION: 0x005a3bd0
Obj_005a3bd0_shapec02_game* Fn005a3bd0()
{
    Obj_005a3bd0_shapec02_game* p = static_cast<Obj_005a3bd0_shapec02_game*>(Fn005e55e0(0x10));
    if (p) {
        p->Base0097564d();
        p->mVtbl = 0xaa0a14;
        return p;
    }
    return 0;
}

struct Obj_008005b0_shapec02_game {
    uint32_t mVtbl;
    uint32_t pad[3];
    // STUB: 0x0097564d
    void Base0097564d();
};

// FUNCTION: 0x008005b0
Obj_008005b0_shapec02_game* Fn008005b0()
{
    Obj_008005b0_shapec02_game* p = static_cast<Obj_008005b0_shapec02_game*>(Fn005e55e0(0x10));
    if (p) {
        p->Base0097564d();
        p->mVtbl = 0xabd324;
        return p;
    }
    return 0;
}

struct Obj_00804050_shapec02_game {
    uint32_t mVtbl;
    uint32_t pad[3];
    // STUB: 0x0097564d
    void Base0097564d();
};

// FUNCTION: 0x00804050
Obj_00804050_shapec02_game* Fn00804050()
{
    Obj_00804050_shapec02_game* p = static_cast<Obj_00804050_shapec02_game*>(Fn005e55e0(0x10));
    if (p) {
        p->Base0097564d();
        p->mVtbl = 0xabd594;
        return p;
    }
    return 0;
}

// STUB: 0x005867b0
void* Fn005867b0(const void* a, const void* b, void* c, uint8_t* pTag, uint32_t flag);

// FUNCTION: 0x00586850
void* Fn00586850(const void* a, const void* b, void* c)
{
    uint8_t tag;
    return Fn005867b0(a, b, c, &tag, 0);
}

// STUB: 0x00586800
void* Fn00586800(const void* a, const void* b, void* c, uint8_t* pTag, uint32_t flag);

// FUNCTION: 0x00586870
void* Fn00586870(const void* a, const void* b, void* c)
{
    uint8_t tag;
    return Fn00586800(a, b, c, &tag, 0);
}

// STUB: 0x005c7e50
void* Fn005c7e50(const void* a, const void* b, void* c, uint8_t* pTag, uint32_t flag);

// FUNCTION: 0x005c82c0
void* Fn005c82c0(const void* a, const void* b, void* c)
{
    uint8_t tag;
    return Fn005c7e50(a, b, c, &tag, 0);
}

// STUB: 0x0081a880
void* Fn0081a880(const void* a, const void* b, void* c, uint8_t* pTag, uint32_t flag);

// FUNCTION: 0x0081aba0
void* Fn0081aba0(const void* a, const void* b, void* c)
{
    uint8_t tag;
    return Fn0081a880(a, b, c, &tag, 0);
}

struct Node_pool_shapec02_game {
    Node_pool_shapec02_game* mpNext;
};

struct PoolState_pool_shapec02_game {
    uint32_t pad0;
    uint32_t pad4;
    Node_pool_shapec02_game* mpFree;
    uint32_t mnCount;
};

struct PoolMgr_pool_shapec02_game {
    // STUB: 0x0090cf9a
    Node_pool_shapec02_game* Refill();
};

struct Obj_005d0bc0_shapec02_game {
    // STUB: 0x005d00f0
    Obj_005d0bc0_shapec02_game* Init(uint32_t n);
};

// GLOBAL: 0x00b0a808
extern PoolMgr_pool_shapec02_game gPoolMgr005d0bc0_shapec02_game;

// GLOBAL: 0x00b0a80c
extern PoolState_pool_shapec02_game* gpPool005d0bc0_shapec02_game;

// FUNCTION: 0x005d0bc0
Obj_005d0bc0_shapec02_game* Fn005d0bc0()
{
    Node_pool_shapec02_game* pNode = gpPool005d0bc0_shapec02_game->mpFree;
    if (!pNode) {
        pNode = gPoolMgr005d0bc0_shapec02_game.Refill();
    }
    gpPool005d0bc0_shapec02_game->mpFree = pNode->mpNext;
    gpPool005d0bc0_shapec02_game->mnCount++;
    return reinterpret_cast<Obj_005d0bc0_shapec02_game*>(pNode)->Init(1);
}

struct Obj_005f5ce0_shapec02_game {
    // STUB: 0x005f5510
    Obj_005f5ce0_shapec02_game* Init(uint32_t n);
};

// GLOBAL: 0x00b0a96c
extern PoolMgr_pool_shapec02_game gPoolMgr005f5ce0_shapec02_game;

// GLOBAL: 0x00b0a970
extern PoolState_pool_shapec02_game* gpPool005f5ce0_shapec02_game;

// FUNCTION: 0x005f5ce0
Obj_005f5ce0_shapec02_game* Fn005f5ce0()
{
    Node_pool_shapec02_game* pNode = gpPool005f5ce0_shapec02_game->mpFree;
    if (!pNode) {
        pNode = gPoolMgr005f5ce0_shapec02_game.Refill();
    }
    gpPool005f5ce0_shapec02_game->mpFree = pNode->mpNext;
    gpPool005f5ce0_shapec02_game->mnCount++;
    return reinterpret_cast<Obj_005f5ce0_shapec02_game*>(pNode)->Init(1);
}

struct Obj_0061c480_shapec02_game {
    // STUB: 0x0061bdd0
    Obj_0061c480_shapec02_game* Init(uint32_t n);
};

// GLOBAL: 0x00b0b394
extern PoolMgr_pool_shapec02_game gPoolMgr0061c480_shapec02_game;

// GLOBAL: 0x00b0b398
extern PoolState_pool_shapec02_game* gpPool0061c480_shapec02_game;

// FUNCTION: 0x0061c480
Obj_0061c480_shapec02_game* Fn0061c480()
{
    Node_pool_shapec02_game* pNode = gpPool0061c480_shapec02_game->mpFree;
    if (!pNode) {
        pNode = gPoolMgr0061c480_shapec02_game.Refill();
    }
    gpPool0061c480_shapec02_game->mpFree = pNode->mpNext;
    gpPool0061c480_shapec02_game->mnCount++;
    return reinterpret_cast<Obj_0061c480_shapec02_game*>(pNode)->Init(1);
}

struct Obj_0064e340_shapec02_game {
    // STUB: 0x0064db30
    Obj_0064e340_shapec02_game* Init(uint32_t n);
};

// GLOBAL: 0x00b0c0c8
extern PoolMgr_pool_shapec02_game gPoolMgr0064e340_shapec02_game;

// GLOBAL: 0x00b0c0cc
extern PoolState_pool_shapec02_game* gpPool0064e340_shapec02_game;

// FUNCTION: 0x0064e340
Obj_0064e340_shapec02_game* Fn0064e340()
{
    Node_pool_shapec02_game* pNode = gpPool0064e340_shapec02_game->mpFree;
    if (!pNode) {
        pNode = gPoolMgr0064e340_shapec02_game.Refill();
    }
    gpPool0064e340_shapec02_game->mpFree = pNode->mpNext;
    gpPool0064e340_shapec02_game->mnCount++;
    return reinterpret_cast<Obj_0064e340_shapec02_game*>(pNode)->Init(1);
}


struct Sim_slcall_shapec02_game {
    virtual void S0(void* p);
    virtual void S1(void* p);
    virtual void S2(void* p);
    virtual void S3(void* p);
    virtual void S4(void* p);
    virtual void S5(void* p);
    virtual void S6(void* p);
    virtual void S7(void* p);
    virtual void S8(void* p);
    virtual void S9(void* p);
    virtual void S10(void* p);
    virtual void S11(void* p);
    virtual void S12(void* p);
    virtual void S13(void* p);
    virtual void S14(void* p);
    virtual void S15(void* p);
    virtual void S16(void* p);
    virtual void S17(void* p);
    virtual void S18(void* p);
    virtual void S19(void* p);
    virtual void S20(void* p);
    virtual void S21(void* p);
    virtual void S22(void* p);
    virtual void S23(void* p);
    virtual void S24(void* p);
    virtual void S25(void* p);
    virtual void S26(void* p);
    virtual void S27(void* p);
    virtual void S28(void* p);
    virtual void S29(void* p);
    virtual void S30(void* p);
    virtual void S31(void* p);
    virtual void S32(void* p);
    virtual void S33(void* p);
    virtual void S34(void* p);
    virtual void S35(void* p);
    virtual void S36(void* p);
    virtual void S37(void* p);
    virtual void S38(void* p);
    virtual void S39(void* p);
    virtual void S40(void* p);
    virtual void S41(void* p);
    virtual void S42(void* p);
    virtual void S43(void* p);
    virtual void S44(void* p);
    virtual void S45(void* p);
    virtual void S46(void* p);
    virtual void S47(void* p);
    virtual void S48(void* p);
    virtual void S49(void* p);
    virtual void S50(void* p);
    virtual void S51(void* p);
    virtual void S52(void* p);
    virtual void S53(void* p);
    virtual void S54(void* p);
    virtual void S55(void* p);
    virtual void S56(void* p);
    virtual void S57(void* p);
    virtual void S58(void* p);
};

// GLOBAL: 0x00b43c94
extern Sim_slcall_shapec02_game* gpB43c94_shapec02_game;

// FUNCTION: 0x00602210
void Fn00602210(void* p)
{
    if (gpB43c94_shapec02_game) {
        gpB43c94_shapec02_game->S51(p);
    }
}

// FUNCTION: 0x00602250
void Fn00602250(void* p)
{
    if (gpB43c94_shapec02_game) {
        gpB43c94_shapec02_game->S55(p);
    }
}

// FUNCTION: 0x00602270
void Fn00602270(void* p)
{
    if (gpB43c94_shapec02_game) {
        gpB43c94_shapec02_game->S58(p);
    }
}

// FUNCTION: 0x005f90b0
void Fn005f90b0(void* p)
{
    if (gpB43c94_shapec02_game) {
        gpB43c94_shapec02_game->S24(p);
    }
}



struct Elem_00588630_shapec02_game {
    uint8_t pad[0x64];
    // STUB: 0x005833f0
    void Assign(const Elem_00588630_shapec02_game* pSrc);
};

// FUNCTION: 0x00588630
Elem_00588630_shapec02_game* Fn00588630(const Elem_00588630_shapec02_game* pFirst, const Elem_00588630_shapec02_game* pLast, Elem_00588630_shapec02_game* pDestEnd)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        --pLast;
        --pDestEnd;
        pDestEnd->Assign(pLast);
    }
    return pDestEnd;
}

struct Elem_005ab790_shapec02_game {
    uint8_t pad[0x6c];
    // STUB: 0x00589af0
    void Assign(const Elem_005ab790_shapec02_game* pSrc);
};

// FUNCTION: 0x005ab790
Elem_005ab790_shapec02_game* Fn005ab790(const Elem_005ab790_shapec02_game* pFirst, const Elem_005ab790_shapec02_game* pLast, Elem_005ab790_shapec02_game* pDestEnd)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        --pLast;
        --pDestEnd;
        pDestEnd->Assign(pLast);
    }
    return pDestEnd;
}

struct Elem_005db0c0_shapec02_game {
    uint8_t pad[0x14];
    // STUB: 0x005daef0
    void Assign(const Elem_005db0c0_shapec02_game* pSrc);
};

// FUNCTION: 0x005db0c0
Elem_005db0c0_shapec02_game* Fn005db0c0(const Elem_005db0c0_shapec02_game* pFirst, const Elem_005db0c0_shapec02_game* pLast, Elem_005db0c0_shapec02_game* pDestEnd)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        --pLast;
        --pDestEnd;
        pDestEnd->Assign(pLast);
    }
    return pDestEnd;
}

struct Elem_007d3c10_shapec02_game {
    uint8_t pad[0x68];
    // STUB: 0x007d3b10
    void Assign(const Elem_007d3c10_shapec02_game* pSrc);
};

// FUNCTION: 0x007d3c10
Elem_007d3c10_shapec02_game* Fn007d3c10(const Elem_007d3c10_shapec02_game* pFirst, const Elem_007d3c10_shapec02_game* pLast, Elem_007d3c10_shapec02_game* pDestEnd)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        --pLast;
        --pDestEnd;
        pDestEnd->Assign(pLast);
    }
    return pDestEnd;
}

struct Strm_005d1b40_shapec02_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual void S8();
    virtual void S9();
    virtual void S10();
    virtual void S11();
    virtual void S12();
    virtual void S13();
    virtual void S14();
    virtual void S15();
    virtual void S16();
    virtual void S17();
    virtual void S18();
    virtual void S19();
    virtual void S20();
    virtual void S21();
    virtual void S22();
    virtual void S23();
    virtual void S24();
    virtual void S25();
    virtual void S26();
    virtual bool Slot(uint32_t a, uint32_t b);
};

struct View_005d1b40_shapec02_game {
    uint8_t pad[4];
    uint8_t mbOk;
    uint8_t pad5[3];
    Strm_005d1b40_shapec02_game* mpStream;
    bool Fn005d1b40(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1b40 score 6
bool View_005d1b40_shapec02_game::Fn005d1b40(uint32_t a, uint32_t b)
{
    if (mbOk) {
        if (mpStream->Slot(a, b)) {
            bool bTrue = true;
            mbOk = bTrue;
            return bTrue;
        }
    }
    bool bFalse = false;
    mbOk = bFalse;
    return bFalse;
}
#endif

struct Strm_005d1ef0_shapec02_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual void S8();
    virtual void S9();
    virtual void S10();
    virtual void S11();
    virtual void S12();
    virtual void S13();
    virtual void S14();
    virtual void S15();
    virtual void S16();
    virtual void S17();
    virtual void S18();
    virtual void S19();
    virtual void S20();
    virtual void S21();
    virtual void S22();
    virtual void S23();
    virtual void S24();
    virtual void S25();
    virtual void S26();
    virtual void S27();
    virtual void S28();
    virtual void S29();
    virtual void S30();
    virtual void S31();
    virtual void S32();
    virtual void S33();
    virtual void S34();
    virtual void S35();
    virtual void S36();
    virtual void S37();
    virtual void S38();
    virtual void S39();
    virtual void S40();
    virtual void S41();
    virtual void S42();
    virtual bool Slot(uint32_t a, uint32_t b);
};

struct View_005d1ef0_shapec02_game {
    uint8_t pad[4];
    uint8_t mbOk;
    uint8_t pad5[3];
    Strm_005d1ef0_shapec02_game* mpStream;
    bool Fn005d1ef0(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1ef0 score 6
bool View_005d1ef0_shapec02_game::Fn005d1ef0(uint32_t a, uint32_t b)
{
    if (mbOk) {
        if (mpStream->Slot(a, b)) {
            bool bTrue = true;
            mbOk = bTrue;
            return bTrue;
        }
    }
    bool bFalse = false;
    mbOk = bFalse;
    return bFalse;
}
#endif

struct Strm_005d1f30_shapec02_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual void S8();
    virtual void S9();
    virtual void S10();
    virtual void S11();
    virtual void S12();
    virtual void S13();
    virtual void S14();
    virtual void S15();
    virtual void S16();
    virtual void S17();
    virtual void S18();
    virtual void S19();
    virtual void S20();
    virtual void S21();
    virtual void S22();
    virtual void S23();
    virtual void S24();
    virtual void S25();
    virtual void S26();
    virtual void S27();
    virtual void S28();
    virtual void S29();
    virtual void S30();
    virtual void S31();
    virtual void S32();
    virtual void S33();
    virtual void S34();
    virtual void S35();
    virtual void S36();
    virtual void S37();
    virtual void S38();
    virtual void S39();
    virtual void S40();
    virtual bool Slot(uint32_t a, uint32_t b);
};

struct View_005d1f30_shapec02_game {
    uint8_t pad[4];
    uint8_t mbOk;
    uint8_t pad5[3];
    Strm_005d1f30_shapec02_game* mpStream;
    bool Fn005d1f30(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1f30 score 6
bool View_005d1f30_shapec02_game::Fn005d1f30(uint32_t a, uint32_t b)
{
    if (mbOk) {
        if (mpStream->Slot(a, b)) {
            bool bTrue = true;
            mbOk = bTrue;
            return bTrue;
        }
    }
    bool bFalse = false;
    mbOk = bFalse;
    return bFalse;
}
#endif

struct Strm_005d2030_shapec02_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual void S8();
    virtual void S9();
    virtual void S10();
    virtual void S11();
    virtual void S12();
    virtual void S13();
    virtual void S14();
    virtual void S15();
    virtual void S16();
    virtual void S17();
    virtual void S18();
    virtual void S19();
    virtual void S20();
    virtual void S21();
    virtual void S22();
    virtual void S23();
    virtual void S24();
    virtual void S25();
    virtual void S26();
    virtual void S27();
    virtual void S28();
    virtual void S29();
    virtual void S30();
    virtual void S31();
    virtual void S32();
    virtual void S33();
    virtual void S34();
    virtual void S35();
    virtual void S36();
    virtual void S37();
    virtual void S38();
    virtual void S39();
    virtual void S40();
    virtual void S41();
    virtual void S42();
    virtual void S43();
    virtual void S44();
    virtual void S45();
    virtual void S46();
    virtual void S47();
    virtual void S48();
    virtual void S49();
    virtual void S50();
    virtual bool Slot(uint32_t a, uint32_t b);
};

struct View_005d2030_shapec02_game {
    uint8_t pad[4];
    uint8_t mbOk;
    uint8_t pad5[3];
    Strm_005d2030_shapec02_game* mpStream;
    bool Fn005d2030(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d2030 score 6
bool View_005d2030_shapec02_game::Fn005d2030(uint32_t a, uint32_t b)
{
    if (mbOk) {
        if (mpStream->Slot(a, b)) {
            bool bTrue = true;
            mbOk = bTrue;
            return bTrue;
        }
    }
    bool bFalse = false;
    mbOk = bFalse;
    return bFalse;
}
#endif

struct Dev_007d2760_shapec02_game {
    virtual void S0(uint32_t n);
    virtual void S1(uint32_t n);
    virtual void S2(uint32_t n);
    virtual void S3(uint32_t n);
    virtual void S4(uint32_t n);
    virtual void S5(uint32_t n);
    virtual void S6(uint32_t n);
    virtual void S7(uint32_t n);
    virtual void S8(uint32_t n);
    virtual void S9(uint32_t n);
    virtual void S10(uint32_t n);
    virtual void S11(uint32_t n);
    virtual void S12(uint32_t n);
    virtual void S13(uint32_t n);
    virtual void S14(uint32_t n);
    virtual void S15(uint32_t n);
};

struct View_007d2760_shapec02_game {
    uint8_t pad[0x30];
    Dev_007d2760_shapec02_game* mpDev;
    uint8_t pad34[0x4c];
    uint32_t mnFlags;
    void Fn007d2760(bool bOn);
};

// FUNCTION: 0x007d2760
void View_007d2760_shapec02_game::Fn007d2760(bool bOn)
{
    if (bOn) {
        if (!(mnFlags & 0x1)) {
            mpDev->S15(1);
            mnFlags |= 0x1;
        }
    } else if (mnFlags & 0x1) {
        mpDev->S15(0);
        mnFlags &= ~0x1;
    }
}

struct Dev_007d2800_shapec02_game {
    virtual void S0(uint32_t n);
    virtual void S1(uint32_t n);
    virtual void S2(uint32_t n);
    virtual void S3(uint32_t n);
    virtual void S4(uint32_t n);
    virtual void S5(uint32_t n);
    virtual void S6(uint32_t n);
    virtual void S7(uint32_t n);
    virtual void S8(uint32_t n);
    virtual void S9(uint32_t n);
    virtual void S10(uint32_t n);
    virtual void S11(uint32_t n);
    virtual void S12(uint32_t n);
    virtual void S13(uint32_t n);
    virtual void S14(uint32_t n);
    virtual void S15(uint32_t n);
    virtual void S16(uint32_t n);
    virtual void S17(uint32_t n);
};

struct View_007d2800_shapec02_game {
    uint8_t pad[0x30];
    Dev_007d2800_shapec02_game* mpDev;
    uint8_t pad34[0x4c];
    uint32_t mnFlags;
    void Fn007d2800(bool bOn);
};

// FUNCTION: 0x007d2800
void View_007d2800_shapec02_game::Fn007d2800(bool bOn)
{
    if (bOn) {
        if (!(mnFlags & 0x2)) {
            mpDev->S17(1);
            mnFlags |= 0x2;
        }
    } else if (mnFlags & 0x2) {
        mpDev->S17(0);
        mnFlags &= ~0x2;
    }
}

struct Dev_007d27b0_shapec02_game {
    virtual void S0(uint32_t n);
    virtual void S1(uint32_t n);
    virtual void S2(uint32_t n);
    virtual void S3(uint32_t n);
    virtual void S4(uint32_t n);
    virtual void S5(uint32_t n);
    virtual void S6(uint32_t n);
    virtual void S7(uint32_t n);
    virtual void S8(uint32_t n);
    virtual void S9(uint32_t n);
    virtual void S10(uint32_t n);
    virtual void S11(uint32_t n);
    virtual void S12(uint32_t n);
    virtual void S13(uint32_t n);
    virtual void S14(uint32_t n);
    virtual void S15(uint32_t n);
    virtual void S16(uint32_t n);
    virtual void S17(uint32_t n);
    virtual void S18(uint32_t n);
    virtual void S19(uint32_t n);
    virtual void S20(uint32_t n);
    virtual void S21(uint32_t n);
    virtual void S22(uint32_t n);
    virtual void S23(uint32_t n);
    virtual void S24(uint32_t n);
    virtual void S25(uint32_t n);
    virtual void S26(uint32_t n);
    virtual void S27(uint32_t n);
    virtual void S28(uint32_t n);
    virtual void S29(uint32_t n);
    virtual void S30(uint32_t n);
    virtual void S31(uint32_t n);
    virtual void S32(uint32_t n);
    virtual void S33(uint32_t n);
    virtual void S34(uint32_t n);
    virtual void S35(uint32_t n);
    virtual void S36(uint32_t n);
    virtual void S37(uint32_t n);
    virtual void S38(uint32_t n);
    virtual void S39(uint32_t n);
    virtual void S40(uint32_t n);
    virtual void S41(uint32_t n);
    virtual void S42(uint32_t n);
    virtual void S43(uint32_t n);
    virtual void S44(uint32_t n);
    virtual void S45(uint32_t n);
};

struct View_007d27b0_shapec02_game {
    uint8_t pad[0x30];
    Dev_007d27b0_shapec02_game* mpDev;
    uint8_t pad34[0x4c];
    uint32_t mnFlags;
    void Fn007d27b0(bool bOn);
};

// FUNCTION: 0x007d27b0
void View_007d27b0_shapec02_game::Fn007d27b0(bool bOn)
{
    if (bOn) {
        if (!(mnFlags & 0x4)) {
            mpDev->S44(1);
            mnFlags |= 0x4;
        }
    } else if (mnFlags & 0x4) {
        mpDev->S45(1);
        mnFlags &= ~0x4;
    }
}

struct Dev_007d2850_shapec02_game {
    virtual void S0(uint32_t n);
    virtual void S1(uint32_t n);
    virtual void S2(uint32_t n);
    virtual void S3(uint32_t n);
    virtual void S4(uint32_t n);
    virtual void S5(uint32_t n);
    virtual void S6(uint32_t n);
    virtual void S7(uint32_t n);
    virtual void S8(uint32_t n);
    virtual void S9(uint32_t n);
    virtual void S10(uint32_t n);
    virtual void S11(uint32_t n);
    virtual void S12(uint32_t n);
    virtual void S13(uint32_t n);
    virtual void S14(uint32_t n);
    virtual void S15(uint32_t n);
    virtual void S16(uint32_t n);
    virtual void S17(uint32_t n);
    virtual void S18(uint32_t n);
    virtual void S19(uint32_t n);
    virtual void S20(uint32_t n);
    virtual void S21(uint32_t n);
    virtual void S22(uint32_t n);
    virtual void S23(uint32_t n);
    virtual void S24(uint32_t n);
    virtual void S25(uint32_t n);
    virtual void S26(uint32_t n);
    virtual void S27(uint32_t n);
    virtual void S28(uint32_t n);
    virtual void S29(uint32_t n);
    virtual void S30(uint32_t n);
    virtual void S31(uint32_t n);
    virtual void S32(uint32_t n);
    virtual void S33(uint32_t n);
    virtual void S34(uint32_t n);
    virtual void S35(uint32_t n);
    virtual void S36(uint32_t n);
    virtual void S37(uint32_t n);
    virtual void S38(uint32_t n);
    virtual void S39(uint32_t n);
    virtual void S40(uint32_t n);
    virtual void S41(uint32_t n);
    virtual void S42(uint32_t n);
    virtual void S43(uint32_t n);
    virtual void S44(uint32_t n);
    virtual void S45(uint32_t n);
};

struct View_007d2850_shapec02_game {
    uint8_t pad[0x30];
    Dev_007d2850_shapec02_game* mpDev;
    uint8_t pad34[0x4c];
    uint32_t mnFlags;
    void Fn007d2850(bool bOn);
};

// FUNCTION: 0x007d2850
void View_007d2850_shapec02_game::Fn007d2850(bool bOn)
{
    if (bOn) {
        if (!(mnFlags & 0x40)) {
            mpDev->S44(3);
            mnFlags |= 0x40;
        }
    } else if (mnFlags & 0x40) {
        mpDev->S45(3);
        mnFlags &= ~0x40;
    }
}

// STUB: 0x00930be0
void Fn00930be0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);

struct View_00988be0_shapec02_game {
    void Fn00988be0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
};

// FUNCTION: 0x00988be0
void View_00988be0_shapec02_game::Fn00988be0(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Fn00930be0(a, b, c, d);
}

// STUB: 0x009875a0
void Fn009875a0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);

struct View_00988de0_shapec02_game {
    void Fn00988de0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
};

// FUNCTION: 0x00988de0
void View_00988de0_shapec02_game::Fn00988de0(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Fn009875a0(a, b, c, d);
}

// STUB: 0x009877f0
void Fn009877f0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);

struct View_00988e00_shapec02_game {
    void Fn00988e00(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
};

// FUNCTION: 0x00988e00
void View_00988e00_shapec02_game::Fn00988e00(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Fn009877f0(a, b, c, d);
}

// STUB: 0x00988270
void Fn00988270(uint32_t a, uint32_t b, uint32_t c, uint32_t d);

struct View_00988e80_shapec02_game {
    void Fn00988e80(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
};

// FUNCTION: 0x00988e80
void View_00988e80_shapec02_game::Fn00988e80(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Fn00988270(a, b, c, d);
}

struct Elem_0058adc0_shapec02_game {
    uint8_t pad[0x64];
};

// STUB: 00588510
Elem_0058adc0_shapec02_game* Fn00588510(const Elem_0058adc0_shapec02_game* a, const Elem_0058adc0_shapec02_game* b, Elem_0058adc0_shapec02_game* c, uint8_t* pTag, uint32_t flag);

// STUB: 00588760
void Fn00588760(Elem_0058adc0_shapec02_game* a, Elem_0058adc0_shapec02_game* b, uint8_t* pTag);

struct Vec_0058adc0_shapec02_game {
    Elem_0058adc0_shapec02_game* mpBegin;
    Elem_0058adc0_shapec02_game* mpEnd;
    // STUB: 0058a020
    void Fill(Elem_0058adc0_shapec02_game* pPos, uint32_t n, const Elem_0058adc0_shapec02_game* pVal);
    void Fn0058adc0(uint32_t n, const Elem_0058adc0_shapec02_game* pVal);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058adc0 score 28
void Vec_0058adc0_shapec02_game::Fn0058adc0(uint32_t n, const Elem_0058adc0_shapec02_game* pVal)
{
    Elem_0058adc0_shapec02_game* pBegin = mpBegin;
    Elem_0058adc0_shapec02_game* pEnd = mpEnd;
    uint32_t nSize = static_cast<uint32_t>(pEnd - pBegin);
    if (n < nSize) {
        uint8_t tagA;
        Elem_0058adc0_shapec02_game* pNew = Fn00588510(pEnd, pEnd, pBegin + n, &tagA, 0);
        Fn00588760(pNew, mpEnd, &tagA);
        mpEnd = pNew;
    } else {
        Fill(pEnd, n - nSize, pVal);
    }
}
#endif

struct Elem_0064e920_shapec02_game {
    uint8_t pad[0x2c];
};

// STUB: 0064d3d0
Elem_0064e920_shapec02_game* Fn0064d3d0(const Elem_0064e920_shapec02_game* a, const Elem_0064e920_shapec02_game* b, Elem_0064e920_shapec02_game* c, uint8_t* pTag, uint32_t flag);

// STUB: 0064d450
void Fn0064d450(Elem_0064e920_shapec02_game* a, Elem_0064e920_shapec02_game* b, uint8_t* pTag);

struct Vec_0064e920_shapec02_game {
    Elem_0064e920_shapec02_game* mpBegin;
    Elem_0064e920_shapec02_game* mpEnd;
    // STUB: 0064e200
    void Fill(Elem_0064e920_shapec02_game* pPos, uint32_t n, const Elem_0064e920_shapec02_game* pVal);
    void Fn0064e920(uint32_t n, const Elem_0064e920_shapec02_game* pVal);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0064e920 score 28
void Vec_0064e920_shapec02_game::Fn0064e920(uint32_t n, const Elem_0064e920_shapec02_game* pVal)
{
    Elem_0064e920_shapec02_game* pBegin = mpBegin;
    Elem_0064e920_shapec02_game* pEnd = mpEnd;
    uint32_t nSize = static_cast<uint32_t>(pEnd - pBegin);
    if (n < nSize) {
        uint8_t tagA;
        Elem_0064e920_shapec02_game* pNew = Fn0064d3d0(pEnd, pEnd, pBegin + n, &tagA, 0);
        Fn0064d450(pNew, mpEnd, &tagA);
        mpEnd = pNew;
    } else {
        Fill(pEnd, n - nSize, pVal);
    }
}
#endif

struct Elem_00805190_shapec02_game {
    uint8_t pad[0x34];
};

// STUB: 008022e0
Elem_00805190_shapec02_game* Fn008022e0(const Elem_00805190_shapec02_game* a, const Elem_00805190_shapec02_game* b, Elem_00805190_shapec02_game* c, uint8_t* pTag, uint32_t flag);

// STUB: 008021f0
void Fn008021f0(Elem_00805190_shapec02_game* a, Elem_00805190_shapec02_game* b, uint8_t* pTag);

struct Vec_00805190_shapec02_game {
    Elem_00805190_shapec02_game* mpBegin;
    Elem_00805190_shapec02_game* mpEnd;
    // STUB: 00804c80
    void Fill(Elem_00805190_shapec02_game* pPos, uint32_t n, const Elem_00805190_shapec02_game* pVal);
    void Fn00805190(uint32_t n, const Elem_00805190_shapec02_game* pVal);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00805190 score 28
void Vec_00805190_shapec02_game::Fn00805190(uint32_t n, const Elem_00805190_shapec02_game* pVal)
{
    Elem_00805190_shapec02_game* pBegin = mpBegin;
    Elem_00805190_shapec02_game* pEnd = mpEnd;
    uint32_t nSize = static_cast<uint32_t>(pEnd - pBegin);
    if (n < nSize) {
        uint8_t tagA;
        Elem_00805190_shapec02_game* pNew = Fn008022e0(pEnd, pEnd, pBegin + n, &tagA, 0);
        Fn008021f0(pNew, mpEnd, &tagA);
        mpEnd = pNew;
    } else {
        Fill(pEnd, n - nSize, pVal);
    }
}
#endif

struct Elem_008b66e0_shapec02_game {
    uint8_t pad[0x2c];
};

// STUB: 008b63d0
Elem_008b66e0_shapec02_game* Fn008b63d0(const Elem_008b66e0_shapec02_game* a, const Elem_008b66e0_shapec02_game* b, Elem_008b66e0_shapec02_game* c, uint8_t* pTag, uint32_t flag);

// STUB: 008b5ed0
void Fn008b5ed0(Elem_008b66e0_shapec02_game* a, Elem_008b66e0_shapec02_game* b, uint8_t* pTag);

struct Vec_008b66e0_shapec02_game {
    Elem_008b66e0_shapec02_game* mpBegin;
    Elem_008b66e0_shapec02_game* mpEnd;
    // STUB: 008b6550
    void Fill(Elem_008b66e0_shapec02_game* pPos, uint32_t n, const Elem_008b66e0_shapec02_game* pVal);
    void Fn008b66e0(uint32_t n, const Elem_008b66e0_shapec02_game* pVal);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008b66e0 score 28
void Vec_008b66e0_shapec02_game::Fn008b66e0(uint32_t n, const Elem_008b66e0_shapec02_game* pVal)
{
    Elem_008b66e0_shapec02_game* pBegin = mpBegin;
    Elem_008b66e0_shapec02_game* pEnd = mpEnd;
    uint32_t nSize = static_cast<uint32_t>(pEnd - pBegin);
    if (n < nSize) {
        uint8_t tagA;
        Elem_008b66e0_shapec02_game* pNew = Fn008b63d0(pEnd, pEnd, pBegin + n, &tagA, 0);
        Fn008b5ed0(pNew, mpEnd, &tagA);
        mpEnd = pNew;
    } else {
        Fill(pEnd, n - nSize, pVal);
    }
}
#endif

struct Ref_00568ba0_shapec02_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
};

// FUNCTION: 0x00568ba0
Ref_00568ba0_shapec02_game** Fn00568ba0(Ref_00568ba0_shapec02_game** pFirst, Ref_00568ba0_shapec02_game** pLast, Ref_00568ba0_shapec02_game** pDest)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        if (pFirst != pDest) {
            Ref_00568ba0_shapec02_game* pNew = *pFirst;
            Ref_00568ba0_shapec02_game* pOld = *pDest;
            if (pNew != pOld) {
                if (pNew) {
                    pNew->S1();
                }
                *pDest = pNew;
                if (pOld) {
                    pOld->S2();
                }
            }
        }
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Ref_00586b00_shapec02_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
};

// FUNCTION: 0x00586b00
Ref_00586b00_shapec02_game** Fn00586b00(Ref_00586b00_shapec02_game** pFirst, Ref_00586b00_shapec02_game** pLast, Ref_00586b00_shapec02_game** pDest)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        if (pFirst != pDest) {
            Ref_00586b00_shapec02_game* pNew = *pFirst;
            Ref_00586b00_shapec02_game* pOld = *pDest;
            if (pNew != pOld) {
                if (pNew) {
                    pNew->S4();
                }
                *pDest = pNew;
                if (pOld) {
                    pOld->S5();
                }
            }
        }
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Ref_00586dc0_shapec02_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
};

// FUNCTION: 0x00586dc0
Ref_00586dc0_shapec02_game** Fn00586dc0(Ref_00586dc0_shapec02_game** pFirst, Ref_00586dc0_shapec02_game** pLast, Ref_00586dc0_shapec02_game** pDest)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        if (pFirst != pDest) {
            Ref_00586dc0_shapec02_game* pNew = *pFirst;
            Ref_00586dc0_shapec02_game* pOld = *pDest;
            if (pNew != pOld) {
                if (pNew) {
                    pNew->S2();
                }
                *pDest = pNew;
                if (pOld) {
                    pOld->S1();
                }
            }
        }
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Ref_0058f020_shapec02_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual void S8();
};

// FUNCTION: 0x0058f020
Ref_0058f020_shapec02_game** Fn0058f020(Ref_0058f020_shapec02_game** pFirst, Ref_0058f020_shapec02_game** pLast, Ref_0058f020_shapec02_game** pDest)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        if (pFirst != pDest) {
            Ref_0058f020_shapec02_game* pNew = *pFirst;
            Ref_0058f020_shapec02_game* pOld = *pDest;
            if (pNew != pOld) {
                if (pNew) {
                    pNew->S7();
                }
                *pDest = pNew;
                if (pOld) {
                    pOld->S8();
                }
            }
        }
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Obj_0053d130_shapec02_game {
    uint32_t mVtbl;
    uint32_t pad[3];
    // STUB: 0x0097564d
    void Base0097564d();
};

// FUNCTION: 0x0053d130
Obj_0053d130_shapec02_game* Fn0053d130()
{
    Obj_0053d130_shapec02_game* p = static_cast<Obj_0053d130_shapec02_game*>(Fn005e55e0(0x10));
    if (p) {
        p->Base0097564d();
        p->mVtbl = 0xa99d34;
        return p;
    }
    return 0;
}

struct Val_005d8af0_shapec02_game {
    uint32_t mKey;
};

struct Node_005d8af0_shapec02_game {
    uint32_t mColor;
    Node_005d8af0_shapec02_game* mpParent;
    Node_005d8af0_shapec02_game* mpLeft;
    Node_005d8af0_shapec02_game* mpRight;
    Val_005d8af0_shapec02_game mValue;
};

struct Cmp_005d8af0_shapec02_game {
    // STUB: 0x005d7c00
    bool Less(const Val_005d8af0_shapec02_game* pA, const Val_005d8af0_shapec02_game* pB);
};

// STUB: 0x0040d5e0
void Fn0040d5e0_005d8af0(Node_005d8af0_shapec02_game* pNode, Node_005d8af0_shapec02_game** ppRoot);

struct View_005d8af0_shapec02_game {
    Node_005d8af0_shapec02_game* mpHeader;
    uint32_t mnCount;
    Cmp_005d8af0_shapec02_game mCmp;
    // STUB: 0x005d88a0
    Node_005d8af0_shapec02_game* Create(const Val_005d8af0_shapec02_game* pValue);
    void Fn005d8af0(Node_005d8af0_shapec02_game** ppOut, Node_005d8af0_shapec02_game* pX, Node_005d8af0_shapec02_game* pY, const Val_005d8af0_shapec02_game* pValue, uint32_t bRight);
};

// FUNCTION: 0x005d8af0
void View_005d8af0_shapec02_game::Fn005d8af0(Node_005d8af0_shapec02_game** ppOut, Node_005d8af0_shapec02_game* pX, Node_005d8af0_shapec02_game* pY, const Val_005d8af0_shapec02_game* pValue, uint32_t bRight)
{
    Node_005d8af0_shapec02_game* pNode;
    if (pY == mpHeader || (bRight == 0 && (pX != 0 || mCmp.Less(pValue, &pY->mValue)))) {
        pNode = Create(pValue);
        pY->mpLeft = pNode;
        if (pY == mpHeader) {
            mpHeader->mpParent = pNode;
            mpHeader->mpRight = pNode;
        } else if (pY == mpHeader->mpLeft) {
            mpHeader->mpLeft = pNode;
        }
    } else {
        pNode = Create(pValue);
        pY->mpRight = pNode;
        if (pY == mpHeader->mpRight) {
            mpHeader->mpRight = pNode;
        }
    }
    pNode->mpParent = pY;
    pNode->mpLeft = 0;
    pNode->mpRight = 0;
    Fn0040d5e0_005d8af0(pNode, &mpHeader->mpParent);
    mnCount++;
    *ppOut = pNode;
}

struct Val_006011a0_shapec02_game {
    uint32_t mKey;
};

struct Node_006011a0_shapec02_game {
    uint32_t mColor;
    Node_006011a0_shapec02_game* mpParent;
    Node_006011a0_shapec02_game* mpLeft;
    Node_006011a0_shapec02_game* mpRight;
    Val_006011a0_shapec02_game mValue;
};

struct Cmp_006011a0_shapec02_game {
    // STUB: 0x006000f0
    bool Less(const Val_006011a0_shapec02_game* pA, const Val_006011a0_shapec02_game* pB);
};

// STUB: 0x0040d5e0
void Fn0040d5e0_006011a0(Node_006011a0_shapec02_game* pNode, Node_006011a0_shapec02_game** ppRoot);

struct View_006011a0_shapec02_game {
    Node_006011a0_shapec02_game* mpHeader;
    uint32_t mnCount;
    Cmp_006011a0_shapec02_game mCmp;
    // STUB: 0x005d88a0
    Node_006011a0_shapec02_game* Create(const Val_006011a0_shapec02_game* pValue);
    void Fn006011a0(Node_006011a0_shapec02_game** ppOut, Node_006011a0_shapec02_game* pX, Node_006011a0_shapec02_game* pY, const Val_006011a0_shapec02_game* pValue, uint32_t bRight);
};

// FUNCTION: 0x006011a0
void View_006011a0_shapec02_game::Fn006011a0(Node_006011a0_shapec02_game** ppOut, Node_006011a0_shapec02_game* pX, Node_006011a0_shapec02_game* pY, const Val_006011a0_shapec02_game* pValue, uint32_t bRight)
{
    Node_006011a0_shapec02_game* pNode;
    if (pY == mpHeader || (bRight == 0 && (pX != 0 || mCmp.Less(pValue, &pY->mValue)))) {
        pNode = Create(pValue);
        pY->mpLeft = pNode;
        if (pY == mpHeader) {
            mpHeader->mpParent = pNode;
            mpHeader->mpRight = pNode;
        } else if (pY == mpHeader->mpLeft) {
            mpHeader->mpLeft = pNode;
        }
    } else {
        pNode = Create(pValue);
        pY->mpRight = pNode;
        if (pY == mpHeader->mpRight) {
            mpHeader->mpRight = pNode;
        }
    }
    pNode->mpParent = pY;
    pNode->mpLeft = 0;
    pNode->mpRight = 0;
    Fn0040d5e0_006011a0(pNode, &mpHeader->mpParent);
    mnCount++;
    *ppOut = pNode;
}

struct Val_00662e40_shapec02_game {
    uint32_t mKey;
};

struct Node_00662e40_shapec02_game {
    uint32_t mColor;
    Node_00662e40_shapec02_game* mpParent;
    Node_00662e40_shapec02_game* mpLeft;
    Node_00662e40_shapec02_game* mpRight;
    Val_00662e40_shapec02_game mValue;
};

struct Cmp_00662e40_shapec02_game {
    // STUB: 0x004b5e10
    bool Less(const Val_00662e40_shapec02_game* pA, const Val_00662e40_shapec02_game* pB);
};

// STUB: 0x0040d5e0
void Fn0040d5e0_00662e40(Node_00662e40_shapec02_game* pNode, Node_00662e40_shapec02_game** ppRoot);

struct View_00662e40_shapec02_game {
    Node_00662e40_shapec02_game* mpHeader;
    uint32_t mnCount;
    Cmp_00662e40_shapec02_game mCmp;
    // STUB: 0x00662b80
    Node_00662e40_shapec02_game* Create(const Val_00662e40_shapec02_game* pValue);
    void Fn00662e40(Node_00662e40_shapec02_game** ppOut, Node_00662e40_shapec02_game* pX, Node_00662e40_shapec02_game* pY, const Val_00662e40_shapec02_game* pValue, uint32_t bRight);
};

// FUNCTION: 0x00662e40
void View_00662e40_shapec02_game::Fn00662e40(Node_00662e40_shapec02_game** ppOut, Node_00662e40_shapec02_game* pX, Node_00662e40_shapec02_game* pY, const Val_00662e40_shapec02_game* pValue, uint32_t bRight)
{
    Node_00662e40_shapec02_game* pNode;
    if (pY == mpHeader || (bRight == 0 && (pX != 0 || mCmp.Less(pValue, &pY->mValue)))) {
        pNode = Create(pValue);
        pY->mpLeft = pNode;
        if (pY == mpHeader) {
            mpHeader->mpParent = pNode;
            mpHeader->mpRight = pNode;
        } else if (pY == mpHeader->mpLeft) {
            mpHeader->mpLeft = pNode;
        }
    } else {
        pNode = Create(pValue);
        pY->mpRight = pNode;
        if (pY == mpHeader->mpRight) {
            mpHeader->mpRight = pNode;
        }
    }
    pNode->mpParent = pY;
    pNode->mpLeft = 0;
    pNode->mpRight = 0;
    Fn0040d5e0_00662e40(pNode, &mpHeader->mpParent);
    mnCount++;
    *ppOut = pNode;
}

struct Val_008057a0_shapec02_game {
    uint32_t mKey;
};

struct Node_008057a0_shapec02_game {
    uint32_t mColor;
    Node_008057a0_shapec02_game* mpParent;
    Node_008057a0_shapec02_game* mpLeft;
    Node_008057a0_shapec02_game* mpRight;
    Val_008057a0_shapec02_game mValue;
};

struct Cmp_008057a0_shapec02_game {
    // STUB: 0x004b5e10
    bool Less(const Val_008057a0_shapec02_game* pA, const Val_008057a0_shapec02_game* pB);
};

// STUB: 0x0040d5e0
void Fn0040d5e0_008057a0(Node_008057a0_shapec02_game* pNode, Node_008057a0_shapec02_game** ppRoot);

struct View_008057a0_shapec02_game {
    Node_008057a0_shapec02_game* mpHeader;
    uint32_t mnCount;
    Cmp_008057a0_shapec02_game mCmp;
    // STUB: 0x00805390
    Node_008057a0_shapec02_game* Create(const Val_008057a0_shapec02_game* pValue);
    void Fn008057a0(Node_008057a0_shapec02_game** ppOut, Node_008057a0_shapec02_game* pX, Node_008057a0_shapec02_game* pY, const Val_008057a0_shapec02_game* pValue, uint32_t bRight);
};

// FUNCTION: 0x008057a0
void View_008057a0_shapec02_game::Fn008057a0(Node_008057a0_shapec02_game** ppOut, Node_008057a0_shapec02_game* pX, Node_008057a0_shapec02_game* pY, const Val_008057a0_shapec02_game* pValue, uint32_t bRight)
{
    Node_008057a0_shapec02_game* pNode;
    if (pY == mpHeader || (bRight == 0 && (pX != 0 || mCmp.Less(pValue, &pY->mValue)))) {
        pNode = Create(pValue);
        pY->mpLeft = pNode;
        if (pY == mpHeader) {
            mpHeader->mpParent = pNode;
            mpHeader->mpRight = pNode;
        } else if (pY == mpHeader->mpLeft) {
            mpHeader->mpLeft = pNode;
        }
    } else {
        pNode = Create(pValue);
        pY->mpRight = pNode;
        if (pY == mpHeader->mpRight) {
            mpHeader->mpRight = pNode;
        }
    }
    pNode->mpParent = pY;
    pNode->mpLeft = 0;
    pNode->mpRight = 0;
    Fn0040d5e0_008057a0(pNode, &mpHeader->mpParent);
    mnCount++;
    *ppOut = pNode;
}

struct Px_00831470_shapec02_game {
    uint32_t v[6];
};

struct Fmt_00831470_shapec02_game {
    uint32_t pad0[4];
    uint32_t mIdx;
    uint32_t pad14[2];
    uint8_t mType;
    uint8_t pad1d[3];
};

typedef void (*Blit_00831470_shapec02_game)(uint32_t a, uint32_t b, Px_00831470_shapec02_game px, Px_00831470_shapec02_game py, Fmt_00831470_shapec02_game fmt);

// GLOBAL: 0x00ac1b44
extern Blit_00831470_shapec02_game* const gTab00ac1b44_shapec02_game[];

struct View_00831470_shapec02_game {
    void Fn00831470(uint32_t a, uint32_t b, const Px_00831470_shapec02_game* pX, const Px_00831470_shapec02_game* pY, const Fmt_00831470_shapec02_game* pFmt, uint32_t nSlot);
};

// FUNCTION: 0x00831470
void View_00831470_shapec02_game::Fn00831470(uint32_t a, uint32_t b, const Px_00831470_shapec02_game* pX, const Px_00831470_shapec02_game* pY, const Fmt_00831470_shapec02_game* pFmt, uint32_t nSlot)
{
    Blit_00831470_shapec02_game* pTab = gTab00ac1b44_shapec02_game[pFmt->mType + pFmt->mIdx * 2];
    pTab[nSlot](a, b, *pX, *pY, *pFmt);
}

struct Px_0083e210_shapec02_game {
    uint32_t v[6];
};

struct Fmt_0083e210_shapec02_game {
    uint32_t pad0[4];
    uint32_t mIdx;
    uint32_t pad14[2];
    uint8_t mType;
    uint8_t pad1d[3];
};

typedef void (*Blit_0083e210_shapec02_game)(uint32_t a, uint32_t b, Px_0083e210_shapec02_game px, Px_0083e210_shapec02_game py, Fmt_0083e210_shapec02_game fmt);

// GLOBAL: 0x00ac1e28
extern Blit_0083e210_shapec02_game* const gTab00ac1e28_shapec02_game[];

struct View_0083e210_shapec02_game {
    void Fn0083e210(uint32_t a, uint32_t b, const Px_0083e210_shapec02_game* pX, const Px_0083e210_shapec02_game* pY, const Fmt_0083e210_shapec02_game* pFmt, uint32_t nSlot);
};

// FUNCTION: 0x0083e210
void View_0083e210_shapec02_game::Fn0083e210(uint32_t a, uint32_t b, const Px_0083e210_shapec02_game* pX, const Px_0083e210_shapec02_game* pY, const Fmt_0083e210_shapec02_game* pFmt, uint32_t nSlot)
{
    Blit_0083e210_shapec02_game* pTab = gTab00ac1e28_shapec02_game[pFmt->mType + pFmt->mIdx * 2];
    pTab[nSlot](a, b, *pX, *pY, *pFmt);
}

struct Px_008480c0_shapec02_game {
    uint32_t v[6];
};

struct Fmt_008480c0_shapec02_game {
    uint32_t pad0[4];
    uint32_t mIdx;
    uint32_t pad14[2];
    uint8_t mType;
    uint8_t pad1d[3];
};

typedef void (*Blit_008480c0_shapec02_game)(uint32_t a, uint32_t b, Px_008480c0_shapec02_game px, Px_008480c0_shapec02_game py, Fmt_008480c0_shapec02_game fmt);

// GLOBAL: 0x00ac2100
extern Blit_008480c0_shapec02_game* const gTab00ac2100_shapec02_game[];

struct View_008480c0_shapec02_game {
    void Fn008480c0(uint32_t a, uint32_t b, const Px_008480c0_shapec02_game* pX, const Px_008480c0_shapec02_game* pY, const Fmt_008480c0_shapec02_game* pFmt, uint32_t nSlot);
};

// FUNCTION: 0x008480c0
void View_008480c0_shapec02_game::Fn008480c0(uint32_t a, uint32_t b, const Px_008480c0_shapec02_game* pX, const Px_008480c0_shapec02_game* pY, const Fmt_008480c0_shapec02_game* pFmt, uint32_t nSlot)
{
    Blit_008480c0_shapec02_game* pTab = gTab00ac2100_shapec02_game[pFmt->mType + pFmt->mIdx * 2];
    pTab[nSlot](a, b, *pX, *pY, *pFmt);
}

struct Px_008551d0_shapec02_game {
    uint32_t v[6];
};

struct Fmt_008551d0_shapec02_game {
    uint32_t pad0[4];
    uint32_t mIdx;
    uint32_t pad14[2];
    uint8_t mType;
    uint8_t pad1d[3];
};

typedef void (*Blit_008551d0_shapec02_game)(uint32_t a, uint32_t b, Px_008551d0_shapec02_game px, Px_008551d0_shapec02_game py, Fmt_008551d0_shapec02_game fmt);

// GLOBAL: 0x00ac23d8
extern Blit_008551d0_shapec02_game* const gTab00ac23d8_shapec02_game[];

struct View_008551d0_shapec02_game {
    void Fn008551d0(uint32_t a, uint32_t b, const Px_008551d0_shapec02_game* pX, const Px_008551d0_shapec02_game* pY, const Fmt_008551d0_shapec02_game* pFmt, uint32_t nSlot);
};

// FUNCTION: 0x008551d0
void View_008551d0_shapec02_game::Fn008551d0(uint32_t a, uint32_t b, const Px_008551d0_shapec02_game* pX, const Px_008551d0_shapec02_game* pY, const Fmt_008551d0_shapec02_game* pFmt, uint32_t nSlot)
{
    Blit_008551d0_shapec02_game* pTab = gTab00ac23d8_shapec02_game[pFmt->mType + pFmt->mIdx * 2];
    pTab[nSlot](a, b, *pX, *pY, *pFmt);
}

struct Elem_008ed280_shapec02_game {
    uint32_t mPos;
    uint32_t mCount;
    uint8_t mBuf[16];
    uint32_t m18;
    uint32_t mMaskA;
    uint32_t mMaskB;
    uint32_t m24;
};

struct Dq_008ed280_shapec02_game {
    uint32_t pad0[4];
    Elem_008ed280_shapec02_game* mpFinish;
    uint32_t pad14;
    Elem_008ed280_shapec02_game* mpLast;
    // STUB: 0x008ecc20
    void PushBackAux(const Elem_008ed280_shapec02_game* pElem);
};

struct View_008ed280_shapec02_game {
    uint8_t pad0[8];
    Elem_008ed280_shapec02_game mRec;
    Dq_008ed280_shapec02_game mDq;
    void Fn008ed280(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ed280 score 44
void View_008ed280_shapec02_game::Fn008ed280(uint32_t a, uint32_t b)
{
    mRec.mPos = 0;
    mRec.mCount++;
    mRec.mBuf[mRec.mPos] = 0x23;
    mRec.mPos++;
    mRec.mBuf[mRec.mPos] = static_cast<uint8_t>(((a - 8) << 3) + b);
    mRec.mPos++;
    mRec.m24 = 1;
    mRec.m18 = 0;
    mRec.mMaskA = (1u << b) | (1u << a);
    mRec.mMaskB = (1u << a) | 0x10000;
    Elem_008ed280_shapec02_game* pFinish = mDq.mpFinish;
    if (pFinish != mDq.mpLast - 1) {
        if (pFinish) {
            *pFinish = mRec;
        }
        mDq.mpFinish++;
    } else {
        mDq.PushBackAux(&mRec);
    }
}
#endif

struct Elem_008ed480_shapec02_game {
    uint32_t mPos;
    uint32_t mCount;
    uint8_t mBuf[16];
    uint32_t m18;
    uint32_t mMaskA;
    uint32_t mMaskB;
    uint32_t m24;
};

struct Dq_008ed480_shapec02_game {
    uint32_t pad0[4];
    Elem_008ed480_shapec02_game* mpFinish;
    uint32_t pad14;
    Elem_008ed480_shapec02_game* mpLast;
    // STUB: 0x008ecc20
    void PushBackAux(const Elem_008ed480_shapec02_game* pElem);
};

struct View_008ed480_shapec02_game {
    uint8_t pad0[8];
    Elem_008ed480_shapec02_game mRec;
    Dq_008ed480_shapec02_game mDq;
    void Fn008ed480(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ed480 score 44
void View_008ed480_shapec02_game::Fn008ed480(uint32_t a, uint32_t b)
{
    mRec.mPos = 0;
    mRec.mCount++;
    mRec.mBuf[mRec.mPos] = 0x33;
    mRec.mPos++;
    mRec.mBuf[mRec.mPos] = static_cast<uint8_t>(((a - 8) << 3) + b);
    mRec.mPos++;
    mRec.m24 = 1;
    mRec.m18 = 0;
    mRec.mMaskA = (1u << b) | (1u << a);
    mRec.mMaskB = (1u << a) | 0x10000;
    Elem_008ed480_shapec02_game* pFinish = mDq.mpFinish;
    if (pFinish != mDq.mpLast - 1) {
        if (pFinish) {
            *pFinish = mRec;
        }
        mDq.mpFinish++;
    } else {
        mDq.PushBackAux(&mRec);
    }
}
#endif

struct Elem_008ed530_shapec02_game {
    uint32_t mPos;
    uint32_t mCount;
    uint8_t mBuf[16];
    uint32_t m18;
    uint32_t mMaskA;
    uint32_t mMaskB;
    uint32_t m24;
};

struct Dq_008ed530_shapec02_game {
    uint32_t pad0[4];
    Elem_008ed530_shapec02_game* mpFinish;
    uint32_t pad14;
    Elem_008ed530_shapec02_game* mpLast;
    // STUB: 0x008ecc20
    void PushBackAux(const Elem_008ed530_shapec02_game* pElem);
};

struct View_008ed530_shapec02_game {
    uint8_t pad0[8];
    Elem_008ed530_shapec02_game mRec;
    Dq_008ed530_shapec02_game mDq;
    void Fn008ed530(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ed530 score 44
void View_008ed530_shapec02_game::Fn008ed530(uint32_t a, uint32_t b)
{
    mRec.mPos = 0;
    mRec.mCount++;
    mRec.mBuf[mRec.mPos] = 0x3;
    mRec.mPos++;
    mRec.mBuf[mRec.mPos] = static_cast<uint8_t>(((a - 8) << 3) + b);
    mRec.mPos++;
    mRec.m24 = 1;
    mRec.m18 = 0;
    mRec.mMaskA = (1u << b) | (1u << a);
    mRec.mMaskB = (1u << a) | 0x10000;
    Elem_008ed530_shapec02_game* pFinish = mDq.mpFinish;
    if (pFinish != mDq.mpLast - 1) {
        if (pFinish) {
            *pFinish = mRec;
        }
        mDq.mpFinish++;
    } else {
        mDq.PushBackAux(&mRec);
    }
}
#endif

struct Elem_008ed990_shapec02_game {
    uint32_t mPos;
    uint32_t mCount;
    uint8_t mBuf[16];
    uint32_t m18;
    uint32_t mMaskA;
    uint32_t mMaskB;
    uint32_t m24;
};

struct Dq_008ed990_shapec02_game {
    uint32_t pad0[4];
    Elem_008ed990_shapec02_game* mpFinish;
    uint32_t pad14;
    Elem_008ed990_shapec02_game* mpLast;
    // STUB: 0x008ecc20
    void PushBackAux(const Elem_008ed990_shapec02_game* pElem);
};

struct View_008ed990_shapec02_game {
    uint8_t pad0[8];
    Elem_008ed990_shapec02_game mRec;
    Dq_008ed990_shapec02_game mDq;
    void Fn008ed990(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ed990 score 44
void View_008ed990_shapec02_game::Fn008ed990(uint32_t a, uint32_t b)
{
    mRec.mPos = 0;
    mRec.mCount++;
    mRec.mBuf[mRec.mPos] = 0x2b;
    mRec.mPos++;
    mRec.mBuf[mRec.mPos] = static_cast<uint8_t>(((a - 8) << 3) + b);
    mRec.mPos++;
    mRec.m24 = 1;
    mRec.m18 = 0;
    mRec.mMaskA = (1u << b) | (1u << a);
    mRec.mMaskB = (1u << a) | 0x10000;
    Elem_008ed990_shapec02_game* pFinish = mDq.mpFinish;
    if (pFinish != mDq.mpLast - 1) {
        if (pFinish) {
            *pFinish = mRec;
        }
        mDq.mpFinish++;
    } else {
        mDq.PushBackAux(&mRec);
    }
}
#endif

// GLOBAL: 0x00b4e740
extern const uint32_t gT00b4e740_shapec02_game[];

// GLOBAL: 0x00b4e744
extern const uint32_t gT00b4e744_shapec02_game[];

// GLOBAL: 0x00b4e748
extern const uint32_t gT00b4e748_shapec02_game[];

// GLOBAL: 0x00b4e74c
extern const uint32_t gT00b4e74c_shapec02_game[];

// GLOBAL: 0x00b4e750
extern const uint32_t gT00b4e750_shapec02_game[];

// GLOBAL: 0x00b4e754
extern const uint32_t gT00b4e754_shapec02_game[];

// GLOBAL: 0x00b4e758
extern const uint32_t gT00b4e758_shapec02_game[];

// GLOBAL: 0x00b4e75c
extern const uint32_t gT00b4e75c_shapec02_game[];

// GLOBAL: 0x00b4ece8
extern const uint32_t gT00b4ece8_shapec02_game[];

// GLOBAL: 0x00b4ecec
extern const uint32_t gT00b4ecec_shapec02_game[];

// GLOBAL: 0x00b4ecf0
extern const uint32_t gT00b4ecf0_shapec02_game[];

// GLOBAL: 0x00b4ecf4
extern const uint32_t gT00b4ecf4_shapec02_game[];

// GLOBAL: 0x00b4ecf8
extern const uint32_t gT00b4ecf8_shapec02_game[];

// GLOBAL: 0x00b4ecfc
extern const uint32_t gT00b4ecfc_shapec02_game[];

// GLOBAL: 0x00b4ed00
extern const uint32_t gT00b4ed00_shapec02_game[];

// GLOBAL: 0x00b4ed04
extern const uint32_t gT00b4ed04_shapec02_game[];

// GLOBAL: 0x00b4f120
extern const uint32_t gT00b4f120_shapec02_game[];

// GLOBAL: 0x00b4f124
extern const uint32_t gT00b4f124_shapec02_game[];

// GLOBAL: 0x00b4f128
extern const uint32_t gT00b4f128_shapec02_game[];

// GLOBAL: 0x00b4f12c
extern const uint32_t gT00b4f12c_shapec02_game[];

// GLOBAL: 0x00b4f130
extern const uint32_t gT00b4f130_shapec02_game[];

// GLOBAL: 0x00b4f134
extern const uint32_t gT00b4f134_shapec02_game[];

// GLOBAL: 0x00b4f138
extern const uint32_t gT00b4f138_shapec02_game[];

// GLOBAL: 0x00b4f13c
extern const uint32_t gT00b4f13c_shapec02_game[];

// GLOBAL: 0x00b4f608
extern const uint32_t gT00b4f608_shapec02_game[];

// GLOBAL: 0x00b4f808
extern const uint32_t gT00b4f808_shapec02_game[];

// GLOBAL: 0x00b4fa08
extern const uint32_t gT00b4fa08_shapec02_game[];

#ifdef OB_DRAFTS
// CLOSE: 0x0080f1e0 score 100
void Fn0080f1e0(const int8_t* pIn, uint32_t* pOut, int32_t nCount)
{
    int32_t n = nCount >> 1;
    do {
    {
        const int8_t* q = pIn + 0;
        uint32_t s = gT00b4f808_shapec02_game[q[1]] + gT00b4f608_shapec02_game[q[0]];
        uint32_t c = gT00b4fa08_shapec02_game[q[3]] + s;
        uint32_t x = gT00b4ece8_shapec02_game[(c >> 11) & 0x1ff] + gT00b4f120_shapec02_game[c >> 23] + gT00b4e740_shapec02_game[c & 0x1ff];
        uint32_t c2 = gT00b4fa08_shapec02_game[q[2]] + s;
        uint32_t y = gT00b4ecf8_shapec02_game[(c2 >> 11) & 0x1ff] + gT00b4f130_shapec02_game[c2 >> 23] + gT00b4e750_shapec02_game[c2 & 0x1ff];
        pOut[0] = (y & 0xffff0000) + (x & 0xffff);
    }
    {
        const int8_t* q = pIn + 4;
        uint32_t s = gT00b4f808_shapec02_game[q[1]] + gT00b4f608_shapec02_game[q[0]];
        uint32_t c = gT00b4fa08_shapec02_game[q[3]] + s;
        uint32_t x = gT00b4ecec_shapec02_game[(c >> 11) & 0x1ff] + gT00b4f124_shapec02_game[c >> 23] + gT00b4e744_shapec02_game[c & 0x1ff];
        uint32_t c2 = gT00b4fa08_shapec02_game[q[2]] + s;
        uint32_t y = gT00b4ecfc_shapec02_game[(c2 >> 11) & 0x1ff] + gT00b4f134_shapec02_game[c2 >> 23] + gT00b4e754_shapec02_game[c2 & 0x1ff];
        pOut[1] = (y & 0xffff0000) + (x & 0xffff);
    }
        pIn += 8;
        pOut += 2;
    } while (--n);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0080f340 score 100
void Fn0080f340(const int8_t* pIn, uint32_t* pOut, int32_t nCount)
{
    int32_t n = nCount >> 1;
    do {
    {
        const int8_t* q = pIn + 0;
        uint32_t s = gT00b4f808_shapec02_game[q[1]] + gT00b4f608_shapec02_game[q[0]];
        uint32_t c = gT00b4fa08_shapec02_game[q[3]] + s;
        uint32_t x = gT00b4ed00_shapec02_game[(c >> 11) & 0x1ff] + gT00b4f138_shapec02_game[c >> 23] + gT00b4e758_shapec02_game[c & 0x1ff];
        uint32_t c2 = gT00b4fa08_shapec02_game[q[2]] + s;
        uint32_t y = gT00b4ecf0_shapec02_game[(c2 >> 11) & 0x1ff] + gT00b4f128_shapec02_game[c2 >> 23] + gT00b4e748_shapec02_game[c2 & 0x1ff];
        pOut[0] = (y & 0xffff0000) + (x & 0xffff);
    }
    {
        const int8_t* q = pIn + 4;
        uint32_t s = gT00b4f808_shapec02_game[q[1]] + gT00b4f608_shapec02_game[q[0]];
        uint32_t c = gT00b4fa08_shapec02_game[q[3]] + s;
        uint32_t x = gT00b4ed04_shapec02_game[(c >> 11) & 0x1ff] + gT00b4f13c_shapec02_game[c >> 23] + gT00b4e75c_shapec02_game[c & 0x1ff];
        uint32_t c2 = gT00b4fa08_shapec02_game[q[2]] + s;
        uint32_t y = gT00b4ecf4_shapec02_game[(c2 >> 11) & 0x1ff] + gT00b4f12c_shapec02_game[c2 >> 23] + gT00b4e74c_shapec02_game[c2 & 0x1ff];
        pOut[1] = (y & 0xffff0000) + (x & 0xffff);
    }
        pIn += 8;
        pOut += 2;
    } while (--n);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0080f4a0 score 100
void Fn0080f4a0(const int8_t* pIn, uint32_t* pOut, int32_t nCount)
{
    int32_t n = nCount >> 1;
    do {
    {
        const int8_t* q = pIn + 0;
        uint32_t s = gT00b4f808_shapec02_game[q[1]] + gT00b4f608_shapec02_game[q[0]];
        uint32_t c = gT00b4fa08_shapec02_game[q[3]] + s;
        uint32_t x = gT00b4ecec_shapec02_game[(c >> 11) & 0x1ff] + gT00b4f124_shapec02_game[c >> 23] + gT00b4e744_shapec02_game[c & 0x1ff];
        uint32_t c2 = gT00b4fa08_shapec02_game[q[2]] + s;
        uint32_t y = gT00b4ecfc_shapec02_game[(c2 >> 11) & 0x1ff] + gT00b4f134_shapec02_game[c2 >> 23] + gT00b4e754_shapec02_game[c2 & 0x1ff];
        pOut[0] = (y & 0xffff0000) + (x & 0xffff);
    }
    {
        const int8_t* q = pIn + 4;
        uint32_t s = gT00b4f808_shapec02_game[q[1]] + gT00b4f608_shapec02_game[q[0]];
        uint32_t c = gT00b4fa08_shapec02_game[q[3]] + s;
        uint32_t x = gT00b4ece8_shapec02_game[(c >> 11) & 0x1ff] + gT00b4f120_shapec02_game[c >> 23] + gT00b4e740_shapec02_game[c & 0x1ff];
        uint32_t c2 = gT00b4fa08_shapec02_game[q[2]] + s;
        uint32_t y = gT00b4ecf8_shapec02_game[(c2 >> 11) & 0x1ff] + gT00b4f130_shapec02_game[c2 >> 23] + gT00b4e750_shapec02_game[c2 & 0x1ff];
        pOut[1] = (y & 0xffff0000) + (x & 0xffff);
    }
        pIn += 8;
        pOut += 2;
    } while (--n);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0080f600 score 100
void Fn0080f600(const int8_t* pIn, uint32_t* pOut, int32_t nCount)
{
    int32_t n = nCount >> 1;
    do {
    {
        const int8_t* q = pIn + 0;
        uint32_t s = gT00b4f808_shapec02_game[q[1]] + gT00b4f608_shapec02_game[q[0]];
        uint32_t c = gT00b4fa08_shapec02_game[q[3]] + s;
        uint32_t x = gT00b4ed04_shapec02_game[(c >> 11) & 0x1ff] + gT00b4f13c_shapec02_game[c >> 23] + gT00b4e75c_shapec02_game[c & 0x1ff];
        uint32_t c2 = gT00b4fa08_shapec02_game[q[2]] + s;
        uint32_t y = gT00b4ecf4_shapec02_game[(c2 >> 11) & 0x1ff] + gT00b4f12c_shapec02_game[c2 >> 23] + gT00b4e74c_shapec02_game[c2 & 0x1ff];
        pOut[0] = (y & 0xffff0000) + (x & 0xffff);
    }
    {
        const int8_t* q = pIn + 4;
        uint32_t s = gT00b4f808_shapec02_game[q[1]] + gT00b4f608_shapec02_game[q[0]];
        uint32_t c = gT00b4fa08_shapec02_game[q[3]] + s;
        uint32_t x = gT00b4ed00_shapec02_game[(c >> 11) & 0x1ff] + gT00b4f138_shapec02_game[c >> 23] + gT00b4e758_shapec02_game[c & 0x1ff];
        uint32_t c2 = gT00b4fa08_shapec02_game[q[2]] + s;
        uint32_t y = gT00b4ecf0_shapec02_game[(c2 >> 11) & 0x1ff] + gT00b4f128_shapec02_game[c2 >> 23] + gT00b4e748_shapec02_game[c2 & 0x1ff];
        pOut[1] = (y & 0xffff0000) + (x & 0xffff);
    }
        pIn += 8;
        pOut += 2;
    } while (--n);
}
#endif

struct Str20_fparse_shapec02_game {
    uint8_t mBytes[20];
};

struct StrVec_fparse_shapec02_game {
    Str20_fparse_shapec02_game* mpBegin;
};

struct IntVec_fparse_shapec02_game {
    int32_t* mpBegin;
    int32_t* mpEnd;
};

struct FloatVec_fparse_shapec02_game {
    float* mpBegin;
    float* mpFinish;
    float* mpCap;
    // STUB: 0x00464180
    float* Erase(float* pFirst, float* pLast);
    // STUB: 0x00676cc0
    void InsertOverflow(float* pPos, const float* pVal, uint8_t* pTag, uint32_t n, bool bAtEnd);
};

// GLOBAL: 0x00b22d2c
extern IntVec_fparse_shapec02_game gB22d2c_fparse_shapec02_game;

// STUB: 0x0067a660
void Fn0067a660(IntVec_fparse_shapec02_game* pOut, const StrVec_fparse_shapec02_game* pStrings, int32_t n);

// STUB: 0x0067bba0
float Fn0067bba0(const Str20_fparse_shapec02_game* pStr);

struct Obj_00599e50_shapec02_game {
    uint8_t pad[0x3a0];
    FloatVec_fparse_shapec02_game mVec;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00599e50 score 42
void Fn00599e50(const StrVec_fparse_shapec02_game* pStrings, Obj_00599e50_shapec02_game* pObj)
{
    Fn0067a660(&gB22d2c_fparse_shapec02_game, pStrings, 1);
    FloatVec_fparse_shapec02_game* pVec = &pObj->mVec;
    pVec->Erase(pVec->mpBegin, pVec->mpFinish);
    for (uint32_t i = 0; i < static_cast<uint32_t>(gB22d2c_fparse_shapec02_game.mpEnd - gB22d2c_fparse_shapec02_game.mpBegin); i++) {
        float f = Fn0067bba0(&pStrings->mpBegin[gB22d2c_fparse_shapec02_game.mpBegin[i]]);
        if (pVec->mpFinish != pVec->mpCap) {
            if (pVec->mpFinish) {
                *pVec->mpFinish = f;
            }
            pVec->mpFinish++;
        } else {
            uint8_t tag;
            pVec->InsertOverflow(pVec->mpFinish, &f, &tag, 1, true);
        }
    }
}
#endif

struct Obj_0059a060_shapec02_game {
    uint8_t pad[0x3e0];
    FloatVec_fparse_shapec02_game mVec;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0059a060 score 42
void Fn0059a060(const StrVec_fparse_shapec02_game* pStrings, Obj_0059a060_shapec02_game* pObj)
{
    Fn0067a660(&gB22d2c_fparse_shapec02_game, pStrings, 1);
    FloatVec_fparse_shapec02_game* pVec = &pObj->mVec;
    pVec->Erase(pVec->mpBegin, pVec->mpFinish);
    for (uint32_t i = 0; i < static_cast<uint32_t>(gB22d2c_fparse_shapec02_game.mpEnd - gB22d2c_fparse_shapec02_game.mpBegin); i++) {
        float f = Fn0067bba0(&pStrings->mpBegin[gB22d2c_fparse_shapec02_game.mpBegin[i]]);
        if (pVec->mpFinish != pVec->mpCap) {
            if (pVec->mpFinish) {
                *pVec->mpFinish = f;
            }
            pVec->mpFinish++;
        } else {
            uint8_t tag;
            pVec->InsertOverflow(pVec->mpFinish, &f, &tag, 1, true);
        }
    }
}
#endif

struct Obj_0059a120_shapec02_game {
    uint8_t pad[0x3ec];
    FloatVec_fparse_shapec02_game mVec;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0059a120 score 42
void Fn0059a120(const StrVec_fparse_shapec02_game* pStrings, Obj_0059a120_shapec02_game* pObj)
{
    Fn0067a660(&gB22d2c_fparse_shapec02_game, pStrings, 1);
    FloatVec_fparse_shapec02_game* pVec = &pObj->mVec;
    pVec->Erase(pVec->mpBegin, pVec->mpFinish);
    for (uint32_t i = 0; i < static_cast<uint32_t>(gB22d2c_fparse_shapec02_game.mpEnd - gB22d2c_fparse_shapec02_game.mpBegin); i++) {
        float f = Fn0067bba0(&pStrings->mpBegin[gB22d2c_fparse_shapec02_game.mpBegin[i]]);
        if (pVec->mpFinish != pVec->mpCap) {
            if (pVec->mpFinish) {
                *pVec->mpFinish = f;
            }
            pVec->mpFinish++;
        } else {
            uint8_t tag;
            pVec->InsertOverflow(pVec->mpFinish, &f, &tag, 1, true);
        }
    }
}
#endif

struct Obj_0059a1e0_shapec02_game {
    uint8_t pad[0x420];
    FloatVec_fparse_shapec02_game mVec;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0059a1e0 score 42
void Fn0059a1e0(const StrVec_fparse_shapec02_game* pStrings, Obj_0059a1e0_shapec02_game* pObj)
{
    Fn0067a660(&gB22d2c_fparse_shapec02_game, pStrings, 1);
    FloatVec_fparse_shapec02_game* pVec = &pObj->mVec;
    pVec->Erase(pVec->mpBegin, pVec->mpFinish);
    for (uint32_t i = 0; i < static_cast<uint32_t>(gB22d2c_fparse_shapec02_game.mpEnd - gB22d2c_fparse_shapec02_game.mpBegin); i++) {
        float f = Fn0067bba0(&pStrings->mpBegin[gB22d2c_fparse_shapec02_game.mpBegin[i]]);
        if (pVec->mpFinish != pVec->mpCap) {
            if (pVec->mpFinish) {
                *pVec->mpFinish = f;
            }
            pVec->mpFinish++;
        } else {
            uint8_t tag;
            pVec->InsertOverflow(pVec->mpFinish, &f, &tag, 1, true);
        }
    }
}
#endif

