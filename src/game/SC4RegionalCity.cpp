#include "classes/cSC4RegionalCity.h"
#include "common/compiler.h"
#include "game/Globals.h"
#include "gzcom/cIGZString.h"
#include "gzcom/cRZString.h"

// Per-commodity record of the map at +0x180 (key: the commodity id).
struct CommodityStats_a8fb20 {
    double mdProduced;
    double mdDemanded;
    double mdExported;
    double mdImported;
    double mdCostPerUnit;
};

// The std::map<long, CommodityStats> at +0x180.
struct StatsMap_a8fb20 {
    // STUB: 0x004a9b40
    CommodityStats_a8fb20& operator[](const int32_t& key);
};


// The std::map<uint32_t, uint32_t> / set tree nodes (STLport): colour, parent, left, right, key, value.
struct RbNodeUU_a8fb20 {
    uint32_t mColor;
    RbNodeUU_a8fb20* mpParent;
    RbNodeUU_a8fb20* mpLeft;
    RbNodeUU_a8fb20* mpRight;
    uint32_t mKey;
    uint32_t mValue;
};

// The iterator find() returns through a hidden pointer.
struct FindResult_a8fb20 {
    RbNodeUU_a8fb20* mpNode;
    FindResult_a8fb20() : mpNode(0) {}
};

// A std::map<uint32_t, uint32_t> (the tree object: header pointer first).
struct TreeUU_a8fb20 {
    RbNodeUU_a8fb20* mpHeader;
    uint32_t mnCount;
    uint32_t mnPad;
    // STUB: 0x00497520
    FindResult_a8fb20 find(const uint32_t& key) const;
    // STUB: 0x00497a00
    uint32_t& operator[](const uint32_t& key);
    void Erase(RbNodeUU_a8fb20* x);
};

// A tree whose nodes own a heap block through the value pointer.
struct TreeSet_a8fb20 {
    RbNodeUU_a8fb20* mpHeader;
    void Erase(RbNodeUU_a8fb20* x);
};

// A tree whose nodes own a heap block through the value pointer.
struct TreeOwn_a8fb20 {
    RbNodeUU_a8fb20* mpHeader;
    void Erase(RbNodeUU_a8fb20* x);
};

// A std::vector copy-assigned from another.
struct VecView_a8fb20 {
    uint32_t mData[3];
    // STUB: 0x007ad7a0
    VecView_a8fb20& operator=(const VecView_a8fb20& other);
};

// A tree node whose value is a std::vector.
struct RbNodeIV_a8fb20 {
    uint32_t mPad[5];
    VecView_a8fb20 mValue;
};

struct FindResultIV_a8fb20 {
    RbNodeIV_a8fb20* mpNode;
    FindResultIV_a8fb20() : mpNode(0) {}
};

// A std::set<int32_t> tree.
struct TreeInt_a8fb20 {
    RbNodeIV_a8fb20* mpHeader;
    uint32_t mnCount;
    uint32_t mnPad;
    // STUB: 0x006c0030
    FindResultIV_a8fb20 find(const int32_t& key) const;
};

// A std::list node: next, prev, then the element.
struct ListNode_a8fb20 {
    ListNode_a8fb20* mpNext;
    ListNode_a8fb20* mpPrev;
    void* mpItem;
};

// A std::list (the object is its header pointer).
struct ListView_a8fb20 {
    ListNode_a8fb20* mpHeader;
    // STUB: 0x00411d70
    void Clear();
    // STUB: 0x00421660
    void Clear421660();
    // STUB: 0x004a86f0
    void InsertRange(ListNode_a8fb20* pos, ListNode_a8fb20* first, ListNode_a8fb20* last, ListNode_a8fb20** result);
    // STUB: 0x004a9150
    void Assign(const ListView_a8fb20& other);
};

// The neighbour deal behind a list element: the cell and notify slots used here.
struct Deal_a8fb20 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void SetCityCell(int32_t x, int32_t z);
    virtual void GetCityCell(int32_t* x, int32_t* z);
    virtual void SetOtherCell(int32_t x, int32_t z);
    virtual void GetOtherCell(int32_t* x, int32_t* z);
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
    virtual void Notify(uint32_t, uint32_t);
};

