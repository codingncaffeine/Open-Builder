// Shape families of packet shaped03_game (pairs): the members of one family differ only in their numbers.
#include <stddef.h>
#include "common/types.h"
#include "common/compiler.h"

// FUNCTION: 0x004e2410
uint32_t Fn004e2410(uint32_t a)
{
    return a;
}

// FUNCTION: 0x008ab860
uint32_t Fn008ab860(uint32_t /*a*/, uint32_t b)
{
    return b;
}

// STUB: 0x004f0de0
void OB_STDCALL Fn004f0de0(uint32_t a);

// FUNCTION: 0x004f1200
bool Fn004f1200()
{
    Fn004f0de0(0);
    return true;
}

// STUB: 0x0076a430
void OB_STDCALL Fn0076a430(uint32_t a);

// FUNCTION: 0x0076a4e0
bool Fn0076a4e0()
{
    Fn0076a430(0);
    return true;
}

struct OB_NOVTABLE View3D_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual uint32_t GetMode() = 0;
};

// GLOBAL: 0x00b43dc4
extern View3D_shaped03_game* gpB43dc4_shaped03_game;

struct View_a93f34_shaped03_game {
    bool Slot05();
};

// FUNCTION: 0x004e2c00
bool View_a93f34_shaped03_game::Slot05()
{
    return gpB43dc4_shaped03_game->GetMode() == 1;
}

struct OB_NOVTABLE Sim_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual uint32_t GetMode() = 0;
};

// GLOBAL: 0x00b43d5c
extern Sim_shaped03_game* gpB43d5c_shaped03_game;

struct View_a93f7c_shaped03_game {
    bool Slot05();
};

// FUNCTION: 0x004e2c70
bool View_a93f7c_shaped03_game::Slot05()
{
    return gpB43d5c_shaped03_game->GetMode() == 1;
}

// Release at +4 (== 1 test), destroy slot 3.
struct OB_NOVTABLE View_a93f34r_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    int32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x004ed0b0
uint32_t View_a93f34r_shaped03_game::Release()
{
    if (mnRefs == 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct OB_NOVTABLE View_a940e4_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint8_t mPad[4];
    int32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x004ed910
uint32_t View_a940e4_shaped03_game::Release()
{
    if (mnRefs == 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct OB_NOVTABLE View_a94164_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint8_t mPad[0x1c];
    int32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x004ede60
uint32_t View_a94164_shaped03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE View_a94340_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void Destroy(uint32_t nFlags) = 0;
    uint8_t mPad[0x14];
    int32_t mnRefs;
    uint32_t Release();
};

// FUNCTION: 0x004f5270
uint32_t View_a94340_shaped03_game::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct OB_NOVTABLE Obj_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void Release() = 0;
};

struct View_a940e4i_shaped03_game {
    uint8_t mPad[0x20];
    Obj_shaped03_game* mpObj;
    bool Slot04();
};

// FUNCTION: 0x004ed1f0
bool View_a940e4i_shaped03_game::Slot04()
{
    Obj_shaped03_game* p = mpObj;
    if (p) {
        mpObj = 0;
        p->Release();
    }
    return true;
}

struct View_ab5568_shaped03_game {
    uint8_t mPad[4];
    Obj_shaped03_game* mpObj;
    bool Slot04();
};

// FUNCTION: 0x0078d030
bool View_ab5568_shaped03_game::Slot04()
{
    Obj_shaped03_game* p = mpObj;
    if (p) {
        mpObj = 0;
        p->Release();
    }
    return true;
}

struct OB_NOVTABLE Arg_aa42c8_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual uint32_t Get() = 0;
};

struct OB_NOVTABLE View_aa42c8_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void Set(uint32_t v) = 0;
    void Slot03(uint32_t a);
};

// FUNCTION: 0x004bdf90
void View_aa42c8_shaped03_game::Slot03(uint32_t a)
{
    Arg_aa42c8_shaped03_game* p = OB_PTR(Arg_aa42c8_shaped03_game, a);
    Set(p->Get());
}

struct OB_NOVTABLE Arg_a9f7b4_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual uint32_t Get() = 0;
};

struct OB_NOVTABLE View_a9f7b4_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void Set(uint32_t v) = 0;
    void Slot04(uint32_t a);
};

// FUNCTION: 0x006773d0
void View_a9f7b4_shaped03_game::Slot04(uint32_t a)
{
    Arg_a9f7b4_shaped03_game* p = OB_PTR(Arg_a9f7b4_shaped03_game, a);
    Set(p->Get());
}

struct OB_NOVTABLE Dst_524560_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual bool Put(uint32_t* p) = 0;
    virtual void PutValue(uint32_t v) = 0;
};

// FUNCTION: 0x00524560
bool Fn00524560(uint32_t* p, Dst_524560_shaped03_game* pDst, bool b)
{
    if (b) {
        return pDst->Put(p);
    }
    pDst->PutValue(*p);
    return true;
}

struct OB_NOVTABLE Dst_505210_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual bool Put(uint32_t* p) = 0;
    virtual void PutValue(uint32_t v) = 0;
};

// FUNCTION: 0x00505210
bool Fn00505210(uint32_t* p, Dst_505210_shaped03_game* pDst, bool b)
{
    if (b) {
        return pDst->Put(p);
    }
    pDst->PutValue(*p);
    return true;
}

struct OB_NOVTABLE Item_a95384_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual bool Check() = 0;
};

struct View_a95384_shaped03_game {
    // STUB: 0x00505e50
    bool Slot02Real(uint32_t a);
    // STUB: 0x00509d00
    bool Slot01Real(uint32_t a);
    bool Slot02(uint32_t a);
    bool Slot01(uint32_t a);
};

// FUNCTION: 0x00506160
bool View_a95384_shaped03_game::Slot02(uint32_t a)
{
    Item_a95384_shaped03_game* p = OB_PTR(Item_a95384_shaped03_game, a);
    if (Slot02Real(a)) {
        return !p->Check();
    }
    return false;
}

// FUNCTION: 0x00509f80
bool View_a95384_shaped03_game::Slot01(uint32_t a)
{
    Item_a95384_shaped03_game* p = OB_PTR(Item_a95384_shaped03_game, a);
    if (Slot01Real(a)) {
        return !p->Check();
    }
    return false;
}

struct OB_NOVTABLE Self_qi_shaped03_game {
    virtual void P0() = 0;
    virtual void AddRef() = 0;
};

