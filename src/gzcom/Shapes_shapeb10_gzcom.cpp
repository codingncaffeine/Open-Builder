#include "common/types.h"

struct View_00874a0f_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint8_t mPad[8];
    uint32_t mnRefs;
    uint32_t Fn00874a0f();
};

// FUNCTION: 0x00874a0f
uint32_t View_00874a0f_shapeb10_gzcom::Fn00874a0f()
{
    if (mnRefs <= 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

// GLOBAL: 0x00b54360
extern float gb54360;

// FUNCTION: 0x0088ff24
float Fn0088ff24()
{
    return gb54360;
}

// GLOBAL: 0x00b54364
extern float gb54364;

// FUNCTION: 0x0088ff2b
float Fn0088ff2b()
{
    return gb54364;
}

// GLOBAL: 0x00b54368
extern float gb54368;

// FUNCTION: 0x0088ff32
float Fn0088ff32()
{
    return gb54368;
}

// GLOBAL: 0x00b5436c
extern float gb5436c;

// FUNCTION: 0x0088ff39
float Fn0088ff39()
{
    return gb5436c;
}

// GLOBAL: 0x00b54398
extern float gb54398;

// FUNCTION: 0x0088ff47
float Fn0088ff47()
{
    return gb54398;
}

struct Node_00892017_shapeb10_gzcom {
    uint8_t mColor;
    uint8_t mPad[3];
    Node_00892017_shapeb10_gzcom* mpParent;
    Node_00892017_shapeb10_gzcom* mpLeft;
    Node_00892017_shapeb10_gzcom* mpRight;
};

struct View_00892017_shapeb10_gzcom {
    Node_00892017_shapeb10_gzcom* mpHeader;
    uint32_t mnSize;
    // STUB: 0x0092d514
    void Base(const void* alloc);
    View_00892017_shapeb10_gzcom* Fn00892017(const void* unused, const void* alloc);
};

// FUNCTION: 0x00892017
View_00892017_shapeb10_gzcom* View_00892017_shapeb10_gzcom::Fn00892017(const void* /*unused*/, const void* alloc)
{
    Base(alloc);
    mnSize = 0;
    mpHeader->mColor = 0;
    mpHeader->mpParent = 0;
    mpHeader->mpLeft = mpHeader;
    mpHeader->mpRight = mpHeader;
    return this;
}

struct Sub1_0089212f_shapeb10_gzcom {
    // STUB: 0x00891f0f
    void Dtor1();
};
struct Sub2_0089212f_shapeb10_gzcom {
    // STUB: 0x00892000
    void Dtor2();
};

struct View_0089212f_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPadmSub2[8];
    Sub2_0089212f_shapeb10_gzcom mSub2;
    uint8_t mPadmSub1[11];
    Sub1_0089212f_shapeb10_gzcom mSub1;
    void Fn0089212f();
};

// FUNCTION: 0x0089212f
void View_0089212f_shapeb10_gzcom::Fn0089212f()
{
    mnVtable = 0xac5290;
    mSub1.Dtor1();
    mSub2.Dtor2();
}

struct Node_0090d291_shapeb10_gzcom {
    uint8_t mColor;
    uint8_t mPad[3];
    Node_0090d291_shapeb10_gzcom* mpParent;
    Node_0090d291_shapeb10_gzcom* mpLeft;
    Node_0090d291_shapeb10_gzcom* mpRight;
};

struct View_0090d291_shapeb10_gzcom {
    Node_0090d291_shapeb10_gzcom* mpHeader;
    uint32_t mnSize;
    // STUB: 0x0090d1e2
    void Base(const void* alloc);
    View_0090d291_shapeb10_gzcom* Fn0090d291(const void* unused, const void* alloc);
};

// FUNCTION: 0x0090d291
View_0090d291_shapeb10_gzcom* View_0090d291_shapeb10_gzcom::Fn0090d291(const void* /*unused*/, const void* alloc)
{
    Base(alloc);
    mnSize = 0;
    mpHeader->mColor = 0;
    mpHeader->mpParent = 0;
    mpHeader->mpLeft = mpHeader;
    mpHeader->mpRight = mpHeader;
    return this;
}

struct Sub1_0090d40a_shapeb10_gzcom {
    // STUB: 0x0090d267
    void Dtor1();
};
struct Sub2_0090d40a_shapeb10_gzcom {
    // STUB: 0x0090d267
    void Dtor2();
};

struct View_0090d40a_shapeb10_gzcom {
    uint32_t mnVtable;
    Sub2_0090d40a_shapeb10_gzcom mSub2;
    uint8_t mPadmSub1[11];
    Sub1_0090d40a_shapeb10_gzcom mSub1;
    void Fn0090d40a();
};

// FUNCTION: 0x0090d40a
void View_0090d40a_shapeb10_gzcom::Fn0090d40a()
{
    mnVtable = 0xace604;
    mSub1.Dtor1();
    mSub2.Dtor2();
}

struct Sub1_0090d44e_shapeb10_gzcom {
    // STUB: 0x0090d27c
    void Dtor1();
};
struct Sub2_0090d44e_shapeb10_gzcom {
    // STUB: 0x0090d27c
    void Dtor2();
};

struct View_0090d44e_shapeb10_gzcom {
    uint32_t mnVtable;
    Sub2_0090d44e_shapeb10_gzcom mSub2;
    uint8_t mPadmSub1[11];
    Sub1_0090d44e_shapeb10_gzcom mSub1;
    void Fn0090d44e();
};

// FUNCTION: 0x0090d44e
void View_0090d44e_shapeb10_gzcom::Fn0090d44e()
{
    mnVtable = 0xace60c;
    mSub1.Dtor1();
    mSub2.Dtor2();
}

struct View_009132fe_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[4];
    uint8_t mbFlags;
    uint32_t Fn009132fe();
};

