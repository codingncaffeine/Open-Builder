// Shape families of packet shapeb02_game, written by scratch/s16/gen/shapeb02_game/gen.sh.
#include "common/types.h"
#include <new>
#include "gzcom/cRZString.h"

// STUB: 0x009ef059
extern "C" int atexit(void (*f)());

struct Elem_0058aea0_shapeb02_game {
    void* mpData;
    uint8_t pad[16];
};

// STUB: 0x0058a4c0
Elem_0058aea0_shapeb02_game* Fn0058a4c0_0058aea0(Elem_0058aea0_shapeb02_game* pFirst, Elem_0058aea0_shapeb02_game* pLast, Elem_0058aea0_shapeb02_game* pDst, Elem_0058aea0_shapeb02_game** ppOut, uint32_t nFlag);

// STUB: 0x0090cf63
void Fn0090cf63_0058aea0(void* p);

struct View_0058aea0_shapeb02_game {
    uint32_t mnField0;
    Elem_0058aea0_shapeb02_game* mpEnd;
    Elem_0058aea0_shapeb02_game* Fn0058aea0(Elem_0058aea0_shapeb02_game* pPos, Elem_0058aea0_shapeb02_game* pLast);
};

// FUNCTION: 0x0058aea0
Elem_0058aea0_shapeb02_game* View_0058aea0_shapeb02_game::Fn0058aea0(Elem_0058aea0_shapeb02_game* pPos, Elem_0058aea0_shapeb02_game* pLast)
{
    Elem_0058aea0_shapeb02_game* pBegin = pPos;
    Elem_0058aea0_shapeb02_game* pEnd = mpEnd;
    Elem_0058aea0_shapeb02_game* pNew = Fn0058a4c0_0058aea0(pLast, pEnd, pBegin, &pPos, 0);
    Elem_0058aea0_shapeb02_game* pOld = mpEnd;
    for (Elem_0058aea0_shapeb02_game* p = pNew; p != pOld; ++p) {
        if (p->mpData) {
            Fn0090cf63_0058aea0(p->mpData);
        }
    }
    mpEnd = pNew;
    return pPos;
}

struct Elem_005abc20_shapeb02_game {
    void* mpData;
    uint8_t pad[104];
};

// STUB: 0x005ab920
Elem_005abc20_shapeb02_game* Fn005ab920_005abc20(Elem_005abc20_shapeb02_game* pFirst, Elem_005abc20_shapeb02_game* pLast, Elem_005abc20_shapeb02_game* pDst, Elem_005abc20_shapeb02_game** ppOut, uint32_t nFlag);

// STUB: 0x0090cf63
void Fn0090cf63_005abc20(void* p);

struct View_005abc20_shapeb02_game {
    uint32_t mnField0;
    Elem_005abc20_shapeb02_game* mpEnd;
    Elem_005abc20_shapeb02_game* Fn005abc20(Elem_005abc20_shapeb02_game* pPos, Elem_005abc20_shapeb02_game* pLast);
};

// FUNCTION: 0x005abc20
Elem_005abc20_shapeb02_game* View_005abc20_shapeb02_game::Fn005abc20(Elem_005abc20_shapeb02_game* pPos, Elem_005abc20_shapeb02_game* pLast)
{
    Elem_005abc20_shapeb02_game* pBegin = pPos;
    Elem_005abc20_shapeb02_game* pEnd = mpEnd;
    Elem_005abc20_shapeb02_game* pNew = Fn005ab920_005abc20(pLast, pEnd, pBegin, &pPos, 0);
    Elem_005abc20_shapeb02_game* pOld = mpEnd;
    for (Elem_005abc20_shapeb02_game* p = pNew; p != pOld; ++p) {
        if (p->mpData) {
            Fn0090cf63_005abc20(p->mpData);
        }
    }
    mpEnd = pNew;
    return pPos;
}

struct Elem_005b1790_shapeb02_game {
    void* mpData;
    uint8_t pad[12];
};

// STUB: 0x005b0f80
Elem_005b1790_shapeb02_game* Fn005b0f80_005b1790(Elem_005b1790_shapeb02_game* pFirst, Elem_005b1790_shapeb02_game* pLast, Elem_005b1790_shapeb02_game* pDst, Elem_005b1790_shapeb02_game** ppOut, uint32_t nFlag);

// STUB: 0x0090cf63
void Fn0090cf63_005b1790(void* p);

struct View_005b1790_shapeb02_game {
    uint32_t mnField0;
    Elem_005b1790_shapeb02_game* mpEnd;
    Elem_005b1790_shapeb02_game* Fn005b1790(Elem_005b1790_shapeb02_game* pPos, Elem_005b1790_shapeb02_game* pLast);
};

// FUNCTION: 0x005b1790
Elem_005b1790_shapeb02_game* View_005b1790_shapeb02_game::Fn005b1790(Elem_005b1790_shapeb02_game* pPos, Elem_005b1790_shapeb02_game* pLast)
{
    Elem_005b1790_shapeb02_game* pBegin = pPos;
    Elem_005b1790_shapeb02_game* pEnd = mpEnd;
    Elem_005b1790_shapeb02_game* pNew = Fn005b0f80_005b1790(pLast, pEnd, pBegin, &pPos, 0);
    Elem_005b1790_shapeb02_game* pOld = mpEnd;
    for (Elem_005b1790_shapeb02_game* p = pNew; p != pOld; ++p) {
        if (p->mpData) {
            Fn0090cf63_005b1790(p->mpData);
        }
    }
    mpEnd = pNew;
    return pPos;
}

struct Elem_005db690_shapeb02_game {
    void* mpData;
    uint8_t pad[16];
};

// STUB: 0x005db070
Elem_005db690_shapeb02_game* Fn005db070_005db690(Elem_005db690_shapeb02_game* pFirst, Elem_005db690_shapeb02_game* pLast, Elem_005db690_shapeb02_game* pDst, Elem_005db690_shapeb02_game** ppOut, uint32_t nFlag);

// STUB: 0x0090cf63
void Fn0090cf63_005db690(void* p);

struct View_005db690_shapeb02_game {
    uint32_t mnField0;
    Elem_005db690_shapeb02_game* mpEnd;
    Elem_005db690_shapeb02_game* Fn005db690(Elem_005db690_shapeb02_game* pPos, Elem_005db690_shapeb02_game* pLast);
};

// FUNCTION: 0x005db690
Elem_005db690_shapeb02_game* View_005db690_shapeb02_game::Fn005db690(Elem_005db690_shapeb02_game* pPos, Elem_005db690_shapeb02_game* pLast)
{
    Elem_005db690_shapeb02_game* pBegin = pPos;
    Elem_005db690_shapeb02_game* pEnd = mpEnd;
    Elem_005db690_shapeb02_game* pNew = Fn005db070_005db690(pLast, pEnd, pBegin, &pPos, 0);
    Elem_005db690_shapeb02_game* pOld = mpEnd;
    for (Elem_005db690_shapeb02_game* p = pNew; p != pOld; ++p) {
        if (p->mpData) {
            Fn0090cf63_005db690(p->mpData);
        }
    }
    mpEnd = pNew;
    return pPos;
}

struct Elem_006135e0_shapeb02_game {
    void* mpData;
    uint8_t pad[8];
};

// STUB: 0x00611c60
Elem_006135e0_shapeb02_game* Fn00611c60_006135e0(Elem_006135e0_shapeb02_game* pFirst, Elem_006135e0_shapeb02_game* pLast, Elem_006135e0_shapeb02_game* pDst, Elem_006135e0_shapeb02_game** ppOut, uint32_t nFlag);

// STUB: 0x0090cf63
void Fn0090cf63_006135e0(void* p);

struct View_006135e0_shapeb02_game {
    uint32_t mnField0;
    Elem_006135e0_shapeb02_game* mpEnd;
    Elem_006135e0_shapeb02_game* Fn006135e0(Elem_006135e0_shapeb02_game* pPos, Elem_006135e0_shapeb02_game* pLast);
};

// FUNCTION: 0x006135e0
Elem_006135e0_shapeb02_game* View_006135e0_shapeb02_game::Fn006135e0(Elem_006135e0_shapeb02_game* pPos, Elem_006135e0_shapeb02_game* pLast)
{
    Elem_006135e0_shapeb02_game* pBegin = pPos;
    Elem_006135e0_shapeb02_game* pEnd = mpEnd;
    Elem_006135e0_shapeb02_game* pNew = Fn00611c60_006135e0(pLast, pEnd, pBegin, &pPos, 0);
    Elem_006135e0_shapeb02_game* pOld = mpEnd;
    for (Elem_006135e0_shapeb02_game* p = pNew; p != pOld; ++p) {
        if (p->mpData) {
            Fn0090cf63_006135e0(p->mpData);
        }
    }
    mpEnd = pNew;
    return pPos;
}

struct Elem_0064cf40_shapeb02_game {
    void* mpData;
    uint8_t pad[8];
};

// STUB: 0x0064b5c0
Elem_0064cf40_shapeb02_game* Fn0064b5c0_0064cf40(Elem_0064cf40_shapeb02_game* pFirst, Elem_0064cf40_shapeb02_game* pLast, Elem_0064cf40_shapeb02_game* pDst, Elem_0064cf40_shapeb02_game** ppOut, uint32_t nFlag);

// STUB: 0x0090cf63
void Fn0090cf63_0064cf40(void* p);

struct View_0064cf40_shapeb02_game {
    uint32_t mnField0;
    Elem_0064cf40_shapeb02_game* mpEnd;
    Elem_0064cf40_shapeb02_game* Fn0064cf40(Elem_0064cf40_shapeb02_game* pPos, Elem_0064cf40_shapeb02_game* pLast);
};

// FUNCTION: 0x0064cf40
Elem_0064cf40_shapeb02_game* View_0064cf40_shapeb02_game::Fn0064cf40(Elem_0064cf40_shapeb02_game* pPos, Elem_0064cf40_shapeb02_game* pLast)
{
    Elem_0064cf40_shapeb02_game* pBegin = pPos;
    Elem_0064cf40_shapeb02_game* pEnd = mpEnd;
    Elem_0064cf40_shapeb02_game* pNew = Fn0064b5c0_0064cf40(pLast, pEnd, pBegin, &pPos, 0);
    Elem_0064cf40_shapeb02_game* pOld = mpEnd;
    for (Elem_0064cf40_shapeb02_game* p = pNew; p != pOld; ++p) {
        if (p->mpData) {
            Fn0090cf63_0064cf40(p->mpData);
        }
    }
    mpEnd = pNew;
    return pPos;
}

