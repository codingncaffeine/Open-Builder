// Shape families of packet shaped03_gzcom (pairs), written by hand.
#include "common/types.h"
#include <new>
#include "common/compiler.h"

// ---- 0096ba27 / 009cdaab
// a class creator, as the COM directors register them
typedef void* (*ClsMaker_shaped03_gzcom)();
// handed on as a plain pointer: the hook generator reads no function-pointer parameter in a STUB declaration
inline void* ClsPtr_shaped03_gzcom(ClsMaker_shaped03_gzcom f) { return reinterpret_cast<void*>(f); }

struct View_0096ba27_shaped03_gzcom {
    void* Slot06();
};

// FUNCTION: 0x0096ba27
void* View_0096ba27_shaped03_gzcom::Slot06()
{
    return reinterpret_cast<char*>(this) - 0x2c;
}

struct View_009cdaab_shaped03_gzcom {
    void* Slot03();
};

// FUNCTION: 0x009cdaab
void* View_009cdaab_shaped03_gzcom::Slot03()
{
    return reinterpret_cast<char*>(this) - 0xdc;
}

// ---- 00938798 / 00945e53
struct Sub_00938798_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;
    virtual void a03() = 0;
    virtual void a04() = 0;
    virtual void a05() = 0;
    virtual void a06() = 0;
    virtual void a07() = 0;
    virtual void a08() = 0;
    virtual void a09() = 0;
    virtual void a0a() = 0;
    virtual void a0b() = 0;
    virtual void a0c() = 0;
    virtual void a0d() = 0;

    virtual void Call0e(uint32_t a) = 0;
};

struct View_00938798_shaped03_gzcom {
    uint8_t mPad00[0x20];
    bool Slot33(uint32_t a);
};

// FUNCTION: 0x00938798
bool View_00938798_shaped03_gzcom::Slot33(uint32_t a)
{
    reinterpret_cast<Sub_00938798_shaped03_gzcom*>(mPad00 + 0x20)->Call0e(a);
    return true;
}

struct Sub_00945e53_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;
    virtual void a03() = 0;
    virtual void a04() = 0;
    virtual void a05() = 0;
    virtual void a06() = 0;
    virtual void a07() = 0;
    virtual void a08() = 0;
    virtual void a09() = 0;
    virtual void a0a() = 0;
    virtual void a0b() = 0;
    virtual void a0c() = 0;

    virtual void Call0d(uint32_t a) = 0;
};

struct View_00945e53_shaped03_gzcom {
    uint8_t mPad00[0xc];
    bool SetFilename(uint32_t a);
};

// FUNCTION: 0x00945e53
bool View_00945e53_shaped03_gzcom::SetFilename(uint32_t a)
{
    reinterpret_cast<Sub_00945e53_shaped03_gzcom*>(mPad00 + 0xc)->Call0d(a);
    return true;
}

// ---- 00969efa / 00985001
struct View_00969efa_shaped03_gzcom {
    virtual void a00() = 0;
    uint32_t mnRefs;
    virtual void b00() = 0;
    virtual void b01() = 0;
    virtual void b02() = 0;
    virtual void b03() = 0;
    virtual void b04() = 0;
    virtual void b05() = 0;
    virtual void b06() = 0;
    virtual void b07() = 0;
    virtual void b08() = 0;
    virtual void b09() = 0;
    virtual void b0a() = 0;
    virtual void b0b() = 0;
    virtual void b0c() = 0;
    virtual void b0d() = 0;
    virtual void b0e() = 0;

    virtual void Destroy10(uint32_t a) = 0;
    uint32_t Release();
};

// FUNCTION: 0x00969efa
uint32_t View_00969efa_shaped03_gzcom::Release()
{
    if (--mnRefs == 0) {
        Destroy10(1);
        return 0;
    }
    return mnRefs;
}

struct View_00985001_shaped03_gzcom {
    virtual void a00() = 0;
    uint32_t mnRefs;
    virtual void b00() = 0;
    virtual void b01() = 0;
    virtual void b02() = 0;
    virtual void b03() = 0;
    virtual void b04() = 0;
    virtual void b05() = 0;
    virtual void b06() = 0;
    virtual void b07() = 0;
    virtual void b08() = 0;
    virtual void b09() = 0;
    virtual void b0a() = 0;
    virtual void b0b() = 0;
    virtual void b0c() = 0;

    virtual void Destroy0e(uint32_t a) = 0;
    uint32_t Slot02();
};

// FUNCTION: 0x00985001
uint32_t View_00985001_shaped03_gzcom::Slot02()
{
    if (--mnRefs == 0) {
        Destroy0e(1);
        return 0;
    }
    return mnRefs;
}

// ---- 0097954b / 0097955d
struct Sub_0097954b_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;
    virtual void a03() = 0;
    virtual void a04() = 0;
    virtual void a05() = 0;
    virtual void a06() = 0;

    virtual uint32_t Call07() = 0;
};

struct View_0097954b_shaped03_gzcom {
    uint8_t mPad00[0x44];
    uint8_t mbFlag;
    uint8_t mPad45[3];
    uint8_t mSub[4];
    uint32_t Slot03();
};

// FUNCTION: 0x0097954b
uint32_t View_0097954b_shaped03_gzcom::Slot03()
{
    if (mbFlag) {
        return reinterpret_cast<Sub_0097954b_shaped03_gzcom*>(mSub)->Call07();
    }
    return 0xffffffff;
}

struct Sub_0097955d_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;
    virtual void a03() = 0;
    virtual void a04() = 0;
    virtual void a05() = 0;

    virtual uint32_t Call06() = 0;
};

struct View_0097955d_shaped03_gzcom {
    uint8_t mPad00[0x40];
    uint8_t mbFlag;
    uint8_t mPad41[3];
    uint8_t mSub[4];
    uint32_t Slot54();
};

// FUNCTION: 0x0097955d
uint32_t View_0097955d_shaped03_gzcom::Slot54()
{
    if (mbFlag) {
        return reinterpret_cast<Sub_0097955d_shaped03_gzcom*>(mSub)->Call06();
    }
    return 0xffffffff;
}

// ---- 0093862f / 009387a9
struct Arg_0093862f_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;
    virtual void a03() = 0;
    virtual void a04() = 0;
    virtual void a05() = 0;
    virtual void a06() = 0;
    virtual void a07() = 0;
    virtual void a08() = 0;
    virtual void a09() = 0;
    virtual void a0a() = 0;
    virtual void a0b() = 0;
    virtual void a0c() = 0;
    virtual void a0d() = 0;

    virtual void Call0e(void* p) = 0;
};

struct View_0093862f_shaped03_gzcom {
    uint8_t mPad00[8];
    uint8_t mSub[4];
    bool Slot04(Arg_0093862f_shaped03_gzcom* a);
};

// FUNCTION: 0x0093862f
bool View_0093862f_shaped03_gzcom::Slot04(Arg_0093862f_shaped03_gzcom* a)
{
    a->Call0e(mSub);
    return true;
}

struct View_009387a9_shaped03_gzcom {
    uint8_t mPad00[0x20];
    uint8_t mSub[4];
    bool Slot34(Arg_0093862f_shaped03_gzcom* a);
};

// FUNCTION: 0x009387a9
bool View_009387a9_shaped03_gzcom::Slot34(Arg_0093862f_shaped03_gzcom* a)
{
    a->Call0e(mSub);
    return true;
}

// ---- 00948f38 / 00948f4d
struct View_00948f38_shaped03_gzcom {
    uint8_t mPad00[0x54];
    uint32_t mnValue;
    bool Slot30(uint32_t a);
};

// FUNCTION: 0x00948f38
bool View_00948f38_shaped03_gzcom::Slot30(uint32_t a)
{
    if (a >= 3) {
        return false;
    }
    mnValue = a;
    return true;
}

struct View_00948f4d_shaped03_gzcom {
    uint8_t mPad00[0x58];
    uint32_t mnValue;
    bool Slot31(uint32_t a);
};

// FUNCTION: 0x00948f4d
bool View_00948f4d_shaped03_gzcom::Slot31(uint32_t a)
{
    if (a >= 3) {
        return false;
    }
    mnValue = a;
    return true;
}

// ---- 00944478 / 0096643d
struct Obj_00944478_shaped03_gzcom {
    uint8_t mPad00[0x14];
    // STUB: 0x009453d4
    Obj_00944478_shaped03_gzcom* Init();
};

