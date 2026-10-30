#include <stddef.h>
#include <new>
#include "classes/cGZSndMgr.h"

// A lock and its guard (the guard's destructor leaves the lock through slot 2).
struct Lock_ad7398 {
    virtual void Pad0_ad7398();
    virtual void Enter_ad7398();
    virtual void Leave_ad7398();
};

struct Guard_ad7398 {
    uint32_t mPad;
    Lock_ad7398* mpLock;

    // STUB: 0x008749a9
    Guard_ad7398(Lock_ad7398* lock);
    ~Guard_ad7398() { mpLock->Leave_ad7398(); }
};

// A node of a list or of a hash table's element list: next, previous, then the item (value at 8).
struct Node_ad7398 {
    Node_ad7398* mpNext;
    Node_ad7398* mpPrev;
    void* mpItem;
    uint32_t mExtra[3];
};

// An iterator over a hash table: the node and the table.
struct Iter_ad7398 {
    Node_ad7398* mpNode;
    void* mpTable;
};

struct TreeNode_ad7398 {
    uint32_t mColor;
    TreeNode_ad7398* mpParent;
    TreeNode_ad7398* mpLeft;
    TreeNode_ad7398* mpRight;
    uint32_t mKey;
    void* mpValue;
};

// STUB: 0x0040d4c0
TreeNode_ad7398* Fn0040d4c0(TreeNode_ad7398* node);

struct Tree_ad7398 {
    TreeNode_ad7398* mpHead;

    // STUB: 0x00968d5f
    void Clear_ad7398();
    // STUB: 0x0098129c
    TreeNode_ad7398* Find_ad7398(const uint32_t* key);
    // STUB: 0x00968d88
    void Erase_ad7398(TreeNode_ad7398* it);
};

struct List_ad7398 {
    Node_ad7398* mpHead;

    // STUB: 0x00968c53
    void Erase_ad7398(Node_ad7398* it, const void* key);
};

struct SndMap_ad7398 {
    Node_ad7398* mpHead;
    uint32_t mBuckets[3];
    uint32_t mnSize;

    // STUB: 0x00968cd9
    Node_ad7398* Find_ad7398(const uint32_t* key);
    // STUB: 0x0087a651
    void Erase_ad7398(Iter_ad7398 it);
    // STUB: 0x00969127
    void Next_ad7398(Iter_ad7398* it);
    // STUB: 0x0097c081
    void Begin_ad7398(Iter_ad7398* out);
};

// A smart pointer built from a raw pointer (0x0096e773), copied from another (0x00966956) or from a slot (0x004f20c0).
struct Ref_ad7398 {
    Lock_ad7398* mp;

    // STUB: 0x0096e773
    Ref_ad7398(void* p);
    ~Ref_ad7398()
    {
        if (mp) {
            mp->Leave_ad7398();
        }
    }
};

// What the sound system and the resource manager answer through (only the used slots).
struct Sys_ad7398 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual bool Get3_ad7398(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
};

struct Str_ad7398 {
    virtual void Pad0_ad7398();
    virtual void Pad1_ad7398();
    virtual void Pad2_ad7398();
    virtual void Pad3_ad7398();
    virtual void Pad4_ad7398();
    virtual uint32_t Hash5_ad7398(uint32_t flag);
};

// STUB: 0x00932f76
uint32_t Fn00932f76(uint32_t value);

// A sound.
struct Snd_ad7398 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad3_ad7398();
    virtual void Pad4_ad7398();
    virtual void Pad5_ad7398();
    virtual void Play6_ad7398(uint32_t a, uint32_t b, uint32_t c);
    virtual bool Check7_ad7398();
};

// A creator (sound or data source): slot 0 is the creating call.
struct Creator_ad7398 {
    virtual bool Create0_ad7398(uint32_t a, uint32_t b);
};

