#include <cmath>
#include <cstddef>
#include "classes/cSC4Lot.h"
#include "common/compiler.h"

// The refcount of the property-holder subobject (offset 0xc from the lot).
struct Ref_ab19b0 {
    uint8_t mPad[0xc];
    uint32_t mnRef;
};

// An object with a refcount (the lot's business unit).
struct Counted_ab19b0 {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

struct Dev_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual float Fn78(void* lot, uint32_t b);
};
struct BuildSim_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual uint32_t Fn78(uint32_t a, uint32_t b);
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual Dev_ab19b0* Fn90();
    virtual void P37();
    virtual void P38();
    virtual uint32_t* Fn9c(uint32_t a);
};
// GLOBAL: 0x00b43d68
extern BuildSim_ab19b0* gpB43d68_ab19b0;

struct Clock_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual uint32_t Fn68();
};
struct Sim_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual Clock_ab19b0* Fn1c();
};
// GLOBAL: 0x00b43d5c
extern Sim_ab19b0* gpB43d5c_ab19b0;

struct Zone_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual uint8_t Fn30(uint32_t x, uint32_t z);
};
// GLOBAL: 0x00b43d14
extern Zone_ab19b0* gpB43d14_ab19b0;

struct Traffic_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
    virtual uint32_t Fn98(void* lot, uint32_t i);
};
// GLOBAL: 0x00b43da8
extern Traffic_ab19b0* gpB43da8_ab19b0;

// FUNCTION: 0x006c2050
uint32_t cSC4Lot::Slot04_ab16e8()
{
    return OB_ADDR(static_cast<cUnk00ab1800*>(this));
}

