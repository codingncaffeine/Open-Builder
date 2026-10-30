#include "classes/cGZWinCombo.h"
#include "gzcom/cIGZString.h"
#include <string>
#include "gzcom/cRZString.h"

// The text-edit interface of the child, seen through the slots used.
struct cTE_ae2970 {
    virtual void D0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void D3();
    virtual void D4();
    virtual void* GetWindow();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void SetFont(uint32_t font);
    virtual void D10();
    virtual void D11();
    virtual void SetColor(uint32_t kind, uint32_t color);
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual void D32();
    virtual void D33();
    virtual void D34();
    virtual void D35();
    virtual void D36();
    virtual void SetColor2(uint32_t kind, uint32_t color);
    virtual void D38();
    virtual void D39();
    virtual void SetGutterX(int32_t g);
    virtual void D41();
    virtual void SetGutterY(int32_t g);
    virtual void D43();
    virtual void D44();
    virtual void D45();
    virtual void D46();
    virtual void D47();
    virtual void D48();
    virtual void SetText(const char* text, uint32_t length, uint32_t flag);
    virtual void D50();
    virtual void D51();
    virtual void D52();
    virtual void D53();
    virtual void D54();
    virtual void D55();
    virtual void D56();
    virtual void D57();
    virtual void D58();
    virtual void D59();
    virtual void D60();
    virtual void D61();
    virtual void D62();
    virtual void D63();
    virtual void D64();
    virtual void D65();
    virtual void D66();
    virtual void D67();
    virtual void D68();
    virtual void D69();
    virtual void D70();
    virtual void D71();
    virtual void D72();
    virtual void D73();
    virtual void D74();
    virtual void D75();
    virtual void SetFlagA(uint32_t f);
    virtual void D77();
    virtual void ClearFlagA(uint32_t f);
};

// The font or buffer object this window holds, seen through the slots used.
struct cRef_ae2970 {
    virtual void D0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual uint32_t GetHeight();
    virtual uint32_t Slot10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual void D32();
    virtual void D33();
    virtual void D34();
    virtual void D35();
    virtual void D36();
    virtual void D37();
    virtual void D38();
    virtual void D39();
    virtual void D40();
};

// This window through its own appended slots (0x25c on).
struct cSelf_ae2970 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void* Slot6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual bool AddChild(void* window);
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual void D32();
    virtual void D33();
    virtual void D34();
    virtual void D35();
    virtual void D36();
    virtual void D37();
    virtual void D38();
    virtual void D39();
    virtual void D40();
    virtual void D41();
    virtual int32_t GetWinHeight();
    virtual void D43();
    virtual void D44();
    virtual void D45();
    virtual void D46();
    virtual void D47();
    virtual void D48();
    virtual void D49();
    virtual void D50();
    virtual void D51();
    virtual void D52();
    virtual void D53();
    virtual void D54();
    virtual void SetArea4(int32_t l, int32_t t, int32_t r, int32_t b);
    virtual void Slot56(uint32_t a, uint32_t b);
    virtual void D57();
    virtual void D58();
    virtual void D59();
    virtual void D60();
    virtual void D61();
    virtual void D62();
    virtual uint32_t GetSender();
    virtual void Slot64(uint32_t id);
    virtual void D65();
    virtual void D66();
    virtual void D67();
    virtual void Slot68b(uint32_t a, uint32_t b);
    virtual void D69();
    virtual void D70();
    virtual void D71();
    virtual void D72();
    virtual void D73();
    virtual void D74();
    virtual void D75();
    virtual void D76();
    virtual void D77();
    virtual void D78();
    virtual void D79();
    virtual void D80();
    virtual void D81();
    virtual void D82();
    virtual void D83();
    virtual void D84();
    virtual void D85();
    virtual void D86();
    virtual void D87();
    virtual void D88();
    virtual void D89();
    virtual void D90();
    virtual void D91();
    virtual void D92();
    virtual void D93();
    virtual void D94();
    virtual void D95();
    virtual void D96();
    virtual void D97();
    virtual void D98();
    virtual void D99();
    virtual void D100();
    virtual void D101();
    virtual void D102();
    virtual uint32_t GetFillColor();
    virtual void D104();
    virtual void D105();
    virtual void SetFillColor1(uint32_t c);
    virtual void D107();
    virtual void D108();
    virtual void D109();
    virtual void D110();
    virtual void D111();
    virtual void D112();
    virtual void D113();
    virtual void D114();
    virtual void D115();
    virtual void D116();
    virtual void D117();
    virtual void D118();
    virtual void D119();
    virtual void D120();
    virtual void D121();
    virtual void D122();
    virtual void D123();
    virtual void D124();
    virtual void D125();
    virtual void D126();
    virtual void D127();
    virtual void D128();
    virtual void D129();
    virtual void D130();
    virtual void D131();
    virtual void D132();
    virtual void D133();
    virtual void D134();
    virtual void D135();
    virtual void D136();
    virtual void D137();
    virtual void D138();
    virtual void D139();
    virtual void D140();
    virtual void D141();
    virtual void D142();
    virtual void D143();
    virtual bool SendMsg5(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
    virtual void D145();
    virtual void D146();
    virtual void D147();
    virtual void D148();
    virtual void D149();
    virtual void D150();
    virtual void D151();
    virtual void D152();
    virtual void D153();
    virtual void D154();
    virtual void D155();
    virtual void SendNotify();
    virtual void D157();
    virtual void D158();
    virtual void D159();
};

