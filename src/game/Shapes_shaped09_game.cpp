// Shape pairs of packet shaped09_game.
#include "common/types.h"

struct Chan_86f350_shaped09_game;

// STUB: 0x0086f350
uint32_t Fn0086f350(Chan_86f350_shaped09_game* pChan, uint32_t a, uint32_t b, uint32_t c);

// STUB: 0x00872b80
uint32_t Fn00872b80(Chan_86f350_shaped09_game* pChan, uint32_t a, uint32_t b, uint32_t c);

struct VtPad21_shaped09_game {
    virtual void P00() = 0;
    virtual void P01() = 0;
    virtual void P02() = 0;
    virtual void P03() = 0;
    virtual void P04() = 0;
    virtual void P05() = 0;
    virtual void P06() = 0;
    virtual void P07() = 0;
    virtual void P08() = 0;
    virtual void P09() = 0;
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
};

// ---- flag setters: 0x875270 / 0x966920
struct View_875270_shaped09_game {
    uint8_t pad00[0xf];
    bool mbFlag;
    bool Fn00875270();
};

#ifdef _MSC_VER
#pragma optimize("s", on)
#pragma optimize("t", off)
#endif
// FUNCTION: 0x00875270
bool View_875270_shaped09_game::Fn00875270()
{
    mbFlag = true;
    return true;
}

struct View_966920_shaped09_game {
    uint8_t pad00[0x68];
    bool mbFlag;
    bool Fn00966920();
};

// FUNCTION: 0x00966920
bool View_966920_shaped09_game::Fn00966920()
{
    mbFlag = true;
    return true;
}

#ifdef _MSC_VER
#pragma optimize("", on)
#endif

// ---- field getters: 0x86e730 / 0x86e8b0
struct Rec_86e730_shaped09_game {
    uint32_t pad00[8];
    uint32_t mn20;
    uint32_t mn24;
    uint32_t mn28;
};

// FUNCTION: 0x0086e730
uint32_t Fn0086e730(Rec_86e730_shaped09_game* p)
{
    return p->mn20;
}

// FUNCTION: 0x0086e8b0
uint32_t Fn0086e8b0(Rec_86e730_shaped09_game* p)
{
    return p->mn28;
}

// ---- virtual slot 21 forwarders: 0x8f4080 / 0x8f4190
struct View_8f4080_shaped09_game : VtPad21_shaped09_game {
    virtual void Draw(uint32_t a, uint32_t b, uint32_t c, uint32_t d) = 0;
    uint32_t pad04[8];
    uint32_t mn24;
    uint32_t mn28;
    void Fn008f4080();
};

// FUNCTION: 0x008f4080
void View_8f4080_shaped09_game::Fn008f4080()
{
    Draw(0, 0, mn24, mn28);
}

struct View_8f4190_shaped09_game : VtPad21_shaped09_game {
    virtual void Draw(uint32_t a, uint32_t b, uint32_t c, uint32_t d) = 0;
    uint32_t pad04[21];
    uint32_t mn58;
    uint32_t mn5c;
    void Fn008f4190();
};

// FUNCTION: 0x008f4190
void View_8f4190_shaped09_game::Fn008f4190()
{
    Draw(0, 0, mn58, mn5c);
}

// ---- primitive manager table lookups: 0x889780 / 0x8897a0
struct Slot_889780_shaped09_game {
    uint32_t pad00[3];
    uint32_t mnMaxVertices;
    uint32_t mnVertexBufferType;
    uint32_t pad14[7];
};

struct View_889780_shaped09_game {
    uint32_t pad00[13];
    Slot_889780_shaped09_game* mpTable;
    uint32_t Fn00889780(uint32_t i);
    uint32_t Fn008897a0(uint32_t i);
};

// FUNCTION: 0x00889780
uint32_t View_889780_shaped09_game::Fn00889780(uint32_t i)
{
    return mpTable[i].mnVertexBufferType;
}

// FUNCTION: 0x008897a0
uint32_t View_889780_shaped09_game::Fn008897a0(uint32_t i)
{
    return mpTable[i].mnMaxVertices;
}