// This object seen through the commodity slots that take a double.
struct CommodityView_a8fb20 {
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
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual void SetExported(uint32_t commodity, double amount);
    virtual void Pad56();
    virtual void SetImported(uint32_t commodity, double amount);
};

// STUB: 0x0090cf63
void StlDelete_a8fb20(void* p);

// A 16-byte record the list sorts (a connection change): four dwords.
struct Rec16_a8fb20 {
    uint32_t mA;
    uint32_t mB;
    uint32_t mC;
    uint32_t mD;
};

typedef bool (*Less16_a8fb20)(const Rec16_a8fb20*, const Rec16_a8fb20*);

// A neighbour connection behind a list element: slot 5 the type, slot 6 the cell.
struct Connection_a8fb20 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual uint32_t GetType();
    virtual void GetConnectionCell(int32_t* x, int32_t* z);
};

// The city interface: the slots SetupCity uses.
struct City_a8fb20 {
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
    virtual void SetCitySaveFilePath(const cIGZString* path);
    virtual void Pad12();
    virtual void SetCityName(const cIGZString* name);
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void SetMayorName(const cIGZString* name);
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void SetDifficultyLevel(uint32_t level);
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
    virtual void Pad65();
    virtual void Pad66();
    virtual void Pad67();
    virtual void Pad68();
    virtual void Pad69();
    virtual void Pad70();
    virtual void Pad71();
    virtual void Pad72();
    virtual void Pad73();
    virtual void Pad74();
    virtual void Pad75();
    virtual void Pad76();
    virtual void Pad77();
    virtual void Pad78();
    virtual void Pad79();
    virtual void Pad80();
    virtual void Pad81();
    virtual void Pad82();
    virtual void Pad83();
    virtual void Pad84();
    virtual void Pad85();
    virtual void Pad86();
    virtual void Pad87();
    virtual void SetSize(float width, float depth);
};

// STUB: 0x005dc790
void Fn005dc790_a8fb20(cIGZString* name, uint32_t serial, cIGZString* path);   // the save path for a city

// GLOBAL: 0x00b217d8
extern bool gbStaticInit_a8fb20;

// FUNCTION: 0x004a7580
float cSC4RegionalCity::GetTaxRate(uint32_t purpose)
{
    switch (purpose) {
    case 0x1010: return mfTax60;
    case 0x1020: return mfTax64;
    case 0x1030: return mfTax68;
    case 0x3110: return mfTax6c;
    case 0x3120: return mfTax70;
    case 0x3130: return mfTax74;
    case 0x3320: return mfTax78;
    case 0x3330: return mfTax7c;
    case 0x4100: return mfTax80;
    case 0x4200: return mfTax84;
    case 0x4300: return mfTax88;
    case 0x4400: return mfTax8c;
    }
    return 7.0f;
}

// FUNCTION: 0x004a7650
void cSC4RegionalCity::SetBudget(uint32_t lo, uint32_t)
{
    mdBudget = *reinterpret_cast<double*>(&lo);
}

// FUNCTION: 0x004a7670
void cSC4RegionalCity::SetIncome(uint32_t lo, uint32_t)
{
    mdIncome = *reinterpret_cast<double*>(&lo);
}

#ifdef OB_DRAFTS
// CLOSE: 0x004a7680 score 18
float cSC4RegionalCity::GetCommodityBalance(uint32_t commodity)
{
    double inflow = GetImported(commodity) + GetProduced(commodity);
    return inflow - (GetExported(commodity) + GetDemanded(commodity));
}
#endif

// FUNCTION: 0x004a76e0
bool cSC4RegionalCity::IsTutorial()
{
    return GetTutorialGUID() != 0xffffffff;
}

// FUNCTION: 0x004a9ee0
float cSC4RegionalCity::GetExported(uint32_t commodity)
{
    return (*reinterpret_cast<StatsMap_a8fb20*>(mTree180))[reinterpret_cast<int32_t&>(commodity)].mdExported;
}

