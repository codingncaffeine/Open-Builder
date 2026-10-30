#include "classes/cUnk00ad7cf0.h"
#include <stddef.h>
#include <new>
#include "gzcom/cRZString.h"

// Byte swaps as the original wrote them: a bswap in inline assembly on the argument slot.
#ifdef _MSC_VER
inline uint32_t Swap32_ad7cf0(uint32_t v)
{
    __asm {
        mov eax, v
        bswap eax
        mov v, eax
    }
    return v;
}
#else
inline uint32_t Swap32_ad7cf0(uint32_t v)
{
    return (v >> 24) | ((v >> 8) & 0xff00) | ((v << 8) & 0xff0000) | (v << 24);
}
#endif

inline uint32_t Swap16_ad7cf0(uint32_t v)
{
    return Swap32_ad7cf0(v) >> 16;
}

// STUB: 0x0092b55b
uint64_t OB_STDCALL Swizzle64(uint64_t v);


// A view of the primary vtable where the original tests the result of Slot37 that the base declares void.
struct Self_ad7cf0 {
    virtual void Pad0_ad7cf0();
    virtual void Pad1_ad7cf0();
    virtual void Pad2_ad7cf0();
    virtual void Pad3_ad7cf0();
    virtual void Pad4_ad7cf0();
    virtual void Pad5_ad7cf0();
    virtual void Pad6_ad7cf0();
    virtual void Pad7_ad7cf0();
    virtual void Pad8_ad7cf0();
    virtual void Pad9_ad7cf0();
    virtual void Pad10_ad7cf0();
    virtual void Pad11_ad7cf0();
    virtual void Pad12_ad7cf0();
    virtual void Pad13_ad7cf0();
    virtual void Pad14_ad7cf0();
    virtual void Pad15_ad7cf0();
    virtual void Pad16_ad7cf0();
    virtual void Pad17_ad7cf0();
    virtual void Pad18_ad7cf0();
    virtual void Pad19_ad7cf0();
    virtual void Pad20_ad7cf0();
    virtual void Pad21_ad7cf0();
    virtual void Pad22_ad7cf0();
    virtual void Pad23_ad7cf0();
    virtual void Pad24_ad7cf0();
    virtual void Pad25_ad7cf0();
    virtual void Pad26_ad7cf0();
    virtual void Pad27_ad7cf0();
    virtual void Pad28_ad7cf0();
    virtual void Pad29_ad7cf0();
    virtual void Pad30_ad7cf0();
    virtual void Pad31_ad7cf0();
    virtual void Pad32_ad7cf0();
    virtual void Pad33_ad7cf0();
    virtual void Pad34_ad7cf0();
    virtual void Pad35_ad7cf0();
    virtual void Pad36_ad7cf0();
    virtual bool Slot37b_ad7cf0(uint32_t value);
};

// A stream-like object: size at slot 7, data pointer at slot 6.
struct Source_ad7cf0 {
    virtual void Pad0_ad7cf0();
    virtual void Pad1_ad7cf0();
    virtual void Pad2_ad7cf0();
    virtual void Pad3_ad7cf0();
    virtual void Pad4_ad7cf0();
    virtual void Pad5_ad7cf0();
    virtual uint32_t Data6_ad7cf0();
    virtual uint32_t Size7_ad7cf0();
};

// GLOBAL: 0x00ad8c50
extern uint32_t g00ad8c50[];

// FUNCTION: 0x0097567e
uint32_t Fn0097567e(uint32_t a)
{
    uint32_t r = g00ad8c50[a & 0x7fff];
    if (a & 0x8000) {
        r |= 0x8000;
    }
    return r;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00975a17 score 38
bool cUnk00ad7cf0::Slot00_ad9030(uint32_t a, uint32_t b)
{
    bool r;
    if (a == 0x51b11bd) {
        *OB_PTR(cUnk00ad1878*, b) = this ? static_cast<cUnk00ad1878*>(this) : 0;
        Slot01_ad9030();
        r = true;
    } else if (a == 0xc51b11cb) {
        *OB_PTR(cGZPersistDBSerialRecord*, b) = this ? static_cast<cGZPersistDBSerialRecord*>(this) : 0;
        Slot01_ad9030();
        r = true;
    } else if (a == 0xc56b8f08) {
        *OB_PTR(cUnk00ad7cf0*, b) = this;
        Slot01_ad9030();
        r = true;
    } else {
        r = cUnk00ad8d48::Slot00_ad9030(a, b);
    }
    return r;
}
#endif

// FUNCTION: 0x00975a67
uint32_t cUnk00ad7cf0::Slot01_ad9030()
{
    return ++*reinterpret_cast<uint16_t*>(cUnk00ad8d48::unknown4);
}

// FUNCTION: 0x00975a78
void cUnk00ad7cf0::Slot05_ad8d88(uint32_t a)
{
    static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, 1);
}