// A node of the string list.
struct Node_ae2970 {
    Node_ae2970* next;
    Node_ae2970* prev;
    uint8_t text[0x14];
};


// ---- batch 4 views ----
// The component manager, seen through the slot used.
struct cGZCOM_ae2970 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual bool GetClass(uint32_t clsid, uint32_t iid, void** out);
};

// The window manager, seen through the slot used.
struct cWCM_ae2970 {
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
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual uint32_t GetColor(uint32_t id);
};

// A font, seen through the slot used.
struct cFont_ae2970 {
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
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual void D32();
    virtual void D33();
    virtual void D34();
    virtual void D35();
    virtual void D36();
    virtual void D37();
    virtual void D38();
    virtual void D39();
    virtual void D40();
    virtual void D41();
    virtual void D42();
    virtual void D43();
    virtual void D44();
    virtual void D45();
    virtual void D46();
    virtual void D47();
    virtual int32_t MeasureText(const char* text, uint32_t length);
};

// The list box interface (at +0xd8 of the list box window), seen through the slots used.
struct cLBIf_ae2970 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void* GetWindow();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void AddString(const void* text, int32_t position, uint32_t flag);
    virtual void D8();
    virtual void D9();
    virtual void SetSelection(int32_t index, uint32_t flag);
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual void D32();
    virtual void D33();
    virtual void D34();
    virtual void D35();
    virtual void D36();
    virtual void D37();
    virtual void SetFont(void* font);
    virtual void SetColor(uint32_t index, uint32_t color);
    virtual void D40();
    virtual void D41();
    virtual void SetValueA(uint32_t v);
    virtual void D43();
    virtual void D44();
    virtual void D45();
    virtual void SetAlpha(float alpha);
    virtual void D47();
    virtual void D48();
    virtual void D49();
    virtual void D50();
    virtual void SetFlag(uint32_t f);
    virtual void D52();
    virtual void D53();
    virtual void D54();
    virtual void SetPair(uint32_t a, uint32_t b);
    virtual void D56();
    virtual void SetPair2(uint32_t a, uint32_t b);
    virtual void D58();
    virtual void SetGutter(uint32_t a, uint32_t b);
};

// The list box window: constructed with a flag, its interface sits at +0xd8.
struct cLBWin_ae2970 {
    virtual void D0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void D3();
    virtual void D4();
    virtual void Finish();
    char mData[0x164];
    // STUB: 0x009ca883
    cLBWin_ae2970(bool flag);
    static void* operator new(size_t size)
    {
        return ::operator new(size);
    }
};

// The object whose slot 41 finds the index of a window.
struct cIdx_ae2970 {
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
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual void D32();
    virtual void D33();
    virtual void D34();
    virtual void D35();
    virtual void D36();
    virtual void D37();
    virtual void D38();
    virtual void D39();
    virtual void D40();
    virtual uint32_t IndexOf(void* window);
};

// A text edit window: constructed with its id, its text interface sits at +0xd8.
struct TextEditWin_ae2970 {
    char mData[0x290];
    // STUB: 0x009c01af
    TextEditWin_ae2970(uint32_t id);
    static void* operator new(size_t size)
    {
        return ::operator new(size);
    }
};

// STUB: 0x00913c72
void* WCM_ae2970();

// STUB: 0x0090ddf1
cGZCOM_ae2970* GZCOM_ae2970();

// STUB: 0x0090cf63
void StlDelete_ae2970(void* p);