struct Elem_00650250_shapeb02_game {
    void* mpData;
    uint8_t pad[8];
};

// STUB: 0x0064faf0
Elem_00650250_shapeb02_game* Fn0064faf0_00650250(Elem_00650250_shapeb02_game* pFirst, Elem_00650250_shapeb02_game* pLast, Elem_00650250_shapeb02_game* pDst, Elem_00650250_shapeb02_game** ppOut, uint32_t nFlag);

// STUB: 0x0090cf63
void Fn0090cf63_00650250(void* p);

struct View_00650250_shapeb02_game {
    uint32_t mnField0;
    Elem_00650250_shapeb02_game* mpEnd;
    Elem_00650250_shapeb02_game* Fn00650250(Elem_00650250_shapeb02_game* pPos, Elem_00650250_shapeb02_game* pLast);
};

// FUNCTION: 0x00650250
Elem_00650250_shapeb02_game* View_00650250_shapeb02_game::Fn00650250(Elem_00650250_shapeb02_game* pPos, Elem_00650250_shapeb02_game* pLast)
{
    Elem_00650250_shapeb02_game* pBegin = pPos;
    Elem_00650250_shapeb02_game* pEnd = mpEnd;
    Elem_00650250_shapeb02_game* pNew = Fn0064faf0_00650250(pLast, pEnd, pBegin, &pPos, 0);
    Elem_00650250_shapeb02_game* pOld = mpEnd;
    for (Elem_00650250_shapeb02_game* p = pNew; p != pOld; ++p) {
        if (p->mpData) {
            Fn0090cf63_00650250(p->mpData);
        }
    }
    mpEnd = pNew;
    return pPos;
}

struct Elem_00650360_shapeb02_game {
    void* mpData;
    uint8_t pad[8];
};

// STUB: 0x0064fa10
Elem_00650360_shapeb02_game* Fn0064fa10_00650360(Elem_00650360_shapeb02_game* pFirst, Elem_00650360_shapeb02_game* pLast, Elem_00650360_shapeb02_game* pDst, Elem_00650360_shapeb02_game** ppOut, uint32_t nFlag);

// STUB: 0x0090cf63
void Fn0090cf63_00650360(void* p);

struct View_00650360_shapeb02_game {
    uint32_t mnField0;
    Elem_00650360_shapeb02_game* mpEnd;
    Elem_00650360_shapeb02_game* Fn00650360(Elem_00650360_shapeb02_game* pPos, Elem_00650360_shapeb02_game* pLast);
};

// FUNCTION: 0x00650360
Elem_00650360_shapeb02_game* View_00650360_shapeb02_game::Fn00650360(Elem_00650360_shapeb02_game* pPos, Elem_00650360_shapeb02_game* pLast)
{
    Elem_00650360_shapeb02_game* pBegin = pPos;
    Elem_00650360_shapeb02_game* pEnd = mpEnd;
    Elem_00650360_shapeb02_game* pNew = Fn0064fa10_00650360(pLast, pEnd, pBegin, &pPos, 0);
    Elem_00650360_shapeb02_game* pOld = mpEnd;
    for (Elem_00650360_shapeb02_game* p = pNew; p != pOld; ++p) {
        if (p->mpData) {
            Fn0090cf63_00650360(p->mpData);
        }
    }
    mpEnd = pNew;
    return pPos;
}

struct Elem_006b71c0_shapeb02_game {
    void* mpData;
    uint8_t pad[12];
};

// STUB: 0x006b3b90
Elem_006b71c0_shapeb02_game* Fn006b3b90_006b71c0(Elem_006b71c0_shapeb02_game* pFirst, Elem_006b71c0_shapeb02_game* pLast, Elem_006b71c0_shapeb02_game* pDst, Elem_006b71c0_shapeb02_game** ppOut, uint32_t nFlag);

// STUB: 0x0090cf63
void Fn0090cf63_006b71c0(void* p);

struct View_006b71c0_shapeb02_game {
    uint32_t mnField0;
    Elem_006b71c0_shapeb02_game* mpEnd;
    Elem_006b71c0_shapeb02_game* Fn006b71c0(Elem_006b71c0_shapeb02_game* pPos, Elem_006b71c0_shapeb02_game* pLast);
};

// FUNCTION: 0x006b71c0
Elem_006b71c0_shapeb02_game* View_006b71c0_shapeb02_game::Fn006b71c0(Elem_006b71c0_shapeb02_game* pPos, Elem_006b71c0_shapeb02_game* pLast)
{
    Elem_006b71c0_shapeb02_game* pBegin = pPos;
    Elem_006b71c0_shapeb02_game* pEnd = mpEnd;
    Elem_006b71c0_shapeb02_game* pNew = Fn006b3b90_006b71c0(pLast, pEnd, pBegin, &pPos, 0);
    Elem_006b71c0_shapeb02_game* pOld = mpEnd;
    for (Elem_006b71c0_shapeb02_game* p = pNew; p != pOld; ++p) {
        if (p->mpData) {
            Fn0090cf63_006b71c0(p->mpData);
        }
    }
    mpEnd = pNew;
    return pPos;
}

struct Base_005ca7a0_shapeb02_game {
    // STUB: 0x005e89c0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_005ca7a0_shapeb02_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005ca7a0
bool View_005ca7a0_shapeb02_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0x496e7636) {
        *ppv = this;
        Slot01();
        return true;
    }
    return reinterpret_cast<Base_005ca7a0_shapeb02_game*>(reinterpret_cast<char*>(this) + 0x8)->QueryInterface(iid, ppv);
}

struct Base_00762490_shapeb02_game {
    // STUB: 0x0099b774
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_00762490_shapeb02_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00762490
bool View_00762490_shapeb02_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0xbcbf1df) {
        *ppv = this;
        Slot01();
        return true;
    }
    return reinterpret_cast<Base_00762490_shapeb02_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
}

struct Base_00797f50_shapeb02_game {
    // STUB: 0x0099b774
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_00797f50_shapeb02_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00797f50
bool View_00797f50_shapeb02_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0xc9b432cf) {
        *ppv = this;
        Slot01();
        return true;
    }
    return reinterpret_cast<Base_00797f50_shapeb02_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
}

struct Base_0079a080_shapeb02_game {
    // STUB: 0x0099b774
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_0079a080_shapeb02_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0079a080
bool View_0079a080_shapeb02_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0x49d98264) {
        *ppv = this;
        Slot01();
        return true;
    }
    return reinterpret_cast<Base_0079a080_shapeb02_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
}

struct Base_0079a110_shapeb02_game {
    // STUB: 0x0099b774
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_0079a110_shapeb02_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0079a110
bool View_0079a110_shapeb02_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0x8a25ce2c) {
        *ppv = this;
        Slot01();
        return true;
    }
    return reinterpret_cast<Base_0079a110_shapeb02_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
}

struct Base_007b23e0_shapeb02_game {
    // STUB: 0x009457c6
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_007b23e0_shapeb02_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x007b23e0
bool View_007b23e0_shapeb02_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0xc989f960) {
        *ppv = this;
        Slot01();
        return true;
    }
    return reinterpret_cast<Base_007b23e0_shapeb02_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
}

struct Base_008085c0_shapeb02_game {
    // STUB: 0x00975395
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_008085c0_shapeb02_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x008085c0
bool View_008085c0_shapeb02_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0x29a5d1ec) {
        *ppv = this;
        Slot01();
        return true;
    }
    return reinterpret_cast<Base_008085c0_shapeb02_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
}

struct Base_00808630_shapeb02_game {
    // STUB: 0x00975395
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_00808630_shapeb02_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00808630
bool View_00808630_shapeb02_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0x69b6f01c) {
        *ppv = this;
        Slot01();
        return true;
    }
    return reinterpret_cast<Base_00808630_shapeb02_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
}

struct Base_0082b890_shapeb02_game {
    // STUB: 0x0091dd67
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_0082b890_shapeb02_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0082b890
bool View_0082b890_shapeb02_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0x4b2ea3b3) {
        *ppv = this;
        Slot01();
        return true;
    }
    return reinterpret_cast<Base_0082b890_shapeb02_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
}

#pragma pack(push, 4)
struct View_005fd620_shapeb02_game {
    uint8_t pad[0x4];
    int64_t mnValue;
    int64_t Get();
};
#pragma pack(pop)

// FUNCTION: 0x005fd620
int64_t View_005fd620_shapeb02_game::Get()
{
    return mnValue;
}

#pragma pack(push, 4)
struct View_00604e10_shapeb02_game {
    uint8_t pad[0x170];
    int64_t mnValue;
    int64_t Get();
};
#pragma pack(pop)

// FUNCTION: 0x00604e10
int64_t View_00604e10_shapeb02_game::Get()
{
    return mnValue;
}

#pragma pack(push, 4)
struct View_006ce110_shapeb02_game {
    uint8_t pad[0x50];
    int64_t mnValue;
    int64_t Get();
};
#pragma pack(pop)

// FUNCTION: 0x006ce110
int64_t View_006ce110_shapeb02_game::Get()
{
    return mnValue;
}

#pragma pack(push, 4)
struct View_0080bc30_shapeb02_game {
    uint8_t pad[0x70];
    int64_t mnValue;
    int64_t Get();
};
#pragma pack(pop)

// FUNCTION: 0x0080bc30
int64_t View_0080bc30_shapeb02_game::Get()
{
    return mnValue;
}

#pragma pack(push, 4)
struct View_0080bc40_shapeb02_game {
    uint8_t pad[0x78];
    int64_t mnValue;
    int64_t Get();
};
#pragma pack(pop)

// FUNCTION: 0x0080bc40
int64_t View_0080bc40_shapeb02_game::Get()
{
    return mnValue;
}

#pragma pack(push, 4)
struct View_0080bca0_shapeb02_game {
    uint8_t pad[0x98];
    int64_t mnValue;
    int64_t Get();
};
#pragma pack(pop)

// FUNCTION: 0x0080bca0
int64_t View_0080bca0_shapeb02_game::Get()
{
    return mnValue;
}

#pragma pack(push, 4)
struct View_0080c350_shapeb02_game {
    uint8_t pad[0x80];
    int64_t mnValue;
    int64_t Get();
};
#pragma pack(pop)

// FUNCTION: 0x0080c350
int64_t View_0080c350_shapeb02_game::Get()
{
    return mnValue;
}