struct View_a9378c_shaped03_game : Self_qi_shaped03_game {
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x004e82d0
bool View_a9378c_shaped03_game::QueryInterface(uint32_t iid, void** ppOut)
{
    switch (iid) {
    case 1:
    case 0x287fb697:
    case 0x6a12f51c:
        *ppOut = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct View_advisor_shaped03_game : Self_qi_shaped03_game {
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x00762ba0
bool View_advisor_shaped03_game::QueryInterface(uint32_t iid, void** ppOut)
{
    switch (iid) {
    case 1:
    case 0x2a5a754d:
    case 0x452294aa:
        *ppOut = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct OB_NOVTABLE Obj_4ea970_shaped03_game {
    virtual void P0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    // STUB: 0x004ea970
    void Handle(void* pOcc);
};

// FUNCTION: 0x004eaaa0
bool Fn004eaaa0(void* pOcc, Obj_4ea970_shaped03_game* pObj)
{
    if (pOcc && pObj) {
        pObj->AddRef();
        pObj->Handle(pOcc);
        pObj->Release();
        return true;
    }
    return false;
}

struct OB_NOVTABLE Obj_4f0480_shaped03_game {
    virtual void P0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    // STUB: 0x004f0480
    void Handle(void* pOcc);
};

// FUNCTION: 0x004f04d0
bool Fn004f04d0(void* pOcc, Obj_4f0480_shaped03_game* pObj)
{
    if (pOcc && pObj) {
        pObj->AddRef();
        pObj->Handle(pOcc);
        pObj->Release();
        return true;
    }
    return false;
}

struct OB_NOVTABLE Tool_d9ea0_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void Set(uint32_t v) = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
};

struct OB_NOVTABLE Obj_d9ea0_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void Release() = 0;
    virtual void P3() = 0;
    virtual void Set(uint32_t v) = 0;
};

struct View_d9ea0_shaped03_game {
    uint8_t mPad[4];
    bool mbActive;
    uint8_t mPad2[0x27];
    Obj_d9ea0_shaped03_game* mpObj;
    // STUB: 0x005fafd0
    bool BaseShutdown();
    bool Shutdown();
};

// FUNCTION: 0x004d9ea0
bool View_d9ea0_shaped03_game::Shutdown()
{
    if (mbActive) {
        if (mpObj) {
            mpObj->Set(0);
            if (mpObj) {
                Obj_d9ea0_shaped03_game* p = mpObj;
                mpObj = 0;
                p->Release();
            }
        }
        BaseShutdown();
    }
    return true;
}

struct OB_NOVTABLE Obj_bd2e0_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void Release() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void SetF(float v) = 0;
};

struct View_bd2e0_shaped03_game {
    uint8_t mPad[4];
    bool mbActive;
    uint8_t mPad2[0x2b];
    Obj_bd2e0_shaped03_game* mpObj;
    // STUB: 0x005fafd0
    bool BaseShutdown();
    bool Shutdown();
};

// FUNCTION: 0x004bd2e0
bool View_bd2e0_shaped03_game::Shutdown()
{
    if (mbActive) {
        if (mpObj) {
            mpObj->SetF(0.5f);
            if (mpObj) {
                Obj_bd2e0_shaped03_game* p = mpObj;
                mpObj = 0;
                p->Release();
            }
        }
        BaseShutdown();
    }
    return true;
}

// ---- batch 2 ----
struct OB_NOVTABLE Out_aircraft_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void Flag(uint32_t v) = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual bool Check() = 0;
};

// STUB: 0x005da580
void Fn005da580(Out_aircraft_shaped03_game* pStream, void* pVec);

struct View_a94b38_shaped03_game {
    uint8_t mPad[0x344];
    uint8_t mVec[12];
    // STUB: 0x004fb060
    bool BaseSlot03(Out_aircraft_shaped03_game* p);
    bool Slot03(Out_aircraft_shaped03_game* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004fd380 score 8
bool View_a94b38_shaped03_game::Slot03(Out_aircraft_shaped03_game* p)
{
    p->Flag(1);
    if (BaseSlot03(p)) {
        Fn005da580(p, mVec);
        return !p->Check();
    }
    return false;
}
#endif

struct View_heli_shaped03_game {
    uint8_t mPad[0x1e8];
    uint8_t mVec[12];
    // STUB: 0x004fb060
    bool BaseSlot03(Out_aircraft_shaped03_game* p);
    bool Slot03(Out_aircraft_shaped03_game* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005343c0 score 8
bool View_heli_shaped03_game::Slot03(Out_aircraft_shaped03_game* p)
{
    p->Flag(1);
    if (BaseSlot03(p)) {
        Fn005da580(p, mVec);
        return !p->Check();
    }
    return false;
}
#endif

struct OB_NOVTABLE Mgr_b43d98_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void GetValue(uint32_t d, int32_t* pOut, uint32_t z) = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual void P37() = 0;
    virtual void P38() = 0;
    virtual void P39() = 0;
    virtual void P40() = 0;
    virtual void P41() = 0;
    virtual void P42() = 0;
    virtual uint32_t GetA(uint32_t d) = 0;
    virtual uint32_t GetB(uint32_t d) = 0;
};

// GLOBAL: 0x00b43d98
extern Mgr_b43d98_shaped03_game* gpB43d98_shaped03_game;

// STUB: 0x004c6bf0
bool Fn004c6bf0(uint32_t a, uint32_t b, uint32_t v);

// FUNCTION: 0x004c7390
bool Fn004c7390(uint32_t a, uint32_t b, bool c, uint32_t d)
{
    if (c) {
        return Fn004c6bf0(a, b, gpB43d98_shaped03_game->GetA(d));
    }
    return true;
}

// FUNCTION: 0x004c73d0
bool Fn004c73d0(uint32_t a, uint32_t b, bool c, uint32_t d)
{
    if (c) {
        return Fn004c6bf0(a, b, gpB43d98_shaped03_game->GetB(d));
    }
    return true;
}

struct OB_NOVTABLE Mgr_b43d78_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void GetValue(uint32_t d, int32_t* pOut, uint32_t z) = 0;
};

// GLOBAL: 0x00b43d78
extern Mgr_b43d78_shaped03_game* gpB43d78_shaped03_game;

// STUB: 0x004c6d50
bool Fn004c6d50(uint32_t a, uint32_t b, int64_t v);

// FUNCTION: 0x004c7350
bool Fn004c7350(uint32_t a, uint32_t b, bool c, uint32_t d)
{
    if (c) {
        int32_t v;
        gpB43d78_shaped03_game->GetValue(d, &v, 0);
        return Fn004c6d50(a, b, v);
    }
    return true;
}

// FUNCTION: 0x004c7560
bool Fn004c7560(uint32_t a, uint32_t b, bool c, uint32_t d)
{
    if (c) {
        int32_t v;
        gpB43d98_shaped03_game->GetValue(d, &v, 0);
        return Fn004c6d50(a, b, v);
    }
    return true;
}

struct OB_NOVTABLE Rect_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual int64_t Measure(void* pLot) = 0;
};

struct OB_NOVTABLE City_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual void P37() = 0;
    virtual void P38() = 0;
    virtual void P39() = 0;
    virtual void P40() = 0;
    virtual void P41() = 0;
    virtual void P42() = 0;
    virtual void P43() = 0;
    virtual void P44() = 0;
    virtual void P45() = 0;
    virtual void P46() = 0;
    virtual void P47() = 0;
    virtual void P48() = 0;
    virtual void P49() = 0;
    virtual void P50() = 0;
    virtual void P51() = 0;
    virtual void P52() = 0;
    virtual void P53() = 0;
    virtual void P54() = 0;
    virtual void P55() = 0;
    virtual void P56() = 0;
    virtual void P57() = 0;
    virtual void P58() = 0;
    virtual void P59() = 0;
    virtual void P60() = 0;
    virtual void P61() = 0;
    virtual void P62() = 0;
    virtual void P63() = 0;
    virtual void P64() = 0;
    virtual void P65() = 0;
    virtual void P66() = 0;
    virtual void P67() = 0;
    virtual void P68() = 0;
    virtual void P69() = 0;
    virtual void P70() = 0;
    virtual void P71() = 0;
    virtual void P72() = 0;
    virtual void P73() = 0;
    virtual void P74() = 0;
    virtual void P75() = 0;
    virtual Rect_shaped03_game* GetRectA() = 0;
    virtual Rect_shaped03_game* GetRectB() = 0;
};

struct OB_NOVTABLE LotMgr_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void* Find(uint32_t d, uint32_t e, uint32_t z) = 0;
};

// GLOBAL: 0x00b43d08
extern LotMgr_shaped03_game* gpB43d08_shaped03_game;
// GLOBAL: 0x00b43cec
extern City_shaped03_game* gpB43cec_shaped03_game;

// FUNCTION: 0x004c7690
bool Fn004c7690(uint32_t a, uint32_t b, bool c, uint32_t d, uint32_t e)
{
    if (c) {
        void* pLot = gpB43d08_shaped03_game->Find(d, e, 0);
        if (pLot) {
            return Fn004c6d50(a, b, gpB43cec_shaped03_game->GetRectB()->Measure(pLot));
        }
        return false;
    }
    return true;
}

// FUNCTION: 0x004c78b0
bool Fn004c78b0(uint32_t a, uint32_t b, bool c, uint32_t d, uint32_t e)
{
    if (c) {
        void* pLot = gpB43d08_shaped03_game->Find(d, e, 0);
        if (pLot) {
            return Fn004c6d50(a, b, gpB43cec_shaped03_game->GetRectA()->Measure(pLot));
        }
        return false;
    }
    return true;
}

// ---- batch 3 ----
struct OB_NOVTABLE Fn4cc240Obj_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void Register(uint32_t id, void* pFn, uint32_t d) = 0;
};

