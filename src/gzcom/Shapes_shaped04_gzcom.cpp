// Shape families of packet shaped04_gzcom (pairs), written by hand.
#include "common/types.h"
#include <new>
#include "common/compiler.h"

// ---- 0097edca family
struct Obj_0097edca_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Pad0c() = 0;
    virtual void Pad0d() = 0;
    virtual void Pad0e() = 0;
    virtual void Pad0f() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad1a() = 0;
    virtual void Pad1b() = 0;
    virtual void Pad1c() = 0;
    virtual void Pad1d() = 0;
    virtual void Pad1e() = 0;
    virtual void Pad1f() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual bool Call25(uint32_t a) = 0;
    virtual void Pad26() = 0;
    virtual bool Call27(uint32_t a) = 0;
    virtual void Pad28() = 0;
    virtual bool Call29(uint32_t a, uint32_t b) = 0;
    virtual void Pad2a() = 0;
    virtual bool Call2b(uint32_t a, uint32_t b) = 0;
};

struct View_0097edca_shaped04_gzcom {
    uint32_t mPad0;
    Obj_0097edca_shaped04_gzcom* mpObj;
    bool Fn0097edca(uint32_t* p);
    bool Fn0097edde(uint32_t* p);
    bool Fn0097edf2(uint32_t* p);
    bool Fn0097ee09(uint32_t* p);
};

// FUNCTION: 0x0097edca
bool View_0097edca_shaped04_gzcom::Fn0097edca(uint32_t* p)
{
    return mpObj->Call25(*p);
}

// FUNCTION: 0x0097edde
bool View_0097edca_shaped04_gzcom::Fn0097edde(uint32_t* p)
{
    return mpObj->Call27(*p);
}

// FUNCTION: 0x0097edf2
bool View_0097edca_shaped04_gzcom::Fn0097edf2(uint32_t* p)
{
    return mpObj->Call29(p[0], p[1]);
}

// FUNCTION: 0x0097ee09
bool View_0097edca_shaped04_gzcom::Fn0097ee09(uint32_t* p)
{
    return mpObj->Call2b(p[0], p[1]);
}

// ---- 009c175b / 009c1785
struct View_009c175b_shaped04_gzcom {
    uint8_t mPad[0xc];
    uint8_t mb0c;
    uint8_t mb0d;
    uint8_t mb0e;
    uint8_t mb0f;
    bool Fn009c175b(uint8_t* a, uint8_t* b);
    bool Fn009c1785(uint8_t* a, uint8_t* b);
};

// FUNCTION: 0x009c175b
bool View_009c175b_shaped04_gzcom::Fn009c175b(uint8_t* a, uint8_t* b)
{
    *a = mb0c;
    *b = mb0d;
    return true;
}

// FUNCTION: 0x009c1785
bool View_009c175b_shaped04_gzcom::Fn009c1785(uint8_t* a, uint8_t* b)
{
    *a = mb0e;
    *b = mb0f;
    return true;
}

// ---- 009cad83 / 009caedf
// STUB: 0x009cab5f
uint32_t Fn009cab5f(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
// STUB: 0x009cae39
uint32_t Fn009cae39(uint32_t a, uint32_t b, uint32_t c, uint32_t d);

// FUNCTION: 0x009cad83
uint32_t Fn009cad83(uint32_t a, uint32_t b, uint32_t c)
{
    return Fn009cab5f(a, b, 0, c);
}

// FUNCTION: 0x009caedf
uint32_t Fn009caedf(uint32_t a, uint32_t b, uint32_t c)
{
    return Fn009cae39(a, b, 0, c);
}

// ---- 009a9d7c / 009caeab
// STUB: 0x009a8c68
uint32_t Fn009a8c68(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
// STUB: 0x009cade4
uint32_t Fn009cade4(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);

// FUNCTION: 0x009a9d7c
uint32_t Fn009a9d7c(uint32_t a, uint32_t b, uint32_t c)
{
    return Fn009a8c68(a, b, c, 0, 0);
}

// FUNCTION: 0x009caeab
uint32_t Fn009caeab(uint32_t a, uint32_t b, uint32_t c)
{
    return Fn009cade4(a, b, c, 0, 0);
}

// ---- 0097ebe6 / 0097ebfe
struct Obj_0097ebe6_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual bool Call5(uint32_t a) = 0;
    virtual void Pad06() = 0;
    virtual bool Call7(uint32_t a) = 0;
};

struct View_0097ebe6_shaped04_gzcom {
    uint32_t mPad0;
    Obj_0097ebe6_shaped04_gzcom* mpObj;
    uint32_t mnIndex;
    uint32_t mnCount;
    bool Fn0097ebe6(uint32_t a);
    bool Fn0097ebfe(uint32_t a);
};

// FUNCTION: 0x0097ebe6
bool View_0097ebe6_shaped04_gzcom::Fn0097ebe6(uint32_t a)
{
    mnIndex++;
    if (mnIndex >= mnCount) {
        return false;
    }
    return mpObj->Call5(a);
}

// FUNCTION: 0x0097ebfe
bool View_0097ebe6_shaped04_gzcom::Fn0097ebfe(uint32_t a)
{
    mnIndex++;
    if (mnIndex >= mnCount) {
        return false;
    }
    return mpObj->Call7(a);
}

// ---- 00984249 / 00984262
struct Head_00984249_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual bool Call4(uint32_t a) = 0;
    virtual bool Call5(uint32_t a) = 0;
};

struct Sec_00984249_shaped04_gzcom {
    virtual void PadSec() = 0;
};

struct Outer_00984249_shaped04_gzcom : Head_00984249_shaped04_gzcom, Sec_00984249_shaped04_gzcom {
};

struct View_00984249_shaped04_gzcom {
    bool Fn00984249(Sec_00984249_shaped04_gzcom* s, uint32_t a);
    bool Fn00984262(Sec_00984249_shaped04_gzcom* s, uint32_t a);
};

// FUNCTION: 0x00984249
bool View_00984249_shaped04_gzcom::Fn00984249(Sec_00984249_shaped04_gzcom* s, uint32_t a)
{
    return static_cast<Outer_00984249_shaped04_gzcom*>(s)->Call4(a);
}

// FUNCTION: 0x00984262
bool View_00984249_shaped04_gzcom::Fn00984262(Sec_00984249_shaped04_gzcom* s, uint32_t a)
{
    return static_cast<Outer_00984249_shaped04_gzcom*>(s)->Call5(a);
}

// ---- 0097cff1 / 0097dd91
struct Obj_0097cff1_shaped04_gzcom {
    virtual bool Query(uint32_t iid, uint32_t a) = 0;
};

struct View_0097cff1_shaped04_gzcom {
    uint32_t mPad0;
    Obj_0097cff1_shaped04_gzcom* mpObj;
    bool Fn0097cff1(uint32_t a);
    bool Fn0097dd91(uint32_t a);
};