// FUNCTION: 0x009132fe
uint32_t View_009132fe_shapeb10_gzcom::Fn009132fe()
{
    return (mbFlags >> 2) & 1;
}

struct View_0091330a_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[4];
    uint8_t mbFlags;
    uint32_t Fn0091330a();
};

// FUNCTION: 0x0091330a
uint32_t View_0091330a_shapeb10_gzcom::Fn0091330a()
{
    return (mbFlags >> 3) & 1;
}

struct View_00913316_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[4];
    uint8_t mbFlags;
    uint32_t Fn00913316();
};

// FUNCTION: 0x00913316
uint32_t View_00913316_shapeb10_gzcom::Fn00913316()
{
    return (mbFlags >> 4) & 1;
}

struct View_0091335a_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[4];
    uint8_t mbFlags;
    uint32_t Fn0091335a();
};

// FUNCTION: 0x0091335a
uint32_t View_0091335a_shapeb10_gzcom::Fn0091335a()
{
    return (mbFlags >> 6) & 1;
}

struct View_0091336e_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[4];
    uint8_t mbFlags;
    bool Fn0091336e();
};

// FUNCTION: 0x0091336e
bool View_0091336e_shapeb10_gzcom::Fn0091336e()
{
    return (mbFlags >> 5) & 1;
}

struct Sub1_00922ece_shapeb10_gzcom {
    // STUB: 0x00930b02
    void Dtor1();
};
struct Sub2_00922ece_shapeb10_gzcom {
    // STUB: 0x00922e84
    void Dtor2();
};

struct View_00922ece_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPadmSub2[24];
    Sub2_00922ece_shapeb10_gzcom mSub2;
    uint8_t mPadmSub1[11];
    Sub1_00922ece_shapeb10_gzcom mSub1;
    void Fn00922ece();
};

// FUNCTION: 0x00922ece
void View_00922ece_shapeb10_gzcom::Fn00922ece()
{
    mnVtable = 0xacfe40;
    mSub1.Dtor1();
    mSub2.Dtor2();
}

struct View_0092464d_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Target() = 0;
    void Fn0092464d();
};

// FUNCTION: 0x0092464d
void View_0092464d_shapeb10_gzcom::Fn0092464d()
{
    Target();
}

struct Sub1_0092a4fa_shapeb10_gzcom {
    // STUB: 0x00915eb5
    void Dtor1();
};
struct Sub2_0092a4fa_shapeb10_gzcom {
    // STUB: 0x0092a278
    void Dtor2();
};

struct View_0092a4fa_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPadmSub2[4];
    Sub2_0092a4fa_shapeb10_gzcom mSub2;
    uint8_t mPadmSub1[11];
    Sub1_0092a4fa_shapeb10_gzcom mSub1;
    void Fn0092a4fa();
};

// FUNCTION: 0x0092a4fa
void View_0092a4fa_shapeb10_gzcom::Fn0092a4fa()
{
    mnVtable = 0xad16c8;
    mSub1.Dtor1();
    mSub2.Dtor2();
}

struct View_0092cb3f_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[16];
    bool mbBinary;
    // STUB: 0x0092b267
    bool Binary(uint32_t value);
    // STUB: 0x0092c7ad
    bool Text(uint32_t value);
    bool Fn0092cb3f(uint32_t value);
};

// FUNCTION: 0x0092cb3f
bool View_0092cb3f_shapeb10_gzcom::Fn0092cb3f(uint32_t value)
{
    if (mbBinary) {
        return Binary(value);
    }
    return Text(value);
}

struct View_0092cb4f_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[16];
    bool mbBinary;
    // STUB: 0x0092b267
    bool Binary(uint32_t value);
    // STUB: 0x0092c808
    bool Text(uint32_t value);
    bool Fn0092cb4f(uint32_t value);
};

