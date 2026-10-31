// The component model's variant: a tagged value (flags 0x8000 = owned array), a COM pointer, or a string. Name from
// the reference build; its class has no generated header here, so this file keeps its own view. Vtable 0x00acecd0.
// Layout: vtable, the value at +4 (up to 8 bytes), the reference count at +0xc, the type at +0xe, the array length
// (or string size) at +0x10. Types: 1 bool, 2 u8, 3 s8, 4 u16, 5 s16, 6 u32, 7 s32, 8 u64, 9 s64, 10 float,
// 11 double, 12 char, 13 unicode char, 14 RZ char, 15 void*, 16 COM pointer.
#include <new>
#include <string.h>
#include "common/compiler.h"
#include "common/types.h"
#include "gzcom/cIGZString.h"
#include "gzcom/cIGZUnknown.h"
#include "gzcom/cRZString.h"

#define RZV_AS(T, f) (*reinterpret_cast<T*>(&(f)))

struct cRZVariant_acecd0 {
    virtual bool QueryInterface(uint32_t, void**);   // slot 0, 0x0
    virtual uint32_t AddRef();   // slot 1, 0x4
    virtual uint32_t Release();   // slot 2, 0x8
    // STUB: 0x005fd600
    virtual uint32_t GetType();   // slot 3, 0xc
    // STUB: 0x0040ce60
    virtual uint32_t GetCount();   // slot 4, 0x10
    virtual bool Erase();   // slot 5, 0x14
    virtual bool CopyFrom(void*);   // slot 6, 0x18
    virtual bool CreateCopy(void*);   // slot 7, 0x1c
    // STUB: 0x0091559a
    virtual bool CanGetVal();   // slot 8, 0x20
    virtual bool GetValBool_1();   // slot 9, 0x24
    virtual bool GetValBool_2(bool&);   // slot 10, 0x28
    // STUB: 0x00916657
    virtual void SetValBool(bool);   // slot 11, 0x2c
    virtual uint8_t GetValUint8_1();   // slot 12, 0x30
    virtual bool GetValUint8_2(uint8_t&);   // slot 13, 0x34
    // STUB: 0x0091665c
    virtual void SetValUint8(uint8_t);   // slot 14, 0x38
    virtual int8_t GetValSint8_1();   // slot 15, 0x3c
    virtual bool GetValSint8_2(int8_t&);   // slot 16, 0x40
    // STUB: 0x00916661
    virtual void SetValSint8(int8_t);   // slot 17, 0x44
    virtual uint16_t GetValUint16_1();   // slot 18, 0x48
    virtual bool GetValUint16_2(uint16_t&);   // slot 19, 0x4c
    // STUB: 0x00916666
    virtual void SetValUint16(uint16_t);   // slot 20, 0x50
    virtual int16_t GetValSint16_1();   // slot 21, 0x54
    virtual bool GetValSint16_2(int16_t&);   // slot 22, 0x58
    // STUB: 0x0091666b
    virtual void SetValSint16(int16_t);   // slot 23, 0x5c
    virtual uint32_t GetValUint32_1();   // slot 24, 0x60
    virtual bool GetValUint32_2(uint32_t&);   // slot 25, 0x64
    // STUB: 0x00916670
    virtual void SetValUint32(uint32_t);   // slot 26, 0x68
    virtual int32_t GetValSint32_1();   // slot 27, 0x6c
    virtual bool GetValSint32_2(int32_t&);   // slot 28, 0x70
    // STUB: 0x00916675
    virtual void SetValSint32(int32_t);   // slot 29, 0x74
    virtual uint64_t GetValUint64_1();   // slot 30, 0x78
    // STUB: 0x00917780
    virtual bool GetValUint64_2(uint64_t&);   // slot 31, 0x7c
    virtual void SetValUint64(uint64_t);   // slot 32, 0x80
    virtual int64_t GetValSint64_1();   // slot 33, 0x84
    virtual bool GetValSint64_2(int64_t&);   // slot 34, 0x88
    virtual void SetValSint64(int64_t);   // slot 35, 0x8c
    virtual float GetValFloat32_1();   // slot 36, 0x90
    virtual bool GetValFloat32_2(float&);   // slot 37, 0x94
    virtual void SetValFloat32(float);   // slot 38, 0x98
    virtual double GetValFloat64_1();   // slot 39, 0x9c
    // STUB: 0x009178b2
    virtual bool GetValFloat64_2(double&);   // slot 40, 0xa0
    virtual void SetValFloat64(double);   // slot 41, 0xa4
    virtual char GetValChar_1();   // slot 42, 0xa8
    virtual bool GetValChar_2(char&);   // slot 43, 0xac
    // STUB: 0x009166bb
    virtual void SetValChar(char);   // slot 44, 0xb0
    virtual uint16_t GetValRZUnicodeChar_1();   // slot 45, 0xb4
    virtual bool GetValRZUnicodeChar_2(uint16_t&);   // slot 46, 0xb8
    // STUB: 0x009166c0
    virtual void SetValRZUnicodeChar(uint16_t);   // slot 47, 0xbc
    virtual char GetValRZChar_1();   // slot 48, 0xc0
    virtual bool GetValRZChar_2(char&);   // slot 49, 0xc4
    // STUB: 0x009166c5
    virtual void SetValRZChar(char);   // slot 50, 0xc8
    virtual void* GetValVoidPtr_1();   // slot 51, 0xcc
    virtual bool GetValVoidPtr_2(void*&);   // slot 52, 0xd0
    // STUB: 0x009166ca
    virtual void SetValVoidPtr(void*);   // slot 53, 0xd4
    virtual bool CreateValString(void*);   // slot 54, 0xd8
    // STUB: 0x00917adb
    virtual bool GetValString(void*);   // slot 55, 0xdc
    // STUB: 0x009166cf
    virtual void SetValString(void*);   // slot 56, 0xe0
    virtual void* GetValUnknown_1();   // slot 57, 0xe4
    // STUB: 0x00915743
    virtual void GetValUnknown_2();   // slot 58, 0xe8
    virtual void SetValUnknown(void*);   // slot 59, 0xec
    // STUB: 0x00916644
    virtual uint32_t AsBool_1();   // slot 60, 0xf0
    // STUB: 0x0091663f
    virtual uint32_t AsBool_2();   // slot 61, 0xf4
    // STUB: 0x0040ce50
    virtual bool AsUint8_1();   // slot 62, 0xf8
    // STUB: 0x0060fb50
    virtual uint32_t AsUint8_2();   // slot 63, 0xfc
    // STUB: 0x0040ce50
    virtual bool AsSint8_1();   // slot 64, 0x100
    // STUB: 0x0060fb50
    virtual uint32_t AsSint8_2();   // slot 65, 0x104
    // STUB: 0x0040ce50
    virtual bool AsUint16_1();   // slot 66, 0x108
    // STUB: 0x0060fb50
    virtual uint32_t AsUint16_2();   // slot 67, 0x10c
    // STUB: 0x005fd610
    virtual uint32_t ASint16_1();   // slot 68, 0x110
    // STUB: 0x0060fb50
    virtual uint32_t AsSint16_2();   // slot 69, 0x114
    // STUB: 0x005fd610
    virtual uint32_t AsUint32_1();   // slot 70, 0x118
    // STUB: 0x0060fb50
    virtual uint32_t AsUint32_2();   // slot 71, 0x11c
    // STUB: 0x0060ce80
    virtual uint32_t AsSint32_1();   // slot 72, 0x120
    // STUB: 0x0060fb50
    virtual uint32_t AsSint32_2();   // slot 73, 0x124
    // STUB: 0x0060ce80
    virtual uint32_t AsUint64_1();   // slot 74, 0x128
    // STUB: 0x0060fb50
    virtual uint32_t AsUint64_2();   // slot 75, 0x12c
    // STUB: 0x005fd620
    virtual void AsSint64_1();   // slot 76, 0x130
    // STUB: 0x0060fb50
    virtual uint32_t AsSint64_2();   // slot 77, 0x134
    // STUB: 0x005fd620
    virtual void AsFloat32_1();   // slot 78, 0x138
    // STUB: 0x0060fb50
    virtual uint32_t AsFloat32_2();   // slot 79, 0x13c
    // STUB: 0x005fd630
    virtual float AsFloat64_1();   // slot 80, 0x140
    // STUB: 0x0060fb50
    virtual uint32_t AsFloat64_2();   // slot 81, 0x144
    // STUB: 0x005fd640
    virtual float AsChar_1();   // slot 82, 0x148
    // STUB: 0x0060fb50
    virtual uint32_t AsChar_2();   // slot 83, 0x14c
    // STUB: 0x0040ce50
    virtual bool AsRZUnicodeChar_1();   // slot 84, 0x150
    // STUB: 0x0060fb50
    virtual uint32_t AsRZUnicodeChar_2();   // slot 85, 0x154
    // STUB: 0x005fd610
    virtual uint32_t AsRZChar_1();   // slot 86, 0x158
    // STUB: 0x0060fb50
    virtual uint32_t AsRZChar_2();   // slot 87, 0x15c
    // STUB: 0x0040ce50
    virtual bool AsVoidPtr_1();   // slot 88, 0x160
    // STUB: 0x0060fb50
    virtual uint32_t AsVoidPtr_2();   // slot 89, 0x164
    // STUB: 0x0060ce80
    virtual uint32_t RefBool_1();   // slot 90, 0x168
    // STUB: 0x0060ce80
    virtual uint32_t RefBool_2();   // slot 91, 0x16c
    // STUB: 0x00914ee4
    virtual void RefUint8_1();   // slot 92, 0x170
    // STUB: 0x0060ce80
    virtual uint32_t RefUint8_2();   // slot 93, 0x174
    // STUB: 0x00914f45
    virtual void RefSint8_1();   // slot 94, 0x178
    // STUB: 0x0060ce80
    virtual uint32_t RefSint8_2();   // slot 95, 0x17c
    // STUB: 0x009150f8
    virtual void RefUint16_1();   // slot 96, 0x180
    // STUB: 0x0060ce80
    virtual uint32_t RefUint16_2();   // slot 97, 0x184
    // STUB: 0x00914fa6
    virtual void RefSint16_1();   // slot 98, 0x188
    // STUB: 0x0060ce80
    virtual uint32_t RefSint16_2();   // slot 99, 0x18c
    // STUB: 0x00915159
    virtual void RefUint32_1();   // slot 100, 0x190
    // STUB: 0x0060ce80
    virtual uint32_t RefUint32_2();   // slot 101, 0x194
    // STUB: 0x00915014
    virtual void RefSint32_1();   // slot 102, 0x198
    // STUB: 0x0060ce80
    virtual uint32_t RefSint32_2();   // slot 103, 0x19c
    // STUB: 0x009151c7
    virtual void RefUint64_1();   // slot 104, 0x1a0
    // STUB: 0x0060ce80
    virtual uint32_t RefUint64_2();   // slot 105, 0x1a4
    // STUB: 0x00915086
    virtual void RefSint64_1();   // slot 106, 0x1a8
    // STUB: 0x0060ce80
    virtual uint32_t RefSint64_2();   // slot 107, 0x1ac
    // STUB: 0x00915239
    virtual void RefFloat32_1();   // slot 108, 0x1b0
    // STUB: 0x0060ce80
    virtual uint32_t RefFloat32_2();   // slot 109, 0x1b4
    // STUB: 0x009152ab
    virtual void RefFloa64_1();   // slot 110, 0x1b8
    // STUB: 0x0060ce80
    virtual uint32_t RefFloat64_2();   // slot 111, 0x1bc
    // STUB: 0x0091531d
    virtual void RefChar_1();   // slot 112, 0x1c0
    // STUB: 0x0060ce80
    virtual uint32_t RefChar_2();   // slot 113, 0x1c4
    // STUB: 0x0091538f
    virtual void RefRZUnicodeChar_1();   // slot 114, 0x1c8
    // STUB: 0x0060ce80
    virtual uint32_t RefRZUnicodeChar_2();   // slot 115, 0x1cc
    // STUB: 0x009153f0
    virtual void RefRZChar_1();   // slot 116, 0x1d0
    // STUB: 0x0060ce80
    virtual uint32_t RefRZChar_2();   // slot 117, 0x1d4
    virtual void RefRZChar(const char* data, uint32_t length);   // slot 118, 0x1d8
    // STUB: 0x0060ce80
    virtual uint32_t RefVoidPtr_2();   // slot 119, 0x1dc
    // STUB: 0x009154bf
    virtual void RefVoid_1();   // slot 120, 0x1e0
    // STUB: 0x0060ce80
    virtual uint32_t RefVoid_2();   // slot 121, 0x1e4
    // STUB: 0x00915531
    virtual void RefIGZUnknown_1();   // slot 122, 0x1e8
    // STUB: 0x0060ce80
    virtual uint32_t RefIGZUnknown_2();   // slot 123, 0x1ec
    // STUB: 0x0091663f
    virtual uint32_t RefIGZUnknown_3();   // slot 124, 0x1f0
    // STUB: 0x00916644
    virtual void SlotPad125_acecd0();
    // STUB: 0x0060ce80
    virtual void SlotPad126_acecd0();
// 0x00915eb5 (the inline destructor; the scorer finds no symbol for it)
    virtual ~cRZVariant_acecd0()
    {
        Destroy();
    }

