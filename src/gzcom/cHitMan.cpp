#include <stddef.h>
#include <new>
#include <string.h>
#include "gzcom/cRZString.h"
#include "classes/cHitMan.h"

// The system service pointer to the hit manager interface (ids 0x1b2ce671 / 0xbb1bd9a8).
struct cSysServPtrHit_ad2a40 {
    cUnk00ad2540* mp;
    // STUB: 0x004ed100
    cSysServPtrHit_ad2a40();
    // STUB: 0x004ed130
    ~cSysServPtrHit_ad2a40();
};

// A reference-counting pointer holder (assignment at 0x0094909a).
struct cAutoRef_ad2a40 {
    void* mp;
    // STUB: 0x0094909a
    cAutoRef_ad2a40& Assign(void* p);
};

// The object behind the register map (this+0x48), seen through the slots used.
struct cRegMap_ad2a40 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Fn3(void* key, void* receiver);
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Fn8(void* key, void* receiver);
};

// A receiver object handed to the register map: a vtable and one value.
struct cRegValue_ad2a40 {
    virtual void Fn0();
    int32_t mnValue;
};

// A control group (the object ControlGroup hands out), seen through slot 3.
struct cCtlGroup_ad2a40 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Fn3(uint32_t id);
};

// The data block (slot 3 gives its base address).
struct cDataBlock_ad2a40 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual uint32_t Fn3();
};

// The view object (this+0x2c); slot 32 takes a callback.
struct cView_ad2a40 {
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
    virtual void Fn32(void* callback, uint32_t a, uint32_t b);
};

// The object a newly built track player is driven through (slot 0).
struct cNewTrackPlayer_ad2a40 {
    virtual void Fn0();
    // STUB: 0x0093e8f4
    cNewTrackPlayer_ad2a40* Construct();
};

// STUB: 0x0093790b
bool Fn0093790b(void* p);

// The sink the hit manager reports track errors to is a plain function pointer (this+0xa8).
typedef void(__cdecl* ErrorFn_ad2a40)(uint32_t, uint32_t);

// The other service pointer (ids 0xfbc9cd04 / 0x7bba0cbd).
struct cSysServPtrB_ad2a40 {
    void* mp;
    cSysServPtrB_ad2a40();
    ~cSysServPtrB_ad2a40();
};

// STUB: 0x008793ec
struct cServices_ad2a40 {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual bool Query(uint32_t id1, uint32_t id2, void* out);
};
// STUB: 0x008793ec
cServices_ad2a40* Fn008793ec();

// FUNCTION: 0x00936176
cSysServPtrB_ad2a40::cSysServPtrB_ad2a40()
{
    mp = 0;
    cServices_ad2a40* services = Fn008793ec();
    if (services) {
        services->Query(0xfbc9cd04, 0x7bba0cbd, this);
    }
}

struct cRef_ad2a40 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Release();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0093619b score 21
cSysServPtrB_ad2a40::~cSysServPtrB_ad2a40()
{
    if (mp) {
        static_cast<cRef_ad2a40*>(mp)->Release();
    }
}
#endif