// FUNCTION: 0x0097cff1
bool View_0097cff1_shaped04_gzcom::Fn0097cff1(uint32_t a)
{
    bool r = false;
    if (mpObj != 0) {
        r = mpObj->Query(0x20732180, a);
    }
    return r;
}

// FUNCTION: 0x0097dd91
bool View_0097cff1_shaped04_gzcom::Fn0097dd91(uint32_t a)
{
    bool r = false;
    if (mpObj != 0) {
        r = mpObj->Query(0x834c471e, a);
    }
    return r;
}

// ---- 009d725d / 009d7278
struct Obj_009d725d_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual bool Call9(uint32_t a) = 0;
    virtual bool Calla(uint32_t a) = 0;
};

struct Node_009d725d_shaped04_gzcom {
    Node_009d725d_shaped04_gzcom* mpNext;
    Node_009d725d_shaped04_gzcom* mpPrev;
    Obj_009d725d_shaped04_gzcom* mpObj;
};

struct View_009d725d_shaped04_gzcom {
    uint8_t mPad[0xe0];
    Node_009d725d_shaped04_gzcom* mpHead;
    bool Fn009d725d(uint32_t a);
    bool Fn009d7278(uint32_t a);
};

// FUNCTION: 0x009d725d
bool View_009d725d_shaped04_gzcom::Fn009d725d(uint32_t a)
{
    if (mpHead->mpNext != mpHead) {
        return mpHead->mpNext->mpObj->Call9(a);
    }
    return false;
}

// FUNCTION: 0x009d7278
bool View_009d725d_shaped04_gzcom::Fn009d7278(uint32_t a)
{
    if (mpHead->mpNext != mpHead) {
        return mpHead->mpNext->mpObj->Calla(a);
    }
    return false;
}

// ---- 009d84d4 / 009d84f3
struct View_009d84d4_shaped04_gzcom {
    uint8_t mPad[0x14];
    int32_t mn14;
    int32_t mn18;
    bool Fn009d84d4(int32_t a);
    bool Fn009d84f3(int32_t a);
};

// FUNCTION: 0x009d84d4
bool View_009d84d4_shaped04_gzcom::Fn009d84d4(int32_t a)
{
    int32_t zero = 0;
    const int32_t* p = (a > zero) ? &a : &zero;
    mn14 = *p;
    return true;
}

// FUNCTION: 0x009d84f3
bool View_009d84d4_shaped04_gzcom::Fn009d84f3(int32_t a)
{
    int32_t zero = 0;
    const int32_t* p = (a > zero) ? &a : &zero;
    mn18 = *p;
    return true;
}

// ---- 009d99d8 / 009d99f8
struct Msg_009d99d8_shaped04_gzcom {
    uint32_t mPad0;
    uint32_t mnWindow;
};

struct View_009d99d8_shaped04_gzcom {
    uint8_t mPad[0x48];
    uint32_t mnWindow;
    // STUB: 0x009d9996
    bool Fn009d9996(uint32_t a, uint32_t b, uint32_t c);
    bool Fn009d99d8(Msg_009d99d8_shaped04_gzcom* m);
    bool Fn009d99f8(Msg_009d99d8_shaped04_gzcom* m);
};

// FUNCTION: 0x009d99d8
bool View_009d99d8_shaped04_gzcom::Fn009d99d8(Msg_009d99d8_shaped04_gzcom* m)
{
    uint32_t w = m->mnWindow;
    if (w == mnWindow) {
        return Fn009d9996(0xe2c7c83a, w, 0);
    }
    return false;
}

// FUNCTION: 0x009d99f8
bool View_009d99d8_shaped04_gzcom::Fn009d99f8(Msg_009d99d8_shaped04_gzcom* m)
{
    uint32_t w = m->mnWindow;
    if (w == mnWindow) {
        return Fn009d9996(0xe2c7c83b, w, 0);
    }
    return false;
}

// ---- 009a19dc / 009a1c45
struct Rec16_009a19dc_shaped04_gzcom {
    uint32_t m0;
    uint32_t m1;
    uint32_t m2;
    uint32_t m3;
};

// STUB: 0x009a0e07
uint32_t Fn009a0e07(uint32_t a, uint32_t b, uint32_t c, Rec16_009a19dc_shaped04_gzcom r);
// STUB: 0x009a1a8e
uint32_t Fn009a1a8e(uint32_t a, uint32_t b, uint32_t c, Rec16_009a19dc_shaped04_gzcom r);

// FUNCTION: 0x009a19dc
uint32_t Fn009a19dc(uint32_t a, uint32_t b, Rec16_009a19dc_shaped04_gzcom r)
{
    return Fn009a0e07(a, b, 0, r);
}

// FUNCTION: 0x009a1c45
uint32_t Fn009a1c45(uint32_t a, uint32_t b, Rec16_009a19dc_shaped04_gzcom r)
{
    return Fn009a1a8e(a, b, 0, r);
}

// ---- 009a963e / 009a9665
struct Rec12_009a963e_shaped04_gzcom {
    uint32_t m0;
    uint32_t m1;
    uint32_t m2;
};

// STUB: 0x009a8bd4
uint32_t Fn009a8bd4(uint32_t a, uint32_t b, uint32_t c, Rec12_009a963e_shaped04_gzcom r, uint32_t d);
// STUB: 0x009a8c1e
uint32_t Fn009a8c1e(uint32_t a, uint32_t b, uint32_t c, Rec12_009a963e_shaped04_gzcom r, uint32_t d);

// FUNCTION: 0x009a963e
uint32_t Fn009a963e(uint32_t a, uint32_t b, uint32_t c, Rec12_009a963e_shaped04_gzcom r)
{
    return Fn009a8bd4(a, b, c, r, 0);
}

// FUNCTION: 0x009a9665
uint32_t Fn009a9665(uint32_t a, uint32_t b, uint32_t c, Rec12_009a963e_shaped04_gzcom r)
{
    return Fn009a8c1e(a, b, c, r, 0);
}

