#include <cstddef>
#include <cstring>

#include "classes/cSC4CitySituationManager.h"
#include "game/Globals.h"

// A field of this object by its offset (the class header has the bytes unnamed).
#define FLD_a97e58(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

// GLOBAL: 0x00b21d34
extern uint8_t gB21d34;

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);
// STUB: 0x009133da
void* Fn009133da_a97e58(uint32_t size);
// STUB: 0x0090cf63
void Fn0090cf63(void* p);

struct OB_NOVTABLE Unknown_a97e58 {
    virtual bool QueryInterface(uint32_t id, void** out) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
};

// An automaton as the situation manager uses it.
struct OB_NOVTABLE Automaton_a97e58 {
    virtual bool QueryInterface_a97e58(uint32_t id, void** out) = 0;
    virtual uint32_t AddRef_a97e58() = 0;
    virtual uint32_t Release_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual Automaton_a97e58* GetOwner_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual void Pad07_a97e58() = 0;
    virtual void Pad08_a97e58() = 0;
    virtual void Pad09_a97e58() = 0;
    virtual void Pad10_a97e58() = 0;
    virtual void Pad11_a97e58() = 0;
    virtual void Pad12_a97e58() = 0;
    virtual void Pad13_a97e58() = 0;
    virtual void Pad14_a97e58() = 0;
    virtual void Pad15_a97e58() = 0;
    virtual void Pad16_a97e58() = 0;
    virtual void Pad17_a97e58() = 0;
    virtual void Pad18_a97e58() = 0;
    virtual void Pad19_a97e58() = 0;
    virtual void Pad20_a97e58() = 0;
    virtual void Pad21_a97e58() = 0;
    virtual void Pad22_a97e58() = 0;
    virtual void SetGroup_a97e58(uint32_t group) = 0;
    virtual void Pad24_a97e58() = 0;
    virtual void Pad25_a97e58() = 0;
    virtual void Pad26_a97e58() = 0;
    virtual void Pad27_a97e58() = 0;
    virtual void Pad28_a97e58() = 0;
    virtual void Pad29_a97e58() = 0;
    virtual void SetFlag_a97e58(uint32_t flag, uint32_t on) = 0;
    virtual bool HasFlag_a97e58(uint32_t flag) = 0;
    virtual void Pad32_a97e58() = 0;
    virtual void Pad33_a97e58() = 0;
    virtual void Pad34_a97e58() = 0;
    virtual void Pad35_a97e58() = 0;
    virtual void Pad36_a97e58() = 0;
    virtual void Pad37_a97e58() = 0;
    virtual void Pad38_a97e58() = 0;
    virtual void Attach_a97e58(void* listener) = 0;
    virtual void Detach_a97e58(void* listener) = 0;
    virtual void Pad41_a97e58() = 0;
    virtual void Pad42_a97e58() = 0;
    virtual void Pad43_a97e58() = 0;
    virtual void Pad44_a97e58() = 0;
    virtual void Pad45_a97e58() = 0;
    virtual void Pad46_a97e58() = 0;
    virtual void Pad47_a97e58() = 0;
    virtual void Pad48_a97e58() = 0;
    virtual void Pad49_a97e58() = 0;
    virtual void Pad50_a97e58() = 0;
    virtual void Pad51_a97e58() = 0;
    virtual void Pad52_a97e58() = 0;
    virtual void Pad53_a97e58() = 0;
    virtual void Pad54_a97e58() = 0;
    virtual void Pad55_a97e58() = 0;
    virtual void Pad56_a97e58() = 0;
    virtual void Pad57_a97e58() = 0;
    virtual void Pad58_a97e58() = 0;
    virtual int32_t GetType_a97e58() = 0;
    virtual void Pad60_a97e58() = 0;
    virtual void Slot61_a97e58(uint32_t value) = 0;
    virtual void Pad62_a97e58() = 0;
    virtual void Pad63_a97e58() = 0;
    virtual void Pad64_a97e58() = 0;
    virtual void Pad65_a97e58() = 0;
    virtual void Pad66_a97e58() = 0;
    virtual void Pad67_a97e58() = 0;
    virtual void Slot68_a97e58() = 0;
};

// A list head: the first word points at the sentinel node.
struct ListNode_a97e58 {
    ListNode_a97e58* mpNext;
    ListNode_a97e58* mpPrev;
};

struct List_a97e58 {
    ListNode_a97e58* mpHead;
    void Init_a97e58();
};

struct DispatchVehicleView_a97e58 {
    // STUB: 0x0046d3a0
    void ShowAllIndicators(uint32_t type, uint32_t visible);
    // STUB: 0x0046efb0
    void Fn0046efb0(uint32_t item, uint32_t flag);
    // STUB: 0x0046b4e0
    void SetIndicatorMax(uint32_t type, uint32_t max);
};

// The situation advice object as the manager calls it.
struct OB_NOVTABLE Advice_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual uint32_t GetId_a97e58() = 0;
    virtual int32_t GetKind_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual void Pad07_a97e58() = 0;
    virtual void Pad08_a97e58() = 0;
    virtual void Pad09_a97e58() = 0;
    virtual void Pad10_a97e58() = 0;
    virtual float GetTimeLimit_a97e58() = 0;
    virtual void Pad12_a97e58() = 0;
    virtual void Pad13_a97e58() = 0;
    virtual void Pad14_a97e58() = 0;
    virtual bool HasFlag_a97e58(uint32_t flag) = 0;
    virtual void* GetTargetList_a97e58() = 0;
    virtual bool HasTargetList_a97e58() = 0;
    virtual void Pad18_a97e58() = 0;
    virtual void Pad19_a97e58() = 0;
    virtual void Pad20_a97e58() = 0;
    virtual void Pad21_a97e58() = 0;
    virtual void Pad22_a97e58() = 0;
    virtual void Pad23_a97e58() = 0;
    virtual void Pad24_a97e58() = 0;
    virtual void Pad25_a97e58() = 0;
    virtual void Pad26_a97e58() = 0;
    virtual void Pad27_a97e58() = 0;
    virtual void Pad28_a97e58() = 0;
    virtual void Pad29_a97e58() = 0;
    virtual void Pad30_a97e58() = 0;
    virtual void Pad31_a97e58() = 0;
    virtual void Pad32_a97e58() = 0;
    virtual void Pad33_a97e58() = 0;
    virtual void Pad34_a97e58() = 0;
    virtual void Pad35_a97e58() = 0;
    virtual void Pad36_a97e58() = 0;
    virtual void Pad37_a97e58() = 0;
    virtual void Pad38_a97e58() = 0;
    virtual void Pad39_a97e58() = 0;
    virtual void Pad40_a97e58() = 0;
    virtual void Pad41_a97e58() = 0;
    virtual void Pad42_a97e58() = 0;
    virtual void Pad43_a97e58() = 0;
    virtual void Pad44_a97e58() = 0;
    virtual void Pad45_a97e58() = 0;
    virtual void GetAura1_a97e58(void* a, void* b) = 0;
    virtual void Pad47_a97e58() = 0;
    virtual void GetMoney1_a97e58(void* out) = 0;
    virtual void GetAura2_a97e58(void* a, void* b) = 0;
    virtual void Pad50_a97e58() = 0;
    virtual void GetMoney2_a97e58(void* out) = 0;
    virtual void Pad52_a97e58() = 0;
    virtual void Pad53_a97e58() = 0;
    virtual void Pad54_a97e58() = 0;
    virtual void Pad55_a97e58() = 0;
    virtual void Pad56_a97e58() = 0;
    virtual void Pad57_a97e58() = 0;
    virtual void Pad58_a97e58() = 0;
    virtual void Pad59_a97e58() = 0;
    virtual void Pad60_a97e58() = 0;
    virtual void Pad61_a97e58() = 0;
    virtual void Pad62_a97e58() = 0;
    virtual void Pad63_a97e58() = 0;
    virtual void Pad64_a97e58() = 0;
    virtual void Pad65_a97e58() = 0;
    virtual void Pad66_a97e58() = 0;
    virtual void Pad67_a97e58() = 0;
    virtual void Slot68_a97e58() = 0;
};

