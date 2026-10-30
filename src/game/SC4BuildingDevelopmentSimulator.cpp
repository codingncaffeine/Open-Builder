#include <cstddef>

#include "classes/cSC4BuildingDevelopmentSimulator.h"
#include "game/Globals.h"

// A field of this object by its offset (the class header has the bytes unnamed).
#define FLD_ab0af8(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

// The construction-resources object kept at +0x70.
struct OB_NOVTABLE Res_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual float Fn08() = 0;
    virtual float Fn09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Fn17(float) = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Pad28() = 0;
    virtual void Pad29() = 0;
    virtual void Fn30() = 0;
};

// The city interface kept at +0x1c.
struct OB_NOVTABLE City_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual uint32_t Fn24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Pad28() = 0;
    virtual void Pad29() = 0;
    virtual void Pad30() = 0;
    virtual void Pad31() = 0;
    virtual void Pad32() = 0;
    virtual void Pad33() = 0;
    virtual void Pad34() = 0;
    virtual void Pad35() = 0;
    virtual void Pad36() = 0;
    virtual void Pad37() = 0;
    virtual void Pad38() = 0;
    virtual void Pad39() = 0;
    virtual void Pad40() = 0;
    virtual void Pad41() = 0;
    virtual void Pad42() = 0;
    virtual void Pad43() = 0;
    virtual void Pad44() = 0;
    virtual void Pad45() = 0;
    virtual void Pad46() = 0;
    virtual void Pad47() = 0;
    virtual void Pad48() = 0;
    virtual void Pad49() = 0;
    virtual void Pad50() = 0;
    virtual void Pad51() = 0;
    virtual void Pad52() = 0;
    virtual void Pad53() = 0;
    virtual void Pad54() = 0;
    virtual void Pad55() = 0;
    virtual void Pad56() = 0;
    virtual void Pad57() = 0;
    virtual void Pad58() = 0;
    virtual void Pad59() = 0;
    virtual void Pad60() = 0;
    virtual void Pad61() = 0;
    virtual void Pad62() = 0;
    virtual void Pad63() = 0;
    virtual void Pad64() = 0;
    virtual void Pad65() = 0;
    virtual void Pad66() = 0;
    virtual void Pad67() = 0;
    virtual void Pad68() = 0;
    virtual void Pad69() = 0;
    virtual void Pad70() = 0;
    virtual void Pad71() = 0;
    virtual void Pad72() = 0;
    virtual void Pad73() = 0;
    virtual void Pad74() = 0;
    virtual void Pad75() = 0;
    virtual void Pad76() = 0;
    virtual void Pad77() = 0;
    virtual void Pad78() = 0;
    virtual void Pad79() = 0;
    virtual void Pad80() = 0;
    virtual void Pad81() = 0;
    virtual void Pad82() = 0;
    virtual void Pad83() = 0;
    virtual void Pad84() = 0;
    virtual void Pad85() = 0;
    virtual void Pad86() = 0;
    virtual void Pad87() = 0;
    virtual void Pad88() = 0;
    virtual void Pad89() = 0;
    virtual void Pad90() = 0;
    virtual void Pad91() = 0;
    virtual void Pad92() = 0;
    virtual void Pad93() = 0;
    virtual void Pad94() = 0;
    virtual void Pad95() = 0;
    virtual void Pad96() = 0;
    virtual void Fn97(uint32_t, uint32_t, uint32_t*, uint32_t*) = 0;
};

// The occupant manager at +0x20 and the occupant it is handed.
struct OB_NOVTABLE OccMgr_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual bool Fn20(uint32_t) = 0;
    virtual bool Fn21(uint32_t, uint32_t, uint32_t) = 0;
};
struct OB_NOVTABLE Occ_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual uint32_t Fn03() = 0;
};
struct OB_NOVTABLE Occ2_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual uint32_t Fn03(uint32_t) = 0;
};

// The object at +0x38 (slot 13 takes two values and returns a float).
struct OB_NOVTABLE Calc_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual float Fn13(uint32_t, uint32_t) = 0;
};

// A global map object whose operator[]-like member returns a pointer to the value.
struct Map_ab0af8 {
    // STUB: 0x004862f0
    void* Fn004862f0(uint32_t* key);
};
struct Map2_ab0af8 {
    // STUB: 0x0069b720
    uint8_t* Fn0069b720(uint32_t* key);
};

// GLOBAL: 0x00b4855c
extern Map_ab0af8 gB4855c;
// GLOBAL: 0x00b48570
extern Map_ab0af8 gB48570;
// GLOBAL: 0x00b48584
extern Map2_ab0af8 gB48584;

