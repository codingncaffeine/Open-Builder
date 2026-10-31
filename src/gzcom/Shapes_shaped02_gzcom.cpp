// Shape families of packet shaped02_gzcom (pairs), written by hand.
#include "common/compiler.h"
#include "common/types.h"

#ifdef _MSC_VER
#define SHAPED02_API extern "C" __declspec(dllimport)
#else
#define SHAPED02_API extern "C"
#endif
SHAPED02_API void* OB_STDCALL GetProcessHeap();
SHAPED02_API void* OB_STDCALL HeapAlloc(void* heap, uint32_t flags, uint32_t size);
SHAPED02_API int32_t OB_STDCALL HeapFree(void* heap, uint32_t flags, void* mem);
SHAPED02_API uint32_t OB_STDCALL SuspendThread(void* handle);
SHAPED02_API uint32_t OB_STDCALL ResumeThread(void* handle);

// ---- pair 00920a2a / 00930b2e: a field of the object the first field points at
struct Inner_shaped02_a {
    uint32_t d[8];
};

struct View_00920a2a_shaped02_gzcom {
    uint32_t pad0;
    Inner_shaped02_a* mpInner;
    uint32_t Fn00920a2a();
};

// FUNCTION: 0x00920a2a
uint32_t View_00920a2a_shaped02_gzcom::Fn00920a2a()
{
    return mpInner->d[1];
}

struct View_00930b2e_shaped02_gzcom {
    uint32_t pad0;
    Inner_shaped02_a* mpInner;
    uint32_t Fn00930b2e();
};

// FUNCTION: 0x00930b2e
uint32_t View_00930b2e_shaped02_gzcom::Fn00930b2e()
{
    return mpInner->d[6];
}

// ---- pair 0092b33f / 0092b348: set a flag, return false
struct View_0092b33f_shaped02_gzcom {
    uint8_t pad[0x10];
    bool mbFlag;
    bool Fn0092b33f(uint32_t /*a*/);
};

// FUNCTION: 0x0092b33f
bool View_0092b33f_shaped02_gzcom::Fn0092b33f(uint32_t /*a*/)
{
    mbFlag = true;
    return false;
}

struct View_0092b348_shaped02_gzcom {
    uint8_t pad[0x10];
    bool mbFlag;
    bool Fn0092b348(uint32_t /*a*/, uint32_t /*b*/);
};

// FUNCTION: 0x0092b348
bool View_0092b348_shaped02_gzcom::Fn0092b348(uint32_t /*a*/, uint32_t /*b*/)
{
    mbFlag = true;
    return false;
}

// ---- pair 0090daa3 / 00974c62: call a method of an embedded member, return true
struct Sub_9677e6_shaped02_gzcom {
    // STUB: 0x009677e6
    void Fn009677e6();
};

struct View_0090daa3_shaped02_gzcom {
    uint8_t pad[4];
    Sub_9677e6_shaped02_gzcom mSub;
    bool Fn0090daa3();
};

// FUNCTION: 0x0090daa3
bool View_0090daa3_shaped02_gzcom::Fn0090daa3()
{
    mSub.Fn009677e6();
    return true;
}

struct Sub_974a78_shaped02_gzcom {
    // STUB: 0x00974a78
    void Fn00974a78();
};

struct View_00974c62_shaped02_gzcom {
    uint8_t pad[0x18];
    Sub_974a78_shaped02_gzcom mSub;
    bool Fn00974c62();
};

// FUNCTION: 0x00974c62
bool View_00974c62_shaped02_gzcom::Fn00974c62()
{
    mSub.Fn00974a78();
    return true;
}

// ---- pair 0090cf54 / 0090cf63: a method of a global object, argument passed on
struct Pool_b62698_shaped02_gzcom {
    // STUB: 0x005e55b0
    void Fn005e55b0(void* p);
    // STUB: 0x005051c0
    void Fn005051c0(void* p);
};

// GLOBAL: 0x00b62698
extern Pool_b62698_shaped02_gzcom gb62698;

// FUNCTION: 0x0090cf54
void Fn0090cf54(void* p)
{
    gb62698.Fn005e55b0(p);
}

// FUNCTION: 0x0090cf63
void Fn0090cf63(void* p)
{
    gb62698.Fn005051c0(p);
}

// ---- pair 0092b294 / 0092b309: call a slot of the argument with this
struct Iface_0092b294_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Call(void* pSelf) = 0;
};

struct View_0092b294_shaped02_gzcom {
    void Fn0092b294(Iface_0092b294_shaped02_gzcom* pOther);
};

// FUNCTION: 0x0092b294
void View_0092b294_shaped02_gzcom::Fn0092b294(Iface_0092b294_shaped02_gzcom* pOther)
{
    pOther->Call(this);
}

struct Iface_0092b309_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Call(void* pSelf) = 0;
};

struct View_0092b309_shaped02_gzcom {
    void Fn0092b309(Iface_0092b309_shaped02_gzcom* pOther);
};

// FUNCTION: 0x0092b309
void View_0092b309_shaped02_gzcom::Fn0092b309(Iface_0092b309_shaped02_gzcom* pOther)
{
    pOther->Call(this);
}

// ---- pair 0090db0b / 00967b1a: count the nodes of a circular list
struct Node_shaped02_gzcom {
    Node_shaped02_gzcom* mpNext;
};

struct View_0090db0b_shaped02_gzcom {
    uint32_t pad0;
    Node_shaped02_gzcom* mpHead;
    uint32_t Fn0090db0b();
};

// FUNCTION: 0x0090db0b
uint32_t View_0090db0b_shaped02_gzcom::Fn0090db0b()
{
    Node_shaped02_gzcom* pHead = mpHead;
    uint32_t n = 0;
    for (Node_shaped02_gzcom* p = pHead->mpNext; p != pHead; p = p->mpNext) {
        ++n;
    }
    return n;
}

struct View_00967b1a_shaped02_gzcom {
    uint8_t pad[0x90];
    Node_shaped02_gzcom* mpHead;
    uint32_t Fn00967b1a();
};

// FUNCTION: 0x00967b1a
uint32_t View_00967b1a_shaped02_gzcom::Fn00967b1a()
{
    Node_shaped02_gzcom* pHead = mpHead;
    uint32_t n = 0;
    for (Node_shaped02_gzcom* p = pHead->mpNext; p != pHead; p = p->mpNext) {
        ++n;
    }
    return n;
}

// ---- pair 009205b7 / 009205d7: suspend / resume the thread handle two levels down
struct Thread_shaped02_gzcom {
    uint32_t pad0;
    void* mpHandle;
};

struct View_009205b7_shaped02_gzcom {
    uint32_t pad0;
    Thread_shaped02_gzcom* mpThread;
    void Fn009205b7();
};

// FUNCTION: 0x009205b7
void View_009205b7_shaped02_gzcom::Fn009205b7()
{
    void* h = mpThread->mpHandle;
    if (h) {
        SuspendThread(h);
    }
}

struct View_009205d7_shaped02_gzcom {
    uint32_t pad0;
    Thread_shaped02_gzcom* mpThread;
    void Fn009205d7();
};

// FUNCTION: 0x009205d7
void View_009205d7_shaped02_gzcom::Fn009205d7()
{
    void* h = mpThread->mpHandle;
    if (h) {
        ResumeThread(h);
    }
}

// ---- pair 0090fc5b / 00910991: string to double
// STUB: 0x009f0eae
double Fn009f0eae(const char* s, char** pEnd);
// STUB: 0x00910426
double Fn00910426(const char* s, char** pEnd);

// FUNCTION: 0x0090fc5b
double Fn0090fc5b(const char* s)
{
    char* pEnd;
    return Fn009f0eae(s, &pEnd);
}

// FUNCTION: 0x00910991
double Fn00910991(const char* s)
{
    char* pEnd;
    return Fn00910426(s, &pEnd);
}

// ---- pair 0090cf72 / 0090cf86: process heap alloc / free
// FUNCTION: 0x0090cf72
void* Fn0090cf72(uint32_t nSize)
{
    return HeapAlloc(GetProcessHeap(), 0, nSize);
}

