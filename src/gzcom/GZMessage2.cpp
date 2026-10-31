#include <stddef.h>
#include "classes/cGZMessageQueue2.h"
#include "classes/cUnk00ad1bf4.h"

// The message queue's own lock (at this+8); only the slots used here are named.
struct Lock_ad1ad0 {
    virtual void Pad0_ad1ad0();
    virtual void Enter_ad1ad0();
    virtual void Leave_ad1ad0();
};

// The signal object at this+0x10: slot 1 wakes the waiters, slot 3 waits that many microseconds.
struct Signal_ad1ad0 {
    virtual void Pad0_ad1ad0();
    virtual void Notify_ad1ad0();
    virtual void Pad2_ad1ad0();
    virtual void Wait_ad1ad0(uint32_t usec);
};

// A scope guard over the lock: the constructor takes it, the destructor lets it go.
struct Guard_ad1ad0 {
    uint32_t mPad;
    Lock_ad1ad0* mpLock;

    // STUB: 0x0048c9f0
    Guard_ad1ad0(Lock_ad1ad0* lock);
    ~Guard_ad1ad0() { mpLock->Leave_ad1ad0(); }
};

struct Msg_ad1ad0;

// A counted reference to a message (one word): built in place, it takes a count and gives it back when it goes.
struct Ref_ad1ad0 {
    Msg_ad1ad0* mp;

    // STUB: 0x004f20c0
    Ref_ad1ad0* Construct(Msg_ad1ad0* p);
    ~Ref_ad1ad0();
    // STUB: 0x009491ff
    void Assign(Msg_ad1ad0* p);
};

// A queued message (a reference-counted component).
struct Msg_ad1ad0 {
    virtual bool QueryInterface(uint32_t iid, uint32_t out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad3_ad1ad0();
    virtual uint32_t GetType();
    virtual void Pad5_ad1ad0();
    virtual bool IsEqual(uint32_t other);
};

inline Ref_ad1ad0::~Ref_ad1ad0()
{
    if (mp) {
        mp->Release();
    }
}

// One link of the circular list: next, previous, the message.
struct Node_ad1ad0 {
    Node_ad1ad0* mpNext;
    Node_ad1ad0* mpPrev;
    Msg_ad1ad0* mpMsg;
};

// An iterator is a class passed by value.
struct Iter_ad1ad0 {
    Node_ad1ad0* mpNode;
    Iter_ad1ad0(Node_ad1ad0* node) : mpNode(node) {}
    Iter_ad1ad0(const Iter_ad1ad0& other) : mpNode(other.mpNode) {}
};

// The list object at this+4: one word, the sentinel node.
struct List_ad1ad0 {
    Node_ad1ad0* mpHead;

