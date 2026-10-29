#include "classes/cUnk00aa4468.h"
#include <vector>

// The object's data, seen from outside: the class map knows only the vtable pointer, the rest sits at these offsets.
// The things the object holds, as the slots used here show them.
struct Item_aa4468 {
    virtual void Pad00() = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Pad03() = 0;
    virtual void Slot04(uint32_t) = 0;
};

// The holder every item is registered with (also reference counted).
struct Owner_aa4468 {
    virtual void Pad00() = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Slot15(void*) = 0;
    virtual void Slot16(void*, bool) = 0;
};

// The service that makes the owner.
struct Maker_aa4468 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual Owner_aa4468* Slot18(uint32_t) = 0;
};

// STUB: 0x00602160
Maker_aa4468* Fn00602160();

// The object at 0x00b43dd0 is told about each item added or removed while the flag is set.
struct Registry_aa4468 {
    virtual void Pad00() = 0;
    virtual void Pad01() = 0;
    virtual void Pad02() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void Pad05() = 0;
    virtual void Pad06() = 0;
    virtual void Pad07() = 0;
    virtual void Pad08() = 0;
    virtual void Pad09() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Slot28(void*) = 0;
    virtual void Slot29(void*) = 0;
};

// GLOBAL: 0x00b43dd0
extern Registry_aa4468* gpB43dd0;

// STUB: 0x005e5620
void Fn005e5620(void* p);

struct Sub_aa4468 {
    uint8_t mData[12];
    // STUB: 0x005ec330
    void Fn005ec330();
};

struct Data_aa4468 {
    void* mpVtable;
    int16_t mnRefCount;
    int16_t mnCount;
    Item_aa4468* mpFirst;
    Item_aa4468** mpMore;
    std::vector<void*> mVec;
    Owner_aa4468* mpOwner;
    Sub_aa4468 mSub;
    uint32_t mnFlags;
};

// The flag word at +0x2c as the original packs it.
struct Bits_aa4468 {
    uint8_t mPad[0x2c];
    uint32_t mbFlagA : 1;
    uint32_t mbFlagB : 1;
    uint32_t mnValueA : 5;
    uint32_t mnValueB : 4;
};

inline Bits_aa4468* Bits(cUnk00aa4468* p)
{
    return reinterpret_cast<Bits_aa4468*>(p);
}

static inline Data_aa4468* Data(cUnk00aa4468* p)
{
    return reinterpret_cast<Data_aa4468*>(p);
}

// FUNCTION: 0x005ebc50
bool cUnk00aa4468::Slot10_aa4468()
{
    return (Data(this)->mnFlags >> 1) & 1;
}

// FUNCTION: 0x005ebcc0
uint32_t cUnk00aa4468::Slot01_aa4468()
{
    return ++Data(this)->mnRefCount;
}

// FUNCTION: 0x005ebd20
bool cUnk00aa4468::Slot00_aa4468(uint32_t iid, void* ppv)
{
    if (iid == 1 || iid == 0xc6bb5efa) {
        *static_cast<cUnk00aa4468**>(ppv) = this;
        Slot01_aa4468();
        return true;
    }
    return false;
}

// FUNCTION: 0x005ebd50
uint32_t cUnk00aa4468::Slot12_aa4468()
{
    return (Data(this)->mnFlags >> 2) & 0x1f;
}

// FUNCTION: 0x005ebd60
void cUnk00aa4468::Slot13_aa4468(uint32_t v)
{
    Data(this)->mnFlags = (Data(this)->mnFlags & ~0x7cu) | (v << 2);
}

// FUNCTION: 0x005ebd80
uint32_t cUnk00aa4468::Slot14_aa4468()
{
    return (Data(this)->mnFlags >> 7) & 0xf;
}

// FUNCTION: 0x005ebd90
void cUnk00aa4468::Slot15_aa4468(uint32_t v)
{
    Data(this)->mnFlags = (Data(this)->mnFlags & ~0x780u) | (v << 7);
}