#pragma pack(push, 4)
struct View_0080d500_shapeb02_game {
    uint8_t pad[0x18];
    int64_t mnValue;
    int64_t Get();
};
#pragma pack(pop)

// FUNCTION: 0x0080d500
int64_t View_0080d500_shapeb02_game::Get()
{
    return mnValue;
}

#pragma pack(push, 4)
struct View_0080d510_shapeb02_game {
    uint8_t pad[0x20];
    int64_t mnValue;
    int64_t Get();
};
#pragma pack(pop)

// FUNCTION: 0x0080d510
int64_t View_0080d510_shapeb02_game::Get()
{
    return mnValue;
}

struct Vec3_00458c30_shapeb02_game {
    float x;
    float y;
    float z;
};

struct View_00458c30_shapeb02_game {
    uint8_t pad[0x38];
    Vec3_00458c30_shapeb02_game mMin;
    Vec3_00458c30_shapeb02_game mMax;
    void GetPair(Vec3_00458c30_shapeb02_game* pA, Vec3_00458c30_shapeb02_game* pB);
};

// FUNCTION: 0x00458c30
void View_00458c30_shapeb02_game::GetPair(Vec3_00458c30_shapeb02_game* pA, Vec3_00458c30_shapeb02_game* pB)
{
    pA->x = mMin.x;
    pA->y = mMin.y;
    pA->z = mMin.z;
    pB->x = mMax.x;
    pB->y = mMax.y;
    pB->z = mMax.z;
}

struct Vec3_00477420_shapeb02_game {
    float x;
    float y;
    float z;
};

struct View_00477420_shapeb02_game {
    uint8_t pad[0x40];
    Vec3_00477420_shapeb02_game mMin;
    Vec3_00477420_shapeb02_game mMax;
    void GetPair(Vec3_00477420_shapeb02_game* pA, Vec3_00477420_shapeb02_game* pB);
};

// FUNCTION: 0x00477420
void View_00477420_shapeb02_game::GetPair(Vec3_00477420_shapeb02_game* pA, Vec3_00477420_shapeb02_game* pB)
{
    pA->x = mMin.x;
    pA->y = mMin.y;
    pA->z = mMin.z;
    pB->x = mMax.x;
    pB->y = mMax.y;
    pB->z = mMax.z;
}

struct Vec3_005b2b20_shapeb02_game {
    float x;
    float y;
    float z;
};

struct View_005b2b20_shapeb02_game {
    uint8_t pad[0x34];
    Vec3_005b2b20_shapeb02_game mPos;
    void GetPair(Vec3_005b2b20_shapeb02_game* pA, Vec3_005b2b20_shapeb02_game* pB);
};

// FUNCTION: 0x005b2b20
void View_005b2b20_shapeb02_game::GetPair(Vec3_005b2b20_shapeb02_game* pA, Vec3_005b2b20_shapeb02_game* pB)
{
    pA->x = mPos.x;
    pA->y = mPos.y;
    pA->z = mPos.z;
    pB->x = mPos.x;
    pB->y = mPos.y;
    pB->z = mPos.z;
}

struct Vec3_005ca820_shapeb02_game {
    float x;
    float y;
    float z;
};

struct View_005ca820_shapeb02_game {
    uint8_t pad[0xa0];
    Vec3_005ca820_shapeb02_game mMin;
    Vec3_005ca820_shapeb02_game mMax;
    void GetPair(Vec3_005ca820_shapeb02_game* pA, Vec3_005ca820_shapeb02_game* pB);
};

// FUNCTION: 0x005ca820
void View_005ca820_shapeb02_game::GetPair(Vec3_005ca820_shapeb02_game* pA, Vec3_005ca820_shapeb02_game* pB)
{
    pA->x = mMin.x;
    pA->y = mMin.y;
    pA->z = mMin.z;
    pB->x = mMax.x;
    pB->y = mMax.y;
    pB->z = mMax.z;
}

struct Vec3_005ded60_shapeb02_game {
    float x;
    float y;
    float z;
};

struct View_005ded60_shapeb02_game {
    uint8_t pad[0x34];
    Vec3_005ded60_shapeb02_game mMin;
    Vec3_005ded60_shapeb02_game mMax;
    void GetPair(Vec3_005ded60_shapeb02_game* pA, Vec3_005ded60_shapeb02_game* pB);
};

// FUNCTION: 0x005ded60
void View_005ded60_shapeb02_game::GetPair(Vec3_005ded60_shapeb02_game* pA, Vec3_005ded60_shapeb02_game* pB)
{
    pA->x = mMin.x;
    pA->y = mMin.y;
    pA->z = mMin.z;
    pB->x = mMax.x;
    pB->y = mMax.y;
    pB->z = mMax.z;
}

struct Vec3_005f08c0_shapeb02_game {
    float x;
    float y;
    float z;
};

struct View_005f08c0_shapeb02_game {
    uint8_t pad[0xc4];
    Vec3_005f08c0_shapeb02_game mMin;
    Vec3_005f08c0_shapeb02_game mMax;
    void GetPair(Vec3_005f08c0_shapeb02_game* pA, Vec3_005f08c0_shapeb02_game* pB);
};

// FUNCTION: 0x005f08c0
void View_005f08c0_shapeb02_game::GetPair(Vec3_005f08c0_shapeb02_game* pA, Vec3_005f08c0_shapeb02_game* pB)
{
    pA->x = mMin.x;
    pA->y = mMin.y;
    pA->z = mMin.z;
    pB->x = mMax.x;
    pB->y = mMax.y;
    pB->z = mMax.z;
}

struct Vec3_00619360_shapeb02_game {
    float x;
    float y;
    float z;
};

struct View_00619360_shapeb02_game {
    uint8_t pad[0x120];
    Vec3_00619360_shapeb02_game mMin;
    Vec3_00619360_shapeb02_game mMax;
    void GetPair(Vec3_00619360_shapeb02_game* pA, Vec3_00619360_shapeb02_game* pB);
};

// FUNCTION: 0x00619360
void View_00619360_shapeb02_game::GetPair(Vec3_00619360_shapeb02_game* pA, Vec3_00619360_shapeb02_game* pB)
{
    pA->x = mMin.x;
    pA->y = mMin.y;
    pA->z = mMin.z;
    pB->x = mMax.x;
    pB->y = mMax.y;
    pB->z = mMax.z;
}

struct Vec3_007f7a00_shapeb02_game {
    float x;
    float y;
    float z;
};

struct View_007f7a00_shapeb02_game {
    uint8_t pad[0x78];
    Vec3_007f7a00_shapeb02_game mMin;
    Vec3_007f7a00_shapeb02_game mMax;
    void GetPair(Vec3_007f7a00_shapeb02_game* pA, Vec3_007f7a00_shapeb02_game* pB);
};

// FUNCTION: 0x007f7a00
void View_007f7a00_shapeb02_game::GetPair(Vec3_007f7a00_shapeb02_game* pA, Vec3_007f7a00_shapeb02_game* pB)
{
    pA->x = mMin.x;
    pA->y = mMin.y;
    pA->z = mMin.z;
    pB->x = mMax.x;
    pB->y = mMax.y;
    pB->z = mMax.z;
}

struct PoolNode_shapeb02_game {
    PoolNode_shapeb02_game* mpNext;
};

struct PoolBlock_shapeb02_game {
    uint32_t pad0;
    uint32_t pad4;
    PoolNode_shapeb02_game* mpFree;
    uint32_t mnUsed;
};

struct Pool_00458f40_shapeb02_game {
    uint32_t mnField00;
    PoolBlock_shapeb02_game* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_shapeb02_game* Refill();
};

struct Obj_00458f40_shapeb02_game {
    // STUB: 0x00458e90
    Obj_00458f40_shapeb02_game* Ctor();
};

// GLOBAL: 0x00b07f1c
extern Pool_00458f40_shapeb02_game gPool_00458f40;

// FUNCTION: 0x00458f40
Obj_00458f40_shapeb02_game* Fn00458f40()
{
    PoolNode_shapeb02_game* pNode = gPool_00458f40.mpBlock->mpFree;
    if (!pNode) {
        pNode = gPool_00458f40.Refill();
    }
    gPool_00458f40.mpBlock->mpFree = pNode->mpNext;
    gPool_00458f40.mpBlock->mnUsed++;
    return reinterpret_cast<Obj_00458f40_shapeb02_game*>(pNode)->Ctor();
}

struct Pool_00472c30_shapeb02_game {
    uint32_t mnField00;
    PoolBlock_shapeb02_game* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_shapeb02_game* Refill();
};

struct Obj_00472c30_shapeb02_game {
    // STUB: 0x00472b30
    Obj_00472c30_shapeb02_game* Ctor();
};

// GLOBAL: 0x00b07fc8
extern Pool_00472c30_shapeb02_game gPool_00472c30;

// FUNCTION: 0x00472c30
Obj_00472c30_shapeb02_game* Fn00472c30()
{
    PoolNode_shapeb02_game* pNode = gPool_00472c30.mpBlock->mpFree;
    if (!pNode) {
        pNode = gPool_00472c30.Refill();
    }
    gPool_00472c30.mpBlock->mpFree = pNode->mpNext;
    gPool_00472c30.mpBlock->mnUsed++;
    return reinterpret_cast<Obj_00472c30_shapeb02_game*>(pNode)->Ctor();
}

struct Pool_004776b0_shapeb02_game {
    uint32_t mnField00;
    PoolBlock_shapeb02_game* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_shapeb02_game* Refill();
};

struct Obj_004776b0_shapeb02_game {
    // STUB: 0x004774c0
    Obj_004776b0_shapeb02_game* Ctor();
};

// GLOBAL: 0x00b09428
extern Pool_004776b0_shapeb02_game gPool_004776b0;

// FUNCTION: 0x004776b0
Obj_004776b0_shapeb02_game* Fn004776b0()
{
    PoolNode_shapeb02_game* pNode = gPool_004776b0.mpBlock->mpFree;
    if (!pNode) {
        pNode = gPool_004776b0.Refill();
    }
    gPool_004776b0.mpBlock->mpFree = pNode->mpNext;
    gPool_004776b0.mpBlock->mnUsed++;
    return reinterpret_cast<Obj_004776b0_shapeb02_game*>(pNode)->Ctor();
}

struct Pool_005e0820_shapeb02_game {
    uint32_t mnField00;
    PoolBlock_shapeb02_game* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_shapeb02_game* Refill();
};