    uint32_t mnValueLo;
    uint32_t mnValueHi;
    uint16_t mnRefCount;
    uint16_t mnType;
    uint32_t mnCount;

    // The constructors are out of line in the original (called, never inlined).
    cRZVariant_acecd0();
    // STUB: 0x00915cb7
    cRZVariant_acecd0(void* p);
    // STUB: 0x00915d1d
    cRZVariant_acecd0(uint8_t v);
    cRZVariant_acecd0(bool v);
    cRZVariant_acecd0(uint16_t v);
    // STUB: 0x00915d6d
    cRZVariant_acecd0(uint32_t v);
    // STUB: 0x00915d94
    cRZVariant_acecd0(int32_t v);
    // STUB: 0x00915e0b
    cRZVariant_acecd0(float v);
    // STUB: 0x00915e32
    cRZVariant_acecd0(double v);
    // STUB: 0x00915dbb
    cRZVariant_acecd0(uint64_t v);
    // STUB: 0x00915de3
    cRZVariant_acecd0(int64_t v);
    // STUB: 0x00916712
    cRZVariant_acecd0(const cRZVariant_acecd0& other);
    // STUB: 0x0091673d
    cRZVariant_acecd0(cIGZUnknown* p);
    // STUB: 0x00915cde
    cRZVariant_acecd0(const cIGZString& str);
    // STUB: 0x00915e53
    cRZVariant_acecd0(void* data, uint32_t length, uint16_t type);

