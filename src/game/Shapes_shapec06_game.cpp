// Shape families of packet shapec06_game, written by scratch/s17/gen/shapec06_game/*.py.
#include <new>
#include "common/types.h"
#include "common/compiler.h"

// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t nBytes);

namespace _STL {
    // STUB: 0x0090cf54
    void* __stl_new(unsigned int n);
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

// GLOBAL: 0xb4bc5c
extern bool gb4bc5c_c06;

// FUNCTION: 0x00741750
bool Fn00741750()
{
    return gb4bc5c_c06;
}

// GLOBAL: 0xb4c741
extern bool gb4c741_c06;

// FUNCTION: 0x00752ae0
bool Fn00752ae0()
{
    return gb4c741_c06;
}

// GLOBAL: 0xb4dfd0
extern bool gb4dfd0_c06;

// FUNCTION: 0x0078c760
bool Fn0078c760()
{
    return gb4dfd0_c06;
}

struct View_0087e0a0_shapec06_game {
    uint32_t Fn();
};

// FUNCTION: 0x0087e0a0
uint32_t View_0087e0a0_shapec06_game::Fn()
{
    return 0xc4554841;
}

struct View_00886e00_shapec06_game {
    uint32_t Fn();
};

// FUNCTION: 0x00886e00
uint32_t View_00886e00_shapec06_game::Fn()
{
    return 0xbadb6906;
}

struct View_009ec390_shapec06_game {
    uint32_t Fn();
};

// FUNCTION: 0x009ec390
uint32_t View_009ec390_shapec06_game::Fn()
{
    return 0x1;
}

struct View_0098cc30_shapec06_game {
    uint8_t mPad0[0x4c];
    uint32_t mB;
    uint8_t mPad1[0x4];
    uint32_t mA;
    uint32_t Fn();
};

// FUNCTION: 0x0098cc30
uint32_t View_0098cc30_shapec06_game::Fn()
{
    return mA - mB;
}

struct View_0098cc40_shapec06_game {
    uint8_t mPad0[0x50];
    uint32_t mB;
    uint8_t mPad1[0x4];
    uint32_t mA;
    uint32_t Fn();
};

// FUNCTION: 0x0098cc40
uint32_t View_0098cc40_shapec06_game::Fn()
{
    return mA - mB;
}

struct View_006dc6c0_shapec06_game {
    uint8_t mPad0[0x188];
    uint32_t mA;
    uint32_t mB;
    uint32_t Fn();
};

// FUNCTION: 0x006dc6c0
uint32_t View_006dc6c0_shapec06_game::Fn()
{
    return mA - mB;
}

struct View_00801710_shapec06_game {
    void Fn(uint32_t v);
};

// FUNCTION: 0x00801710
void View_00801710_shapec06_game::Fn(uint32_t v)
{
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) - 0x10) = v;
}

struct View_008018a0_shapec06_game {
    void Fn(uint32_t v);
};

// FUNCTION: 0x008018a0
void View_008018a0_shapec06_game::Fn(uint32_t v)
{
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) - 0x24) = v;
}

struct View_008018f0_shapec06_game {
    void Fn(uint32_t v);
};

// FUNCTION: 0x008018f0
void View_008018f0_shapec06_game::Fn(uint32_t v)
{
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) - 0x1c) = v;
}

// GLOBAL: 0xb53c30
extern uint32_t gb53c30_c06;

// FUNCTION: 0x0086f990
void Fn0086f990(uint32_t v)
{
    gb53c30_c06 = v;
}

// GLOBAL: 0xb53c28
extern uint32_t gb53c28_c06;

// FUNCTION: 0x0086f9a0
void Fn0086f9a0(uint32_t v)
{
    gb53c28_c06 = v;
}

// GLOBAL: 0xb603d4
extern uint32_t gb603d4_c06;

// FUNCTION: 0x008e3140
void Fn008e3140(uint32_t v)
{
    gb603d4_c06 = v;
}

struct View_0080a580_shapec06_game {
    uint8_t mPad0[0x64];
    uint32_t mValue;
    // STUB: 0x80a0a0
    void Update();
    void Fn(uint32_t v);
};

// FUNCTION: 0x0080a580
void View_0080a580_shapec06_game::Fn(uint32_t v)
{
    mValue = v;
    Update();
}

struct View_007a6270_shapec06_game {
    uint8_t mPad0[0x9d4];
    uint32_t mValue;
    // STUB: 0x7a5610
    void Update();
    void Fn(uint32_t v);
};

// FUNCTION: 0x007a6270
void View_007a6270_shapec06_game::Fn(uint32_t v)
{
    mValue = v;
    Update();
}

struct View_007b30f0_shapec06_game {
    uint8_t mPad0[0x118];
    uint32_t mValue;
    // STUB: 0x7b29e0
    void Update();
    void Fn(uint32_t v);
};

// FUNCTION: 0x007b30f0
void View_007b30f0_shapec06_game::Fn(uint32_t v)
{
    mValue = v;
    Update();
}

struct Rec_007ddee0_shapec06_game {
    uint32_t m[10];
};

struct View_007ddee0_shapec06_game {
    uint8_t mPad0[0x18];
    Rec_007ddee0_shapec06_game* mpRecs;
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x007ddee0
uint32_t View_007ddee0_shapec06_game::Fn(uint32_t i)
{
    return mpRecs[i].m[7];
}

struct Rec_007ddf40_shapec06_game {
    uint32_t m[10];
};

struct View_007ddf40_shapec06_game {
    uint8_t mPad0[0x18];
    Rec_007ddf40_shapec06_game* mpRecs;
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x007ddf40
uint32_t View_007ddf40_shapec06_game::Fn(uint32_t i)
{
    return mpRecs[i].m[1];
}

struct Rec_007ddf60_shapec06_game {
    uint32_t m[10];
};

struct View_007ddf60_shapec06_game {
    uint8_t mPad0[0x24];
    Rec_007ddf60_shapec06_game* mpRecs;
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x007ddf60
uint32_t View_007ddf60_shapec06_game::Fn(uint32_t i)
{
    return mpRecs[i].m[1];
}

struct Iface_006ce140_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4(uint32_t v) = 0;
};

struct View_006ce140_shapec06_game {
    uint8_t mPad0[0x64];
    uint32_t mValue;
    void Fn(Iface_006ce140_shapec06_game* p);
};

// FUNCTION: 0x006ce140
void View_006ce140_shapec06_game::Fn(Iface_006ce140_shapec06_game* p)
{
    p->Slot4(mValue);
}

struct Iface_006ce180_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4(uint32_t v) = 0;
};

struct View_006ce180_shapec06_game {
    uint8_t mPad0[0x6c];
    uint32_t mValue;
    void Fn(Iface_006ce180_shapec06_game* p);
};

// FUNCTION: 0x006ce180
void View_006ce180_shapec06_game::Fn(Iface_006ce180_shapec06_game* p)
{
    p->Slot4(mValue);
}

struct Iface_006ce1c0_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4(uint32_t v) = 0;
};

struct View_006ce1c0_shapec06_game {
    uint8_t mPad0[0x74];
    uint32_t mValue;
    void Fn(Iface_006ce1c0_shapec06_game* p);
};

// FUNCTION: 0x006ce1c0
void View_006ce1c0_shapec06_game::Fn(Iface_006ce1c0_shapec06_game* p)
{
    p->Slot4(mValue);
}

struct View_0097cf60_shapec06_game {
    uint8_t mPad0[0x4];
    uint32_t mA;
    uint32_t mB;
    void Fn(const uint32_t* p);
};

// FUNCTION: 0x0097cf60
void View_0097cf60_shapec06_game::Fn(const uint32_t* p)
{
    mA = p[0];
    mB = p[1];
}

struct View_007a98a0_shapec06_game {
    uint8_t mPad0[0xf0];
    uint32_t mA;
    uint32_t mB;
    void Fn(const uint32_t* p);
};

// FUNCTION: 0x007a98a0
void View_007a98a0_shapec06_game::Fn(const uint32_t* p)
{
    mA = p[0];
    mB = p[1];
}

struct View_00872300_shapec06_game {
    uint8_t mPad0[0x98];
    uint32_t mA;
    uint32_t mB;
    void Fn(const uint32_t* p);
};

// FUNCTION: 0x00872300
void View_00872300_shapec06_game::Fn(const uint32_t* p)
{
    mA = p[0];
    mB = p[1];
}

