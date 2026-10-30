#include <cstddef>
#include <stdio.h>

#include "classes/cUnk00ac3090.h"
#include "common/winapi.h"

// Views of the objects this framework class talks to: only the slots used here are named.
struct Lock_ac3090 {
    virtual void Pad00();
    virtual void Enter();
    virtual void Leave();
};
// The scope guard around the class's lock: entered when built, left when it ends.
struct Guard_ac3090 {
    uint32_t mn00;
    Lock_ac3090* mpLock;
    // STUB: 0x0048c9f0
    void Fn0048c9f0(void* pLock);
    ~Guard_ac3090() { mpLock->Leave(); }
};
struct Client_ac3090 {
    virtual bool Call(uint32_t a, void* b);
    virtual void AddRef();
    virtual void Release();
    virtual uint32_t GetId();
    virtual void Pad04();
    virtual int32_t GetPriority();
    virtual void Pad06();
    virtual void SetFlag(bool b);
    virtual bool IsFlag();
    virtual bool IsReady();
    virtual void Notify(uint32_t n);
    virtual void Notify2(uint32_t n);
    virtual int32_t GetOrder();
};
struct Client2_ac3090 {
    virtual bool Call(uint32_t a, uint32_t b);
};
struct Hooked_ac3090 {
    virtual bool Query(uint32_t nIid, void** ppOut);
    virtual void AddRef();
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
    virtual void Notify(uint32_t n);
};
struct ListNode_ac3090 {
    ListNode_ac3090* mpNext;
    ListNode_ac3090* mpPrev;
    void* mpData;
};
struct TreeNode_ac3090 {
    TreeNode_ac3090* mpParent;
    TreeNode_ac3090* mpLeft;
    TreeNode_ac3090* mpRight;
    uint32_t mnColour;
    int32_t mnKey;
};
// One receiver for the container operations of the framework's STL (each STUB leads to the original).
struct Op_ac3090 {
    void* mpHead;
    uint32_t mnSize;
    // STUB: 0x0094909a
    void PushBack(void* pValue);
    // STUB: 0x00473ec0
    void Clear();
    // STUB: 0x005447b0
    void Assign(void* pValue);
    // STUB: 0x0090dbcd
    void AssignRef(void* ppValue);
    // STUB: 0x00968cd9
    ListNode_ac3090* Find(void* pKey);
    // STUB: 0x00968c53
    void Erase(void* pIter);
    // STUB: 0x00968d88
    void EraseIter(void* pIter);
    // STUB: 0x0097c081
    void Begin(void* pOut);
    // STUB: 0x00969127
    void Next(void* pOut);
    // STUB: 0x00966956
    void Fn00966956(void* pValue);
    // STUB: 0x004f20c0
    void* MakeRef(void* pObj);
    // STUB: 0x0093f7eb
    void Fn0093f7eb(void* pFlag);
    // STUB: 0x00879951
    void Fn00879951();
    // STUB: 0x0093baef
    void Fn0093baef();
    // STUB: 0x007ebd30
    void PushBackVec(void* pValue);
    // STUB: 0x0040e490
    void EraseVec(void* pFirst, void* pLast);
    // STUB: 0x00879e68
    void Fn00879e68();
    // STUB: 0x00879968
    void Fn00879968(void* pNode);
    // STUB: 0x00879e91
    void Fn00879e91(void* pOut, void* pKey);
    // STUB: 0x00879a46
    void Fn00879a46(void* pOut, uint32_t a, void* pParent, void* pKey, uint32_t b);
    // STUB: 0x0087999f
    void Fn0087999f(void* pOut, void* pPair);
    // STUB: 0x0087a66f
    void* Fn0087a66f(void* pOut, void* pPair);
    // STUB: 0x00879886
    void* Fn00879886(void* pKey);
    // STUB: 0x0099a579
    void* Fn0099a579(void* pKey);
    // STUB: 0x0092bc4a
    void Fn0092bc4a();
    // STUB: 0x0092bc80
    void Fn0092bc80();
    // STUB: 0x0087a178
    void Fn0087a178(void* pOut);
};
struct Ref_ac3090 {
    void* mp;
};
struct Msg_ac3090 {
    uint32_t mHwnd;
    uint32_t mnMessage;
    uint32_t mnWParam;
    uint32_t mnLParam;
    uint32_t mnTime;
    uint32_t mX;
    uint32_t mY;
};

// GLOBAL: 0x00b540b4
extern uint32_t gB540b4;
// GLOBAL: 0x00b540a8
extern uint32_t gB540a8;

