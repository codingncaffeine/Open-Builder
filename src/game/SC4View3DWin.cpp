#include <cstddef>
#include "classes/cSC4View3DWin.h"
#include "classes/cSC4ToolTipManager.h"
#include "game/Globals.h"

// Views of objects the window reaches through pointers (the tag is the window's primary vtable, abc9c0).
struct Unknown_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual uint32_t Slot03() = 0;
    virtual uint32_t Slot04() = 0;
};

struct Camera_abc9c0 {
    // STUB: 0x007cbc40
    int32_t GetVirtualZoom();
};

struct List_abc9c0 {
    // STUB: 0x00473ec0
    void Fn00473ec0();
};

// FUNCTION: 0x007e57e0
void cSC4View3DWin::Slot20_abc9c0(uint32_t a)
{
    *OB_PTR(uint32_t, a) = mnViewLevel;
}

// FUNCTION: 0x007f0ff0
void cSC4View3DWin::Slot43_abc9c0(uint32_t a)
{
    Slot42_abc9c0(a, a);
}

// FUNCTION: 0x007e7f90
void cSC4View3DWin::Slot35_abc9c0()
{
    mnScrollVelX = 0;
    mnScrollVelY = 0;
    RecalcScrollVelocity();
}

// FUNCTION: 0x007e57c0
void cSC4View3DWin::Slot18_abc9c0(uint32_t a)
{
    Unknown_abc9c0* pFilter = static_cast<Unknown_abc9c0*>(mpViewFilter);
    *OB_PTR(Unknown_abc9c0*, a) = pFilter;
    pFilter->AddRef();
}

// FUNCTION: 0x007ede30
void Fn007ede30(uint32_t a, uint32_t b, cSC4View3DWin* pWin)
{
    pWin->Fn007ecda0(OB_PTR(void, a), b);
}

// FUNCTION: 0x007f1020
void cSC4View3DWin::Slot53_abc9c0(uint32_t a)
{
    mnLastBuilding = a;
    mbLastBuildingSet = true;
}

// FUNCTION: 0x007f1040
void cSC4View3DWin::Slot54_abc9c0(uint32_t a)
{
    mnLastLot = a;
    mbLastLotSet = true;
}

// FUNCTION: 0x007f1060
uint32_t cSC4View3DWin::Slot51_abc9c0()
{
    if (mbLastBuildingSet) {
        return mnLastBuilding;
    }
    return 0;
}

// FUNCTION: 0x007f1080
uint32_t cSC4View3DWin::Slot52_abc9c0()
{
    if (mbLastLotSet) {
        return mnLastLot;
    }
    return 0;
}

// FUNCTION: 0x007e5820
void cSC4View3DWin::Slot27_abc9c0(uint32_t a)
{
    do {
    } while (Slot26_abc9c0(a));
}

#ifdef OB_DRAFTS
// CLOSE: 0x007e65e0 score 10
uint32_t cSC4View3DWin::Slot24_abc9c0()
{
    uint32_t* pBegin = mpInputControlsBegin;
    uint32_t* pEnd = mpInputControlsEnd;
    if (pBegin != pEnd) {
        return pEnd[-1];
    }
    return 0;
}
#endif

// FUNCTION: 0x007e5800
void cSC4View3DWin::Slot23_abc9c0(uint32_t a)
{
    if (a != mnViewLevel) {
        uint32_t level = a;
        Slot21_abc9c0(OB_ADDR(&level));
    }
}

// FUNCTION: 0x007e5780
bool cSC4View3DWin::Slot12_abc9c0()
{
    return static_cast<Camera_abc9c0*>(mpCamera)->GetVirtualZoom() < mnZoomMax;
}

// FUNCTION: 0x007e57a0
bool cSC4View3DWin::Slot13_abc9c0()
{
    return static_cast<Camera_abc9c0*>(mpCamera)->GetVirtualZoom() > mnZoomMin;
}

// FUNCTION: 0x007e9780
bool cSC4View3DWin::Fn007e9780()
{
    reinterpret_cast<List_abc9c0*>(reinterpret_cast<char*>(this) + 0x14c)->Fn00473ec0();
    Slot27_abc9c0(1);
    return Slot30_abc9c0();
}

// The object at +0x154 (a vtable with the pause and resume calls at 0x28 and 0x34).
struct Pauser_abc9c0 {
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
    virtual void Pause() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Resume() = 0;
};

// The view object at +0xf4 (calls at 0x98, 0x9c, 0xa0 and 0xf0).
struct View_abc9c0 {
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
    virtual bool SetZoom(int32_t) = 0;
    virtual bool ZoomIn() = 0;
    virtual bool ZoomOut() = 0;
    virtual bool SetRotation(uint32_t) = 0;
    virtual bool RotateLeft() = 0;
    virtual bool RotateRight() = 0;
    virtual bool SetZoomAndRotation(int32_t, uint32_t) = 0;
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
    virtual bool Pick(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t) = 0;
};

struct Timer_abc9c0 {
    // STUB: 0x0089058f
    void Restart();
    // STUB: 0x0088ff0a
    void Reset();
};

struct AutoGamePause_abc9c0 {
    uint32_t mnState;
    // STUB: 0x005f9320
    void Init(bool, bool, bool, bool);
    // STUB: 0x005f9360
    void Done();
};

// STUB: 0x009afd73
void Fn009afd73(void* pWin, uint32_t id, bool value);

// STUB: 0x009afe69
void Fn009afe69(void* pWin, uint32_t id, bool value);

// STUB: 0x0078e2f0
uint32_t Fn0078e2f0(uint32_t a, uint32_t b);

// STUB: 0x0090cf63
void StlDelete_abc9c0(void* p);

// STUB: 0x0090cf54
void* StlNew_abc9c0(uint32_t size);

// The simulator (the global at 0xb43c94) with the call at 0x30.
struct Sim_abc9c0 {
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
    virtual void SetPaused(uint32_t) = 0;
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
    virtual uint8_t* GetSettings() = 0;
};

// GLOBAL: 0x00b43c94
extern Sim_abc9c0* gpB43c94_abc9c0;

// A node of the doubly linked lists the window keeps (next, previous, an object).
struct ListNode_abc9c0 {
    ListNode_abc9c0* mpNext;
    ListNode_abc9c0* mpPrev;
    Unknown_abc9c0* mpData;
};

struct ListHead_abc9c0 {
    ListNode_abc9c0* mpHead;
    void PopFront();
};

struct Item_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual uint32_t Slot03() = 0;
    virtual uint32_t GetId() = 0;
};

struct ItemNode_abc9c0 {
    ItemNode_abc9c0* mpNext;
    ItemNode_abc9c0* mpPrev;
    Item_abc9c0* mpItem;
};

