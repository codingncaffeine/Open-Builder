// Shape families of packet shapec05_game, written by scratch/s17/gen/shapec05_game/gen*.py.
#include "common/types.h"

struct View_5f1a40_shapec05_game {
    uint8_t pad[0x14c];
    uint16_t mnWord;
    uint16_t Fn005f1a40();
};

// FUNCTION: 0x005f1a40
uint16_t View_5f1a40_shapec05_game::Fn005f1a40()
{
    return mnWord;
}

struct View_5fd610_shapec05_game {
    uint8_t pad[0x4];
    uint16_t mnWord;
    uint16_t Fn005fd610();
};

// FUNCTION: 0x005fd610
uint16_t View_5fd610_shapec05_game::Fn005fd610()
{
    return mnWord;
}

struct View_81e760_shapec05_game {
    uint8_t pad[0x2];
    uint16_t mnWord;
    uint16_t Fn0081e760();
};

// FUNCTION: 0x0081e760
uint16_t View_81e760_shapec05_game::Fn0081e760()
{
    return mnWord;
}

// GLOBAL: 0xb43c94
extern void* gpb43c94_c05;

// FUNCTION: 0x00601c00
bool Fn00601c00(void* p)
{
    gpb43c94_c05 = p;
    return true;
}

// GLOBAL: 0xb43cec
extern void* gpb43cec_c05;

// FUNCTION: 0x00601c10
bool Fn00601c10(void* p)
{
    gpb43cec_c05 = p;
    return true;
}

// GLOBAL: 0xb43dc4
extern void* gpb43dc4_c05;

// FUNCTION: 0x00602120
bool Fn00602120(void* p)
{
    gpb43dc4_c05 = p;
    return true;
}

struct View_604d50_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08(uint32_t flags) = 0;
    void Fn00604d50();
};

// FUNCTION: 0x00604d50
void View_604d50_shapec05_game::Fn00604d50()
{
    Slot08(0x400000);
}

struct View_604d80_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08(uint32_t flags) = 0;
    void Fn00604d80();
};

// FUNCTION: 0x00604d80
void View_604d80_shapec05_game::Fn00604d80()
{
    Slot08(0x10000000);
}

struct View_619540_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11(uint32_t flags) = 0;
    void Fn00619540();
};

// FUNCTION: 0x00619540
void View_619540_shapec05_game::Fn00619540()
{
    Slot11(0x8000);
}

// STUB: 0x653b80
void Fn653b80(void* p);

