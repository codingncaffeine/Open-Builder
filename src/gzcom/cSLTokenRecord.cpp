#include <cstddef>

#include "classes/cSLTokenRecord.h"
#include "gzcom/cRZString.h"

// Wave 11c: cSLTokenRecord, its field-class constructors and helpers. Offsets in this file are from the object start.
#define FLD_ad9a88(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

// GLOBAL: 0x00b17a74
extern uint32_t g00b17a74;
// GLOBAL: 0x00b17a78
extern uint32_t g00b17a78;

// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t size);
// STUB: 0x0090cf63
void Fn0090cf63(void* p);
// STUB: 0x0040d4c0
void* Fn0040d4c0(void* node);
// STUB: 0x0041d490
void Fn0041d490(void* base, uint32_t size, uint32_t count, void* ctor);

// A token definition: id, kind, count.
struct Def_ad9a88 {
    uint32_t mnId;
    uint16_t mnKind;
    uint16_t mnCount;
};
struct Key12_ad9a88 {
    Def_ad9a88 mDef;
    uint32_t mnPad;
};

struct OB_NOVTABLE VIo2_ad9a88 {
    virtual void Pad00_ad9a88();
    virtual void Pad01_ad9a88();
    virtual void Pad02_ad9a88();
    virtual uint32_t* Slot03_ad9a88(void* a) = 0;
};
struct OB_NOVTABLE VIo_ad9a88 {
    virtual void Pad00_ad9a88();
    virtual bool Slot01_ad9a88(void* a) = 0;
    virtual void Slot02_ad9a88() = 0;
    virtual VIo2_ad9a88* Slot03_ad9a88() = 0;
};
struct OB_NOVTABLE VIoW_ad9a88 {
    virtual void Pad00_ad9a88();
    virtual void Slot01_ad9a88() = 0;
    virtual void Slot02_ad9a88() = 0;
    virtual void Pad03_ad9a88();
    virtual void Pad04_ad9a88();
    virtual void Pad05_ad9a88();
    virtual void Pad06_ad9a88();
    virtual void Pad07_ad9a88();
    virtual void Pad08_ad9a88();
    virtual void Pad09_ad9a88();
    virtual void Pad10_ad9a88();
    virtual void Pad11_ad9a88();
    virtual void Pad12_ad9a88();
    virtual void Pad13_ad9a88();
    virtual bool Slot14_ad9a88(void* a, void* b) = 0;
};
struct OB_NOVTABLE VFld_ad9a88 {
    virtual void Slot00_ad9a88(uint32_t a);
    virtual bool Slot01_ad9a88(void* a);
    virtual bool Slot02_ad9a88(void* a);
    virtual bool Slot03_ad9a88(uint32_t a, uint32_t b);
    virtual bool Slot04_ad9a88(uint32_t a, uint32_t b);
    virtual bool Slot05_ad9a88(uint32_t a, uint32_t b);
    virtual bool Slot06_ad9a88(uint32_t a, uint32_t b);
    virtual bool Slot07_ad9a88(uint32_t a, uint32_t b);
    virtual bool Slot08_ad9a88(uint32_t a, uint32_t b);
    virtual bool Slot09_ad9a88(uint32_t a, uint32_t b);
    virtual bool Slot10_ad9a88(uint32_t a, uint32_t b);
    virtual bool Slot11_ad9a88(uint32_t a, uint32_t b);
    virtual void Slot12_ad9a88(uint32_t a, uint32_t b);
    virtual void Slot13_ad9a88(uint32_t a, uint32_t b);
    virtual void Slot14_ad9a88(uint32_t a, uint32_t b);
    virtual void Slot15_ad9a88(uint32_t a, uint32_t b);
    virtual void Slot16_ad9a88(uint32_t a, uint32_t b);
    virtual void Slot17_ad9a88(uint32_t a, uint32_t b);
    virtual void Slot18_ad9a88(uint32_t a, uint32_t b);
    virtual void Slot19_ad9a88(uint32_t a, uint32_t b);
    virtual void Slot20_ad9a88(uint32_t a, uint32_t b);
};
struct OB_NOVTABLE VIoRel_ad9a88 {
    virtual void Pad00_ad9a88();
    virtual void Slot01_ad9a88() = 0;
    virtual void Slot02_ad9a88() = 0;
};