// ---- 009afd9d / 009afdc5
struct Child_009afd9d_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Pad0c() = 0;
    virtual void Pad0d() = 0;
    virtual void Pad0e() = 0;
    virtual void Pad0f() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad1a() = 0;
    virtual void Pad1b() = 0;
    virtual void Pad1c() = 0;
    virtual void Pad1d() = 0;
    virtual void Pad1e() = 0;
    virtual void Pad1f() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Pad28() = 0;
    virtual void Pad29() = 0;
    virtual void Pad2a() = 0;
    virtual void Pad2b() = 0;
    virtual void Pad2c() = 0;
    virtual void Pad2d() = 0;
    virtual void Pad2e() = 0;
    virtual void Pad2f() = 0;
    virtual void Pad30() = 0;
    virtual void Pad31() = 0;
    virtual void Pad32() = 0;
    virtual void Pad33() = 0;
    virtual void Pad34() = 0;
    virtual void Pad35() = 0;
    virtual void Pad36() = 0;
    virtual void Pad37() = 0;
    virtual void Pad38() = 0;
    virtual void Pad39() = 0;
    virtual void Pad3a() = 0;
    virtual void Pad3b() = 0;
    virtual void Pad3c() = 0;
    virtual void Pad3d() = 0;
    virtual void Pad3e() = 0;
    virtual void Pad3f() = 0;
    virtual void Pad40() = 0;
    virtual void Pad41() = 0;
    virtual void Pad42() = 0;
    virtual void Pad43() = 0;
    virtual void Pad44() = 0;
    virtual void Pad45() = 0;
    virtual void Pad46() = 0;
    virtual void Pad47() = 0;
    virtual void Pad48() = 0;
    virtual void Pad49() = 0;
    virtual void Call4a(uint32_t a) = 0;
    virtual void Pad4b() = 0;
    virtual void Pad4c() = 0;
    virtual void Pad4d() = 0;
    virtual void Pad4e() = 0;
    virtual void Pad4f() = 0;
    virtual void Pad50() = 0;
    virtual void Pad51() = 0;
    virtual void Pad52() = 0;
    virtual void Pad53() = 0;
    virtual void Pad54() = 0;
    virtual void Pad55() = 0;
    virtual void Call56(uint32_t a) = 0;
};

struct Parent_009afd9d_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Pad0c() = 0;
    virtual void Pad0d() = 0;
    virtual void Pad0e() = 0;
    virtual void Pad0f() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad1a() = 0;
    virtual void Pad1b() = 0;
    virtual void Pad1c() = 0;
    virtual void Pad1d() = 0;
    virtual void Pad1e() = 0;
    virtual void Pad1f() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual Child_009afd9d_shaped04_gzcom* Get23(uint32_t a) = 0;
};

// FUNCTION: 0x009afd9d
bool Fn009afd9d(Parent_009afd9d_shaped04_gzcom* p, uint32_t a, uint32_t b)
{
    Child_009afd9d_shaped04_gzcom* c = p->Get23(a);
    if (c != 0) {
        c->Call4a(b);
        return true;
    }
    return false;
}

// FUNCTION: 0x009afdc5
bool Fn009afdc5(Parent_009afd9d_shaped04_gzcom* p, uint32_t a, uint32_t b)
{
    Child_009afd9d_shaped04_gzcom* c = p->Get23(a);
    if (c != 0) {
        c->Call56(b);
        return true;
    }
    return false;
}

// ---- 0097dccd / 009c7357
struct Ref_0097dccd_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct View_0097dccd_shaped04_gzcom {
    uint32_t mPad0;
    Ref_0097dccd_shaped04_gzcom* mpRef4;
    bool Fn0097dccd(Ref_0097dccd_shaped04_gzcom* p);
};

// FUNCTION: 0x0097dccd
bool View_0097dccd_shaped04_gzcom::Fn0097dccd(Ref_0097dccd_shaped04_gzcom* p)
{
    if (p != 0) {
        p->AddRef();
    }
    if (mpRef4 != 0) {
        mpRef4->Release();
    }
    mpRef4 = p;
    return true;
}

struct View_009c7357_shaped04_gzcom {
    uint8_t mPad[0x24];
    Ref_0097dccd_shaped04_gzcom* mpRef24;
    bool Fn009c7357(Ref_0097dccd_shaped04_gzcom* p);
};

// FUNCTION: 0x009c7357
bool View_009c7357_shaped04_gzcom::Fn009c7357(Ref_0097dccd_shaped04_gzcom* p)
{
    if (p != 0) {
        p->AddRef();
    }
    if (mpRef24 != 0) {
        mpRef24->Release();
    }
    mpRef24 = p;
    return true;
}

// ---- 009817c7 / 009817f2
struct Tree_009817c7_shaped04_gzcom {
    uint32_t* mpHeader;
    // STUB: 0x0098129c
    uint32_t* FindKey(const uint32_t* key);
    // STUB: 0x0096a7b0
    int32_t* Index(const uint32_t* key);
};

struct View_009817c7_shaped04_gzcom {
    uint8_t mPad[0x1c];
    Tree_009817c7_shaped04_gzcom mTreeA;
    uint8_t mPad2[0x14];
    Tree_009817c7_shaped04_gzcom mTreeB;
    int32_t Fn009817c7(uint32_t key);
    int32_t Fn009817f2(uint32_t key);
};

// FUNCTION: 0x009817c7
int32_t View_009817c7_shaped04_gzcom::Fn009817c7(uint32_t key)
{
    Tree_009817c7_shaped04_gzcom* t = &mTreeA;
    if (t->FindKey(&key) != t->mpHeader) {
        return *t->Index(&key);
    }
    return -1;
}

// FUNCTION: 0x009817f2
int32_t View_009817c7_shaped04_gzcom::Fn009817f2(uint32_t key)
{
    Tree_009817c7_shaped04_gzcom* t = &mTreeB;
    if (t->FindKey(&key) != t->mpHeader) {
        return *t->Index(&key);
    }
    return -1;
}

// ---- 009cd75c / 009cd789
struct Msg_009cd75c_shaped04_gzcom {
    uint32_t mnType;
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
};

struct Target_009cd75c_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual bool Send(Msg_009cd75c_shaped04_gzcom* m) = 0;
};

struct View_009cd75c_shaped04_gzcom {
    uint8_t mPad[0x4c];
    Target_009cd75c_shaped04_gzcom* mpTarget;
    bool Fn009cd75c(uint32_t a, uint32_t b);
    bool Fn009cd789(uint32_t a, uint32_t b);
};

// FUNCTION: 0x009cd75c
bool View_009cd75c_shaped04_gzcom::Fn009cd75c(uint32_t a, uint32_t b)
{
    Msg_009cd75c_shaped04_gzcom m;
    m.mnC = 0;
    m.mnA = a;
    m.mnType = 5;
    m.mnB = b;
    return mpTarget->Send(&m);
}

// FUNCTION: 0x009cd789
bool View_009cd75c_shaped04_gzcom::Fn009cd789(uint32_t a, uint32_t b)
{
    Msg_009cd75c_shaped04_gzcom m;
    m.mnC = 0;
    m.mnA = a;
    m.mnType = 6;
    m.mnB = b;
    return mpTarget->Send(&m);
}

