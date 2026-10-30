#include "classes/cRZLanguageManager.h"
#include "gzcom/cRZString.h"
#include "classes/cRZLanguageUtility.h"
#include <locale.h>
#ifdef _MSC_VER
#include <mbctype.h>
#define OB_SETMBCP() _setmbcp(_MB_CP_LOCALE)
#else
#define OB_SETMBCP()
#endif

// The Windows call GetCurrentSystemLanguage makes (declared here, imported as the original imported it).
#ifdef _MSC_VER
extern "C" __declspec(dllimport) uint32_t __stdcall GetUserDefaultLCID(void);
#else
extern "C" uint32_t GetUserDefaultLCID(void);
#endif

// The header node of the language set (a red-black tree of numbers), the result of an insert, and the set itself.
struct RbHeader_ad14a0 {
    uint32_t mnColor;
    void* mpParent;
    void* mpLeftmost;
    void* mpRightmost;
};

struct SetPair_ad14a0 {
    void* mpNode;
    bool mbInserted;
};

struct SetRange_ad14a0 {
    void* mpFirst;
    void* mpLast;
};

// STUB: 0x0040d4c0
void* Fn0040d4c0(void* node);
// STUB: 0x00893dec
uint32_t Fn00893dec(void* first, void* last, void* tag);

struct Set_ad14a0 {
    RbHeader_ad14a0* mpHeader;
    uint32_t mnCount;
    uint32_t mnPad;
    // STUB: 0x0094c8f5
    void* Find(const uint32_t* key);
    // STUB: 0x0046c0e0
    void Fn0046c0e0(SetPair_ad14a0* result, const uint32_t* value);
    // STUB: 0x00927d27
    void* Fn00927d27(const uint32_t* key);
    // STUB: 0x00927d4c
    void* Fn00927d4c(const uint32_t* key);
    // STUB: 0x00927cf8
    void Fn00927cf8(void* node);
    // STUB: 0x0065e780
    void Fn0065e780();
    void Fn00927d71(void* first, void* last);
    SetRange_ad14a0* Fn00927dda(SetRange_ad14a0* result, const uint32_t* key);
    // STUB: 0x00927fd8
    uint32_t Fn00927fd8(const uint32_t* key);
    void Fn0065e900(SetPair_ad14a0* result, const uint32_t* value);
};

// The list of numbers the caller hands in.
struct IntList_ad14a0 {
    void* mpNode;
    void Fn00891bad(void** result, void* first, void* last);
    // STUB: 0x00427640
    void PushBack(const uint32_t* value);
    // STUB: 0x0049eaa0
    void Fn0049eaa0(void* node);
};

// FUNCTION: 0x00923ded
bool cRZLanguageManager::QueryInterface(uint32_t riid, void** ppv)
{
    switch (riid) {
    case 0x287fb697:
        *ppv = static_cast<cRZSystemService*>(this);
        break;
    case 0x54b7d5:
        *ppv = this;
        break;
    default:
        return false;
    }
    AddRef();
    return true;
}

// FUNCTION: 0x00923e28
void cRZLanguageManager::Slot10_ad1198()
{
    uint16_t id = static_cast<uint16_t>(GetUserDefaultLCID());
    Slot12_ad1198(id);
}

// 0x00924648 / 0x0092464d / 0x009256ed (Slot21_ad1198, Slot22_ad1198, Slot35_ad1198) are jumps through slots 16, 17 and 34
// with the caller's own arguments: their slots lack the arguments.

#ifdef OB_DRAFTS
// CLOSE: 0x00924652 score 8
bool cRZLanguageManager::Slot14_ad1198(uint32_t language)
{
    uint32_t* p = OB_PTR(uint32_t, language);
    do {
        ++*p;
        if (static_cast<uint8_t>(Slot09_ad1198(*p))) {
            return true;
        }
    } while (*p <= 0x2c);
    ++*p;
    return false;
}
#endif

// FUNCTION: 0x00924aef
uint32_t cRZLanguageManager::Slot23_ad1198(uint32_t language)
{
    if (language == 0) {
        language = mnLanguage;
    }
    if (language == 2) {
        return 1;
    }
    if (language == 0x24 || language == 0x25 || language == 0x26) {
        return 3;
    }
    if (language == 0x27) {
        return 4;
    }
    if (language == 0x28) {
        return 5;
    }
    if (language == 0x29) {
        return 7;
    }
    if (language == 0x2a) {
        return 6;
    }
    if (language == 0x17 || language == 0x19 || language == 0x18) {
        return 0xd;
    }
    return language;
}

// FUNCTION: 0x00924b50
uint32_t cRZLanguageManager::Slot38_ad1198(uint32_t language)
{
    if (language == 0) {
        language = mnLanguage;
    }
    if (language == mnLanguage) {
        return OB_ADDR(mUtility);
    }
    return 0;
}

// FUNCTION: 0x00924b73
bool cRZLanguageManager::Slot43_ad1198(uint32_t value, uint32_t out, uint32_t /*locale*/)
{
    *OB_PTR(uint32_t, out) = value;
    return true;
}

// FUNCTION: 0x00924b82
bool cRZLanguageManager::Slot42_ad1198(uint32_t low, uint32_t high, uint32_t out, uint32_t /*locale*/)
{
    uint32_t* result = OB_PTR(uint32_t, out);
    result[0] = low;
    result[1] = high;
    return true;
}

// FUNCTION: 0x00924b98
bool cRZLanguageManager::Slot45_ad1198(uint32_t value, uint32_t /*b*/, uint32_t out, uint32_t /*locale*/)
{
    *OB_PTR(uint32_t, out) = value;
    return true;
}

// FUNCTION: 0x00924ba7
bool cRZLanguageManager::Slot44_ad1198(uint32_t low, uint32_t high, uint32_t /*c*/, uint32_t out, uint32_t /*locale*/)
{
    uint32_t* result = OB_PTR(uint32_t, out);
    result[0] = low;
    result[1] = high;
    return true;
}

