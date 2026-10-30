#include "classes/cGZPersistResourceManager.h"
#include <stddef.h>
#include <new>
#include "classes/cUnk00ad8970.h"

// A resource key: three words.
struct Key_ad89d0 {
    uint32_t v[3];
};

// The lock objects embedded in the manager (a vtable and one word); only the slots used here are named.
struct Lock_ad89d0 {
    virtual void Pad0_ad89d0();
    virtual void Enter_ad89d0();
    virtual void Leave_ad89d0();
};

// A scope guard over a lock: the constructor takes the lock, the destructor lets it go.
struct Guard_ad89d0 {
    uint32_t mPad;
    Lock_ad89d0* mpLock;

    // STUB: 0x0048c9f0
    Guard_ad89d0(Lock_ad89d0* lock);
    ~Guard_ad89d0() { mpLock->Leave_ad89d0(); }
};

// Views of the interfaces the manager calls through (slots by their offsets; only those used are named).
struct Unk_ad89d0 {
    virtual bool Query_ad89d0(uint32_t, uint32_t);
    virtual void Pad1_ad89d0();
    virtual uint32_t Release_ad89d0();
};

struct Rec_ad89d0 {
    virtual void Pad0_ad89d0();
    virtual void Pad1_ad89d0();
    virtual uint32_t Release_ad89d0();
    virtual void Pad3_ad89d0();
    virtual void Pad4_ad89d0();
    virtual bool Close5_ad89d0();
};

struct Res_ad89d0 {
    virtual bool Query_ad89d0(uint32_t, uint32_t);
    virtual void Pad1_ad89d0();
    virtual uint32_t Release_ad89d0();
    virtual Key_ad89d0* GetKey_ad89d0(Key_ad89d0* key);
    virtual void SetKey_ad89d0(uint32_t key);
    virtual uint32_t GetType_ad89d0();
};

struct List_ad89d0 {
    virtual void Pad0_ad89d0();
    virtual void Pad1_ad89d0();
    virtual void Pad2_ad89d0();
    virtual void Pad3_ad89d0();
    virtual void Pad4_ad89d0();
    virtual void Pad5_ad89d0();
    virtual void Pad6_ad89d0();
    virtual void Pad7_ad89d0();
    virtual void Pad8_ad89d0();
    virtual uint32_t Count_ad89d0();
    virtual uint32_t Get_ad89d0(uint32_t index);
};

