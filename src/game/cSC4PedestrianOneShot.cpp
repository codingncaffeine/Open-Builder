#include <cmath>
#include <cstddef>
#include <cstring>

#include "classes/cSC4PedestrianOneShot.h"
#include "game/Globals.h"

// The primary vtable of the automaton with the signatures the code shows (the base interface declares some wrongly).
struct AutoVT_a9c068 {
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
    virtual bool Slot70_a9c068(bool);
    virtual bool PlaceInOccupantManager(bool);
    virtual bool DoAnimationTick(uint32_t, uint32_t);
    virtual bool ShouldCollide(void*);
    virtual void SetZoomAndRotation(uint32_t, uint32_t);
    virtual bool SetTransform(void*);
    virtual uint32_t Slot76_a9c068(void*);
    virtual void EnableActiveSound(bool);
    virtual void UpdateActiveSound(float);
    virtual void HandleReachedRouteDestination();
    virtual void Slot80_a9c068(uint32_t, uint32_t);
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
    virtual void Slot96_a9c068(uint32_t, void*);
    virtual bool LoadModels();
    virtual bool UnloadModels();
    virtual bool LoadAuxiliaryModel(uint32_t, void*);
    virtual void FinishMove(bool, bool);
    virtual bool PostInit();
    virtual void Slot102_a9c068(uint32_t, uint32_t);
    virtual bool Slot103_a9c068(float);
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

#define AVT(self) reinterpret_cast<AutoVT_a9c068*>(self)

struct PedVT_a9c068 : AutoVT_a9c068 {
    virtual bool DoPathTick(float);
    virtual bool DoStraightLineTick(uint32_t);
    virtual bool StartTrip(uint32_t, uint32_t, uint32_t);
    virtual void SetPath(void*, void*, void*, bool);
    virtual void InterpolateAlongPath(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
    virtual bool SnapToPath();
    virtual void HandleNetworkOccupantRemoved();
    virtual void* GetPathKey(void*);
    virtual uint32_t GetNetworkOccupant();
    virtual float GetPathOffset();
    virtual void SetPathOffset(uint32_t);
    virtual void* GetPathPos();
    virtual bool IsTrain();
    virtual bool BeginRoute(bool);
    virtual void* GetDispatchDestination();
    virtual void* GetRouteInfo();
    virtual bool SetRouteInfo(void*, bool, bool);
    virtual bool CloseEnoughToDispatchDestination();
    virtual void RemoveSurroundingAutomata(uint32_t, uint32_t);
    virtual void* FindLeader();
    virtual void SetDetectCollisions(bool);
    virtual bool GetDetectCollisions();
    virtual float GetSafeDistance();
    virtual bool GetStopPoint(void*);
    virtual bool GetCellLifespan();
    virtual void SetCellLifespan(bool);
    virtual void UpdateOrientation(void*, void*);
    virtual void* GetLookaheadDeque();
    virtual void OffsetPathPoint(uint32_t);
    virtual void RecalculatePathOffset();
    virtual void SlowDownForStopLight();
    virtual void ReturnToDefaultSpeed();
    virtual void UpdateCollision();
    virtual bool CheckIntersectionDensity();
    virtual bool DoStopSignTick(float);
    virtual bool DoStopAtStationTick(float);
    virtual bool ChooseNewDestination();
    virtual bool ChooseLookaheadTiles();
    virtual void Slot167_a9c068();
    virtual bool ChooseLookaheadTileByRoute(uint32_t, uint32_t);
    virtual bool Slot169_a9c068(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
    virtual bool ApplyAttractionWeight(uint32_t, uint32_t);
    virtual uint32_t GetEdgeFromVector(uint32_t, uint32_t, uint32_t, uint32_t);
    virtual bool HandleExitNetwork(void*, uint32_t, void*, void*);
    virtual bool ChooseRandomPath(void*, uint32_t);
    virtual void Slot174_a9c068();
    virtual uint32_t GetDesiredLookaheadCount();
};

#define PVT(self) reinterpret_cast<PedVT_a9c068*>(self)

#define OCCV_A9C068(self) reinterpret_cast<OccView_a9c068*>(reinterpret_cast<char*>(self) + 4)

// The occupant subobject at +0x4: slot 5 says whether the automaton is already set up.
struct OccView_a9c068 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual bool Fn05();
};

// The random generator object at 0xb21d78, passed by address.
struct Random_a9c068 {
    uint32_t mPad;
};

// GLOBAL: 0x00b21d78
extern Random_a9c068 gB21d78_a9c068;

// GLOBAL: 0x00b21d28
extern uint8_t gbB21d28;

// GLOBAL: 0x00b21cb8
extern uint8_t gbB21cb8;

// The ramped value embedded at +0x1a0.
struct Ramp_a9c068 {
    // STUB: 0x004fa960
    float Fn004fa960();
};

// The route deque embedded at +0x22c.
struct RouteDeque_a9c068 {
    // STUB: 0x00532430
    void Fn00532430(const void* other);
};

// The path object a network occupant hands out: slot 9 picks a random path.
struct PathSrc_a9c068 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void* Fn09(uint32_t, uint32_t, uint32_t, void*, void*, uint32_t);
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
    virtual bool Fn36(void* out, uint32_t a, uint32_t b, uint32_t c, uint32_t d);
};

// A network occupant: slot 49 hands out its path source.
struct NetOcc_a9c068 {
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
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual PathSrc_a9c068* Fn49();
};

// An object with a boolean query in slot 22.
struct Query_a9c068 {
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
    virtual bool Fn22(uint32_t);
};

// A reference-counted object: slot 1 adds a reference, slot 2 releases one.
struct Ref_a9c068 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};

