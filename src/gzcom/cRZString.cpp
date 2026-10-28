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

// FUNCTION: 0x0090e230
cIGZString& cRZString::operator=(const cIGZString& other)
{
    Copy(other);
    return *this;
}

// FUNCTION: 0x0090e20a
void cRZString::Copy(const cIGZString& other)
{
    FromChar(other.Data(), other.Strlen());
}

// FUNCTION: 0x0090f042
void cRZString::Resize(uint32_t newSize)
{
    resize(newSize);
}

// FUNCTION: 0x0090f053
cIGZString* cRZString::Append(const char* other, uint32_t length)
{
    append(other, length);
    return this;
}

// FUNCTION: 0x0090f06c
cIGZString* cRZString::Append(const cIGZString& other)
{
    append(other.ToChar(), other.Strlen());
    return this;
}

// FUNCTION: 0x0090f093
cIGZString* cRZString::Insert(uint32_t position, const char* other, uint32_t length)
{
    insert(position, other, length);
    return this;
}

// FUNCTION: 0x0090f0b0
cIGZString* cRZString::Insert(uint32_t position, const cIGZString& other)
{
    insert(position, other.ToChar(), other.Strlen());
    return this;
}

// FUNCTION: 0x0090fc13
cIGZString* cRZString::Replace(uint32_t start, const char* other, uint32_t length)
{
    replace(start, length, other);
    return this;
}

// FUNCTION: 0x0090fc30
cIGZString* cRZString::Replace(uint32_t start, const cIGZString& other)
{
    replace(start, other.Strlen(), other.ToChar());
    return this;
}

// FUNCTION: 0x0090e4d8
cIGZString* cRZString::Erase(uint32_t start, uint32_t end)
{
    erase(start, end);
    return this;
}