    // STUB: 0x007e9330
    Iter_ad1ad0 Erase(Iter_ad1ad0 pos);
    // STUB: 0x007e9850
    void PopFront7e9850();
    // STUB: 0x007e98c0
    void PushBack(const Ref_ad1ad0& ref);
    // STUB: 0x007e9880
    Iter_ad1ad0 Insert7e9880(Iter_ad1ad0 pos, const Ref_ad1ad0& ref);
    // STUB: 0x0092dc08
    void PushFront(const Ref_ad1ad0& ref);
    // STUB: 0x00473ec0
    void Clear();
    // STUB: 0x0092dc24
    void PopFrontDc24();
    // STUB: 0x0092da64
    void ClearDa64();
    // STUB: 0x0092dca6
    void DestroyDca6();
    // STUB: 0x0092d4d0
    void PopFront();
    // STUB: 0x0092d4b9
    void PopBack();
};

// FUNCTION: 0x0092dc08
void List_ad1ad0::PushFront(const Ref_ad1ad0& ref)
{
    Insert7e9880(Iter_ad1ad0(mpHead->mpNext), ref);
}

// FUNCTION: 0x0092d4d0
void List_ad1ad0::PopFront()
{
    Erase(Iter_ad1ad0(mpHead->mpNext));
}

// FUNCTION: 0x0092d4b9
void List_ad1ad0::PopBack()
{
    Erase(Iter_ad1ad0(mpHead->mpPrev));
}

// The notification table object (at +0x38 of the server): slot 3 / 4 add or remove, slot 22 reports a count.
struct Table_ad1ad0 {
    virtual void Pad0_ad1ad0();
    virtual void Pad1_ad1ad0();
    virtual void Pad2_ad1ad0();
    virtual void Add_ad1ad0(uint32_t id);
    virtual void Remove_ad1ad0(uint32_t id);
    virtual void Pad5_ad1ad0();
    virtual void Pad6_ad1ad0();
    virtual void Pad7_ad1ad0();
    virtual void Pad8_ad1ad0();
    virtual void Pad9_ad1ad0();
    virtual void Pad10_ad1ad0();
    virtual void Pad11_ad1ad0();
    virtual void Pad12_ad1ad0();
    virtual void Pad13_ad1ad0();
    virtual void Pad14_ad1ad0();
    virtual void Pad15_ad1ad0();
    virtual void Pad16_ad1ad0();
    virtual void Pad17_ad1ad0();
    virtual void Pad18_ad1ad0();
    virtual void Pad19_ad1ad0();
    virtual void Pad20_ad1ad0();
    virtual void Pad21_ad1ad0();
    virtual uint32_t Count_ad1ad0();
};

// The framework, as far as slots 9 and 10 go.
struct Fw_ad1ad0 {
    virtual void Pad0_ad1ad0();
    virtual void Pad1_ad1ad0();
    virtual void Pad2_ad1ad0();
    virtual void Pad3_ad1ad0();
    virtual void Pad4_ad1ad0();
    virtual void Pad5_ad1ad0();
    virtual void Pad6_ad1ad0();
    virtual void Pad7_ad1ad0();
    virtual void Pad8_ad1ad0();
    virtual bool Fn9_ad1ad0(cRZSystemService* service);
    virtual bool Fn10_ad1ad0(cRZSystemService* service);
};

// STUB: 0x008793ec
Fw_ad1ad0* Fn008793ec();

// STUB: 0x009133da
void* Fn009133da(uint32_t size);

// The object d1fe makes (0x2c bytes), built by its constructor.
struct Made_ad1ad0 {
    // STUB: 0x009134d6
    Made_ad1ad0* Construct();
};

// FUNCTION: 0x0092cf85
bool cGZMessageQueue2::QueryInterface(uint32_t iid, uint32_t out)
{
    if (iid == 1 || iid == 0xa52294cd) {
        *OB_PTR(cGZMessageQueue2*, out) = this;
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x0092cfaa
uint32_t cGZMessageQueue2::Release()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x0092cfc1
bool cGZMessageQueue2::GetFrontMessageBlock(uint32_t out)
{
    if (!GetFrontMessage(out)) {
        Signal_ad1ad0* signal = reinterpret_cast<Signal_ad1ad0*>(mSignal);
        do {
            signal->Wait_ad1ad0(1000000);
        } while (!GetFrontMessage(out));
    }
    return true;
}

// FUNCTION: 0x0092cff7
bool cGZMessageQueue2::GetBackMessageBlock(uint32_t out)
{
    if (!GetBackMessage(out)) {
        Signal_ad1ad0* signal = reinterpret_cast<Signal_ad1ad0*>(mSignal);
        do {
            signal->Wait_ad1ad0(1000000);
        } while (!GetBackMessage(out));
    }
    return true;
}

// FUNCTION: 0x0092d313
uint32_t cGZMessageQueue2::PeekFrontType()
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    uint32_t type;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    if (list->mpHead->mpNext != list->mpHead) {
        type = list->mpHead->mpNext->mpMsg->GetType();
    } else {
        type = 0;
    }
    return type;
}

// FUNCTION: 0x0092d34b
uint32_t cGZMessageQueue2::PeekBackType()
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    uint32_t type;
    Node_ad1ad0* head = reinterpret_cast<List_ad1ad0*>(mList)->mpHead;
    if (head->mpNext != head) {
        type = head->mpPrev->mpMsg->GetType();
    } else {
        type = 0;
    }
    return type;
}

// FUNCTION: 0x0092d384
bool cGZMessageQueue2::PeekAnywhereType(uint32_t type)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found = true;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    Node_ad1ad0* node = list->mpHead->mpNext;
    if (node != list->mpHead) {
        do {
            if (node->mpMsg->GetType() == type) {
                return found;
            }
            node = node->mpNext;
        } while (node != list->mpHead);
    }
    found = false;
    return found;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092d3ce score 6
bool cGZMessageQueue2::PeekFrontMessage(uint32_t out)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    if (list->mpHead->mpNext != list->mpHead) {
        Msg_ad1ad0* msg = list->mpHead->mpNext->mpMsg;
        *OB_PTR(Msg_ad1ad0*, out) = msg;
        msg->AddRef();
        found = true;
    } else {
        found = false;
        *OB_PTR(Msg_ad1ad0*, out) = 0;
    }
    return found;
}
#endif