// ---- 009d7e75 / 009d7ea6
struct Outer_009d7e75_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Pad0c() = 0;
    virtual void Pad0d() = 0;
    virtual void Pad0e() = 0;
    virtual void Pad0f() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad1a() = 0;
    virtual void Pad1b() = 0;
    virtual void Pad1c() = 0;
    virtual void Pad1d() = 0;
    virtual void Pad1e() = 0;
    virtual void Pad1f() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Pad28() = 0;
    virtual void Pad29() = 0;
    virtual void Pad2a() = 0;
    virtual void Pad2b() = 0;
    virtual void Pad2c() = 0;
    virtual void Pad2d() = 0;
    virtual void Pad2e() = 0;
    virtual void Pad2f() = 0;
    virtual void Pad30() = 0;
    virtual void Pad31() = 0;
    virtual void Pad32() = 0;
    virtual void Pad33() = 0;
    virtual void Pad34() = 0;
    virtual void Pad35() = 0;
    virtual void Pad36() = 0;
    virtual void Pad37() = 0;
    virtual void Pad38() = 0;
    virtual void Pad39() = 0;
    virtual void Pad3a() = 0;
    virtual void Pad3b() = 0;
    virtual void Pad3c() = 0;
    virtual void Pad3d() = 0;
    virtual void Pad3e() = 0;
    virtual void Pad3f() = 0;
    virtual void Pad40() = 0;
    virtual void Pad41() = 0;
    virtual void Pad42() = 0;
    virtual void Pad43() = 0;
    virtual void Pad44() = 0;
    virtual void Pad45() = 0;
    virtual void Pad46() = 0;
    virtual void Pad47() = 0;
    virtual void Pad48() = 0;
    virtual void Pad49() = 0;
    virtual void Pad4a() = 0;
    virtual void Pad4b() = 0;
    virtual void Pad4c() = 0;
    virtual void Pad4d() = 0;
    virtual void Pad4e() = 0;
    virtual void Pad4f() = 0;
    virtual void Pad50() = 0;
    virtual void Pad51() = 0;
    virtual void Pad52() = 0;
    virtual void Pad53() = 0;
    virtual void Pad54() = 0;
    virtual void Pad55() = 0;
    virtual void Pad56() = 0;
    virtual void Pad57() = 0;
    virtual void Pad58() = 0;
    virtual void Pad59() = 0;
    virtual void Pad5a() = 0;
    virtual void Pad5b() = 0;
    virtual void Call5c() = 0;
};

struct View_009d7e75_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Call6(uint32_t a, uint32_t b) = 0;
    uint32_t mn4;
    uint32_t mn8;
    uint32_t mnC;
    uint8_t mPad[0x50 - 0x10];
    uint8_t mFlags;
    bool Fn009d7e75(uint32_t a);
    bool Fn009d7ea6(uint32_t a);
};

// FUNCTION: 0x009d7e75
bool View_009d7e75_shaped04_gzcom::Fn009d7e75(uint32_t a)
{
    if (mn8 != a) {
        mn8 = a;
        Call6(mn4, 1);
        mFlags |= 2;
        reinterpret_cast<Outer_009d7e75_shaped04_gzcom*>(reinterpret_cast<char*>(this) - 0xd8)->Call5c();
    }
    return true;
}

// FUNCTION: 0x009d7ea6
bool View_009d7e75_shaped04_gzcom::Fn009d7ea6(uint32_t a)
{
    if (mnC != a) {
        mnC = a;
        Call6(mn4, 1);
        mFlags |= 2;
        reinterpret_cast<Outer_009d7e75_shaped04_gzcom*>(reinterpret_cast<char*>(this) - 0xd8)->Call5c();
    }
    return true;
}

// ---- 009bbd9f / 009bbdf1
struct Str_009bbd9f_shaped04_gzcom {
    uint8_t mBytes[0x14];
    // STUB: 0x00414250
    void Dtor414250();
};

struct Tmp1_009bbd9f_shaped04_gzcom {
    uint8_t mPad[0x14];
    Str_009bbd9f_shaped04_gzcom mStr;
    // STUB: 0x009b74ce
    Str_009bbd9f_shaped04_gzcom* Make();
};

struct Tmp2_009bbd9f_shaped04_gzcom {
    uint8_t mPad[0x8];
    Str_009bbd9f_shaped04_gzcom mStr;
    // STUB: 0x009b750d
    Str_009bbd9f_shaped04_gzcom* Make();
};

struct View_009bbd9f_shaped04_gzcom {
    // STUB: 0x009bbcc5
    void Use1(uint32_t a, Str_009bbd9f_shaped04_gzcom* s);
    // STUB: 0x009bbd57
    void Use2(uint32_t a, Str_009bbd9f_shaped04_gzcom* s);
    void Fn009bbd9f(uint32_t a);
    void Fn009bbdf1(uint32_t a);
};

// FUNCTION: 0x009bbd9f
void View_009bbd9f_shaped04_gzcom::Fn009bbd9f(uint32_t a)
{
    Tmp1_009bbd9f_shaped04_gzcom t;
    Use1(a, t.Make());
    t.mStr.Dtor414250();
}

// FUNCTION: 0x009bbdf1
void View_009bbd9f_shaped04_gzcom::Fn009bbdf1(uint32_t a)
{
    Tmp2_009bbd9f_shaped04_gzcom t;
    Use2(a, t.Make());
    t.mStr.Dtor414250();
}

// ---- 009cfc7e / 009cfcb3
struct Item_009cfc7e_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Release() = 0;
    virtual uint32_t Call3() = 0;
};

struct Sub_009cfc7e_shaped04_gzcom {
    virtual void Pad00() {}
    virtual void Pad01() {}
    virtual void Pad02() {}
    virtual void Pad03() {}
    virtual void Pad04() {}
    virtual void Pad05() {}
    virtual void Pad06() {}
    virtual void Pad07() {}
    virtual void Pad08() {}
    virtual void Pad09() {}
    virtual void Pad0a() {}
    virtual void Pad0b() {}
    virtual void Pad0c() {}
    virtual void Pad0d() {}
    virtual void Pad0e() {}
    virtual void Pad0f() {}
    virtual void Call10(uint32_t /*a*/) {}
};

struct View_009cfc7e_shaped04_gzcom {
    uint32_t mPad0;
    Sub_009cfc7e_shaped04_gzcom mSub;
    uint8_t mPad[0x148];
    Item_009cfc7e_shaped04_gzcom* mpItemA;
    Item_009cfc7e_shaped04_gzcom* mpItemB;
    void Fn009cfc7e();
    void Fn009cfcb3();
};

// FUNCTION: 0x009cfc7e
void View_009cfc7e_shaped04_gzcom::Fn009cfc7e()
{
    if (mpItemA != 0) {
        mSub.Call10(mpItemA->Call3());
        mpItemA->Release();
        mpItemA = 0;
    }
}

// FUNCTION: 0x009cfcb3
void View_009cfc7e_shaped04_gzcom::Fn009cfcb3()
{
    if (mpItemB != 0) {
        mSub.Call10(mpItemB->Call3());
        mpItemB->Release();
        mpItemB = 0;
    }
}

// ---- 009d6c01 / 009d6d9c
struct Rel_009d6c01_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Release() = 0;
};

struct View_009d6c01_shaped04_gzcom {
    uint8_t mPad[0xd8];
    Rel_009d6c01_shaped04_gzcom* mp0;
    Rel_009d6c01_shaped04_gzcom* mp1;
    Rel_009d6c01_shaped04_gzcom* mp2;
    Rel_009d6c01_shaped04_gzcom* mp3;
    Rel_009d6c01_shaped04_gzcom* mp4;
    Rel_009d6c01_shaped04_gzcom* mp5;
    // STUB: 0x0099d2fe
    bool Fn0099d2fe();
    bool Fn009d6c01();
    bool Fn009d6d9c();
};

