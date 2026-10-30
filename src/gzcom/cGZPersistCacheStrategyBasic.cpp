#include "classes/cGZPersistCacheStrategyBasic.h"
#include <new>
#include "classes/cUnk00ad8970.h"

// A resource key: three words.
struct Key_ad9428 {
    uint32_t mnType;
    uint32_t mnGroup;
    uint32_t mnInstance;
};

// The lock objects embedded in the strategy (a vtable and one word); only the slots used here are named.
struct Lock_ad9428 {
    virtual void Pad0_ad9428();
    virtual void Enter_ad9428();
    virtual void Leave_ad9428();
};

// A scope guard over a lock: the constructor takes the lock, the destructor lets it go.
struct Guard_ad9428 {
    uint32_t mPad;
    Lock_ad9428* mpLock;

    // STUB: 0x0048c9f0
    Guard_ad9428(Lock_ad9428* lock);
    ~Guard_ad9428() { mpLock->Leave_ad9428(); }
};

// The cached resources, as far as the cache uses them.
struct Resource_ad9428 {
    virtual void Pad0_ad9428();
    virtual void AddRef_ad9428();
    virtual void Release_ad9428();
    virtual void GetKey_ad9428(Key_ad9428* key);
    virtual void SetKey_ad9428(const Key_ad9428* key);
    virtual void Pad5_ad9428();
    virtual void Pad6_ad9428();
    virtual void Pad7_ad9428();
    virtual void Pad8_ad9428();
    virtual void Pad9_ad9428();
    virtual void Pad10_ad9428();
    virtual uint32_t GetRefCount_ad9428();
};

// A filter over keys.
struct Filter_ad9428 {
    virtual void Pad0_ad9428();
    virtual void Pad1_ad9428();
    virtual void Release_ad9428();
    virtual bool IsKeyIncluded_ad9428(const Key_ad9428* key);
};

// A list collecting keys.
struct KeyList_ad9428 {
    virtual void Pad0_ad9428();
    virtual void Pad1_ad9428();
    virtual void Pad2_ad9428();
    virtual void Pad3_ad9428();
    virtual void Add_ad9428(const Key_ad9428* key);
};

// A node of the hash table: the chain link, the key and the resource at 0x10.
struct Node_ad9428 {
    uint32_t mPad[4];
    Resource_ad9428* mpResource;
};

struct Table_ad9428;

// The table's iterator: the node and the table.
struct Iter_ad9428 {
    Node_ad9428* mpNode;
    Table_ad9428* mpTable;
    Iter_ad9428() {}
    Iter_ad9428(Node_ad9428* node, Table_ad9428* table)
    {
        mpTable = table;
        mpNode = node;
    }
    // copied and assigned by the implicit members: a hand-written copy changes the matched code (load both, store both)

    // STUB: 0x0096f5b7
    void Next();
};

struct InsertResult_ad9428 {
    Iter_ad9428 mIter;
    uint8_t mbInserted;
};

struct Pair_ad9428 {
    Key_ad9428 mKey;
    Resource_ad9428* mpResource;
};

// The hash table of resources (five words).
struct Table_ad9428 {
    // STUB: 0x0097c081
    Iter_ad9428 Begin();
    // STUB: 0x0097c081
    void BeginInto(Iter_ad9428* out);
    // STUB: 0x0096f290
    Iter_ad9428 Find(const Key_ad9428* key);
    // STUB: 0x0096f290
    void FindInto(Iter_ad9428* out, const Key_ad9428* key);
    // STUB: 0x0097c221
    void Erase(Iter_ad9428 it);
    // STUB: 0x0097c1a2
    void Clear();
    // STUB: 0x0097c51a
    InsertResult_ad9428 Insert(const Pair_ad9428* pair);
};

// A reference-holding pointer to a filter: the constructor holds it, the destructor lets it go.
struct FilterRef_ad9428 {
    Filter_ad9428* mpFilter;

    // STUB: 0x0096e773
    FilterRef_ad9428(Filter_ad9428* filter);
};

inline Lock_ad9428* CacheLockOf_ad9428(uint32_t* p)
{
    return reinterpret_cast<Lock_ad9428*>(p);
}

inline Table_ad9428* TableOf_ad9428(uint32_t* p)
{
    return reinterpret_cast<Table_ad9428*>(p);
}

