#include "gzcom/cRZString.h"

#include <ctype.h>
#include <string.h>
#include <wctype.h>

#include <algorithm>
#include <vector>

#include "gzcom/RZTextEncoding.h"

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

// FUNCTION: 0x0090eac5
void cRZString::MakeLower()
{
    for (iterator it = begin(), last = end(); it != last; ++it) {
        char c = *it;
        if (static_cast<uint8_t>(c) >= 0x7f) {
            // Not ASCII: lower the whole string as UTF-16, on the stack when it fits.
            uint32_t length = size();
            std::vector<uint16_t> heapBuffer;
            uint16_t localBuffer[256];
            uint16_t* buffer = localBuffer;
            if (length > 256) {
                heapBuffer.resize(length);
                buffer = &heapBuffer[0];
            }
            RZStringToEncoding(*this, buffer, length, kRZEncodingUTF16);
            for (uint32_t i = 0; i < length; i++) {
                buffer[i] = static_cast<uint16_t>(towlower(buffer[i]));
            }
            RZEncodingToString(buffer, length, kRZEncodingUTF16, *this);
            return;
        }
        if (isupper(c)) {
            c = static_cast<char>(tolower(c));
        }
        *it = c;
    }
}

// FUNCTION: 0x0090eb8e
void cRZString::MakeUpper()
{
    for (iterator it = begin(), last = end(); it != last; ++it) {
        char c = *it;
        if (static_cast<uint8_t>(c) >= 0x7f) {
            uint32_t length = size();
            std::vector<uint16_t> heapBuffer;
            uint16_t localBuffer[256];
            uint16_t* buffer = localBuffer;
            if (length > 256) {
                heapBuffer.resize(length);
                buffer = &heapBuffer[0];
            }
            RZStringToEncoding(*this, buffer, length, kRZEncodingUTF16);
            for (uint32_t i = 0; i < length; i++) {
                buffer[i] = static_cast<uint16_t>(towupper(buffer[i]));
            }
            RZEncodingToString(buffer, length, kRZEncodingUTF16, *this);
            return;
        }
        if (islower(c)) {
            c = static_cast<char>(toupper(c));
        }
        *it = c;
    }
}

// FUNCTION: 0x0090ec57
bool cRZString::IsEqual(const cIGZString& other, bool caseSensitive) const
{
    if (size() != other.Strlen()) {
        return false;
    }
    if (caseSensitive) {
        return strncmp(c_str(), other.Data(), size()) == 0;
    }
    cRZString lowerThis(*this);
    cRZString lowerOther(other.Data(), size());
    lowerThis.MakeLower();
    lowerOther.MakeLower();
    if (lowerThis.size() != lowerOther.size()) {
        return false;
    }
    return memcmp(lowerThis.data(), lowerOther.data(), lowerThis.size()) == 0;
}

// FUNCTION: 0x0090ed5d
bool cRZString::IsEqual(const char* other, uint32_t length, bool caseSensitive) const
{
    if (length == kUnknownLength) {
        length = strlen(other);
    }
    if (size() != length) {
        return false;
    }
    if (caseSensitive) {
        return strncmp(c_str(), other, size()) == 0;
    } else {
        cRZString lowerThis(*this);
        cRZString lowerOther(other, length);
        lowerThis.MakeLower();
        lowerOther.MakeLower();
        if (lowerThis.size() != lowerOther.size()) {
            return false;
        }
        return memcmp(lowerThis.data(), lowerOther.data(), lowerThis.size()) == 0;
    }
}

// FUNCTION: 0x0090ee61
int32_t cRZString::CompareTo(const cIGZString& other, bool caseSensitive) const
{
    uint32_t otherLength = other.Strlen();
    uint32_t length = size();
    const uint32_t& count = std::min(length, otherLength);
    int32_t result;
    if (caseSensitive) {
        result = strncmp(c_str(), other.Data(), count);
    } else {
        cRZString lowerThis(*this);
        cRZString lowerOther(other.Data(), other.Strlen());
        lowerThis.MakeLower();
        lowerOther.MakeLower();
        result = memcmp(lowerThis.data(), lowerOther.data(), std::min(lowerThis.size(), lowerOther.size()));
    }
    if (result == 0) {
        result = size() - other.Strlen();
    }
    return result;
}

// FUNCTION: 0x0090ef5b
int32_t cRZString::CompareTo(const char* other, uint32_t length, bool caseSensitive) const
{
    if (length == kUnknownLength) {
        length = strlen(other);
    }
    uint32_t thisLength = size();
    const uint32_t& count = std::min(thisLength, length);
    int32_t result;
    if (caseSensitive) {
        result = strncmp(c_str(), other, count);
    } else {
        cRZString lowerThis(*this);
        cRZString lowerOther(other, length);
        lowerThis.MakeLower();
        lowerOther.MakeLower();
        result = memcmp(lowerThis.data(), lowerOther.data(), std::min(lowerThis.size(), lowerOther.size()));
    }
    if (result == 0) {
        result = size() - length;
    }
    return result;
}

// FUNCTION: 0x0090f0db
int32_t cRZString::Find(const char* other, uint32_t position, bool caseSensitive) const
{
    if (caseSensitive) {
        return find(other, position);
    }
    cRZString lowerThis(*this);
    cRZString lowerOther(other, strlen(other));
    lowerThis.MakeLower();
    lowerOther.MakeLower();
    return lowerThis.find(lowerOther.c_str(), position);
}

