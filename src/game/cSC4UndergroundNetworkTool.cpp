#include <algorithm>
#include <cmath>
#include <list>
#include <vector>

#include "classes/cSC4UndergroundNetworkTool.h"

// The original keeps a hash set of cell vertices (STLport hash_set); elsewhere the standard unordered set does the same.
#ifdef _MSC_VER
#include <hash_set>
typedef std::hash_set<uint32_t> UintSet_aaa950;
#else
#include <unordered_set>
typedef std::unordered_set<uint32_t> UintSet_aaa950;
#endif

struct Occ_aaa950;
struct CellInfo_aaa950;
struct ObjX_aaa950;
struct Sub_aaa950;

struct QiSub_aaa950;

// The secondary interface of an underground occupant, at +4 of the object.
struct Sub_aaa950 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Fn17(uint32_t, uint32_t);
};

// What the occupant's slot 48 returns.
struct ObjX_aaa950 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Fn31(uint32_t);
    virtual void Pad32();
    virtual uint32_t Fn33();
};

// An underground occupant's first interface.
struct OccBase_aaa950 {
    virtual bool QueryInterface(uint32_t, QiSub_aaa950**);
    virtual void Pad01();
    virtual void Release();
    virtual void Pad03();
    virtual void Fn04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual bool Fn08(uint32_t);
    virtual void Pad09();
    virtual void Fn10(uint32_t);
    virtual void Fn11(uint32_t);
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual uint32_t Fn23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Fn34(float*);
    virtual void Pad35();
    virtual void Pad36();
    virtual void Fn37(uint32_t, uint32_t);
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual ObjX_aaa950* Fn48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual void Pad55();
    virtual void Pad56();
    virtual void Pad57();
    virtual void Pad58();
    virtual void Fn59(void*, void*);
    virtual void Pad60();
    virtual void Pad61();
    virtual void Pad62();
    virtual void Pad63();
    virtual void Pad64();
    virtual void Pad65();
    virtual void Pad66();
    virtual void Pad67();
    virtual void Pad68();
    virtual void Pad69();
    virtual void Pad70();
    virtual void Pad71();
    virtual void Pad72();
    virtual void Pad73();
    virtual void Pad74();
    virtual void Pad75();
    virtual void Pad76();
    virtual void Pad77();
    virtual void Pad78();
    virtual void Pad79();
    virtual void Pad80();
    virtual void Pad81();
    virtual void Pad82();
    virtual void Pad83();
    virtual void Fn84(const float*);
    virtual void Pad85();
    virtual void Fn86(bool);
    virtual void Pad87();
    virtual void Pad88();
    virtual void Pad89();
    virtual void Pad90();
    virtual void Fn91(uint32_t);
    virtual void Pad92();
    virtual void Pad93();
    virtual void Pad94();
    virtual void Pad95();
    virtual void Pad96();
    virtual void Pad97();
    virtual void Pad98();
    virtual void Pad99();
    virtual void Pad100();
    virtual void Pad101();
    virtual void Pad102();
    virtual void Pad103();
    virtual void Pad104();
    virtual void Pad105();
    virtual void Pad106();
    virtual void Pad107();
    virtual void Pad108();
    virtual void Pad109();
    virtual void Pad110();
};

// An underground occupant: the first interface, then the second one at +4.
struct Occ_aaa950 : public OccBase_aaa950, public Sub_aaa950 {
};

// The object the tool keeps at +0x44.
struct Terrain_aaa950 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual float Fn12(uint32_t);
};

// The object the tool keeps at +0x48.
struct Tool48_aaa950 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual bool Fn20(Sub_aaa950*, uint32_t);
    virtual void Fn21(Sub_aaa950*, uint32_t, uint32_t);
};