// FUNCTION: 0x006c20e0
void cSC4Lot::Slot28_ab16e8()
{
    Slot29_ab16e8(0);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c2120 score 5
bool cSC4Lot::Slot68_ab16e8()
{
    return static_cast<uint8_t>(static_cast<uint8_t>(mnFlags >> 6) & 1);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c21a0 score 5
bool cSC4Lot::Slot65_ab16e8()
{
    return static_cast<uint8_t>(static_cast<uint8_t>(mnFlags >> 3) & 1);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c21b0 score 5
bool cSC4Lot::Slot66_ab16e8()
{
    return static_cast<uint8_t>(static_cast<uint8_t>(mnFlags >> 4) & 1);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c2220 score 5
bool cSC4Lot::Slot43_ab16e8()
{
    return static_cast<uint8_t>(static_cast<uint8_t>(mnFlags >> 5) & 1);
}
#endif

// FUNCTION: 0x006c2150
bool cSC4Lot::Slot37_ab16e8()
{
    return mnState == 3;
}

// FUNCTION: 0x006c2160
uint32_t cSC4Lot::Slot38_ab16e8()
{
    return mnState >= 2 && mnState < 4;
}

// FUNCTION: 0x006c2180
uint32_t cSC4Lot::Slot39_ab16e8()
{
    return (mnState >= 2 && mnState <= 4) || mnState == 6;
}

// FUNCTION: 0x006c2130
void cSC4Lot::Slot69_ab16e8(uint32_t a)
{
    bool b = *reinterpret_cast<bool*>(&a);
    if (b) {
        mnFlags = static_cast<uint8_t>(mnFlags | 0x40);
    } else {
        mnFlags = static_cast<uint8_t>(mnFlags & 0xbf);
    }
}

// FUNCTION: 0x006c21c0
void cSC4Lot::Slot67_ab16e8(uint32_t a)
{
    bool b = *reinterpret_cast<bool*>(&a);
    if (b) {
        mnFlags = static_cast<uint8_t>(mnFlags | 0x10);
    } else {
        mnFlags = static_cast<uint8_t>(mnFlags & 0xef);
    }
}

// FUNCTION: 0x006c2230
void cSC4Lot::Slot44_ab16e8(uint32_t a)
{
    bool b = *reinterpret_cast<bool*>(&a);
    if (b) {
        mnFlags = static_cast<uint8_t>(mnFlags | 0x20);
    } else {
        mnFlags = static_cast<uint8_t>(mnFlags & 0xdf);
    }
}

// FUNCTION: 0x006c2200
void cSC4Lot::Slot47_ab16e8(uint32_t a)
{
    mn3c = a;
    mnByte82 = 0;
}

// FUNCTION: 0x006bf2e0
void cSC4Lot::Slot21_ab16e8(uint32_t a, uint32_t b)
{
    *OB_PTR(uint32_t, a) = mnByte7a;
    *OB_PTR(uint32_t, b) = mnByte7b;
}

// FUNCTION: 0x006bf300
void cSC4Lot::Slot22_ab16e8(uint32_t a, uint32_t b)
{
    *OB_PTR(uint8_t, a) = mnByte7c;
    *OB_PTR(uint8_t, b) = mnByte7d;
}

// FUNCTION: 0x006bf320
void cSC4Lot::Slot14_ab16e8(uint32_t p)
{
    uint32_t* out = OB_PTR(uint32_t, p);
    out[0] = mnByte20;
    out[1] = mnByte21;
    out[2] = mnByte22;
    out[3] = mnByte23;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c22d0 score 8
void cSC4Lot::Slot05_ab1800(uint32_t p)
{
    uint32_t* out = OB_PTR(uint32_t, p);
    uint32_t d = mnByte23;
    uint32_t s = mnByte22;
    uint32_t di = mnByte21;
    uint32_t c = mnByte20;
    out[1] = di;
    out[2] = s;
    out[0] = c;
    out[3] = d;
}
#endif

// FUNCTION: 0x006bf350
float cSC4Lot::Slot63_ab16e8(uint32_t i)
{
    switch (i) {
    case 1:
        return mf6c;
    case 2:
        return mf70;
    case 3:
        return mf74;
    }
    return 0.0f;
}

// FUNCTION: 0x006bf200
void cSC4Lot::Slot08_ab16e8()
{
    int8_t f = mnFlags;
    mnFlags = 0;
    Slot13_ab16e8(f);
}

// FUNCTION: 0x006c20b0
void cSC4Lot::Slot26_ab16e8(uint32_t unit)
{
    Counted_ab19b0* p = OB_PTR(Counted_ab19b0, unit);
    Counted_ab19b0* cur = static_cast<Counted_ab19b0*>(mpUnit);
    if (p != cur) {
        if (cur) {
            cur->Release();
        }
        mpUnit = p;
        if (p) {
            p->AddRef();
        }
    }
}

// FUNCTION: 0x006bf610
void cSC4Lot::Slot20_ab16e8()
{
    mfSlope = gpB43d68_ab19b0->Fn90()->Fn78(this, 0);
}

// FUNCTION: 0x006bf630
uint32_t cSC4Lot::Slot40_ab16e8()
{
    if (mnLastStateChangeDay != 0) {
        return gpB43d5c_ab19b0->Fn1c()->Fn68() - mnLastStateChangeDay;
    }
    return 0;
}

// FUNCTION: 0x006bfc40
void cSC4Lot::Slot32_ab16e8()
{
    mnByte81 = gpB43d14_ab19b0->Fn30(mnByte7a, mnByte7b);
}

// FUNCTION: 0x006bfce0
bool cSC4Lot::Slot27_ab16e8()
{
    Traffic_ab19b0* t = gpB43da8_ab19b0;
    for (int32_t i = 0; i < 2; i++) {
        if (t->Fn98(this, i) > 0) {
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x006bf460
unsigned int cSC4Lot::Release()
{
    Ref_ab19b0* self = reinterpret_cast<Ref_ab19b0*>(this);
    if (self->mnRef > 1) {
        self->mnRef = self->mnRef - 1;
        return self->mnRef;
    }
    Slot07_ab16e8();
    delete this;
    return 0;
}
struct BuildType_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual uint32_t Fn0c();
};

// Free function: the terrain view.
struct Terr_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void Fn40(uint32_t x, uint32_t z, float alt);
    virtual void Fn44(uint32_t x, uint32_t z);
};
// STUB: 0x00602160
Terr_ab19b0* Fn00602160();

struct Obj_ab19b0 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};
struct Occ_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual bool Fn8c(void** out, void* a, void* b, uint32_t id);
    virtual void P36();
    virtual void P37();
    virtual void P38();
    virtual void P39();
    virtual void Fn_a0(uint32_t out, void* a, void* b, void* filter, int32_t n);
};
// GLOBAL: 0x00b43d0c
extern Occ_ab19b0* gpB43d0c_ab19b0;

struct LandVal_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual uint8_t Fn18(uint32_t a, uint32_t b);
};
// GLOBAL: 0x00b43d88
extern LandVal_ab19b0* gpB43d88_ab19b0;

#ifdef OB_DRAFTS
// CLOSE: 0x006bf220 score 31
void cSC4Lot::Slot13_ab16e8(uint32_t flags)
{
    uint32_t old = mnFlags;
    mnFlags = static_cast<uint8_t>(flags);
    if (((flags ^ old) & 1) != 0) {
        Terr_ab19b0* t = Fn00602160();
        if (t != 0) {
            if (mnFlags & 1) {
                for (int32_t x = mnByte20; x <= mnByte22; x++) {
                    for (int32_t z = mnByte21; z <= mnByte23; z++) {
                        t->Fn40(x, z, mfAltitude);
                    }
                }
            } else {
                for (int32_t x = mnByte20; x <= mnByte22; x++) {
                    for (int32_t z = mnByte21; z <= mnByte23; z++) {
                        t->Fn44(x, z);
                    }
                }
            }
        }
    }
}
#endif

// FUNCTION: 0x006bf560
void cSC4Lot::Slot15_ab16e8(uint32_t p)
{
    float* out = OB_PTR(float, p);
    float z0 = static_cast<float>(mnByte21 << 4);
    float z1 = static_cast<float>(mnByte23 * 16 + 16);
    float x1 = static_cast<float>(mnByte22 * 16 + 16);
    float x0 = static_cast<float>(mnByte20 << 4);
    out[0] = (x0 + x1) * 0.5f;
    out[1] = mfAltitude;
    out[2] = (z0 + z1) * 0.5f;
}

// FUNCTION: 0x006bf5c0
void cSC4Lot::Slot17_ab16e8(uint32_t a)
{
    float alt = *reinterpret_cast<float*>(&a);
    if (std::fabs(alt - mfAltitude) > 0.001) {
        mfAltitude = alt;
        mfSlope = mfSlopeOld = gpB43d68_ab19b0->Fn90()->Fn78(this, 0);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x006bf660 score 15
void cSC4Lot::Slot60_ab16e8(uint32_t p)
{
    Counted_ab19b0* n = OB_PTR(Counted_ab19b0, p);
    if (mpTravelDesignate != n) {
        Counted_ab19b0* old = static_cast<Counted_ab19b0*>(mpTravelDesignate);
        if (n != old) {
            if (n) {
                n->AddRef();
            }
            mpTravelDesignate = n;
            if (old) {
                old->Release();
            }
        }
    }
}
#endif

// FUNCTION: 0x006bfa30
uint32_t cSC4Lot::Slot48_ab16e8()
{
    void* result = 0;
    if (mn3c != 0) {
        uint32_t hi[2];
        uint32_t lo[2];
        Obj_ab19b0* pObj;
        lo[0] = mnByte20;
        lo[1] = mnByte21;
        hi[0] = mnByte22;
        hi[1] = mnByte23;
        if (gpB43d0c_ab19b0->Fn8c(reinterpret_cast<void**>(&pObj), lo, hi, 0x278128a0)) {
            if (pObj->QueryInterface(0x87dda3a9, &result)) {
                static_cast<Obj_ab19b0*>(result)->Release();
            }
            pObj->Release();
        }
    }
    return OB_ADDR(result);
}

struct Cfg_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual uint32_t Fn58();
    virtual uint32_t* Fn5c();
};
struct Occ2_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void Fn20(float* out);
};
struct Developer_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
    virtual void P38();
    virtual void Fn9c(void* lot, void* cfg, void* elem, float* a, void* b);
};
// GLOBAL: 0x00b43d20
extern Developer_ab19b0* gpB43d20_ab19b0;

struct Terrain_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual float Fn34(float x, float z);
};
// GLOBAL: 0x00b43cf4
extern Terrain_ab19b0* gpB43cf4_ab19b0;

struct CfgMgr_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void* Fn20(uint32_t id);
};
// GLOBAL: 0x00b43d18
extern CfgMgr_ab19b0* gpB43d18_ab19b0;

