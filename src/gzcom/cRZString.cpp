#include "gzcom/cRZString.h"

#include <string.h>

// FUNCTION: 0x0090e1d1
bool cRZString::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case GZIID_cIGZUnknown:
    case GZIID_cIGZString:
        *ppvObj = static_cast<cIGZString*>(this);
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x0094d34f
uint32_t cRZString::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x0090e1f3
uint32_t cRZString::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x0090f50f
void cRZString::FromChar(const char* source)
{
    if (source) {
        assign(source, source + strlen(source));
    } else {
        clear();
    }
}

// FUNCTION: 0x0090f546
void cRZString::FromChar(const char* source, uint32_t length)
{
    if (source) {
        assign(source, source + length);
    } else {
        clear();
    }
}

// FUNCTION: 0x009d7e63
const char* cRZString::ToChar() const
{
    return c_str();
}

// FUNCTION: 0x009d7e63 nohook
const char* cRZString::Data() const
{
    return data();
}

// FUNCTION: 0x0090e4b6
uint32_t cRZString::Strlen() const
{
    return size();
}

// FUNCTION: 0x0090e242
bool cRZString::IsEqual(const cIGZString* other, bool caseSensitive) const
{
    return IsEqual(*other, caseSensitive);
}
