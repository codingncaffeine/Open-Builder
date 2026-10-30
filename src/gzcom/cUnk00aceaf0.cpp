#include <new>
#include <string.h>
#include "classes/cUnk00aceaf0.h"
#include "common/crt.h"
#include "gzcom/cRZString.h"

// The date object as the helpers see it: a vtable pointer and the Julian day number.
struct DateView_aceaf0 {
    uint32_t mVt;
    uint32_t mnJulian;
    // STUB: 0x00912789
    void Fn00912789(uint32_t* month, uint32_t* day, uint32_t* year);
    // STUB: 0x0091276f
    int32_t Fn0091276f(const DateView_aceaf0* other);
    // STUB: 0x0091282d
    cGZDate Fn0091282d(const DateView_aceaf0* other);
    // STUB: 0x0091284e
    cGZDate Fn0091284e(const DateView_aceaf0* other);
    // STUB: 0x00912ad9
    uint32_t Fn00912ad9(const DateView_aceaf0* a, const DateView_aceaf0* b);
    // STUB: 0x0091286f
    uint32_t Fn0091286f();
    // STUB: 0x0091288b
    uint32_t Fn0091288b();
    // STUB: 0x009128a3
    uint32_t Fn009128a3();
    // STUB: 0x00912bcc
    uint32_t Fn00912bcc();
    // STUB: 0x00912beb
    uint32_t Fn00912beb();
    // STUB: 0x00912c07
    uint32_t Fn00912c07(uint32_t month);
    // STUB: 0x009130e4
    void Fn009130e4(uint32_t a, uint32_t b);
    // STUB: 0x00913113
    void Fn00913113(uint32_t a, uint32_t b, uint32_t c);
    // STUB: 0x00913131
    void Fn00913131(uint32_t a, uint32_t b, uint32_t c);
    // STUB: 0x00913216
    void Fn00913216(const uint32_t* t);
    // STUB: 0x00912c42
    cGZDate Fn00912c42(uint32_t a);
    // STUB: 0x00912c79
    void Fn00912c79(cRZString* out, uint32_t a);
};

// The same view whose method bodies are the drafts (a visible body changes what the callers compile to).
struct DateViewDraft_aceaf0 {
    uint32_t mVt;
    uint32_t mnJulian;
    // STUB: 0x00912789
    void Fn00912789(uint32_t* month, uint32_t* day, uint32_t* year);
    int32_t Fn0091276f(const DateView_aceaf0* other);
    cGZDate Fn0091282d(const DateView_aceaf0* other);
    cGZDate Fn0091284e(const DateView_aceaf0* other);
    uint32_t Fn00912ad9(const DateView_aceaf0* a, const DateView_aceaf0* b);
    uint32_t Fn0091286f();
    uint32_t Fn0091288b();
    uint32_t Fn009128a3();
    uint32_t Fn00912bcc();
    uint32_t Fn00912beb();
    uint32_t Fn00912c07(uint32_t month);
    void Fn009130e4(uint32_t a, uint32_t b);
    void Fn00913113(uint32_t a, uint32_t b, uint32_t c);
    void Fn00913131(uint32_t a, uint32_t b, uint32_t c);
    void Fn00913216(const uint32_t* t);
    cGZDate Fn00912c42(uint32_t a);
    void Fn00912c79(cRZString* out, uint32_t a);
};

// A date copied out of another date object (the 8-byte value type).
struct Rz_aceaf0 {
    uint32_t mVt;
    uint32_t mnJulian;
    // STUB: 0x009126f3
    Rz_aceaf0(const void* date);
};

// A whole date object: both bases and the reference count.
struct DateObj_aceaf0 : public cUnk00aceaf0 {
    // STUB: 0x00912e24
    DateObj_aceaf0(const void* date);
    static void* operator new(size_t, void* p) { return p; }
};

// The same, copied from an 8-byte date.
struct DateObj2_aceaf0 : public cUnk00aceaf0 {
    // STUB: 0x00912e4e
    DateObj2_aceaf0(const cGZDate& date);
};

// The time value of the C runtime, as the original's helper reads it.
struct TimeView_aceaf0 {
    uint32_t mnTime;
    // STUB: 0x00417840
    uint32_t Fn00417840();
    // STUB: 0x00417730
    bool Fn00417730();
};

