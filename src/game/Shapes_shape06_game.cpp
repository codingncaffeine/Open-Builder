// Shape families of packet shape06_game, written by scratch/s16/gen/shape06_game/gen.sh.
#include "common/types.h"
#include "gzcom/cIGZUnknown.h"
#include "gzcom/cIGZString.h"


struct Elem_889620_shape06_game {
    uint8_t mData[0x30];
    // STUB: 0x889620
    void Assign(const Elem_889620_shape06_game& other);
};

// FUNCTION: 0x00889960
Elem_889620_shape06_game* Fn889960(const Elem_889620_shape06_game* pFirst, const Elem_889620_shape06_game* pLast, Elem_889620_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Elem_802240_shape06_game {
    uint8_t mData[0x34];
    // STUB: 0x802240
    void Assign(const Elem_802240_shape06_game& other);
};

// FUNCTION: 0x008022e0
Elem_802240_shape06_game* Fn8022e0(const Elem_802240_shape06_game* pFirst, const Elem_802240_shape06_game* pLast, Elem_802240_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Elem_7d3b10_shape06_game {
    uint8_t mData[0x68];
    // STUB: 0x7d3b10
    void Assign(const Elem_7d3b10_shape06_game& other);
};

// FUNCTION: 0x007d3bc0
Elem_7d3b10_shape06_game* Fn7d3bc0(const Elem_7d3b10_shape06_game* pFirst, const Elem_7d3b10_shape06_game* pLast, Elem_7d3b10_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Elem_42fd30_shape06_game {
    uint8_t mData[0x30];
    // STUB: 0x42fd30
    void Assign(const Elem_42fd30_shape06_game& other);
};

// FUNCTION: 0x0042fdc0
Elem_42fd30_shape06_game* Fn42fdc0(const Elem_42fd30_shape06_game* pFirst, const Elem_42fd30_shape06_game* pLast, Elem_42fd30_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

struct Elem_5120e0_shape06_game {
    uint8_t mData[0x6c];
    // STUB: 0x5120e0
    void Assign(const Elem_5120e0_shape06_game& other);
};

// FUNCTION: 0x00512c80
Elem_5120e0_shape06_game* Fn512c80(const Elem_5120e0_shape06_game* pFirst, const Elem_5120e0_shape06_game* pLast, Elem_5120e0_shape06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        pDest->Assign(*pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

// FUNCTION: 0x007d5170
void Fn7d5170(Elem_7d3b10_shape06_game* pFirst, Elem_7d3b10_shape06_game* pLast, const Elem_7d3b10_shape06_game* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Assign(*pValue);
    }
}

struct Elem_5f4460_shape06_game {
    uint8_t mData[0x10];
    // STUB: 0x5f4460
    void Assign(const Elem_5f4460_shape06_game& other);
};

// FUNCTION: 0x006b3b60
void Fn6b3b60(Elem_5f4460_shape06_game* pFirst, Elem_5f4460_shape06_game* pLast, const Elem_5f4460_shape06_game* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Assign(*pValue);
    }
}

struct Elem_4e3f80_shape06_game {
    uint8_t mData[0xc];
    // STUB: 0x4e3f80
    void Assign(const Elem_4e3f80_shape06_game& other);
};

// FUNCTION: 0x006c1040
void Fn6c1040(Elem_4e3f80_shape06_game* pFirst, Elem_4e3f80_shape06_game* pLast, const Elem_4e3f80_shape06_game* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Assign(*pValue);
    }
}

struct Elem_6f1e10_shape06_game {
    uint8_t mData[0x4];
    // STUB: 0x6f1e10
    void Assign(const Elem_6f1e10_shape06_game& other);
};

// FUNCTION: 0x006f2270
void Fn6f2270(Elem_6f1e10_shape06_game* pFirst, Elem_6f1e10_shape06_game* pLast, const Elem_6f1e10_shape06_game* pValue)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Assign(*pValue);
    }
}

struct View_7ff230_shape06_game {
    uint8_t mPad[0x50];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn7ff230(uint32_t* pOut);
};

// FUNCTION: 0x007ff230
void View_7ff230_shape06_game::Fn7ff230(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_7d6b20_shape06_game {
    uint8_t mPad[0x8c];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn7d6b20(uint32_t* pOut);
};

// FUNCTION: 0x007d6b20
void View_7d6b20_shape06_game::Fn7d6b20(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_7d6b50_shape06_game {
    uint8_t mPad[0x64];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn7d6b50(uint32_t* pOut);
};

// FUNCTION: 0x007d6b50
void View_7d6b50_shape06_game::Fn7d6b50(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_4e76b0_shape06_game {
    uint8_t mPad[0xc8];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn4e76b0(uint32_t* pOut);
};

// FUNCTION: 0x004e76b0
void View_4e76b0_shape06_game::Fn4e76b0(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_4f8280_shape06_game {
    uint8_t mPad[0xc];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn4f8280(uint32_t* pOut);
};

// FUNCTION: 0x004f8280
void View_4f8280_shape06_game::Fn4f8280(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_5b2b00_shape06_game {
    uint8_t mPad[0x34];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn5b2b00(uint32_t* pOut);
};

// FUNCTION: 0x005b2b00
void View_5b2b00_shape06_game::Fn5b2b00(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_5d6360_shape06_game {
    uint8_t mPad[0x3c];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn5d6360(uint32_t* pOut);
};

// FUNCTION: 0x005d6360
void View_5d6360_shape06_game::Fn5d6360(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_602f70_shape06_game {
    uint8_t mPad[0x14];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn602f70(uint32_t* pOut);
};

// FUNCTION: 0x00602f70
void View_602f70_shape06_game::Fn602f70(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_649da0_shape06_game {
    uint8_t mPad[0x98];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn649da0(uint32_t* pOut);
};

// FUNCTION: 0x00649da0
void View_649da0_shape06_game::Fn649da0(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_6540c0_shape06_game {
    uint8_t mPad[0x230];
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    void Fn6540c0(uint32_t* pOut);
};

// FUNCTION: 0x006540c0
void View_6540c0_shape06_game::Fn6540c0(uint32_t* pOut)
{
    pOut[0] = mnX;
    pOut[1] = mnY;
    pOut[2] = mnZ;
}

struct View_459580_shape06_game {
    void Fn459580(cIGZString* pOther);
};

// FUNCTION: 0x00459580
void View_459580_shape06_game::Fn459580(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0x4c));
}

struct View_4777f0_shape06_game {
    void Fn4777f0(cIGZString* pOther);
};

// FUNCTION: 0x004777f0
void View_4777f0_shape06_game::Fn4777f0(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0xc));
}

struct View_4abb30_shape06_game {
    void Fn4abb30(cIGZString* pOther);
};

// FUNCTION: 0x004abb30
void View_4abb30_shape06_game::Fn4abb30(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0xbc));
}

struct View_4abb60_shape06_game {
    void Fn4abb60(cIGZString* pOther);
};

// FUNCTION: 0x004abb60
void View_4abb60_shape06_game::Fn4abb60(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0xd0));
}

struct View_4abb90_shape06_game {
    void Fn4abb90(cIGZString* pOther);
};

// FUNCTION: 0x004abb90
void View_4abb90_shape06_game::Fn4abb90(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0xf8));
}

