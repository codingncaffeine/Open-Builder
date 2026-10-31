#include "classes/cSC4LotDeveloper.h"
#include <cfloat>
#include <cmath>
#include "common/compiler.h"

// Views of the interfaces this file calls through (slots by their real names).
struct Lot_ab1b98 {
    virtual bool QueryInterface(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void* AsPropertyHolder();  // return type from the reference build
    virtual uint32_t AsTrafficSource();
    virtual bool Init();
    virtual bool IsInitialized();
    virtual bool Shutdown();
    virtual void PostCityInit();  // return type from the reference build
    virtual void* GetLotConfiguration();
    virtual void SetLotConfiguration(void*);  // return type from the reference build
    virtual uint32_t GetLotConfigurationObject(void*);
    virtual uint32_t GetFlags();
    virtual void SetFlags(int32_t);
    virtual void GetBoundingRect(void*);
    virtual void GetCenter(void*);
    virtual float GetAltitude();
    virtual void SetAltitude(float);
    virtual float GetSlope();
    virtual float GetSlopeAtTimeOfConstruction();
    virtual void UpdateSlope();
    virtual void GetLocation(void*, void*);
    virtual void GetSize(void*, void*);
    virtual int32_t GetFacing();
    virtual void SetFacing(int32_t);
    virtual void* GetUnit();
    virtual void SetUnit(void*);  // return type from the reference build
    virtual bool HasJobAccess();
    virtual bool HasRoadAccess();  // return type from the reference build
    virtual uint32_t HasOrganicRoadAccess();  // return type unknown; arguments unknown
    virtual void UpdateRoadAccess();
    virtual uint32_t GetZoneType();
    virtual void UpdateZoneType();
    virtual uint32_t GetState();
    virtual void SetState(uint32_t, uint32_t, uint32_t);
    virtual uint32_t GetCondition();
    virtual void SetCondition(uint32_t);
    virtual bool IsInLivableState();
    virtual uint32_t HasCapacity();
    virtual uint32_t IsInDemolishableState();
    virtual uint32_t GetDaysSinceLastStateChange();
    virtual uint32_t GetOccupantWealth();
    virtual uint32_t GetLandValue();  // return type unknown
    virtual bool IsHistorical();
    virtual void SetHistorical(bool);
    virtual uint32_t GetVacateReason();
    virtual uint32_t GetBuildingType(bool);  // return type from the reference build
    virtual void SetBuildingType(uint32_t);
    virtual uint32_t GetBuilding();
    virtual void GetLotOccupants(void*);  // return type from the reference build
    virtual uint32_t GetCapacity1();  // arguments unknown
    virtual uint32_t GetCapacity2();  // return type unknown; arguments unknown
    virtual uint32_t GetAvailableCapacity(uint32_t, uint32_t);
    virtual uint32_t GetPopulation();  // return type unknown; arguments unknown
    virtual uint32_t GetPopulations();
    virtual bool SetPopulation(uint32_t, uint32_t);
    virtual uint32_t GetTravelPopulation();  // arguments unknown
    virtual void ResetTravelPopulation();  // return type from the reference build
    virtual void AddTravelPopulation(void*);  // return type from the reference build
    virtual uint32_t GetTravelDesignate();
    virtual void SetTravelDesignate(void*);  // return type from the reference build
    virtual void GetOccupancy();
    virtual void GetOccupancyByType();  // return type from the reference build; arguments unknown
    virtual float GetTravelJobs();  // arguments unknown
    virtual void GetJobs(void*);
    virtual bool GetNeedsPower();
    virtual bool GetHasPower();
    virtual void SetHasPower(bool);
    virtual bool GetVerticesAreLocked();
    virtual void SetVerticesAreLocked(bool);
};

struct Occ_ab1b98 {
    virtual bool QueryInterface(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual uint32_t Init();  // return type unknown; arguments unknown
    virtual uint32_t Shutdown();  // return type unknown; arguments unknown
    virtual uint32_t IsInitialized();  // return type unknown; arguments unknown
    virtual void* AsPropertyHolder();
    virtual uint32_t GetType();  // return type unknown; arguments unknown
    virtual void GetPosition(void*);
    virtual uint32_t SetPosition();  // return type unknown; arguments unknown
    virtual void GetBoundingBox(void*, void*);
    virtual uint32_t GetBoundingCityCells();  // return type unknown; arguments unknown
    virtual uint32_t SetRemovalFlags();  // return type unknown; arguments unknown
    virtual uint32_t UnsetRemovalFlags();  // return type unknown; arguments unknown
    virtual uint32_t CanRemove();  // return type unknown; arguments unknown
    virtual uint32_t PostOccupantMessage();  // return type unknown; arguments unknown
    virtual uint32_t GetHighlight();  // return type unknown; arguments unknown
    virtual uint32_t SetHighlight();  // return type unknown; arguments unknown
    virtual uint32_t SetVisibility();  // return type unknown; arguments unknown
    virtual uint32_t GetPlaceableObject();  // return type unknown; arguments unknown
    virtual uint32_t GetOrCreatePlaceableObject();  // return type unknown; arguments unknown
    virtual uint32_t SetPlaceableObject();  // return type unknown; arguments unknown
    virtual uint32_t IsOccupantGroup();  // return type unknown; arguments unknown
    virtual uint32_t AddOccupantGroup();  // return type unknown; arguments unknown
    virtual uint32_t GetOccupantGroups();  // return type unknown; arguments unknown
    virtual uint32_t GetOccupantManagerBBox();  // return type unknown; arguments unknown
    virtual uint32_t SetOccupantManagerBBox();  // return type unknown; arguments unknown
    virtual uint32_t GetLotTag();  // return type unknown; arguments unknown
    virtual uint32_t SetLotTag();  // return type unknown; arguments unknown
    virtual uint32_t SetFlag();  // return type unknown; arguments unknown
    virtual uint32_t SetAllFlags();  // return type unknown; arguments unknown
    virtual uint32_t ClearFlag();  // return type unknown; arguments unknown
    virtual uint32_t IsFlagSet();  // return type unknown; arguments unknown
    virtual uint32_t GetFlags();  // return type unknown; arguments unknown
};

struct Unit_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void RemoveLot(void*);
};


// Views of objects reached through fields (slots by index; the unnamed ones are padding).
struct Demo_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual uint32_t Level(int32_t, bool, int32_t, int32_t, int32_t, int32_t, float, void*, int32_t, int32_t);
};
struct ConfData_ab1b98 {
    uint8_t mPad[0x20];
    uint32_t mnId;
    uint32_t mnPad24;
    uint32_t* mpBegin;
    uint32_t* mpEnd;
};

struct ConfObj_ab1b98 {
    uint8_t mPad[0x24];
    uint32_t mn24;
    uint8_t mTail[0x34 - 0x28];
};
struct ConfVec_ab1b98 {
    ConfObj_ab1b98* mpBegin;
    ConfObj_ab1b98* mpEnd;
};
struct Conf_ab1b98 {
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
    virtual ConfVec_ab1b98* GetObjects();
    virtual ConfData_ab1b98* GetObject();
    virtual void P25();
    virtual ConfData_ab1b98* GetObject2();
};
struct TexOcc_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual uint32_t Release();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void Update(int32_t, bool, int32_t);
};
struct PropObj_ab1b98 {
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
    virtual void SetValue(uint32_t);
};
struct PropMgr_ab1b98 {
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
    virtual PropObj_ab1b98* CreateProp(uint32_t, void*, uint32_t);
    virtual void P27();
    virtual void RemoveLotProps(void*);
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
    virtual void RemoveBuildingProps(void*);
};
struct PH_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void* GetHolder();
    virtual void P7();
    virtual void P8();
    virtual void* Query(uint32_t);
};
struct PHItem_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void* Get();
};
struct PHTarget_ab1b98 {
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
    virtual void Fn(uint32_t);
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
    virtual void P39();
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual void P48();
    virtual void P49();
    virtual void P50();
    virtual void P51();
    virtual void P52();
    virtual void P53();
    virtual void P54();
    virtual void P55();
    virtual void P56();
    virtual void P57();
    virtual void P58();
    virtual void P59();
    virtual void P60();
    virtual void P61();
    virtual void P62();
    virtual void P63();
    virtual void P64();
    virtual void P65();
    virtual void P66();
    virtual void P67();
    virtual void P68();
    virtual void P69();
    virtual void P70();
    virtual void P71();
    virtual void P72();
    virtual uint32_t* GetIdSlot();
};
struct Terrain_ab1b98 {
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
    virtual float GetAltitude(int32_t);
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
    virtual float GetWaterAltitude(int32_t);
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual bool Fn37(int32_t, int32_t);
};
struct OccMgr_ab1b98 {
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
    virtual void Remove(void*, uint32_t, uint32_t);
};
struct Obj_ab1b98 {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void* Fn3();
    virtual uint32_t Fn4r();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual uint32_t Fn14();
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
    virtual bool Fn32(bool);
};

struct Iter_ab1b98 {
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
    void Fn006c5fe0(Iter_ab1b98* out);
};

struct Node_ab1b98 {
    uint32_t mColor;
    Node_ab1b98* mpParent;
    Node_ab1b98* mpLeft;
    Node_ab1b98* mpRight;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

struct Tree_ab1b98 {
    void Fn006c6080(Node_ab1b98* node);
};

struct PtrVec_ab1b98 {
    Obj_ab1b98** mpBegin;
    Obj_ab1b98** mpEnd;
    void Fn006c6e90();
};

struct ListNode_ab1b98 {
    ListNode_ab1b98* mpNext;
    ListNode_ab1b98* mpPrev;
    Obj_ab1b98* mpData;
};
struct List_ab1b98 {
    ListNode_ab1b98* mpHead;
};

struct LotMgr_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void* GetLot(int32_t, int32_t, int32_t);
    virtual void P7();
    virtual void P8();
    virtual uint32_t GetNearbyLots(void*, void*, uint32_t);
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
    virtual void Fn24(void*);
};
struct PropHolderItem_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual uint32_t P6x();
};

struct Curve_ab1b98 {
    // STUB: 0x005f4250
    float GetOutputValue(float value) const;
};