    void Destroy();
    void RefBool(const bool* data, uint32_t length);
    void RefUint8(const uint8_t* data, uint32_t length);
    void RefSint8(const int8_t* data, uint32_t length);
    void RefUint16(const uint16_t* data, uint32_t length);
    void RefSint16(const int16_t* data, uint32_t length);
    void RefUint32(const uint32_t* data, uint32_t length);
    void RefSint32(const int32_t* data, uint32_t length);
    void RefUint64(const uint64_t* data, uint32_t length);
    void RefSint64(const int64_t* data, uint32_t length);
    void RefFloat32(const float* data, uint32_t length);
    void RefFloat64(const double* data, uint32_t length);
    void RefChar(const char* data, uint32_t length);
    void RefRZUnicodeChar(const uint16_t* data, uint32_t length);
    void RefVoidPtr(void* const* data, uint32_t length);
    void RefVoid(void* data, uint32_t length);
    void SetValVoid(const void* data, uint32_t length);
    bool GetValVoid(void* dst, uint32_t& length);
    bool QueryHeld(uint32_t riid, void** ppv);
    void FromStringVirtual(cIGZString* str);
    // STUB: 0x009172a1
    bool GetValStringImpl(cIGZString& dst);
    bool GetValStringImplDraft(cIGZString& dst);
    void SetValUnknownImpl(cIGZUnknown* p);
    void SetBoolImpl(bool v);
    void SetUint8Impl(uint8_t v);
    void SetSint8Impl(int8_t v);
    void SetUint16Impl(uint16_t v);
    void SetSint16Impl(int16_t v);
    void SetUint32Impl(uint32_t v);
    void SetSint32Impl(int32_t v);
    void SetUint64Impl(uint64_t v);
    void SetSint64Impl(int64_t v);
    void SetFloat32Impl(float v);
    void SetFloat64Impl(double v);
    void SetCharImpl(char v);
    void SetRZUnicodeCharImpl(uint16_t v);
    void SetRZCharImpl(char v);
    void SetVoidPtrImpl(void* v);
    // STUB: 0x00915ec0
    cRZVariant_acecd0* Fn00915ec0(const cRZVariant_acecd0& other);
    // STUB: 0x009161db
    cRZVariant_acecd0* Fn009161db(const void* other);
};

// STUB: 0x00917350
bool Fn00917350(const cRZVariant_acecd0* src, cRZVariant_acecd0* dst);
// STUB: 0x00916eaa
bool Fn00916eaa(const cRZVariant_acecd0* src, cRZString* out);
// STUB: 0x009167c5
bool Fn009167c5(cRZString* src, cRZVariant_acecd0* dst);

// FUNCTION: 0x00914ea3
void cRZVariant_acecd0::Destroy()
{
    uint16_t type = mnType;
    if (type & 0x8000) {
        ::operator delete(OB_PTR(void, mnValueLo));
        mnCount = 0;
        mnValueLo = 0;
    } else if (type == 16) {
        cIGZUnknown* p = OB_PTR(cIGZUnknown, mnValueLo);
        if (p != 0) {
            p->Release();
        }
        mnValueLo = 0;
    }
    mnValueLo = 0;
    mnValueHi = 0;
    mnType = 0;
    mnCount = 0;
}

// FUNCTION: 0x00914e78
uint32_t cRZVariant_acecd0::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x00914e56
bool cRZVariant_acecd0::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0x60fd4d2b:
        *ppvObj = this;
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x00914e81
uint32_t cRZVariant_acecd0::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x00915592
bool cRZVariant_acecd0::Erase()
{
    Destroy();
    return true;
}

// FUNCTION: 0x00916649
bool cRZVariant_acecd0::CopyFrom(void* other)
{
    Fn009161db(other);
    return true;
}

// FUNCTION: 0x009157a3
void* cRZVariant_acecd0::GetValUnknown_1()
{
    if (mnType == 16) {
        return OB_PTR(void, mnValueLo);
    }
    return 0;
}

// FUNCTION: 0x0091663f
void cRZVariant_acecd0::SetValUnknown(void* p)
{
    SetValUnknownImpl(static_cast<cIGZUnknown*>(p));
}

// FUNCTION: 0x0091667a
void cRZVariant_acecd0::SetValUint64(uint64_t v)
{
    SetUint64Impl(v);
}

// FUNCTION: 0x0091668a
void cRZVariant_acecd0::SetValSint64(int64_t v)
{
    SetSint64Impl(v);
}

