#include "classes/cSC4ResidentialSimulator.h"
#include <cstddef>
#include "common/compiler.h"

// A field of this object by its offset (the class header has the bytes unnamed).
#define FLD_rs(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

// A grid of the simulator (cISC4SimGrid): only the slots used here are named.
struct Grid_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t AddRef();
    virtual uint32_t Pad02_rs();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual uint32_t Pad05_rs();
    virtual uint32_t Pad06_rs();
    virtual uint32_t Pad07_rs();
    virtual uint32_t Pad08_rs();
    virtual uint32_t Pad09_rs();
    virtual uint32_t GetSize();
    virtual uint32_t Pad11_rs();
    virtual uint32_t Pad12_rs();
    virtual uint32_t Pad13_rs();
    virtual uint32_t Pad14_rs();
    virtual uint32_t Pad15_rs();
    virtual uint32_t Pad16_rs();
    virtual uint32_t Pad17_rs();
    virtual uint32_t Pad18_rs();
    virtual uint32_t Pad19_rs();
    virtual uint32_t Pad20_rs();
    virtual uint32_t Pad21_rs();
    virtual uint16_t GetValue(uint32_t x, uint32_t y);
};

// The pollution simulator (SL::spPollutionSim).
struct PollSim_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Pad02_rs();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual uint32_t Pad05_rs();
    virtual uint16_t GetValue(uint32_t type, uint32_t x, uint32_t y);
};

// A lot manager lookup result and the manager (SL::spLotManager).
struct LotPos_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Pad02_rs();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual uint32_t Pad05_rs();
    virtual uint32_t Pad06_rs();
    virtual uint32_t Pad07_rs();
    virtual uint32_t Pad08_rs();
    virtual uint32_t Pad09_rs();
    virtual uint32_t Pad10_rs();
    virtual uint32_t Pad11_rs();
    virtual uint32_t Pad12_rs();
    virtual uint32_t Pad13_rs();
    virtual uint32_t Pad14_rs();
    virtual void GetPosition(float* out);
};

struct LotMgr_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Pad02_rs();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual uint32_t Pad05_rs();
    virtual uint32_t Pad06_rs();
    virtual uint32_t Pad07_rs();
    virtual uint32_t Pad08_rs();
    virtual uint32_t Pad09_rs();
    virtual uint32_t Pad10_rs();
    virtual uint32_t Pad11_rs();
    virtual uint32_t Pad12_rs();
    virtual uint32_t Pad13_rs();
    virtual LotPos_rs* GetLotFor(void* occupant);
};

// An occupant (cISC4Occupant): slot 6 = its property holder, slot 8 = its position.
struct Occupant_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Pad02_rs();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual uint32_t Pad05_rs();
    virtual void* GetPropertyHolder();
    virtual uint32_t Pad07_rs();
    virtual void GetPosition(float* out);
};

// GLOBAL: 0x00b43d08
extern LotMgr_rs* gpB43d08_rs;
// GLOBAL: 0x00b43d9c
extern PollSim_rs* gpB43d9c_rs;

// STUB: 0x005fd390
void GetPropBool_rs(void* holder, uint32_t id, bool* out);
// STUB: 0x005fe210
void SetPropBool_rs(void* holder, uint32_t id, bool value);
// STUB: 0x005e5200
void GetTractsInRadius_rs(float x, float y, float radius, float p4, uint32_t p5, uint32_t p6, void* list);


