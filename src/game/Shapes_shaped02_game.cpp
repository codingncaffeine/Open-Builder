// Shape families of packet shaped02_game (pairs written by hand: one member scored, the other by changing its numbers).
#include <new>
#include "common/types.h"
#include "common/compiler.h"

// ---- 0046f770 / 006b8a10: clear a flag, report true
struct View_0046f770_shaped02_game {
    uint8_t pad0[4];
    bool mbInit;
    bool Fn0046f770();
};

// FUNCTION: 0x0046f770
bool View_0046f770_shaped02_game::Fn0046f770()
{
    if (mbInit) {
        mbInit = false;
    }
    return true;
}

struct View_006b8a10_shaped02_game {
    uint8_t pad0[0xc];
    bool mbInit;
    bool Fn006b8a10();
};

// FUNCTION: 0x006b8a10
bool View_006b8a10_shaped02_game::Fn006b8a10()
{
    if (mbInit) {
        mbInit = false;
    }
    return true;
}

// ---- 0045d2e0 / 00829960: release with a deleting destructor
struct OB_NOVTABLE View_0045d2e0_shaped02_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t pad4[2];
    uint32_t mnRefs;
    uint32_t Fn0045d2e0();
};

// FUNCTION: 0x0045d2e0
uint32_t View_0045d2e0_shaped02_game::Fn0045d2e0()
{
    if (--mnRefs == 0) {
        Destroy(1);
        return 0;
    }
    return mnRefs;
}

struct OB_NOVTABLE View_00829960_shaped02_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void S7() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Fn00829960();
};

// FUNCTION: 0x00829960
uint32_t View_00829960_shaped02_game::Fn00829960()
{
    if (--mnRefs == 0) {
        Destroy(1);
        return 0;
    }
    return mnRefs;
}

// ---- 00473b90 / 00473bb0: a field of the argument, or 0
struct Entry_00473b90_shaped02_game {
    uint32_t pad[9];
    uint32_t mnCtx;
};

struct View_00473b90_shaped02_game {
    uint32_t Fn00473b90(Entry_00473b90_shaped02_game* pEntry);
};

// FUNCTION: 0x00473b90
uint32_t View_00473b90_shaped02_game::Fn00473b90(Entry_00473b90_shaped02_game* pEntry)
{
    if (pEntry) {
        return pEntry->mnCtx;
    }
    return 0;
}

struct Entry_00473bb0_shaped02_game {
    uint32_t pad[9];
};

struct View_00473bb0_shaped02_game {
    uint32_t Fn00473bb0(Entry_00473bb0_shaped02_game* pEntry);
};

// FUNCTION: 0x00473bb0
uint32_t View_00473bb0_shaped02_game::Fn00473bb0(Entry_00473bb0_shaped02_game* pEntry)
{
    if (pEntry) {
        return pEntry->pad[8];
    }
    return 0;
}

// ---- 0049c7e0 / 004bdfb0: not one of two ids
struct View_0049c7e0_shaped02_game {
    bool Fn0049c7e0(uint32_t nId);
};

// FUNCTION: 0x0049c7e0
bool View_0049c7e0_shaped02_game::Fn0049c7e0(uint32_t nId)
{
    if (nId == 0x74758926 || nId == 0x69d25c5f) {
        return false;
    }
    return true;
}

struct View_004bdfb0_shaped02_game {
    bool Fn004bdfb0(uint32_t nId);
};

// FUNCTION: 0x004bdfb0
bool View_004bdfb0_shaped02_game::Fn004bdfb0(uint32_t nId)
{
    if (nId == 0x2890d4de || nId == 0x990b2ea) {
        return false;
    }
    return true;
}

// ---- 0047b850 / 00681f80: key equals the stored pair
struct Key_0047b850_shaped02_game {
    uint32_t mnA;
    uint32_t mnB;
};

struct View_0047b850_shaped02_game {
    uint32_t pad0[2];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t Fn0047b850(Key_0047b850_shaped02_game* pKey);
};

// FUNCTION: 0x0047b850
uint32_t View_0047b850_shaped02_game::Fn0047b850(Key_0047b850_shaped02_game* pKey)
{
    if (pKey->mnA == mnA && pKey->mnB == mnB) {
        return 1;
    }
    return 0;
}

struct View_00681f80_shaped02_game {
    uint32_t pad0;
    uint32_t mnA;
    uint32_t mnB;
    uint32_t Fn00681f80(Key_0047b850_shaped02_game* pKey);
};

// FUNCTION: 0x00681f80
uint32_t View_00681f80_shaped02_game::Fn00681f80(Key_0047b850_shaped02_game* pKey)
{
    if (pKey->mnA == mnA && pKey->mnB == mnB) {
        return 1;
    }
    return 0;
}