// A queried interface of an occupant.
struct QiSub_aaa950 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual void Pad55();
    virtual void Pad56();
    virtual void Pad57();
    virtual void Pad58();
    virtual void Pad59();
    virtual void Pad60();
    virtual void Pad61();
    virtual void Pad62();
    virtual void Pad63();
    virtual void Pad64();
    virtual void Pad65();
    virtual void Pad66();
    virtual void Pad67();
    virtual void Pad68();
    virtual void Pad69();
    virtual void Pad70();
    virtual void Pad71();
    virtual void Pad72();
    virtual void Pad73();
    virtual void Pad74();
    virtual void Pad75();
    virtual void Pad76();
    virtual void Pad77();
    virtual void Pad78();
    virtual void Pad79();
    virtual void Pad80();
    virtual void Pad81();
    virtual void Pad82();
    virtual void Pad83();
    virtual void Pad84();
    virtual void Pad85();
    virtual void Pad86();
    virtual void Pad87();
    virtual void Pad88();
    virtual void Pad89();
    virtual void Pad90();
    virtual void Pad91();
    virtual void Fn92(bool*, bool*, bool*);
};

// A resource, as the resource manager hands it out (any object with Release in slot 2 reads the same).
struct Res_aaa950 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void* Fn07();
};

struct Key_aaa950 {
    uint32_t mType;
    uint32_t mGroup;
    uint32_t mInstance;
};

// The resource manager behind the global at 0xb43ca8: only slot 3 is used here.
struct RM_aaa950 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual bool Fn03(const Key_aaa950*, uint32_t, Res_aaa950**, uint32_t, uint32_t);
};

// GLOBAL: 0x00b43ca8
extern RM_aaa950* gpB43ca8_aaa950;

// GLOBAL: 0x00aaa8fc
extern uint32_t gAaa8fc_aaa950[];

// STUB: 0x005fd4f0
void GetPropFloat_aaa950(void* holder, uint32_t id, float* out);

// STUB: 0x005fd390
void GetPropBool_aaa950(void* holder, uint32_t id, bool* out);

// STUB: 0x006584d0
bool FindUndergroundOccupant_aaa950(int32_t x, int32_t y, Occ_aaa950** out, uint32_t type);

// STUB: 0x006585e0
bool FindUndergroundConnectionOccupant_aaa950(int32_t x, int32_t y, uint32_t type, Res_aaa950** out);

// STUB: 0x0090cf63
void StlDelete_aaa950(void* p);

// STUB: 0x0090cf54
void* StlNew_aaa950(uint32_t size);

// The height constraint solver the tool keeps at +0x124.
struct Sat_aaa950 {
    // STUB: 0x0065eb00
    bool GetHeight(int32_t vertex, float* out) const;
    // STUB: 0x0065fdb0
    void InsertEqualityConstraint(int32_t a, int32_t b);
    // STUB: 0x00660360
    void InsertFixedVertex(int32_t vertex, float height);
    // STUB: 0x0065fb60
    void AddVertexToSolve(int32_t vertex, float height);
    // STUB: 0x0065fed0
    void InsertRangeConstraint(int32_t vertex, float lo, float hi);
    // STUB: 0x0065ebe0
    void InsertPreferredRangeConstraint(int32_t vertex, float lo, float hi);
    // STUB: 0x0065eb90
    void InsertPreferredValueConstraint(int32_t vertex, float height);
};

// One cell of the network (0xbc bytes).
struct CellInfo_aaa950 {
    int32_t mX;              // 0x00
    int32_t mY;              // 0x04
    uint32_t mFlags;         // 0x08
    Occ_aaa950* mpOcc;       // 0x0c
    bool mbB10;              // 0x10
    uint8_t mPad11[3];
    int32_t mnIndex;         // 0x14
    uint32_t mTab18[14];     // 0x18
    uint8_t mPad50;          // 0x50
    bool mbB51;              // 0x51
    bool mbB52;              // 0x52
    bool mbB53;              // 0x53
    bool mbB54;              // 0x54
    bool mbB55;              // 0x55
    bool mbB56;              // 0x56
    bool mbB57;              // 0x57
    float mfBase[4];         // 0x58
    float mfTab[16];         // 0x68
    int32_t mVert[4];        // 0xa8
    int32_t mnB8;            // 0xb8
    CellInfo_aaa950() {}
    // STUB: 0x00647850
    void Fn00647850();
    // STUB: 0x006478a0
    CellInfo_aaa950(const CellInfo_aaa950& other);
    // STUB: 0x00632d50
    CellInfo_aaa950& operator=(const CellInfo_aaa950& other);
    ~CellInfo_aaa950()
    {
        if (mpOcc) {
            mpOcc->Release();
        }
    }
};