struct Factory_ad89d0 {
    virtual void Pad0_ad89d0();
    virtual void Pad1_ad89d0();
    virtual uint32_t Release_ad89d0();
    virtual bool Make3_ad89d0(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
    virtual bool Make4_ad89d0(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
    virtual void Pad5_ad89d0();
    virtual bool Save6_ad89d0(uint32_t res, uint32_t rec);
    virtual bool Find7_ad89d0(uint32_t key, uint32_t out);
    virtual void Add8_ad89d0(uint32_t key, uint32_t res);
    virtual bool Remove9_ad89d0(uint32_t key);
    virtual bool Has10_ad89d0(uint32_t key);
    virtual bool Has11_ad89d0(uint32_t key);
    virtual uint32_t Collect12_ad89d0(void* list, void* filter);
    virtual void Pad13_ad89d0();
    virtual bool Cond14_ad89d0(uint32_t);
    virtual bool Gc15_ad89d0();
    virtual void SetGc16_ad89d0(uint32_t);
    virtual bool Force17_ad89d0();
};

struct Seg_ad89d0 {
    virtual void Pad0_ad89d0();
    virtual void AddRef_ad89d0();
    virtual uint32_t Release_ad89d0();
    virtual void Pad3_ad89d0();
    virtual void Pad4_ad89d0();
    virtual void Pad5_ad89d0();
    virtual void Pad6_ad89d0();
    virtual void Pad7_ad89d0();
    virtual void Pad8_ad89d0();
    virtual void Pad9_ad89d0();
    virtual void Pad10_ad89d0();
    virtual void Pad11_ad89d0();
    virtual void Pad12_ad89d0();
    virtual void Pad13_ad89d0();
    virtual uint32_t GetId14_ad89d0();
    virtual void Pad15_ad89d0();
    virtual void Pad16_ad89d0();
    virtual void Pad17_ad89d0();
    virtual uint32_t Collect18_ad89d0(void* list, void* filter);
    virtual bool Has19_ad89d0(uint32_t key);
    virtual void Pad20_ad89d0();
    virtual bool Open21_ad89d0(uint32_t key, uint32_t rec, uint32_t flags);
    virtual bool Create22_ad89d0(uint32_t key, uint32_t rec);
    virtual bool Close23_ad89d0(uint32_t rec);
    virtual void Close24_ad89d0(uint32_t rec);
    virtual void Abort25_ad89d0(uint32_t rec);
};

// An iterator of the segment deque: the element, its block's bounds and the block pointer.
struct Seg_ad89d0;

// STUB: 0x0090cf63
void StlDelete_ad89d0(void* p);
struct Iter_ad89d0 {
    Seg_ad89d0** mpCur;
    Seg_ad89d0** mpFirst;
    Seg_ad89d0** mpLast;
    Seg_ad89d0*** mpNode;

    // STUB: 0x0097316e
    void Advance_ad89d0();
    // STUB: 0x0097cf72
    uint32_t Diff_ad89d0(const Iter_ad89d0* other);
    // STUB: 0x0097304d
    void AddAssign_ad89d0(uint32_t n);
    // STUB: 0x00973669
    void AdvanceSlow_ad89d0();
    Iter_ad89d0 Plus_ad89d0(uint32_t n);
    Seg_ad89d0** Index_ad89d0(uint32_t n);
    void AdvanceFast_ad89d0();
};

typedef bool SegCallback_ad89d0(Seg_ad89d0* seg, void* user);

struct Node_ad89d0;

// A node of the factory hash table: next link, key, factory.
struct HNode_ad89d0 {
    HNode_ad89d0* mpNext;
    uint32_t mnKey;
    union {
        Unk_ad89d0* mpItem;
        uint32_t mnValue;
    };
};

struct HTable_ad89d0;

// A key-value pair to insert.
struct Pair_ad89d0 {
    uint32_t mnKey;
    uint32_t mnValue;
};

// An iterator over the table: the node and its table.
struct HIter_ad89d0 {
    HNode_ad89d0* mpNode;
    HTable_ad89d0* mpTable;

    // STUB: 0x00969127
    void Next_ad89d0();
};

struct HTable_ad89d0 {
    uint32_t mPad0;
    HNode_ad89d0** mpBuckets;
    HNode_ad89d0** mpBucketsEnd;
    uint32_t mPad3;
    uint32_t mnCount;

    // STUB: 0x009978af
    void Resize_ad89d0(uint32_t n);
    // STUB: 0x00973ac4
    HIter_ad89d0* InsertEqual_ad89d0(HIter_ad89d0* out, const Pair_ad89d0* p);
    // STUB: 0x00968cb6
    HNode_ad89d0* NewNode_ad89d0(const Pair_ad89d0* p);
    HIter_ad89d0* InsertEqualDraft_ad89d0(HIter_ad89d0* out, const Pair_ad89d0* p);
    // STUB: 0x00968cd9
    HNode_ad89d0* Find_ad89d0(uint32_t* key);
    // STUB: 0x0097c081
    void Begin_ad89d0(HIter_ad89d0* out);
    // STUB: 0x0092dc3a
    void Erase_ad89d0(HIter_ad89d0 at);
    // STUB: 0x0097c1a2
    void Clear_ad89d0();
    HIter_ad89d0* Insert_ad89d0(HIter_ad89d0* out, const Pair_ad89d0* pair);
};

// The table mapping a type to the type of its factory.
struct HTableMap_ad89d0 {
    uint32_t mPad0;
    HNode_ad89d0** mpBuckets;
    HNode_ad89d0** mpBucketsEnd;
    uint32_t mPad3;
    uint32_t mnCount;

    // STUB: 0x004f0940
    void Resize_ad89d0(uint32_t n);
    // STUB: 0x00973b37
    HIter_ad89d0* InsertEqual_ad89d0(HIter_ad89d0* out, const Pair_ad89d0* p);
    // STUB: 0x0050b9f0
    HNode_ad89d0* NewNode_ad89d0(const Pair_ad89d0* p);
    HIter_ad89d0* InsertEqualDraft_ad89d0(HIter_ad89d0* out, const Pair_ad89d0* p);
    // STUB: 0x0058efe0
    HNode_ad89d0* Find_ad89d0(uint32_t* key);
    HIter_ad89d0* Insert_ad89d0(HIter_ad89d0* out, const Pair_ad89d0* pair);
};

// The list of cache strategies: a position is its node.
struct ListIter_ad89d0 {
    Node_ad89d0* mpNode;
};

struct StratList_ad89d0 {
    // STUB: 0x00968c53
    void Erase_ad89d0(ListIter_ad89d0* out, ListIter_ad89d0 at);
    // STUB: 0x009690f4
    void PushFront_ad89d0(void* ref);
    // STUB: 0x009677e6
    void Clear_ad89d0();
};

// A counted reference held while a strategy is added.
struct RefHolder_ad89d0 {
    Unk_ad89d0* mp;

    // STUB: 0x0096e773
    RefHolder_ad89d0(Unk_ad89d0* p);
    ~RefHolder_ad89d0() { if (mp) { mp->Release_ad89d0(); } }
};

// The segment deque: begin and end iterators.
struct Deque_ad89d0 {
    Iter_ad89d0 mBegin;
    Iter_ad89d0 mEnd;

    // STUB: 0x00974159
    Iter_ad89d0 Erase_ad89d0(Iter_ad89d0 at);
    void PushBack_ad89d0(Seg_ad89d0* const* p);
    // STUB: 0x0097435c
    void PushFront_ad89d0(Seg_ad89d0* const* p);
    void ClearDraft_ad89d0();
    // STUB: 0x00973baa
    void Clear_ad89d0();
    // STUB: 0x00891fd1
    void PopBackAux_ad89d0();
    // STUB: 0x00892252
    void PushBackAux_ad89d0(Seg_ad89d0* const* p);
    void PopBack_ad89d0();
};

// A cache strategy, as far as shutdown uses it.
struct Strat_ad89d0 {
    virtual void Pad0_ad89d0();
    virtual void Pad1_ad89d0();
    virtual void Pad2_ad89d0();
    virtual void Pad3_ad89d0();
    virtual void Shutdown4_ad89d0();
};

// The framework object the manager asks for factories.
struct Com_ad89d0 {
    virtual void Pad0_ad89d0();
    virtual void Pad1_ad89d0();
    virtual void Pad2_ad89d0();
    virtual bool Get3_ad89d0(uint32_t, uint32_t, uint32_t);
};

// STUB: 0x0090ddf1
Com_ad89d0* GZCOM();

// The key list the manager creates; its constructor is the original one.
struct KeyList_ad89d0 {
    virtual void Pad0_ad89d0();
    virtual void AddRef_ad89d0();
    virtual void Release_ad89d0();
    char mPad[0x3c];

    // STUB: 0x00974e7a
    KeyList_ad89d0();
};

// One node of the factory list: links, then the factory.
struct Node_ad89d0 {
    Node_ad89d0* mpNext;
    Node_ad89d0* mpPrev;
    Factory_ad89d0* mpItem;
};

// A key filter.
struct Filter_ad89d0 {
    virtual void Pad0_ad89d0();
    virtual void AddRef_ad89d0();
    virtual void Release_ad89d0();
};

// A view of the manager's own vtable for the slots whose result the original tests but the base declares void.
struct Self_ad89d0 {
    virtual void Pad0_ad89d0();
    virtual void Pad1_ad89d0();
    virtual void Pad2_ad89d0();
    virtual void Pad3_ad89d0();
    virtual void Pad4_ad89d0();
    virtual void Pad5_ad89d0();
    virtual void Pad6_ad89d0();
    virtual void Pad7_ad89d0();
    virtual void Pad8_ad89d0();
    virtual void Pad9_ad89d0();
    virtual void Pad10_ad89d0();
    virtual void Pad11_ad89d0();
    virtual void Pad12_ad89d0();
    virtual void Pad13_ad89d0();
    virtual void Pad14_ad89d0();
    virtual void Pad15_ad89d0();
    virtual void Pad16_ad89d0();
    virtual void Pad17_ad89d0();
    virtual void Pad18_ad89d0();
    virtual void Pad19_ad89d0();
    virtual void Pad20_ad89d0();
    virtual void Pad21_ad89d0();
    virtual bool FindFactory_ad89d0(uint32_t, uint32_t);
    virtual bool FindFactoryOf23_ad89d0(uint32_t, uint32_t);
};

// FUNCTION: 0x00972b51
bool cGZPersistResourceManager::QueryInterface(uint32_t id, void** out)
{
    if (id != 0x656b8efc) {
        return cRZSystemService::QueryInterface(id, out);
    }
    *out = this;
    AddRef();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00972b78 score 14
bool cGZPersistResourceManager::Slot37_ad88c0(uint32_t a, uint32_t b, uint32_t c)
{
    Seg_ad89d0* seg = 0;
    bool r = false;
    if (Slot32_ad88c0(a, OB_ADDR(&seg))) {
        uint32_t flags;
        if (*reinterpret_cast<bool*>(&c)) {
            flags = 3;
        } else {
            flags = 1;
        }
        r = seg->Open21_ad89d0(a, b, flags);
        seg->Release_ad89d0();
    }
    return r;
}
#endif

// FUNCTION: 0x00972bbf
bool cGZPersistResourceManager::Slot38_ad88c0(uint32_t /*a*/, uint32_t b)
{
    Rec_ad89d0** pp = OB_PTR(Rec_ad89d0*, b);
    bool r = (*pp)->Close5_ad89d0();
    (*pp)->Release_ad89d0();
    return r;
}

// FUNCTION: 0x00972bdc
bool cGZPersistResourceManager::Slot12_ad88c0(uint32_t a, uint32_t b)
{
    uint32_t rec = 0;
    bool r = false;
    if (Slot03_ad88c0(a, 0x456b8f1d, OB_ADDR(&rec), 0, 0)) {
        r = Slot13_ad88c0(rec, a, b);
        OB_PTR(Unk_ad89d0, rec)->Release_ad89d0();
    }
    return r;
}

// FUNCTION: 0x00972cdc
bool cGZPersistResourceManager::Slot11_ad88c0(uint32_t a, uint32_t b)
{
    uint32_t i = 0;
    bool r = true;
    List_ad89d0* list = OB_PTR(List_ad89d0, a);
    uint32_t n = list->Count_ad89d0();
    for (; i < n; i++) {
        if (!Slot12_ad88c0(list->Get_ad89d0(i), b)) {
            r = false;
        }
    }
    return r;
}

// FUNCTION: 0x00972d30
void cGZPersistResourceManager::Slot23_ad88c0(uint32_t a, uint32_t b)
{
    Slot21_ad88c0(OB_PTR(Res_ad89d0, a)->GetType_ad89d0(), b);
}

// FUNCTION: 0x00972d4e
void cGZPersistResourceManager::Slot22_ad88c0(uint32_t a, uint32_t b)
{
    Slot21_ad88c0(*OB_PTR(uint32_t, a), b);
}

// FUNCTION: 0x00972d60
bool cGZPersistResourceManager::Slot04_ad88c0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    bool r = false;
    if (CreateAndSerialize(a, 0x456b8f1d, OB_ADDR(&e), d, e)) {
        r = OB_PTR(Unk_ad89d0, e)->Query_ad89d0(b, c);
        OB_PTR(Unk_ad89d0, e)->Release_ad89d0();
    }
    return r;
}

// FUNCTION: 0x00972e2b
void cGZPersistResourceManager::Slot08_ad88c0(uint32_t a, uint32_t b)
{
    Res_ad89d0* res = OB_PTR(Res_ad89d0, b);
    res->SetKey_ad89d0(a);
    Slot07_ad88c0(b);
}

// FUNCTION: 0x00972e4b
bool cGZPersistResourceManager::Slot07_ad88c0(uint32_t a)
{
    if (a == 0) {
        return false;
    } else {
        bool r;
        Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
        Key_ad89d0 key;
        OB_PTR(Res_ad89d0, a)->GetKey_ad89d0(&key);
        r = Slot10_ad88c0(OB_ADDR(&key));
        if (!r) {
            r = AddResourceToCache(OB_ADDR(&key), a);
        }
        return r;
    }
}

// FUNCTION: 0x00972fae
bool cGZPersistResourceManager::CreateNewResource(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Factory_ad89d0* fac = 0;
    bool r = false;
    if (reinterpret_cast<Self_ad89d0*>(this)->FindFactory_ad89d0(a, OB_ADDR(&fac))) {
        r = fac->Make4_ad89d0(*OB_PTR(uint32_t, a), b, c, d, e);
        fac->Release_ad89d0();
    }
    return r;
}

// FUNCTION: 0x00972da2
bool cGZPersistResourceManager::Slot06_ad88c0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    uint32_t res = 0;
    bool r = false;
    if (CreateNewResource(a, 0x456b8f1d, OB_ADDR(&res), d, e)) {
        OB_PTR(Res_ad89d0, res)->SetKey_ad89d0(a);
        if (OB_PTR(Res_ad89d0, res)->Query_ad89d0(b, c)) {
            r = true;
            AddResourceToCache(a, res);
        }
        OB_PTR(Res_ad89d0, res)->Release_ad89d0();
        res = 0;
    }
    return r;
}

// FUNCTION: 0x00972eae
bool cGZPersistResourceManager::CreateAndSerialize(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t fac;
    uint32_t seg;
    bool r = false;
    if (reinterpret_cast<Self_ad89d0*>(this)->FindFactory_ad89d0(a, OB_ADDR(&fac))) {
        if (Slot32_ad88c0(a, OB_ADDR(&seg))) {
            if (ReadRecord(a, fac, seg, b, c, d, e)) {
                r = true;
            }
            OB_PTR(Unk_ad89d0, seg)->Release_ad89d0();
        }
        OB_PTR(Unk_ad89d0, fac)->Release_ad89d0();
    }
    return r;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00972f1d score 24
bool cGZPersistResourceManager::ReadRecord(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    Seg_ad89d0* seg = OB_PTR(Seg_ad89d0, c);
    uint32_t rec = 0;
    bool r = false;
    if (seg->Open21_ad89d0(a, OB_ADDR(&rec), 1)) {
        uint32_t out = 0;
        if (OB_PTR(Factory_ad89d0, b)->Make3_ad89d0(rec, 0x456b8f1d, OB_ADDR(&out), f, g)) {
            OB_PTR(Res_ad89d0, out)->SetKey_ad89d0(a);
            r = OB_PTR(Res_ad89d0, out)->Query_ad89d0(d, e);
            seg->Close24_ad89d0(rec);
            OB_PTR(Unk_ad89d0, rec)->Release_ad89d0();
            OB_PTR(Unk_ad89d0, out)->Release_ad89d0();
            return r;
        }
    } else if (rec == 0) {
        return r;
    }
    seg->Abort25_ad89d0(OB_ADDR(&rec));
    return false;
}
#endif

// FUNCTION: 0x00972ff2
uint32_t cGZPersistResourceManager::Fn00972ff2()
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock8c[0]));
    return mnCount94++;
}