struct View_610540_shapec05_game {
    void Fn00610540(void* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00610540 score 2
void View_610540_shapec05_game::Fn00610540(void* p)
{
    Fn653b80(p);
}
#endif

// STUB: 0x988a80
void Fn988a80(void* p);

struct View_988cb0_shapec05_game {
    void Fn00988cb0(void* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00988cb0 score 2
void View_988cb0_shapec05_game::Fn00988cb0(void* p)
{
    Fn988a80(p);
}
#endif

// STUB: 0x985d40
void Fn985d40(void* p);

struct View_988c80_shapec05_game {
    void Fn00988c80(void* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00988c80 score 2
void View_988c80_shapec05_game::Fn00988c80(void* p)
{
    Fn985d40(p);
}
#endif

struct PoolNode_5a6200_c05 {
    PoolNode_5a6200_c05* mpNext;
};

// GLOBAL: 0xb0a5a0
extern PoolNode_5a6200_c05* gpFreeb0a5a0_c05;

struct View_5a6200_shapec05_game {
    void Fn005a6200(PoolNode_5a6200_c05* pNode);
};

// FUNCTION: 0x005a6200
void View_5a6200_shapec05_game::Fn005a6200(PoolNode_5a6200_c05* pNode)
{
    if (pNode) {
        pNode->mpNext = gpFreeb0a5a0_c05;
        gpFreeb0a5a0_c05 = pNode;
    }
}

struct PoolNode_5b2240_c05 {
    PoolNode_5b2240_c05* mpNext;
};

// GLOBAL: 0xb0a688
extern PoolNode_5b2240_c05* gpFreeb0a688_c05;

struct View_5b2240_shapec05_game {
    void Fn005b2240(PoolNode_5b2240_c05* pNode);
};

// FUNCTION: 0x005b2240
void View_5b2240_shapec05_game::Fn005b2240(PoolNode_5b2240_c05* pNode)
{
    if (pNode) {
        pNode->mpNext = gpFreeb0a688_c05;
        gpFreeb0a688_c05 = pNode;
    }
}

struct PoolNode_5b9d90_c05 {
    PoolNode_5b9d90_c05* mpNext;
};

// GLOBAL: 0xb0a6a0
extern PoolNode_5b9d90_c05* gpFreeb0a6a0_c05;

struct View_5b9d90_shapec05_game {
    void Fn005b9d90(PoolNode_5b9d90_c05* pNode);
};

// FUNCTION: 0x005b9d90
void View_5b9d90_shapec05_game::Fn005b9d90(PoolNode_5b9d90_c05* pNode)
{
    if (pNode) {
        pNode->mpNext = gpFreeb0a6a0_c05;
        gpFreeb0a6a0_c05 = pNode;
    }
}

struct Out_5d80a0_c05 {
    uint32_t mnW;
    uint32_t mnH;
};

struct View_5d80a0_shapec05_game {
    uint8_t pad[0x18];
    uint16_t mnW;
    uint16_t mnH;
    void Fn005d80a0(Out_5d80a0_c05* pOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d80a0 score 8
void View_5d80a0_shapec05_game::Fn005d80a0(Out_5d80a0_c05* pOut)
{
    pOut->mnW = mnW;
    pOut->mnH = mnH;
}
#endif

struct Out_5d80c0_c05 {
    uint32_t mnW;
    uint32_t mnH;
};

struct View_5d80c0_shapec05_game {
    uint8_t pad[0x1c];
    uint16_t mnW;
    uint16_t mnH;
    void Fn005d80c0(Out_5d80c0_c05* pOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d80c0 score 8
void View_5d80c0_shapec05_game::Fn005d80c0(Out_5d80c0_c05* pOut)
{
    pOut->mnW = mnW;
    pOut->mnH = mnH;
}
#endif

struct Out_5d8130_c05 {
    uint32_t mnW;
    uint32_t mnH;
};

struct View_5d8130_shapec05_game {
    uint8_t pad[0x4];
    uint16_t mnW;
    uint16_t mnH;
    void Fn005d8130(Out_5d8130_c05* pOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d8130 score 8
void View_5d8130_shapec05_game::Fn005d8130(Out_5d8130_c05* pOut)
{
    pOut->mnW = mnW;
    pOut->mnH = mnH;
}
#endif


#include "common/compiler.h"
#ifdef _MSC_VER
#define OB_C05_API extern "C" __declspec(dllimport)
#else
#define OB_C05_API extern "C"
#endif
OB_C05_API int32_t OB_STDCALL InternetSetOptionA(void* handle, uint32_t option, void* buffer, uint32_t length);

struct View_5c3e30_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    bool Fn005c3e30(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005c3e30
bool View_5c3e30_shapec05_game::Fn005c3e30(uint32_t iid, void** ppv)
{
    if (iid == 0x452294aa) {
        *ppv = this;
        Slot01();
        return true;
    }
    return false;
}

struct View_5d7b70_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    bool Fn005d7b70(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005d7b70
bool View_5d7b70_shapec05_game::Fn005d7b70(uint32_t iid, void** ppv)
{
    if (iid == 0xb54c519) {
        *ppv = this;
        Slot01();
        return true;
    }
    return false;
}

struct View_811cb0_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    bool Fn00811cb0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00811cb0
bool View_811cb0_shapec05_game::Fn00811cb0(uint32_t iid, void** ppv)
{
    if (iid == 0x1) {
        *ppv = this;
        Slot01();
        return true;
    }
    return false;
}

struct View_5c1e50_shapec05_game {
    uint32_t pad0;
    void* mpHandle;
    bool Fn005c1e50(uint32_t nValue);
};

// FUNCTION: 0x005c1e50
bool View_5c1e50_shapec05_game::Fn005c1e50(uint32_t nValue)
{
    if (mpHandle) {
        return InternetSetOptionA(mpHandle, 0x2, &nValue, 4) != 0;
    }
    return false;
}

struct View_5c1e80_shapec05_game {
    uint32_t pad0;
    void* mpHandle;
    bool Fn005c1e80(uint32_t nValue);
};

// FUNCTION: 0x005c1e80
bool View_5c1e80_shapec05_game::Fn005c1e80(uint32_t nValue)
{
    if (mpHandle) {
        return InternetSetOptionA(mpHandle, 0x5, &nValue, 4) != 0;
    }
    return false;
}

struct View_5c1eb0_shapec05_game {
    uint32_t pad0;
    void* mpHandle;
    bool Fn005c1eb0(uint32_t nValue);
};

// FUNCTION: 0x005c1eb0
bool View_5c1eb0_shapec05_game::Fn005c1eb0(uint32_t nValue)
{
    if (mpHandle) {
        return InternetSetOptionA(mpHandle, 0x6, &nValue, 4) != 0;
    }
    return false;
}

struct View_5d1c30_shapec05_game {
    uint8_t pad[0x8];
    void* mpFirst;
    void* mpSecond;
    uint32_t Fn005d1c30();
};

// FUNCTION: 0x005d1c30
uint32_t View_5d1c30_shapec05_game::Fn005d1c30()
{
    if (mpFirst && mpSecond) {
        return 1;
    }
    return 0;
}

struct View_5d9670_shapec05_game {
    uint8_t pad[0x4];
    void* mpFirst;
    void* mpSecond;
    uint32_t Fn005d9670();
};

// FUNCTION: 0x005d9670
uint32_t View_5d9670_shapec05_game::Fn005d9670()
{
    if (mpFirst && mpSecond) {
        return 1;
    }
    return 0;
}

struct View_8f4060_shapec05_game {
    uint8_t pad[0x10];
    void* mpFirst;
    void* mpSecond;
    uint32_t Fn008f4060();
};

// FUNCTION: 0x008f4060
uint32_t View_8f4060_shapec05_game::Fn008f4060()
{
    if (mpFirst && mpSecond) {
        return 1;
    }
    return 0;
}

struct Vec3_5d6400_c05 {
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
};

struct View_5d6400_shapec05_game {
    uint8_t pad[0x4c];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    bool Fn005d6400(const Vec3_5d6400_c05* pIn);
};

// FUNCTION: 0x005d6400
bool View_5d6400_shapec05_game::Fn005d6400(const Vec3_5d6400_c05* pIn)
{
    mnX = pIn->mnX;
    mnY = pIn->mnY;
    mnZ = pIn->mnZ;
    return true;
}

struct Vec3_5e2c90_c05 {
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
};

struct View_5e2c90_shapec05_game {
    uint8_t pad[0x60];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    bool Fn005e2c90(const Vec3_5e2c90_c05* pIn);
};

// FUNCTION: 0x005e2c90
bool View_5e2c90_shapec05_game::Fn005e2c90(const Vec3_5e2c90_c05* pIn)
{
    mnX = pIn->mnX;
    mnY = pIn->mnY;
    mnZ = pIn->mnZ;
    return true;
}

struct Vec3_80ca30_c05 {
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
};

struct View_80ca30_shapec05_game {
    uint8_t pad[0x2c];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    bool Fn0080ca30(const Vec3_80ca30_c05* pIn);
};

// FUNCTION: 0x0080ca30
bool View_80ca30_shapec05_game::Fn0080ca30(const Vec3_80ca30_c05* pIn)
{
    mnX = pIn->mnX;
    mnY = pIn->mnY;
    mnZ = pIn->mnZ;
    return true;
}

struct Quad_5e2910_c05 {
    uint32_t mn0;
    uint32_t mn1;
    uint32_t mn2;
    uint32_t mn3;
};

struct View_5e2910_shapec05_game {
    uint8_t pad0[0x44];
    uint32_t mn0;
    uint32_t mn1;
    uint32_t mn2;
    uint32_t mn3;
    void Fn005e2910(Quad_5e2910_c05* pOut);
};

// FUNCTION: 0x005e2910
void View_5e2910_shapec05_game::Fn005e2910(Quad_5e2910_c05* pOut)
{
    pOut->mn0 = mn0;
    pOut->mn1 = mn1;
    pOut->mn2 = mn2;
    pOut->mn3 = mn3;
}

struct Quad_659dd0_c05 {
    uint32_t mn0;
    uint32_t mn1;
    uint32_t mn2;
    uint32_t mn3;
};

struct View_659dd0_shapec05_game {
    uint8_t pad0[0x24c];
    uint32_t mn0;
    uint32_t mn1;
    uint32_t mn2;
    uint32_t mn3;
    void Fn00659dd0(Quad_659dd0_c05* pOut);
};

// FUNCTION: 0x00659dd0
void View_659dd0_shapec05_game::Fn00659dd0(Quad_659dd0_c05* pOut)
{
    pOut->mn0 = mn0;
    pOut->mn1 = mn1;
    pOut->mn2 = mn2;
    pOut->mn3 = mn3;
}

struct Quad_65a6c0_c05 {
    uint32_t mn0;
    uint32_t mn1;
    uint32_t mn2;
    uint32_t mn3;
};

struct View_65a6c0_shapec05_game {
    uint8_t pad0[0xa0];
    uint32_t mn0;
    uint8_t pad1[0x14];
    uint32_t mn1;
    uint8_t pad2[0x14];
    uint32_t mn2;
    uint8_t pad3[0x14];
    uint32_t mn3;
    void Fn0065a6c0(Quad_65a6c0_c05* pOut);
};

// FUNCTION: 0x0065a6c0
void View_65a6c0_shapec05_game::Fn0065a6c0(Quad_65a6c0_c05* pOut)
{
    pOut->mn0 = mn0;
    pOut->mn1 = mn1;
    pOut->mn2 = mn2;
    pOut->mn3 = mn3;
}

struct Rec_619d90_c05 {
    uint32_t d[19];
};

#ifdef OB_DRAFTS
// CLOSE: 0x00619d90 score 16
void Fn00619d90(Rec_619d90_c05* pFirst, Rec_619d90_c05* pLast, Rec_619d90_c05* pDest)
{
    for (; pFirst != pLast; ++pFirst, ++pDest) {
        if (pDest) {
            *pDest = *pFirst;
        }
    }
}
#endif

struct Rec_8846f0_c05 {
    uint32_t d[26];
};

#ifdef OB_DRAFTS
// CLOSE: 0x008846f0 score 16
void Fn008846f0(Rec_8846f0_c05* pFirst, Rec_8846f0_c05* pLast, Rec_8846f0_c05* pDest)
{
    for (; pFirst != pLast; ++pFirst, ++pDest) {
        if (pDest) {
            *pDest = *pFirst;
        }
    }
}
#endif

struct Rec_8de6d0_c05 {
    uint32_t d[51];
};

#ifdef OB_DRAFTS
// CLOSE: 0x008de6d0 score 16
void Fn008de6d0(Rec_8de6d0_c05* pFirst, Rec_8de6d0_c05* pLast, Rec_8de6d0_c05* pDest)
{
    for (; pFirst != pLast; ++pFirst, ++pDest) {
        if (pDest) {
            *pDest = *pFirst;
        }
    }
}
#endif

struct Rec_619dc0_c05 {
    uint32_t d[19];
};

// FUNCTION: 0x00619dc0
void Fn00619dc0(Rec_619dc0_c05* pFirst, Rec_619dc0_c05* pLast, const Rec_619dc0_c05* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        *pFirst = *pValue;
    }
}

struct Rec_882930_c05 {
    uint32_t d[26];
};

// FUNCTION: 0x00882930
void Fn00882930(Rec_882930_c05* pFirst, Rec_882930_c05* pLast, const Rec_882930_c05* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        *pFirst = *pValue;
    }
}

struct Rec_8de560_c05 {
    uint32_t d[51];
};

// FUNCTION: 0x008de560
void Fn008de560(Rec_8de560_c05* pFirst, Rec_8de560_c05* pLast, const Rec_8de560_c05* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        *pFirst = *pValue;
    }
}

struct Rec_61bb30_c05 {
    uint32_t d[19];
};

#ifdef OB_DRAFTS
// CLOSE: 0x0061bb30 score 8
void Fn0061bb30(Rec_61bb30_c05* pDest, uint32_t nCount, const Rec_61bb30_c05* pValue)
{
    for (; nCount > 0; --nCount, ++pDest) {
        if (pDest) {
            *pDest = *pValue;
        }
    }
}
#endif

struct Rec_884720_c05 {
    uint32_t d[26];
};

#ifdef OB_DRAFTS
// CLOSE: 0x00884720 score 8
void Fn00884720(Rec_884720_c05* pDest, uint32_t nCount, const Rec_884720_c05* pValue)
{
    for (; nCount > 0; --nCount, ++pDest) {
        if (pDest) {
            *pDest = *pValue;
        }
    }
}
#endif

struct Rec_8de710_c05 {
    uint32_t d[51];
};

#ifdef OB_DRAFTS
// CLOSE: 0x008de710 score 8
void Fn008de710(Rec_8de710_c05* pDest, uint32_t nCount, const Rec_8de710_c05* pValue)
{
    for (; nCount > 0; --nCount, ++pDest) {
        if (pDest) {
            *pDest = *pValue;
        }
    }
}
#endif

struct View_60a7d0_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    bool Fn0060a7d0(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0060a7d0 score 12
bool View_60a7d0_shapec05_game::Fn0060a7d0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x8a175d6b:
        *ppv = this;
        Slot01();
        return true;
    case 1:
        *ppv = this;
        Slot01();
        return true;
    }
    return false;
}
#endif

struct View_829920_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    bool Fn00829920(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00829920 score 12
bool View_829920_shapec05_game::Fn00829920(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0xa8bc2a75:
        *ppv = this;
        Slot01();
        return true;
    case 1:
        *ppv = this;
        Slot01();
        return true;
    }
    return false;
}
#endif

struct View_8f37a0_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    bool Fn008f37a0(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008f37a0 score 12
bool View_8f37a0_shapec05_game::Fn008f37a0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0xea9dab44:
        *ppv = this;
        Slot01();
        return true;
    case 1:
        *ppv = this;
        Slot01();
        return true;
    }
    return false;
}
#endif

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

struct Rec_5e6110_c05 {
    uint8_t d[0x3c];
    // STUB: 0x5e5f90
    void Assign(const Rec_5e6110_c05* pSrc);
};

// FUNCTION: 0x005e6110
Rec_5e6110_c05* Fn005e6110(Rec_5e6110_c05* pFirst, Rec_5e6110_c05* pLast, Rec_5e6110_c05* pDest)
{
    int32_t nCount = static_cast<int32_t>(pLast - pFirst);
    for (; nCount > 0; --nCount) {
        pDest->Assign(pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Rec_6412b0_c05 {
    uint8_t d[0x178];
    // STUB: 0x63fcd0
    void Assign(const Rec_6412b0_c05* pSrc);
};

// FUNCTION: 0x006412b0
Rec_6412b0_c05* Fn006412b0(Rec_6412b0_c05* pFirst, Rec_6412b0_c05* pLast, Rec_6412b0_c05* pDest)
{
    int32_t nCount = static_cast<int32_t>(pLast - pFirst);
    for (; nCount > 0; --nCount) {
        pDest->Assign(pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Rec_7d0a00_c05 {
    uint8_t d[0x7c];
    // STUB: 0x7d0950
    void Assign(const Rec_7d0a00_c05* pSrc);
};

// FUNCTION: 0x007d0a00
Rec_7d0a00_c05* Fn007d0a00(Rec_7d0a00_c05* pFirst, Rec_7d0a00_c05* pLast, Rec_7d0a00_c05* pDest)
{
    int32_t nCount = static_cast<int32_t>(pLast - pFirst);
    for (; nCount > 0; --nCount) {
        pDest->Assign(pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct QIBase_5deb00_c05 {
    // STUB: 0x801940
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_5deb00_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    uint8_t pad[0x30];
    QIBase_5deb00_c05 mBase;
    bool Fn005deb00(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005deb00
bool View_5deb00_shapec05_game::Fn005deb00(uint32_t iid, void** ppv)
{
    if (iid == 0xa9e2831d) {
        Slot01();
        *ppv = this;
        return true;
    }
    return mBase.QueryInterface(iid, ppv);
}

struct QIBase_5e1200_c05 {
    // STUB: 0x801940
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_5e1200_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    uint8_t pad[0x30];
    QIBase_5e1200_c05 mBase;
    bool Fn005e1200(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005e1200
bool View_5e1200_shapec05_game::Fn005e1200(uint32_t iid, void** ppv)
{
    if (iid == 0xa9e2831e) {
        Slot01();
        *ppv = this;
        return true;
    }
    return mBase.QueryInterface(iid, ppv);
}

struct QIBase_6759b0_c05 {
    // STUB: 0x6855e0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_6759b0_shapec05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;

    QIBase_6759b0_c05 mBase;
    bool Fn006759b0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006759b0
bool View_6759b0_shapec05_game::Fn006759b0(uint32_t iid, void** ppv)
{
    if (iid == 0x6c5ff7b) {
        Slot01();
        *ppv = this;
        return true;
    }
    return mBase.QueryInterface(iid, ppv);
}

struct Rec_587ee0_c05 {
    uint8_t pad_mpSecond[0x8];
    void* mpSecond;
    uint8_t pad_mpFirst[0x8];
    void* mpFirst;
    uint8_t padEnd[0x10];
};

// FUNCTION: 0x00587ee0
void Fn00587ee0(Rec_587ee0_c05* pFirst, Rec_587ee0_c05* pLast)
{
    for (; pFirst != pLast; ++pFirst) {
        if (pFirst->mpFirst) {
            Fn0090cf63(pFirst->mpFirst);
        }
        if (pFirst->mpSecond) {
            Fn0090cf63(pFirst->mpSecond);
        }
    }
}

struct Rec_7de170_c05 {
    uint8_t pad_mpSecond[0x4];
    void* mpSecond;
    uint8_t pad_mpFirst[0x8];
    void* mpFirst;
    uint8_t padEnd[0xc];
};

// FUNCTION: 0x007de170
void Fn007de170(Rec_7de170_c05* pFirst, Rec_7de170_c05* pLast)
{
    for (; pFirst != pLast; ++pFirst) {
        if (pFirst->mpFirst) {
            Fn0090cf63(pFirst->mpFirst);
        }
        if (pFirst->mpSecond) {
            Fn0090cf63(pFirst->mpSecond);
        }
    }
}

struct Rec_7de1b0_c05 {
    uint8_t pad_mpSecond[0x4];
    void* mpSecond;
    uint8_t pad_mpFirst[0x8];
    void* mpFirst;
    uint8_t padEnd[0x14];
};

// FUNCTION: 0x007de1b0
void Fn007de1b0(Rec_7de1b0_c05* pFirst, Rec_7de1b0_c05* pLast)
{
    for (; pFirst != pLast; ++pFirst) {
        if (pFirst->mpFirst) {
            Fn0090cf63(pFirst->mpFirst);
        }
        if (pFirst->mpSecond) {
            Fn0090cf63(pFirst->mpSecond);
        }
    }
}

#include <new>

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

struct Elem_58a630_c05 {
    void* mpData;
    uint8_t pad[0x68];
};

struct View_58a630_shapec05_game {
    Elem_58a630_c05* mpFirst;
    Elem_58a630_c05* mpLast;
    void Fn0058a630();
};

// FUNCTION: 0x0058a630
void View_58a630_shapec05_game::Fn0058a630()
{
    Elem_58a630_c05* pElem = mpFirst;
    Elem_58a630_c05* pEnd = mpLast;
    for (; pElem != pEnd; ++pElem) {
        if (pElem->mpData) {
            Fn0090cf63(pElem->mpData);
        }
    }
    if (mpFirst) {
        Fn0090cf63(mpFirst);
    }
}

struct Elem_5db590_c05 {
    void* mpData;
    uint8_t pad[0x10];
};

struct View_5db590_shapec05_game {
    Elem_5db590_c05* mpFirst;
    Elem_5db590_c05* mpLast;
    void Fn005db590();
};

// FUNCTION: 0x005db590
void View_5db590_shapec05_game::Fn005db590()
{
    Elem_5db590_c05* pElem = mpFirst;
    Elem_5db590_c05* pEnd = mpLast;
    for (; pElem != pEnd; ++pElem) {
        if (pElem->mpData) {
            Fn0090cf63(pElem->mpData);
        }
    }
    if (mpFirst) {
        Fn0090cf63(mpFirst);
    }
}

struct Elem_6b7180_c05 {
    void* mpData;
    uint8_t pad[0xc];
};

struct View_6b7180_shapec05_game {
    Elem_6b7180_c05* mpFirst;
    Elem_6b7180_c05* mpLast;
    void Fn006b7180();
};

// FUNCTION: 0x006b7180
void View_6b7180_shapec05_game::Fn006b7180()
{
    Elem_6b7180_c05* pElem = mpFirst;
    Elem_6b7180_c05* pEnd = mpLast;
    for (; pElem != pEnd; ++pElem) {
        if (pElem->mpData) {
            Fn0090cf63(pElem->mpData);
        }
    }
    if (mpFirst) {
        Fn0090cf63(mpFirst);
    }
}

struct Node_59bd10_c05 {
    uint8_t pad0[0x8];
    Node_59bd10_c05* mpLeft;
    Node_59bd10_c05* mpRight;
    void* mpB;
    uint8_t pad14[0xc];
    void* mpA;
};

struct View_59bd10_shapec05_game {
    void Fn0059bd10(Node_59bd10_c05* pNode);
};

// FUNCTION: 0x0059bd10
void View_59bd10_shapec05_game::Fn0059bd10(Node_59bd10_c05* pNode)
{
    while (pNode) {
        Fn0059bd10(pNode->mpRight);
        Node_59bd10_c05* pNext = pNode->mpLeft;
        if (pNode->mpA) {
            Fn0090cf63(pNode->mpA);
        }
        if (pNode->mpB) {
            Fn0090cf63(pNode->mpB);
        }
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct Node_622190_c05 {
    uint8_t pad0[0x8];
    Node_622190_c05* mpLeft;
    Node_622190_c05* mpRight;
    uint8_t pad10[0x8];
    void* mpB;
    uint8_t pad1c[0x8];
    void* mpA;
};

struct View_622190_shapec05_game {
    void Fn00622190(Node_622190_c05* pNode);
};

// FUNCTION: 0x00622190
void View_622190_shapec05_game::Fn00622190(Node_622190_c05* pNode)
{
    while (pNode) {
        Fn00622190(pNode->mpRight);
        Node_622190_c05* pNext = pNode->mpLeft;
        if (pNode->mpA) {
            Fn0090cf63(pNode->mpA);
        }
        if (pNode->mpB) {
            Fn0090cf63(pNode->mpB);
        }
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct Node_63d700_c05 {
    uint8_t pad0[0x8];
    Node_63d700_c05* mpLeft;
    Node_63d700_c05* mpRight;
    uint8_t pad10[0x4];
    void* mpB;
    uint8_t pad18[0x8];
    void* mpA;
};

struct View_63d700_shapec05_game {
    void Fn0063d700(Node_63d700_c05* pNode);
};

// FUNCTION: 0x0063d700
void View_63d700_shapec05_game::Fn0063d700(Node_63d700_c05* pNode)
{
    while (pNode) {
        Fn0063d700(pNode->mpRight);
        Node_63d700_c05* pNext = pNode->mpLeft;
        if (pNode->mpA) {
            Fn0090cf63(pNode->mpA);
        }
        if (pNode->mpB) {
            Fn0090cf63(pNode->mpB);
        }
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct SubA_5c8960_c05 {
    uint8_t d[0xc];
    // STUB: 0x5c8510
    void Copy(const SubA_5c8960_c05* pSrc);
};

struct SubB_5c8960_c05 {
    uint8_t d[0xc];
    // STUB: 0x5c8510
    void Copy(const SubB_5c8960_c05* pSrc);
};

struct Value_5c8960_c05 {
    uint32_t mnKey;

    SubA_5c8960_c05 mA;
    SubB_5c8960_c05 mB;
    explicit Value_5c8960_c05(const Value_5c8960_c05* pSrc)
    {
        mnKey = pSrc->mnKey;
        mA.Copy(&pSrc->mA);
        mB.Copy(&pSrc->mB);
    }
};

struct Node_5c8960_c05 {
    uint8_t pad[0x10];
    Value_5c8960_c05 mValue;
};

struct View_5c8960_shapec05_game {
    Node_5c8960_c05* Fn005c8960(const Value_5c8960_c05* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005c8960 score 27
Node_5c8960_c05* View_5c8960_shapec05_game::Fn005c8960(const Value_5c8960_c05* pSrc)
{
    Node_5c8960_c05* pNode = static_cast<Node_5c8960_c05*>(Fn0090cf54(0x2c));
    new (&pNode->mValue) Value_5c8960_c05(pSrc);
    return pNode;
}
#endif

struct SubA_63d8b0_c05 {
    uint8_t d[0xc];
    // STUB: 0x63c150
    void Copy(const SubA_63d8b0_c05* pSrc);
};

struct SubB_63d8b0_c05 {
    uint8_t d[0xc];
    // STUB: 0x464760
    void Copy(const SubB_63d8b0_c05* pSrc);
};

struct Value_63d8b0_c05 {
    uint32_t mnKey;

    SubA_63d8b0_c05 mA;
    SubB_63d8b0_c05 mB;
    explicit Value_63d8b0_c05(const Value_63d8b0_c05* pSrc)
    {
        mnKey = pSrc->mnKey;
        mA.Copy(&pSrc->mA);
        mB.Copy(&pSrc->mB);
    }
};

struct Node_63d8b0_c05 {
    uint8_t pad[0x10];
    Value_63d8b0_c05 mValue;
};

struct View_63d8b0_shapec05_game {
    Node_63d8b0_c05* Fn0063d8b0(const Value_63d8b0_c05* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0063d8b0 score 27
Node_63d8b0_c05* View_63d8b0_shapec05_game::Fn0063d8b0(const Value_63d8b0_c05* pSrc)
{
    Node_63d8b0_c05* pNode = static_cast<Node_63d8b0_c05*>(Fn0090cf54(0x2c));
    new (&pNode->mValue) Value_63d8b0_c05(pSrc);
    return pNode;
}
#endif

struct SubA_693e80_c05 {
    uint8_t d[0x28];
    // STUB: 0x692e20
    void Copy(const SubA_693e80_c05* pSrc);
};

struct SubB_693e80_c05 {
    uint8_t d[0x10];
    // STUB: 0x691450
    void Copy(const SubB_693e80_c05* pSrc);
};

struct Value_693e80_c05 {
    uint32_t mnKey;
    uint8_t pad[0x4];
    SubA_693e80_c05 mA;
    SubB_693e80_c05 mB;
    explicit Value_693e80_c05(const Value_693e80_c05* pSrc)
    {
        mnKey = pSrc->mnKey;
        mA.Copy(&pSrc->mA);
        mB.Copy(&pSrc->mB);
    }
};

struct Node_693e80_c05 {
    uint8_t pad[0x10];
    Value_693e80_c05 mValue;
};

struct View_693e80_shapec05_game {
    Node_693e80_c05* Fn00693e80(const Value_693e80_c05* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00693e80 score 27
Node_693e80_c05* View_693e80_shapec05_game::Fn00693e80(const Value_693e80_c05* pSrc)
{
    Node_693e80_c05* pNode = static_cast<Node_693e80_c05*>(Fn0090cf54(0x50));
    new (&pNode->mValue) Value_693e80_c05(pSrc);
    return pNode;
}
#endif

struct Rec_61b0b0_c05 {
    uint8_t mnCount;
    uint8_t mnFlag;
    uint16_t pad;
    uint32_t d[13];
};

struct View_61b0b0_shapec05_game {
    void CopyOut(Rec_61b0b0_c05* pDst);
};

// FUNCTION: 0x0061b0b0
void View_61b0b0_shapec05_game::CopyOut(Rec_61b0b0_c05* pDst)
{
    Rec_61b0b0_c05* pSrc = reinterpret_cast<Rec_61b0b0_c05*>(reinterpret_cast<char*>(this) - 0x118);
    pDst->mnCount++;
    pDst->d[0] = pSrc->d[0];
    pDst->d[1] = pSrc->d[1];
    pDst->d[2] = pSrc->d[2];
    pDst->d[3] = pSrc->d[3];
    pDst->d[4] = pSrc->d[4];
    pDst->d[5] = pSrc->d[5];
    pDst->d[6] = pSrc->d[6];
    pDst->d[7] = pSrc->d[7];
    pDst->d[8] = pSrc->d[8];
    pDst->d[9] = pSrc->d[9];
    pDst->d[10] = pSrc->d[10];
    pDst->d[11] = pSrc->d[11];
    pDst->d[12] = pSrc->d[12];
    pDst->mnFlag = pSrc->mnFlag;
}

struct Rec_654500_c05 {
    uint8_t mnCount;
    uint8_t mnFlag;
    uint16_t pad;
    uint32_t d[13];
};

struct View_654500_shapec05_game {
    void CopyOut(Rec_654500_c05* pDst);
};

// FUNCTION: 0x00654500
void View_654500_shapec05_game::CopyOut(Rec_654500_c05* pDst)
{
    Rec_654500_c05* pSrc = reinterpret_cast<Rec_654500_c05*>(reinterpret_cast<char*>(this) - 0xb4);
    pDst->mnCount++;
    pDst->d[0] = pSrc->d[0];
    pDst->d[1] = pSrc->d[1];
    pDst->d[2] = pSrc->d[2];
    pDst->d[3] = pSrc->d[3];
    pDst->d[4] = pSrc->d[4];
    pDst->d[5] = pSrc->d[5];
    pDst->d[6] = pSrc->d[6];
    pDst->d[7] = pSrc->d[7];
    pDst->d[8] = pSrc->d[8];
    pDst->d[9] = pSrc->d[9];
    pDst->d[10] = pSrc->d[10];
    pDst->d[11] = pSrc->d[11];
    pDst->d[12] = pSrc->d[12];
    pDst->mnFlag = pSrc->mnFlag;
}

struct Rec_801b80_c05 {
    uint8_t mnCount;
    uint8_t mnFlag;
    uint16_t pad;
    uint32_t d[13];
};

struct View_801b80_shapec05_game {
    void CopyOut(Rec_801b80_c05* pDst);
};

// FUNCTION: 0x00801b80
void View_801b80_shapec05_game::CopyOut(Rec_801b80_c05* pDst)
{
    Rec_801b80_c05* pSrc = reinterpret_cast<Rec_801b80_c05*>(reinterpret_cast<char*>(this) - 0x74);
    pDst->mnCount++;
    pDst->d[0] = pSrc->d[0];
    pDst->d[1] = pSrc->d[1];
    pDst->d[2] = pSrc->d[2];
    pDst->d[3] = pSrc->d[3];
    pDst->d[4] = pSrc->d[4];
    pDst->d[5] = pSrc->d[5];
    pDst->d[6] = pSrc->d[6];
    pDst->d[7] = pSrc->d[7];
    pDst->d[8] = pSrc->d[8];
    pDst->d[9] = pSrc->d[9];
    pDst->d[10] = pSrc->d[10];
    pDst->d[11] = pSrc->d[11];
    pDst->d[12] = pSrc->d[12];
    pDst->mnFlag = pSrc->mnFlag;
}

struct Rec_61b140_c05 {
    uint8_t mnCount;
    uint8_t mnFlag;
    uint16_t pad;
    uint32_t d[13];
};

struct View_61b140_shapec05_game {
    void CopyIn(const Rec_61b140_c05* pSrc);
};

// FUNCTION: 0x0061b140
void View_61b140_shapec05_game::CopyIn(const Rec_61b140_c05* pSrc)
{
    Rec_61b140_c05* pDst = reinterpret_cast<Rec_61b140_c05*>(reinterpret_cast<char*>(this) - 0x118);
    pDst->mnCount++;
    pDst->d[0] = pSrc->d[0];
    pDst->d[1] = pSrc->d[1];
    pDst->d[2] = pSrc->d[2];
    pDst->d[3] = pSrc->d[3];
    pDst->d[4] = pSrc->d[4];
    pDst->d[5] = pSrc->d[5];
    pDst->d[6] = pSrc->d[6];
    pDst->d[7] = pSrc->d[7];
    pDst->d[8] = pSrc->d[8];
    pDst->d[9] = pSrc->d[9];
    pDst->d[10] = pSrc->d[10];
    pDst->d[11] = pSrc->d[11];
    pDst->d[12] = pSrc->d[12];
    pDst->mnFlag = pSrc->mnFlag;
}

struct Rec_654590_c05 {
    uint8_t mnCount;
    uint8_t mnFlag;
    uint16_t pad;
    uint32_t d[13];
};

struct View_654590_shapec05_game {
    void CopyIn(const Rec_654590_c05* pSrc);
};

// FUNCTION: 0x00654590
void View_654590_shapec05_game::CopyIn(const Rec_654590_c05* pSrc)
{
    Rec_654590_c05* pDst = reinterpret_cast<Rec_654590_c05*>(reinterpret_cast<char*>(this) - 0xb4);
    pDst->mnCount++;
    pDst->d[0] = pSrc->d[0];
    pDst->d[1] = pSrc->d[1];
    pDst->d[2] = pSrc->d[2];
    pDst->d[3] = pSrc->d[3];
    pDst->d[4] = pSrc->d[4];
    pDst->d[5] = pSrc->d[5];
    pDst->d[6] = pSrc->d[6];
    pDst->d[7] = pSrc->d[7];
    pDst->d[8] = pSrc->d[8];
    pDst->d[9] = pSrc->d[9];
    pDst->d[10] = pSrc->d[10];
    pDst->d[11] = pSrc->d[11];
    pDst->d[12] = pSrc->d[12];
    pDst->mnFlag = pSrc->mnFlag;
}

struct Rec_801be0_c05 {
    uint8_t mnCount;
    uint8_t mnFlag;
    uint16_t pad;
    uint32_t d[13];
};

struct View_801be0_shapec05_game {
    void CopyIn(const Rec_801be0_c05* pSrc);
};

// FUNCTION: 0x00801be0
void View_801be0_shapec05_game::CopyIn(const Rec_801be0_c05* pSrc)
{
    Rec_801be0_c05* pDst = reinterpret_cast<Rec_801be0_c05*>(reinterpret_cast<char*>(this) - 0x74);
    pDst->mnCount++;
    pDst->d[0] = pSrc->d[0];
    pDst->d[1] = pSrc->d[1];
    pDst->d[2] = pSrc->d[2];
    pDst->d[3] = pSrc->d[3];
    pDst->d[4] = pSrc->d[4];
    pDst->d[5] = pSrc->d[5];
    pDst->d[6] = pSrc->d[6];
    pDst->d[7] = pSrc->d[7];
    pDst->d[8] = pSrc->d[8];
    pDst->d[9] = pSrc->d[9];
    pDst->d[10] = pSrc->d[10];
    pDst->d[11] = pSrc->d[11];
    pDst->d[12] = pSrc->d[12];
    pDst->mnFlag = pSrc->mnFlag;
}

struct View_6483c0_shapec05_game {
    uint32_t mnV0;
    uint32_t mnV4;
    uint32_t mnV8;
    uint8_t padc[0x10];
    uint32_t mnV1c;
    uint8_t pad20[0x14];
    uint32_t mnV34;
    uint32_t mnV38;
    const int32_t* mpVbTable;
    uint8_t pad40[0x20c];
    uint32_t mnV24c;
    // STUB: 0x654f00
    void Fn654f00(uint32_t arg);
    View_6483c0_shapec05_game* Fn006483c0(uint32_t bMostDerived);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006483c0 score 5
View_6483c0_shapec05_game* View_6483c0_shapec05_game::Fn006483c0(uint32_t bMostDerived)
{
    if (bMostDerived) {
        mpVbTable = reinterpret_cast<const int32_t*>(0xaa962c);
        mnV24c = 0xaa1f38;
        Fn654f00(0);
    }
    const int32_t* pTable = mpVbTable;
    mnV0 = 0xaa9578;
    mnV4 = 0xaa955c;
    mnV8 = 0xaa94f8;
    mnV1c = 0xaa94e0;
    mnV34 = 0xaa94d0;
    mnV38 = 0xaa94cc;
    char* pBase = reinterpret_cast<char*>(this);
    *reinterpret_cast<uint32_t*>(pBase + pTable[1] + 0x3c) = 0xaa9480;
    int32_t nOffset = mpVbTable[1];
    *reinterpret_cast<int32_t*>(pBase + nOffset + 0x38) = nOffset - 0x210;
    return this;
}
#endif

struct View_652c30_shapec05_game {
    uint32_t mnV0;
    uint32_t mnV4;
    uint32_t mnV8;
    uint8_t padc[0x10];
    uint32_t mnV1c;
    uint8_t pad20[0x14];
    uint32_t mnV34;
    uint32_t mnV38;
    const int32_t* mpVbTable;
    uint8_t pad40[0x20c];
    uint32_t mnV24c;
    // STUB: 0x654f00
    void Fn654f00(uint32_t arg);
    View_652c30_shapec05_game* Fn00652c30(uint32_t bMostDerived);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00652c30 score 5
View_652c30_shapec05_game* View_652c30_shapec05_game::Fn00652c30(uint32_t bMostDerived)
{
    if (bMostDerived) {
        mpVbTable = reinterpret_cast<const int32_t*>(0xaaa23c);
        mnV24c = 0xaa1f38;
        Fn654f00(0);
    }
    const int32_t* pTable = mpVbTable;
    mnV0 = 0xaaa188;
    mnV4 = 0xaaa16c;
    mnV8 = 0xaaa108;
    mnV1c = 0xaaa0f0;
    mnV34 = 0xaaa0e0;
    mnV38 = 0xaaa0dc;
    char* pBase = reinterpret_cast<char*>(this);
    *reinterpret_cast<uint32_t*>(pBase + pTable[1] + 0x3c) = 0xaaa090;
    int32_t nOffset = mpVbTable[1];
    *reinterpret_cast<int32_t*>(pBase + nOffset + 0x38) = nOffset - 0x210;
    return this;
}
#endif

struct View_6530b0_shapec05_game {
    uint32_t mnV0;
    uint32_t mnV4;
    uint32_t mnV8;
    uint32_t mnVc;
    uint8_t pad10[0x10];
    uint32_t mnV20;
    uint8_t pad24[0x14];
    uint32_t mnV38;
    const int32_t* mpVbTable;
    uint8_t pad40[0x294];
    uint32_t mnV2d4;
    // STUB: 0x65c330
    void Fn65c330(uint32_t arg);
    View_6530b0_shapec05_game* Fn006530b0(uint32_t bMostDerived);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006530b0 score 5
View_6530b0_shapec05_game* View_6530b0_shapec05_game::Fn006530b0(uint32_t bMostDerived)
{
    if (bMostDerived) {
        mpVbTable = reinterpret_cast<const int32_t*>(0xaaa588);
        mnV2d4 = 0xaa1f38;
        Fn65c330(0);
    }
    const int32_t* pTable = mpVbTable;
    mnV0 = 0xaaa3c8;
    mnV4 = 0xaaa340;
    mnV8 = 0xaaa324;
    mnVc = 0xaaa2c0;
    mnV20 = 0xaaa2a8;
    mnV38 = 0xaaa2a4;
    char* pBase = reinterpret_cast<char*>(this);
    *reinterpret_cast<uint32_t*>(pBase + pTable[1] + 0x3c) = 0xaaa258;
    int32_t nOffset = mpVbTable[1];
    *reinterpret_cast<int32_t*>(pBase + nOffset + 0x38) = nOffset - 0x298;
    return this;
}
#endif

struct Elem_58aff0_c05 {
    uint8_t pad0[0x4];
    void* mpData;
    uint8_t pad1[0x8];
};

// STUB: 0x58a540
Elem_58aff0_c05* Fn58a540(Elem_58aff0_c05* pFirst, Elem_58aff0_c05* pLast, Elem_58aff0_c05* pDest, Elem_58aff0_c05** ppOut, uint32_t nFlag);

struct View_58aff0_shapec05_game {
    uint32_t mnPad;
    Elem_58aff0_c05* mpEnd;
    Elem_58aff0_c05* Fn0058aff0(Elem_58aff0_c05* pFirst, Elem_58aff0_c05* pLast);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058aff0 score 37
Elem_58aff0_c05* View_58aff0_shapec05_game::Fn0058aff0(Elem_58aff0_c05* pFirst, Elem_58aff0_c05* pLast)
{
    Elem_58aff0_c05* pDest = pFirst;
    Elem_58aff0_c05* pNew = Fn58a540(pLast, mpEnd, pDest, &pFirst, 0);
    Elem_58aff0_c05* pEnd = mpEnd;
    for (Elem_58aff0_c05* pElem = pNew; pElem != pEnd; ++pElem) {
        if (pElem->mpData) {
            Fn0090cf63(pElem->mpData);
        }
    }
    mpEnd = pNew;
    return pFirst;
}
#endif

struct Elem_5abc80_c05 {
    uint8_t pad0[0x4];
    void* mpData;
    uint8_t pad1[0x10];
};

// STUB: 0x58a5b0
Elem_5abc80_c05* Fn58a5b0(Elem_5abc80_c05* pFirst, Elem_5abc80_c05* pLast, Elem_5abc80_c05* pDest, Elem_5abc80_c05** ppOut, uint32_t nFlag);

struct View_5abc80_shapec05_game {
    uint32_t mnPad;
    Elem_5abc80_c05* mpEnd;
    Elem_5abc80_c05* Fn005abc80(Elem_5abc80_c05* pFirst, Elem_5abc80_c05* pLast);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005abc80 score 37
Elem_5abc80_c05* View_5abc80_shapec05_game::Fn005abc80(Elem_5abc80_c05* pFirst, Elem_5abc80_c05* pLast)
{
    Elem_5abc80_c05* pDest = pFirst;
    Elem_5abc80_c05* pNew = Fn58a5b0(pLast, mpEnd, pDest, &pFirst, 0);
    Elem_5abc80_c05* pEnd = mpEnd;
    for (Elem_5abc80_c05* pElem = pNew; pElem != pEnd; ++pElem) {
        if (pElem->mpData) {
            Fn0090cf63(pElem->mpData);
        }
    }
    mpEnd = pNew;
    return pFirst;
}
#endif

struct Elem_5be110_c05 {
    uint8_t pad0[0x8];
    void* mpData;
    uint8_t pad1[0x8];
};

// STUB: 0x5bde90
Elem_5be110_c05* Fn5bde90(Elem_5be110_c05* pFirst, Elem_5be110_c05* pLast, Elem_5be110_c05* pDest, Elem_5be110_c05** ppOut, uint32_t nFlag);

struct View_5be110_shapec05_game {
    uint32_t mnPad;
    Elem_5be110_c05* mpEnd;
    Elem_5be110_c05* Fn005be110(Elem_5be110_c05* pFirst, Elem_5be110_c05* pLast);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005be110 score 37
Elem_5be110_c05* View_5be110_shapec05_game::Fn005be110(Elem_5be110_c05* pFirst, Elem_5be110_c05* pLast)
{
    Elem_5be110_c05* pDest = pFirst;
    Elem_5be110_c05* pNew = Fn5bde90(pLast, mpEnd, pDest, &pFirst, 0);
    Elem_5be110_c05* pEnd = mpEnd;
    for (Elem_5be110_c05* pElem = pNew; pElem != pEnd; ++pElem) {
        if (pElem->mpData) {
            Fn0090cf63(pElem->mpData);
        }
    }
    mpEnd = pNew;
    return pFirst;
}
#endif

struct Elem_58ae30_c05 {
    uint8_t d[0x1c];
};

// STUB: 0x5885d0
Elem_58ae30_c05* Fn5885d0(Elem_58ae30_c05* pA, Elem_58ae30_c05* pB, Elem_58ae30_c05* pC, uint32_t* pnOut, uint32_t nFlag);
// STUB: 0x5887d0
void Fn5887d0(Elem_58ae30_c05* pA, Elem_58ae30_c05* pB, uint32_t* pnArg);

struct View_58ae30_shapec05_game {
    Elem_58ae30_c05* mpBegin;
    Elem_58ae30_c05* mpEnd;
    // STUB: 0x58a170
    void Fn58a170(Elem_58ae30_c05* pPos, uint32_t nCount, const Elem_58ae30_c05* pValue);
    void Fn0058ae30(uint32_t nNew, const Elem_58ae30_c05* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058ae30 score 28
void View_58ae30_shapec05_game::Fn0058ae30(uint32_t nNew, const Elem_58ae30_c05* pValue)
{
    uint32_t nOld = static_cast<uint32_t>(mpEnd - mpBegin);
    if (nNew < nOld) {
        Elem_58ae30_c05* pNew = Fn5885d0(mpEnd, mpEnd, mpBegin + nNew, &nNew, 0);
        Fn5887d0(pNew, mpEnd, &nNew);
        mpEnd = pNew;
        return;
    }
    Fn58a170(mpEnd, nNew - nOld, pValue);
}
#endif

struct Elem_58d070_c05 {
    uint8_t d[0x38];
};

// STUB: 0x58b9a0
Elem_58d070_c05* Fn58b9a0(Elem_58d070_c05* pA, Elem_58d070_c05* pB, Elem_58d070_c05* pC, uint32_t* pnOut, uint32_t nFlag);
// STUB: 0x58be50
void Fn58be50(Elem_58d070_c05* pA, Elem_58d070_c05* pB, uint32_t* pnArg);

struct View_58d070_shapec05_game {
    Elem_58d070_c05* mpBegin;
    Elem_58d070_c05* mpEnd;
    // STUB: 0x58c8e0
    void Fn58c8e0(Elem_58d070_c05* pPos, uint32_t nCount, const Elem_58d070_c05* pValue);
    void Fn0058d070(uint32_t nNew, const Elem_58d070_c05* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058d070 score 28
void View_58d070_shapec05_game::Fn0058d070(uint32_t nNew, const Elem_58d070_c05* pValue)
{
    uint32_t nOld = static_cast<uint32_t>(mpEnd - mpBegin);
    if (nNew < nOld) {
        Elem_58d070_c05* pNew = Fn58b9a0(mpEnd, mpEnd, mpBegin + nNew, &nNew, 0);
        Fn58be50(pNew, mpEnd, &nNew);
        mpEnd = pNew;
        return;
    }
    Fn58c8e0(mpEnd, nNew - nOld, pValue);
}
#endif

struct Elem_71f7c0_c05 {
    uint8_t d[0x1c];
};

// STUB: 0x714000
Elem_71f7c0_c05* Fn714000(Elem_71f7c0_c05* pA, Elem_71f7c0_c05* pB, Elem_71f7c0_c05* pC, uint32_t* pnOut, uint32_t nFlag);
// STUB: 0x716a70
void Fn716a70(Elem_71f7c0_c05* pA, Elem_71f7c0_c05* pB, uint32_t* pnArg);

struct View_71f7c0_shapec05_game {
    Elem_71f7c0_c05* mpBegin;
    Elem_71f7c0_c05* mpEnd;
    // STUB: 0x71dec0
    void Fn71dec0(Elem_71f7c0_c05* pPos, uint32_t nCount, const Elem_71f7c0_c05* pValue);
    void Fn0071f7c0(uint32_t nNew, const Elem_71f7c0_c05* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0071f7c0 score 28
void View_71f7c0_shapec05_game::Fn0071f7c0(uint32_t nNew, const Elem_71f7c0_c05* pValue)
{
    uint32_t nOld = static_cast<uint32_t>(mpEnd - mpBegin);
    if (nNew < nOld) {
        Elem_71f7c0_c05* pNew = Fn714000(mpEnd, mpEnd, mpBegin + nNew, &nNew, 0);
        Fn716a70(pNew, mpEnd, &nNew);
        mpEnd = pNew;
        return;
    }
    Fn71dec0(mpEnd, nNew - nOld, pValue);
}
#endif

struct Elem_5b0840_c05 {
    uint8_t d[0x1c];
};

// STUB: 0x5afe00
Elem_5b0840_c05* Fn5afe00(Elem_5b0840_c05* pA, Elem_5b0840_c05* pB, Elem_5b0840_c05* pC, uint32_t* pnOut, uint32_t nFlag);

struct View_5b0840_shapec05_game {
    Elem_5b0840_c05* mpBegin;
    Elem_5b0840_c05* mpEnd;
    // STUB: 0x5b05a0
    void Fn5b05a0(Elem_5b0840_c05* pPos, uint32_t nCount, const Elem_5b0840_c05* pValue);
    void Fn005b0840(uint32_t nNew, const Elem_5b0840_c05* pValue);
};

// FUNCTION: 0x005b0840
void View_5b0840_shapec05_game::Fn005b0840(uint32_t nNew, const Elem_5b0840_c05* pValue)
{
    uint32_t nOld = static_cast<uint32_t>(mpEnd - mpBegin);
    if (nNew < nOld) {
        mpEnd = Fn5afe00(mpEnd, mpEnd, mpBegin + nNew, &nNew, 0);
        return;
    }
    Fn5b05a0(mpEnd, nNew - nOld, pValue);
}

struct Elem_6a1380_c05 {
    uint8_t d[0x1c];
};

// STUB: 0x69fa80
Elem_6a1380_c05* Fn69fa80(Elem_6a1380_c05* pA, Elem_6a1380_c05* pB, Elem_6a1380_c05* pC, uint32_t* pnOut, uint32_t nFlag);

struct View_6a1380_shapec05_game {
    Elem_6a1380_c05* mpBegin;
    Elem_6a1380_c05* mpEnd;
    // STUB: 0x6a02e0
    void Fn6a02e0(Elem_6a1380_c05* pPos, uint32_t nCount, const Elem_6a1380_c05* pValue);
    void Fn006a1380(uint32_t nNew, const Elem_6a1380_c05* pValue);
};

// FUNCTION: 0x006a1380
void View_6a1380_shapec05_game::Fn006a1380(uint32_t nNew, const Elem_6a1380_c05* pValue)
{
    uint32_t nOld = static_cast<uint32_t>(mpEnd - mpBegin);
    if (nNew < nOld) {
        mpEnd = Fn69fa80(mpEnd, mpEnd, mpBegin + nNew, &nNew, 0);
        return;
    }
    Fn6a02e0(mpEnd, nNew - nOld, pValue);
}

struct Elem_8df1f0_c05 {
    uint8_t d[0xcc];
};

// STUB: 0x8de5c0
Elem_8df1f0_c05* Fn8de5c0(Elem_8df1f0_c05* pA, Elem_8df1f0_c05* pB, Elem_8df1f0_c05* pC, uint32_t* pnOut, uint32_t nFlag);

struct View_8df1f0_shapec05_game {
    Elem_8df1f0_c05* mpBegin;
    Elem_8df1f0_c05* mpEnd;
    // STUB: 0x8def60
    void Fn8def60(Elem_8df1f0_c05* pPos, uint32_t nCount, const Elem_8df1f0_c05* pValue);
    void Fn008df1f0(uint32_t nNew, const Elem_8df1f0_c05* pValue);
};

// FUNCTION: 0x008df1f0
void View_8df1f0_shapec05_game::Fn008df1f0(uint32_t nNew, const Elem_8df1f0_c05* pValue)
{
    uint32_t nOld = static_cast<uint32_t>(mpEnd - mpBegin);
    if (nNew < nOld) {
        mpEnd = Fn8de5c0(mpEnd, mpEnd, mpBegin + nNew, &nNew, 0);
        return;
    }
    Fn8def60(mpEnd, nNew - nOld, pValue);
}

struct Obj_58fec0_c05 {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
};

struct Elem_58fec0_c05 {
    uint8_t pad0[0x38];
    Obj_58fec0_c05* mpObj;
    uint8_t pad1[0x8];
};

// STUB: 0x58e120
Elem_58fec0_c05* Fn58e120(Elem_58fec0_c05* pFirst, Elem_58fec0_c05* pLast, Elem_58fec0_c05* pDest, Elem_58fec0_c05** ppOut, uint32_t nFlag);

struct View_58fec0_shapec05_game {
    uint32_t mnPad;
    Elem_58fec0_c05* mpEnd;
    Elem_58fec0_c05* Fn0058fec0(Elem_58fec0_c05* pFirst, Elem_58fec0_c05* pLast);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058fec0 score 39
Elem_58fec0_c05* View_58fec0_shapec05_game::Fn0058fec0(Elem_58fec0_c05* pFirst, Elem_58fec0_c05* pLast)
{
    Elem_58fec0_c05* pOrig = pFirst;
    Elem_58fec0_c05* pNew = Fn58e120(pLast, mpEnd, pFirst, &pFirst, 0);
    Elem_58fec0_c05* pEnd = mpEnd;
    if (pNew != pEnd) {
        for (Elem_58fec0_c05* pElem = pNew; pElem != pEnd; ++pElem) {
            if (pElem->mpObj) {
                pElem->mpObj->Slot08();
            }
        }
        mpEnd = pNew;
        return pFirst;
    }
    mpEnd = pNew;
    return pOrig;
}
#endif

struct Obj_77c3c0_c05 {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
};

struct Elem_77c3c0_c05 {
    uint8_t pad0[0x10];
    Obj_77c3c0_c05* mpObj;
    uint8_t pad1[0x4];
};

// STUB: 0x77a080
Elem_77c3c0_c05* Fn77a080(Elem_77c3c0_c05* pFirst, Elem_77c3c0_c05* pLast, Elem_77c3c0_c05* pDest, Elem_77c3c0_c05** ppOut, uint32_t nFlag);

struct View_77c3c0_shapec05_game {
    uint32_t mnPad;
    Elem_77c3c0_c05* mpEnd;
    Elem_77c3c0_c05* Fn0077c3c0(Elem_77c3c0_c05* pFirst, Elem_77c3c0_c05* pLast);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0077c3c0 score 39
Elem_77c3c0_c05* View_77c3c0_shapec05_game::Fn0077c3c0(Elem_77c3c0_c05* pFirst, Elem_77c3c0_c05* pLast)
{
    Elem_77c3c0_c05* pOrig = pFirst;
    Elem_77c3c0_c05* pNew = Fn77a080(pLast, mpEnd, pFirst, &pFirst, 0);
    Elem_77c3c0_c05* pEnd = mpEnd;
    if (pNew != pEnd) {
        for (Elem_77c3c0_c05* pElem = pNew; pElem != pEnd; ++pElem) {
            if (pElem->mpObj) {
                pElem->mpObj->Slot02();
            }
        }
        mpEnd = pNew;
        return pFirst;
    }
    mpEnd = pNew;
    return pOrig;
}
#endif

struct Obj_77c420_c05 {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
};

struct Elem_77c420_c05 {
    uint8_t pad0[0x4];
    Obj_77c420_c05* mpObj;
};

// STUB: 0x77a120
Elem_77c420_c05* Fn77a120(Elem_77c420_c05* pFirst, Elem_77c420_c05* pLast, Elem_77c420_c05* pDest, Elem_77c420_c05** ppOut, uint32_t nFlag);

struct View_77c420_shapec05_game {
    uint32_t mnPad;
    Elem_77c420_c05* mpEnd;
    Elem_77c420_c05* Fn0077c420(Elem_77c420_c05* pFirst, Elem_77c420_c05* pLast);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0077c420 score 39
Elem_77c420_c05* View_77c420_shapec05_game::Fn0077c420(Elem_77c420_c05* pFirst, Elem_77c420_c05* pLast)
{
    Elem_77c420_c05* pOrig = pFirst;
    Elem_77c420_c05* pNew = Fn77a120(pLast, mpEnd, pFirst, &pFirst, 0);
    Elem_77c420_c05* pEnd = mpEnd;
    if (pNew != pEnd) {
        for (Elem_77c420_c05* pElem = pNew; pElem != pEnd; ++pElem) {
            if (pElem->mpObj) {
                pElem->mpObj->Slot02();
            }
        }
        mpEnd = pNew;
        return pFirst;
    }
    mpEnd = pNew;
    return pOrig;
}
#endif

struct Elem_5be170_c05 {
    uint8_t d[0x14];
};

struct View_5be170_shapec05_game {
    Elem_5be170_c05* mpBegin;
    Elem_5be170_c05* mpEnd;
    // STUB: 0x5be110
    Elem_5be170_c05* Fn5be110(Elem_5be170_c05* pFirst, Elem_5be170_c05* pLast);
    // STUB: 0x5bdf60
    void Fn5bdf60(Elem_5be170_c05* pPos, uint32_t nCount, const Elem_5be170_c05* pValue);
    void Fn005be170(uint32_t nNew, const Elem_5be170_c05* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005be170 score 36
void View_5be170_shapec05_game::Fn005be170(uint32_t nNew, const Elem_5be170_c05* pValue)
{
    Elem_5be170_c05* pEnd = mpEnd;
    Elem_5be170_c05* pBegin = mpBegin;
    uint32_t nOld = static_cast<uint32_t>(pEnd - pBegin);
    if (nNew < nOld) {
        Fn5be110(pBegin + nNew, pEnd);
        return;
    }
    Fn5bdf60(mpEnd, nNew - nOld, pValue);
}
#endif

struct Elem_5c8730_c05 {
    uint8_t d[0x14];
};

struct View_5c8730_shapec05_game {
    Elem_5c8730_c05* mpBegin;
    Elem_5c8730_c05* mpEnd;
    // STUB: 0x4863f0
    Elem_5c8730_c05* Fn4863f0(Elem_5c8730_c05* pFirst, Elem_5c8730_c05* pLast);
    // STUB: 0x5c85c0
    void Fn5c85c0(Elem_5c8730_c05* pPos, uint32_t nCount, const Elem_5c8730_c05* pValue);
    void Fn005c8730(uint32_t nNew, const Elem_5c8730_c05* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005c8730 score 36
void View_5c8730_shapec05_game::Fn005c8730(uint32_t nNew, const Elem_5c8730_c05* pValue)
{
    Elem_5c8730_c05* pEnd = mpEnd;
    Elem_5c8730_c05* pBegin = mpBegin;
    uint32_t nOld = static_cast<uint32_t>(pEnd - pBegin);
    if (nNew < nOld) {
        Fn4863f0(pBegin + nNew, pEnd);
        return;
    }
    Fn5c85c0(mpEnd, nNew - nOld, pValue);
}
#endif

