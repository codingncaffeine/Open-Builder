#include "classes/cSC4Region.h"

#include <algorithm>
#include <new>

#ifdef _MSC_VER
#define OB_FORCEINLINE_a8fa40 __forceinline
#else
#define OB_FORCEINLINE_a8fa40 inline
#endif

// A city of the region, seen through its interface: only the slots used here are named (slot numbers from the
// vtable, PadNN keeping the rest).
struct cISC4RegionalCity_a8fa40 {
    virtual void Pad00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad03();
    virtual void Shutdown();
    virtual void GetPosition(int32_t* x, int32_t* y);
    virtual void SetPosition(int32_t x, int32_t y, bool flag);
    virtual void GetCitySize(int32_t* width, int32_t* height);
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
    virtual uint32_t GetCitySerialNumber();
    virtual void SetCitySerialNumber(uint32_t serial);
    virtual void Pad29();
    virtual void Pad30();
    virtual void GetCitySaveFilePath(cIGZString& path);
    virtual void SetCitySaveFilePath(const cIGZString& path);
    virtual void GetCityName(cIGZString& name);
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
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual void Pad55();
    virtual void Pad56();
    virtual void Pad57();
    virtual void Pad58();
    virtual void Pad59();
    virtual void Pad60();
    virtual void Pad61();
    virtual void Pad62();
    virtual void Pad63();
    virtual void Pad64();
    virtual int32_t GetTutorialGUID();
    virtual void SetTutorialGUID(int32_t guid);
};

// What a region keeps per city cell: a heap cell holding one reference to the city.
struct Holder_a8fa40 {
    cISC4RegionalCity_a8fa40* mpCity;
    explicit Holder_a8fa40(cISC4RegionalCity_a8fa40* city)
        : mpCity(city)
    {
        city->AddRef();
    }
    ~Holder_a8fa40()
    {
        if (mpCity) {
            mpCity->Release();
        }
    }
};

// A cell of the region.
struct Point_a8fa40 {
    int32_t mnX;
    int32_t mnY;
};

// A node of the cell table: the next node of its bucket, the cell, and the holder of the city standing on it.
struct Node_a8fa40 {
    Node_a8fa40* mpNext;
    int32_t mnX;
    int32_t mnY;
    Holder_a8fa40* mpValue;
};

// The (cell, holder) pair the table stores.
struct Pair_a8fa40 {
    int32_t mnX;
    int32_t mnY;
    Holder_a8fa40* mpValue;
};

struct Cells_a8fa40;

struct Iterator_a8fa40 {
    Node_a8fa40* mpNode;
    Cells_a8fa40* mpTable;
    Iterator_a8fa40() {}
    void Advance();
    Iterator_a8fa40(Node_a8fa40* node, Cells_a8fa40* table)
        : mpNode(node)
        , mpTable(table)
    {
    }
};

// The region's cell table at +0x50 (an STL hash table in the original, its bucket vector at +4): a view over the
// region's own bytes. The functions that are not inline were instantiated elsewhere.
struct Cells_a8fa40 {
    uint32_t mnPad;
    Node_a8fa40** mpBucketsBegin;
    Node_a8fa40** mpBucketsEnd;
    Node_a8fa40** mpBucketsCap;
    uint32_t mnCount;

    Iterator_a8fa40 FindInline(int32_t x, int32_t y)
    {
        uint32_t bucket = static_cast<uint32_t>(((x & 0xf) << 4) | (y & 0xf)) %
                          static_cast<uint32_t>(mpBucketsEnd - mpBucketsBegin);
        Node_a8fa40* node = mpBucketsBegin[bucket];
        while (node && !(node->mnX == x && node->mnY == y)) {
            node = node->mpNext;
        }
        return Iterator_a8fa40(node, this);
    }
    // STUB: 0x004a4ad0
    Pair_a8fa40* FindOrInsert(const Pair_a8fa40* value);
    // STUB: 0x004a46a0
    void* Find(const Point_a8fa40* key);
    // STUB: 0x004a4760
    void Erase(const Point_a8fa40* key);
    // STUB: 0x004b0390
    Iterator_a8fa40 Begin();
    OB_FORCEINLINE_a8fa40 Iterator_a8fa40 BeginInline()
    {
        for (uint32_t n = 0; n < static_cast<uint32_t>(mpBucketsEnd - mpBucketsBegin); ++n) {
            if (mpBucketsBegin[n]) {
                return Iterator_a8fa40(mpBucketsBegin[n], this);
            }
        }
        return Iterator_a8fa40(0, this);
    }
};

