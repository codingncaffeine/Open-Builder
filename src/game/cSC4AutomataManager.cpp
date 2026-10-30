#include <cmath>
#include <cstddef>
#include <cstring>

#include "classes/cSC4AutomataManager.h"
#include "game/Globals.h"

// GLOBAL: 0x00b21b94
extern bool gbB21b94;

// GLOBAL: 0x00b21ba4
extern float gfB21ba4;

// GLOBAL: 0x00b0996c
extern float gfB0996c;

// A reference-counted object: slot 1 adds a reference, slot 2 releases one.
struct Ref_a95880 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};

// An occupant group template: the parent link sits at +0xc and a value at +0x6c.
struct Group_a95880 {
    uint8_t mPad0[0xc];
    Group_a95880* mpParent;
    uint8_t mPad10[0x6c - 0x10];
    uint32_t mn6c;
    uint32_t Fn00505330();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00505330 score 9
uint32_t Group_a95880::Fn00505330()
{
    uint32_t value = mn6c;
    if (value == 0) {
        if (mpParent == 0) {
            return 0;
        }
        return mpParent->Fn00505330();
    }
    return value;
}
#endif

// FUNCTION: 0x004fbbf0
void cSC4AutomataManager::Pause()
{
    mbPaused = true;
}

// FUNCTION: 0x004fbc00
void cSC4AutomataManager::Resume()
{
    mbPaused = false;
}

// FUNCTION: 0x00505350
bool cSC4AutomataManager::HandleViewZoomChanged(uint32_t from, uint32_t to)
{
    if (from != to) {
        HandleViewChanged();
    }
    return true;
}

// FUNCTION: 0x00505400
bool cSC4AutomataManager::IsCameraFollowUpdating()
{
    return gbB21b94;
}

// FUNCTION: 0x00505480
bool cSC4AutomataManager::QueryInterface(uint32_t iid, void** pv)
{
    void** ppv = pv;
    switch (iid) {
    case 1:
        *ppv = static_cast<cUnk00a8298c*>(this);
        AddRef();
        return true;
    case 0x98f9bf4:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<cUnk00aaaa9c*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<cUnk00a80784*>(this);
        AddRef();
        return true;
    default:
        break;
    }
    return false;
}

// A 3D view: slot 24 hands out the camera.
struct View3D_a95880 {
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
    virtual struct Camera_a95880* Fn24();
};

// The camera: slot 5 says what kind of camera it is.
struct Camera_a95880 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual uint32_t Fn05();
};

// GLOBAL: 0x00b43dc4
extern View3D_a95880* gpB43dc4;

// FUNCTION: 0x00506940
bool cSC4AutomataManager::IsDrivingMode()
{
    Camera_a95880* camera = gpB43dc4->Fn24();
    if (camera != 0 && camera->Fn05() == 0x2b709676) {
        return true;
    }
    return false;
}

// The view utilities: one STUB method tells whether a point is on screen.
struct ViewUtil_a95880 {
    // STUB: 0x007f7e50
    bool IsPointInViewFrustum(const float* point);
};

// GLOBAL: 0x00b43dd8
extern ViewUtil_a95880* gpB43dd8;

// An automaton: slot 7 reads its position.
struct AutoPos_a95880 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Fn07(void* out);
};

// FUNCTION: 0x00507ac0
bool cSC4AutomataManager::IsAutomatonOnscreen(void* pAutomaton)
{
    float where[3] = { gfB21ba4, gfB21ba4, gfB21ba4 };
    static_cast<AutoPos_a95880*>(pAutomaton)->Fn07(where);
    return gpB43dd8->IsPointInViewFrustum(where);
}

// One exemplar record: 0x6c bytes with a three-word key at +0x10.
struct ExemplarRec_a95880 {
    uint8_t mPad0[0x10];
    uint32_t mnType;
    uint32_t mnGroup;
    uint32_t mnInstance;
    uint8_t mPad1c[0x6c - 0x1c];
};

#ifdef OB_DRAFTS
// CLOSE: 0x00507b00 score 49
void* cSC4AutomataManager::FindExemplarFromModelKey(void* pKey)
{
    const uint32_t* key = static_cast<const uint32_t*>(pKey);
    ExemplarRec_a95880* it = static_cast<ExemplarRec_a95880*>(mpExemplarsBegin);
    ExemplarRec_a95880* end = static_cast<ExemplarRec_a95880*>(mpExemplarsEnd);
    for (; it != end; ++it) {
        if (it->mnType == key[0] && it->mnGroup == key[1] && it->mnInstance == key[2]) {
            return it;
        }
    }
    return 0;
}
#endif