// FUNCTION: 0x009d6c01
bool View_009d6c01_shaped04_gzcom::Fn009d6c01()
{
    if (mp0 != 0) {
        mp0->Release();
        mp0 = 0;
    }
    if (mp5 != 0) {
        mp5->Release();
        mp5 = 0;
    }
    return Fn0099d2fe();
}

// FUNCTION: 0x009d6d9c
bool View_009d6c01_shaped04_gzcom::Fn009d6d9c()
{
    if (mp3 != 0) {
        mp3->Release();
        mp3 = 0;
    }
    if (mp2 != 0) {
        mp2->Release();
        mp2 = 0;
    }
    return Fn0099d2fe();
}

// ---- 00993e26 / 00993e5f
struct Mgr_00993e26_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Pad0c() = 0;
    virtual void Pad0d() = 0;
    virtual void Pad0e() = 0;
    virtual void Pad0f() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Call17(uint32_t a) = 0;
};

struct Holder_00993e26_shaped04_gzcom {
    Mgr_00993e26_shaped04_gzcom* mpMgr;
    // STUB: 0x004177c0
    Holder_00993e26_shaped04_gzcom* Ctor4177c0();
    // STUB: 0x004177f0
    void Dtor4177f0();
};

struct Obj_00993e26_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual uint32_t Call3() = 0;
};

struct Ptr_00993e26_shaped04_gzcom {
    Obj_00993e26_shaped04_gzcom* mpObj;
    // STUB: 0x0094909a
    void Fn0094909a(uint32_t a);
};

struct View_00993e26_shaped04_gzcom {
    uint8_t mPad[0x54];
    Ptr_00993e26_shaped04_gzcom mPtrA;
    uint8_t mPad2[8];
    Ptr_00993e26_shaped04_gzcom mPtrB;
    void Fn00993e26();
    void Fn00993e5f();
};

// FUNCTION: 0x00993e26
void View_00993e26_shaped04_gzcom::Fn00993e26()
{
    Ptr_00993e26_shaped04_gzcom* p = &mPtrA;
    if (p->mpObj != 0) {
        Holder_00993e26_shaped04_gzcom h;
        h.Ctor4177c0();
        uint32_t v = p->mpObj->Call3();
        h.mpMgr->Call17(v);
        p->Fn0094909a(0);
        h.Dtor4177f0();
    }
}

// FUNCTION: 0x00993e5f
void View_00993e26_shaped04_gzcom::Fn00993e5f()
{
    Ptr_00993e26_shaped04_gzcom* p = &mPtrB;
    if (p->mpObj != 0) {
        Holder_00993e26_shaped04_gzcom h;
        h.Ctor4177c0();
        uint32_t v = p->mpObj->Call3();
        h.mpMgr->Call17(v);
        p->Fn0094909a(0);
        h.Dtor4177f0();
    }
}

// ---- 009cb459 / 009cb497
struct Src_009cb459_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Pad0c() = 0;
    virtual void Pad0d() = 0;
    virtual void Pad0e() = 0;
    virtual void Pad0f() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad1a() = 0;
    virtual void Pad1b() = 0;
    virtual void Pad1c() = 0;
    virtual void Pad1d() = 0;
    virtual void Pad1e() = 0;
    virtual void Pad1f() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Get24(uint32_t a, uint32_t* x, uint32_t* y, uint32_t* z) = 0;
};

// STUB: 0x00913c1a
Src_009cb459_shaped04_gzcom* Fn00913c1a();

struct View_009cb459_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Set5(uint32_t which, uint32_t x, uint32_t y, uint32_t z) = 0;
    void Fn009cb459(uint32_t a);
    void Fn009cb497(uint32_t a);
};

// FUNCTION: 0x009cb459
void View_009cb459_shaped04_gzcom::Fn009cb459(uint32_t a)
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    Fn00913c1a()->Get24(a, &x, &y, &z);
    Set5(1, x, y, z);
}

// FUNCTION: 0x009cb497
void View_009cb459_shaped04_gzcom::Fn009cb497(uint32_t a)
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    Fn00913c1a()->Get24(a, &x, &y, &z);
    Set5(2, x, y, z);
}

// ---- 009c717d / 009c71be
struct Child_009c717d_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Pad0c() = 0;
    virtual void Pad0d() = 0;
    virtual void Pad0e() = 0;
    virtual void Pad0f() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad1a() = 0;
    virtual void Pad1b() = 0;
    virtual void Pad1c() = 0;
    virtual void Pad1d() = 0;
    virtual void Pad1e() = 0;
    virtual void Pad1f() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Pad28() = 0;
    virtual void Pad29() = 0;
    virtual void Pad2a() = 0;
    virtual void Pad2b() = 0;
    virtual void Pad2c() = 0;
    virtual void Pad2d() = 0;
    virtual void Pad2e() = 0;
    virtual void Pad2f() = 0;
    virtual void Pad30() = 0;
    virtual void Pad31() = 0;
    virtual void Pad32() = 0;
    virtual void Pad33() = 0;
    virtual void Pad34() = 0;
    virtual void Call35(uint32_t a, uint32_t b) = 0;
    virtual void Pad36() = 0;
    virtual void Pad37() = 0;
    virtual void Call38(uint32_t a, uint32_t b) = 0;
};

struct Outer_009c717d_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Pad0c() = 0;
    virtual void Pad0d() = 0;
    virtual void Pad0e() = 0;
    virtual void Pad0f() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad1a() = 0;
    virtual void Pad1b() = 0;
    virtual void Pad1c() = 0;
    virtual void Pad1d() = 0;
    virtual void Pad1e() = 0;
    virtual void Pad1f() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual Child_009c717d_shaped04_gzcom* Get22(uint32_t a) = 0;
    // STUB: 0x0099be32
    bool Fn0099be32(Child_009c717d_shaped04_gzcom* c);
};

struct View_009c717d_shaped04_gzcom {
    uint32_t mPad0;
    bool Fn009c717d(uint32_t a, uint32_t b, uint32_t c);
    bool Fn009c71be(uint32_t a, uint32_t b, uint32_t c);
};

// FUNCTION: 0x009c717d
bool View_009c717d_shaped04_gzcom::Fn009c717d(uint32_t a, uint32_t b, uint32_t c)
{
    Outer_009c717d_shaped04_gzcom* o = reinterpret_cast<Outer_009c717d_shaped04_gzcom*>(reinterpret_cast<char*>(this) - 0xd8);
    Child_009c717d_shaped04_gzcom* ch = o->Get22(a);
    if (o->Fn0099be32(ch)) {
        ch->Call38(b, c);
        return true;
    }
    return false;
}

