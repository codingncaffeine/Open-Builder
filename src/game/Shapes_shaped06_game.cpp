// Shape families of packet shaped06_game (pairs written by hand, one member first, then the other).
#include <cctype>
#include "common/types.h"
#include "common/compiler.h"

// ---- GZOnMouseUpL pair: one call on this, return true

struct View_6856b0_shaped06_game {
    // STUB: 0x99be1e
    void Fn0099be1e();
    bool GZOnMouseUpL(uint32_t a, uint32_t b, uint32_t c);
};

// FUNCTION: 0x006856b0
bool View_6856b0_shaped06_game::GZOnMouseUpL(uint32_t /*a*/, uint32_t /*b*/, uint32_t /*c*/)
{
    Fn0099be1e();
    return true;
}

struct View_79c550_shaped06_game {
    // STUB: 0x79c1d0
    void DoPopupStringListMenu();
    bool GZOnMouseDownR(uint32_t a, uint32_t b, uint32_t c);
};

// FUNCTION: 0x0079c550
bool View_79c550_shaped06_game::GZOnMouseDownR(uint32_t /*a*/, uint32_t /*b*/, uint32_t /*c*/)
{
    DoPopupStringListMenu();
    return true;
}

// ---- flag bit getters

struct View_619890_shaped06_game {
    uint8_t pad[0x13c];
    uint32_t mnFlags;
    uint32_t GetFlag29();
    uint32_t GetFlag30();
};

// FUNCTION: 0x00619890
uint32_t View_619890_shaped06_game::GetFlag29()
{
    return (mnFlags >> 29) & 1;
}

// FUNCTION: 0x006199c0
uint32_t View_619890_shaped06_game::GetFlag30()
{
    return (mnFlags >> 30) & 1;
}

// ---- Init with a key and a data table

struct Info_b0b6d0_shaped06_game {
    uint32_t mn;
};

// GLOBAL: 0x00b0b6d0
extern Info_b0b6d0_shaped06_game gb0b6d0;
// GLOBAL: 0x00b0c388
extern Info_b0b6d0_shaped06_game gb0c388;

struct View_648050_shaped06_game {
    uint8_t pad[0x24];
    uint32_t mnKey;
    // STUB: 0x654710
    uint32_t Init(uint32_t id, Info_b0b6d0_shaped06_game* pInfo);
    uint32_t Fn00648050();
    uint32_t Fn00652a80();
};

// FUNCTION: 0x00648050
uint32_t View_648050_shaped06_game::Fn00648050()
{
    mnKey = 0x2a183167;
    return Init(0xea0a5acf, &gb0b6d0);
}

// FUNCTION: 0x00652a80
uint32_t View_648050_shaped06_game::Fn00652a80()
{
    mnKey = 0x8a13918a;
    return Init(0xca15ed6b, &gb0c388);
}

// ---- release a field and clear it

struct Unk_shaped06_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Release() = 0;
};

struct View_7cb970_shaped06_game {
    uint8_t pad[0xc];
    Unk_shaped06_game* mpObj;
    void Fn007cb970();
};

// FUNCTION: 0x007cb970
void View_7cb970_shaped06_game::Fn007cb970()
{
    if (mpObj) {
        mpObj->Release();
        mpObj = 0;
    }
}

struct View_619680_shaped06_game {
    uint8_t pad[0x140];
    Unk_shaped06_game* mpObj;
    void Fn00619680();
};

// FUNCTION: 0x00619680
void View_619680_shaped06_game::Fn00619680()
{
    if (mpObj) {
        mpObj->Release();
        mpObj = 0;
    }
}

// ---- set something, then update the shadow

struct View_61f480_shaped06_game {
    // STUB: 0x61bb60
    void Fn0061bb60(uint32_t a);
    // STUB: 0x61b910
    void Fn0061b910(uint32_t a);
    // STUB: 0x61e340
    void UpdateShadow(bool b);
    void Fn0061f480(uint32_t a);
    void Fn0061f4a0(uint32_t a);
};

// FUNCTION: 0x0061f480
void View_61f480_shaped06_game::Fn0061f480(uint32_t a)
{
    Fn0061bb60(a);
    UpdateShadow(true);
}

// FUNCTION: 0x0061f4a0
void View_61f480_shaped06_game::Fn0061f4a0(uint32_t a)
{
    Fn0061b910(a);
    UpdateShadow(true);
}

// ---- isdigit / isalpha as bool

// the runtime's isdigit, the original's own copy
// STUB: 0x009ef61d
int CrtIsdigit_shaped06_game(int c);

// FUNCTION: 0x0063bf30
uint32_t Fn0063bf30(uint8_t c)
{
    return CrtIsdigit_shaped06_game(c) != 0;
}

// FUNCTION: 0x0063bf70
uint32_t Fn0063bf70(uint8_t c)
{
    return isalpha(c) != 0;
}

// ---- constructors: base init with a number, two vtables, a clear byte

struct View_648ec0_shaped06_game {
    uint32_t mpVtbl;
    uint32_t mpVtbl2;
    uint8_t pad[0x388];
    uint8_t mbFlag;
    // STUB: 0x657fd0
    void Fn00657fd0(uint32_t n);
    View_648ec0_shaped06_game* Fn00648ec0();
    View_648ec0_shaped06_game* Fn00653d60();
};

// FUNCTION: 0x00648ec0
View_648ec0_shaped06_game* View_648ec0_shaped06_game::Fn00648ec0()
{
    Fn00657fd0(4);
    mpVtbl = 0xaa99a8;
    mpVtbl2 = 0xaa9994;
    mbFlag = 0;
    return this;
}

// FUNCTION: 0x00653d60
View_648ec0_shaped06_game* View_648ec0_shaped06_game::Fn00653d60()
{
    Fn00657fd0(7);
    mpVtbl = 0xaaa5c0;
    mpVtbl2 = 0xaaa5ac;
    mbFlag = 0;
    return this;
}

// ---- key down / key up forward to slot 144 of this with a field