// The city-side object at +0x18: slot 50 leads to the clock whose slot 7 gives the date holder.
struct Clock2_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Pad02_rs();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual uint32_t Pad05_rs();
    virtual uint32_t Pad06_rs();
    virtual uint32_t Pad07_rs();
    virtual uint32_t Pad08_rs();
    virtual uint32_t Pad09_rs();
    virtual uint32_t Pad10_rs();
    virtual uint32_t Pad11_rs();
    virtual uint32_t Pad12_rs();
    virtual uint32_t Pad13_rs();
    virtual uint32_t Pad14_rs();
    virtual uint32_t Pad15_rs();
    virtual uint32_t Pad16_rs();
    virtual uint32_t Pad17_rs();
    virtual uint32_t Pad18_rs();
    virtual uint32_t Pad19_rs();
    virtual uint32_t Pad20_rs();
    virtual uint32_t Pad21_rs();
    virtual uint32_t Pad22_rs();
    virtual uint32_t Pad23_rs();
    virtual uint32_t Pad24_rs();
    virtual uint32_t Pad25_rs();
    virtual uint32_t GetDay();
};
struct Clock1_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Pad02_rs();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual uint32_t Pad05_rs();
    virtual uint32_t Pad06_rs();
    virtual Clock2_rs* GetDate();
};
struct City_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Pad02_rs();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual uint32_t Pad05_rs();
    virtual uint32_t Pad06_rs();
    virtual uint32_t Pad07_rs();
    virtual uint32_t Pad08_rs();
    virtual uint32_t Pad09_rs();
    virtual uint32_t Pad10_rs();
    virtual uint32_t Pad11_rs();
    virtual uint32_t Pad12_rs();
    virtual uint32_t Pad13_rs();
    virtual uint32_t Pad14_rs();
    virtual uint32_t Pad15_rs();
    virtual uint32_t Pad16_rs();
    virtual uint32_t Pad17_rs();
    virtual uint32_t Pad18_rs();
    virtual uint32_t Pad19_rs();
    virtual uint32_t Pad20_rs();
    virtual uint32_t Pad21_rs();
    virtual uint32_t Pad22_rs();
    virtual uint32_t Pad23_rs();
    virtual uint32_t Pad24_rs();
    virtual uint32_t Pad25_rs();
    virtual uint32_t Pad26_rs();
    virtual uint32_t Pad27_rs();
    virtual uint32_t Pad28_rs();
    virtual uint32_t Pad29_rs();
    virtual uint32_t Pad30_rs();
    virtual uint32_t Pad31_rs();
    virtual uint32_t Pad32_rs();
    virtual uint32_t Pad33_rs();
    virtual uint32_t Pad34_rs();
    virtual uint32_t Pad35_rs();
    virtual uint32_t Pad36_rs();
    virtual uint32_t Pad37_rs();
    virtual uint32_t Pad38_rs();
    virtual uint32_t Pad39_rs();
    virtual uint32_t Pad40_rs();
    virtual uint32_t Pad41_rs();
    virtual uint32_t Pad42_rs();
    virtual uint32_t Pad43_rs();
    virtual uint32_t Pad44_rs();
    virtual uint32_t Pad45_rs();
    virtual uint32_t Pad46_rs();
    virtual uint32_t Pad47_rs();
    virtual uint32_t Pad48_rs();
    virtual uint32_t Pad49_rs();
    virtual Clock1_rs* GetClock();
};

// The 0x2c-byte message object (vtable 0x00acec00) and the message server (SL::spMS2).
// STUB: 0x009133da
void* Fn009133da(uint32_t size);
struct MsgBase_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual void SetType(uint32_t);
    virtual uint32_t Pad06_rs();
    virtual uint32_t Pad07_rs();
    virtual uint32_t Pad08_rs();
    virtual uint32_t Pad09_rs();
    virtual uint32_t Pad10_rs();
    virtual uint32_t Pad11_rs();
    virtual void SetData3(uint32_t);
    virtual uint32_t Pad13_rs();
    virtual uint32_t Pad14_rs();
    virtual uint32_t Pad15_rs();
    virtual void SetData1(uint32_t);
    virtual uint32_t Pad17_rs();
    virtual uint32_t Pad18_rs();
    virtual uint32_t Pad19_rs();
    virtual uint32_t Pad20_rs();
    virtual void SetData2(uint32_t);
    virtual uint32_t Pad22_rs();
    virtual uint32_t Pad23_rs();
    virtual uint32_t Pad24_rs();
    virtual uint32_t Pad25_rs();
    virtual uint32_t Pad26_rs();
    virtual uint32_t Pad27_rs();
    virtual uint32_t Pad28_rs();
    virtual uint32_t Pad29_rs();
    virtual uint32_t Pad30_rs();
    virtual uint32_t Pad31_rs();
    virtual uint32_t Pad32_rs();
    virtual void SetData4(uint32_t);
};

