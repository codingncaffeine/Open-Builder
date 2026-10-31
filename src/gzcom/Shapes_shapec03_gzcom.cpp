#include "common/types.h"
#include "common/compiler.h"
#include <new>
struct Tgt_00944891_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Target4() = 0;
    virtual void Target5() = 0;
    virtual void Pad6() = 0;
    virtual void Target7() = 0;
};

struct View_00944891_shapec03_gzcom {
    uint8_t mPad[24];
    Tgt_00944891_shapec03_gzcom** mpArr;
    void Fn00944891();
};

// FUNCTION: 0x00944891
void View_00944891_shapec03_gzcom::Fn00944891()
{
    mpArr[-1]->Target4();
}

struct View_009448ce_shapec03_gzcom {
    uint8_t mPad[24];
    Tgt_00944891_shapec03_gzcom** mpArr;
    void Fn009448ce();
};

// FUNCTION: 0x009448ce
void View_009448ce_shapec03_gzcom::Fn009448ce()
{
    mpArr[-1]->Target5();
}

struct View_009448d9_shapec03_gzcom {
    uint8_t mPad[24];
    Tgt_00944891_shapec03_gzcom** mpArr;
    void Fn009448d9();
};

// FUNCTION: 0x009448d9
void View_009448d9_shapec03_gzcom::Fn009448d9()
{
    mpArr[-1]->Target7();
}

struct View_0092b2df_shapec03_gzcom {
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
    virtual void Target(uint32_t, uint32_t) = 0;
    void Fn0092b2df(uint32_t a);
};

// FUNCTION: 0x0092b2df
void View_0092b2df_shapec03_gzcom::Fn0092b2df(uint32_t a)
{
    Target(a, 1);
}

struct View_0092b2ed_shapec03_gzcom {
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
    virtual void Target(uint32_t, uint32_t) = 0;
    void Fn0092b2ed(uint32_t a);
};

// FUNCTION: 0x0092b2ed
void View_0092b2ed_shapec03_gzcom::Fn0092b2ed(uint32_t a)
{
    Target(a, 4);
}

struct View_0092b2fb_shapec03_gzcom {
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
    virtual void Target(uint32_t, uint32_t) = 0;
    void Fn0092b2fb(uint32_t a);
};

// FUNCTION: 0x0092b2fb
void View_0092b2fb_shapec03_gzcom::Fn0092b2fb(uint32_t a)
{
    Target(a, 8);
}

struct View_0092b267_shapec03_gzcom {
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
    virtual bool Target(void*, uint32_t) = 0;
    bool Fn0092b267(uint32_t a);
};

// FUNCTION: 0x0092b267
bool View_0092b267_shapec03_gzcom::Fn0092b267(uint32_t a)
{
    return Target(&a, 1);
}

struct View_0092b276_shapec03_gzcom {
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
    virtual bool Target(void*, uint32_t) = 0;
    bool Fn0092b276(uint32_t a);
};

// FUNCTION: 0x0092b276
bool View_0092b276_shapec03_gzcom::Fn0092b276(uint32_t a)
{
    return Target(&a, 4);
}

struct View_0092b285_shapec03_gzcom {
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
    virtual bool Target(void*, uint32_t) = 0;
    bool Fn0092b285(uint32_t a, uint32_t /*b*/);
};

// FUNCTION: 0x0092b285
bool View_0092b285_shapec03_gzcom::Fn0092b285(uint32_t a, uint32_t /*b*/)
{
    return Target(&a, 8);
}

struct View_009668ec_shapec03_gzcom {
    uint8_t mPad[260];
    float mfValue;
    void Fn009668ec(float* out);
};

// FUNCTION: 0x009668ec
void View_009668ec_shapec03_gzcom::Fn009668ec(float* out)
{
    *out = mfValue;
}

struct View_009668fb_shapec03_gzcom {
    uint8_t mPad[264];
    float mfValue;
    void Fn009668fb(float* out);
};

// FUNCTION: 0x009668fb
void View_009668fb_shapec03_gzcom::Fn009668fb(float* out)
{
    *out = mfValue;
}

struct View_0096690a_shapec03_gzcom {
    uint8_t mPad[268];
    float mfValue;
    void Fn0096690a(float* out);
};

// FUNCTION: 0x0096690a
void View_0096690a_shapec03_gzcom::Fn0096690a(float* out)
{
    *out = mfValue;
}

#ifdef _MSC_VER
#define SHAPEC03_API extern "C" __declspec(dllimport)
#else
#define SHAPEC03_API extern "C"
#endif
SHAPEC03_API int32_t OB_STDCALL ReleaseMutex(void* handle);
SHAPEC03_API int32_t OB_STDCALL PulseEvent(void* handle);
SHAPEC03_API int32_t OB_STDCALL ResetEvent(void* handle);

struct View_00920a69_shapec03_gzcom {
    uint8_t mPad[4];
    void** mpHandle;
    bool Fn00920a69();
};

// FUNCTION: 0x00920a69
bool View_00920a69_shapec03_gzcom::Fn00920a69()
{
    return ReleaseMutex(*mpHandle) != 0;
}

struct View_00932d95_shapec03_gzcom {
    uint8_t mPad[4];
    void** mpHandle;
    bool Fn00932d95();
};

// FUNCTION: 0x00932d95
bool View_00932d95_shapec03_gzcom::Fn00932d95()
{
    return PulseEvent(*mpHandle) != 0;
}

struct View_00932dce_shapec03_gzcom {
    uint8_t mPad[4];
    void** mpHandle;
    bool Fn00932dce();
};

// FUNCTION: 0x00932dce
bool View_00932dce_shapec03_gzcom::Fn00932dce()
{
    return ResetEvent(*mpHandle) != 0;
}

struct IntList_00935df1_shapec03_gzcom {
    // STUB: 0x00427640
    void push_back(const int32_t& value);
};
struct PtrDeque_0097dc42_shapec03_gzcom {
    // STUB: 0x00714630
    void push_back(void* const& value);
};

struct View_00935df1_shapec03_gzcom {
    uint8_t mPad[16];
    IntList_00935df1_shapec03_gzcom mList;
    bool Fn00935df1(int32_t a, uint32_t /*b*/, uint32_t /*c*/, uint32_t /*d*/);
};

// FUNCTION: 0x00935df1
bool View_00935df1_shapec03_gzcom::Fn00935df1(int32_t a, uint32_t /*b*/, uint32_t /*c*/, uint32_t /*d*/)
{
    mList.push_back(a);
    return true;
}

struct View_00935e03_shapec03_gzcom {
    uint8_t mPad[12];
    IntList_00935df1_shapec03_gzcom mList;
    bool Fn00935e03(int32_t a, uint32_t /*b*/, uint32_t /*c*/, uint32_t /*d*/);
};

// FUNCTION: 0x00935e03
bool View_00935e03_shapec03_gzcom::Fn00935e03(int32_t a, uint32_t /*b*/, uint32_t /*c*/, uint32_t /*d*/)
{
    mList.push_back(a);
    return true;
}

struct View_0097dc42_shapec03_gzcom {
    uint8_t mPad[12];
    PtrDeque_0097dc42_shapec03_gzcom mDeque;
    bool Fn0097dc42(void* a);
};

// FUNCTION: 0x0097dc42
bool View_0097dc42_shapec03_gzcom::Fn0097dc42(void* a)
{
    mDeque.push_back(a);
    return true;
}

struct View_0099bda4_shapec03_gzcom {
    uint8_t mPad[160];
    uint32_t mnA;
    uint32_t mnB;
    void Fn0099bda4(uint32_t a, uint32_t b);
};

// FUNCTION: 0x0099bda4
void View_0099bda4_shapec03_gzcom::Fn0099bda4(uint32_t a, uint32_t b)
{
    mnA = a;
    mnB = b;
}

struct View_00978097_shapec03_gzcom {
    uint8_t mPad[4];
    uint32_t mnA;
    uint32_t mnB;
    void Fn00978097(uint32_t a, uint32_t b);
};

// FUNCTION: 0x00978097
void View_00978097_shapec03_gzcom::Fn00978097(uint32_t a, uint32_t b)
{
    mnA = a;
    mnB = b;
}

struct View_009d457e_shapec03_gzcom {
    uint8_t mPad[164];
    uint32_t mnA;
    uint32_t mnB;
    void Fn009d457e(uint32_t a, uint32_t b);
};

// FUNCTION: 0x009d457e
void View_009d457e_shapec03_gzcom::Fn009d457e(uint32_t a, uint32_t b)
{
    mnA = a;
    mnB = b;
}

struct Sub1_00945f24_shapec03_gzcom {
    // STUB: 0x0096edbc
    void Dtor1();
};
struct Sub2_00945f24_shapec03_gzcom {
    // STUB: 0x00414250
    void Dtor2();
};

struct View_00945f24_shapec03_gzcom {
    uint8_t mPadmSub2[12];
    Sub2_00945f24_shapec03_gzcom mSub2;
    uint8_t mPadmSub1[87];
    Sub1_00945f24_shapec03_gzcom mSub1;
    void Fn00945f24();
};

// FUNCTION: 0x00945f24
void View_00945f24_shapec03_gzcom::Fn00945f24()
{
    mSub1.Dtor1();
    mSub2.Dtor2();
}

struct Sub1_00932eb4_shapec03_gzcom {
    // STUB: 0x00930b02
    void Dtor1();
};
struct Sub2_00932eb4_shapec03_gzcom {
    // STUB: 0x00414250
    void Dtor2();
};

struct View_00932eb4_shapec03_gzcom {
    uint8_t mPadmSub2[8];
    Sub2_00932eb4_shapec03_gzcom mSub2;
    uint8_t mPadmSub1[19];
    Sub1_00932eb4_shapec03_gzcom mSub1;
    void Fn00932eb4();
};

// FUNCTION: 0x00932eb4
void View_00932eb4_shapec03_gzcom::Fn00932eb4()
{
    mSub1.Dtor1();
    mSub2.Dtor2();
}

struct Sub1_00984fc4_shapec03_gzcom {
    // STUB: 0x00930b02
    void Dtor1();
};
struct Sub2_00984fc4_shapec03_gzcom {
    // STUB: 0x00920811
    void Dtor2();
};

struct View_00984fc4_shapec03_gzcom {
    uint8_t mPadmSub2[12];
    Sub2_00984fc4_shapec03_gzcom mSub2;
    uint8_t mPadmSub1[11];
    Sub1_00984fc4_shapec03_gzcom mSub1;
    void Fn00984fc4();
};

// FUNCTION: 0x00984fc4
void View_00984fc4_shapec03_gzcom::Fn00984fc4()
{
    mSub1.Dtor1();
    mSub2.Dtor2();
}

struct Sub_009453ed_shapec03_gzcom {
    // STUB: 0x009452f9
    void Dtor();
};