// FUNCTION: 0x00973023
uint32_t cGZPersistResourceManager::Fn00973023()
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock8c[0]));
    return mnValue98;
}

// FUNCTION: 0x009730cc
bool cGZPersistResourceManager::Slot05_ad88c0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    bool r = false;
    uint32_t instance = Fn00972ff2();
    uint32_t group = Fn00973023();
    Key_ad89d0 key;
    key.v[0] = a;
    key.v[1] = group;
    key.v[2] = instance;
    uint32_t res;
    if (CreateNewResource(OB_ADDR(&key), 0x456b8f1d, OB_ADDR(&res), d, e)) {
        OB_PTR(Res_ad89d0, res)->SetKey_ad89d0(OB_ADDR(&key));
        if (OB_PTR(Res_ad89d0, res)->Query_ad89d0(b, c)) {
            r = true;
            AddResourceToCache(OB_ADDR(&key), res);
        }
        OB_PTR(Res_ad89d0, res)->Release_ad89d0();
    }
    return r;
}

// FUNCTION: 0x009731c2
uint32_t cGZPersistResourceManager::Slot15_ad88c0(uint32_t a, uint32_t b)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    uint32_t n = 0;
    KeyList_ad89d0* list = new KeyList_ad89d0;
    list->AddRef_ad89d0();
    *OB_PTR(KeyList_ad89d0*, a) = list;
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != static_cast<Node_ad89d0*>(mpList88); node = node->mpNext) {
        n += node->mpItem->Collect12_ad89d0(list, OB_PTR(void, b));
    }
    return n;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00973239 score 9