struct Obj_005e0820_shapeb02_game {
    // STUB: 0x005e05b0
    Obj_005e0820_shapeb02_game* Ctor();
};

// GLOBAL: 0x00b0a86c
extern Pool_005e0820_shapeb02_game gPool_005e0820;

// FUNCTION: 0x005e0820
Obj_005e0820_shapeb02_game* Fn005e0820()
{
    PoolNode_shapeb02_game* pNode = gPool_005e0820.mpBlock->mpFree;
    if (!pNode) {
        pNode = gPool_005e0820.Refill();
    }
    gPool_005e0820.mpBlock->mpFree = pNode->mpNext;
    gPool_005e0820.mpBlock->mnUsed++;
    return reinterpret_cast<Obj_005e0820_shapeb02_game*>(pNode)->Ctor();
}

struct Pool_005e3330_shapeb02_game {
    uint32_t mnField00;
    PoolBlock_shapeb02_game* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_shapeb02_game* Refill();
};

struct Obj_005e3330_shapeb02_game {
    // STUB: 0x005e2f40
    Obj_005e3330_shapeb02_game* Ctor();
};

// GLOBAL: 0x00b0a8ac
extern Pool_005e3330_shapeb02_game gPool_005e3330;

// FUNCTION: 0x005e3330
Obj_005e3330_shapeb02_game* Fn005e3330()
{
    PoolNode_shapeb02_game* pNode = gPool_005e3330.mpBlock->mpFree;
    if (!pNode) {
        pNode = gPool_005e3330.Refill();
    }
    gPool_005e3330.mpBlock->mpFree = pNode->mpNext;
    gPool_005e3330.mpBlock->mnUsed++;
    return reinterpret_cast<Obj_005e3330_shapeb02_game*>(pNode)->Ctor();
}

struct Pool_005f84d0_shapeb02_game {
    uint32_t mnField00;
    PoolBlock_shapeb02_game* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_shapeb02_game* Refill();
};

struct Obj_005f84d0_shapeb02_game {
    // STUB: 0x005f8300
    Obj_005f84d0_shapeb02_game* Ctor();
};

// GLOBAL: 0x00b0a9b8
extern Pool_005f84d0_shapeb02_game gPool_005f84d0;

// FUNCTION: 0x005f84d0
Obj_005f84d0_shapeb02_game* Fn005f84d0()
{
    PoolNode_shapeb02_game* pNode = gPool_005f84d0.mpBlock->mpFree;
    if (!pNode) {
        pNode = gPool_005f84d0.Refill();
    }
    gPool_005f84d0.mpBlock->mpFree = pNode->mpNext;
    gPool_005f84d0.mpBlock->mnUsed++;
    return reinterpret_cast<Obj_005f84d0_shapeb02_game*>(pNode)->Ctor();
}

struct Pool_0064ab70_shapeb02_game {
    uint32_t mnField00;
    PoolBlock_shapeb02_game* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_shapeb02_game* Refill();
};

struct Obj_0064ab70_shapeb02_game {
    // STUB: 0x0064a270
    Obj_0064ab70_shapeb02_game* Ctor();
};

// GLOBAL: 0x00b0c258
extern Pool_0064ab70_shapeb02_game gPool_0064ab70;

// FUNCTION: 0x0064ab70
Obj_0064ab70_shapeb02_game* Fn0064ab70()
{
    PoolNode_shapeb02_game* pNode = gPool_0064ab70.mpBlock->mpFree;
    if (!pNode) {
        pNode = gPool_0064ab70.Refill();
    }
    gPool_0064ab70.mpBlock->mpFree = pNode->mpNext;
    gPool_0064ab70.mpBlock->mnUsed++;
    return reinterpret_cast<Obj_0064ab70_shapeb02_game*>(pNode)->Ctor();
}

struct Pool_006c2fc0_shapeb02_game {
    uint32_t mnField00;
    PoolBlock_shapeb02_game* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_shapeb02_game* Refill();
};

struct Obj_006c2fc0_shapeb02_game {
    // STUB: 0x006c2340
    Obj_006c2fc0_shapeb02_game* Ctor();
};

// GLOBAL: 0x00b0d3ac
extern Pool_006c2fc0_shapeb02_game gPool_006c2fc0;

// FUNCTION: 0x006c2fc0
Obj_006c2fc0_shapeb02_game* Fn006c2fc0()
{
    PoolNode_shapeb02_game* pNode = gPool_006c2fc0.mpBlock->mpFree;
    if (!pNode) {
        pNode = gPool_006c2fc0.Refill();
    }
    gPool_006c2fc0.mpBlock->mpFree = pNode->mpNext;
    gPool_006c2fc0.mpBlock->mnUsed++;
    return reinterpret_cast<Obj_006c2fc0_shapeb02_game*>(pNode)->Ctor();
}

struct Single_00460f80 {
    // STUB: 0x00460090
    Single_00460f80();
    uint8_t mPad[4];
};

// STUB: 0x00a7ae10
void Tcf_00460f80();
// GLOBAL: 0x00b21544
extern uint32_t gGuard_00460f80;
// GLOBAL: 0x00b214f8
extern Single_00460f80 gObject_00460f80;
// GLOBAL: 0x00b214f8
extern uint8_t gAddress_00460f80[4];

// FUNCTION: 0x00460f80
Single_00460f80* Fn00460f80()
{
    if (!(gGuard_00460f80 & 1)) {
        gGuard_00460f80 |= 1;
        new (&gObject_00460f80) Single_00460f80();
        atexit(Tcf_00460f80);
    }
    return reinterpret_cast<Single_00460f80*>(gAddress_00460f80);
}

struct Single_00466400 {
    // STUB: 0x004662b0
    Single_00466400();
    uint8_t mPad[4];
};

// STUB: 0x00a7ae20
void Tcf_00466400();
// GLOBAL: 0x00b21594
extern uint32_t gGuard_00466400;
// GLOBAL: 0x00b21548
extern Single_00466400 gObject_00466400;
// GLOBAL: 0x00b21548
extern uint8_t gAddress_00466400[4];

// FUNCTION: 0x00466400
Single_00466400* Fn00466400()
{
    if (!(gGuard_00466400 & 1)) {
        gGuard_00466400 |= 1;
        new (&gObject_00466400) Single_00466400();
        atexit(Tcf_00466400);
    }
    return reinterpret_cast<Single_00466400*>(gAddress_00466400);
}

struct Single_00466440 {
    // STUB: 0x00466250
    Single_00466440();
    uint8_t mPad[4];
};

// STUB: 0x00a7ae30
void Tcf_00466440();
// GLOBAL: 0x00b215e4
extern uint32_t gGuard_00466440;
// GLOBAL: 0x00b21598
extern Single_00466440 gObject_00466440;
// GLOBAL: 0x00b21598
extern uint8_t gAddress_00466440[4];

// FUNCTION: 0x00466440
Single_00466440* Fn00466440()
{
    if (!(gGuard_00466440 & 1)) {
        gGuard_00466440 |= 1;
        new (&gObject_00466440) Single_00466440();
        atexit(Tcf_00466440);
    }
    return reinterpret_cast<Single_00466440*>(gAddress_00466440);
}

struct Single_004ecd60 {
    // STUB: 0x004ec710
    Single_004ecd60();
    uint8_t mPad[4];
};

// STUB: 0x00a7b1d0
void Tcf_004ecd60();
// GLOBAL: 0x00b219e4
extern uint32_t gGuard_004ecd60;
// GLOBAL: 0x00b21978
extern Single_004ecd60 gObject_004ecd60;
// GLOBAL: 0x00b21978
extern uint8_t gAddress_004ecd60[4];

// FUNCTION: 0x004ecd60
Single_004ecd60* Fn004ecd60()
{
    if (!(gGuard_004ecd60 & 1)) {
        gGuard_004ecd60 |= 1;
        new (&gObject_004ecd60) Single_004ecd60();
        atexit(Tcf_004ecd60);
    }
    return reinterpret_cast<Single_004ecd60*>(gAddress_004ecd60);
}

struct Single_00514c30 {
    // STUB: 0x00514a00
    Single_00514c30();
    uint8_t mPad[4];
};

// STUB: 0x00a7b430
void Tcf_00514c30();
// GLOBAL: 0x00b227c4
extern uint32_t gGuard_00514c30;
// GLOBAL: 0x00b22778
extern Single_00514c30 gObject_00514c30;
// GLOBAL: 0x00b22778
extern uint8_t gAddress_00514c30[4];

// FUNCTION: 0x00514c30
Single_00514c30* Fn00514c30()
{
    if (!(gGuard_00514c30 & 1)) {
        gGuard_00514c30 |= 1;
        new (&gObject_00514c30) Single_00514c30();
        atexit(Tcf_00514c30);
    }
    return reinterpret_cast<Single_00514c30*>(gAddress_00514c30);
}

struct Single_00664b60 {
    // STUB: 0x00664920
    Single_00664b60();
    uint8_t mPad[4];
};

// STUB: 0x00a7c6d0
void Tcf_00664b60();
// GLOBAL: 0x00b468ec
extern uint32_t gGuard_00664b60;
// GLOBAL: 0x00b468a0
extern Single_00664b60 gObject_00664b60;
// GLOBAL: 0x00b468a0
extern uint8_t gAddress_00664b60[4];

// FUNCTION: 0x00664b60
Single_00664b60* Fn00664b60()
{
    if (!(gGuard_00664b60 & 1)) {
        gGuard_00664b60 |= 1;
        new (&gObject_00664b60) Single_00664b60();
        atexit(Tcf_00664b60);
    }
    return reinterpret_cast<Single_00664b60*>(gAddress_00664b60);
}

struct Single_00825c40 {
    // STUB: 0x00825b60
    Single_00825c40();
    uint8_t mPad[4];
};

// STUB: 0x00a7f2d0
void Tcf_00825c40();
// GLOBAL: 0x00b5088c
extern uint32_t gGuard_00825c40;
// GLOBAL: 0x00b50840
extern Single_00825c40 gObject_00825c40;
// GLOBAL: 0x00b50840
extern uint8_t gAddress_00825c40[4];

// FUNCTION: 0x00825c40
Single_00825c40* Fn00825c40()
{
    if (!(gGuard_00825c40 & 1)) {
        gGuard_00825c40 |= 1;
        new (&gObject_00825c40) Single_00825c40();
        atexit(Tcf_00825c40);
    }
    return reinterpret_cast<Single_00825c40*>(gAddress_00825c40);
}

