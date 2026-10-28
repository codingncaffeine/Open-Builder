#include "gzcom/cRZString.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>

#include <algorithm>
#include <vector>

#include "common/crt.h"
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

// FUNCTION: 0x0090fbe5
void RZStringFromStd(const std::string& source, cRZString& dest)
{
    dest = source;
}

// The text Sprintf builds: in the object (on the stack) while it fits, on the heap after. Names assumed.
class cRZCharBuffer {
public:
    char* Begin() const { return mpBegin; }
    char* End() const { return mpEnd; }
    uint32_t Size() const { return static_cast<uint32_t>(mpEnd - mpBegin); }
    uint32_t Capacity() const { return static_cast<uint32_t>(mpCapacityEnd - mpBegin); }

    void Reserve(uint32_t capacity);
    void Resize(uint32_t size);
    void PushBack(const char& c);
    void Append(const char* text, uint32_t length);
    void Append(uint32_t count, char c);

protected:
    char* mpBegin;
    char* mpEnd;
    char* mpCapacityEnd;
    char* mpHeap;
};

template <uint32_t N>
class cRZLocalCharBuffer : public cRZCharBuffer {
public:
    cRZLocalCharBuffer()
    {
        mpHeap = NULL;
        mpBegin = mLocal;
        mpEnd = mLocal;
        mpCapacityEnd = mLocal + N;
    }
    ~cRZLocalCharBuffer() { operator delete(mpHeap); }

private:
    char mLocal[N];
};

// FUNCTION: 0x0090e25c
void cRZCharBuffer::Reserve(uint32_t capacity)
{
    if (capacity >= Capacity()) {
        char* buffer = static_cast<char*>(operator new(capacity));
        uint32_t size = Size();
        memcpy(buffer, mpBegin, size);
        operator delete(mpHeap);
        mpHeap = buffer;
        mpBegin = buffer;
        mpEnd = buffer + size;
        mpCapacityEnd = buffer + capacity;
    }
}

// FUNCTION: 0x0090e2c8
void cRZCharBuffer::Resize(uint32_t size)
{
    if (size > Size()) {
        Reserve(size);
    }
    mpEnd = mpBegin + size;
}

// FUNCTION: 0x0090e2eb
void cRZCharBuffer::PushBack(const char& c)
{
    if (mpEnd == mpCapacityEnd) {
        Reserve(Capacity() * 2);
    }
    *mpEnd = c;
    mpEnd++;
}

// FUNCTION: 0x0090e312
void cRZCharBuffer::Append(const char* text, uint32_t length)
{
    if (static_cast<uint32_t>(mpCapacityEnd - mpEnd) < length) {
        Reserve(std::max(Capacity() * 2, Size() + length));
    }
    memcpy(mpEnd, text, length);
    mpEnd += length;
}

// FUNCTION: 0x0090e366
void cRZCharBuffer::Append(uint32_t count, char c)
{
    if (static_cast<uint32_t>(mpCapacityEnd - mpEnd) < count) {
        Reserve(std::max(Capacity() * 2, Size() + count));
    }
    std::fill(mpEnd, mpEnd + count, c);
    mpEnd += count;
}

// FUNCTION: 0x0090e247
bool RZIsDigit(char c)
{
    return c >= '0' && c <= '9';
}

