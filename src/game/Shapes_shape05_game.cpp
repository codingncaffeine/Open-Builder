// Shape families of packet shape05_game, written by scratch/s16/gen/shape05_game/gen.sh.
#include <new>
#include "common/types.h"

struct PoolNode_shape05_game {
    PoolNode_shape05_game* mpNext;
};

struct PoolBlock_shape05_game {
    uint32_t pad0;
    uint32_t pad4;
    PoolNode_shape05_game* mpFree;
    uint32_t mnUsed;
};

struct Pool_shape05_game {
    uint32_t mnField00;
    PoolBlock_shape05_game* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_shape05_game* Refill();
};

// GLOBAL: 0x00b07f1c
extern Pool_shape05_game gBb07f1c;

struct View_458a60_shape05_game {
    PoolNode_shape05_game* Fn00458a60();
};

// FUNCTION: 0x00458a60
PoolNode_shape05_game* View_458a60_shape05_game::Fn00458a60()
{
    PoolNode_shape05_game* pNode = gBb07f1c.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb07f1c.Refill();
    }
    gBb07f1c.mpBlock->mpFree = pNode->mpNext;
    gBb07f1c.mpBlock->mnUsed++;
    return pNode;
}

struct View_46f7f0_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08(uint32_t n) = 0;
    uint32_t pad[1];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x0046f7f0
uint32_t View_46f7f0_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot08(1);
    return 0;
}

// GLOBAL: 0x00b0a824
extern Pool_shape05_game gBb0a824;

struct View_5d5500_shape05_game {
    PoolNode_shape05_game* Fn005d5500();
};

// FUNCTION: 0x005d5500
PoolNode_shape05_game* View_5d5500_shape05_game::Fn005d5500()
{
    PoolNode_shape05_game* pNode = gBb0a824.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0a824.Refill();
    }
    gBb0a824.mpBlock->mpFree = pNode->mpNext;
    gBb0a824.mpBlock->mnUsed++;
    return pNode;
}

// GLOBAL: 0x00b0a830
extern Pool_shape05_game gBb0a830;

struct View_5d6220_shape05_game {
    PoolNode_shape05_game* Fn005d6220();
};

// FUNCTION: 0x005d6220
PoolNode_shape05_game* View_5d6220_shape05_game::Fn005d6220()
{
    PoolNode_shape05_game* pNode = gBb0a830.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0a830.Refill();
    }
    gBb0a830.mpBlock->mpFree = pNode->mpNext;
    gBb0a830.mpBlock->mnUsed++;
    return pNode;
}

struct Base_5dea80_shape05_game {
    // STUB: 0x005e89c0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_5dea80_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005dea80
bool View_5dea80_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x97f6d98) {
        return reinterpret_cast<Base_5dea80_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

// GLOBAL: 0x00b0a86c
extern Pool_shape05_game gBb0a86c;

struct View_5decf0_shape05_game {
    PoolNode_shape05_game* Fn005decf0();
};

// FUNCTION: 0x005decf0
PoolNode_shape05_game* View_5decf0_shape05_game::Fn005decf0()
{
    PoolNode_shape05_game* pNode = gBb0a86c.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0a86c.Refill();
    }
    gBb0a86c.mpBlock->mpFree = pNode->mpNext;
    gBb0a86c.mpBlock->mnUsed++;
    return pNode;
}

// GLOBAL: 0x00b0a898
extern Pool_shape05_game gBb0a898;

struct View_5e1490_shape05_game {
    PoolNode_shape05_game* Fn005e1490();
};

// FUNCTION: 0x005e1490
PoolNode_shape05_game* View_5e1490_shape05_game::Fn005e1490()
{
    PoolNode_shape05_game* pNode = gBb0a898.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0a898.Refill();
    }
    gBb0a898.mpBlock->mpFree = pNode->mpNext;
    gBb0a898.mpBlock->mnUsed++;
    return pNode;
}

// GLOBAL: 0x00b0a8ac
extern Pool_shape05_game gBb0a8ac;

struct View_5e2a50_shape05_game {
    PoolNode_shape05_game* Fn005e2a50();
};

// FUNCTION: 0x005e2a50
PoolNode_shape05_game* View_5e2a50_shape05_game::Fn005e2a50()
{
    PoolNode_shape05_game* pNode = gBb0a8ac.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0a8ac.Refill();
    }
    gBb0a8ac.mpBlock->mpFree = pNode->mpNext;
    gBb0a8ac.mpBlock->mnUsed++;
    return pNode;
}