// FUNCTION: 0x00975a86
void cUnk00ad7cf0::Slot21_ad8d88(uint32_t a)
{
    static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, 4);
}

// FUNCTION: 0x00975a94
void cUnk00ad7cf0::Slot20_ad8d88(uint32_t a, uint32_t b)
{
    static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, b << 2);
}

// FUNCTION: 0x00975aa8
void cUnk00ad7cf0::Slot23_ad8d88(uint32_t a)
{
    static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, 8);
}

// FUNCTION: 0x00975ab6
void cUnk00ad7cf0::Slot22_ad8d88(uint32_t a, uint32_t b)
{
    static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, b << 3);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00975aca score 6
void cUnk00ad7cf0::Slot25_ad8d88(uint32_t a)
{
    if (Slot13_ad8d88(a) && Slot13_ad8d88(a + 4)) {
        Slot13_ad8d88(a + 8);
    }
}
#endif

// FUNCTION: 0x00975aff
void cUnk00ad7cf0::Slot29_ad8d88(uint32_t a)
{
    static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(OB_ADDR(&a), 1);
}

// NOT ATTEMPTED: 0x00975b11 and 0x00972b73 are bare tail jumps (jmp [vptr+0xcc] / [vptr+0x6c]) that pass their own stack arguments on; the declared arguments (none) cannot express them.

// FUNCTION: 0x00975b19
void cUnk00ad7cf0::Slot45_ad8d88(uint32_t a)
{
    static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(OB_ADDR(&a), 4);
}

// FUNCTION: 0x00975b2b
void cUnk00ad7cf0::Slot44_ad8d88(uint32_t a, uint32_t b)
{
    static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(a, b << 2);
}

// FUNCTION: 0x00975b42
void cUnk00ad7cf0::Slot47_ad8d88(uint32_t a, uint32_t /*b*/)
{
    static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(OB_ADDR(&a), 8);
}

// FUNCTION: 0x00975b54
void cUnk00ad7cf0::Slot46_ad8d88(uint32_t a, uint32_t b)
{
    static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(a, b << 3);
}

// FUNCTION: 0x00975b76
void* cUnk00ad7cf0::Slot60_ad7cf0(uint32_t /*a*/)
{
    return static_cast<cGZPersistDBSerialRecord*>(this);
}

// FUNCTION: 0x00975b84
void* cUnk00ad7cf0::Slot59_ad7cf0(uint32_t a)
{
    Slot48_ad8d88(a);
    return static_cast<cGZPersistDBSerialRecord*>(this);
}

// FUNCTION: 0x00975ba2
void* cUnk00ad7cf0::Slot61_ad7cf0(uint32_t a)
{
    Slot24_ad8d88(a);
    return static_cast<cUnk00ad1878*>(this);
}

// NOT ATTEMPTED: 0x00975b6b 0x00975b9a 0x00975c08 0x00975c10 0x00975c34 are adjustor thunks (add ecx,-N; jmp [vptr+K]).

// FUNCTION: 0x00975bf2
void cUnk00ad7cf0::Slot57_ad7cf0(uint32_t a, uint32_t b, uint32_t c)
{
    static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, b * c);
}

// FUNCTION: 0x00975c1b
void cUnk00ad7cf0::Slot58_ad7cf0(uint32_t a, uint32_t b, uint32_t c)
{
    static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(a, b * c);
}

// FUNCTION: 0x00975d13
bool cUnk00ad7cf0::Slot09_ad8d88(uint32_t a)
{
    bool r = static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, 2);
    if (!mbNoSwap) {
        uint16_t* p = OB_PTR(uint16_t, a);
        *p = static_cast<uint16_t>(Swap16_ad7cf0(*p));
    }
    return r;
}

