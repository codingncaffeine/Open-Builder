#include <cstddef>
#include <set>
#include <vector>
#include "classes/cSC4NetworkTool.h"
#include "common/compiler.h"
#include "game/Globals.h"
#include "gzcom/cRZString.h"

// What the tool's info pointer (offset 0x358) points to.
struct Info_aa8748 {
    uint32_t mn0;
    uint32_t mn4;
    uint32_t mn8;   // the view input control id
    uint32_t mnC;
    uint32_t mn10;  // the tool view id
    uint32_t mn14;  // the cursor id
    uint32_t mn18;  // the directional cursor base
    uint32_t mn1c;  // pen width x
    uint32_t mn20;  // pen width z
    uint32_t mn24;
    uint32_t mn28;
    uint32_t mn2c;
    uint8_t* mpTable30;  // records of 0x178 bytes
};

struct Bridge_aa8748 {
    uint32_t mn0;
    uint32_t mnId;
    uint32_t mnAltitude;
    uint32_t mnReferenceAltitude;
    bool mbLandBridge;
    uint8_t mPad[0xf];
};

// One step of the dragged path: 12 bytes.
struct Step_aa8748 {
    uint32_t mn0;
    uint32_t mn4;
    uint32_t mn8;
};

// An object with a reference and an active flag (a preview, used by Shutdown).
struct Counted_aa8748 {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

struct Holder_aa8748 {
    virtual void P0();
    virtual void P1();
    virtual uint32_t Release();
    uint8_t mPad4[8];
    Counted_aa8748* mpRef;
    uint8_t mPad10[0x44];
    uint8_t mbActive;
    // STUB: 0x0061fbc0
    void Fn0061fbc0();
    void Fn0061fbc0Impl_aa8748();
};

struct Point_aa8748 {
    uint32_t mnX;
    uint32_t mnZ;
};

struct Draw_aa8748 {
    uint32_t mn[5];
};

// The tool seen as plain data (offsets from the object).
struct View_aa8748 {
    uint8_t mPad0[0x14];
    uint32_t mnRefCount;      // 0x14
    uint8_t mPad18[0x2c];
    void* mpCity;             // 0x44
    void* mpOccMgr;           // 0x48
    void* mp4c;               // 0x4c
    uint8_t mPad50[3];
    uint8_t mbForceReload;    // 0x53
    std::vector<Step_aa8748> mSteps;  // 0x54
    std::vector<Point_aa8748> mCells;  // 0x60
    uint8_t mPad6c[0xc];
    uint32_t mnStepIndex;     // 0x78
    uint8_t mPad7c[0x5c];
    std::vector<Bridge_aa8748> mBridges;  // 0xd8
    uint8_t mPade4[0xc];
    std::vector<Draw_aa8748> mDraws;  // 0xf0
    uint32_t mnPreferredBridge;  // 0xfc
    uint8_t mPad100[0x18];
    std::vector<Point_aa8748> mPoints118;  // 0x118
    uint8_t mSatisfier[0xd0 - 0x4];  // 0x124
    Holder_aa8748* mpHolder;  // 0x1f0
    std::vector<uint32_t> mPossible;  // 0x1f4
    uint32_t mn200;
    uint32_t mn204;
    uint8_t mPad208[4];
    uint32_t mnFailure;       // 0x20c
    uint8_t mPad210[0x80];
    uint8_t mPlacementParams[0x10]; // 0x290
    uint8_t mPad2a0[0xb8];
    Info_aa8748* mpInfo;      // 0x358
    uint32_t mnNetType;       // 0x35c
    uint32_t mn360;
    void* mp364;
};

struct Anchor_aa8748 {
    // STUB: 0x00611b00
    void Fn00611b00(void* vec);
};

struct PlacementTarget_aa8748 {
    // STUB: 0x00626860
    uint32_t Fn00626860(void* src);
};

struct Satisfier_aa8748 {
    // STUB: 0x0065eb00
    bool GetHeight(int32_t vtx, float& h) const;
};

struct Possible_aa8748 {
    // STUB: 0x00462c10
    void Fn00462c10(void* vec);
};

struct City_aa8748 {
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
    virtual float Fn30(uint32_t v);
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
    virtual bool Fn88(uint32_t x, uint32_t z);
};
struct Namer_aa8748 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void Fn10(uint32_t id);
};
struct Typed_aa8748 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual uint32_t Fn10();
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
    virtual uint32_t* Fn3c();
};

// FUNCTION: 0x0062c8c0
void cSC4NetworkTool::ForceReload()
{
    reinterpret_cast<View_aa8748*>(this)->mbForceReload = 1;
}

// FUNCTION: 0x0062c910
uint32_t cSC4NetworkTool::ViewInputControlId()
{
    return reinterpret_cast<View_aa8748*>(this)->mpInfo->mn8;
}

// FUNCTION: 0x0062c920
uint32_t cSC4NetworkTool::GetToolViewId()
{
    return reinterpret_cast<View_aa8748*>(this)->mpInfo->mn10;
}

// FUNCTION: 0x0062c930
uint32_t cSC4NetworkTool::CursorId()
{
    return reinterpret_cast<View_aa8748*>(this)->mpInfo->mn14;
}

// FUNCTION: 0x0062c940
uint32_t cSC4NetworkTool::DirectionalCursorBase()
{
    return reinterpret_cast<View_aa8748*>(this)->mpInfo->mn18;
}

// FUNCTION: 0x0062c8e0
void cSC4NetworkTool::ClearFailureReason()
{
    reinterpret_cast<View_aa8748*>(this)->mnFailure = 0;
}

// FUNCTION: 0x0062c8f0
bool cSC4NetworkTool::GetFailureState()
{
    return reinterpret_cast<View_aa8748*>(this)->mnFailure != 0;
}

// FUNCTION: 0x0062ca10
void cSC4NetworkTool::Slot24_aa8748(uint32_t a)
{
    reinterpret_cast<View_aa8748*>(this)->mnStepIndex = a;
    SetTerrainHilight(a);
}

// FUNCTION: 0x0062ca30
void cSC4NetworkTool::GetDraggedCells(uint32_t p)
{
    OB_PTR(Anchor_aa8748, p)->Fn00611b00(reinterpret_cast<uint8_t*>(this) + 0x60);
}

// FUNCTION: 0x0062cad0
void cSC4NetworkTool::GetPlacementParams(uint32_t p)
{
    OB_PTR(PlacementTarget_aa8748, p)->Fn00626860(reinterpret_cast<uint8_t*>(this) + 0x290);
}

// FUNCTION: 0x00623270
unsigned int cSC4NetworkTool::Release()
{
    View_aa8748* self = reinterpret_cast<View_aa8748*>(this);
    if (self->mnRefCount > 1) {
        self->mnRefCount = self->mnRefCount - 1;
        return self->mnRefCount;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x00624130
uint32_t cSC4NetworkTool::GetMajorBridge()
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    if (!v->mBridges.empty()) {
        return v->mBridges.back().mnId;
    }
    return 0xffffffff;
}

// FUNCTION: 0x006241b0
bool cSC4NetworkTool::IsMajorBridgeLandBridge()
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    if (v->mBridges.empty()) {
        return false;
    }
    return v->mBridges.back().mbLandBridge;
}

// FUNCTION: 0x0062c9c0
bool cSC4NetworkTool::IsRegularStep(uint32_t i)
{
    return reinterpret_cast<View_aa8748*>(this)->mSteps[i].mn8 == 0;
}

// FUNCTION: 0x0062c950
void cSC4NetworkTool::PenWidth(uint32_t a, uint32_t b)
{
    *OB_PTR(uint32_t, a) = reinterpret_cast<View_aa8748*>(this)->mpInfo->mn1c;
    *OB_PTR(uint32_t, b) = reinterpret_cast<View_aa8748*>(this)->mpInfo->mn20;
}

// FUNCTION: 0x00626e80
bool cSC4NetworkTool::GetPossibleBridges(uint32_t p)
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    if (v->mPossible.empty()) {
        return false;
    }
    OB_PTR(Possible_aa8748, p)->Fn00462c10(&v->mPossible);
    return true;
}

// FUNCTION: 0x00624150
bool cSC4NetworkTool::GetMajorBridgeReferenceAltitude(uint32_t p)
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    if (v->mBridges.empty()) {
        return false;
    }
    *OB_PTR(uint32_t, p) = v->mBridges.back().mnReferenceAltitude;
    return true;
}

// FUNCTION: 0x00624180
bool cSC4NetworkTool::GetMajorBridgeAltitude(uint32_t p)
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    if (v->mBridges.empty()) {
        return false;
    }
    *OB_PTR(uint32_t, p) = v->mBridges.back().mnAltitude;
    return true;
}

// FUNCTION: 0x0062c9e0
void cSC4NetworkTool::GetLastValidPoint(uint32_t p)
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    uint32_t k = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(&v->mSteps.front()) + v->mnStepIndex * 12 - 8);
    uint32_t* out = OB_PTR(uint32_t, p);
    out[0] = v->mCells[k].mnX;
    out[1] = v->mCells[k].mnZ;
}

// FUNCTION: 0x00624af0
void cSC4NetworkTool::GetBridgeName(uint32_t a, uint32_t b)
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    uint32_t id = *reinterpret_cast<uint32_t*>(v->mpInfo->mpTable30 + b * 0x178 + 0x15c);
    OB_PTR(Namer_aa8748, a)->Fn10(id);
}

// FUNCTION: 0x00624480
bool cSC4NetworkTool::Slot03_aaaa9c(void* p)
{
    Typed_aa8748* t = static_cast<Typed_aa8748*>(p);
    if (t->Fn10() == 0xa6b79602) {
        reinterpret_cast<View_aa8748*>(this)->mnPreferredBridge = *t->Fn3c();
    }
    return true;
}

// FUNCTION: 0x006444f0
float cSC4NetworkTool::GetNetworkVertexHt(uint32_t vtx)
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    float h;
    if (reinterpret_cast<Satisfier_aa8748*>(v->mSatisfier)->GetHeight(vtx, h)) {
        return h;
    }
    return static_cast<City_aa8748*>(v->mpCity)->Fn30(vtx);
}

// A per-cell record (found by key).
struct Cell_aa8748 {
    uint8_t mPad0[8];
    uint32_t mn8;
    uint8_t mPadC[0xc];
    uint32_t mnOcc[16];
};

