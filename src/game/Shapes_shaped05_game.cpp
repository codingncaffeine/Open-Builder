// Shape families of packet shaped05_game (pairs written by hand).
#include "common/types.h"

struct Byte58_shaped05_game {
    uint8_t pad[0x58];
    int8_t mcValue;
    uint32_t Slot09_aa29d4();
};

// FUNCTION: 0x005d6140
uint32_t Byte58_shaped05_game::Slot09_aa29d4()
{
    return mcValue;
}

struct Byte50_shaped05_game {
    uint8_t pad[0x50];
    int8_t mcValue;
    uint32_t Slot04_aa2ca4();
};

// FUNCTION: 0x005e0630
uint32_t Byte50_shaped05_game::Slot04_aa2ca4()
{
    return mcValue;
}

struct Target1c_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void Call(uint32_t flag) = 0;
};

struct View_5fb0c0_shaped05_game {
    uint8_t pad[0x1c];
    Target1c_shaped05_game* mpTarget;
    void EndInput();
};

// FUNCTION: 0x005fb0c0
void View_5fb0c0_shaped05_game::EndInput()
{
    if (mpTarget) {
        mpTarget->Call(0);
    }
}

struct Target0c8_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual void P29() = 0;
    virtual void P30() = 0;
    virtual void P31() = 0;
    virtual void P32() = 0;
    virtual void P33() = 0;
    virtual void P34() = 0;
    virtual void P35() = 0;
    virtual void P36() = 0;
    virtual void P37() = 0;
    virtual void P38() = 0;
    virtual void P39() = 0;
    virtual void P40() = 0;
    virtual void P41() = 0;
    virtual void P42() = 0;
    virtual void P43() = 0;
    virtual void P44() = 0;
    virtual void P45() = 0;
    virtual void P46() = 0;
    virtual void P47() = 0;
    virtual void P48() = 0;
    virtual void P49() = 0;
    virtual void P50() = 0;
    virtual void P51() = 0;
    virtual void P52() = 0;
    virtual void P53() = 0;
    virtual void P54() = 0;
    virtual void P55() = 0;
    virtual void P56() = 0;
    virtual void P57() = 0;
    virtual void P58() = 0;
    virtual void P59() = 0;
    virtual void P60() = 0;
    virtual void P61() = 0;
    virtual void P62() = 0;
    virtual void P63() = 0;
    virtual void P64() = 0;
    virtual void P65() = 0;
    virtual void P66() = 0;
    virtual void P67() = 0;
    virtual void P68() = 0;
    virtual void P69() = 0;
    virtual void P70() = 0;
    virtual void P71() = 0;
    virtual void P72() = 0;
    virtual void P73() = 0;
    virtual void P74() = 0;
    virtual void P75() = 0;
    virtual void P76() = 0;
    virtual void P77() = 0;
    virtual void P78() = 0;
    virtual void P79() = 0;
    virtual void P80() = 0;
    virtual void P81() = 0;
    virtual void P82() = 0;
    virtual void P83() = 0;
    virtual void P84() = 0;
    virtual void P85() = 0;
    virtual void P86() = 0;
    virtual void P87() = 0;
    virtual void P88() = 0;
    virtual void P89() = 0;
    virtual void P90() = 0;
    virtual void P91() = 0;
    virtual void P92() = 0;
    virtual void P93() = 0;
    virtual void P94() = 0;
    virtual void P95() = 0;
    virtual void P96() = 0;
    virtual void P97() = 0;
    virtual void P98() = 0;
    virtual void P99() = 0;
    virtual void Call(uint32_t flag) = 0;
};

struct View_654160_shaped05_game {
    uint8_t pad[0xc8];
    Target0c8_shaped05_game* mpTarget;
    void Fn654160();
};

// FUNCTION: 0x00654160
void View_654160_shaped05_game::Fn654160()
{
    if (mpTarget) {
        mpTarget->Call(1);
    }
}