// FUNCTION: 0x0097be6c
bool cGZPersistCacheStrategyBasic::QueryInterface(uint32_t a, void* b)
{
    bool found;
    switch (a) {
    case 1:
    case 0x6bb923e4:
        *static_cast<cGZPersistCacheStrategyBasic**>(b) = this;
        AddRef();
        found = true;
        break;
    default:
        found = false;
        break;
    }
    return found;
}

// FUNCTION: 0x0097be8e
uint32_t cGZPersistCacheStrategyBasic::AddRef()
{
    Guard_ad9428 guard(CacheLockOf_ad9428(&mRefLock[0]));
    return mnRefCount++;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097beba score 2 (the vtable load of the lock is scheduled after the count store, the original loads it before)
uint32_t cGZPersistCacheStrategyBasic::Release()
{
    Lock_ad9428* lock = CacheLockOf_ad9428(&mRefLock[0]);
    lock->Enter_ad9428();
    if (mnRefCount > 1) {
        uint32_t n = mnRefCount - 1;
        mnRefCount = n;
        lock->Leave_ad9428();
        return n;
    } else {
        lock->Leave_ad9428();
        delete this;
        return 0;
    }
}
#endif

// FUNCTION: 0x0097bef6
bool cGZPersistCacheStrategyBasic::IsGarbageCollectionActive()
{
    Guard_ad9428 guard(CacheLockOf_ad9428(&mRefLock[0]));
    return mbGarbageCollectionActive;
}

// FUNCTION: 0x0097bf1c
void cGZPersistCacheStrategyBasic::SetGarbageCollectionActive(bool a)
{
    Guard_ad9428 guard(CacheLockOf_ad9428(&mRefLock[0]));
    mbGarbageCollectionActive = a;
}

// FUNCTION: 0x0097bf43
bool cGZPersistCacheStrategyBasic::OnIdle(uint32_t /*a*/)
{
    if (mbGarbageCollectionActive) {
        ++mnIdleCount;
        if (mnIdleCount > 0x80) {
            mnIdleCount = 0;
            GarbageCollect();
        }
    }
    return true;
}

// FUNCTION: 0x0097bf63
uint32_t cGZPersistCacheStrategyBasic::ForceGarbageCollection()
{
    uint32_t n = 0;
    do {
        if (!GarbageCollect()) {
            break;
        }
        ++n;
    } while (n < 8);
    return n > 0;
}

// FUNCTION: 0x0097bfac
uint32_t cGZPersistCacheStrategyBasic::CanCacheResource(void* a)
{
    Filter_ad9428* filter = static_cast<Filter_ad9428*>(mpKeyFilter);
    if (filter) {
        if (!filter->IsKeyIncluded_ad9428(static_cast<const Key_ad9428*>(a))) {
            return 0;
        }
    }
    return 1;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097bfca score 15 (the filter object has no constructor taking the type, so its words are stored by hand; the held reference lives in the dead argument slot in the original)
uint32_t cGZPersistCacheStrategyBasic::GetCachedResourceListForType(void* a, uint32_t b)
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
    FilterRef_ad9428 ref(reinterpret_cast<Filter_ad9428*>(made));
    Filter_ad9428* f = ref.mpFilter;
    uint32_t r = GetCachedResourceList(a, f);
    if (f) {
        f->Release_ad9428();
    }
    return r;
}
#endif

// FUNCTION: 0x0097c26d
void cGZPersistCacheStrategyBasic::Shutdown()
{
    Lock_ad9428* lock = CacheLockOf_ad9428(&mCacheLock[0]);
    lock->Enter_ad9428();
    FlushCache();
    Table_ad9428* table = TableOf_ad9428(&mTable[0]);
    Iter_ad9428 it;
    Iter_ad9428 first;
    table->BeginInto(&first);
    it = first;
    while (it.mpNode) {
        Resource_ad9428* res = it.mpNode->mpResource;
        if (res) {
            res->Release_ad9428();
        }
        it.Next();
    }
    table->Clear();
    lock->Leave_ad9428();
}

// FUNCTION: 0x0097c2d3
uint32_t cGZPersistCacheStrategyBasic::GetCachedResourceList(void* a, void* b)
{
    KeyList_ad9428* list = static_cast<KeyList_ad9428*>(a);
    Filter_ad9428* filter = static_cast<Filter_ad9428*>(b);
    Guard_ad9428 guard(CacheLockOf_ad9428(&mCacheLock[0]));
    uint32_t count = 0;
    Iter_ad9428 it = TableOf_ad9428(&mTable[0])->Begin();
    while (it.mpNode) {
        Key_ad9428 key;
        it.mpNode->mpResource->GetKey_ad9428(&key);
        Filter_ad9428* own = static_cast<Filter_ad9428*>(mpKeyFilter);
        if (!own || own->IsKeyIncluded_ad9428(&key)) {
            if (!filter || filter->IsKeyIncluded_ad9428(&key)) {
                if (list) {
                    list->Add_ad9428(&key);
                }
                ++count;
            }
        }
        it.Next();
    }
    return count;
}

// FUNCTION: 0x0097c36e
bool cGZPersistCacheStrategyBasic::GetResource(void* a, void* b)
{
    Guard_ad9428 guard(CacheLockOf_ad9428(&mCacheLock[0]));
    bool found = false;
    Iter_ad9428 it = TableOf_ad9428(&mTable[0])->Find(static_cast<const Key_ad9428*>(a));
    if (it.mpNode) {
        Resource_ad9428* res = it.mpNode->mpResource;
        *static_cast<Resource_ad9428**>(b) = res;
        res->AddRef_ad9428();
        found = true;
    }
    return found;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097c3bb score 17 (only the register choice between the table and the node)
bool cGZPersistCacheStrategyBasic::UncacheResource(void* a)
{
    Guard_ad9428 guard(CacheLockOf_ad9428(&mCacheLock[0]));
    bool found = false;
    Node_ad9428* node;
    Table_ad9428* table = TableOf_ad9428(&mTable[0]);
    Iter_ad9428 it;
    table->FindInto(&it, static_cast<const Key_ad9428*>(a));
    node = it.mpNode;
    if (node) {
        node->mpResource->Release_ad9428();
        table->Erase(Iter_ad9428(node, it.mpTable));
        found = true;
    }
    return found;
}
#endif

// FUNCTION: 0x0097c41a
bool cGZPersistCacheStrategyBasic::HasCachedResource(void* a)
{
    Iter_ad9428 it;
    {
        Guard_ad9428 guard(CacheLockOf_ad9428(&mCacheLock[0]));
        TableOf_ad9428(&mTable[0])->FindInto(&it, static_cast<const Key_ad9428*>(a));
    }
    return it.mpNode ? true : false;
}

// FUNCTION: 0x0097c452
void cGZPersistCacheStrategyBasic::FlushCache()
{
    Table_ad9428* table = TableOf_ad9428(&mTable[0]);
    Iter_ad9428 it = table->Begin();
    while (it.mpNode) {
        Resource_ad9428* res = it.mpNode->mpResource;
        if (res) {
            res->Release_ad9428();
        }
        it.Next();
    }
    table->Clear();
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097c48f score 40 (the node and the resource swap registers)
bool cGZPersistCacheStrategyBasic::GarbageCollect()
{
    Guard_ad9428 guard(CacheLockOf_ad9428(&mCacheLock[0]));
    uint32_t freed = 0;
    Table_ad9428* table = TableOf_ad9428(&mTable[0]);
    Iter_ad9428 it = table->Begin();
    while (it.mpNode) {
        Node_ad9428* node = it.mpNode;
        Resource_ad9428* res = node->mpResource;
        if (res) {
            if (res->GetRefCount_ad9428() > 1) {
                it.Next();
                continue;
            }
            ++freed;
            res->Release_ad9428();
            node->mpResource = 0;
        }
        Iter_ad9428 old(it);
        it.Next();
        table->Erase(old);
    }
    return freed != 0;
}
#endif

// FUNCTION: 0x0097c595
bool cGZPersistCacheStrategyBasic::CacheResource(void* a, void* b)
{
    Guard_ad9428 guard(CacheLockOf_ad9428(&mCacheLock[0]));
    Table_ad9428* table = TableOf_ad9428(&mTable[0]);
    const Key_ad9428* key = static_cast<const Key_ad9428*>(a);
    bool added = false;
    bool missing;
    {
        Iter_ad9428 found = table->Find(key);
        missing = found.mpNode == 0;
    }
    if (missing) {
        Resource_ad9428* res = static_cast<Resource_ad9428*>(b);
        res->AddRef_ad9428();
        res->SetKey_ad9428(key);
        Pair_ad9428 pair;
        pair.mKey.mnType = key->mnType;
        pair.mKey.mnGroup = key->mnGroup;
        pair.mKey.mnInstance = key->mnInstance;
        pair.mpResource = res;
        table->Insert(&pair);
        added = true;
    }
    return added;
}
