#include "classes/cGZDBSegmentDirectoryFiles.h"
#include "classes/cGZRESIDtoExtensionMap.h"
#include <stddef.h>
#include <new>
#include "gzcom/cRZString.h"

// STUB: 0x00933015
uint32_t Fn00933015(uint32_t* count, int32_t delta);

// The extension map embedded at 0x44; only the slot used here is named.
struct ExtMap_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual void Call3_ad93a0();
    virtual void Pad4_ad93a0();
    virtual bool ResIDToExtension_ad93a0(uint32_t key, uint32_t ext);
    virtual void Pad6_ad93a0();
};

// The string the file name is written into; only the printf-like slot is named.
struct String_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual void Assign3_ad93a0(const char* data, uint32_t length);
    virtual void Pad4_ad93a0();
    virtual void Pad5_ad93a0();
    virtual void Pad6_ad93a0();
    virtual void Pad7_ad93a0();
    virtual void Pad8_ad93a0();
    virtual void Pad9_ad93a0();
    virtual void Pad10_ad93a0();
    virtual void Pad11_ad93a0();
    virtual void Pad12_ad93a0();
    virtual void Set13_ad93a0(uint32_t value);
    virtual void Assign14_ad93a0(const void* value);
    virtual void Pad15_ad93a0();
    virtual void Pad16_ad93a0();
    virtual void Append17_ad93a0(const char* data, uint32_t length);
    virtual void Pad18_ad93a0();
    virtual void Pad19_ad93a0();
    virtual void Pad20_ad93a0();
    virtual void Pad21_ad93a0();
    virtual void Pad22_ad93a0();
    virtual void Pad23_ad93a0();
    virtual void Pad24_ad93a0();
    virtual void Pad25_ad93a0();
    virtual void Pad26_ad93a0();
    virtual void Format27_ad93a0(const char* format, ...);
};

// A lock and its guard (the lock at 0xc is a vtable and a word).
struct Lock_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Enter_ad93a0();
    virtual void Leave_ad93a0();
};

struct Guard_ad93a0 {
    uint32_t mPad;
    Lock_ad93a0* mpLock;

    // STUB: 0x0048c9f0
    Guard_ad93a0(Lock_ad93a0* lock);
    ~Guard_ad93a0() { mpLock->Leave_ad93a0(); }
};

// The periodic timer embedded at 0x6c.
struct Timer_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual void Pad3_ad93a0();
    virtual void Pad4_ad93a0();
    virtual void Pad5_ad93a0();
    virtual void Pad6_ad93a0();
    virtual void Stop7_ad93a0();
};

// A key filter and a key list, as far as the key list walk uses them.
struct Filter_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual bool Test3_ad93a0(const void* key);
};

struct KeyList_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual void Pad3_ad93a0();
    virtual void Add4_ad93a0(const void* key);
};

// The record map: header pointer, size, then the walk helpers.
struct Map_ad93a0 {
    void* mpHead;
    uint32_t mnSize;

    // STUB: 0x0097989f
    void* Find_ad93a0(const void* key);
    // STUB: 0x0097ac6a
    void Clear_ad93a0();
    // STUB: 0x0097abe1
    void EraseSubtree_ad93a0(void* node);
    void ClearDraft_ad93a0();
};

// The records of one key (open handles): find one by its record, then drop it.
struct Handle_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual uint32_t Query3_ad93a0();
    virtual void Pad4_ad93a0();
    virtual void Pad5_ad93a0();
    virtual void Pad6_ad93a0();
    virtual void Pad7_ad93a0();
    virtual void Pad8_ad93a0();
    virtual void Pad9_ad93a0();
    virtual void Pad10_ad93a0();
    virtual void Pad11_ad93a0();
    virtual void Pad12_ad93a0();
    virtual void Pad13_ad93a0();
    virtual void Pad14_ad93a0();
    virtual void Close15_ad93a0();
    virtual void Abort16_ad93a0();
};

struct ListNode_ad93a0 {
    ListNode_ad93a0* mpNext;
    ListNode_ad93a0* mpPrev;
    Handle_ad93a0* mpItem;
};

struct RecordData_ad93a0 {
    uint32_t mPad[5];
    ListNode_ad93a0* mpList;

    Handle_ad93a0* FindHandle_ad93a0(uint32_t rec);
    // STUB: 0x00979a45
    uint32_t RemoveHandle_ad93a0(void* slot);
};

// The record being closed or aborted: only its key is read.
struct Record_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual void GetKey3_ad93a0(uint32_t* key);
};

// The base path string at 0x24: begin, end, capacity.
struct Path_ad93a0 {
    char* mpBegin;
    char* mpEnd;
    char* mpCapacity;

    // STUB: 0x00417a70
    void PushBack_ad93a0(char c);
};

// STUB: 0x005f8fe0
bool Fn005f8fe0(int c);

// The open file object owned by the segment (only its destructor is called here).
struct File_ad93a0 {
    // STUB: 0x0091b2f7
    void Destroy_ad93a0();
};

