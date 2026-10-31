// Shape families of packet top_shape03_game, written by scratch/s16/gen/top_shape03_game/gen.py.
#include "common/types.h"
#include "common/compiler.h"

// The service locator of the original.
struct OB_NOVTABLE Svc_top_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void GetService(uint32_t id, uint32_t iid, void** ppOut) = 0;
};

// STUB: 0x008793ec
Svc_top_shape03_game* Fn008793ec();

struct View_00411840_top_shape03_game {
    void* mpObj;
    View_00411840_top_shape03_game* Fn00411840();
};

// FUNCTION: 0x00411840
View_00411840_top_shape03_game* View_00411840_top_shape03_game::Fn00411840()
{
    mpObj = 0;
    Svc_top_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0x3ae4bea3, 0x3ae4beab, &mpObj);
    }
    return this;
}

struct View_004177c0_top_shape03_game {
    void* mpObj;
    View_004177c0_top_shape03_game* Fn004177c0();
};

// FUNCTION: 0x004177c0
View_004177c0_top_shape03_game* View_004177c0_top_shape03_game::Fn004177c0()
{
    mpObj = 0;
    Svc_top_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0xa417445e, 0x5a4, &mpObj);
    }
    return this;
}

struct OB_NOVTABLE View_0041d460_top_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[1];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x0041d460
uint32_t View_0041d460_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_004302e0_top_shape03_game {
    void* mpObj;
    View_004302e0_top_shape03_game* Fn004302e0();
};

// FUNCTION: 0x004302e0
View_004302e0_top_shape03_game* View_004302e0_top_shape03_game::Fn004302e0()
{
    mpObj = 0;
    Svc_top_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0x23cecba0, 0x106077d2, &mpObj);
    }
    return this;
}

struct Elem_0043b1d0_top_shape03_game {
    // STUB: 0x0043b100
    void Construct(const Elem_0043b1d0_top_shape03_game* pSrc);
    uint8_t mData[48];
};