struct View_009453ed_shapec03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad4[4];
    Sub_009453ed_shapec03_gzcom mSub;
    // STUB: 0x00945310
    bool Clear();
    void Fn009453ed();
};

// FUNCTION: 0x009453ed
void View_009453ed_shapec03_gzcom::Fn009453ed()
{
    mnVtable = 0xad4764;
    Clear();
    mSub.Dtor();
}

struct Svc_009d1f4c_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Target(void*) = 0;
};

// STUB: 0x009d0747
Svc_009d1f4c_shapec03_gzcom* Get_009d1f4c();

struct View_009d1f4c_shapec03_gzcom {
    void* mpValue;
    // STUB: 0x009d1e2a
    void Prepare();
    void Fn009d1f4c();
};

// FUNCTION: 0x009d1f4c
void View_009d1f4c_shapec03_gzcom::Fn009d1f4c()
{
    Prepare();
    void* value = mpValue;
    Get_009d1f4c()->Target(value);
}

struct Svc_009348b5_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Target(void*) = 0;
};

// STUB: 0x00933ce3
Svc_009348b5_shapec03_gzcom* Get_009348b5();

struct View_009348b5_shapec03_gzcom {
    void* mpValue;
    // STUB: 0x00934752
    void Prepare();
    void Fn009348b5();
};

// FUNCTION: 0x009348b5
void View_009348b5_shapec03_gzcom::Fn009348b5()
{
    Prepare();
    void* value = mpValue;
    Get_009348b5()->Target(value);
}

struct Svc_0093de67_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Target(void*) = 0;
};

// STUB: 0x0093af7e
Svc_0093de67_shapec03_gzcom* Get_0093de67();

struct View_0093de67_shapec03_gzcom {
    void* mpValue;
    // STUB: 0x0093c099
    void Prepare();
    void Fn0093de67();
};

// FUNCTION: 0x0093de67
void View_0093de67_shapec03_gzcom::Fn0093de67()
{
    Prepare();
    void* value = mpValue;
    Get_0093de67()->Target(value);
}

struct Rec_00975062_shapec03_gzcom {
    uint8_t mData[16];
    // STUB: 0x0096ec7c
    Rec_00975062_shapec03_gzcom* Construct(void* record);
};

// FUNCTION: 0x00975062
void* Fn00975062()
{
    void* mem = operator new(16);
    Rec_00975062_shapec03_gzcom* obj = mem ? static_cast<Rec_00975062_shapec03_gzcom*>(mem)->Construct(0) : 0;
    return obj;
}

struct Tail_00913452_shapec03_gzcom {
    // STUB: 0x0094909a
    void Set(uint32_t flag);
};

struct View_00913452_shapec03_gzcom {
    uint8_t mPad[8];
    uint8_t mnFlags;
    uint8_t mPad9[23];
    Tail_00913452_shapec03_gzcom mTail;
    void Fn00913452(uint32_t flag);
};

// FUNCTION: 0x00913452
void View_00913452_shapec03_gzcom::Fn00913452(uint32_t flag)
{
    if (flag) {
        mnFlags |= 0x40;
    } else {
        mnFlags &= 0xbf;
    }
    mTail.Set(flag);
}

struct Tail_0091346b_shapec03_gzcom {
    // STUB: 0x005447b0
    void Set(uint32_t flag);
};

struct View_0091346b_shapec03_gzcom {
    uint8_t mPad[8];
    uint8_t mnFlags;
    uint8_t mPad9[27];
    Tail_0091346b_shapec03_gzcom mTail;
    void Fn0091346b(uint32_t flag);
};

// FUNCTION: 0x0091346b
void View_0091346b_shapec03_gzcom::Fn0091346b(uint32_t flag)
{
    if (flag) {
        mnFlags |= 0x80;
    } else {
        mnFlags &= 0x7f;
    }
    mTail.Set(flag);
}

struct Tail_009134a1_shapec03_gzcom {
    // STUB: 0x005447b0
    void Set(uint32_t flag);
};

struct View_009134a1_shapec03_gzcom {
    uint8_t mPad[8];
    uint8_t mnFlags;
    uint8_t mPad9[31];
    Tail_009134a1_shapec03_gzcom mTail;
    void Fn009134a1(uint32_t flag);
};

// FUNCTION: 0x009134a1
void View_009134a1_shapec03_gzcom::Fn009134a1(uint32_t flag)
{
    if (flag) {
        mnFlags |= 0x20;
    } else {
        mnFlags &= 0xdf;
    }
    mTail.Set(flag);
}

struct View_0096bedf_shapec03_gzcom {
    uint8_t mPad34[52];
    uint8_t* mpData;
    uint32_t mnCount;
    bool Fn0096bedf();
};

// FUNCTION: 0x0096bedf
bool View_0096bedf_shapec03_gzcom::Fn0096bedf()
{
    if (--mnCount == 0) {
        delete mpData;
        mpData = 0;
    }
    return true;
}

struct View_0096c3b2_shapec03_gzcom {
    uint8_t mPad54[84];
    uint8_t* mpData;
    uint32_t mnCount;
    bool Fn0096c3b2();
};

// FUNCTION: 0x0096c3b2
bool View_0096c3b2_shapec03_gzcom::Fn0096c3b2()
{
    if (--mnCount == 0) {
        delete mpData;
        mpData = 0;
    }
    return true;
}

struct View_0096bbf5_shapec03_gzcom {
    uint8_t mPad8[8];
    uint32_t mnCount;
    uint8_t mPad44[56];
    uint8_t* mpData;
    bool Fn0096bbf5();
};

// FUNCTION: 0x0096bbf5
bool View_0096bbf5_shapec03_gzcom::Fn0096bbf5()
{
    if (--mnCount == 0) {
        delete mpData;
        mpData = 0;
    }
    return true;
}

struct View_0096c03e_shapec03_gzcom {
    uint8_t mPad[8];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    bool Fn0096c03e(uint32_t* out);
};

// FUNCTION: 0x0096c03e
bool View_0096c03e_shapec03_gzcom::Fn0096c03e(uint32_t* out)
{
    out[0] = mnA;
    out[1] = mnB;
    out[2] = mnC;
    return true;
}

struct View_0096c456_shapec03_gzcom {
    uint8_t mPad[36];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    bool Fn0096c456(uint32_t* out);
};

// FUNCTION: 0x0096c456
bool View_0096c456_shapec03_gzcom::Fn0096c456(uint32_t* out)
{
    out[0] = mnA;
    out[1] = mnB;
    out[2] = mnC;
    return true;
}

struct View_0096bc7f_shapec03_gzcom {
    uint8_t mPad[12];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    bool Fn0096bc7f(uint32_t* out);
};

// FUNCTION: 0x0096bc7f
bool View_0096bc7f_shapec03_gzcom::Fn0096bc7f(uint32_t* out)
{
    out[0] = mnA;
    out[1] = mnB;
    out[2] = mnC;
    return true;
}

struct View_0096a957_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Destroy(uint32_t) = 0;
    uint32_t mnRefs;
    uint32_t Fn0096a957();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096a957 score 2
