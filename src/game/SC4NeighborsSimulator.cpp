#include <cstddef>
#include "game/Globals.h"
#include "classes/cSC4NeighborsSimulator.h"
#include "classes/cSC4NeighborDeal.h"
#include "classes/cSC4NeighborConnection.h"

// A date object embedded in a deal (only its setter is called here).
struct Date_ab1cb0 {
    // STUB: 0x009b2c1c
    void SetJulian(uint32_t value);
};

// The date argument of the date setters: only slot 26 (the day count) is read.
struct DateArg_ab1cb0 {
    virtual void P00() = 0; virtual void P01() = 0; virtual void P02() = 0; virtual void P03() = 0;
    virtual void P04() = 0; virtual void P05() = 0; virtual void P06() = 0; virtual void P07() = 0;
    virtual void P08() = 0; virtual void P09() = 0; virtual void P10() = 0; virtual void P11() = 0;
    virtual void P12() = 0; virtual void P13() = 0; virtual void P14() = 0; virtual void P15() = 0;
    virtual void P16() = 0; virtual void P17() = 0; virtual void P18() = 0; virtual void P19() = 0;
    virtual void P20() = 0; virtual void P21() = 0; virtual void P22() = 0; virtual void P23() = 0;
    virtual void P24() = 0; virtual void P25() = 0;
    virtual uint32_t GetDays() = 0;
};

// The list of deals the simulator keeps (the standard list with the game's allocator).
struct DealList_ab1ee0 {
    // STUB: 0x004a9150
    DealList_ab1ee0* Assign(const DealList_ab1ee0* other);
};

// FUNCTION: 0x006cfd70
void cSC4NeighborsSimulator::MarkDealsDirty()
{
    mbDealsDirty = true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006d4730 score 3
bool cSC4NeighborConnection::Slot11_ab1e7c()
{
    return mnFlags & 1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006d4760 score 7
bool cSC4NeighborConnection::Slot13_ab1e7c()
{
    return ((mnFlags >> 1) ^ 1) & 1;
}
#endif

// FUNCTION: 0x006ce220
uint32_t cSC4NeighborDeal::Slot39_ab1cb0(uint32_t flags)
{
    return (mnFlags & flags) != 0;
}

// FUNCTION: 0x006d4670
void cSC4NeighborsSimulator::FindDealsAll(uint32_t list)
{
    OB_PTR(DealList_ab1ee0, list)->Assign(reinterpret_cast<DealList_ab1ee0*>(&mDeals));
}

// FUNCTION: 0x006ce0d0
void cSC4NeighborDeal::Slot05_ab1cb0(uint32_t x, uint32_t y)
{
    mnOtherCellX = x;
    mnOtherCellY = y;
}

// FUNCTION: 0x006ce200
uint32_t cSC4NeighborDeal::Slot38_ab1cb0(uint32_t flags)
{
    return (mnFlags & flags) == flags;
}

// FUNCTION: 0x006ce0b0
void cSC4NeighborDeal::Slot04_ab1cb0(uint32_t x, uint32_t y)
{
    *OB_PTR(int32_t, x) = mnCityCellX;
    *OB_PTR(int32_t, y) = mnCityCellY;
}

// FUNCTION: 0x006d46f0
void cSC4NeighborConnection::Slot06_ab1e7c(uint32_t x, uint32_t y)
{
    *OB_PTR(int32_t, x) = mnCellX;
    *OB_PTR(int32_t, y) = mnCellY;
}

// FUNCTION: 0x006d4710
void cSC4NeighborConnection::Slot08_ab1e7c(uint32_t x, uint32_t y)
{
    *OB_PTR(int32_t, x) = mnOtherCellX;
    *OB_PTR(int32_t, y) = mnOtherCellY;
}

// FUNCTION: 0x006ce120
void cSC4NeighborDeal::Slot25_ab1cb0(uint32_t date)
{
    reinterpret_cast<Date_ab1cb0*>(&mStartDate)->SetJulian(OB_PTR(DateArg_ab1cb0, date)->GetDays());
}

// FUNCTION: 0x006ce160
void cSC4NeighborDeal::Slot27_ab1cb0(uint32_t date)
{
    reinterpret_cast<Date_ab1cb0*>(&mExpirationDate)->SetJulian(OB_PTR(DateArg_ab1cb0, date)->GetDays());
}

// FUNCTION: 0x006ce1a0
void cSC4NeighborDeal::Slot29_ab1cb0(uint32_t date)
{
    reinterpret_cast<Date_ab1cb0*>(&mCurrentDate)->SetJulian(OB_PTR(DateArg_ab1cb0, date)->GetDays());
}

// FUNCTION: 0x006ce1e0
void cSC4NeighborDeal::Slot31_ab1cb0(uint32_t date)
{
    reinterpret_cast<Date_ab1cb0*>(&mSuspensionDate)->SetJulian(OB_PTR(DateArg_ab1cb0, date)->GetDays());
}

#ifdef OB_DRAFTS
// CLOSE: 0x006ce060 score 3
unsigned int cSC4NeighborConnection::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete static_cast<cSCPropertyHolder*>(this);
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006ce2c0 score 3
unsigned int cSC4NeighborDeal::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete static_cast<cSCPropertyHolder*>(this);
    return 0;
}
#endif

// FUNCTION: 0x006d4740
void cSC4NeighborConnection::Slot12_ab1e7c(uint32_t visited)
{
    if (static_cast<uint8_t>(visited)) {
        mnFlags |= 1;
    } else {
        mnFlags &= ~1;
    }
}

// FUNCTION: 0x006d4770
void cSC4NeighborConnection::Slot14_ab1e7c(uint32_t active)
{
    if (!static_cast<uint8_t>(active)) {
        mnFlags |= 2;
    } else {
        mnFlags &= ~2;
    }
}

// FUNCTION: 0x006ce610
void cSC4NeighborDeal::Slot34_ab1cb0()
{
    Slot37_ab1cb0(4, 1);
    Slot37_ab1cb0(2, 0);
    Slot11_ab1cb0(0);
}

// FUNCTION: 0x006ce770
uint32_t cSC4NeighborsSimulator::Slot02_ab1ee0()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Shutdown();
    delete this;
    return 0;
}