// The UI tool object created by GetUITool (constructor and setup belong to its own class).
struct UITool_aa8748 {
    virtual void P0();
    virtual uint32_t AddRef();
    // STUB: 0x00645d50
    UITool_aa8748* Fn00645d50();
    // STUB: 0x00645240
    bool Fn00645240(void* owner, uint32_t type);
};

// FUNCTION: 0x00623b20
bool cSC4NetworkTool::GetUITool(uint32_t p)
{
    UITool_aa8748* tool;
    void* mem = operator new(0x134);
    if (mem) {
        tool = static_cast<UITool_aa8748*>(mem)->Fn00645d50();
    } else {
        tool = 0;
    }
    tool->AddRef();
    tool->Fn00645240(this, mnNetworkType);
    *OB_PTR(UITool_aa8748*, p) = tool;
    return true;
}

// FUNCTION: 0x00624b20
bool cSC4NetworkTool::GetBridgeBitmapKey(uint32_t a, uint32_t b, uint32_t c)
{
    uint8_t* rec = reinterpret_cast<View_aa8748*>(this)->mpInfo->mpTable30 + a * 0x178;
    uint32_t k = *reinterpret_cast<uint32_t*>(rec + 0x148);
    if (k != 0 && *reinterpret_cast<uint32_t*>(rec + 0x14c) != 0) {
        *OB_PTR(uint32_t, b) = k;
        *OB_PTR(uint32_t, c) = *reinterpret_cast<uint32_t*>(rec + 0x14c);
        return true;
    }
    return false;
}

// FUNCTION: 0x006248d0
bool cSC4NetworkTool::OccupantExists(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Cell_aa8748* cell = static_cast<Cell_aa8748*>(Fn00633220((b << 16) + a));
    if (cell != 0 && reinterpret_cast<uint8_t*>(cell)[0x51] != 0 && (cell->mn8 & c) != 0) {
        *OB_PTR(uint32_t, d) = cell->mnOcc[mnNetworkType];
        return true;
    }
    return false;
}

// FUNCTION: 0x0061fbc0
void Holder_aa8748::Fn0061fbc0Impl_aa8748()
{
    if (mbActive) {
        Counted_aa8748* p = mpRef;
        if (p) {
            mpRef = 0;
            p->Release();
        }
        mbActive = 0;
    }
}