// ---- stack pop + copy: 0x8acf70 / 0x8adf50
struct Dst_8acf70_shaped09_game {
    uint8_t pad00[0x84];
    uint16_t mn84;
    uint16_t mn86;
};

struct Ctx_8acf70_shaped09_game {
    uint32_t pad00[8];
    uint32_t* mpStack;
    uint32_t pad24;
    Dst_8acf70_shaped09_game* mpDst;
};

#ifdef _MSC_VER
#pragma optimize("s", on)
#pragma optimize("t", off)
#endif
// FUNCTION: 0x008acf70
void Fn008acf70(Ctx_8acf70_shaped09_game* p)
{
    p->mpStack -= 1;
    p->mpDst->mn86 = static_cast<uint16_t>(*p->mpStack);
}

// FUNCTION: 0x008adf50
void Fn008adf50(Ctx_8acf70_shaped09_game* p)
{
    p->mpStack -= 1;
    p->mpDst->mn84 = static_cast<uint16_t>(*p->mpStack);
}

#ifdef _MSC_VER
#pragma optimize("", on)
#endif

// ---- 0x86e8c0 / 0x8724e0: forward a sub-object to another function
struct Holder_86e8c0_shaped09_game {
    uint32_t pad00[7];
    uint32_t mnSub;
};

// STUB: 0x008720c0
void Fn008720c0(uint32_t sub);

// STUB: 0x00868b80
void Fn00868b80(uint32_t sub);

// FUNCTION: 0x0086e8c0
void Fn0086e8c0(Holder_86e8c0_shaped09_game* p)
{
    if (p->mnSub) {
        Fn008720c0(p->mnSub);
    }
}

// FUNCTION: 0x008724e0
void Fn008724e0(Holder_86e8c0_shaped09_game* p)
{
    if (p->mnSub) {
        Fn00868b80(p->mnSub);
    }
}

// ---- 0x86d7a0 / 0x86d7d0: call an entry's callback with its argument
// GLOBAL: 0x00b50900
extern uint32_t* gpB50900_shaped09_game;

