#include <cstddef>
#include <cmath>

#include "classes/cSC4AutomataController.h"
#include "game/Globals.h"

// Views of the objects the controller talks to: only the slots used here are named, the rest are padding.
struct Terrain_a95d90 {
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
    virtual float GetHeight(float x, float z);
};
struct Heights_a95d90 {
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
    virtual float GetHeight(float x, float z);
};
struct Lot_a95d90 {
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
    virtual void GetBounds(int32_t* pBounds);
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual uint32_t GetFacing();
};
struct LotMgr_a95d90 {
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
    virtual void* GetLot(void* pOccupant);
};
struct Occupant_a95d90 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void GetPosition(void* pVec);
    virtual void Pad09();
    virtual void GetBounds(void* pLo, void* pHi);
};
struct Automaton_a95d90 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void SetPosition(void* pVec);
    virtual void GetPosition(void* pVec);
    virtual void Pad12();
    virtual void Slot13(uint32_t n);
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual float GetScale();
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
    virtual Automaton_a95d90* GetOwner();
    virtual void SetQueueLeader(void* pLeader);
};
struct ScriptSys_a95d90 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};
struct Effects_a95d90 {
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
    virtual bool CheckEffect(uint32_t nEffect);
};
struct View3DWin_a95d90 {
    virtual bool QueryInterface(uint32_t nIid, void** ppOut);
    virtual void Pad01();
    virtual void Release();
};
struct SoundA_a95d90 {
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
    virtual void Post(uint32_t nMsg, uint32_t nSfx, void* pObj, uint32_t a, uint32_t b);
};
struct SoundB_a95d90 {
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
    virtual void Post(uint32_t nMsg, void* pObj, int32_t x, int32_t y, int32_t z);
};
struct Random_a95d90 {
    uint8_t mPad[0x14];
    // STUB: 0x00913a5c
    void Init(uint32_t nSeed);
    // STUB: 0x009136b1
    uint32_t Uniform(uint32_t n);
};
struct Template_a95d90 {
    uint8_t mPad00[0x20];
    float mfRadius;
    uint8_t mPad24[0x14];
    uint8_t* mpBehBegin;
    uint8_t* mpBehEnd;
    uint8_t mPad40[4];
    void* mpTriggersA;
    void* mpTriggersB;
    float mfLifetime;
    float mfAnimLength;
    uint32_t mnCapacity;
    uint32_t mnFlags;
    uint8_t mPad5c[4];
    uint32_t* mpSfxBegin;
    uint32_t* mpSfxEnd;
};
struct Behavior_a95d90 {
    int32_t mnType;
    float mfRange;
};
struct ListNode_a95d90 {
    ListNode_a95d90* mpNext;
    ListNode_a95d90* mpPrev;
    void* mpData;
};
struct ValueNode_a95d90 {
    ValueNode_a95d90* mpNext;
    ValueNode_a95d90* mpPrev;
    uint32_t mnValue;
};
struct IStream_a95d90 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void ReadVersion(uint32_t* pnVersion);
    virtual void Pad08();
    virtual void ReadUInt32(uint32_t* pn);
    virtual void Pad10();
    virtual void Pad11();
    virtual void ReadFloat(float* pf);
    virtual void Pad13();
    virtual void Pad14();
    virtual void ReadString(void* pStr);
    virtual void Pad16();
    virtual void Pad17();
    virtual bool GetError();
};
struct OStream_a95d90 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void WriteVersion(uint32_t nVersion);
    virtual void Pad08();
    virtual void WriteUInt32(uint32_t n);
    virtual void Pad10();
    virtual void Pad11();
    virtual void WriteFloat(float f);
    virtual void Pad13();
    virtual void Pad14();
    virtual void WriteString(void* pStr);
    virtual void Pad16();
    virtual void Pad17();
    virtual bool GetError();
};
struct String_a95d90 {
    uint32_t mnVtbl;
    char* mpBegin;
    char* mpEnd;
    char* mpCap;
};