struct OB_NOVTABLE VStrm_ad9a88 {
    virtual void Pad00_ad9a88();
    virtual void Pad01_ad9a88();
    virtual void Pad02_ad9a88();
    virtual void Pad03_ad9a88();
    virtual void Pad04_ad9a88();
    virtual void Pad05_ad9a88();
    virtual void Pad06_ad9a88();
    virtual void Pad07_ad9a88();
    virtual void Pad08_ad9a88();
    virtual void Pad09_ad9a88();
    virtual void Pad10_ad9a88();
    virtual void Pad11_ad9a88();
    virtual void Pad12_ad9a88();
    virtual void Pad13_ad9a88();
    virtual void Pad14_ad9a88();
    virtual void Pad15_ad9a88();
    virtual void Pad16_ad9a88();
    virtual void Pad17_ad9a88();
    virtual void Pad18_ad9a88();
    virtual void Pad19_ad9a88();
    virtual void Pad20_ad9a88();
    virtual void Pad21_ad9a88();
    virtual void Pad22_ad9a88();
    virtual void Pad23_ad9a88();
    virtual void Pad24_ad9a88();
    virtual void Pad25_ad9a88();
    virtual void Pad26_ad9a88();
    virtual void Pad27_ad9a88();
    virtual void Pad28_ad9a88();
    virtual void Pad29_ad9a88();
    virtual void Pad30_ad9a88();
    virtual void Pad31_ad9a88();
    virtual void Pad32_ad9a88();
    virtual void Pad33_ad9a88();
    virtual void Pad34_ad9a88();
    virtual void Pad35_ad9a88();
    virtual void Pad36_ad9a88();
    virtual uint32_t Slot37_ad9a88(uint32_t a) = 0;
};

struct OB_NOVTABLE VCk_ad9a88 {
    virtual void Pad00_ad9a88();
    virtual void Pad01_ad9a88();
    virtual void Pad02_ad9a88();
    virtual void Pad03_ad9a88();
    virtual void Pad04_ad9a88();
    virtual void Pad05_ad9a88();
    virtual void Pad06_ad9a88();
    virtual void Pad07_ad9a88();
    virtual void Pad08_ad9a88();
    virtual void Pad09_ad9a88();
    virtual void Pad10_ad9a88();
    virtual void Pad11_ad9a88();
    virtual void Pad12_ad9a88();
    virtual void Pad13_ad9a88();
    virtual void Pad14_ad9a88();
    virtual void Pad15_ad9a88();
    virtual void Pad16_ad9a88();
    virtual void Pad17_ad9a88();
    virtual void Pad18_ad9a88();
    virtual void Pad19_ad9a88();
    virtual void Pad20_ad9a88();
    virtual void Pad21_ad9a88();
    virtual void Pad22_ad9a88();
    virtual void Pad23_ad9a88();
    virtual void Pad24_ad9a88();
    virtual void Pad25_ad9a88();
    virtual void Pad26_ad9a88();
    virtual void Pad27_ad9a88();
    virtual void Pad28_ad9a88();
    virtual void Pad29_ad9a88();
    virtual void Pad30_ad9a88();
    virtual void Pad31_ad9a88();
    virtual void Pad32_ad9a88();
    virtual void Pad33_ad9a88();
    virtual void Pad34_ad9a88();
    virtual void Pad35_ad9a88();
    virtual void Pad36_ad9a88();
    virtual void Pad37_ad9a88();
    virtual void Pad38_ad9a88();
    virtual void Pad39_ad9a88();
    virtual void Pad40_ad9a88();
    virtual void Pad41_ad9a88();
    virtual void Pad42_ad9a88();
    virtual void Pad43_ad9a88();
    virtual void Pad44_ad9a88();
    virtual void Pad45_ad9a88();
    virtual void Pad46_ad9a88();
    virtual void Pad47_ad9a88();
    virtual void Pad48_ad9a88();
    virtual void Pad49_ad9a88();
    virtual void Pad50_ad9a88();
    virtual void Pad51_ad9a88();
    virtual uint32_t Slot52_ad9a88() = 0;
};