// FUNCTION: 0x007e6030
bool cSC4ToolTipManager::QueryInterface(uint32_t iid, uint32_t pOut)
{
    switch (iid) {
    case 1:
    case 0x22c010cd:
        *OB_PTR(cSC4ToolTipManager*, pOut) = this;
        AddRef();
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007e9850 (cannot be scored: no symbol)
void ListHead_abc9c0::PopFront()
{
    ListNode_abc9c0* pNode = mpHead->mpNext;
    ListNode_abc9c0* pPrev = pNode->mpPrev;
    ListNode_abc9c0* pNext = pNode->mpNext;
    pPrev->mpNext = pNext;
    pNext->mpPrev = pPrev;
    if (pNode->mpData) {
        pNode->mpData->Release();
    }
    StlDelete_abc9c0(pNode);
}
#endif

// FUNCTION: 0x007e60b0
uint32_t cSC4View3DWin::Slot06_abc9c0()
{
    void* pView;
    if (static_cast<Unknown_abc9c0*>(mpManagerHost)->QueryInterface(0x67c5bede, &pView)) {
        static_cast<Unknown_abc9c0*>(pView)->Release();
        return OB_ADDR(pView);
    }
    return 0;
}

// FUNCTION: 0x007e5b40
void cSC4View3DWin::DoTemporarySimHiddenPause()
{
    if (!mbSimPaused) {
        if (mpSimTarget) {
            mbSimPaused = true;
            static_cast<Pauser_abc9c0*>(mpSimTarget)->Pause();
        }
    }
    reinterpret_cast<Timer_abc9c0*>(reinterpret_cast<char*>(this) + 0x160)->Restart();
}

// FUNCTION: 0x007e5b70
void cSC4View3DWin::Fn007e5b70()
{
    if (mbSimPaused) {
        Pauser_abc9c0* pTarget = static_cast<Pauser_abc9c0*>(mpSimTarget);
        mbSimPaused = false;
        if (pTarget) {
            pTarget->Resume();
        }
    }
    reinterpret_cast<Timer_abc9c0*>(reinterpret_cast<char*>(this) + 0x160)->Reset();
}

#ifdef OB_DRAFTS
// CLOSE: 0x007e9360 score 17
void Fn007e9360(ItemNode_abc9c0** pOut, ItemNode_abc9c0* pFirst, ItemNode_abc9c0* pLast, uint32_t id)
{
    for (; pFirst != pLast; pFirst = pFirst->mpNext) {
        if (pFirst->mpItem->GetId() == id) {
            break;
        }
    }
    *pOut = pFirst;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007e9330 score 11
void OB_STDCALL Fn007e9330(ListNode_abc9c0** pOut, ListNode_abc9c0* pNode)
{
    ListNode_abc9c0* pPrev = pNode->mpPrev;
    ListNode_abc9c0* pNext = pNode->mpNext;
    pPrev->mpNext = pNext;
    pNext->mpPrev = pPrev;
    if (pNode->mpData) {
        pNode->mpData->Release();
    }
    StlDelete_abc9c0(pNode);
    *pOut = pNext;
}
#endif

// FUNCTION: 0x007e77f0
void cSC4View3DWin::Slot57_abc9c0()
{
    if (mpMissionPanel) {
        Slot15_adc8d8(mpMissionPanel);
        Unknown_abc9c0* pPanel = static_cast<Unknown_abc9c0*>(mpMissionPanel);
        if (pPanel) {
            mpMissionPanel = 0;
            pPanel->Release();
        }
    }
}

// FUNCTION: 0x007e5700
void cSC4View3DWin::Slot32_abc9c0(uint32_t a)
{
    Unknown_abc9c0* pNew = OB_PTR(Unknown_abc9c0, a);
    if (mpKeyAccelerator != pNew) {
        if (pNew) {
            pNew->AddRef();
        }
        if (mpKeyAccelerator) {
            static_cast<Unknown_abc9c0*>(mpKeyAccelerator)->Release();
        }
        mpKeyAccelerator = pNew;
    }
}

// FUNCTION: 0x007e5b00
void cSC4View3DWin::UpdateZoomButtons()
{
    Fn009afd73(mpToolbarWin, 0x4992046a, Slot12_abc9c0());
    Fn009afd73(mpToolbarWin, 0xe9920494, Slot13_abc9c0());
}

#ifdef OB_DRAFTS
// CLOSE: 0x007e5740 score 15
void cSC4View3DWin::Slot34_abc9c0()
{
    if (mbScrolling) {
        mbScrollStopping = true;
        if (mbScrollScaled) {
            mfScrollVelocity = mfScrollSpeed * mfScrollScale;
        } else {
            mfScrollVelocity = mfScrollSpeed;
        }
    }
}
#endif

// FUNCTION: 0x007e6e00
void cSC4View3DWin::DoBudgetFailure()
{
    AutoGamePause_abc9c0 pause;
    pause.Init(false, false, true, true);
    Fn0078e2f0(0x0a5cf71d, 0x2a5cfb2c);
    pause.Done();
    if (gpB43c94_abc9c0) {
        gpB43c94_abc9c0->SetPaused(0);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x007e5840 score 1
void cSC4View3DWin::Slot36_abc9c0(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    if (mpPicker) {
        static_cast<View_abc9c0*>(mpPicker)->Pick(a, b, c, 0, d);
        return;
    }
    uint32_t* pOut = OB_PTR(uint32_t, c);
    pOut[2] = 0;
    pOut[1] = 0;
    pOut[0] = 0;
}
#endif

// FUNCTION: 0x007e97a0
void cSC4View3DWin::DoCityObliterated()
{
    Fn009afd73(mpToolbarWin, 0x4988bc6a, false);
    if (mnPanel == 4) {
        Fn007e8ca0(4);
    }
    Fn009afe69(mpToolbarWin, 0x2988bc85, false);
}

// ---- batch 3 ----

struct HashNode_abc9c0 {
    HashNode_abc9c0* mpNext;
    uint32_t mnKey;
};

struct ColorWin_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void SetColor(uint32_t, uint32_t, uint32_t, uint32_t) = 0;
};

// The terrain scrubber input control (0x130 bytes); only its interface calls and constructor are used here.
struct Scrubber_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    // STUB: 0x004d9430
    Scrubber_abc9c0* Fn004d9430(uint32_t, bool);
};

struct ProgressScreen_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    // STUB: 0x00776f90
    ProgressScreen_abc9c0* Fn00776f90(void*);
    // STUB: 0x007778d0
    void Init();
};

// The secondary menu at +0x1f8 (call at 0x118).
struct Menu_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
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
    virtual void Hide() = 0;
};

struct TrueType_abc9c0 {
};

struct PtrVec_abc9c0 {
    void** mpStart;
    void** mpFinish;
    void** mpEnd;
    // STUB: 0x0051ca60
    void Overflow(void** pos, void* const& x, const TrueType_abc9c0& tt, uint32_t n, bool atEnd);
    void PushBack(void* const& x);
};

struct Elem20_abc9c0 {
    uint8_t mBytes[0x20];
    // STUB: 0x007de030
    void Fn007de030(const Elem20_abc9c0* pSrc);
};

struct Elem28_abc9c0 {
    uint8_t mBytes[0x28];
    // STUB: 0x007de0a0
    void Fn007de0a0(const Elem28_abc9c0* pSrc);
};

struct MsgServer_abc9c0 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Post(void*, uint32_t) = 0;
};

// STUB: 0x00913b97
MsgServer_abc9c0* Fn00913b97();

struct TickMessage_abc9c0 {
    uint32_t mnType;
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    TickMessage_abc9c0()
        : mnType(0xca56dd76)
        , mnA(0)
        , mnB(0)
        , mnC(0)
    {
    }
};