// A hash-table node: next, key at +4 (building types) or +8 (profiles).
struct HNode_ab0af8 {
    HNode_ab0af8* mpNext;
    uint32_t mKey4;
    uint32_t mKey8;
    uint32_t mC;
    uint32_t mVal[3];
};
// GLOBAL: 0x00b4854c
extern HNode_ab0af8** gB4854c;
// GLOBAL: 0x00b48550
extern HNode_ab0af8** gB48550;
// GLOBAL: 0x00b48588
extern HNode_ab0af8** gB48588;
// GLOBAL: 0x00b4858c
extern HNode_ab0af8** gB4858c;
// GLOBAL: 0x00b485bc
extern HNode_ab0af8** gB485bc;
// GLOBAL: 0x00b485c0
extern HNode_ab0af8** gB485c0;
// GLOBAL: 0x00b485d0
extern HNode_ab0af8** gB485d0;
// GLOBAL: 0x00b485d4
extern HNode_ab0af8** gB485d4;

// A red-black tree node: color, parent, left, right, then the key (+0x10) and the value.
struct TNode_ab0af8 {
    uint32_t mColor;
    TNode_ab0af8* mpParent;
    TNode_ab0af8* mpLeft;
    TNode_ab0af8* mpRight;
    int32_t mKey0;
    uint32_t mKey1;
    float mVal;
};

// A key of two values: (long, long) and (long, byte).
struct KeyL_ab0af8 {
    int32_t a;
    int32_t b;
};
struct KeyB_ab0af8 {
    int32_t a;
    uint8_t b;
};

// The tree objects: the first word is the header node (its parent is the root).
struct TreeL_ab0af8 {
    TNode_ab0af8* mpHeader;
    // STUB: 0x00695f70
    TNode_ab0af8* Fn00695f70(const KeyL_ab0af8* k);
};
struct TreeB_ab0af8 {
    TNode_ab0af8* mpHeader;
    // STUB: 0x00695f10
    TNode_ab0af8* Fn00695f10(const KeyB_ab0af8* k);
};

// A map of the class (tree whose lookup hands the iterator back through a pointer).
struct TMap_ab0af8 {
    TNode_ab0af8* mpHeader;
    // STUB: 0x006c0030
    TNode_ab0af8** Fn006c0030(TNode_ab0af8** out, const uint32_t* key);
    // STUB: 0x00497520
    TNode_ab0af8** Fn00497520(TNode_ab0af8** out, const uint32_t* key);
};

// GLOBAL: 0x00b485ac
extern TreeB_ab0af8 gB485ac;

// A 12-byte element copied by the vector helpers.
struct Elem12_ab0af8 {
    uint32_t m[3];
    // STUB: 0x004c9470
    void Fn004c9470(const Elem12_ab0af8* src);
};

// The record whose range the helper at 0x0069ac70 destroys.
struct Rec_ab0af8 {
    uint32_t pad[7];
    void* mpBegin;
    void* mpEnd;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);
// STUB: 0x00459170
void Fn00459170(void* first, void* last, void* tag);

// The message the class posts and its constructor.
struct OB_NOVTABLE Msg_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Fn01() = 0;
    virtual void Fn02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Fn05(uint32_t) = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Fn12(uint32_t) = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Fn16(uint32_t) = 0;
};

struct MsgImpl_ab0af8 {
    // STUB: 0x009134d6
    Msg_ab0af8* Fn009134d6();
};
// STUB: 0x009133da
void* Fn009133da(uint32_t size);

// The property holder an occupant hands out.
struct OB_NOVTABLE Prop_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual uint32_t Fn06(uint32_t, void*) = 0;
};

struct OB_NOVTABLE OccP_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual Prop_ab0af8* Fn03() = 0;
};

// STUB: 0x005fd4b0
void Fn005fd4b0(uint32_t value);
// STUB: 0x004696c0
void* Fn004696c0(void* first, void* last, const void* val, const void* tag);

// GLOBAL: 0x00b48558
extern uint32_t gB48558;
// GLOBAL: 0x00b4859c
extern HNode_ab0af8** gB4859c;
// GLOBAL: 0x00b485a0
extern HNode_ab0af8** gB485a0;
// GLOBAL: 0x00b0d1dc
extern float gB0d1dc;

// The resource manager (+ the object it hands back) and the application.
struct OB_NOVTABLE RM_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual bool Fn03(void*, uint32_t, void**, uint32_t, uint32_t) = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual uint32_t Fn18(uint32_t, void**) = 0;
};

struct OB_NOVTABLE Hold_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Release() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void* Fn07() = 0;
};

struct OB_NOVTABLE Hold2_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Release() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Fn07(void*, uint32_t) = 0;
};