// FUNCTION: 0x00975d4c
bool cUnk00ad7cf0::Slot08_ad8d88(uint32_t a, uint32_t b)
{
    bool r = static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, b + b);
    if (!mbNoSwap) {
        uint16_t* p = OB_PTR(uint16_t, a);
        for (uint32_t i = 0; i < b; i++) {
            p[i] = static_cast<uint16_t>(Swap16_ad7cf0(p[i]));
        }
    }
    return r;
}

// FUNCTION: 0x00975d9a
bool cUnk00ad7cf0::Slot12_ad8d88(uint32_t a, uint32_t b)
{
    bool r = static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, b << 2);
    if (!mbNoSwap) {
        uint32_t* p = OB_PTR(uint32_t, a);
        for (uint32_t i = 0; i < b; i++) {
            p[i] = Swap32_ad7cf0(p[i]);
        }
    }
    return r;
}

// FUNCTION: 0x00975de5
bool cUnk00ad7cf0::Slot13_ad8d88(uint32_t a)
{
    bool r = static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, 4);
    if (!mbNoSwap) {
        uint32_t* p = OB_PTR(uint32_t, a);
        *p = Swap32_ad7cf0(*p);
    }
    return r;
}

// FUNCTION: 0x00975e19
bool cUnk00ad7cf0::Slot17_ad8d88(uint32_t a)
{
    bool r = static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, 8);
    if (!mbNoSwap) {
        uint64_t* p = OB_PTR(uint64_t, a);
        *p = Swizzle64(*p);
    }
    return r;
}

// FUNCTION: 0x00975e49
bool cUnk00ad7cf0::Slot16_ad8d88(uint32_t a, uint32_t b)
{
    bool r = static_cast<cUnk00ad8d88*>(this)->Slot04_ad9030(a, b << 3);
    if (!mbNoSwap) {
        uint64_t* p = OB_PTR(uint64_t, a);
        for (uint32_t i = 0; i < b; i++) {
            p[i] = Swizzle64(p[i]);
        }
    }
    return r;
}

