#include <stddef.h>
#include "classes/cSC4PollutionSimulator.h"

// The tunables the simulator reads at start (static members of the class in the original).
// GLOBAL: 0x00b49ba4
extern uint32_t gnB49ba4;
// GLOBAL: 0x00b49ba0
extern uint32_t gnB49ba0;
// GLOBAL: 0x00b49b9c
extern uint32_t gnB49b9c;
// GLOBAL: 0x00b49b98
extern uint32_t gnB49b98;
// GLOBAL: 0x00b49b94
extern uint32_t gnB49b94;
// GLOBAL: 0x00b49b7c
extern uint32_t gnB49b7c;
// GLOBAL: 0x00b49b78
extern uint32_t gnB49b78;
// GLOBAL: 0x00b49b80
extern uint32_t gnB49b80;

// One of the simulator's cell grids, seen through its vtable.
struct Grid_ab2630 {
    virtual void Slot00_ab2630();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab2630();
    virtual void Slot04_ab2630();
    virtual void Slot05_ab2630();
    virtual void Slot06_ab2630();
    virtual uint32_t Get(uint32_t x, uint32_t z);
    virtual void Slot08_ab2630();
    virtual void Slot09_ab2630();
    virtual void Slot10_ab2630();
    virtual uint32_t GetShift();
    virtual void Slot12_ab2630();
    virtual void Slot13_ab2630();
    virtual void Slot14_ab2630();
    virtual void Slot15_ab2630();
    virtual void Slot16_ab2630();
    virtual void Slot17_ab2630();
    virtual void Slot18_ab2630();
    virtual void Slot19_ab2630();
    virtual void Slot20_ab2630();
    virtual void Slot21_ab2630();
    virtual void Slot22_ab2630();
    virtual void Slot23_ab2630();
    virtual void Slot24_ab2630();
    virtual void Slot25_ab2630();
    virtual void Set(uint32_t x, uint32_t z, int16_t value);
};

// An occupant (a building): slot 6 gives its property holder.
struct Occupant_ab2630 {
    virtual void Slot00_ab2630();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab2630();
    virtual void Slot04_ab2630();
    virtual void Slot05_ab2630();
    virtual void* GetPropertyHolder();
};

// The object at 0x24: asked for the kind of a cell.
struct Cells_ab2630 {
    virtual void Slot00_ab2630();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab2630();
    virtual void Slot04_ab2630();
    virtual void Slot05_ab2630();
    virtual void Slot06_ab2630();
    virtual void Slot07_ab2630();
    virtual void Slot08_ab2630();
    virtual void Slot09_ab2630();
    virtual void Slot10_ab2630();
    virtual void Slot11_ab2630();
    virtual uint32_t GetCellKind(uint32_t x, uint32_t z);
};

// The global object at 0xb43da0 (the power state of an occupant).
struct Host_ab2630 {
    virtual void Slot00_ab2630();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab2630();
    virtual void Slot04_ab2630();
    virtual void Slot05_ab2630();
    virtual void Slot06_ab2630();
    virtual void Slot07_ab2630();
    virtual void Slot08_ab2630();
    virtual void Slot09_ab2630();
    virtual void Slot10_ab2630();
    virtual void Slot11_ab2630();
    virtual void Slot12_ab2630();
    virtual void Slot13_ab2630();
    virtual void Slot14_ab2630();
    virtual void Slot15_ab2630();
    virtual void Slot16_ab2630();
    virtual void Slot17_ab2630();
    virtual void Slot18_ab2630();
    virtual void Slot19_ab2630();
    virtual void Slot20_ab2630();
    virtual void Slot21_ab2630();
    virtual void Slot22_ab2630();
    virtual void Slot23_ab2630();
    virtual void Slot24_ab2630();
    virtual void Slot25_ab2630();
    virtual void Slot26_ab2630();
    virtual void Slot27_ab2630();
    virtual void Slot28_ab2630();
    virtual void Slot29_ab2630();
    virtual void Slot30_ab2630();
    virtual bool IsPowered(void* occupant);
};
// GLOBAL: 0x00b43da0
extern Host_ab2630* gpB43da0_ab2630;