// FUNCTION: 0x00507b50
unsigned int cSC4AutomataManager::Release()
{
    if (mnRefCount > 1) {
        --mnRefCount;
        return mnRefCount;
    }
    Shutdown();
    delete this;
    return 0;
}

// A list node: next link, previous link, value.
struct Node_a95880 {
    Node_a95880* mpNext;
    Node_a95880* mpPrev;
    struct Controllable_a95880* mpValue;
};

// An automaton the manager notifies when a controller goes away: slot 81 takes the controller.
struct Controllable_a95880 {
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
    virtual void Fn81(void* controller);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050a670 score 9
bool cSC4AutomataManager::HandleRemoveController(void* pController)
{
    Node_a95880* head = static_cast<Node_a95880*>(mpAutomataList);
    Node_a95880* node = head->mpNext;
    if (node != head) {
        do {
            if (node->mpValue != 0) {
                node->mpValue->Fn81(pController);
            }
            node = node->mpNext;
        } while (node != static_cast<Node_a95880*>(mpAutomataList));
    }
    return true;
}
#endif

// The automaton group tree at +0xa24.
struct GroupTree_a95880 {
    uint32_t mpRoot;
    // STUB: 0x00497520
    void Find(void* outIter, const uint32_t* key);
};

// FUNCTION: 0x0050c300
bool cSC4AutomataManager::CanCreateGroup(uint32_t group)
{
    GroupTree_a95880* tree = reinterpret_cast<GroupTree_a95880*>(reinterpret_cast<char*>(this) + 0xa24);
    uint32_t it;
    tree->Find(&it, &group);
    return it != tree->mpRoot;
}

// FUNCTION: 0x005108e0
bool cSC4AutomataManager::Slot04_a80784(void* pOccupant)
{
    AutoPos_a95880* occupant = static_cast<AutoPos_a95880*>(pOccupant);
    uint32_t where;
    occupant->Fn07(&where);
    return Fn0050feb0(pOccupant, where);
}

// ---- batch 2 ----

// The view rectangle of the 3D view, four floats.
struct Rect4_a95880 {
    float f0;
    float f1;
    float f2;
    float f3;
};

// (gpB43dd8 is declared above; the view utilities keep the current rectangle at +0x3ec)

#ifdef OB_DRAFTS
// CLOSE: 0x00506cd0 score 2
bool cSC4AutomataManager::HandleViewChanged()
{
    Rect4_a95880* current = reinterpret_cast<Rect4_a95880*>(&mfView14[0]);
    Rect4_a95880* previous = reinterpret_cast<Rect4_a95880*>(&mfView24[0]);
    *previous = *current;
    *current = *reinterpret_cast<Rect4_a95880*>(reinterpret_cast<char*>(gpB43dd8) + 0x3ec);
    current->f0 = current->f0 - 64.0f;
    current->f1 = current->f1 - 64.0f;
    current->f2 = current->f2 + 64.0f;
    current->f3 = current->f3 + 64.0f;
    UpdateZoomAndRotation();
    return true;
}
#endif

// The object behind an automaton's slot 5: slot 33 reports capability flags.
struct ObjQ_a95880 {
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
    virtual uint32_t Fn33();
};

// An automaton as the manager adds it: slot 5 hands out the object behind it, slots 70 and 71 place it.
struct AutoPlace_a95880 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual ObjQ_a95880* Fn05();
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
    virtual bool Fn70(bool on);
    virtual bool Fn71(bool on);
    uint8_t mPad04[0x2f];
    uint8_t mFlags33;
};