#ifdef OB_DRAFTS
// CLOSE: 0x007eb850 score 16
bool cSC4View3DWin::Slot46_abc9c0(uint32_t a)
{
    HashNode_abc9c0** pBuckets = reinterpret_cast<HashNode_abc9c0**>(mpBuckets);
    uint32_t nCount = reinterpret_cast<HashNode_abc9c0**>(mpBucketsEnd) - pBuckets;
    HashNode_abc9c0* pNode = reinterpret_cast<HashNode_abc9c0**>(mpBuckets)[a % nCount];
    while (pNode && pNode->mnKey != a) {
        pNode = pNode->mpNext;
    }
    return pNode != 0;
}
#endif

// FUNCTION: 0x007e6220
bool cSC4View3DWin::Slot15_abc9c0()
{
    bool bOk = static_cast<View_abc9c0*>(mpPicker)->RotateLeft();
    if (bOk) {
        DoTemporarySimHiddenPause();
    }
    return bOk;
}

// FUNCTION: 0x007e6270
bool cSC4View3DWin::Slot16_abc9c0()
{
    bool bOk = static_cast<View_abc9c0*>(mpPicker)->RotateRight();
    if (bOk) {
        DoTemporarySimHiddenPause();
    }
    return bOk;
}

// FUNCTION: 0x007e61d0
bool cSC4View3DWin::Slot14_abc9c0(uint32_t a)
{
    bool bOk = static_cast<View_abc9c0*>(mpPicker)->SetRotation(a);
    if (bOk) {
        DoTemporarySimHiddenPause();
    }
    return bOk;
}

// FUNCTION: 0x007e7220
void cSC4View3DWin::Fn007e7220(uint32_t a)
{
    ColorWin_abc9c0* pWin = 0;
    if (static_cast<Unknown_abc9c0*>(mpCaptionWin)->QueryInterface(0x86d72b57, reinterpret_cast<void**>(&pWin))) {
        pWin->SetColor(0xff, 0xff, 0xff, a);
        pWin->Release();
    }
}

// FUNCTION: 0x007e5910
void cSC4View3DWin::InvokeLandscapeTool(uint32_t a, bool b)
{
    void* pMem = ::operator new(0x130);
    Scrubber_abc9c0* pTool;
    if (pMem) {
        pTool = static_cast<Scrubber_abc9c0*>(pMem)->Fn004d9430(a, b);
    } else {
        pTool = 0;
    }
    pTool->AddRef();
    Slot25_abc9c0(OB_ADDR(pTool), 2);
    pTool->Release();
}

#ifdef OB_DRAFTS
// CLOSE: 0x007e5960 score 10
bool cSC4View3DWin::Fn007e5960(uint32_t a, uint32_t b)
{
    uint32_t nCurrent = mnViewLevel;
    uint32_t nLevel = 1;
    if (a == 0x4a2b2467) {
        if (b == 0x299237bf) {
            nLevel = 2;
        } else if (b == 0x2992f72c) {
            nLevel = 3;
        }
    }
    return nLevel != nCurrent;
}
#endif