// The cell cache the tool keeps at +0x1c.
struct Cache_aaa950 {
    // STUB: 0x00647e60
    void GetAllCells(std::vector<CellInfo_aaa950>& out);
    // STUB: 0x00647e10
    CellInfo_aaa950& Fn00647e10(uint32_t key);
};

struct Range_aaa950 {
    uint32_t mStart;
    uint32_t mEnd;
    int32_t mnFlag;
};

struct Point_aaa950 {
    int32_t mX;
    int32_t mY;
};

struct SolvedCell_aaa950 {
    uint32_t mType;
    uint32_t mField4;
    uint32_t mKey;
};

typedef std::list<Occ_aaa950*> OccList_aaa950;

struct ListNode_aaa950 {
    ListNode_aaa950* mpNext;
    ListNode_aaa950* mpPrev;
    Occ_aaa950* mpData;
};

// The base class's data, by offset from the object.
struct View_aaa950 {
    uint8_t mPad00[0x1c];
    Cache_aaa950 mCache;                // 0x1c
    uint8_t mPad1d[0x44 - 0x1d];
    Terrain_aaa950* mpTerrain;          // 0x44
    Tool48_aaa950* mpTool48;            // 0x48
    uint8_t mPad4c[4];
    bool mbB50;                         // 0x50
    uint8_t mPad51[3];
    Range_aaa950* mpRanges;             // 0x54
    uint8_t mPad58[8];
    Point_aaa950* mpPoints;             // 0x60
    uint8_t mPad64[0x14];
    int32_t mnRanges;                   // 0x78
    uint8_t mPad7c[0x98 - 0x7c];
    SolvedCell_aaa950* mpSolvedBegin;   // 0x98
    SolvedCell_aaa950* mpSolvedEnd;     // 0x9c
    uint8_t mPada0[0x124 - 0xa0];
    Sat_aaa950 mSat;                    // 0x124
    uint8_t mPad125[0x208 - 0x125];
    uint32_t mn208;                     // 0x208
    uint8_t mPad20c[0x248 - 0x20c];
    int32_t mnWidth;                    // 0x248
    uint8_t mPad24c[0x2a4 - 0x24c];
    float mf2a4;                        // 0x2a4
    uint8_t mPad2a8[0x2c4 - 0x2a8];
    float mf2c4;                        // 0x2c4
    uint8_t mPad2c8[0x35c - 0x2c8];
    uint32_t mnTabIndex;                // 0x35c
};

#ifdef _MSC_VER
typedef char ob_chk_44_aaa950[offsetof(View_aaa950, mpTerrain) == 0x44 ? 1 : -1];
typedef char ob_chk_78_aaa950[offsetof(View_aaa950, mnRanges) == 0x78 ? 1 : -1];
typedef char ob_chk_98_aaa950[offsetof(View_aaa950, mpSolvedBegin) == 0x98 ? 1 : -1];
typedef char ob_chk_124_aaa950[offsetof(View_aaa950, mSat) == 0x124 ? 1 : -1];
typedef char ob_chk_2a4_aaa950[offsetof(View_aaa950, mf2a4) == 0x2a4 ? 1 : -1];
typedef char ob_chk_35c_aaa950[offsetof(View_aaa950, mnTabIndex) == 0x35c ? 1 : -1];
#endif

inline Sub_aaa950* SubOf_aaa950(Occ_aaa950* occ)
{
    return reinterpret_cast<Sub_aaa950*>(reinterpret_cast<uint8_t*>(occ) + 4);
}

inline ListNode_aaa950* ListHead_aaa950(void* p)
{
    return static_cast<ListNode_aaa950*>(p);
}


// FUNCTION: 0x00648f20
float cSC4UndergroundNetworkTool::GetNetworkHeightForTerrainHeight(uint32_t a)
{
    float height = *reinterpret_cast<float*>(&a);
    return height - mfDepthOffset;
}

// FUNCTION: 0x00648f30
uint32_t cSC4UndergroundNetworkTool::UpdateOccupantHighlights(uint32_t a)
{
    return a;
}

// FUNCTION: 0x00657740
void cSC4UndergroundNetworkTool::CreateNetworkOccupant(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    void** out = reinterpret_cast<void**>(b);
    if (out) {
        void* occupant;
        Slot82_aaa950(a, &occupant, c, d);
        *out = occupant;
    }
}