// FUNCTION: 0x0092d414
bool cGZMessageQueue2::PeekBackMessage(uint32_t out)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found;
    Node_ad1ad0* head = reinterpret_cast<List_ad1ad0*>(mList)->mpHead;
    if (head->mpNext != head) {
        Msg_ad1ad0* msg = head->mpPrev->mpMsg;
        *OB_PTR(Msg_ad1ad0*, out) = msg;
        msg->AddRef();
        found = true;
    } else {
        found = false;
        *OB_PTR(Msg_ad1ad0*, out) = 0;
    }
    return found;
}

// FUNCTION: 0x0092d45b
bool cGZMessageQueue2::PeekAnywhereMessage(uint32_t match, uint32_t out)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    Node_ad1ad0* node = list->mpHead->mpNext;
    if (node != list->mpHead) {
        do {
            if (node->mpMsg->IsEqual(match)) {
                Msg_ad1ad0* msg = node->mpMsg;
                *OB_PTR(Msg_ad1ad0*, out) = msg;
                msg->AddRef();
                found = true;
                return found;
            }
            node = node->mpNext;
        } while (node != list->mpHead);
    }
    *OB_PTR(Msg_ad1ad0*, out) = 0;
    found = false;
    return found;
}

// FUNCTION: 0x0092d66f
bool cGZMessageQueue2::RemoveLastFound(uint32_t match)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found = true;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    Node_ad1ad0* node = list->mpHead->mpNext;
    if (node != list->mpHead) {
        do {
            if (node->mpMsg->IsEqual(match)) {
                list->Erase(Iter_ad1ad0(node));
                return found;
            }
            node = node->mpNext;
        } while (node != list->mpHead);
    }
    found = false;
    return found;
}

// FUNCTION: 0x0092d78b
bool cGZMessageQueue2::RemoveFirstFound(uint32_t match)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found = true;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    Node_ad1ad0* node = list->mpHead->mpNext;
    if (node != list->mpHead) {
        do {
            if (node->mpMsg->GetType() == match) {
                list->Erase(Iter_ad1ad0(node));
                return found;
            }
            node = node->mpNext;
        } while (node != list->mpHead);
    }
    found = false;
    return found;
}

// FUNCTION: 0x0092d6cc
bool cGZMessageQueue2::RemoveFirstFound_2(uint32_t match)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found = true;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    Node_ad1ad0* node = list->mpHead;
    if (node != node->mpNext) {
        do {
            node = node->mpPrev;
            if (node->mpMsg->IsEqual(match)) {
                list->Erase(Iter_ad1ad0(node));
                return found;
            }
        } while (node != list->mpHead->mpNext);
    }
    found = false;
    return found;
}

// FUNCTION: 0x0092d7e6
bool cGZMessageQueue2::RemoveAllFound(uint32_t type)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found = true;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    Node_ad1ad0* node = list->mpHead;
    if (node != node->mpNext) {
        do {
            node = node->mpPrev;
            if (node->mpMsg->GetType() == type) {
                list->Erase(Iter_ad1ad0(node));
                return found;
            }
        } while (node != list->mpHead->mpNext);
    }
    found = false;
    return found;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092d72a score 6
uint32_t cGZMessageQueue2::RemoveAllFound_2(uint32_t match)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    Node_ad1ad0* node = list->mpHead->mpNext;
    uint32_t count = 0;
    if (node != list->mpHead) {
        do {
            if (node->mpMsg->IsEqual(match)) {
                Node_ad1ad0* cur = node;
                node = node->mpNext;
                ++count;
                list->Erase(Iter_ad1ad0(cur));
            } else {
                node = node->mpNext;
            }
        } while (node != list->mpHead);
    }
    return count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092d842 score 6
