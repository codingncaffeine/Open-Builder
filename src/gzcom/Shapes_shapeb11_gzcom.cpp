#include "common/types.h"

struct View_00959e83_shapeb11_gzcom {
    uint32_t mField0;
    uint32_t mField4;
    uint32_t mField8;
    uint32_t mnValue;
    uint8_t mPad10[0x10];
    uint8_t mbActive;
    // STUB: 0x0095524f
    void Release();
    bool Fn00959e83();
};

// FUNCTION: 0x00959e83
bool View_00959e83_shapeb11_gzcom::Fn00959e83()
{
    if (mbActive) {
        Release();
        mnValue = 0;
        mbActive = 0;
    }
    return true;
}

struct View_00959eef_shapeb11_gzcom {
    uint32_t mField0;
    uint32_t mField4;
    uint32_t mField8;
    uint32_t mnValue;
    uint8_t mPad10[0x10];
    uint8_t mbActive;
    // STUB: 0x00955278
    void Release();
    bool Fn00959eef();
};

// FUNCTION: 0x00959eef
bool View_00959eef_shapeb11_gzcom::Fn00959eef()
{
    if (mbActive) {
        Release();
        mnValue = 0;
        mbActive = 0;
    }
    return true;
}

struct View_0095a0d9_shapeb11_gzcom {
    uint32_t mField0;
    uint32_t mField4;
    uint32_t mField8;
    uint32_t mnValue;
    uint8_t mPad10[0x10];
    uint8_t mbActive;
    // STUB: 0x009599a9
    void Release();
    bool Fn0095a0d9();
};

// FUNCTION: 0x0095a0d9
bool View_0095a0d9_shapeb11_gzcom::Fn0095a0d9()
{
    if (mbActive) {
        Release();
        mnValue = 0;
        mbActive = 0;
    }
    return true;
}

struct View_009ab9ab_shapeb11_gzcom {
    uint32_t mField0;
    uint32_t mField4;
    uint32_t mField8;
    uint32_t mnValue;
    uint8_t mPad10[0x10];
    uint8_t mbActive;
    // STUB: 0x009ab5c1
    void Release();
    bool Fn009ab9ab();
};

// FUNCTION: 0x009ab9ab
bool View_009ab9ab_shapeb11_gzcom::Fn009ab9ab()
{
    if (mbActive) {
        Release();
        mnValue = 0;
        mbActive = 0;
    }
    return true;
}

struct View_009ab9c5_shapeb11_gzcom {
    uint32_t mField0;
    uint32_t mField4;
    uint32_t mField8;
    uint32_t mnValue;
    uint8_t mPad10[0x10];
    uint8_t mbActive;
    // STUB: 0x009ab5ea
    void Release();
    bool Fn009ab9c5();
};

// FUNCTION: 0x009ab9c5
bool View_009ab9c5_shapeb11_gzcom::Fn009ab9c5()
{
    if (mbActive) {
        Release();
        mnValue = 0;
        mbActive = 0;
    }
    return true;
}

struct View_00969fad_shapeb11_gzcom {
    virtual void Pad0_00969fad() = 0;
    virtual void Pad1_00969fad() = 0;
    virtual void Pad2_00969fad() = 0;
    virtual void Pad3_00969fad() = 0;
    virtual void Pad4_00969fad() = 0;
    virtual void Pad5_00969fad() = 0;
    virtual void Pad6_00969fad() = 0;
    virtual void Pad7_00969fad() = 0;
    virtual void Pad8_00969fad() = 0;
    virtual uint32_t Target_00969fad(uint32_t a, uint32_t b) = 0;
    uint32_t Fn00969fad(uint32_t a);
};

// FUNCTION: 0x00969fad
uint32_t View_00969fad_shapeb11_gzcom::Fn00969fad(uint32_t a)
{
    return Target_00969fad(0xcc3014ee, a);
}

struct View_009c16c3_shapeb11_gzcom {
    virtual void Pad0_009c16c3() = 0;
    virtual void Pad1_009c16c3() = 0;
    virtual void Pad2_009c16c3() = 0;
    virtual void Pad3_009c16c3() = 0;
    virtual void Pad4_009c16c3() = 0;
    virtual void Pad5_009c16c3() = 0;
    virtual void Pad6_009c16c3() = 0;
    virtual void Pad7_009c16c3() = 0;
    virtual void Pad8_009c16c3() = 0;
    virtual uint32_t Target_009c16c3(uint32_t a, uint32_t b) = 0;
    uint32_t Fn009c16c3(uint32_t a);
};

// FUNCTION: 0x009c16c3
uint32_t View_009c16c3_shapeb11_gzcom::Fn009c16c3(uint32_t a)
{
    return Target_009c16c3(0x0, a);
}

struct View_009c16d1_shapeb11_gzcom {
    virtual void Pad0_009c16d1() = 0;
    virtual void Pad1_009c16d1() = 0;
    virtual void Pad2_009c16d1() = 0;
    virtual void Pad3_009c16d1() = 0;
    virtual void Pad4_009c16d1() = 0;
    virtual void Pad5_009c16d1() = 0;
    virtual void Pad6_009c16d1() = 0;
    virtual void Pad7_009c16d1() = 0;
    virtual void Pad8_009c16d1() = 0;
    virtual void Pad9_009c16d1() = 0;
    virtual void Pad10_009c16d1() = 0;
    virtual void Pad11_009c16d1() = 0;
    virtual uint32_t Target_009c16d1(uint32_t a, uint32_t b) = 0;
    uint32_t Fn009c16d1(uint32_t a);
};

