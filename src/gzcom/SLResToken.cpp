#include <stddef.h>
#include <new>
#include <stdio.h>

#include "gzcom/cRZString.h"

#include "classes/cSLTokenSerialRecordIO_Text.h"
#include "classes/cSLTokenResourceFactory.h"
#include "classes/cSLTokenRecord.h"
#include "classes/cUnk00ad9bc8.h"
#include "classes/cUnk00ad9c20.h"
#include "classes/cUnk00ad9cd0.h"
#include "classes/cUnk00ad9d28.h"
#include "classes/cUnk00ad9d80.h"
#include "classes/cUnk00ad9dd8.h"
#include "classes/cUnk00ad9e30.h"
#include "classes/cUnk00ad9f90.h"
#include "classes/cUnk00ad9f38.h"
#include "classes/cUnk00ad9ee0.h"
#include "classes/cUnk00ad9e88.h"
#include "classes/cUnk00ad9c78.h"

// The element arrays of the token fields: count (uint16) at +0xa, data pointer at +0x20.
#define SLRT_COUNT(p) (*reinterpret_cast<const uint16_t*>(reinterpret_cast<const char*>(p) + 0xa))
#define SLRT_DATA(p, T) (*reinterpret_cast<T**>(reinterpret_cast<char*>(p) + 0x20))

// The token stream the arrays read from and write to (cUnk00ad9978's slots, pointers as pointers).
struct IO_SLResToken {
    virtual void D00();
    virtual bool S01(void* p);
    virtual bool S02(void* p);
    virtual bool S03(void* p);
    virtual bool S04(void* p);
    virtual bool S05(void* p);
    virtual bool S06(void* p);
    virtual bool S07(void* p);
    virtual bool S08(void* p);
    virtual bool S09(void* p);
    virtual bool S10(void* p);
    virtual bool S11(void* p);
    virtual bool S12(void* p);
    virtual bool S13(void* p);
    virtual bool S14(void* p);
    virtual bool S15(void* p);
    virtual bool S16(void* p);
    virtual bool S17(void* p);
    virtual bool S18(void* p);
    virtual bool S19(void* p);
    virtual bool S20(void* p);
    virtual bool S21(void* p);
    virtual bool S22(void* p);
    virtual bool S23(void* p);
    virtual bool S24(void* p);
    virtual bool S25(void* p);
    virtual bool S26(void* p);
};

// A 12-byte element (a resource key).
struct Elem12_SLResToken {
    uint32_t v[3];
};

// A 20-byte element (a string).
struct Elem20_SLResToken {
    uint8_t b[20];
};

// An 8-byte element.
struct Quad_SLResToken {
    uint32_t lo;
    uint32_t hi;
};

// The serial record the cookie is read from (slot 13 reads the cookie).
struct Record_SLResToken {
    virtual void S00();
    virtual void S01();
    virtual void S02();
    virtual void S03();
    virtual void S04();
    virtual void S05();
    virtual void S06();
    virtual void S07();
    virtual void S08();
    virtual void S09();
    virtual void S10();
    virtual void S11();
    virtual void S12();
    virtual bool GetCookie(void* out);
};

// FUNCTION: 0x00980cc0
bool cSLTokenSerialRecordIO_Text::Slot03_ad9978(uint32_t a)
{
    return GetToken(OB_PTR(void, a), ',');
}

// FUNCTION: 0x00980db9
bool cSLTokenSerialRecordIO_Text::Slot09_ad9978(uint32_t a)
{
    return ReadULong(OB_PTR(void, a), ',');
}

// FUNCTION: 0x00980dc7
bool cSLTokenSerialRecordIO_Text::Slot08_ad9978(uint32_t a)
{
    return ReadLong(OB_PTR(void, a), ',');
}

// FUNCTION: 0x00980d81
bool cSLTokenSerialRecordIO_Text::Slot13_ad9978(uint32_t a)
{
    uint32_t v;
    bool r = ReadULong(&v, ',');
    *OB_PTR(uint8_t, a) = static_cast<uint8_t>(v);
    return r;
}