// FUNCTION: 0x006cdfa0
void cSC4NeighborsSimulator::FindConnectionOnOtherSide(uint32_t connection)
{
    cSC4NeighborConnection* conn = OB_PTR(cSC4NeighborConnection, connection);
    uint32_t type = conn->Slot05_ab1e7c();
    int32_t x, z;
    conn->Slot06_ab1e7c(OB_ADDR(&x), OB_ADDR(&z));
    Slot14_ab1ee0(type, x, z);
}

// The interface at +0x8 of the regional city object (non-pure: only used as a member, never constructed).
struct RegionalCitySub_ab1ee0 {
    virtual void P00(); virtual void P01(); virtual void P02(); virtual void P03(); virtual void P04(); virtual void P05(); virtual void P06(); virtual void P07(); virtual void P08(); virtual void P09(); virtual void P10(); virtual void P11(); virtual void P12(); virtual void P13(); virtual void P14(); virtual void P15(); virtual void P16(); virtual void P17(); virtual void P18(); virtual void P19(); virtual void P20(); virtual void P21(); virtual void P22(); virtual void P23(); virtual void P24(); virtual void P25(); virtual void P26();
    virtual uint32_t Slot27(RegionalCitySub_ab1ee0* other);
};

// A regional city object seen from outside: its interface sits at +0x8.
struct RegionalCityObj_ab1ee0 {
    char mPad[8];
    RegionalCitySub_ab1ee0 mSub;
};

// A node of the doubly linked lists the simulator keeps (next, previous, the value).
struct Node_ab1ee0 {
    Node_ab1ee0* mpNext;
    Node_ab1ee0* mpPrev;
    cSC4NeighborConnection* mpValue;
};

