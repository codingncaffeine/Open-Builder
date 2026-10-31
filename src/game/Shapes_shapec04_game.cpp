// Shape families of packet shapec04_game, written by scratch/s17/gen/shapec04_game/*.py.
#include "common/types.h"
#include "common/compiler.h"

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
    // STUB: 0x0090cf54
    void* __stl_new(uint32_t size);
}

// STUB: 0x005e5620
void Fn005e5620(void* p);

struct PoolNode_shapec04_game {
    PoolNode_shapec04_game* mpNext;
    PoolNode_shapec04_game* mpPrev;
};

struct PoolAlloc_shapec04_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual PoolNode_shapec04_game* Alloc(uint32_t size);
};

struct PoolRef_shapec04_game {
    PoolAlloc_shapec04_game* mp;
    // STUB: 0x00411870
    void Release();
};

struct PoolList_shapec04_game {
    PoolNode_shapec04_game* mpHeader;
    // STUB: 0x00413fe0
    void Clear();
};

struct Svc_shapec04_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void Get(uint32_t a, uint32_t b, PoolAlloc_shapec04_game** ppOut);
};

// GLOBAL: 0x00b207e4
extern PoolAlloc_shapec04_game* gpB207e4;

// STUB: 0x008793ec
Svc_shapec04_game* Fn008793ec();

struct View_004a3850_shapec04_game {
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
    virtual bool Collect(PoolList_shapec04_game* pList, uint32_t arg);
    // STUB: 0x004a28a0
    void RemoveAll(PoolList_shapec04_game* pList);
    bool Fn(uint32_t arg);
};

// FUNCTION: 0x004a3850
bool View_004a3850_shapec04_game::Fn(uint32_t arg)
{
    PoolList_shapec04_game list;
    list.mpHeader = 0;
    if (!gpB207e4) {
        PoolRef_shapec04_game ref;
        ref.mp = 0;
        Svc_shapec04_game* pSvc = Fn008793ec();
        if (pSvc) {
            pSvc->Get(0x3ae4bea3, 0x3ae4beab, &ref.mp);
        }
        gpB207e4 = ref.mp;
        ref.Release();
    }
    PoolNode_shapec04_game* pNode = gpB207e4->Alloc(0xc);
    pNode->mpNext = pNode;
    pNode->mpPrev = pNode;
    list.mpHeader = pNode;
    if (Collect(&list, arg)) {
        RemoveAll(&list);
    }
    list.Clear();
    return true;
}

struct View_004a38f0_shapec04_game {
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
    virtual bool Collect(PoolList_shapec04_game* pList, uint32_t arg);
    // STUB: 0x004a28a0
    void RemoveAll(PoolList_shapec04_game* pList);
    bool Fn(uint32_t arg);
};

// FUNCTION: 0x004a38f0
bool View_004a38f0_shapec04_game::Fn(uint32_t arg)
{
    PoolList_shapec04_game list;
    list.mpHeader = 0;
    if (!gpB207e4) {
        PoolRef_shapec04_game ref;
        ref.mp = 0;
        Svc_shapec04_game* pSvc = Fn008793ec();
        if (pSvc) {
            pSvc->Get(0x3ae4bea3, 0x3ae4beab, &ref.mp);
        }
        gpB207e4 = ref.mp;
        ref.Release();
    }
    PoolNode_shapec04_game* pNode = gpB207e4->Alloc(0xc);
    pNode->mpNext = pNode;
    pNode->mpPrev = pNode;
    list.mpHeader = pNode;
    if (Collect(&list, arg)) {
        RemoveAll(&list);
    }
    list.Clear();
    return true;
}

struct View_004a3a50_shapec04_game {
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
    virtual bool Collect(PoolList_shapec04_game* pList, uint32_t arg);
    // STUB: 0x004a28a0
    void RemoveAll(PoolList_shapec04_game* pList);
    bool Fn(uint32_t arg);
};

// FUNCTION: 0x004a3a50
bool View_004a3a50_shapec04_game::Fn(uint32_t arg)
{
    PoolList_shapec04_game list;
    list.mpHeader = 0;
    if (!gpB207e4) {
        PoolRef_shapec04_game ref;
        ref.mp = 0;
        Svc_shapec04_game* pSvc = Fn008793ec();
        if (pSvc) {
            pSvc->Get(0x3ae4bea3, 0x3ae4beab, &ref.mp);
        }
        gpB207e4 = ref.mp;
        ref.Release();
    }
    PoolNode_shapec04_game* pNode = gpB207e4->Alloc(0xc);
    pNode->mpNext = pNode;
    pNode->mpPrev = pNode;
    list.mpHeader = pNode;
    if (Collect(&list, arg)) {
        RemoveAll(&list);
    }
    list.Clear();
    return true;
}

struct Probe_shapec04_game {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
    virtual void S1();
    virtual void Release();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual void S8();
    virtual void S9();
    virtual void S10();
    virtual uint32_t GetKind();
};

struct Triple_shapec04_game {
    uint32_t a;
    uint32_t b;
    uint32_t c;
    Triple_shapec04_game()
    {
        c = 0;
        b = 0;
        a = 0;
    }
};

struct Rec_shapec04_game {
    uint32_t mKind;
    uint32_t m4;
    uint16_t m8;
    uint8_t ma;
    uint32_t mc;
    uint32_t m10;
    uint32_t m14;
    uint8_t m18;
    uint32_t m1c;
    Triple_shapec04_game mTriple;
    uint32_t m2c;
    uint32_t m30;
    uint32_t m34;
    uint32_t m38;
    uint32_t m3c;
    Rec_shapec04_game()
        : mKind(0), m4(0), m8(0), ma(0), mc(0), m10(0), m14(0), m18(0), m1c(0), m30(0), m34(0), m38(0), m3c(0)
    {
    }
    // STUB: 0x004e41f0
    void Fill(uint32_t kind);
    // STUB: 0x00459220
    void Dtor();
};