// FUNCTION: 0x0090f16c
int32_t cRZString::Find(const cIGZString& other, uint32_t position, bool caseSensitive) const
{
    if (caseSensitive) {
        return find(other.ToChar(), position);
    }
    cRZString lowerThis(*this);
    cRZString lowerOther(other);
    lowerThis.MakeLower();
    lowerOther.MakeLower();
    return lowerThis.find(lowerOther.c_str(), position);
}

// FUNCTION: 0x0090f1fb
int32_t cRZString::RFind(const char* other, uint32_t position, bool caseSensitive) const
{
    if (caseSensitive) {
        return rfind(other, position);
    }
    cRZString lowerThis(*this);
    cRZString lowerOther(other, strlen(other));
    lowerThis.MakeLower();
    lowerOther.MakeLower();
    return lowerThis.rfind(lowerOther.c_str(), position);
}

// FUNCTION: 0x0090f28c
int32_t cRZString::RFind(const cIGZString& other, uint32_t position, bool caseSensitive) const
{
    if (caseSensitive) {
        return rfind(other.ToChar(), position);
    }
    cRZString lowerThis(*this);
    cRZString lowerOther(other);
    lowerThis.MakeLower();
    lowerOther.MakeLower();
    return lowerThis.rfind(lowerOther.c_str(), position);
}

// FUNCTION: 0x0090e443
bool cRZString::BeginsWith(const char* prefix, uint32_t length) const
{
    if (length <= size()) {
        for (uint32_t i = 0; i < length; i++) {
            if ((*this)[i] != prefix[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x0090e478
bool cRZString::EndsWith(const char* suffix, uint32_t length) const
{
    uint32_t ownLength = size();
    if (length <= ownLength) {
        for (uint32_t i = 1; i <= length; i++) {
            if ((*this)[ownLength - i] != suffix[length - i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x0090ea57
cRZString cRZString::Mid(uint32_t start, uint32_t count) const
{
    if (start >= size()) {
        return cRZString();
    }
    return cRZString(*this, start, std::min<size_t>(size() - start, count));
}

// FUNCTION: 0x0090f45f
cRZString cRZString::Left(uint32_t count) const
{
    if (count > size()) {
        return *this;
    }
    return Mid(0, count);
}

// FUNCTION: 0x0090f4b3
cRZString cRZString::Right(uint32_t count) const
{
    if (count > size()) {
        return *this;
    }
    return Mid(size() - count, count);
}

// FUNCTION: 0x0090f430
cRZString& cRZString::Assign(const char* source, uint32_t maxLength)
{
    size_t length = strlen(source);
    if (maxLength > length) {
        assign(source, source + length);
    } else {
        assign(source, source + maxLength);
    }
    return *this;
}

// FUNCTION: 0x0090ea42
cRZString& cRZString::operator+=(const char* text)
{
    append(text);
    return *this;
}

// FUNCTION: 0x0090f335
bool cRZString::SplitToken(char delimiter, cRZString& token)
{
    size_t position = find(delimiter);
    if (position == npos) {
        token.erase();
        swap(token);
        return false;
    }
    token.assign(*this, 0, position);
    erase(0, position + 1);
    return true;
}

// FUNCTION: 0x0090f39d
bool cRZString::NextToken(char delimiter, cRZString& token)
{
    for (;;) {
        size_t position = find(delimiter);
        if (position == npos) {
            if (empty()) {
                return false;
            }
            token.erase();
            token.swap(*this);
            return true;
        }
        size_t next = find_first_not_of(delimiter, position);
        if (position > 0) {
            token.assign(*this, 0, position);
            erase(0, next);
            return true;
        }
        erase(0, next);
    }
}

// FUNCTION: 0x0090e5dc
bool cRZString::SkipPast(char delimiter)
{
    size_t position = find(delimiter);
    if (position == npos) {
        erase(0, position);
        return false;
    }
    erase(0, position + 1);
    return true;
}

// FUNCTION: 0x0090e98c
cRZString cRZString::SplitAt(const char* delimiter)
{
    if (delimiter == NULL) {
        return *this;
    }
    size_t length = strlen(delimiter);
    if (length == 0) {
        return *this;
    }
    size_t position = find(delimiter, 0, length);
    if (position == npos) {
        return cRZString();
    }
    cRZString head(*this, 0, position);
    erase(0, position + length);
    return head;
}

// FUNCTION: 0x0090e869
void cRZString::TrimLeft()
{
    erase(0, find_first_not_of(" \t"));
}

// FUNCTION: 0x0090e887
void cRZString::TrimRight()
{
    erase(find_last_not_of(" \t") + 1);
}

// FUNCTION: 0x0090e8a6
void cRZString::Trim()
{
    TrimLeft();
    TrimRight();
}

// FUNCTION: 0x0090e901
void RZUnicodeToString(const RZUnicodeString& source, cRZString& dest)
{
    dest.resize(0);
    int i = 0;
    int length = static_cast<int>(source.size());
    for (; i < length; i++) {
        if (source[i] <= 0x7f) {
            dest.push_back(static_cast<char>(source[i]));
        } else {
            dest.push_back('?');
        }
    }
}

// FUNCTION: 0x0090e953
void RZStringToUnicode(const cRZString& source, RZUnicodeString& dest)
{
    dest.resize(0);
    int i = 0;
    int length = static_cast<int>(source.size());
    for (; i < length; i++) {
        dest.push_back(source[i]);
    }
}
