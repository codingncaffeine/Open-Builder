// Shape pairs of packet shaped04_game.
#include "common/types.h"
#include "common/compiler.h"

// ---- family: return (field == 0)
struct OB_NOVTABLE View_a9e3dc_shaped04_game {
    uint8_t mPad[0x38];
    uint32_t mnValue;
    bool IsZero();
};

// FUNCTION: 0x005773b0
bool View_a9e3dc_shaped04_game::IsZero()
{
    return mnValue == 0;
}

struct View_growth_shaped04_game {
    uint8_t mPad[0xd4];
    uint32_t mnValue;
    bool IsZero();
};

// FUNCTION: 0x006b75d0
bool View_growth_shaped04_game::IsZero()
{
    return mnValue == 0;
}

// ---- family: arg == field
struct View_aa0da0_shaped04_game {
    uint8_t mPad[0x40];
    uint32_t mnValue;
    bool IsValue(uint32_t n);
};

// FUNCTION: 0x005b2a90
bool View_aa0da0_shaped04_game::IsValue(uint32_t n)
{
    return n == mnValue;
}

struct View_a8f79c_shaped04_game {
    uint8_t mPad[0xc];
    uint32_t mnValue;
    bool IsValue(uint32_t n);
};

// FUNCTION: 0x005e9740
bool View_a8f79c_shaped04_game::IsValue(uint32_t n)
{
    return n == mnValue;
}

// ---- family: clear flag
struct View_clear_0053c940_shaped04_game {
    uint8_t mPad[0xc];
    uint8_t mbFlag;
    void Clear();
};

// FUNCTION: 0x0053c940
void View_clear_0053c940_shaped04_game::Clear()
{
    if (mbFlag) {
        mbFlag = 0;
    }
}

struct View_dlg_shaped04_game {
    uint8_t mPad[0x19d];
    uint8_t mbA;
    uint8_t mbB;
    void OnCancel();
};

// FUNCTION: 0x00764830
void View_dlg_shaped04_game::OnCancel()
{
    if (mbA) {
        mbB = 1;
    }
}

// ---- family: tuning params changed
// GLOBAL: 0xb21bdc
extern uint32_t g00b21bdc;
// GLOBAL: 0xb21ca5
extern uint8_t g00b21ca5;
// GLOBAL: 0xb21bc8
extern uint32_t g00b21bc8;
// GLOBAL: 0xb21ca4
extern uint8_t g00b21ca4;

struct OB_NOVTABLE View_ped_shaped04_game {
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
    virtual void SetTuning(uint32_t n) = 0;
    uint8_t mPad[0xa3c - 4];
    uint8_t mbFlag;
    bool HandleTuning();
};

// FUNCTION: 0x00544410
bool View_ped_shaped04_game::HandleTuning()
{
    SetTuning(g00b21bdc);
    mbFlag = g00b21ca5;
    return true;
}

struct OB_NOVTABLE View_veh_shaped04_game {
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
    virtual void SetTuning(uint32_t n) = 0;
    uint8_t mPad[0xa3c - 4];
    uint8_t mbFlag;
    bool HandleTuning();
};

// FUNCTION: 0x0055b410
bool View_veh_shaped04_game::HandleTuning()
{
    SetTuning(g00b21bc8);
    mbFlag = g00b21ca4;
    return true;
}

// ---- family: random path offset
struct Random_shaped04_game {
    // STUB: 0x00913a46
    double Fn00913a46(double low, double high);
};

// GLOBAL: 0x00b21d78
extern Random_shaped04_game gB21d78_shaped04_game;
// GLOBAL: 0x00b21ce8
extern float gB21ce8_shaped04_game;
// GLOBAL: 0x00b21cec
extern float gB21cec_shaped04_game;
// GLOBAL: 0x00b21cf0
extern float gB21cf0_shaped04_game;
// GLOBAL: 0x00b21cf4
extern float gB21cf4_shaped04_game;

struct View_pedpath_shaped04_game {
    uint8_t mPad[0x200];
    float mfOffset;
    void RecalculatePathOffset();
};

// FUNCTION: 0x00544620
void View_pedpath_shaped04_game::RecalculatePathOffset()
{
    mfOffset = static_cast<float>(gB21d78_shaped04_game.Fn00913a46(gB21ce8_shaped04_game, gB21cec_shaped04_game));
}

struct View_vehpath_shaped04_game {
    uint8_t mPad[0x200];
    float mfOffset;
    void RecalculatePathOffset();
};

// FUNCTION: 0x0055b690
void View_vehpath_shaped04_game::RecalculatePathOffset()
{
    mfOffset = static_cast<float>(gB21d78_shaped04_game.Fn00913a46(gB21cf0_shaped04_game, gB21cf4_shaped04_game));
}

// ---- family: QueryInterface with two ids, else the base
struct OB_NOVTABLE View_qiped_shaped04_game {
    virtual void S0() = 0;
    virtual uint32_t AddRef() = 0;
    // STUB: 0x0054d7f0
    bool BaseQueryInterface(uint32_t iid, void** ppOut);
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x00544780
bool View_qiped_shaped04_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid == 0xaa09dc28 || iid == 0x896e75af) {
        *ppOut = this;
        AddRef();
        return true;
    }
    return BaseQueryInterface(iid, ppOut);
}

struct OB_NOVTABLE View_qitrain_shaped04_game {
    virtual void S0() = 0;
    virtual uint32_t AddRef() = 0;
    // STUB: 0x0055b660
    bool BaseQueryInterface(uint32_t iid, void** ppOut);
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x00557220
bool View_qitrain_shaped04_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid == 0x8a41625a || iid == 0x4a416254) {
        *ppOut = this;
        AddRef();
        return true;
    }
    return BaseQueryInterface(iid, ppOut);
}

// ---- family: copy-construct n interface pointers (AddRef through a slot)
struct OB_NOVTABLE IFace_586bb0_shaped04_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void Hold() = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00586bb0 score 10
IFace_586bb0_shaped04_game** Fn00586bb0(IFace_586bb0_shaped04_game** pDest, uint32_t n, IFace_586bb0_shaped04_game* const* pSrc)
{
    if (n > 0) {
        for (uint32_t i = n; i != 0; --i) {
            if (pDest) {
                IFace_586bb0_shaped04_game* p = *pSrc;
                *pDest = p;
                if (p) {
                    p->Hold();
                }
            }
            ++pDest;
        }
    }
    return pDest;
}
#endif