// STUB: 0x005fd480
bool Fn005fd480_ab2630(void* holder, uint32_t id, void* out);
// STUB: 0x005fd450
bool Fn005fd450_ab2630(void* holder, uint32_t id, void* out);
// STUB: 0x005fdac0
bool Fn005fdac0_ab2630(void* holder, uint32_t id, void* out);

// GLOBAL: 0x00b49bc4
extern uint32_t gnB49bc4;


// A node of the std::list the simulator keeps its occupants in: next, previous, then the value.
struct Node_ab2630 {
    Node_ab2630* mpNext;
    Node_ab2630* mpPrev;
    Occupant_ab2630* mpOccupant;
};
struct List_ab2630 {
    Node_ab2630* mpHead;
    // STUB: 0x00413fe0
    void Fn00413fe0();
};

// STUB: 0x0090cf63
void Fn0090cf63_ab2630(void* block);

struct Releasable_ab2630 {
    virtual void Slot00_ab2630();
    virtual void AddRef();
    virtual void Release();
};

// A heap box of the shutdown: it owns one block.
struct Box_ab2630 {
    void* mpInner;
};
// GLOBAL: 0x00b49ba8
extern bool gbB49ba8;
// GLOBAL: 0x00b49bac
extern Box_ab2630* gpB49bac;
// GLOBAL: 0x00b49bb0
extern Box_ab2630* gpB49bb0;
// GLOBAL: 0x00b49bb4
extern Box_ab2630* gpB49bb4;
// GLOBAL: 0x00b49bb8
extern Box_ab2630* gpB49bb8;
// GLOBAL: 0x00b49bbc
extern Box_ab2630* gpB49bbc;
// GLOBAL: 0x00b49bc0
extern Box_ab2630* gpB49bc0;

// The property holder of an occupant: slot 13 sets a value.
struct Holder_ab2630 {
    virtual void Slot00_ab2630();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab2630();
    virtual void Slot04_ab2630();
    virtual void Slot05_ab2630();
    virtual void Slot06_ab2630();
    virtual void Slot07_ab2630();
    virtual void Slot08_ab2630();
    virtual void Slot09_ab2630();
    virtual void Slot10_ab2630();
    virtual void Slot11_ab2630();
    virtual void Slot12_ab2630();
    virtual void SetValue(uint32_t id, uint32_t value, bool flag);
};

// The budget simulator (SL::spBudgetSim).
struct Budget_ab2630 {
    virtual void Slot00_ab2630();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab2630();
    virtual void Slot04_ab2630();
    virtual void Slot05_ab2630();
    virtual void Slot06_ab2630();
    virtual void Slot07_ab2630();
    virtual void Slot08_ab2630();
    virtual void Slot09_ab2630();
    virtual void Slot10_ab2630();
    virtual void Slot11_ab2630();
    virtual void Slot12_ab2630();
    virtual void Slot13_ab2630();
    virtual void Slot14_ab2630();
    virtual void Slot15_ab2630();
    virtual void Slot16_ab2630();
    virtual void Slot17_ab2630();
    virtual void Slot18_ab2630();
    virtual void Slot19_ab2630();
    virtual void Slot20_ab2630();
    virtual void Slot21_ab2630();
    virtual void Slot22_ab2630();
    virtual void Slot23_ab2630();
    virtual void Slot24_ab2630();
    virtual void Slot25_ab2630();
    virtual void Slot26_ab2630();
    virtual void Slot27_ab2630();
    virtual void Slot28_ab2630();
    virtual void Slot29_ab2630();
    virtual void Slot30_ab2630();
    virtual void Slot31_ab2630();
    virtual void Slot32_ab2630();
    virtual void Slot33_ab2630();
    virtual void Slot34_ab2630();
    virtual void Slot35_ab2630();
    virtual void Slot36_ab2630();
    virtual void Slot37_ab2630();
    virtual void Slot38_ab2630();
    virtual void Slot39_ab2630();
    virtual void Slot40_ab2630();
    virtual void Slot41_ab2630();
    virtual void Slot42_ab2630();
    virtual void Slot43_ab2630();
    virtual void Slot44_ab2630();
    virtual void Slot45_ab2630();
    virtual void Slot46_ab2630();
    virtual void Slot47_ab2630();
    virtual void Slot48_ab2630();
    virtual void Slot49_ab2630();
    virtual void Slot50_ab2630();
    virtual bool FindLineItem(void* holder, uint32_t id, void* record);
    virtual void Slot52_ab2630();
    virtual void SetLineItem(void* holder, uint32_t id, int64_t cost);
    virtual void Slot54_ab2630();
    virtual void Slot55_ab2630();
    virtual void Slot56_ab2630();
    virtual struct Department_ab2630* DepartmentFor(void* record);
};
// GLOBAL: 0x00b43d64
extern Budget_ab2630* gpB43d64_ab2630;

