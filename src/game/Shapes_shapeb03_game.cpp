// Shape families of packet shapeb03_game, written by scratch/s16/gen/shapeb03_game/*.py.
#include "common/types.h"
#include "common/compiler.h"

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

struct View_00990dc0_shapeb03_game {
    uint8_t mPad[0x5c];
    uint8_t mFlag;
    void Fn();
};

// FUNCTION: 0x00990dc0
void View_00990dc0_shapeb03_game::Fn()
{
    mFlag = true;
}

struct View_00445090_shapeb03_game {
    uint8_t mPad[0x3c];
    uint32_t mA;
    uint32_t mB;
    void Fn(uint32_t* pA, uint32_t* pB);
};

// FUNCTION: 0x00445090
void View_00445090_shapeb03_game::Fn(uint32_t* pA, uint32_t* pB)
{
    *pA = mA;
    *pB = mB;
}

struct View_007cb990_shapeb03_game {
    uint8_t mPad[0x12c];
    uint32_t mA;
    uint32_t mB;
    void Fn(uint32_t* pA, uint32_t* pB);
};

// FUNCTION: 0x007cb990
void View_007cb990_shapeb03_game::Fn(uint32_t* pA, uint32_t* pB)
{
    *pA = mA;
    *pB = mB;
}

struct View_007cb9f0_shapeb03_game {
    uint8_t mPad[0x124];
    uint32_t mA;
    uint32_t mB;
    void Fn(uint32_t* pA, uint32_t* pB);
};

// FUNCTION: 0x007cb9f0
void View_007cb9f0_shapeb03_game::Fn(uint32_t* pA, uint32_t* pB)
{
    *pA = mA;
    *pB = mB;
}

struct View_004595d0_shapeb03_game {
    uint8_t mPad[0xec];
    uint32_t mA;
    uint32_t mB;
    void Fn(uint32_t* pA, uint32_t* pB);
};

// FUNCTION: 0x004595d0
void View_004595d0_shapeb03_game::Fn(uint32_t* pA, uint32_t* pB)
{
    *pA = mA;
    *pB = mB;
}

struct View_007d2750_shapeb03_game {
    uint8_t mPad[0x138];
    uint8_t mFlag;
    void Fn();
};

// FUNCTION: 0x007d2750
void View_007d2750_shapeb03_game::Fn()
{
    mFlag = false;
}

struct View_00489a50_shapeb03_game {
    uint32_t mVtable;
    uint32_t mField;
    View_00489a50_shapeb03_game* Fn();
};

// FUNCTION: 0x00489a50
View_00489a50_shapeb03_game* View_00489a50_shapeb03_game::Fn()
{
    mVtable = 0xa8ec1c;
    mField = 0;
    return this;
}

// GLOBAL: 0x00b21738
extern bool gb21738;

struct View_0049c7c0_shapeb03_game {
    bool Fn();
};

// FUNCTION: 0x0049c7c0
bool View_0049c7c0_shapeb03_game::Fn()
{
    if (gb21738) {
        gb21738 = false;
    }
    return true;
}

struct View_007f66a0_shapeb03_game {
    uint8_t mPad[0xc];
    uint32_t mA;
    uint32_t mB;
    void Fn(uint32_t* pA, uint32_t* pB);
};

// FUNCTION: 0x007f66a0
void View_007f66a0_shapeb03_game::Fn(uint32_t* pA, uint32_t* pB)
{
    *pA = mA;
    *pB = mB;
}