// FUNCTION: 0x0092cb4f
bool View_0092cb4f_shapeb10_gzcom::Fn0092cb4f(uint32_t value)
{
    if (mbBinary) {
        return Binary(value);
    }
    return Text(value);
}

struct View_0092cb5f_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[16];
    bool mbBinary;
    // STUB: 0x0092b640
    bool Binary(uint32_t value);
    // STUB: 0x0092c863
    bool Text(uint32_t value);
    bool Fn0092cb5f(uint32_t value);
};

// FUNCTION: 0x0092cb5f
bool View_0092cb5f_shapeb10_gzcom::Fn0092cb5f(uint32_t value)
{
    if (mbBinary) {
        return Binary(value);
    }
    return Text(value);
}

struct View_0092cb6f_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[16];
    bool mbBinary;
    // STUB: 0x0092b640
    bool Binary(uint32_t value);
    // STUB: 0x0092c8be
    bool Text(uint32_t value);
    bool Fn0092cb6f(uint32_t value);
};

// FUNCTION: 0x0092cb6f
bool View_0092cb6f_shapeb10_gzcom::Fn0092cb6f(uint32_t value)
{
    if (mbBinary) {
        return Binary(value);
    }
    return Text(value);
}

struct View_0092cb7f_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[16];
    bool mbBinary;
    // STUB: 0x0092b676
    bool Binary(uint32_t value);
    // STUB: 0x0092c919
    bool Text(uint32_t value);
    bool Fn0092cb7f(uint32_t value);
};

// FUNCTION: 0x0092cb7f
bool View_0092cb7f_shapeb10_gzcom::Fn0092cb7f(uint32_t value)
{
    if (mbBinary) {
        return Binary(value);
    }
    return Text(value);
}

struct View_0092cb8f_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[16];
    bool mbBinary;
    // STUB: 0x0092b676
    bool Binary(uint32_t value);
    // STUB: 0x0092c972
    bool Text(uint32_t value);
    bool Fn0092cb8f(uint32_t value);
};

// FUNCTION: 0x0092cb8f
bool View_0092cb8f_shapeb10_gzcom::Fn0092cb8f(uint32_t value)
{
    if (mbBinary) {
        return Binary(value);
    }
    return Text(value);
}

struct View_00932a04_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[16];
    uint32_t mnValue;
    bool Fn00932a04(uint32_t* out);
};

// FUNCTION: 0x00932a04
bool View_00932a04_shapeb10_gzcom::Fn00932a04(uint32_t* out)
{
    *out = mnValue;
    return true;
}

struct Left_00933bf7_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    uint8_t mPad[24];
};
struct Right_00933bf7_shapeb10_gzcom {
    uint32_t mnData;
};