// FUNCTION: 0x0043b1d0
Elem_0043b1d0_top_shape03_game* Fn0043b1d0(Elem_0043b1d0_top_shape03_game* pFirst, Elem_0043b1d0_top_shape03_game* pLast, Elem_0043b1d0_top_shape03_game* pDest)
{
    Elem_0043b1d0_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_00447040_top_shape03_game {
    // STUB: 0x00446e40
    void Construct(const Elem_00447040_top_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x00447040
Elem_00447040_top_shape03_game* Fn00447040(Elem_00447040_top_shape03_game* pFirst, Elem_00447040_top_shape03_game* pLast, Elem_00447040_top_shape03_game* pDest)
{
    Elem_00447040_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_00447070_top_shape03_game {
    // STUB: 0x00446e40
    void Construct(const Elem_00447070_top_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x00447070
Elem_00447070_top_shape03_game* Fn00447070(Elem_00447070_top_shape03_game* pDest, uint32_t nCount, const Elem_00447070_top_shape03_game* pSrc)
{
    Elem_00447070_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_004614d0_top_shape03_game {
    // STUB: 0x00459e80
    void Construct(const Elem_004614d0_top_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x004614d0
Elem_004614d0_top_shape03_game* Fn004614d0(Elem_004614d0_top_shape03_game* pDest, uint32_t nCount, const Elem_004614d0_top_shape03_game* pSrc)
{
    Elem_004614d0_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_004626b0_top_shape03_game {
    // STUB: 0x00462620
    void Construct(const Elem_004626b0_top_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x004626b0
Elem_004626b0_top_shape03_game* Fn004626b0(Elem_004626b0_top_shape03_game* pDest, uint32_t nCount, const Elem_004626b0_top_shape03_game* pSrc)
{
    Elem_004626b0_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_00463e70_top_shape03_game {
    // STUB: 0x00463740
    void Construct(const Elem_00463e70_top_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x00463e70
Elem_00463e70_top_shape03_game* Fn00463e70(Elem_00463e70_top_shape03_game* pDest, uint32_t nCount, const Elem_00463e70_top_shape03_game* pSrc)
{
    Elem_00463e70_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_004647e0_top_shape03_game {
    // STUB: 0x00464760
    void Construct(const Elem_004647e0_top_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x004647e0
Elem_004647e0_top_shape03_game* Fn004647e0(Elem_004647e0_top_shape03_game* pDest, uint32_t nCount, const Elem_004647e0_top_shape03_game* pSrc)
{
    Elem_004647e0_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_00465330_top_shape03_game {
    // STUB: 0x004652f0
    void Construct(const Elem_00465330_top_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x00465330
Elem_00465330_top_shape03_game* Fn00465330(Elem_00465330_top_shape03_game* pDest, uint32_t nCount, const Elem_00465330_top_shape03_game* pSrc)
{
    Elem_00465330_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_00465eb0_top_shape03_game {
    // STUB: 0x00462f00
    void Construct(const Elem_00465eb0_top_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x00465eb0
Elem_00465eb0_top_shape03_game* Fn00465eb0(Elem_00465eb0_top_shape03_game* pDest, uint32_t nCount, const Elem_00465eb0_top_shape03_game* pSrc)
{
    Elem_00465eb0_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct OB_NOVTABLE View_0048c920_top_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[1];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x0048c920
uint32_t View_0048c920_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_004d7bb0_top_shape03_game {
    void* mpObj;
    View_004d7bb0_top_shape03_game* Fn004d7bb0();
};

// FUNCTION: 0x004d7bb0
View_004d7bb0_top_shape03_game* View_004d7bb0_top_shape03_game::Fn004d7bb0()
{
    mpObj = 0;
    Svc_top_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0x64063387, 0xc1085722, &mpObj);
    }
    return this;
}

struct View_004de430_top_shape03_game {
    void* mpObj;
    View_004de430_top_shape03_game* Fn004de430();
};

// FUNCTION: 0x004de430
View_004de430_top_shape03_game* View_004de430_top_shape03_game::Fn004de430()
{
    mpObj = 0;
    Svc_top_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0x2073215d, 0xe0203660, &mpObj);
    }
    return this;
}

struct OB_NOVTABLE View_004e82b0_top_shape03_game {
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
    uint32_t mPad[3];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x004e82b0
uint32_t View_004e82b0_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_004edfd0_top_shape03_game {
    void* mpObj;
    View_004edfd0_top_shape03_game* Fn004edfd0();
};

// FUNCTION: 0x004edfd0
View_004edfd0_top_shape03_game* View_004edfd0_top_shape03_game::Fn004edfd0()
{
    mpObj = 0;
    Svc_top_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0x1af85bfb, 0x3af85bb7, &mpObj);
    }
    return this;
}

struct View_00562da0_top_shape03_game {
    void* mpObj;
    View_00562da0_top_shape03_game* Fn00562da0();
};

// FUNCTION: 0x00562da0
View_00562da0_top_shape03_game* View_00562da0_top_shape03_game::Fn00562da0()
{
    mpObj = 0;
    Svc_top_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0xeb903a32, 0xcb90253a, &mpObj);
    }
    return this;
}

struct Elem_00588330_top_shape03_game {
    // STUB: 0x00587890
    void Construct(const Elem_00588330_top_shape03_game* pSrc);
    uint8_t mData[100];
};

// FUNCTION: 0x00588330
Elem_00588330_top_shape03_game* Fn00588330(Elem_00588330_top_shape03_game* pFirst, Elem_00588330_top_shape03_game* pLast, Elem_00588330_top_shape03_game* pDest)
{
    Elem_00588330_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_00588390_top_shape03_game {
    // STUB: 0x00587890
    void Construct(const Elem_00588390_top_shape03_game* pSrc);
    uint8_t mData[100];
};

// FUNCTION: 0x00588390
Elem_00588390_top_shape03_game* Fn00588390(Elem_00588390_top_shape03_game* pDest, uint32_t nCount, const Elem_00588390_top_shape03_game* pSrc)
{
    Elem_00588390_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_00589490_top_shape03_game {
    // STUB: 0x005888a0
    void Construct(const Elem_00589490_top_shape03_game* pSrc);
    uint8_t mData[108];
};

// FUNCTION: 0x00589490
Elem_00589490_top_shape03_game* Fn00589490(Elem_00589490_top_shape03_game* pFirst, Elem_00589490_top_shape03_game* pLast, Elem_00589490_top_shape03_game* pDest)
{
    Elem_00589490_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_0058b2d0_top_shape03_game {
    // STUB: 0x0058a8c0
    void Construct(const Elem_0058b2d0_top_shape03_game* pSrc);
    uint8_t mData[56];
};

// FUNCTION: 0x0058b2d0
Elem_0058b2d0_top_shape03_game* Fn0058b2d0(Elem_0058b2d0_top_shape03_game* pFirst, Elem_0058b2d0_top_shape03_game* pLast, Elem_0058b2d0_top_shape03_game* pDest)
{
    Elem_0058b2d0_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_0058b300_top_shape03_game {
    // STUB: 0x0058a8c0
    void Construct(const Elem_0058b300_top_shape03_game* pSrc);
    uint8_t mData[56];
};

// FUNCTION: 0x0058b300
Elem_0058b300_top_shape03_game* Fn0058b300(Elem_0058b300_top_shape03_game* pDest, uint32_t nCount, const Elem_0058b300_top_shape03_game* pSrc)
{
    Elem_0058b300_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_0058ef60_top_shape03_game {
    // STUB: 0x0058e020
    void Construct(const Elem_0058ef60_top_shape03_game* pSrc);
    uint8_t mData[68];
};

// FUNCTION: 0x0058ef60
Elem_0058ef60_top_shape03_game* Fn0058ef60(Elem_0058ef60_top_shape03_game* pFirst, Elem_0058ef60_top_shape03_game* pLast, Elem_0058ef60_top_shape03_game* pDest)
{
    Elem_0058ef60_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_005a63f0_top_shape03_game {
    // STUB: 0x005a6220
    void Construct(const Elem_005a63f0_top_shape03_game* pSrc);
    uint8_t mData[60];
};

// FUNCTION: 0x005a63f0
Elem_005a63f0_top_shape03_game* Fn005a63f0(Elem_005a63f0_top_shape03_game* pFirst, Elem_005a63f0_top_shape03_game* pLast, Elem_005a63f0_top_shape03_game* pDest)
{
    Elem_005a63f0_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_005a6420_top_shape03_game {
    // STUB: 0x005ec750
    void Construct(const Elem_005a6420_top_shape03_game* pSrc);
    uint8_t mData[64];
};

// FUNCTION: 0x005a6420
Elem_005a6420_top_shape03_game* Fn005a6420(Elem_005a6420_top_shape03_game* pFirst, Elem_005a6420_top_shape03_game* pLast, Elem_005a6420_top_shape03_game* pDest)
{
    Elem_005a6420_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_005a6450_top_shape03_game {
    // STUB: 0x005ec750
    void Construct(const Elem_005a6450_top_shape03_game* pSrc);
    uint8_t mData[64];
};

// FUNCTION: 0x005a6450
Elem_005a6450_top_shape03_game* Fn005a6450(Elem_005a6450_top_shape03_game* pDest, uint32_t nCount, const Elem_005a6450_top_shape03_game* pSrc)
{
    Elem_005a6450_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_005ab660_top_shape03_game {
    // STUB: 0x005888a0
    void Construct(const Elem_005ab660_top_shape03_game* pSrc);
    uint8_t mData[108];
};

// FUNCTION: 0x005ab660
Elem_005ab660_top_shape03_game* Fn005ab660(Elem_005ab660_top_shape03_game* pDest, uint32_t nCount, const Elem_005ab660_top_shape03_game* pSrc)
{
    Elem_005ab660_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct View_005c3e80_top_shape03_game {
    void* mpObj;
    View_005c3e80_top_shape03_game* Fn005c3e80();
};

// FUNCTION: 0x005c3e80
View_005c3e80_top_shape03_game* View_005c3e80_top_shape03_game::Fn005c3e80()
{
    mpObj = 0;
    Svc_top_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0x9b69c4e, 0x9b69c46, &mpObj);
    }
    return this;
}

struct View_005c3eb0_top_shape03_game {
    void* mpObj;
    View_005c3eb0_top_shape03_game* Fn005c3eb0();
};

// FUNCTION: 0x005c3eb0
View_005c3eb0_top_shape03_game* View_005c3eb0_top_shape03_game::Fn005c3eb0()
{
    mpObj = 0;
    Svc_top_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0xa3460deb, 0x66b217a1, &mpObj);
    }
    return this;
}

struct View_005d4920_top_shape03_game {
    void* mpObj;
    View_005d4920_top_shape03_game* Fn005d4920();
};

// FUNCTION: 0x005d4920
View_005d4920_top_shape03_game* View_005d4920_top_shape03_game::Fn005d4920()
{
    mpObj = 0;
    Svc_top_shape03_game* pSvc = Fn008793ec();
    if (pSvc) {
        pSvc->GetService(0x20673960, 0x673960, &mpObj);
    }
    return this;
}

struct Elem_005db220_top_shape03_game {
    // STUB: 0x005db110
    void Construct(const Elem_005db220_top_shape03_game* pSrc);
    uint8_t mData[20];
};

// FUNCTION: 0x005db220
Elem_005db220_top_shape03_game* Fn005db220(Elem_005db220_top_shape03_game* pFirst, Elem_005db220_top_shape03_game* pLast, Elem_005db220_top_shape03_game* pDest)
{
    Elem_005db220_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_005db250_top_shape03_game {
    // STUB: 0x005db110
    void Construct(const Elem_005db250_top_shape03_game* pSrc);
    uint8_t mData[20];
};

// FUNCTION: 0x005db250
Elem_005db250_top_shape03_game* Fn005db250(Elem_005db250_top_shape03_game* pDest, uint32_t nCount, const Elem_005db250_top_shape03_game* pSrc)
{
    Elem_005db250_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_005e60e0_top_shape03_game {
    // STUB: 0x005e5ea0
    void Construct(const Elem_005e60e0_top_shape03_game* pSrc);
    uint8_t mData[60];
};

// FUNCTION: 0x005e60e0
Elem_005e60e0_top_shape03_game* Fn005e60e0(Elem_005e60e0_top_shape03_game* pFirst, Elem_005e60e0_top_shape03_game* pLast, Elem_005e60e0_top_shape03_game* pDest)
{
    Elem_005e60e0_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct OB_NOVTABLE View_005fd370_top_shape03_game {
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
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x005fd370
uint32_t View_005fd370_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_0060c740_top_shape03_game {
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
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[26];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x0060c740
uint32_t View_0060c740_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct Elem_00611bd0_top_shape03_game {
    // STUB: 0x007ced60
    void Construct(const Elem_00611bd0_top_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x00611bd0
Elem_00611bd0_top_shape03_game* Fn00611bd0(Elem_00611bd0_top_shape03_game* pFirst, Elem_00611bd0_top_shape03_game* pLast, Elem_00611bd0_top_shape03_game* pDest)
{
    Elem_00611bd0_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_00611c30_top_shape03_game {
    // STUB: 0x007ced60
    void Construct(const Elem_00611c30_top_shape03_game* pSrc);
    uint8_t mData[12];
};

// FUNCTION: 0x00611c30
Elem_00611c30_top_shape03_game* Fn00611c30(Elem_00611c30_top_shape03_game* pDest, uint32_t nCount, const Elem_00611c30_top_shape03_game* pSrc)
{
    Elem_00611c30_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_0062f6b0_top_shape03_game {
    // STUB: 0x006267d0
    void Construct(const Elem_0062f6b0_top_shape03_game* pSrc);
    uint8_t mData[80];
};

// FUNCTION: 0x0062f6b0
Elem_0062f6b0_top_shape03_game* Fn0062f6b0(Elem_0062f6b0_top_shape03_game* pFirst, Elem_0062f6b0_top_shape03_game* pLast, Elem_0062f6b0_top_shape03_game* pDest)
{
    Elem_0062f6b0_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_0064d270_top_shape03_game {
    // STUB: 0x0064cfa0
    void Construct(const Elem_0064d270_top_shape03_game* pSrc);
    uint8_t mData[44];
};

// FUNCTION: 0x0064d270
Elem_0064d270_top_shape03_game* Fn0064d270(Elem_0064d270_top_shape03_game* pFirst, Elem_0064d270_top_shape03_game* pLast, Elem_0064d270_top_shape03_game* pDest)
{
    Elem_0064d270_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_0064d2a0_top_shape03_game {
    // STUB: 0x0064cfa0
    void Construct(const Elem_0064d2a0_top_shape03_game* pSrc);
    uint8_t mData[44];
};

// FUNCTION: 0x0064d2a0
Elem_0064d2a0_top_shape03_game* Fn0064d2a0(Elem_0064d2a0_top_shape03_game* pDest, uint32_t nCount, const Elem_0064d2a0_top_shape03_game* pSrc)
{
    Elem_0064d2a0_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_00686260_top_shape03_game {
    // STUB: 0x00686150
    void Construct(const Elem_00686260_top_shape03_game* pSrc);
    uint8_t mData[32];
};

// FUNCTION: 0x00686260
Elem_00686260_top_shape03_game* Fn00686260(Elem_00686260_top_shape03_game* pFirst, Elem_00686260_top_shape03_game* pLast, Elem_00686260_top_shape03_game* pDest)
{
    Elem_00686260_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct OB_NOVTABLE View_0069d7a0_top_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void S6() = 0;
    virtual void S7() = 0;
    virtual void S8() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[2];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x0069d7a0
uint32_t View_0069d7a0_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_006a9730_top_shape03_game {
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
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[2];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x006a9730
uint32_t View_006a9730_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_00762bd0_top_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[1];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x00762bd0
uint32_t View_00762bd0_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_00769400_top_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x00769400
uint32_t View_00769400_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_0076a370_top_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x0076a370
uint32_t View_0076a370_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_007cb920_top_shape03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void S5() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[1];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x007cb920
uint32_t View_007cb920_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_007d6650_top_shape03_game {
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
    virtual void Destroy(uint32_t nFlags) = 0;
    uint32_t mPad[2];
    uint32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x007d6650
uint32_t View_007d6650_top_shape03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct Elem_007de110_top_shape03_game {
    // STUB: 0x007de030
    void Construct(const Elem_007de110_top_shape03_game* pSrc);
    uint8_t mData[32];
};

// FUNCTION: 0x007de110
Elem_007de110_top_shape03_game* Fn007de110(Elem_007de110_top_shape03_game* pDest, uint32_t nCount, const Elem_007de110_top_shape03_game* pSrc)
{
    Elem_007de110_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_007de140_top_shape03_game {
    // STUB: 0x007de0a0
    void Construct(const Elem_007de140_top_shape03_game* pSrc);
    uint8_t mData[40];
};

// FUNCTION: 0x007de140
Elem_007de140_top_shape03_game* Fn007de140(Elem_007de140_top_shape03_game* pDest, uint32_t nCount, const Elem_007de140_top_shape03_game* pSrc)
{
    Elem_007de140_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

struct Elem_008b5f90_top_shape03_game {
    // STUB: 0x008b5f20
    void Construct(const Elem_008b5f90_top_shape03_game* pSrc);
    uint8_t mData[44];
};

// FUNCTION: 0x008b5f90
Elem_008b5f90_top_shape03_game* Fn008b5f90(Elem_008b5f90_top_shape03_game* pFirst, Elem_008b5f90_top_shape03_game* pLast, Elem_008b5f90_top_shape03_game* pDest)
{
    Elem_008b5f90_top_shape03_game* pOut = pDest;
    for (; pFirst != pLast; ++pFirst, ++pOut) {
        if (pOut) {
            pOut->Construct(pFirst);
        }
    }
    return pOut;
}

struct Elem_008b5fc0_top_shape03_game {
    // STUB: 0x008b5f20
    void Construct(const Elem_008b5fc0_top_shape03_game* pSrc);
    uint8_t mData[44];
};

// FUNCTION: 0x008b5fc0
Elem_008b5fc0_top_shape03_game* Fn008b5fc0(Elem_008b5fc0_top_shape03_game* pDest, uint32_t nCount, const Elem_008b5fc0_top_shape03_game* pSrc)
{
    Elem_008b5fc0_top_shape03_game* pOut = pDest;
    for (; nCount > 0; --nCount, ++pOut) {
        if (pOut) {
            pOut->Construct(pSrc);
        }
    }
    return pOut;
}