// FUNCTION: 0x00504fa0
bool cSC4PedestrianOneShot::GetDetectCollisions()
{
    return AVT(this)->Slot31_a953a8(8);
}

// FUNCTION: 0x00504fe0
uint32_t cSC4PedestrianOneShot::GetDesiredLookaheadCount()
{
    return gbB21d28;
}

// FUNCTION: 0x0053cc00
void cSC4PedestrianOneShot::RecalculatePathOffset()
{
    mfPathOffset = 0.0f;
}

// FUNCTION: 0x0054d790
bool cSC4PedestrianOneShot::Slot03_a953a8()
{
    bool ok = true;
    if (!OCCV_A9C068(this)->Fn05()) {
        ok = cSC4Automaton::Slot03_a953a8();
        if (!mb3c && ok) {
            if (!AVT(this)->Slot31_a953a8(0x4000)) {
                UpdateAttraction();
            }
            if (!AVT(this)->Slot31_a953a8(0x2000)) {
                PVT(this)->SnapToPath();
            }
        }
    }
    return ok;
}

// FUNCTION: 0x0054d7f0
bool cSC4PedestrianOneShot::QueryInterface(uint32_t iid, void** pv)
{
    void** ppv = pv;
    *ppv = 0;
    if (iid == 0x8b99ee7c) {
        *ppv = this;
        AddRef();
        return true;
    }
    return cSC4Automaton::QueryInterface(iid, pv);
}

// FUNCTION: 0x0054d820
void cSC4PedestrianOneShot::HandleNetworkOccupantRemoved()
{
    AVT(this)->Slot13_a953a8(0);
}