// FUNCTION: 0x0091669a
void cRZVariant_acecd0::SetValFloat32(float v)
{
    SetFloat32Impl(v);
}

// FUNCTION: 0x009166aa
void cRZVariant_acecd0::SetValFloat64(double v)
{
    SetFloat64Impl(v);
}

// FUNCTION: 0x0091559f
bool cRZVariant_acecd0::GetValBool_1()
{
    bool v = false;
    GetValBool_2(v);
    return v;
}

// FUNCTION: 0x009155b5
uint8_t cRZVariant_acecd0::GetValUint8_1()
{
    uint8_t v = 0;
    GetValUint8_2(v);
    return v;
}

// FUNCTION: 0x009155cb
int8_t cRZVariant_acecd0::GetValSint8_1()
{
    int8_t v = 0;
    GetValSint8_2(v);
    return v;
}

// FUNCTION: 0x009155e1
uint16_t cRZVariant_acecd0::GetValUint16_1()
{
    uint16_t v = 0;
    GetValUint16_2(v);
    return v;
}

// FUNCTION: 0x009155f8
int16_t cRZVariant_acecd0::GetValSint16_1()
{
    int16_t v = 0;
    GetValSint16_2(v);
    return v;
}

// FUNCTION: 0x0091560f
uint32_t cRZVariant_acecd0::GetValUint32_1()
{
    uint32_t v = 0;
    GetValUint32_2(v);
    return v;
}

// FUNCTION: 0x00915625
int32_t cRZVariant_acecd0::GetValSint32_1()
{
    int32_t v = 0;
    GetValSint32_2(v);
    return v;
}

// FUNCTION: 0x0091563b
uint64_t cRZVariant_acecd0::GetValUint64_1()
{
    uint64_t v = 0;
    GetValUint64_2(v);
    return v;
}

// FUNCTION: 0x00915659
int64_t cRZVariant_acecd0::GetValSint64_1()
{
    int64_t v = 0;
    GetValSint64_2(v);
    return v;
}

// FUNCTION: 0x0091567a
float cRZVariant_acecd0::GetValFloat32_1()
{
    float v = 0.0f;
    GetValFloat32_2(v);
    return v;
}

// FUNCTION: 0x00915694
double cRZVariant_acecd0::GetValFloat64_1()
{
    double v = 0.0;
    GetValFloat64_2(v);
    return v;
}

// FUNCTION: 0x009156af
char cRZVariant_acecd0::GetValChar_1()
{
    char v = 0;
    GetValChar_2(v);
    return v;
}

// FUNCTION: 0x009156c8
uint16_t cRZVariant_acecd0::GetValRZUnicodeChar_1()
{
    uint16_t v = 0;
    GetValRZUnicodeChar_2(v);
    return v;
}

// FUNCTION: 0x009156e2
char cRZVariant_acecd0::GetValRZChar_1()
{
    char v = 0;
    GetValRZChar_2(v);
    return v;
}

// FUNCTION: 0x009156fb
void* cRZVariant_acecd0::GetValVoidPtr_1()
{
    void* v = 0;
    GetValVoidPtr_2(v);
    return v;
}

// FUNCTION: 0x009157b1
void cRZVariant_acecd0::SetBoolImpl(bool v)
{
    uint16_t t = mnType;
    if (t != 1) {
        if (t != 0) {
            Destroy();
        }
        mnType = 1;
    }
    RZV_AS(bool, mnValueLo) = v;
}

// FUNCTION: 0x009157d9
void cRZVariant_acecd0::SetUint8Impl(uint8_t v)
{
    uint16_t t = mnType;
    if (t != 2) {
        if (t != 0) {
            Destroy();
        }
        mnType = 2;
    }
    RZV_AS(uint8_t, mnValueLo) = v;
}

// FUNCTION: 0x00915801
void cRZVariant_acecd0::SetSint8Impl(int8_t v)
{
    uint16_t t = mnType;
    if (t != 3) {
        if (t != 0) {
            Destroy();
        }
        mnType = 3;
    }
    RZV_AS(int8_t, mnValueLo) = v;
}

// FUNCTION: 0x00915829
void cRZVariant_acecd0::SetUint16Impl(uint16_t v)
{
    uint16_t t = mnType;
    if (t != 4) {
        if (t != 0) {
            Destroy();
        }
        mnType = 4;
    }
    RZV_AS(uint16_t, mnValueLo) = v;
}

// FUNCTION: 0x00915853
void cRZVariant_acecd0::SetSint16Impl(int16_t v)
{
    uint16_t t = mnType;
    if (t != 5) {
        if (t != 0) {
            Destroy();
        }
        mnType = 5;
    }
    RZV_AS(int16_t, mnValueLo) = v;
}

// FUNCTION: 0x0091587d
void cRZVariant_acecd0::SetUint32Impl(uint32_t v)
{
    uint16_t t = mnType;
    if (t != 6) {
        if (t != 0) {
            Destroy();
        }
        mnType = 6;
    }
    mnValueLo = v;
}

// FUNCTION: 0x009158a5
void cRZVariant_acecd0::SetSint32Impl(int32_t v)
{
    uint16_t t = mnType;
    if (t != 7) {
        if (t != 0) {
            Destroy();
        }
        mnType = 7;
    }
    RZV_AS(int32_t, mnValueLo) = v;
}

// FUNCTION: 0x009158cd
void cRZVariant_acecd0::SetUint64Impl(uint64_t v)
{
    uint16_t t = mnType;
    if (t != 8) {
        if (t != 0) {
            Destroy();
        }
        mnType = 8;
    }
    RZV_AS(uint64_t, mnValueLo) = v;
}

// FUNCTION: 0x009158fc
void cRZVariant_acecd0::SetSint64Impl(int64_t v)
{
    uint16_t t = mnType;
    if (t != 9) {
        if (t != 0) {
            Destroy();
        }
        mnType = 9;
    }
    RZV_AS(int64_t, mnValueLo) = v;
}

// FUNCTION: 0x0091592b
void cRZVariant_acecd0::SetFloat32Impl(float v)
{
    uint16_t t = mnType;
    if (t != 10) {
        if (t != 0) {
            Destroy();
        }
        mnType = 10;
    }
    RZV_AS(float, mnValueLo) = v;
}

// FUNCTION: 0x00915953
void cRZVariant_acecd0::SetFloat64Impl(double v)
{
    uint16_t t = mnType;
    if (t != 11) {
        if (t != 0) {
            Destroy();
        }
        mnType = 11;
    }
    RZV_AS(double, mnValueLo) = v;
}