// The string list (the head pointer of a doubly linked ring), seen through the slots used.
struct cList_ae2970 {
    Node_ae2970* mpHead;
    // STUB: 0x004974c0
    void PopFront();
    void Fn004974c0Draft_ae2970();
    // STUB: 0x0091b32d
    void PushFront(const cRZString* value);
    void Fn0091b32dDraft_ae2970(const cRZString* value);
    // STUB: 0x00457250
    void Insert(Node_ae2970** result, Node_ae2970* position, const cRZString* value);
    // STUB: 0x00456ab0
    void Erase(Node_ae2970** result, Node_ae2970* position);
    // STUB: 0x007b6f80
    void EraseRange(Node_ae2970** result, Node_ae2970* first, Node_ae2970* last);
    // STUB: 0x004580e0
    void PushBack(const cRZString* value);
};
// FUNCTION: 0x0092ec14
void cGZWinCombo::Slot04_ae28c8()
{
    Slot05_ae28c8();
}

// FUNCTION: 0x00999055
uint32_t cGZWinCombo::Slot09_ae28c8(uint32_t a)
{
    return (mnFlags & a) != 0;
}

// FUNCTION: 0x009ce74a
bool cGZWinCombo::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0x412ce496) {
        if (!ppv) {
            return false;
        }
        *ppv = static_cast<cUnk00ae28c8*>(this);
        AddRef();
        return true;
    }
    return cGZWin::QueryInterface(iid, ppv);
}

// FUNCTION: 0x009ce781
uint32_t cGZWinCombo::Slot05_ae28c8()
{
    uint32_t te = get_text_edit();
    if (!te) {
        if (create_text_edit()) {
            return get_text_edit();
        }
        return 0;
    }
    return te;
}

// FUNCTION: 0x009ce936
bool cGZWinCombo::Slot04_ae1d24()
{
    HideWindow();
    cRef_ae2970* arrow = static_cast<cRef_ae2970*>(mpArrow);
    if (arrow) {
        arrow->Release();
        mpArrow = 0;
    }
    cRef_ae2970* font = static_cast<cRef_ae2970*>(mpFont);
    if (font) {
        font->Release();
        mpFont = 0;
    }
    return cGZWin::Slot04_ae1d24();
}

// FUNCTION: 0x009ce973
void cGZWinCombo::Slot06_ae28c8(uint32_t a)
{
    if (!(a & mnFlags)) {
        Slot07_ae28c8(mnFlags | a);
    }
}