struct View_682100_shaped06_game {
    virtual void Slot000() = 0;
    virtual void Slot001() = 0;
    virtual void Slot002() = 0;
    virtual void Slot003() = 0;
    virtual void Slot004() = 0;
    virtual void Slot005() = 0;
    virtual void Slot006() = 0;
    virtual void Slot007() = 0;
    virtual void Slot008() = 0;
    virtual void Slot009() = 0;
    virtual void Slot010() = 0;
    virtual void Slot011() = 0;
    virtual void Slot012() = 0;
    virtual void Slot013() = 0;
    virtual void Slot014() = 0;
    virtual void Slot015() = 0;
    virtual void Slot016() = 0;
    virtual void Slot017() = 0;
    virtual void Slot018() = 0;
    virtual void Slot019() = 0;
    virtual void Slot020() = 0;
    virtual void Slot021() = 0;
    virtual void Slot022() = 0;
    virtual void Slot023() = 0;
    virtual void Slot024() = 0;
    virtual void Slot025() = 0;
    virtual void Slot026() = 0;
    virtual void Slot027() = 0;
    virtual void Slot028() = 0;
    virtual void Slot029() = 0;
    virtual void Slot030() = 0;
    virtual void Slot031() = 0;
    virtual void Slot032() = 0;
    virtual void Slot033() = 0;
    virtual void Slot034() = 0;
    virtual void Slot035() = 0;
    virtual void Slot036() = 0;
    virtual void Slot037() = 0;
    virtual void Slot038() = 0;
    virtual void Slot039() = 0;
    virtual void Slot040() = 0;
    virtual void Slot041() = 0;
    virtual void Slot042() = 0;
    virtual void Slot043() = 0;
    virtual void Slot044() = 0;
    virtual void Slot045() = 0;
    virtual void Slot046() = 0;
    virtual void Slot047() = 0;
    virtual void Slot048() = 0;
    virtual void Slot049() = 0;
    virtual void Slot050() = 0;
    virtual void Slot051() = 0;
    virtual void Slot052() = 0;
    virtual void Slot053() = 0;
    virtual void Slot054() = 0;
    virtual void Slot055() = 0;
    virtual void Slot056() = 0;
    virtual void Slot057() = 0;
    virtual void Slot058() = 0;
    virtual void Slot059() = 0;
    virtual void Slot060() = 0;
    virtual void Slot061() = 0;
    virtual void Slot062() = 0;
    virtual void Slot063() = 0;
    virtual void Slot064() = 0;
    virtual void Slot065() = 0;
    virtual void Slot066() = 0;
    virtual void Slot067() = 0;
    virtual void Slot068() = 0;
    virtual void Slot069() = 0;
    virtual void Slot070() = 0;
    virtual void Slot071() = 0;
    virtual void Slot072() = 0;
    virtual void Slot073() = 0;
    virtual void Slot074() = 0;
    virtual void Slot075() = 0;
    virtual void Slot076() = 0;
    virtual void Slot077() = 0;
    virtual void Slot078() = 0;
    virtual void Slot079() = 0;
    virtual void Slot080() = 0;
    virtual void Slot081() = 0;
    virtual void Slot082() = 0;
    virtual void Slot083() = 0;
    virtual void Slot084() = 0;
    virtual void Slot085() = 0;
    virtual void Slot086() = 0;
    virtual void Slot087() = 0;
    virtual void Slot088() = 0;
    virtual void Slot089() = 0;
    virtual void Slot090() = 0;
    virtual void Slot091() = 0;
    virtual void Slot092() = 0;
    virtual void Slot093() = 0;
    virtual void Slot094() = 0;
    virtual void Slot095() = 0;
    virtual void Slot096() = 0;
    virtual void Slot097() = 0;
    virtual void Slot098() = 0;
    virtual void Slot099() = 0;
    virtual void Slot100() = 0;
    virtual void Slot101() = 0;
    virtual void Slot102() = 0;
    virtual void Slot103() = 0;
    virtual void Slot104() = 0;
    virtual void Slot105() = 0;
    virtual void Slot106() = 0;
    virtual void Slot107() = 0;
    virtual void Slot108() = 0;
    virtual void Slot109() = 0;
    virtual void Slot110() = 0;
    virtual void Slot111() = 0;
    virtual void Slot112() = 0;
    virtual void Slot113() = 0;
    virtual void Slot114() = 0;
    virtual void Slot115() = 0;
    virtual void Slot116() = 0;
    virtual void Slot117() = 0;
    virtual void Slot118() = 0;
    virtual void Slot119() = 0;
    virtual void Slot120() = 0;
    virtual void Slot121() = 0;
    virtual void Slot122() = 0;
    virtual void Slot123() = 0;
    virtual void Slot124() = 0;
    virtual void Slot125() = 0;
    virtual void Slot126() = 0;
    virtual void Slot127() = 0;
    virtual void Slot128() = 0;
    virtual void Slot129() = 0;
    virtual void Slot130() = 0;
    virtual void Slot131() = 0;
    virtual void Slot132() = 0;
    virtual void Slot133() = 0;
    virtual void Slot134() = 0;
    virtual void Slot135() = 0;
    virtual void Slot136() = 0;
    virtual void Slot137() = 0;
    virtual void Slot138() = 0;
    virtual void Slot139() = 0;
    virtual void Slot140() = 0;
    virtual void Slot141() = 0;
    virtual void Slot142() = 0;
    virtual void Slot143() = 0;
    virtual bool Slot144(uint32_t id, uint32_t kind, uint32_t a, uint32_t b, uint32_t c) = 0;
    uint8_t pad[0x48];
    uint32_t mnId;
    bool GZOnKeyDown(uint32_t a, uint32_t b);
    bool GZOnKeyUp(uint32_t a, uint32_t b);
};

// FUNCTION: 0x00682100
bool View_682100_shaped06_game::GZOnKeyDown(uint32_t a, uint32_t b)
{
    return Slot144(mnId, 5, a, b, 0);
}

// FUNCTION: 0x00682120
bool View_682100_shaped06_game::GZOnKeyUp(uint32_t a, uint32_t b)
{
    return Slot144(mnId, 6, a, b, 0);
}

// ---- EnterUI / LeaveUI

struct Obj_645310_shaped06_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04(void* p) = 0;
    virtual void Slot05(void* p) = 0;
};

struct Owner_645310_shaped06_game {
    virtual void Slot000() = 0;
    virtual void Slot001() = 0;
    virtual void Slot002() = 0;
    virtual void Slot003() = 0;
    virtual void Slot004() = 0;
    virtual void Slot005() = 0;
    virtual void Slot006() = 0;
    virtual void Slot007() = 0;
    virtual void Slot008() = 0;
    virtual void Slot009() = 0;
    virtual void Slot010() = 0;
    virtual void Slot011() = 0;
    virtual void Slot012() = 0;
    virtual void Slot013() = 0;
    virtual void Slot014() = 0;
    virtual void Slot015() = 0;
    virtual void Slot016() = 0;
    virtual void Slot017() = 0;
    virtual void Slot018() = 0;
    virtual void Slot019() = 0;
    virtual void Slot020() = 0;
    virtual void Slot021() = 0;
    virtual void Slot022() = 0;
    virtual void Slot023() = 0;
    virtual void Slot024() = 0;
    virtual void Slot025() = 0;
    virtual void Slot026() = 0;
    virtual void Slot027() = 0;
    virtual void Slot028() = 0;
    virtual void Slot029() = 0;
    virtual void Slot030() = 0;
    virtual void Slot031() = 0;
    virtual void Slot032() = 0;
    virtual void Slot033() = 0;
    virtual void Slot034() = 0;
    virtual void Slot035() = 0;
    virtual void Slot036() = 0;
    virtual void Slot037() = 0;
    virtual void Slot038() = 0;
    virtual void Slot039() = 0;
    virtual void Slot040() = 0;
    virtual void Slot041() = 0;
    virtual void Slot042() = 0;
    virtual void Slot043() = 0;
    virtual void Slot044() = 0;
    virtual void Slot045() = 0;
    virtual void Slot046() = 0;
    virtual void* Slot47() = 0;
};