struct Deque_ab1b98 {
    void* mpCur;
    void* mpFirst;
    void* mpLast;
    void** mpStartNode;
    void* mpFinishCur;
    void* mpFinishFirst;
    void* mpFinishLast;
    void** mpFinishNode;
    void** mpMap;
    uint32_t mnMapSize;
    // STUB: 0x006db4a0
    void ReallocateMap(uint32_t nodes, bool atFront);
    void NewNodesAtFront(uint32_t n);
    void NewNodesAtBack(uint32_t n);
};

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);
// STUB: 0x005fd480
bool Fn005fd480(void* holder, uint32_t id, uint32_t* value);
// STUB: 0x005f98c0
void Fn005f98c0(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*);

struct Flora_ab1b98 {
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
    virtual void RemoveFlora(void*, int32_t);
};
struct City_ab1b98 {
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
    virtual void P39();
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual void P48();
    virtual void P49();
    virtual void P50();
    virtual void P51();
    virtual void P52();
    virtual void P53();
    virtual void P54();
    virtual void P55();
    virtual void P56();
    virtual void P57();
    virtual void P58();
    virtual void P59();
    virtual void P60();
    virtual void P61();
    virtual void P62();
    virtual void P63();
    virtual void P64();
    virtual void P65();
    virtual void P66();
    virtual void P67();
    virtual void P68();
    virtual void P69();
    virtual void P70();
    virtual void P71();
    virtual void P72();
    virtual void P73();
    virtual void P74();
    virtual void P75();
    virtual void P76();
    virtual void P77();
    virtual void P78();
    virtual void P79();
    virtual void P80();
    virtual void P81();
    virtual void P82();
    virtual void P83();
    virtual void P84();
    virtual void P85();
    virtual void P86();
    virtual void P87();
    virtual void P88();
    virtual void P89();
    virtual void P90();
    virtual void P91();
    virtual void P92();
    virtual void P93();
    virtual void P94();
    virtual void PositionToCell(float, float, int32_t*, int32_t*);
};

struct Random_ab1b98 {
    // STUB: 0x009136b1
    uint32_t Uniform(uint32_t limit);
};
// GLOBAL: 0x00b49af0
extern Random_ab1b98 g00b49af0;

struct RbNode_ab1b98 {
    uint8_t mPad[0x14];
    uint32_t mnTexture;
    uint8_t mb18;
    uint8_t mb19;
};
struct BoundaryMap_ab1b98 {
    RbNode_ab1b98* mpHeader;
    uint32_t mnCount;
    // STUB: 0x006c0030
    void Find(RbNode_ab1b98** result, const int32_t* key);
};

struct ListNodeL_ab1b98 {
    ListNodeL_ab1b98* mpNext;
    ListNodeL_ab1b98* mpPrev;
    void* mpData;
};
struct LotList_ab1b98 {
    ListNodeL_ab1b98* mpHead;
    uint32_t mnPad;
    // STUB: 0x00809580
    void Unregister(void* iterator);
};
struct LotIter_ab1b98 {
    ListNodeL_ab1b98* mpCur;
    LotList_ab1b98* mpList;
};
struct LotMgr2_ab1b98 {
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
    virtual LotIter_ab1b98* GetIterator();
};

// STUB: 0x005e5620
void Fn005e5620(void* p);

// GLOBAL: 0x00b43d08
extern LotMgr2_ab1b98* gpB43d08;

// STUB: 0x005e3070
void Fn005e3070(void* lot, bool flag);
// STUB: 0x005e3960
void Fn005e3960(void* lot);

struct Profile_ab1b98 {
    uint32_t mn0;
    int32_t mn4;
};

struct BuildSim_ab1b98 {
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
    virtual bool AddFoundation(uint32_t, int32_t, void*, float, float, uint32_t, float);
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual int32_t Fn31(uint32_t);
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
    virtual void P38();
    virtual Profile_ab1b98* GetProfile(uint32_t);
};
// GLOBAL: 0x00b49aec
extern float g00b49aec;

// STUB: 0x005d76a0
float Fn005d76a0(float* a, float* b);

// STUB: 0x005e37f0
void Fn005e37f0(void* lot);

// FUNCTION: 0x006c4190
void cSC4LotDeveloper::UpdateLotRetainingWalls(void* lot)
{
    Fn005e37f0(lot);
}

// FUNCTION: 0x006c3d30
void cSC4LotDeveloper::Slot08_ab1b98(void* lot, uint32_t reason)
{
    static_cast<Lot_ab1b98*>(lot)->SetState(4, 0, reason);
}

// FUNCTION: 0x006c7320
void cSC4LotDeveloper::RemoveLotFromItsBusinessUnit(void* lot)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    static_cast<Unit_ab1b98*>(l->GetUnit())->RemoveLot(lot);
    mb5e = true;
}

// FUNCTION: 0x006c5c00
bool cSC4LotDeveloper::IsLotDeveloped(void* lot)
{
    uint32_t rect[4];
    static_cast<Lot_ab1b98*>(lot)->GetBoundingRect(rect);
    return IsAreaDeveloped(rect);
}

// FUNCTION: 0x006c3ff0
uint32_t cSC4LotDeveloper::IsLotObjectFoundationRequired(void* occ)
{
    return GetOccupantSlope(occ, true) > mfd4;
}

// FUNCTION: 0x006c5cc0
bool cSC4LotDeveloper::IsLotFlat(void* lot, bool flag)
{
    uint32_t rect[4];
    static_cast<Lot_ab1b98*>(lot)->GetBoundingRect(rect);
    return IsAreaFlat(rect, flag);
}

// FUNCTION: 0x006c5d90
float cSC4LotDeveloper::GetLotAltitudeRange(void* lot, bool flag)
{
    uint32_t rect[4];
    static_cast<Lot_ab1b98*>(lot)->GetBoundingRect(rect);
    return GetAreaAltitudeRange(rect, flag);
}

// FUNCTION: 0x006c5f20
float cSC4LotDeveloper::GetLotSlope(void* lot, bool flag)
{
    uint32_t rect[4];
    static_cast<Lot_ab1b98*>(lot)->GetBoundingRect(rect);
    return GetAreaSlope(rect, flag);
}

// FUNCTION: 0x006c5f50
float cSC4LotDeveloper::GetOccupantSlope(void* occ, bool flag)
{
    uint32_t rect[4];
    GetOccupantCellCoverage(occ, rect);
    return GetAreaSlope(rect, flag);
}

// FUNCTION: 0x006c4150
void cSC4LotDeveloper::RemoveBuildingFoundation(void* occ)
{
    float pos[3];
    static_cast<Occ_ab1b98*>(occ)->GetPosition(pos);
    RemoveFoundation(1, pos[0], pos[2]);
}

// FUNCTION: 0x006c3e70
void* cSC4LotDeveloper::GetLotFoundation(void* lot)
{
    uint32_t x;
    uint32_t z;
    static_cast<Lot_ab1b98*>(lot)->GetLocation(&x, &z);
    return GetFoundationByStandardCityCell(2, x, z);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c5fe0 score 17
void Iter_ab1b98::Fn006c5fe0(Iter_ab1b98* out)
{
    Iter_ab1b98* p = out;
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
}
#endif

// FUNCTION: 0x006c49d0
uint32_t cSC4LotDeveloper::Slot02_ab1b98()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Shutdown();
    delete this;
    return 0;
}

// FUNCTION: 0x006c6080
void Tree_ab1b98::Fn006c6080(Node_ab1b98* node)
{
    while (node) {
        Fn006c6080(node->mpRight);
        Node_ab1b98* left = node->mpLeft;
        Fn0090cf63(node);
        node = left;
    }
}

// FUNCTION: 0x006c44b0
void cSC4LotDeveloper::LevelBorderingVertices(void* rect, float height, bool /*flag*/, void* lot)
{
    int32_t* r = static_cast<int32_t*>(rect);
    static_cast<Demo_ab1b98*>(mpDemolition)->Level(1, true, r[0], r[1], r[2] + 1, r[3] + 1, height, lot, 5, 0);
}

// FUNCTION: 0x006c6e90
void PtrVec_ab1b98::Fn006c6e90()
{
    Obj_ab1b98** p = mpBegin;
    Obj_ab1b98** e = mpEnd;
    if (p != e) {
        do {
            if (*p) {
                (*p)->Release();
            }
            ++p;
        } while (p != e);
    }
    if (mpBegin) {
        Fn0090cf63(mpBegin);
    }
}

// FUNCTION: 0x006c3cf0
void cSC4LotDeveloper::GetPositionForBuilding(void* lot, void* pos, void* index)
{
    Conf_ab1b98* conf = static_cast<Conf_ab1b98*>(static_cast<Lot_ab1b98*>(lot)->GetLotConfiguration());
    if (conf) {
        void* obj = conf->GetObject();
        if (obj) {
            GetPositionForLotConfigurationObject(lot, conf, obj, pos, index);
        }
    }
}

// FUNCTION: 0x006c4290
void cSC4LotDeveloper::UpdateLotBaseTextureOccupant(void* lot, bool flag)
{
    TexOcc_ab1b98* occ = 0;
    if (GetLotBaseTextureOccupant(lot, &occ, 0)) {
        occ->Update(1, flag, 0);
        occ->Release();
    }
}

// FUNCTION: 0x006c42d0
void cSC4LotDeveloper::RemoveLotProps(void* lot)
{
    static_cast<PropMgr_ab1b98*>(mpPropManager)->RemoveLotProps(lot);
    PH_ab1b98* ph = static_cast<PH_ab1b98*>(static_cast<Lot_ab1b98*>(lot)->AsPropertyHolder());
    PHItem_ab1b98* item = static_cast<PHItem_ab1b98*>(ph->Query(0xc999c45e));
    if (item) {
        static_cast<PHTarget_ab1b98*>(item->Get())->Fn(0);
    }
}

// FUNCTION: 0x006c4310
float cSC4LotDeveloper::GetTerrainAltitudeByVertex(int32_t x, int32_t z, bool flag)
{
    int32_t index = mn40 * z + x;
    Terrain_ab1b98* t = static_cast<Terrain_ab1b98*>(mpTerrain);
    float alt = t->GetAltitude(index);
    if (flag) {
        float water = static_cast<Terrain_ab1b98*>(mpTerrain)->GetWaterAltitude(index);
        if (water > alt) {
            return water;
        }
    }
    return alt;
}