// FUNCTION: 0x00975e97
void cUnk00ad7cf0::Slot33_ad8d88(uint32_t a)
{
    uint32_t v;
    if (mbNoSwap) {
        v = a;
    } else {
        v = Swap16_ad7cf0(static_cast<uint16_t>(a));
    }
    a = v;
    static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(OB_ADDR(&a), 2);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00975ed0
bool cUnk00ad7cf0::Slot32_ad8d88(uint32_t a, uint32_t b)
{
    bool r;
    if (mbNoSwap) {
        r = static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(a, b + b);
    } else {
        uint16_t stack[0x100];
        uint32_t n = b;
        uint16_t* heap;
        if (n > 0x100) {
            heap = static_cast<uint16_t*>(::operator new(n + n));
        } else {
            heap = 0;
        }
        uint16_t* dst = heap;
        if (!dst) {
            dst = stack;
        }
        if (n) {
            const uint16_t* src = OB_PTR(const uint16_t, a);
            uint16_t* d = dst;
            uint32_t k = n;
            do {
                *d = static_cast<uint16_t>(Swap16_ad7cf0(*src));
                d++;
                src++;
                k--;
            } while (k);
        }
        r = static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(OB_ADDR(dst), n + n);
        ::operator delete(heap);
    }
    return r;
}
#endif

// FUNCTION: 0x00975f74
void cUnk00ad7cf0::Slot37_ad8d88(uint32_t a)
{
    uint32_t v = a;
    if (!mbNoSwap) {
        v = Swap32_ad7cf0(v);
    }
    a = v;
    static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(OB_ADDR(&a), 4);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00975fa4
bool cUnk00ad7cf0::Slot36_ad8d88(uint32_t a, uint32_t b)
{
    bool r;
    if (mbNoSwap) {
        r = static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(a, b << 2);
    } else {
        uint32_t stack[0x100];
        uint32_t n = b;
        uint32_t* heap;
        if (n > 0x100) {
            heap = static_cast<uint32_t*>(::operator new(n << 2));
        } else {
            heap = 0;
        }
        uint32_t* dst = heap;
        if (!dst) {
            dst = stack;
        }
        if (n) {
            const uint32_t* src = OB_PTR(const uint32_t, a);
            uint32_t* d = dst;
            uint32_t k = n;
            do {
                *d = Swap32_ad7cf0(*src);
                d++;
                src++;
                k--;
            } while (k);
        }
        r = static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(OB_ADDR(dst), n << 2);
        ::operator delete(heap);
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00976049 score 25
void cUnk00ad7cf0::Slot41_ad8d88(uint32_t a, uint32_t b)
{
    uint64_t v;
    if (mbNoSwap) {
        v = (static_cast<uint64_t>(b) << 32) | a;
    } else {
        v = Swizzle64((static_cast<uint64_t>(b) << 32) | a);
    }
    static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(OB_ADDR(&v), 8);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097608b
bool cUnk00ad7cf0::Slot40_ad8d88(uint32_t a, uint32_t b)
{
    bool r;
    if (mbNoSwap) {
        r = static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(a, b << 3);
    } else {
        uint64_t stack[0x100];
        uint32_t n = b;
        uint64_t* heap;
        if (n > 0x100) {
            heap = static_cast<uint64_t*>(::operator new(n << 3));
        } else {
            heap = 0;
        }
        uint64_t* dst = heap;
        if (!dst) {
            dst = stack;
        }
        if (n) {
            const uint64_t* src = OB_PTR(const uint64_t, a);
            uint64_t* d = dst;
            uint32_t k = n;
            do {
                *d = Swizzle64(*src);
                d++;
                src++;
                k--;
            } while (k);
        }
        r = static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(OB_ADDR(dst), n << 3);
        ::operator delete(heap);
    }
    return r;
}
#endif


// FUNCTION: 0x00976a6e
bool cUnk00ad7cf0::GetFieldFloat64_2(uint32_t a)
{
    cRZString s(OB_PTR(const char, a));
    return Slot48_ad8d88(OB_ADDR(&s));
}

#ifdef OB_DRAFTS
// CLOSE: 0x00975bb5 score 6
void cUnk00ad7cf0::Slot49_ad8d88(uint32_t a)
{
    uint32_t* p = OB_PTR(uint32_t, a);
    Self_ad7cf0* self = reinterpret_cast<Self_ad7cf0*>(this);
    if (self->Slot37b_ad7cf0(p[0]) && self->Slot37b_ad7cf0(p[1])) {
        self->Slot37b_ad7cf0(p[2]);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00976139 score 4
bool cUnk00ad7cf0::Slot48_ad8d88(uint32_t a)
{
    Source_ad7cf0* src = OB_PTR(Source_ad7cf0, a);
    uint32_t n = src->Size7_ad7cf0();
    if (!reinterpret_cast<Self_ad7cf0*>(this)->Slot37b_ad7cf0(n)) {
        return false;
    }
    return static_cast<cUnk00ad8d88*>(this)->Slot05_ad9030(src->Data6_ad7cf0(), n);
}
#endif

// ---- the string reader (Slot24) ----
// The primary vtable where the string reader calls the byte readers whose base declarations differ (slot 5 returns a flag, 27 reads a block).
struct Reader_ad7cf0 {
    virtual void Pad0_ad7cf0();
    virtual void Pad1_ad7cf0();
    virtual void Pad2_ad7cf0();
    virtual void Pad3_ad7cf0();
    virtual void Pad4_ad7cf0();
    virtual bool Read5_ad7cf0(uint32_t out);
    virtual void Pad6_ad7cf0();
    virtual void Pad7_ad7cf0();
    virtual void Pad8_ad7cf0();
    virtual void Pad9_ad7cf0();
    virtual void Pad10_ad7cf0();
    virtual void Pad11_ad7cf0();
    virtual void Pad12_ad7cf0();
    virtual void Pad13_ad7cf0();
    virtual void Pad14_ad7cf0();
    virtual void Pad15_ad7cf0();
    virtual void Pad16_ad7cf0();
    virtual void Pad17_ad7cf0();
    virtual void Pad18_ad7cf0();
    virtual void Pad19_ad7cf0();
    virtual void Pad20_ad7cf0();
    virtual void Pad21_ad7cf0();
    virtual void Pad22_ad7cf0();
    virtual void Pad23_ad7cf0();
    virtual void Pad24_ad7cf0();
    virtual void Pad25_ad7cf0();
    virtual void Pad26_ad7cf0();
    virtual bool ReadBlock27_ad7cf0(uint32_t buffer, uint32_t count);
    virtual void Pad28_ad7cf0();
    virtual void Pad29_ad7cf0();
    virtual void Pad30_ad7cf0();
    virtual void Pad31_ad7cf0();
    virtual void Pad32_ad7cf0();
    virtual void Pad33_ad7cf0();
    virtual void Pad34_ad7cf0();
    virtual void Pad35_ad7cf0();
    virtual void Pad36_ad7cf0();
    virtual void Pad37_ad7cf0();
    virtual void Pad38_ad7cf0();
    virtual void Pad39_ad7cf0();
    virtual void Pad40_ad7cf0();
    virtual void Pad41_ad7cf0();
    virtual void Pad42_ad7cf0();
    virtual void Pad43_ad7cf0();
    virtual void Pad44_ad7cf0();
    virtual void Pad45_ad7cf0();
    virtual void Pad46_ad7cf0();
    virtual void Pad47_ad7cf0();
    virtual void Pad48_ad7cf0();
    virtual void Pad49_ad7cf0();
    virtual void Pad50_ad7cf0();
    virtual void Pad51_ad7cf0();
    virtual uint32_t Count52_ad7cf0();
    virtual void Pad53_ad7cf0();
    virtual void Pad54_ad7cf0();
    virtual void Pad55_ad7cf0();
    virtual bool Skip56_ad7cf0(int32_t count);
};

// STUB: 0x00911358
uint32_t Fn00911358(const void* data, uint32_t count, int32_t encoding, cIGZString& dest);

#ifdef OB_DRAFTS
// CLOSE: 0x00977054 score 169
bool cUnk00ad7cf0::Slot24_ad8d88(uint32_t a)
{
    uint32_t head = 0;
    Reader_ad7cf0* reader = reinterpret_cast<Reader_ad7cf0*>(this);
    uint8_t ok = 0;
    if (!Slot13_ad8d88(OB_ADDR(&head))) {
        cIGZString* out = OB_PTR(cIGZString, a);
        out->Resize(0);
        char c;
        while (reader->Read5_ad7cf0(OB_ADDR(&c))) {
            out->Append(&c, 1);
        }
        return true;
    }
    uint8_t tag = static_cast<uint8_t>(head >> 24);
    if (tag != 0 && tag != 0x10) {
        uint32_t n = reader->Count52_ad7cf0();
        reader->Skip56_ad7cf0(-4);
        cIGZString* out = OB_PTR(cIGZString, a);
        out->Resize(0);
        while (n != 0) {
            char c;
            reader->Read5_ad7cf0(OB_ADDR(&c));
            out->Append(&c, 1);
            n--;
        }
        return true;
    }
    head &= 0xffffff;
    if (head > 200000) {
        return false;
    }
    uint32_t bytes = head;
    if (tag == 0x10) {
        bytes = head * 2;
    }
    uint16_t stackBuffer[512];
    uint16_t* heap = 0;
    uint16_t* buffer = stackBuffer;
    if (bytes > 0x400) {
        heap = static_cast<uint16_t*>(::operator new(bytes));
        if (heap) {
            buffer = heap;
        }
    }
    if (bytes != 0) {
        ok = reader->ReadBlock27_ad7cf0(OB_ADDR(buffer), bytes);
    } else {
        ok = 1;
    }
    if (ok) {
        if (bytes >= 2 && reinterpret_cast<char*>(buffer)[1] == 0) {
            tag = 0x10;
        }
        cIGZString* out = OB_PTR(cIGZString, a);
        if (tag == 0x10) {
            RZUnicodeString wide;
            wide.assign(reinterpret_cast<RZUnicodeChar*>(buffer), reinterpret_cast<RZUnicodeChar*>(buffer) + head);
            uint32_t n = static_cast<uint32_t>(wide.size());
            if (!mbNoSwap) {
                for (uint32_t i = 0; i < n; i++) {
                    wide[i] = static_cast<RZUnicodeChar>(Swap16_ad7cf0(wide[i]));
                }
            }
            Fn00911358(wide.data(), n, 0x10, *out);
        } else {
            out->FromChar(reinterpret_cast<char*>(buffer), head);
        }
    }
    if (heap) {
        ::operator delete(heap);
    }
    return ok != 0;
}
#endif