// FUNCTION: 0x0091597b
void cRZVariant_acecd0::SetCharImpl(char v)
{
    uint16_t t = mnType;
    if (t != 12) {
        if (t != 0) {
            Destroy();
        }
        mnType = 12;
    }
    RZV_AS(char, mnValueLo) = v;
}

// FUNCTION: 0x009159a3
void cRZVariant_acecd0::SetRZUnicodeCharImpl(uint16_t v)
{
    uint16_t t = mnType;
    if (t != 13) {
        if (t != 0) {
            Destroy();
        }
        mnType = 13;
    }
    RZV_AS(uint16_t, mnValueLo) = v;
}

// FUNCTION: 0x009159cd
void cRZVariant_acecd0::SetRZCharImpl(char v)
{
    uint16_t t = mnType;
    if (t != 14) {
        if (t != 0) {
            Destroy();
        }
        mnType = 14;
    }
    RZV_AS(char, mnValueLo) = v;
}

// FUNCTION: 0x009159f5
void cRZVariant_acecd0::SetVoidPtrImpl(void* v)
{
    uint16_t t = mnType;
    if (t != 15) {
        if (t != 0) {
            Destroy();
        }
        mnType = 15;
    }
    mnValueLo = OB_ADDR(v);
}

// FUNCTION: 0x00915a5f
void cRZVariant_acecd0::SetValUnknownImpl(cIGZUnknown* p)
{
    uint16_t t = mnType;
    if (t != 16) {
        if (t != 0) {
            Destroy();
        }
        mnType = 16;
    }
    if (p != OB_PTR(cIGZUnknown, mnValueLo)) {
        if (p != 0) {
            p->AddRef();
        }
        cIGZUnknown* old = OB_PTR(cIGZUnknown, mnValueLo);
        if (old != 0) {
            old->Release();
        }
        mnValueLo = OB_ADDR(p);
    }
}

// FUNCTION: 0x009166d4
cRZVariant_acecd0::cRZVariant_acecd0()
    : mnValueLo(0), mnValueHi(0), mnRefCount(0), mnType(0), mnCount(0)
{
}

