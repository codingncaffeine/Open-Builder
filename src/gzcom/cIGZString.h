// The component model's string interface. Slot order as the original's vtables have it (0x00a80810); this
// compiler places a run of overloads in the vtable in reverse order of declaration, so each run is declared
// backwards from its slots.
#ifndef OB_GZCOM_CIGZSTRING_H
#define OB_GZCOM_CIGZSTRING_H

#include "gzcom/cIGZUnknown.h"

static const uint32_t GZIID_cIGZString = 0x089b7dc8;

class OB_NOVTABLE cIGZString : public cIGZUnknown {
public:
    virtual void FromChar(const char* source) = 0;
    virtual void FromChar(const char* source, uint32_t length) = 0;
    virtual const char* ToChar() const = 0;
    virtual const char* Data() const = 0;
    virtual uint32_t Strlen() const = 0;
    virtual bool IsEqual(const cIGZString& other, bool caseSensitive) const = 0;
    virtual bool IsEqual(const cIGZString* other, bool caseSensitive) const = 0;
    virtual bool IsEqual(const char* other, uint32_t length, bool caseSensitive) const = 0;
    virtual int32_t CompareTo(const cIGZString& other, bool caseSensitive) const = 0;
    virtual int32_t CompareTo(const char* other, uint32_t length, bool caseSensitive) const = 0;
    virtual cIGZString& operator=(const cIGZString& other) = 0;
    virtual void Copy(const cIGZString& other) = 0;
    virtual void Resize(uint32_t newSize) = 0;
    virtual cIGZString* Append(const char* other, uint32_t length) = 0;
    virtual cIGZString* Append(const cIGZString& other) = 0;
    virtual cIGZString* Insert(uint32_t position, const char* other, uint32_t length) = 0;
    virtual cIGZString* Insert(uint32_t position, const cIGZString& other) = 0;
    virtual cIGZString* Replace(uint32_t start, const char* other, uint32_t length) = 0;
    virtual cIGZString* Replace(uint32_t start, const cIGZString& other) = 0;
    virtual cIGZString* Erase(uint32_t start, uint32_t end) = 0;
    virtual int32_t Find(const char* other, uint32_t position, bool caseSensitive) const = 0;
    virtual int32_t Find(const cIGZString& other, uint32_t position, bool caseSensitive) const = 0;
    virtual int32_t RFind(const char* other, uint32_t position, bool caseSensitive) const = 0;
    virtual int32_t RFind(const cIGZString& other, uint32_t position, bool caseSensitive) const = 0;
    virtual cIGZString* Sprintf(const char* format, ...) = 0;
};

#endif