// The regional city (its interface at +0x8): the calls the simulator uses.
struct RegionalCity_ab1ee0 {
    virtual void P00() = 0; virtual void P01() = 0; virtual void P02() = 0; virtual void P03() = 0; virtual void P04() = 0; 
    virtual void GetPosition(int32_t* x, int32_t* z) = 0;
    virtual void P06() = 0;
    virtual void GetCitySize(int32_t* x, int32_t* z) = 0;
    virtual void P08() = 0; virtual void P09() = 0; virtual void P10() = 0; virtual void P11() = 0; virtual void P12() = 0; virtual void P13() = 0; virtual void P14() = 0; virtual void P15() = 0; virtual void P16() = 0; virtual void P17() = 0; virtual void P18() = 0; virtual void P19() = 0; 
    virtual void* FindConnection(int32_t type, int32_t x, int32_t z) = 0;
    virtual void P21() = 0; virtual void P22() = 0; virtual void P23() = 0; virtual void P24() = 0; virtual void P25() = 0; virtual void P26() = 0; 
    virtual uint32_t Slot27(void* other) = 0;
};

// The region (only the lookup of a city by cell).
struct Region_ab1ee0 {
    virtual void P00() = 0; virtual void P01() = 0; virtual void P02() = 0; virtual void P03() = 0; virtual void P04() = 0; virtual void P05() = 0; virtual void P06() = 0; virtual void P07() = 0; virtual void P08() = 0; virtual void P09() = 0; virtual void P10() = 0; 
    virtual void** FindCity(int32_t x, int32_t z) = 0;
};

// The application object (global 0xb43c94).
struct App_ab1ee0 {
    virtual void P00() = 0; virtual void P01() = 0; virtual void P02() = 0; virtual void P03() = 0; virtual void P04() = 0; virtual void P05() = 0; virtual void P06() = 0; virtual void P07() = 0; virtual void P08() = 0; virtual void P09() = 0; virtual void P10() = 0; virtual void P11() = 0; virtual void P12() = 0; virtual void P13() = 0; virtual void P14() = 0; virtual void P15() = 0; virtual void P16() = 0; virtual void P17() = 0; virtual void P18() = 0; virtual void P19() = 0; virtual void P20() = 0; virtual void P21() = 0; virtual void P22() = 0; virtual void P23() = 0; virtual void P24() = 0; virtual void P25() = 0; virtual void P26() = 0; virtual void P27() = 0; virtual void P28() = 0; virtual void P29() = 0; virtual void P30() = 0; virtual void P31() = 0; virtual void P32() = 0; virtual void P33() = 0; virtual void P34() = 0; 
    virtual Region_ab1ee0* GetRegion() = 0;
    virtual RegionalCity_ab1ee0* GetRegionalCity() = 0;
};

// GLOBAL: 0x00b43c94
extern App_ab1ee0* gpB43c94_ab1ee0;

// STUB: 0x006ce920
bool Fn006ce920(int32_t x, int32_t z, int32_t* cellX, int32_t* cellZ, RegionalCity_ab1ee0** city, int32_t* nx, int32_t* nz);