// FUNCTION: 0x0090f574
cIGZString* cRZString::Sprintf(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    cRZLocalCharBuffer<64> number;
    cRZLocalCharBuffer<1024> text;

    for (;;) {
        char next = *format++;
        if (next == '\0') {
            break;
        }
        if (next == '%') {
            bool leftAlign = false;
            bool plus = false;
            bool space = false;
            bool zeroPad = false;
            bool alternate = false;
            char c;
            for (;;) {
                c = *format++;
                if (c == '-') {
                    leftAlign = true;
                } else if (c == '+') {
                    plus = true;
                } else if (c == ' ') {
                    space = true;
                } else if (c == '0') {
                    zeroPad = true;
                } else if (c == '#') {
                    alternate = true;
                } else {
                    break;
                }
            }
            if (c == '%') {
                text.PushBack(c);
                continue;
            }
            if (leftAlign) {
                zeroPad = false;
            }
            if (plus) {
                space = false;
            }

            int width = -1;
            if (c == '*') {
                width = va_arg(args, int);
                c = *format++;
            } else if (RZIsDigit(c)) {
                width = 0;
                do {
                    width = width * 10 + c - '0';
                    c = *format++;
                } while (RZIsDigit(c));
            }
            int precision = -1;
            if (c == '.') {
                c = *format++;
                if (c == '*') {
                    precision = va_arg(args, int);
                    c = *format++;
                } else if (RZIsDigit(c)) {
                    precision = 0;
                    do {
                        precision = precision * 10 + c - '0';
                        c = *format++;
                    } while (RZIsDigit(c));
                }
            }
            // h, none, l, then ll or I64
            int modifier = 1;
            switch (c) {
            case 'I':
                if (format[0] == '6' && format[1] == '4') {
                    format += 2;
                    c = *format++;
                    modifier = 3;
                }
                break;
            case 'h':
                c = *format++;
                modifier = 0;
                break;
            case 'l':
                c = *format++;
                modifier = 2;
                if (c == 'l') {
                    c = *format++;
                    modifier = 3;
                }
                break;
            }

            // The conversion, into the number buffer (or pointing at the argument for %s).
            const char* output = number.Begin();
            const char* end = output;
            bool isInteger = false;
            bool isSigned = false;
            bool isNegative = false;
            char spec[32];
            switch (c) {
            case 'd':
            case 'i':
                isSigned = true;
                // fall through
            case 'o':
            case 'u':
            case 'x':
            case 'X':
                isInteger = true;
                spec[0] = '%';
                switch (modifier) {
                case 0: {
                    short value = static_cast<short>(va_arg(args, int));
                    if (value < 0 && isSigned) {
                        isNegative = true;
                        value = static_cast<short>(-value);
                        c = 'u';
                    }
                    spec[1] = 'h';
                    spec[2] = c;
                    spec[3] = '\0';
                    end = output + sprintf(number.Begin(), spec, value);
                    break;
                }
                case 1: {
                    int value = va_arg(args, int);
                    if (value < 0 && isSigned) {
                        isNegative = true;
                        value = -value;
                        c = 'u';
                    }
                    spec[1] = c;
                    spec[2] = '\0';
                    end = output + sprintf(number.Begin(), spec, value);
                    break;
                }
                case 2: {
                    long value = va_arg(args, long);
                    if (value < 0 && isSigned) {
                        isNegative = true;
                        value = -value;
                        c = 'u';
                    }
                    spec[1] = 'l';
                    spec[2] = c;
                    spec[3] = '\0';
                    end = output + sprintf(number.Begin(), spec, value);
                    break;
                }
                case 3: {
                    // The 2003 runtime's spelling; the native port needs "ll" here.
                    int64_t value = va_arg(args, int64_t);
                    if (value < 0 && isSigned) {
                        isNegative = true;
                        value = -value;
                        c = 'u';
                    }
                    spec[1] = 'I';
                    spec[2] = '6';
                    spec[3] = '4';
                    spec[4] = c;
                    spec[5] = '\0';
                    end = output + sprintf(number.Begin(), spec, value);
                    break;
                }
                }
                break;
            case 'c':
                *number.Begin() = static_cast<char>(va_arg(args, int));
                end = output + 1;
                break;
            case 'e':
            case 'f':
            case 'g':
            case 'E':
            case 'G': {
                spec[0] = '%';
                char* p = spec + 1;
                if (alternate) {
                    *p++ = '#';
                }
                if (precision >= 0) {
                    *p++ = '.';
                    p += sprintf(p, "%d", precision);
                }
                double value = va_arg(args, double);
                p[0] = c;
                p[1] = '\0';
                isSigned = true;
                if (value < 0.0) {
                    isNegative = true;
                    value = -value;
                }
                int length;
                while ((length = OB_SNPRINTF(number.Begin(), number.Size(), spec, value)) < 0) {
                    number.Resize(number.Capacity() * 2);
                }
                output = number.Begin();
                end = output + length;
                break;
            }
            case 's': {
                output = va_arg(args, const char*);
                int length = static_cast<int>(strlen(output));
                if (precision >= 0) {
                    // the precision counts characters, not bytes
                    int bytes = length;
                    length = 0;
                    for (int characters = 0; length < bytes && characters < precision; characters++) {
                        int characterSize = RZCharacterSize(output + length, bytes - length, kRZEncodingString);
                        if (characterSize == 0) {
                            break;
                        }
                        length += characterSize;
                    }
                }
                end = output + length;
                break;
            }
            case 'p':
                end = output + sprintf(number.Begin(), "%p", va_arg(args, void*));
                break;
            case 'n':
                *va_arg(args, int*) = static_cast<int>(size());
                continue;
            case 'C':
            case 'S':
                // wide characters and strings are not supported
                format--;
                break;
            default:
                format--;
                break;
            }

            // Padding, sign and prefix around the conversion; widths count characters.
            int length = static_cast<int>(end - output);
            int characters = RZCharacterCount(output, length, kRZEncodingString);
            int zeros = 0;
            int padding = 0;
            char sign = '\0';
            const char* prefix = NULL;
            int prefixLength;
            if (isInteger) {
                if (precision > characters) {
                    zeros = precision - characters;
                }
                if (alternate) {
                    switch (c) {
                    case 'X':
                        prefix = "0X";
                        prefixLength = 2;
                        characters += 2;
                        break;
                    case 'o':
                        prefix = "0";
                        prefixLength = 1;
                        characters++;
                        break;
                    case 'x':
                        prefix = "0x";
                        prefixLength = 2;
                        characters += 2;
                        break;
                    }
                }
            }
            if (isSigned) {
                if (isNegative) {
                    sign = '-';
                } else {
                    if (space) {
                        sign = ' ';
                    }
                    if (plus) {
                        sign = '+';
                    }
                }
                if (sign != '\0') {
                    characters++;
                    if (zeroPad) {
                        text.PushBack(sign);
                    }
                }
            }
            if (width > 0) {
                padding = width - zeros - characters;
                if (padding > 0 && !leftAlign) {
                    text.Append(padding, zeroPad ? '0' : ' ');
                }
            }
            if (sign != '\0' && !zeroPad) {
                text.PushBack(sign);
            }
            if (prefix != NULL) {
                text.Append(prefix, prefixLength);
            }
            if (zeros > 0) {
                text.Append(zeros, '0');
            }
            text.Append(output, length);
            if (padding > 0 && leftAlign) {
                text.Append(padding, ' ');
            }
        } else {
            const char* run = format - 1;
            while (*format != '\0' && *format != '%') {
                format++;
            }
            text.Append(run, static_cast<uint32_t>(format - run));
        }
    }
    va_end(args);

    assign(static_cast<const char*>(text.Begin()), static_cast<const char*>(text.End()));
    return this;
}