// STUB: 0x0090cf63
void Fn0090cf63(void* p);
// STUB: 0x0040d4c0
void* Fn0040d4c0(void* pNode);
// STUB: 0x0040d500
void* Fn0040d500(void* pNode);
// STUB: 0x009d07a0
void Fn009d07a0(void** pOut, void* pFirst, void* pLast, void* pValue);
// STUB: 0x009978af
uint32_t OB_STDCALL Fn009978af(uint32_t nCount);
// STUB: 0x0087985a
void OB_STDCALL Fn0087985a(void* pOut, void* pNode);
// STUB: 0x0090ff9c
uint32_t Fn0090ff9c(const char* pName, const char* pValue);

// Imports the original calls (named from their use; reported as asks).
OB_WINAPI int32_t OB_STDCALL WaitMessage();
OB_WINAPI int32_t OB_STDCALL TranslateMessage(const void* pMsg);
OB_WINAPI int32_t OB_STDCALL DispatchMessageA(const void* pMsg);
OB_WINAPI int32_t OB_STDCALL PeekMessageA(void* pMsg, uint32_t hWnd, uint32_t nMin, uint32_t nMax, uint32_t nRemove);
OB_WINAPI void OB_STDCALL PostQuitMessage(int32_t nCode);
OB_WINAPI int32_t OB_STDCALL MessageBoxA(uint32_t hWnd, const char* pText, const char* pCaption, uint32_t nType);
OB_WINAPI void OB_STDCALL OutputDebugStringA(const char* pText);
OB_WINAPI int32_t OB_STDCALL SetEnvironmentVariableA(const char* pName, const char* pValue);