struct View_4abbc0_shape06_game {
    void Fn4abbc0(cIGZString* pOther);
};

// FUNCTION: 0x004abbc0
void View_4abbc0_shape06_game::Fn4abbc0(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0x154));
}

struct View_4abbf0_shape06_game {
    void Fn4abbf0(cIGZString* pOther);
};

// FUNCTION: 0x004abbf0
void View_4abbf0_shape06_game::Fn4abbf0(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0x120));
}

struct View_5d8080_shape06_game {
    void Fn5d8080(cIGZString* pOther);
};

// FUNCTION: 0x005d8080
void View_5d8080_shape06_game::Fn5d8080(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0x4));
}

struct View_60fb60_shape06_game {
    void Fn60fb60(cIGZString* pOther);
};

// FUNCTION: 0x0060fb60
void View_60fb60_shape06_game::Fn60fb60(cIGZString* pOther)
{
    pOther->operator=(*reinterpret_cast<cIGZString*>(reinterpret_cast<char*>(this) + 0x14));
}

struct Base_505480_shape06_game {
    // STUB: 0x505480
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_4fa740_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x004fa740
bool View_4fa740_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xc98f9d4a) {
        return reinterpret_cast<Base_505480_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

struct Base_505d80_shape06_game {
    // STUB: 0x505d80
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_4fa7a0_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x004fa7a0
bool View_4fa7a0_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xc96e75dc) {
        return reinterpret_cast<Base_505d80_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

struct View_5444c0_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005444c0
bool View_5444c0_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xc98f9d17) {
        return reinterpret_cast<Base_505480_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

struct Base_54d7f0_shape06_game {
    // STUB: 0x54d7f0
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_544750_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00544750
bool View_544750_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x896e75af) {
        return reinterpret_cast<Base_54d7f0_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

struct View_55b630_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0055b630
bool View_55b630_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0xa98f9d3b) {
        return reinterpret_cast<Base_505480_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

struct View_55b660_shape06_game : public cIGZUnknown {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0055b660
bool View_55b660_shape06_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x896e714a) {
        return reinterpret_cast<Base_54d7f0_shape06_game*>(this)->QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}