// ---- 004a2120 / 004a2670: AddPropWithUsage with a fixed usage
struct View_004a2120_shaped02_game {
    // STUB: 0x004a2010
    void AddPropWithUsage(uint32_t nType, uint32_t pPos, uint32_t nFlag, uint32_t nUsage);
    void Fn004a2120(uint32_t nType, uint32_t pPos, uint32_t nFlag);
    void Fn004a2670(uint32_t nType, uint32_t pPos, uint32_t nFlag);
};

// FUNCTION: 0x004a2120
void View_004a2120_shaped02_game::Fn004a2120(uint32_t nType, uint32_t pPos, uint32_t nFlag)
{
    AddPropWithUsage(nType, pPos, nFlag, 4);
}

// FUNCTION: 0x004a2670
void View_004a2120_shaped02_game::Fn004a2670(uint32_t nType, uint32_t pPos, uint32_t nFlag)
{
    AddPropWithUsage(nType, pPos, nFlag, 2);
}

// ---- 00493700 / 0069e5b0: membership in a hash table at an offset
struct Table_00493700_shaped02_game {
    // STUB: 0x0058efe0
    void* Find(int32_t* pKey);
};

struct View_00493700_shaped02_game {
    uint8_t pad0[0xc];
    Table_00493700_shaped02_game mTable;
    bool Fn00493700(int32_t nKey);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00493700 score 4
bool View_00493700_shaped02_game::Fn00493700(int32_t nKey)
{
    bool bFound = mTable.Find(&nKey) != 0;
    return bFound;
}
#endif

struct View_0069e5b0_shaped02_game {
    uint8_t pad0[0x18];
    Table_00493700_shaped02_game mTable;
    bool Fn0069e5b0(int32_t nKey);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0069e5b0 score 4
bool View_0069e5b0_shaped02_game::Fn0069e5b0(int32_t nKey)
{
    bool bFound = mTable.Find(&nKey) != 0;
    return bFound;
}
#endif

// ---- 0048ea00 / 0048ea30: index of the lowest set bit below a limit
// FUNCTION: 0x0048ea00
uint32_t OB_STDCALL Fn0048ea00(uint32_t nMask)
{
    if (nMask) {
        uint32_t nBit = 1;
        for (int32_t i = 0; i < 5; ++i, nBit <<= 1) {
            if (nMask & nBit) {
                return static_cast<uint32_t>(i);
            }
        }
    }
    return 5;
}

// FUNCTION: 0x0048ea30
uint32_t OB_STDCALL Fn0048ea30(uint32_t nMask)
{
    if (nMask) {
        uint32_t nBit = 1;
        for (int32_t i = 0; i < 4; ++i, nBit <<= 1) {
            if (nMask & nBit) {
                return static_cast<uint32_t>(i);
            }
        }
    }
    return 4;
}

// ---- 004661d0 / 00664510: factories
struct Obj_004661d0_shaped02_game {
    // STUB: 0x0079c560
    Obj_004661d0_shaped02_game* Ctor();
};

// FUNCTION: 0x004661d0
void* Fn004661d0()
{
    void* p = ::operator new(0x128);
    if (p) {
        return static_cast<Obj_004661d0_shaped02_game*>(p)->Ctor();
    }
    return 0;
}

struct Obj_00664510_shaped02_game {
    // STUB: 0x00808900
    Obj_00664510_shaped02_game* Ctor();
};

// FUNCTION: 0x00664510
void* Fn00664510()
{
    void* p = ::operator new(0x10);
    if (p) {
        return static_cast<Obj_00664510_shaped02_game*>(p)->Ctor();
    }
    return 0;
}

// ---- 004642e0 / 00464e70: forward three arguments and the address of a scratch byte
// STUB: 0x00464530
uint32_t Fn00464530(void* a, void* b, void* c, char* pScratch);

// FUNCTION: 0x004642e0
uint32_t Fn004642e0(void* a, void* b, void* c)
{
    char cScratch;
    return Fn00464530(a, b, c, &cScratch);
}

// STUB: 0x004650c0
uint32_t Fn004650c0(void* a, void* b, void* c, char* pScratch);

// FUNCTION: 0x00464e70
uint32_t Fn00464e70(void* a, void* b, void* c)
{
    char cScratch;
    return Fn004650c0(a, b, c, &cScratch);
}

// ---- 0045c590 / 00478aa0: member call with a zeroed scratch byte
struct View_0045c590_shaped02_game {
    // STUB: 0x0045c530
    uint32_t Fn0045c530(uint32_t nArg, char* pScratch);
    uint32_t Fn0045c590(uint32_t nArg);
};

// FUNCTION: 0x0045c590
uint32_t View_0045c590_shaped02_game::Fn0045c590(uint32_t nArg)
{
    char cScratch = 0;
    return Fn0045c530(nArg, &cScratch);
}

struct View_00478aa0_shaped02_game {
    // STUB: 0x004610a0
    uint32_t Fn004610a0(uint32_t nArg, char* pScratch);
    uint32_t Fn00478aa0(uint32_t nArg);
};

// FUNCTION: 0x00478aa0
uint32_t View_00478aa0_shaped02_game::Fn00478aa0(uint32_t nArg)
{
    char cScratch = 0;
    return Fn004610a0(nArg, &cScratch);
}

// ---- 0046fa80 / 006b0fc0: is the id in a global set
struct Iter_0046fa80_shaped02_game {
    void* mpNode;
};

struct Set_0046fa80_shaped02_game {
    void* mpHeader;
    // STUB: 0x00497520
    Iter_0046fa80_shaped02_game* Find(Iter_0046fa80_shaped02_game* pOut, const uint32_t* pKey) const;
};

// GLOBAL: 0x00b2162c
extern Set_0046fa80_shaped02_game gB2162c_shaped02_game;
// GLOBAL: 0x00b49050
extern Set_0046fa80_shaped02_game gB49050_shaped02_game;

struct View_0046fa80_shaped02_game {
    bool Fn0046fa80(uint32_t nId);
    bool Fn006b0fc0(uint32_t nId);
};

// FUNCTION: 0x0046fa80
bool View_0046fa80_shaped02_game::Fn0046fa80(uint32_t nId)
{
    Iter_0046fa80_shaped02_game it;
    gB2162c_shaped02_game.Find(&it, &nId);
    return it.mpNode != gB2162c_shaped02_game.mpHeader;
}

// FUNCTION: 0x006b0fc0
bool View_0046fa80_shaped02_game::Fn006b0fc0(uint32_t nId)
{
    Iter_0046fa80_shaped02_game it;
    gB49050_shaped02_game.Find(&it, &nId);
    return it.mpNode != gB49050_shaped02_game.mpHeader;
}

// ---- 00476aa0 / 0079b820: Release that destroys and frees on the last reference
struct View_00476aa0_shaped02_game {
    uint8_t pad0[0x1c];
    uint32_t mnRefs;
    // STUB: 0x00476900
    void Destroy();
    uint32_t Fn00476aa0();
};

// FUNCTION: 0x00476aa0
uint32_t View_00476aa0_shaped02_game::Fn00476aa0()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy();
    ::operator delete(this);
    return 0;
}

struct View_0079b820_shaped02_game {
    uint8_t pad0[0x3c];
    uint32_t mnRefs;
    // STUB: 0x0079b750
    void Destroy();
    uint32_t Fn0079b820();
};

// FUNCTION: 0x0079b820
uint32_t View_0079b820_shaped02_game::Fn0079b820()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy();
    ::operator delete(this);
    return 0;
}