// FUNCTION: 0x004a9f00
void cSC4RegionalCity::SetExported(uint32_t commodity, uint32_t lo, uint32_t)
{
    double& v = *reinterpret_cast<double*>(&lo);
    if (v < 0.0) {
        v = 0.0;
    }
    (*reinterpret_cast<StatsMap_a8fb20*>(mTree180))[reinterpret_cast<int32_t&>(commodity)].mdExported = v;
}

// FUNCTION: 0x004a9f40
float cSC4RegionalCity::GetImported(uint32_t commodity)
{
    return (*reinterpret_cast<StatsMap_a8fb20*>(mTree180))[reinterpret_cast<int32_t&>(commodity)].mdImported;
}

// FUNCTION: 0x004a9f60
void cSC4RegionalCity::SetImported(uint32_t commodity, uint32_t lo, uint32_t)
{
    double& v = *reinterpret_cast<double*>(&lo);
    if (v < 0.0) {
        v = 0.0;
    }
    (*reinterpret_cast<StatsMap_a8fb20*>(mTree180))[reinterpret_cast<int32_t&>(commodity)].mdImported = v;
}

// FUNCTION: 0x004a9fa0
float cSC4RegionalCity::GetProduced(uint32_t commodity)
{
    return (*reinterpret_cast<StatsMap_a8fb20*>(mTree180))[reinterpret_cast<int32_t&>(commodity)].mdProduced;
}

// FUNCTION: 0x004a9fc0
void cSC4RegionalCity::SetProduced(uint32_t commodity, uint32_t lo, uint32_t)
{
    double& v = *reinterpret_cast<double*>(&lo);
    if (v < 0.0) {
        v = 0.0;
    }
    (*reinterpret_cast<StatsMap_a8fb20*>(mTree180))[reinterpret_cast<int32_t&>(commodity)].mdProduced = v;
}

// FUNCTION: 0x004aa000
float cSC4RegionalCity::GetDemanded(uint32_t commodity)
{
    return (*reinterpret_cast<StatsMap_a8fb20*>(mTree180))[reinterpret_cast<int32_t&>(commodity)].mdDemanded;
}

// FUNCTION: 0x004aa020
void cSC4RegionalCity::SetDemanded(uint32_t commodity, uint32_t lo, uint32_t)
{
    double& v = *reinterpret_cast<double*>(&lo);
    if (v < 0.0) {
        v = 0.0;
    }
    (*reinterpret_cast<StatsMap_a8fb20*>(mTree180))[reinterpret_cast<int32_t&>(commodity)].mdDemanded = v;
}

// FUNCTION: 0x004aa060
float cSC4RegionalCity::GetCostPerUnit(uint32_t commodity)
{
    return (*reinterpret_cast<StatsMap_a8fb20*>(mTree180))[reinterpret_cast<int32_t&>(commodity)].mdCostPerUnit;
}

// FUNCTION: 0x004aa080
void cSC4RegionalCity::SetCostPerUnit(uint32_t commodity, uint32_t lo, uint32_t)
{
    double& v = *reinterpret_cast<double*>(&lo);
    if (v < 0.0) {
        v = 0.0;
    }
    (*reinterpret_cast<StatsMap_a8fb20*>(mTree180))[reinterpret_cast<int32_t&>(commodity)].mdCostPerUnit = v;
}

// FUNCTION: 0x004aba70
void cSC4RegionalCity::GetPosition(uint32_t x, uint32_t y)
{
    *OB_PTR(int32_t, x) = mnPosX;
    *OB_PTR(int32_t, y) = mnPosY;
}

// FUNCTION: 0x004aba90
void cSC4RegionalCity::GetCitySize(uint32_t x, uint32_t y)
{
    *OB_PTR(int32_t, x) = mnSizeX;
    *OB_PTR(int32_t, y) = mnSizeY;
}

// FUNCTION: 0x004abab0
void cSC4RegionalCity::SetCitySize(uint32_t x, uint32_t y)
{
    mnSizeX = x;
    mnSizeY = y;
}