struct Single_00880180 {
    // STUB: 0x008800f0
    Single_00880180();
    uint8_t mPad[4];
};

// STUB: 0x00a7f310
void Tcf_00880180();
// GLOBAL: 0x00b542e4
extern uint32_t gGuard_00880180;
// GLOBAL: 0x00b54298
extern Single_00880180 gObject_00880180;
// GLOBAL: 0x00b54298
extern uint8_t gAddress_00880180[4];

// FUNCTION: 0x00880180
Single_00880180* Fn00880180()
{
    if (!(gGuard_00880180 & 1)) {
        gGuard_00880180 |= 1;
        new (&gObject_00880180) Single_00880180();
        atexit(Tcf_00880180);
    }
    return reinterpret_cast<Single_00880180*>(gAddress_00880180);
}

struct Elem_00461120_shapeb02_game {
    uint32_t mnWord0;
    uint32_t mnWord1;
    uint32_t mnWord2;
};

struct View_00461120_shapeb02_game {
    Elem_00461120_shapeb02_game* mpBegin;
    Elem_00461120_shapeb02_game* mpEnd;
    // STUB: 0x00461190
    void Erase(Elem_00461120_shapeb02_game* pFirst, Elem_00461120_shapeb02_game* pLast);
    // STUB: 0x00461310
    void FillInsert(Elem_00461120_shapeb02_game* pPos, uint32_t nCount, const Elem_00461120_shapeb02_game& rValue);
    void Resize(uint32_t nNewSize, const Elem_00461120_shapeb02_game& rValue);
};

// FUNCTION: 0x00461120
void View_00461120_shapeb02_game::Resize(uint32_t nNewSize, const Elem_00461120_shapeb02_game& rValue)
{
    if (nNewSize < static_cast<uint32_t>(mpEnd - mpBegin)) {
        Erase(mpBegin + nNewSize, mpEnd);
    } else {
        FillInsert(mpEnd, nNewSize - (mpEnd - mpBegin), rValue);
    }
}

struct Elem_00461b20_shapeb02_game {
    uint32_t mnWord0;
    uint32_t mnWord1;
    uint32_t mnWord2;
};

struct View_00461b20_shapeb02_game {
    Elem_00461b20_shapeb02_game* mpBegin;
    Elem_00461b20_shapeb02_game* mpEnd;
    // STUB: 0x00461b90
    void Erase(Elem_00461b20_shapeb02_game* pFirst, Elem_00461b20_shapeb02_game* pLast);
    // STUB: 0x00461cf0
    void FillInsert(Elem_00461b20_shapeb02_game* pPos, uint32_t nCount, const Elem_00461b20_shapeb02_game& rValue);
    void Resize(uint32_t nNewSize, const Elem_00461b20_shapeb02_game& rValue);
};

// FUNCTION: 0x00461b20
void View_00461b20_shapeb02_game::Resize(uint32_t nNewSize, const Elem_00461b20_shapeb02_game& rValue)
{
    if (nNewSize < static_cast<uint32_t>(mpEnd - mpBegin)) {
        Erase(mpBegin + nNewSize, mpEnd);
    } else {
        FillInsert(mpEnd, nNewSize - (mpEnd - mpBegin), rValue);
    }
}

struct Elem_004623f0_shapeb02_game {
    uint32_t mnWord0;
    uint32_t mnWord1;
    uint32_t mnWord2;
};

struct View_004623f0_shapeb02_game {
    Elem_004623f0_shapeb02_game* mpBegin;
    Elem_004623f0_shapeb02_game* mpEnd;
    // STUB: 0x00465990
    void Erase(Elem_004623f0_shapeb02_game* pFirst, Elem_004623f0_shapeb02_game* pLast);
    // STUB: 0x00462460
    void FillInsert(Elem_004623f0_shapeb02_game* pPos, uint32_t nCount, const Elem_004623f0_shapeb02_game& rValue);
    void Resize(uint32_t nNewSize, const Elem_004623f0_shapeb02_game& rValue);
};

// FUNCTION: 0x004623f0
void View_004623f0_shapeb02_game::Resize(uint32_t nNewSize, const Elem_004623f0_shapeb02_game& rValue)
{
    if (nNewSize < static_cast<uint32_t>(mpEnd - mpBegin)) {
        Erase(mpBegin + nNewSize, mpEnd);
    } else {
        FillInsert(mpEnd, nNewSize - (mpEnd - mpBegin), rValue);
    }
}

struct Elem_00462b20_shapeb02_game {
    uint32_t mnWord0;
    uint32_t mnWord1;
    uint32_t mnWord2;
};

struct View_00462b20_shapeb02_game {
    Elem_00462b20_shapeb02_game* mpBegin;
    Elem_00462b20_shapeb02_game* mpEnd;
    // STUB: 0x00462b90
    void Erase(Elem_00462b20_shapeb02_game* pFirst, Elem_00462b20_shapeb02_game* pLast);
    // STUB: 0x00462d40
    void FillInsert(Elem_00462b20_shapeb02_game* pPos, uint32_t nCount, const Elem_00462b20_shapeb02_game& rValue);
    void Resize(uint32_t nNewSize, const Elem_00462b20_shapeb02_game& rValue);
};

// FUNCTION: 0x00462b20
void View_00462b20_shapeb02_game::Resize(uint32_t nNewSize, const Elem_00462b20_shapeb02_game& rValue)
{
    if (nNewSize < static_cast<uint32_t>(mpEnd - mpBegin)) {
        Erase(mpBegin + nNewSize, mpEnd);
    } else {
        FillInsert(mpEnd, nNewSize - (mpEnd - mpBegin), rValue);
    }
}

struct Elem_00463c00_shapeb02_game {
    uint32_t mnWord0;
    uint32_t mnWord1;
    uint32_t mnWord2;
};

struct View_00463c00_shapeb02_game {
    Elem_00463c00_shapeb02_game* mpBegin;
    Elem_00463c00_shapeb02_game* mpEnd;
    // STUB: 0x00463c70
    void Erase(Elem_00463c00_shapeb02_game* pFirst, Elem_00463c00_shapeb02_game* pLast);
    // STUB: 0x00463580
    void FillInsert(Elem_00463c00_shapeb02_game* pPos, uint32_t nCount, const Elem_00463c00_shapeb02_game& rValue);
    void Resize(uint32_t nNewSize, const Elem_00463c00_shapeb02_game& rValue);
};

// FUNCTION: 0x00463c00
void View_00463c00_shapeb02_game::Resize(uint32_t nNewSize, const Elem_00463c00_shapeb02_game& rValue)
{
    if (nNewSize < static_cast<uint32_t>(mpEnd - mpBegin)) {
        Erase(mpBegin + nNewSize, mpEnd);
    } else {
        FillInsert(mpEnd, nNewSize - (mpEnd - mpBegin), rValue);
    }
}

struct Elem_00464340_shapeb02_game {
    uint32_t mnWord0;
    uint32_t mnWord1;
    uint32_t mnWord2;
};

struct View_00464340_shapeb02_game {
    Elem_00464340_shapeb02_game* mpBegin;
    Elem_00464340_shapeb02_game* mpEnd;
    // STUB: 0x004643b0
    void Erase(Elem_00464340_shapeb02_game* pFirst, Elem_00464340_shapeb02_game* pLast);
    // STUB: 0x004645a0
    void FillInsert(Elem_00464340_shapeb02_game* pPos, uint32_t nCount, const Elem_00464340_shapeb02_game& rValue);
    void Resize(uint32_t nNewSize, const Elem_00464340_shapeb02_game& rValue);
};

// FUNCTION: 0x00464340
void View_00464340_shapeb02_game::Resize(uint32_t nNewSize, const Elem_00464340_shapeb02_game& rValue)
{
    if (nNewSize < static_cast<uint32_t>(mpEnd - mpBegin)) {
        Erase(mpBegin + nNewSize, mpEnd);
    } else {
        FillInsert(mpEnd, nNewSize - (mpEnd - mpBegin), rValue);
    }
}

struct Elem_00464ed0_shapeb02_game {
    uint32_t mnWord0;
    uint32_t mnWord1;
    uint32_t mnWord2;
};

struct View_00464ed0_shapeb02_game {
    Elem_00464ed0_shapeb02_game* mpBegin;
    Elem_00464ed0_shapeb02_game* mpEnd;
    // STUB: 0x00464f40
    void Erase(Elem_00464ed0_shapeb02_game* pFirst, Elem_00464ed0_shapeb02_game* pLast);
    // STUB: 0x00465130
    void FillInsert(Elem_00464ed0_shapeb02_game* pPos, uint32_t nCount, const Elem_00464ed0_shapeb02_game& rValue);
    void Resize(uint32_t nNewSize, const Elem_00464ed0_shapeb02_game& rValue);
};

// FUNCTION: 0x00464ed0
void View_00464ed0_shapeb02_game::Resize(uint32_t nNewSize, const Elem_00464ed0_shapeb02_game& rValue)
{
    if (nNewSize < static_cast<uint32_t>(mpEnd - mpBegin)) {
        Erase(mpBegin + nNewSize, mpEnd);
    } else {
        FillInsert(mpEnd, nNewSize - (mpEnd - mpBegin), rValue);
    }
}

struct Elem_0064d990_shapeb02_game {
    uint32_t mnWord0;
    uint32_t mnWord1;
    uint32_t mnWord2;
};

struct View_0064d990_shapeb02_game {
    Elem_0064d990_shapeb02_game* mpBegin;
    Elem_0064d990_shapeb02_game* mpEnd;
    // STUB: 0x0064cf40
    void Erase(Elem_0064d990_shapeb02_game* pFirst, Elem_0064d990_shapeb02_game* pLast);
    // STUB: 0x0064d130
    void FillInsert(Elem_0064d990_shapeb02_game* pPos, uint32_t nCount, const Elem_0064d990_shapeb02_game& rValue);
    void Resize(uint32_t nNewSize, const Elem_0064d990_shapeb02_game& rValue);
};

// FUNCTION: 0x0064d990
void View_0064d990_shapeb02_game::Resize(uint32_t nNewSize, const Elem_0064d990_shapeb02_game& rValue)
{
    if (nNewSize < static_cast<uint32_t>(mpEnd - mpBegin)) {
        Erase(mpBegin + nNewSize, mpEnd);
    } else {
        FillInsert(mpEnd, nNewSize - (mpEnd - mpBegin), rValue);
    }
}

struct First_004664b0_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

struct Second_004664b0_shapeb02_game {
    virtual void SecondSlot() {}
};