// FUNCTION: 0x009c71be
bool View_009c717d_shaped04_gzcom::Fn009c71be(uint32_t a, uint32_t b, uint32_t c)
{
    Outer_009c717d_shaped04_gzcom* o = reinterpret_cast<Outer_009c717d_shaped04_gzcom*>(reinterpret_cast<char*>(this) - 0xd8);
    Child_009c717d_shaped04_gzcom* ch = o->Get22(a);
    if (o->Fn0099be32(ch)) {
        ch->Call35(b, c);
        return true;
    }
    return false;
}

// ---- 009840a7 / 009840f5
struct Q_009840a7_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Release() = 0;
};

struct P_009840a7_shaped04_gzcom {
    virtual bool Query(uint32_t iid, void** out) = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual uint32_t GetType() = 0;
};

struct T_009840a7_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Pad0c() = 0;
    virtual void Pad0d() = 0;
    virtual void Pad0e() = 0;
    virtual void Pad0f() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual bool Call18(Q_009840a7_shaped04_gzcom* q) = 0;
    virtual void Pad19() = 0;
    virtual void Pad1a() = 0;
    virtual void Pad1b() = 0;
    virtual void Pad1c() = 0;
    virtual void Pad1d() = 0;
    virtual void Pad1e() = 0;
    virtual void Pad1f() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Pad28() = 0;
    virtual void Pad29() = 0;
    virtual void Pad2a() = 0;
    virtual void Pad2b() = 0;
    virtual void Pad2c() = 0;
    virtual void Pad2d() = 0;
    virtual void Pad2e() = 0;
    virtual void Pad2f() = 0;
    virtual bool Call30(Q_009840a7_shaped04_gzcom* q) = 0;
};

struct View_009840a7_shaped04_gzcom {
    bool Fn009840a7(P_009840a7_shaped04_gzcom* p, T_009840a7_shaped04_gzcom* t);
    bool Fn009840f5(P_009840a7_shaped04_gzcom* p, T_009840a7_shaped04_gzcom* t);
};

// FUNCTION: 0x009840a7
bool View_009840a7_shaped04_gzcom::Fn009840a7(P_009840a7_shaped04_gzcom* p, T_009840a7_shaped04_gzcom* t)
{
    if (p->GetType() == 0x2026960b) {
        Q_009840a7_shaped04_gzcom* q = 0;
        if (p->Query(0x89b7dc8, reinterpret_cast<void**>(&q))) {
            bool r = t->Call18(q);
            q->Release();
            return r;
        }
    }
    return false;
}

// FUNCTION: 0x009840f5
bool View_009840a7_shaped04_gzcom::Fn009840f5(P_009840a7_shaped04_gzcom* p, T_009840a7_shaped04_gzcom* t)
{
    if (p->GetType() == 0x2026960b) {
        Q_009840a7_shaped04_gzcom* q = 0;
        if (p->Query(0x89b7dc8, reinterpret_cast<void**>(&q))) {
            bool r = t->Call30(q);
            q->Release();
            return r;
        }
    }
    return false;
}

// ---- 0097e6d6 / 0097e723
struct Key_0097e6d6_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual uint32_t Call3(void* tmp) = 0;
};

struct Handler_0097e6d6_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Pad0c() = 0;
    virtual void Pad0d() = 0;
    virtual void Pad0e() = 0;
    virtual void Pad0f() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual bool Call18(Key_0097e6d6_shaped04_gzcom* k) = 0;
    virtual void Pad19() = 0;
    virtual bool Call1a(Key_0097e6d6_shaped04_gzcom* k) = 0;
};

struct Entry_0097e6d6_shaped04_gzcom {
    uint8_t mPad[0x10];
    Handler_0097e6d6_shaped04_gzcom* mpHandler;
};

struct Found_0097e6d6_shaped04_gzcom {
    Entry_0097e6d6_shaped04_gzcom* mpEntry;
    uint32_t mSecond;
};

struct Table_0097e6d6_shaped04_gzcom {
    // STUB: 0x0096f290
    Found_0097e6d6_shaped04_gzcom* Find(Found_0097e6d6_shaped04_gzcom* out, uint32_t key);
};