// FUNCTION: 0x005ec0a0
uint32_t cUnk00aa4468::Slot02_aa4468()
{
    Data_aa4468* d = Data(this);
    if (d->mnRefCount > 1) {
        return --d->mnRefCount;
    }
    Fn005ebcd0();
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ebc00 score 2 (the original reloads *pn in the empty case, ours folds it to xor eax,eax)
uint32_t cUnk00aa4468::Slot04_aa4468(void* pOut, void* pCount)
{
    Data_aa4468* d = Data(this);
    void** out = static_cast<void**>(pOut);
    uint32_t* pn = static_cast<uint32_t*>(pCount);
    uint32_t n = d->mnCount;
    if (*pn < n) {
        n = *pn;
    }
    *pn = n;
    if (*pn != 0) {
        out[0] = d->mpFirst;
        for (uint32_t i = 1; i < *pn; ++i) {
            out[i] = d->mpMore[i - 1];
        }
        return *pn;
    }
    return *pn;
}
#endif

// FUNCTION: 0x005ebe20
bool cUnk00aa4468::Slot05_aa4468(void* p)
{
    Data_aa4468* d = Data(this);
    Item_aa4468* item = static_cast<Item_aa4468*>(p);
    item->AddRef();
    if (d->mnCount == 0) {
        d->mpFirst = item;
    } else {
        Fn005ebc60(d->mnCount);
        d->mpMore[d->mnCount - 1] = item;
    }
    uint32_t flags = d->mnFlags;
    d->mnCount++;
    if (flags & 2) {
        gpB43dd0->Slot28(item);
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ebe80 score 119 (the original keeps the constant 2 in ebx for the flag test and the count==2 compare, shifting every register; permuter found nothing honest)
bool cUnk00aa4468::Slot06_aa4468(void* p)
{
    Data_aa4468* d = Data(this);
    Item_aa4468* item = static_cast<Item_aa4468*>(p);
    if (d->mnFlags & 2) {
        gpB43dd0->Slot29(item);
    }
    if (d->mpFirst == item) {
        d->mpFirst->Release();
        if (d->mnCount > 1) {
            Item_aa4468** m;
            m = d->mpMore;
            Item_aa4468** last = &m[d->mnCount - 2];
            d->mpFirst = *last;
            *last = 0;
            if (d->mnCount == 2) {
                d->mnCount -= 1;
                Fn005e5620(d->mpMore);
                d->mpMore = 0;
                return true;
            }
        } else {
            d->mpFirst = 0;
            --d->mnCount;
            return true;
        }
        d->mnCount -= 1;
        return true;
    }
    Item_aa4468** m = d->mpMore;
    if (0 != m) {
        int32_t i = 0;
        int32_t n = d->mnCount - 1;
        Item_aa4468** q;
        q = m;
        while (i < n) {
            if (*q == item) {
                m[i]->Release();
                while (i < n - 1) {
                    d->mpMore[i] = d->mpMore[i + 1];
                    ++i;
                }
                d->mpMore[i] = 0;
                if (i == 0) {
                    Fn005e5620(d->mpMore);
                    d->mpMore = 0;
                }
                d->mnCount--;
                return true;
            }
            ++i, ++q;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x005ec0c0
void cUnk00aa4468::Slot08_aa4468(uint8_t v)
{
    Data_aa4468* d = Data(this);
    if (v != Slot10_aa4468()) {
        bool on = (v != 0);
        d->mnFlags = (static_cast<uint32_t>(on) << 1) | (d->mnFlags & ~2u);
        Fn005ebf80();
        if (v) {
            Fn005ebff0();
        } else {
            Fn005ec050();
        }
    }
}

// FUNCTION: 0x005ec110
void cUnk00aa4468::Slot09_aa4468(uint8_t v)
{
    Data_aa4468* d = Data(this);
    if ((*reinterpret_cast<uint8_t*>(&d->mnFlags) & 1) != v) {
        bool on = (v != 0);
        d->mnFlags = static_cast<uint32_t>(on) | (d->mnFlags & ~1u);
        if (Slot10_aa4468()) {
            Fn005ebf80();
        }
    }
}

// FUNCTION: 0x005ec190
bool cUnk00aa4468::Slot07_aa4468(void* p)
{
    Data_aa4468* d = Data(this);
    d->mVec.push_back(p);
    if (d->mpOwner == 0) {
        Owner_aa4468* o = Fn00602160()->Slot18(0);
        Owner_aa4468* old = d->mpOwner;
        if (o != old) {
            if (o) {
                o->AddRef();
            }
            d->mpOwner = o;
            if (old) {
                old->Release();
            }
        }
    }
    d->mpOwner->Slot16(p, (d->mnFlags & 1) && Slot10_aa4468());
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ec240 score 2 (xor edi,edi sits one instruction later than in the original)
void cUnk00aa4468::Slot11_aa4468()
{
    Data_aa4468* d = Data(this);
    if (d->mnFlags & 2) {
        Fn005ec050();
    }
    if (d->mnCount != 0) {
        d->mpFirst->Slot04(0);
        d->mpFirst->Release();
        int32_t n = d->mnCount - 1;
        d->mpFirst = 0;
        for (int32_t i = 0; i < n; ++i) {
            d->mpMore[i]->Slot04(0);
            d->mpMore[i]->Release();
        }
        Fn005e5620(d->mpMore);
        d->mpMore = 0;
        d->mnCount = 0;
    }
    if (d->mVec.begin() != d->mVec.end()) {
        for (uint32_t i = 0; i < d->mVec.size(); ++i) {
            d->mpOwner->Slot15(d->mVec[i]);
        }
        d->mVec.clear();
    }
    Slot13_aa4468(0);
    Slot15_aa4468(0);
}
#endif