// FUNCTION: 0x009c16d1
uint32_t View_009c16d1_shapeb11_gzcom::Fn009c16d1(uint32_t a)
{
    return Target_009c16d1(0x0, a);
}

struct View_009c16e7_shapeb11_gzcom {
    virtual void Pad0_009c16e7() = 0;
    virtual void Pad1_009c16e7() = 0;
    virtual void Pad2_009c16e7() = 0;
    virtual void Pad3_009c16e7() = 0;
    virtual void Pad4_009c16e7() = 0;
    virtual void Pad5_009c16e7() = 0;
    virtual void Pad6_009c16e7() = 0;
    virtual uint32_t Target_009c16e7(uint32_t a, uint32_t b) = 0;
    uint32_t Fn009c16e7(uint32_t a);
};

// FUNCTION: 0x009c16e7
uint32_t View_009c16e7_shapeb11_gzcom::Fn009c16e7(uint32_t a)
{
    return Target_009c16e7(0x4, a);
}

struct View_0099bc3f_shapeb11_gzcom {
    virtual void Pad0_0099bc3f() = 0;
    virtual void Pad1_0099bc3f() = 0;
    virtual void Pad2_0099bc3f() = 0;
    virtual void Pad3_0099bc3f() = 0;
    virtual void Pad4_0099bc3f() = 0;
    virtual void Pad5_0099bc3f() = 0;
    virtual void Pad6_0099bc3f() = 0;
    virtual void Pad7_0099bc3f() = 0;
    virtual void Pad8_0099bc3f() = 0;
    virtual void Pad9_0099bc3f() = 0;
    virtual void Pad10_0099bc3f() = 0;
    virtual void Pad11_0099bc3f() = 0;
    virtual void Pad12_0099bc3f() = 0;
    virtual void Pad13_0099bc3f() = 0;
    virtual void Pad14_0099bc3f() = 0;
    virtual void Pad15_0099bc3f() = 0;
    virtual void Pad16_0099bc3f() = 0;
    virtual void Pad17_0099bc3f() = 0;
    virtual void Pad18_0099bc3f() = 0;
    virtual void Pad19_0099bc3f() = 0;
    virtual void Pad20_0099bc3f() = 0;
    virtual void Pad21_0099bc3f() = 0;
    virtual void Pad22_0099bc3f() = 0;
    virtual void Pad23_0099bc3f() = 0;
    virtual void Pad24_0099bc3f() = 0;
    virtual void Pad25_0099bc3f() = 0;
    virtual void Pad26_0099bc3f() = 0;
    virtual void Pad27_0099bc3f() = 0;
    virtual void Pad28_0099bc3f() = 0;
    virtual void Pad29_0099bc3f() = 0;
    virtual void Pad30_0099bc3f() = 0;
    virtual void Pad31_0099bc3f() = 0;
    virtual void Pad32_0099bc3f() = 0;
    virtual void Pad33_0099bc3f() = 0;
    virtual void Pad34_0099bc3f() = 0;
    virtual void Pad35_0099bc3f() = 0;
    virtual void Pad36_0099bc3f() = 0;
    virtual void Pad37_0099bc3f() = 0;
    virtual void Pad38_0099bc3f() = 0;
    virtual void Pad39_0099bc3f() = 0;
    virtual void Pad40_0099bc3f() = 0;
    virtual void Pad41_0099bc3f() = 0;
    virtual void Pad42_0099bc3f() = 0;
    virtual void Pad43_0099bc3f() = 0;
    virtual void Pad44_0099bc3f() = 0;
    virtual void Pad45_0099bc3f() = 0;
    virtual void Pad46_0099bc3f() = 0;
    virtual void Pad47_0099bc3f() = 0;
    virtual void Pad48_0099bc3f() = 0;
    virtual void Pad49_0099bc3f() = 0;
    virtual void Pad50_0099bc3f() = 0;
    virtual void Pad51_0099bc3f() = 0;
    virtual void Pad52_0099bc3f() = 0;
    virtual void Pad53_0099bc3f() = 0;
    virtual void Pad54_0099bc3f() = 0;
    virtual void Pad55_0099bc3f() = 0;
    virtual void Pad56_0099bc3f() = 0;
    virtual void Pad57_0099bc3f() = 0;
    virtual void Pad58_0099bc3f() = 0;
    virtual void Pad59_0099bc3f() = 0;
    virtual void Pad60_0099bc3f() = 0;
    virtual void Pad61_0099bc3f() = 0;
    virtual void Pad62_0099bc3f() = 0;
    virtual void Pad63_0099bc3f() = 0;
    virtual void Pad64_0099bc3f() = 0;
    virtual void Pad65_0099bc3f() = 0;
    virtual void Pad66_0099bc3f() = 0;
    virtual void Pad67_0099bc3f() = 0;
    virtual uint32_t Target_0099bc3f(uint32_t a, uint32_t b) = 0;
    uint32_t Fn0099bc3f(uint32_t a);
};

// FUNCTION: 0x0099bc3f
uint32_t View_0099bc3f_shapeb11_gzcom::Fn0099bc3f(uint32_t a)
{
    return Target_0099bc3f(0x4000, a);
}