struct Out_00777cc0_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9(uint32_t a, void* b, uint32_t c) = 0;
};

struct Mid_00777cc0_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual Out_00777cc0_shapec06_game* Slot6() = 0;
};

struct View_00777cc0_shapec06_game {
    uint8_t mPad0[0xc];
    Mid_00777cc0_shapec06_game* mpMid;
    void Fn();
};

// FUNCTION: 0x00777cc0
void View_00777cc0_shapec06_game::Fn()
{
    mpMid->Slot6()->Slot9(0xf, mpMid, 0xffffffff);
}

struct Out_00777cf0_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9(uint32_t a, void* b, uint32_t c) = 0;
};

struct Mid_00777cf0_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual Out_00777cf0_shapec06_game* Slot6() = 0;
};

struct View_00777cf0_shapec06_game {
    uint8_t mPad0[0xc];
    Mid_00777cf0_shapec06_game* mpMid;
    void Fn();
};

// FUNCTION: 0x00777cf0
void View_00777cf0_shapec06_game::Fn()
{
    mpMid->Slot6()->Slot9(0xf, mpMid, 0x0);
}

struct Out_00777d10_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9(uint32_t a, void* b, uint32_t c) = 0;
};

struct Mid_00777d10_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual Out_00777d10_shapec06_game* Slot6() = 0;
};

struct View_00777d10_shapec06_game {
    uint8_t mPad0[0xc];
    Mid_00777d10_shapec06_game* mpMid;
    void Fn();
};

// FUNCTION: 0x00777d10
void View_00777d10_shapec06_game::Fn()
{
    mpMid->Slot6()->Slot9(0xf, mpMid, 0x1);
}

struct Src_006ad170_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void* Slot6(uint32_t k, uint32_t v) = 0;
};

// STUB: 0x5fe3c0
uint32_t Fn5fe3c0_006ad170(void* p, uint32_t k, uint32_t v);

struct View_006ad170_shapec06_game {
    uint32_t Fn(Src_006ad170_shapec06_game* pSrc, uint32_t v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006ad170 score 2
uint32_t View_006ad170_shapec06_game::Fn(Src_006ad170_shapec06_game* pSrc, uint32_t v)
{
    return Fn5fe3c0_006ad170(pSrc->Slot6(0x69b425dd, v), 0x69b425dd, v);
}
#endif

struct Src_006ad190_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void* Slot6(uint32_t k, uint32_t v) = 0;
};

// STUB: 0x5fe3c0
uint32_t Fn5fe3c0_006ad190(void* p, uint32_t k, uint32_t v);

struct View_006ad190_shapec06_game {
    uint32_t Fn(Src_006ad190_shapec06_game* pSrc, uint32_t v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006ad190 score 2
uint32_t View_006ad190_shapec06_game::Fn(Src_006ad190_shapec06_game* pSrc, uint32_t v)
{
    return Fn5fe3c0_006ad190(pSrc->Slot6(0x69b425de, v), 0x69b425de, v);
}
#endif

struct Src_006eb110_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void* Slot6(uint32_t k, uint32_t v) = 0;
};

// STUB: 0x5fd480
uint32_t Fn5fd480_006eb110(void* p, uint32_t k, uint32_t v);

struct View_006eb110_shapec06_game {
    uint32_t Fn(Src_006eb110_shapec06_game* pSrc, uint32_t v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006eb110 score 2
uint32_t View_006eb110_shapec06_game::Fn(Src_006eb110_shapec06_game* pSrc, uint32_t v)
{
    return Fn5fd480_006eb110(pSrc->Slot6(0x27812852, v), 0x27812852, v);
}
#endif

#ifdef _MSC_VER
#pragma optimize("s", on)
#endif

#ifdef _MSC_VER
#pragma optimize("s", on)
#endif

struct Head_00936480_shapec06_game {
    uint8_t mHead[0x3c];
};

struct Second_00936480_shapec06_game {
    uint32_t mSecond;
};

struct Obj_00936480_shapec06_game : Head_00936480_shapec06_game, Second_00936480_shapec06_game {
    // STUB: 0x9363f5
    Obj_00936480_shapec06_game* Ctor();
};

// FUNCTION: 0x00936480
Second_00936480_shapec06_game* Fn00936480()
{
    void* p = Fn005e55e0(0x68);
    Obj_00936480_shapec06_game* r;
    if (p) {
        r = static_cast<Obj_00936480_shapec06_game*>(p)->Ctor();
    } else {
        r = 0;
    }
    return r;
}

struct Head_00998a40_shapec06_game {
    uint8_t mHead[0x4];
};

struct Second_00998a40_shapec06_game {
    uint32_t mSecond;
};

struct Obj_00998a40_shapec06_game : Head_00998a40_shapec06_game, Second_00998a40_shapec06_game {
    // STUB: 0x9a57c4
    Obj_00998a40_shapec06_game* Ctor();
};

// FUNCTION: 0x00998a40
Second_00998a40_shapec06_game* Fn00998a40()
{
    void* p = Fn005e55e0(0x364);
    Obj_00998a40_shapec06_game* r;
    if (p) {
        r = static_cast<Obj_00998a40_shapec06_game*>(p)->Ctor();
    } else {
        r = 0;
    }
    return r;
}

struct Head_008747b0_shapec06_game {
    uint8_t mHead[0x8];
};

struct Second_008747b0_shapec06_game {
    uint32_t mSecond;
};

struct Obj_008747b0_shapec06_game : Head_008747b0_shapec06_game, Second_008747b0_shapec06_game {
    // STUB: 0x87517f
    Obj_008747b0_shapec06_game* Ctor();
};

// FUNCTION: 0x008747b0
Second_008747b0_shapec06_game* Fn008747b0()
{
    void* p = Fn005e55e0(0xa0);
    Obj_008747b0_shapec06_game* r;
    if (p) {
        r = static_cast<Obj_008747b0_shapec06_game*>(p)->Ctor();
    } else {
        r = 0;
    }
    return r;
}

#ifdef _MSC_VER
#pragma optimize("", on)
#endif

#ifdef _MSC_VER
#pragma optimize("", on)
#endif

struct Ord_0080d3e0_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual bool Slot19() = 0;
};

struct Sim_0080d3e0_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
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
    virtual Ord_0080d3e0_shapec06_game* Slot20(uint32_t id) = 0;
};

struct View_0080d3e0_shapec06_game {
    uint32_t Fn(uint32_t id);
};

// FUNCTION: 0x0080d3e0
uint32_t View_0080d3e0_shapec06_game::Fn(uint32_t id)
{
    Ord_0080d3e0_shapec06_game* p = reinterpret_cast<Sim_0080d3e0_shapec06_game*>(this)->Slot20(id);
    if (p) {
        if (p->Slot19()) {
            return 1;
        }
    }
    return 0;
}

struct Ord_0080d440_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual bool Slot17() = 0;
};

struct Sim_0080d440_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
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
    virtual Ord_0080d440_shapec06_game* Slot20(uint32_t id) = 0;
};

struct View_0080d440_shapec06_game {
    uint32_t Fn(uint32_t id);
};

// FUNCTION: 0x0080d440
uint32_t View_0080d440_shapec06_game::Fn(uint32_t id)
{
    Ord_0080d440_shapec06_game* p = reinterpret_cast<Sim_0080d440_shapec06_game*>(this)->Slot20(id);
    if (p) {
        if (p->Slot17()) {
            return 1;
        }
    }
    return 0;
}

struct Ord_0080d470_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual bool Slot18() = 0;
};

struct Sim_0080d470_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
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
    virtual Ord_0080d470_shapec06_game* Slot20(uint32_t id) = 0;
};

struct View_0080d470_shapec06_game {
    uint32_t Fn(uint32_t id);
};

// FUNCTION: 0x0080d470
uint32_t View_0080d470_shapec06_game::Fn(uint32_t id)
{
    Ord_0080d470_shapec06_game* p = reinterpret_cast<Sim_0080d470_shapec06_game*>(this)->Slot20(id);
    if (p) {
        if (p->Slot18()) {
            return 1;
        }
    }
    return 0;
}

struct View_006acb30_shapec06_game {
    bool Fn(uint32_t /*a*/, uint32_t* pA, uint32_t* pB, uint32_t* pC, uint32_t /*e*/);
};