// FUNCTION: 0x005245c0
uint8_t cSC4CitySituationManager::GetMaxCSI()
{
    return gB21d34;
}

// FUNCTION: 0x00524750
uint32_t cSC4CitySituationManager::AddRef()
{
    return ++FLD_a97e58(uint32_t, 0x18);
}

// FUNCTION: 0x00527570
float cSC4CitySituationManager::GetCurrentTimeRemainingSeconds()
{
    return GetCurrentTimeLimitSeconds() - FLD_a97e58(float, 0xa8c);
}

#ifdef OB_DRAFTS
// CLOSE: 0x005245d0 score 3
bool cSC4CitySituationManager::HandleTuningParametersChanged()
{
    SetMaxCSI(gB21d34);
    return true;
}
#endif

// FUNCTION: 0x00527530
uint32_t cSC4CitySituationManager::GetNumTargetsRemaining()
{
    uint32_t total = GetNumTargets();
    return total - GetCurrentTargetIndex();
}

// FUNCTION: 0x00527300
void List_a97e58::Init_a97e58()
{
    mpHead = 0;
    ListNode_a97e58* node = static_cast<ListNode_a97e58*>(Fn0090cf54(0x14));
    node->mpNext = node;
    node->mpPrev = node;
    mpHead = node;
}

// FUNCTION: 0x00527580
uint32_t cSC4CitySituationManager::CountdownIsInProgress()
{
    return FLD_a97e58(float, 0xa90) > 0.0f;
}

// FUNCTION: 0x00524c20
void cSC4CitySituationManager::SetCSIVisible(uint32_t visible)
{
    FLD_a97e58(uint8_t, 0x9f0) = static_cast<uint8_t>(visible);
    DispatchVehicleView_a97e58* view = FLD_a97e58(DispatchVehicleView_a97e58*, 0xa2c);
    if (view) {
        view->ShowAllIndicators(4, visible);
    }
}

// FUNCTION: 0x00524cf0
uint32_t cSC4CitySituationManager::HandleTimeLimitReached()
{
    uint32_t result = FLD_a97e58(uint32_t, 0xa48);
    if (FLD_a97e58(uint32_t, 0x9f4)) {
        result = 2;
    }
    HandleStatusChanged(result);
    return result;
}

// FUNCTION: 0x00524bf0
void cSC4CitySituationManager::SetMaxCSI(uint32_t max)
{
    gB21d34 = static_cast<uint8_t>(max);
    DispatchVehicleView_a97e58* view = FLD_a97e58(DispatchVehicleView_a97e58*, 0xa2c);
    if (view) {
        view->SetIndicatorMax(4, static_cast<uint8_t>(max));
    }
}

// FUNCTION: 0x00524cc0
uint32_t cSC4CitySituationManager::HandleActiveAutoRemoved()
{
    uint32_t result = FLD_a97e58(uint32_t, 0xa48);
    if (FLD_a97e58(uint32_t, 0x9f4) && result == 3) {
        result = 2;
    }
    HandleStatusChanged(result);
    return result;
}

// FUNCTION: 0x00524df0
void cSC4CitySituationManager::Fn00524df0(uint32_t value)
{
    DoMessage(0);
    if (value == FLD_a97e58(uint32_t, 0x9f4)) {
        EndSituation();
    }
}

// FUNCTION: 0x00525520
unsigned int cSC4CitySituationManager::Release()
{
    if (FLD_a97e58(uint32_t, 0x18) > 1) {
        return --FLD_a97e58(uint32_t, 0x18);
    }
    Shutdown();
    delete this;
    return 0;
}

// FUNCTION: 0x0052a7a0
void cSC4CitySituationManager::TreatAutomatonAsGroup(uint32_t automaton, uint32_t group)
{
    if (automaton) {
        Automaton_a97e58* a = OB_PTR(Automaton_a97e58, automaton);
        a->GetOwner_a97e58()->SetGroup_a97e58(group);
        HandleInsertAutomaton(a);
    }
}