// FUNCTION: 0x009174f6
bool cRZVariant_acecd0::GetValBool_2(bool& out)
{
    if (mnType == 1) {
        out = RZV_AS(bool, mnValueLo);
        return true;
    }
    bool ok = false;
    cRZVariant_acecd0 tmp((bool)0);
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(bool, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x0091754f
bool cRZVariant_acecd0::GetValUint8_2(uint8_t& out)
{
    if (mnType == 2) {
        out = RZV_AS(uint8_t, mnValueLo);
        return true;
    }
    bool ok = false;
    cRZVariant_acecd0 tmp((uint8_t)0);
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(uint8_t, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x00917607
bool cRZVariant_acecd0::GetValUint16_2(uint16_t& out)
{
    if (mnType == 4) {
        out = RZV_AS(uint16_t, mnValueLo);
        return true;
    }
    bool ok = false;
    cRZVariant_acecd0 tmp((uint16_t)0);
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(uint16_t, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x009176c8
bool cRZVariant_acecd0::GetValUint32_2(uint32_t& out)
{
    if (mnType == 6) {
        out = RZV_AS(uint32_t, mnValueLo);
        return true;
    }
    bool ok = false;
    cRZVariant_acecd0 tmp((uint32_t)0);
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(uint32_t, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x00917721
bool cRZVariant_acecd0::GetValSint32_2(int32_t& out)
{
    if (mnType == 7) {
        out = RZV_AS(int32_t, mnValueLo);
        return true;
    }
    cRZVariant_acecd0 tmp;
    bool ok = false;
    tmp.mnType = 7;
    tmp.mnValueLo = 0;
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(int32_t, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x00917a33
bool cRZVariant_acecd0::GetValVoidPtr_2(void*& out)
{
    if (mnType == 15) {
        out = OB_PTR(void, mnValueLo);
        return true;
    }
    bool ok = false;
    cRZVariant_acecd0 tmp(static_cast<void*>(0));
    if (Fn00917350(this, &tmp)) {
        out = OB_PTR(void, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x009175a8
bool cRZVariant_acecd0::GetValSint8_2(int8_t& out)
{
    if (mnType == 3) {
        out = RZV_AS(int8_t, mnValueLo);
        return true;
    }
    cRZVariant_acecd0 tmp;
    bool ok = false;
    tmp.mnType = 3;
    RZV_AS(int8_t, tmp.mnValueLo) = 0;
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(int8_t, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x00917664
bool cRZVariant_acecd0::GetValSint16_2(int16_t& out)
{
    if (mnType == 5) {
        out = RZV_AS(int16_t, mnValueLo);
        return true;
    }
    cRZVariant_acecd0 tmp;
    bool ok = false;
    tmp.mnType = 5;
    RZV_AS(int16_t, tmp.mnValueLo) = 0;
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(int16_t, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x00917911
bool cRZVariant_acecd0::GetValChar_2(char& out)
{
    if (mnType == 12) {
        out = RZV_AS(char, mnValueLo);
        return true;
    }
    cRZVariant_acecd0 tmp;
    bool ok = false;
    tmp.mnType = 12;
    RZV_AS(char, tmp.mnValueLo) = 0;
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(char, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x009179d4
bool cRZVariant_acecd0::GetValRZChar_2(char& out)
{
    if (mnType == 14) {
        out = RZV_AS(char, mnValueLo);
        return true;
    }
    cRZVariant_acecd0 tmp;
    bool ok = false;
    tmp.mnType = 14;
    RZV_AS(char, tmp.mnValueLo) = 0;
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(char, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x00917970
bool cRZVariant_acecd0::GetValRZUnicodeChar_2(uint16_t& out)
{
    if (mnType == 13) {
        out = RZV_AS(uint16_t, mnValueLo);
        return true;
    }
    cRZVariant_acecd0 tmp;
    bool ok = false;
    tmp.mnType = 13;
    RZV_AS(uint16_t, tmp.mnValueLo) = 0;
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(uint16_t, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x009177e4
bool cRZVariant_acecd0::GetValSint64_2(int64_t& out)
{
    if (mnType == 9) {
        out = RZV_AS(int64_t, mnValueLo);
        return true;
    }
    cRZVariant_acecd0 tmp;
    bool ok = false;
    tmp.mnType = 9;
    tmp.mnValueLo = 0;
    tmp.mnValueHi = 0;
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(int64_t, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00917780 score 2 (0 with the drafts compiled in: the draft callee Fn00917350 changes the register choice)
bool cRZVariant_acecd0::GetValUint64_2(uint64_t& out)
{
    if (mnType == 8) {
        out = RZV_AS(uint64_t, mnValueLo);
        return true;
    }
    bool ok = false;
    cRZVariant_acecd0 tmp(static_cast<uint64_t>(0));
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(uint64_t, tmp.mnValueLo);
        ok = true;
    }
    return ok;
}
#endif

// FUNCTION: 0x00917852
bool cRZVariant_acecd0::GetValFloat32_2(float& out)
{
    if (mnType == 10) {
        out = RZV_AS(float, mnValueLo);
        return true;
    }
    bool ok;
    cRZVariant_acecd0 tmp(0.0f);
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(float, tmp.mnValueLo);
        ok = true;
    } else {
        ok = false;
    }
    return ok;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009178b2 score 2 (0 with the drafts compiled in: the draft callee Fn00917350 changes the register choice)
bool cRZVariant_acecd0::GetValFloat64_2(double& out)
{
    if (mnType == 11) {
        out = RZV_AS(double, mnValueLo);
        return true;
    }
    bool ok;
    cRZVariant_acecd0 tmp(0.0);
    if (Fn00917350(this, &tmp)) {
        out = RZV_AS(double, tmp.mnValueLo);
        ok = true;
    } else {
        ok = false;
    }
    return ok;
}
#endif

// FUNCTION: 0x00915d44
cRZVariant_acecd0::cRZVariant_acecd0(uint16_t v)
    : mnValueLo(0), mnValueHi(0)
{
    RZV_AS(uint16_t, mnValueLo) = v;
    mnType = 4;
    mnCount = 0;
    mnRefCount = 0;
}

// FUNCTION: 0x00915e8e
cRZVariant_acecd0::cRZVariant_acecd0(bool v)
    : mnValueLo(0), mnValueHi(0)
{
    RZV_AS(bool, mnValueLo) = v;
    mnType = 1;
    mnCount = 0;
    mnRefCount = 0;
}

// FUNCTION: 0x00914ee4
void cRZVariant_acecd0::RefBool(const bool* data, uint32_t length)
{
    if (mnType == 0x8001 && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length);
    } else {
        Destroy();
        void* p = ::operator new(length);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, length);
        }
        mnCount = length;
        mnType = 0x8001;
    }
}

// FUNCTION: 0x00914f45
void cRZVariant_acecd0::RefUint8(const uint8_t* data, uint32_t length)
{
    if (mnType == 0x8002 && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length);
    } else {
        Destroy();
        void* p = ::operator new(length);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, length);
        }
        mnCount = length;
        mnType = 0x8002;
    }
}

// FUNCTION: 0x009150f8
void cRZVariant_acecd0::RefSint8(const int8_t* data, uint32_t length)
{
    if (mnType == 0x8003 && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length);
    } else {
        Destroy();
        void* p = ::operator new(length);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, length);
        }
        mnCount = length;
        mnType = 0x8003;
    }
}

// FUNCTION: 0x00914fa6
void cRZVariant_acecd0::RefUint16(const uint16_t* data, uint32_t length)
{
    if (mnType == 0x8004 && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length * 2);
    } else {
        Destroy();
        uint32_t bytes = length * 2;
        void* p = ::operator new(bytes);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, bytes);
        }
        mnCount = length;
        mnType = 0x8004;
    }
}

// FUNCTION: 0x00915159
void cRZVariant_acecd0::RefSint16(const int16_t* data, uint32_t length)
{
    if (mnType == 0x8005 && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length * 2);
    } else {
        Destroy();
        uint32_t bytes = length * 2;
        void* p = ::operator new(bytes);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, bytes);
        }
        mnCount = length;
        mnType = 0x8005;
    }
}

// FUNCTION: 0x00915014
void cRZVariant_acecd0::RefUint32(const uint32_t* data, uint32_t length)
{
    if (mnType == 0x8006 && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length * 4);
    } else {
        Destroy();
        uint32_t bytes = length * 4;
        void* p = ::operator new(bytes);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, bytes);
        }
        mnCount = length;
        mnType = 0x8006;
    }
}

// FUNCTION: 0x009151c7
void cRZVariant_acecd0::RefSint32(const int32_t* data, uint32_t length)
{
    if (mnType == 0x8007 && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length * 4);
    } else {
        Destroy();
        uint32_t bytes = length * 4;
        void* p = ::operator new(bytes);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, bytes);
        }
        mnCount = length;
        mnType = 0x8007;
    }
}

// FUNCTION: 0x00915086
void cRZVariant_acecd0::RefUint64(const uint64_t* data, uint32_t length)
{
    if (mnType == 0x8008 && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length * 8);
    } else {
        Destroy();
        uint32_t bytes = length * 8;
        void* p = ::operator new(bytes);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, bytes);
        }
        mnCount = length;
        mnType = 0x8008;
    }
}

// FUNCTION: 0x00915239
void cRZVariant_acecd0::RefSint64(const int64_t* data, uint32_t length)
{
    if (mnType == 0x8009 && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length * 8);
    } else {
        Destroy();
        uint32_t bytes = length * 8;
        void* p = ::operator new(bytes);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, bytes);
        }
        mnCount = length;
        mnType = 0x8009;
    }
}

// FUNCTION: 0x009152ab
void cRZVariant_acecd0::RefFloat32(const float* data, uint32_t length)
{
    if (mnType == 0x800a && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length * 4);
    } else {
        Destroy();
        uint32_t bytes = length * 4;
        void* p = ::operator new(bytes);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, bytes);
        }
        mnCount = length;
        mnType = 0x800a;
    }
}

// FUNCTION: 0x0091531d
void cRZVariant_acecd0::RefFloat64(const double* data, uint32_t length)
{
    if (mnType == 0x800b && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length * 8);
    } else {
        Destroy();
        uint32_t bytes = length * 8;
        void* p = ::operator new(bytes);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, bytes);
        }
        mnCount = length;
        mnType = 0x800b;
    }
}

// FUNCTION: 0x0091538f
void cRZVariant_acecd0::RefChar(const char* data, uint32_t length)
{
    if (mnType == 0x800c && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length);
    } else {
        Destroy();
        void* p = ::operator new(length);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, length);
        }
        mnCount = length;
        mnType = 0x800c;
    }
}