struct Sink_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual void P18() = 0;
    virtual void P19() = 0;
    virtual void P20() = 0;
    virtual void P21() = 0;
    virtual void P22() = 0;
    virtual void P23() = 0;
    virtual void P24() = 0;
    virtual void P25() = 0;
    virtual void P26() = 0;
    virtual void P27() = 0;
    virtual void P28() = 0;
    virtual bool Call(void* p) = 0;
    virtual bool Call2(void* p) = 0;
};

struct View_5fb130_shaped05_game {
    uint8_t pad[0x18];
    void* mpItem;
    uint32_t pad2;
    Sink_shaped05_game* mpSink;
    bool Fn005fb130();
    bool Fn005fb150();
};

// FUNCTION: 0x005fb130
bool View_5fb130_shaped05_game::Fn005fb130()
{
    if (mpItem) {
        return mpSink->Call(mpItem);
    }
    return false;
}

// FUNCTION: 0x005fb150
bool View_5fb130_shaped05_game::Fn005fb150()
{
    if (mpItem) {
        return mpSink->Call2(mpItem);
    }
    return false;
}

struct Seg_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual bool Call() = 0;
    virtual bool Call2() = 0;
};

struct View_5d2080_shaped05_game {
    uint8_t pad[0x1cc];
    Seg_shaped05_game* mpSegment;
    bool Slot07_aa239c();
    bool Slot10_aa239c();
};

// FUNCTION: 0x005d2080
bool View_5d2080_shaped05_game::Slot07_aa239c()
{
    Seg_shaped05_game* p = mpSegment;
    return p ? p->Call() : false;
}

// FUNCTION: 0x005d20a0
bool View_5d2080_shaped05_game::Slot10_aa239c()
{
    Seg_shaped05_game* p = mpSegment;
    return p ? p->Call2() : false;
}

struct Inner5fd1e0_shaped05_game {
    // STUB: 0x00975402
    bool Slot05_ad7670(uint32_t a);
};

struct View_5fd1e0_shaped05_game {
    uint8_t pad[0x20];
    Inner5fd1e0_shaped05_game mInner;
    bool Fn005fd1e0(uint32_t a);
};

// FUNCTION: 0x005fd1e0
bool View_5fd1e0_shaped05_game::Fn005fd1e0(uint32_t a)
{
    mInner.Slot05_ad7670(a);
    return true;
}

struct View_67c220_shaped05_game {
    uint8_t pad[0x4];
    Inner5fd1e0_shaped05_game mInner;
    bool Slot12_aaee5c(uint32_t a);
};

// FUNCTION: 0x0067c220
bool View_67c220_shaped05_game::Slot12_aaee5c(uint32_t a)
{
    mInner.Slot05_ad7670(a);
    return true;
}

struct Inner5fd820_shaped05_game {
    // STUB: 0x009753ea
    void Slot03_ad8bec(uint32_t a);
};

struct View_5fd820_shaped05_game {
    uint8_t pad[0x20];
    Inner5fd820_shaped05_game mInner;
    uint32_t Fn005fd820(uint32_t a);
};

// FUNCTION: 0x005fd820
uint32_t View_5fd820_shaped05_game::Fn005fd820(uint32_t a)
{
    mInner.Slot03_ad8bec(a);
    return a;
}

struct Inner700f40_shaped05_game {
    // STUB: 0x006e9900
    uint32_t Slot05_ab2d50(uint32_t a);
};

struct View_700f40_shaped05_game {
    uint8_t pad[0x4];
    Inner700f40_shaped05_game mInner;
    uint32_t Slot05_ab2d50(uint32_t a);
};

// FUNCTION: 0x00700f40
uint32_t View_700f40_shaped05_game::Slot05_ab2d50(uint32_t a)
{
    mInner.Slot05_ab2d50(a);
    return a;
}

struct View_602710_shaped05_game {
    uint8_t pad[0x8];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    void Fn00602710(uint32_t a, uint32_t b, uint32_t c);
};

// FUNCTION: 0x00602710
void View_602710_shaped05_game::Fn00602710(uint32_t a, uint32_t b, uint32_t c)
{
    mnA = a;
    mnB = b;
    mnC = c;
}