struct Third_004664b0_shapeb02_game {
    virtual void ThirdSlot() {}
};

struct View_004664b0_shapeb02_game : First_004664b0_shapeb02_game, Second_004664b0_shapeb02_game, Third_004664b0_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
};

// FUNCTION: 0x004664b0
bool View_004664b0_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 0x1:
    case 0x26dde2ea:
        *ppvObj = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppvObj = static_cast<Second_004664b0_shapeb02_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppvObj = static_cast<Third_004664b0_shapeb02_game*>(this);
        AddRef();
        return true;
    default:
        return false;
    }
}

struct First_004a1d30_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

struct Second_004a1d30_shapeb02_game {
    virtual void SecondSlot() {}
};

struct Third_004a1d30_shapeb02_game {
    virtual void ThirdSlot() {}
};

struct View_004a1d30_shapeb02_game : First_004a1d30_shapeb02_game, Second_004a1d30_shapeb02_game, Third_004a1d30_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
};

// FUNCTION: 0x004a1d30
bool View_004a1d30_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 0x28326f3e:
        *ppvObj = this;
        AddRef();
        return true;
    case 0x1:
    case 0x452294aa:
        *ppvObj = static_cast<Second_004a1d30_shapeb02_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppvObj = static_cast<Third_004a1d30_shapeb02_game*>(this);
        AddRef();
        return true;
    default:
        return false;
    }
}

struct First_004f0270_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

struct Second_004f0270_shapeb02_game {
    virtual void SecondSlot() {}
    uint32_t pad[3];
};

struct Third_004f0270_shapeb02_game {
    virtual void ThirdSlot() {}
};

struct View_004f0270_shapeb02_game : First_004f0270_shapeb02_game, Second_004f0270_shapeb02_game, Third_004f0270_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
};

// FUNCTION: 0x004f0270
bool View_004f0270_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 0x452294aa:
        *ppvObj = this;
        AddRef();
        return true;
    case 0x1:
    case 0x89e51472:
        *ppvObj = static_cast<Second_004f0270_shapeb02_game*>(this);
        AddRef();
        return true;
    case 0xbb523bb2:
        *ppvObj = static_cast<Third_004f0270_shapeb02_game*>(this);
        AddRef();
        return true;
    default:
        return false;
    }
}

struct First_0069ea50_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

struct Second_0069ea50_shapeb02_game {
    virtual void SecondSlot() {}
};

struct Third_0069ea50_shapeb02_game {
    virtual void ThirdSlot() {}
};

struct View_0069ea50_shapeb02_game : First_0069ea50_shapeb02_game, Second_0069ea50_shapeb02_game, Third_0069ea50_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
};

// FUNCTION: 0x0069ea50
bool View_0069ea50_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 0x1:
    case 0x77abeb2:
        *ppvObj = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppvObj = static_cast<Second_0069ea50_shapeb02_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppvObj = static_cast<Third_0069ea50_shapeb02_game*>(this);
        AddRef();
        return true;
    default:
        return false;
    }
}

struct First_006afc90_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

struct Second_006afc90_shapeb02_game {
    virtual void SecondSlot() {}
};

struct Third_006afc90_shapeb02_game {
    virtual void ThirdSlot() {}
};

struct View_006afc90_shapeb02_game : First_006afc90_shapeb02_game, Second_006afc90_shapeb02_game, Third_006afc90_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
};

// FUNCTION: 0x006afc90
bool View_006afc90_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 0x1:
    case 0x6c66177:
        *ppvObj = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppvObj = static_cast<Second_006afc90_shapeb02_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppvObj = static_cast<Third_006afc90_shapeb02_game*>(this);
        AddRef();
        return true;
    default:
        return false;
    }
}

struct First_006cdf00_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

struct Second_006cdf00_shapeb02_game {
    virtual void SecondSlot() {}
};

struct Third_006cdf00_shapeb02_game {
    virtual void ThirdSlot() {}
};

struct View_006cdf00_shapeb02_game : First_006cdf00_shapeb02_game, Second_006cdf00_shapeb02_game, Third_006cdf00_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
};

// FUNCTION: 0x006cdf00
bool View_006cdf00_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 0x1:
    case 0x773fef0:
        *ppvObj = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppvObj = static_cast<Second_006cdf00_shapeb02_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppvObj = static_cast<Third_006cdf00_shapeb02_game*>(this);
        AddRef();
        return true;
    default:
        return false;
    }
}

struct First_006f6e60_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

struct Second_006f6e60_shapeb02_game {
    virtual void SecondSlot() {}
};

struct Third_006f6e60_shapeb02_game {
    virtual void ThirdSlot() {}
};

struct View_006f6e60_shapeb02_game : First_006f6e60_shapeb02_game, Second_006f6e60_shapeb02_game, Third_006f6e60_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
};

// FUNCTION: 0x006f6e60
bool View_006f6e60_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 0x1:
    case 0x77ac1ee:
        *ppvObj = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppvObj = static_cast<Second_006f6e60_shapeb02_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppvObj = static_cast<Third_006f6e60_shapeb02_game*>(this);
        AddRef();
        return true;
    default:
        return false;
    }
}

struct First_0080d340_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

struct Second_0080d340_shapeb02_game {
    virtual void SecondSlot() {}
};

struct Third_0080d340_shapeb02_game {
    virtual void ThirdSlot() {}
};

struct View_0080d340_shapeb02_game : First_0080d340_shapeb02_game, Second_0080d340_shapeb02_game, Third_0080d340_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
};

// FUNCTION: 0x0080d340
bool View_0080d340_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 0x1:
    case 0x41193c3a:
        *ppvObj = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppvObj = static_cast<Second_0080d340_shapeb02_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppvObj = static_cast<Third_0080d340_shapeb02_game*>(this);
        AddRef();
        return true;
    default:
        return false;
    }
}

struct View_0046f740_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x0046f740
bool View_0046f740_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0xb562673:
        *ppvObj = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct View_004777b0_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x004777b0
bool View_004777b0_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0x68edbebc:
        *ppvObj = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct View_00489670_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x00489670
bool View_00489670_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0x68f0113a:
        *ppvObj = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct View_004e8350_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x004e8350
bool View_004e8350_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0x46a80026:
        *ppvObj = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct View_004f1f30_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x004f1f30
bool View_004f1f30_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0x22e85d8e:
        *ppvObj = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct View_005dc8a0_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x005dc8a0
bool View_005dc8a0_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0x452294aa:
        *ppvObj = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct View_008016d0_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x008016d0
bool View_008016d0_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0x26a68448:
        *ppvObj = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct View_00811570_shapeb02_game {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x00811570
bool View_00811570_shapeb02_game::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0x3afd825f:
        *ppvObj = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

// STUB: 0x0090cf63
void Fn0090cf63_004b6250(void* p);

struct Node_004b6250_shapeb02_game {
    uint8_t pad0[8];
    Node_004b6250_shapeb02_game* mpNext;
    Node_004b6250_shapeb02_game* mpChild;
    uint8_t pad10[4];
    cRZString mKey;
};

struct View_004b6250_shapeb02_game {
    void Erase(Node_004b6250_shapeb02_game* pNode);
};

// FUNCTION: 0x004b6250
void View_004b6250_shapeb02_game::Erase(Node_004b6250_shapeb02_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Node_004b6250_shapeb02_game* pNext = pNode->mpNext;
        pNode->mKey.cRZString::~cRZString();
        Fn0090cf63_004b6250(pNode);
        pNode = pNext;
    }
}

// STUB: 0x0090cf63
void Fn0090cf63_004cb8b0(void* p);

struct Node_004cb8b0_shapeb02_game {
    uint8_t pad0[8];
    Node_004cb8b0_shapeb02_game* mpNext;
    Node_004cb8b0_shapeb02_game* mpChild;
    uint8_t pad10[4];
    cRZString mKey;
};

struct View_004cb8b0_shapeb02_game {
    void Erase(Node_004cb8b0_shapeb02_game* pNode);
};

// FUNCTION: 0x004cb8b0
void View_004cb8b0_shapeb02_game::Erase(Node_004cb8b0_shapeb02_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Node_004cb8b0_shapeb02_game* pNext = pNode->mpNext;
        pNode->mKey.cRZString::~cRZString();
        Fn0090cf63_004cb8b0(pNode);
        pNode = pNext;
    }
}

// STUB: 0x0090cf63
void Fn0090cf63_005d82e0(void* p);

struct Node_005d82e0_shapeb02_game {
    uint8_t pad0[8];
    Node_005d82e0_shapeb02_game* mpNext;
    Node_005d82e0_shapeb02_game* mpChild;
    
    cRZString mKey;
};

struct View_005d82e0_shapeb02_game {
    void Erase(Node_005d82e0_shapeb02_game* pNode);
};

// FUNCTION: 0x005d82e0
void View_005d82e0_shapeb02_game::Erase(Node_005d82e0_shapeb02_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Node_005d82e0_shapeb02_game* pNext = pNode->mpNext;
        pNode->mKey.cRZString::~cRZString();
        Fn0090cf63_005d82e0(pNode);
        pNode = pNext;
    }
}

// STUB: 0x0090cf63
void Fn0090cf63_00600580(void* p);

struct Node_00600580_shapeb02_game {
    uint8_t pad0[8];
    Node_00600580_shapeb02_game* mpNext;
    Node_00600580_shapeb02_game* mpChild;
    
    cRZString mKey;
};

struct View_00600580_shapeb02_game {
    void Erase(Node_00600580_shapeb02_game* pNode);
};

// FUNCTION: 0x00600580
void View_00600580_shapeb02_game::Erase(Node_00600580_shapeb02_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Node_00600580_shapeb02_game* pNext = pNode->mpNext;
        pNode->mKey.cRZString::~cRZString();
        Fn0090cf63_00600580(pNode);
        pNode = pNext;
    }
}

// STUB: 0x0090cf63
void Fn0090cf63_00662a60(void* p);

struct Node_00662a60_shapeb02_game {
    uint8_t pad0[8];
    Node_00662a60_shapeb02_game* mpNext;
    Node_00662a60_shapeb02_game* mpChild;
    
    cRZString mKey;
};

struct View_00662a60_shapeb02_game {
    void Erase(Node_00662a60_shapeb02_game* pNode);
};