// A field of a token record: a vtable, then the definition it was made for (a second base, so a pointer to the
// field converts to a pointer to the definition with a null check).
struct OB_NOVTABLE FieldVt_ad9a88 : public VFld_ad9a88 {
};
struct FieldBase_ad9a88 : public FieldVt_ad9a88, public Def_ad9a88 {
    cRZString mName;
    // STUB: 0x0097f991
    explicit FieldBase_ad9a88(const Def_ad9a88* def);
};

struct Node_ad9a88 {
    uint32_t mnColor;
    Node_ad9a88* mpParent;
    Node_ad9a88* mpLeft;
    Node_ad9a88* mpRight;
    uint32_t mnKey;
    FieldBase_ad9a88* mpField;
};

// The token map at +0x14: header node, count.
struct Map_ad9a88 {
    Node_ad9a88* mpHeader;
    uint32_t mnSize;
    // STUB: 0x0098129c
    Node_ad9a88* Fn0098129c(const void* key);
    // STUB: 0x00927cf8
    void Fn00927cf8(Node_ad9a88* it);
    // STUB: 0x0094950a
    void Fn0094950a(void* ret, void* pair);
    // STUB: 0x0097f3f6
    void Fn0097f3f6(Node_ad9a88* first, Node_ad9a88* last);
    // STUB: 0x0097f190
    void Fn0097f190(Node_ad9a88* first, Node_ad9a88* last);
};
#define MAP_ad9a88 (reinterpret_cast<Map_ad9a88*>(reinterpret_cast<char*>(this) + 0x14))

// The stream wrappers a record reads and writes through (16 bytes: vtable, stream, mode, cookie).
struct IOBase_ad9a88 {
    virtual void Pad_ad9a88();
    void* mpStream;
    uint32_t mnMode;
    uint32_t mnCookie;
    // STUB: 0x0097eb78
    explicit IOBase_ad9a88(void* stream);
};
struct IOText_ad9a88 : public IOBase_ad9a88 {
    // STUB: 0x0097ee84
    explicit IOText_ad9a88(void* stream);
};