// GLOBAL: 0x00b227cc
extern float gB227cc;
// GLOBAL: 0x00b43cf4
extern Terrain_a95d90* gpB43cf4_a95d90;
// GLOBAL: 0x00b43cb8
extern void* gpB43cb8_a95d90;
// GLOBAL: 0x00b43dc8
extern View3DWin_a95d90* gpB43dc8_a95d90;

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t nSize);
// STUB: 0x0090cf63
void Fn0090cf63(void* p);
// STUB: 0x005d99a0
void Fn005d99a0(void* pStream, void* pObj);
// STUB: 0x005da580
void Fn005da580(void* pStream, void* pVec);
// STUB: 0x005da550
void Fn005da550(void* pStream, void* pVec);
// STUB: 0x005d9730
void Fn005d9730(void* pStream, uint32_t nGuid, void* ppOut, uint32_t nZero);
// STUB: 0x005d76a0
float Fn005d76a0(const float* pA, const float* pB);
struct ViewUtil_a95d90 {
    // STUB: 0x007f7e50
    bool IsPointInViewFrustum(const float* pPoint);
};

// GLOBAL: 0x00b43dd8
extern ViewUtil_a95d90* gpB43dd8_a95d90;

struct QInfo_a95d90;
struct HashNode_a95d90;
struct HashResult_a95d90;
struct HashPair_a95d90;

// The record the automata controller manager keeps per occupant: a queue of automata and the point they queue at.
struct QInfo_a95d90 {
    ListNode_a95d90* mpHead;
    uint32_t mn04;
    float mfPointX;
    float mfPointY;
    float mfPointZ;
    float mfDirX;
    float mfDirY;
    float mfDirZ;
    bool mbValid;
    // STUB: 0x00517340
    QInfo_a95d90* Fn00517340();
    // STUB: 0x00518a40
    QInfo_a95d90* Fn00518a40(const QInfo_a95d90* pSrc);
    // STUB: 0x005184e0
    void AddToQueue(void* pAutomaton);
    // STUB: 0x005172d0
    void RemoveFromQueue(void* pAutomaton);
    // STUB: 0x00516070
    void InitQueuePoint(void* pOccupant);
    // STUB: 0x005650a0
    void Fn005650a0();
    // STUB: 0x006f1570
    void Fn006f1570(ListNode_a95d90* pPos, ListNode_a95d90* pFirst, ListNode_a95d90* pLast, void* pTmp);
};
struct HashNode_a95d90 {
    HashNode_a95d90* mpNext;
    void* mpKey;
    QInfo_a95d90 mValue;
};
struct HashPair_a95d90 {
    void* mpKey;
    QInfo_a95d90 mValue;
};
struct HashResult_a95d90 {
    HashNode_a95d90* mpNode;
    void* mpTable;
    bool mbInserted;
};
struct HashTable_a95d90 {
    uint32_t mn00;
    HashNode_a95d90** mpBegin;
    HashNode_a95d90** mpEnd;
    uint32_t mn0c;
    uint32_t mnCount;
    // STUB: 0x0051a900
    void Fn0051a900(HashResult_a95d90* pOut, HashPair_a95d90* pVal);
    // STUB: 0x004f0940
    void Fn004f0940(uint32_t nSize);
};
struct Manager_a95d90 {
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
    virtual void Activate(void* pController);
    uint8_t mPad04[0x68];
    HashTable_a95d90 mTable;
    // STUB: 0x0051b9d0
    QInfo_a95d90* GetControllerQInfo(void* pOccupant, bool bCreate);
};

#define TPL_a95d90 (reinterpret_cast<Template_a95d90*>(mpTemplate))
#define OCC_a95d90 (reinterpret_cast<Occupant_a95d90*>(mpOccupant))
#define MGR_a95d90 OB_PTR(Manager_a95d90, gpB43cec->GetAutomataControllerManager())

// FUNCTION: 0x00514d90
void cSC4AutomataController::DoAnimationTick(float fMs, uint32_t /*b*/, void* /*c*/)
{
    float dt = fMs * 0.001f;
    if (Slot12_a95d90(1)) {
        if (Slot12_a95d90(0x400)) {
            mfAnimTime += dt;
            if (mpTemplate) {
                if (TPL_a95d90->mfAnimLength <= mfAnimTime) {
                    Slot13_a95d90(0x400, false);
                }
            }
        }
        if (!Slot12_a95d90(0x400) && mfLifetime > 0.0f) {
            mfAge += dt;
            if (mfAge > mfLifetime) {
                Activate(false);
            }
        }
    }
}