// FUNCTION: 0x00944478
Obj_00944478_shaped03_gzcom* Fn00944478()
{
    Obj_00944478_shaped03_gzcom* p = new Obj_00944478_shaped03_gzcom;
    if (p) {
        return p->Init();
    }
    return 0;
}

struct Obj_0096643d_shaped03_gzcom {
    uint8_t mPad00[0x14];
    // STUB: 0x0096a6a9
    Obj_0096643d_shaped03_gzcom* Init();
};

// FUNCTION: 0x0096643d
Obj_0096643d_shaped03_gzcom* Fn0096643d()
{
    Obj_0096643d_shaped03_gzcom* p = new Obj_0096643d_shaped03_gzcom;
    if (p) {
        return p->Init();
    }
    return 0;
}

// ---- 00941636 / 0094164d
struct Fn_00941636_shaped03_gzcom {
    uint8_t mPad00[8];
    // STUB: 0x00940973
    void Run(uint32_t a, void* b, uint32_t c);
};

struct View_00941636_shaped03_gzcom {
    void Write_XML(uint32_t a, uint32_t /*b*/, uint32_t /*c*/);
};

// FUNCTION: 0x00941636
void View_00941636_shaped03_gzcom::Write_XML(uint32_t a, uint32_t /*b*/, uint32_t /*c*/)
{
    Fn_00941636_shaped03_gzcom local;
    local.Run(a, this, 0);
}

struct View_0094164d_shaped03_gzcom {
    void Write_Binary(uint32_t a, uint32_t /*b*/, uint32_t /*c*/);
};

// FUNCTION: 0x0094164d
void View_0094164d_shaped03_gzcom::Write_Binary(uint32_t a, uint32_t /*b*/, uint32_t /*c*/)
{
    Fn_00941636_shaped03_gzcom local;
    local.Run(a, this, 1);
}

// ---- 009753ea / 00975666
struct View_009753ea_shaped03_gzcom {
    uint8_t mPad00[0xc];
    uint32_t mn0c;
    uint32_t mn10;
    uint32_t mn14;
    void Slot03(uint32_t* out);
};

// FUNCTION: 0x009753ea
void View_009753ea_shaped03_gzcom::Slot03(uint32_t* out)
{
    out[0] = mn0c;
    out[1] = mn10;
    out[2] = mn14;
}

struct View_00975666_shaped03_gzcom {
    uint8_t mPad00[8];
    uint32_t mn08;
    uint32_t mn0c;
    uint32_t mn10;
    void Slot03(uint32_t* out);
};

// FUNCTION: 0x00975666
void View_00975666_shaped03_gzcom::Slot03(uint32_t* out)
{
    out[0] = mn08;
    out[1] = mn0c;
    out[2] = mn10;
}

// ---- 009385d6 / 00939237
struct Sub_009385d6_shaped03_gzcom {
    uint8_t mPad00[0x14];
    // STUB: 0x00578390
    Sub_009385d6_shaped03_gzcom* Init();
};

struct View_009385d6_shaped03_gzcom {
    uint32_t mnVtable;
    uint32_t mn04;
    Sub_009385d6_shaped03_gzcom mSub;
    uint32_t mn1c;
    View_009385d6_shaped03_gzcom* Fn009385d6();
};

// FUNCTION: 0x009385d6
View_009385d6_shaped03_gzcom* View_009385d6_shaped03_gzcom::Fn009385d6()
{
    mn04 = 0;
    mnVtable = 0xad265c;
    mSub.Init();
    mn1c = 0;
    return this;
}

struct Sub_00939237_shaped03_gzcom {
    uint8_t mPad00[0xc];
    // STUB: 0x0096f57b
    void Init();
};

struct View_00939237_shaped03_gzcom {
    uint32_t mnVtable;
    uint32_t mn04;
    Sub_00939237_shaped03_gzcom mSub;
    uint32_t mn14;
    View_00939237_shaped03_gzcom* Fn00939237();
};

// FUNCTION: 0x00939237
View_00939237_shaped03_gzcom* View_00939237_shaped03_gzcom::Fn00939237()
{
    mn04 = 0;
    mnVtable = 0xad27d4;
    mSub.Init();
    mn14 = 0;
    return this;
}

// ---- 00944f7c / 00944f99
struct Tgt_00944f7c_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;
    virtual void a03() = 0;

    virtual void Call04(void* a, uint32_t b) = 0;
};

struct View_00944f7c_shaped03_gzcom {
    uint8_t mPad00[8];
    Tgt_00944f7c_shaped03_gzcom* mpTarget;
    // STUB: 0x00944eea
    void Fn00944eea();
    bool Fn00944f7c();
    bool Fn00944f99();
};

// FUNCTION: 0x00944f7c
bool View_00944f7c_shaped03_gzcom::Fn00944f7c()
{
    Fn00944eea();
    if (mpTarget) {
        mpTarget->Call04(this, 0);
    }
    return true;
}

// FUNCTION: 0x00944f99
bool View_00944f7c_shaped03_gzcom::Fn00944f99()
{
    Fn00944eea();
    if (mpTarget) {
        mpTarget->Call04(this, 1);
    }
    return true;
}

// ---- 0094c3f5 / 0094c413
struct Tgt_0094c3f5_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;
    virtual void a03() = 0;
    virtual void a04() = 0;
    virtual void a05() = 0;
    virtual void a06() = 0;
    virtual void a07() = 0;
    virtual void a08() = 0;
    virtual void a09() = 0;
    virtual void a0a() = 0;
    virtual void a0b() = 0;
    virtual void a0c() = 0;
    virtual void a0d() = 0;
    virtual void a0e() = 0;
    virtual void a0f() = 0;
    virtual void a10() = 0;
    virtual void a11() = 0;
    virtual void a12() = 0;
    virtual void a13() = 0;
    virtual void a14() = 0;
    virtual void a15() = 0;
    virtual void a16() = 0;
    virtual void a17() = 0;
    virtual void a18() = 0;
    virtual void a19() = 0;
    virtual void a1a() = 0;
    virtual void a1b() = 0;
    virtual void a1c() = 0;
    virtual void a1d() = 0;
    virtual void a1e() = 0;
    virtual void a1f() = 0;
    virtual void a20() = 0;
    virtual void a21() = 0;
    virtual void a22() = 0;
    virtual void a23() = 0;
    virtual void a24() = 0;
    virtual void a25() = 0;
    virtual void a26() = 0;
    virtual void a27() = 0;
    virtual void a28() = 0;
    virtual void a29() = 0;
    virtual void a2a() = 0;
    virtual void a2b() = 0;
    virtual void a2c() = 0;
    virtual void a2d() = 0;
    virtual void a2e() = 0;
    virtual void a2f() = 0;
    virtual void a30() = 0;
    virtual void a31() = 0;
    virtual void a32() = 0;
    virtual void a33() = 0;
    virtual void a34() = 0;
    virtual void a35() = 0;

    virtual void Call36(uint32_t a) = 0;
};

struct View_0094c3f5_shaped03_gzcom {
    uint8_t mPad00[0xc];
    Tgt_0094c3f5_shaped03_gzcom* mpTarget;
    bool SetArea(uint32_t a);
};

// FUNCTION: 0x0094c3f5
bool View_0094c3f5_shaped03_gzcom::SetArea(uint32_t a)
{
    if (mpTarget) {
        mpTarget->Call36(a);
        return true;
    }
    return false;
}

struct Tgt_0094c413_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;
    virtual void a03() = 0;
    virtual void a04() = 0;
    virtual void a05() = 0;
    virtual void a06() = 0;
    virtual void a07() = 0;
    virtual void a08() = 0;
    virtual void a09() = 0;
    virtual void a0a() = 0;
    virtual void a0b() = 0;
    virtual void a0c() = 0;
    virtual void a0d() = 0;
    virtual void a0e() = 0;
    virtual void a0f() = 0;
    virtual void a10() = 0;
    virtual void a11() = 0;
    virtual void a12() = 0;
    virtual void a13() = 0;
    virtual void a14() = 0;
    virtual void a15() = 0;
    virtual void a16() = 0;
    virtual void a17() = 0;
    virtual void a18() = 0;
    virtual void a19() = 0;
    virtual void a1a() = 0;
    virtual void a1b() = 0;
    virtual void a1c() = 0;
    virtual void a1d() = 0;
    virtual void a1e() = 0;
    virtual void a1f() = 0;
    virtual void a20() = 0;
    virtual void a21() = 0;
    virtual void a22() = 0;
    virtual void a23() = 0;
    virtual void a24() = 0;
    virtual void a25() = 0;
    virtual void a26() = 0;
    virtual void a27() = 0;
    virtual void a28() = 0;
    virtual void a29() = 0;
    virtual void a2a() = 0;
    virtual void a2b() = 0;
    virtual void a2c() = 0;
    virtual void a2d() = 0;
    virtual void a2e() = 0;

    virtual void Call2f(uint32_t a) = 0;
};