// FUNCTION: 0x005073d0
bool cSC4AutomataManager::AddAutomatonInternal(void* pAutomaton)
{
    AutoPlace_a95880* a = static_cast<AutoPlace_a95880*>(pAutomaton);
    if (a != 0) {
        if (a->Fn05()->Fn33() & 4) {
            if (!(a->mFlags33 & 1)) {
                if (a->Fn70(true)) {
                    if (!(a->mFlags33 & 2)) {
                        a->Fn71(true);
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

// FUNCTION: 0x00507430
bool cSC4AutomataManager::RemoveAutomatonInternal(void* pAutomaton)
{
    AutoPlace_a95880* a = static_cast<AutoPlace_a95880*>(pAutomaton);
    if (a != 0) {
        if (a->mFlags33 & 2) {
            a->Fn71(false);
        }
        if (a->mFlags33 & 1) {
            a->Fn70(false);
        }
    }
    return true;
}

// The message the manager posts (vtable 0x00acec00, 0x2c bytes from the pool).
// STUB: 0x009133da
void* Fn009133da_a95880(uint32_t size);

struct Msg_a95880 {
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
    virtual void Pad11();
    virtual void Fn12(uint32_t);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Fn16(uint32_t);
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Fn21(uint32_t);
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    Msg_a95880();
    static void* operator new(size_t size) { return Fn009133da_a95880(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// FUNCTION: 0x00507b80
void cSC4AutomataManager::PostNotificationMessage(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    cIGZMessageServer2* server = gpB43ccc;
    Msg_a95880* msg = new Msg_a95880;
    msg->AddRef();
    msg->Fn05(a);
    msg->Fn12(b);
    msg->Fn16(c);
    msg->Fn21(d);
    server->MessagePost(msg, false);
    msg->Release();
}

// The group manager at +0xa80: slot 6 finds a group template by id.
struct GroupMgr_a95880 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual Group_a95880* Fn06(uint32_t id);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00505410 score 39
uint32_t cSC4AutomataManager::GetSourceBuildingCountForAutomataGroup(uint32_t id)
{
    uint32_t result = 0;
    GroupMgr_a95880* mgr = static_cast<GroupMgr_a95880*>(mpGroupMgr);
    if (mgr != 0) {
        Group_a95880* group = mgr->Fn06(id);
        if (group != 0) {
            if (group->mn6c != 0) {
                return GetSourceBuildingCount(group->mn6c);
            }
            if (group->mpParent != 0) {
                return GetSourceBuildingCount(group->mpParent->Fn00505330());
            }
            return GetSourceBuildingCount(0);
        }
    }
    return result;
}
#endif

// ---- batch 3 ----

// What the zoom check asks about: the record behind slot 67 keeps a group id at +0x10.
struct Tail_a95880 {
    uint8_t mPad[0x10];
    uint32_t mnGroup;
};

struct KeyObj_a95880 {
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
    virtual struct Tail_a95880* Fn67();
};

// The simulator object at 0xb21d74: a key object sits at +0x30.
struct SimSlot_a95880 {
    uint8_t mPad[0x30];
    KeyObj_a95880* mpKey30;
};

// GLOBAL: 0x00b21d74
extern SimSlot_a95880* gpB21d74;

struct ZoomUser_a95880 {
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
    virtual void Fn74(int32_t zoom, int32_t rotation);
};

// STUB: 0x007f66a0
struct ZoomQuery_a95880 {
    // STUB: 0x007f66a0
    void GetZoomAndRotation(int32_t* zoom, int32_t* rotation);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050a520 score 36
bool cSC4AutomataManager::UpdateZoomAndRotation()
{
    int32_t zoom;
    int32_t rotation;
    reinterpret_cast<ZoomQuery_a95880*>(gpB43dd8)->GetZoomAndRotation(&zoom, &rotation);
    bool good = zoom >= static_cast<int32_t>(mnMinZoom);
    if (!good) {
        if (gpB21d74 != 0 && gpB21d74->mpKey30 != 0) {
            good = CanCreateGroup(gpB21d74->mpKey30->Fn67()->mnGroup);
        }
    }
    if (good) {
        if (!mbActive) {
            Activate(true);
        }
    } else if (mbActive) {
        Activate(false);
    }
    if (mbActive) {
        Node_a95880* head = static_cast<Node_a95880*>(mpAutomataList);
        for (Node_a95880* node = head->mpNext; node != head; node = node->mpNext) {
            reinterpret_cast<ZoomUser_a95880*>(node->mpValue)->Fn74(zoom, rotation);
        }
    }
    return true;
}
#endif

struct Closable_a95880 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual void Pad03();
    virtual void Fn04();
};

struct Ccm_a95880 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Fn04(uint32_t);
};

// GLOBAL: 0x00b21b88
extern int32_t gnB21b88;

// GLOBAL: 0x00b21b98
extern Closable_a95880* gpB21b98;

// The pending-work object at 0xb21ba0 has a clear routine.
struct Pending_a95880 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    // STUB: 0x0053c940
    void Fn0053c940();
};

// GLOBAL: 0x00b21ba0
extern Pending_a95880* gpB21ba0;

// GLOBAL: 0x00b43cac
extern Ccm_a95880* gpB43cac;

// FUNCTION: 0x00506600
bool cSC4AutomataManager::StaticShutdown()
{
    if (--gnB21b88 == 0) {
        SetCameraFollow(0);
        if (gpB21b98 != 0) {
            gpB21b98->Fn04();
            gpB21b98->Release();
            gpB21b98 = 0;
        }
        if (gpB21ba0 != 0) {
            gpB21ba0->Fn0053c940();
            gpB21ba0->Release();
            gpB21ba0 = 0;
        }
        Ccm_a95880* ccm = gpB43cac;
        if (ccm != 0) {
            ccm->Fn04(0xe97fcbc8);
            ccm->Fn04(0xe97fcbc9);
            ccm->Fn04(0xb70c96d);
            ccm->Fn04(0x6bb354c7);
            ccm->Fn04(0xcc478b79);
        }
    }
    return true;
}

// ---- batch 4 ----

struct Counted_a95880 {
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
    virtual void Fn13(uint32_t);
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
    virtual bool Fn31(uint32_t);
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
    virtual uint8_t Fn63();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050a740 score 37
bool cSC4AutomataManager::AdjustCountForAutomaton(uint8_t priority)
{
    bool result = false;
    if (mnCount48 < mnLimit40) {
        if (priority > 0) {
            Node_a95880* head = static_cast<Node_a95880*>(mpAutomataList);
            for (Node_a95880* node = head->mpNext; node != static_cast<Node_a95880*>(mpAutomataList); node = node->mpNext) {
                Counted_a95880* a = reinterpret_cast<Counted_a95880*>(node->mpValue);
                if (a->Fn63() < priority) {
                    a->Fn13(0);
                    result = true;
                    return result;
                }
            }
        }
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050aa60 score 26
void cSC4AutomataManager::SetMaxCount(uint32_t count)
{
    int32_t n = static_cast<int32_t>(count);
    if (n < 0) {
        n = 0;
    } else if (n > 5000) {
        n = 5000;
    }
    if (n != static_cast<int32_t>(mnMaxCount)) {
        Node_a95880* node = static_cast<Node_a95880*>(mpAutomataList)->mpNext;
        if (node != static_cast<Node_a95880*>(mpAutomataList)) {
            do {
                if (static_cast<uint32_t>(n) >= mnCount48) {
                    break;
                }
                Counted_a95880* a = reinterpret_cast<Counted_a95880*>(node->mpValue);
                node = node->mpNext;
                if (!a->Fn31(0x200000)) {
                    if (a->Fn63() < 0xff) {
                        RemoveAutomatonInternal(a);
                    }
                }
            } while (node != static_cast<Node_a95880*>(mpAutomataList));
        }
        mnMaxCount = n;
        mnLimit40 = static_cast<int32_t>(n * 1.25);
    }
}
#endif

struct Landfill_a95880 {
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
    virtual uint32_t Fn11();
};

// GLOBAL: 0x00b43d28
extern Landfill_a95880* gpB43d28;

// The tuning tree at +0xa64 maps a kind to a record whose count sits at +8.
struct CountNode_a95880 {
    uint8_t mPad[8];
    uint32_t mnCount;
};

struct CountTree_a95880 {
    // STUB: 0x006f1530
    void Find(void* outIter, const uint32_t* key);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050be30 score 31
uint32_t cSC4AutomataManager::GetSourceBuildingCount(uint32_t kind)
{
    uint32_t result = 0;
    if (kind == 0x1402 || kind == 0x1406) {
        if (gpB43d28 != 0) {
            return gpB43d28->Fn11();
        }
        return result;
    }
    CountNode_a95880* node;
    reinterpret_cast<CountTree_a95880*>(reinterpret_cast<char*>(this) + 0xa64)->Find(&node, &kind);
    if (node != 0) {
        return node->mnCount;
    }
    return result;
}
#endif