struct OB_NOVTABLE IFace_586cb0_shaped04_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Hold() = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00586cb0 score 10
IFace_586cb0_shaped04_game** Fn00586cb0(IFace_586cb0_shaped04_game** pDest, uint32_t n, IFace_586cb0_shaped04_game* const* pSrc)
{
    if (n > 0) {
        for (uint32_t i = n; i != 0; --i) {
            if (pDest) {
                IFace_586cb0_shaped04_game* p = *pSrc;
                *pDest = p;
                if (p) {
                    p->Hold();
                }
            }
            ++pDest;
        }
    }
    return pDest;
}
#endif

// ---- family: copy a range of interface pointers, AddRef each
struct Elem_586bf0_shaped04_game {
    // STUB: 0x005af940
    uint32_t Fn005af940();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00586bf0 score 6
Elem_586bf0_shaped04_game** Fn00586bf0(Elem_586bf0_shaped04_game** pFirst, Elem_586bf0_shaped04_game** pLast, Elem_586bf0_shaped04_game** pDest)
{
    if (pFirst != pLast) {
        do {
            if (pDest) {
                Elem_586bf0_shaped04_game* p = *pFirst;
                *pDest = p;
                if (p) {
                    p->Fn005af940();
                }
            }
            ++pFirst;
            ++pDest;
        } while (pFirst != pLast);
    }
    return pDest;
}
#endif

struct Elem_5a63b0_shaped04_game {
    // STUB: 0x004664a0
    uint32_t Fn004664a0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x005a63b0 score 6
Elem_5a63b0_shaped04_game** Fn005a63b0(Elem_5a63b0_shaped04_game** pFirst, Elem_5a63b0_shaped04_game** pLast, Elem_5a63b0_shaped04_game** pDest)
{
    if (pFirst != pLast) {
        do {
            if (pDest) {
                Elem_5a63b0_shaped04_game* p = *pFirst;
                *pDest = p;
                if (p) {
                    p->Fn004664a0();
                }
            }
            ++pFirst;
            ++pDest;
        } while (pFirst != pLast);
    }
    return pDest;
}
#endif

// ---- family: release every non-null pointer of a vector, free its storage
// STUB: 0x0090cf63
void Fn0090cf63_shaped04_game(void* p);

struct Item_587850_shaped04_game {
    // STUB: 0x005b1c80
    void Fn005b1c80();
};

struct View_587850_shaped04_game {
    Item_587850_shaped04_game** mpBegin;
    Item_587850_shaped04_game** mpEnd;
    void Destroy();
};

// FUNCTION: 0x00587850
void View_587850_shaped04_game::Destroy()
{
    Item_587850_shaped04_game** p = mpBegin;
    Item_587850_shaped04_game** pEnd = mpEnd;
    for (; p != pEnd; ++p) {
        if (*p) {
            (*p)->Fn005b1c80();
        }
    }
    if (mpBegin) {
        Fn0090cf63_shaped04_game(mpBegin);
    }
}

struct Item_5a8e90_shaped04_game {
    // STUB: 0x008090e0
    void Fn008090e0();
};

struct View_5a8e90_shaped04_game {
    Item_5a8e90_shaped04_game** mpBegin;
    Item_5a8e90_shaped04_game** mpEnd;
    void Destroy();
};

// FUNCTION: 0x005a8e90
void View_5a8e90_shaped04_game::Destroy()
{
    Item_5a8e90_shaped04_game** p = mpBegin;
    Item_5a8e90_shaped04_game** pEnd = mpEnd;
    for (; p != pEnd; ++p) {
        if (*p) {
            (*p)->Fn008090e0();
        }
    }
    if (mpBegin) {
        Fn0090cf63_shaped04_game(mpBegin);
    }
}

// ---- family: emergency vehicle slot 3 (base, then a call with a field)
struct OB_NOVTABLE Target_shaped04_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void Notify(uint32_t n) = 0;
};

// STUB: 0x005d99a0
void Fn005d99a0_shaped04_game(Target_shaped04_game* pTarget, uint32_t nValue);

struct View_532ee0_shaped04_game {
    uint8_t mPad[0x2d8];
    uint32_t mnValue;
    // STUB: 0x0052fa60
    bool BaseSlot03(Target_shaped04_game* pTarget);
    bool Slot03(Target_shaped04_game* pTarget);
};

// FUNCTION: 0x00532ee0
bool View_532ee0_shaped04_game::Slot03(Target_shaped04_game* pTarget)
{
    pTarget->Notify(2);
    bool bResult = BaseSlot03(pTarget);
    if (bResult) {
        Fn005d99a0_shaped04_game(pTarget, mnValue);
    }
    return bResult;
}

struct View_543db0_shaped04_game {
    uint8_t mPad[0x2d0];
    uint32_t mnValue;
    // STUB: 0x0052fa60
    bool BaseSlot03(Target_shaped04_game* pTarget);
    bool Slot03(Target_shaped04_game* pTarget);
};

// FUNCTION: 0x00543db0
bool View_543db0_shaped04_game::Slot03(Target_shaped04_game* pTarget)
{
    pTarget->Notify(2);
    bool bResult = BaseSlot03(pTarget);
    if (bResult) {
        Fn005d99a0_shaped04_game(pTarget, mnValue);
    }
    return bResult;
}

// ---- family: free two buffers of every record of a range
struct Rec_5887d0_shaped04_game {
    void* mpA;
    uint8_t mPad[8];
    void* mpB;
    uint8_t mPad2[0xc];
};

// FUNCTION: 0x005887d0
void Fn005887d0(Rec_5887d0_shaped04_game* pFirst, Rec_5887d0_shaped04_game* pLast)
{
    for (; pFirst != pLast; ++pFirst) {
        if (pFirst->mpB) {
            Fn0090cf63_shaped04_game(pFirst->mpB);
        }
        if (pFirst->mpA) {
            Fn0090cf63_shaped04_game(pFirst->mpA);
        }
    }
}

struct Rec_818450_shaped04_game {
    void* mpA;
    uint8_t mPad[8];
    void* mpB;
    uint8_t mPad2[8];
};

// FUNCTION: 0x00818450
void Fn00818450(Rec_818450_shaped04_game* pFirst, Rec_818450_shaped04_game* pLast)
{
    for (; pFirst != pLast; ++pFirst) {
        if (pFirst->mpB) {
            Fn0090cf63_shaped04_game(pFirst->mpB);
        }
        if (pFirst->mpA) {
            Fn0090cf63_shaped04_game(pFirst->mpA);
        }
    }
}

// ---- family: vector push_back of one dword
struct View_59d6c0_shaped04_game {
    uint32_t mnPad;
    uint32_t* mpFinish;
    uint32_t* mpEnd;
    // STUB: 0x0059d700
    void InsertOverflow(uint32_t* pPos, const uint32_t* pValue, uint8_t* pTag, uint32_t nCount, bool bAtEnd);
    void PushBack(const uint32_t* pValue);
};

// FUNCTION: 0x0059d6c0
void View_59d6c0_shaped04_game::PushBack(const uint32_t* pValue)
{
    uint32_t* pFinish = mpFinish;
    if (pFinish != mpEnd) {
        if (pFinish) {
            *pFinish = *pValue;
        }
        mpFinish += 1;
    } else {
        uint8_t nTag = 0;
        InsertOverflow(pFinish, pValue, &nTag, 1, true);
    }
}

struct View_676c80_shaped04_game {
    uint32_t mnPad;
    uint32_t* mpFinish;
    uint32_t* mpEnd;
    // STUB: 0x00676cc0
    void InsertOverflow(uint32_t* pPos, const uint32_t* pValue, uint8_t* pTag, uint32_t nCount, bool bAtEnd);
    void PushBack(const uint32_t* pValue);
};

// FUNCTION: 0x00676c80
void View_676c80_shaped04_game::PushBack(const uint32_t* pValue)
{
    uint32_t* pFinish = mpFinish;
    if (pFinish != mpEnd) {
        if (pFinish) {
            *pFinish = *pValue;
        }
        mpFinish += 1;
    } else {
        uint8_t nTag = 0;
        InsertOverflow(pFinish, pValue, &nTag, 1, true);
    }
}

// ---- family: locked store of one argument into a field
struct OB_NOVTABLE Lock_5c0c90_shaped04_game {
    virtual void S0() = 0;
    virtual void Enter() = 0;
    virtual void Leave() = 0;
};

struct Shared_5c0c90_shaped04_game {
    uint8_t mbBusy;
    uint8_t mPad[0xf];
    uint32_t mnLockVtbl;
};

struct View_5c0c90_shaped04_game {
    uint8_t mPad[0x14];
    uint32_t mnValue;
    uint8_t mPad2[0x10];
    Shared_5c0c90_shaped04_game* mpShared;
    bool Set(uint32_t nValue);
};

// FUNCTION: 0x005c0c90
bool View_5c0c90_shaped04_game::Set(uint32_t nValue)
{
    Shared_5c0c90_shaped04_game* pShared = mpShared;
    Lock_5c0c90_shaped04_game* pLock = reinterpret_cast<Lock_5c0c90_shaped04_game*>(&pShared->mnLockVtbl);
    pLock->Enter();
    if (pShared->mbBusy) {
        pLock->Leave();
        return false;
    }
    mnValue = nValue;
    pLock->Leave();
    return true;
}

struct View_5c0cd0_shaped04_game {
    uint8_t mPad[0x18];
    uint32_t mnValue;
    uint8_t mPad2[0xc];
    Shared_5c0c90_shaped04_game* mpShared;
    bool Set(uint32_t nValue);
};

// FUNCTION: 0x005c0cd0
bool View_5c0cd0_shaped04_game::Set(uint32_t nValue)
{
    Shared_5c0c90_shaped04_game* pShared = mpShared;
    Lock_5c0c90_shaped04_game* pLock = reinterpret_cast<Lock_5c0c90_shaped04_game*>(&pShared->mnLockVtbl);
    pLock->Enter();
    if (pShared->mbBusy) {
        pLock->Leave();
        return false;
    }
    mnValue = nValue;
    pLock->Leave();
    return true;
}

// ---- family: copy-assign a record with two vectors
struct Vec_587920_shaped04_game {
    uint32_t mData[3];
    // STUB: 0x00464760
    void Assign(const Vec_587920_shaped04_game* pSrc);
};

struct View_587920_shaped04_game {
    uint32_t mnA;
    uint32_t mnB;
    Vec_587920_shaped04_game mVecA;
    Vec_587920_shaped04_game mVecB;
    uint32_t mnC;
    uint32_t mnD;
    View_587920_shaped04_game* Assign(const View_587920_shaped04_game* pSrc);
};

// FUNCTION: 0x00587920
View_587920_shaped04_game* View_587920_shaped04_game::Assign(const View_587920_shaped04_game* pSrc)
{
    mnA = pSrc->mnA;
    mnB = pSrc->mnB;
    mVecA.Assign(&pSrc->mVecA);
    mVecB.Assign(&pSrc->mVecB);
    mnC = pSrc->mnC;
    mnD = pSrc->mnD;
    return this;
}

struct Vec_588080_shaped04_game {
    uint32_t mData[3];
    // STUB: 0x00464430
    void Assign(const Vec_588080_shaped04_game* pSrc);
};

struct View_588080_shaped04_game {
    uint32_t mnA;
    uint32_t mnB;
    Vec_588080_shaped04_game mVecA;
    Vec_588080_shaped04_game mVecB;
    uint32_t mnC;
    uint32_t mnD;
    View_588080_shaped04_game* Assign(const View_588080_shaped04_game* pSrc);
};

// FUNCTION: 0x00588080
View_588080_shaped04_game* View_588080_shaped04_game::Assign(const View_588080_shaped04_game* pSrc)
{
    mnA = pSrc->mnA;
    mnB = pSrc->mnB;
    mVecA.Assign(&pSrc->mVecA);
    mVecB.Assign(&pSrc->mVecB);
    mnC = pSrc->mnC;
    mnD = pSrc->mnD;
    return this;
}

// ---- family: ShouldCollide, no hit in a list then the base
// STUB: 0x004696c0
void** Fn004696c0_shaped04_game(void** pFirst, void** pLast, void* const& rValue, void* const& rTag);

struct View_556260_shaped04_game {
    uint8_t mPad[0x2c4];
    void** mpBegin;
    void** mpEnd;
    // STUB: 0x005059c0
    bool BaseShouldCollide(void* pOther);
    bool ShouldCollide(void* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00556260 score 20
bool View_556260_shaped04_game::ShouldCollide(void* pOther)
{
    void** pEnd = mpEnd;
    void** pBegin = mpBegin;
    if (Fn004696c0_shaped04_game(pBegin, pEnd, pOther, pOther) == pEnd) {
        return BaseShouldCollide(pOther);
    }
    return false;
}
#endif

struct View_558dc0_shaped04_game {
    uint8_t mPad[0x2d0];
    void** mpBegin;
    void** mpEnd;
    // STUB: 0x005059c0
    bool BaseShouldCollide(void* pOther);
    bool ShouldCollide(void* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00558dc0 score 20
bool View_558dc0_shaped04_game::ShouldCollide(void* pOther)
{
    void** pEnd = mpEnd;
    void** pBegin = mpBegin;
    if (Fn004696c0_shaped04_game(pBegin, pEnd, pOther, pOther) == pEnd) {
        return BaseShouldCollide(pOther);
    }
    return false;
}
#endif

// ---- family: constructor, base then three vtables and a global thrice
// GLOBAL: 0x00b22bdc
extern uint32_t g00b22bdc;
// GLOBAL: 0x00b22d70
extern uint32_t g00b22d70;

struct View_580c20_shaped04_game {
    uint32_t mnVt0;
    uint32_t mnVt4;
    uint32_t mnVt8;
    uint8_t mPad[0x10];
    uint32_t mnVt1c;
    uint8_t mPad2[0x14];
    uint32_t mn34;
    uint32_t mn38;
    uint32_t mn3c;
    // STUB: 0x005e9220
    void Base();
    View_580c20_shaped04_game* Construct();
};

// FUNCTION: 0x00580c20
View_580c20_shaped04_game* View_580c20_shaped04_game::Construct()
{
    Base();
    mnVt0 = 0x00a9ecd8;
    mnVt4 = 0x00a9ecbc;
    mnVt8 = 0x00a9ec58;
    mnVt1c = 0x00a9ec40;
    mn34 = g00b22bdc;
    mn38 = g00b22bdc;
    mn3c = g00b22bdc;
    return this;
}

struct View_5b2a40_shaped04_game {
    uint32_t mnVt0;
    uint32_t mnVt4;
    uint32_t mnVt8;
    uint8_t mPad[0x10];
    uint32_t mnVt1c;
    uint8_t mPad2[0x14];
    uint32_t mn34;
    uint32_t mn38;
    uint32_t mn3c;
    // STUB: 0x005e9220
    void Base();
    View_5b2a40_shaped04_game* Construct();
};

// FUNCTION: 0x005b2a40
View_5b2a40_shaped04_game* View_5b2a40_shaped04_game::Construct()
{
    Base();
    mnVt0 = 0x00aa0da0;
    mnVt4 = 0x00aa0d84;
    mnVt8 = 0x00aa0d20;
    mnVt1c = 0x00aa0d08;
    mn34 = g00b22d70;
    mn38 = g00b22d70;
    mn3c = g00b22d70;
    return this;
}

// ---- family: destructor body, vtable then destroy a sub-object
struct Sub_5b9f40_shaped04_game {
    // STUB: 0x005650a0
    void Fn005650a0();
};

struct View_5b9f40_shaped04_game {
    uint32_t mnVtbl;
    uint8_t mPad[0xc];
    Sub_5b9f40_shaped04_game mSub;
    void Destroy();
};

// FUNCTION: 0x005b9f40
void View_5b9f40_shaped04_game::Destroy()
{
    mnVtbl = 0x00aa0f48;
    mSub.Fn005650a0();
}

struct Sub_5ff150_shaped04_game {
    // STUB: 0x005ff0c0
    void Fn005ff0c0();
};

struct View_5ff150_shaped04_game {
    uint32_t mnVtbl;
    uint32_t mnPad;
    Sub_5ff150_shaped04_game mSub;
    void Destroy();
};

// FUNCTION: 0x005ff150
void View_5ff150_shaped04_game::Destroy()
{
    mnVtbl = 0x00aa6cd8;
    mSub.Fn005ff0c0();
}

// ---- family: factory of a 0x28 object with five vtable values
#include <new>

struct Obj_0057edf0_shaped04_game {
    uint32_t mnVt0;
    uint8_t mPad[4];
    uint32_t mnVt8;
    uint32_t mnVtC;
    uint8_t mPad2[0x14];
    uint32_t mnVt24;
    // STUB: 0x00578160
    void Base();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0057edf0 score 3
uint32_t* Fn0057edf0()
{
    Obj_0057edf0_shaped04_game* p = static_cast<Obj_0057edf0_shaped04_game*>(::operator new(0x28));
    if (p) {
        p->Base();
        p->mnVt24 = 0x00a9e8ec;
        uint32_t* pSub = &p->mnVt8;
        p->mnVt0 = 0x00a9e8cc;
        p->mnVtC = 0x00a9e88c;
        p->mnVt24 = 0x00a9e874;
        *pSub = 0x00a9e89c;
        return pSub;
    }
    return 0;
}
#endif

struct Obj_0057fe00_shaped04_game {
    uint32_t mnVt0;
    uint8_t mPad[4];
    uint32_t mnVt8;
    uint32_t mnVtC;
    uint8_t mPad2[0x14];
    uint32_t mnVt24;
    // STUB: 0x00578160
    void Base();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0057fe00 score 3
uint32_t* Fn0057fe00()
{
    Obj_0057fe00_shaped04_game* p = static_cast<Obj_0057fe00_shaped04_game*>(::operator new(0x28));
    if (p) {
        p->Base();
        p->mnVt24 = 0x00a9e9f0;
        uint32_t* pSub = &p->mnVt8;
        p->mnVt0 = 0x00a9e9c4;
        p->mnVtC = 0x00a9e984;
        p->mnVt24 = 0x00a9e96c;
        *pSub = 0x00a9e994;
        return pSub;
    }
    return 0;
}
#endif

// ---- family: vector push_back of a record (element constructed through a method)
struct Elem_59b4e0_shaped04_game {
    uint8_t mData[0x20];
    // STUB: 0x0059b530
    void Copy(const Elem_59b4e0_shaped04_game* pSrc);
};

struct View_59b4e0_shaped04_game {
    uint32_t mnPad;
    Elem_59b4e0_shaped04_game* mpFinish;
    Elem_59b4e0_shaped04_game* mpEnd;
    // STUB: 0x0059b570
    void InsertOverflow(Elem_59b4e0_shaped04_game* pPos, const Elem_59b4e0_shaped04_game* pValue, uint8_t* pTag, uint32_t nCount, bool bAtEnd);
    void PushBack(const Elem_59b4e0_shaped04_game* pValue);
};

// FUNCTION: 0x0059b4e0
void View_59b4e0_shaped04_game::PushBack(const Elem_59b4e0_shaped04_game* pValue)
{
    Elem_59b4e0_shaped04_game* pFinish = mpFinish;
    if (pFinish != mpEnd) {
        if (pFinish) {
            pFinish->Copy(pValue);
        }
        mpFinish += 1;
    } else {
        uint8_t nTag = 0;
        InsertOverflow(pFinish, pValue, &nTag, 1, true);
    }
}

struct Elem_59bb10_shaped04_game {
    uint8_t mData[0x1c];
    // STUB: 0x0059bb60
    void Copy(const Elem_59bb10_shaped04_game* pSrc);
};

struct View_59bb10_shaped04_game {
    uint32_t mnPad;
    Elem_59bb10_shaped04_game* mpFinish;
    Elem_59bb10_shaped04_game* mpEnd;
    // STUB: 0x0059bba0
    void InsertOverflow(Elem_59bb10_shaped04_game* pPos, const Elem_59bb10_shaped04_game* pValue, uint8_t* pTag, uint32_t nCount, bool bAtEnd);
    void PushBack(const Elem_59bb10_shaped04_game* pValue);
};

// FUNCTION: 0x0059bb10
void View_59bb10_shaped04_game::PushBack(const Elem_59bb10_shaped04_game* pValue)
{
    Elem_59bb10_shaped04_game* pFinish = mpFinish;
    if (pFinish != mpEnd) {
        if (pFinish) {
            pFinish->Copy(pValue);
        }
        mpFinish += 1;
    } else {
        uint8_t nTag = 0;
        InsertOverflow(pFinish, pValue, &nTag, 1, true);
    }
}

// ---- family: hashtable insert without a resize check

struct Node_005bb590_shaped04_game {
    Node_005bb590_shaped04_game* mpNext;
    int32_t mnValue;
};

struct View_005bb590_shaped04_game {
    uint32_t mnPad;
    Node_005bb590_shaped04_game** mpBegin;
    Node_005bb590_shaped04_game** mpEnd;
    uint32_t mnPad2;
    uint32_t mnCount;
    // STUB: 0x004f0940
    void Resize(uint32_t nWanted);
    // STUB: 0x005bb530
    Node_005bb590_shaped04_game* NewNode(const int32_t* pValue);
    int32_t* InsertNoResize(const int32_t* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005bb590 score 23
int32_t* View_005bb590_shaped04_game::InsertNoResize(const int32_t* pValue)
{
    Resize(mnCount + 1);
    uint32_t nBuckets = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t nIndex = static_cast<uint32_t>(*pValue) % nBuckets;
    Node_005bb590_shaped04_game* pFirst = mpBegin[nIndex];
    Node_005bb590_shaped04_game* pNode = NewNode(pValue);
    pNode->mpNext = pFirst;
    mpBegin[nIndex] = pNode;
    mnCount = mnCount + 1;
    return &pNode->mnValue;
}
#endif

struct Node_008bcaf0_shaped04_game {
    Node_008bcaf0_shaped04_game* mpNext;
    int32_t mnValue;
};

struct View_008bcaf0_shaped04_game {
    uint32_t mnPad;
    Node_008bcaf0_shaped04_game** mpBegin;
    Node_008bcaf0_shaped04_game** mpEnd;
    uint32_t mnPad2;
    uint32_t mnCount;
    // STUB: 0x004f0940
    void Resize(uint32_t nWanted);
    // STUB: 0x008bc960
    Node_008bcaf0_shaped04_game* NewNode(const int32_t* pValue);
    int32_t* InsertNoResize(const int32_t* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008bcaf0 score 23
int32_t* View_008bcaf0_shaped04_game::InsertNoResize(const int32_t* pValue)
{
    Resize(mnCount + 1);
    uint32_t nBuckets = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t nIndex = static_cast<uint32_t>(*pValue) % nBuckets;
    Node_008bcaf0_shaped04_game* pFirst = mpBegin[nIndex];
    Node_008bcaf0_shaped04_game* pNode = NewNode(pValue);
    pNode->mpNext = pFirst;
    mpBegin[nIndex] = pNode;
    mnCount = mnCount + 1;
    return &pNode->mnValue;
}
#endif

// ---- family: QueryInterface of two subobjects

struct OB_NOVTABLE QIPrim_00577400_shaped04_game {
    virtual void S0() = 0;
    virtual uint32_t AddRef() = 0;
    uint32_t mnPad;
};
struct QISub8_00577400_shaped04_game {
    uint32_t mnPad;
};
struct QISubC_00577400_shaped04_game {
    uint32_t mnPad;
};

struct OB_NOVTABLE View_00577400_shaped04_game : QIPrim_00577400_shaped04_game, QISub8_00577400_shaped04_game, QISubC_00577400_shaped04_game {
    // STUB: 0x009457c6
    bool BaseQueryInterface(uint32_t iid, void** ppOut);
    bool QueryInterface(uint32_t iid, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00577400 score 22
bool View_00577400_shaped04_game::QueryInterface(uint32_t iid, void** ppOut)
{
    *ppOut = 0;
    void* pResult;
    if (iid == 0x29b02a2c) {
        pResult = static_cast<QISub8_00577400_shaped04_game*>(this);
    } else if (iid == 0x452294aa) {
        pResult = static_cast<QISubC_00577400_shaped04_game*>(this);
    } else {
        pResult = 0;
    }
    *ppOut = pResult;
    if (pResult) {
        AddRef();
        return true;
    }
    return BaseQueryInterface(iid, ppOut);
}
#endif

struct OB_NOVTABLE QIPrim_00577470_shaped04_game {
    virtual void S0() = 0;
    virtual uint32_t AddRef() = 0;
    uint32_t mnPad;
};
struct QISub8_00577470_shaped04_game {
    uint32_t mnPad;
};
struct QISubC_00577470_shaped04_game {
    uint32_t mnPad;
};

struct OB_NOVTABLE View_00577470_shaped04_game : QIPrim_00577470_shaped04_game, QISub8_00577470_shaped04_game, QISubC_00577470_shaped04_game {
    // STUB: 0x009457c6
    bool BaseQueryInterface(uint32_t iid, void** ppOut);
    bool QueryInterface(uint32_t iid, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00577470 score 22
bool View_00577470_shaped04_game::QueryInterface(uint32_t iid, void** ppOut)
{
    *ppOut = 0;
    void* pResult;
    if (iid == 0x021e9cbf) {
        pResult = static_cast<QISub8_00577470_shaped04_game*>(this);
    } else if (iid == 0x452294aa) {
        pResult = static_cast<QISubC_00577470_shaped04_game*>(this);
    } else {
        pResult = 0;
    }
    *ppOut = pResult;
    if (pResult) {
        AddRef();
        return true;
    }
    return BaseQueryInterface(iid, ppOut);
}
#endif

// ---- family: vector erase of a range, release the tail

// STUB: 0x00586d50
Item_587850_shaped04_game** Fn00586d50_shaped04_game(Item_587850_shaped04_game** pA, Item_587850_shaped04_game** pB, Item_587850_shaped04_game** pC, uint8_t* pTag, uint32_t nFlag);

struct View_0058ff20_shaped04_game {
    uint32_t mnPad;
    Item_587850_shaped04_game** mpFinish;
    Item_587850_shaped04_game** Erase(Item_587850_shaped04_game** pA, Item_587850_shaped04_game** pB);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058ff20 score 14
Item_587850_shaped04_game** View_0058ff20_shaped04_game::Erase(Item_587850_shaped04_game** pA, Item_587850_shaped04_game** pB)
{
    uint8_t nTag;
    Item_587850_shaped04_game** pNewEnd = Fn00586d50_shaped04_game(pB, mpFinish, pA, &nTag, 0);
    Item_587850_shaped04_game** pOldEnd = mpFinish;
    for (Item_587850_shaped04_game** p = pNewEnd; p != pOldEnd; ++p) {
        if (*p) {
            (*p)->Fn005b1c80();
        }
    }
    mpFinish = pNewEnd;
    return pB;
}
#endif

// STUB: 0x005a88c0
Item_5a8e90_shaped04_game** Fn005a88c0_shaped04_game(Item_5a8e90_shaped04_game** pA, Item_5a8e90_shaped04_game** pB, Item_5a8e90_shaped04_game** pC, uint8_t* pTag, uint32_t nFlag);

struct View_005a8d40_shaped04_game {
    uint32_t mnPad;
    Item_5a8e90_shaped04_game** mpFinish;
    Item_5a8e90_shaped04_game** Erase(Item_5a8e90_shaped04_game** pA, Item_5a8e90_shaped04_game** pB);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005a8d40 score 14
Item_5a8e90_shaped04_game** View_005a8d40_shaped04_game::Erase(Item_5a8e90_shaped04_game** pA, Item_5a8e90_shaped04_game** pB)
{
    uint8_t nTag;
    Item_5a8e90_shaped04_game** pNewEnd = Fn005a88c0_shaped04_game(pB, mpFinish, pA, &nTag, 0);
    Item_5a8e90_shaped04_game** pOldEnd = mpFinish;
    for (Item_5a8e90_shaped04_game** p = pNewEnd; p != pOldEnd; ++p) {
        if (*p) {
            (*p)->Fn008090e0();
        }
    }
    mpFinish = pNewEnd;
    return pB;
}
#endif

// ---- family: read an object's fields from a stream
struct OB_NOVTABLE Stream_581eb0_shaped04_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void ReadA(void* pOut) = 0;
    virtual void S6() = 0;
    virtual void ReadB(void* pOut) = 0;
    virtual void S8() = 0;
    virtual void ReadC(void* pOut) = 0;
    virtual void S10() = 0;
    virtual void S11() = 0;
    virtual void ReadD(void* pOut) = 0;
};

struct View_581eb0_shaped04_game {
    uint32_t mnPad[3];
    uint32_t mnFlags;
    uint8_t mbA;
    uint8_t mbB;
    uint8_t mPad[2];
    uint32_t mnC;
    void Read(Stream_581eb0_shaped04_game* pStream);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00581eb0 score 6
void View_581eb0_shaped04_game::Read(Stream_581eb0_shaped04_game* pStream)
{
    uint32_t nBits;
    uint32_t nSkip;
    pStream->ReadB(&nSkip);
    pStream->ReadC(&nBits);
    mnFlags = nBits & 0xf;
    pStream->ReadA(&mbA);
    pStream->ReadA(&mbB);
    pStream->ReadD(&mnC);
}
#endif

struct View_5be790_shaped04_game {
    uint32_t mnPad[3];
    uint32_t mnFlags;
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    void Read(Stream_581eb0_shaped04_game* pStream);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005be790 score 6
void View_5be790_shaped04_game::Read(Stream_581eb0_shaped04_game* pStream)
{
    uint32_t nBits;
    uint32_t nSkip;
    pStream->ReadB(&nSkip);
    pStream->ReadC(&nBits);
    mnFlags = nBits & 0x1;
    pStream->ReadC(&mnA);
    pStream->ReadD(&mnB);
    pStream->ReadD(&mnC);
}
#endif

// ---- free five buffers
struct View_583130_shaped04_game {
    uint32_t mnPad[4];
    void* mpA;
    uint32_t mnPad2[2];
    void* mpB;
    uint32_t mnPad3[2];
    void* mpC;
    uint32_t mnPad4[2];
    void* mpD;
    uint32_t mnPad5[2];
    void* mpE;
    void FreeAll();
};

// FUNCTION: 0x00583130
void View_583130_shaped04_game::FreeAll()
{
    if (mpE) {
        Fn0090cf63_shaped04_game(mpE);
    }
    if (mpD) {
        Fn0090cf63_shaped04_game(mpD);
    }
    if (mpC) {
        Fn0090cf63_shaped04_game(mpC);
    }
    if (mpB) {
        Fn0090cf63_shaped04_game(mpB);
    }
    if (mpA) {
        Fn0090cf63_shaped04_game(mpA);
    }
}

// ---- family: QueryInterface, two ids (one with a base-cast pointer), else the base subobject
struct QIPrim_79dce0_shaped04_game {
    virtual void S0() = 0;
    virtual uint32_t AddRef() = 0;
};
struct QISub4_79dce0_shaped04_game {
    uint32_t mnPad;
};
struct QIBase_79dce0_shaped04_game {
    // STUB: 0x00998f83
    bool BaseQueryInterface(uint32_t iid, void** ppOut);
};

struct OB_NOVTABLE View_79dce0_shaped04_game : QIPrim_79dce0_shaped04_game, QISub4_79dce0_shaped04_game {
    uint32_t mnPad2;
    bool QueryInterface(uint32_t iid, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0079dce0 score 26
bool View_79dce0_shaped04_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid == 0x452294aa) {
        *ppOut = static_cast<QISub4_79dce0_shaped04_game*>(this);
        AddRef();
        return true;
    }
    if (iid == 0x67c5bede) {
        *ppOut = this;
        AddRef();
        return true;
    }
    return reinterpret_cast<QIBase_79dce0_shaped04_game*>(reinterpret_cast<uint8_t*>(this) + 8)->BaseQueryInterface(iid, ppOut);
}
#endif

struct QIPrim_5a3b40_shaped04_game {
    virtual void S0() = 0;
    virtual uint32_t AddRef() = 0;
};
struct QISub4_5a3b40_shaped04_game {
    uint32_t mnPad;
};
struct QIBase_5a3b40_shaped04_game {
    // STUB: 0x00975395
    bool BaseQueryInterface(uint32_t iid, void** ppOut);
};

struct OB_NOVTABLE View_5a3b40_shaped04_game : QIPrim_5a3b40_shaped04_game, QISub4_5a3b40_shaped04_game {
    bool QueryInterface(uint32_t iid, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005a3b40 score 26
bool View_5a3b40_shaped04_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid == 0xc97cf5ce) {
        *ppOut = static_cast<QISub4_5a3b40_shaped04_game*>(this);
        AddRef();
        return true;
    }
    if (iid == 0xca51189b) {
        *ppOut = this;
        AddRef();
        return true;
    }
    return reinterpret_cast<QIBase_5a3b40_shaped04_game*>(reinterpret_cast<uint8_t*>(this) + 0x11c)->BaseQueryInterface(iid, ppOut);
}
#endif

// ---- free five buffers (second layout)
struct View_624f70_shaped04_game {
    uint8_t mPad[0x28];
    void* mpA;
    uint8_t mPad2[0x28];
    void* mpB;
    uint8_t mPad3[8];
    void* mpC;
    uint8_t mPad4[8];
    void* mpD;
    uint8_t mPad5[0x30];
    void* mpE;
    void FreeAll();
};

// FUNCTION: 0x00624f70
void View_624f70_shaped04_game::FreeAll()
{
    if (mpE) {
        Fn0090cf63_shaped04_game(mpE);
    }
    if (mpD) {
        Fn0090cf63_shaped04_game(mpD);
    }
    if (mpC) {
        Fn0090cf63_shaped04_game(mpC);
    }
    if (mpB) {
        Fn0090cf63_shaped04_game(mpB);
    }
    if (mpA) {
        Fn0090cf63_shaped04_game(mpA);
    }
}

// ---- family: deque pop_front (destroy the element, step or move to the next node)
struct OB_NOVTABLE Obj_553720_shaped04_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Destroy() = 0;
};

struct Elem_553720_shaped04_game {
    Obj_553720_shaped04_game* mpObj;
    uint8_t mPad[8];
};

struct View_553720_shaped04_game {
    Elem_553720_shaped04_game* mpCur;
    Elem_553720_shaped04_game* mpFirst;
    Elem_553720_shaped04_game* mpLast;
    Elem_553720_shaped04_game** mpNode;
    void PopFront();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00553720 score 28
void View_553720_shaped04_game::PopFront()
{
    Elem_553720_shaped04_game* pLast = mpLast - 1;
    Obj_553720_shaped04_game* pObj = mpCur->mpObj;
    if (mpCur != pLast) {
        if (pObj) {
            pObj->Destroy();
        }
        mpCur = mpCur + 1;
    } else {
        if (pObj) {
            pObj->Destroy();
        }
        if (mpFirst) {
            Fn0090cf63_shaped04_game(mpFirst);
        }
        mpNode = mpNode + 1;
        mpFirst = *mpNode;
        mpLast = mpFirst + 10;
        mpCur = mpFirst;
    }
}
#endif

struct OB_NOVTABLE Obj_55faf0_shaped04_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Destroy() = 0;
};

struct Elem_55faf0_shaped04_game {
    Obj_55faf0_shaped04_game* mpObj;
    uint8_t mPad[4];
};

struct View_55faf0_shaped04_game {
    Elem_55faf0_shaped04_game* mpCur;
    Elem_55faf0_shaped04_game* mpFirst;
    Elem_55faf0_shaped04_game* mpLast;
    Elem_55faf0_shaped04_game** mpNode;
    void PopFront();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0055faf0 score 28
void View_55faf0_shaped04_game::PopFront()
{
    Elem_55faf0_shaped04_game* pLast = mpLast - 1;
    Obj_55faf0_shaped04_game* pObj = mpCur->mpObj;
    if (mpCur != pLast) {
        if (pObj) {
            pObj->Destroy();
        }
        mpCur = mpCur + 1;
    } else {
        if (pObj) {
            pObj->Destroy();
        }
        if (mpFirst) {
            Fn0090cf63_shaped04_game(mpFirst);
        }
        mpNode = mpNode + 1;
        mpFirst = *mpNode;
        mpLast = mpFirst + 16;
        mpCur = mpFirst;
    }
}
#endif

// ---- family: mouse button handlers (flag a drive target unless busy)
struct OB_NOVTABLE Sit_564390_shaped04_game {
    virtual void T0() = 0;
    virtual void T1() = 0;
    virtual void T2() = 0;
    virtual void T3() = 0;
    virtual void T4() = 0;
    virtual void T5() = 0;
    virtual void T6() = 0;
    virtual void T7() = 0;
    virtual void T8() = 0;
    virtual void T9() = 0;
    virtual void T10() = 0;
    virtual void T11() = 0;
    virtual void T12() = 0;
    virtual void T13() = 0;
    virtual void T14() = 0;
    virtual void T15() = 0;
    virtual void T16() = 0;
    virtual void T17() = 0;
    virtual void T18() = 0;
    virtual void T19() = 0;
    virtual void T20() = 0;
    virtual void T21() = 0;
    virtual void T22() = 0;
    virtual void T23() = 0;
    virtual void T24() = 0;
    virtual void T25() = 0;
    virtual void T26() = 0;
    virtual void T27() = 0;
    virtual void T28() = 0;
    virtual void T29() = 0;
    virtual void T30() = 0;
    virtual void T31() = 0;
    virtual bool IsActive() = 0;
};

struct OB_NOVTABLE City_564390_shaped04_game {
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
    virtual void S40() = 0;
    virtual void S41() = 0;
    virtual void S42() = 0;
    virtual void S43() = 0;
    virtual void S44() = 0;
    virtual void S45() = 0;
    virtual void S46() = 0;
    virtual void S47() = 0;
    virtual void S48() = 0;
    virtual Sit_564390_shaped04_game* GetSit() = 0;
};

// GLOBAL: 0x00b43cec
extern City_564390_shaped04_game* gpB43cec_shaped04_game;

struct OB_NOVTABLE Target_564390_shaped04_game {
    virtual void U0() = 0;
    virtual void U1() = 0;
    virtual void U2() = 0;
    virtual void U3() = 0;
    virtual void U4() = 0;
    virtual void U5() = 0;
    virtual void U6() = 0;
    virtual void U7() = 0;
    virtual void U8() = 0;
    virtual void U9() = 0;
    virtual void U10() = 0;
    virtual void U11() = 0;
    virtual void U12() = 0;
    virtual void U13() = 0;
    virtual void U14() = 0;
    virtual void U15() = 0;
    virtual void U16() = 0;
    virtual void U17() = 0;
    virtual void U18() = 0;
    virtual void U19() = 0;
    virtual void U20() = 0;
    virtual void U21() = 0;
    virtual void U22() = 0;
    virtual void U23() = 0;
    virtual void U24() = 0;
    virtual void U25() = 0;
    virtual void U26() = 0;
    virtual void U27() = 0;
    virtual void U28() = 0;
    virtual void U29() = 0;
    virtual void U30() = 0;
    virtual bool HasFlag(uint32_t nFlag) = 0;
    virtual void W32() = 0;
    virtual void W33() = 0;
    virtual void W34() = 0;
    virtual void W35() = 0;
    virtual void W36() = 0;
    virtual void W37() = 0;
    virtual void W38() = 0;
    virtual void W39() = 0;
    virtual void W40() = 0;
    virtual void W41() = 0;
    virtual void W42() = 0;
    virtual void W43() = 0;
    virtual void W44() = 0;
    virtual void W45() = 0;
    virtual void W46() = 0;
    virtual void W47() = 0;
    virtual void W48() = 0;
    virtual void W49() = 0;
    virtual void W50() = 0;
    virtual void W51() = 0;
    virtual void W52() = 0;
    virtual void W53() = 0;
    virtual void W54() = 0;
    virtual void W55() = 0;
    virtual void W56() = 0;
    virtual void W57() = 0;
    virtual void W58() = 0;
    virtual void W59() = 0;
    virtual void SetState(uint32_t nState, uint32_t nValue) = 0;
};

struct View_564390_shaped04_game {
    uint8_t mPad[0x30];
    Target_564390_shaped04_game* mpTarget;
    bool OnMouse(uint32_t nX, uint32_t nY, uint32_t nFlags);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00564390 score 13
bool View_564390_shaped04_game::OnMouse(uint32_t /*nX*/, uint32_t /*nY*/, uint32_t /*nFlags*/)
{
    if (mpTarget) {
        if (!mpTarget->HasFlag(0x8000000)) {
            if (!mpTarget->HasFlag(1)) {
                if (!gpB43cec_shaped04_game->GetSit()->IsActive()) {
                    mpTarget->SetState(8, 1);
                }
            }
        }
    }
    return true;
}
#endif

struct View_5643f0_shaped04_game {
    uint8_t mPad[0x30];
    Target_564390_shaped04_game* mpTarget;
    bool OnMouse(uint32_t nX, uint32_t nY, uint32_t nFlags);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005643f0 score 13
bool View_5643f0_shaped04_game::OnMouse(uint32_t /*nX*/, uint32_t /*nY*/, uint32_t /*nFlags*/)
{
    if (mpTarget) {
        if (!mpTarget->HasFlag(0x8000000)) {
            if (!mpTarget->HasFlag(1)) {
                if (!gpB43cec_shaped04_game->GetSit()->IsActive()) {
                    mpTarget->SetState(8, 0);
                }
            }
        }
    }
    return true;
}
#endif

// ---- family: assign a range of reference-counted pointers

struct Obj_00586d50_shaped04_game {
    // STUB: 0x005af940
    void Fn005af940();
    // STUB: 0x005b1c80
    void Fn005b1c80();
};

// FUNCTION: 0x00586d50
Obj_00586d50_shaped04_game** Fn00586d50(Obj_00586d50_shaped04_game** pFirst, Obj_00586d50_shaped04_game** pLast, Obj_00586d50_shaped04_game** pDest)
{
    for (int32_t n = static_cast<int32_t>(pLast - pFirst); n > 0; --n) {
        if (pFirst != pDest) {
            Obj_00586d50_shaped04_game* pNew = *pFirst;
            Obj_00586d50_shaped04_game* pOld = *pDest;
            if (pNew != pOld) {
                if (pNew) {
                    pNew->Fn005af940();
                }
                *pDest = pNew;
                if (pOld) {
                    pOld->Fn005b1c80();
                }
            }
        }
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Obj_005a88c0_shaped04_game {
    // STUB: 0x004664a0
    void Fn004664a0();
    // STUB: 0x008090e0
    void Fn008090e0();
};

// FUNCTION: 0x005a88c0
Obj_005a88c0_shaped04_game** Fn005a88c0(Obj_005a88c0_shaped04_game** pFirst, Obj_005a88c0_shaped04_game** pLast, Obj_005a88c0_shaped04_game** pDest)
{
    for (int32_t n = static_cast<int32_t>(pLast - pFirst); n > 0; --n) {
        if (pFirst != pDest) {
            Obj_005a88c0_shaped04_game* pNew = *pFirst;
            Obj_005a88c0_shaped04_game* pOld = *pDest;
            if (pNew != pOld) {
                if (pNew) {
                    pNew->Fn004664a0();
                }
                *pDest = pNew;
                if (pOld) {
                    pOld->Fn008090e0();
                }
            }
        }
        ++pFirst;
        ++pDest;
    }
    return pDest;
}