struct View_0094c413_shaped03_gzcom {
    uint8_t mPad00[0xc];
    Tgt_0094c413_shaped03_gzcom* mpTarget;
    bool GetArea(uint32_t a);
};

// FUNCTION: 0x0094c413
bool View_0094c413_shaped03_gzcom::GetArea(uint32_t a)
{
    if (mpTarget) {
        mpTarget->Call2f(a);
        return true;
    }
    return false;
}

// ---- 00969e68 / 0096a31c
struct Own_00969e68_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;

    virtual void Call02() = 0;
};

struct Sub_00969e68_shaped03_gzcom {
    uint8_t mPad00[4];
    // STUB: 0x005650a0
    void Fini();
};

struct View_00969e68_shaped03_gzcom {
    uint32_t mnVtable;
    uint32_t mn04;
    Own_00969e68_shaped03_gzcom* mpOwn;
    Sub_00969e68_shaped03_gzcom mSub;
    void Fn00969e68();
};

// FUNCTION: 0x00969e68
void View_00969e68_shaped03_gzcom::Fn00969e68()
{
    mnVtable = 0xad73d4;
    mSub.Fini();
    if (mpOwn) {
        mpOwn->Call02();
    }
}

struct Own_0096a31c_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;

    virtual void Call02() = 0;
};

struct Sub_0096a31c_shaped03_gzcom {
    uint8_t mPad00[4];
    // STUB: 0x0096a305
    void Fini();
};

struct View_0096a31c_shaped03_gzcom {
    uint32_t mnVtable;
    uint32_t mn04;
    Own_0096a31c_shaped03_gzcom* mpOwn;
    Sub_0096a31c_shaped03_gzcom mSub;
    void Fn0096a31c();
};

// FUNCTION: 0x0096a31c
void View_0096a31c_shaped03_gzcom::Fn0096a31c()
{
    mnVtable = 0xad73f8;
    mSub.Fini();
    if (mpOwn) {
        mpOwn->Call02();
    }
}

// ---- 0092d5c4 / 009833ab
struct Elem_0092d5c4_shaped03_gzcom {
    // STUB: 0x00473180
    void Destroy();
};

struct Iter_0092d5c4_shaped03_gzcom {
    Elem_0092d5c4_shaped03_gzcom* mpCur;
    uint32_t mnFirst;
    uint32_t mnLast;
    uint32_t mnNode;
    // STUB: 0x0092d26d
    void Increment();
};

// FUNCTION: 0x0092d5c4
void Fn0092d5c4(Iter_0092d5c4_shaped03_gzcom first, Iter_0092d5c4_shaped03_gzcom last)
{
    for (; first.mpCur != last.mpCur; first.Increment()) {
        first.mpCur->Destroy();
    }
}

struct Elem_009833ab_shaped03_gzcom {
    // STUB: 0x009831f0
    void Destroy();
};

struct Iter_009833ab_shaped03_gzcom {
    Elem_009833ab_shaped03_gzcom* mpCur;
    uint32_t mnFirst;
    uint32_t mnLast;
    uint32_t mnNode;
    // STUB: 0x00981ab6
    void Increment();
};

// FUNCTION: 0x009833ab
void Fn009833ab(Iter_009833ab_shaped03_gzcom first, Iter_009833ab_shaped03_gzcom last)
{
    for (; first.mpCur != last.mpCur; first.Increment()) {
        first.mpCur->Destroy();
    }
}

// ---- 0095bab3 / 009cdb5a
struct SubVt_shaped03_gzcom {
    uint32_t mnVtable;
    void SetA(uint32_t v) { mnVtable = v; }
    void SetB(uint32_t v) { mnVtable = v; }
};

struct View_0095bab3_shaped03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad04[0xd4];
    SubVt_shaped03_gzcom mSubVt;
    // STUB: 0x0099d938
    void Base();
    View_0095bab3_shaped03_gzcom* Fn0095bab3();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0095bab3 score 4
View_0095bab3_shaped03_gzcom* View_0095bab3_shaped03_gzcom::Fn0095bab3()
{
    Base();
    mSubVt.SetA(0xad6cfc);
    mSubVt.SetB(0xad6a8c);
    mnVtable = 0xad6aa0;
    return this;
}
#endif

struct View_009cdb5a_shaped03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad04[0xd4];
    SubVt_shaped03_gzcom mSubVt;
    // STUB: 0x0099d938
    void Base();
    View_009cdb5a_shaped03_gzcom* Fn009cdb5a();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009cdb5a score 4
View_009cdb5a_shaped03_gzcom* View_009cdb5a_shaped03_gzcom::Fn009cdb5a()
{
    Base();
    mSubVt.SetA(0xae2350);
    mSubVt.SetB(0xae25f4);
    mnVtable = 0xae2398;
    return this;
}
#endif

// ---- 00975197 / 009751bb
struct Obj_00975197_shaped03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad04[0xc];
    // STUB: 0x0097564d
    void Init();
};

// FUNCTION: 0x00975197
Obj_00975197_shaped03_gzcom* Fn00975197()
{
    Obj_00975197_shaped03_gzcom* p = new Obj_00975197_shaped03_gzcom;
    if (p) {
        p->Init();
        p->mnVtable = 0xad8b14;
        return p;
    }
    return 0;
}

struct Obj_009751bb_shaped03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad04[0xc];
    // STUB: 0x0097564d
    void Init();
};

// FUNCTION: 0x009751bb
Obj_009751bb_shaped03_gzcom* Fn009751bb()
{
    Obj_009751bb_shaped03_gzcom* p = new Obj_009751bb_shaped03_gzcom;
    if (p) {
        p->Init();
        p->mnVtable = 0xad8b44;
        return p;
    }
    return 0;
}

// ---- 00943554 / 0094365f
struct Iter_00943554_shaped03_gzcom {
    uint32_t mnPtr;
    Iter_00943554_shaped03_gzcom(const Iter_00943554_shaped03_gzcom& o) { mnPtr = o.mnPtr; }
};

struct Zero_00943554_shaped03_gzcom {
    uint8_t mb;
    Zero_00943554_shaped03_gzcom() { uint8_t* p = &mb; for (int i = 0; i < 1; ++i) { *p++ = 0; } }
};

struct View_00943554_shaped03_gzcom {
    // STUB: 0x0094357b
    void Fn0094357b(Iter_00943554_shaped03_gzcom a, uint32_t b, uint32_t c, Zero_00943554_shaped03_gzcom* d);
    void Fn00943554(Iter_00943554_shaped03_gzcom a, uint32_t b, uint32_t c);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00943554 score 8
void View_00943554_shaped03_gzcom::Fn00943554(Iter_00943554_shaped03_gzcom a, uint32_t b, uint32_t c)
{
    Zero_00943554_shaped03_gzcom local;
    Fn0094357b(a, b, c, &local);
}
#endif

struct View_0094365f_shaped03_gzcom {
    // STUB: 0x00943686
    void Fn00943686(Iter_00943554_shaped03_gzcom a, uint32_t b, uint32_t c, Zero_00943554_shaped03_gzcom* d);
    void Fn0094365f(Iter_00943554_shaped03_gzcom a, uint32_t b, uint32_t c);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0094365f score 8
void View_0094365f_shaped03_gzcom::Fn0094365f(Iter_00943554_shaped03_gzcom a, uint32_t b, uint32_t c)
{
    Zero_00943554_shaped03_gzcom local;
    Fn00943686(a, b, c, &local);
}
#endif

// ---- 00944c4b / 0094c0ec
struct Item_00944c4b_shaped03_gzcom {
    virtual void a00() = 0;