struct View_00933bf7_shapeb10_gzcom : Left_00933bf7_shapeb10_gzcom, Right_00933bf7_shapeb10_gzcom {
    // STUB: 0x0091dd67
    bool Base(uint32_t iid, void** ppv);
    bool Fn00933bf7(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00933bf7
bool View_00933bf7_shapeb10_gzcom::Fn00933bf7(uint32_t iid, void** ppv)
{
    if (iid != 0x9b69c46) {
        return Base(iid, ppv);
    }
    *ppv = static_cast<Right_00933bf7_shapeb10_gzcom*>(this);
    AddRef();
    return true;
}

struct Node_00933eff_shapeb10_gzcom {
    uint8_t mColor;
    uint8_t mPad[3];
    Node_00933eff_shapeb10_gzcom* mpParent;
    Node_00933eff_shapeb10_gzcom* mpLeft;
    Node_00933eff_shapeb10_gzcom* mpRight;
};

struct View_00933eff_shapeb10_gzcom {
    Node_00933eff_shapeb10_gzcom* mpHeader;
    uint32_t mnSize;
    // STUB: 0x00933e4b
    void Base(const void* alloc);
    View_00933eff_shapeb10_gzcom* Fn00933eff(const void* unused, const void* alloc);
};

// FUNCTION: 0x00933eff
View_00933eff_shapeb10_gzcom* View_00933eff_shapeb10_gzcom::Fn00933eff(const void* /*unused*/, const void* alloc)
{
    Base(alloc);
    mnSize = 0;
    mpHeader->mColor = 0;
    mpHeader->mpParent = 0;
    mpHeader->mpLeft = mpHeader;
    mpHeader->mpRight = mpHeader;
    return this;
}

struct Elem_0093aab5_shapeb10_gzcom {
    uint32_t mnData;
    // STUB: 0x00969fea
    void Fn(uint32_t value);
};

// FUNCTION: 0x0093aab5
void Fn0093aab5(Elem_0093aab5_shapeb10_gzcom* first, Elem_0093aab5_shapeb10_gzcom* last, uint32_t value)
{
    for (; first != last; ++first) {
        first->Fn(value);
    }
}

struct Elem_0093b776_shapeb10_gzcom {
    uint32_t mnData;
    // STUB: 0x0093ab29
    void Fn(uint32_t zero);
};

// FUNCTION: 0x0093b776
void Fn0093b776(Elem_0093b776_shapeb10_gzcom* first, Elem_0093b776_shapeb10_gzcom* last, void* /*tag*/)
{
    for (; first != last; ++first) {
        first->Fn(0);
    }
}

struct Node_0093c0c2_shapeb10_gzcom {
    uint8_t mColor;
    uint8_t mPad[3];
    Node_0093c0c2_shapeb10_gzcom* mpParent;
    Node_0093c0c2_shapeb10_gzcom* mpLeft;
    Node_0093c0c2_shapeb10_gzcom* mpRight;
};

struct View_0093c0c2_shapeb10_gzcom {
    Node_0093c0c2_shapeb10_gzcom* mpHeader;
    uint32_t mnSize;
    // STUB: 0x0093bb06
    void Base(const void* alloc);
    View_0093c0c2_shapeb10_gzcom* Fn0093c0c2(const void* unused, const void* alloc);
};

// FUNCTION: 0x0093c0c2
View_0093c0c2_shapeb10_gzcom* View_0093c0c2_shapeb10_gzcom::Fn0093c0c2(const void* /*unused*/, const void* alloc)
{
    Base(alloc);
    mnSize = 0;
    mpHeader->mColor = 0;
    mpHeader->mpParent = 0;
    mpHeader->mpLeft = mpHeader;
    mpHeader->mpRight = mpHeader;
    return this;
}

struct View_009457af_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn009457af();
};

// FUNCTION: 0x009457af
uint32_t View_009457af_shapeb10_gzcom::Fn009457af()
{
    if (mnRefs <= 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct View_00948ebb_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPadmbDirty[357];
    bool mbDirty;
    uint8_t mPadmbValue[14];
    bool mbValue;
    bool Fn00948ebb(uint32_t, uint32_t, bool value);
};

// FUNCTION: 0x00948ebb
bool View_00948ebb_shapeb10_gzcom::Fn00948ebb(uint32_t, uint32_t, bool value)
{
    mbValue = value;
    mbDirty = true;
    return true;
}

struct View_0094a8ac_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPadmbValue[4324];
    bool mbValue;
    bool mbDirty;
    bool Fn0094a8ac(bool value);
};

// FUNCTION: 0x0094a8ac
bool View_0094a8ac_shapeb10_gzcom::Fn0094a8ac(bool value)
{
    mbValue = value;
    mbDirty = true;
    return true;
}

struct Node_0094cb8b_shapeb10_gzcom {
    uint8_t mColor;
    uint8_t mPad[3];
    Node_0094cb8b_shapeb10_gzcom* mpParent;
    Node_0094cb8b_shapeb10_gzcom* mpLeft;
    Node_0094cb8b_shapeb10_gzcom* mpRight;
};

struct View_0094cb8b_shapeb10_gzcom {
    Node_0094cb8b_shapeb10_gzcom* mpHeader;
    uint32_t mnSize;
    // STUB: 0x004b5c80
    void Base(const void* alloc);
    View_0094cb8b_shapeb10_gzcom* Fn0094cb8b(const void* unused, const void* alloc);
};

// FUNCTION: 0x0094cb8b
View_0094cb8b_shapeb10_gzcom* View_0094cb8b_shapeb10_gzcom::Fn0094cb8b(const void* /*unused*/, const void* alloc)
{
    Base(alloc);
    mnSize = 0;
    mpHeader->mColor = 0;
    mpHeader->mpParent = 0;
    mpHeader->mpLeft = mpHeader;
    mpHeader->mpRight = mpHeader;
    return this;
}

struct View_0095b9a1_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[212];
    uint32_t mnVtable2;
    // STUB: 0x0099d2fe
    void Pre();
    // STUB: 0x0099e1a2
    void Base();
    void Fn0095b9a1();
};

// FUNCTION: 0x0095b9a1
void View_0095b9a1_shapeb10_gzcom::Fn0095b9a1()
{
    mnVtable = 0xad6aa0;
    mnVtable2 = 0xad6a8c;
    Pre();
    Base();
}

struct View_00966799_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
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
    virtual void Pad50() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint8_t mPad[48];
    uint32_t mnRefs;
    uint32_t Fn00966799();
};