// FUNCTION: 0x006acb30
bool View_006acb30_shapec06_game::Fn(uint32_t /*a*/, uint32_t* pA, uint32_t* pB, uint32_t* pC, uint32_t /*e*/)
{
    *pA = 0x4303;
    pB[0] = 0;
    pB[1] = 0;
    pB[2] = 0;
    *pC = 0x11882;
    return true;
}

struct View_006dfac0_shapec06_game {
    bool Fn(uint32_t /*a*/, uint32_t* pA, uint32_t* pB, uint32_t* pC, uint32_t /*e*/);
};

// FUNCTION: 0x006dfac0
bool View_006dfac0_shapec06_game::Fn(uint32_t /*a*/, uint32_t* pA, uint32_t* pB, uint32_t* pC, uint32_t /*e*/)
{
    *pA = 0x4301;
    pB[0] = 0;
    pB[1] = 0;
    pB[2] = 0;
    *pC = 0x11882;
    return true;
}

struct View_006ad5b0_shapec06_game {
    bool Fn(uint32_t /*a*/, uint32_t* pA, uint32_t* pB, uint32_t* pC, uint32_t /*e*/);
};

// FUNCTION: 0x006ad5b0
bool View_006ad5b0_shapec06_game::Fn(uint32_t /*a*/, uint32_t* pA, uint32_t* pB, uint32_t* pC, uint32_t /*e*/)
{
    *pA = 0x4202;
    pB[0] = 0;
    pB[1] = 0;
    pB[2] = 0;
    *pC = 0x11882;
    return true;
}

struct Elem_009b9a30_shapec06_game {
    uint8_t mData[0x28];
    // STUB: 0x9b974e
    void Init(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009b9a30 score 20
Elem_009b9a30_shapec06_game* Fn009b9a30(Elem_009b9a30_shapec06_game* p, uint32_t n, uint32_t a)
{
    for (; n > 0; --n) {
        if (p) {
            p->Init(a);
        }
        ++p;
    }
    return p;
}
#endif

struct Elem_008d6230_shapec06_game {
    uint8_t mData[0x2c];
    // STUB: 0x8d3c38
    void Init(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008d6230 score 20
Elem_008d6230_shapec06_game* Fn008d6230(Elem_008d6230_shapec06_game* p, uint32_t n, uint32_t a)
{
    for (; n > 0; --n) {
        if (p) {
            p->Init(a);
        }
        ++p;
    }
    return p;
}
#endif

struct Elem_00875120_shapec06_game {
    uint8_t mData[0x2c];
    // STUB: 0x8750ae
    void Init(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00875120 score 20
Elem_00875120_shapec06_game* Fn00875120(Elem_00875120_shapec06_game* p, uint32_t n, uint32_t a)
{
    for (; n > 0; --n) {
        if (p) {
            p->Init(a);
        }
        ++p;
    }
    return p;
}
#endif

// STUB: 0x8d0660
void Fn8d0660_008d0860(const void* a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, uint32_t a7);

// FUNCTION: 0x008d0860
void Fn008d0860(void* a0, uint32_t a1, const void* a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6)
{
    Fn8d0660_008d0860(a2, a3, a0, a1, a4, a5, a6, 0xfff0fff);
}

// STUB: 0x8d0660
void Fn8d0660_008d0820(const void* a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, uint32_t a7);

// FUNCTION: 0x008d0820
void Fn008d0820(void* a0, uint32_t a1, const void* a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6)
{
    Fn8d0660_008d0820(a2, a3, a0, a1, a4, a5, a6, 0x7fff7fff);
}

// STUB: 0x8d0750
void Fn8d0750_008d08a0(const void* a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, uint32_t a7);

// FUNCTION: 0x008d08a0
void Fn008d08a0(void* a0, uint32_t a1, const void* a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6)
{
    Fn8d0750_008d08a0(a2, a3, a0, a1, a4, a5, a6, 0xffffff);
}

struct Payload_00719250_shapec06_game {
    // STUB: 0x713f90
    void Init(uint32_t v);
};

struct Node_00719250_shapec06_game {
    Node_00719250_shapec06_game* mpNext;
    Node_00719250_shapec06_game* mpPrev;
    Payload_00719250_shapec06_game mData;
};

struct View_00719250_shapec06_game {
    Node_00719250_shapec06_game* mpHead;
    void Fn(uint32_t v);
};

// FUNCTION: 0x00719250
void View_00719250_shapec06_game::Fn(uint32_t v)
{
    Node_00719250_shapec06_game* pHead = mpHead;
    Node_00719250_shapec06_game* pNode = static_cast<Node_00719250_shapec06_game*>(_STL::__stl_new(0x34));
    Payload_00719250_shapec06_game* pData = reinterpret_cast<Payload_00719250_shapec06_game*>(reinterpret_cast<uint8_t*>(pNode) + 8);
    if (pData) {
        pData->Init(v);
    }
    Node_00719250_shapec06_game* pPrev = pHead->mpPrev;
    pNode->mpNext = pHead;
    pNode->mpPrev = pPrev;
    pPrev->mpNext = pNode;
    pHead->mpPrev = pNode;
}

struct Payload_00721950_shapec06_game {
    // STUB: 0x71e0e0
    void Init(uint32_t v);
};

struct Node_00721950_shapec06_game {
    Node_00721950_shapec06_game* mpNext;
    Node_00721950_shapec06_game* mpPrev;
    Payload_00721950_shapec06_game mData;
};

struct View_00721950_shapec06_game {
    Node_00721950_shapec06_game* mpHead;
    void Fn(uint32_t v);
};

// FUNCTION: 0x00721950
void View_00721950_shapec06_game::Fn(uint32_t v)
{
    Node_00721950_shapec06_game* pHead = mpHead;
    Node_00721950_shapec06_game* pNode = static_cast<Node_00721950_shapec06_game*>(_STL::__stl_new(0x28));
    Payload_00721950_shapec06_game* pData = reinterpret_cast<Payload_00721950_shapec06_game*>(reinterpret_cast<uint8_t*>(pNode) + 8);
    if (pData) {
        pData->Init(v);
    }
    Node_00721950_shapec06_game* pPrev = pHead->mpPrev;
    pNode->mpNext = pHead;
    pNode->mpPrev = pPrev;
    pPrev->mpNext = pNode;
    pHead->mpPrev = pNode;
}

struct Payload_0081dde0_shapec06_game {
    // STUB: 0x81db10
    void Init(uint32_t v);
};

struct Node_0081dde0_shapec06_game {
    Node_0081dde0_shapec06_game* mpNext;
    Node_0081dde0_shapec06_game* mpPrev;
    Payload_0081dde0_shapec06_game mData;
};

struct View_0081dde0_shapec06_game {
    Node_0081dde0_shapec06_game* mpHead;
    void Fn(uint32_t v);
};

// FUNCTION: 0x0081dde0
void View_0081dde0_shapec06_game::Fn(uint32_t v)
{
    Node_0081dde0_shapec06_game* pHead = mpHead;
    Node_0081dde0_shapec06_game* pNode = static_cast<Node_0081dde0_shapec06_game*>(_STL::__stl_new(0x34));
    Payload_0081dde0_shapec06_game* pData = reinterpret_cast<Payload_0081dde0_shapec06_game*>(reinterpret_cast<uint8_t*>(pNode) + 8);
    if (pData) {
        pData->Init(v);
    }
    Node_0081dde0_shapec06_game* pPrev = pHead->mpPrev;
    pNode->mpNext = pHead;
    pNode->mpPrev = pPrev;
    pPrev->mpNext = pNode;
    pHead->mpPrev = pNode;
}

struct Obj_00648500_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual bool Slot9(uint32_t flags) = 0;
};

struct View_00648500_shapec06_game {
    void Fn(uint32_t* pOut);
};

// FUNCTION: 0x00648500
void View_00648500_shapec06_game::Fn(uint32_t* pOut)
{
    Obj_00648500_shapec06_game* pObj = reinterpret_cast<Obj_00648500_shapec06_game*>(reinterpret_cast<uint8_t*>(this) - 0x27c);
    if (pObj->Slot9(0x6000000)) {
        *pOut = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) - 0x180);
    } else {
        *pOut = 0x49c05b9f;
    }
}

struct Obj_00652d30_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual bool Slot9(uint32_t flags) = 0;
};

struct View_00652d30_shapec06_game {
    void Fn(uint32_t* pOut);
};

// FUNCTION: 0x00652d30
void View_00652d30_shapec06_game::Fn(uint32_t* pOut)
{
    Obj_00652d30_shapec06_game* pObj = reinterpret_cast<Obj_00652d30_shapec06_game*>(reinterpret_cast<uint8_t*>(this) - 0x2d4);
    if (pObj->Slot9(0x6000000)) {
        *pOut = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) - 0x1d8);
    } else {
        *pOut = 0xca16374f;
    }
}