// STUB: 0x602180
Obj_645310_shaped06_game* Fn00602180();

struct View_645310_shaped06_game {
    uint8_t pad[0x14];
    Owner_645310_shaped06_game* mpOwner;
    void EnterUI();
    void LeaveUI();
};

// FUNCTION: 0x00645310
void View_645310_shaped06_game::EnterUI()
{
    void* p = mpOwner->Slot47();
    if (p) {
        Fn00602180()->Slot04(p);
    }
}

// FUNCTION: 0x00645340
void View_645310_shaped06_game::LeaveUI()
{
    void* p = mpOwner->Slot47();
    if (p) {
        Fn00602180()->Slot05(p);
    }
}

// ---- byte-lane test of a sub-object's lookup

struct Sub_61aee0_shaped06_game {
    // STUB: 0x619b70
    uint32_t Fn00619b70(uint32_t a);
};

struct View_61aee0_shaped06_game {
    uint8_t pad[0x108];
    Sub_61aee0_shaped06_game mSub;
    uint32_t Fn0061aee0(uint32_t a);
    uint32_t Fn0061af10(uint32_t a);
};

// FUNCTION: 0x0061aee0
uint32_t View_61aee0_shaped06_game::Fn0061aee0(uint32_t a)
{
    uint32_t v = mSub.Fn00619b70(a);
    v = ((v & 0x07070707) + 0x07070707) & 0x08080808;
    return (v * 0x01020408) >> 27;
}

// FUNCTION: 0x0061af10
uint32_t View_61aee0_shaped06_game::Fn0061af10(uint32_t a)
{
    uint32_t v = mSub.Fn00619b70(a);
    v = ((v & 0x03030303) + 0x03030303) & 0x04040404;
    return (v * 0x01020408) >> 26;
}

// ---- init once, then StaticInit

// GLOBAL: 0x00b46730
extern uint8_t gb46730;
// GLOBAL: 0x00b46820
extern uint8_t gb46820;

// STUB: 0x648a90
void Fn00648a90();
// STUB: 0x653640
void Fn00653640();
// STUB: 0x65ae80
void Fn0065ae80();

struct View_648bc0_shaped06_game {
    virtual void Slot000() = 0;
    virtual void Slot001() = 0;
    virtual void Slot002() = 0;
    virtual void Slot003() = 0;
    virtual void Slot004() = 0;
    virtual bool Slot05() = 0;
    // STUB: 0x65c070
    void StaticInit();
    bool Fn00648bc0();
    bool Fn00653770();
};

// FUNCTION: 0x00648bc0
bool View_648bc0_shaped06_game::Fn00648bc0()
{
    if (!gb46730) {
        Fn00648a90();
    }
    if (!Slot05()) {
        StaticInit();
        Fn0065ae80();
    }
    return true;
}

// FUNCTION: 0x00653770
bool View_648bc0_shaped06_game::Fn00653770()
{
    if (!gb46820) {
        Fn00653640();
    }
    if (!Slot05()) {
        StaticInit();
        Fn0065ae80();
    }
    return true;
}

// ---- constructors of a table-holding object

struct Table_67e360_shaped06_game {
    uint8_t mPad[4];
    uint32_t mn4;
    uint32_t mn8;
    uint32_t mnC;
    uint32_t mn10;
    // STUB: 0x829bc0
    void InitializeBuckets(uint32_t n);
};