// FUNCTION: 0x009153f0
void cRZVariant_acecd0::RefRZUnicodeChar(const uint16_t* data, uint32_t length)
{
    if (mnType == 0x800d && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length * 2);
    } else {
        Destroy();
        uint32_t bytes = length * 2;
        void* p = ::operator new(bytes);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, bytes);
        }
        mnCount = length;
        mnType = 0x800d;
    }
}

// FUNCTION: 0x0091545e
void cRZVariant_acecd0::RefRZChar(const char* data, uint32_t length)
{
    if (mnType == 0x800e && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length);
    } else {
        Destroy();
        void* p = ::operator new(length);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, length);
        }
        mnCount = length;
        mnType = 0x800e;
    }
}

// FUNCTION: 0x009154bf
void cRZVariant_acecd0::RefVoidPtr(void* const* data, uint32_t length)
{
    if (mnType == 0x800f && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length * 4);
    } else {
        Destroy();
        uint32_t bytes = length * 4;
        void* p = ::operator new(bytes);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, bytes);
        }
        mnCount = length;
        mnType = 0x800f;
    }
}

// FUNCTION: 0x00915531
void cRZVariant_acecd0::RefVoid(void* data, uint32_t length)
{
    if (mnType == 0x8000 && mnCount == length && mnValueLo != 0 && data != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length);
    } else {
        Destroy();
        void* p = ::operator new(length);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, length);
        }
        mnCount = length;
        mnType = 0x8000;
    }
}

// FUNCTION: 0x00915743
void cRZVariant_acecd0::SetValVoid(const void* data, uint32_t length)
{
    if (mnType == 0x8000 && mnCount == length && mnValueLo != 0) {
        memcpy(OB_PTR(void, mnValueLo), data, length);
    } else {
        Destroy();
        void* p = ::operator new(length);
        mnValueLo = OB_ADDR(p);
        if (data != 0) {
            memcpy(p, data, length);
        }
        mnCount = length;
        mnType = 0x8000;
    }
}

// FUNCTION: 0x00915714
bool cRZVariant_acecd0::GetValVoid(void* dst, uint32_t& length)
{
    if (mnType == 0x8000) {
        uint32_t n = mnCount;
        if (length > n) {
            length = n;
        }
        memcpy(dst, OB_PTR(void, mnValueLo), length);
        return true;
    }
    return false;
}

// FUNCTION: 0x00915a46
bool cRZVariant_acecd0::QueryHeld(uint32_t riid, void** ppv)
{
    if (mnType == 16 && mnValueLo != 0) {
        return OB_PTR(cIGZUnknown, mnValueLo)->QueryInterface(riid, ppv);
    }
    return false;
}

// FUNCTION: 0x00915a1d
void cRZVariant_acecd0::FromStringVirtual(cIGZString* str)
{
    RefRZChar(str->Data(), str->Strlen());
}

// FUNCTION: 0x00916768
bool cRZVariant_acecd0::CreateCopy(void* ppOut)
{
    cRZVariant_acecd0* p = new cRZVariant_acecd0(*this);
    p->AddRef();
    *reinterpret_cast<cRZVariant_acecd0**>(ppOut) = p;
    return true;
}

