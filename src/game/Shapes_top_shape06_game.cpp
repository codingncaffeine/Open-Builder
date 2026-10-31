// Shape families of packet top_shape06_game, written by scratch/s16/gen/top_shape06_game/gen.sh.
#include "common/types.h"
#include "gzcom/cIGZUnknown.h"
#include "gzcom/cIGZString.h"


struct Query_top_shape06_game {
    // STUB: 0x0
    virtual void Slot00();
    // STUB: 0x4
    virtual void Slot01();
    // STUB: 0x8
    virtual void Slot02();
    // STUB: 0xc
    virtual void Slot03();
    // STUB: 0x10
    virtual void Slot04();
    // STUB: 0x14
    virtual void Slot05();
    // STUB: 0x18
    virtual void Slot06();
    // STUB: 0x1c
    virtual void Slot07();
    // STUB: 0x20
    virtual void Slot08();
    // STUB: 0x24
    virtual void Slot09();
    // STUB: 0x28
    virtual void Slot10();
    // STUB: 0x2c
    virtual void Slot11();
    // STUB: 0x30
    virtual void Slot12();
    // STUB: 0x34
    virtual void Slot13();
    // STUB: 0x38
    virtual void Slot14();
    // STUB: 0x3c
    virtual void Slot15();
    // STUB: 0x40
    virtual void Slot16();
    // STUB: 0x44
    virtual void Slot17();
    // STUB: 0x48
    virtual void Slot18();
    // STUB: 0x4c
    virtual void Slot19();
    // STUB: 0x50
    virtual void Slot20();
    // STUB: 0x54
    virtual void Slot21();
    // STUB: 0x58
    virtual bool Ask(uint32_t nId);
};

struct Elem_43b2f0_top_shape06_game {
    uint8_t mData[0x30];
    // STUB: 0x43b2f0
    void Assign(const Elem_43b2f0_top_shape06_game& other);
};