uint32_t View_0096a957_shapec03_gzcom::Fn0096a957()
{
    if (mnRefs == 1) {
        mnRefs = 0;
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}
#endif

struct View_00969e4d_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Destroy(uint32_t) = 0;
    uint32_t mnRefs;
    uint32_t Fn00969e4d();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00969e4d score 2
uint32_t View_00969e4d_shapec03_gzcom::Fn00969e4d()
{
    if (mnRefs == 1) {
        mnRefs = 0;
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}
#endif

struct View_0093599a_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Destroy(uint32_t) = 0;
    uint8_t mPad[8];
    uint32_t mnRefs;
    uint32_t Fn0093599a();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0093599a score 2
uint32_t View_0093599a_shapec03_gzcom::Fn0093599a()
{
    if (mnRefs == 1) {
        mnRefs = 0;
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}
#endif

struct Obj_00998a08_shapec03_gzcom {
    uint8_t mData[360];
    // STUB: 0x009ca883
    Obj_00998a08_shapec03_gzcom* Construct(bool flag);
};

// FUNCTION: 0x00998a08
void* Fn00998a08()
{
    void* mem = operator new(360);
    Obj_00998a08_shapec03_gzcom* obj = mem ? static_cast<Obj_00998a08_shapec03_gzcom*>(mem)->Construct(false) : 0;
    return obj;
}

struct Obj_00998a24_shapec03_gzcom {
    uint8_t mData[316];
    // STUB: 0x009cf772
    Obj_00998a24_shapec03_gzcom* Construct(bool flag);
};

// FUNCTION: 0x00998a24
void* Fn00998a24()
{
    void* mem = operator new(316);
    Obj_00998a24_shapec03_gzcom* obj = mem ? static_cast<Obj_00998a24_shapec03_gzcom*>(mem)->Construct(true) : 0;
    return obj;
}

struct Node_0092fa73_shapec03_gzcom {
    Node_0092fa73_shapec03_gzcom* mpNext;
};

struct Iter_0092fa73_shapec03_gzcom {
    Node_0092fa73_shapec03_gzcom* mpNode;
    Iter_0092fa73_shapec03_gzcom() : mpNode(0) {}
    explicit Iter_0092fa73_shapec03_gzcom(Node_0092fa73_shapec03_gzcom* n) : mpNode(n) {}
    Iter_0092fa73_shapec03_gzcom(const Iter_0092fa73_shapec03_gzcom& o) : mpNode(o.mpNode) {}
};

struct View_0092fa73_shapec03_gzcom {
    Node_0092fa73_shapec03_gzcom* mpHeader;
    // STUB: 0x0092f511
    Iter_0092fa73_shapec03_gzcom Insert(Iter_0092fa73_shapec03_gzcom pos, const uint32_t& x);
    void Fn0092fa73(const uint32_t& x);
};

// FUNCTION: 0x0092fa73
void View_0092fa73_shapec03_gzcom::Fn0092fa73(const uint32_t& x)
{
    Insert(Iter_0092fa73_shapec03_gzcom(mpHeader->mpNext), x);
}

struct Node_009690f4_shapec03_gzcom {
    Node_009690f4_shapec03_gzcom* mpNext;
};

struct Iter_009690f4_shapec03_gzcom {
    Node_009690f4_shapec03_gzcom* mpNode;
    Iter_009690f4_shapec03_gzcom() : mpNode(0) {}
    explicit Iter_009690f4_shapec03_gzcom(Node_009690f4_shapec03_gzcom* n) : mpNode(n) {}
    Iter_009690f4_shapec03_gzcom(const Iter_009690f4_shapec03_gzcom& o) : mpNode(o.mpNode) {}
};

struct View_009690f4_shapec03_gzcom {
    Node_009690f4_shapec03_gzcom* mpHeader;
    // STUB: 0x0099d2c2
    Iter_009690f4_shapec03_gzcom Insert(Iter_009690f4_shapec03_gzcom pos, const uint32_t& x);
    void Fn009690f4(const uint32_t& x);
};

// FUNCTION: 0x009690f4
void View_009690f4_shapec03_gzcom::Fn009690f4(const uint32_t& x)
{
    Insert(Iter_009690f4_shapec03_gzcom(mpHeader->mpNext), x);
}

struct Node_0091b9ec_shapec03_gzcom {
    Node_0091b9ec_shapec03_gzcom* mpNext;
};

struct Iter_0091b9ec_shapec03_gzcom {
    Node_0091b9ec_shapec03_gzcom* mpNode;
    Iter_0091b9ec_shapec03_gzcom() : mpNode(0) {}
    explicit Iter_0091b9ec_shapec03_gzcom(Node_0091b9ec_shapec03_gzcom* n) : mpNode(n) {}
    Iter_0091b9ec_shapec03_gzcom(const Iter_0091b9ec_shapec03_gzcom& o) : mpNode(o.mpNode) {}
};

struct View_0091b9ec_shapec03_gzcom {
    Node_0091b9ec_shapec03_gzcom* mpHeader;
    // STUB: 0x0091b349
    Iter_0091b9ec_shapec03_gzcom Insert(Iter_0091b9ec_shapec03_gzcom pos, const uint32_t& x);
    void Fn0091b9ec(const uint32_t& x);
};

// FUNCTION: 0x0091b9ec
void View_0091b9ec_shapec03_gzcom::Fn0091b9ec(const uint32_t& x)
{
    Insert(Iter_0091b9ec_shapec03_gzcom(mpHeader->mpNext), x);
}

struct Iter_009d2975_shapec03_gzcom {
    void* mpNode;
    Iter_009d2975_shapec03_gzcom() : mpNode(0) {}
    Iter_009d2975_shapec03_gzcom(const Iter_009d2975_shapec03_gzcom& o) : mpNode(o.mpNode) {}
};

struct View_009d2975_shapec03_gzcom {
    // STUB: 0x009382b5
    Iter_009d2975_shapec03_gzcom Impl(Iter_009d2975_shapec03_gzcom pos, void* x);
    Iter_009d2975_shapec03_gzcom Fn009d2975(Iter_009d2975_shapec03_gzcom pos, void* x);
};

// FUNCTION: 0x009d2975
Iter_009d2975_shapec03_gzcom View_009d2975_shapec03_gzcom::Fn009d2975(Iter_009d2975_shapec03_gzcom pos, void* x)
{
    return Impl(pos, x);
}

struct Iter_0094988a_shapec03_gzcom {
    void* mpNode;
    Iter_0094988a_shapec03_gzcom() : mpNode(0) {}
    Iter_0094988a_shapec03_gzcom(const Iter_0094988a_shapec03_gzcom& o) : mpNode(o.mpNode) {}
};

struct View_0094988a_shapec03_gzcom {
    // STUB: 0x009495ce
    Iter_0094988a_shapec03_gzcom Impl(Iter_0094988a_shapec03_gzcom pos, void* x);
    Iter_0094988a_shapec03_gzcom Fn0094988a(Iter_0094988a_shapec03_gzcom pos, void* x);
};

// FUNCTION: 0x0094988a
Iter_0094988a_shapec03_gzcom View_0094988a_shapec03_gzcom::Fn0094988a(Iter_0094988a_shapec03_gzcom pos, void* x)
{
    return Impl(pos, x);
}

struct Iter_0096964f_shapec03_gzcom {
    void* mpNode;
    Iter_0096964f_shapec03_gzcom() : mpNode(0) {}
    Iter_0096964f_shapec03_gzcom(const Iter_0096964f_shapec03_gzcom& o) : mpNode(o.mpNode) {}
};

struct View_0096964f_shapec03_gzcom {
    // STUB: 0x009691bd
    Iter_0096964f_shapec03_gzcom Impl(Iter_0096964f_shapec03_gzcom pos, void* x);
    Iter_0096964f_shapec03_gzcom Fn0096964f(Iter_0096964f_shapec03_gzcom pos, void* x);
};

// FUNCTION: 0x0096964f
Iter_0096964f_shapec03_gzcom View_0096964f_shapec03_gzcom::Fn0096964f(Iter_0096964f_shapec03_gzcom pos, void* x)
{
    return Impl(pos, x);
}

struct Sub_00956164_shapec03_gzcom {
    // STUB: 0x00955209
    void Copy(const void* other);
};

struct View_00956164_shapec03_gzcom {
    uint32_t mnFirst;
    Sub_00956164_shapec03_gzcom mSub;
    View_00956164_shapec03_gzcom* Fn00956164(const uint32_t* a, const void* b);
};

// FUNCTION: 0x00956164
View_00956164_shapec03_gzcom* View_00956164_shapec03_gzcom::Fn00956164(const uint32_t* a, const void* b)
{
    mnFirst = *a;
    mSub.Copy(b);
    return this;
}

struct Sub_0098427b_shapec03_gzcom {
    // STUB: 0x0097bf85
    void Copy(const void* other);
};

struct View_0098427b_shapec03_gzcom {
    uint32_t mnFirst;
    Sub_0098427b_shapec03_gzcom mSub;
    View_0098427b_shapec03_gzcom* Fn0098427b(const uint32_t* a, const void* b);
};

// FUNCTION: 0x0098427b
View_0098427b_shapec03_gzcom* View_0098427b_shapec03_gzcom::Fn0098427b(const uint32_t* a, const void* b)
{
    mnFirst = *a;
    mSub.Copy(b);
    return this;
}

struct Sub_00949188_shapec03_gzcom {
    // STUB: 0x004e4bb0
    void Copy(const void* other);
};

struct View_00949188_shapec03_gzcom {
    uint32_t mnFirst;
    Sub_00949188_shapec03_gzcom mSub;
    View_00949188_shapec03_gzcom* Fn00949188(const uint32_t* a, const void* b);
};

// FUNCTION: 0x00949188
View_00949188_shapec03_gzcom* View_00949188_shapec03_gzcom::Fn00949188(const uint32_t* a, const void* b)
{
    mnFirst = *a;
    mSub.Copy(b);
    return this;
}

struct Releasable_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
};

struct Alloc_009d1f8b_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void* Allocate(uint32_t size) = 0;
};

// STUB: 0x009d0747
Alloc_009d1f8b_shapec03_gzcom* GetAlloc_009d1f8b();

struct Value_009d1f8b_shapec03_gzcom {
    uint32_t mnValue;
    explicit Value_009d1f8b_shapec03_gzcom(const uint32_t* source) : mnValue(*source) {}
};

struct Item_009d1f8b_shapec03_gzcom {
    uint8_t mPad[8];
    Value_009d1f8b_shapec03_gzcom mValue;
};

// FUNCTION: 0x009d1f8b
Item_009d1f8b_shapec03_gzcom* OB_STDCALL Fn009d1f8b(const uint32_t* source)
{
    Item_009d1f8b_shapec03_gzcom* node = static_cast<Item_009d1f8b_shapec03_gzcom*>(GetAlloc_009d1f8b()->Allocate(0xc));
    new (&node->mValue) Value_009d1f8b_shapec03_gzcom(source);
    return node;
}

struct Alloc_0096a597_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void* Allocate(uint32_t size) = 0;
};

// STUB: 0x0096a49e
Alloc_0096a597_shapec03_gzcom* GetAlloc_0096a597();

struct Value_0096a597_shapec03_gzcom {
    uint32_t mnValue;
    explicit Value_0096a597_shapec03_gzcom(const uint32_t* source) : mnValue(*source) {}
};

struct Item_0096a597_shapec03_gzcom {
    uint8_t mPad[8];
    Value_0096a597_shapec03_gzcom mValue;
};

// FUNCTION: 0x0096a597
Item_0096a597_shapec03_gzcom* OB_STDCALL Fn0096a597(const uint32_t* source)
{
    Item_0096a597_shapec03_gzcom* node = static_cast<Item_0096a597_shapec03_gzcom*>(GetAlloc_0096a597()->Allocate(0xc));
    new (&node->mValue) Value_0096a597_shapec03_gzcom(source);
    return node;
}

struct Alloc_0093b6ce_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void* Allocate(uint32_t size) = 0;
};

// STUB: 0x0093af7e
Alloc_0093b6ce_shapec03_gzcom* GetAlloc_0093b6ce();

struct Value_0093b6ce_shapec03_gzcom {
    uint32_t mnValue;
    explicit Value_0093b6ce_shapec03_gzcom(const uint32_t* source) : mnValue(*source) {}
};

struct Item_0093b6ce_shapec03_gzcom {
    uint8_t mPad[16];
    Value_0093b6ce_shapec03_gzcom mValue;
};

// FUNCTION: 0x0093b6ce
Item_0093b6ce_shapec03_gzcom* OB_STDCALL Fn0093b6ce(const uint32_t* source)
{
    Item_0093b6ce_shapec03_gzcom* node = static_cast<Item_0093b6ce_shapec03_gzcom*>(GetAlloc_0093b6ce()->Allocate(0x14));
    new (&node->mValue) Value_0093b6ce_shapec03_gzcom(source);
    return node;
}

struct View_00959e31_shapec03_gzcom {
    uint8_t mPad[8];
    uint32_t mnRefs;
    // STUB: 0x00959e54
    void Cleanup();
    uint32_t Fn00959e31();
};

// FUNCTION: 0x00959e31
uint32_t View_00959e31_shapec03_gzcom::Fn00959e31()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Cleanup();
    delete this;
    return 0;
}

struct View_00959e9d_shapec03_gzcom {
    uint8_t mPad[8];
    uint32_t mnRefs;
    // STUB: 0x00959ec0
    void Cleanup();
    uint32_t Fn00959e9d();
};

// FUNCTION: 0x00959e9d
uint32_t View_00959e9d_shapec03_gzcom::Fn00959e9d()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Cleanup();
    delete this;
    return 0;
}

struct View_0095a087_shapec03_gzcom {
    uint8_t mPad[8];
    uint32_t mnRefs;
    // STUB: 0x0095a0aa
    void Cleanup();
    uint32_t Fn0095a087();
};

// FUNCTION: 0x0095a087
uint32_t View_0095a087_shapec03_gzcom::Fn0095a087()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Cleanup();
    delete this;
    return 0;
}

struct View_0096c001_shapec03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad4[16];
    Releasable_shapec03_gzcom* mpA;
    Releasable_shapec03_gzcom* mpB;
    void Fn0096c001();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096c001 score 2
void View_0096c001_shapec03_gzcom::Fn0096c001()
{
    mnVtable = 0xad76d8;
    if (mpB) {
        mpB->Release();
    }
    if (mpA) {
        mpA->Release();
    }
}
#endif