uint32_t cGZPersistResourceManager::Slot16_ad88c0(uint32_t a, uint32_t b)
{
    void* mem = operator new(sizeof(cUnk00ad8970));
    cUnk00ad8970* made;
    if (mem) {
        made = new (mem) cUnk00ad8970;
        *reinterpret_cast<uint32_t*>(made->unknown4) = 0;
        *reinterpret_cast<uint32_t*>(made->unknown8) = b;
    } else {
        made = 0;
    }
    Filter_ad89d0* filter = reinterpret_cast<Filter_ad89d0*>(made);
    filter->AddRef_ad89d0();
    uint32_t r = Slot15_ad88c0(a, OB_ADDR(filter));
    filter->Release_ad89d0();
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00973280 score 9
uint32_t cGZPersistResourceManager::Slot18_ad88c0(uint32_t a, uint32_t b)
{
    void* mem = operator new(sizeof(cUnk00ad8970));
    cUnk00ad8970* made;
    if (mem) {
        made = new (mem) cUnk00ad8970;
        *reinterpret_cast<uint32_t*>(made->unknown4) = 0;
        *reinterpret_cast<uint32_t*>(made->unknown8) = b;
    } else {
        made = 0;
    }
    Filter_ad89d0* filter = reinterpret_cast<Filter_ad89d0*>(made);
    filter->AddRef_ad89d0();
    uint32_t r = Slot17_ad88c0(a, OB_ADDR(filter));
    filter->Release_ad89d0();
    return r;
}
#endif

// FUNCTION: 0x009732c7
uint32_t cGZPersistResourceManager::Slot24_ad88c0()
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock20[0]));
    return mnFactoryCount;
}