struct View_004e4260_shapec04_game {
    uint32_t pad0;
    Probe_shapec04_game* mpLast;
    bool mbFlag;
    bool Slot05(Probe_shapec04_game* pObj);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004e4260 score 10
bool View_004e4260_shapec04_game::Slot05(Probe_shapec04_game* pObj)
{
    if (pObj == mpLast) {
        return mbFlag;
    }
    Probe_shapec04_game* pProbe = 0;
    if (!pObj->QueryInterface(0x87dda3a9, reinterpret_cast<void**>(&pProbe))) {
        mpLast = pObj;
        mbFlag = false;
        if (pProbe) {
            pProbe->Release();
        }
        return false;
    }
    Rec_shapec04_game info;
    info.Fill(pProbe->GetKind());
    mpLast = pObj;
    if (info.mKind == 2) {
        mbFlag = true;
        info.Dtor();
        if (pProbe) {
            pProbe->Release();
        }
        return true;
    }
    mbFlag = false;
    info.Dtor();
    if (pProbe) {
        pProbe->Release();
    }
    return false;
}
#endif

struct View_004e45a0_shapec04_game {
    uint32_t pad0;
    Probe_shapec04_game* mpLast;
    bool mbFlag;
    bool Slot05(Probe_shapec04_game* pObj);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004e45a0 score 10
bool View_004e45a0_shapec04_game::Slot05(Probe_shapec04_game* pObj)
{
    if (pObj == mpLast) {
        return mbFlag;
    }
    Probe_shapec04_game* pProbe = 0;
    if (!pObj->QueryInterface(0x87dda3a9, reinterpret_cast<void**>(&pProbe))) {
        mpLast = pObj;
        mbFlag = false;
        if (pProbe) {
            pProbe->Release();
        }
        return false;
    }
    Rec_shapec04_game info;
    info.Fill(pProbe->GetKind());
    mpLast = pObj;
    if (info.mKind == 5) {
        mbFlag = true;
        info.Dtor();
        if (pProbe) {
            pProbe->Release();
        }
        return true;
    }
    mbFlag = false;
    info.Dtor();
    if (pProbe) {
        pProbe->Release();
    }
    return false;
}
#endif

struct View_004e48a0_shapec04_game {
    uint32_t pad0;
    Probe_shapec04_game* mpLast;
    bool mbFlag;
    bool Slot05(Probe_shapec04_game* pObj);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004e48a0 score 10
bool View_004e48a0_shapec04_game::Slot05(Probe_shapec04_game* pObj)
{
    if (pObj == mpLast) {
        return mbFlag;
    }
    Probe_shapec04_game* pProbe = 0;
    if (!pObj->QueryInterface(0x87dda3a9, reinterpret_cast<void**>(&pProbe))) {
        mpLast = pObj;
        mbFlag = false;
        if (pProbe) {
            pProbe->Release();
        }
        return false;
    }
    Rec_shapec04_game info;
    info.Fill(pProbe->GetKind());
    mpLast = pObj;
    if (info.mKind == 1) {
        mbFlag = true;
        info.Dtor();
        if (pProbe) {
            pProbe->Release();
        }
        return true;
    }
    mbFlag = false;
    info.Dtor();
    if (pProbe) {
        pProbe->Release();
    }
    return false;
}
#endif

struct Elem_00479910_shapec04_game {
    uint8_t d[0x34];
    // STUB: 0x004788d0
    void Copy(const Elem_00479910_shapec04_game* pSrc);
};

// STUB: 0x004789c0
Elem_00479910_shapec04_game* Fn004789c0Move(Elem_00479910_shapec04_game* pFirst, Elem_00479910_shapec04_game* pLast, Elem_00479910_shapec04_game* pDst, const bool* pTag);

struct View_00479910_shapec04_game {
    Elem_00479910_shapec04_game* mpBegin;
    Elem_00479910_shapec04_game* mpFinish;
    Elem_00479910_shapec04_game* mpCap;
    // STUB: 0x00479760
    void Free();
    void Fn(Elem_00479910_shapec04_game* pPos, const Elem_00479910_shapec04_game* pVal, const void* pTag, uint32_t nFill, bool bAtEnd);
};

// FUNCTION: 0x00479910
void View_00479910_shapec04_game::Fn(Elem_00479910_shapec04_game* pPos, const Elem_00479910_shapec04_game* pVal, const void* /*pTag*/, uint32_t nFill, bool bAtEnd)
{
    uint32_t nOld = static_cast<uint32_t>(mpFinish - mpBegin);
    const uint32_t* pMax = (nOld < nFill) ? &nFill : &nOld;
    uint32_t nNew = *pMax + nOld;
    Elem_00479910_shapec04_game* pBuf = nNew ? static_cast<Elem_00479910_shapec04_game*>(_STL::__stl_new(nNew * 0x34)) : 0;
    Elem_00479910_shapec04_game* pDst = pBuf;
    for (Elem_00479910_shapec04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t nLeft = nFill;
    if (nLeft == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; nLeft > 0; --nLeft) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!bAtEnd) {
        pDst = Fn004789c0Move(pPos, mpFinish, pDst, &bAtEnd);
    }
    Free();
    mpFinish = pDst;
    mpCap = pBuf + nNew;
    mpBegin = pBuf;
}

struct Elem_005905c0_shapec04_game {
    uint8_t d[0x44];
    // STUB: 0x0058e020
    void Copy(const Elem_005905c0_shapec04_game* pSrc);
};

// STUB: 0x0058ef60
Elem_005905c0_shapec04_game* Fn0058ef60Move(Elem_005905c0_shapec04_game* pFirst, Elem_005905c0_shapec04_game* pLast, Elem_005905c0_shapec04_game* pDst, const bool* pTag);

struct View_005905c0_shapec04_game {
    Elem_005905c0_shapec04_game* mpBegin;
    Elem_005905c0_shapec04_game* mpFinish;
    Elem_005905c0_shapec04_game* mpCap;
    // STUB: 0x00590040
    void Free();
    void Fn(Elem_005905c0_shapec04_game* pPos, const Elem_005905c0_shapec04_game* pVal, const void* pTag, uint32_t nFill, bool bAtEnd);
};

// FUNCTION: 0x005905c0
void View_005905c0_shapec04_game::Fn(Elem_005905c0_shapec04_game* pPos, const Elem_005905c0_shapec04_game* pVal, const void* /*pTag*/, uint32_t nFill, bool bAtEnd)
{
    uint32_t nOld = static_cast<uint32_t>(mpFinish - mpBegin);
    const uint32_t* pMax = (nOld < nFill) ? &nFill : &nOld;
    uint32_t nNew = *pMax + nOld;
    Elem_005905c0_shapec04_game* pBuf = nNew ? static_cast<Elem_005905c0_shapec04_game*>(_STL::__stl_new(nNew * 0x44)) : 0;
    Elem_005905c0_shapec04_game* pDst = pBuf;
    for (Elem_005905c0_shapec04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t nLeft = nFill;
    if (nLeft == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; nLeft > 0; --nLeft) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!bAtEnd) {
        pDst = Fn0058ef60Move(pPos, mpFinish, pDst, &bAtEnd);
    }
    Free();
    mpFinish = pDst;
    mpCap = pBuf + nNew;
    mpBegin = pBuf;
}

struct Elem_0059edc0_shapec04_game {
    uint8_t d[0x6c];
    // STUB: 0x005888a0
    void Copy(const Elem_0059edc0_shapec04_game* pSrc);
};

// STUB: 0x00589490
Elem_0059edc0_shapec04_game* Fn00589490Move(Elem_0059edc0_shapec04_game* pFirst, Elem_0059edc0_shapec04_game* pLast, Elem_0059edc0_shapec04_game* pDst, const bool* pTag);

struct View_0059edc0_shapec04_game {
    Elem_0059edc0_shapec04_game* mpBegin;
    Elem_0059edc0_shapec04_game* mpFinish;
    Elem_0059edc0_shapec04_game* mpCap;
    // STUB: 0x0058a630
    void Free();
    void Fn(Elem_0059edc0_shapec04_game* pPos, const Elem_0059edc0_shapec04_game* pVal, const void* pTag, uint32_t nFill, bool bAtEnd);
};

// FUNCTION: 0x0059edc0
void View_0059edc0_shapec04_game::Fn(Elem_0059edc0_shapec04_game* pPos, const Elem_0059edc0_shapec04_game* pVal, const void* /*pTag*/, uint32_t nFill, bool bAtEnd)
{
    uint32_t nOld = static_cast<uint32_t>(mpFinish - mpBegin);
    const uint32_t* pMax = (nOld < nFill) ? &nFill : &nOld;
    uint32_t nNew = *pMax + nOld;
    Elem_0059edc0_shapec04_game* pBuf = nNew ? static_cast<Elem_0059edc0_shapec04_game*>(_STL::__stl_new(nNew * 0x6c)) : 0;
    Elem_0059edc0_shapec04_game* pDst = pBuf;
    for (Elem_0059edc0_shapec04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t nLeft = nFill;
    if (nLeft == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; nLeft > 0; --nLeft) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!bAtEnd) {
        pDst = Fn00589490Move(pPos, mpFinish, pDst, &bAtEnd);
    }
    Free();
    mpFinish = pDst;
    mpCap = pBuf + nNew;
    mpBegin = pBuf;
}

struct Elem_007618b0_shapec04_game {
    uint8_t d[0x38];
    // STUB: 0x00761590
    void Copy(const Elem_007618b0_shapec04_game* pSrc);
};

// STUB: 0x007616e0
Elem_007618b0_shapec04_game* Fn007616e0Move(Elem_007618b0_shapec04_game* pFirst, Elem_007618b0_shapec04_game* pLast, Elem_007618b0_shapec04_game* pDst, const bool* pTag);

// STUB: 0x00761710
void Fn00761710Destroy(Elem_007618b0_shapec04_game* pFirst, Elem_007618b0_shapec04_game* pLast, const bool* pTag);

struct View_007618b0_shapec04_game {
    Elem_007618b0_shapec04_game* mpBegin;
    Elem_007618b0_shapec04_game* mpFinish;
    Elem_007618b0_shapec04_game* mpCap;
    void Fn(Elem_007618b0_shapec04_game* pPos, const Elem_007618b0_shapec04_game* pVal, const void* pTag, uint32_t nFill, bool bAtEnd);
};

// FUNCTION: 0x007618b0
void View_007618b0_shapec04_game::Fn(Elem_007618b0_shapec04_game* pPos, const Elem_007618b0_shapec04_game* pVal, const void* /*pTag*/, uint32_t nFill, bool bAtEnd)
{
    uint32_t nOld = static_cast<uint32_t>(mpFinish - mpBegin);
    const uint32_t* pMax = (nOld < nFill) ? &nFill : &nOld;
    uint32_t nNew = *pMax + nOld;
    Elem_007618b0_shapec04_game* pBuf = nNew ? static_cast<Elem_007618b0_shapec04_game*>(_STL::__stl_new(nNew * 0x38)) : 0;
    Elem_007618b0_shapec04_game* pDst = pBuf;
    for (Elem_007618b0_shapec04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t nLeft = nFill;
    if (nLeft == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; nLeft > 0; --nLeft) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!bAtEnd) {
        pDst = Fn007616e0Move(pPos, mpFinish, pDst, &bAtEnd);
    }
    Fn00761710Destroy(mpBegin, mpFinish, &bAtEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
    mpFinish = pDst;
    mpCap = pBuf + nNew;
    mpBegin = pBuf;
}

struct Elem_00521350_shapec04_game {
    uint8_t d[0x7c];
    // STUB: 0x005205d0
    void Copy(const Elem_00521350_shapec04_game* pSrc);
};

// STUB: 0x00520940
Elem_00521350_shapec04_game* Fn00520940Move(Elem_00521350_shapec04_game* pFirst, Elem_00521350_shapec04_game* pLast, Elem_00521350_shapec04_game* pDst, const bool* pTag);

// STUB: 0x00518b20
void Fn00518b20Destroy(Elem_00521350_shapec04_game* pFirst, Elem_00521350_shapec04_game* pLast, const bool* pTag);

struct View_00521350_shapec04_game {
    Elem_00521350_shapec04_game* mpBegin;
    Elem_00521350_shapec04_game* mpFinish;
    Elem_00521350_shapec04_game* mpCap;
    void Fn(Elem_00521350_shapec04_game* pPos, const Elem_00521350_shapec04_game* pVal, const void* pTag, uint32_t nFill, bool bAtEnd);
};

// FUNCTION: 0x00521350
void View_00521350_shapec04_game::Fn(Elem_00521350_shapec04_game* pPos, const Elem_00521350_shapec04_game* pVal, const void* /*pTag*/, uint32_t nFill, bool bAtEnd)
{
    uint32_t nOld = static_cast<uint32_t>(mpFinish - mpBegin);
    const uint32_t* pMax = (nOld < nFill) ? &nFill : &nOld;
    uint32_t nNew = *pMax + nOld;
    Elem_00521350_shapec04_game* pBuf = nNew ? static_cast<Elem_00521350_shapec04_game*>(_STL::__stl_new(nNew * 0x7c)) : 0;
    Elem_00521350_shapec04_game* pDst = pBuf;
    for (Elem_00521350_shapec04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t nLeft = nFill;
    if (nLeft == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; nLeft > 0; --nLeft) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!bAtEnd) {
        pDst = Fn00520940Move(pPos, mpFinish, pDst, &bAtEnd);
    }
    Fn00518b20Destroy(mpBegin, mpFinish, &bAtEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
    mpFinish = pDst;
    mpCap = pBuf + nNew;
    mpBegin = pBuf;
}

struct Elem_0058c270_shapec04_game {
    uint8_t d[0x38];
    // STUB: 0x0058a8c0
    void Copy(const Elem_0058c270_shapec04_game* pSrc);
};

// STUB: 0x0058b2d0
Elem_0058c270_shapec04_game* Fn0058b2d0Move(Elem_0058c270_shapec04_game* pFirst, Elem_0058c270_shapec04_game* pLast, Elem_0058c270_shapec04_game* pDst, const bool* pTag);

// STUB: 0x0058be50
void Fn0058be50Destroy(Elem_0058c270_shapec04_game* pFirst, Elem_0058c270_shapec04_game* pLast, const bool* pTag);

struct View_0058c270_shapec04_game {
    Elem_0058c270_shapec04_game* mpBegin;
    Elem_0058c270_shapec04_game* mpFinish;
    Elem_0058c270_shapec04_game* mpCap;
    void Fn(Elem_0058c270_shapec04_game* pPos, const Elem_0058c270_shapec04_game* pVal, const void* pTag, uint32_t nFill, bool bAtEnd);
};

// FUNCTION: 0x0058c270
void View_0058c270_shapec04_game::Fn(Elem_0058c270_shapec04_game* pPos, const Elem_0058c270_shapec04_game* pVal, const void* /*pTag*/, uint32_t nFill, bool bAtEnd)
{
    uint32_t nOld = static_cast<uint32_t>(mpFinish - mpBegin);
    const uint32_t* pMax = (nOld < nFill) ? &nFill : &nOld;
    uint32_t nNew = *pMax + nOld;
    Elem_0058c270_shapec04_game* pBuf = nNew ? static_cast<Elem_0058c270_shapec04_game*>(_STL::__stl_new(nNew * 0x38)) : 0;
    Elem_0058c270_shapec04_game* pDst = pBuf;
    for (Elem_0058c270_shapec04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t nLeft = nFill;
    if (nLeft == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; nLeft > 0; --nLeft) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!bAtEnd) {
        pDst = Fn0058b2d0Move(pPos, mpFinish, pDst, &bAtEnd);
    }
    Fn0058be50Destroy(mpBegin, mpFinish, &bAtEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
    mpFinish = pDst;
    mpCap = pBuf + nNew;
    mpBegin = pBuf;
}

// STUB: 0x00586bf0
uint32_t* Fn00586bf0Copy(const uint32_t* pFirst, const uint32_t* pLast, uint32_t* pDst, const void* pTag);

// STUB: 0x00586e30
void Fn00586e30CopyBack(uint32_t* pFirst, uint32_t* pLast, uint32_t* pDst, const void* pTag, uint32_t n);

// STUB: 0x00586d50
void Fn00586d50Assign(const uint32_t* pFirst, const uint32_t* pLast, uint32_t* pDst, const void* pTag, uint32_t n);

struct View_00587a00_shapec04_game {
    uint32_t* mpBegin;
    uint32_t* mpFinish;
    uint32_t* mpCap;
    // STUB: 0x00587850
    void Free();
    void Fn(uint32_t* pPos, const uint32_t* pFirst, const uint32_t* pLast, const void* pTag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00587a00 score 157
void View_00587a00_shapec04_game::Fn(uint32_t* pPos, const uint32_t* pFirst, const uint32_t* pLast, const void* /*pTag*/)
{
    if (pFirst != pLast) {
        uint32_t* pEnd = mpFinish;
        uint32_t n = static_cast<uint32_t>(pLast - pFirst);
        if (n <= static_cast<uint32_t>(mpCap - pEnd)) {
            uint32_t* pOldEnd = mpFinish;
            uint32_t nAfter = static_cast<uint32_t>(pEnd - pPos);
            if (n < nAfter) {
                uint32_t* pMid = pOldEnd - n;
                Fn00586bf0Copy(pMid, pOldEnd, pOldEnd, &pFirst);
                mpFinish = mpFinish + n;
                Fn00586e30CopyBack(pPos, pMid, pOldEnd, &pFirst, 0);
                Fn00586d50Assign(pFirst, pLast, pPos, &pFirst, 0);
                return;
            }
            const uint32_t* pSplit = pFirst + nAfter;
            Fn00586bf0Copy(pSplit, pLast, pOldEnd, &pFirst);
            uint32_t* pNewEnd = mpFinish + (n - nAfter);
            mpFinish = pNewEnd;
            Fn00586bf0Copy(pPos, pOldEnd, pNewEnd, &pFirst);
            mpFinish = mpFinish + nAfter;
            Fn00586d50Assign(pFirst, pSplit, pPos, &pFirst, 0);
            return;
        }
        uint32_t nOld = static_cast<uint32_t>(pEnd - mpBegin);
        const uint32_t* pMax = (nOld < n) ? &n : &nOld;
        uint32_t nNew = *pMax + nOld;
        uint32_t* pBuf = nNew ? static_cast<uint32_t*>(_STL::__stl_new(nNew * 4)) : 0;
        uint32_t* pDst = Fn00586bf0Copy(mpBegin, pPos, pBuf, &pFirst);
        pDst = Fn00586bf0Copy(pFirst, pLast, pDst, &pFirst);
        uint32_t* pTail = Fn00586bf0Copy(pPos, mpFinish, pDst, &pFirst);
        Free();
        mpBegin = pBuf;
        mpFinish = pTail;
        mpCap = pBuf + nNew;
    }
}
#endif

// STUB: 0x00586c70
uint32_t* Fn00586c70Copy(const uint32_t* pFirst, const uint32_t* pLast, uint32_t* pDst, const void* pTag);

// STUB: 0x00586e90
void Fn00586e90CopyBack(uint32_t* pFirst, uint32_t* pLast, uint32_t* pDst, const void* pTag, uint32_t n);

// STUB: 0x00586dc0
void Fn00586dc0Assign(const uint32_t* pFirst, const uint32_t* pLast, uint32_t* pDst, const void* pTag, uint32_t n);

struct View_00587ba0_shapec04_game {
    uint32_t* mpBegin;
    uint32_t* mpFinish;
    uint32_t* mpCap;
    // STUB: 0x005877d0
    void Free();
    void Fn(uint32_t* pPos, const uint32_t* pFirst, const uint32_t* pLast, const void* pTag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00587ba0 score 157
void View_00587ba0_shapec04_game::Fn(uint32_t* pPos, const uint32_t* pFirst, const uint32_t* pLast, const void* /*pTag*/)
{
    if (pFirst != pLast) {
        uint32_t* pEnd = mpFinish;
        uint32_t n = static_cast<uint32_t>(pLast - pFirst);
        if (n <= static_cast<uint32_t>(mpCap - pEnd)) {
            uint32_t* pOldEnd = mpFinish;
            uint32_t nAfter = static_cast<uint32_t>(pEnd - pPos);
            if (n < nAfter) {
                uint32_t* pMid = pOldEnd - n;
                Fn00586c70Copy(pMid, pOldEnd, pOldEnd, &pFirst);
                mpFinish = mpFinish + n;
                Fn00586e90CopyBack(pPos, pMid, pOldEnd, &pFirst, 0);
                Fn00586dc0Assign(pFirst, pLast, pPos, &pFirst, 0);
                return;
            }
            const uint32_t* pSplit = pFirst + nAfter;
            Fn00586c70Copy(pSplit, pLast, pOldEnd, &pFirst);
            uint32_t* pNewEnd = mpFinish + (n - nAfter);
            mpFinish = pNewEnd;
            Fn00586c70Copy(pPos, pOldEnd, pNewEnd, &pFirst);
            mpFinish = mpFinish + nAfter;
            Fn00586dc0Assign(pFirst, pSplit, pPos, &pFirst, 0);
            return;
        }
        uint32_t nOld = static_cast<uint32_t>(pEnd - mpBegin);
        const uint32_t* pMax = (nOld < n) ? &n : &nOld;
        uint32_t nNew = *pMax + nOld;
        uint32_t* pBuf = nNew ? static_cast<uint32_t*>(_STL::__stl_new(nNew * 4)) : 0;
        uint32_t* pDst = Fn00586c70Copy(mpBegin, pPos, pBuf, &pFirst);
        pDst = Fn00586c70Copy(pFirst, pLast, pDst, &pFirst);
        uint32_t* pTail = Fn00586c70Copy(pPos, mpFinish, pDst, &pFirst);
        Free();
        mpBegin = pBuf;
        mpFinish = pTail;
        mpCap = pBuf + nNew;
    }
}
#endif

// STUB: 0x00586b70
uint32_t* Fn00586b70Copy(const uint32_t* pFirst, const uint32_t* pLast, uint32_t* pDst, const void* pTag);

// STUB: 0x00586cf0
void Fn00586cf0CopyBack(uint32_t* pFirst, uint32_t* pLast, uint32_t* pDst, const void* pTag, uint32_t n);

// STUB: 0x00586b00
void Fn00586b00Assign(const uint32_t* pFirst, const uint32_t* pLast, uint32_t* pDst, const void* pTag, uint32_t n);

struct View_00587d40_shapec04_game {
    uint32_t* mpBegin;
    uint32_t* mpFinish;
    uint32_t* mpCap;
    // STUB: 0x00587810
    void Free();
    void Fn(uint32_t* pPos, const uint32_t* pFirst, const uint32_t* pLast, const void* pTag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00587d40 score 157
void View_00587d40_shapec04_game::Fn(uint32_t* pPos, const uint32_t* pFirst, const uint32_t* pLast, const void* /*pTag*/)
{
    if (pFirst != pLast) {
        uint32_t* pEnd = mpFinish;
        uint32_t n = static_cast<uint32_t>(pLast - pFirst);
        if (n <= static_cast<uint32_t>(mpCap - pEnd)) {
            uint32_t* pOldEnd = mpFinish;
            uint32_t nAfter = static_cast<uint32_t>(pEnd - pPos);
            if (n < nAfter) {
                uint32_t* pMid = pOldEnd - n;
                Fn00586b70Copy(pMid, pOldEnd, pOldEnd, &pFirst);
                mpFinish = mpFinish + n;
                Fn00586cf0CopyBack(pPos, pMid, pOldEnd, &pFirst, 0);
                Fn00586b00Assign(pFirst, pLast, pPos, &pFirst, 0);
                return;
            }
            const uint32_t* pSplit = pFirst + nAfter;
            Fn00586b70Copy(pSplit, pLast, pOldEnd, &pFirst);
            uint32_t* pNewEnd = mpFinish + (n - nAfter);
            mpFinish = pNewEnd;
            Fn00586b70Copy(pPos, pOldEnd, pNewEnd, &pFirst);
            mpFinish = mpFinish + nAfter;
            Fn00586b00Assign(pFirst, pSplit, pPos, &pFirst, 0);
            return;
        }
        uint32_t nOld = static_cast<uint32_t>(pEnd - mpBegin);
        const uint32_t* pMax = (nOld < n) ? &n : &nOld;
        uint32_t nNew = *pMax + nOld;
        uint32_t* pBuf = nNew ? static_cast<uint32_t*>(_STL::__stl_new(nNew * 4)) : 0;
        uint32_t* pDst = Fn00586b70Copy(mpBegin, pPos, pBuf, &pFirst);
        pDst = Fn00586b70Copy(pFirst, pLast, pDst, &pFirst);
        uint32_t* pTail = Fn00586b70Copy(pPos, mpFinish, pDst, &pFirst);
        Free();
        mpBegin = pBuf;
        mpFinish = pTail;
        mpCap = pBuf + nNew;
    }
}
#endif

// GLOBAL: 0x00b22ad8
extern uint8_t g00b22ad8;

// FUNCTION: 0x00575640
bool Fn00575640()
{
    g00b22ad8 = 0;
    return true;
}

// GLOBAL: 0x00b22b58
extern uint8_t g00b22b58;

// FUNCTION: 0x0057c050
bool Fn0057c050()
{
    g00b22b58 = 0;
    return true;
}

// GLOBAL: 0x00b22b78
extern uint8_t g00b22b78;

// FUNCTION: 0x0057d270
bool Fn0057d270()
{
    g00b22b78 = 0;
    return true;
}

struct View3D_shapec04_game {
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
    virtual uint32_t Get();
};

// GLOBAL: 0x00b43dc4
extern View3D_shapec04_game* gp00b43dc4;

struct View_004e2bc0_shapec04_game {
    uint32_t Fn();
};

// FUNCTION: 0x004e2bc0
uint32_t View_004e2bc0_shapec04_game::Fn()
{
    return gp00b43dc4->Get() == 3;
}

struct View_004e2be0_shapec04_game {
    uint32_t Fn();
};

// FUNCTION: 0x004e2be0
uint32_t View_004e2be0_shapec04_game::Fn()
{
    return gp00b43dc4->Get() == 2;
}

struct Sim_shapec04_game {
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
    virtual uint32_t Get();
};

// GLOBAL: 0x00b43d5c
extern Sim_shapec04_game* gp00b43d5c;

struct View_004e2c90_shapec04_game {
    uint32_t Fn();
};

// FUNCTION: 0x004e2c90
uint32_t View_004e2c90_shapec04_game::Fn()
{
    return gp00b43d5c->Get() == 2;
}

struct View_004c6af0_shapec04_game {
    uint8_t pad[0x4];
    uint32_t mVtbl;
    void* mpData;
    void Fn();
};

// FUNCTION: 0x004c6af0
void View_004c6af0_shapec04_game::Fn()
{
    mVtbl = 0xa80810;
    if (mpData) {
        _STL::__stl_delete(mpData);
    }
}

struct View_005998c0_shapec04_game {
    uint8_t pad[0x8];
    uint32_t mVtbl;
    void* mpData;
    void Fn();
};

// FUNCTION: 0x005998c0
void View_005998c0_shapec04_game::Fn()
{
    mVtbl = 0xa80810;
    if (mpData) {
        _STL::__stl_delete(mpData);
    }
}

struct View_00778430_shapec04_game {
    uint8_t pad[0xc];
    uint32_t mVtbl;
    void* mpData;
    void Fn();
};

// FUNCTION: 0x00778430
void View_00778430_shapec04_game::Fn()
{
    mVtbl = 0xa80810;
    if (mpData) {
        _STL::__stl_delete(mpData);
    }
}

struct View_0046b4a0_shapec04_game {
    uint8_t pad[0xc];
    View_0046b4a0_shapec04_game* mpParent;
    uint8_t pad2[0x54];
    uint32_t mnValue;
    uint32_t Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0046b4a0 score 5
uint32_t View_0046b4a0_shapec04_game::Fn()
{
    View_0046b4a0_shapec04_game* p = this;
    do {
        if (p->mnValue) {
            return p->mnValue;
        }
        p = p->mpParent;
    } while (p);
    return 0;
}
#endif

struct View_004fc8e0_shapec04_game {
    uint8_t pad[0xc];
    View_004fc8e0_shapec04_game* mpParent;
    uint8_t pad2[0x50];
    uint32_t mnValue;
    uint32_t Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x004fc8e0 score 5
uint32_t View_004fc8e0_shapec04_game::Fn()
{
    View_004fc8e0_shapec04_game* p = this;
    do {
        if (p->mnValue) {
            return p->mnValue;
        }
        p = p->mpParent;
    } while (p);
    return 0;
}
#endif

struct View_005245a0_shapec04_game {
    uint8_t pad[0xc];
    View_005245a0_shapec04_game* mpParent;
    uint8_t pad2[0x58];
    uint32_t mnValue;
    uint32_t Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x005245a0 score 5
uint32_t View_005245a0_shapec04_game::Fn()
{
    View_005245a0_shapec04_game* p = this;
    do {
        if (p->mnValue) {
            return p->mnValue;
        }
        p = p->mpParent;
    } while (p);
    return 0;
}
#endif

struct View_0048daa0_shapec04_game {
    // STUB: 0x00464130
    void Resize(uint32_t n, const uint32_t* pVal);
    void Fn(uint32_t n);
};

// FUNCTION: 0x0048daa0
void View_0048daa0_shapec04_game::Fn(uint32_t n)
{
    uint32_t zero = 0;
    Resize(n, &zero);
}

struct View_005db490_shapec04_game {
    // STUB: 0x00462960
    void Resize(uint32_t n, const uint32_t* pVal);
    void Fn(uint32_t n);
};

// FUNCTION: 0x005db490
void View_005db490_shapec04_game::Fn(uint32_t n)
{
    uint32_t zero = 0;
    Resize(n, &zero);
}

struct View_00493ec0_shapec04_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void Destroy(uint32_t n);
    uint8_t pad[0x8];
    uint32_t mnRefs;
    // STUB: 0x004929f0
    void Shutdown();
    uint32_t Release();
};

// FUNCTION: 0x00493ec0
uint32_t View_00493ec0_shapec04_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Shutdown();
    Destroy(1);
    return 0;
}

struct View_006bb8c0_shapec04_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void Destroy(uint32_t n);
    uint32_t mnRefs;
    // STUB: 0x006bb750
    void Shutdown();
    uint32_t Release();
};

// FUNCTION: 0x006bb8c0
uint32_t View_006bb8c0_shapec04_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Shutdown();
    Destroy(1);
    return 0;
}

struct View_00479ce0_shapec04_game {
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
    virtual void Destroy(uint32_t n);
    uint32_t mnRefs;
    // STUB: 0x00479a10
    void Shutdown();
    uint32_t Release();
};

// FUNCTION: 0x00479ce0
uint32_t View_00479ce0_shapec04_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Shutdown();
    Destroy(1);
    return 0;
}

struct View_004e7a60_shapec04_game {
    uint8_t pad[0x8];
    int32_t mnRefs;
    // STUB: 0x004e76e0
    void Shutdown();
    uint32_t Release();
};

// FUNCTION: 0x004e7a60
uint32_t View_004e7a60_shapec04_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Shutdown();
    Fn005e5620(this);
    return 0;
}

struct View_004f1a50_shapec04_game {
    uint8_t pad[0x4];
    int32_t mnRefs;
    // STUB: 0x004f19e0
    void Shutdown();
    uint32_t Release();
};

// FUNCTION: 0x004f1a50
uint32_t View_004f1a50_shapec04_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Shutdown();
    Fn005e5620(this);
    return 0;
}

struct View_004f8da0_shapec04_game {
    uint8_t pad[0x10];
    int32_t mnRefs;
    // STUB: 0x004f8820
    void Shutdown();
    uint32_t Release();
};

// FUNCTION: 0x004f8da0
uint32_t View_004f8da0_shapec04_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Shutdown();
    Fn005e5620(this);
    return 0;
}

struct Pool_00801ed0_shapec04_game {
    // STUB: 0x008020f0
    void Free(void* p);
};

// GLOBAL: 0x00b0e368
extern Pool_00801ed0_shapec04_game g00b0e368;

// FUNCTION: 0x00801ed0
void Fn00801ed0(void* p, uint32_t size)
{
    if (p) {
        if (size == 0xa4) {
            g00b0e368.Free(p);
        } else {
            Fn005e5620(p);
        }
    }
}

struct Pool_00545130_shapec04_game {
    // STUB: 0x00545410
    void Free(void* p);
};

// GLOBAL: 0x00b0a018
extern Pool_00545130_shapec04_game g00b0a018;

// FUNCTION: 0x00545130
void Fn00545130(void* p, uint32_t size)
{
    if (p) {
        if (size == 0x270) {
            g00b0a018.Free(p);
        } else {
            Fn005e5620(p);
        }
    }
}

struct Pool_0055ca60_shapec04_game {
    // STUB: 0x0055f600
    void Free(void* p);
};

// GLOBAL: 0x00b0a0f8
extern Pool_0055ca60_shapec04_game g00b0a0f8;

// FUNCTION: 0x0055ca60
void Fn0055ca60(void* p, uint32_t size)
{
    if (p) {
        if (size == 0x2b8) {
            g00b0a0f8.Free(p);
        } else {
            Fn005e5620(p);
        }
    }
}

struct Msg_shapec04_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual uint32_t GetType();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual void S8();
    virtual void S9();
    virtual uint32_t GetA();
    virtual void S11();
    virtual void S12();
    virtual void S13();
    virtual uint32_t GetB();
};

struct Outer_0057e740_shapec04_game {
    // STUB: 0x0057dfe0
    void Handle();
};

struct View_0057e740_shapec04_game {
    bool Slot03(void* pMsg);
};

// FUNCTION: 0x0057e740
bool View_0057e740_shapec04_game::Slot03(void* pMsg)
{
    if (static_cast<Msg_shapec04_game*>(pMsg)->GetType() == 0x86ad10ee) {
        reinterpret_cast<Outer_0057e740_shapec04_game*>(reinterpret_cast<char*>(this) - 0x10)->Handle();
    }
    return true;
}

struct Outer_0057efa0_shapec04_game {
    // STUB: 0x0057ee40
    void Handle();
};

struct View_0057efa0_shapec04_game {
    bool Slot03(void* pMsg);
};

// FUNCTION: 0x0057efa0
bool View_0057efa0_shapec04_game::Slot03(void* pMsg)
{
    if (static_cast<Msg_shapec04_game*>(pMsg)->GetType() == 0x86ad10ee) {
        reinterpret_cast<Outer_0057efa0_shapec04_game*>(reinterpret_cast<char*>(this) - 0xc)->Handle();
    }
    return true;
}

struct Outer_0048c8f0_shapec04_game {
    // STUB: 0x0048c6d0
    void Handle();
};

struct View_0048c8f0_shapec04_game {
    bool Slot03(void* pMsg);
};

// FUNCTION: 0x0048c8f0
bool View_0048c8f0_shapec04_game::Slot03(void* pMsg)
{
    if (static_cast<Msg_shapec04_game*>(pMsg)->GetType() == 0xea8ae29a) {
        reinterpret_cast<Outer_0048c8f0_shapec04_game*>(reinterpret_cast<char*>(this) - 0x8)->Handle();
    }
    return true;
}

struct Outer_00576b80_shapec04_game {
    // STUB: 0x00576b10
    void Handle(uint32_t v);
};

struct View_00576b80_shapec04_game {
    bool Slot03(void* pMsg);
};

// FUNCTION: 0x00576b80
bool View_00576b80_shapec04_game::Slot03(void* pMsg)
{
    Msg_shapec04_game* pM = static_cast<Msg_shapec04_game*>(pMsg);
    if (pM->GetType() == 0x86ad10ee) {
        reinterpret_cast<Outer_00576b80_shapec04_game*>(reinterpret_cast<char*>(this) - 0xc)->Handle(pM->GetB());
    }
    return true;
}

struct Outer_0064a140_shapec04_game {
    // STUB: 0x0064a0f0
    void Handle(uint32_t v);
};

struct View_0064a140_shapec04_game {
    bool Slot03(void* pMsg);
};

// FUNCTION: 0x0064a140
bool View_0064a140_shapec04_game::Slot03(void* pMsg)
{
    Msg_shapec04_game* pM = static_cast<Msg_shapec04_game*>(pMsg);
    if (pM->GetType() == 0x99ef1142) {
        reinterpret_cast<Outer_0064a140_shapec04_game*>(reinterpret_cast<char*>(this) - 0x4)->Handle(pM->GetA());
    }
    return true;
}

struct Outer_006584a0_shapec04_game {
    // STUB: 0x006583f0
    void Handle(uint32_t v);
};

struct View_006584a0_shapec04_game {
    bool Slot03(void* pMsg);
};

// FUNCTION: 0x006584a0
bool View_006584a0_shapec04_game::Slot03(void* pMsg)
{
    Msg_shapec04_game* pM = static_cast<Msg_shapec04_game*>(pMsg);
    if (pM->GetType() == 0x99ef1142) {
        reinterpret_cast<Outer_006584a0_shapec04_game*>(reinterpret_cast<char*>(this) - 0xc)->Handle(pM->GetA());
    }
    return true;
}

struct View_00506420_shapec04_game {
    uint32_t mVtbl;
    uint32_t m4;
    uint32_t m8;
    uint32_t mc;
    uint32_t m10;
    uint8_t m14;
    uint32_t m18;
    uint32_t m1c;
    uint32_t m20;
    uint32_t m24;
    uint32_t m28;
    View_00506420_shapec04_game* Fn();
};

// FUNCTION: 0x00506420
View_00506420_shapec04_game* View_00506420_shapec04_game::Fn()
{
    m4 = 0;
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    mVtbl = 0xa9550c;
    m28 = 0;
    return this;
}

struct View_00509a20_shapec04_game {
    uint32_t mVtbl;
    uint32_t m4;
    uint32_t m8;
    uint32_t mc;
    uint32_t m10;
    uint8_t m14;
    uint32_t m18;
    uint32_t m1c;
    uint32_t m20;
    uint32_t m24;
    uint32_t m28;
    View_00509a20_shapec04_game* Fn();
};

// FUNCTION: 0x00509a20
View_00509a20_shapec04_game* View_00509a20_shapec04_game::Fn()
{
    m4 = 0;
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    mVtbl = 0xa95590;
    m28 = 0;
    return this;
}

struct View_005052d0_shapec04_game {
    uint32_t mVtbl;
    uint32_t m4;
    uint32_t m8;
    uint32_t mc;
    uint32_t m10;
    uint8_t m14;
    uint32_t m18;
    uint32_t m1c;
    uint32_t m20;
    uint32_t m24;
    uint32_t m28;
    View_005052d0_shapec04_game* Fn();
};

// FUNCTION: 0x005052d0
View_005052d0_shapec04_game* View_005052d0_shapec04_game::Fn()
{
    m4 = 0;
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    mVtbl = 0xa9539c;
    m28 = 0;
    return this;
}

struct Vec_007a12d0_shapec04_game {
    uint32_t* mpBegin;
    uint32_t* mpFinish;
    uint32_t* mpCap;
    // STUB: 0x005bfe60
    void InsertOverflow(uint32_t* pPos, const uint32_t* pVal, const uint8_t* pTag, uint32_t n, bool bAtEnd);
};

struct View_007a12d0_shapec04_game {
    uint8_t pad[0x18];
    Vec_007a12d0_shapec04_game mVec;
    void Fn(uint32_t v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007a12d0 score 1
void View_007a12d0_shapec04_game::Fn(uint32_t v)
{
    Vec_007a12d0_shapec04_game* pVec = &mVec;
    if (pVec->mpFinish != pVec->mpCap) {
        if (pVec->mpFinish) {
            *pVec->mpFinish = v;
        }
        pVec->mpFinish++;
    } else {
        pVec->InsertOverflow(pVec->mpFinish, &v, reinterpret_cast<const uint8_t*>(&v), 1, true);
    }
}
#endif

struct Vec_00556380_shapec04_game {
    uint32_t* mpBegin;
    uint32_t* mpFinish;
    uint32_t* mpCap;
    // STUB: 0x0051ca60
    void InsertOverflow(uint32_t* pPos, const uint32_t* pVal, const uint8_t* pTag, uint32_t n, bool bAtEnd);
};

struct View_00556380_shapec04_game {
    uint8_t pad[0x2b8];
    Vec_00556380_shapec04_game mVec;
    void Fn(uint32_t v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00556380 score 1
void View_00556380_shapec04_game::Fn(uint32_t v)
{
    Vec_00556380_shapec04_game* pVec = &mVec;
    if (pVec->mpFinish != pVec->mpCap) {
        if (pVec->mpFinish) {
            *pVec->mpFinish = v;
        }
        pVec->mpFinish++;
    } else {
        pVec->InsertOverflow(pVec->mpFinish, &v, reinterpret_cast<const uint8_t*>(&v), 1, true);
    }
}
#endif

struct Vec_0079fb90_shapec04_game {
    uint32_t* mpBegin;
    uint32_t* mpFinish;
    uint32_t* mpCap;
    // STUB: 0x0051ca60
    void InsertOverflow(uint32_t* pPos, const uint32_t* pVal, const uint8_t* pTag, uint32_t n, bool bAtEnd);
};

struct View_0079fb90_shapec04_game {
    uint8_t pad[0xc];
    Vec_0079fb90_shapec04_game mVec;
    void Fn(uint32_t v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0079fb90 score 1
void View_0079fb90_shapec04_game::Fn(uint32_t v)
{
    Vec_0079fb90_shapec04_game* pVec = &mVec;
    if (pVec->mpFinish != pVec->mpCap) {
        if (pVec->mpFinish) {
            *pVec->mpFinish = v;
        }
        pVec->mpFinish++;
    } else {
        pVec->InsertOverflow(pVec->mpFinish, &v, reinterpret_cast<const uint8_t*>(&v), 1, true);
    }
}
#endif

struct Res_shapec04_game {
    uint32_t mValue;
};

struct Svc_004c3f90_shapec04_game {
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
    virtual Res_shapec04_game Get(uint32_t id);
};

// GLOBAL: 0x00b43da0
extern Svc_004c3f90_shapec04_game* gp00b43da0;

// STUB: 0x004c3ca0
bool Fn004c3ca0(uint32_t a, uint32_t b, uint32_t c);

#ifdef OB_DRAFTS
// CLOSE: 0x004c3f90 score 12
bool Fn004c3f90(uint32_t a, uint32_t b, bool bFlag, uint32_t id)
{
    if (bFlag) {
        uint32_t key = gp00b43da0->Get(id).mValue;
        return Fn004c3ca0(a, b, key);
    }
    return true;
}
#endif

struct Svc_004c5180_shapec04_game {
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
    virtual Res_shapec04_game Get(uint32_t id);
};

// GLOBAL: 0x00b43d78
extern Svc_004c5180_shapec04_game* gp00b43d78;

// STUB: 0x004c3ca0
bool Fn004c3ca0(uint32_t a, uint32_t b, uint32_t c);

#ifdef OB_DRAFTS
// CLOSE: 0x004c5180 score 12
bool Fn004c5180(uint32_t a, uint32_t b, bool bFlag, uint32_t id)
{
    if (bFlag) {
        uint32_t key = gp00b43d78->Get(id).mValue;
        return Fn004c3ca0(a, b, key);
    }
    return true;
}
#endif

struct Svc_004c51c0_shapec04_game {
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
    virtual Res_shapec04_game Get(uint32_t id);
};

// GLOBAL: 0x00b43d98
extern Svc_004c51c0_shapec04_game* gp00b43d98;

// STUB: 0x004c3ca0
bool Fn004c3ca0(uint32_t a, uint32_t b, uint32_t c);

#ifdef OB_DRAFTS
// CLOSE: 0x004c51c0 score 12
bool Fn004c51c0(uint32_t a, uint32_t b, bool bFlag, uint32_t id)
{
    if (bFlag) {
        uint32_t key = gp00b43d98->Get(id).mValue;
        return Fn004c3ca0(a, b, key);
    }
    return true;
}
#endif

struct View_00477d00_shapec04_game {
    uint8_t pad[0x44];
    uint32_t* mpBits;
    uint32_t mnOffset;
    uint32_t Fn(uint32_t idx);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00477d00 score 26
uint32_t View_00477d00_shapec04_game::Fn(uint32_t idx)
{
    uint32_t* pBits = mpBits;
    int32_t i = static_cast<int32_t>(mnOffset + idx);
    uint32_t* pWord = pBits + i / 32;
    int32_t bit = i % 32;
    if (bit < 0) {
        bit += 32;
        --pWord;
    }
    return (*pWord & (1u << bit)) != 0;
}
#endif

struct View_00477d50_shapec04_game {
    uint8_t pad[0x58];
    uint32_t* mpBits;
    uint32_t mnOffset;
    uint32_t Fn(uint32_t idx);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00477d50 score 26
uint32_t View_00477d50_shapec04_game::Fn(uint32_t idx)
{
    uint32_t* pBits = mpBits;
    int32_t i = static_cast<int32_t>(mnOffset + idx);
    uint32_t* pWord = pBits + i / 32;
    int32_t bit = i % 32;
    if (bit < 0) {
        bit += 32;
        --pWord;
    }
    return (*pWord & (1u << bit)) != 0;
}
#endif

struct View_00477da0_shapec04_game {
    uint8_t pad[0x6c];
    uint32_t* mpBits;
    uint32_t mnOffset;
    uint32_t Fn(uint32_t idx);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00477da0 score 26
uint32_t View_00477da0_shapec04_game::Fn(uint32_t idx)
{
    uint32_t* pBits = mpBits;
    int32_t i = static_cast<int32_t>(mnOffset + idx);
    uint32_t* pWord = pBits + i / 32;
    int32_t bit = i % 32;
    if (bit < 0) {
        bit += 32;
        --pWord;
    }
    return (*pWord & (1u << bit)) != 0;
}
#endif

// STUB: 0x004899f0
void Fn00489c90Adjust(uint32_t* pFirst, int32_t nHole, int32_t nLen, uint32_t nValue, uint32_t pCmp);

// FUNCTION: 0x00489c90
void Fn00489c90(uint32_t* pFirst, uint32_t* pLast, uint32_t pCmp)
{
    int32_t nLen = static_cast<int32_t>(pLast - pFirst);
    if (nLen >= 2) {
        int32_t nParent = (nLen - 2) / 2;
        for (;;) {
            Fn00489c90Adjust(pFirst, nParent, nLen, pFirst[nParent], pCmp);
            if (nParent == 0) {
                return;
            }
            --nParent;
        }
    }
}

// STUB: 0x0062ea20
void Fn0062ec70Adjust(uint32_t* pFirst, int32_t nHole, int32_t nLen, uint32_t nValue, uint32_t pCmp);

// FUNCTION: 0x0062ec70
void Fn0062ec70(uint32_t* pFirst, uint32_t* pLast, uint32_t pCmp)
{
    int32_t nLen = static_cast<int32_t>(pLast - pFirst);
    if (nLen >= 2) {
        int32_t nParent = (nLen - 2) / 2;
        for (;;) {
            Fn0062ec70Adjust(pFirst, nParent, nLen, pFirst[nParent], pCmp);
            if (nParent == 0) {
                return;
            }
            --nParent;
        }
    }
}

// STUB: 0x00704af0
void Fn00705550Adjust(uint32_t* pFirst, int32_t nHole, int32_t nLen, uint32_t nValue, uint32_t pCmp);

// FUNCTION: 0x00705550
void Fn00705550(uint32_t* pFirst, uint32_t* pLast, uint32_t pCmp)
{
    int32_t nLen = static_cast<int32_t>(pLast - pFirst);
    if (nLen >= 2) {
        int32_t nParent = (nLen - 2) / 2;
        for (;;) {
            Fn00705550Adjust(pFirst, nParent, nLen, pFirst[nParent], pCmp);
            if (nParent == 0) {
                return;
            }
            --nParent;
        }
    }
}

struct Obj_shapec04_game {
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
    virtual void S51();
    virtual void S52();
    virtual void S53();
    virtual void S54();
    virtual void S55();
    virtual void S56();
    virtual void S57();
    virtual void S58();
    virtual void S59();
    virtual void S60();
    virtual void S61();
    virtual void S62();
    virtual uint32_t GetType();
};

struct Info_shapec04_game {
    uint32_t mType;
    uint32_t mKey;
    uint32_t mId;
};

struct Server_shapec04_game {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual void S8();
    virtual void Post(uint32_t code, Obj_shapec04_game* pObj, uint32_t id);
};

// STUB: 0x00913c46
Server_shapec04_game* Fn00913c46();

struct View_0048c0a0_shapec04_game {
    bool Slot03(Obj_shapec04_game* pObj, Info_shapec04_game* pInfo);
};

// FUNCTION: 0x0048c0a0
bool View_0048c0a0_shapec04_game::Slot03(Obj_shapec04_game* pObj, Info_shapec04_game* pInfo)
{
    if (pObj->GetType() != 0x2a5cfb2c) {
        return false;
    }
    if (pInfo->mType != 3 || pInfo->mKey != 0x287259f6) {
        return false;
    }
    uint32_t id = pInfo->mId;
    Server_shapec04_game* pServer = Fn00913c46();
    if (id == 0xaa89faf5) {
        pServer->Post(0xf, pObj, 0xaa89faf5);
    }
    return true;
}

struct View_00734b10_shapec04_game {
    bool Slot03(Obj_shapec04_game* pObj, Info_shapec04_game* pInfo);
};

// FUNCTION: 0x00734b10
bool View_00734b10_shapec04_game::Slot03(Obj_shapec04_game* pObj, Info_shapec04_game* pInfo)
{
    if (pObj->GetType() != 0x10000001) {
        return false;
    }
    if (pInfo->mType != 3 || pInfo->mKey != 0x287259f6) {
        return false;
    }
    uint32_t id = pInfo->mId;
    Server_shapec04_game* pServer = Fn00913c46();
    if (id == 0xb) {
        pServer->Post(0xf, pObj, 0xb);
    }
    return true;
}

struct View_00734d30_shapec04_game {
    bool Slot03(Obj_shapec04_game* pObj, Info_shapec04_game* pInfo);
};

// FUNCTION: 0x00734d30
bool View_00734d30_shapec04_game::Slot03(Obj_shapec04_game* pObj, Info_shapec04_game* pInfo)
{
    if (pObj->GetType() != 0x6a4d0a59) {
        return false;
    }
    if (pInfo->mType != 3 || pInfo->mKey != 0x287259f6) {
        return false;
    }
    uint32_t id = pInfo->mId;
    Server_shapec04_game* pServer = Fn00913c46();
    if (id == 0x6a4d0a6b) {
        pServer->Post(0xf, pObj, 0x6a4d0a6b);
    }
    return true;
}

struct Str_004ed8a0_shapec04_game {
    uint32_t mBegin;
    uint32_t mEnd;
    uint32_t mCap;
    // STUB: 0x00407fa0
    void Init(const char* pFirst, const char* pLast, uint8_t* pTag);
};

struct Base0_004ed8a0_shapec04_game {
    uint32_t mVtbl;
};

struct Base4_004ed8a0_shapec04_game {
    uint32_t m4;
    Base4_004ed8a0_shapec04_game() : m4(0xa94018) {}
};

struct View_004ed8a0_shapec04_game : Base0_004ed8a0_shapec04_game, Base4_004ed8a0_shapec04_game {
    uint32_t m8;
    uint32_t mc;
    Str_004ed8a0_shapec04_game mStr;
    uint32_t m1c;
    uint32_t m20;
    uint32_t m24;
    View_004ed8a0_shapec04_game();
};

#ifdef OB_DRAFTS
// CLOSE: 0x004ed8a0 score 16
View_004ed8a0_shapec04_game::View_004ed8a0_shapec04_game()
{
    uint32_t zero = 0;
    uint8_t tag;
    mVtbl = 0xa94068;
    m4 = 0xa94054;
    m8 = zero;
    mStr.mBegin = zero;
    mStr.mEnd = zero;
    mStr.mCap = zero;
    const char* pName = "2D SC4K";
    mStr.Init(pName, pName + 7, &tag);
    m1c = zero;
    mc = 0xa80810;
    m20 = 0x7dcded2d;
    m24 = zero;
}
#endif

struct Str_004ed9a0_shapec04_game {
    uint32_t mBegin;
    uint32_t mEnd;
    uint32_t mCap;
    // STUB: 0x00407fa0
    void Init(const char* pFirst, const char* pLast, uint8_t* pTag);
};

struct Base0_004ed9a0_shapec04_game {
    uint32_t mVtbl;
};

struct Base4_004ed9a0_shapec04_game {
    uint32_t m4;
    Base4_004ed9a0_shapec04_game() : m4(0xa94018) {}
};

struct View_004ed9a0_shapec04_game : Base0_004ed9a0_shapec04_game, Base4_004ed9a0_shapec04_game {
    uint32_t m8;
    uint32_t mc;
    Str_004ed9a0_shapec04_game mStr;
    uint32_t m1c;
    uint32_t m20;
    uint32_t m24;
    View_004ed9a0_shapec04_game();
};

#ifdef OB_DRAFTS
// CLOSE: 0x004ed9a0 score 16
View_004ed9a0_shapec04_game::View_004ed9a0_shapec04_game()
{
    uint32_t zero = 0;
    uint8_t tag;
    mVtbl = 0xa940a4;
    m4 = 0xa94090;
    m8 = zero;
    mStr.mBegin = zero;
    mStr.mEnd = zero;
    mStr.mCap = zero;
    const char* pName = "3D SC4K";
    mStr.Init(pName, pName + 7, &tag);
    m1c = zero;
    mc = 0xa80810;
    m20 = 0x7dcded3d;
    m24 = zero;
}
#endif

struct Str_004eda00_shapec04_game {
    uint32_t mBegin;
    uint32_t mEnd;
    uint32_t mCap;
    // STUB: 0x00407fa0
    void Init(const char* pFirst, const char* pLast, uint8_t* pTag);
};

struct Base0_004eda00_shapec04_game {
    uint32_t mVtbl;
};

struct Base4_004eda00_shapec04_game {
    uint32_t m4;
    Base4_004eda00_shapec04_game() : m4(0xa94018) {}
};

struct View_004eda00_shapec04_game : Base0_004eda00_shapec04_game, Base4_004eda00_shapec04_game {
    uint32_t m8;
    uint32_t mc;
    Str_004eda00_shapec04_game mStr;
    uint32_t m1c;
    uint32_t m20;
    uint32_t m24;
    View_004eda00_shapec04_game();
};

#ifdef OB_DRAFTS
// CLOSE: 0x004eda00 score 16
View_004eda00_shapec04_game::View_004eda00_shapec04_game()
{
    uint32_t zero = 0;
    uint8_t tag;
    mVtbl = 0xa940e4;
    m4 = 0xa940d0;
    m8 = zero;
    mStr.mBegin = zero;
    mStr.mEnd = zero;
    mStr.mCap = zero;
    const char* pName = "3DEffect";
    mStr.Init(pName, pName + 8, &tag);
    m1c = zero;
    mc = 0xa80810;
    m20 = 0xa63a543;
    m24 = zero;
}
#endif

struct Elem_004fc6b0_shapec04_game {
    uint32_t mA;
    uint32_t mB;
    uint32_t mC;
};

struct Vec_004fc6b0_shapec04_game {
    Elem_004fc6b0_shapec04_game* mpBegin;
    Elem_004fc6b0_shapec04_game* mpFinish;
    // STUB: 0x004fbd30
    void Fill(Elem_004fc6b0_shapec04_game* pPos, uint32_t n, const Elem_004fc6b0_shapec04_game* pVal);
    void Resize(uint32_t n, const Elem_004fc6b0_shapec04_game* pVal);
};

// STUB: 0x00506280
Elem_004fc6b0_shapec04_game* Fn004fc6b0Erase(Elem_004fc6b0_shapec04_game* pA, Elem_004fc6b0_shapec04_game* pB, Elem_004fc6b0_shapec04_game* pC, uint8_t* pTag, uint32_t n);

#ifdef OB_DRAFTS
// CLOSE: 0x004fc6b0 score 8
void Vec_004fc6b0_shapec04_game::Resize(uint32_t n, const Elem_004fc6b0_shapec04_game* pVal)
{
    Elem_004fc6b0_shapec04_game* pBegin = mpBegin;
    Elem_004fc6b0_shapec04_game* pEnd = mpFinish;
    uint32_t nSize = static_cast<uint32_t>(pEnd - pBegin);
    if (n < nSize) {
        Elem_004fc6b0_shapec04_game* pNew = pBegin + n;
        uint8_t tag;
        mpFinish = Fn004fc6b0Erase(pEnd, pEnd, pNew, &tag, 0);
    } else {
        Fill(pEnd, n - nSize, pVal);
    }
}
#endif

struct Elem_00683c40_shapec04_game {
    uint32_t mA;
    uint32_t mB;
    uint32_t mC;
};

struct Vec_00683c40_shapec04_game {
    Elem_00683c40_shapec04_game* mpBegin;
    Elem_00683c40_shapec04_game* mpFinish;
    // STUB: 0x00683950
    void Fill(Elem_00683c40_shapec04_game* pPos, uint32_t n, const Elem_00683c40_shapec04_game* pVal);
    void Resize(uint32_t n, const Elem_00683c40_shapec04_game* pVal);
};

// STUB: 0x00506230
Elem_00683c40_shapec04_game* Fn00683c40Erase(Elem_00683c40_shapec04_game* pA, Elem_00683c40_shapec04_game* pB, Elem_00683c40_shapec04_game* pC, uint8_t* pTag, uint32_t n);

#ifdef OB_DRAFTS
// CLOSE: 0x00683c40 score 8
void Vec_00683c40_shapec04_game::Resize(uint32_t n, const Elem_00683c40_shapec04_game* pVal)
{
    Elem_00683c40_shapec04_game* pBegin = mpBegin;
    Elem_00683c40_shapec04_game* pEnd = mpFinish;
    uint32_t nSize = static_cast<uint32_t>(pEnd - pBegin);
    if (n < nSize) {
        Elem_00683c40_shapec04_game* pNew = pBegin + n;
        uint8_t tag;
        mpFinish = Fn00683c40Erase(pEnd, pEnd, pNew, &tag, 0);
    } else {
        Fill(pEnd, n - nSize, pVal);
    }
}
#endif

struct Elem_00616cc0_shapec04_game {
    uint32_t mA;
    uint32_t mB;
    uint32_t mC;
};

struct Vec_00616cc0_shapec04_game {
    Elem_00616cc0_shapec04_game* mpBegin;
    Elem_00616cc0_shapec04_game* mpFinish;
    // STUB: 0x006161b0
    void Fill(Elem_00616cc0_shapec04_game* pPos, uint32_t n, const Elem_00616cc0_shapec04_game* pVal);
    void Resize(uint32_t n, const Elem_00616cc0_shapec04_game* pVal);
};

// STUB: 0x006143e0
Elem_00616cc0_shapec04_game* Fn00616cc0Erase(Elem_00616cc0_shapec04_game* pA, Elem_00616cc0_shapec04_game* pB, Elem_00616cc0_shapec04_game* pC, uint8_t* pTag, uint32_t n);

#ifdef OB_DRAFTS
// CLOSE: 0x00616cc0 score 8
void Vec_00616cc0_shapec04_game::Resize(uint32_t n, const Elem_00616cc0_shapec04_game* pVal)
{
    Elem_00616cc0_shapec04_game* pBegin = mpBegin;
    Elem_00616cc0_shapec04_game* pEnd = mpFinish;
    uint32_t nSize = static_cast<uint32_t>(pEnd - pBegin);
    if (n < nSize) {
        Elem_00616cc0_shapec04_game* pNew = pBegin + n;
        uint8_t tag;
        mpFinish = Fn00616cc0Erase(pEnd, pEnd, pNew, &tag, 0);
    } else {
        Fill(pEnd, n - nSize, pVal);
    }
}
#endif

struct Node_00511900_shapec04_game {
    uint8_t pad0[8];
    Node_00511900_shapec04_game* mpNext;
    Node_00511900_shapec04_game* mpChild;
    uint32_t mVtbl2;
    void* mpData2;
    uint8_t pad1[0x14];
    uint32_t mVtbl1;
    void* mpData1;
};

struct View_00511900_shapec04_game {
    void Fn(Node_00511900_shapec04_game* pNode);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00511900 score 6
void View_00511900_shapec04_game::Fn(Node_00511900_shapec04_game* pNode)
{
    while (pNode) {
        Fn(pNode->mpChild);
        Node_00511900_shapec04_game* pNext = pNode->mpNext;
        pNode->mVtbl1 = 0xa80810;
        if (pNode->mpData1) {
            _STL::__stl_delete(pNode->mpData1);
        }
        pNode->mVtbl2 = 0xa80810;
        if (pNode->mpData2) {
            _STL::__stl_delete(pNode->mpData2);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}
#endif

struct Node_00600520_shapec04_game {
    uint8_t pad0[8];
    Node_00600520_shapec04_game* mpNext;
    Node_00600520_shapec04_game* mpChild;
    uint32_t mVtbl2;
    void* mpData2;
    uint8_t pad1[0xc];
    uint32_t mVtbl1;
    void* mpData1;
};

struct View_00600520_shapec04_game {
    void Fn(Node_00600520_shapec04_game* pNode);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00600520 score 6
void View_00600520_shapec04_game::Fn(Node_00600520_shapec04_game* pNode)
{
    while (pNode) {
        Fn(pNode->mpChild);
        Node_00600520_shapec04_game* pNext = pNode->mpNext;
        pNode->mVtbl1 = 0xa80810;
        if (pNode->mpData1) {
            _STL::__stl_delete(pNode->mpData1);
        }
        pNode->mVtbl2 = 0xa80810;
        if (pNode->mpData2) {
            _STL::__stl_delete(pNode->mpData2);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}
#endif

struct Node_0081d0f0_shapec04_game {
    uint8_t pad0[8];
    Node_0081d0f0_shapec04_game* mpNext;
    Node_0081d0f0_shapec04_game* mpChild;
    uint32_t mVtbl2;
    void* mpData2;
    uint8_t pad1[0xc];
    uint32_t mVtbl1;
    void* mpData1;
};

struct View_0081d0f0_shapec04_game {
    void Fn(Node_0081d0f0_shapec04_game* pNode);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0081d0f0 score 6
void View_0081d0f0_shapec04_game::Fn(Node_0081d0f0_shapec04_game* pNode)
{
    while (pNode) {
        Fn(pNode->mpChild);
        Node_0081d0f0_shapec04_game* pNext = pNode->mpNext;
        pNode->mVtbl1 = 0xa80810;
        if (pNode->mpData1) {
            _STL::__stl_delete(pNode->mpData1);
        }
        pNode->mVtbl2 = 0xa80810;
        if (pNode->mpData2) {
            _STL::__stl_delete(pNode->mpData2);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}
#endif

struct Prim_00576e10_shapec04_game {
    virtual void S0();
    virtual void AddRef();
    uint8_t pad[0x20];
};

struct Sub_00576e10_shapec04_game {
    uint32_t mData;
};

struct View_00576e10_shapec04_game : Prim_00576e10_shapec04_game, Sub_00576e10_shapec04_game {
    // STUB: 0x00577470
    bool Base(uint32_t iid, void** ppv);
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00576e10
bool View_00576e10_shapec04_game::QueryInterface(uint32_t iid, void** ppv)
{
    *ppv = 0;
    if (iid == 0xca7b3f3c) {
        Sub_00576e10_shapec04_game* pSub = this;
        *ppv = pSub;
        if (pSub) {
            AddRef();
            return true;
        }
    }
    return Base(iid, ppv);
}

struct Prim_005790c0_shapec04_game {
    virtual void S0();
    virtual void AddRef();
    uint8_t pad[0x20];
};

struct Sub_005790c0_shapec04_game {
    uint32_t mData;
};

struct View_005790c0_shapec04_game : Prim_005790c0_shapec04_game, Sub_005790c0_shapec04_game {
    // STUB: 0x00577470
    bool Base(uint32_t iid, void** ppv);
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005790c0
bool View_005790c0_shapec04_game::QueryInterface(uint32_t iid, void** ppv)
{
    *ppv = 0;
    if (iid == 0x49b43f57) {
        Sub_005790c0_shapec04_game* pSub = this;
        *ppv = pSub;
        if (pSub) {
            AddRef();
            return true;
        }
    }
    return Base(iid, ppv);
}

struct Prim_0057f310_shapec04_game {
    virtual void S0();
    virtual void AddRef();
    uint8_t pad[0x20];
};

struct Sub_0057f310_shapec04_game {
    uint32_t mData;
};

struct View_0057f310_shapec04_game : Prim_0057f310_shapec04_game, Sub_0057f310_shapec04_game {
    // STUB: 0x00577470
    bool Base(uint32_t iid, void** ppv);
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0057f310
bool View_0057f310_shapec04_game::QueryInterface(uint32_t iid, void** ppv)
{
    *ppv = 0;
    if (iid == 0xa9b5ab9e) {
        Sub_0057f310_shapec04_game* pSub = this;
        *ppv = pSub;
        if (pSub) {
            AddRef();
            return true;
        }
    }
    return Base(iid, ppv);
}

struct Link_006a2e60_shapec04_game {
    Link_006a2e60_shapec04_game* mpNext;
    Link_006a2e60_shapec04_game* mpPrev;
};

struct Node_006a2e60_shapec04_game {
    uint8_t pad0[8];
    Node_006a2e60_shapec04_game* mpNext;
    Node_006a2e60_shapec04_game* mpChild;
    uint8_t pad1[0x4];
    Link_006a2e60_shapec04_game* mpList;
};

struct View_006a2e60_shapec04_game {
    void Fn(Node_006a2e60_shapec04_game* pNode);
};

// FUNCTION: 0x006a2e60
void View_006a2e60_shapec04_game::Fn(Node_006a2e60_shapec04_game* pNode)
{
    while (pNode) {
        Fn(pNode->mpChild);
        Link_006a2e60_shapec04_game* pLink = pNode->mpList->mpNext;
        Node_006a2e60_shapec04_game* pNext = pNode->mpNext;
        while (pLink != pNode->mpList) {
            Link_006a2e60_shapec04_game* pDead = pLink;
            pLink = pLink->mpNext;
            _STL::__stl_delete(pDead);
        }
        pNode->mpList->mpNext = pNode->mpList;
        pNode->mpList->mpPrev = pNode->mpList;
        if (pNode->mpList) {
            _STL::__stl_delete(pNode->mpList);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}

struct Link_006a2ed0_shapec04_game {
    Link_006a2ed0_shapec04_game* mpNext;
    Link_006a2ed0_shapec04_game* mpPrev;
};

struct Node_006a2ed0_shapec04_game {
    uint8_t pad0[8];
    Node_006a2ed0_shapec04_game* mpNext;
    Node_006a2ed0_shapec04_game* mpChild;
    uint8_t pad1[0x4];
    Link_006a2ed0_shapec04_game* mpList;
};

struct View_006a2ed0_shapec04_game {
    void Fn(Node_006a2ed0_shapec04_game* pNode);
};

// FUNCTION: 0x006a2ed0
void View_006a2ed0_shapec04_game::Fn(Node_006a2ed0_shapec04_game* pNode)
{
    while (pNode) {
        Fn(pNode->mpChild);
        Link_006a2ed0_shapec04_game* pLink = pNode->mpList->mpNext;
        Node_006a2ed0_shapec04_game* pNext = pNode->mpNext;
        while (pLink != pNode->mpList) {
            Link_006a2ed0_shapec04_game* pDead = pLink;
            pLink = pLink->mpNext;
            _STL::__stl_delete(pDead);
        }
        pNode->mpList->mpNext = pNode->mpList;
        pNode->mpList->mpPrev = pNode->mpList;
        if (pNode->mpList) {
            _STL::__stl_delete(pNode->mpList);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}

struct Link_004767d0_shapec04_game {
    Link_004767d0_shapec04_game* mpNext;
    Link_004767d0_shapec04_game* mpPrev;
};

struct Node_004767d0_shapec04_game {
    uint8_t pad0[8];
    Node_004767d0_shapec04_game* mpNext;
    Node_004767d0_shapec04_game* mpChild;
    uint8_t pad1[0x4];
    Link_004767d0_shapec04_game* mpList;
};

struct View_004767d0_shapec04_game {
    void Fn(Node_004767d0_shapec04_game* pNode);
};

// FUNCTION: 0x004767d0
void View_004767d0_shapec04_game::Fn(Node_004767d0_shapec04_game* pNode)
{
    while (pNode) {
        Fn(pNode->mpChild);
        Link_004767d0_shapec04_game* pLink = pNode->mpList->mpNext;
        Node_004767d0_shapec04_game* pNext = pNode->mpNext;
        while (pLink != pNode->mpList) {
            Link_004767d0_shapec04_game* pDead = pLink;
            pLink = pLink->mpNext;
            _STL::__stl_delete(pDead);
        }
        pNode->mpList->mpNext = pNode->mpList;
        pNode->mpList->mpPrev = pNode->mpList;
        if (pNode->mpList) {
            _STL::__stl_delete(pNode->mpList);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}

struct Elem_00479670_shapec04_game {
    uint8_t d[0x34];
    // STUB: 0x004788d0
    void Copy(const Elem_00479670_shapec04_game* pSrc);
};

struct View_00479670_shapec04_game {
    Elem_00479670_shapec04_game* mpBegin;
    Elem_00479670_shapec04_game* mpFinish;
    Elem_00479670_shapec04_game* mpCap;
    View_00479670_shapec04_game* Fn(const View_00479670_shapec04_game* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00479670 score 58
View_00479670_shapec04_game* View_00479670_shapec04_game::Fn(const View_00479670_shapec04_game* pSrc)
{
    uint32_t n = static_cast<uint32_t>(pSrc->mpFinish - pSrc->mpBegin);
    mpBegin = 0;
    mpFinish = 0;
    mpCap = 0;
    if (n) {
        Elem_00479670_shapec04_game* pDst = static_cast<Elem_00479670_shapec04_game*>(_STL::__stl_new(n * 0x34));
        mpBegin = pDst;
        mpFinish = pDst;
        mpCap = pDst + n;
        Elem_00479670_shapec04_game* pEnd = pSrc->mpFinish;
        for (Elem_00479670_shapec04_game* p = pSrc->mpBegin; p != pEnd; ++p, ++pDst) {
            if (pDst) {
                pDst->Copy(p);
            }
        }
        mpFinish = pDst;
    }
    return this;
}
#endif

struct Elem_0074b3e0_shapec04_game {
    uint8_t d[0x4c];
    // STUB: 0x00749040
    void Copy(const Elem_0074b3e0_shapec04_game* pSrc);
};

struct View_0074b3e0_shapec04_game {
    Elem_0074b3e0_shapec04_game* mpBegin;
    Elem_0074b3e0_shapec04_game* mpFinish;
    Elem_0074b3e0_shapec04_game* mpCap;
    View_0074b3e0_shapec04_game* Fn(const View_0074b3e0_shapec04_game* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0074b3e0 score 58
View_0074b3e0_shapec04_game* View_0074b3e0_shapec04_game::Fn(const View_0074b3e0_shapec04_game* pSrc)
{
    uint32_t n = static_cast<uint32_t>(pSrc->mpFinish - pSrc->mpBegin);
    mpBegin = 0;
    mpFinish = 0;
    mpCap = 0;
    if (n) {
        Elem_0074b3e0_shapec04_game* pDst = static_cast<Elem_0074b3e0_shapec04_game*>(_STL::__stl_new(n * 0x4c));
        mpBegin = pDst;
        mpFinish = pDst;
        mpCap = pDst + n;
        Elem_0074b3e0_shapec04_game* pEnd = pSrc->mpFinish;
        for (Elem_0074b3e0_shapec04_game* p = pSrc->mpBegin; p != pEnd; ++p, ++pDst) {
            if (pDst) {
                pDst->Copy(p);
            }
        }
        mpFinish = pDst;
    }
    return this;
}
#endif

struct Elem_0058a330_shapec04_game {
    uint8_t d[0x6c];
    // STUB: 0x005888a0
    void Copy(const Elem_0058a330_shapec04_game* pSrc);
};

struct View_0058a330_shapec04_game {
    Elem_0058a330_shapec04_game* mpBegin;
    Elem_0058a330_shapec04_game* mpFinish;
    Elem_0058a330_shapec04_game* mpCap;
    View_0058a330_shapec04_game* Fn(const View_0058a330_shapec04_game* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058a330 score 58
View_0058a330_shapec04_game* View_0058a330_shapec04_game::Fn(const View_0058a330_shapec04_game* pSrc)
{
    uint32_t n = static_cast<uint32_t>(pSrc->mpFinish - pSrc->mpBegin);
    mpBegin = 0;
    mpFinish = 0;
    mpCap = 0;
    if (n) {
        Elem_0058a330_shapec04_game* pDst = static_cast<Elem_0058a330_shapec04_game*>(_STL::__stl_new(n * 0x6c));
        mpBegin = pDst;
        mpFinish = pDst;
        mpCap = pDst + n;
        Elem_0058a330_shapec04_game* pEnd = pSrc->mpFinish;
        for (Elem_0058a330_shapec04_game* p = pSrc->mpBegin; p != pEnd; ++p, ++pDst) {
            if (pDst) {
                pDst->Copy(p);
            }
        }
        mpFinish = pDst;
    }
    return this;
}
#endif

struct Elem_004796f0_shapec04_game {
    uint8_t pad[0x28];
    void* mpData;
    uint8_t pad2[0x8];
};

struct View_004796f0_shapec04_game {
    Elem_004796f0_shapec04_game* mpBegin;
    Elem_004796f0_shapec04_game* mpFinish;
    Elem_004796f0_shapec04_game* Fn(Elem_004796f0_shapec04_game* pFirst, Elem_004796f0_shapec04_game* pLast);
};

// STUB: 0x004789f0
Elem_004796f0_shapec04_game* Fn004789f0Move(Elem_004796f0_shapec04_game* pA, Elem_004796f0_shapec04_game* pB, Elem_004796f0_shapec04_game* pC, uint8_t* pTag, uint32_t n);

#ifdef OB_DRAFTS
// CLOSE: 0x004796f0 score 10
Elem_004796f0_shapec04_game* View_004796f0_shapec04_game::Fn(Elem_004796f0_shapec04_game* pFirst, Elem_004796f0_shapec04_game* pLast)
{
    uint8_t tag;
    Elem_004796f0_shapec04_game* pNew = Fn004789f0Move(pLast, mpFinish, pFirst, &tag, 0);
    Elem_004796f0_shapec04_game* pEnd = mpFinish;
    for (Elem_004796f0_shapec04_game* p = pNew; p != pEnd; ++p) {
        if (p->mpData) {
            _STL::__stl_delete(p->mpData);
        }
    }
    mpFinish = pNew;
    return pFirst;
}
#endif

struct Elem_0062be80_shapec04_game {
    uint8_t pad[0x1c];
    void* mpData;
    uint8_t pad2[0x8];
};

struct View_0062be80_shapec04_game {
    Elem_0062be80_shapec04_game* mpBegin;
    Elem_0062be80_shapec04_game* mpFinish;
    Elem_0062be80_shapec04_game* Fn(Elem_0062be80_shapec04_game* pFirst, Elem_0062be80_shapec04_game* pLast);
};

// STUB: 0x00627220
Elem_0062be80_shapec04_game* Fn00627220Move(Elem_0062be80_shapec04_game* pA, Elem_0062be80_shapec04_game* pB, Elem_0062be80_shapec04_game* pC, uint8_t* pTag, uint32_t n);

#ifdef OB_DRAFTS
// CLOSE: 0x0062be80 score 10
Elem_0062be80_shapec04_game* View_0062be80_shapec04_game::Fn(Elem_0062be80_shapec04_game* pFirst, Elem_0062be80_shapec04_game* pLast)
{
    uint8_t tag;
    Elem_0062be80_shapec04_game* pNew = Fn00627220Move(pLast, mpFinish, pFirst, &tag, 0);
    Elem_0062be80_shapec04_game* pEnd = mpFinish;
    for (Elem_0062be80_shapec04_game* p = pNew; p != pEnd; ++p) {
        if (p->mpData) {
            _STL::__stl_delete(p->mpData);
        }
    }
    mpFinish = pNew;
    return pFirst;
}
#endif

struct Elem_006502f0_shapec04_game {
    uint8_t pad[0x18];
    void* mpData;
    uint8_t pad2[0x14];
};

struct View_006502f0_shapec04_game {
    Elem_006502f0_shapec04_game* mpBegin;
    Elem_006502f0_shapec04_game* mpFinish;
    Elem_006502f0_shapec04_game* Fn(Elem_006502f0_shapec04_game* pFirst, Elem_006502f0_shapec04_game* pLast);
};

// STUB: 0x0064fa60
Elem_006502f0_shapec04_game* Fn0064fa60Move(Elem_006502f0_shapec04_game* pA, Elem_006502f0_shapec04_game* pB, Elem_006502f0_shapec04_game* pC, uint8_t* pTag, uint32_t n);

#ifdef OB_DRAFTS
// CLOSE: 0x006502f0 score 10
Elem_006502f0_shapec04_game* View_006502f0_shapec04_game::Fn(Elem_006502f0_shapec04_game* pFirst, Elem_006502f0_shapec04_game* pLast)
{
    uint8_t tag;
    Elem_006502f0_shapec04_game* pNew = Fn0064fa60Move(pLast, mpFinish, pFirst, &tag, 0);
    Elem_006502f0_shapec04_game* pEnd = mpFinish;
    for (Elem_006502f0_shapec04_game* p = pNew; p != pEnd; ++p) {
        if (p->mpData) {
            _STL::__stl_delete(p->mpData);
        }
    }
    mpFinish = pNew;
    return pFirst;
}
#endif

struct Node_008bca80_shapec04_game {
    Node_008bca80_shapec04_game* mpNext;
    uint8_t pad2[0xc];
    void* mpData;
};

struct View_008bca80_shapec04_game {
    uint32_t pad0;
    Node_008bca80_shapec04_game** mpBegin;
    Node_008bca80_shapec04_game** mpEnd;
    uint32_t pad1;
    uint32_t mnCount;
    void Fn();
};

// FUNCTION: 0x008bca80
void View_008bca80_shapec04_game::Fn()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        Node_008bca80_shapec04_game* pNode = mpBegin[i];
        while (pNode) {
            Node_008bca80_shapec04_game* pNext = pNode->mpNext;
            if (pNode->mpData) {
                _STL::__stl_delete(pNode->mpData);
            }
            _STL::__stl_delete(pNode);
            pNode = pNext;
        }
        mpBegin[i] = 0;
    }
    mnCount = 0;
}

struct Node_00510de0_shapec04_game {
    Node_00510de0_shapec04_game* mpNext;
    uint8_t pad2[0x14];
    void* mpData;
};

struct View_00510de0_shapec04_game {
    uint32_t pad0;
    Node_00510de0_shapec04_game** mpBegin;
    Node_00510de0_shapec04_game** mpEnd;
    uint32_t pad1;
    uint32_t mnCount;
    void Fn();
};

// FUNCTION: 0x00510de0
void View_00510de0_shapec04_game::Fn()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        Node_00510de0_shapec04_game* pNode = mpBegin[i];
        while (pNode) {
            Node_00510de0_shapec04_game* pNext = pNode->mpNext;
            if (pNode->mpData) {
                _STL::__stl_delete(pNode->mpData);
            }
            _STL::__stl_delete(pNode);
            pNode = pNext;
        }
        mpBegin[i] = 0;
    }
    mnCount = 0;
}

struct Node_00718930_shapec04_game {
    Node_00718930_shapec04_game* mpNext;
    uint8_t pad2[0x20];
    void* mpData;
};

struct View_00718930_shapec04_game {
    uint32_t pad0;
    Node_00718930_shapec04_game** mpBegin;
    Node_00718930_shapec04_game** mpEnd;
    uint32_t pad1;
    uint32_t mnCount;
    void Fn();
};

// FUNCTION: 0x00718930
void View_00718930_shapec04_game::Fn()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        Node_00718930_shapec04_game* pNode = mpBegin[i];
        while (pNode) {
            Node_00718930_shapec04_game* pNext = pNode->mpNext;
            if (pNode->mpData) {
                _STL::__stl_delete(pNode->mpData);
            }
            _STL::__stl_delete(pNode);
            pNode = pNext;
        }
        mpBegin[i] = 0;
    }
    mnCount = 0;
}

// STUB: 0x00864d10
void Fn00864d10();

// STUB: 0x00864d30
void Fn00864d30();

// GLOBAL: 0x00b107f0
extern int32_t (*gfnB107f0)(uint32_t channel, int32_t value);

struct View_004e1530_shapec04_game {
    bool Slot(float f);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004e1530 score 1
bool View_004e1530_shapec04_game::Slot(float f)
{
    float v;
    if (f < 0.0f) {
        v = 0.0f;
    } else if (f > 1.0f) {
        v = 1.0f;
    } else {
        v = f;
    }
    f = v;
    Fn00864d10();
    int32_t r = gfnB107f0(0, static_cast<int32_t>(f * 127.0f));
    Fn00864d30();
    return r >= 0;
}
#endif

struct View_004e15a0_shapec04_game {
    bool Slot(float f);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004e15a0 score 1
bool View_004e15a0_shapec04_game::Slot(float f)
{
    float v;
    if (f < 0.0f) {
        v = 0.0f;
    } else if (f > 1.0f) {
        v = 1.0f;
    } else {
        v = f;
    }
    f = v;
    Fn00864d10();
    int32_t r = gfnB107f0(1, static_cast<int32_t>(f * 127.0f));
    Fn00864d30();
    return r >= 0;
}
#endif

struct View_004e1610_shapec04_game {
    bool Slot(float f);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004e1610 score 1
bool View_004e1610_shapec04_game::Slot(float f)
{
    float v;
    if (f < 0.0f) {
        v = 0.0f;
    } else if (f > 1.0f) {
        v = 1.0f;
    } else {
        v = f;
    }
    f = v;
    Fn00864d10();
    int32_t r = gfnB107f0(2, static_cast<int32_t>(f * 127.0f));
    Fn00864d30();
    return r >= 0;
}
#endif

// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t size);

struct Win_shapec04_game {
    virtual void S0();
    virtual void AddRef();
    virtual void Release();
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
    virtual void S51();
    virtual void S52();
    virtual void S53();
    virtual void S54();
    virtual void S55();
    virtual void S56();
    virtual void S57();
    virtual void S58();
    virtual void S59();
    virtual void S60();
    virtual void S61();
    virtual void S62();
    virtual void S63();
    virtual void S64();
    virtual void S65();
    virtual void S66();
    virtual void S67();
    virtual void S68();
    virtual void Slot69();
};

struct WinC_004e0c20_shapec04_game : Win_shapec04_game {
    // STUB: 0x0079ced0
    WinC_004e0c20_shapec04_game* Ctor();
};

struct View_004e0c20_shapec04_game {
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
    virtual void SetWin(Win_shapec04_game* pWin);
    uint8_t pad[0xe8];
    Win_shapec04_game* mpWin;
    // STUB: 0x0099c9df
    void SetFocus(Win_shapec04_game* pWin);
    bool Fn();
};

// FUNCTION: 0x004e0c20
bool View_004e0c20_shapec04_game::Fn()
{
    if (!mpWin) {
        void* pMem = Fn005e55e0(0x108);
        WinC_004e0c20_shapec04_game* pNew = pMem ? static_cast<WinC_004e0c20_shapec04_game*>(pMem)->Ctor() : 0;
        Win_shapec04_game* pOld = mpWin;
        if (pNew != pOld) {
            if (pNew) {
                pNew->AddRef();
            }
            mpWin = pNew;
            if (pOld) {
                pOld->Release();
            }
        }
        SetWin(mpWin);
        mpWin->Slot69();
        SetFocus(mpWin);
        return true;
    }
    return false;
}

struct WinC_004e0cb0_shapec04_game : Win_shapec04_game {
    // STUB: 0x007be4e0
    WinC_004e0cb0_shapec04_game* Ctor();
};

struct View_004e0cb0_shapec04_game {
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
    virtual void SetWin(Win_shapec04_game* pWin);
    uint8_t pad[0xe8];
    Win_shapec04_game* mpWin;
    // STUB: 0x0099c9df
    void SetFocus(Win_shapec04_game* pWin);
    bool Fn();
};

// FUNCTION: 0x004e0cb0
bool View_004e0cb0_shapec04_game::Fn()
{
    if (!mpWin) {
        void* pMem = Fn005e55e0(0x118);
        WinC_004e0cb0_shapec04_game* pNew = pMem ? static_cast<WinC_004e0cb0_shapec04_game*>(pMem)->Ctor() : 0;
        Win_shapec04_game* pOld = mpWin;
        if (pNew != pOld) {
            if (pNew) {
                pNew->AddRef();
            }
            mpWin = pNew;
            if (pOld) {
                pOld->Release();
            }
        }
        SetWin(mpWin);
        mpWin->Slot69();
        SetFocus(mpWin);
        return true;
    }
    return false;
}

struct WinC_004e0d40_shapec04_game : Win_shapec04_game {
    // STUB: 0x007b0c00
    WinC_004e0d40_shapec04_game* Ctor();
};

struct View_004e0d40_shapec04_game {
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
    virtual void SetWin(Win_shapec04_game* pWin);
    uint8_t pad[0xe8];
    Win_shapec04_game* mpWin;
    // STUB: 0x0099c9df
    void SetFocus(Win_shapec04_game* pWin);
    bool Fn();
};

// FUNCTION: 0x004e0d40
bool View_004e0d40_shapec04_game::Fn()
{
    if (!mpWin) {
        void* pMem = Fn005e55e0(0x200);
        WinC_004e0d40_shapec04_game* pNew = pMem ? static_cast<WinC_004e0d40_shapec04_game*>(pMem)->Ctor() : 0;
        Win_shapec04_game* pOld = mpWin;
        if (pNew != pOld) {
            if (pNew) {
                pNew->AddRef();
            }
            mpWin = pNew;
            if (pOld) {
                pOld->Release();
            }
        }
        SetWin(mpWin);
        mpWin->Slot69();
        SetFocus(mpWin);
        return true;
    }
    return false;
}

struct Unk_shapec04_game {
    virtual bool QueryInterface(uint32_t iid, uint32_t* ppv);
};

struct Found_shapec04_game {
    virtual void S0();
    virtual void S1();
    virtual void Release();
    virtual Unk_shapec04_game* GetUnknown();
};

struct Registry_shapec04_game {
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
    virtual void S51();
    virtual void S52();
    virtual void S53();
    virtual void S54();
    virtual void S55();
    virtual void S56();
    virtual void S57();
    virtual void S58();
    virtual void S59();
    virtual void S60();
    virtual void S61();
    virtual void S62();
    virtual void S63();
    virtual void S64();
    virtual bool Find(uint32_t a, uint32_t b, uint32_t c, Found_shapec04_game** ppOut);
};

// GLOBAL: 0x00b43dd0
extern Registry_shapec04_game* gpB43dd0;

struct View_004b9ff0_shapec04_game {
    uint8_t pad[0x78];
    uint32_t mField;
    bool Fn(uint32_t a, uint32_t b, uint32_t* pOut);
};

// FUNCTION: 0x004b9ff0
bool View_004b9ff0_shapec04_game::Fn(uint32_t a, uint32_t b, uint32_t* pOut)
{
    Registry_shapec04_game* pReg = gpB43dd0;
    Found_shapec04_game* pFound = 0;
    bool bOk = false;
    *pOut = 0;
    if (pReg->Find(a, b, mField, &pFound)) {
        Unk_shapec04_game* pUnk = pFound->GetUnknown();
        uint32_t iface = 0;
        if (pUnk && pUnk->QueryInterface(0xc9b6d7d6, &iface)) {
            *pOut = iface;
            bOk = true;
        }
        pFound->Release();
    }
    return bOk;
}

struct View_005630c0_shapec04_game {
    uint8_t pad[0x88];
    uint32_t mField;
    bool Fn(uint32_t a, uint32_t b, uint32_t* pOut);
};

// FUNCTION: 0x005630c0
bool View_005630c0_shapec04_game::Fn(uint32_t a, uint32_t b, uint32_t* pOut)
{
    Registry_shapec04_game* pReg = gpB43dd0;
    Found_shapec04_game* pFound = 0;
    bool bOk = false;
    *pOut = 0;
    if (pReg->Find(a, b, mField, &pFound)) {
        Unk_shapec04_game* pUnk = pFound->GetUnknown();
        uint32_t iface = 0;
        if (pUnk && pUnk->QueryInterface(0xa821ef94, &iface)) {
            *pOut = iface;
            bOk = true;
        }
        pFound->Release();
    }
    return bOk;
}

struct View_00563140_shapec04_game {
    uint8_t pad[0x84];
    uint32_t mField;
    bool Fn(uint32_t a, uint32_t b, uint32_t* pOut);
};

// FUNCTION: 0x00563140
bool View_00563140_shapec04_game::Fn(uint32_t a, uint32_t b, uint32_t* pOut)
{
    Registry_shapec04_game* pReg = gpB43dd0;
    Found_shapec04_game* pFound = 0;
    bool bOk = false;
    *pOut = 0;
    if (pReg->Find(a, b, mField, &pFound)) {
        Unk_shapec04_game* pUnk = pFound->GetUnknown();
        uint32_t iface = 0;
        if (pUnk && pUnk->QueryInterface(0xa9b40f05, &iface)) {
            *pOut = iface;
            bOk = true;
        }
        pFound->Release();
    }
    return bOk;
}

struct V4_shapec04_game {
    uint32_t d[4];
};

// STUB: 0x00530180
void Fn00530180(void* pOut, V4_shapec04_game a, V4_shapec04_game b, V4_shapec04_game c, void** ppSlot);

#ifdef OB_DRAFTS
// CLOSE: 0x00530530 score 53
void* Fn00530530(void* pOut, V4_shapec04_game a, V4_shapec04_game b, V4_shapec04_game c)
{
    void* pRet = pOut;
    Fn00530180(pOut, a, b, c, &pOut);
    return pRet;
}
#endif

// STUB: 0x0052fcb0
void Fn0052fcb0(void* pOut, V4_shapec04_game a, V4_shapec04_game b, V4_shapec04_game c, void** ppSlot);

#ifdef OB_DRAFTS
// CLOSE: 0x00530630 score 53
void* Fn00530630(void* pOut, V4_shapec04_game a, V4_shapec04_game b, V4_shapec04_game c)
{
    void* pRet = pOut;
    Fn0052fcb0(pOut, a, b, c, &pOut);
    return pRet;
}
#endif

// STUB: 0x005305b0
void Fn005305b0(void* pOut, V4_shapec04_game a, V4_shapec04_game b, V4_shapec04_game c, void** ppSlot);

#ifdef OB_DRAFTS
// CLOSE: 0x005306b0 score 53
void* Fn005306b0(void* pOut, V4_shapec04_game a, V4_shapec04_game b, V4_shapec04_game c)
{
    void* pRet = pOut;
    Fn005305b0(pOut, a, b, c, &pOut);
    return pRet;
}
#endif