// STUB: 0x004cc240
bool Fn004cc240(uint32_t a, uint32_t b, uint32_t flag, uint32_t d);

bool Fn004cc660(uint32_t a, uint32_t b, Fn4cc240Obj_shaped03_game* pObj, uint32_t d);
bool Fn004cc6a0(uint32_t a, uint32_t b, Fn4cc240Obj_shaped03_game* pObj, uint32_t d);

// FUNCTION: 0x004cc660
bool Fn004cc660(uint32_t a, uint32_t b, Fn4cc240Obj_shaped03_game* pObj, uint32_t d)
{
    if (!Fn004cc240(a, b, 1, d)) {
        pObj->Register(0x22ba0121, reinterpret_cast<void*>(Fn004cc660), d);
    }
    return true;
}

// FUNCTION: 0x004cc6a0
bool Fn004cc6a0(uint32_t a, uint32_t b, Fn4cc240Obj_shaped03_game* pObj, uint32_t d)
{
    if (!Fn004cc240(a, b, 0, d)) {
        pObj->Register(0x22ba0121, reinterpret_cast<void*>(Fn004cc6a0), d);
    }
    return true;
}

typedef bool (*Handler_a92488_shaped03_game)(uint32_t, uint32_t, uint32_t, uint32_t);
// GLOBAL: 0x00a92488
extern Handler_a92488_shaped03_game ga92488_shaped03_game[0x7f];

bool Fn004d3ae0(uint32_t a, uint32_t b, Fn4cc240Obj_shaped03_game* pObj, uint32_t d);
bool Fn004d3bd0(uint32_t a, uint32_t b, Fn4cc240Obj_shaped03_game* pObj, uint32_t d);

#ifdef OB_DRAFTS
// CLOSE: 0x004d3ae0 score 4
bool Fn004d3ae0(uint32_t a, uint32_t b, Fn4cc240Obj_shaped03_game* pObj, uint32_t d)
{
    if ((b & 0x1000) && a && d && (b & 0xfff) < 0x7f && ga92488_shaped03_game[b & 0xfff]) {
        if (ga92488_shaped03_game[b & 0xfff](a, b, 1, d)) {
            return true;
        }
    }
    pObj->Register(0x22ba0121, reinterpret_cast<void*>(Fn004d3ae0), d);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004d3bd0 score 4
bool Fn004d3bd0(uint32_t a, uint32_t b, Fn4cc240Obj_shaped03_game* pObj, uint32_t d)
{
    if ((b & 0x1000) && a && d && (b & 0xfff) < 0x7f && ga92488_shaped03_game[b & 0xfff]) {
        if (ga92488_shaped03_game[b & 0xfff](a, b, 0, d)) {
            return true;
        }
    }
    pObj->Register(0x22ba0121, reinterpret_cast<void*>(Fn004d3bd0), d);
    return true;
}
#endif

struct OB_NOVTABLE Rel_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void Release() = 0;
};

struct OB_NOVTABLE Qi_shaped03_game {
    virtual bool QueryInterface(uint32_t iid, void** ppOut) = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual uint32_t GetType() = 0;
};

struct View_aa42c8b_shaped03_game {
    bool Slot03(uint32_t a);
};

// FUNCTION: 0x004bc9b0
bool View_aa42c8b_shaped03_game::Slot03(uint32_t a)
{
    Qi_shaped03_game* p = OB_PTR(Qi_shaped03_game, a);
    if (p->GetType() == 0xa823821e) {
        Rel_shaped03_game* q = 0;
        if (p->QueryInterface(0x2b3b7d86, reinterpret_cast<void**>(&q))) {
            if (q) {
                q->Release();
            }
            return true;
        }
        if (q) {
            q->Release();
        }
    }
    return false;
}