// FUNCTION: 0x009732eb
bool cGZPersistResourceManager::Slot03_ad88c0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    uint32_t res = 0;
    bool found = false;
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != static_cast<Node_ad89d0*>(mpList88); node = node->mpNext) {
        if (found) {
            break;
        }
        Factory_ad89d0* fac = node->mpItem;
        if (res) {
            uint32_t old = res;
            res = 0;
            OB_PTR(Unk_ad89d0, old)->Release_ad89d0();
        }
        if (fac->Find7_ad89d0(a, OB_ADDR(&res))) {
            found = true;
        }
    }
    bool ok = true;
    if (!found) {
        if (res) {
            uint32_t old = res;
            res = 0;
            OB_PTR(Unk_ad89d0, old)->Release_ad89d0();
        }
        if (CreateAndSerialize(a, 0x456b8f1d, OB_ADDR(&res), d, e)) {
            AddResourceToCache(a, res);
        } else {
            ok = false;
        }
    }
    if (ok) {
        found = OB_PTR(Res_ad89d0, res)->Query_ad89d0(b, c);
    }
    if (res) {
        OB_PTR(Unk_ad89d0, res)->Release_ad89d0();
    }
    return found;
}

// FUNCTION: 0x009733c6
bool cGZPersistResourceManager::AddResourceToCache(uint32_t a, uint32_t b)
{
    bool done = false;
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != static_cast<Node_ad89d0*>(mpList88); node = node->mpNext) {
        if (done) {
            break;
        }
        Factory_ad89d0* fac = node->mpItem;
        if (fac->Has11_ad89d0(a)) {
            fac->Add8_ad89d0(a, b);
            done = true;
        }
    }
    return done;
}

// FUNCTION: 0x0097341b
bool cGZPersistResourceManager::Slot09_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    bool done = false;
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != static_cast<Node_ad89d0*>(mpList88); node = node->mpNext) {
        if (done) {
            break;
        }
        Factory_ad89d0* fac = node->mpItem;
        if (fac->Has10_ad89d0(a)) {
            done = fac->Remove9_ad89d0(a);
        }
    }
    return done;
}

// FUNCTION: 0x00973485
bool cGZPersistResourceManager::Slot10_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    bool found = false;
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != static_cast<Node_ad89d0*>(mpList88) && !found; node = node->mpNext) {
        if (node->mpItem->Has10_ad89d0(a)) {
            found = true;
        }
    }
    return found;
}

// FUNCTION: 0x009734dc
bool cGZPersistResourceManager::Slot41_ad88c0()
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock8c[0]));
    bool r = false;
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != static_cast<Node_ad89d0*>(mpList88); node = node->mpNext) {
        r |= node->mpItem->Gc15_ad89d0();
    }
    return r;
}

// FUNCTION: 0x00973526
void cGZPersistResourceManager::Slot42_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock8c[0]));
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != static_cast<Node_ad89d0*>(mpList88); node = node->mpNext) {
        node->mpItem->SetGc16_ad89d0(a);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097356d
bool cGZPersistResourceManager::Slot11_a93658(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    bool r = false;
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != static_cast<Node_ad89d0*>(mpList88); node = node->mpNext) {
        r |= node->mpItem->Cond14_ad89d0(a);
    }
    return r;
}
#endif

// FUNCTION: 0x009735b8
bool cGZPersistResourceManager::Slot43_ad88c0()
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    bool r = false;
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != static_cast<Node_ad89d0*>(mpList88); node = node->mpNext) {
        r |= node->mpItem->Force17_ad89d0();
    }
    return r;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097371f score 36
bool cGZPersistResourceManager::Slot30_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock50[0]));
    Iter_ad89d0 it = *reinterpret_cast<Iter_ad89d0*>(&mSegBegin[0]);
    Iter_ad89d0 end = *reinterpret_cast<Iter_ad89d0*>(&mSegEnd[0]);
    bool r = false;
    for (; it.mpCur != end.mpCur; it.Advance_ad89d0()) {
        if (OB_ADDR(*it.mpCur) == a) {
            r = true;
            break;
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097377f score 22
bool cGZPersistResourceManager::Slot32_ad88c0(uint32_t a, uint32_t b)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock50[0]));
    *OB_PTR(Seg_ad89d0*, b) = 0;
    Iter_ad89d0 it = *reinterpret_cast<Iter_ad89d0*>(&mSegBegin[0]);
    Iter_ad89d0 end = *reinterpret_cast<Iter_ad89d0*>(&mSegEnd[0]);
    bool r = false;
    for (; it.mpCur != end.mpCur; it.Advance_ad89d0()) {
        Seg_ad89d0* seg = *it.mpCur;
        if (seg->Has19_ad89d0(a)) {
            *OB_PTR(Seg_ad89d0*, b) = seg;
            seg->AddRef_ad89d0();
            r = true;
            break;
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009737fa score 22
bool cGZPersistResourceManager::Slot31_ad88c0(uint32_t a, uint32_t b)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock50[0]));
    *OB_PTR(Seg_ad89d0*, b) = 0;
    Iter_ad89d0 it = *reinterpret_cast<Iter_ad89d0*>(&mSegBegin[0]);
    Iter_ad89d0 end = *reinterpret_cast<Iter_ad89d0*>(&mSegEnd[0]);
    bool r = false;
    for (; it.mpCur != end.mpCur; it.Advance_ad89d0()) {
        Seg_ad89d0* seg = *it.mpCur;
        if (seg->GetId14_ad89d0() == a) {
            *OB_PTR(Seg_ad89d0*, b) = seg;
            seg->AddRef_ad89d0();
            r = true;
            break;
        }
    }
    return r;
}
#endif

// FUNCTION: 0x00973873
uint32_t cGZPersistResourceManager::Slot33_ad88c0()
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock50[0]));
    Iter_ad89d0* begin = reinterpret_cast<Iter_ad89d0*>(&mSegBegin[0]);
    return (begin + 1)->Diff_ad89d0(begin);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009738a2 score 24