struct OB_NOVTABLE App_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Pad28() = 0;
    virtual void Pad29() = 0;
    virtual void Pad30() = 0;
    virtual void Pad31() = 0;
    virtual void Pad32() = 0;
    virtual void Pad33() = 0;
    virtual void Pad34() = 0;
    virtual void Pad35() = 0;
    virtual void Pad36() = 0;
    virtual void Pad37() = 0;
    virtual void Pad38() = 0;
    virtual void Pad39() = 0;
    virtual void Pad40() = 0;
    virtual void Pad41() = 0;
    virtual void Pad42() = 0;
    virtual void Pad43() = 0;
    virtual void Pad44() = 0;
    virtual void Pad45() = 0;
    virtual void Pad46() = 0;
    virtual void Pad47() = 0;
    virtual void Pad48() = 0;
    virtual void Pad49() = 0;
    virtual void Pad50() = 0;
    virtual void Pad51() = 0;
    virtual void Pad52() = 0;
    virtual void Pad53() = 0;
    virtual void Pad54() = 0;
    virtual void Pad55() = 0;
    virtual void Pad56() = 0;
    virtual void Pad57() = 0;
    virtual void Pad58() = 0;
    virtual void Pad59() = 0;
    virtual void Pad60() = 0;
    virtual void Pad61() = 0;
    virtual void Pad62() = 0;
    virtual void Pad63() = 0;
    virtual void Pad64() = 0;
    virtual void Pad65() = 0;
    virtual void Pad66() = 0;
    virtual void Pad67() = 0;
    virtual void Pad68() = 0;
    virtual void Fn69(void*, uint32_t) = 0;
};

// GLOBAL: 0x00b43ca8
extern RM_ab0af8* gpB43ca8_ab0af8;
// GLOBAL: 0x00b43c94
extern App_ab0af8* gpB43c94_ab0af8;
// GLOBAL: 0x00b48540
extern bool gB48540;

// A resource key (type, group, instance).
struct TGI_ab0af8 {
    uint32_t t;
    uint32_t g;
    uint32_t i;
};

// A map from an instance id to a key: operator[] hands back the 12-byte value.
struct KMap_ab0af8 {
    // STUB: 0x004a3470
    TGI_ab0af8* Fn004a3470(uint32_t* key);
};
// GLOBAL: 0x00b485b8
extern KMap_ab0af8 gB485b8;
// GLOBAL: 0x00b485cc
extern KMap_ab0af8 gB485cc;
// GLOBAL: 0x00b48548
extern KMap_ab0af8 gB48548;

// The timer of the daily simulation.
struct Timer_ab0af8 {
    char mBytes[0x14];
    // STUB: 0x0088fedf
    Timer_ab0af8* Fn0088fedf(uint32_t units);
    // STUB: 0x008905c4
    void Start();
    // STUB: 0x00a6d837
    void Fn00a6d837();
};

// Erase helpers of six different trees.
struct TreeE1_ab0af8 { void Fn00695cd0(TNode_ab0af8* n); };
struct TreeE2_ab0af8 { void Fn00695d10(TNode_ab0af8* n); };
struct TreeE3_ab0af8 { void Fn00695d50(TNode_ab0af8* n); };
struct TreeE4_ab0af8 { void Fn00695d90(TNode_ab0af8* n); };
struct TreeE5_ab0af8 { void Fn00695dd0(TNode_ab0af8* n); };
struct TreeE6_ab0af8 { void Fn00695e10(TNode_ab0af8* n); };

// STUB: 0x0069b850
bool Fn0069b850(void* a);
// STUB: 0x0069c370
void Fn0069c370();
void Fn00695fd0();
// STUB: 0x0069d130
void Fn0069d130(TGI_ab0af8* e);
// STUB: 0x0069b910
uint32_t Fn0069b910(void* holder, uint32_t instance, bool flag);
// STUB: 0x005fd480
bool Fn005fd480(void* holder, uint32_t id, uint32_t* out);
// A global map object of the building-type table and its two lookups.
struct TypeMap_ab0af8 {
    // STUB: 0x0069ab40
    TreeL_ab0af8* Fn0069ab40(const uint32_t* key);
};
// GLOBAL: 0x00b485e0
extern TypeMap_ab0af8 gB485e0;
// GLOBAL: 0x00b48544
extern uint32_t gB48544;

// The lot-retaining-wall occupant and what it hands out.
struct OB_NOVTABLE WallProps_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Release() = 0;
    virtual void Fn03(void*) = 0;
};

struct OB_NOVTABLE WallHolder_ab0af8 {
    virtual bool Query(uint32_t, void**) = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Fn06() = 0;
};

struct OB_NOVTABLE WallOcc_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual WallHolder_ab0af8* Fn03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual uint32_t Fn11() = 0;
};

// STUB: 0x00695790
uint32_t Fn00695790(uint32_t a, uint32_t b);
// STUB: 0x00695840
uint32_t Fn00695840(uint32_t a);