// GLOBAL: 0x00b0a9b8
extern Pool_shape05_game gBb0a9b8;

struct View_5f7d80_shape05_game {
    PoolNode_shape05_game* Fn005f7d80();
};

// FUNCTION: 0x005f7d80
PoolNode_shape05_game* View_5f7d80_shape05_game::Fn005f7d80()
{
    PoolNode_shape05_game* pNode = gBb0a9b8.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0a9b8.Refill();
    }
    gBb0a9b8.mpBlock->mpFree = pNode->mpNext;
    gBb0a9b8.mpBlock->mnUsed++;
    return pNode;
}

// GLOBAL: 0x00b0a9e8
extern Pool_shape05_game gBb0a9e8;

struct View_5fd840_shape05_game {
    PoolNode_shape05_game* Fn005fd840();
};

// FUNCTION: 0x005fd840
PoolNode_shape05_game* View_5fd840_shape05_game::Fn005fd840()
{
    PoolNode_shape05_game* pNode = gBb0a9e8.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0a9e8.Refill();
    }
    gBb0a9e8.mpBlock->mpFree = pNode->mpNext;
    gBb0a9e8.mpBlock->mnUsed++;
    return pNode;
}

// GLOBAL: 0x00b0a9f4
extern Pool_shape05_game gBb0a9f4;

struct View_5fd8f0_shape05_game {
    PoolNode_shape05_game* Fn005fd8f0();
};

// FUNCTION: 0x005fd8f0
PoolNode_shape05_game* View_5fd8f0_shape05_game::Fn005fd8f0()
{
    PoolNode_shape05_game* pNode = gBb0a9f4.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0a9f4.Refill();
    }
    gBb0a9f4.mpBlock->mpFree = pNode->mpNext;
    gBb0a9f4.mpBlock->mnUsed++;
    return pNode;
}

struct Target_6457b0_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual void Slot34() = 0;
    virtual void Slot35() = 0;
    virtual void Slot36() = 0;
    virtual void Slot37() = 0;
    virtual void Slot38() = 0;
    virtual void Slot39() = 0;
    virtual void Slot40() = 0;
    virtual void Slot41() = 0;
    virtual void Slot42() = 0;
    virtual void Slot43() = 0;
    virtual uint32_t Slot44() = 0;
};

struct View_6457b0_shape05_game {
    uint32_t pad[5];
    Target_6457b0_shape05_game* mpTarget;
    uint32_t Fn006457b0();
};

// FUNCTION: 0x006457b0
uint32_t View_6457b0_shape05_game::Fn006457b0()
{
    return mpTarget->Slot44();
}

// GLOBAL: 0x00b0c0c8
extern Pool_shape05_game gBb0c0c8;

struct View_6499d0_shape05_game {
    PoolNode_shape05_game* Fn006499d0();
};

// FUNCTION: 0x006499d0
PoolNode_shape05_game* View_6499d0_shape05_game::Fn006499d0()
{
    PoolNode_shape05_game* pNode = gBb0c0c8.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0c0c8.Refill();
    }
    gBb0c0c8.mpBlock->mpFree = pNode->mpNext;
    gBb0c0c8.mpBlock->mnUsed++;
    return pNode;
}

// GLOBAL: 0x00b0c258
extern Pool_shape05_game gBb0c258;

struct View_64a2e0_shape05_game {
    PoolNode_shape05_game* Fn0064a2e0();
};

// FUNCTION: 0x0064a2e0
PoolNode_shape05_game* View_64a2e0_shape05_game::Fn0064a2e0()
{
    PoolNode_shape05_game* pNode = gBb0c258.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0c258.Refill();
    }
    gBb0c258.mpBlock->mpFree = pNode->mpNext;
    gBb0c258.mpBlock->mnUsed++;
    return pNode;
}

struct Base_6808a0_shape05_game {
    // STUB: 0x009457c6
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_6808a0_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006808a0
bool View_6808a0_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x1cf94583) {
        return reinterpret_cast<Base_6808a0_shape05_game*>(reinterpret_cast<char*>(this) + 0x8)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct View_68bfb0_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x0068bfb0
uint32_t View_68bfb0_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot16(1);
    return 0;
}

struct View_69eb50_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x0069eb50
uint32_t View_69eb50_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot06(1);
    return 0;
}

struct Obj_6a05c0_shape05_game {
    // STUB: 0x006a0440
    Obj_6a05c0_shape05_game* Ctor();
};