uint32_t cGZPersistResourceManager::Slot36_ad88c0(uint32_t a, uint32_t b)
{
    Iter_ad89d0* begin = reinterpret_cast<Iter_ad89d0*>(&mSegBegin[0]);
    uint32_t total = (begin + 1)->Diff_ad89d0(begin);
    Seg_ad89d0** out = OB_PTR(Seg_ad89d0*, a);
    uint32_t* count = OB_PTR(uint32_t, b);
    if (out && *count) {
        uint32_t* p = count;
        if (total < *count) {
            p = &total;
        }
        uint32_t n = *p;
        *count = 0;
        Iter_ad89d0 it = *begin;
        while (*count < n) {
            out[*count] = *it.mpCur;
            out[*count]->AddRef_ad89d0();
            it.Advance_ad89d0();
            (*count)++;
        }
    }
    return total;
}
#endif

// FUNCTION: 0x0097391b
void cGZPersistResourceManager::Slot35_ad88c0(uint32_t a, uint32_t b)
{
    if (a != 0) {
        Iter_ad89d0 it = *reinterpret_cast<Iter_ad89d0*>(&mSegBegin[0]);
        Iter_ad89d0 end = *reinterpret_cast<Iter_ad89d0*>(&mSegEnd[0]);
        while (it.mpCur != end.mpCur) {
            Seg_ad89d0* seg = *it.mpCur;
            if (!OB_PTR(SegCallback_ad89d0, a)(seg, OB_PTR(void, b))) {
                break;
            }
            it.Advance_ad89d0();
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00973964 score 36
bool cGZPersistResourceManager::Slot14_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock50[0]));
    Iter_ad89d0 it = *reinterpret_cast<Iter_ad89d0*>(&mSegBegin[0]);
    Iter_ad89d0 end = *reinterpret_cast<Iter_ad89d0*>(&mSegEnd[0]);
    bool r = false;
    for (; it.mpCur != end.mpCur; it.Advance_ad89d0()) {
        if ((*it.mpCur)->Has19_ad89d0(a)) {
            r = true;
            break;
        }
    }
    return r;
}
#endif

// FUNCTION: 0x009739cb
uint32_t cGZPersistResourceManager::Slot17_ad88c0(uint32_t a, uint32_t b)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    uint32_t n = 0;
    KeyList_ad89d0* list = new KeyList_ad89d0;
    list->AddRef_ad89d0();
    *OB_PTR(KeyList_ad89d0*, a) = list;
    Iter_ad89d0 it = *reinterpret_cast<Iter_ad89d0*>(&mSegBegin[0]);
    Iter_ad89d0 end = *reinterpret_cast<Iter_ad89d0*>(&mSegEnd[0]);
    while (it.mpCur != end.mpCur) {
        n += (*it.mpCur)->Collect18_ad89d0(list, OB_PTR(void, b));
        it.Advance_ad89d0();
    }
    return n;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00973a57 score 22
bool cGZPersistResourceManager::Slot40_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    StratList_ad89d0* list = reinterpret_cast<StratList_ad89d0*>(&mpList88);
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != head; node = node->mpNext) {
        if (OB_ADDR(node->mpItem) == a) {
            ListIter_ad89d0 at;
            at.mpNode = node;
            ListIter_ad89d0 out;
            list->Erase_ad89d0(&out, at);
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009740f1 score 23
bool cGZPersistResourceManager::Slot39_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock80[0]));
    StratList_ad89d0* list = reinterpret_cast<StratList_ad89d0*>(&mpList88);
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != head; node = node->mpNext) {
        if (OB_ADDR(node->mpItem) == a) {
            return false;
        }
    }
    RefHolder_ad89d0 ref(OB_PTR(Unk_ad89d0, a));
    list->PushFront_ad89d0(&ref);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00973fd6 score 26
bool cGZPersistResourceManager::Slot20_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock20[0]));
    HTable_ad89d0* table = reinterpret_cast<HTable_ad89d0*>(reinterpret_cast<char*>(this) + 0x28);
    bool r = false;
    HNode_ad89d0* node = table->Find_ad89d0(&a);
    while (node) {
        r = true;
        node->mpItem->Release_ad89d0();
        HIter_ad89d0 at;
        at.mpNode = node;
        at.mpTable = table;
        table->Erase_ad89d0(at);
        node = table->Find_ad89d0(&a);
    }
    return r;
}
#endif

// FUNCTION: 0x00974042
bool cGZPersistResourceManager::Slot21_ad88c0(uint32_t a, uint32_t b)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock20[0]));
    bool r = false;
    HNode_ad89d0* node = reinterpret_cast<HTableMap_ad89d0*>(reinterpret_cast<char*>(this) + 0x3c)->Find_ad89d0(&a);
    if (node) {
        a = node->mnValue;
        HNode_ad89d0* f = reinterpret_cast<HTable_ad89d0*>(reinterpret_cast<char*>(this) + 0x28)->Find_ad89d0(&a);
        if (f) {
            Unk_ad89d0* fac = f->mpItem;
            *OB_PTR(Unk_ad89d0*, b) = fac;
            fac->Pad1_ad89d0();
            r = true;
        }
    }
    return r;
}

// FUNCTION: 0x0097409e
uint32_t cGZPersistResourceManager::Slot25_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock20[0]));
    uint32_t r = 0;
    if (a < mnFactoryCount) {
        HIter_ad89d0 it;
        reinterpret_cast<HTable_ad89d0*>(reinterpret_cast<char*>(this) + 0x28)->Begin_ad89d0(&it);
        for (uint32_t i = 0; i < a; i++) {
            it.Next_ad89d0();
        }
        r = OB_ADDR(it.mpNode->mpItem);
    }
    return r;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009742b7 score 51