// A budget department: slot 13 adds a cost.
struct Department_ab2630 {
    virtual void Slot00_ab2630();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab2630();
    virtual void Slot04_ab2630();
    virtual void Slot05_ab2630();
    virtual void Slot06_ab2630();
    virtual void Slot07_ab2630();
    virtual void Slot08_ab2630();
    virtual void Slot09_ab2630();
    virtual void Slot10_ab2630();
    virtual void Slot11_ab2630();
    virtual void Slot12_ab2630();
    virtual void AddCost(int64_t cost);
};

// One budget line item as the budget simulator fills it.
struct Record_ab2630 {
    uint32_t mnHeader[4];
    int64_t mnCost;
    uint32_t mnId;
    uint32_t mnPad[2];
};

struct View_ab2630 {
    void* mpVtables[4];        // 0x0
    uint8_t mPad10[4];         // 0x10
    int32_t mnRefCount;        // 0x14
    uint8_t mPad18[0xc];       // 0x18
    Cells_ab2630* mpCells;     // 0x24
    uint8_t mPad28[0x18];      // 0x28
    Grid_ab2630* mpGrids[8];   // 0x40: indexed by pollution type from 4 (3 = radioactive at 0x4c)
    uint8_t mPad60[8];         // 0x60
    List_ab2630 mList68;       // 0x68
    List_ab2630 mList6c;       // 0x6c
    List_ab2630 mList70;       // 0x70
    List_ab2630 mList74;       // 0x74
    uint8_t mPad78[0x18];      // 0x78
    void* mp90;                // 0x90
    uint8_t mPad94[0x14];      // 0x94
    void* mpA8;                // 0xa8
    uint8_t mPadAc[8];         // 0xac
    void* mpB4;                // 0xb4
    uint8_t mPadB8[8];         // 0xb8
    void* mpC0;                // 0xc0
    uint8_t mPadC4[8];         // 0xc4
    void* mpCc;                // 0xcc
    uint8_t mPadD0[8];         // 0xd0
    Releasable_ab2630* mpD8;   // 0xd8
    void* mpDc;                // 0xdc
    uint8_t mPadE0[0xc];       // 0xe0
    void* mpEc;                // 0xec
    uint8_t mPadF0[0x48];      // 0xf0
    uint8_t mbGarbageUncollected; // 0x138
    uint8_t mPad139[0x37];     // 0x139
    int64_t mnLandfilled;      // 0x170
    uint64_t mnGarbageProduced;   // 0x178
    uint64_t mnGarbageImported;   // 0x180
    uint64_t mnGarbageExported;   // 0x188
    double mdGarbageRecycled;     // 0x190
    uint64_t mnGarbageIncinerated; // 0x198
    uint64_t mnGarbageToEnergy;   // 0x1a0
    uint64_t mnGarbageLandfilled; // 0x1a8
    uint8_t mPad1b0[8];        // 0x1b0
    uint32_t mnGarbageAbducted; // 0x1b8
    uint32_t mnActiveLandfills; // 0x1bc
    uint8_t mPad1c0[0x30];     // 0x1c0
    void* mp1f0;               // 0x1f0
    uint8_t mPad1f4[0x14];     // 0x1f4
    uint8_t mbDirty208;        // 0x208
    uint8_t mbDirtyAir;        // 0x209
    uint8_t mbDirtyWater;      // 0x20a
    uint8_t mbDirtyGarbage;    // 0x20b
    uint8_t mPad20c[4];        // 0x20c
    uint16_t mnWorstAirX;      // 0x210
    uint16_t mnWorstAirZ;      // 0x212
    int32_t mnWorstAirValue;   // 0x214
    uint16_t mnWorstWaterX;    // 0x218
    uint16_t mnWorstWaterZ;    // 0x21a
    int32_t mnWorstWaterValue; // 0x21c
    uint16_t mnWorstGarbageX;  // 0x220
    uint16_t mnWorstGarbageZ;  // 0x222
    int32_t mnWorstGarbageValue; // 0x224
    float mfEfficiency;        // 0x228
    int32_t mnGarbageSupply;   // 0x22c
};