#ifdef OB_DRAFTS
// CLOSE: 0x0086d7a0 score 12
void Fn0086d7a0(uint32_t i)
{
    uint32_t* e = gpB50900_shaped09_game + i * 65;
    void (*pfn)(uint32_t) = *reinterpret_cast<void (**)(uint32_t)>(e + 0x3c);
    if (pfn) {
        pfn(e[0x31]);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0086d7d0 score 12
void Fn0086d7d0(uint32_t i)
{
    uint32_t* e = gpB50900_shaped09_game + i * 65;
    void (*pfn)(uint32_t) = *reinterpret_cast<void (**)(uint32_t)>(e + 0x3b);
    if (pfn) {
        pfn(e[0x30]);
    }
}
#endif

// ---- 0x86f350 / 0x872b80: send through the sink, then pass on
struct Sink_86f350_shaped09_game {
    int32_t (*mpfn)(Sink_86f350_shaped09_game*, uint32_t, uint32_t, uint32_t, uint32_t);
};

struct Chan_86f350_shaped09_game {
    uint32_t pad00[2];
    Sink_86f350_shaped09_game* mpSink;
    uint32_t pad0c[3];
    uint8_t pad18[2];
    uint8_t mbFlag1a;
    uint8_t pad1b;
    uint32_t mnNext;
};

// STUB: 0x00872cc0
void Fn00872cc0(void* next, uint32_t a, uint32_t b, uint32_t c);

// STUB: 0x00873880
void Fn00873880(void* next, uint32_t a, uint32_t b, uint32_t c);

#ifdef OB_DRAFTS
// CLOSE: 0x0086f350 score 38
uint32_t Fn0086f350(Chan_86f350_shaped09_game* pChan, uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t lc = c;
    uint32_t lb = b;
    Chan_86f350_shaped09_game* p = pChan;
    uint32_t la = a;
    Sink_86f350_shaped09_game* pSink = p->mpSink;
    if (pSink) {
        if (pSink->mpfn(pSink, la, lc, lb, p->mbFlag1a) > 0) {
            Fn00872cc0(&p->mnNext, la, lb, lc);
        }
    }
    return la;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00872b80 score 38
uint32_t Fn00872b80(Chan_86f350_shaped09_game* pChan, uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t lc = c;
    uint32_t lb = b;
    Chan_86f350_shaped09_game* p = pChan;
    uint32_t la = a;
    Sink_86f350_shaped09_game* pSink = p->mpSink;
    if (pSink) {
        if (pSink->mpfn(pSink, la, lc, lb, p->mbFlag1a) > 0) {
            Fn00873880(&p->mnNext, la, lb, lc);
        }
    }
    return la;
}
#endif

// ---- 0x8f3fd0 / 0x8f3fa0: copy a 0x34-byte record out of a table
struct Rec_8f3fd0_shaped09_game {
    uint32_t mnIndex;
    uint32_t pad[12];
};

struct View_8f3fd0_shaped09_game {
    uint32_t pad00[0x19];
    Rec_8f3fd0_shaped09_game* mpRecs;
    void Fn008f3fd0(uint32_t i, Rec_8f3fd0_shaped09_game* pOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008f3fd0 score 6
void View_8f3fd0_shaped09_game::Fn008f3fd0(uint32_t i, Rec_8f3fd0_shaped09_game* pOut)
{
    Rec_8f3fd0_shaped09_game* pSrc = mpRecs + i;
    *pOut = *pSrc;
    pOut->mnIndex = i;
}
#endif

struct View_8f3fa0_shaped09_game {
    uint32_t pad00[0x43];
    Rec_8f3fd0_shaped09_game* mpRecs;
    void Fn008f3fa0(uint32_t i, Rec_8f3fd0_shaped09_game* pOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008f3fa0 score 6
void View_8f3fa0_shaped09_game::Fn008f3fa0(uint32_t i, Rec_8f3fd0_shaped09_game* pOut)
{
    Rec_8f3fd0_shaped09_game* pSrc = mpRecs + i;
    *pOut = *pSrc;
    pOut->mnIndex = i;
}
#endif

// ---- 0x88bcd0 / 0x88bd20: size of a format code
// FUNCTION: 0x0088bcd0
uint32_t Fn0088bcd0(uint32_t n)
{
    switch (n) {
    case 0:
    case 1:
        return 0;
    case 2:
        return 4;
    case 3:
    case 5:
        return 1;
    case 4:
    case 6:
    case 7:
        return 8;
    }
    return 0;
}

// FUNCTION: 0x0088bd20
uint32_t Fn0088bd20(uint32_t n)
{
    switch (n) {
    case 0:
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
        return 0x10;
    case 1:
        return 0x18;
    case 4:
        return 0x20;
    }
    return 0;
}

// ---- 0x86f3a0 / 0x8728a0 / 0x8725d0 / 0x8727a0 / 0x872af0 / 0x872bd0: reset a channel record
struct Conn_86f3a0_shaped09_game {
    void* mpfnA;
    void* mpfnB;
    uint32_t mn08;
    uint32_t mn0c;
    uint32_t mn10;
    uint32_t mn14;
    uint8_t pad18[3];
    uint8_t mb1b;
    uint32_t mn1c;
    uint32_t mn20;
};

// STUB: 0x00872850
void Fn00872850();

// STUB: 0x00872540
void Fn00872540();

// STUB: 0x00872600
void Fn00872600();

// STUB: 0x00872770
void Fn00872770();

// STUB: 0x008706e0
void Fn008706e0();

// STUB: 0x00873860
void Fn00873860(void* p);

// FUNCTION: 0x0086f3a0
uint32_t Fn0086f3a0(Conn_86f3a0_shaped09_game* p)
{
    p->mn08 = 0;
    p->mn0c = 0;
    p->mn10 = 0;
    p->mn14 = 0;
    p->mb1b = 0;
    p->mpfnB = 0;
    p->mpfnA = reinterpret_cast<void*>(&Fn0086f350);
    p->mn1c = 0;
    return 0;
}

// FUNCTION: 0x008728a0
uint32_t Fn008728a0(Conn_86f3a0_shaped09_game* p)
{
    p->mn08 = 0;
    p->mn0c = 0;
    p->mn10 = 0;
    p->mn14 = 0;
    p->mb1b = 0;
    p->mpfnB = 0;
    p->mpfnA = reinterpret_cast<void*>(&Fn00872850);
    p->mn1c = 0;
    return 0;
}

// FUNCTION: 0x008725d0
uint32_t Fn008725d0(Conn_86f3a0_shaped09_game* p)
{
    p->mn08 = 0;
    p->mn0c = 0;
    p->mn10 = 0;
    p->mn14 = 0;
    p->mb1b = 0;
    p->mpfnB = reinterpret_cast<void*>(&Fn008724e0);
    p->mpfnA = reinterpret_cast<void*>(&Fn00872540);
    p->mn1c = 0;
    p->mn20 = 0;
    return 0;
}

// FUNCTION: 0x008727a0
uint32_t Fn008727a0(Conn_86f3a0_shaped09_game* p)
{
    p->mn08 = 0;
    p->mn0c = 0;
    p->mn10 = 0;
    p->mn14 = 0;
    p->mb1b = 0;
    p->mpfnB = reinterpret_cast<void*>(&Fn00872770);
    p->mpfnA = reinterpret_cast<void*>(&Fn00872600);
    p->mn20 = 0;
    p->mn1c = 0;
    return 0;
}

// FUNCTION: 0x00872af0
uint32_t Fn00872af0(Conn_86f3a0_shaped09_game* p)
{
    p->mn08 = 0;
    p->mn0c = 0;
    p->mn10 = 0;
    p->mn14 = 0;
    p->mb1b = 0;
    p->mpfnB = 0;
    p->mpfnA = reinterpret_cast<void*>(&Fn008706e0);
    Fn00873860(&p->mn1c);
    return 0;
}

// FUNCTION: 0x00872bd0
uint32_t Fn00872bd0(Conn_86f3a0_shaped09_game* p)
{
    p->mn08 = 0;
    p->mn0c = 0;
    p->mn10 = 0;
    p->mn14 = 0;
    p->mb1b = 0;
    p->mpfnB = 0;
    p->mpfnA = reinterpret_cast<void*>(&Fn00872b80);
    Fn00873860(&p->mn1c);
    return 0;
}

// ---- 0x86cef0 / 0x86cf90: call a function for each id of a list
struct IdList_86cef0_shaped09_game {
    uint8_t mnCount;
    uint8_t pad01[3];
    int16_t maIds[1];
};

// STUB: 0x00870500
void Fn00870500(int32_t id, uint32_t arg);

// STUB: 0x00870600
void Fn00870600(int32_t id, uint32_t arg);

#ifdef OB_DRAFTS
// CLOSE: 0x0086cef0 score 8
void Fn0086cef0(IdList_86cef0_shaped09_game* p, uint32_t arg)
{
    for (int32_t i = 0; i < p->mnCount; i++) {
        Fn00870500(p->maIds[i], arg);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0086cf90 score 8
void Fn0086cf90(IdList_86cef0_shaped09_game* p, uint32_t arg)
{
    for (int32_t i = 0; i < p->mnCount; i++) {
        Fn00870600(p->maIds[i], arg);
    }
}
#endif

// ---- 0x8ab800 / 0x8ab830: sum of two lookups
struct Pair_8ab800_shaped09_game {
    uint8_t pad00[0x14];
    uint16_t mnA14;
    uint16_t mnA16;
    uint8_t pad18[4];
    uint16_t mnB1c;
    uint16_t mnB1e;
};

// STUB: 0x008a1d20
uint32_t Fn008a1d20(uint32_t a, uint32_t b);

#ifdef OB_DRAFTS
// CLOSE: 0x008ab800 score 12
uint32_t Fn008ab800(Pair_8ab800_shaped09_game* p, uint32_t a, uint32_t b)
{
    uint32_t n = Fn008a1d20(a, p->mnA14);
    return Fn008a1d20(b, p->mnA16) + n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008ab830 score 12
uint32_t Fn008ab830(Pair_8ab800_shaped09_game* p, uint32_t a, uint32_t b)
{
    uint32_t n = Fn008a1d20(a, p->mnB1c);
    return Fn008a1d20(b, p->mnB1e) + n;
}
#endif

// ---- 0x88ae90: release every element's object, free the buffer
struct Obj_88ae90_shaped09_game {
    virtual void P0() = 0;
    virtual void P1() = 0;
    virtual void Release() = 0;
};

struct Elem_88ae90_shaped09_game {
    uint32_t pad00[11];
    Obj_88ae90_shaped09_game* mpObj;
};

// STUB: 0x0090cf63
void Fn0090cf63_shaped09_game(void* p);

struct View_88ae90_shaped09_game {
    Elem_88ae90_shaped09_game* mpBegin;
    Elem_88ae90_shaped09_game* mpEnd;
    void Fn0088ae90();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0088ae90 score 6
void View_88ae90_shaped09_game::Fn0088ae90()
{
    Elem_88ae90_shaped09_game* pEnd = mpEnd;
    for (Elem_88ae90_shaped09_game* p = mpBegin; p != pEnd; p++) {
        if (p->mpObj) {
            p->mpObj->Release();
        }
    }
    if (mpBegin) {
        Fn0090cf63_shaped09_game(mpBegin);
    }
}
#endif

// ---- 0x88d210 / 0x88d270: function pointer by code
typedef void (*Pfn_88d210_shaped09_game)();
// The selectors below hand back a function pointer; wrapped in a one-field struct (returned in eax alike) so the hook
// generator reads their names.
struct RetPfn_88d210_shaped09_game { Pfn_88d210_shaped09_game p; };
inline RetPfn_88d210_shaped09_game RetPfn_88d210(Pfn_88d210_shaped09_game p) { RetPfn_88d210_shaped09_game r = { p }; return r; }

// STUB: 0x0088c830
void Fn0088c830();

// STUB: 0x0088cf90
void Fn0088cf90();

// STUB: 0x0088cfc0
void Fn0088cfc0();

// STUB: 0x0080a6a0
void Fn0080a6a0();

// STUB: 0x0088cff0
void Fn0088cff0();

// STUB: 0x0088d020
void Fn0088d020();

// STUB: 0x0080a6d0
void Fn0080a6d0();

// FUNCTION: 0x0088d210
RetPfn_88d210_shaped09_game Fn0088d210(uint32_t n)
{
    switch (n) {
    case 1:
    case 2:
        return RetPfn_88d210(Fn0088c830);
    case 3:
    case 10:
    case 11:
    case 12:
    case 13:
        return RetPfn_88d210(Fn0088cf90);
    case 4:
    case 5:
        return RetPfn_88d210(Fn0088cfc0);
    case 7:
        return RetPfn_88d210(Fn0080a6a0);
    case 9:
        return RetPfn_88d210(0);
    }
    return RetPfn_88d210(0);
}

// FUNCTION: 0x0088d270
RetPfn_88d210_shaped09_game Fn0088d270(uint32_t n)
{
    switch (n) {
    case 1:
    case 2:
        return RetPfn_88d210(Fn0088c830);
    case 3:
    case 9:
    case 10:
    case 12:
    case 13:
        return RetPfn_88d210(Fn0088cff0);
    case 4:
    case 5:
        return RetPfn_88d210(Fn0088d020);
    case 7:
        return RetPfn_88d210(Fn0080a6d0);
    case 11:
        return RetPfn_88d210(0);
    }
    return RetPfn_88d210(0);
}

// ---- 0x889d40: sibling of 0x88ae90 (element object at 0x8)
struct Elem_889d40_shaped09_game {
    uint32_t pad00[2];
    Obj_88ae90_shaped09_game* mpObj;
    uint32_t pad0c[9];
};

struct View_889d40_shaped09_game {
    Elem_889d40_shaped09_game* mpBegin;
    Elem_889d40_shaped09_game* mpEnd;
    void Fn00889d40();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00889d40 score 6
void View_889d40_shaped09_game::Fn00889d40()
{
    Elem_889d40_shaped09_game* pEnd = mpEnd;
    for (Elem_889d40_shaped09_game* p = mpBegin; p != pEnd; p++) {
        if (p->mpObj) {
            p->mpObj->Release();
        }
    }
    if (mpBegin) {
        Fn0090cf63_shaped09_game(mpBegin);
    }
}
#endif

// ---- 0x86f8c0 / 0x86f900: fill in two callback tables
// GLOBAL: 0x00b528b0
extern void* gB528b0_shaped09_game;
// GLOBAL: 0x00b528b4
extern void* gB528b4_shaped09_game;
// GLOBAL: 0x00b528b8
extern void* gB528b8_shaped09_game;
// GLOBAL: 0x00b52934
extern uint32_t gB52934_shaped09_game;
// GLOBAL: 0x00b52938
extern uint32_t gB52938_shaped09_game;
// GLOBAL: 0x00b5293c
extern uint32_t gB5293c_shaped09_game;
// GLOBAL: 0x00b528a4
extern void* gB528a4_shaped09_game;
// GLOBAL: 0x00b528a8
extern void* gB528a8_shaped09_game;
// GLOBAL: 0x00b528ac
extern void* gB528ac_shaped09_game;
// GLOBAL: 0x00b52928
extern uint32_t gB52928_shaped09_game;
// GLOBAL: 0x00b5292c
extern uint32_t gB5292c_shaped09_game;
// GLOBAL: 0x00b52930
extern uint32_t gB52930_shaped09_game;

// STUB: 0x0086e8e0
void Fn0086e8e0();
// STUB: 0x00873280
void Fn00873280();
// STUB: 0x00873070
void Fn00873070();
// STUB: 0x0086ea00
void Fn0086ea00();
// STUB: 0x008734b0
void Fn008734b0();
// STUB: 0x008733f0
void Fn008733f0();

// FUNCTION: 0x0086f8c0
void Fn0086f8c0()
{
    gB528b0_shaped09_game = reinterpret_cast<void*>(&Fn0086e8e0);
    gB52934_shaped09_game = 0x2c;
    gB52938_shaped09_game = 0x44;
    gB528b4_shaped09_game = reinterpret_cast<void*>(&Fn00873280);
    gB528b8_shaped09_game = reinterpret_cast<void*>(&Fn00873070);
    gB5293c_shaped09_game = 0x38;
}

// FUNCTION: 0x0086f900
void Fn0086f900()
{
    gB528a4_shaped09_game = reinterpret_cast<void*>(&Fn0086ea00);
    gB52928_shaped09_game = 0x2c;
    gB528a8_shaped09_game = reinterpret_cast<void*>(&Fn008734b0);
    gB5292c_shaped09_game = 0x30;
    gB528ac_shaped09_game = reinterpret_cast<void*>(&Fn008733f0);
    gB52930_shaped09_game = 0x34;
}

// ---- 0x82b910 / 0x993270: factory slot, query the source then create the object
struct Unk_82b910_shaped09_game {
    virtual bool QueryInterface(uint32_t iid, void** out) = 0;
    virtual void AddRef() = 0;
    virtual uint32_t Release() = 0;
};

struct Obj_82b910_shaped09_game {
    virtual void P0() = 0;
    virtual void AddRef() = 0;
    // STUB: 0x00830690
    Obj_82b910_shaped09_game* Fn00830690();
};

struct Obj_993270_shaped09_game {
    virtual void P0() = 0;
    virtual void AddRef() = 0;
    // STUB: 0x009920e0
    Obj_993270_shaped09_game* Fn009920e0();
};

struct View_82b910_shaped09_game {
    bool Fn0082b910(Unk_82b910_shaped09_game* pSrc, void** ppOut);
    bool Fn00993270(Unk_82b910_shaped09_game* pSrc, void** ppOut);
};

// FUNCTION: 0x0082b910
bool View_82b910_shaped09_game::Fn0082b910(Unk_82b910_shaped09_game* pSrc, void** ppOut)
{
    Unk_82b910_shaped09_game* pQuery = 0;
    if (pSrc->QueryInterface(0x20732180, reinterpret_cast<void**>(&pQuery))) {
        void* mem = operator new(0xd4);
        Obj_82b910_shaped09_game* pObj;
        if (mem) {
            pObj = static_cast<Obj_82b910_shaped09_game*>(mem)->Fn00830690();
        } else {
            pObj = 0;
        }
        *ppOut = pObj;
        pObj->AddRef();
        if (pQuery) {
            pQuery->Release();
        }
        return true;
    }
    if (pQuery) {
        pQuery->Release();
    }
    return false;
}

// FUNCTION: 0x00993270
bool View_82b910_shaped09_game::Fn00993270(Unk_82b910_shaped09_game* pSrc, void** ppOut)
{
    Unk_82b910_shaped09_game* pQuery = 0;
    if (pSrc->QueryInterface(0xe3094dc8, reinterpret_cast<void**>(&pQuery))) {
        void* mem = operator new(0xdc);
        Obj_993270_shaped09_game* pObj;
        if (mem) {
            pObj = static_cast<Obj_993270_shaped09_game*>(mem)->Fn009920e0();
        } else {
            pObj = 0;
        }
        *ppOut = pObj;
        pObj->AddRef();
        if (pQuery) {
            pQuery->Release();
        }
        return true;
    }
    if (pQuery) {
        pQuery->Release();
    }
    return false;
}

// ---- 0x8edcb0 / 0x8edd30: build a record in place, then push it onto a deque
struct Rec_8edcb0_shaped09_game {
    uint32_t mnCount;
    uint32_t mnRef;
    uint8_t mabBytes[32];
};

struct Deque_8edcb0_shaped09_game {
    uint32_t pad00[4];
    Rec_8edcb0_shaped09_game* mpCur;
    uint32_t pad14;
    Rec_8edcb0_shaped09_game* mpLast;
    // STUB: 0x008ecc20
    void Fn008ecc20(Rec_8edcb0_shaped09_game* pRec);
};

struct View_8edcb0_shaped09_game {
    uint32_t pad00[2];
    uint32_t mnCount;
    uint32_t mnRef;
    uint8_t mabBytes[0x18];
    uint32_t mn20;
    uint32_t mn24;
    uint32_t mn28;
    uint32_t mn2c;
    Deque_8edcb0_shaped09_game mDeque;
    void Fn008edcb0(uint32_t n);
    void Fn008edd30(uint32_t n);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008edcb0 score 44
void View_8edcb0_shaped09_game::Fn008edcb0(uint32_t n)
{
    Rec_8edcb0_shaped09_game* pRec = reinterpret_cast<Rec_8edcb0_shaped09_game*>(&mnCount);
    mnRef = mnRef + 1;
    pRec->mnCount = 0;
    pRec->mabBytes[pRec->mnCount] = static_cast<uint8_t>(n + 0x40);
    pRec->mnCount++;
    mn2c = 1;
    mn20 = 0;
    mn24 = 1u << n;
    mn28 = mn24 | 0x10000;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = *pRec;
        }
        mDeque.mpCur = mDeque.mpCur + 1;
    } else {
        mDeque.Fn008ecc20(pRec);
    }
}

// CLOSE: 0x008edd30 score 44
void View_8edcb0_shaped09_game::Fn008edd30(uint32_t n)
{
    Rec_8edcb0_shaped09_game* pRec = reinterpret_cast<Rec_8edcb0_shaped09_game*>(&mnCount);
    mnRef = mnRef + 1;
    pRec->mnCount = 0;
    pRec->mabBytes[pRec->mnCount] = static_cast<uint8_t>(n + 0x48);
    pRec->mnCount++;
    mn2c = 1;
    mn20 = 0;
    mn24 = 1u << n;
    mn28 = mn24 | 0x10000;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = *pRec;
        }
        mDeque.mpCur = mDeque.mpCur + 1;
    } else {
        mDeque.Fn008ecc20(pRec);
    }
}
#endif