bool cGZPersistResourceManager::Slot29_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock50[0]));
    Deque_ad89d0* deque = reinterpret_cast<Deque_ad89d0*>(&mSegBegin[0]);
    Iter_ad89d0 it = deque->mBegin;
    Iter_ad89d0 end = deque->mEnd;
    bool r = false;
    for (; it.mpCur != end.mpCur; it.Advance_ad89d0()) {
        if (OB_ADDR(*it.mpCur) == a) {
            OB_PTR(Unk_ad89d0, a)->Release_ad89d0();
            deque->Erase_ad89d0(it);
            r = true;
            break;
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097437b score 6
bool cGZPersistResourceManager::Slot27_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock50[0]));
    Seg_ad89d0* seg = OB_PTR(Seg_ad89d0, a);
    seg->AddRef_ad89d0();
    Slot29_ad88c0(OB_ADDR(seg));
    a = OB_ADDR(seg);
    reinterpret_cast<Deque_ad89d0*>(&mSegBegin[0])->PushFront_ad89d0(OB_PTR(Seg_ad89d0*, OB_ADDR(&a)));
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009743c1 score 6
bool cGZPersistResourceManager::Slot28_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock50[0]));
    Seg_ad89d0* seg = OB_PTR(Seg_ad89d0, a);
    seg->AddRef_ad89d0();
    Slot29_ad88c0(OB_ADDR(seg));
    a = OB_ADDR(seg);
    reinterpret_cast<Deque_ad89d0*>(&mSegBegin[0])->PushBack_ad89d0(OB_PTR(Seg_ad89d0*, OB_ADDR(&a)));
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00974407 score 8
bool cGZPersistResourceManager::Slot19_ad88c0(uint32_t a, uint32_t b, uint32_t c)
{
    bool r = false;
    if (c != 0) {
        OB_PTR(Unk_ad89d0, c)->Pad1_ad89d0();
    } else {
        Com_ad89d0* com = GZCOM();
        if (com) {
            com->Get3_ad89d0(a, 0xa56b8f17, OB_ADDR(&c));
        }
    }
    if (c != 0) {
        Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock20[0]));
        HIter_ad89d0 out;
        Pair_ad89d0 pair;
        pair.mnKey = a;
        pair.mnValue = c;
        reinterpret_cast<HTable_ad89d0*>(reinterpret_cast<char*>(this) + 0x28)->Insert_ad89d0(&out, &pair);
        pair.mnKey = b;
        pair.mnValue = a;
        reinterpret_cast<HTableMap_ad89d0*>(reinterpret_cast<char*>(this) + 0x3c)->Insert_ad89d0(&out, &pair);
        r = true;
    }
    return r;
}
#endif

// FUNCTION: 0x00892062
void Deque_ad89d0::PopBack_ad89d0()
{
    if (mEnd.mpCur != mEnd.mpFirst) {
        --mEnd.mpCur;
    } else {
        PopBackAux_ad89d0();
    }
}

// FUNCTION: 0x00974337
void Deque_ad89d0::PushBack_ad89d0(Seg_ad89d0* const* p)
{
    if (mEnd.mpCur != mEnd.mpLast - 1) {
        if (mEnd.mpCur) {
            *mEnd.mpCur = *p;
        }
        ++mEnd.mpCur;
    } else {
        PushBackAux_ad89d0(p);
    }
}

// FUNCTION: 0x00973602
Iter_ad89d0 Iter_ad89d0::Plus_ad89d0(uint32_t n)
{
    Iter_ad89d0 t = *this;
    t.AddAssign_ad89d0(n);
    return t;
}

// FUNCTION: 0x00973630
Seg_ad89d0** Iter_ad89d0::Index_ad89d0(uint32_t n)
{
    return Plus_ad89d0(n).mpCur;
}

// FUNCTION: 0x00973aad
void Iter_ad89d0::AdvanceFast_ad89d0()
{
    if (mpCur != mpLast - 1) {
        ++mpCur;
    } else {
        AdvanceSlow_ad89d0();
    }
}