// FUNCTION: 0x00662a60
void View_00662a60_shapeb02_game::Erase(Node_00662a60_shapeb02_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Node_00662a60_shapeb02_game* pNext = pNode->mpNext;
        pNode->mKey.cRZString::~cRZString();
        Fn0090cf63_00662a60(pNode);
        pNode = pNext;
    }
}

// STUB: 0x0090cf63
void Fn0090cf63_0066f6a0(void* p);

struct Node_0066f6a0_shapeb02_game {
    uint8_t pad0[8];
    Node_0066f6a0_shapeb02_game* mpNext;
    Node_0066f6a0_shapeb02_game* mpChild;
    uint8_t pad10[4];
    cRZString mKey;
};

struct View_0066f6a0_shapeb02_game {
    void Erase(Node_0066f6a0_shapeb02_game* pNode);
};

// FUNCTION: 0x0066f6a0
void View_0066f6a0_shapeb02_game::Erase(Node_0066f6a0_shapeb02_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Node_0066f6a0_shapeb02_game* pNext = pNode->mpNext;
        pNode->mKey.cRZString::~cRZString();
        Fn0090cf63_0066f6a0(pNode);
        pNode = pNext;
    }
}

// STUB: 0x0090cf63
void Fn0090cf63_0066f6f0(void* p);

struct Node_0066f6f0_shapeb02_game {
    uint8_t pad0[8];
    Node_0066f6f0_shapeb02_game* mpNext;
    Node_0066f6f0_shapeb02_game* mpChild;
    uint8_t pad10[4];
    cRZString mKey;
};

struct View_0066f6f0_shapeb02_game {
    void Erase(Node_0066f6f0_shapeb02_game* pNode);
};

// FUNCTION: 0x0066f6f0
void View_0066f6f0_shapeb02_game::Erase(Node_0066f6f0_shapeb02_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Node_0066f6f0_shapeb02_game* pNext = pNode->mpNext;
        pNode->mKey.cRZString::~cRZString();
        Fn0090cf63_0066f6f0(pNode);
        pNode = pNext;
    }
}

// STUB: 0x0090cf63
void Fn0090cf63_0081d960(void* p);

struct Node_0081d960_shapeb02_game {
    uint8_t pad0[8];
    Node_0081d960_shapeb02_game* mpNext;
    Node_0081d960_shapeb02_game* mpChild;
    
    cRZString mKey;
};

struct View_0081d960_shapeb02_game {
    void Erase(Node_0081d960_shapeb02_game* pNode);
};

// FUNCTION: 0x0081d960
void View_0081d960_shapeb02_game::Erase(Node_0081d960_shapeb02_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Node_0081d960_shapeb02_game* pNext = pNode->mpNext;
        pNode->mKey.cRZString::~cRZString();
        Fn0090cf63_0081d960(pNode);
        pNode = pNext;
    }
}

struct TNode_004b70f0_shapeb02_game {
    uint32_t mnColor;
    TNode_004b70f0_shapeb02_game* mpParent;
    TNode_004b70f0_shapeb02_game* mpLeft;
    TNode_004b70f0_shapeb02_game* mpRight;
    cRZString mKey;
};