struct View_a9293c_shaped03_game {
    bool Slot03(uint32_t a);
};

// FUNCTION: 0x004d7cc0
bool View_a9293c_shaped03_game::Slot03(uint32_t a)
{
    Qi_shaped03_game* p = OB_PTR(Qi_shaped03_game, a);
    if (p->GetType() == 0xa823821e) {
        Rel_shaped03_game* q = 0;
        if (p->QueryInterface(0x4b44fbe2, reinterpret_cast<void**>(&q))) {
            if (q) {
                q->Release();
            }
            return true;
        }
        if (q) {
            q->Release();
        }
    }
    return false;
}

struct OB_NOVTABLE Is_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual bool Is(uint32_t id) = 0;
};

struct View_a93a28_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnLast;
    bool mbResult;
    bool Slot05(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004e2620 score 9
bool View_a93a28_shaped03_game::Slot05(uint32_t a)
{
    if (a == mnLast) {
        return mbResult;
    }
    Is_shaped03_game* p = OB_PTR(Is_shaped03_game, a);
    if (p->Is(0x4224) || p->Is(0x4225)) {
        mnLast = a;
        mbResult = true;
        return true;
    }
    mnLast = a;
    mbResult = false;
    return false;
}
#endif

struct View_a93950_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnLast;
    bool mbResult;
    bool Slot05(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004e2880 score 9
bool View_a93950_shaped03_game::Slot05(uint32_t a)
{
    if (a == mnLast) {
        return mbResult;
    }
    Is_shaped03_game* p = OB_PTR(Is_shaped03_game, a);
    if (p->Is(0x4200) || p->Is(0x420f)) {
        mnLast = a;
        mbResult = true;
        return true;
    }
    mnLast = a;
    mbResult = false;
    return false;
}
#endif

struct Vec_a954e8_shaped03_game {
    uint8_t mB[12];
};

// STUB: 0x005da550
void Fn005da550(Out_aircraft_shaped03_game* pStream, void* pVec);

struct View_a954e8_shaped03_game {
    uint8_t mPad[0x28];
    Vec_a954e8_shaped03_game mV[4];
    // STUB: 0x00505e50
    bool Real02(uint32_t a);
    // STUB: 0x00509d00
    bool Real01(uint32_t a);
    bool Slot02(uint32_t a);
    bool Slot01(uint32_t a);
};

// FUNCTION: 0x00506100
bool View_a954e8_shaped03_game::Slot02(uint32_t a)
{
    Out_aircraft_shaped03_game* p = OB_PTR(Out_aircraft_shaped03_game, a);
    if (Real02(a)) {
        Fn005da550(p, &mV[0]);
        Fn005da550(p, &mV[1]);
        Fn005da550(p, &mV[2]);
        Fn005da550(p, &mV[3]);
        return !p->Check();
    }
    return false;
}

// FUNCTION: 0x00509f20
bool View_a954e8_shaped03_game::Slot01(uint32_t a)
{
    Out_aircraft_shaped03_game* p = OB_PTR(Out_aircraft_shaped03_game, a);
    if (Real01(a)) {
        Fn005da580(p, &mV[0]);
        Fn005da580(p, &mV[1]);
        Fn005da580(p, &mV[2]);
        Fn005da580(p, &mV[3]);
        return !p->Check();
    }
    return false;
}

struct OB_NOVTABLE Sink_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void Release() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void SetFlag(uint32_t v) = 0;
};

struct OB_NOVTABLE Lookup_shaped03_game {
    virtual bool QueryInterface(uint32_t iid, void** ppOut) = 0;
};

struct OB_NOVTABLE Owner_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual uint32_t Get(uint32_t a) = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual Lookup_shaped03_game* Find(uint32_t a) = 0;
};

// FUNCTION: 0x00509a50
bool Fn00509a50(uint32_t a, uint32_t /*b*/, uint32_t /*c*/, Owner_shaped03_game* pOwner)
{
    Lookup_shaped03_game* pFound = pOwner->Find(pOwner->Get(a));
    Sink_shaped03_game* q = 0;
    if (pFound) {
        if (pFound->QueryInterface(0xa9b40f05, reinterpret_cast<void**>(&q))) {
            q->SetFlag(0);
        }
        if (q) {
            q->Release();
        }
    }
    return true;
}

// FUNCTION: 0x00509ab0
bool Fn00509ab0(uint32_t a, uint32_t /*b*/, uint32_t /*c*/, Owner_shaped03_game* pOwner)
{
    Lookup_shaped03_game* pFound = pOwner->Find(pOwner->Get(a));
    Sink_shaped03_game* q = 0;
    if (pFound) {
        if (pFound->QueryInterface(0xa9b40f05, reinterpret_cast<void**>(&q))) {
            q->SetFlag(1);
        }
        if (q) {
            q->Release();
        }
    }
    return true;
}

struct OB_NOVTABLE Out2_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void GetCount(uint16_t* pOut) = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual bool Check() = 0;
};

struct View_a94b38b_shaped03_game {
    uint8_t mPad[0x340];
    bool mbFlag;
    uint8_t mPad2[3];
    uint8_t mVec[12];
    // STUB: 0x004fb080
    bool BaseSlot04(Out2_shaped03_game* p);
    bool Slot04(Out2_shaped03_game* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004fd3c0 score 14
bool View_a94b38b_shaped03_game::Slot04(Out2_shaped03_game* p)
{
    uint16_t n;
    p->GetCount(&n);
    if (n > 1) {
        return false;
    }
    if (BaseSlot04(p)) {
        Fn005da550(reinterpret_cast<Out_aircraft_shaped03_game*>(p), mVec);
        mbFlag = true;
        return !p->Check();
    }
    return false;
}
#endif

struct OB_NOVTABLE CityB_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual void P37() = 0;
    virtual void P38() = 0;
    virtual void P39() = 0;
    virtual void P40() = 0;
    virtual void P41() = 0;
    virtual void P42() = 0;
    virtual void P43() = 0;
    virtual Fn4cc240Obj_shaped03_game* GetCrewMgr() = 0;
};

struct OB_NOVTABLE CrewMgr_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void Remove(Rel_shaped03_game* pCrew, uint32_t z) = 0;
};

struct OB_NOVTABLE CityC_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual void P37() = 0;
    virtual void P38() = 0;
    virtual void P39() = 0;
    virtual void P40() = 0;
    virtual void P41() = 0;
    virtual void P42() = 0;
    virtual void P43() = 0;
    virtual CrewMgr_shaped03_game* GetCrewMgr() = 0;
};