// FUNCTION: 0x006e4f10
uint32_t cSC4PollutionSimulator::GetLandfillTileCapacity()
{
    return gnB49ba4;
}

// FUNCTION: 0x006e5060
uint32_t cSC4PollutionSimulator::GetMaxAirPollutionLevelForUI()
{
    return gnB49ba0;
}

// FUNCTION: 0x006e5070
uint32_t cSC4PollutionSimulator::GetMaxWaterPollutionLevelForUI()
{
    return gnB49b9c;
}

// FUNCTION: 0x006e5080
uint32_t cSC4PollutionSimulator::GetMaxGarbagePollutionLevelForUI()
{
    return gnB49b98;
}

// FUNCTION: 0x006e5090
uint32_t cSC4PollutionSimulator::GetMaxRadiationPollutionLevelForUI()
{
    return gnB49b94;
}

// FUNCTION: 0x006e4f20
uint64_t cSC4PollutionSimulator::GetGarbageAbductedPrevMonth()
{
    return reinterpret_cast<View_ab2630*>(this)->mnGarbageAbducted;
}

// FUNCTION: 0x006e4f60
uint64_t cSC4PollutionSimulator::Slot38_ab2630()
{
    return static_cast<int64_t>(reinterpret_cast<View_ab2630*>(this)->mdGarbageRecycled);
}

// FUNCTION: 0x006e2ff0
bool cSC4PollutionSimulator::IsGarbageUncollected()
{
    uint8_t flag = reinterpret_cast<View_ab2630*>(this)->mbGarbageUncollected;
    bool uncollected = flag != 0;
    return uncollected;
}

// FUNCTION: 0x006e4f30
uint64_t cSC4PollutionSimulator::GetGarbageProducedPrevMonth()
{
    return reinterpret_cast<View_ab2630*>(this)->mnGarbageProduced;
}

// FUNCTION: 0x006e4f40
uint64_t cSC4PollutionSimulator::GetGarbageImportedPrevMonth()
{
    return reinterpret_cast<View_ab2630*>(this)->mnGarbageImported;
}

// FUNCTION: 0x006e4f50
uint64_t cSC4PollutionSimulator::GetGarbageExportedPrevMonth()
{
    return reinterpret_cast<View_ab2630*>(this)->mnGarbageExported;
}

// FUNCTION: 0x006e4f70
uint64_t cSC4PollutionSimulator::GetGarbageIncineratedPrevMonth()
{
    return reinterpret_cast<View_ab2630*>(this)->mnGarbageIncinerated;
}

// FUNCTION: 0x006e4f80
uint64_t cSC4PollutionSimulator::GetGarbageConvertedToEnergyPrevMonth()
{
    return reinterpret_cast<View_ab2630*>(this)->mnGarbageToEnergy;
}

// FUNCTION: 0x006e4f90
uint64_t cSC4PollutionSimulator::GetGarbageLandfilledPrevMonth()
{
    return reinterpret_cast<View_ab2630*>(this)->mnGarbageLandfilled;
}

