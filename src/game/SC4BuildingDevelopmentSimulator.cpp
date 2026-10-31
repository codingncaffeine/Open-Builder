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

// ===== Agent 2 =====
struct OB_NOVTABLE City95_ab0af8 {
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
    virtual void Fn95(uint32_t, uint32_t, uint32_t*, uint32_t*) = 0;
};
struct OB_NOVTABLE OccMgr33_ab0af8 {
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
    virtual void Fn33(void**, uint32_t, uint32_t, uint32_t) = 0;
};

#define FLDS_ab0af8(self, T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(self) + (off)))

// An STLport hash table: bucket vector at +4/+8, element count at +0x10.
struct HTab_ab0af8 {
    uint32_t m0;
    HNode_ab0af8** mBegin;
    HNode_ab0af8** mEnd;
    uint32_t mC;
    uint32_t mSize;
};

// The result of a unique tree insert: the iterator and whether it was new.
struct InsRes_ab0af8 {
    TNode_ab0af8* it;
    bool inserted;
};

// An iterator whose decrement the original calls.
struct ItDec_ab0af8 {
    TNode_ab0af8* p;
    // STUB: 0x006809e0
    void Fn006809e0();
};

inline TNode_ab0af8* TreeNext_ab0af8(TNode_ab0af8* n)
{
    TNode_ab0af8* r = n->mpRight;
    if (r) {
        while (r->mpLeft) {
            r = r->mpLeft;
        }
        return r;
    }
    TNode_ab0af8* p = n->mpParent;
    while (n == p->mpRight) {
        n = p;
        p = p->mpParent;
    }
    if (n->mpRight != p) {
        n = p;
    }
    return n;
}

