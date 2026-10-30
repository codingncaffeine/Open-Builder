#include <cmath>
#include <cstddef>
#include <cstring>

#include "classes/cSC4Automaton.h"
#include "gzcom/cRZString.h"
#include "game/Globals.h"

// The primary vtable of the automaton with the signatures the code shows (the base interface declares some wrongly).
struct AutoVT_a95ac0 {
    virtual bool QueryInterface(uint32_t, void*);
    virtual void AddRef();
    virtual void Release();
    virtual bool Slot03_a953a8();
    virtual void Slot04_a953a8();
    virtual void* Slot05_a953a8();
    virtual void* Slot06_a953a8();
    virtual void Slot07_a953a8(void*);
    virtual void Slot08_a953a8(void*);
    virtual void Slot09_a953a8(bool);
    virtual void Slot10_a953a8(void*);
    virtual void Slot11_a953a8(void*);
    virtual bool Slot12_a953a8(void*);
    virtual void Slot13_a953a8(bool);
    virtual void Slot14_a953a8(void*);
    virtual bool Slot15_a953a8(void*);
    virtual void Slot16_a953a8(void*, void*);
    virtual float Slot17_a953a8();
    virtual bool Slot18_a953a8();
    virtual bool Slot19_a953a8(uint32_t);
    virtual bool Slot20_a953a8(void*);
    virtual void Slot21_a953a8(void*);
    virtual bool Slot22_a953a8(void*, uint32_t, bool, float);
    virtual uint32_t Slot23_a953a8();
    virtual void Slot24_a953a8(uint32_t);
    virtual void Slot25_a953a8(uint32_t);
    virtual uint32_t Slot26_a953a8();
    virtual uint32_t Slot27_a953a8();
    virtual void Slot28_a953a8(uint32_t);
    virtual void Slot29_a953a8();
    virtual void Slot30_a953a8(uint32_t, bool);
    virtual bool Slot31_a953a8(uint32_t);
    virtual void Slot32_a953a8();
    virtual void Slot33_a953a8(float, float);
    virtual void Slot34_a953a8();
    virtual float Slot35_a953a8();
    virtual void Slot36_a953a8(float, float);
    virtual float Slot37_a953a8();
    virtual float Slot38_a953a8();
    virtual void Slot39_a953a8(void*);
    virtual void Slot40_a953a8(void*);
    virtual void Slot41_a953a8(void*, void*);
    virtual void Slot42_a953a8();
    virtual void Slot43_a953a8();
    virtual void Slot44_a953a8();
    virtual void Slot45_a953a8(uint32_t, uint32_t);
    virtual void Slot46_a953a8(uint32_t, uint32_t, uint32_t);
    virtual void Slot47_a953a8(uint32_t, uint32_t, uint32_t);
    virtual void* Slot48_a953a8();
    virtual void Slot49_a953a8(void*);
    virtual void* Slot50_a953a8();
    virtual bool Slot51_a953a8(uint32_t, void*, float, uint8_t, uint32_t, uint32_t, void*);
    virtual bool Slot52_a953a8(uint32_t, void*, float, uint8_t, uint32_t, uint32_t, void*);
    virtual bool Slot53_a953a8();
    virtual void Slot54_a953a8(void*, void*);
    virtual bool Slot55_a953a8(void*, void*);
    virtual void* Slot56_a953a8();
    virtual void* Slot57_a953a8(uint32_t);
    virtual void* Slot58_a953a8(void*);
    virtual uint32_t Slot59_a953a8();
    virtual bool Slot60_a953a8(uint32_t, bool);
    virtual bool Slot61_a953a8(uint32_t);
    virtual bool Slot62_a953a8(uint32_t);
    virtual bool Slot63_a953a8();
    virtual void Slot64_a953a8(bool);
    virtual bool Slot65_a953a8(uint32_t, uint32_t);
    virtual void Slot66_a953a8(void*);
    virtual void* Slot67_a953a8();
    virtual void Slot68_a953a8();
    virtual void Slot69_a953a8();
    virtual bool Slot70_a95ac0(bool);
    virtual bool PlaceInOccupantManager(bool);
    virtual bool DoAnimationTick(uint32_t, uint32_t);
    virtual bool ShouldCollide(void*);
    virtual void SetZoomAndRotation(uint32_t, uint32_t);
    virtual bool SetTransform(void*);
    virtual uint32_t Slot76_a95ac0(void*);
    virtual void EnableActiveSound(bool);
    virtual void UpdateActiveSound(float);
    virtual void HandleReachedRouteDestination();
    virtual void Slot80_a95ac0(uint32_t, uint32_t);
    virtual bool HandleRemoveController(void*);
    virtual void* GetModelInstance();
    virtual void UpdateOpacity(float);
    virtual void SetSpeedFromBehaviorTemplate(void*);
    virtual bool GetMarkedForRemove();
    virtual bool GetSelfControlling();
    virtual bool GetReachedDestination();
    virtual bool GetSpecialRouteFlag();
    virtual void SetMarkedForRemove(bool);
    virtual void SetSpecialRouteFlag(bool);
    virtual void SetSelfControlling(bool);
    virtual void* GetDebugFlagsText();
    virtual void* GetDebugExtraText();
    virtual void* CreateAutomataState(uint32_t);
    virtual void SetAutomataGroup(void*);
    virtual void Slot96_a95ac0(uint32_t, void*);
    virtual bool LoadModels();
    virtual bool UnloadModels();
    virtual bool LoadAuxiliaryModel(uint32_t, void*);
    virtual void FinishMove(bool, bool);
    virtual bool PostInit();
    virtual void Slot102_a95ac0(uint32_t, uint32_t);
    virtual bool Slot103_a95ac0(float);
    virtual void UpdateEffects();
    virtual void UpdateAttraction();
    virtual void InitLighting();
    virtual void UpdateLighting();
    virtual void ClearStateStack();
    virtual bool DoStateTick(float);
    virtual bool HandleEnterState(void*);
    virtual void HandleExitState(void*);
    virtual bool DoIdleTick(uint32_t);
    virtual bool DoRandomWalkTick(uint32_t);
    virtual bool DoPlopJumpTick(float);
    virtual bool DoPlayerDriveTick(float);
    virtual bool DoBumpedTick(uint32_t);
    virtual bool DoMagnetTick(float);
    virtual bool DoScriptedTick(uint32_t);
    virtual bool DoAttachAnimTick(float);
    virtual bool DoCollideTick(uint32_t);
    virtual bool TranslatePlayerDriveCommands(uint32_t, uint32_t);
    virtual bool GetChaseVector(void*);
    virtual uint32_t GetCollidingAutomaton(uint32_t);
    virtual void RecalculateLeaders();
    virtual float GetSpeedModifier();
    virtual void InitGhostModel();
    virtual void ShutdownGhostModel();
    virtual void UpdateGhostModel();
};

#define AVT(self) reinterpret_cast<AutoVT_a95ac0*>(self)

// The occupant subobject at +0x4 and the property holder at +0xc, seen through their vtables.
#define OCCV(self) reinterpret_cast<OccView_a95ac0*>(reinterpret_cast<char*>(self) + 4)
struct OccView_a95ac0 {
    virtual bool QueryInterface(uint32_t, void*);
    virtual void AsOccupant();
    virtual void Slot02_a95ac0();
    virtual bool Slot03_a95ac0();
    virtual void Slot04_a95ac0();
    virtual bool Slot05_a95ac0_4();
    virtual void* Slot06_a95ac0_4();
    virtual uint32_t Slot07_a95ac0_4();
    virtual void SetVisible(void*);
    virtual void SetDestination(void*);
    virtual void Slot10_a95ac0_4(void*, void*);
    virtual void Slot11_a95ac0_4(void*);
    virtual void Slot12_a95ac0_4(uint32_t);
    virtual void Slot13_a95ac0_4(uint32_t);
    virtual bool Slot14_a95ac0_4(uint32_t);
    virtual void Slot15_a95ac0_4(uint32_t, uint32_t);
    virtual uint32_t Slot16_a95ac0_4();
    virtual void Slot17_a95ac0_4(uint32_t, bool);
    virtual void Slot18_a95ac0_4(bool, bool);
    virtual uint32_t Slot19_a95ac0_4();
    virtual void* Slot20_a95ac0_4();
    virtual void Slot21_a95ac0_4(void*);
    virtual bool Slot22_a95ac0_4(uint32_t);
    virtual void Slot23_a95ac0_4(uint32_t);
    virtual bool Slot24_a95ac0_4(void*);
    virtual bool Slot25_a95ac0_4(void*);
    virtual void Slot26_a95ac0_4(void*);
    virtual bool Slot27_a95ac0_4(uint32_t);
    virtual void Slot28_a95ac0_4(uint32_t);
    virtual void Slot29_a95ac0_4(uint32_t);
    virtual void Slot30_a95ac0_4(uint32_t);
    virtual void Slot31_a95ac0_4(uint32_t);
    virtual bool Slot32_a95ac0_4(uint32_t);
    virtual uint32_t Slot33_a95ac0_4();
};
struct PropView_a95ac0 {
    virtual bool QueryInterface(uint32_t, void*);
    virtual void AsOccupant();
    virtual void Slot02_a95ac0();
    virtual bool Slot03_a95ac0_c(uint32_t);
    virtual bool Slot04_a95ac0_c(void*);
    virtual bool Slot05_a95ac0_c(uint32_t, uint32_t, uint32_t);
    virtual bool Slot06_a95ac0_c(uint32_t, uint32_t, uint32_t);
    virtual bool Slot07_a95ac0_c(uint32_t, uint32_t);
    virtual bool Slot08_a95ac0_c(uint32_t, uint32_t);
    virtual void* Slot09_a95ac0_c(uint32_t);
    virtual void Slot10_a95ac0_c(uint32_t, uint32_t, uint32_t, uint32_t);
    virtual void Slot11_a95ac0_c(uint32_t, uint32_t, uint32_t);
    virtual void Slot12_a95ac0_c(uint32_t, uint32_t, uint32_t);
    virtual void Slot13_a95ac0_c(uint32_t, uint32_t, uint32_t);
    virtual void Slot14_a95ac0_c(void*, uint32_t, void*);
    virtual void Slot15_a95ac0_c(void*, void*);
    virtual void Slot16_a95ac0_c(void*, void*);
    virtual bool Slot17_a95ac0_c(uint32_t, uint32_t);
    virtual void Slot18_a95ac0_c(uint32_t);
    virtual void Slot19_a95ac0_c(void*, void*, void*);
    virtual void Slot20_a95ac0_c(void*, void*);
    virtual void Slot21_a95ac0_c();
    virtual void Pad22_a95ac0();
    virtual void Slot23_a95ac0_c();
    virtual void Slot24_a95ac0_c();
};

struct Vec3_a95ac0 {
    float x;
    float y;
    float z;
};

struct Vec3u_a95ac0 {
    uint32_t x;
    uint32_t y;
    uint32_t z;
};

// A state with the float table at +0x7c (also readable as raw words).
struct FloatState_a95ac0 {
    uint8_t mPad[0x7c];
    union {
        float mf7c[1];
        uint32_t mn7c[1];
    };
};

// GLOBAL: 0x00b21c84
extern float gfB21c84;

// The object seen from the subobject at +0x4 (offsets are the object's minus 4).
struct Sub4_a95ac0 {
    uint8_t mPad[0x28];
    uint8_t mBytes28[4];
    uint8_t mb2c;
    uint8_t mb2d;
    uint8_t mbFlags2e;
    uint8_t mbFlags2f;
    void* mp30;
    uint8_t mPad34[0x16c - 0x34];
    float mf16c;
    float mf170;
    float mf174;
    float mf178;
    float mf17c;
    float mf180;
};

// An effect handle the embedded object hands out; only the slot called here is named.
struct Effect_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Fn03(uint32_t);
};

// The object embedded at +0x18c (its vtable pointer first); only the slots called here are named.
struct Embedded_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Fn02(void*);
    virtual void* Fn03();
    virtual void Fn04(const void*, const void*, float);
    virtual void Pad05();
    virtual void Pad06();
    virtual void Fn07(uint32_t);
    virtual void Pad08();
    virtual Effect_a95ac0* Fn09(void*, void*);
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13(uint32_t, uint32_t);
    virtual void Fn14(uint32_t, uint32_t, uint32_t);
    virtual void Fn15(uint32_t, uint32_t, uint32_t);
};

inline Embedded_a95ac0* EmbeddedOf_a95ac0(cSC4Automaton* self)
{
    return reinterpret_cast<Embedded_a95ac0*>(reinterpret_cast<char*>(self) + 0x18c);
}

// A group template: its parent link sits at +0xc.
struct cOccupantGroup_a95ac0 {
    uint8_t mPad[0xc];
    cOccupantGroup_a95ac0* mpParent;
    uint32_t mnId10;
    uint8_t mPad14[0x44];
    float mf58;
    float mf5c;
    uint8_t mPad60[0x70 - 0x60];
    uint8_t mEffects[0x10];
    uint32_t mnEffectCount80;
    int32_t GetGroupHierarchyDepth();
    float Fn00505300();
    // STUB: 0x0046b4a0
    void* Fn0046b4a0();
};