struct Obj_0065a0e0_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual bool Slot9(uint32_t flags) = 0;
};

struct View_0065a0e0_shapec06_game {
    void Fn(uint32_t* pOut);
};

// FUNCTION: 0x0065a0e0
void View_0065a0e0_shapec06_game::Fn(uint32_t* pOut)
{
    Obj_0065a0e0_shapec06_game* pObj = reinterpret_cast<Obj_0065a0e0_shapec06_game*>(reinterpret_cast<uint8_t*>(this) - 0x274);
    if (pObj->Slot9(0x6000000)) {
        *pOut = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) - 0x178);
    } else {
        *pOut = 0x4a10afc2;
    }
}

struct Rec_c06 {
    uint32_t m[11];
};

struct DispMgr_c06 {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual bool Slot10(void* pOcc, Rec_c06* pRec) = 0;
};

// GLOBAL: 0x00b43d04
extern DispMgr_c06* gpb43d04_c06;

struct View_006acaf0_shapec06_game {
    // STUB: 0x6ac7c0
    void Ret(uint32_t a, uint32_t b);
    void Fn(void* pOcc);
};

// FUNCTION: 0x006acaf0
void View_006acaf0_shapec06_game::Fn(void* pOcc)
{
    if (gpb43d04_c06) {
        Rec_c06 rec;
        if (gpb43d04_c06->Slot10(pOcc, &rec)) {
            Ret(rec.m[8], rec.m[2]);
        }
    }
}

struct View_006df9c0_shapec06_game {
    // STUB: 0x6df820
    void Ret(uint32_t a, uint32_t b);
    void Fn(void* pOcc);
};

// FUNCTION: 0x006df9c0
void View_006df9c0_shapec06_game::Fn(void* pOcc)
{
    if (gpb43d04_c06) {
        Rec_c06 rec;
        if (gpb43d04_c06->Slot10(pOcc, &rec)) {
            Ret(rec.m[8], rec.m[2]);
        }
    }
}

struct View_006f5a40_shapec06_game {
    // STUB: 0x6f5620
    void Ret(uint32_t a, uint32_t b);
    void Fn(void* pOcc);
};

// FUNCTION: 0x006f5a40
void View_006f5a40_shapec06_game::Fn(void* pOcc)
{
    if (gpb43d04_c06) {
        Rec_c06 rec;
        if (gpb43d04_c06->Slot10(pOcc, &rec)) {
            Ret(rec.m[8], rec.m[2]);
        }
    }
}

struct Obj_00880000_shapec06_game {
    virtual bool Slot0(uint32_t a, uint32_t b) = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    // STUB: 0x8b6480
    Obj_00880000_shapec06_game* Ctor();
};

// FUNCTION: 0x00880000
bool Fn00880000(uint32_t a, uint32_t b)
{
    void* p = Fn005e55e0(0x58);
    Obj_00880000_shapec06_game* pObj;
    if (p) {
        pObj = static_cast<Obj_00880000_shapec06_game*>(p)->Ctor();
    } else {
        pObj = 0;
    }
    pObj->Slot1();
    bool bResult = pObj->Slot0(a, b);
    pObj->Slot2();
    return bResult;
}

struct Obj_008800a0_shapec06_game {
    virtual bool Slot0(uint32_t a, uint32_t b) = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    // STUB: 0x8809e0
    Obj_008800a0_shapec06_game* Ctor();
};

// FUNCTION: 0x008800a0
bool Fn008800a0(uint32_t a, uint32_t b)
{
    void* p = Fn005e55e0(0x58);
    Obj_008800a0_shapec06_game* pObj;
    if (p) {
        pObj = static_cast<Obj_008800a0_shapec06_game*>(p)->Ctor();
    } else {
        pObj = 0;
    }
    pObj->Slot1();
    bool bResult = pObj->Slot0(a, b);
    pObj->Slot2();
    return bResult;
}

struct Obj_00880050_shapec06_game {
    virtual bool Slot0(uint32_t a, uint32_t b) = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    // STUB: 0x8b8dd0
    Obj_00880050_shapec06_game* Ctor();
};

// FUNCTION: 0x00880050
bool Fn00880050(uint32_t a, uint32_t b)
{
    void* p = Fn005e55e0(0x1c);
    Obj_00880050_shapec06_game* pObj;
    if (p) {
        pObj = static_cast<Obj_00880050_shapec06_game*>(p)->Ctor();
    } else {
        pObj = 0;
    }
    pObj->Slot1();
    bool bResult = pObj->Slot0(a, b);
    pObj->Slot2();
    return bResult;
}

// STUB: 0x0090ffc8
void memset16(void* pDst, uint16_t value, uint32_t n);

struct Surf_008310b0_shapec06_game {
    uint8_t* mpBase;
    uint32_t mPitch;
};