// GLOBAL: 0x00b43cec
extern CityC_shaped03_game* gpB43cec_c_shaped03_game;

struct View_fire_shaped03_game {
    uint8_t mPad[0x2e0];
    Rel_shaped03_game* mpCrew;
    void ReleaseCrew();
};

// FUNCTION: 0x00532d30
void View_fire_shaped03_game::ReleaseCrew()
{
    if (mpCrew) {
        gpB43cec_c_shaped03_game->GetCrewMgr()->Remove(mpCrew, 0);
        if (mpCrew) {
            Rel_shaped03_game* p = mpCrew;
            mpCrew = 0;
            p->Release();
        }
    }
}

struct View_patrol_shaped03_game {
    uint8_t mPad[0x2d8];
    Rel_shaped03_game* mpCrew;
    void ReleaseCrew();
};

// FUNCTION: 0x00543d60
void View_patrol_shaped03_game::ReleaseCrew()
{
    if (mpCrew) {
        gpB43cec_c_shaped03_game->GetCrewMgr()->Remove(mpCrew, 0);
        if (mpCrew) {
            Rel_shaped03_game* p = mpCrew;
            mpCrew = 0;
            p->Release();
        }
    }
}

struct View_heli4_shaped03_game {
    uint8_t mPad[0x1e4];
    bool mbFlag;
    uint8_t mPad2[3];
    uint8_t mVec[12];
    // STUB: 0x004fb080
    bool BaseSlot04(Out2_shaped03_game* p);
    bool Slot04(Out2_shaped03_game* p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00534400 score 14
bool View_heli4_shaped03_game::Slot04(Out2_shaped03_game* p)
{
    uint16_t n;
    p->GetCount(&n);
    if (n > 1) {
        return false;
    }
    if (BaseSlot04(p)) {
        Fn005da550(reinterpret_cast<Out_aircraft_shaped03_game*>(p), mVec);
        mbFlag = true;
        return !p->Check();
    }
    return false;
}
#endif

// ---- batch 4 ----
// STUB: 0x0090cf63
void StlDelete_shaped03_game(void* p);

struct Node_4b6350_shaped03_game {
    Node_4b6350_shaped03_game* pNext;
    Node_4b6350_shaped03_game* pPrev;
    uint8_t mPad[0x14];
    uint32_t mnVtbl;
    void* pData;
};

#ifdef OB_DRAFTS
// CLOSE: 0x004b6350 score 37
void OB_STDCALL Fn004b6350(Node_4b6350_shaped03_game** pOut, Node_4b6350_shaped03_game* pFirst, Node_4b6350_shaped03_game* pLast)
{
    if (pFirst != pLast) {
        do {
        Node_4b6350_shaped03_game* pNode = pFirst;
        Node_4b6350_shaped03_game* pNext = pNode->pNext;
        Node_4b6350_shaped03_game* pPrev = pNode->pPrev;
        pFirst = pFirst->pNext;
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
        pNode->mnVtbl = 0xa80810;
        if (pNode->pData) {
            StlDelete_shaped03_game(pNode->pData);
        }
        StlDelete_shaped03_game(pNode);
        } while (pFirst != pLast);
    }
    *pOut = pLast;
}
#endif

struct Node_812a50_shaped03_game {
    Node_812a50_shaped03_game* pNext;
    Node_812a50_shaped03_game* pPrev;
    uint32_t mnVtbl;
    void* pData;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00812a50 score 37
void OB_STDCALL Fn00812a50(Node_812a50_shaped03_game** pOut, Node_812a50_shaped03_game* pFirst, Node_812a50_shaped03_game* pLast)
{
    if (pFirst != pLast) {
        do {
        Node_812a50_shaped03_game* pNode = pFirst;
        Node_812a50_shaped03_game* pNext = pNode->pNext;
        Node_812a50_shaped03_game* pPrev = pNode->pPrev;
        pFirst = pFirst->pNext;
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
        pNode->mnVtbl = 0xa80810;
        if (pNode->pData) {
            StlDelete_shaped03_game(pNode->pData);
        }
        StlDelete_shaped03_game(pNode);
        } while (pFirst != pLast);
    }
    *pOut = pLast;
}
#endif

struct View_vec_4c1390_shaped03_game {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    // STUB: 0x00527180
    void Erase(uint32_t* pFirst, uint32_t* pLast);
    // STUB: 0x004bff30
    void InsertN(uint32_t* pPos, uint32_t n, uint32_t* pVal);
    void Resize(uint32_t n);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004c1390 score 22
void View_vec_4c1390_shaped03_game::Resize(uint32_t n)
{
    uint32_t* pBegin = mpBegin;
    uint32_t nZero = 0;
    uint32_t nSize = static_cast<uint32_t>(mpEnd - pBegin);
    if (n < nSize) {
        Erase(pBegin + n, mpEnd);
    } else {
        InsertN(mpEnd, n - nSize, &nZero);
    }
}
#endif

struct View_vec_5a4a80_shaped03_game {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    // STUB: 0x0058ff20
    void Erase(uint32_t* pFirst, uint32_t* pLast);
    // STUB: 0x005a4820
    void InsertN(uint32_t* pPos, uint32_t n, uint32_t* pVal);
    void Resize(uint32_t n);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005a4a80 score 22
void View_vec_5a4a80_shaped03_game::Resize(uint32_t n)
{
    uint32_t* pBegin = mpBegin;
    uint32_t nZero = 0;
    uint32_t nSize = static_cast<uint32_t>(mpEnd - pBegin);
    if (n < nSize) {
        Erase(pBegin + n, mpEnd);
    } else {
        InsertN(mpEnd, n - nSize, &nZero);
    }
}
#endif

struct OB_NOVTABLE Radius_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual bool Has(uint32_t p) = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual float Radius(uint32_t p) = 0;
};

struct OB_NOVTABLE CityR1_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual void P37() = 0;
    virtual void P38() = 0;
    virtual void P39() = 0;
    virtual void P40() = 0;
    virtual void P41() = 0;
    virtual void P42() = 0;
    virtual void P43() = 0;
    virtual void P44() = 0;
    virtual void P45() = 0;
    virtual void P46() = 0;
    virtual void P47() = 0;
    virtual void P48() = 0;
    virtual void P49() = 0;
    virtual void P50() = 0;
    virtual void P51() = 0;
    virtual void P52() = 0;
    virtual void P53() = 0;
    virtual void P54() = 0;
    virtual void P55() = 0;
    virtual void P56() = 0;
    virtual Radius_shaped03_game* GetMgr() = 0;
};

// GLOBAL: 0x00b43cec
extern CityR1_shaped03_game* gpB43cec_r1_shaped03_game;

struct View_fire_r_shaped03_game {
    uint8_t mPad[0x2c4];
    uint32_t mnTarget;
    float GetEffectiveRadius();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00532bf0 score 10
float View_fire_r_shaped03_game::GetEffectiveRadius()
{
    float fDefault = 16.0f;
    Radius_shaped03_game* pMgr = gpB43cec_r1_shaped03_game->GetMgr();
    if (mnTarget && pMgr->Has(mnTarget)) {
        return pMgr->Radius(mnTarget);
    }
    return fDefault;
}
#endif

struct OB_NOVTABLE Radius2_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual bool Has(uint32_t p) = 0;
    virtual float Radius(uint32_t p) = 0;
};

struct OB_NOVTABLE CityR2_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual void P37() = 0;
    virtual void P38() = 0;
    virtual void P39() = 0;
    virtual void P40() = 0;
    virtual void P41() = 0;
    virtual void P42() = 0;
    virtual void P43() = 0;
    virtual void P44() = 0;
    virtual void P45() = 0;
    virtual void P46() = 0;
    virtual void P47() = 0;
    virtual void P48() = 0;
    virtual void P49() = 0;
    virtual void P50() = 0;
    virtual void P51() = 0;
    virtual void P52() = 0;
    virtual void P53() = 0;
    virtual void P54() = 0;
    virtual void P55() = 0;
    virtual void P56() = 0;
    virtual void P57() = 0;
    virtual void P58() = 0;
    virtual void P59() = 0;
    virtual void P60() = 0;
    virtual void P61() = 0;
    virtual void P62() = 0;
    virtual void P63() = 0;
    virtual void P64() = 0;
    virtual Radius2_shaped03_game* GetMgr() = 0;
};

// GLOBAL: 0x00b43cec
extern CityR2_shaped03_game* gpB43cec_r2_shaped03_game;

struct View_patrol_r_shaped03_game {
    uint8_t mPad[0x2c4];
    uint32_t mnTarget;
    float GetEffectiveRadius();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00543bc0 score 10
float View_patrol_r_shaped03_game::GetEffectiveRadius()
{
    float fDefault = 16.0f;
    Radius2_shaped03_game* pMgr = gpB43cec_r2_shaped03_game->GetMgr();
    if (mnTarget && pMgr->Has(mnTarget)) {
        return pMgr->Radius(mnTarget);
    }
    return fDefault;
}
#endif

// ---- batch 5 ----
struct Single_4ecd60_shaped03_game {
    uint8_t mPad[0x60];
    Rel_shaped03_game* mp60;
    Rel_shaped03_game* mp64;
};

// STUB: 0x004ecd60
Single_4ecd60_shaped03_game* Fn004ecd60();

#ifdef OB_DRAFTS
// CLOSE: 0x004bb9e0 score 30
Rel_shaped03_game* Fn004bb9e0()
{
    bool bTemp = false;
    Rel_shaped03_game* pTemp = 0;
    Rel_shaped03_game** ppObj;
    Single_4ecd60_shaped03_game* pSingle = Fn004ecd60();
    if (pSingle) {
        ppObj = &pSingle->mp60;
    } else {
        pTemp = 0;
        bTemp = true;
        ppObj = &pTemp;
    }
    Rel_shaped03_game* pObj = *ppObj;
    if (bTemp && pTemp) {
        pTemp->Release();
    }
    return pObj;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004e8490 score 30
Rel_shaped03_game* Fn004e8490()
{
    bool bTemp = false;
    Rel_shaped03_game* pTemp = 0;
    Rel_shaped03_game** ppObj;
    Single_4ecd60_shaped03_game* pSingle = Fn004ecd60();
    if (pSingle) {
        ppObj = &pSingle->mp64;
    } else {
        pTemp = 0;
        bTemp = true;
        ppObj = &pTemp;
    }
    Rel_shaped03_game* pObj = *ppObj;
    if (bTemp && pTemp) {
        pTemp->Release();
    }
    return pObj;
}
#endif

struct OB_NOVTABLE LotObj_shaped03_game {
    virtual void P0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual void P37() = 0;
    virtual void P38() = 0;
    virtual void P39() = 0;
    virtual void P40() = 0;
    virtual uint32_t Kind() = 0;
};

struct OB_NOVTABLE LotMgr2_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual LotObj_shaped03_game* GetLot(uint32_t a) = 0;
};

// GLOBAL: 0x00b43d08
extern LotMgr2_shaped03_game* gpB43d08_b_shaped03_game;

struct View_a93a58_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnKey;
    bool mbResult;
    bool Slot05(uint32_t a);
};

// FUNCTION: 0x004e2f60
bool View_a93a58_shaped03_game::Slot05(uint32_t a)
{
    if (a == mnKey) {
        return mbResult;
    }
    LotObj_shaped03_game* pLot = gpB43d08_b_shaped03_game->GetLot(a);
    if (pLot) {
        pLot->AddRef();
        if (pLot->Kind() == 2) {
            mnKey = a;
            mbResult = true;
            pLot->Release();
            return true;
        }
    }
    mnKey = a;
    mbResult = false;
    if (pLot) {
        pLot->Release();
    }
    return false;
}

struct View_a93a70_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnKey;
    bool mbResult;
    bool Slot05(uint32_t a);
};

// FUNCTION: 0x004e2fd0
bool View_a93a70_shaped03_game::Slot05(uint32_t a)
{
    if (a == mnKey) {
        return mbResult;
    }
    LotObj_shaped03_game* pLot = gpB43d08_b_shaped03_game->GetLot(a);
    if (pLot) {
        pLot->AddRef();
        if (pLot->Kind() == 3) {
            mnKey = a;
            mbResult = true;
            pLot->Release();
            return true;
        }
    }
    mnKey = a;
    mbResult = false;
    if (pLot) {
        pLot->Release();
    }
    return false;
}

struct OB_NOVTABLE ZoneMgr_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual uint32_t GetZoneType(uint32_t a, uint32_t b) = 0;
};