struct View_67e360_shaped06_game {
    uint32_t mpVtbl;
    uint8_t pad[0xc];
    uint8_t mbFlag10;
    uint8_t mbFlag11;
    uint8_t pad2[2];
    Table_67e360_shaped06_game mTable;
    // STUB: 0x97564d
    void Fn0097564d();
    View_67e360_shaped06_game* Fn0067e360();
    View_67e360_shaped06_game* Fn0067e3a0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0067e360 score 2 (push 0x64 scheduled before the last store)
View_67e360_shaped06_game* View_67e360_shaped06_game::Fn0067e360()
{
    Fn0097564d();
    uint32_t z = 0;
    Table_67e360_shaped06_game* t = &mTable;
    mpVtbl = 0xaaeef8;
    mbFlag10 = 1;
    mbFlag11 = static_cast<uint8_t>(z);
    t->mn4 = z;
    t->mn8 = z;
    t->mnC = z;
    t->mn10 = z;
    t->InitializeBuckets(100);
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0067e3a0 score 2 (push 0x64 scheduled before the last store)
View_67e360_shaped06_game* View_67e360_shaped06_game::Fn0067e3a0()
{
    Fn0097564d();
    uint32_t z = 0;
    Table_67e360_shaped06_game* t = &mTable;
    mpVtbl = 0xaaef2c;
    mbFlag10 = 1;
    mbFlag11 = static_cast<uint8_t>(z);
    t->mn4 = z;
    t->mn8 = z;
    t->mnC = z;
    t->mn10 = z;
    t->InitializeBuckets(100);
    return this;
}
#endif

// ---- set a value through a slot, flag a change in the bits 16-17

struct View_65a900_shaped06_game {
    virtual void Slot000() = 0;
    virtual void Slot001() = 0;
    virtual void Slot002() = 0;
    virtual void Slot003() = 0;
    virtual void Slot004() = 0;
    virtual void Slot005() = 0;
    virtual void Slot006() = 0;
    virtual void Slot007() = 0;
    virtual void Slot008() = 0;
    virtual void Slot009() = 0;
    virtual void Slot010() = 0;
    virtual void Slot011() = 0;
    virtual uint32_t Slot12() = 0;
    uint8_t pad[0x25c];
    uint8_t mbDirty;
    // STUB: 0x619ec0
    void Fn00619ec0(uint32_t a);
    // STUB: 0x619f70
    void Fn00619f70(uint32_t a);
    void Fn0065a900(uint32_t a);
    void Fn0065a940(uint32_t a);
};

// FUNCTION: 0x0065a900
void View_65a900_shaped06_game::Fn0065a900(uint32_t a)
{
    uint32_t before = Slot12() & 0x30000;
    Fn00619ec0(a);
    if (((Slot12() & 0x30000) ^ before) != 0) {
        mbDirty = 1;
    }
}

// FUNCTION: 0x0065a940
void View_65a900_shaped06_game::Fn0065a940(uint32_t a)
{
    uint32_t before = Slot12() & 0x30000;
    Fn00619f70(a);
    if (((Slot12() & 0x30000) ^ before) != 0) {
        mbDirty = 1;
    }
}

// ---- GZPaint of a catalog view

struct Painter_675d80_shaped06_game {
    virtual void Slot000() = 0;
    virtual void Slot001() = 0;
    virtual void Slot002() = 0;
    virtual void Slot003() = 0;
    virtual void Slot004() = 0;
    virtual void Slot005() = 0;
    virtual bool Slot06(uint32_t a) = 0;
    virtual void Slot07(uint32_t a) = 0;
    virtual void SlotA00() = 0;
    virtual void SlotA01() = 0;
    virtual void SlotA02() = 0;
    virtual void SlotA03() = 0;
    virtual void SlotA04() = 0;
    virtual void SlotA05() = 0;
    virtual void SlotA06() = 0;
    virtual void SlotA07() = 0;
    virtual void SlotA08() = 0;
    virtual void SlotA09() = 0;
    virtual void SlotA10() = 0;
    virtual void SlotA11() = 0;
    virtual void Slot20(uint32_t a, void* p, uint32_t b) = 0;
};
struct View_675d80_shaped06_game {
    uint8_t pad[0x24];
    uint32_t mData24;
    uint8_t pad2[0x68 - 0x28];
    Painter_675d80_shaped06_game* mpPainter;
    // STUB: 0x949ade
    bool HandleStartCdataSection();
    bool GZPaint();
};

// FUNCTION: 0x00675d80
bool View_675d80_shaped06_game::GZPaint()
{
    if (mpPainter->Slot06(0x8001)) {
        mpPainter->Slot20(0, &mData24, 0);
        mpPainter->Slot07(0x8001);
    }
    return HandleStartCdataSection();
}

struct View_6821f0_shaped06_game {
    uint8_t pad[0x68];
    Painter_675d80_shaped06_game* mpPainter;
    uint8_t pad2[0xd8 - 0x6c];
    uint32_t mDataD8;
    // STUB: 0x949ade
    bool HandleStartCdataSection();
    bool GZPaint();
};

// FUNCTION: 0x006821f0
bool View_6821f0_shaped06_game::GZPaint()
{
    if (mpPainter->Slot06(0x8001)) {
        mpPainter->Slot20(0, &mDataD8, 0);
        mpPainter->Slot07(0x8001);
    }
    return HandleStartCdataSection();
}

// ---- call slot 10 of the enclosing object with a pointer and the pointer + 0xc

struct Outer_654140_shaped06_game {
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
    virtual void Slot10(float* p, float* q) = 0;
};

struct View_654140_shaped06_game {
    void Fn00654140(float* p);
};

// FUNCTION: 0x00654140
void View_654140_shaped06_game::Fn00654140(float* p)
{
    Outer_654140_shaped06_game* o = reinterpret_cast<Outer_654140_shaped06_game*>(reinterpret_cast<uint8_t*>(this) - 0x24c);
    o->Slot10(p, p + 3);
}

struct View_6194e0_shaped06_game {
    void Fn006194e0(float* p);
};

// FUNCTION: 0x006194e0
void View_6194e0_shaped06_game::Fn006194e0(float* p)
{
    Outer_654140_shaped06_game* o = reinterpret_cast<Outer_654140_shaped06_game*>(reinterpret_cast<uint8_t*>(this) - 0x178);
    o->Slot10(p, p + 3);
}

// ---- tree erase: release two owned objects per node, delete the node

// STUB: 0x90cf63
void StlDelete_shaped06(void* p);

struct Rel_shaped06_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Release() = 0;
};

struct Node_667fc0_shaped06_game {
    uint8_t pad[8];
    Node_667fc0_shaped06_game* mpLeft;
    Node_667fc0_shaped06_game* mpRight;
    uint8_t padC[4];
    Rel_shaped06_game* mpA;
    Rel_shaped06_game* mpB;
};

struct View_667fc0_shaped06_game {
    // The first member of the pair erases from the right child, then the left.
    void Erase(Node_667fc0_shaped06_game* pNode);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00667fc0 score 11-16 (logic same; null test loads eax instead of ecx)
void View_667fc0_shaped06_game::Erase(Node_667fc0_shaped06_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpRight);
        Node_667fc0_shaped06_game* pLeft = pNode->mpLeft;
        if (pNode->mpB) {
            pNode->mpB->Release();
        }
        if (pNode->mpA) {
            pNode->mpA->Release();
        }
        StlDelete_shaped06(pNode);
        pNode = pLeft;
    }
}
#endif

struct Node_79fad0_shaped06_game {
    uint8_t pad[8];
    Node_79fad0_shaped06_game* mpLeft;
    Node_79fad0_shaped06_game* mpRight;
    Rel_shaped06_game* mpA;
    Rel_shaped06_game* mpB;
};

struct View_79fad0_shaped06_game {
    void Erase(Node_79fad0_shaped06_game* pNode);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0079fad0 score 11-16 (logic same; null test loads eax instead of ecx)
void View_79fad0_shaped06_game::Erase(Node_79fad0_shaped06_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpRight);
        Node_79fad0_shaped06_game* pLeft = pNode->mpLeft;
        if (pNode->mpB) {
            pNode->mpB->Release();
        }
        if (pNode->mpA) {
            pNode->mpA->Release();
        }
        StlDelete_shaped06(pNode);
        pNode = pLeft;
    }
}
#endif

// ---- QueryInterface chain