struct FldF00_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x0097f9df
    explicit FldF00_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF01_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x0097fab0
    explicit FldF01_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF02_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x0097fb89
    explicit FldF02_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF03_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x0097fc0a
    explicit FldF03_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF04_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x0097fdc8
    explicit FldF04_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF05_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x0097fce0
    explicit FldF05_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF06_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x0097ffbf
    explicit FldF06_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF07_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x0097fe9e
    explicit FldF07_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF08_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x009800dd
    explicit FldF08_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF09_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x0098016c
    explicit FldF09_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF10_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x009801ff
    explicit FldF10_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct FldF11_ad9a88 : public FieldBase_ad9a88 {
    void* mpData;
    // STUB: 0x00980293
    explicit FldF11_ad9a88(const Def_ad9a88* def);
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// FUNCTION: 0x0097ef5b
uint32_t Fn0097ef5b(const Def_ad9a88* a, const Def_ad9a88* b)
{
    if (a->mnId == b->mnId && a->mnKind == b->mnKind && a->mnCount == b->mnCount) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x0097ef84
bool cSLTokenRecord::QueryInterface(uint32_t iid, uint32_t pp)
{
    if (iid == 1 || iid == 0xa2ace662) {
        *OB_PTR(void*, pp) = this;
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x0097efa9
uint32_t cSLTokenRecord::Release()
{
    if (mnRefCount > 1) {
        mnRefCount = mnRefCount - 1;
        return mnRefCount;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x0097efc3
bool cSLTokenRecord::GetKey(uint32_t out)
{
    uint32_t tmp[3];
    if (mpIO) {
        VIo2_ad9a88* o = static_cast<VIo_ad9a88*>(mpIO)->Slot03_ad9a88();
        uint32_t* r = o->Slot03_ad9a88(tmp);
        uint32_t* d = OB_PTR(uint32_t, out);
        d[0] = r[0];
        d[1] = r[1];
        d[2] = r[2];
        return true;
    }
    return false;
}

// FUNCTION: 0x0097efff
uint32_t cSLTokenRecord::GetCookie()
{
    if (mbInit) {
        return mnCookie;
    }
    return 0;
}

// FUNCTION: 0x0097f00c
bool cSLTokenRecord::InitWriteText(uint32_t a)
{
    if (mbInit) {
        return false;
    }
    mnCookie = g00b17a74;
    mbInit = true;
    mbRead = true;
    mbText = true;
    mpIO = OB_PTR(void, a);
    OB_PTR(VIoRel_ad9a88, a)->Slot01_ad9a88();
    return true;
}

// FUNCTION: 0x0097f03e
bool cSLTokenRecord::InitWriteBinary(uint32_t a)
{
    if (mbInit) {
        return false;
    }
    mnCookie = g00b17a78;
    mbInit = true;
    mbRead = true;
    mbText = false;
    mpIO = OB_PTR(void, a);
    OB_PTR(VIoRel_ad9a88, a)->Slot01_ad9a88();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0097f1d4 score 2
bool cSLTokenRecord::GetField(const void* def, void* out)
{
    Map_ad9a88* m = MAP_ad9a88;
    Node_ad9a88* n = m->Fn0098129c(def);
    if (n != m->mpHeader) {
        FieldBase_ad9a88* f = n->mpField;
        FieldBase_ad9a88** o = static_cast<FieldBase_ad9a88**>(out);
        *o = f;
        const Def_ad9a88* d;
        if (f) {
            d = f;
        } else {
            d = 0;
        }
        if (Fn0097ef5b(d, static_cast<const Def_ad9a88*>(def))) {
            return true;
        }
        *o = 0;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097f218 score 6
bool cSLTokenRecord::IsTokenAvailable(uint32_t a)
{
    uint32_t key = *OB_PTR(uint32_t, a);
    Map_ad9a88* m = MAP_ad9a88;
    Node_ad9a88* n = m->Fn0098129c(&key);
    if (n != m->mpHeader) {
        const Def_ad9a88* d = n->mpField;
        return Fn0097ef5b(d, OB_PTR(Def_ad9a88, a));
    }
    return false;
}
#endif

// FUNCTION: 0x0097f258
bool cSLTokenRecord::GetFieldSint8(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f)) {
        return f->Slot11_ad9a88(b, c);
    }
    return false;
}

// FUNCTION: 0x0097f286
bool cSLTokenRecord::GetFieldSint16(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f)) {
        return f->Slot10_ad9a88(b, c);
    }
    return false;
}

// FUNCTION: 0x0097f2b4
bool cSLTokenRecord::GetFieldUint32(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f)) {
        return f->Slot09_ad9a88(b, c);
    }
    return false;
}

// FUNCTION: 0x0097f2e2
bool cSLTokenRecord::GetFieldSint32(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f)) {
        return f->Slot08_ad9a88(b, c);
    }
    return false;
}

// FUNCTION: 0x0097f310
bool cSLTokenRecord::GetFieldSint64(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f)) {
        return f->Slot07_ad9a88(b, c);
    }
    return false;
}

// FUNCTION: 0x0097f33e
bool cSLTokenRecord::GetFieldFloat32(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f)) {
        return f->Slot06_ad9a88(b, c);
    }
    return false;
}

// FUNCTION: 0x0097f36c
bool cSLTokenRecord::GetFieldFloat64(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f)) {
        return f->Slot05_ad9a88(b, c);
    }
    return false;
}

// FUNCTION: 0x0097f39a
bool cSLTokenRecord::GetFieldString(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f)) {
        return f->Slot04_ad9a88(b, c);
    }
    return false;
}

// FUNCTION: 0x0097f3c8
bool cSLTokenRecord::GetFieldResKey(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f)) {
        return f->Slot03_ad9a88(b, c);
    }
    return false;
}

// FUNCTION: 0x00980801
void cSLTokenRecord::SetFieldSint8(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f) || CreateField(OB_PTR(void, a), &f)) {
        f->Slot20_ad9a88(b, c);
    }
}

// FUNCTION: 0x00980841
void cSLTokenRecord::SetFieldSint16(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f) || CreateField(OB_PTR(void, a), &f)) {
        f->Slot19_ad9a88(b, c);
    }
}