// GLOBAL: 0x00b43d14
extern ZoneMgr_shaped03_game* gpB43d14_shaped03_game;

struct View_a93b30_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnA;
    uint32_t mnB;
    bool mbResult;
    bool Slot05(uint32_t a, uint32_t b);
};

// FUNCTION: 0x004e3420
bool View_a93b30_shaped03_game::Slot05(uint32_t a, uint32_t b)
{
    if (a == mnA && b == mnB) {
        return mbResult;
    }
    uint32_t nType = gpB43d14_shaped03_game->GetZoneType(a, b);
    if (nType == 4 || nType == 5 || nType == 6) {
        mnA = a;
        mnB = b;
        mbResult = true;
        return true;
    }
    mnA = a;
    mnB = b;
    mbResult = false;
    return false;
}

struct View_a93b48_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnA;
    uint32_t mnB;
    bool mbResult;
    bool Slot05(uint32_t a, uint32_t b);
};

// FUNCTION: 0x004e3490
bool View_a93b48_shaped03_game::Slot05(uint32_t a, uint32_t b)
{
    if (a == mnA && b == mnB) {
        return mbResult;
    }
    uint32_t nType = gpB43d14_shaped03_game->GetZoneType(a, b);
    if (nType == 7 || nType == 8 || nType == 9) {
        mnA = a;
        mnB = b;
        mbResult = true;
        return true;
    }
    mnA = a;
    mnB = b;
    mbResult = false;
    return false;
}