// FUNCTION: 0x00966799
uint32_t View_00966799_shapeb10_gzcom::Fn00966799()
{
    if (mnRefs <= 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct View_0096ac93_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
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
    virtual void Pad20() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint8_t mPad[88];
    uint32_t mnRefs;
    uint32_t Fn0096ac93();
};

// FUNCTION: 0x0096ac93
uint32_t View_0096ac93_shapeb10_gzcom::Fn0096ac93()
{
    if (mnRefs <= 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct View_0096ada8_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
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
    virtual void Pad20() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn0096ada8();
};

// FUNCTION: 0x0096ada8
uint32_t View_0096ada8_shapeb10_gzcom::Fn0096ada8()
{
    if (mnRefs <= 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct View_0096bc4c_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPadmbValue[28];
    bool mbValue;
    bool mbDirty;
    bool Fn0096bc4c(bool value);
};

// FUNCTION: 0x0096bc4c
bool View_0096bc4c_shapeb10_gzcom::Fn0096bc4c(bool value)
{
    mbValue = value;
    mbDirty = true;
    return true;
}

struct View_0096bef8_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPadmbValue[72];
    bool mbValue;
    bool mbDirty;
    bool Fn0096bef8(bool value);
};

// FUNCTION: 0x0096bef8
bool View_0096bef8_shapeb10_gzcom::Fn0096bef8(bool value)
{
    mbValue = value;
    mbDirty = true;
    return true;
}

struct View_0096c06e_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Target() = 0;
    void Fn0096c06e();
};

// FUNCTION: 0x0096c06e
void View_0096c06e_shapeb10_gzcom::Fn0096c06e()
{
    Target();
}

struct View_0096c409_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPadmbValue[88];
    bool mbValue;
    bool mbDirty;
    bool Fn0096c409(bool value);
};

// FUNCTION: 0x0096c409
bool View_0096c409_shapeb10_gzcom::Fn0096c409(bool value)
{
    mbValue = value;
    mbDirty = true;
    return true;
}

struct View_00972b73_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
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
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Target() = 0;
    void Fn00972b73();
};

// FUNCTION: 0x00972b73
void View_00972b73_shapeb10_gzcom::Fn00972b73()
{
    Target();
}

struct View_00975b11_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
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
    virtual void Pad50() = 0;
    virtual void Target() = 0;
    void Fn00975b11();
};

// FUNCTION: 0x00975b11
void View_00975b11_shapeb10_gzcom::Fn00975b11()
{
    Target();
}

struct View_009793f1_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
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
    virtual void Target() = 0;
    void Fn009793f1();
};

// FUNCTION: 0x009793f1
void View_009793f1_shapeb10_gzcom::Fn009793f1()
{
    Target();
}

struct Left_00998e73_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    uint8_t mPad[236];
};
struct Right_00998e73_shapeb10_gzcom {
    uint32_t mnData;
};