struct Rm_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Pad02_rs();
    virtual bool Find(void* id, uint32_t type, void** out, uint32_t a, uint32_t b);
};

struct Holder_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Release();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual uint32_t Pad05_rs();
    virtual uint32_t Pad06_rs();
    virtual void* GetProperties();
};

// GLOBAL: 0x00b43ca8
extern Rm_rs* gpB43ca8_rs;

// STUB: 0x005fd3c0
void GetPropUint8_rs(void* holder, uint32_t id, uint8_t* out);

struct Svc_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Pad02_rs();
    virtual uint32_t Pad03_rs();
    virtual uint32_t Pad04_rs();
    virtual uint32_t Pad05_rs();
    virtual uint32_t Pad06_rs();
    virtual uint32_t Pad07_rs();
    virtual uint32_t Pad08_rs();
    virtual uint32_t Pad09_rs();
    virtual uint32_t Pad10_rs();
    virtual uint32_t Pad11_rs();
    virtual uint32_t Pad12_rs();
    virtual uint32_t Pad13_rs();
    virtual uint32_t Pad14_rs();
    virtual uint32_t Pad15_rs();
    virtual uint32_t Pad16_rs();
    virtual uint32_t Pad17_rs();
    virtual uint32_t Pad18_rs();
    virtual uint32_t Pad19_rs();
    virtual uint32_t Pad20_rs();
    virtual uint32_t Pad21_rs();
    virtual uint32_t Pad22_rs();
    virtual uint32_t Pad23_rs();
    virtual uint32_t Pad24_rs();
    virtual uint32_t Pad25_rs();
    virtual uint32_t Pad26_rs();
    virtual uint32_t Pad27_rs();
    virtual uint32_t Pad28_rs();
    virtual uint32_t Pad29_rs();
    virtual uint32_t Pad30_rs();
    virtual uint32_t Pad31_rs();
    virtual uint32_t Pad32_rs();
    virtual uint32_t Pad33_rs();
    virtual uint32_t Pad34_rs();
    virtual uint32_t Pad35_rs();
    virtual uint32_t Pad36_rs();
    virtual uint32_t Pad37_rs();
    virtual uint32_t Pad38_rs();
    virtual uint32_t Pad39_rs();
    virtual uint32_t Pad40_rs();
    virtual uint32_t Pad41_rs();
    virtual uint32_t Pad42_rs();
    virtual uint32_t Pad43_rs();
    virtual uint32_t Pad44_rs();
    virtual uint32_t Pad45_rs();
    virtual uint32_t Pad46_rs();
    virtual uint32_t Pad47_rs();
    virtual uint32_t Pad48_rs();
    virtual uint32_t Pad49_rs();
    virtual uint32_t Pad50_rs();
    virtual bool GetProperty(void* holder, uint32_t id, void* out);
};

// A response curve (cSC4ResponseCurve) of the simulator.
struct Curve_rs {
    uint8_t mData[0x20];
    // STUB: 0x005f4250
    float GetOutputValue(float input) const;
};

// GLOBAL: 0x00b0d440
extern uint32_t gB0d440_rs;