struct QI_shaped06_game {
    virtual bool QueryInterface(uint32_t id, void** ppOut) = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

// FUNCTION: 0x00648360
bool OB_STDCALL Fn00648360(QI_shaped06_game* pObj, void** ppOut)
{
    QI_shaped06_game* pFound = 0;
    if (pObj->QueryInterface(0x49c05b9f, reinterpret_cast<void**>(&pFound))) {
        bool bOk = pFound->QueryInterface(0x4a10afc2, ppOut);
        if (pFound) {
            pFound->Release();
        }
        return bOk;
    }
    if (pFound) {
        pFound->Release();
    }
    return false;
}

// FUNCTION: 0x00652bd0
bool OB_STDCALL Fn00652bd0(QI_shaped06_game* pObj, void** ppOut)
{
    QI_shaped06_game* pFound = 0;
    if (pObj->QueryInterface(0xca16374f, reinterpret_cast<void**>(&pFound))) {
        bool bOk = pFound->QueryInterface(0x4a10afc2, ppOut);
        if (pFound) {
            pFound->Release();
        }
        return bOk;
    }
    if (pFound) {
        pFound->Release();
    }
    return false;
}

// ---- bucket vector clear: delete every chain

struct Chain_6479b0_shaped06_game {
    Chain_6479b0_shaped06_game* mpNext;
    uint8_t pad[0x10];
    Rel_shaped06_game* mpObj;
};

struct View_6479b0_shaped06_game {
    uint8_t pad[4];
    Chain_6479b0_shaped06_game** mpBegin;
    Chain_6479b0_shaped06_game** mpEnd;
    uint8_t pad2[4];
    uint32_t mnCount;
    void Clear();
};

#ifdef OB_DRAFTS
// CLOSE: 0x006479b0 score 11-16 (logic same; null test loads eax instead of ecx)
void View_6479b0_shaped06_game::Clear()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        Chain_6479b0_shaped06_game* p = mpBegin[i];
        while (p) {
            Chain_6479b0_shaped06_game* pNext = p->mpNext;
            if (p->mpObj) {
                p->mpObj->Release();
            }
            StlDelete_shaped06(p);
            p = pNext;
        }
        mpBegin[i] = 0;
    }
    mnCount = 0;
}
#endif

struct Chain_7d1b40_shaped06_game {
    Chain_7d1b40_shaped06_game* mpNext;
    uint8_t pad[4];
    Rel_shaped06_game* mpObj;
};

struct View_7d1b40_shaped06_game {
    uint8_t pad[4];
    Chain_7d1b40_shaped06_game** mpBegin;
    Chain_7d1b40_shaped06_game** mpEnd;
    uint8_t pad2[4];
    uint32_t mnCount;
    void Clear();
};

#ifdef OB_DRAFTS
// CLOSE: 0x007d1b40 score 11-16 (logic same; null test loads eax instead of ecx)
void View_7d1b40_shaped06_game::Clear()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        Chain_7d1b40_shaped06_game* p = mpBegin[i];
        while (p) {
            Chain_7d1b40_shaped06_game* pNext = p->mpNext;
            if (p->mpObj) {
                p->mpObj->Release();
            }
            StlDelete_shaped06(p);
            p = pNext;
        }
        mpBegin[i] = 0;
    }
    mnCount = 0;
}
#endif

// ---- constructors with a list head node

// STUB: 0x90cf54
void* StlNew_shaped06(uint32_t n);

struct ListNode_658290_shaped06_game {
    ListNode_658290_shaped06_game* mpA;
    ListNode_658290_shaped06_game* mpB;
};