// FUNCTION: 0x00980881
void cSLTokenRecord::SetFieldUint32(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f) || CreateField(OB_PTR(void, a), &f)) {
        f->Slot18_ad9a88(b, c);
    }
}

// FUNCTION: 0x009808c1
void cSLTokenRecord::SetFieldSint32(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f) || CreateField(OB_PTR(void, a), &f)) {
        f->Slot17_ad9a88(b, c);
    }
}

// FUNCTION: 0x00980901
void cSLTokenRecord::SetFieldSint64(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f) || CreateField(OB_PTR(void, a), &f)) {
        f->Slot16_ad9a88(b, c);
    }
}

// FUNCTION: 0x00980941
void cSLTokenRecord::SetFieldFloat32(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f) || CreateField(OB_PTR(void, a), &f)) {
        f->Slot15_ad9a88(b, c);
    }
}

// FUNCTION: 0x00980981
void cSLTokenRecord::SetFieldFloat64(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f) || CreateField(OB_PTR(void, a), &f)) {
        f->Slot14_ad9a88(b, c);
    }
}

// FUNCTION: 0x009809c1
void cSLTokenRecord::SetFieldString(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f) || CreateField(OB_PTR(void, a), &f)) {
        f->Slot13_ad9a88(b, c);
    }
}

// FUNCTION: 0x00980a01
void cSLTokenRecord::SetFieldResKey(uint32_t a, uint32_t b, uint32_t c)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f) || CreateField(OB_PTR(void, a), &f)) {
        f->Slot12_ad9a88(b, c);
    }
}

// FUNCTION: 0x0097f093
uint32_t __stdcall Fn0097f093(VStrm_ad9a88* o, uint32_t x)
{
    return o->Slot37_ad9a88(x);
}

// GLOBAL: 0x00ad9964
extern Def_ad9a88 gEndDef_ad9a88;