// FUNCTION: 0x00879355
uint32_t cUnk00ac3090::Slot01_ac3090()
{
    Guard_ac3090 g;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    uint32_t n = ++mnRefCount;
    return n;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00879383 score 12
uint32_t cUnk00ac3090::Slot02_ac3090()
{
    Guard_ac3090 g;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    uint32_t n;
    uint32_t c = mnRefCount;
    if (c > 1) {
        --c;
        mnRefCount = c;
        n = c;
    } else {
        n = 0;
    }
    return n;
}
#endif

// FUNCTION: 0x00879427
void cUnk00ac3090::Slot36_ac3090(uint32_t nValue)
{
    Guard_ac3090 g;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    gB540b4 = nValue;
}

// FUNCTION: 0x0087944f
void cUnk00ac3090::Slot14_ac3090(uint32_t nValue)
{
    if (static_cast<int32_t>(nValue) > 0) {
        mnBc = nValue;
    } else {
        mnBc = 1;
    }
}

// FUNCTION: 0x00879473
uint32_t cUnk00ac3090::Slot37_ac3090()
{
    return gB540b4;
}

// FUNCTION: 0x00879487
void cUnk00ac3090::Slot26_ac3090()
{
    Slot25_ac3090();
}

// FUNCTION: 0x0087948c
void cUnk00ac3090::Slot29_ac3090(uint32_t nLevel)
{
    char buf[0x40];
    mnDebugLevel = nLevel;
    sprintf(buf, "%d", nLevel);
    Fn0090ff9c("GZFRAMEWORK_DEBUG_LEVEL", buf);
}

// FUNCTION: 0x0090ff9c
uint32_t Fn0090ff9c(const char* pName, const char* pValue)
{
    return SetEnvironmentVariableA(pName, pValue) != 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0087950f score 21
bool cUnk00ac3090::Slot34_ac3090(uint32_t nKind, uint32_t nArg, void* pOut)
{
    Guard_ac3090 g;
    bool bResult = false;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    if (pOut) {
        Client_ac3090* c = 0;
        switch (nKind) {
        case 0:
            c = reinterpret_cast<Client_ac3090*>(Slot33_ac3090());
            break;
        case 1:
            c = reinterpret_cast<Client_ac3090*>(Slot32_ac3090());
            break;
        case 2:
            c = reinterpret_cast<Client_ac3090*>(Slot31_ac3090());
            break;
        default:
            break;
        }
        if (c) {
            bResult = c->Call(nArg, pOut);
        }
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008795bd score 16
void cUnk00ac3090::Slot48_ac3090()
{
    Msg_ac3090 msg;
    if (!mbB8) {
        WaitMessage();
    }
    for (;;) {
        while (PeekMessageA(&msg, 0, 0, 0, 1)) {
            if (msg.mnMessage == 0x12) {
                gB540a8 = msg.mnWParam;
                return;
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        if (mbB8) {
            Slot16_ac3090();
            if (mbHave124 && mbHave140) {
                gB540a8 = mnValue144;
                return;
            }
        } else {
            WaitMessage();
        }
    }
}
#endif

// FUNCTION: 0x0087963d
void cUnk00ac3090::Slot19_ac3090(uint32_t nValue)
{
    Guard_ac3090 g;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    if (mbHave124) {
        mbHave140 = true;
        mnValue144 = nValue;
    } else {
        PostQuitMessage(nValue);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00879685 score 11
void cUnk00ac3090::Slot38_ac3090(void* pText)
{
    const char* text = static_cast<const char*>(pText);
    if (!text) {
        text = "";
    }
    Slot18_ac3090(false);
    MessageBoxA(0, text, "", 0x30);
    Slot18_ac3090(true);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008796bd score 15
void* cUnk00ac3090::Slot31_ac3090()
{
    Guard_ac3090 g;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    Op_ac3090* slot = reinterpret_cast<Op_ac3090*>(&mpObj12c);
    if (!mpObj12c) {
        Op_ac3090* p = static_cast<Op_ac3090*>(::operator new(0x10));
        if (p) {
            p->Fn0092bc4a();
        }
        slot->Assign(p);
    }
    return mpObj12c;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087970d score 15
void* cUnk00ac3090::Slot32_ac3090()
{
    Guard_ac3090 g;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    Op_ac3090* slot = reinterpret_cast<Op_ac3090*>(&mpObj130);
    if (!mpObj130) {
        Op_ac3090* p = static_cast<Op_ac3090*>(::operator new(0x10));
        if (p) {
            p->Fn0092bc4a();
        }
        slot->Assign(p);
    }
    return mpObj130;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087975d score 20
void* cUnk00ac3090::Slot33_ac3090()
{
    Guard_ac3090 g;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    Op_ac3090* slot = reinterpret_cast<Op_ac3090*>(&mpObj134);
    if (!mpObj134) {
        Op_ac3090* p = static_cast<Op_ac3090*>(::operator new(0x14));
        if (p) {
            p->Fn0092bc80();
        }
        slot->PushBack(p);
    }
    return mpObj134;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008797ad score 45
bool cUnk00ac3090::Slot35_ac3090(uint32_t nKind, void* pObj)
{
    Guard_ac3090 g;
    bool bResult = false;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    Op_ac3090* slot = 0;
    switch (nKind) {
    case 0:
        slot = reinterpret_cast<Op_ac3090*>(&mpObj12c);
        break;
    case 1:
        slot = reinterpret_cast<Op_ac3090*>(&mpObj130);
        break;
    case 2:
        slot = reinterpret_cast<Op_ac3090*>(&mpObj134);
        break;
    default:
        break;
    }
    if (slot) {
        if (pObj) {
            slot->Assign(pObj);
            bResult = static_cast<Client_ac3090*>(pObj)->Call(0xc51b11cb, slot);
        } else {
            slot->Assign(0);
            bResult = true;
        }
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008798aa score 24
bool cUnk00ac3090::Slot08_ac3090(void* pClient)
{
    Guard_ac3090 g;
    bool bResult = false;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    if (!mbD4) {
        void* ref = pClient;
        Op_ac3090* list = reinterpret_cast<Op_ac3090*>(&mpList84);
        void* it;
        Fn009d07a0(&it, list->mpHead, *static_cast<void**>(list->mpHead), &ref);
        if (it != list->mpHead) {
            list->Erase(it);
            ++bResult;
        }
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00879bb9 score 72
bool cUnk00ac3090::Slot09_ac3090(void* pClient)
{
    Guard_ac3090 g;
    bool bResult = false;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    if (!mbD3) {
        Client_ac3090* c = static_cast<Client_ac3090*>(pClient);
        int32_t nOrder = c->GetOrder();
        uint32_t nId = c->GetId();
        ListNode_ac3090* head = *reinterpret_cast<ListNode_ac3090**>(&mpList_b0);
        ListNode_ac3090* n = head->mpNext;
        bool bFound = false;
        while (n != head) {
            ListNode_ac3090* next = n->mpNext;
            Client_ac3090* e = static_cast<Client_ac3090*>(n->mpData);
            if (nId == e->GetId()) {
                bFound = true;
                break;
            }
            if (nOrder <= e->GetOrder()) {
                n = next;
                continue;
            }
            n = next;
        }
        if (!bFound) {
            Op_ac3090* list = reinterpret_cast<Op_ac3090*>(&mpList_b0);
            void* ref = list->MakeRef(pClient);
            list->PushBack(ref);
            bResult = true;
        }
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00879c6c score 63
bool cUnk00ac3090::Slot10_ac3090(void* pClient)
{
    Guard_ac3090 g;
    bool bResult = false;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    if (!mbD3) {
        if (mnDc > 0) {
            Op_ac3090* pending = reinterpret_cast<Op_ac3090*>(&mpList_b4);
            void* ref = 0;
            pending->AssignRef(&ref);
            void* list = *static_cast<void**>(pending->mpHead);
            static_cast<Op_ac3090*>(static_cast<ListNode_ac3090*>(list)->mpNext->mpData)->PushBack(pClient);
        }
        Op_ac3090* list = reinterpret_cast<Op_ac3090*>(&mpList_b0);
        void* ref = pClient;
        void* it;
        Fn009d07a0(&it, list->mpHead, *static_cast<void**>(list->mpHead), &ref);
        if (it != list->mpHead) {
            Fn0087985a(list, it);
            bResult = true;
        }
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00879d21 score 39
bool cUnk00ac3090::Slot11_ac3090(void* pClient)
{
    Guard_ac3090 g;
    bool bResult = false;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    if (!mbD2) {
        void* ref = pClient;
        Op_ac3090* list = reinterpret_cast<Op_ac3090*>(&mpList_a8);
        void* it;
        Fn009d07a0(&it, list->mpHead, *static_cast<void**>(list->mpHead), &ref);
        if (it == list->mpHead) {
            ref = 0;
            list->AssignRef(&ref);
            list->PushBack(pClient);
            bResult = true;
        }
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00879db3 score 62
bool cUnk00ac3090::Slot12_ac3090(void* pClient)
{
    Guard_ac3090 g;
    bool bResult = false;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    if (!mbD2) {
        if (mnD8 > 0) {
            Op_ac3090* pending = reinterpret_cast<Op_ac3090*>(&mpList_ac);
            void* ref = 0;
            pending->AssignRef(&ref);
            pending->PushBack(pClient);
        }
        Op_ac3090* list = reinterpret_cast<Op_ac3090*>(&mpList_a8);
        void* ref = pClient;
        void* it;
        Fn009d07a0(&it, list->mpHead, *static_cast<void**>(list->mpHead), &ref);
        if (it != list->mpHead) {
            Fn0087985a(list, it);
            bResult = true;
        }
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00879f15 score 49
bool cUnk00ac3090::Slot41_ac3090()
{
    Hooked_ac3090* hook = 0;
    Client_ac3090* owner = reinterpret_cast<Client_ac3090*>(Slot37_ac3090());
    (void)owner;
    Op_ac3090 snap;
    snap.Fn0093f7eb(&hook);
    Fn00879ace(&snap, false);
    ListNode_ac3090* head = static_cast<ListNode_ac3090*>(snap.mpHead);
    for (ListNode_ac3090* n = head->mpNext; n != head; n = n->mpNext) {
        Client_ac3090* c = static_cast<Client_ac3090*>(n->mpData);
        if (c->GetPriority() > static_cast<int32_t>(0xffe17b80)) {
            if (c->IsFlag()) {
                c->SetFlag(true);
            }
        }
    }
    snap.Fn00879951();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00879fbc score 45
bool cUnk00ac3090::Slot42_ac3090()
{
    bool bResult = true;
    Op_ac3090 snap;
    uint8_t flag;
    snap.Fn0093f7eb(&flag);
    Fn00879ace(&snap, false);
    ListNode_ac3090* head = static_cast<ListNode_ac3090*>(snap.mpHead);
    for (ListNode_ac3090* n = head->mpNext; n != head; n = n->mpNext) {
        Client_ac3090* c = static_cast<Client_ac3090*>(n->mpData);
        int32_t p = c->GetPriority();
        if (p > static_cast<int32_t>(0xffe17b80) || p < static_cast<int32_t>(0xffd23941)) {
            continue;
        }
        if (c->IsFlag()) {
            c->SetFlag(true);
        } else {
            void* out;
            if (!c->Call(0x66, &out)) {
                bResult = false;
                break;
            }
        }
    }
    snap.Fn00879951();
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a046 score 16
bool cUnk00ac3090::Slot43_ac3090()
{
    Op_ac3090 snap;
    uint8_t flag;
    snap.Fn0093f7eb(&flag);
    Fn00879ace(&snap, false);
    ListNode_ac3090* head = static_cast<ListNode_ac3090*>(snap.mpHead);
    for (ListNode_ac3090* n = head->mpNext; n != head; n = n->mpNext) {
        Client_ac3090* c = static_cast<Client_ac3090*>(n->mpData);
        if (c->GetPriority() < static_cast<int32_t>(0xffd23941)) {
            if (c->IsFlag()) {
                c->SetFlag(true);
            }
        }
    }
    snap.Fn00879951();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a0ac score 2
bool cUnk00ac3090::Slot05_ac3090(uint32_t nKey, uint32_t nArg, uint32_t nArg2)
{
    Guard_ac3090 g;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    ListNode_ac3090* node = reinterpret_cast<Op_ac3090*>(&mpMap94)->Find(&nKey);
    bool bResult = false;
    mbD1 = true;
    if (node) {
        bResult = static_cast<Client2_ac3090*>(node->mpData)->Call(nArg, nArg2);
    }
    mbD1 = false;
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a106 score 40
bool cUnk00ac3090::Slot06_ac3090(void* pTarget, uint32_t nArg, uint32_t nArg2)
{
    Op_ac3090 snap;
    uint8_t flag;
    snap.Fn0093f7eb(&flag);
    Fn00879ace(&snap, false);
    ListNode_ac3090* head = static_cast<ListNode_ac3090*>(snap.mpHead);
    for (ListNode_ac3090* n = head->mpNext; n != head; n = n->mpNext) {
        Client_ac3090* c = static_cast<Client_ac3090*>(n->mpData);
        Client_ac3090* found = 0;
        if (c->Call(1, &found)) {
            static_cast<Client2_ac3090*>(pTarget)->Call(nArg, nArg2);
            found->Release();
        }
    }
    snap.Fn00879951();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a1f4 score 39
bool cUnk00ac3090::Slot07_ac3090(void* pClient)
{
    Guard_ac3090 g;
    bool bResult = false;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    if (!mbD4) {
        void* ref = pClient;
        Op_ac3090* list = reinterpret_cast<Op_ac3090*>(&mpList84);
        void* it;
        Fn009d07a0(&it, list->mpHead, *static_cast<void**>(list->mpHead), &ref);
        if (it == list->mpHead) {
            ref = 0;
            list->AssignRef(&ref);
            list->PushBack(pClient);
            bResult = true;
        }
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a466 score 26
bool cUnk00ac3090::Fn0087a466()
{
    if (!mbD4) {
        uint8_t flag;
        Op_ac3090 snap;
        snap.Fn0093f7eb(&flag);
        Fn0087a178(&snap);
        ListNode_ac3090* head = static_cast<ListNode_ac3090*>(snap.mpHead);
        for (ListNode_ac3090* n = head->mpNext; n != head; n = n->mpNext) {
            static_cast<Client_ac3090*>(n->mpData)->Notify(0);
        }
        snap.Fn0093baef();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a4b6 score 37
bool cUnk00ac3090::Slot44_ac3090()
{
    bool bResult = true;
    uint8_t flag;
    Op_ac3090 snap;
    snap.Fn0093f7eb(&flag);
    Fn00879ace(&snap, true);
    ListNode_ac3090* head = static_cast<ListNode_ac3090*>(snap.mpHead);
    for (ListNode_ac3090* n = head->mpNext; n != head; n = n->mpNext) {
        Client_ac3090* c = static_cast<Client_ac3090*>(n->mpData);
        if (c->GetPriority() < static_cast<int32_t>(0xffd23941)) {
            if (c->IsReady()) {
                c->SetFlag(false);
            } else {
                bResult = false;
            }
        }
    }
    snap.Fn00879951();
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a527 score 39
bool cUnk00ac3090::Slot45_ac3090()
{
    bool bResult = true;
    uint8_t flag;
    Op_ac3090 snap;
    snap.Fn0093f7eb(&flag);
    Fn00879ace(&snap, true);
    ListNode_ac3090* head = static_cast<ListNode_ac3090*>(snap.mpHead);
    for (ListNode_ac3090* n = head->mpNext; n != head; n = n->mpNext) {
        Client_ac3090* c = static_cast<Client_ac3090*>(n->mpData);
        int32_t p = c->GetPriority();
        if (p >= static_cast<int32_t>(0xffd23941) && p <= static_cast<int32_t>(0xffe17b80)) {
            if (c->IsReady()) {
                c->SetFlag(false);
            } else {
                bResult = false;
            }
        }
    }
    snap.Fn00879951();
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a59f score 37
bool cUnk00ac3090::Slot46_ac3090()
{
    bool bResult = true;
    uint8_t flag;
    Op_ac3090 snap;
    snap.Fn0093f7eb(&flag);
    Fn00879ace(&snap, true);
    ListNode_ac3090* head = static_cast<ListNode_ac3090*>(snap.mpHead);
    for (ListNode_ac3090* n = head->mpNext; n != head; n = n->mpNext) {
        Client_ac3090* c = static_cast<Client_ac3090*>(n->mpData);
        if (c->GetPriority() > static_cast<int32_t>(0xffe17b80)) {
            if (c->IsReady()) {
                c->SetFlag(false);
            } else {
                bResult = false;
            }
        }
    }
    snap.Fn00879951();
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a610 score 24
void cUnk00ac3090::Slot20_ac3090()
{
    OutputDebugStringA("");
    Fn0087a466();
    OutputDebugStringA("");
    ::operator delete(this);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a74b score 56
void cUnk00ac3090::Slot15_ac3090(uint32_t nArg)
{
    Lock_ac3090* lock = reinterpret_cast<Lock_ac3090*>(reinterpret_cast<uint8_t*>(this) + 0xe0);
    lock->Enter();
    void* head = mpList_b0;
    ++mnDc;
    Op_ac3090 vec;
    vec.mpHead = 0;
    vec.mnSize = 0;
    mbD3 = true;
    for (ListNode_ac3090* n = static_cast<ListNode_ac3090*>(head)->mpNext; n != head;) {
        void* v = n->mpData;
        vec.PushBackVec(&v);
        n = n->mpNext;
    }
    mbD3 = false;
    lock->Leave();
    // notify every collected client
    Client_ac3090** it = reinterpret_cast<Client_ac3090**>(vec.mpHead);
    Client_ac3090** end = reinterpret_cast<Client_ac3090**>(vec.mnSize);
    for (; it != end; ++it) {
        (*it)->Notify(nArg);
    }
    vec.EraseVec(end, vec.mpHead);
    if (mnDc == 1) {
        reinterpret_cast<Op_ac3090*>(&mpList_b4)->Clear();
    }
    --mnDc;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a812 score 72
void cUnk00ac3090::Slot16_ac3090()
{
    uint32_t nTick = mnC0;
    mnC0 = nTick + 1;
    Slot15_ac3090(nTick);
    Lock_ac3090* lock = reinterpret_cast<Lock_ac3090*>(reinterpret_cast<uint8_t*>(this) + 0xe0);
    lock->Enter();
    ++mnD8;
    if (mnC0 % mnBc == 0) {
        void* head = mpList_a8;
        uint32_t nId = ++mnC4;
        Op_ac3090 vec;
        vec.mpHead = 0;
        vec.mnSize = 0;
        mbD2 = true;
        for (ListNode_ac3090* n = static_cast<ListNode_ac3090*>(head)->mpNext; n != head; n = n->mpNext) {
            void* v = n->mpData;
            vec.PushBackVec(&v);
        }
        mbD2 = false;
        lock->Leave();
        Client_ac3090** it = reinterpret_cast<Client_ac3090**>(vec.mpHead);
        Client_ac3090** end = reinterpret_cast<Client_ac3090**>(vec.mnSize);
        for (; it != end; ++it) {
            (*it)->Notify2(nId);
        }
        vec.EraseVec(end, vec.mpHead);
    } else {
        lock->Leave();
    }
    if (mnD8 == 1) {
        reinterpret_cast<Op_ac3090*>(&mpList_ac)->Clear();
    }
    --mnD8;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087a90e score 139
bool cUnk00ac3090::Slot04_ac3090(void* pClient)
{
    Guard_ac3090 g;
    bool bResult = false;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    if (!mbD0 && !mbD1) {
        Op_ac3090* list = reinterpret_cast<Op_ac3090*>(&mpList_a8);
        void* ref = list->MakeRef(pClient);
        void* it;
        Fn009d07a0(&it, list->mpHead, *static_cast<void**>(list->mpHead), ref);
        if (it != list->mpHead) {
            Fn0087985a(list, it);
        }
        list = reinterpret_cast<Op_ac3090*>(&mpList_b0);
        ref = list->MakeRef(pClient);
        Fn009d07a0(&it, list->mpHead, *static_cast<void**>(list->mpHead), ref);
        if (it != list->mpHead) {
            Fn0087985a(list, it);
        }
        mbD0 = true;
        Op_ac3090* tree = reinterpret_cast<Op_ac3090*>(&mpTree88);
        TreeNode_ac3090* hdr = static_cast<TreeNode_ac3090*>(tree->mpHead);
        TreeNode_ac3090* t = hdr->mpLeft;
        while (t != hdr) {
            if (reinterpret_cast<void*>(t->mnKey) == pClient) {
                break;
            }
            t = static_cast<TreeNode_ac3090*>(Fn0040d4c0(t));
        }
        tree->EraseIter(t);
        mbD0 = false;
        mbD1 = true;
        mbD1 = false;
        bResult = true;
    }
    return bResult;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087ac3c score 69
bool cUnk00ac3090::Slot03_ac3090(void* pClient)
{
    if (!mbD0 && !mbD1 && pClient) {
        Guard_ac3090 g;
        g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
        Client_ac3090* c = static_cast<Client_ac3090*>(pClient);
        int32_t nPriority = c->GetPriority();
        uint32_t nId = c->GetId();
        Op_ac3090* map = reinterpret_cast<Op_ac3090*>(&mpMap94);
        if (!map->Find(&nId)) {
            uint32_t pair[2];
            pair[0] = nPriority;
            pair[1] = 0;
            Op_ac3090* tree = reinterpret_cast<Op_ac3090*>(&mpTree88);
            uint8_t* pos;
            tree->Fn00879e91(&pos, pair);
            reinterpret_cast<Op_ac3090*>(pos + 0x14)->PushBack(pClient);
            uint32_t pair2[2];
            pair2[0] = nId;
            pair2[1] = 0;
            void* res;
            void* node = map->Fn0087a66f(&res, pair2);
            reinterpret_cast<Op_ac3090*>(static_cast<uint8_t*>(node) + 8)->PushBack(pClient);
        }
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00879ace score 78
void cUnk00ac3090::Fn00879ace(void* pOut, bool bForward)
{
    Guard_ac3090 g;
    g.Fn0048c9f0(reinterpret_cast<uint8_t*>(this) + 0xe0);
    mbD0 = true;
    Op_ac3090* out = static_cast<Op_ac3090*>(pOut);
    TreeNode_ac3090* hdr = static_cast<TreeNode_ac3090*>(reinterpret_cast<Op_ac3090*>(&mpTree88)->mpHead);
    if (bForward) {
        TreeNode_ac3090* n = hdr->mpLeft;
        while (n != hdr) {
            void* ref = 0;
            out->AssignRef(&ref);
            static_cast<Op_ac3090*>(static_cast<void*>(static_cast<uint8_t*>(static_cast<void*>(
                static_cast<ListNode_ac3090*>(out->mpHead)->mpNext)) + 8))
                ->PushBack(reinterpret_cast<void*>(static_cast<uint8_t*>(static_cast<void*>(n)) + 0x14));
            n = static_cast<TreeNode_ac3090*>(Fn0040d4c0(n));
        }
    } else {
        TreeNode_ac3090* n = hdr->mpLeft;
        while (n != hdr) {
            n = static_cast<TreeNode_ac3090*>(Fn0040d500(n));
        }
    }
    mbD0 = false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087985a score 18
void OB_STDCALL Fn0087985a(void* pOut, void* pNode)
{
    ListNode_ac3090* node = static_cast<ListNode_ac3090*>(pNode);
    ListNode_ac3090* next = node->mpNext;
    node->mpPrev->mpNext = next;
    next->mpPrev = node->mpPrev;
    reinterpret_cast<Op_ac3090*>(&node->mpData)->Clear();
    Fn0090cf63(node);
    *static_cast<ListNode_ac3090**>(pOut) = next;
}
#endif

// FUNCTION: 0x00879951
void Op_ac3090::Fn00879951()
{
    Clear();
    void* p = mpHead;
    if (p) {
        Fn0090cf63(p);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00879968 score 7
void Op_ac3090::Fn00879968(void* pNode)
{
    TreeNode_ac3090* n = static_cast<TreeNode_ac3090*>(pNode);
    while (n) {
        Fn00879968(n->mpRight);
        TreeNode_ac3090* left = n->mpLeft;
        reinterpret_cast<Op_ac3090*>(reinterpret_cast<uint8_t*>(n) + 0x10)->Clear();
        Fn0090cf63(n);
        n = left;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00879e68 score 7
void Op_ac3090::Fn00879e68()
{
    if (mnSize) {
        TreeNode_ac3090* hdr = static_cast<TreeNode_ac3090*>(mpHead);
        Fn00879968(hdr->mpLeft);
        hdr = static_cast<TreeNode_ac3090*>(mpHead);
        hdr->mpParent = hdr;
        hdr->mpLeft = 0;
        static_cast<TreeNode_ac3090*>(mpHead)->mpRight = static_cast<TreeNode_ac3090*>(mpHead);
        mnSize = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00879e91 score 22
void Op_ac3090::Fn00879e91(void* pOut, void* pKey)
{
    TreeNode_ac3090* hdr = static_cast<TreeNode_ac3090*>(mpHead);
    TreeNode_ac3090* cur = hdr->mpLeft;
    TreeNode_ac3090* parent = hdr;
    int32_t key = *static_cast<int32_t*>(pKey);
    while (cur) {
        parent = cur;
        if (key < cur->mnKey) {
            cur = cur->mpParent;
        } else {
            cur = cur->mpRight;
        }
    }
    Fn00879a46(pOut, 0, parent, pKey, 0);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092bc80 score 13
void Op_ac3090::Fn0092bc80()
{
    uint32_t* p = reinterpret_cast<uint32_t*>(this);
    p[1] = 0;
    p[3] = 0;
    reinterpret_cast<uint8_t*>(this)[8] = 0;
    p[0] = 0xad1938;
    reinterpret_cast<uint8_t*>(this)[0x10] = 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00879a46 score 64
void Op_ac3090::Fn00879a46(void* pOut, uint32_t bLeft, void* pParent, void* pKey, uint32_t bForce)
{
    TreeNode_ac3090* parent = static_cast<TreeNode_ac3090*>(pParent);
    TreeNode_ac3090* hdr = static_cast<TreeNode_ac3090*>(mpHead);
    TreeNode_ac3090* node;
    if (parent == hdr || bLeft || *static_cast<int32_t*>(pKey) < parent->mnKey) {
        node = static_cast<TreeNode_ac3090*>(Fn0099a579(pKey));
        parent->mpParent = node;
        if (parent == static_cast<TreeNode_ac3090*>(mpHead)) {
            hdr->mpLeft = node;
        }
    } else {
        node = static_cast<TreeNode_ac3090*>(Fn0099a579(pKey));
        parent->mpLeft = node;
        if (parent == hdr->mpParent) {
            hdr->mpParent = node;
        }
    }
    node->mpParent = 0;
    node->mpLeft = 0;
    node->mpRight = parent;
    ++mnSize;
    *static_cast<TreeNode_ac3090**>(pOut) = node;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087999f score 45
void Op_ac3090::Fn0087999f(void* pOut, void* pPair)
{
    ListNode_ac3090** buckets = *reinterpret_cast<ListNode_ac3090***>(reinterpret_cast<uint8_t*>(this) + 4);
    ListNode_ac3090** end = *reinterpret_cast<ListNode_ac3090***>(reinterpret_cast<uint8_t*>(this) + 8);
    uint32_t key = *static_cast<uint32_t*>(pPair);
    uint32_t idx = key % static_cast<uint32_t>(end - buckets);
    ListNode_ac3090* first = buckets[idx];
    ListNode_ac3090* c = first;
    while (c) {
        if (reinterpret_cast<uint32_t*>(c)[1] == key) {
            *static_cast<ListNode_ac3090**>(pOut) = c;
            reinterpret_cast<void**>(pOut)[1] = this;
            reinterpret_cast<uint8_t*>(pOut)[8] = 0;
            return;
        }
        c = c->mpNext;
    }
    ListNode_ac3090* node = static_cast<ListNode_ac3090*>(Fn00879886(pPair));
    node->mpNext = first;
    (*reinterpret_cast<ListNode_ac3090***>(reinterpret_cast<uint8_t*>(this) + 4))[idx] = node;
    ++*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) + 0x10);
    *static_cast<ListNode_ac3090**>(pOut) = node;
    reinterpret_cast<void**>(pOut)[1] = this;
    reinterpret_cast<uint8_t*>(pOut)[8] = 1;
}
#endif

// FUNCTION: 0x0087a66f
void* Op_ac3090::Fn0087a66f(void* pOut, void* pPair)
{
    Fn009978af(*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) + 0x10) + 1);
    Fn0087999f(pOut, pPair);
    return pOut;
}