// ---- 004710a0 / 007e4c10: construct an array of records
struct Elem_004710a0_shaped02_game {
    uint8_t pad[0x38];
};

// STUB: 0x004707d0
void Fn004707d0(Elem_004710a0_shaped02_game* pElem, void* pSrc);

#ifdef OB_DRAFTS
// CLOSE: 0x004710a0 score 17
Elem_004710a0_shaped02_game* Fn004710a0(Elem_004710a0_shaped02_game* pElem, uint32_t nCount, void* pSrc)
{
    for (; nCount > 0; --nCount) {
        Fn004707d0(pElem, pSrc);
        ++pElem;
    }
    return pElem;
}
#endif

struct Elem_007e4c10_shaped02_game {
    uint8_t pad[0x24];
};

// STUB: 0x007cf4c0
void Fn007cf4c0(Elem_007e4c10_shaped02_game* pElem, void* pSrc);

#ifdef OB_DRAFTS
// CLOSE: 0x007e4c10 score 17
Elem_007e4c10_shaped02_game* Fn007e4c10(Elem_007e4c10_shaped02_game* pElem, uint32_t nCount, void* pSrc)
{
    for (; nCount > 0; --nCount) {
        Fn007cf4c0(pElem, pSrc);
        ++pElem;
    }
    return pElem;
}
#endif

// ---- 00473a80 / 0082b8c0: notify a service about the object this sub-object sits in
struct Sub_00473a80_shaped02_game;

struct OB_NOVTABLE Svc_00473a80_shaped02_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void S7() = 0;
    virtual void S8() = 0;
    virtual void Notify(Sub_00473a80_shaped02_game* pObj) = 0;
    virtual void Notify2(Sub_00473a80_shaped02_game* pObj) = 0;
};

// STUB: 0x008793ec
Svc_00473a80_shaped02_game* Fn008793ec();

struct Outer_00473a80_shaped02_game;