// FUNCTION: 0x004abaf0
bool cSC4RegionalCity::GetOriginalLanguageAndCountry(uint32_t language, uint32_t country)
{
    *OB_PTR(int32_t, language) = mnOrigLanguage;
    *OB_PTR(int32_t, country) = mnOrigCountry;
    return true;
}

// FUNCTION: 0x004abb10
bool cSC4RegionalCity::GetLastLanguageAndCountry(uint32_t language, uint32_t country)
{
    *OB_PTR(int32_t, language) = mnLastLanguage;
    *OB_PTR(int32_t, country) = mnLastCountry;
    return true;
}

// FUNCTION: 0x004abc40
bool cSC4RegionalCity::GetEstablished()
{
    return mbEstablished != 0;
}

// FUNCTION: 0x004abc60
void cSC4RegionalCity::GetWorldPosition(uint32_t x, uint32_t y)
{
    *OB_PTR(float, x) = mfWorldX;
    *OB_PTR(float, y) = mfWorldY;
}

// FUNCTION: 0x004abc80
void cSC4RegionalCity::SetWorldPosition(uint32_t x, uint32_t y)
{
    mfWorldX = *reinterpret_cast<float*>(&x);
    mfWorldY = *reinterpret_cast<float*>(&y);
}

// FUNCTION: 0x004abcc0
uint32_t cSC4RegionalCity::GetWorldHemisphere()
{
    return mfWorldY > 0.0f ? 1 : 2;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004a7800 score 1
void cSC4RegionalCity::Slot02_a8fb20()
{
    if (mnRefCount > 1) {
        mnRefCount--;
        return;
    }
    Shutdown();
    delete this;
}
#endif

// FUNCTION: 0x004a8500
uint32_t cSC4RegionalCity::GetPopulation(uint32_t city)
{
    TreeUU_a8fb20* tree = reinterpret_cast<TreeUU_a8fb20*>(mTree3c);
    FindResult_a8fb20 it = tree->find(city);
    if (it.mpNode != tree->mpHeader) {
        return it.mpNode->mValue;
    }
    return 0;
}

// FUNCTION: 0x004a8a40
void cSC4RegionalCity::Slot72_a8fb20(uint32_t key, uint32_t out)
{
    TreeInt_a8fb20* tree = reinterpret_cast<TreeInt_a8fb20*>(mTree194);
    FindResultIV_a8fb20 it = tree->find(reinterpret_cast<int32_t&>(key));
    if (it.mpNode != tree->mpHeader) {
        *OB_PTR(VecView_a8fb20, out) = it.mpNode->mValue;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x004a8db0 score 14
void cSC4RegionalCity::GetAllConnections(uint32_t out)
{
    ListView_a8fb20* list = OB_PTR(ListView_a8fb20, out);
    list->Clear();
    ListNode_a8fb20* last = OB_PTR(ListNode_a8fb20, mpConnections90);
    ListNode_a8fb20* first = last->mpNext;
    ListNode_a8fb20* pos = list->mpHeader;
    ListNode_a8fb20* result;
    list->InsertRange(pos, first, last, &result);
}
#endif

// FUNCTION: 0x004a90d0
bool cSC4RegionalCity::SetLocalDeals(uint32_t deals)
{
    ListView_a8fb20* mine = reinterpret_cast<ListView_a8fb20*>(&mpDeals190);
    mine->Clear421660();
    ExtractLocalDeals(OB_PTR(void, deals), mine, false);
    UpdateImportExport();
    return true;
}

// FUNCTION: 0x004a9110
bool cSC4RegionalCity::UpdateLocalDeals()
{
    ListView_a8fb20* extracted = reinterpret_cast<ListView_a8fb20*>(&mpDeals18c);
    ExtractLocalDeals(extracted, &mpDeals190, true);
    ListNode_a8fb20* header = extracted->mpHeader;
    for (ListNode_a8fb20* node = header->mpNext; node != extracted->mpHeader; node = node->mpNext) {
        static_cast<Deal_a8fb20*>(node->mpItem)->Notify(0x80, 0);
    }
    return true;
}

// FUNCTION: 0x004a9820
uint32_t cSC4RegionalCity::GetAllowableExtrapolation(uint32_t city)
{
    uint32_t& limit = (*reinterpret_cast<TreeUU_a8fb20*>(mTree54))[city];
    uint32_t& current = (*reinterpret_cast<TreeUU_a8fb20*>(mTree48))[city];
    int32_t room = limit - current;
    return room > 0 ? room : 0;
}

// FUNCTION: 0x004a9860
void cSC4RegionalCity::ExtrapolateGrowth(uint32_t city, uint32_t growth)
{
    uint32_t* current = &(*reinterpret_cast<TreeUU_a8fb20*>(mTree48))[city];
    *current = static_cast<int32_t>(static_cast<int32_t>(*current) + *reinterpret_cast<float*>(&growth));
}

// FUNCTION: 0x004aa0c0
bool cSC4RegionalCity::GetLocalDeals(uint32_t out)
{
    OB_PTR(ListView_a8fb20, out)->Assign(*reinterpret_cast<ListView_a8fb20*>(&mpDeals190));
    return true;
}

// FUNCTION: 0x004a79a0
void TreeUU_a8fb20::Erase(RbNodeUU_a8fb20* x)
{
    while (x) {
        Erase(x->mpRight);
        RbNodeUU_a8fb20* left = x->mpLeft;
        StlDelete_a8fb20(x);
        x = left;
    }
}

// FUNCTION: 0x004a9c00
void TreeOwn_a8fb20::Erase(RbNodeUU_a8fb20* x)
{
    while (x) {
        Erase(x->mpRight);
        RbNodeUU_a8fb20* left = x->mpLeft;
        if (x->mValue) {
            StlDelete_a8fb20(OB_PTR(void, x->mValue));
        }
        StlDelete_a8fb20(x);
        x = left;
    }
}

// FUNCTION: 0x004a79e0
void TreeSet_a8fb20::Erase(RbNodeUU_a8fb20* x)
{
    while (x) {
        Erase(x->mpRight);
        RbNodeUU_a8fb20* left = x->mpLeft;
        StlDelete_a8fb20(x);
        x = left;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x004a8530 score 27
void cSC4RegionalCity::GetExtrapolatedPopulation(uint32_t city)
{
    TreeUU_a8fb20* tree = reinterpret_cast<TreeUU_a8fb20*>(mTree48);
    FindResult_a8fb20 it = tree->find(city);
    if (it.mpNode == tree->mpHeader) {
        GetPopulation(city);
    }
}
#endif

// FUNCTION: 0x004a7830
bool cSC4RegionalCity::Init()
{
    if (!mbInitialized) {
        mbInitialized = 1;
        if (!gbStaticInit_a8fb20) {
            gbStaticInit_a8fb20 = true;
        }
        cIGZMessageServer2* server = gpB43ccc;
        void* target = reinterpret_cast<char*>(this) + 4;
        server->AddNotification(target, 0x26c63342);
        server->AddNotification(target, 0x26c63343);
        server->AddNotification(target, 0x26d31ec1);
        server->AddNotification(target, 0x26d31ec3);
        server->AddNotification(target, 0xca63d517);
    }
    return true;
}

// FUNCTION: 0x004a78a0
void cSC4RegionalCity::SetupPreferences(uint32_t prefs)
{
    const char* name = mStrD0.c_str();
    char* out = OB_PTR(char, prefs);
    char* dest = out;
    for (;;) {
        char c = *name++;
        *dest++ = c;
        if (!c) {
            break;
        }
    }
    const char* mayor = mStrF8.c_str();
    dest = out + 0x200;
    for (;;) {
        char c = *mayor++;
        *dest++ = c;
        if (!c) {
            break;
        }
    }
    *reinterpret_cast<uint32_t*>(out + 0x400) = mnDifficulty;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004a7b40 score 0 (pointer return in a uint32_t slot: the base declares FindConnection wrongly)
uint32_t cSC4RegionalCity::FindConnection(uint32_t type, uint32_t x, uint32_t z)
{
    ListNode_a8fb20* header = OB_PTR(ListNode_a8fb20, mpConnections90);
    for (ListNode_a8fb20* node = header->mpNext; node != OB_PTR(ListNode_a8fb20, mpConnections90); node = node->mpNext) {
        Connection_a8fb20* connection = static_cast<Connection_a8fb20*>(node->mpItem);
        int32_t cellX;
        int32_t cellZ;
        connection->GetConnectionCell(&cellX, &cellZ);
        if (connection->GetType() == type && cellX == static_cast<int32_t>(x) && cellZ == static_cast<int32_t>(z)) {
            return OB_ADDR(connection);
        }
    }
    return 0;
}
#endif

// FUNCTION: 0x004a8960
void cSC4RegionalCity::SetupCity(uint32_t cityPtr)
{
    City_a8fb20* city = OB_PTR(City_a8fb20, cityPtr);
    city->SetMayorName(&mStrF8);
    city->SetCityName(&mStrD0);
    city->SetDifficultyLevel(mnDifficulty);
    cRZString path;
    Fn005dc790_a8fb20(&mStrD0, 0, &path);
    city->SetCitySaveFilePath(&path);
    float depth = static_cast<float>(mnSizeY << 10);
    float width = static_cast<float>(mnSizeX << 10);
    city->SetSize(width, depth);
}

// FUNCTION: 0x004a7700
void Fn004a7700_a8fb20(Rec16_a8fb20* last, Rec16_a8fb20 value, Less16_a8fb20 less)
{
    Rec16_a8fb20* prev = last - 1;
    while (less(&value, prev)) {
        *last = *prev;
        last = prev;
        --prev;
    }
    *last = value;
}

// FUNCTION: 0x004a7770
void Fn004a7770_a8fb20(Rec16_a8fb20* first, int32_t hole, int32_t top, Rec16_a8fb20 value, Less16_a8fb20 less)
{
    int32_t parent = (hole - 1) / 2;
    while (hole > top && less(&first[parent], &value)) {
        first[hole] = first[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    first[hole] = value;
}

// FUNCTION: 0x004a7a20
void Fn004a7a20_a8fb20(Rec16_a8fb20* first, Rec16_a8fb20* last, uint32_t unused, Less16_a8fb20 less)
{
    for (Rec16_a8fb20* p = first; p != last; ++p) {
        Fn004a7700_a8fb20(p, *p, less);
    }
}

// FUNCTION: 0x004a8470
bool cSC4RegionalCity::Shutdown()
{
    if (mbInitialized) {
        mbInitialized = 0;
        cIGZMessageServer2* server = gpB43ccc;
        void* target = reinterpret_cast<char*>(this) + 4;
        server->RemoveNotification(target, 0x26c63342);
        server->RemoveNotification(target, 0x26c63343);
        server->RemoveNotification(target, 0x26d31ec1);
        server->RemoveNotification(target, 0x26d31ec3);
        server->RemoveNotification(target, 0xca63d517);
        reinterpret_cast<ListView_a8fb20*>(&mpConnections90)->Clear();
        reinterpret_cast<ListView_a8fb20*>(&mpDeals18c)->Clear421660();
        reinterpret_cast<ListView_a8fb20*>(&mpDeals190)->Clear421660();
    }
    return true;
}

// FUNCTION: 0x004aa200
bool cSC4RegionalCity::UpdateImportExport()
{
    CommodityView_a8fb20* view = reinterpret_cast<CommodityView_a8fb20*>(this);
    view->SetImported(1, 0.0);
    view->SetExported(1, 0.0);
    view->SetImported(2, 0.0);
    view->SetExported(2, 0.0);
    view->SetImported(3, 0.0);
    view->SetExported(3, 0.0);
    ListNode_a8fb20* node;
    for (node = OB_PTR(ListNode_a8fb20, mpDeals18c)->mpNext; node != OB_PTR(ListNode_a8fb20, mpDeals18c); node = node->mpNext) {
        UpdateImportExportDeal(node->mpItem);
    }
    for (node = OB_PTR(ListNode_a8fb20, mpDeals190)->mpNext; node != OB_PTR(ListNode_a8fb20, mpDeals190); node = node->mpNext) {
        UpdateImportExportDeal(node->mpItem);
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004a99f0 score 174
void cSC4RegionalCity::SetPosition(uint32_t x, uint32_t z, uint32_t fromImport)
{
    int32_t oldX = mnPosX;
    int32_t oldZ = mnPosY;
    mnPosY = z;
    mnPosX = x;
    if (static_cast<uint8_t>(fromImport)) {
        mbConnectionsChanged = 1;
        Fn004a9720();
        int32_t dx = mnPosX - oldX;
        int32_t dz = mnPosY - oldZ;
        ListNode_a8fb20* node = OB_PTR(ListNode_a8fb20, mpDeals18c)->mpNext;
        while (node != OB_PTR(ListNode_a8fb20, mpDeals18c)) {
            Deal_a8fb20* deal = static_cast<Deal_a8fb20*>(node->mpItem);
            node = node->mpNext;
            int32_t cellZ;
            int32_t cellX;
            deal->GetCityCell(&cellX, &cellZ);
            deal->SetCityCell(dx + cellX, dz + cellZ);
            deal->GetOtherCell(&cellX, &cellZ);
            deal->SetOtherCell(dx + cellX, dz + cellZ);
        }
        node = OB_PTR(ListNode_a8fb20, mpDeals190)->mpNext;
        while (node != OB_PTR(ListNode_a8fb20, mpDeals190)) {
            Deal_a8fb20* deal = static_cast<Deal_a8fb20*>(node->mpItem);
            node = node->mpNext;
            int32_t cellZ;
            int32_t cellX;
            deal->GetCityCell(&cellX, &cellZ);
            deal->SetCityCell(dx + cellX, dz + cellZ);
            deal->GetOtherCell(&cellX, &cellZ);
            deal->SetOtherCell(dx + cellX, dz + cellZ);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004a9970 score 60
void cSC4RegionalCity::Fn004a9970(uint32_t)
{
    TreeUU_a8fb20* src = reinterpret_cast<TreeUU_a8fb20*>(mTree3c);
    TreeUU_a8fb20* dst = reinterpret_cast<TreeUU_a8fb20*>(mTree48);
    RbNodeUU_a8fb20* node = src->mpHeader->mpLeft;
    while (node != src->mpHeader) {
        uint32_t key = node->mKey;
        uint32_t value = node->mValue;
        (*dst)[key] = value;
        RbNodeUU_a8fb20* next = node->mpRight;
        if (next) {
            node = next;
            while (node->mpLeft) {
                node = node->mpLeft;
            }
            next = node;
        } else {
            next = node->mpParent;
            while (node == next->mpRight) {
                node = next;
                next = next->mpParent;
            }
            if (node->mpRight != next) {
                node = next;
            }
            next = node;
        }
        node = next;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004a9890 score 87
void cSC4RegionalCity::Fn004a9890()
{
    TreeUU_a8fb20* src = reinterpret_cast<TreeUU_a8fb20*>(mTree3c);
    TreeUU_a8fb20* dst = reinterpret_cast<TreeUU_a8fb20*>(mTree54);
    RbNodeUU_a8fb20* node = src->mpHeader->mpLeft;
    while (node != src->mpHeader) {
        uint32_t key = node->mKey;
        int32_t population = static_cast<int32_t>(node->mValue);
        float limit;
        if (population > 0) {
            float cap = 1000.0f;
            float scaled = population * 1.1f;
            limit = (scaled < cap) ? scaled : cap;
        } else {
            limit = 0.0f;
        }
        (*dst)[key] = static_cast<int32_t>(limit);
        RbNodeUU_a8fb20* next = node->mpRight;
        if (next) {
            node = next;
            while (node->mpLeft) {
                node = node->mpLeft;
            }
            next = node;
        } else {
            next = node->mpParent;
            while (node == next->mpRight) {
                node = next;
                next = next->mpParent;
            }
            if (node->mpRight != next) {
                node = next;
            }
            next = node;
        }
        node = next;
    }
}
#endif