// FUNCTION: 0x006e3360
void* cSC4PollutionSimulator::Slot05_ab2630(uint32_t type)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    if (type == 3) {
        return self->mpGrids[3];
    }
    return self->mpGrids[type + 4];
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e31a0 score 2
bool cSC4PollutionSimulator::IsActiveLandfill(uint32_t x, uint32_t z)
{
    return static_cast<bool>((reinterpret_cast<View_ab2630*>(this)->mpGrids[6]->Get(x, z) >> 15) & 1);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e2ed0 score 5
bool cSC4PollutionSimulator::IsRadioactive(uint32_t x, uint32_t z)
{
    return static_cast<uint16_t>(reinterpret_cast<View_ab2630*>(this)->mpGrids[3]->Get(x, z)) != 0;
}
#endif

// FUNCTION: 0x006e3340
uint32_t cSC4PollutionSimulator::GetGarbageSupply()
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    if (self->mnGarbageSupply < 0) {
        self->mnGarbageSupply = 0;
    }
    return self->mnGarbageSupply;
}

// FUNCTION: 0x006e2ef0
void cSC4PollutionSimulator::GetAirValue(uint32_t x, uint32_t z, void* out)
{
    *static_cast<int32_t*>(out) = static_cast<int16_t>(reinterpret_cast<View_ab2630*>(this)->mpGrids[4]->Get(x, z));
}

// FUNCTION: 0x006e2f10
void cSC4PollutionSimulator::GetWaterValue(uint32_t x, uint32_t z, void* out)
{
    *static_cast<int32_t*>(out) = static_cast<int16_t>(reinterpret_cast<View_ab2630*>(this)->mpGrids[5]->Get(x, z));
}

// FUNCTION: 0x006e2f30
void cSC4PollutionSimulator::GetGarbageValue(uint32_t x, uint32_t z, void* out)
{
    *static_cast<int32_t*>(out) = static_cast<int16_t>(reinterpret_cast<View_ab2630*>(this)->mpGrids[6]->Get(x, z)) & 0xffff7fff;
}

// FUNCTION: 0x006e2dd0
bool cSC4PollutionSimulator::GetIncineratorCurrentCapacity(void* occupant, void* out)
{
    *static_cast<uint32_t*>(out) = 0;
    return GetCurrentCapacity(0xa8ebcf0c, occupant, out);
}

// FUNCTION: 0x006e2df0
bool cSC4PollutionSimulator::GetWasteToEnergyCurrentCapacity(void* occupant, void* out)
{
    *static_cast<uint32_t*>(out) = 0;
    return GetCurrentCapacity(0x48ebd0b1, occupant, out);
}

// FUNCTION: 0x006e2e10
bool cSC4PollutionSimulator::GetWaterTreatmentMaxCapacity(void* occupant, void* out)
{
    *static_cast<uint32_t*>(out) = 0;
    return GetMaxCapacity(0xc8ebd131, occupant, out);
}

// FUNCTION: 0x006e2e30
bool cSC4PollutionSimulator::GetWaterTreatmentCurrentCapacity(void* occupant, void* out)
{
    *static_cast<uint32_t*>(out) = 0;
    return GetCurrentCapacity(0xc8ebd131, occupant, out);
}

// FUNCTION: 0x006e2e50
bool cSC4PollutionSimulator::GetWaterTreatmentUsedCapacity(void* occupant, void* out)
{
    *static_cast<uint32_t*>(out) = 0;
    return GetMaxCapacity(0x28ecf510, occupant, out);
}

// FUNCTION: 0x006e2f60
bool cSC4PollutionSimulator::IsAirPolluted(uint32_t x, uint32_t z)
{
    uint32_t value;
    GetAirValue(x, z, &value);
    bool polluted = value >= gnB49b7c;
    return polluted;
}

// FUNCTION: 0x006e2f90
bool cSC4PollutionSimulator::IsWaterPolluted(uint32_t x, uint32_t z)
{
    uint32_t value;
    GetWaterValue(x, z, &value);
    bool polluted = value >= gnB49b78;
    return polluted;
}

// FUNCTION: 0x006e2fc0
bool cSC4PollutionSimulator::IsGarbageAccumulated(uint32_t x, uint32_t z)
{
    uint32_t value;
    GetGarbageValue(x, z, &value);
    bool polluted = value >= gnB49b80;
    return polluted;
}

// FUNCTION: 0x006e4fa0
void cSC4PollutionSimulator::GetWorstAirTract(void* x, void* z, void* value)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    *static_cast<int32_t*>(x) = self->mnWorstAirX;
    *static_cast<int32_t*>(z) = self->mnWorstAirZ;
    *static_cast<int32_t*>(value) = self->mnWorstAirValue;
}