// FUNCTION: 0x009ce98b
void cGZWinCombo::Slot08_ae28c8(uint32_t a)
{
    if (a & mnFlags) {
        Slot07_ae28c8(~a & mnFlags);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ce9a5 score 19 (logic matches; register/order differ)
void cGZWinCombo::Slot07_ae28c8(uint32_t a)
{
    uint32_t old = mnFlags;
    if (a != old) {
        mnFlags = a;
        if ((old ^ a) & 1) {
            mbDirty = true;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ce9c0 score 22 (logic matches; register/order differ)
uint32_t cGZWinCombo::Slot68_adc8d8(uint32_t a, uint32_t b)
{
    if ((a & 2) && mbDropped) {
        return 0;
    }
    uint32_t r = cGZWin::Slot68_adc8d8(a, b);
    if (a == 2) {
        cTE_ae2970* te = OB_PTR(cTE_ae2970, get_text_edit());
        cGZWin* w = static_cast<cGZWin*>(te->GetWindow());
        int32_t v;
        if (*reinterpret_cast<bool*>(&b)) {
            w->Slot68_adc8d8(2, 1);
            v = mnArrowW + mnArrowX;
        } else {
            w->Slot68_adc8d8(2, 0);
            v = mnArrowX;
        }
        mn12c = v;
        InvalidateSelfAndParents();
    }
    return r;
}
#endif

// FUNCTION: 0x009cea4b
void cGZWinCombo::Slot08_ae1a28(uint32_t a)
{
    cGZWin::Slot08_ae1a28(a);
    cTE_ae2970* te = OB_PTR(cTE_ae2970, get_text_edit());
    if (te) {
        static_cast<cGZWin*>(te->GetWindow())->Slot08_ae1a28(a);
    }
}

// FUNCTION: 0x009cea7a
bool cGZWinCombo::Slot35_ae28c8(uint32_t a)
{
    mnComboDownColor = a;
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009cea94
bool cGZWinCombo::Slot36_ae28c8(uint32_t a)
{
    *OB_PTR(uint32_t, a) = mnComboDownColor;
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ceaa2 score 31 (logic matches; register/order differ)
bool cGZWinCombo::Slot12_ae28c8(uint32_t a, uint32_t b)
{
    int32_t idx = static_cast<int32_t>(a);
    if (idx >= 0 && idx < 3) {
        bool changed = mnColor[idx] != b;
        mnColor[idx] = b;
        if (changed) {
            InvalidateSelfAndParents();
            cTE_ae2970* te = OB_PTR(cTE_ae2970, get_text_edit());
            if (te) {
                int32_t kind;
                if (idx == 0) {
                    kind = 0;
                } else if (idx == 1) {
                    kind = 2;
                } else if (idx == 2) {
                    kind = 4;
                } else {
                    return false;
                }
                te->SetColor(kind, b);
            }
        }
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x009ceb0b
uint32_t cGZWinCombo::Slot14_ae28c8(uint32_t a)
{
    return mnColor[a];
}

// FUNCTION: 0x009ceb16
bool cGZWinCombo::Slot13_ae28c8(uint32_t a, uint32_t b)
{
    uint32_t c = mnColor[a];
    if (c != 0xdeadbeef) {
        *OB_PTR(uint32_t, b) = c;
        return true;
    }
    return false;
}

// FUNCTION: 0x009ceb34
void cGZWinCombo::Slot15_ae28c8(uint32_t a)
{
    Slot12_ae28c8(a, 0xdeadbeef);
}

// FUNCTION: 0x009ceb45
bool cGZWinCombo::Slot37_ae28c8(uint32_t a)
{
    mnBtnGutter = static_cast<int8_t>(a);
    layout(GetW(), GetH());
    return true;
}

// FUNCTION: 0x009ceb79
bool cGZWinCombo::Slot38_ae28c8(uint32_t a)
{
    *OB_PTR(int8_t, a) = mnBtnGutter;
    return true;
}

// FUNCTION: 0x009ceb87
bool cGZWinCombo::Slot39_ae28c8(uint32_t a, uint32_t b)
{
    mnTextGutterX = static_cast<int8_t>(a);
    mnTextGutterY = static_cast<int8_t>(b);
    cTE_ae2970* te = OB_PTR(cTE_ae2970, get_text_edit());
    if (te) {
        te->SetGutterX(mnTextGutterX);
        te->SetGutterY(mnTextGutterY);
        SetSize_2(GetW(), GetH());
    }
    return true;
}

// FUNCTION: 0x009cebf4
bool cGZWinCombo::Slot40_ae28c8(uint32_t a, uint32_t b)
{
    *OB_PTR(int8_t, a) = mnTextGutterX;
    *OB_PTR(int8_t, b) = mnTextGutterY;
    return true;
}

// FUNCTION: 0x009cec0b
void cGZWinCombo::Slot11_ae28c8(uint32_t a)
{
    cRef_ae2970* old = static_cast<cRef_ae2970*>(mpFont);
    if (old) {
        old->Release();
    }
    cRef_ae2970* font = OB_PTR(cRef_ae2970, a);
    mpFont = font;
    if (font) {
        font->AddRef();
    }
    cTE_ae2970* te = OB_PTR(cTE_ae2970, get_text_edit());
    if (te) {
        te->SetFont(OB_ADDR(mpFont));
    }
}

// FUNCTION: 0x009cec4e
bool cGZWinCombo::Slot21_ae28c8(uint32_t a)
{
    cTE_ae2970* te = OB_PTR(cTE_ae2970, get_text_edit());
    bool on = *reinterpret_cast<bool*>(&a);
    if (te) {
        if (on) {
            te->SetFlagA(1);
        } else {
            te->ClearFlagA(1);
        }
    }
    mbEditable = on;
    return true;
}

// FUNCTION: 0x009cec8a
bool cGZWinCombo::Slot16_ae28c8(uint32_t a)
{
    mnHighlightColor = a;
    cTE_ae2970* te = OB_PTR(cTE_ae2970, get_text_edit());
    if (te) {
        te->SetColor(5, mnHighlightColor);
    }
    return true;
}

// FUNCTION: 0x009cecb8
bool cGZWinCombo::Slot17_ae28c8(uint32_t a)
{
    uint32_t c = mnHighlightColor;
    if (c != 0xdeadbeef) {
        *OB_PTR(uint32_t, a) = c;
        return true;
    }
    return false;
}

// FUNCTION: 0x009cecd1
bool cGZWinCombo::Slot18_ae28c8(uint32_t a)
{
    mfHighlightAlpha = *reinterpret_cast<float*>(&a);
    if (mfHighlightAlpha < 0.0f) {
        mfHighlightAlpha = 0.0f;
    }
    if (mfHighlightAlpha > 1.0f) {
        mfHighlightAlpha = 1.0f;
    }
    return true;
}

// FUNCTION: 0x009ced04
bool cGZWinCombo::Slot19_ae28c8(uint32_t a)
{
    *OB_PTR(float, a) = mfHighlightAlpha;
    return true;
}

// FUNCTION: 0x009ced1e
bool cGZWinCombo::Slot23_ae28c8(uint32_t a)
{
    *OB_PTR(uint32_t, a) = mnDropOutlineColor;
    return true;
}

// FUNCTION: 0x009ced2c
bool cGZWinCombo::GZOnMouseDownL(uint32_t, uint32_t, uint32_t)
{
    do_drop_down();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ced39 score 14 (logic matches; register/order differ)
bool cGZWinCombo::GZOnKeyDown(uint32_t a, uint32_t b)
{
    switch (a) {
    case 0x26:
        Slot28_ae28c8(mnSelection - 1, 1);
        break;
    case 0x28:
        if ((b >> 2) & 1) {
            do_drop_down();
        } else {
            Slot28_ae28c8(mnSelection + 1, 1);
        }
        break;
    default:
        reinterpret_cast<cSelf_ae2970*>(this)->SendMsg5(field4c, 5, a, b, 0);
        break;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ced9f score 18 (logic matches; register/order differ)
bool cGZWinCombo::DoMessage(uint32_t a)
{
    uint32_t id = *OB_PTR(uint32_t, a);
    if (id == 0x9b1552d5) {
        send_combo_changed_msg();
    } else if (id > 0x9b1552d5 && id <= 0x9b1552d7) {
        if (!mbEditable) {
            do_drop_down();
        }
    } else {
        return cGZWin::DoMessage(a);
    }
    return true;
}
#endif

// FUNCTION: 0x009cede5
bool cGZWinCombo::Slot29_ae28c8(uint32_t a, uint32_t b)
{
    *OB_PTR(int32_t, a) = mnSelection;
    Slot31_ae28c8(mnSelection, b);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009cedff score 15 (logic matches; register/order differ)
bool cGZWinCombo::Slot31_ae28c8(uint32_t a, uint32_t b)
{
    if (get_string_address_from_index(a, OB_ADDR(&a))) {
        static_cast<cIGZString*>(OB_PTR(cIGZString, b))->Copy(*OB_PTR(cIGZString, a));
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009cee2c score 13 (logic matches; register/order differ)
bool cGZWinCombo::Slot25_ae28c8(uint32_t a)
{
    if (Slot32_ae28c8(OB_ADDR(&a), a)) {
        mbDirty = true;
        return Slot24_ae28c8(a);
    }
    return false;
}
#endif

// FUNCTION: 0x009cee5e
uint32_t cGZWinCombo::get_text_edit()
{
    uint32_t te = 0;
    if (GetChildAs(0x53430d98, 0x231a1c57, OB_ADDR(&te))) {
        OB_PTR(cTE_ae2970, te)->Release();
        return te;
    }
    return 0;
}

// FUNCTION: 0x009cf071
bool cGZWinCombo::send_combo_changed_msg()
{
    reinterpret_cast<cSelf_ae2970*>(this)->SendMsg5(field4c, 3, 0xe8711255, reinterpret_cast<cSelf_ae2970*>(this)->GetSender(), 0);
    return true;
}

struct cDraw_ae2970 {
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
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual void D32();
    virtual void D33();
    virtual void D34();
    virtual void D35();
    virtual void D36();
    virtual void D37();
    virtual void DrawBuffer(void* buffer, const void* source, const void* destination);
};

// A 16-byte rectangle.
struct Rect_ae2970 {
    int32_t v[4];
};

// STUB: 0x008d9900
void RZDrawComboButton_ae2970(cDraw_ae2970* context, const Rect_ae2970* area, uint32_t color, bool flag, uint32_t width);

// FUNCTION: 0x009cf097
void cGZWinCombo::Slot07_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    int32_t w = c - a;
    int32_t h = d - b;
    int32_t r[4];
    Slot41_ae28c8(OB_ADDR(r));
    if (w < r[0]) {
        w = r[0];
    }
    if (h < r[1]) {
        h = r[1];
    }
    if (w == static_cast<int32_t>(GetW()) && h == static_cast<int32_t>(GetH())) {
        cGZWin::Slot07_add348(a, b, c, d);
        return;
    }
    layout(w, h);
    cGZWin::Slot07_add348(a, b, a + w, b + h);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ceff6 score 2 (logic matches; register/order differ)
bool cGZWinCombo::layout(uint32_t a, uint32_t b)
{
    if (!mpArrow) {
        mnArrowH = b;
    }
    mnBtnX = a - mnArrowW;
    mnBtnY = (static_cast<int32_t>(b) - mnArrowH) / 2;
    cTE_ae2970* te = OB_PTR(cTE_ae2970, get_text_edit());
    if (te) {
        static_cast<cGZWin*>(te->GetWindow())->SetSize_2(mnBtnX - mnBtnGutter, b);
        InvalidateSelfAndParents();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009cf122 score 40 (logic matches; register/order differ)
bool cGZWinCombo::Slot33_ae28c8(uint32_t a, uint32_t b)
{
    cRef_ae2970* old = static_cast<cRef_ae2970*>(mpArrow);
    if (old) {
        old->Release();
    }
    cRef_ae2970* buf = OB_PTR(cRef_ae2970, a);
    mpArrow = buf;
    if (buf) {
        buf->AddRef();
    }
    if (mpArrow) {
        const int32_t* rect = OB_PTR(const int32_t, b);
        if (rect) {
            mnArrowX = rect[0];
            mnArrowY = rect[1];
            mnArrowW = (rect[2] - rect[0]) / 4;
            mnArrowH = rect[3] - rect[1];
        } else {
            int32_t w = static_cast<int32_t>(static_cast<cRef_ae2970*>(mpArrow)->GetHeight()) / 4;
            mnArrowX = 0;
            mnArrowY = 0;
            mnArrowW = w;
            mnArrowH = static_cast<int32_t>(static_cast<cRef_ae2970*>(mpArrow)->Slot10());
        }
    } else {
        mnArrowX = 0;
        mnArrowY = 0;
        mnArrowW = 16;
        mnArrowH = GetH();
    }
    int32_t w = GetW();
    int32_t h = GetH();
    if (w < mnArrowW) {
        w = mnArrowW;
    }
    if (h < mnArrowH) {
        h = mnArrowH;
    }
    SetSize_2(w, h);
    return true;
}
#endif

// FUNCTION: 0x009cf1fb
bool cGZWinCombo::Slot34_ae28c8(uint32_t a, uint32_t b)
{
    *OB_PTR(void*, a) = mpArrow;
    Rect_ae2970 r;
    r.v[0] = mnArrowX;
    r.v[1] = mnArrowY;
    r.v[2] = mnArrowX + mnArrowW * 4;
    r.v[3] = mnArrowH + mnArrowY;
    *OB_PTR(Rect_ae2970, b) = r;
    return *OB_PTR(void*, a) != 0;
}

// FUNCTION: 0x009cf241
bool cGZWinCombo::GZPaint()
{
    Rect_ae2970 dst;
    dst.v[0] = mnBtnX + reinterpret_cast<const int32_t*>(&field24[0])[0];
    dst.v[1] = mnBtnY + reinterpret_cast<const int32_t*>(&field24[0])[1];
    dst.v[2] = dst.v[0] + mnArrowW;
    dst.v[3] = dst.v[1] + mnArrowH;
    if (mpArrow) {
        Rect_ae2970 src;
        src.v[0] = mn12c;
        src.v[1] = mnArrowY;
        src.v[2] = mn12c + mnArrowW;
        src.v[3] = mnArrowY + mnArrowH;
        OB_PTR(cDraw_ae2970, field6c)->DrawBuffer(mpArrow, &src, &dst);
    } else {
        RZDrawComboButton_ae2970(OB_PTR(cDraw_ae2970, field6c), &dst, mnComboDownColor, !mbDropped, 1);
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009cf2dd score 14 (logic matches; register/order differ)
bool cGZWinCombo::Slot41_ae28c8(uint32_t a)
{
    int32_t* r = OB_PTR(int32_t, a);
    r[0] = mnArrowW;
    if (mpArrow) {
        r[0] = mnArrowW;
        r[1] = mnArrowH;
    } else {
        r[0] = 16;
        r[1] = 8;
    }
    if (get_text_edit()) {
        r[0] += mnBtnGutter + 1;
    }
    if (r[1] < 1) {
        r[1] = 1;
    }
    r[2] = 0x7fffffff;
    r[3] = 0x7fffffff;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009cf343 score 19 (logic matches; register/order differ)
bool cGZWinCombo::Slot32_ae28c8(uint32_t a, uint32_t b)
{
    int32_t index = 0;
    Node_ae2970* head = static_cast<Node_ae2970*>(mpStrings);
    for (Node_ae2970* n = head->next; n != head; n = n->next) {
        if (OB_PTR(cIGZString, b)->IsEqual(reinterpret_cast<const cIGZString*>(n->text), true)) {
            *OB_PTR(int32_t, a) = index;
            return true;
        }
        index++;
    }
    return false;
}
#endif

// FUNCTION: 0x009cf38c
bool cGZWinCombo::get_string_address_from_index(uint32_t a, uint32_t b)
{
    int32_t n = mnStringCount;
    if (static_cast<int32_t>(a) <= n - 1) {
        Node_ae2970* node = static_cast<Node_ae2970*>(mpStrings)->next;
        int32_t i = 0;
        if (n > 0) {
            do {
                if (i == static_cast<int32_t>(a)) {
                    *OB_PTR(void*, b) = &node->text[0];
                    return true;
                }
                node = node->next;
                i++;
            } while (i < n);
        }
    }
    return false;
}

// ---- batch 4 ----

#ifdef OB_DRAFTS
// CLOSE: 0x004974c0 score 12 (logic follows the asm)
void cList_ae2970::Fn004974c0Draft_ae2970()
{
    Node_ae2970* n = mpHead->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    reinterpret_cast<cRZString*>(n->text)->~cRZString();
    StlDelete_ae2970(n);
}

// CLOSE: 0x0091b32d score 7 (logic follows the asm)
void cList_ae2970::Fn0091b32dDraft_ae2970(const cRZString* value)
{
    Node_ae2970* result;
    Insert(&result, mpHead->next, value);
}

// CLOSE: 0x009cee91 score 5 (logic follows the asm)
bool cGZWinCombo::create_text_edit()
{
    if (get_text_edit()) {
        return true;
    }
    cWCM_ae2970* wcm = static_cast<cWCM_ae2970*>(WCM_ae2970());
    cTE_ae2970* te = 0;
    if (!GZCOM_ae2970()->GetClass(0x231a1c58, 0x231a1c57, reinterpret_cast<void**>(&te))) {
        TextEditWin_ae2970* obj = new TextEditWin_ae2970(0x11ff);
        te = obj ? reinterpret_cast<cTE_ae2970*>(reinterpret_cast<char*>(obj) + 0xd8) : 0;
        te->AddRef();
    }
    cSelf_ae2970* win = static_cast<cSelf_ae2970*>(te->GetWindow());
    win->Slot64(0x53430d98);
    win->Slot56(0, 0);
    win->SetFillColor1(reinterpret_cast<cSelf_ae2970*>(this)->GetFillColor());
    te->SetFlagA(0x200);
    te->SetFlagA(1);
    te->SetFlagA(0x400);
    te->SetFont(OB_ADDR(mpFont));
    te->SetGutterX(mnTextGutterX);
    te->SetGutterY(mnTextGutterY);
    te->SetColor2(1, wcm->GetColor(0xa8963fad));
    bool r = reinterpret_cast<cSelf_ae2970*>(this)->AddChild(win);
    te->Release();
    Slot21_ae28c8(mbEditable);
    return r;
}

// CLOSE: 0x009cf3c8 score 82 (logic follows the asm)
bool cGZWinCombo::do_drop_down()
{
    if (mbDropped) {
        return false;
    }
    cLBWin_ae2970* lb = new cLBWin_ae2970(true);
    if (!lb) {
        return false;
    }
    lb->AddRef();
    cSelf_ae2970* self = reinterpret_cast<cSelf_ae2970*>(this);
    const int32_t* area = reinterpret_cast<const int32_t*>(&field14[0]);
    mn12c = mnArrowX + mnArrowW * 2;
    mbDropped = true;
    InvalidateSelfAndParents();
    int32_t width = area[2] - area[0];
    cFont_ae2970* font = static_cast<cFont_ae2970*>(mpFont);
    if (mnFlags & 1) {
        if (mbDirty) {
            mnMaxTextWidth = 0;
            Node_ae2970* head = static_cast<Node_ae2970*>(mpStrings);
            for (Node_ae2970* n = head->next; n != head; n = n->next) {
                cRZString* s = reinterpret_cast<cRZString*>(n->text);
                int32_t w = font->MeasureText(s->data(), s->size());
                if (mnMaxTextWidth < w) {
                    mnMaxTextWidth = w;
                }
            }
            mbDirty = false;
        }
        int32_t need = mnMaxTextWidth + 8;
        if (width < need) {
            width = need;
        }
        int32_t limit;
        if (Slot10_adc8d8()) {
            limit = static_cast<cRef_ae2970*>(Slot10_adc8d8())->GetHeight() - 0x10;
        } else {
            limit = 0x400;
        }
        if (width > limit) {
            width = limit;
        }
    }
    cLBIf_ae2970* lbIf = reinterpret_cast<cLBIf_ae2970*>(reinterpret_cast<char*>(lb) + 0xd8);
    static_cast<cSelf_ae2970*>(lbIf->GetWindow())->Slot64(0x53430d99);
    cSelf_ae2970* w = static_cast<cSelf_ae2970*>(lbIf->GetWindow());
    int32_t bottom = area[3];
    int32_t left = area[0];
    w->SetArea4(left, bottom, width + left, bottom + self->GetWinHeight());
    w = static_cast<cSelf_ae2970*>(lbIf->GetWindow());
    w->SetFillColor1(self->GetFillColor());
    lbIf->SetFont(mpFont);
    if (mnColor[0] != 0xdeadbeef) {
        lbIf->SetColor(0, mnColor[0]);
    }
    if (mnColor[1] != 0xdeadbeef) {
        lbIf->SetColor(1, mnColor[1]);
    }
    if (mnColor[2] != 0xdeadbeef) {
        lbIf->SetColor(2, mnColor[2]);
    }
    lbIf->SetFlag(1);
    lbIf->SetPair(mnDropOutlineColor, mnDropOutlineColor);
    lbIf->SetValueA(mnHighlightColor);
    lbIf->SetAlpha(mfHighlightAlpha);
    lbIf->SetPair2(0, 0);
    lbIf->SetGutter(static_cast<uint8_t>(mnTextGutterX), static_cast<uint8_t>(mnTextGutterY));
    static_cast<cSelf_ae2970*>(lbIf->GetWindow())->Slot68b(0x10000, 0);
    for (Node_ae2970* n = static_cast<Node_ae2970*>(mpStrings)->next; n != mpStrings; n = n->next) {
        lbIf->AddString(&n->text[0], -2, 0);
    }
    static_cast<cSelf_ae2970*>(lbIf->GetWindow())->Slot68b(0x10000, 1);
    lbIf->SetSelection(mnSelection, 0);
    cIdx_ae2970* idx = static_cast<cIdx_ae2970*>(self->Slot6());
    Slot28_ae28c8(idx->IndexOf(lbIf->GetWindow()), 1);
    lb->Finish();
    lb->Release();
    mn12c = mnArrowW + mnArrowX;
    mbDropped = false;
    InvalidateSelfAndParents();
    return true;
}

// CLOSE: 0x009cf6ec score 27 (logic follows the asm)
bool cGZWinCombo::Slot24_ae28c8(uint32_t a)
{
    int32_t index = a;
    if (index <= mnStringCount - 1) {
        cList_ae2970* list = reinterpret_cast<cList_ae2970*>(&mpStrings);
        int32_t i = 0;
        if (index == 0) {
            list->PopFront();
            mnStringCount--;
            mbDirty = true;
            return true;
        }
        Node_ae2970* head = static_cast<Node_ae2970*>(mpStrings);
        for (Node_ae2970* n = head->next; n != head; n = n->next) {
            if (i == index) {
                Node_ae2970* result;
                list->Erase(&result, n);
                mnStringCount--;
                mbDirty = true;
                return true;
            }
            i++;
        }
    }
    return false;
}

// CLOSE: 0x009cf742 score 12 (logic follows the asm)
void cGZWinCombo::Slot26_ae28c8()
{
    Node_ae2970* result;
    cList_ae2970* list = reinterpret_cast<cList_ae2970*>(&mpStrings);
    list->EraseRange(&result, list->mpHead->next, list->mpHead);
    mnStringCount = 0;
    mnSelection = -1;
    mbDirty = true;
}

// CLOSE: 0x009cf8c7 score 18 (logic follows the asm)
bool cGZWinCombo::Slot28_ae28c8(uint32_t a, uint32_t b)
{
    int32_t index = a;
    if (index < 0 || index >= mnStringCount) {
        return false;
    }
    mnSelection = index;
    cTE_ae2970* te = OB_PTR(cTE_ae2970, get_text_edit());
    if (te) {
        Node_ae2970* node = static_cast<Node_ae2970*>(mpStrings)->next;
        for (int32_t i = index; i > 0; i--) {
            node = node->next;
        }
        cRZString s(*reinterpret_cast<const cRZString*>(node->text), 0, cRZString::npos);
        s.Trim();
        te->SetText(s.data(), s.size(), 0);
    }
    InvalidateSelfAndParents();
    if (static_cast<uint8_t>(b)) {
        reinterpret_cast<cSelf_ae2970*>(this)->SendNotify();
    }
    return true;
}

// CLOSE: 0x009cf975 score 43 (logic follows the asm)
bool cGZWinCombo::Slot27_ae28c8(uint32_t a, uint32_t b)
{
    int32_t pos = b;
    cList_ae2970* list = reinterpret_cast<cList_ae2970*>(&mpStrings);
    if (pos == 0) {
        cRZString s(*OB_PTR(cIGZString, a));
        list->PushFront(&s);
    } else if (pos < mnStringCount && pos != -2) {
        Node_ae2970* head = static_cast<Node_ae2970*>(mpStrings);
        Node_ae2970* n = head->next;
        int32_t i = 0;
        for (; n != head; n = n->next) {
            if (i == pos) {
                break;
            }
            i++;
        }
        if (n == head) {
            return false;
        }
        cRZString s(*OB_PTR(cIGZString, a));
        Node_ae2970* result;
        list->Insert(&result, n, &s);
    } else {
        cRZString s(*OB_PTR(cIGZString, a));
        list->PushBack(&s);
    }
    mnStringCount++;
    mbDirty = true;
    return true;
}
#endif
