#include "common/types.h"
#include "common/compiler.h"
#include <stddef.h>
#include <new>

// The STL allocator of the original.
namespace _STL {
    // STUB: 0x0090cf54
    void* __stl_new(unsigned int size);
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

// The header-less node of an STL tree container.
struct Node_shape09_gzcom {
    uint8_t mPad[8];
    Node_shape09_gzcom* mpLeft;
    Node_shape09_gzcom* mpRight;
};

template <int N> struct Pad_shape09_gzcom { uint8_t mPad[N]; };
struct Tail_shape09_gzcom { uint32_t mTail; };


// STUB: 0x008d5245
uint32_t Fn008d54c2_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x008d54c2
uint32_t Fn008d54c2(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn008d54c2_callee(a, b, c, &flag, 0);
}

// STUB: 0x008f74d5
uint32_t Fn008f805e_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x008f805e
uint32_t Fn008f805e(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn008f805e_callee(a, b, c, &flag, 0);
}

// STUB: 0x0093aafa
uint32_t Fn0093afaa_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x0093afaa
uint32_t Fn0093afaa(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn0093afaa_callee(a, b, c, &flag, 0);
}

// STUB: 0x009a7626
uint32_t Fn009a8574_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009a8574
uint32_t Fn009a8574(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009a8574_callee(a, b, c, &flag, 0);
}

// STUB: 0x009b68f8
uint32_t Fn009b6a0f_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009b6a0f
uint32_t Fn009b6a0f(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009b6a0f_callee(a, b, c, &flag, 0);
}

// STUB: 0x009b692a
uint32_t Fn009b6a2c_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009b6a2c
uint32_t Fn009b6a2c(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009b6a2c_callee(a, b, c, &flag, 0);
}

// STUB: 0x009c017d
uint32_t Fn009c04ae_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009c04ae
uint32_t Fn009c04ae(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009c04ae_callee(a, b, c, &flag, 0);
}

// STUB: 0x009ca851
uint32_t Fn009cac1d_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009cac1d
uint32_t Fn009cac1d(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009cac1d_callee(a, b, c, &flag, 0);
}

// STUB: 0x009cba35
uint32_t Fn009cbaaa_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009cbaaa
uint32_t Fn009cbaaa(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009cbaaa_callee(a, b, c, &flag, 0);
}

// STUB: 0x009d5923
uint32_t Fn009d5973_callee(uint32_t a, uint32_t b, uint32_t c, void* flag, uint32_t zero);

// FUNCTION: 0x009d5973
uint32_t Fn009d5973(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t flag;
    return Fn009d5973_callee(a, b, c, &flag, 0);
}

struct Value_0087bf21 {
    // STUB: 0x0087bee4
    void Copy(const void* source);
};

struct Item_0087bf21 {
    uint8_t mPad[16];
    Value_0087bf21 mValue;
};

// FUNCTION: 0x0087bf21
Item_0087bf21* OB_STDCALL Fn0087bf21(const void* source)
{
    Item_0087bf21* node = static_cast<Item_0087bf21*>(_STL::__stl_new(0x38));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_008f7fd1 {
    // STUB: 0x008f72fd
    void Copy(const void* source);
};

struct Item_008f7fd1 {
    uint8_t mPad[8];
    Value_008f7fd1 mValue;
};

// FUNCTION: 0x008f7fd1
Item_008f7fd1* OB_STDCALL Fn008f7fd1(const void* source)
{
    Item_008f7fd1* node = static_cast<Item_008f7fd1*>(_STL::__stl_new(0x58));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_009004f8 {
    // STUB: 0x008ffe6a
    void Copy(const void* source);
};

struct Item_009004f8 {
    uint8_t mPad[16];
    Value_009004f8 mValue;
};

// FUNCTION: 0x009004f8
Item_009004f8* OB_STDCALL Fn009004f8(const void* source)
{
    Item_009004f8* node = static_cast<Item_009004f8*>(_STL::__stl_new(0x38));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_0092194f {
    // STUB: 0x009217f2
    void Copy(const void* source);
};

struct Item_0092194f {
    uint8_t mPad[8];
    Value_0092194f mValue;
};

// FUNCTION: 0x0092194f
Item_0092194f* OB_STDCALL Fn0092194f(const void* source)
{
    Item_0092194f* node = static_cast<Item_0092194f*>(_STL::__stl_new(0x24));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Obj_0092ea44 : Pad_shape09_gzcom<4>, Tail_shape09_gzcom {
    // STUB: 0x0092e714
    Obj_0092ea44* Construct();
};

// FUNCTION: 0x0092ea44
Tail_shape09_gzcom* Fn0092ea44()
{
    void* mem = operator new(0x38);
    Obj_0092ea44* obj = mem ? static_cast<Obj_0092ea44*>(mem)->Construct() : 0;
    return obj;
}

struct Value_0092f0af {
    // STUB: 0x0097bf85
    void Copy(const void* source);
};

struct Item_0092f0af {
    uint8_t mPad[8];
    Value_0092f0af mValue;
};

// FUNCTION: 0x0092f0af
Item_0092f0af* OB_STDCALL Fn0092f0af(const void* source)
{
    Item_0092f0af* node = static_cast<Item_0092f0af*>(_STL::__stl_new(0x18));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_0093460f {
    // STUB: 0x00934573
    void Copy(const void* source);
};

struct Item_0093460f {
    uint8_t mPad[8];
    Value_0093460f mValue;
};

// FUNCTION: 0x0093460f
Item_0093460f* OB_STDCALL Fn0093460f(const void* source)
{
    Item_0093460f* node = static_cast<Item_0093460f*>(_STL::__stl_new(0x34));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_00934878 {
    // STUB: 0x009ca065
    void Copy(const void* source);
};

struct Item_00934878 {
    uint8_t mPad[16];
    Value_00934878 mValue;
};

// FUNCTION: 0x00934878
Item_00934878* OB_STDCALL Fn00934878(const void* source)
{
    Item_00934878* node = static_cast<Item_00934878*>(_STL::__stl_new(0x28));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_009560dd {
    // STUB: 0x009550c3
    void Copy(const void* source);
};

struct Item_009560dd {
    uint8_t mPad[8];
    Value_009560dd mValue;
};

// FUNCTION: 0x009560dd
Item_009560dd* OB_STDCALL Fn009560dd(const void* source)
{
    Item_009560dd* node = static_cast<Item_009560dd*>(_STL::__stl_new(0x70));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_009560fe {
    // STUB: 0x009ca065
    void Copy(const void* source);
};

struct Item_009560fe {
    uint8_t mPad[8];
    Value_009560fe mValue;
};

// FUNCTION: 0x009560fe
Item_009560fe* OB_STDCALL Fn009560fe(const void* source)
{
    Item_009560fe* node = static_cast<Item_009560fe*>(_STL::__stl_new(0x20));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_0095619a {
    // STUB: 0x009541d8
    void Copy(const void* source);
};

struct Item_0095619a {
    uint8_t mPad[16];
    Value_0095619a mValue;
};

// FUNCTION: 0x0095619a
Item_0095619a* OB_STDCALL Fn0095619a(const void* source)
{
    Item_0095619a* node = static_cast<Item_0095619a*>(_STL::__stl_new(0x24));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_009561bb {
    // STUB: 0x009541f5
    void Copy(const void* source);
};

struct Item_009561bb {
    uint8_t mPad[16];
    Value_009561bb mValue;
};

// FUNCTION: 0x009561bb
Item_009561bb* OB_STDCALL Fn009561bb(const void* source)
{
    Item_009561bb* node = static_cast<Item_009561bb*>(_STL::__stl_new(0x24));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_00956269 {
    // STUB: 0x004b6100
    void Copy(const void* source);
};

struct Item_00956269 {
    uint8_t mPad[16];
    Value_00956269 mValue;
};

// FUNCTION: 0x00956269
Item_00956269* OB_STDCALL Fn00956269(const void* source)
{
    Item_00956269* node = static_cast<Item_00956269*>(_STL::__stl_new(0x28));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_0095628a {
    // STUB: 0x00662ab0
    void Copy(const void* source);
};

struct Item_0095628a {
    uint8_t mPad[16];
    Value_0095628a mValue;
};

// FUNCTION: 0x0095628a
Item_0095628a* OB_STDCALL Fn0095628a(const void* source)
{
    Item_0095628a* node = static_cast<Item_0095628a*>(_STL::__stl_new(0x28));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_00959f5a {
    // STUB: 0x00959f3d
    void Copy(const void* source);
};

struct Item_00959f5a {
    uint8_t mPad[16];
    Value_00959f5a mValue;
};

// FUNCTION: 0x00959f5a
Item_00959f5a* OB_STDCALL Fn00959f5a(const void* source)
{
    Item_00959f5a* node = static_cast<Item_00959f5a*>(_STL::__stl_new(0x24));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_00973648 {
    // STUB: 0x00966956
    void Copy(const void* source);
};

struct Item_00973648 {
    uint8_t mPad[8];
    Value_00973648 mValue;
};

// FUNCTION: 0x00973648
Item_00973648* OB_STDCALL Fn00973648(const void* source)
{
    Item_00973648* node = static_cast<Item_00973648*>(_STL::__stl_new(0xc));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_0098433c {
    // STUB: 0x0092ee7c
    void Copy(const void* source);
};

struct Item_0098433c {
    uint8_t mPad[16];
    Value_0098433c mValue;
};

// FUNCTION: 0x0098433c
Item_0098433c* OB_STDCALL Fn0098433c(const void* source)
{
    Item_0098433c* node = static_cast<Item_0098433c*>(_STL::__stl_new(0x24));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_009ab839 {
    // STUB: 0x009ab44d
    void Copy(const void* source);
};

struct Item_009ab839 {
    uint8_t mPad[16];
    Value_009ab839 mValue;
};

// FUNCTION: 0x009ab839
Item_009ab839* OB_STDCALL Fn009ab839(const void* source)
{
    Item_009ab839* node = static_cast<Item_009ab839*>(_STL::__stl_new(0x24));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_009ab85a {
    // STUB: 0x009ab430
    void Copy(const void* source);
};

struct Item_009ab85a {
    uint8_t mPad[16];
    Value_009ab85a mValue;
};

// FUNCTION: 0x009ab85a
Item_009ab85a* OB_STDCALL Fn009ab85a(const void* source)
{
    Item_009ab85a* node = static_cast<Item_009ab85a*>(_STL::__stl_new(0x24));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_009ccb01 {
    // STUB: 0x004e4bb0
    void Copy(const void* source);
};

struct Item_009ccb01 {
    uint8_t mPad[8];
    Value_009ccb01 mValue;
};

// FUNCTION: 0x009ccb01
Item_009ccb01* OB_STDCALL Fn009ccb01(const void* source)
{
    Item_009ccb01* node = static_cast<Item_009ccb01*>(_STL::__stl_new(0xc));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_009d7729 {
    // STUB: 0x009d76ce
    void Copy(const void* source);
};

struct Item_009d7729 {
    uint8_t mPad[8];
    Value_009d7729 mValue;
};

// FUNCTION: 0x009d7729
Item_009d7729* OB_STDCALL Fn009d7729(const void* source)
{
    Item_009d7729* node = static_cast<Item_009d7729*>(_STL::__stl_new(0x30));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Value_009dbb21 {
    // STUB: 0x0092ee7c
    void Copy(const void* source);
};

struct Item_009dbb21 {
    uint8_t mPad[8];
    Value_009dbb21 mValue;
};

// FUNCTION: 0x009dbb21
Item_009dbb21* OB_STDCALL Fn009dbb21(const void* source)
{
    Item_009dbb21* node = static_cast<Item_009dbb21*>(_STL::__stl_new(0x1c));
    if (&node->mValue) {
        node->mValue.Copy(source);
    }
    return node;
}

struct Obj_009456a4 : Pad_shape09_gzcom<4>, Tail_shape09_gzcom {
    // STUB: 0x009489ae
    Obj_009456a4* Construct();
};

// FUNCTION: 0x009456a4
Tail_shape09_gzcom* Fn009456a4()
{
    void* mem = operator new(0x4144);
    Obj_009456a4* obj = mem ? static_cast<Obj_009456a4*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_009456c8 : Pad_shape09_gzcom<4>, Tail_shape09_gzcom {
    // STUB: 0x00949902
    Obj_009456c8* Construct();
};

// FUNCTION: 0x009456c8
Tail_shape09_gzcom* Fn009456c8()
{
    void* mem = operator new(0x190);
    Obj_009456c8* obj = mem ? static_cast<Obj_009456c8*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_00975091 : Pad_shape09_gzcom<4>, Tail_shape09_gzcom {
    // STUB: 0x0097212d
    Obj_00975091* Construct();
};

// FUNCTION: 0x00975091
Tail_shape09_gzcom* Fn00975091()
{
    void* mem = operator new(0x1c8);
    Obj_00975091* obj = mem ? static_cast<Obj_00975091*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_0099893d : Pad_shape09_gzcom<4>, Tail_shape09_gzcom {
    // STUB: 0x009cbbff
    Obj_0099893d* Construct();
};

// FUNCTION: 0x0099893d
Tail_shape09_gzcom* Fn0099893d()
{
    void* mem = operator new(0x110);
    Obj_0099893d* obj = mem ? static_cast<Obj_0099893d*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_0099897a : Pad_shape09_gzcom<8>, Tail_shape09_gzcom {
    // STUB: 0x009ccf9c
    Obj_0099897a* Construct();
};

// FUNCTION: 0x0099897a
Tail_shape09_gzcom* Fn0099897a()
{
    void* mem = operator new(0x108);
    Obj_0099897a* obj = mem ? static_cast<Obj_0099897a*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_00998a64 : Pad_shape09_gzcom<4>, Tail_shape09_gzcom {
    // STUB: 0x009d2bf0
    Obj_00998a64* Construct();
};

// FUNCTION: 0x00998a64
Tail_shape09_gzcom* Fn00998a64()
{
    void* mem = operator new(0x1c4);
    Obj_00998a64* obj = mem ? static_cast<Obj_00998a64*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_008fbdbd : Pad_shape09_gzcom<216>, Tail_shape09_gzcom {
    // STUB: 0x008fbc38
    Obj_008fbdbd* Construct();
};

// FUNCTION: 0x008fbdbd
Tail_shape09_gzcom* Fn008fbdbd()
{
    void* mem = operator new(0x468);
    Obj_008fbdbd* obj = mem ? static_cast<Obj_008fbdbd*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_0094afa6 : Pad_shape09_gzcom<216>, Tail_shape09_gzcom {
    // STUB: 0x0095bab3
    Obj_0094afa6* Construct();
};

// FUNCTION: 0x0094afa6
Tail_shape09_gzcom* Fn0094afa6()
{
    void* mem = operator new(0xdc);
    Obj_0094afa6* obj = mem ? static_cast<Obj_0094afa6*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_00998a88 : Pad_shape09_gzcom<216>, Tail_shape09_gzcom {
    // STUB: 0x009d5990
    Obj_00998a88* Construct();
};

// FUNCTION: 0x00998a88
Tail_shape09_gzcom* Fn00998a88()
{
    void* mem = operator new(0x198);
    Obj_00998a88* obj = mem ? static_cast<Obj_00998a88*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_009c5973 : Pad_shape09_gzcom<216>, Tail_shape09_gzcom {
    // STUB: 0x009c5327
    Obj_009c5973* Construct();
};

// FUNCTION: 0x009c5973
Tail_shape09_gzcom* Fn009c5973()
{
    void* mem = operator new(0x170);
    Obj_009c5973* obj = mem ? static_cast<Obj_009c5973*>(mem)->Construct() : 0;
    return obj;
}

struct Obj_009c7dff : Pad_shape09_gzcom<216>, Tail_shape09_gzcom {
    // STUB: 0x009c7bb8
    Obj_009c7dff* Construct();
};

// FUNCTION: 0x009c7dff
Tail_shape09_gzcom* Fn009c7dff()
{
    void* mem = operator new(0x11c);
    Obj_009c7dff* obj = mem ? static_cast<Obj_009c7dff*>(mem)->Construct() : 0;
    return obj;
}

struct View_0087b3e2_shape09_gzcom {
    void Fn0087b3e2(Node_shape09_gzcom* node);
};

// FUNCTION: 0x0087b3e2
void View_0087b3e2_shape09_gzcom::Fn0087b3e2(Node_shape09_gzcom* node)
{
    while (node) {
        Fn0087b3e2(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_0089753f_shape09_gzcom {
    void Fn0089753f(Node_shape09_gzcom* node);
};

// FUNCTION: 0x0089753f
void View_0089753f_shape09_gzcom::Fn0089753f(Node_shape09_gzcom* node)
{
    while (node) {
        Fn0089753f(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_0089756c_shape09_gzcom {
    void Fn0089756c(Node_shape09_gzcom* node);
};

// FUNCTION: 0x0089756c
void View_0089756c_shape09_gzcom::Fn0089756c(Node_shape09_gzcom* node)
{
    while (node) {
        Fn0089756c(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_008fe9ac_shape09_gzcom {
    void Fn008fe9ac(Node_shape09_gzcom* node);
};

// FUNCTION: 0x008fe9ac
void View_008fe9ac_shape09_gzcom::Fn008fe9ac(Node_shape09_gzcom* node)
{
    while (node) {
        Fn008fe9ac(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_00922753_shape09_gzcom {
    void Fn00922753(Node_shape09_gzcom* node);
};

// FUNCTION: 0x00922753
void View_00922753_shape09_gzcom::Fn00922753(Node_shape09_gzcom* node)
{
    while (node) {
        Fn00922753(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_00937af1_shape09_gzcom {
    void Fn00937af1(Node_shape09_gzcom* node);
};

// FUNCTION: 0x00937af1
void View_00937af1_shape09_gzcom::Fn00937af1(Node_shape09_gzcom* node)
{
    while (node) {
        Fn00937af1(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_00937b1e_shape09_gzcom {
    void Fn00937b1e(Node_shape09_gzcom* node);
};

// FUNCTION: 0x00937b1e
void View_00937b1e_shape09_gzcom::Fn00937b1e(Node_shape09_gzcom* node)
{
    while (node) {
        Fn00937b1e(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_00937b4b_shape09_gzcom {
    void Fn00937b4b(Node_shape09_gzcom* node);
};

// FUNCTION: 0x00937b4b
void View_00937b4b_shape09_gzcom::Fn00937b4b(Node_shape09_gzcom* node)
{
    while (node) {
        Fn00937b4b(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_00937b78_shape09_gzcom {
    void Fn00937b78(Node_shape09_gzcom* node);
};

// FUNCTION: 0x00937b78
void View_00937b78_shape09_gzcom::Fn00937b78(Node_shape09_gzcom* node)
{
    while (node) {
        Fn00937b78(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_0094c86e_shape09_gzcom {
    void Fn0094c86e(Node_shape09_gzcom* node);
};

// FUNCTION: 0x0094c86e
void View_0094c86e_shape09_gzcom::Fn0094c86e(Node_shape09_gzcom* node)
{
    while (node) {
        Fn0094c86e(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_0094c89b_shape09_gzcom {
    void Fn0094c89b(Node_shape09_gzcom* node);
};

// FUNCTION: 0x0094c89b
void View_0094c89b_shape09_gzcom::Fn0094c89b(Node_shape09_gzcom* node)
{
    while (node) {
        Fn0094c89b(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_0094c8c8_shape09_gzcom {
    void Fn0094c8c8(Node_shape09_gzcom* node);
};

// FUNCTION: 0x0094c8c8
void View_0094c8c8_shape09_gzcom::Fn0094c8c8(Node_shape09_gzcom* node)
{
    while (node) {
        Fn0094c8c8(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_0096a4ca_shape09_gzcom {
    void Fn0096a4ca(Node_shape09_gzcom* node);
};

// FUNCTION: 0x0096a4ca
void View_0096a4ca_shape09_gzcom::Fn0096a4ca(Node_shape09_gzcom* node)
{
    while (node) {
        Fn0096a4ca(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_00981219_shape09_gzcom {
    void Fn00981219(Node_shape09_gzcom* node);
};

// FUNCTION: 0x00981219
void View_00981219_shape09_gzcom::Fn00981219(Node_shape09_gzcom* node)
{
    while (node) {
        Fn00981219(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_00981246_shape09_gzcom {
    void Fn00981246(Node_shape09_gzcom* node);
};

// FUNCTION: 0x00981246
void View_00981246_shape09_gzcom::Fn00981246(Node_shape09_gzcom* node)
{
    while (node) {
        Fn00981246(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_00984298_shape09_gzcom {
    void Fn00984298(Node_shape09_gzcom* node);
};

// FUNCTION: 0x00984298
void View_00984298_shape09_gzcom::Fn00984298(Node_shape09_gzcom* node)
{
    while (node) {
        Fn00984298(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_009a8446_shape09_gzcom {
    void Fn009a8446(Node_shape09_gzcom* node);
};

// FUNCTION: 0x009a8446
void View_009a8446_shape09_gzcom::Fn009a8446(Node_shape09_gzcom* node)
{
    while (node) {
        Fn009a8446(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_009a8473_shape09_gzcom {
    void Fn009a8473(Node_shape09_gzcom* node);
};

// FUNCTION: 0x009a8473
void View_009a8473_shape09_gzcom::Fn009a8473(Node_shape09_gzcom* node)
{
    while (node) {
        Fn009a8473(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_009a84cd_shape09_gzcom {
    void Fn009a84cd(Node_shape09_gzcom* node);
};

// FUNCTION: 0x009a84cd
void View_009a84cd_shape09_gzcom::Fn009a84cd(Node_shape09_gzcom* node)
{
    while (node) {
        Fn009a84cd(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

struct View_009db96b_shape09_gzcom {
    void Fn009db96b(Node_shape09_gzcom* node);
};

// FUNCTION: 0x009db96b
void View_009db96b_shape09_gzcom::Fn009db96b(Node_shape09_gzcom* node)
{
    while (node) {
        Fn009db96b(node->mpRight);
        Node_shape09_gzcom* next = node->mpLeft;
        _STL::__stl_delete(node);
        node = next;
    }
}