uint32_t cGZMessageQueue2::RemoveLastFound_2(uint32_t type)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    Node_ad1ad0* node = list->mpHead->mpNext;
    uint32_t count = 0;
    if (node != list->mpHead) {
        do {
            if (node->mpMsg->GetType() == type) {
                Node_ad1ad0* cur = node;
                node = node->mpNext;
                ++count;
                list->Erase(Iter_ad1ad0(cur));
            } else {
                node = node->mpNext;
            }
        } while (node != list->mpHead);
    }
    return count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092d8a1 score 11
bool cGZMessageQueue2::GetFrontMessage(uint32_t out)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    if (list->mpHead->mpNext != list->mpHead) {
        Msg_ad1ad0* msg = list->mpHead->mpNext->mpMsg;
        *OB_PTR(Msg_ad1ad0*, out) = msg;
        msg->AddRef();
        list->PopFront7e9850();
        found = true;
    } else {
        found = false;
        *OB_PTR(Msg_ad1ad0*, out) = 0;
    }
    return found;
}
#endif

// FUNCTION: 0x0092d8f0
bool cGZMessageQueue2::GetBackMessage(uint32_t out)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    if (list->mpHead->mpNext != list->mpHead) {
        Msg_ad1ad0* msg = list->mpHead->mpPrev->mpMsg;
        *OB_PTR(Msg_ad1ad0*, out) = msg;
        msg->AddRef();
        list->PopBack();
        found = true;
    } else {
        found = false;
        *OB_PTR(Msg_ad1ad0*, out) = 0;
    }
    return found;
}

// FUNCTION: 0x0092d940
bool cGZMessageQueue2::GetAnywhereMessage(uint32_t match, uint32_t out)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool found;
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    Node_ad1ad0* node = list->mpHead->mpNext;
    if (node != list->mpHead) {
        do {
            if (node->mpMsg->IsEqual(match)) {
                Msg_ad1ad0* msg = node->mpMsg;
                *OB_PTR(Msg_ad1ad0*, out) = msg;
                msg->AddRef();
                list->Erase(Iter_ad1ad0(node));
                found = true;
                return found;
            }
            node = node->mpNext;
        } while (node != list->mpHead);
    }
    *OB_PTR(Msg_ad1ad0*, out) = 0;
    found = false;
    return found;
}

// FUNCTION: 0x0092db79
uint32_t cGZMessageQueue2::RemoveAll()
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    Node_ad1ad0* head = list->mpHead;
    Node_ad1ad0* node = head->mpNext;
    uint32_t count = 0;
    while (node != head) {
        node = node->mpNext;
        ++count;
    }
    list->Clear();
    return count;
}

// FUNCTION: 0x0092ddd2
void cGZMessageQueue2::PushBack(uint32_t msg)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    bool wasEmpty = list->mpHead->mpNext == list->mpHead;
    {
        Ref_ad1ad0 ref;
        list->PushBack(*ref.Construct(OB_PTR(Msg_ad1ad0, msg)));
    }
    if (wasEmpty) {
        reinterpret_cast<Signal_ad1ad0*>(mSignal)->Notify_ad1ad0();
    }
}

// FUNCTION: 0x0092de2c
void cGZMessageQueue2::PushFront(uint32_t msg)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    List_ad1ad0* list = reinterpret_cast<List_ad1ad0*>(mList);
    bool wasEmpty = list->mpHead->mpNext == list->mpHead;
    {
        Ref_ad1ad0 ref;
        list->PushFront(*ref.Construct(OB_PTR(Msg_ad1ad0, msg)));
    }
    if (wasEmpty) {
        reinterpret_cast<Signal_ad1ad0*>(mSignal)->Notify_ad1ad0();
    }
}

// FUNCTION: 0x0092d05b
bool cUnk00ad1bf4::Slot03_ae1d24()
{
    return Fn008793ec()->Fn9_ad1ad0(static_cast<cRZSystemService*>(this));
}