// FUNCTION: 0x006a05c0
Obj_6a05c0_shape05_game* Fn006a05c0()
{
    void* p = ::operator new(0x174);
    if (p) {
        return static_cast<Obj_6a05c0_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct View_6ae4a0_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x006ae4a0
uint32_t View_6ae4a0_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot09(1);
    return 0;
}

struct View_6b3d00_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x006b3d00
uint32_t View_6b3d00_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot31(1);
    return 0;
}

struct Target_6bd740_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual uint32_t Slot07() = 0;
};

struct View_6bd740_shape05_game {
    uint32_t pad[10];
    Target_6bd740_shape05_game* mpTarget;
    uint32_t Fn006bd740();
};

// FUNCTION: 0x006bd740
uint32_t View_6bd740_shape05_game::Fn006bd740()
{
    return mpTarget->Slot07();
}

struct View_6bd8a0_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x006bd8a0
uint32_t View_6bd8a0_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot12(1);
    return 0;
}

// GLOBAL: 0x00b0d3ac
extern Pool_shape05_game gBb0d3ac;

struct View_6bf430_shape05_game {
    PoolNode_shape05_game* Fn006bf430();
};

// FUNCTION: 0x006bf430
PoolNode_shape05_game* View_6bf430_shape05_game::Fn006bf430()
{
    PoolNode_shape05_game* pNode = gBb0d3ac.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0d3ac.Refill();
    }
    gBb0d3ac.mpBlock->mpFree = pNode->mpNext;
    gBb0d3ac.mpBlock->mnUsed++;
    return pNode;
}

struct View_6da610_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x006da610
uint32_t View_6da610_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot29(1);
    return 0;
}

struct Target_6eb180_shape05_game {
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
    virtual uint32_t Slot10() = 0;
};

struct View_6eb180_shape05_game {
    uint32_t pad[8];
    Target_6eb180_shape05_game* mpTarget;
    uint32_t Fn006eb180();
};

// FUNCTION: 0x006eb180
uint32_t View_6eb180_shape05_game::Fn006eb180()
{
    return mpTarget->Slot10();
}

struct View_6eb190_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual void Slot34() = 0;
    virtual void Slot35() = 0;
    virtual void Slot36() = 0;
    virtual void Slot37() = 0;
    virtual void Slot38() = 0;
    virtual void Slot39() = 0;
    virtual void Slot40() = 0;
    virtual void Slot41() = 0;
    virtual void Slot42() = 0;
    virtual void Slot43() = 0;
    virtual void Slot44() = 0;
    virtual void Slot45() = 0;
    virtual void Slot46() = 0;
    virtual void Slot47() = 0;
    virtual void Slot48() = 0;
    virtual void Slot49() = 0;
    virtual void Slot50() = 0;
    virtual void Slot51() = 0;
    virtual void Slot52(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x006eb190
uint32_t View_6eb190_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot52(1);
    return 0;
}

struct View_70e2f0_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual void Slot34() = 0;
    virtual void Slot35() = 0;
    virtual void Slot36() = 0;
    virtual void Slot37() = 0;
    virtual void Slot38() = 0;
    virtual void Slot39() = 0;
    virtual void Slot40() = 0;
    virtual void Slot41() = 0;
    virtual void Slot42() = 0;
    virtual void Slot43(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x0070e2f0
uint32_t View_70e2f0_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot43(1);
    return 0;
}

struct Obj_721580_shape05_game {
    // STUB: 0x0071f830
    Obj_721580_shape05_game* Ctor();
};