struct Sub_00473a80_shaped02_game {
    bool Fn00473a80();
    bool Fn0082b8c0();
};

struct Outer_00473a80_shaped02_game {
    uint32_t mpad;
    Sub_00473a80_shaped02_game mSub;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00473a80 score 5
bool Sub_00473a80_shaped02_game::Fn00473a80()
{
    Outer_00473a80_shaped02_game* pOuter = reinterpret_cast<Outer_00473a80_shaped02_game*>(reinterpret_cast<char*>(this) - 4);
    Fn008793ec()->Notify(&pOuter->mSub);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082b8c0 score 5
bool Sub_00473a80_shaped02_game::Fn0082b8c0()
{
    Outer_00473a80_shaped02_game* pOuter = reinterpret_cast<Outer_00473a80_shaped02_game*>(reinterpret_cast<char*>(this) - 4);
    Fn008793ec()->Notify2(&pOuter->mSub);
    return true;
}
#endif

// ---- 0048ee50 / 005be8a0: small-buffer allocation, inline below a limit
struct View_0048ee50_shaped02_game {
    uint32_t mnSize;
    uint32_t* mpData;
    uint32_t maInline[10];
    void* Fn0048ee50(uint32_t nCount);
};

// FUNCTION: 0x0048ee50
void* View_0048ee50_shaped02_game::Fn0048ee50(uint32_t nCount)
{
    if (mnSize == 0xffffffff) {
        mnSize = nCount;
        if (nCount < 10) {
            return maInline;
        }
        mpData = static_cast<uint32_t*>(::operator new(nCount * 4));
        return mpData;
    }
    return ::operator new(nCount * 4);
}

struct View_005be8a0_shaped02_game {
    uint32_t mnSize;
    uint32_t* mpData;
    uint32_t maInline[32];
    void* Fn005be8a0(uint32_t nCount);
};

// FUNCTION: 0x005be8a0
void* View_005be8a0_shaped02_game::Fn005be8a0(uint32_t nCount)
{
    if (mnSize == 0xffffffff) {
        mnSize = nCount;
        if (nCount < 32) {
            return maInline;
        }
        mpData = static_cast<uint32_t*>(::operator new(nCount * 4));
        return mpData;
    }
    return ::operator new(nCount * 4);
}

// ---- 004a1db0 / 004a1f90: forward a request to the owner with a fixed mode
struct OB_NOVTABLE Owner_004a1db0_shaped02_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void S7() = 0;
    virtual void S8() = 0;
    virtual void S9() = 0;
    virtual void S10() = 0;
    virtual void S11() = 0;
    virtual void S12() = 0;
    virtual void S13() = 0;
    virtual void S14() = 0;
    virtual void S15() = 0;
    virtual void S16() = 0;
    virtual void S17() = 0;
    virtual void S18() = 0;
    virtual void S19() = 0;
    virtual void S20() = 0;
    virtual void S21() = 0;
    virtual void S22() = 0;
    virtual void S23() = 0;
    virtual void S24() = 0;
    virtual void S25() = 0;
    virtual void S26() = 0;
    virtual void S27() = 0;
    virtual void S28() = 0;
    virtual void S29() = 0;
    virtual void S30() = 0;
    virtual void S31() = 0;
    virtual void S32() = 0;
    virtual void S33() = 0;
    virtual void S34() = 0;
    virtual void S35() = 0;
    virtual void S36() = 0;
    virtual void S37() = 0;
    virtual void S38() = 0;
    virtual void S39() = 0;
    virtual bool Query(uint32_t nArg, void* pRect, void* pRect8, void* pParam, int32_t nFlag) = 0;
};

struct Param_004a1db0_shaped02_game {
    uint32_t pad[3];
    uint32_t mnMode;
};

struct Rect_004a1db0_shaped02_game {
    uint32_t pad[2];
    uint32_t mnX;
};

struct View_004a1db0_shaped02_game {
    uint8_t pad0[0x14];
    Owner_004a1db0_shaped02_game* mpOwner;
    uint32_t pad18;
    Param_004a1db0_shaped02_game* mpParam;
    bool Fn004a1db0(uint32_t nArg, Rect_004a1db0_shaped02_game* pRect);
    bool Fn004a1f90(uint32_t nArg, Rect_004a1db0_shaped02_game* pRect);
};

// FUNCTION: 0x004a1db0
bool View_004a1db0_shaped02_game::Fn004a1db0(uint32_t nArg, Rect_004a1db0_shaped02_game* pRect)
{
    if (mpOwner) {
        mpParam->mnMode = 1;
        return mpOwner->Query(nArg, pRect, &pRect->pad[2], mpParam, -1);
    }
    return false;
}

// FUNCTION: 0x004a1f90
bool View_004a1db0_shaped02_game::Fn004a1f90(uint32_t nArg, Rect_004a1db0_shaped02_game* pRect)
{
    if (mpOwner) {
        mpParam->mnMode = 4;
        return mpOwner->Query(nArg, pRect, &pRect->pad[2], mpParam, -1);
    }
    return false;
}

// ---- 004a4310 / 006b0760: walk a resource-manager table, then post the update message
typedef void (OB_STDCALL* Callback_004a4310_shaped02_game)(void*);

struct OB_NOVTABLE Table_004a4310_shaped02_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Release() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void Enumerate(Callback_004a4310_shaped02_game pFn, void* pCtx) = 0;
};