struct View_004dc2d0_shapeb03_game {
    uint8_t mPad[0x4c];
    uint32_t mValues[1];
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x004dc2d0
uint32_t View_004dc2d0_shapeb03_game::Fn(uint32_t i)
{
    return mValues[i];
}

struct View_004dc2f0_shapeb03_game {
    uint8_t mPad[0x8c];
    uint32_t mValues[1];
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x004dc2f0
uint32_t View_004dc2f0_shapeb03_game::Fn(uint32_t i)
{
    return mValues[i];
}

struct View_004dcd20_shapeb03_game {
    uint8_t mPad[0x320];
    uint32_t mValues[1];
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x004dcd20
uint32_t View_004dcd20_shapeb03_game::Fn(uint32_t i)
{
    return mValues[i];
}

struct View_004dcd30_shapeb03_game {
    uint8_t mPad[0x11c];
    uint32_t mValues[1];
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x004dcd30
uint32_t View_004dcd30_shapeb03_game::Fn(uint32_t i)
{
    return mValues[i];
}

struct View_004dcd40_shapeb03_game {
    uint8_t mPad[0x15c];
    uint32_t mValues[1];
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x004dcd40
uint32_t View_004dcd40_shapeb03_game::Fn(uint32_t i)
{
    return mValues[i];
}

struct View_00505110_shapeb03_game {
    uint8_t mPad[0x264];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    void Fn(const uint32_t* pSrc);
};

// FUNCTION: 0x00505110
void View_00505110_shapeb03_game::Fn(const uint32_t* pSrc)
{
    mX = pSrc[0];
    mY = pSrc[1];
    mZ = pSrc[2];
}

struct View_00505140_shapeb03_game {
    uint8_t mPad[0x270];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    void Fn(const uint32_t* pSrc);
};

// FUNCTION: 0x00505140
void View_00505140_shapeb03_game::Fn(const uint32_t* pSrc)
{
    mX = pSrc[0];
    mY = pSrc[1];
    mZ = pSrc[2];
}

struct View_005b2230_shapeb03_game {
    uint8_t mPad[0x21a];
    uint8_t mFlag;
    void Fn();
};

// FUNCTION: 0x005b2230
void View_005b2230_shapeb03_game::Fn()
{
    mFlag = true;
}

struct View_005b2ae0_shapeb03_game {
    uint8_t mPad[0x34];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    void Fn(const uint32_t* pSrc);
};

// FUNCTION: 0x005b2ae0
void View_005b2ae0_shapeb03_game::Fn(const uint32_t* pSrc)
{
    mX = pSrc[0];
    mY = pSrc[1];
    mZ = pSrc[2];
}

struct View_005d6380_shapeb03_game {
    uint8_t mPad[0x3c];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    void Fn(const uint32_t* pSrc);
};

// FUNCTION: 0x005d6380
void View_005d6380_shapeb03_game::Fn(const uint32_t* pSrc)
{
    mX = pSrc[0];
    mY = pSrc[1];
    mZ = pSrc[2];
}

struct View_005e2c10_shapeb03_game {
    uint8_t mPad[0x50];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    void Fn(const uint32_t* pSrc);
};

// FUNCTION: 0x005e2c10
void View_005e2c10_shapeb03_game::Fn(const uint32_t* pSrc)
{
    mX = pSrc[0];
    mY = pSrc[1];
    mZ = pSrc[2];
}

struct View_005f4860_shapeb03_game {
    uint32_t mVtable;
    uint32_t mField;
    View_005f4860_shapeb03_game* Fn();
};

// FUNCTION: 0x005f4860
View_005f4860_shapeb03_game* View_005f4860_shapeb03_game::Fn()
{
    mVtable = 0xaa51d8;
    mField = 0;
    return this;
}

// GLOBAL: 0x00b43e60
extern bool gb43e60;

struct View_00605640_shapeb03_game {
    bool Fn();
};

// FUNCTION: 0x00605640
bool View_00605640_shapeb03_game::Fn()
{
    if (gb43e60) {
        gb43e60 = false;
    }
    return true;
}

struct View_00649330_shapeb03_game {
    uint8_t mPad[0x44];
    uint32_t mA;
    uint32_t mB;
    void Fn(uint32_t* pA, uint32_t* pB);
};

// FUNCTION: 0x00649330
void View_00649330_shapeb03_game::Fn(uint32_t* pA, uint32_t* pB)
{
    *pA = mA;
    *pB = mB;
}

struct View_006540f0_shapeb03_game {
    uint8_t mPad[0x230];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    void Fn(const uint32_t* pSrc);
};

// FUNCTION: 0x006540f0
void View_006540f0_shapeb03_game::Fn(const uint32_t* pSrc)
{
    mX = pSrc[0];
    mY = pSrc[1];
    mZ = pSrc[2];
}

struct View_006ead30_shapeb03_game {
    uint8_t mPad[0x270];
    uint32_t mValues[1];
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x006ead30
uint32_t View_006ead30_shapeb03_game::Fn(uint32_t i)
{
    return mValues[i];
}

struct View_006efa00_shapeb03_game {
    uint8_t mPad[0x2e0];
    uint32_t mValues[1];
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x006efa00
uint32_t View_006efa00_shapeb03_game::Fn(uint32_t i)
{
    return mValues[i];
}

struct View_0071fff0_shapeb03_game {
    uint8_t mPad[0x128];
    uint32_t mValues[1];
    uint32_t Fn(uint32_t i);
};

// FUNCTION: 0x0071fff0
uint32_t View_0071fff0_shapeb03_game::Fn(uint32_t i)
{
    return mValues[i];
}

struct View_0048c960_shapeb03_game {
    uint8_t mPad[0x28];
    uint8_t mFlag;
    void Fn();
};

// FUNCTION: 0x0048c960
void View_0048c960_shapeb03_game::Fn()
{
    mFlag = true;
}

struct View_0048c970_shapeb03_game {
    uint8_t mPad[0x28];
    uint8_t mFlag;
    void Fn();
};

// FUNCTION: 0x0048c970
void View_0048c970_shapeb03_game::Fn()
{
    mFlag = false;
}

// GLOBAL: 0x00b21924
extern bool gb21924;

struct View_004d8b70_shapeb03_game {
    bool Fn();
};

// FUNCTION: 0x004d8b70
bool View_004d8b70_shapeb03_game::Fn()
{
    if (gb21924) {
        gb21924 = false;
    }
    return true;
}

struct View_006026f0_shapeb03_game {
    uint8_t mPad[0x8];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    void Fn(const uint32_t* pSrc);
};

// FUNCTION: 0x006026f0
void View_006026f0_shapeb03_game::Fn(const uint32_t* pSrc)
{
    mX = pSrc[0];
    mY = pSrc[1];
    mZ = pSrc[2];
}

// GLOBAL: 0x00b452a8
extern bool gb452a8;

struct View_006232f0_shapeb03_game {
    bool Fn();
};

// FUNCTION: 0x006232f0
bool View_006232f0_shapeb03_game::Fn()
{
    if (gb452a8) {
        gb452a8 = false;
    }
    return true;
}

struct View_0063bf90_shapeb03_game {
    uint8_t mPad[0x4];
    uint8_t mFlag;
    void Fn();
};

// FUNCTION: 0x0063bf90
void View_0063bf90_shapeb03_game::Fn()
{
    mFlag = true;
}

struct View_00649210_shapeb03_game {
    uint8_t mPad[0xc8];
    uint32_t mA;
    uint32_t mB;
    void Fn(uint32_t* pA, uint32_t* pB);
};

// FUNCTION: 0x00649210
void View_00649210_shapeb03_game::Fn(uint32_t* pA, uint32_t* pB)
{
    *pA = mA;
    *pB = mB;
}

struct View_00683f20_shapeb03_game {
    uint8_t mPad[0xf4];
    uint32_t mX;
    uint32_t mY;
    uint32_t mZ;
    void Fn(const uint32_t* pSrc);
};

// FUNCTION: 0x00683f20
void View_00683f20_shapeb03_game::Fn(const uint32_t* pSrc)
{
    mX = pSrc[0];
    mY = pSrc[1];
    mZ = pSrc[2];
}

// GLOBAL: 0x00b49b60
extern bool gb49b60;

struct View_006e0100_shapeb03_game {
    bool Fn();
};

// FUNCTION: 0x006e0100
bool View_006e0100_shapeb03_game::Fn()
{
    if (gb49b60) {
        gb49b60 = false;
    }
    return true;
}

struct View_00734d20_shapeb03_game {
    uint32_t mVtable;
    uint8_t mPad[0x4];
    uint32_t mField;
    View_00734d20_shapeb03_game* Fn();
};

// FUNCTION: 0x00734d20
View_00734d20_shapeb03_game* View_00734d20_shapeb03_game::Fn()
{
    mVtable = 0xab3868;
    mField = 0;
    return this;
}

struct View_00734fb0_shapeb03_game {
    uint32_t mVtable;
    uint32_t mField;
    View_00734fb0_shapeb03_game* Fn();
};

// FUNCTION: 0x00734fb0
View_00734fb0_shapeb03_game* View_00734fb0_shapeb03_game::Fn()
{
    mVtable = 0xab3894;
    mField = 0;
    return this;
}

struct View_007350f0_shapeb03_game {
    uint32_t mVtable;
    uint32_t mField;
    View_007350f0_shapeb03_game* Fn();
};

// FUNCTION: 0x007350f0
View_007350f0_shapeb03_game* View_007350f0_shapeb03_game::Fn()
{
    mVtable = 0xab38a4;
    mField = 0;
    return this;
}

struct View_00735250_shapeb03_game {
    uint32_t mVtable;
    uint32_t mField;
    View_00735250_shapeb03_game* Fn();
};

// FUNCTION: 0x00735250
View_00735250_shapeb03_game* View_00735250_shapeb03_game::Fn()
{
    mVtable = 0xab3884;
    mField = 0;
    return this;
}

// GLOBAL: 0x00b4d524
extern bool gb4d524;

struct View_0075fb20_shapeb03_game {
    bool Fn();
};

// FUNCTION: 0x0075fb20
bool View_0075fb20_shapeb03_game::Fn()
{
    if (gb4d524) {
        gb4d524 = false;
    }
    return true;
}

struct View_00774550_shapeb03_game {
    uint32_t mVtable;
    uint32_t mField;
    View_00774550_shapeb03_game* Fn();
};

// FUNCTION: 0x00774550
View_00774550_shapeb03_game* View_00774550_shapeb03_game::Fn()
{
    mVtable = 0xab51e4;
    mField = 0;
    return this;
}

// GLOBAL: 0x00b4e738
extern bool gb4e738;

struct View_0080d3c0_shapeb03_game {
    bool Fn();
};

// FUNCTION: 0x0080d3c0
bool View_0080d3c0_shapeb03_game::Fn()
{
    if (gb4e738) {
        gb4e738 = false;
    }
    return true;
}

struct View_008f4170_shapeb03_game {
    uint8_t mPad[0x33];
    uint8_t mFlag;
    void Fn();
};

// FUNCTION: 0x008f4170
void View_008f4170_shapeb03_game::Fn()
{
    mFlag = false;
}

struct Elem_00461190_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x461210
    void Assign(const Elem_00461190_shapeb03_game* pSrc);
};

struct View_00461190_shapeb03_game {
    Elem_00461190_shapeb03_game* mpBegin;
    Elem_00461190_shapeb03_game* mpEnd;
    Elem_00461190_shapeb03_game* Erase(Elem_00461190_shapeb03_game* pFirst, Elem_00461190_shapeb03_game* pLast);
};

// FUNCTION: 0x00461190
Elem_00461190_shapeb03_game* View_00461190_shapeb03_game::Erase(Elem_00461190_shapeb03_game* pFirst, Elem_00461190_shapeb03_game* pLast)
{
    int32_t n = mpEnd - pLast;
    Elem_00461190_shapeb03_game* pDest = pFirst;
    for (; n > 0; --n, ++pDest) {
        pDest->Assign(reinterpret_cast<Elem_00461190_shapeb03_game*>(reinterpret_cast<char*>(pDest) + (reinterpret_cast<char*>(pLast) - reinterpret_cast<char*>(pFirst))));
    }
    Elem_00461190_shapeb03_game* pEnd = mpEnd;
    for (Elem_00461190_shapeb03_game* p = pDest; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    mpEnd = pDest;
    return pFirst;
}

struct Elem_00461b90_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x461c10
    void Assign(const Elem_00461b90_shapeb03_game* pSrc);
};

struct View_00461b90_shapeb03_game {
    Elem_00461b90_shapeb03_game* mpBegin;
    Elem_00461b90_shapeb03_game* mpEnd;
    Elem_00461b90_shapeb03_game* Erase(Elem_00461b90_shapeb03_game* pFirst, Elem_00461b90_shapeb03_game* pLast);
};

// FUNCTION: 0x00461b90
Elem_00461b90_shapeb03_game* View_00461b90_shapeb03_game::Erase(Elem_00461b90_shapeb03_game* pFirst, Elem_00461b90_shapeb03_game* pLast)
{
    int32_t n = mpEnd - pLast;
    Elem_00461b90_shapeb03_game* pDest = pFirst;
    for (; n > 0; --n, ++pDest) {
        pDest->Assign(reinterpret_cast<Elem_00461b90_shapeb03_game*>(reinterpret_cast<char*>(pDest) + (reinterpret_cast<char*>(pLast) - reinterpret_cast<char*>(pFirst))));
    }
    Elem_00461b90_shapeb03_game* pEnd = mpEnd;
    for (Elem_00461b90_shapeb03_game* p = pDest; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    mpEnd = pDest;
    return pFirst;
}

struct Elem_00462b90_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x462c10
    void Assign(const Elem_00462b90_shapeb03_game* pSrc);
};

struct View_00462b90_shapeb03_game {
    Elem_00462b90_shapeb03_game* mpBegin;
    Elem_00462b90_shapeb03_game* mpEnd;
    Elem_00462b90_shapeb03_game* Erase(Elem_00462b90_shapeb03_game* pFirst, Elem_00462b90_shapeb03_game* pLast);
};

// FUNCTION: 0x00462b90
Elem_00462b90_shapeb03_game* View_00462b90_shapeb03_game::Erase(Elem_00462b90_shapeb03_game* pFirst, Elem_00462b90_shapeb03_game* pLast)
{
    int32_t n = mpEnd - pLast;
    Elem_00462b90_shapeb03_game* pDest = pFirst;
    for (; n > 0; --n, ++pDest) {
        pDest->Assign(reinterpret_cast<Elem_00462b90_shapeb03_game*>(reinterpret_cast<char*>(pDest) + (reinterpret_cast<char*>(pLast) - reinterpret_cast<char*>(pFirst))));
    }
    Elem_00462b90_shapeb03_game* pEnd = mpEnd;
    for (Elem_00462b90_shapeb03_game* p = pDest; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    mpEnd = pDest;
    return pFirst;
}

struct Elem_00463c70_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x463cf0
    void Assign(const Elem_00463c70_shapeb03_game* pSrc);
};

struct View_00463c70_shapeb03_game {
    Elem_00463c70_shapeb03_game* mpBegin;
    Elem_00463c70_shapeb03_game* mpEnd;
    Elem_00463c70_shapeb03_game* Erase(Elem_00463c70_shapeb03_game* pFirst, Elem_00463c70_shapeb03_game* pLast);
};

// FUNCTION: 0x00463c70
Elem_00463c70_shapeb03_game* View_00463c70_shapeb03_game::Erase(Elem_00463c70_shapeb03_game* pFirst, Elem_00463c70_shapeb03_game* pLast)
{
    int32_t n = mpEnd - pLast;
    Elem_00463c70_shapeb03_game* pDest = pFirst;
    for (; n > 0; --n, ++pDest) {
        pDest->Assign(reinterpret_cast<Elem_00463c70_shapeb03_game*>(reinterpret_cast<char*>(pDest) + (reinterpret_cast<char*>(pLast) - reinterpret_cast<char*>(pFirst))));
    }
    Elem_00463c70_shapeb03_game* pEnd = mpEnd;
    for (Elem_00463c70_shapeb03_game* p = pDest; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    mpEnd = pDest;
    return pFirst;
}

struct Elem_004643b0_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x464430
    void Assign(const Elem_004643b0_shapeb03_game* pSrc);
};

struct View_004643b0_shapeb03_game {
    Elem_004643b0_shapeb03_game* mpBegin;
    Elem_004643b0_shapeb03_game* mpEnd;
    Elem_004643b0_shapeb03_game* Erase(Elem_004643b0_shapeb03_game* pFirst, Elem_004643b0_shapeb03_game* pLast);
};

// FUNCTION: 0x004643b0
Elem_004643b0_shapeb03_game* View_004643b0_shapeb03_game::Erase(Elem_004643b0_shapeb03_game* pFirst, Elem_004643b0_shapeb03_game* pLast)
{
    int32_t n = mpEnd - pLast;
    Elem_004643b0_shapeb03_game* pDest = pFirst;
    for (; n > 0; --n, ++pDest) {
        pDest->Assign(reinterpret_cast<Elem_004643b0_shapeb03_game*>(reinterpret_cast<char*>(pDest) + (reinterpret_cast<char*>(pLast) - reinterpret_cast<char*>(pFirst))));
    }
    Elem_004643b0_shapeb03_game* pEnd = mpEnd;
    for (Elem_004643b0_shapeb03_game* p = pDest; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    mpEnd = pDest;
    return pFirst;
}

struct Elem_00464f40_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x464fc0
    void Assign(const Elem_00464f40_shapeb03_game* pSrc);
};

struct View_00464f40_shapeb03_game {
    Elem_00464f40_shapeb03_game* mpBegin;
    Elem_00464f40_shapeb03_game* mpEnd;
    Elem_00464f40_shapeb03_game* Erase(Elem_00464f40_shapeb03_game* pFirst, Elem_00464f40_shapeb03_game* pLast);
};

// FUNCTION: 0x00464f40
Elem_00464f40_shapeb03_game* View_00464f40_shapeb03_game::Erase(Elem_00464f40_shapeb03_game* pFirst, Elem_00464f40_shapeb03_game* pLast)
{
    int32_t n = mpEnd - pLast;
    Elem_00464f40_shapeb03_game* pDest = pFirst;
    for (; n > 0; --n, ++pDest) {
        pDest->Assign(reinterpret_cast<Elem_00464f40_shapeb03_game*>(reinterpret_cast<char*>(pDest) + (reinterpret_cast<char*>(pLast) - reinterpret_cast<char*>(pFirst))));
    }
    Elem_00464f40_shapeb03_game* pEnd = mpEnd;
    for (Elem_00464f40_shapeb03_game* p = pDest; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    mpEnd = pDest;
    return pFirst;
}

struct Elem_00465990_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x465a10
    void Assign(const Elem_00465990_shapeb03_game* pSrc);
};

struct View_00465990_shapeb03_game {
    Elem_00465990_shapeb03_game* mpBegin;
    Elem_00465990_shapeb03_game* mpEnd;
    Elem_00465990_shapeb03_game* Erase(Elem_00465990_shapeb03_game* pFirst, Elem_00465990_shapeb03_game* pLast);
};

// FUNCTION: 0x00465990
Elem_00465990_shapeb03_game* View_00465990_shapeb03_game::Erase(Elem_00465990_shapeb03_game* pFirst, Elem_00465990_shapeb03_game* pLast)
{
    int32_t n = mpEnd - pLast;
    Elem_00465990_shapeb03_game* pDest = pFirst;
    for (; n > 0; --n, ++pDest) {
        pDest->Assign(reinterpret_cast<Elem_00465990_shapeb03_game*>(reinterpret_cast<char*>(pDest) + (reinterpret_cast<char*>(pLast) - reinterpret_cast<char*>(pFirst))));
    }
    Elem_00465990_shapeb03_game* pEnd = mpEnd;
    for (Elem_00465990_shapeb03_game* p = pDest; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    mpEnd = pDest;
    return pFirst;
}

struct Elem_00479760_shapeb03_game {
    uint8_t mPad1[0x28];
    void* mpData;
    uint8_t mPad2[0x8];
};

struct View_00479760_shapeb03_game {
    Elem_00479760_shapeb03_game* mpBegin;
    Elem_00479760_shapeb03_game* mpEnd;
    void Free();
};

// FUNCTION: 0x00479760
void View_00479760_shapeb03_game::Free()
{
    Elem_00479760_shapeb03_game* p = mpBegin;
    Elem_00479760_shapeb03_game* pEnd = mpEnd;
    for (; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    if (mpBegin) {
        Fn0090cf63(mpBegin);
    }
}

struct Elem_0058a420_shapeb03_game {
    uint8_t mPad1[0x4];
    void* mpData;
    uint8_t mPad2[0x10];
};

struct View_0058a420_shapeb03_game {
    Elem_0058a420_shapeb03_game* mpBegin;
    Elem_0058a420_shapeb03_game* mpEnd;
    void Free();
};

// FUNCTION: 0x0058a420
void View_0058a420_shapeb03_game::Free()
{
    Elem_0058a420_shapeb03_game* p = mpBegin;
    Elem_0058a420_shapeb03_game* pEnd = mpEnd;
    for (; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    if (mpBegin) {
        Fn0090cf63(mpBegin);
    }
}

struct Elem_0058a880_shapeb03_game {
    uint8_t mPad1[0x4];
    void* mpData;
    uint8_t mPad2[0x8];
};

struct View_0058a880_shapeb03_game {
    Elem_0058a880_shapeb03_game* mpBegin;
    Elem_0058a880_shapeb03_game* mpEnd;
    void Free();
};

// FUNCTION: 0x0058a880
void View_0058a880_shapeb03_game::Free()
{
    Elem_0058a880_shapeb03_game* p = mpBegin;
    Elem_0058a880_shapeb03_game* pEnd = mpEnd;
    for (; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    if (mpBegin) {
        Fn0090cf63(mpBegin);
    }
}

struct Elem_005bddf0_shapeb03_game {
    uint8_t mPad1[0x8];
    void* mpData;
    uint8_t mPad2[0x8];
};

struct View_005bddf0_shapeb03_game {
    Elem_005bddf0_shapeb03_game* mpBegin;
    Elem_005bddf0_shapeb03_game* mpEnd;
    void Free();
};

// FUNCTION: 0x005bddf0
void View_005bddf0_shapeb03_game::Free()
{
    Elem_005bddf0_shapeb03_game* p = mpBegin;
    Elem_005bddf0_shapeb03_game* pEnd = mpEnd;
    for (; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    if (mpBegin) {
        Fn0090cf63(mpBegin);
    }
}

struct Elem_0062be40_shapeb03_game {
    uint8_t mPad1[0x1c];
    void* mpData;
    uint8_t mPad2[0x8];
};

struct View_0062be40_shapeb03_game {
    Elem_0062be40_shapeb03_game* mpBegin;
    Elem_0062be40_shapeb03_game* mpEnd;
    void Free();
};

// FUNCTION: 0x0062be40
void View_0062be40_shapeb03_game::Free()
{
    Elem_0062be40_shapeb03_game* p = mpBegin;
    Elem_0062be40_shapeb03_game* pEnd = mpEnd;
    for (; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    if (mpBegin) {
        Fn0090cf63(mpBegin);
    }
}

struct Elem_0062bf20_shapeb03_game {
    uint8_t mPad1[0x44];
    void* mpData;
    uint8_t mPad2[0x8];
};

struct View_0062bf20_shapeb03_game {
    Elem_0062bf20_shapeb03_game* mpBegin;
    Elem_0062bf20_shapeb03_game* mpEnd;
    void Free();
};

// FUNCTION: 0x0062bf20
void View_0062bf20_shapeb03_game::Free()
{
    Elem_0062bf20_shapeb03_game* p = mpBegin;
    Elem_0062bf20_shapeb03_game* pEnd = mpEnd;
    for (; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    if (mpBegin) {
        Fn0090cf63(mpBegin);
    }
}

struct Elem_006502b0_shapeb03_game {
    uint8_t mPad1[0x18];
    void* mpData;
    uint8_t mPad2[0x14];
};

struct View_006502b0_shapeb03_game {
    Elem_006502b0_shapeb03_game* mpBegin;
    Elem_006502b0_shapeb03_game* mpEnd;
    void Free();
};

// FUNCTION: 0x006502b0
void View_006502b0_shapeb03_game::Free()
{
    Elem_006502b0_shapeb03_game* p = mpBegin;
    Elem_006502b0_shapeb03_game* pEnd = mpEnd;
    for (; p != pEnd; ++p) {
        if (p->mpData) {
            Fn0090cf63(p->mpData);
        }
    }
    if (mpBegin) {
        Fn0090cf63(mpBegin);
    }
}

struct OB_NOVTABLE Obj_004676a0_shapeb03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Release() = 0;
};

struct Node_004676a0_shapeb03_game {
    uint32_t mUnused0;
    uint32_t mUnused1;
    Node_004676a0_shapeb03_game* mpNext;
    Node_004676a0_shapeb03_game* mpChild;
    Obj_004676a0_shapeb03_game* mpObj;
};

struct View_004676a0_shapeb03_game {
    void Erase(Node_004676a0_shapeb03_game* pNode);
};

// FUNCTION: 0x004676a0
void View_004676a0_shapeb03_game::Erase(Node_004676a0_shapeb03_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Obj_004676a0_shapeb03_game* pObj = pNode->mpObj;
        Node_004676a0_shapeb03_game* pNext = pNode->mpNext;
        if (pObj) {
            pObj->Release();
        }
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct OB_NOVTABLE Obj_004676e0_shapeb03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Release() = 0;
};

struct Node_004676e0_shapeb03_game {
    uint32_t mUnused0;
    uint32_t mUnused1;
    Node_004676e0_shapeb03_game* mpNext;
    Node_004676e0_shapeb03_game* mpChild;
    Obj_004676e0_shapeb03_game* mpObj;
};

struct View_004676e0_shapeb03_game {
    void Erase(Node_004676e0_shapeb03_game* pNode);
};

// FUNCTION: 0x004676e0
void View_004676e0_shapeb03_game::Erase(Node_004676e0_shapeb03_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Obj_004676e0_shapeb03_game* pObj = pNode->mpObj;
        Node_004676e0_shapeb03_game* pNext = pNode->mpNext;
        if (pObj) {
            pObj->Release();
        }
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct OB_NOVTABLE Obj_00418c40_shapeb03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Release() = 0;
};

struct Node_00418c40_shapeb03_game {
    uint32_t mUnused0;
    uint32_t mUnused1;
    Node_00418c40_shapeb03_game* mpNext;
    Node_00418c40_shapeb03_game* mpChild;
    uint8_t mPad[0x4];
    Obj_00418c40_shapeb03_game* mpObj;
};

struct View_00418c40_shapeb03_game {
    void Erase(Node_00418c40_shapeb03_game* pNode);
};

// FUNCTION: 0x00418c40
void View_00418c40_shapeb03_game::Erase(Node_00418c40_shapeb03_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Obj_00418c40_shapeb03_game* pObj = pNode->mpObj;
        Node_00418c40_shapeb03_game* pNext = pNode->mpNext;
        if (pObj) {
            pObj->Release();
        }
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct OB_NOVTABLE Obj_0040e050_shapeb03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Release() = 0;
};

struct Node_0040e050_shapeb03_game {
    uint32_t mUnused0;
    uint32_t mUnused1;
    Node_0040e050_shapeb03_game* mpNext;
    Node_0040e050_shapeb03_game* mpChild;
    Obj_0040e050_shapeb03_game* mpObj;
};

struct View_0040e050_shapeb03_game {
    void Erase(Node_0040e050_shapeb03_game* pNode);
};

// FUNCTION: 0x0040e050
void View_0040e050_shapeb03_game::Erase(Node_0040e050_shapeb03_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Obj_0040e050_shapeb03_game* pObj = pNode->mpObj;
        Node_0040e050_shapeb03_game* pNext = pNode->mpNext;
        if (pObj) {
            pObj->Release();
        }
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct OB_NOVTABLE Obj_005d2880_shapeb03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Release() = 0;
};

struct Node_005d2880_shapeb03_game {
    uint32_t mUnused0;
    uint32_t mUnused1;
    Node_005d2880_shapeb03_game* mpNext;
    Node_005d2880_shapeb03_game* mpChild;
    uint8_t mPad[0x4];
    Obj_005d2880_shapeb03_game* mpObj;
};

struct View_005d2880_shapeb03_game {
    void Erase(Node_005d2880_shapeb03_game* pNode);
};

// FUNCTION: 0x005d2880
void View_005d2880_shapeb03_game::Erase(Node_005d2880_shapeb03_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Obj_005d2880_shapeb03_game* pObj = pNode->mpObj;
        Node_005d2880_shapeb03_game* pNext = pNode->mpNext;
        if (pObj) {
            pObj->Release();
        }
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct OB_NOVTABLE Obj_0066e360_shapeb03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Release() = 0;
};

struct Node_0066e360_shapeb03_game {
    uint32_t mUnused0;
    uint32_t mUnused1;
    Node_0066e360_shapeb03_game* mpNext;
    Node_0066e360_shapeb03_game* mpChild;
    uint8_t mPad[0x4];
    Obj_0066e360_shapeb03_game* mpObj;
};

struct View_0066e360_shapeb03_game {
    void Erase(Node_0066e360_shapeb03_game* pNode);
};

// FUNCTION: 0x0066e360
void View_0066e360_shapeb03_game::Erase(Node_0066e360_shapeb03_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Obj_0066e360_shapeb03_game* pObj = pNode->mpObj;
        Node_0066e360_shapeb03_game* pNext = pNode->mpNext;
        if (pObj) {
            pObj->Release();
        }
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct OB_NOVTABLE Obj_0080dfc0_shapeb03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Release() = 0;
};

struct Node_0080dfc0_shapeb03_game {
    uint32_t mUnused0;
    uint32_t mUnused1;
    Node_0080dfc0_shapeb03_game* mpNext;
    Node_0080dfc0_shapeb03_game* mpChild;
    uint8_t mPad[0x4];
    Obj_0080dfc0_shapeb03_game* mpObj;
};

struct View_0080dfc0_shapeb03_game {
    void Erase(Node_0080dfc0_shapeb03_game* pNode);
};

// FUNCTION: 0x0080dfc0
void View_0080dfc0_shapeb03_game::Erase(Node_0080dfc0_shapeb03_game* pNode)
{
    while (pNode) {
        Erase(pNode->mpChild);
        Obj_0080dfc0_shapeb03_game* pObj = pNode->mpObj;
        Node_0080dfc0_shapeb03_game* pNext = pNode->mpNext;
        if (pObj) {
            pObj->Release();
        }
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct OB_NOVTABLE Ref_0048c060_shapeb03_game {
    virtual void S0() = 0;
    virtual void AddRef() = 0;
};

struct Primary_0048c060_shapeb03_game {
    uint8_t mPad[0x8];
    // STUB: 0x9457c6
    bool QueryInterface(uint32_t iid, void** ppOut);
};

struct Secondary_0048c060_shapeb03_game {
    uint32_t mField;
};

struct View_0048c060_shapeb03_game : Primary_0048c060_shapeb03_game, Secondary_0048c060_shapeb03_game {
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x0048c060
bool View_0048c060_shapeb03_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid != 0x452294aa) {
        return Primary_0048c060_shapeb03_game::QueryInterface(iid, ppOut);
    }
    *ppOut = static_cast<Secondary_0048c060_shapeb03_game*>(this);
    reinterpret_cast<Ref_0048c060_shapeb03_game*>(this)->AddRef();
    return true;
}

struct OB_NOVTABLE Ref_005c1f40_shapeb03_game {
    virtual void S0() = 0;
    virtual void AddRef() = 0;
};

struct Primary_005c1f40_shapeb03_game {
    uint8_t mPad[0x1c];
    // STUB: 0x91dd67
    bool QueryInterface(uint32_t iid, void** ppOut);
};

struct Secondary_005c1f40_shapeb03_game {
    uint32_t mField;
};

struct View_005c1f40_shapeb03_game : Primary_005c1f40_shapeb03_game, Secondary_005c1f40_shapeb03_game {
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x005c1f40
bool View_005c1f40_shapeb03_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid != 0x1cab77d5) {
        return Primary_005c1f40_shapeb03_game::QueryInterface(iid, ppOut);
    }
    *ppOut = static_cast<Secondary_005c1f40_shapeb03_game*>(this);
    reinterpret_cast<Ref_005c1f40_shapeb03_game*>(this)->AddRef();
    return true;
}

struct OB_NOVTABLE Ref_005d1780_shapeb03_game {
    virtual void S0() = 0;
    virtual void AddRef() = 0;
};

struct Primary_005d1780_shapeb03_game {
    uint8_t mPad[0x8];
    // STUB: 0x9457c6
    bool QueryInterface(uint32_t iid, void** ppOut);
};

struct Secondary_005d1780_shapeb03_game {
    uint32_t mField;
};

struct View_005d1780_shapeb03_game : Primary_005d1780_shapeb03_game, Secondary_005d1780_shapeb03_game {
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x005d1780
bool View_005d1780_shapeb03_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid != 0x699899ea) {
        return Primary_005d1780_shapeb03_game::QueryInterface(iid, ppOut);
    }
    *ppOut = static_cast<Secondary_005d1780_shapeb03_game*>(this);
    reinterpret_cast<Ref_005d1780_shapeb03_game*>(this)->AddRef();
    return true;
}

struct OB_NOVTABLE Ref_00985d00_shapeb03_game {
    virtual void S0() = 0;
    virtual void AddRef() = 0;
};

struct Primary_00985d00_shapeb03_game {
    uint8_t mPad[0x1c];
    // STUB: 0x91dd67
    bool QueryInterface(uint32_t iid, void** ppOut);
};

struct Secondary_00985d00_shapeb03_game {
    uint32_t mField;
};

struct View_00985d00_shapeb03_game : Primary_00985d00_shapeb03_game, Secondary_00985d00_shapeb03_game {
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x00985d00
bool View_00985d00_shapeb03_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid != 0xe3260321) {
        return Primary_00985d00_shapeb03_game::QueryInterface(iid, ppOut);
    }
    *ppOut = static_cast<Secondary_00985d00_shapeb03_game*>(this);
    reinterpret_cast<Ref_00985d00_shapeb03_game*>(this)->AddRef();
    return true;
}

struct OB_NOVTABLE Ref_004e08c0_shapeb03_game {
    virtual void S0() = 0;
    virtual void AddRef() = 0;
};

struct Primary_004e08c0_shapeb03_game {
    uint8_t mPad[0xd8];
    // STUB: 0x99b774
    bool QueryInterface(uint32_t iid, void** ppOut);
};

struct Secondary_004e08c0_shapeb03_game {
    uint32_t mField;
};

struct View_004e08c0_shapeb03_game : Primary_004e08c0_shapeb03_game, Secondary_004e08c0_shapeb03_game {
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x004e08c0
bool View_004e08c0_shapeb03_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid != 0x452294aa) {
        return Primary_004e08c0_shapeb03_game::QueryInterface(iid, ppOut);
    }
    *ppOut = static_cast<Secondary_004e08c0_shapeb03_game*>(this);
    reinterpret_cast<Ref_004e08c0_shapeb03_game*>(this)->AddRef();
    return true;
}

struct OB_NOVTABLE Ref_0066b190_shapeb03_game {
    virtual void S0() = 0;
    virtual void AddRef() = 0;
};

struct Primary_0066b190_shapeb03_game {
    uint8_t mPad[0x100];
    // STUB: 0x687910
    bool QueryInterface(uint32_t iid, void** ppOut);
};

struct Secondary_0066b190_shapeb03_game {
    uint32_t mField;
};

struct View_0066b190_shapeb03_game : Primary_0066b190_shapeb03_game, Secondary_0066b190_shapeb03_game {
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x0066b190
bool View_0066b190_shapeb03_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid != 0x273b784c) {
        return Primary_0066b190_shapeb03_game::QueryInterface(iid, ppOut);
    }
    *ppOut = static_cast<Secondary_0066b190_shapeb03_game*>(this);
    reinterpret_cast<Ref_0066b190_shapeb03_game*>(this)->AddRef();
    return true;
}

struct OB_NOVTABLE Ref_0098ad80_shapeb03_game {
    virtual void S0() = 0;
    virtual void AddRef() = 0;
};

struct Primary_0098ad80_shapeb03_game {
    uint8_t mPad[0x174];
    // STUB: 0x98def0
    bool QueryInterface(uint32_t iid, void** ppOut);
};

struct Secondary_0098ad80_shapeb03_game {
    uint32_t mField;
};

struct View_0098ad80_shapeb03_game : Primary_0098ad80_shapeb03_game, Secondary_0098ad80_shapeb03_game {
    bool QueryInterface(uint32_t iid, void** ppOut);
};

// FUNCTION: 0x0098ad80
bool View_0098ad80_shapeb03_game::QueryInterface(uint32_t iid, void** ppOut)
{
    if (iid != 0x5ad24c36) {
        return Primary_0098ad80_shapeb03_game::QueryInterface(iid, ppOut);
    }
    *ppOut = static_cast<Secondary_0098ad80_shapeb03_game*>(this);
    reinterpret_cast<Ref_0098ad80_shapeb03_game*>(this)->AddRef();
    return true;
}

struct Inner_00823710_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x004089b0
    void Construct(const void* pSrc, uint32_t nPos, uint32_t nCount, uint8_t* pAlloc);
};

struct Str_00823710_shapeb03_game {
    uint32_t mVtable;
    Inner_00823710_shapeb03_game mString;
    uint32_t mRefs;
};

struct Pad8_00823710_shapeb03_game {
    uint8_t mPad0;
    uint8_t mFlag;
    uint8_t mPad[6];
};

struct Sub_00823710_shapeb03_game {
    uint32_t mA;
    uint32_t mB;
};

struct View_00823710_shapeb03_game : Pad8_00823710_shapeb03_game, Sub_00823710_shapeb03_game {
    uint8_t mPad[0xc];
    uint8_t mResult[1];
    // STUB: 0x008231b0
    void ParseURL(Str_00823710_shapeb03_game* pStr);
    uint8_t* Fn();
};

// FUNCTION: 0x00823710
uint8_t* View_00823710_shapeb03_game::Fn()
{
    if (!mFlag) {
        uint8_t alloc;
        Str_00823710_shapeb03_game str;
        Sub_00823710_shapeb03_game* pSub = this;
        str.mString.Construct(pSub ? &pSub->mB : 0, 0, 0xffffffff, &alloc);
        str.mVtable = 0xa80810;
        str.mRefs = 0;
        ParseURL(&str);
        if (str.mString.mpData) {
            Fn0090cf63(str.mString.mpData);
        }
    }
    return mResult;
}

struct Inner_00823780_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x004089b0
    void Construct(const void* pSrc, uint32_t nPos, uint32_t nCount, uint8_t* pAlloc);
};

struct Str_00823780_shapeb03_game {
    uint32_t mVtable;
    Inner_00823780_shapeb03_game mString;
    uint32_t mRefs;
};

struct Pad8_00823780_shapeb03_game {
    uint8_t mPad0;
    uint8_t mFlag;
    uint8_t mPad[6];
};

struct Sub_00823780_shapeb03_game {
    uint32_t mA;
    uint32_t mB;
};

struct View_00823780_shapeb03_game : Pad8_00823780_shapeb03_game, Sub_00823780_shapeb03_game {
    uint8_t mPad[0x20];
    uint8_t mResult[1];
    // STUB: 0x008231b0
    void ParseURL(Str_00823780_shapeb03_game* pStr);
    uint8_t* Fn();
};

// FUNCTION: 0x00823780
uint8_t* View_00823780_shapeb03_game::Fn()
{
    if (!mFlag) {
        uint8_t alloc;
        Str_00823780_shapeb03_game str;
        Sub_00823780_shapeb03_game* pSub = this;
        str.mString.Construct(pSub ? &pSub->mB : 0, 0, 0xffffffff, &alloc);
        str.mVtable = 0xa80810;
        str.mRefs = 0;
        ParseURL(&str);
        if (str.mString.mpData) {
            Fn0090cf63(str.mString.mpData);
        }
    }
    return mResult;
}

struct Inner_008237f0_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x004089b0
    void Construct(const void* pSrc, uint32_t nPos, uint32_t nCount, uint8_t* pAlloc);
};

struct Str_008237f0_shapeb03_game {
    uint32_t mVtable;
    Inner_008237f0_shapeb03_game mString;
    uint32_t mRefs;
};

struct Pad8_008237f0_shapeb03_game {
    uint8_t mPad0;
    uint8_t mFlag;
    uint8_t mPad[6];
};

struct Sub_008237f0_shapeb03_game {
    uint32_t mA;
    uint32_t mB;
};

struct View_008237f0_shapeb03_game : Pad8_008237f0_shapeb03_game, Sub_008237f0_shapeb03_game {
    uint8_t mPad[0x34];
    uint8_t mResult[1];
    // STUB: 0x008231b0
    void ParseURL(Str_008237f0_shapeb03_game* pStr);
    uint8_t* Fn();
};

// FUNCTION: 0x008237f0
uint8_t* View_008237f0_shapeb03_game::Fn()
{
    if (!mFlag) {
        uint8_t alloc;
        Str_008237f0_shapeb03_game str;
        Sub_008237f0_shapeb03_game* pSub = this;
        str.mString.Construct(pSub ? &pSub->mB : 0, 0, 0xffffffff, &alloc);
        str.mVtable = 0xa80810;
        str.mRefs = 0;
        ParseURL(&str);
        if (str.mString.mpData) {
            Fn0090cf63(str.mString.mpData);
        }
    }
    return mResult;
}

struct Inner_00823860_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x004089b0
    void Construct(const void* pSrc, uint32_t nPos, uint32_t nCount, uint8_t* pAlloc);
};

struct Str_00823860_shapeb03_game {
    uint32_t mVtable;
    Inner_00823860_shapeb03_game mString;
    uint32_t mRefs;
};

struct Pad8_00823860_shapeb03_game {
    uint8_t mPad0;
    uint8_t mFlag;
    uint8_t mPad[6];
};

struct Sub_00823860_shapeb03_game {
    uint32_t mA;
    uint32_t mB;
};

struct View_00823860_shapeb03_game : Pad8_00823860_shapeb03_game, Sub_00823860_shapeb03_game {
    uint8_t mPad[0x48];
    uint8_t mResult[1];
    // STUB: 0x008231b0
    void ParseURL(Str_00823860_shapeb03_game* pStr);
    uint8_t* Fn();
};

// FUNCTION: 0x00823860
uint8_t* View_00823860_shapeb03_game::Fn()
{
    if (!mFlag) {
        uint8_t alloc;
        Str_00823860_shapeb03_game str;
        Sub_00823860_shapeb03_game* pSub = this;
        str.mString.Construct(pSub ? &pSub->mB : 0, 0, 0xffffffff, &alloc);
        str.mVtable = 0xa80810;
        str.mRefs = 0;
        ParseURL(&str);
        if (str.mString.mpData) {
            Fn0090cf63(str.mString.mpData);
        }
    }
    return mResult;
}

struct Inner_008238d0_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x004089b0
    void Construct(const void* pSrc, uint32_t nPos, uint32_t nCount, uint8_t* pAlloc);
};

struct Str_008238d0_shapeb03_game {
    uint32_t mVtable;
    Inner_008238d0_shapeb03_game mString;
    uint32_t mRefs;
};

struct Pad8_008238d0_shapeb03_game {
    uint8_t mPad0;
    uint8_t mFlag;
    uint8_t mPad[6];
};

struct Sub_008238d0_shapeb03_game {
    uint32_t mA;
    uint32_t mB;
};

struct View_008238d0_shapeb03_game : Pad8_008238d0_shapeb03_game, Sub_008238d0_shapeb03_game {
    uint8_t mPad[0x5c];
    uint8_t mResult[1];
    // STUB: 0x008231b0
    void ParseURL(Str_008238d0_shapeb03_game* pStr);
    uint8_t* Fn();
};

// FUNCTION: 0x008238d0
uint8_t* View_008238d0_shapeb03_game::Fn()
{
    if (!mFlag) {
        uint8_t alloc;
        Str_008238d0_shapeb03_game str;
        Sub_008238d0_shapeb03_game* pSub = this;
        str.mString.Construct(pSub ? &pSub->mB : 0, 0, 0xffffffff, &alloc);
        str.mVtable = 0xa80810;
        str.mRefs = 0;
        ParseURL(&str);
        if (str.mString.mpData) {
            Fn0090cf63(str.mString.mpData);
        }
    }
    return mResult;
}

struct Inner_00823940_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x004089b0
    void Construct(const void* pSrc, uint32_t nPos, uint32_t nCount, uint8_t* pAlloc);
};

struct Str_00823940_shapeb03_game {
    uint32_t mVtable;
    Inner_00823940_shapeb03_game mString;
    uint32_t mRefs;
};

struct Pad8_00823940_shapeb03_game {
    uint8_t mPad0;
    uint8_t mFlag;
    uint8_t mPad[6];
};

struct Sub_00823940_shapeb03_game {
    uint32_t mA;
    uint32_t mB;
};

struct View_00823940_shapeb03_game : Pad8_00823940_shapeb03_game, Sub_00823940_shapeb03_game {
    uint8_t mPad[0x70];
    uint8_t mResult[1];
    // STUB: 0x008231b0
    void ParseURL(Str_00823940_shapeb03_game* pStr);
    uint8_t* Fn();
};

// FUNCTION: 0x00823940
uint8_t* View_00823940_shapeb03_game::Fn()
{
    if (!mFlag) {
        uint8_t alloc;
        Str_00823940_shapeb03_game str;
        Sub_00823940_shapeb03_game* pSub = this;
        str.mString.Construct(pSub ? &pSub->mB : 0, 0, 0xffffffff, &alloc);
        str.mVtable = 0xa80810;
        str.mRefs = 0;
        ParseURL(&str);
        if (str.mString.mpData) {
            Fn0090cf63(str.mString.mpData);
        }
    }
    return mResult;
}

struct Inner_008239b0_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x004089b0
    void Construct(const void* pSrc, uint32_t nPos, uint32_t nCount, uint8_t* pAlloc);
};

struct Str_008239b0_shapeb03_game {
    uint32_t mVtable;
    Inner_008239b0_shapeb03_game mString;
    uint32_t mRefs;
};

struct Pad8_008239b0_shapeb03_game {
    uint8_t mPad0;
    uint8_t mFlag;
    uint8_t mPad[6];
};

struct Sub_008239b0_shapeb03_game {
    uint32_t mA;
    uint32_t mB;
};

struct View_008239b0_shapeb03_game : Pad8_008239b0_shapeb03_game, Sub_008239b0_shapeb03_game {
    uint8_t mPad[0x84];
    uint8_t mResult[1];
    // STUB: 0x008231b0
    void ParseURL(Str_008239b0_shapeb03_game* pStr);
    uint8_t* Fn();
};

// FUNCTION: 0x008239b0
uint8_t* View_008239b0_shapeb03_game::Fn()
{
    if (!mFlag) {
        uint8_t alloc;
        Str_008239b0_shapeb03_game str;
        Sub_008239b0_shapeb03_game* pSub = this;
        str.mString.Construct(pSub ? &pSub->mB : 0, 0, 0xffffffff, &alloc);
        str.mVtable = 0xa80810;
        str.mRefs = 0;
        ParseURL(&str);
        if (str.mString.mpData) {
            Fn0090cf63(str.mString.mpData);
        }
    }
    return mResult;
}

struct Inner_00823a20_shapeb03_game {
    void* mpData;
    uint32_t mB;
    uint32_t mC;
    // STUB: 0x004089b0
    void Construct(const void* pSrc, uint32_t nPos, uint32_t nCount, uint8_t* pAlloc);
};

struct Str_00823a20_shapeb03_game {
    uint32_t mVtable;
    Inner_00823a20_shapeb03_game mString;
    uint32_t mRefs;
};

struct Pad8_00823a20_shapeb03_game {
    uint8_t mPad0;
    uint8_t mFlag;
    uint8_t mPad[6];
};

struct Sub_00823a20_shapeb03_game {
    uint32_t mA;
    uint32_t mB;
};

struct View_00823a20_shapeb03_game : Pad8_00823a20_shapeb03_game, Sub_00823a20_shapeb03_game {
    uint8_t mPad[0x98];
    uint8_t mResult[1];
    // STUB: 0x008231b0
    void ParseURL(Str_00823a20_shapeb03_game* pStr);
    uint8_t* Fn();
};

// FUNCTION: 0x00823a20
uint8_t* View_00823a20_shapeb03_game::Fn()
{
    if (!mFlag) {
        uint8_t alloc;
        Str_00823a20_shapeb03_game str;
        Sub_00823a20_shapeb03_game* pSub = this;
        str.mString.Construct(pSub ? &pSub->mB : 0, 0, 0xffffffff, &alloc);
        str.mVtable = 0xa80810;
        str.mRefs = 0;
        ParseURL(&str);
        if (str.mString.mpData) {
            Fn0090cf63(str.mString.mpData);
        }
    }
    return mResult;
}

struct Elem_00461310_shapeb03_game {
    void* mpBegin;
    void* mpEnd;
    void* mpEos;
    // STUB: 0x459e80
    void CopyConstruct(const Elem_00461310_shapeb03_game* pSrc);
    // STUB: 0x461210
    void Assign(const Elem_00461310_shapeb03_game* pSrc);
};

// STUB: 0x4614d0
void Fn4614d0(Elem_00461310_shapeb03_game* pFirst, uint32_t nCount, const Elem_00461310_shapeb03_game* pValue);

struct View_00461310_shapeb03_game {
    uint32_t mUnused;
    Elem_00461310_shapeb03_game* mpEnd;
    Elem_00461310_shapeb03_game* mpEos;
    // STUB: 0x461500
    void InsertOverflow(Elem_00461310_shapeb03_game* pPos, const Elem_00461310_shapeb03_game* pValue, const bool& rTag, uint32_t nCount, bool bAtEnd);
    void FillInsert(Elem_00461310_shapeb03_game* pPos, uint32_t nCount, const Elem_00461310_shapeb03_game* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00461310 score 164
#ifdef OB_DRAFTS
void View_00461310_shapeb03_game::FillInsert(Elem_00461310_shapeb03_game* pPos, uint32_t nCount, const Elem_00461310_shapeb03_game* pValue)
{
    if (nCount != 0) {
        if (static_cast<uint32_t>(mpEos - mpEnd) < nCount) {
            bool bTag = false;
            InsertOverflow(pPos, pValue, bTag, nCount, false);
            return;
        }
        Elem_00461310_shapeb03_game xCopy;
        xCopy.CopyConstruct(pValue);
        uint32_t nAfter = static_cast<uint32_t>(mpEnd - pPos);
        Elem_00461310_shapeb03_game* pOldEnd = mpEnd;
        if (nAfter > nCount) {
            Elem_00461310_shapeb03_game* pSrc = pOldEnd - nCount;
            Elem_00461310_shapeb03_game* pDst = pOldEnd;
            for (Elem_00461310_shapeb03_game* p = pSrc; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nCount;
            int32_t n = static_cast<int32_t>(pSrc - pPos);
            Elem_00461310_shapeb03_game* pTo = pOldEnd;
            for (; n > 0; --n) {
                --pTo;
                pTo->Assign(pTo + (pSrc - pOldEnd));
            }
            Elem_00461310_shapeb03_game* pStop = pPos + nCount;
            for (Elem_00461310_shapeb03_game* p = pPos; p != pStop; ++p) {
                p->Assign(&xCopy);
            }
        } else {
            Fn4614d0(pOldEnd, nCount - nAfter, &xCopy);
            mpEnd += nCount - nAfter;
            Elem_00461310_shapeb03_game* pDst = mpEnd;
            for (Elem_00461310_shapeb03_game* p = pPos; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nAfter;
            for (Elem_00461310_shapeb03_game* p = pPos; p != pOldEnd; ++p) {
                p->Assign(&xCopy);
            }
        }
        if (xCopy.mpBegin) {
            Fn0090cf63(xCopy.mpBegin);
        }
    }
}
#endif
#endif

struct Elem_00461cf0_shapeb03_game {
    void* mpBegin;
    void* mpEnd;
    void* mpEos;
    // STUB: 0x459e80
    void CopyConstruct(const Elem_00461cf0_shapeb03_game* pSrc);
    // STUB: 0x461c10
    void Assign(const Elem_00461cf0_shapeb03_game* pSrc);
};

// STUB: 0x4614d0
void Fn4614d0(Elem_00461cf0_shapeb03_game* pFirst, uint32_t nCount, const Elem_00461cf0_shapeb03_game* pValue);

struct View_00461cf0_shapeb03_game {
    uint32_t mUnused;
    Elem_00461cf0_shapeb03_game* mpEnd;
    Elem_00461cf0_shapeb03_game* mpEos;
    // STUB: 0x461500
    void InsertOverflow(Elem_00461cf0_shapeb03_game* pPos, const Elem_00461cf0_shapeb03_game* pValue, const bool& rTag, uint32_t nCount, bool bAtEnd);
    void FillInsert(Elem_00461cf0_shapeb03_game* pPos, uint32_t nCount, const Elem_00461cf0_shapeb03_game* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00461cf0 score 164
#ifdef OB_DRAFTS
void View_00461cf0_shapeb03_game::FillInsert(Elem_00461cf0_shapeb03_game* pPos, uint32_t nCount, const Elem_00461cf0_shapeb03_game* pValue)
{
    if (nCount != 0) {
        if (static_cast<uint32_t>(mpEos - mpEnd) < nCount) {
            bool bTag = false;
            InsertOverflow(pPos, pValue, bTag, nCount, false);
            return;
        }
        Elem_00461cf0_shapeb03_game xCopy;
        xCopy.CopyConstruct(pValue);
        uint32_t nAfter = static_cast<uint32_t>(mpEnd - pPos);
        Elem_00461cf0_shapeb03_game* pOldEnd = mpEnd;
        if (nAfter > nCount) {
            Elem_00461cf0_shapeb03_game* pSrc = pOldEnd - nCount;
            Elem_00461cf0_shapeb03_game* pDst = pOldEnd;
            for (Elem_00461cf0_shapeb03_game* p = pSrc; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nCount;
            int32_t n = static_cast<int32_t>(pSrc - pPos);
            Elem_00461cf0_shapeb03_game* pTo = pOldEnd;
            for (; n > 0; --n) {
                --pTo;
                pTo->Assign(pTo + (pSrc - pOldEnd));
            }
            Elem_00461cf0_shapeb03_game* pStop = pPos + nCount;
            for (Elem_00461cf0_shapeb03_game* p = pPos; p != pStop; ++p) {
                p->Assign(&xCopy);
            }
        } else {
            Fn4614d0(pOldEnd, nCount - nAfter, &xCopy);
            mpEnd += nCount - nAfter;
            Elem_00461cf0_shapeb03_game* pDst = mpEnd;
            for (Elem_00461cf0_shapeb03_game* p = pPos; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nAfter;
            for (Elem_00461cf0_shapeb03_game* p = pPos; p != pOldEnd; ++p) {
                p->Assign(&xCopy);
            }
        }
        if (xCopy.mpBegin) {
            Fn0090cf63(xCopy.mpBegin);
        }
    }
}
#endif
#endif

struct Elem_00462460_shapeb03_game {
    void* mpBegin;
    void* mpEnd;
    void* mpEos;
    // STUB: 0x462620
    void CopyConstruct(const Elem_00462460_shapeb03_game* pSrc);
    // STUB: 0x465a10
    void Assign(const Elem_00462460_shapeb03_game* pSrc);
};

// STUB: 0x4626b0
void Fn4626b0(Elem_00462460_shapeb03_game* pFirst, uint32_t nCount, const Elem_00462460_shapeb03_game* pValue);

struct View_00462460_shapeb03_game {
    uint32_t mUnused;
    Elem_00462460_shapeb03_game* mpEnd;
    Elem_00462460_shapeb03_game* mpEos;
    // STUB: 0x465b10
    void InsertOverflow(Elem_00462460_shapeb03_game* pPos, const Elem_00462460_shapeb03_game* pValue, const bool& rTag, uint32_t nCount, bool bAtEnd);
    void FillInsert(Elem_00462460_shapeb03_game* pPos, uint32_t nCount, const Elem_00462460_shapeb03_game* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00462460 score 164
#ifdef OB_DRAFTS
void View_00462460_shapeb03_game::FillInsert(Elem_00462460_shapeb03_game* pPos, uint32_t nCount, const Elem_00462460_shapeb03_game* pValue)
{
    if (nCount != 0) {
        if (static_cast<uint32_t>(mpEos - mpEnd) < nCount) {
            bool bTag = false;
            InsertOverflow(pPos, pValue, bTag, nCount, false);
            return;
        }
        Elem_00462460_shapeb03_game xCopy;
        xCopy.CopyConstruct(pValue);
        uint32_t nAfter = static_cast<uint32_t>(mpEnd - pPos);
        Elem_00462460_shapeb03_game* pOldEnd = mpEnd;
        if (nAfter > nCount) {
            Elem_00462460_shapeb03_game* pSrc = pOldEnd - nCount;
            Elem_00462460_shapeb03_game* pDst = pOldEnd;
            for (Elem_00462460_shapeb03_game* p = pSrc; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nCount;
            int32_t n = static_cast<int32_t>(pSrc - pPos);
            Elem_00462460_shapeb03_game* pTo = pOldEnd;
            for (; n > 0; --n) {
                --pTo;
                pTo->Assign(pTo + (pSrc - pOldEnd));
            }
            Elem_00462460_shapeb03_game* pStop = pPos + nCount;
            for (Elem_00462460_shapeb03_game* p = pPos; p != pStop; ++p) {
                p->Assign(&xCopy);
            }
        } else {
            Fn4626b0(pOldEnd, nCount - nAfter, &xCopy);
            mpEnd += nCount - nAfter;
            Elem_00462460_shapeb03_game* pDst = mpEnd;
            for (Elem_00462460_shapeb03_game* p = pPos; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nAfter;
            for (Elem_00462460_shapeb03_game* p = pPos; p != pOldEnd; ++p) {
                p->Assign(&xCopy);
            }
        }
        if (xCopy.mpBegin) {
            Fn0090cf63(xCopy.mpBegin);
        }
    }
}
#endif
#endif

struct Elem_00462d40_shapeb03_game {
    void* mpBegin;
    void* mpEnd;
    void* mpEos;
    // STUB: 0x462f00
    void CopyConstruct(const Elem_00462d40_shapeb03_game* pSrc);
    // STUB: 0x462c10
    void Assign(const Elem_00462d40_shapeb03_game* pSrc);
};

// STUB: 0x465eb0
void Fn465eb0(Elem_00462d40_shapeb03_game* pFirst, uint32_t nCount, const Elem_00462d40_shapeb03_game* pValue);

struct View_00462d40_shapeb03_game {
    uint32_t mUnused;
    Elem_00462d40_shapeb03_game* mpEnd;
    Elem_00462d40_shapeb03_game* mpEos;
    // STUB: 0x462f50
    void InsertOverflow(Elem_00462d40_shapeb03_game* pPos, const Elem_00462d40_shapeb03_game* pValue, const bool& rTag, uint32_t nCount, bool bAtEnd);
    void FillInsert(Elem_00462d40_shapeb03_game* pPos, uint32_t nCount, const Elem_00462d40_shapeb03_game* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00462d40 score 164
#ifdef OB_DRAFTS
void View_00462d40_shapeb03_game::FillInsert(Elem_00462d40_shapeb03_game* pPos, uint32_t nCount, const Elem_00462d40_shapeb03_game* pValue)
{
    if (nCount != 0) {
        if (static_cast<uint32_t>(mpEos - mpEnd) < nCount) {
            bool bTag = false;
            InsertOverflow(pPos, pValue, bTag, nCount, false);
            return;
        }
        Elem_00462d40_shapeb03_game xCopy;
        xCopy.CopyConstruct(pValue);
        uint32_t nAfter = static_cast<uint32_t>(mpEnd - pPos);
        Elem_00462d40_shapeb03_game* pOldEnd = mpEnd;
        if (nAfter > nCount) {
            Elem_00462d40_shapeb03_game* pSrc = pOldEnd - nCount;
            Elem_00462d40_shapeb03_game* pDst = pOldEnd;
            for (Elem_00462d40_shapeb03_game* p = pSrc; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nCount;
            int32_t n = static_cast<int32_t>(pSrc - pPos);
            Elem_00462d40_shapeb03_game* pTo = pOldEnd;
            for (; n > 0; --n) {
                --pTo;
                pTo->Assign(pTo + (pSrc - pOldEnd));
            }
            Elem_00462d40_shapeb03_game* pStop = pPos + nCount;
            for (Elem_00462d40_shapeb03_game* p = pPos; p != pStop; ++p) {
                p->Assign(&xCopy);
            }
        } else {
            Fn465eb0(pOldEnd, nCount - nAfter, &xCopy);
            mpEnd += nCount - nAfter;
            Elem_00462d40_shapeb03_game* pDst = mpEnd;
            for (Elem_00462d40_shapeb03_game* p = pPos; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nAfter;
            for (Elem_00462d40_shapeb03_game* p = pPos; p != pOldEnd; ++p) {
                p->Assign(&xCopy);
            }
        }
        if (xCopy.mpBegin) {
            Fn0090cf63(xCopy.mpBegin);
        }
    }
}
#endif
#endif

struct Elem_00463580_shapeb03_game {
    void* mpBegin;
    void* mpEnd;
    void* mpEos;
    // STUB: 0x463740
    void CopyConstruct(const Elem_00463580_shapeb03_game* pSrc);
    // STUB: 0x463cf0
    void Assign(const Elem_00463580_shapeb03_game* pSrc);
};

// STUB: 0x463e70
void Fn463e70(Elem_00463580_shapeb03_game* pFirst, uint32_t nCount, const Elem_00463580_shapeb03_game* pValue);

struct View_00463580_shapeb03_game {
    uint32_t mUnused;
    Elem_00463580_shapeb03_game* mpEnd;
    Elem_00463580_shapeb03_game* mpEos;
    // STUB: 0x463790
    void InsertOverflow(Elem_00463580_shapeb03_game* pPos, const Elem_00463580_shapeb03_game* pValue, const bool& rTag, uint32_t nCount, bool bAtEnd);
    void FillInsert(Elem_00463580_shapeb03_game* pPos, uint32_t nCount, const Elem_00463580_shapeb03_game* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00463580 score 164
#ifdef OB_DRAFTS
void View_00463580_shapeb03_game::FillInsert(Elem_00463580_shapeb03_game* pPos, uint32_t nCount, const Elem_00463580_shapeb03_game* pValue)
{
    if (nCount != 0) {
        if (static_cast<uint32_t>(mpEos - mpEnd) < nCount) {
            bool bTag = false;
            InsertOverflow(pPos, pValue, bTag, nCount, false);
            return;
        }
        Elem_00463580_shapeb03_game xCopy;
        xCopy.CopyConstruct(pValue);
        uint32_t nAfter = static_cast<uint32_t>(mpEnd - pPos);
        Elem_00463580_shapeb03_game* pOldEnd = mpEnd;
        if (nAfter > nCount) {
            Elem_00463580_shapeb03_game* pSrc = pOldEnd - nCount;
            Elem_00463580_shapeb03_game* pDst = pOldEnd;
            for (Elem_00463580_shapeb03_game* p = pSrc; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nCount;
            int32_t n = static_cast<int32_t>(pSrc - pPos);
            Elem_00463580_shapeb03_game* pTo = pOldEnd;
            for (; n > 0; --n) {
                --pTo;
                pTo->Assign(pTo + (pSrc - pOldEnd));
            }
            Elem_00463580_shapeb03_game* pStop = pPos + nCount;
            for (Elem_00463580_shapeb03_game* p = pPos; p != pStop; ++p) {
                p->Assign(&xCopy);
            }
        } else {
            Fn463e70(pOldEnd, nCount - nAfter, &xCopy);
            mpEnd += nCount - nAfter;
            Elem_00463580_shapeb03_game* pDst = mpEnd;
            for (Elem_00463580_shapeb03_game* p = pPos; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nAfter;
            for (Elem_00463580_shapeb03_game* p = pPos; p != pOldEnd; ++p) {
                p->Assign(&xCopy);
            }
        }
        if (xCopy.mpBegin) {
            Fn0090cf63(xCopy.mpBegin);
        }
    }
}
#endif
#endif

struct Elem_004645a0_shapeb03_game {
    void* mpBegin;
    void* mpEnd;
    void* mpEos;
    // STUB: 0x464760
    void CopyConstruct(const Elem_004645a0_shapeb03_game* pSrc);
    // STUB: 0x464430
    void Assign(const Elem_004645a0_shapeb03_game* pSrc);
};

// STUB: 0x4647e0
void Fn4647e0(Elem_004645a0_shapeb03_game* pFirst, uint32_t nCount, const Elem_004645a0_shapeb03_game* pValue);

struct View_004645a0_shapeb03_game {
    uint32_t mUnused;
    Elem_004645a0_shapeb03_game* mpEnd;
    Elem_004645a0_shapeb03_game* mpEos;
    // STUB: 0x464810
    void InsertOverflow(Elem_004645a0_shapeb03_game* pPos, const Elem_004645a0_shapeb03_game* pValue, const bool& rTag, uint32_t nCount, bool bAtEnd);
    void FillInsert(Elem_004645a0_shapeb03_game* pPos, uint32_t nCount, const Elem_004645a0_shapeb03_game* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004645a0 score 164
#ifdef OB_DRAFTS
void View_004645a0_shapeb03_game::FillInsert(Elem_004645a0_shapeb03_game* pPos, uint32_t nCount, const Elem_004645a0_shapeb03_game* pValue)
{
    if (nCount != 0) {
        if (static_cast<uint32_t>(mpEos - mpEnd) < nCount) {
            bool bTag = false;
            InsertOverflow(pPos, pValue, bTag, nCount, false);
            return;
        }
        Elem_004645a0_shapeb03_game xCopy;
        xCopy.CopyConstruct(pValue);
        uint32_t nAfter = static_cast<uint32_t>(mpEnd - pPos);
        Elem_004645a0_shapeb03_game* pOldEnd = mpEnd;
        if (nAfter > nCount) {
            Elem_004645a0_shapeb03_game* pSrc = pOldEnd - nCount;
            Elem_004645a0_shapeb03_game* pDst = pOldEnd;
            for (Elem_004645a0_shapeb03_game* p = pSrc; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nCount;
            int32_t n = static_cast<int32_t>(pSrc - pPos);
            Elem_004645a0_shapeb03_game* pTo = pOldEnd;
            for (; n > 0; --n) {
                --pTo;
                pTo->Assign(pTo + (pSrc - pOldEnd));
            }
            Elem_004645a0_shapeb03_game* pStop = pPos + nCount;
            for (Elem_004645a0_shapeb03_game* p = pPos; p != pStop; ++p) {
                p->Assign(&xCopy);
            }
        } else {
            Fn4647e0(pOldEnd, nCount - nAfter, &xCopy);
            mpEnd += nCount - nAfter;
            Elem_004645a0_shapeb03_game* pDst = mpEnd;
            for (Elem_004645a0_shapeb03_game* p = pPos; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nAfter;
            for (Elem_004645a0_shapeb03_game* p = pPos; p != pOldEnd; ++p) {
                p->Assign(&xCopy);
            }
        }
        if (xCopy.mpBegin) {
            Fn0090cf63(xCopy.mpBegin);
        }
    }
}
#endif
#endif

struct Elem_00465130_shapeb03_game {
    void* mpBegin;
    void* mpEnd;
    void* mpEos;
    // STUB: 0x4652f0
    void CopyConstruct(const Elem_00465130_shapeb03_game* pSrc);
    // STUB: 0x464fc0
    void Assign(const Elem_00465130_shapeb03_game* pSrc);
};

// STUB: 0x465330
void Fn465330(Elem_00465130_shapeb03_game* pFirst, uint32_t nCount, const Elem_00465130_shapeb03_game* pValue);

struct View_00465130_shapeb03_game {
    uint32_t mUnused;
    Elem_00465130_shapeb03_game* mpEnd;
    Elem_00465130_shapeb03_game* mpEos;
    // STUB: 0x465360
    void InsertOverflow(Elem_00465130_shapeb03_game* pPos, const Elem_00465130_shapeb03_game* pValue, const bool& rTag, uint32_t nCount, bool bAtEnd);
    void FillInsert(Elem_00465130_shapeb03_game* pPos, uint32_t nCount, const Elem_00465130_shapeb03_game* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00465130 score 164
#ifdef OB_DRAFTS
void View_00465130_shapeb03_game::FillInsert(Elem_00465130_shapeb03_game* pPos, uint32_t nCount, const Elem_00465130_shapeb03_game* pValue)
{
    if (nCount != 0) {
        if (static_cast<uint32_t>(mpEos - mpEnd) < nCount) {
            bool bTag = false;
            InsertOverflow(pPos, pValue, bTag, nCount, false);
            return;
        }
        Elem_00465130_shapeb03_game xCopy;
        xCopy.CopyConstruct(pValue);
        uint32_t nAfter = static_cast<uint32_t>(mpEnd - pPos);
        Elem_00465130_shapeb03_game* pOldEnd = mpEnd;
        if (nAfter > nCount) {
            Elem_00465130_shapeb03_game* pSrc = pOldEnd - nCount;
            Elem_00465130_shapeb03_game* pDst = pOldEnd;
            for (Elem_00465130_shapeb03_game* p = pSrc; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nCount;
            int32_t n = static_cast<int32_t>(pSrc - pPos);
            Elem_00465130_shapeb03_game* pTo = pOldEnd;
            for (; n > 0; --n) {
                --pTo;
                pTo->Assign(pTo + (pSrc - pOldEnd));
            }
            Elem_00465130_shapeb03_game* pStop = pPos + nCount;
            for (Elem_00465130_shapeb03_game* p = pPos; p != pStop; ++p) {
                p->Assign(&xCopy);
            }
        } else {
            Fn465330(pOldEnd, nCount - nAfter, &xCopy);
            mpEnd += nCount - nAfter;
            Elem_00465130_shapeb03_game* pDst = mpEnd;
            for (Elem_00465130_shapeb03_game* p = pPos; p != pOldEnd; ++p, ++pDst) {
                if (pDst) {
                    pDst->CopyConstruct(p);
                }
            }
            mpEnd += nAfter;
            for (Elem_00465130_shapeb03_game* p = pPos; p != pOldEnd; ++p) {
                p->Assign(&xCopy);
            }
        }
        if (xCopy.mpBegin) {
            Fn0090cf63(xCopy.mpBegin);
        }
    }
}
#endif
#endif