// FUNCTION: 0x00721580
Obj_721580_shape05_game* Fn00721580()
{
    void* p = ::operator new(0xd58);
    if (p) {
        return static_cast<Obj_721580_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Obj_729310_shape05_game {
    // STUB: 0x00728c40
    Obj_729310_shape05_game* Ctor();
};

// FUNCTION: 0x00729310
Obj_729310_shape05_game* Fn00729310()
{
    void* p = ::operator new(0x168);
    if (p) {
        return static_cast<Obj_729310_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Target_7696b0_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual void Slot34() = 0;
    virtual void Slot35() = 0;
    virtual void Slot36() = 0;
    virtual void Slot37() = 0;
    virtual void Slot38() = 0;
    virtual void Slot39() = 0;
    virtual void Slot40() = 0;
    virtual void Slot41() = 0;
    virtual void Slot42() = 0;
    virtual void Slot43() = 0;
    virtual void Slot44() = 0;
    virtual void Slot45() = 0;
    virtual void Slot46() = 0;
    virtual void Slot47() = 0;
    virtual void Slot48() = 0;
    virtual void Slot49() = 0;
    virtual void Slot50() = 0;
    virtual void Slot51() = 0;
    virtual void Slot52() = 0;
    virtual void Slot53() = 0;
    virtual void Slot54() = 0;
    virtual void Slot55() = 0;
    virtual void Slot56() = 0;
    virtual void Slot57() = 0;
    virtual void Slot58() = 0;
    virtual void Slot59() = 0;
    virtual void Slot60() = 0;
    virtual void Slot61() = 0;
    virtual void Slot62() = 0;
    virtual void Slot63() = 0;
    virtual void Slot64() = 0;
    virtual void Slot65() = 0;
    virtual void Slot66() = 0;
    virtual void Slot67() = 0;
    virtual void Slot68() = 0;
    virtual void Slot69() = 0;
    virtual uint32_t Slot70() = 0;
};

struct View_7696b0_shape05_game {
    uint32_t pad[3];
    Target_7696b0_shape05_game* mpTarget;
    uint32_t Fn007696b0();
};

// FUNCTION: 0x007696b0
uint32_t View_7696b0_shape05_game::Fn007696b0()
{
    return mpTarget->Slot70();
}

struct Target_7696c0_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual void Slot34() = 0;
    virtual void Slot35() = 0;
    virtual void Slot36() = 0;
    virtual void Slot37() = 0;
    virtual void Slot38() = 0;
    virtual void Slot39() = 0;
    virtual void Slot40() = 0;
    virtual void Slot41() = 0;
    virtual void Slot42() = 0;
    virtual void Slot43() = 0;
    virtual void Slot44() = 0;
    virtual void Slot45() = 0;
    virtual void Slot46() = 0;
    virtual void Slot47() = 0;
    virtual void Slot48() = 0;
    virtual void Slot49() = 0;
    virtual void Slot50() = 0;
    virtual void Slot51() = 0;
    virtual void Slot52() = 0;
    virtual void Slot53() = 0;
    virtual void Slot54() = 0;
    virtual void Slot55() = 0;
    virtual void Slot56() = 0;
    virtual void Slot57() = 0;
    virtual void Slot58() = 0;
    virtual void Slot59() = 0;
    virtual void Slot60() = 0;
    virtual void Slot61() = 0;
    virtual void Slot62() = 0;
    virtual void Slot63() = 0;
    virtual void Slot64() = 0;
    virtual void Slot65() = 0;
    virtual void Slot66() = 0;
    virtual void Slot67() = 0;
    virtual void Slot68() = 0;
    virtual void Slot69() = 0;
    virtual void Slot70() = 0;
    virtual uint32_t Slot71() = 0;
};

struct View_7696c0_shape05_game {
    uint32_t pad[3];
    Target_7696c0_shape05_game* mpTarget;
    uint32_t Fn007696c0();
};

// FUNCTION: 0x007696c0
uint32_t View_7696c0_shape05_game::Fn007696c0()
{
    return mpTarget->Slot71();
}

struct Target_793170_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual uint32_t Slot09() = 0;
};

struct View_793170_shape05_game {
    uint32_t pad[1];
    Target_793170_shape05_game* mpTarget;
    uint32_t Fn00793170();
};

// FUNCTION: 0x00793170
uint32_t View_793170_shape05_game::Fn00793170()
{
    return mpTarget->Slot09();
}

struct Base_7ce140_shape05_game {
    // STUB: 0x009457c6
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_7ce140_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x007ce140
bool View_7ce140_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xa1d8284) {
        return reinterpret_cast<Base_7ce140_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct Target_7d2a20_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual uint32_t Slot33() = 0;
};

struct View_7d2a20_shape05_game {
    uint32_t pad[12];
    Target_7d2a20_shape05_game* mpTarget;
    uint32_t Fn007d2a20();
};

// FUNCTION: 0x007d2a20
uint32_t View_7d2a20_shape05_game::Fn007d2a20()
{
    return mpTarget->Slot33();
}

struct Obj_800320_shape05_game {
    // STUB: 0x007ff930
    Obj_800320_shape05_game* Ctor();
};

// FUNCTION: 0x00800320
Obj_800320_shape05_game* Fn00800320()
{
    void* p = ::operator new(0x1a8);
    if (p) {
        return static_cast<Obj_800320_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Base_800c00_shape05_game {
    // STUB: 0x0091dd67
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_800c00_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00800c00
bool View_800c00_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xfac0e21a) {
        return reinterpret_cast<Base_800c00_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct View_80d520_shape05_game {
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
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x0080d520
uint32_t View_80d520_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot26(1);
    return 0;
}

