#include "classes/cUnk00acd938.h"
#include "gzcom/cRZString.h"
#include <string>

// GLOBAL: 0x00b6249c
extern uint32_t g00b6249c;
// GLOBAL: 0x00b62498
extern uint32_t g00b62498;

// STUB: 0x00462d10
void Fn00462d10(void* first, void* last, void* dst);

// Views of the raw bytes inside cUnk00acd938 (the header keeps these as unknown bytes).
static inline cRZString& RZAt_acd938(cUnk00acd938* self, uint32_t off)
{
    return *reinterpret_cast<cRZString*>(reinterpret_cast<char*>(self) + off);
}

inline std::string& StrAt_acd938(cUnk00acd938* self, uint32_t off)
{
    return *reinterpret_cast<std::string*>(reinterpret_cast<char*>(self) + off);
}

// Shapes the original calls through; no instance of either is made here.
struct Sub_acd938 {
    virtual void Slot00_acd938() = 0;
    virtual void Slot01_acd938() = 0;
    virtual void Slot02_acd938() = 0;
    virtual void Slot03_acd938() = 0;
    virtual void Slot04_acd938() = 0;
    virtual void Slot05_acd938() = 0;
    virtual void Slot06_acd938() = 0;
    virtual void Slot07_acd938() = 0;
    virtual void Slot08_acd938() = 0;
    virtual void Slot09_acd938() = 0;
    virtual bool Slot10_acd938(uint32_t, bool) = 0;
};

struct Entry_acd938 {
    char unknown0[0x30];
    Sub_acd938* mpSub;
};

#ifdef OB_DRAFTS
// CLOSE: 0x008fe759 score 16
bool cUnk00acd938::QueryInterface(unsigned int riid, void** ppv)
{
    switch (riid) {
    case 1:
        *ppv = this;
        break;
    case 0x452294aa:
        *ppv = this ? static_cast<cUnk00aaaa9c*>(this) : 0;
        break;
    case 0xe0eca23a:
        *ppv = this;
        break;
    default:
        return false;
    }
    AddRef();
    return true;
}
#endif

// FUNCTION: 0x008fe79a
unsigned int cUnk00acd938::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x008fe7a1
unsigned int cUnk00acd938::Release()
{
    if (mnRefCount == 1) {
        delete this;
        return 0;
    }
    return --mnRefCount;
}

// FUNCTION: 0x008fe89e
void* cUnk00acd938::Slot13_acd938(uint32_t a)
{
    Entry_acd938** end = reinterpret_cast<Entry_acd938**>(mpEntryEnd);
    for (Entry_acd938** p = reinterpret_cast<Entry_acd938**>(mpEntryBegin); p != end; ++p) {
        Entry_acd938* e = *p;
        if (e->mpSub->Slot10_acd938(a, true)) {
            return e;
        }
    }
    return 0;
}

// FUNCTION: 0x008fee66
uint32_t cUnk00acd938::Slot06_acd938(void* p, int32_t b)
{
    int32_t seven = 7;
    const int32_t& n = (b > seven) ? seven : b;
    uint32_t* dst = static_cast<uint32_t*>(p);
    Fn00462d10(&mnValues[0], &mnValues[0] + n, dst);
    uint32_t* end = dst + b;
    for (uint32_t* q = dst + n; q != end; ++q) {
        *q = 0;
    }
    return static_cast<uint32_t>(n);
}

// FUNCTION: 0x008feeb8
void cUnk00acd938::Slot07_acd938(void* p, int32_t b)
{
    int32_t seven = 7;
    const int32_t& n = (b > seven) ? seven : b;
    uint32_t* src = static_cast<uint32_t*>(p);
    Fn00462d10(src, src + n, &mnValues[0]);
    mn54 = mnValues[3];
    mn6c = mnValues[3];
}

// FUNCTION: 0x009006bb
void cUnk00acd938::Slot05_acd938(void* p)
{
    Slot08_acd938(p);
}

// FUNCTION: 0x009006ca
uint32_t cUnk00acd938::Slot18_acd938()
{
    return g00b6249c;
}

// FUNCTION: 0x009006d0
uint32_t cUnk00acd938::Slot19_acd938()
{
    return g00b62498;
}

// FUNCTION: 0x009006f2
void cUnk00acd938::Slot22_acd938(void* s, void* out)
{
    *static_cast<cRZString*>(s) = RZAt_acd938(this, 0x40);
    *static_cast<uint32_t*>(out) = mn54;
}

// FUNCTION: 0x0090070f
void cUnk00acd938::Slot23_acd938(void* s, void* out)
{
    *static_cast<cRZString*>(s) = RZAt_acd938(this, 0x58);
    *static_cast<uint32_t*>(out) = mn6c;
}

// FUNCTION: 0x009007a1
bool cUnk00acd938::Slot21_acd938(void* p)
{
    cRZString* s = static_cast<cRZString*>(p);
    if (mpB8) {
        *s = *static_cast<cRZString*>(mpB8);
        return true;
    }
    std::string* str = reinterpret_cast<std::string*>(reinterpret_cast<char*>(s) + 4);
    str->erase(0, std::string::npos);
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00908122 score 19
void cUnk00acd938::Slot08_acd938(void* p)
{
    RZAt_acd938(this, 0x180) = *static_cast<cRZString*>(p);
    mn194 = 0;
    Fn008ffac2();
    Fn00905cf0(0);
    switch (mnE8) {
    case 2:
        Slot09_acd938();
        break;
    case 4:
        Fn009080a2();
        break;
    case 1:
    case 3:
    default:
        StrAt_acd938(this, 0x104).erase(0, std::string::npos);
        mn194 = 0;
        Slot11_acd938();
        break;
    }
}
#endif

// FUNCTION: 0x0090818e
bool cUnk00acd938::Slot10_acd938()
{
    Fn008fe7b8();
    Fn008ffac2();
    Fn00905cf0(0);
    if (mnE8 != 4) {
        return false;
    }
    return Fn009080a2();
}