struct SrcCreator_ad7398 {
    virtual bool Create0_ad7398(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
};


// ---- batch 2 ----
struct SndSys_ad7398 {
    virtual void Pad0_ad7398();
    virtual void Pad1_ad7398();
    virtual void Pad2_ad7398();
    virtual void Pad3_ad7398();
    virtual void Pad4_ad7398();
    virtual void Pad5_ad7398();
    virtual void Pad6_ad7398();
    virtual void Pad7_ad7398();
    virtual void Pad8_ad7398();
    virtual void Pad9_ad7398();
    virtual void Pad10_ad7398();
    virtual void Pad11_ad7398();
    virtual void Pad12_ad7398();
    virtual void Pad13_ad7398();
    virtual void Pad14_ad7398();
    virtual void Pad15_ad7398();
    virtual void Pad16_ad7398();
    virtual void Pad17_ad7398();
    virtual void Pad18_ad7398();
    virtual void Pad19_ad7398();
    virtual void Pad20_ad7398();
    virtual void Pad21_ad7398();
    virtual void Pad22_ad7398();
    virtual void Pad23_ad7398();
    virtual void Pad24_ad7398();
    virtual void Pad25_ad7398();
    virtual void Pad26_ad7398();
    virtual void Pad27_ad7398();
    virtual void Pad28_ad7398();
    virtual void Pad29_ad7398();
    virtual void Register30_ad7398(void* a, uint32_t b);
    virtual void Pad31_ad7398();
    virtual void Pad32_ad7398();
    virtual void Pad33_ad7398();
    virtual void Pad34_ad7398();
    virtual void Pad35_ad7398();
    virtual void Pad36_ad7398();
    virtual void Pad37_ad7398();
    virtual uint32_t Ready38_ad7398();
};

struct TreeObj_ad7398 {
    TreeNode_ad7398* mpHead;
    uint32_t mnSize;