// FUNCTION: 0x006c4360
void cSC4LotDeveloper::Fn006c4360(void* rect, void* out, bool flag)
{
    int32_t* r = static_cast<int32_t*>(rect);
    float* o = static_cast<float*>(out);
    o[0] = GetTerrainAltitudeByVertex(r[0], r[1], flag);
    o[1] = GetTerrainAltitudeByVertex(r[2] + 1, r[1], flag);
    o[2] = GetTerrainAltitudeByVertex(r[2] + 1, r[3] + 1, flag);
    o[3] = GetTerrainAltitudeByVertex(r[0], r[3] + 1, flag);
}

// FUNCTION: 0x006c3f30
bool cSC4LotDeveloper::RemoveLotFoundation(void* lot)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    uint32_t x;
    uint32_t z;
    l->GetLocation(&x, &z);
    bool result = RemoveLotFoundation(x, z);
    uint32_t flags = l->GetFlags();
    l->SetFlags(flags & 0xfffffffc);
    return result;
}

// FUNCTION: 0x006c62f0
void cSC4LotDeveloper::Fn006c62f0(void* list)
{
    ListNode_ab1b98* head = static_cast<List_ab1b98*>(list)->mpHead;
    for (ListNode_ab1b98* n = head->mpNext; n != head; n = n->mpNext) {
        Obj_ab1b98* o = n->mpData;
        if (o->Fn32(true)) {
            static_cast<OccMgr_ab1b98*>(mpOccupantManager)->Remove(o, 0, 0);
        }
        o->Fn4r();
        o->Release();
    }
}

// FUNCTION: 0x006cb940
void cSC4LotDeveloper::RemoveBuildingZotProp(void* lot)
{
    PH_ab1b98* ph = static_cast<PH_ab1b98*>(static_cast<Lot_ab1b98*>(lot)->AsPropertyHolder());
    PHItem_ab1b98* item = static_cast<PHItem_ab1b98*>(ph->Query(0xc999c45e));
    if (item) {
        PHTarget_ab1b98* target = static_cast<PHTarget_ab1b98*>(item->Get());
        uint32_t id = *target->GetIdSlot();
        if (id) {
            RemoveLotProp(lot, id);
        }
        target->Fn(0);
    }
}

// FUNCTION: 0x006c90a0
void cSC4LotDeveloper::EndDemolishLot(void* lot)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    if (l->IsInitialized()) {
        l->SetState(6, 0, 0);
        ClearLot(lot);
        uint32_t zone = l->GetZoneType();
        if (zone == 0 || zone == 0xf || zone == 0xb || zone == 0xc) {
            static_cast<LotMgr_ab1b98*>(mpLotManager)->Fn24(lot);
        }
    }
}

// FUNCTION: 0x006c3e10
void cSC4LotDeveloper::GetFoundationByOccupant(void* occ)
{
    Occ_ab1b98* o = static_cast<Occ_ab1b98*>(occ);
    float pos[3];
    o->GetPosition(pos);
    uint32_t type = o->GetType();
    uint32_t kind;
    if (type == 0x278128a0) {
        kind = 1;
    } else {
        kind = (type != 0xa823821e) + 3;
    }
    GetFoundationByPosition(kind, pos[0], pos[2]);
}

// FUNCTION: 0x006c5f80
int32_t cSC4LotDeveloper::GetLotDevelopmentCost(void* rect)
{
    int32_t* r = static_cast<int32_t*>(rect);
    int32_t width = r[2] - r[0] + 1;
    int32_t height = r[3] - r[1] + 1;
    float slope = GetAreaSlope(rect, true);
    float scaled = slope * 0.0625f;
    float value = reinterpret_cast<Curve_ab1b98*>(mCurve)->GetOutputValue(scaled);
    return static_cast<int32_t>(value * height * width);
}

// FUNCTION: 0x006c3eb0
bool cSC4LotDeveloper::RemoveLotFoundation(uint32_t x, uint32_t z)
{
    bool removed = false;
    Obj_ab1b98* found = static_cast<Obj_ab1b98*>(GetFoundationByStandardCityCell(2, x, z));
    if (found) {
        Obj_ab1b98* inner = static_cast<Obj_ab1b98*>(found->Fn3());
        inner->AddRef();
        static_cast<OccMgr_ab1b98*>(mpOccupantManager)->Remove(inner, 1, 0);
        inner->Release();
        removed = true;
    }
    Lot_ab1b98* lot = static_cast<Lot_ab1b98*>(static_cast<LotMgr_ab1b98*>(mpLotManager)->GetLot(x, z, 0));
    if (lot) {
        uint32_t flags = lot->GetFlags();
        lot->SetFlags(flags & 0xfffffffc);
    }
    return removed;
}

// FUNCTION: 0x006c3f80
void cSC4LotDeveloper::UpdateLotFoundation(void* lot)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    if (l->GetFlags() & 3) {
        Obj_ab1b98* found = static_cast<Obj_ab1b98*>(GetLotFoundation(lot));
        if (found) {
            uint32_t ref = found->Fn4r();
            RemoveLotFoundation(lot);
            AddLotFoundation_2(lot, ref, true, false, false);
        } else {
            AddLotFoundation(lot, l->GetLotConfiguration(), true, false, false);
        }
    }
}

// FUNCTION: 0x006c40e0
bool cSC4LotDeveloper::AddBuildingFoundation(void* building, void* config)
{
    uint32_t id = mnFoundationId;
    ConfData_ab1b98* data = static_cast<Conf_ab1b98*>(config)->GetObject();
    if (data && data->mnId) {
        id = data->mnId;
    } else {
        PH_ab1b98* ph = static_cast<PH_ab1b98*>(static_cast<Obj_ab1b98*>(building)->Fn3());
        void* holder = ph->GetHolder();
        Fn005fd480(holder, 0x88fcd877, &id);
    }
    if (id != 0) {
        return AddBuildingFoundation_2(building, id);
    }
    return false;
}

// FUNCTION: 0x006c6fd0
void Deque_ab1b98::NewNodesAtFront(uint32_t n)
{
    uint32_t nodes = (n + 0x1f) >> 5;
    if (nodes > static_cast<uint32_t>(mpStartNode - mpMap)) {
        ReallocateMap(nodes, true);
    }
    for (uint32_t i = 1; i <= nodes; ++i) {
        mpStartNode[-static_cast<int32_t>(i)] = Fn0090cf54(0x80);
    }
}

// FUNCTION: 0x006c7020
void Deque_ab1b98::NewNodesAtBack(uint32_t n)
{
    uint32_t nodes = (n + 0x1f) >> 5;
    if (nodes + 1 > mnMapSize - static_cast<uint32_t>(mpFinishNode - mpMap)) {
        ReallocateMap(nodes, false);
    }
    for (uint32_t i = 1; i <= nodes; ++i) {
        mpFinishNode[i] = Fn0090cf54(0x80);
    }
}

// FUNCTION: 0x006cc1d0
void cSC4LotDeveloper::StartDemolishLot(void* lot)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    if (l->GetFlags() & 1) {
        int32_t rect[4];
        l->GetBoundingRect(rect);
        static_cast<Flora_ab1b98*>(mpFloraSim)->RemoveFlora(rect, 0);
    }
    RemoveLotProps(lot);
    RemoveNetworkConnectionNodes(lot);
    ClearLotBuildings(lot, 5, true, 0);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c5460 score 23
bool cSC4LotDeveloper::AddLotFoundation(void* lot, void* config, bool a, bool b, bool c)
{
    if (lot && config) {
        uint32_t id = mnLotFoundationId;
        ConfData_ab1b98* data = static_cast<Conf_ab1b98*>(config)->GetObject2();
        if (data) {
            uint32_t count = data->mpEnd - data->mpBegin;
            if (count) {
                uint32_t pick = g00b49af0.Uniform(count);
                id = data->mpBegin[pick];
            } else {
                id = data->mnId;
            }
        }
        if (id) {
            return AddLotFoundation_2(lot, id, a, b, c);
        }
    }
    return false;
}
#endif

// FUNCTION: 0x006c9a40
void cSC4LotDeveloper::RemoveBuildingZotProp(void* lot, uint32_t id)
{
    PH_ab1b98* ph = static_cast<PH_ab1b98*>(static_cast<Lot_ab1b98*>(lot)->AsPropertyHolder());
    PHItem_ab1b98* item = static_cast<PHItem_ab1b98*>(ph->Query(0xc999c45e));
    if (item) {
        PHTarget_ab1b98* target = static_cast<PHTarget_ab1b98*>(item->Get());
        uint32_t current = *target->GetIdSlot();
        if (id == 6) {
            Fn005f98c0(0x4c04de69, 2, 0, 0, 0, lot);
        }
        if (id == 0 || current == id) {
            if (current) {
                RemoveLotProp(lot, current);
            }
            target->Fn(0);
        }
    }
}

// FUNCTION: 0x006c6cf0
void cSC4LotDeveloper::GetBoundaryLotTexture(void* type, void* texture, void* flag1, void* flag2)
{
    int32_t* k = static_cast<int32_t*>(type);
    int32_t key = ((k[0] * 16 + k[1]) * 16 + k[2]) * 16 + k[3];
    BoundaryMap_ab1b98* map = reinterpret_cast<BoundaryMap_ab1b98*>(mBoundaryMap);
    RbNode_ab1b98* node;
    map->Find(&node, &key);
    if (node == map->mpHeader) {
        key = 0;
        map->Find(&node, &key);
    }
    *static_cast<uint32_t*>(texture) = node->mnTexture;
    *static_cast<uint8_t*>(flag1) = node->mb18;
    *static_cast<uint8_t*>(flag2) = node->mb19;
}