struct TIter_004b70f0_shapeb02_game {
    TNode_004b70f0_shapeb02_game* mpNode;
    TIter_004b70f0_shapeb02_game(TNode_004b70f0_shapeb02_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_004b70f0_shapeb02_game {
    TNode_004b70f0_shapeb02_game* mpNode;
    bool mbInserted;
    TRes_004b70f0_shapeb02_game(TNode_004b70f0_shapeb02_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

// STUB: 0x004b5ca0
bool Fn004b5ca0_004b70f0(const std::string& rLeft, const std::string& rRight);

struct View_004b70f0_shapeb02_game {
    TNode_004b70f0_shapeb02_game* mpHead;
    // STUB: 0x004b7030
    TIter_004b70f0_shapeb02_game Insert(TNode_004b70f0_shapeb02_game* pX, TNode_004b70f0_shapeb02_game* pY, const cRZString* pValue, uint32_t nFlag);
    TRes_004b70f0_shapeb02_game InsertUnique(const cRZString* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004b70f0 score 19
TRes_004b70f0_shapeb02_game View_004b70f0_shapeb02_game::InsertUnique(const cRZString* pValue)
{
    TNode_004b70f0_shapeb02_game* pHead = mpHead;
    TNode_004b70f0_shapeb02_game* pX = pHead->mpParent;
    TNode_004b70f0_shapeb02_game* pY = pHead;
    bool bLess = true;
    while (pX) {
        pY = pX;
        cRZString* pNodeKey = &pX->mKey;
        const std::string* pNodeStr = pNodeKey;
        const std::string* pValueStr = pValue;
        bLess = pValueStr->compare(*pNodeStr) < 0;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_004b70f0_shapeb02_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_004b70f0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    const std::string* pValueStr2 = pValue;
    cRZString* pItKey = &it.mpNode->mKey;
    const std::string* pItStr = pItKey;
    if (Fn004b5ca0_004b70f0(*pItStr, *pValueStr2)) {
        return TRes_004b70f0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_004b70f0_shapeb02_game(it.mpNode, false);
}
#endif

struct TNode_004df900_shapeb02_game {
    uint32_t mnColor;
    TNode_004df900_shapeb02_game* mpParent;
    TNode_004df900_shapeb02_game* mpLeft;
    TNode_004df900_shapeb02_game* mpRight;
    cRZString mKey;
};

struct TIter_004df900_shapeb02_game {
    TNode_004df900_shapeb02_game* mpNode;
    TIter_004df900_shapeb02_game(TNode_004df900_shapeb02_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_004df900_shapeb02_game {
    TNode_004df900_shapeb02_game* mpNode;
    bool mbInserted;
    TRes_004df900_shapeb02_game(TNode_004df900_shapeb02_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

// STUB: 0x004b5ca0
bool Fn004b5ca0_004df900(const std::string& rLeft, const std::string& rRight);

struct View_004df900_shapeb02_game {
    TNode_004df900_shapeb02_game* mpHead;
    // STUB: 0x004dec40
    TIter_004df900_shapeb02_game Insert(TNode_004df900_shapeb02_game* pX, TNode_004df900_shapeb02_game* pY, const cRZString* pValue, uint32_t nFlag);
    TRes_004df900_shapeb02_game InsertUnique(const cRZString* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004df900 score 19
TRes_004df900_shapeb02_game View_004df900_shapeb02_game::InsertUnique(const cRZString* pValue)
{
    TNode_004df900_shapeb02_game* pHead = mpHead;
    TNode_004df900_shapeb02_game* pX = pHead->mpParent;
    TNode_004df900_shapeb02_game* pY = pHead;
    bool bLess = true;
    while (pX) {
        pY = pX;
        cRZString* pNodeKey = &pX->mKey;
        const std::string* pNodeStr = pNodeKey;
        const std::string* pValueStr = pValue;
        bLess = pValueStr->compare(*pNodeStr) < 0;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_004df900_shapeb02_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_004df900_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    const std::string* pValueStr2 = pValue;
    cRZString* pItKey = &it.mpNode->mKey;
    const std::string* pItStr = pItKey;
    if (Fn004b5ca0_004df900(*pItStr, *pValueStr2)) {
        return TRes_004df900_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_004df900_shapeb02_game(it.mpNode, false);
}
#endif

struct TNode_005e86d0_shapeb02_game {
    uint32_t mnColor;
    TNode_005e86d0_shapeb02_game* mpParent;
    TNode_005e86d0_shapeb02_game* mpLeft;
    TNode_005e86d0_shapeb02_game* mpRight;
    cRZString mKey;
};

struct TIter_005e86d0_shapeb02_game {
    TNode_005e86d0_shapeb02_game* mpNode;
    TIter_005e86d0_shapeb02_game(TNode_005e86d0_shapeb02_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_005e86d0_shapeb02_game {
    TNode_005e86d0_shapeb02_game* mpNode;
    bool mbInserted;
    TRes_005e86d0_shapeb02_game(TNode_005e86d0_shapeb02_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

// STUB: 0x004b5ca0
bool Fn004b5ca0_005e86d0(const std::string& rLeft, const std::string& rRight);

struct View_005e86d0_shapeb02_game {
    TNode_005e86d0_shapeb02_game* mpHead;
    // STUB: 0x005e85b0
    TIter_005e86d0_shapeb02_game Insert(TNode_005e86d0_shapeb02_game* pX, TNode_005e86d0_shapeb02_game* pY, const cRZString* pValue, uint32_t nFlag);
    TRes_005e86d0_shapeb02_game InsertUnique(const cRZString* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005e86d0 score 19
TRes_005e86d0_shapeb02_game View_005e86d0_shapeb02_game::InsertUnique(const cRZString* pValue)
{
    TNode_005e86d0_shapeb02_game* pHead = mpHead;
    TNode_005e86d0_shapeb02_game* pX = pHead->mpParent;
    TNode_005e86d0_shapeb02_game* pY = pHead;
    bool bLess = true;
    while (pX) {
        pY = pX;
        cRZString* pNodeKey = &pX->mKey;
        const std::string* pNodeStr = pNodeKey;
        const std::string* pValueStr = pValue;
        bLess = pValueStr->compare(*pNodeStr) < 0;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_005e86d0_shapeb02_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_005e86d0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    const std::string* pValueStr2 = pValue;
    cRZString* pItKey = &it.mpNode->mKey;
    const std::string* pItStr = pItKey;
    if (Fn004b5ca0_005e86d0(*pItStr, *pValueStr2)) {
        return TRes_005e86d0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_005e86d0_shapeb02_game(it.mpNode, false);
}
#endif

struct TNode_00662ef0_shapeb02_game {
    uint32_t mnColor;
    TNode_00662ef0_shapeb02_game* mpParent;
    TNode_00662ef0_shapeb02_game* mpLeft;
    TNode_00662ef0_shapeb02_game* mpRight;
    cRZString mKey;
};

struct TIter_00662ef0_shapeb02_game {
    TNode_00662ef0_shapeb02_game* mpNode;
    TIter_00662ef0_shapeb02_game(TNode_00662ef0_shapeb02_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_00662ef0_shapeb02_game {
    TNode_00662ef0_shapeb02_game* mpNode;
    bool mbInserted;
    TRes_00662ef0_shapeb02_game(TNode_00662ef0_shapeb02_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

// STUB: 0x004b5ca0
bool Fn004b5ca0_00662ef0(const std::string& rLeft, const std::string& rRight);

struct View_00662ef0_shapeb02_game {
    TNode_00662ef0_shapeb02_game* mpHead;
    // STUB: 0x00662e40
    TIter_00662ef0_shapeb02_game Insert(TNode_00662ef0_shapeb02_game* pX, TNode_00662ef0_shapeb02_game* pY, const cRZString* pValue, uint32_t nFlag);
    TRes_00662ef0_shapeb02_game InsertUnique(const cRZString* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00662ef0 score 19
TRes_00662ef0_shapeb02_game View_00662ef0_shapeb02_game::InsertUnique(const cRZString* pValue)
{
    TNode_00662ef0_shapeb02_game* pHead = mpHead;
    TNode_00662ef0_shapeb02_game* pX = pHead->mpParent;
    TNode_00662ef0_shapeb02_game* pY = pHead;
    bool bLess = true;
    while (pX) {
        pY = pX;
        cRZString* pNodeKey = &pX->mKey;
        const std::string* pNodeStr = pNodeKey;
        const std::string* pValueStr = pValue;
        bLess = pValueStr->compare(*pNodeStr) < 0;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_00662ef0_shapeb02_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_00662ef0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    const std::string* pValueStr2 = pValue;
    cRZString* pItKey = &it.mpNode->mKey;
    const std::string* pItStr = pItKey;
    if (Fn004b5ca0_00662ef0(*pItStr, *pValueStr2)) {
        return TRes_00662ef0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_00662ef0_shapeb02_game(it.mpNode, false);
}
#endif

struct TNode_006815c0_shapeb02_game {
    uint32_t mnColor;
    TNode_006815c0_shapeb02_game* mpParent;
    TNode_006815c0_shapeb02_game* mpLeft;
    TNode_006815c0_shapeb02_game* mpRight;
    cRZString mKey;
};

struct TIter_006815c0_shapeb02_game {
    TNode_006815c0_shapeb02_game* mpNode;
    TIter_006815c0_shapeb02_game(TNode_006815c0_shapeb02_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_006815c0_shapeb02_game {
    TNode_006815c0_shapeb02_game* mpNode;
    bool mbInserted;
    TRes_006815c0_shapeb02_game(TNode_006815c0_shapeb02_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

// STUB: 0x004b5ca0
bool Fn004b5ca0_006815c0(const std::string& rLeft, const std::string& rRight);

struct View_006815c0_shapeb02_game {
    TNode_006815c0_shapeb02_game* mpHead;
    // STUB: 0x00681500
    TIter_006815c0_shapeb02_game Insert(TNode_006815c0_shapeb02_game* pX, TNode_006815c0_shapeb02_game* pY, const cRZString* pValue, uint32_t nFlag);
    TRes_006815c0_shapeb02_game InsertUnique(const cRZString* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006815c0 score 19
TRes_006815c0_shapeb02_game View_006815c0_shapeb02_game::InsertUnique(const cRZString* pValue)
{
    TNode_006815c0_shapeb02_game* pHead = mpHead;
    TNode_006815c0_shapeb02_game* pX = pHead->mpParent;
    TNode_006815c0_shapeb02_game* pY = pHead;
    bool bLess = true;
    while (pX) {
        pY = pX;
        cRZString* pNodeKey = &pX->mKey;
        const std::string* pNodeStr = pNodeKey;
        const std::string* pValueStr = pValue;
        bLess = pValueStr->compare(*pNodeStr) < 0;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_006815c0_shapeb02_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_006815c0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    const std::string* pValueStr2 = pValue;
    cRZString* pItKey = &it.mpNode->mKey;
    const std::string* pItStr = pItKey;
    if (Fn004b5ca0_006815c0(*pItStr, *pValueStr2)) {
        return TRes_006815c0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_006815c0_shapeb02_game(it.mpNode, false);
}
#endif

struct TNode_008059f0_shapeb02_game {
    uint32_t mnColor;
    TNode_008059f0_shapeb02_game* mpParent;
    TNode_008059f0_shapeb02_game* mpLeft;
    TNode_008059f0_shapeb02_game* mpRight;
    cRZString mKey;
};

struct TIter_008059f0_shapeb02_game {
    TNode_008059f0_shapeb02_game* mpNode;
    TIter_008059f0_shapeb02_game(TNode_008059f0_shapeb02_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_008059f0_shapeb02_game {
    TNode_008059f0_shapeb02_game* mpNode;
    bool mbInserted;
    TRes_008059f0_shapeb02_game(TNode_008059f0_shapeb02_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

// STUB: 0x004b5ca0
bool Fn004b5ca0_008059f0(const std::string& rLeft, const std::string& rRight);

struct View_008059f0_shapeb02_game {
    TNode_008059f0_shapeb02_game* mpHead;
    // STUB: 0x008057a0
    TIter_008059f0_shapeb02_game Insert(TNode_008059f0_shapeb02_game* pX, TNode_008059f0_shapeb02_game* pY, const cRZString* pValue, uint32_t nFlag);
    TRes_008059f0_shapeb02_game InsertUnique(const cRZString* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008059f0 score 19
TRes_008059f0_shapeb02_game View_008059f0_shapeb02_game::InsertUnique(const cRZString* pValue)
{
    TNode_008059f0_shapeb02_game* pHead = mpHead;
    TNode_008059f0_shapeb02_game* pX = pHead->mpParent;
    TNode_008059f0_shapeb02_game* pY = pHead;
    bool bLess = true;
    while (pX) {
        pY = pX;
        cRZString* pNodeKey = &pX->mKey;
        const std::string* pNodeStr = pNodeKey;
        const std::string* pValueStr = pValue;
        bLess = pValueStr->compare(*pNodeStr) < 0;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_008059f0_shapeb02_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_008059f0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    const std::string* pValueStr2 = pValue;
    cRZString* pItKey = &it.mpNode->mKey;
    const std::string* pItStr = pItKey;
    if (Fn004b5ca0_008059f0(*pItStr, *pValueStr2)) {
        return TRes_008059f0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_008059f0_shapeb02_game(it.mpNode, false);
}
#endif

struct TNode_0081d300_shapeb02_game {
    uint32_t mnColor;
    TNode_0081d300_shapeb02_game* mpParent;
    TNode_0081d300_shapeb02_game* mpLeft;
    TNode_0081d300_shapeb02_game* mpRight;
    cRZString mKey;
};

struct TIter_0081d300_shapeb02_game {
    TNode_0081d300_shapeb02_game* mpNode;
    TIter_0081d300_shapeb02_game(TNode_0081d300_shapeb02_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_0081d300_shapeb02_game {
    TNode_0081d300_shapeb02_game* mpNode;
    bool mbInserted;
    TRes_0081d300_shapeb02_game(TNode_0081d300_shapeb02_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

// STUB: 0x004b5ca0
bool Fn004b5ca0_0081d300(const std::string& rLeft, const std::string& rRight);

struct View_0081d300_shapeb02_game {
    TNode_0081d300_shapeb02_game* mpHead;
    // STUB: 0x0081d240
    TIter_0081d300_shapeb02_game Insert(TNode_0081d300_shapeb02_game* pX, TNode_0081d300_shapeb02_game* pY, const cRZString* pValue, uint32_t nFlag);
    TRes_0081d300_shapeb02_game InsertUnique(const cRZString* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0081d300 score 19
TRes_0081d300_shapeb02_game View_0081d300_shapeb02_game::InsertUnique(const cRZString* pValue)
{
    TNode_0081d300_shapeb02_game* pHead = mpHead;
    TNode_0081d300_shapeb02_game* pX = pHead->mpParent;
    TNode_0081d300_shapeb02_game* pY = pHead;
    bool bLess = true;
    while (pX) {
        pY = pX;
        cRZString* pNodeKey = &pX->mKey;
        const std::string* pNodeStr = pNodeKey;
        const std::string* pValueStr = pValue;
        bLess = pValueStr->compare(*pNodeStr) < 0;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_0081d300_shapeb02_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_0081d300_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    const std::string* pValueStr2 = pValue;
    cRZString* pItKey = &it.mpNode->mKey;
    const std::string* pItStr = pItKey;
    if (Fn004b5ca0_0081d300(*pItStr, *pValueStr2)) {
        return TRes_0081d300_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_0081d300_shapeb02_game(it.mpNode, false);
}
#endif

struct TNode_0081dee0_shapeb02_game {
    uint32_t mnColor;
    TNode_0081dee0_shapeb02_game* mpParent;
    TNode_0081dee0_shapeb02_game* mpLeft;
    TNode_0081dee0_shapeb02_game* mpRight;
    cRZString mKey;
};

struct TIter_0081dee0_shapeb02_game {
    TNode_0081dee0_shapeb02_game* mpNode;
    TIter_0081dee0_shapeb02_game(TNode_0081dee0_shapeb02_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_0081dee0_shapeb02_game {
    TNode_0081dee0_shapeb02_game* mpNode;
    bool mbInserted;
    TRes_0081dee0_shapeb02_game(TNode_0081dee0_shapeb02_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

// STUB: 0x004b5ca0
bool Fn004b5ca0_0081dee0(const std::string& rLeft, const std::string& rRight);

struct View_0081dee0_shapeb02_game {
    TNode_0081dee0_shapeb02_game* mpHead;
    // STUB: 0x0081de20
    TIter_0081dee0_shapeb02_game Insert(TNode_0081dee0_shapeb02_game* pX, TNode_0081dee0_shapeb02_game* pY, const cRZString* pValue, uint32_t nFlag);
    TRes_0081dee0_shapeb02_game InsertUnique(const cRZString* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0081dee0 score 19
TRes_0081dee0_shapeb02_game View_0081dee0_shapeb02_game::InsertUnique(const cRZString* pValue)
{
    TNode_0081dee0_shapeb02_game* pHead = mpHead;
    TNode_0081dee0_shapeb02_game* pX = pHead->mpParent;
    TNode_0081dee0_shapeb02_game* pY = pHead;
    bool bLess = true;
    while (pX) {
        pY = pX;
        cRZString* pNodeKey = &pX->mKey;
        const std::string* pNodeStr = pNodeKey;
        const std::string* pValueStr = pValue;
        bLess = pValueStr->compare(*pNodeStr) < 0;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_0081dee0_shapeb02_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_0081dee0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    const std::string* pValueStr2 = pValue;
    cRZString* pItKey = &it.mpNode->mKey;
    const std::string* pItStr = pItKey;
    if (Fn004b5ca0_0081dee0(*pItStr, *pValueStr2)) {
        return TRes_0081dee0_shapeb02_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_0081dee0_shapeb02_game(it.mpNode, false);
}
#endif

