#include "classes/cGZWinLineInput.h"
#include <algorithm>
#include "gzcom/cIGZString.h"

// This object seen through the primary vtable where a slot is called with a different argument list.
struct cSelf_ae0fb0 {
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
    virtual void D48();
    virtual void D49();
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
    virtual uint32_t GetSender();
    virtual void D64();
    virtual void D65();
    virtual void D66();
    virtual bool GetFlag(uint32_t which);
    virtual void D68();
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
    virtual void SetCursor1(uint32_t cursor);
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
    virtual void D106();
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
};

// The cursor manager, seen through the slot used.
struct cCursors_ae0fb0 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual uint32_t GetCursor(uint32_t kind, uint32_t flag);
};

// A font, seen through the slots used.
struct cFont_ae0fb0 {
    virtual void D0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
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
    virtual int32_t GetHeight(uint32_t a, uint32_t b);
    virtual void D38();
    virtual void D39();
    virtual void D40();
    virtual void D41();
    virtual uint32_t FitText(const char* text, uint32_t length, int32_t maxWidth, uint32_t flag);
    virtual void D43();
    virtual void D44();
    virtual void D45();
    virtual void D46();
    virtual void D47();
    virtual int32_t MeasureText(const char* text, uint32_t length);
    virtual void D49();
    virtual void D50();
    virtual void DrawText(uint32_t target, int32_t x, int32_t y, const char* text, uint32_t length, uint32_t color, uint32_t a, uint32_t b, uint32_t c);
};

// The interface base, seen through a slot the original calls without arguments.
struct cIf_ae0fb0 {
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
    virtual void Slot23();
};

// STUB: 0x00940da8
uint32_t Fn00940da8();

// STUB: 0x00913c72
void* WCM_ae0fb0();

// FUNCTION: 0x009c48c0
bool cGZWinLineInput::Slot26_ae0e80(uint32_t a)
{
    *OB_PTR(uint32_t, a) = mnCursor;
    return true;
}

// FUNCTION: 0x009c59b6
bool cGZWinLineInput::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x21335c59) {
        return cGZWin::QueryInterface(iid, ppv);
    }
    *ppv = static_cast<cUnk00ae0e80*>(this);
    AddRef();
    return true;
}

// FUNCTION: 0x009c5b35
bool cGZWinLineInput::Slot04_ae1d24()
{
    HideWindow();
    Slot04_ae0e80(0);
    return cGZWin::Slot04_ae1d24();
}

// FUNCTION: 0x009c5b55
uint32_t cGZWinLineInput::Slot68_adc8d8(uint32_t a, uint32_t b)
{
    if (a == 2) {
        if (*reinterpret_cast<bool*>(&b)) {
            if (mbEditable) {
                cCursors_ae0fb0* cm = static_cast<cCursors_ae0fb0*>(GetCursorManager_ae0fb0());
                reinterpret_cast<cSelf_ae0fb0*>(this)->SetCursor1(cm->GetCursor(3, 0));
            }
        } else {
            static_cast<cGZWin*>(Slot03_ae0e80())->SetCursor(0, 1);
        }
    }
    return cGZWin::Slot68_adc8d8(a, b);
}

// FUNCTION: 0x009c5bba
bool cGZWinLineInput::Slot04_ae0e80(uint32_t a)
{
    cFont_ae0fb0* font = OB_PTR(cFont_ae0fb0, a);
    if (font) {
        font->AddRef();
    }
    cFont_ae0fb0* old = static_cast<cFont_ae0fb0*>(mpFont);
    if (old) {
        old->Release();
    }
    mpFont = font;
    if (font) {
        mnFontHeight = font->GetHeight(0, 0);
    } else {
        mnFontHeight = 1;
    }
    return true;
}

// FUNCTION: 0x009c5c01
bool cGZWinLineInput::Slot06_ae0e80(uint32_t a)
{
    Slot05_ae0e80(0, a);
    return true;
}