struct View_658290_shaped06_game {
    uint32_t mpVtbl0;
    uint8_t pad[4];
    uint32_t mpVtbl8;
    uint32_t mpVtblC;
    ListNode_658290_shaped06_game* mpHead;
    uint32_t mnKey;
    // STUB: 0x90d957
    void Fn0090d957();
    View_658290_shaped06_game* Fn00658290();
    View_658290_shaped06_game* Fn00658300();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00658290 score 4 (dead first stores of two vtable fields kept in the original)
View_658290_shaped06_game* View_658290_shaped06_game::Fn00658290()
{
    Fn0090d957();
    mpVtbl8 = 0xaa75b0;
    mpVtblC = 0xa81174;
    mpVtbl0 = 0xaaaac4;
    mpVtbl8 = 0xaaaaac;
    mpVtblC = 0xaaaa9c;
    mpHead = 0;
    ListNode_658290_shaped06_game* p = static_cast<ListNode_658290_shaped06_game*>(StlNew_shaped06(0xc));
    p->mpA = p;
    p->mpB = p;
    mpHead = p;
    mnKey = 0x49c05b9f;
    mpVtbl0 = 0xaaab00;
    mpVtbl8 = 0xaaaae8;
    mpVtblC = 0xaaaad8;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00658300 score 4 (same)
View_658290_shaped06_game* View_658290_shaped06_game::Fn00658300()
{
    Fn0090d957();
    mpVtbl8 = 0xaa75b0;
    mpVtblC = 0xa81174;
    mpVtbl0 = 0xaaaac4;
    mpVtbl8 = 0xaaaaac;
    mpVtblC = 0xaaaa9c;
    mpHead = 0;
    ListNode_658290_shaped06_game* p = static_cast<ListNode_658290_shaped06_game*>(StlNew_shaped06(0xc));
    p->mpA = p;
    p->mpB = p;
    mpHead = p;
    mnKey = 0xca16374f;
    mpVtbl0 = 0xaaab3c;
    mpVtbl8 = 0xaaab24;
    mpVtblC = 0xaaab14;
    return this;
}
#endif

// ---- factory: create by id, query the new object, destroy it on failure

struct Obj_67d820_shaped06_game {
    virtual bool Slot00(uint32_t a, void** pp) = 0;
};

struct Sub_67d820_shaped06_game {
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
    virtual void Destroy(bool bDelete) = 0;
};

struct Layout_67d820_shaped06_game {
    Obj_67d820_shaped06_game* mpObj() { return reinterpret_cast<Obj_67d820_shaped06_game*>(this); }
    Sub_67d820_shaped06_game* mpSub() { return reinterpret_cast<Sub_67d820_shaped06_game*>(reinterpret_cast<uint8_t*>(this) + 4); }
    // STUB: 0x67cc50
    Layout_67d820_shaped06_game* CtorA();
    // STUB: 0x67cbc0
    Layout_67d820_shaped06_game* CtorB();
};

// FUNCTION: 0x0067d820
bool OB_STDCALL Fn0067d820(uint32_t id, uint32_t a, void** ppOut)
{
    if (id == 0x6534284a) {
        Layout_67d820_shaped06_game* p = static_cast<Layout_67d820_shaped06_game*>(operator new(0x40));
        Layout_67d820_shaped06_game* pObj = p ? p->CtorA() : 0;
        if (pObj->mpObj()->Slot00(a, ppOut)) {
            return true;
        }
        pObj->mpSub()->Destroy(true);
    }
    *ppOut = 0;
    return false;
}

// FUNCTION: 0x0067d8d0
bool OB_STDCALL Fn0067d8d0(uint32_t id, uint32_t a, void** ppOut)
{
    if (id == 0x5342861) {
        Layout_67d820_shaped06_game* p = static_cast<Layout_67d820_shaped06_game*>(operator new(0x40));
        Layout_67d820_shaped06_game* pObj = p ? p->CtorB() : 0;
        if (pObj->mpObj()->Slot00(a, ppOut)) {
            return true;
        }
        pObj->mpSub()->Destroy(true);
    }
    *ppOut = 0;
    return false;
}

// ---- constructors of a three-part object

struct Part_67cbc0_shaped06_game {
    uint32_t mpVtbl;
    // STUB: 0x975633
    void Fn00975633();
};

struct Part2_67cbc0_shaped06_game {
    uint32_t mpVtbl;
    // STUB: 0x5ff100
    void Fn005ff100();
};

struct View_67cbc0_shaped06_game {
    uint32_t mpVtbl;
    Part_67cbc0_shaped06_game mPartA;
    uint8_t pad[0x1c - 8];
    Part2_67cbc0_shaped06_game mPartB;
    uint8_t pad2[0x30 - 0x20];
    uint32_t mn30;
    uint32_t mn34;
    uint32_t mn38;
    uint32_t mn3c;
    View_67cbc0_shaped06_game* Fn0067cbc0();
    View_67cbc0_shaped06_game* Fn0067cc50();
};

// FUNCTION: 0x0067cbc0
View_67cbc0_shaped06_game* View_67cbc0_shaped06_game::Fn0067cbc0()
{
    Part_67cbc0_shaped06_game* pA = &mPartA;
    mpVtbl = 0xaaeec0;
    pA->Fn00975633();
    Part2_67cbc0_shaped06_game* pB = &mPartB;
    pB->Fn005ff100();
    uint32_t z = 0;
    mn30 = z;
    mpVtbl = 0xaaeff8;
    pA->mpVtbl = 0xaaefc4;
    pB->mpVtbl = 0xaaef60;
    mn34 = z;
    mn38 = z;
    mn3c = z;
    return this;
}

// FUNCTION: 0x0067cc50
View_67cbc0_shaped06_game* View_67cbc0_shaped06_game::Fn0067cc50()
{
    Part_67cbc0_shaped06_game* pA = &mPartA;
    mpVtbl = 0xaaee5c;
    pA->Fn00975633();
    Part2_67cbc0_shaped06_game* pB = &mPartB;
    pB->Fn005ff100();
    uint32_t z = 0;
    mn30 = z;
    mpVtbl = 0xaaf0d0;
    pA->mpVtbl = 0xaaf09c;
    pB->mpVtbl = 0xaaf038;
    mn34 = z;
    mn38 = z;
    mn3c = z;
    return this;
}

// ---- QueryInterface of an object with two extra interfaces at +4 and +8

struct Base0_644f40_shaped06_game {
    virtual void Slot00() = 0;
    virtual void AddRef() = 0;
};

struct Base1_644f40_shaped06_game {
    virtual void Slot00() = 0;
};

struct Base2_644f40_shaped06_game {
    virtual void Slot00() = 0;
};

struct View_644f40_shaped06_game : Base0_644f40_shaped06_game, Base1_644f40_shaped06_game, Base2_644f40_shaped06_game {
    bool QueryInterface(uint32_t id, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00644f40 score 12 (null-check of the upcasts: original shares one null block)
bool View_644f40_shaped06_game::QueryInterface(uint32_t id, void** ppOut)
{
    switch (id) {
    case 0x22e85d8e:
        *ppOut = static_cast<Base1_644f40_shaped06_game*>(this);
        break;
    case 0x452294aa:
        *ppOut = static_cast<Base2_644f40_shaped06_game*>(this);
        break;
    case 1:
    case 0x8b54be51:
        *ppOut = this;
        break;
    default:
        return false;
    }
    AddRef();
    return true;
}
#endif

struct View_809130_shaped06_game : Base0_644f40_shaped06_game, Base1_644f40_shaped06_game, Base2_644f40_shaped06_game {
    bool QueryInterface(uint32_t id, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00809130 score 12 (same)
bool View_809130_shaped06_game::QueryInterface(uint32_t id, void** ppOut)
{
    switch (id) {
    case 0x88ceb67:
        *ppOut = static_cast<Base1_644f40_shaped06_game*>(this);
        break;
    case 0x287fb697:
        *ppOut = static_cast<Base2_644f40_shaped06_game*>(this);
        break;
    case 1:
    case 0xfac0e219:
        *ppOut = this;
        break;
    default:
        return false;
    }
    AddRef();
    return true;
}
#endif

// ---- collect a position and a virtual-base pointer (61af90)

struct Sub_61af90_shaped06_game {
    virtual void Slot000() = 0;
    virtual void Slot001() = 0;
    virtual void Slot002() = 0;
    virtual void Slot003() = 0;
    virtual void Slot004() = 0;
    virtual void Slot005() = 0;
    virtual void Slot006() = 0;
    virtual void Slot007() = 0;
    virtual void GetPosition(float* pOut) = 0;
};

struct View_61af90_shaped06_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    uint8_t padB[0x3c - 4];
    uint32_t* mpVbTable;
    uint8_t padC[0x64 - 0x3c - 4];
    uint8_t mnCount;
    uint8_t mnFlags;
    uint8_t padD[0x8c - 0x65 - 1];
    float mfX;
    float mfY;
    float mfZ;
    void Fn61af90(uint32_t a1, uint32_t a2, void** pArray, uint32_t a4, uint32_t* pCount);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0061af90 score 14 (same logic; instruction scheduling)
void View_61af90_shaped06_game::Fn61af90(uint32_t /*a1*/, uint32_t /*a2*/, void** pArray, uint32_t /*a4*/, uint32_t* pCount)
{
    float pos[3];
    Sub_61af90_shaped06_game* pSub = reinterpret_cast<Sub_61af90_shaped06_game*>(reinterpret_cast<uint8_t*>(this) + 4);
    pSub->GetPosition(pos);
    *pCount = 0;
    mfX = pos[0];
    mfY = pos[1];
    mfZ = pos[2];
    mnFlags |= 1;
    ++mnCount;
    pArray[*pCount] = reinterpret_cast<uint8_t*>(this) + 0x3c + mpVbTable[1];
    ++*pCount;
    Slot01();
}
#endif

// ---- collect a position and a virtual-base pointer (649d00)

struct Sub_649d00_shaped06_game {
    virtual void Slot000() = 0;
    virtual void Slot001() = 0;
    virtual void Slot002() = 0;
    virtual void Slot003() = 0;
    virtual void Slot004() = 0;
    virtual void Slot005() = 0;
    virtual void Slot006() = 0;
    virtual void Slot007() = 0;
    virtual void GetPosition(float* pOut) = 0;
};

struct View_649d00_shaped06_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    uint8_t padB[0x40 - 4];
    uint32_t* mpVbTable;
    uint8_t padC[0x68 - 0x40 - 4];
    uint8_t mnCount;
    uint8_t mnFlags;
    uint8_t padD[0x90 - 0x69 - 1];
    float mfX;
    float mfY;
    float mfZ;
    void Fn649d00(uint32_t a1, uint32_t a2, void** pArray, uint32_t a4, uint32_t* pCount);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00649d00 score 14 (same)
void View_649d00_shaped06_game::Fn649d00(uint32_t /*a1*/, uint32_t /*a2*/, void** pArray, uint32_t /*a4*/, uint32_t* pCount)
{
    float pos[3];
    Sub_649d00_shaped06_game* pSub = reinterpret_cast<Sub_649d00_shaped06_game*>(reinterpret_cast<uint8_t*>(this) + 8);
    pSub->GetPosition(pos);
    *pCount = 0;
    mfX = pos[0];
    mfY = pos[1];
    mfZ = pos[2];
    mnFlags |= 1;
    ++mnCount;
    pArray[*pCount] = reinterpret_cast<uint8_t*>(this) + 0x40 + mpVbTable[1];
    ++*pCount;
    Slot01();
}
#endif


// ---- vector copy constructors of 12-byte elements

struct Elem_64bc00_shaped06_game {
    uint32_t mn[3];
    // STUB: 0x50bcb0
    void CopyFrom(const Elem_64bc00_shaped06_game* pOther);
};

struct View_64bc00_shaped06_game {
    Elem_64bc00_shaped06_game* mpBegin;
    Elem_64bc00_shaped06_game* mpEnd;
    Elem_64bc00_shaped06_game* mpCap;
    View_64bc00_shaped06_game* Fn0064bc00(const View_64bc00_shaped06_game* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0064bc00 score 82 (register allocation: n kept in edi across the new call)
View_64bc00_shaped06_game* View_64bc00_shaped06_game::Fn0064bc00(const View_64bc00_shaped06_game* pOther)
{
    Elem_64bc00_shaped06_game* pFirst = pOther->mpBegin;
    uint32_t n = pOther->mpEnd - pFirst;
    mpBegin = 0;
    mpEnd = 0;
    mpCap = 0;
    if (n) {
        Elem_64bc00_shaped06_game* p = static_cast<Elem_64bc00_shaped06_game*>(StlNew_shaped06(n * sizeof(Elem_64bc00_shaped06_game)));
        mpBegin = p;
        mpEnd = p;
        mpCap = p + n;
        Elem_64bc00_shaped06_game* pLast = pOther->mpEnd;
        pFirst = pOther->mpBegin;
        for (; pFirst != pLast; ++pFirst) {
            if (p) {
                p->CopyFrom(pFirst);
            }
            ++p;
        }
        mpEnd = p;
    }
    return this;
}
#endif

struct Elem_707540_shaped06_game {
    uint32_t mn[3];
    // STUB: 0x462f00
    void CopyFrom(const Elem_707540_shaped06_game* pOther);
};

struct View_707540_shaped06_game {
    Elem_707540_shaped06_game* mpBegin;
    Elem_707540_shaped06_game* mpEnd;
    Elem_707540_shaped06_game* mpCap;
    View_707540_shaped06_game* Fn00707540(const View_707540_shaped06_game* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00707540 score 82 (same)
View_707540_shaped06_game* View_707540_shaped06_game::Fn00707540(const View_707540_shaped06_game* pOther)
{
    Elem_707540_shaped06_game* pFirst = pOther->mpBegin;
    uint32_t n = pOther->mpEnd - pFirst;
    mpBegin = 0;
    mpEnd = 0;
    mpCap = 0;
    if (n) {
        Elem_707540_shaped06_game* p = static_cast<Elem_707540_shaped06_game*>(StlNew_shaped06(n * sizeof(Elem_707540_shaped06_game)));
        mpBegin = p;
        mpEnd = p;
        mpCap = p + n;
        Elem_707540_shaped06_game* pLast = pOther->mpEnd;
        pFirst = pOther->mpBegin;
        for (; pFirst != pLast; ++pFirst) {
            if (p) {
                p->CopyFrom(pFirst);
            }
            ++p;
        }
        mpEnd = p;
    }
    return this;
}
#endif

// ---- erase tail: copy the empty tail range over the finish pointer

struct Tag_639040_shaped06_game {
};

struct S12_639040_shaped06_game {
    uint32_t mn[3];
};

// STUB: 0x6143e0
S12_639040_shaped06_game* Fn006143e0(S12_639040_shaped06_game* pFirst, S12_639040_shaped06_game* pLast, S12_639040_shaped06_game* pDest, const Tag_639040_shaped06_game& tag, int* pDist);
// STUB: 0x506230
S12_639040_shaped06_game* Fn00506230(S12_639040_shaped06_game* pFirst, S12_639040_shaped06_game* pLast, S12_639040_shaped06_game* pDest, const Tag_639040_shaped06_game& tag, int* pDist);

struct View_639040_shaped06_game {
    uint8_t pad[8];
    S12_639040_shaped06_game* mpFinish;
    S12_639040_shaped06_game* mpEnd;
    S12_639040_shaped06_game* mpEndB;
    S12_639040_shaped06_game* mpEndC;
    void Fn00639040();
    void Fn00683b60();
};

// FUNCTION: 0x00639040
void View_639040_shaped06_game::Fn00639040()
{
    Tag_639040_shaped06_game tag;
    S12_639040_shaped06_game* pDest = mpFinish;
    S12_639040_shaped06_game* p = mpEnd;
    mpEnd = Fn006143e0(p, p, pDest, tag, 0);
}

// FUNCTION: 0x00683b60
void View_639040_shaped06_game::Fn00683b60()
{
    Tag_639040_shaped06_game tag;
    S12_639040_shaped06_game* pDest = mpEnd;
    S12_639040_shaped06_game* p = mpEndB;
    mpEndB = Fn00506230(p, p, pDest, tag, 0);
}

// ---- compaction of records whose count drops to zero

struct Rec_6189e0_shaped06_game {
    uint32_t mn0;
    uint32_t mnSize;
    uint32_t mnLeft;
};

struct View_6189e0_shaped06_game {
    uint8_t pad[0x2c];
    uint16_t* mpBegin;
    uint16_t* mpEnd;
    // STUB: 0x6185c0
    void Fn006185c0(uint32_t a, uint32_t n, uint32_t left);
    uint32_t Fn006189e0(Rec_6189e0_shaped06_game* pRecs, uint32_t a, uint32_t nCount);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006189e0 score 9 (count spilled to the stack, branch order of the copy test)
uint32_t View_6189e0_shaped06_game::Fn006189e0(Rec_6189e0_shaped06_game* pRecs, uint32_t a, uint32_t nCount)
{
    Rec_6189e0_shaped06_game* pIn = pRecs;
    Rec_6189e0_shaped06_game* pOut = pIn;
    if (nCount) {
        do {
            Rec_6189e0_shaped06_game* pRec = pIn;
            pIn = pIn + 1;
            pRec->mnSize = mpEnd - mpBegin;
            Fn006185c0(a, pRec->mnSize, pRec->mnLeft);
            pRec->mnLeft = static_cast<uint32_t>(mpEnd - mpBegin) - pRec->mnSize;
            if (pRec->mnLeft) {
                if (pOut != pRec) {
                    *pOut = *pRec;
                }
                ++pOut;
            }
            --nCount;
        } while (nCount);
    }
    return pOut - pRecs;
}
#endif

struct View_618a70_shaped06_game {
    uint8_t pad[0x2c];
    uint16_t* mpBegin;
    uint16_t* mpEnd;
    // STUB: 0x6187d0
    void Fn006187d0(uint32_t a, uint32_t n, uint32_t left);
    uint32_t Fn00618a70(Rec_6189e0_shaped06_game* pRecs, uint32_t a, uint32_t nCount);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00618a70 score 9 (same)
uint32_t View_618a70_shaped06_game::Fn00618a70(Rec_6189e0_shaped06_game* pRecs, uint32_t a, uint32_t nCount)
{
    Rec_6189e0_shaped06_game* pIn = pRecs;
    Rec_6189e0_shaped06_game* pOut = pIn;
    if (nCount) {
        do {
            Rec_6189e0_shaped06_game* pRec = pIn;
            pIn = pIn + 1;
            pRec->mnSize = mpEnd - mpBegin;
            Fn006187d0(a, pRec->mnSize, pRec->mnLeft);
            pRec->mnLeft = static_cast<uint32_t>(mpEnd - mpBegin) - pRec->mnSize;
            if (pRec->mnLeft) {
                if (pOut != pRec) {
                    *pOut = *pRec;
                }
                ++pOut;
            }
            --nCount;
        } while (nCount);
    }
    return pOut - pRecs;
}
#endif

// ---- destructor-like: two vtable stores, then the base's tail call

struct View_681f60_shaped06_game {
    uint32_t mpVtbl0;
    uint8_t pad[4];
    uint32_t mpVtbl8;
    // STUB: 0x90d990
    void Fn0090d990();
    void Fn00681f60();
};

// FUNCTION: 0x00681f60
void View_681f60_shaped06_game::Fn00681f60()
{
    mpVtbl0 = 0xaaf4f0;
    mpVtbl8 = 0xaaf4e0;
    Fn0090d990();
}

struct View_96ba10_shaped06_game {
    uint32_t mpVtbl0;
    uint8_t pad[0x28];
    uint32_t mpVtbl2c;
    // STUB: 0x9133ab
    void Fn009133ab();
    void Fn0096ba10();
};

// FUNCTION: 0x0096ba10
void View_96ba10_shaped06_game::Fn0096ba10()
{
    mpVtbl0 = 0xad75a0;
    mpVtbl2c = 0xad7580;
    Fn009133ab();
}

// ---- vector resize of records (76 and 104 bytes)

struct Tag_61caf0_shaped06_game {
};

struct Elem_61caf0_shaped06_game {
    uint8_t mData[0x4c];
};

// STUB: 0x619df0
Elem_61caf0_shaped06_game* Fn00619df0(Elem_61caf0_shaped06_game* pFirst, Elem_61caf0_shaped06_game* pLast, Elem_61caf0_shaped06_game* pDest, const Tag_61caf0_shaped06_game& tag, int* pDist);

struct View_61caf0_shaped06_game {
    Elem_61caf0_shaped06_game* mpBegin;
    Elem_61caf0_shaped06_game* mpEnd;
    // STUB: 0x61c340
    void Fn0061c340(Elem_61caf0_shaped06_game* pPos, uint32_t nCount, const Elem_61caf0_shaped06_game* pVal);
    void Fn0061caf0(uint32_t n, const Elem_61caf0_shaped06_game* pVal);
};

// FUNCTION: 0x0061caf0
void View_61caf0_shaped06_game::Fn0061caf0(uint32_t n, const Elem_61caf0_shaped06_game* pVal)
{
    Elem_61caf0_shaped06_game* pBegin = mpBegin;
    Elem_61caf0_shaped06_game* pEnd = mpEnd;
    uint32_t nSize = pEnd - pBegin;
    if (n < nSize) {
        Tag_61caf0_shaped06_game tag;
        mpEnd = Fn00619df0(pEnd, pEnd, pBegin + n, tag, 0);
    } else {
        Fn0061c340(pEnd, n - nSize, pVal);
    }
}

struct Elem_7d5eb0_shaped06_game {
    uint8_t mData[0x68];
};

// STUB: 0x7d3bc0
Elem_7d5eb0_shaped06_game* Fn007d3bc0(const Elem_7d5eb0_shaped06_game* pFirst, const Elem_7d5eb0_shaped06_game* pLast, Elem_7d5eb0_shaped06_game* pDest, const Tag_61caf0_shaped06_game& tag, int* pDist);

struct View_7d5eb0_shaped06_game {
    Elem_7d5eb0_shaped06_game* mpBegin;
    Elem_7d5eb0_shaped06_game* mpEnd;
    // STUB: 0x7d5d60
    void Fn007d5d60(Elem_7d5eb0_shaped06_game* pPos, uint32_t nCount, const Elem_7d5eb0_shaped06_game* pVal);
    void Fn007d5eb0(uint32_t n, const Elem_7d5eb0_shaped06_game* pVal);
};

// FUNCTION: 0x007d5eb0
void View_7d5eb0_shaped06_game::Fn007d5eb0(uint32_t n, const Elem_7d5eb0_shaped06_game* pVal)
{
    Elem_7d5eb0_shaped06_game* pBegin = mpBegin;
    Elem_7d5eb0_shaped06_game* pEnd = mpEnd;
    uint32_t nSize = pEnd - pBegin;
    if (n < nSize) {
        Tag_61caf0_shaped06_game tag;
        mpEnd = Fn007d3bc0(pEnd, pEnd, pBegin + n, tag, 0);
    } else {
        Fn007d5d60(pEnd, n - nSize, pVal);
    }
}