// FUNCTION: 0x00695910
uint32_t cSC4BuildingDevelopmentSimulator::Slot49_ab0af8()
{
    Res_ab0af8* res = FLD_ab0af8(Res_ab0af8*, 0x70);
    return static_cast<int32_t>(res->Fn08());
}

#ifdef OB_DRAFTS
// CLOSE: 0x00698d80 score 2
void cSC4BuildingDevelopmentSimulator::Slot31_ab0af8(uint32_t a)
{
    Fn00695840(a);
}
#endif

// FUNCTION: 0x00698d90
uint8_t cSC4BuildingDevelopmentSimulator::Slot42_ab0af8(uint8_t a, uint8_t b)
{
    a = static_cast<uint8_t>(a << 2);
    a += b;
    return ++a;
}

// FUNCTION: 0x0069ab00
void cSC4BuildingDevelopmentSimulator::GetBuildingName(uint32_t id)
{
    gB4855c.Fn004862f0(&id);
}

// FUNCTION: 0x0069ab20
void cSC4BuildingDevelopmentSimulator::GetExemplarName(uint32_t id)
{
    gB48570.Fn004862f0(&id);
}

// FUNCTION: 0x0069ca60
void cSC4BuildingDevelopmentSimulator::GetBuildingProfile(uint32_t id)
{
    gB48584.Fn0069b720(&id);
}

// FUNCTION: 0x00698d60
uint32_t cSC4BuildingDevelopmentSimulator::Slot30_ab0af8(uint32_t a, uint32_t b)
{
    return Fn00695790(a, b);
}

// FUNCTION: 0x00696040
float cSC4BuildingDevelopmentSimulator::GetStagePopulationMultiplier()
{
    City_ab0af8* city = FLD_ab0af8(City_ab0af8*, 0x1c);
    return FLD_ab0af8(float*, 0xd0)[city->Fn24()];
}

// FUNCTION: 0x00695770
void cSC4BuildingDevelopmentSimulator::DemolishFoundationOccupant(void* occupant, uint32_t unused)
{
    Occ_ab0af8* occ = static_cast<Occ_ab0af8*>(occupant);
    uint32_t id = occ->Fn03();
    (void)unused;
    FLD_ab0af8(OccMgr_ab0af8*, 0x20)->Fn21(id, 1, 0);
}

// FUNCTION: 0x00695570
void cSC4BuildingDevelopmentSimulator::PlopBuilding(void* profile)
{
    uint32_t* p = static_cast<uint32_t*>(profile);
    AddNewBuildingOccupant(p[0x14 / 4], p[0x1c / 4], p[0x20 / 4], p[0x18 / 4]);
}

// FUNCTION: 0x006958b0
uint32_t cSC4BuildingDevelopmentSimulator::Slot33_ab0af8(uint32_t a, uint32_t b)
{
    return Slot32_ab0af8(Slot30_ab0af8(a, b));
}

// FUNCTION: 0x006959b0
unsigned int cSC4BuildingDevelopmentSimulator::Release()
{
    if (FLD_ab0af8(int32_t, 0x14) > 1) {
        return --FLD_ab0af8(int32_t, 0x14);
    }
    Slot04_ab0af8();
    delete this;
    return 0;
}

// FUNCTION: 0x0069ccb0
uint8_t cSC4BuildingDevelopmentSimulator::GetBuildingMapKey(uint32_t id)
{
    uint32_t key = id;
    uint8_t* p = gB48584.Fn0069b720(&key);
    uint8_t a = p[0];
    uint8_t b = p[4];
    a = static_cast<uint8_t>(a << 2);
    a += b;
    return ++a;
}

// FUNCTION: 0x00695740
bool cSC4BuildingDevelopmentSimulator::AddNewFoundationOccupant_2(void* occupant)
{
    if (FLD_ab0af8(OccMgr_ab0af8*, 0x20)) {
        return FLD_ab0af8(OccMgr_ab0af8*, 0x20)->Fn20(static_cast<Occ2_ab0af8*>(occupant)->Fn03(0));
    }
    return false;
}

// FUNCTION: 0x00695980
void cSC4BuildingDevelopmentSimulator::ReleaseConstructionResources(uint16_t n)
{
    FLD_ab0af8(Res_ab0af8*, 0x70)->Fn17(static_cast<float>(-static_cast<int32_t>(n)));
    FLD_ab0af8(Res_ab0af8*, 0x70)->Fn30();
}

#ifdef OB_DRAFTS
// CLOSE: 0x006958e0 score 9
uint32_t cSC4BuildingDevelopmentSimulator::GetFreeConstructionResources()
{
    Res_ab0af8* res = FLD_ab0af8(Res_ab0af8*, 0x70);
    float total = res->Fn08();
    int32_t n = static_cast<int32_t>(total - res->Fn09());
    if (n < 0) {
        n = 0;
    }
    return n;
}
#endif

