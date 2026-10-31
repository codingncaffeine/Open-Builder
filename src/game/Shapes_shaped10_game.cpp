// Shape families of packet shaped10_game (pairs written by hand).
#include <new>
#include "common/types.h"
#include "common/compiler.h"

// A generic object with virtual slots, used only through pointers (never constructed here).
struct Obj_shaped10_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06(uint32_t a) = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13(uint32_t a) = 0;
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
};

// ---- store a field into an out pointer
struct View_ae5c78_shaped10_game {
    uint32_t pad0;
    uint32_t pad4;
    uint32_t pad8;
    uint32_t mnC;
    uint32_t mnD;
    void Fn009edcc0(uint32_t* pOut);
    void Fn009edcd0(uint32_t* pOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009edcc0 score 6
void View_ae5c78_shaped10_game::Fn009edcc0(uint32_t* pOut)
{
    uint32_t v = mnC;
    *pOut = v;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009edcd0 score 6
void View_ae5c78_shaped10_game::Fn009edcd0(uint32_t* pOut)
{
    uint32_t v = mnD;
    *pOut = v;
}
#endif

// ---- null-checked slot call
struct View_acfb90_shaped10_game {
    uint32_t Fn00920530();
    uint32_t Fn00930b20();
};

// FUNCTION: 0x00920530
uint32_t View_acfb90_shaped10_game::Fn00920530()
{
    View_acfb90_shaped10_game* p = this;
    if (p) {
        reinterpret_cast<Obj_shaped10_game*>(p)->Slot13(1);
    }
    return 0;
}

// FUNCTION: 0x00930b20
uint32_t View_acfb90_shaped10_game::Fn00930b20()
{
    View_acfb90_shaped10_game* p = this;
    if (p) {
        reinterpret_cast<Obj_shaped10_game*>(p)->Slot06(1);
    }
    return 0;
}

// ---- factories
struct Obj_940294_shaped10_game {
    // STUB: 0x00940294
    Obj_940294_shaped10_game* Fn00940294();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009358c0 score 2
Obj_940294_shaped10_game* Fn009358c0()
{
    void* p = ::operator new(0x8);
    if (p) {
        return static_cast<Obj_940294_shaped10_game*>(p)->Fn00940294();
    }
    return 0;
}
#endif

struct Obj_95b8c4_shaped10_game {
    // STUB: 0x0095b8c4
    Obj_95b8c4_shaped10_game* Fn0095b8c4();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0094af90 score 2
Obj_95b8c4_shaped10_game* Fn0094af90()
{
    void* p = ::operator new(0x20);
    if (p) {
        return static_cast<Obj_95b8c4_shaped10_game*>(p)->Fn0095b8c4();
    }
    return 0;
}
#endif

// ---- double results stored through a pointer
// STUB: 0x009ed970
double Fn009ed970(uint32_t v);
// STUB: 0x009edad0
double Fn009edad0(uint32_t v);

// FUNCTION: 0x009edc60
void Fn009edc60(const uint32_t* pIn, double* pOut)
{
    uint32_t v = *pIn;
    *pOut = Fn009ed970(v);
}

// FUNCTION: 0x009edc80
void Fn009edc80(const uint32_t* pIn, double* pOut)
{
    uint32_t v = *pIn;
    *pOut = Fn009edad0(v);
}

// ---- 8-bit table maps
// GLOBAL: 0x00ae5200
extern uint8_t g00ae5200[0x100];
// GLOBAL: 0x00ae5300
extern uint8_t g00ae5300[0x100];

struct View_ae4bdc_shaped10_game {
    uint16_t Fn009eb3f0(uint32_t a);
    uint16_t Fn009eb450(uint32_t a);
};

// FUNCTION: 0x009eb3f0
uint16_t View_ae4bdc_shaped10_game::Fn009eb3f0(uint32_t a)
{
    uint16_t c = static_cast<uint16_t>(a);
    if (c < 0x100) {
        return g00ae5200[c];
    }
    return c;
}

// FUNCTION: 0x009eb450
uint16_t View_ae4bdc_shaped10_game::Fn009eb450(uint32_t a)
{
    uint16_t c = static_cast<uint16_t>(a);
    if (c < 0x100) {
        return g00ae5300[c];
    }
    return c;
}

// ---- exception constructors
struct View_ae4a2c_shaped10_game {
    uint32_t mVtbl;
    // STUB: 0x009dcb10
    void Base(const void* pMsg);
    View_ae4a2c_shaped10_game* Fn009dcdc0(const void* pMsg);
    View_ae4a2c_shaped10_game* Fn009dcde0(const void* pMsg);
};

// FUNCTION: 0x009dcdc0
View_ae4a2c_shaped10_game* View_ae4a2c_shaped10_game::Fn009dcdc0(const void* pMsg)
{
    Base(pMsg);
    mVtbl = 0xae4a2c;
    return this;
}

// FUNCTION: 0x009dcde0
View_ae4a2c_shaped10_game* View_ae4a2c_shaped10_game::Fn009dcde0(const void* pMsg)
{
    Base(pMsg);
    mVtbl = 0xae4a38;
    return this;
}

// ---- pair copy constructors
struct SubA_959f20_shaped10_game {
    // STUB: 0x009585fb
    void Fn009585fb(const SubA_959f20_shaped10_game* pOther);
};

struct View_959f20_shaped10_game {
    uint32_t mnKey;
    SubA_959f20_shaped10_game mSub;
    View_959f20_shaped10_game* Fn00959f20(const View_959f20_shaped10_game* pOther);
};

// FUNCTION: 0x00959f20
View_959f20_shaped10_game* View_959f20_shaped10_game::Fn00959f20(const View_959f20_shaped10_game* pOther)
{
    mnKey = pOther->mnKey;
    mSub.Fn009585fb(&pOther->mSub);
    return this;
}

struct SubB_9ab430_shaped10_game {
    // STUB: 0x009ab299
    void Fn009ab299(const SubB_9ab430_shaped10_game* pOther);
};

struct View_9ab430_shaped10_game {
    uint32_t mnKey;
    SubB_9ab430_shaped10_game mSub;
    View_9ab430_shaped10_game* Fn009ab430(const View_9ab430_shaped10_game* pOther);
};

// FUNCTION: 0x009ab430
View_9ab430_shaped10_game* View_9ab430_shaped10_game::Fn009ab430(const View_9ab430_shaped10_game* pOther)
{
    mnKey = pOther->mnKey;
    mSub.Fn009ab299(&pOther->mSub);
    return this;
}

// ---- sized factories with an argument
struct Obj_9c01af_shaped10_game {
    // STUB: 0x009c01af
    Obj_9c01af_shaped10_game* Fn009c01af(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009989d0 score 2
Obj_9c01af_shaped10_game* Fn009989d0()
{
    void* p = ::operator new(0x290);
    if (p) {
        return static_cast<Obj_9c01af_shaped10_game*>(p)->Fn009c01af(0x11ff);
    }
    return 0;
}
#endif

struct Obj_9abc95_shaped10_game {
    // STUB: 0x009abc95
    Obj_9abc95_shaped10_game* Fn009abc95(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00998b10 score 2
Obj_9abc95_shaped10_game* Fn00998b10()
{
    void* p = ::operator new(0x2e8);
    if (p) {
        return static_cast<Obj_9abc95_shaped10_game*>(p)->Fn009abc95(0x19bff);
    }
    return 0;
}
#endif

// ---- QueryInterface by two ids
struct View_QI_shaped10_game {
    bool Fn00944650(uint32_t id, void** ppOut);
    bool Fn0096c390(uint32_t id, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00944650 score 6
bool View_QI_shaped10_game::Fn00944650(uint32_t id, void** ppOut)
{
    switch (id) {
    case 1:
    case 0x5a2c1570:
        *ppOut = this;
        reinterpret_cast<Obj_shaped10_game*>(this)->Slot01();
        return true;
    default:
        return false;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096c390 score 6
bool View_QI_shaped10_game::Fn0096c390(uint32_t id, void** ppOut)
{
    switch (id) {
    case 1:
    case 0x3afd825f:
        *ppOut = this;
        reinterpret_cast<Obj_shaped10_game*>(this)->Slot01();
        return true;
    default:
        return false;
    }
}
#endif

// ---- QueryInterface by two ids (compare form)
struct View_QI2_shaped10_game {
    bool Fn00937880(uint32_t id, void** ppOut);
    bool Fn009759a0(uint32_t id, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00937880 score 17
bool View_QI2_shaped10_game::Fn00937880(uint32_t id, void** ppOut)
{
    if (id != 1 && id != 0xfb1c0050) {
        return false;
    }
    *ppOut = this;
    reinterpret_cast<Obj_shaped10_game*>(this)->Slot01();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009759a0 score 17
bool View_QI2_shaped10_game::Fn009759a0(uint32_t id, void** ppOut)
{
    if (id != 0xe56b8f03 && id != 1) {
        return false;
    }
    *ppOut = this;
    reinterpret_cast<Obj_shaped10_game*>(this)->Slot01();
    return true;
}
#endif

// ---- forwarding wrappers with a constant
// STUB: 0x00987440
void Fn00987440(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t k);
// STUB: 0x00989140
void Fn00989140(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t k, uint32_t e);

struct View_ada668_shaped10_game {
    void Fn00988d80(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
    void Fn00988db0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
    void Fn009896b0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
    void Fn009896e0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
};

// FUNCTION: 0x00988d80
void View_ada668_shaped10_game::Fn00988d80(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Fn00987440(a, b, c, d, 0xb8bee8);
}

// FUNCTION: 0x00988db0
void View_ada668_shaped10_game::Fn00988db0(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Fn00987440(a, b, c, d, 0xb6bee8);
}

// FUNCTION: 0x009896b0
void View_ada668_shaped10_game::Fn009896b0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Fn00989140(a, b, c, d, 0xb8bee8, e);
}

// FUNCTION: 0x009896e0
void View_ada668_shaped10_game::Fn009896e0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Fn00989140(a, b, c, d, 0xb6bee8, e);
}

// ---- tree erase
namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct TreeNode_shaped10_game {
    uint32_t pad0;
    uint32_t pad4;
    TreeNode_shaped10_game* mpLeft;
    TreeNode_shaped10_game* mpRight;
    uint8_t mData[1];
};

struct Dtor921c12_shaped10_game {
    // STUB: 0x00921c12
    void Fn00921c12();
};

struct Dtor414250_shaped10_game {
    // STUB: 0x00414250
    void Fn00414250();
};

struct View_Erase_shaped10_game {
    void Fn00922780(TreeNode_shaped10_game* pNode);
    void Fn009a84a0(TreeNode_shaped10_game* pNode);
    void Fn00921c60(TreeNode_shaped10_game* pNode);
    void Fn00938c50(TreeNode_shaped10_game* pNode);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00922780 score 10
void View_Erase_shaped10_game::Fn00922780(TreeNode_shaped10_game* pNode)
{
    if (pNode) {
        do {
            Fn00922780(pNode->mpRight);
            TreeNode_shaped10_game* pLeft = pNode->mpLeft;
            _STL::__stl_delete(pNode);
            pNode = pLeft;
        } while (pNode);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a84a0 score 10
void View_Erase_shaped10_game::Fn009a84a0(TreeNode_shaped10_game* pNode)
{
    if (pNode) {
        do {
            Fn009a84a0(pNode->mpRight);
            TreeNode_shaped10_game* pLeft = pNode->mpLeft;
            _STL::__stl_delete(pNode);
            pNode = pLeft;
        } while (pNode);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00921c60 score 10
void View_Erase_shaped10_game::Fn00921c60(TreeNode_shaped10_game* pNode)
{
    if (pNode) {
        do {
            Fn00921c60(pNode->mpRight);
            TreeNode_shaped10_game* pLeft = pNode->mpLeft;
            reinterpret_cast<Dtor921c12_shaped10_game*>(pNode->mData)->Fn00921c12();
            _STL::__stl_delete(pNode);
            pNode = pLeft;
        } while (pNode);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00938c50 score 10
void View_Erase_shaped10_game::Fn00938c50(TreeNode_shaped10_game* pNode)
{
    if (pNode) {
        do {
            Fn00938c50(pNode->mpRight);
            TreeNode_shaped10_game* pLeft = pNode->mpLeft;
            reinterpret_cast<Dtor414250_shaped10_game*>(pNode->mData)->Fn00414250();
            _STL::__stl_delete(pNode);
            pNode = pLeft;
        } while (pNode);
    }
}
#endif

// ---- table map over a range
struct View_ae4c14_shaped10_game {
    void Fn009eb410(uint16_t* pBegin, const uint16_t* pEnd);
    void Fn009eb470(uint16_t* pBegin, const uint16_t* pEnd);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009eb410 score 25
void View_ae4c14_shaped10_game::Fn009eb410(uint16_t* pBegin, const uint16_t* pEnd)
{
    if (pBegin < pEnd) {
        do {
            uint16_t c = *pBegin;
            if (c < 0x100) {
                c = g00ae5200[c];
            }
            *pBegin = c;
            ++pBegin;
        } while (pBegin < pEnd);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009eb470 score 25
void View_ae4c14_shaped10_game::Fn009eb470(uint16_t* pBegin, const uint16_t* pEnd)
{
    if (pBegin < pEnd) {
        do {
            uint16_t c = *pBegin;
            if (c < 0x100) {
                c = g00ae5300[c];
            }
            *pBegin = c;
            ++pBegin;
        } while (pBegin < pEnd);
    }
}
#endif

// ---- 15-bit colour blend through a lookup table
// GLOBAL: 0x00b63ee8
extern uint8_t g00b63ee8[];

// FUNCTION: 0x009854f0
uint32_t Fn009854f0(uint32_t a, uint32_t b, uint32_t t)
{
    uint32_t ga = (a >> 5) & 0x1f;
    uint32_t ra = a >> 10;
    uint32_t gb = (b >> 5) & 0x1f;
    uint32_t rb = b >> 10;
    uint32_t r = g00b63ee8[(((ra << 5) + rb) << 5) + t];
    uint32_t g = g00b63ee8[(((ga << 5) + gb) << 5) + t];
    uint32_t bl = g00b63ee8[((((a & 0x1f) << 5) + (b & 0x1f)) << 5) + t];
    return (((g | (r << 5)) << 5) | bl);
}

// FUNCTION: 0x00985560
uint32_t Fn00985560(uint32_t a, uint32_t b, uint32_t t)
{
    uint32_t ga = (a >> 6) & 0x1f;
    uint32_t ra = a >> 11;
    uint32_t gb = (b >> 6) & 0x1f;
    uint32_t rb = b >> 11;
    uint32_t r = g00b63ee8[(((ra << 5) + rb) << 5) + t];
    uint32_t g = g00b63ee8[(((ga << 5) + gb) << 5) + t];
    uint32_t bl = g00b63ee8[((((a & 0x1f) << 5) + (b & 0x1f)) << 5) + t];
    return (((g | (r << 5)) << 6) | bl);
}

// ---- interface lookup then a call, then release
struct Iface_shaped10_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03(uint32_t iid, Iface_shaped10_game** ppOut) = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08(uint32_t a) = 0;
};

struct Holder_shaped10_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03(Iface_shaped10_game* p) = 0;
};

struct View_98c590_shaped10_game {
    uint8_t pad[0xa0];
    Holder_shaped10_game* mpHolder;
    Iface_shaped10_game* mpSource;
    void Fn0098c590(uint32_t a);
    void Fn0098c5e0(uint32_t a);
};

// FUNCTION: 0x0098c590
void View_98c590_shaped10_game::Fn0098c590(uint32_t /*a*/)
{
    Iface_shaped10_game* p = 0;
    mpSource->Slot03(0xda1062fa, &p);
    p->Slot08(0xa);
    mpHolder->Slot03(p);
    if (p) {
        p->Slot02();
    }
}

// FUNCTION: 0x0098c5e0
void View_98c590_shaped10_game::Fn0098c5e0(uint32_t /*a*/)
{
    Iface_shaped10_game* p = 0;
    mpSource->Slot03(0xda1062fa, &p);
    p->Slot08(0x5);
    mpHolder->Slot03(p);
    if (p) {
        p->Slot02();
    }
}

// ---- guarded interface call with a computed argument
struct Iface2_shaped10_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03(uint32_t iid, Iface2_shaped10_game** ppOut) = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08(uint32_t kind, uint32_t b, uint32_t c) = 0;
};

struct Holder2_shaped10_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03(Iface2_shaped10_game* p) = 0;
};

// CLOSE draft: the original's helper pops 4 bytes of its two pushed arguments
// STUB: 0x0098b6e0
uint32_t Fn0098b6e0(uint32_t x, uint32_t y);

struct View_98c400_shaped10_game {
    uint8_t pad0[0x60];
    uint32_t mnDisabled;
    uint8_t pad1[0xa0 - 0x64];
    Holder2_shaped10_game* mpHolder;
    uint32_t pad2;
    Iface2_shaped10_game* mpSource;
    void Fn0098c400(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
    void Fn0098c480(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0098c400 score 55
void View_98c400_shaped10_game::Fn0098c400(uint32_t /*a*/, uint32_t b, uint32_t c, uint32_t d)
{
    if (mnDisabled == 0) {
        if (b != 0xe5) {
            Iface2_shaped10_game* p = 0;
            mpSource->Slot03(0x1a104742, &p);
            p->Slot08(5, b, Fn0098b6e0(d, c));
            mpHolder->Slot03(p);
            if (p) {
                p->Slot02();
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098c480 score 55
void View_98c400_shaped10_game::Fn0098c480(uint32_t /*a*/, uint32_t b, uint32_t c, uint32_t d)
{
    if (mnDisabled == 0) {
        if (b != 0xe5) {
            Iface2_shaped10_game* p = 0;
            mpSource->Slot03(0x1a104742, &p);
            p->Slot08(6, b, Fn0098b6e0(d, c));
            mpHolder->Slot03(p);
            if (p) {
                p->Slot02();
            }
        }
    }
}
#endif

// ---- results through a pair
struct Pair_shaped10_game {
    uint32_t first;
    uint32_t second;
};

// STUB: 0x009ddbf0
void Fn009ddbf0(Pair_shaped10_game* pOut, uint32_t* p1, uint32_t* p3, uint32_t a5, const uint8_t* pFlags, uint32_t* pTmp,
                uint32_t zero);
// STUB: 0x009ded40
void Fn009ded40(Pair_shaped10_game* pOut, uint32_t* p1, uint32_t* p3, uint32_t a5, const uint8_t* pFlags, uint32_t* pTmp,
                uint32_t zero);

struct View_de460_shaped10_game {
    Pair_shaped10_game Fn009de460(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, const uint8_t* pFlags,
                                  uint32_t* pOut);
    Pair_shaped10_game Fn009df600(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, const uint8_t* pFlags,
                                  uint32_t* pOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009de460 score 20
Pair_shaped10_game View_de460_shaped10_game::Fn009de460(uint32_t a1, uint32_t /*a2*/, uint32_t a3, uint32_t /*a4*/,
                                                       uint32_t a5, const uint8_t* pFlags, uint32_t* pOut)
{
    Pair_shaped10_game result;
    uint32_t tmp;
    Fn009ddbf0(&result, &a1, &a3, a5, pFlags, &tmp, 0);
    if (!(*pFlags & 4)) {
        *pOut = tmp;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009df600 score 20
Pair_shaped10_game View_de460_shaped10_game::Fn009df600(uint32_t a1, uint32_t /*a2*/, uint32_t a3, uint32_t /*a4*/,
                                                       uint32_t a5, const uint8_t* pFlags, uint32_t* pOut)
{
    Pair_shaped10_game result;
    uint32_t tmp;
    Fn009ded40(&result, &a1, &a3, a5, pFlags, &tmp, 0);
    if (!(*pFlags & 4)) {
        *pOut = tmp;
    }
    return result;
}
#endif