// FUNCTION: 0x00917a8c
bool cRZVariant_acecd0::CreateValString(void* ppOut)
{
    cRZString* str = new cRZString();
    str->AddRef();
    if (GetValStringImpl(*str)) {
        *reinterpret_cast<cRZString**>(ppOut) = str;
        return true;
    }
    str->Release();
    *reinterpret_cast<cRZString**>(ppOut) = 0;
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00915aa5 score 26
bool Fn00915aa5(const cRZVariant_acecd0* src, cRZVariant_acecd0* dst)
{
    dst->mnRefCount = 0;
    dst->mnCount = 0;
    int32_t v;
    switch (src->mnType) {
    case 1:
    case 2:
        v = RZV_AS(const uint8_t, src->mnValueLo);
        dst->mnType = 8;
        RZV_AS(int64_t, dst->mnValueLo) = v;
        return true;
    case 4:
        v = RZV_AS(const uint16_t, src->mnValueLo);
        dst->mnType = 8;
        RZV_AS(int64_t, dst->mnValueLo) = v;
        return true;
    case 6:
        dst->mnType = 8;
        RZV_AS(uint64_t, dst->mnValueLo) = src->mnValueLo;
        return true;
    case 8:
        dst->mnValueLo = src->mnValueLo;
        dst->mnValueHi = src->mnValueHi;
        dst->mnType = 8;
        return true;
    case 9:
        dst->mnValueLo = src->mnValueLo;
        dst->mnValueHi = src->mnValueHi;
        dst->mnType = 9;
        return true;
    case 10:
        RZV_AS(int64_t, dst->mnValueLo) = static_cast<int64_t>(RZV_AS(const float, src->mnValueLo));
        dst->mnType = 9;
        return true;
    case 11:
        RZV_AS(int64_t, dst->mnValueLo) = static_cast<int64_t>(RZV_AS(const double, src->mnValueLo));
        dst->mnType = 9;
        return true;
    case 3:
    case 12:
    case 14:
        v = RZV_AS(const int8_t, src->mnValueLo);
        break;
    case 5:
        v = RZV_AS(const int16_t, src->mnValueLo);
        break;
    case 13:
        v = RZV_AS(const uint16_t, src->mnValueLo);
        break;
    default:
        v = RZV_AS(const int32_t, src->mnValueLo);
        break;
    }
    dst->mnType = 9;
    RZV_AS(int64_t, dst->mnValueLo) = v;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915b85 score 110
bool Fn00915b85(const cRZVariant_acecd0* src, cRZVariant_acecd0* dst)
{
    dst->mnRefCount = 0;
    dst->mnCount = 0;
    dst->mnType = 11;
    double d;
    switch (src->mnType) {
    case 1:
    case 2:
        d = static_cast<double>(RZV_AS(const uint8_t, src->mnValueLo));
        break;
    case 3:
    case 12:
    case 14:
        d = static_cast<double>(RZV_AS(const int8_t, src->mnValueLo));
        break;
    case 4:
    case 13:
        d = static_cast<double>(RZV_AS(const uint16_t, src->mnValueLo));
        break;
    case 5:
        d = static_cast<double>(RZV_AS(const int16_t, src->mnValueLo));
        break;
    case 6:
        d = static_cast<double>(src->mnValueLo);
        break;
    case 7:
        d = static_cast<double>(RZV_AS(const int32_t, src->mnValueLo));
        break;
    case 8:
        d = static_cast<double>(RZV_AS(const uint64_t, src->mnValueLo));
        break;
    case 9:
        d = static_cast<double>(RZV_AS(const int64_t, src->mnValueLo));
        break;
    case 10:
        d = RZV_AS(const float, src->mnValueLo);
        break;
    case 11:
        d = RZV_AS(const double, src->mnValueLo);
        break;
    default:
        d = 0.0;
        break;
    }
    RZV_AS(double, dst->mnValueLo) = d;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00917350 score 151
bool Fn00917350Draft_acecd0(const cRZVariant_acecd0* src, cRZVariant_acecd0* dst)
{
    uint16_t st = src->mnType;
    uint16_t dt = dst->mnType;
    if (st < 1 || st > 14 || dt < 1 || dt > 14) {
        cRZString str;
        if (Fn00916eaa(src, &str) && Fn009167c5(&str, dst)) {
            return true;
        }
        return false;
    }
    if (dt == 11) {
        return Fn00915b85(src, dst);
    }
    if (dt == 10) {
        cRZVariant_acecd0 tmp;
        Fn00915b85(src, &tmp);
        dst->mnRefCount = 0;
        RZV_AS(float, dst->mnValueLo) = static_cast<float>(RZV_AS(double, tmp.mnValueLo));
        return true;
    }
    cRZVariant_acecd0 tmp;
    Fn00915aa5(src, &tmp);
    dst->mnRefCount = 0;
    dst->mnCount = 0;
    switch (dt) {
    case 1:
        dst->mnValueLo = (tmp.mnValueLo | tmp.mnValueHi) != 0 ? 1 : 0;
        dst->mnType = 1;
        break;
    case 2:
    case 3:
    case 12:
    case 14:
        RZV_AS(uint8_t, dst->mnValueLo) = RZV_AS(uint8_t, tmp.mnValueLo);
        break;
    case 4:
    case 5:
    case 13:
        RZV_AS(uint16_t, dst->mnValueLo) = RZV_AS(uint16_t, tmp.mnValueLo);
        break;
    case 6:
    case 7:
        dst->mnValueLo = tmp.mnValueLo;
        break;
    case 8:
    case 9:
        dst->mnValueLo = tmp.mnValueLo;
        dst->mnValueHi = tmp.mnValueHi;
        break;
    default:
        dst->mnValueLo = 0;
        break;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009172a1 score 11
bool cRZVariant_acecd0::GetValStringImplDraft(cIGZString& dst)
{
    if (mnType == 0x800e) {
        dst.FromChar(OB_PTR(const char, mnValueLo), mnCount);
        return true;
    }
    if (mnType == 16) {
        cIGZString* s = 0;
        if (OB_PTR(cIGZUnknown, mnValueLo)->QueryInterface(0x089b7dc8, reinterpret_cast<void**>(&s))) {
            dst.FromChar(s->Data(), s->Strlen());
            s->Release();
            return true;
        }
    }
    cRZString str;
    Fn00916eaa(this, &str);
    dst.FromChar(str.c_str(), static_cast<uint32_t>(str.end() - str.begin()));
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915cb7 score 1
cRZVariant_acecd0::cRZVariant_acecd0(void* p)
    : mnValueLo(0), mnValueHi(0)
{
    mnValueLo = OB_ADDR(p);
    mnType = 15;
    mnCount = 0;
    mnRefCount = 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915d1d score 2
cRZVariant_acecd0::cRZVariant_acecd0(uint8_t v)
    : mnValueLo(0), mnValueHi(0)
{
    RZV_AS(uint8_t, mnValueLo) = v;
    mnType = 2;
    mnCount = 0;
    mnRefCount = 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915d6d score 1
cRZVariant_acecd0::cRZVariant_acecd0(uint32_t v)
    : mnValueLo(0), mnValueHi(0)
{
    mnValueLo = v;
    mnType = 6;
    mnCount = 0;
    mnRefCount = 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915d94 score 1
cRZVariant_acecd0::cRZVariant_acecd0(int32_t v)
    : mnValueLo(0), mnValueHi(0)
{
    RZV_AS(int32_t, mnValueLo) = v;
    mnType = 7;
    mnCount = 0;
    mnRefCount = 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915e0b score 1
cRZVariant_acecd0::cRZVariant_acecd0(float v)
    : mnValueLo(0), mnValueHi(0)
{
    mnValueLo = RZV_AS(uint32_t, v);
    mnType = 10;
    mnCount = 0;
    mnRefCount = 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915e32 score 5
cRZVariant_acecd0::cRZVariant_acecd0(double v)
    : mnCount(0), mnRefCount(0)
{
    RZV_AS(double, mnValueLo) = v;
    mnType = 11;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915dbb score 11
cRZVariant_acecd0::cRZVariant_acecd0(uint64_t v)
    : mnCount(0), mnRefCount(0)
{
    RZV_AS(uint64_t, mnValueLo) = v;
    mnType = 8;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915de3 score 11
cRZVariant_acecd0::cRZVariant_acecd0(int64_t v)
    : mnCount(0), mnRefCount(0)
{
    RZV_AS(int64_t, mnValueLo) = v;
    mnType = 9;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00916712 score 7
cRZVariant_acecd0::cRZVariant_acecd0(const cRZVariant_acecd0& other)
    : mnValueLo(0), mnValueHi(0), mnRefCount(0), mnType(0), mnCount(0)
{
    Fn00915ec0(other);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0091673d score 7
cRZVariant_acecd0::cRZVariant_acecd0(cIGZUnknown* p)
    : mnValueLo(0), mnValueHi(0), mnRefCount(0), mnType(0), mnCount(0)
{
    SetValUnknownImpl(p);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915cde score 6
cRZVariant_acecd0::cRZVariant_acecd0(const cIGZString& str)
    : mnValueLo(0), mnValueHi(0), mnRefCount(0), mnType(0), mnCount(0)
{
    RefRZChar(str.Data(), str.Strlen());
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00915e53 score 21
cRZVariant_acecd0::cRZVariant_acecd0(void* data, uint32_t length, uint16_t type)
    : mnValueLo(0), mnValueHi(0), mnCount(0), mnType(0), mnRefCount(0)
{
    RefVoid(data, length);
    mnType = static_cast<uint16_t>(type | 0x8000);
}
#endif