// FUNCTION: 0x00514e30
void cSC4AutomataController::NotifySourceDataChanged()
{
    if (mpTemplate) {
        Slot13_a95d90(TPL_a95d90->mnFlags, true);
        Slot13_a95d90(2, true);
        mfLifetime = TPL_a95d90->mfLifetime;
        mfAnimTime = 0.0f;
    }
}




// FUNCTION: 0x00515a40
void cSC4AutomataController::GetPosition(void* pOut)
{
    if (mpOccupant && !Slot12_a95d90(0x20)) {
        OCC_a95d90->GetPosition(pOut);
        return;
    }
    float* p = static_cast<float*>(pOut);
    p[0] = mfPosX;
    p[1] = mfPosY;
    p[2] = mfPosZ;
}






// FUNCTION: 0x00516aa0
void cSC4AutomataController::Activate(bool bOn)
{
    if (mbInitialised) {
        if (Slot12_a95d90(1) != bOn) {
            Slot13_a95d90(1, bOn);
            Manager_a95d90* m = MGR_a95d90;
            if (bOn) {
                m->Activate(this);
            }
            PlaySFX(bOn);
            HandleViewChanged();
            mfAnimTime = 0.0f;
            Slot13_a95d90(0x400, false);
            if (bOn && mpTemplate) {
                if (TPL_a95d90->mfAnimLength > 0.0f) {
                    Slot13_a95d90(0x400, true);
                }
            }
        }
    }
}




// FUNCTION: 0x00517430
void cSC4AutomataController::SetTemplate(void* pTemplate)
{
    mpTemplate = pTemplate;
    if (pTemplate) {
        if (mpStrBegin != mpStrEnd) {
            *mpStrBegin = 0;
            mpStrEnd = mpStrBegin;
        }
        mfLifetime = TPL_a95d90->mfLifetime;
        mnFlags = TPL_a95d90->mnFlags;
    }
}

// FUNCTION: 0x00517df0
void* cSC4AutomataController::GetTemplateName()
{
    if (mpTemplate) {
        return reinterpret_cast<uint8_t*>(mpTemplate) + 4;
    }
    return &mnStrVtbl28;
}

// FUNCTION: 0x00517e00
float cSC4AutomataController::GetRadius()
{
    if (mpTemplate) {
        return TPL_a95d90->mfRadius;
    }
    return 0.0f;
}

// FUNCTION: 0x00517e20
bool cSC4AutomataController::IsActive()
{
    if (Slot12_a95d90(1) && Slot12_a95d90(2) && Slot12_a95d90(4) && !Slot12_a95d90(0x400)) {
        return true;
    }
    return false;
}

// FUNCTION: 0x00517e60
bool cSC4AutomataController::Slot12_a95d90(uint32_t nFlag)
{
    return (mnFlags & nFlag) != 0;
}


// FUNCTION: 0x00517ea0
uint32_t cSC4AutomataController::IsExpired()
{
    if (mfLifetime > 0.0f && mfAge >= mfLifetime) {
        return 1;
    }
    return 0;
}


// FUNCTION: 0x00517f10
unsigned int cSC4AutomataController::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    FinalRelease();
    return 0;
}

// FUNCTION: 0x00517f40
void cSC4AutomataController::SetOccupant(void* pOccupant)
{
    Occupant_a95d90* pNew = static_cast<Occupant_a95d90*>(pOccupant);
    Occupant_a95d90* pOld = OCC_a95d90;
    if (pNew != pOld) {
        if (pNew) {
            pNew->AddRef();
        }
        mpOccupant = pNew;
        if (pOld) {
            pOld->Release();
        }
    }
}

// FUNCTION: 0x00518330
bool cSC4AutomataController::IsTickable()
{
    return Slot12_a95d90(1);
}