struct OB_NOVTABLE Rating_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual uint8_t Rate(uint32_t a, uint32_t b) = 0;
};

struct OB_NOVTABLE CrimeSim_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual Rating_shaped03_game* GetRating() = 0;
};

struct OB_NOVTABLE CrimeSim2_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual Rating_shaped03_game* GetRating() = 0;
};

// GLOBAL: 0x00b43d70
extern CrimeSim_shaped03_game* gpB43d70_shaped03_game;
// GLOBAL: 0x00b43d88
extern CrimeSim2_shaped03_game* gpB43d88_shaped03_game;

struct View_a93c20_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnA;
    uint32_t mnB;
    bool mbResult;
    bool Slot05(uint32_t a, uint32_t b);
};

// FUNCTION: 0x004e3af0
bool View_a93c20_shaped03_game::Slot05(uint32_t a, uint32_t b)
{
    if (a == mnA && b == mnB) {
        return mbResult;
    }
    if (gpB43d70_shaped03_game && gpB43d70_shaped03_game->GetRating()->Rate(a, b) >= 0xc8) {
        mnA = a;
        mnB = b;
        mbResult = true;
        return true;
    }
    mnA = a;
    mnB = b;
    mbResult = false;
    return false;
}

struct View_a93c98_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnA;
    uint32_t mnB;
    bool mbResult;
    bool Slot05(uint32_t a, uint32_t b);
};

// FUNCTION: 0x004e3d20
bool View_a93c98_shaped03_game::Slot05(uint32_t a, uint32_t b)
{
    if (a == mnA && b == mnB) {
        return mbResult;
    }
    if (gpB43d88_shaped03_game && gpB43d88_shaped03_game->GetRating()->Rate(a, b) >= 0xc8) {
        mnA = a;
        mnB = b;
        mbResult = true;
        return true;
    }
    mnA = a;
    mnB = b;
    mbResult = false;
    return false;
}

struct View_a93c50_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnA;
    uint32_t mnB;
    bool mbResult;
    bool Slot05(uint32_t a, uint32_t b);
};

// FUNCTION: 0x004e3bd0
bool View_a93c50_shaped03_game::Slot05(uint32_t a, uint32_t b)
{
    if (a == mnA && b == mnB) {
        return mbResult;
    }
    if (gpB43d70_shaped03_game && gpB43d70_shaped03_game->GetRating()->Rate(a, b) < 0x78) {
        mnA = a;
        mnB = b;
        mbResult = true;
        return true;
    }
    mnA = a;
    mnB = b;
    mbResult = false;
    return false;
}

struct View_a93c68_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnA;
    uint32_t mnB;
    bool mbResult;
    bool Slot05(uint32_t a, uint32_t b);
};

// FUNCTION: 0x004e3c40
bool View_a93c68_shaped03_game::Slot05(uint32_t a, uint32_t b)
{
    if (a == mnA && b == mnB) {
        return mbResult;
    }
    if (gpB43d88_shaped03_game && gpB43d88_shaped03_game->GetRating()->Rate(a, b) < 0x8c) {
        mnA = a;
        mnB = b;
        mbResult = true;
        return true;
    }
    mnA = a;
    mnB = b;
    mbResult = false;
    return false;
}

struct View_a93c38_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnA;
    uint32_t mnB;
    bool mbResult;
    bool Slot05(uint32_t a, uint32_t b);
};

// FUNCTION: 0x004e3b60
bool View_a93c38_shaped03_game::Slot05(uint32_t a, uint32_t b)
{
    if (a == mnA && b == mnB) {
        return mbResult;
    }
    if (gpB43d70_shaped03_game) {
        uint8_t nRate = gpB43d70_shaped03_game->GetRating()->Rate(a, b);
        if (nRate >= 0x78 && nRate < 0xc8) {
            mnA = a;
            mnB = b;
            mbResult = true;
            return true;
        }
    }
    mnA = a;
    mnB = b;
    mbResult = false;
    return false;
}

struct View_a93c80_shaped03_game {
    uint32_t mnVtbl;
    uint32_t mnA;
    uint32_t mnB;
    bool mbResult;
    bool Slot05(uint32_t a, uint32_t b);
};

// FUNCTION: 0x004e3cb0
bool View_a93c80_shaped03_game::Slot05(uint32_t a, uint32_t b)
{
    if (a == mnA && b == mnB) {
        return mbResult;
    }
    if (gpB43d88_shaped03_game) {
        uint8_t nRate = gpB43d88_shaped03_game->GetRating()->Rate(a, b);
        if (nRate >= 0x8c && nRate < 0xc8) {
            mnA = a;
            mnB = b;
            mbResult = true;
            return true;
        }
    }
    mnA = a;
    mnB = b;
    mbResult = false;
    return false;
}

// ---- batch 6 ----
struct Elem_504c70_shaped03_game {
    Rel_shaped03_game* mpObj;
    uint32_t mnValue;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00504c70 score 12
void Fn00504c70(Elem_504c70_shaped03_game* pCur, Elem_504c70_shaped03_game* /*pFirst*/, Elem_504c70_shaped03_game* pBlockEnd, Elem_504c70_shaped03_game** ppNode, Elem_504c70_shaped03_game* pLast)
{
    while (pCur != pLast) {
        if (pCur->mpObj) {
            pCur->mpObj->Release();
        }
        ++pCur;
        if (pCur == pBlockEnd) {
            ++ppNode;
            pCur = *ppNode;
            pBlockEnd = pCur + 16;
        }
    }
}
#endif

struct Elem_504cb0_shaped03_game {
    Rel_shaped03_game* mpObj;
    uint32_t mnValue;
    uint32_t mnValue2;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00504cb0 score 12
void Fn00504cb0(Elem_504cb0_shaped03_game* pCur, Elem_504cb0_shaped03_game* /*pFirst*/, Elem_504cb0_shaped03_game* pBlockEnd, Elem_504cb0_shaped03_game** ppNode, Elem_504cb0_shaped03_game* pLast)
{
    while (pCur != pLast) {
        if (pCur->mpObj) {
            pCur->mpObj->Release();
        }
        ++pCur;
        if (pCur == pBlockEnd) {
            ++ppNode;
            pCur = *ppNode;
            pBlockEnd = pCur + 10;
        }
    }
}
#endif

struct Curve_shaped03_game {
    // STUB: 0x005f4250
    float GetOutputValue(float v) const;
};

struct OB_NOVTABLE Rate_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual float Rate(uint32_t a, uint32_t b) = 0;
};

struct OB_NOVTABLE ResSim_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual void P37() = 0;
    virtual void P38() = 0;
    virtual Rate_shaped03_game* GetA() = 0;
    virtual Rate_shaped03_game* GetB() = 0;
};