struct Msg_rs : public MsgBase_rs {
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    Msg_rs();
    static void* operator new(size_t size) { return Fn009133da(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct Ms2_rs {
    virtual uint32_t Pad00_rs();
    virtual uint32_t Pad01_rs();
    virtual uint32_t Pad02_rs();
    virtual uint32_t Pad03_rs();
    virtual void Send(void* message, uint32_t flags);
};

// GLOBAL: 0x00b43ccc
extern Ms2_rs* gpB43ccc_rs;

// An element of a vector the original fills and copies (a 4-byte object with a copy-assign at 0x006e5660).
struct Elem_rs {
    uint32_t mValue;
    // STUB: 0x006e5660
    void Assign(const Elem_rs* other);
};

// A node of the circular lists the simulator keeps: next, previous, then the payload.
struct Node_rs {
    Node_rs* mpNext;
    Node_rs* mpPrev;
    uint32_t mValue;
};

// An ilist (the head node) and the vectors of them.
struct IList_rs {
    Node_rs* mpHead;
};
struct IListVec_rs {
    IList_rs** mpBegin;
    IList_rs** mpEnd;
};

#ifdef OB_DRAFTS
// CLOSE: 0x006f6f10 score 5
bool cSC4ResidentialSimulator::SchoolIsOnStrike()
{
    return FLD_rs(bool, 0x178) != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006f6f20 score 5
bool cSC4ResidentialSimulator::HealthIsOnStrike()
{
    return FLD_rs(bool, 0x118) != 0;
}
#endif

// FUNCTION: 0x006f6f80
void Fn006f6f80(bool* p, bool value)
{
    *p = value;
}

// FUNCTION: 0x006f6f90
uint32_t cSC4ResidentialSimulator::Slot05_ab2c10(uint32_t index)
{
    switch (index) {
    case 1:
        return FLD_rs(uint32_t, 0x38);
    case 2:
        return FLD_rs(uint32_t, 0x3c);
    case 3:
        return FLD_rs(uint32_t, 0x40);
    }
    return 0;
}

// FUNCTION: 0x006f72c0
void cSC4ResidentialSimulator::GetEQGrids(uint32_t a, uint32_t b, uint32_t c)
{
    Grid_rs** pa = OB_PTR(Grid_rs*, a);
    Grid_rs** pb = OB_PTR(Grid_rs*, b);
    Grid_rs** pc = OB_PTR(Grid_rs*, c);
    *pa = FLD_rs(Grid_rs*, 0x7c);
    *pb = FLD_rs(Grid_rs*, 0x80);
    *pc = FLD_rs(Grid_rs*, 0x84);
    (*pa)->AddRef();
    (*pb)->AddRef();
    (*pc)->AddRef();
}

// FUNCTION: 0x006f7300
void cSC4ResidentialSimulator::GetHQGrids(uint32_t a, uint32_t b, uint32_t c)
{
    Grid_rs** pa = OB_PTR(Grid_rs*, a);
    Grid_rs** pb = OB_PTR(Grid_rs*, b);
    Grid_rs** pc = OB_PTR(Grid_rs*, c);
    *pa = FLD_rs(Grid_rs*, 0x88);
    *pb = FLD_rs(Grid_rs*, 0x8c);
    *pc = FLD_rs(Grid_rs*, 0x90);
    (*pa)->AddRef();
    (*pb)->AddRef();
    (*pc)->AddRef();
}

// FUNCTION: 0x006f7340
void cSC4ResidentialSimulator::GetPopulationGrids(uint32_t a, uint32_t b, uint32_t c)
{
    Grid_rs** pa = OB_PTR(Grid_rs*, a);
    Grid_rs** pb = OB_PTR(Grid_rs*, b);
    Grid_rs** pc = OB_PTR(Grid_rs*, c);
    *pa = FLD_rs(Grid_rs*, 0x48);
    *pb = FLD_rs(Grid_rs*, 0x4c);
    *pc = FLD_rs(Grid_rs*, 0x50);
    (*pa)->AddRef();
    (*pb)->AddRef();
    (*pc)->AddRef();
}

#ifdef OB_DRAFTS
// CLOSE: 0x006f79c0 score 20
float cSC4ResidentialSimulator::GetCellEQ(uint32_t x, uint32_t y)
{
    Grid_rs* grid = FLD_rs(Grid_rs*, 0x7c);
    return GetTractQuotient(&FLD_rs(Grid_rs*, 0x7c), &FLD_rs(Grid_rs*, 0x48), x / grid->GetSize(), y / grid->GetSize());
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006f7a10 score 20
float cSC4ResidentialSimulator::GetCellHQ(uint32_t x, uint32_t y)
{
    Grid_rs* grid = FLD_rs(Grid_rs*, 0x88);
    return GetTractQuotient(&FLD_rs(Grid_rs*, 0x88), &FLD_rs(Grid_rs*, 0x48), x / grid->GetSize(), y / grid->GetSize());
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006f7a60 score 8
void cSC4ResidentialSimulator::Slot37_ab2c10(uint32_t x, uint32_t y, uint32_t wealth)
{
    uint32_t b = y / FLD_rs(Grid_rs*, 0x7c)->GetSize();
    uint32_t a = x / FLD_rs(Grid_rs*, 0x7c)->GetSize();
    (&FLD_rs(Grid_rs*, 0x7c))[static_cast<uint8_t>(wealth - 1)]->GetValue(a, b);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006f7ab0 score 8
void cSC4ResidentialSimulator::Slot38_ab2c10(uint32_t x, uint32_t y, uint32_t wealth)
{
    uint32_t b = y / FLD_rs(Grid_rs*, 0x88)->GetSize();
    uint32_t a = x / FLD_rs(Grid_rs*, 0x88)->GetSize();
    (&FLD_rs(Grid_rs*, 0x88))[static_cast<uint8_t>(wealth - 1)]->GetValue(a, b);
}
#endif

// FUNCTION: 0x006f7d70
bool cSC4ResidentialSimulator::GetAutoBudget(uint32_t occupant)
{
    bool value = false;
    GetPropBool_rs(OB_PTR(Occupant_rs, occupant)->GetPropertyHolder(), 0x6c05fc4d, &value);
    return value;
}

// FUNCTION: 0x006f7da0
void cSC4ResidentialSimulator::SetAutoBudget(uint32_t occupant, uint32_t value)
{
    SetPropBool_rs(OB_PTR(Occupant_rs, occupant)->GetPropertyHolder(), 0x6c05fc4d, *reinterpret_cast<bool*>(&value));
}

// FUNCTION: 0x006f7dd0
uint32_t cSC4ResidentialSimulator::Init()
{
    if (FLD_rs(int32_t, 0x10) > 1) {
        FLD_rs(int32_t, 0x10) = FLD_rs(int32_t, 0x10) - 1;
        return FLD_rs(int32_t, 0x10);
    }
    Slot04_ab2c10();
    delete this;
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006f7e00 score 2
void cSC4ResidentialSimulator::GetCoveredTractList(void* occupant, float a, float b, uint32_t c, uint32_t d, void* list)
{
    float pos[3];
    LotPos_rs* lot = gpB43d08_rs->GetLotFor(occupant);
    if (lot) {
        lot->GetPosition(pos);
    } else {
        OB_PTR(Occupant_rs, OB_ADDR(occupant))->GetPosition(pos);
    }
    GetTractsInRadius_rs(pos[0], pos[1], a * FLD_rs(float, 0x324), b, c, d, list);
}
#endif

// FUNCTION: 0x006f7ff0
uint32_t cSC4ResidentialSimulator::GetPollutionTractValue(uint32_t type, uint32_t x, uint32_t y, uint32_t size)
{
    PollSim_rs* sim = gpB43d9c_rs;
    uint32_t sum = 0;
    for (uint32_t i = x; i < x + size; i++) {
        for (uint32_t j = y; j < y + size; j++) {
            sum += sim->GetValue(type, i, j);
        }
    }
    return sum / (size * size);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006f6fc0 score 140
float cSC4ResidentialSimulator::GetTractQuotient(void* quotients, void* populations, uint32_t x, uint32_t y)
{
    Grid_rs** q = static_cast<Grid_rs**>(quotients);
    Grid_rs** p = static_cast<Grid_rs**>(populations);
    uint16_t total = p[0]->GetValue(x, y) + p[1]->GetValue(x, y) + p[2]->GetValue(x, y);
    if (total == 0) {
        return 0.0f;
    }
    float a = q[0]->GetValue(x, y);
    float pa = p[0]->GetValue(x, y);
    float b = q[1]->GetValue(x, y);
    float pb = p[1]->GetValue(x, y);
    float c = q[2]->GetValue(x, y);
    float pc = p[2]->GetValue(x, y);
    return (pa * a + pb * b + pc * c) / total;
}
#endif

// FUNCTION: 0x006f8570
bool cSC4ResidentialSimulator::EndStrike(void* department, uint32_t date)
{
    uint8_t* dept = static_cast<uint8_t*>(department);
    if (dept[0x44]) {
        dept[0x44] = 0;
        *reinterpret_cast<uint32_t*>(dept + 0x48) = 0;
        Msg_rs* msg = new Msg_rs();
        msg->AddRef();
        msg->SetType(*reinterpret_cast<uint32_t*>(dept + 0x5c));
        Ms2_rs* ms = gpB43ccc_rs;
        msg->SetData1(0);
        msg->SetData2(date);
        ms->Send(msg, 0);
        msg->Release();
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006f9340 score 4
void cSC4ResidentialSimulator::GetOrdinanceModifiers(void* occupant, void* effects, void* a, void* b, void* c)
{
    Node_rs* head = *static_cast<Node_rs**>(effects);
    Node_rs* node = head->mpNext;
    float* pa = static_cast<float*>(a);
    float* pb = static_cast<float*>(b);
    float* pc = static_cast<float*>(c);
    *pa = 1.0f;
    *pc = 1.0f;
    *pb = 1.0f;
    for (; node != head; node = node->mpNext) {
        *pa = *reinterpret_cast<float*>(reinterpret_cast<char*>(node) + 8) * *pa;
        *pb = *pb * *reinterpret_cast<float*>(reinterpret_cast<char*>(node) + 0x20);
        *pc = *pc * *reinterpret_cast<float*>(reinterpret_cast<char*>(node) + 0x1c);
    }
}
#endif

// FUNCTION: 0x006f9470
bool cSC4ResidentialSimulator::EndSchoolStrike()
{
    if (SchoolIsOnStrike()) {
        uint32_t day = FLD_rs(City_rs*, 0x18)->GetClock()->GetDate()->GetDay();
        return EndStrike(&FLD_rs(uint8_t, 0x134), day - FLD_rs(uint32_t, 0x17c));
    }
    return false;
}

// FUNCTION: 0x006f94b0
bool cSC4ResidentialSimulator::EndHealthStrike()
{
    if (HealthIsOnStrike()) {
        uint32_t day = FLD_rs(City_rs*, 0x18)->GetClock()->GetDate()->GetDay();
        return EndStrike(&FLD_rs(uint8_t, 0xd4), day - FLD_rs(uint32_t, 0x11c));
    }
    return false;
}

// FUNCTION: 0x006fa240
void cSC4ResidentialSimulator::GetSchoolSystemTotals(uint32_t data, uint32_t list)
{
    GetSystemTotals(&FLD_rs(uint8_t, 0x1a8), OB_PTR(void, data), true, OB_PTR(void, list));
}

// FUNCTION: 0x006fa260
void cSC4ResidentialSimulator::GetHospitalSystemTotals(uint32_t data, uint32_t list)
{
    GetSystemTotals(&FLD_rs(uint8_t, 0x1b4), OB_PTR(void, data), false, OB_PTR(void, list));
}

#ifdef OB_DRAFTS
// CLOSE: 0x006f9590 score 31
uint32_t cSC4ResidentialSimulator::GetSchoolBuildingCount()
{
    uint32_t total = 0;
    uint32_t i = 0;
    while (i < static_cast<uint32_t>(FLD_rs(IList_rs**, 0x1ac) - FLD_rs(IList_rs**, 0x1a8))) {
        uint32_t n = 0;
        Node_rs* head = FLD_rs(IList_rs**, 0x1a8)[i]->mpHead;
        for (Node_rs* p = head->mpNext; p != head; p = p->mpNext) {
            n++;
        }
        total += n;
        i++;
    }
    uint32_t n = 0;
    Node_rs* head = FLD_rs(IList_rs*, 0x19c)->mpHead;
    for (Node_rs* p = head->mpNext; p != head; p = p->mpNext) {
        n++;
    }
    return n + total;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006f9600 score 31
uint32_t cSC4ResidentialSimulator::GetHospitalBuildingCount()
{
    uint32_t total = 0;
    uint32_t i = 0;
    while (i < static_cast<uint32_t>(FLD_rs(IList_rs**, 0x1b8) - FLD_rs(IList_rs**, 0x1b4))) {
        uint32_t n = 0;
        Node_rs* head = FLD_rs(IList_rs**, 0x1b4)[i]->mpHead;
        for (Node_rs* p = head->mpNext; p != head; p = p->mpNext) {
            n++;
        }
        total += n;
        i++;
    }
    uint32_t n = 0;
    Node_rs* head = FLD_rs(IList_rs*, 0x1a0)->mpHead;
    for (Node_rs* p = head->mpNext; p != head; p = p->mpNext) {
        n++;
    }
    return n + total;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006fade0 score 28
void cSC4ResidentialSimulator::GetSchoolBuildings(uint32_t list, uint32_t filter)
{
    uint32_t i = 0;
    while (i < static_cast<uint32_t>(FLD_rs(IList_rs**, 0x1ac) - FLD_rs(IList_rs**, 0x1a8))) {
        GetBuildings(FLD_rs(IList_rs**, 0x1a8) + i, list, filter);
        i++;
    }
    GetBuildings(&FLD_rs(IList_rs*, 0x19c), list, filter);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006fae50 score 28
void cSC4ResidentialSimulator::GetHospitalBuildings(uint32_t list, uint32_t filter)
{
    uint32_t i = 0;
    while (i < static_cast<uint32_t>(FLD_rs(IList_rs**, 0x1b8) - FLD_rs(IList_rs**, 0x1b4))) {
        GetBuildings(FLD_rs(IList_rs**, 0x1b4) + i, list, filter);
        i++;
    }
    GetBuildings(&FLD_rs(IList_rs*, 0x1a0), list, filter);
}
#endif

// FUNCTION: 0x006fcc50
void Fn006fcc50(Elem_rs* first, Elem_rs* last, Elem_rs* value)
{
    for (; first != last; first++) {
        first->Assign(value);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x006fcc80 score 33
Elem_rs* Fn006fcc80(Elem_rs* first, Elem_rs* last, Elem_rs* dest)
{
    int32_t n = last - first;
    if (n > 0) {
        do {
            dest->Assign(first);
            first++;
            dest++;
            n--;
        } while (n != 0);
        return dest;
    }
    return dest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006fba70 score 27
Elem_rs* Fn006fba70(Elem_rs* first, Elem_rs* last, Elem_rs* dest)
{
    int32_t n = last - first;
    if (n > 0) {
        do {
            last--;
            dest--;
            dest->Assign(last);
            n--;
        } while (n != 0);
        return dest;
    }
    return dest;
}
#endif

// FUNCTION: 0x006f84c0
bool cSC4ResidentialSimulator::StartStrike(void* department, uint32_t amount)
{
    uint8_t* dept = static_cast<uint8_t*>(department);
    if (!dept[0x44]) {
        dept[0x44] = 1;
        *reinterpret_cast<uint32_t*>(dept + 0x48) = FLD_rs(City_rs*, 0x18)->GetClock()->GetDate()->GetDay();
        Msg_rs* msg = new Msg_rs();
        msg->AddRef();
        msg->SetType(*reinterpret_cast<uint32_t*>(dept + 0x5c));
        msg->SetData3(amount);
        msg->SetData4(amount);
        Ms2_rs* ms = gpB43ccc_rs;
        msg->SetData1(1);
        ms->Send(msg, 0);
        msg->Release();
        return true;
    }
    return false;
}

// FUNCTION: 0x006f88b0
bool cSC4ResidentialSimulator::Slot42_ab2c10(uint32_t wealth)
{
    uint8_t values[3];
    uint32_t id[3];
    Holder_rs* holder;
    values[0] = 0x19;
    values[1] = 0x1e;
    values[2] = 0x19;
    id[0] = 0x6534284a;
    id[1] = 0xe7e2c2db;
    id[2] = 0x69189c84;
    uint8_t index = static_cast<uint8_t>(wealth) - 1;
    if (gpB43ca8_rs->Find(id, 0xa52160f5, reinterpret_cast<void**>(&holder), 0, 0)) {
        void* props = holder->GetProperties();
        GetPropUint8_rs(props, 0xc929c652, &values[0]);
        GetPropUint8_rs(props, 0x929cc30, &values[1]);
        GetPropUint8_rs(props, 0x929cc36, &values[2]);
        holder->Release();
        return *reinterpret_cast<bool*>(&values[index]);
    }
    return *reinterpret_cast<bool*>(&values[index]);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006f8710 score 55
void cSC4ResidentialSimulator::GetOccupantEfficiencyRatings(void* occupant, void* outA, void* outB, bool useActual, bool ignoreStrike)
{
    uint32_t* pa = static_cast<uint32_t*>(outA);
    uint32_t* pb = static_cast<uint32_t*>(outB);
    *pa = gB0d440_rs;
    *pb = gB0d440_rs;
    float effA = 0.0f;
    float effB = 0.0f;
    uint8_t scratch[0x18];
    Slot20_ab2c10(occupant, &effA, &effB, useActual);
    if (useActual) {
        if (FLD_rs(Svc_rs*, 0xd0)->GetProperty(OB_PTR(Occupant_rs, OB_ADDR(occupant))->GetPropertyHolder(), 0xea5654b6, scratch)) {
            float rate;
            if (ignoreStrike || !IsBuildingOnStrike(occupant)) {
                rate = FLD_rs(Curve_rs, 0x148).GetOutputValue(effA * 100.0f) * 0.01f;
            } else {
                rate = effA * FLD_rs(float, 0x13c);
            }
            *reinterpret_cast<float*>(pa) = rate;
            *reinterpret_cast<float*>(pb) = FLD_rs(Curve_rs, 0x168).GetOutputValue(effB * 100.0f) * 0.01f;
        }
    } else {
        if (FLD_rs(Svc_rs*, 0xd0)->GetProperty(OB_PTR(Occupant_rs, OB_ADDR(occupant))->GetPropertyHolder(), 0xca565486, scratch)) {
            float rate;
            if (ignoreStrike || !IsBuildingOnStrike(occupant)) {
                rate = FLD_rs(Curve_rs, 0xe8).GetOutputValue(effA * 100.0f) * 0.01f;
            } else {
                rate = effA * FLD_rs(float, 0xdc);
            }
            *reinterpret_cast<float*>(pa) = rate;
            *reinterpret_cast<float*>(pb) = FLD_rs(Curve_rs, 0x108).GetOutputValue(effB * 100.0f) * 0.01f;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006f85f0 score 65
void cSC4ResidentialSimulator::GetOccupantEfficiency(void* out, void* occupant, bool useActual)
{
    float effA = 0.0f;
    float effB = 0.0f;
    uint8_t scratch[0x18];
    Slot20_ab2c10(occupant, &effA, &effB, useActual);
    if (useActual) {
        if (FLD_rs(Svc_rs*, 0xd0)->GetProperty(OB_PTR(Occupant_rs, OB_ADDR(occupant))->GetPropertyHolder(), 0xea5654b6, scratch)) {
            *static_cast<float*>(out) = FLD_rs(Curve_rs, 0x148).GetOutputValue(effA * 100.0f) * 0.01f;
            return;
        }
    } else {
        if (FLD_rs(Svc_rs*, 0xd0)->GetProperty(OB_PTR(Occupant_rs, OB_ADDR(occupant))->GetPropertyHolder(), 0xca565486, scratch)) {
            *static_cast<float*>(out) = FLD_rs(Curve_rs, 0xe8).GetOutputValue(effA * 100.0f) * 0.01f;
            return;
        }
    }
    *static_cast<float*>(out) = effA;
}
#endif
