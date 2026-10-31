// Shape families of packet top_shape05_game, written by scratch/s16/gen/top_shape05_game/gen.sh.
#include <new>
#include "common/types.h"

struct PoolNode_top_shape05_game {
    PoolNode_top_shape05_game* mpNext;
};

struct PoolBlock_top_shape05_game {
    uint32_t pad0;
    uint32_t pad4;
    PoolNode_top_shape05_game* mpFree;
    uint32_t mnUsed;
};

struct Pool_top_shape05_game {
    uint32_t mnField00;
    PoolBlock_top_shape05_game* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_top_shape05_game* Refill();
};

struct View_42e410_top_shape05_game {
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
    virtual void Slot13(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x0042e410
uint32_t View_42e410_top_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot13(1);
    return 0;
}

struct Obj_42f6b0_top_shape05_game {
    // STUB: 0x0042f5d0
    Obj_42f6b0_top_shape05_game* Ctor();
};

// FUNCTION: 0x0042f6b0
Obj_42f6b0_top_shape05_game* Fn0042f6b0()
{
    void* p = ::operator new(0x3c);
    if (p) {
        return static_cast<Obj_42f6b0_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Base_43fba0_top_shape05_game {
    // STUB: 0x009457c6
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_43fba0_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0043fba0
bool View_43fba0_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x8a09f5f5) {
        return reinterpret_cast<Base_43fba0_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct Obj_448ff0_top_shape05_game {
    // STUB: 0x00448e30
    Obj_448ff0_top_shape05_game* Ctor();
};

// FUNCTION: 0x00448ff0
Obj_448ff0_top_shape05_game* Fn00448ff0()
{
    void* p = ::operator new(0x128);
    if (p) {
        return static_cast<Obj_448ff0_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Base_4587d0_top_shape05_game {
    // STUB: 0x005e89c0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_4587d0_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x004587d0
bool View_4587d0_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x87dda3a9) {
        return reinterpret_cast<Base_4587d0_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct Base_46fe30_top_shape05_game {
    // STUB: 0x005e89c0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_46fe30_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0046fe30
bool View_46fe30_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x69d25c60) {
        return reinterpret_cast<Base_46fe30_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

// GLOBAL: 0x00b07fc8
extern Pool_top_shape05_game gBb07fc8;

struct View_472960_top_shape05_game {
    PoolNode_top_shape05_game* Fn00472960();
};

// FUNCTION: 0x00472960
PoolNode_top_shape05_game* View_472960_top_shape05_game::Fn00472960()
{
    PoolNode_top_shape05_game* pNode = gBb07fc8.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb07fc8.Refill();
    }
    gBb07fc8.mpBlock->mpFree = pNode->mpNext;
    gBb07fc8.mpBlock->mnUsed++;
    return pNode;
}

// GLOBAL: 0x00b09428
extern Pool_top_shape05_game gBb09428;

struct View_477320_top_shape05_game {
    PoolNode_top_shape05_game* Fn00477320();
};

// FUNCTION: 0x00477320
PoolNode_top_shape05_game* View_477320_top_shape05_game::Fn00477320()
{
    PoolNode_top_shape05_game* pNode = gBb09428.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb09428.Refill();
    }
    gBb09428.mpBlock->mpFree = pNode->mpNext;
    gBb09428.mpBlock->mnUsed++;
    return pNode;
}

struct View_4972c0_top_shape05_game {
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
    virtual void Slot17(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x004972c0
uint32_t View_4972c0_top_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot17(1);
    return 0;
}

struct Base_4ada10_top_shape05_game {
    // STUB: 0x005e89c0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_4ada10_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x004ada10
bool View_4ada10_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xabf98cb3) {
        return reinterpret_cast<Base_4ada10_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct Obj_4eb080_top_shape05_game {
    // STUB: 0x004f9830
    Obj_4eb080_top_shape05_game* Ctor();
};

// FUNCTION: 0x004eb080
Obj_4eb080_top_shape05_game* Fn004eb080()
{
    void* p = ::operator new(0x80);
    if (p) {
        return static_cast<Obj_4eb080_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Obj_4eb0a0_top_shape05_game {
    // STUB: 0x004ef6f0
    Obj_4eb0a0_top_shape05_game* Ctor();
};

// FUNCTION: 0x004eb0a0
Obj_4eb0a0_top_shape05_game* Fn004eb0a0()
{
    void* p = ::operator new(0x50);
    if (p) {
        return static_cast<Obj_4eb0a0_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Obj_4eb0c0_top_shape05_game {
    // STUB: 0x004ea390
    Obj_4eb0c0_top_shape05_game* Ctor();
};

// FUNCTION: 0x004eb0c0
Obj_4eb0c0_top_shape05_game* Fn004eb0c0()
{
    void* p = ::operator new(0x120);
    if (p) {
        return static_cast<Obj_4eb0c0_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Obj_4eb0e0_top_shape05_game {
    // STUB: 0x004f1930
    Obj_4eb0e0_top_shape05_game* Ctor();
};

// FUNCTION: 0x004eb0e0
Obj_4eb0e0_top_shape05_game* Fn004eb0e0()
{
    void* p = ::operator new(0x7c);
    if (p) {
        return static_cast<Obj_4eb0e0_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Obj_4eb180_top_shape05_game {
    // STUB: 0x008d376e
    Obj_4eb180_top_shape05_game* Ctor();
};

// FUNCTION: 0x004eb180
Obj_4eb180_top_shape05_game* Fn004eb180()
{
    void* p = ::operator new(0x100);
    if (p) {
        return static_cast<Obj_4eb180_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

// STUB: 0x0055b970
void* Fn0055b970(uint32_t n);

struct Obj_5146a0_top_shape05_game {
    // STUB: 0x00533ba0
    Obj_5146a0_top_shape05_game* Ctor();
};

// FUNCTION: 0x005146a0
Obj_5146a0_top_shape05_game* Fn005146a0()
{
    void* p = Fn0055b970(0x2b8);
    if (p) {
        return static_cast<Obj_5146a0_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

// STUB: 0x0055b970
void* Fn0055b970(uint32_t n);

struct Obj_5146c0_top_shape05_game {
    // STUB: 0x00524360
    Obj_5146c0_top_shape05_game* Ctor();
};

// FUNCTION: 0x005146c0
Obj_5146c0_top_shape05_game* Fn005146c0()
{
    void* p = Fn0055b970(0x2b8);
    if (p) {
        return static_cast<Obj_5146c0_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

// STUB: 0x0055b970
void* Fn0055b970(uint32_t n);

struct Obj_5146e0_top_shape05_game {
    // STUB: 0x005244c0
    Obj_5146e0_top_shape05_game* Ctor();
};

// FUNCTION: 0x005146e0
Obj_5146e0_top_shape05_game* Fn005146e0()
{
    void* p = Fn0055b970(0x2b8);
    if (p) {
        return static_cast<Obj_5146e0_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

// STUB: 0x0055b970
void* Fn0055b970(uint32_t n);

struct Obj_514700_top_shape05_game {
    // STUB: 0x0054cd90
    Obj_514700_top_shape05_game* Ctor();
};

// FUNCTION: 0x00514700
Obj_514700_top_shape05_game* Fn00514700()
{
    void* p = Fn0055b970(0x37c);
    if (p) {
        return static_cast<Obj_514700_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

// STUB: 0x0055b970
void* Fn0055b970(uint32_t n);

struct Obj_514720_top_shape05_game {
    // STUB: 0x0053cec0
    Obj_514720_top_shape05_game* Ctor();
};

// FUNCTION: 0x00514720
Obj_514720_top_shape05_game* Fn00514720()
{
    void* p = Fn0055b970(0x2c4);
    if (p) {
        return static_cast<Obj_514720_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Obj_514820_top_shape05_game {
    // STUB: 0x0056d9a0
    Obj_514820_top_shape05_game* Ctor();
};

// FUNCTION: 0x00514820
Obj_514820_top_shape05_game* Fn00514820()
{
    void* p = ::operator new(0xdc8);
    if (p) {
        return static_cast<Obj_514820_top_shape05_game*>(p)->Ctor();
    }
    return 0;
}

struct Base_585ad0_top_shape05_game {
    // STUB: 0x009457c6
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_585ad0_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00585ad0
bool View_585ad0_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xa5eaa1a) {
        return reinterpret_cast<Base_585ad0_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

// GLOBAL: 0x00b0a808
extern Pool_top_shape05_game gBb0a808;

struct View_5ca8a0_top_shape05_game {
    PoolNode_top_shape05_game* Fn005ca8a0();
};

// FUNCTION: 0x005ca8a0
PoolNode_top_shape05_game* View_5ca8a0_top_shape05_game::Fn005ca8a0()
{
    PoolNode_top_shape05_game* pNode = gBb0a808.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0a808.Refill();
    }
    gBb0a808.mpBlock->mpFree = pNode->mpNext;
    gBb0a808.mpBlock->mnUsed++;
    return pNode;
}

struct Base_5d6160_top_shape05_game {
    // STUB: 0x005e89c0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_5d6160_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005d6160
bool View_5d6160_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xc8fce101) {
        return reinterpret_cast<Base_5d6160_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct Base_5e28c0_top_shape05_game {
    // STUB: 0x005e89c0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_5e28c0_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005e28c0
bool View_5e28c0_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x295d1162) {
        return reinterpret_cast<Base_5e28c0_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

// GLOBAL: 0x00b0a96c
extern Pool_top_shape05_game gBb0a96c;

struct View_5f5050_top_shape05_game {
    PoolNode_top_shape05_game* Fn005f5050();
};

// FUNCTION: 0x005f5050
PoolNode_top_shape05_game* View_5f5050_top_shape05_game::Fn005f5050()
{
    PoolNode_top_shape05_game* pNode = gBb0a96c.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0a96c.Refill();
    }
    gBb0a96c.mpBlock->mpFree = pNode->mpNext;
    gBb0a96c.mpBlock->mnUsed++;
    return pNode;
}

struct Target_637ea0_top_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual uint32_t Slot05() = 0;
};

struct View_637ea0_top_shape05_game {
    uint32_t pad[3];
    Target_637ea0_top_shape05_game* mpTarget;
    uint32_t Fn00637ea0();
};

// FUNCTION: 0x00637ea0
uint32_t View_637ea0_top_shape05_game::Fn00637ea0()
{
    return mpTarget->Slot05();
}

struct Target_6452e0_top_shape05_game {
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
    virtual uint32_t Slot42() = 0;
};

struct View_6452e0_top_shape05_game {
    uint32_t pad[5];
    Target_6452e0_top_shape05_game* mpTarget;
    uint32_t Fn006452e0();
};

// FUNCTION: 0x006452e0
uint32_t View_6452e0_top_shape05_game::Fn006452e0()
{
    return mpTarget->Slot42();
}

struct Target_6452f0_top_shape05_game {
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
    virtual uint32_t Slot43() = 0;
};

struct View_6452f0_top_shape05_game {
    uint32_t pad[5];
    Target_6452f0_top_shape05_game* mpTarget;
    uint32_t Fn006452f0();
};

// FUNCTION: 0x006452f0
uint32_t View_6452f0_top_shape05_game::Fn006452f0()
{
    return mpTarget->Slot43();
}

struct Target_645300_top_shape05_game {
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
    virtual uint32_t Slot45() = 0;
};

struct View_645300_top_shape05_game {
    uint32_t pad[5];
    Target_645300_top_shape05_game* mpTarget;
    uint32_t Fn00645300();
};

// FUNCTION: 0x00645300
uint32_t View_645300_top_shape05_game::Fn00645300()
{
    return mpTarget->Slot45();
}

// GLOBAL: 0x00b0bec0
extern Pool_top_shape05_game gBb0bec0;

struct View_6487d0_top_shape05_game {
    PoolNode_top_shape05_game* Fn006487d0();
};

// FUNCTION: 0x006487d0
PoolNode_top_shape05_game* View_6487d0_top_shape05_game::Fn006487d0()
{
    PoolNode_top_shape05_game* pNode = gBb0bec0.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0bec0.Refill();
    }
    gBb0bec0.mpBlock->mpFree = pNode->mpNext;
    gBb0bec0.mpBlock->mnUsed++;
    return pNode;
}

// GLOBAL: 0x00b0cdb8
extern Pool_top_shape05_game gBb0cdb8;

struct View_652fe0_top_shape05_game {
    PoolNode_top_shape05_game* Fn00652fe0();
};

// FUNCTION: 0x00652fe0
PoolNode_top_shape05_game* View_652fe0_top_shape05_game::Fn00652fe0()
{
    PoolNode_top_shape05_game* pNode = gBb0cdb8.mpBlock->mpFree;
    if (!pNode) {
        pNode = gBb0cdb8.Refill();
    }
    gBb0cdb8.mpBlock->mpFree = pNode->mpNext;
    gBb0cdb8.mpBlock->mnUsed++;
    return pNode;
}

struct Base_6855e0_top_shape05_game {
    // STUB: 0x0099b774
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_6855e0_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006855e0
bool View_6855e0_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x7a368ee3) {
        return reinterpret_cast<Base_6855e0_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct Base_68b1a0_top_shape05_game {
    // STUB: 0x006e8fd0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_68b1a0_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0068b1a0
bool View_68b1a0_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xea20548d) {
        return reinterpret_cast<Base_68b1a0_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct Target_68bab0_top_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual uint32_t Slot07() = 0;
};

struct View_68bab0_top_shape05_game {
    uint32_t pad[16];
    Target_68bab0_top_shape05_game* mpTarget;
    uint32_t Fn0068bab0();
};

// FUNCTION: 0x0068bab0
uint32_t View_68bab0_top_shape05_game::Fn0068bab0()
{
    return mpTarget->Slot07();
}

struct View_6d5140_top_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x006d5140
uint32_t View_6d5140_top_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot05(1);
    return 0;
}

struct Target_6da440_top_shape05_game {
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
    virtual uint32_t Slot22() = 0;
};

struct View_6da440_top_shape05_game {
    uint32_t pad[13];
    Target_6da440_top_shape05_game* mpTarget;
    uint32_t Fn006da440();
};

// FUNCTION: 0x006da440
uint32_t View_6da440_top_shape05_game::Fn006da440()
{
    return mpTarget->Slot22();
}

struct Base_700ee0_top_shape05_game {
    // STUB: 0x006e8fd0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_700ee0_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00700ee0
bool View_700ee0_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xca22fe3e) {
        return reinterpret_cast<Base_700ee0_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x4)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct View_7048b0_top_shape05_game {
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
    virtual void Slot15(uint32_t n) = 0;
    uint32_t pad[3];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x007048b0
uint32_t View_7048b0_top_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot15(1);
    return 0;
}

struct Target_72a030_top_shape05_game {
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
    virtual uint32_t Slot34() = 0;
};

struct View_72a030_top_shape05_game {
    uint32_t pad[13];
    Target_72a030_top_shape05_game* mpTarget;
    uint32_t Fn0072a030();
};

// FUNCTION: 0x0072a030
uint32_t View_72a030_top_shape05_game::Fn0072a030()
{
    return mpTarget->Slot34();
}

struct View_72a270_top_shape05_game {
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
    virtual void Slot10(uint32_t n) = 0;
    uint32_t pad[4];
    int32_t mnRefCount;
    uint32_t Release();
};

// FUNCTION: 0x0072a270
uint32_t View_72a270_top_shape05_game::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot04();
    Slot10(1);
    return 0;
}

struct Base_735260_top_shape05_game {
    // STUB: 0x009457c6
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_735260_top_shape05_game {
    virtual void Slot00() = 0;
    virtual uint32_t Slot01() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00735260
bool View_735260_top_shape05_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x895d6544) {
        return reinterpret_cast<Base_735260_top_shape05_game*>(reinterpret_cast<char*>(this) + 0x8)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    Slot01();
    return true;
}

struct Target_7fc2d0_top_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual uint32_t Slot03() = 0;
};

struct View_7fc2d0_top_shape05_game {
    uint32_t pad[12];
    Target_7fc2d0_top_shape05_game* mpTarget;
    uint32_t Fn007fc2d0();
};

// FUNCTION: 0x007fc2d0
uint32_t View_7fc2d0_top_shape05_game::Fn007fc2d0()
{
    return mpTarget->Slot03();
}

struct Obj_80bd70_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080bd70
Obj_80bd70_top_shape05_game* Fn0080bd70()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80bd70_top_shape05_game* o = static_cast<Obj_80bd70_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabd9d8;
        o->w[1] = 0xabd9bc;
        o->w[2] = 0xabd958;
        o->w[7] = 0xabd940;
        return o;
    }
    return 0;
}

struct Obj_80bdc0_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080bdc0
Obj_80bdc0_top_shape05_game* Fn0080bdc0()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80bdc0_top_shape05_game* o = static_cast<Obj_80bdc0_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabdaf8;
        o->w[1] = 0xabdadc;
        o->w[2] = 0xabda78;
        o->w[7] = 0xabda60;
        return o;
    }
    return 0;
}

struct Obj_80be10_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080be10
Obj_80be10_top_shape05_game* Fn0080be10()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80be10_top_shape05_game* o = static_cast<Obj_80be10_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabdc18;
        o->w[1] = 0xabdbfc;
        o->w[2] = 0xabdb98;
        o->w[7] = 0xabdb80;
        return o;
    }
    return 0;
}

struct Obj_80c360_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080c360
Obj_80c360_top_shape05_game* Fn0080c360()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80c360_top_shape05_game* o = static_cast<Obj_80c360_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabe098;
        o->w[1] = 0xabe07c;
        o->w[2] = 0xabe018;
        o->w[7] = 0xabe000;
        return o;
    }
    return 0;
}

struct Obj_80c540_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080c540
Obj_80c540_top_shape05_game* Fn0080c540()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80c540_top_shape05_game* o = static_cast<Obj_80c540_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabe1b8;
        o->w[1] = 0xabe19c;
        o->w[2] = 0xabe138;
        o->w[7] = 0xabe120;
        return o;
    }
    return 0;
}

struct Obj_80c660_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080c660
Obj_80c660_top_shape05_game* Fn0080c660()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80c660_top_shape05_game* o = static_cast<Obj_80c660_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabe3f8;
        o->w[1] = 0xabe3dc;
        o->w[2] = 0xabe378;
        o->w[7] = 0xabe360;
        return o;
    }
    return 0;
}

struct Obj_80c6b0_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080c6b0
Obj_80c6b0_top_shape05_game* Fn0080c6b0()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80c6b0_top_shape05_game* o = static_cast<Obj_80c6b0_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabe518;
        o->w[1] = 0xabe4fc;
        o->w[2] = 0xabe498;
        o->w[7] = 0xabe480;
        return o;
    }
    return 0;
}

struct Obj_80c700_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080c700
Obj_80c700_top_shape05_game* Fn0080c700()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80c700_top_shape05_game* o = static_cast<Obj_80c700_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabe638;
        o->w[1] = 0xabe61c;
        o->w[2] = 0xabe5b8;
        o->w[7] = 0xabe5a0;
        return o;
    }
    return 0;
}

struct Obj_80c8e0_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080c8e0
Obj_80c8e0_top_shape05_game* Fn0080c8e0()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80c8e0_top_shape05_game* o = static_cast<Obj_80c8e0_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabe878;
        o->w[1] = 0xabe85c;
        o->w[2] = 0xabe7f8;
        o->w[7] = 0xabe7e0;
        return o;
    }
    return 0;
}

struct Obj_80ea30_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080ea30
Obj_80ea30_top_shape05_game* Fn0080ea30()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80ea30_top_shape05_game* o = static_cast<Obj_80ea30_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabebc8;
        o->w[1] = 0xabebac;
        o->w[2] = 0xabeb48;
        o->w[7] = 0xabeb34;
        return o;
    }
    return 0;
}

struct Obj_80edb0_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080edb0
Obj_80edb0_top_shape05_game* Fn0080edb0()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80edb0_top_shape05_game* o = static_cast<Obj_80edb0_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabef28;
        o->w[1] = 0xabef0c;
        o->w[2] = 0xabeea8;
        o->w[7] = 0xabee90;
        return o;
    }
    return 0;
}

struct Obj_80ee00_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080ee00
Obj_80ee00_top_shape05_game* Fn0080ee00()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80ee00_top_shape05_game* o = static_cast<Obj_80ee00_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabf048;
        o->w[1] = 0xabf02c;
        o->w[2] = 0xabefc8;
        o->w[7] = 0xabefb0;
        return o;
    }
    return 0;
}

struct Obj_80ee60_top_shape05_game {
    uint32_t w[0xa0 / 4];
    // STUB: 0x0080cc50
    void Ctor();
};

// FUNCTION: 0x0080ee60
Obj_80ee60_top_shape05_game* Fn0080ee60()
{
    void* p = ::operator new(0xa0);
    if (p) {
        Obj_80ee60_top_shape05_game* o = static_cast<Obj_80ee60_top_shape05_game*>(p);
        o->Ctor();
        o->w[0] = 0xabf168;
        o->w[1] = 0xabf14c;
        o->w[2] = 0xabf0e8;
        o->w[7] = 0xabf0d0;
        return o;
    }
    return 0;
}

struct Target_875a90_top_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual uint32_t Slot05() = 0;
};

struct View_875a90_top_shape05_game {
    uint32_t pad[8];
    Target_875a90_top_shape05_game* mpTarget;
    uint32_t Fn00875a90();
};

// FUNCTION: 0x00875a90
uint32_t View_875a90_top_shape05_game::Fn00875a90()
{
    return mpTarget->Slot05();
}

// SKIPPED 8f59c0: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f59f0: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f5a20: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f5a50: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f5a80: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f5ab0: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f5ae0: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f65f0: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f6620: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f6650: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f6680: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f66b0: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f66e0: mid-frame fragment (reads the caller's stack slots, jumps back into it)
// SKIPPED 8f6710: mid-frame fragment (reads the caller's stack slots, jumps back into it)
struct Target_9ee030_top_shape05_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual uint32_t Slot03() = 0;
};

struct View_9ee030_top_shape05_game {
    uint32_t pad[3];
    Target_9ee030_top_shape05_game* mpTarget;
    uint32_t Fn009ee030();
};

// FUNCTION: 0x009ee030
uint32_t View_9ee030_top_shape05_game::Fn009ee030()
{
    return mpTarget->Slot03();
}