struct View_79a0e0_shaped05_game {
    uint8_t pad[0xf8];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    void Slot12_ab6a28(uint32_t a, uint32_t b, uint32_t c);
};

// FUNCTION: 0x0079a0e0
void View_79a0e0_shaped05_game::Slot12_ab6a28(uint32_t a, uint32_t b, uint32_t c)
{
    mnA = a;
    mnB = b;
    mnC = c;
}

struct View_604d60_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void Set(uint32_t mask) = 0;
    virtual void Clear(uint32_t mask) = 0;
    void Fn00604d60(bool on);
    void Fn00604d90(bool on);
};

// FUNCTION: 0x00604d60
void View_604d60_shaped05_game::Fn00604d60(bool on)
{
    if (on) {
        Set(0x400000);
    } else {
        Clear(0x400000);
    }
}

// FUNCTION: 0x00604d90
void View_604d60_shaped05_game::Fn00604d90(bool on)
{
    if (on) {
        Set(0x10000000);
    } else {
        Clear(0x10000000);
    }
}

// STUB: 0x00648f70
void Fn00648f70(uint32_t a, uint32_t b, uint32_t c);
// STUB: 0x00649080
void Fn00649080(uint32_t a, uint32_t b, uint32_t c);

struct View_610550_shaped05_game {
    void FindPipeOccupant(uint32_t a, uint32_t b, uint32_t c);
    void FindPipeConnectionOccupant(uint32_t a, uint32_t b, uint32_t c);
};

// FUNCTION: 0x00610550
void View_610550_shaped05_game::FindPipeOccupant(uint32_t a, uint32_t b, uint32_t c)
{
    Fn00648f70(a, b, c);
}

// FUNCTION: 0x00610570
void View_610550_shaped05_game::FindPipeConnectionOccupant(uint32_t a, uint32_t b, uint32_t c)
{
    Fn00649080(a, b, c);
}

struct PoolNode_shaped05_game {
    PoolNode_shaped05_game* mpNext;
};

struct Pool_shaped05_game {
    uint32_t pad[3];
    // STUB: 0x005a61b0
    void Refill();
};

// GLOBAL: 0x00b17abc
extern Pool_shaped05_game gPoolB17abc;
// GLOBAL: 0x00b17ac8
extern PoolNode_shaped05_game* gpFreeB17ac8;
// GLOBAL: 0x00b17acc
extern Pool_shaped05_game gPoolB17acc;
// GLOBAL: 0x00b17ad8
extern PoolNode_shaped05_game* gpFreeB17ad8;

#ifdef OB_DRAFTS
// CLOSE: 0x005c3f30 score 5
void Fn005c3f30()
{
    if (!gpFreeB17ac8) {
        gPoolB17abc.Refill();
    }
    gpFreeB17ac8 = gpFreeB17ac8->mpNext;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005c3f60 score 5
void Fn005c3f60()
{
    if (!gpFreeB17ad8) {
        gPoolB17acc.Refill();
    }
    gpFreeB17ad8 = gpFreeB17ad8->mpNext;
}
#endif

// STUB: 0x005f9800
uint32_t Fn005f9800(uint32_t kind, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);

// FUNCTION: 0x005f98c0
uint32_t Fn005f98c0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    return Fn005f9800(1, a, b, c, d, e, f);
}

// FUNCTION: 0x005f98f0
uint32_t Fn005f98f0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    return Fn005f9800(0, a, b, c, d, e, f);
}

struct Holder6162f0_shaped05_game {
    // STUB: 0x006162f0
    ~Holder6162f0_shaped05_game();
};

struct Holder6164e0_shaped05_game {
    // STUB: 0x006164e0
    ~Holder6164e0_shaped05_game();
};

// GLOBAL: 0x00b45240
extern Holder6162f0_shaped05_game* gpB45240;
// GLOBAL: 0x00b45244
extern Holder6164e0_shaped05_game* gpB45244;

// FUNCTION: 0x006167a0
bool Fn006167a0()
{
    Holder6162f0_shaped05_game* p = gpB45240;
    delete p;
    gpB45240 = 0;
    return true;
}