struct OB_NOVTABLE Rm_004a4310_shaped02_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void S7() = 0;
    virtual void S8() = 0;
    virtual void S9() = 0;
    virtual void S10() = 0;
    virtual void S11() = 0;
    virtual void S12() = 0;
    virtual void S13() = 0;
    virtual void S14() = 0;
    virtual void S15() = 0;
    virtual void S16() = 0;
    virtual void S17() = 0;
    virtual uint32_t GetTable(Table_004a4310_shaped02_game** ppOut, uint32_t nType) = 0;
};

// GLOBAL: 0x00b43ca8
extern Rm_004a4310_shaped02_game* gpB43ca8_shaped02_game;

// STUB: 0x004a42a0
void OB_STDCALL Fn004a42a0_shaped02_game(void* pCtx);

// STUB: 0x006b03b0
void OB_STDCALL Fn006b03b0_shaped02_game(void* pCtx);

struct View_004a4310_shaped02_game {
    // STUB: 0x004a2730
    void Post();
    void Fn004a4310();
};

// FUNCTION: 0x004a4310
void View_004a4310_shaped02_game::Fn004a4310()
{
    Rm_004a4310_shaped02_game* pRm = gpB43ca8_shaped02_game;
    if (pRm) {
        Table_004a4310_shaped02_game* pTable = 0;
        if (pRm->GetTable(&pTable, 0x6534284a)) {
            pTable->Enumerate(Fn004a42a0_shaped02_game, this);
            pTable->Release();
        }
    }
    Post();
}

struct View_006b0760_shaped02_game {
    // STUB: 0x006b05e0
    void Post();
    void Fn006b0760();
};

// FUNCTION: 0x006b0760
void View_006b0760_shaped02_game::Fn006b0760()
{
    Rm_004a4310_shaped02_game* pRm = gpB43ca8_shaped02_game;
    if (pRm) {
        Table_004a4310_shaped02_game* pTable = 0;
        if (pRm->GetTable(&pTable, 0x6534284a)) {
            pTable->Enumerate(Fn006b03b0_shaped02_game, this);
            pTable->Release();
        }
    }
    Post();
}

// ---- 004a1f30 / 004a20c0: register an occupant as a prop with a usage
struct OB_NOVTABLE Occ_004a1f30_shaped02_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual bool Slot3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void S7() = 0;
    virtual void S8() = 0;
    virtual void S9() = 0;
    virtual void S10() = 0;
    virtual void S11() = 0;
    virtual void S12() = 0;
    virtual void S13() = 0;
    virtual void S14() = 0;
    virtual void S15() = 0;
    virtual void S16() = 0;
    virtual void S17() = 0;
    virtual void S18() = 0;
    virtual void S19() = 0;
    virtual void S20() = 0;
    virtual void S21() = 0;
    virtual void S22() = 0;
    virtual void S23() = 0;
    virtual void S24() = 0;
    virtual void S25() = 0;
    virtual void S26() = 0;
    virtual void S27() = 0;
    virtual void S28() = 0;
    virtual void S29() = 0;
    virtual void S30() = 0;
    virtual void S31() = 0;
    virtual bool Slot32(uint32_t nFlag) = 0;
};

struct OB_NOVTABLE Owner_004a1f30_shaped02_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void S7() = 0;
    virtual void S8() = 0;
    virtual void S9() = 0;
    virtual void S10() = 0;
    virtual void S11() = 0;
    virtual void S12() = 0;
    virtual void S13() = 0;
    virtual void S14() = 0;
    virtual void S15() = 0;
    virtual void S16() = 0;
    virtual void S17() = 0;
    virtual void S18() = 0;
    virtual void S19() = 0;
    virtual bool Slot20(Occ_004a1f30_shaped02_game* pOcc, uint32_t nFlag) = 0;
};