    // STUB: 0x0046f820
    void EraseSubtree_ad7398(TreeNode_ad7398* node);
    void Clear_ad7398();
};

// FUNCTION: 0x00968a9d
bool cGZSndMgr::QueryInterface(uint32_t riid, void** out)
{
    void** ppv = out;
    if (riid == 0x3af85bb7) {
        if (!ppv) {
            return false;
        }
        *ppv = static_cast<cUnk00ad7270*>(this);
        AddRef();
        return true;
    }
    return cRZSystemService::QueryInterface(riid, ppv);
}

// FUNCTION: 0x00968ad1
unsigned int cGZSndMgr::Release()
{
    if (refCount == 1) {
        Slot04_ae1d24();
    }
    return cRZSystemService::Release();
}

#ifdef OB_DRAFTS
// CLOSE: 0x00968ae7 score 1
void cGZSndMgr::Slot17_ad7270(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t id = Fn00932f76(OB_PTR(Str_ad7398, a)->Hash5_ad7398(0)) | 0xff000000;
    Slot18_ad7270(id, b, c, d, e);
}
#endif

// FUNCTION: 0x00968b1d
void cGZSndMgr::Slot19_ad7270(uint32_t a)
{
    Slot20_ad7270(a, field30);
}

// FUNCTION: 0x00968b2c
void cGZSndMgr::Slot21_ad7270(uint32_t a)
{
    Slot22_ad7270(a, field30);
}

// FUNCTION: 0x00968b76
bool cGZSndMgr::Slot09_ad7270(uint32_t a)
{
    *OB_PTR(uint32_t, a) = fielda0;
    return true;
}

// FUNCTION: 0x00968b96
bool cGZSndMgr::Slot11_ad7270(uint32_t a)
{
    *OB_PTR(uint32_t, a) = fielda4;
    return true;
}

// FUNCTION: 0x00968c18
bool cGZSndMgr::Slot03_ad7270(uint32_t a, uint32_t b, uint32_t c)
{
    Sys_ad7398* mgr = static_cast<Sys_ad7398*>(mpPersistMgr);
    if (mgr) {
        return mgr->Get3_ad7398(a, b, c, 0, 0);
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00969710 score 9
void cGZSndMgr::Slot13_ad7270(uint32_t a)
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    SndMap_ad7398* map = reinterpret_cast<SndMap_ad7398*>(&mSoundMap);
    Node_ad7398* node = map->Find_ad7398(&a);
    if (node) {
        Iter_ad7398 it;
        it.mpNode = node;
        it.mpTable = map;
        map->Erase_ad7398(it);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096958d score 6
void cGZSndMgr::Slot30_ad7270(uint32_t a)
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    Tree_ad7398* tree = reinterpret_cast<Tree_ad7398*>(&mSourceMap);
    TreeNode_ad7398* node = tree->Find_ad7398(&a);
    if (node != tree->mpHead) {
        tree->Erase_ad7398(node);
    }
}
#endif

// FUNCTION: 0x009692fc
uint32_t cGZSndMgr::Slot06_ad7270(uint32_t a)
{
    uint32_t result;
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    Node_ad7398* node = reinterpret_cast<SndMap_ad7398*>(&mSystemSndMap)->Find_ad7398(&a);
    if (node) {
        result = OB_ADDR(node->mpItem);
    } else {
        result = 0;
    }
    return result;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00968d08 score 19
bool cGZSndMgr::Slot16_ad7270(uint32_t a)
{
    bool removed = false;
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    ++mnCreatorIter;
    List_ad7398* list = reinterpret_cast<List_ad7398*>(&mCreatorList);
    Node_ad7398* head = list->mpHead;
    Node_ad7398* node = head->mpNext;
    while (node != head) {
        if (OB_ADDR(node->mpItem) == a) {
            list->Erase_ad7398(node, &a);
            removed = true;
            break;
        }
        node = node->mpNext;
    }
    --mnCreatorIter;
    return removed;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00968f4f score 9
bool cGZSndMgr::Slot27_ad7270(uint32_t a)
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    bool removed = false;
    ++mnSourceCreatorIter;
    Tree_ad7398* tree = reinterpret_cast<Tree_ad7398*>(&mSourceCreatorList);
    TreeNode_ad7398* head = tree->mpHead;
    for (TreeNode_ad7398* node = head->mpLeft; node != head; node = Fn0040d4c0(node)) {
        if (OB_ADDR(node->mpValue) == a) {
            tree->Erase_ad7398(node);
            removed = true;
            break;
        }
    }
    --mnSourceCreatorIter;
    return removed;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00968fb0 score 6
bool cGZSndMgr::Slot26_ad7270(uint32_t a)
{
    bool found = false;
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    ++mnSourceCreatorIter;
    Tree_ad7398* tree = reinterpret_cast<Tree_ad7398*>(&mSourceCreatorList);
    TreeNode_ad7398* node = tree->Find_ad7398(&a);
    if (node != tree->mpHead) {
        found = true;
        tree->Erase_ad7398(node);
    }
    --mnSourceCreatorIter;
    return found;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00968ffe score 2
bool cGZSndMgr::Slot28_ad7270(uint32_t a, uint32_t b, uint32_t c)
{
    bool ok;
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    ++mnSourceCreatorIter;
    int32_t saved = mnSourceCreatorIter;
    Tree_ad7398* tree = reinterpret_cast<Tree_ad7398*>(&mSourceCreatorList);
    TreeNode_ad7398* node = tree->Find_ad7398(&a);
    --saved;
    mnSourceCreatorIter = saved;
    if (node == tree->mpHead) {
        ok = false;
    } else {
        ok = static_cast<Creator_ad7398*>(node->mpValue)->Create0_ad7398(b, c);
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00969055 score 23
bool cGZSndMgr::Slot24_ad7270(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    bool ok = false;
    {
        Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
        Tree_ad7398* tree = reinterpret_cast<Tree_ad7398*>(&mSourceMap);
        TreeNode_ad7398* node = tree->Find_ad7398(&a);
        if (node != tree->mpHead) {
            Creator_ad7398* src = static_cast<Creator_ad7398*>(node->mpValue);
            if (src) {
                ok = src->Create0_ad7398(d, e);
            }
            return ok;
        }
    }
    Guard_ad7398 guard2(static_cast<Lock_ad7398*>(mpLock));
    TreeNode_ad7398* head2 = reinterpret_cast<Tree_ad7398*>(&mSourceCreatorList)->mpHead;
    ++mnSourceCreatorIter;
    for (TreeNode_ad7398* node = head2->mpLeft; node != head2; node = Fn0040d4c0(node)) {
        ok = static_cast<SrcCreator_ad7398*>(node->mpValue)->Create0_ad7398(a, b, c, d, e);
        if (ok) {
            break;
        }
    }
    --mnSourceCreatorIter;
    return ok;
}
#endif

// Smart pointers: built from a raw pointer in place (0x004f20c0).
struct RefA_ad7398 {
    Snd_ad7398* mp;

    // STUB: 0x004f20c0
    RefA_ad7398(Snd_ad7398* p);
    ~RefA_ad7398()
    {
        if (mp) {
            mp->Release();
        }
    }
};

// What the system hands out for the persistent resource manager (0x004496c0, destroyed by 0x004495c0).
struct PersistPtr_ad7398 {
    void* mp;

    // STUB: 0x004496c0
    PersistPtr_ad7398();
    // STUB: 0x004495c0
    ~PersistPtr_ad7398();
};

struct AutoAssign_ad7398 {
    void* mp;

    // STUB: 0x005447b0
    void Assign_ad7398(void* p);
};

struct Unk_ad7398 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

// STUB: 0x00913c9e
void* Fn00913c9e();

struct ListOps_ad7398 {
    Node_ad7398* mpHead;

    // STUB: 0x009677e6
    void Clear_ad7398();
    // STUB: 0x0090dbcd
    void PushBackA_ad7398(const RefA_ad7398& r);
    // STUB: 0x009690f4
    void PushBack_ad7398(const Ref_ad7398& r);
    // STUB: 0x0090daae
    void PopFront_ad7398();
};

// STUB: 0x0097c1a2
void Fn0097c1a2(void* map);
// STUB: 0x00879ecc
void Fn00879ecc(void* map);

#ifdef OB_DRAFTS
// CLOSE: 0x00968ba7 score 19
bool cGZSndMgr::Slot03_ae1d24()
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    bool ok = false;
    if (!mbInitialized) {
        mbInitialized = true;
        reinterpret_cast<AutoAssign_ad7398*>(&mpSndSys)->Assign_ad7398(Fn00913c9e());
        if (mpSndSys == 0) {
            return false;
        }
        static_cast<SndSys_ad7398*>(mpSndSys)->Register30_ad7398(static_cast<cUnk00a943c0*>(this), 0xfa);
        PersistPtr_ad7398 persist;
        reinterpret_cast<AutoAssign_ad7398*>(&mpPersistMgr)->Assign_ad7398(persist.mp);
    }
    ok = true;
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00968f11 score 4
void cGZSndMgr::Slot13_ad3e48(uint32_t a)
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpUpdateLock));
    ListOps_ad7398* list = reinterpret_cast<ListOps_ad7398*>(&mSystemSndMap);
    if (list->mpHead->mpNext != list->mpHead) {
        if (!static_cast<Snd_ad7398*>(list->mpHead->mpNext->mpItem)->Check7_ad7398()) {
            list->PopFront_ad7398();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00969335 score 13
bool cGZSndMgr::Slot15_ad7270(uint32_t a)
{
    Unk_ad7398* p = OB_PTR(Unk_ad7398, a);
    if (!p) {
        return false;
    }
    Unk_ad7398* q = 0;
    if (!p->QueryInterface(0x3af9866f, reinterpret_cast<void**>(&q))) {
        if (q) {
            q->Release();
        }
        return false;
    }
    Slot16_ad7270(OB_ADDR(p));
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    ++mnCreatorIter;
    {
        Ref_ad7398 ref(p);
        reinterpret_cast<ListOps_ad7398*>(&mCreatorList)->PushBack_ad7398(ref);
    }
    --mnCreatorIter;
    if (q) {
        q->Release();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009693c0 score 47
bool cGZSndMgr::Slot18_ad7270(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    bool ok = false;
    if (static_cast<SndSys_ad7398*>(mpSndSys)->Ready38_ad7398() == 0) {
        return false;
    }
    {
        Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
        Node_ad7398* node = reinterpret_cast<SndMap_ad7398*>(&mSoundMap)->Find_ad7398(&a);
        if (node) {
            Creator_ad7398* snd = static_cast<Creator_ad7398*>(node->mpItem);
            if (!snd) {
                ok = false;
            } else {
                ok = snd->Create0_ad7398(d, e);
            }
            return ok;
        }
    }
    Guard_ad7398 guard2(static_cast<Lock_ad7398*>(mpLock));
    Node_ad7398* head = reinterpret_cast<ListOps_ad7398*>(&mCreatorList)->mpHead;
    ++mnCreatorIter;
    for (Node_ad7398* node = head->mpNext; node != head; node = node->mpNext) {
        ok = static_cast<SrcCreator_ad7398*>(node->mpItem)->Create0_ad7398(a, b, c, d, e);
        if (ok) {
            break;
        }
    }
    --mnCreatorIter;
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00969475 score 3
bool cGZSndMgr::Slot23_ad7270(uint32_t a)
{
    RefA_ad7398 ref(OB_PTR(Snd_ad7398, a));
    reinterpret_cast<ListOps_ad7398*>(&mAutoPlayList)->PushBackA_ad7398(ref);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009694a2 score 3
void cGZSndMgr::Slot20_ad7270(uint32_t a, uint32_t b)
{
    Snd_ad7398* snd = 0;
    {
        Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
        ++mnSoundIter;
        int32_t n = mnSoundIter;
        Node_ad7398* node = reinterpret_cast<SndMap_ad7398*>(&mSoundMap)->Find_ad7398(&a);
        --n;
        mnSoundIter = n;
        if (node) {
            snd = static_cast<Snd_ad7398*>(node->mpItem);
            snd->AddRef();
            Slot23_ad7270(OB_ADDR(snd));
        } else {
            if (!Slot18_ad7270(a, 0, 0, 0x206077d2, OB_ADDR(&snd))) {
                return;
            }
        }
    }
    snd->Release();
    snd->Play6_ad7398(b, 0, 1);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00969536 score 13
void cGZSndMgr::Slot22_ad7270(uint32_t a, uint32_t b)
{
    uint32_t id = 0;
    bool found;
    {
        Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
        Node_ad7398* node = reinterpret_cast<SndMap_ad7398*>(&mSystemSndMap)->Find_ad7398(&a);
        found = node != 0;
        if (found) {
            id = OB_ADDR(node->mpItem);
        }
    }
    Slot20_ad7270(found ? id : 0, b);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009695cb score 7
void cGZSndMgr::Slot31_ad7270(uint32_t a)
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    ++mnSourceIter;
    Tree_ad7398* tree = reinterpret_cast<Tree_ad7398*>(&mSourceMap);
    TreeNode_ad7398* head = tree->mpHead;
    for (TreeNode_ad7398* node = head->mpLeft; node != head; node = Fn0040d4c0(node)) {
        if (OB_ADDR(node->mpValue) == a) {
            tree->Erase_ad7398(node);
            break;
        }
    }
    --mnSourceIter;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096966c score 28
bool cGZSndMgr::Slot04_ae1d24()
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    ListOps_ad7398* autoplay = reinterpret_cast<ListOps_ad7398*>(&mAutoPlayList);
    Node_ad7398* end = autoplay->mpHead;
    for (Node_ad7398* n = end->mpNext; n != end; n = n->mpNext) {
    }
    ++mnAutoPlayIter;
    autoplay->Clear_ad7398();
    --mnAutoPlayIter;
    Fn0097c1a2(&mSystemSndMap);
    ++mnSoundIter;
    Fn00879ecc(&mSoundMap);
    --mnSoundIter;
    ++mnCreatorIter;
    reinterpret_cast<ListOps_ad7398*>(&mCreatorList)->Clear_ad7398();
    --mnCreatorIter;
    int32_t* iter = &mnSourceCreatorIter;
    ++*iter;
    reinterpret_cast<Tree_ad7398*>(&mSourceCreatorList)->Clear_ad7398();
    --*iter;
    if (mnPending != 0) {
        TreeNode_ad7398* head = reinterpret_cast<Tree_ad7398*>(&mPendingMap)->mpHead;
        for (TreeNode_ad7398* n = head->mpLeft; n != head; n = Fn0040d4c0(n)) {
        }
        reinterpret_cast<TreeObj_ad7398*>(&mPendingMap)->Clear_ad7398();
    }
    mbInitialized = false;
    return true;
}
#endif

// ---- batch 3 ----
// A smart pointer copied from another (0x00966956).
struct RefC_ad7398 {
    Lock_ad7398* mp;

    // STUB: 0x00966956
    RefC_ad7398(void* other);
    ~RefC_ad7398()
    {
        if (mp) {
            mp->Leave_ad7398();
        }
    }
};

struct SndPair_ad7398 {
    uint32_t mKey;
    RefC_ad7398 mValue;
    SndPair_ad7398(uint32_t k, void* other) : mKey(k), mValue(other) {}
};

struct IdPair_ad7398 {
    uint32_t mKey;
    uint32_t mValue;
};

struct SndMap2_ad7398 {
    Node_ad7398* mpHead;

    // STUB: 0x00968cd9
    Node_ad7398* Find_ad7398(const uint32_t* key);
    // STUB: 0x0092dc3a
    void Erase_ad7398(Iter_ad7398 it);
    // STUB: 0x0092fdd8
    void Insert_ad7398(void* out, const IdPair_ad7398* pair);
    // STUB: 0x0087a66f
    void InsertSnd_ad7398(void* out, const SndPair_ad7398* pair);
    // STUB: 0x0097c081
    void Begin_ad7398(Iter_ad7398* out);
    // STUB: 0x0087a651
    void EraseSnd_ad7398(Iter_ad7398 it);
};

struct TreeIns_ad7398 {
    TreeNode_ad7398* mpHead;

    // STUB: 0x0098129c
    TreeNode_ad7398* Find_ad7398(const uint32_t* key);
    // STUB: 0x0096a233
    void Insert_ad7398(void* out, const void* pair);
    // STUB: 0x0096982e
    void* Index_ad7398(const uint32_t* key, const Ref_ad7398* ref);
};

struct Slot_ad7398 {
    // STUB: 0x00969fea
    void Fn00969fea();
};

// STUB: 0x00969127
void Fn00969127(Iter_ad7398* it);

#ifdef OB_DRAFTS
// CLOSE: 0x009697b7 score 4
void cGZSndMgr::Slot29_ad7270(uint32_t a, uint32_t b)
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    TreeIns_ad7398* tree = reinterpret_cast<TreeIns_ad7398*>(&mSourceMap);
    if (tree->Find_ad7398(&b) == tree->mpHead) {
        Ref_ad7398 ref(OB_PTR(void, a));
        SndPair_ad7398 pair(b, &ref);
        uint32_t out[6];
        tree->Insert_ad7398(out, &pair);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096995c score 13
void cGZSndMgr::Slot07_ad7270(uint32_t a, uint32_t b)
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    SndMap2_ad7398* map = reinterpret_cast<SndMap2_ad7398*>(&mSystemSndMap);
    Node_ad7398* node = map->Find_ad7398(&a);
    if (node) {
        Iter_ad7398 it;
        it.mpNode = node;
        it.mpTable = map;
        map->Erase_ad7398(it);
    }
    IdPair_ad7398 pair;
    pair.mKey = a;
    pair.mValue = b;
    uint32_t out[7];
    map->Insert_ad7398(out, &pair);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009699ba score 4
void cGZSndMgr::Slot12_ad7270(uint32_t a, uint32_t b)
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    SndMap2_ad7398* map = reinterpret_cast<SndMap2_ad7398*>(&mSoundMap);
    if (map->Find_ad7398(&b) == 0) {
        RefA_ad7398 ref(OB_PTR(Snd_ad7398, a));
        SndPair_ad7398 pair(b, &ref);
        uint32_t out[7];
        map->InsertSnd_ad7398(out, &pair);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00969a31 score 7
bool cGZSndMgr::Slot25_ad7270(uint32_t a, uint32_t b)
{
    Unk_ad7398* p = OB_PTR(Unk_ad7398, a);
    if (!p) {
        return false;
    }
    Unk_ad7398* q = 0;
    if (!p->QueryInterface(0x9b75709e, reinterpret_cast<void**>(&q))) {
        return false;
    }
    q->Release();
    Slot26_ad7270(b);
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    ++mnSourceCreatorIter;
    Ref_ad7398 ref(p);
    static_cast<Slot_ad7398*>(reinterpret_cast<TreeIns_ad7398*>(&mSourceCreatorList)->Index_ad7398(&b, &ref))->Fn00969fea();
    --mnSourceCreatorIter;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00969752 score 24
void cGZSndMgr::Slot14_ad7270(uint32_t a)
{
    Guard_ad7398 guard(static_cast<Lock_ad7398*>(mpLock));
    ++mnSoundIter;
    SndMap2_ad7398* map = reinterpret_cast<SndMap2_ad7398*>(&mSoundMap);
    Iter_ad7398 it;
    map->Begin_ad7398(&it);
    while (it.mpNode) {
        if (OB_ADDR(it.mpNode->mpItem) == a) {
            map->EraseSnd_ad7398(it);
            break;
        }
        Fn00969127(&it);
    }
    --mnSoundIter;
}
#endif

// ---- helpers: the tree and the hash table of the manager ----
struct HNode_ad7398 {
    HNode_ad7398* mpNext;
    uint32_t mKey;
    void* mpValue;
};

struct HOut_ad7398 {
    HNode_ad7398* mpNode;
    void* mpTable;
    bool mbNew;
};

struct HashT_ad7398 {
    uint32_t mPad0;
    HNode_ad7398** mpBegin;
    HNode_ad7398** mpEnd;
    uint32_t mPad3;
    uint32_t mnSize;

    // STUB: 0x00879886
    HNode_ad7398* NewNode_ad7398(const void* pair);
    // STUB: 0x009978af
    void Resize_ad7398(uint32_t n);
    // STUB: 0x00968ef3
    void FreeNode_ad7398(HNode_ad7398* node);
    // STUB: 0x00969166
    void Erase_ad7398(Iter_ad7398* it);
    // STUB: 0x0087999f
    HOut_ad7398* Fn0087999f(HOut_ad7398* out, const uint32_t* pair);
    HOut_ad7398* Fn0087a66f(HOut_ad7398* out, const uint32_t* pair);
    void Fn0087a651(HNode_ad7398* node, void* table);
    // STUB: 0x00969166
    void Fn00969166(Iter_ad7398* it);
};

// STUB: 0x009491ff
struct KeyDtor_ad7398 {
    // STUB: 0x009491ff
    void Destroy_ad7398(uint32_t flag);
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

struct TreeC_ad7398 {
    TreeNode_ad7398* mpHead;
    uint32_t mnSize;

    void EraseSubtree_ad7398(TreeNode_ad7398* node);
    void Clear_ad7398();
};

// FUNCTION: 0x00968c7f
void TreeC_ad7398::EraseSubtree_ad7398(TreeNode_ad7398* node)
{
    while (node) {
        EraseSubtree_ad7398(node->mpRight);
        TreeNode_ad7398* left = node->mpLeft;
        reinterpret_cast<KeyDtor_ad7398*>(&node->mKey)->Destroy_ad7398(0);
        Fn0090cf63(node);
        node = left;
    }
}

// FUNCTION: 0x00968d5f
void TreeC_ad7398::Clear_ad7398()
{
    if (mnSize != 0) {
        EraseSubtree_ad7398(mpHead->mpParent);
        mpHead->mpLeft = mpHead;
        mpHead->mpParent = 0;
        mpHead->mpRight = mpHead;
        mnSize = 0;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0046f8d0 score 15
void TreeObj_ad7398::Clear_ad7398()
{
    if (mnSize != 0) {
        EraseSubtree_ad7398(mpHead->mpParent);
        mpHead->mpLeft = mpHead;
        mpHead->mpParent = 0;
        mpHead->mpRight = mpHead;
        mnSize = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0087999f score 40
HOut_ad7398* HashT_ad7398::Fn0087999f(HOut_ad7398* out, const uint32_t* pair)
{
    uint32_t key = pair[0];
    uint32_t n = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t index = key % n;
    HNode_ad7398* first = mpBegin[index];
    for (HNode_ad7398* node = first; node; node = node->mpNext) {
        if (node->mKey == key) {
            out->mpNode = node;
            out->mpTable = this;
            out->mbNew = false;
            return out;
        }
    }
    HNode_ad7398* made = NewNode_ad7398(pair);
    made->mpNext = first;
    mpBegin[index] = made;
    ++mnSize;
    out->mpNode = made;
    out->mpTable = this;
    out->mbNew = true;
    return out;
}
#endif

// FUNCTION: 0x0087a66f
HOut_ad7398* HashT_ad7398::Fn0087a66f(HOut_ad7398* out, const uint32_t* pair)
{
    Resize_ad7398(mnSize + 1);
    Fn0087999f(out, pair);
    return out;
}

// FUNCTION: 0x0087a651
void HashT_ad7398::Fn0087a651(HNode_ad7398* node, void* table)
{
    Iter_ad7398 it;
    it.mpNode = reinterpret_cast<Node_ad7398*>(node);
    it.mpTable = table;
    Fn00969166(&it);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00969166 score 28
void HashT_ad7398::Fn00969166(Iter_ad7398* it)
{
    HNode_ad7398* target = reinterpret_cast<HNode_ad7398*>(it->mpNode);
    if (target) {
        uint32_t n = static_cast<uint32_t>(mpEnd - mpBegin);
        HNode_ad7398** slot = &mpBegin[target->mKey % n];
        HNode_ad7398* cur = *slot;
        if (cur == target) {
            *slot = cur->mpNext;
            FreeNode_ad7398(cur);
        } else {
            HNode_ad7398* next = cur->mpNext;
            while (next) {
                if (next == target) {
                    cur->mpNext = next->mpNext;
                    FreeNode_ad7398(next);
                    break;
                }
                cur = next;
                next = next->mpNext;
            }
            if (!next) {
                return;
            }
        }
        --mnSize;
    }
}
#endif