// FUNCTION: 0x00973d88
uint32_t cGZPersistResourceManager::Slot34_ad88c0(uint32_t a)
{
    Guard_ad89d0 guard(reinterpret_cast<Lock_ad89d0*>(&mLock50[0]));
    Iter_ad89d0* begin = reinterpret_cast<Iter_ad89d0*>(&mSegBegin[0]);
    uint32_t r = 0;
    if (a < (begin + 1)->Diff_ad89d0(begin)) {
        r = OB_ADDR(*begin->Index_ad89d0(a));
    }
    return r;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00973eeb score 97
bool cGZPersistResourceManager::Slot04_ae1d24()
{
    Lock_ad89d0* lock80 = reinterpret_cast<Lock_ad89d0*>(&mLock80[0]);
    Lock_ad89d0* lock20 = reinterpret_cast<Lock_ad89d0*>(&mLock20[0]);
    Lock_ad89d0* lock50 = reinterpret_cast<Lock_ad89d0*>(&mLock50[0]);
    lock80->Enter_ad89d0();
    lock20->Enter_ad89d0();
    lock50->Enter_ad89d0();
    StratList_ad89d0* list = reinterpret_cast<StratList_ad89d0*>(&mpList88);
    Node_ad89d0* head = static_cast<Node_ad89d0*>(mpList88);
    for (Node_ad89d0* node = head->mpNext; node != static_cast<Node_ad89d0*>(mpList88); node = node->mpNext) {
        reinterpret_cast<Strat_ad89d0*>(node->mpItem)->Shutdown4_ad89d0();
    }
    list->Clear_ad89d0();
    lock80->Leave_ad89d0();
    HTable_ad89d0* table = reinterpret_cast<HTable_ad89d0*>(reinterpret_cast<char*>(this) + 0x28);
    HIter_ad89d0 hit;
    table->Begin_ad89d0(&hit);
    for (; hit.mpNode; hit.Next_ad89d0()) {
        Unk_ad89d0* item = hit.mpNode->mpItem;
        if (item) {
            item->Release_ad89d0();
        }
    }
    table->Clear_ad89d0();
    lock20->Leave_ad89d0();
    Deque_ad89d0* deque = reinterpret_cast<Deque_ad89d0*>(&mSegBegin[0]);
    Iter_ad89d0 it = deque->mBegin;
    Iter_ad89d0 end = deque->mEnd;
    for (; it.mpCur != end.mpCur; it.Advance_ad89d0()) {
        Unk_ad89d0* seg = reinterpret_cast<Unk_ad89d0*>(*it.mpCur);
        if (seg) {
            seg->Release_ad89d0();
        }
    }
    deque->Clear_ad89d0();
    lock50->Leave_ad89d0();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00973baa score 2
void Deque_ad89d0::ClearDraft_ad89d0()
{
    for (Seg_ad89d0*** p = mBegin.mpNode; p < mEnd.mpNode; ++p) {
        if (*p) {
            StlDelete_ad89d0(*p);
        }
    }
    if (mBegin.mpNode != mEnd.mpNode) {
        if (mEnd.mpFirst) {
            StlDelete_ad89d0(mEnd.mpFirst);
        }
    }
    mEnd = mBegin;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00973ac4 score 25
HIter_ad89d0* HTable_ad89d0::InsertEqualDraft_ad89d0(HIter_ad89d0* out, const Pair_ad89d0* p)
{
    HNode_ad89d0** buckets = mpBuckets;
    uint32_t index = p->mnKey % static_cast<uint32_t>(mpBucketsEnd - mpBuckets);
    HNode_ad89d0* first = buckets[index];
    for (HNode_ad89d0* cur = first; cur; cur = cur->mpNext) {
        if (cur->mnKey == p->mnKey) {
            HNode_ad89d0* made = NewNode_ad89d0(p);
            made->mpNext = cur->mpNext;
            cur->mpNext = made;
            ++mnCount;
            out->mpNode = made;
            out->mpTable = reinterpret_cast<HTable_ad89d0*>(this);
            return out;
        }
    }
    HNode_ad89d0* made = NewNode_ad89d0(p);
    made->mpNext = first;
    mpBuckets[index] = made;
    ++mnCount;
    out->mpNode = made;
    out->mpTable = reinterpret_cast<HTable_ad89d0*>(this);
    return out;
}
#endif

// FUNCTION: 0x0097420d
HIter_ad89d0* HTable_ad89d0::Insert_ad89d0(HIter_ad89d0* out, const Pair_ad89d0* p)
{
    Resize_ad89d0(mnCount + 1);
    InsertEqual_ad89d0(out, p);
    return out;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00973b37 score 25
HIter_ad89d0* HTableMap_ad89d0::InsertEqualDraft_ad89d0(HIter_ad89d0* out, const Pair_ad89d0* p)
{
    HNode_ad89d0** buckets = mpBuckets;
    uint32_t index = p->mnKey % static_cast<uint32_t>(mpBucketsEnd - mpBuckets);
    HNode_ad89d0* first = buckets[index];
    for (HNode_ad89d0* cur = first; cur; cur = cur->mpNext) {
        if (cur->mnKey == p->mnKey) {
            HNode_ad89d0* made = NewNode_ad89d0(p);
            made->mpNext = cur->mpNext;
            cur->mpNext = made;
            ++mnCount;
            out->mpNode = made;
            out->mpTable = reinterpret_cast<HTable_ad89d0*>(this);
            return out;
        }
    }
    HNode_ad89d0* made = NewNode_ad89d0(p);
    made->mpNext = first;
    mpBuckets[index] = made;
    ++mnCount;
    out->mpNode = made;
    out->mpTable = reinterpret_cast<HTable_ad89d0*>(this);
    return out;
}
#endif

// FUNCTION: 0x00974231
HIter_ad89d0* HTableMap_ad89d0::Insert_ad89d0(HIter_ad89d0* out, const Pair_ad89d0* p)
{
    Resize_ad89d0(mnCount + 1);
    InsertEqual_ad89d0(out, p);
    return out;
}

// FUNCTION: 0x00972c24
bool cGZPersistResourceManager::Slot13_ad88c0(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t rec = 0;
    uint32_t fac = 0;
    Seg_ad89d0* seg = OB_PTR(Seg_ad89d0, c);
    Res_ad89d0* res = OB_PTR(Res_ad89d0, a);
    Key_ad89d0 key;
    bool r;
    if (seg->Has19_ad89d0(OB_ADDR(res->GetKey_ad89d0(&key)))) {
        r = seg->Open21_ad89d0(OB_ADDR(res->GetKey_ad89d0(&key)), OB_ADDR(&rec), 3);
    } else {
        r = seg->Create22_ad89d0(b, OB_ADDR(&rec));
    }
    if (r) {
        if (reinterpret_cast<Self_ad89d0*>(this)->FindFactoryOf23_ad89d0(OB_ADDR(res), OB_ADDR(&fac))) {
            if (OB_PTR(Factory_ad89d0, fac)->Save6_ad89d0(OB_ADDR(res), rec)) {
                if (seg->Close23_ad89d0(OB_ADDR(&rec))) {
                    rec = 0;
                    r = true;
                }
            }
            OB_PTR(Unk_ad89d0, fac)->Release_ad89d0();
        }
    }
    if (rec) {
        seg->Abort25_ad89d0(OB_ADDR(&rec));
    }
    return r;
}
