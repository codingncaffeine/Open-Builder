#include <cstddef>

#include <cstring>
#include "classes/cUnk00adb17c.h"

// A field of this object by its offset from the class start. In a method of a secondary base's vtable the
// original's offsets are from that base (adae18 at +0x1c, adaf30 at +0x20): add it.
#define FLD_adb17c(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

struct Blk3_adb17c {
    uint32_t w[3];
};
struct Blk4_adb17c {
    uint32_t w[4];
};
struct Blk7_adb17c {
    uint32_t w[7];
};
struct Blk8_adb17c {
    uint32_t w[8];
};

// GLOBAL: 0x00b17adc
extern uint8_t g00b17adc;
// GLOBAL: 0x00babfb4
extern uint8_t g00babfb4;
// GLOBAL: 0x00babfbc
extern uint32_t g00babfbc;
// GLOBAL: 0x00b17ae4
extern Blk7_adb17c g00b17ae4;
// GLOBAL: 0x00babf94
extern Blk8_adb17c g00babf94;


// The adae18 subobject's vtable as the methods below call through it.
struct OB_NOVTABLE S18_adb17c {
    virtual void Pad00_adb17c(); virtual void Pad01_adb17c(); virtual void Pad02_adb17c(); virtual void Pad03_adb17c(); virtual void Pad04_adb17c(); virtual void Pad05_adb17c(); 
    virtual void Pad06_adb17c(); virtual void Pad07_adb17c(); virtual void Pad08_adb17c(); virtual void Pad09_adb17c(); virtual void Pad10_adb17c(); virtual void Pad11_adb17c(); 
    virtual void Pad12_adb17c(); virtual void Pad13_adb17c(); virtual void Pad14_adb17c(); virtual void Pad15_adb17c(); virtual void Pad16_adb17c(); 
    virtual bool Slot17_adb17c() = 0;
    virtual void Pad18_adb17c(); virtual void Pad19_adb17c(); virtual void Pad20_adb17c(); virtual void Pad21_adb17c(); virtual void Pad22_adb17c(); virtual void Pad23_adb17c(); 
    
    virtual uint32_t Slot24_adb17c(uint32_t a, uint32_t b) = 0;
    virtual void Pad25_adb17c(); virtual void Pad26_adb17c(); virtual void Pad27_adb17c(); virtual void Pad28_adb17c(); virtual void Pad29_adb17c(); 
    virtual void Pad30_adb17c(); virtual void Pad31_adb17c(); virtual void Pad32_adb17c(); virtual void Pad33_adb17c(); virtual void Pad34_adb17c(); virtual void Pad35_adb17c(); 
    virtual void Pad36_adb17c(); virtual void Pad37_adb17c(); virtual void Pad38_adb17c(); virtual void Pad39_adb17c(); virtual void Pad40_adb17c(); virtual void Pad41_adb17c(); 
    virtual void Pad42_adb17c(); virtual void Pad43_adb17c(); virtual void Pad44_adb17c(); virtual void Pad45_adb17c(); virtual void Pad46_adb17c(); virtual void Pad47_adb17c(); 
    virtual void Pad48_adb17c(); virtual void Pad49_adb17c(); 
    virtual void Slot50_adb17c() = 0;
};

// The adaf30 subobject's slot 4.
struct OB_NOVTABLE S20_adb17c {
    virtual void Pad00_adb17c(); virtual void Pad01_adb17c(); virtual void Pad02_adb17c(); virtual void Pad03_adb17c(); 
    virtual uint32_t Slot04_adb17c() = 0;
};

// The embedded object at +0x88: slot 13.
struct OB_NOVTABLE E88_adb17c {
    virtual void Pad00_adb17c(); virtual void Pad01_adb17c(); virtual void Pad02_adb17c(); virtual void Pad03_adb17c(); virtual void Pad04_adb17c(); virtual void Pad05_adb17c(); 
    virtual void Pad06_adb17c(); virtual void Pad07_adb17c(); virtual void Pad08_adb17c(); virtual void Pad09_adb17c(); virtual void Pad10_adb17c(); virtual void Pad11_adb17c(); 
    virtual void Pad12_adb17c(); 
    virtual void Slot13_adb17c() = 0;
};

// The objects at +0x108 / +0x100: slot 0 takes two values; slot 15 one; slot 30 three.
struct OB_NOVTABLE O108_adb17c {
    virtual bool Slot00_adb17c(uint32_t a, uint32_t b) = 0;
};
struct OB_NOVTABLE O100_adb17c {
    virtual void Pad00_adb17c(); virtual void Pad01_adb17c(); virtual void Pad02_adb17c(); virtual void Pad03_adb17c(); virtual void Pad04_adb17c(); virtual void Pad05_adb17c(); 
    virtual void Pad06_adb17c(); virtual void Pad07_adb17c(); virtual void Pad08_adb17c(); virtual void Pad09_adb17c(); virtual void Pad10_adb17c(); virtual void Pad11_adb17c(); 
    virtual void Pad12_adb17c(); virtual void Pad13_adb17c(); virtual void Pad14_adb17c(); 
    virtual void Slot15_adb17c(uint32_t a) = 0;
    virtual void Pad16_adb17c(); virtual void Pad17_adb17c(); 
    virtual void Pad18_adb17c(); virtual void Pad19_adb17c(); virtual void Pad20_adb17c(); virtual void Pad21_adb17c(); virtual void Pad22_adb17c(); virtual void Pad23_adb17c(); 
    virtual void Pad24_adb17c(); virtual void Pad25_adb17c(); virtual void Pad26_adb17c(); virtual void Pad27_adb17c(); virtual void Pad28_adb17c(); virtual void Pad29_adb17c(); 
    
    virtual uint32_t Slot30_adb17c(uint32_t a, uint32_t b, uint32_t c) = 0;
    virtual void Slot31_adb17c(uint32_t a, uint32_t b, uint32_t c, uint32_t d) = 0;
};

// An object with a width and a height (slots 9 and 10).
struct OB_NOVTABLE Dim_adb17c {
    virtual void Pad00_adb17c(); virtual void Pad01_adb17c(); virtual void Pad02_adb17c(); virtual void Pad03_adb17c(); virtual void Pad04_adb17c(); virtual void Pad05_adb17c(); 
    virtual void Pad06_adb17c(); virtual void Pad07_adb17c(); virtual void Pad08_adb17c(); 
    virtual uint16_t Slot09_adb17c() = 0;
    virtual uint16_t Slot10_adb17c() = 0;
};

// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t size);