struct View_00998e73_shapeb10_gzcom : Left_00998e73_shapeb10_gzcom, Right_00998e73_shapeb10_gzcom {
    // STUB: 0x009cd1d2
    bool Base(uint32_t iid, void** ppv);
    bool Fn00998e73(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00998e73
bool View_00998e73_shapeb10_gzcom::Fn00998e73(uint32_t iid, void** ppv)
{
    if (iid != 0x37c86704) {
        return Base(iid, ppv);
    }
    *ppv = static_cast<Right_00998e73_shapeb10_gzcom*>(this);
    AddRef();
    return true;
}

struct Left_009b2bef_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    uint8_t mPad[552];
};
struct Right_009b2bef_shapeb10_gzcom {
    uint32_t mnData;
};

struct View_009b2bef_shapeb10_gzcom : Left_009b2bef_shapeb10_gzcom, Right_009b2bef_shapeb10_gzcom {
    // STUB: 0x009b1e73
    bool Base(uint32_t iid, void** ppv);
    bool Fn009b2bef(uint32_t iid, void** ppv);
};

// FUNCTION: 0x009b2bef
bool View_009b2bef_shapeb10_gzcom::Fn009b2bef(uint32_t iid, void** ppv)
{
    if (iid != 0x42cf2351) {
        return Base(iid, ppv);
    }
    *ppv = static_cast<Right_009b2bef_shapeb10_gzcom*>(this);
    AddRef();
    return true;
}

struct Elem_009b68f8_shapeb10_gzcom {
    uint8_t mData[12];
    // STUB: 0x009b679a
    void Assign(const Elem_009b68f8_shapeb10_gzcom* source);
};

// FUNCTION: 0x009b68f8
Elem_009b68f8_shapeb10_gzcom* Fn009b68f8(Elem_009b68f8_shapeb10_gzcom* first, Elem_009b68f8_shapeb10_gzcom* last, Elem_009b68f8_shapeb10_gzcom* dest)
{
    for (int32_t n = last - first; n > 0; --n) {
        --last;
        --dest;
        dest->Assign(last);
    }
    return dest;
}

struct Elem_009b95eb_shapeb10_gzcom {
    uint8_t mData[36];
    // STUB: 0x009b74af
    void Fn(uint32_t zero);
};

// FUNCTION: 0x009b95eb
void Fn009b95eb(Elem_009b95eb_shapeb10_gzcom* first, Elem_009b95eb_shapeb10_gzcom* last, void* /*tag*/)
{
    for (; first != last; ++first) {
        first->Fn(0);
    }
}

struct Elem_009b9606_shapeb10_gzcom {
    uint8_t mData[28];
    // STUB: 0x009a2e07
    void Fn(uint32_t zero);
};

// FUNCTION: 0x009b9606
void Fn009b9606(Elem_009b9606_shapeb10_gzcom* first, Elem_009b9606_shapeb10_gzcom* last, void* /*tag*/)
{
    for (; first != last; ++first) {
        first->Fn(0);
    }
}

struct Elem_009b96b9_shapeb10_gzcom {
    uint8_t mData[40];
    // STUB: 0x009be9af
    void Fn(uint32_t zero);
};

// FUNCTION: 0x009b96b9
void Fn009b96b9(Elem_009b96b9_shapeb10_gzcom* first, Elem_009b96b9_shapeb10_gzcom* last, void* /*tag*/)
{
    for (; first != last; ++first) {
        first->Fn(0);
    }
}

struct Elem_009ba7af_shapeb10_gzcom {
    uint8_t mData[40];
    // STUB: 0x009b9f6b
    void Fn(uint32_t value);
};

// FUNCTION: 0x009ba7af
void Fn009ba7af(Elem_009ba7af_shapeb10_gzcom* first, Elem_009ba7af_shapeb10_gzcom* last, uint32_t value)
{
    for (; first != last; ++first) {
        first->Fn(value);
    }
}

struct Elem_009ba7cc_shapeb10_gzcom {
    uint8_t mData[36];
    // STUB: 0x009ba152
    void Fn(uint32_t value);
};

// FUNCTION: 0x009ba7cc
void Fn009ba7cc(Elem_009ba7cc_shapeb10_gzcom* first, Elem_009ba7cc_shapeb10_gzcom* last, uint32_t value)
{
    for (; first != last; ++first) {
        first->Fn(value);
    }
}

struct Elem_009ba7e9_shapeb10_gzcom {
    uint8_t mData[28];
    // STUB: 0x009ba38f
    void Fn(uint32_t value);
};

// FUNCTION: 0x009ba7e9
void Fn009ba7e9(Elem_009ba7e9_shapeb10_gzcom* first, Elem_009ba7e9_shapeb10_gzcom* last, uint32_t value)
{
    for (; first != last; ++first) {
        first->Fn(value);
    }
}

struct Elem_009ba806_shapeb10_gzcom {
    uint8_t mData[40];
    // STUB: 0x009b9f6b
    void Assign(const Elem_009ba806_shapeb10_gzcom* source);
};

// FUNCTION: 0x009ba806
Elem_009ba806_shapeb10_gzcom* Fn009ba806(Elem_009ba806_shapeb10_gzcom* first, Elem_009ba806_shapeb10_gzcom* last, Elem_009ba806_shapeb10_gzcom* dest)
{
    for (int32_t n = last - first; n > 0; --n) {
        --last;
        --dest;
        dest->Assign(last);
    }
    return dest;
}

struct Elem_009ba86a_shapeb10_gzcom {
    uint8_t mData[36];
    // STUB: 0x009ba152
    void Assign(const Elem_009ba86a_shapeb10_gzcom* source);
};

// FUNCTION: 0x009ba86a
Elem_009ba86a_shapeb10_gzcom* Fn009ba86a(Elem_009ba86a_shapeb10_gzcom* first, Elem_009ba86a_shapeb10_gzcom* last, Elem_009ba86a_shapeb10_gzcom* dest)
{
    for (int32_t n = last - first; n > 0; --n) {
        --last;
        --dest;
        dest->Assign(last);
    }
    return dest;
}

struct Elem_009ba8ce_shapeb10_gzcom {
    uint8_t mData[28];
    // STUB: 0x009ba38f
    void Assign(const Elem_009ba8ce_shapeb10_gzcom* source);
};

// FUNCTION: 0x009ba8ce
Elem_009ba8ce_shapeb10_gzcom* Fn009ba8ce(Elem_009ba8ce_shapeb10_gzcom* first, Elem_009ba8ce_shapeb10_gzcom* last, Elem_009ba8ce_shapeb10_gzcom* dest)
{
    for (int32_t n = last - first; n > 0; --n) {
        --last;
        --dest;
        dest->Assign(last);
    }
    return dest;
}

struct Elem_009badd5_shapeb10_gzcom {
    uint8_t mData[40];
    // STUB: 0x009baa81
    void Fn(uint32_t value);
};

// FUNCTION: 0x009badd5
void Fn009badd5(Elem_009badd5_shapeb10_gzcom* first, Elem_009badd5_shapeb10_gzcom* last, uint32_t value)
{
    for (; first != last; ++first) {
        first->Fn(value);
    }
}

struct Elem_009badf2_shapeb10_gzcom {
    uint8_t mData[40];
    // STUB: 0x009baa81
    void Assign(const Elem_009badf2_shapeb10_gzcom* source);
};

// FUNCTION: 0x009badf2
Elem_009badf2_shapeb10_gzcom* Fn009badf2(Elem_009badf2_shapeb10_gzcom* first, Elem_009badf2_shapeb10_gzcom* last, Elem_009badf2_shapeb10_gzcom* dest)
{
    for (int32_t n = last - first; n > 0; --n) {
        --last;
        --dest;
        dest->Assign(last);
    }
    return dest;
}

struct View_009bc2fa_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[212];
    uint32_t mnVtable2;
    // STUB: 0x009bc097
    void Pre();
    // STUB: 0x0099e1a2
    void Base();
    void Fn009bc2fa();
};