// FUNCTION: 0x0092d076
bool cUnk00ad1bf4::Slot04_ae1d24()
{
    return Fn008793ec()->Fn10_ad1ad0(static_cast<cRZSystemService*>(this));
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092d0bb score 8
bool cUnk00ad1bf4::Slot04_ad1a98(uint32_t id, uint32_t flag)
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(reinterpret_cast<uint8_t*>(this) + 0x28));
    Table_ad1ad0* table = reinterpret_cast<Table_ad1ad0*>(reinterpret_cast<uint8_t*>(this) + 0x38);
    if (static_cast<uint8_t>(flag) != 0) {
        table->Remove_ad1ad0(id);
    } else {
        table->Add_ad1ad0(id);
    }
    return true;
}
#endif

// FUNCTION: 0x0092d0f4
uint32_t cUnk00ad1bf4::Slot10_ad1a98()
{
    Guard_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(reinterpret_cast<uint8_t*>(this) + 0x28));
    uint32_t count = reinterpret_cast<Table_ad1ad0*>(reinterpret_cast<uint8_t*>(this) + 0x38)->Count_ad1ad0();
    return count;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092d1fe score 19
bool cUnk00ad1bf4::Slot13_ad1a98(uint32_t clsid, uint32_t iid, uint32_t out)
{
    if (clsid != 0x46df45e7) {
        return false;
    }
    void* mem = Fn009133da(0x2c);
    Made_ad1ad0* made = reinterpret_cast<Made_ad1ad0*>(mem);
    if (made) {
        made = made->Construct();
    }
    Ref_ad1ad0 ref;
    ref.Construct(reinterpret_cast<Msg_ad1ad0*>(made));
    bool ok = ref.mp->QueryInterface(iid, out);
    return ok;
}
#endif

// The object at +8, as far as slot 5 goes.
struct Obj8_ad1ad0 {
    virtual void Pad0_ad1ad0();
    virtual void Pad1_ad1ad0();
    virtual void Pad2_ad1ad0();
    virtual void Pad3_ad1ad0();
    virtual void Pad4_ad1ad0();
    virtual void Fn5_ad1ad0();
};

// FUNCTION: 0x0092d0b3
void cUnk00ad1bf4::Slot12_ad1a98()
{
    reinterpret_cast<Obj8_ad1ad0*>(reinterpret_cast<uint8_t*>(this) + 8)->Fn5_ad1ad0();
}

// An element copied through its own copy constructor (0x004e4bb0).
struct Elem_ad1ad0 {
    uint32_t mV;
    // STUB: 0x004e4bb0
    Elem_ad1ad0(const Elem_ad1ad0& other);
};

// A reference built in place from a raw pointer (0x004f20c0), no destructor here.
struct RefC_ad1ad0 {
    Msg_ad1ad0* mp;
    // STUB: 0x004f20c0
    RefC_ad1ad0(Msg_ad1ad0* p);
};

// A reference copied from another (0x00966956).
struct RefK_ad1ad0 {
    uint32_t mV;
    // STUB: 0x00966956
    RefK_ad1ad0(const RefK_ad1ad0& other);
};

struct PairR_ad1ad0 {
    RefC_ad1ad0 mA;
    RefC_ad1ad0 mB;
    PairR_ad1ad0(Msg_ad1ad0* a, Msg_ad1ad0* b);
};

struct PairE_ad1ad0 {
    Elem_ad1ad0 mA;
    uint32_t mB;
    PairE_ad1ad0(const PairE_ad1ad0& other);
};

struct PairC_ad1ad0 {
    Elem_ad1ad0 mA;
    Elem_ad1ad0 mB;
    PairC_ad1ad0(const PairC_ad1ad0& other);
};

struct PairK_ad1ad0 {
    int32_t mKey;
    RefK_ad1ad0 mRef;
    PairK_ad1ad0(const PairK_ad1ad0& other);
    PairK_ad1ad0(const int32_t* key, const RefK_ad1ad0& ref);
};

// FUNCTION: 0x0092d185
PairK_ad1ad0::PairK_ad1ad0(const PairK_ad1ad0& other) : mKey(other.mKey), mRef(other.mRef)
{
}

// FUNCTION: 0x0092d250
PairK_ad1ad0::PairK_ad1ad0(const int32_t* key, const RefK_ad1ad0& ref) : mKey(*key), mRef(ref)
{
}

// FUNCTION: 0x0092d1c5
PairR_ad1ad0::PairR_ad1ad0(Msg_ad1ad0* a, Msg_ad1ad0* b) : mA(a), mB(b)
{
}