// FUNCTION: 0x009c5c11
bool cGZWinLineInput::Slot05_ae0e80(uint32_t a, uint32_t b)
{
    if (static_cast<int32_t>(a) < 3) {
        uint32_t* p = &mnFontColor[a];
        bool changed = *p != b;
        *p = b;
        if (changed) {
            InvalidateSelfAndParents();
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x009c5c48
bool cGZWinLineInput::Slot07_ae0e80(uint32_t a, uint32_t b)
{
    if (static_cast<int32_t>(a) < 3) {
        uint32_t c = mnFontColor[a];
        if (c != 0xdeadbeef) {
            *OB_PTR(uint32_t, b) = c;
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x009c5c6b
void cGZWinLineInput::Slot08_ae0e80(uint32_t a)
{
    Slot05_ae0e80(a, 0xdeadbeef);
}

// FUNCTION: 0x009c5c7c
bool cGZWinLineInput::Slot09_ae0e80(uint32_t a)
{
    mbFilled = *reinterpret_cast<bool*>(&a);
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009c5c9a
void cGZWinLineInput::Slot16_ae0e80(uint32_t a)
{
    if (*reinterpret_cast<bool*>(&a)) {
        Slot11_ae0e80(1);
    } else {
        Slot11_ae0e80(0);
    }
}

// FUNCTION: 0x009c5caf
void cGZWinLineInput::Slot13_ae0e80(uint32_t a)
{
    Slot14_ae0e80(0, a);
}

// FUNCTION: 0x009c5cc9
bool cGZWinLineInput::Slot14_ae0e80(uint32_t a, uint32_t b)
{
    uint32_t c = ConvertNativeToPackedRGB(b);
    if (static_cast<int32_t>(a) < 4) {
        uint32_t* p = &mnOutlineColor[a];
        bool changed = *p != c;
        *p = c;
        if (changed) {
            InvalidateSelfAndParents();
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x009c5d0e
bool cGZWinLineInput::Slot15_ae0e80(uint32_t a, uint32_t b)
{
    if (static_cast<int32_t>(a) < 4) {
        *OB_PTR(uint32_t, b) = ConvertPackedRGBToNative(mnOutlineColor[a]);
        return true;
    }
    return false;
}

// FUNCTION: 0x009c5d3c
bool cGZWinLineInput::Slot17_ae0e80(uint32_t a)
{
    mnHighlightFill = ConvertNativeToPackedRGB(a);
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009c5d68
bool cGZWinLineInput::Slot18_ae0e80(uint32_t a)
{
    *OB_PTR(uint32_t, a) = ConvertPackedRGBToNative(mnHighlightFill);
    return true;
}

// FUNCTION: 0x009c5d86
bool cGZWinLineInput::Slot19_ae0e80(uint32_t a)
{
    mfHighlightAlpha = *reinterpret_cast<float*>(&a);
    if (mfHighlightAlpha < 0.0f) {
        mfHighlightAlpha = 0.0f;
    }
    if (mfHighlightAlpha > 1.0f) {
        mfHighlightAlpha = 1.0f;
    }
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009c5dc7
bool cGZWinLineInput::Slot20_ae0e80(uint32_t a)
{
    *OB_PTR(float, a) = mfHighlightAlpha;
    return true;
}

// FUNCTION: 0x009c5dd5
bool cGZWinLineInput::GZOnSetFocus(uint32_t)
{
    if (mbEditable) {
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}

// FUNCTION: 0x009c5def
bool cGZWinLineInput::GZOnKillFocus(uint32_t)
{
    InvalidateSelfAndParents();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c5dfc score 9 (logic matches; register choice/order differ)
void cGZWinLineInput::Slot24_ae0e80()
{
    reinterpret_cast<cIf_ae0fb0*>(static_cast<cUnk00ae0e80*>(this))->Slot23();
}
#endif

// FUNCTION: 0x009c5e05
bool cGZWinLineInput::Slot28_ae0e80(uint32_t a)
{
    mbEditable = *reinterpret_cast<bool*>(&a);
    if (mbEditable) {
        cCursors_ae0fb0* cm = static_cast<cCursors_ae0fb0*>(GetCursorManager_ae0fb0());
        reinterpret_cast<cSelf_ae0fb0*>(this)->SetCursor1(cm->GetCursor(3, 0));
    } else {
        SetCursor(0, 1);
    }
    return true;
}

// FUNCTION: 0x009c5e5c
bool cGZWinLineInput::Slot30_ae0e80(uint32_t a)
{
    *OB_PTR(uint32_t, a) = mnCharLimit;
    return true;
}

// FUNCTION: 0x009c5e6a
bool cGZWinLineInput::Slot32_ae0e80(uint32_t a, uint32_t b)
{
    *OB_PTR(uint32_t, a) = mnSelStart;
    *OB_PTR(uint32_t, b) = mnSelEnd - mnSelStart;
    return true;
}

// FUNCTION: 0x009c5e84
bool cGZWinLineInput::Slot33_ae0e80(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    mnGutter[0] = static_cast<int8_t>(a);
    mnGutter[1] = static_cast<int8_t>(b);
    mnGutter[2] = static_cast<int8_t>(c);
    mnGutter[3] = static_cast<int8_t>(d);
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009c5eb3
bool cGZWinLineInput::Slot34_ae0e80(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(int8_t, a) = mnGutter[0];
    *OB_PTR(int8_t, b) = mnGutter[1];
    *OB_PTR(int8_t, c) = mnGutter[2];
    *OB_PTR(int8_t, d) = mnGutter[3];
    return true;
}

// FUNCTION: 0x009c5edc
bool cGZWinLineInput::Slot35_ae0e80(uint32_t a)
{
    int32_t border;
    if (mnOutlineStyle > 0) {
        if (mnOutlineStyle > 2) {
            if (mnOutlineStyle != 3) {
                border = 0;
            } else {
                border = 2;
            }
        } else {
            border = 1;
        }
    } else {
        border = 0;
    }
    int32_t* r = OB_PTR(int32_t, a);
    r[0] = mnGutter[0] + mnGutter[2] + border * 2;
    r[1] = mnGutter[3] + mnGutter[1] + mnFontHeight + border * 2;
    r[2] = 0x7fffffff;
    r[3] = 0x7fffffff;
    return true;
}

// FUNCTION: 0x009c5f34
bool cGZWinLineInput::Slot36_ae0e80(uint32_t a, uint32_t b)
{
    if (static_cast<int32_t>(a) < 3) {
        mnSoundID[a] = b;
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c62c9 score 9 (logic matches; register choice/order differ)
bool cGZWinLineInput::Slot25_ae0e80(uint32_t a)
{
    uint32_t n = mText.size();
    if (a > n) {
        n = mText.size();
        mnCursor = n;
        mnSelStart = n;
        mnSelEnd = n;
    }
    return true;
}
#endif

// FUNCTION: 0x009c62eb
uint32_t cGZWinLineInput::Slot21_ae0e80(uint32_t a)
{
    reinterpret_cast<cIGZString*>(a)->Copy(mText);
    return mText.size();
}


// A queried interface.
struct cIface_ae0fb0 {
    virtual bool QueryInterface(uint32_t iid, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

// A 16-byte rectangle.
struct Rect_ae0fb0 {
    int32_t v[4];
};

// The draw context of the window.
struct cDrawContext_ae0fb0 {
    virtual void C0();
};

// STUB: 0x008d9470
void RZDraw3DRectangleOutline_ae0fb0(cDrawContext_ae0fb0* context, const Rect_ae0fb0* area, uint32_t colorA, uint32_t colorB);

// STUB: 0x008d9360
void RZDrawRectangleOutline_ae0fb0(cDrawContext_ae0fb0* context, const Rect_ae0fb0* area, uint32_t color, uint32_t width);

// STUB: 0x009106a9
int32_t RZCharacterSize_ae0fb0(const char* text, int32_t length, int32_t codePage);

// ---- batch 2 ----

// FUNCTION: 0x009c5f4e
void cGZWinLineInput::send_line_input_completed_msg()
{
    reinterpret_cast<cSelf_ae0fb0*>(this)->SendMsg5(field4c, 3, 0xa8711130, reinterpret_cast<cSelf_ae0fb0*>(this)->GetSender(), 0);
}

// FUNCTION: 0x009c5f72
void cGZWinLineInput::send_line_input_changed_msg()
{
    reinterpret_cast<cSelf_ae0fb0*>(this)->SendMsg5(field4c, 3, 0xa871112f, reinterpret_cast<cSelf_ae0fb0*>(this)->GetSender(), 0);
}

// FUNCTION: 0x009c5f96
void cGZWinLineInput::Slot07_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    int32_t w = c - a;
    int32_t h = d - b;
    int32_t r[4];
    Slot35_ae0e80(OB_ADDR(r));
    if (w < r[0]) {
        w = r[0];
    }
    if (h < r[1]) {
        h = r[1];
    }
    cGZWin::Slot07_add348(a, b, a + w, b + h);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c5feb score 50 (logic matches; register choice/order differ)
void cGZWinLineInput::paint_outline()
{
    cDrawContext_ae0fb0* ctx = OB_PTR(cDrawContext_ae0fb0, field6c);
    const Rect_ae0fb0* area = reinterpret_cast<const Rect_ae0fb0*>(&field24[0]);
    if (mnOutlineStyle == 2) {
        RZDraw3DRectangleOutline_ae0fb0(ctx, area, mnOutlineColor[0], mnOutlineColor[1]);
    } else if (mnOutlineStyle == 3) {
        Rect_ae0fb0 r = *area;
        RZDraw3DRectangleOutline_ae0fb0(ctx, &r, mnOutlineColor[0], mnOutlineColor[1]);
        r.v[0]++;
        r.v[2]--;
        r.v[1]++;
        r.v[3]--;
        RZDraw3DRectangleOutline_ae0fb0(ctx, &r, mnOutlineColor[2], mnOutlineColor[3]);
    } else if (mnOutlineStyle == 1) {
        RZDrawRectangleOutline_ae0fb0(ctx, area, ConvertNativeToPackedRGB(mnOutlineColor[0]), 1);
    }
}
#endif


#ifdef OB_DRAFTS
// CLOSE: 0x009c610b score 58 (logic matches; register choice/order differ)
uint32_t cGZWinLineInput::FindTextIndexFromCursorLocation(int32_t x)
{
    int32_t gutter = mnGutter[0];
    uint32_t start = mnEC;
    int32_t remaining = mText.size() - start;
    int32_t target = x - gutter;
    int32_t prev = 0;
    int32_t consumed = 0;
    int32_t last = 0;
    if (target > 0) {
        if (remaining > 0) {
            do {
                int32_t width = static_cast<cFont_ae0fb0*>(mpFont)->MeasureText(mText.data() + mnEC, consumed);
                if (width > target) {
                    if (width - target < target - prev) {
                        return mnEC + consumed;
                    }
                    return mnEC - last + consumed;
                }
                prev = width;
                last = RZCharacterSize_ae0fb0(mText.data() + mnEC + consumed, mText.size() - mnEC - consumed, mnDC);
                consumed += last;
            } while (consumed < remaining);
            return mText.size();
        }
        return mText.size();
    }
    return start;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c61d1 score 82 (logic matches; register choice/order differ)
bool cGZWinLineInput::UpdateViewLocation()
{
    if (mText.begin() == mText.end()) {
        mnCursor = 0;
        mnEC = 0;
        return true;
    }
    if (mnCursor <= mnEC) {
        int32_t cursor = mnCursor;
        int32_t last = mText.size() - 1;
        mnEC = last < cursor ? last : cursor;
        return true;
    }
    int32_t usable = reinterpret_cast<const int32_t*>(&field24[0])[2] - mnGutter[2] - mnGutter[0] - reinterpret_cast<const int32_t*>(&field24[0])[0];
    int32_t w = static_cast<cFont_ae0fb0*>(mpFont)->MeasureText(mText.data() + mnEC, mnCursor - mnEC);
    while (w > usable) {
        mnEC += RZCharacterSize_ae0fb0(mText.data() + mnEC, mText.size() - mnEC, mnDC);
        w = static_cast<cFont_ae0fb0*>(mpFont)->MeasureText(mText.data() + mnEC, mnCursor - mnEC);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c636a score 2 (logic matches; register choice/order differ)
bool cGZWinLineInput::GZOnMouseDownL(uint32_t a, uint32_t b, uint32_t c)
{
    bool result;
    if (!mbEditable) {
        cIface_ae0fb0* p;
        result = true;
        if (OB_PTR(cIface_ae0fb0, field48)->QueryInterface(0x412ce496, reinterpret_cast<void**>(&p))) {
            result = reinterpret_cast<cSelf_ae0fb0*>(this)->SendMsg5(field4c, 7, a, b, c);
            p->Release();
        }
        return result;
    }
    if (!GZSetCapture_ae0fb0()) {
        return false;
    }
    uint32_t cur;
    if (c & 1) {
        cur = FindTextIndexFromCursorLocation(a);
        mnCursor = cur;
    } else {
        Slot25_ae0e80(FindTextIndexFromCursorLocation(a));
        cur = mnCursor;
        mnSelStart = cur;
    }
    mnSelEnd = cur;
    UpdateViewLocation();
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c641d score 2 (logic matches; register choice/order differ)
bool cGZWinLineInput::GZOnMouseUpL(uint32_t a, uint32_t, uint32_t)
{
    if (!GZAmCapturing()) {
        return false;
    }
    GZReleaseCapture();
    mnSelEnd = FindTextIndexFromCursorLocation(a);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c6447 score 6 (logic matches; register choice/order differ)
bool cGZWinLineInput::GZOnMouseMove(uint32_t a, uint32_t, uint32_t)
{
    if (!GZAmCapturing()) {
        return false;
    }
    uint32_t i = FindTextIndexFromCursorLocation(a);
    if (mnSelEnd == i) {
        return false;
    }
    mnSelEnd = i;
    InvalidateSelfAndParents();
    return true;
}
#endif

// FUNCTION: 0x009c647a
bool cGZWinLineInput::DeleteChar(uint32_t a, uint32_t b)
{
    if (a > 0 && a <= mText.size() && b > 0) {
        mText.erase(a - 1, b);
        send_line_input_changed_msg();
        return true;
    }
    return false;
}

// FUNCTION: 0x009c69e0
void cGZWinLineInput::draw_text(int32_t x, int32_t y, int32_t start, int32_t length, uint32_t colorIdx)
{
    uint32_t color = mnFontColor[colorIdx];
    if (color != 0xdeadbeef) {
        cRZString tmp(mText.data() + start, length);
        static_cast<cFont_ae0fb0*>(mpFont)->DrawText(field68, x, y, tmp.data(), tmp.size(), color, 0x8000000, 0, 0);
    } else {
        static_cast<cFont_ae0fb0*>(mpFont)->DrawText(field68, x, y, mText.data() + start, length, 0x8000000, 0x8000000, 0, 0);
    }
}

// FUNCTION: 0x009c6a7e
bool cGZWinLineInput::Slot22_ae0e80(uint32_t a)
{
    cRZString tmp(OB_PTR(const char, a));
    bool r = Slot23_ae0e80(OB_ADDR(&tmp));
    return r;
}

// FUNCTION: 0x009c6f14
bool cGZWinLineInput::InsertChar(uint32_t a, uint32_t b)
{
    if (mText.size() < mnCharLimit) {
        mText.insert(b, 1, static_cast<char>(a));
        send_line_input_changed_msg();
        return true;
    }
    Slot37_ae0e80(1);
    return false;
}

// FUNCTION: 0x009c701e
bool cGZWinLineInput::Slot23_ae0e80(uint32_t a)
{
    if (a) {
        static_cast<cIGZString*>(&mText)->Copy(*OB_PTR(cIGZString, a));
        uint32_t n = mnCharLimit;
        if (mText.size() > n) {
            mText.resize(n, 0);
        }
    } else {
        mText.erase(0, std::string::npos);
    }
    if (!mbSending) {
        mbSending = true;
        send_line_input_changed_msg();
        mbSending = false;
    }
    mnCursor = 0;
    mnSelStart = 0;
    mnSelEnd = 0;
    mnEC = 0;
    mbSending = false;
    InvalidateSelfAndParents();
    return true;
}

// ---- batch 3 ----

// The window-manager-like object the first-time setup asks for fonts and colors.
struct cResources_ae0fb0 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void* GetFont(uint32_t id);
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

// The sound system.
struct cSounds_ae0fb0 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual bool Play(void* sound);
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual bool Create(uint32_t kind, uint32_t iid, cIface_ae0fb0** out, uint32_t id, uint32_t a, uint32_t b, uint32_t c);
};

// STUB: 0x00913c9e
cSounds_ae0fb0* SS_ae0fb0();

// STUB: 0x009f58e2
int32_t abs_ae0fb0(int32_t value);

// FUNCTION: 0x009c59e3
bool cGZWinLineInput::Slot03_ae1d24()
{
    if (get_init_flag()) {
        return true;
    }
    mnEC = 0;
    cResources_ae0fb0* res = static_cast<cResources_ae0fb0*>(WCM_ae0fb0());
    if (res) {
        if (!mpFont) {
            Slot04_ae0e80(OB_ADDR(res->GetFont(0x68963c4c)));
        }
        if (mnFontColor[1] == 0xdeadbeef) {
            Slot05_ae0e80(1, res->GetColor(0x08963fb9));
        }
        if (mnFontColor[2] == 0xdeadbeef) {
            Slot05_ae0e80(2, res->GetColor(0x28963fbc));
        }
        if (reinterpret_cast<cSelf_ae0fb0*>(this)->GetFillColor() == 0xdeadbeef) {
            Slot08_ae1a28(res->GetColor(0xa8963fb2));
        }
        if (mnHighlightFill == 0xdeadbeef) {
            Slot17_ae0e80(res->GetColor(0x88963fb4));
        }
    }
    if (mbEditable) {
        cCursors_ae0fb0* cm = static_cast<cCursors_ae0fb0*>(GetCursorManager_ae0fb0());
        reinterpret_cast<cSelf_ae0fb0*>(this)->SetCursor1(cm->GetCursor(3, 0));
    }
    mnDC = Fn00940da8();
    SetSize_2(GetW(), GetH());
    return cGZWin::Slot03_ae1d24();
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c6096 score 4 (logic matches; register choice/order differ)
bool cGZWinLineInput::Slot37_ae0e80(uint32_t a)
{
    int32_t* id = &mnSoundID[a];
    if (*id != 0) {
        cSounds_ae0fb0* sys = SS_ae0fb0();
        if (sys) {
            cIface_ae0fb0* out = 0;
            if (sys->Create(5, 0x5b523ba4, &out, *id, 0, 0, 0)) {
                if (out) {
                    bool r = sys->Play(out);
                    if (out) {
                        out->Release();
                    }
                    return r;
                }
            } else if (out) {
                out->Release();
            }
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c6305 score 2 (logic matches; register choice/order differ)
bool cGZWinLineInput::Slot31_ae0e80(uint32_t a, uint32_t b)
{
    uint32_t start = a;
    if (start >= mText.size()) {
        if (mText.size() != 0) {
            start = mText.size() - 1;
        } else {
            start = 0;
        }
    }
    uint32_t len = b;
    if (start + len > mText.size()) {
        len = mText.size() - start;
    }
    mnSelStart = start;
    uint32_t end = start + len;
    mnSelEnd = end;
    mnCursor = end;
    UpdateViewLocation();
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c6f5a score 10 (logic matches; register choice/order differ)
bool cGZWinLineInput::GZOnCharacter(uint32_t a)
{
    if (mbEditable) {
        if (static_cast<uint8_t>(a) >= 0x20) {
            if (mnCharLimit != 0xffffffff) {
                uint32_t n = mText.size();
                if (mnSelStart != mnSelEnd) {
                    n -= abs_ae0fb0(mnSelEnd - mnSelStart);
                }
                if (n >= mnCharLimit) {
                    Slot37_ae0e80(1);
                    return false;
                }
            }
            if (mnSelStart != mnSelEnd) {
                GZOnKeyDown(8, 0);
            }
            InsertChar(static_cast<char>(a), mnCursor);
            mnCursor++;
            uint32_t cur = mnCursor;
            mnSelStart = cur;
            mnSelEnd = cur;
            UpdateViewLocation();
            InvalidateSelfAndParents();
            return true;
        }
        Slot37_ae0e80(0);
        return false;
    }
    return false;
}
#endif

// ---- batch 4 ----

// The draw context (field6c), seen through the slots used.
struct cDC_ae0fb0 {
    virtual void X0();
    virtual void X1();
    virtual void X2();
    virtual void X3();
    virtual void X4();
    virtual void X5();
    virtual void X6();
    virtual void X7();
    virtual void X8();
    virtual void X9();
    virtual void X10();
    virtual void X11();
    virtual void X12();
    virtual void X13();
    virtual void X14();
    virtual void X15();
    virtual void X16();
    virtual void X17();
    virtual void X18();
    virtual void X19();
    virtual void X20();
    virtual void SetColor(uint32_t color);
    virtual void X22();
    virtual void X23();
    virtual void X24();
    virtual void SetLineWidth(float width);
    virtual void X26();
    virtual void X27();
    virtual void X28();
    virtual void X29();
    virtual void X30();
    virtual void X31();
    virtual void X32();
    virtual void X33();
    virtual void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
    virtual void FillRect(const int32_t* rect);
};

// STUB: 0x0091073c
uint32_t GetPreviousCharLength_ae0fb0(const void* text, uint32_t position, int32_t codePage);

#ifdef OB_DRAFTS
// CLOSE: 0x009c64b7 score 174 (logic follows the asm; shared tails as gotos)
bool cGZWinLineInput::GZOnKeyDown(uint32_t a, uint32_t b)
{
    bool shift = (b & 1) != 0;
    bool changed = false;
    switch (a) {
    case 9:
    case 0x1b:
        return reinterpret_cast<cSelf_ae0fb0*>(this)->SendMsg5(field4c, 5, a, b, 0);
    case 0xd:
        if (mbEditable) {
            send_line_input_completed_msg();
        }
        if (mnSelStart == mnSelEnd) {
            return true;
        }
        mnSelStart = mnCursor;
        mnSelEnd = mnCursor;
        goto update;
    case 8:
        if (mnSelStart == mnSelEnd) {
            if (mnCursor != 0 && mbEditable) {
                uint32_t prev = GetPreviousCharLength_ae0fb0(mText.data(), mnCursor, mnDC);
                DeleteChar(mnCursor - prev, prev);
                mnCursor -= prev;
                mnSelStart = mnCursor;
                mnSelEnd = mnCursor;
                changed = true;
                if (mnEC == mnCursor) {
                    int32_t zero = 0;
                    int32_t v = mnEC - 10;
                    mnEC = *(v < 0 ? &zero : &v);
                }
            }
            if (mnSelStart != mnSelEnd) {
                mnSelStart = mnCursor;
                goto selEndAndChanged;
            }
            goto tail;
        }
        goto rangeDelete;
    case 0x2e:
        if (mnSelStart == mnSelEnd) {
            if (mbEditable && mText.size() != 0) {
                uint32_t n = RZCharacterSize_ae0fb0(mText.data() + mnCursor, mText.size() - mnCursor, mnDC);
                DeleteChar(mnCursor + 1, n);
                changed = true;
            }
            if (mnSelStart != mnSelEnd) {
                mnSelStart = mnCursor;
                goto selEndAndChanged;
            }
            goto tail;
        }
    rangeDelete:
        {
            int32_t lo = std::min(mnSelStart, mnSelEnd);
            int32_t hi = std::max(mnSelStart, mnSelEnd);
            if (mbEditable) {
                DeleteChar(lo + 1, hi - lo);
            }
            Slot25_ae0e80(lo);
        }
    selEndAndChanged:
        changed = true;
    tail:
        if (!changed) {
            return true;
        }
        goto updateView;
    case 0x23:
        if (mnCursor == mText.size()) {
            return true;
        }
        mnCursor = mText.size();
        mnSelStart = mnCursor;
        mnSelEnd = mnCursor;
        goto update;
    case 0x24:
        if (mnCursor == 0) {
            return true;
        }
        mnCursor = 0;
        mnSelStart = 0;
        mnSelEnd = 0;
        changed = true;
    updateView:
        UpdateViewLocation();
        if (!changed) {
            return true;
        }
        break;
    case 0x25:
        if (mnCursor > 0) {
            uint32_t n = GetPreviousCharLength_ae0fb0(mText.data(), mnCursor, mnDC);
            if (shift) {
                if (mnCursor > 0) {
                    mnCursor -= n;
                }
                if (static_cast<int32_t>(mnSelEnd) > 0) {
                    mnSelEnd -= n;
                }
            } else {
                Slot25_ae0e80(mnCursor - n);
                mnSelStart = mnCursor;
                mnSelEnd = mnCursor;
            }
        } else {
            if (shift) {
                return true;
            }
            Slot25_ae0e80(0);
            mnSelStart = 0;
            mnSelEnd = 0;
        }
        goto update;
    case 0x27:
        if (mnCursor < mText.size()) {
            uint32_t n = RZCharacterSize_ae0fb0(mText.data() + mnCursor, mText.size() - mnCursor, mnDC);
            if (shift) {
                if (mnCursor < mText.size()) {
                    mnCursor += n;
                }
                int32_t end = mText.size();
                if (static_cast<int32_t>(mnSelEnd) < end) {
                    mnSelEnd += n;
                }
            } else {
                Slot25_ae0e80(mnCursor + n);
                mnSelStart = mnCursor;
                mnSelEnd = mnCursor;
            }
        } else {
            if (shift) {
                return true;
            }
            Slot25_ae0e80(mText.size());
            mnSelStart = mText.size();
            mnSelEnd = mText.size();
        }
        goto update;
    default:
        return true;
    update:
        UpdateViewLocation();
        break;
    }
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c6b03 score 431 (logic follows the asm)
bool cGZWinLineInput::GZPaint()
{
    cDC_ae0fb0* dc = OB_PTR(cDC_ae0fb0, field6c);
    const int32_t* area = reinterpret_cast<const int32_t*>(&field24[0]);
    if (mbFilled) {
        dc->SetColor(GetFillColorRGB());
        dc->FillRect(area);
    }
    if (!mpFont) {
        return false;
    }
    int32_t left = mnGutter[0] + area[0];
    int32_t top = mnGutter[1] + area[1];
    int32_t right = area[2] - mnGutter[2];
    int32_t bottom = area[3] - mnGutter[3];
    int32_t y = (bottom - top - mnFontHeight) / 2 + top;
    cFont_ae0fb0* font = static_cast<cFont_ae0fb0*>(mpFont);
    if (Fn0099bdf3() == this) {
        if (mnSelStart == mnSelEnd) {
            if (mText.size() != 0) {
                uint32_t n = font->FitText(mText.data() + mnEC, mText.size() - mnEC, right - left, 0);
                draw_text(left, y, mnEC, n, reinterpret_cast<cSelf_ae0fb0*>(this)->GetFlag(2) ? 0 : 1);
            }
            if (mbEditable && mnCursor >= mnEC) {
                uint32_t w = (mnFontHeight >= 0x18) + 1;
                int32_t x = left;
                if (mnCursor != 0) {
                    x = font->MeasureText(mText.data() + mnEC, mnCursor - mnEC) + (x - (w >> 1)) - 1;
                }
                dc->SetColor(0xff000000);
                dc->SetLineWidth(static_cast<float>(w));
                dc->DrawLine(x, y + w, x, y - w + mnFontHeight);
                dc->SetLineWidth(1.0f);
            }
        } else {
            uint32_t n = font->FitText(mText.data() + mnEC, mText.size() - mnEC, right - left, 0);
            int32_t zero = 0;
            int32_t selLo = std::min(mnSelStart, mnSelEnd);
            int32_t s = std::max(std::max(selLo, zero), static_cast<int32_t>(mnEC));
            int32_t selHi = std::max(mnSelStart, mnSelEnd);
            int32_t len = mText.size();
            int32_t e = std::min(std::min(selHi, len), static_cast<int32_t>(mnEC + n));
            int32_t x0 = 0;
            if (s != 0) {
                x0 = font->MeasureText(mText.data(), s);
            }
            int32_t xe = font->MeasureText(mText.data(), e);
            if (mnEC != 0) {
                int32_t m = font->MeasureText(mText.data(), mnEC);
                x0 -= m;
                xe -= m;
            }
            if (mfHighlightAlpha != 0.0) {
                int32_t r[4];
                r[0] = x0 + left;
                r[1] = top;
                r[2] = xe + left;
                r[3] = bottom;
                if (mfHighlightAlpha == 1.0) {
                    dc->SetColor(mnHighlightFill);
                    dc->FillRect(r);
                }
            }
            if (n > 0) {
                draw_text(left, y, mnEC, n, 0);
            }
            int32_t cnt = e - s;
            if (cnt > 0) {
                draw_text(x0 + left, y, s, cnt, 2);
            }
        }
    } else if (mText.size() != 0) {
        uint32_t n = font->FitText(mText.data() + mnEC, mText.size() - mnEC, right - left, 0);
        if (n != 0) {
            draw_text(left, y, mnEC, n, reinterpret_cast<cSelf_ae0fb0*>(this)->GetFlag(2) ? 0 : 1);
        }
    }
    if (mnOutlineStyle != 0) {
        paint_outline();
    }
    return true;
}
#endif