// FUNCTION: 0x00937805
void cHitMan::Slot29_ad2540(uint32_t a, uint32_t b)
{
    reinterpret_cast<ErrorFn_ad2a40>(mpErrorFn)(a, b);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00937818 score 8
bool cHitMan::QueryInterface(uint32_t id, void** out)
{
    if (id == 1 || id == 0xbb1bd9a8) {
        *out = static_cast<cUnk00ad2540*>(this);
        AddRef();
        return true;
    }
    return cRZSystemService::QueryInterface(id, out);
}
#endif

// FUNCTION: 0x00937855
void cHitMan::Slot15_ad2540()
{
    cNewTrackPlayer_ad2a40* p = static_cast<cNewTrackPlayer_ad2a40*>(operator new(0x104));
    if (p) {
        p = p->Construct();
    } else {
        p = 0;
    }
    p->Fn0();
}

// FUNCTION: 0x00937875
bool cHitMan::Slot06_ad2540()
{
    Slot42_ad2540();
    return true;
}

// FUNCTION: 0x0093793f
void cHitMan::Slot05_ad2540()
{
    if (mpView != 0) {
        static_cast<cView_ad2a40*>(mpView)->Fn32(reinterpret_cast<void*>(&Fn0093790b), 0, 0);
    }
}

// FUNCTION: 0x00937959
void cHitMan::Slot32_ad2540()
{
    static_cast<cDataBlock_ad2a40*>(mpDataHandler)->Fn3();
}

// FUNCTION: 0x00937961
bool cHitMan::Slot33_ad2540(uint32_t a)
{
    reinterpret_cast<cAutoRef_ad2a40*>(&mpDataHandler)->Assign(OB_PTR(void, a));
    return true;
}

// FUNCTION: 0x00937972
bool cHitMan::Slot36_ad2540(uint32_t a, uint32_t b)
{
    cSysServPtrHit_ad2a40 service;
    OB_PTR(cCtlGroup_ad2a40, service.mp->Slot35_ad2540(a))->Fn3(b);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009379a4 score 4
uint32_t cHitMan::Slot14_ad2540(uint32_t id)
{
    uint32_t result = 0;
    uint32_t offset = 0;
    cDataBlock_ad2a40* block = 0;
    cSysServPtrHit_ad2a40 service;
    if (service.mp->Slot13_ad2540(id, OB_ADDR(&block), OB_ADDR(&offset))) {
        result = block->Fn3() + offset;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00937ba5 score 2
uint32_t cHitMan::Slot31_ad2540(uint32_t reg)
{
    cRegValue_ad2a40 receiver;
    receiver.mnValue = 0;
    static_cast<cRegMap_ad2a40*>(mpRegisters)->Fn8(&reg, &receiver);
    return receiver.mnValue;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00937bd2 score 4
bool cHitMan::Slot30_ad2540(uint32_t reg, uint32_t value)
{
    cRegValue_ad2a40 receiver;
    receiver.mnValue = value;
    static_cast<cRegMap_ad2a40*>(mpRegisters)->Fn3(&reg, &receiver);
    return true;
}
#endif

// ---- containers as the original lays them out (stlport 4.6 instantiations; their out-of-line code is the original's)

// An iterator handed by value (it has a copy constructor, so the compiler builds it in place).
struct TreeNode_ad2a40;
struct Iter_ad2a40 {
    void* mpNode;
    Iter_ad2a40(void* node)
        : mpNode(node)
    {
    }
    Iter_ad2a40(const Iter_ad2a40& other)
        : mpNode(other.mpNode)
    {
    }
};

// A std::list node: links, then the value.
struct ListNode_ad2a40 {
    ListNode_ad2a40* mpNext;
    ListNode_ad2a40* mpPrev;
    uint32_t mnValue;
};

// A std::list<T*>: one pointer to the sentinel node.
struct cList_ad2a40 {
    ListNode_ad2a40* mpHead;
    // STUB: 0x0050a2a0
    void Clear();
    // STUB: 0x005650a0
    void Destroy();
    // STUB: 0x0049eaa0
    void Erase(Iter_ad2a40 pos, Iter_ad2a40* result);
    // STUB: 0x00427640
    void PushBack(const uint32_t* value);
};

// The list of track data blocks (another instantiation).
struct cBlockList_ad2a40 {
    ListNode_ad2a40* mpHead;
    // STUB: 0x009677e6
    void Clear();
    // STUB: 0x00968c53
    void Erase(Iter_ad2a40 pos, Iter_ad2a40* result);
    void Remove(const uint32_t* value);
};

// A red-black tree node of a std::map<unsigned long, smart pointer>.
struct Pair_ad2a40 {
    uint32_t mnKey;
    void* mpValue;
    // STUB: 0x009491ff
    void Destroy(uint32_t flag);
};

struct TreeNode_ad2a40 {
    uint32_t mnColor;
    TreeNode_ad2a40* mpParent;
    TreeNode_ad2a40* mpLeft;
    TreeNode_ad2a40* mpRight;
    Pair_ad2a40 mValue;
};

// STUB: 0x0040d4c0
TreeNode_ad2a40* Fn0040d4c0(TreeNode_ad2a40* node);

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// A std::map<unsigned long, ...>: pointer to the header node, then the count.
struct cULongMap_ad2a40 {
    TreeNode_ad2a40* mpHeader;
    uint32_t mnCount;
    // STUB: 0x00938263
    void ClearGroups();
    // STUB: 0x0093828c
    void ClearSegments();
    // STUB: 0x0098129c
    TreeNode_ad2a40* Find(const uint32_t* key);
    // STUB: 0x00968d88
    void EraseNode(Iter_ad2a40 node);
    // STUB: 0x0096982e
    void* Index(const uint32_t* key);
    void Fn00937f08(TreeNode_ad2a40* node);
    void RemoveAllSems();
};

// The duck map (std::map<const cIGZSnd*, long>).
struct cDuckMap_ad2a40 {
    TreeNode_ad2a40* mpHeader;
    uint32_t mnCount;
    // STUB: 0x00937c8e
    void Clear();
    // STUB: 0x00927cf8
    void EraseNode(Iter_ad2a40 node);
    // STUB: 0x00937e7e
    void Erase(Iter_ad2a40 first, Iter_ad2a40 last);
    void Fn00938220(Iter_ad2a40 first, Iter_ad2a40 last);
};

// A smart pointer (assignment at 0x005447b0).
struct cAutoRefB_ad2a40 {
    void* mp;
    // STUB: 0x005447b0
    cAutoRefB_ad2a40& Assign(void* p);
};

// A smart pointer built from a raw pointer (0x0096e773).
struct cSmartRef_ad2a40 {
    void* mp;
    // STUB: 0x0096e773
    cSmartRef_ad2a40(void* p);
    ~cSmartRef_ad2a40()
    {
        if (mp) {
            static_cast<cRef_ad2a40*>(mp)->Release();
        }
    }
};

// A channel object (0x38 bytes) built by 0x0093fe12; asked for an interface through slot 0.
struct cChannel_ad2a40 {
    virtual bool QueryInterface(uint32_t id, void** out);
    // STUB: 0x0093fe12
    cChannel_ad2a40* Construct();
};

// A bound object found in a map: slot 0 is QueryInterface.
struct cBound_ad2a40 {
    virtual bool QueryInterface(uint32_t id, void** out);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00937c54 score 9
void cBlockList_ad2a40::Remove(const uint32_t* value)
{
    ListNode_ad2a40* head = mpHead;
    ListNode_ad2a40* node = head->mpNext;
    if (node != head) {
        ListNode_ad2a40* next;
        do {
            next = node->mpNext;
            if (*value == node->mnValue) {
                Iter_ad2a40 result(0);
                Erase(node, &result);
            }
            node = next;
        } while (next != head);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00937e7e score 38
void cDuckMap_ad2a40::Erase(Iter_ad2a40 first, Iter_ad2a40 last)
{
    TreeNode_ad2a40* node = static_cast<TreeNode_ad2a40*>(first.mpNode);
    if (node == mpHeader->mpLeft && last.mpNode == mpHeader) {
        Clear();
    } else {
        while (node != last.mpNode) {
            TreeNode_ad2a40* current = node;
            node = Fn0040d4c0(node);
            EraseNode(current);
        }
    }
}
#endif

// FUNCTION: 0x00937f08
void cULongMap_ad2a40::Fn00937f08(TreeNode_ad2a40* node)
{
    while (node) {
        Fn00937f08(node->mpRight);
        TreeNode_ad2a40* left = node->mpLeft;
        node->mValue.Destroy(0);
        Fn0090cf63(node);
        node = left;
    }
}

// FUNCTION: 0x00938220
void cDuckMap_ad2a40::Fn00938220(Iter_ad2a40 first, Iter_ad2a40 last)
{
    Erase(first, last);
}

// FUNCTION: 0x0093823a
void cULongMap_ad2a40::RemoveAllSems()
{
    if (mnCount) {
        Fn00937f08(mpHeader->mpParent);
        mpHeader->mpLeft = mpHeader;
        mpHeader->mpParent = 0;
        mpHeader->mpRight = mpHeader;
        mnCount = 0;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00937d48 score 16
bool cHitMan::RemoveFromActiveTrackList(uint32_t snd)
{
    cList_ad2a40* list = static_cast<cList_ad2a40*>(mpActiveTracks);
    ListNode_ad2a40* first = list->mpHead->mpNext;
    if (first != list->mpHead) {
        Iter_ad2a40 result(0);
        list->Erase(first, &result);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00937d6c score 12
void cHitMan::Slot18_ad2540(uint32_t snd)
{
    cList_ad2a40* list = reinterpret_cast<cList_ad2a40*>(&mpChannelList);
    ListNode_ad2a40* head = list->mpHead;
    ListNode_ad2a40* node = head->mpNext;
    if (node != head) {
        while (node->mnValue != snd) {
            node = node->mpNext;
            if (node == head) {
                break;
            }
        }
        if (node != head) {
            Iter_ad2a40 result(0);
            list->Erase(node, &result);
            static_cast<cRef_ad2a40*>(OB_PTR(cRef_ad2a40, snd))->Release();
        }
    }
}
#endif

// FUNCTION: 0x00937da7
uint32_t cHitMan::Slot41_ad2540()
{
    cDuckMap_ad2a40* map = reinterpret_cast<cDuckMap_ad2a40*>(&mpDuckMapHeader);
    TreeNode_ad2a40* header = map->mpHeader;
    TreeNode_ad2a40* node = header->mpLeft;
    int32_t best = 0;
    while (node != header) {
        int32_t value = static_cast<int32_t>(OB_ADDR(node->mValue.mpValue));
        if (value > best) {
            best = value;
        }
        node = Fn0040d4c0(node);
    }
    return best;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00937dcc score 6
bool cHitMan::Slot12_ad2540(uint32_t block)
{
    ++mnBlockListLock;
    cSmartRef_ad2a40 ref(OB_PTR(void, block));
    reinterpret_cast<cBlockList_ad2a40*>(&mpBlockList)->Remove(reinterpret_cast<const uint32_t*>(&ref));
    --mnBlockListLock;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00937e02 score 2
uint32_t cHitMan::Slot25_ad2540(uint32_t index)
{
    TreeNode_ad2a40* node = reinterpret_cast<cULongMap_ad2a40*>(&mpSemMapHeader)->mpHeader->mpLeft;
    while (index) {
        node = Fn0040d4c0(node);
        --index;
    }
    return OB_ADDR(node->mValue.mpValue);
}
#endif

// FUNCTION: 0x009380e3
bool cHitMan::Slot38_ad2540(uint32_t id, uint32_t out)
{
    uint32_t key = id;
    cULongMap_ad2a40* map = reinterpret_cast<cULongMap_ad2a40*>(&mpSeqGroupMapHeader);
    TreeNode_ad2a40* node = map->Find(&key);
    if (node != map->mpHeader) {
        *OB_PTR(void*, out) = node->mValue.mpValue;
        return true;
    }
    *OB_PTR(void*, out) = 0;
    return false;
}

// FUNCTION: 0x00938201
uint32_t cHitMan::Slot22_ad2540(uint32_t id)
{
    cULongMap_ad2a40* map = reinterpret_cast<cULongMap_ad2a40*>(&mpSemMapHeader);
    TreeNode_ad2a40* node = map->Find(&id);
    if (node == map->mpHeader) {
        return 0;
    }
    return OB_ADDR(node->mValue.mpValue);
}

// FUNCTION: 0x00938419
bool cHitMan::AddToActiveTrackList(uint32_t snd)
{
    RemoveFromActiveTrackList(snd);
    static_cast<cList_ad2a40*>(mpActiveTracks)->PushBack(&snd);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009381a4 score 4
void cHitMan::Slot44_ad2540(uint32_t id, uint32_t iid, uint32_t out)
{
    cULongMap_ad2a40* map = reinterpret_cast<cULongMap_ad2a40*>(&mpSegmentMapHeader);
    TreeNode_ad2a40* node = map->Find(&id);
    if (node != map->mpHeader) {
        static_cast<cBound_ad2a40*>(node->mValue.mpValue)->QueryInterface(iid, OB_PTR(void*, out));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009381d4 score 4
void cHitMan::Slot23_ad2540(uint32_t id, uint32_t iid, uint32_t out)
{
    cULongMap_ad2a40* map = reinterpret_cast<cULongMap_ad2a40*>(&mpSemMapHeader);
    TreeNode_ad2a40* node = map->Find(&id);
    if (node != map->mpHeader) {
        static_cast<cBound_ad2a40*>(node->mValue.mpValue)->QueryInterface(iid, OB_PTR(void*, out));
    }
}
#endif

// FUNCTION: 0x00938540
void cHitMan::Slot45_ad2540(uint32_t id)
{
    cULongMap_ad2a40* map = reinterpret_cast<cULongMap_ad2a40*>(&mpSegmentMapHeader);
    TreeNode_ad2a40* node = map->Find(&id);
    if (node != map->mpHeader) {
        map->EraseNode(node);
    }
}

// FUNCTION: 0x00938567
bool cHitMan::Slot20_ad2540(uint32_t id)
{
    cULongMap_ad2a40* map = reinterpret_cast<cULongMap_ad2a40*>(&mpSemMapHeader);
    TreeNode_ad2a40* node = map->Find(&id);
    if (node == map->mpHeader) {
        return false;
    }
    map->EraseNode(node);
    return true;
}

// FUNCTION: 0x0093899f
bool cHitMan::Slot21_ad2540()
{
    reinterpret_cast<cULongMap_ad2a40*>(&mpSemMapHeader)->RemoveAllSems();
    return true;
}

// FUNCTION: 0x00938a26
void cHitMan::Slot37_ad2540(uint32_t id, uint32_t snd)
{
    reinterpret_cast<cAutoRefB_ad2a40*>(reinterpret_cast<cULongMap_ad2a40*>(&mpSeqGroupMapHeader)->Index(&id))->Assign(OB_PTR(void, snd));
}

// FUNCTION: 0x00938b50
void cHitMan::Slot43_ad2540(uint32_t id, uint32_t segment)
{
    reinterpret_cast<cAutoRef_ad2a40*>(reinterpret_cast<cULongMap_ad2a40*>(&mpSegmentMapHeader)->Index(&id))->Assign(OB_PTR(void, segment));
}

#ifdef OB_DRAFTS
// CLOSE: 0x00938492 score 13
void cHitMan::Slot42_ad2540()
{
    cDuckMap_ad2a40* map = reinterpret_cast<cDuckMap_ad2a40*>(&mpDuckMapHeader);
    Iter_ad2a40 end(map->mpHeader);
    Iter_ad2a40 begin(map->mpHeader->mpLeft);
    map->Fn00938220(begin, end);
    Slot30_ad2540(0x1b, 0);
    Slot05_ad2540();
}
#endif

// ---- batch 3

// STUB: 0x0098129c
// (declared per map type above) the duck map also finds and indexes by key:
struct cDuckMapAccess_ad2a40 : public cDuckMap_ad2a40 {
    // STUB: 0x0098129c
    TreeNode_ad2a40* Find(const uint32_t* key);
    // STUB: 0x0096a7b0
    uint32_t* Index(const uint32_t* key);
};

// The map of control groups (another instantiation).
struct cCtlMap_ad2a40 {
    TreeNode_ad2a40* mpHeader;
    uint32_t mnCount;
    // STUB: 0x0094c8f5
    TreeNode_ad2a40* Find(const uint32_t* key);
    // STUB: 0x009389aa
    void* Index(const uint32_t* key);
};

// The map of type-to-group associations (value: a list of groups).
struct cTypeMap_ad2a40 {
    TreeNode_ad2a40* mpHeader;
    uint32_t mnCount;
    // STUB: 0x00927cf8
    void EraseNode(Iter_ad2a40 node);
    // STUB: 0x0098129c
    TreeNode_ad2a40* Find(const uint32_t* key);
    // STUB: 0x0096a7b0
    void** Index(const uint32_t* key);
};

// The list of groups of one type (a std::list<unsigned long>, allocated on its own).
struct cGroupList_ad2a40 {
    ListNode_ad2a40* mpHead;
    // STUB: 0x005650a0
    void Destroy();
    // STUB: 0x004f5a00
    cGroupList_ad2a40(const void* allocator);
    // STUB: 0x00427640
    void PushBack(const uint32_t* value);
};

// The control group object built with 0x0093873f; slot 0 is QueryInterface.
struct cCtlGroupObj_ad2a40 {
    virtual bool QueryInterface(uint32_t id, void** out);
    // STUB: 0x0093873f
    cCtlGroupObj_ad2a40* Construct(uint32_t id);
};

// The message-sending service pointer (0x004496c0 / 0x004495c0).
struct cMsgSvc_ad2a40 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual bool Fn3(void* msg, uint32_t id, uint32_t c, uint32_t d, uint32_t e);
};
struct cMsgSvcPtr_ad2a40 {
    cMsgSvc_ad2a40* mp;
    // STUB: 0x004496c0
    cMsgSvcPtr_ad2a40();
    // STUB: 0x004495c0
    ~cMsgSvcPtr_ad2a40();
};

struct Msg_ad2a40 {
    uint32_t mnType;
    uint32_t mnValue;
    uint32_t mnA;
};

// A track data block as the list holds it: slot 5 finds an id's offset.
struct cBlock_ad2a40 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual bool Fn5(uint32_t id, uint32_t* offset);
};

// The random number source (this+0x90).
struct cRandom_ad2a40 {
    // STUB: 0x009136b1
    uint32_t Next(uint32_t range);
};

// The sem object: slot 3 gives its id.
struct cSem_ad2a40 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual uint32_t Fn3();
};

// The group map's inner list type: another std::list instantiation.
// STUB: 0x009690f4
struct cBlockListPush_ad2a40 : public cBlockList_ad2a40 {
    // STUB: 0x009690f4
    void PushBack(cSmartRef_ad2a40* ref);
};

// GLOBAL: 0x00ad2518
extern const uint32_t g00ad2518;

// FUNCTION: 0x00937c00
bool cHitMan::Slot13_ad2540(uint32_t id, uint32_t outBlock, uint32_t outOffset)
{
    uint32_t offset;
    bool found;
    ListNode_ad2a40* head = reinterpret_cast<cBlockList_ad2a40*>(&mpBlockList)->mpHead;
    ++mnBlockListLock;
    ListNode_ad2a40* node = head->mpNext;
    found = false;
    while (node != head) {
        if (OB_PTR(cBlock_ad2a40, node->mnValue)->Fn5(id, &offset)) {
            *OB_PTR(uint32_t, outBlock) = node->mnValue;
            found = true;
            *OB_PTR(uint32_t, outOffset) = offset;
            break;
        }
        node = node->mpNext;
    }
    --mnBlockListLock;
    return found;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00938118 score 24
bool cHitMan::Slot16_ad2540(uint32_t a, uint32_t b, uint32_t c)
{
    cMsgSvcPtr_ad2a40 service;
    cTypeMap_ad2a40* map = reinterpret_cast<cTypeMap_ad2a40*>(&mpTypeGroupMapHeader);
    TreeNode_ad2a40* node = map->Find(&g00ad2518);
    if (node != map->mpHeader) {
        cGroupList_ad2a40* groups = static_cast<cGroupList_ad2a40*>(node->mValue.mpValue);
        if (groups != 0) {
            bool result = false;
            ListNode_ad2a40* head = groups->mpHead;
            ListNode_ad2a40* item = head->mpNext;
            while (item != head) {
                Msg_ad2a40 msg;
                msg.mnType = 0x7b1acfcd;
                msg.mnValue = item->mnValue;
                msg.mnA = a;
                if (service.mp->Fn3(&msg, 0xdb1acfb2, c, 0, 0)) {
                    result = true;
                    break;
                }
                item = item->mpNext;
            }
            return result;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00938a41 score 13
void cHitMan::Slot39_ad2540(uint32_t snd, uint32_t pri)
{
    if (mbDuckEnabled) {
        cDuckMapAccess_ad2a40* map = static_cast<cDuckMapAccess_ad2a40*>(reinterpret_cast<cDuckMap_ad2a40*>(&mpDuckMapHeader));
        TreeNode_ad2a40* node = map->Find(&snd);
        bool found = node != map->mpHeader;
        bool changed = false;
        if (pri != 0) {
            if (!found || OB_ADDR(node->mValue.mpValue) != pri) {
                changed = true;
            }
            *map->Index(&snd) = pri;
        } else if (found) {
            map->EraseNode(node);
            changed = true;
        }
        if (changed) {
            Slot30_ad2540(0x1b, Slot41_ad2540());
            Slot05_ad2540();
        }
    }
}
#endif

// FUNCTION: 0x00938ac6
uint32_t cHitMan::Slot40_ad2540(uint32_t snd)
{
    cDuckMapAccess_ad2a40* map = static_cast<cDuckMapAccess_ad2a40*>(reinterpret_cast<cDuckMap_ad2a40*>(&mpDuckMapHeader));
    if (map->Find(&snd) != map->mpHeader) {
        return *map->Index(&snd);
    }
    return 0;
}

// FUNCTION: 0x00938af0
uint32_t cHitMan::Slot35_ad2540(uint32_t id)
{
    cCtlMap_ad2a40* map = reinterpret_cast<cCtlMap_ad2a40*>(&mpControlGroupMapHeader);
    TreeNode_ad2a40* node = map->Find(&id);
    if (node == map->mpHeader) {
        cCtlGroupObj_ad2a40* group = static_cast<cCtlGroupObj_ad2a40*>(operator new(0x38));
    if (group) {
        group = group->Construct(id);
    } else {
        group = 0;
    }
    void* iface;
    group->QueryInterface(0xfb1c0050, &iface);
    *reinterpret_cast<void**>(map->Index(&id)) = iface;
        return OB_ADDR(iface);
    }
    return OB_ADDR(node->mValue.mpValue);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00938b6e score 31
bool cHitMan::Slot46_ad2540(uint32_t type, uint32_t group)
{
    cTypeMap_ad2a40* map = reinterpret_cast<cTypeMap_ad2a40*>(&mpTypeGroupMapHeader);
    cGroupList_ad2a40* list;
    TreeNode_ad2a40* node = map->Find(&type);
    if (node != map->mpHeader) {
        list = static_cast<cGroupList_ad2a40*>(node->mValue.mpValue);
    } else {
        list = static_cast<cGroupList_ad2a40*>(operator new(4));
        if (list) {
            char allocator;
            new (list) cGroupList_ad2a40(&allocator);
        }
        if (!list) {
            return false;
        }
        *map->Index(&type) = list;
    }
    ListNode_ad2a40* head = list->mpHead;
    ListNode_ad2a40* item = head->mpNext;
    if (item != head) {
        while (item->mnValue != group) {
            item = item->mpNext;
            if (item == head) {
                break;
            }
        }
    }
    if (item == head) {
        list->PushBack(&group);
    }
    return true;
}
#endif

// FUNCTION: 0x00938bf1
bool cHitMan::Slot19_ad2540(uint32_t sem)
{
    uint32_t id = OB_PTR(cSem_ad2a40, sem)->Fn3();
    reinterpret_cast<cAutoRefB_ad2a40*>(reinterpret_cast<cULongMap_ad2a40*>(&mpSemMapHeader)->Index(&id))->Assign(OB_PTR(void, sem));
    return id != 0;
}

// FUNCTION: 0x00939993
uint32_t cHitMan::Slot26_ad2540(uint32_t a, uint32_t b)
{
    return reinterpret_cast<cRandom_ad2a40*>(&mRandom)->Next(a - b) + b;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009384c1 score 18
bool cHitMan::Slot11_ad2540(uint32_t block)
{
    uint32_t iface = block;
    if (block != 0) {
        iface = 0;
        if (!OB_PTR(cBound_ad2a40, block)->QueryInterface(0x9b82eae7, OB_PTR(void*, OB_ADDR(&iface)))) {
            return false;
        }
    }
    Slot12_ad2540(block);
    ++mnBlockListLock;
    cSmartRef_ad2a40 ref(OB_PTR(void, block));
    static_cast<cBlockListPush_ad2a40*>(reinterpret_cast<cBlockList_ad2a40*>(&mpBlockList))->PushBack(&ref);
    --mnBlockListLock;
    if (iface) {
        OB_PTR(cRef_ad2a40, iface)->Release();
    }
    return true;
}
#endif

// ---- batch 4

struct cUnk_ad2a40 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
};

// The persistence resource manager (slot 32 finds the segment of a key).
struct cPersistMgr_ad2a40 : public cUnk_ad2a40 {
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
    virtual bool Fn32(void* key, void** segment);
};
struct cPersistMgrPtr_ad2a40 {
    cPersistMgr_ad2a40* mp;
    // STUB: 0x004496c0
    cPersistMgrPtr_ad2a40();
    // STUB: 0x004495c0
    ~cPersistMgrPtr_ad2a40();
};

// A database segment (slot 21 opens a record).
struct cSegment_ad2a40 : public cUnk_ad2a40 {
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
    virtual bool Fn21(void* key, void** record, uint32_t mode);
};

// A file object created by the framework; slot 3 attaches a record, slot 5 hands out its stream.
struct cFileObj_ad2a40 : public cUnk_ad2a40 {
    virtual void Fn3(void* record);
    virtual void Pad04();
    virtual cFileObj_ad2a40* Fn5();
};

// The framework object (GZCOM): slot 3 creates a component by two ids.
struct cGZCOM_ad2a40 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Fn3(uint32_t id1, uint32_t id2, void** out);
};
// STUB: 0x0090ddf1
cGZCOM_ad2a40* Fn0090ddf1();

// STUB: 0x00938263
// STUB: 0x0093828c
// STUB: 0x009677e6

#ifdef OB_DRAFTS
// CLOSE: 0x009379ef score 26
bool cHitMan::ParseHitFileFromIGZPersistRecordAsIGZFile(uint32_t key)
{
    bool ok = false;
    cPersistMgrPtr_ad2a40 manager;
    if (manager.mp != 0) {
        cSegment_ad2a40* segment;
        if (manager.mp->Fn32(OB_PTR(void, key), reinterpret_cast<void**>(&segment))) {
            cUnk_ad2a40* record = 0;
            if (segment->Fn21(OB_PTR(void, key), reinterpret_cast<void**>(&record), 1)) {
                cUnk_ad2a40* stream = 0;
                if (record->QueryInterface(0xc56b8f08, reinterpret_cast<void**>(&stream))) {
                    cFileObj_ad2a40* file = 0;
                    cGZCOM_ad2a40* com = Fn0090ddf1();
                    if (file) {
                        cFileObj_ad2a40* old = file;
                        file = 0;
                        old->Release();
                    }
                    com->Fn3(0xa32c0da, 0x8a32c0ac, reinterpret_cast<void**>(&file));
                    if (file) {
                        file->Fn3(stream);
                        ok = ParseHitFile(OB_ADDR(file->Fn5()));
                        file->Fn5()->Fn5();
                        stream->Release();
                    }
                    if (file) {
                        file->Release();
                    }
                }
                record->Release();
            }
            segment->Release();
        }
    }
    return ok;
}
#endif

// STUB: 0x0090fcef
uint32_t Fn0090fcef(const char* text);

#ifdef OB_DRAFTS
// CLOSE: 0x00938ec6 score 77
bool cHitMan::FilepathHasEmbeddedKey(uint32_t path, uint32_t out)
{
    cRZString text(*OB_PTR(cRZString, path), 0, std::string::npos);
    const char* data = text.std::string::c_str();
    uint32_t i = 0;
    uint32_t count = 0;
    uint32_t group = 0;
    uint32_t instance = 0;
    uint32_t type = 0;
    if (text.Strlen() > 0) {
        for (; i < text.Strlen(); ++i) {
            if (strchr("0123456789abcdefABCDEF", data[i])) {
                ++count;
            } else {
                count = 0;
            }
            if (count == 8) {
                type = Fn0090fcef(data + i - 7);
                if (type == 0) {
                    return false;
                }
                count = 0;
                for (++i; i < text.Strlen(); ++i) {
                    if (strchr("0123456789abcdefABCDEF", data[i])) {
                        ++count;
                    } else {
                        count = 0;
                    }
                    if (count == 8) {
                        group = Fn0090fcef(data + i - 7);
                        if (group == 0) {
                            return false;
                        }
                        count = 0;
                        for (++i; i < text.Strlen(); ++i) {
                            if (strchr("0123456789abcdefABCDEF", data[i])) {
                                ++count;
                            } else {
                                count = 0;
                            }
                            if (count == 8) {
                                instance = Fn0090fcef(data + i - 7);
                                if (instance == 0) {
                                    return false;
                                }
                                uint32_t* key = OB_PTR(uint32_t, out);
                                key[0] = type;
                                key[1] = group;
                                key[2] = instance;
                                return true;
                            }
                        }
                        return false;
                    }
                }
                return false;
            }
        }
    }
    return false;
}
#endif

// A pointer to a list element object whose slot 9 is called when the track list is torn down.
struct cTrackObj_ad2a40 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Fn09();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00938643 score 55
bool cHitMan::Slot04_ae1d24()
{
    if (mbDuckEnabled) {
        reinterpret_cast<cULongMap_ad2a40*>(&mpSeqGroupMapHeader)->ClearGroups();
        cList_ad2a40* tracks = static_cast<cList_ad2a40*>(mpActiveTracks);
        if (tracks != 0) {
            ListNode_ad2a40* head = tracks->mpHead;
            ListNode_ad2a40* node = head->mpNext;
            if (node != head) {
                do {
                    cTrackObj_ad2a40* track = OB_PTR(cTrackObj_ad2a40, node->mnValue);
                    if (track != 0) {
                        track->Fn09();
                    }
                    node = node->mpNext;
                } while (node != static_cast<cList_ad2a40*>(mpActiveTracks)->mpHead);
            }
            static_cast<cList_ad2a40*>(mpActiveTracks)->Clear();
            cList_ad2a40* list = static_cast<cList_ad2a40*>(mpActiveTracks);
            if (list != 0) {
                list->Destroy();
                operator delete(list);
            }
            mpActiveTracks = 0;
        }
        cTypeMap_ad2a40* types = reinterpret_cast<cTypeMap_ad2a40*>(&mpTypeGroupMapHeader);
        while (types->mnCount != 0) {
            TreeNode_ad2a40* node = types->mpHeader->mpLeft;
            cGroupList_ad2a40* groups = static_cast<cGroupList_ad2a40*>(node->mValue.mpValue);
            if (groups != 0) {
                groups->Destroy();
                operator delete(groups);
            }
            types->EraseNode(node);
        }
        reinterpret_cast<cAutoRef_ad2a40*>(&mpSmart4c)->Assign(0);
        reinterpret_cast<cAutoRef_ad2a40*>(&mpSmart54)->Assign(0);
        reinterpret_cast<cAutoRef_ad2a40*>(&mpDataHandler)->Assign(0);
        reinterpret_cast<cULongMap_ad2a40*>(&mpSemMapHeader)->RemoveAllSems();
        reinterpret_cast<cBlockList_ad2a40*>(&mpBlockList)->Clear();
        reinterpret_cast<cULongMap_ad2a40*>(&mpSeqGroupMapHeader)->ClearGroups();
        reinterpret_cast<cULongMap_ad2a40*>(&mpSegmentMapHeader)->ClearSegments();
        reinterpret_cast<cAutoRef_ad2a40*>(&mpSmart4c)->Assign(0);
        reinterpret_cast<cAutoRef_ad2a40*>(&mpSmart54)->Assign(0);
        mbDuckEnabled = 0;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00938438 score 4
bool cHitMan::Slot17_ad2540(uint32_t id, uint32_t out)
{
    cChannel_ad2a40* channel = static_cast<cChannel_ad2a40*>(operator new(0x38));
    if (channel) {
        channel = channel->Construct();
    } else {
        channel = 0;
    }
    uint32_t iface = 0;
    bool ok = channel->QueryInterface(0x206077d2, reinterpret_cast<void**>(&iface));
    if (ok && iface != 0) {
        reinterpret_cast<cList_ad2a40*>(&mpChannelList)->PushBack(&iface);
        *OB_PTR(uint32_t, out) = iface;
    }
    return ok;
}
#endif