// FUNCTION: 0x006167d0
bool Fn006167d0()
{
    Holder6164e0_shaped05_game* p = gpB45244;
    delete p;
    gpB45244 = 0;
    return true;
}

struct View_5f0ca0_shaped05_game {
    uint8_t pad[0x68];
    bool mbDirty;
    uint8_t pad2[3];
    uint32_t mnA;
    uint32_t mnB;
    uint8_t pad3[0x1a4 - 0x74];
    bool mbPending;
    void Fn005f0ca0(uint32_t v);
    void Fn005f0cd0(uint32_t v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005f0ca0 score 16
void View_5f0ca0_shaped05_game::Fn005f0ca0(uint32_t v)
{
    if (mnA != v) {
        bool pending = mbPending;
        mbDirty = true;
        if (pending) {
            mbDirty = true;
            mbPending = false;
        }
        mnA = v;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005f0cd0 score 16
void View_5f0ca0_shaped05_game::Fn005f0cd0(uint32_t v)
{
    if (mnB != v) {
        bool pending = mbPending;
        mbDirty = true;
        if (pending) {
            mbDirty = true;
            mbPending = false;
        }
        mnB = v;
    }
}
#endif

struct Base5f4930_shaped05_game {
    // STUB: 0x006491c0
    uint32_t AddRef();
    // STUB: 0x005ec960
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_5f4930_shaped05_game {
    uint32_t pad0;
    Base5f4930_shaped05_game mBase;
    bool Fn005f4930(uint32_t iid, void** ppv);
    bool Slot_5f7650(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005f4930
bool View_5f4930_shaped05_game::Fn005f4930(uint32_t iid, void** ppv)
{
    if (iid == 0x4b44fbe2) {
        *ppv = this;
        mBase.AddRef();
        return true;
    }
    return mBase.QueryInterface(iid, ppv);
}

// FUNCTION: 0x005f7650
bool View_5f4930_shaped05_game::Slot_5f7650(uint32_t iid, void** ppv)
{
    if (iid == 0x2b3b7d86) {
        *ppv = this;
        mBase.AddRef();
        return true;
    }
    return mBase.QueryInterface(iid, ppv);
}

struct StreamV12_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void Write(uint32_t v) = 0;
};

struct Vec3_shaped05_game {
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
};

// FUNCTION: 0x005da580
StreamV12_shaped05_game* Fn005da580(StreamV12_shaped05_game* s, const Vec3_shaped05_game* v)
{
    s->Write(v->mnX);
    s->Write(v->mnY);
    s->Write(v->mnZ);
    return s;
}

struct StreamV9_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void Write(uint32_t v) = 0;
};

// FUNCTION: 0x005da0a0
StreamV9_shaped05_game* Fn005da0a0(StreamV9_shaped05_game* s, const Vec3_shaped05_game* v)
{
    s->Write(v->mnX);
    s->Write(v->mnY);
    s->Write(v->mnZ);
    return s;
}

struct StreamP12_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void Write(const float* p) = 0;
};

// FUNCTION: 0x005da650
StreamP12_shaped05_game* Fn005da650(StreamP12_shaped05_game* s, const float* m)
{
    const float* p = m;
    for (uint32_t i = 3; i; --i) {
        for (uint32_t j = 3; j; --j) {
            s->Write(p);
            p++;
        }
    }
    return s;
}

// FUNCTION: 0x005da6b0
StreamP12_shaped05_game* Fn005da6b0(StreamP12_shaped05_game* s, const float* m)
{
    const float* p = m;
    for (uint32_t i = 4; i; --i) {
        for (uint32_t j = 4; j; --j) {
            s->Write(p);
            p++;
        }
    }
    return s;
}

struct Node5e97e0_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void GetType(uint16_t* out) = 0;
    virtual void Q0() = 0;
    virtual void Q1() = 0;
    virtual void Q2() = 0;
    virtual void Q3() = 0;
    virtual void Q4() = 0;
    virtual void Q5() = 0;
    virtual void Q6() = 0;
    virtual void Q7() = 0;
    virtual void Q8() = 0;
    virtual void Q9() = 0;
    virtual bool Query() = 0;
};

struct View_5e97e0_shaped05_game {
    bool Slot04_aa4330(Node5e97e0_shaped05_game* n);
    bool Slot_6b8a70(Node5e97e0_shaped05_game* n);
};

// FUNCTION: 0x005e97e0
bool View_5e97e0_shaped05_game::Slot04_aa4330(Node5e97e0_shaped05_game* n)
{
    uint16_t type;
    n->GetType(&type);
    if (type != 3) {
        return false;
    }
    return !n->Query();
}

// FUNCTION: 0x006b8a70
bool View_5e97e0_shaped05_game::Slot_6b8a70(Node5e97e0_shaped05_game* n)
{
    uint16_t type;
    n->GetType(&type);
    if (type != 1) {
        return false;
    }
    return !n->Query();
}

struct Center_shaped05_game {
    uint8_t pad[0x34];
    float mfMin[3];
    float mfMax[3];
    void Slot07_a953a8(float* out);
};

// FUNCTION: 0x005ded20
void Center_shaped05_game::Slot07_a953a8(float* out)
{
    out[0] = (mfMax[0] + mfMin[0]) * 0.5f;
    out[1] = (mfMax[1] + mfMin[1]) * 0.5f;
    out[2] = (mfMax[2] + mfMin[2]) * 0.5f;
}

struct Center2_shaped05_game {
    uint8_t pad[0xa0];
    float mfMin[3];
    float mfMax[3];
    void Fn005ca7d0(float* out);
};

// FUNCTION: 0x005ca7d0
void Center2_shaped05_game::Fn005ca7d0(float* out)
{
    out[0] = (mfMax[0] + mfMin[0]) * 0.5f;
    out[1] = (mfMax[1] + mfMin[1]) * 0.5f;
    out[2] = (mfMax[2] + mfMin[2]) * 0.5f;
}

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct Releasable_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void Release() = 0;
};

struct Elem8_shaped05_game {
    uint32_t mnKey;
    Releasable_shaped05_game* mpObj;
};

struct Vec8_shaped05_game {
    Elem8_shaped05_game* mpBegin;
    Elem8_shaped05_game* mpEnd;
    void Fn005ff0c0();
};

// FUNCTION: 0x005ff0c0
void Vec8_shaped05_game::Fn005ff0c0()
{
    Elem8_shaped05_game* it = mpBegin;
    Elem8_shaped05_game* end = mpEnd;
    for (; it != end; ++it) {
        Releasable_shaped05_game* p = it->mpObj;
        if (p) {
            p->Release();
        }
    }
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct Elem18_shaped05_game {
    uint32_t mnPad[4];
    Releasable_shaped05_game* mpObj;
    uint32_t mnPad2;
};

struct Vec18_shaped05_game {
    Elem18_shaped05_game* mpBegin;
    Elem18_shaped05_game* mpEnd;
    void Fn0077c380();
};

// FUNCTION: 0x0077c380
void Vec18_shaped05_game::Fn0077c380()
{
    Elem18_shaped05_game* it = mpBegin;
    Elem18_shaped05_game* end = mpEnd;
    for (; it != end; ++it) {
        Releasable_shaped05_game* p = it->mpObj;
        if (p) {
            p->Release();
        }
    }
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct Svc_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void Get(uint32_t a, uint32_t b, void** out) = 0;
};

// STUB: 0x008793ec
Svc_shaped05_game* Fn008793ec_shaped05_game();

struct SvcPtr_shaped05_game {
    void* mpObj;
    // STUB: 0x005f8f20
    ~SvcPtr_shaped05_game();
};

// FUNCTION: 0x00602600
void* Fn00602600()
{
    SvcPtr_shaped05_game h;
    h.mpObj = 0;
    Svc_shaped05_game* s = Fn008793ec_shaped05_game();
    if (s) {
        s->Get(0x86ad10ec, 0x86ad10ed, &h.mpObj);
    }
    return h.mpObj;
}

struct SvcPtr2_shaped05_game {
    void* mpObj;
    // STUB: 0x006021c0
    ~SvcPtr2_shaped05_game();
};

// FUNCTION: 0x00602640
void* Fn00602640()
{
    SvcPtr2_shaped05_game h;
    h.mpObj = 0;
    Svc_shaped05_game* s = Fn008793ec_shaped05_game();
    if (s) {
        s->Get(0xac1fae31, 0x8c1faeb7, &h.mpObj);
    }
    return h.mpObj;
}

struct Cb_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void Release() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void Register(void (*cb)(void*), void* user) = 0;
};

struct Rm_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void P2() = 0;
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
    virtual void P6() = 0;
    virtual void P7() = 0;
    virtual void P8() = 0;
    virtual void P9() = 0;
    virtual void P10() = 0;
    virtual void P11() = 0;
    virtual void P12() = 0;
    virtual void P13() = 0;
    virtual void P14() = 0;
    virtual void P15() = 0;
    virtual void P16() = 0;
    virtual void P17() = 0;
    virtual uint32_t Find(Cb_shaped05_game** out, uint32_t iid) = 0;
};

// GLOBAL: 0x00b43ca8
extern Rm_shaped05_game* gpB43ca8_shaped05_game;

// STUB: 0x0060fb90
void Fn0060fb90(void* user);
// STUB: 0x0080e430
void Fn0080e430(void* user);

struct View_6100d0_shaped05_game {
    void Fn006100d0();
    void Fn0080e4a0();
};

// FUNCTION: 0x006100d0
void View_6100d0_shaped05_game::Fn006100d0()
{
    Rm_shaped05_game* rm = gpB43ca8_shaped05_game;
    if (rm) {
        Cb_shaped05_game* cb = 0;
        if (rm->Find(&cb, 0x6534284a)) {
            cb->Register(Fn0060fb90, this);
            cb->Release();
        }
    }
}

// FUNCTION: 0x0080e4a0
void View_6100d0_shaped05_game::Fn0080e4a0()
{
    Rm_shaped05_game* rm = gpB43ca8_shaped05_game;
    if (rm) {
        Cb_shaped05_game* cb = 0;
        if (rm->Find(&cb, 0x6534284a)) {
            cb->Register(Fn0080e430, this);
            cb->Release();
        }
    }
}

struct Item_shaped05_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void Release() = 0;
    virtual void Q0() = 0;
    virtual void Q1() = 0;
    virtual void Q2() = 0;
    virtual void Q3() = 0;
    virtual void Q4() = 0;
    virtual void Q5() = 0;
    virtual void Q6() = 0;
    virtual void Q7() = 0;
    virtual void Q8() = 0;
    virtual void Q9() = 0;
    virtual void Q10() = 0;
    virtual void Q11() = 0;
    virtual void Q12() = 0;
    virtual void Q13() = 0;
    virtual void Q14() = 0;
    virtual void Q15() = 0;
    virtual void Q16() = 0;
    virtual void Q17() = 0;
    virtual void Q18() = 0;
    virtual void Q19() = 0;
    virtual void Q20() = 0;
    virtual void Q21() = 0;
    virtual void Q22() = 0;
    virtual void Q23() = 0;
    virtual void Q24() = 0;
    virtual void Apply(uint32_t a) = 0;
};

