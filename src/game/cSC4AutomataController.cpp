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

#ifdef OB_DRAFTS
// CLOSE: 0x00514f60 score 8
bool cSC4AutomataController::QueryInterface(uint32_t nIid, void** ppOut)
{
    void** pp = ppOut;
    if (nIid == 1 || nIid == 0x6a1857f8) {
        *pp = this;
        AddRef();
        return true;
    }
    if (nIid == 0xe4fda3d4) {
        *pp = static_cast<cUnk00a80784*>(this);
        AddRef();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00515770 score 58
void cSC4AutomataController::PlaySFX(bool bOn)
{
    void* ss = gpB43cb8_a95d90;
    if (!ss) {
        return;
    }
    if (bOn) {
        if (!mpTemplate) {
            return;
        }
        if (TPL_a95d90->mpSfxBegin == TPL_a95d90->mpSfxEnd) {
            return;
        }
        Random_a95d90 rnd;
        rnd.Init(0xffffffff);
        uint32_t n = TPL_a95d90->mpSfxEnd - TPL_a95d90->mpSfxBegin;
        uint32_t idx = rnd.Uniform(n);
        mnSfxId = TPL_a95d90->mpSfxBegin[idx];
        float v[3];
        v[0] = gB227cc;
        v[1] = gB227cc;
        v[2] = gB227cc;
        GetPosition(v);
        reinterpret_cast<SoundA_a95d90*>(ss)->Post(0xea451903, mnSfxId, this, 0, 0);
        reinterpret_cast<SoundB_a95d90*>(ss)->Post(0xca45190f, this, static_cast<int32_t>(v[0]),
                                                    static_cast<int32_t>(v[1]), static_cast<int32_t>(v[2]));
    } else if (mnSfxId) {
        reinterpret_cast<SoundB_a95d90*>(ss)->Post(0x6a451908, this, 0, 0, 0);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00515870 score 95
bool cSC4AutomataController::HandleViewChanged()
{
    ViewUtil_a95d90* vu = gpB43dd8_a95d90;
    if (vu && gpB43cf4_a95d90) {
        bool bVisible = false;
        float lo[3];
        float hi[3];
        float pos[3];
        float c[3];
        if (!Slot12_a95d90(0x200)) {
            GetBoundingBox(lo, hi);
            pos[0] = gB227cc;
            pos[1] = gB227cc;
            pos[2] = gB227cc;
            GetPosition(pos);
            if (gpB43cec->LocationIsInBounds(lo[0], lo[2])) {
                lo[1] = gpB43cf4_a95d90->GetHeight(lo[0], lo[2]);
            } else {
                lo[1] = pos[1];
            }
            if (gpB43cec->LocationIsInBounds(hi[0], hi[2])) {
                hi[1] = gpB43cf4_a95d90->GetHeight(hi[0], hi[2]);
            } else {
                hi[1] = pos[1];
            }
            c[0] = gB227cc;
            c[1] = gB227cc;
            c[2] = gB227cc;
            GetPosition(c);
            if (vu->IsPointInViewFrustum(c)) {
                bVisible = true;
            } else {
                c[0] = lo[0];
                c[1] = lo[1];
                c[2] = lo[2];
                if (vu->IsPointInViewFrustum(c)) {
                    bVisible = true;
                } else {
                    c[0] = hi[0];
                    if (vu->IsPointInViewFrustum(c)) {
                        bVisible = true;
                    } else {
                        c[0] = hi[0];
                        c[1] = hi[1];
                        c[2] = hi[2];
                        if (vu->IsPointInViewFrustum(c)) {
                            bVisible = true;
                        } else {
                            c[0] = lo[0];
                            if (vu->IsPointInViewFrustum(c)) {
                                bVisible = true;
                            }
                        }
                    }
                }
            }
        } else {
            bVisible = true;
        }
        Slot13_a95d90(4, bVisible);
        return true;
    }
    return true;
}
#endif

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

#ifdef OB_DRAFTS
// CLOSE: 0x00515a80 score 38
bool cSC4AutomataController::IsPointWithinRadius(void* pPoint, void* pOut)
{
    float* p = static_cast<float*>(pPoint);
    float* out = static_cast<float*>(pOut);
    bool bResult = false;
    float lo[3];
    float hi[3];
    GetOccupantBoundingBox(lo, hi);
    float r = GetRadius();
    if (lo[0] - r <= p[0] && lo[2] - r <= p[2] && p[0] <= hi[0] + r && p[2] <= hi[2] + r) {
        if (Slot12_a95d90(0x1000)) {
            float h = gpB43cf4_a95d90->GetHeight(p[0], p[2]);
            if (!(p[1] <= h + 5.0f)) {
                return false;
            }
        }
        bResult = true;
        if (out) {
            float q[3];
            if (Slot12_a95d90(0x10)) {
                GetLotFacingPoint(q);
            } else {
                GetPosition(q);
            }
            float pt[2];
            float pp[2];
            float hit[2];
            pt[0] = q[0];
            pt[1] = q[2];
            pp[0] = p[0];
            pp[1] = p[2];
            const float* from = pt;
            if (Fn00514e70(pt, pp, hit)) {
                from = hit;
            }
            *out = Fn005d76a0(from, pp);
        }
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00515bd0 score 141
void cSC4AutomataController::GetBoundingBox(void* pLo, void* pHi)
{
    float* lo = static_cast<float*>(pLo);
    float* hi = static_cast<float*>(pHi);
    GetOccupantBoundingBox(lo, hi);
    float r = GetRadius();
    lo[0] = lo[0] - r;
    hi[0] = hi[0] + r;
    lo[2] = lo[2] - r;
    hi[2] = hi[2] + r;
    float sx = gpB43cec->SizeX();
    float sz = gpB43cec->SizeZ();
    float v = lo[0];
    float o = 0.0f;
    if (0.0f <= v) {
        o = sx;
        if (v <= sx) {
            o = v;
        }
    }
    lo[0] = o;
    v = lo[2];
    o = 0.0f;
    if (0.0f <= v) {
        o = sz;
        if (v <= sz) {
            o = v;
        }
    }
    lo[2] = o;
    v = hi[0];
    o = 0.0f;
    if (0.0f <= v) {
        o = sx;
        if (v <= sx) {
            o = v;
        }
    }
    hi[0] = o;
    v = hi[2];
    o = 0.0f;
    if (0.0f <= v) {
        o = sz;
        if (v <= sz) {
            o = v;
        }
    }
    hi[2] = o;
    Terrain_a95d90* t = OB_PTR(Terrain_a95d90, gpB43cec->GetTerrain());
    lo[1] = t->GetHeight(lo[0], lo[2]);
    hi[1] = t->GetHeight(hi[0], hi[2]);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00515d20 score 10
void* cSC4AutomataController::GetOccupantLot()
{
    LotMgr_a95d90* lm = OB_PTR(LotMgr_a95d90, gpB43cec->GetLotManager());
    void* lot = 0;
    if (lm && mpOccupant) {
        return lm->GetLot(mpOccupant);
    }
    return lot;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00516850 score 55
bool cSC4AutomataController::Init()
{
    if (!mbInitialised) {
        mbInitialised = true;
        mbFlag27 = false;
        mbFlag25 = false;
        mbFlag26 = false;
        mbFlag24 = false;
        ScriptSys_a95d90* pNew = OB_PTR(ScriptSys_a95d90, gpB43cec->GetAutomataScriptSystem());
        ScriptSys_a95d90* pOld = reinterpret_cast<ScriptSys_a95d90*>(mpScriptSystem);
        if (pNew != pOld) {
            if (pNew) {
                pNew->AddRef();
            }
            mpScriptSystem = pNew;
            if (pOld) {
                pOld->Release();
            }
        }
        if (Slot12_a95d90(0x20)) {
            LotMgr_a95d90* lm = OB_PTR(LotMgr_a95d90, gpB43cec->GetLotManager());
            Lot_a95d90* lot = 0;
            if (lm && mpOccupant) {
                lot = reinterpret_cast<Lot_a95d90*>(lm->GetLot(mpOccupant));
            }
            if (lot) {
                int32_t b[4];
                lot->GetBounds(b);
                mfPosX = static_cast<float>((b[2] - b[0] + 1) << 4) * 0.5f + (b[0] << 4);
                mfPosZ = static_cast<float>((b[3] - b[1] + 1) << 4) * 0.5f + (b[1] << 4);
                if (gpB43cec->LocationIsInBounds(mfPosX, mfPosZ)) {
                    mfPosY = gpB43cf4_a95d90->GetHeight(mfPosX, mfPosZ);
                } else if (mpOccupant) {
                    float v[3];
                    v[0] = gB227cc;
                    v[1] = gB227cc;
                    v[2] = gB227cc;
                    OCC_a95d90->GetPosition(v);
                    mfPosY = v[1];
                } else {
                    mfPosY = 0.0f;
                }
            } else if (mpOccupant) {
                OCC_a95d90->GetPosition(&mfPosX);
            }
        }
        Activate(true);
        CheckEffectTriggers();
        PlaySFX(true);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005169f0 score 56
bool cSC4AutomataController::Shutdown()
{
    Activate(false);
    if (mbInitialised) {
        mbInitialised = false;
        ListNode_a95d90* head = reinterpret_cast<ListNode_a95d90*>(mpAutomata);
        ListNode_a95d90* n = head->mpNext;
        while (n != head) {
            Automaton_a95d90* a = reinterpret_cast<Automaton_a95d90*>(n->mpData);
            if (Slot12_a95d90(0x100)) {
                a->Slot13(0);
            }
            a->Release();
            n = n->mpNext;
            if (n == reinterpret_cast<ListNode_a95d90*>(mpAutomata)) {
                break;
            }
        }
        n = reinterpret_cast<ListNode_a95d90*>(mpAutomata)->mpNext;
        while (n != reinterpret_cast<ListNode_a95d90*>(mpAutomata)) {
            ListNode_a95d90* del = n;
            n = n->mpNext;
            Fn0090cf63(del);
        }
        reinterpret_cast<ListNode_a95d90*>(mpAutomata)->mpNext = reinterpret_cast<ListNode_a95d90*>(mpAutomata);
        reinterpret_cast<ListNode_a95d90*>(mpAutomata)->mpPrev = reinterpret_cast<ListNode_a95d90*>(mpAutomata);
        mnAutomataCount = 0;
        if (mpOccupant) {
            Occupant_a95d90* o = OCC_a95d90;
            mpOccupant = 0;
            o->Release();
        }
        if (mpScriptSystem) {
            ScriptSys_a95d90* s = reinterpret_cast<ScriptSys_a95d90*>(mpScriptSystem);
            mpScriptSystem = 0;
            s->Release();
        }
        mpTemplate = 0;
    }
    return true;
}
#endif

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

#ifdef OB_DRAFTS
// CLOSE: 0x00516b40 score 82
void cSC4AutomataController::CheckEffectTriggers()
{
    if (mpTemplate) {
        View3DWin_a95d90* win = gpB43dc8_a95d90;
        Effects_a95d90* fx = 0;
        if (win && win->QueryInterface(0xfa47b3f9, reinterpret_cast<void**>(&fx))) {
            Template_a95d90* t = TPL_a95d90;
            ValueNode_a95d90* head = static_cast<ValueNode_a95d90*>(t->mpTriggersA);
            bool bAny = false;
            bool bAnyB = false;
            bool bOk = true;
            if (head != head->mpNext) {
                bAny = true;
                for (ValueNode_a95d90* n = head->mpNext; n != head && bOk; n = n->mpNext) {
                    bOk = fx->CheckEffect(n->mnValue);
                }
            }
            t = TPL_a95d90;
            head = static_cast<ValueNode_a95d90*>(t->mpTriggersB);
            if (head != head->mpNext) {
                bAnyB = true;
                for (ValueNode_a95d90* n = head->mpNext; n != head && bOk; n = n->mpNext) {
                    bOk = !fx->CheckEffect(n->mnValue);
                }
            }
            if (bAny || bAnyB) {
                Activate(bOk);
            }
            win->Release();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00516c40 score 160
void cSC4AutomataController::GetLotFacingPoint(void* pOut)
{
    float* out = static_cast<float*>(pOut);
    Random_a95d90 rnd;
    rnd.Init(0xffffffff);
    float a[3];
    float b[3];
    a[0] = gB227cc;
    a[1] = gB227cc;
    a[2] = gB227cc;
    b[0] = gB227cc;
    b[1] = gB227cc;
    b[2] = gB227cc;
    if (mpOccupant) {
        LotMgr_a95d90* lm = OB_PTR(LotMgr_a95d90, gpB43cec->GetLotManager());
        Lot_a95d90* lot = 0;
        if (lm && mpOccupant) {
            lot = reinterpret_cast<Lot_a95d90*>(lm->GetLot(mpOccupant));
        }
        if (lot) {
            int32_t n[4];
            lot->GetBounds(n);
            float x0 = static_cast<float>(n[0] << 4);
            float z0 = static_cast<float>(n[1] << 4);
            float x1 = static_cast<float>((n[2] + 1) << 4);
            float z1 = static_cast<float>((n[3] + 1) << 4);
            switch (lot->GetFacing()) {
            case 0:
                a[0] = x0;
                a[1] = 0.0f;
                a[2] = z0 - 1.0f;
                b[0] = x1;
                b[1] = 0.0f;
                b[2] = z0 - 1.0f;
                break;
            case 1:
                a[0] = x1 + 1.0f;
                a[1] = 0.0f;
                a[2] = z0;
                b[0] = x1 + 1.0f;
                b[1] = 0.0f;
                b[2] = z1;
                break;
            case 2:
                a[0] = x1;
                a[1] = 0.0f;
                a[2] = z1 + 1.0f;
                b[0] = x0;
                b[1] = 0.0f;
                b[2] = z1 + 1.0f;
                break;
            case 3:
                a[0] = x0 - 1.0f;
                a[1] = 0.0f;
                a[2] = z1;
                b[0] = x0 - 1.0f;
                b[1] = 0.0f;
                b[2] = z0;
                break;
            default:
                break;
            }
            out[0] = a[0] + (b[0] - a[0]) * 0.5f;
            out[1] = a[1] + (b[1] - a[1]) * 0.5f;
            out[2] = a[2] + (b[2] - a[2]) * 0.5f;
        } else {
            OCC_a95d90->GetPosition(pOut);
        }
    } else {
        out[0] = mfPosX;
        out[1] = mfPosY;
        out[2] = mfPosZ;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00516ec0 score 28
void cSC4AutomataController::GetOccupantBoundingBox(void* pLo, void* pHi)
{
    float* lo = static_cast<float*>(pLo);
    float* hi = static_cast<float*>(pHi);
    if (!Slot12_a95d90(0x20) && !Slot12_a95d90(0x40) && mpOccupant) {
        OCC_a95d90->GetBounds(lo, hi);
        Lot_a95d90* lot = reinterpret_cast<Lot_a95d90*>(GetOccupantLot());
        if (lot) {
            int32_t b[4];
            lot->GetBounds(b);
            lo[0] = static_cast<float>(b[0] << 4);
            lo[2] = static_cast<float>(b[1] << 4);
            hi[0] = static_cast<float>(b[2] * 16 + 16);
            hi[2] = static_cast<float>(b[3] * 16 + 16);
        }
    } else {
        GetPosition(lo);
        GetPosition(hi);
    }
}
#endif

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

#ifdef OB_DRAFTS
// CLOSE: 0x00517e70 score 15
void cSC4AutomataController::Slot13_a95d90(uint32_t nFlag, bool bSet)
{
    if (bSet == true) {
        mnFlags |= nFlag;
    } else {
        mnFlags &= ~nFlag;
    }
}
#endif

// FUNCTION: 0x00517ea0
uint32_t cSC4AutomataController::IsExpired()
{
    if (mfLifetime > 0.0f && mfAge >= mfLifetime) {
        return 1;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00517ed0 score 8
uint32_t cSC4AutomataController::IsFull()
{
    if (!mpTemplate) {
        return 0;
    }
    uint32_t cap = TPL_a95d90->mnCapacity;
    if (!cap) {
        return 0;
    }
    return mnAutomataCount >= cap;
}
#endif

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

#ifdef OB_DRAFTS
// CLOSE: 0x0051bab0 score 64
void* cSC4AutomataController::GetBehaviorTemplate(float fRange, void* pPos)
{
    float* pos = static_cast<float*>(pPos);
    uint8_t* e = TPL_a95d90->mpBehBegin;
    uint8_t* end = TPL_a95d90->mpBehEnd;
    if (e != end) {
        do {
            Behavior_a95d90* b = reinterpret_cast<Behavior_a95d90*>(e);
            if (!(b->mfRange < fRange)) {
                if (b->mnType != 4) {
                    return b;
                }
                QInfo_a95d90* q = MGR_a95d90->GetControllerQInfo(mpOccupant, true);
                q->InitQueuePoint(mpOccupant);
                if (q->mbValid) {
                    float dx = pos[0] - q->mfPointX;
                    float dz = pos[2] - q->mfPointZ;
                    float d = static_cast<float>(std::sqrt(dx * dx + dz * dz));
                    if (d <= b->mfRange) {
                        return b;
                    }
                }
            }
            e += 0x7c;
        } while (e != TPL_a95d90->mpBehEnd);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051bb60 score 89
bool cSC4AutomataController::HandleStateTick(void* pAutomaton, uint32_t nState, uint32_t nTime)
{
    if (nState == 4) {
        QInfo_a95d90* q = MGR_a95d90->GetControllerQInfo(mpOccupant, true);
        q->InitQueuePoint(mpOccupant);
        if (!q->mbValid) {
            static_cast<Automaton_a95d90*>(pAutomaton)->Slot13(0);
            return true;
        }
        Automaton_a95d90* a = static_cast<Automaton_a95d90*>(pAutomaton);
        Automaton_a95d90* owner = a->GetOwner();
        float v[3];
        v[0] = gB227cc;
        v[1] = gB227cc;
        v[2] = gB227cc;
        if (!owner) {
            v[0] = q->mfPointX;
            v[1] = q->mfPointY;
            v[2] = q->mfPointZ;
        } else {
            owner->GetPosition(v);
            float s = owner->GetScale();
            if (s <= 1.0f) {
                s = 1.0f;
            }
            v[0] = s * q->mfDirX + v[0];
            v[1] = s * q->mfDirY + v[1];
            v[2] = s * q->mfDirZ + v[2];
        }
        Heights_a95d90* t = OB_PTR(Heights_a95d90, gpB43cec->GetTrafficNetwork());
        v[1] = t->GetHeight(v[0], v[2]);
        a->SetPosition(v);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051bca0 score 4
bool cSC4AutomataController::HandleEnterState(void* pAutomaton, uint32_t nState)
{
    if (nState == 4) {
        QInfo_a95d90* q = MGR_a95d90->GetControllerQInfo(mpOccupant, true);
        if (q) {
            q->AddToQueue(pAutomaton);
        }
    }
    return false;
}
#endif


#ifdef OB_DRAFTS
// CLOSE: 0x0051bce0 score 26
bool cSC4AutomataController::HandleExitState(void* pAutomaton, uint32_t nState)
{
    if (nState == 4) {
        void* key = mpOccupant;
        Manager_a95d90* m = MGR_a95d90;
        uint32_t n = m->mTable.mpEnd - m->mTable.mpBegin;
        HashNode_a95d90* node = m->mTable.mpBegin[OB_ADDR(key) % n];
        while (node) {
            if (node->mpKey == key) {
                break;
            }
            node = node->mpNext;
        }
        if (node) {
            node->mValue.RemoveFromQueue(pAutomaton);
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051bd50 score 45
bool cSC4AutomataController::HandleRemoveAutomaton(void* pAutomaton)
{
    Manager_a95d90* m = MGR_a95d90;
    void* key = mpOccupant;
    uint32_t n = m->mTable.mpEnd - m->mTable.mpBegin;
    HashNode_a95d90* node = m->mTable.mpBegin[OB_ADDR(key) % n];
    while (node) {
        if (node->mpKey == key) {
            break;
        }
        node = node->mpNext;
    }
    if (node) {
        node->mValue.RemoveFromQueue(pAutomaton);
    }
    ListNode_a95d90* head = reinterpret_cast<ListNode_a95d90*>(mpAutomata);
    ListNode_a95d90* it = head->mpNext;
    while (it != head) {
        if (it->mpData == pAutomaton) {
            break;
        }
        it = it->mpNext;
    }
    if (it != head) {
        static_cast<Automaton_a95d90*>(pAutomaton)->Release();
        it->mpNext->mpPrev = it->mpPrev;
        it->mpPrev->mpNext = it->mpNext;
        Fn0090cf63(it);
        mnAutomataCount = mnAutomataCount - 1;
    }
    return true;
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

#ifdef OB_DRAFTS
// CLOSE: 0x00518a40 score 18
QInfo_a95d90* QInfo_a95d90::Fn00518a40(const QInfo_a95d90* pSrc)
{
    mpHead = 0;
    ListNode_a95d90* head = static_cast<ListNode_a95d90*>(Fn0090cf54(0xc));
    head->mpNext = head;
    head->mpPrev = head;
    mpHead = head;
    ListNode_a95d90* srcHead = pSrc->mpHead;
    uint32_t tmp;
    Fn006f1570(head->mpNext, srcHead->mpNext, srcHead, &tmp);
    mn04 = pSrc->mn04;
    mfPointX = pSrc->mfPointX;
    mfPointY = pSrc->mfPointY;
    mfPointZ = pSrc->mfPointZ;
    mfDirX = pSrc->mfDirX;
    mfDirY = pSrc->mfDirY;
    mfDirZ = pSrc->mfDirZ;
    mbValid = pSrc->mbValid;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005184e0 score 31
void QInfo_a95d90::AddToQueue(void* pAutomaton)
{
    ListNode_a95d90* head = mpHead;
    ListNode_a95d90* it = head->mpNext;
    while (it != head) {
        if (it->mpData == pAutomaton) {
            break;
        }
        it = it->mpNext;
    }
    if (it == head) {
        void* pPrev;
        if (head->mpNext == head) {
            pPrev = 0;
        } else {
            pPrev = head->mpPrev->mpData;
        }
        ListNode_a95d90* n = static_cast<ListNode_a95d90*>(Fn0090cf54(0xc));
        n->mpData = pAutomaton;
        n->mpPrev = head->mpPrev;
        n->mpNext = head;
        n->mpPrev->mpNext = n;
        head->mpPrev = n;
        Automaton_a95d90* a = static_cast<Automaton_a95d90*>(pAutomaton);
        a->AddRef();
        a->SetQueueLeader(pPrev);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005172d0 score 28
void QInfo_a95d90::RemoveFromQueue(void* pAutomaton)
{
    ListNode_a95d90* head = mpHead;
    ListNode_a95d90* first = head->mpNext;
    ListNode_a95d90* it = first;
    if (it != head) {
        while (it->mpData != pAutomaton) {
            it = it->mpNext;
            if (it == head) {
                break;
            }
        }
        if (it != head) {
            ListNode_a95d90* next = it->mpNext;
            if (next != head) {
                Automaton_a95d90* nextAuto = static_cast<Automaton_a95d90*>(next->mpData);
                if (pAutomaton == first->mpData) {
                    nextAuto->SetQueueLeader(0);
                } else {
                    nextAuto->SetQueueLeader(it->mpPrev->mpData);
                }
            }
            it->mpNext->mpPrev = it->mpPrev;
            it->mpPrev->mpNext = it->mpNext;
            Fn0090cf63(it);
            static_cast<Automaton_a95d90*>(pAutomaton)->Release();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051a900 score 57
void HashTable_a95d90::Fn0051a900(HashResult_a95d90* pOut, HashPair_a95d90* pVal)
{
    void* key = pVal->mpKey;
    uint32_t n = mpEnd - mpBegin;
    uint32_t idx = OB_ADDR(key) % n;
    HashNode_a95d90* first = mpBegin[idx];
    HashNode_a95d90* c = first;
    while (c) {
        if (c->mpKey == key) {
            pOut->mpTable = this;
            pOut->mpNode = c;
            pOut->mbInserted = false;
            return;
        }
        c = c->mpNext;
    }
    HashNode_a95d90* node = static_cast<HashNode_a95d90*>(Fn0090cf54(0x2c));
    node->mpNext = 0;
    node->mpKey = pVal->mpKey;
    node->mValue.Fn00518a40(&pVal->mValue);
    node->mpNext = first;
    mpBegin[idx] = node;
    ++mnCount;
    pOut->mpNode = node;
    pOut->mpTable = this;
    pOut->mbInserted = true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051b9d0 score 54
QInfo_a95d90* Manager_a95d90::GetControllerQInfo(void* pOccupant, bool bCreate)
{
    HashTable_a95d90* t = &mTable;
    uint32_t n = t->mpEnd - t->mpBegin;
    HashNode_a95d90* node = t->mpBegin[OB_ADDR(pOccupant) % n];
    while (node) {
        if (node->mpKey == pOccupant) {
            break;
        }
        node = node->mpNext;
    }
    if (node) {
        return &node->mValue;
    }
    if (!bCreate) {
        return 0;
    }
    QInfo_a95d90 blank;
    blank.Fn00517340();
    HashPair_a95d90 pair;
    pair.mpKey = pOccupant;
    pair.mValue.Fn00518a40(&blank);
    t->Fn004f0940(t->mnCount + 1);
    HashResult_a95d90 res;
    t->Fn0051a900(&res, &pair);
    pair.mValue.Fn005650a0();
    blank.Fn005650a0();
    QInfo_a95d90* q = &res.mpNode->mValue;
    if (pOccupant) {
        static_cast<Occupant_a95d90*>(pOccupant)->AddRef();
    }
    q->mbValid = false;
    q->mn04 = 0;
    q->InitQueuePoint(pOccupant);
    return q;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00516070 score 308
void QInfo_a95d90::InitQueuePoint(void* pOccupant)
{
    if (!mbValid) {
        uint32_t nSide = 1;
        Random_a95d90 rnd;
        rnd.Init(0xffffffff);
        float a[3];
        float b[3];
        a[0] = gB227cc;
        a[1] = gB227cc;
        a[2] = gB227cc;
        b[0] = gB227cc;
        b[1] = gB227cc;
        b[2] = gB227cc;
        LotMgr_a95d90* lm = OB_PTR(LotMgr_a95d90, gpB43cec->GetLotManager());
        Lot_a95d90* lot = reinterpret_cast<Lot_a95d90*>(lm->GetLot(pOccupant));
        float x0 = 0.0f;
        float z0 = 0.0f;
        float x1 = 0.0f;
        float z1 = 0.0f;
        if (lot) {
            int32_t n[4];
            lot->GetBounds(n);
            x0 = static_cast<float>(n[0] << 4);
            z0 = static_cast<float>(n[1] << 4);
            x1 = static_cast<float>((n[2] + 1) << 4);
            z1 = static_cast<float>((n[3] + 1) << 4);
            switch (lot->GetFacing()) {
            case 0:
                nSide = 1;
                break;
            case 1:
                nSide = 2;
                break;
            case 2:
                nSide = 3;
                break;
            default:
                nSide = 0;
                break;
            }
        } else {
            static_cast<Occupant_a95d90*>(pOccupant)->GetBounds(&b[0], &a[0]);
            nSide = rnd.Uniform(4);
        }
        for (int32_t i = 0; i < 4; ++i) {
            if (mbValid) {
                break;
            }
            switch (nSide) {
            case 0:
                a[0] = x0;
                a[2] = z0 - 1.0f;
                b[0] = x1;
                b[2] = z0 - 1.0f;
                mfDirX = 0.0f;
                mfDirZ = -1.0f;
                break;
            case 1:
                a[0] = x1 + 1.0f;
                a[2] = z0;
                b[0] = x1 + 1.0f;
                b[2] = z1;
                mfDirX = 1.0f;
                mfDirZ = 0.0f;
                break;
            case 2:
                a[0] = x0;
                a[2] = z1 + 1.0f;
                b[0] = x1;
                b[2] = z1 + 1.0f;
                mfDirX = 0.0f;
                mfDirZ = 1.0f;
                break;
            default:
                a[0] = x0 - 1.0f;
                a[2] = z0;
                b[0] = x0 - 1.0f;
                b[2] = z1;
                mfDirX = -1.0f;
                mfDirZ = 0.0f;
                break;
            }
            mfDirY = 0.0f;
            mfPointX = a[0] + (b[0] - a[0]) * 0.5f;
            mfPointY = a[1] + (b[1] - a[1]) * 0.5f;
            mfPointZ = a[2] + (b[2] - a[2]) * 0.5f;
            int32_t cx = static_cast<int32_t>(mfPointX * (1.0f / 16.0f));
            int32_t cz = static_cast<int32_t>(mfPointZ * (1.0f / 16.0f));
            Lot_a95d90* cell = reinterpret_cast<Lot_a95d90*>(OB_PTR(LotMgr_a95d90, gpB43cec->GetTrafficNetwork())->GetLot(0));
            (void)cx;
            (void)cz;
            if (cell) {
                mbValid = true;
            } else {
                nSide = (nSide + 1) & 3;
            }
        }
    }
}
#endif