// GLOBAL: 0x00b43da4
extern ResSim_shaped03_game* gpB43da4_shaped03_game;

struct OB_NOVTABLE Query_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void GetRange(uint32_t kind, int32_t* pLo, int32_t* pHi) = 0;
    uint8_t mPad[0x74 - 4];
    Curve_shaped03_game* mpCurveA;
    Curve_shaped03_game* mpCurveB;
};

// FUNCTION: 0x004c4750
uint32_t Fn004c4750(Query_shaped03_game* pQuery, uint32_t a, uint32_t b, int32_t* pOut)
{
    int32_t nLo;
    int32_t nHi;
    pQuery->GetRange(2, &nLo, &nHi);
    if (pQuery->mpCurveA) {
        float fValue = gpB43da4_shaped03_game->GetA()->Rate(a, b);
        int32_t n = static_cast<int32_t>(pQuery->mpCurveA->GetOutputValue(fValue));
        if (n < nLo) {
            *pOut = -n;
            return 0;
        }
        if (n >= nHi) {
            *pOut = n / 2;
            return 2;
        }
    }
    *pOut = 0;
    return 1;
}

// FUNCTION: 0x004c47f0
uint32_t Fn004c47f0(Query_shaped03_game* pQuery, uint32_t a, uint32_t b, int32_t* pOut)
{
    int32_t nLo;
    int32_t nHi;
    pQuery->GetRange(3, &nLo, &nHi);
    if (pQuery->mpCurveB) {
        float fValue = gpB43da4_shaped03_game->GetB()->Rate(a, b);
        int32_t n = static_cast<int32_t>(pQuery->mpCurveB->GetOutputValue(fValue));
        if (n < nLo) {
            *pOut = -n;
            return 0;
        }
        if (n >= nHi) {
            *pOut = n / 2;
            return 2;
        }
    }
    *pOut = 0;
    return 1;
}

// ---- batch 7 ----
struct OB_NOVTABLE PolSim_shaped03_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual void P37() = 0;
    virtual void P38() = 0;
    virtual void P39() = 0;
    virtual void P40() = 0;
    virtual void P41() = 0;
    virtual void P42() = 0;
    virtual void P43() = 0;
    virtual void P44() = 0;
    virtual void P45() = 0;
    virtual void P46() = 0;
    virtual void P47() = 0;
    virtual float GetFactor() = 0;
    virtual void P49() = 0;
    virtual void P50() = 0;
    virtual void P51() = 0;
    virtual void P52() = 0;
    virtual void P53() = 0;
    virtual void P54() = 0;
    virtual void P55() = 0;
    virtual void P56() = 0;
    virtual void P57() = 0;
    virtual void GetCountA(uint32_t d, uint32_t* pOut) = 0;
    virtual void GetCountB(uint32_t d, uint32_t* pOut) = 0;
};

// GLOBAL: 0x00b43d9c
extern PolSim_shaped03_game* gpB43d9c_shaped03_game;

// FUNCTION: 0x004c83b0
bool Fn004c83b0(uint32_t a, uint32_t b, bool c, uint32_t d)
{
    if (c) {
        uint32_t nCount = 0;
        gpB43d9c_shaped03_game->GetCountA(d, &nCount);
        nCount = static_cast<uint32_t>(static_cast<float>(nCount) * gpB43d9c_shaped03_game->GetFactor());
        return Fn004c6bf0(a, b, nCount);
    }
    return true;
}

// FUNCTION: 0x004c85f0
bool Fn004c85f0(uint32_t a, uint32_t b, bool c, uint32_t d)
{
    if (c) {
        uint32_t nCount = 0;
        gpB43d9c_shaped03_game->GetCountB(d, &nCount);
        nCount = static_cast<uint32_t>(static_cast<float>(nCount) * gpB43d9c_shaped03_game->GetFactor());
        return Fn004c6bf0(a, b, nCount);
    }
    return true;
}

// ---- batch 8 ----
struct OB_NOVTABLE Fetch_shaped03_game {
    virtual bool P0() = 0;
    virtual void P1() = 0;
    virtual void Release() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void Fetch(uint32_t a, uint32_t* pC, uint32_t* pB, uint32_t* pA) = 0;
};

struct OB_NOVTABLE Provider_shaped03_game {
    virtual bool QueryInterface(uint32_t iid, void** ppOut) = 0;
};

// GLOBAL: 0x00b43d78
extern Provider_shaped03_game* gpB43d78_p_shaped03_game;
// GLOBAL: 0x00b43d98
extern Provider_shaped03_game* gpB43d98_p_shaped03_game;

#ifdef OB_DRAFTS
// CLOSE: 0x004c72e0 score 25
bool Fn004c72e0(uint32_t a, uint32_t b, bool c, uint32_t /*d*/)
{
    if (c) {
        Fetch_shaped03_game* pFetch;
        if (gpB43d78_p_shaped03_game->QueryInterface(0xc9c00435, reinterpret_cast<void**>(&pFetch))) {
            uint32_t nA;
            uint32_t nB;
            uint32_t nC;
            pFetch->Fetch(a, &nC, &nB, &nA);
            pFetch->Release();
            return Fn004c6bf0(a, b, nA);
        }
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004c74f0 score 25
bool Fn004c74f0(uint32_t a, uint32_t b, bool c, uint32_t /*d*/)
{
    if (c) {
        Fetch_shaped03_game* pFetch;
        if (gpB43d98_p_shaped03_game->QueryInterface(0xc9c00435, reinterpret_cast<void**>(&pFetch))) {
            uint32_t nA;
            uint32_t nB;
            uint32_t nC;
            pFetch->Fetch(a, &nC, &nB, &nA);
            pFetch->Release();
            return Fn004c6bf0(a, b, nA);
        }
        return false;
    }
    return true;
}
#endif