// FUNCTION: 0x0092d1e3
PairE_ad1ad0::PairE_ad1ad0(const PairE_ad1ad0& other) : mA(other.mA)
{
    mB = other.mB;
}

// FUNCTION: 0x0092d293
PairC_ad1ad0::PairC_ad1ad0(const PairC_ad1ad0& other) : mA(other.mA), mB(other.mB)
{
}

// STUB: 0x0090cf54
void* StlNew_ad1ad0(uint32_t size);
// STUB: 0x0090cf63
void StlDelete_ad1ad0(void* p);

struct ListH_ad1ad0 {
    Node_ad1ad0* mpHead;
    ListH_ad1ad0(const void* alloc);
};

// FUNCTION: 0x0092d514
ListH_ad1ad0::ListH_ad1ad0(const void* /*alloc*/) : mpHead(0)
{
    mpHead = static_cast<Node_ad1ad0*>(StlNew_ad1ad0(0x18));
}

// FUNCTION: 0x0092d9af
Iter_ad1ad0* OB_STDCALL Fn0092d9af(Iter_ad1ad0* out, Iter_ad1ad0 pos)
{
    Node_ad1ad0* node = pos.mpNode;
    Node_ad1ad0* next = node->mpNext;
    Node_ad1ad0* prev = node->mpPrev;
    prev->mpNext = next;
    next->mpPrev = prev;
    reinterpret_cast<Ref_ad1ad0*>(&node->mpMsg)->Assign(0);
    StlDelete_ad1ad0(node);
    out->mpNode = next;
    return out;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092dc24 score 6
void List_ad1ad0::PopFrontDc24()
{
    Iter_ad1ad0 result(0);
    Fn0092d9af(&result, Iter_ad1ad0(mpHead->mpNext));
}
#endif

// FUNCTION: 0x0092da64
void List_ad1ad0::ClearDa64()
{
    Node_ad1ad0* node = mpHead->mpNext;
    while (node != mpHead) {
        Node_ad1ad0* cur = node;
        node = node->mpNext;
        reinterpret_cast<Ref_ad1ad0*>(&cur->mpMsg)->Assign(0);
        StlDelete_ad1ad0(cur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

// FUNCTION: 0x0092dca6
void List_ad1ad0::DestroyDca6()
{
    ClearDa64();
    if (mpHead) {
        StlDelete_ad1ad0(mpHead);
    }
}

// A tree node of the second container: four link words, then a counted reference at +0x10.
struct TNode_ad1ad0 {
    uint32_t mColor;
    TNode_ad1ad0* mpParent;
    TNode_ad1ad0* mpLeft;
    TNode_ad1ad0* mpRight;
    Msg_ad1ad0* mpMsg;
};

struct Tree_ad1ad0 {
    TNode_ad1ad0* mpHeader;
    uint32_t mnSize;

    // STUB: 0x0092da2d
    void EraseSubtree(TNode_ad1ad0* node);
    // STUB: 0x0092dc58
    void Clear();
    // STUB: 0x0092e103
    void Destroy();
};

// FUNCTION: 0x0092da2d
void Tree_ad1ad0::EraseSubtree(TNode_ad1ad0* node)
{
    while (node) {
        EraseSubtree(node->mpRight);
        TNode_ad1ad0* left = node->mpLeft;
        reinterpret_cast<Ref_ad1ad0*>(&node->mpMsg)->Assign(0);
        StlDelete_ad1ad0(node);
        node = left;
    }
}

// FUNCTION: 0x0092dc58
void Tree_ad1ad0::Clear()
{
    if (mnSize) {
        EraseSubtree(mpHeader->mpParent);
        mpHeader->mpLeft = mpHeader;
        mpHeader->mpParent = 0;
        mpHeader->mpRight = mpHeader;
        mnSize = 0;
    }
}

// FUNCTION: 0x0092e103
void Tree_ad1ad0::Destroy()
{
    Clear();
    if (mpHeader) {
        StlDelete_ad1ad0(mpHeader);
    }
}

// The three sub-objects of the queue, each built (or taken apart) by its own function.
struct ListBase_ad1ad0 {
    // STUB: 0x004f5a00
    void Construct(char* alloc);
    // STUB: 0x00427670
    void Destruct();
};

struct LockObj_ad1ad0 {
    // STUB: 0x00930b91
    void Construct();
    // STUB: 0x00930b02
    void Destruct();
};

struct SignalObj_ad1ad0 {
    // STUB: 0x00932e65
    void Construct(uint32_t manual);
    // STUB: 0x00932ec8
    void Destruct();
};

// FUNCTION: 0x0092dd7e
cGZMessageQueue2::cGZMessageQueue2()
{
    char alloc;
    reinterpret_cast<ListBase_ad1ad0*>(mList)->Construct(&alloc);
    reinterpret_cast<LockObj_ad1ad0*>(mLock)->Construct();
    reinterpret_cast<SignalObj_ad1ad0*>(mSignal)->Construct(0);
    mnRefs = 0;
}

// FUNCTION: 0x0092ddb0
cGZMessageQueue2::~cGZMessageQueue2()
{
    reinterpret_cast<SignalObj_ad1ad0*>(mSignal)->Destruct();
    reinterpret_cast<LockObj_ad1ad0*>(mLock)->Destruct();
    reinterpret_cast<ListBase_ad1ad0*>(mList)->Destruct();
}

// ---- the queue manager (no class header declares it yet): plain struct drafts over its layout ----

// The manager's scope guard over its lock at +0x20 (null-checked conversion of this).
struct GuardM_ad1ad0 {
    uint32_t mPad;
    Lock_ad1ad0* mpLock;

    // STUB: 0x0092cf67
    GuardM_ad1ad0(Lock_ad1ad0* lock);
    ~GuardM_ad1ad0() { mpLock->Leave_ad1ad0(); }
};

// A node of the id-to-queue tree: four link words, the id, the queue.
struct QNode_ad1ad0 {
    uint32_t mColor;
    QNode_ad1ad0* mpParent;
    QNode_ad1ad0* mpLeft;
    QNode_ad1ad0* mpRight;
    uint32_t mnId;
    Msg_ad1ad0* mpQueue;
};

struct QIter_ad1ad0 {
    QNode_ad1ad0* mpNode;
    QIter_ad1ad0(QNode_ad1ad0* node) : mpNode(node) {}
    QIter_ad1ad0(const QIter_ad1ad0& other) : mpNode(other.mpNode) {}
};

struct QTree_ad1ad0 {
    QNode_ad1ad0* mpHeader;
    uint32_t mnSize;

    // STUB: 0x0098129c
    QNode_ad1ad0* Find(const uint32_t* id);
    // STUB: 0x00968d88
    void Erase(QIter_ad1ad0 pos);
    // STUB: 0x0096a233
    void Insert(void* out, const PairK_ad1ad0& entry);
    // STUB: 0x0092dc58
    void Clear();
    // STUB: 0x0040d4c0
    QNode_ad1ad0* Next(QNode_ad1ad0* node);
};

struct Mgr_ad1ad0 {
    uint8_t mPad[0x20];
    uint8_t mLock[0xc];
    QTree_ad1ad0 mTree;

    bool GetQueue(uint32_t id, Msg_ad1ad0** out);
    bool RemoveQueue(uint32_t id);
    bool RemoveAllQueues();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0092dbb1 score 10
bool Mgr_ad1ad0::GetQueue(uint32_t id, Msg_ad1ad0** out)
{
    GuardM_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    QNode_ad1ad0* node = mTree.Find(&id);
    if (node != mTree.mpHeader) {
        *out = node->mpQueue;
        (*out)->AddRef();
    } else {
        *out = 0;
    }
    return *out != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092de86 score 10
bool Mgr_ad1ad0::RemoveQueue(uint32_t id)
{
    GuardM_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    bool removed;
    QNode_ad1ad0* node = mTree.Find(&id);
    if (node != mTree.mpHeader) {
        mTree.Erase(QIter_ad1ad0(node));
        removed = true;
    } else {
        removed = false;
    }
    return removed;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092e3fc score 6
bool Mgr_ad1ad0::RemoveAllQueues()
{
    GuardM_ad1ad0 guard(reinterpret_cast<Lock_ad1ad0*>(mLock));
    mTree.Clear();
    return true;
}
#endif