// FUNCTION: 0x00657770
bool cSC4UndergroundNetworkTool::Init()
{
    if (!mbInitialized) {
        mbInitialized = true;
        cSC4NetworkTool::Init();
    }
    return true;
}

// FUNCTION: 0x00657790
float cSC4UndergroundNetworkTool::GetNetworkVertexHt(uint32_t a)
{
    View_aaa950* v = reinterpret_cast<View_aaa950*>(this);
    float height;
    if (v->mSat.GetHeight(a, &height)) {
        return height;
    }
    return v->mpTerrain->Fn12(a) - mfDepthOffset;
}

// FUNCTION: 0x00657860
void cSC4UndergroundNetworkTool::InsertNetworkSpecificConstraintsForCell(uint32_t a)
{
    CellInfo_aaa950* cell = static_cast<CellInfo_aaa950*>(Fn00633220(a));
    if (cell && !cell->mbB53) {
        uint32_t type;
        if (cell->mbB57) {
            type = reinterpret_cast<View_aaa950*>(this)->mpSolvedBegin[cell->mnB8].mType;
        } else {
            if (!cell->mpOcc) {
                return;
            }
            Occ_aaa950* occ = cell->mpOcc;
            type = occ->Fn23();
            uint32_t outA;
            uint32_t outB;
            cell->mpOcc->Fn59(&outB, &outA);
        }
        switch (type) {
        case 0:
        case 0x200:
        case 0x300:
        case 0x800:
        case 0xa00:
        case 0x1400:
        case 0x4b00:
        case 0x14e00:
            return;
        }
        int32_t offset = cell->mbB56 ? 100000 : 0;
        for (int32_t i = 0; i < 3; i++) {
            int32_t to = cell->mVert[(i + 1) & 3] + offset;
            int32_t from = cell->mVert[i] + offset;
            if (from != to && from >= 0 && to >= 0) {
                reinterpret_cast<View_aaa950*>(this)->mSat.InsertEqualityConstraint(from, to);
            }
        }
    }
}

// FUNCTION: 0x00657980
void cSC4UndergroundNetworkTool::ReloadNetworkSpecificInfo(uint32_t a)
{
    Key_aaa950 key;
    key.mType = 0x6534284a;
    key.mGroup = 0x84344e0;
    key.mInstance = a;
    Res_aaa950* res;
    if (gpB43ca8_aaa950->Fn03(&key, 0xa52160f5, &res, 0, 0)) {
        void* holder = res->Fn07();
        GetPropFloat_aaa950(holder, 0xa96e5641, &mfDepthOffset);
        GetPropFloat_aaa950(holder, 0x496e564c, &mfF370);
        GetPropFloat_aaa950(holder, 0x96e5653, &mfF378);
        GetPropBool_aaa950(holder, 0x496e5a36, &mbB374);
        res->Release();
    }
}