// FUNCTION: 0x0054d830
bool cSC4PedestrianOneShot::HandleExitNetwork(void* pNet, uint32_t key, void* /*pLot*/, void* /*pRect*/)
{
    PVT(this)->ChooseRandomPath(pNet, key);
    AVT(this)->Slot13_a953a8(0);
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0054d860 score 30
bool cSC4PedestrianOneShot::ChooseRandomPath(void* pNet, uint32_t key)
{
    bool result = false;
    NetOcc_a9c068* net = static_cast<NetOcc_a9c068*>(pNet);
    if (net != 0) {
        PathSrc_a9c068* src = net->Fn49();
        if (src != 0) {
            uint32_t local;
            void* path = src->Fn09((key >> 24) & 0xf, key >> 8, 0xff, &gB21d78_a9c068, &local, 0);
            if (path != 0) {
                PVT(this)->SetPath(pNet, OB_PTR(void, local), path, true);
                return true;
            }
        }
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0054da00 score 7
void cSC4PedestrianOneShot::SlowDownForStopLight()
{
    float speed = GetSpeedModifier();
    float rate;
    if (speed > 0.0f) {
        rate = 1.0f / speed * 1.5f;
    } else {
        rate = 0.1f;
    }
    AVT(this)->Slot36_a953a8(0.0f, rate);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0054da50 score 7
void cSC4PedestrianOneShot::ReturnToDefaultSpeed()
{
    float speed = GetSpeedModifier();
    float rate;
    if (speed > 0.0f) {
        rate = 1.0f / speed * 0.3f;
    } else {
        rate = 0.1f;
    }
    AVT(this)->Slot36_a953a8(AVT(this)->Slot35_a953a8(), rate);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0054dab0 score 4
bool cSC4PedestrianOneShot::CloseEnoughToDispatchDestination()
{
    const float* dest = static_cast<const float*>(PVT(this)->GetDispatchDestination());
    float dx = dest[0] - mfPosX;
    float dy = dest[1] - mfPosY;
    float dz = dest[2] - mfPosZ;
    int32_t limit = gbB21cb8 << 4;
    return static_cast<float>(std::sqrt(static_cast<double>(dx * dx + dy * dy + dz * dz))) <= static_cast<float>(limit);
}
#endif

// FUNCTION: 0x0054e3d0
bool cSC4PedestrianOneShot::DoStopAtStationTick(float dt)
{
    Ramp_a9c068* ramp = reinterpret_cast<Ramp_a9c068*>(reinterpret_cast<char*>(this) + 0x1a0);
    if (ramp->Fn004fa960() > 0.0f) {
        PVT(this)->DoPathTick(dt);
    }
    cSC4Automaton::DoStateTick(dt);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00550090 score 17
bool cSC4PedestrianOneShot::DoStateTick(float dt)
{
    if (mpStateBegin != mpStateEnd) {
        uint32_t id = static_cast<uint32_t*>(mpStateEnd[-1])[1];
        if (id == 0xd) {
            return PVT(this)->DoStopSignTick(dt);
        }
        if (id == 0x1e) {
            return PVT(this)->DoStopAtStationTick(dt);
        }
    }
    return cSC4Automaton::DoStateTick(dt);
}
#endif

// FUNCTION: 0x00555310
bool cSC4PedestrianOneShot::Slot04_a953a8()
{
    if (OCCV_A9C068(this)->Fn05()) {
        PVT(this)->SetPath(0, 0, 0, false);
        Fn00554640();
    }
    return cSC4Automaton::Slot04_a953a8();
}

#ifdef OB_DRAFTS
// CLOSE: 0x005559d0 score 7
bool cSC4PedestrianOneShot::SetRouteInfo(void* pRoute, bool applyNow, bool flag)
{
    const void* const* route = static_cast<const void* const*>(pRoute);
    if (route[4] == route[0]) {
        return false;
    }
    bool ok = true;
    reinterpret_cast<RouteDeque_a9c068*>(reinterpret_cast<char*>(this) + 0x22c)->Fn00532430(pRoute);
    if (applyNow) {
        ok = PVT(this)->BeginRoute(flag);
        if (!ok) {
            return ok;
        }
    }
    PVT(this)->ReturnToDefaultSpeed();
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0054ea30 score 17
bool cSC4PedestrianOneShot::Fn0054ea30()
{
    if (mb1e8) {
        return true;
    }
    if (mnMode1e4 == 7 || mnMode1e4 == 8) {
        return true;
    }
    if (AVT(this)->Slot31_a953a8(0x200000)) {
        return true;
    }
    if (mpObj1ec != 0) {
        if (static_cast<Query_a9c068*>(mpObj1ec)->Fn22(2)) {
            return true;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x0054eb20
void cSC4PedestrianOneShot::SetDetectCollisions(bool on)
{
    if (on != PVT(this)->GetDetectCollisions()) {
        AVT(this)->Slot30_a953a8(8, on);
        if (on) {
            Ref_a9c068* leader = static_cast<Ref_a9c068*>(PVT(this)->FindLeader());
            Ref_a9c068* old = static_cast<Ref_a9c068*>(mpLeader);
            if (leader != old) {
                if (leader != 0) {
                    leader->AddRef();
                }
                mpLeader = leader;
                if (old != 0) {
                    old->Release();
                }
            }
        }
        RecalculateLeaders();
    }
}

// ---- batch 2 ----

// The traffic network map: slot 15 finds the occupants of a cell.
struct TrafficMap_a9c068 {
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
    virtual NetOcc_a9c068** Fn15(void* network, uint32_t a, uint32_t b, uint32_t c);
};

// GLOBAL: 0x00b43d54
extern TrafficMap_a9c068* gpB43d54;

#ifdef OB_DRAFTS
// CLOSE: 0x0054ea80 score 42
void cSC4PedestrianOneShot::UpdateOrientation(void* pTarget, void* pOut)
{
    const float* t = static_cast<const float*>(pTarget);
    float* out = static_cast<float*>(pOut);
    float dx = t[0] - mfPosX;
    float dy = t[1] - mfPosY;
    float dz = t[2] - mfPosZ;
    float len = static_cast<float>(std::sqrt(static_cast<double>(dz * dz + dy * dy + dx * dx)));
    if (len > 9.99999974737875e-06f) {
        float scale = 1.0f / len;
        out[0] = dx * scale;
        out[1] = dy * scale;
        out[2] = dz * scale;
    } else {
        out[1] = 0.0f;
        out[0] = 0.0f;
        out[2] = 1.0f;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0054eb90 score 72
bool cSC4PedestrianOneShot::GetStopPoint(void* pOut)
{
    PathSrc_a9c068* src = static_cast<PathSrc_a9c068*>(mpPathSrc1f0);
    if (src == 0) {
        return false;
    }
    uint8_t keyLo = static_cast<uint8_t>(mnKey1f4);
    uint8_t keyMid = static_cast<uint8_t>(mnKey1f4 >> 8);
    uint32_t dir = static_cast<uint8_t>(mnKey1f4 >> 24) & 0xf;
    bool found = src->Fn36(pOut, dir, keyMid, 0xff, 0);
    if (found) {
        return found;
    }
    NetOcc_a9c068** pp = gpB43d54->Fn15(mpObj1ec, keyLo, 1, dir);
    if (pp != 0) {
        NetOcc_a9c068* occ = *pp;
        if (occ != 0) {
            PathSrc_a9c068* other = occ->Fn49();
            if (other != 0) {
                int32_t turn = (keyLo + 2) % 4;
                return other->Fn36(pOut, dir, turn, 0xff, 0);
            }
        }
    }
    return found;
}
#endif

// Mass-produced view of the city: slot 40 hands out the traffic network.
struct TrafficNet_a9c068 {
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
    virtual uint32_t Fn33(void* network, void* automaton, void* key);
};

struct CityV_a9c068 {
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
    virtual TrafficNet_a9c068* Fn40();
};

// GLOBAL: 0x00b43cec
extern CityV_a9c068* gpB43cec_a9c068;

// The top state: the countdown at +0x10.
struct TopState_a9c068 {
    uint8_t mPad[0x10];
    float mfTimer;
};

#ifdef OB_DRAFTS
// CLOSE: 0x005500d0 score 52
bool cSC4PedestrianOneShot::DoStopSignTick(float dt)
{
    TopState_a9c068* s = static_cast<TopState_a9c068*>(mpStateEnd[-1]);
    if (0.0f < s->mfTimer) {
        if (!AVT(this)->Slot31_a953a8(0x20)) {
            return false;
        }
        s->mfTimer = s->mfTimer - cSC4Automaton::GetSpeedModifier() * dt;
        if (0.0f < s->mfTimer) {
            return true;
        }
    }
    PVT(this)->ReturnToDefaultSpeed();
    AVT(this)->Slot30_a953a8(0x20, false);
    AVT(this)->Slot30_a953a8(0x10, false);
    TrafficNet_a9c068* net = gpB43cec_a9c068->Fn40();
    uint8_t keyBuf[16];
    void* key = PVT(this)->GetPathKey(keyBuf);
    if (net->Fn33(mpObj1ec, this, key) == 0) {
        AVT(this)->Slot53_a953a8();
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0054e5b0 score 51
void cSC4PedestrianOneShot::Slot10_a953a8(uint32_t pDest)
{
    AVT(this)->Slot30_a953a8(4, false);
    const float* d = OB_PTR(const float, pDest);
    mfDestX = d[0];
    mfDestY = d[1];
    mfDestZ = d[2];
    float dx = mfDestX - mfPosX;
    float dy = mfDestY - mfDestY;
    float dz = mfDestZ - mfPosZ;
    float len = static_cast<float>(std::sqrt(static_cast<double>(dz * dz + dy * dy + dx * dx)));
    if (len > 0.0f) {
        float scale = 1.0f / len;
        mfVec58X = dx * scale;
        mfVec58Y = dy * scale;
        mfVec58Z = dz * scale;
        AVT(this)->Slot16_a953a8(0, &mfVec58X);
    } else {
        AVT(this)->Slot30_a953a8(4, true);
        Slot102_a95ac0(4, 0);
    }
}
#endif