// FUNCTION: 0x0043b360
Elem_43b2f0_top_shape06_game* Fn43b360(const Elem_43b2f0_top_shape06_game* pFirst, const Elem_43b2f0_top_shape06_game* pLast, Elem_43b2f0_top_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Elem_5833f0_top_shape06_game {
    uint8_t mData[0x64];
    // STUB: 0x5833f0
    void Assign(const Elem_5833f0_top_shape06_game& other);
};

// FUNCTION: 0x00588510
Elem_5833f0_top_shape06_game* Fn588510(const Elem_5833f0_top_shape06_game* pFirst, const Elem_5833f0_top_shape06_game* pLast, Elem_5833f0_top_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Elem_589af0_top_shape06_game {
    uint8_t mData[0x6c];
    // STUB: 0x589af0
    void Assign(const Elem_589af0_top_shape06_game& other);
};

// FUNCTION: 0x005ab920
Elem_589af0_top_shape06_game* Fn5ab920(const Elem_589af0_top_shape06_game* pFirst, const Elem_589af0_top_shape06_game* pLast, Elem_589af0_top_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Elem_626750_top_shape06_game {
    uint8_t mData[0x50];
    // STUB: 0x626750
    void Assign(const Elem_626750_top_shape06_game& other);
};

// FUNCTION: 0x006272a0
Elem_626750_top_shape06_game* Fn6272a0(const Elem_626750_top_shape06_game* pFirst, const Elem_626750_top_shape06_game* pLast, Elem_626750_top_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Elem_88a870_top_shape06_game {
    uint8_t mData[0x30];
    // STUB: 0x88a870
    void Assign(const Elem_88a870_top_shape06_game& other);
};

// FUNCTION: 0x0088abf0
Elem_88a870_top_shape06_game* Fn88abf0(const Elem_88a870_top_shape06_game* pFirst, const Elem_88a870_top_shape06_game* pLast, Elem_88a870_top_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Elem_5daef0_top_shape06_game {
    uint8_t mData[0x14];
    // STUB: 0x5daef0
    void Assign(const Elem_5daef0_top_shape06_game& other);
};

// FUNCTION: 0x005db070
Elem_5daef0_top_shape06_game* Fn5db070(const Elem_5daef0_top_shape06_game* pFirst, const Elem_5daef0_top_shape06_game* pLast, Elem_5daef0_top_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Elem_4470a0_top_shape06_game {
    uint8_t mData[0xc];
    // STUB: 0x4470a0
    void Assign(const Elem_4470a0_top_shape06_game& other);
};

// FUNCTION: 0x00447320
void Fn447320(Elem_4470a0_top_shape06_game* pFirst, Elem_4470a0_top_shape06_game* pLast, const Elem_4470a0_top_shape06_game* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Assign(*pValue);
    }
}

// FUNCTION: 0x00588360
void Fn588360(Elem_5833f0_top_shape06_game* pFirst, Elem_5833f0_top_shape06_game* pLast, const Elem_5833f0_top_shape06_game* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Assign(*pValue);
    }
}

// FUNCTION: 0x005ab890
void Fn5ab890(Elem_589af0_top_shape06_game* pFirst, Elem_589af0_top_shape06_game* pLast, const Elem_589af0_top_shape06_game* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Assign(*pValue);
    }
}

struct Elem_5f3940_top_shape06_game {
    uint8_t mData[0xc];
    // STUB: 0x5f3940
    void Assign(const Elem_5f3940_top_shape06_game& other);
};

// FUNCTION: 0x005f3b60
void Fn5f3b60(Elem_5f3940_top_shape06_game* pFirst, Elem_5f3940_top_shape06_game* pLast, const Elem_5f3940_top_shape06_game* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Assign(*pValue);
    }
}

// FUNCTION: 0x005db040
void Fn5db040(Elem_5daef0_top_shape06_game* pFirst, Elem_5daef0_top_shape06_game* pLast, const Elem_5daef0_top_shape06_game* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Assign(*pValue);
    }
}

struct Elem_611b00_top_shape06_game {
    uint8_t mData[0xc];
    // STUB: 0x611b00
    void Assign(const Elem_611b00_top_shape06_game& other);
};

// FUNCTION: 0x00611c00
void Fn611c00(Elem_611b00_top_shape06_game* pFirst, Elem_611b00_top_shape06_game* pLast, const Elem_611b00_top_shape06_game* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Assign(*pValue);
    }
}

struct View_6026d0_top_shape06_game {
    uint8_t mPad[0x8];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn6026d0(uint32_t* pOut);
};

// FUNCTION: 0x006026d0
void View_6026d0_top_shape06_game::Fn6026d0(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_5f5920_top_shape06_game {
    void Fn5f5920(cIGZString* pOther);
};

// FUNCTION: 0x005f5920
void View_5f5920_top_shape06_game::Fn5f5920(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0x98));
}

struct View_5f8410_top_shape06_game {
    void Fn5f8410(cIGZString* pOther);
};

// FUNCTION: 0x005f8410
void View_5f8410_top_shape06_game::Fn5f8410(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0x6c));
}