OB_FORCEINLINE_a8fa40 Node_a8fa40* NextNode_a8fa40(Node_a8fa40* old, Cells_a8fa40* table)
{
    Node_a8fa40* cur = old->mpNext;
    if (!cur) {
        uint32_t bucket = static_cast<uint32_t>(((old->mnX & 0xf) << 4) | (old->mnY & 0xf)) %
                          static_cast<uint32_t>(table->mpBucketsEnd - table->mpBucketsBegin);
        while (!cur && ++bucket < static_cast<uint32_t>(table->mpBucketsEnd - table->mpBucketsBegin)) {
            cur = table->mpBucketsBegin[bucket];
        }
    }
    return cur;
}

OB_FORCEINLINE_a8fa40 void Iterator_a8fa40::Advance()
{
    Node_a8fa40* old = mpNode;
    mpNode = old->mpNext;
    if (!mpNode) {
        uint32_t bucket = static_cast<uint32_t>(((old->mnX & 0xf) << 4) | (old->mnY & 0xf));
        Node_a8fa40** begin = mpTable->mpBucketsBegin;
        bucket %= static_cast<uint32_t>(mpTable->mpBucketsEnd - begin);
        uint32_t count = static_cast<uint32_t>(mpTable->mpBucketsEnd - begin);
        while (!mpNode && ++bucket < count) {
            mpNode = mpTable->mpBucketsBegin[bucket];
        }
    }
}

// The list of city locations at +0x44.
struct Locations_a8fa40 {
    // STUB: 0x007ad7a0
    void Assign(const Locations_a8fa40* source);
};

struct Location_a8fa40 {
    int32_t mnX;
    int32_t mnY;
    int32_t mn8;
};

inline Cells_a8fa40* CellsOf_a8fa40(cSC4Region* region)
{
    return reinterpret_cast<Cells_a8fa40*>(reinterpret_cast<char*>(region) + 0x50);
}