// FUNCTION: 0x00927db5
uint32_t cRZLanguageManager::Slot09_ad1198(uint32_t language)
{
    if (reinterpret_cast<Set_ad14a0*>(mAvailable)->mnCount != 0) {
        Set_ad14a0* set = reinterpret_cast<Set_ad14a0*>(mAvailable);
        if (set->Find(&language) == set->mpHeader) {
            return 0;
        }
    }
    return 1;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00927e04 score 2
void cRZLanguageManager::Slot05_ad1198(uint32_t language)
{
    SetPair_ad14a0 result;
    uint32_t value = language;
    if (value <= 0x2c) {
        reinterpret_cast<Set_ad14a0*>(mAvailable)->Fn0065e900(&result, &value);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00927e28 score 28
void cRZLanguageManager::GetAllAvailableLanguagesIntoIntList(uint32_t list)
{
    IntList_ad14a0* out = OB_PTR(IntList_ad14a0, list);
    void* result;
    out->Fn00891bad(&result, *static_cast<void**>(out->mpNode), out->mpNode);
    Set_ad14a0* set = reinterpret_cast<Set_ad14a0*>(mAvailable);
    for (void* node = set->mpHeader->mpLeftmost; node != set->mpHeader; node = Fn0040d4c0(node)) {
        uint32_t value = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(node) + 0x10);
        out->PushBack(&value);
    }
}
#endif

// FUNCTION: 0x00928bd2
void cRZLanguageManager::Slot06_ad1198(uint32_t language)
{
    uint32_t key = language;
    reinterpret_cast<Set_ad14a0*>(mAvailable)->Fn00927fd8(&key);
}

// The language utility object: constructed by 0x0092847c (cRZLanguageUtility's constructor, thiscall).
struct UtilityView_ad14a0 {
    // STUB: 0x0092847c
    UtilityView_ad14a0* Fn0092847c();
};
struct UtilitySlots_ad14a0 {
    virtual void Pad00_UtilitySlots_ad14a0();
    virtual uint32_t AddRef();
    virtual void Pad02_UtilitySlots_ad14a0();
    virtual void Pad03_UtilitySlots_ad14a0();
    virtual void Pad04_UtilitySlots_ad14a0();
    virtual void Pad05_UtilitySlots_ad14a0();
    virtual void Pad06_UtilitySlots_ad14a0();
    virtual void Pad07_UtilitySlots_ad14a0();
    virtual void Pad08_UtilitySlots_ad14a0();
    virtual void Pad09_UtilitySlots_ad14a0();
    virtual void Pad10_UtilitySlots_ad14a0();
    virtual void Pad11_UtilitySlots_ad14a0();
    virtual void Pad12_UtilitySlots_ad14a0();
    virtual void Pad13_UtilitySlots_ad14a0();
    virtual void Pad14_UtilitySlots_ad14a0();
    virtual void Pad15_UtilitySlots_ad14a0();
    virtual void Pad16_UtilitySlots_ad14a0();
    virtual void Pad17_UtilitySlots_ad14a0();
    virtual void Pad18_UtilitySlots_ad14a0();
    virtual void Pad19_UtilitySlots_ad14a0();
    virtual void Pad20_UtilitySlots_ad14a0();
    virtual void Pad21_UtilitySlots_ad14a0();
    virtual void Pad22_UtilitySlots_ad14a0();
    virtual void Pad23_UtilitySlots_ad14a0();
    virtual void Pad24_UtilitySlots_ad14a0();
    virtual void Pad25_UtilitySlots_ad14a0();
    virtual void Pad26_UtilitySlots_ad14a0();
    virtual void Pad27_UtilitySlots_ad14a0();
    virtual void Pad28_UtilitySlots_ad14a0();
    virtual void Pad29_UtilitySlots_ad14a0();
    virtual void Pad30_UtilitySlots_ad14a0();
    virtual void SetLanguage(uint32_t language);   // 0x7c
};

// FUNCTION: 0x00928beb
uint32_t cRZLanguageManager::Slot39_ad1198(uint32_t language)
{
    void* memory = operator new(0x28);
    UtilitySlots_ad14a0* utility;
    if (memory) {
        utility = reinterpret_cast<UtilitySlots_ad14a0*>(static_cast<UtilityView_ad14a0*>(memory)->Fn0092847c());
    } else {
        utility = 0;
    }
    utility->AddRef();
    utility->SetLanguage(language);
    return OB_ADDR(utility);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00891bad score 19
void IntList_ad14a0::Fn00891bad(void** result, void* first, void* last)
{
    while (first != last) {
        void* current = first;
        first = *static_cast<void**>(first);
        Fn0049eaa0(current);
    }
    *result = last;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0065e900 score 20
void Set_ad14a0::Fn0065e900(SetPair_ad14a0* result, const uint32_t* value)
{
    SetPair_ad14a0 inserted;
    Fn0046c0e0(&inserted, value);
    *result = inserted;
}
#endif

// Erases the nodes from first up to last.
#ifdef OB_DRAFTS
// CLOSE: 0x00927d71 score 34
void Set_ad14a0::Fn00927d71(void* first, void* last)
{
    if (first == mpHeader->mpLeftmost && last == mpHeader) {
        Fn0065e780();
        return;
    }
    do {
        void* current = first;
        first = Fn0040d4c0(first);
        Fn00927cf8(current);
    } while (first != last);
}
#endif

// The range of nodes holding the key.
#ifdef OB_DRAFTS
// CLOSE: 0x00927dda score 2
SetRange_ad14a0* Set_ad14a0::Fn00927dda(SetRange_ad14a0* result, const uint32_t* key)
{
    void* upper = Fn00927d4c(key);
    void* lower = Fn00927d27(key);
    result->mpFirst = lower;
    result->mpLast = upper;
    return result;
}
#endif

// Erases every node holding the key; returns how many there were.
#ifdef OB_DRAFTS
// CLOSE: 0x00927fd8 score 16
uint32_t Set_ad14a0::Fn00927fd8(const uint32_t* key)
{
    SetRange_ad14a0 range;
    Fn00927dda(&range, key);
    uint32_t count = Fn00893dec(&range.mpFirst, &range.mpLast, 0);
    Fn00927d71(range.mpFirst, range.mpLast);
    return count;
}
#endif

// The slots the language manager calls through its own vtable with arguments the header lacks.
struct LanguageView_ad14a0 {
    virtual void Pad00_LanguageView_ad14a0();
    virtual void Pad01_LanguageView_ad14a0();
    virtual void Pad02_LanguageView_ad14a0();
    virtual void Pad03_LanguageView_ad14a0();
    virtual void Pad04_LanguageView_ad14a0();
    virtual void Pad05_LanguageView_ad14a0();
    virtual void Pad06_LanguageView_ad14a0();
    virtual void Pad07_LanguageView_ad14a0();
    virtual void Pad08_LanguageView_ad14a0();
    virtual void Pad09_LanguageView_ad14a0();
    virtual void Pad10_LanguageView_ad14a0();
    virtual void Pad11_LanguageView_ad14a0();
    virtual void Pad12_LanguageView_ad14a0();
    virtual void Pad13_LanguageView_ad14a0();
    virtual void Pad14_LanguageView_ad14a0();
    virtual void Pad15_LanguageView_ad14a0();
    virtual void Pad16_LanguageView_ad14a0();
    virtual void Pad17_LanguageView_ad14a0();
    virtual void Pad18_LanguageView_ad14a0();
    virtual void Pad19_LanguageView_ad14a0();
    virtual void Pad20_LanguageView_ad14a0();
    virtual void Pad21_LanguageView_ad14a0();
    virtual void Pad22_LanguageView_ad14a0();
    virtual void Pad23_LanguageView_ad14a0();
    virtual void Pad24_LanguageView_ad14a0();
    virtual void Pad25_LanguageView_ad14a0();
    virtual void Pad26_LanguageView_ad14a0();
    virtual void Pad27_LanguageView_ad14a0();
    virtual void Pad28_LanguageView_ad14a0();
    virtual void Pad29_LanguageView_ad14a0();
    virtual void Pad30_LanguageView_ad14a0();
    virtual void Pad31_LanguageView_ad14a0();
    virtual void Pad32_LanguageView_ad14a0();
    virtual void Pad33_LanguageView_ad14a0();
    virtual void Pad34_LanguageView_ad14a0();
    virtual bool V35(uint32_t str, uint32_t id);   // 0x8c
};

// The list of strings the caller hands in (its clear and push_back).
struct StringList_ad14a0 {
    // STUB: 0x0043aba0
    void Fn0043aba0();
    // STUB: 0x004580e0
    void Fn004580e0(const cRZString* value);
};

// STUB: 0x00923d58
void Fn00923d58(cIGZString* text);

// FUNCTION: 0x00924798
bool cRZLanguageManager::Slot16_ad1198(uint32_t str, uint32_t language)
{
    if (language == 0) {
        language = mnLanguage;
    }
    switch (language) {
    case 1:
        OB_PTR(cIGZString, str)->FromChar("English");
        break;
    case 2:
        OB_PTR(cIGZString, str)->FromChar("UK English");
        break;
    case 3:
        OB_PTR(cIGZString, str)->FromChar("French");
        break;
    case 4:
        OB_PTR(cIGZString, str)->FromChar("German");
        break;
    case 5:
        OB_PTR(cIGZString, str)->FromChar("Italian");
        break;
    case 6:
        OB_PTR(cIGZString, str)->FromChar("Spanish");
        break;
    case 8:
        OB_PTR(cIGZString, str)->FromChar("Danish");
        break;
    case 9:
        OB_PTR(cIGZString, str)->FromChar("Swedish");
        break;
    case 12:
        OB_PTR(cIGZString, str)->FromChar("Hebrew");
        break;
    case 13:
        OB_PTR(cIGZString, str)->FromChar("Russian");
        break;
    case 16:
        OB_PTR(cIGZString, str)->FromChar("Polish");
        break;
    case 7:
        OB_PTR(cIGZString, str)->FromChar("Dutch");
        break;
    case 10:
        OB_PTR(cIGZString, str)->FromChar("Norwegian");
        break;
    case 11:
        OB_PTR(cIGZString, str)->FromChar("Finnish");
        break;
    case 15:
        OB_PTR(cIGZString, str)->FromChar("Japanese");
        break;
    case 14:
        OB_PTR(cIGZString, str)->FromChar("Portuguese");
        break;
    case 35:
        OB_PTR(cIGZString, str)->FromChar("Brazilian Portuguese");
        break;
    case 17:
        OB_PTR(cIGZString, str)->FromChar("Simplified Chinese");
        break;
    case 18:
        OB_PTR(cIGZString, str)->FromChar("Traditional Chinese");
        break;
    case 19:
        OB_PTR(cIGZString, str)->FromChar("Thai");
        break;
    case 20:
        OB_PTR(cIGZString, str)->FromChar("Korean");
        break;
    case 21:
        OB_PTR(cIGZString, str)->FromChar("Hindi");
        break;
    case 22:
        OB_PTR(cIGZString, str)->FromChar("Arabic");
        break;
    case 23:
        OB_PTR(cIGZString, str)->FromChar("Bulgarian");
        break;
    case 24:
        OB_PTR(cIGZString, str)->FromChar("Cyrillic");
        break;
    case 25:
        OB_PTR(cIGZString, str)->FromChar("Ukranian");
        break;
    case 26:
        OB_PTR(cIGZString, str)->FromChar("Czech");
        break;
    case 27:
        OB_PTR(cIGZString, str)->FromChar("Greek");
        break;
    case 28:
        OB_PTR(cIGZString, str)->FromChar("Hungarian");
        break;
    case 29:
        OB_PTR(cIGZString, str)->FromChar("Icelandic");
        break;
    case 30:
        OB_PTR(cIGZString, str)->FromChar("Romanian");
        break;
    case 31:
        OB_PTR(cIGZString, str)->FromChar("Latin");
        break;
    case 32:
        OB_PTR(cIGZString, str)->FromChar("Slovak");
        break;
    case 33:
        OB_PTR(cIGZString, str)->FromChar("Albanian");
        break;
    case 34:
        OB_PTR(cIGZString, str)->FromChar("Turkish");
        break;
    case 36:
        OB_PTR(cIGZString, str)->FromChar("Swiss French");
        break;
    case 37:
        OB_PTR(cIGZString, str)->FromChar("Canadian French");
        break;
    case 38:
        OB_PTR(cIGZString, str)->FromChar("Belgian French");
        break;
    case 39:
        OB_PTR(cIGZString, str)->FromChar("Swiss German");
        break;
    case 40:
        OB_PTR(cIGZString, str)->FromChar("Swiss Italian");
        break;
    case 41:
        OB_PTR(cIGZString, str)->FromChar("Belgian Dutch");
        break;
    case 42:
        OB_PTR(cIGZString, str)->FromChar("Mexican Spanish");
        break;
    case 43:
        OB_PTR(cIGZString, str)->FromChar("Tagalog");
        break;
    case 44:
        OB_PTR(cIGZString, str)->FromChar("Vietnamese");
        break;
    default:
        OB_PTR(cIGZString, str)->FromChar("");
        return false;
    }
    return true;
}

// FUNCTION: 0x00924bbd
bool cRZLanguageManager::Slot24_ad1198(uint32_t str, uint32_t language)
{
    if (language == 0) {
        language = mnLanguage;
    }
    switch (language) {
    case 1:
        OB_PTR(cIGZString, str)->FromChar("en");
        break;
    case 4:
        OB_PTR(cIGZString, str)->FromChar("de");
        break;
    case 6:
        OB_PTR(cIGZString, str)->FromChar("es");
        break;
    case 8:
        OB_PTR(cIGZString, str)->FromChar("da");
        break;
    case 9:
        OB_PTR(cIGZString, str)->FromChar("sv");
        break;
    case 10:
        OB_PTR(cIGZString, str)->FromChar("no");
        break;
    case 11:
        OB_PTR(cIGZString, str)->FromChar("fi");
        break;
    case 12:
        OB_PTR(cIGZString, str)->FromChar("iw");
        break;
    case 14:
    case 35:
        OB_PTR(cIGZString, str)->FromChar("pt");
        break;
    case 15:
        OB_PTR(cIGZString, str)->FromChar("ja");
        break;
    case 16:
        OB_PTR(cIGZString, str)->FromChar("pl");
        break;
    case 17:
    case 18:
        OB_PTR(cIGZString, str)->FromChar("zh");
        break;
    case 19:
        OB_PTR(cIGZString, str)->FromChar("th");
        break;
    case 20:
        OB_PTR(cIGZString, str)->FromChar("ko");
        break;
    case 33:
        OB_PTR(cIGZString, str)->FromChar("al");
        break;
    case 34:
        OB_PTR(cIGZString, str)->FromChar("tr");
        break;
    case 21:
        OB_PTR(cIGZString, str)->FromChar("hi");
        break;
    case 22:
        OB_PTR(cIGZString, str)->FromChar("ar");
        break;
    case 23:
        OB_PTR(cIGZString, str)->FromChar("bg");
        break;
    case 13:
    case 24:
        OB_PTR(cIGZString, str)->FromChar("ru");
        break;
    case 2:
    case 25:
        OB_PTR(cIGZString, str)->FromChar("uk");
        break;
    case 26:
        OB_PTR(cIGZString, str)->FromChar("cs");
        break;
    case 27:
        OB_PTR(cIGZString, str)->FromChar("el");
        break;
    case 28:
        OB_PTR(cIGZString, str)->FromChar("hu");
        break;
    case 29:
        OB_PTR(cIGZString, str)->FromChar("is");
        break;
    case 30:
        OB_PTR(cIGZString, str)->FromChar("ro");
        break;
    case 31:
        OB_PTR(cIGZString, str)->FromChar("la");
        break;
    case 32:
        OB_PTR(cIGZString, str)->FromChar("sk");
        break;
    case 3:
    case 36:
    case 37:
    case 38:
        OB_PTR(cIGZString, str)->FromChar("fr");
        break;
    case 39:
        OB_PTR(cIGZString, str)->FromChar("gr");
        break;
    case 5:
    case 40:
        OB_PTR(cIGZString, str)->FromChar("it");
        break;
    case 7:
    case 41:
        OB_PTR(cIGZString, str)->FromChar("nl");
        break;
    case 42:
        OB_PTR(cIGZString, str)->FromChar("sp");
        break;
    case 43:
        OB_PTR(cIGZString, str)->FromChar("tl");
        break;
    case 44:
        OB_PTR(cIGZString, str)->FromChar("vi");
        break;
    default:
        OB_PTR(cIGZString, str)->FromChar("");
        return false;
    }
    return true;
}

// FUNCTION: 0x00924dcd
bool cRZLanguageManager::Slot26_ad1198(uint32_t str, uint32_t language)
{
    if (language == 0) {
        language = mnLanguage2;
    }
    switch (language) {
    case 1:
        OB_PTR(cIGZString, str)->FromChar("al");
        break;
    case 2:
        OB_PTR(cIGZString, str)->FromChar("ar");
        break;
    case 3:
        OB_PTR(cIGZString, str)->FromChar("au");
        break;
    case 4:
        OB_PTR(cIGZString, str)->FromChar("at");
        break;
    case 5:
        OB_PTR(cIGZString, str)->FromChar("be");
        break;
    case 6:
        OB_PTR(cIGZString, str)->FromChar("br");
        break;
    case 7:
        OB_PTR(cIGZString, str)->FromChar("bg");
        break;
    case 8:
        OB_PTR(cIGZString, str)->FromChar("ca");
        break;
    case 9:
        OB_PTR(cIGZString, str)->FromChar("cl");
        break;
    case 10:
        OB_PTR(cIGZString, str)->FromChar("cn");
        break;
    case 11:
        OB_PTR(cIGZString, str)->FromChar("co");
        break;
    case 12:
        OB_PTR(cIGZString, str)->FromChar("cu");
        break;
    case 13:
        OB_PTR(cIGZString, str)->FromChar("cz");
        break;
    case 14:
        OB_PTR(cIGZString, str)->FromChar("dk");
        break;
    case 15:
        OB_PTR(cIGZString, str)->FromChar("eg");
        break;
    case 16:
        OB_PTR(cIGZString, str)->FromChar("fi");
        break;
    case 17:
        OB_PTR(cIGZString, str)->FromChar("fr");
        break;
    case 18:
        OB_PTR(cIGZString, str)->FromChar("ge");
        break;
    case 19:
        OB_PTR(cIGZString, str)->FromChar("de");
        break;
    case 20:
        OB_PTR(cIGZString, str)->FromChar("gr");
        break;
    case 22:
        OB_PTR(cIGZString, str)->FromChar("hk");
        break;
    case 23:
        OB_PTR(cIGZString, str)->FromChar("hu");
        break;
    case 24:
        OB_PTR(cIGZString, str)->FromChar("is");
        break;
    case 25:
        OB_PTR(cIGZString, str)->FromChar("in");
        break;
    case 26:
        OB_PTR(cIGZString, str)->FromChar("ir");
        break;
    case 27:
        OB_PTR(cIGZString, str)->FromChar("iq");
        break;
    case 28:
        OB_PTR(cIGZString, str)->FromChar("ie");
        break;
    case 29:
        OB_PTR(cIGZString, str)->FromChar("il");
        break;
    case 30:
        OB_PTR(cIGZString, str)->FromChar("it");
        break;
    case 31:
        OB_PTR(cIGZString, str)->FromChar("jp");
        break;
    case 32:
        OB_PTR(cIGZString, str)->FromChar("kr");
        break;
    case 33:
        OB_PTR(cIGZString, str)->FromChar("mx");
        break;
    case 34:
        OB_PTR(cIGZString, str)->FromChar("nl");
        break;
    case 35:
        OB_PTR(cIGZString, str)->FromChar("nz");
        break;
    case 36:
        OB_PTR(cIGZString, str)->FromChar("no");
        break;
    case 37:
        OB_PTR(cIGZString, str)->FromChar("ph");
        break;
    case 38:
        OB_PTR(cIGZString, str)->FromChar("pl");
        break;
    case 39:
        OB_PTR(cIGZString, str)->FromChar("pt");
        break;
    case 40:
        OB_PTR(cIGZString, str)->FromChar("ro");
        break;
    case 41:
        OB_PTR(cIGZString, str)->FromChar("ru");
        break;
    case 42:
        OB_PTR(cIGZString, str)->FromChar("sg");
        break;
    case 43:
        OB_PTR(cIGZString, str)->FromChar("sk");
        break;
    case 44:
        OB_PTR(cIGZString, str)->FromChar("si");
        break;
    case 45:
        OB_PTR(cIGZString, str)->FromChar("es");
        break;
    case 46:
        OB_PTR(cIGZString, str)->FromChar("se");
        break;
    case 47:
        OB_PTR(cIGZString, str)->FromChar("ch");
        break;
    case 48:
        OB_PTR(cIGZString, str)->FromChar("sy");
        break;
    case 49:
        OB_PTR(cIGZString, str)->FromChar("tw");
        break;
    case 50:
        OB_PTR(cIGZString, str)->FromChar("th");
        break;
    case 51:
        OB_PTR(cIGZString, str)->FromChar("tr");
        break;
    case 52:
        OB_PTR(cIGZString, str)->FromChar("ua");
        break;
    case 53:
        OB_PTR(cIGZString, str)->FromChar("gb");
        break;
    case 54:
        OB_PTR(cIGZString, str)->FromChar("us");
        break;
    case 55:
        OB_PTR(cIGZString, str)->FromChar("vn");
        break;
    case 56:
        OB_PTR(cIGZString, str)->FromChar("yu");
        break;
    default:
        OB_PTR(cIGZString, str)->FromChar("");
        return false;
    }
    return true;
}

// FUNCTION: 0x009253db
bool cRZLanguageManager::Slot34_ad1198(uint32_t str, uint32_t language)
{
    if (language == 0) {
        language = mnLanguage2;
    }
    switch (language) {
    case 1:
        OB_PTR(cIGZString, str)->FromChar("Albania");
        break;
    case 2:
        OB_PTR(cIGZString, str)->FromChar("Argentina");
        break;
    case 3:
        OB_PTR(cIGZString, str)->FromChar("Australia");
        break;
    case 4:
        OB_PTR(cIGZString, str)->FromChar("Austria");
        break;
    case 5:
        OB_PTR(cIGZString, str)->FromChar("Belgium");
        break;
    case 6:
        OB_PTR(cIGZString, str)->FromChar("Brazil");
        break;
    case 7:
        OB_PTR(cIGZString, str)->FromChar("Bulgaria");
        break;
    case 8:
        OB_PTR(cIGZString, str)->FromChar("Canada");
        break;
    case 9:
        OB_PTR(cIGZString, str)->FromChar("Chile");
        break;
    case 10:
        OB_PTR(cIGZString, str)->FromChar("China");
        break;
    case 11:
        OB_PTR(cIGZString, str)->FromChar("Colombia");
        break;
    case 12:
        OB_PTR(cIGZString, str)->FromChar("Cuba");
        break;
    case 13:
        OB_PTR(cIGZString, str)->FromChar("Czech Republic");
        break;
    case 14:
        OB_PTR(cIGZString, str)->FromChar("Denmark");
        break;
    case 15:
        OB_PTR(cIGZString, str)->FromChar("Egypt");
        break;
    case 16:
        OB_PTR(cIGZString, str)->FromChar("Finland");
        break;
    case 17:
        OB_PTR(cIGZString, str)->FromChar("France");
        break;
    case 18:
        OB_PTR(cIGZString, str)->FromChar("Georgia");
        break;
    case 19:
        OB_PTR(cIGZString, str)->FromChar("Germany");
        break;
    case 20:
        OB_PTR(cIGZString, str)->FromChar("Greece");
        break;
    case 21:
        OB_PTR(cIGZString, str)->FromChar("Holy See");
        break;
    case 22:
        OB_PTR(cIGZString, str)->FromChar("Hong Kong");
        break;
    case 23:
        OB_PTR(cIGZString, str)->FromChar("Hungray");
        break;
    case 24:
        OB_PTR(cIGZString, str)->FromChar("Iceland");
        break;
    case 25:
        OB_PTR(cIGZString, str)->FromChar("India");
        break;
    case 26:
        OB_PTR(cIGZString, str)->FromChar("Iran");
        break;
    case 27:
        OB_PTR(cIGZString, str)->FromChar("Iraq");
        break;
    case 28:
        OB_PTR(cIGZString, str)->FromChar("Ireland");
        break;
    case 29:
        OB_PTR(cIGZString, str)->FromChar("Israel");
        break;
    case 30:
        OB_PTR(cIGZString, str)->FromChar("Italy");
        break;
    case 31:
        OB_PTR(cIGZString, str)->FromChar("Japan");
        break;
    case 32:
        OB_PTR(cIGZString, str)->FromChar("Korea");
        break;
    case 33:
        OB_PTR(cIGZString, str)->FromChar("Mexico");
        break;
    case 34:
        OB_PTR(cIGZString, str)->FromChar("Netherlands");
        break;
    case 35:
        OB_PTR(cIGZString, str)->FromChar("New Zealand");
        break;
    case 36:
        OB_PTR(cIGZString, str)->FromChar("Norway");
        break;
    case 37:
        OB_PTR(cIGZString, str)->FromChar("Philippines");
        break;
    case 38:
        OB_PTR(cIGZString, str)->FromChar("Poland");
        break;
    case 39:
        OB_PTR(cIGZString, str)->FromChar("Portugal");
        break;
    case 40:
        OB_PTR(cIGZString, str)->FromChar("Romania");
        break;
    case 41:
        OB_PTR(cIGZString, str)->FromChar("Russia");
        break;
    case 42:
        OB_PTR(cIGZString, str)->FromChar("Singapore");
        break;
    case 43:
        OB_PTR(cIGZString, str)->FromChar("Slovakia");
        break;
    case 44:
        OB_PTR(cIGZString, str)->FromChar("Slovenia");
        break;
    case 45:
        OB_PTR(cIGZString, str)->FromChar("Spain");
        break;
    case 46:
        OB_PTR(cIGZString, str)->FromChar("Sweden");
        break;
    case 47:
        OB_PTR(cIGZString, str)->FromChar("Switzerland");
        break;
    case 48:
        OB_PTR(cIGZString, str)->FromChar("Syria");
        break;
    case 49:
        OB_PTR(cIGZString, str)->FromChar("Taiwan");
        break;
    case 50:
        OB_PTR(cIGZString, str)->FromChar("Thailand");
        break;
    case 51:
        OB_PTR(cIGZString, str)->FromChar("Turkey");
        break;
    case 52:
        OB_PTR(cIGZString, str)->FromChar("Ukraine");
        break;
    case 53:
        OB_PTR(cIGZString, str)->FromChar("United Kingdom");
        break;
    case 54:
        OB_PTR(cIGZString, str)->FromChar("United States");
        break;
    case 55:
        OB_PTR(cIGZString, str)->FromChar("Vietnam");
        break;
    case 56:
        OB_PTR(cIGZString, str)->FromChar("Yugoslavia");
        break;
    default:
        OB_PTR(cIGZString, str)->FromChar("UnitedStates");
        return false;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092440f score 6
bool cRZLanguageManager::Slot13_ad1198(uint32_t str, uint32_t language)
{
    bool ok = true;
    if (language == 0) {
        language = mnLanguage;
    }
    switch (language) {
    case 1:
        OB_PTR(cIGZString, str)->FromChar("english-us");
        break;
    case 2:
        OB_PTR(cIGZString, str)->FromChar("english-uk");
        break;
    case 3:
        OB_PTR(cIGZString, str)->FromChar("french");
        break;
    case 4:
        OB_PTR(cIGZString, str)->FromChar("german");
        break;
    case 5:
        OB_PTR(cIGZString, str)->FromChar("italian");
        break;
    case 6:
        OB_PTR(cIGZString, str)->FromChar("spanish");
        break;
    case 8:
        OB_PTR(cIGZString, str)->FromChar("danish");
        break;
    case 9:
        OB_PTR(cIGZString, str)->FromChar("swedish");
        break;
    case 13:
    case 23:
    case 24:
    case 25:
        OB_PTR(cIGZString, str)->FromChar("russian");
        break;
    case 16:
        OB_PTR(cIGZString, str)->FromChar("polish");
        break;
    case 15:
        OB_PTR(cIGZString, str)->FromChar("japanese");
        break;
    case 7:
        OB_PTR(cIGZString, str)->FromChar("dutch");
        break;
    case 10:
        OB_PTR(cIGZString, str)->FromChar("norwegian");
        break;
    case 11:
        OB_PTR(cIGZString, str)->FromChar("finnish");
        break;
    case 14:
    case 35:
        OB_PTR(cIGZString, str)->FromChar("portuguese");
        break;
    case 17:
        OB_PTR(cIGZString, str)->FromChar("chinese-simplified");
        break;
    case 18:
        OB_PTR(cIGZString, str)->FromChar("chinese-traditional");
        break;
    case 20:
        OB_PTR(cIGZString, str)->FromChar("korean");
        break;
    case 26:
        OB_PTR(cIGZString, str)->FromChar("czech");
        break;
    case 41:
        OB_PTR(cIGZString, str)->FromChar("dutch-belgian");
        break;
    case 38:
        OB_PTR(cIGZString, str)->FromChar("french-belgian");
        break;
    case 37:
        OB_PTR(cIGZString, str)->FromChar("french-canadian");
        break;
    case 36:
        OB_PTR(cIGZString, str)->FromChar("french-swiss");
        break;
    case 39:
        OB_PTR(cIGZString, str)->FromChar("german-swiss");
        break;
    case 27:
        OB_PTR(cIGZString, str)->FromChar("greek");
        break;
    case 28:
        OB_PTR(cIGZString, str)->FromChar("hungarian");
        break;
    case 29:
        OB_PTR(cIGZString, str)->FromChar("icelandic");
        break;
    case 40:
        OB_PTR(cIGZString, str)->FromChar("italian-swiss");
        break;
    case 32:
        OB_PTR(cIGZString, str)->FromChar("slovak");
        break;
    case 42:
        OB_PTR(cIGZString, str)->FromChar("spanish-mexican");
        break;
    case 34:
        OB_PTR(cIGZString, str)->FromChar("turkish");
        break;
    case 21:
        OB_PTR(cIGZString, str)->FromChar("hindi");
        break;
    case 22:
        OB_PTR(cIGZString, str)->FromChar("arabic");
        break;
    case 31:
        OB_PTR(cIGZString, str)->FromChar("latin");
        break;
    case 30:
        OB_PTR(cIGZString, str)->FromChar("romanian");
        break;
    case 44:
        OB_PTR(cIGZString, str)->FromChar("vietnamese");
        break;
    case 43:
        OB_PTR(cIGZString, str)->FromChar("tagalog");
        break;
    case 33:
        OB_PTR(cIGZString, str)->FromChar("albanian");
        break;
    case 12:
        OB_PTR(cIGZString, str)->FromChar("hebrew");
        break;
    case 19:
        OB_PTR(cIGZString, str)->FromChar("thai");
        break;
    default:
        ok = false;
        break;
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009250d5 score 184
uint32_t cRZLanguageManager::Slot30_ad1198(uint32_t id)
{
    if (id == 0) {
        id = mnLanguage2;
    }
    switch (id) {
    case 2:
    case 9:
    case 11:
    case 12:
    case 45:
        return 0x6;
    case 3:
    case 28:
    case 35:
    case 47:
    case 53:
        return 0x2;
    case 4:
    case 19:
        return 0x4;
    case 5:
        return 0x26;
    case 6:
        return 0x23;
    case 7:
        return 0x17;
    case 10:
    case 42:
        return 0x11;
    case 13:
        return 0x1a;
    case 14:
        return 0x8;
    case 16:
        return 0xb;
    case 18:
    case 41:
        return 0xd;
    case 20:
        return 0x1b;
    case 22:
    case 49:
        return 0x12;
    case 23:
        return 0x1c;
    case 24:
        return 0x1d;
    case 26:
    case 27:
        return 0x16;
    case 29:
        return 0xc;
    case 30:
        return 0x5;
    case 31:
        return 0xf;
    case 32:
        return 0x14;
    case 33:
        return 0x2a;
    case 34:
        return 0x7;
    case 36:
        return 0xa;
    case 37:
        return 0x2b;
    case 38:
        return 0x10;
    case 39:
        return 0xe;
    case 40:
        return 0x1e;
    case 46:
        return 0x9;
    case 50:
        return 0x13;
    case 52:
        return 0x19;
    case 55:
        return 0x2c;
    case 43:
    case 56:
        return 0x20;
    default:
        return 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092525a score 101
uint32_t cRZLanguageManager::Slot31_ad1198(uint32_t id)
{
    if (id == 0) {
        id = mnLanguage;
    }
    switch (id) {
    case 2:
        return 0x35;
    case 3:
        return 0x11;
    case 4:
        return 0x13;
    case 6:
        return 0x2d;
    case 7:
        return 0x22;
    case 8:
        return 0xe;
    case 9:
        return 0x2e;
    case 10:
        return 0x24;
    case 11:
        return 0x10;
    case 12:
        return 0x1d;
    case 14:
        return 0x27;
    case 35:
        return 0x6;
    case 15:
        return 0x1f;
    case 16:
        return 0x26;
    case 17:
        return 0xa;
    case 18:
        return 0x16;
    case 19:
        return 0x32;
    case 20:
        return 0x20;
    case 21:
        return 0x19;
    case 22:
        return 0x1a;
    case 23:
        return 0x7;
    case 13:
    case 24:
        return 0x29;
    case 25:
        return 0x34;
    case 26:
        return 0xd;
    case 27:
        return 0x14;
    case 28:
        return 0x17;
    case 29:
        return 0x18;
    case 30:
        return 0x28;
    case 5:
    case 31:
        return 0x1e;
    case 32:
        return 0x2b;
    case 34:
        return 0x33;
    case 37:
        return 0x8;
    case 36:
    case 39:
    case 40:
        return 0x2f;
    case 38:
    case 41:
        return 0x5;
    case 42:
        return 0x21;
    case 43:
        return 0x25;
    case 44:
        return 0x37;
    case 1:
        return 0x36;
    default:
        return 0x36;
    }
}
#endif

// FUNCTION: 0x00923e3e
uint32_t cRZLanguageManager::Slot11_ad1198(uint32_t language)
{
    if (language == 0) {
        language = mnLanguage;
    }
    switch (language) {
    case 1:
        return 0x409;
    case 2:
        return 0x809;
    case 3:
        return 0x40c;
    case 4:
        return 0x407;
    case 5:
        return 0x410;
    case 7:
        return 0x413;
    case 10:
        return 0x414;
    case 14:
        return 0x816;
    case 35:
        return 0x416;
    case 9:
        return 0x41d;
    case 6:
        return 0x40a;
    case 42:
        return 0x80a;
    case 11:
        return 0x40b;
    case 16:
        return 0x415;
    case 8:
        return 0x406;
    case 33:
        return 0x41c;
    case 34:
        return 0x41f;
    case 29:
        return 0x40f;
    case 12:
        return 0x40d;
    case 27:
        return 0x408;
    case 30:
        return 0x418;
    case 28:
        return 0x40e;
    case 26:
        return 0x405;
    case 32:
        return 0x41b;
    case 23:
        return 0x402;
    case 13:
        return 0x419;
    case 25:
        return 0x422;
    case 15:
        return 0x411;
    case 19:
        return 0x41e;
    case 17:
        return 0x804;
    case 18:
        return 0x404;
    case 20:
        return 0x412;
    case 21:
        return 0x439;
    case 44:
        return 0x42a;
    case 22:
        return 0x401;
    default:
        return 1;
    }
}

// FUNCTION: 0x009280b8
bool cRZLanguageManager::Slot18_ad1198(uint32_t name, uint32_t out)
{
    cRZString candidate;
    uint32_t id = 1;
    do {
        if (Slot16_ad1198(OB_ADDR(&candidate), id)) {
            if (reinterpret_cast<cRZLanguageUtility*>(mUtility)->CompareStrings(OB_PTR(void, name), &candidate, false) == 0) {
                *OB_PTR(uint32_t, out) = id;
                return true;
            }
        }
        ++id;
    } while (id <= 0x2c);
    *OB_PTR(uint32_t, out) = 1;
    return false;
}

// FUNCTION: 0x0092813e
bool cRZLanguageManager::Slot19_ad1198(uint32_t name, uint32_t out)
{
    cRZString candidate;
    uint32_t id = 1;
    do {
        if (Slot17_ad1198(OB_ADDR(&candidate), id)) {
            if (reinterpret_cast<cRZLanguageUtility*>(mUtility)->CompareStrings(OB_PTR(void, name), &candidate, false) == 0) {
                *OB_PTR(uint32_t, out) = id;
                return true;
            }
        }
        ++id;
    } while (id <= 0x2c);
    *OB_PTR(uint32_t, out) = 1;
    return false;
}

// FUNCTION: 0x0092821e
bool cRZLanguageManager::Slot25_ad1198(uint32_t name, uint32_t out)
{
    cRZString candidate;
    uint32_t id = 1;
    do {
        if (Slot24_ad1198(OB_ADDR(&candidate), id)) {
            if (reinterpret_cast<cRZLanguageUtility*>(mUtility)->CompareStrings(OB_PTR(void, name), &candidate, false) == 0) {
                *OB_PTR(uint32_t, out) = id;
                return true;
            }
        }
        ++id;
    } while (id <= 0x2c);
    *OB_PTR(uint32_t, out) = 1;
    return false;
}

// FUNCTION: 0x009282a4
bool cRZLanguageManager::Slot27_ad1198(uint32_t name, uint32_t out)
{
    cRZString candidate;
    uint32_t id = 1;
    do {
        if (Slot26_ad1198(OB_ADDR(&candidate), id)) {
            if (reinterpret_cast<cRZLanguageUtility*>(mUtility)->CompareStrings(OB_PTR(void, name), &candidate, false) == 0) {
                *OB_PTR(uint32_t, out) = id;
                return true;
            }
        }
        ++id;
    } while (id <= 0x39);
    *OB_PTR(uint32_t, out) = 0x36;
    return false;
}

// FUNCTION: 0x0092836a
bool cRZLanguageManager::Slot36_ad1198(uint32_t name, uint32_t out)
{
    cRZString candidate;
    uint32_t id = 1;
    do {
        if (Slot34_ad1198(OB_ADDR(&candidate), id)) {
            if (reinterpret_cast<cRZLanguageUtility*>(mUtility)->CompareStrings(OB_PTR(void, name), &candidate, false) == 0) {
                *OB_PTR(uint32_t, out) = id;
                return true;
            }
        }
        ++id;
    } while (id <= 0x39);
    *OB_PTR(uint32_t, out) = 0x36;
    return false;
}

// FUNCTION: 0x009283f3
bool cRZLanguageManager::Slot37_ad1198(uint32_t name, uint32_t out)
{
    cRZString candidate;
    uint32_t id = 1;
    do {
        if (reinterpret_cast<LanguageView_ad14a0*>(static_cast<cUnk00ad1198*>(this))->V35(OB_ADDR(&candidate), id)) {
            if (reinterpret_cast<cRZLanguageUtility*>(mUtility)->CompareStrings(OB_PTR(void, name), &candidate, false) == 0) {
                *OB_PTR(uint32_t, out) = id;
                return true;
            }
        }
        ++id;
    } while (id <= 0x39);
    *OB_PTR(uint32_t, out) = 0x36;
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092467e score 14
uint32_t cRZLanguageManager::Slot15_ad1198(uint32_t str, uint32_t language)
{
    if (language == 0) {
        language = mnLanguage;
    }
    const char* text;
    switch (language) {
    case 2:
        OB_PTR(cIGZString, str)->FromChar("UKEnglsh");
        break;
    case 10:
        OB_PTR(cIGZString, str)->FromChar("Norwgian");
        break;
    case 0xe:
        OB_PTR(cIGZString, str)->FromChar("Portuges");
        break;
    case 0x11:
        OB_PTR(cIGZString, str)->FromChar("SChinese");
        break;
    case 0x12:
        OB_PTR(cIGZString, str)->FromChar("TChinese");
        break;
    case 0x17:
        OB_PTR(cIGZString, str)->FromChar("Blgarian");
        break;
    case 0x1c:
        OB_PTR(cIGZString, str)->FromChar("Hngarian");
        break;
    case 0x1d:
        OB_PTR(cIGZString, str)->FromChar("Icelandc");
        break;
    case 0x23:
        OB_PTR(cIGZString, str)->FromChar("Portgese");
        break;
    case 0x24:
        OB_PTR(cIGZString, str)->FromChar("SFrench");
        break;
    case 0x25:
        OB_PTR(cIGZString, str)->FromChar("CFrench");
        break;
    case 0x26:
        OB_PTR(cIGZString, str)->FromChar("BFrench");
        break;
    case 0x27:
        OB_PTR(cIGZString, str)->FromChar("SGerman");
        break;
    case 0x28:
        OB_PTR(cIGZString, str)->FromChar("SItalian");
        break;
    case 0x29:
        OB_PTR(cIGZString, str)->FromChar("BDutch");
        break;
    case 0x2a:
        OB_PTR(cIGZString, str)->FromChar("MSpanish");
        break;
    case 0x2c:
        OB_PTR(cIGZString, str)->FromChar("Vietnmse");
        break;
    default:
        Slot16_ad1198(str, language);
        return OB_PTR(cIGZString, str)->Strlen() != 0;
    }
    OB_PTR(cIGZString, str)->FromChar(text);
    return OB_PTR(cIGZString, str)->Strlen() != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00924a02 score 123
bool cRZLanguageManager::Slot17_ad1198(uint32_t str, uint32_t language)
{
    bool ok = true;
    if (language == 0) {
        language = mnLanguage;
    }
    const char* text;
    switch (language) {
    case 1:
    case 2:
        OB_PTR(cIGZString, str)->FromChar("English");
        break;
    case 3:
        OB_PTR(cIGZString, str)->FromChar("Fran\303\207ais");
        break;
    case 4:
        OB_PTR(cIGZString, str)->FromChar("Deutsch");
        break;
    case 5:
        OB_PTR(cIGZString, str)->FromChar("Italiano");
        break;
    case 6:
        OB_PTR(cIGZString, str)->FromChar("Espa\303\261ol");
        break;
    case 7:
        OB_PTR(cIGZString, str)->FromChar("Nederlands");
        break;
    case 8:
        OB_PTR(cIGZString, str)->FromChar("Dansk");
        break;
    case 9:
        OB_PTR(cIGZString, str)->FromChar("Svensk");
        break;
    case 10:
    case 0xc:
    case 0xd:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
        OB_PTR(cIGZString, str)->FromChar("Untranslated");
        break;
    case 0xb:
        OB_PTR(cIGZString, str)->FromChar("Suomi");
        break;
    case 0xe:
    case 0x23:
        OB_PTR(cIGZString, str)->FromChar("Portugues");
        break;
    default:
        text = 0;
        break;
    }
    if (text) {
        OB_PTR(cIGZString, str)->FromChar(text);
    }
    if (OB_PTR(cIGZString, str)->Strlen() == 0) {
        OB_PTR(cIGZString, str)->FromChar("Untranslated");
        ok = false;
    }
    Fn00923d58(OB_PTR(cIGZString, str));
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00928021 score 38
bool cRZLanguageManager::Slot08_ad1198(uint32_t language)
{
    cRZString name;
    if (language == 0) {
        language = 1;
    }
    if (language == mnLanguage) {
        return true;
    }
    if (!static_cast<uint8_t>(Slot09_ad1198(language))) {
        return false;
    }
    mnLanguage = language;
    reinterpret_cast<cRZLanguageUtility*>(mUtility)->SetLanguage(language);
    if (!Slot13_ad1198(OB_ADDR(&name), language)) {
        return false;
    }
    if (setlocale(LC_ALL, name.c_str())) {
        OB_SETMBCP();
    }
    return true;
}
#endif

// FUNCTION: 0x0092832a
bool cRZLanguageManager::Slot29_ad1198(uint32_t country)
{
    cRZString unused;
    if (country == 0) {
        country = 0x36;
    }
    mnLanguage2 = country;
    reinterpret_cast<cRZLanguageUtility*>(mUtility)->SetCountry(country);
    return true;
}

// FUNCTION: 0x009281c4
bool cRZLanguageManager::Slot20_ad1198(uint32_t name, uint32_t out)
{
    cRZString copy(*OB_PTR(cIGZString, name));
    bool ok = Slot20_ad1198(OB_ADDR(&copy), out);
    if (ok) {
        OB_PTR(cIGZString, name)->FromChar(copy.ToChar());
    }
    return ok;
}

// FUNCTION: 0x00929609
void cRZLanguageManager::GetAllAvailableLanguagesIntoStringList(uint32_t list)
{
    StringList_ad14a0* out = OB_PTR(StringList_ad14a0, list);
    out->Fn0043aba0();
    uint32_t id = 1;
    do {
        if (Slot14_ad1198(OB_ADDR(&id))) {
            cRZString name;
            Slot16_ad1198(OB_ADDR(&name), id);
            out->Fn004580e0(&name);
        }
        ++id;
    } while (id <= 0x2c);
}

// The language of a system locale (the inverse of the table of Slot11).
#ifdef OB_DRAFTS
// CLOSE: 0x00924038 score 328
uint32_t cRZLanguageManager::Slot12_ad1198(uint32_t locale)
{
    switch (locale & 0xffff) {
    case 0x409:
        return 0;
    case 0x809:
        return 0;
    case 0x40c:
        return 0;
    case 0x407:
        return 0;
    case 0x410:
        return 0;
    case 0x40a:
        return 0;
    case 0x413:
        return 0;
    case 0x406:
        return 0;
    case 0x41d:
        return 0;
    case 0x414:
        return 0;
    case 0x40b:
        return 0;
    case 0x40d:
        return 0;
    case 0x419:
        return 0;
    case 0x816:
        return 0;
    case 0x411:
        return 0;
    case 0x415:
        return 0;
    case 0x804:
        return 0;
    case 0x404:
        return 0;
    case 0x41e:
        return 0;
    case 0x412:
        return 0;
    case 0x439:
        return 0;
    case 0x401:
        return 0;
    case 0x402:
        return 0;
    case 0x422:
        return 0;
    case 0x405:
        return 0;
    case 0x408:
        return 0;
    case 0x40e:
        return 0;
    case 0x40f:
        return 0;
    case 0x418:
        return 0;
    case 0x41b:
        return 0;
    case 0x41c:
        return 0;
    case 0x41f:
        return 0;
    case 0x416:
        return 0;
    case 0x80a:
        return 0;
    case 0x42a:
        return 0;
    }
    return 2;
}
#endif