struct View_0097e6d6_shaped04_gzcom {
    uint8_t mPad[0x44];
    uint8_t mbEnabled;
    uint8_t mPad2[0x54 - 0x45];
    Table_0097e6d6_shaped04_gzcom mTable;
    bool Fn0097e6d6(Key_0097e6d6_shaped04_gzcom* k);
    bool Fn0097e723(Key_0097e6d6_shaped04_gzcom* k);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0097e6d6 score 20
bool View_0097e6d6_shaped04_gzcom::Fn0097e6d6(Key_0097e6d6_shaped04_gzcom* k)
{
    if (mbEnabled) {
        uint8_t tmp[0xc];
        Found_0097e6d6_shaped04_gzcom f;
        mTable.Find(&f, k->Call3(tmp));
        Found_0097e6d6_shaped04_gzcom g = f;
        if (g.mpEntry != 0) {
            return g.mpEntry->mpHandler->Call18(k);
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097e723 score 20
bool View_0097e6d6_shaped04_gzcom::Fn0097e723(Key_0097e6d6_shaped04_gzcom* k)
{
    if (mbEnabled) {
        uint8_t tmp[0xc];
        Found_0097e6d6_shaped04_gzcom f;
        mTable.Find(&f, k->Call3(tmp));
        Found_0097e6d6_shaped04_gzcom g = f;
        if (g.mpEntry != 0) {
            return g.mpEntry->mpHandler->Call1a(k);
        }
    }
    return false;
}
#endif

// ---- 0097d833 / 0097e23c
struct Made_0097d833_shaped04_gzcom {
    virtual bool Call0(uint32_t a, uint32_t b) = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct Raw_0097d833_shaped04_gzcom {
    // STUB: 0x0097d636
    Made_0097d833_shaped04_gzcom* Ctor0097d636();
};

struct Raw_0097e23c_shaped04_gzcom {
    // STUB: 0x0097e1d5
    Made_0097d833_shaped04_gzcom* Ctor0097e1d5();
};

struct View_0097d833_shaped04_gzcom {
    bool Fn0097d833(uint32_t id, uint32_t a, uint32_t b);
    bool Fn0097e23c(uint32_t id, uint32_t a, uint32_t b);
};

// FUNCTION: 0x0097d833
bool View_0097d833_shaped04_gzcom::Fn0097d833(uint32_t id, uint32_t a, uint32_t b)
{
    if (id != 0x62b9da24) {
        return false;
    }
    void* mem = operator new(0x20);
    Made_0097d833_shaped04_gzcom* o = (mem != 0) ? static_cast<Raw_0097d833_shaped04_gzcom*>(mem)->Ctor0097d636() : 0;
    if (o == 0) {
        return false;
    }
    o->AddRef();
    bool r = o->Call0(a, b);
    o->Release();
    return r;
}

// FUNCTION: 0x0097e23c
bool View_0097d833_shaped04_gzcom::Fn0097e23c(uint32_t id, uint32_t a, uint32_t b)
{
    if (id != 0x686aa4b0) {
        return false;
    }
    void* mem = operator new(0x20);
    Made_0097d833_shaped04_gzcom* o = (mem != 0) ? static_cast<Raw_0097e23c_shaped04_gzcom*>(mem)->Ctor0097e1d5() : 0;
    if (o == 0) {
        return false;
    }
    o->AddRef();
    bool r = o->Call0(a, b);
    o->Release();
    return r;
}

// ---- 0098188d / 009818e8
struct Obj_0098188d_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Release() = 0;
};

struct Holder_0098188d_shaped04_gzcom {
    Obj_0098188d_shaped04_gzcom* mpObj;
    // STUB: 0x0096e773
    Holder_0098188d_shaped04_gzcom* Init(uint32_t object);
};

struct VecA_0098188d_shaped04_gzcom {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    // STUB: 0x0098181d
    void PushBack(Holder_0098188d_shaped04_gzcom* h);
};

struct VecB_0098188d_shaped04_gzcom {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    // STUB: 0x00981855
    void PushBack(Holder_0098188d_shaped04_gzcom* h);
};

struct View_0098188d_shaped04_gzcom {
    uint8_t mPad[0x10];
    VecA_0098188d_shaped04_gzcom mVecA;
    uint8_t mPad2[4];
    Tree_009817c7_shaped04_gzcom mTreeA;
    uint8_t mPad3[8];
    VecB_0098188d_shaped04_gzcom mVecB;
    uint8_t mPad4[4];
    Tree_009817c7_shaped04_gzcom mTreeB;
    void Fn0098188d(uint32_t key);
    void Fn009818e8(uint32_t key);
};

// FUNCTION: 0x0098188d
void View_0098188d_shaped04_gzcom::Fn0098188d(uint32_t key)
{
    Tree_009817c7_shaped04_gzcom* t = &mTreeA;
    if (t->FindKey(&key) == t->mpHeader) {
        Holder_0098188d_shaped04_gzcom h;
        h.Init(key);
        VecA_0098188d_shaped04_gzcom* v = &mVecA;
        v->PushBack(&h);
        if (h.mpObj != 0) {
            h.mpObj->Release();
        }
        *t->Index(&key) = static_cast<int32_t>(v->mpEnd - v->mpBegin) - 1;
    }
}

// FUNCTION: 0x009818e8
void View_0098188d_shaped04_gzcom::Fn009818e8(uint32_t key)
{
    Tree_009817c7_shaped04_gzcom* t = &mTreeB;
    if (t->FindKey(&key) == t->mpHeader) {
        Holder_0098188d_shaped04_gzcom h;
        h.Init(key);
        VecB_0098188d_shaped04_gzcom* v = &mVecB;
        v->PushBack(&h);
        if (h.mpObj != 0) {
            h.mpObj->Release();
        }
        *t->Index(&key) = static_cast<int32_t>(v->mpEnd - v->mpBegin) - 1;
    }
}

// ---- 009d75bb / 009d762c
struct Item_009d75bb_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Call7() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual bool Call0b(uint32_t a) = 0;
    virtual bool Call0c(uint32_t a) = 0;
};

struct Node_009d75bb_shaped04_gzcom {
    Node_009d75bb_shaped04_gzcom* mpNext;
    Node_009d75bb_shaped04_gzcom* mpPrev;
    Item_009d75bb_shaped04_gzcom* mpItem;
};

struct List_009d75bb_shaped04_gzcom {
    Node_009d75bb_shaped04_gzcom* mpHead;
    // STUB: 0x0092f4d7
    void Remove(Item_009d75bb_shaped04_gzcom* const* v);
    // STUB: 0x009d74d9
    void PushFront(Item_009d75bb_shaped04_gzcom* const* v);
};

struct View_009d75bb_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad0a() = 0;
    virtual void Pad0b() = 0;
    virtual void Call0c() = 0;
    uint8_t mPad[0xe0 - 4];
    List_009d75bb_shaped04_gzcom mList;
    uint8_t mPad2[0xf4 - 0xe4];
    uint8_t mbFlag;
    bool Fn009d75bb(uint32_t a);
    bool Fn009d762c(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009d75bb score 2
bool View_009d75bb_shaped04_gzcom::Fn009d75bb(uint32_t a)
{
    if (mbFlag) {
        Call0c();
    }
    List_009d75bb_shaped04_gzcom* l = &mList;
    bool r = false;
    for (Node_009d75bb_shaped04_gzcom* n = l->mpHead->mpNext; n != l->mpHead; n = n->mpNext) {
        Item_009d75bb_shaped04_gzcom* o = n->mpItem;
        Item_009d75bb_shaped04_gzcom* v = o;
        if (o->Call0c(a)) {
            l->Remove(&v);
            l->PushFront(&v);
            r = true;
            break;
        }
        o->Call7();
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d762c score 2
bool View_009d75bb_shaped04_gzcom::Fn009d762c(uint32_t a)
{
    if (mbFlag) {
        Call0c();
    }
    List_009d75bb_shaped04_gzcom* l = &mList;
    bool r = false;
    for (Node_009d75bb_shaped04_gzcom* n = l->mpHead->mpNext; n != l->mpHead; n = n->mpNext) {
        Item_009d75bb_shaped04_gzcom* o = n->mpItem;
        Item_009d75bb_shaped04_gzcom* v = o;
        if (o->Call0b(a)) {
            l->Remove(&v);
            l->PushFront(&v);
            r = true;
            break;
        }
        o->Call7();
    }
    return r;
}
#endif

struct Elem_009bb1d6_shaped04_gzcom {
    uint8_t mPad[0x14];
    Str_009bbd9f_shaped04_gzcom mStr;
    // STUB: 0x009b978d
    Elem_009bb1d6_shaped04_gzcom* CopyCtor(const Elem_009bb1d6_shaped04_gzcom* v);
};

// STUB: 0x009b9a58
Elem_009bb1d6_shaped04_gzcom* Fn009b9a58(Elem_009bb1d6_shaped04_gzcom* first, Elem_009bb1d6_shaped04_gzcom* last, Elem_009bb1d6_shaped04_gzcom* out, const uint8_t* tag);
// STUB: 0x009bad27
Elem_009bb1d6_shaped04_gzcom* Fn009bad27(Elem_009bb1d6_shaped04_gzcom* first, Elem_009bb1d6_shaped04_gzcom* last, Elem_009bb1d6_shaped04_gzcom* out, const uint8_t* tag);
// STUB: 0x009b9d9c
Elem_009bb1d6_shaped04_gzcom* Fn009b9d9c(Elem_009bb1d6_shaped04_gzcom* first, uint32_t n, const Elem_009bb1d6_shaped04_gzcom* value);
// STUB: 0x009ba7af
void Fn009ba7af(Elem_009bb1d6_shaped04_gzcom* first, Elem_009bb1d6_shaped04_gzcom* last, const Elem_009bb1d6_shaped04_gzcom* value);

struct Vec_009bb1d6_shaped04_gzcom {
    uint32_t mPad0;
    Elem_009bb1d6_shaped04_gzcom* mpFinish;
    Elem_009bb1d6_shaped04_gzcom* mpEndOfStorage;
    // STUB: 0x009ba538
    void Overflow(Elem_009bb1d6_shaped04_gzcom* pos, const Elem_009bb1d6_shaped04_gzcom* value, const uint8_t* tag, uint32_t n, uint32_t flags);
    // draft of 0x009bb1d6
    void Fn009bb1d6(Elem_009bb1d6_shaped04_gzcom* pos, uint32_t n, const Elem_009bb1d6_shaped04_gzcom* value);
};

struct Elem_009bba43_shaped04_gzcom {
    uint8_t mPad[0x14];
    Str_009bbd9f_shaped04_gzcom mStr;
    // STUB: 0x009b974e
    Elem_009bba43_shaped04_gzcom* CopyCtor(const Elem_009bba43_shaped04_gzcom* v);
};

// STUB: 0x009b9a07
Elem_009bba43_shaped04_gzcom* Fn009b9a07(Elem_009bba43_shaped04_gzcom* first, Elem_009bba43_shaped04_gzcom* last, Elem_009bba43_shaped04_gzcom* out, const uint8_t* tag);
// STUB: 0x009bb4a5
Elem_009bba43_shaped04_gzcom* Fn009bb4a5(Elem_009bba43_shaped04_gzcom* first, Elem_009bba43_shaped04_gzcom* last, Elem_009bba43_shaped04_gzcom* out, const uint8_t* tag);
// STUB: 0x009b9d69
Elem_009bba43_shaped04_gzcom* Fn009b9d69(Elem_009bba43_shaped04_gzcom* first, uint32_t n, const Elem_009bba43_shaped04_gzcom* value);
// STUB: 0x009badd5
void Fn009badd5(Elem_009bba43_shaped04_gzcom* first, Elem_009bba43_shaped04_gzcom* last, const Elem_009bba43_shaped04_gzcom* value);

struct Vec_009bba43_shaped04_gzcom {
    uint32_t mPad0;
    Elem_009bba43_shaped04_gzcom* mpFinish;
    Elem_009bba43_shaped04_gzcom* mpEndOfStorage;
    // STUB: 0x009bac6c
    void Overflow(Elem_009bba43_shaped04_gzcom* pos, const Elem_009bba43_shaped04_gzcom* value, const uint8_t* tag, uint32_t n, uint32_t flags);
    // draft of 0x009bba43
    void Fn009bba43(Elem_009bba43_shaped04_gzcom* pos, uint32_t n, const Elem_009bba43_shaped04_gzcom* value);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009bb1d6 score 0
void Vec_009bb1d6_shaped04_gzcom::Fn009bb1d6(Elem_009bb1d6_shaped04_gzcom* pos, uint32_t n, const Elem_009bb1d6_shaped04_gzcom* value)
{
    if (n == 0) {
        return;
    }
    uint8_t tag = 0;
    if (static_cast<uint32_t>(mpEndOfStorage - mpFinish) >= n) {
        Elem_009bb1d6_shaped04_gzcom copy;
        copy.CopyCtor(value);
        uint32_t elemsAfter = static_cast<uint32_t>(mpFinish - pos);
        Elem_009bb1d6_shaped04_gzcom* oldFinish = mpFinish;
        if (elemsAfter > n) {
            Fn009b9a58(oldFinish - n, oldFinish, oldFinish, &tag);
            mpFinish += n;
            Fn009bad27(pos, oldFinish - n, oldFinish, &tag);
            Fn009ba7af(pos, pos + n, &copy);
        } else {
            Fn009b9d9c(mpFinish, n - elemsAfter, &copy);
            mpFinish += n - elemsAfter;
            Fn009b9a58(pos, oldFinish, mpFinish, &tag);
            mpFinish += elemsAfter;
            Fn009ba7af(pos, oldFinish, &copy);
        }
        copy.mStr.Dtor414250();
    } else {
        Overflow(pos, value, &tag, n, 0);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bba43 score 0
void Vec_009bba43_shaped04_gzcom::Fn009bba43(Elem_009bba43_shaped04_gzcom* pos, uint32_t n, const Elem_009bba43_shaped04_gzcom* value)
{
    if (n == 0) {
        return;
    }
    uint8_t tag = 0;
    if (static_cast<uint32_t>(mpEndOfStorage - mpFinish) >= n) {
        Elem_009bba43_shaped04_gzcom copy;
        copy.CopyCtor(value);
        uint32_t elemsAfter = static_cast<uint32_t>(mpFinish - pos);
        Elem_009bba43_shaped04_gzcom* oldFinish = mpFinish;
        if (elemsAfter > n) {
            Fn009b9a07(oldFinish - n, oldFinish, oldFinish, &tag);
            mpFinish += n;
            Fn009bb4a5(pos, oldFinish - n, oldFinish, &tag);
            Fn009badd5(pos, pos + n, &copy);
        } else {
            Fn009b9d69(mpFinish, n - elemsAfter, &copy);
            mpFinish += n - elemsAfter;
            Fn009b9a07(pos, oldFinish, mpFinish, &tag);
            mpFinish += elemsAfter;
            Fn009badd5(pos, oldFinish, &copy);
        }
        copy.mStr.Dtor414250();
    } else {
        Overflow(pos, value, &tag, n, 0);
    }
}
#endif

// ---- 0097c6a3 / 0097dc7c
struct Inner_0097c6a3_shaped04_gzcom {
    virtual bool Query(uint32_t iid, void** out) = 0;
};

struct View_0097c6a3_shaped04_gzcom {
    virtual void Pad00() = 0;
    virtual void AddRef() = 0;
    uint8_t mPad[0x1c - 4];
    Inner_0097c6a3_shaped04_gzcom* mpInner;
    // STUB: 0x00975395
    bool BaseQueryInterface(uint32_t iid, void** out);
    bool Fn0097c6a3(uint32_t iid, void** out);
    bool Fn0097dc7c(uint32_t iid, void** out);
};

// FUNCTION: 0x0097c6a3
bool View_0097c6a3_shaped04_gzcom::Fn0097c6a3(uint32_t iid, void** out)
{
    if (mpInner != 0) {
        if (mpInner->Query(iid, out)) {
            return true;
        }
    }
    if (iid != 0x22b9da52) {
        return BaseQueryInterface(iid, out);
    }
    if (out == 0) {
        return false;
    }
    *out = reinterpret_cast<char*>(this) + 0x18;
    AddRef();
    return true;
}

// FUNCTION: 0x0097dc7c
bool View_0097c6a3_shaped04_gzcom::Fn0097dc7c(uint32_t iid, void** out)
{
    if (mpInner != 0) {
        if (mpInner->Query(iid, out)) {
            return true;
        }
    }
    if (iid != 0x88696706) {
        return BaseQueryInterface(iid, out);
    }
    if (out == 0) {
        return false;
    }
    *out = reinterpret_cast<char*>(this) + 0x18;
    AddRef();
    return true;
}