struct Base_40d430_top_shape06_game {
    // STUB: 0x40d430
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_411810_top_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00411810
bool View_411810_top_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x2a5f877d) {
        return reinterpret_cast<Base_40d430_top_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

struct Base_407bc0_top_shape06_game {
    // STUB: 0x407bc0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_420d60_top_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00420d60
bool View_420d60_top_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xea3848ba) {
        return reinterpret_cast<Base_407bc0_top_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

struct Base_55b660_top_shape06_game {
    // STUB: 0x55b660
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_555a60_top_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00555a60
bool View_555a60_top_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x4a5b69ed) {
        return reinterpret_cast<Base_55b660_top_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

struct View_557040_top_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00557040
bool View_557040_top_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x4a416254) {
        return reinterpret_cast<Base_55b660_top_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

struct Base_505480_top_shape06_game {
    // STUB: 0x505480
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_566e30_top_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00566e30
bool View_566e30_top_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xa98f9d28) {
        return reinterpret_cast<Base_505480_top_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

struct View_459680_top_shape06_game {
    uint8_t mPad[0xf4];
    uint32_t mnValue;
    void Fn459680(uint32_t nValue);
};

// FUNCTION: 0x00459680
void View_459680_top_shape06_game::Fn459680(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_4abcb0_top_shape06_game {
    uint8_t mPad[0x150];
    uint32_t mnValue;
    void Fn4abcb0(uint32_t nValue);
};

// FUNCTION: 0x004abcb0
void View_4abcb0_top_shape06_game::Fn4abcb0(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_517ef0_top_shape06_game {
    uint8_t mPad[0x54];
    uint32_t mnValue;
    void Fn517ef0(uint32_t nValue);
};

// FUNCTION: 0x00517ef0
void View_517ef0_top_shape06_game::Fn517ef0(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_5fd810_top_shape06_game {
    uint8_t mPad[0x1c];
    uint32_t mnValue;
    void Fn5fd810(uint32_t nValue);
};

// FUNCTION: 0x005fd810
void View_5fd810_top_shape06_game::Fn5fd810(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_6197d0_top_shape06_game {
    uint8_t mPad[0x164];
    uint32_t mnValue;
    void Fn6197d0(uint32_t nValue);
};

// FUNCTION: 0x006197d0
void View_6197d0_top_shape06_game::Fn6197d0(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_623ba0_top_shape06_game {
    uint8_t mPad[0x204];
    uint32_t mnValue;
    void Fn623ba0(uint32_t nValue);
};

// FUNCTION: 0x00623ba0
void View_623ba0_top_shape06_game::Fn623ba0(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_6d6df0_top_shape06_game {
    uint8_t mPad[0x60];
    uint32_t mnValue;
    void Fn6d6df0(uint32_t nValue);
};

// FUNCTION: 0x006d6df0
void View_6d6df0_top_shape06_game::Fn6d6df0(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_75d5b0_top_shape06_game {
    uint8_t mPad[0x110];
    uint32_t mnValue;
    void Fn75d5b0(uint32_t nValue);
};

// FUNCTION: 0x0075d5b0
void View_75d5b0_top_shape06_game::Fn75d5b0(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_75d5c0_top_shape06_game {
    uint8_t mPad[0x114];
    uint32_t mnValue;
    void Fn75d5c0(uint32_t nValue);
};

// FUNCTION: 0x0075d5c0
void View_75d5c0_top_shape06_game::Fn75d5c0(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_7d2980_top_shape06_game {
    uint8_t mPad[0x1fc];
    uint32_t mnValue;
    void Fn7d2980(uint32_t nUnused, uint32_t nValue);
};

// FUNCTION: 0x007d2980
void View_7d2980_top_shape06_game::Fn7d2980(uint32_t /*nUnused*/, uint32_t nValue)
{
    mnValue = nValue;
}

struct View_881ea0_top_shape06_game {
    uint8_t mPad[0x208];
    uint32_t mnValue;
    void Fn881ea0(uint32_t nValue);
};

// FUNCTION: 0x00881ea0
void View_881ea0_top_shape06_game::Fn881ea0(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_881fb0_top_shape06_game {
    uint8_t mPad[0x18c];
    uint32_t mnValue;
    void Fn881fb0(uint32_t nValue);
};

// FUNCTION: 0x00881fb0
void View_881fb0_top_shape06_game::Fn881fb0(uint32_t nValue)
{
    mnValue = nValue;
}

struct View_4f6250_top_shape06_game {
    uint8_t mPad[0x80];
    uint8_t mbValue;
    void Fn4f6250(uint8_t bValue);
};

// FUNCTION: 0x004f6250
void View_4f6250_top_shape06_game::Fn4f6250(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_5d6150_top_shape06_game {
    uint8_t mPad[0x58];
    uint8_t mbValue;
    void Fn5d6150(uint8_t bValue);
};

// FUNCTION: 0x005d6150
void View_5d6150_top_shape06_game::Fn5d6150(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_5e0640_top_shape06_game {
    uint8_t mPad[0x50];
    uint8_t mbValue;
    void Fn5e0640(uint8_t bValue);
};

// FUNCTION: 0x005e0640
void View_5e0640_top_shape06_game::Fn5e0640(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_5f1a50_top_shape06_game {
    uint8_t mPad[0x1a5];
    uint8_t mbValue;
    void Fn5f1a50(uint8_t bValue);
};

// FUNCTION: 0x005f1a50
void View_5f1a50_top_shape06_game::Fn5f1a50(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_604df0_top_shape06_game {
    uint8_t mPad[0x104];
    uint8_t mbValue;
    void Fn604df0(uint8_t bValue);
};

// FUNCTION: 0x00604df0
void View_604df0_top_shape06_game::Fn604df0(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_649250_top_shape06_game {
    uint8_t mPad[0x118];
    uint8_t mbValue;
    void Fn649250(uint8_t bValue);
};

// FUNCTION: 0x00649250
void View_649250_top_shape06_game::Fn649250(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_7b2430_top_shape06_game {
    uint8_t mPad[0x116];
    uint8_t mbValue;
    void Fn7b2430(uint8_t bValue);
};

// FUNCTION: 0x007b2430
void View_7b2430_top_shape06_game::Fn7b2430(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_7dc1a0_top_shape06_game {
    uint8_t mPad[0xd];
    uint8_t mbValue;
    void Fn7dc1a0(uint8_t bValue);
};

// FUNCTION: 0x007dc1a0
void View_7dc1a0_top_shape06_game::Fn7dc1a0(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_7dc1b0_top_shape06_game {
    uint8_t mPad[0xe];
    uint8_t mbValue;
    void Fn7dc1b0(uint8_t bValue);
};

// FUNCTION: 0x007dc1b0
void View_7dc1b0_top_shape06_game::Fn7dc1b0(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_7dc1c0_top_shape06_game {
    uint8_t mPad[0xf];
    uint8_t mbValue;
    void Fn7dc1c0(uint8_t bValue);
};

// FUNCTION: 0x007dc1c0
void View_7dc1c0_top_shape06_game::Fn7dc1c0(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_7fb330_top_shape06_game {
    uint8_t mPad[0xa8];
    uint8_t mbValue;
    void Fn7fb330(uint8_t bValue);
};

// FUNCTION: 0x007fb330
void View_7fb330_top_shape06_game::Fn7fb330(uint8_t bValue)
{
    mbValue = bValue;
}

struct View_4e2570_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e2570(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e2570
bool View_4e2570_top_shape06_game::Fn4e2570(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x4002)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e2680_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e2680(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e2680
bool View_4e2680_top_shape06_game::Fn4e2680(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x4219)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e26c0_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e26c0(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e26c0
bool View_4e26c0_top_shape06_game::Fn4e26c0(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x420b)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e2700_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e2700(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e2700
bool View_4e2700_top_shape06_game::Fn4e2700(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x420c)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e2740_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e2740(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e2740
bool View_4e2740_top_shape06_game::Fn4e2740(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x420d)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e2780_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e2780(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e2780
bool View_4e2780_top_shape06_game::Fn4e2780(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x420e)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e27c0_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e27c0(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e27c0
bool View_4e27c0_top_shape06_game::Fn4e27c0(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x420a)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e2800_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e2800(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e2800
bool View_4e2800_top_shape06_game::Fn4e2800(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x4218)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e2840_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e2840(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e2840
bool View_4e2840_top_shape06_game::Fn4e2840(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x4005)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e28e0_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e28e0(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e28e0
bool View_4e28e0_top_shape06_game::Fn4e28e0(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x4206)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e2920_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e2920(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e2920
bool View_4e2920_top_shape06_game::Fn4e2920(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x4205)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}

struct View_4e2960_top_shape06_game {
    uint32_t mUnused;
    Query_top_shape06_game* mpPeer;
    bool mbAnswer;
    bool Fn4e2960(Query_top_shape06_game* pPeer);
};

// FUNCTION: 0x004e2960
bool View_4e2960_top_shape06_game::Fn4e2960(Query_top_shape06_game* pPeer)
{
    if (pPeer == mpPeer) {
        return mbAnswer;
    }
    if (pPeer->Ask(0x4209)) {
        mpPeer = pPeer;
        mbAnswer = true;
        return true;
    }
    mpPeer = pPeer;
    mbAnswer = false;
    return false;
}