// FUNCTION: 0x007e6060
void Fn007e6060(uint32_t)
{
    MsgServer_abc9c0* pServer = Fn00913b97();
    if (pServer) {
        static TickMessage_abc9c0 message;
        pServer->Post(&message, 0);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x007e5bb0 (the base slot GetArea_2 is declared without the argument the original passes)
void cSC4View3DWin::CreateProgressScreen(uint32_t a)
{
    void* pMem = ::operator new(0xc0);
    ProgressScreen_abc9c0* pScreen;
    if (pMem) {
        pScreen = static_cast<ProgressScreen_abc9c0*>(pMem)->Fn00776f90(GetArea_2());
    } else {
        pScreen = 0;
    }
    mpProgressScreen = pScreen;
    pScreen->AddRef();
    static_cast<ProgressScreen_abc9c0*>(mpProgressScreen)->Init();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007ebd30 (cannot be scored: no symbol)
void PtrVec_abc9c0::PushBack(void* const& x)
{
    if (mpFinish != mpEnd) {
        if (mpFinish) {
            *mpFinish = x;
        }
        mpFinish = mpFinish + 1;
        return;
    }
    TrueType_abc9c0 tt;
    Overflow(mpFinish, x, tt, 1, true);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007efee0 score 6
Elem20_abc9c0* Fn007efee0(Elem20_abc9c0* pFirst, Elem20_abc9c0* pLast, Elem20_abc9c0* pDest)
{
    if (pFirst != pLast) {
        do {
            if (pDest) {
                pDest->Fn007de030(pFirst);
            }
            ++pFirst;
            ++pDest;
        } while (pFirst != pLast);
    }
    return pDest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007eff10 score 6
Elem28_abc9c0* Fn007eff10(Elem28_abc9c0* pFirst, Elem28_abc9c0* pLast, Elem28_abc9c0* pDest)
{
    if (pFirst != pLast) {
        do {
            if (pDest) {
                pDest->Fn007de0a0(pFirst);
            }
            ++pFirst;
            ++pDest;
        } while (pFirst != pLast);
    }
    return pDest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007f09b0 score 26
Elem20_abc9c0* OB_STDCALL Fn007f09b0(uint32_t n, Elem20_abc9c0* pFirst, Elem20_abc9c0* pLast)
{
    Elem20_abc9c0* pNew;
    if (n) {
        pNew = static_cast<Elem20_abc9c0*>(StlNew_abc9c0(n << 5));
    } else {
        pNew = 0;
    }
    Elem20_abc9c0* pDest = pNew;
    for (; pFirst != pLast; ++pFirst, ++pDest) {
        if (pDest) {
            pDest->Fn007de030(pFirst);
        }
    }
    return pNew;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007f0a10 score 23
Elem28_abc9c0* OB_STDCALL Fn007f0a10(uint32_t n, Elem28_abc9c0* pFirst, Elem28_abc9c0* pLast)
{
    Elem28_abc9c0* pNew;
    if (n) {
        pNew = static_cast<Elem28_abc9c0*>(StlNew_abc9c0(n * 40));
    } else {
        pNew = 0;
    }
    Elem28_abc9c0* pDest = pNew;
    for (; pFirst != pLast; ++pFirst, ++pDest) {
        if (pDest) {
            pDest->Fn007de0a0(pFirst);
        }
    }
    return pNew;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007f64f0 score 8
void cSC4View3DWin::Slot33_abc9c0(uint32_t a, uint32_t b, uint32_t c)
{
    bool bOn = *reinterpret_cast<bool*>(&a);
    bool bWas = mbScrolling;
    if (!bWas && bOn) {
        Fn007f6410();
    } else if (!bOn && bWas) {
        Fn007f6160();
    }
    mbScrolling = bOn;
    mnScrollArg328 = b;
    mfScrollScale = *reinterpret_cast<float*>(&c);
    mbScrollStopping = false;
}
#endif

// FUNCTION: 0x007e5d20
void cSC4View3DWin::Slot59_abc9c0()
{
    if (mpSecondaryMenu) {
        Slot60_abc9c0();
        static_cast<Menu_abc9c0*>(mpSecondaryMenu)->Hide();
        static_cast<Menu_abc9c0*>(mpSecondaryMenu)->Release();
        Slot16_adc8d8(OB_ADDR(mpSecondaryMenu));
        mpSecondaryMenu = 0;
        mnSecondaryMenu200 = 0;
    }
}

// ---- batch 4 ----

// An input control at the end of a persistent list (calls at 0x10 and 0x60).
struct InputCtl_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Pad03() = 0;
    virtual void Deactivate() = 0;
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
    virtual void Shutdown() = 0;
};

struct ViewUtil_abc9c0 {
    // STUB: 0x007f78e0
    void Project(float* pPoint);
};

// GLOBAL: 0x00b43dd8
extern ViewUtil_abc9c0* gpB43dd8_abc9c0;

// STUB: 0x0078f100
Unknown_abc9c0* Fn0078f100(uint32_t a, uint32_t b, uint32_t c, uint32_t d);

struct Zone_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    // STUB: 0x004dae80
    Zone_abc9c0* Fn004dae80(uint32_t);
};

// A string node of the list at the start of a holder (the fields the clearing code touches).
struct StrNode_abc9c0 {
    StrNode_abc9c0* mpNext;
    StrNode_abc9c0* mpPrev;
    uint32_t mn8;
    uint32_t mnC;
    const void* mpAlloc10;
    void* mpBuf14;
    uint32_t mn18;
    uint32_t mn1C;
    uint32_t mn20;
    const void* mpAlloc24;
    void* mpBuf28;
};

// GLOBAL: 0x00a80810
extern const uint8_t gA80810_abc9c0;

struct StrListHolder_abc9c0 {
    StrNode_abc9c0* mpHead;
    void Fn007ede50();
};

#ifdef OB_DRAFTS
// CLOSE: 0x007e8030 score 42
bool cSC4View3DWin::Slot30_abc9c0()
{
    if (mpPersistentBegin != mpPersistentEnd) {
        do {
            InputCtl_abc9c0* pCtl = static_cast<InputCtl_abc9c0*>(mpPersistentEnd[-1]);
            if (pCtl) {
                pCtl->Shutdown();
                pCtl->Deactivate();
                pCtl->Release();
            }
            mpPersistentEnd = mpPersistentEnd - 1;
        } while (mpPersistentBegin != mpPersistentEnd);
    }
    return true;
}
#endif

// FUNCTION: 0x007e90f0
void cSC4View3DWin::Slot50_abc9c0(uint32_t a)
{
    const uint32_t* pIn = OB_PTR(const uint32_t, a);
    uint32_t point[3];
    point[0] = pIn[0];
    point[1] = pIn[1];
    point[2] = pIn[2];
    if (gpB43dd8_abc9c0) {
        gpB43dd8_abc9c0->Project(reinterpret_cast<float*>(point));
        float* pf = reinterpret_cast<float*>(point);
        Fn007e9090(static_cast<int32_t>(pf[0]), static_cast<int32_t>(pf[1]));
    }
}

// FUNCTION: 0x007ec620
void cSC4View3DWin::Fn007ec620(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Unknown_abc9c0* pObj = Fn0078f100(0x6a01fc2a, d, 0, c);
    if (pObj) {
        pObj->AddRef();
    }
    Fn007eaeb0(c, a, b, OB_ADDR(pObj), 0x14215ed0, e);
    if (pObj) {
        pObj->Release();
    }
}

// FUNCTION: 0x007e6da0
void cSC4View3DWin::InvokeZoningTool(uint32_t a)
{
    if (gpB43cec->GetEstablished()) {
        void* pMem = ::operator new(0x98);
        Zone_abc9c0* pZone;
        if (pMem) {
            pZone = static_cast<Zone_abc9c0*>(pMem)->Fn004dae80(a);
        } else {
            pZone = 0;
        }
        if (pZone) {
            pZone->AddRef();
        }
        Slot25_abc9c0(OB_ADDR(pZone), 2);
        if (pZone) {
            pZone->Release();
        }
    }
}

// FUNCTION: 0x007e62c0
bool cSC4View3DWin::Slot09_abc9c0()
{
    if (static_cast<Camera_abc9c0*>(mpCamera)->GetVirtualZoom() < mnZoomMax) {
        bool bOk = static_cast<View_abc9c0*>(mpPicker)->ZoomIn();
        if (bOk) {
            DoTemporarySimHiddenPause();
        }
        return bOk;
    }
    return false;
}

// FUNCTION: 0x007e6320
bool cSC4View3DWin::Slot10_abc9c0()
{
    if (static_cast<Camera_abc9c0*>(mpCamera)->GetVirtualZoom() > mnZoomMin) {
        bool bOk = static_cast<View_abc9c0*>(mpPicker)->ZoomOut();
        if (bOk) {
            DoTemporarySimHiddenPause();
        }
        return bOk;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007ede50 score 6
void StrListHolder_abc9c0::Fn007ede50()
{
    StrNode_abc9c0* pNext = mpHead->mpNext;
    if (pNext != mpHead) {
        do {
            StrNode_abc9c0* pNode = pNext;
            pNext = pNode->mpNext;
            pNode->mpAlloc24 = &gA80810_abc9c0;
            if (pNode->mpBuf28) {
                StlDelete_abc9c0(pNode->mpBuf28);
            }
            pNode->mpAlloc10 = &gA80810_abc9c0;
            if (pNode->mpBuf14) {
                StlDelete_abc9c0(pNode->mpBuf14);
            }
            StlDelete_abc9c0(pNode);
        } while (pNext != mpHead);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}
#endif

// ---- batch 5 ----

// The cursor-text window at +0x3d8 (call at 0x3c; its second interface, at +4, answers at 0x11c).
struct CursorSub_abc9c0 {
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
    virtual bool IsShown() = 0;
};

struct CursorWin_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
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
    virtual void SetPosition(int32_t*) = 0;
};

// The cost-indicator window at +0x3d4 (call at 0xc gives a menu-like object).
struct CostWin_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual Menu_abc9c0* GetChild() = 0;
};

// The terrain at the global 0xb43cf4 (calls at 0xa4 and 0xa8) and the object a helper builds for it.
struct Terrain_abc9c0 {
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
    virtual void SetValue(uint32_t) = 0;
    virtual uint32_t GetValue() = 0;
};

// GLOBAL: 0x00b43cf4
extern Terrain_abc9c0* gpB43cf4_abc9c0;

struct Helper_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    // STUB: 0x00734d20
    Helper_abc9c0* Fn00734d20();
    // STUB: 0x00734b90
    void Fn00734b90(uint32_t* pValue);
};

// The 24-hour clock (global 0xb43dbc) with the calls the speed buttons use.
struct Clock_abc9c0 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void SetSpeed(uint32_t) = 0;
    virtual uint32_t GetSpeed() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual uint32_t Slot12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual uint32_t Slot15() = 0;
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
    virtual void Enable(uint32_t) = 0;
};

// GLOBAL: 0x00b43dbc
extern Clock_abc9c0* gpB43dbc_abc9c0;

// FUNCTION: 0x007e9090
void cSC4View3DWin::Fn007e9090(int32_t x, int32_t y)
{
    if (mpCursorTextWin) {
        CursorSub_abc9c0* pSub = reinterpret_cast<CursorSub_abc9c0*>(reinterpret_cast<char*>(mpCursorTextWin) + 4);
        if (pSub->IsShown()) {
            int32_t pos[2];
            pos[0] = x;
            pos[1] = y;
            static_cast<CursorWin_abc9c0*>(mpCursorTextWin)->SetPosition(pos);
        }
    }
    mnCursorX = x;
    mnCursorY = y;
    Fn007e8f30(0);
}

// FUNCTION: 0x007ec680
void cSC4View3DWin::DoFloraCatalogView(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Unknown_abc9c0* pObj = Fn0078f100(0xe83e0437, d, 0, c);
    if (pObj) {
        pObj->AddRef();
    }
    Fn007eaeb0(c + 0xea5ada53, a, b, OB_ADDR(pObj), 0x14215ed0, e);
    if (pObj) {
        pObj->Release();
    }
}

// FUNCTION: 0x007ec6e0
void cSC4View3DWin::DoZoneCatalogView(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Unknown_abc9c0* pObj = Fn0078f100(0x2a3858e4, d, 0, c);
    if (pObj) {
        pObj->AddRef();
    }
    Fn007eaeb0(c + 0x8a3f003f, a, b, OB_ADDR(pObj), 0x14215ed1, e);
    if (pObj) {
        pObj->Release();
    }
}

// FUNCTION: 0x007ebf30
uint32_t cSC4View3DWin::DoCityEstablished()
{
    Fn009afd73(mpToolbarWin, 0x99887766, true);
    Fn009afd73(mpToolbarWin, 0x8b96b73e, true);
    Fn009afd73(mpToolbarWin, 0x4988bc6a, true);
    if (Slot24_abc9c0()) {
        Slot26_abc9c0(0);
    }
    UpdateBudget();
    return Fn007eab60();
}

// FUNCTION: 0x007e5f40
void cSC4View3DWin::Fn007e5f40()
{
    Terrain_abc9c0* pTerrain = gpB43cf4_abc9c0;
    if (pTerrain) {
        uint32_t nValue = pTerrain->GetValue();
        void* pMem = ::operator new(0xc);
        Helper_abc9c0* pHelper;
        if (pMem) {
            pHelper = static_cast<Helper_abc9c0*>(pMem)->Fn00734d20();
        } else {
            pHelper = 0;
        }
        pHelper->AddRef();
        pHelper->Fn00734b90(&nValue);
        pHelper->Release();
        pTerrain->SetValue(nValue);
    }
}

// FUNCTION: 0x007e60e0
bool cSC4View3DWin::Slot08_abc9c0(uint32_t a)
{
    int32_t nZoom = a;
    int32_t nMin = mnZoomMin;
    if (nZoom < nMin) {
        nZoom = nMin;
    } else {
        int32_t nMax = mnZoomMax;
        if (nZoom > nMax) {
            nZoom = nMax;
        }
    }
    bool bOk = static_cast<View_abc9c0*>(mpPicker)->SetZoom(nZoom);
    if (bOk) {
        DoTemporarySimHiddenPause();
    }
    return bOk;
}

// FUNCTION: 0x007e70c0
void cSC4View3DWin::Fn007e70c0(uint32_t a)
{
    Clock_abc9c0* pClock = gpB43dbc_abc9c0;
    uint8_t* pSettings = gpB43c94_abc9c0->GetSettings();
    pClock->Enable(1);
    switch (a) {
    case 0xca35cb74:
        pClock->SetSpeed(0);
        break;
    case 0xca35cb76:
        pClock->SetSpeed(1);
        break;
    case 0xca35cb78:
        pClock->SetSpeed(2);
        break;
    }
    *pSettings = pClock->GetSpeed();
    Fn007e6ee0();
}

#ifdef OB_DRAFTS
// CLOSE: 0x007ec900 score 9
void cSC4View3DWin::Slot44_abc9c0(uint32_t a)
{
    bool bOn = *reinterpret_cast<bool*>(&a);
    mnCostState = bOn;
    if (mnCostState) {
        int32_t nY = mnCursorY;
        mnCostState2 = 2;
        mnCostState = 2;
        mnCostX = mnCursorX;
        mnCostY = nY;
        mfCostTimer = 1500.0f;
        RenderCostIndicator();
        return;
    }
    mfCostTimer = 0.0f;
    mnCostState = 0;
    static_cast<CostWin_abc9c0*>(mpCostWin)->GetChild()->Hide();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007ef7a0 score 4
void cSC4View3DWin::Slot41_abc9c0(uint32_t a)
{
    StrNode_abc9c0* pHead = static_cast<StrNode_abc9c0*>(mpTipList);
    StrNode_abc9c0* pNode = pHead->mpNext;
    while (pNode != pHead) {
        if (pNode->mn8 == a) {
            StrNode_abc9c0* pNext = pNode->mpNext;
            StrNode_abc9c0* pPrev = pNode->mpPrev;
            pPrev->mpNext = pNext;
            pNext->mpPrev = pPrev;
            pNode->mpAlloc24 = &gA80810_abc9c0;
            if (pNode->mpBuf28) {
                StlDelete_abc9c0(pNode->mpBuf28);
            }
            pNode->mpAlloc10 = &gA80810_abc9c0;
            if (pNode->mpBuf14) {
                StlDelete_abc9c0(pNode->mpBuf14);
            }
            StlDelete_abc9c0(pNode);
            break;
        }
        pNode = pNode->mpNext;
    }
    Fn007e8e40();
}
#endif

// FUNCTION: 0x007e6150
bool cSC4View3DWin::Slot11_abc9c0(uint32_t a, uint32_t b)
{
    int32_t nMin = a;
    int32_t nMax = b;
    mnZoomMin = nMin;
    mnZoomMax = nMax;
    if (nMax >= 5) {
        int32_t nLevel = 2;
        uint8_t* pSettings = gpB43c94_abc9c0->GetSettings();
        if (pSettings) {
            nLevel = pSettings[0xf10];
        }
        mnZoomMax = (nLevel > 0) + 4;
    }
    int32_t nZoom = static_cast<Camera_abc9c0*>(mpCamera)->GetVirtualZoom();
    int32_t nTarget = nZoom;
    if (nZoom < nMin) {
        nTarget = nMin;
    } else if (nZoom > nMax) {
        nTarget = nMax;
    }
    if (nTarget != nZoom) {
        Slot08_abc9c0(nTarget);
    }
    return true;
}

// ---- batch 6 ----

// A persistent input control (calls at 0xc, 0x28, 0x5c).
struct InputCtl2_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual bool IsValid() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Attach(void*) = 0;
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
    virtual void Activate() = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007ebea0 score 22
bool cSC4View3DWin::Slot28_abc9c0(uint32_t a)
{
    InputCtl2_abc9c0* pCtl = OB_PTR(InputCtl2_abc9c0, a);
    if (pCtl && pCtl->IsValid()) {
        pCtl->Attach(static_cast<cGZWin*>(this));
        pCtl->AddRef();
        void* pItem = pCtl;
        reinterpret_cast<PtrVec_abc9c0*>(reinterpret_cast<char*>(this) + 0x140)->PushBack(pItem);
        pCtl->Activate();
    }
    return true;
}
#endif

// FUNCTION: 0x007e6ee0
void cSC4View3DWin::Fn007e6ee0()
{
    uint32_t nSpeed = gpB43dbc_abc9c0->GetSpeed();
    if (mpSecondaryMenu) {
        uint32_t ids[3] = { 0xca35cb74, 0xca35cb76, 0xca35cb78 };
        int32_t values[3] = { 0, 1, 2 };
        for (int32_t i = 0; i < 3; ++i) {
            Fn009afe69(mpSecondaryMenu, ids[i], nSpeed == static_cast<uint32_t>(values[i]));
        }
    }
}

// ===== Agent 2 additions =====
// The picker object at +0xf4 seen through its slot 65 (0x104).
struct PickView_abc9c0 {
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
    virtual bool PickOccupant(uint32_t, uint32_t, uint32_t, Unknown_abc9c0**) = 0;
};

// The layer a terrain view hands out (slots 8 and 15).
struct TerrainLayer_abc9c0 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual uint32_t Slot08(uint32_t) = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Slot15(uint32_t) = 0;
};

struct TerrainView_abc9c0 {
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
    virtual TerrainLayer_abc9c0* Slot18(uint32_t) = 0;
};

// STUB: 0x00602160
TerrainView_abc9c0* Fn00602160();

// The object a tertiary menu answers a deep interface query with (calls at 0x24 and 0x44).
struct MenuInfo_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual uint32_t Slot09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual uint32_t Slot17() = 0;
};

struct MenuPair_abc9c0 {
    uint32_t mnFirst;
    uint32_t mnSecond;
};

struct ObliterateCity_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    // STUB: 0x0049cf90
    ObliterateCity_abc9c0* Fn0049cf90();
};

// The tertiary menu at +0x1fc (calls at 0x94 and 0x118).
struct TertiaryMenu_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
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
    virtual bool QueryDeep(uint32_t, uint32_t, MenuInfo_abc9c0**) = 0;
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
    virtual void Hide() = 0;
};

// FUNCTION: 0x007e5fb0
bool cSC4View3DWin::ToggleContourDisplay()
{
    mbContour = !mbContour;
    TerrainView_abc9c0* pView = Fn00602160();
    if (pView) {
        TerrainLayer_abc9c0* pLayer = pView->Slot18(0);
        if (mbContour) {
            if (mnContourHandle == -1) {
                mnContourHandle = pLayer->Slot08(0x7f94205);
            }
        } else {
            int32_t nHandle = mnContourHandle;
            if (nHandle != -1) {
                pLayer->Slot15(nHandle);
                mnContourHandle = -1;
            }
        }
    }
    return mbContour;
}

// FUNCTION: 0x007e6380
bool cSC4View3DWin::Slot17_abc9c0(uint32_t zoom, uint32_t rotation)
{
    int32_t nZoom = zoom;
    int32_t nMin = mnZoomMin;
    if (nZoom < nMin) {
        nZoom = nMin;
    } else {
        int32_t nMax = mnZoomMax;
        if (nZoom > nMax) {
            nZoom = nMax;
        }
    }
    bool bOk = static_cast<View_abc9c0*>(mpPicker)->SetZoomAndRotation(nZoom, rotation);
    if (bOk) {
        if (!mbSimPaused) {
            if (mpSimTarget) {
                mbSimPaused = true;
                static_cast<Pauser_abc9c0*>(mpSimTarget)->Pause();
            }
        }
        reinterpret_cast<Timer_abc9c0*>(reinterpret_cast<char*>(this) + 0x160)->Restart();
    }
    return bOk;
}

// FUNCTION: 0x007e9150
void cSC4View3DWin::ObliterateCity()
{
    if (Fn0078e2f0(0x2a41436c, 0x27df05be) == 0x6a41bbb5) {
        Fn009afd73(mpToolbarWin, 0x4988bc6a, false);
        if (mnPanel == 4) {
            Fn007e8ca0(4);
        }
        void* pMem = ::operator new(0xa8);
        ObliterateCity_abc9c0* pCtl;
        if (pMem) {
            pCtl = static_cast<ObliterateCity_abc9c0*>(pMem)->Fn0049cf90();
        } else {
            pCtl = 0;
        }
        if (pCtl) {
            pCtl->AddRef();
        }
        Slot25_abc9c0(OB_ADDR(pCtl), 2);
        if (pCtl) {
            pCtl->Release();
        }
    }
}

// FUNCTION: 0x007e5890
bool cSC4View3DWin::Slot37_abc9c0(uint32_t x, uint32_t y, uint32_t pOut)
{
    bool bOk = false;
    void** pResult = OB_PTR(void*, pOut);
    *pResult = 0;
    if (mpPicker) {
        Unknown_abc9c0* pObj = 0;
        if (static_cast<PickView_abc9c0*>(mpPicker)->PickOccupant(x, y, 0, &pObj)) {
            Unknown_abc9c0* pFound = OB_PTR(Unknown_abc9c0, pObj->Slot03());
            if (pFound) {
                void* pTmp;
                if (pFound->QueryInterface(0x26bb767e, &pTmp)) {
                    *pResult = pTmp;
                    bOk = true;
                }
            }
            pObj->Release();
        }
    }
    return bOk;
}

// FUNCTION: 0x007e5e90
void cSC4View3DWin::Slot60_abc9c0()
{
    if (mpTertiaryMenu) {
        TertiaryMenu_abc9c0* pMenu = static_cast<TertiaryMenu_abc9c0*>(mpTertiaryMenu);
        if (mpTertiaryData) {
            MenuInfo_abc9c0* pInfo;
            if (pMenu->QueryDeep(0x8a2cad8b, 0x49d98264, &pInfo)) {
                static_cast<MenuPair_abc9c0*>(mpTertiaryData)->mnFirst = pInfo->Slot17();
                static_cast<MenuPair_abc9c0*>(mpTertiaryData)->mnSecond = pInfo->Slot09();
                pInfo->Release();
            }
        }
        static_cast<TertiaryMenu_abc9c0*>(mpTertiaryMenu)->Hide();
        static_cast<TertiaryMenu_abc9c0*>(mpTertiaryMenu)->Release();
        Slot16_adc8d8(OB_ADDR(mpTertiaryMenu));
        mpTertiaryMenu = 0;
        mnTertiary204 = 0;
    }
}

// ===== Agent 2 batch B =====
// STUB: 0x009133da
void* Fn009133da_abc9c0(uint32_t size);

// The 0x2c-byte message object the allocator hands out.
struct Msg_abc9c0 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetType(uint32_t);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void SetKey(uint32_t);
    virtual void SetPtrA(void*);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void SetFlag(uint32_t);
    virtual void SetPtrB(void*);
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    Msg_abc9c0();
    static void* operator new(size_t size) { return Fn009133da_abc9c0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// The message server (the global at 0xb43ccc): slot 3 posts a message.
struct MsgPost_abc9c0 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Post(void*) = 0;
};

// GLOBAL: 0x00b43ccc
extern MsgPost_abc9c0* gpB43ccc_abc9c0;

struct HashEntry_abc9c0 {
    HashEntry_abc9c0* mpNext;
    uint32_t mnKey;
    uint32_t mnCount;
};

// The hash map of global effect triggers at +0x428.
struct TriggerMap_abc9c0 {
    uint32_t mnPad;
    HashEntry_abc9c0** mpBuckets;
    HashEntry_abc9c0** mpBucketsEnd;
    HashEntry_abc9c0* Find(uint32_t key)
    {
        uint32_t nCount = mpBucketsEnd - mpBuckets;
        HashEntry_abc9c0* pNode = mpBuckets[key % nCount];
        while (pNode && pNode->mnKey != key) {
            pNode = pNode->mpNext;
        }
        return pNode;
    }
    // STUB: 0x004f8d30
    uint32_t* Fn004f8d30(uint32_t* key);
    // STUB: 0x00489cf0
    void Fn00489cf0(HashEntry_abc9c0** it);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007ecce0 score 51: key held in a register by the original's inlined find; the loop head order differs
void cSC4View3DWin::Slot47_abc9c0(uint32_t key)
{
    TriggerMap_abc9c0* pMap = reinterpret_cast<TriggerMap_abc9c0*>(reinterpret_cast<char*>(this) + 0x428);
    HashEntry_abc9c0* pNode = pMap->Find(key);
    if (!pNode) {
        *pMap->Fn004f8d30(&key) = 1;
        MsgPost_abc9c0* pServer = gpB43ccc_abc9c0;
        Msg_abc9c0* pMsg = new Msg_abc9c0;
        pMsg->AddRef();
        pMsg->SetType(0xaa375fe8);
        pMsg->SetKey(key);
        pMsg->SetFlag(1);
        pServer->Post(pMsg);
        pMsg->Release();
    } else {
        pNode->mnCount = pNode->mnCount + 1;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007eb8a0 score 68: same inlined find as 007ecce0
void cSC4View3DWin::Slot48_abc9c0(uint32_t key)
{
    TriggerMap_abc9c0* pMap = reinterpret_cast<TriggerMap_abc9c0*>(reinterpret_cast<char*>(this) + 0x428);
    HashEntry_abc9c0* pNode = pMap->Find(key);
    if (pNode) {
        if (pNode->mnCount > 1) {
            pNode->mnCount = pNode->mnCount - 1;
        } else {
            HashEntry_abc9c0* pIt = pNode;
            pMap->Fn00489cf0(&pIt);
            MsgPost_abc9c0* pServer = gpB43ccc_abc9c0;
            Msg_abc9c0* pMsg = new Msg_abc9c0;
            pMsg->AddRef();
            pMsg->SetType(0xaa375fe8);
            pMsg->SetKey(key);
            pMsg->SetFlag(0);
            pServer->Post(pMsg);
            pMsg->Release();
        }
    }
}
#endif

// ===== Agent 2 batch C =====
struct InputCtlB_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Pad03() = 0;
    virtual void Slot04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual uint32_t Slot07() = 0;
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
    virtual void Slot24() = 0;
};

struct CursorHolder_abc9c0 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual uint32_t Slot09(uint32_t) = 0;
};

struct WinCursor_abc9c0 {
    // STUB: 0x0099bf14
    CursorHolder_abc9c0* Fn0099bf14();
};

struct ViewRange_abc9c0 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual bool Slot06(float) = 0;
};

struct ViewWithRange_abc9c0 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual ViewRange_abc9c0* Slot09() = 0;
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
    virtual void Slot20() = 0;
};

struct CityNode_abc9c0 {
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
    virtual void Slot11() = 0;
};

struct FundsObj_abc9c0 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual int64_t Slot06() = 0;
};