// FUNCTION: 0x004a44e0
bool cSC4Region::QueryInterface(uint32_t riid, void* ppvObj)
{
    if (riid == 1 || riid == 0x89d2be26) {
        *static_cast<cSC4Region**>(ppvObj) = this;
        AddRef();
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004a4510 score 2
void* cSC4Region::Slot04_a8fa40(void* name)
{
    cIGZString* target = &mName;
    return &(*target = *static_cast<cIGZString*>(name));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004a4520 score 2
void* cSC4Region::Slot06_a8fa40(void* name)
{
    cIGZString* target = &mDirectoryName;
    return &(*target = *static_cast<cIGZString*>(name));
}
#endif

// FUNCTION: 0x004a4570
uint32_t cSC4Region::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Slot09_a8fa40();
    delete this;
    return 0;
}

// FUNCTION: 0x004a45a0
void cSC4Region::GetBoundingRect(void* rectArg)
{
    int32_t* rect = static_cast<int32_t*>(rectArg);
    Location_a8fa40* it = static_cast<Location_a8fa40*>(mpLocationsBegin);
    Location_a8fa40* end = static_cast<Location_a8fa40*>(mpLocationsEnd);
    rect[1] = 0x7fffffff;
    rect[0] = 0x7fffffff;
    rect[2] = -0x7fffffff - 1;
    rect[3] = -0x7fffffff - 1;
    for (; it != end; ++it) {
        int32_t x = it->mnX;
        rect[0] = std::min(rect[0], x);
        int32_t y = it->mnY;
        rect[1] = std::min(rect[1], y);
        int32_t x2 = it->mnX;
        rect[2] = std::max(rect[2], x2);
        int32_t y2 = it->mnY;
        rect[3] = std::max(rect[3], y2);
    }
    if (rect[2] - rect[0] <= 0 || rect[3] - rect[1] <= 0) {
        rect[0] = 0;
        rect[1] = 0;
        rect[2] = 0;
        rect[3] = 0;
    }
}

// FUNCTION: 0x004a4930
void* cSC4Region::GetCity(int32_t x, int32_t y)
{
    Point_a8fa40 key;
    key.mnX = x;
    key.mnY = y;
    void* node = CellsOf_a8fa40(this)->Find(&key);
    if (node) {
        return *reinterpret_cast<void**>(static_cast<char*>(node) + 0xc);
    }
    return 0;
}

// FUNCTION: 0x004a4c20
void cSC4Region::GetCityLocations(void* out)
{
    static_cast<Locations_a8fa40*>(out)->Assign(reinterpret_cast<Locations_a8fa40*>(&mpLocationsBegin));
}

// GLOBAL: 0x00b217b0
extern uint32_t gnB217b0[];
// GLOBAL: 0x00b217b8
extern bool gbB217b8;

// FUNCTION: 0x004a4ca0
uint32_t cSC4Region::GetBaseTerrainHeight()
{
    return gnB217b0[mnBaseTerrainType];
}

// FUNCTION: 0x004a4cc0
void cSC4Region::GetWaterPrefs(void* first, void* second)
{
    *static_cast<uint8_t*>(first) = static_cast<uint8_t>(mnWaterPref1);
    *static_cast<uint8_t*>(second) = static_cast<uint8_t>(mnWaterPref2);
}

// FUNCTION: 0x004a6c80
bool cSC4Region::Init()
{
    if (!mbInitialized) {
        mbInitialized = true;
        if (!gbB217b8) {
            gbB217b8 = true;
        }
        LoadConfig();
        LoadCityLocations();
        LoadCities();
        MoveOverflowCitiesToDownloadDirectory();
    }
    return mnCityCount != 0;
}

// STUB: 0x0091a1a6
void Fn0091a1a6(cIGZString* path);   // removes the file
// STUB: 0x005dc220
bool Fn005dc220(cIGZString* path, cISC4RegionalCity_a8fa40** city);   // reads a regional city from its file

// FUNCTION: 0x004a4b50
void cSC4Region::RemoveCity(void* holderArg)
{
    Holder_a8fa40** ppHolder = static_cast<Holder_a8fa40**>(holderArg);
    cISC4RegionalCity_a8fa40* city = (*ppHolder)->mpCity;
    if (city) {
        city->AddRef();
    }
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    city->GetPosition(&x, &y);
    city->GetCitySize(&width, &height);
    for (int32_t i = 0; i < width; ++i) {
        for (int32_t j = 0; j < height; ++j) {
            Point_a8fa40 key;
            key.mnX = i + x;
            key.mnY = j + y;
            CellsOf_a8fa40(this)->Erase(&key);
        }
    }
    city->Shutdown();
    delete *ppHolder;
    city->Release();
}

#ifdef OB_DRAFTS
// CLOSE: 0x004a5120 score 6
void cSC4Region::DeleteCity(void* holderArg)
{
    Holder_a8fa40** ppHolder = static_cast<Holder_a8fa40**>(holderArg);
    cISC4RegionalCity_a8fa40* city = (*ppHolder)->mpCity;
    if (city) {
        city->AddRef();
    }
    {
        cRZString path;
        cIGZString* p = &path;
        city->GetCitySaveFilePath(*p);
        RemoveCity(holderArg);
        Fn0091a1a6(p);
    }
    city->Release();
}
#endif

// FUNCTION: 0x004a5030
void cSC4Region::ReloadCity(void* holderArg)
{
    Holder_a8fa40** ppHolder = static_cast<Holder_a8fa40**>(holderArg);
    cRZString path;
    (*ppHolder)->mpCity->GetCitySaveFilePath(path);
    RemoveCity(holderArg);
    cISC4RegionalCity_a8fa40* city = 0;
    if (Fn005dc220(&path, &city)) {
        city->SetCitySaveFilePath(path);
        Slot12_a8fa40(city);
        int32_t x;
        int32_t y;
        city->GetPosition(&x, &y);
        *ppHolder = static_cast<Holder_a8fa40*>(GetCity(x, y));
    }
    if (city) {
        city->Release();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x004a4f00 score 108
void cSC4Region::Slot12_a8fa40(void* cityArg)
{
    cISC4RegionalCity_a8fa40* city = static_cast<cISC4RegionalCity_a8fa40*>(cityArg);
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    city->GetPosition(&x, &y);
    city->GetCitySize(&width, &height);
    Holder_a8fa40* holder = new Holder_a8fa40(city);
    for (int32_t i = 0; i < width; ++i) {
        for (int32_t j = 0; j < height; ++j) {
            int32_t cx = x + i;
            int32_t cy = y + j;
            Iterator_a8fa40 found = CellsOf_a8fa40(this)->FindInline(cx, cy);
            Holder_a8fa40** slot;
            if (found.mpNode != 0) {
                slot = &found.mpNode->mpValue;
            } else {
                Pair_a8fa40 pair;
                pair.mnX = cx;
                pair.mnY = cy;
                pair.mpValue = 0;
                slot = &CellsOf_a8fa40(this)->FindOrInsert(&pair)->mpValue;
            }
            *slot = holder;
        }
    }
}
#endif

// The service manager and the allocator service it hands out (the global at 0xb207e0 caches it).
struct ServiceManager_a8fa40 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual bool Query(uint32_t clsid, uint32_t iid, void* out);
};
struct Allocator_a8fa40 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void* Alloc(uint32_t size);
    virtual void Free(void* block);
};
struct ServiceRef_a8fa40 {
    Allocator_a8fa40* mp;
    // STUB: 0x00411870
    void Release();
};
// STUB: 0x008793ec
ServiceManager_a8fa40* Fn008793ec();
// GLOBAL: 0x00b207e0
extern Allocator_a8fa40* gpB207e0;

OB_FORCEINLINE_a8fa40 Allocator_a8fa40* AllocatorOf_a8fa40()
{
    if (!gpB207e0) {
        ServiceRef_a8fa40 ref;
        ref.mp = 0;
        ServiceManager_a8fa40* manager = Fn008793ec();
        if (manager) {
            manager->Query(0x3ae4bea3, 0x3ae4beab, &ref.mp);
        }
        gpB207e0 = ref.mp;
        ref.Release();
    }
    return gpB207e0;
}

// The framework's list of references: a sentinel node (the member is its pointer) in a ring of nodes from the
// allocator service; a node is next, previous, then the reference.
// A counted reference to a city.
struct CityRef_a8fa40 {
    cISC4RegionalCity_a8fa40* mpCity;
    explicit CityRef_a8fa40(cISC4RegionalCity_a8fa40* city)
        : mpCity(city)
    {
        if (city) {
            city->AddRef();
        }
    }
    CityRef_a8fa40(const CityRef_a8fa40& other)
        : mpCity(other.mpCity)
    {
        if (mpCity) {
            mpCity->AddRef();
        }
    }
    ~CityRef_a8fa40()
    {
        if (mpCity) {
            mpCity->Release();
        }
    }
};
struct ListNode_a8fa40 {
    ListNode_a8fa40* mpNext;
    ListNode_a8fa40* mpPrev;
    CityRef_a8fa40 mRef;
};
struct List_a8fa40 {
    ListNode_a8fa40* mpHead;
    OB_FORCEINLINE_a8fa40 List_a8fa40()
        : mpHead(0)
    {
        ListNode_a8fa40* node = static_cast<ListNode_a8fa40*>(AllocatorOf_a8fa40()->Alloc(sizeof(ListNode_a8fa40)));
        node->mpNext = node;
        node->mpPrev = node;
        mpHead = node;
    }
    // STUB: 0x00411df0
    void Clear();
    OB_FORCEINLINE_a8fa40 ~List_a8fa40()
    {
        Clear();
        ListNode_a8fa40* head = mpHead;
        AllocatorOf_a8fa40()->Free(head);
    }
};

struct TutorialRegistry_a8fa40 {
    // STUB: 0x004b5d80
    void SetActive(int32_t guid, bool active);
};
struct cISC4App_a8fa40 {
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
    virtual void* GetPathProvider();
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
    virtual void Pad48();
    virtual TutorialRegistry_a8fa40* GetTutorialRegistry();
};
// GLOBAL: 0x00b43c94
extern cISC4App_a8fa40* gpB43c94;

struct ResourceKey_a8fa40 {
    uint32_t mnType;
    uint32_t mnGroup;
    int32_t mnInstance;
};
// STUB: 0x005dbdc0
int32_t Fn005dbdc0(const ResourceKey_a8fa40* key, cIGZString* path);   // reads a binary record from a file

// FUNCTION: 0x004a5400
bool cSC4Region::ResetTutorialCity(int32_t guid)
{
    if (guid == -1) {
        return false;
    }
    cRZString path;
    cRZString unused;
    int32_t result = 0;
    List_a8fa40 cities;
    Slot17_a8fa40(&cities);
    ListNode_a8fa40* end = cities.mpHead;
    for (ListNode_a8fa40* node = end->mpNext; node != end; node = node->mpNext) {
        cISC4RegionalCity_a8fa40* city = node->mRef.mpCity;
        if (city->GetTutorialGUID() == guid) {
            city->GetCitySaveFilePath(path);
            ResourceKey_a8fa40 key;
            key.mnType = 0x6a5b7bf5;
            key.mnGroup = 0x6a5b7b57;
            key.mnInstance = guid;
            result = Fn005dbdc0(&key, &path);
            if (result != -1) {
                int32_t x;
                int32_t y;
                city->GetPosition(&x, &y);
                Holder_a8fa40* holder = static_cast<Holder_a8fa40*>(GetCity(x, y));
                if (holder) {
                    ReloadCity(&holder);
                    holder->mpCity->SetTutorialGUID(guid);
                }
                TutorialRegistry_a8fa40* registry = gpB43c94->GetTutorialRegistry();
                registry->SetActive(guid, true);
            }
            break;
        }
    }
    return result == -1;
}

// A set of city pointers (an STL red-black tree in the original): a header node and a count.
struct TreeNode_a8fa40 {
    uint8_t mnColor;
    TreeNode_a8fa40* mpParent;
    TreeNode_a8fa40* mpLeft;
    TreeNode_a8fa40* mpRight;
    cISC4RegionalCity_a8fa40* mpValue;
};
// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);
// STUB: 0x0090cf63
void Fn0090cf63(void* block);
struct TreeResult_a8fa40 {
    TreeNode_a8fa40* mpNode;
    bool mbInserted;
};
struct Tree_a8fa40 {
    TreeNode_a8fa40* mpHeader;
    uint32_t mnCount;
    OB_FORCEINLINE_a8fa40 Tree_a8fa40()
        : mpHeader(0)
        , mnCount(0)
    {
        TreeNode_a8fa40* header = static_cast<TreeNode_a8fa40*>(Fn0090cf54(sizeof(TreeNode_a8fa40)));
        mpHeader = header;
        header->mnColor = 0;
        header->mpParent = 0;
        header->mpLeft = header;
        header->mpRight = header;
    }
    // STUB: 0x0049a050
    void Insert(uint32_t* result, cISC4RegionalCity_a8fa40* const* value);
    // STUB: 0x004a4660
    void EraseFrom(TreeNode_a8fa40* node);
    OB_FORCEINLINE_a8fa40 ~Tree_a8fa40()
    {
        if (mnCount != 0) {
            TreeNode_a8fa40* node = mpHeader->mpParent;
            while (node) {
                EraseFrom(node->mpRight);
                TreeNode_a8fa40* left = node->mpLeft;
                Fn0090cf63(node);
                node = left;
            }
            mpHeader->mpLeft = mpHeader;
            mpHeader->mpParent = 0;
            mpHeader->mpRight = mpHeader;
            mnCount = 0;
        }
        if (mpHeader) {
            Fn0090cf63(mpHeader);
        }
    }
};

#ifdef OB_DRAFTS
// CLOSE: 0x004a4ce0 score 247
void cSC4Region::Slot17_a8fa40(void* outArg)
{
    List_a8fa40* out = static_cast<List_a8fa40*>(outArg);
    out->Clear();
    Tree_a8fa40 cities;
    Iterator_a8fa40 first = CellsOf_a8fa40(this)->Begin();
    Node_a8fa40* cell = first.mpNode;
    Cells_a8fa40* table = first.mpTable;
    for (; cell != 0; cell = NextNode_a8fa40(cell, table)) {
        cISC4RegionalCity_a8fa40* key = cell->mpValue->mpCity;
        uint32_t result[2];
        cities.Insert(result, &key);
    }
    TreeNode_a8fa40* header = cities.mpHeader;
    for (TreeNode_a8fa40* node = header->mpLeft; node != header;) {
        CityRef_a8fa40 ref(node->mpValue);
        ListNode_a8fa40* head = out->mpHead;
        ListNode_a8fa40* item = static_cast<ListNode_a8fa40*>(AllocatorOf_a8fa40()->Alloc(sizeof(ListNode_a8fa40)));
        new (&item->mRef) CityRef_a8fa40(ref);
        item->mpNext = head;
        item->mpPrev = head->mpPrev;
        head->mpPrev->mpNext = item;
        head->mpPrev = item;
        TreeNode_a8fa40* next = node->mpRight;
        if (next) {
            node = next;
            while (node->mpLeft) {
                node = node->mpLeft;
            }
        } else {
            next = node->mpParent;
            if (node == next->mpRight) {
                do {
                    node = next;
                    next = next->mpParent;
                } while (node == next->mpRight);
            }
            if (node->mpRight != next) {
                node = next;
            }
        }
    }
}
#endif

// STUB: 0x005dbd40
uint32_t Fn005dbd40();   // a fresh city serial number
// STUB: 0x005dc790
void Fn005dc790(cIGZString* name, uint32_t serial, cIGZString* path);   // the save path for a city
// STUB: 0x0091a225
bool Fn0091a225(cIGZString* from, cIGZString* to);   // renames a file
// STUB: 0x0091a035
void Fn0091a035(cIGZString* path, uint32_t attribute, bool on);   // sets a file attribute
// STUB: 0x005dc2e0
void Fn005dc2e0(cIGZString* path, cISC4RegionalCity_a8fa40* city);   // writes a regional city to its file

#ifdef OB_DRAFTS
// CLOSE: 0x004a7200 score 276
bool cSC4Region::MoveCity(void* other, void* cityArg, int32_t x, int32_t y)
{
    cISC4RegionalCity_a8fa40* city = static_cast<cISC4RegionalCity_a8fa40*>(cityArg);
    if (other == this) {
        other = 0;
    }
    Holder_a8fa40* holder = static_cast<Holder_a8fa40*>(GetCity(x, y));
    if (holder) {
        if (holder->mpCity == city) {
            return true;
        }
        DeleteCity(&holder);
    }
    cRZString oldPath;
    cRZString newPath;
    cRZString name;
    city->GetCitySaveFilePath(oldPath);
    city->GetCityName(name);
    uint32_t serial = city->GetCitySerialNumber();
    Iterator_a8fa40 first = CellsOf_a8fa40(this)->Begin();
    Iterator_a8fa40 end(0, CellsOf_a8fa40(this));
    uint32_t spare = Fn005dbd40();
    for (;;) {
        Iterator_a8fa40 it(first.mpNode, first.mpTable);
        while (it.mpNode != end.mpNode) {
            if (it.mpNode->mpValue->mpCity->GetCitySerialNumber() == serial) {
                serial = spare;
                --spare;
                break;
            }
            it.Advance();
        }
        if (it.mpNode == end.mpNode) {
            break;
        }
    }
    if (other) {
        static_cast<cSC4Region*>(other)->Slot09_a8fa40();
    }
    Slot09_a8fa40();
    bool result = true;
    if (other == this) {
        newPath.assign(oldPath.begin(), oldPath.end());
    } else {
        Fn005dc790(&name, serial, &newPath);
        if (!Fn0091a225(&oldPath, &newPath)) {
            result = false;
            Init();
            return result;
        }
    }
    Fn0091a035(&newPath, 2, true);
    cISC4RegionalCity_a8fa40* loaded = 0;
    if (Fn005dc220(&newPath, &loaded)) {
        loaded->SetCitySerialNumber(serial);
        loaded->SetPosition(x, y, true);
        Fn005dc2e0(&newPath, loaded);
        loaded->Shutdown();
        loaded->Release();
    } else {
        result = false;
    }
    Init();
    return result;
}
#endif

// STUB: 0x0091bf93
void Fn0091bf93(cIGZString* path, bool recursive);   // removes a directory
// GLOBAL: 0x00b0954c
extern const char* gpszB0954c;
// GLOBAL: 0x00b09564
extern const char* gpszB09564;

// The path provider behind slot 34 of the application object: its slot 5 gives a path.
struct PathProvider_a8fa40 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual cIGZString* GetPath();
};

#ifdef OB_DRAFTS
// CLOSE: 0x004a65a0 score 110
void cSC4Region::Delete()
{
    while (mnCityCount != 0) {
        Holder_a8fa40* holder = CellsOf_a8fa40(this)->BeginInline().mpNode->mpValue;
        DeleteCity(&holder);
    }
    PathProvider_a8fa40* paths = static_cast<PathProvider_a8fa40*>(gpB43c94->GetPathProvider());
    cRZString directory(*paths->GetPath());
    directory.append(mDirectoryName + '\\');
    cRZString first(directory + gpszB0954c);
    cRZString second(directory + gpszB09564);
    Fn0091a1a6(&first);
    Fn0091a1a6(&second);
    Fn0091bf93(&directory, true);
    Slot09_a8fa40();
}
#endif

// The settings-file reader (class cUnk00acf150 elsewhere): the calls here are direct, so each is a STUB at its own
// address.
struct IniFile_a8fa40 {
    uint8_t mStorage[0x3c];
    // STUB: 0x0091cee3
    void Open(cIGZString* path);
    // STUB: 0x0091cde3
    void Close();
    ~IniFile_a8fa40()
    {
        Close();
    }
    // STUB: 0x0091cbb3
    bool ReadEntry(const cIGZString& section, const cIGZString& key, cIGZString& value);
    // STUB: 0x0091c8d2
    bool ReadNumber(const cIGZString& section, const cIGZString& key, int32_t* value);
    // STUB: 0x0091d168
    bool WriteEntry(const cIGZString& section, const cIGZString& key, const cIGZString& value);
    // STUB: 0x0091c6b3
    bool WriteNumber(const cIGZString& section, const cIGZString& key, uint32_t value);
};
// The string assignment as the original calls it: out of line.
struct StringAssign_a8fa40 {
    // STUB: 0x00424380
    cRZString& Assign(const cRZString& other);
};

// A localised string made from a (group, instance) pair: built by a function elsewhere, then used as a string.
struct LocalString_a8fa40 {
    uint8_t mStorage[0x20];
    // STUB: 0x00603580
    LocalString_a8fa40* Construct(uint32_t group, uint32_t instance, bool flag);
};
// STUB: 0x0090fcef
uint32_t Fn0090fcef(const char* text);   // hexadecimal text to a number
// GLOBAL: 0x00b09550
extern const char* gpszB09550;
// GLOBAL: 0x00b09554
extern const char* gpszB09554;
// GLOBAL: 0x00b09558
extern const char* gpszB09558;
// GLOBAL: 0x00b0955c
extern const char* gpszB0955c;
// GLOBAL: 0x00b09560
extern const char* gpszB09560;

// FUNCTION: 0x004a6cd0
void cSC4Region::LoadConfig()
{
    PathProvider_a8fa40* paths = static_cast<PathProvider_a8fa40*>(gpB43c94->GetPathProvider());
    cRZString iniPath(*paths->GetPath());
    iniPath.append(mDirectoryName + '\\');
    iniPath.append(gpszB0954c);
    IniFile_a8fa40 ini;
    ini.Open(&iniPath);
    cRZString value;
    bool found = ini.ReadEntry(cRZString(gpszB09550), cRZString(gpszB09554), value);
    if (found && !value.empty()) {
        if (value[0] == '#') {
            uint32_t id = Fn0090fcef(value.c_str() + 1);
            if (id != 0) {
                LocalString_a8fa40 local;
                cRZString* text = reinterpret_cast<cRZString*>(local.Construct(0x6a231eaa, id, true));
                std::string* chars = text;
                mName.assign(chars->begin(), chars->end());
                reinterpret_cast<cRZString*>(&local)->cRZString::~cRZString();
                goto nameDone;
            }
        }
        reinterpret_cast<StringAssign_a8fa40*>(&mName)->Assign(value);
    }
nameDone:
    int32_t number;
    bool read = ini.ReadNumber(cRZString(gpszB09550), cRZString(gpszB09558), &number);
    if (read && number >= 0 && number < 2) {
        mnBaseTerrainType = number;
    }
    read = ini.ReadNumber(cRZString(gpszB09550), cRZString(gpszB0955c), &number);
    if (read && number >= 0 && number < 0xff) {
        mnWaterPref1 = number;
    }
    read = ini.ReadNumber(cRZString(gpszB09550), cRZString(gpszB09560), &number);
    if (read && number >= 0 && number < 0xff) {
        mnWaterPref2 = number;
    }
}

// The list at +0x40 of the references to the region's cities (the member is the sentinel node's pointer).
struct CityList_a8fa40 {
    ListNode_a8fa40* mpHead;
    // STUB: 0x00411df0
    void Clear();
};
// STUB: 0x00919f17
bool Fn00919f17(cIGZString* path, uint32_t attribute);   // tests a file attribute

#ifdef OB_DRAFTS
// CLOSE: 0x004a5be0 score 180
bool cSC4Region::Slot09_a8fa40()
{
    if (!mbInitialized) {
        return true;
    }
    mbInitialized = false;
    while (mnCityCount != 0) {
        Holder_a8fa40* holder = CellsOf_a8fa40(this)->BeginInline().mpNode->mpValue;
        RemoveCity(&holder);
    }
    CityList_a8fa40* cities = reinterpret_cast<CityList_a8fa40*>(&mpCityList);
    ListNode_a8fa40* end = cities->mpHead;
    for (ListNode_a8fa40* node = end->mpNext; node != end; node = node->mpNext) {
        node->mRef.mpCity->Shutdown();
    }
    cities->Clear();
    PathProvider_a8fa40* paths = static_cast<PathProvider_a8fa40*>(gpB43c94->GetPathProvider());
    cRZString iniPath(*paths->GetPath());
    iniPath.append(mDirectoryName + '\\');
    iniPath.append(gpszB0954c);
    if (!Fn00919f17(&iniPath, 2)) {
        Fn0091a035(&iniPath, 2, true);
    }
    IniFile_a8fa40 ini;
    ini.Open(&iniPath);
    ini.WriteEntry(cRZString(gpszB09550), cRZString(gpszB09554), mName);
    ini.WriteNumber(cRZString(gpszB09550), cRZString(gpszB09558), mnBaseTerrainType);
    ini.WriteNumber(cRZString(gpszB09550), cRZString(gpszB0955c), mnWaterPref1);
    ini.WriteNumber(cRZString(gpszB09550), cRZString(gpszB09560), mnWaterPref2);
    return true;
}
#endif