// FUNCTION: 0x00697e30
bool cSC4BuildingDevelopmentSimulator::IsBuildingTypeValid(uint32_t id)
{
    HNode_ab0af8** b = gB4854c;
    uint32_t n = static_cast<uint32_t>(gB48550 - b);
    HNode_ab0af8* node;
    for (node = b[id % n]; node && node->mKey4 != id; node = node->mpNext) {
    }
    return node != 0;
}


#ifdef OB_DRAFTS
// CLOSE: 0x006985c0 score 2
void* cSC4BuildingDevelopmentSimulator::GetBuildingProfilePtr(uint32_t id)
{
    HNode_ab0af8** b = gB48588;
    uint32_t n = static_cast<uint32_t>(gB4858c - b);
    HNode_ab0af8* node;
    for (node = b[id % n]; node && node->mKey8 != id; node = node->mpNext) {
    }
    if (node) {
        return &node->mVal[0];
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00695ca0 score 10
uint32_t OB_STDCALL Fn00695ca0(const KeyB_ab0af8* a, const KeyB_ab0af8* b)
{
    if (a->a < b->a) {
        return 1;
    }
    if (a->a == b->a && a->b < b->b) {
        return 1;
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00699150 score 6
Elem12_ab0af8* Fn00699150(Elem12_ab0af8* first, Elem12_ab0af8* last, Elem12_ab0af8* dest)
{
    while (first != last) {
        if (dest) {
            dest->Fn004c9470(first);
        }
        first += 1;
        dest += 1;
    }
    return dest;
}
#endif

// FUNCTION: 0x00696cc0
uint32_t cSC4BuildingDevelopmentSimulator::Slot52_ab0af8(uint32_t key)
{
    TMap_ab0af8* map = &FLD_ab0af8(TMap_ab0af8, 0xb0);
    TNode_ab0af8* it;
    map->Fn006c0030(&it, &key);
    if (it != map->mpHeader) {
        return it->mKey1;
    }
    return 0;
}

// FUNCTION: 0x00696c80
uint32_t cSC4BuildingDevelopmentSimulator::Slot32_ab0af8(uint32_t key)
{
    TMap_ab0af8* map = &FLD_ab0af8(TMap_ab0af8, 0x5c);
    TNode_ab0af8* it;
    uint32_t k = key;
    map->Fn00497520(&it, &k);
    if (it != map->mpHeader) {
        return it->mKey1;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00695f70 score 45
TNode_ab0af8* Fn00695f70Draft_ab0af8(TreeL_ab0af8* self, const KeyL_ab0af8* k)
{
    TNode_ab0af8* y = self->mpHeader;
    TNode_ab0af8* x = y->mpParent;
    while (x) {
        if (x->mKey0 < k->a || (!(k->a < x->mKey0) && static_cast<int32_t>(x->mKey1) < k->b)) {
            x = x->mpRight;
        } else {
            y = x;
            x = x->mpLeft;
        }
    }
    if (y == self->mpHeader || k->a < y->mKey0 || (!(y->mKey0 < k->a) && k->b < static_cast<int32_t>(y->mKey1))) {
        return self->mpHeader;
    }
    return y;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00695f10 score 45
TNode_ab0af8* Fn00695f10Draft_ab0af8(TreeB_ab0af8* self, const KeyB_ab0af8* k)
{
    TNode_ab0af8* y = self->mpHeader;
    TNode_ab0af8* x = y->mpParent;
    while (x) {
        if (x->mKey0 < k->a || (!(k->a < x->mKey0) && static_cast<uint8_t>(x->mKey1) < k->b)) {
            x = x->mpRight;
        } else {
            y = x;
            x = x->mpLeft;
        }
    }
    if (y == self->mpHeader || k->a < y->mKey0 || (!(y->mKey0 < k->a) && k->b < static_cast<uint8_t>(y->mKey1))) {
        return self->mpHeader;
    }
    return y;
}
#endif

// FUNCTION: 0x00696c20
float cSC4BuildingDevelopmentSimulator::Slot45_ab0af8(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t v = 0;
    KeyB_ab0af8 key;
    key.a = a;
    key.b = static_cast<uint8_t>(Slot42_ab0af8(static_cast<uint8_t>(b), static_cast<uint8_t>(c)));
    TNode_ab0af8* node = gB485ac.Fn00695f10(&key);
    if (node != gB485ac.mpHeader) {
        v = static_cast<int32_t>(node->mVal);
    }
    return static_cast<float>(v);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00695920 score 22
bool cSC4BuildingDevelopmentSimulator::ClaimConstructionResources(uint16_t n)
{
    float f = static_cast<float>(n);
    Res_ab0af8* res = FLD_ab0af8(Res_ab0af8*, 0x70);
    float sum = res->Fn09() + f;
    if (res->Fn08() < sum) {
        return false;
    }
    FLD_ab0af8(Res_ab0af8*, 0x70)->Fn17(f);
    FLD_ab0af8(Res_ab0af8*, 0x70)->Fn30();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00697dd0 score 2
bool cSC4BuildingDevelopmentSimulator::GetBuildingKeyFromType(uint32_t id, uint32_t out)
{
    HNode_ab0af8** b = gB4854c;
    uint32_t n = static_cast<uint32_t>(gB48550 - b);
    HNode_ab0af8* node;
    for (node = b[id % n]; node && node->mKey4 != id; node = node->mpNext) {
    }
    if (node) {
        uint32_t* o = OB_PTR(uint32_t, out);
        o[0] = node->mKey8;
        o[1] = node->mC;
        o[2] = node->mVal[0];
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00698120 score 2
bool cSC4BuildingDevelopmentSimulator::GetFoundationKeyFromType(uint32_t id, uint32_t out)
{
    HNode_ab0af8** b = gB485bc;
    uint32_t n = static_cast<uint32_t>(gB485c0 - b);
    HNode_ab0af8* node;
    for (node = b[id % n]; node && node->mKey4 != id; node = node->mpNext) {
    }
    if (node) {
        uint32_t* o = OB_PTR(uint32_t, out);
        o[0] = node->mKey8;
        o[1] = node->mC;
        o[2] = node->mVal[0];
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00698250 score 2
bool cSC4BuildingDevelopmentSimulator::GetLotRetainingWallKeyFromType(uint32_t id, uint32_t out)
{
    HNode_ab0af8** b = gB485d0;
    uint32_t n = static_cast<uint32_t>(gB485d4 - b);
    HNode_ab0af8* node;
    for (node = b[id % n]; node && node->mKey4 != id; node = node->mpNext) {
    }
    if (node) {
        uint32_t* o = OB_PTR(uint32_t, out);
        o[0] = node->mKey8;
        o[1] = node->mC;
        o[2] = node->mVal[0];
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0069ac70 score 26
void OB_STDCALL Fn0069ac70(Rec_ab0af8* p)
{
    Rec_ab0af8* q = p;
    Fn00459170(q->mpBegin, q->mpEnd, &p);
    if (q->mpBegin) {
        Fn0090cf63(q->mpBegin);
    }
    if (q) {
        Fn0090cf63(q);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00695840 score 6
uint32_t Fn00695840Draft_ab0af8(uint32_t a)
{
    switch (a) {
    case 0x1010:
    case 0x3110:
    case 0x4100:
        return 1;
    case 0x1020:
    case 0x3120:
    case 0x3320:
    case 0x4200:
    case 0x4300:
        return 2;
    case 0x1030:
    case 0x3130:
    case 0x3330:
    case 0x4400:
        return 3;
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00695790 score 3
uint32_t Fn00695790Draft_ab0af8(uint32_t a, uint32_t b)
{
    switch (a) {
    case 1:
        switch (b) {
        case 1: return 0x1010;
        case 2: return 0x1020;
        case 3: return 0x1030;
        }
        break;
    case 2:
        switch (b) {
        case 1: return 0x3110;
        case 2: return 0x3120;
        case 3: return 0x3130;
        }
        break;
    case 3:
        switch (b) {
        case 2: return 0x3320;
        case 3: return 0x3330;
        }
        break;
    case 4: return 0x4100;
    case 5: return 0x4200;
    case 6: return 0x4300;
    case 7: return 0x4400;
    }
    return 0;
}
#endif

// FUNCTION: 0x00695fd0
void Fn00695fd0()
{
    cIGZMessageServer2* ms = gpB43ccc;
    if (ms) {
        void* mem = Fn009133da(0x2c);
        Msg_ab0af8* m = mem ? static_cast<MsgImpl_ab0af8*>(mem)->Fn009134d6() : 0;
        m->Fn01();
        m->Fn05(0xa783ebc8);
        m->Fn12(0);
        m->Fn16(gB48558);
        ms->MessagePost(m, false);
        m->Fn02();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00697e70 score 24
bool cSC4BuildingDevelopmentSimulator::IsBuildingFamilyTypeValid(uint32_t id)
{
    HNode_ab0af8** b = gB4859c;
    uint32_t n = static_cast<uint32_t>(gB485a0 - b);
    HNode_ab0af8* node;
    for (node = b[id % n]; node && node->mKey4 != id; node = node->mpNext) {
    }
    if (node) {
        return true;
    }
    b = gB4854c;
    n = static_cast<uint32_t>(gB48550 - b);
    for (node = b[id % n]; node && node->mKey4 != id; node = node->mpNext) {
    }
    return node != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00697fe0 score 21
bool cSC4BuildingDevelopmentSimulator::IsBuildingInFamily(uint32_t building, uint32_t family)
{
    if (building == family) {
        return true;
    }
    HNode_ab0af8** b = gB4859c;
    uint32_t n = static_cast<uint32_t>(gB485a0 - b);
    HNode_ab0af8* node;
    for (node = b[family % n]; node && node->mKey4 != family; node = node->mpNext) {
    }
    if (node) {
        void* last = reinterpret_cast<void*>(node->mC);
        void* first = reinterpret_cast<void*>(node->mKey8);
        return Fn004696c0(first, last, &building, &building) != last;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00695610 score 6
void cSC4BuildingDevelopmentSimulator::Fn00695610(void* in, void* out)
{
    const float* f = static_cast<const float*>(in);
    int32_t* o = static_cast<int32_t*>(out);
    o[0] = static_cast<int32_t>(gB0d1dc * f[0]);
    o[1] = static_cast<int32_t>(gB0d1dc * f[1]);
    o[2] = static_cast<int32_t>(gB0d1dc * f[2]);
    o[3] = static_cast<int32_t>(gB0d1dc * f[3]);
    if (o[0] < 0) {
        o[0] = 0;
    }
    if (o[1] < 0) {
        o[1] = 0;
    }
    if (o[2] >= FLD_ab0af8(int32_t, 0x40)) {
        o[2] = FLD_ab0af8(int32_t, 0x40) - 1;
    }
    if (o[3] >= FLD_ab0af8(int32_t, 0x44)) {
        o[3] = FLD_ab0af8(int32_t, 0x44) - 1;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006956a0 score 22
void cSC4BuildingDevelopmentSimulator::AddNewBuildingOccupant(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t x;
    uint32_t y;
    FLD_ab0af8(City_ab0af8*, 0x1c)->Fn97(b, c, &y, &x);
    float z = FLD_ab0af8(Calc_ab0af8*, 0x38)->Fn13(y, x);
    AddNewBuildingOccupant_2(a, &z, d);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00695700 score 15
uint64_t cSC4BuildingDevelopmentSimulator::GetCostOfOccupantDemolition_2(void* occupant, uint32_t unused)
{
    uint32_t v[2];
    v[0] = 0;
    v[1] = 0;
    (void)unused;
    Prop_ab0af8* p = static_cast<OccP_ab0af8*>(occupant)->Fn03();
    Fn005fd4b0(p->Fn06(0x99afacd, v));
    return (static_cast<uint64_t>(v[1]) << 32) | v[0];
}
#endif

// FUNCTION: 0x00695cd0
void TreeE1_ab0af8::Fn00695cd0(TNode_ab0af8* n)
{
    while (n) {
        Fn00695cd0(n->mpRight);
        TNode_ab0af8* left = n->mpLeft;
        Fn0090cf63(n);
        n = left;
    }
}

// FUNCTION: 0x00695d10
void TreeE2_ab0af8::Fn00695d10(TNode_ab0af8* n)
{
    while (n) {
        Fn00695d10(n->mpRight);
        TNode_ab0af8* left = n->mpLeft;
        Fn0090cf63(n);
        n = left;
    }
}

// FUNCTION: 0x00695d50
void TreeE3_ab0af8::Fn00695d50(TNode_ab0af8* n)
{
    while (n) {
        Fn00695d50(n->mpRight);
        TNode_ab0af8* left = n->mpLeft;
        Fn0090cf63(n);
        n = left;
    }
}

// FUNCTION: 0x00695d90
void TreeE4_ab0af8::Fn00695d90(TNode_ab0af8* n)
{
    while (n) {
        Fn00695d90(n->mpRight);
        TNode_ab0af8* left = n->mpLeft;
        Fn0090cf63(n);
        n = left;
    }
}

// FUNCTION: 0x00695dd0
void TreeE5_ab0af8::Fn00695dd0(TNode_ab0af8* n)
{
    while (n) {
        Fn00695dd0(n->mpRight);
        TNode_ab0af8* left = n->mpLeft;
        Fn0090cf63(n);
        n = left;
    }
}

// FUNCTION: 0x00695e10
void TreeE6_ab0af8::Fn00695e10(TNode_ab0af8* n)
{
    while (n) {
        Fn00695e10(n->mpRight);
        TNode_ab0af8* left = n->mpLeft;
        Fn0090cf63(n);
        n = left;
    }
}

// FUNCTION: 0x0069b070
bool Fn0069b070(const KeyL_ab0af8* k)
{
    TreeL_ab0af8* t = gB485e0.Fn0069ab40(&gB48544);
    KeyL_ab0af8 key = *k;
    return t->Fn00695f70(&key) == t->mpHeader;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0069b6d0 score 4
void cSC4BuildingDevelopmentSimulator::DoDailySimulation(int32_t)
{
    Timer_ab0af8 timer;
    timer.Fn0088fedf(4);
    timer.Start();
    if (FLD_ab0af8(bool, 0xdc)) {
        ExecuteGrowthPlan();
    } else {
        Grow();
    }
    ExecuteDeclinePlan();
    timer.Fn00a6d837();
}
#endif

// FUNCTION: 0x00698f50
bool Fn00698f50(TGI_ab0af8* e)
{
    Hold_ab0af8* held;
    if (gpB43ca8_ab0af8->Fn03(e, 0xa52160f5, reinterpret_cast<void**>(&held), 0, 0)) {
        held->Fn07();
        uint32_t key = e->i;
        TGI_ab0af8* slot = gB485b8.Fn004a3470(&key);
        slot->t = e->t;
        slot->g = e->g;
        slot->i = e->i;
        held->Release();
    }
    return false;
}

// FUNCTION: 0x00698fc0
bool Fn00698fc0(TGI_ab0af8* e)
{
    Hold_ab0af8* held;
    if (gpB43ca8_ab0af8->Fn03(e, 0xa52160f5, reinterpret_cast<void**>(&held), 0, 0)) {
        held->Fn07();
        uint32_t key = e->i;
        TGI_ab0af8* slot = gB485cc.Fn004a3470(&key);
        slot->t = e->t;
        slot->g = e->g;
        slot->i = e->i;
        held->Release();
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0069d0a0 score 26
bool Fn0069d0a0(TGI_ab0af8* e)
{
    bool ok = false;
    Hold_ab0af8* held;
    if (gpB43ca8_ab0af8->Fn03(e, 0xa52160f5, reinterpret_cast<void**>(&held), 0, 0)) {
        void* props = held->Fn07();
        uint32_t instance = e->i;
        uint32_t key = instance;
        TGI_ab0af8* slot = gB48548.Fn004a3470(&key);
        slot->t = e->t;
        slot->g = e->g;
        slot->i = e->i;
        Fn0069b910(props, instance, true);
        held->Release();
        return true;
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0069d130 score 14
void Fn0069d130(TGI_ab0af8* e)
{
    Hold_ab0af8* held = 0;
    if (gpB43ca8_ab0af8->Fn03(e, 0xa52160f5, reinterpret_cast<void**>(&held), 0, 0)) {
        uint32_t kind = 0;
        if (Fn005fd480(held->Fn07(), 0x10, &kind)) {
            switch (kind) {
            case 2:
                Fn0069d0a0(e);
                break;
            case 0x11:
                Fn00698f50(e);
                break;
            case 0x15:
                Fn00698fc0(e);
                break;
            }
        }
    }
    if (held) {
        held->Release();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0069d1d0 score 6
bool Fn0069d1d0()
{
    if (!gB48540) {
        gB48540 = true;
        gpB43c94_ab0af8->Fn69(reinterpret_cast<void*>(&Fn0069b850), 0);
        if (gpB43ca8_ab0af8) {
            Hold2_ab0af8* res = 0;
            if (gpB43ca8_ab0af8->Fn18(0x6534284a, reinterpret_cast<void**>(&res))) {
                res->Fn07(reinterpret_cast<void*>(&Fn0069d130), 0);
                res->Release();
            }
        }
        Fn00695fd0();
        Fn0069c370();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006983c0 score 10
bool cSC4BuildingDevelopmentSimulator::LoadLotRetainingWallProperties(void* occupant, uint32_t id)
{
    bool ok = false;
    WallOcc_ab0af8* occ = static_cast<WallOcc_ab0af8*>(occupant);
    WallHolder_ab0af8* holder = occ->Fn03();
    holder->Fn06();
    WallProps_ab0af8* props = 0;
    holder->Query(0xac2b5f7, reinterpret_cast<void**>(&props));
    if (id == 0) {
        id = occ->Fn11();
    }
    HNode_ab0af8** b = gB485d0;
    uint32_t n = static_cast<uint32_t>(gB485d4 - b);
    HNode_ab0af8* node;
    for (node = b[id % n]; node && node->mKey4 != id; node = node->mpNext) {
    }
    if (node) {
        WallProps_ab0af8* res;
        if (FLD_ab0af8(RM_ab0af8*, 0x24)->Fn03(&node->mKey8, 0xa52160f5, reinterpret_cast<void**>(&res), 0, 0)) {
            props->Fn03(res);
            res->Release();
            ok = true;
        }
    }
    if (props) {
        props->Release();
    }
    return ok;
}
#endif