// A tree of a 16-byte key (find, insert).
struct KTree_ab0af8 {
    // STUB: 0x004c6920
    TNode_ab0af8* Fn004c6920(const uint32_t* key);
    // STUB: 0x00697470
    char* Fn00697470(const uint32_t* pair);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0069b550 score 99
void Fn0069b550Draft_ab0af8(HTab_ab0af8* self, HNode_ab0af8** it)
{
    HNode_ab0af8* node = *it;
    if (node) {
        uint32_t n = static_cast<uint32_t>(self->mEnd - self->mBegin);
        HNode_ab0af8** slot = &self->mBegin[node->mKey8 % n];
        HNode_ab0af8* cur = *slot;
        if (cur == node) {
            *slot = cur->mpNext;
            Fn0069ac70(reinterpret_cast<Rec_ab0af8*>(cur));
            self->mSize = self->mSize - 1;
            return;
        }
        HNode_ab0af8* nx = cur->mpNext;
        while (nx) {
            if (nx == node) {
                cur->mpNext = node->mpNext;
                Fn0069ac70(reinterpret_cast<Rec_ab0af8*>(node));
                self->mSize = self->mSize - 1;
                return;
            }
            cur = nx;
            nx = nx->mpNext;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00698970 score 99
char* Fn00698970Draft_ab0af8(KTree_ab0af8* self, const uint32_t* k)
{
    TNode_ab0af8* found = self->Fn004c6920(k);
    if (found) {
        return reinterpret_cast<char*>(found) + 0x14;
    }
    uint32_t pair[5];
    pair[0] = k[0];
    pair[1] = k[1];
    pair[2] = k[2];
    pair[3] = k[3];
    pair[4] = 0;
    return self->Fn00697470(pair) + 0x10;
}
#endif

// A map of a 32-bit key to a 16-bit value.
struct TreeW_ab0af8 {
    TNode_ab0af8* mpHeader;
    // STUB: 0x00696d00
    TNode_ab0af8** Fn00696d00(TNode_ab0af8** out, TNode_ab0af8* y, const uint32_t* pair);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00699030 score 99
uint16_t* Fn00699030Draft_ab0af8(TreeW_ab0af8* self, const uint32_t* key)
{
    TNode_ab0af8* header = self->mpHeader;
    TNode_ab0af8* x = header->mpParent;
    TNode_ab0af8* y = header;
    while (x) {
        if (static_cast<uint32_t>(x->mKey0) < *key) {
            x = x->mpRight;
        } else {
            y = x;
            x = x->mpLeft;
        }
    }
    if (y == header || *key < static_cast<uint32_t>(y->mKey0)) {
        uint32_t pair[2];
        TNode_ab0af8* res;
        pair[0] = *key;
        pair[1] = 0;
        self->Fn00696d00(&res, y, pair);
        y = res;
    }
    return reinterpret_cast<uint16_t*>(&y->mKey1);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0069b5d0 score 99
void Fn0069b5d0Draft_ab0af8(HTab_ab0af8* self)
{
    uint32_t i = 0;
    while (i < static_cast<uint32_t>(self->mEnd - self->mBegin)) {
        HNode_ab0af8* node = self->mBegin[i];
        while (node) {
            HNode_ab0af8* next = node->mpNext;
            uint32_t tag;
            Fn00459170(reinterpret_cast<void*>(node->mVal[0]), reinterpret_cast<void*>(node->mVal[1]), &tag);
            if (node->mVal[0]) {
                Fn0090cf63(reinterpret_cast<void*>(node->mVal[0]));
            }
            Fn0090cf63(node);
            node = next;
        }
        self->mBegin[i] = 0;
        i++;
    }
    self->mSize = 0;
}
#endif

// STUB: 0x00696540
void Fn00696540(uint32_t n);
// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);
struct Copy12_ab0af8 {
    // STUB: 0x004d1230
    void Fn004d1230(const void* src);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0069b650 score 99
char* Fn0069b650Draft_ab0af8(HTab_ab0af8* self, const uint32_t* v)
{
    Fn00696540(self->mSize + 1);
    uint32_t n = static_cast<uint32_t>(self->mEnd - self->mBegin);
    uint32_t idx = v[0] % n;
    HNode_ab0af8* first = self->mBegin[idx];
    char* node = static_cast<char*>(Fn0090cf54(0x50));
    uint32_t* val = reinterpret_cast<uint32_t*>(node + 8);
    *reinterpret_cast<uint32_t*>(node) = 0;
    if (val) {
        val[0] = v[0];
        reinterpret_cast<Copy12_ab0af8*>(val + 2)->Fn004d1230(v + 2);
    }
    *reinterpret_cast<HNode_ab0af8**>(node) = first;
    self->mBegin[idx] = reinterpret_cast<HNode_ab0af8*>(node);
    self->mSize = self->mSize + 1;
    return reinterpret_cast<char*>(val);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00695590 score 99
bool cSC4BuildingDevelopmentSimulator::LocationIsOKForNewBuilding(uint32_t a, uint32_t b, uint32_t c)
{
    if (!IsBuildingTypeValid(a)) {
        return false;
    }
    uint32_t py = 0;
    uint32_t px = 0;
    void* hold = 0;
    reinterpret_cast<City95_ab0af8*>(FLD_ab0af8(void*, 0x1c))->Fn95(b, c, &px, &py);
    reinterpret_cast<OccMgr33_ab0af8*>(FLD_ab0af8(void*, 0x20))->Fn33(&hold, px, py, 0x278128a0);
    bool found = hold != 0;
    if (hold) {
        (*reinterpret_cast<void (**)(void*)>(*reinterpret_cast<char**>(hold) + 8))(hold);
    }
    return !found;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00699f70 score 99
void Fn00699f70Draft_ab0af8(HTab_ab0af8* self, HNode_ab0af8** it)
{
    HNode_ab0af8* node = *it;
    if (node) {
        uint32_t n = static_cast<uint32_t>(self->mEnd - self->mBegin);
        HNode_ab0af8** slot = &self->mBegin[node->mKey4 % n];
        HNode_ab0af8* cur = *slot;
        if (cur == node) {
            *slot = cur->mpNext;
            cur->mKey8 = 0xa80810;
            if (cur->mC) {
                Fn0090cf63(reinterpret_cast<void*>(cur->mC));
            }
            Fn0090cf63(cur);
            self->mSize = self->mSize - 1;
            return;
        }
        HNode_ab0af8* nx = cur->mpNext;
        while (nx) {
            if (nx == node) {
                cur->mpNext = node->mpNext;
                Fn0090cf63(node);
                self->mSize = self->mSize - 1;
                return;
            }
            cur = nx;
            nx = nx->mpNext;
        }
    }
}
#endif

struct Vec_ab0af8 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
};
struct Flags_ab0af8 {
    uint32_t pad[7];
    uint32_t mMask;
};
// STUB: 0x005ff510
bool Fn005ff510(void* holder, uint32_t id, Vec_ab0af8* out);
// GLOBAL: 0x00ab0a40
extern uint32_t gAb0a40[31];

#ifdef OB_DRAFTS
// CLOSE: 0x00696b80 score 99
void Fn00696b80Draft_ab0af8(Flags_ab0af8* flags, void* holder)
{
    Vec_ab0af8 v;
    flags->mMask = 0;
    v.mpBegin = 0;
    v.mpEnd = 0;
    v.mpCap = 0;
    if (!Fn005ff510(holder, 0xaa1dd396, &v)) {
        if (v.mpBegin) {
            Fn0090cf63(v.mpBegin);
        }
        return;
    }
    uint32_t* p = v.mpBegin;
    while (p != v.mpEnd) {
        for (int32_t i = 0; i < 31; i++) {
            if (gAb0a40[i] == *p) {
                flags->mMask |= 1u << i;
            }
        }
        p++;
    }
    if (v.mpBegin) {
        Fn0090cf63(v.mpBegin);
    }
}
#endif

// STUB: 0x00695e10
void Fn00695e10Free(TNode_ab0af8* n);

#ifdef OB_DRAFTS
// CLOSE: 0x006990b0 score 99
void Fn006990b0Draft_ab0af8(void* self, TNode_ab0af8* n)
{
    while (n) {
        Fn006990b0Draft_ab0af8(self, n->mpRight);
        TNode_ab0af8* left = n->mpLeft;
        TNode_ab0af8** inner = reinterpret_cast<TNode_ab0af8**>(&n->mKey1);
        if (reinterpret_cast<uint32_t*>(n)[6]) {
            TNode_ab0af8* e = (*inner)->mpParent;
            while (e) {
                reinterpret_cast<TreeE6_ab0af8*>(inner)->Fn00695e10(e->mpRight);
                TNode_ab0af8* nx = e->mpLeft;
                Fn0090cf63(e);
                e = nx;
            }
            (*inner)->mpLeft = *inner;
            (*inner)->mpParent = 0;
            (*inner)->mpRight = *inner;
            reinterpret_cast<uint32_t*>(n)[6] = 0;
        }
        if (*inner) {
            Fn0090cf63(*inner);
        }
        Fn0090cf63(n);
        n = left;
    }
}
#endif

// A copy of a red-black tree: allocate the header, copy the nodes, find the extremes.
struct TreeCopy_ab0af8 {
    TNode_ab0af8* mpHeader;
    uint32_t mCount;
    // STUB: 0x00696f10
    TNode_ab0af8* Fn00696f10(TNode_ab0af8* src, TNode_ab0af8* parent);
    // STUB: 0x00697740
    TNode_ab0af8* Fn00697740(TNode_ab0af8* src, TNode_ab0af8* parent);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006989d0 score 99
TreeCopy_ab0af8* Fn006989d0Draft_ab0af8(TreeCopy_ab0af8* self, const TreeCopy_ab0af8* src)
{
    self->mpHeader = 0;
    self->mpHeader = static_cast<TNode_ab0af8*>(Fn0090cf54(0x18));
    self->mCount = 0;
    self->mpHeader->mColor = 0;
    if (!src->mpHeader->mpParent) {
        self->mpHeader->mpParent = 0;
        self->mpHeader->mpLeft = self->mpHeader;
        self->mpHeader->mpRight = self->mpHeader;
        self->mCount = src->mCount;
        return self;
    }
    TNode_ab0af8* header = self->mpHeader;
    header->mpParent = self->Fn00696f10(src->mpHeader->mpParent, header);
    TNode_ab0af8* l = self->mpHeader->mpParent;
    while (l->mpLeft) {
        l = l->mpLeft;
    }
    self->mpHeader->mpLeft = l;
    TNode_ab0af8* r = self->mpHeader->mpParent;
    while (r->mpRight) {
        r = r->mpRight;
    }
    self->mpHeader->mpRight = r;
    self->mCount = src->mCount;
    return self;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00698a80 score 99
TreeCopy_ab0af8* Fn00698a80Draft_ab0af8(TreeCopy_ab0af8* self, const TreeCopy_ab0af8* src)
{
    self->mpHeader = 0;
    self->mpHeader = static_cast<TNode_ab0af8*>(Fn0090cf54(0x18));
    self->mCount = 0;
    self->mpHeader->mColor = 0;
    if (!src->mpHeader->mpParent) {
        self->mpHeader->mpParent = 0;
        self->mpHeader->mpLeft = self->mpHeader;
        self->mpHeader->mpRight = self->mpHeader;
        self->mCount = src->mCount;
        return self;
    }
    TNode_ab0af8* header = self->mpHeader;
    header->mpParent = self->Fn00697740(src->mpHeader->mpParent, header);
    TNode_ab0af8* l = self->mpHeader->mpParent;
    while (l->mpLeft) {
        l = l->mpLeft;
    }
    self->mpHeader->mpLeft = l;
    TNode_ab0af8* r = self->mpHeader->mpParent;
    while (r->mpRight) {
        r = r->mpRight;
    }
    self->mpHeader->mpRight = r;
    self->mCount = src->mCount;
    return self;
}
#endif

// Unique inserts into the red-black trees: a lookup down the tree, then the tree's own insert.
struct TreeIU_ab0af8 {
    TNode_ab0af8* mpHeader;
    // STUB: 0x006963b0
    TNode_ab0af8** Fn006963b0(TNode_ab0af8** out, TNode_ab0af8* x, TNode_ab0af8* y, const uint32_t* k, int32_t w);
    // STUB: 0x006c03e0
    TNode_ab0af8** Fn006c03e0(TNode_ab0af8** out, TNode_ab0af8* x, TNode_ab0af8* y, const int32_t* k, int32_t w);
    // STUB: 0x0069a610
    TNode_ab0af8** Fn0069a610(TNode_ab0af8** out, TNode_ab0af8* x, TNode_ab0af8* y, const uint32_t* k, int32_t w);
    // STUB: 0x00696060
    TNode_ab0af8** Fn00696060(TNode_ab0af8** out, TNode_ab0af8* x, TNode_ab0af8* y, const KeyL_ab0af8* k, int32_t w);
    // STUB: 0x00696630
    TNode_ab0af8** Fn00696630(TNode_ab0af8** out, TNode_ab0af8* x, TNode_ab0af8* y, const KeyB_ab0af8* k, int32_t w);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00696480 score 99
InsRes_ab0af8 Fn00696480Draft_ab0af8(TreeIU_ab0af8* self, const uint32_t* k)
{
    InsRes_ab0af8 r;
    TNode_ab0af8* header = self->mpHeader;
    TNode_ab0af8* x = header->mpParent;
    TNode_ab0af8* y = header;
    bool lt = true;
    while (x) {
        y = x;
        lt = *k < static_cast<uint32_t>(x->mKey0);
        x = lt ? x->mpLeft : x->mpRight;
    }
    TNode_ab0af8* j = y;
    TNode_ab0af8* tmp;
    if (lt) {
        if (y == header->mpLeft) {
            r.it = *self->Fn006963b0(&tmp, x, y, k, 0);
            r.inserted = true;
            return r;
        }
        reinterpret_cast<ItDec_ab0af8*>(&j)->Fn006809e0();
    }
    if (static_cast<uint32_t>(j->mKey0) < *k) {
        r.it = *self->Fn006963b0(&tmp, x, y, k, 0);
        r.inserted = true;
        return r;
    }
    r.it = j;
    r.inserted = false;
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006967c0 score 99
InsRes_ab0af8 Fn006967c0Draft_ab0af8(TreeIU_ab0af8* self, const int32_t* k)
{
    InsRes_ab0af8 r;
    TNode_ab0af8* header = self->mpHeader;
    TNode_ab0af8* x = header->mpParent;
    TNode_ab0af8* y = header;
    bool lt = true;
    while (x) {
        y = x;
        lt = *k < x->mKey0;
        x = lt ? x->mpLeft : x->mpRight;
    }
    TNode_ab0af8* j = y;
    TNode_ab0af8* tmp;
    if (lt) {
        if (y == header->mpLeft) {
            r.it = *self->Fn006c03e0(&tmp, x, y, k, 0);
            r.inserted = true;
            return r;
        }
        reinterpret_cast<ItDec_ab0af8*>(&j)->Fn006809e0();
    }
    if (j->mKey0 < *k) {
        r.it = *self->Fn006c03e0(&tmp, x, y, k, 0);
        r.inserted = true;
        return r;
    }
    r.it = j;
    r.inserted = false;
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0069a6e0 score 99
InsRes_ab0af8 Fn0069a6e0Draft_ab0af8(TreeIU_ab0af8* self, const uint32_t* k)
{
    InsRes_ab0af8 r;
    TNode_ab0af8* header = self->mpHeader;
    TNode_ab0af8* x = header->mpParent;
    TNode_ab0af8* y = header;
    bool lt = true;
    while (x) {
        y = x;
        lt = *k < static_cast<uint32_t>(x->mKey0);
        x = lt ? x->mpLeft : x->mpRight;
    }
    TNode_ab0af8* j = y;
    TNode_ab0af8* tmp;
    if (lt) {
        if (y == header->mpLeft) {
            r.it = *self->Fn0069a610(&tmp, x, y, k, 0);
            r.inserted = true;
            return r;
        }
        reinterpret_cast<ItDec_ab0af8*>(&j)->Fn006809e0();
    }
    if (static_cast<uint32_t>(j->mKey0) < *k) {
        r.it = *self->Fn0069a610(&tmp, x, y, k, 0);
        r.inserted = true;
        return r;
    }
    r.it = j;
    r.inserted = false;
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00696300 score 99
InsRes_ab0af8 Fn00696300Draft_ab0af8(TreeIU_ab0af8* self, const KeyL_ab0af8* k)
{
    InsRes_ab0af8 r;
    TNode_ab0af8* header = self->mpHeader;
    TNode_ab0af8* x = header->mpParent;
    TNode_ab0af8* y = header;
    bool lt = true;
    while (x) {
        y = x;
        lt = k->a < x->mKey0 || (k->a == x->mKey0 && k->b < static_cast<int32_t>(x->mKey1));
        x = lt ? x->mpLeft : x->mpRight;
    }
    TNode_ab0af8* j = y;
    TNode_ab0af8* tmp;
    if (lt) {
        if (y == header->mpLeft) {
            r.it = *self->Fn00696060(&tmp, x, y, k, 0);
            r.inserted = true;
            return r;
        }
        reinterpret_cast<ItDec_ab0af8*>(&j)->Fn006809e0();
    }
    if (j->mKey0 < k->a || (j->mKey0 == k->a && static_cast<int32_t>(j->mKey1) < k->b)) {
        r.it = *self->Fn00696060(&tmp, x, y, k, 0);
        r.inserted = true;
        return r;
    }
    r.it = j;
    r.inserted = false;
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00696710 score 99
InsRes_ab0af8 Fn00696710Draft_ab0af8(TreeIU_ab0af8* self, const KeyB_ab0af8* k)
{
    InsRes_ab0af8 r;
    TNode_ab0af8* header = self->mpHeader;
    TNode_ab0af8* x = header->mpParent;
    TNode_ab0af8* y = header;
    bool lt = true;
    while (x) {
        y = x;
        lt = k->a < x->mKey0 || (k->a == x->mKey0 && k->b < static_cast<uint8_t>(x->mKey1));
        x = lt ? x->mpLeft : x->mpRight;
    }
    TNode_ab0af8* j = y;
    TNode_ab0af8* tmp;
    if (lt) {
        if (y == header->mpLeft) {
            r.it = *self->Fn00696630(&tmp, x, y, k, 0);
            r.inserted = true;
            return r;
        }
        reinterpret_cast<ItDec_ab0af8*>(&j)->Fn006809e0();
    }
    if (j->mKey0 < k->a || (j->mKey0 == k->a && static_cast<uint8_t>(j->mKey1) < k->b)) {
        r.it = *self->Fn00696630(&tmp, x, y, k, 0);
        r.inserted = true;
        return r;
    }
    r.it = j;
    r.inserted = false;
    return r;
}
#endif

// The members of the class the state machine at 0x00699ea0 calls.
struct SimView_ab0af8 {
    // STUB: 0x00699440
    void Fn00699440();
    // STUB: 0x00699890
    void Fn00699890();
};
struct OB_NOVTABLE Step_ab0af8 {
    virtual void Pad00() = 0; virtual void Pad01() = 0; virtual void Pad02() = 0; virtual void Pad03() = 0;
    virtual void Pad04() = 0; virtual void Pad05() = 0; virtual void Pad06() = 0; virtual void Pad07() = 0;
    virtual void Pad08() = 0; virtual void Pad09() = 0; virtual void Pad10() = 0; virtual void Pad11() = 0;
    virtual void Pad12() = 0; virtual void Pad13() = 0; virtual void Pad14() = 0; virtual void Pad15() = 0;
    virtual void Pad16() = 0; virtual void Pad17() = 0; virtual void Pad18() = 0; virtual void Pad19() = 0;
    virtual void Pad20() = 0; virtual void Pad21() = 0; virtual void Pad22() = 0; virtual void Pad23() = 0;
    virtual void Pad24() = 0; virtual void Pad25() = 0; virtual void Pad26() = 0; virtual void Pad27() = 0;
    virtual bool Fn28() = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00699ea0 score 99
void Fn00699ea0Draft_ab0af8(cSC4BuildingDevelopmentSimulator* self, uint32_t unused)
{
    (void)unused;
    TNode_ab0af8* header = FLDS_ab0af8(self, TNode_ab0af8*, 0x5c);
    switch (FLDS_ab0af8(self, int32_t, 0x74)) {
    case 1:
        FLDS_ab0af8(self, TNode_ab0af8*, 0x78) = header->mpLeft;
        FLDS_ab0af8(self, int32_t, 0x74) = 2;
        /* fall through */
    case 2:
        while (FLDS_ab0af8(self, TNode_ab0af8*, 0x78) != header) {
            TNode_ab0af8* it = FLDS_ab0af8(self, TNode_ab0af8*, 0x78);
            if (!reinterpret_cast<Step_ab0af8*>(it->mKey1)->Fn28()) {
                return;
            }
            FLDS_ab0af8(self, TNode_ab0af8*, 0x78) = TreeNext_ab0af8(it);
        }
        FLDS_ab0af8(self, int32_t, 0x74) = 3;
        /* fall through */
    case 3:
        if (FLDS_ab0af8(self, bool, 0xdc)) {
            reinterpret_cast<SimView_ab0af8*>(self)->Fn00699440();
        }
        FLDS_ab0af8(self, int32_t, 0x74) = 4;
        break;
    case 4:
        reinterpret_cast<SimView_ab0af8*>(self)->Fn00699890();
        FLDS_ab0af8(self, int32_t, 0x74) = 0;
        break;
    }
}
#endif

// The next element of a chained hash table iteration (node key at +4).
inline HNode_ab0af8* HashNext_ab0af8(HTab_ab0af8* t, HNode_ab0af8* node)
{
    HNode_ab0af8* next = node->mpNext;
    if (next) {
        return next;
    }
    uint32_t n = static_cast<uint32_t>(t->mEnd - t->mBegin);
    uint32_t i = node->mKey4 % n + 1;
    while (i < static_cast<uint32_t>(t->mEnd - t->mBegin)) {
        if (t->mBegin[i]) {
            return t->mBegin[i];
        }
        i++;
    }
    return 0;
}

// A hash table whose begin() hands the first node back through a pointer.
struct HBeg_ab0af8 {
    HTab_ab0af8 t;
    // STUB: 0x004b0390
    void Fn004b0390(HNode_ab0af8** out);
};
// GLOBAL: 0x00b48548
extern HBeg_ab0af8 gB48548_ab0af8;
// GLOBAL: 0x00b48598
extern HBeg_ab0af8 gB48598_ab0af8;

// A vector of pointers (push_back with its overflow helper).
struct PVec_ab0af8 {
    void** mpBegin;
    void** mpEnd;
    void** mpCap;
    // STUB: 0x0051ca60
    void Fn0051ca60(void** where, void* const* val, int32_t a, uint32_t b, bool c);
};

struct HResize_ab0af8 {
    HTab_ab0af8 t;
    // STUB: 0x00696940
    void Fn00696940(uint32_t n);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00697470 score 99
char* Fn00697470Draft_ab0af8(HTab_ab0af8* self, const uint32_t* v)
{
    reinterpret_cast<HResize_ab0af8*>(self)->Fn00696940(self->mSize + 1);
    uint32_t h = (((((v[0] << 6) | (v[1] & 0x3f)) << 6) | (v[2] & 0x3f)) << 4) | (static_cast<uint8_t>(v[3]) & 0xf);
    uint32_t idx = h % static_cast<uint32_t>(self->mEnd - self->mBegin);
    HNode_ab0af8* first = self->mBegin[idx];
    uint32_t* node = static_cast<uint32_t*>(Fn0090cf54(0x18));
    node[0] = 0;
    node[1] = v[0];
    node[2] = v[1];
    node[3] = v[2];
    node[4] = v[3];
    node[5] = v[4];
    *reinterpret_cast<HNode_ab0af8**>(node) = first;
    self->mBegin[idx] = reinterpret_cast<HNode_ab0af8*>(node);
    self->mSize = self->mSize + 1;
    return reinterpret_cast<char*>(node + 1);
}
#endif

// A tree node copied recursively (an 8-byte value at +0x10).
inline TNode_ab0af8* NewNodeCopy_ab0af8(const TNode_ab0af8* src, TNode_ab0af8* parent)
{
    TNode_ab0af8* n = static_cast<TNode_ab0af8*>(Fn0090cf54(0x18));
    if (n) {
        n->mKey0 = src->mKey0;
        n->mKey1 = src->mKey1;
    }
    n->mColor = src->mColor;
    n->mpLeft = 0;
    n->mpRight = 0;
    n->mpParent = parent;
    return n;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00696f10 score 99
TNode_ab0af8* Fn00696f10Draft_ab0af8(TreeCopy_ab0af8* self, const TNode_ab0af8* src, TNode_ab0af8* parent)
{
    TNode_ab0af8* top = NewNodeCopy_ab0af8(src, parent);
    if (src->mpRight) {
        top->mpRight = self->Fn00696f10(src->mpRight, top);
    }
    TNode_ab0af8* p = top;
    src = src->mpLeft;
    while (src) {
        TNode_ab0af8* y = NewNodeCopy_ab0af8(src, p);
        p->mpLeft = y;
        if (src->mpRight) {
            y->mpRight = self->Fn00696f10(src->mpRight, y);
        }
        p = y;
        src = src->mpLeft;
    }
    return top;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00697740 score 99
TNode_ab0af8* Fn00697740Draft_ab0af8(TreeCopy_ab0af8* self, const TNode_ab0af8* src, TNode_ab0af8* parent)
{
    TNode_ab0af8* top = NewNodeCopy_ab0af8(src, parent);
    if (src->mpRight) {
        top->mpRight = self->Fn00697740(src->mpRight, top);
    }
    TNode_ab0af8* p = top;
    src = src->mpLeft;
    while (src) {
        TNode_ab0af8* y = NewNodeCopy_ab0af8(src, p);
        p->mpLeft = y;
        if (src->mpRight) {
            y->mpRight = self->Fn00697740(src->mpRight, y);
        }
        p = y;
        src = src->mpLeft;
    }
    return top;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00695e50 score 99
Elem12_ab0af8* Fn00695e50Draft_ab0af8(Elem12_ab0af8* first, Elem12_ab0af8* last, bool (*pred)(Elem12_ab0af8*))
{
    while (first != last) {
        if (pred(first)) {
            return first;
        }
        first++;
    }
    return last;
}
#endif

// Rebalancing helpers of the tree erase (a node unlink, then its release).
struct TreeEr_ab0af8 {
    TNode_ab0af8* mpHeader;
    uint32_t mCount;
    // STUB: 0x00695cd0
    void Fn00695cd0(TNode_ab0af8* n);
};
// STUB: 0x0040daf0
TNode_ab0af8* Fn0040daf0(TNode_ab0af8* node, TNode_ab0af8** root, TNode_ab0af8** leftmost, TNode_ab0af8** rightmost);

#ifdef OB_DRAFTS
// CLOSE: 0x00696240 score 99
void Fn00696240Draft_ab0af8(TreeEr_ab0af8* self, TNode_ab0af8* first, TNode_ab0af8* last)
{
    if (first == self->mpHeader->mpLeft && last == self->mpHeader) {
        if (self->mCount != 0) {
            self->Fn00695cd0(self->mpHeader->mpParent);
            self->mpHeader->mpLeft = self->mpHeader;
            self->mpHeader->mpParent = 0;
            self->mpHeader->mpRight = self->mpHeader;
            self->mCount = 0;
        }
        return;
    }
    while (first != last) {
        TNode_ab0af8* node = first;
        first = TreeNext_ab0af8(first);
        TNode_ab0af8* gone = Fn0040daf0(node, &self->mpHeader->mpParent, &self->mpHeader->mpLeft, &self->mpHeader->mpRight);
        if (gone) {
            Fn0090cf63(gone);
        }
        self->mCount = self->mCount - 1;
    }
}
#endif

inline void PushBack_ab0af8(PVec_ab0af8* v, void* val)
{
    if (v->mpEnd != v->mpCap) {
        if (v->mpEnd) {
            *v->mpEnd = val;
        }
        v->mpEnd = v->mpEnd + 1;
    } else {
        v->Fn0051ca60(v->mpEnd, &val, 1, 1, true);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00697c50 score 99
void cSC4BuildingDevelopmentSimulator::GetAllBuildingTypes(uint32_t out)
{
    PVec_ab0af8* v = OB_PTR(PVec_ab0af8, out);
    v->mpEnd = v->mpBegin;
    HNode_ab0af8* it = 0;
    gB48548_ab0af8.Fn004b0390(&it);
    while (it) {
        PushBack_ab0af8(v, reinterpret_cast<void*>(it->mKey4));
        it = HashNext_ab0af8(&gB48548_ab0af8.t, it);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00697d10 score 99
void cSC4BuildingDevelopmentSimulator::GetAllBuildingFamilyTypes(uint32_t out)
{
    PVec_ab0af8* v = OB_PTR(PVec_ab0af8, out);
    v->mpEnd = v->mpBegin;
    HNode_ab0af8* it = 0;
    gB48598_ab0af8.Fn004b0390(&it);
    while (it) {
        PushBack_ab0af8(v, reinterpret_cast<void*>(it->mKey4));
        it = HashNext_ab0af8(&gB48598_ab0af8.t, it);
    }
}
#endif

// A tree insert: place the new node under y (left when x or y says so), link, rebalance.
// STUB: 0x0040d5e0
void Fn0040d5e0(TNode_ab0af8* node, TNode_ab0af8** root);

struct TreeIns_ab0af8 {
    TNode_ab0af8* mpHeader;
    uint32_t mCount;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00696880 score 99
TNode_ab0af8** Fn00696880Draft_ab0af8(TreeIns_ab0af8* self, TNode_ab0af8** out, TNode_ab0af8* x, TNode_ab0af8* y, const uint32_t* v, int32_t w)
{
    TNode_ab0af8* node;
    if (y == self->mpHeader || w != 0 || x != 0 || *v < static_cast<uint32_t>(y->mKey0)) {
        node = static_cast<TNode_ab0af8*>(Fn0090cf54(0x18));
        if (node) {
            node->mKey0 = v[0];
            node->mKey1 = v[1];
        }
        y->mpLeft = node;
        if (y == self->mpHeader) {
            self->mpHeader->mpParent = node;
            self->mpHeader->mpRight = node;
        } else if (y == self->mpHeader->mpLeft) {
            self->mpHeader->mpLeft = node;
        }
    } else {
        node = static_cast<TNode_ab0af8*>(Fn0090cf54(0x18));
        if (node) {
            node->mKey0 = v[0];
            node->mKey1 = v[1];
        }
        y->mpRight = node;
        if (y == self->mpHeader->mpRight) {
            self->mpHeader->mpRight = node;
        }
    }
    node->mpParent = y;
    node->mpLeft = 0;
    node->mpRight = 0;
    Fn0040d5e0(node, &self->mpHeader->mpParent);
    self->mCount = self->mCount + 1;
    *out = node;
    return out;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006963b0 score 99
TNode_ab0af8** Fn006963b0Draft_ab0af8(TreeIns_ab0af8* self, TNode_ab0af8** out, TNode_ab0af8* x, TNode_ab0af8* y, const uint32_t* v, int32_t w)
{
    TNode_ab0af8* node;
    if (y == self->mpHeader || w != 0 || x != 0 || *v < static_cast<uint32_t>(y->mKey0)) {
        node = static_cast<TNode_ab0af8*>(Fn0090cf54(0x18));
        if (node) {
            node->mKey0 = v[0];
            *reinterpret_cast<uint16_t*>(&node->mKey1) = *reinterpret_cast<const uint16_t*>(v + 1);
        }
        y->mpLeft = node;
        if (y == self->mpHeader) {
            self->mpHeader->mpParent = node;
            self->mpHeader->mpRight = node;
        } else if (y == self->mpHeader->mpLeft) {
            self->mpHeader->mpLeft = node;
        }
    } else {
        node = static_cast<TNode_ab0af8*>(Fn0090cf54(0x18));
        if (node) {
            node->mKey0 = v[0];
            *reinterpret_cast<uint16_t*>(&node->mKey1) = *reinterpret_cast<const uint16_t*>(v + 1);
        }
        y->mpRight = node;
        if (y == self->mpHeader->mpRight) {
            self->mpHeader->mpRight = node;
        }
    }
    node->mpParent = y;
    node->mpLeft = 0;
    node->mpRight = 0;
    Fn0040d5e0(node, &self->mpHeader->mpParent);
    self->mCount = self->mCount + 1;
    *out = node;
    return out;
}
#endif

struct OB_NOVTABLE Filter_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual bool Fn03(uint32_t) = 0;
};
struct HSet_ab0af8 {
    HTab_ab0af8 t;
    // STUB: 0x004f0940
    void Fn004f0940(uint32_t n);
    // STUB: 0x00624dd0
    void Fn00624dd0(char* out, const uint32_t* key);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00699c50 score 99
uint32_t cSC4BuildingDevelopmentSimulator::GetBuildingTypesByFilter(uint32_t a, uint32_t b)
{
    uint32_t count = 0;
    HNode_ab0af8* it = 0;
    gB48548_ab0af8.Fn004b0390(&it);
    if (it) {
        Filter_ab0af8* filter = OB_PTR(Filter_ab0af8, b);
        HSet_ab0af8* out = OB_PTR(HSet_ab0af8, a);
        while (it) {
            uint32_t key = it->mKey4;
            if (!filter || filter->Fn03(key)) {
                char tmp[8];
                out->Fn004f0940(out->t.mSize + 1);
                out->Fn00624dd0(tmp, &key);
                count++;
            }
            it = HashNext_ab0af8(&gB48548_ab0af8.t, it);
        }
    }
    return count;
}
#endif

// GLOBAL: 0x00b485b8
extern HBeg_ab0af8 gB485b8_ab0af8;
// GLOBAL: 0x00b485cc
extern HBeg_ab0af8 gB485cc_ab0af8;
// GLOBAL: 0x00b485c8
extern uint32_t gB485c8;
// GLOBAL: 0x00b485dc
extern uint32_t gB485dc;

#ifdef OB_DRAFTS
// CLOSE: 0x00698050 score 99
uint32_t cSC4BuildingDevelopmentSimulator::GetAllFoundationTypes(uint32_t out)
{
    PVec_ab0af8* v = OB_PTR(PVec_ab0af8, out);
    v->mpEnd = v->mpBegin;
    HNode_ab0af8* it = 0;
    gB485b8_ab0af8.Fn004b0390(&it);
    while (it) {
        PushBack_ab0af8(v, reinterpret_cast<void*>(it->mKey4));
        it = HashNext_ab0af8(&gB485b8_ab0af8.t, it);
    }
    return gB485c8;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00698180 score 99
uint32_t cSC4BuildingDevelopmentSimulator::GetAllLotRetainingWallTypes(uint32_t out)
{
    PVec_ab0af8* v = OB_PTR(PVec_ab0af8, out);
    v->mpEnd = v->mpBegin;
    HNode_ab0af8* it = 0;
    gB485cc_ab0af8.Fn004b0390(&it);
    while (it) {
        PushBack_ab0af8(v, reinterpret_cast<void*>(it->mKey4));
        it = HashNext_ab0af8(&gB485cc_ab0af8.t, it);
    }
    return gB485dc;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00697b80 score 99
uint32_t cSC4BuildingDevelopmentSimulator::GetAllBuildingTypes_2(uint32_t pn, uint32_t arr)
{
    uint32_t* n = OB_PTR(uint32_t, pn);
    uint32_t total = gB48558;
    uint32_t* dest = OB_PTR(uint32_t, arr);
    if (*n > total) {
        *n = total;
    }
    if (dest && *n != 0) {
        HNode_ab0af8* it = 0;
        gB48548_ab0af8.Fn004b0390(&it);
        for (uint32_t i = 0; i < *n; i++) {
            if (it) {
                dest[i] = it->mKey4;
                it = HashNext_ab0af8(&gB48548_ab0af8.t, it);
            }
        }
        return total;
    }
    return total;
}
#endif

// The tree inserts: new node under y, to the left or right, then the rebalance and the count.
#define OB_RB_INSERT_BODY(LEFTCOND, COPYV)                                        \
    TNode_ab0af8* node;                                                           \
    if (y == self->mpHeader || w != 0 || x != 0 || (LEFTCOND)) {                  \
        node = static_cast<TNode_ab0af8*>(Fn0090cf54(0x18));                      \
        if (node) {                                                               \
            COPYV                                                                 \
        }                                                                         \
        y->mpLeft = node;                                                         \
        if (y == self->mpHeader) {                                                \
            self->mpHeader->mpParent = node;                                      \
            self->mpHeader->mpRight = node;                                       \
        } else if (y == self->mpHeader->mpLeft) {                                 \
            self->mpHeader->mpLeft = node;                                        \
        }                                                                         \
    } else {                                                                      \
        node = static_cast<TNode_ab0af8*>(Fn0090cf54(0x18));                      \
        if (node) {                                                               \
            COPYV                                                                 \
        }                                                                         \
        y->mpRight = node;                                                        \
        if (y == self->mpHeader->mpRight) {                                       \
            self->mpHeader->mpRight = node;                                       \
        }                                                                         \
    }                                                                             \
    node->mpParent = y;                                                           \
    node->mpLeft = 0;                                                             \
    node->mpRight = 0;                                                            \
    Fn0040d5e0(node, &self->mpHeader->mpParent);                                  \
    self->mCount = self->mCount + 1;                                              \
    *out = node;                                                                  \
    return out;

#ifdef OB_DRAFTS
// CLOSE: 0x00696060 score 99
TNode_ab0af8** Fn00696060Draft_ab0af8(TreeIns_ab0af8* self, TNode_ab0af8** out, TNode_ab0af8* x, TNode_ab0af8* y, const KeyL_ab0af8* v, int32_t w)
{
    OB_RB_INSERT_BODY(v->a < y->mKey0 || (v->a == y->mKey0 && v->b < static_cast<int32_t>(y->mKey1)),
                      node->mKey0 = v->a; node->mKey1 = v->b;)
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00696630 score 99
TNode_ab0af8** Fn00696630Draft_ab0af8(TreeIns_ab0af8* self, TNode_ab0af8** out, TNode_ab0af8* x, TNode_ab0af8* y, const KeyB_ab0af8* v, int32_t w)
{
    OB_RB_INSERT_BODY(v->a < y->mKey0 || (v->a == y->mKey0 && v->b < static_cast<uint8_t>(y->mKey1)),
                      node->mKey0 = v->a; *reinterpret_cast<uint8_t*>(&node->mKey1) = v->b;)
}
#endif

// The tree whose values are themselves trees (node size 0x20).
struct TreeCopy2_ab0af8 {
    // STUB: 0x00698a80
    void Fn00698a80(const void* src);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0069a610 score 99
TNode_ab0af8** Fn0069a610Draft_ab0af8(TreeIns_ab0af8* self, TNode_ab0af8** out, TNode_ab0af8* x, TNode_ab0af8* y, const uint32_t* v, int32_t w)
{
    TNode_ab0af8* node;
    if (y == self->mpHeader || w != 0 || x != 0 || *v < static_cast<uint32_t>(y->mKey0)) {
        node = static_cast<TNode_ab0af8*>(Fn0090cf54(0x20));
        if (node) {
            node->mKey0 = v[0];
            reinterpret_cast<TreeCopy2_ab0af8*>(&node->mKey1)->Fn00698a80(v + 1);
        }
        y->mpLeft = node;
        if (y == self->mpHeader) {
            self->mpHeader->mpParent = node;
            self->mpHeader->mpRight = node;
        } else if (y == self->mpHeader->mpLeft) {
            self->mpHeader->mpLeft = node;
        }
    } else {
        node = static_cast<TNode_ab0af8*>(Fn0090cf54(0x20));
        if (node) {
            node->mKey0 = v[0];
            reinterpret_cast<TreeCopy2_ab0af8*>(&node->mKey1)->Fn00698a80(v + 1);
        }
        y->mpRight = node;
        if (y == self->mpHeader->mpRight) {
            self->mpHeader->mpRight = node;
        }
    }
    node->mpParent = y;
    node->mpLeft = 0;
    node->mpRight = 0;
    Fn0040d5e0(node, &self->mpHeader->mpParent);
    self->mCount = self->mCount + 1;
    *out = node;
    return out;
}
#endif

// The simulator's per-type objects and its maps (+0x5c: type -> object, +0xb0: type -> value).
struct OB_NOVTABLE Hdl_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Fn01() = 0;
    virtual void Pad02() = 0;
    virtual void Fn03(void* holder) = 0;
};
struct ObjMap_ab0af8 {
    TNode_ab0af8* mpHeader;
    // STUB: 0x00497520
    TNode_ab0af8** Fn00497520(TNode_ab0af8** out, const uint32_t* key);
    // STUB: 0x00497a00
    Hdl_ab0af8** Fn00497a00(const uint32_t* key);
};
struct ValMap_ab0af8 {
    // STUB: 0x00429760
    uint32_t* Fn00429760(const uint32_t* key);
};
struct OB_NOVTABLE SimGlobal_ab0af8 {
    virtual void Pad00() = 0; virtual void Pad01() = 0; virtual void Pad02() = 0; virtual void Pad03() = 0;
    virtual void Pad04() = 0; virtual void Pad05() = 0; virtual void Pad06() = 0;
    virtual struct SimSub_ab0af8* Fn07() = 0;
};
struct OB_NOVTABLE SimSub_ab0af8 {
    virtual void Pad00() = 0; virtual void Pad01() = 0; virtual void Pad02() = 0; virtual void Pad03() = 0;
    virtual void Pad04() = 0; virtual void Pad05() = 0; virtual void Pad06() = 0; virtual void Pad07() = 0;
    virtual void Pad08() = 0; virtual void Pad09() = 0; virtual void Pad10() = 0; virtual void Pad11() = 0;
    virtual void Pad12() = 0; virtual void Pad13() = 0; virtual void Pad14() = 0; virtual void Pad15() = 0;
    virtual void Pad16() = 0; virtual void Pad17() = 0; virtual void Pad18() = 0; virtual void Pad19() = 0;
    virtual void Pad20() = 0; virtual void Pad21() = 0; virtual void Pad22() = 0; virtual void Pad23() = 0;
    virtual void Pad24() = 0; virtual void Pad25() = 0;
    virtual uint32_t Fn26() = 0;
};
// GLOBAL: 0x00b43d5c
extern SimGlobal_ab0af8** gpB43d5c_ab0af8;
// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t size);
struct Obj13c_ab0af8 {
    // STUB: 0x006b7310
    Hdl_ab0af8* Fn006b7310();
};

#ifdef OB_DRAFTS
// CLOSE: 0x006991a0 score 99
void Fn006991a0Draft_ab0af8(cSC4BuildingDevelopmentSimulator* self, void* holder)
{
    uint32_t id = 0;
    Fn005fd480(holder, 0x21, &id);
    if (id != 0) {
        TNode_ab0af8* it;
        ObjMap_ab0af8* map = &FLDS_ab0af8(self, ObjMap_ab0af8, 0x5c);
        map->Fn00497520(&it, &id);
        if (it != map->mpHeader) {
            reinterpret_cast<Hdl_ab0af8*>(it->mKey1)->Fn03(holder);
        } else {
            Hdl_ab0af8* obj = 0;
            void* mem = Fn005e55e0(0x13c);
            if (mem) {
                obj = static_cast<Obj13c_ab0af8*>(mem)->Fn006b7310();
            }
            obj->Fn01();
            obj->Fn03(holder);
            *map->Fn00497a00(&id) = obj;
            uint32_t key = id;
            SimSub_ab0af8* sub = (*gpB43d5c_ab0af8)->Fn07();
            *FLDS_ab0af8(self, ValMap_ab0af8, 0xb0).Fn00429760(&key) = sub->Fn26();
        }
    }
}
#endif

inline HNode_ab0af8* HFind4_ab0af8(HNode_ab0af8** b, HNode_ab0af8** e, uint32_t key)
{
    uint32_t n = static_cast<uint32_t>(e - b);
    HNode_ab0af8* node;
    for (node = b[key % n]; node && node->mKey4 != key; node = node->mpNext) {
    }
    return node;
}

// A vector of 32-bit values that a family's member list is copied into.
struct UVec_ab0af8 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x00462c10
    void Fn00462c10(const void* range);
    // STUB: 0x0051ca60
    void Fn0051ca60(uint32_t* where, const uint32_t* val, int32_t a, uint32_t b, bool c);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00697ef0 score 99
uint32_t cSC4BuildingDevelopmentSimulator::GetBuildingTypesByFamily(uint32_t out, uint32_t family)
{
    UVec_ab0af8* v = OB_PTR(UVec_ab0af8, out);
    HNode_ab0af8* node = HFind4_ab0af8(gB4859c, gB485a0, family);
    if (node) {
        uint32_t n = (node->mC - node->mKey8) >> 2;
        v->Fn00462c10(&node->mKey8);
        return n;
    }
    node = HFind4_ab0af8(gB4854c, gB48550, family);
    if (node) {
        v->mpEnd = v->mpBegin;
        if (v->mpEnd != v->mpCap) {
            if (v->mpEnd) {
                *v->mpEnd = family;
            }
            v->mpEnd = v->mpEnd + 1;
        } else {
            v->Fn0051ca60(v->mpEnd, &family, 1, 1, true);
        }
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00699d20 score 99
uint32_t cSC4BuildingDevelopmentSimulator::GetBuildingTypesByFamily_2(uint32_t set, uint32_t family)
{
    HSet_ab0af8* out = OB_PTR(HSet_ab0af8, set);
    uint32_t count = 0;
    HNode_ab0af8* node = HFind4_ab0af8(gB4859c, gB485a0, family);
    if (node) {
        count = (node->mC - node->mKey8) >> 2;
        for (int32_t i = 0; i < static_cast<int32_t>(count); i++) {
            out->Fn004f0940(out->t.mSize + 1);
            out->Fn00624dd0(0, reinterpret_cast<uint32_t*>(node->mKey8) + i);
        }
        return count;
    }
    node = HFind4_ab0af8(gB4854c, gB48550, family);
    if (node) {
        out->Fn004f0940(out->t.mSize + 1);
        out->Fn00624dd0(0, &family);
    }
    return 0;
}
#endif
struct FoundHolder_ab0af8;
struct OB_NOVTABLE FoundOcc_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual struct FoundHolder_ab0af8* Fn03() = 0;
    virtual uint32_t Fn04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Fn07(uint32_t) = 0;
    virtual void Fn08(void*, uint32_t) = 0;
};
struct OB_NOVTABLE FoundHolder_ab0af8 {
    virtual bool Query(uint32_t, void**) = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void* Fn06() = 0;
};
struct OB_NOVTABLE FoundProps_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Release() = 0;
    virtual void Fn03(void*) = 0;
};
struct OB_NOVTABLE DemandObj_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual float Fn08() = 0;
};
struct OB_NOVTABLE DemandSim_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual DemandObj_ab0af8* Fn06(uint32_t, uint32_t) = 0;
};
struct OB_NOVTABLE StepObj_ab0af8 {
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
    virtual void Fn27() = 0;
};
struct ObjA_ab0af8;
struct OB_NOVTABLE PropsA_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual struct ObjA_ab0af8* Fn09(uint32_t) = 0;
};
struct OB_NOVTABLE ObjB_ab0af8 {
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
    virtual void Pad97() = 0;
    virtual void Pad98() = 0;
    virtual void Pad99() = 0;
    virtual void Pad100() = 0;
    virtual void Pad101() = 0;
    virtual void Pad102() = 0;
    virtual uint32_t* Fn103() = 0;
};
struct OB_NOVTABLE ObjA_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual ObjB_ab0af8* Fn05() = 0;
};
struct OB_NOVTABLE ObjC_ab0af8 {
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
    virtual void Pad97() = 0;
    virtual void Pad98() = 0;
    virtual void Pad99() = 0;
    virtual void Pad100() = 0;
    virtual void Pad101() = 0;
    virtual void Pad102() = 0;
    virtual void Pad103() = 0;
    virtual void Pad104() = 0;
    virtual void Pad105() = 0;
    virtual void Pad106() = 0;
    virtual void Pad107() = 0;
    virtual void Pad108() = 0;
    virtual void Pad109() = 0;
    virtual void Pad110() = 0;
    virtual uint32_t Fn111() = 0;
};
struct OB_NOVTABLE ObjAC_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual ObjC_ab0af8* Fn05() = 0;
};
struct OB_NOVTABLE PropsC_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual ObjAC_ab0af8* Fn09(uint32_t) = 0;
};
struct OB_NOVTABLE Res18_ab0af8 {
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
    virtual void Fn18(float) = 0;
};

// STUB: 0x005fd4f0
bool Fn005fd4f0(void* holder, uint32_t id, void* out);
// STUB: 0x005ffcc0
bool Fn005ffcc0(void* holder, uint32_t id, void* out);
// GLOBAL: 0x00b43d74
extern DemandSim_ab0af8** gpB43d74_ab0af8;

#ifdef OB_DRAFTS
// CLOSE: 0x006982b0 score 99
bool cSC4BuildingDevelopmentSimulator::LoadFoundationProperties(uint32_t occupant, uint32_t id)
{
    bool ok = false;
    FoundOcc_ab0af8* occ = OB_PTR(FoundOcc_ab0af8, occupant);
    FoundHolder_ab0af8* holder = occ->Fn03();
    holder->Fn06();
    FoundProps_ab0af8* props = 0;
    holder->Query(0xac2b5f7, reinterpret_cast<void**>(&props));
    if (id == 0) {
        id = occ->Fn04();
    }
    HNode_ab0af8* node = HFind4_ab0af8(gB485bc, gB485c0, id);
    if (node) {
        FoundProps_ab0af8* res;
        if (FLD_ab0af8(RM_ab0af8*, 0x24)->Fn03(&node->mKey8, 0xa52160f5, reinterpret_cast<void**>(&res), 0, 0)) {
            props->Fn03(res);
            uint32_t out = 0;
            if (Fn005fd4f0(res, 0x88fcc3e3, &out)) {
                occ->Fn07(out);
                res->Release();
                ok = true;
            } else {
                res->Release();
            }
        }
    }
    if (props) {
        props->Release();
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00698490 score 99
bool Fn00698490Draft_ab0af8(cSC4BuildingDevelopmentSimulator* self, uint32_t occupant, uint32_t unused)
{
    (void)unused;
    FoundOcc_ab0af8* occ = OB_PTR(FoundOcc_ab0af8, occupant);
    FoundHolder_ab0af8* holder = occ->Fn03();
    holder->Fn06();
    FoundProps_ab0af8* props = 0;
    holder->Query(0xac2b5f7, reinterpret_cast<void**>(&props));
    uint32_t id = occ->Fn04();
    HNode_ab0af8* node = HFind4_ab0af8(gB4854c, gB48550, id);
    if (node) {
        Hold_ab0af8* res;
        if (FLDS_ab0af8(self, RM_ab0af8*, 0x24)->Fn03(&node->mKey8, 0xa52160f5, reinterpret_cast<void**>(&res), 0, 0)) {
            props->Fn03(res);
            PropsC_ab0af8* p = reinterpret_cast<PropsC_ab0af8*>(holder->Fn06());
            ObjAC_ab0af8* obj = p->Fn09(0x27812810);
            if (obj) {
                uint32_t vec[3];
                vec[0] = 0;
                vec[1] = 0;
                vec[2] = 0;
                occ->Fn08(vec, obj->Fn05()->Fn111());
            }
            res->Release();
        }
    }
    if (props) {
        props->Release();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00696130 score 99
void Fn00696130Draft_ab0af8(cSC4BuildingDevelopmentSimulator* self, uint32_t unused)
{
    (void)unused;
    if (FLDS_ab0af8(self, int32_t, 0x74) == 0) {
        DemandSim_ab0af8* ds = *gpB43d74_ab0af8;
        float a = ds->Fn06(0x1001, 0)->Fn08();
        float b = ds->Fn06(0x3001, 0)->Fn08();
        float c = ds->Fn06(0x4001, 0)->Fn08();
        uint32_t v = static_cast<uint32_t>(static_cast<int32_t>((c + b + a) * FLDS_ab0af8(self, float, 0xc8)));
        if (v < FLDS_ab0af8(self, uint32_t, 0xc0)) {
            v = FLDS_ab0af8(self, uint32_t, 0xc0);
        }
        if (v > FLDS_ab0af8(self, uint32_t, 0xc4)) {
            v = FLDS_ab0af8(self, uint32_t, 0xc4);
        }
        FLDS_ab0af8(self, Res18_ab0af8*, 0x70)->Fn18(static_cast<float>(static_cast<int32_t>(v)));
        TNode_ab0af8* header = FLDS_ab0af8(self, TNode_ab0af8*, 0x5c);
        for (TNode_ab0af8* it = header->mpLeft; it != header; it = TreeNext_ab0af8(it)) {
            reinterpret_cast<StepObj_ab0af8*>(it->mKey1)->Fn27();
        }
        FLDS_ab0af8(self, int32_t, 0x74) = 1;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006959e0 score 99
void Fn006959e0Draft_ab0af8(cSC4BuildingDevelopmentSimulator* self)
{
    uint32_t cap = 10;
    uint32_t key[3];
    Hold_ab0af8* hold;
    FLDS_ab0af8(self, uint32_t, 0xc0) = 100;
    FLDS_ab0af8(self, uint32_t, 0xc4) = 2000;
    FLDS_ab0af8(self, float, 0xc8) = 0.5f;
    key[0] = 0x6534284a;
    key[1] = 0xe7e2c2db;
    key[2] = 0xe8da7677;
    if (gpB43ca8_ab0af8->Fn03(key, 0xa52160f5, reinterpret_cast<void**>(&hold), 0, 0)) {
        PropsA_ab0af8* props = static_cast<PropsA_ab0af8*>(hold->Fn07());
        ObjA_ab0af8* obj = props->Fn09(0x47e2c380);
        if (obj) {
            uint32_t* pair = obj->Fn05()->Fn103();
            FLDS_ab0af8(self, uint32_t, 0xc0) = pair[0];
            FLDS_ab0af8(self, uint32_t, 0xc4) = pair[1];
        }
        Fn005fd4f0(props, 0x47e2c381, &FLDS_ab0af8(self, float, 0xc8));
        Fn005fd480(props, 0x47e2c382, &cap);
        Fn005ffcc0(props, 0x47e2c383, &FLDS_ab0af8(self, float, 0xd0));
        hold->Release();
    }
    FLDS_ab0af8(self, uint32_t, 0xcc) = cap;
}
#endif
struct OB_NOVTABLE Suit33_ab0af8 {
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
    virtual uint32_t Fn33() = 0;
};
struct OB_NOVTABLE Suit28_ab0af8 {
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
    virtual int8_t Fn12(uint32_t, uint32_t) = 0;
};
struct OB_NOVTABLE Suit2c_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual Suit33_ab0af8* Fn06(uint32_t, uint32_t, uint32_t) = 0;
};
struct OB_NOVTABLE Suit34_ab0af8 {
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
    virtual bool Fn19(uint32_t, uint32_t) = 0;
};
struct OB_NOVTABLE Suit30_ab0af8 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual uint32_t Fn05(uint32_t, uint32_t) = 0;
    virtual uint8_t Fn06(uint32_t, uint32_t) = 0;
};

// STUB: 0x00695390
bool Fn00695390(uint32_t kind, int32_t value);

// A hash table's rehash: the next prime from the table at 0x00a829b0, then every node moves.
// GLOBAL: 0x00a829b0
extern const uint32_t gA829b0[28];

inline uint32_t NextPrime_ab0af8(uint32_t n)
{
    const uint32_t* p = gA829b0;
    while (p != gA829b0 + 28 && *p < n) {
        p++;
    }
    if (p == gA829b0 + 28) {
        return 0xfffffffb;
    }
    return *p;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00696540 score 99
void Fn00696540Draft_ab0af8(HTab_ab0af8* self, uint32_t n)
{
    uint32_t old = static_cast<uint32_t>(self->mEnd - self->mBegin);
    if (n > old) {
        uint32_t nb = NextPrime_ab0af8(n);
        if (nb > old) {
            HNode_ab0af8** fresh = static_cast<HNode_ab0af8**>(Fn0090cf54(nb * 4));
            for (uint32_t k = 0; k < nb; k++) {
                fresh[k] = 0;
            }
            for (uint32_t i = 0; i < old; i++) {
                HNode_ab0af8* node = self->mBegin[i];
                while (node) {
                    uint32_t idx = node->mKey8 % nb;
                    self->mBegin[i] = node->mpNext;
                    node->mpNext = fresh[idx];
                    fresh[idx] = node;
                    node = self->mBegin[i];
                }
            }
            HNode_ab0af8** oldv = self->mBegin;
            self->mBegin = fresh;
            self->mEnd = fresh + nb;
            if (oldv) {
                Fn0090cf63(oldv);
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00696940 score 99
void Fn00696940Draft_ab0af8(HTab_ab0af8* self, uint32_t n)
{
    uint32_t old = static_cast<uint32_t>(self->mEnd - self->mBegin);
    if (n > old) {
        uint32_t nb = NextPrime_ab0af8(n);
        if (nb > old) {
            HNode_ab0af8** fresh = static_cast<HNode_ab0af8**>(Fn0090cf54(nb * 4));
            for (uint32_t k = 0; k < nb; k++) {
                fresh[k] = 0;
            }
            for (uint32_t i = 0; i < old; i++) {
                HNode_ab0af8* node = self->mBegin[i];
                while (node) {
                    const uint32_t* v = &node->mKey4;
                    uint32_t h = (((((v[0] << 6) | (v[1] & 0x3f)) << 6) | (v[2] & 0x3f)) << 4) | (static_cast<uint8_t>(v[3]) & 0xf);
                    uint32_t idx = h % nb;
                    self->mBegin[i] = node->mpNext;
                    node->mpNext = fresh[idx];
                    fresh[idx] = node;
                    node = self->mBegin[i];
                }
            }
            HNode_ab0af8** oldv = self->mBegin;
            self->mBegin = fresh;
            self->mEnd = fresh + nb;
            if (oldv) {
                Fn0090cf63(oldv);
            }
        }
    }
}
#endif

// The value of the building map: an 0x50-byte record.
struct Rec50_ab0af8 {
    uint32_t m[20];
    // STUB: 0x004d1230
    void Fn004d1230(const void* src);
};
struct HIns50_ab0af8 {
    HTab_ab0af8 t;
    // STUB: 0x0069b650
    char* Fn0069b650(const uint32_t* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0069b720 score 99
uint8_t* Fn0069b720Draft_ab0af8(HIns50_ab0af8* self, const uint32_t* key)
{
    uint32_t k = *key;
    uint32_t n = static_cast<uint32_t>(self->t.mEnd - self->t.mBegin);
    HNode_ab0af8* node;
    for (node = self->t.mBegin[k % n]; node && node->mKey8 != k; node = node->mpNext) {
    }
    if (!node) {
        uint32_t entry[22];
        for (int32_t i = 0; i < 22; i++) {
            entry[i] = 0;
        }
        entry[0] = k;
        entry[2] = 3;
        char* v = self->Fn0069b650(entry);
        return reinterpret_cast<uint8_t*>(v + 8);
    }
    return reinterpret_cast<uint8_t*>(node) + 0x10;
}
#endif

struct TreeMapT_ab0af8 {
    TNode_ab0af8* mpHeader;
    // STUB: 0x0069a8f0
    TNode_ab0af8** Fn0069a8f0(TNode_ab0af8** out, TNode_ab0af8* hint, const uint32_t* pair);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0069ab40 score 99
void* Fn0069ab40Draft_ab0af8(TreeMapT_ab0af8* self, const uint32_t* key)
{
    TNode_ab0af8* header = self->mpHeader;
    TNode_ab0af8* x = header->mpParent;
    TNode_ab0af8* y = header;
    while (x) {
        if (static_cast<uint32_t>(x->mKey0) < *key) {
            x = x->mpRight;
        } else {
            y = x;
            x = x->mpLeft;
        }
    }
    if (y == header || *key < static_cast<uint32_t>(y->mKey0)) {
        TNode_ab0af8* empty = static_cast<TNode_ab0af8*>(Fn0090cf54(0x18));
        empty->mColor = 0;
        empty->mpParent = 0;
        empty->mpLeft = empty;
        empty->mpRight = empty;
        uint32_t pair[3];
        pair[0] = *key;
        pair[1] = 0;
        pair[2] = 0;
        reinterpret_cast<TreeCopy2_ab0af8*>(pair + 1)->Fn00698a80(&empty);
        TNode_ab0af8* res;
        self->Fn0069a8f0(&res, y, pair);
        y = res;
        Fn0090cf63(empty);
    }
    return reinterpret_cast<char*>(y) + 0x14;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00695430 score 99
bool cSC4BuildingDevelopmentSimulator::IsSuitableForConstruction(void* profile, void* reason)
{
    uint32_t* p = static_cast<uint32_t*>(profile);
    uint32_t* r = static_cast<uint32_t*>(reason);
    uint32_t px = p[0x1c / 4];
    uint32_t py = p[0x20 / 4];
    int8_t c = FLD_ab0af8(Suit28_ab0af8*, 0x28)->Fn12(px, py);
    if (!Fn00695390(p[0], c)) {
        *r = 0;
        return false;
    }
    Suit33_ab0af8* obj = FLD_ab0af8(Suit2c_ab0af8*, 0x2c)->Fn06(px, py, 1);
    if (!obj) {
        *r = 3;
        return false;
    }
    if (!FLD_ab0af8(bool, 0xde) && !FLD_ab0af8(Suit34_ab0af8*, 0x34)->Fn19(px, py)) {
        *r = 5;
        return false;
    }
    uint8_t lo = static_cast<uint8_t>(p[0x10 / 4]);
    uint8_t hi = static_cast<uint8_t>(p[0x10 / 4] >> 8);
    if (!lo && !hi) {
        uint32_t e = FLD_ab0af8(Suit30_ab0af8*, 0x30)->Fn05(px, py);
        if (p[0] != 7 && p[0] != 8 && p[0] != 9 && e != p[2]) {
            *r = 2;
            return false;
        }
    }
    uint8_t v = FLD_ab0af8(Suit30_ab0af8*, 0x30)->Fn06(px, py);
    if (v < lo || v > hi) {
        *r = 1;
        return false;
    }
    if (obj->Fn33() != 1) {
        *r = 4;
        return false;
    }
    return true;
}
#endif