struct CityHolder_abc9c0 {
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
    virtual FundsObj_abc9c0* Slot52() = 0;
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
    virtual CityNode_abc9c0* Slot72() = 0;
};

// GLOBAL: 0x00b43cec
extern CityHolder_abc9c0* gpB43cec_abc9c0;

struct Ctl90_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    // STUB: 0x004ba7d0
    Ctl90_abc9c0* Fn004ba7d0(uint32_t);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007e9390 score 20: this+0xc cached in ebp for the cGZWin calls; our copy reloads it
bool cSC4View3DWin::Slot26_abc9c0(uint32_t bKeepCursor)
{
    InputCtlB_abc9c0* pCtl = OB_PTR(InputCtlB_abc9c0, Slot24_abc9c0());
    if (pCtl) {
        pCtl->AddRef();
        cGZWin* pWin = this;
        pWin->GZReleaseCapture();
        --mpInputControlsEnd;
        pCtl->Slot24();
        pCtl->Slot04();
        pCtl->Release();
        if (!(bKeepCursor & 0xff)) {
            InputCtlB_abc9c0* pNext = OB_PTR(InputCtlB_abc9c0, Slot24_abc9c0());
            if (pNext) {
                pNext->AddRef();
                pWin->SetCursor(pNext->Slot07(), 1);
                Fn007e8090(OB_ADDR(pCtl), OB_ADDR(pNext));
                pNext->Release();
            } else {
                uint32_t nCursor = reinterpret_cast<WinCursor_abc9c0*>(pWin)->Fn0099bf14()->Slot09(0xc16c4e1b);
                if (nCursor) {
                    pWin->SetCursor(nCursor, 1);
                }
            }
        }
        pCtl->Release();
        return true;
    }
    return false;

}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007e6e40 score 51: register allocation; unsigned int to float conversions
void cSC4View3DWin::Fn007e6e40()
{
    if (mpPicker) {
        uint32_t nHour = gpB43dbc_abc9c0->Slot12();
        uint32_t nMinute = gpB43dbc_abc9c0->Slot15();
        gpB43c94_abc9c0->GetSettings();
        ViewRange_abc9c0* pRange = static_cast<ViewWithRange_abc9c0*>(mpPicker)->Slot09();
        if (pRange) {
            float fTime = static_cast<float>(nMinute) * (1.0f / 60.0f) + static_cast<float>(nHour);
            if (pRange->Slot06(fTime)) {
                static_cast<ViewWithRange_abc9c0*>(mpPicker)->Slot20();
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007e7130 score 75: original switch duplicates the construction tail; constant 1/60 guessed
void cSC4View3DWin::Fn007e7130(uint32_t pWin, uint32_t pMsg)
{
    uint32_t nId = *(OB_PTR(uint32_t, pMsg) + 2);
    int32_t nArg;
    switch (nId) {
    case 1:
        Fn007e5d80(0x9de3002, 0x9de8798, pMsg, 1, 0xffffffe7);
        return;
    case 0x992fd36:
        gpB43cec_abc9c0->Slot72()->Slot11();
        return;
    case 0x33:
    case 0x69a30679:
        nArg = (nId != 0x33);
        break;
    case 0x4bfc8c2f:
    case 0x6bfc8c55:
        nArg = (nId == 0x4bfc8c2f) + 5;
        break;
    default:
        return;
    }
    void* pMem = ::operator new(0x90);
    Ctl90_abc9c0* pCtl;
    if (pMem) {
        pCtl = static_cast<Ctl90_abc9c0*>(pMem)->Fn004ba7d0(nArg);
    } else {
        pCtl = 0;
    }
    if (pCtl) {
        pCtl->AddRef();
    }
    Slot25_abc9c0(OB_ADDR(pCtl), 2);
    if (pCtl) {
        pCtl->Release();
    }
}
#endif

// FUNCTION: 0x007e6500
void cSC4View3DWin::Slot21_abc9c0(uint32_t pInfo)
{
    uint32_t nOld = mnViewLevel;
    uint32_t nNew = *OB_PTR(uint32_t, pInfo);
    if (nOld != nNew) {
        mnViewLevel = nNew;
        MsgPost_abc9c0* pServer = gpB43ccc_abc9c0;
        uint32_t aOld = nOld;
        uint32_t aNew = nNew;
        Msg_abc9c0* pMsg = new Msg_abc9c0;
        pMsg->AddRef();
        pMsg->SetType(0xc6cdbf1a);
        pMsg->SetPtrA(&aOld);
        pMsg->SetPtrB(&aNew);
        pServer->Post(pMsg);
        pMsg->Release();
        pMsg = new Msg_abc9c0;
        pMsg->AddRef();
        pMsg->SetType(0xc6cdbf1b);
        pMsg->SetPtrA(&aOld);
        pMsg->SetPtrB(&aNew);
        pServer->Post(pMsg);
        pMsg->Release();
    }
}

// FUNCTION: 0x007e63f0
bool cSC4View3DWin::Slot19_abc9c0(uint32_t pInfo)
{
    Unknown_abc9c0* pOld = static_cast<Unknown_abc9c0*>(mpViewFilter);
    if (pOld) {
        pOld->AddRef();
    }
    MsgPost_abc9c0* pServer = gpB43ccc_abc9c0;
    Msg_abc9c0* pMsg = new Msg_abc9c0;
    pMsg->AddRef();
    pMsg->SetType(0x6cdb65a);
    pMsg->SetPtrA(&pOld);
    pMsg->SetPtrB(OB_PTR(void, pInfo));
    pServer->Post(pMsg);
    pMsg->Release();
    Unknown_abc9c0* pNew = *OB_PTR(Unknown_abc9c0*, pInfo);
    if (mpViewFilter != pNew) {
        if (pNew) {
            pNew->AddRef();
        }
        if (mpViewFilter) {
            static_cast<Unknown_abc9c0*>(mpViewFilter)->Release();
        }
        mpViewFilter = *OB_PTR(Unknown_abc9c0*, pInfo);
    }
    pMsg = new Msg_abc9c0;
    pMsg->AddRef();
    pMsg->SetType(0x6cdb65b);
    pMsg->SetPtrA(&pOld);
    pMsg->SetPtrB(OB_PTR(void, pInfo));
    pServer->Post(pMsg);
    pMsg->Release();
    if (pOld) {
        pOld->Release();
    }
    return true;
}

// ===== Agent 2 batch D =====
struct InputCtlC_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual bool Slot03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual uint32_t Slot07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Slot10(void*) = 0;
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
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
};

struct Widget_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
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
    virtual void Slot69() = 0;
    virtual void Slot70() = 0;
    virtual bool Slot71() = 0;
};

// STUB: 0x009afcfe
void Fn009afcfe(void* pWin, uint32_t id, uint32_t a, uint32_t b);

// FUNCTION: 0x007e91e0
void cSC4View3DWin::Slot55_abc9c0(uint32_t bMinimize)
{
    if (bMinimize & 0xff) {
        if (static_cast<Widget_abc9c0*>(mpToolbarWin)->Slot71()) {
            static_cast<Widget_abc9c0*>(mpToolbarWin)->Slot70();
            if (mnPanel != -1) {
                Fn007e8ca0(mnPanel);
            }
            static_cast<Widget_abc9c0*>(mpPanelA)->Slot06();
            Slot59_abc9c0();
            if (mpPanelB) {
                static_cast<Widget_abc9c0*>(mpPanelB)->Slot70();
            }
            static_cast<Widget_abc9c0*>(mpPanelC)->Slot69();
            Fn009afcfe(static_cast<cGZWin*>(this), 0xea8cad14, 0, 0);
        }
    } else {
        if (!static_cast<Widget_abc9c0*>(mpToolbarWin)->Slot71()) {
            static_cast<Widget_abc9c0*>(mpToolbarWin)->Slot69();
            if (mnPanel != -1) {
                ShowPanel(mnPanel);
            }
            if (mpPanelB) {
                static_cast<Widget_abc9c0*>(mpPanelB)->Slot69();
            }
            if (mbPanelFlag2d5 || mbPanelFlag2d4 || mbPanelFlag2d6) {
                static_cast<Widget_abc9c0*>(mpPanelA)->Slot05();
            }
            static_cast<Widget_abc9c0*>(mpPanelC)->Slot70();
            Fn009afcfe(static_cast<cGZWin*>(this), 0xea8cad14, 1, 0);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x007ebd70 score 87: register assignment (edi/ebx swapped for the control and previous control); statement order of the tail
bool cSC4View3DWin::Slot25_abc9c0(uint32_t pControl, uint32_t nMode)
{
    InputCtlC_abc9c0* pCtl = OB_PTR(InputCtlC_abc9c0, pControl);
    if (pCtl) {
        pCtl->Slot10(static_cast<cGZWin*>(this));
    }
    InputCtlC_abc9c0* pPrev = OB_PTR(InputCtlC_abc9c0, Slot24_abc9c0());
    if (pPrev) {
        pPrev->AddRef();
    }
    Fn007e8090(OB_ADDR(pPrev), OB_ADDR(pCtl));
    if (nMode == 1) {
        Slot26_abc9c0(0);
    } else if (nMode == 2) {
        Slot27_abc9c0(0);
    }
    InputCtlC_abc9c0* pCur = OB_PTR(InputCtlC_abc9c0, Slot24_abc9c0());
    if (pCur != pPrev) {
        if (pCur) {
            pCur->AddRef();
        }
        if (pPrev) {
            pPrev->Release();
        }
        pPrev = pCur;
    }
    if (pPrev) {
        pPrev->Slot22();
        pPrev->Slot24();
    }
    if (pCtl && pCtl->Slot03()) {
        pCtl->AddRef();
        void* pItem = pCtl;
        reinterpret_cast<PtrVec_abc9c0*>(reinterpret_cast<char*>(this) + 0x134)->PushBack(pItem);
        pCtl->Slot23();
        uint32_t nCursor = pCtl->Slot07();
        if (nCursor) {
            SetCursor(nCursor, 1);
        }
    }
    if (pPrev) {
        pPrev->Release();
    }
    return true;
}
#endif

// ===== Agent 2 batch E =====
struct ColorObj_abc9c0 {
    virtual bool QueryInterface(uint32_t, void**) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void SetColor(uint32_t, uint32_t, uint32_t, uint32_t) = 0;
};

struct CostWinB_abc9c0 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual Widget_abc9c0* Slot03() = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007ec800 score 51: unsigned limit test and the zero register shared with the timer store; alpha select (setne/dec/and) not reproduced
void cSC4View3DWin::Slot42_abc9c0(uint32_t nCost, uint32_t nLimit)
{
    int64_t nFunds = 0;
    uint32_t nOver = 0;
    CityHolder_abc9c0* pCity = gpB43cec_abc9c0;
    if (pCity) {
        FundsObj_abc9c0* pFunds = pCity->Slot52();
        if (pFunds) {
            nFunds = pFunds->Slot06();
        }
    }
    if (nLimit != 0 && static_cast<int64_t>(nLimit) > nFunds) {
        nOver = 1;
    }
    mfCostTimer = 0.0f;
    if (mnCostState != 1 || mnCostState2 != nOver || mnCostValue != nCost) {
        mnCostState = 1;
        mnCostState2 = nOver;
        mnCostValue = nCost;
        RenderCostIndicator();
        ColorObj_abc9c0* pColor = 0;
        if (static_cast<Unknown_abc9c0*>(mpCaptionWin)->QueryInterface(0x86d72b57, reinterpret_cast<void**>(&pColor))) {
            pColor->SetColor(0xff, 0xff, 0xff, nOver != 1 ? 0x96 : 0xff);
            pColor->Release();
        }
        if (mpCostWin) {
            static_cast<CostWinB_abc9c0*>(mpCostWin)->Slot03()->Slot69();
        }
    }
}
#endif