// The string interface the date text is handed to.
struct StrIface_aceaf0 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void Assign(cRZString* s);
};

// GLOBAL: 0x00b18ba8
extern uint32_t g00b18ba8;
// GLOBAL: 0x00ace9f7
extern uint8_t g00ace9f7[13];
// GLOBAL: 0x00acea00
extern uint32_t g00acea00[13];
// GLOBAL: 0x00b168fc
extern const char* g00b168fc[12];

// STUB: 0x00912b5f
uint32_t Fn00912b5f(uint32_t month, uint32_t day, uint32_t year);
// STUB: 0x009126e0
uint32_t Fn009126e0(uint32_t month);
// STUB: 0x00912741
uint32_t Fn00912741(uint32_t year);
// STUB: 0x00912b49
uint32_t Fn00912b49(uint32_t year);
// STUB: 0x00912b08
uint32_t Fn00912b08(uint32_t month, uint32_t day, uint32_t year);

#ifdef OB_DRAFTS
// CLOSE: 0x00417840 score 15
uint32_t TimeView_aceaf0::Fn00417840()
{
    uint32_t t = mnTime - g00b18ba8;
    TimeView_aceaf0 v;
    v.mnTime = t;
    if (v.Fn00417730()) {
        t += 0xe10;
    }
    return t;
}
#endif