// The extension map object handed out by Slot13.
struct ResMap_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void AddRef_ad93a0();
    virtual void Pad2_ad93a0();
    virtual void Pad3_ad93a0();
    virtual void Pad4_ad93a0();
    virtual void Pad5_ad93a0();
    virtual void Pad6_ad93a0();
    virtual void CopyFrom7_ad93a0(uint32_t other);
    uint32_t mPad[3];

    // STUB: 0x0097b3ce
    ResMap_ad93a0();
};

// A node of the record map: tree links, then the key and the record data (a name range at 0x20).
struct MapNode_ad93a0 {
    uint32_t mColor;
    MapNode_ad93a0* mpParent;
    MapNode_ad93a0* mpLeft;
    MapNode_ad93a0* mpRight;
    uint32_t mKey[3];
    uint32_t mData[4];
    const char* mpName;
    const char* mpNameEnd;
};

// STUB: 0x0040d4c0
MapNode_ad93a0* Fn0040d4c0(MapNode_ad93a0* node);

// FUNCTION: 0x0096dfbd
bool cGZDBSegmentDirectoryFiles::Slot07_ad8ca0()
{
    return (mnMode & 3) != 0;
}

// FUNCTION: 0x009792af
bool cGZDBSegmentDirectoryFiles::Slot00_ad8fc8(uint32_t a, void* b)
{
    if (a != 0x856c8cf7) {
        return cUnk00ad8ca0::Slot00_ad8fc8(a, b);
    }
    *static_cast<cGZDBSegmentDirectoryFiles**>(b) = this;
    Slot01_ad8fc8();
    return true;
}