// FUNCTION: 0x0090cf86
int32_t Fn0090cf86(void* p)
{
    return HeapFree(GetProcessHeap(), 0, p);
}

// ---- pair 0090d267 / 0090d27c: call a method, then release the pointer in the first field
// STUB: 0x0090cf86
void Fn0090cf86Free_shaped02(void* p, uint32_t flag);

struct View_0090d267_shaped02_gzcom {
    void* mpMem;
    // STUB: 0x0090d164
    void Fn0090d164();
    void Fn0090d267();
};

// FUNCTION: 0x0090d267
void View_0090d267_shaped02_gzcom::Fn0090d267()
{
    Fn0090d164();
    Fn0090cf86Free_shaped02(mpMem, 1);
}

struct View_0090d27c_shaped02_gzcom {
    void* mpMem;
    // STUB: 0x0090d1b9
    void Fn0090d1b9();
    void Fn0090d27c();
};

// FUNCTION: 0x0090d27c
void View_0090d27c_shaped02_gzcom::Fn0090d27c()
{
    Fn0090d1b9();
    Fn0090cf86Free_shaped02(mpMem, 1);
}

// ---- pair 009136ca / 00913a14: a + F(b - a)
// STUB: 0x009136b1
uint32_t OB_STDCALL Fn009136b1(uint32_t n);
// STUB: 0x00913a06
uint32_t OB_STDCALL Fn00913a06(uint32_t n);

// FUNCTION: 0x009136ca
uint32_t OB_STDCALL Fn009136ca(uint32_t a, uint32_t b)
{
    return Fn009136b1(b - a) + a;
}

// FUNCTION: 0x00913a14
uint32_t OB_STDCALL Fn00913a14(uint32_t a, uint32_t b)
{
    return Fn00913a06(b - a) + a;
}

// ---- pair 0090c654 / 0090c815: release one reference, destroy at the last
struct View_0090c654_shaped02_gzcom {
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
    virtual void Destroy() = 0;
    uint32_t pad4[4];
    uint32_t mnRefs;
    uint32_t Fn0090c654();
};

// FUNCTION: 0x0090c654
uint32_t View_0090c654_shaped02_gzcom::Fn0090c654()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy();
    return 0;
}

struct View_0090c815_shaped02_gzcom {
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
    virtual void Destroy() = 0;
    uint32_t pad4[4];
    uint32_t mnRefs;
    uint32_t Fn0090c815();
};

// FUNCTION: 0x0090c815
uint32_t View_0090c815_shaped02_gzcom::Fn0090c815()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy();
    return 0;
}

// ---- pair 0090d468 / 0090d47e: set the vtable, call a method, tail-call another
struct View_0090d468_shaped02_gzcom {
    uint32_t mnVtbl;
    // STUB: 0x0090d218
    void Fn0090d218();
    // STUB: 0x0090d40a
    void Fn0090d40a();
    void Fn0090d468();
};

// FUNCTION: 0x0090d468
void View_0090d468_shaped02_gzcom::Fn0090d468()
{
    mnVtbl = 0x00ace614;
    Fn0090d218();
    Fn0090d40a();
}

struct View_0090d47e_shaped02_gzcom {
    uint32_t mnVtbl;
    // STUB: 0x0090d218
    void Fn0090d218();
    // STUB: 0x0090d44e
    void Fn0090d44e();
    void Fn0090d47e();
};

// FUNCTION: 0x0090d47e
void View_0090d47e_shaped02_gzcom::Fn0090d47e()
{
    mnVtbl = 0x00ace61c;
    Fn0090d218();
    Fn0090d44e();
}

// ---- pair 00913761 / 00913a46: a random double in [lo, hi)
struct View_00913761_shaped02_gzcom {
    // STUB: 0x0091372e
    double RandomDoubleUniform();
    double Fn00913761(double lo, double hi);
};

// FUNCTION: 0x00913761
double View_00913761_shaped02_gzcom::Fn00913761(double lo, double hi)
{
    return lo + (hi - lo) * RandomDoubleUniform();
}

struct View_00913a46_shaped02_gzcom {
    // STUB: 0x00913a29
    double RandomDoubleUniform();
    double Fn00913a46(double lo, double hi);
};

// FUNCTION: 0x00913a46
double View_00913a46_shaped02_gzcom::Fn00913a46(double lo, double hi)
{
    return lo + (hi - lo) * RandomDoubleUniform();
}

// ---- pair 00913394 / 00995d7c: compare a key with the argument's key (slot 4), less-than
struct Key_00913394_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual uint32_t GetKey() = 0;
};

struct View_00913394_shaped02_gzcom {
    uint8_t pad[0xc];
    uint32_t mnKey;
    uint32_t Fn00913394(Key_00913394_shaped02_gzcom* pOther);
};

// FUNCTION: 0x00913394
uint32_t View_00913394_shaped02_gzcom::Fn00913394(Key_00913394_shaped02_gzcom* pOther)
{
    return mnKey < pOther->GetKey();
}

struct View_00995d7c_shaped02_gzcom {
    uint8_t pad[8];
    uint32_t mnKey;
    uint32_t Fn00995d7c(Key_00913394_shaped02_gzcom* pOther);
};

// FUNCTION: 0x00995d7c
uint32_t View_00995d7c_shaped02_gzcom::Fn00995d7c(Key_00913394_shaped02_gzcom* pOther)
{
    return mnKey < pOther->GetKey();
}

// ---- pair 0091337a / 00995d62: the same, equality
struct View_0091337a_shaped02_gzcom {
    uint8_t pad[0xc];
    uint32_t mnKey;
    bool Fn0091337a(Key_00913394_shaped02_gzcom* pOther);
};

// FUNCTION: 0x0091337a
bool View_0091337a_shaped02_gzcom::Fn0091337a(Key_00913394_shaped02_gzcom* pOther)
{
    return mnKey == pOther->GetKey();
}

struct View_00995d62_shaped02_gzcom {
    uint8_t pad[8];
    uint32_t mnKey;
    bool Fn00995d62(Key_00913394_shaped02_gzcom* pOther);
};

// FUNCTION: 0x00995d62
bool View_00995d62_shaped02_gzcom::Fn00995d62(Key_00913394_shaped02_gzcom* pOther)
{
    return mnKey == pOther->GetKey();
}

// ---- pair 00913438 / 00913484: if a check slot says yes, forward to slot 0 of a member
struct Target_00913438_shaped02_gzcom {
    virtual bool Get(uint32_t a, uint32_t b) = 0;
};

struct View_00913438_shaped02_gzcom {
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
    virtual bool Check() = 0;
    uint8_t pad[0x1c];
    Target_00913438_shaped02_gzcom* mpTarget;
    bool Fn00913438(uint32_t a, uint32_t b);
};

// FUNCTION: 0x00913438
bool View_00913438_shaped02_gzcom::Fn00913438(uint32_t a, uint32_t b)
{
    if (Check()) {
        return mpTarget->Get(a, b);
    }
    return false;
}

struct View_00913484_shaped02_gzcom {
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
    virtual bool Check() = 0;
    uint8_t pad[0x24];
    Target_00913438_shaped02_gzcom* mpTarget;
    bool Fn00913484(uint32_t a, uint32_t b);
};

// FUNCTION: 0x00913484
bool View_00913484_shaped02_gzcom::Fn00913484(uint32_t a, uint32_t b)
{
    if (Check()) {
        return mpTarget->Get(a, b);
    }
    return false;
}