// FUNCTION: 0x004fad60
bool cSC4Automaton::Slot31_a953a8(uint32_t flag)
{
    if (mnAutomataFlags & flag) {
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004fadf0 score 2
void cSC4Automaton::Slot44_a953a8()
{
    Embedded_a95ac0* p = EmbeddedOf_a95ac0(this);
    p->Fn12();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005059a0 score 2
void cSC4Automaton::Slot42_a953a8()
{
    Embedded_a95ac0* p = EmbeddedOf_a95ac0(this);
    p->Fn10();
}
#endif

// A state record: the depth of the state stack when it was pushed sits at +0xc.
struct State_a95ac0 {
    uint8_t mPad0[4];
    uint32_t mnBehavior;
    void* mpObj8;
    uint32_t mnDepth;
    float mf10;
    uint8_t mb14;
    uint8_t mPad15[3];
    uint32_t mn18;
    uint32_t mn1c;
    uint8_t mPad20[4];
    void* mp24;
    void* mpTarget;
};

// A smart-pointer-like element: its pointer sits first.
struct Holder_a95ac0 {
    void* mp;
    void* Get() { return mp; }
};

// A resource key: type, group, instance.
struct Key_a95ac0 {
    uint32_t mnType;
    uint32_t mnGroup;
    uint32_t mnInstance;
};

#if 0  // blocked: the base declares Slot15_a953a8 as void() (it takes the out pointer and returns bool)
// BLOCKED: 0x00505540
bool cSC4Automaton::Slot15_a953a8(void* pOut)
{
    Vec3_a95ac0* out = static_cast<Vec3_a95ac0*>(pOut);
    out->x = mfVec58X;
    out->y = mfVec58Y;
    out->z = mfVec58Z;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004fb340 score 5
void* cSC4Automaton::GetModelInstance()
{
    if (mpModelsBegin != mpModelsEnd) {
        return reinterpret_cast<Holder_a95ac0*>(mpModelsBegin)->Get();
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005098e0 score 7
uint32_t cSC4Automaton::Slot56_a953a8()
{
    if (mpStateEnd == mpStateBegin) {
        return 0;
    }
    return OB_ADDR(mpStateEnd[-1]);
}
#endif

// A controller's target: slot 5 hands out the automaton interface (slots used: 25, 55, 57, 60).
struct Obj2_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual uint32_t Fn04();
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
    virtual bool Fn25(uint32_t);
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
    virtual bool Fn55(uint32_t);
    virtual void Pad56();
    virtual bool Fn57(uint32_t, uint32_t);
    virtual void Pad58();
    virtual void Pad59();
    virtual bool Fn60(uint32_t, uint32_t);
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
    virtual uint32_t* Fn103();
};

struct StateObj_a95ac0 {
    virtual void Fn00(void*);
};

// What the _c subobject's lookup (Slot09_a95ac0_c) hands out.
struct Obj1_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Obj2_a95ac0* Fn05();
};

// The reference-counted base interface: slot 1 adds a reference, slot 2 releases one.
struct Unknown_a95ac0 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};

// A behavior template: the speed at +0x28.
struct BehaviorTemplate_a95ac0 {
    uint32_t mnId;
    uint8_t mPad4[0xc];
    uint8_t* mpRecBegin;
    uint8_t* mpRecEnd;
    uint8_t mPad18[4];
    int32_t* mpIntBegin;
    int32_t* mpIntEnd;
    uint8_t mPad24[4];
    float mf28;
    uint8_t mb2c;
    uint8_t mPad2d[3];
    float mf30;
    float mf34;
    int32_t mn38;
    int32_t mn3c;
    float mf40;
    float Fn00514c70();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00509920 score 13
uint32_t cSC4Automaton::Slot59_a953a8()
{
    void** end = mpStateEnd;
    void** begin = mpStateBegin;
    uint32_t result = 0;
    if (begin != end) {
        result = static_cast<State_a95ac0*>(mpStateEnd[-1])->mnBehavior;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00510210 score 19
bool cSC4Automaton::Slot20_a953a8(uint32_t a1)
{
    void* pKey = OB_PTR(void, a1);
    if (static_cast<Key_a95ac0*>(pKey)->mnInstance != 0) {
        if (mpModelsBegin != mpModelsEnd) {
            ReplaceModelInstance(*mpModelsBegin, pKey);
        }
    }
    return true;
}
#endif

struct ScriptSys_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void* Fn06(uint32_t);
};

struct WatercraftMgr_a95ac0;

struct Terrain_a95ac0 {
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
    virtual float Fn18(float, float);
};

struct AutoMgr_a95ac0 {
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
    virtual void* Fn22(void*, void*, void*, void*);
};

struct City_a95ac0 {
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
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual Terrain_a95ac0* Fn40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual WatercraftMgr_a95ac0* Fn46();
    virtual AutoMgr_a95ac0* Fn47();
    virtual ScriptSys_a95ac0* Fn48();
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
    virtual void Pad92();
    virtual int32_t Fn93();
    virtual int32_t Fn94();
    virtual void Fn95(float, float, int32_t*, int32_t*);
    virtual void Pad96();
    virtual void Pad97();
    virtual void Pad98();
    virtual bool Fn99(int32_t, int32_t);
};

// GLOBAL: 0x00b43cec
extern City_a95ac0* gpB43cec_a95ac0;

// The interface the model instances share through their virtual base (the base sits after the vtable pointer and the base pointer).
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverloaded-virtual"  // views of the original vtables: the overloads hide the base ones on purpose
#endif
struct ModelVBase_a95ac0 {
    virtual void VPad00();
    virtual void AddRef();
    virtual void Release();
    virtual void VPad03();
    virtual void VPad04();
    virtual void VPad05();
    virtual void VPad06();
    virtual void VPad07();
    virtual void Fn08(void*);
    virtual void Fn09(void*);
    virtual void Fn10(void*);
    virtual void VPad11();
    virtual void VPad12();
    virtual void VPad13();
    virtual void VPad14();
    virtual void Fn15(void*);
    virtual void Fn16(void*);
};

// A model instance: its own slots, and a virtual base reached through the base pointer at +4.
struct ModelInst_a95ac0 : virtual ModelVBase_a95ac0 {
    virtual void* Fn00();
    virtual void Fn01(void*);
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn08(uint32_t, uint32_t);
    virtual void Pad09();
    virtual void Pad10();
    virtual int32_t Fn11();
    virtual int32_t Fn12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Fn15(float);
    virtual void Fn16(uint32_t);
    virtual void Pad17();
    virtual void Fn18(uint32_t, float);
};
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

// The ramped value embedded at +0x1a0: where it started, where it is going, and the rest of the ramp.
struct Ramp_a95ac0 {
    float mfFrom;
    float mfTo;
    float mfB;
    union {
        uint32_t mnC;
        float mfC;
    };
    // STUB: 0x004fa960
    float Fn004fa960();
};

// A node of the callback list: next, previous, the callback.
struct ListNode_a95ac0 {
    ListNode_a95ac0* mpNext;
    ListNode_a95ac0* mpPrev;
    Unknown_a95ac0* mpValue;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* block);

// A node of the key-effect hashtable: next link, then the unsigned-char key.
struct HNode_a95ac0 {
    HNode_a95ac0* mpNext;
    uint8_t mnKey;
};

struct HTable_a95ac0 {
    uint32_t mnPad0;
    HNode_a95ac0** mpBegin;
    HNode_a95ac0** mpEnd;
};

struct HIter_a95ac0 {
    HNode_a95ac0* mpCur;
    HTable_a95ac0* mpTable;
    HNode_a95ac0* Fn0050bbe0();
};

// The string argument of the group lookup: the base at +4 is what the table takes.
struct StrBase_a95ac0 {
    virtual void Pad00();
};

struct StrOwner_a95ac0 {
    virtual void Pad00();
};

struct Str_a95ac0 : StrOwner_a95ac0, StrBase_a95ac0 {
};

struct GroupNode_a95ac0 {
    uint8_t mPad[0x10];
    uint32_t mnValue;
};

struct GroupTable_a95ac0 {
    // STUB: 0x0051c9f0
    GroupNode_a95ac0* Find(StrBase_a95ac0* name);
};

struct GroupMgr_a95ac0 {
    uint8_t mPad[0x34];
    GroupTable_a95ac0 mTable;
    bool Fn0051d970(Str_a95ac0* name, uint32_t* pOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00509400 score 22
bool cSC4Automaton::Slot12_a953a8(uint32_t a1)
{
    void* arg = OB_PTR(void, a1);
    void** begin = mpModelsBegin;
    void** end = mpModelsEnd;
    if (begin != end) {
        ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*begin);
        ModelVBase_a95ac0& base = *model;
        base.Fn09(arg);
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004fad20 score 19
void cSC4Automaton::Slot30_a953a8(uint32_t flag, uint32_t a2)
{
    bool on = a2 != 0;
    if (on) {
        mnAutomataFlags |= flag;
    } else {
        mnAutomataFlags &= ~flag;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050bb90 score 21
void cSC4Automaton::Slot40_a953a8(uint32_t a1)
{
    void* pCallback = OB_PTR(void, a1);
    ListNode_a95ac0* head = static_cast<ListNode_a95ac0*>(mpCallbacks);
    ListNode_a95ac0* node;
    for (node = head->mpNext; node != head; node = node->mpNext) {
        if (node->mpValue == pCallback) {
            break;
        }
    }
    if (node != head) {
        ListNode_a95ac0* prev = node->mpPrev;
        ListNode_a95ac0* next = node->mpNext;
        prev->mpNext = next;
        next->mpPrev = prev;
        if (node->mpValue != 0) {
            node->mpValue->Release();
        }
        Fn0090cf63(node);
    }
}
#endif

struct Renderer_a95ac0 {
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
    virtual bool Fn27(void*);
    virtual bool Fn28(void*);
    virtual void Fn29(void*);
    virtual void Fn30(void*);
    virtual void Fn31(void*);
};

// GLOBAL: 0x00b43dd0
extern Renderer_a95ac0* gpB43dd0;

// The object at +0x12c: a smart pointer whose assignment returns whether it took the value.
struct Light_a95ac0 {
    void* mpValue;
    // STUB: 0x008038d0
    bool Fn008038d0(void* value);
    // STUB: 0x00803e10
    void Fn00803e10(void* manager, uint32_t flag);
};

// STUB: 0x005e5620
void Fn005e5620(void* block);

#ifdef OB_DRAFTS
// CLOSE: 0x00505a40 score 20
void cSC4Automaton::Slot66_a953a8(uint32_t a1)
{
    void* pOut = OB_PTR(void, a1);
    Vec3_a95ac0* out = static_cast<Vec3_a95ac0*>(pOut);
    out->x = mfPosX;
    out->y = mfPosY;
    out->z = mfPosZ;
    float length = mfLength;
    float dx = length * mfVec58X;
    float dy = length * mfVec58Y;
    float dz = length * mfVec58Z;
    out->x -= dx;
    out->y -= dy;
    out->z -= dz;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00509440 score 7
bool cSC4Automaton::SetTransform(void* pTransform)
{
    if (mpModelsBegin != mpModelsEnd) {
        void** it = mpModelsBegin;
        do {
            ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*it);
            if (model != 0) {
                ModelVBase_a95ac0& base = *model;
                base.Fn10(pTransform);
            }
            ++it;
        } while (it != mpModelsEnd);
    }
    return mpModelsEnd != mpModelsBegin;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00510240 score 15
bool cSC4Automaton::Slot19_a953a8(uint32_t index)
{
    Key_a95ac0 key = { mnAnimKeyType, mnAnimKeyGroup, mnAnimKeyInstance };
    if (key.mnInstance != 0) {
        if (mpModelsBegin != mpModelsEnd) {
            key.mnInstance = key.mnInstance + index;
            ReplaceModelInstance(*mpModelsBegin, &key);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00508d00 score 28
void cSC4Automaton::ShutdownGhostModel()
{
    if (mpGhost != 0) {
        ModelInst_a95ac0* ghost = static_cast<ModelInst_a95ac0*>(mpGhost);
        if (gpB43dd0->Fn27(ghost->Fn00())) {
            ghost = static_cast<ModelInst_a95ac0*>(mpGhost);
            gpB43dd0->Fn29(ghost->Fn00());
        }
        ghost = static_cast<ModelInst_a95ac0*>(mpGhost);
        if (ghost != 0) {
            mpGhost = 0;
            ModelVBase_a95ac0& base = *ghost;
            base.Release();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050d510 score 52
void cSC4Automaton::ClearStateStack()
{
    for (void** it = mpStateBegin; it != mpStateEnd; ++it) {
        StateObj_a95ac0* state = static_cast<StateObj_a95ac0*>(*it);
        if (state != 0) {
            state->Fn00(this);
            Fn005e5620(state);
        }
    }
    mpStateEnd = mpStateBegin;
}
#endif

// The message the sound/state code posts (vtable 0x00acec00, 0x2c bytes from the pool); slots as used in cSC4Demand.cpp.
// STUB: 0x009133da is the pool allocator the original's `new` calls.
// STUB: 0x009133da
void* Fn009133da(uint32_t size);

struct Msg_a95ac0 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05(uint32_t);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Fn11(uint32_t);
    virtual void Fn12(void*);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Fn16(uint32_t);
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Fn21(uint32_t);
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Fn26(uint32_t);
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Fn33(void*);
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    Msg_a95ac0();
    static void* operator new(size_t size) { return Fn009133da(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

// STUB: 0x005ff510
bool Fn005ff510(void* controller, uint32_t key, void* pVec);

inline Sub4_a95ac0* Sub4Of_a95ac0(cSC4Automaton* self)
{
    return reinterpret_cast<Sub4_a95ac0*>(reinterpret_cast<char*>(self) + 4);
}

// FUNCTION: 0x00505690
bool cSC4Automaton::DoBumpedTick(uint32_t)
{
    if (AVT(this)->Slot31_a953a8(1)) {
        return false;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00507e00 score 45
void cSC4Automaton::Slot96_a95ac0(uint32_t index, void* pOut)
{
    Vec3u_a95ac0* begin = static_cast<Vec3u_a95ac0*>(mpPathBegin);
    uint32_t count = static_cast<Vec3u_a95ac0*>(mpPathEnd) - begin;
    uint32_t x = 0;
    uint32_t y = 0;
    uint32_t z = 0;
    if (index < count) {
        const Vec3u_a95ac0& v = static_cast<Vec3u_a95ac0*>(mpPathBegin)[index];
        x = v.x;
        y = v.y;
        z = v.z;
    }
    Vec3u_a95ac0* out = static_cast<Vec3u_a95ac0*>(pOut);
    out->x = x;
    out->y = y;
    out->z = z;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050d490 score 18
void cSC4Automaton::Slot39_a953a8(uint32_t a1)
{
    void* pCallback = OB_PTR(void, a1);
    Unknown_a95ac0* callback = static_cast<Unknown_a95ac0*>(pCallback);
    if (callback != 0) {
        ListNode_a95ac0* head = static_cast<ListNode_a95ac0*>(mpCallbacks);
        ListNode_a95ac0* node = head->mpNext;
        while (node != head) {
            if (node->mpValue == callback) {
                break;
            }
            node = node->mpNext;
        }
        if (node == head) {
            callback->AddRef();
            ListNode_a95ac0* end = static_cast<ListNode_a95ac0*>(mpCallbacks);
            ListNode_a95ac0* added = static_cast<ListNode_a95ac0*>(Fn0090cf54(sizeof(ListNode_a95ac0)));
            if (&added->mpValue != 0) {
                added->mpValue = callback;
                callback->AddRef();
            }
            ListNode_a95ac0* prev = end->mpPrev;
            added->mpNext = end;
            added->mpPrev = prev;
            prev->mpNext = added;
            end->mpPrev = added;
            callback->Release();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005056a0 score 6
bool cSC4Automaton::Slot60_a953a8(uint32_t index, uint32_t a2)
{
    bool flag = a2 != 0;
    FloatState_a95ac0* state = static_cast<FloatState_a95ac0*>(AVT(this)->Slot57_a953a8(0x10));
    if (state != 0) {
        if (flag) {
            if (state->mf7c[index] < 0.0f) {
                state->mn7c[index] = 0;
                Slot102_a95ac0(0xe, index);
            }
            return true;
        }
        if (state->mf7c[index] >= 0.0f) {
            Slot102_a95ac0(0xf, index);
        }
        state->mn7c[index] = 0xbf800000;
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050c330 score 49
void cSC4Automaton::EnableActiveSound(bool enable)
{
    if (!mbActiveSound1dc) {
        if (enable) {
            mpVec1c8End = mpVec1c8Begin;
            Fn005ff510(OCCV(this)->Slot06_a95ac0_4(), 0x6c044bb5, &mpVec1c8Begin);
        }
        mbActiveSound1dc = enable;
    } else {
        mbActiveSound1dc = enable;
    }
}
#endif

// The random generator object at 0xb21d78 (cRZRandomSuper): a count, an integer range and a double range.
struct Random_a95ac0 {
    // STUB: 0x00913a06
    uint32_t Fn00913a06(uint32_t count);
    // STUB: 0x00913a14
    int32_t Fn00913a14(int32_t low, int32_t high);
    // STUB: 0x00913a46
    double Fn00913a46(double low, double high);
    // STUB: 0x00913a29
    double Fn00913a29();
};

// GLOBAL: 0x00b21d78
extern Random_a95ac0 gB21d78;

#ifdef OB_DRAFTS
// CLOSE: 0x00505780 score 19
void cSC4Automaton::SetSpeedFromBehaviorTemplate(void* pTemplate)
{
    BehaviorTemplate_a95ac0* t = static_cast<BehaviorTemplate_a95ac0*>(pTemplate);
    float speed = field80;
    int32_t low = t->mn38;
    if (low > 0 && t->mn3c > 0) {
        int32_t value;
        if (low == t->mn3c) {
            value = low;
        } else {
            value = gB21d78.Fn00913a14(low, t->mn3c);
        }
        speed = static_cast<float>(value) * 2.77777814e-4f;
    }
    float result;
    if (t->mf34 != t->mf30) {
        result = static_cast<float>(gB21d78.Fn00913a46(t->mf30, t->mf34)) * speed;
    } else {
        result = speed * t->mf30;
    }
    AVT(this)->Slot36_a953a8(result, t->mf40);
}
#endif

#if 0  // blocked: the base declares Slot55_a953a8 as void(uint32_t, uint32_t) (it returns bool)
// BLOCKED: 0x0050b740
bool cSC4Automaton::Slot55_a953a8(uint32_t a1, uint32_t a2)
{
    void* pTemplate = OB_PTR(void, a1);
    void* x = OB_PTR(void, a2);
    BehaviorTemplate_a95ac0* t = static_cast<BehaviorTemplate_a95ac0*>(pTemplate);
    if (t == 0) {
        return false;
    }
    int32_t chosenInt = 0;
    if (t->mpIntBegin != t->mpIntEnd) {
        uint32_t index = gB21d78.Fn00913a06(static_cast<uint32_t>(t->mpIntEnd - t->mpIntBegin));
        chosenInt = t->mpIntBegin[index];
    }
    uint32_t anim = 0;
    if (t->mpRecBegin != t->mpRecEnd) {
        uint32_t index = gB21d78.Fn00913a06(static_cast<uint32_t>((t->mpRecEnd - t->mpRecBegin) / 20));
        anim = index;
        Slot76_a95ac0(t->mpRecBegin + index * 20);
    }
    return AVT(this)->Slot52_a953a8(t->mnId, x, t->Fn00514c70(), t->mb2c, anim, chosenInt, t);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050b660 score 42
bool cSC4Automaton::Slot53_a953a8()
{
    if (mpStateBegin != mpStateEnd) {
        State_a95ac0* state = static_cast<State_a95ac0*>(mpStateEnd[-1]);
        HandleExitState(state);
        if (state->mb14 != 0 && state->mnBehavior != 1) {
            AVT(this)->Slot52_a953a8(1, 0, -1.0f, 0, 0, 0, 0);
            return true;
        }
        if (state->mpObj8 != 0) {
            static_cast<Unknown_a95ac0*>(state->mpObj8)->Release();
        }
        mpStateEnd = mpStateEnd - 1;
        Fn005e5620(state);
        if (!GetMarkedForRemove()) {
            if (mpStateBegin != mpStateEnd) {
                HandleEnterState(mpStateEnd[-1]);
            }
        }
        return true;
    }
    return false;
}
#endif

struct OccMgr_a95ac0 {
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
    virtual void Fn17(float, float, int32_t*, int32_t*);
    virtual void Pad18();
    virtual void Pad19();
    virtual bool Fn20(void*, uint32_t);
    virtual void Fn21(void*, uint32_t, uint32_t);
    virtual void Pad22();
    virtual void Pad23();
    virtual void Fn24(void*, uint32_t);
};

// GLOBAL: 0x00b43d0c
extern OccMgr_a95ac0* gpB43d0c;

struct Sim_a95ac0 {
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
    virtual bool Fn15();
    virtual void Pad16();
    virtual bool Fn17();
};

// GLOBAL: 0x00b43d5c
extern Sim_a95ac0* gpB43d5c;

#ifdef OB_DRAFTS
// CLOSE: 0x00508d70 score 39
bool cSC4Automaton::DoCollideTick(uint32_t)
{
    if (AVT(this)->Slot31_a953a8(1)) {
        return false;
    }
    if (Sub4Of_a95ac0(this)->mbFlags2f & 2) {
        AVT(this)->Slot09_a953a8(false);
    }
    if (mpModelsBegin != mpModelsEnd) {
        ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*mpModelsBegin);
        ModelVBase_a95ac0* base = model;
        base->Fn08(&mfVec170X);
    }
    if (Sub4Of_a95ac0(this)->mbFlags2f & 1) {
        gpB43d0c->Fn24(Sub4Of_a95ac0(this), 0);
    }
    if (mf1c0 > 100.0f) {
        Slot102_a95ac0(9, 0);
        mf1c0 = 0.0f;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050f140 score 51
void cSC4Automaton::SetAutomataGroup(void* pGroup)
{
    cOccupantGroup_a95ac0* group = static_cast<cOccupantGroup_a95ac0*>(pGroup);
    if (group != 0) {
        mnGroupId = group->mnId10;
        if (group->mf58 > 0.0f) {
            float high;
            if (group->mf5c > 0.0f) {
                high = group->mf5c;
            } else if (group->mpParent != 0) {
                high = group->mpParent->Fn00505300();
            } else {
                high = 0.0f;
            }
            float speed = static_cast<float>(gB21d78.Fn00913a46(group->mf58, high)) * 2.77777814e-4f;
            field80 = speed;
            AVT(this)->Slot36_a953a8(speed, 0);
        }
        Fn0050d870();
        ApplyAutomataGroup();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005089f0 score 35
bool cSC4Automaton::Slot103_a95ac0(float dt)
{
    if (gpB43d5c->Fn17() || !gpB43d5c->Fn15()) {
        for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
            ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*it);
            if (model != 0) {
                model->Fn15(dt);
            }
        }
        ListNode_a95ac0* head = static_cast<ListNode_a95ac0*>(mpCallbacks);
        if (head->mpNext != head && mpModelsBegin != mpModelsEnd) {
            ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*mpModelsBegin);
            int32_t last = model->Fn12() - 1;
            if (model->Fn11() >= last) {
                Slot102_a95ac0(1, 0);
            }
        }
        mf1c0 = dt + mf1c0;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005058a0 score 45
uint32_t cSC4Automaton::Slot76_a95ac0(void* pKey)
{
    PropView_a95ac0* controllers = reinterpret_cast<PropView_a95ac0*>(reinterpret_cast<char*>(this) + 0xc);
    Obj1_a95ac0* obj = static_cast<Obj1_a95ac0*>(controllers->Slot09_a95ac0_c(0xaa1dd396));
    if (obj != 0) {
        ScriptSys_a95ac0* system = gpB43cec_a95ac0->Fn48();
        Obj2_a95ac0* list = obj->Fn05();
        uint32_t* ids = list->Fn103();
        for (uint32_t i = 0; i < list->Fn04(); ++i) {
            GroupMgr_a95ac0* group = static_cast<GroupMgr_a95ac0*>(system->Fn06(ids[i]));
            if (group != 0) {
                uint32_t out;
                if (group->Fn0051d970(static_cast<Str_a95ac0*>(pKey), &out)) {
                    return out;
                }
            }
        }
        return 0;
    }
    return 0;
}
#endif

// A state record of the animation kind: the model at +0x28 (smart pointer), a byte at +0x2c and a word at +0x30.
struct AnimState_a95ac0 {
    uint8_t mPad[0x28];
    ModelInst_a95ac0* mpModel28;
    uint8_t mb2c;
    uint8_t mPad2d[3];
    int32_t mn30;
};

// GLOBAL: 0x00b09978
extern float gfB09978;

// STUB: 0x005fd5b0
bool Fn005fd5b0(void* controller, uint32_t key, void* pOut);

// STUB: 0x004ecd60
void* Fn004ecd60();

// STUB: 0x004f7bb0
uint32_t Fn004f7bb0();

#ifdef OB_DRAFTS
// CLOSE: 0x0050eb20 score 45
bool cSC4Automaton::LoadAuxiliaryModel(uint32_t kind, void* pOut)
{
    Key_a95ac0 key = { 0, 0, 0 };
    uint32_t instance;
    switch (kind) {
    case 1:
        instance = 0x09c80417;
        break;
    case 2:
        instance = 0xc9e69af6;
        break;
    case 3:
        instance = 0xec214180;
        break;
    default:
        instance = kind;
        break;
    }
    if (Fn005fd5b0(OCCV(this)->Slot06_a95ac0_4(), instance, &key)) {
        ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(AddModelInstance(&key));
        *static_cast<ModelInst_a95ac0**>(pOut) = model;
        if (model != 0) {
            ModelVBase_a95ac0* base = model;
            base->AddRef();
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005102a0 score 48
bool cSC4Automaton::Slot22_a953a8(uint32_t a1, uint32_t b, uint32_t a3, uint32_t a4)
{
    void* pKey = OB_PTR(void, a1);
    bool c = a3 != 0;
    float d = *reinterpret_cast<float*>(&a4);
    bool result = false;
    if (AVT(this)->Slot52_a953a8(0x13, 0, d, 0, 0, 0, 0)) {
        AnimState_a95ac0* state = static_cast<AnimState_a95ac0*>(AVT(this)->Slot56_a953a8());
        state->mb2c = c;
        state->mn30 = b;
        ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(AddModelInstance(pKey));
        ModelInst_a95ac0* old = state->mpModel28;
        if (model != old) {
            if (model != 0) {
                ModelVBase_a95ac0* base = model;
                base->AddRef();
            }
            state->mpModel28 = model;
            if (old != 0) {
                ModelVBase_a95ac0* oldBase = old;
                oldBase->Release();
            }
        }
        if (state->mpModel28 != 0) {
            state->mpModel28->Fn16(b);
            state->mpModel28->Fn18(1, 0.0f);
            return true;
        }
        return false;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050af10 score 42
void cSC4Automaton::Slot14_a953a8(uint32_t a1)
{
    void* pDir = OB_PTR(void, a1);
    Sub4_a95ac0* sub = Sub4Of_a95ac0(this);
    uint8_t flags = sub->mbFlags2f;
    if ((flags & 1) && (flags & 2)) {
        AVT(this)->Slot16_a953a8(0, pDir);
        return;
    }
    const Vec3_a95ac0* dir = static_cast<const Vec3_a95ac0*>(pDir);
    mfVec58X = dir->x;
    mfVec58Y = dir->y;
    mfVec58Z = dir->z;
    float length = static_cast<float>(std::sqrt(static_cast<double>(mfVec58X * mfVec58X + mfVec58Y * mfVec58Y + mfVec58Z * mfVec58Z)));
    float scale = gfB09978 / length;
    mfVec58X = mfVec58X * scale;
    mfVec58Y = mfVec58Y * scale;
    mfVec58Z = mfVec58Z * scale;
    for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
        ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*it);
        ModelVBase_a95ac0* base = model;
        PositionModelInstance(base);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005091c0 score 8
void cSC4Automaton::UpdateOpacity(float dt)
{
    Ramp_a95ac0* ramp = reinterpret_cast<Ramp_a95ac0*>(reinterpret_cast<char*>(this) + 0x1b0);
    float before = ramp->Fn004fa960();
    if (ramp->mfC < ramp->mfB) {
        ramp->mfC = dt * 0.001f + ramp->mfC;
        if (ramp->mfC >= ramp->mfB) {
            ramp->mfFrom = ramp->mfTo;
            ramp->mnC = 0;
            ramp->mfB = 0.0f;
        }
    }
    float after = ramp->Fn004fa960();
    if (before != after) {
        for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
            ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*it);
            if (model != 0) {
                if (after < 1.0f) {
                    model->Fn18(1, after);
                } else {
                    model->Fn18(0, 1.0f);
                }
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00509950 score 64
bool cSC4Automaton::Slot61_a953a8(uint32_t id)
{
    if (id != 0) {
        Fn004ecd60();
        mnSfx8c = Fn004f7bb0();
        Msg_a95ac0* msg = new Msg_a95ac0;
        msg->AddRef();
        msg->Fn05(0x8a385dd8);
        msg->Fn33(static_cast<void*>(AVT(this)->Slot05_a953a8()));
        msg->Fn11(id);
        msg->Fn16(mnSfx8c);
        gpB43ccc->MessagePost(msg, false);
        msg->Release();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050d3c0 score 41
bool cSC4Automaton::UnloadModels()
{
    if (Sub4Of_a95ac0(this)->mbFlags2f & 2) {
        PlaceInOccupantManager(false);
    }
    reinterpret_cast<Light_a95ac0*>(&mpLight12c)->Fn008038d0(0);
    for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
        ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*it);
        if (model != 0) {
            ModelVBase_a95ac0* base = model;
            base->Release();
        }
    }
    mpModelsEnd = mpModelsBegin;
    mpPathEnd = mpPathBegin;
    InitLighting();
    return true;
}
#endif

typedef void (*PropVisit_a95ac0)(void* prop, void* context);
typedef bool (*PropFilter_a95ac0)(void* prop, void* context);

// A node of the set<uint32_t> the group collectors fill: header-based red-black tree, value at +0x10.
struct SetNode_a95ac0 {
    uint8_t mPad[4];
    SetNode_a95ac0* mpParent;
    SetNode_a95ac0* mpLeft;
    SetNode_a95ac0* mpRight;
    uint32_t mnValue;
};

struct Set_a95ac0 {
    SetNode_a95ac0* mpHead;
    uint32_t mnCount;
    // STUB: 0x0046f820
    void Fn0046f820(SetNode_a95ac0* root);
    // STUB: 0x0049a050
    void Fn0049a050(void* pResult, const uint32_t* pValue);
};

// A vector of 32-bit words as the callee fills it.
struct WordVec_a95ac0 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x0051ca60
    void Fn0051ca60(uint32_t* pos, const uint32_t* pValue, uint32_t a, uint32_t b);
};

// What a model hands back for its animation progress (slot 15 of the virtual base): the progress at +0x10, the rate at +0x18.
struct AnimInfo_a95ac0 {
    float mf0;
    float mf4;
    float mf8;
    float mfc;
    float mf10;
    float mf14;
    float mf18;
};

// GLOBAL: 0x00b43ddc
extern void* gpB43ddc;

// The view utilities (zoom level at +0xc).
struct ViewUtil_a95ac0 {
    uint8_t mPad[0xc];
    int32_t mnZoom;
    // STUB: 0x007f66a0
    void GetZoomAndRotation(int32_t* pZoom, int32_t* pRotation);
};

// GLOBAL: 0x00b43dd8
extern ViewUtil_a95ac0* gpB43dd8;

// GLOBAL: 0x00a95554
extern const float gaA95554[];

// GLOBAL: 0x00a95540
extern const float gaA95540[];

#ifdef OB_DRAFTS
// CLOSE: 0x00508f80 score 79
bool cSC4Automaton::DoAttachAnimTick(float)
{
    if (AVT(this)->Slot31_a953a8(1)) {
        return false;
    }
    AnimState_a95ac0* state = static_cast<AnimState_a95ac0*>(AVT(this)->Slot56_a953a8());
    if (state->mpModel28 != 0) {
        AnimInfo_a95ac0 info;
        ModelVBase_a95ac0* base = state->mpModel28;
        base->Fn15(&info);
        if (info.mf10 < 1.0f) {
            float step = info.mf18 / (gfB21c84 * 0.5f);
            info.mf18 = 1.0f;
            info.mf10 = step + info.mf10;
            const float* value = &info.mf18;
            if (!(1.0f < info.mf10)) {
                value = &info.mf10;
            }
            state->mpModel28->Fn18(1, *value);
        }
    }
    if (!(state->mn30 >= 2 && state->mn30 <= 3)) {
        if (state->mpModel28 != 0) {
            int32_t last = state->mpModel28->Fn12() - 1;
            if (state->mpModel28->Fn11() >= last) {
                AVT(this)->Slot53_a953a8();
                return true;
            }
        }
    }
    return state->mb2c;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00507e60 score 122
bool cSC4Automaton::Slot70_a95ac0(bool on)
{
    bool result = false;
    uint8_t flags = Sub4Of_a95ac0(this)->mbFlags2f;
    uint8_t current = flags & 1;
    if (current != on) {
        if (gpB43d0c == 0) {
            return result;
        }
        OccView_a95ac0* sub = reinterpret_cast<OccView_a95ac0*>(reinterpret_cast<char*>(this) + 4);
        if (current) {
            if (flags & 2) {
                if (gpB43dd0 != 0) {
                    for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
                        ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*it);
                        if (model != 0) {
                            gpB43dd0->Fn29(model->Fn00());
                        }
                    }
                }
                sub->Slot31_a95ac0_4(2);
            }
            gpB43d0c->Fn21(sub, 0, 0);
            sub->Slot31_a95ac0_4(1);
            return true;
        }
        if (mpModelsBegin != mpModelsEnd) {
            ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*mpModelsBegin);
            if (model != 0) {
                ModelVBase_a95ac0* base = model;
                if (base != 0) {
                    base->Fn08(&mfVec170X);
                }
            }
        }
        if (gpB43d0c->Fn20(sub, 0)) {
            sub->Slot29_a95ac0_4(1);
            return true;
        }
        return result;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00509290 score 58
void cSC4Automaton::UpdateLighting()
{
    void* lighting = gpB43ddc;
    if (!AVT(this)->Slot31_a953a8(0x100000) && lighting != 0 && mpLight12c != 0) {
        int32_t zoom = 0;
        if (gpB43dd8 != 0) {
            zoom = gpB43dd8->mnZoom;
        }
        float dx = mfVec58X - mfDirOldX;
        float dy = mfVec58Y - mfDirOldY;
        float dz = mfVec58Z - mfDirOldZ;
        const float* limits = &gaA95554[zoom * 3];
        bool still = std::fabs(dx) <= limits[0] && std::fabs(dy) <= limits[1] && std::fabs(dz) <= limits[2];
        if (still) {
            float px = mfPosX - mfPosOldX;
            float py = mfPosY - mfPosOldY;
            float pz = mfPosZ - mfPosOldZ;
            if (px * px + py * py + pz * pz <= gaA95540[zoom]) {
                return;
            }
        }
        reinterpret_cast<Light_a95ac0*>(&mpLight12c)->Fn00803e10(lighting, 0);
        mfPosOldX = mfPosX;
        mfPosOldY = mfPosY;
        mfPosOldZ = mfPosZ;
        mfDirOldX = mfVec58X;
        mfDirOldY = mfVec58Y;
        mfDirOldZ = mfVec58Z;
    }
}
#endif

struct Boat_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Fn07(void*);
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual float Fn17();
};

// A node of the manager's docking table: next, the lot, and two slots holding a boat each.
struct DockNode_a95ac0 {
    DockNode_a95ac0* mpNext;
    void* mpLot;
    void* mpBoatA;
    void* mpBoatB;
};

// cSC4WatercraftManager: the boats list head at +0x44, the docking hashtable buckets at +0xa90.
struct WatercraftMgr_a95ac0 {
    uint8_t mPad0[0x44];
    ListNode_a95ac0* mpBoats;
    uint8_t mPad48[0xa90 - 0x48];
    DockNode_a95ac0** mpBucketsBegin;
    DockNode_a95ac0** mpBucketsEnd;
    uint8_t mPada98[4];
    uint32_t mnA9c;
    uint8_t mPadaa0[0xac4 - 0xaa0];
    uint32_t mnAc4;
    // STUB: 0x0056cfe0
    void DoneDocking(void* lot, void* boat);
    // STUB: 0x0056d060
    void Fn0056d060(void* lot, void* boat);
    void* LookForBoatsAtPosition(Vec3_a95ac0 position, Boat_a95ac0* skip);
};

// STUB: 0x005d17c0
SetNode_a95ac0* SetNext_a95ac0(SetNode_a95ac0* node);

#ifdef OB_DRAFTS
// CLOSE: 0x0050b290 score 24
bool cSC4Automaton::HandleRemoveController(void* pController)
{
    Unknown_a95ac0* controller = static_cast<Unknown_a95ac0*>(pController);
    if (controller != 0) {
        State_a95ac0* top = static_cast<State_a95ac0*>(AVT(this)->Slot56_a953a8());
        while (top != 0 && top->mpObj8 == controller) {
            AVT(this)->Slot53_a953a8();
            top = static_cast<State_a95ac0*>(AVT(this)->Slot56_a953a8());
        }
        void** it = mpStateBegin;
        while (it != mpStateEnd) {
            State_a95ac0* state = static_cast<State_a95ac0*>(*it);
            if (state->mpObj8 == controller) {
                controller->Release();
                if (it + 1 != mpStateEnd) {
                    std::memmove(it, it + 1, (mpStateEnd - (it + 1)) * sizeof(void*));
                }
                mpStateEnd = mpStateEnd - 1;
                Fn005e5620(state);
            } else {
                ++it;
            }
        }
        if (controller == mpLinked98) {
            Unknown_a95ac0* linked = static_cast<Unknown_a95ac0*>(mpLinked98);
            if (linked != 0) {
                mpLinked98 = 0;
                linked->Release();
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050ce60 score 131
bool cSC4Automaton::PostInit()
{
    if (mb3c) {
        if (mnGroupId == 0) {
            ScriptSys_a95ac0* system = gpB43cec_a95ac0->Fn48();
            SetNode_a95ac0* head = static_cast<SetNode_a95ac0*>(Fn0090cf54(0x14));
            head->mpParent = 0;
            head->mpLeft = head;
            head->mpRight = head;
            Set_a95ac0 set = { head, 0 };
            if (system != 0) {
                OccView_a95ac0* sub = reinterpret_cast<OccView_a95ac0*>(reinterpret_cast<char*>(this) + 4);
                if (sub->Slot24_a95ac0_4(&set)) {
                    for (SetNode_a95ac0* it = set.mpHead->mpLeft; it != set.mpHead; it = SetNext_a95ac0(it)) {
                        uint32_t id = it->mnValue;
                        if (mnGroupId != 0) {
                            cOccupantGroup_a95ac0* group = static_cast<cOccupantGroup_a95ac0*>(system->Fn06(id));
                            group->GetGroupHierarchyDepth();
                        }
                        mnGroupId = id;
                    }
                }
            }
            if (set.mnCount != 0) {
                set.Fn0046f820(set.mpHead->mpParent);
                set.mpHead->mpLeft = set.mpHead;
                set.mpHead->mpParent = 0;
                set.mpHead->mpRight = set.mpHead;
            }
            if (set.mpHead != 0) {
                Fn0090cf63(set.mpHead);
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050ef50 score 152
bool cSC4Automaton::Slot52_a953a8(uint32_t id, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, uint32_t n7)
{
    void* obj = OB_PTR(void, a2);
    float f3 = *reinterpret_cast<float*>(&a3);
    uint8_t flag = static_cast<uint8_t>(a4);
    void* a7 = OB_PTR(void, n7);
    bool result = false;
    if (id == 0 && obj == 0) {
        if (mpStateBegin != mpStateEnd) {
            AVT(this)->Slot51_a953a8(0, 0, f3, flag, a5, a6, a7);
            return true;
        }
        return result;
    }
    if (mpStateBegin != mpStateEnd) {
        if (static_cast<State_a95ac0*>(AVT(this)->Slot56_a953a8())->mnBehavior == id) {
            if (static_cast<State_a95ac0*>(AVT(this)->Slot56_a953a8())->mpObj8 == obj) {
                return false;
            }
        }
    }
    HandleExitState(static_cast<void*>(AVT(this)->Slot56_a953a8()));
    State_a95ac0* state = static_cast<State_a95ac0*>(CreateAutomataState(id));
    WordVec_a95ac0* stack = reinterpret_cast<WordVec_a95ac0*>(&mpStateBegin);
    if (stack->mpEnd != stack->mpCap) {
        if (stack->mpEnd != 0) {
            *reinterpret_cast<State_a95ac0**>(stack->mpEnd) = state;
        }
        stack->mpEnd = stack->mpEnd + 1;
    } else {
        stack->Fn0051ca60(stack->mpEnd, reinterpret_cast<uint32_t*>(&state), 1, 1);
    }
    state->mnBehavior = id;
    state->mpObj8 = obj;
    state->mf10 = f3;
    state->mb14 = flag;
    state->mn1c = a5;
    state->mn18 = a6;
    state->mp24 = a7;
    if (obj != 0) {
        static_cast<Unknown_a95ac0*>(obj)->AddRef();
    }
    state->mnDepth = (stack->mpEnd - stack->mpBegin) - 1;
    HandleEnterState(state);
    return true;
}
#endif

struct Anim_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Fn04(void*);
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Fn14(uint32_t);
};

// A 3-by-3 matrix of floats and the transform record the models take (flag bytes, matrix at +8, position at +0x30).
struct Matrix3_a95ac0 {
    float m[9];
};

struct Transform_a95ac0 {
    uint8_t mCount;
    uint8_t mFlags;
    uint8_t mPad2[2];
    Matrix3_a95ac0 mMatrix;
    float mPos[3];
    float mScale;
};

// STUB: 0x0080b830
void Fn0080b830(const void* pDirection, Matrix3_a95ac0* pOut);

// STUB: 0x007fede0
bool Fn007fede0(const void* pKey, void* pModelOut);

// GLOBAL: 0x00b21ba4
extern float gfB21ba4;

// The vector of resource keys at +0xc0 (12-byte elements).
struct KeyVec_a95ac0 {
    void* mpBegin;
    void* mpEnd;
    void* mpCap;
    // STUB: 0x0050da30
    void Fn0050da30(const void* pKey);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005094a0 score 106
void cSC4Automaton::PositionModelInstance(void* pBase)
{
    ModelVBase_a95ac0* base = static_cast<ModelVBase_a95ac0*>(pBase);
    Transform_a95ac0 transform;
    transform.mCount = 0;
    transform.mFlags = 0;
    for (int32_t i = 0; i < 9; ++i) {
        transform.mMatrix.m[i] = (i % 4 == 0) ? 1.0f : 0.0f;
    }
    transform.mPos[0] = 0.0f;
    transform.mPos[1] = 0.0f;
    transform.mPos[2] = 0.0f;
    transform.mScale = 1.0f;
    base->Fn09(&transform);
    Matrix3_a95ac0 rotation;
    for (int32_t i = 0; i < 9; ++i) {
        rotation.m[i] = gfB21ba4;
    }
    Fn0080b830(&mfVec58X, &rotation);
    transform.mPos[0] = mfPosX;
    transform.mPos[1] = mfPosY;
    transform.mPos[2] = mfPosZ;
    transform.mFlags = transform.mFlags | 1;
    transform.mCount = transform.mCount + 1;
    transform.mMatrix = rotation;
    transform.mFlags = transform.mFlags | 4;
    transform.mCount = transform.mCount + 1;
    base->Fn10(&transform);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050e4d0 score 94
void* cSC4Automaton::AddModelInstance(void* pKey)
{
    const Key_a95ac0* key = static_cast<const Key_a95ac0*>(pKey);
    ModelInst_a95ac0* model = 0;
    if (key->mnInstance != 0) {
        if (mnAnimKeyInstance == 0) {
            mnAnimKeyType = key->mnType;
            mnAnimKeyGroup = key->mnGroup;
            mnAnimKeyInstance = key->mnInstance;
            mn128 = key->mnInstance;
        }
        bool wasPlaced = ((Sub4Of_a95ac0(this)->mbFlags2f >> 1) & 1) != 0;
        if (wasPlaced) {
            PlaceInOccupantManager(false);
        }
        if (Fn007fede0(key, &model)) {
            Anim_a95ac0* anim = static_cast<Anim_a95ac0*>(model->Fn00());
            anim->Fn04(Sub4Of_a95ac0(this));
            anim->Fn14(1);
            int32_t zoom;
            int32_t rotation;
            gpB43dd8->GetZoomAndRotation(&zoom, &rotation);
            model->Fn08(zoom, rotation);
            ModelVBase_a95ac0* base = model;
            PositionModelInstance(base);
            WordVec_a95ac0* models = reinterpret_cast<WordVec_a95ac0*>(&mpModelsBegin);
            if (models->mpEnd != models->mpCap) {
                if (models->mpEnd != 0) {
                    *reinterpret_cast<ModelInst_a95ac0**>(models->mpEnd) = model;
                }
                models->mpEnd = models->mpEnd + 1;
            } else {
                models->Fn0051ca60(models->mpEnd, reinterpret_cast<uint32_t*>(&model), 1, 1);
            }
            reinterpret_cast<KeyVec_a95ac0*>(&mpPathBegin)->Fn0050da30(key);
        }
        if (wasPlaced) {
            PlaceInOccupantManager(true);
        }
        InitLighting();
    }
    return model;
}
#endif

struct ModelInst3_a95ac0 {
    virtual void* Fn00(uint32_t);
};

struct NameStr_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual const char* Fn05();
};

// A key-effect node of the group's hashtable: next link, then two strings (the effect and the registration point).
struct KeyEffect_a95ac0 {
    KeyEffect_a95ac0* mpNext;
    uint8_t mPad4[4];
    NameStr_a95ac0 mPointName;
    uint8_t mPadc[0x1c - 0xc];
    NameStr_a95ac0 mEffectName;
    uint8_t mPad20[4];
    char* mpEffectBegin;
    char* mpEffectEnd;
};

// The hashtable of key effects inside a group template (at +0x70; its element count sits at +0x80).
struct EffectTable_a95ac0 {
    // STUB: 0x004b0390
    void Fn004b0390(HIter_a95ac0* pOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00507f70 score 104
bool cSC4Automaton::PlaceInOccupantManager(bool on)
{
    bool result = false;
    uint8_t flags = Sub4Of_a95ac0(this)->mbFlags2f;
    uint8_t placed = (flags >> 1) & 1;
    if (placed != on) {
        if (gpB43dd0 != 0) {
            OccView_a95ac0* sub = reinterpret_cast<OccView_a95ac0*>(reinterpret_cast<char*>(this) + 4);
            if (placed) {
                for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
                    ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*it);
                    if (model != 0) {
                        gpB43dd0->Fn29(model->Fn00());
                    }
                }
                sub->Slot31_a95ac0_4(2);
                return true;
            }
            if (!(flags & 1)) {
                Slot70_a95ac0(true);
            }
            if (Sub4Of_a95ac0(this)->mbFlags2f & 1) {
                float opacity = reinterpret_cast<Ramp_a95ac0*>(reinterpret_cast<char*>(this) + 0x1b0)->Fn004fa960();
                bool ok = true;
                for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
                    if (!ok) {
                        return false;
                    }
                    ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*it);
                    if (model != 0) {
                        if (opacity < 1.0f) {
                            model->Fn18(1, opacity);
                        } else {
                            model->Fn18(0, 1.0f);
                        }
                        ok = gpB43dd0->Fn28(model->Fn00()) != 0;
                    }
                }
                if (ok) {
                    sub->Slot29_a95ac0_4(2);
                }
            }
            return false;
        }
        return result;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00508610 score 98
void cSC4Automaton::FinishMove(bool a, bool b)
{
    if (mpModelsBegin != mpModelsEnd) {
        ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*mpModelsBegin);
        ModelVBase_a95ac0* base = model;
        base->Fn08(&mfVec170X);
    }
    OccView_a95ac0* sub = reinterpret_cast<OccView_a95ac0*>(reinterpret_cast<char*>(this) + 4);
    if (sub->Slot32_a95ac0_4(4)) {
        uint8_t flags = Sub4Of_a95ac0(this)->mbFlags2f;
        if (flags & 2) {
            for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
                ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*it);
                if (model != 0) {
                    if (a) {
                        gpB43dd0->Fn30(model->Fn00());
                    } else if (b) {
                        gpB43dd0->Fn31(static_cast<ModelInst3_a95ac0*>(static_cast<void*>(model))->Fn00(3));
                    }
                }
            }
            if (Sub4Of_a95ac0(this)->mbFlags2f & 1) {
                gpB43d0c->Fn24(sub, 0);
            }
        } else {
            if (flags & 1) {
                gpB43d0c->Fn24(sub, 0);
            } else {
                Slot70_a95ac0(true);
            }
            if (Sub4Of_a95ac0(this)->mbFlags2f & 1) {
                PlaceInOccupantManager(true);
            }
        }
    }
    if (mf1c0 > 100.0f) {
        Slot102_a95ac0(9, 0);
        mf1c0 = 0.0f;
    }
}
#endif

#if 0  // blocked: the base declares Slot67_a953a8 as void (it returns the group pointer)
// BLOCKED: 0x0050d580 score 106
void cSC4Automaton::ApplyAutomataGroup()
{
    cOccupantGroup_a95ac0* group = static_cast<cOccupantGroup_a95ac0*>(AVT(this)->Slot67_a953a8());
    if (group != 0 && group->mnEffectCount80 != 0) {
        HIter_a95ac0 it;
        reinterpret_cast<EffectTable_a95ac0*>(reinterpret_cast<char*>(group) + 0x70)->Fn004b0390(&it);
        while (it.mpCur != 0) {
            KeyEffect_a95ac0* node = reinterpret_cast<KeyEffect_a95ac0*>(it.mpCur);
            if (node->mpEffectEnd != node->mpEffectBegin) {
                if (EmbeddedOf_a95ac0(this)->Fn09(&node->mEffectName, &node->mPointName) == 0) {
                    cRZString text;
                    text.Sprintf("Warning: Could not create effect named '%s' attached to reg. point named '%s' for automata group '%d'.\n", node->mPointName.Fn05(), node->mEffectName.Fn05(), group->mnId10);
                }
            }
            HNode_a95ac0* next = it.mpCur->mpNext;
            if (next == 0) {
                next = it.Fn0050bbe0();
            }
            it.mpCur = next;
        }
    }
}
#endif

struct Target11_a95ac0 {
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
    virtual void Fn11(void*);
};

struct SoundSvc_a95ac0 {
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
    virtual void Fn11(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
};

struct VehMgr_a95ac0 {
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
    virtual bool Fn13();
};

// STUB: 0x00913c9e
SoundSvc_a95ac0* Fn00913c9e();

// STUB: 0x004bb9e0
void Fn004bb9e0();

// GLOBAL: 0x00b43d44
extern VehMgr_a95ac0* gpB43d44;

#ifdef OB_DRAFTS
// CLOSE: 0x00508e10 score 84
bool cSC4Automaton::DoMagnetTick(float)
{
    if (AVT(this)->Slot31_a953a8(1)) {
        return false;
    }
    State_a95ac0* state = static_cast<State_a95ac0*>(AVT(this)->Slot56_a953a8());
    if (state->mpObj8 != 0) {
        Vec3_a95ac0 target = { gfB21ba4, gfB21ba4, gfB21ba4 };
        static_cast<Target11_a95ac0*>(state->mpObj8)->Fn11(&target);
        float dx = target.x - mfPosX;
        float dy = target.y - mfPosY;
        float dz = target.z - mfPosZ;
        float length = static_cast<float>(std::sqrt(static_cast<double>(dx * dx + dy * dy + dz * dz)));
        if (length > 0.0001f) {
            float scale = gfB09978 / length;
            float speed = reinterpret_cast<Ramp_a95ac0*>(reinterpret_cast<char*>(this) + 0x1a0)->Fn004fa960();
            Vec3_a95ac0 step;
            step.x = dx * scale * speed + mfPosX;
            step.y = dy * scale * speed + mfPosY;
            step.z = dz * scale * speed + mfPosZ;
            if (!AVT(this)->Slot31_a953a8(0x40000)) {
                step.y = gpB43cec_a95ac0->Fn40()->Fn18(step.x, step.z);
            }
            AVT(this)->Slot16_a953a8(&step, 0);
        }
    }
    UpdateAttraction();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050a130 score 34
void cSC4Automaton::UpdateActiveSound(float dt)
{
    if (Fn00913c9e() != 0) {
        uint32_t count = static_cast<uint32_t*>(mpVec1c8End) - static_cast<uint32_t*>(mpVec1c8Begin);
        if (count != 0) {
            mf1e0 = dt + mf1e0;
            if (mf1e0 > 100.0f) {
                mf1e0 = 0.0f;
                uint32_t index = gpB43dd8->mnZoom;
                if (index >= count) {
                    index = count - 1;
                }
                uint32_t sound = 0;
                if (mbActiveSound1dc && !gpB43d44->Fn13()) {
                    sound = static_cast<uint32_t*>(mpVec1c8Begin)[index];
                }
                if (mnSfxId1d4 != 0) {
                    if (sound != mnSfxKind1d8) {
                        Fn00913c9e()->Fn11(0x6a451908, mnSfxId1d4, 0, 0, 0);
                        mnSfxId1d4 = 0;
                        mnSfxKind1d8 = 0;
                    }
                }
                if (mnSfxId1d4 == 0) {
                    if (sound != 0) {
                        Fn004bb9e0();
                        mnSfxId1d4 = Fn004f7bb0();
                        mnSfxKind1d8 = sound;
                        Fn00913c9e()->Fn11(0xea451903, mnSfxKind1d8, mnSfxId1d4, 0, 0);
                    }
                }
                if (mnSfxId1d4 != 0) {
                    Vec3_a95ac0 where = { gfB21ba4, gfB21ba4, gfB21ba4 };
                    AVT(this)->Slot07_a953a8(&where);
                    SoundSvc_a95ac0* service = Fn00913c9e();
                    service->Fn11(0xca45190f, mnSfxId1d4, static_cast<int32_t>(where.x), static_cast<int32_t>(where.y), static_cast<int32_t>(where.z));
                }
            }
        }
    }
}
#endif

// The state records CreateAutomataState allocates (vtable at +0, the behavior id at +4); each kind has its own
// out-of-line constructor and size. STUB: 0x005e55e0 is the plain operator new they all use.
// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t size);

struct StateRec_a95ac0 {
    virtual void PadRec();
    uint32_t mnBehavior;
};

struct StateRecA_a95ac0 : StateRec_a95ac0 {
    uint8_t mData[0x34 - 8];
    // STUB: 0x00505290
    StateRecA_a95ac0();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecB_a95ac0 : StateRec_a95ac0 {
    uint8_t mData[0x40 - 8];
    // STUB: 0x00505bf0
    StateRecB_a95ac0();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecC_a95ac0 : StateRec_a95ac0 {
    uint8_t mData[0x40 - 8];
    // STUB: 0x00505c70
    StateRecC_a95ac0();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecD_a95ac0 : StateRec_a95ac0 {
    uint8_t mData[0x30 - 8];
    // STUB: 0x00505c40
    StateRecD_a95ac0();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecE_a95ac0 : StateRec_a95ac0 {
    uint8_t mData[0x274 - 8];
    // STUB: 0x00506370
    StateRecE_a95ac0();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecF_a95ac0 : StateRec_a95ac0 {
    uint8_t mData[0x58 - 8];
    // STUB: 0x00505ca0
    StateRecF_a95ac0();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecG_a95ac0 : StateRec_a95ac0 {
    uint8_t mData[0x34 - 8];
    // STUB: 0x00509a20
    StateRecG_a95ac0();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecH_a95ac0 : StateRec_a95ac0 {
    uint8_t mData[0x2c - 8];
    // STUB: 0x005052d0
    StateRecH_a95ac0();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecI_a95ac0 : StateRec_a95ac0 {
    uint8_t mData[0x44 - 8];
    // STUB: 0x00506330
    StateRecI_a95ac0();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecJ_a95ac0 : StateRec_a95ac0 {
    uint8_t mData[0x2c - 8];
    // STUB: 0x00506420
    StateRecJ_a95ac0();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// The generic 0x28-byte record: its constructor is inlined at the call site.
struct StateRecK_a95ac0 : StateRec_a95ac0 {
    uint32_t mn8;
    uint32_t mnc;
    uint32_t mn10;
    uint8_t mb14;
    uint32_t mn18;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
    StateRecK_a95ac0() : mn8(0), mnc(0), mn10(0), mb14(0), mn18(0), mn1c(0), mn20(0), mn24(0) { mnBehavior = 0; }
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050b7f0 score 18
void* cSC4Automaton::CreateAutomataState(uint32_t id)
{
    StateRec_a95ac0* state;
    switch (id) {
    case 8:
        state = new StateRecA_a95ac0;
        break;
    case 11:
        state = new StateRecB_a95ac0;
        break;
    case 14:
        state = new StateRecC_a95ac0;
        break;
    case 15:
        state = new StateRecD_a95ac0;
        break;
    case 16:
        state = new StateRecE_a95ac0;
        break;
    case 17:
        state = new StateRecF_a95ac0;
        break;
    case 19:
        state = new StateRecG_a95ac0;
        break;
    case 20:
        state = new StateRecH_a95ac0;
        break;
    case 21:
        state = new StateRecI_a95ac0;
        break;
    case 0x34:
        state = new StateRecJ_a95ac0;
        break;
    default:
        state = new StateRecK_a95ac0;
        break;
    }
    if (state != 0) {
        state->mnBehavior = id;
    }
    return state;
}
#endif

// An attraction record: id first, the chance at +8.
struct Item_a95ac0 {
    uint32_t mnId;
    uint8_t mPad4[4];
    float mf8;
};

struct Linked_a95ac0 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual uint32_t Fn06();
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
    virtual Item_a95ac0* Fn32(uint32_t, void*);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005096b0 score 104
void cSC4Automaton::UpdateAttraction()
{
    if (!AVT(this)->Slot31_a953a8(0x4000)) {
        AutoMgr_a95ac0* manager = gpB43cec_a95ac0->Fn47();
        Unknown_a95ac0* target = static_cast<Unknown_a95ac0*>(manager->Fn22(Sub4Of_a95ac0(this), &mnA4, &mn9c, &mnA0));
        if (target != 0) {
            target->AddRef();
        }
        Unknown_a95ac0* old = static_cast<Unknown_a95ac0*>(mpLinked98);
        if (target != old) {
            if (old != 0) {
                State_a95ac0* top = static_cast<State_a95ac0*>(AVT(this)->Slot56_a953a8());
                while (top != 0 && top->mpObj8 == mpLinked98) {
                    AVT(this)->Slot53_a953a8();
                    top = static_cast<State_a95ac0*>(AVT(this)->Slot56_a953a8());
                }
            }
            Unknown_a95ac0* previous = static_cast<Unknown_a95ac0*>(mpLinked98);
            if (target != previous) {
                if (target != 0) {
                    target->AddRef();
                }
                mpLinked98 = target;
                if (previous != 0) {
                    previous->Release();
                }
            }
        }
        Linked_a95ac0* current = static_cast<Linked_a95ac0*>(mpLinked98);
        if (current != 0) {
            Item_a95ac0* item = current->Fn32(mn9c, &mfPosX);
            if (item != 0) {
                float limit = item->mf8;
                double roll = gB21d78.Fn00913a29();
                if (!(limit < roll)) {
                    State_a95ac0* state = static_cast<State_a95ac0*>(AVT(this)->Slot56_a953a8());
                    bool push = true;
                    while (state != 0) {
                        if (state->mpObj8 != 0) {
                            Linked_a95ac0* linked = static_cast<Linked_a95ac0*>(mpLinked98);
                            if (static_cast<Linked_a95ac0*>(state->mpObj8)->Fn06() == linked->Fn06() && state->mnBehavior != item->mnId) {
                                AVT(this)->Slot53_a953a8();
                                state = static_cast<State_a95ac0*>(AVT(this)->Slot56_a953a8());
                                continue;
                            }
                        }
                        if (state->mp24 == item) {
                            push = false;
                        }
                        break;
                    }
                    if (push) {
                        AVT(this)->Slot55_a953a8(item, mpLinked98);
                    }
                }
            }
        }
        if (target != 0) {
            target->Release();
        }
    }
}
#endif

// The tint record the ghost model is given: flag byte at +0, colour at +4 (r, g, b), alpha-ish at +0x10.
struct Tint_a95ac0 {
    uint8_t mFlags;
    uint8_t mPad1[3];
    float mf4;
    float mf8;
    float mfc;
    float mf10;
    uint8_t mPad14[0x30];
};

// The small holder at +0xd0 the ghost is registered with.
struct GhostHolder_a95ac0 {
    void* mpValue;
    // STUB: 0x00513ff0
    void Fn00513ff0(void* value);
    // STUB: 0x008038d0
    bool Fn008038d0(void* value);
};

// STUB: 0x00803060
void* Fn00803060(void* pTemp);

// STUB: 0x008030a0
void Fn008030a0(void* pTemp);

#ifdef OB_DRAFTS
// CLOSE: 0x00514340 score 132
void cSC4Automaton::InitGhostModel()
{
    OccView_a95ac0* sub = reinterpret_cast<OccView_a95ac0*>(reinterpret_cast<char*>(this) + 4);
    if (sub->Slot07_a95ac0_4() != 0x496e5783 || sub->Slot07_a95ac0_4() != 0x897f7ec2) {
        if (mpPathBegin != mpPathEnd) {
            ModelInst_a95ac0* ghost = static_cast<ModelInst_a95ac0*>(mpGhost);
            if (ghost != 0) {
                mpGhost = 0;
                ModelVBase_a95ac0* base = ghost;
                base->Release();
            }
            ghost = static_cast<ModelInst_a95ac0*>(mpGhost);
            if (ghost != 0) {
                mpGhost = 0;
                ModelVBase_a95ac0* base = ghost;
                base->Release();
            }
            if (Fn007fede0(mpPathBegin, &mpGhost)) {
                ModelVBase_a95ac0* base = static_cast<ModelInst_a95ac0*>(mpGhost);
                Tint_a95ac0 tint;
                base->Fn15(&tint);
                tint.mFlags = tint.mFlags | 0x20;
                tint.mf10 = 0.5f;
                tint.mf4 = 0.6f;
                tint.mf8 = 1.0f;
                tint.mfc = 0.6f;
                ModelVBase_a95ac0* base2 = static_cast<ModelInst_a95ac0*>(mpGhost);
                base2->Fn16(&tint);
                Transform_a95ac0 transform;
                transform.mCount = 0;
                transform.mFlags = 0;
                for (int32_t i = 0; i < 9; ++i) {
                    transform.mMatrix.m[i] = (i % 4 == 0) ? 1.0f : 0.0f;
                }
                            transform.mPos[0] = 0.0f;
                transform.mPos[1] = 0.0f;
                transform.mPos[2] = 0.0f;
                transform.mScale = 1.0f;
                ModelVBase_a95ac0* first = static_cast<ModelInst_a95ac0*>(*mpModelsBegin);
                first->Fn09(&transform);
                ModelVBase_a95ac0* ghostBase = static_cast<ModelInst_a95ac0*>(mpGhost);
                ghostBase->Fn10(&transform);
                ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(mpGhost);
                gpB43dd0->Fn28(model->Fn00());
                uint8_t temp[0x30];
                GhostHolder_a95ac0* holder = reinterpret_cast<GhostHolder_a95ac0*>(reinterpret_cast<char*>(this) + 0xd0);
                holder->Fn00513ff0(Fn00803060(temp));
                Fn008030a0(temp);
                holder->Fn008038d0(static_cast<ModelInst_a95ac0*>(mpGhost)->Fn00());
            }
        }
    }
}
#endif

// The original's float-to-cell conversion: the scaled value is turned into an integer through the 1.5 * 2^23 bit trick,
// then corrected by one when it lands exactly on the next cell.
inline int32_t CellOf_a95ac0(float scaled)
{
    float t = (scaled - 0.5f) + 12582912.0f;
    int32_t cell = *reinterpret_cast<int32_t*>(&t) - 0x4b400000;
    if (static_cast<float>(cell + 1) == scaled) {
        cell = cell + 1;
    }
    return cell;
}

struct BoxSource_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn08(void*);
};

// What the first model reports about itself (slot 8 of the primary vtable): a box, of which the depth is used.
struct ModelBox_a95ac0 {
    float mf0;
    float mf4;
    float mf8;
    float mfc;
    float mf10;
    float mf14;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050e8b0 score 141
bool cSC4Automaton::LoadModels()
{
    WordVec_a95ac0* models = reinterpret_cast<WordVec_a95ac0*>(&mpModelsBegin);
    bool loadedAny = false;
    ModelInst_a95ac0* model = 0;
    if (models->mpBegin == models->mpEnd) {
        KeyVec_a95ac0* keys = reinterpret_cast<KeyVec_a95ac0*>(&mpPathBegin);
        if (keys->mpBegin == keys->mpEnd && mnAnimKeyInstance != 0) {
            keys->Fn0050da30(&mnAnimKeyType);
        }
        for (Key_a95ac0* key = static_cast<Key_a95ac0*>(keys->mpBegin); key != static_cast<Key_a95ac0*>(mpPathEnd); ++key) {
            Key_a95ac0 current = *key;
            if (!Fn007fede0(&current, &model)) {
                return false;
            }
            if (models->mpEnd != models->mpCap) {
                if (models->mpEnd != 0) {
                    *reinterpret_cast<ModelInst_a95ac0**>(models->mpEnd) = model;
                }
                models->mpEnd = models->mpEnd + 1;
            } else {
                models->Fn0051ca60(models->mpEnd, reinterpret_cast<uint32_t*>(&model), 1, 1);
            }
            ModelInst_a95ac0* inner = static_cast<ModelInst_a95ac0*>(model->Fn00());
            if (key == static_cast<Key_a95ac0*>(mpPathBegin)) {
                ModelBox_a95ac0 box = { 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f };
                mfLength = (box.mfc - box.mf4) * 0.5f;
                if (!(mfLength <= 32.0f)) {
                    mfLength = 32.0f;
                }
            }
            model->Fn18(1, 0.0f);
            PositionModelInstance(inner);
            Anim_a95ac0* anim = reinterpret_cast<Anim_a95ac0*>(inner);
            anim->Fn04(Sub4Of_a95ac0(this));
            anim->Fn14(3);
            int32_t zoom;
            int32_t rotation;
            gpB43dd8->GetZoomAndRotation(&zoom, &rotation);
            model->Fn08(zoom, rotation);
            loadedAny = true;
        }
        WordVec_a95ac0 ids = { 0, 0, 0 };
        if (Fn005ff510(OCCV(this)->Slot06_a95ac0_4(), 0xcc21420d, &ids) && ids.mpBegin != ids.mpEnd) {
            for (uint32_t* id = ids.mpBegin; id != ids.mpEnd; ++id) {
                if (*id > 0 && *id < 4) {
                    ModelInst_a95ac0* aux = 0;
                    LoadAuxiliaryModel(*id, &aux);
                    if (aux != 0) {
                        ModelVBase_a95ac0* base = aux;
                        base->Release();
                    }
                }
            }
        }
        if (ids.mpBegin != 0) {
            Fn0090cf63(ids.mpBegin);
        }
    }
    UpdateOpacity(0.0f);
    InitLighting();
    return loadedAny;
}
#endif

struct GhostProbe_a95ac0 {
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
    virtual bool Fn13();
};

struct VehMgrQ_a95ac0 {
    virtual bool Fn00(uint32_t iid, void* pOut);
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
    virtual bool Fn13();
};

// The state the ghost compares against: its cell at +0x26c / +0x270.
struct CellState_a95ac0 {
    uint8_t mPad[0x26c];
    int32_t mnCellA;
    int32_t mnCellB;
};

// The object the global at 0xb21d74 points to: the boat being placed sits at +0x30.
struct Placing_a95ac0 {
    uint8_t mPad[0x30];
    cSC4Automaton* mpBoat;
};

// GLOBAL: 0x00b09968
extern uint8_t gbB09968;

// GLOBAL: 0x00b21d74
extern Placing_a95ac0* gpB21d74;

// GLOBAL: 0x00b43ddc
extern void* gpLighting_a95ac0;

#ifdef OB_DRAFTS
// CLOSE: 0x0050afd0 score 241
void cSC4Automaton::UpdateGhostModel()
{
    OccView_a95ac0* sub = reinterpret_cast<OccView_a95ac0*>(reinterpret_cast<char*>(this) + 4);
    if (sub->Slot07_a95ac0_4() == 0x496e5783 && sub->Slot07_a95ac0_4() == 0x897f7ec2) {
        return;
    }
    if (gbB09968 == 0) {
        ShutdownGhostModel();
        return;
    }
    bool match = false;
    VehMgrQ_a95ac0* manager = reinterpret_cast<VehMgrQ_a95ac0*>(gpB43d44);
    if (manager->Fn13()) {
        if (mpGhost == 0 && mpModelsBegin != mpModelsEnd) {
            GhostProbe_a95ac0* probe = 0;
            manager->Fn00(0x098f9bf4, &probe);
            if (probe != 0) {
                if (gpB21d74 != 0) {
                    if (probe->Fn13()) {
                        if (gpB21d74->mpBoat != 0) {
                            CellState_a95ac0* other = OB_PTR(CellState_a95ac0, gpB21d74->mpBoat->Slot57_a953a8(0x10));
                            if (other != 0) {
                                int32_t cellA;
                                int32_t cellB;
                                gpB43d0c->Fn17(mfPosX, mfPosZ, &cellA, &cellB);
                                if (other->mnCellA == cellA && other->mnCellB == cellB) {
                                    match = true;
                                }
                            }
                        }
                    }
                }
                probe->Release();
            }
            if (match) {
                if (mpGhost == 0) {
                    InitGhostModel();
                    return;
                }
            }
        }
    }
    if (mpGhost != 0 && mpModelsBegin != mpModelsEnd) {
        ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*mpModelsBegin);
        Transform_a95ac0 transform;
        transform.mCount = 0;
        transform.mFlags = 0;
        for (int32_t i = 0; i < 9; ++i) {
            transform.mMatrix.m[i] = (i % 4 == 0) ? 1.0f : 0.0f;
        }
        transform.mPos[0] = 0.0f;
        transform.mPos[1] = 0.0f;
        transform.mPos[2] = 0.0f;
        transform.mScale = 1.0f;
        ModelVBase_a95ac0* base = model;
        base->Fn09(&transform);
        ModelBox_a95ac0 box;
        reinterpret_cast<BoxSource_a95ac0*>(model->Fn00())->Fn08(&box);
        float shift = (box.mf10 - box.mf4) * 1.5f;
        transform.mPos[0] = transform.mPos[0] - shift * gpB43dd8->mnZoom;
        ModelVBase_a95ac0* ghostBase = static_cast<ModelInst_a95ac0*>(mpGhost);
        ghostBase->Fn10(&transform);
        gpB43dd0->Fn30(static_cast<ModelInst_a95ac0*>(mpGhost)->Fn00());
        if (mpLight0xd0 != 0) {
            reinterpret_cast<Light_a95ac0*>(&mpLight0xd0)->Fn00803e10(gpLighting_a95ac0, 0);
        }
    }
}
#endif

struct LotMgr_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void* Fn06(int32_t, int32_t, int32_t);
};

// GLOBAL: 0x00b43d08
extern LotMgr_a95ac0* gpB43d08;

// The static debug text (a cRZString at 0xb22760, its std::string part at 0xb22764); string members are out of line.
struct DbgString_a95ac0 {
    // STUB: 0x0040ebc0
    void* Append(const char* first, const char* last, const uint8_t* tag);
    // STUB: 0x00410f00
    void* AppendText(const char* text);
    // STUB: 0x00408a70
    void* Assign(const void* first, const void* last, const uint8_t* tag);
};

// A temporary string built from a character range.
struct TempString_a95ac0 {
    void* mpBegin;
    void* mpEnd;
    void* mpCap;
    // STUB: 0x00407fa0
    void Build(const char* first, const char* last, const uint8_t* tag);
};

// GLOBAL: 0x00b22764
extern DbgString_a95ac0 gDbgString_a95ac0;

// GLOBAL: 0x00b22760
extern uint8_t gDbgText_a95ac0[];

#ifdef OB_DRAFTS
// CLOSE: 0x00511a90 score 183
void* cSC4Automaton::GetDebugFlagsText()
{
    uint8_t tag;
    TempString_a95ac0 temp = { 0, 0, 0 };
    temp.Build("", "", &tag);
    gDbgString_a95ac0.Assign(temp.mpBegin, temp.mpEnd, &tag);
    if (temp.mpBegin != 0) {
        Fn0090cf63(temp.mpBegin);
    }
    if (AVT(this)->Slot31_a953a8(0x1)) {
        const char* text = " (remove)";
        gDbgString_a95ac0.Append(text, text + 9, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x2)) {
        const char* text = " (self control)";
        gDbgString_a95ac0.Append(text, text + 15, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x4)) {
        const char* text = " (reached dest)";
        gDbgString_a95ac0.Append(text, text + 15, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x8)) {
        const char* text = " (collide)";
        gDbgString_a95ac0.Append(text, text + 10, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x10)) {
        const char* text = " (stop light)";
        gDbgString_a95ac0.Append(text, text + 13, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x20)) {
        const char* text = " (stopped)";
        gDbgString_a95ac0.Append(text, text + 10, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x40)) {
        const char* text = " (special route)";
        gDbgString_a95ac0.Append(text, text + 16, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x80)) {
        const char* text = " (Emergency!)";
        gDbgString_a95ac0.Append(text, text + 13, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x100)) {
        const char* text = " (idle)";
        gDbgString_a95ac0.Append(text, text + 7, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x200)) {
        const char* text = " (repathing)";
        gDbgString_a95ac0.Append(text, text + 12, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x400)) {
        const char* text = " (teleporting)";
        gDbgString_a95ac0.Append(text, text + 14, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x800)) {
        const char* text = " (ignore lights)";
        gDbgString_a95ac0.Append(text, text + 16, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x1000)) {
        const char* text = " (ignore speed limit)";
        gDbgString_a95ac0.Append(text, text + 21, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x2000)) {
        const char* text = " (ignore paths)";
        gDbgString_a95ac0.Append(text, text + 15, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x4000)) {
        const char* text = " (ignore attractors)";
        gDbgString_a95ac0.Append(text, text + 20, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x20000)) {
        const char* text = " (ignore roads)";
        gDbgString_a95ac0.Append(text, text + 15, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x400000)) {
        const char* text = " (avoid lots)";
        gDbgString_a95ac0.Append(text, text + 13, &tag);
    }
    if (AVT(this)->Slot31_a953a8(0x800000)) {
        const char* text = " (avoid roads)";
        gDbgString_a95ac0.Append(text, text + 14, &tag);
    }
    if (gpB43d08 != 0) {
        int32_t cellX = CellOf_a95ac0(mfPosX * 0.0625f);
        int32_t cellZ = CellOf_a95ac0(mfPosZ * 0.0625f);
        if (cellX >= 0 && cellZ >= 0 && cellX < gpB43cec_a95ac0->Fn93() && cellZ < gpB43cec_a95ac0->Fn94()) {
            if (gpB43d08->Fn06(cellX, cellZ, 0) != 0) {
                gDbgString_a95ac0.AppendText(" [ON LOT]");
            }
        }
    }
    return gDbgText_a95ac0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00505300 score 14
float cOccupantGroup_a95ac0::Fn00505300()
{
    cOccupantGroup_a95ac0* group = this;
    for (;;) {
        if (group->mf5c > 0.0f) {
            return group->mf5c;
        }
        group = group->mpParent;
        if (group == 0) {
            return 0.0f;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051d970 score 14
bool GroupMgr_a95ac0::Fn0051d970(Str_a95ac0* name, uint32_t* pOut)
{
    bool found = false;
    GroupNode_a95ac0* node = mTable.Find(name);
    if (node != 0) {
        *pOut = node->mnValue;
        return true;
    }
    return found;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050bbe0 score 45
HNode_a95ac0* HIter_a95ac0::Fn0050bbe0()
{
    HTable_a95ac0* table = mpTable;
    uint32_t size = table->mpEnd - table->mpBegin;
    uint32_t index = mpCur->mnKey % size;
    size = table->mpEnd - table->mpBegin;
    HNode_a95ac0* result = 0;
    for (++index; index < size; ++index) {
        result = mpTable->mpBegin[index];
        if (result != 0) {
            break;
        }
    }
    return result;
}
#endif


// ---- batch 2: functions that are not shared with the watercraft ----

// The first 13 spans of a 26-float table: a flag per span whose width lies strictly between 0 and 250.
#ifdef OB_DRAFTS
// CLOSE: 0x00505730 score 7
void OB_STDCALL Fn00505730(void* pTable)
{
    const float* f = reinterpret_cast<const float*>(static_cast<char*>(pTable) + 0x7c);
    uint8_t* flags = static_cast<uint8_t*>(pTable) + 0xe4;
    int n = 13;
    do {
        float d = f[13] - f[0];
        *flags = (0.0f < d && d < 250.0f);
        ++f;
        ++flags;
        --n;
    } while (n != 0);
}
#endif

// A message: slot 4 = type, slot 10 = object, slot 14 = count.
struct Msg5_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual uint32_t Fn04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void* Fn10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual uint32_t Fn14();
};

// The record a controller lookup hands back: the object pointer at +0x28.
struct Ctl_a95ac0 {
    uint8_t mPad[0x28];
    Unknown_a95ac0* mpObj28;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00507cd0 score 24
bool cSC4Automaton::Slot03_aaaa9c(void* pMessage)
{
    bool result = false;
    Msg5_a95ac0* msg = static_cast<Msg5_a95ac0*>(pMessage);
    if (msg->Fn04() == 0x9d92fc3) {
        uint32_t n = msg->Fn14();
        if (n >= 2 && n <= 3) {
            Ctl_a95ac0* ctl = static_cast<Ctl_a95ac0*>(AVT(this)->Slot57_a953a8(0x34));
            if (ctl != 0) {
                void* obj = msg->Fn10();
                if (ctl->mpObj28 == obj) {
                    if (ctl->mpObj28 != 0) {
                        Unknown_a95ac0* old = ctl->mpObj28;
                        ctl->mpObj28 = 0;
                        old->Release();
                    }
                    AVT(this)->Slot53_a953a8();
                }
            }
            return true;
        }
    }
    return result;
}
#endif

// FUNCTION: 0x005101d0
bool cSC4Automaton::Slot03_a953a8()
{
    OccView_a95ac0* occ = OCCV(this);
    if (!occ->Slot05_a95ac0_4()) {
        bool ok = LoadModels();
        if (ok) {
            InitEffectsList();
        }
        cSC4Occupant::Slot03_a953a8();
        return ok;
    }
    return true;
}

// FUNCTION: 0x0050f0a0
void* cSC4Automaton::GetDebugExtraText()
{
    static cRZString extraString;
    extraString.Sprintf("State: %d  ", AVT(this)->Slot59_a953a8());
    return &extraString;
}

// A state record as the exit handler sees it.
struct Obj8_a95ac0 {
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
    virtual bool Fn28(void* automaton, uint32_t id, float dt);
    virtual void Pad29();
    virtual bool Fn30(void* automaton, uint32_t id);
};

struct StateEx_a95ac0 {
    virtual void Fn00(void* automaton);
    uint32_t mnId;
    Obj8_a95ac0* mpObj8;
    uint32_t mn0c;
    float mf10;
    uint8_t mb14;
    uint8_t mPad15[3];
    uint32_t mn18;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
    ModelInst_a95ac0* mpModel28;
    uint8_t mPad2c[0x205 - 0x2c];
    uint8_t mbEffects205[13];
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050e3f0 score 46
bool cSC4Automaton::HandleExitState(void* pState)
{
    StateEx_a95ac0* s = static_cast<StateEx_a95ac0*>(pState);
    if (s == 0) {
        return false;
    }
    switch (s->mnId) {
    case 0x13:
        if (s->mpModel28 != 0) {
            RemoveModelInstance(s->mpModel28);
            ModelInst_a95ac0* model = s->mpModel28;
            if (model != 0) {
                s->mpModel28 = 0;
                ModelVBase_a95ac0& base = *model;
                base.Release();
            }
        }
        break;
    case 0x10:
        std::memset(s->mbEffects205, 0, sizeof(s->mbEffects205));
        Fn0050d870();
        s->Fn00(this);
        break;
    case 0x14:
        s->Fn00(this);
        break;
    default:
        break;
    }
    if (s->mn18 != 0) {
        AVT(this)->Slot62_a953a8(s->mn18);
    }
    mnAutomataFlags = (mnAutomataFlags & 0x600c001) | s->mn20;
    Slot102_a95ac0(0xd, s->mnId);
    if (s->mpObj8 != 0) {
        return s->mpObj8->Fn30(this, s->mnId);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050ebb0 score 13
void cSC4Automaton::InitEffectsList()
{
    if (mpModelsBegin != mpModelsEnd) {
        ModelInst_a95ac0* model = static_cast<ModelInst_a95ac0*>(*mpModelsBegin);
        ModelVBase_a95ac0* base = model ? static_cast<ModelVBase_a95ac0*>(model) : 0;
        Embedded_a95ac0* e = EmbeddedOf_a95ac0(this);
        e->Fn02(base);
        e->Pad00();
        e->Fn04(&mfPosX, &mfVec58X, mf94);
        Fn0050d6a0();
    }
}
#endif

// ---- batch 3 ----

// The state of the player-drive behaviour: 13 float timers at +0x7c and the command tables behind them.
struct DriveState3_a95ac0 {
    uint8_t mPad0[0x7c];
    float mf7c[13];
    uint8_t mPadB0[0x26c - 0xb0];
    int32_t mn26c;
    int32_t mn270;
};

// The audio/event service: slot 5 and slot 6 take an event id.
struct Aems_a95ac0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05(uint32_t);
    virtual void Fn06(uint32_t);
};

// STUB: 0x00602640
Aems_a95ac0* Fn00602640();

// The player-drive state seen by the command translator.
struct DriveCmd_a95ac0 {
    uint8_t mPad0[0x7c];
    uint32_t mn7c[13];
    uint32_t mnB0[13];
    uint8_t mbE4[0x14];
    uint32_t mnPad[0x128 / 4 - 0x7c / 4 - 26 - 5];
    int32_t mnCmd[13];
    int32_t mnLimit[13];
    float mfWait[13];
    float mfTimer[13];
    uint8_t mbFlag[13];
};

#ifdef OB_DRAFTS
// CLOSE: 0x00508c50 score 9
bool cSC4Automaton::DoPlayerDriveTick(float dt)
{
    if (AVT(this)->Slot31_a953a8(1)) {
        return false;
    }
    DriveState3_a95ac0* ds = static_cast<DriveState3_a95ac0*>(AVT(this)->Slot56_a953a8());
    float* p = ds->mf7c;
    int n = 13;
    do {
        if (!(*p < 0.0f)) {
            if (3.4028235e+38f - dt > *p) {
                *p = dt + *p;
            } else {
                *p = 3.4028235e+38f;
            }
        }
        ++p;
        --n;
    } while (n != 0);
    TranslatePlayerDriveCommands(ds, dt);
    gpB43d0c->Fn17(mfPosX, mfPosZ, &ds->mn26c, &ds->mn270);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00509070 score 30
bool cSC4Automaton::TranslatePlayerDriveCommands(void* pState, float dt)
{
    Fn00505730(pState);
    DriveCmd_a95ac0* ds = static_cast<DriveCmd_a95ac0*>(pState);
    for (int i = 0; i < 13; ++i) {
        int32_t c = ds->mnCmd[i];
        ds->mnB0[i] = ds->mn7c[i];
        if (static_cast<float>(c) != -1.0f && ds->mnLimit[i] >= c) {
            ds->mbFlag[i] = 0;
            if (ds->mn7c[i] != 0xbf800000) {
                Fn00602640()->Fn06(0x14);
                Fn00602640()->Fn05(0x14);
            }
        } else if (ds->mbFlag[i] == 0) {
            if (ds->mfTimer[i] < ds->mfWait[i]) {
                ds->mfTimer[i] = dt + ds->mfTimer[i];
            } else {
                ds->mbFlag[i] = 1;
                ds->mfTimer[i] = 0;
            }
        }
    }
    return true;
}
#endif

// ---- batch 4 ----

// The top state as the tick sees it: a countdown at +0x10, the behaviour at +0x8.
struct TickState_a95ac0 {
    virtual void Fn00(void* automaton);
    uint32_t mnId;
    Obj8_a95ac0* mpObj8;
    uint32_t mn0c;
    float mfTimer;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00508aa0 score 145
bool cSC4Automaton::DoStateTick(float dt)
{
    bool result = false;
    if (mpStateBegin == mpStateEnd) {
        return result;
    }
    TickState_a95ac0* s = static_cast<TickState_a95ac0*>(mpStateEnd[-1]);
    if (0.0f < s->mfTimer) {
        s->mfTimer = s->mfTimer - dt;
        if (s->mfTimer < 0.0f) {
            AVT(this)->Slot53_a953a8();
            if (mpStateBegin == mpStateEnd) {
                return true;
            }
            s = static_cast<TickState_a95ac0*>(mpStateEnd[-1]);
        }
    }
    if (s->mpObj8 != 0) {
        result = s->mpObj8->Fn28(this, s->mnId, dt);
        if (result) {
            return result;
        }
    }
    switch (s->mnId) {
    case 1:
        if (!GetMarkedForRemove()) {
            AVT(this)->Slot13_a953a8(0);
        }
        return true;
    case 7:
        return DoIdleTick(dt);
    case 10:
        return DoScriptedTick(dt);
    case 0xb:
        return DoRandomWalkTick(dt);
    case 0xf:
        return DoPlopJumpTick(dt);
    case 0x10:
        return DoPlayerDriveTick(dt);
    case 0x12:
        return DoMagnetTick(dt);
    case 0x13:
        return DoAttachAnimTick(dt);
    case 0x14:
        return DoCollideTick(dt);
    default:
        break;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050b400 score 118
bool cSC4Automaton::RemoveModelInstance(void* pModel)
{
    if (mpModelsBegin != mpModelsEnd) {
        ModelInst_a95ac0* first = static_cast<ModelInst_a95ac0*>(*mpModelsBegin);
        ModelVBase_a95ac0* firstBase = first ? static_cast<ModelVBase_a95ac0*>(first) : 0;
        Embedded_a95ac0* e = EmbeddedOf_a95ac0(this);
        if (e->Fn03() == firstBase) {
            e->Fn02(0);
        }
    }
    bool placed = ((Sub4Of_a95ac0(this)->mbFlags2f >> 1) & 1) != 0;
    if (placed && mpModelsBegin != mpModelsEnd) {
        PlaceInOccupantManager(0);
    }
    void** it = mpModelsBegin;
    while (it != mpModelsEnd) {
        ModelInst_a95ac0* m = static_cast<ModelInst_a95ac0*>(*it);
        if (m == pModel) {
            std::memmove(it, it + 1, (mpModelsEnd - (it + 1)) * sizeof(void*));
            mpModelsEnd = mpModelsEnd - 1;
            ModelVBase_a95ac0* base = m ? static_cast<ModelVBase_a95ac0*>(m) : 0;
            if (mpLight12c == base) {
                reinterpret_cast<Light_a95ac0*>(&mpLight12c)->Fn008038d0(0);
            }
            base->Release();
            break;
        }
        ++it;
    }
    if (placed && mpModelsBegin != mpModelsEnd) {
        PlaceInOccupantManager(1);
    }
    InitLighting();
    return false;
}
#endif

struct ListHead_a95ac0 {
    // STUB: 0x00473ec0
    void Fn00473ec0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050ba50 score 39
bool cSC4Automaton::Slot04_a953a8()
{
    AVT(this)->Slot69_a953a8();
    Embedded_a95ac0* e = EmbeddedOf_a95ac0(this);
    e->Fn07(1);
    e->Fn02(0);
    OccView_a95ac0* occ = OCCV(this);
    if (occ->Slot05_a95ac0_4()) {
        HandleExitState(static_cast<void*>(AVT(this)->Slot56_a953a8()));
        ClearStateStack();
        if (mpLeader != 0) {
            Unknown_a95ac0* leader = static_cast<Unknown_a95ac0*>(mpLeader);
            mpLeader = 0;
            leader->Release();
        }
        if (Sub4Of_a95ac0(this)->mbFlags2f & 1) {
            Slot70_a95ac0(false);
        }
        if (Sub4Of_a95ac0(this)->mbFlags2f & 2) {
            PlaceInOccupantManager(0);
        }
        ShutdownGhostModel();
        UnloadModels();
        ListNode_a95ac0* head = static_cast<ListNode_a95ac0*>(mpCallbacks);
        for (ListNode_a95ac0* node = head->mpNext; node != head; node = node->mpNext) {
            Unknown_a95ac0* value = node->mpValue;
            if (value != 0) {
                node->mpValue = 0;
                value->Release();
            }
        }
        reinterpret_cast<ListHead_a95ac0*>(mpCallbacks)->Fn00473ec0();
        if (mpLinked98 != 0) {
            Unknown_a95ac0* linked = static_cast<Unknown_a95ac0*>(mpLinked98);
            mpLinked98 = 0;
            linked->Release();
        }
        mnAutomataFlags = 0;
        mfLength = 0;
        field88 = 0;
        if (mnSfxId1d4 != 0) {
            Fn00913c9e()->Fn11(0x6a451908, mnSfxId1d4, 0, 0, 0);
            mnSfxId1d4 = 0;
        }
    }
    cSC4Occupant::Slot04_a953a8();
    return true;
}
#endif