struct Rand_ab19b0 {
    // STUB: 0x00913a06
    uint32_t Fn00913a06(uint32_t n);
};
// GLOBAL: 0x00b49120
extern Rand_ab19b0 g00b49120_ab19b0;
// GLOBAL: 0x00b49110
extern uint8_t g00b49110_ab19b0;

// The occupant filter the lot builds (constructor and SetLot belong to its own class).
struct Filter_ab19b0 {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    // STUB: 0x006bfb20
    Filter_ab19b0* Fn006bfb20();
    // STUB: 0x006bfac0
    void Fn006bfac0(void* lot);
};


// FUNCTION: 0x0060cb80
void cSC4Lot::Slot10_ab16e8(uint32_t p)
{
    Counted_ab19b0* n = OB_PTR(Counted_ab19b0, p);
    Counted_ab19b0* old = static_cast<Counted_ab19b0*>(mpLotConfiguration);
    if (n != old) {
        if (n) {
            n->AddRef();
        }
        mpLotConfiguration = n;
        if (old) {
            old->Release();
        }
    }
}

// FUNCTION: 0x006bf190
bool cSC4Lot::QueryInterface(uint32_t id, void** outp)
{
    void** out = outp;
    switch (id) {
    case 0xe818fced:
        *out = this;
        AddRef();
        return true;
    case 0xe4fda3d4:
        *out = static_cast<cUnk00a80784*>(this);
        AddRef();
        return true;
    case 1:
        *out = static_cast<cUnk00ab16e8*>(this);
        AddRef();
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006bf490 score 34
bool cSC4Lot::Slot05_ab16e8()
{
    if (g00b49110_ab19b0 == 0) {
        g00b49110_ab19b0 = 1;
    }
    if (!mbInitialized) {
        float pos[3];
        mf6c = 0;
        mf70 = 0;
        mf74 = 0;
        Terrain_ab19b0* terrain = gpB43cf4_ab19b0;
        Slot15_ab16e8(OB_ADDR(pos));
        float h = terrain->Fn34(pos[0], pos[2]);
        Slot17_ab16e8(*reinterpret_cast<uint32_t*>(&h));
        mbInitialized = true;
    }
    if (mnRandomByte == 0xff) {
        mnRandomByte = static_cast<uint8_t>(g00b49120_ab19b0.Fn00913a06(100));
    }
    if (mpLotConfiguration != 0) {
        Counted_ab19b0* cur = static_cast<Counted_ab19b0*>(mpLotConfiguration);
        mpLotConfiguration = 0;
        cur->Release();
    }
    if (mnLotConfigId != 0) {
        Counted_ab19b0* n = static_cast<Counted_ab19b0*>(gpB43d18_ab19b0->Fn20(mnLotConfigId));
        Counted_ab19b0* old = static_cast<Counted_ab19b0*>(mpLotConfiguration);
        if (n != old) {
            if (n) {
                n->AddRef();
            }
            mpLotConfiguration = n;
            if (old) {
                old->Release();
            }
        }
    }
    mnLotConfigId = 0;
    return true;
}
#endif

// FUNCTION: 0x006bff70
void cSC4Lot::Slot49_ab16e8(uint32_t out)
{
    uint32_t lo[2];
    uint32_t hi[2];
    lo[0] = mnByte20;
    lo[1] = mnByte21;
    hi[0] = mnByte22;
    hi[1] = mnByte23;
    void* mem = operator new(0x38);
    Filter_ab19b0* f;
    if (mem) {
        f = static_cast<Filter_ab19b0*>(mem)->Fn006bfb20();
    } else {
        f = 0;
    }
    f->AddRef();
    f->Fn006bfac0(this);
    gpB43d0c_ab19b0->Fn_a0(out, lo, hi, f, -1);
    f->Release();
}

#ifdef OB_DRAFTS
// CLOSE: 0x006bfea0 score 53
uint32_t cSC4Lot::Slot11_ab16e8(uint32_t occ)
{
    uint32_t off = 0;
    if (mpLotConfiguration != 0) {
        uint32_t count = static_cast<Cfg_ab19b0*>(mpLotConfiguration)->Fn58();
        uint32_t* vec = static_cast<Cfg_ab19b0*>(mpLotConfiguration)->Fn5c();
        if (vec != 0) {
            float occPos[3];
            float pos[3];
            uint8_t buf[16];
            OB_PTR(Occ2_ab19b0, occ)->Fn20(occPos);
            for (uint32_t i = 0; i < count; i++) {
                uint32_t elem = *vec + off;
                gpB43d20_ab19b0->Fn9c(this, mpLotConfiguration, OB_PTR(void, elem), pos, buf);
                if (std::fabs(pos[0] - occPos[0]) < 0.1f && std::fabs(pos[2] - occPos[2]) < 0.1f) {
                    return elem;
                }
                off += 0x34;
            }
        }
    }
    return 0;
}
#endif

// Records of the lot's lists (found by the sizes the original's copy code moves).
struct Sub_ab19b0 {
    uint8_t mData[12];
    // STUB: 0x00459e80
    void Fn00459e80(const Sub_ab19b0& src);
};

struct Entry_ab19b0 {
    Sub_ab19b0 mA;
    Sub_ab19b0 mB;
    uint32_t mn18;
    uint8_t mb1c;
    uint8_t mb1d;
    uint8_t mb1e;
    uint8_t mb1f;
    uint16_t mw20;
    uint16_t mw22;
    uint32_t mn24;
    uint32_t mn28;
    // STUB: 0x006c0ae0
    Entry_ab19b0* Fn006c0ae0(const Entry_ab19b0& src);
    Entry_ab19b0* Fn006c0ae0Impl_ab19b0(const Entry_ab19b0& src);
};

// FUNCTION: 0x006c0ae0
Entry_ab19b0* Entry_ab19b0::Fn006c0ae0Impl_ab19b0(const Entry_ab19b0& src)
{
    mA.Fn00459e80(src.mA);
    mB.Fn00459e80(src.mB);
    mn18 = src.mn18;
    mb1c = src.mb1c;
    mb1d = src.mb1d;
    mb1e = src.mb1e;
    mb1f = src.mb1f;
    mw20 = src.mw20;
    mw22 = src.mw22;
    mn24 = src.mn24;
    mn28 = src.mn28;
    return this;
}

struct ListNode_ab19b0 {
    ListNode_ab19b0* mpNext;
    ListNode_ab19b0* mpPrev;
    Entry_ab19b0 mData;
};

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

struct List_ab19b0 {
    ListNode_ab19b0* mpNode;
    void Fn006c1e10Impl_ab19b0(const Entry_ab19b0& e);
};

// FUNCTION: 0x006c1e10
void List_ab19b0::Fn006c1e10Impl_ab19b0(const Entry_ab19b0& e)
{
    ListNode_ab19b0* pos = mpNode->mpNext;
    ListNode_ab19b0* n = static_cast<ListNode_ab19b0*>(Fn0090cf54(0x34));
    if (&n->mData) {
        n->mData.Fn006c0ae0(e);
    }
    ListNode_ab19b0* prev = pos->mpPrev;
    n->mpNext = pos;
    n->mpPrev = prev;
    prev->mpNext = n;
    pos->mpPrev = n;
}

struct Map12_ab19b0 {
    uint8_t mData[12];
    // STUB: 0x004e3f80
    void Fn004e3f80(const Map12_ab19b0& src);
};

// FUNCTION: 0x006c10a0
Map12_ab19b0* Fn006c10a0(Map12_ab19b0* first, Map12_ab19b0* last, Map12_ab19b0* dest, void* /*tag*/)
{
    for (int32_t n = last - first; n > 0; n--) {
        dest->Fn004e3f80(*first);
        first++;
        dest++;
    }
    return dest;
}

// ---- the std::map<uint32_t, uint16_t> / vector helpers of the lot's state (found in the lot's own functions) ----

// A tree node of a map keyed by a dword (the value at 0x14 is a word or a byte).
struct MapNode_ab19b0 {
    uint32_t mnColor;
    MapNode_ab19b0* mpParent;
    MapNode_ab19b0* mpLeft;
    MapNode_ab19b0* mpRight;
    uint32_t mnKey;
    uint16_t mnValue;
};

struct U16Map_ab19b0 {
    MapNode_ab19b0* mpHeader;
    uint32_t mnSize;
    // STUB: 0x00497520
    void Find(MapNode_ab19b0** out, uint32_t* key);
    // STUB: 0x00458e00
    void Erase(MapNode_ab19b0* root);
};

// The lot's state at 0x54: a vector of 12-byte records, a map and a count.
struct State_ab19b0 {
    Map12_ab19b0* mpBegin;
    Map12_ab19b0* mpEnd;
    uint32_t mnPad;
    U16Map_ab19b0 mMap;
};

// STUB: 0x00459170
void Fn00459170(Map12_ab19b0* first, Map12_ab19b0* last, void* tag);

// A vector of 12-byte records.
struct Vec12_ab19b0 {
    Map12_ab19b0* mpBegin;
    Map12_ab19b0* mpEnd;
    Map12_ab19b0* mpCap;
    // STUB: 0x006c2e70
    void Fn006c2e70(Map12_ab19b0* where, uint32_t n, void* val);
    Vec12_ab19b0* Fn004cdf00Impl_ab19b0(const Vec12_ab19b0& src);
    void Fn006c2e30Impl_ab19b0();
    void Fn006c34f0Impl_ab19b0(uint32_t n, void* val);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004cdf00 score 61
Vec12_ab19b0* Vec12_ab19b0::Fn004cdf00Impl_ab19b0(const Vec12_ab19b0& src)
{
    Map12_ab19b0* first = src.mpBegin;
    int32_t n = src.mpEnd - first;
    mpBegin = 0;
    mpEnd = 0;
    mpCap = 0;
    if (n != 0) {
        mpBegin = static_cast<Map12_ab19b0*>(Fn0090cf54(n * 12));
        mpEnd = mpBegin;
        mpCap = mpBegin + n;
        Map12_ab19b0* dest = mpBegin;
        Map12_ab19b0* last = src.mpEnd;
        Map12_ab19b0* p = src.mpBegin;
        while (p != last) {
            if (dest) {
                dest->Fn004e3f80(*p);
            }
            p++;
            dest++;
        }
        mpEnd = dest;
    }
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c2e30 score 14
void Vec12_ab19b0::Fn006c2e30Impl_ab19b0()
{
    char tag = 0;
    Map12_ab19b0* ne = Fn006c10a0(mpEnd, mpEnd, mpBegin, &tag);
    Fn00459170(ne, mpEnd, &tag);
    mpEnd = ne;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c34f0 score 18
void Vec12_ab19b0::Fn006c34f0Impl_ab19b0(uint32_t n, void* val)
{
    uint32_t size = mpEnd - mpBegin;
    if (n < size) {
        char tag = 0;
        Map12_ab19b0* ne = Fn006c10a0(mpEnd, mpEnd, mpBegin + n, &tag);
        Fn00459170(ne, mpEnd, &tag);
        mpEnd = ne;
    } else {
        Fn006c2e70(mpEnd, n - size, val);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00699150 score 6
Map12_ab19b0* Fn00699150(Map12_ab19b0* first, Map12_ab19b0* last, Map12_ab19b0* dest)
{
    while (first != last) {
        if (dest) {
            dest->Fn004e3f80(*first);
        }
        first++;
        dest++;
    }
    return dest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c0510 score 32
uint16_t Lookup006c0510_ab19b0(State_ab19b0* st, uint32_t key)
{
    MapNode_ab19b0* it = 0;
    st->mMap.Find(&it, &key);
    if (it != st->mMap.mpHeader) {
        return it->mnValue;
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c0550 score 33
void Clear006c0550_ab19b0(cSC4Lot* lot, State_ab19b0* st)
{
    if (st->mMap.mnSize != 0) {
        st->mMap.Erase(st->mMap.mpHeader->mpParent);
        st->mMap.mpHeader->mpLeft = st->mMap.mpHeader;
        st->mMap.mpHeader->mpParent = 0;
        st->mMap.mpHeader->mpRight = st->mMap.mpHeader;
        st->mMap.mnSize = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c3060 score 33
bool cSC4Lot::Slot07_ab16e8()
{
    if (mbInitialized) {
        State_ab19b0* st = reinterpret_cast<State_ab19b0*>(&field54[0]);
        char tag = 0;
        mbInitialized = false;
        Map12_ab19b0* ne = Fn006c10a0(st->mpEnd, st->mpEnd, st->mpBegin, &tag);
        Fn00459170(ne, st->mpEnd, &tag);
        st->mpEnd = ne;
        if (st->mMap.mnSize != 0) {
            st->mMap.Erase(st->mMap.mpHeader->mpParent);
            st->mMap.mpHeader->mpLeft = st->mMap.mpHeader;
            st->mMap.mpHeader->mpParent = 0;
            st->mMap.mpHeader->mpRight = st->mMap.mpHeader;
            st->mMap.mnSize = 0;
        }
        Counted_ab19b0* cfg = static_cast<Counted_ab19b0*>(mpLotConfiguration);
        if (cfg) {
            mpLotConfiguration = 0;
            cfg->Release();
        }
        Counted_ab19b0* td = static_cast<Counted_ab19b0*>(mpTravelDesignate);
        if (td) {
            mpTravelDesignate = 0;
            td->Release();
        }
    }
    return true;
}
#endif

// The output stream the trip record is written to (slots by vtable offset / 4).
struct OStream_ab19b0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void Put8(uint32_t v);
    virtual void Put16(uint32_t v);
    virtual void P7();
    virtual void P8();
    virtual void Put32(uint32_t v);
    virtual void P10();
    virtual void P11();
    virtual void PutFloat(uint32_t v);
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual bool Failed();
};
// STUB: 0x005dada0
void Fn005dada0(OStream_ab19b0* s, const Sub_ab19b0* v);

struct TripData_ab19b0 {
    Sub_ab19b0 mA;
    Sub_ab19b0 mB;
    uint32_t mn18;
    uint8_t mb1c;
    uint8_t mb1d;
    uint8_t mb1e;
    uint8_t mb1f;
    uint16_t mw20;
    uint16_t mw22;
    uint32_t mn24;
    uint32_t mn28;
    bool WriteDraft_ab19b0(OStream_ab19b0* s) const;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0070e0b0 score 30
bool TripData_ab19b0::WriteDraft_ab19b0(OStream_ab19b0* s) const
{
    s->Put32(2);
    Fn005dada0(s, &mA);
    Fn005dada0(s, &mB);
    s->Put32(mn18);
    s->Put8(mb1c);
    s->Put8(mb1d);
    s->Put8(mb1e);
    s->Put8(mb1f);
    s->Put16(mw20);
    s->Put16(mw22);
    s->PutFloat(mn24);
    s->Put32(mn28);
    return !s->Failed();
}
#endif