// FUNCTION: 0x00980d9c
bool cSLTokenSerialRecordIO_Text::Slot11_ad9978(uint32_t a)
{
    uint32_t v;
    bool r = ReadULong(&v, ',');
    *OB_PTR(uint16_t, a) = static_cast<uint16_t>(v);
    return r;
}

// FUNCTION: 0x0097f074
uint32_t cSLTokenResourceFactory::ReadCookie(uint32_t a)
{
    uint32_t v = 0;
    bool ok = OB_PTR(Record_SLResToken, a)->GetCookie(&v);
    return ok ? v : 0;
}

// FUNCTION: 0x0097fa08
bool cUnk00ad9bc8::Slot11_ad9b70(uint32_t out, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        *OB_PTR(uint8_t, out) = SLRT_DATA(this, uint8_t)[idx];
        return true;
    }
    return false;
}

// FUNCTION: 0x0097fa29
bool cUnk00ad9bc8::Slot20_ad9b70(uint32_t in, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        SLRT_DATA(this, uint8_t)[idx] = *OB_PTR(uint8_t, in);
        return true;
    }
    return false;
}

// FUNCTION: 0x0097fadb
bool cUnk00ad9c20::Slot10_ad9b70(uint32_t out, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        *OB_PTR(uint16_t, out) = SLRT_DATA(this, uint16_t)[idx];
        return true;
    }
    return false;
}

// FUNCTION: 0x0097fafe
bool cUnk00ad9c20::Slot19_ad9b70(uint32_t in, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        SLRT_DATA(this, uint16_t)[idx] = *OB_PTR(uint16_t, in);
        return true;
    }
    return false;
}

// FUNCTION: 0x0097fc36
bool cUnk00ad9cd0::Slot08_ad9b70(uint32_t out, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        *OB_PTR(uint32_t, out) = SLRT_DATA(this, uint32_t)[idx];
        return true;
    }
    return false;
}

// FUNCTION: 0x0097fc57
bool cUnk00ad9cd0::Slot17_ad9b70(uint32_t in, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        SLRT_DATA(this, uint32_t)[idx] = *OB_PTR(uint32_t, in);
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097fd0c score 21
bool cUnk00ad9d28::Slot07_ad9b70(uint32_t out, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        Quad_SLResToken* d = SLRT_DATA(this, Quad_SLResToken);
        Quad_SLResToken* o = OB_PTR(Quad_SLResToken, out);
        o->lo = d[idx].lo;
        o->hi = d[idx].hi;
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097fd36 score 21
bool cUnk00ad9d28::Slot16_ad9b70(uint32_t in, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        Quad_SLResToken* d = SLRT_DATA(this, Quad_SLResToken);
        Quad_SLResToken* s = OB_PTR(Quad_SLResToken, in);
        d[idx].lo = s->lo;
        d[idx].hi = s->hi;
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x0097fdf4
bool cUnk00ad9d80::Slot06_ad9b70(uint32_t out, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        *OB_PTR(float, out) = SLRT_DATA(this, float)[idx];
        return true;
    }
    return false;
}

// FUNCTION: 0x0097fe15
bool cUnk00ad9d80::Slot15_ad9b70(uint32_t in, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        SLRT_DATA(this, float)[idx] = *OB_PTR(float, in);
        return true;
    }
    return false;
}

// FUNCTION: 0x0097fee7
bool cUnk00ad9dd8::Slot03_ad9b70(uint32_t out, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        uint32_t* e = SLRT_DATA(this, uint32_t) + idx * 3;
        uint32_t* o = OB_PTR(uint32_t, out);
        o[0] = e[0];
        o[1] = e[1];
        o[2] = e[2];
        return true;
    }
    return false;
}

// FUNCTION: 0x0097ff19
bool cUnk00ad9dd8::Slot12_ad9b70(uint32_t in, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        uint32_t* e = SLRT_DATA(this, uint32_t) + idx * 3;
        uint32_t* s = OB_PTR(uint32_t, in);
        e[0] = s[0];
        e[1] = s[1];
        e[2] = s[2];
        return true;
    }
    return false;
}

