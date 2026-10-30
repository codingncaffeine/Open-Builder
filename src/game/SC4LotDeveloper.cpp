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