struct View_0096c419_shapec03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad4[44];
    Releasable_shapec03_gzcom* mpA;
    Releasable_shapec03_gzcom* mpB;
    void Fn0096c419();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096c419 score 2
void View_0096c419_shapec03_gzcom::Fn0096c419()
{
    mnVtable = 0xad7b78;
    if (mpB) {
        mpB->Release();
    }
    if (mpA) {
        mpA->Release();
    }
}
#endif

struct View_0096bc5c_shapec03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad4[20];
    Releasable_shapec03_gzcom* mpA;
    Releasable_shapec03_gzcom* mpB;
    void Fn0096bc5c();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096bc5c score 2
void View_0096bc5c_shapec03_gzcom::Fn0096bc5c()
{
    mnVtable = 0xad7670;
    if (mpB) {
        mpB->Release();
    }
    if (mpA) {
        mpA->Release();
    }
}
#endif

struct Outer_0093ff4a_shapec03_gzcom {
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
    virtual bool S12(uint32_t, uint32_t, uint32_t) = 0;
    virtual bool S13(uint32_t, uint32_t, uint32_t) = 0;
    virtual bool S14(uint32_t, uint32_t, uint32_t) = 0;
    virtual bool S15(uint32_t, uint32_t, uint32_t) = 0;
    uint8_t mData[20];
};

struct Second_0093ff4a_shapec03_gzcom {
    uint32_t mnVtable;
    uint32_t mnType;
    bool Fn0093ff4a(uint32_t a, uint32_t b, uint32_t c);
};

struct Whole_0093ff4a_shapec03_gzcom : Outer_0093ff4a_shapec03_gzcom, Second_0093ff4a_shapec03_gzcom {
};

// FUNCTION: 0x0093ff4a
bool Second_0093ff4a_shapec03_gzcom::Fn0093ff4a(uint32_t a, uint32_t b, uint32_t c)
{
    switch (mnType) {
    case 0xb8d821a:
        return static_cast<Whole_0093ff4a_shapec03_gzcom*>(this)->S13(a, b, c);
    case 0xb9eb87e:
        return static_cast<Whole_0093ff4a_shapec03_gzcom*>(this)->S14(a, b, c);
    }
    return false;
}

struct Second_0093ff76_shapec03_gzcom {
    uint32_t mnVtable;
    uint32_t mnType;
    bool Fn0093ff76(uint32_t a, uint32_t b, uint32_t c);
};

struct Whole_0093ff76_shapec03_gzcom : Outer_0093ff4a_shapec03_gzcom, Second_0093ff76_shapec03_gzcom {
};

// FUNCTION: 0x0093ff76
bool Second_0093ff76_shapec03_gzcom::Fn0093ff76(uint32_t a, uint32_t b, uint32_t c)
{
    switch (mnType) {
    case 0xebfee345:
        return static_cast<Whole_0093ff76_shapec03_gzcom*>(this)->S14(a, b, c);
    case 0xebfee349:
        return static_cast<Whole_0093ff76_shapec03_gzcom*>(this)->S15(a, b, c);
    }
    return false;
}

struct Second_0093ffa2_shapec03_gzcom {
    uint32_t mnVtable;
    uint32_t mnType;
    bool Fn0093ffa2(uint32_t a, uint32_t b, uint32_t c);
};

struct Whole_0093ffa2_shapec03_gzcom : Outer_0093ff4a_shapec03_gzcom, Second_0093ffa2_shapec03_gzcom {
};

// FUNCTION: 0x0093ffa2
bool Second_0093ffa2_shapec03_gzcom::Fn0093ffa2(uint32_t a, uint32_t b, uint32_t c)
{
    switch (mnType) {
    case 0xebfee345:
        return static_cast<Whole_0093ffa2_shapec03_gzcom*>(this)->S13(a, b, c);
    case 0xebfee349:
        return static_cast<Whole_0093ffa2_shapec03_gzcom*>(this)->S12(a, b, c);
    }
    return false;
}

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct Val_009ccb22_shapec03_gzcom {
    // STUB: 0x004731a0
    void* Destroy(uint32_t flag);
};

struct Node_009ccb22_shapec03_gzcom {
    Node_009ccb22_shapec03_gzcom* mpNext;
    Node_009ccb22_shapec03_gzcom* mpPrev;
    Val_009ccb22_shapec03_gzcom mValue;
};

struct View_009ccb22_shapec03_gzcom {
    Node_009ccb22_shapec03_gzcom* mpHeader;
    void Fn009ccb22();
};

// FUNCTION: 0x009ccb22
void View_009ccb22_shapec03_gzcom::Fn009ccb22()
{
    Node_009ccb22_shapec03_gzcom* cur = mpHeader->mpNext;
    while (cur != mpHeader) {
        Node_009ccb22_shapec03_gzcom* node = cur;
        cur = cur->mpNext;
        node->mValue.Destroy(0);
        _STL::__stl_delete(node);
    }
    mpHeader->mpNext = mpHeader;
    mpHeader->mpPrev = mpHeader;
}

struct Val_0091aeba_shapec03_gzcom {
    // STUB: 0x0091adff
    void* Destroy(uint32_t flag);
};

struct Node_0091aeba_shapec03_gzcom {
    Node_0091aeba_shapec03_gzcom* mpNext;
    Node_0091aeba_shapec03_gzcom* mpPrev;
    Val_0091aeba_shapec03_gzcom mValue;
};

struct View_0091aeba_shapec03_gzcom {
    Node_0091aeba_shapec03_gzcom* mpHeader;
    void Fn0091aeba();
};

// FUNCTION: 0x0091aeba
void View_0091aeba_shapec03_gzcom::Fn0091aeba()
{
    Node_0091aeba_shapec03_gzcom* cur = mpHeader->mpNext;
    while (cur != mpHeader) {
        Node_0091aeba_shapec03_gzcom* node = cur;
        cur = cur->mpNext;
        node->mValue.Destroy(0);
        _STL::__stl_delete(node);
    }
    mpHeader->mpNext = mpHeader;
    mpHeader->mpPrev = mpHeader;
}

struct Val_009677e6_shapec03_gzcom {
    // STUB: 0x0093ab29
    void* Destroy(uint32_t flag);
};

struct Node_009677e6_shapec03_gzcom {
    Node_009677e6_shapec03_gzcom* mpNext;
    Node_009677e6_shapec03_gzcom* mpPrev;
    Val_009677e6_shapec03_gzcom mValue;
};

struct View_009677e6_shapec03_gzcom {
    Node_009677e6_shapec03_gzcom* mpHeader;
    void Fn009677e6();
};

// FUNCTION: 0x009677e6
void View_009677e6_shapec03_gzcom::Fn009677e6()
{
    Node_009677e6_shapec03_gzcom* cur = mpHeader->mpNext;
    while (cur != mpHeader) {
        Node_009677e6_shapec03_gzcom* node = cur;
        cur = cur->mpNext;
        node->mValue.Destroy(0);
        _STL::__stl_delete(node);
    }
    mpHeader->mpNext = mpHeader;
    mpHeader->mpPrev = mpHeader;
}

struct Node_0094362b_shapec03_gzcom {
    Node_0094362b_shapec03_gzcom* mpNext;
};

struct Iter_0094362b_shapec03_gzcom {
    Node_0094362b_shapec03_gzcom* mpNode;
    Iter_0094362b_shapec03_gzcom() : mpNode(0) {}
    Iter_0094362b_shapec03_gzcom(const Iter_0094362b_shapec03_gzcom& o) : mpNode(o.mpNode) {}
    bool operator!=(const Iter_0094362b_shapec03_gzcom& o) const { return mpNode != o.mpNode; }
    Iter_0094362b_shapec03_gzcom operator++(int)
    {
        Iter_0094362b_shapec03_gzcom old = *this;
        mpNode = mpNode->mpNext;
        return old;
    }
};

struct View_0094362b_shapec03_gzcom {
    // STUB: 0x00968c53
    Iter_0094362b_shapec03_gzcom Erase(Iter_0094362b_shapec03_gzcom pos);
    Iter_0094362b_shapec03_gzcom Fn0094362b(Iter_0094362b_shapec03_gzcom first, Iter_0094362b_shapec03_gzcom last);
};

// FUNCTION: 0x0094362b
Iter_0094362b_shapec03_gzcom View_0094362b_shapec03_gzcom::Fn0094362b(Iter_0094362b_shapec03_gzcom first, Iter_0094362b_shapec03_gzcom last)
{
    while (first != last) {
        Erase(first++);
    }
    return last;
}

struct Node_0091af16_shapec03_gzcom {
    Node_0091af16_shapec03_gzcom* mpNext;
};

struct Iter_0091af16_shapec03_gzcom {
    Node_0091af16_shapec03_gzcom* mpNode;
    Iter_0091af16_shapec03_gzcom() : mpNode(0) {}
    Iter_0091af16_shapec03_gzcom(const Iter_0091af16_shapec03_gzcom& o) : mpNode(o.mpNode) {}
    bool operator!=(const Iter_0091af16_shapec03_gzcom& o) const { return mpNode != o.mpNode; }
    Iter_0091af16_shapec03_gzcom operator++(int)
    {
        Iter_0091af16_shapec03_gzcom old = *this;
        mpNode = mpNode->mpNext;
        return old;
    }
};

struct View_0091af16_shapec03_gzcom {
    // STUB: 0x0091ae8e
    Iter_0091af16_shapec03_gzcom Erase(Iter_0091af16_shapec03_gzcom pos);
    Iter_0091af16_shapec03_gzcom Fn0091af16(Iter_0091af16_shapec03_gzcom first, Iter_0091af16_shapec03_gzcom last);
};

// FUNCTION: 0x0091af16
Iter_0091af16_shapec03_gzcom View_0091af16_shapec03_gzcom::Fn0091af16(Iter_0091af16_shapec03_gzcom first, Iter_0091af16_shapec03_gzcom last)
{
    while (first != last) {
        Erase(first++);
    }
    return last;
}

struct Node_009437a7_shapec03_gzcom {
    Node_009437a7_shapec03_gzcom* mpNext;
};

struct Iter_009437a7_shapec03_gzcom {
    Node_009437a7_shapec03_gzcom* mpNode;
    Iter_009437a7_shapec03_gzcom() : mpNode(0) {}
    Iter_009437a7_shapec03_gzcom(const Iter_009437a7_shapec03_gzcom& o) : mpNode(o.mpNode) {}
    bool operator!=(const Iter_009437a7_shapec03_gzcom& o) const { return mpNode != o.mpNode; }
    Iter_009437a7_shapec03_gzcom operator++(int)
    {
        Iter_009437a7_shapec03_gzcom old = *this;
        mpNode = mpNode->mpNext;
        return old;
    }
};