struct Src_shaped05_game {
    virtual bool Query(uint32_t iid, Item_shaped05_game** out) = 0;
};

// FUNCTION: 0x005da0d0
Src_shaped05_game* Fn005da0d0(Src_shaped05_game* s, uint32_t a)
{
    Item_shaped05_game* o = 0;
    if (s->Query(0x4999a8f5, &o)) {
        o->Apply(a);
    }
    if (o) {
        o->Release();
    }
    return s;
}

// FUNCTION: 0x005da120
Src_shaped05_game* Fn005da120(Src_shaped05_game* s, uint32_t a)
{
    Item_shaped05_game* o = 0;
    if (s->Query(0x6999a8fb, &o)) {
        o->Apply(a);
    }
    if (o) {
        o->Release();
    }
    return s;
}

struct QiBase_shaped05_game {
    virtual void P0() = 0;
    virtual uint32_t AddRef() = 0;
    uint32_t mnPadBase;
};

struct QiSub_shaped05_game {
    virtual void S0() = 0;
};

struct View_5d1520_shaped05_game : public QiBase_shaped05_game, public QiSub_shaped05_game {
    uint32_t mnPad;
    // STUB: 0x009457c6
    bool BaseQueryInterface(uint32_t iid, void** ppv);
    bool QueryInterface_5d1520(uint32_t iid, void** ppv);
    bool QueryInterface_5d1620(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1520 score 14
bool View_5d1520_shaped05_game::QueryInterface_5d1520(uint32_t iid, void** ppv)
{
    *ppv = 0;
    if (iid == 0x051b11bd || iid == 0x4999a8f5) {
        QiSub_shaped05_game* sub = this;
        *ppv = sub;
        if (sub) {
            AddRef();
            return true;
        }
    }
    return BaseQueryInterface(iid, ppv);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005d1620 score 14
bool View_5d1520_shaped05_game::QueryInterface_5d1620(uint32_t iid, void** ppv)
{
    *ppv = 0;
    if (iid == 0x6999a8fb || iid == 0xc51b11cb) {
        QiSub_shaped05_game* sub = this;
        *ppv = sub;
        if (sub) {
            AddRef();
            return true;
        }
    }
    return BaseQueryInterface(iid, ppv);
}
#endif

// FUNCTION: 0x005da680
StreamV12_shaped05_game* Fn005da680(StreamV12_shaped05_game* s, const uint32_t* m)
{
    const uint32_t* p = m;
    for (uint32_t i = 3; i; --i) {
        for (uint32_t j = 3; j; --j) {
            s->Write(*p);
            p++;
        }
    }
    return s;
}

// FUNCTION: 0x005da6e0
StreamV12_shaped05_game* Fn005da6e0(StreamV12_shaped05_game* s, const uint32_t* m)
{
    const uint32_t* p = m;
    for (uint32_t i = 4; i; --i) {
        for (uint32_t j = 4; j; --j) {
            s->Write(*p);
            p++;
        }
    }
    return s;
}

struct View_5e2930_shaped05_game {
    uint8_t pad[0x44];
    uint32_t mnHash[4];
    void Slot10_aa2f30(const uint32_t* p);
};

// FUNCTION: 0x005e2930
void View_5e2930_shaped05_game::Slot10_aa2f30(const uint32_t* p)
{
    mnHash[0] = p[0];
    mnHash[1] = p[1];
    mnHash[2] = p[2];
    mnHash[3] = p[3];
}

struct View_619650_shaped05_game {
    uint8_t pad[0xa0];
    uint32_t mnA;
    uint8_t pad1[0xb8 - 0xa4];
    uint32_t mnB;
    uint8_t pad2[0xd0 - 0xbc];
    uint32_t mnC;
    uint8_t pad3[0xe8 - 0xd4];
    uint32_t mnD;
    void Fn00619650(const uint32_t* p);
};

// FUNCTION: 0x00619650
void View_619650_shaped05_game::Fn00619650(const uint32_t* p)
{
    mnA = p[0];
    mnB = p[1];
    mnC = p[2];
    mnD = p[3];
}

struct PropPair_shaped05_game {
    uint32_t mnKey;
    uint32_t mnValue;
};

// STUB: 0x005fe940
PropPair_shaped05_game* Fn005fe940(PropPair_shaped05_game* first, PropPair_shaped05_game* last, PropPair_shaped05_game* value, uint32_t key, uint32_t zero);

struct View_5feb20_shaped05_game {
    uint8_t pad[8];
    PropPair_shaped05_game* mpBegin;
    PropPair_shaped05_game* mpEnd;
    bool HasProperty(uint32_t id);
    uint32_t GetProperty_5(uint32_t id);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005feb20 score 17
bool View_5feb20_shaped05_game::HasProperty(uint32_t id)
{
    PropPair_shaped05_game* end = mpEnd;
    PropPair_shaped05_game probe;
    probe.mnValue = 0;
    probe.mnKey = id;
    PropPair_shaped05_game* it = Fn005fe940(mpBegin, end, &probe, id, 0);
    return it != end && it->mnKey == id;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005feb70 score 13
uint32_t View_5feb20_shaped05_game::GetProperty_5(uint32_t id)
{
    PropPair_shaped05_game* end = mpEnd;
    PropPair_shaped05_game probe;
    probe.mnValue = 0;
    probe.mnKey = id;
    PropPair_shaped05_game* it = Fn005fe940(mpBegin, end, &probe, id, 0);
    if (it != end && it->mnKey == id) {
        return it->mnValue;
    }
    return 0;
}
#endif

struct View_67c620_shaped05_game {
    uint8_t pad[0x18];
    PropPair_shaped05_game* mpBegin;
    PropPair_shaped05_game* mpEnd;
    bool HasProperty(uint32_t id);
    uint32_t GetProperty_5(uint32_t id);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0067c620 score 17
bool View_67c620_shaped05_game::HasProperty(uint32_t id)
{
    PropPair_shaped05_game* end = mpEnd;
    PropPair_shaped05_game probe;
    probe.mnValue = 0;
    probe.mnKey = id;
    PropPair_shaped05_game* it = Fn005fe940(mpBegin, end, &probe, id, 0);
    return it != end && it->mnKey == id;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0067c670 score 13
uint32_t View_67c620_shaped05_game::GetProperty_5(uint32_t id)
{
    PropPair_shaped05_game* end = mpEnd;
    PropPair_shaped05_game probe;
    probe.mnValue = 0;
    probe.mnKey = id;
    PropPair_shaped05_game* it = Fn005fe940(mpBegin, end, &probe, id, 0);
    if (it != end && it->mnKey == id) {
        return it->mnValue;
    }
    return 0;
}
#endif

struct Lock_shaped05_game {
    virtual void P0();
    virtual void Lock();
    virtual void Unlock();
};

struct Arena_shaped05_game {
    // STUB: 0x005b9fc0
    void* Alloc(uint32_t bytes);
};

// GLOBAL: 0x00b62698
extern Lock_shaped05_game gLockB62698;
// GLOBAL: 0x00b626a0
extern Arena_shaped05_game gArenaB626a0;

struct E24_shaped05_game {
    uint32_t d[6];
};

struct E12_shaped05_game {
    uint32_t d[3];
};

struct FalseType_shaped05_game {
};

// STUB: 0x0082c140
E24_shaped05_game* Fn0082c140(E24_shaped05_game* first, E24_shaped05_game* last, E24_shaped05_game* dest, const FalseType_shaped05_game& tag);
// STUB: 0x00623fa0
E12_shaped05_game* Fn00623fa0(E12_shaped05_game* first, E12_shaped05_game* last, E12_shaped05_game* dest, const FalseType_shaped05_game& tag);

struct View_6149b0_shaped05_game {
    E24_shaped05_game* Fn006149b0(uint32_t n, E24_shaped05_game* first, E24_shaped05_game* last);
    E12_shaped05_game* Fn00614df0(uint32_t n, E12_shaped05_game* first, E12_shaped05_game* last);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006149b0 score 26
E24_shaped05_game* View_6149b0_shaped05_game::Fn006149b0(uint32_t n, E24_shaped05_game* first, E24_shaped05_game* last)
{
    gLockB62698.Lock();
    E24_shaped05_game* dest = static_cast<E24_shaped05_game*>(gArenaB626a0.Alloc(n * 24));
    gLockB62698.Unlock();
    FalseType_shaped05_game tag;
    Fn0082c140(first, last, dest, tag);
    return dest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00614df0 score 26
E12_shaped05_game* View_6149b0_shaped05_game::Fn00614df0(uint32_t n, E12_shaped05_game* first, E12_shaped05_game* last)
{
    gLockB62698.Lock();
    E12_shaped05_game* dest = static_cast<E12_shaped05_game*>(gArenaB626a0.Alloc(n * 12));
    gLockB62698.Unlock();
    FalseType_shaped05_game tag;
    Fn00623fa0(first, last, dest, tag);
    return dest;
}
#endif