// FUNCTION: 0x009bc2fa
void View_009bc2fa_shapeb10_gzcom::Fn009bc2fa()
{
    mnVtable = 0xadf6a0;
    mnVtable2 = 0xadf66c;
    Pre();
    Base();
}

struct Elem_009bea0d_shapeb10_gzcom {
    uint8_t mData[60];
    // STUB: 0x009be9af
    void Fn(uint32_t zero);
};

// FUNCTION: 0x009bea0d
void Fn009bea0d(Elem_009bea0d_shapeb10_gzcom* first, Elem_009bea0d_shapeb10_gzcom* last, void* /*tag*/)
{
    for (; first != last; ++first) {
        first->Fn(0);
    }
}

struct View_009c17d1_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[40];
    uint32_t mnValue;
    bool Fn009c17d1(uint32_t* out);
};

// FUNCTION: 0x009c17d1
bool View_009c17d1_shapeb10_gzcom::Fn009c17d1(uint32_t* out)
{
    *out = mnValue;
    return true;
}

struct View_009c2b7b_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[212];
    uint32_t mnVtable2;
    // STUB: 0x009c229f
    void Pre();
    // STUB: 0x0099e1a2
    void Base();
    void Fn009c2b7b();
};

// FUNCTION: 0x009c2b7b
void View_009c2b7b_shapeb10_gzcom::Fn009c2b7b()
{
    mnVtable = 0xae0240;
    mnVtable2 = 0xae01e8;
    Pre();
    Base();
}

struct Elem_009ca851_shapeb10_gzcom {
    uint8_t mData[24];
    // STUB: 0x009ca734
    void Assign(const Elem_009ca851_shapeb10_gzcom* source);
};

// FUNCTION: 0x009ca851
Elem_009ca851_shapeb10_gzcom* Fn009ca851(Elem_009ca851_shapeb10_gzcom* first, Elem_009ca851_shapeb10_gzcom* last, Elem_009ca851_shapeb10_gzcom* dest)
{
    for (int32_t n = last - first; n > 0; --n) {
        --last;
        --dest;
        dest->Assign(last);
    }
    return dest;
}

struct Elem_009cb9c1_shapeb10_gzcom {
    uint32_t mnData;
    // STUB: 0x009cb959
    void Fn(uint32_t value);
};

// FUNCTION: 0x009cb9c1
void Fn009cb9c1(Elem_009cb9c1_shapeb10_gzcom* first, Elem_009cb9c1_shapeb10_gzcom* last, uint32_t value)
{
    for (; first != last; ++first) {
        first->Fn(value);
    }
}

struct View_009cd1b2_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[212];
    uint32_t mnVtable2;
    // STUB: 0x0099d2fe
    void Pre();
    // STUB: 0x0099e1a2
    void Base();
    void Fn009cd1b2();
};

// FUNCTION: 0x009cd1b2
void View_009cd1b2_shapeb10_gzcom::Fn009cd1b2()
{
    mnVtable = 0xae20a0;
    mnVtable2 = 0xae2050;
    Pre();
    Base();
}

struct Left_009cd88c_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    uint8_t mPad[216];
};
struct Right_009cd88c_shapeb10_gzcom {
    uint32_t mnData;
};

struct View_009cd88c_shapeb10_gzcom : Left_009cd88c_shapeb10_gzcom, Right_009cd88c_shapeb10_gzcom {
    // STUB: 0x009da629
    bool Base(uint32_t iid, void** ppv);
    bool Fn009cd88c(uint32_t iid, void** ppv);
};

// FUNCTION: 0x009cd88c
bool View_009cd88c_shapeb10_gzcom::Fn009cd88c(uint32_t iid, void** ppv)
{
    if (iid != 0x57c) {
        return Base(iid, ppv);
    }
    *ppv = static_cast<Right_009cd88c_shapeb10_gzcom*>(this);
    AddRef();
    return true;
}