#ifdef OB_DRAFTS
// CLOSE: 0x006ce6a0 score 15
bool Fn006ce6a0(RegionalCityObj_ab1ee0* a, RegionalCityObj_ab1ee0* b)
{
    if (b) {
        return a->mSub.Slot27(&b->mSub) == 0;
    }
    return a->mSub.Slot27(0) == 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006ce7a0 score 53
bool Fn006ce7a0(int32_t x, int32_t z, RegionalCity_ab1ee0* city)
{
    if (!city) {
        city = gpB43c94_ab1ee0->GetRegionalCity();
    }
    int32_t sizeX, sizeZ;
    city->GetCitySize(&sizeX, &sizeZ);
    bool onX = x == -1 || x == (sizeX << 6);
    bool onZ = z == -1 || z == (sizeZ << 6);
    return onX != onZ;
}
#endif

// FUNCTION: 0x006ce820
void Fn006ce820(int32_t x, int32_t z, int32_t* outX, int32_t* outZ, RegionalCity_ab1ee0* city)
{
    if (!city) {
        city = gpB43c94_ab1ee0->GetRegionalCity();
    }
    int32_t sizeX, sizeZ;
    city->GetCitySize(&sizeX, &sizeZ);
    int32_t edge = -1;
    if (x < 0) {
        edge = 3;
    } else if (z < 0) {
        edge = 0;
    } else if (x >= (sizeX << 6)) {
        edge = 1;
    } else if (z >= (sizeZ << 6)) {
        edge = 2;
    }
    city->GetPosition(outX, outZ);
    int32_t cx = x / 64;
    int32_t cz = z / 64;
    switch (edge) {
    case 3:
        *outX -= 1;
        *outZ += cz;
        return;
    case 0:
        *outX += cx;
        *outZ -= 1;
        return;
    case 1:
        *outX += sizeX;
        *outZ += cz;
        return;
    case 2:
        *outX += cx;
        *outZ += sizeZ;
        break;
    }
}

// FUNCTION: 0x006d4820
void cSC4NeighborConnection::Slot05_ab1800(uint32_t rect)
{
    int32_t* r = OB_PTR(int32_t, rect);
    r[0] = mnCellX;
    r[1] = mnCellY;
    r[2] = mnCellX;
    r[3] = mnCellY;
}

// FUNCTION: 0x006cf250
void cSC4NeighborConnection::Slot10_ab1e7c(uint32_t city)
{
    Fn006ce820(mnCellX, mnCellY, &mnOtherCellX, &mnOtherCellY, OB_PTR(RegionalCity_ab1ee0, city));
}

// FUNCTION: 0x006cf030
void* cSC4NeighborsSimulator::FindCityOnOtherSideOfConnection(uint32_t x, uint32_t z)
{
    Fn006ce820(x, z, reinterpret_cast<int32_t*>(&x), reinterpret_cast<int32_t*>(&z), 0);
    Region_ab1ee0* region = gpB43c94_ab1ee0->GetRegion();
    if (region) {
        void** entry = region->FindCity(x, z);
        if (entry) {
            return *entry;
        }
    }
    return 0;
}

// FUNCTION: 0x006cf720
void* cSC4NeighborsSimulator::Slot15_ab1ee0(uint32_t type, uint32_t city)
{
    for (Node_ab1ee0* n = static_cast<Node_ab1ee0*>(mpConnectionsHead)->mpNext; n != mpConnectionsHead; n = n->mpNext) {
        cSC4NeighborConnection* conn = n->mpValue;
        if (conn->Slot05_ab1e7c() == type && !conn->Slot11_ab1e7c() && conn->Slot09_ab1e7c() == city) {
            return conn;
        }
    }
    return 0;
}

// FUNCTION: 0x006ce640
bool cSC4NeighborDeal::Slot35_ab1cb0()
{
    if (static_cast<uint8_t>(Slot39_ab1cb0(1)) && !static_cast<uint8_t>(Slot39_ab1cb0(0x38))) {
        Slot37_ab1cb0(2, 1);
        Slot37_ab1cb0(1, 0);
        Slot37_ab1cb0(4, 0);
        return true;
    }
    return false;
}

// FUNCTION: 0x006cede0
void* cSC4NeighborsSimulator::Slot14_ab1ee0(uint32_t type, uint32_t x, uint32_t z)
{
    RegionalCity_ab1ee0* city = 0;
    int32_t cellX, cellZ, nx, nz;
    if (Fn006ce920(x, z, &cellX, &cellZ, &city, &nx, &nz)) {
        return city->FindConnection(type, nx, nz);
    }
    return 0;
}

// The stream a serializable writes to or reads from (the calls used here).
struct Stream_a80784 {
    virtual void P00() = 0; virtual void P01() = 0; virtual void P02() = 0; virtual void P03() = 0; virtual void P04() = 0; 
    virtual void Slot05(uint8_t* value) = 0;
    virtual void P06() = 0;
    virtual void Slot07(uint16_t* value) = 0;
    virtual void Slot08(int32_t* value) = 0;
    virtual void Slot09(uint32_t* value) = 0;
    virtual void P10() = 0; virtual void P11() = 0; virtual void P12() = 0; virtual void P13() = 0; virtual void P14() = 0; virtual void P15() = 0; virtual void P16() = 0; virtual void P17() = 0; 
    virtual bool GetError() = 0;
};

// The stream when writing: the values go by value.
struct OutStream_a80784 {
    virtual void P00() = 0; virtual void P01() = 0; virtual void P02() = 0; virtual void P03() = 0; virtual void P04() = 0; 
    virtual void SetUint8(uint8_t value) = 0;
    virtual void P06() = 0;
    virtual void SetUint16(uint32_t value) = 0;
    virtual void SetSint32(int32_t value) = 0;
    virtual void SetUint32(uint32_t value) = 0;
    virtual void P10() = 0; virtual void P11() = 0; virtual void P12() = 0; virtual void P13() = 0; virtual void P14() = 0; virtual void P15() = 0; virtual void P16() = 0; virtual void P17() = 0; 
    virtual bool GetError() = 0;
};

// FUNCTION: 0x006d4640
void cSC4NeighborsSimulator::Slot07_ab1ee0(uint32_t a, uint32_t b, uint32_t c)
{
    void* conn = Slot11_ab1ee0(a, b, c);
    if (conn) {
        Fn006d17b0(conn, 1);
    }
}

// FUNCTION: 0x006ce000
bool cSC4NeighborConnection::QueryInterface(unsigned int iid, void** ppv)
{
    if (iid != 1 && iid != 0x773fef2) {
        if (iid != 0xe4fda3d4) {
            return false;
        }
        *ppv = static_cast<cUnk00a80784*>(this);
        AddRef();
        return true;
    }
    *ppv = this;
    AddRef();
    return true;
}

// FUNCTION: 0x006ce260
bool cSC4NeighborDeal::QueryInterface(unsigned int iid, void** ppv)
{
    if (iid != 1 && iid != 0x773fef1) {
        if (iid != 0xe4fda3d4) {
            return false;
        }
        *ppv = static_cast<cUnk00a80784*>(this);
        AddRef();
        return true;
    }
    *ppv = this;
    AddRef();
    return true;
}

// FUNCTION: 0x006cf6b0
void* cSC4NeighborsSimulator::Slot11_ab1ee0(uint32_t type, uint32_t x, uint32_t z)
{
    for (Node_ab1ee0* n = static_cast<Node_ab1ee0*>(mpConnectionsHead)->mpNext; n != mpConnectionsHead; n = n->mpNext) {
        cSC4NeighborConnection* conn = n->mpValue;
        int32_t cx, cz;
        conn->Slot06_ab1e7c(OB_ADDR(&cx), OB_ADDR(&cz));
        if (conn->Slot05_ab1e7c() == type && cx == static_cast<int32_t>(x) && cz == static_cast<int32_t>(z)) {
            return conn;
        }
    }
    return 0;
}

// FUNCTION: 0x006cf080
bool cSC4NeighborConnection::Slot03_a80784(void* stream)
{
    OutStream_a80784* s = static_cast<OutStream_a80784*>(stream);
    s->SetUint16(1);
    s->SetUint32(mnType);
    s->SetSint32(mnCellX);
    s->SetSint32(mnCellY);
    s->SetSint32(mnOtherCellX);
    s->SetSint32(mnOtherCellY);
    s->SetUint8(mnFlags);
    cSCPropertyHolder::Slot03_aaee5c(OB_ADDR(s));
    return !s->GetError();
}

// FUNCTION: 0x006cf0f0
bool cSC4NeighborConnection::Slot04_a80784(void* stream)
{
    Stream_a80784* s = static_cast<Stream_a80784*>(stream);
    uint16_t version;
    s->Slot07(&version);
    if (version != 1) {
        return false;
    }
    uint32_t type;
    s->Slot09(&type);
    mnType = type;
    s->Slot08(&mnCellX);
    s->Slot08(&mnCellY);
    s->Slot08(&mnOtherCellX);
    s->Slot08(&mnOtherCellY);
    s->Slot05(&mnFlags);
    cSCPropertyHolder::Slot04_aaee5c(OB_ADDR(s));
    return !s->GetError();
}

#ifdef OB_DRAFTS
// CLOSE: 0x006cf660 score 17
void Fn006cf660(Node_ab1ee0** out, Node_ab1ee0* first, Node_ab1ee0* last, uint32_t type)
{
    if (first != last) {
        do {
            cSC4NeighborConnection* conn = first->mpValue;
            if (conn) {
                conn->AddRef();
            }
            bool found = conn->Slot05_ab1e7c() == type;
            conn->Release();
            if (found) {
                break;
            }
            first = first->mpNext;
        } while (first != last);
    }
    *out = first;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006cfa50 score 5
bool cSC4NeighborDeal::Slot37_ab1cb0(uint32_t flags, uint32_t set)
{
    uint32_t old = mnFlags;
    if (static_cast<uint8_t>(set)) {
        if ((flags & 0x38) && (old & 0x100)) {
            flags &= 0xffffffc7;
        }
        mnFlags = old | flags;
    } else {
        mnFlags = old & ~flags;
    }
    if (!static_cast<uint8_t>(Slot39_ab1cb0(0x80)) && mnFlags != old) {
        Fn006cf5c0(1, 0);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006cf960 score 9
void cSC4NeighborDeal::Slot11_ab1cb0(uint32_t amount)
{
    if (gpB43cec && gpB43cec->GetNeighborsSimulator()) {
        if (!static_cast<uint8_t>(Slot39_ab1cb0(0x300))) {
            mnAmount = amount;
            if (!static_cast<uint8_t>(Slot39_ab1cb0(0x80))) {
                Fn006cf5c0(0, 0);
            }
            Slot23_ab1cb0();
        }
    }
}
#endif

// The neighbors simulator as the deals reach it (the cost call only).
struct SimView_ab1ee0 {
    virtual void P00() = 0; virtual void P01() = 0; virtual void P02() = 0; virtual void P03() = 0; virtual void P04() = 0; virtual void P05() = 0; virtual void P06() = 0; virtual void P07() = 0; virtual void P08() = 0; virtual void P09() = 0; virtual void P10() = 0; virtual void P11() = 0; virtual void P12() = 0; virtual void P13() = 0; virtual void P14() = 0; virtual void P15() = 0; virtual void P16() = 0; virtual void P17() = 0; virtual void P18() = 0; virtual void P19() = 0; virtual void P20() = 0; virtual void P21() = 0; virtual void P22() = 0; virtual void P23() = 0; virtual void P24() = 0; virtual void P25() = 0; virtual void P26() = 0; virtual void P27() = 0; virtual void P28() = 0; virtual void P29() = 0; virtual void P30() = 0; virtual void P31() = 0; virtual void P32() = 0; virtual void P33() = 0; virtual void P34() = 0; 
    virtual float GetDealCost(int32_t type, double amount, void* city) = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x006cf9c0 score 5
void cSC4NeighborDeal::Slot23_ab1cb0()
{
    if (!static_cast<uint8_t>(Slot39_ab1cb0(0x300))) {
        SimView_ab1ee0* sim = OB_PTR(SimView_ab1ee0, gpB43cec->GetNeighborsSimulator());
        mnCost = static_cast<int64_t>(sim->GetDealCost(mnType, static_cast<double>(mnAmount), OB_PTR(void, Slot07_ab1cb0())));
        if (mnCost == 0) {
            mnCost = 1;
        }
        if (!static_cast<uint8_t>(Slot39_ab1cb0(0x80))) {
            Fn006cf5c0(1, 0);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006cf330 score 0 (returns a pointer through uint32_t: base slot Slot07_ab1cb0 needs void*)
uint32_t cSC4NeighborDeal::Slot07_ab1cb0()
{
    Region_ab1ee0* region = gpB43c94_ab1ee0->GetRegion();
    if (region) {
        void** entry = region->FindCity(mnOtherCellX, mnOtherCellY);
        if (entry) {
            return OB_ADDR(*entry);
        }
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006cf180 score 0 (returns a pointer through uint32_t: base slot Slot09_ab1e7c needs void*)
uint32_t cSC4NeighborConnection::Slot09_ab1e7c()
{
    Region_ab1ee0* region = gpB43c94_ab1ee0->GetRegion();
    if (region) {
        void** entry = region->FindCity(mnOtherCellX, mnOtherCellY);
        if (entry) {
            return OB_ADDR(*entry);
        }
    }
    return 0;
}
#endif
