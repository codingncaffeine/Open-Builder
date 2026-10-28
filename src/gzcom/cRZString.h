// The component model's string: cIGZString over a standard string (STLport 4.6 in the original), reference
// counted. Name assumed (the binary keeps none; RZ is the framework's prefix for concrete classes). Layout in the
// original: vtable, the string's three pointers at +0x04, the reference count at +0x10. Vtable 0x00a80810.
#ifndef OB_GZCOM_CRZSTRING_H
#define OB_GZCOM_CRZSTRING_H

#include <string>

#include "gzcom/cIGZString.h"

// The string is a base, not a member: the original stores the vtable after the string is built, which is where a
// constructor stores it after its bases and before its members.
class cRZString : public cIGZString, public std::string {
public:
    cRZString();
    cRZString(const char* source);
    cRZString(const char* source, size_t length);
    cRZString(const cIGZString& source);
    cRZString(const std::string& source);
    // The copy constructor, and a substring of another string.
    cRZString(const cRZString& source, size_t position = 0, size_t count = npos);
    virtual ~cRZString() {}

    bool QueryInterface(uint32_t riid, void** ppvObj);
    uint32_t AddRef();
    uint32_t Release();

    void FromChar(const char* source);
    void FromChar(const char* source, uint32_t length);
    const char* ToChar() const;
    const char* Data() const;
    uint32_t Strlen() const;
    bool IsEqual(const cIGZString* other, bool caseSensitive) const;
    bool IsEqual(const cIGZString& other, bool caseSensitive) const;
    bool IsEqual(const char* other, uint32_t length, bool caseSensitive) const;
    int32_t CompareTo(const cIGZString& other, bool caseSensitive) const;
    int32_t CompareTo(const char* other, uint32_t length, bool caseSensitive) const;
    cIGZString& operator=(const cIGZString& other);
    void Copy(const cIGZString& other);
    void Resize(uint32_t newSize);
    cIGZString* Append(const char* other, uint32_t length);
    cIGZString* Append(const cIGZString& other);
    cIGZString* Insert(uint32_t position, const char* other, uint32_t length);
    cIGZString* Insert(uint32_t position, const cIGZString& other);
    cIGZString* Replace(uint32_t start, const char* other, uint32_t length);
    cIGZString* Replace(uint32_t start, const cIGZString& other);
    cIGZString* Erase(uint32_t start, uint32_t end);
    int32_t Find(const char* other, uint32_t position, bool caseSensitive) const;
    int32_t Find(const cIGZString& other, uint32_t position, bool caseSensitive) const;
    int32_t RFind(const char* other, uint32_t position, bool caseSensitive) const;
    int32_t RFind(const cIGZString& other, uint32_t position, bool caseSensitive) const;
    cIGZString* Sprintf(const char* format, ...);

    // The copy assignment takes the text only; the reference count stays.
    cRZString& operator=(const cRZString& other);

    // Not in the interface: in place, ASCII through the C library, anything else through UTF-16.
    void MakeLower();
    void MakeUpper();
    bool BeginsWith(const char* prefix, uint32_t length) const;
    bool EndsWith(const char* suffix, uint32_t length) const;
    cRZString Mid(uint32_t start, uint32_t count) const;
    cRZString Left(uint32_t count) const;
    cRZString Right(uint32_t count) const;
    cRZString& Assign(const char* source, uint32_t maxLength);
    cRZString& operator+=(const char* text);
    // Moves the text before the first delimiter into token and drops it and the delimiter; without a
    // delimiter, moves all of the text and returns false.
    bool SplitToken(char delimiter, cRZString& token);
    // The same, skipping empty tokens and runs of delimiters; false only when no text is left.
    bool NextToken(char delimiter, cRZString& token);
    // Drops the text up to and including the first delimiter; false (and all text dropped) without one.
    bool SkipPast(char delimiter);
    // Takes the text before the first delimiter out of the string and returns it, the delimiter dropped; without
    // one, returns an empty string and leaves the string alone.
    cRZString SplitAt(const char* delimiter);
    // Spaces and tabs off the start, the end, or both.
    void TrimLeft();
    void TrimRight();
    void Trim();

protected:
    uint32_t mnRefCount;  // +0x10
};

// A UTF-16 code unit. The original's is unsigned short (the 2003 compiler has no char16_t); today's standard
// libraries define char_traits only for the standard character types.
#if defined(_MSC_VER) && _MSC_VER < 1600
typedef unsigned short RZUnicodeChar;
#else
typedef char16_t RZUnicodeChar;
#endif
typedef std::basic_string<RZUnicodeChar> RZUnicodeString;

// ASCII only: other characters become '?' one way and are sign-extended the other.
void RZUnicodeToString(const RZUnicodeString& source, cRZString& dest);
void RZStringToUnicode(const cRZString& source, RZUnicodeString& dest);
// Replaces dest's text with source's.
void RZStringFromStd(const std::string& source, cRZString& dest);

// The constructors are inline: the original has each one out of line once, from the first of its game sources that
// used it (built with the game's flags, see src/game/FLAGS), and the framework calls those.

// FUNCTION: 0x00578390
inline cRZString::cRZString()
    : mnRefCount(0)
{
}

// FUNCTION: 0x00408480
inline cRZString::cRZString(const char* source)
    : std::string(source), mnRefCount(0)
{
}

// FUNCTION: 0x0044abe0
inline cRZString::cRZString(const char* source, size_t length)
    : std::string(source, length), mnRefCount(0)
{
}

// FUNCTION: 0x0040ae00
inline cRZString::cRZString(const cIGZString& source)
    : std::string(source.Data(), source.Strlen()), mnRefCount(0)
{
}

// FUNCTION: 0x00408b90
inline cRZString::cRZString(const std::string& source)
    : std::string(source), mnRefCount(0)
{
}

// FUNCTION: 0x00408be0
inline cRZString::cRZString(const cRZString& source, size_t position, size_t count)
    : std::string(source, position, count), mnRefCount(0)
{
}

// FUNCTION: 0x00424380
inline cRZString& cRZString::operator=(const cRZString& other)
{
    std::string::operator=(other);
    return *this;
}

#endif