// FUNCTION: 0x0091276f
int32_t DateViewDraft_aceaf0::Fn0091276f(const DateView_aceaf0* other)
{
    uint32_t a = mnJulian;
    uint32_t b = other->mnJulian;
    if (b > a) {
        return -1;
    }
    return a > b ? 1 : 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00912789 score 10
void DateViewDraft_aceaf0::Fn00912789(uint32_t* month, uint32_t* day, uint32_t* year)
{
    uint32_t t = (mnJulian - 1721119) * 4;
    uint32_t y = (t - 1) / 146097;
    *year = y;
    uint32_t r = (t - y * 146097 - 1) / 4 * 4;
    uint32_t a = (r + 3) / 1461;
    r = (r - a * 1461 + 7) / 4;
    uint32_t b = r * 5;
    uint32_t mo = (b - 3) / 153;
    *month = mo;
    *day = (b - mo * 153 + 2) / 5;
    *year = *year * 100 + a;
    if (*month < 10) {
        *month += 3;
    } else {
        *month -= 9;
        ++*year;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0091282d score 2
cGZDate DateViewDraft_aceaf0::Fn0091282d(const DateView_aceaf0* other)
{
    const DateView_aceaf0* p = reinterpret_cast<const DateView_aceaf0*>(this);
    if (other->mnJulian > mnJulian) {
        p = other;
    }
    cGZDate r;
    r.field4 = p->mnJulian;
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0091284e score 2
cGZDate DateViewDraft_aceaf0::Fn0091284e(const DateView_aceaf0* other)
{
    const DateView_aceaf0* p = reinterpret_cast<const DateView_aceaf0*>(this);
    if (other->mnJulian < mnJulian) {
        p = other;
    }
    cGZDate r;
    r.field4 = p->mnJulian;
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00912ad9 score 30
uint32_t DateViewDraft_aceaf0::Fn00912ad9(const DateView_aceaf0* a, const DateView_aceaf0* b)
{
    uint32_t x = a->mnJulian;
    uint32_t y = b->mnJulian;
    uint32_t t = mnJulian;
    if (x > y) {
        if (t >= y && t <= x) {
            return 1;
        }
        return 0;
    }
    if (t >= x && t <= y) {
        return 1;
    }
    return 0;
}
#endif

// FUNCTION: 0x0091286f
uint32_t DateViewDraft_aceaf0::Fn0091286f()
{
    uint32_t year;
    uint32_t day;
    uint32_t month;
    Fn00912789(&month, &day, &year);
    return month;
}

// FUNCTION: 0x0091288b
uint32_t DateViewDraft_aceaf0::Fn0091288b()
{
    return (((mnJulian + 1) % 7) + 6) % 7 + 1;
}

// FUNCTION: 0x009128a3
uint32_t DateViewDraft_aceaf0::Fn009128a3()
{
    uint32_t month;
    uint32_t day;
    uint32_t year;
    Fn00912789(&month, &day, &year);
    return year;
}

// FUNCTION: 0x00912bcc
uint32_t DateViewDraft_aceaf0::Fn00912bcc()
{
    return mnJulian - Fn00912b5f(12, 31, Fn009128a3() - 1);
}

// FUNCTION: 0x00912beb
uint32_t DateViewDraft_aceaf0::Fn00912beb()
{
    uint32_t month;
    uint32_t day;
    uint32_t year;
    Fn00912789(&month, &day, &year);
    return day;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00912c07 score 4
uint32_t DateViewDraft_aceaf0::Fn00912c07(uint32_t month)
{
    if (Fn009126e0(month)) {
        uint32_t days = g00acea00[month];
        if (month > 2 && Fn00912741(Fn009128a3())) {
            ++days;
        }
        return days;
    }
    return 0;
}
#endif

// FUNCTION: 0x009130e4
void DateViewDraft_aceaf0::Fn009130e4(uint32_t a, uint32_t b)
{
    if (b) {
        mnJulian = Fn00912b5f(12, 31, b - 1) + a;
    } else {
        mnJulian = a + 0x24db1a;
    }
}

// FUNCTION: 0x00913113
void DateViewDraft_aceaf0::Fn00913113(uint32_t a, uint32_t b, uint32_t c)
{
    mnJulian = Fn00912b5f(a, b, c);
}

// FUNCTION: 0x00913131
void DateViewDraft_aceaf0::Fn00913131(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t m = 1;
    int32_t i = 0;
    do {
        if (OB_STRNICMP(g00b168fc[i], OB_PTR(const char, a), 3) == 0) {
            m = i + 1;
        }
        ++i;
    } while (i < 12);
    mnJulian = Fn00912b5f(m, b, c);
}

// FUNCTION: 0x00913216
void DateViewDraft_aceaf0::Fn00913216(const uint32_t* t)
{
    uint32_t j = 0;
    if (*t > 0) {
        j = reinterpret_cast<const TimeView_aceaf0*>(t)->mnTime;
        j = const_cast<TimeView_aceaf0*>(reinterpret_cast<const TimeView_aceaf0*>(t))->Fn00417840() / 86400 + 0x24db1a;
    }
    mnJulian = j;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00912e24 score 9
DateObj_aceaf0::DateObj_aceaf0(const void* date)
{
    field4 = OB_PTR(cUnk00aceb48, OB_ADDR(date) + 8)->Slot26_aceb48();
    mnRefCount = 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00912e4e score 7
DateObj2_aceaf0::DateObj2_aceaf0(const cGZDate& date)
{
    field4 = date.field4;
    mnRefCount = 0;
}
#endif

// FUNCTION: 0x00912acc
void cUnk00aceaf0::Slot45_aceb48(uint32_t year)
{
    Fn00912741(year);
}

// FUNCTION: 0x0091296c
uint32_t cUnk00aceaf0::Slot19_aceb48()
{
    return 0 < field4;
}

// FUNCTION: 0x00912a78
uint32_t cUnk00aceaf0::Slot33_aceb48(uint32_t a)
{
    return field4 - a;
}

// FUNCTION: 0x00912a82
uint32_t cUnk00aceaf0::Slot35_aceb48(uint32_t a)
{
    return field4 + a;
}

// FUNCTION: 0x00912a8c
uint32_t cUnk00aceaf0::Slot37_aceb48()
{
    ++field4;
    return OB_ADDR(static_cast<cUnk00aceb48*>(this));
}

// FUNCTION: 0x00912a99
uint32_t cUnk00aceaf0::Slot38_aceb48()
{
    --field4;
    return OB_ADDR(static_cast<cUnk00aceb48*>(this));
}

// FUNCTION: 0x00912aa6
uint32_t cUnk00aceaf0::Slot39_aceb48(uint32_t a)
{
    field4 += a;
    return OB_ADDR(static_cast<cUnk00aceb48*>(this));
}

// FUNCTION: 0x00912ab9
uint32_t cUnk00aceaf0::Slot40_aceb48(uint32_t a)
{
    field4 -= a;
    return OB_ADDR(static_cast<cUnk00aceb48*>(this));
}

// FUNCTION: 0x00912a4e
uint32_t cUnk00aceaf0::Slot34_aceb48(uint32_t a)
{
    return field4 - OB_PTR(cUnk00aceb48, a)->Slot26_aceb48();
}

// FUNCTION: 0x00912a65
uint32_t cUnk00aceaf0::Slot36_aceb48(uint32_t a)
{
    return OB_PTR(cUnk00aceb48, a)->Slot26_aceb48() + field4;
}

// FUNCTION: 0x009128cd
void cUnk00aceaf0::Slot08_aceb48(uint32_t a)
{
    Slot04_aceb48(OB_PTR(cUnk00aceb48, a)->Slot26_aceb48());
}

// FUNCTION: 0x009128e7
bool cUnk00aceaf0::Slot00_aceb48(uint32_t iid, uint32_t out)
{
    switch (iid) {
    case 1:
    case 0x43378255:
        *OB_PTR(cUnk00aceb48*, out) = static_cast<cUnk00aceb48*>(this);
        Slot01_aceb48();
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00912912 score 5
void cUnk00aceaf0::Slot02_aceb48()
{
    if (mnRefCount <= 1) {
        delete this;
        return;
    }
    --mnRefCount;
}
#endif

// FUNCTION: 0x00912938
void cUnk00aceaf0::Slot11_aceb48(uint32_t a)
{
    Rz_aceaf0 t(OB_PTR(void, a));
    reinterpret_cast<DateView_aceaf0*>(this)->Fn0091276f(reinterpret_cast<const DateView_aceaf0*>(&t));
}

// FUNCTION: 0x00912982
uint32_t cUnk00aceaf0::Slot27_aceb48(uint32_t a)
{
    Rz_aceaf0 t(OB_PTR(void, a));
    return field4 < t.mnJulian;
}

// FUNCTION: 0x009129a4
uint32_t cUnk00aceaf0::Slot28_aceb48(uint32_t a)
{
    Rz_aceaf0 t(OB_PTR(void, a));
    return t.mnJulian >= field4;
}

// FUNCTION: 0x009129c5
uint32_t cUnk00aceaf0::Slot29_aceb48(uint32_t a)
{
    Rz_aceaf0 t(OB_PTR(void, a));
    return t.mnJulian < field4;
}

// FUNCTION: 0x009129e7
uint32_t cUnk00aceaf0::Slot30_aceb48(uint32_t a)
{
    Rz_aceaf0 t(OB_PTR(void, a));
    return field4 >= t.mnJulian;
}

// FUNCTION: 0x00912a08
bool cUnk00aceaf0::Slot31_aceb48(uint32_t a)
{
    Rz_aceaf0 t(OB_PTR(void, a));
    return field4 == t.mnJulian;
}

// FUNCTION: 0x00912a2b
bool cUnk00aceaf0::Slot32_aceb48(uint32_t a)
{
    Rz_aceaf0 t(OB_PTR(void, a));
    return field4 != t.mnJulian;
}

// FUNCTION: 0x00912e9f
void cUnk00aceaf0::Slot09_aceb48(uint32_t out)
{
    DateObj_aceaf0* obj = ::new DateObj_aceaf0(this);
    cUnk00aceb48* iface = static_cast<cUnk00aceb48*>(obj);
    *OB_PTR(cUnk00aceb48*, out) = iface;
    iface->Slot01_aceb48();
}

// FUNCTION: 0x00912ed7
void cUnk00aceaf0::Slot10_aceb48(uint32_t a, uint32_t b)
{
    Rz_aceaf0 t1(OB_PTR(void, b));
    Rz_aceaf0 t2(OB_PTR(void, a));
    reinterpret_cast<DateView_aceaf0*>(this)->Fn00912ad9(reinterpret_cast<const DateView_aceaf0*>(&t2), reinterpret_cast<const DateView_aceaf0*>(&t1));
}

// FUNCTION: 0x00912f23
void cUnk00aceaf0::Slot20_aceb48()
{
    Fn00912741(reinterpret_cast<DateView_aceaf0*>(this)->Fn009128a3());
}

// FUNCTION: 0x00912f33
void cUnk00aceaf0::Slot21_aceb48(uint32_t a, uint32_t b)
{
    Rz_aceaf0 t(OB_PTR(void, a));
    DateObj2_aceaf0 d(reinterpret_cast<DateView_aceaf0*>(this)->Fn0091282d(reinterpret_cast<const DateView_aceaf0*>(&t)));
    OB_PTR(cUnk00aceb48, b)->Slot08_aceb48(OB_ADDR(static_cast<cUnk00aceb48*>(&d)));
}

// FUNCTION: 0x00912f71
void cUnk00aceaf0::Slot22_aceb48(uint32_t a, uint32_t b)
{
    Rz_aceaf0 t(OB_PTR(void, a));
    DateObj2_aceaf0 d(reinterpret_cast<DateView_aceaf0*>(this)->Fn0091284e(reinterpret_cast<const DateView_aceaf0*>(&t)));
    OB_PTR(cUnk00aceb48, b)->Slot08_aceb48(OB_ADDR(static_cast<cUnk00aceb48*>(&d)));
}

// FUNCTION: 0x00912faf
void cUnk00aceaf0::Slot24_aceb48(uint32_t a, uint32_t b)
{
    DateObj2_aceaf0 d(reinterpret_cast<DateView_aceaf0*>(this)->Fn00912c42(a));
    OB_PTR(cUnk00aceb48, b)->Slot08_aceb48(OB_ADDR(static_cast<cUnk00aceb48*>(&d)));
}

// FUNCTION: 0x00912fdd
uint32_t cUnk00aceaf0::Slot25_aceb48()
{
    return reinterpret_cast<DateView_aceaf0*>(this)->Fn009128a3() % 100;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00912fef score 6
void* cUnk00aceaf0::Slot05_aceaf0(void* ret, uint32_t)
{
    DateObj_aceaf0 old(this);
    --field4;
    new (ret) DateObj_aceaf0(&old);
    return ret;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00913018 score 6
void* cUnk00aceaf0::Slot04_aceaf0(void* ret, uint32_t)
{
    DateObj_aceaf0 old(this);
    ++field4;
    new (ret) DateObj_aceaf0(&old);
    return ret;
}
#endif

// FUNCTION: 0x00913041
void cUnk00aceaf0::Slot42_aceb48(uint32_t a, uint32_t b, uint32_t c)
{
    Fn00912b08(a, b, c);
}

// FUNCTION: 0x00913058
void cUnk00aceaf0::Slot43_aceb48(uint32_t a)
{
    Fn00912b49(a);
}

// FUNCTION: 0x00913065
void cUnk00aceaf0::Slot44_aceb48(uint32_t a, uint32_t b, uint32_t c)
{
    Fn00912b5f(a, b, c);
}

// FUNCTION: 0x009131e5
void cUnk00aceaf0::Slot17_aceb48()
{
    DateView_aceaf0* v = reinterpret_cast<DateView_aceaf0*>(this);
    v->Fn00912c07(v->Fn0091286f());
}

// FUNCTION: 0x00913245
void cUnk00aceaf0::Slot41_aceb48(uint32_t a, uint32_t b)
{
    cRZString s;
    reinterpret_cast<DateView_aceaf0*>(this)->Fn00912c79(&s, b);
    OB_PTR(StrIface_aceaf0, a)->Assign(&s);
}

// FUNCTION: 0x009126e0
uint32_t Fn009126e0Draft_aceaf0(uint32_t month)
{
    return month >= 1 && month <= 12;
}

// FUNCTION: 0x00912741
uint32_t Fn00912741Draft_aceaf0(uint32_t year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// FUNCTION: 0x00912b49
uint32_t Fn00912b49Draft_aceaf0(uint32_t year)
{
    return 365 + (Fn00912741(year) ? 1 : 0);
}

// FUNCTION: 0x00912b08
uint32_t Fn00912b08Draft_aceaf0(uint32_t month, uint32_t day, uint32_t year)
{
    if (day > 0 && Fn009126e0(month)) {
        uint32_t days = g00ace9f7[month];
        if (Fn00912741(year) && month == 2) {
            ++days;
        }
        return day <= days;
    }
    return 0;
}


// A bare date made from another date's interface.
struct Date0_aceaf0 : public cGZDate {
    Date0_aceaf0(const void* date);
};

// FUNCTION: 0x0091270e
Date0_aceaf0::Date0_aceaf0(const void* date)
{
    field4 = OB_PTR(cUnk00aceb48, OB_ADDR(date) + 8)->Slot26_aceb48();
}
