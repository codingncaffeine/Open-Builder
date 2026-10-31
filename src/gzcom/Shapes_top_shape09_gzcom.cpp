#include "common/types.h"
#include "common/compiler.h"
#include <stddef.h>
#include <new>

// STUB: 0x009ef059
extern "C" int atexit(void (*f)());

// The STL allocator of the original.
namespace _STL {
    // STUB: 0x0090cf54
    void* __stl_new(unsigned int size);
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

// The header-less node of an STL tree container.
struct Node_top_shape09_gzcom {
    uint8_t mPad[8];
    Node_top_shape09_gzcom* mpLeft;
    Node_top_shape09_gzcom* mpRight;
};

template <int N> struct Pad_top_shape09_gzcom { uint8_t mPad[N]; };
struct Tail_top_shape09_gzcom { uint32_t mTail; };


// STUB: 0x0091f887
uint32_t Fn0091f90d_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x0091f90d
uint32_t Fn0091f90d(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn0091f90d_callee(a, b, c, &flag, 0);
}

// STUB: 0x009ba806
uint32_t Fn009bad27_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009bad27
uint32_t Fn009bad27(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009bad27_callee(a, b, c, &flag, 0);
}

// STUB: 0x009ba838
uint32_t Fn009bad44_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009bad44
uint32_t Fn009bad44(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009bad44_callee(a, b, c, &flag, 0);
}

// STUB: 0x009ba86a
uint32_t Fn009bad61_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009bad61
uint32_t Fn009bad61(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009bad61_callee(a, b, c, &flag, 0);
}

// STUB: 0x009ba89c
uint32_t Fn009bad7e_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009bad7e
uint32_t Fn009bad7e(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009bad7e_callee(a, b, c, &flag, 0);
}

// STUB: 0x009ba8ce
uint32_t Fn009bad9b_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009bad9b
uint32_t Fn009bad9b(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009bad9b_callee(a, b, c, &flag, 0);
}

// STUB: 0x009ba900
uint32_t Fn009badb8_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009badb8
uint32_t Fn009badb8(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009badb8_callee(a, b, c, &flag, 0);
}

// STUB: 0x009badf2
uint32_t Fn009bb4a5_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009bb4a5
uint32_t Fn009bb4a5(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009bb4a5_callee(a, b, c, &flag, 0);
}

// STUB: 0x009bae24
uint32_t Fn009bb4c2_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009bb4c2
uint32_t Fn009bb4c2(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009bb4c2_callee(a, b, c, &flag, 0);
}

struct Obj_008747d4 : Pad_top_shape09_gzcom<4>, Tail_top_shape09_gzcom {
    // STUB: 0x00875f76
    Obj_008747d4* Construct();
};

// FUNCTION: 0x008747d4
Tail_top_shape09_gzcom* Fn008747d4()
{
    void* mem = operator new(0x54);
    Obj_008747d4* obj = mem ? static_cast<Obj_008747d4*>(mem)->Construct() : 0;
    return obj;
}

struct Value_0091b2d6 {
    // STUB: 0x0091aeed
    void Copy(const void* source);
};

struct Item_0091b2d6 {
    uint8_t mPad[8];
    Value_0091b2d6 mValue;
};

// FUNCTION: 0x0091b2d6
Item_0091b2d6* OB_STDCALL Fn0091b2d6(const void* source)
{
    Item_0091b2d6* node = static_cast<Item_0091b2d6*>(_STL::__stl_new(0x24));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Obj_00935865 : Pad_top_shape09_gzcom<4>, Tail_top_shape09_gzcom {
    // STUB: 0x0093a280
    Obj_00935865* Construct();
};

// FUNCTION: 0x00935865
Tail_top_shape09_gzcom* Fn00935865()
{
    void* mem = operator new(0x48);
    Obj_00935865* obj = mem ? static_cast<Obj_00935865*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_00935ebd : Pad_top_shape09_gzcom<4>, Tail_top_shape09_gzcom {
    // STUB: 0x00935e15
    Obj_00935ebd* Construct();
};

// FUNCTION: 0x00935ebd
Tail_top_shape09_gzcom* Fn00935ebd()
{
    void* mem = operator new(0x30);
    Obj_00935ebd* obj = mem ? static_cast<Obj_00935ebd*>(mem)->Construct() : 0;
    return obj;
}

struct Value_00949327 {
    // STUB: 0x009490c9
    void Copy(const void* source);
};

struct Item_00949327 {
    uint8_t mPad[16];
    Value_00949327 mValue;
};

// FUNCTION: 0x00949327
Item_00949327* OB_STDCALL Fn00949327(const void* source)
{
    Item_00949327* node = static_cast<Item_00949327*>(_STL::__stl_new(0x18));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Obj_00974f87 : Pad_top_shape09_gzcom<16>, Tail_top_shape09_gzcom {
    // STUB: 0x0097806d
    Obj_00974f87* Construct();
};

// FUNCTION: 0x00974f87
Tail_top_shape09_gzcom* Fn00974f87()
{
    void* mem = operator new(0x1c);
    Obj_00974f87* obj = mem ? static_cast<Obj_00974f87*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_0092ebb7 : Pad_top_shape09_gzcom<4>, Tail_top_shape09_gzcom {
    // STUB: 0x0092eb23
    Obj_0092ebb7* Construct();
};

// FUNCTION: 0x0092ebb7
Tail_top_shape09_gzcom* Fn0092ebb7()
{
    void* mem = operator new(0xb0);
    Obj_0092ebb7* obj = mem ? static_cast<Obj_0092ebb7*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_00935886 : Pad_top_shape09_gzcom<12>, Tail_top_shape09_gzcom {
    // STUB: 0x0093e8f4
    Obj_00935886* Construct();
};

// FUNCTION: 0x00935886
Tail_top_shape09_gzcom* Fn00935886()
{
    void* mem = operator new(0x104);
    Obj_00935886* obj = mem ? static_cast<Obj_00935886*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_009b1e0a : Pad_top_shape09_gzcom<4>, Tail_top_shape09_gzcom {
    // STUB: 0x009b1c27
    Obj_009b1e0a* Construct();
};

// FUNCTION: 0x009b1e0a
Tail_top_shape09_gzcom* Fn009b1e0a()
{
    void* mem = operator new(0x1b4);
    Obj_009b1e0a* obj = mem ? static_cast<Obj_009b1e0a*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_009da575 : Pad_top_shape09_gzcom<4>, Tail_top_shape09_gzcom {
    // STUB: 0x009dae9f
    Obj_009da575* Construct();
};

// FUNCTION: 0x009da575
Tail_top_shape09_gzcom* Fn009da575()
{
    void* mem = operator new(0x1dc);
    Obj_009da575* obj = mem ? static_cast<Obj_009da575*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_009da599 : Pad_top_shape09_gzcom<4>, Tail_top_shape09_gzcom {
    // STUB: 0x00996271
    Obj_009da599* Construct();
};

// FUNCTION: 0x009da599
Tail_top_shape09_gzcom* Fn009da599()
{
    void* mem = operator new(0x9c);
    Obj_009da599* obj = mem ? static_cast<Obj_009da599*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_0087480e : Pad_top_shape09_gzcom<216>, Tail_top_shape09_gzcom {
    // STUB: 0x00878d9f
    Obj_0087480e* Construct();
};

// FUNCTION: 0x0087480e
Tail_top_shape09_gzcom* Fn0087480e()
{
    void* mem = operator new(0x100);
    Obj_0087480e* obj = mem ? static_cast<Obj_0087480e*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_0099b74d : Pad_top_shape09_gzcom<216>, Tail_top_shape09_gzcom {
    // STUB: 0x0099b6a5
    Obj_0099b74d* Construct();
};

// FUNCTION: 0x0099b74d
Tail_top_shape09_gzcom* Fn0099b74d()
{
    void* mem = operator new(0x128);
    Obj_0099b74d* obj = mem ? static_cast<Obj_0099b74d*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_009c471e : Pad_top_shape09_gzcom<292>, Tail_top_shape09_gzcom {
    // STUB: 0x009c46af
    Obj_009c471e* Construct();
};

// FUNCTION: 0x009c471e
Tail_top_shape09_gzcom* Fn009c471e()
{
    void* mem = operator new(0x150);
    Obj_009c471e* obj = mem ? static_cast<Obj_009c471e*>(mem)->Construct() : 0;
    return obj;
}

struct View_00876f2a_top_shape09_gzcom {
    void Fn00876f2a(Node_top_shape09_gzcom* node);
};

// FUNCTION: 0x00876f2a
void View_00876f2a_top_shape09_gzcom::Fn00876f2a(Node_top_shape09_gzcom* node)
{
    while (node) {
        Fn00876f2a(node->mpRight);
        Node_top_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_00891eb9_top_shape09_gzcom {
    void Fn00891eb9(Node_top_shape09_gzcom* node);
};

// FUNCTION: 0x00891eb9
void View_00891eb9_top_shape09_gzcom::Fn00891eb9(Node_top_shape09_gzcom* node)
{
    while (node) {
        Fn00891eb9(node->mpRight);
        Node_top_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_009491a5_top_shape09_gzcom {
    void Fn009491a5(Node_top_shape09_gzcom* node);
};

// FUNCTION: 0x009491a5
void View_009491a5_top_shape09_gzcom::Fn009491a5(Node_top_shape09_gzcom* node)
{
    while (node) {
        Fn009491a5(node->mpRight);
        Node_top_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_009491d2_top_shape09_gzcom {
    void Fn009491d2(Node_top_shape09_gzcom* node);
};

// FUNCTION: 0x009491d2
void View_009491d2_top_shape09_gzcom::Fn009491d2(Node_top_shape09_gzcom* node)
{
    while (node) {
        Fn009491d2(node->mpRight);
        Node_top_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_009dad98_top_shape09_gzcom {
    void Fn009dad98(Node_top_shape09_gzcom* node);
};

// FUNCTION: 0x009dad98
void View_009dad98_top_shape09_gzcom::Fn009dad98(Node_top_shape09_gzcom* node)
{
    while (node) {
        Fn009dad98(node->mpRight);
        Node_top_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct Single_0087497e {
    // STUB: 0x0087484b
    Single_0087497e();
    uint8_t mPad[4];
};

// STUB: 0x00a7f2da
void Tcf_0087497e();
// GLOBAL: 0x00b54084
extern uint32_t gGuard_0087497e;
// GLOBAL: 0x00b54038
extern Single_0087497e gObject_0087497e;
// GLOBAL: 0x00b54038
extern uint8_t gAddress_0087497e[4];

// FUNCTION: 0x0087497e
Single_0087497e* Fn0087497e()
{
    if (!(gGuard_0087497e & 1)) {
        gGuard_0087497e |= 1;
        new (&gObject_0087497e) Single_0087497e();
        atexit(Tcf_0087497e);
    }
    return reinterpret_cast<Single_0087497e*>(gAddress_0087497e);
}

struct Single_0087b212 {
    // STUB: 0x0087b1c3
    Single_0087b212();
    uint8_t mPad[4];
};

// STUB: 0x00a7f2f8
void Tcf_0087b212();
// GLOBAL: 0x00b54104
extern uint32_t gGuard_0087b212;
// GLOBAL: 0x00b540b8
extern Single_0087b212 gObject_0087b212;
// GLOBAL: 0x00b540b8
extern uint8_t gAddress_0087b212[4];

// FUNCTION: 0x0087b212
Single_0087b212* Fn0087b212()
{
    if (!(gGuard_0087b212 & 1)) {
        gGuard_0087b212 |= 1;
        new (&gObject_0087b212) Single_0087b212();
        atexit(Tcf_0087b212);
    }
    return reinterpret_cast<Single_0087b212*>(gAddress_0087b212);
}

struct Single_00896012 {
    // STUB: 0x00895f7b
    Single_00896012();
    uint8_t mPad[4];
};

// STUB: 0x00a7f355
void Tcf_00896012();
// GLOBAL: 0x00b54414
extern uint32_t gGuard_00896012;
// GLOBAL: 0x00b543c8
extern Single_00896012 gObject_00896012;
// GLOBAL: 0x00b543c8
extern uint8_t gAddress_00896012[4];

// FUNCTION: 0x00896012
Single_00896012* Fn00896012()
{
    if (!(gGuard_00896012 & 1)) {
        gGuard_00896012 |= 1;
        new (&gObject_00896012) Single_00896012();
        atexit(Tcf_00896012);
    }
    return reinterpret_cast<Single_00896012*>(gAddress_00896012);
}

struct Single_008f677c {
    // STUB: 0x008f673e
    Single_008f677c();
    uint8_t mPad[4];
};

// STUB: 0x00a7f38b
void Tcf_008f677c();
// GLOBAL: 0x00b6243c
extern uint32_t gGuard_008f677c;
// GLOBAL: 0x00b623f0
extern Single_008f677c gObject_008f677c;
// GLOBAL: 0x00b623f0
extern uint8_t gAddress_008f677c[4];

// FUNCTION: 0x008f677c
Single_008f677c* Fn008f677c()
{
    if (!(gGuard_008f677c & 1)) {
        gGuard_008f677c |= 1;
        new (&gObject_008f677c) Single_008f677c();
        atexit(Tcf_008f677c);
    }
    return reinterpret_cast<Single_008f677c*>(gAddress_008f677c);
}

struct Single_008fc398 {
    // STUB: 0x008fc379
    Single_008fc398();
    uint8_t mPad[4];
};

// STUB: 0x00a7f395
void Tcf_008fc398();
// GLOBAL: 0x00b6248c
extern uint32_t gGuard_008fc398;
// GLOBAL: 0x00b62440
extern Single_008fc398 gObject_008fc398;
// GLOBAL: 0x00b62440
extern uint8_t gAddress_008fc398[4];

// FUNCTION: 0x008fc398
Single_008fc398* Fn008fc398()
{
    if (!(gGuard_008fc398 & 1)) {
        gGuard_008fc398 |= 1;
        new (&gObject_008fc398) Single_008fc398();
        atexit(Tcf_008fc398);
    }
    return reinterpret_cast<Single_008fc398*>(gAddress_008fc398);
}

struct Single_0090ade3 {
    // STUB: 0x0090ad97
    Single_0090ade3();
    uint8_t mPad[4];
};

// STUB: 0x00a7f419
void Tcf_0090ade3();
// GLOBAL: 0x00b6258c
extern uint32_t gGuard_0090ade3;
// GLOBAL: 0x00b62540
extern Single_0090ade3 gObject_0090ade3;
// GLOBAL: 0x00b62540
extern uint8_t gAddress_0090ade3[4];

// FUNCTION: 0x0090ade3
Single_0090ade3* Fn0090ade3()
{
    if (!(gGuard_0090ade3 & 1)) {
        gGuard_0090ade3 |= 1;
        new (&gObject_0090ade3) Single_0090ade3();
        atexit(Tcf_0090ade3);
    }
    return reinterpret_cast<Single_0090ade3*>(gAddress_0090ade3);
}

struct Single_009361d5 {
    // STUB: 0x00935f28
    Single_009361d5();
    uint8_t mPad[4];
};

// STUB: 0x00a7f580
void Tcf_009361d5();
// GLOBAL: 0x00b63374
extern uint32_t gGuard_009361d5;
// GLOBAL: 0x00b63328
extern Single_009361d5 gObject_009361d5;
// GLOBAL: 0x00b63328
extern uint8_t gAddress_009361d5[4];

// FUNCTION: 0x009361d5
Single_009361d5* Fn009361d5()
{
    if (!(gGuard_009361d5 & 1)) {
        gGuard_009361d5 |= 1;
        new (&gObject_009361d5) Single_009361d5();
        atexit(Tcf_009361d5);
    }
    return reinterpret_cast<Single_009361d5*>(gAddress_009361d5);
}

struct Single_009444cf {
    // STUB: 0x0094448e
    Single_009444cf();
    uint8_t mPad[4];
};

// STUB: 0x00a7f600
void Tcf_009444cf();
// GLOBAL: 0x00b63444
extern uint32_t gGuard_009444cf;
// GLOBAL: 0x00b633f8
extern Single_009444cf gObject_009444cf;
// GLOBAL: 0x00b633f8
extern uint8_t gAddress_009444cf[4];

// FUNCTION: 0x009444cf
Single_009444cf* Fn009444cf()
{
    if (!(gGuard_009444cf & 1)) {
        gGuard_009444cf |= 1;
        new (&gObject_009444cf) Single_009444cf();
        atexit(Tcf_009444cf);
    }
    return reinterpret_cast<Single_009444cf*>(gAddress_009444cf);
}

struct Single_0094575a {
    // STUB: 0x009456ec
    Single_0094575a();
    uint8_t mPad[4];
};

// STUB: 0x00a7f60a
void Tcf_0094575a();
// GLOBAL: 0x00b63494
extern uint32_t gGuard_0094575a;
// GLOBAL: 0x00b63448
extern Single_0094575a gObject_0094575a;
// GLOBAL: 0x00b63448
extern uint8_t gAddress_0094575a[4];

// FUNCTION: 0x0094575a
Single_0094575a* Fn0094575a()
{
    if (!(gGuard_0094575a & 1)) {
        gGuard_0094575a |= 1;
        new (&gObject_0094575a) Single_0094575a();
        atexit(Tcf_0094575a);
    }
    return reinterpret_cast<Single_0094575a*>(gAddress_0094575a);
}

struct Single_0094b053 {
    // STUB: 0x0094aff6
    Single_0094b053();
    uint8_t mPad[4];
};

// STUB: 0x00a7f650
void Tcf_0094b053();
// GLOBAL: 0x00b63584
extern uint32_t gGuard_0094b053;
// GLOBAL: 0x00b63538
extern Single_0094b053 gObject_0094b053;
// GLOBAL: 0x00b63538
extern uint8_t gAddress_0094b053[4];

// FUNCTION: 0x0094b053
Single_0094b053* Fn0094b053()
{
    if (!(gGuard_0094b053 & 1)) {
        gGuard_0094b053 |= 1;
        new (&gObject_0094b053) Single_0094b053();
        atexit(Tcf_0094b053);
    }
    return reinterpret_cast<Single_0094b053*>(gAddress_0094b053);
}

struct Single_009666c9 {
    // STUB: 0x00966498
    Single_009666c9();
    uint8_t mPad[4];
};

// STUB: 0x00a7f682
void Tcf_009666c9();
// GLOBAL: 0x00b635f4
extern uint32_t gGuard_009666c9;
// GLOBAL: 0x00b635a8
extern Single_009666c9 gObject_009666c9;
// GLOBAL: 0x00b635a8
extern uint8_t gAddress_009666c9[4];

// FUNCTION: 0x009666c9
Single_009666c9* Fn009666c9()
{
    if (!(gGuard_009666c9 & 1)) {
        gGuard_009666c9 |= 1;
        new (&gObject_009666c9) Single_009666c9();
        atexit(Tcf_009666c9);
    }
    return reinterpret_cast<Single_009666c9*>(gAddress_009666c9);
}

struct Single_00970c22 {
    // STUB: 0x00578390
    Single_00970c22();
    uint8_t mPad[4];
};

// STUB: 0x00a7f6c9
void Tcf_00970c22();
// GLOBAL: 0x00b63634
extern uint32_t gGuard_00970c22;
// GLOBAL: 0x00b63620
extern Single_00970c22 gObject_00970c22;
// GLOBAL: 0x00b63620
extern uint8_t gAddress_00970c22[4];

// FUNCTION: 0x00970c22
Single_00970c22* Fn00970c22()
{
    if (!(gGuard_00970c22 & 1)) {
        gGuard_00970c22 |= 1;
        new (&gObject_00970c22) Single_00970c22();
        atexit(Tcf_00970c22);
    }
    return reinterpret_cast<Single_00970c22*>(gAddress_00970c22);
}

struct Single_00975037 {
    // STUB: 0x00974fd4
    Single_00975037();
    uint8_t mPad[4];
};

// STUB: 0x00a7f6e4
void Tcf_00975037();
// GLOBAL: 0x00b6368c
extern uint32_t gGuard_00975037;
// GLOBAL: 0x00b63640
extern Single_00975037 gObject_00975037;
// GLOBAL: 0x00b63640
extern uint8_t gAddress_00975037[4];

// FUNCTION: 0x00975037
Single_00975037* Fn00975037()
{
    if (!(gGuard_00975037 & 1)) {
        gGuard_00975037 |= 1;
        new (&gObject_00975037) Single_00975037();
        atexit(Tcf_00975037);
    }
    return reinterpret_cast<Single_00975037*>(gAddress_00975037);
}

struct Single_00975363 {
    // STUB: 0x009751df
    Single_00975363();
    uint8_t mPad[4];
};

// STUB: 0x00a7f6ee
void Tcf_00975363();
// GLOBAL: 0x00b636dc
extern uint32_t gGuard_00975363;
// GLOBAL: 0x00b63690
extern Single_00975363 gObject_00975363;
// GLOBAL: 0x00b63690
extern uint8_t gAddress_00975363[4];

// FUNCTION: 0x00975363
Single_00975363* Fn00975363()
{
    if (!(gGuard_00975363 & 1)) {
        gGuard_00975363 |= 1;
        new (&gObject_00975363) Single_00975363();
        atexit(Tcf_00975363);
    }
    return reinterpret_cast<Single_00975363*>(gAddress_00975363);
}

struct Single_00998e48 {
    // STUB: 0x00998b90
    Single_00998e48();
    uint8_t mPad[4];
};

// STUB: 0x00a7f7ba
void Tcf_00998e48();
// GLOBAL: 0x00bac054
extern uint32_t gGuard_00998e48;
// GLOBAL: 0x00bac008
extern Single_00998e48 gObject_00998e48;
// GLOBAL: 0x00bac008
extern uint8_t gAddress_00998e48[4];

// FUNCTION: 0x00998e48
Single_00998e48* Fn00998e48()
{
    if (!(gGuard_00998e48 & 1)) {
        gGuard_00998e48 |= 1;
        new (&gObject_00998e48) Single_00998e48();
        atexit(Tcf_00998e48);
    }
    return reinterpret_cast<Single_00998e48*>(gAddress_00998e48);
}

struct Single_009da5fe {
    // STUB: 0x009da5bd
    Single_009da5fe();
    uint8_t mPad[4];
};

// STUB: 0x00a7f814
void Tcf_009da5fe();
// GLOBAL: 0x00bac134
extern uint32_t gGuard_009da5fe;
// GLOBAL: 0x00bac0e8
extern Single_009da5fe gObject_009da5fe;
// GLOBAL: 0x00bac0e8
extern uint8_t gAddress_009da5fe[4];

// FUNCTION: 0x009da5fe
Single_009da5fe* Fn009da5fe()
{
    if (!(gGuard_009da5fe & 1)) {
        gGuard_009da5fe |= 1;
        new (&gObject_009da5fe) Single_009da5fe();
        atexit(Tcf_009da5fe);
    }
    return reinterpret_cast<Single_009da5fe*>(gAddress_009da5fe);
}