// The 0x4c-byte object made by slots 3 and 4 (slot 0 sets it up, slot 1 adds a reference, slot 40 destroys it).
struct X_adb17c {
    virtual bool Slot00_adb17c(uint32_t a, uint32_t b);
    virtual void AddRef_adb17c();
    virtual void Pad02_adb17c(); virtual void Pad03_adb17c(); virtual void Pad04_adb17c(); virtual void Pad05_adb17c(); 
    virtual void Pad06_adb17c(); virtual void Pad07_adb17c(); virtual void Pad08_adb17c(); virtual void Pad09_adb17c(); virtual void Pad10_adb17c(); virtual void Pad11_adb17c(); 
    virtual void Pad12_adb17c(); virtual void Pad13_adb17c(); virtual void Pad14_adb17c(); virtual void Pad15_adb17c(); virtual void Pad16_adb17c(); virtual void Pad17_adb17c(); 
    virtual void Pad18_adb17c(); virtual void Pad19_adb17c(); virtual void Pad20_adb17c(); virtual void Pad21_adb17c(); virtual void Pad22_adb17c(); virtual void Pad23_adb17c(); 
    virtual void Pad24_adb17c(); virtual void Pad25_adb17c(); virtual void Pad26_adb17c(); virtual void Pad27_adb17c(); virtual void Pad28_adb17c(); virtual void Pad29_adb17c(); 
    virtual void Pad30_adb17c(); virtual void Pad31_adb17c(); virtual void Pad32_adb17c(); virtual void Pad33_adb17c(); virtual void Pad34_adb17c(); virtual void Pad35_adb17c(); 
    virtual void Pad36_adb17c(); virtual void Pad37_adb17c(); virtual void Pad38_adb17c(); virtual void Pad39_adb17c(); 
    virtual void Destroy_adb17c(uint32_t flag);
    uint8_t mData[0x48];
    // STUB: 0x008272e0
    X_adb17c();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// STUB: 0x00989ef0
void Fn00989ef0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
// STUB: 0x0098a070
void Fn0098a070(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
// STUB: 0x0098a1f0
void Fn0098a1f0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
// STUB: 0x0098a3d0
void Fn0098a3d0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
// STUB: 0x0098a5e0
void Fn0098a5e0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
// STUB: 0x0098a700
void Fn0098a700(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
// STUB: 0x0098a8a0
void Fn0098a8a0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
// STUB: 0x0098aa90
void Fn0098aa90(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
// STUB: 0x0098abd0
void Fn0098abd0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);

// Methods of the secondary bases written on a view of the object (this = the original's ecx, offsets as in the
// original's code), where they call on into other slots.
struct Fix_adb17c {
    void Slot51_adae18();
    void Slot27_adae18();
    void Slot09_adaf30();
    void Slot22_adae18(uint32_t a);
    void Slot23_adae18(uint32_t a);
};

// The object at +0x9c: slot 63 counts its entries, slot 65 fetches one.
struct Entry_adb17c {
    uint32_t mFirst;
    uint32_t mKey[3];
    uint32_t mPad[4];
    uint8_t mTag;
    uint8_t mPad21[3];
    uint32_t mPad24;
};
struct OB_NOVTABLE O9c_adb17c {
    virtual void Pad00_adb17c(); virtual void Pad01_adb17c(); virtual void Pad02_adb17c(); virtual void Pad03_adb17c(); virtual void Pad04_adb17c(); virtual void Pad05_adb17c(); 
    virtual void Pad06_adb17c(); virtual void Pad07_adb17c(); virtual void Pad08_adb17c(); virtual void Pad09_adb17c(); virtual void Pad10_adb17c(); virtual void Pad11_adb17c(); 
    virtual void Pad12_adb17c(); virtual void Pad13_adb17c(); virtual void Pad14_adb17c(); virtual void Pad15_adb17c(); virtual void Pad16_adb17c(); virtual void Pad17_adb17c(); 
    virtual void Pad18_adb17c(); virtual void Pad19_adb17c(); virtual void Pad20_adb17c(); virtual void Pad21_adb17c(); virtual void Pad22_adb17c(); virtual void Pad23_adb17c(); 
    virtual void Pad24_adb17c(); virtual void Pad25_adb17c(); virtual void Pad26_adb17c(); virtual void Pad27_adb17c(); virtual void Pad28_adb17c(); virtual void Pad29_adb17c(); 
    virtual void Pad30_adb17c(); virtual void Pad31_adb17c(); virtual void Pad32_adb17c(); virtual void Pad33_adb17c(); virtual void Pad34_adb17c(); virtual void Pad35_adb17c(); 
    virtual void Pad36_adb17c(); virtual void Pad37_adb17c(); virtual void Pad38_adb17c(); virtual void Pad39_adb17c(); virtual void Pad40_adb17c(); virtual void Pad41_adb17c(); 
    virtual void Pad42_adb17c(); virtual void Pad43_adb17c(); virtual void Pad44_adb17c(); virtual void Pad45_adb17c(); virtual void Pad46_adb17c(); virtual void Pad47_adb17c(); 
    virtual void Pad48_adb17c(); virtual void Pad49_adb17c(); virtual void Pad50_adb17c(); virtual void Pad51_adb17c(); virtual void Pad52_adb17c(); virtual void Pad53_adb17c(); 
    virtual void Pad54_adb17c(); virtual void Pad55_adb17c(); virtual void Pad56_adb17c(); virtual void Pad57_adb17c(); virtual void Pad58_adb17c(); virtual void Pad59_adb17c(); 
    virtual void Pad60_adb17c(); virtual void Pad61_adb17c(); virtual void Pad62_adb17c(); 
    virtual uint32_t Count63_adb17c() = 0;
    virtual void Pad64_adb17c();
    virtual void Get65_adb17c(uint32_t index, Entry_adb17c* out) = 0;
};

// FUNCTION: 0x0098ad10
void cUnk00adb17c::Slot16_adaf30()
{
    FLD_adb17c(bool, 0x42) = true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0098dfa0 score 4
void cUnk00adb17c::Slot19_adae18()
{
    FLD_adb17c(int32_t, 0x64) = FLD_adb17c(int32_t, 0x64) - 1;
}
#endif

// FUNCTION: 0x00989e50
void cUnk00adb17c::Slot54_adae18(uint32_t a)
{
    g00b17adc = static_cast<uint8_t>(a);
}

// FUNCTION: 0x00989e60
void cUnk00adb17c::Slot55_adae18(uint32_t a)
{
    g00babfb4 = static_cast<uint8_t>(a);
}

// FUNCTION: 0x00989e70
void cUnk00adb17c::Slot56_adae18(uint32_t a)
{
    g00babfbc = a;
}

// FUNCTION: 0x0098ace0
void cUnk00adb17c::Slot14_adaf30()
{
    if (!FLD_adb17c(bool, 0x30)) {
        FLD_adb17c(bool, 0x41) = false;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0098dfb0 score 5
uint32_t cUnk00adb17c::Slot20_adae18()
{
    return FLD_adb17c(uint32_t, 0x64) != 0;
}
#endif

// FUNCTION: 0x0098ad20
bool cUnk00adb17c::Slot19_adaf30()
{
    return !FLD_adb17c(bool, 0x10c);
}

// FUNCTION: 0x00989e30
void cUnk00adb17c::Slot53_adae18(uint32_t a)
{
    g00b17ae4 = *OB_PTR(Blk7_adb17c, a);
}

// FUNCTION: 0x00989e80
void cUnk00adb17c::Slot57_adae18(uint32_t a)
{
    g00babf94 = *OB_PTR(Blk8_adb17c, a);
}

// FUNCTION: 0x0098e020
void cUnk00adb17c::Slot18_adaf30(uint32_t a, uint32_t b)
{
    FLD_adb17c(uint8_t, 0x10c) = static_cast<uint8_t>(a);
    FLD_adb17c(uint32_t, 0x110) = b;
}

// FUNCTION: 0x0098acf0
void cUnk00adb17c::Slot15_adaf30(uint32_t a)
{
    *OB_PTR(Blk8_adb17c, a) = FLD_adb17c(Blk8_adb17c, 0xdc);
}

// FUNCTION: 0x0098dfc0
void cUnk00adb17c::Slot30_adae18(uint32_t a)
{
    if (static_cast<uint8_t>(a)) {
        FLD_adb17c(int32_t, 0x44) = FLD_adb17c(int32_t, 0x44) - 1;
        return;
    }
    FLD_adb17c(int32_t, 0x44) = FLD_adb17c(int32_t, 0x44) + 1;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0098e1d0 score 3
void cUnk00adb17c::Slot11_adae18(uint32_t a)
{
    *OB_PTR(Blk7_adb17c, a) = g00b17ae4;
}
#endif

// FUNCTION: 0x0098e850
bool cUnk00adb17c::Slot26_adae18(uint32_t a, uint32_t b)
{
    *OB_PTR(uint32_t, a) = 0;
    *OB_PTR(uint32_t, b) = 0;
    return true;
}

// FUNCTION: 0x0098aca0
void cUnk00adb17c::Slot49_adae18(uint32_t a)
{
    *OB_PTR(Blk3_adb17c, a) = FLD_adb17c(Blk3_adb17c, 0x148);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0098ac70 score 17
void cUnk00adb17c::Slot16_adae18(uint32_t a)
{
    *OB_PTR(Blk4_adb17c, a) = FLD_adb17c(Blk4_adb17c, 0x54);
}
#endif

// FUNCTION: 0x0098e840
void Fix_adb17c::Slot51_adae18()
{
    reinterpret_cast<S18_adb17c*>(this)->Slot50_adb17c();
}

#ifdef OB_DRAFTS
// CLOSE: 0x0098e870 score 2
void Fix_adb17c::Slot27_adae18()
{
    reinterpret_cast<S20_adb17c*>(reinterpret_cast<char*>(this) + 4)->Slot04_adb17c();
}
#endif

// FUNCTION: 0x0098ad70
void Fix_adb17c::Slot09_adaf30()
{
    reinterpret_cast<E88_adb17c*>(reinterpret_cast<char*>(this) + 0x68)->Slot13_adb17c();
}

// FUNCTION: 0x0098df90
bool cUnk00adb17c::Slot09_ad1a98(uint32_t /*a*/)
{
    return Slot17_adae18();
}

// FUNCTION: 0x0098acc0
void Fix_adb17c::Slot22_adae18(uint32_t a)
{
    reinterpret_cast<S18_adb17c*>(this)->Slot24_adb17c(a, 1);
}

// FUNCTION: 0x0098acd0
void Fix_adb17c::Slot23_adae18(uint32_t a)
{
    reinterpret_cast<S18_adb17c*>(this)->Slot24_adb17c(a, 0);
}

// FUNCTION: 0x0098e980
uint32_t cUnk00adb17c::Slot07_adae18()
{
    O100_adb17c* p = FLD_adb17c(O100_adb17c*, 0x100);
    if (p) {
        return OB_ADDR(reinterpret_cast<char*>(p) + 0x4c);
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0098e120 score 7
bool cUnk00adb17c::Slot15_adae18(uint32_t a, uint32_t b)
{
    O108_adb17c* p = FLD_adb17c(O108_adb17c*, 0x108);
    if (p) {
        return p->Slot00_adb17c(a, b);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098e9e0 score 7
uint32_t cUnk00adb17c::Slot34_adae18(uint32_t a, uint32_t b, uint32_t c)
{
    O100_adb17c* p = FLD_adb17c(O100_adb17c*, 0x100);
    if (p) {
        return p->Slot30_adb17c(a, b, c);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098e9b0 score 9
bool cUnk00adb17c::Slot35_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    O100_adb17c* p = FLD_adb17c(O100_adb17c*, 0x100);
    if (p) {
        *OB_PTR(uint32_t, a) = p->Slot30_adb17c(b, c, d);
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098ed70 score 21
void cUnk00adb17c::Slot09_adae18(uint32_t a)
{
    O100_adb17c* p = FLD_adb17c(O100_adb17c*, 0x100);
    if (p) {
        p->Slot15_adb17c(a);
        return;
    }
    OB_PTR(uint32_t, a)[0] = 1;
    OB_PTR(uint32_t, a)[1] = 0x10;
}
#endif

// FUNCTION: 0x0098e190
bool cUnk00adb17c::Slot03_adae18(uint32_t a)
{
    X_adb17c* x = new X_adb17c();
    *OB_PTR(X_adb17c*, a) = x;
    x->AddRef_adb17c();
    return true;
}

// FUNCTION: 0x0098e140
bool cUnk00adb17c::Slot04_adae18(uint32_t a, uint32_t b)
{
    X_adb17c* x = new X_adb17c();
    if (x->Slot00_adb17c(a, b)) {
        return true;
    }
    x->Destroy_adb17c(1);
    return false;
}

// FUNCTION: 0x0098dfe0
void cUnk00adb17c::Slot31_adae18(uint32_t a, uint32_t b, uint32_t c)
{
    Dim_adb17c* d = OB_PTR(Dim_adb17c, a);
    FLD_adb17c(uint32_t, 0x48) = a;
    if (d) {
        FLD_adb17c(uint16_t, 0x4c) = d->Slot09_adb17c();
        FLD_adb17c(uint16_t, 0x4e) = d->Slot10_adb17c();
        FLD_adb17c(uint16_t, 0x50) = static_cast<uint16_t>(b);
        FLD_adb17c(uint16_t, 0x52) = static_cast<uint16_t>(c);
    }
}

// FUNCTION: 0x00989ec0
void cUnk00adb17c::Slot38_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn00989ef0(a, b, c, d, e, f);
}

// FUNCTION: 0x0098a040
void cUnk00adb17c::Slot37_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn0098a070(a, b, c, d, e, f);
}

// FUNCTION: 0x0098a1c0
void cUnk00adb17c::Slot40_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn0098a1f0(a, b, c, d, e, f);
}

// FUNCTION: 0x0098a3a0
void cUnk00adb17c::Slot39_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn0098a3d0(a, b, c, d, e, f);
}

// FUNCTION: 0x0098a5b0
void cUnk00adb17c::Slot42_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn0098a5e0(a, b, c, d, e, f);
}

// FUNCTION: 0x0098a6d0
void cUnk00adb17c::Slot41_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn0098a700(a, b, c, d, e, f);
}

// FUNCTION: 0x0098a870
void cUnk00adb17c::Slot44_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn0098a8a0(a, b, c, d, e, f);
}

// FUNCTION: 0x0098aa60
void cUnk00adb17c::Slot43_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn0098aa90(a, b, c, d, e, f);
}

// FUNCTION: 0x0098aba0
void cUnk00adb17c::Slot47_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    Fn0098abd0(a, b, c, d, e, f, g);
}

// FUNCTION: 0x0098ab70
void cUnk00adb17c::Slot45_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    *OB_PTR(uint8_t, d) = static_cast<uint8_t>(0xff - static_cast<uint8_t>(a));
    *OB_PTR(uint8_t, e) = static_cast<uint8_t>(0xff - static_cast<uint8_t>(b));
    *OB_PTR(uint8_t, f) = static_cast<uint8_t>(0xff - static_cast<uint8_t>(c));
}

#ifdef OB_DRAFTS
// CLOSE: 0x0098ac30 score 8
void cUnk00adb17c::Slot48_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    *OB_PTR(uint8_t, e) = static_cast<uint8_t>(0xff - static_cast<uint8_t>(a) - static_cast<uint8_t>(d));
    *OB_PTR(uint8_t, f) = static_cast<uint8_t>(0xff - static_cast<uint8_t>(b) - static_cast<uint8_t>(d));
    *OB_PTR(uint8_t, g) = static_cast<uint8_t>(0xff - static_cast<uint8_t>(c) - static_cast<uint8_t>(d));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098ea00 score 9
bool cUnk00adb17c::Slot36_adae18(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    O100_adb17c* p = FLD_adb17c(O100_adb17c*, 0x100);
    if (p) {
        p->Slot31_adb17c(a, b, c, d);
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098e1f0 score 74
bool cUnk00adb17c::Slot10_adaf30(uint32_t a, uint32_t b)
{
    Entry_adb17c rec;
    if (a) {
        if (!Slot06_adaf30(a)) {
            return false;
        }
    }
    O9c_adb17c* o = FLD_adb17c(O9c_adb17c*, 0x9c);
    for (uint32_t i = 0; i < o->Count63_adb17c(); ++i) {
        FLD_adb17c(O9c_adb17c*, 0x9c)->Get65_adb17c(i, &rec);
        uint32_t* key = OB_PTR(uint32_t, a);
        if (rec.mTag == FLD_adb17c(uint8_t, 0xa2) && rec.mKey[0] == key[0] && rec.mKey[1] == key[1] && rec.mKey[2] == key[2]) {
            return true;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x0098def0
bool cUnk00adb17c::QueryInterface(uint32_t iid, void** ppv)
{
    void** pp = ppv;
    if (iid == 0x73283c) {
        *pp = static_cast<cUnk00adae18*>(this);
        AddRef();
        return true;
    }
    if (iid == 0xc47b747c) {
        *pp = static_cast<cUnk00adaf30*>(this);
        AddRef();
        return true;
    }
    if (iid == 0x3fa40bf) {
        *pp = static_cast<cUnk00ace69c*>(this);
        AddRef();
        return true;
    }
    if (iid == 0xe98b2f57) {
        *pp = static_cast<cUnk00a8298c*>(this);
        AddRef();
        return true;
    }
    return cRZSystemService::QueryInterface(iid, pp);
}

// ---- Colour-conversion helpers (wave 11c). Drafts carry true argument types, so they are named Draft_adb17c;
// the callers above stay on the STUB declarations (uint32_t arguments).

// STUB: 0x0098a9a0
uint8_t Fn0098a9a0(float a, float b, float c);

// FUNCTION: 0x0098abd0
void Fn0098abd0Draft_adb17c(uint8_t a, uint8_t b, uint8_t c, uint8_t* d, uint8_t* e, uint8_t* f, uint8_t* g)
{
    *d = static_cast<uint8_t>(0xff - a);
    *e = static_cast<uint8_t>(0xff - b);
    *f = static_cast<uint8_t>(0xff - c);
    if (b < a) {
        a = b;
    }
    if (c < a) {
        a = c;
    }
    *g = a;
    *d = static_cast<uint8_t>(*d - *g);
    *e = static_cast<uint8_t>(*e - *g);
    *f = static_cast<uint8_t>(*f - *g);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00989ef0 score 46
void Fn00989ef0Draft_adb17c(uint8_t r, uint8_t g, uint8_t b, uint8_t* h, uint8_t* s, uint8_t* v)
{
    uint8_t mx = r;
    if (g > r) {
        mx = g;
    }
    if (b > mx) {
        mx = b;
    }
    uint8_t mn = r;
    if (g < r) {
        mn = g;
    }
    if (b < mn) {
        mn = b;
    }
    *v = mx;
    if (mx == 0) {
        *s = 0;
        *h = 0;
        return;
    }
    uint8_t sat = static_cast<uint8_t>(static_cast<int32_t>(static_cast<float>(mx - mn) * 255.0f / static_cast<float>(mx)));
    *s = sat;
    if (sat == 0) {
        *h = 0;
        return;
    }
    uint8_t delta = static_cast<uint8_t>(mx - mn);
    float t;
    if (r == mx) {
        t = static_cast<float>(g - b) / static_cast<float>(delta);
    } else if (g == mx) {
        t = static_cast<float>(b - r) / static_cast<float>(delta) + 2.0f;
    } else {
        t = static_cast<float>(r - g) / static_cast<float>(delta) + 4.0f;
    }
    t *= 60.0f;
    if (t < 0.0f) {
        t += 360.0f;
    }
    t *= 0.70833331f;
    *h = static_cast<uint8_t>(static_cast<int32_t>(t));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098a070 score 113
void Fn0098a070Draft_adb17c(uint8_t r, uint8_t g, uint8_t b, float* h, float* s, float* v)
{
    uint8_t mx = r;
    if (g > r) {
        mx = g;
    }
    if (b > mx) {
        mx = b;
    }
    uint8_t mn = r;
    if (g < r) {
        mn = g;
    }
    if (b < mn) {
        mn = b;
    }
    *v = static_cast<float>(mx);
    if (mx == 0) {
        *s = 0.0f;
        *h = 0.0f;
        return;
    }
    uint8_t sat = static_cast<uint8_t>(static_cast<int32_t>((static_cast<float>(mx) - static_cast<float>(mn)) / static_cast<float>(mx)));
    *s = static_cast<float>(sat);
    if (*s == 0.0f) {
        *h = 0.0f;
        return;
    }
    float d = static_cast<float>(mx - mn);
    float t;
    if (r == mx) {
        t = static_cast<float>(g - b) / d;
    } else if (g == mx) {
        t = static_cast<float>(b - r) / d + 2.0f;
    } else if (b == mx) {
        t = static_cast<float>(r - g) / d + 4.0f;
    } else {
        t = *h;
    }
    *h = t;
    t = *h * 60.0f;
    *h = t;
    if (t < 0.0f) {
        *h = t + 360.0f;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098a1f0 score 72
void Fn0098a1f0Draft_adb17c(float h, uint8_t s, uint8_t v, uint8_t* r, uint8_t* g, uint8_t* b)
{
    if (s != 0) {
        float sf = static_cast<float>(s) * 0.0039215689f;
        float fv = static_cast<float>(v) * 0.0039215689f;
        int32_t hi = static_cast<int32_t>(h);
        float fr = h - static_cast<float>(hi);
        float p = (1.0f - sf) * fv;
        float q = (1.0f - fr * sf) * fv;
        float t = (1.0f - (1.0f - fr) * sf) * fv;
        float rr = q;
        float gg = p;
        float bb = fv;
        switch (hi) {
        case 0:
            rr = fv;
            gg = t;
            bb = p;
            break;
        case 1:
            rr = q;
            gg = fv;
            bb = p;
            break;
        case 2:
            rr = p;
            gg = fv;
            bb = t;
            break;
        case 3:
            rr = p;
            gg = q;
            bb = fv;
            break;
        case 4:
            rr = t;
            gg = p;
            bb = fv;
            break;
        default:
            rr = fv;
            gg = p;
            bb = q;
            break;
        }
        *r = static_cast<uint8_t>(static_cast<int32_t>(rr * 255.0f));
        *g = static_cast<uint8_t>(static_cast<int32_t>(gg * 255.0f));
        *b = static_cast<uint8_t>(static_cast<int32_t>(bb * 255.0f));
        return;
    }
    *r = v;
    *g = v;
    *b = v;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098a3d0 score 124
void Fn0098a3d0Draft_adb17c(float h, float s, float v, uint8_t* r, uint8_t* g, uint8_t* b)
{
    if (s != 0.0f) {
        int32_t hi = static_cast<int32_t>(h);
        float fr = h - static_cast<float>(hi);
        float p = (1.0f - s) * v;
        float q = (1.0f - s * fr) * v;
        float t = (1.0f - (1.0f - fr) * s) * v;
        float rr = p;
        float gg = q;
        float bb = v;
        switch (hi) {
        case 0:
            rr = v;
            gg = t;
            bb = p;
            break;
        case 1:
            rr = q;
            gg = v;
            bb = p;
            break;
        case 2:
            rr = p;
            gg = v;
            bb = t;
            break;
        case 3:
            rr = p;
            gg = q;
            bb = v;
            break;
        case 4:
            rr = t;
            gg = p;
            bb = v;
            break;
        default:
            rr = v;
            gg = p;
            bb = q;
            break;
        }
        *r = static_cast<uint8_t>(static_cast<int32_t>(rr * 255.0f));
        *g = static_cast<uint8_t>(static_cast<int32_t>(gg * 255.0f));
        *b = static_cast<uint8_t>(static_cast<int32_t>(bb * 255.0f));
        return;
    }
    v = v * 255.0f;
    *r = static_cast<uint8_t>(static_cast<int32_t>(v));
    *g = static_cast<uint8_t>(static_cast<int32_t>(v));
    *b = static_cast<uint8_t>(static_cast<int32_t>(v));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098a5e0 score 18
void Fn0098a5e0Draft_adb17c(uint8_t r, uint8_t g, uint8_t b, uint8_t* h, uint8_t* l, uint8_t* s)
{
    uint8_t mx = r;
    if (r < g) {
        mx = g;
    }
    if (mx < b) {
        mx = b;
    }
    uint8_t mn = r;
    if (g < r) {
        mn = g;
    }
    if (b < mn) {
        mn = b;
    }
    int32_t sum = mx + mn;
    int32_t d = mx - mn;
    uint8_t li = static_cast<uint8_t>(sum / 2);
    *l = li;
    if (d == 0) {
        *s = 0;
        *h = 0;
        return;
    }
    if (li < 0x80) {
        *s = static_cast<uint8_t>(d / sum);
    } else {
        *s = static_cast<uint8_t>(d / (0x1fe - sum));
    }
    int32_t t;
    if (r == mx) {
        t = (g - b) / d;
    } else if (g == mx) {
        t = (b - r) / d + 0x200;
    } else {
        t = (r - g) / d + 0x400;
    }
    t = t / 6;
    if (t < 0) {
        t += 0x100;
    }
    *h = static_cast<uint8_t>(t);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098a700 score 120
void Fn0098a700Draft_adb17c(uint8_t r, uint8_t g, uint8_t b, float* h, float* l, float* s)
{
    uint8_t mx = r;
    if (r < g) {
        mx = g;
    }
    if (mx < b) {
        mx = b;
    }
    uint8_t mn = r;
    if (g < r) {
        mn = g;
    }
    if (b < mn) {
        mn = b;
    }
    float d = static_cast<float>(mx - mn);
    float sum = static_cast<float>(mx + mn);
    float lum = static_cast<float>(0.0019607843137254902) * sum;
    *l = lum;
    if (d == 0.0f) {
        *s = 0.0f;
        *h = 0.0f;
        return;
    }
    if (lum < 0.5f) {
        sum = sum * 255.0f;
    } else {
        sum = 2.0f - sum * 0.0039215686274509803f;
    }
    *s = d / sum;
    float t;
    if (r == mx) {
        t = static_cast<float>(g - b) / (d * 255.0f);
    } else if (g == mx) {
        t = static_cast<float>(b - r) / (d * 255.0f) + 2.0f;
    } else if (b == mx) {
        t = static_cast<float>(r - g) / (d * 255.0f) + 4.0f;
    } else {
        t = *h;
    }
    *h = t;
    t = *h * 60.0f;
    *h = t;
    if (t < 0.0f) {
        *h = t + 360.0f;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098a8a0 score 29
void Fn0098a8a0Draft_adb17c(uint8_t h, uint8_t l, uint8_t s, uint8_t* r, uint8_t* g, uint8_t* b)
{
    if (s == 0) {
        *b = l;
        *r = l;
        *g = l;
        return;
    }
    double lf = static_cast<double>(l) * 0.0039215686274509803;
    double sf = static_cast<double>(s) * 0.0039215686274509803;
    double q;
    if (lf < 0.5) {
        q = (sf + 1.0) * lf;
    } else {
        q = (sf + lf) - sf * lf;
    }
    double hf = static_cast<double>(h) * 1.40625;
    float p = static_cast<float>((lf + lf) - q);
    float qq = static_cast<float>(q);
    *r = Fn0098a9a0(p, qq, static_cast<float>(hf + 120.0));
    *g = Fn0098a9a0(p, qq, static_cast<float>(hf));
    *b = Fn0098a9a0(p, qq, static_cast<float>(hf - 120.0));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098aa90 score 34
void Fn0098aa90Draft_adb17c(float h, float l, float s, uint8_t* r, uint8_t* g, uint8_t* b)
{
    if (s < 0.0f ? -s < 0.001f : s < 0.001f) {
        uint8_t v = static_cast<uint8_t>(static_cast<int32_t>(l * 255.0f));
        *b = v;
        *g = v;
        *r = v;
        return;
    }
    float q;
    if (l < 0.5f) {
        q = (s + 1.0f) * l;
    } else {
        q = (l + s) - l * s;
    }
    float p = (l + l) - q;
    *r = Fn0098a9a0(p, q, h + 120.0f);
    *g = Fn0098a9a0(p, q, h);
    *b = Fn0098a9a0(p, q, h - 120.0f);
}
#endif

// ---- Wave 11c methods. Views of the objects they call through (slot offsets as in the original).
// ask crt strcspn
struct VD_adb17c;
struct OB_NOVTABLE VR14_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Slot07_adb17c() = 0;
    virtual void Slot08_adb17c() = 0;
};
struct OB_NOVTABLE VO9c_adb17c {
    virtual void Pad00_adb17c();
    virtual void Slot01_adb17c() = 0;
    virtual void Slot02_adb17c() = 0;
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void Pad15_adb17c();
    virtual void Pad16_adb17c();
    virtual void Pad17_adb17c();
    virtual void Pad18_adb17c();
    virtual void Pad19_adb17c();
    virtual void Pad20_adb17c();
    virtual void Pad21_adb17c();
    virtual void Pad22_adb17c();
    virtual void Pad23_adb17c();
    virtual void Pad24_adb17c();
    virtual void Pad25_adb17c();
    virtual void Pad26_adb17c();
    virtual void Pad27_adb17c();
    virtual void Pad28_adb17c();
    virtual void Pad29_adb17c();
    virtual void Pad30_adb17c();
    virtual void Pad31_adb17c();
    virtual void Pad32_adb17c();
    virtual void Pad33_adb17c();
    virtual void Pad34_adb17c();
    virtual void Pad35_adb17c();
    virtual void Pad36_adb17c();
    virtual void Pad37_adb17c();
    virtual void Pad38_adb17c();
    virtual void Pad39_adb17c();
    virtual void Pad40_adb17c();
    virtual void Pad41_adb17c();
    virtual void Pad42_adb17c();
    virtual void Pad43_adb17c();
    virtual void Pad44_adb17c();
    virtual void Pad45_adb17c();
    virtual void Pad46_adb17c();
    virtual void Pad47_adb17c();
    virtual void Pad48_adb17c();
    virtual void Pad49_adb17c();
    virtual void Pad50_adb17c();
    virtual void Pad51_adb17c();
    virtual void Pad52_adb17c();
    virtual void Pad53_adb17c();
    virtual void Pad54_adb17c();
    virtual void Pad55_adb17c();
    virtual void Pad56_adb17c();
    virtual void Pad57_adb17c();
    virtual void Pad58_adb17c();
    virtual void Pad59_adb17c();
    virtual void Pad60_adb17c();
    virtual void Pad61_adb17c();
    virtual void Pad62_adb17c();
    virtual uint32_t Slot63_adb17c() = 0;
    virtual void Pad64_adb17c();
    virtual void Pad65_adb17c();
    virtual void Pad66_adb17c();
    virtual void Pad67_adb17c();
    virtual void Pad68_adb17c();
    virtual void Pad69_adb17c();
    virtual void Pad70_adb17c();
    virtual void Pad71_adb17c();
    virtual void Pad72_adb17c();
    virtual void Pad73_adb17c();
    virtual void Pad74_adb17c();
    virtual void Pad75_adb17c();
    virtual void Pad76_adb17c();
    virtual void Pad77_adb17c();
    virtual void Pad78_adb17c();
    virtual void Slot79_adb17c() = 0;
};
struct OB_NOVTABLE Vw38_adb17c {
    virtual void Pad00_adb17c();
    virtual void Slot01_adb17c() = 0;
    virtual void Slot02_adb17c() = 0;
};
struct OB_NOVTABLE Vw100_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Slot02_adb17c() = 0;
    virtual void Pad03_adb17c();
    virtual void Slot04_adb17c() = 0;
    virtual void Slot05_adb17c() = 0;
};
struct OB_NOVTABLE V4c_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Slot06_adb17c() = 0;
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual VD_adb17c* Slot15_adb17c() = 0;
    virtual void Pad16_adb17c();
    virtual void Pad17_adb17c();
    virtual void Pad18_adb17c();
    virtual void Pad19_adb17c();
    virtual void Slot20_adb17c() = 0;
};
struct OB_NOVTABLE VD_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Slot09_adb17c() = 0;
    virtual void Slot10_adb17c() = 0;
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void Slot15_adb17c(void* a) = 0;
};
struct OB_NOVTABLE VG_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual bool Slot05_adb17c(uint32_t a, uint32_t b, void* c) = 0;
};
struct OB_NOVTABLE VU9_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Slot09_adb17c() = 0;
};
struct OB_NOVTABLE VArg4_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual uint32_t Slot04_adb17c() = 0;
};
struct OB_NOVTABLE VStr_adb17c {
    virtual void Pad00_adb17c();
    virtual void Slot01_adb17c() = 0;
    virtual void Slot02_adb17c() = 0;
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void Pad15_adb17c();
    virtual void Pad16_adb17c();
    virtual void Pad17_adb17c();
    virtual void Pad18_adb17c();
    virtual void Pad19_adb17c();
    virtual void Pad20_adb17c();
    virtual void Pad21_adb17c();
    virtual void Pad22_adb17c();
    virtual void Pad23_adb17c();
    virtual void Pad24_adb17c();
    virtual void Pad25_adb17c();
    virtual void Pad26_adb17c();
    virtual void Pad27_adb17c();
    virtual void Pad28_adb17c();
    virtual void Pad29_adb17c();
    virtual void Pad30_adb17c();
    virtual void Pad31_adb17c();
    virtual void Pad32_adb17c();
    virtual void Pad33_adb17c();
    virtual void Pad34_adb17c();
    virtual void Pad35_adb17c();
    virtual void Pad36_adb17c();
    virtual void Pad37_adb17c();
    virtual void Pad38_adb17c();
    virtual void Pad39_adb17c();
    virtual void Pad40_adb17c();
    virtual void Pad41_adb17c();
    virtual void Pad42_adb17c();
    virtual void Pad43_adb17c();
    virtual void Pad44_adb17c();
    virtual void Pad45_adb17c();
    virtual void Pad46_adb17c();
    virtual void Pad47_adb17c();
    virtual void Pad48_adb17c();
    virtual void Pad49_adb17c();
    virtual void Pad50_adb17c();
    virtual void Pad51_adb17c();
    virtual void Pad52_adb17c();
    virtual void Pad53_adb17c();
    virtual void Pad54_adb17c();
    virtual void Pad55_adb17c();
    virtual void Pad56_adb17c();
    virtual void Pad57_adb17c();
    virtual void Pad58_adb17c();
    virtual void Pad59_adb17c();
    virtual void Pad60_adb17c();
    virtual void Pad61_adb17c();
    virtual void Pad62_adb17c();
    virtual void Pad63_adb17c();
    virtual void Pad64_adb17c();
    virtual void Pad65_adb17c();
    virtual void Pad66_adb17c();
    virtual void Pad67_adb17c();
    virtual void Pad68_adb17c();
    virtual void Pad69_adb17c();
    virtual void Pad70_adb17c();
    virtual void Pad71_adb17c();
    virtual void Pad72_adb17c();
    virtual void Pad73_adb17c();
    virtual void Pad74_adb17c();
    virtual void Pad75_adb17c();
    virtual void Pad76_adb17c();
    virtual const char* Slot77_adb17c() = 0;
    virtual void Pad78_adb17c();
    virtual void Pad79_adb17c();
    virtual void Slot80_adb17c() = 0;
};
struct OB_NOVTABLE VSet_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Slot03_adb17c(const char* a, uint32_t b) = 0;
};
struct OB_NOVTABLE VI6_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Slot02_adb17c() = 0;
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Slot06_adb17c(void* a, uint32_t b) = 0;
    virtual void Pad07_adb17c();
    virtual void Slot08_adb17c(void* a) = 0;
};
struct OB_NOVTABLE VX68_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Slot08_adb17c(void* a) = 0;
    virtual void Pad09_adb17c();
    virtual void Slot10_adb17c(void* a) = 0;
};

// STUB: 0x008793ec
VG_adb17c* Fn008793ec();

struct Ref_adb17c {
    void* p;
    // STUB: 0x004495c0
    void Fn004495c0();
};

struct Node_adb17c {
    uint32_t color;
    Node_adb17c* parent;
    Node_adb17c* left;
    Node_adb17c* right;
    uint32_t key;
    uint32_t value;
};

struct Map_adb17c {
    // STUB: 0x0098ef10
    void Fn0098ef10(Node_adb17c* n);
    // STUB: 0x00497520
    void Fn00497520(Node_adb17c** out, const uint32_t* key);
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// GLOBAL: 0x00a80520
extern void(__stdcall* gpImp00a80520)(uint32_t);

#ifdef OB_DRAFTS
// CLOSE: 0x0098e040 score 2
void cUnk00adb17c::Slot21_adaf30(uint32_t a)
{
    bool b = static_cast<uint8_t>(a) == 0;
    if (FLD_adb17c(bool, 0xfc) != b) {
        gpImp00a80520(b);
        FLD_adb17c(bool, 0xfc) = b;
    }
}
#endif

// FUNCTION: 0x0098e070
void cUnk00adb17c::Slot07_adaf30(uint32_t a)
{
    VO9c_adb17c* cur = FLD_adb17c(VO9c_adb17c*, 0x9c);
    if (cur != OB_PTR(VO9c_adb17c, a)) {
        if (cur) {
            if (Slot14_adae18()) {
                OB_PTR(VR14_adb17c, Slot14_adae18())->Slot07_adb17c();
            }
        }
        VO9c_adb17c* old = FLD_adb17c(VO9c_adb17c*, 0x9c);
        if (old) {
            old->Slot02_adb17c();
            FLD_adb17c(VO9c_adb17c*, 0x9c) = 0;
            FLD_adb17c(bool, 0xa0) = false;
            FLD_adb17c(bool, 0xa1) = false;
        }
        FLD_adb17c(uint32_t, 0x9c) = a;
        if (a) {
            OB_PTR(VO9c_adb17c, a)->Slot01_adb17c();
            if (!FLD_adb17c(VO9c_adb17c*, 0x9c)->Slot63_adb17c()) {
                FLD_adb17c(VO9c_adb17c*, 0x9c)->Slot79_adb17c();
            }
        }
        if (FLD_adb17c(uint32_t, 0x9c)) {
            if (Slot14_adae18()) {
                OB_PTR(VR14_adb17c, Slot14_adae18())->Slot08_adb17c();
            }
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0098e290 score 12
bool cUnk00adb17c::Slot11_adaf30(uint32_t a, uint32_t b)
{
    uint32_t r = FLD_adb17c(uint32_t, 0x9c);
    if (a) {
        r = Slot06_adaf30(a);
    }
    if (!r) {
        return false;
    }
    Entry_adb17c rec;
    uint32_t* sz = OB_PTR(uint32_t, b);
    for (;;) {
        if (sz[2] > 0x10) {
            sz[2] = 0x10;
        } else {
            int32_t area = static_cast<int32_t>(sz[1] * sz[0]);
            if (area > 0x300000) {
                sz[0] = 0x800;
                sz[1] = 0x600;
            } else if (area > 0x1d4c00) {
                sz[0] = 0x640;
                sz[1] = 0x4b0;
            } else if (area > 0x140000) {
                sz[0] = 0x500;
                sz[1] = 0x400;
            } else if (area > 0xc0000) {
                sz[0] = 0x400;
                sz[1] = 0x300;
            } else if (area > 0x75300) {
                sz[0] = 0x320;
                sz[1] = 0x258;
            } else if (area > 0x4b000) {
                sz[0] = 0x280;
                sz[1] = 0x1e0;
            } else if (area > 0x12c00) {
                sz[0] = 0x140;
                sz[1] = 0xf0;
            } else {
                return false;
            }
        }
        uint32_t i = 0;
        for (; i < FLD_adb17c(O9c_adb17c*, 0x9c)->Count63_adb17c(); ++i) {
            FLD_adb17c(O9c_adb17c*, 0x9c)->Get65_adb17c(i, &rec);
            if (rec.mTag == FLD_adb17c(uint8_t, 0xa2) && rec.mKey[0] == sz[0] && rec.mKey[1] == sz[1] && rec.mKey[2] == sz[2]) {
                return true;
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098e790 score 18
void cUnk00adb17c::Slot13_adb17c(uint32_t a)
{
    bool v = static_cast<uint8_t>(a) != 0;
    if (v != Slot12_adae18()) {
        Vw38_adb17c* o = reinterpret_cast<Vw38_adb17c*>(reinterpret_cast<char*>(this) + 0x38);
        o->Slot01_adb17c();
        if (FLD_adb17c(uint32_t, 0x34) != 1) {
            FLD_adb17c(Vw100_adb17c*, 0x100)->Slot05_adb17c();
        }
        if (v) {
            V4c_adb17c* s = reinterpret_cast<V4c_adb17c*>(reinterpret_cast<char*>(FLD_adb17c(char*, 0x100)) + 0x4c);
            VD_adb17c* d = s->Slot15_adb17c();
            uint32_t loc[2];
            d->Slot09_adb17c();
            d->Slot10_adb17c();
            d->Slot15_adb17c(loc);
        }
        FLD_adb17c(bool, 0xa2) = v;
        if (FLD_adb17c(uint32_t, 0x34) != 2) {
            reinterpret_cast<V4c_adb17c*>(reinterpret_cast<char*>(FLD_adb17c(char*, 0x100)) + 0x4c)->Slot20_adb17c();
        }
        reinterpret_cast<V4c_adb17c*>(reinterpret_cast<char*>(FLD_adb17c(char*, 0x100)) + 0x4c)->Slot06_adb17c();
        o->Slot02_adb17c();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098e880 score 17
bool cUnk00adb17c::Slot28_adae18(uint32_t a, uint32_t b, uint32_t c)
{
    VStr_adb17c* p = OB_PTR(VStr_adb17c, Slot05_adaf30(c));
    if (p) {
        p->Slot01_adb17c();
        const char* s = p->Slot77_adb17c();
        s = s + strcspn(s, "\n") + 1;
        uint32_t n = strcspn(s, "\n");
        OB_PTR(VSet_adb17c, a)->Slot03_adb17c(s, n);
        s = s + n + 1;
        OB_PTR(VSet_adb17c, b)->Slot03_adb17c(s, strcspn(s, "\n"));
        p->Slot02_adb17c();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098e910 score 22
bool cUnk00adb17c::Slot29_adae18(uint32_t a, uint32_t b)
{
    VStr_adb17c* p = FLD_adb17c(VStr_adb17c*, 0x9c);
    if (p) {
        const char* s = p->Slot77_adb17c();
        s = s + strcspn(s, "\n") + 1;
        uint32_t n = strcspn(s, "\n");
        OB_PTR(VSet_adb17c, a)->Slot03_adb17c(s, n);
        s = s + n + 1;
        OB_PTR(VSet_adb17c, b)->Slot03_adb17c(s, strcspn(s, "\n"));
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x0098ed10
bool cUnk00adb17c::Slot03_aaaa9c(void* a)
{
    if (static_cast<VArg4_adb17c*>(a)->Slot04_adb17c() == 0x8acaa95f) {
        Ref_adb17c r;
        r.p = 0;
        VG_adb17c* g = Fn008793ec();
        if (g) {
            g->Slot05_adb17c(0xeb2ea3cb, 0x4b2ea3b3, &r.p);
        }
        if (r.p) {
            static_cast<VU9_adb17c*>(r.p)->Slot09_adb17c();
        }
        r.Fn004495c0();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0098ef50 score 24
void cUnk00adb17c::Slot50_adae18(uint32_t a)
{
    float* out = OB_PTR(float, a);
    *out = 0.0f;
    if (FLD_adb17c(bool, 0x164)) {
        int32_t n = (FLD_adb17c(char*, 0x15c) - FLD_adb17c(char*, 0x158)) >> 2;
        for (int32_t i = 0; i < n; ++i) {
            *out = *out + FLD_adb17c(float*, 0x158)[i];
        }
        if (*out != 0.0f) {
            *out = static_cast<float>(((FLD_adb17c(char*, 0x15c) - FLD_adb17c(char*, 0x158)) >> 2) * 1000) / *out;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098f0a0 score 24
uint32_t cUnk00adb17c::Slot05_adaf30(uint32_t a)
{
    Node_adb17c* head = FLD_adb17c(Node_adb17c*, 0x78);
    Node_adb17c* n = head->left;
    uint32_t i = 0;
    if (a > 0 && n != head) {
        do {
            if (n->right) {
                n = n->right;
                while (n->left) {
                    n = n->left;
                }
            } else {
                Node_adb17c* p = n->parent;
                while (n == p->right) {
                    n = p;
                    p = p->parent;
                }
                if (n->right != p) {
                    n = p;
                }
            }
            ++i;
        } while (i < a);
    }
    if (n != head) {
        return n->value;
    }
    return 0;
}
#endif

// FUNCTION: 0x0098fcb0
uint32_t cUnk00adb17c::Slot06_adaf30(uint32_t a)
{
    Map_adb17c* m = reinterpret_cast<Map_adb17c*>(reinterpret_cast<char*>(this) + 0x78);
    Node_adb17c* found;
    m->Fn00497520(&found, &a);
    if (found != FLD_adb17c(Node_adb17c*, 0x78)) {
        return found->value;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0098fbe0 score 92
bool cUnk00adb17c::Fn0098fbe0()
{
    Slot07_adaf30(0);
    Node_adb17c* head = FLD_adb17c(Node_adb17c*, 0x78);
    Node_adb17c* n = head->left;
    while (n != head) {
        VStr_adb17c* o = OB_PTR(VStr_adb17c, n->value);
        if (o) {
            o->Slot80_adb17c();
            o->Slot02_adb17c();
        }
        if (n->right) {
            n = n->right;
            while (n->left) {
                n = n->left;
            }
        } else {
            Node_adb17c* p = n->parent;
            while (n == p->right) {
                n = p;
                p = p->parent;
            }
            if (n->right != p) {
                n = p;
            }
        }
    }
    Map_adb17c* m = reinterpret_cast<Map_adb17c*>(reinterpret_cast<char*>(this) + 0x78);
    if (FLD_adb17c(uint32_t, 0x7c)) {
        Node_adb17c* r = FLD_adb17c(Node_adb17c*, 0x78)->parent;
        while (r) {
            m->Fn0098ef10(r->right);
            Node_adb17c* next = r->left;
            Fn0090cf63(r);
            r = next;
        }
        FLD_adb17c(Node_adb17c*, 0x78)->left = FLD_adb17c(Node_adb17c*, 0x78);
        FLD_adb17c(Node_adb17c*, 0x78)->parent = 0;
        FLD_adb17c(Node_adb17c*, 0x78)->right = FLD_adb17c(Node_adb17c*, 0x78);
        FLD_adb17c(uint32_t, 0x7c) = 0;
    }
    return true;
}
#endif

// FUNCTION: 0x0098fce0
bool cUnk00adb17c::Slot04_ae1d24()
{
    if (FLD_adb17c(bool, 0x30)) {
        FLD_adb17c(bool, 0x30) = false;
        if (FLD_adb17c(VO9c_adb17c*, 0x108)) {
            FLD_adb17c(VO9c_adb17c*, 0x108)->Slot02_adb17c();
            FLD_adb17c(uint32_t, 0x108) = 0;
        }
        Ref_adb17c r;
        r.p = 0;
        VG_adb17c* g = Fn008793ec();
        if (g) {
            g->Slot05_adb17c(0x04fa845b, 0x652294c7, &r.p);
        }
        if (r.p) {
            static_cast<VI6_adb17c*>(r.p)->Slot06_adb17c(reinterpret_cast<char*>(this) + 0x2c, 0x8acaa95f);
        }
        if (FLD_adb17c(VI6_adb17c*, 0x6c)) {
            FLD_adb17c(VI6_adb17c*, 0x6c)->Slot06_adb17c(reinterpret_cast<char*>(this) + 0x70, 0x1a10630a);
            FLD_adb17c(VI6_adb17c*, 0x6c)->Slot02_adb17c();
            FLD_adb17c(uint32_t, 0x6c) = 0;
        }
        if (FLD_adb17c(Vw100_adb17c*, 0x100)) {
            FLD_adb17c(Vw100_adb17c*, 0x100)->Slot04_adb17c();
            FLD_adb17c(Vw100_adb17c*, 0x100)->Slot02_adb17c();
            FLD_adb17c(uint32_t, 0x100) = 0;
        }
        Fn0098fbe0();
        if (FLD_adb17c(VX68_adb17c*, 0x68)) {
            FLD_adb17c(VX68_adb17c*, 0x68)->Slot10_adb17c(this);
            FLD_adb17c(VX68_adb17c*, 0x68)->Slot08_adb17c(reinterpret_cast<char*>(this) + 0x24);
        }
        r.Fn004495c0();
    }
    return true;
}

// ---- Wave 11c, the long methods (rough drafts: the calls and branches of the asm, not its exact code).
struct OB_NOVTABLE V108b_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void Slot15_adb17c() = 0;
    virtual uint32_t Slot16_adb17c() = 0;
    virtual uint32_t Slot17_adb17c() = 0;
};
struct OB_NOVTABLE Vd4c_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void* Slot15_adb17c() = 0;
};
struct OB_NOVTABLE VdD_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual bool Slot06_adb17c(uint32_t a) = 0;
    virtual void Slot07_adb17c(uint32_t a) = 0;
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Slot12_adb17c() = 0;
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void Pad15_adb17c();
    virtual void Pad16_adb17c();
    virtual void Pad17_adb17c();
    virtual void Pad18_adb17c();
    virtual void Pad19_adb17c();
    virtual void Pad20_adb17c();
    virtual void Pad21_adb17c();
    virtual void Pad22_adb17c();
    virtual void Pad23_adb17c();
    virtual void Pad24_adb17c();
    virtual void Pad25_adb17c();
    virtual void Pad26_adb17c();
    virtual void Pad27_adb17c();
    virtual void Pad28_adb17c();
    virtual bool Slot29_adb17c(uint32_t a, void* b, void* c, uint32_t d) = 0;
    virtual void Pad30_adb17c();
    virtual void Pad31_adb17c();
    virtual void Pad32_adb17c();
    virtual void Pad33_adb17c();
    virtual void Pad34_adb17c();
    virtual void Pad35_adb17c();
    virtual void Pad36_adb17c();
    virtual void Pad37_adb17c();
    virtual void Pad38_adb17c();
    virtual bool Slot39_adb17c() = 0;
};
struct OB_NOVTABLE Vdev_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void Slot15_adb17c(uint32_t a) = 0;
    virtual void Pad16_adb17c();
    virtual void Slot17_adb17c(uint32_t a) = 0;
    virtual void Pad18_adb17c();
    virtual void Pad19_adb17c();
    virtual void Pad20_adb17c();
    virtual void Pad21_adb17c();
    virtual void Pad22_adb17c();
    virtual void Pad23_adb17c();
    virtual void Pad24_adb17c();
    virtual void Pad25_adb17c();
    virtual void Pad26_adb17c();
    virtual void Pad27_adb17c();
    virtual void Pad28_adb17c();
    virtual void Pad29_adb17c();
    virtual void Pad30_adb17c();
    virtual void Pad31_adb17c();
    virtual void Slot32_adb17c(float a, float b, float c) = 0;
    virtual void Slot33_adb17c(float a) = 0;
    virtual void Slot34_adb17c(uint32_t a, uint32_t b) = 0;
    virtual void Pad35_adb17c();
    virtual void Pad36_adb17c();
    virtual void Pad37_adb17c();
    virtual void Pad38_adb17c();
    virtual void Pad39_adb17c();
    virtual void Slot40_adb17c(uint32_t a) = 0;
    virtual void Slot41_adb17c(void* a) = 0;
    virtual void Slot42_adb17c() = 0;
    virtual void Pad43_adb17c();
    virtual void Slot44_adb17c(uint32_t a) = 0;
    virtual void Slot45_adb17c(uint32_t a) = 0;
    virtual void Pad46_adb17c();
    virtual void Pad47_adb17c();
    virtual void Pad48_adb17c();
    virtual void Pad49_adb17c();
    virtual void Pad50_adb17c();
    virtual void Slot51_adb17c(uint32_t a) = 0;
    virtual void Slot52_adb17c(uint32_t a) = 0;
    virtual void Slot53_adb17c(uint32_t a, uint32_t b, uint32_t c, uint32_t d) = 0;
    virtual void Pad54_adb17c();
    virtual void Pad55_adb17c();
    virtual void Pad56_adb17c();
    virtual void Pad57_adb17c();
    virtual void Pad58_adb17c();
    virtual void Pad59_adb17c();
    virtual void Pad60_adb17c();
    virtual void Pad61_adb17c();
    virtual void Pad62_adb17c();
    virtual void Pad63_adb17c();
    virtual void Pad64_adb17c();
    virtual void Pad65_adb17c();
    virtual void Pad66_adb17c();
    virtual void Slot67_adb17c(uint32_t a) = 0;
    virtual void Pad68_adb17c();
    virtual void Pad69_adb17c();
    virtual void Pad70_adb17c();
    virtual void Pad71_adb17c();
    virtual void Pad72_adb17c();
    virtual void Pad73_adb17c();
    virtual void Pad74_adb17c();
    virtual void Slot75_adb17c() = 0;
    virtual void Slot76_adb17c(void* a) = 0;
    virtual void Pad77_adb17c();
    virtual void Pad78_adb17c();
    virtual void Pad79_adb17c();
    virtual void Pad80_adb17c();
    virtual bool Slot81_adb17c() = 0;
};
struct OB_NOVTABLE Vobj3_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void Pad15_adb17c();
    virtual void Pad16_adb17c();
    virtual void Pad17_adb17c();
    virtual void Pad18_adb17c();
    virtual void Pad19_adb17c();
    virtual void Pad20_adb17c();
    virtual void Pad21_adb17c();
    virtual void Pad22_adb17c();
    virtual void Pad23_adb17c();
    virtual void Pad24_adb17c();
    virtual void Pad25_adb17c();
    virtual void Pad26_adb17c();
    virtual void Pad27_adb17c();
    virtual void Pad28_adb17c();
    virtual void Pad29_adb17c();
    virtual void Pad30_adb17c();
    virtual void Pad31_adb17c();
    virtual void Pad32_adb17c();
    virtual void Pad33_adb17c();
    virtual void Pad34_adb17c();
    virtual void Pad35_adb17c();
    virtual void Pad36_adb17c();
    virtual void Pad37_adb17c();
    virtual void Pad38_adb17c();
    virtual void Pad39_adb17c();
    virtual void Pad40_adb17c();
    virtual void Pad41_adb17c();
    virtual void Pad42_adb17c();
    virtual void Slot43_adb17c() = 0;
};

struct Mat_adb17c {
    float m[16];
};

#ifdef OB_DRAFTS
// CLOSE: 0x0098e5c0 score 131
bool cUnk00adb17c::Slot17_adae18()
{
    if (FLD_adb17c(uint32_t, 0x64) == 0) {
        Slot12_adaf30();
        if (FLD_adb17c(uint32_t, 0x108)) {
            FLD_adb17c(V108b_adb17c*, 0x108)->Slot15_adb17c();
        }
        if (FLD_adb17c(bool, 0x41)) {
            Vd4c_adb17c* s = reinterpret_cast<Vd4c_adb17c*>(FLD_adb17c(char*, 0x100) + 0x4c);
            VdD_adb17c* d = static_cast<VdD_adb17c*>(s->Slot15_adb17c());
            if (d->Slot39_adb17c() && FLD_adb17c(uint32_t, 0x48) != 0 && FLD_adb17c(uint32_t, 0x44) == 0) {
                d = static_cast<VdD_adb17c*>(reinterpret_cast<Vd4c_adb17c*>(FLD_adb17c(char*, 0x100) + 0x4c)->Slot15_adb17c());
                uint32_t src[4];
                uint32_t dst[4];
                src[0] = 0;
                src[1] = 0;
                src[2] = FLD_adb17c(uint16_t, 0x4c);
                src[3] = FLD_adb17c(uint16_t, 0x4e);
                int32_t w = FLD_adb17c(V108b_adb17c*, 0x108)->Slot16_adb17c() - FLD_adb17c(uint16_t, 0x50);
                int32_t h = FLD_adb17c(V108b_adb17c*, 0x108)->Slot17_adb17c() - FLD_adb17c(uint16_t, 0x52);
                dst[0] = w;
                dst[1] = h;
                dst[2] = FLD_adb17c(uint16_t, 0x4c) + w;
                dst[3] = FLD_adb17c(uint16_t, 0x4e) + h;
                if (d->Slot06_adb17c(0x8010)) {
                    d->Slot29_adb17c(FLD_adb17c(uint32_t, 0x48), src, dst, 0);
                    d->Slot07_adb17c(0x8010);
                }
            }
            reinterpret_cast<VdD_adb17c*>(FLD_adb17c(char*, 0x100) + 0x4c)->Slot12_adb17c();
        }
        if (FLD_adb17c(bool, 0x42)) {
            if (!FLD_adb17c(bool, 0xfc) && FLD_adb17c(uint32_t, 0x48) != 0) {
                uint32_t src[4];
                uint32_t dst[4];
                src[0] = 0;
                src[1] = 0;
                src[2] = FLD_adb17c(uint16_t, 0x4c);
                src[3] = FLD_adb17c(uint16_t, 0x4e);
                int32_t w = FLD_adb17c(V108b_adb17c*, 0x108)->Slot16_adb17c() - FLD_adb17c(uint16_t, 0x50);
                int32_t h = FLD_adb17c(V108b_adb17c*, 0x108)->Slot17_adb17c() - FLD_adb17c(uint16_t, 0x52);
                dst[0] = w;
                dst[1] = h;
                dst[2] = FLD_adb17c(uint16_t, 0x4c) + w;
                dst[3] = FLD_adb17c(uint16_t, 0x4e) + h;
                Slot13_adaf30(FLD_adb17c(uint32_t, 0x48), OB_ADDR(src), OB_ADDR(dst));
            }
            Vobj3_adb17c* o = OB_PTR(Vobj3_adb17c, Slot03_adaf30());
            if (o) {
                o->Slot43_adb17c();
            }
            FLD_adb17c(bool, 0x42) = false;
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0098ea30 score 53
void cUnk00adb17c::Slot12_adaf30()
{
    Vdev_adb17c* d = OB_PTR(Vdev_adb17c, Slot03_adaf30());
    if (d->Slot81_adb17c()) {
        uint32_t rect[4];
        d->Slot51_adb17c(1);
        d->Slot45_adb17c(5);
        d->Slot51_adb17c(0);
        d->Slot44_adb17c(5);
        d->Slot53_adb17c(0, 3, 2, 1);
        d->Slot52_adb17c(0);
        d->Slot45_adb17c(2);
        d->Slot44_adb17c(1);
        d->Slot45_adb17c(1);
        d->Slot45_adb17c(0);
        d->Slot45_adb17c(4);
        d->Slot45_adb17c(3);
        d->Slot45_adb17c(6);
        d->Slot33_adb17c(1.0f);
        d->Slot32_adb17c(1.0f, 1.0f, 1.0f);
        d->Slot17_adb17c(0);
        d->Slot15_adb17c(1);
        d->Slot34_adb17c(1, 1);
        d->Slot67_adb17c(0);
        d->Slot75_adb17c();
        d->Slot76_adb17c(rect);
        static Mat_adb17c mat;
        static bool init = false;
        if (!init) {
            init = true;
            for (int32_t i = 0; i < 16; ++i) {
                mat.m[i] = 0.0f;
            }
            mat.m[0] = 2.0f / static_cast<float>(static_cast<int32_t>(rect[2] - rect[0]));
            mat.m[5] = -2.0f / static_cast<float>(static_cast<int32_t>(rect[3] - rect[1]));
            mat.m[12] = -1.0f;
            mat.m[13] = 1.0f;
            mat.m[14] = 0.5f;
            mat.m[15] = 1.0f;
        }
        d->Slot40_adb17c(1);
        d->Slot41_adb17c(&mat);
        d->Slot40_adb17c(0);
        d->Slot42_adb17c();
    }
}
#endif

struct OB_NOVTABLE Vms_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual bool Slot08_adb17c(void* a, void* b, uint32_t c) = 0;
};
struct OB_NOVTABLE Vrr_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual Vrr_adb17c* Slot03_adb17c() = 0;
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual bool Slot10_adb17c(uint32_t a, void* b) = 0;
    virtual bool Slot11_adb17c(uint32_t a, void* b) = 0;
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void Pad15_adb17c();
    virtual void Pad16_adb17c();
    virtual void Pad17_adb17c();
    virtual void Pad18_adb17c();
    virtual void Pad19_adb17c();
    virtual void Pad20_adb17c();
    virtual void Pad21_adb17c();
    virtual void Pad22_adb17c();
    virtual void Pad23_adb17c();
    virtual void Pad24_adb17c();
    virtual void Pad25_adb17c();
    virtual void Pad26_adb17c();
    virtual void Pad27_adb17c();
    virtual void Pad28_adb17c();
    virtual void Pad29_adb17c();
    virtual void Pad30_adb17c();
    virtual void Pad31_adb17c();
    virtual void Pad32_adb17c();
    virtual void Pad33_adb17c();
    virtual void Pad34_adb17c();
    virtual void Pad35_adb17c();
    virtual void Pad36_adb17c();
    virtual void Pad37_adb17c();
    virtual void Pad38_adb17c();
    virtual void Pad39_adb17c();
    virtual void Pad40_adb17c();
    virtual void Pad41_adb17c();
    virtual void Pad42_adb17c();
    virtual void Pad43_adb17c();
    virtual void Pad44_adb17c();
    virtual void Pad45_adb17c();
    virtual void Pad46_adb17c();
    virtual void Pad47_adb17c();
    virtual void Pad48_adb17c();
    virtual void Pad49_adb17c();
    virtual void Pad50_adb17c();
    virtual void Pad51_adb17c();
    virtual void Pad52_adb17c();
    virtual void Pad53_adb17c();
    virtual void Pad54_adb17c();
    virtual void Pad55_adb17c();
    virtual void Pad56_adb17c();
    virtual void Pad57_adb17c();
    virtual void Pad58_adb17c();
    virtual void Pad59_adb17c();
    virtual void Pad60_adb17c();
    virtual void Pad61_adb17c();
    virtual void Pad62_adb17c();
    virtual void Pad63_adb17c();
    virtual void Pad64_adb17c();
    virtual void Pad65_adb17c();
    virtual void Pad66_adb17c();
    virtual void Pad67_adb17c();
    virtual void Pad68_adb17c();
    virtual void Pad69_adb17c();
    virtual void Pad70_adb17c();
    virtual void Pad71_adb17c();
    virtual void Pad72_adb17c();
    virtual void Pad73_adb17c();
    virtual void Pad74_adb17c();
    virtual void Pad75_adb17c();
    virtual void Pad76_adb17c();
    virtual void Pad77_adb17c();
    virtual uint32_t Slot78_adb17c() = 0;
};
struct OB_NOVTABLE Vw1c_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual uint32_t* Slot10_adb17c() = 0;
};
struct OB_NOVTABLE Vc100_adb17c {
    virtual void Pad00_adb17c();
    virtual void Slot01_adb17c() = 0;
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void Pad15_adb17c();
    virtual void Pad16_adb17c();
    virtual void Pad17_adb17c();
    virtual void Pad18_adb17c();
    virtual void Slot19_adb17c() = 0;
    virtual void Pad20_adb17c();
    virtual void Pad21_adb17c();
    virtual void Pad22_adb17c();
    virtual void Pad23_adb17c();
    virtual void Pad24_adb17c();
    virtual void Pad25_adb17c();
    virtual void Pad26_adb17c();
    virtual void Pad27_adb17c();
    virtual void Pad28_adb17c();
    virtual void Pad29_adb17c();
    virtual void Pad30_adb17c();
    virtual void Pad31_adb17c();
    virtual void Pad32_adb17c();
    virtual void Pad33_adb17c();
    virtual void Pad34_adb17c();
    virtual void Pad35_adb17c();
    virtual void Pad36_adb17c();
    virtual void Pad37_adb17c();
    virtual void Pad38_adb17c();
    virtual void Pad39_adb17c();
    virtual void Pad40_adb17c();
    virtual void Pad41_adb17c();
    virtual void Pad42_adb17c();
    virtual void Pad43_adb17c();
    virtual void Pad44_adb17c();
    virtual void Pad45_adb17c();
    virtual void Pad46_adb17c();
    virtual void Slot47_adb17c(void* a) = 0;
};
struct OB_NOVTABLE Vsl_adb17c {
    virtual bool Slot00_adb17c(uint32_t a, void* b) = 0;
    virtual void Slot01_adb17c() = 0;
    virtual void Slot02_adb17c() = 0;
    virtual Vsl_adb17c* Slot03_adb17c() = 0;
    virtual void Pad04_adb17c();
    virtual void Slot05_adb17c(void* a, uint32_t b) = 0;
};
struct OB_NOVTABLE Vmgr_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Slot07_adb17c(void* a) = 0;
    virtual void Pad08_adb17c();
    virtual void Slot09_adb17c(void* a) = 0;
};

// STUB: 0x009904d0
bool Fn009904d0();
// STUB: 0x0098e450
bool Fn0098e450(uint32_t a, void* b);
// STUB: 0x00991da0
void* Fn00991da0(void* p);
// STUB: 0x005c3ee0
void Fn005c3ee0();
// GLOBAL: 0x00b17add
extern uint8_t g00b17add;
// GLOBAL: 0x00b17aec
extern uint32_t g00b17aec;
// GLOBAL: 0x00b17ae8
extern uint32_t g00b17ae8;

#ifdef OB_DRAFTS
// CLOSE: 0x00990880 score 344
bool cUnk00adb17c::Slot03_ae1d24()
{
    if (FLD_adb17c(bool, 0x30)) {
        return true;
    }
    if (FLD_adb17c(uint32_t, 0x68) == 0) {
        VG_adb17c* g = Fn008793ec();
        FLD_adb17c(VG_adb17c*, 0x68) = g;
        if (!g) {
            return false;
        }
    }
    // (the original builds two temporary cRZStrings from the manager's name here and tests them against the
    // renderer's descriptors; not reproduced in this draft)
    FLD_adb17c(bool, 0xa2) = g00babfb4 == 0;
    Vrr_adb17c* base = reinterpret_cast<Vrr_adb17c*>(reinterpret_cast<char*>(this) + 0x20);
    if (OB_PTR(Vrr_adb17c, Slot03_adaf30()) == 0) {
        if (!Fn009904d0()) {
            return false;
        }
    }
    Blk7_adb17c* src = reinterpret_cast<Blk7_adb17c*>(FLD_adb17c(Vw1c_adb17c*, 0x1c)->Slot10_adb17c());
    FLD_adb17c(Blk7_adb17c, 0xc0) = *src;
    if (!FLD_adb17c(bool, 0xa2)) {
        if (FLD_adb17c(uint32_t, 0xc8) != g00b17aec || FLD_adb17c(uint32_t, 0xc0) < g00b17ae4.w[0] || FLD_adb17c(uint32_t, 0xc4) < g00b17ae4.w[1]) {
            FLD_adb17c(bool, 0xa2) = true;
        }
    }
    Vrr_adb17c* rr = OB_PTR(Vrr_adb17c, Slot03_adaf30());
    if (FLD_adb17c(bool, 0xa2)) {
        if (!rr->Slot10_adb17c(0, &g00b17ae4)) {
            if (!rr->Slot11_adb17c(0, &g00b17ae4)) {
                FLD_adb17c(bool, 0xa2) = false;
            }
        }
    }
    FLD_adb17c(uint32_t, 0x5c) = g00b17ae4.w[0];
    FLD_adb17c(uint32_t, 0x60) = g00b17ae4.w[1];
    FLD_adb17c(uint32_t, 0x54) = 0;
    FLD_adb17c(uint32_t, 0x58) = 0;
    Blk7_adb17c tmp;
    tmp.w[0] = g00b17ae4.w[0];
    tmp.w[1] = g00b17ae4.w[1];
    tmp.w[2] = g00b17aec;
    FLD_adb17c(Blk7_adb17c, 0xa4) = tmp;
    if (Fn0098e450(0, &g00b17ae4)) {
        void* obj = Fn005e55e0(0x88);
        Vc100_adb17c* c = 0;
        if (obj) {
            c = static_cast<Vc100_adb17c*>(Fn00991da0(obj));
        }
        FLD_adb17c(Vc100_adb17c*, 0x100) = c;
        c->Slot01_adb17c();
        FLD_adb17c(Vc100_adb17c*, 0x100)->Slot47_adb17c(this);
        FLD_adb17c(Vmgr_adb17c*, 0x68)->Slot09_adb17c(this);
        FLD_adb17c(Vmgr_adb17c*, 0x68)->Slot07_adb17c(reinterpret_cast<char*>(this) + 0x24);
        Ref_adb17c r;
        r.p = 0;
        VG_adb17c* g = Fn008793ec();
        if (g) {
            g->Slot05_adb17c(0x04fa845b, 0x652294c7, &r.p);
        }
        if (r.p) {
            static_cast<Vsl_adb17c*>(r.p)->Slot05_adb17c(reinterpret_cast<char*>(this) + 0x2c, 0x8acaa95f);
        }
        Ref_adb17c r2;
        r2.p = 0;
        g = Fn008793ec();
        if (g) {
            g->Slot05_adb17c(0xa3460deb, 0x66b217a1, &r2.p);
        }
        FLD_adb17c(void*, 0x108) = r2.p;
        bool ok = true;
        if (r2.p) {
            static_cast<Vsl_adb17c*>(r2.p)->Slot01_adb17c();
            FLD_adb17c(void*, 0x74) = reinterpret_cast<char*>(this) + 0x1c;
            Ref_adb17c r3;
            r3.p = 0;
            if (FLD_adb17c(Vsl_adb17c*, 0x108)->Slot00_adb17c(0x3ac7a210, &r3.p)) {
                if (FLD_adb17c(uint32_t, 0x6c) == 0) {
                    FLD_adb17c(Vsl_adb17c*, 0x6c) = static_cast<Vsl_adb17c*>(static_cast<Vsl_adb17c*>(r3.p)->Slot03_adb17c());
                    FLD_adb17c(Vsl_adb17c*, 0x6c)->Slot01_adb17c();
                }
                if (FLD_adb17c(uint32_t, 0x6c)) {
                    FLD_adb17c(Vsl_adb17c*, 0x6c)->Slot05_adb17c(reinterpret_cast<char*>(this) + 0x70, 0x1a10630a);
                }
            }
            FLD_adb17c(bool, 0x30) = true;
            if (r3.p) {
                static_cast<Vsl_adb17c*>(r3.p)->Slot02_adb17c();
            }
        } else {
            ok = false;
        }
        Fn005c3ee0();
        r.Fn004495c0();
        return ok;
    }
    return false;
}
#endif

struct OB_NOVTABLE Vdev2_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Pad02_adb17c();
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual void Pad15_adb17c();
    virtual void Pad16_adb17c();
    virtual void Pad17_adb17c();
    virtual void Pad18_adb17c();
    virtual void Pad19_adb17c();
    virtual void Pad20_adb17c();
    virtual void Pad21_adb17c();
    virtual void Pad22_adb17c();
    virtual void Pad23_adb17c();
    virtual void Pad24_adb17c();
    virtual void Pad25_adb17c();
    virtual void Slot26_adb17c(uint32_t a, uint32_t b) = 0;
    virtual void Pad27_adb17c();
    virtual void Pad28_adb17c();
    virtual void Pad29_adb17c();
    virtual void Pad30_adb17c();
    virtual void Pad31_adb17c();
    virtual void Pad32_adb17c();
    virtual void Pad33_adb17c();
    virtual void Pad34_adb17c();
    virtual void Pad35_adb17c();
    virtual void Pad36_adb17c();
    virtual void Pad37_adb17c();
    virtual void Pad38_adb17c();
    virtual void Pad39_adb17c();
    virtual void Pad40_adb17c();
    virtual void Pad41_adb17c();
    virtual void Pad42_adb17c();
    virtual void Pad43_adb17c();
    virtual void Pad44_adb17c();
    virtual void Pad45_adb17c();
    virtual void Pad46_adb17c();
    virtual void Pad47_adb17c();
    virtual void Pad48_adb17c();
    virtual void Pad49_adb17c();
    virtual uint32_t Slot50_adb17c() = 0;
    virtual void Pad51_adb17c();
    virtual void Pad52_adb17c();
    virtual void Pad53_adb17c();
    virtual void Pad54_adb17c();
    virtual void Pad55_adb17c();
    virtual void Pad56_adb17c();
    virtual void Pad57_adb17c();
    virtual void Pad58_adb17c();
    virtual void Pad59_adb17c();
    virtual void Pad60_adb17c();
    virtual void Pad61_adb17c();
    virtual void Pad62_adb17c();
    virtual void Pad63_adb17c();
    virtual void Pad64_adb17c();
    virtual void Pad65_adb17c();
    virtual void Pad66_adb17c();
    virtual void Pad67_adb17c();
    virtual void Slot68_adb17c(void* a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g) = 0;
    virtual void Slot69_adb17c(void* a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g) = 0;
    virtual void Pad70_adb17c();
    virtual void Pad71_adb17c();
    virtual void Slot72_adb17c(void* a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h) = 0;
    virtual void Slot73_adb17c(void* a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h) = 0;
    virtual void Pad74_adb17c();
    virtual void Pad75_adb17c();
    virtual void Pad76_adb17c();
    virtual void Pad77_adb17c();
    virtual void Pad78_adb17c();
    virtual void Pad79_adb17c();
    virtual void Pad80_adb17c();
    virtual bool Slot81_adb17c() = 0;
};
struct OB_NOVTABLE Vsrc_adb17c {
    virtual void Pad00_adb17c();
    virtual void Pad01_adb17c();
    virtual void Slot02_adb17c() = 0;
    virtual void Pad03_adb17c();
    virtual void Pad04_adb17c();
    virtual void Pad05_adb17c();
    virtual void Pad06_adb17c();
    virtual void Pad07_adb17c();
    virtual void Pad08_adb17c();
    virtual void Pad09_adb17c();
    virtual void Pad10_adb17c();
    virtual void Pad11_adb17c();
    virtual void Pad12_adb17c();
    virtual void Pad13_adb17c();
    virtual void Pad14_adb17c();
    virtual uint32_t* Slot15_adb17c(void* a) = 0;
    virtual void Pad16_adb17c();
    virtual void Pad17_adb17c();
    virtual void Pad18_adb17c();
    virtual void Pad19_adb17c();
    virtual void Pad20_adb17c();
    virtual void Pad21_adb17c();
    virtual void Pad22_adb17c();
    virtual void Pad23_adb17c();
    virtual bool Slot24_adb17c() = 0;
    virtual void Pad25_adb17c();
    virtual void Slot26_adb17c(void* a) = 0;
    virtual void Pad27_adb17c();
    virtual void Pad28_adb17c();
    virtual void Pad29_adb17c();
    virtual void Pad30_adb17c();
    virtual void Pad31_adb17c();
    virtual void Pad32_adb17c();
    virtual void Pad33_adb17c();
    virtual uint32_t Slot34_adb17c() = 0;
    virtual uint32_t Slot35_adb17c() = 0;
    virtual void Pad36_adb17c();
    virtual void Pad37_adb17c();
    virtual void Pad38_adb17c();
    virtual void Pad39_adb17c();
    virtual void Pad40_adb17c();
    virtual void Pad41_adb17c();
    virtual void Pad42_adb17c();
    virtual void Pad43_adb17c();
    virtual void Pad44_adb17c();
    virtual void Pad45_adb17c();
    virtual void Pad46_adb17c();
    virtual void Pad47_adb17c();
    virtual void Pad48_adb17c();
    virtual void Pad49_adb17c();
    virtual uint32_t Slot50_adb17c() = 0;
};
struct OB_NOVTABLE Vcq_adb17c {
    virtual bool Slot00_adb17c(uint32_t a, void* b) = 0;
    virtual void Pad01_adb17c();
    virtual void Slot02_adb17c() = 0;
    virtual void Pad03_adb17c();
    virtual bool Slot04_adb17c(uint8_t* a, uint8_t* b, uint8_t* c, uint8_t* d) = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0098f110 score 950
bool cUnk00adb17c::Slot13_adaf30(uint32_t a, uint32_t b, uint32_t c)
{
    Vdev2_adb17c* dev = OB_PTR(Vdev2_adb17c, Slot03_adaf30());
    if (!dev || !dev->Slot81_adb17c()) {
        return false;
    }
    Vsrc_adb17c* src = OB_PTR(Vsrc_adb17c, a);
    // the colour key: asked of the source through its interface 0x86d72b57
    uint8_t keyed = 0;
    Vcq_adb17c* q = 0;
    uint8_t k1;
    uint8_t k2;
    uint8_t k3;
    uint8_t k4;
    if (OB_PTR(Vcq_adb17c, a)->Slot00_adb17c(0x86d72b57, &q)) {
        keyed = q->Slot04_adb17c(&k1, &k2, &k3, &k4);
        q->Slot02_adb17c();
        q = 0;
    }
    uint32_t tmp[3];
    uint32_t fmt = *src->Slot15_adb17c(tmp);
    uint32_t bytes = 1;
    uint32_t mode = 5;
    uint32_t aux = 1;
    switch (fmt - 2) {
    case 0:
        break;
    case 2:
    case 4:
        mode = 3;
        aux = 10;
        bytes = 2;
        break;
    case 5:
        mode = 3;
        aux = 13;
        bytes = 2;
        break;
    case 6:
        aux = 1;
        mode = 2;
        bytes = 3;
        break;
    case 7:
        aux = 1;
        mode = 3;
        bytes = 4;
        break;
    default:
        return false;
    }
    uint32_t* dst = OB_PTR(uint32_t, b);
    uint32_t* srcRect = OB_PTR(uint32_t, c);
    if (FLD_adb17c(bool, 0x81)) {
        uint32_t pitch = src->Slot35_adb17c();
        uint32_t pal = 0;
        bool hasPal = src->Slot24_adb17c();
        uint32_t bits = src->Slot34_adb17c();
        if (hasPal) {
            src->Slot26_adb17c(&pal);
        }
        bits = bits + srcRect[1] * pitch + srcRect[0] * bytes;
        dev->Slot26_adb17c(0, pitch / bytes);
        uint32_t w = dst[2] - dst[0];
        uint32_t h = dst[3] - dst[1];
        bool same = (srcRect[2] - srcRect[0] == w) && (srcRect[3] - srcRect[1] == h);
        if (keyed == 0) {
            if (same) {
                dev->Slot68_adb17c(&bits, mode, aux, dst[0], dst[1], w, h);
                return true;
            }
            if (FLD_adb17c(bool, 0x80)) {
                dev->Slot69_adb17c(&bits, mode, aux, dst[0], dst[1], w, h);
                return true;
            }
        } else {
            if (same) {
                dev->Slot72_adb17c(&bits, mode, aux, dst[0], dst[1], w, h, 0xffffffff);
                return true;
            }
            if (FLD_adb17c(bool, 0x80)) {
                dev->Slot73_adb17c(&bits, mode, aux, dst[0], dst[1], w, h, 0xffffffff);
            }
        }
        return true;
    }
    // Textured-quad path: the source is bound as a texture (device slots 0xcc/0xb4/0xb0/0xd4 set the states), and one
    // quad per tile of the source is built (4 vertices of 0x18 bytes each, six 16-bit indices) and drawn; not
    // reproduced in this draft.
    return true;
}
#endif