// FUNCTION: 0x0097fa4a
void cUnk00ad9bc8::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S13(SLRT_DATA(this, uint8_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097fa7d
void cUnk00ad9bc8::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S26(SLRT_DATA(this, uint8_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097fb21
void cUnk00ad9c20::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S11(SLRT_DATA(this, uint16_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097fb55
void cUnk00ad9c20::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S24(SLRT_DATA(this, uint16_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097f0cd
void cUnk00ad9c78::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S22(SLRT_DATA(this, uint32_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097fbb5
void cUnk00ad9c78::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S09(SLRT_DATA(this, uint32_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097fc78
void cUnk00ad9cd0::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S08(SLRT_DATA(this, uint32_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097fcac
void cUnk00ad9cd0::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S21(SLRT_DATA(this, uint32_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097fd60
void cUnk00ad9d28::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S06(SLRT_DATA(this, Quad_SLResToken) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097fd94
void cUnk00ad9d28::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S19(SLRT_DATA(this, Quad_SLResToken) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097fe36
void cUnk00ad9d80::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S05(SLRT_DATA(this, uint32_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097fe6a
void cUnk00ad9d80::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S18(SLRT_DATA(this, uint32_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097ff4b
void cUnk00ad9dd8::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S02(SLRT_DATA(this, Elem12_SLResToken) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0097ff85
void cUnk00ad9dd8::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S15(SLRT_DATA(this, Elem12_SLResToken) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x00980069
void cUnk00ad9e30::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S03(SLRT_DATA(this, Elem20_SLResToken) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x009800a3
void cUnk00ad9e30::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S16(SLRT_DATA(this, Elem20_SLResToken) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x00980106
void cUnk00ad9e88::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S12(SLRT_DATA(this, uint8_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x00980139
void cUnk00ad9e88::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S25(SLRT_DATA(this, uint8_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x00980197
void cUnk00ad9ee0::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S10(SLRT_DATA(this, uint16_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x009801cb
void cUnk00ad9ee0::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S23(SLRT_DATA(this, uint16_t) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0098022b
void cUnk00ad9f38::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S07(SLRT_DATA(this, Quad_SLResToken) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x0098025f
void cUnk00ad9f38::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S20(SLRT_DATA(this, Quad_SLResToken) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x009802bf
void cUnk00ad9f90::Slot01_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S04(SLRT_DATA(this, Quad_SLResToken) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// FUNCTION: 0x009802f3
void cUnk00ad9f90::Slot02_ad9b70(uint32_t a)
{
    int32_t i = 0;
    bool ok = true;
    if (static_cast<uint32_t>(i) < SLRT_COUNT(this)) {
        do {
            if (!ok) {
                return;
            }
            ok = OB_PTR(IO_SLResToken, a)->S17(SLRT_DATA(this, Quad_SLResToken) + i);
            ++i;
        } while (i < SLRT_COUNT(this));
    }
}

// The managers hand out through a global accessor.
struct Mgr_SLResToken {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual bool S3(uint32_t a, uint32_t b, uint32_t c);
};

// STUB: 0x0090ddf1
Mgr_SLResToken* Fn0090ddf1();

// The stream the text is read from (slot 27 reads bytes).
struct ByteSource_SLResToken {
    virtual void B00();
    virtual void B01();
    virtual void B02();
    virtual void B03();
    virtual void B04();
    virtual void B05();
    virtual void B06();
    virtual void B07();
    virtual void B08();
    virtual void B09();
    virtual void B10();
    virtual void B11();
    virtual void B12();
    virtual void B13();
    virtual void B14();
    virtual void B15();
    virtual void B16();
    virtual void B17();
    virtual void B18();
    virtual void B19();
    virtual void B20();
    virtual void B21();
    virtual void B22();
    virtual void B23();
    virtual void B24();
    virtual void B25();
    virtual void B26();
    virtual bool Read(void* out, uint32_t length);
};

// FUNCTION: 0x0097f0b8
bool cSLTokenResourceFactory::Slot09_ad8c20(uint32_t a, uint32_t b, uint32_t c)
{
    Mgr_SLResToken* m = Fn0090ddf1();
    if (m) {
        return m->S3(a, b, c);
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097f0a6 score 8
cSLTokenResourceFactory::cSLTokenResourceFactory()
{
}
#endif

// A red-black tree node of the set of token ids and the tree itself (the original's STL).
struct Node_SLResToken {
    uint32_t color;
    Node_SLResToken* parent;
    Node_SLResToken* left;
    Node_SLResToken* right;
    uint8_t value;
};

struct Iter_SLResToken {
    Node_SLResToken* node;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// STUB: 0x0040d4c0
Node_SLResToken* Fn0040d4c0(Node_SLResToken* p);

struct Tree_SLResToken {
    Node_SLResToken* header;
    uint32_t count;
    // STUB: 0x00927cf8
    void Fn00927cf8(Iter_SLResToken it);
    void Fn0097f123(Node_SLResToken* x);
    void Fn0097f150();
    void Fn0097f179();
    void Fn0097f190(Iter_SLResToken first, Iter_SLResToken last);
    void Fn0097f3f6(Iter_SLResToken first, Iter_SLResToken last);
};

// FUNCTION: 0x0097f123
void Tree_SLResToken::Fn0097f123(Node_SLResToken* x)
{
    while (x) {
        Fn0097f123(x->right);
        Node_SLResToken* l = x->left;
        Fn0090cf63(x);
        x = l;
    }
}

// FUNCTION: 0x0097f150
void Tree_SLResToken::Fn0097f150()
{
    if (count != 0) {
        Fn0097f123(header->parent);
        header->left = header;
        header->parent = 0;
        header->right = header;
        count = 0;
    }
}

// FUNCTION: 0x0097f179
void Tree_SLResToken::Fn0097f179()
{
    Fn0097f150();
    if (header) {
        Fn0090cf63(header);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097f190 score 36
void Tree_SLResToken::Fn0097f190(Iter_SLResToken first, Iter_SLResToken last)
{
    if (first.node == header->left && last.node == header) {
        Fn0097f150();
    } else {
        while (first.node != last.node) {
            Iter_SLResToken cur = first;
            first.node = Fn0040d4c0(first.node);
            Fn00927cf8(cur);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097f3f6 score 11
void Tree_SLResToken::Fn0097f3f6(Iter_SLResToken first, Iter_SLResToken last)
{
    Fn0097f190(first, last);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00980343 score 3
cUnk00ad9bc8::~cUnk00ad9bc8()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00980380 score 3
cUnk00ad9c20::~cUnk00ad9c20()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009803d9 score 3
cUnk00ad9cd0::~cUnk00ad9cd0()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00980416 score 3
cUnk00ad9d28::~cUnk00ad9d28()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00980453 score 3
cUnk00ad9d80::~cUnk00ad9d80()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00980490 score 3
cUnk00ad9dd8::~cUnk00ad9dd8()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00980520 score 3
cUnk00ad9e88::~cUnk00ad9e88()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098055d score 3
cUnk00ad9ee0::~cUnk00ad9ee0()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098059a score 3
cUnk00ad9f38::~cUnk00ad9f38()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009805d7 score 3
cUnk00ad9f90::~cUnk00ad9f90()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

struct SerialRecord_SLResToken {
    virtual void R00();
    virtual void R01();
    virtual void R02();
    virtual void R03();
    virtual void R04();
    virtual void R05();
    virtual void R06();
    virtual void R07();
    virtual void R08();
    virtual void R09();
    virtual void R10();
    virtual void R11();
    virtual void R12();
    virtual void R13();
    virtual void R14();
    virtual void R15();
    virtual void R16();
    virtual void R17();
    virtual void R18();
    virtual void R19();
    virtual void R20();
    virtual void R21();
    virtual void R22();
    virtual void R23();
    virtual void R24();
    virtual void R25();
    virtual void R26();
    virtual void R27();
    virtual void R28();
    virtual void R29();
    virtual void R30();
    virtual void R31();
    virtual void R32();
    virtual void R33();
    virtual void R34();
    virtual void R35();
    virtual void R36();
    virtual void R37();
    virtual void R38();
    virtual void R39();
    virtual void R40();
    virtual void R41();
    virtual void R42();
    virtual void R43();
    virtual void R44();
    virtual void R45();
    virtual void R46();
    virtual void R47();
    virtual void R48();
    virtual void R49();
    virtual void R50();
    virtual bool Write(const char* data, uint32_t length);
};

// FUNCTION: 0x0097f5e4
bool cSLTokenSerialRecordIO_Text::Slot26_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%u, ", (uint32_t)*OB_PTR(uint8_t, a));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f639
bool cSLTokenSerialRecordIO_Text::Slot25_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%d, ", (int32_t)*OB_PTR(int8_t, a));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f68e
bool cSLTokenSerialRecordIO_Text::Slot24_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%u, ", (uint32_t)*OB_PTR(uint16_t, a));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f6e3
bool cSLTokenSerialRecordIO_Text::Slot23_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%d, ", (int32_t)*OB_PTR(int16_t, a));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f738
bool cSLTokenSerialRecordIO_Text::Slot22_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%u, ", *OB_PTR(uint32_t, a));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f78b
bool cSLTokenSerialRecordIO_Text::Slot21_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%d, ", *OB_PTR(int32_t, a));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f7de
bool cSLTokenSerialRecordIO_Text::Slot20_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%I64u, ", *OB_PTR(uint64_t, a));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f834
bool cSLTokenSerialRecordIO_Text::Slot19_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%I64d, ", *OB_PTR(int64_t, a));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f88a
bool cSLTokenSerialRecordIO_Text::Slot18_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%f, ", (double)*OB_PTR(float, a));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f8e2
bool cSLTokenSerialRecordIO_Text::Slot17_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%g, ", *OB_PTR(double, a));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f93a
bool cSLTokenSerialRecordIO_Text::Slot16_ad9978(uint32_t a)
{
    cRZString s;
    s.Sprintf("%s, ", OB_PTR(cRZString, a)->ToChar());
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097f5b7
bool cSLTokenSerialRecordIO_Text::WriteToSerialRecord(void* p)
{
    SerialRecord_SLResToken*& rec = *reinterpret_cast<SerialRecord_SLResToken**>(reinterpret_cast<char*>(this) + 4);
    cRZString* str = static_cast<cRZString*>(p);
    return rec->Write(str->ToChar(), str->Strlen());
}
// FUNCTION: 0x00980b19
bool cSLTokenSerialRecordIO_Text::ReadULong(void* p, int8_t delim)
{
    cRZString s;
    bool ok = GetToken(&s, delim);
    if (ok) {
        uint32_t* out = static_cast<uint32_t*>(p);
        int n = sscanf(s.c_str(), "%u", out);
        if (n == -1 || n != 1) {
            ok = false;
            *out = 0;
        }
    }
    return ok;
}

// FUNCTION: 0x00980dd5
bool cSLTokenSerialRecordIO_Text::ReadLong(void* p, int8_t delim)
{
    cRZString s;
    bool ok = GetToken(&s, delim);
    if (ok) {
        int32_t* out = static_cast<int32_t*>(p);
        int n = sscanf(s.c_str(), "%d", out);
        if (n == -1 || n != 1) {
            ok = false;
            *out = 0;
        }
    }
    return ok;
}

// FUNCTION: 0x00980b80
bool cSLTokenSerialRecordIO_Text::Slot06_ad9978(uint32_t a)
{
    cRZString s;
    bool ok = GetToken(&s, ',');
    if (ok) {
        long long* out = OB_PTR(long long, a);
        int n = sscanf(s.c_str(), OB_SCN_INT64, out);
        if (n == -1 || n != 1) {
            ok = false;
            *out = 0;
        }
    }
    return ok;
}

// FUNCTION: 0x00980bea
bool cSLTokenSerialRecordIO_Text::Slot05_ad9978(uint32_t a)
{
    cRZString s;
    bool ok = GetToken(&s, ',');
    if (ok) {
        double d;
        int n = sscanf(s.c_str(), "%lf", &d);
        float* out = OB_PTR(float, a);
        *out = static_cast<float>(d);
        if (n == -1 || n != 1) {
            *out = 0.0f;
            ok = false;
        }
    }
    return ok;
}

// FUNCTION: 0x00980c59
bool cSLTokenSerialRecordIO_Text::Slot04_ad9978(uint32_t a)
{
    cRZString s;
    bool ok = GetToken(&s, ',');
    if (ok) {
        double* out = OB_PTR(double, a);
        int n = sscanf(s.c_str(), "%lf", out);
        if (n == -1 || n != 1) {
            *out = 0.0;
            ok = false;
        }
    }
    return ok;
}

// FUNCTION: 0x0097ef35
bool cSLTokenSerialRecordIO_Text::ReadByte(void* out)
{
    char* self = reinterpret_cast<char*>(this);
    uint32_t& pos = *reinterpret_cast<uint32_t*>(self + 8);
    ++pos;
    if (pos < *reinterpret_cast<uint32_t*>(self + 0xc)) {
        if ((*reinterpret_cast<ByteSource_SLResToken**>(self + 4))->Read(out, 1)) {
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x00980a41
bool cSLTokenSerialRecordIO_Text::GetToken(void* p, int8_t delim)
{
    cRZString* str = static_cast<cRZString*>(p);
    char c;
    str->erase(0, std::string::npos);
    bool more;
    do {
        more = ReadByte(&c);
        if (c == delim) {
            str->push_back(0);
            str->Trim();
            return true;
        }
        if (c == ';') {
            while (c != '\r') {
                if (!more) {
                    return false;
                }
                more = ReadByte(&c);
            }
        } else if (c != '\n') {
            if (c == '\r' || c == '\t') {
                c = ' ';
            }
            str->push_back(c);
        }
    } while (more);
    return false;
}

// A token definition: three words (a type, two ids) as the text format writes them.
struct TokenDef_SLResToken {
    uint32_t mnType;
    uint16_t mnGroup;
    uint16_t mnId;
};

// FUNCTION: 0x00980cce
bool cSLTokenSerialRecordIO_Text::Slot01_ad9978(uint32_t a)
{
    cRZString s;
    bool ok = GetToken(&s, '[');
    uint32_t type = 0;
    if (ok) {
        ok = ReadULong(&type, ',');
    }
    uint32_t group = 0;
    if (ok) {
        ok = ReadULong(&group, ',');
    }
    uint32_t id = 0;
    if (ok) {
        ok = ReadULong(&id, ']');
        if (ok) {
            ok = GetToken(&s, '=');
            if (ok) {
                TokenDef_SLResToken* def = OB_PTR(TokenDef_SLResToken, a);
                def->mnType = type;
                def->mnGroup = static_cast<uint16_t>(group);
                def->mnId = static_cast<uint16_t>(id);
            }
        }
    }
    return ok;
}

// FUNCTION: 0x0097f54d
bool cSLTokenSerialRecordIO_Text::Slot14_ad9978(uint32_t a, uint32_t b)
{
    cRZString s;
    TokenDef_SLResToken* def = OB_PTR(TokenDef_SLResToken, b);
    s.Sprintf("%c%c%s[ %d, %d, %d ]= ", 13, 10, OB_PTR(cRZString, a)->ToChar(), def->mnType, static_cast<uint32_t>(def->mnGroup), static_cast<uint32_t>(def->mnId));
    bool r = WriteToSerialRecord(&s);
    return r;
}

// FUNCTION: 0x0097ee9c
bool cSLTokenSerialRecordIO_Text::Slot02_ad9978(uint32_t a)
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    IO_SLResToken* io = reinterpret_cast<IO_SLResToken*>(this);
    bool r = io->S09(&x);
    if (r) {
        r = io->S09(&y);
        if (r) {
            r = io->S09(&z);
            if (r) {
                uint32_t* k = OB_PTR(uint32_t, a);
                k[0] = x;
                k[1] = y;
                k[2] = z;
            }
        }
    }
    return r;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097eeeb score 2
void cSLTokenSerialRecordIO_Text::Slot15_ad9978(uint32_t a)
{
    uint32_t* k = OB_PTR(uint32_t, a);
    IO_SLResToken* io = reinterpret_cast<IO_SLResToken*>(this);
    uint32_t v = k[0];
    bool r = io->S22(&v);
    v = k[1];
    if (r) {
        r = io->S22(&v);
        v = k[2];
        if (r) {
            io->S22(&v);
        }
    }
}
#endif

// FUNCTION: 0x0098000f
bool cUnk00ad9e30::Slot04_ad9b70(uint32_t out, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        cRZString* e = SLRT_DATA(this, cRZString) + idx;
        OB_PTR(cIGZString, out)->FromChar(static_cast<cIGZString*>(e)->ToChar());
        return true;
    }
    return false;
}

// FUNCTION: 0x00980042
bool cUnk00ad9e30::Slot13_ad9b70(uint32_t in, uint32_t idx)
{
    if (idx < SLRT_COUNT(this)) {
        cRZString* e = SLRT_DATA(this, cRZString) + idx;
        static_cast<cIGZString&>(*e) = *OB_PTR(cIGZString, in);
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097fbe9 score 3
cUnk00ad9c78::~cUnk00ad9c78()
{
    operator delete(SLRT_DATA(this, void));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009804cd score 3
cUnk00ad9e30::~cUnk00ad9e30()
{
    delete[] SLRT_DATA(this, cRZString);
}
#endif

// FUNCTION: 0x0098103b
cSLTokenRecord::~cSLTokenRecord()
{
    Shutdown();
    reinterpret_cast<Tree_SLResToken*>(reinterpret_cast<char*>(this) + 0x14)->Fn0097f179();
}

// The persist resource and its record sink as the factory calls them.
struct Sink_SLResToken {
    virtual bool QueryInterface(uint32_t iid, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual bool Take(void* record);
    virtual bool Put(void* record);
    virtual bool S5();
    virtual bool IsText();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0097f439 score 15
bool cSLTokenResourceFactory::Slot10_ad8c20(uint32_t a, uint32_t b)
{
    Sink_SLResToken* local = 0;
    bool ok = OB_PTR(Sink_SLResToken, a)->QueryInterface(0xa2ace668, reinterpret_cast<void**>(&local));
    if (ok) {
        uint32_t cookie = ReadCookie(b);
        if (cookie != 0) {
            cSLTokenRecord* r = new cSLTokenRecord;
            r->AddRef();
            ok = r->InitRead_2(b, cookie);
            if (ok) {
                ok = local->Take(r);
            }
            r->Release();
        }
    }
    if (local) {
        local->Release();
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097f4c4 score 17
bool cSLTokenResourceFactory::Slot11_ad8c20(uint32_t a, uint32_t b)
{
    Sink_SLResToken* local = 0;
    bool ok = OB_PTR(Sink_SLResToken, a)->QueryInterface(0xa2ace668, reinterpret_cast<void**>(&local));
    if (ok) {
        bool text = local->IsText();
        cSLTokenRecord* r = new cSLTokenRecord;
        r->AddRef();
        if (text) {
            ok = r->InitWriteText(b);
        } else {
            ok = r->InitWriteBinary(b);
        }
        if (ok) {
            ok = local->Put(r);
        }
        r->Release();
    }
    if (local) {
        local->Release();
    }
    return ok;
}
#endif