// FUNCTION: 0x006c5590
uint32_t cSC4LotDeveloper::IsLotObjectFoundationRequired_2(void* a, void* b)
{
    int32_t rect[4];
    float* pa = static_cast<float*>(a);
    float* pb = static_cast<float*>(b);
    static_cast<City_ab1b98*>(mpCity)->PositionToCell(pa[0], pa[2], &rect[0], &rect[1]);
    static_cast<City_ab1b98*>(mpCity)->PositionToCell(pb[0], pb[2], &rect[2], &rect[3]);
    rect[2]++;
    rect[3]++;
    return GetAreaSlope(rect, true) > mfd4;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c5b70 score 38
float cSC4LotDeveloper::GetAverageAreaAltitude(void* rect, bool flag)
{
    int32_t* r = static_cast<int32_t*>(rect);
    int32_t x = r[0];
    int32_t y0 = r[1];
    int32_t y = y0;
    int32_t x1 = r[2] + 1;
    int32_t y1 = r[3] + 1;
    float sum = 0.0f;
    int32_t count = 0;
    for (; x <= x1; x++) {
        for (y = y0; y <= y1; y++) {
            sum += GetTerrainAltitudeByVertex(x, y, flag);
            count++;
        }
    }
    return sum / count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c77d0 score 74
void cSC4LotDeveloper::SetForceEmptyLotBaseTextures(bool flag)
{
    if (flag != mb5c) {
        mb5c = flag;
        LotIter_ab1b98* it = gpB43d08->GetIterator();
        for (;;) {
            LotList_ab1b98* list = it->mpList;
            if (!list) {
                break;
            }
            ListNodeL_ab1b98* node = it->mpCur;
            if (node == list->mpHead) {
                break;
            }
            it->mpCur = node->mpNext;
            Lot_ab1b98* lot = static_cast<Lot_ab1b98*>(node->mpData);
            if (mb5c) {
                SetEmptyLotBaseTexture(lot);
            } else {
                SetNormalLotBaseTexture(lot, lot->GetLotConfiguration(), true);
            }
        }
        if (it->mpList) {
            LotIter_ab1b98* self = it;
            it->mpList->Unregister(&self);
        }
        Fn005e5620(it);
    }
}
#endif

// FUNCTION: 0x006c8a20
void cSC4LotDeveloper::ClearLot(void* lot)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    uint32_t x;
    uint32_t z;
    l->GetLocation(&x, &z);
    Fn005e3070(lot, false);
    RemoveLotFoundation(x, z);
    UpdateSurroundingLotFoundations(lot);
    Fn005e3960(lot);
    l->SetVerticesAreLocked(false);
    l->SetState(1, 0, 0);
    l->SetBuildingType(0);
    l->SetLotConfiguration(0);
    SetEmptyLotBaseTexture(lot);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c5c30 score 18
bool cSC4LotDeveloper::IsAreaFlat(void* rect, bool flag)
{
    int32_t* r = static_cast<int32_t*>(rect);
    int32_t x0 = r[0];
    int32_t y0 = r[1];
    int32_t x1 = r[2] + 1;
    int32_t y1 = r[3] + 1;
    float base = GetTerrainAltitudeByVertex(x0, y0, true);
    for (int32_t x = x0; x <= x1; x++) {
        for (int32_t y = y0; y <= y1; y++) {
            if (std::fabs(GetTerrainAltitudeByVertex(x, y, flag) - base) > mfd0) {
                return false;
            }
        }
    }
    return true;
}
#endif

// FUNCTION: 0x006c4590
void cSC4LotDeveloper::GetOccupantCellCoverage(void* occ, void* rect)
{
    int32_t* r = static_cast<int32_t*>(rect);
    float high[3];
    float low[3];
    static_cast<Occ_ab1b98*>(occ)->GetBoundingBox(low, high);
    low[0] = low[0] + 0.05f;
    low[2] = low[2] + 0.05f;
    high[0] = high[0] - 0.05f;
    high[2] = high[2] - 0.05f;
    static_cast<City_ab1b98*>(mpCity)->PositionToCell(low[0], low[2], &r[0], &r[1]);
    static_cast<City_ab1b98*>(mpCity)->PositionToCell(high[0], high[2], &r[2], &r[3]);
}

// FUNCTION: 0x006c3c50
void cSC4LotDeveloper::ClearLotBuildings(void* lot, uint32_t state, bool removeFoundation, uint32_t arg)
{
    Obj_ab1b98* building = static_cast<Obj_ab1b98*>(GetFirstBuilding(lot));
    static_cast<Lot_ab1b98*>(lot)->SetState(state, 0, 0);
    while (building) {
        building->AddRef();
        void* occ = building->Fn3();
        static_cast<PropMgr_ab1b98*>(mpPropManager)->RemoveBuildingProps(occ);
        if (removeFoundation) {
            RemoveBuildingFoundation(occ);
        }
        static_cast<OccMgr_ab1b98*>(mpOccupantManager)->Remove(occ, 1, arg);
        building->Release();
        building = static_cast<Obj_ab1b98*>(GetFirstBuilding(lot));
    }
    RemoveBuildingZotProp(lot);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c44f0 score 6
uint32_t cSC4LotDeveloper::AttemptAreaLevelling(void* rect, float height, bool flag, bool flag2, float limit, void* lot)
{
    int32_t* r = static_cast<int32_t*>(rect);
    float average = GetAverageAreaAltitude(rect, flag);
    if (limit == FLT_MAX) {
        limit = mfe8;
    }
    if (limit >= 1000.0f || GetAreaSlope(rect, flag) <= limit) {
        return static_cast<Demo_ab1b98*>(mpDemolition)->Level(1, flag2, r[0], r[1], r[2] + 1, r[3] + 1, average, lot, 5, 0);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c5cf0 score 68
float cSC4LotDeveloper::GetAreaAltitudeRange(void* rect, bool flag)
{
    int32_t* r = static_cast<int32_t*>(rect);
    int32_t x = r[0];
    int32_t y0 = r[1];
    int32_t x1 = r[2] + 1;
    int32_t y1 = r[3] + 1;
    float low = FLT_MAX;
    float high = -FLT_MAX;
    for (; x <= x1; x++) {
        for (int32_t y = y0; y <= y1; y++) {
            float v = GetTerrainAltitudeByVertex(x, y, flag);
            if (v < low) {
                low = v;
            }
            if (v > high) {
                high = v;
            }
        }
    }
    return high - low;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c5620 score 49
float cSC4LotDeveloper::GetLowestOrHighestAreaAltitude(void* rect, bool findLowest, bool flag)
{
    int32_t* r = static_cast<int32_t*>(rect);
    int32_t x = r[0];
    int32_t y0 = r[1];
    int32_t x1 = r[2] + 1;
    int32_t y1 = r[3] + 1;
    float best = findLowest ? FLT_MAX : -FLT_MAX;
    for (; x <= x1; x++) {
        for (int32_t y = y0; y <= y1; y++) {
            float v = GetTerrainAltitudeByVertex(x, y, flag);
            if (findLowest) {
                if (v < best) {
                    best = v;
                }
            } else {
                if (v > best) {
                    best = v;
                }
            }
        }
    }
    return best;
}
#endif

// FUNCTION: 0x006c54e0
bool cSC4LotDeveloper::RemoveFoundation(int32_t kind, float x, float z)
{
    bool removed = false;
    Obj_ab1b98* found = static_cast<Obj_ab1b98*>(GetFoundationByPosition(kind, x, z));
    if (found) {
        Obj_ab1b98* inner = static_cast<Obj_ab1b98*>(found->Fn3());
        if (inner) {
            inner->AddRef();
        }
        static_cast<OccMgr_ab1b98*>(mpOccupantManager)->Remove(inner, 1, 0);
        removed = true;
        if (inner) {
            inner->Release();
        }
    }
    if (kind == 2) {
        Lot_ab1b98* lot = static_cast<Lot_ab1b98*>(static_cast<LotMgr_ab1b98*>(mpLotManager)->GetLot(static_cast<int32_t>(x * 0.0625f), static_cast<int32_t>(z * 0.0625f), 0));
        if (lot) {
            uint32_t flags = lot->GetFlags();
            lot->SetFlags(flags & 0xfffffffc);
        }
    }
    return removed;
}

// FUNCTION: 0x006c4020
bool cSC4LotDeveloper::AddBuildingFoundation_2(void* building, uint32_t id)
{
    Obj_ab1b98* b = static_cast<Obj_ab1b98*>(building);
    float position[3];
    float low[3];
    float high[3];
    static_cast<Occ_ab1b98*>(b->Fn3())->GetPosition(position);
    static_cast<Occ_ab1b98*>(b->Fn3())->GetBoundingBox(low, high);
    uint32_t extra = b->Fn14();
    if (id == 0) {
        PH_ab1b98* ph = static_cast<PH_ab1b98*>(b->Fn3());
        void* holder = ph->GetHolder();
        Fn005fd480(holder, 0x88fcd877, &id);
        if (id == 0) {
            id = mnFoundationId;
        }
    }
    return static_cast<BuildSim_ab1b98*>(mpBuildingDevSim)->AddFoundation(id, 1, position, high[0] - low[0], high[2] - low[2], extra, -1.0f);
}

// FUNCTION: 0x006c6230
void* cSC4LotDeveloper::CreateLotProp(void* lot, uint32_t index, uint32_t propId)
{
    if (!lot) {
        return 0;
    }
    Conf_ab1b98* conf = static_cast<Conf_ab1b98*>(static_cast<Lot_ab1b98*>(lot)->GetLotConfiguration());
    if (!conf) {
        return 0;
    }
    ConfObj_ab1b98* object = &conf->GetObjects()->mpBegin[index];
    float position[3];
    position[0] = g00b49aec;
    position[1] = g00b49aec;
    position[2] = g00b49aec;
    uint32_t height;
    GetPositionForLotConfigurationObject(lot, conf, object, position, &height);
    if (propId) {
        PropObj_ab1b98* prop = static_cast<PropMgr_ab1b98*>(mpPropManager)->CreateProp(propId, position, height);
        if (prop) {
            prop->SetValue(object->mn24);
            return prop;
        }
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c7720 score 9
void cSC4LotDeveloper::UpdateSurroundingLotFoundations(void* lot)
{
    List_ab1b98 list;
    list.mpHead = 0;
    ListNode_ab1b98* head = static_cast<ListNode_ab1b98*>(Fn0090cf54(0xc));
    head->mpNext = head;
    head->mpPrev = head;
    list.mpHead = head;
    if (static_cast<LotMgr_ab1b98*>(mpLotManager)->GetNearbyLots(lot, &list, 0xf)) {
        for (ListNode_ab1b98* n = list.mpHead->mpNext; n != list.mpHead; n = n->mpNext) {
            Lot_ab1b98* l = static_cast<Lot_ab1b98*>(static_cast<void*>(n->mpData));
            if (l->GetFlags() & 3) {
                UpdateLotFoundation(l);
            }
        }
    }
    ListNode_ab1b98* node = list.mpHead->mpNext;
    if (node != list.mpHead) {
        do {
            ListNode_ab1b98* cur = node;
            node = node->mpNext;
            if (cur->mpData) {
                cur->mpData->Release();
            }
            Fn0090cf63(cur);
        } while (node != list.mpHead);
    }
    list.mpHead->mpNext = list.mpHead;
    list.mpHead->mpPrev = list.mpHead;
    Fn0090cf63(list.mpHead);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c3d50 score 2
void cSC4LotDeveloper::Slot09_ab1b98(void* lot, uint32_t developerType)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    uint32_t type = l->GetBuildingType(false);
    Profile_ab1b98* profile = static_cast<BuildSim_ab1b98*>(mpBuildingDevSim)->GetProfile(type);
    int32_t wealth = static_cast<BuildSim_ab1b98*>(mpBuildingDevSim)->Fn31(developerType);
    int32_t delta = profile->mn4 - wealth;
    uint32_t condition;
    PH_ab1b98* ph = static_cast<PH_ab1b98*>(l->AsPropertyHolder());
    PHItem_ab1b98* item = static_cast<PHItem_ab1b98*>(ph->Query(0xe999b11f));
    if (item && *static_cast<PHTarget_ab1b98*>(item->Get())->GetIdSlot() != 0) {
        condition = 1;
    } else {
        condition = 0;
    }
    switch (delta) {
    case 1:
        condition = 2;
        break;
    case 2:
        condition = 3;
        break;
    }
    l->SetState(3, wealth, 0);
    l->SetCondition(condition);
    uint32_t capacity = l->GetAvailableCapacity(developerType, 0);
    l->SetPopulation(developerType, capacity);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c43d0 score 2
uint32_t cSC4LotDeveloper::LevelAreaInternalVertices(void* rect, float target, bool skipWater, bool force, void* lot)
{
    int32_t* r = static_cast<int32_t*>(rect);
    uint32_t count = 0;
    if (target < 0.0f) {
        target = GetAverageAreaAltitude(rect, true);
    }
    for (int32_t x = r[0] + 1; x <= r[2]; x++) {
        for (int32_t y = r[1] + 1; y <= r[3]; y++) {
            if (!skipWater || !static_cast<Terrain_ab1b98*>(mpTerrain)->Fn37(x, y)) {
                float diff = GetTerrainAltitudeByVertex(x, y, true) - target;
                if (force || diff > mfe4) {
                    static_cast<Demo_ab1b98*>(mpDemolition)->Level(1, true, x, y, x, y, target, lot, 5, 0);
                    count++;
                }
            }
        }
    }
    return count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c5dc0 score 152
float cSC4LotDeveloper::GetAreaSlope(void* rect, bool flag)
{
    int32_t* r = static_cast<int32_t*>(rect);
    int32_t y1 = r[3];
    int32_t x1 = r[2];
    int32_t y0 = r[1];
    int32_t x = r[0];
    float low = FLT_MAX;
    float high = -FLT_MAX;
    float lowPos[2];
    float highPos[2];
    for (; x <= x1 + 1; x++) {
        for (int32_t y = y0; y <= y1 + 1; y++) {
            float v = GetTerrainAltitudeByVertex(x, y, flag);
            if (v < low) {
                lowPos[0] = static_cast<float>(x);
                lowPos[1] = static_cast<float>(y);
                low = v;
            }
            if (high < v) {
                highPos[0] = static_cast<float>(x);
                highPos[1] = static_cast<float>(y);
                high = v;
            }
        }
    }
    float length = Fn005d76a0(lowPos, highPos);
    float slope = 0.0f;
    if (length != 0.0f) {
        if (6.0f < length) {
            length = length * 0.25f;
        }
        if (5.0f < length) {
            length = length * 0.3f;
        }
        if (length <= 4.0f) {
            if (3.0f < length) {
                length = length * 0.4f;
            }
        } else {
            length = length * 0.35f;
        }
        slope = (high - low) / length;
    }
    return slope;
}
#endif

// ===== Agent 2 additions =====
struct BaseTexOcc_ab1b98 {
    virtual bool QueryInterface(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual BaseTexOcc_ab1b98* Fn3();
    virtual void P4();
    virtual void SetFlag(uint32_t);

    // STUB: 0x005e05b0
    BaseTexOcc_ab1b98* Fn005e05b0();
};
struct Gzcom_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual bool Create(uint32_t clsid, uint32_t iid, void* out);
};
// STUB: 0x0090ddf1
Gzcom_ab1b98* Fn0090ddf1();
// STUB: 0x005decf0
void* Fn005decf0(uint32_t size);
struct OccMgrB_ab1b98 {
    virtual void P0();
    virtual uint32_t AddRef();
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
    virtual bool Find(void*, int32_t, int32_t, uint32_t);
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual bool GetOccupantsF(void*, void*, void*, uint32_t, int32_t);
    virtual void P38();
    virtual void P39();
    virtual void P40();
    virtual bool GetOccupants(void*, void*, void*, uint32_t, int32_t);
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual void FreeList(void*);
};
struct LotCfgB_ab1b98 {
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
    virtual float GetStoredSlope();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual bool Fn14();
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
    virtual bool Fn27(int32_t);
};
struct DqIt_ab1b98 {
    void** mpCur;
    void** mpFirst;
    void** mpLast;
    void*** mpNode;
};

// A list head like the original's allocator hands out; nodes hold an object pointer at +8.
inline ListNode_ab1b98* NewListHead_ab1b98()
{
    ListNode_ab1b98* head = static_cast<ListNode_ab1b98*>(Fn0090cf54(0xc));
    head->mpNext = head;
    head->mpPrev = head;
    return head;
}
inline void FreeListHead_ab1b98(ListNode_ab1b98* head)
{
    ListNode_ab1b98* n = head->mpNext;
    while (n != head) {
        ListNode_ab1b98* cur = n;
        n = n->mpNext;
        if (cur->mpData) {
            cur->mpData->Release();
        }
        Fn0090cf63(cur);
    }
    head->mpNext = head;
    head->mpPrev = head;
    Fn0090cf63(head);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c41a0 score 13
bool cSC4LotDeveloper::GetLotBaseTextureOccupant(void* lot, void* out, bool create)
{
    BaseTexOcc_ab1b98** pp = static_cast<BaseTexOcc_ab1b98**>(out);
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    uint32_t x;
    uint32_t z;
    BaseTexOcc_ab1b98* found;
    *pp = 0;
    l->GetLocation(&x, &z);
    if (static_cast<OccMgrB_ab1b98*>(mpOccupantManager)->Find(&found, x, z, 0x497f6d9d)) {
        if (found->QueryInterface(0x97f6d98, reinterpret_cast<void**>(pp))) {
            (*pp)->SetFlag(2);
            found->Release();
        }
    } else if (create) {
        if (!Fn0090ddf1()->Create(0xc97f987c, 0x97f6d98, pp)) {
            void* mem = Fn005decf0(0x60);
            BaseTexOcc_ab1b98* o = 0;
            if (mem) {
                o = static_cast<BaseTexOcc_ab1b98*>(mem)->Fn005e05b0();
            }
            *pp = o;
            o->AddRef();
        }
        (*pp)->Fn3()->Fn3();
        (*pp)->SetFlag(2);
    }
    return *pp != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c7860 score 4
void cSC4LotDeveloper::Fn006c7860(void* lot, void* config, uint32_t)
{
    ConfVec_ab1b98* objects = static_cast<Conf_ab1b98*>(config)->GetObjects();
    if (objects) {
        int32_t count = static_cast<int32_t>(objects->mpEnd - objects->mpBegin);
        for (int32_t i = 0; i < count; i++) {
            ConfObj_ab1b98* o = objects->mpBegin + i;
            if (o->mPad[0] == 1 && !(o->mPad[1] & 1)) {
                Fn006c6d70(lot, i);
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c7630 score 23
float cSC4LotDeveloper::Fn006c7630(void* lot)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    int32_t rect[4];
    l->GetBoundingRect(rect);
    float lowest = GetLowestOrHighestAreaAltitude(rect, true, true);
    List_ab1b98 list;
    list.mpHead = NewListHead_ab1b98();
    if (static_cast<LotMgr_ab1b98*>(mpLotManager)->GetNearbyLots(lot, &list, 0xf)) {
        for (ListNode_ab1b98* n = list.mpHead->mpNext; n != list.mpHead; n = n->mpNext) {
            Lot_ab1b98* o = reinterpret_cast<Lot_ab1b98*>(n->mpData);
            if (o->GetFlags() & 3) {
                float altitude = o->GetAltitude();
                if (lowest > altitude) {
                    lowest = altitude;
                }
            }
        }
    }
    FreeListHead_ab1b98(list.mpHead);
    return lowest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006caaf0 score 66
void cSC4LotDeveloper::Fn006caaf0(void* lot)
{
    List_ab1b98 list;
    list.mpHead = NewListHead_ab1b98();
    if (lot && mpOccupantManager) {
        int32_t rect[4];
        static_cast<Lot_ab1b98*>(lot)->GetBoundingRect(rect);
        if (static_cast<OccMgrB_ab1b98*>(mpOccupantManager)->GetOccupants(&list, &rect[0], &rect[2], 0x497f6d9d, -1)) {
            Fn006c62f0(&list);
        }
    }
    FreeListHead_ab1b98(list.mpHead);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c9100 score 84
void* cSC4LotDeveloper::GetFirstBuilding(void* lot)
{
    void* result = 0;
    int32_t rect[4];
    static_cast<Lot_ab1b98*>(lot)->GetBoundingRect(rect);
    List_ab1b98 list;
    list.mpHead = NewListHead_ab1b98();
    OccMgrB_ab1b98* mgr = static_cast<OccMgrB_ab1b98*>(mpOccupantManager);
    if (mgr->GetOccupants(&list, &rect[0], &rect[2], 0x278128a0, 1) && list.mpHead->mpNext != list.mpHead) {
        if (reinterpret_cast<Occ_ab1b98*>(list.mpHead->mpNext->mpData)->QueryInterface(0x87dda3a9, &result)) {
            static_cast<Occ_ab1b98*>(result)->Release();
        }
        mgr->FreeList(&list);
    }
    FreeListHead_ab1b98(list.mpHead);
    return result;
}
#endif

// FUNCTION: 0x006cc880
bool cSC4LotDeveloper::UpdateLotElements(void* lot, uint32_t kind)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    if (static_cast<int32_t>(l->GetState()) >= 2) {
        bool flag = false;
        if (l->GetFlags() & 3) {
            UpdateLotFoundation(lot);
            UpdateLotRetainingWalls(lot);
        } else if (kind != 5) {
            LotCfgB_ab1b98* config = static_cast<LotCfgB_ab1b98*>(l->GetLotConfiguration());
            if (config) {
                bool b = config->Fn14();
                float slope = GetLotSlope(lot, b);
                if (config->GetStoredSlope() < slope) {
                    bool required = config->Fn27(7);
                    AddLotFoundation(lot, config, required, false, true);
                    flag = true;
                }
                if (fabsf(slope) > 0.25f) {
                    UpdateLotObjectAlitudes(lot);
                }
            }
        }
        UpdateLotBaseTextureOccupant(lot, flag);
        l->UpdateSlope();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006cbd60 score 2
void cSC4LotDeveloper::Fn006cbd60(uint32_t ticks)
{
    mnQueueTicks += ticks;
    if (mnQueueTicks > 200) {
        bool flag = mnQueueState == 2;
        mnQueueTicks = 0;
        uint32_t count = mnQueueBatch;
        if (count != 0) {
            DqIt_ab1b98* cursor = reinterpret_cast<DqIt_ab1b98*>(mQueueCursor);
            DqIt_ab1b98* finish = reinterpret_cast<DqIt_ab1b98*>(mQueueFinish);
            do {
                DqIt_ab1b98 fin = *finish;
                count--;
                if (cursor->mpCur == fin.mpCur) {
                    mnQueueState = 0;
                    return;
                }
                void* item = *cursor->mpCur;
                cursor->mpCur++;
                if (cursor->mpCur == cursor->mpLast) {
                    cursor->mpNode++;
                    cursor->mpFirst = *cursor->mpNode;
                    cursor->mpLast = cursor->mpFirst + 0x80 / sizeof(void*);
                    cursor->mpCur = cursor->mpFirst;
                }
                Fn006c8e10(item, flag);
            } while (count != 0);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006cbe50 score 10
void cSC4LotDeveloper::Fn006cbe50(uint32_t state)
{
    bool flag = state == 2;
    DqIt_ab1b98* start = reinterpret_cast<DqIt_ab1b98*>(mQueueStart);
    DqIt_ab1b98* finish = reinterpret_cast<DqIt_ab1b98*>(mQueueFinish);
    DqIt_ab1b98* cursor = reinterpret_cast<DqIt_ab1b98*>(mQueueCursor);
    *cursor = *start;
    DqIt_ab1b98 fin = *finish;
    while (cursor->mpCur != fin.mpCur) {
        void* item = *cursor->mpCur;
        Fn006c8e10(item, flag);
        cursor->mpCur++;
        if (cursor->mpCur == cursor->mpLast) {
            cursor->mpNode++;
            cursor->mpFirst = *cursor->mpNode;
            cursor->mpLast = cursor->mpFirst + 0x80 / sizeof(void*);
            cursor->mpCur = cursor->mpFirst;
        }
        fin = *finish;
    }
    *cursor = *start;
    mnQueueState = 0;
}
#endif

struct PropObjB_ab1b98;
struct PropObjC_ab1b98;
struct PHItemB_ab1b98;
struct PHTargetB_ab1b98;
struct BldC_ab1b98;
struct SimOrd_ab1b98;
struct LotB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void* AsPropertyHolder();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void* GetLotConfiguration();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void GetCenter(void*);
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
    virtual uint32_t GetState();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
    virtual void P38();
    virtual void P39();
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual uint32_t GetBuildingType(bool);
    virtual void P47();
    virtual void* GetBuilding();
};
struct PropMgrB_ab1b98 {
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
    virtual void GetLotProps(void*, void*);
    virtual void P25();
    virtual PropObjB_ab1b98* CreateProp(uint32_t, void*, uint32_t);
    virtual void P27();
    virtual void P28();
    virtual void RemoveProp(void*);
    virtual void P30();
};
struct PropObjB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual PropObjC_ab1b98* Fn6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void Fn12(uint32_t);
};
struct PropObjC_ab1b98 {
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
    virtual void SetProperty(uint32_t, uint32_t, uint32_t);
};
struct PHB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual PHItemB_ab1b98* Query(uint32_t);
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void SetProperty(uint32_t, uint32_t, uint32_t);
};
struct PHItemB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual PHTargetB_ab1b98* Get();
};
struct PHTargetB_ab1b98 {
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
    virtual void SetValue(uint32_t);
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
    virtual void P39();
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual void P48();
    virtual void P49();
    virtual void P50();
    virtual void P51();
    virtual void P52();
    virtual void P53();
    virtual void P54();
    virtual void P55();
    virtual void P56();
    virtual void P57();
    virtual void P58();
    virtual void P59();
    virtual void P60();
    virtual void P61();
    virtual void P62();
    virtual void P63();
    virtual void P64();
    virtual void P65();
    virtual void P66();
    virtual void P67();
    virtual void P68();
    virtual void P69();
    virtual void P70();
    virtual void P71();
    virtual uint32_t* GetValueSlot72();
    virtual uint32_t* GetValueSlot73();
};
struct PlumbB_ab1b98 {
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
    virtual bool Fn11(int32_t, int32_t);
};
struct CfgC_ab1b98 {
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
    virtual uint8_t Fn11();
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
    virtual uint32_t Fn24();
};
struct BldC_ab1b98 {
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
    virtual void Fn10(void*, void*);
};
struct BldB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual BldC_ab1b98* Fn3();
};
struct FoundB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual uint32_t Release();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual int32_t Fn9();
};
struct SimOrd_ab1b98 {
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
    virtual uint8_t Fn20();
};
struct BuildSimB_ab1b98 {
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
    virtual SimOrd_ab1b98* Fn33(uint32_t, int32_t);
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
    virtual void P38();
    virtual Profile_ab1b98* GetProfile(uint32_t);
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual void P48();
    virtual void P49();
    virtual void P50();
    virtual void P51();
    virtual void P52();
    virtual void P53();
    virtual bool Fn54();
};
struct ViewUtil_ab1b98 {
    uint8_t mPad[0x10];
    uint32_t mn10;
};
// GLOBAL: 0x00b43dd8
extern ViewUtil_ab1b98* gpB43dd8;

inline void FreeListNodes_ab1b98(ListNode_ab1b98* head)
{
    ListNode_ab1b98* n = head->mpNext;
    while (n != head) {
        ListNode_ab1b98* cur = n;
        n = n->mpNext;
        Fn0090cf63(cur);
    }
    head->mpNext = head;
    head->mpPrev = head;
    Fn0090cf63(head);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c9780 score 107
bool cSC4LotDeveloper::RemoveLotProp(void* lot, uint32_t id)
{
    List_ab1b98 list;
    list.mpHead = NewListHead_ab1b98();
    bool removed = false;
    static_cast<PropMgrB_ab1b98*>(mpPropManager)->GetLotProps(&list, lot);
    for (ListNode_ab1b98* n = list.mpHead->mpNext; n != list.mpHead; n = n->mpNext) {
        Obj_ab1b98* item = n->mpData;
        if (item) {
            PropObjB_ab1b98* prop = reinterpret_cast<PropObjB_ab1b98*>(item);
            PHB_ab1b98* ph = reinterpret_cast<PHB_ab1b98*>(prop->Fn6());
            PHItemB_ab1b98* entry = ph->Query(0x48e95539);
            if (entry) {
                if (*entry->Get()->GetValueSlot72() == id) {
                    static_cast<PropMgrB_ab1b98*>(mpPropManager)->RemoveProp(item);
                    removed = true;
                }
            }
            item->Release();
        }
    }
    FreeListNodes_ab1b98(list.mpHead);
    return removed;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006cae30 score 106
bool cSC4LotDeveloper::TestWater(void* lot, int32_t x, int32_t z)
{
    LotB_ab1b98* l = static_cast<LotB_ab1b98*>(lot);
    PHB_ab1b98* ph = static_cast<PHB_ab1b98*>(l->AsPropertyHolder());
    PHItemB_ab1b98* item = ph->Query(0x8999b20b);
    if (!item) {
        ph->SetProperty(0x8999b20b, 0, 0);
        item = ph->Query(0x8999b20b);
    }
    PHTargetB_ab1b98* target = item->Get();
    uint32_t level = *target->GetValueSlot73();
    bool flag = false;
    int32_t state = static_cast<int32_t>(l->GetState());
    if (state >= 2 && state <= 4) {
        BuildSimB_ab1b98* sim = static_cast<BuildSimB_ab1b98*>(mpBuildingDevSim);
        Profile_ab1b98* profile = sim->GetProfile(l->GetBuildingType(false));
        if (profile->mn0 == 0) {
            flag = true;
        } else {
            SimOrd_ab1b98* ordinance = sim->Fn33(profile->mn0, profile->mn4);
            CfgC_ab1b98* config = static_cast<CfgC_ab1b98*>(l->GetLotConfiguration());
            if (ordinance && config) {
                uint8_t wanted = config->Fn11();
                if (wanted > ordinance->Fn20()) {
                    flag = true;
                }
            }
        }
    }
    if (!static_cast<BuildSimB_ab1b98*>(mpBuildingDevSim)->Fn54() && !static_cast<PlumbB_ab1b98*>(mpPlumbingSim)->Fn11(x, z) && flag) {
        uint32_t next = level + 1;
        target->SetValue(next);
        AddBuildingZotProp(lot, 0x1c430000, 5);
        return next <= 2;
    }
    target->SetValue(0);
    PHItemB_ab1b98* other = static_cast<PHB_ab1b98*>(l->AsPropertyHolder())->Query(0xc999c45e);
    if (other) {
        PHTargetB_ab1b98* t2 = other->Get();
        uint32_t v = *t2->GetValueSlot73();
        if (v == 5) {
            RemoveLotProp(lot, v);
            t2->SetValue(0);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c9480 score 136
void* cSC4LotDeveloper::GetFoundationByStandardCityCell(uint32_t id, uint32_t x, uint32_t z)
{
    int32_t first[2];
    int32_t second[2];
    first[0] = x;
    first[1] = z;
    second[0] = x;
    second[1] = z;
    FoundB_ab1b98* result = 0;
    List_ab1b98 list;
    list.mpHead = NewListHead_ab1b98();
    if (static_cast<OccMgrB_ab1b98*>(mpOccupantManager)->GetOccupants(&list, first, second, 0x68fd0c69, -1)) {
        for (ListNode_ab1b98* n = list.mpHead->mpNext; n != list.mpHead; n = n->mpNext) {
            Occ_ab1b98* o = reinterpret_cast<Occ_ab1b98*>(n->mpData);
            if (!result) {
                FoundB_ab1b98* found;
                if (o->QueryInterface(0xc8fce101, reinterpret_cast<void**>(&found))) {
                    if (found->Fn9() == static_cast<int32_t>(id)) {
                        result = found;
                    }
                    found->Release();
                }
            }
            o->Release();
        }
    }
    FreeListNodes_ab1b98(list.mpHead);
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006c98c0 score 55
void cSC4LotDeveloper::AddBuildingZotProp(void* lot, uint32_t id, uint32_t amount)
{
    LotB_ab1b98* l = static_cast<LotB_ab1b98*>(lot);
    void* building = l->GetBuilding();
    CfgC_ab1b98* config = static_cast<CfgC_ab1b98*>(l->GetLotConfiguration());
    uint32_t extent;
    if (config) {
        extent = config->Fn24();
    } else {
        extent = 0;
    }
    if (amount == 6) {
        Fn005f98c0(0x4c04de69, 1, 0, 0, 0, lot);
    }
    PHB_ab1b98* ph = static_cast<PHB_ab1b98*>(l->AsPropertyHolder());
    PHItemB_ab1b98* item = ph->Query(0xc999c45e);
    if (!item) {
        ph->SetProperty(0xc999c45e, 0, 0);
        item = ph->Query(0xc999c45e);
    }
    PHTargetB_ab1b98* target = item->Get();
    uint32_t current = *target->GetValueSlot73();
    if (current != 0) {
        if (current >= amount) {
            return;
        }
        RemoveLotProp(lot, current);
    }
    target->SetValue(amount);
    float pos[3];
    float height;
    if (building && config && extent) {
        float unused[3];
        GetPositionForBuilding(lot, pos, &extent);
        static_cast<BldB_ab1b98*>(l->GetBuilding())->Fn3()->Fn10(unused, &height);
    } else {
        l->GetCenter(pos);
        height = pos[1];
    }
    pos[1] = height + 3.0f;
    PropObjB_ab1b98* prop = static_cast<PropMgrB_ab1b98*>(mpPropManager)->CreateProp(id, pos, gpB43dd8->mn10);
    prop->Fn12(3);
    prop->Fn6()->SetProperty(0x48e95539, amount, 0);
}
#endif

struct HolderItemB_ab1b98;
struct HolderTargetB_ab1b98;
struct RmB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual bool Find(void*, uint32_t, void*, uint32_t, uint32_t);
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
    virtual bool Exists(void*);
};
struct RmOutB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual uint32_t Release();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void* GetHolder();
};
struct HolderB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual HolderItemB_ab1b98* Query(uint32_t);
};
struct HolderItemB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual HolderTargetB_ab1b98* Get();
};
struct HolderTargetB_ab1b98 {
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
    virtual void P39();
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual void P48();
    virtual void P49();
    virtual void P50();
    virtual void P51();
    virtual void P52();
    virtual void P53();
    virtual void P54();
    virtual void P55();
    virtual void P56();
    virtual void P57();
    virtual void P58();
    virtual void P59();
    virtual void P60();
    virtual void P61();
    virtual void P62();
    virtual void P63();
    virtual void P64();
    virtual void P65();
    virtual void P66();
    virtual void P67();
    virtual void P68();
    virtual void P69();
    virtual void P70();
    virtual void P71();
    virtual void P72();
    virtual void P73();
    virtual void P74();
    virtual void P75();
    virtual void P76();
    virtual void P77();
    virtual void P78();
    virtual void P79();
    virtual void P80();
    virtual void P81();
    virtual void P82();
    virtual void P83();
    virtual void P84();
    virtual void P85();
    virtual void P86();
    virtual void P87();
    virtual void P88();
    virtual void P89();
    virtual void P90();
    virtual void P91();
    virtual void P92();
    virtual void P93();
    virtual void P94();
    virtual void P95();
    virtual void P96();
    virtual void P97();
    virtual void P98();
    virtual void P99();
    virtual void P100();
    virtual void P101();
    virtual void P102();
    virtual void P103();
    virtual void P104();
    virtual void P105();
    virtual void P106();
    virtual void P107();
    virtual void P108();
    virtual void P109();
    virtual void P110();
    virtual float* GetTriple();
};
// GLOBAL: 0x00b43ca8
extern RmB_ab1b98* gpB43ca8;
// STUB: 0x005fd420
bool Fn005fd420(void* holder, uint32_t id, uint16_t* value);
// STUB: 0x005fd4f0
bool Fn005fd4f0(void* holder, uint32_t id, float* value);
// STUB: 0x005fd390
bool Fn005fd390(void* holder, uint32_t id, bool* value);
struct CurveB_ab1b98 {
    // STUB: 0x005f4620
    void SetData(void* property);
};

// FUNCTION: 0x006c4a20
void cSC4LotDeveloper::ReadSimulatorTunableValues()
{
    RmOutB_ab1b98* out;
    uint32_t key[3];
    key[0] = 0x6534284a;
    key[1] = 0xe7e2c2db;
    key[2] = 0xe8da7677;
    if (gpB43ca8->Find(key, 0xa52160f5, &out, 0, 0)) {
        void* holder = out->GetHolder();
        Fn005fd420(holder, 0x47e2c400, &mnC0);
        mfCC = 0.2f;
        mfC8 = 0.4f;
        mfC4 = 0.6f;
        HolderItemB_ab1b98* item = static_cast<HolderB_ab1b98*>(holder)->Query(0x47e2c401);
        if (item) {
            float* triple = item->Get()->GetTriple();
            mfCC = triple[0];
            mfC8 = triple[1];
            mfC4 = triple[2];
        }
        Fn005fd4f0(holder, 0xe900ea24, &mfd0);
        Fn005fd4f0(holder, 0xe900ea25, &mfd4);
        Fn005fd480(holder, 0xe900ea26, &mnLotFoundationId);
        Fn005fd480(holder, 0x6916516b, &mnFoundationId);
        Fn005fd390(holder, 0xe900ea27, &mbE0);
        Fn005fd390(holder, 0xe900ea28, &mbE1);
        Fn005fd4f0(holder, 0xe900ea29, &mfe4);
        Fn005fd4f0(holder, 0xe900ea2a, &mfe8);
        Fn005fd480(holder, 0xe900ea2b, &mnQueueTicks);
        Fn005fd480(holder, 0xe900ea2c, &mnQueueBatch);
        HolderItemB_ab1b98* curve = static_cast<HolderB_ab1b98*>(holder)->Query(0x2a2d7824);
        if (curve) {
            reinterpret_cast<CurveB_ab1b98*>(mCurve)->SetData(curve);
        }
        out->Release();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x006c8ab0 score 11
bool cSC4LotDeveloper::AddLotFoundation_2(void* lot, uint32_t id, bool useLotAltitude, bool level, bool walls)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    float center[3];
    int32_t rect[4];
    l->GetCenter(center);
    l->GetBoundingRect(rect);
    int32_t facing = l->GetFacing();
    float width = static_cast<float>((rect[2] - rect[0] + 1) * 16);
    float depth = static_cast<float>((rect[3] - rect[1] + 1) * 16);
    float bottom = Fn006c7630(lot);
    float baseAltitude = GetLowestOrHighestAreaAltitude(rect, false, true);
    if (useLotAltitude) {
        center[1] = l->GetAltitude();
    } else {
        float corners[4];
        Fn006c4360(rect, corners, true);
        center[1] = PickLotFoundationAltitude(lot, bottom, baseAltitude, corners);
    }
    if (level) {
        if (rect[2] - rect[0] > 1 && rect[3] - rect[1] > 1) {
            LevelAreaInternalVertices(rect, center[1] - 0.5f, true, true, lot);
        }
        LevelBorderingVertices(rect, center[1], true, lot);
    }
    bool result = static_cast<BuildSim_ab1b98*>(mpBuildingDevSim)->AddFoundation(id, 2, center, width, depth, facing, bottom);
    l->SetAltitude(center[1]);
    l->SetFlags((l->GetFlags() & 0xfffffffb) | 3);
    if (walls && center[1] < baseAltitude) {
        Fn005e3070(lot, true);
        UpdateSurroundingLotFoundations(lot);
        Fn005e3960(lot);
    }
    return result;
}
#endif

struct BldObjC_ab1b98;
struct BuildSimC_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual BldObjC_ab1b98* CreateBuilding(uint32_t, void*, uint32_t);
};
struct BldObjC_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void* GetRoot();
};

// FUNCTION: 0x006c5210
void cSC4LotDeveloper::ChangeBuilding(void* lot, uint32_t id)
{
    Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
    LotCfgB_ab1b98* config = static_cast<LotCfgB_ab1b98*>(l->GetLotConfiguration());
    if (config) {
        ClearLotBuildings(lot, 1, true, 0);
        uint32_t out = 0;
        float pos[3];
        GetPositionForBuilding(lot, pos, &out);
        BldObjC_ab1b98* building = static_cast<BuildSimC_ab1b98*>(mpBuildingDevSim)->CreateBuilding(id, pos, out);
        if (building) {
            bool locked = (l->GetFlags() & 3) != 0;
            bool flag = config->Fn14();
            if (!locked) {
                float score = GetOccupantSlope(building->GetRoot(), flag);
                if (score > mfd4) {
                    int32_t rect[4];
                    GetOccupantCellCoverage(building->GetRoot(), rect);
                    if (AttemptAreaLevelling(rect, mfd4, true, flag, mfe8, lot)) {
                        score = GetOccupantSlope(building->GetRoot(), flag);
                    }
                    if (score > mfd4) {
                        AddBuildingFoundation(building, config);
                    }
                }
            }
        }
        l->SetState(3, 0, 0);
    }
}

struct DesirObjB_ab1b98;
struct DesirGridB_ab1b98;
struct BuildSimD_ab1b98 {
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
    virtual uint32_t Fn30(uint32_t, uint32_t);
    virtual void P31();
    virtual DesirObjB_ab1b98* Fn32(uint32_t);
};
struct DesirObjB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual int32_t Fn7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual DesirGridB_ab1b98* Fn13();
};
struct DesirGridB_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual int16_t Fn7(int32_t, int32_t);
};
struct RandomB_ab1b98 {
    uint8_t mPad[0x14];
    // STUB: 0x00913a5c
    void Init(uint32_t seed);
    // STUB: 0x009136ca
    int32_t Range(int32_t lo, int32_t hi);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006c47c0 score 112
bool cSC4LotDeveloper::TestDesirability(void* lot, int32_t x, int32_t z)
{
    LotB_ab1b98* l = static_cast<LotB_ab1b98*>(lot);
    PHB_ab1b98* ph = static_cast<PHB_ab1b98*>(l->AsPropertyHolder());
    PHItemB_ab1b98* item = ph->Query(0xc999e206);
    if (!item) {
        ph->SetProperty(0xc999e206, 0, 0);
        item = ph->Query(0xc999e206);
    }
    PHTargetB_ab1b98* target = item->Get();
    uint32_t level = *target->GetValueSlot73();
    if (static_cast<Lot_ab1b98*>(lot)->IsInLivableState()) {
        BuildSimD_ab1b98* sim = static_cast<BuildSimD_ab1b98*>(mpBuildingDevSim);
        Profile_ab1b98* profile = static_cast<BuildSimB_ab1b98*>(mpBuildingDevSim)->GetProfile(l->GetBuildingType(false));
        uint32_t wealth = static_cast<Lot_ab1b98*>(lot)->GetOccupantWealth();
        DesirObjB_ab1b98* obj = sim->Fn32(sim->Fn30(profile->mn0, wealth));
        if (obj) {
            if (obj->Fn7() == 5) {
                return true;
            }
            int16_t value = obj->Fn13()->Fn7(x, z);
            if (static_cast<float>(value) * 0.01f < mfCC) {
                RandomB_ab1b98 random;
                random.Init((x << 16) + z);
                int32_t roll = random.Range(0, 7);
                uint32_t next = level + 1;
                target->SetValue(next);
                return next <= static_cast<uint32_t>(roll + 2);
            }
        }
    }
    target->SetValue(0);
    return true;
}
#endif

struct U32Vec_ab1b98 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
};

#ifdef OB_DRAFTS
// CLOSE: 0x006c60c0 score 93
uint32_t cSC4LotDeveloper::PickLotBaseTextureForLot(void* lot, void* textures)
{
    U32Vec_ab1b98* v = static_cast<U32Vec_ab1b98*>(textures);
    if (v->mpBegin != v->mpEnd) {
        uint32_t picked = v->mpBegin[g00b49af0.Uniform(static_cast<uint32_t>(v->mpEnd - v->mpBegin))];
        Lot_ab1b98* l = static_cast<Lot_ab1b98*>(lot);
        uint32_t wealth = l->GetOccupantWealth();
        uint32_t stage = 0;
        switch (l->GetCondition()) {
        case 0:
        case 1:
            stage = 0;
            break;
        case 2:
        case 3:
            stage = 1;
            break;
        case 4:
        case 5:
        case 6:
            stage = 2;
            break;
        }
        if (wealth == 0) {
            uint32_t type = l->GetBuildingType(false);
            if (type) {
                wealth = static_cast<BuildSim_ab1b98*>(mpBuildingDevSim)->GetProfile(type)->mn4;
            } else {
                wealth = 1;
            }
        }
        RmB_ab1b98* rm = gpB43ca8;
        uint32_t high = picked & 0xffff0000;
        uint32_t key[3];
        key[0] = 0x7ab50e44;
        key[1] = 0x986135e;
        key[2] = (((wealth << 4) | stage) << 8) | high;
        if (rm->Exists(key)) {
            return key[2];
        }
        key[2] = (wealth << 12) | high;
        if (rm->Exists(key)) {
            return key[2];
        }
        key[2] = (stage << 8) | high;
        if (rm->Exists(key)) {
            return key[2];
        }
        return picked;
    }
    return 0;
}
#endif

// GLOBAL: 0x00b43d0c
extern OccMgrB_ab1b98* gpB43d0c;

#ifdef OB_DRAFTS
// CLOSE: 0x006c95e0 score 133
void* cSC4LotDeveloper::GetFoundationByPosition(uint32_t id, float x, float z)
{
    FoundB_ab1b98* result = 0;
    List_ab1b98 list;
    list.mpHead = NewListHead_ab1b98();
    float high[3];
    float low[3];
    high[0] = x - 0.05f;
    high[2] = z + 0.05f;
    low[0] = x - 0.05f;
    low[1] = -FLT_MAX;
    low[2] = z + 0.05f;
    high[1] = FLT_MAX;
    if (!mpOccupantManager) {
        mpOccupantManager = gpB43d0c;
        gpB43d0c->AddRef();
    }
    if (static_cast<OccMgrB_ab1b98*>(mpOccupantManager)->GetOccupantsF(&list, low, high, 0x68fd0c69, -1)) {
        for (ListNode_ab1b98* n = list.mpHead->mpNext; n != list.mpHead; n = n->mpNext) {
            Occ_ab1b98* o = reinterpret_cast<Occ_ab1b98*>(n->mpData);
            FoundB_ab1b98* found = 0;
            if (!result) {
                if (o->QueryInterface(0xc8fce101, reinterpret_cast<void**>(&found))) {
                    if (found->Fn9() == static_cast<int32_t>(id)) {
                        result = found;
                    }
                    found->Release();
                }
            }
            o->Release();
        }
    }
    FreeListNodes_ab1b98(list.mpHead);
    return result;
}
#endif

struct LotD_ab1b98 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void* AsPropertyHolder();
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
    virtual uint32_t GetState();
    virtual void P34();
    virtual uint32_t GetCondition();
    virtual void P36();
    virtual void P37();
    virtual void P38();
    virtual void P39();
    virtual uint32_t GetDaysSinceLastStateChange();
    virtual uint32_t GetOccupantWealth();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual uint32_t GetBuildingType(bool);
    virtual void P47();
    virtual void P48();
    virtual void P49();
    virtual void P50();
    virtual void P51();
    virtual void P52();
    virtual void P53();
    virtual void P54();
    virtual void P55();
    virtual void P56();
    virtual void P57();
    virtual void P58();
    virtual void P59();
    virtual void P60();
    virtual void GetOccupancy(float*);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006c4630 score 106
uint32_t cSC4LotDeveloper::Fn006c4630(void* lot, uint32_t, uint32_t)
{
    LotD_ab1b98* l = static_cast<LotD_ab1b98*>(lot);
    int32_t state = static_cast<int32_t>(l->GetState());
    uint32_t condition = l->GetCondition();
    switch (state) {
    case 3: {
        BuildSimB_ab1b98* sim = static_cast<BuildSimB_ab1b98*>(mpBuildingDevSim);
        Profile_ab1b98* profile = sim->GetProfile(l->GetBuildingType(false));
        int32_t delta = profile->mn4 - static_cast<int32_t>(l->GetOccupantWealth());
        bool flag = static_cast<int32_t>(condition - 1) > delta;
        if (flag || l->GetDaysSinceLastStateChange() > mnC0) {
            float occupancy;
            l->GetOccupancy(&occupancy);
            if (occupancy < mfC8 || (flag && occupancy < mfC4)) {
                delta++;
            }
        }
        if (delta > 2) {
            return 3;
        }
        if (delta == 0) {
            PHItemB_ab1b98* item = static_cast<PHB_ab1b98*>(l->AsPropertyHolder())->Query(0xe999b11f);
            if (item && *item->Get()->GetValueSlot73() != 0) {
                return 1;
            }
            return 0;
        }
        if (delta > 0) {
            return delta + 1;
        }
        break;
    }
    case 4:
        if (condition == 0) {
            condition = 1;
        }
        if (l->GetDaysSinceLastStateChange() > mnC0) {
            switch (condition) {
            case 0:
            case 1:
                condition = 2;
                break;
            case 2:
                condition = 3;
                break;
            case 3:
                condition = 4;
                break;
            }
        }
        break;
    }
    return condition;
}
#endif

struct FloraObjB_ab1b98;
struct FloraB_ab1b98 {
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
    virtual FloraObjB_ab1b98* Fn17(void*, void*, uint32_t);
};
struct FloraObjB_ab1b98 {
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
    virtual void Fn28(uint32_t);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006cd2b0 score 64
void cSC4LotDeveloper::Fn006cd2b0(void* config, void* lot, void* extra)
{
    ConfVec_ab1b98* objects = static_cast<Conf_ab1b98*>(config)->GetObjects();
    if (objects) {
        int32_t count = static_cast<int32_t>(objects->mpEnd - objects->mpBegin);
        for (int32_t i = 0; i < count; i++) {
            ConfObj_ab1b98* o = objects->mpBegin + i;
            if (o->mPad[0] == 4) {
                float posA[3];
                float posB[3];
                posA[0] = g00b49aec;
                posA[1] = g00b49aec;
                posA[2] = g00b49aec;
                GetPositionForLotConfigurationObject(lot, extra, o, posA, posB);
                void* found = Fn006cd010(o->mTail, posA);
                if (found) {
                    FloraObjB_ab1b98* flora = static_cast<FloraB_ab1b98*>(mpFloraSim)->Fn17(found, posB, 0);
                    if (flora) {
                        flora->Fn28(o->mn24);
                    }
                }
            }
        }
    }
}
#endif