struct View_004a1f30_shaped02_game {
    uint8_t pad0[0x14];
    Owner_004a1f30_shaped02_game* mpOwner;
    // STUB: 0x004a1f00
    void SetPropUsage(Occ_004a1f30_shaped02_game* pOcc, uint32_t nUsage);
    bool Fn004a1f30(Occ_004a1f30_shaped02_game* pOcc);
    bool Fn004a20c0(void* pLot, Occ_004a1f30_shaped02_game* pOcc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004a1f30 score 2
bool View_004a1f30_shaped02_game::Fn004a1f30(Occ_004a1f30_shaped02_game* pOcc)
{
    bool bResult = false;
    if (mpOwner) {
        if (pOcc->Slot32(1) || (pOcc->Slot3() && mpOwner->Slot20(pOcc, 0))) {
            SetPropUsage(pOcc, 1);
            bResult = true;
        }
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004a20c0 score 2
bool View_004a1f30_shaped02_game::Fn004a20c0(void* /*pLot*/, Occ_004a1f30_shaped02_game* pOcc)
{
    bool bResult = false;
    if (mpOwner) {
        if (pOcc->Slot32(1) || (pOcc->Slot3() && mpOwner->Slot20(pOcc, 0))) {
            SetPropUsage(pOcc, 2);
            bResult = true;
        }
    }
    return bResult;
}
#endif

// ---- 0048ea70 / 0081e800: QueryInterface of a class with a second interface at +4
struct OB_NOVTABLE IfaceA_0048ea70_shaped02_game {
    virtual void S0() = 0;
    virtual void AddRef() = 0;
};

struct OB_NOVTABLE IfaceB_0048ea70_shaped02_game {
    virtual void B0() = 0;
};

struct View_0048ea70_shaped02_game : IfaceA_0048ea70_shaped02_game, IfaceB_0048ea70_shaped02_game {
    bool Fn0048ea70(uint32_t nId, void** ppOut);
    bool Fn0081e800(uint32_t nId, void** ppOut);
};

// FUNCTION: 0x0048ea70
bool View_0048ea70_shaped02_game::Fn0048ea70(uint32_t nId, void** ppOut)
{
    switch (nId) {
    case 0xa9c741b3:
    case 1:
    case 0x452294aa:
        *ppOut = static_cast<IfaceA_0048ea70_shaped02_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppOut = static_cast<IfaceB_0048ea70_shaped02_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x0081e800
bool View_0048ea70_shaped02_game::Fn0081e800(uint32_t nId, void** ppOut)
{
    switch (nId) {
    case 0x2bbda368:
    case 1:
    case 0x2bbda365:
        *ppOut = static_cast<IfaceA_0048ea70_shaped02_game*>(this);
        AddRef();
        return true;
    case 0x452294aa:
        *ppOut = static_cast<IfaceB_0048ea70_shaped02_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

// ---- 00497220 / 004ed930: QueryInterface (3 ids; the middle one answers with the second interface at +4)
struct View_00497220_shaped02_game : IfaceA_0048ea70_shaped02_game, IfaceB_0048ea70_shaped02_game {
    bool Fn00497220(uint32_t nId, void** ppOut);
    bool Fn004ed930(uint32_t nId, void** ppOut);
};

// FUNCTION: 0x00497220
bool View_00497220_shaped02_game::Fn00497220(uint32_t nId, void** ppOut)
{
    switch (nId) {
    case 0x89d2c366:
        *ppOut = static_cast<IfaceA_0048ea70_shaped02_game*>(this);
        AddRef();
        return true;
    case 0x452294aa:
        *ppOut = static_cast<IfaceB_0048ea70_shaped02_game*>(this);
        AddRef();
        return true;
    case 1:
        *ppOut = static_cast<IfaceA_0048ea70_shaped02_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x004ed930
bool View_00497220_shaped02_game::Fn004ed930(uint32_t nId, void** ppOut)
{
    switch (nId) {
    case 0xddcf3bd7:
        *ppOut = static_cast<IfaceA_0048ea70_shaped02_game*>(this);
        AddRef();
        return true;
    case 0x89e51472:
        *ppOut = static_cast<IfaceB_0048ea70_shaped02_game*>(this);
        AddRef();
        return true;
    case 1:
        *ppOut = static_cast<IfaceA_0048ea70_shaped02_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

// ---- 0049aaa0 / 0058a460: allocate and copy-construct a range
// STUB: 0x0090cf54
void* Fn0090cf54_shaped02_game(uint32_t nBytes);

struct Rec_0049aaa0_shaped02_game {
    // STUB: 0x004788d0
    void CopyCtor(const Rec_0049aaa0_shaped02_game* pSrc);
    uint8_t pad[0x34];
};

// FUNCTION: 0x0049aaa0
Rec_0049aaa0_shaped02_game* OB_STDCALL Fn0049aaa0(uint32_t nCount, Rec_0049aaa0_shaped02_game* pFirst, Rec_0049aaa0_shaped02_game* pLast)
{
    Rec_0049aaa0_shaped02_game* pBuf = nCount ? static_cast<Rec_0049aaa0_shaped02_game*>(Fn0090cf54_shaped02_game(nCount * 0x34)) : 0;
    Rec_0049aaa0_shaped02_game* pDst = pBuf;
    for (Rec_0049aaa0_shaped02_game* pSrc = pFirst; pSrc != pLast; ++pSrc) {
        if (pDst) {
            pDst->CopyCtor(pSrc);
        }
        ++pDst;
    }
    return pBuf;
}

struct Rec_0058a460_shaped02_game {
    // STUB: 0x005888a0
    void CopyCtor(const Rec_0058a460_shaped02_game* pSrc);
    uint8_t pad[0x6c];
};

// FUNCTION: 0x0058a460
Rec_0058a460_shaped02_game* OB_STDCALL Fn0058a460(uint32_t nCount, Rec_0058a460_shaped02_game* pFirst, Rec_0058a460_shaped02_game* pLast)
{
    Rec_0058a460_shaped02_game* pBuf = nCount ? static_cast<Rec_0058a460_shaped02_game*>(Fn0090cf54_shaped02_game(nCount * 0x6c)) : 0;
    Rec_0058a460_shaped02_game* pDst = pBuf;
    for (Rec_0058a460_shaped02_game* pSrc = pFirst; pSrc != pLast; ++pSrc) {
        if (pDst) {
            pDst->CopyCtor(pSrc);
        }
        ++pDst;
    }
    return pBuf;
}

// ---- 0048a460 / 00706ea0: sort a range: insertion sort of the head, then the rest
// STUB: 0x0048a100
void Fn0048a100_shaped02_game(int32_t* pFirst, int32_t* pLast, void* pCmp);
// STUB: 0x0047b810
void Fn0047b810_shaped02_game(int32_t* pFirst, int32_t* pLast, int32_t nZero, void* pCmp);

// FUNCTION: 0x0048a460
void Fn0048a460(int32_t* pFirst, int32_t* pLast, void* pCmp)
{
    if (pLast - pFirst > 16) {
        int32_t* pMid = pFirst + 16;
        Fn0048a100_shaped02_game(pFirst, pMid, pCmp);
        Fn0047b810_shaped02_game(pMid, pLast, 0, pCmp);
    } else {
        Fn0048a100_shaped02_game(pFirst, pLast, pCmp);
    }
}

// STUB: 0x007062d0
void Fn007062d0_shaped02_game(int32_t* pFirst, int32_t* pLast, void* pCmp);
// STUB: 0x00704a90
void Fn00704a90_shaped02_game(int32_t* pFirst, int32_t* pLast, int32_t nZero, void* pCmp);

// FUNCTION: 0x00706ea0
void Fn00706ea0(int32_t* pFirst, int32_t* pLast, void* pCmp)
{
    if (pLast - pFirst > 16) {
        int32_t* pMid = pFirst + 16;
        Fn007062d0_shaped02_game(pFirst, pMid, pCmp);
        Fn00704a90_shaped02_game(pMid, pLast, 0, pCmp);
    } else {
        Fn007062d0_shaped02_game(pFirst, pLast, pCmp);
    }
}

// ---- 00473fb0 / 00474020: remove a notification target from a list held at an offset
struct OB_NOVTABLE Target_00473fb0_shaped02_game {
    virtual void S0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct Node_00473fb0_shaped02_game {
    Node_00473fb0_shaped02_game* mpNext;
    Node_00473fb0_shaped02_game* mpPrev;
    Target_00473fb0_shaped02_game* mpTarget;
};

// STUB: 0x0090cf63
void Fn0090cf63_shaped02_game(void* p);

struct View_00473fb0_shaped02_game {
    uint8_t pad0[0x3c];
    Node_00473fb0_shaped02_game* mpHead;
    bool Fn00473fb0(Target_00473fb0_shaped02_game* pTarget);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00473fb0 score 13
bool View_00473fb0_shaped02_game::Fn00473fb0(Target_00473fb0_shaped02_game* pTarget)
{
    if (pTarget) {
        pTarget->AddRef();
    }
    Node_00473fb0_shaped02_game* pHead = mpHead;
    Node_00473fb0_shaped02_game* pNode = pHead->mpNext;
    while (pNode != pHead) {
        if (pNode->mpTarget == pTarget) {
            break;
        }
        pNode = pNode->mpNext;
    }
    if (pTarget) {
        pTarget->Release();
    }
    if (pNode != mpHead) {
        Node_00473fb0_shaped02_game* pNext = pNode->mpNext;
        Node_00473fb0_shaped02_game* pPrev = pNode->mpPrev;
        pPrev->mpNext = pNext;
        pNext->mpPrev = pPrev;
        if (pNode->mpTarget) {
            pNode->mpTarget->Release();
        }
        Fn0090cf63_shaped02_game(pNode);
        return true;
    }
    return false;
}
#endif

struct View_00474020_shaped02_game {
    uint8_t pad0[0x40];
    Node_00473fb0_shaped02_game* mpHead;
    bool Fn00474020(Target_00473fb0_shaped02_game* pTarget);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00474020 score 13
bool View_00474020_shaped02_game::Fn00474020(Target_00473fb0_shaped02_game* pTarget)
{
    if (pTarget) {
        pTarget->AddRef();
    }
    Node_00473fb0_shaped02_game* pHead = mpHead;
    Node_00473fb0_shaped02_game* pNode = pHead->mpNext;
    while (pNode != pHead) {
        if (pNode->mpTarget == pTarget) {
            break;
        }
        pNode = pNode->mpNext;
    }
    if (pTarget) {
        pTarget->Release();
    }
    if (pNode != mpHead) {
        Node_00473fb0_shaped02_game* pNext = pNode->mpNext;
        Node_00473fb0_shaped02_game* pPrev = pNode->mpPrev;
        pPrev->mpNext = pNext;
        pNext->mpPrev = pPrev;
        if (pNode->mpTarget) {
            pNode->mpTarget->Release();
        }
        Fn0090cf63_shaped02_game(pNode);
        return true;
    }
    return false;
}
#endif

// ---- 004a2730 / 006b05e0: post a message built from a pooled message object
struct OB_NOVTABLE Msg_004a2730_shaped02_game {
    virtual void S0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void SetType(uint32_t nType) = 0;
    virtual void S6() = 0;
    virtual void S7() = 0;
    virtual void S8() = 0;
    virtual void S9() = 0;
    virtual void S10() = 0;
    virtual void S11() = 0;
    virtual void SetSender(void* pSender) = 0;
    virtual void S13() = 0;
    virtual void S14() = 0;
    virtual void S15() = 0;
    virtual void SetData(uint32_t nData) = 0;
    virtual void S17() = 0;
    virtual void S18() = 0;
    virtual void S19() = 0;
    virtual void S20() = 0;
    virtual void S21() = 0;
    virtual void S22() = 0;
    virtual void S23() = 0;
    virtual void S24() = 0;
    virtual void S25() = 0;
    virtual void S26() = 0;
    virtual void S27() = 0;
    virtual void S28() = 0;
    virtual void S29() = 0;
    virtual void S30() = 0;
    virtual void S31() = 0;
    virtual void S32() = 0;
    virtual void SetTarget(void* pTarget) = 0;
    // STUB: 0x009134d6
    Msg_004a2730_shaped02_game* Ctor();
};

struct OB_NOVTABLE Ms_004a2730_shaped02_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void Post(Msg_004a2730_shaped02_game* pMsg, uint32_t nFlag) = 0;
};

// GLOBAL: 0x00b43ccc
extern Ms_004a2730_shaped02_game* gpB43ccc_shaped02_game;
// GLOBAL: 0x00b21770
extern uint32_t gB21770_shaped02_game;
// GLOBAL: 0x00b49054
extern uint32_t gB49054_shaped02_game;

// STUB: 0x009133da
void* Fn009133da_shaped02_game(uint32_t nBytes);

struct View_004a2730_shaped02_game {
    void Fn004a2730();
    void Fn006b05e0();
};

// FUNCTION: 0x004a2730
void View_004a2730_shaped02_game::Fn004a2730()
{
    Ms_004a2730_shaped02_game* pMs = gpB43ccc_shaped02_game;
    if (pMs) {
        void* pMem = Fn009133da_shaped02_game(0x2c);
        Msg_004a2730_shaped02_game* pMsg = pMem ? static_cast<Msg_004a2730_shaped02_game*>(pMem)->Ctor() : 0;
        pMsg->AddRef();
        pMsg->SetType(0x896fdc70);
        pMsg->SetSender(this);
        pMsg->SetTarget(this);
        pMsg->SetData(gB21770_shaped02_game);
        pMs->Post(pMsg, 0);
        pMsg->Release();
    }
}

// FUNCTION: 0x006b05e0
void View_004a2730_shaped02_game::Fn006b05e0()
{
    Ms_004a2730_shaped02_game* pMs = gpB43ccc_shaped02_game;
    if (pMs) {
        void* pMem = Fn009133da_shaped02_game(0x2c);
        Msg_004a2730_shaped02_game* pMsg = pMem ? static_cast<Msg_004a2730_shaped02_game*>(pMem)->Ctor() : 0;
        pMsg->AddRef();
        pMsg->SetType(0x87a6277f);
        pMsg->SetSender(this);
        pMsg->SetTarget(this);
        pMsg->SetData(gB49054_shaped02_game);
        pMs->Post(pMsg, 0);
        pMsg->Release();
    }
}