struct View_009437a7_shapec03_gzcom {
    // STUB: 0x009437db
    Iter_009437a7_shapec03_gzcom Erase(Iter_009437a7_shapec03_gzcom pos);
    Iter_009437a7_shapec03_gzcom Fn009437a7(Iter_009437a7_shapec03_gzcom first, Iter_009437a7_shapec03_gzcom last);
};

// FUNCTION: 0x009437a7
Iter_009437a7_shapec03_gzcom View_009437a7_shapec03_gzcom::Fn009437a7(Iter_009437a7_shapec03_gzcom first, Iter_009437a7_shapec03_gzcom last)
{
    while (first != last) {
        Erase(first++);
    }
    return last;
}

struct Node_009418f7_shapec03_gzcom {
    Node_009418f7_shapec03_gzcom* mpNext;
    Node_009418f7_shapec03_gzcom* mpPrev;
    uint32_t mnValue;
};

struct View_009418f7_shapec03_gzcom {
    // STUB: 0x004273f0
    Node_009418f7_shapec03_gzcom* CreateNode(const uint32_t& value);
    void Fn009418f7(Node_009418f7_shapec03_gzcom* pos, Node_009418f7_shapec03_gzcom* first, Node_009418f7_shapec03_gzcom* last, uint32_t /*tag*/);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009418f7 score 4
void View_009418f7_shapec03_gzcom::Fn009418f7(Node_009418f7_shapec03_gzcom* pos, Node_009418f7_shapec03_gzcom* first, Node_009418f7_shapec03_gzcom* last, uint32_t /*tag*/)
{
    for (; first != last; first = first->mpNext) {
        Node_009418f7_shapec03_gzcom* node = CreateNode(first->mnValue);
        Node_009418f7_shapec03_gzcom* prev = pos->mpPrev;
        node->mpNext = pos;
        node->mpPrev = prev;
        prev->mpNext = node;
        pos->mpPrev = node;
    }
}
#endif

struct Node_0094357b_shapec03_gzcom {
    Node_0094357b_shapec03_gzcom* mpNext;
    Node_0094357b_shapec03_gzcom* mpPrev;
    uint32_t mnValue;
};

struct View_0094357b_shapec03_gzcom {
    // STUB: 0x0094b33a
    Node_0094357b_shapec03_gzcom* CreateNode(const uint32_t& value);
    void Fn0094357b(Node_0094357b_shapec03_gzcom* pos, Node_0094357b_shapec03_gzcom* first, Node_0094357b_shapec03_gzcom* last, uint32_t /*tag*/);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0094357b score 4
void View_0094357b_shapec03_gzcom::Fn0094357b(Node_0094357b_shapec03_gzcom* pos, Node_0094357b_shapec03_gzcom* first, Node_0094357b_shapec03_gzcom* last, uint32_t /*tag*/)
{
    for (; first != last; first = first->mpNext) {
        Node_0094357b_shapec03_gzcom* node = CreateNode(first->mnValue);
        Node_0094357b_shapec03_gzcom* prev = pos->mpPrev;
        node->mpNext = pos;
        node->mpPrev = prev;
        prev->mpNext = node;
        pos->mpPrev = node;
    }
}
#endif

struct Node_00943686_shapec03_gzcom {
    Node_00943686_shapec03_gzcom* mpNext;
    Node_00943686_shapec03_gzcom* mpPrev;
    uint32_t mnValue;
};

struct View_00943686_shapec03_gzcom {
    // STUB: 0x00973648
    Node_00943686_shapec03_gzcom* CreateNode(const uint32_t& value);
    void Fn00943686(Node_00943686_shapec03_gzcom* pos, Node_00943686_shapec03_gzcom* first, Node_00943686_shapec03_gzcom* last, uint32_t /*tag*/);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00943686 score 4
void View_00943686_shapec03_gzcom::Fn00943686(Node_00943686_shapec03_gzcom* pos, Node_00943686_shapec03_gzcom* first, Node_00943686_shapec03_gzcom* last, uint32_t /*tag*/)
{
    for (; first != last; first = first->mpNext) {
        Node_00943686_shapec03_gzcom* node = CreateNode(first->mnValue);
        Node_00943686_shapec03_gzcom* prev = pos->mpPrev;
        node->mpNext = pos;
        node->mpPrev = prev;
        prev->mpNext = node;
        pos->mpPrev = node;
    }
}
#endif

struct View_009d9863_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Destroy(uint32_t) = 0;
    int32_t mnRefs;
    uint32_t Fn009d9863();
};

// FUNCTION: 0x009d9863
uint32_t View_009d9863_shapec03_gzcom::Fn009d9863()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_00938d0f_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Destroy(uint32_t) = 0;
    int32_t mnRefs;
    uint32_t Fn00938d0f();
};

// FUNCTION: 0x00938d0f
uint32_t View_00938d0f_shapec03_gzcom::Fn00938d0f()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_0093556e_shapec03_gzcom {
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
    virtual void Destroy(uint32_t) = 0;
    uint8_t mPad[12];
    int32_t mnRefs;
    uint32_t Fn0093556e();
};

// FUNCTION: 0x0093556e
uint32_t View_0093556e_shapec03_gzcom::Fn0093556e()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_00943917_shapec03_gzcom {
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
    virtual void Destroy(uint32_t) = 0;
    int32_t mnRefs;
    uint32_t Fn00943917();
};

// FUNCTION: 0x00943917
uint32_t View_00943917_shapec03_gzcom::Fn00943917()
{
    if (mnRefs <= 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct View_009378a5_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Destroy(uint32_t) = 0;
    uint8_t mPad[8];
    int32_t mnRefs;
    uint32_t Fn009378a5();
};

// FUNCTION: 0x009378a5
uint32_t View_009378a5_shapec03_gzcom::Fn009378a5()
{
    if (mnRefs <= 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct View_00948e63_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Destroy(uint32_t) = 0;
    uint8_t mPad[12];
    int32_t mnRefs;
    uint32_t Fn00948e63();
};

// FUNCTION: 0x00948e63
uint32_t View_00948e63_shapec03_gzcom::Fn00948e63()
{
    if (mnRefs <= 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct Sub_0096b81c_shapec03_gzcom {
    // STUB: 0x00414250
    void Dtor();
};

struct View_0096b81c_shapec03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad4[4];
    Sub_0096b81c_shapec03_gzcom mSub;
    // STUB: 0x0096adbf
    bool Clear();
    void Fn0096b81c();
};

// FUNCTION: 0x0096b81c
void View_0096b81c_shapec03_gzcom::Fn0096b81c()
{
    mnVtable = 0xad7520;
    Clear();
    mSub.Dtor();
}

struct Sub_009393bd_shapec03_gzcom {
    // STUB: 0x00938c85
    void Dtor();
};

struct View_009393bd_shapec03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad4[4];
    Sub_009393bd_shapec03_gzcom mSub;
    // STUB: 0x00939040
    void Clear();
    void Fn009393bd();
};

// FUNCTION: 0x009393bd
void View_009393bd_shapec03_gzcom::Fn009393bd()
{
    mnVtable = 0xad27d4;
    Clear();
    mSub.Dtor();
}

struct Out_00940de8_shapec03_gzcom {
    uint32_t mnVtable;
    uint32_t mnOwner;
};

struct View_00940de8_shapec03_gzcom {
    uint8_t mPad[4];
    uint32_t mnOwner;
    void Fn00940de8(Out_00940de8_shapec03_gzcom* out);
};

// FUNCTION: 0x00940de8
void View_00940de8_shapec03_gzcom::Fn00940de8(Out_00940de8_shapec03_gzcom* out)
{
    if (out) {
        out->mnVtable = 0xad4468;
        out->mnOwner = mnOwner;
    }
}

struct Out_00937ef1_shapec03_gzcom {
    uint32_t mnVtable;
    uint32_t mnOwner;
};

struct View_00937ef1_shapec03_gzcom {
    uint8_t mPad[4];
    uint32_t mnOwner;
    void Fn00937ef1(Out_00937ef1_shapec03_gzcom* out);
};

// FUNCTION: 0x00937ef1
void View_00937ef1_shapec03_gzcom::Fn00937ef1(Out_00937ef1_shapec03_gzcom* out)
{
    if (out) {
        out->mnVtable = 0xad25fc;
        out->mnOwner = mnOwner;
    }
}

struct Out_0093bb22_shapec03_gzcom {
    uint32_t mnVtable;
    uint32_t mnOwner;
};

struct View_0093bb22_shapec03_gzcom {
    uint8_t mPad[4];
    uint32_t mnOwner;
    void Fn0093bb22(Out_0093bb22_shapec03_gzcom* out);
};

// FUNCTION: 0x0093bb22
void View_0093bb22_shapec03_gzcom::Fn0093bb22(Out_0093bb22_shapec03_gzcom* out)
{
    if (out) {
        out->mnVtable = 0xad2ba4;
        out->mnOwner = mnOwner;
    }
}

struct Target_00949fb9_shapec03_gzcom {
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
    virtual void Target(uint32_t) = 0;
};

struct TNode_00949fb9_shapec03_gzcom {
    uint8_t mPad[8];
    TNode_00949fb9_shapec03_gzcom* mpLeft;
    uint8_t mPad0c[8];
    Target_00949fb9_shapec03_gzcom* mpValue;
};

// STUB: 0x0040d4c0
TNode_00949fb9_shapec03_gzcom* Increment_00949fb9(TNode_00949fb9_shapec03_gzcom* node);

struct First_00949fb9_shapec03_gzcom {
    uint32_t mnVtable;
};

struct Second_00949fb9_shapec03_gzcom {
    uint8_t mPad[20];
    TNode_00949fb9_shapec03_gzcom* mpHeader;
    uint8_t mPad14[288];
    uint32_t mnValue;
    bool Fn00949fb9(uint32_t value);
};

struct Whole_00949fb9_shapec03_gzcom : First_00949fb9_shapec03_gzcom, Second_00949fb9_shapec03_gzcom {
    // STUB: 0x00949d19
    void Notify();
};

// FUNCTION: 0x00949fb9
bool Second_00949fb9_shapec03_gzcom::Fn00949fb9(uint32_t value)
{
    mnValue = value;
    TNode_00949fb9_shapec03_gzcom* it = mpHeader->mpLeft;
    while (it != mpHeader) {
        it->mpValue->Target(value);
        it = Increment_00949fb9(it);
    }
    static_cast<Whole_00949fb9_shapec03_gzcom*>(this)->Notify();
    return true;
}

struct Target_00949ff9_shapec03_gzcom {
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
    virtual void Target(uint32_t) = 0;
};

struct TNode_00949ff9_shapec03_gzcom {
    uint8_t mPad[8];
    TNode_00949ff9_shapec03_gzcom* mpLeft;
    uint8_t mPad0c[8];
    Target_00949ff9_shapec03_gzcom* mpValue;
};

// STUB: 0x0040d4c0
TNode_00949ff9_shapec03_gzcom* Increment_00949ff9(TNode_00949ff9_shapec03_gzcom* node);

struct First_00949ff9_shapec03_gzcom {
    uint32_t mnVtable;
};

struct Second_00949ff9_shapec03_gzcom {
    uint8_t mPad[20];
    TNode_00949ff9_shapec03_gzcom* mpHeader;
    uint8_t mPad14[292];
    uint32_t mnValue;
    bool Fn00949ff9(uint32_t value);
};

struct Whole_00949ff9_shapec03_gzcom : First_00949ff9_shapec03_gzcom, Second_00949ff9_shapec03_gzcom {
    // STUB: 0x00949d19
    void Notify();
};

// FUNCTION: 0x00949ff9
bool Second_00949ff9_shapec03_gzcom::Fn00949ff9(uint32_t value)
{
    mnValue = value;
    TNode_00949ff9_shapec03_gzcom* it = mpHeader->mpLeft;
    while (it != mpHeader) {
        it->mpValue->Target(value);
        it = Increment_00949ff9(it);
    }
    static_cast<Whole_00949ff9_shapec03_gzcom*>(this)->Notify();
    return true;
}

struct Target_0094a039_shapec03_gzcom {
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
    virtual void Target(uint32_t) = 0;
};

struct TNode_0094a039_shapec03_gzcom {
    uint8_t mPad[8];
    TNode_0094a039_shapec03_gzcom* mpLeft;
    uint8_t mPad0c[8];
    Target_0094a039_shapec03_gzcom* mpValue;
};

// STUB: 0x0040d4c0
TNode_0094a039_shapec03_gzcom* Increment_0094a039(TNode_0094a039_shapec03_gzcom* node);

struct First_0094a039_shapec03_gzcom {
    uint32_t mnVtable;
};

struct Second_0094a039_shapec03_gzcom {
    uint8_t mPad[20];
    TNode_0094a039_shapec03_gzcom* mpHeader;
    uint8_t mPad14[304];
    uint32_t mnValue;
    bool Fn0094a039(uint32_t value);
};

struct Whole_0094a039_shapec03_gzcom : First_0094a039_shapec03_gzcom, Second_0094a039_shapec03_gzcom {
    // STUB: 0x00949d19
    void Notify();
};

// FUNCTION: 0x0094a039
bool Second_0094a039_shapec03_gzcom::Fn0094a039(uint32_t value)
{
    mnValue = value;
    TNode_0094a039_shapec03_gzcom* it = mpHeader->mpLeft;
    while (it != mpHeader) {
        it->mpValue->Target(value);
        it = Increment_0094a039(it);
    }
    static_cast<Whole_0094a039_shapec03_gzcom*>(this)->Notify();
    return true;
}

struct Node_009cb959_shapec03_gzcom {
    Node_009cb959_shapec03_gzcom* mpNext;
    Node_009cb959_shapec03_gzcom* mpPrev;
    uint32_t mnValue;
};

struct Iter_009cb959_shapec03_gzcom {
    Node_009cb959_shapec03_gzcom* mpNode;
    Iter_009cb959_shapec03_gzcom() : mpNode(0) {}
    explicit Iter_009cb959_shapec03_gzcom(Node_009cb959_shapec03_gzcom* n) : mpNode(n) {}
    Iter_009cb959_shapec03_gzcom(const Iter_009cb959_shapec03_gzcom& o) : mpNode(o.mpNode) {}
    bool operator!=(const Iter_009cb959_shapec03_gzcom& o) const { return mpNode != o.mpNode; }
    bool operator==(const Iter_009cb959_shapec03_gzcom& o) const { return mpNode == o.mpNode; }
};

struct View_009cb959_shapec03_gzcom {
    Node_009cb959_shapec03_gzcom* mpHeader;
    // STUB: 0x0093a22b
    Iter_009cb959_shapec03_gzcom Erase(Iter_009cb959_shapec03_gzcom first, Iter_009cb959_shapec03_gzcom last);
    // STUB: 0x0099d3b4
    void Insert(Iter_009cb959_shapec03_gzcom pos, Iter_009cb959_shapec03_gzcom first, Iter_009cb959_shapec03_gzcom last);
    View_009cb959_shapec03_gzcom* Fn009cb959(View_009cb959_shapec03_gzcom* other);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009cb959 score 64
View_009cb959_shapec03_gzcom* View_009cb959_shapec03_gzcom::Fn009cb959(View_009cb959_shapec03_gzcom* other)
{
    if (this != other) {
        Iter_009cb959_shapec03_gzcom last2(other->mpHeader);
        Iter_009cb959_shapec03_gzcom first2(last2.mpNode->mpNext);
        Iter_009cb959_shapec03_gzcom last1(mpHeader);
        Iter_009cb959_shapec03_gzcom first1(last1.mpNode->mpNext);
        while (first1 != last1 && first2 != last2) {
            first1.mpNode->mnValue = first2.mpNode->mnValue;
            first1.mpNode = first1.mpNode->mpNext;
            first2.mpNode = first2.mpNode->mpNext;
        }
        if (first2 == last2) {
            Erase(first1, last1);
        } else {
            Insert(last1, first2, last2);
        }
    }
    return this;
}
#endif

struct Node_009434ec_shapec03_gzcom {
    Node_009434ec_shapec03_gzcom* mpNext;
    Node_009434ec_shapec03_gzcom* mpPrev;
    uint32_t mnValue;
};

struct Iter_009434ec_shapec03_gzcom {
    Node_009434ec_shapec03_gzcom* mpNode;
    Iter_009434ec_shapec03_gzcom() : mpNode(0) {}
    explicit Iter_009434ec_shapec03_gzcom(Node_009434ec_shapec03_gzcom* n) : mpNode(n) {}
    Iter_009434ec_shapec03_gzcom(const Iter_009434ec_shapec03_gzcom& o) : mpNode(o.mpNode) {}
    bool operator!=(const Iter_009434ec_shapec03_gzcom& o) const { return mpNode != o.mpNode; }
    bool operator==(const Iter_009434ec_shapec03_gzcom& o) const { return mpNode == o.mpNode; }
};

struct View_009434ec_shapec03_gzcom {
    Node_009434ec_shapec03_gzcom* mpHeader;
    // STUB: 0x0093a22b
    Iter_009434ec_shapec03_gzcom Erase(Iter_009434ec_shapec03_gzcom first, Iter_009434ec_shapec03_gzcom last);
    // STUB: 0x00943554
    void Insert(Iter_009434ec_shapec03_gzcom pos, Iter_009434ec_shapec03_gzcom first, Iter_009434ec_shapec03_gzcom last);
    View_009434ec_shapec03_gzcom* Fn009434ec(View_009434ec_shapec03_gzcom* other);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009434ec score 64
View_009434ec_shapec03_gzcom* View_009434ec_shapec03_gzcom::Fn009434ec(View_009434ec_shapec03_gzcom* other)
{
    if (this != other) {
        Iter_009434ec_shapec03_gzcom last2(other->mpHeader);
        Iter_009434ec_shapec03_gzcom first2(last2.mpNode->mpNext);
        Iter_009434ec_shapec03_gzcom last1(mpHeader);
        Iter_009434ec_shapec03_gzcom first1(last1.mpNode->mpNext);
        while (first1 != last1 && first2 != last2) {
            first1.mpNode->mnValue = first2.mpNode->mnValue;
            first1.mpNode = first1.mpNode->mpNext;
            first2.mpNode = first2.mpNode->mpNext;
        }
        if (first2 == last2) {
            Erase(first1, last1);
        } else {
            Insert(last1, first2, last2);
        }
    }
    return this;
}
#endif

struct Node_00941838_shapec03_gzcom {
    Node_00941838_shapec03_gzcom* mpNext;
    Node_00941838_shapec03_gzcom* mpPrev;
    uint32_t mnValue;
};

struct Iter_00941838_shapec03_gzcom {
    Node_00941838_shapec03_gzcom* mpNode;
    Iter_00941838_shapec03_gzcom() : mpNode(0) {}
    explicit Iter_00941838_shapec03_gzcom(Node_00941838_shapec03_gzcom* n) : mpNode(n) {}
    Iter_00941838_shapec03_gzcom(const Iter_00941838_shapec03_gzcom& o) : mpNode(o.mpNode) {}
    bool operator!=(const Iter_00941838_shapec03_gzcom& o) const { return mpNode != o.mpNode; }
    bool operator==(const Iter_00941838_shapec03_gzcom& o) const { return mpNode == o.mpNode; }
};

struct View_00941838_shapec03_gzcom {
    Node_00941838_shapec03_gzcom* mpHeader;
    // STUB: 0x009418a0
    Iter_00941838_shapec03_gzcom Erase(Iter_00941838_shapec03_gzcom first, Iter_00941838_shapec03_gzcom last);
    // STUB: 0x009418d0
    void Insert(Iter_00941838_shapec03_gzcom pos, Iter_00941838_shapec03_gzcom first, Iter_00941838_shapec03_gzcom last);
    View_00941838_shapec03_gzcom* Fn00941838(View_00941838_shapec03_gzcom* other);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00941838 score 64
View_00941838_shapec03_gzcom* View_00941838_shapec03_gzcom::Fn00941838(View_00941838_shapec03_gzcom* other)
{
    if (this != other) {
        Iter_00941838_shapec03_gzcom last2(other->mpHeader);
        Iter_00941838_shapec03_gzcom first2(last2.mpNode->mpNext);
        Iter_00941838_shapec03_gzcom last1(mpHeader);
        Iter_00941838_shapec03_gzcom first1(last1.mpNode->mpNext);
        while (first1 != last1 && first2 != last2) {
            first1.mpNode->mnValue = first2.mpNode->mnValue;
            first1.mpNode = first1.mpNode->mpNext;
            first2.mpNode = first2.mpNode->mpNext;
        }
        if (first2 == last2) {
            Erase(first1, last1);
        } else {
            Insert(last1, first2, last2);
        }
    }
    return this;
}
#endif

struct Tag_009cbb4c_shapec03_gzcom {
};

struct Elem_009cbb4c_shapec03_gzcom {
    uint32_t mpHeader;
    // STUB: 0x0099d8f3
    Elem_009cbb4c_shapec03_gzcom(const Elem_009cbb4c_shapec03_gzcom& other);
};

// STUB: 0x009cba81
Elem_009cbb4c_shapec03_gzcom* Copy_009cbb4c(Elem_009cbb4c_shapec03_gzcom* first, Elem_009cbb4c_shapec03_gzcom* last, Elem_009cbb4c_shapec03_gzcom* out, const Tag_009cbb4c_shapec03_gzcom& tag);

// STUB: 0x009cba0d
Elem_009cbb4c_shapec03_gzcom* Fill_009cbb4c(Elem_009cbb4c_shapec03_gzcom* first, uint32_t n, const Elem_009cbb4c_shapec03_gzcom& x, const Tag_009cbb4c_shapec03_gzcom& tag);

struct Alloc_009cbb4c_shapec03_gzcom {
    Elem_009cbb4c_shapec03_gzcom* mpEnd;
    // STUB: 0x009db998
    Elem_009cbb4c_shapec03_gzcom* Allocate(uint32_t n);
};

struct View_009cbb4c_shapec03_gzcom {
    Elem_009cbb4c_shapec03_gzcom* mpStart;
    Elem_009cbb4c_shapec03_gzcom* mpFinish;
    Alloc_009cbb4c_shapec03_gzcom mAlloc;
    // STUB: 0x009cbafb
    void Destroy();
    void Fn009cbb4c(Elem_009cbb4c_shapec03_gzcom* pos, const Elem_009cbb4c_shapec03_gzcom& x, const Tag_009cbb4c_shapec03_gzcom& tag, uint32_t n, bool atEnd);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009cbb4c score 19
void View_009cbb4c_shapec03_gzcom::Fn009cbb4c(Elem_009cbb4c_shapec03_gzcom* pos, const Elem_009cbb4c_shapec03_gzcom& x, const Tag_009cbb4c_shapec03_gzcom& tag, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpFinish - mpStart);
    const uint32_t& grow = oldSize < n ? n : oldSize;
    uint32_t newSize = grow + oldSize;
    Alloc_009cbb4c_shapec03_gzcom* alloc = &mAlloc;
    Elem_009cbb4c_shapec03_gzcom* newStart = alloc->Allocate(newSize);
    Elem_009cbb4c_shapec03_gzcom* cur = Copy_009cbb4c(mpStart, pos, newStart, tag);
    if (n == 1) {
        if (cur) {
            new (cur) Elem_009cbb4c_shapec03_gzcom(x);
        }
        ++cur;
    } else {
        cur = Fill_009cbb4c(cur, n, x, tag);
    }
    if (!atEnd) {
        cur = Copy_009cbb4c(pos, mpFinish, cur, tag);
    }
    Destroy();
    mpStart = newStart;
    mpFinish = cur;
    alloc->mpEnd = newStart + newSize;
}
#endif

struct Tag_0098160d_shapec03_gzcom {
};

struct Elem_0098160d_shapec03_gzcom {
    uint32_t mpHeader;
    // STUB: 0x00966956
    Elem_0098160d_shapec03_gzcom(const Elem_0098160d_shapec03_gzcom& other);
};

// STUB: 0x00981273
Elem_0098160d_shapec03_gzcom* Copy_0098160d(Elem_0098160d_shapec03_gzcom* first, Elem_0098160d_shapec03_gzcom* last, Elem_0098160d_shapec03_gzcom* out, const Tag_0098160d_shapec03_gzcom& tag);

// STUB: 0x0093aad2
Elem_0098160d_shapec03_gzcom* Fill_0098160d(Elem_0098160d_shapec03_gzcom* first, uint32_t n, const Elem_0098160d_shapec03_gzcom& x, const Tag_0098160d_shapec03_gzcom& tag);

struct Alloc_0098160d_shapec03_gzcom {
    Elem_0098160d_shapec03_gzcom* mpEnd;
    // STUB: 0x009db998
    Elem_0098160d_shapec03_gzcom* Allocate(uint32_t n);
};

struct View_0098160d_shapec03_gzcom {
    Elem_0098160d_shapec03_gzcom* mpStart;
    Elem_0098160d_shapec03_gzcom* mpFinish;
    Alloc_0098160d_shapec03_gzcom mAlloc;
    // STUB: 0x0093de49
    void Destroy();
    void Fn0098160d(Elem_0098160d_shapec03_gzcom* pos, const Elem_0098160d_shapec03_gzcom& x, const Tag_0098160d_shapec03_gzcom& tag, uint32_t n, bool atEnd);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0098160d score 19
void View_0098160d_shapec03_gzcom::Fn0098160d(Elem_0098160d_shapec03_gzcom* pos, const Elem_0098160d_shapec03_gzcom& x, const Tag_0098160d_shapec03_gzcom& tag, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpFinish - mpStart);
    const uint32_t& grow = oldSize < n ? n : oldSize;
    uint32_t newSize = grow + oldSize;
    Alloc_0098160d_shapec03_gzcom* alloc = &mAlloc;
    Elem_0098160d_shapec03_gzcom* newStart = alloc->Allocate(newSize);
    Elem_0098160d_shapec03_gzcom* cur = Copy_0098160d(mpStart, pos, newStart, tag);
    if (n == 1) {
        if (cur) {
            new (cur) Elem_0098160d_shapec03_gzcom(x);
        }
        ++cur;
    } else {
        cur = Fill_0098160d(cur, n, x, tag);
    }
    if (!atEnd) {
        cur = Copy_0098160d(pos, mpFinish, cur, tag);
    }
    Destroy();
    mpStart = newStart;
    mpFinish = cur;
    alloc->mpEnd = newStart + newSize;
}
#endif

struct Tag_0093de99_shapec03_gzcom {
};

struct Elem_0093de99_shapec03_gzcom {
    uint32_t mpHeader;
    // STUB: 0x00966956
    Elem_0093de99_shapec03_gzcom(const Elem_0093de99_shapec03_gzcom& other);
};

// STUB: 0x00981273
Elem_0093de99_shapec03_gzcom* Copy_0093de99(Elem_0093de99_shapec03_gzcom* first, Elem_0093de99_shapec03_gzcom* last, Elem_0093de99_shapec03_gzcom* out, const Tag_0093de99_shapec03_gzcom& tag);

// STUB: 0x0093aad2
Elem_0093de99_shapec03_gzcom* Fill_0093de99(Elem_0093de99_shapec03_gzcom* first, uint32_t n, const Elem_0093de99_shapec03_gzcom& x, const Tag_0093de99_shapec03_gzcom& tag);

struct Alloc_0093de99_shapec03_gzcom {
    Elem_0093de99_shapec03_gzcom* mpEnd;
    // STUB: 0x009db998
    Elem_0093de99_shapec03_gzcom* Allocate(uint32_t n);
};

struct View_0093de99_shapec03_gzcom {
    Elem_0093de99_shapec03_gzcom* mpStart;
    Elem_0093de99_shapec03_gzcom* mpFinish;
    Alloc_0093de99_shapec03_gzcom mAlloc;
    // STUB: 0x0093de49
    void Destroy();
    void Fn0093de99(Elem_0093de99_shapec03_gzcom* pos, const Elem_0093de99_shapec03_gzcom& x, const Tag_0093de99_shapec03_gzcom& tag, uint32_t n, bool atEnd);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0093de99 score 19
void View_0093de99_shapec03_gzcom::Fn0093de99(Elem_0093de99_shapec03_gzcom* pos, const Elem_0093de99_shapec03_gzcom& x, const Tag_0093de99_shapec03_gzcom& tag, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpFinish - mpStart);
    const uint32_t& grow = oldSize < n ? n : oldSize;
    uint32_t newSize = grow + oldSize;
    Alloc_0093de99_shapec03_gzcom* alloc = &mAlloc;
    Elem_0093de99_shapec03_gzcom* newStart = alloc->Allocate(newSize);
    Elem_0093de99_shapec03_gzcom* cur = Copy_0093de99(mpStart, pos, newStart, tag);
    if (n == 1) {
        if (cur) {
            new (cur) Elem_0093de99_shapec03_gzcom(x);
        }
        ++cur;
    } else {
        cur = Fill_0093de99(cur, n, x, tag);
    }
    if (!atEnd) {
        cur = Copy_0093de99(pos, mpFinish, cur, tag);
    }
    Destroy();
    mpStart = newStart;
    mpFinish = cur;
    alloc->mpEnd = newStart + newSize;
}
#endif

SHAPEC03_API long OB_STDCALL InterlockedIncrement(long* addend);
SHAPEC03_API long OB_STDCALL InterlockedDecrement(long* addend);

struct Lock_0096742c_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
};

// A scope guard over the lock: the constructor takes it, the destructor lets it go.
struct Guard_0096742c_shapec03_gzcom {
    uint32_t mPad;
    Lock_0096742c_shapec03_gzcom* mpLock;
    // STUB: 0x0048c9f0
    Guard_0096742c_shapec03_gzcom(Lock_0096742c_shapec03_gzcom* lock);
    ~Guard_0096742c_shapec03_gzcom() { mpLock->Release(); }
};

struct Target_0096742c_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Set(float) = 0;
};

struct Listener_0096742c_shapec03_gzcom {
    virtual bool QueryInterface(uint32_t id, void** out) = 0;
};

struct Node_0096742c_shapec03_gzcom {
    Node_0096742c_shapec03_gzcom* mpNext;
    uint8_t mPad4[4];
    Listener_0096742c_shapec03_gzcom* mpValue;
};

struct View_0096742c_shapec03_gzcom {
    uint8_t mPad[128];
    Node_0096742c_shapec03_gzcom* mpHeader;
    long mnLock;
    uint8_t mLock[4];
    uint8_t mPad8c[120];
    float mfValue;
    bool Fn0096742c(float value);
};

// FUNCTION: 0x0096742c
bool View_0096742c_shapec03_gzcom::Fn0096742c(float value)
{
    mfValue = value;
    Guard_0096742c_shapec03_gzcom guard(reinterpret_cast<Lock_0096742c_shapec03_gzcom*>(mLock));
    InterlockedIncrement(&mnLock);
    Node_0096742c_shapec03_gzcom* node = mpHeader->mpNext;
    if (node != mpHeader) {
        do {
            Listener_0096742c_shapec03_gzcom* listener = node->mpValue;
            Target_0096742c_shapec03_gzcom* target = 0;
            if (listener->QueryInterface(0x5b30e7b3, reinterpret_cast<void**>(&target))) {
                target->Set(value);
            }
            if (target) {
                target->Release();
            }
            node = node->mpNext;
        } while (node != mpHeader);
    }
    InterlockedDecrement(&mnLock);
    return true;
}

struct Target_009674bd_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Set(float) = 0;
};

struct Listener_009674bd_shapec03_gzcom {
    virtual bool QueryInterface(uint32_t id, void** out) = 0;
};

struct Node_009674bd_shapec03_gzcom {
    Node_009674bd_shapec03_gzcom* mpNext;
    uint8_t mPad4[4];
    Listener_009674bd_shapec03_gzcom* mpValue;
};

struct View_009674bd_shapec03_gzcom {
    uint8_t mPad[128];
    Node_009674bd_shapec03_gzcom* mpHeader;
    long mnLock;
    uint8_t mLock[4];
    uint8_t mPad8c[124];
    float mfValue;
    bool Fn009674bd(float value);
};

// FUNCTION: 0x009674bd
bool View_009674bd_shapec03_gzcom::Fn009674bd(float value)
{
    mfValue = value;
    Guard_0096742c_shapec03_gzcom guard(reinterpret_cast<Lock_0096742c_shapec03_gzcom*>(mLock));
    InterlockedIncrement(&mnLock);
    Node_009674bd_shapec03_gzcom* node = mpHeader->mpNext;
    if (node != mpHeader) {
        do {
            Listener_009674bd_shapec03_gzcom* listener = node->mpValue;
            Target_009674bd_shapec03_gzcom* target = 0;
            if (listener->QueryInterface(0x5b30e7b3, reinterpret_cast<void**>(&target))) {
                target->Set(value);
            }
            if (target) {
                target->Release();
            }
            node = node->mpNext;
        } while (node != mpHeader);
    }
    InterlockedDecrement(&mnLock);
    return true;
}

struct Target_0096754e_shapec03_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Set(float) = 0;
};

struct Listener_0096754e_shapec03_gzcom {
    virtual bool QueryInterface(uint32_t id, void** out) = 0;
};

struct Node_0096754e_shapec03_gzcom {
    Node_0096754e_shapec03_gzcom* mpNext;
    uint8_t mPad4[4];
    Listener_0096754e_shapec03_gzcom* mpValue;
};

struct View_0096754e_shapec03_gzcom {
    uint8_t mPad[128];
    Node_0096754e_shapec03_gzcom* mpHeader;
    long mnLock;
    uint8_t mLock[4];
    uint8_t mPad8c[128];
    float mfValue;
    bool Fn0096754e(float value);
};

// FUNCTION: 0x0096754e
bool View_0096754e_shapec03_gzcom::Fn0096754e(float value)
{
    mfValue = value;
    Guard_0096742c_shapec03_gzcom guard(reinterpret_cast<Lock_0096742c_shapec03_gzcom*>(mLock));
    InterlockedIncrement(&mnLock);
    Node_0096754e_shapec03_gzcom* node = mpHeader->mpNext;
    if (node != mpHeader) {
        do {
            Listener_0096754e_shapec03_gzcom* listener = node->mpValue;
            Target_0096754e_shapec03_gzcom* target = 0;
            if (listener->QueryInterface(0x5b30e7b3, reinterpret_cast<void**>(&target))) {
                target->Set(value);
            }
            if (target) {
                target->Release();
            }
            node = node->mpNext;
        } while (node != mpHeader);
    }
    InterlockedDecrement(&mnLock);
    return true;
}

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

// STUB: 0x00407a50
void* DequeCopy_shapec03_gzcom(const void* first, const void* last, void* out);

// STUB: 0x00413d00
void* DequeCopyBackward_shapec03_gzcom(const void* first, const void* last, void* out);

struct Size_00973c0e_shapec03_gzcom {
    uint32_t mnData;
    const uint32_t& Get() const { return mnData; }
};

struct Map_00973c0e_shapec03_gzcom {
    uint8_t** mpData;
    // STUB: 0x009db998
    uint8_t** Allocate(uint32_t n);
};

struct View_00973c0e_shapec03_gzcom {
    uint8_t mPad[4];
    uint8_t* mpStartFirst;
    uint8_t* mpStartLast;
    uint8_t** mpStartNode;
    uint8_t mPad10[4];
    uint8_t* mpFinishFirst;
    uint8_t* mpFinishLast;
    uint8_t** mpFinishNode;
    Map_00973c0e_shapec03_gzcom mMap;
    Size_00973c0e_shapec03_gzcom mMapSize;
    void Fn00973c0e(uint32_t nodesToAdd, bool addAtFront);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00973c0e score 70
void View_00973c0e_shapec03_gzcom::Fn00973c0e(uint32_t nodesToAdd, bool addAtFront)
{
    uint32_t oldNum = static_cast<uint32_t>(mpFinishNode - mpStartNode) + 1;
    uint32_t newNum = oldNum + nodesToAdd;
    uint8_t** newStart;
    if (mMapSize.Get() > 2 * newNum) {
        newStart = mMap.mpData + (mMapSize.Get() - newNum) / 2 + (addAtFront ? nodesToAdd : 0);
        if (newStart < mpStartNode) {
            DequeCopy_shapec03_gzcom(mpStartNode, mpFinishNode + 1, newStart);
        } else {
            DequeCopyBackward_shapec03_gzcom(mpStartNode, mpFinishNode + 1, newStart + oldNum);
        }
    } else {
        const uint32_t& biggest = mMapSize.Get() < nodesToAdd ? nodesToAdd : mMapSize.Get();
        uint32_t newMapSize = mMapSize.Get() + biggest + 2;
        uint8_t** newMap = mMap.Allocate(newMapSize);
        newStart = newMap + (newMapSize - newNum) / 2 + (addAtFront ? nodesToAdd : 0);
        DequeCopy_shapec03_gzcom(mpStartNode, mpFinishNode + 1, newStart);
        if (mMap.mpData) {
            _STL::__stl_delete(mMap.mpData);
        }
        mMap.mpData = newMap;
        mMapSize.mnData = newMapSize;
    }
    mpStartNode = newStart;
    mpStartFirst = *newStart;
    mpStartLast = mpStartFirst + 0x80;
    mpFinishNode = newStart + oldNum - 1;
    mpFinishFirst = *mpFinishNode;
    mpFinishLast = mpFinishFirst + 0x80;
}
#endif

struct Size_00982c25_shapec03_gzcom {
    uint32_t mnData;
    const uint32_t& Get() const { return mnData; }
};

struct Map_00982c25_shapec03_gzcom {
    uint8_t** mpData;
    // STUB: 0x009db998
    uint8_t** Allocate(uint32_t n);
};

struct View_00982c25_shapec03_gzcom {
    uint8_t mPad[4];
    uint8_t* mpStartFirst;
    uint8_t* mpStartLast;
    uint8_t** mpStartNode;
    uint8_t mPad10[4];
    uint8_t* mpFinishFirst;
    uint8_t* mpFinishLast;
    uint8_t** mpFinishNode;
    Map_00982c25_shapec03_gzcom mMap;
    Size_00982c25_shapec03_gzcom mMapSize;
    void Fn00982c25(uint32_t nodesToAdd, bool addAtFront);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00982c25 score 70
void View_00982c25_shapec03_gzcom::Fn00982c25(uint32_t nodesToAdd, bool addAtFront)
{
    uint32_t oldNum = static_cast<uint32_t>(mpFinishNode - mpStartNode) + 1;
    uint32_t newNum = oldNum + nodesToAdd;
    uint8_t** newStart;
    if (mMapSize.Get() > 2 * newNum) {
        newStart = mMap.mpData + (mMapSize.Get() - newNum) / 2 + (addAtFront ? nodesToAdd : 0);
        if (newStart < mpStartNode) {
            DequeCopy_shapec03_gzcom(mpStartNode, mpFinishNode + 1, newStart);
        } else {
            DequeCopyBackward_shapec03_gzcom(mpStartNode, mpFinishNode + 1, newStart + oldNum);
        }
    } else {
        const uint32_t& biggest = mMapSize.Get() < nodesToAdd ? nodesToAdd : mMapSize.Get();
        uint32_t newMapSize = mMapSize.Get() + biggest + 2;
        uint8_t** newMap = mMap.Allocate(newMapSize);
        newStart = newMap + (newMapSize - newNum) / 2 + (addAtFront ? nodesToAdd : 0);
        DequeCopy_shapec03_gzcom(mpStartNode, mpFinishNode + 1, newStart);
        if (mMap.mpData) {
            _STL::__stl_delete(mMap.mpData);
        }
        mMap.mpData = newMap;
        mMapSize.mnData = newMapSize;
    }
    mpStartNode = newStart;
    mpStartFirst = *newStart;
    mpStartLast = mpStartFirst + 0x70;
    mpFinishNode = newStart + oldNum - 1;
    mpFinishFirst = *mpFinishNode;
    mpFinishLast = mpFinishFirst + 0x70;
}
#endif

struct Size_0092f62a_shapec03_gzcom {
    uint32_t mnData;
    const uint32_t& Get() const { return mnData; }
};

struct Map_0092f62a_shapec03_gzcom {
    uint8_t** mpData;
    // STUB: 0x009db998
    uint8_t** Allocate(uint32_t n);
};

struct View_0092f62a_shapec03_gzcom {
    uint8_t mPad[4];
    uint8_t* mpStartFirst;
    uint8_t* mpStartLast;
    uint8_t** mpStartNode;
    uint8_t mPad10[4];
    uint8_t* mpFinishFirst;
    uint8_t* mpFinishLast;
    uint8_t** mpFinishNode;
    Map_0092f62a_shapec03_gzcom mMap;
    Size_0092f62a_shapec03_gzcom mMapSize;
    void Fn0092f62a(uint32_t nodesToAdd, bool addAtFront);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0092f62a score 70
void View_0092f62a_shapec03_gzcom::Fn0092f62a(uint32_t nodesToAdd, bool addAtFront)
{
    uint32_t oldNum = static_cast<uint32_t>(mpFinishNode - mpStartNode) + 1;
    uint32_t newNum = oldNum + nodesToAdd;
    uint8_t** newStart;
    if (mMapSize.Get() > 2 * newNum) {
        newStart = mMap.mpData + (mMapSize.Get() - newNum) / 2 + (addAtFront ? nodesToAdd : 0);
        if (newStart < mpStartNode) {
            DequeCopy_shapec03_gzcom(mpStartNode, mpFinishNode + 1, newStart);
        } else {
            DequeCopyBackward_shapec03_gzcom(mpStartNode, mpFinishNode + 1, newStart + oldNum);
        }
    } else {
        const uint32_t& biggest = mMapSize.Get() < nodesToAdd ? nodesToAdd : mMapSize.Get();
        uint32_t newMapSize = mMapSize.Get() + biggest + 2;
        uint8_t** newMap = mMap.Allocate(newMapSize);
        newStart = newMap + (newMapSize - newNum) / 2 + (addAtFront ? nodesToAdd : 0);
        DequeCopy_shapec03_gzcom(mpStartNode, mpFinishNode + 1, newStart);
        if (mMap.mpData) {
            _STL::__stl_delete(mMap.mpData);
        }
        mMap.mpData = newMap;
        mMapSize.mnData = newMapSize;
    }
    mpStartNode = newStart;
    mpStartFirst = *newStart;
    mpStartLast = mpStartFirst + 0x78;
    mpFinishNode = newStart + oldNum - 1;
    mpFinishFirst = *mpFinishNode;
    mpFinishLast = mpFinishFirst + 0x78;
}
#endif
