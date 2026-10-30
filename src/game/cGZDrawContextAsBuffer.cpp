#include <cstddef>

#include "classes/cGZDrawContextAsBuffer.h"

// A field of this object by its offset from the class start (the offsets of the ac14e8 slots (this at +0xc) have
// the base's offset added).
#define FLD_ac1550(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

struct Blk4_ac1550 {
    uint32_t w[4];
};

struct PixFmt_ac1550 {
    uint32_t mnFormat;
    uint32_t mnBits;
    uint32_t Fn00449500(uint32_t fmt);
};

struct Info6_ac1550 {
    uint32_t w[6];
};

// The object at +0x10 (a draw surface): its slots as the methods below call them.
struct OB_NOVTABLE P10_ac1550 {
    virtual void Pad00_ac1550();
    virtual void Slot01_ac1550() = 0;
    virtual void Slot02_ac1550() = 0;
    virtual void Slot03_ac1550() = 0;
    virtual void Pad04_ac1550();
    virtual void Slot05_ac1550(uint32_t a) = 0;
    virtual void Pad06_ac1550();
    virtual void Pad07_ac1550();
    virtual void Pad08_ac1550();
    virtual void Slot09_ac1550() = 0;
    virtual void Pad10_ac1550();
    virtual void Pad11_ac1550();
    virtual void Pad12_ac1550();
    virtual void Pad13_ac1550();
    virtual void Slot14_ac1550(void* a) = 0;
    virtual void Pad15_ac1550();
    virtual bool Slot16_ac1550() = 0;
    virtual void Slot17_ac1550(uint32_t a) = 0;
    virtual void Pad18_ac1550();
    virtual void Pad19_ac1550();
    virtual void Slot20_ac1550(uint32_t a, uint32_t b) = 0;
    virtual void Slot21_ac1550(uint32_t a) = 0;
    virtual void Pad22_ac1550();
    virtual void Pad23_ac1550();
    virtual void Pad24_ac1550();
    virtual void Slot25_ac1550(float a) = 0;
    virtual void Pad26_ac1550();
    virtual void Pad27_ac1550();
    virtual void Pad28_ac1550();
    virtual void Pad29_ac1550();
    virtual void Pad30_ac1550();
    virtual void Pad31_ac1550();
    virtual void Slot32_ac1550() = 0;
    virtual void Slot33_ac1550(uint32_t a, uint32_t b) = 0;
    virtual void Slot34_ac1550(uint32_t a, uint32_t b, uint32_t c, uint32_t d) = 0;
    virtual void Slot35_ac1550(uint32_t a) = 0;
    virtual void Pad36_ac1550();
    virtual void Pad37_ac1550();
    virtual void Slot38_ac1550(uint32_t a, void* b, void* c) = 0;
    virtual void Pad39_ac1550();
    virtual void Slot40_ac1550() = 0;
    virtual bool Slot41_ac1550() = 0;
    virtual void Slot42_ac1550() = 0;
    virtual void Slot43_ac1550() = 0;
    virtual void Slot44_ac1550(uint32_t a, void* b, uint32_t c) = 0;
    virtual void Pad45_ac1550();
    virtual bool Slot46_ac1550(void* a, uint32_t b) = 0;
};
// The object at +0x14 (the source).
struct OB_NOVTABLE P14_ac1550 {
    virtual void Pad00_ac1550();
    virtual void Slot01_ac1550() = 0;
    virtual void Slot02_ac1550() = 0;
    virtual void Pad03_ac1550();
    virtual void Pad04_ac1550();
    virtual void Pad05_ac1550();
    virtual void Pad06_ac1550();
    virtual void Pad07_ac1550();
    virtual void Pad08_ac1550();
    virtual void Pad09_ac1550();
    virtual void Pad10_ac1550();
    virtual void Pad11_ac1550();
    virtual uint32_t* Slot12_ac1550() = 0;
    virtual void Pad13_ac1550();
    virtual void Pad14_ac1550();
    virtual uint32_t* Slot15_ac1550(uint32_t* a) = 0;
    virtual void Pad16_ac1550();
    virtual uint32_t Slot17_ac1550() = 0;
    virtual void Pad18_ac1550();
    virtual void Pad19_ac1550();
    virtual void Pad20_ac1550();
    virtual void Pad21_ac1550();
    virtual void Pad22_ac1550();
    virtual void Pad23_ac1550();
    virtual void Pad24_ac1550();
    virtual void Pad25_ac1550();
    virtual bool Slot26_ac1550(void* a) = 0;
};
// The same object's slots reached by a tail jump (no arguments).
struct OB_NOVTABLE P14t_ac1550 {
    virtual void Pad00_ac1550();
    virtual void Pad01_ac1550();
    virtual void Pad02_ac1550();
    virtual void Pad03_ac1550();
    virtual void Pad04_ac1550();
    virtual void Pad05_ac1550();
    virtual void Pad06_ac1550();
    virtual void Pad07_ac1550();
    virtual void Pad08_ac1550();
    virtual void Pad09_ac1550();
    virtual void Pad10_ac1550();
    virtual void Pad11_ac1550();
    virtual void Pad12_ac1550();
    virtual void Pad13_ac1550();
    virtual void Pad14_ac1550();
    virtual void Pad15_ac1550();
    virtual void Pad16_ac1550();
    virtual void Pad17_ac1550();
    virtual void Pad18_ac1550();
    virtual void Pad19_ac1550();
    virtual void Pad20_ac1550();
    virtual void Pad21_ac1550();
    virtual void Pad22_ac1550();
    virtual void Slot23_ac1550() = 0;
    virtual void Pad24_ac1550();
    virtual void Pad25_ac1550();
    virtual void Slot26_ac1550() = 0;
    virtual void Slot27_ac1550() = 0;
    virtual void Pad28_ac1550();
    virtual void Pad29_ac1550();
    virtual void Pad30_ac1550();
    virtual void Pad31_ac1550();
    virtual void Pad32_ac1550();
    virtual void Pad33_ac1550();
    virtual void Pad34_ac1550();
    virtual void Pad35_ac1550();
    virtual void Slot36_ac1550() = 0;
    virtual void Slot37_ac1550() = 0;
    virtual void Slot38_ac1550() = 0;
};
// An object asked for an interface (slot 0), and the colour object it hands back.
struct OB_NOVTABLE VQ_ac1550 {
    virtual bool Slot00_ac1550(uint32_t a, void* b) = 0;
    virtual void Pad01_ac1550();
    virtual void Slot02_ac1550() = 0;
};
struct OB_NOVTABLE VC_ac1550 {
    virtual void Pad00_ac1550();
    virtual void Pad01_ac1550();
    virtual void Slot02_ac1550() = 0;
    virtual void Pad03_ac1550();
    virtual bool Slot04_ac1550(uint8_t* a, uint8_t* b, uint8_t* c, uint8_t* d) = 0;
};