// FUNCTION: 0x009792d1
uint32_t cGZDBSegmentDirectoryFiles::Slot01_ad8fc8()
{
    return Fn00933015(&mnRefCount, 1);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009792df score 8
uint32_t cGZDBSegmentDirectoryFiles::Slot02_ad8fc8()
{
    uint32_t n = Fn00933015(&mnRefCount, -1);
    if (n > 0) {
        return n;
    }
    static_cast<cUnk00ad8ca0&>(*this).Slot31_ad8ca0();
    return 0;
}
#endif

// FUNCTION: 0x009792ff
void cGZDBSegmentDirectoryFiles::Slot31_ad8ca0()
{
    Slot06_ad8fc8();
    cUnk00ad8ca0::Slot31_ad8ca0();
}

// FUNCTION: 0x00979312
bool cGZDBSegmentDirectoryFiles::Slot15_ad8ca0(uint32_t a)
{
    uint32_t* p = OB_PTR(uint32_t, a);
    bool unset = mnSegmentID == 0;
    mnLastID = *p;
    if (unset) {
        mnSegmentID = *p;
    }
    return true;
}

// FUNCTION: 0x0097932b
bool cGZDBSegmentDirectoryFiles::Slot05_ad8fc8()
{
    if (!mbFlag14) {
        mbFlag14 = true;
    }
    return true;
}

// FUNCTION: 0x00979338
uint32_t cGZDBSegmentDirectoryFiles::Slot16_ad8ca0(uint32_t a)
{
    return Slot18_ad8ca0(0, a);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00979346 score 23
bool cGZDBSegmentDirectoryFiles::Slot34_ad8ca0(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t mode;
    if (c & 2) {
        mode = 2;
    } else if (c & 1) {
        mode = 1;
    } else {
        return false;
    }
    return Slot27_ad93a0(a, b, mode);
}
#endif

// FUNCTION: 0x00979371
bool cGZDBSegmentDirectoryFiles::DoOpenRecordForWrite(uint32_t a, uint32_t b)
{
    return Slot27_ad93a0(a, b, 2);
}

// FUNCTION: 0x00979383
bool cGZDBSegmentDirectoryFiles::Slot35_ad8ca0(uint32_t a, uint32_t b)
{
    return Slot27_ad93a0(a, b, 3);
}

// FUNCTION: 0x00979398
bool cGZDBSegmentDirectoryFiles::getFileNameFromKey(uint32_t a, uint32_t b, uint32_t c)
{
    bool r;
    if (reinterpret_cast<ExtMap_ad93a0*>(&field44[0])->ResIDToExtension_ad93a0(a, c)) {
    const uint32_t* key = OB_PTR(const uint32_t, a);
    String_ad93a0* s = OB_PTR(String_ad93a0, b);
    if (key[1] == mnSegmentID) {
        s->Format27_ad93a0("%8.8x", key[2]);
    } else {
        s->Format27_ad93a0("%8.8x%8.8x", key[2], key[1]);
    }
        r = true;
    } else {
        r = false;
    }
    return r;
}

// NOT ATTEMPTED: 0x009793f1 Slot31_ad93a0 is a bare tail jmp [vptr+0x78] (to getFileNameFromKey) that passes its stack arguments on; its declared arguments (none) cannot express it.

// FUNCTION: 0x009793f6
void cGZDBSegmentDirectoryFiles::Slot15_ad8fc8(uint32_t a, uint32_t b)
{
    mbAllowedA = *reinterpret_cast<bool*>(&a);
    mbAllowedB = *reinterpret_cast<bool*>(&b);
}

// FUNCTION: 0x00979411
void cGZDBSegmentDirectoryFiles::Slot14_ad8fc8()
{
    reinterpret_cast<ExtMap_ad93a0*>(&field44[0])->Call3_ad93a0();
}

#ifdef OB_DRAFTS
// CLOSE: 0x00979912 score 13
void cGZDBSegmentDirectoryFiles::Slot08_ad8fc8(uint32_t a)
{
    OB_PTR(String_ad93a0, a)->Assign3_ad93a0(mpName, static_cast<uint32_t>(mpNameEnd - mpName));
}
#endif

// FUNCTION: 0x0097992c
bool cGZDBSegmentDirectoryFiles::Slot24_ad8fc8(uint32_t a, uint32_t b)
{
    bool on = *reinterpret_cast<bool*>(&a);
    if (field64 != on) {
        if (on) {
            if (mbFlag14) {
                StartBackgroundThread();
            }
        } else {
            reinterpret_cast<Timer_ad93a0*>(&field64 + 8)->Stop7_ad93a0();
        }
        field64 = on;
    }
    mnInterval = b;
    if (b < 0xf) {
        mnInterval = 0xf;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00979a82 score 24
uint32_t cGZDBSegmentDirectoryFiles::Slot18_ad8ca0(uint32_t a, uint32_t b)
{
    uint32_t n = 0;
    MapNode_ad93a0* head = static_cast<MapNode_ad93a0*>(mpMapHead);
    for (MapNode_ad93a0* node = head->mpLeft; node != head; node = Fn0040d4c0(node)) {
        Filter_ad93a0* filter = OB_PTR(Filter_ad93a0, b);
        if (filter) {
            if (!filter->Test3_ad93a0(&node->mKey[0])) {
                continue;
            }
        }
        KeyList_ad93a0* list = OB_PTR(KeyList_ad93a0, a);
        if (list) {
            list->Add4_ad93a0(&node->mKey[0]);
        }
        n++;
    }
    return n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00979b1f score 60
uint32_t cGZDBSegmentDirectoryFiles::Slot22_ad8fc8(uint32_t a, uint32_t b)
{
    Guard_ad93a0 guard(reinterpret_cast<Lock_ad93a0*>(&mLock[0]));
    uint32_t n = 0;
    uint32_t result;
    if (a != 0) {
        String_ad93a0** out = OB_PTR(String_ad93a0*, a);
        MapNode_ad93a0* head = static_cast<MapNode_ad93a0*>(mpMapHead);
        MapNode_ad93a0* node = head->mpLeft;
        for (; node != head && n < b && out[n]; n++) {
            out[n]->Assign3_ad93a0(node->mpName, static_cast<uint32_t>(node->mpNameEnd - node->mpName));
            node = Fn0040d4c0(node);
        }
        result = n;
    } else {
        result = mnMapSize;
    }
    return result;
}
#endif

// FUNCTION: 0x00979cbb
bool cGZDBSegmentDirectoryFiles::Slot36_ad8ca0(void* a)
{
    Record_ad93a0* rec = static_cast<Record_ad93a0*>(a);
    bool r = false;
    uint32_t key[3];
    rec->GetKey3_ad93a0(key);
    Map_ad93a0* map = reinterpret_cast<Map_ad93a0*>(&mpMapHead);
    void* node = map->Find_ad93a0(key);
    if (node != map->mpHead) {
        RecordData_ad93a0* data = reinterpret_cast<RecordData_ad93a0*>(static_cast<char*>(node) + 0x1c);
        Handle_ad93a0* h = data->FindHandle_ad93a0(OB_ADDR(rec));
        if (h) {
            h->Close15_ad93a0();
            data->RemoveHandle_ad93a0(reinterpret_cast<char*>(h) + 8);
            r = true;
        }
    }
    return r;
}

// FUNCTION: 0x00979d1b
bool cGZDBSegmentDirectoryFiles::Slot37_ad8ca0(void* a)
{
    Record_ad93a0* rec = static_cast<Record_ad93a0*>(a);
    bool r = false;
    uint32_t key[3];
    rec->GetKey3_ad93a0(key);
    Map_ad93a0* map = reinterpret_cast<Map_ad93a0*>(&mpMapHead);
    void* node = map->Find_ad93a0(key);
    if (node != map->mpHead) {
        RecordData_ad93a0* data = reinterpret_cast<RecordData_ad93a0*>(static_cast<char*>(node) + 0x1c);
        Handle_ad93a0* h = data->FindHandle_ad93a0(OB_ADDR(rec));
        if (h) {
            h->Abort16_ad93a0();
            data->RemoveHandle_ad93a0(reinterpret_cast<char*>(h) + 8);
            r = true;
        }
    }
    return r;
}

// FUNCTION: 0x00979d7b
bool cGZDBSegmentDirectoryFiles::Slot32_ad8ca0(uint32_t a)
{
    Map_ad93a0* map = reinterpret_cast<Map_ad93a0*>(&mpMapHead);
    return map->Find_ad93a0(OB_PTR(void, a)) != map->mpHead;
}

// FUNCTION: 0x00979d97
bool cGZDBSegmentDirectoryFiles::Slot17_ad8fc8(uint32_t a, uint32_t b)
{
    Map_ad93a0* map = reinterpret_cast<Map_ad93a0*>(&mpMapHead);
    void* node = map->Find_ad93a0(OB_PTR(void, a));
    if (node != map->mpHead) {
        OB_PTR(String_ad93a0, b)->Assign14_ad93a0(static_cast<char*>(node) + 0x1c);
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00979dc1 score 21
bool cGZDBSegmentDirectoryFiles::Slot21_ad8fc8(uint32_t a, uint32_t b)
{
    if (!mbFlag14) {
        return false;
    }
    uint32_t* key = OB_PTR(uint32_t, b);
    key[1] = mnSegmentID;
    key[0] = a;
    Map_ad93a0* map = reinterpret_cast<Map_ad93a0*>(&mpMapHead);
    for (;;) {
        if (mnNextID == 0xffffffff) {
            return false;
        }
        key[2] = mnNextID;
        mnNextID++;
        if (map->Find_ad93a0(key) == map->mpHead) {
            return true;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097a6d1 score 10
bool cGZDBSegmentDirectoryFiles::Slot09_ad8fc8(uint32_t a)
{
    if (mnMode & 3) {
        return false;
    }
    reinterpret_cast<String_ad93a0*>(&field20[0])->Set13_ad93a0(a);
    Path_ad93a0* path = reinterpret_cast<Path_ad93a0*>(&field20[4]);
    if (!Fn005f8fe0(path->mpEnd[-1])) {
        path->PushBack_ad93a0('\\');
    }
    return true;
}
#endif

// FUNCTION: 0x0097b283
bool cGZDBSegmentDirectoryFiles::Slot08_ad8ca0()
{
    if (mnMode & 3) {
        Fn00979ad2();
        mnMode = 0;
        reinterpret_cast<ExtMap_ad93a0*>(&field44[0])->Pad6_ad93a0();
        reinterpret_cast<Map_ad93a0*>(&mpMapHead)->Clear_ad93a0();
        File_ad93a0* file = static_cast<File_ad93a0*>(mpFile);
        if (file) {
            file->Destroy_ad93a0();
            ::operator delete(file);
            mpFile = 0;
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097b52d score 2
bool cGZDBSegmentDirectoryFiles::Slot13_ad8fc8(uint32_t a)
{
    ResMap_ad93a0* map = new ResMap_ad93a0;
    map->AddRef_ad93a0();
    map->CopyFrom7_ad93a0(OB_ADDR(&field44[0]));
    *OB_PTR(ResMap_ad93a0*, a) = map;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097b11e score 2
bool cGZDBSegmentDirectoryFiles::Slot06_ad8fc8()
{
    if (mbFlag14) {
        mbFlag14 = false;
        reinterpret_cast<Timer_ad93a0*>(&field64 + 8)->Stop7_ad93a0();
        if (mnMode & 3) {
            Slot08_ad8ca0();
        }
        mnNextID = 1;
        if (mpName != mpNameEnd) {
            *const_cast<char*>(mpName) = 0;
            mpNameEnd = mpName;
        }
        File_ad93a0* file = static_cast<File_ad93a0*>(mpFile);
        mnSegmentID = 0;
        mnLastID = 0;
        mbAllowedA = true;
        mbAllowedB = false;
        if (file) {
            file->Destroy_ad93a0();
            ::operator delete(file);
            mpFile = 0;
        }
        reinterpret_cast<ExtMap_ad93a0*>(&field44[0])->Pad6_ad93a0();
        reinterpret_cast<Map_ad93a0*>(&mpMapHead)->Clear_ad93a0();
    }
    return true;
}
#endif

// FUNCTION: 0x009798e8
Handle_ad93a0* RecordData_ad93a0::FindHandle_ad93a0(uint32_t rec)
{
    ListNode_ad93a0* head = mpList;
    for (ListNode_ad93a0* node = head->mpNext; node != head; node = node->mpNext) {
        Handle_ad93a0* h = node->mpItem;
        char* address = h ? reinterpret_cast<char*>(h) + 8 : 0;
        if (OB_ADDR(address) == rec) {
            return h;
        }
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097ac6a score 11
void Map_ad93a0::ClearDraft_ad93a0()
{
    if (mnSize != 0) {
        MapNode_ad93a0* head = static_cast<MapNode_ad93a0*>(mpHead);
        EraseSubtree_ad93a0(head->mpParent);
        head->mpLeft = head;
        head = static_cast<MapNode_ad93a0*>(mpHead);
        head->mpParent = 0;
        head = static_cast<MapNode_ad93a0*>(mpHead);
        head->mpRight = head;
        mnSize = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00979e74 score 19
bool cGZDBSegmentDirectoryFiles::Slot18_ad8fc8(uint32_t a, uint32_t b)
{
    cRZString name;
    bool r = Slot17_ad8fc8(a, OB_ADDR(&name));
    if (r) {
        String_ad93a0* out = OB_PTR(String_ad93a0, b);
        out->Assign14_ad93a0(&field20[0]);
        out->Append17_ad93a0(name.c_str(), static_cast<uint32_t>(name.size()));
    }
    return r;
}
#endif

// ---- helpers (STL list/map internals of the record map) ----
struct Key_ad93a0 {
    uint32_t mKey[3];

    // STUB: 0x00662810
    bool Less_ad93a0(const void* other) const;
};

struct ListHead_ad93a0 {
    ListNode_ad93a0* mpHead;

    // STUB: 0x009677e6
    void Clear_ad93a0();
    // STUB: 0x00968c53
    void Erase_ad93a0(ListNode_ad93a0* it, const uint32_t* key);
    // STUB: 0x0093f7eb
    void Init_ad93a0(const char* alloc);
    // STUB: 0x0093baef
    void Destroy_ad93a0();
    // STUB: 0x00979e2a
    void Copy_ad93a0(const void* other);
};

struct KeyData_ad93a0 {
    uint32_t mPad[3];

    // STUB: 0x0097a68d
    void Destroy_ad93a0(uint32_t flag);
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);
// STUB: 0x0040daf0
MapNode_ad93a0* Fn0040daf0(MapNode_ad93a0* x, void* a, void* b, void* c);
// STUB: 0x0040d500
MapNode_ad93a0* Fn0040d500(MapNode_ad93a0* x);
// STUB: 0x0040d5e0
void Fn0040d5e0(MapNode_ad93a0* x, void* root);

struct Svc_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual void Pad3_ad93a0();
    virtual void Pad4_ad93a0();
    virtual void Query5_ad93a0(uint32_t a, uint32_t b, void* out);
};
// STUB: 0x008793ec
Svc_ad93a0* Fn008793ec();

struct Holder_ad93a0 {
    void* mpValue;
    Holder_ad93a0* Fn00456a30();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00456a30 score 2
Holder_ad93a0* Holder_ad93a0::Fn00456a30()
{
    mpValue = 0;
    Svc_ad93a0* svc = Fn008793ec();
    if (svc) {
        svc->Query5_ad93a0(0x25076b9e, 0xa237613c, this);
    }
    return this;
}
#endif

struct Erasable_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual void Pad3_ad93a0();
    virtual void Pad4_ad93a0();
    virtual void Pad5_ad93a0();
    virtual void Pad6_ad93a0();
    virtual void Pad7_ad93a0();
    virtual void Pad8_ad93a0();
    virtual void Pad9_ad93a0();
    virtual void Pad10_ad93a0();
    virtual void Pad11_ad93a0();
    virtual void Pad12_ad93a0();
    virtual void Pad13_ad93a0();
    virtual void Pad14_ad93a0();
    virtual void Pad15_ad93a0();
    virtual void Pad16_ad93a0();
    virtual void Pad17_ad93a0();
    virtual void Pad18_ad93a0();
    virtual void Pad19_ad93a0();
    virtual void Pad20_ad93a0();
    virtual void Pad21_ad93a0();
    virtual void Pad22_ad93a0();
    virtual void Pad23_ad93a0();
    virtual void Pad24_ad93a0();
    virtual void Pad25_ad93a0();
    virtual void Pad26_ad93a0();
    virtual void Pad27_ad93a0();
    virtual void Release28_ad93a0(uint32_t flag);
};

struct EraseNode_ad93a0 {
    EraseNode_ad93a0* mpNext;
    EraseNode_ad93a0* mpPrev;
    Erasable_ad93a0 mItem;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00456ab0 score 3
void OB_STDCALL Fn00456ab0(EraseNode_ad93a0** out, EraseNode_ad93a0* node)
{
    EraseNode_ad93a0* next = node->mpNext;
    node->mpPrev->mpNext = next;
    next->mpPrev = node->mpPrev;
    node->mItem.Release28_ad93a0(0);
    Fn0090cf63(node);
    *out = next;
}
#endif


#ifdef OB_DRAFTS
// CLOSE: 0x00979ad2 score 12
void cGZDBSegmentDirectoryFiles::Fn00979ad2()
{
    MapNode_ad93a0* head = static_cast<MapNode_ad93a0*>(mpMapHead);
    MapNode_ad93a0* node = head->mpLeft;
    while (node != head) {
        ListHead_ad93a0* list = reinterpret_cast<ListHead_ad93a0*>(reinterpret_cast<char*>(node) + 0x30);
        ListNode_ad93a0* lh = list->mpHead;
        if (lh->mpNext != lh) {
            ListNode_ad93a0* end = lh;
            for (ListNode_ad93a0* it = end->mpNext; it != end; it = it->mpNext) {
                it->mpItem->Close15_ad93a0();
            }
            list->Clear_ad93a0();
        }
        node = Fn0040d4c0(node);
    }
}
#endif

struct RecordInit_ad93a0 {
    cRZString mName;
    uint32_t mPad[1];
    ListHead_ad93a0 mList;
    RecordInit_ad93a0* Fn00979e59();
    RecordInit_ad93a0* Fn0097a6ac(const cRZString& src);
    // STUB: 0x0097ab7f
    RecordInit_ad93a0* Fn0097ab7f(const RecordInit_ad93a0& src);
    void Fn0097a1e5();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00979e59 score 4
RecordInit_ad93a0* RecordInit_ad93a0::Fn00979e59()
{
    new (this) cRZString();
    char dummy;
    mList.Init_ad93a0(&dummy);
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097a6ac score 6
RecordInit_ad93a0* RecordInit_ad93a0::Fn0097a6ac(const cRZString& src)
{
    new (this) cRZString(src, 0, 0xffffffff);
    char dummy;
    mList.Init_ad93a0(&dummy);
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097ab7f score 8
RecordInit_ad93a0* RecordInit_ad93a0::Fn0097ab7f(const RecordInit_ad93a0& src)
{
    new (this) cRZString(src.mName, 0, 0xffffffff);
    mList.Copy_ad93a0(&src.mList);
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097a1e5 score 2
void RecordInit_ad93a0::Fn0097a1e5()
{
    mList.Destroy_ad93a0();
    mName.cRZString::~cRZString();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097aba4 score 6
void Map_ad93a0_Erase(Map_ad93a0* map, MapNode_ad93a0* x)
{
    MapNode_ad93a0* head = static_cast<MapNode_ad93a0*>(map->mpHead);
    MapNode_ad93a0* n = Fn0040daf0(x, &head->mpParent, &head->mpLeft, &head->mpRight);
    reinterpret_cast<KeyData_ad93a0*>(&n->mKey[0])->Destroy_ad93a0(0);
    if (n) {
        Fn0090cf63(n);
    }
    map->mnSize--;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097abe1 score 11
void Map_ad93a0_EraseSubtree(Map_ad93a0* map, MapNode_ad93a0* x)
{
    while (x) {
        Map_ad93a0_EraseSubtree(map, x->mpRight);
        MapNode_ad93a0* left = x->mpLeft;
        reinterpret_cast<KeyData_ad93a0*>(&x->mKey[0])->Destroy_ad93a0(0);
        Fn0090cf63(x);
        x = left;
    }
}
#endif

struct Pair_ad93a0 {
    uint32_t mKey[3];
    RecordInit_ad93a0 mData;
    Pair_ad93a0* Fn0097ac41(const uint32_t* key, const RecordInit_ad93a0& data);
};

// FUNCTION: 0x0097ac41
Pair_ad93a0* Pair_ad93a0::Fn0097ac41(const uint32_t* key, const RecordInit_ad93a0& data)
{
    mKey[0] = key[0];
    mKey[1] = key[1];
    mKey[2] = key[2];
    mData.Fn0097ab7f(data);
    return this;
}

struct Alloc_ad93a0 {
    // STUB: 0x0066e320
    void Init_ad93a0(char* a, char* b);
    // STUB: 0x0097b2cf
    Alloc_ad93a0* Fn0097b2cf();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0097b2cf score 1
Alloc_ad93a0* Alloc_ad93a0::Fn0097b2cf()
{
    char c;
    Init_ad93a0(&c, &c);
    return this;
}
#endif

// Not hooked: run in the game, a constructor installs our stand-in vtables (their destructors are not the original's
// yet) in place of the original's.
// FUNCTION: 0x0097b3ce nohook
cGZRESIDtoExtensionMap::cGZRESIDtoExtensionMap()
{
    mnCount = 0;
    reinterpret_cast<Alloc_ad93a0*>(unknown8)->Fn0097b2cf();
}

// STUB: 0x0097b670
struct Inserter_ad93a0 {
    // STUB: 0x0097b670
    void Fn0097b670(uint32_t* out, MapNode_ad93a0* it, const void* value);
    uint32_t* Fn0097bb80(uint32_t* out, MapNode_ad93a0* it, const void* value);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0097bb80 score 5
uint32_t* Inserter_ad93a0::Fn0097bb80(uint32_t* out, MapNode_ad93a0* it, const void* value)
{
    Fn0097b670(out, it, value);
    return out;
}
#endif

struct MapOps_ad93a0 {
    void* mpHead;
    uint32_t mnSize;
    MapNode_ad93a0* Fn00979a17(const void* key);
    void* Index_ad93a0(const uint32_t* key);
    void Fn0097b33c(uint32_t* out, MapNode_ad93a0* x, MapNode_ad93a0* y, const void* v, uint32_t flag);
    void Fn0097b569(uint32_t* out, const uint32_t* v);
    // STUB: 0x0097ae7d
    MapNode_ad93a0* NewNode_ad93a0(const void* v);
    // STUB: 0x0097b670
    void Fn0097b670(uint32_t* out, MapNode_ad93a0* it, const void* value);
};

// FUNCTION: 0x00979a17
MapNode_ad93a0* MapOps_ad93a0::Fn00979a17(const void* key)
{
    MapNode_ad93a0* result = static_cast<MapNode_ad93a0*>(mpHead);
    MapNode_ad93a0* node = result->mpParent;
    while (node) {
        if (!reinterpret_cast<Key_ad93a0*>(&node->mKey[0])->Less_ad93a0(key)) {
            result = node;
            node = node->mpLeft;
        } else {
            node = node->mpRight;
        }
    }
    return result;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097bb9d score 34
void* MapOps_ad93a0::Index_ad93a0(const uint32_t* key)
{
    MapNode_ad93a0* it = Fn00979a17(key);
    if (it == mpHead || reinterpret_cast<const Key_ad93a0*>(key)->Less_ad93a0(&it->mKey[0])) {
        RecordInit_ad93a0 blank;
        blank.Fn00979e59();
        Pair_ad93a0 pair;
        pair.Fn0097ac41(key, blank);
        uint32_t result;
        Fn0097b670(&result, it, &pair);
        it = reinterpret_cast<MapNode_ad93a0*>(result);
        pair.mData.Fn0097a1e5();
        blank.Fn0097a1e5();
    }
    return &it->mData[0];
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097b33c score 4
void MapOps_ad93a0::Fn0097b33c(uint32_t* out, MapNode_ad93a0* x, MapNode_ad93a0* y, const void* v, uint32_t flag)
{
    MapNode_ad93a0* z;
    if (y == mpHead || flag != 0 || (x == 0 && reinterpret_cast<const Key_ad93a0*>(v)->Less_ad93a0(&y->mKey[0]))) {
        z = NewNode_ad93a0(v);
        y->mpLeft = z;
        MapNode_ad93a0* head = static_cast<MapNode_ad93a0*>(mpHead);
        if (y == head) {
            head->mpParent = z;
            head = static_cast<MapNode_ad93a0*>(mpHead);
            head->mpRight = z;
        } else if (y == head->mpLeft) {
            head->mpLeft = z;
        }
    } else {
        z = NewNode_ad93a0(v);
        y->mpRight = z;
        MapNode_ad93a0* head = static_cast<MapNode_ad93a0*>(mpHead);
        if (y == head->mpRight) {
            head->mpRight = z;
        }
    }
    z->mpLeft = 0;
    z->mpRight = 0;
    z->mpParent = y;
    Fn0040d5e0(z, &static_cast<MapNode_ad93a0*>(mpHead)->mpParent);
    mnSize++;
    *out = OB_ADDR(z);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097b569 score 14
void MapOps_ad93a0::Fn0097b569(uint32_t* out, const uint32_t* v)
{
    MapNode_ad93a0* head = static_cast<MapNode_ad93a0*>(mpHead);
    MapNode_ad93a0* x = head->mpParent;
    MapNode_ad93a0* y = head;
    bool left = true;
    while (x) {
        y = x;
        left = reinterpret_cast<const Key_ad93a0*>(v)->Less_ad93a0(&x->mKey[0]);
        x = left ? x->mpLeft : x->mpRight;
    }
    MapNode_ad93a0* j = y;
    if (left) {
        if (y != head->mpLeft) {
            j = Fn0040d500(y);
            goto check;
        }
    } else {
    check:
        if (!reinterpret_cast<Key_ad93a0*>(&j->mKey[0])->Less_ad93a0(v)) {
            out[0] = OB_ADDR(j);
            reinterpret_cast<uint8_t*>(out)[4] = 0;
            return;
        }
    }
    uint32_t it;
    Fn0097b33c(&it, x, y, v, 0);
    out[0] = it;
    reinterpret_cast<uint8_t*>(out)[4] = 1;
}
#endif

// ---- the name-checking and record-size methods ----
// STUB: 0x0091a93d
void Fn0091a93d(const void* entry, void* dest, bool flag);
// STUB: 0x0091a1a6
void Fn0091a1a6(cRZString* name);
// STUB: 0x00918417
void Fn00918417(uint32_t name, cRZString* out);
// STUB: 0x0091a3e2
uint32_t Fn0091a3e2(cRZString* name);
// STUB: 0x00408ae0
std::string Fn00408ae0_ad93a0(const std::string* a, const std::string* b);

// FUNCTION: 0x0097a144
bool cGZDBSegmentDirectoryFiles::Slot20_ad8fc8(uint32_t a)
{
    cRZString path;
    cRZString ext;
    uint32_t options[3];
    options[0] = 0;
    options[1] = 0;
    options[2] = 0;
    Fn0091a93d(OB_PTR(const void, a), &path, false);
    Fn00918417(a, &ext);
    if (ext.size() != 0 && ext[0] == '.') {
        ext.erase(0, 1);
    }
    return Slot19_ad8fc8(OB_ADDR(&path), OB_ADDR(&ext), OB_ADDR(options));
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097a713 score 30
uint32_t cGZDBSegmentDirectoryFiles::Slot33_ad8ca0(uint32_t key)
{
    uint32_t result = 0xffffffff;
    if (mbFlag14) {
        Map_ad93a0* map = reinterpret_cast<Map_ad93a0*>(&mpMapHead);
        MapNode_ad93a0* node = static_cast<MapNode_ad93a0*>(map->Find_ad93a0(OB_PTR(const void, key)));
        if (node != map->mpHead) {
            ListNode_ad93a0* lh = *reinterpret_cast<ListNode_ad93a0**>(reinterpret_cast<char*>(node) + 0x30);
            for (ListNode_ad93a0* it = lh->mpNext; it != lh; it = it->mpNext) {
                Handle_ad93a0* h = it->mpItem;
                uint32_t kind = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(h) + 0x148);
                if (kind == 2 || kind == 3) {
                    result = h->Query3_ad93a0();
                }
            }
            if (lh->mpNext == lh || result == 0xffffffff) {
                std::string full = Fn00408ae0_ad93a0(static_cast<std::string*>(reinterpret_cast<cRZString*>(&field20[0])),
                                                     reinterpret_cast<std::string*>(&node->mData[1]));
                cRZString name(full);
                result = Fn0091a3e2(&name);
            }
        }
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097ac93 score 64
bool cGZDBSegmentDirectoryFiles::Slot38_ad8ca0(uint32_t key)
{
    bool done = false;
    if (mbFlag14) {
        Map_ad93a0* map = reinterpret_cast<Map_ad93a0*>(&mpMapHead);
        MapNode_ad93a0* node = static_cast<MapNode_ad93a0*>(map->Find_ad93a0(OB_PTR(const void, key)));
        if (node != map->mpHead) {
            ListNode_ad93a0* lh = *reinterpret_cast<ListNode_ad93a0**>(reinterpret_cast<char*>(node) + 0x30);
            if (lh->mpNext == lh) {
                std::string full = Fn00408ae0_ad93a0(static_cast<std::string*>(reinterpret_cast<cRZString*>(&field20[0])),
                                                     static_cast<std::string*>(reinterpret_cast<cRZString*>(&node->mData[0])));
                cRZString name(full);
                Map_ad93a0_Erase(map, node);
                Fn0091a1a6(&name);
                done = true;
            }
        }
    }
    return done;
}
#endif

// ---- Open ----
// A directory object (0x34 bytes), built from the base path.
struct Dir_ad93a0 {
    // STUB: 0x0091bd31
    Dir_ad93a0(const void* path, bool a, bool b, bool c);
};

// The holder 0x00456a30 fills and 0x00456a60 releases.
struct Watcher_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual void Pad3_ad93a0();
    virtual void Pad4_ad93a0();
    virtual void Pad5_ad93a0();
    virtual void Pad6_ad93a0();
    virtual bool Watch7_ad93a0(uint32_t what, void* callback, void* user);
};

struct WatcherRef_ad93a0 {
    Watcher_ad93a0* mp;

    // STUB: 0x00456a60
    ~WatcherRef_ad93a0();
};

// STUB: 0x0091b6ca
bool Fn0091b6ca(const void* path);

struct PrimaryView_ad93a0 {
    virtual void Pad0_ad93a0();
    virtual void Pad1_ad93a0();
    virtual void Pad2_ad93a0();
    virtual void Pad3_ad93a0();
    virtual void Pad4_ad93a0();
    virtual void Pad5_ad93a0();
    virtual void Pad6_ad93a0();
    virtual void Pad7_ad93a0();
    virtual void Pad8_ad93a0();
    virtual void Pad9_ad93a0();
    virtual void Pad10_ad93a0();
    virtual void Pad11_ad93a0();
    virtual void Pad12_ad93a0();
    virtual void Pad13_ad93a0();
    virtual void Pad14_ad93a0();
    virtual void Pad15_ad93a0();
    virtual void Pad16_ad93a0();
    virtual void Pad17_ad93a0();
    virtual void Pad18_ad93a0();
    virtual void Pad19_ad93a0();
    virtual void Pad20_ad93a0();
    virtual void Pad21_ad93a0();
    virtual void Pad22_ad93a0();
    virtual void Pad23_ad93a0();
    virtual void Pad24_ad93a0();
    virtual void Pad25_ad93a0();
    virtual void Pad26_ad93a0();
    virtual void Pad27_ad93a0();
    virtual bool Build28_ad93a0();
};


#ifdef OB_DRAFTS
// CLOSE: 0x0097b195 score 68
bool cGZDBSegmentDirectoryFiles::Slot06_ad8ca0(uint32_t a, uint32_t b)
{
    bool wantRead = *reinterpret_cast<bool*>(&a);
    bool wantWrite = *reinterpret_cast<bool*>(&b);
    bool open = false;
    if (mnMode & 3) {
        open = true;
        return open;
    }
    if (!mbFlag14 || mpName == mpNameEnd || (!wantRead && !wantWrite)) {
        return open;
    }
    mnMode = 0;
    if (wantRead) {
        mnMode = 1;
    }
    if (wantWrite) {
        mnMode |= 2;
    }
    if (unknown15[0]) {
        if (!Fn0091b6ca(&field20[0])) {
            open = false;
            mnMode = 0;
            return open;
        }
    }
    if (mpFile == 0) {
        void* mem = ::operator new(0x34);
        mpFile = mem ? new (mem) Dir_ad93a0(&field20[0], false, false, false) : 0;
    }
    WatcherRef_ad93a0 ref;
    ref.mp = 0;
    reinterpret_cast<Holder_ad93a0*>(&ref)->Fn00456a30();
    if (ref.mp) {
        if (!ref.mp->Watch7_ad93a0(0x00a870a8, reinterpret_cast<void*>(0x0097ad40), static_cast<cUnk00ad8fc8*>(this))) {
            return false;
        }
    }
    open = reinterpret_cast<PrimaryView_ad93a0*>(static_cast<cUnk00ad8fc8*>(this))->Build28_ad93a0();
    if (open && field64) {
        StartBackgroundThread();
    }
    return open;
}
#endif

// ---- list erase by element address ----
struct RecList_ad93a0 {
    uint32_t mPad[5];
    ListHead_ad93a0 mList;
    uint32_t Fn00979a45Draft(uint32_t rec);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00979a45 score 37
uint32_t RecList_ad93a0::Fn00979a45Draft(uint32_t rec)
{
    ListNode_ad93a0* head = mList.mpHead;
    ListNode_ad93a0* node = head->mpNext;
    while (node != head) {
        Handle_ad93a0* h = node->mpItem;
        char* address = h ? reinterpret_cast<char*>(h) + 8 : 0;
        if (OB_ADDR(address) == rec) {
            mList.Erase_ad93a0(node, &rec);
            break;
        }
        node = node->mpNext;
    }
    return OB_ADDR(node);
}
#endif
