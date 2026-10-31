#include <cstddef>
#include <cmath>

#include "classes/cSC4AutomataController.h"
#include "classes/cSC4AutomataControllerManager.h"
#include "classes/cSC4AutomataGenerator.h"
#include "classes/cUnk00a95f00.h"
#include "gzcom/cRZString.h"
#include "game/Globals.h"

// Views of the objects the controller talks to: only the slots used here are named, the rest are padding.
struct Terrain_sc4ac {
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
struct Heights_sc4ac {
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
struct Lot_sc4ac {
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
struct LotMgr_sc4ac {
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
struct Occupant_sc4ac {
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
struct Automaton_sc4ac {
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
    virtual Automaton_sc4ac* GetOwner();
    virtual void SetQueueLeader(void* pLeader);
};
struct ScriptSys_sc4ac {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};
struct Effects_sc4ac {
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
struct View3DWin_sc4ac {
    virtual bool QueryInterface(uint32_t nIid, void** ppOut);
    virtual void Pad01();
    virtual void Release();
};
struct SoundA_sc4ac {
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
struct SoundB_sc4ac {
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
struct Random_sc4ac {
    uint8_t mPad[0x14];
    // STUB: 0x00913a5c
    void Init(uint32_t nSeed);
    // STUB: 0x009136b1
    uint32_t Uniform(uint32_t n);
};
struct Template_sc4ac {
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
struct Behavior_sc4ac {
    int32_t mnType;
    float mfRange;
};
struct ListNode_sc4ac {
    ListNode_sc4ac* mpNext;
    ListNode_sc4ac* mpPrev;
    void* mpData;
};
struct ValueNode_sc4ac {
    ValueNode_sc4ac* mpNext;
    ValueNode_sc4ac* mpPrev;
    uint32_t mnValue;
};
struct IStream_sc4ac {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void ReadUInt16(uint16_t* pn);
    virtual void ReadVersion(uint16_t* pnVersion);
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
struct OStream_sc4ac {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void WriteUInt16(uint16_t n);
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
struct String_sc4ac {
    uint32_t mnVtbl;
    char* mpBegin;
    char* mpEnd;
    char* mpCap;
};

// GLOBAL: 0x00b227cc
extern float gB227cc;
// GLOBAL: 0x00b43cf4
extern Terrain_sc4ac* gpB43cf4_sc4ac;
// GLOBAL: 0x00b43cb8
extern void* gpB43cb8_sc4ac;
// GLOBAL: 0x00b43dc8
extern View3DWin_sc4ac* gpB43dc8_sc4ac;

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
struct ViewUtil_sc4ac {
    // STUB: 0x007f7e50
    bool IsPointInViewFrustum(const float* pPoint);
};

// GLOBAL: 0x00b43dd8
extern ViewUtil_sc4ac* gpB43dd8_sc4ac;

struct QInfo_sc4ac;
struct HashNode_sc4ac;
struct HashResult_sc4ac;
struct HashPair_sc4ac;

// The record the automata controller manager keeps per occupant: a queue of automata and the point they queue at.
struct QInfo_sc4ac {
    ListNode_sc4ac* mpHead;
    uint32_t mn04;
    float mfPointX;
    float mfPointY;
    float mfPointZ;
    float mfDirX;
    float mfDirY;
    float mfDirZ;
    bool mbValid;
    // STUB: 0x00517340
    QInfo_sc4ac* Fn00517340();
    // STUB: 0x00518a40
    QInfo_sc4ac* Fn00518a40(const QInfo_sc4ac* pSrc);
    // STUB: 0x005184e0
    void AddToQueue(void* pAutomaton);
    // STUB: 0x005172d0
    void RemoveFromQueue(void* pAutomaton);
    // STUB: 0x00516070
    void InitQueuePoint(void* pOccupant);
    // STUB: 0x005650a0
    void Fn005650a0();
    // STUB: 0x006f1570
    void Fn006f1570(ListNode_sc4ac* pPos, ListNode_sc4ac* pFirst, ListNode_sc4ac* pLast, void* pTmp);
};
struct HashNode_sc4ac {
    HashNode_sc4ac* mpNext;
    void* mpKey;
    QInfo_sc4ac mValue;
};
struct HashPair_sc4ac {
    void* mpKey;
    QInfo_sc4ac mValue;
};
struct HashResult_sc4ac {
    HashNode_sc4ac* mpNode;
    void* mpTable;
    bool mbInserted;
};
struct HashTable_sc4ac {
    uint32_t mn00;
    HashNode_sc4ac** mpBegin;
    HashNode_sc4ac** mpEnd;
    uint32_t mn0c;
    uint32_t mnCount;
    // STUB: 0x0051a900
    void Fn0051a900(HashResult_sc4ac* pOut, HashPair_sc4ac* pVal);
    // STUB: 0x004f0940
    void Fn004f0940(uint32_t nSize);
};
struct Manager_sc4ac {
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
    HashTable_sc4ac mTable;
    // STUB: 0x0051b9d0
    QInfo_sc4ac* GetControllerQInfo(void* pOccupant, bool bCreate);
};

#define TPL_sc4ac (reinterpret_cast<Template_sc4ac*>(mpTemplate))
#define OCC_sc4ac (reinterpret_cast<Occupant_sc4ac*>(mpOccupant))
#define MGR_sc4ac OB_PTR(Manager_sc4ac, gpB43cec->GetAutomataControllerManager())
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
    void* ss = gpB43cb8_sc4ac;
    if (!ss) {
        return;
    }
    if (bOn) {
        if (!mpTemplate) {
            return;
        }
        if (TPL_sc4ac->mpSfxBegin == TPL_sc4ac->mpSfxEnd) {
            return;
        }
        Random_sc4ac rnd;
        rnd.Init(0xffffffff);
        uint32_t n = TPL_sc4ac->mpSfxEnd - TPL_sc4ac->mpSfxBegin;
        uint32_t idx = rnd.Uniform(n);
        mnSfxId = TPL_sc4ac->mpSfxBegin[idx];
        float v[3];
        v[0] = gB227cc;
        v[1] = gB227cc;
        v[2] = gB227cc;
        GetPosition(v);
        reinterpret_cast<SoundA_sc4ac*>(ss)->Post(0xea451903, mnSfxId, this, 0, 0);
        reinterpret_cast<SoundB_sc4ac*>(ss)->Post(0xca45190f, this, static_cast<int32_t>(v[0]),
                                                    static_cast<int32_t>(v[1]), static_cast<int32_t>(v[2]));
    } else if (mnSfxId) {
        reinterpret_cast<SoundB_sc4ac*>(ss)->Post(0x6a451908, this, 0, 0, 0);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00515870 score 95
bool cSC4AutomataController::HandleViewChanged()
{
    ViewUtil_sc4ac* vu = gpB43dd8_sc4ac;
    if (vu && gpB43cf4_sc4ac) {
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
                lo[1] = gpB43cf4_sc4ac->GetHeight(lo[0], lo[2]);
            } else {
                lo[1] = pos[1];
            }
            if (gpB43cec->LocationIsInBounds(hi[0], hi[2])) {
                hi[1] = gpB43cf4_sc4ac->GetHeight(hi[0], hi[2]);
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
            float h = gpB43cf4_sc4ac->GetHeight(p[0], p[2]);
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
    Terrain_sc4ac* t = OB_PTR(Terrain_sc4ac, gpB43cec->GetTerrain());
    lo[1] = t->GetHeight(lo[0], lo[2]);
    hi[1] = t->GetHeight(hi[0], hi[2]);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00515d20 score 10
void* cSC4AutomataController::GetOccupantLot()
{
    LotMgr_sc4ac* lm = OB_PTR(LotMgr_sc4ac, gpB43cec->GetLotManager());
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
        ScriptSys_sc4ac* pNew = OB_PTR(ScriptSys_sc4ac, gpB43cec->GetAutomataScriptSystem());
        ScriptSys_sc4ac* pOld = reinterpret_cast<ScriptSys_sc4ac*>(mpScriptSystem);
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
            LotMgr_sc4ac* lm = OB_PTR(LotMgr_sc4ac, gpB43cec->GetLotManager());
            Lot_sc4ac* lot = 0;
            if (lm && mpOccupant) {
                lot = reinterpret_cast<Lot_sc4ac*>(lm->GetLot(mpOccupant));
            }
            if (lot) {
                int32_t b[4];
                lot->GetBounds(b);
                mfPosX = static_cast<float>((b[2] - b[0] + 1) << 4) * 0.5f + (b[0] << 4);
                mfPosZ = static_cast<float>((b[3] - b[1] + 1) << 4) * 0.5f + (b[1] << 4);
                if (gpB43cec->LocationIsInBounds(mfPosX, mfPosZ)) {
                    mfPosY = gpB43cf4_sc4ac->GetHeight(mfPosX, mfPosZ);
                } else if (mpOccupant) {
                    float v[3];
                    v[0] = gB227cc;
                    v[1] = gB227cc;
                    v[2] = gB227cc;
                    OCC_sc4ac->GetPosition(v);
                    mfPosY = v[1];
                } else {
                    mfPosY = 0.0f;
                }
            } else if (mpOccupant) {
                OCC_sc4ac->GetPosition(&mfPosX);
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
        ListNode_sc4ac* head = reinterpret_cast<ListNode_sc4ac*>(mpAutomata);
        ListNode_sc4ac* n = head->mpNext;
        while (n != head) {
            Automaton_sc4ac* a = reinterpret_cast<Automaton_sc4ac*>(n->mpData);
            if (Slot12_a95d90(0x100)) {
                a->Slot13(0);
            }
            a->Release();
            n = n->mpNext;
            if (n == reinterpret_cast<ListNode_sc4ac*>(mpAutomata)) {
                break;
            }
        }
        n = reinterpret_cast<ListNode_sc4ac*>(mpAutomata)->mpNext;
        while (n != reinterpret_cast<ListNode_sc4ac*>(mpAutomata)) {
            ListNode_sc4ac* del = n;
            n = n->mpNext;
            Fn0090cf63(del);
        }
        reinterpret_cast<ListNode_sc4ac*>(mpAutomata)->mpNext = reinterpret_cast<ListNode_sc4ac*>(mpAutomata);
        reinterpret_cast<ListNode_sc4ac*>(mpAutomata)->mpPrev = reinterpret_cast<ListNode_sc4ac*>(mpAutomata);
        mnAutomataCount = 0;
        if (mpOccupant) {
            Occupant_sc4ac* o = OCC_sc4ac;
            mpOccupant = 0;
            o->Release();
        }
        if (mpScriptSystem) {
            ScriptSys_sc4ac* s = reinterpret_cast<ScriptSys_sc4ac*>(mpScriptSystem);
            mpScriptSystem = 0;
            s->Release();
        }
        mpTemplate = 0;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00516b40 score 82
void cSC4AutomataController::CheckEffectTriggers()
{
    if (mpTemplate) {
        View3DWin_sc4ac* win = gpB43dc8_sc4ac;
        Effects_sc4ac* fx = 0;
        if (win && win->QueryInterface(0xfa47b3f9, reinterpret_cast<void**>(&fx))) {
            Template_sc4ac* t = TPL_sc4ac;
            ValueNode_sc4ac* head = static_cast<ValueNode_sc4ac*>(t->mpTriggersA);
            bool bAny = false;
            bool bAnyB = false;
            bool bOk = true;
            if (head != head->mpNext) {
                bAny = true;
                for (ValueNode_sc4ac* n = head->mpNext; n != head && bOk; n = n->mpNext) {
                    bOk = fx->CheckEffect(n->mnValue);
                }
            }
            t = TPL_sc4ac;
            head = static_cast<ValueNode_sc4ac*>(t->mpTriggersB);
            if (head != head->mpNext) {
                bAnyB = true;
                for (ValueNode_sc4ac* n = head->mpNext; n != head && bOk; n = n->mpNext) {
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
    Random_sc4ac rnd;
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
        LotMgr_sc4ac* lm = OB_PTR(LotMgr_sc4ac, gpB43cec->GetLotManager());
        Lot_sc4ac* lot = 0;
        if (lm && mpOccupant) {
            lot = reinterpret_cast<Lot_sc4ac*>(lm->GetLot(mpOccupant));
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
            OCC_sc4ac->GetPosition(pOut);
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
        OCC_sc4ac->GetBounds(lo, hi);
        Lot_sc4ac* lot = reinterpret_cast<Lot_sc4ac*>(GetOccupantLot());
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

#ifdef OB_DRAFTS
// CLOSE: 0x00517ed0 score 8
uint32_t cSC4AutomataController::IsFull()
{
    if (!mpTemplate) {
        return 0;
    }
    uint32_t cap = TPL_sc4ac->mnCapacity;
    if (!cap) {
        return 0;
    }
    return mnAutomataCount >= cap;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051bab0 score 64
void* cSC4AutomataController::GetBehaviorTemplate(float fRange, void* pPos)
{
    float* pos = static_cast<float*>(pPos);
    uint8_t* e = TPL_sc4ac->mpBehBegin;
    uint8_t* end = TPL_sc4ac->mpBehEnd;
    if (e != end) {
        do {
            Behavior_sc4ac* b = reinterpret_cast<Behavior_sc4ac*>(e);
            if (!(b->mfRange < fRange)) {
                if (b->mnType != 4) {
                    return b;
                }
                QInfo_sc4ac* q = MGR_sc4ac->GetControllerQInfo(mpOccupant, true);
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
        } while (e != TPL_sc4ac->mpBehEnd);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051bb60 score 89
bool cSC4AutomataController::HandleStateTick(void* pAutomaton, uint32_t nState, uint32_t nTime)
{
    if (nState == 4) {
        QInfo_sc4ac* q = MGR_sc4ac->GetControllerQInfo(mpOccupant, true);
        q->InitQueuePoint(mpOccupant);
        if (!q->mbValid) {
            static_cast<Automaton_sc4ac*>(pAutomaton)->Slot13(0);
            return true;
        }
        Automaton_sc4ac* a = static_cast<Automaton_sc4ac*>(pAutomaton);
        Automaton_sc4ac* owner = a->GetOwner();
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
        Heights_sc4ac* t = OB_PTR(Heights_sc4ac, gpB43cec->GetTrafficNetwork());
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
        QInfo_sc4ac* q = MGR_sc4ac->GetControllerQInfo(mpOccupant, true);
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
        Manager_sc4ac* m = MGR_sc4ac;
        uint32_t n = m->mTable.mpEnd - m->mTable.mpBegin;
        HashNode_sc4ac* node = m->mTable.mpBegin[OB_ADDR(key) % n];
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
    Manager_sc4ac* m = MGR_sc4ac;
    void* key = mpOccupant;
    uint32_t n = m->mTable.mpEnd - m->mTable.mpBegin;
    HashNode_sc4ac* node = m->mTable.mpBegin[OB_ADDR(key) % n];
    while (node) {
        if (node->mpKey == key) {
            break;
        }
        node = node->mpNext;
    }
    if (node) {
        node->mValue.RemoveFromQueue(pAutomaton);
    }
    ListNode_sc4ac* head = reinterpret_cast<ListNode_sc4ac*>(mpAutomata);
    ListNode_sc4ac* it = head->mpNext;
    while (it != head) {
        if (it->mpData == pAutomaton) {
            break;
        }
        it = it->mpNext;
    }
    if (it != head) {
        static_cast<Automaton_sc4ac*>(pAutomaton)->Release();
        it->mpNext->mpPrev = it->mpPrev;
        it->mpPrev->mpNext = it->mpNext;
        Fn0090cf63(it);
        mnAutomataCount = mnAutomataCount - 1;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00518a40 score 18
QInfo_sc4ac* QInfo_sc4ac::Fn00518a40(const QInfo_sc4ac* pSrc)
{
    mpHead = 0;
    ListNode_sc4ac* head = static_cast<ListNode_sc4ac*>(Fn0090cf54(0xc));
    head->mpNext = head;
    head->mpPrev = head;
    mpHead = head;
    ListNode_sc4ac* srcHead = pSrc->mpHead;
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
void QInfo_sc4ac::AddToQueue(void* pAutomaton)
{
    ListNode_sc4ac* head = mpHead;
    ListNode_sc4ac* it = head->mpNext;
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
        ListNode_sc4ac* n = static_cast<ListNode_sc4ac*>(Fn0090cf54(0xc));
        n->mpData = pAutomaton;
        n->mpPrev = head->mpPrev;
        n->mpNext = head;
        n->mpPrev->mpNext = n;
        head->mpPrev = n;
        Automaton_sc4ac* a = static_cast<Automaton_sc4ac*>(pAutomaton);
        a->AddRef();
        a->SetQueueLeader(pPrev);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005172d0 score 28
void QInfo_sc4ac::RemoveFromQueue(void* pAutomaton)
{
    ListNode_sc4ac* head = mpHead;
    ListNode_sc4ac* first = head->mpNext;
    ListNode_sc4ac* it = first;
    if (it != head) {
        while (it->mpData != pAutomaton) {
            it = it->mpNext;
            if (it == head) {
                break;
            }
        }
        if (it != head) {
            ListNode_sc4ac* next = it->mpNext;
            if (next != head) {
                Automaton_sc4ac* nextAuto = static_cast<Automaton_sc4ac*>(next->mpData);
                if (pAutomaton == first->mpData) {
                    nextAuto->SetQueueLeader(0);
                } else {
                    nextAuto->SetQueueLeader(it->mpPrev->mpData);
                }
            }
            it->mpNext->mpPrev = it->mpPrev;
            it->mpPrev->mpNext = it->mpNext;
            Fn0090cf63(it);
            static_cast<Automaton_sc4ac*>(pAutomaton)->Release();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051a900 score 57
void HashTable_sc4ac::Fn0051a900(HashResult_sc4ac* pOut, HashPair_sc4ac* pVal)
{
    void* key = pVal->mpKey;
    uint32_t n = mpEnd - mpBegin;
    uint32_t idx = OB_ADDR(key) % n;
    HashNode_sc4ac* first = mpBegin[idx];
    HashNode_sc4ac* c = first;
    while (c) {
        if (c->mpKey == key) {
            pOut->mpTable = this;
            pOut->mpNode = c;
            pOut->mbInserted = false;
            return;
        }
        c = c->mpNext;
    }
    HashNode_sc4ac* node = static_cast<HashNode_sc4ac*>(Fn0090cf54(0x2c));
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
QInfo_sc4ac* Manager_sc4ac::GetControllerQInfo(void* pOccupant, bool bCreate)
{
    HashTable_sc4ac* t = &mTable;
    uint32_t n = t->mpEnd - t->mpBegin;
    HashNode_sc4ac* node = t->mpBegin[OB_ADDR(pOccupant) % n];
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
    QInfo_sc4ac blank;
    blank.Fn00517340();
    HashPair_sc4ac pair;
    pair.mpKey = pOccupant;
    pair.mValue.Fn00518a40(&blank);
    t->Fn004f0940(t->mnCount + 1);
    HashResult_sc4ac res;
    t->Fn0051a900(&res, &pair);
    pair.mValue.Fn005650a0();
    blank.Fn005650a0();
    QInfo_sc4ac* q = &res.mpNode->mValue;
    if (pOccupant) {
        static_cast<Occupant_sc4ac*>(pOccupant)->AddRef();
    }
    q->mbValid = false;
    q->mn04 = 0;
    q->InitQueuePoint(pOccupant);
    return q;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00516070 score 308
void QInfo_sc4ac::InitQueuePoint(void* pOccupant)
{
    if (!mbValid) {
        uint32_t nSide = 1;
        Random_sc4ac rnd;
        rnd.Init(0xffffffff);
        float a[3];
        float b[3];
        a[0] = gB227cc;
        a[1] = gB227cc;
        a[2] = gB227cc;
        b[0] = gB227cc;
        b[1] = gB227cc;
        b[2] = gB227cc;
        LotMgr_sc4ac* lm = OB_PTR(LotMgr_sc4ac, gpB43cec->GetLotManager());
        Lot_sc4ac* lot = reinterpret_cast<Lot_sc4ac*>(lm->GetLot(pOccupant));
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
            static_cast<Occupant_sc4ac*>(pOccupant)->GetBounds(&b[0], &a[0]);
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
            Lot_sc4ac* cell = reinterpret_cast<Lot_sc4ac*>(OB_PTR(LotMgr_sc4ac, gpB43cec->GetTrafficNetwork())->GetLot(0));
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


// ---- batch 1 ----
// The attractor/generator templates (a different record from the controller's template).
struct AttrTpl_sc4ac {
    uint8_t mPad00[0x18];
    uint32_t mnKind;
    uint8_t mPad1c[0x38];
    uint32_t mnCount54;
    uint8_t mPad58[0x20];
    uint32_t* mpVecBegin;
    uint32_t* mpVecEnd;
    uint8_t mVector78rest[0x8];
    uint8_t mCurve88[0x8];
    uint32_t mnRangeLo;
    uint32_t mnRangeHi;
    uint8_t mPad98[0x10];
    float mfRadius;
    uint32_t mnAc;
};
struct Vec_sc4ac {
    // STUB: 0x00462c10
    void Assign(void* pOther);
};
struct TplMgr_sc4ac {
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
    virtual void* GetGroupList();
    virtual void* GetGroupById(void* pId);
    virtual void* GetGroupByName(void* pName);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void* GetTemplateByName(void* pName);
};
struct ControllerGrid_sc4ac {
    uint8_t mPad00[0xc];
    uint8_t mnTractsX;
    uint8_t mnTractsZ;
    uint8_t mnShift;
    uint8_t mPad0f;
    float mfWidth;
    float mfDepth;
    // STUB: 0x00517b70
    void MoveController(void* pController);
    // STUB: 0x0051b350
    void Resize(uint32_t nCount, ListNode_sc4ac** ppValue);
    // STUB: 0x005650a0
    void Fn005650a0(ListNode_sc4ac** ppList);
    bool Init();
};
struct Curve_sc4ac {
    // STUB: 0x005f4460
    void Assign(void* pOther);
};

// FUNCTION: 0x00517000
bool cUnk00a95f00::Shutdown()
{
    if (mbInitialised) {
        cSC4AutomataController::Shutdown();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00516fe0 score 7
bool cUnk00a95f00::Init()
{
    if (!mbInitialised) {
        return static_cast<char>(cSC4AutomataController::Init()) != 0;
    }
    return true;
}
#endif

// FUNCTION: 0x00518310
float cUnk00a95f00::GetRadius()
{
    if (mpTemplate) {
        return reinterpret_cast<AttrTpl_sc4ac*>(mpTemplate)->mfRadius;
    }
    return 0.0f;
}

// FUNCTION: 0x005192c0
void cSC4AutomataGenerator::FinalRelease()
{
    Shutdown();
    Fn005192e0();
    ::operator delete(this);
}

// FUNCTION: 0x00518a00
void cSC4AutomataGenerator::Slot16_a95d90(void* pOther)
{
    AttrTpl_sc4ac* t = reinterpret_cast<AttrTpl_sc4ac*>(mpTemplate);
    if (t && t->mnKind == 0x6a1628ba) {
        reinterpret_cast<Vec_sc4ac*>(&t->mpVecBegin)->Assign(pOther);
    }
}

// FUNCTION: 0x00518a20
void cUnk00a95f00::Slot16_a95d90(void* pOther)
{
    AttrTpl_sc4ac* t = reinterpret_cast<AttrTpl_sc4ac*>(mpTemplate);
    if (t && t->mnKind == 0x4a1628c5) {
        reinterpret_cast<Vec_sc4ac*>(&t->mpVecBegin)->Assign(pOther);
    }
}

// FUNCTION: 0x00518930
bool cSC4AutomataControllerManager::MoveController(void* pController)
{
    if (pController) {
        reinterpret_cast<ControllerGrid_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x1c)->MoveController(pController);
        static_cast<cSC4AutomataController*>(pController)->HandleViewChanged();
    }
    return true;
}

// FUNCTION: 0x00516fb0
bool cSC4AutomataGenerator::Init()
{
    if (!mbInitialised) {
        reinterpret_cast<Curve_sc4ac*>(&unknown5c[0])->Assign(reinterpret_cast<uint8_t*>(mpTemplate) + 0x88);
        return cSC4AutomataController::Init();
    }
    return true;
}

// FUNCTION: 0x0051b1c0
unsigned int cSC4AutomataControllerManager::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Shutdown();
    Fn0051a280();
    ::operator delete(this);
    return 0;
}

// FUNCTION: 0x00514ce0
void* cSC4AutomataControllerManager::GetController_2(void* pOccupant, void* pName)
{
    void* pResult = 0;
    void* pTpl = reinterpret_cast<TplMgr_sc4ac*>(mpTemplateMgr)->GetTemplateByName(pName);
    if (pTpl) {
        pResult = GetController(pOccupant, pTpl);
    }
    return pResult;
}

// FUNCTION: 0x00514ca0
void* cSC4AutomataControllerManager::AddControllerFromTemplateName(void* pOccupant, void* pName, void* pPos)
{
    void* pResult = 0;
    void* pTpl = reinterpret_cast<TplMgr_sc4ac*>(mpTemplateMgr)->GetTemplateByName(pName);
    if (pTpl) {
        pResult = AddControllerFromTemplate(pOccupant, pTpl, pPos);
    }
    return pResult;
}

// FUNCTION: 0x0051ab00
bool cSC4AutomataControllerManager::RemoveControllersFromOccupantGroup_2(void* pName, void* pOccupant)
{
    if (mpTemplateMgr) {
        void* pGroup = reinterpret_cast<TplMgr_sc4ac*>(mpTemplateMgr)->GetGroupByName(pName);
        if (pGroup) {
            return Fn0051a350(pGroup, pOccupant);
        }
    }
    return false;
}

// FUNCTION: 0x0051ab40
bool cSC4AutomataControllerManager::RemoveControllersFromOccupantGroup(void* pId, void* pOccupant)
{
    if (mpTemplateMgr) {
        void* pGroup = reinterpret_cast<TplMgr_sc4ac*>(mpTemplateMgr)->GetGroupById(pId);
        if (pGroup) {
            return Fn0051a350(pGroup, pOccupant);
        }
    }
    return false;
}

// FUNCTION: 0x00517150
bool cSC4AutomataControllerManager::AddControllersFromOccupantGroup_2(void* pName, void* pOccupant, void* pPos)
{
    if (mpTemplateMgr) {
        void* pGroup = reinterpret_cast<TplMgr_sc4ac*>(mpTemplateMgr)->GetGroupByName(pName);
        if (pGroup) {
            return Fn005163d0(pGroup, pOccupant, pPos);
        }
    }
    return false;
}

// FUNCTION: 0x00517190
bool cSC4AutomataControllerManager::AddControllersFromOccupantGroup(void* pId, void* pOccupant, void* pPos)
{
    if (mpTemplateMgr) {
        void* pGroup = reinterpret_cast<TplMgr_sc4ac*>(mpTemplateMgr)->GetGroupById(pId);
        if (pGroup) {
            return Fn005163d0(pGroup, pOccupant, pPos);
        }
    }
    return false;
}

// ---- batch 2 ----
struct List_sc4ac {
    // STUB: 0x00427640
    void PushBack(void** ppValue);
    // STUB: 0x0050a2a0
    void Clear();
};
struct Random2_sc4ac {
    // STUB: 0x009136ca
    uint32_t Range(uint32_t nLow, uint32_t nHigh);
};

// FUNCTION: 0x005183d0
bool cUnk00a95f00::Slot03_a80784(void* pStream)
{
    OStream_sc4ac* s = static_cast<OStream_sc4ac*>(pStream);
    s->WriteVersion(4);
    cSC4AutomataController::Slot03_a80784(pStream);
    s->WriteFloat(mfF78);
    s->WriteUInt16(mwW7c);
    s->WriteFloat(mfF80);
    s->WriteUInt16(mwW84);
    s->WriteUInt32(mnV90);
    s->WriteUInt32(mnV94);
    return !s->GetError();
}

// FUNCTION: 0x00518450
bool cUnk00a95f00::Slot04_a80784(void* pStream)
{
    IStream_sc4ac* s = static_cast<IStream_sc4ac*>(pStream);
    uint16_t nVersion;
    s->ReadVersion(&nVersion);
    if (nVersion != 4) {
        return false;
    }
    cSC4AutomataController::Slot04_a80784(pStream);
    s->ReadFloat(&mfF78);
    s->ReadUInt16(&mwW7c);
    s->ReadFloat(&mfF80);
    s->ReadUInt16(&mwW84);
    s->ReadUInt32(&mnV90);
    s->ReadUInt32(&mnV94);
    return !s->GetError();
}

#ifdef OB_DRAFTS
// CLOSE: 0x00517240 score 25
void cUnk00a95f00::Activate(bool bOn)
{
    if (mbInitialised && !bOn && mpTemplate && reinterpret_cast<AttrTpl_sc4ac*>(mpTemplate)->mnKind == 0x4a1628c5) {
        if (Slot12_a95d90(0x100)) {
            ListNode_sc4ac* head = reinterpret_cast<ListNode_sc4ac*>(mpAutomata);
            List_sc4ac* pList = reinterpret_cast<List_sc4ac*>(&mpAutomata);
            ListNode_sc4ac* it = head->mpNext;
            while (it != head) {
                Automaton_sc4ac* a = static_cast<Automaton_sc4ac*>(it->mpData);
                a->Slot13(0);
                a->Release();
                it = it->mpNext;
            }
            pList->Clear();
        }
        uint32_t n = 0;
        ListNode_sc4ac* head2 = reinterpret_cast<ListNode_sc4ac*>(mpAutomata);
        ListNode_sc4ac* p = head2->mpNext;
        while (p != head2) {
            p = p->mpNext;
            n++;
        }
        mnAutomataCount = n;
    }
    cSC4AutomataController::Activate(bOn);
}
#endif

// FUNCTION: 0x00517460
void cUnk00a95f00::SetTemplate(void* pTemplate)
{
    mpTemplate = pTemplate;
    if (pTemplate) {
        if (mpStrBegin != mpStrEnd) {
            *mpStrBegin = 0;
            mpStrEnd = mpStrBegin;
        }
        mfLifetime = TPL_sc4ac->mfLifetime;
        mnFlags = TPL_sc4ac->mnFlags;
    }
    AttrTpl_sc4ac* t = reinterpret_cast<AttrTpl_sc4ac*>(mpTemplate);
    if (t && t->mnKind == 0x4a1628c5) {
        mnV8c = t->mnAc;
        mnRoll98 = reinterpret_cast<Random2_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x60)->Range(t->mnRangeLo, t->mnRangeHi);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0051c030 score 31
bool cSC4AutomataGenerator::HandleExitState(void* pAutomaton, uint32_t nState)
{
    ListNode_sc4ac* head = reinterpret_cast<ListNode_sc4ac*>(mpAutomata);
    if (head->mpNext != head) {
        ListNode_sc4ac* it = head->mpNext;
        while (it != head) {
            if (it->mpData == pAutomaton) {
                break;
            }
            it = it->mpNext;
        }
        if (it != head) {
            it->mpNext->mpPrev = it->mpPrev;
            it->mpPrev->mpNext = it->mpNext;
            Fn0090cf63(it);
            mnAutomataCount = mnAutomataCount - 1;
            static_cast<Automaton_sc4ac*>(pAutomaton)->Release();
        }
    }
    return cSC4AutomataController::HandleExitState(pAutomaton, nState);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051bfb0 score 44
bool cSC4AutomataGenerator::HandleEnterState(void* pAutomaton, uint32_t nState)
{
    if (mpTemplate && TPL_sc4ac->mnCapacity > 0) {
        ListNode_sc4ac* head = reinterpret_cast<ListNode_sc4ac*>(mpAutomata);
        ListNode_sc4ac* it = head->mpNext;
        while (it != head) {
            if (it->mpData == pAutomaton) {
                break;
            }
            it = it->mpNext;
        }
        if (it == head) {
            reinterpret_cast<List_sc4ac*>(&mpAutomata)->PushBack(&pAutomaton);
            mnAutomataCount++;
            static_cast<Automaton_sc4ac*>(pAutomaton)->AddRef();
        }
    }
    if (nState == 4) {
        QInfo_sc4ac* q = MGR_sc4ac->GetControllerQInfo(mpOccupant, true);
        if (q) {
            q->AddToQueue(pAutomaton);
        }
    }
    return false;
}
#endif

// ---- batch 3 ----
struct Time_sc4ac {
    float mfValue;
    int16_t mwDay;
};

#ifdef OB_DRAFTS
// CLOSE: 0x005188c0 score 35
bool cSC4AutomataControllerManager::MoveControllers(void* pOccupant)
{
    HashTable_sc4ac* t = reinterpret_cast<HashTable_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x58);
    uint32_t nBuckets = t->mpEnd - t->mpBegin;
    HashNode_sc4ac* node = t->mpBegin[OB_ADDR(pOccupant) % nBuckets];
    while (node) {
        if (node->mpKey == pOccupant) {
            break;
        }
        node = node->mpNext;
    }
    if (node) {
        ListNode_sc4ac* it = node->mValue.mpHead->mpNext;
        if (it != node->mValue.mpHead) {
            ControllerGrid_sc4ac* grid = reinterpret_cast<ControllerGrid_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x1c);
            do {
                void* pController = it->mpData;
                grid->MoveController(pController);
                static_cast<cSC4AutomataController*>(pController)->HandleViewChanged();
                it = it->mpNext;
            } while (it != node->mValue.mpHead);
        }
    }
    return true;
}
#endif

// FUNCTION: 0x0051a520
bool cSC4AutomataControllerManager::RemoveControllers(void* pOccupant)
{
    return Fn0051a350(0, pOccupant);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00514d10 score 28
bool cSC4AutomataControllerManager::QueryInterface(uint32_t nIid, void** ppOut)
{
    switch (nIid) {
    case 0x452294aa:
        *ppOut = static_cast<cSC4AutomataControllerManager_8*>(this);
        break;
    case 1:
    case 0xe4fda3d4:
        *ppOut = static_cast<cSC4AutomataControllerManager_c*>(this);
        break;
    case 0xca14c9fc:
        *ppOut = this;
        break;
    default:
        return false;
    }
    AddRef();
    return true;
}
#endif

// FUNCTION: 0x00518350
uint32_t cUnk00a95f00::IsExpired()
{
    if (mfLifetime > 0.0f && mfAge >= mfLifetime) {
        return 1;
    }
    if (mnV8c > 0) {
        return mnCount88 >= mnV8c;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00515220 score 14
uint32_t cUnk00a95f00::Fn00515220(void* pTemplate)
{
    uint32_t r = 0xffffffff;
    if (pTemplate) {
        uint32_t n = mnRoll98;
        if (n <= 1) {
            n = reinterpret_cast<AttrTpl_sc4ac*>(pTemplate)->mnCount54;
            if (n == 0) {
                return r;
            }
        }
        r = n;
    }
    return r;
}
#endif

// FUNCTION: 0x00515250
bool Fn00515250(const Time_sc4ac* pA, const Time_sc4ac* pB)
{
    bool bLess;
    if (pA->mwDay < pB->mwDay) {
        bLess = true;
    } else if (pA->mwDay > pB->mwDay) {
        bLess = false;
    } else {
        bLess = pA->mfValue < pB->mfValue;
    }
    return !bLess;
}

// ---- batch 4 ----
struct Elem_sc4ac {
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
    virtual void Reset(uint32_t n);
    uint8_t mPad04[0x10];
};
struct Item_sc4ac {
    uint8_t mPad00[0x10];
    Elem_sc4ac* mpBegin;
    Elem_sc4ac* mpEnd;
    uint8_t mPad18[4];
    void* mpBuffer;
    uint8_t mPad20[0x5c];
};

#ifdef OB_DRAFTS
// CLOSE: 0x00516010 score 16
void cUnk00a95f00::Fn00516010()
{
    AttrTpl_sc4ac* t = reinterpret_cast<AttrTpl_sc4ac*>(mpTemplate);
    uint32_t n = t->mpVecEnd - t->mpVecBegin;
    if (n > 1) {
        mnV90 = t->mpVecBegin[reinterpret_cast<Random_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x60)->Uniform(n)];
    } else {
        mnV90 = *t->mpVecBegin;
    }
    mnV94 = 0;
    mnRoll98 = reinterpret_cast<Random2_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x60)->Range(t->mnRangeLo, t->mnRangeHi);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00518b20 score 2
void Fn00518b20(Item_sc4ac* pFirst, Item_sc4ac* pLast)
{
    for (; pFirst != pLast; pFirst++) {
        if (pFirst->mpBuffer) {
            Fn0090cf63(pFirst->mpBuffer);
        }
        Elem_sc4ac* e = pFirst->mpBegin;
        Elem_sc4ac* end = pFirst->mpEnd;
        for (; e != end; e++) {
            e->Reset(0);
        }
        if (pFirst->mpBegin) {
            Fn0090cf63(pFirst->mpBegin);
        }
    }
}
#endif

// FUNCTION: 0x00516800
void cSC4AutomataControllerManager::ReleaseControllerList(void* pList)
{
    ListNode_sc4ac** ppHead = static_cast<ListNode_sc4ac**>(pList);
    ListNode_sc4ac* it = (*ppHead)->mpNext;
    while (it != *ppHead) {
        static_cast<Automaton_sc4ac*>(it->mpData)->Release();
        it = it->mpNext;
    }
    it = (*ppHead)->mpNext;
    while (it != *ppHead) {
        ListNode_sc4ac* pCur = it;
        it = it->mpNext;
        Fn0090cf63(pCur);
    }
    (*ppHead)->mpNext = *ppHead;
    (*ppHead)->mpPrev = *ppHead;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005173a0 score 77
void* cSC4AutomataControllerManager::GetController(void* pOccupant, void* pTemplate)
{
    HashTable_sc4ac* t = reinterpret_cast<HashTable_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x58);
    uint32_t nBuckets = t->mpEnd - t->mpBegin;
    HashNode_sc4ac* node = t->mpBegin[OB_ADDR(pOccupant) % nBuckets];
    while (node) {
        if (node->mpKey == pOccupant) {
            break;
        }
        node = node->mpNext;
    }
    if (node && pTemplate) {
        ListNode_sc4ac* head = node->mValue.mpHead;
        ListNode_sc4ac* it = head->mpNext;
        while (it != head) {
            cSC4AutomataController* pController = static_cast<cSC4AutomataController*>(it->mpData);
            if (pController && OB_PTR(void, pController->GetTemplate()) == pTemplate) {
                return pController;
            }
            it = it->mpNext;
        }
    }
    return 0;
}
#endif

// ---- batch 5: slot-padding chain: PadN_sc4ac has N unnamed virtual slots ----
struct Pad1_sc4ac { virtual void PadSlot1(); };
struct Pad2_sc4ac : Pad1_sc4ac { virtual void PadSlot2(); };
struct Pad3_sc4ac : Pad2_sc4ac { virtual void PadSlot3(); };
struct Pad4_sc4ac : Pad3_sc4ac { virtual void PadSlot4(); };
struct Pad5_sc4ac : Pad4_sc4ac { virtual void PadSlot5(); };
struct Pad6_sc4ac : Pad5_sc4ac { virtual void PadSlot6(); };
struct Pad7_sc4ac : Pad6_sc4ac { virtual void PadSlot7(); };
struct Pad8_sc4ac : Pad7_sc4ac { virtual void PadSlot8(); };
struct Pad9_sc4ac : Pad8_sc4ac { virtual void PadSlot9(); };
struct Pad10_sc4ac : Pad9_sc4ac { virtual void PadSlot10(); };
struct Pad11_sc4ac : Pad10_sc4ac { virtual void PadSlot11(); };
struct Pad12_sc4ac : Pad11_sc4ac { virtual void PadSlot12(); };
struct Pad13_sc4ac : Pad12_sc4ac { virtual void PadSlot13(); };
struct Pad14_sc4ac : Pad13_sc4ac { virtual void PadSlot14(); };
struct Pad15_sc4ac : Pad14_sc4ac { virtual void PadSlot15(); };
struct Pad16_sc4ac : Pad15_sc4ac { virtual void PadSlot16(); };
struct Pad17_sc4ac : Pad16_sc4ac { virtual void PadSlot17(); };
struct Pad18_sc4ac : Pad17_sc4ac { virtual void PadSlot18(); };
struct Pad19_sc4ac : Pad18_sc4ac { virtual void PadSlot19(); };
struct Pad20_sc4ac : Pad19_sc4ac { virtual void PadSlot20(); };
struct Pad21_sc4ac : Pad20_sc4ac { virtual void PadSlot21(); };
struct Pad22_sc4ac : Pad21_sc4ac { virtual void PadSlot22(); };
struct Pad23_sc4ac : Pad22_sc4ac { virtual void PadSlot23(); };
struct Pad24_sc4ac : Pad23_sc4ac { virtual void PadSlot24(); };
struct Pad25_sc4ac : Pad24_sc4ac { virtual void PadSlot25(); };
struct Pad26_sc4ac : Pad25_sc4ac { virtual void PadSlot26(); };
struct Pad27_sc4ac : Pad26_sc4ac { virtual void PadSlot27(); };
struct Pad28_sc4ac : Pad27_sc4ac { virtual void PadSlot28(); };
struct Pad29_sc4ac : Pad28_sc4ac { virtual void PadSlot29(); };
struct Pad30_sc4ac : Pad29_sc4ac { virtual void PadSlot30(); };
struct Pad31_sc4ac : Pad30_sc4ac { virtual void PadSlot31(); };
struct Pad32_sc4ac : Pad31_sc4ac { virtual void PadSlot32(); };
struct Pad33_sc4ac : Pad32_sc4ac { virtual void PadSlot33(); };
struct Pad34_sc4ac : Pad33_sc4ac { virtual void PadSlot34(); };
struct Pad35_sc4ac : Pad34_sc4ac { virtual void PadSlot35(); };
struct Pad36_sc4ac : Pad35_sc4ac { virtual void PadSlot36(); };
struct Pad37_sc4ac : Pad36_sc4ac { virtual void PadSlot37(); };
struct Pad38_sc4ac : Pad37_sc4ac { virtual void PadSlot38(); };
struct Pad39_sc4ac : Pad38_sc4ac { virtual void PadSlot39(); };
struct Pad40_sc4ac : Pad39_sc4ac { virtual void PadSlot40(); };
struct Pad41_sc4ac : Pad40_sc4ac { virtual void PadSlot41(); };
struct Pad42_sc4ac : Pad41_sc4ac { virtual void PadSlot42(); };
struct Pad43_sc4ac : Pad42_sc4ac { virtual void PadSlot43(); };
struct Pad44_sc4ac : Pad43_sc4ac { virtual void PadSlot44(); };
struct Pad45_sc4ac : Pad44_sc4ac { virtual void PadSlot45(); };
struct Pad46_sc4ac : Pad45_sc4ac { virtual void PadSlot46(); };
struct Pad47_sc4ac : Pad46_sc4ac { virtual void PadSlot47(); };
struct Pad48_sc4ac : Pad47_sc4ac { virtual void PadSlot48(); };
struct Pad49_sc4ac : Pad48_sc4ac { virtual void PadSlot49(); };
struct Pad50_sc4ac : Pad49_sc4ac { virtual void PadSlot50(); };
struct Pad51_sc4ac : Pad50_sc4ac { virtual void PadSlot51(); };
struct Pad52_sc4ac : Pad51_sc4ac { virtual void PadSlot52(); };
struct Pad53_sc4ac : Pad52_sc4ac { virtual void PadSlot53(); };
struct Pad54_sc4ac : Pad53_sc4ac { virtual void PadSlot54(); };
struct Pad55_sc4ac : Pad54_sc4ac { virtual void PadSlot55(); };
struct Pad56_sc4ac : Pad55_sc4ac { virtual void PadSlot56(); };
struct Pad57_sc4ac : Pad56_sc4ac { virtual void PadSlot57(); };
struct Pad58_sc4ac : Pad57_sc4ac { virtual void PadSlot58(); };
struct Pad59_sc4ac : Pad58_sc4ac { virtual void PadSlot59(); };
struct Pad60_sc4ac : Pad59_sc4ac { virtual void PadSlot60(); };
struct Pad61_sc4ac : Pad60_sc4ac { virtual void PadSlot61(); };
struct Pad62_sc4ac : Pad61_sc4ac { virtual void PadSlot62(); };
struct Pad63_sc4ac : Pad62_sc4ac { virtual void PadSlot63(); };
struct Pad64_sc4ac : Pad63_sc4ac { virtual void PadSlot64(); };
struct Pad65_sc4ac : Pad64_sc4ac { virtual void PadSlot65(); };
struct Pad66_sc4ac : Pad65_sc4ac { virtual void PadSlot66(); };
struct Pad67_sc4ac : Pad66_sc4ac { virtual void PadSlot67(); };
struct Pad68_sc4ac : Pad67_sc4ac { virtual void PadSlot68(); };
struct Pad69_sc4ac : Pad68_sc4ac { virtual void PadSlot69(); };
struct Pad70_sc4ac : Pad69_sc4ac { virtual void PadSlot70(); };
struct Pad71_sc4ac : Pad70_sc4ac { virtual void PadSlot71(); };
struct Pad72_sc4ac : Pad71_sc4ac { virtual void PadSlot72(); };
struct Pad73_sc4ac : Pad72_sc4ac { virtual void PadSlot73(); };
struct Pad74_sc4ac : Pad73_sc4ac { virtual void PadSlot74(); };
struct Pad75_sc4ac : Pad74_sc4ac { virtual void PadSlot75(); };
struct Pad76_sc4ac : Pad75_sc4ac { virtual void PadSlot76(); };
struct Pad77_sc4ac : Pad76_sc4ac { virtual void PadSlot77(); };
struct Pad78_sc4ac : Pad77_sc4ac { virtual void PadSlot78(); };
struct Pad79_sc4ac : Pad78_sc4ac { virtual void PadSlot79(); };
struct Pad80_sc4ac : Pad79_sc4ac { virtual void PadSlot80(); };
struct Pad81_sc4ac : Pad80_sc4ac { virtual void PadSlot81(); };
struct Pad82_sc4ac : Pad81_sc4ac { virtual void PadSlot82(); };
struct Pad83_sc4ac : Pad82_sc4ac { virtual void PadSlot83(); };
struct Pad84_sc4ac : Pad83_sc4ac { virtual void PadSlot84(); };
struct Pad85_sc4ac : Pad84_sc4ac { virtual void PadSlot85(); };
struct Pad86_sc4ac : Pad85_sc4ac { virtual void PadSlot86(); };
struct Pad87_sc4ac : Pad86_sc4ac { virtual void PadSlot87(); };
struct Pad88_sc4ac : Pad87_sc4ac { virtual void PadSlot88(); };
struct Pad89_sc4ac : Pad88_sc4ac { virtual void PadSlot89(); };
struct Pad90_sc4ac : Pad89_sc4ac { virtual void PadSlot90(); };
struct Pad91_sc4ac : Pad90_sc4ac { virtual void PadSlot91(); };
struct Pad92_sc4ac : Pad91_sc4ac { virtual void PadSlot92(); };
struct Pad93_sc4ac : Pad92_sc4ac { virtual void PadSlot93(); };
struct Pad94_sc4ac : Pad93_sc4ac { virtual void PadSlot94(); };
struct Pad95_sc4ac : Pad94_sc4ac { virtual void PadSlot95(); };
struct Pad96_sc4ac : Pad95_sc4ac { virtual void PadSlot96(); };
struct Pad97_sc4ac : Pad96_sc4ac { virtual void PadSlot97(); };
struct Pad98_sc4ac : Pad97_sc4ac { virtual void PadSlot98(); };
struct Pad99_sc4ac : Pad98_sc4ac { virtual void PadSlot99(); };
struct Pad100_sc4ac : Pad99_sc4ac { virtual void PadSlot100(); };
struct Pad101_sc4ac : Pad100_sc4ac { virtual void PadSlot101(); };
struct Pad102_sc4ac : Pad101_sc4ac { virtual void PadSlot102(); };
struct Pad103_sc4ac : Pad102_sc4ac { virtual void PadSlot103(); };
struct Pad104_sc4ac : Pad103_sc4ac { virtual void PadSlot104(); };
struct Pad105_sc4ac : Pad104_sc4ac { virtual void PadSlot105(); };
struct Pad106_sc4ac : Pad105_sc4ac { virtual void PadSlot106(); };
struct Pad107_sc4ac : Pad106_sc4ac { virtual void PadSlot107(); };
struct Pad108_sc4ac : Pad107_sc4ac { virtual void PadSlot108(); };
struct Pad109_sc4ac : Pad108_sc4ac { virtual void PadSlot109(); };
struct Pad110_sc4ac : Pad109_sc4ac { virtual void PadSlot110(); };

struct OccV_sc4ac : Pad6_sc4ac {
    virtual void* GetOwner();
};
struct OwnerV_sc4ac : Pad9_sc4ac {
    virtual void* QueryObj(uint32_t nIid);
};
struct SubV_sc4ac : Pad5_sc4ac {
    virtual void* GetData();
};
struct DataV_sc4ac : Pad4_sc4ac {
    virtual uint32_t Count();
};
struct DataIds_sc4ac : Pad103_sc4ac {
    virtual uint32_t* GetIds();
};
struct Group_sc4ac : Pad3_sc4ac {
    virtual bool Matches(void* pOccupant);
    uint8_t mPad04[0x2c];
    ListNode_sc4ac** mppTemplates;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00517060 score 21
bool cSC4AutomataControllerManager::AddControllers(void* pOccupant)
{
    if (pOccupant) {
        OwnerV_sc4ac* pOwner = static_cast<OwnerV_sc4ac*>(static_cast<OccV_sc4ac*>(pOccupant)->GetOwner());
        SubV_sc4ac* pSub = static_cast<SubV_sc4ac*>(pOwner->QueryObj(0xaa1dd396));
        if (pSub) {
            DataV_sc4ac* pData = static_cast<DataV_sc4ac*>(pSub->GetData());
            uint32_t* pIds = reinterpret_cast<DataIds_sc4ac*>(pData)->GetIds();
            uint32_t i = 0;
            while (i < pData->Count()) {
                void* pGroup = reinterpret_cast<TplMgr_sc4ac*>(mpTemplateMgr)->GetGroupById(OB_PTR(void, pIds[i]));
                if (pGroup) {
                    Fn005163d0(pGroup, pOccupant, 0);
                }
                i++;
            }
        }
        ListNode_sc4ac** ppList = static_cast<ListNode_sc4ac**>(reinterpret_cast<TplMgr_sc4ac*>(mpTemplateMgr)->GetGroupList());
        ListNode_sc4ac* it = (*ppList)->mpNext;
        while (it != *ppList) {
            Group_sc4ac* pGroup = static_cast<Group_sc4ac*>(it->mpData);
            if (pGroup->Matches(pOccupant)) {
                ListNode_sc4ac* t = (*pGroup->mppTemplates)->mpNext;
                while (t != *pGroup->mppTemplates) {
                    AddControllerFromTemplate(pOccupant, t->mpData, 0);
                    t = t->mpNext;
                }
            }
            it = it->mpNext;
        }
    }
    return true;
}
#endif

// ---- batch 6 ----
struct HashIter_sc4ac {
    HashNode_sc4ac* mpNode;
    HashTable_sc4ac* mpTable;
};
struct Msg_sc4ac : Pad1_sc4ac {
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetType(uint32_t nType);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void SetData(void* pData);
    // STUB: 0x009134d6
    Msg_sc4ac* Construct();
};
// STUB: 0x009133da
void* Fn009133da(uint32_t nSize);
struct GridTable_sc4ac {
    // STUB: 0x004b0390
    void Begin(HashIter_sc4ac* pOut);
};
struct ControllerGrid2_sc4ac {
    // STUB: 0x005171d0
    void RemoveController(void* pController);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00518950 score 1
void cSC4AutomataControllerManager::UpdateControllers()
{
    HashIter_sc4ac it;
    reinterpret_cast<GridTable_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x58)->Begin(&it);
    HashNode_sc4ac* node = it.mpNode;
    HashTable_sc4ac* tbl = it.mpTable;
    while (node) {
        ListNode_sc4ac* e = node->mValue.mpHead->mpNext;
        while (e != node->mValue.mpHead) {
            cSC4AutomataController* c = static_cast<cSC4AutomataController*>(e->mpData);
            if (c->Slot12_a95d90(1)) {
                reinterpret_cast<ControllerGrid_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x1c)->MoveController(c);
                c->HandleViewChanged();
            }
            e = e->mpNext;
        }
        HashNode_sc4ac* next = node->mpNext;
        if (!next) {
            uint32_t n = tbl->mpEnd - tbl->mpBegin;
            uint32_t i = OB_ADDR(node->mpKey) % n + 1;
            while (i < n) {
                next = tbl->mpBegin[i];
                if (next) {
                    break;
                }
                i++;
            }
        }
        node = next;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00517880 score 1
bool cSC4AutomataControllerManager::RemoveController(void* pController)
{
    bool bRemoved = false;
    if (pController) {
        HashIter_sc4ac it;
        reinterpret_cast<GridTable_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x58)->Begin(&it);
        HashNode_sc4ac* node = it.mpNode;
        HashTable_sc4ac* tbl = it.mpTable;
        while (node) {
            ListNode_sc4ac* head = node->mValue.mpHead;
            ListNode_sc4ac* e = head->mpNext;
            while (e != head) {
                if (e->mpData == pController) {
                    break;
                }
                e = e->mpNext;
            }
            if (e != head) {
                e->mpNext->mpPrev = e->mpPrev;
                e->mpPrev->mpNext = e->mpNext;
                bRemoved = true;
                Fn0090cf63(e);
                Msg_sc4ac* m = static_cast<Msg_sc4ac*>(Fn009133da(0x2c));
                if (m) {
                    m = m->Construct();
                }
                m->AddRef();
                m->SetType(0xea298d50);
                m->SetData(pController);
                gpB43ccc->MessageSend(m);
                m->Release();
                reinterpret_cast<ControllerGrid2_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x1c)->RemoveController(pController);
                static_cast<cSC4AutomataController*>(pController)->Shutdown();
                static_cast<cSC4AutomataController*>(pController)->Release();
            }
            HashNode_sc4ac* next = node->mpNext;
            if (!next) {
                uint32_t n = tbl->mpEnd - tbl->mpBegin;
                uint32_t i = OB_ADDR(node->mpKey) % n + 1;
                while (i < n) {
                    next = tbl->mpBegin[i];
                    if (next) {
                        break;
                    }
                    i++;
                }
            }
            node = next;
        }
    }
    return bRemoved;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051c090 score 1
bool ControllerGrid_sc4ac::Init()
{
    int32_t nCells = gpB43cec->CellCountX();
    uint32_t nTracts = nCells / 8;
    mnTractsX = static_cast<uint8_t>(nTracts);
    mnTractsZ = static_cast<uint8_t>(nTracts);
    mnShift = 0;
    for (uint8_t s = 0; s < 32; s++) {
        mnShift = s;
        if ((1u << s) == nTracts) {
            break;
        }
    }
    ListNode_sc4ac* pEmpty = static_cast<ListNode_sc4ac*>(Fn0090cf54(0xc));
    pEmpty->mpNext = pEmpty;
    pEmpty->mpPrev = pEmpty;
    Resize(nTracts * nTracts, &pEmpty);
    Fn005650a0(&pEmpty);
    mfWidth = static_cast<float>(nCells << 4);
    mfDepth = static_cast<float>(static_cast<int32_t>(gpB43cec->CellCountZ()) << 4);
    return true;
}
#endif

// ---- batch 7 ----
struct Ccm_sc4ac : Pad3_sc4ac {
    virtual void AddCheat(uint32_t nId, void* pName);
    virtual void RemoveCheat(uint32_t nId);
    virtual void AddNotification(void* pTarget, uint32_t nId);
    virtual void RemoveNotification(void* pTarget, uint32_t nId);
};
struct Atm_sc4ac : Pad5_sc4ac {
    virtual void AddNotification(void* pTarget, uint32_t nId);
    virtual void RemoveNotification(void* pTarget, uint32_t nId);
};
struct Sc4Game_sc4ac : Pad21_sc4ac {
    virtual bool IsCheatsEnabled();
};
struct CityV_sc4ac : Pad48_sc4ac {
    virtual void* GetTemplates();
};
struct CityW_sc4ac : Pad86_sc4ac {
    virtual void* GetTractObject();
};
struct Obj_sc4ac : Pad1_sc4ac {
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};
// STUB: 0x00602600
Atm_sc4ac* Fn00602600();
// GLOBAL: 0x00b43cac
extern Ccm_sc4ac* gpB43cac_sc4ac;
// GLOBAL: 0x00b43c94
extern Sc4Game_sc4ac* gpB43c94_sc4ac;
// GLOBAL: 0x00b09a10
extern const char* gpB09a10_sc4ac;

#ifdef OB_DRAFTS
// CLOSE: 0x0051b3e0 score 1
bool cSC4AutomataControllerManager::Shutdown()
{
    if (mbInitialised) {
        Ccm_sc4ac* pCcm = gpB43cac_sc4ac;
        if (pCcm) {
            pCcm->RemoveCheat(0xaba2b5bb);
            pCcm->RemoveNotification(static_cast<cSC4AutomataControllerManager_0*>(this), 0);
        }
        Atm_sc4ac* pAtm = Fn00602600();
        if (pAtm) {
            pAtm->RemoveNotification(static_cast<cSC4AutomataControllerManager_8*>(this), 0xc0);
        }
        cIGZMessageServer2* pMs = gpB43ccc;
        if (pMs) {
            void* pSelf = static_cast<cSC4AutomataControllerManager_8*>(this);
            pMs->RemoveNotification(pSelf, 0x99ef1142);
            pMs->RemoveNotification(pSelf, 0x99ef1143);
            pMs->RemoveNotification(pSelf, 0x26d31ec1);
            pMs->RemoveNotification(pSelf, 0x89d3e9f3);
            pMs->RemoveNotification(pSelf, 0x44778230);
            pMs->RemoveNotification(pSelf, 0xaa1d07f3);
            pMs->RemoveNotification(pSelf, 0xa6b79602);
            pMs->RemoveNotification(pSelf, 0xa6b79612);
            pMs->RemoveNotification(pSelf, 0xaa375fe8);
            pMs->RemoveNotification(pSelf, 0xcad61e00);
            pMs->RemoveNotification(pSelf, 0xead61e16);
            pMs->RemoveNotification(pSelf, 0xebff18a3);
        }
        if (mpTemplateMgr) {
            static_cast<Obj_sc4ac*>(mpTemplateMgr)->Release();
            mpTemplateMgr = 0;
        }
        if (mpObj18) {
            static_cast<Obj_sc4ac*>(mpObj18)->Release();
            mpObj18 = 0;
        }
        ClearControllerQInfo();
        ClearControllers();
        mbInitialised = false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051c140 score 1
void cSC4AutomataControllerManager::Init()
{
    if (!mbInitialised) {
        reinterpret_cast<ControllerGrid_sc4ac*>(reinterpret_cast<uint8_t*>(this) + 0x1c)->Init();
        if (!mpObj18) {
            mpObj18 = OB_PTR(void, gpB43cec->Get24HourClock());
            static_cast<Obj_sc4ac*>(mpObj18)->AddRef();
        }
        if (!mpTemplateMgr) {
            mpTemplateMgr = OB_PTR(void, gpB43cec->GetAutomataScriptSystem());
            static_cast<Obj_sc4ac*>(mpTemplateMgr)->AddRef();
        }
        cIGZMessageServer2* pMs = gpB43ccc;
        if (pMs) {
            void* pSelf = static_cast<cSC4AutomataControllerManager_8*>(this);
            pMs->AddNotification(pSelf, 0x99ef1142);
            pMs->AddNotification(pSelf, 0x99ef1143);
            pMs->AddNotification(pSelf, 0x26d31ec1);
            pMs->AddNotification(pSelf, 0x89d3e9f3);
            pMs->AddNotification(pSelf, 0x44778230);
            pMs->AddNotification(pSelf, 0xaa1d07f3);
            pMs->AddNotification(pSelf, 0xa6b79602);
            pMs->AddNotification(pSelf, 0xa6b79612);
            pMs->AddNotification(pSelf, 0xaa375fe8);
            pMs->AddNotification(pSelf, 0xcad61e00);
            pMs->AddNotification(pSelf, 0xead61e16);
            pMs->AddNotification(pSelf, 0xebff18a3);
        }
        Atm_sc4ac* pAtm = Fn00602600();
        if (pAtm) {
            pAtm->AddNotification(static_cast<cSC4AutomataControllerManager_8*>(this), 0xc0);
        }
        Ccm_sc4ac* pCcm = gpB43cac_sc4ac;
        if (pCcm) {
            if (gpB43c94_sc4ac->IsCheatsEnabled()) {
                cRZString sName(gpB09a10_sc4ac);
                pCcm->AddCheat(0xaba2b5bb, &sName);
                pCcm->AddNotification(static_cast<cSC4AutomataControllerManager_0*>(this), 0);
            }
        }
        mbInitialised = true;
    }
}
#endif

// ---- batch 8 ----
#ifdef OB_DRAFTS
// CLOSE: 0x005163d0 score 19
bool cSC4AutomataControllerManager::Fn005163d0(void* pGroup, void* pOccupant, void* pPos)
{
    Group_sc4ac* g = static_cast<Group_sc4ac*>(pGroup);
    ListNode_sc4ac* it = (*g->mppTemplates)->mpNext;
    if (it != *g->mppTemplates) {
        do {
            AddControllerFromTemplate(pOccupant, it->mpData, pPos);
            it = it->mpNext;
        } while (it != *g->mppTemplates);
    }
    return true;
}
#endif