    virtual void Call01() = 0;
};

struct Arr_00944c4b_shaped03_gzcom {
    uint8_t mPad00[4];
    // STUB: 0x008ff785
    void PushBack(Item_00944c4b_shaped03_gzcom* const* p);
};

struct View_00944c4b_shaped03_gzcom {
    uint8_t mPad00[0x14];
    Arr_00944c4b_shaped03_gzcom mArr;
    bool PushVocabulary(Item_00944c4b_shaped03_gzcom* p);
};

// FUNCTION: 0x00944c4b
bool View_00944c4b_shaped03_gzcom::PushVocabulary(Item_00944c4b_shaped03_gzcom* p)
{
    if (p) {
        p->Call01();
        mArr.PushBack(&p);
        return true;
    }
    return false;
}

struct Arr_0094c0ec_shaped03_gzcom {
    uint8_t mPad00[4];
    // STUB: 0x0094c037
    void PushBack(Item_00944c4b_shaped03_gzcom* const* p);
};

struct View_0094c0ec_shaped03_gzcom {
    uint8_t mPad00[8];
    Arr_0094c0ec_shaped03_gzcom mArr;
    bool Slot04(Item_00944c4b_shaped03_gzcom* p);
};

// FUNCTION: 0x0094c0ec
bool View_0094c0ec_shaped03_gzcom::Slot04(Item_00944c4b_shaped03_gzcom* p)
{
    if (p) {
        p->Call01();
        mArr.PushBack(&p);
        return true;
    }
    return false;
}

// ---- 009667ca / 0096683a
struct View_009667ca_shaped03_gzcom {
    uint8_t mPad00[0xd8];
    float mfX;
    float mfY;
    float mfZ;
    void Fn009667ca(float* x, float* y, float* z);
};

// FUNCTION: 0x009667ca
void View_009667ca_shaped03_gzcom::Fn009667ca(float* x, float* y, float* z)
{
    *x = mfX;
    *y = mfY;
    *z = mfZ;
}

struct View_0096683a_shaped03_gzcom {
    uint8_t mPad00[0xf8];
    float mfX;
    float mfY;
    float mfZ;
    void Fn0096683a(float* x, float* y, float* z);
};

// FUNCTION: 0x0096683a
void View_0096683a_shaped03_gzcom::Fn0096683a(float* x, float* y, float* z)
{
    *x = mfX;
    *y = mfY;
    *z = mfZ;
}

// ---- 0092ec19 / 0092ec43
struct Wait_0092ec19_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;

    virtual void Call03(uint32_t a) = 0;
};

struct View_0092ec19_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void b00() = 0;
    virtual void b01() = 0;
    virtual void b02() = 0;
    virtual void b03() = 0;
    virtual void b04() = 0;
    virtual void b05() = 0;
    virtual void b06() = 0;
    virtual void b07() = 0;
    virtual void b08() = 0;
    virtual void b09() = 0;
    virtual void b0a() = 0;
    virtual void b0b() = 0;
    virtual void b0c() = 0;
    virtual void b0d() = 0;
    virtual void b0e() = 0;
    virtual void b0f() = 0;
    virtual void b10() = 0;

    virtual uint32_t Get12() = 0;
    virtual uint32_t Get13() = 0;
    uint8_t mPad04[0xc];
    uint8_t mWait[4];
    void GetFrontTypeBlock();
    void GetBackTypeBlock();
};

// FUNCTION: 0x0092ec19
void View_0092ec19_shaped03_gzcom::GetFrontTypeBlock()
{
    while (!Get12()) {
        reinterpret_cast<Wait_0092ec19_shaped03_gzcom*>(mWait)->Call03(1000000);
    }
}

// FUNCTION: 0x0092ec43
void View_0092ec19_shaped03_gzcom::GetBackTypeBlock()
{
    while (!Get13()) {
        reinterpret_cast<Wait_0092ec19_shaped03_gzcom*>(mWait)->Call03(1000000);
    }
}

// ---- 0093aafa / 009cba35
struct Elem_0093aafa_shaped03_gzcom {
    uint32_t mnValue;
    // STUB: 0x00969fea
    void Assign(Elem_0093aafa_shaped03_gzcom* src);
};

// FUNCTION: 0x0093aafa
Elem_0093aafa_shaped03_gzcom* Fn0093aafa(Elem_0093aafa_shaped03_gzcom* first, Elem_0093aafa_shaped03_gzcom* last, Elem_0093aafa_shaped03_gzcom* dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        --last;
        --dest;
        dest->Assign(last);
    }
    return dest;
}

struct Elem_009cba35_shaped03_gzcom {
    uint32_t mnValue;
    // STUB: 0x009cb959
    void Assign(Elem_009cba35_shaped03_gzcom* src);
};

// FUNCTION: 0x009cba35
Elem_009cba35_shaped03_gzcom* Fn009cba35(Elem_009cba35_shaped03_gzcom* first, Elem_009cba35_shaped03_gzcom* last, Elem_009cba35_shaped03_gzcom* dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        --last;
        --dest;
        dest->Assign(last);
    }
    return dest;
}

// ---- 0094ba22 / 0094ba51
struct Svc_0094ba22_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;

    virtual void Call03(void* a) = 0;
    virtual void b00() = 0;
    virtual void b01() = 0;

    virtual void Call06(uint32_t a) = 0;
    virtual void Call07(uint32_t a) = 0;
};

struct View_0094ba22_shaped03_gzcom {
    uint8_t mPad00[8];
    uint8_t mSub[0x2c];
    Svc_0094ba22_shaped03_gzcom* mpSvc;
    uint8_t mPad38[0x18];
    uint32_t mnResult;
    // STUB: 0x0094b73a
    bool TestSetup();
    uint32_t ExecuteScriptString(uint32_t a);
    uint32_t ExecuteScriptFile(uint32_t a);
};

// FUNCTION: 0x0094ba22
uint32_t View_0094ba22_shaped03_gzcom::ExecuteScriptString(uint32_t a)
{
    if (TestSetup()) {
        mpSvc->Call03(mSub);
        mpSvc->Call06(a);
    }
    uint32_t r = mnResult;
    mnResult = 0;
    return r;
}

// FUNCTION: 0x0094ba51
uint32_t View_0094ba22_shaped03_gzcom::ExecuteScriptFile(uint32_t a)
{
    if (TestSetup()) {
        mpSvc->Call03(mSub);
        mpSvc->Call07(a);
    }
    uint32_t r = mnResult;
    mnResult = 0;
    return r;
}

// ---- 00959e54 / 0095a0aa
struct Own_00959e54_shaped03_gzcom {
    // STUB: 0x00959e83
    bool Fn00959e83();
    // STUB: 0x00956136
    void Fn00956136();
};

struct View_00959e54_shaped03_gzcom {
    uint32_t mnVtable;
    Own_00959e54_shaped03_gzcom* mpOwn;
    uint8_t mPad08[4];
    uint8_t mbOwns;
    void Fn00959e54();
};

// FUNCTION: 0x00959e54
void View_00959e54_shaped03_gzcom::Fn00959e54()
{
    mnVtable = 0xad5398;
    if (mbOwns) {
        Own_00959e54_shaped03_gzcom* p = mpOwn;
        mpOwn = 0;
        if (p) {
            p->Fn00959e83();
            p->Fn00956136();
            operator delete(p);
        }
    }
}

struct Own_0095a0aa_shaped03_gzcom {
    // STUB: 0x0095a0d9
    bool Fn0095a0d9();
    // STUB: 0x00959f09
    void Fn00959f09();
};

struct View_0095a0aa_shaped03_gzcom {
    uint32_t mnVtable;
    Own_0095a0aa_shaped03_gzcom* mpOwn;
    uint8_t mPad08[4];
    uint8_t mbOwns;
    void Fn0095a0aa();
};

// FUNCTION: 0x0095a0aa
void View_0095a0aa_shaped03_gzcom::Fn0095a0aa()
{
    mnVtable = 0xad538c;
    if (mbOwns) {
        Own_0095a0aa_shaped03_gzcom* p = mpOwn;
        mpOwn = 0;
        if (p) {
            p->Fn0095a0d9();
            p->Fn00959f09();
            operator delete(p);
        }
    }
}

// ---- 0096a5d8 / 009d1e2a
struct Node_0096a5d8_shaped03_gzcom {
    Node_0096a5d8_shaped03_gzcom* mpNext;
    Node_0096a5d8_shaped03_gzcom* mpPrev;
};

struct Tgt_0096a5d8_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;
    virtual void a03() = 0;

    virtual void Call04(Node_0096a5d8_shaped03_gzcom* n) = 0;
};