struct Rect_aa8748 {
    uint8_t mPad0[0x19c];
    uint32_t mn19c;
    uint32_t mn1a0;
    uint32_t mn1a4;
    uint32_t mn1a8;
    uint32_t mn1ac;
    void Fn0061d340(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
};

// FUNCTION: 0x0061d340
void Rect_aa8748::Fn0061d340(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    mn19c = a;
    mn1a0 = b;
    mn1a4 = c;
    mn1a8 = d;
    mn1ac = e;
}
struct OccMgr_aa8748 {
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
    virtual bool Fn80(void** out, uint32_t a, uint32_t b, uint32_t c);
};
struct Unk_aa8748 {
    virtual bool QueryInterface(uint32_t id, uint32_t out);
    virtual void P1();
    virtual uint32_t Release();
};

// GLOBAL: 0x00aa835c
extern const uint32_t gaa835c_aa8748[12];

// FUNCTION: 0x00623e60
uint32_t Fn00623e60(uint32_t mask)
{
    int32_t i = 0;
    do {
        if (gaa835c_aa8748[i] & mask) {
            return i;
        }
        if (gaa835c_aa8748[i + 1] & mask) {
            return i + 1;
        }
        if (gaa835c_aa8748[i + 2] & mask) {
            return i + 2;
        }
        if (gaa835c_aa8748[i + 3] & mask) {
            return i + 3;
        }
        if (gaa835c_aa8748[i + 4] & mask) {
            return i + 4;
        }
        if (gaa835c_aa8748[i + 5] & mask) {
            return i + 5;
        }
        i += 6;
    } while (i < 12);
    return i;
}

// FUNCTION: 0x00623bb0
uint32_t cSC4NetworkTool::Fn00623bb0(uint32_t a)
{
    int32_t best = 0;
    uint32_t* p = OB_PTR(uint32_t, a) + 0x2a;
    for (int32_t n = 4; n != 0; n--, p++) {
        float h = static_cast<City_aa8748*>(reinterpret_cast<View_aa8748*>(this)->mpCity)->Fn30(*p);
        float d = *reinterpret_cast<float*>(p - 20) - h;
        if (d > 0.01f) {
            int32_t level;
            if (d < mfLimit2c8) {
                level = 1;
            } else {
                level = 2;
            }
            if (level > best) {
                best = level;
            }
        }
    }
    return best;
}

struct HashNode_aa8748 {
    HashNode_aa8748* mpNext;
    uint32_t mnKey;
    uint32_t mValue;
};

struct HashTable_aa8748 {
    uint32_t mn0;
    HashNode_aa8748** mpBegin;
    HashNode_aa8748** mpEnd;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00625860 score 28
void* cSC4NetworkTool::Fn00625860(uint32_t key)
{
    HashTable_aa8748* h = reinterpret_cast<HashTable_aa8748*>(reinterpret_cast<uint8_t*>(reinterpret_cast<View_aa8748*>(this)->mpInfo) + 0x3c);
    uint32_t n = static_cast<uint32_t>(h->mpEnd - h->mpBegin);
    HashNode_aa8748* node = h->mpBegin[key % n];
    while (node) {
        if (node->mnKey == key) {
            return &node->mValue;
        }
        node = node->mpNext;
    }
    return 0;
}
#endif

// FUNCTION: 0x00638710
bool cSC4NetworkTool::IdentifyStartingConditions(uint32_t out)
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    if (IsStoppedByWater()) {
        uint32_t z = v->mCells[0].mnZ;
        uint32_t x = v->mCells[0].mnX;
        if (static_cast<City_aa8748*>(v->mpCity)->Fn88(x, z)) {
            Cell_aa8748* cell = static_cast<Cell_aa8748*>(Fn00633220((z << 16) + x));
            if (cell == 0 || reinterpret_cast<uint8_t*>(cell)[0x56] == 0) {
                *OB_PTR(uint32_t, out) = 0;
                return false;
            }
        }
    }
    return true;
}

// FUNCTION: 0x00624510
bool cSC4NetworkTool::Fn00624510(uint32_t x, uint32_t z, uint32_t mask)
{
    if (x > 0) {
        Cell_aa8748* c = static_cast<Cell_aa8748*>(Fn00633220((z << 16) + x - 1));
        if (c != 0 && (c->mn8 & ~mask & 0x1fff) != 0) {
            return true;
        }
    }
    if (x < mnSizeX - 1) {
        Cell_aa8748* c = static_cast<Cell_aa8748*>(Fn00633220((z << 16) + x + 1));
        if (c != 0 && (c->mn8 & ~mask & 0x1fff) != 0) {
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x00624590
bool cSC4NetworkTool::Fn00624590(uint32_t x, uint32_t z, uint32_t mask)
{
    if (z > 0) {
        Cell_aa8748* c = static_cast<Cell_aa8748*>(Fn00633220(((z - 1) << 16) + x));
        if (c != 0 && (c->mn8 & ~mask & 0x1fff) != 0) {
            return true;
        }
    }
    if (z < mnSizeZ - 1) {
        Cell_aa8748* c = static_cast<Cell_aa8748*>(Fn00633220(((z + 1) << 16) + x));
        if (c != 0 && (c->mn8 & ~mask & 0x1fff) != 0) {
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x00624b70
bool cSC4NetworkTool::Fn00624b70(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    if (a < mnSizeX && b < mnSizeZ) {
        Unk_aa8748* local = 0;
        if (static_cast<OccMgr_aa8748*>(reinterpret_cast<View_aa8748*>(this)->mpOccMgr)->Fn80(reinterpret_cast<void**>(&local), a, b, c)) {
            bool r = local->QueryInterface(0xa821ef94, d);
            if (local) {
                local->Release();
            }
            return r;
        }
        if (local) {
            local->Release();
        }
    }
    return false;
}

struct Cache_aa8748 {
    // STUB: 0x00647b20
    void Fn00647b20();
};

struct Renderer_aa8748 {
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
    virtual void Fn84(void* preview);
};
// GLOBAL: 0x00b43dd0
extern Renderer_aa8748* gpB43dd0_aa8748;

// FUNCTION: 0x00626f90
void cSC4NetworkTool::Reset()
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    reinterpret_cast<Cache_aa8748*>(reinterpret_cast<uint8_t*>(this) + 0x1c)->Fn00647b20();
    ClearOccupantHighlights();
    Slot16_aa8748();
    v->mPoints118.clear();
    v->mCells.clear();
    v->mn200 = 0xffffffff;
    v->mn204 = 0xbf800000;
    v->mPossible.clear();
    ClearFailureReason();
    v->mDraws.clear();
}

// FUNCTION: 0x00626d30
bool cSC4NetworkTool::Shutdown()
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    if (v->mPad18[0]) {
        if (gpB43ccc != 0) {
            gpB43ccc->RemoveNotification(reinterpret_cast<uint8_t*>(this) + 4, 0xa6b79602);
        }
        v->mPossible.clear();
        ClearOccupantHighlights();
        v->mPoints118.clear();
        v->mCells.clear();
        Slot16_aa8748();
        if (v->mp4c) {
            static_cast<Counted_aa8748*>(v->mp4c)->Release();
            v->mp4c = 0;
        }
        if (v->mpOccMgr) {
            static_cast<Counted_aa8748*>(v->mpOccMgr)->Release();
            v->mpOccMgr = 0;
        }
        if (v->mpCity) {
            static_cast<Counted_aa8748*>(v->mpCity)->Release();
            v->mpCity = 0;
        }
        if (v->mp364) {
            static_cast<Counted_aa8748*>(v->mp364)->Release();
            v->mp364 = 0;
        }
        if (v->mpHolder) {
            gpB43dd0_aa8748->Fn84(v->mpHolder);
            v->mpHolder->Fn0061fbc0();
            Holder_aa8748* h = v->mpHolder;
            if (h) {
                v->mpHolder = 0;
                h->Release();
            }
        }
        v->mPad18[0] = 0;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00638990 score 11
bool cSC4NetworkTool::CheckForGoodTerrain(uint32_t p)
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    if (!IsStoppedByWater()) {
        return true;
    }
    int32_t* pn = OB_PTR(int32_t, p);
    for (int32_t i = 0; i < *pn; i++) {
        if (v->mSteps[i].mn8 == 0) {
            for (uint32_t k = v->mSteps[i].mn0; k <= v->mSteps[i].mn4; k++) {
                Point_aa8748* pt = &v->mCells[k];
                uint32_t z = pt->mnZ;
                uint32_t x = pt->mnX;
                if (static_cast<City_aa8748*>(v->mpCity)->Fn88(x, z)) {
                    Cell_aa8748* c = static_cast<Cell_aa8748*>(Fn00633220((z << 16) + x));
                    if (c == 0 || reinterpret_cast<uint8_t*>(c)[0x56] == 0) {
                        *pn = i;
                        return false;
                    }
                }
            }
        }
    }
    Draw_aa8748* end = v->mDraws.end();
    for (Draw_aa8748* d = v->mDraws.begin(); d != end; d++) {
        uint32_t z = d->mn[1];
        uint32_t x = d->mn[0];
        if (!static_cast<City_aa8748*>(v->mpCity)->Fn88(x, z)) {
            *pn = 0;
            return false;
        }
        Cell_aa8748* c = static_cast<Cell_aa8748*>(Fn00633220((z << 16) + x));
        if (c != 0 && reinterpret_cast<uint8_t*>(c)[0x56] != 0) {
            *pn = 0;
            return false;
        }
    }
    return true;
}
#endif

// ---- continuation batches (next agent) ----

// An STLport free-list pool: the head of the free nodes and the number in use.
struct PoolNode_aa8748 {
    PoolNode_aa8748* mpNext;
};
struct Pool_aa8748 {
    uint32_t mn0;
    uint32_t mn4;
    PoolNode_aa8748* mpFree;
    uint32_t mnUsed;
};
struct PoolGrow_aa8748 {
    // STUB: 0x0090cf9a
    PoolNode_aa8748* Grow();
};

// GLOBAL: 0x00b0b2d4
extern Pool_aa8748* gpB0b2d4;
// GLOBAL: 0x00b0b2d0
extern PoolGrow_aa8748 gB0b2d0;
// GLOBAL: 0x00b0b398
extern Pool_aa8748* gpB0b398;
// GLOBAL: 0x00b0b394
extern PoolGrow_aa8748 gB0b394;
// GLOBAL: 0x00b0b3ac
extern Pool_aa8748* gpB0b3ac;
// GLOBAL: 0x00b0b3a8
extern PoolGrow_aa8748 gB0b3a8;
// GLOBAL: 0x00b0b574
extern Pool_aa8748* gpB0b574;
// GLOBAL: 0x00b0b570
extern PoolGrow_aa8748 gB0b570;
// GLOBAL: 0x00b0b3d8
extern int8_t gB0b3d8[];
// GLOBAL: 0x00b0b3f4
extern int8_t gB0b3f4[];

#ifdef OB_DRAFTS
// CLOSE: 0x00605040 score 4
void* Fn00605040(uint32_t)
{
    PoolNode_aa8748* n = gpB0b2d4->mpFree;
    if (!n) {
        n = gB0b2d0.Grow();
    }
    gpB0b2d4->mpFree = n->mpNext;
    gpB0b2d4->mnUsed++;
    return n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00619e90 score 4
void* Fn00619e90(uint32_t)
{
    PoolNode_aa8748* n = gpB0b398->mpFree;
    if (!n) {
        n = gB0b394.Grow();
    }
    gpB0b398->mpFree = n->mpNext;
    gpB0b398->mnUsed++;
    return n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0061d200 score 4
void* Fn0061d200(uint32_t)
{
    PoolNode_aa8748* n = gpB0b3ac->mpFree;
    if (!n) {
        n = gB0b3a8.Grow();
    }
    gpB0b3ac->mpFree = n->mpNext;
    gpB0b3ac->mnUsed++;
    return n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00647230 score 4
void* Fn00647230(uint32_t)
{
    PoolNode_aa8748* n = gpB0b574->mpFree;
    if (!n) {
        n = gB0b570.Grow();
    }
    gpB0b574->mpFree = n->mpNext;
    gpB0b574->mnUsed++;
    return n;
}
#endif

// A tile-info record: its meta position index at +4.
struct TileInfo_aa8748 {
    uint8_t mPad0[4];
    uint8_t mnMeta;
    // STUB: 0x00620da0
    void GetCell(uint32_t x, uint32_t z, uint32_t* ox, uint32_t* oz);
};

// FUNCTION: 0x00620da0
void TileInfo_aa8748::GetCell(uint32_t x, uint32_t z, uint32_t* ox, uint32_t* oz)
{
    int8_t dz = gB0b3f4[mnMeta];
    *ox = gB0b3d8[mnMeta] + x;
    *oz = dz + z;
}

// A set the copy loop fills: Fn0045d460 inserts one value.
struct IdSet_aa8748 {
    // STUB: 0x0045d460
    void Insert(uint32_t* v);
};

// FUNCTION: 0x00633ed0
void Fn00633ed0(IdSet_aa8748* set, std::vector<uint32_t>* vec)
{
    std::vector<uint32_t>::iterator end = vec->end();
    for (std::vector<uint32_t>::iterator p = vec->begin(); p != end; p++) {
        uint32_t v = *p;
        set->Insert(&v);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x006241d0 score 1
bool cSC4NetworkTool::GetPossibleNeighborConnection(void* out)
{
    View_aa8748* v = reinterpret_cast<View_aa8748*>(this);
    uint32_t* b = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(this) + 0x10c);
    uint32_t* e = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(this) + 0x110);
    if (b == e) {
        return false;
    }
    uint32_t* r = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(this) + 0x10c);
    uint32_t* o = static_cast<uint32_t*>(out);
    o[0] = r[2];
    o[1] = r[3];
    o[2] = r[4];
    reinterpret_cast<uint8_t*>(o)[0xc] = reinterpret_cast<uint8_t*>(r)[0x14];
    (void)v;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00623290 score 14
bool cSC4NetworkTool::QueryInterface(uint32_t id, void** out)
{
    void** pp = out;
    if (id == 1 || id == 0x0a74ca15) {
        *pp = static_cast<cSC4NetworkTool_0*>(this);
        AddRef();
        return true;
    }
    if (id == 0x452294aa) {
        *pp = static_cast<cUnk00aaaa9c*>(this);
        AddRef();
        return true;
    }
    return false;
}
#endif

// The constraint satisfier object: an active flag at +4, a map of vertices at +0x14, a cursor at +0x5c.
struct SatMap_aa8748 {
    uint8_t mPad0[4];
    uint8_t mbActive;
    uint8_t mbDirty;
    uint8_t mPad6[2];
    uint32_t mn8;
    uint32_t mnC;
    uint32_t mn10;
    uint8_t mMap14[0x48];
    uint32_t* mpCursor5c;
    uint32_t mn60;
    // STUB: 0x0065e710
    bool Fn0065e710(uint32_t a, uint32_t b);
    // STUB: 0x006601a0
    bool Fn006601a0();
    // STUB: 0x0065fbe0
    void Fn0065fbe0();
    // STUB: 0x0065ef70
    void Fn0065ef70();
    // STUB: 0x0065eb50
    bool Fn0065eb50(uint32_t* a, uint32_t* b);
    // STUB: 0x00660360
    void Fn00660360(uint32_t a, uint32_t b);
    // STUB: 0x0065fb60
    void Fn0065fb60(uint32_t a, uint32_t b);
    // STUB: 0x0065fed0
    void Fn0065fed0(uint32_t a, uint32_t b, uint32_t c);
    // STUB: 0x006606e0
    bool DoInitialConstraintPropagation();
    // STUB: 0x0065ed80
    bool PickASolution(int32_t* vtx, float* h, bool* flag);
    // STUB: 0x00660390
    bool PropagateRangeConstraintsOfVerts(void* set);
    // STUB: 0x00660130
    void MarkSolution(uint32_t vtx, uint32_t h);
    // STUB: 0x006608c0
    void DumpConstraints();
    // STUB: 0x00660b10
    bool Solve();
    // STUB: 0x0065eca0
    bool MarkConstraintAboutVert(int32_t vtx, uint32_t kind);
    // STUB: 0x0065e810
    void* FindEqualitySet(int32_t vtx);
    // STUB: 0x0065ed00
    void MergeEqualitySets(void* a, void* b);
    // STUB: 0x0065fdb0
    void InsertEqualityConstraint(int32_t a, int32_t b);
    // STUB: 0x0065fbe0
    void DeleteConstraintsAndOtherTemporaryData();
};
struct MapOps_aa8748 {
    // STUB: 0x008eba60
    void Clear();
    // STUB: 0x004b0390
    void Front(uint32_t* out);
    // STUB: 0x0053dcf0
    uint32_t* Next();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0065e710 score 6
bool SatMap_aa8748::Fn0065e710(uint32_t a, uint32_t b)
{
    if (mbActive) {
        return false;
    }
    mn8 = a;
    mbActive = 1;
    mbDirty = 1;
    mnC = b;
    return true;
}
#endif

// FUNCTION: 0x006601a0
bool SatMap_aa8748::Fn006601a0()
{
    if (mbActive) {
        mbActive = 0;
        Fn0065fbe0();
        reinterpret_cast<MapOps_aa8748*>(mMap14)->Clear();
    }
    return true;
}

// FUNCTION: 0x0065ef70
void SatMap_aa8748::Fn0065ef70()
{
    uint32_t r[2];
    reinterpret_cast<MapOps_aa8748*>(mMap14)->Front(r);
    mpCursor5c = reinterpret_cast<uint32_t*>(r[0]);
    mn60 = r[1];
}

// FUNCTION: 0x00660360
void SatMap_aa8748::Fn00660360(uint32_t a, uint32_t b)
{
    Fn0065fb60(a, b);
    Fn0065fed0(a, b, b);
}

// ---- batch 2 ----

// STUB: 0x00603040
bool SC4LoadStringB_aa8748(cIGZString* pString, uint32_t group, uint32_t instance, void* pDetokenizer);

#ifdef OB_DRAFTS
// CLOSE: 0x0062bf60 score 53
void cSC4NetworkTool::GetFailureReasonString_2(uint32_t id, void* str)
{
    cRZString* s = static_cast<cRZString*>(static_cast<cIGZString*>(str));
    s->clear();
    if (id != 0) {
        if (!SC4LoadStringB_aa8748(s, 0x2a592fd1, id, 0)) {
            cRZString fallback("?");
            s->assign(fallback.begin(), fallback.end());
        }
    }
}
#endif

// FUNCTION: 0x0062ca40
void cSC4NetworkTool::GetFailureReasonString(void* out)
{
    cRZString text;
    GetFailureReasonString_2(reinterpret_cast<View_aa8748*>(this)->mnFailure, &text);
    static_cast<cIGZString*>(out)->FromChar(text.c_str(), text.size());
}

// Two ordered trees of a container: the root header, the node count, and an erase of the subtree.
struct TreeA_aa8748 {
    struct Node {
        uint32_t mn0;
        Node* mpParent;
        Node* mpLeft;
        Node* mpRight;
    };
    Node* mpHead;
    uint32_t mnSize;
    // STUB: 0x0061fcd0
    void Erase(Node* n);
};
struct TreeB_aa8748 {
    struct Node {
        uint32_t mn0;
        Node* mpParent;
        Node* mpLeft;
        Node* mpRight;
    };
    Node* mpHead;
    uint32_t mnSize;
    // STUB: 0x006203a0
    void Erase(Node* n);
};
struct TwoTrees_aa8748 {
    uint8_t mPad0[0x10];
    TreeA_aa8748 mA;
    uint32_t mn18;
    TreeB_aa8748 mB;
    // STUB: 0x006208d0
    void Fn006208d0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x006208d0 score 25
void TwoTrees_aa8748::Fn006208d0()
{
    TreeA_aa8748* a = &mA;
    if (mA.mnSize != 0) {
        a->Erase(a->mpHead->mpParent);
        a->mpHead->mpLeft = a->mpHead;
        a->mpHead->mpParent = 0;
        a->mpHead->mpRight = a->mpHead;
        a->mnSize = 0;
    }
    TreeB_aa8748* b = &mB;
    if (mB.mnSize != 0) {
        b->Erase(b->mpHead->mpParent);
        b->mpHead->mpLeft = b->mpHead;
        b->mpHead->mpParent = 0;
        b->mpHead->mpRight = b->mpHead;
        b->mnSize = 0;
    }
}
#endif

// STUB: 0x0090cf54
void* StlNew_aa8748(uint32_t n);

// An object with a raw vtable (0x00aa74ac): zeroed fields and a tree header.
struct Raw74ac_aa8748 {
    virtual void P0();
    uint32_t mn4, mn8, mnC, mn10;
    uint8_t mb14, mb15;
    uint32_t mn18, mn1c, mn20, mn24, mn28;
    uint32_t* mpTree2c;
    uint32_t mn30, mn34, mn38, mn3c, mn40, mn44, mn48, mn4c, mn50;
    Raw74ac_aa8748();
};

#ifdef OB_DRAFTS
// CLOSE: 0x006070c0 score 0
Raw74ac_aa8748::Raw74ac_aa8748()
{
    mn4 = 0; mn8 = 0; mnC = 0; mn10 = 0;
    mb14 = 0; mb15 = 0;
    mn18 = 0; mn1c = 0; mn20 = 0; mn24 = 0; mn28 = 0;
    mpTree2c = 0;
    uint32_t* t = static_cast<uint32_t*>(StlNew_aa8748(0xc));
    t[0] = reinterpret_cast<uint32_t>(t);
    t[1] = reinterpret_cast<uint32_t>(t);
    mpTree2c = t;
    mn30 = 0; mn34 = 0; mn38 = 0; mn3c = 0; mn40 = 0; mn44 = 0; mn48 = 0; mn4c = 0; mn50 = 0;
}
#endif

// The neighbourhood record of a tile (vtable 0x00aa8700).
struct Neighborhood_aa8748 {
    virtual void P0();
    uint32_t mn4, mn8, mnC, mn10, mnX, mnZ;
    void* mpTool;
    uint32_t mnType;
    uint32_t mnMask;
    Neighborhood_aa8748(uint32_t x, uint32_t z, void* tool, uint32_t type, bool b);
};
struct ToolCells_aa8748 {
    // STUB: 0x00633220
    uint8_t* Fn00633220(uint32_t pos);
};
// GLOBAL: 0x00aa835c
extern uint32_t gTable_aa8748[];

#ifdef OB_DRAFTS
// CLOSE: 0x00627080 score 0
Neighborhood_aa8748::Neighborhood_aa8748(uint32_t x, uint32_t z, void* tool, uint32_t type, bool b)
{
    mn4 = 0; mn8 = 0; mnC = 0; mn10 = 0;
    mpTool = tool;
    mnX = x; mnZ = z;
    mnType = type;
    mnMask = b ? 0 : (gTable_aa8748[type] ^ 0x1fff);
    mn4 = 0;
    uint8_t* c = static_cast<ToolCells_aa8748*>(mpTool)->Fn00633220((z << 16) + x);
    if (c != 0) {
        mn4 = *reinterpret_cast<uint32_t*>(c + type * 4 + 0x18);
    }
}
#endif

// A chained hash table of ids (STLport hash_set<uint32_t>): the bucket vector at +4, the nodes chain.
struct HNode_aa8748 {
    HNode_aa8748* mpNext;
    uint32_t mnKey;
};
struct HSet_aa8748 {
    uint32_t mn0;
    HNode_aa8748** mpBuckets;
    HNode_aa8748** mpBucketsEnd;
    // STUB: 0x00489cf0
    void Fn00489cf0(void* a);
};
struct HOwner_aa8748 {
    uint8_t mPad0[8];
    uint32_t mn8;
    uint32_t mnC;
    uint8_t mPad10[0x18];
    HSet_aa8748 mSet28;
    // STUB: 0x0065fb60
    void Fn0065fb60(uint32_t key, uint32_t val);
};
struct Pair7_aa8748 {
    uint32_t mn[7];
};
// STUB: 0x0065fad0
uint32_t* Fn0065fad0_aa8748(HSet_aa8748* set, uint32_t* key);

#ifdef OB_DRAFTS
// CLOSE: 0x0065fb60 score 0
void HOwner_aa8748::Fn0065fb60(uint32_t key, uint32_t val)
{
    uint32_t n = mSet28.mpBucketsEnd - mSet28.mpBuckets;
    HNode_aa8748* node = mSet28.mpBuckets[key % n];
    while (node != 0 && node->mnKey != key) {
        node = node->mpNext;
    }
    if (node == 0) {
        Pair7_aa8748 p;
        p.mn[0] = mn8;
        p.mn[1] = mnC;
        p.mn[2] = val;
        p.mn[3] = 1;
        uint32_t k = key;
        uint32_t* slot = Fn0065fad0_aa8748(&mSet28, &k);
        *reinterpret_cast<Pair7_aa8748*>(slot) = p;
    }
}
#endif

// ---- batch 3 ----
struct OccRel_aa8748 {
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
    virtual void Fn54(void* occ, uint32_t a, uint32_t b);
};
struct Ini_aa8748 {
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
    virtual void Fn34(void* name, void* cb, void* user);
};
struct RefObj_aa8748 {
    virtual void P0();
    virtual void P1();
    virtual void Release();
};
// GLOBAL: 0x00b43d0c
extern OccRel_aa8748* gpB43d0c;

// The in-order successor in a red-black tree node (left +8, right +0xc, parent +4).
struct RbNode_aa8748 {
    uint32_t mn0;
    RbNode_aa8748* mpParent;
    RbNode_aa8748* mpLeft;
    RbNode_aa8748* mpRight;
    RefObj_aa8748* mpValue;
};
inline RbNode_aa8748* RbNext_aa8748(RbNode_aa8748* n)
{
    RbNode_aa8748* r = n->mpRight;
    if (r) {
        n = r;
        while (n->mpLeft) {
            n = n->mpLeft;
        }
        return n;
    }
    RbNode_aa8748* p = n->mpParent;
    while (n == p->mpRight) {
        n = p;
        p = p->mpParent;
    }
    if (n->mpRight != p) {
        n = p;
    }
    return n;
}
struct RbSet_aa8748 {
    RbNode_aa8748* mpHead;
    uint32_t mnSize;
    // STUB: 0x004676a0
    void Erase(RbNode_aa8748* n);
};
struct HolderTrees_aa8748 {
    // STUB: 0x006208d0
    void Fn006208d0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00625580 score 0
void cSC4NetworkTool::Slot16_aa8748()
{
    uint8_t* b = reinterpret_cast<uint8_t*>(this);
    (*reinterpret_cast<HolderTrees_aa8748**>(b + 0x1f0))->Fn006208d0();
    RbSet_aa8748* set = reinterpret_cast<RbSet_aa8748*>(b + 0x228);
    RbNode_aa8748* head = set->mpHead;
    OccRel_aa8748* mgr = gpB43d0c;
    RbNode_aa8748* end = head;
    for (RbNode_aa8748* n = head->mpLeft; n != end; n = RbNext_aa8748(n)) {
        RefObj_aa8748* o = n->mpValue;
        mgr->Fn54(o, 1, 0);
        o->Release();
    }
    if (set->mnSize != 0) {
        set->Erase(set->mpHead->mpParent);
        set->mpHead->mpLeft = set->mpHead;
        set->mpHead->mpParent = 0;
        set->mpHead->mpRight = set->mpHead;
        set->mnSize = 0;
    }
}
#endif

// A base with two vtables (0x00aa8290, 0x00aa8278) over the constructor of 0x005ea080.
struct Two8290_aa8748 {
    virtual void P0();
    Two8290_aa8748();
};
struct Base5ea080_aa8748 {
    // STUB: 0x005ea080
    void Fn005ea080();
};
#ifdef OB_DRAFTS
// CLOSE: 0x0061f510 score 0
Two8290_aa8748::Two8290_aa8748()
{
    reinterpret_cast<Base5ea080_aa8748*>(this)->Fn005ea080();
}
#endif

// The loader of one rule file: a name, then the ini's callback walk.
// STUB: 0x0063d530
bool LoadOverrideCallback_aa8748(void* a, void* b);
// STUB: 0x0063d1e0
bool AddRuleOverrides_aa8748(void* a, void* b);
// GLOBAL: 0x00b466d0
extern uint32_t gB466d0;

// FUNCTION: 0x0063d630
void SC4NetworkLoadOverrideMatrix(Ini_aa8748* ini, uint32_t* user)
{
    cRZString key("AllowedOverrides");
    ini->Fn34(&key, reinterpret_cast<void*>(LoadOverrideCallback_aa8748), user);
}

// FUNCTION: 0x0063d3e0
void Fn0063d3e0(Ini_aa8748* ini, const char* name)
{
    cRZString key(name);
    ini->Fn34(&key, reinterpret_cast<void*>(AddRuleOverrides_aa8748), &gB466d0);
}

// STUB: 0x0065eca0
bool Fn0065eca0_aa8748(void* self, uint32_t v, uint32_t flag);

// ---- batch 4 ----

// A map node tree keyed by uint32_t: find the lower bound then insert (the tail call inserts).
struct KeyTree_aa8748 {
    struct Node {
        uint32_t mn0;
        Node* mpParent;
        Node* mpLeft;
        Node* mpRight;
        uint32_t mnKey;
    };
    Node* mpHead;
};
struct TreeHolder_aa8748 {
    KeyTree_aa8748* mpTree;
    // STUB: 0x00620a90
    void* Fn00620a90(void* out, uint32_t* key);
};
// STUB: 0x006205c0
void Fn006205c0_aa8748(void* out, KeyTree_aa8748::Node* hit, KeyTree_aa8748::Node* parent, uint32_t* key, uint32_t flag);

#ifdef OB_DRAFTS
// CLOSE: 0x00620a90 score 0
void* TreeHolder_aa8748::Fn00620a90(void* out, uint32_t* key)
{
    KeyTree_aa8748::Node* n = mpTree->mpHead->mpParent;
    KeyTree_aa8748::Node* p = 0;
    if (n) {
        do {
            p = n;
            if (*key < n->mnKey) {
                n = n->mpLeft;
            } else {
                n = n->mpRight;
            }
        } while (n);
    }
    Fn006205c0_aa8748(out, n, p, key, 0);
    return out;
}
#endif

// FUNCTION-less: reads the cursor of a map and advances it.
#ifdef OB_DRAFTS
// CLOSE: 0x0065eb50 score 0
bool SatMap_aa8748::Fn0065eb50(uint32_t* a, uint32_t* b)
{
    uint32_t** cur = &mpCursor5c;
    if (*cur == 0) {
        return false;
    }
    *a = (*cur)[1];
    *b = (*cur)[2];
    uint32_t* next = reinterpret_cast<uint32_t*>((*cur)[0]);
    if (next == 0) {
        next = reinterpret_cast<MapOps_aa8748*>(cur)->Next();
    }
    *cur = next;
    return true;
}
#endif

// An object that keeps a reference and a service (vtables of its own, see the stores).
struct RefTarget_aa8748 {
    virtual void P0();
    virtual void AddRef();
    virtual void Release();
};
struct Rebinder_aa8748 {
    uint8_t mPad0[0x14];
    RefTarget_aa8748* mpTarget14;
    RefTarget_aa8748* mpService18;
    uint8_t mPad1c[0x8];
    uint8_t mb24;
    uint8_t mPad25[5];
    uint8_t mb2a;
    uint8_t mPad2b[0x55];
    uint32_t mn80;
    uint8_t mb84[0x24];
    uint8_t mba8;
    // STUB: 0x00645240
    bool Fn00645240(RefTarget_aa8748* target, uint32_t v);
};
struct Src_aa8748 {
    virtual void P0(); virtual void P1(); virtual void P2(); virtual void P3(); virtual void P4(); virtual void P5();
    virtual void P6(); virtual void P7(); virtual void P8(); virtual void P9(); virtual void P10(); virtual void P11();
    virtual void P12(); virtual void P13(); virtual void P14(); virtual void P15(); virtual void P16(); virtual void P17();
    virtual void P18(); virtual void P19(); virtual void P20(); virtual void P21(); virtual void P22(); virtual void P23();
    virtual void P24(); virtual void P25(); virtual void P26(); virtual void P27(); virtual void P28(); virtual void P29();
    virtual void P30(); virtual void P31(); virtual void P32(); virtual void P33(); virtual void P34(); virtual void P35();
    virtual void P36(); virtual void P37(); virtual void P38(); virtual void P39(); virtual void P40(); virtual void P41();
    virtual void P42(); virtual void P43(); virtual void P44(); virtual void P45(); virtual void P46(); virtual void P47();
    virtual void Fn0c0(void* out);
};
// GLOBAL: 0x00b43cb8
extern RefTarget_aa8748* gpB43cb8_aa8748;
struct Atm_aa8748 {
    virtual void P0(); virtual void P1(); virtual void P2(); virtual void P3(); virtual void P4();
    virtual void Fn14(void* p, uint32_t v);
};
// STUB: 0x00602600
Atm_aa8748* Fn00602600_aa8748();

#ifdef OB_DRAFTS
// CLOSE: 0x00645240 score 0
bool Rebinder_aa8748::Fn00645240(RefTarget_aa8748* target, uint32_t v)
{
    mb24 = 1;
    RefTarget_aa8748* old = mpTarget14;
    if (target != old) {
        if (target) {
            target->AddRef();
        }
        mpTarget14 = target;
        if (old) {
            old->Release();
        }
    }
    mn80 = v;
    RefTarget_aa8748* svc = gpB43cb8_aa8748;
    RefTarget_aa8748* oldSvc = mpService18;
    if (svc != oldSvc) {
        if (svc) {
            svc->AddRef();
        }
        mpService18 = svc;
        if (oldSvc) {
            oldSvc->Release();
        }
    }
    static_cast<Src_aa8748*>(static_cast<void*>(target))->Fn0c0(mb84);
    mb2a = mba8;
    Fn00602600_aa8748()->Fn14(reinterpret_cast<uint8_t*>(this) + 8, 0xff);
    return true;
}
#endif

// The in-order search of a tree for the range of a key (lower and upper bound), then an equality test.
struct CmpTree_aa8748 {
    uint32_t mn0;
    KeyTree_aa8748::Node* mpHead;
    // STUB: 0x006220d0
    bool Fn006220d0(uint32_t* key, uint32_t* out);
};
// STUB: 0x00622040
bool Fn00622040_aa8748(void* node, uint32_t* key, uint32_t* out);

#ifdef OB_DRAFTS
// CLOSE: 0x006220d0 score 0
bool CmpTree_aa8748::Fn006220d0(uint32_t* key, uint32_t* out)
{
    *out = 0;
    KeyTree_aa8748::Node* lo = mpHead;
    KeyTree_aa8748::Node* n = lo->mpParent;
    while (n) {
        if (n->mnKey < key[1]) {
            n = n->mpRight;
        } else {
            lo = n;
            n = n->mpLeft;
        }
    }
    KeyTree_aa8748::Node* hi = mpHead;
    n = hi->mpParent;
    while (n) {
        if (key[1] < n->mnKey) {
            hi = n;
            n = n->mpLeft;
        } else {
            n = n->mpRight;
        }
    }
    while (lo != hi) {
        if (Fn00622040_aa8748(reinterpret_cast<uint8_t*>(lo) + 0x14, key, out)) {
            return true;
        }
        lo = RbNext_aa8748(reinterpret_cast<RbNode_aa8748*>(lo)) ? reinterpret_cast<KeyTree_aa8748::Node*>(RbNext_aa8748(reinterpret_cast<RbNode_aa8748*>(lo))) : lo;
    }
    return false;
}
#endif

// Hash set walk (from a hash_set<uint32_t> into another container).
struct HashIter_aa8748 {
    uint32_t mn0;
    HNode_aa8748** mpBuckets;
    HNode_aa8748** mpBucketsEnd;
};
struct Sink_aa8748 {
    uint8_t mPad0[0x10];
    uint32_t mnCount;
    // STUB: 0x004f0940
    void Reserve(uint32_t n);
    // STUB: 0x00624dd0
    void Add(uint32_t* v, uint32_t* k);
};
// STUB: 0x004b0390
HNode_aa8748* Fn004b0390_aa8748(void* out);

#ifdef OB_DRAFTS
// CLOSE: 0x00633f10 score 0
void Fn00633f10(HashIter_aa8748* h, Sink_aa8748* sink)
{
    HNode_aa8748* node = 0;
    HNode_aa8748* first = Fn004b0390_aa8748(&node);
    (void)first;
    HNode_aa8748* cur = node;
    while (cur) {
        sink->Reserve(sink->mnCount + 1);
        uint32_t k = cur->mnKey;
        sink->Add(&k, &cur->mnKey);
        HNode_aa8748* next = cur->mpNext;
        if (!next) {
            uint32_t n = h->mpBucketsEnd - h->mpBuckets;
            uint32_t idx = cur->mnKey % n;
            idx++;
            while (idx < n) {
                next = h->mpBuckets[idx];
                if (next) {
                    break;
                }
                idx++;
            }
        }
        cur = next;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00633e50 score 0
void Fn00633e50(HashIter_aa8748* h, IdSet_aa8748* set)
{
    HNode_aa8748* node = 0;
    Fn004b0390_aa8748(&node);
    HNode_aa8748* cur = node;
    while (cur) {
        set->Insert(&cur->mnKey);
        HNode_aa8748* next = cur->mpNext;
        if (!next) {
            uint32_t n = h->mpBucketsEnd - h->mpBuckets;
            uint32_t idx = cur->mnKey % n;
            idx++;
            while (idx < n) {
                next = h->mpBuckets[idx];
                if (next) {
                    break;
                }
                idx++;
            }
        }
        cur = next;
    }
}
#endif

// ---- batch 5 ----
// The network occupants: slots by their offsets in the vtable.
struct NetOcc_aa8748 {
    virtual bool Query(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
    virtual void SetPosition(float* box);
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void ClearFlags(uint32_t f);
    // slot 17 (0x44) is declared below as Fn44
    virtual void SetFlags(uint32_t f);
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void Fn44(uint32_t a, uint32_t b);
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
    virtual void SetEdge(uint32_t i, uint32_t v);
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
    virtual void SetPlacement(uint32_t a, uint32_t b);
    virtual void P65();
    virtual void P66();
    virtual void P67();
    virtual void P68();
    virtual void P69();
    virtual void SetByte(uint32_t v);
};
struct Shear_aa8748 {
    // STUB: 0x0061d230
    void Recompute();
    virtual void P0();
    virtual void P1();
    virtual void Release();
};
struct CellInfo_aa8748 {
    uint32_t mnX;
    uint32_t mnZ;
    uint32_t mnFlags;
    NetOcc_aa8748* mpOcc;
    uint8_t mPad10[8];
    uint32_t mnEdge[13];
    uint8_t mbByte;
    uint8_t mPad51[7];
    float mfY58, mfY5c, mfY60, mfY64;
};
// GLOBAL: 0x00aa835c
extern uint32_t gFlags_aa8748[];
struct CityScale_aa8748 {
    virtual void P0(); virtual void P1(); virtual void P2(); virtual void P3(); virtual void P4(); virtual void P5();
    virtual float Fn18();
};
struct Occ6476f0_aa8748 { Occ6476f0_aa8748(); };
// STUB: 0x00647230
void* OpNew647230_aa8748(uint32_t n);
// STUB: 0x00605040
void* OpNew605040_aa8748(uint32_t n);
// STUB: 0x0061d200
void* OpNew61d200_aa8748(uint32_t n);
// STUB: 0x00619e90
void* OpNew619e90_aa8748(uint32_t n);
struct OccMem_aa8748 {
    // STUB: 0x006476f0
    NetOcc_aa8748* Ctor6476f0(uint32_t heap);
    // STUB: 0x00605160
    NetOcc_aa8748* Ctor605160(uint32_t heap);
    // STUB: 0x0061e1a0
    NetOcc_aa8748* Ctor61e1a0(uint32_t heap);
    // STUB: 0x0061bdd0
    NetOcc_aa8748* Ctor61bdd0(uint32_t heap);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00624210 score 0
void cSC4NetworkTool::CreateNetworkOccupant(uint32_t cellInfo, uint32_t outOcc, uint32_t floats, uint32_t type)
{
    CityScale_aa8748* city = static_cast<CityScale_aa8748*>(reinterpret_cast<View_aa8748*>(this)->mpCity);
    float scale = city->Fn18();
    CellInfo_aa8748* ci = OB_PTR(CellInfo_aa8748, cellInfo);
    float* f = OB_PTR(float, floats);
    f[0] = static_cast<float>(ci->mnX) * scale;
    f[2] = static_cast<float>(ci->mnZ) * scale;
    f[1] = ci->mfY58;
    f[3] = f[0];
    f[5] = scale + f[2];
    f[4] = ci->mfY5c;
    f[6] = scale + f[0];
    f[8] = f[5];
    f[7] = ci->mfY60;
    f[9] = f[6];
    f[11] = f[2];
    f[10] = ci->mfY64;
    NetOcc_aa8748* occ;
    if (type == 0) {
        occ = static_cast<OccMem_aa8748*>(OpNew619e90_aa8748(0x180))->Ctor61bdd0(1);
    } else if (type == 0x49c1a034) {
        occ = static_cast<OccMem_aa8748*>(OpNew61d200_aa8748(0x1d8))->Ctor61e1a0(1);
    } else if (type == 0x49cc1bcd) {
        occ = static_cast<OccMem_aa8748*>(OpNew605040_aa8748(0x1f0))->Ctor605160(1);
    } else if (type == 0x8a4bd52b) {
        occ = static_cast<OccMem_aa8748*>(OpNew647230_aa8748(0x1e0))->Ctor6476f0(1);
    } else {
        occ = 0;
    }
    NetOcc_aa8748** out = OB_PTR(NetOcc_aa8748*, outOcc);
    *out = occ;
    occ->AddRef();
    uint8_t active = reinterpret_cast<uint8_t*>(this)[0x50];
    uint32_t flags;
    if (active) {
        NetOcc_aa8748* old = ci->mpOcc;
        NetOcc_aa8748* nw = *out;
        if (nw != old) {
            if (nw) {
                nw->AddRef();
            }
            ci->mpOcc = nw;
            if (old) {
                old->Release();
            }
        }
        flags = ci->mnFlags;
    } else {
        flags = ci->mnFlags & 0xc0000;
    }
    occ->ClearFlags(flags);
    occ->SetPosition(f);
    if (reinterpret_cast<uint8_t*>(this)[0x50]) {
        occ->SetFlags(0x80000000);
    } else {
        occ->ClearFlags(0x80000000);
    }
    Shear_aa8748* shear = 0;
    if (occ->Query(0x49c1a034, reinterpret_cast<void**>(&shear))) {
        shear->Recompute();
    }
    if (type == 0x8a4bd52b) {
        occ->ClearFlags(0x10000000);
        occ->SetFlags(0x4000);
    } else {
        occ->ClearFlags(0x4000);
    }
    if (reinterpret_cast<uint8_t*>(this)[0x50]) {
        for (uint32_t i = 0; i < 13; i++) {
            if (ci->mnFlags & gFlags_aa8748[i]) {
                occ->SetEdge(i, ci->mnEdge[i]);
            }
        }
        occ->SetByte(ci->mbByte);
    }
    occ->SetPlacement(*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) + 0x32c), 0);
    if (shear) {
        shear->Release();
    }
}
#endif

// ---- AddCellPreview ----
struct NetMgr_aa8748 {
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
    virtual uint32_t Fn34(uint32_t id, uint8_t* sub);
};
struct Preview_aa8748 {
    // STUB: 0x00620cf0
    void Erase(uint32_t* pos);
    // STUB: 0x00620bc0
    void AddTexturedSelection(uint32_t* pos, uint32_t color, float* box, uint32_t* key, uint32_t sub, bool flag, float alt, bool b);
};
struct SolvedCell_aa8748 {
    uint32_t mnId;
    uint8_t mbSub;
};
struct MultiSep_aa8748 {
    // STUB: 0x00633fa0
    bool SolveMultiTypeSeparation(uint32_t* pos, uint32_t type, uint32_t* out, uint8_t* sub, bool* flag);
};
// STUB: 0x00602680
NetMgr_aa8748* Fn00602680_aa8748();
// GLOBAL: 0x00aa83f0
extern float gAlt_aa8748[];

#ifdef OB_DRAFTS
// CLOSE: 0x006246a0 score 0
void cSC4NetworkTool::AddCellPreview(uint32_t cellInfo, uint32_t solved)
{
    CellInfo_aa8748* ci = OB_PTR(CellInfo_aa8748, cellInfo);
    SolvedCell_aa8748* sc = OB_PTR(SolvedCell_aa8748, solved);
    uint8_t* b = reinterpret_cast<uint8_t*>(this);
    if (!reinterpret_cast<uint8_t*>(ci)[0x10]) {
        return;
    }
    uint32_t key[3];
    key[0] = 0;
    key[1] = 0;
    key[2] = 0;
    NetMgr_aa8748* nm = Fn00602680_aa8748();
    uint32_t pos[2];
    pos[0] = ci->mnX;
    pos[1] = ci->mnZ;
    bool flag = (sc->mbSub >> 7) != 0;
    uint8_t sub = sc->mbSub & 0x7f;
    key[0] = 0x7ab50e44;
    key[1] = 0x1abe787d;
    key[2] = nm->Fn34(sc->mnId + *reinterpret_cast<uint32_t*>(b + 0xfc), &sub);
    uint32_t color = (reinterpret_cast<uint8_t*>(ci)[0x52] ? 0xff99b3ffu : 0u) + 0xff664d00u;
    Preview_aa8748* pv = *reinterpret_cast<Preview_aa8748**>(b + 0x1f0);
    pv->Erase(pos);
    uint32_t flags = ci->mnFlags;
    if ((flags & 0x304) == 0 || (flags & 0xfffffcfb) == 0) {
        uint32_t low = flags & ~(flags - 1);
        uint32_t i = 0;
        while (low != gFlags_aa8748[i] && i < 13) {
            i++;
        }
        pv->AddTexturedSelection(pos, color, reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(ci) + 0x58), key, sub, flag, gAlt_aa8748[i], reinterpret_cast<uint8_t*>(ci)[0x56] != 0);
    } else {
        for (uint32_t i = 0; i < 13; i++) {
            if (ci->mnFlags & gFlags_aa8748[i]) {
                uint32_t val;
                if (static_cast<MultiSep_aa8748*>(static_cast<void*>(this))->SolveMultiTypeSeparation(pos, i, &val, &sub, &flag)) {
                    key[2] = nm->Fn34(*reinterpret_cast<uint32_t*>(b + 0xfc) + val, &sub);
                    pv->AddTexturedSelection(pos, color, reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(ci) + 0x58), key, sub, flag, gAlt_aa8748[i], false);
                }
            }
        }
    }
}
#endif

// ---- batch 10 ----

#ifdef OB_DRAFTS
// CLOSE: 0x00625f10 score 0
void cSC4NetworkTool::ClearOccupantHighlights()
{
    uint8_t* b = reinterpret_cast<uint8_t*>(this);
    RbSet_aa8748* set = reinterpret_cast<RbSet_aa8748*>(b + 0x214);
    RbNode_aa8748* head = set->mpHead;
    RbNode_aa8748* end = head;
    for (RbNode_aa8748* n = head->mpLeft; n != end; n = RbNext_aa8748(n)) {
        static_cast<NetOcc_aa8748*>(static_cast<void*>(n->mpValue))->Fn44(0, 0);
    }
    if (set->mnSize != 0) {
        set->Erase(set->mpHead->mpParent);
        set->mpHead->mpLeft = set->mpHead;
        set->mpHead->mpParent = 0;
        set->mpHead->mpRight = set->mpHead;
        set->mnSize = 0;
    }
    uint32_t* m = *reinterpret_cast<uint32_t**>(b + 0x210);
    if (m) {
        m[4] = 0xa86364;
        void** items = reinterpret_cast<void**>(m[8]);
        if (items) {
            for (uint32_t i = 0; i < m[5]; i++) {
                ::operator delete(items[i]);
            }
            ::operator delete(items);
        }
        ::operator delete(m);
        *reinterpret_cast<uint32_t*>(b + 0x210) = 0;
    }
}
#endif

// ---- batch 10b ----

// The terrain the tool edits (slots by their offsets).
struct Terrain_aa8748 {
    virtual void P0(); virtual void P1(); virtual void P2(); virtual void P3(); virtual void P4(); virtual void P5();
    virtual void P6(); virtual void P7(); virtual void P8(); virtual void P9(); virtual void P10(); virtual void P11();
    virtual float GetHeight(uint32_t v);
    virtual void P13(); virtual void P14(); virtual void P15(); virtual void P16(); virtual void P17(); virtual void P18();
    virtual void P19(); virtual void P20(); virtual void P21(); virtual void P22(); virtual void P23(); virtual void P24();
    virtual void P25(); virtual void P26(); virtual void P27(); virtual void P28(); virtual void P29(); virtual void P30();
    virtual void P31(); virtual void P32(); virtual void P33(); virtual void P34(); virtual void P35(); virtual void P36();
    virtual void P37(); virtual void P38(); virtual void P39(); virtual void P40(); virtual void P41(); virtual void P42();
    virtual void P43(); virtual void P44(); virtual void P45(); virtual void P46(); virtual void P47(); virtual void P48();
    virtual void P49();
    virtual void SetHeight(uint32_t v, float h);
    virtual void P51(); virtual void P52(); virtual void P53(); virtual void P54(); virtual void P55(); virtual void P56();
    virtual void P57(); virtual void P58(); virtual void P59(); virtual void P60(); virtual void P61(); virtual void P62();
    virtual void P63(); virtual void P64(); virtual void P65(); virtual void P66(); virtual void P67(); virtual void P68();
    virtual void P69(); virtual void P70(); virtual void P71(); virtual void P72(); virtual void P73(); virtual void P74();
    virtual void P75(); virtual void P76(); virtual void P77(); virtual void P78(); virtual void P79(); virtual void P80();
    virtual void P81(); virtual void P82(); virtual void P83(); virtual void P84(); virtual void P85(); virtual void P86();
    virtual void Begin();
    virtual void P88();
    virtual void Update(uint32_t a, uint32_t b, int32_t* rect, uint32_t c);
    virtual void End();
};
// STUB: 0x0051ca60
void Fn0051ca60_aa8748(void* vec, uint32_t* where, uint32_t* v, uint32_t a, uint32_t b);

// The signature takes a vector of the changed vertices.
#ifdef OB_DRAFTS
// CLOSE: 0x00644530 score 0
void cSC4NetworkTool::UpdateTerrainHeights(uint32_t vecArg)
{
    uint8_t* b = reinterpret_cast<uint8_t*>(this);
    std::vector<uint32_t>* changed = OB_PTR(std::vector<uint32_t>, vecArg);
    int32_t rect[4];
    rect[0] = *reinterpret_cast<int32_t*>(b + 0x248);
    rect[1] = *reinterpret_cast<int32_t*>(b + 0x24c);
    rect[2] = -1;
    rect[3] = -1;
    changed->clear();
    SatMap_aa8748* sat = reinterpret_cast<SatMap_aa8748*>(b + 0x188);
    reinterpret_cast<SatMap_aa8748*>(sat)->Fn0065ef70();
    uint32_t vtx;
    uint32_t hbits;
    Terrain_aa8748* terrain = static_cast<Terrain_aa8748*>(reinterpret_cast<View_aa8748*>(this)->mpCity);
    while (sat->Fn0065eb50(&vtx, &hbits)) {
        float h = *reinterpret_cast<float*>(&hbits);
        float diff = h - terrain->GetHeight(vtx);
        if (diff < 0) {
            diff = -diff;
        }
        if (diff > 0.001f) {
            terrain->SetHeight(vtx, h);
            changed->push_back(vtx);
            int32_t x = vtx % *reinterpret_cast<uint32_t*>(b + 0x248);
            int32_t z = vtx / *reinterpret_cast<uint32_t*>(b + 0x24c);
            if (x < rect[0]) {
                rect[0] = x;
            }
            if (x > rect[2]) {
                rect[2] = x;
            }
            if (z < rect[1]) {
                rect[1] = z;
            }
            if (z > rect[3]) {
                rect[3] = z;
            }
        }
    }
    if (rect[1] != 0) {
        rect[1]--;
    }
    if (rect[0] != 0) {
        rect[0]--;
    }
    if (rect[2] < static_cast<int32_t>(gpB43cec->CellCountX())) {
        rect[2]++;
    }
    if (rect[3] < static_cast<int32_t>(gpB43cec->CellCountZ())) {
        rect[3]++;
    }
    if (rect[0] <= rect[2] && rect[1] <= rect[3]) {
        terrain->Begin();
        terrain->Update(1, 1, rect, 4);
        terrain->End();
    }
}
#endif

// ---- batch 11: the occupant constructors (raw vtable stores over a byte view) ----

#define OBW32_aa8748(base, off) (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(base) + (off)))
#define OBW8_aa8748(base, off) (*(reinterpret_cast<uint8_t*>(base) + (off)))

// GLOBAL: 0x00b45298
extern uint32_t g00b45298;

struct OccBase_aa8748 {
    // STUB: 0x0061bdd0
    OccBase_aa8748* Ctor61bdd0(uint32_t heap);
    // STUB: 0x0061e1a0
    OccBase_aa8748* Ctor61e1a0(uint32_t heap);
    // STUB: 0x005e8670
    void Fn005e8670();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0061e1a0 score 0
OccBase_aa8748* OccBase_aa8748::Ctor61e1a0(uint32_t heap)
{
    if (heap != 0) {
        OBW32_aa8748(this, 0x3c) = 0xaa81fc;
        OBW32_aa8748(this, 0x1d4) = 0xaa1f38;
    }
    Ctor61bdd0(0);
    uint32_t vb = OBW32_aa8748(this, 0x3c);
    OBW32_aa8748(this, 0) = 0xaa7038;
    OBW32_aa8748(this, 4) = 0xaa6fb0;
    OBW32_aa8748(this, 8) = 0xaa6f94;
    OBW32_aa8748(this, 0xc) = 0xaa6f30;
    OBW32_aa8748(this, 0x20) = 0xaa6f18;
    OBW32_aa8748(this, 0x38) = 0xaa6f14;
    uint32_t d1 = OBW32_aa8748(reinterpret_cast<uint8_t*>(vb), 4);
    OBW32_aa8748(this, d1 + 0x3c) = 0xaa6ec8;
    uint32_t d2 = OBW32_aa8748(reinterpret_cast<uint8_t*>(OBW32_aa8748(this, 0x3c)), 4);
    OBW32_aa8748(this, d2 + 0x38) = d2 - 0x198;
    OBW32_aa8748(this, 0x184) = g00b45298;
    OBW32_aa8748(this, 0x188) = g00b45298;
    OBW32_aa8748(this, 0x18c) = g00b45298;
    OBW32_aa8748(this, 0x190) = g00b45298;
    OBW32_aa8748(this, 0x194) = g00b45298;
    OBW32_aa8748(this, 0x198) = g00b45298;
    OBW32_aa8748(this, 0x1a4) = g00b45298;
    OBW32_aa8748(this, 0x1a8) = g00b45298;
    OBW32_aa8748(this, 0x1ac) = g00b45298;
    OBW32_aa8748(this, 0x1b0) = 0;
    OBW8_aa8748(this, 0x1b4) = 0;
    OBW32_aa8748(this, 0x1b8) = 0xffffffff;
    OBW32_aa8748(this, 0x1bc) = 0xffffffff;
    OBW8_aa8748(this, 0x1c0) = 0xff;
    OBW8_aa8748(this, 0x1c1) = 0xff;
    OBW32_aa8748(this, 0x1c4) = 0;
    OBW32_aa8748(this, 0x1c8) = 0;
    OBW32_aa8748(this, 0x16c) = 0;
    OBW32_aa8748(this, 0x168) = 0;
    OBW32_aa8748(this, 0x13c) |= 0x400000;
    OBW32_aa8748(this, 0x184) = 0;
    OBW32_aa8748(this, 0x188) = 0;
    OBW32_aa8748(this, 0x18c) = 0;
    OBW32_aa8748(this, 0x190) = 0;
    OBW32_aa8748(this, 0x194) = 0;
    OBW32_aa8748(this, 0x198) = 0;
    OBW32_aa8748(this, 0x19c) = 0;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00605160 score 0
OccBase_aa8748* Ctor605160_aa8748(OccBase_aa8748* self, uint32_t heap)
{
    if (heap != 0) {
        OBW32_aa8748(self, 0x3c) = 0xaa7448;
        OBW32_aa8748(self, 0x1ec) = 0xaa1f38;
    }
    self->Ctor61e1a0(0);
    uint32_t vb = OBW32_aa8748(self, 0x3c);
    OBW32_aa8748(self, 0) = 0xaa7300;
    OBW32_aa8748(self, 4) = 0xaa7278;
    OBW32_aa8748(self, 8) = 0xaa725c;
    OBW32_aa8748(self, 0xc) = 0xaa71f8;
    OBW32_aa8748(self, 0x20) = 0xaa71e0;
    OBW32_aa8748(self, 0x38) = 0xaa71dc;
    uint32_t d1 = OBW32_aa8748(reinterpret_cast<uint8_t*>(vb), 4);
    OBW32_aa8748(self, d1 + 0x3c) = 0xaa7190;
    uint32_t d2 = OBW32_aa8748(reinterpret_cast<uint8_t*>(OBW32_aa8748(self, 0x3c)), 4);
    OBW32_aa8748(self, d2 + 0x38) = d2 - 0x1b0;
    reinterpret_cast<OccBase_aa8748*>(reinterpret_cast<uint8_t*>(self) + 0x1d0)->Fn005e8670();
    OBW32_aa8748(self, 0x13c) |= 0xc00000;
    return self;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006476f0 score 0
OccBase_aa8748* Ctor6476f0_aa8748(OccBase_aa8748* self, uint32_t heap)
{
    if (heap != 0) {
        OBW32_aa8748(self, 0x3c) = 0xaa9450;
        OBW32_aa8748(self, 0x1dc) = 0xaa1f38;
    }
    self->Ctor61e1a0(0);
    uint32_t vb = OBW32_aa8748(self, 0x3c);
    OBW32_aa8748(self, 0) = 0xaa9308;
    OBW32_aa8748(self, 4) = 0xaa9280;
    OBW32_aa8748(self, 8) = 0xaa9264;
    OBW32_aa8748(self, 0xc) = 0xaa9200;
    OBW32_aa8748(self, 0x20) = 0xaa91e8;
    OBW32_aa8748(self, 0x38) = 0xaa91e4;
    uint32_t d1 = OBW32_aa8748(reinterpret_cast<uint8_t*>(vb), 4);
    OBW32_aa8748(self, d1 + 0x3c) = 0xaa9198;
    uint32_t d2 = OBW32_aa8748(reinterpret_cast<uint8_t*>(OBW32_aa8748(self, 0x3c)), 4);
    OBW32_aa8748(self, d2 + 0x38) = d2 - 0x1a0;
    OBW32_aa8748(self, 0x1d0) = 0;
    OBW32_aa8748(self, 0x13c) = (OBW32_aa8748(self, 0x13c) & 0xffffbfff) | 0x10c00000;
    return self;
}
#endif

// A container of the preview: two ordered trees, three vectors and a byte block (vtables 0xa881c0 / 0xaa8314).
struct Raw8314_aa8748 {
    virtual void P0();
    Raw8314_aa8748();
};
// STUB: 0x0090da1e
void Fn0090da1e_aa8748(void* self);

#ifdef OB_DRAFTS
// CLOSE: 0x00620ad0 score 0
Raw8314_aa8748::Raw8314_aa8748()
{
    uint8_t* b = reinterpret_cast<uint8_t*>(this);
    Fn0090da1e_aa8748(b + 4);
    OBW32_aa8748(this, 0xc) = 0;
    OBW32_aa8748(this, 0x10) = 0;
    uint32_t* t1 = static_cast<uint32_t*>(StlNew_aa8748(0x7c));
    OBW32_aa8748(this, 0x10) = reinterpret_cast<uint32_t>(t1);
    OBW32_aa8748(this, 0x14) = 0;
    *reinterpret_cast<uint8_t*>(t1) = 0;
    t1[1] = 0;
    t1[2] = reinterpret_cast<uint32_t>(t1);
    t1[3] = reinterpret_cast<uint32_t>(t1);
    OBW32_aa8748(this, 0x1c) = 0;
    uint32_t* t2 = static_cast<uint32_t*>(StlNew_aa8748(0x80));
    OBW32_aa8748(this, 0x1c) = reinterpret_cast<uint32_t>(t2);
    OBW32_aa8748(this, 0x20) = 0;
    *reinterpret_cast<uint8_t*>(t2) = 0;
    t2[1] = 0;
    t2[2] = reinterpret_cast<uint32_t>(t2);
    t2[3] = reinterpret_cast<uint32_t>(t2);
    OBW32_aa8748(this, 0x28) = 0;
    OBW32_aa8748(this, 0x2c) = 0;
    OBW32_aa8748(this, 0x30) = 0;
    OBW32_aa8748(this, 0x34) = 0;
    OBW32_aa8748(this, 0x38) = 0;
    OBW32_aa8748(this, 0x3c) = 0;
    OBW32_aa8748(this, 0x40) = 0;
    OBW32_aa8748(this, 0x44) = 0;
    OBW8_aa8748(this, 0x48) = 1;
    OBW8_aa8748(this, 0x49) = 0;
    OBW8_aa8748(this, 0x4a) = 3;
    OBW8_aa8748(this, 0x4b) = 1;
    OBW8_aa8748(this, 0x4c) = 1;
    OBW8_aa8748(this, 0x4d) = 0;
    OBW8_aa8748(this, 0x4e) = 3;
    OBW8_aa8748(this, 0x4f) = 1;
    OBW8_aa8748(this, 0x50) = 0;
    OBW8_aa8748(this, 0x51) = 0;
    OBW8_aa8748(this, 0x52) = 0;
    OBW8_aa8748(this, 0x53) = 0;
    OBW8_aa8748(this, 0x54) = 0;
}
#endif

// ---- batch 12: the vertex height constraint satisfier ----

#ifdef OB_DRAFTS
// CLOSE: 0x00660b10 score 0
bool SatMap_aa8748::Solve()
{
    std::set<int32_t> picked;
    mbDirty = DoInitialConstraintPropagation();
    int32_t left = OBW32_aa8748(this, 0x38);
    while (mbDirty && OBW32_aa8748(this, 0x38) != 0) {
        if (left <= 0) {
            mbDirty = 0;
            break;
        }
        int32_t vtx;
        float h;
        bool flag;
        mbDirty = PickASolution(&vtx, &h, &flag);
        if (!mbDirty) {
            continue;
        }
        if (flag) {
            picked.insert(vtx);
            mbDirty = PropagateRangeConstraintsOfVerts(&picked);
            left--;
        }
        if (!mbDirty) {
            continue;
        }
        MarkSolution(vtx, *reinterpret_cast<uint32_t*>(&h));
        left = OBW32_aa8748(this, 0x38);
    }
    Fn0065fbe0();
    if (!mbDirty) {
        DumpConstraints();
    }
    return mbDirty != 0;
}
#endif

// The equality sets of the satisfier: a list of sets of vertices at +0x3c.
struct EqSetList_aa8748 {
    // STUB: 0x00809580
    void Remove(void* setPtr);
    // STUB: 0x0065eaa0
    void FreeSet(uint32_t flag);
};
struct EqSet_aa8748 {
    // STUB: 0x0046c0e0
    void Insert(void* result, int32_t* v);
};
// STUB: 0x0065e8c0
void* Fn0065e8c0_aa8748(void* mem);
// STUB: 0x005e55e0
void* Fn005e55e0_aa8748(uint32_t n);
// (list push_back, inlined in the original: draft-only stand-in)
void Fn0089ec00_aa8748(void* list, void* val);

#ifdef OB_DRAFTS
// CLOSE: 0x0065fdb0 score 0
void SatMap_aa8748::InsertEqualityConstraint(int32_t a, int32_t b)
{
    MarkConstraintAboutVert(a, 8);
    MarkConstraintAboutVert(b, 8);
    EqSet_aa8748* sa = static_cast<EqSet_aa8748*>(FindEqualitySet(a));
    EqSet_aa8748* sb = static_cast<EqSet_aa8748*>(FindEqualitySet(b));
    uint32_t res[2];
    if (sa == 0) {
        if (sb == 0) {
            void* mem = Fn005e55e0_aa8748(0xc);
            EqSet_aa8748* s = static_cast<EqSet_aa8748*>(mem ? Fn0065e8c0_aa8748(mem) : 0);
            Fn0089ec00_aa8748(reinterpret_cast<uint8_t*>(this) + 0x3c, &s);
            s->Insert(res, &a);
            s->Insert(res, &b);
        } else {
            sb->Insert(res, &a);
        }
    } else if (sb == 0) {
        sa->Insert(res, &b);
    } else if (sa != sb) {
        MergeEqualitySets(sa, sb);
        reinterpret_cast<EqSetList_aa8748*>(reinterpret_cast<uint8_t*>(this) + 0x3c)->Remove(&sb);
        reinterpret_cast<EqSetList_aa8748*>(sb)->FreeSet(1);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0065fbe0 score 0
void SatMap_aa8748::DeleteConstraintsAndOtherTemporaryData()
{
    reinterpret_cast<MapOps_aa8748*>(reinterpret_cast<uint8_t*>(this) + 0x28)->Clear();
    for (int i = 0; i < 4; i++) {
        uint32_t* head = reinterpret_cast<uint32_t*>(OBW32_aa8748(this, 0x3c + i * 4));
        uint32_t* n = reinterpret_cast<uint32_t*>(head[0]);
        while (n != head) {
            uint32_t* next = reinterpret_cast<uint32_t*>(n[0]);
            ::operator delete(n);
            n = next;
        }
        head[0] = reinterpret_cast<uint32_t>(head);
        head[1] = reinterpret_cast<uint32_t>(head);
    }
    OBW32_aa8748(this, 0x50) = OBW32_aa8748(this, 0x54);
}
#endif

// ---- batch 13: rough drafts following the calls ----

// One vertex record of the satisfier (a hash node): next, key, then the range and the state.
struct SatVert_aa8748 {
    SatVert_aa8748* mpNext;
    uint32_t mnKey;
    float mfLo;
    float mfHi;
    float mfSolved;
    float mfA;
    float mfB;
    uint32_t mnFlags;
};
struct SatIter_aa8748 {
    // STUB: 0x004b0390
    void Begin(SatVert_aa8748** out);
    // STUB: 0x0053dcf0
    SatVert_aa8748* NextBucket();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0065ed80 score 0
bool PickASolution_aa8748(SatMap_aa8748* self, int32_t* vtx, float* h, bool* flag)
{
    *flag = false;
    uint32_t* stackBegin = reinterpret_cast<uint32_t*>(OBW32_aa8748(self, 0x50));
    uint32_t* stackEnd = reinterpret_cast<uint32_t*>(OBW32_aa8748(self, 0x54));
    if (stackBegin != stackEnd) {
        *vtx = stackEnd[-2];
        *h = *reinterpret_cast<float*>(&stackEnd[-1]);
        OBW32_aa8748(self, 0x54) = reinterpret_cast<uint32_t>(stackEnd - 2);
        return true;
    }
    float best = 3.4028235e38f;
    SatVert_aa8748* pick = 0;
    int32_t pickKey = 0;
    SatVert_aa8748* node = 0;
    reinterpret_cast<SatIter_aa8748*>(self)->Begin(&node);
    while (node) {
        float width = node->mfHi - node->mfLo;
        if (width < 0.0f) {
            OBW32_aa8748(self, 0x10) = node->mnKey;
            return false;
        }
        if (width < best) {
            pickKey = static_cast<int32_t>(node->mnKey);
            pick = node;
            best = width;
        }
        if (best == 0.0f) {
            break;
        }
        SatVert_aa8748* next = node->mpNext;
        if (!next) {
            next = reinterpret_cast<SatIter_aa8748*>(self)->NextBucket();
        }
        node = next;
    }
    *vtx = pickKey;
    float lo = pick->mfLo;
    float hi = pick->mfHi;
    float target = pick->mfSolved;
    if ((pick->mnFlags & 4) != 0) {
        if (lo < pick->mfA) {
            lo = pick->mfA;
        }
        if (pick->mfB < hi) {
            hi = pick->mfB;
        }
    }
    if (hi < target) {
        *h = hi;
    } else if (target < lo) {
        *h = lo;
    } else {
        *h = target;
    }
    *flag = pick->mfLo != pick->mfHi;
    pick->mfHi = *h;
    pick->mfLo = *h;
    pick->mnFlags |= 0x40;
    return true;
}
#endif