// FUNCTION: 0x006e4fd0
void cSC4PollutionSimulator::GetWorstWaterTract(void* x, void* z, void* value)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    *static_cast<int32_t*>(x) = self->mnWorstWaterX;
    *static_cast<int32_t*>(z) = self->mnWorstWaterZ;
    *static_cast<int32_t*>(value) = self->mnWorstWaterValue;
}

// FUNCTION: 0x006e5000
void cSC4PollutionSimulator::GetWorstGarbageTract(void* x, void* z, void* value)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    *static_cast<int32_t*>(x) = self->mnWorstGarbageX;
    *static_cast<int32_t*>(z) = self->mnWorstGarbageZ;
    *static_cast<int32_t*>(value) = self->mnWorstGarbageValue;
}

// FUNCTION: 0x006e5f20
uint32_t cSC4PollutionSimulator::Release()
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    if (self->mnRefCount > 1) {
        --self->mnRefCount;
        return self->mnRefCount;
    }
    Slot04_ab2630();
    Fn006e4e20();
    delete this;
    return 0;
}

// FUNCTION: 0x006e3030
void cSC4PollutionSimulator::SetIsRadioactive(uint32_t x, uint32_t z, bool flag)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    uint32_t shift = self->mpGrids[3]->GetShift();
    self->mpGrids[3]->Set(x >> shift, z >> shift, flag);
    self->mbDirty208 = 1;
}

// FUNCTION: 0x006e3070
void cSC4PollutionSimulator::SetAirValue(uint32_t x, uint32_t z, uint32_t value)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    uint32_t shift = self->mpGrids[4]->GetShift();
    self->mpGrids[4]->Set(x >> shift, z >> shift, static_cast<int16_t>(value));
    self->mbDirtyAir = 1;
}

// FUNCTION: 0x006e30b0
void cSC4PollutionSimulator::SetWaterValue(uint32_t x, uint32_t z, uint32_t value)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    uint32_t shift = self->mpGrids[5]->GetShift();
    self->mpGrids[5]->Set(x >> shift, z >> shift, static_cast<int16_t>(value));
    self->mbDirtyWater = 1;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e30f0 score 1
void cSC4PollutionSimulator::SetGarbageValue(uint32_t x, uint32_t z, uint32_t value)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    uint32_t shift = self->mpGrids[6]->GetShift();
    int16_t old = static_cast<int16_t>(self->mpGrids[6]->Get(x, z));
    self->mpGrids[6]->Set(x >> shift, z >> shift, (old & 0xffff8000) | value);
    self->mbDirtyGarbage = 1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e37e0 score 2
int16_t cSC4PollutionSimulator::Slot06_ab2630(uint32_t type, uint32_t x, uint32_t z)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    int16_t zero = 0;
    int16_t value = self->mpGrids[type]->Get(x, z);
    const int16_t& result = (value < 0) ? zero : value;
    return result;
}
#endif

// FUNCTION: 0x006e3160
uint32_t cSC4PollutionSimulator::GetBuildingGarbageCapacity(uint32_t occupant)
{
    uint32_t value;
    bool found = Fn005fd450_ab2630(OB_PTR(Occupant_ab2630, occupant)->GetPropertyHolder(), 0x48ee7a44, &value);
    return found ? value : 0;
}

// FUNCTION: 0x006e2da0
bool cSC4PollutionSimulator::GetMaxCapacity(uint32_t id, void* occupant, void* out)
{
    *static_cast<uint32_t*>(out) = 0;
    return Fn005fd480_ab2630(static_cast<Occupant_ab2630*>(occupant)->GetPropertyHolder(), id, out);
}

// FUNCTION: 0x006e2e70
bool cSC4PollutionSimulator::GetIncineratorUsedCapacity(void* occupant, void* out)
{
    *static_cast<uint32_t*>(out) = 0;
    return Fn005fd480_ab2630(static_cast<Occupant_ab2630*>(occupant)->GetPropertyHolder(), 0xe8ecf641, out);
}