// FUNCTION: 0x00525100
void* cSC4CitySituationManager::GetTargetAsAutomaton()
{
    void* result = 0;
    Unknown_a97e58* target = FLD_a97e58(Unknown_a97e58*, 0xa50);
    if (target) {
        if (target->QueryInterface(0xa9b40f05, &result)) {
            static_cast<Unknown_a97e58*>(result)->Release();
        }
    }
    return result;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00524bb0 score 17
bool cSC4CitySituationManager::GetSituationMoney(uint32_t out)
{
    Advice_a97e58* advice = FLD_a97e58(Advice_a97e58*, 0x9f4);
    bool found = false;
    if (!advice) {
        return found;
    }
    if (FLD_a97e58(uint32_t, 0xa48) == 2) {
        advice->GetMoney2_a97e58(OB_PTR(void, out));
        return true;
    }
    advice->GetMoney1_a97e58(OB_PTR(void, out));
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00524b70 score 17
bool cSC4CitySituationManager::GetSituationAura(uint32_t a, uint32_t b)
{
    Advice_a97e58* advice = FLD_a97e58(Advice_a97e58*, 0x9f4);
    bool found = false;
    if (!advice) {
        return found;
    }
    if (FLD_a97e58(uint32_t, 0xa48) == 2) {
        advice->GetAura2_a97e58(OB_PTR(void, a), OB_PTR(void, b));
        return true;
    }
    advice->GetAura1_a97e58(OB_PTR(void, a), OB_PTR(void, b));
    return true;
}
#endif

struct HashClear_a97e58 {
    // STUB: 0x008eba60
    void Clear_a97e58();
};

struct OB_NOVTABLE SC4App_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual void Pad07_a97e58() = 0;
    virtual void Pad08_a97e58() = 0;
    virtual void Pad09_a97e58() = 0;
    virtual void Pad10_a97e58() = 0;
    virtual void Pad11_a97e58() = 0;
    virtual void Pad12_a97e58() = 0;
    virtual void Pad13_a97e58() = 0;
    virtual void Pad14_a97e58() = 0;
    virtual void Pad15_a97e58() = 0;
    virtual void Pad16_a97e58() = 0;
    virtual void Slot17_a97e58() = 0;
    virtual void Pad18_a97e58() = 0;
    virtual void Pad19_a97e58() = 0;
    virtual void Pad20_a97e58() = 0;
    virtual void Pad21_a97e58() = 0;
    virtual void Pad22_a97e58() = 0;
    virtual void Pad23_a97e58() = 0;
    virtual void Pad24_a97e58() = 0;
    virtual void Pad25_a97e58() = 0;
    virtual void Pad26_a97e58() = 0;
    virtual void Pad27_a97e58() = 0;
    virtual void Pad28_a97e58() = 0;
    virtual void Pad29_a97e58() = 0;
    virtual void Pad30_a97e58() = 0;
    virtual void Pad31_a97e58() = 0;
    virtual void Pad32_a97e58() = 0;
    virtual void Pad33_a97e58() = 0;
    virtual void Pad34_a97e58() = 0;
    virtual void Pad35_a97e58() = 0;
    virtual void Pad36_a97e58() = 0;
    virtual void Pad37_a97e58() = 0;
    virtual void* GetState_a97e58() = 0;
};

// GLOBAL: 0x00b43c94
extern SC4App_a97e58* gpB43c94_a97e58;

#ifdef OB_DRAFTS
// CLOSE: 0x005266e0 score 9
void cSC4CitySituationManager::ResetTutorials()
{
    reinterpret_cast<HashClear_a97e58*>(reinterpret_cast<char*>(this) + 0xa34)->Clear_a97e58();
    SC4App_a97e58* app = gpB43c94_a97e58;
    if (app) {
        void* state = app->GetState_a97e58();
        if (state) {
            memset(static_cast<char*>(state) + 0x1334, 0, 0x100);
            app->Slot17_a97e58();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0052e710 score 11
void cSC4CitySituationManager::HandleAutomatonMoved(void* automaton)
{
    if (FLD_a97e58(uint32_t, 0x9f4)) {
        if (FLD_a97e58(void*, 0xa4c) == automaton ||
            FLD_a97e58(void*, 0xa50) == static_cast<Automaton_a97e58*>(automaton)->GetOwner_a97e58()) {
            HandleStatusChanged(CheckForSuccess(0.0f));
        }
    }
}
#endif

struct OB_NOVTABLE Lua_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual int32_t GetTop_a97e58() = 0;
    virtual void SetTop_a97e58(int32_t top) = 0;
    virtual void Pad08_a97e58() = 0;
    virtual void Pad09_a97e58() = 0;
    virtual void Pad10_a97e58() = 0;
    virtual void Pad11_a97e58() = 0;
    virtual void Pad12_a97e58() = 0;
    virtual void Pad13_a97e58() = 0;
    virtual void Pad14_a97e58() = 0;
    virtual void Pad15_a97e58() = 0;
    virtual void Pad16_a97e58() = 0;
    virtual void Pad17_a97e58() = 0;
    virtual void Pad18_a97e58() = 0;
    virtual void Pad19_a97e58() = 0;
    virtual void Pad20_a97e58() = 0;
    virtual void Pad21_a97e58() = 0;
    virtual void Pad22_a97e58() = 0;
    virtual void Pad23_a97e58() = 0;
    virtual void Pad24_a97e58() = 0;
    virtual void Pad25_a97e58() = 0;
    virtual void Pad26_a97e58() = 0;
    virtual void Pad27_a97e58() = 0;
    virtual void Pad28_a97e58() = 0;
    virtual void Pad29_a97e58() = 0;
    virtual void Pad30_a97e58() = 0;
    virtual void Pad31_a97e58() = 0;
    virtual void Pad32_a97e58() = 0;
    virtual void Pad33_a97e58() = 0;
    virtual void Pad34_a97e58() = 0;
    virtual void Pad35_a97e58() = 0;
    virtual void Pad36_a97e58() = 0;
    virtual void Pad37_a97e58() = 0;
    virtual void Pad38_a97e58() = 0;
    virtual void Pad39_a97e58() = 0;
    virtual void Pad40_a97e58() = 0;
    virtual void Pad41_a97e58() = 0;
    virtual void Pad42_a97e58() = 0;
    virtual void Push_a97e58(uint32_t value) = 0;
    virtual void Pad44_a97e58() = 0;
    virtual void Pad45_a97e58() = 0;
    virtual void Pad46_a97e58() = 0;
    virtual void Pad47_a97e58() = 0;
    virtual void Pad48_a97e58() = 0;
    virtual void Pad49_a97e58() = 0;
    virtual int32_t Ref_a97e58(int32_t index) = 0;
    virtual void Call_a97e58(uint32_t args, uint32_t results) = 0;
    virtual void Pad52_a97e58() = 0;
    virtual void Pad53_a97e58() = 0;
    virtual void Pad54_a97e58() = 0;
    virtual void Pad55_a97e58() = 0;
    virtual void Pad56_a97e58() = 0;
    virtual void Pad57_a97e58() = 0;
    virtual void Pad58_a97e58() = 0;
    virtual void Pad59_a97e58() = 0;
    virtual void Pad60_a97e58() = 0;
    virtual void Pad61_a97e58() = 0;
    virtual void Pad62_a97e58() = 0;
    virtual void Pad63_a97e58() = 0;
    virtual void Pad64_a97e58() = 0;
    virtual void Pad65_a97e58() = 0;
    virtual void Pad66_a97e58() = 0;
    virtual void Pad67_a97e58() = 0;
    virtual void Pad68_a97e58() = 0;
    virtual void Pad69_a97e58() = 0;
    virtual void Pad70_a97e58() = 0;
    virtual bool IsFunction_a97e58(int32_t index) = 0;
};

// STUB: 0x005fb6a0
bool Fn005fb6a0(Lua_a97e58* lua, const char* name, int32_t index);

#ifdef OB_DRAFTS
// CLOSE: 0x005254d0 score 8
void cSC4CitySituationManager::InitScriptFuncRef(const char* name, int32_t index, void* out)
{
    if (Fn005fb6a0(FLD_a97e58(Lua_a97e58*, 0x24), name, index)) {
        if (FLD_a97e58(Lua_a97e58*, 0x24)->IsFunction_a97e58(-1)) {
            *static_cast<int32_t*>(out) = FLD_a97e58(Lua_a97e58*, 0x24)->Ref_a97e58(1);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00524660 score 12
float OB_STDCALL Fn00524660(float x)
{
    float v = x * 0.004f * 0.3f + 0.2f;
    if (v < 0.2f) {
        return 0.2f;
    }
    if (0.5f < v) {
        v = 0.5f;
    }
    return v;
}
#endif

struct Variant_a97e58 {
    uint8_t mData[0x14];
    // STUB: 0x0091673d
    Variant_a97e58* Construct_a97e58(uint32_t value);
    // STUB: 0x00915eb5
    void Destruct_a97e58();
    // STUB: 0x00915e8e
    Variant_a97e58* ConstructBool_a97e58(bool value);
    // STUB: 0x00915d6d
    Variant_a97e58* ConstructUlong_a97e58(uint32_t value);
    // STUB: 0x00915d44
    Variant_a97e58* ConstructUshort_a97e58(uint16_t value);
};

struct OB_NOVTABLE Object_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual uint16_t Slot05_a97e58(void* arg) = 0;
    virtual void Pad06_a97e58() = 0;
    virtual void Pad07_a97e58() = 0;
    virtual uint32_t Slot08_a97e58() = 0;
    virtual uint32_t Slot09_a97e58() = 0;
    virtual void Pad10_a97e58() = 0;
    virtual void Pad11_a97e58() = 0;
    virtual uint32_t Slot12_a97e58() = 0;
    virtual void Pad13_a97e58() = 0;
    virtual void Pad14_a97e58() = 0;
    virtual void Pad15_a97e58() = 0;
    virtual void Pad16_a97e58() = 0;
    virtual void Pad17_a97e58() = 0;
    virtual void Pad18_a97e58() = 0;
    virtual void Pad19_a97e58() = 0;
    virtual void Pad20_a97e58() = 0;
    virtual void Pad21_a97e58() = 0;
    virtual void Pad22_a97e58() = 0;
    virtual void Pad23_a97e58() = 0;
    virtual void Pad24_a97e58() = 0;
    virtual void Pad25_a97e58() = 0;
    virtual void Pad26_a97e58() = 0;
    virtual void Pad27_a97e58() = 0;
    virtual void Pad28_a97e58() = 0;
    virtual void Slot29_a97e58(uint32_t value) = 0;
    virtual bool Slot30_a97e58() = 0;
};

struct OB_NOVTABLE Item_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual void Pad07_a97e58() = 0;
    virtual void Pad08_a97e58() = 0;
    virtual void Pad09_a97e58() = 0;
    virtual void GetValue_a97e58(uint32_t* out) = 0;
};

struct OB_NOVTABLE ParamSet_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual Item_a97e58* GetItem_a97e58(uint32_t index) = 0;
    virtual void* GetParam_a97e58(uint32_t index) = 0;
    virtual void SetValue_a97e58(uint32_t index, Variant_a97e58* value) = 0;
    virtual uint32_t GetValue_a97e58(uint32_t index) = 0;
    virtual void Pad09_a97e58() = 0;
    virtual void Pad10_a97e58() = 0;
    virtual void Pad11_a97e58() = 0;
    virtual void Pad12_a97e58() = 0;
    virtual void Pad13_a97e58() = 0;
    virtual void Pad14_a97e58() = 0;
    virtual void Pad15_a97e58() = 0;
    virtual void Pad16_a97e58() = 0;
    virtual void Pad17_a97e58() = 0;
    virtual Object_a97e58* GetObject_a97e58(uint32_t id) = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x005247e0 score 7
bool Fn005247e0(uint32_t id, uint32_t unused, ParamSet_a97e58* set)
{
    Variant_a97e58 value;
    Variant_a97e58* made = value.Construct_a97e58(set->GetObject_a97e58(set->GetValue_a97e58(id))->Slot09_a97e58());
    set->SetValue_a97e58(1, made);
    value.Destruct_a97e58();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00524830 score 7
bool Fn00524830(uint32_t id, uint32_t unused, ParamSet_a97e58* set)
{
    Variant_a97e58 value;
    Variant_a97e58* made = value.Construct_a97e58(set->GetObject_a97e58(set->GetValue_a97e58(id))->Slot08_a97e58());
    set->SetValue_a97e58(1, made);
    value.Destruct_a97e58();
    return true;
}
#endif

// ---- batch 3: the STL containers the manager owns ----

struct HashResult_a97e58 {
    void* mpNode;
    void* mpTable;
    bool mbInserted;
};

// A COM-ish object held by a container.
struct OB_NOVTABLE Held_a97e58 {
    virtual bool QueryInterface(uint32_t id, void** out) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
};

struct PtrNode_a97e58 {
    PtrNode_a97e58* mpNext;
    Held_a97e58* mpValue;
};

struct Pair_a97e58 {
    uint32_t mnKey;
    uint16_t mnValue;
};

struct KeyNode_a97e58 {
    KeyNode_a97e58* mpNext;
    uint32_t mnKey;
    uint16_t mnValue;
};

struct PointNode_a97e58 {
    PointNode_a97e58* mpNext;
    uint16_t mnX;
    uint16_t mnY;
};

// A hash set of held objects (bucket vector at +4, element count at +0x10).
struct HashPtr_a97e58 {
    uint32_t mnPad;
    PtrNode_a97e58** mpBegin;
    PtrNode_a97e58** mpEnd;
    PtrNode_a97e58** mpCap;
    uint32_t mnSize;
    // STUB: 0x004f0940
    void Resize_a97e58(uint32_t count);
    // STUB: 0x00525fb0
    void Fn00525fb0(HashResult_a97e58* out, Held_a97e58** value);
    void Fn00526050();
    HashResult_a97e58* Fn005278a0(HashResult_a97e58* out, Held_a97e58** value);
};

// A hash map from a 32-bit key to a 16-bit value.
struct HashKey_a97e58 {
    uint32_t mnPad;
    KeyNode_a97e58** mpBegin;
    KeyNode_a97e58** mpEnd;
    KeyNode_a97e58** mpCap;
    uint32_t mnSize;
    uint32_t Fn00525e80(const uint32_t* key);
    void Fn00525f10(HashResult_a97e58* out, const KeyNode_a97e58* value);
    // STUB: 0x005260c0
    void Fn005260c0(HashResult_a97e58* out, const Pair_a97e58* value);
    // STUB: 0x00526510
    void Resize_00526510(uint32_t count);
    void Fn005278e0(HashResult_a97e58* out, const Pair_a97e58* value);
    uint16_t* Fn00527110(const uint32_t* key);
    // STUB: 0x004f0940
    void ResizeKey_a97e58(uint32_t count);
    // STUB: 0x005264a0
    Pair_a97e58* Fn005264a0(const Pair_a97e58* value);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00525e80 score 26
uint32_t HashKey_a97e58::Fn00525e80(const uint32_t* key)
{
    uint32_t k = *key;
    uint32_t count = 0;
    KeyNode_a97e58* p = mpBegin[k % static_cast<uint32_t>(mpEnd - mpBegin)];
    while (p) {
        if (p->mnKey == k) {
            ++count;
        }
        p = p->mpNext;
    }
    return count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00525f10 score 69
void HashKey_a97e58::Fn00525f10(HashResult_a97e58* out, const KeyNode_a97e58* value)
{
    uint32_t k = value->mnKey;
    uint32_t bucket = k % static_cast<uint32_t>(mpEnd - mpBegin);
    KeyNode_a97e58* first = mpBegin[bucket];
    for (KeyNode_a97e58* p = first; p; p = p->mpNext) {
        if (p->mnKey == k) {
            out->mpNode = p;
            out->mpTable = this;
            out->mbInserted = false;
            return;
        }
    }
    KeyNode_a97e58* node = static_cast<KeyNode_a97e58*>(Fn0090cf54(0xc));
    node->mpNext = 0;
    node->mnKey = value->mnKey;
    node->mnValue = value->mnValue;
    node->mpNext = first;
    mpBegin[bucket] = node;
    ++mnSize;
    out->mpNode = node;
    out->mpTable = this;
    out->mbInserted = true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00525fb0 score 47
void HashPtr_a97e58::Fn00525fb0(HashResult_a97e58* out, Held_a97e58** value)
{
    uint32_t k = OB_ADDR(*value);
    uint32_t bucket = k % static_cast<uint32_t>(mpEnd - mpBegin);
    PtrNode_a97e58* first = mpBegin[bucket];
    for (PtrNode_a97e58* p = first; p; p = p->mpNext) {
        if (OB_ADDR(p->mpValue) == k) {
            out->mpNode = p;
            out->mpTable = this;
            out->mbInserted = false;
            return;
        }
    }
    PtrNode_a97e58* node = static_cast<PtrNode_a97e58*>(Fn0090cf54(8));
    node->mpNext = 0;
    node->mpValue = *value;
    if (node->mpValue) {
        node->mpValue->AddRef();
    }
    node->mpNext = first;
    mpBegin[bucket] = node;
    ++mnSize;
    out->mpNode = node;
    out->mpTable = this;
    out->mbInserted = true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00526050 score 11
void HashPtr_a97e58::Fn00526050()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        PtrNode_a97e58* p = mpBegin[i];
        while (p) {
            PtrNode_a97e58* next = p->mpNext;
            if (p->mpValue) {
                p->mpValue->Release();
            }
            Fn0090cf63(p);
            p = next;
        }
        mpBegin[i] = 0;
    }
    mnSize = 0;
}
#endif

// FUNCTION: 0x005278a0
HashResult_a97e58* HashPtr_a97e58::Fn005278a0(HashResult_a97e58* out, Held_a97e58** value)
{
    Resize_a97e58(mnSize + 1);
    HashResult_a97e58 result;
    Fn00525fb0(&result, value);
    out->mpNode = result.mpNode;
    out->mpTable = result.mpTable;
    out->mbInserted = result.mbInserted;
    return out;
}

// The element nodes of the manager's lists hold two held objects at +8 and +0xc.
struct ListObjNode_a97e58 {
    ListObjNode_a97e58* mpNext;
    ListObjNode_a97e58* mpPrev;
    Held_a97e58* mpFirst;
    Held_a97e58* mpSecond;
    uint32_t mnThird;
};

struct ListObj_a97e58 {
    ListObjNode_a97e58* mpHead;
    // STUB: 0x00525ec0
    void Fn00525ec0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00525ec0 score 34
void ListObj_a97e58::Fn00525ec0()
{
    ListObjNode_a97e58* head = mpHead;
    ListObjNode_a97e58* p = head->mpNext;
    while (p != head) {
        ListObjNode_a97e58* node = p;
        p = p->mpNext;
        if (node->mpSecond) {
            node->mpSecond->Release();
        }
        if (node->mpFirst) {
            node->mpFirst->Release();
        }
        Fn0090cf63(node);
        head = mpHead;
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}
#endif

// A pair of held pointers with a size/flag word.
struct HeldPair_a97e58 {
    Held_a97e58* mpFirst;
    Held_a97e58* mpSecond;
    uint32_t mnFlag;
    HeldPair_a97e58* Fn00524a00(Held_a97e58* first);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00524a00 score 40
HeldPair_a97e58* HeldPair_a97e58::Fn00524a00(Held_a97e58* first)
{
    mpFirst = 0;
    mpSecond = 0;
    Held_a97e58* old = mpFirst;
    if (first != old) {
        if (first) {
            first->AddRef();
        }
        mpFirst = first;
        if (old) {
            old->Release();
        }
    }
    Held_a97e58* second = mpSecond;
    if (second) {
        mpSecond = 0;
        second->Release();
    }
    mnFlag = 0;
    return this;
}
#endif

struct Point16_a97e58 {
    uint16_t mnX;
    uint16_t mnY;
};

// A hash set of 16-bit points (key = y << 16 | x).
struct HashPoint_a97e58 {
    uint32_t mnPad;
    PointNode_a97e58** mpBegin;
    PointNode_a97e58** mpEnd;
    PointNode_a97e58** mpCap;
    uint32_t mnSize;
    uint32_t Fn00525a50(const Point16_a97e58* point);
    void Fn005271d0(const HashPoint_a97e58* other);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00525a50 score 39
uint32_t HashPoint_a97e58::Fn00525a50(const Point16_a97e58* point)
{
    uint16_t y = point->mnY;
    uint16_t x = point->mnX;
    uint32_t key = (static_cast<uint32_t>(y) << 16) | x;
    PointNode_a97e58* p = mpBegin[key % static_cast<uint32_t>(mpEnd - mpBegin)];
    uint32_t count = 0;
    while (p) {
        if (p->mnX == x && p->mnY == y) {
            ++count;
        }
        p = p->mpNext;
    }
    return count;
}
#endif

// ---- batch 4 ----

// The 0x2c-byte message object the allocator hands out; only the calls used here are named.
struct Message_a97e58 {
    virtual void Pad00_a97e58();
    virtual void AddRef_a97e58();
    virtual void Release_a97e58();
    virtual void Pad03_a97e58();
    virtual void Pad04_a97e58();
    virtual void SetType_a97e58(uint32_t id);
    virtual void Pad06_a97e58();
    virtual void Pad07_a97e58();
    virtual void Pad08_a97e58();
    virtual void Pad09_a97e58();
    virtual void Pad10_a97e58();
    virtual void SetValue_a97e58(uint32_t value);
    virtual void SetObject_a97e58(void* object);
    virtual void Pad13_a97e58();
    virtual void Pad14_a97e58();
    virtual void Pad15_a97e58();
    virtual void Pad16_a97e58();
    virtual void Pad17_a97e58();
    virtual void Pad18_a97e58();
    virtual void Pad19_a97e58();
    virtual void Pad20_a97e58();
    virtual void Pad21_a97e58();
    virtual void Pad22_a97e58();
    virtual void Pad23_a97e58();
    virtual void Pad24_a97e58();
    virtual void Pad25_a97e58();
    virtual void Pad26_a97e58();
    virtual void Pad27_a97e58();
    virtual void Pad28_a97e58();
    virtual void Pad29_a97e58();
    virtual void Pad30_a97e58();
    virtual void Pad31_a97e58();
    virtual void Pad32_a97e58();
    virtual void SetAdvice_a97e58(void* advice);
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    Message_a97e58();
    static void* operator new(size_t size) { return Fn009133da_a97e58(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct Vector_a97e58 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
};

// STUB: 0x00506850
void Fn00506850(void* automaton, void* target);

// FUNCTION: 0x00524c40
void cSC4CitySituationManager::HandleStatusChanged(uint32_t status)
{
    if (status != FLD_a97e58(uint32_t, 0xa48)) {
        Advice_a97e58* advice = FLD_a97e58(Advice_a97e58*, 0x9f4);
        FLD_a97e58(uint32_t, 0xa48) = status;
        if (advice && (status == 1 || status == 2)) {
            Automaton_a97e58* active = FLD_a97e58(Automaton_a97e58*, 0xa4c);
            if (active && active->HasFlag_a97e58(0x8000000)) {
                float limit = FLD_a97e58(Advice_a97e58*, 0x9f4)->GetTimeLimit_a97e58();
                if (!(limit > 1.0f)) {
                    limit = 1.0f;
                }
                FLD_a97e58(float, 0xa88) = limit;
                return;
            }
            FLD_a97e58(float, 0xa88) = 1.0f;
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x005246b0 score 34
bool cSC4CitySituationManager::QueryInterface(unsigned int id, void** out)
{
    switch (id) {
    case 0x6bb1437a:
        *out = this;
        break;
    case 1:
    case 0xe4fda3d4:
        *out = static_cast<cUnk00a80784*>(this);
        break;
    case 0x452294aa:
        *out = static_cast<cSC4CitySituationManager_4*>(this);
        break;
    case 0xe98b2f57:
        *out = static_cast<cSC4CitySituationManager_8*>(this);
        break;
    default:
        return false;
    }
    AddRef();
    return true;
}
#endif

// FUNCTION: 0x00524e20
void cSC4CitySituationManager::StartJoyride(uint32_t automaton, uint32_t flag, uint32_t target)
{
    FLD_a97e58(uint8_t, 0xa98) = static_cast<uint8_t>(flag);
    Message_a97e58* message = new Message_a97e58();
    message->AddRef_a97e58();
    message->SetType_a97e58(0xabbbca64);
    message->SetValue_a97e58(1);
    gpB43ccc->MessageSend(message);
    message->Release_a97e58();
    Fn00506850(OB_PTR(void, automaton), OB_PTR(void, target));
}

// FUNCTION: 0x00524d10
void cSC4CitySituationManager::Fn00524d10(uint32_t id, void* advice, void* automaton)
{
    Message_a97e58* message = new Message_a97e58();
    message->AddRef_a97e58();
    message->SetType_a97e58(id);
    if (advice) {
        message->SetAdvice_a97e58(advice);
    }
    if (automaton) {
        message->SetObject_a97e58(automaton);
    }
    gpB43ccc->MessagePost(message, false);
    message->Release_a97e58();
}

// FUNCTION: 0x00524d80
void cSC4CitySituationManager::SendSituationMessage(uint32_t id, void* advice, uint32_t value)
{
    Message_a97e58* message = new Message_a97e58();
    message->AddRef_a97e58();
    message->SetType_a97e58(id);
    if (advice) {
        message->SetAdvice_a97e58(advice);
    }
    message->SetValue_a97e58(value);
    gpB43ccc->MessageSend(message);
    message->Release_a97e58();
}

// FUNCTION: 0x00525070
void cSC4CitySituationManager::SetActiveAuto(void* automaton)
{
    Automaton_a97e58* wanted = static_cast<Automaton_a97e58*>(automaton);
    Automaton_a97e58* current = FLD_a97e58(Automaton_a97e58*, 0xa4c);
    if (wanted != current) {
        if (current) {
            current->Detach_a97e58(static_cast<cSC4CitySituationManager_4*>(this));
        }
        Automaton_a97e58* old = FLD_a97e58(Automaton_a97e58*, 0xa4c);
        if (wanted != old) {
            if (wanted) {
                wanted->AddRef_a97e58();
            }
            FLD_a97e58(Automaton_a97e58*, 0xa4c) = wanted;
            if (old) {
                old->Release_a97e58();
            }
        }
        if (FLD_a97e58(Automaton_a97e58*, 0xa4c)) {
            FLD_a97e58(Automaton_a97e58*, 0xa4c)->SetFlag_a97e58(0x4000, 1);
            FLD_a97e58(Automaton_a97e58*, 0xa4c)->Attach_a97e58(static_cast<cSC4CitySituationManager_4*>(this));
            FLD_a97e58(Automaton_a97e58*, 0xa4c)->Slot68_a97e58();
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0052bbc0 score 17
bool cSC4CitySituationManager::ChooseNextTarget()
{
    bool found = false;
    Advice_a97e58* advice = FLD_a97e58(Advice_a97e58*, 0x9f4);
    if (advice && advice->HasTargetList_a97e58()) {
        Vector_a97e58* targets = static_cast<Vector_a97e58*>(FLD_a97e58(Advice_a97e58*, 0x9f4)->GetTargetList_a97e58());
        uint32_t count = static_cast<uint32_t>(targets->mpEnd - targets->mpBegin);
        uint32_t index = FLD_a97e58(uint32_t, 0xa60) + 1;
        FLD_a97e58(uint32_t, 0xa60) = index;
        if (index < count) {
            found = Fn0052ad00(1) != 0;
            if (found) {
                FLD_a97e58(Automaton_a97e58*, 0xa4c)->Slot61_a97e58(0x2c22d924);
            }
            SendSituationMessage(0xac083d7d, FLD_a97e58(void*, 0x9f4), FLD_a97e58(uint32_t, 0xa60));
        }
    }
    return found;
}
#endif

// ---- batch 5 ----

struct OB_NOVTABLE Grid_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual int8_t GetCell_a97e58(uint32_t x, uint32_t y) = 0;
};

struct OB_NOVTABLE SurfaceWater_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual void Pad07_a97e58() = 0;
    virtual bool IsWater_a97e58(uint32_t x, uint32_t y, uint32_t kind, uint32_t flag) = 0;
};

// GLOBAL: 0x00b43cf0
extern SurfaceWater_a97e58* gpB43cf0_a97e58;

#ifdef OB_DRAFTS
// CLOSE: 0x00524e90 score 10
bool OB_STDCALL Fn00524e90(Point16_a97e58* point, int32_t zone, void* visited, uint32_t* count, uint32_t limit, int32_t width, int32_t height, Grid_a97e58* grid)
{
    if (*count < limit && point->mnX < width && point->mnY < height) {
        if (grid->GetCell_a97e58(point->mnX, point->mnY) == zone) {
            return gpB43cf0_a97e58->IsWater_a97e58(point->mnX, point->mnY, 2, 0);
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00526440 score 41
void Fn00526440(ListObjNode_a97e58** out, ListObjNode_a97e58* position, ListObjNode_a97e58* value)
{
    ListObjNode_a97e58* node = static_cast<ListObjNode_a97e58*>(Fn0090cf54(0x14));
    if (&node->mpFirst) {
        node->mpFirst = value->mpFirst;
        if (node->mpFirst) {
            node->mpFirst->AddRef();
        }
        node->mpSecond = value->mpSecond;
        if (node->mpSecond) {
            node->mpSecond->AddRef();
        }
        node->mnThird = value->mnThird;
    }
    node->mpNext = position;
    node->mpPrev = position->mpPrev;
    position->mpPrev->mpNext = node;
    position->mpPrev = node;
    *out = node;
}
#endif

// FUNCTION: 0x00525430
void cSC4CitySituationManager::Fn00525430(uint32_t first, uint32_t second)
{
    if (second != 0xfffffffe && FLD_a97e58(Lua_a97e58*, 0x24)) {
        Advice_a97e58* advice = FLD_a97e58(Advice_a97e58*, 0x9f4);
        if (advice && advice->HasFlag_a97e58(0x20)) {
            Advice_a97e58* object = FLD_a97e58(Advice_a97e58*, 0xaf8);
            if (object) {
                object->Slot68_a97e58();
            }
        }
        int32_t top = FLD_a97e58(Lua_a97e58*, 0x24)->GetTop_a97e58();
        FLD_a97e58(Lua_a97e58*, 0x24)->Push_a97e58(second);
        if (FLD_a97e58(Lua_a97e58*, 0x24)->IsFunction_a97e58(-1)) {
            FLD_a97e58(Lua_a97e58*, 0x24)->Push_a97e58(first);
            FLD_a97e58(Lua_a97e58*, 0x24)->Call_a97e58(1, 0);
        }
        FLD_a97e58(Lua_a97e58*, 0x24)->SetTop_a97e58(top);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00524910 score 7
bool Fn00524910(uint32_t id, uint32_t unused, ParamSet_a97e58* set)
{
    Object_a97e58* object = set->GetObject_a97e58(set->GetValue_a97e58(id));
    uint32_t result = 1;
    if (object) {
        result = object->Slot12_a97e58();
    }
    Variant_a97e58 value;
    Variant_a97e58* made = value.ConstructUlong_a97e58(result);
    set->SetValue_a97e58(1, made);
    value.Destruct_a97e58();
    return true;
}
#endif
struct OB_NOVTABLE OwnerQuery_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual bool HasKind_a97e58(uint32_t kind) = 0;
};

struct OB_NOVTABLE Occupant_a97e58 {
    virtual bool QueryInterface_a97e58(uint32_t id, void** out) = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual OwnerQuery_a97e58* GetOwner_a97e58() = 0;
};

struct OB_NOVTABLE ViewObject_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual uint32_t GetTypeId_a97e58() = 0;
};

struct OB_NOVTABLE View3D_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual void Pad07_a97e58() = 0;
    virtual void Pad08_a97e58() = 0;
    virtual void Pad09_a97e58() = 0;
    virtual void Pad10_a97e58() = 0;
    virtual void Pad11_a97e58() = 0;
    virtual void Pad12_a97e58() = 0;
    virtual void Pad13_a97e58() = 0;
    virtual void Pad14_a97e58() = 0;
    virtual void Pad15_a97e58() = 0;
    virtual void Pad16_a97e58() = 0;
    virtual void Pad17_a97e58() = 0;
    virtual void Pad18_a97e58() = 0;
    virtual void Pad19_a97e58() = 0;
    virtual void Pad20_a97e58() = 0;
    virtual void Pad21_a97e58() = 0;
    virtual void Pad22_a97e58() = 0;
    virtual void Pad23_a97e58() = 0;
    virtual ViewObject_a97e58* GetView_a97e58() = 0;
    virtual void Pad25_a97e58() = 0;
    virtual void SetMode_a97e58(uint32_t mode) = 0;
};

// GLOBAL: 0x00b43dc4
extern View3D_a97e58* gpB43dc4_a97e58;

// ---- batch 6 ----

// FUNCTION: 0x0052a7d0
void cSC4CitySituationManager::HandleInsertOccupant(void* occupant)
{
    Occupant_a97e58* occ = static_cast<Occupant_a97e58*>(occupant);
    if (occ) {
        if (!occ->GetOwner_a97e58()->HasKind_a97e58(0x29244db)) {
            Automaton_a97e58* automaton = 0;
            if (occ->QueryInterface_a97e58(0xa9b40f05, reinterpret_cast<void**>(&automaton))) {
                HandleInsertAutomaton(automaton);
            }
            if (automaton) {
                automaton->Release_a97e58();
            }
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0052e670 score 2
void cSC4CitySituationManager::HandleRemoveOccupant(void* occupant)
{
    Occupant_a97e58* occ = static_cast<Occupant_a97e58*>(occupant);
    if (occ) {
        if (FLD_a97e58(uint32_t, 0x9f4)) {
            uint32_t status = FLD_a97e58(uint32_t, 0xa48);
            if (occupant == FLD_a97e58(void*, 0xa50) && status == 3) {
                status = HandleTargetRemoved();
            }
            Automaton_a97e58* active = FLD_a97e58(Automaton_a97e58*, 0xa4c);
            if (active && static_cast<void*>(active->GetOwner_a97e58()) == occupant && status == 3) {
                status = HandleActiveAutoRemoved();
            }
            HandleStatusChanged(status);
        }
        Automaton_a97e58* automaton = 0;
        if (occ->QueryInterface_a97e58(0xa9b40f05, reinterpret_cast<void**>(&automaton))) {
            HandleRemoveAutomaton(automaton);
        }
        if (automaton) {
            automaton->Release_a97e58();
        }
    }
}
#endif

// FUNCTION: 0x005252d0
void cSC4CitySituationManager::DoMessage(uint32_t flag)
{
    if (static_cast<uint8_t>(flag)) {
        FLD_a97e58(uint8_t, 0xa98) = 1;
        Fn00506850(FLD_a97e58(void*, 0xa4c), static_cast<cSC4CitySituationManager_4*>(this));
    } else {
        View3D_a97e58* view = gpB43dc4_a97e58;
        if (view) {
            ViewObject_a97e58* current = view->GetView_a97e58();
            if (current) {
                if (current->GetTypeId_a97e58() == 0x2b709676) {
                    view->SetMode_a97e58(0);
                }
            }
        }
    }
}

// ---- Agent 2 ----

// STUB: 0x0051d120
void* Fn0051d120(void* param);
// STUB: 0x00568ba0
Held_a97e58** Fn00568ba0(Held_a97e58** from, Held_a97e58** end, Held_a97e58** to, void* scratch, uint32_t zero);
// GLOBAL: 0x00b227e0
extern uint32_t gB227e0;

// A smart pointer to an object that orders by a number two calls away.
struct OB_NOVTABLE Rank_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual int32_t GetValue_a97e58() = 0;
};

struct OB_NOVTABLE Ranked_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual Rank_a97e58* GetRank_a97e58() = 0;
};

struct Ref_a97e58 {
    Ranked_a97e58* mpObject;
    bool Fn00524a50(const Ref_a97e58* other);
};

struct VecHeld_a97e58 {
    Held_a97e58** mpBegin;
    Held_a97e58** mpEnd;
    Held_a97e58** Fn00527180(Held_a97e58** first, Held_a97e58** last);
};

struct Obj_a97de4 {
    uint32_t mnVtable0;
    uint32_t mnVtable4;
    uint32_t mnPad[4];
    uint32_t mn18;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
    // STUB: 0x005ea280
    void Fn005ea280(uint32_t arg);
    Obj_a97de4* Fn00526610();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00526610 score 2
Obj_a97de4* Obj_a97de4::Fn00526610()
{
    Fn005ea280(0);
    // (the two vtable words at +0 and +4 are stored here by the original)
    mn18 = 0;
    mn1c = gB227e0;
    mn20 = gB227e0;
    mn24 = gB227e0;
    return this;
}
#endif

// FUNCTION: 0x005278e0
void HashKey_a97e58::Fn005278e0(HashResult_a97e58* out, const Pair_a97e58* value)
{
    Resize_00526510(mnSize + 1);
    HashResult_a97e58 result;
    Fn005260c0(&result, value);
    out->mpNode = result.mpNode;
    out->mpTable = result.mpTable;
    out->mbInserted = result.mbInserted;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005264a0 score 15
Pair_a97e58* HashKey_a97e58::Fn005264a0(const Pair_a97e58* value)
{
    ResizeKey_a97e58(mnSize + 1);
    uint32_t bucket = value->mnKey % static_cast<uint32_t>(mpEnd - mpBegin);
    KeyNode_a97e58* first = mpBegin[bucket];
    KeyNode_a97e58* node = static_cast<KeyNode_a97e58*>(Fn0090cf54(0xc));
    Pair_a97e58* pair = reinterpret_cast<Pair_a97e58*>(&node->mnKey);
    node->mpNext = 0;
    if (pair) {
        pair->mnKey = value->mnKey;
        pair->mnValue = value->mnValue;
    }
    node->mpNext = first;
    mpBegin[bucket] = node;
    ++mnSize;
    return pair;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00527110 score 33
uint16_t* HashKey_a97e58::Fn00527110(const uint32_t* key)
{
    uint32_t k = *key;
    KeyNode_a97e58* p = mpBegin[k % static_cast<uint32_t>(mpEnd - mpBegin)];
    while (p) {
        if (p->mnKey == k) {
            break;
        }
        p = p->mpNext;
    }
    if (!p) {
        Pair_a97e58 pair;
        pair.mnKey = k;
        pair.mnValue = 0;
        return &Fn005264a0(&pair)->mnValue;
    }
    return &p->mnValue;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00524a50 score 27
bool Ref_a97e58::Fn00524a50(const Ref_a97e58* other)
{
    bool result = false;
    if (mpObject) {
        if (other->mpObject) {
            Rank_a97e58* mine = mpObject->GetRank_a97e58();
            int32_t theirs = other->mpObject->GetRank_a97e58()->GetValue_a97e58();
            if (mine->GetValue_a97e58() < theirs) {
                return true;
            }
        }
        return result;
    }
    if (other->mpObject) {
        return true;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00527180 score 12
Held_a97e58** VecHeld_a97e58::Fn00527180(Held_a97e58** first, Held_a97e58** last)
{
    uint32_t scratch;
    Held_a97e58** newEnd = Fn00568ba0(last, mpEnd, first, &scratch, 0);
    Held_a97e58** oldEnd = mpEnd;
    for (Held_a97e58** p = newEnd; p != oldEnd; ++p) {
        if (*p) {
            (*p)->Release();
        }
    }
    mpEnd = newEnd;
    return first;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005245f0 score 26
bool OB_STDCALL Fn005245f0(Automaton_a97e58* automaton)
{
    bool result = false;
    if (automaton) {
        if (automaton->HasFlag_a97e58(2) && !automaton->HasFlag_a97e58(1) && !automaton->HasFlag_a97e58(0x8000000)
            && !automaton->HasFlag_a97e58(0x10000000)) {
            int32_t type = automaton->GetType_a97e58();
            if (type != 0x34) {
                return type != 0x14;
            }
        }
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00524760 score 23
bool Fn00524760(uint32_t id, ParamSet_a97e58* input, ParamSet_a97e58* set)
{
    Object_a97e58* object = set->GetObject_a97e58(set->GetValue_a97e58(id));
    uint16_t result = 0;
    void* param = input->GetParam_a97e58(0);
    if (param) {
        void* handle = Fn0051d120(param);
        if (object && handle) {
            result = object->Slot05_a97e58(handle);
        }
    }
    Variant_a97e58 value;
    Variant_a97e58* made = value.ConstructUshort_a97e58(result);
    set->SetValue_a97e58(1, made);
    value.Destruct_a97e58();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00524880 score 25
bool Fn00524880(uint32_t id, ParamSet_a97e58* input, ParamSet_a97e58* set)
{
    Object_a97e58* object = set->GetObject_a97e58(set->GetValue_a97e58(id));
    bool result = true;
    if (object) {
        uint32_t token = 1;
        input->GetItem_a97e58(0)->GetValue_a97e58(&token);
        result = object->Slot30_a97e58();
        object->Slot29_a97e58(token);
    }
    Variant_a97e58 value;
    Variant_a97e58* made = value.ConstructBool_a97e58(result);
    set->SetValue_a97e58(1, made);
    value.Destruct_a97e58();
    return true;
}
#endif

// FUNCTION: 0x005263d0
void cSC4CitySituationManager::Fn005263d0()
{
    ListObjNode_a97e58* head = FLD_a97e58(ListObjNode_a97e58*, 0xa04);
    for (ListObjNode_a97e58* node = head->mpNext; node != head; node = node->mpNext) {
        Held_a97e58* first = node->mpFirst;
        if (first) {
            node->mpFirst = 0;
            first->Release();
        }
        DispatchVehicleView_a97e58* view = FLD_a97e58(DispatchVehicleView_a97e58*, 0xa2c);
        if (view && node->mnThird) {
            view->Fn0046efb0(node->mnThird, 0);
        }
        Held_a97e58* second = node->mpSecond;
        if (second) {
            node->mpSecond = 0;
            second->Release();
        }
        node->mnThird = 0;
    }
    reinterpret_cast<ListObj_a97e58*>(reinterpret_cast<char*>(this) + 0xa04)->Fn00525ec0();
}

// ---- batch 8 ----

struct BucketVec_a97e58 {
    PointNode_a97e58** mpBegin;
    PointNode_a97e58** mpEnd;
    PointNode_a97e58** mpCap;
    // STUB: 0x0045d4f0
    void Reserve_a97e58(uint32_t count);
    // STUB: 0x004fba20
    void Fill_a97e58(PointNode_a97e58** position, uint32_t count, PointNode_a97e58* const* value);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005271d0 score 123
void HashPoint_a97e58::Fn005271d0(const HashPoint_a97e58* other)
{
    BucketVec_a97e58* vec = reinterpret_cast<BucketVec_a97e58*>(&mpBegin);
    mpEnd = mpBegin;
    uint32_t count = static_cast<uint32_t>(other->mpEnd - other->mpBegin);
    vec->Reserve_a97e58(count);
    PointNode_a97e58* zero = 0;
    vec->Fill_a97e58(mpEnd, count, &zero);
    for (uint32_t i = 0; i < static_cast<uint32_t>(other->mpEnd - other->mpBegin); ++i) {
        PointNode_a97e58* src = other->mpBegin[i];
        if (src) {
            PointNode_a97e58* node = static_cast<PointNode_a97e58*>(Fn0090cf54(8));
            node->mpNext = 0;
            node->mnX = src->mnX;
            node->mnY = src->mnY;
            mpBegin[i] = node;
            PointNode_a97e58* last = node;
            for (src = src->mpNext; src; src = src->mpNext) {
                PointNode_a97e58* copy = static_cast<PointNode_a97e58*>(Fn0090cf54(8));
                copy->mpNext = 0;
                copy->mnX = src->mnX;
                copy->mnY = src->mnY;
                last->mpNext = copy;
                last = copy;
            }
        }
    }
    mnSize = other->mnSize;
}
#endif

struct OB_NOVTABLE TargetObj_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual void Pad07_a97e58() = 0;
    virtual void Pad08_a97e58() = 0;
    virtual void Pad09_a97e58() = 0;
    virtual void Pad10_a97e58() = 0;
    virtual void Pad11_a97e58() = 0;
    virtual void Pad12_a97e58() = 0;
    virtual void Pad13_a97e58() = 0;
    virtual void Pad14_a97e58() = 0;
    virtual void Pad15_a97e58() = 0;
    virtual void Pad16_a97e58() = 0;
    virtual void Pad17_a97e58() = 0;
    virtual void Pad18_a97e58() = 0;
    virtual void Pad19_a97e58() = 0;
    virtual void Pad20_a97e58() = 0;
    virtual void Pad21_a97e58() = 0;
    virtual bool HasKind_a97e58(uint32_t kind) = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0052c0e0 score 63
uint32_t cSC4CitySituationManager::HandleTargetRemoved()
{
    uint32_t result = FLD_a97e58(uint32_t, 0xa48);
    if (FLD_a97e58(int32_t, 0xae4) == -2) {
        int32_t kind = FLD_a97e58(Advice_a97e58*, 0x9f4)->GetKind_a97e58();
        if (kind == 1) {
            result = 2;
        } else if (kind == 3) {
            if (!ChooseNextTarget()) {
                result = 1;
            }
        }
    } else {
        TargetObj_a97e58* target = FLD_a97e58(TargetObj_a97e58*, 0xa50);
        if (target) {
            if (target->HasKind_a97e58(0x5005) || target->HasKind_a97e58(0x5006)) {
                if (!Fn0052ad00(1)) {
                    SetTarget(0);
                }
            }
        }
    }
    HandleStatusChanged(result);
    return result;
}
#endif

struct OB_NOVTABLE AutoTarget_a97e58 {
    virtual bool QueryInterface_a97e58(uint32_t id, void** out) = 0;
    virtual uint32_t AddRef_a97e58() = 0;
    virtual uint32_t Release_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual void Pad07_a97e58() = 0;
    virtual void Pad08_a97e58() = 0;
    virtual void Pad09_a97e58() = 0;
    virtual void Pad10_a97e58() = 0;
    virtual void Pad11_a97e58() = 0;
    virtual void Pad12_a97e58() = 0;
    virtual void Slot13_a97e58(uint32_t value) = 0;
};

struct OB_NOVTABLE Advisor_a97e58 {
    virtual void Pad00_a97e58() = 0;
    virtual void Pad01_a97e58() = 0;
    virtual void Pad02_a97e58() = 0;
    virtual void Pad03_a97e58() = 0;
    virtual void Pad04_a97e58() = 0;
    virtual void Pad05_a97e58() = 0;
    virtual void Pad06_a97e58() = 0;
    virtual Advisor_a97e58* GetAdvisor_a97e58(uint32_t id) = 0;
    virtual void Pad08_a97e58() = 0;
    virtual void Pad09_a97e58() = 0;
    virtual void Pad10_a97e58() = 0;
    virtual void Pad11_a97e58() = 0;
    virtual void Pad12_a97e58() = 0;
    virtual void Pad13_a97e58() = 0;
    virtual void Pad14_a97e58() = 0;
    virtual void Pad15_a97e58() = 0;
    virtual void Pad16_a97e58() = 0;
    virtual void Pad17_a97e58() = 0;
    virtual void Pad18_a97e58() = 0;
    virtual void Pad19_a97e58() = 0;
    virtual void Slot20_a97e58(uint32_t value) = 0;
};

// GLOBAL: 0x00b43d34
extern Advisor_a97e58* gpB43d34_a97e58;

#ifdef OB_DRAFTS
// CLOSE: 0x0052bf00 score 1
uint32_t cSC4CitySituationManager::Fn0052bf00()
{
    if (FLD_a97e58(uint8_t, 0xa64)) {
        void* found = 0;
        Unknown_a97e58* target = FLD_a97e58(Unknown_a97e58*, 0xa50);
        if (target) {
            if (target->QueryInterface(0xa9b40f05, &found)) {
                static_cast<Unknown_a97e58*>(found)->Release();
            }
        }
        AutoTarget_a97e58* automaton = static_cast<AutoTarget_a97e58*>(found);
        if (automaton) {
            automaton->AddRef_a97e58();
            automaton->Slot13_a97e58(0);
            automaton->Release_a97e58();
        }
    }
    Advice_a97e58* advice = FLD_a97e58(Advice_a97e58*, 0x9f4);
    if (advice) {
        if (gpB43d34_a97e58) {
            Advisor_a97e58* advisor = gpB43d34_a97e58->GetAdvisor_a97e58(0x1d);
            if (advisor) {
                advisor->Slot20_a97e58(advice->GetId_a97e58());
            }
        }
        Fn0052a650(OB_ADDR(advice));
    }
    EndSituation();
    return 0;
}
#endif
