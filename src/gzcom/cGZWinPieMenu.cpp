#include "classes/cGZWinPieMenu.h"
#include "gzcom/cRZString.h"

#define PIE_I32(base, off) (*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + (off)))

// An object that takes a pointer in its slot 14.
struct cTarget_ae3338 {
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
    virtual void Take(void* value);
};

// A reference counted object held by an entry.
struct cRef_ae3338 {
    virtual void D0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

// The parent, seen through the slot used to report the end of a popup.
struct cParent_ae3338 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void Notify(uint32_t kind, void* window, uint32_t value);
};

// A menu entry: a label, a held object, a flag and a few values (0x30 bytes).
struct Entry_ae3338 {
    cRZString mLabel;
    cRef_ae3338* mpObject;
    bool mbEnabled;
    float mfValue;
    uint32_t mnValues[4];
    // STUB: 0x004f20c0
    void AssignObject(void* object);
    Entry_ae3338* Fn009d57dfDraft_ae3338(const cIGZString* label, void* object);
    void Fn009d5814Draft_ae3338();
};

// FUNCTION: 0x009d40f2
void cGZWinPieMenu::Slot37_ae3338(uint32_t a, uint32_t b, uint32_t c)
{
    fielde0 = MakeFillColor(a, b, c);
}

// FUNCTION: 0x009d4116
void cGZWinPieMenu::Slot39_ae3338(uint32_t a, uint32_t b, uint32_t c)
{
    fielde4 = MakeFillColor(a, b, c);
}

// FUNCTION: 0x009d413a
void cGZWinPieMenu::Slot41_ae3338(uint32_t a, uint32_t b, uint32_t c)
{
    fielde8 = MakeFillColor(a, b, c);
}

// FUNCTION: 0x009d41b1
bool cGZWinPieMenu::Slot33_ae3338(uint32_t a)
{
    OB_PTR(cTarget_ae3338, a)->Take(reinterpret_cast<char*>(this) + 0xf4);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d41c5 score 4 (tail jmp through the slot)
void cGZWinPieMenu::Slot32_ae3338()
{
    reinterpret_cast<cTarget_ae3338*>(reinterpret_cast<char*>(this) + 0xf4)->Take(0);
}
#endif

#ifdef OB_DRAFTS
#endif

// FUNCTION: 0x009d41cd
bool cGZWinPieMenu::Slot10_ae3338()
{
    bool r = Slot09_ae3338();
    int32_t x = PIE_I32(this, 0x128) - PIE_I32(this, 0x130);
    int32_t y = PIE_I32(this, 0x12c) - PIE_I32(this, 0x134);
    PIE_I32(this, 0x138) = x;
    PIE_I32(this, 0x13c) = y;
    Slot07_add348(x, y, PIE_I32(this, 0x140) + x, PIE_I32(this, 0x144) + y);
    return r;
}

#ifdef OB_DRAFTS

#endif

// FUNCTION: 0x009d420f
bool cGZWinPieMenu::GZOnCharacter(uint32_t a)
{
    if (field4c) {
        SendMsg(field4c, 3, 0x1aad67d8, static_cast<int8_t>(a), 0);
    }
    return cGZWin::GZOnCharacter(a);
}

#ifdef OB_DRAFTS

#endif

// FUNCTION: 0x009d4242
bool cGZWinPieMenu::GZOnKeyDown(uint32_t a, uint32_t /*b*/)
{
    if (a != 0x1b) {
        if (field4c) {
            SendMsg(field4c, 3, 0x1aad67d9, a, 0);
        }
        return false;
    }
    fielddc = 0xffffffff;
    if (field4c) {
        SendMsg(field4c, 3, 0x1aad67d7, 0x1b, 0);
    }
    Slot55_ae3338();
    return true;
}

#ifdef OB_DRAFTS

#endif

// FUNCTION: 0x009d4454
void cGZWinPieMenu::Slot54_ae3338(uint32_t a)
{
    if (PIE_I32(this, 0x184) & 0xff) {
        OB_PTR(cParent_ae3338, field4)->Notify(0xf, this, a);
        field148 = false;
        reinterpret_cast<bool*>(this)[0x149] = false;
    } else {
        Slot50_ae3338();
    }
}

#ifdef OB_DRAFTS

#endif

// FUNCTION: 0x009d4490
void cGZWinPieMenu::Slot55_ae3338()
{
    Slot54_ae3338(fielddc);
}

#ifdef OB_DRAFTS

// CLOSE: 0x009d57df score 15
Entry_ae3338* Entry_ae3338::Fn009d57dfDraft_ae3338(const cIGZString* label, void* object)
{
    new (&mLabel) cRZString(*label);
    AssignObject(object);
    mfValue = 0.0f;
    mnValues[0] = 0;
    mnValues[1] = 0;
    mnValues[2] = 0;
    mnValues[3] = 0;
    mbEnabled = true;
    return this;
}

// CLOSE: 0x009d5814 score 9
void Entry_ae3338::Fn009d5814Draft_ae3338()
{
    if (mpObject) {
        mpObject->Release();
    }
    mLabel.~cRZString();
}

// CLOSE: 0x009d590a score 0
void Fn009d590aDraft_ae3338(Entry_ae3338* first, Entry_ae3338* last)
{
    for (Entry_ae3338* p = first; p != last; p++) {
        p->Fn009d5814Draft_ae3338();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d40c5 score 4
bool cGZWinPieMenu::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0x1aad4a4a) {
        *ppv = static_cast<cUnk00ae3338*>(this);
        AddRef();
        return true;
    }
    return cGZWin::QueryInterface(iid, ppv);
}

// CLOSE: 0x009d4c30 score 21
void cGZWinPieMenu::Slot53_ae3338(uint32_t a, uint32_t b)
{
    int32_t index = a;
    if (index >= 0 && index < (PIE_I32(this, 0x190) - PIE_I32(this, 0x18c)) / 0x30) {
        reinterpret_cast<Entry_ae3338*>(PIE_I32(this, 0x18c))[index].mbEnabled = static_cast<uint8_t>(b) != 0;
    }
}

// CLOSE: 0x009d4f11 score 26
uint32_t cGZWinPieMenu::Slot30_ae3338()
{
    uint32_t n = (PIE_I32(this, 0x190) - PIE_I32(this, 0x18c)) / 0x30;
    if (n != 0 && static_cast<int32_t>(fielddc) >= 0) {
        Entry_ae3338* e = reinterpret_cast<Entry_ae3338*>(PIE_I32(this, 0x18c)) + fielddc;
        return static_cast<int32_t>(e->mnValues[2]) / 2 + e->mnValues[0];
    }
    return 0;
}
#endif