// FUNCTION: 0x00519340
void cSC4AutomataController::FinalRelease()
{
    Shutdown();
    Fn00517f80();
    ::operator delete(this);
}

// FUNCTION: 0x00602f90
void cSC4AutomataController::SetPosition(void* pVec)
{
    const float* v = static_cast<const float*>(pVec);
    mfPosX = v[0];
    mfPosY = v[1];
    mfPosZ = v[2];
}

// FUNCTION: 0x008ae800
uint32_t cSC4AutomataController::AddRef()
{
    return ++mnRefCount;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00517fd0 score 17
bool cSC4AutomataController::Slot03_a80784(void* pStream)
{
    OStream_a95d90* os = static_cast<OStream_a95d90*>(pStream);
    os->WriteVersion(5);
    Fn005d99a0(os, mpOccupant);
    if (mpTemplate) {
        os->WriteString(reinterpret_cast<uint8_t*>(mpTemplate) + 4);
    } else {
        String_a95d90 s;
        s.mpBegin = 0;
        s.mpEnd = 0;
        s.mpCap = 0;
        char* buf = static_cast<char*>(Fn0090cf54(8));
        s.mpBegin = buf;
        s.mpEnd = buf;
        s.mpCap = buf + 8;
        *buf = 0;
        s.mnVtbl = 0xa80810;
        os->WriteString(&s);
        s.mnVtbl = 0xa80810;
        if (s.mpBegin) {
            Fn0090cf63(s.mpBegin);
        }
    }
    Fn005da580(os, &mfPosX);
    os->WriteFloat(mfAge);
    os->WriteFloat(mfLifetime);
    os->WriteUInt32(mnSfxId);
    os->WriteUInt32(mnFlags);
    os->WriteUInt32(mnAutomataCount);
    ListNode_a95d90* head = reinterpret_cast<ListNode_a95d90*>(mpAutomata);
    for (ListNode_a95d90* n = head->mpNext; n != head; n = n->mpNext) {
        Fn005d99a0(os, n->mpData);
        head = reinterpret_cast<ListNode_a95d90*>(mpAutomata);
    }
    return !os->GetError();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005180e0 score 78
bool cSC4AutomataController::Slot04_a80784(void* pStream)
{
    IStream_a95d90* is = static_cast<IStream_a95d90*>(pStream);
    uint32_t nVersion;
    is->ReadVersion(&nVersion);
    if (mpOccupant) {
        Occupant_a95d90* o = OCC_a95d90;
        mpOccupant = 0;
        o->Release();
    }
    Fn005d9730(is, 0x26bb767e, &mpOccupant, 0);
    is->ReadString(&mnStrVtbl28);
    Fn005da550(is, &mfPosX);
    is->ReadFloat(&mfAge);
    is->ReadFloat(&mfLifetime);
    is->ReadUInt32(&mnSfxId);
    is->ReadUInt32(&mnFlags);
    is->ReadUInt32(&mnAutomataCount);
    for (uint32_t i = 0; i < mnAutomataCount; ++i) {
        void* pAuto;
        pAuto = 0;
        Fn005d9730(is, 0xa9b40f05, &pAuto, 0);
        ListNode_a95d90* head = reinterpret_cast<ListNode_a95d90*>(mpAutomata);
        ListNode_a95d90* n = static_cast<ListNode_a95d90*>(Fn0090cf54(0xc));
        n->mpData = pAuto;
        n->mpPrev = head->mpPrev;
        n->mpNext = head;
        n->mpPrev->mpNext = n;
        head->mpPrev = n;
    }
    return !is->GetError();
}
#endif







// FUNCTION: 0x00517340
QInfo_a95d90* QInfo_a95d90::Fn00517340()
{
    mpHead = 0;
    ListNode_a95d90* head = static_cast<ListNode_a95d90*>(Fn0090cf54(0xc));
    head->mpNext = head;
    head->mpPrev = head;
    mpHead = head;
    mfPointX = gB227cc;
    mfPointY = gB227cc;
    mfPointZ = gB227cc;
    mfDirX = gB227cc;
    mfDirY = gB227cc;
    mfDirZ = gB227cc;
    return this;
}