struct View_0096a5d8_shaped03_gzcom {
    Node_0096a5d8_shaped03_gzcom* mpHead;
    // STUB: 0x0096a49e
    Tgt_0096a5d8_shaped03_gzcom* Fn0096a49e();
    void Fn0096a5d8();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096a5d8 score 3
void View_0096a5d8_shaped03_gzcom::Fn0096a5d8()
{
    Node_0096a5d8_shaped03_gzcom* node = mpHead->mpNext;
    while (node != mpHead) {
        Node_0096a5d8_shaped03_gzcom* cur = node;
        node = node->mpNext;
        Fn0096a49e()->Call04(cur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}
#endif

struct View_009d1e2a_shaped03_gzcom {
    Node_0096a5d8_shaped03_gzcom* mpHead;
    // STUB: 0x009d0747
    Tgt_0096a5d8_shaped03_gzcom* Fn009d0747();
    void Fn009d1e2a();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009d1e2a score 3
void View_009d1e2a_shaped03_gzcom::Fn009d1e2a()
{
    Node_0096a5d8_shaped03_gzcom* node = mpHead->mpNext;
    while (node != mpHead) {
        Node_0096a5d8_shaped03_gzcom* cur = node;
        node = node->mpNext;
        Fn009d0747()->Call04(cur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}
#endif

// ---- 0096bc1a / 0096c3d7
struct View_0096bc1a_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void b00() = 0;
    virtual void b01() = 0;
    virtual void b02() = 0;
    virtual void b03() = 0;
    virtual void b04() = 0;
    virtual void b05() = 0;

    virtual uint32_t Call07() = 0;
    virtual void Call08() = 0;
    virtual void c00() = 0;
    virtual void c01() = 0;
    virtual void c02() = 0;
    virtual void c03() = 0;
    virtual void c04() = 0;
    virtual void c05() = 0;
    virtual void c06() = 0;
    virtual void c07() = 0;
    virtual void c08() = 0;

    virtual void Call12(uint32_t a) = 0;
    uint8_t mPad04[0x1c];
    bool mbDone;
    bool mbBusy;
    bool Slot17();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096bc1a score 2
bool View_0096bc1a_shaped03_gzcom::Slot17()
{
    if (mbDone) {
        return true;
    }
    if (mbBusy) {
        return false;
    }
    Call12(Call07());
    Call08();
    return mbDone;
}
#endif

struct View_0096c3d7_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void b00() = 0;
    virtual void b01() = 0;
    virtual void b02() = 0;
    virtual void b03() = 0;
    virtual void b04() = 0;
    virtual void b05() = 0;

    virtual uint32_t Call07() = 0;
    virtual void Call08() = 0;
    virtual void c00() = 0;
    virtual void c01() = 0;
    virtual void c02() = 0;
    virtual void c03() = 0;
    virtual void c04() = 0;
    virtual void c05() = 0;
    virtual void c06() = 0;
    virtual void c07() = 0;
    virtual void c08() = 0;

    virtual void Call12(uint32_t a) = 0;
    uint8_t mPad04[0x58];
    bool mbDone;
    bool mbBusy;
    bool DataIsValid();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096c3d7 score 2
bool View_0096c3d7_shaped03_gzcom::DataIsValid()
{
    if (mbDone) {
        return true;
    }
    if (mbBusy) {
        return false;
    }
    Call12(Call07());
    Call08();
    return mbDone;
}
#endif

// ---- 00966f31 / 00966f63
struct Ref_00966f31_shaped03_gzcom {
    virtual void a00() = 0;

    virtual void Call01() = 0;
};

struct View_00966f31_shaped03_gzcom {
    uint8_t mPad00[0xd8];
    Ref_00966f31_shaped03_gzcom* mpRef;
    bool Fn00966f31(Ref_00966f31_shaped03_gzcom** out);
};

// FUNCTION: 0x00966f31
bool View_00966f31_shaped03_gzcom::Fn00966f31(Ref_00966f31_shaped03_gzcom** out)
{
    *out = mpRef;
    if (mpRef) {
        mpRef->Call01();
    }
    return mpRef != 0;
}

struct View_00966f63_shaped03_gzcom {
    uint8_t mPad00[0xdc];
    Ref_00966f31_shaped03_gzcom* mpRef;
    bool Fn00966f63(Ref_00966f31_shaped03_gzcom** out);
};

// FUNCTION: 0x00966f63
bool View_00966f63_shaped03_gzcom::Fn00966f63(Ref_00966f31_shaped03_gzcom** out)
{
    *out = mpRef;
    if (mpRef) {
        mpRef->Call01();
    }
    return mpRef != 0;
}

// ---- 0092ec6d / 0092eca3
struct Wait_0092ec6d_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;
    virtual void a02() = 0;

    virtual void Call03(uint32_t a) = 0;
};

struct View_0092ec6d_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void b00() = 0;
    virtual void b01() = 0;
    virtual void b02() = 0;
    virtual void b03() = 0;
    virtual void b04() = 0;
    virtual void b05() = 0;
    virtual void b06() = 0;
    virtual void b07() = 0;
    virtual void b08() = 0;
    virtual void b09() = 0;
    virtual void b0a() = 0;
    virtual void b0b() = 0;
    virtual void b0c() = 0;
    virtual void b0d() = 0;
    virtual void b0e() = 0;
    virtual void b0f() = 0;
    virtual void b10() = 0;
    virtual void b11() = 0;
    virtual void b12() = 0;
    virtual void b13() = 0;

    virtual bool Get15(uint32_t a) = 0;
    virtual bool Get16(uint32_t a) = 0;
    uint8_t mPad04[0xc];
    uint8_t mWait[4];
    bool GetFrontMessageBlock(uint32_t a);
    bool GetBackMessageBlock(uint32_t a);
};

// FUNCTION: 0x0092ec6d
bool View_0092ec6d_shaped03_gzcom::GetFrontMessageBlock(uint32_t a)
{
    while (!Get15(a)) {
        reinterpret_cast<Wait_0092ec6d_shaped03_gzcom*>(mWait)->Call03(1000000);
    }
    return true;
}

// FUNCTION: 0x0092eca3
bool View_0092ec6d_shaped03_gzcom::GetBackMessageBlock(uint32_t a)
{
    while (!Get16(a)) {
        reinterpret_cast<Wait_0092ec6d_shaped03_gzcom*>(mWait)->Call03(1000000);
    }
    return true;
}

// ---- 0096b996 / 0096b9cc
namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct Str_0096b996_shaped03_gzcom {
    uint8_t mPad00[4];
    uint8_t* mpBuf;
    uint8_t mPad08[12];
    // STUB: 0x00408480
    Str_0096b996_shaped03_gzcom(const char* source);
    // STUB: 0x00424380
    Str_0096b996_shaped03_gzcom* Assign(const Str_0096b996_shaped03_gzcom* other);
    ~Str_0096b996_shaped03_gzcom()
    {
        if (mpBuf) {
            _STL::__stl_delete(mpBuf);
        }
    }
};

struct View_0096b996_shaped03_gzcom {
    uint8_t mPad00[4];
    Str_0096b996_shaped03_gzcom mStr;
    bool SetPath(const char* path);
};

// FUNCTION: 0x0096b996
bool View_0096b996_shaped03_gzcom::SetPath(const char* path)
{
    Str_0096b996_shaped03_gzcom local(path);
    mStr.Assign(&local);
    return true;
}

struct View_0096b9cc_shaped03_gzcom {
    uint8_t mPad00[8];
    Str_0096b996_shaped03_gzcom mStr;
    bool Slot03(const char* path);
};

// FUNCTION: 0x0096b9cc
bool View_0096b9cc_shaped03_gzcom::Slot03(const char* path)
{
    Str_0096b996_shaped03_gzcom local(path);
    mStr.Assign(&local);
    return true;
}

// ---- 0092da97 / 00983972
struct Elem_0092da97_shaped03_gzcom {
    // STUB: 0x00473180
    void Destroy();
};

struct View_0092da97_shaped03_gzcom {
    uint8_t mPad00[0x10];
    Elem_0092da97_shaped03_gzcom* mpCur;
    uint8_t* mpFirst;
    uint8_t* mpLast;
    uint8_t** mpNode;
    void Fn0092da97();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0092da97 score 5
void View_0092da97_shaped03_gzcom::Fn0092da97()
{
    if (mpFirst) {
        _STL::__stl_delete(mpFirst);
    }
    --mpNode;
    mpFirst = *mpNode;
    mpLast = mpFirst + 0x80;
    mpCur = reinterpret_cast<Elem_0092da97_shaped03_gzcom*>(mpLast - 8);
    mpCur->Destroy();
}
#endif

struct Elem_00983972_shaped03_gzcom {
    // STUB: 0x009831f0
    void Destroy();
};

struct View_00983972_shaped03_gzcom {
    uint8_t mPad00[0x10];
    Elem_00983972_shaped03_gzcom* mpCur;
    uint8_t* mpFirst;
    uint8_t* mpLast;
    uint8_t** mpNode;
    void Fn00983972();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00983972 score 2
void View_00983972_shaped03_gzcom::Fn00983972()
{
    if (mpFirst) {
        _STL::__stl_delete(mpFirst);
    }
    uint8_t** node = mpNode - 1;
    mpNode = node;
    uint8_t* first = *node;
    mpFirst = first;
    uint8_t* last = first + 0x70;
    mpLast = last;
    mpCur = reinterpret_cast<Elem_00983972_shaped03_gzcom*>(last - 0x1c);
    mpCur->Destroy();
}
#endif

// ---- 009396d8 / 0094048b
struct Key_009396d8_shaped03_gzcom {
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
};

struct View_009396d8_shaped03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad04[0x14];
    uint32_t mnSubVtable;
    Key_009396d8_shaped03_gzcom mKey;
    // STUB: 0x00939237
    void Base();
    View_009396d8_shaped03_gzcom* Fn009396d8(const Key_009396d8_shaped03_gzcom* key);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009396d8 score 1
View_009396d8_shaped03_gzcom* View_009396d8_shaped03_gzcom::Fn009396d8(const Key_009396d8_shaped03_gzcom* key)
{
    Base();
    mnSubVtable = 0xad2620;
    mnVtable = 0xad2898;
    mnSubVtable = 0xad285c;
    mKey.mnA = key->mnA;
    mKey.mnB = key->mnB;
    mKey.mnC = key->mnC;
    return this;
}
#endif

struct View_0094048b_shaped03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad04[0x14];
    uint32_t mnSubVtable;
    Key_009396d8_shaped03_gzcom mKey;
    // STUB: 0x009439cf
    void Base();
    View_0094048b_shaped03_gzcom* Fn0094048b(const Key_009396d8_shaped03_gzcom* key);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0094048b score 1
View_0094048b_shaped03_gzcom* View_0094048b_shaped03_gzcom::Fn0094048b(const Key_009396d8_shaped03_gzcom* key)
{
    Base();
    mnSubVtable = 0xad2620;
    mnVtable = 0xad4378;
    mnSubVtable = 0xad4338;
    mKey.mnA = key->mnA;
    mKey.mnB = key->mnB;
    mKey.mnC = key->mnC;
    return this;
}
#endif

// ---- 009407f4 / 0094082e
struct Str_009407f4_shaped03_gzcom {
    uint8_t mPad00[0x14];
    // STUB: 0x0040ae00
    Str_009407f4_shaped03_gzcom(const void* source);
};

struct Smart_009407f4_shaped03_gzcom {
    Str_009407f4_shaped03_gzcom* mpStr;
    // STUB: 0x0094909a
    void Set(Str_009407f4_shaped03_gzcom* p);
};

struct View_009407f4_shaped03_gzcom {
    uint32_t mnVtable;
    Smart_009407f4_shaped03_gzcom mSmart;
    View_009407f4_shaped03_gzcom* Fn009407f4(const void* source);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009407f4 score 2
View_009407f4_shaped03_gzcom* View_009407f4_shaped03_gzcom::Fn009407f4(const void* source)
{
    mSmart.mpStr = 0;
    mnVtable = 0xad43d8;
    mSmart.Set(new Str_009407f4_shaped03_gzcom(source));
    return this;
}
#endif

struct Str_0094082e_shaped03_gzcom {
    uint8_t mPad00[0x14];
    // STUB: 0x00408480
    Str_0094082e_shaped03_gzcom(const char* source);
};

struct Smart_0094082e_shaped03_gzcom {
    Str_0094082e_shaped03_gzcom* mpStr;
    // STUB: 0x0094909a
    void Set(Str_0094082e_shaped03_gzcom* p);
};

struct View_0094082e_shaped03_gzcom {
    uint32_t mnVtable;
    Smart_0094082e_shaped03_gzcom mSmart;
    View_0094082e_shaped03_gzcom* Fn0094082e(const char* source);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0094082e score 2
View_0094082e_shaped03_gzcom* View_0094082e_shaped03_gzcom::Fn0094082e(const char* source)
{
    mSmart.mpStr = 0;
    mnVtable = 0xad43d8;
    mSmart.Set(new Str_0094082e_shaped03_gzcom(source));
    return this;
}
#endif

// ---- 0094448e / 009da5bd
// STUB: 0x00944462
void* Fn00944462_shaped03_gzcom();

struct View_0094448e_shaped03_gzcom {
    uint32_t mnVtable;
    uint32_t mnVtable2;
    // STUB: 0x0090e18d
    void Base();
    // STUB: 0x0090e133
    void AddCls(uint32_t id, void* fn);
    View_0094448e_shaped03_gzcom* Fn0094448e();
};

// FUNCTION: 0x0094448e
View_0094448e_shaped03_gzcom* View_0094448e_shaped03_gzcom::Fn0094448e()
{
    Base();
    mnVtable = 0xad46c8;
    mnVtable2 = 0xad469c;
    AddCls(0xba2e7953, ClsPtr_shaped03_gzcom(Fn00944462_shaped03_gzcom));
    AddCls(0xba2e7954, ClsPtr_shaped03_gzcom(reinterpret_cast<void* (*)()>(Fn00944478)));
    return this;
}

// STUB: 0x009da575
void* Fn009da575_shaped03_gzcom();
// STUB: 0x009da599
void* Fn009da599_shaped03_gzcom();

struct View_009da5bd_shaped03_gzcom {
    uint32_t mnVtable;
    uint32_t mnVtable2;
    // STUB: 0x0090e18d
    void Base();
    // STUB: 0x0090e133
    void AddCls(uint32_t id, void* fn);
    View_009da5bd_shaped03_gzcom* Fn009da5bd();
};

// FUNCTION: 0x009da5bd
View_009da5bd_shaped03_gzcom* View_009da5bd_shaped03_gzcom::Fn009da5bd()
{
    Base();
    mnVtable = 0xae4628;
    mnVtable2 = 0xae45fc;
    AddCls(0x84174448, ClsPtr_shaped03_gzcom(Fn009da575_shaped03_gzcom));
    AddCls(0x2ac4516b, ClsPtr_shaped03_gzcom(Fn009da599_shaped03_gzcom));
    return this;
}

// ---- 0092fbac / 0092fbed
struct Lock_0092fbac_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;

    virtual void Call02() = 0;
};

struct Guard_0092fbac_shaped03_gzcom {
    uint32_t mn00;
    Lock_0092fbac_shaped03_gzcom* mpLock;
    // STUB: 0x0048c9f0
    Guard_0092fbac_shaped03_gzcom(void* lock);
    ~Guard_0092fbac_shaped03_gzcom() { mpLock->Call02(); }
};

struct Node_0092fbac_shaped03_gzcom {
    Node_0092fbac_shaped03_gzcom* mpNext;
};

struct Sig_0092fbac_shaped03_gzcom {
    virtual void a00() = 0;

    virtual void Call01() = 0;
};

struct List_0092fbac_shaped03_gzcom {
    Node_0092fbac_shaped03_gzcom* mpHead;
    // STUB: 0x0092fa8f
    void Push(uint32_t x);
};

struct View_0092fbac_shaped03_gzcom {
    uint8_t mPad00[4];
    List_0092fbac_shaped03_gzcom mList;
    uint8_t mLock[8];
    uint8_t mSig[4];
    void PushBack(uint32_t a);
};

// FUNCTION: 0x0092fbac
void View_0092fbac_shaped03_gzcom::PushBack(uint32_t a)
{
    Guard_0092fbac_shaped03_gzcom guard(mLock);
    bool bEmpty = mList.mpHead->mpNext == mList.mpHead;
    mList.Push(a);
    if (bEmpty) {
        reinterpret_cast<Sig_0092fbac_shaped03_gzcom*>(mSig)->Call01();
    }
}

struct List_0092fbed_shaped03_gzcom {
    Node_0092fbac_shaped03_gzcom* mpHead;
    // STUB: 0x0092fa73
    void Push(uint32_t x);
};

struct View_0092fbed_shaped03_gzcom {
    uint8_t mPad00[4];
    List_0092fbed_shaped03_gzcom mList;
    uint8_t mLock[8];
    uint8_t mSig[4];
    void PushFront(uint32_t a);
};

// FUNCTION: 0x0092fbed
void View_0092fbed_shaped03_gzcom::PushFront(uint32_t a)
{
    Guard_0092fbac_shaped03_gzcom guard(mLock);
    bool bEmpty = mList.mpHead->mpNext == mList.mpHead;
    mList.Push(a);
    if (bEmpty) {
        reinterpret_cast<Sig_0092fbac_shaped03_gzcom*>(mSig)->Call01();
    }
}

// ---- 0094bc69 / 0094bcaa
struct Ref_0094bc69_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;

    virtual void Call02() = 0;
    virtual uint32_t Call03() = 0;
};

struct Obj_0094bc69_shaped03_gzcom {
    virtual bool Query(uint32_t id, Ref_0094bc69_shaped03_gzcom** out) = 0;
};

struct View_0094bc69_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void b00() = 0;
    virtual void b01() = 0;
    virtual void b02() = 0;
    virtual void b03() = 0;

    virtual Obj_0094bc69_shaped03_gzcom* Get05(uint32_t a) = 0;
    virtual Obj_0094bc69_shaped03_gzcom* Get06(uint32_t a) = 0;
    uint32_t Slot07(uint32_t a);
    uint32_t Slot08(uint32_t a);
};

// FUNCTION: 0x0094bc69
uint32_t View_0094bc69_shaped03_gzcom::Slot07(uint32_t a)
{
    uint32_t r = 0;
    Obj_0094bc69_shaped03_gzcom* o = Get05(a);
    if (o) {
        Ref_0094bc69_shaped03_gzcom* tmp = 0;
        if (o->Query(0x9a4527cb, &tmp)) {
            r = tmp->Call03();
            tmp->Call02();
        }
    }
    return r;
}

// FUNCTION: 0x0094bcaa
uint32_t View_0094bc69_shaped03_gzcom::Slot08(uint32_t a)
{
    uint32_t r = 0;
    Obj_0094bc69_shaped03_gzcom* o = Get06(a);
    if (o) {
        Ref_0094bc69_shaped03_gzcom* tmp = 0;
        if (o->Query(0x9a4527cb, &tmp)) {
            r = tmp->Call03();
            tmp->Call02();
        }
    }
    return r;
}

// ---- 0095bddf / 0095be2e
namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct Str_0095bddf_shaped03_gzcom {
    uint32_t mnVtable;
    uint8_t* mpBuf;
    uint8_t mPad08[12];
    // STUB: 0x00578390
    Str_0095bddf_shaped03_gzcom();
    ~Str_0095bddf_shaped03_gzcom()
    {
        mnVtable = 0xa80810;
        if (mpBuf) {
            _STL::__stl_delete(mpBuf);
        }
    }
};

struct Text_0095bddf_shaped03_gzcom {
    uint8_t mPad00[4];
    uint8_t mString[4];
    // STUB: 0x00408c20
    void Append(uint8_t* const* s);
};

struct Name_0095bddf_shaped03_gzcom {
    uint8_t mPad00[4];
    const char* mpChars;
};

// STUB: 0x0090f574
Str_0095bddf_shaped03_gzcom* Sprintf_shaped03_gzcom(Str_0095bddf_shaped03_gzcom* self, const char* format, ...);

#ifdef OB_DRAFTS
// CLOSE: 0x0095bddf score 3
void script_tag_int(Text_0095bddf_shaped03_gzcom* out, Name_0095bddf_shaped03_gzcom* name, int32_t value)
{
    Str_0095bddf_shaped03_gzcom local;
    Sprintf_shaped03_gzcom(&local, "%s=%d ", name->mpChars, value);
    out->Append(&local.mpBuf);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0095be2e score 3
void script_tag_hex(Text_0095bddf_shaped03_gzcom* out, Name_0095bddf_shaped03_gzcom* name, uint32_t value)
{
    Str_0095bddf_shaped03_gzcom local;
    Sprintf_shaped03_gzcom(&local, "%s=0x%08x ", name->mpChars, value);
    out->Append(&local.mpBuf);
}
#endif

// ---- 00944a77 / 0094c05e
struct Heap_00944a77_shaped03_gzcom {
    uint32_t mnVtable;
    uint32_t mn04;
};

struct Alloc_00944a77_shaped03_gzcom {
    virtual void a00() = 0;

    virtual void Call01() = 0;
    virtual void Call02() = 0;
    virtual uint8_t* Call03(uint32_t n) = 0;
};

struct View_00944a77_shaped03_gzcom {
    uint8_t* mpBegin;
    uint8_t* mpCur;
    uint8_t* mpEnd;
    uint32_t mn0c;
    Alloc_00944a77_shaped03_gzcom* mpAlloc;
    uint32_t mn14;
    View_00944a77_shaped03_gzcom* Fn00944a77();
    View_00944a77_shaped03_gzcom* Fn0094c05e();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00944a77 score 5
View_00944a77_shaped03_gzcom* View_00944a77_shaped03_gzcom::Fn00944a77()
{
    mpBegin = 0;
    mpCur = 0;
    mpEnd = 0;
    mn0c = 0;
    mn14 = 0;
    Heap_00944a77_shaped03_gzcom* h = new Heap_00944a77_shaped03_gzcom;
    Heap_00944a77_shaped03_gzcom* q = 0;
    if (h) {
        h->mnVtable = 0xad1dc0;
        h->mn04 = 0;
        q = h;
    }
    mpAlloc = reinterpret_cast<Alloc_00944a77_shaped03_gzcom*>(q);
    mpAlloc->Call01();
    uint8_t* p = mpAlloc->Call03(0x40);
    mpBegin = p;
    mpCur = p;
    mpEnd = p + 0x40;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0094c05e score 5
View_00944a77_shaped03_gzcom* View_00944a77_shaped03_gzcom::Fn0094c05e()
{
    mpBegin = 0;
    mpCur = 0;
    mpEnd = 0;
    mn0c = 0;
    mn14 = 0;
    Heap_00944a77_shaped03_gzcom* h = new Heap_00944a77_shaped03_gzcom;
    Heap_00944a77_shaped03_gzcom* q = 0;
    if (h) {
        h->mnVtable = 0xad1dc0;
        h->mn04 = 0;
        q = h;
    }
    mpAlloc = reinterpret_cast<Alloc_00944a77_shaped03_gzcom*>(q);
    mpAlloc->Call01();
    uint8_t* p = mpAlloc->Call03(0x20);
    mpBegin = p;
    mpCur = p;
    mpEnd = p + 0x20;
    return this;
}
#endif

// ---- 0093076e / 009307b5
struct Sub_0093076e_shaped03_gzcom {
    uint8_t mPad00[0xc];
    // STUB: 0x00408050
    void Init();
};

struct Sub2_0093076e_shaped03_gzcom {
    uint8_t mPad00[0xc];
    // STUB: 0x00621810
    void Init();
};

struct Sub3_0093076e_shaped03_gzcom {
    uint8_t mPad00[0x14];
    // STUB: 0x00578390
    void Init();
};

struct View_0093076e_shaped03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad04[0x7c];
    uint32_t mn80;
    uint8_t mb84;
    uint8_t mPad85[3];
    Sub_0093076e_shaped03_gzcom mSub88;
    Sub2_0093076e_shaped03_gzcom mSub94;
    Sub3_0093076e_shaped03_gzcom mSuba0;
    // STUB: 0x00918c00
    void Base(uint32_t a);
    View_0093076e_shaped03_gzcom* Fn0093076e(uint32_t a);
};

// FUNCTION: 0x0093076e
View_0093076e_shaped03_gzcom* View_0093076e_shaped03_gzcom::Fn0093076e(uint32_t a)
{
    Base(a);
    mn80 = 0;
    mnVtable = 0xad1e58;
    mb84 = 0;
    mSub88.Init();
    mSub94.Init();
    mSuba0.Init();
    return this;
}

struct View_009307b5_shaped03_gzcom {
    uint32_t mnVtable;
    uint8_t mPad04[0x7c];
    uint32_t mn80;
    uint8_t mb84;
    uint8_t mPad85[3];
    Sub_0093076e_shaped03_gzcom mSub88;
    Sub2_0093076e_shaped03_gzcom mSub94;
    Sub3_0093076e_shaped03_gzcom mSuba0;
    // STUB: 0x00919a60
    void Base(uint32_t a);
    View_009307b5_shaped03_gzcom* Fn009307b5(uint32_t a);
};

// FUNCTION: 0x009307b5
View_009307b5_shaped03_gzcom* View_009307b5_shaped03_gzcom::Fn009307b5(uint32_t a)
{
    Base(a);
    mn80 = 0;
    mnVtable = 0xad1e58;
    mb84 = 0;
    mSub88.Init();
    mSub94.Init();
    mSuba0.Init();
    return this;
}

// ---- 00975495 / 009754e8
struct Lock_00975495_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;

    virtual void Call02() = 0;
};

struct Guard_00975495_shaped03_gzcom {
    uint32_t mn00;
    Lock_00975495_shaped03_gzcom* mpLock;
    // STUB: 0x0048c9f0
    Guard_00975495_shaped03_gzcom(void* lock);
    ~Guard_00975495_shaped03_gzcom() { mpLock->Call02(); }
};

struct Res_00975495_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void a01() = 0;

    virtual void Call02() = 0;
};

struct Arg_00975495_shaped03_gzcom {
    virtual bool Query(uint32_t id, Res_00975495_shaped03_gzcom** out) = 0;
};

struct View_00975495_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void b00() = 0;
    virtual void b01() = 0;
    virtual void b02() = 0;
    virtual void b03() = 0;
    virtual void b04() = 0;
    virtual void b05() = 0;
    virtual void b06() = 0;
    virtual void b07() = 0;
    virtual void b08() = 0;

    virtual bool Call0a(uint32_t a, Res_00975495_shaped03_gzcom* r) = 0;
    virtual bool Call0b(uint32_t a, Res_00975495_shaped03_gzcom* r) = 0;
    uint8_t mPad04[4];
    uint8_t mLock[8];
    bool Read(uint32_t a, Arg_00975495_shaped03_gzcom* b);
    bool Write(uint32_t a, Arg_00975495_shaped03_gzcom* b);
};

// FUNCTION: 0x00975495
bool View_00975495_shaped03_gzcom::Read(uint32_t a, Arg_00975495_shaped03_gzcom* b)
{
    Guard_00975495_shaped03_gzcom guard(mLock);
    Res_00975495_shaped03_gzcom* res;
    bool ok = false;
    if (b->Query(0xc56b8f08, &res)) {
        ok = Call0a(a, res);
        res->Call02();
    }
    return ok;
}

// FUNCTION: 0x009754e8
bool View_00975495_shaped03_gzcom::Write(uint32_t a, Arg_00975495_shaped03_gzcom* b)
{
    Guard_00975495_shaped03_gzcom guard(mLock);
    Res_00975495_shaped03_gzcom* res;
    bool ok = false;
    if (b->Query(0xc56b8f08, &res)) {
        ok = Call0b(a, res);
        res->Call02();
    }
    return ok;
}

// ---- 0095be7d / 0095becf / 0095bf79 / 0095c028
#ifdef OB_DRAFTS
// CLOSE: 0x0095be7d score 3
void Fn0095be7d(Text_0095bddf_shaped03_gzcom* out, Name_0095bddf_shaped03_gzcom* name, uint32_t a, uint32_t b)
{
    Str_0095bddf_shaped03_gzcom local;
    Sprintf_shaped03_gzcom(&local, "%s={%08x,%08x} ", name->mpChars, a, b);
    out->Append(&local.mpBuf);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0095becf score 3
void script_tag_pair(Text_0095bddf_shaped03_gzcom* out, Name_0095bddf_shaped03_gzcom* name, int32_t a, int32_t b)
{
    Str_0095bddf_shaped03_gzcom local;
    Sprintf_shaped03_gzcom(&local, "%s=(%d,%d) ", name->mpChars, a, b);
    out->Append(&local.mpBuf);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0095bf79 score 3
void Fn0095bf79(Text_0095bddf_shaped03_gzcom* out, Name_0095bddf_shaped03_gzcom* name, Name_0095bddf_shaped03_gzcom* value)
{
    Str_0095bddf_shaped03_gzcom local;
    Sprintf_shaped03_gzcom(&local, "%s=%s ", name->mpChars, value->mpChars);
    out->Append(&local.mpBuf);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0095c028 score 3
void script_tag_quoted(Text_0095bddf_shaped03_gzcom* out, Name_0095bddf_shaped03_gzcom* name, Name_0095bddf_shaped03_gzcom* value)
{
    Str_0095bddf_shaped03_gzcom local;
    Sprintf_shaped03_gzcom(&local, "%s=\"%s\" ", name->mpChars, value->mpChars);
    out->Append(&local.mpBuf);
}
#endif

// ---- 0093294a / 009329ae
struct Held_0093294a_shaped03_gzcom {
    virtual void a00() = 0;

    virtual void Call01() = 0;
    virtual void Call02() = 0;
};

struct View_0093294a_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void b00() = 0;
    virtual void b01() = 0;
    virtual void b02() = 0;
    virtual void b03() = 0;

    virtual void Call05(uint32_t a, uint32_t b) = 0;
    virtual void Call06(uint32_t a, uint32_t b) = 0;
    virtual void Call07() = 0;
    uint8_t mPad04[0xc];
    uint32_t mnValue;
    uint8_t mPad14[4];
    bool mbA;
    bool mbB;
    uint8_t mPad1a[10];
    Held_0093294a_shaped03_gzcom* mpHeld;
    bool Slot01(uint32_t a);
};

// FUNCTION: 0x0093294a
bool View_0093294a_shaped03_gzcom::Slot01(uint32_t a)
{
    Held_0093294a_shaped03_gzcom* p = mpHeld;
    if (p) {
        p->Call01();
    }
    mnValue = a;
    if (mbA) {
        Call07();
        if (mbB) {
            Call06(0, 0);
        } else {
            Call05(0, 0);
        }
    }
    if (p) {
        if (mpHeld) {
            p->Call02();
        }
        mpHeld = p;
    }
    return true;
}

struct View_009329ae_shaped03_gzcom {
    virtual void a00() = 0;
    virtual void b00() = 0;
    virtual void b01() = 0;
    virtual void b02() = 0;
    virtual void b03() = 0;

    virtual void Call05(uint32_t a, uint32_t b) = 0;
    virtual void Call06(uint32_t a, uint32_t b) = 0;
    virtual void Call07() = 0;
    uint8_t mPad04[0xc];
    uint32_t mnValue10;
    uint32_t mnValue;
    bool mbA;
    bool mbB;
    uint8_t mPad1a[10];
    Held_0093294a_shaped03_gzcom* mpHeld;
    bool Slot03(uint32_t a);
};

// FUNCTION: 0x009329ae
bool View_009329ae_shaped03_gzcom::Slot03(uint32_t a)
{
    Held_0093294a_shaped03_gzcom* p = mpHeld;
    if (p) {
        p->Call01();
    }
    mnValue = a;
    if (mbA) {
        Call07();
        if (mbB) {
            Call06(0, 0);
        } else {
            Call05(0, 0);
        }
    }
    if (p) {
        if (mpHeld) {
            p->Call02();
        }
        mpHeld = p;
    }
    return true;
}

// ---- 0094aff6
// STUB: 0x0094af64
void* Fn0094af64_shaped03_gzcom();
// STUB: 0x0094af7a
void* Fn0094af7a_shaped03_gzcom();
// STUB: 0x0094af90
void* Fn0094af90_shaped03_gzcom();
// STUB: 0x0094afa6
void* Fn0094afa6_shaped03_gzcom();

struct View_0094aff6_shaped03_gzcom {
    uint32_t mnVtable;
    uint32_t mnVtable2;
    // STUB: 0x0090e18d
    void Base();
    // STUB: 0x0090e133
    void AddCls(uint32_t id, ClsMaker_shaped03_gzcom fn);
    View_0094aff6_shaped03_gzcom* Fn0094aff6();
};

// FUNCTION: 0x0094aff6
View_0094aff6_shaped03_gzcom* View_0094aff6_shaped03_gzcom::Fn0094aff6()
{
    Base();
    mnVtable = 0xad4fe0;
    mnVtable2 = 0xad4fb4;
    AddCls(0xfa3562fb, Fn0094af64_shaped03_gzcom);
    AddCls(0x5a354595, Fn0094af7a_shaped03_gzcom);
    AddCls(0xfa450242, Fn0094af90_shaped03_gzcom);
    AddCls(0x478d1e6f, Fn0094afa6_shaped03_gzcom);
    return this;
}