struct Left_009d7d6a_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    uint8_t mPad[212];
};
struct Right_009d7d6a_shapeb10_gzcom {
    uint32_t mnData;
};

struct View_009d7d6a_shapeb10_gzcom : Left_009d7d6a_shapeb10_gzcom, Right_009d7d6a_shapeb10_gzcom {
    // STUB: 0x0099b774
    bool Base(uint32_t iid, void** ppv);
    bool Fn009d7d6a(uint32_t iid, void** ppv);
};

// FUNCTION: 0x009d7d6a
bool View_009d7d6a_shapeb10_gzcom::Fn009d7d6a(uint32_t iid, void** ppv)
{
    if (iid != 0x4b42da53) {
        return Base(iid, ppv);
    }
    *ppv = static_cast<Right_009d7d6a_shapeb10_gzcom*>(this);
    AddRef();
    return true;
}

struct View_009d7e67_shapeb10_gzcom {
    uint32_t mnVtable;
    uint32_t mnValue;
    bool Fn009d7e67(uint32_t* out);
};

// FUNCTION: 0x009d7e67
bool View_009d7e67_shapeb10_gzcom::Fn009d7e67(uint32_t* out)
{
    *out = mnValue;
    return true;
}

struct View_009d7ed7_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[8];
    uint32_t mnValue;
    bool Fn009d7ed7(uint32_t* out);
};

// FUNCTION: 0x009d7ed7
bool View_009d7ed7_shapeb10_gzcom::Fn009d7ed7(uint32_t* out)
{
    *out = mnValue;
    return true;
}

struct View_009d7ee5_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[20];
    uint32_t mnValue;
    bool Fn009d7ee5(uint32_t* out);
};

// FUNCTION: 0x009d7ee5
bool View_009d7ee5_shapeb10_gzcom::Fn009d7ee5(uint32_t* out)
{
    *out = mnValue;
    return true;
}

struct View_009d9a18_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[212];
    uint32_t mnVtable2;
    // STUB: 0x009d9664
    void Pre();
    // STUB: 0x0099e1a2
    void Base();
    void Fn009d9a18();
};

// FUNCTION: 0x009d9a18
void View_009d9a18_shapeb10_gzcom::Fn009d9a18()
{
    mnVtable = 0xae4398;
    mnVtable2 = 0xae4380;
    Pre();
    Base();
}

struct View_009da656_shapeb10_gzcom {
    uint32_t mnVtable;
    uint8_t mPad[212];
    uint32_t mnVtable2;
    // STUB: 0x0099d2fe
    void Pre();
    // STUB: 0x0099e1a2
    void Base();
    void Fn009da656();
};

// FUNCTION: 0x009da656
void View_009da656_shapeb10_gzcom::Fn009da656()
{
    mnVtable = 0xae2398;
    mnVtable2 = 0xae25f4;
    Pre();
    Base();
}

struct View_009daf79_shapeb10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Target() = 0;
    void Fn009daf79();
};

// FUNCTION: 0x009daf79
void View_009daf79_shapeb10_gzcom::Fn009daf79()
{
    Target();
}

// STUB: 0x008f94dd
void Fn008f9a7a_callee(void* first, void* last, void* tag);

// FUNCTION: 0x008f9a7a
void Fn008f9a7a(void* first, void* last)
{
    uint8_t tag;
    Fn008f9a7a_callee(first, last, &tag);
}

// FUNCTION: 0x00981543
void Fn00981543(Elem_0093b776_shapeb10_gzcom* first, Elem_0093b776_shapeb10_gzcom* last)
{
    uint8_t tag;
    Fn0093b776(first, last, &tag);
}

// FUNCTION: 0x009b99d7
void Fn009b99d7(Elem_009b95eb_shapeb10_gzcom* first, Elem_009b95eb_shapeb10_gzcom* last)
{
    uint8_t tag;
    Fn009b95eb(first, last, &tag);
}

// FUNCTION: 0x009b99ef
void Fn009b99ef(Elem_009b9606_shapeb10_gzcom* first, Elem_009b9606_shapeb10_gzcom* last)
{
    uint8_t tag;
    Fn009b9606(first, last, &tag);
}

// FUNCTION: 0x009b9d84
void Fn009b9d84(Elem_009b96b9_shapeb10_gzcom* first, Elem_009b96b9_shapeb10_gzcom* last)
{
    uint8_t tag;
    Fn009b96b9(first, last, &tag);
}

// FUNCTION: 0x009bf518
void Fn009bf518(Elem_009bea0d_shapeb10_gzcom* first, Elem_009bea0d_shapeb10_gzcom* last)
{
    uint8_t tag;
    Fn009bea0d(first, last, &tag);
}

