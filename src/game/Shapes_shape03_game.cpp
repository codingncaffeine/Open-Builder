// Shape families of packet shape03_game, written by scratch/s16/gen/shape03_game/gen.py.
#include "common/types.h"
#include "common/compiler.h"

// The service locator of the original.
struct OB_NOVTABLE Svc_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void GetService(uint32_t id, uint32_t iid, void** ppOut) = 0;
};

// STUB: 0x008793ec
Svc_shape03_game* Fn008793ec();

struct Elem_00889930_shape03_game {
    // STUB: 0x008895b0
    void Construct(const Elem_00889930_shape03_game* pSrc);
    uint8_t mData[48];
};

// FUNCTION: 0x00889930
Elem_00889930_shape03_game* Fn00889930(Elem_00889930_shape03_game* pFirst, Elem_00889930_shape03_game* pLast, Elem_00889930_shape03_game* pDest)
{
    Elem_00889930_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct OB_NOVTABLE View_009899a0_shape03_game {
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
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x009899a0
uint32_t View_009899a0_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_00989ae0_shape03_game {
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
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x00989ae0
uint32_t View_00989ae0_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_009745b0_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x009745b0
uint32_t View_009745b0_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_007ff020_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x007ff020
uint32_t View_007ff020_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_008016b0_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void S7() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[6];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x008016b0
uint32_t View_008016b0_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct Elem_008022b0_shape03_game {
    // STUB: 0x00802130
    void Construct(const Elem_008022b0_shape03_game* pSrc);
    uint8_t mData[52];
};

// FUNCTION: 0x008022b0
Elem_008022b0_shape03_game* Fn008022b0(Elem_008022b0_shape03_game* pFirst, Elem_008022b0_shape03_game* pLast, Elem_008022b0_shape03_game* pDest)
{
    Elem_008022b0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct View_007ce170_shape03_game {
    void* mpObj;
    View_007ce170_shape03_game* Fn007ce170();
};

// FUNCTION: 0x007ce170
View_007ce170_shape03_game* View_007ce170_shape03_game::Fn007ce170()
{
    mpObj = 0;
    Svc_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0xe9d27715, 0x49d28666, &mpObj);
    }
    return this;
}

struct Elem_007d06f0_shape03_game {
    // STUB: 0x007d0580
    void Construct(const Elem_007d06f0_shape03_game* pSrc);
    uint8_t mData[124];
};

// FUNCTION: 0x007d06f0
Elem_007d06f0_shape03_game* Fn007d06f0(Elem_007d06f0_shape03_game* pFirst, Elem_007d06f0_shape03_game* pLast, Elem_007d06f0_shape03_game* pDest)
{
    Elem_007d06f0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_007d51a0_shape03_game {
    // STUB: 0x007d39c0
    void Construct(const Elem_007d51a0_shape03_game* pSrc);
    uint8_t mData[104];
};

// FUNCTION: 0x007d51a0
Elem_007d51a0_shape03_game* Fn007d51a0(Elem_007d51a0_shape03_game* pFirst, Elem_007d51a0_shape03_game* pLast, Elem_007d51a0_shape03_game* pDest)
{
    Elem_007d51a0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_007d51d0_shape03_game {
    // STUB: 0x007d39c0
    void Construct(const Elem_007d51d0_shape03_game* pSrc);
    uint8_t mData[104];
};

// FUNCTION: 0x007d51d0
Elem_007d51d0_shape03_game* Fn007d51d0(Elem_007d51d0_shape03_game* pDest, uint32_t nCount, const Elem_007d51d0_shape03_game* pSrc)
{
    Elem_007d51d0_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_004789c0_shape03_game {
    // STUB: 0x004788d0
    void Construct(const Elem_004789c0_shape03_game* pSrc);
    uint8_t mData[52];
};

// FUNCTION: 0x004789c0
Elem_004789c0_shape03_game* Fn004789c0(Elem_004789c0_shape03_game* pFirst, Elem_004789c0_shape03_game* pLast, Elem_004789c0_shape03_game* pDest)
{
    Elem_004789c0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_007362e0_shape03_game {
    // STUB: 0x007359f0
    void Construct(const Elem_007362e0_shape03_game* pSrc);
    uint8_t mData[180];
};

// FUNCTION: 0x007362e0
Elem_007362e0_shape03_game* Fn007362e0(Elem_007362e0_shape03_game* pFirst, Elem_007362e0_shape03_game* pLast, Elem_007362e0_shape03_game* pDest)
{
    Elem_007362e0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct OB_NOVTABLE View_00741f70_shape03_game {
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
    virtual void S49() = 0;
    virtual void S50() = 0;
    virtual void S51() = 0;
    virtual void S52() = 0;
    virtual void S53() = 0;
    virtual void S54() = 0;
    virtual void S55() = 0;
    virtual void S56() = 0;
    virtual void S57() = 0;
    virtual void S58() = 0;
    virtual void S59() = 0;
    virtual void S60() = 0;
    virtual void S61() = 0;
    virtual void S62() = 0;
    virtual void S63() = 0;
    virtual void S64() = 0;
    virtual void S65() = 0;
    virtual void S66() = 0;
    virtual void S67() = 0;
    virtual void S68() = 0;
    virtual void S69() = 0;
    virtual void S70() = 0;
    virtual void S71() = 0;
    virtual void S72() = 0;
    virtual void S73() = 0;
    virtual void S74() = 0;
    virtual void S75() = 0;
    virtual void S76() = 0;
    virtual void S77() = 0;
    virtual void S78() = 0;
    virtual void S79() = 0;
    virtual void S80() = 0;
    virtual void S81() = 0;
    virtual void S82() = 0;
    virtual void S83() = 0;
    virtual void S84() = 0;
    virtual void S85() = 0;
    virtual void S86() = 0;
    virtual void S87() = 0;
    virtual void S88() = 0;
    virtual void S89() = 0;
    virtual void S90() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[3];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x00741f70
uint32_t View_00741f70_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct Elem_00749f20_shape03_game {
    // STUB: 0x00749040
    void Construct(const Elem_00749f20_shape03_game* pSrc);
    uint8_t mData[76];
};

// FUNCTION: 0x00749f20
Elem_00749f20_shape03_game* Fn00749f20(Elem_00749f20_shape03_game* pFirst, Elem_00749f20_shape03_game* pLast, Elem_00749f20_shape03_game* pDest)
{
    Elem_00749f20_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_007616e0_shape03_game {
    // STUB: 0x00761590
    void Construct(const Elem_007616e0_shape03_game* pSrc);
    uint8_t mData[56];
};

// FUNCTION: 0x007616e0
Elem_007616e0_shape03_game* Fn007616e0(Elem_007616e0_shape03_game* pFirst, Elem_007616e0_shape03_game* pLast, Elem_007616e0_shape03_game* pDest)
{
    Elem_007616e0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_0042fbd0_shape03_game {
    // STUB: 0x0042fb40
    void Construct(const Elem_0042fbd0_shape03_game* pSrc);
    uint8_t mData[48];
};

// FUNCTION: 0x0042fbd0
Elem_0042fbd0_shape03_game* Fn0042fbd0(Elem_0042fbd0_shape03_game* pFirst, Elem_0042fbd0_shape03_game* pLast, Elem_0042fbd0_shape03_game* pDest)
{
    Elem_0042fbd0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_00440b20_shape03_game {
    // STUB: 0x00624d60
    void Construct(const Elem_00440b20_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x00440b20
Elem_00440b20_shape03_game* Fn00440b20(Elem_00440b20_shape03_game* pFirst, Elem_00440b20_shape03_game* pLast, Elem_00440b20_shape03_game* pDest)
{
    Elem_00440b20_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct View_004ed100_shape03_game {
    void* mpObj;
    View_004ed100_shape03_game* Fn004ed100();
};

// FUNCTION: 0x004ed100
View_004ed100_shape03_game* View_004ed100_shape03_game::Fn004ed100()
{
    mpObj = 0;
    Svc_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0x1b2ce671, 0xbb1bd9a8, &mpObj);
    }
    return this;
}

struct Elem_0050f230_shape03_game {
    // STUB: 0x00459e80
    void Construct(const Elem_0050f230_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x0050f230
Elem_0050f230_shape03_game* Fn0050f230(Elem_0050f230_shape03_game* pFirst, Elem_0050f230_shape03_game* pLast, Elem_0050f230_shape03_game* pDest)
{
    Elem_0050f230_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_00511960_shape03_game {
    // STUB: 0x00510fa0
    void Construct(const Elem_00511960_shape03_game* pSrc);
    uint8_t mData[108];
};

// FUNCTION: 0x00511960
Elem_00511960_shape03_game* Fn00511960(Elem_00511960_shape03_game* pFirst, Elem_00511960_shape03_game* pLast, Elem_00511960_shape03_game* pDest)
{
    Elem_00511960_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct OB_NOVTABLE View_005f4800_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x005f4800
uint32_t View_005f4800_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_005ffe90_shape03_game {
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
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x005ffe90
uint32_t View_005ffe90_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_00602190_shape03_game {
    void* mpObj;
    View_00602190_shape03_game* Fn00602190();
};

// FUNCTION: 0x00602190
View_00602190_shape03_game* View_00602190_shape03_game::Fn00602190()
{
    mpObj = 0;
    Svc_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0x8414a2c2, 0x6054a2fb, &mpObj);
    }
    return this;
}

struct OB_NOVTABLE View_00603630_shape03_game {
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
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x00603630
uint32_t View_00603630_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_0060c7e0_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[3];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x0060c7e0
uint32_t View_0060c7e0_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_0060c840_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[25];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x0060c840
uint32_t View_0060c840_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_006107d0_shape03_game {
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
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[2];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x006107d0
uint32_t View_006107d0_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_00610800_shape03_game {
    void* mpObj;
    View_00610800_shape03_game* Fn00610800();
};

// FUNCTION: 0x00610800
View_00610800_shape03_game* View_00610800_shape03_game::Fn00610800()
{
    mpObj = 0;
    Svc_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0x441e5070, 0x54b7d5, &mpObj);
    }
    return this;
}

struct Elem_00641640_shape03_game {
    // STUB: 0x00640fa0
    void Construct(const Elem_00641640_shape03_game* pSrc);
    uint8_t mData[376];
};

// FUNCTION: 0x00641640
Elem_00641640_shape03_game* Fn00641640(Elem_00641640_shape03_game* pFirst, Elem_00641640_shape03_game* pLast, Elem_00641640_shape03_game* pDest)
{
    Elem_00641640_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_00641680_shape03_game {
    // STUB: 0x00640fa0
    void Construct(const Elem_00641680_shape03_game* pSrc);
    uint8_t mData[376];
};

// FUNCTION: 0x00641680
Elem_00641680_shape03_game* Fn00641680(Elem_00641680_shape03_game* pDest, uint32_t nCount, const Elem_00641680_shape03_game* pSrc)
{
    Elem_00641680_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_006774e0_shape03_game {
    // STUB: 0x0051fe90
    void Construct(const Elem_006774e0_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x006774e0
Elem_006774e0_shape03_game* Fn006774e0(Elem_006774e0_shape03_game* pFirst, Elem_006774e0_shape03_game* pLast, Elem_006774e0_shape03_game* pDest)
{
    Elem_006774e0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_006812c0_shape03_game {
    // STUB: 0x00680d20
    void Construct(const Elem_006812c0_shape03_game* pSrc);
    uint8_t mData[44];
};

// FUNCTION: 0x006812c0
Elem_006812c0_shape03_game* Fn006812c0(Elem_006812c0_shape03_game* pFirst, Elem_006812c0_shape03_game* pLast, Elem_006812c0_shape03_game* pDest)
{
    Elem_006812c0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_0068d660_shape03_game {
    // STUB: 0x00462620
    void Construct(const Elem_0068d660_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x0068d660
Elem_0068d660_shape03_game* Fn0068d660(Elem_0068d660_shape03_game* pFirst, Elem_0068d660_shape03_game* pLast, Elem_0068d660_shape03_game* pDest)
{
    Elem_0068d660_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_006b49f0_shape03_game {
    // STUB: 0x005f4430
    void Construct(const Elem_006b49f0_shape03_game* pSrc);
    uint8_t mData[16];
};

// FUNCTION: 0x006b49f0
Elem_006b49f0_shape03_game* Fn006b49f0(Elem_006b49f0_shape03_game* pFirst, Elem_006b49f0_shape03_game* pLast, Elem_006b49f0_shape03_game* pDest)
{
    Elem_006b49f0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_006b4a20_shape03_game {
    // STUB: 0x005f4430
    void Construct(const Elem_006b4a20_shape03_game* pSrc);
    uint8_t mData[16];
};

// FUNCTION: 0x006b4a20
Elem_006b4a20_shape03_game* Fn006b4a20(Elem_006b4a20_shape03_game* pDest, uint32_t nCount, const Elem_006b4a20_shape03_game* pSrc)
{
    Elem_006b4a20_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_006c1070_shape03_game {
    // STUB: 0x004c9470
    void Construct(const Elem_006c1070_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x006c1070
Elem_006c1070_shape03_game* Fn006c1070(Elem_006c1070_shape03_game* pDest, uint32_t nCount, const Elem_006c1070_shape03_game* pSrc)
{
    Elem_006c1070_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct OB_NOVTABLE View_006f0ea0_shape03_game {
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
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[3];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x006f0ea0
uint32_t View_006f0ea0_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct Elem_00706e10_shape03_game {
    // STUB: 0x00462f00
    void Construct(const Elem_00706e10_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x00706e10
Elem_00706e10_shape03_game* Fn00706e10(Elem_00706e10_shape03_game* pFirst, Elem_00706e10_shape03_game* pLast, Elem_00706e10_shape03_game* pDest)
{
    Elem_00706e10_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_0076c9c0_shape03_game {
    // STUB: 0x0076bdf0
    void Construct(const Elem_0076c9c0_shape03_game* pSrc);
    uint8_t mData[48];
};

// FUNCTION: 0x0076c9c0
Elem_0076c9c0_shape03_game* Fn0076c9c0(Elem_0076c9c0_shape03_game* pFirst, Elem_0076c9c0_shape03_game* pLast, Elem_0076c9c0_shape03_game* pDest)
{
    Elem_0076c9c0_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_0076c9f0_shape03_game {
    // STUB: 0x0076bdf0
    void Construct(const Elem_0076c9f0_shape03_game* pSrc);
    uint8_t mData[48];
};

// FUNCTION: 0x0076c9f0
Elem_0076c9f0_shape03_game* Fn0076c9f0(Elem_0076c9f0_shape03_game* pDest, uint32_t nCount, const Elem_0076c9f0_shape03_game* pSrc)
{
    Elem_0076c9f0_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_007aed60_shape03_game {
    // STUB: 0x007ae7b0
    void Construct(const Elem_007aed60_shape03_game* pSrc);
    uint8_t mData[128];
};

// FUNCTION: 0x007aed60
Elem_007aed60_shape03_game* Fn007aed60(Elem_007aed60_shape03_game* pFirst, Elem_007aed60_shape03_game* pLast, Elem_007aed60_shape03_game* pDest)
{
    Elem_007aed60_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_007aeda0_shape03_game {
    // STUB: 0x007ae7b0
    void Construct(const Elem_007aeda0_shape03_game* pSrc);
    uint8_t mData[128];
};

// FUNCTION: 0x007aeda0
Elem_007aeda0_shape03_game* Fn007aeda0(Elem_007aeda0_shape03_game* pDest, uint32_t nCount, const Elem_007aeda0_shape03_game* pSrc)
{
    Elem_007aeda0_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct View_007b2480_shape03_game {
    void* mpObj;
    View_007b2480_shape03_game* Fn007b2480();
};

// FUNCTION: 0x007b2480
View_007b2480_shape03_game* View_007b2480_shape03_game::Fn007b2480()
{
    mpObj = 0;
    Svc_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0xc2c2eb0f, 0x22c2eb1f, &mpObj);
    }
    return this;
}