// FUNCTION: 0x006e2ea0
bool cSC4PollutionSimulator::GetWasteToEnergyUsedCapacity(void* occupant, void* out)
{
    *static_cast<uint32_t*>(out) = 0;
    return Fn005fd480_ab2630(static_cast<Occupant_ab2630*>(occupant)->GetPropertyHolder(), 0x88ecf76c, out);
}

// FUNCTION: 0x006e2d70
bool cSC4PollutionSimulator::GetRecyclingCenterMaxCapacity(void* occupant, void* out)
{
    *static_cast<uint32_t*>(out) = gnB49bc4;
    return Fn005fdac0_ab2630(static_cast<Occupant_ab2630*>(occupant)->GetPropertyHolder(), 0x88ed1059, out);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e3720 score 18
bool cSC4PollutionSimulator::GetRecyclingCenterCurrentCapacity(void* occupant, void* out)
{
    uint32_t value;
    if (GetCurrentCapacity(0x88ed1059, occupant, &value)) {
        *static_cast<float*>(out) = static_cast<float>(value) * 0.01f;
        return true;
    }
    *static_cast<uint32_t*>(out) = gnB49bc4;
    return false;
}
#endif

// FUNCTION: 0x006e3770
bool cSC4PollutionSimulator::GetCurrentOccupantEfficiency(void* occupant, void* out)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    float* percentage = static_cast<float*>(out);
    if (gpB43da0_ab2630->IsPowered(occupant)) {
        *percentage = self->mfEfficiency;
        float condition = 0.0f;
        if (GetCurrentOccupantCondition(occupant, &condition)) {
            *percentage = condition * *percentage;
            return true;
        }
    }
    *static_cast<uint32_t*>(out) = gnB49bc4;
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e32e0 score 31
void cSC4PollutionSimulator::AddToGarbageSupply(uint32_t amount)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    int32_t delta = static_cast<int32_t>(amount);
    if (delta > 0) {
        int32_t current = self->mnGarbageSupply;
        if (current + delta < current) {
            delta = 0x7fffffff - current;
        }
    } else if (delta < 0) {
        int32_t current = self->mnGarbageSupply;
        if (current + delta < 0) {
            delta = -current;
        }
    }
    int32_t total = self->mnGarbageSupply + delta;
    self->mnGarbageSupply = total;
    if (total < 0) {
        self->mnGarbageSupply = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e3250 score 55
void cSC4PollutionSimulator::GarbagePutInLandfill(uint32_t amount)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    int32_t delta = static_cast<int32_t>(amount);
    if (delta > 0) {
        int64_t current = self->mnLandfilled;
        if (current + delta < current) {
            delta = -1 - static_cast<int32_t>(self->mnLandfilled);
        }
    } else if (delta < 0) {
        int64_t current = self->mnLandfilled;
        if (current + delta > current) {
            delta = -static_cast<int32_t>(self->mnLandfilled);
        }
    }
    self->mnLandfilled += delta;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e31c0 score 8
void cSC4PollutionSimulator::SetIsActiveLandfill(uint32_t x, uint32_t z, bool flag)
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    bool on = flag;
    uint32_t kind = self->mpCells->GetCellKind(x, z);
    if (!on || kind == 0xe) {
        bool active = IsActiveLandfill(x, z);
        int16_t value;
        if (on) {
            if (active) {
                return;
            }
            value = static_cast<int16_t>(self->mpGrids[6]->Get(x, z) | 0x8000);
            self->mnActiveLandfills = self->mnActiveLandfills + 1;
        } else {
            if (!active) {
                return;
            }
            value = static_cast<int16_t>(self->mpGrids[6]->Get(x, z) & 0x7fff);
            if (self->mnActiveLandfills != 0) {
                self->mnActiveLandfills = self->mnActiveLandfills - 1;
            }
        }
        self->mpGrids[6]->Set(x, z, value);
        self->mbDirtyGarbage = 1;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e5150 score 68
bool Fn006e5150()
{
    if (gbB49ba8) {
        gbB49ba8 = false;
        if (gpB49bac) {
            Box_ab2630* box = gpB49bac;
            if (box->mpInner) {
                Fn0090cf63_ab2630(box->mpInner);
            }
            delete box;
            gpB49bac = 0;
        }
        if (gpB49bb0) {
            Box_ab2630* box = gpB49bb0;
            if (box->mpInner) {
                Fn0090cf63_ab2630(box->mpInner);
            }
            delete box;
            gpB49bb0 = 0;
        }
        if (gpB49bb4) {
            Box_ab2630* box = gpB49bb4;
            if (box->mpInner) {
                Fn0090cf63_ab2630(box->mpInner);
            }
            delete box;
            gpB49bb4 = 0;
        }
        if (gpB49bb8) {
            Box_ab2630* box = gpB49bb8;
            if (box->mpInner) {
                Fn0090cf63_ab2630(box->mpInner);
            }
            delete box;
            gpB49bb8 = 0;
        }
        if (gpB49bbc) {
            Box_ab2630* box = gpB49bbc;
            if (box->mpInner) {
                Fn0090cf63_ab2630(box->mpInner);
            }
            delete box;
            gpB49bbc = 0;
        }
        if (gpB49bc0) {
            Box_ab2630* box = gpB49bc0;
            if (box->mpInner) {
                Fn0090cf63_ab2630(box->mpInner);
            }
            delete box;
            gpB49bc0 = 0;
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e4e20 score 27
// The destructor body of the class: the four vtable stores at its start are not written (the vtable addresses are
// the compiler's to emit).
void cSC4PollutionSimulator::Fn006e4e20()
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    if (self->mp1f0) {
        Fn0090cf63_ab2630(self->mp1f0);
    }
    if (self->mpEc) {
        Fn0090cf63_ab2630(self->mpEc);
    }
    if (self->mpDc) {
        Fn0090cf63_ab2630(self->mpDc);
    }
    if (self->mpD8) {
        self->mpD8->Release();
    }
    if (self->mpCc) {
        Fn0090cf63_ab2630(self->mpCc);
    }
    if (self->mpC0) {
        Fn0090cf63_ab2630(self->mpC0);
    }
    if (self->mpB4) {
        Fn0090cf63_ab2630(self->mpB4);
    }
    if (self->mpA8) {
        Fn0090cf63_ab2630(self->mpA8);
    }
    if (self->mp90) {
        Fn0090cf63_ab2630(self->mp90);
    }
    self->mList74.Fn00413fe0();
    self->mList70.Fn00413fe0();
    self->mList6c.Fn00413fe0();
    self->mList68.Fn00413fe0();
}
#endif

// FUNCTION: 0x006e3f50
void cSC4PollutionSimulator::Fn006e3f50()
{
    View_ab2630* self = reinterpret_cast<View_ab2630*>(this);
    Node_ab2630* head = self->mList70.mpHead;
    for (Node_ab2630* node = head->mpNext; node != head; node = node->mpNext) {
        Holder_ab2630* holder = static_cast<Holder_ab2630*>(node->mpOccupant->GetPropertyHolder());
        uint32_t c;
        uint32_t a;
        uint32_t b;
        if (Fn005fd480_ab2630(holder, 0x08fd1613, &a) && Fn005fd480_ab2630(holder, 0x48ebd0b1, &b)
            && Fn005fd480_ab2630(holder, 0x88ecf76c, &c)) {
            holder->SetValue(0x27812852, c * a / b, false);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e4100 score 111
void cSC4PollutionSimulator::Fn006e4100(void* listObject)
{
    List_ab2630* list = static_cast<List_ab2630*>(listObject);
    Node_ab2630* head = list->mpHead;
    for (Node_ab2630* node = head->mpNext; node != head; node = node->mpNext) {
        void* holder = node->mpOccupant->GetPropertyHolder();
        int64_t cost = 0;
        if (CalcOccupantMaintenanceCost(node->mpOccupant, &cost)) {
            Record_ab2630 record;
            record.mnId = 0;
            if (gpB43d64_ab2630->FindLineItem(holder, 0xca58edc7, &record) && cost != record.mnCost) {
                Department_ab2630* department = gpB43d64_ab2630->DepartmentFor(&record);
                if (department) {
                    department->AddCost(cost - record.mnCost);
                    gpB43d64_ab2630->SetLineItem(holder, record.mnId, cost);
                }
            }
        }
    }
}
#endif