#ifdef OB_DRAFTS
// CLOSE: 0x009805f8 score 159
bool cSLTokenRecord::CreateField(const void* defv, void* outv)
{
    const Def_ad9a88* def = static_cast<const Def_ad9a88*>(defv);
    if (def->mnCount) {
        Map_ad9a88* m = MAP_ad9a88;
        Node_ad9a88* n = m->Fn0098129c(def);
        FieldBase_ad9a88** out = static_cast<FieldBase_ad9a88**>(outv);
        if (n != m->mpHeader) {
            FieldBase_ad9a88* f = n->mpField;
            *out = f;
            const Def_ad9a88* d;
            if (f) {
                d = f;
            } else {
                d = 0;
            }
            if (!Fn0097ef5b(d, def)) {
                m->Fn00927cf8(n);
                n = m->mpHeader;
            }
        }
        if (n == m->mpHeader) {
            FieldBase_ad9a88* nf;
            switch (def->mnKind - 1) {
            case 0:
                nf = new FldF00_ad9a88(def);
                break;
            case 1:
                nf = new FldF01_ad9a88(def);
                break;
            case 2:
                nf = new FldF02_ad9a88(def);
                break;
            case 3:
                nf = new FldF03_ad9a88(def);
                break;
            case 4:
                nf = new FldF04_ad9a88(def);
                break;
            case 5:
                nf = new FldF05_ad9a88(def);
                break;
            case 6:
                nf = new FldF06_ad9a88(def);
                break;
            case 7:
                nf = new FldF07_ad9a88(def);
                break;
            case 8:
                nf = new FldF08_ad9a88(def);
                break;
            case 9:
                nf = new FldF09_ad9a88(def);
                break;
            case 10:
                nf = new FldF10_ad9a88(def);
                break;
            case 11:
                nf = new FldF11_ad9a88(def);
                break;
            default:
                return false;
            }
            *out = nf;
            uint32_t pair[2];
            uint32_t ret[2];
            pair[0] = def->mnId;
            pair[1] = reinterpret_cast<uint32_t>(nf);
            m->Fn0094950a(ret, pair);
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00980ac9 score 26
bool cSLTokenRecord::ReadTokens(void* io)
{
    FieldBase_ad9a88* f = 0;
    Def_ad9a88 k;
    while (true) {
        if (!static_cast<VIo_ad9a88*>(io)->Slot01_ad9a88(&k)) {
            return false;
        }
        if (k.mnId == 1) {
            return true;
        }
        if (!CreateField(&k, &f)) {
            return false;
        }
        f->Slot01_ad9a88(io);
    }
}
#endif

// FUNCTION: 0x00980f3a
bool cSLTokenRecord::SetTokenString(uint32_t a, uint32_t b)
{
    FieldBase_ad9a88* f = 0;
    if (GetField(OB_PTR(void, a), &f)) {
        cRZString s(*OB_PTR(cIGZString, b));
        f->mName = s;
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00980e3c score 118
bool cSLTokenRecord::WriteTokensToSerialRecord(void* io)
{
    Map_ad9a88* m = MAP_ad9a88;
    Node_ad9a88* n = m->mpHeader->mpLeft;
    bool ok = true;
    while (n != m->mpHeader) {
        if (!ok) {
            return ok;
        }
        FieldBase_ad9a88* f = n->mpField;
        cRZString key;
        key = f->mName;
        const Def_ad9a88* d;
        if (f) {
            d = f;
        } else {
            d = 0;
        }
        ok = static_cast<VIoW_ad9a88*>(io)->Slot14_ad9a88(&key, const_cast<Def_ad9a88*>(d));
        if (ok) {
            ok = f->Slot02_ad9a88(io);
        }
        n = static_cast<Node_ad9a88*>(Fn0040d4c0(n));
    }
    if (ok) {
        FldF02_ad9a88 end(&gEndDef_ad9a88);
        *static_cast<uint32_t*>(end.mpData) = 0;
        cRZString key("TK_TKR_End");
        ok = static_cast<VIoW_ad9a88*>(io)->Slot14_ad9a88(&key, static_cast<Def_ad9a88*>(&end));
        if (ok) {
            ok = end.Slot02_ad9a88(io);
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00980f87 score 34
void cSLTokenRecord::Shutdown()
{
    if (mpIO) {
        if (mbRead) {
            bool ok;
            if (mbText) {
                ok = Fn0097f093(static_cast<VStrm_ad9a88*>(mpIO), g00b17a74) != 0;
                IOText_ad9a88 io(mpIO);
                if (ok) {
                    WriteTokensToSerialRecord(&io);
                }
            } else {
                ok = Fn0097f093(static_cast<VStrm_ad9a88*>(mpIO), g00b17a78) != 0;
                IOBase_ad9a88 io(mpIO);
                if (ok) {
                    WriteTokensToSerialRecord(&io);
                }
            }
        }
        static_cast<VIoRel_ad9a88*>(mpIO)->Slot02_ad9a88();
        mpIO = 0;
    }
    Map_ad9a88* m = MAP_ad9a88;
    Node_ad9a88* n = m->mpHeader->mpLeft;
    while (n != m->mpHeader) {
        FieldBase_ad9a88* f = n->mpField;
        if (f) {
            f->Slot00_ad9a88(1);
        }
        n = static_cast<Node_ad9a88*>(Fn0040d4c0(n));
    }
    m->Fn0097f3f6(m->mpHeader->mpLeft, m->mpHeader);
    mbInit = false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00981052 score 2
bool cSLTokenRecord::InitRead_2(uint32_t a, uint32_t b)
{
    if (mbInit) {
        return false;
    }
    mbRead = false;
    mpIO = OB_PTR(void, a);
    OB_PTR(VIoRel_ad9a88, a)->Slot01_ad9a88();
    mnCookie = b;
    if (b == g00b17a74) {
        mbText = true;
        IOText_ad9a88 io(OB_PTR(void, a));
        mbInit = ReadTokens(&io);
    } else if (b == g00b17a78) {
        mbText = false;
        IOBase_ad9a88 io(OB_PTR(void, a));
        mbInit = ReadTokens(&io);
    }

    if (!mbInit) {
        Shutdown();
    }
    return mbInit;
}
#endif

// FUNCTION: 0x009810cd
bool cSLTokenRecord::InitRead(uint32_t a)
{
    if (mbInit) {
        return false;
    }
    mpIO = OB_PTR(void, a);
    OB_PTR(VIoRel_ad9a88, a)->Slot01_ad9a88();
    mbRead = false;
    uint32_t cookie = Fn0097f074(a);
    mnCookie = cookie;
    if (cookie) {
        if (cookie == g00b17a74) {
            mbText = true;
            IOText_ad9a88 io(OB_PTR(void, a));
            mbInit = ReadTokens(&io);
        } else if (cookie == g00b17a78) {
            mbText = false;
            IOBase_ad9a88 io(OB_PTR(void, a));
            mbInit = ReadTokens(&io);
        }
    }

    if (!mbInit) {
        Shutdown();
    }
    return mbInit;
}

// ---- Drafts of constructors and map helpers (kept below the callers so they stay out of line there).

#ifdef OB_DRAFTS
// CLOSE: 0x0097eb78 score 0 (vtable pointer is the stand-in class's)
IOBase_ad9a88::IOBase_ad9a88(void* stream)
{
    mpStream = stream;
    mnCookie = static_cast<VCk_ad9a88*>(stream)->Slot52_ad9a88();
    mnMode = 4;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097ee84 score 0 (vtable pointer is the stand-in class's)
IOText_ad9a88::IOText_ad9a88(void* stream) : IOBase_ad9a88(stream)
{
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097f3f6 score 11
void Map_ad9a88::Fn0097f3f6(Node_ad9a88* first, Node_ad9a88* last)
{
    Fn0097f190(first, last);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097f9df score 0 (vtable pointer is the stand-in class's)
FldF00_ad9a88::FldF00_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    mpData = Fn005e55e0(static_cast<uint32_t>(def->mnCount) * 1);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097fab0 score 0 (vtable pointer is the stand-in class's)
FldF01_ad9a88::FldF01_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    mpData = Fn005e55e0(static_cast<uint32_t>(def->mnCount) * 2);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097fb89 score 0 (vtable pointer is the stand-in class's)
FldF02_ad9a88::FldF02_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    mpData = Fn005e55e0(static_cast<uint32_t>(def->mnCount) * 4);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097fc0a score 0 (vtable pointer is the stand-in class's)
FldF03_ad9a88::FldF03_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    mpData = Fn005e55e0(static_cast<uint32_t>(def->mnCount) * 4);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097fdc8 score 0 (vtable pointer is the stand-in class's)
FldF04_ad9a88::FldF04_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    mpData = Fn005e55e0(static_cast<uint32_t>(def->mnCount) * 4);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097fce0 score 0 (vtable pointer is the stand-in class's)
FldF05_ad9a88::FldF05_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    mpData = Fn005e55e0(static_cast<uint32_t>(def->mnCount) * 8);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009800dd score 0 (vtable pointer is the stand-in class's)
FldF08_ad9a88::FldF08_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    mpData = Fn005e55e0(static_cast<uint32_t>(def->mnCount) * 1);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098016c score 0 (vtable pointer is the stand-in class's)
FldF09_ad9a88::FldF09_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    mpData = Fn005e55e0(static_cast<uint32_t>(def->mnCount) * 2);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009801ff score 0 (vtable pointer is the stand-in class's)
FldF10_ad9a88::FldF10_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    mpData = Fn005e55e0(static_cast<uint32_t>(def->mnCount) * 8);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00980293 score 0 (vtable pointer is the stand-in class's)
FldF11_ad9a88::FldF11_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    mpData = Fn005e55e0(static_cast<uint32_t>(def->mnCount) * 8);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097ffbf score 8
FldF06_ad9a88::FldF06_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    uint32_t n = def->mnCount;
    uint32_t* p = static_cast<uint32_t*>(Fn005e55e0(n * 20 + 4));
    uint8_t* base = 0;
    if (p) {
        base = reinterpret_cast<uint8_t*>(p + 1);
        *p = n;
        Fn0041d490(base, 0x14, n, 0);
    }
    mpData = base;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097fe9e score 5
FldF07_ad9a88::FldF07_ad9a88(const Def_ad9a88* def) : FieldBase_ad9a88(def)
{
    uint32_t n = def->mnCount;
    void* p = Fn005e55e0(n * 12);
    if (p) {
        Fn0041d490(p, 0xc, n, 0);
    }
    mpData = p;
}
#endif