struct View_008310b0_shapec06_game {
    void Fn(const uint32_t* pRec, uint32_t n, const Surf_008310b0_shapec06_game* pSurf, uint16_t color);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008310b0 score 17
void View_008310b0_shapec06_game::Fn(const uint32_t* pRec, uint32_t n, const Surf_008310b0_shapec06_game* pSurf, uint16_t color)
{
    do {
        memset16(pSurf->mpBase + (pRec[0] >> 16) * pSurf->mPitch + (pRec[0] & 0xffff) * 2, color, pRec[1] - pRec[0]);
        pRec += 2;
        --n;
    } while (n);
}
#endif

struct Surf_0083de50_shapec06_game {
    uint8_t* mpBase;
    uint32_t mPitch;
};

struct View_0083de50_shapec06_game {
    void Fn(const uint32_t* pRec, uint32_t n, const Surf_0083de50_shapec06_game* pSurf, uint16_t color);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0083de50 score 17
void View_0083de50_shapec06_game::Fn(const uint32_t* pRec, uint32_t n, const Surf_0083de50_shapec06_game* pSurf, uint16_t color)
{
    do {
        memset16(pSurf->mpBase + (pRec[0] >> 16) * pSurf->mPitch + (pRec[0] & 0xffff) * 2, color, pRec[1] - pRec[0]);
        pRec += 2;
        --n;
    } while (n);
}
#endif

struct Surf_00847ce0_shapec06_game {
    uint8_t* mpBase;
    uint32_t mPitch;
};

struct View_00847ce0_shapec06_game {
    void Fn(const uint32_t* pRec, uint32_t n, const Surf_00847ce0_shapec06_game* pSurf, uint16_t color);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00847ce0 score 17
void View_00847ce0_shapec06_game::Fn(const uint32_t* pRec, uint32_t n, const Surf_00847ce0_shapec06_game* pSurf, uint16_t color)
{
    do {
        memset16(pSurf->mpBase + (pRec[0] >> 16) * pSurf->mPitch + (pRec[0] & 0xffff) * 2, color, pRec[1] - pRec[0]);
        pRec += 2;
        --n;
    } while (n);
}
#endif

struct Var_00665c30_shapec06_game {
    // STUB: 0x915eb5
    void Dtor();
};

struct View_00665c30_shapec06_game {
    uint32_t mVt;
    uint8_t mPad0[0xd4];
    uint32_t mVt2;
    Var_00665c30_shapec06_game mVar;
    uint8_t mPad1[0x100 - 0xdc - 1];
    void* mpBuf;
    // STUB: 0x99e1a2
    void Base();
    void Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00665c30 score 4
void View_00665c30_shapec06_game::Fn()
{
    mVt = 0xaad6a8;
    mVt2 = 0xaad684;
    if (mpBuf) {
        _STL::__stl_delete(mpBuf);
    }
    mVt = 0xaab558;
    mVt2 = 0xaab530;
    mVar.Dtor();
    Base();
}
#endif

struct Var_00687e80_shapec06_game {
    // STUB: 0x915eb5
    void Dtor();
};

struct View_00687e80_shapec06_game {
    uint32_t mVt;
    uint8_t mPad0[0xd4];
    uint32_t mVt2;
    Var_00687e80_shapec06_game mVar;
    uint8_t mPad1[0x100 - 0xdc - 1];
    void* mpBuf;
    // STUB: 0x99e1a2
    void Base();
    void Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00687e80 score 4
void View_00687e80_shapec06_game::Fn()
{
    mVt = 0xab01a8;
    mVt2 = 0xab0184;
    if (mpBuf) {
        _STL::__stl_delete(mpBuf);
    }
    mVt = 0xaab558;
    mVt2 = 0xaab530;
    mVar.Dtor();
    Base();
}
#endif

struct Var_00687ef0_shapec06_game {
    // STUB: 0x915eb5
    void Dtor();
};

struct View_00687ef0_shapec06_game {
    uint32_t mVt;
    uint8_t mPad0[0xd4];
    uint32_t mVt2;
    Var_00687ef0_shapec06_game mVar;
    uint8_t mPad1[0x100 - 0xdc - 1];
    void* mpBuf;
    // STUB: 0x99e1a2
    void Base();
    void Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00687ef0 score 4
void View_00687ef0_shapec06_game::Fn()
{
    mVt = 0xab0428;
    mVt2 = 0xab0404;
    if (mpBuf) {
        _STL::__stl_delete(mpBuf);
    }
    mVt = 0xaab558;
    mVt2 = 0xaab530;
    mVar.Dtor();
    Base();
}
#endif

struct Node_007606f0_shapec06_game {
    Node_007606f0_shapec06_game* mpNext;
    Node_007606f0_shapec06_game* mpPrev;
    void* mpA;
    uint8_t mPad0[0x24];
    void* mpB;
};

struct View_007606f0_shapec06_game {
    Node_007606f0_shapec06_game* mpHead;
    void Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x007606f0 score 4
void View_007606f0_shapec06_game::Fn()
{
    Node_007606f0_shapec06_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_007606f0_shapec06_game* pCur = pNode;
        void* pB = pCur->mpB;
        pNode = pNode->mpNext;
        if (pB) {
            _STL::__stl_delete(pB);
        }
        if (pCur->mpA) {
            _STL::__stl_delete(pCur->mpA);
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}
#endif

struct Node_006c0ff0_shapec06_game {
    Node_006c0ff0_shapec06_game* mpNext;
    Node_006c0ff0_shapec06_game* mpPrev;
    void* mpA;
    uint8_t mPad0[0x8];
    void* mpB;
};

struct View_006c0ff0_shapec06_game {
    Node_006c0ff0_shapec06_game* mpHead;
    void Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x006c0ff0 score 4
void View_006c0ff0_shapec06_game::Fn()
{
    Node_006c0ff0_shapec06_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_006c0ff0_shapec06_game* pCur = pNode;
        void* pB = pCur->mpB;
        pNode = pNode->mpNext;
        if (pB) {
            _STL::__stl_delete(pB);
        }
        if (pCur->mpA) {
            _STL::__stl_delete(pCur->mpA);
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}
#endif

struct Node_00714660_shapec06_game {
    Node_00714660_shapec06_game* mpNext;
    Node_00714660_shapec06_game* mpPrev;
    uint8_t mPad0[0xc];
    void* mpA;
    uint8_t mPad1[0x8];
    void* mpB;
};

struct View_00714660_shapec06_game {
    Node_00714660_shapec06_game* mpHead;
    void Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00714660 score 4
void View_00714660_shapec06_game::Fn()
{
    Node_00714660_shapec06_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_00714660_shapec06_game* pCur = pNode;
        void* pB = pCur->mpB;
        pNode = pNode->mpNext;
        if (pB) {
            _STL::__stl_delete(pB);
        }
        if (pCur->mpA) {
            _STL::__stl_delete(pCur->mpA);
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}
#endif

struct Head_00665c80_shapec06_game {
    uint32_t mVt;
    uint8_t mPad0[0xd4];
};

struct Sub_00665c80_shapec06_game {
    uint32_t mVt2;
    uint8_t mPad1[0x24];
    uint32_t mA;
    uint32_t mB;
    uint32_t mC;
};

struct Obj_00665c80_shapec06_game : Head_00665c80_shapec06_game, Sub_00665c80_shapec06_game {
    // STUB: 0x687c20
    void Ctor();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00665c80 score 4
Sub_00665c80_shapec06_game* Fn00665c80()
{
    Obj_00665c80_shapec06_game* p = static_cast<Obj_00665c80_shapec06_game*>(Fn005e55e0(0x10c));
    if (p) {
        p->Ctor();
        p->mVt = 0xaad6a8;
        p->mVt2 = 0xaad684;
        p->mA = 0;
        p->mB = 0;
        p->mC = 0;
        return p;
    }
    return 0;
}
#endif

struct Head_00687f40_shapec06_game {
    uint32_t mVt;
    uint8_t mPad0[0xd4];
};

struct Sub_00687f40_shapec06_game {
    uint32_t mVt2;
    uint8_t mPad1[0x24];
    uint32_t mA;
    uint32_t mB;
    uint32_t mC;
};

struct Obj_00687f40_shapec06_game : Head_00687f40_shapec06_game, Sub_00687f40_shapec06_game {
    // STUB: 0x687c20
    void Ctor();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00687f40 score 4
Sub_00687f40_shapec06_game* Fn00687f40()
{
    Obj_00687f40_shapec06_game* p = static_cast<Obj_00687f40_shapec06_game*>(Fn005e55e0(0x10c));
    if (p) {
        p->Ctor();
        p->mVt = 0xab01a8;
        p->mVt2 = 0xab0184;
        p->mA = 0;
        p->mB = 0;
        p->mC = 0;
        return p;
    }
    return 0;
}
#endif

struct Head_00687fa0_shapec06_game {
    uint32_t mVt;
    uint8_t mPad0[0xd4];
};

struct Sub_00687fa0_shapec06_game {
    uint32_t mVt2;
    uint8_t mPad1[0x24];
    uint32_t mA;
    uint32_t mB;
    uint32_t mC;
};

struct Obj_00687fa0_shapec06_game : Head_00687fa0_shapec06_game, Sub_00687fa0_shapec06_game {
    // STUB: 0x687c20
    void Ctor();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00687fa0 score 4
Sub_00687fa0_shapec06_game* Fn00687fa0()
{
    Obj_00687fa0_shapec06_game* p = static_cast<Obj_00687fa0_shapec06_game*>(Fn005e55e0(0x10c));
    if (p) {
        p->Ctor();
        p->mVt = 0xab0428;
        p->mVt2 = 0xab0404;
        p->mA = 0;
        p->mB = 0;
        p->mC = 0;
        return p;
    }
    return 0;
}
#endif

struct View3D_00741830_shapec06_game {
    // STUB: 0x752af0
    void SetIndices(int32_t a, int32_t b);
};

struct Cell_00741830_shapec06_game {
    uint8_t m[0x24];
};

struct View_00741830_shapec06_game {
    uint8_t mPad0[0x28];
    uint32_t mW;
    uint32_t mH;
    uint8_t mPad1[0x8];
    uint32_t mStride;
    uint8_t mPad2[0x30];
    Cell_00741830_shapec06_game* mpCells;
    uint8_t mPad3[0x78];
    View3D_00741830_shapec06_game* mpView;
    bool mbView;
    void Fn(uint32_t x, uint32_t y, bool b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00741830 score 18
void View_00741830_shapec06_game::Fn(uint32_t x, uint32_t y, bool b)
{
    if (x < mW && y < mH) {
        uint8_t* pFlag = &mpCells[mStride * y + x].m[0x22];
        if (b) {
            *pFlag |= 0x20;
        } else {
            *pFlag &= 0xdf;
        }
        if (mbView) {
            mpView->SetIndices(y, x);
        }
    }
}
#endif

struct View3D_00741890_shapec06_game {
    // STUB: 0x752af0
    void SetIndices(int32_t a, int32_t b);
};

struct Cell_00741890_shapec06_game {
    uint8_t m[0x24];
};

struct View_00741890_shapec06_game {
    uint8_t mPad0[0x28];
    uint32_t mW;
    uint32_t mH;
    uint8_t mPad1[0x8];
    uint32_t mStride;
    uint8_t mPad2[0x30];
    Cell_00741890_shapec06_game* mpCells;
    uint8_t mPad3[0x78];
    View3D_00741890_shapec06_game* mpView;
    bool mbView;
    void Fn(uint32_t x, uint32_t y, bool b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00741890 score 18
void View_00741890_shapec06_game::Fn(uint32_t x, uint32_t y, bool b)
{
    if (x < mW && y < mH) {
        uint8_t* pFlag = &mpCells[mStride * y + x].m[0x22];
        if (b) {
            *pFlag |= 0x40;
        } else {
            *pFlag &= 0xbf;
        }
        if (mbView) {
            mpView->SetIndices(y, x);
        }
    }
}
#endif

struct View3D_007418f0_shapec06_game {
    // STUB: 0x752af0
    void SetIndices(int32_t a, int32_t b);
};

struct Cell_007418f0_shapec06_game {
    uint8_t m[0x24];
};

struct View_007418f0_shapec06_game {
    uint8_t mPad0[0x28];
    uint32_t mW;
    uint32_t mH;
    uint8_t mPad1[0x8];
    uint32_t mStride;
    uint8_t mPad2[0x30];
    Cell_007418f0_shapec06_game* mpCells;
    uint8_t mPad3[0x78];
    View3D_007418f0_shapec06_game* mpView;
    bool mbView;
    void Fn(uint32_t x, uint32_t y, bool b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007418f0 score 18
void View_007418f0_shapec06_game::Fn(uint32_t x, uint32_t y, bool b)
{
    if (x < mW && y < mH) {
        uint8_t* pFlag = &mpCells[mStride * y + x].m[0x22];
        if (b) {
            *pFlag |= 0x60;
        } else {
            *pFlag &= 0x9f;
        }
        if (mbView) {
            mpView->SetIndices(y, x);
        }
    }
}
#endif

// FUNCTION: 0x00827ed0
void Fn00827ed0(uint32_t w, uint32_t rows, uint8_t* pDst, uint32_t dstStride, uint32_t /*a5*/, uint32_t /*a6*/, uint32_t /*a7*/, uint32_t /*a8*/, const uint8_t* pSrc, uint32_t srcStride, uint32_t /*a11*/, uint32_t /*a12*/, uint32_t /*a13*/, uint32_t /*a14*/, uint32_t /*a15*/, uint32_t /*a16*/, uint32_t /*a17*/, uint32_t /*a18*/, uint32_t /*a19*/, uint32_t /*a20*/, uint32_t key)
{
    do {
        uint16_t* pD = reinterpret_cast<uint16_t*>(pDst);
        intptr_t delta = reinterpret_cast<intptr_t>(pSrc) - reinterpret_cast<intptr_t>(pD);
        uint32_t n = w;
        do {
            uint32_t v = *reinterpret_cast<const uint16_t*>(reinterpret_cast<intptr_t>(pD) + delta);
            if ((v & 0xffff) != key) {
                *pD = static_cast<uint16_t>(v);
            }
            ++pD;
            --n;
        } while (n);
        pDst += dstStride;
        pSrc += srcStride;
        --rows;
    } while (rows);
}

// FUNCTION: 0x00828360
void Fn00828360(uint32_t w, uint32_t rows, uint8_t* pDst, uint32_t dstStride, uint32_t /*a5*/, uint32_t /*a6*/, uint32_t /*a7*/, uint32_t /*a8*/, const uint8_t* pSrc, uint32_t srcStride, uint32_t /*a11*/, uint32_t /*a12*/, uint32_t /*a13*/, uint32_t /*a14*/, uint32_t /*a15*/, uint32_t /*a16*/, uint32_t /*a17*/, uint32_t /*a18*/, uint32_t /*a19*/, uint32_t /*a20*/, uint32_t key)
{
    do {
        uint16_t* pD = reinterpret_cast<uint16_t*>(pDst);
        intptr_t delta = reinterpret_cast<intptr_t>(pSrc) - reinterpret_cast<intptr_t>(pD);
        uint32_t n = w;
        do {
            uint32_t v = *reinterpret_cast<const uint16_t*>(reinterpret_cast<intptr_t>(pD) + delta);
            if ((v & 0x7fff) != key) {
                *pD = static_cast<uint16_t>(v);
            }
            ++pD;
            --n;
        } while (n);
        pDst += dstStride;
        pSrc += srcStride;
        --rows;
    } while (rows);
}

// FUNCTION: 0x00828bc0
void Fn00828bc0(uint32_t w, uint32_t rows, uint8_t* pDst, uint32_t dstStride, uint32_t /*a5*/, uint32_t /*a6*/, uint32_t /*a7*/, uint32_t /*a8*/, const uint8_t* pSrc, uint32_t srcStride, uint32_t /*a11*/, uint32_t /*a12*/, uint32_t /*a13*/, uint32_t /*a14*/, uint32_t /*a15*/, uint32_t /*a16*/, uint32_t /*a17*/, uint32_t /*a18*/, uint32_t /*a19*/, uint32_t /*a20*/, uint32_t key)
{
    do {
        uint16_t* pD = reinterpret_cast<uint16_t*>(pDst);
        intptr_t delta = reinterpret_cast<intptr_t>(pSrc) - reinterpret_cast<intptr_t>(pD);
        uint32_t n = w;
        do {
            uint32_t v = *reinterpret_cast<const uint16_t*>(reinterpret_cast<intptr_t>(pD) + delta);
            if ((v & 0xfff) != key) {
                *pD = static_cast<uint16_t>(v);
            }
            ++pD;
            --n;
        } while (n);
        pDst += dstStride;
        pSrc += srcStride;
        --rows;
    } while (rows);
}

// STUB: 0x738800
uint32_t** FnA738800_0073cab0(uint32_t** a, uint32_t** b, uint32_t** c, uint32_t* pN, uint32_t z);

// STUB: 0x73a170
void FnB73a170_0073cab0(uint32_t** a, uint32_t** b, uint32_t* pN);

struct View_0073cab0_shapec06_game {
    uint32_t** mpBegin;
    uint32_t** mpEnd;
    // STUB: 0x73c840
    void Grow(uint32_t** pEnd, uint32_t n, uint32_t v);
    void Fn(uint32_t n, uint32_t v);
};

// FUNCTION: 0x0073cab0
void View_0073cab0_shapec06_game::Fn(uint32_t n, uint32_t v)
{
    uint32_t** pEnd = mpEnd;
    uint32_t size = static_cast<uint32_t>(pEnd - mpBegin);
    if (n < size) {
        uint32_t** pDst = mpBegin + n;
        uint32_t** pNew = FnA738800_0073cab0(pEnd, pEnd, pDst, &n, 0);
        FnB73a170_0073cab0(pNew, mpEnd, &n);
        mpEnd = pNew;
        return;
    }
    Grow(pEnd, n - size, v);
}

// STUB: 0x6fcc80
uint32_t** FnA6fcc80_00700430(uint32_t** a, uint32_t** b, uint32_t** c, uint32_t* pN, uint32_t z);

// STUB: 0x6fcec0
void FnB6fcec0_00700430(uint32_t** a, uint32_t** b, uint32_t* pN);

struct View_00700430_shapec06_game {
    uint32_t** mpBegin;
    uint32_t** mpEnd;
    // STUB: 0x700200
    void Grow(uint32_t** pEnd, uint32_t n, uint32_t v);
    void Fn(uint32_t n, uint32_t v);
};

// FUNCTION: 0x00700430
void View_00700430_shapec06_game::Fn(uint32_t n, uint32_t v)
{
    uint32_t** pEnd = mpEnd;
    uint32_t size = static_cast<uint32_t>(pEnd - mpBegin);
    if (n < size) {
        uint32_t** pDst = mpBegin + n;
        uint32_t** pNew = FnA6fcc80_00700430(pEnd, pEnd, pDst, &n, 0);
        FnB6fcec0_00700430(pNew, mpEnd, &n);
        mpEnd = pNew;
        return;
    }
    Grow(pEnd, n - size, v);
}

// STUB: 0x5105c0
uint32_t** FnA5105c0_00803310(uint32_t** a, uint32_t** b, uint32_t** c, uint32_t* pN, uint32_t z);

// STUB: 0x511040
void FnB511040_00803310(uint32_t** a, uint32_t** b, uint32_t* pN);

struct View_00803310_shapec06_game {
    uint32_t** mpBegin;
    uint32_t** mpEnd;
    // STUB: 0x8031f0
    void Grow(uint32_t** pEnd, uint32_t n, uint32_t v);
    void Fn(uint32_t n, uint32_t v);
};

// FUNCTION: 0x00803310
void View_00803310_shapec06_game::Fn(uint32_t n, uint32_t v)
{
    uint32_t** pEnd = mpEnd;
    uint32_t size = static_cast<uint32_t>(pEnd - mpBegin);
    if (n < size) {
        uint32_t** pDst = mpBegin + n;
        uint32_t** pNew = FnA5105c0_00803310(pEnd, pEnd, pDst, &n, 0);
        FnB511040_00803310(pNew, mpEnd, &n);
        mpEnd = pNew;
        return;
    }
    Grow(pEnd, n - size, v);
}

struct Item_006a9ef0_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual uint64_t Slot10() = 0;
};

struct TNode_006a9ef0_shapec06_game {
    uint32_t mColor;
    TNode_006a9ef0_shapec06_game* mpParent;
    TNode_006a9ef0_shapec06_game* mpLeft;
    TNode_006a9ef0_shapec06_game* mpRight;
    uint32_t mKey;
    Item_006a9ef0_shapec06_game* mpItem;
};

struct View_006a9ef0_shapec06_game {
    uint8_t mPad0[0x4c];
    TNode_006a9ef0_shapec06_game* mpTree;
    uint64_t Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x006a9ef0 score 2
uint64_t View_006a9ef0_shapec06_game::Fn()
{
    TNode_006a9ef0_shapec06_game* pHeader = mpTree;
    TNode_006a9ef0_shapec06_game* pNode = pHeader->mpLeft;
    uint64_t total = 0;
    while (pNode != pHeader) {
        total += pNode->mpItem->Slot10();
        TNode_006a9ef0_shapec06_game* pRight = pNode->mpRight;
        TNode_006a9ef0_shapec06_game* pNext = pNode;
        if (pRight) {
            pNext = pRight;
            while (pNext->mpLeft) {
                pNext = pNext->mpLeft;
            }
        } else {
            TNode_006a9ef0_shapec06_game* pParent = pNode->mpParent;
            if (pNode == pParent->mpRight) {
                do {
                    pNext = pParent;
                    pParent = pParent->mpParent;
                } while (pNext == pParent->mpRight);
            }
            if (pNext->mpRight != pParent) {
                pNext = pParent;
            }
        }
        pNode = pNext;
    }
    return total;
}
#endif

struct Item_006a9f60_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual void Slot10() = 0;
    virtual uint64_t Slot11() = 0;
};

struct TNode_006a9f60_shapec06_game {
    uint32_t mColor;
    TNode_006a9f60_shapec06_game* mpParent;
    TNode_006a9f60_shapec06_game* mpLeft;
    TNode_006a9f60_shapec06_game* mpRight;
    uint32_t mKey;
    Item_006a9f60_shapec06_game* mpItem;
};

struct View_006a9f60_shapec06_game {
    uint8_t mPad0[0x4c];
    TNode_006a9f60_shapec06_game* mpTree;
    uint64_t Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x006a9f60 score 2
uint64_t View_006a9f60_shapec06_game::Fn()
{
    TNode_006a9f60_shapec06_game* pHeader = mpTree;
    TNode_006a9f60_shapec06_game* pNode = pHeader->mpLeft;
    uint64_t total = 0;
    while (pNode != pHeader) {
        total += pNode->mpItem->Slot11();
        TNode_006a9f60_shapec06_game* pRight = pNode->mpRight;
        TNode_006a9f60_shapec06_game* pNext = pNode;
        if (pRight) {
            pNext = pRight;
            while (pNext->mpLeft) {
                pNext = pNext->mpLeft;
            }
        } else {
            TNode_006a9f60_shapec06_game* pParent = pNode->mpParent;
            if (pNode == pParent->mpRight) {
                do {
                    pNext = pParent;
                    pParent = pParent->mpParent;
                } while (pNext == pParent->mpRight);
            }
            if (pNext->mpRight != pParent) {
                pNext = pParent;
            }
        }
        pNode = pNext;
    }
    return total;
}
#endif

struct Item_006a9fd0_shapec06_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual uint64_t Slot14() = 0;
};

struct TNode_006a9fd0_shapec06_game {
    uint32_t mColor;
    TNode_006a9fd0_shapec06_game* mpParent;
    TNode_006a9fd0_shapec06_game* mpLeft;
    TNode_006a9fd0_shapec06_game* mpRight;
    uint32_t mKey;
    Item_006a9fd0_shapec06_game* mpItem;
};

struct View_006a9fd0_shapec06_game {
    uint8_t mPad0[0x4c];
    TNode_006a9fd0_shapec06_game* mpTree;
    uint64_t Fn();
};

#ifdef OB_DRAFTS
// CLOSE: 0x006a9fd0 score 2
uint64_t View_006a9fd0_shapec06_game::Fn()
{
    TNode_006a9fd0_shapec06_game* pHeader = mpTree;
    TNode_006a9fd0_shapec06_game* pNode = pHeader->mpLeft;
    uint64_t total = 0;
    while (pNode != pHeader) {
        total += pNode->mpItem->Slot14();
        TNode_006a9fd0_shapec06_game* pRight = pNode->mpRight;
        TNode_006a9fd0_shapec06_game* pNext = pNode;
        if (pRight) {
            pNext = pRight;
            while (pNext->mpLeft) {
                pNext = pNext->mpLeft;
            }
        } else {
            TNode_006a9fd0_shapec06_game* pParent = pNode->mpParent;
            if (pNode == pParent->mpRight) {
                do {
                    pNext = pParent;
                    pParent = pParent->mpParent;
                } while (pNext == pParent->mpRight);
            }
            if (pNext->mpRight != pParent) {
                pNext = pParent;
            }
        }
        pNode = pNext;
    }
    return total;
}
#endif

// STUB: 0x009133da
void* Fn009133da(uint32_t nBytes);

struct Cmd_c06 {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5(uint32_t k) = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11(uint32_t a) = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16(uint32_t b) = 0;
    // STUB: 0x009134d6
    Cmd_c06* Ctor();
};

struct Sink_c06 {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3(Cmd_c06* p) = 0;
};

struct View_006f7d00_shapec06_game {
    uint8_t mPad0[0x14];
    Sink_c06* mpSink;
    void Fn(uint32_t a, uint32_t b);
};

// FUNCTION: 0x006f7d00
void View_006f7d00_shapec06_game::Fn(uint32_t a, uint32_t b)
{
    if (mpSink) {
        void* p = Fn009133da(0x2c);
        Cmd_c06* pCmd;
        if (p) {
            pCmd = static_cast<Cmd_c06*>(p)->Ctor();
        } else {
            pCmd = 0;
        }
        pCmd->Slot1();
        pCmd->Slot5(0x89efa536);
        pCmd->Slot11(a);
        pCmd->Slot16(b);
        mpSink->Slot3(pCmd);
        pCmd->Slot2();
    }
}

struct View_006b8bc0_shapec06_game {
    uint8_t mPad0[0x18];
    Sink_c06* mpSink;
    void Fn(uint32_t a, uint32_t b);
};

// FUNCTION: 0x006b8bc0
void View_006b8bc0_shapec06_game::Fn(uint32_t a, uint32_t b)
{
    if (mpSink) {
        void* p = Fn009133da(0x2c);
        Cmd_c06* pCmd;
        if (p) {
            pCmd = static_cast<Cmd_c06*>(p)->Ctor();
        } else {
            pCmd = 0;
        }
        pCmd->Slot1();
        pCmd->Slot5(0x89efa536);
        pCmd->Slot11(a);
        pCmd->Slot16(b);
        mpSink->Slot3(pCmd);
        pCmd->Slot2();
    }
}

struct View_006e9070_shapec06_game {
    uint8_t mPad0[0x1c];
    Sink_c06* mpSink;
    void Fn(uint32_t a, uint32_t b);
};

// FUNCTION: 0x006e9070
void View_006e9070_shapec06_game::Fn(uint32_t a, uint32_t b)
{
    if (mpSink) {
        void* p = Fn009133da(0x2c);
        Cmd_c06* pCmd;
        if (p) {
            pCmd = static_cast<Cmd_c06*>(p)->Ctor();
        } else {
            pCmd = 0;
        }
        pCmd->Slot1();
        pCmd->Slot5(0x89efa536);
        pCmd->Slot11(a);
        pCmd->Slot16(b);
        mpSink->Slot3(pCmd);
        pCmd->Slot2();
    }
}

struct Pkt_c06 {
    uint32_t mnLen;
    uint32_t mnCount;
    uint8_t mBuf[16];
    uint32_t mn18;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
};

struct Deque_008ed330_shapec06_game {
    uint32_t mPad[4];
    Pkt_c06* mpCur;
    Pkt_c06* mpFirst;
    Pkt_c06* mpLast;
    // STUB: 0x8ecc20
    void PushAux(Pkt_c06* pItem);
};

struct View_008ed330_shapec06_game {
    uint32_t mPad[2];
    Pkt_c06 mRec;
    Deque_008ed330_shapec06_game mDeque;
    // STUB: 0x8ec190
    void Append(uint32_t nCode, uint32_t nShifted, uint32_t* pValue);
    void Fn(uint32_t nShift, uint32_t* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ed330 score 99
void View_008ed330_shapec06_game::Fn(uint32_t nShift, uint32_t* pValue)
{
    Pkt_c06* pRec = &mRec;
    ++pRec->mnCount;
    pRec->mnLen = 0;
    uint8_t nByte = static_cast<uint8_t>(nShift);
    nByte = static_cast<uint8_t>(nByte << 3);
    Append(0x23, nByte, pValue);
    uint32_t nBit = 1u << nShift;
    mRec.mn24 = 1;
    mRec.mn18 = 0;
    mRec.mn1c = nBit | *pValue;
    mRec.mn20 = nBit | 0x10000;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct Deque_008ed5e0_shapec06_game {
    uint32_t mPad[4];
    Pkt_c06* mpCur;
    Pkt_c06* mpFirst;
    Pkt_c06* mpLast;
    // STUB: 0x8ecc20
    void PushAux(Pkt_c06* pItem);
};

struct View_008ed5e0_shapec06_game {
    uint32_t mPad[2];
    Pkt_c06 mRec;
    Deque_008ed5e0_shapec06_game mDeque;
    // STUB: 0x8ec190
    void Append(uint32_t nCode, uint32_t nShifted, uint32_t* pValue);
    void Fn(uint32_t nShift, uint32_t* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ed5e0 score 99
void View_008ed5e0_shapec06_game::Fn(uint32_t nShift, uint32_t* pValue)
{
    Pkt_c06* pRec = &mRec;
    ++pRec->mnCount;
    pRec->mnLen = 0;
    uint8_t nByte = static_cast<uint8_t>(nShift);
    nByte = static_cast<uint8_t>(nByte << 3);
    Append(0x3, nByte, pValue);
    uint32_t nBit = 1u << nShift;
    mRec.mn24 = 2;
    mRec.mn18 = 1;
    mRec.mn1c = nBit | *pValue;
    mRec.mn20 = nBit | 0x10000;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct Deque_008eda40_shapec06_game {
    uint32_t mPad[4];
    Pkt_c06* mpCur;
    Pkt_c06* mpFirst;
    Pkt_c06* mpLast;
    // STUB: 0x8ecc20
    void PushAux(Pkt_c06* pItem);
};

struct View_008eda40_shapec06_game {
    uint32_t mPad[2];
    Pkt_c06 mRec;
    Deque_008eda40_shapec06_game mDeque;
    // STUB: 0x8ec190
    void Append(uint32_t nCode, uint32_t nShifted, uint32_t* pValue);
    void Fn(uint32_t nShift, uint32_t* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008eda40 score 99
void View_008eda40_shapec06_game::Fn(uint32_t nShift, uint32_t* pValue)
{
    Pkt_c06* pRec = &mRec;
    ++pRec->mnCount;
    pRec->mnLen = 0;
    uint8_t nByte = static_cast<uint8_t>(nShift);
    nByte = static_cast<uint8_t>(nByte << 3);
    Append(0x2b, nByte, pValue);
    uint32_t nBit = 1u << nShift;
    mRec.mn24 = 2;
    mRec.mn18 = 1;
    mRec.mn1c = nBit | *pValue;
    mRec.mn20 = nBit | 0x10000;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct Pkt2_008edad0_shapec06_game {
    uint32_t mnLen;
    uint32_t mnCount;
    uint8_t mBuf[16];
    uint32_t mn18;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
};

struct Deque_008edad0_shapec06_game {
    uint32_t mPad[4];
    Pkt2_008edad0_shapec06_game* mpCur;
    Pkt2_008edad0_shapec06_game* mpFirst;
    Pkt2_008edad0_shapec06_game* mpLast;
    // STUB: 0x8ecc20
    void PushAux(Pkt2_008edad0_shapec06_game* pItem);
};

struct View_008edad0_shapec06_game {
    uint32_t mPad[2];
    Pkt2_008edad0_shapec06_game mRec;
    Deque_008edad0_shapec06_game mDeque;
    void Fn(uint32_t nShift, uint8_t nByte);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008edad0 score 51
void View_008edad0_shapec06_game::Fn(uint32_t nShift, uint8_t nByte)
{
    ++mRec.mnCount;
    mRec.mnLen = 0;
    mRec.mBuf[mRec.mnLen] = 0xc1;
    ++mRec.mnLen;
    mRec.mBuf[mRec.mnLen] = static_cast<uint8_t>(nShift - 0x18);
    ++mRec.mnLen;
    mRec.mBuf[mRec.mnLen] = nByte;
    ++mRec.mnLen;
    uint32_t nBit = 1u << nShift;
    mRec.mn24 = 1;
    mRec.mn18 = 0;
    mRec.mn1c = nBit;
    mRec.mn20 = nBit | 0x10000;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct Pkt2_008edb70_shapec06_game {
    uint32_t mnLen;
    uint32_t mnCount;
    uint8_t mBuf[16];
    uint32_t mn18;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
};

struct Deque_008edb70_shapec06_game {
    uint32_t mPad[4];
    Pkt2_008edb70_shapec06_game* mpCur;
    Pkt2_008edb70_shapec06_game* mpFirst;
    Pkt2_008edb70_shapec06_game* mpLast;
    // STUB: 0x8ecc20
    void PushAux(Pkt2_008edb70_shapec06_game* pItem);
};

struct View_008edb70_shapec06_game {
    uint32_t mPad[2];
    Pkt2_008edb70_shapec06_game mRec;
    Deque_008edb70_shapec06_game mDeque;
    void Fn(uint32_t nShift, uint8_t nByte);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008edb70 score 51
void View_008edb70_shapec06_game::Fn(uint32_t nShift, uint8_t nByte)
{
    ++mRec.mnCount;
    mRec.mnLen = 0;
    mRec.mBuf[mRec.mnLen] = 0xc1;
    ++mRec.mnLen;
    mRec.mBuf[mRec.mnLen] = static_cast<uint8_t>(nShift - 0x8);
    ++mRec.mnLen;
    mRec.mBuf[mRec.mnLen] = nByte;
    ++mRec.mnLen;
    uint32_t nBit = 1u << nShift;
    mRec.mn24 = 1;
    mRec.mn18 = 0;
    mRec.mn1c = nBit;
    mRec.mn20 = nBit | 0x10000;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct Pkt2_008edc10_shapec06_game {
    uint32_t mnLen;
    uint32_t mnCount;
    uint8_t mBuf[16];
    uint32_t mn18;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
};

struct Deque_008edc10_shapec06_game {
    uint32_t mPad[4];
    Pkt2_008edc10_shapec06_game* mpCur;
    Pkt2_008edc10_shapec06_game* mpFirst;
    Pkt2_008edc10_shapec06_game* mpLast;
    // STUB: 0x8ecc20
    void PushAux(Pkt2_008edc10_shapec06_game* pItem);
};

struct View_008edc10_shapec06_game {
    uint32_t mPad[2];
    Pkt2_008edc10_shapec06_game mRec;
    Deque_008edc10_shapec06_game mDeque;
    void Fn(uint32_t nShift, uint8_t nByte);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008edc10 score 51
void View_008edc10_shapec06_game::Fn(uint32_t nShift, uint8_t nByte)
{
    ++mRec.mnCount;
    mRec.mnLen = 0;
    mRec.mBuf[mRec.mnLen] = 0xc1;
    ++mRec.mnLen;
    mRec.mBuf[mRec.mnLen] = static_cast<uint8_t>(nShift - 0x40);
    ++mRec.mnLen;
    mRec.mBuf[mRec.mnLen] = nByte;
    ++mRec.mnLen;
    uint32_t nBit = 1u << nShift;
    mRec.mn24 = 1;
    mRec.mn18 = 0;
    mRec.mn1c = nBit;
    mRec.mn20 = nBit | 0x10000;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