// FUNCTION: 0x00657a30
void cSC4UndergroundNetworkTool::SetQuadTrianglesToDraw(uint32_t a, uint32_t /*unused*/)
{
    Occ_aaa950* occupant = reinterpret_cast<Occ_aaa950*>(a);
    QiSub_aaa950* iface = 0;
    if (occupant->QueryInterface(0x4a10afc2, &iface)) {
        occupant->Fn11(0x1000000);
        occupant->Fn11(0x2000000);
        occupant->Fn11(0x4000000);
        bool first;
        bool second;
        bool third;
        iface->Fn92(&first, &second, &third);
        if (first) {
            occupant->Fn10(0x1000000);
        }
        if (!second) {
            occupant->Fn10(0x2000000);
        }
        if (!third) {
            occupant->Fn10(0x4000000);
        }
    }
    if (iface) {
        iface->Release();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00657af0 score 18
bool cSC4UndergroundNetworkTool::Shutdown()
{
    if (mbInitialized) {
        mbInitialized = false;
        if (ListHead_aaa950(mpOccListA)->mpNext != ListHead_aaa950(mpOccListA)) {
            ListNode_aaa950* end = ListHead_aaa950(mpOccListA);
            for (ListNode_aaa950* n = end->mpNext; n != end; n = n->mpNext) {
                n->mpData->Release();
            }
        }
        for (ListNode_aaa950* n = ListHead_aaa950(mpOccListA)->mpNext; n != ListHead_aaa950(mpOccListA);) {
            ListNode_aaa950* cur = n;
            n = n->mpNext;
            StlDelete_aaa950(cur);
        }
        ListHead_aaa950(mpOccListA)->mpNext = ListHead_aaa950(mpOccListA);
        ListHead_aaa950(mpOccListA)->mpPrev = ListHead_aaa950(mpOccListA);
        if (ListHead_aaa950(mpOccListB)->mpNext != ListHead_aaa950(mpOccListB)) {
            ListNode_aaa950* end = ListHead_aaa950(mpOccListB);
            for (ListNode_aaa950* n = end->mpNext; n != end; n = n->mpNext) {
                n->mpData->Release();
            }
        }
        for (ListNode_aaa950* n = ListHead_aaa950(mpOccListB)->mpNext; n != ListHead_aaa950(mpOccListB);) {
            ListNode_aaa950* cur = n;
            n = n->mpNext;
            StlDelete_aaa950(cur);
        }
        ListHead_aaa950(mpOccListB)->mpNext = ListHead_aaa950(mpOccListB);
        ListHead_aaa950(mpOccListB)->mpPrev = ListHead_aaa950(mpOccListB);
        return cSC4NetworkTool::Shutdown();
    }
    return true;
}
#endif

// FUNCTION: 0x00657be0
void cSC4UndergroundNetworkTool::Slot16_aa8748()
{
    View_aaa950* v = reinterpret_cast<View_aaa950*>(this);
    OccList_aaa950& listA = *reinterpret_cast<OccList_aaa950*>(&mpOccListA);
    OccList_aaa950& listB = *reinterpret_cast<OccList_aaa950*>(&mpOccListB);
    OccList_aaa950::iterator endA = listA.end();
    for (OccList_aaa950::iterator it = listA.begin(); it != endA; ++it) {
        Occ_aaa950* occ = *it;
        Sub_aaa950* sub = SubOf_aaa950(occ);
        sub->Fn17(0, 0);
        if (v->mpTool48) {
            if (occ->Fn48()->Fn33() & 1) {
                v->mpTool48->Fn21(sub, 0, v->mn208);
            }
        }
        occ->Fn04();
        occ->Release();
    }
    listA.clear();
    OccList_aaa950::iterator endB = listB.end();
    for (OccList_aaa950::iterator it = listB.begin(); it != endB; ++it) {
        Occ_aaa950* occ = *it;
        occ->Fn17(0, 0);
        occ->Release();
    }
    listB.clear();
    cSC4NetworkTool::Slot16_aa8748();
}

// FUNCTION: 0x00657da0
void cSC4UndergroundNetworkTool::CreateCellInfosForCurrentPlacementTiles(uint32_t /*unused*/)
{
    View_aaa950* v = reinterpret_cast<View_aaa950*>(this);
    for (int32_t i = 0; i < v->mnRanges; i++) {
        for (uint32_t k = v->mpRanges[i].mStart; k <= v->mpRanges[i].mEnd; k++) {
            int32_t x = v->mpPoints[k].mX;
            int32_t y = v->mpPoints[k].mY;
            uint32_t key = (y << 16) + x;
            CellInfo_aaa950* cell = static_cast<CellInfo_aaa950*>(Fn00633220(key));
            if (cell) {
                cell->mFlags |= gAaa8fc_aaa950[v->mnTabIndex];
                cell->mnIndex = i;
                cell->mbB10 = true;
                if (v->mpRanges[i].mnFlag) {
                    cell->mbB53 = true;
                }
                for (int32_t j = 0; j < 4; j++) {
                    float h = v->mpTerrain->Fn12(cell->mVert[j]) - mfDepthOffset;
                    cell->mfTab[j * 2] = h - v->mf2a4;
                    cell->mfTab[j * 2 + 1] = h;
                    float low = std::min(cell->mfBase[j], h);
                    cell->mfTab[j * 2 + 9] = low;
                    cell->mfTab[j * 2 + 8] = low;
                }
            } else {
                CellInfo_aaa950 fresh;
                fresh.Fn00647850();
                fresh.mX = x;
                fresh.mY = y;
                fresh.mFlags = gAaa8fc_aaa950[v->mnTabIndex];
                fresh.mnIndex = i;
                fresh.mbB10 = true;
                fresh.mbB51 = false;
                fresh.mbB53 = v->mpRanges[i].mnFlag != 0;
                fresh.mbB54 = false;
                fresh.mbB55 = v->mpRanges[i].mnFlag == 3;
                fresh.mbB56 = false;
                fresh.mbB52 = false;
                fresh.mVert[0] = v->mnWidth * y + x;
                fresh.mVert[1] = v->mnWidth + fresh.mVert[0];
                fresh.mVert[2] = fresh.mVert[1] + 1;
                fresh.mVert[3] = fresh.mVert[0] + 1;
                for (int32_t j = 0; j < 4; j++) {
                    float h = v->mpTerrain->Fn12(fresh.mVert[j]) - mfDepthOffset;
                    fresh.mfBase[j] = h;
                    fresh.mfTab[j * 2] = h - v->mf2c4;
                    fresh.mfTab[j * 2 + 1] = h;
                    fresh.mfTab[j * 2 + 9] = h;
                    fresh.mfTab[j * 2 + 8] = h;
                }
                v->mCache.Fn00647e10(key) = fresh;
            }
        }
    }
}

// FUNCTION: 0x00658040
void cSC4UndergroundNetworkTool::InsertRangeConstraintsForCell(uint32_t a)
{
    View_aaa950* v = reinterpret_cast<View_aaa950*>(this);
    CellInfo_aaa950* cell = static_cast<CellInfo_aaa950*>(Fn00633220(a));
    if (cell) {
        if (cell->mbB56) {
            cSC4NetworkTool::InsertRangeConstraintsForCell(a);
            return;
        }
        if (cell->mbB53) {
            for (int32_t j = 0; j < 4; j++) {
                v->mSat.InsertFixedVertex(cell->mVert[j], cell->mfBase[j]);
            }
            return;
        }
        for (int32_t j = 0; j < 4; j++) {
            v->mSat.AddVertexToSolve(cell->mVert[j], cell->mfBase[j]);
            UintSet_aaa950& fixedSet = *reinterpret_cast<UintSet_aaa950*>(reinterpret_cast<uint8_t*>(this) + 0xb8);
            uint32_t key = cell->mVert[j];
            if (fixedSet.find(key) != fixedSet.end()) {
                v->mSat.InsertFixedVertex(cell->mVert[j], cell->mfBase[j]);
            } else {
                float h = v->mpTerrain->Fn12(cell->mVert[j]) - mfDepthOffset;
                float lo = std::min(cell->mfTab[j * 2], h);
                v->mSat.InsertRangeConstraint(cell->mVert[j], lo, std::min(cell->mfTab[j * 2 + 1], h));
                v->mSat.InsertPreferredRangeConstraint(cell->mVert[j], std::min(cell->mfTab[j * 2 + 8], h), std::min(cell->mfTab[j * 2 + 9], h));
                if (cell->mbB51) {
                    v->mSat.InsertPreferredValueConstraint(cell->mVert[j], cell->mfBase[j]);
                }
            }
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00658710 score 106
void cSC4UndergroundNetworkTool::StartPlacing()
{
    std::vector<CellInfo_aaa950> cells;
    reinterpret_cast<View_aaa950*>(this)->mCache.GetAllCells(cells);
    std::vector<CellInfo_aaa950>::iterator it = cells.begin();
    std::vector<CellInfo_aaa950>::iterator end = cells.end();
    for (; it != end; ++it) {
        if (!it->mbB54 || it->mbB10) {
            UintSet_aaa950& placedSet = *reinterpret_cast<UintSet_aaa950*>(reinterpret_cast<uint8_t*>(this) + 0xa4);
            uint32_t key = (it->mY << 16) + it->mX;
            if (placedSet.find(key) != placedSet.end()) {
                Occ_aaa950* occ = 0;
                FindUndergroundOccupant_aaa950(it->mX, it->mY, &occ, Slot81_aaa950());
                if (occ) {
                    bool changed = false;
                    if (!occ->Fn08(0x200000)) {
                        float oldHeights[4];
                        occ->Fn34(oldHeights);
                        float newHeights[4];
                        for (int32_t k = 0; k < 4; k++) {
                            newHeights[k] = GetNetworkVertexHt(it->mVert[k]);
                            if (std::fabs(newHeights[k] - oldHeights[k]) > 0.001f) {
                                changed = true;
                            }
                        }
                        if (changed) {
                            occ->Fn84(newHeights);
                            occ->Fn86(true);
                        }
                    }
                    occ->Release();
                }
            }
        }
    }
}
#endif

// FUNCTION: 0x00659410
void cSC4UndergroundNetworkTool::PropagateSolvedCellsForSmoothing()
{
    std::vector<SolvedCell_aaa950>& cells = *reinterpret_cast<std::vector<SolvedCell_aaa950>*>(reinterpret_cast<uint8_t*>(this) + 0x98);
    int32_t count = static_cast<int32_t>(cells.size());
    for (int32_t i = 0; i < count; i++) {
        void* cell = Fn00633220(cells[i].mKey);
        if (cell) {
            Fn00659240(cell, 0);
        }
    }
}

// FUNCTION: 0x00659470
bool cSC4UndergroundNetworkTool::TestForAutoConnectOccupant(uint32_t a, uint32_t b)
{
    Occ_aaa950* occupant = 0;
    Res_aaa950* connection = 0;
    if (FindUndergroundOccupant_aaa950(a, b, &occupant, Slot81_aaa950())) {
        occupant->Release();
        return true;
    }
    if (FindUndergroundConnectionOccupant_aaa950(a, b, Slot81_aaa950(), &connection)) {
        connection->Release();
        return true;
    }
    return false;
}

// FUNCTION: 0x006597e0
void cSC4UndergroundNetworkTool::AddCellPreview(uint32_t a, uint32_t b)
{
    View_aaa950* v = reinterpret_cast<View_aaa950*>(this);
    CellInfo_aaa950* cell = reinterpret_cast<CellInfo_aaa950*>(a);
    if (cell->mbB10) {
        CellInfo_aaa950 copy(*cell);
        float heights[4];
        for (int32_t k = 0; k < 4; k++) {
            int32_t vertex = cell->mVert[k];
            heights[k] = v->mpTerrain->Fn12(vertex);
            copy.mfBase[k] = heights[k] - mfDepthOffset;
        }
        Occ_aaa950* occ;
        OccList_aaa950& listA = *reinterpret_cast<OccList_aaa950*>(&mpOccListA);
        OccList_aaa950& listB = *reinterpret_cast<OccList_aaa950*>(&mpOccListB);
        if (!FindUndergroundOccupant_aaa950(cell->mX, cell->mY, &occ, Slot81_aaa950())) {
            bool flag;
            if (CreateNewUndergroundOccupant(&copy, reinterpret_cast<void*>(b), &occ, &flag)) {
                occ->Fn48()->Fn31(1);
                occ->Fn91(1);
                if (!flag && v->mpTool48) {
                    cell->mbB54 = v->mpTool48->Fn20(occ, v->mn208);
                }
                listA.push_back(occ);
            }
        } else {
            listB.push_back(occ);
        }
        if (occ) {
            SubOf_aaa950(occ)->Fn17(1, 0);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x006599d0 score 23
void cSC4UndergroundNetworkTool::Slot55_aa8748(uint32_t a, uint32_t b, uint32_t c)
{
    View_aaa950* v = reinterpret_cast<View_aaa950*>(this);
    cSC4NetworkTool::Slot55_aa8748(a, b, c);
    if (v->mbB50 || static_cast<uint8_t>(c)) {
        std::vector<SolvedCell_aaa950>& solved = *reinterpret_cast<std::vector<SolvedCell_aaa950>*>(a);
        std::vector<SolvedCell_aaa950>::iterator end = solved.end();
        for (std::vector<SolvedCell_aaa950>::iterator it = solved.begin(); it != end; ++it) {
            CellInfo_aaa950* cell = static_cast<CellInfo_aaa950*>(Fn00633220(it->mKey));
            Occ_aaa950* occ = 0;
            bool flag;
            if (CreateNewUndergroundOccupant(cell, &*it, &occ, &flag)) {
                occ->Fn84(cell->mfBase);
                bool existing = flag;
                occ->Fn86(existing);
                occ->Fn37(v->mnTabIndex, cell->mTab18[v->mnTabIndex]);
                occ->Fn11(0x4000);
                occ->Fn10(0x10000000);
                if (!existing && v->mpTool48) {
                    cell->mbB54 = v->mpTool48->Fn20(occ, v->mn208);
                }
                occ->Release();
                occ = 0;
            }
        }
    }
}
#endif