// STUB: 0x00825c90
uint32_t Fn00825c90();

// FUNCTION: 0x0082abe0
void cGZDrawContextAsBuffer::Slot06_ac14e8()
{
    Slot07_ac1338(0x8010);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082abf0 score 2
uint32_t cGZDrawContextAsBuffer::Fn0082abf0(uint32_t v)
{
    switch (FLD_ac1550(uint32_t, 0x2c)) {
    case 4:
    case 6: {
        uint32_t t = (((v & 0x1f) + (((v & 0x3e0) + ((v & 0x7c00) << 3)) << 3)) << 3);
        return ((t >> 5) & 0x70707) + t - 0x1000000;
    }
    case 5: {
        uint32_t t = (((v & 0xf800) << 5) + (v & 0x1f)) << 3;
        return ((t >> 5) & 0x70007) + (t + ((v >> 1) & 0x300) + (((v & 0x7e0) + 0x7f80000) << 5));
    }
    case 7: {
        uint32_t t = ((((v & 0xf00) + 0xf0000) << 4) + (v & 0xf0)) << 4;
        t = t + (v & 0xf);
        return (t << 4) + t;
    }
    case 8:
    case 9:
        return v | 0xff000000;
    }
    return 0;
}
#endif

// FUNCTION: 0x0082ace0
uint32_t cGZDrawContextAsBuffer::Slot08_ac1338()
{
    return 0 < FLD_ac1550(uint32_t, 0x28);
}

// FUNCTION: 0x0082ad00
void cGZDrawContextAsBuffer::Slot11_ac1338(uint32_t a)
{
    *OB_PTR(Blk4_ac1550, a) = FLD_ac1550(Blk4_ac1550, 0x18);
}

// FUNCTION: 0x0082ad20
uint32_t cGZDrawContextAsBuffer::Slot16_ac1338()
{
    return FLD_ac1550(uint32_t, 0x44) << 3;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082ad30 score 2
uint32_t cGZDrawContextAsBuffer::Slot30_ac1338(uint32_t a, uint32_t b, uint32_t c)
{
    switch (FLD_ac1550(uint32_t, 0x2c)) {
    case 4:
    case 6:
        return (((((static_cast<uint8_t>(a) & 0xf8) + 0x1e0) << 5) + (static_cast<uint8_t>(b) & 0xf8)) * 4) + (static_cast<uint8_t>(c) >> 3);
    case 5:
        return (((((static_cast<uint8_t>(a) & 0xf8) + 0xf0) << 5) + (static_cast<uint8_t>(b) & 0xfc)) * 8) + (static_cast<uint8_t>(c) >> 3);
    case 7:
        return ((((static_cast<uint8_t>(a) & 0xf0) + 0xf00) << 4) + (static_cast<uint8_t>(b) & 0xf0)) + (static_cast<uint8_t>(c) >> 4);
    case 8:
    case 9:
        return ((((static_cast<uint8_t>(a) + 0xff00) << 8) + static_cast<uint8_t>(b)) << 8) + static_cast<uint8_t>(c);
    }
    return 0;
}
#endif

// FUNCTION: 0x0082ae10
bool cGZDrawContextAsBuffer::Slot31_ac1338(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t v = Fn0082abf0(a);
    *OB_PTR(uint8_t, b) = static_cast<uint8_t>(v >> 16);
    *OB_PTR(uint8_t, c) = static_cast<uint8_t>(v >> 8);
    *OB_PTR(uint8_t, d) = static_cast<uint8_t>(v);
    return true;
}

// FUNCTION: 0x0082ae80
void* cGZDrawContextAsBuffer::Slot03_ac14e8()
{
    return this;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082aea0 score 47
void cGZDrawContextAsBuffer::Slot00_ac1338(uint32_t iid, uint32_t pp)
{
    if (iid == 1) {
        *OB_PTR(void*, pp) = this;
        AddRef();
        return;
    }
    if (iid == 0x20732180) {
        *OB_PTR(void*, pp) = this;
        AddRef();
        return;
    }
    if (iid == 0xab300b2b) {
        *OB_PTR(void*, pp) = static_cast<cUnk00ac14e8*>(this);
        AddRef();
        return;
    }
    VQ_ac1550* p = FLD_ac1550(VQ_ac1550*, 0x14);
    if (p) {
        p->Slot00_ac1550(iid, OB_PTR(void, pp));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082af20 score 2
uint32_t cGZDrawContextAsBuffer::Slot04_ac14e8()
{
    if (!OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot16_ac1550()) {
        OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot17_ac1550(FLD_ac1550(uint32_t, 0x14));
    }
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot42_ac1550();
    return FLD_ac1550(uint32_t, 0x10);
}
#endif

// FUNCTION: 0x0082af50
uint32_t cGZDrawContextAsBuffer::Slot05_ac14e8()
{
    Slot06_ac1338(0x8010);
    return FLD_ac1550(uint32_t, 0x10);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082af70 score 68
void cGZDrawContextAsBuffer::Slot07_ac14e8(uint32_t a, uint32_t b)
{
    uint32_t tmp;
    uint32_t old = FLD_ac1550(uint32_t, 0x10);
    if (a != old) {
        if (a) {
            OB_PTR(P10_ac1550, a)->Slot01_ac1550();
        }
        FLD_ac1550(uint32_t, 0x10) = a;
        if (old) {
            OB_PTR(P10_ac1550, old)->Slot02_ac1550();
        }
    }
    uint32_t src = FLD_ac1550(uint32_t, 0x14);
    if (b != src) {
        if (b) {
            OB_PTR(P14_ac1550, b)->Slot01_ac1550();
        }
        FLD_ac1550(uint32_t, 0x14) = b;
        if (src) {
            OB_PTR(P14_ac1550, src)->Slot02_ac1550();
        }
    }
    P14_ac1550* s = OB_PTR(P14_ac1550, b);
    uint32_t* r = s->Slot12_ac1550();
    uint32_t* rect = &FLD_ac1550(uint32_t, 0x18);
    rect[0] = r[0];
    rect[1] = r[1];
    rect[2] = r[2];
    rect[3] = r[3];
    FLD_ac1550(uint32_t, 0x2c) = *s->Slot15_ac1550(&tmp);
    FLD_ac1550(uint32_t, 0x44) = s->Slot17_ac1550();
    FLD_ac1550(uint32_t, 0x38) = rect[2] - rect[0];
    FLD_ac1550(uint32_t, 0x3c) = rect[3] - rect[1];
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot17_ac1550(0);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082b030 score 31
void cGZDrawContextAsBuffer::Slot08_ac14e8()
{
    uint32_t* r = OB_PTR(P14_ac1550, FLD_ac1550(uint32_t, 0x14))->Slot12_ac1550();
    uint32_t* rect = &FLD_ac1550(uint32_t, 0x18);
    rect[0] = r[0];
    rect[1] = r[1];
    rect[2] = r[2];
    rect[3] = r[3];
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot17_ac1550(0);
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot17_ac1550(FLD_ac1550(uint32_t, 0x14));
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot42_ac1550();
}
#endif

// FUNCTION: 0x0082b080
void cGZDrawContextAsBuffer::Slot09_ac14e8(uint32_t a)
{
    VC_ac1550* q = 0;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
    uint8_t b4;
    if (OB_PTR(VQ_ac1550, a)->Slot00_ac1550(0x86d72b57, &q)) {
        if (q->Slot04_ac1550(&b1, &b2, &b3, &b4)) {
            uint32_t col = (((static_cast<uint32_t>(b4) << 8) + b1) << 8) + b2;
            col = (col << 8) + b3;
            OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot21_ac1550(col);
        } else {
            OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot21_ac1550(0xffffffff);
        }
    } else {
        OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot21_ac1550(0xffffffff);
    }
    if (q) {
        q->Slot02_ac1550();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082b120 score 31
bool cGZDrawContextAsBuffer::Slot06_ac1338(uint32_t a)
{
    if (!FLD_ac1550(uint32_t, 0x28)) {
        P10_ac1550* p = OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10));
        bool f;
        if (p->Slot16_ac1550()) {
            f = !p->Slot41_ac1550() ? false : true;
            f = !f;
        } else {
            f = true;
        }
        FLD_ac1550(bool, 0x49) = f;
        OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot17_ac1550(FLD_ac1550(uint32_t, 0x14));
        if (OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot41_ac1550()) {
            OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot43_ac1550();
            OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot46_ac1550(&FLD_ac1550(uint32_t, 0x30), ~(a >> 15) & 1);
        }
    }
    FLD_ac1550(uint32_t, 0x28) = FLD_ac1550(uint32_t, 0x28) + 1;
    return true;
}
#endif

// FUNCTION: 0x0082b1a0
bool cGZDrawContextAsBuffer::Slot07_ac1338(uint32_t /*a*/)
{
    FLD_ac1550(uint32_t, 0x28) = FLD_ac1550(uint32_t, 0x28) - 1;
    if (FLD_ac1550(uint32_t, 0x28) == 0 && FLD_ac1550(bool, 0x49)) {
        OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot42_ac1550();
    }
    return true;
}

// FUNCTION: 0x0082b1c0
uint32_t cGZDrawContextAsBuffer::Slot09_ac1338()
{
    uint32_t* r = static_cast<uint32_t*>(Slot12_ac1338());
    return r[2] - r[0];
}

// FUNCTION: 0x0082b1d0
uint32_t cGZDrawContextAsBuffer::Slot10_ac1338()
{
    uint32_t* r = static_cast<uint32_t*>(Slot12_ac1338());
    return r[3] - r[1];
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082b1e0 score 11
uint32_t cGZDrawContextAsBuffer::Slot15_ac1338(uint32_t a)
{
    PixFmt_ac1550* o = OB_PTR(PixFmt_ac1550, a);
    uint32_t f = FLD_ac1550(uint32_t, 0x2c);
    o->mnFormat = f;
    o->mnBits = o->Fn00449500(f);
    return a;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082b200 score 52
void cGZDrawContextAsBuffer::Slot14_ac1338(uint32_t a)
{
    uint32_t* o = OB_PTR(uint32_t, a);
    uint32_t f = FLD_ac1550(uint32_t, 0x2c);
    switch (f) {
    case 2:
        o[0] = f;
        o[1] = 8;
        return;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        o[0] = f;
        o[1] = 0x10;
        return;
    case 8:
    case 9:
        o[0] = f;
        o[1] = 0x20;
        return;
    }
    o[0] = f;
    o[1] = 0;
}
#endif

// FUNCTION: 0x0082b280
bool cGZDrawContextAsBuffer::Slot20_ac1338(uint32_t a, uint32_t b, uint32_t c)
{
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot03_ac1550();
    if (c) {
        OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot05_ac1550(c);
    }
    P10_ac1550* p = OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10));
    p->Slot20_ac1550(0, Fn0082abf0(a));
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot35_ac1550(b);
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot09_ac1550();
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot40_ac1550();
    return true;
}

// FUNCTION: 0x0082b330
bool cGZDrawContextAsBuffer::Slot18_ac1338(uint32_t a, uint32_t b)
{
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot03_ac1550();
    if (b) {
        OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot05_ac1550(b);
    }
    P10_ac1550* p = OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10));
    p->Slot20_ac1550(0, Fn0082abf0(a));
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot32_ac1550();
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot09_ac1550();
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot40_ac1550();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082b390 score 39
uint32_t cGZDrawContextAsBuffer::Slot21_ac1338(uint32_t a, uint32_t b)
{
    Info6_ac1550 info;
    if (OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot46_ac1550(&info, 1)) {
        uint32_t row = info.w[1] * b + info.w[0];
        switch (info.w[5]) {
        case 1:
            return *OB_PTR(uint8_t, row + a);
        case 2:
            return OB_PTR(uint16_t, row)[a];
        case 3: {
            uint8_t* p = OB_PTR(uint8_t, row) + a * 3;
            return (((static_cast<uint32_t>(p[2]) << 8) + p[1]) << 8) + p[0];
        }
        case 4:
            return OB_PTR(uint32_t, row)[a];
        }
    }
    return 0;
}
#endif

// FUNCTION: 0x0082b460
void cGZDrawContextAsBuffer::Slot22_ac1338(uint32_t a, uint32_t b, uint32_t c)
{
    P10_ac1550* p = OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10));
    p->Slot20_ac1550(0, Fn0082abf0(c));
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot33_ac1550(a, b);
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot40_ac1550();
}

// FUNCTION: 0x0082b4b0
void cGZDrawContextAsBuffer::Slot23_ac1338()
{
    FLD_ac1550(bool, 0x48) = true;
    FLD_ac1550(P14t_ac1550*, 0x14)->Slot23_ac1550();
}

// FUNCTION: 0x0082b540
void cGZDrawContextAsBuffer::Slot26_ac1338()
{
    FLD_ac1550(P14t_ac1550*, 0x14)->Slot26_ac1550();
}

// FUNCTION: 0x0082b550
void cGZDrawContextAsBuffer::Slot27_ac1338()
{
    FLD_ac1550(bool, 0x48) = false;
    FLD_ac1550(P14t_ac1550*, 0x14)->Slot27_ac1550();
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082b560 score 76
bool cGZDrawContextAsBuffer::Slot28_ac1338(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot03_ac1550();
    P10_ac1550* p = OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10));
    p->Slot20_ac1550(0, Fn0082abf0(e));
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot25_ac1550(static_cast<float>(f));
    if (f > 1) {
        float v[4];
        v[0] = static_cast<float>(static_cast<int32_t>(a));
        v[1] = static_cast<float>(static_cast<int32_t>(b));
        v[2] = static_cast<float>(static_cast<int32_t>(c));
        v[3] = static_cast<float>(static_cast<int32_t>(d));
        float w = static_cast<float>(f - 1) * 0.5f;
        int32_t dx = static_cast<int32_t>(c) - static_cast<int32_t>(a);
        int32_t dy = static_cast<int32_t>(d) - static_cast<int32_t>(b);
        if (dx < 0) {
            dx = -dx;
        }
        if (dy < 0) {
            dy = -dy;
        }
        if (dx < dy) {
            v[0] = v[0] + w;
            v[2] = v[2] + w;
        } else {
            v[1] = v[1] + w;
            v[3] = v[3] + w;
        }
        OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot44_ac1550(1, v, 2);
    } else {
        OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot34_ac1550(a, b, c, d);
    }
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot09_ac1550();
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot40_ac1550();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082b690 score 43
bool cGZDrawContextAsBuffer::Slot29_ac1338(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t dst[4];
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot03_ac1550();
    if (d) {
        OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot05_ac1550(d);
    }
    Slot09_ac14e8(a);
    uint32_t* pt = OB_PTR(uint32_t, b);
    uint32_t* rc = OB_PTR(uint32_t, c);
    int32_t dx = pt[0] - rc[0];
    int32_t dy = pt[1] - rc[1];
    dst[0] = rc[0] + dx;
    dst[2] = rc[2] + dx;
    dst[1] = rc[1] + dy;
    dst[3] = rc[3] + dy;
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot38_ac1550(a, dst, rc);
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot09_ac1550();
    OB_PTR(P10_ac1550, FLD_ac1550(uint32_t, 0x10))->Slot40_ac1550();
    return true;
}
#endif

// FUNCTION: 0x0082b740
void cGZDrawContextAsBuffer::Slot36_ac1338()
{
    FLD_ac1550(P14t_ac1550*, 0x14)->Slot36_ac1550();
}

// FUNCTION: 0x0082b750
void cGZDrawContextAsBuffer::Slot37_ac1338()
{
    FLD_ac1550(P14t_ac1550*, 0x14)->Slot37_ac1550();
}

// FUNCTION: 0x0082b760
void cGZDrawContextAsBuffer::Slot38_ac1338()
{
    FLD_ac1550(P14t_ac1550*, 0x14)->Slot38_ac1550();
}

// FUNCTION: 0x00449500
uint32_t PixFmt_ac1550::Fn00449500(uint32_t fmt)
{
    switch (fmt) {
    case 2:
        return 8;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        return 0x10;
    case 8:
    case 9:
        return 0x20;
    }
    return 0;
}