// ---- pair 0092bbde / 0092bc14: constructor setting a vtable, a flag and two zeroed fields
struct View_0092bbde_shaped02_gzcom {
    uint32_t mnVtbl;
    uint32_t mnA;
    bool mbFlag;
    uint32_t mnB;
    View_0092bbde_shaped02_gzcom* Fn0092bbde(bool b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0092bbde score 4
View_0092bbde_shaped02_gzcom* View_0092bbde_shaped02_gzcom::Fn0092bbde(bool b)
{
    bool bv = b;
    mnA = 0;
    mnVtbl = 0x00ad1818;
    mnB = 0;
    mbFlag = bv;
    return this;
}
#endif

struct View_0092bc14_shaped02_gzcom {
    uint32_t mnVtbl;
    uint32_t mnA;
    bool mbFlag;
    uint32_t mnB;
    View_0092bc14_shaped02_gzcom* Fn0092bc14(bool b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0092bc14 score 4
View_0092bc14_shaped02_gzcom* View_0092bc14_shaped02_gzcom::Fn0092bc14(bool b)
{
    bool bv = b;
    mnA = 0;
    mnVtbl = 0x00ad1878;
    mnB = 0;
    mbFlag = bv;
    return this;
}
#endif

// ---- pair 0091b2f7 / 0094d163: destroy two embedded strings, then the base
struct Str_shaped02_gzcom {
    // STUB: 0x00414250
    void Dtor();
};

struct View_0091b2f7_shaped02_gzcom {
    uint8_t pad8[8];
    Str_shaped02_gzcom mS2;
    uint8_t pad9[0x13];
    Str_shaped02_gzcom mS1;
    // STUB: 0x0091af4a
    void Fn0091af4a();
    void Fn0091b2f7();
};

// FUNCTION: 0x0091b2f7
void View_0091b2f7_shaped02_gzcom::Fn0091b2f7()
{
    mS1.Dtor();
    mS2.Dtor();
    Fn0091af4a();
}

struct View_0094d163_shaped02_gzcom {
    uint8_t pad14[0x14];
    Str_shaped02_gzcom mS2;
    uint8_t pad15[0x13];
    Str_shaped02_gzcom mS1;
    // STUB: 0x00414250
    void Base();
    void Fn0094d163();
};

// FUNCTION: 0x0094d163
void View_0094d163_shaped02_gzcom::Fn0094d163()
{
    mS1.Dtor();
    mS2.Dtor();
    Base();
}

// ---- pair 00921215 / 0096a607: is a key in an embedded set
struct Tree_426aa0_shaped02_gzcom {
    void* mpHeader;
    // STUB: 0x00426aa0
    void* Find(const uint32_t* pKey);
};

struct View_00921215_shaped02_gzcom {
    uint8_t pad[0x34];
    Tree_426aa0_shaped02_gzcom mTree;
    bool Fn00921215(uint32_t nKey);
};

// FUNCTION: 0x00921215
bool View_00921215_shaped02_gzcom::Fn00921215(uint32_t nKey)
{
    return mTree.Find(&nKey) != mTree.mpHeader;
}

struct Tree_98129c_shaped02_gzcom {
    void* mpHeader;
    // STUB: 0x0098129c
    void* Find(const uint32_t* pKey);
};

struct View_0096a607_shaped02_gzcom {
    uint8_t pad[8];
    Tree_98129c_shaped02_gzcom mTree;
    bool Fn0096a607(uint32_t nKey);
};

// FUNCTION: 0x0096a607
bool View_0096a607_shaped02_gzcom::Fn0096a607(uint32_t nKey)
{
    return mTree.Find(&nKey) != mTree.mpHeader;
}

// ---- pair 0092cb9f / 0092cbbc: one of two writers by a flag
struct View_0092cb9f_shaped02_gzcom {
    uint8_t pad[0x14];
    bool mbRecord;
    // STUB: 0x0092b6a3
    bool Rec(uint32_t a, uint32_t b);
    // STUB: 0x0092c9cb
    bool Txt(uint32_t a, uint32_t b);
    bool Fn0092cb9f(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0092cb9f score 10
bool View_0092cb9f_shaped02_gzcom::Fn0092cb9f(uint32_t a, uint32_t b)
{
    bool r;
    if (mbRecord) {
        r = Rec(a, b);
    } else {
        r = Txt(a, b);
    }
    return r;
}
#endif

struct View_0092cbbc_shaped02_gzcom {
    uint8_t pad[0x14];
    bool mbRecord;
    // STUB: 0x0092b6a3
    bool Rec(uint32_t a, uint32_t b);
    // STUB: 0x0092ca27
    bool Txt(uint32_t a, uint32_t b);
    bool Fn0092cbbc(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0092cbbc score 10
bool View_0092cbbc_shaped02_gzcom::Fn0092cbbc(uint32_t a, uint32_t b)
{
    bool r;
    if (mbRecord) {
        r = Rec(a, b);
    } else {
        r = Txt(a, b);
    }
    return r;
}
#endif

// ---- pair 0091c507 / 0091c52a: prepare with a code, copy the string at 0x50 into the result
struct Str_408be0_shaped02_gzcom {
    // STUB: 0x00408be0
    void CopyFrom(const void* pSource, uint32_t nPos, uint32_t nCount);
};

struct View_0091c507_shaped02_gzcom {
    uint8_t pad[0x50];
    uint8_t mStr[0x14];
    // STUB: 0x0091c46e
    void Prepare(uint32_t nCode);
    Str_408be0_shaped02_gzcom* Fn0091c507(Str_408be0_shaped02_gzcom* pOut);
};

// FUNCTION: 0x0091c507
Str_408be0_shaped02_gzcom* View_0091c507_shaped02_gzcom::Fn0091c507(Str_408be0_shaped02_gzcom* pOut)
{
    Prepare(0xf);
    pOut->CopyFrom(mStr, 0, 0xffffffff);
    return pOut;
}

struct View_0091c52a_shaped02_gzcom {
    uint8_t pad[0x50];
    uint8_t mStr[0x14];
    // STUB: 0x0091c46e
    void Prepare(uint32_t nCode);
    Str_408be0_shaped02_gzcom* Fn0091c52a(Str_408be0_shaped02_gzcom* pOut);
};

// FUNCTION: 0x0091c52a
Str_408be0_shaped02_gzcom* View_0091c52a_shaped02_gzcom::Fn0091c52a(Str_408be0_shaped02_gzcom* pOut)
{
    Prepare(3);
    pOut->CopyFrom(mStr, 0, 0xffffffff);
    return pOut;
}

// ---- pair 009204cb / 0092259c: AddRef under a lock guard
struct Lock_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Unlock() = 0;
};

struct Guard_48c9f0_shaped02_gzcom {
    uint32_t pad0;
    Lock_shaped02_gzcom* mpLock;
    // STUB: 0x0048c9f0
    void Init(void* pLock);
};

struct View_009204cb_shaped02_gzcom {
    uint8_t pad[0x24];
    uint32_t mnRefs;
    uint8_t mLock[4];
    uint32_t Fn009204cb();
};

// FUNCTION: 0x009204cb
uint32_t View_009204cb_shaped02_gzcom::Fn009204cb()
{
    Guard_48c9f0_shaped02_gzcom guard;
    guard.Init(mLock);
    ++mnRefs;
    uint32_t n = mnRefs;
    guard.mpLock->Unlock();
    return n;
}

struct View_0092259c_shaped02_gzcom {
    uint8_t pad[0x24];
    uint32_t mnRefs;
    uint8_t padB[0xc];
    uint8_t mLock[4];
    uint32_t Fn0092259c();
};

// FUNCTION: 0x0092259c
uint32_t View_0092259c_shaped02_gzcom::Fn0092259c()
{
    Guard_48c9f0_shaped02_gzcom guard;
    guard.Init(mLock);
    ++mnRefs;
    uint32_t n = mnRefs;
    guard.mpLock->Unlock();
    return n;
}

// ---- pair 0090cd65 / 0090cd8c: read / write through a slot, clamped at zero
struct Stream_0090cd65_shaped02_gzcom {
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
    virtual void Read(void* pBuf, int32_t* pCount) = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0090cd65 score 6
int32_t OB_STDCALL Fn0090cd65(Stream_0090cd65_shaped02_gzcom* pStream, void* pBuf, int32_t nCount)
{
    int32_t n = nCount;
    if (n < 0) {
        return 0;
    }
    pStream->Read(pBuf, &n);
    return n;
}
#endif

struct Stream_0090cd8c_shaped02_gzcom {
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
    virtual void Write(void* pBuf, int32_t* pCount) = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0090cd8c score 6
int32_t OB_STDCALL Fn0090cd8c(Stream_0090cd8c_shaped02_gzcom* pStream, void* pBuf, int32_t nCount)
{
    int32_t n = nCount;
    if (n < 0) {
        return 0;
    }
    pStream->Write(pBuf, &n);
    return n;
}
#endif

// ---- pair 0090d0b4 / 0090d0dc: clear a run of bits in a word
// FUNCTION: 0x0090d0b4
void OB_STDCALL Fn0090d0b4(uint32_t* pBits, uint32_t nPos, uint32_t nLevel)
{
    uint32_t nCount = 1u << (nLevel - 14);
    uint32_t nMask = ((1u << nCount) - 1u) << (nPos >> 14);
    *pBits &= ~nMask;
}

// FUNCTION: 0x0090d0dc
void OB_STDCALL Fn0090d0dc(uint32_t* pBits, uint32_t nPos, uint32_t nLevel)
{
    uint32_t nCount = 1u << (nLevel - 9);
    uint32_t nMask = ((1u << nCount) - 1u) << (nPos >> 9);
    *pBits &= ~nMask;
}

// ---- pair 0093059d / 00921f9b: destructor body of a class with two more vtables
struct Base_91dd53_shaped02_gzcom {
    uint32_t mnVtbl;
    // STUB: 0x0091dd53
    void Dtor();
};

struct Sub_5e5a10_shaped02_gzcom {
    // STUB: 0x005e5a10
    void Fn005e5a10();
};

struct View_0093059d_shaped02_gzcom {
    uint32_t mnVtbl0;
    Base_91dd53_shaped02_gzcom mBase;
    uint32_t mnVtbl2;
    uint8_t pad[0x14];
    Sub_5e5a10_shaped02_gzcom mSub;
    void Fn0093059d();
};

// FUNCTION: 0x0093059d
void View_0093059d_shaped02_gzcom::Fn0093059d()
{
    mnVtbl0 = 0x00ad1e40;
    mnVtbl2 = 0x00ad1e28;
    mBase.mnVtbl = 0x00ad1df4;
    mSub.Fn005e5a10();
    mBase.Dtor();
}

struct Sub_921f63_shaped02_gzcom {
    // STUB: 0x00921f63
    void Fn00921f63();
};

struct View_00921f9b_shaped02_gzcom {
    uint32_t mnVtbl0;
    Base_91dd53_shaped02_gzcom mBase;
    uint32_t mnVtbl2;
    uint8_t pad[0x14];
    Sub_921f63_shaped02_gzcom mSub;
    void Fn00921f9b();
};

// FUNCTION: 0x00921f9b
void View_00921f9b_shaped02_gzcom::Fn00921f9b()
{
    mnVtbl0 = 0x00acfdac;
    mnVtbl2 = 0x00acfd94;
    mBase.mnVtbl = 0x00acfd60;
    mSub.Fn00921f63();
    mBase.Dtor();
}

// ---- pair 0091ae8e / 00968c53: unlink a list node, destroy and free it, store the next in the result
// STUB: 0x0090cf63
void Fn0090cf63Free_shaped02(void* p);

struct Data_91adff_shaped02_gzcom {
    // STUB: 0x0091adff
    void Destroy(uint32_t nFlag);
};

struct Node_0091ae8e_shaped02_gzcom {
    Node_0091ae8e_shaped02_gzcom* mpNext;
    Node_0091ae8e_shaped02_gzcom* mpPrev;
    Data_91adff_shaped02_gzcom mData;
};

struct Iter_0091ae8e_shaped02_gzcom {
    Node_0091ae8e_shaped02_gzcom* mpNode;
};

// FUNCTION: 0x0091ae8e
Iter_0091ae8e_shaped02_gzcom* OB_STDCALL Fn0091ae8e(Iter_0091ae8e_shaped02_gzcom* pOut, Node_0091ae8e_shaped02_gzcom* pNode)
{
    Node_0091ae8e_shaped02_gzcom* pNext = pNode->mpNext;
    Node_0091ae8e_shaped02_gzcom* pPrev = pNode->mpPrev;
    pPrev->mpNext = pNext;
    pNext->mpPrev = pPrev;
    pNode->mData.Destroy(0);
    Fn0090cf63Free_shaped02(pNode);
    pOut->mpNode = pNext;
    return pOut;
}

struct Data_93ab29_shaped02_gzcom {
    // STUB: 0x0093ab29
    void Destroy(uint32_t nFlag);
};

struct Node_00968c53_shaped02_gzcom {
    Node_00968c53_shaped02_gzcom* mpNext;
    Node_00968c53_shaped02_gzcom* mpPrev;
    Data_93ab29_shaped02_gzcom mData;
};

struct Iter_00968c53_shaped02_gzcom {
    Node_00968c53_shaped02_gzcom* mpNode;
};

// FUNCTION: 0x00968c53
Iter_00968c53_shaped02_gzcom* OB_STDCALL Fn00968c53(Iter_00968c53_shaped02_gzcom* pOut, Node_00968c53_shaped02_gzcom* pNode)
{
    Node_00968c53_shaped02_gzcom* pNext = pNode->mpNext;
    Node_00968c53_shaped02_gzcom* pPrev = pNode->mpPrev;
    pPrev->mpNext = pNext;
    pNext->mpPrev = pPrev;
    pNode->mData.Destroy(0);
    Fn0090cf63Free_shaped02(pNode);
    pOut->mpNode = pNext;
    return pOut;
}

// ---- pair 0090dc3d / 0090dd09: insert a wrapped object into the member at +4, then release it
struct Obj_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
};

struct Wrap_4f20c0_shaped02_gzcom {
    Obj_shaped02_gzcom* mp;
    // STUB: 0x004f20c0
    uint32_t Get(Obj_shaped02_gzcom* p);
};

struct Set_9690f4_shaped02_gzcom {
    // STUB: 0x009690f4
    void Insert(uint32_t v);
};

struct View_0090dc3d_shaped02_gzcom {
    uint32_t pad0;
    Set_9690f4_shaped02_gzcom mSet;
    bool Fn0090dc3d(Wrap_4f20c0_shaped02_gzcom w);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0090dc3d score 11
bool View_0090dc3d_shaped02_gzcom::Fn0090dc3d(Wrap_4f20c0_shaped02_gzcom w)
{
    mSet.Insert(w.Get(w.mp));
    if (w.mp) {
        w.mp->Release();
    }
    return true;
}
#endif

struct Set_90dbcd_shaped02_gzcom {
    // STUB: 0x0090dbcd
    void Insert(uint32_t v);
};

struct View_0090dd09_shaped02_gzcom {
    uint32_t pad0;
    Set_90dbcd_shaped02_gzcom mSet;
    bool Fn0090dd09(Wrap_4f20c0_shaped02_gzcom w);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0090dd09 score 11
bool View_0090dd09_shaped02_gzcom::Fn0090dd09(Wrap_4f20c0_shaped02_gzcom w)
{
    mSet.Insert(w.Get(w.mp));
    if (w.mp) {
        w.mp->Release();
    }
    return true;
}
#endif

// ---- pair 00913292 / 00995d97: answer a few interface ids with this (and add a reference)
struct View_00913292_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn00913292(uint32_t nIid, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00913292 score 19
bool View_00913292_shaped02_gzcom::Fn00913292(uint32_t nIid, void** ppOut)
{
    if (nIid == 1 || nIid == 0x65297976 || nIid == 0xa52294b4) {
        *ppOut = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_00995d97_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn00995d97(uint32_t nIid, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00995d97 score 19
bool View_00995d97_shaped02_gzcom::Fn00995d97(uint32_t nIid, void** ppOut)
{
    if (nIid == 1 || nIid == 0x1a104742 || nIid == 0xa52294b4) {
        *ppOut = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

// ---- pair 0090d104 / 0090d134: free a binary tree (right subtree by recursion, left by loop)
struct TNode_0090d104_shaped02_gzcom {
    uint32_t pad[2];
    TNode_0090d104_shaped02_gzcom* mpLeft;
    TNode_0090d104_shaped02_gzcom* mpRight;
};

struct View_0090d104_shaped02_gzcom {
    void Fn0090d104(TNode_0090d104_shaped02_gzcom* pNode);
};

// FUNCTION: 0x0090d104
void View_0090d104_shaped02_gzcom::Fn0090d104(TNode_0090d104_shaped02_gzcom* pNode)
{
    while (pNode) {
        Fn0090d104(pNode->mpRight);
        TNode_0090d104_shaped02_gzcom* pLeft = pNode->mpLeft;
        Fn0090cf86Free_shaped02(pNode, 1);
        pNode = pLeft;
    }
}

struct View_0090d134_shaped02_gzcom {
    void Fn0090d134(TNode_0090d104_shaped02_gzcom* pNode);
};

// FUNCTION: 0x0090d134
void View_0090d134_shaped02_gzcom::Fn0090d134(TNode_0090d104_shaped02_gzcom* pNode)
{
    while (pNode) {
        Fn0090d134(pNode->mpRight);
        TNode_0090d104_shaped02_gzcom* pLeft = pNode->mpLeft;
        Fn0090cf86Free_shaped02(pNode, 1);
        pNode = pLeft;
    }
}

// ---- pair 0090c669 / 0090c82a: close the held object, then release self through two slots
struct Held_0090c669_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual bool IsOpen() = 0;
    virtual void Close() = 0;
};

struct View_0090c669_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Reset(uint32_t nFlag) = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Destroy(uint32_t nFlag) = 0;
    Held_0090c669_shaped02_gzcom* mpHeld;
    void Fn0090c669();
};

// FUNCTION: 0x0090c669
void View_0090c669_shaped02_gzcom::Fn0090c669()
{
    if (mpHeld) {
        if (mpHeld->IsOpen()) {
            mpHeld->Close();
        }
        Reset(0);
    }
    Destroy(1);
}

struct View_0090c82a_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Reset(uint32_t nFlag) = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Destroy(uint32_t nFlag) = 0;
    Held_0090c669_shaped02_gzcom* mpHeld;
    void Fn0090c82a();
};

// FUNCTION: 0x0090c82a
void View_0090c82a_shaped02_gzcom::Fn0090c82a()
{
    if (mpHeld) {
        if (mpHeld->IsOpen()) {
            mpHeld->Close();
        }
        Reset(0);
    }
    Destroy(1);
}

// ---- pair 0091e106 / 0091e137: wrap the argument, add the wrapper to the member at 0x124, release the argument
struct Set_91e008_shaped02_gzcom {
    // STUB: 0x0091e008
    void Insert(Wrap_4f20c0_shaped02_gzcom* pWrap);
};

struct View_0091e106_shaped02_gzcom {
    uint8_t pad[0x124];
    Set_91e008_shaped02_gzcom mSet;
    void Fn0091e106(Wrap_4f20c0_shaped02_gzcom w);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0091e106 score 13
void View_0091e106_shaped02_gzcom::Fn0091e106(Wrap_4f20c0_shaped02_gzcom w)
{
    w.Get(w.mp);
    mSet.Insert(&w);
    if (w.mp) {
        w.mp->Release();
    }
}
#endif

struct Set_7e98c0_shaped02_gzcom {
    // STUB: 0x007e98c0
    void Insert(Wrap_4f20c0_shaped02_gzcom* pWrap);
};

struct View_0091e137_shaped02_gzcom {
    uint8_t pad[0x124];
    Set_7e98c0_shaped02_gzcom mSet;
    void Fn0091e137(Wrap_4f20c0_shaped02_gzcom w);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0091e137 score 13
void View_0091e137_shaped02_gzcom::Fn0091e137(Wrap_4f20c0_shaped02_gzcom w)
{
    w.Get(w.mp);
    mSet.Insert(&w);
    if (w.mp) {
        w.mp->Release();
    }
}
#endif

// ---- pair 00923035 / 0092e298: destructor body: set three vtables, destroy two members, then the base
struct SubA_930b02_shaped02_gzcom {
    // STUB: 0x00930b02
    void Dtor();
};

struct SubB_922e9b_shaped02_gzcom {
    // STUB: 0x00922e9b
    void Dtor();
};

struct View_00923035_shaped02_gzcom {
    uint32_t mnVtbl0;
    Base_91dd53_shaped02_gzcom mBase;
    uint32_t mnVtbl2;
    uint8_t pad1[0x1c];
    SubB_922e9b_shaped02_gzcom mB;
    uint8_t pad2[0xb];
    SubA_930b02_shaped02_gzcom mA;
    void Fn00923035();
};

// FUNCTION: 0x00923035
void View_00923035_shaped02_gzcom::Fn00923035()
{
    mnVtbl0 = 0x00acfee0;
    mBase.mnVtbl = 0x00acfeac;
    mnVtbl2 = 0x00acfe94;
    mA.Dtor();
    mB.Dtor();
    mBase.Dtor();
}

struct SubC_92e103_shaped02_gzcom {
    // STUB: 0x0092e103
    void Dtor();
};

struct View_0092e298_shaped02_gzcom {
    uint32_t mnVtbl0;
    Base_91dd53_shaped02_gzcom mBase;
    uint32_t mnVtbl2;
    uint8_t pad1[0x18];
    SubA_930b02_shaped02_gzcom mA;
    uint8_t pad2[7];
    SubC_92e103_shaped02_gzcom mC;
    void Fn0092e298();
};

// FUNCTION: 0x0092e298
void View_0092e298_shaped02_gzcom::Fn0092e298()
{
    mnVtbl0 = 0x00ad1b80;
    mBase.mnVtbl = 0x00ad1b4c;
    mnVtbl2 = 0x00ad1b34;
    mC.Dtor();
    mA.Dtor();
    mBase.Dtor();
}

// ---- pair 00913da6 / 00913dde: assign a string built from a service's text to the argument
struct Str_408480_shaped02_gzcom {
    uint32_t pad0;
    void* mpBuf;
    uint32_t pad8[3];
    // STUB: 0x00408480
    void Ctor(const char* s);
    // STUB: 0x00424380
    void Assign(const Str_408480_shaped02_gzcom& other);
};

struct Svc_913da6_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual const char* GetText() = 0;
};

// STUB: 0x00913d4e
Svc_913da6_shaped02_gzcom* Fn00913d4e();

// FUNCTION: 0x00913da6
void Fn00913da6(Str_408480_shaped02_gzcom* pOut)
{
    Str_408480_shaped02_gzcom tmp;
    tmp.Ctor(Fn00913d4e()->GetText());
    pOut->Assign(tmp);
    if (tmp.mpBuf) {
        Fn0090cf63Free_shaped02(tmp.mpBuf);
    }
}

struct Svc_913dde_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual const char* GetText() = 0;
};

// STUB: 0x00913d4e
Svc_913dde_shaped02_gzcom* Fn00913d4eB();

// FUNCTION: 0x00913dde
void Fn00913dde(Str_408480_shaped02_gzcom* pOut)
{
    Str_408480_shaped02_gzcom tmp;
    tmp.Ctor(Fn00913d4eB()->GetText());
    pOut->Assign(tmp);
    if (tmp.mpBuf) {
        Fn0090cf63Free_shaped02(tmp.mpBuf);
    }
}

// ---- pair 0090de02 / 0094bbfe: answer interface ids with this or the second base, add a reference
struct BaseA_0090de02_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
};

struct BaseB_0090de02_shaped02_gzcom {
    virtual void PadB0() = 0;
};

struct View_0090de02_shaped02_gzcom : BaseA_0090de02_shaped02_gzcom, BaseB_0090de02_shaped02_gzcom {
    bool Fn0090de02(uint32_t nIid, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0090de02 score 8
bool View_0090de02_shaped02_gzcom::Fn0090de02(uint32_t nIid, void** ppOut)
{
    if (nIid == 1 || nIid == 0xa21ee941) {
        *ppOut = this;
    } else if (nIid == 0x03fa40bf) {
        *ppOut = static_cast<BaseB_0090de02_shaped02_gzcom*>(this);
    } else {
        return false;
    }
    AddRef();
    return true;
}
#endif

struct View_0094bbfe_shaped02_gzcom : BaseA_0090de02_shaped02_gzcom, BaseB_0090de02_shaped02_gzcom {
    bool Fn0094bbfe(uint32_t nIid, void** ppOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0094bbfe score 6
bool View_0094bbfe_shaped02_gzcom::Fn0094bbfe(uint32_t nIid, void** ppOut)
{
    if (nIid == 1 || nIid == 0x1a35608a) {
        *ppOut = this;
    } else if (nIid == 0xfa35615f) {
        *ppOut = static_cast<BaseB_0090de02_shaped02_gzcom*>(this);
    } else {
        return false;
    }
    AddRef();
    return true;
}
#endif

// ---- pair 0090b7ea / 0090b912: create a buffer, fill it through a slot, release it again on failure
struct Buf_0090b7ea_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
};

struct View_0090b7ea_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual bool Fill(uint32_t a, uint32_t b, Buf_0090b7ea_shaped02_gzcom* pBuf, uint32_t c) = 0;
    // STUB: 0x0090b6fc
    bool CreateBuffer(Buf_0090b7ea_shaped02_gzcom** ppBuf);
    bool Fn0090b7ea(uint32_t a, uint32_t b, Buf_0090b7ea_shaped02_gzcom** ppBuf, uint32_t c);
};

// FUNCTION: 0x0090b7ea
bool View_0090b7ea_shaped02_gzcom::Fn0090b7ea(uint32_t a, uint32_t b, Buf_0090b7ea_shaped02_gzcom** ppBuf, uint32_t c)
{
    bool bOk = false;
    if (CreateBuffer(ppBuf)) {
        bOk = Fill(a, b, *ppBuf, c);
        if (!bOk) {
            (*ppBuf)->Release();
            *ppBuf = 0;
        }
    }
    return bOk;
}

struct View_0090b912_shaped02_gzcom {
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
    virtual bool Fill(uint32_t a, uint32_t b, Buf_0090b7ea_shaped02_gzcom* pBuf, uint32_t c) = 0;
    // STUB: 0x0090b6fc
    bool CreateBuffer(Buf_0090b7ea_shaped02_gzcom** ppBuf);
    bool Fn0090b912(uint32_t a, uint32_t b, Buf_0090b7ea_shaped02_gzcom** ppBuf, uint32_t c);
};

// FUNCTION: 0x0090b912
bool View_0090b912_shaped02_gzcom::Fn0090b912(uint32_t a, uint32_t b, Buf_0090b7ea_shaped02_gzcom** ppBuf, uint32_t c)
{
    bool bOk = false;
    if (CreateBuffer(ppBuf)) {
        bOk = Fill(a, b, *ppBuf, c);
        if (!bOk) {
            (*ppBuf)->Release();
            *ppBuf = 0;
        }
    }
    return bOk;
}

// ---- pair 0090c7ab / 0090c9ae: under the global lock, select the handle, then read / write frame pixels
struct Lock_b625a4_shaped02_gzcom {
    // STUB: 0x00930b35
    uint32_t Lock();
    // STUB: 0x00930b6d
    uint32_t Unlock();
};

// GLOBAL: 0x00b625a4
extern Lock_b625a4_shaped02_gzcom gb625a4;

// STUB: 0x00a05580
void OB_STDCALL Fn00a05580(uint32_t nHandle);
// STUB: 0x00a054c0
bool OB_STDCALL Fn00a054c0(uint32_t nHandle, uint32_t a, uint32_t b, uint32_t c);
// STUB: 0x00a05550
bool OB_STDCALL Fn00a05550(uint32_t nHandle, uint32_t a, uint32_t b, uint32_t c);

struct View_0090c7ab_shaped02_gzcom {
    uint8_t pad[8];
    bool mbOpen;
    uint32_t mnSelect;
    uint32_t mnHandle;
    bool Fn0090c7ab(uint32_t a, uint32_t b, uint32_t c);
};

// FUNCTION: 0x0090c7ab
bool View_0090c7ab_shaped02_gzcom::Fn0090c7ab(uint32_t a, uint32_t b, uint32_t c)
{
    if (mbOpen) {
        gb625a4.Lock();
        Fn00a05580(mnSelect);
        bool bOk = Fn00a054c0(mnHandle, a, b, c);
        gb625a4.Unlock();
        return bOk;
    }
    return false;
}

struct View_0090c9ae_shaped02_gzcom {
    uint8_t pad[8];
    bool mbOpen;
    uint32_t mnHandle;
    uint32_t mnSelect;
    bool Fn0090c9ae(uint32_t a, uint32_t b, uint32_t c);
};

// FUNCTION: 0x0090c9ae
bool View_0090c9ae_shaped02_gzcom::Fn0090c9ae(uint32_t a, uint32_t b, uint32_t c)
{
    if (mbOpen) {
        gb625a4.Lock();
        Fn00a05580(mnSelect);
        bool bOk = Fn00a05550(mnHandle, a, b, c);
        gb625a4.Unlock();
        return bOk;
    }
    return false;
}

// ---- pair 00913556 / 0091359f: add / remove every notification of the list at the server (default: the global service)
struct Server_00913556_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Add(void* pTarget, uint32_t nMessage) = 0;
    virtual void Remove(void* pTarget, uint32_t nMessage) = 0;
};

struct Ref_449690_shaped02_gzcom {
    Server_00913556_shaped02_gzcom* mp;
    // STUB: 0x00449690
    Server_00913556_shaped02_gzcom** Get();
    // STUB: 0x004495c0
    void Release();
};

struct LNodeItem_shaped02_gzcom {
    uint32_t pad0[4];
    uint32_t mnMessage;
};

// STUB: 0x0040d4c0
LNodeItem_shaped02_gzcom* Fn0040d4c0(LNodeItem_shaped02_gzcom* pNode);

struct LHead_shaped02_gzcom {
    uint32_t pad0[2];
    LNodeItem_shaped02_gzcom* mpFirst;
};

struct View_00913556_shaped02_gzcom {
    LHead_shaped02_gzcom* mpList;
    void Fn00913556(void* pTarget, Ref_449690_shaped02_gzcom ref);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00913556 score 17
void View_00913556_shaped02_gzcom::Fn00913556(void* pTarget, Ref_449690_shaped02_gzcom ref)
{
    Server_00913556_shaped02_gzcom* pServer = ref.mp;
    if (!pServer) {
        pServer = *ref.Get();
        ref.Release();
    }
    LHead_shaped02_gzcom* pHead = mpList;
    for (LNodeItem_shaped02_gzcom* pNode = pHead->mpFirst; pNode != reinterpret_cast<LNodeItem_shaped02_gzcom*>(pHead); pNode = Fn0040d4c0(pNode)) {
        pServer->Add(pTarget, pNode->mnMessage);
    }
}
#endif

struct View_0091359f_shaped02_gzcom {
    LHead_shaped02_gzcom* mpList;
    void Fn0091359f(void* pTarget, Ref_449690_shaped02_gzcom ref);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0091359f score 17
void View_0091359f_shaped02_gzcom::Fn0091359f(void* pTarget, Ref_449690_shaped02_gzcom ref)
{
    Server_00913556_shaped02_gzcom* pServer = ref.mp;
    if (!pServer) {
        pServer = *ref.Get();
        ref.Release();
    }
    LHead_shaped02_gzcom* pHead = mpList;
    for (LNodeItem_shaped02_gzcom* pNode = pHead->mpFirst; pNode != reinterpret_cast<LNodeItem_shaped02_gzcom*>(pHead); pNode = Fn0040d4c0(pNode)) {
        pServer->Remove(pTarget, pNode->mnMessage);
    }
}
#endif

// ---- pair 0090be8e / 0090bee5: ask the service for an object, test it with the first argument, then pass it on
struct ObjA_0090be8e_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual bool Test(uint32_t a) = 0;
};

struct ObjB_0090bee5_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual bool Test(uint32_t a) = 0;
};

struct SvcA_0090be8e_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual bool Query(uint32_t nIid, uint32_t nType, ObjA_0090be8e_shaped02_gzcom** ppObj) = 0;
};

struct SvcB_0090bee5_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual bool Query(uint32_t nIid, uint32_t nType, ObjB_0090bee5_shaped02_gzcom** ppObj) = 0;
};

struct View_0090be8e_shaped02_gzcom {
    // STUB: 0x0090ddf1
    SvcA_0090be8e_shaped02_gzcom* GetService();
    // STUB: 0x0090bd07
    bool Apply(ObjA_0090be8e_shaped02_gzcom* pObj, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);
    bool Fn0090be8e(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);
};

// FUNCTION: 0x0090be8e
bool View_0090be8e_shaped02_gzcom::Fn0090be8e(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4)
{
    ObjA_0090be8e_shaped02_gzcom* pObj = 0;
    if (GetService()->Query(0xca316c55, 0x2a316c43, &pObj) && pObj->Test(a0)) {
        return Apply(pObj, a1, a2, a3, a4);
    }
    return false;
}

struct View_0090bee5_shaped02_gzcom {
    // STUB: 0x0090ddf1
    SvcB_0090bee5_shaped02_gzcom* GetService();
    // STUB: 0x0090bd07
    bool Apply(ObjB_0090bee5_shaped02_gzcom* pObj, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);
    bool Fn0090bee5(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);
};

// FUNCTION: 0x0090bee5
bool View_0090bee5_shaped02_gzcom::Fn0090bee5(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4)
{
    ObjB_0090bee5_shaped02_gzcom* pObj = 0;
    if (GetService()->Query(0xca316c55, 0x2a316c43, &pObj) && pObj->Test(a0)) {
        return Apply(pObj, a1, a2, a3, a4);
    }
    return false;
}

// ---- pair 0092c919 / 0092c972: format the argument with a global format string and pass the text to slot 14
struct Str_578390_shaped02_gzcom {
    uint32_t mnVtbl;
    void* mpBuf;
    uint32_t pad8[3];
    // STUB: 0x00578390
    void Ctor();
    // STUB: 0x009d7e63
    const char* CStr();
};

// STUB: 0x0090f574
void* Fn0090f574(Str_578390_shaped02_gzcom* pStr, const char* pFormat, ...);

// GLOBAL: 0x00b169b0
extern const char* gpb169b0;
// GLOBAL: 0x00b169b4
extern const char* gpb169b4;

struct View_0092c919_shaped02_gzcom {
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
    virtual bool Put(const char* pText) = 0;
    bool Fn0092c919(uint32_t nValue);
};

// FUNCTION: 0x0092c919
bool View_0092c919_shaped02_gzcom::Fn0092c919(uint32_t nValue)
{
    Str_578390_shaped02_gzcom tmp;
    tmp.Ctor();
    Fn0090f574(&tmp, gpb169b0, nValue);
    bool bOk = Put(tmp.CStr());
    tmp.mnVtbl = 0x00a80810;
    if (tmp.mpBuf) {
        Fn0090cf63Free_shaped02(tmp.mpBuf);
    }
    return bOk;
}

struct View_0092c972_shaped02_gzcom {
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
    virtual bool Put(const char* pText) = 0;
    bool Fn0092c972(uint32_t nValue);
};

// FUNCTION: 0x0092c972
bool View_0092c972_shaped02_gzcom::Fn0092c972(uint32_t nValue)
{
    Str_578390_shaped02_gzcom tmp;
    tmp.Ctor();
    Fn0090f574(&tmp, gpb169b4, nValue);
    bool bOk = Put(tmp.CStr());
    tmp.mnVtbl = 0x00a80810;
    if (tmp.mpBuf) {
        Fn0090cf63Free_shaped02(tmp.mpBuf);
    }
    return bOk;
}

// ---- pair 0092c9cb / 0092ca27: the same with two values
// GLOBAL: 0x00b169b8
extern const char* gpb169b8;
// GLOBAL: 0x00b169bc
extern const char* gpb169bc;

struct View_0092c9cb_shaped02_gzcom {
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
    virtual bool Put(const char* pText) = 0;
    bool Fn0092c9cb(uint32_t a, uint32_t b);
};

// FUNCTION: 0x0092c9cb
bool View_0092c9cb_shaped02_gzcom::Fn0092c9cb(uint32_t a, uint32_t b)
{
    Str_578390_shaped02_gzcom tmp;
    tmp.Ctor();
    Fn0090f574(&tmp, gpb169b8, a, b);
    bool bOk = Put(tmp.CStr());
    tmp.mnVtbl = 0x00a80810;
    if (tmp.mpBuf) {
        Fn0090cf63Free_shaped02(tmp.mpBuf);
    }
    return bOk;
}

struct View_0092ca27_shaped02_gzcom {
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
    virtual bool Put(const char* pText) = 0;
    bool Fn0092ca27(uint32_t a, uint32_t b);
};

// FUNCTION: 0x0092ca27
bool View_0092ca27_shaped02_gzcom::Fn0092ca27(uint32_t a, uint32_t b)
{
    Str_578390_shaped02_gzcom tmp;
    tmp.Ctor();
    Fn0090f574(&tmp, gpb169bc, a, b);
    bool bOk = Put(tmp.CStr());
    tmp.mnVtbl = 0x00a80810;
    if (tmp.mpBuf) {
        Fn0090cf63Free_shaped02(tmp.mpBuf);
    }
    return bOk;
}

// ---- pair 0090b82c / 0090b89f: look an object up, ask it for an inner interface, hand that to a slot of this
struct Inner_0090b82c_shaped02_gzcom {
    virtual bool Query(uint32_t nIid, void** ppOut) = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
};

struct Found_0090b82c_shaped02_gzcom {
    virtual bool Query(uint32_t nIid, Inner_0090b82c_shaped02_gzcom** ppOut) = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Close() = 0;
};

struct Finder_0090b82c_shaped02_gzcom {
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
    virtual bool Find(uint32_t nKey, Found_0090b82c_shaped02_gzcom** ppOut, uint32_t nFlag) = 0;
};

struct View_0090b82c_shaped02_gzcom {
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
    virtual bool Use(Inner_0090b82c_shaped02_gzcom* pInner, uint32_t a, uint32_t b, uint32_t c) = 0;
    // STUB: 0x0090b69c
    Finder_0090b82c_shaped02_gzcom* GetFinder();
    bool Fn0090b82c(uint32_t nKey, uint32_t a, uint32_t b, uint32_t c);
};

// FUNCTION: 0x0090b82c
bool View_0090b82c_shaped02_gzcom::Fn0090b82c(uint32_t nKey, uint32_t a, uint32_t b, uint32_t c)
{
    Found_0090b82c_shaped02_gzcom* pFound;
    bool bOk = GetFinder()->Find(nKey, &pFound, 0);
    if (bOk) {
        Inner_0090b82c_shaped02_gzcom* pInner = 0;
        if (pFound->Query(0xc56b8f08, &pInner)) {
            bOk = Use(pInner, a, b, c);
            pInner->Release();
        }
        pFound->Close();
        pFound->Release();
    }
    return bOk;
}

struct View_0090b89f_shaped02_gzcom {
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
    virtual bool Use(Inner_0090b82c_shaped02_gzcom* pInner, uint32_t a, uint32_t b, uint32_t c) = 0;
    // STUB: 0x0090b69c
    Finder_0090b82c_shaped02_gzcom* GetFinder();
    bool Fn0090b89f(uint32_t nKey, uint32_t a, uint32_t b, uint32_t c);
};

// FUNCTION: 0x0090b89f
bool View_0090b89f_shaped02_gzcom::Fn0090b89f(uint32_t nKey, uint32_t a, uint32_t b, uint32_t c)
{
    Found_0090b82c_shaped02_gzcom* pFound;
    bool bOk = GetFinder()->Find(nKey, &pFound, 0);
    if (bOk) {
        Inner_0090b82c_shaped02_gzcom* pInner = 0;
        if (pFound->Query(0xc56b8f08, &pInner)) {
            bOk = Use(pInner, a, b, c);
            pInner->Release();
        }
        pFound->Close();
        pFound->Release();
    }
    return bOk;
}

// ---- pairs 00922bca/00922d19 and 009229f3/00922ca6: under the lock, call slot Do on every list object or on the one for the key

struct Obj_00922bca_shaped02_gzcom {
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
    virtual bool Do(uint32_t a, uint32_t b) = 0;
};

struct ONode_00922bca_shaped02_gzcom {
    uint32_t pad[5];
    Obj_00922bca_shaped02_gzcom* mpObj;
};

struct OHead_00922bca_shaped02_gzcom {
    uint32_t pad[2];
    ONode_00922bca_shaped02_gzcom* mpFirst;
};

// STUB: 0x0040d4c0
ONode_00922bca_shaped02_gzcom* Fn0040d4c0_00922bca(ONode_00922bca_shaped02_gzcom* pNode);

struct View_00922bca_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual Obj_00922bca_shaped02_gzcom* GetObj(uint32_t nKey) = 0;
    uint8_t pad[0x24];
    OHead_00922bca_shaped02_gzcom* mpList;
    uint8_t padB[8];
    uint8_t mLock[4];
    bool Fn00922bca(uint32_t a, uint32_t b, uint32_t nKey);
};

// FUNCTION: 0x00922bca
bool View_00922bca_shaped02_gzcom::Fn00922bca(uint32_t a, uint32_t b, uint32_t nKey)
{
    Guard_48c9f0_shaped02_gzcom guard;
    guard.Init(mLock);
    bool bOk;
    if (nKey == 0xffffffff) {
        OHead_00922bca_shaped02_gzcom* pHead = mpList;
        for (ONode_00922bca_shaped02_gzcom* pNode = pHead->mpFirst; pNode != reinterpret_cast<ONode_00922bca_shaped02_gzcom*>(pHead); pNode = Fn0040d4c0_00922bca(pNode)) {
            pNode->mpObj->Do(a, b);
        }
        bOk = false;
    } else {
        Obj_00922bca_shaped02_gzcom* pObj = GetObj(nKey);
        if (pObj) {
            bOk = pObj->Do(a, b);
        } else {
            bOk = false;
        }
    }
    guard.mpLock->Unlock();
    return bOk;
}

struct Obj_00922d19_shaped02_gzcom {
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
    virtual bool Do(uint32_t a, uint32_t b) = 0;
};

struct ONode_00922d19_shaped02_gzcom {
    uint32_t pad[5];
    Obj_00922d19_shaped02_gzcom* mpObj;
};

struct OHead_00922d19_shaped02_gzcom {
    uint32_t pad[2];
    ONode_00922d19_shaped02_gzcom* mpFirst;
};

// STUB: 0x0040d4c0
ONode_00922d19_shaped02_gzcom* Fn0040d4c0_00922d19(ONode_00922d19_shaped02_gzcom* pNode);

struct View_00922d19_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual Obj_00922d19_shaped02_gzcom* GetObj(uint32_t nKey) = 0;
    uint8_t pad[0x24];
    OHead_00922d19_shaped02_gzcom* mpList;
    uint8_t padB[8];
    uint8_t mLock[4];
    bool Fn00922d19(uint32_t a, uint32_t b, uint32_t nKey);
};

// FUNCTION: 0x00922d19
bool View_00922d19_shaped02_gzcom::Fn00922d19(uint32_t a, uint32_t b, uint32_t nKey)
{
    Guard_48c9f0_shaped02_gzcom guard;
    guard.Init(mLock);
    bool bOk;
    if (nKey == 0xffffffff) {
        OHead_00922d19_shaped02_gzcom* pHead = mpList;
        for (ONode_00922d19_shaped02_gzcom* pNode = pHead->mpFirst; pNode != reinterpret_cast<ONode_00922d19_shaped02_gzcom*>(pHead); pNode = Fn0040d4c0_00922d19(pNode)) {
            pNode->mpObj->Do(a, b);
        }
        bOk = false;
    } else {
        Obj_00922d19_shaped02_gzcom* pObj = GetObj(nKey);
        if (pObj) {
            bOk = pObj->Do(a, b);
        } else {
            bOk = false;
        }
    }
    guard.mpLock->Unlock();
    return bOk;
}

struct Obj_009229f3_shaped02_gzcom {
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
    virtual bool Do(uint32_t a) = 0;
};

struct ONode_009229f3_shaped02_gzcom {
    uint32_t pad[5];
    Obj_009229f3_shaped02_gzcom* mpObj;
};

struct OHead_009229f3_shaped02_gzcom {
    uint32_t pad[2];
    ONode_009229f3_shaped02_gzcom* mpFirst;
};

// STUB: 0x0040d4c0
ONode_009229f3_shaped02_gzcom* Fn0040d4c0_009229f3(ONode_009229f3_shaped02_gzcom* pNode);

struct View_009229f3_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual Obj_009229f3_shaped02_gzcom* GetObj(uint32_t nKey) = 0;
    uint8_t pad[0x24];
    OHead_009229f3_shaped02_gzcom* mpList;
    uint8_t padB[8];
    uint8_t mLock[4];
    bool Fn009229f3(uint32_t a, uint32_t nKey);
};

// FUNCTION: 0x009229f3
bool View_009229f3_shaped02_gzcom::Fn009229f3(uint32_t a, uint32_t nKey)
{
    Guard_48c9f0_shaped02_gzcom guard;
    guard.Init(mLock);
    bool bOk;
    if (nKey == 0xfffffffe) {
        OHead_009229f3_shaped02_gzcom* pHead = mpList;
        for (ONode_009229f3_shaped02_gzcom* pNode = pHead->mpFirst; pNode != reinterpret_cast<ONode_009229f3_shaped02_gzcom*>(pHead); pNode = Fn0040d4c0_009229f3(pNode)) {
            if (pNode->mpObj->Do(a)) {
                bOk = true;
                goto done;
            }
        }
        bOk = false;
    } else {
        Obj_009229f3_shaped02_gzcom* pObj = GetObj(nKey);
        if (pObj) {
            bOk = pObj->Do(a);
        } else {
            bOk = false;
        }
    }
done:
    guard.mpLock->Unlock();
    return bOk;
}

struct Obj_00922ca6_shaped02_gzcom {
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
    virtual bool Do(uint32_t a) = 0;
};

struct ONode_00922ca6_shaped02_gzcom {
    uint32_t pad[5];
    Obj_00922ca6_shaped02_gzcom* mpObj;
};

struct OHead_00922ca6_shaped02_gzcom {
    uint32_t pad[2];
    ONode_00922ca6_shaped02_gzcom* mpFirst;
};

// STUB: 0x0040d4c0
ONode_00922ca6_shaped02_gzcom* Fn0040d4c0_00922ca6(ONode_00922ca6_shaped02_gzcom* pNode);

struct View_00922ca6_shaped02_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual Obj_00922ca6_shaped02_gzcom* GetObj(uint32_t nKey) = 0;
    uint8_t pad[0x24];
    OHead_00922ca6_shaped02_gzcom* mpList;
    uint8_t padB[8];
    uint8_t mLock[4];
    bool Fn00922ca6(uint32_t a, uint32_t nKey);
};

// FUNCTION: 0x00922ca6
bool View_00922ca6_shaped02_gzcom::Fn00922ca6(uint32_t a, uint32_t nKey)
{
    Guard_48c9f0_shaped02_gzcom guard;
    guard.Init(mLock);
    bool bOk;
    if (nKey == 0xfffffffe) {
        OHead_00922ca6_shaped02_gzcom* pHead = mpList;
        for (ONode_00922ca6_shaped02_gzcom* pNode = pHead->mpFirst; pNode != reinterpret_cast<ONode_00922ca6_shaped02_gzcom*>(pHead); pNode = Fn0040d4c0_00922ca6(pNode)) {
            if (pNode->mpObj->Do(a)) {
                bOk = true;
                goto done;
            }
        }
        bOk = false;
    } else {
        Obj_00922ca6_shaped02_gzcom* pObj = GetObj(nKey);
        if (pObj) {
            bOk = pObj->Do(a);
        } else {
            bOk = false;
        }
    }
done:
    guard.mpLock->Unlock();
    return bOk;
}

