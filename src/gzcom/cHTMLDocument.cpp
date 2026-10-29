#include "classes/cHTMLDocument.h"
#include "gzcom/cRZString.h"
#include <string>

// GLOBAL: 0x00b6249c
extern uint32_t g00b6249c;
// GLOBAL: 0x00b62498
extern uint32_t g00b62498;

// STUB: 0x00462d10
void Fn00462d10(void* first, void* last, void* dst);

// Views of the raw bytes inside cHTMLDocument (the header keeps these as unknown bytes).
static inline cRZString& RZAt_acd938(cHTMLDocument* self, uint32_t off)
{
    return *reinterpret_cast<cRZString*>(reinterpret_cast<char*>(self) + off);
}

inline std::string& StrAt_acd938(cHTMLDocument* self, uint32_t off)
{
    return *reinterpret_cast<std::string*>(reinterpret_cast<char*>(self) + off);
}

// Shapes the original calls through; no instance of either is made here.
struct Sub_acd938 {
    virtual void QueryInterface() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual void Slot03_acd938() = 0;
    virtual void GetDocument() = 0;
    virtual void Slot05_acd938() = 0;
    virtual void GetFontSizeTable() = 0;
    virtual void SetFontSizeTable() = 0;
    virtual void ParseSGMLElements() = 0;
    virtual void ParseSGMLDocumentType() = 0;
    virtual bool ParseHTMLDocument(uint32_t, bool) = 0;
};

struct Entry_acd938 {
    char unknown0[0x30];
    Sub_acd938* mpSub;
};

#ifdef OB_DRAFTS
// CLOSE: 0x008fe759 score 16
bool cHTMLDocument::QueryInterface(unsigned int riid, void** ppv)
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
unsigned int cHTMLDocument::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x008fe7a1
unsigned int cHTMLDocument::Release()
{
    if (mnRefCount == 1) {
        delete this;
        return 0;
    }
    return --mnRefCount;
}

// FUNCTION: 0x008fe89e
void* cHTMLDocument::FindAnchor(uint32_t a)
{
    Entry_acd938** end = reinterpret_cast<Entry_acd938**>(mpEntryEnd);
    for (Entry_acd938** p = reinterpret_cast<Entry_acd938**>(mpEntryBegin); p != end; ++p) {
        Entry_acd938* e = *p;
        if (e->mpSub->ParseHTMLDocument(a, true)) {
            return e;
        }
    }
    return 0;
}

// FUNCTION: 0x008fee66
uint32_t cHTMLDocument::GetFontSizeTable(void* p, int32_t b)
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
void cHTMLDocument::SetFontSizeTable(void* p, int32_t b)
{
    int32_t seven = 7;
    const int32_t& n = (b > seven) ? seven : b;
    uint32_t* src = static_cast<uint32_t*>(p);
    Fn00462d10(src, src + n, &mnValues[0]);
    mn54 = mnValues[3];
    mn6c = mnValues[3];
}

// FUNCTION: 0x009006bb
void cHTMLDocument::Slot05_acd938(void* p)
{
    ParseSGMLElements(p);
}

// FUNCTION: 0x009006ca
uint32_t cHTMLDocument::GetActiveLinkColor()
{
    return g00b6249c;
}

// FUNCTION: 0x009006d0
uint32_t cHTMLDocument::GetVisitedLinkColor()
{
    return g00b62498;
}

// FUNCTION: 0x009006f2
void cHTMLDocument::GetDefaultVariableWidthFontInfo(void* s, void* out)
{
    *static_cast<cRZString*>(s) = RZAt_acd938(this, 0x40);
    *static_cast<uint32_t*>(out) = mn54;
}

// FUNCTION: 0x0090070f
void cHTMLDocument::GetDefaultFixedWidthFontInfo(void* s, void* out)
{
    *static_cast<cRZString*>(s) = RZAt_acd938(this, 0x58);
    *static_cast<uint32_t*>(out) = mn6c;
}

// FUNCTION: 0x009007a1
bool cHTMLDocument::GetBaseURL(void* p)
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
void cHTMLDocument::ParseSGMLElements(void* p)
{
    RZAt_acd938(this, 0x180) = *static_cast<cRZString*>(p);
    mn194 = 0;
    Fn008ffac2();
    Fn00905cf0(0);
    switch (mnE8) {
    case 2:
        ParseSGMLDocumentType();
        break;
    case 4:
        Fn009080a2();
        break;
    case 1:
    case 3:
    default:
        StrAt_acd938(this, 0x104).erase(0, std::string::npos);
        mn194 = 0;
        ParseTextDocument();
        break;
    }
}
#endif

// FUNCTION: 0x0090818e
bool cHTMLDocument::ParseHTMLDocument()
{
    Fn008fe7b8();
    Fn008ffac2();
    Fn00905cf0(0);
    if (mnE8 != 4) {
        return false;
    }
    return Fn009080a2();
}
