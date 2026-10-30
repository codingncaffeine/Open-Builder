#include "classes/cUnk00addd50.h"

// The component manager the accessor 0x00913c72 gives; slot 5 finds a font by its id.
struct cWCM_addd50 {
    virtual void W0();
    virtual void W1();
    virtual void W2();
    virtual void W3();
    virtual void W4();
    virtual void* GetFont(uint32_t id);
    virtual void W6();
    virtual void* GetClass(uint32_t id);
    virtual void W8();
    virtual void W9();
    virtual void W10();
    virtual void W11();
    virtual void W12();
    virtual void W13();
    virtual void W14();
    virtual void W15();
    virtual void W16();
    virtual void W17();
    virtual void W18();
    virtual void W19();
    virtual void W20();
    virtual void W21();
    virtual void W22();
    virtual void W23();
    virtual void W24();
    virtual void W25();
    virtual void W26();
    virtual void W27();
    virtual void W28();
    virtual uint32_t GetSound(uint32_t index);
};


// The framework window seen through its vtable, for the slots whose return type the base header lacks.
struct WinView_addd50 {
    virtual void W0();
    virtual void W1();
    virtual void W2();
    virtual void W3();
    virtual void W4();
    virtual void W5();
    virtual void W6();
    virtual void W7();
    virtual void W8();
    virtual void W9();
    virtual void W10();
    virtual void W11();
    virtual void W12();
    virtual void W13();
    virtual void W14();
    virtual void W15();
    virtual void W16();
    virtual void W17();
    virtual void W18();
    virtual void W19();
    virtual void W20();
    virtual void W21();
    virtual void W22();
    virtual void W23();
    virtual void W24();
    virtual void W25();
    virtual void W26();
    virtual void W27();
    virtual void W28();
    virtual void W29();
    virtual void W30();
    virtual void W31();
    virtual void W32();
    virtual void W33();
    virtual void W34();
    virtual void W35();
    virtual void W36();
    virtual void W37();
    virtual void W38();
    virtual void W39();
    virtual void W40();
    virtual void W41();
    virtual void W42();
    virtual void W43();
    virtual void W44();
    virtual void W45();
    virtual void W46();
    virtual void W47();
    virtual void W48();
    virtual void W49();
    virtual void W50();
    virtual void W51();
    virtual void W52();
    virtual void W53();
    virtual void W54();
    virtual void W55();
    virtual void W56();
    virtual void W57();
    virtual void W58();
    virtual void W59();
    virtual void W60();
    virtual void W61();
    virtual void W62();
    virtual void W63();
    virtual void W64();
    virtual void W65();
    virtual void W66();
    virtual void W67();
    virtual void W68();
    virtual void W69();
    virtual void W70();
    virtual void W71();
    virtual void W72();
    virtual void W73();
    virtual void W74();
    virtual void W75();
    virtual void W76();
    virtual void W77();
    virtual void W78();
    virtual void W79();
    virtual void W80();
    virtual void W81();
    virtual void W82();
    virtual void W83();
    virtual void W84();
    virtual void W85();
    virtual void W86();
    virtual void W87();
    virtual void W88();
    virtual void W89();
    virtual void W90();
    virtual void W91();
    virtual void W92();
    virtual void W93();
    virtual void W94();
    virtual void W95();
    virtual void W96();
    virtual void W97();
    virtual void W98();
    virtual void W99();
    virtual void W100();
    virtual void W101();
    virtual void W102();
    virtual void W103();
    virtual void W104();
    virtual void W105();
    virtual void W106();
    virtual void W107();
    virtual void W108();
    virtual void W109();
    virtual void W110();
    virtual void W111();
    virtual void W112();
    virtual void W113();
    virtual void W114();
    virtual void W115();
    virtual void W116();
    virtual void W117();
    virtual void W118();
    virtual void W119();
    virtual void W120();
    virtual void W121();
    virtual void W122();
    virtual void W123();
    virtual void W124();
    virtual void W125();
    virtual void W126();
    virtual void W127();
    virtual void W128();
    virtual void W129();
    virtual void W130();
    virtual void W131();
    virtual void W132();
    virtual void W133();
    virtual void W134();
    virtual void W135();
    virtual void W136();
    virtual void W137();
    virtual void W138();
    virtual void W139();
    virtual void W140();
    virtual void W141();
    virtual void W142();
    virtual void W143();
    virtual bool SendMsg(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
};

// The font object seen through its vtable: the slots used.
struct Font_addd50 {
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8();
    virtual void F9();
    virtual void F10();
    virtual void F11();
    virtual uint32_t Slot12();
    virtual uint32_t Slot13();
    virtual void F14();
    virtual void F15();
    virtual void F16();
    virtual void F17();
    virtual void F18();
    virtual void F19();
    virtual void F20();
    virtual void F21();
    virtual void F22();
    virtual void F23();
    virtual void F24();
    virtual void F25();
    virtual void F26();
    virtual void F27();
    virtual void F28();
    virtual void F29();
    virtual void F30();
    virtual void F31();
    virtual void F32();
    virtual void F33();
    virtual void F34();
    virtual void F35();
    virtual void F36();
    virtual uint32_t Slot37(uint32_t a, uint32_t b);
    virtual void F38();
    virtual void F39();
    virtual void F40();
    virtual void F41();
    virtual void F42();
    virtual uint32_t Slot43(uint32_t a, uint32_t b, uint32_t c);
    virtual uint32_t Slot44(uint32_t a, uint32_t b, uint32_t c);
    virtual void F45();
    virtual void F46();
    virtual uint32_t Slot47(uint32_t a, uint32_t b, void* rect);
};

// A 16-byte record copied as a whole.
struct Quad_addd50 {
    int32_t v[4];
};

// STUB: 0x00913c72
cWCM_addd50* Fn00913c72();

// The button seen through its first vtable, for slots whose argument count the base header lacks.
struct Self_addd50 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void SetFlag(uint32_t mask, uint32_t on);
};

// FUNCTION: 0x009affd3
bool cUnk00addd50::QueryInterface(uint32_t iid, void** out)
{
    if (iid == 0x8810) {
        *reinterpret_cast<cUnk00addd50**>(out) = this;
        AddRef();
        return true;
    }
    return cGZWin::QueryInterface(iid, reinterpret_cast<void**>(out));
}

// FUNCTION: 0x009b048d
uint32_t cUnk00addd50::Slot08_adda20()
{
    return mnBtnFlags & 1;
}

// FUNCTION: 0x009b1bc2
void cUnk00addd50::Slot06_adda20()
{
    set_btn_flag(1, 1);
}

// FUNCTION: 0x009b1bcc
void cUnk00addd50::Slot07_adda20()
{
    set_btn_flag(1, 0);
}

// FUNCTION: 0x009b1bd6
void cUnk00addd50::Slot09_adda20(uint32_t on)
{
    set_btn_flag(1, on);
}

// FUNCTION: 0x009b0568
uint32_t cUnk00addd50::Slot15_adda20()
{
    return mnRect[3] - mnRect[1];
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b0559 score 3
uint32_t cUnk00addd50::Slot14_adda20()
{
    return mnRect[2] - mnRect[0];
}
#endif

// FUNCTION: 0x009b0303
uint32_t cUnk00addd50::Slot46_adda20(uint32_t index)
{
    return mnSounds[index];
}

// FUNCTION: 0x009b02ef
bool cUnk00addd50::Slot45_adda20(uint32_t index, uint32_t value)
{
    mnSounds[index] = value;
    return true;
}

// FUNCTION: 0x009b0034
bool cUnk00addd50::Slot28_adda20(uint32_t out)
{
    *OB_PTR(uint32_t, out) = mnAlign;
    return true;
}

// FUNCTION: 0x009b0252
bool cUnk00addd50::Slot39_adda20(uint32_t out)
{
    *OB_PTR(uint32_t, out) = mn174;
    return true;
}

// FUNCTION: 0x009b10bf
bool cUnk00addd50::Slot18_adda20(uint32_t out)
{
    *OB_PTR(uint32_t, out) = mpBitmap;
    return true;
}

// FUNCTION: 0x009b01cc
bool cUnk00addd50::Slot26_adda20(uint32_t a)
{
    Slot23_adda20(a, 0x8000000);
    return true;
}

// FUNCTION: 0x009b022d
bool cUnk00addd50::Slot36_adda20(uint32_t out)
{
    OB_PTR(cIGZString, out)->Copy(mText);
    return true;
}

// FUNCTION: 0x009b005e
bool cUnk00addd50::Slot16_adda20(uint32_t out)
{
    *OB_PTR(Quad_addd50, out) = *reinterpret_cast<Quad_addd50*>(mnRect);
    return true;
}

// FUNCTION: 0x009b0075
void cUnk00addd50::Slot30_adda20(uint32_t a, uint32_t b)
{
    Slot29_adda20(a, b, a, b);
}

// FUNCTION: 0x009b0045
bool cUnk00addd50::Slot21_adda20(uint32_t out)
{
    if (mnFontId) {
        *OB_PTR(uint32_t, out) = mnFontId;
        return true;
    }
    return false;
}

// FUNCTION: 0x009b1c0c
bool cUnk00addd50::Slot37_adda20()
{
    hide_tip();
    mText.erase(0, std::string::npos);
    return true;
}

// FUNCTION: 0x009b0263
bool cUnk00addd50::Slot40_adda20(uint32_t x, uint32_t y)
{
    msPosX = static_cast<int16_t>(x);
    msPosY = static_cast<int16_t>(y);
    return true;
}

// FUNCTION: 0x009b008d
bool cUnk00addd50::Slot32_adda20(uint32_t a, uint32_t b)
{
    *OB_PTR(uint32_t, a) = mnMarginL;
    *OB_PTR(uint32_t, b) = mnMarginT;
    return true;
}

// FUNCTION: 0x009b0280
bool cUnk00addd50::Slot41_adda20(uint32_t a, uint32_t b)
{
    *OB_PTR(int32_t, a) = msPosX;
    *OB_PTR(int32_t, b) = msPosY;
    return true;
}

// FUNCTION: 0x009b19e0
bool cUnk00addd50::GZOnMouseExit(uint32_t /*win*/)
{
    set_btn_flag(0x2000, 0);
    hide_tip();
    return true;
}

// FUNCTION: 0x009b1be4
bool cUnk00addd50::GZOnMouseEnter(uint32_t /*win*/)
{
    if (!(mnBtnFlags & 0x1000)) {
        set_btn_flag(0x2000, 1);
        show_tip();
    }
    return true;
}

// FUNCTION: 0x009b01ab
bool cUnk00addd50::Slot25_adda20(uint32_t index, uint32_t out)
{
    uint32_t color = mnColors[index];
    if (color != 0x8000000) {
        *OB_PTR(uint32_t, out) = color;
        return true;
    }
    return false;
}

// FUNCTION: 0x009b0ff1
bool cUnk00addd50::Slot24_adda20(uint32_t index, uint32_t out)
{
    uint32_t color = mnColors[index];
    if (color != 0x8000000) {
        *OB_PTR(uint32_t, out) = ConvertNativeToPackedRGB(color);
        return true;
    }
    return false;
}

// FUNCTION: 0x009b0174
bool cUnk00addd50::Slot22_adda20(uint32_t index, uint32_t color)
{
    uint32_t native = ConvertPackedRGBToNative(color);
    if (mnColors[index] != native) {
        mnColors[index] = native;
        InvalidateSelfAndParents();
    }
    return true;
}

// FUNCTION: 0x009b014f
bool cUnk00addd50::Slot23_adda20(uint32_t index, uint32_t color)
{
    uint32_t* p = &mnColors[index];
    if (*p != color) {
        *p = color;
        InvalidateSelfAndParents();
    }
    return true;
}

// FUNCTION: 0x009b029f
bool cUnk00addd50::Slot42_adda20(uint32_t index, uint32_t r, uint32_t g, uint32_t b)
{
    mnTextColors[index] = (((static_cast<uint8_t>(r) << 8) | static_cast<uint8_t>(g)) << 8) | static_cast<uint8_t>(b);
    return true;
}

// FUNCTION: 0x009b02c3
bool cUnk00addd50::Slot43_adda20(uint32_t index, uint32_t r, uint32_t g, uint32_t b)
{
    uint32_t* p = &mnTextColors[index];
    *OB_PTR(uint8_t, r) = reinterpret_cast<uint8_t*>(p)[2];
    *OB_PTR(uint8_t, g) = static_cast<uint8_t>(*p >> 8);
    *OB_PTR(uint8_t, b) = static_cast<uint8_t>(*p);
    return true;
}

// FUNCTION: 0x009b0338
bool cUnk00addd50::Slot17_adda20(uint32_t a)
{
    Slot12_adda20(mnMode, a, 0);
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009b0005
void cUnk00addd50::SetKeyEquivalent(uint32_t key)
{
    cGZWin::SetKeyEquivalent(key);
    Slot49_adda20(OB_ADDR(Slot50_adda20()));
}

// FUNCTION: 0x009b00e9
bool cUnk00addd50::Slot52_addd50()
{
    PostMsg(field4c, 3, 0x287259f0, Slot48_adda20(), 0);
    return true;
}

// FUNCTION: 0x009b00b4
bool cUnk00addd50::Slot51_addd50()
{
    PostMsg(field4c, 3, 0x287259f6, Slot48_adda20(), mnBtnFlags & 1);
    return true;
}

// FUNCTION: 0x009b0776
bool cUnk00addd50::Slot33_adda20()
{
    int32_t size[4];
    if (Slot34_adda20(OB_ADDR(size))) {
        if (size[0] != 0 || size[1] != 0) {
            SetSize_2(size[0], size[1]);
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x009b1397
void cUnk00addd50::Slot07_add348(uint32_t l, uint32_t t, uint32_t r, uint32_t b)
{
    int32_t w = r - l;
    int32_t h = b - t;
    if (w < 0) {
        w = 0;
    }
    if (h < 0) {
        h = 0;
    }
    cGZWin::Slot07_add348(l, t, l + w, t + h);
    on_layout(w, h);
}

// FUNCTION: 0x009b112d
uint32_t cUnk00addd50::Slot68_adc8d8(uint32_t a, uint32_t b)
{
    uint32_t result = cGZWin::Slot68_adc8d8(a, b);
    switch (a) {
    case 1:
        InvalidateSelfAndParents();
        break;
    case 2:
        on_layout(GetW(), GetH());
        InvalidateSelfAndParents();
        break;
    }
    return result;
}

// FUNCTION: 0x009b0f9e
bool cUnk00addd50::Slot29_adda20(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    mnMarginL = static_cast<uint8_t>(a);
    mnMarginT = static_cast<uint8_t>(b);
    mnMarginR = static_cast<uint8_t>(c);
    mnMarginB = static_cast<uint8_t>(d);
    on_layout(GetW(), GetH());
    return true;
}

// FUNCTION: 0x009b0116
bool cUnk00addd50::Slot31_adda20(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(uint32_t, a) = mnMarginL;
    *OB_PTR(uint32_t, b) = mnMarginT;
    *OB_PTR(uint32_t, d) = mnMarginB;
    *OB_PTR(uint32_t, c) = mnMarginR;
    return true;
}

// FUNCTION: 0x009b0507
bool cUnk00addd50::Slot20_adda20(uint32_t id)
{
    mnFontId = id;
    if (get_init_flag() || mpFontObj) {
        uint32_t key = mnFontId ? mnFontId : 0x68963c4c;
        Slot19_adda20(OB_ADDR(Fn00913c72()->GetFont(key)));
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b01df score 12
bool cUnk00addd50::Slot35_adda20(uint32_t text)
{
    cIGZString* s = OB_PTR(cIGZString, text);
    if (s->Strlen()) {
        mText.Copy(*s);
        reinterpret_cast<Self_addd50*>(this)->SetFlag(0x100, 1);
    } else {
        reinterpret_cast<Self_addd50*>(this)->SetFlag(0x100, 0);
    }
    Slot37_adda20();
    return true;
}
#endif

// FUNCTION: 0x009b167d
bool cUnk00addd50::GZPaint()
{
    if (mpBitmap) {
        btn_paint_bmp();
    } else {
        btn_paint_flat();
    }
    if (mnBtnFlags & 4) {
        btn_paint_label();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b19ff score 11
bool cUnk00addd50::GZOnCaptureChanged(uint32_t from, uint32_t to)
{
    cUnk00addd50* self = this;
    if (to != OB_ADDR(static_cast<cGZWin*>(self))) {
        set_btn_flag(0x2000, 0);
        set_btn_flag(0x1000, 0);
        hide_tip();
    }
    return true;
}
#endif

// The window seen through the framework window's vtable (return types the base header lacks).
struct WinCalls_addd50 {
    // STUB: 0x0099bdfe
    bool GZSetCapture();
};

// The timer the button owns (its class is not declared yet): the slots used.
struct cTimer_addd50 {
    virtual void T0();
    virtual void T1();
    virtual void T2();
    virtual void T3();
    virtual void T4();
    virtual void StartPeriodic(uint32_t period, void* target);
    virtual void T6();
    virtual void Stop();
    virtual bool IsRunning();
    virtual void SetCallbackFunction(void (*fn)(void*), void* context);
};

// STUB: 0x009b0311
void Fn009b0311(void* context);

// FUNCTION: 0x009b1291
bool cUnk00addd50::Slot27_adda20(uint32_t align)
{
    mnAlign = align;
    switch (align) {
    case 0:
        msAlignCode = 1;
        break;
    case 1:
        msAlignCode = 0;
        break;
    case 2:
        msAlignCode = 2;
        break;
    }
    on_layout(GetW(), GetH());
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b14e4 score 2
void cUnk00addd50::Slot49_adda20(uint32_t text)
{
    cGZWin::Slot49_adda20(text);
    if (OB_PTR(cIGZString, text)->Strlen()) {
        reinterpret_cast<Self_addd50*>(this)->SetFlag(4, 1);
        update_text_size();
    } else {
        reinterpret_cast<Self_addd50*>(this)->SetFlag(4, 0);
    }
    on_layout(GetW(), GetH());
}
#endif

// FUNCTION: 0x009b1058
void cUnk00addd50::Slot44_adda20(uint32_t flashes, uint32_t period)
{
    cTimer_addd50* timer = reinterpret_cast<cTimer_addd50*>(mFlashTimer);
    if (timer->IsRunning()) {
        timer->Stop();
    }
    mnFlash = flashes;
    on_layout(GetW(), GetH());
    timer->SetCallbackFunction(Fn009b0311, this);
    timer->StartPeriodic(period, 0);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b0497 score 8
bool cUnk00addd50::Slot13_adda20(uint32_t a)
{
    Quad_addd50 r = *reinterpret_cast<Quad_addd50*>(mnRect);
    uint8_t m = 1;
    if (mnMode >= 2) {
        if (mnMode <= 3) {
            m = 4;
        } else if (mnMode == 4) {
            m += 7;
        }
    }
    r.v[2] = (r.v[2] - r.v[0]) * m + r.v[0];
    Slot12_adda20(a, mpBitmap, OB_ADDR(&r));
    InvalidateSelfAndParents();
    return true;
}
#endif

// FUNCTION: 0x009b0b87
void cUnk00addd50::Fn009b0b87(void* area)
{
    const int32_t* r = static_cast<const int32_t*>(area);
    int16_t x;
    switch (mnAlign) {
    case 0:
        x = static_cast<int16_t>((r[2] - msTextX - r[0]) / 2 + r[0]);
        break;
    case 1:
        x = static_cast<int16_t>(r[0]);
        break;
    case 2:
        x = static_cast<int16_t>(r[2] - msTextX);
        break;
    default:
        msLabelX = 0;
        msLabelY = 0;
        return;
    }
    msLabelX = x;
    msLabelY = static_cast<int16_t>((r[3] - msTextY - r[1]) / 2 + r[1]);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b1a3b score 17
bool cUnk00addd50::DoMessage(uint32_t msg)
{
    if (*OB_PTR(uint32_t, msg) == 0xc7ec278e) {
        on_layout(GetW(), GetH());
        uint32_t n = mnFlash;
        if (n != 0) {
            if (n == 0xffffffff) {
                mnFlash = 0xfffffffe;
            }
            if (mnFlash == 0xfffffffe) {
                mnFlash = 0xffffffff;
            } else {
                mnFlash = n - 1;
            }
        } else {
            cTimer_addd50* timer = reinterpret_cast<cTimer_addd50*>(mFlashTimer);
            if (timer->IsRunning()) {
                timer->Stop();
            }
        }
        return true;
    }
    return cGZWin::DoMessage(msg);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b176c score 45
bool cUnk00addd50::GZOnMouseDownL(uint32_t x, uint32_t y, uint32_t flags)
{
    if (!(mnBtnFlags & 0x1000)) {
        Fn009b071a(0);
        cGZWin* w = this;
        reinterpret_cast<WinCalls_addd50*>(w)->GZSetCapture();
        hide_tip();
        set_btn_flag(0x1000, 1);
        if ((mnBtnFlags & 2) && !(mnBtnFlags & 0x800)) {
            Fn009b071a(2);
            set_btn_flag(1, static_cast<uint8_t>(~static_cast<uint8_t>(mnBtnFlags)) & 1);
            Slot51_addd50();
        }
        InvalidateSelfAndParents();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b17ef score 51
bool cUnk00addd50::GZOnMouseDownR(uint32_t x, uint32_t y, uint32_t flags)
{
    if (!(mnBtnFlags & 0x1000)) {
        Fn009b071a(0);
        cGZWin* w = this;
        reinterpret_cast<WinCalls_addd50*>(w)->GZSetCapture();
        hide_tip();
        set_btn_flag(0x1000, 1);
        if (mnBtnFlags & 2) {
            if (mnBtnFlags & 0x800) {
                Fn009b071a(2);
                set_btn_flag(1, static_cast<uint8_t>(~static_cast<uint8_t>(mnBtnFlags)) & 1);
                Slot51_addd50();
            } else {
                Slot52_addd50();
            }
        }
        InvalidateSelfAndParents();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b187c score 28
bool cUnk00addd50::GZOnMouseUpL(uint32_t x, uint32_t y, uint32_t flags)
{
    bool wasDown = ((mnBtnFlags >> 12) & 1) != 0;
    if (wasDown) {
        Fn009b071a(1);
        set_btn_flag(0x1000, 0);
        cGZWin* w = this;
        if (GZAmCapturing()) {
            if (!(mnBtnFlags & 2) && IsPointInWindowWindowCoordinates(x, y) && wasDown) {
                Fn009b071a(2);
                set_btn_flag(1, static_cast<uint8_t>(~static_cast<uint8_t>(mnBtnFlags)) & 1);
                Slot51_addd50();
            }
            GZReleaseCapture();
        }
    }
    if (wasDown) {
        InvalidateSelfAndParents();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b1923 score 41
bool cUnk00addd50::GZOnMouseUpR(uint32_t x, uint32_t y, uint32_t flags)
{
    bool wasDown = ((mnBtnFlags >> 12) & 1) != 0;
    if (wasDown) {
        Fn009b071a(1);
        set_btn_flag(0x1000, 0);
        cGZWin* w = this;
        if (GZAmCapturing()) {
            if (!(mnBtnFlags & 2) && IsPointInWindowWindowCoordinates(x, y) && wasDown) {
                if (mnBtnFlags & 0x800) {
                    Fn009b071a(2);
                    set_btn_flag(1, static_cast<uint8_t>(~static_cast<uint8_t>(mnBtnFlags)) & 1);
                    Slot51_addd50();
                } else {
                    Slot52_addd50();
                }
            }
            GZReleaseCapture();
        }
    }
    if (wasDown) {
        InvalidateSelfAndParents();
    }
    return true;
}
#endif

// The bitmap object: the slots used.
struct Bitmap_addd50 {
    virtual void B0();
    virtual void B1();
    virtual void B2();
    virtual void B3();
    virtual void B4();
    virtual void B5();
    virtual void B6();
    virtual void B7();
    virtual void B8();
    virtual uint32_t GetWidth();
    virtual uint32_t GetHeight();
};

// The sound system the accessor 0x00913c9e gives.
struct cSS_addd50 {
    virtual void Q0();
    virtual void Q1();
    virtual void Q2();
    virtual void Q3();
    virtual void Q4();
    virtual void Q5();
    virtual void Q6();
    virtual void Q7();
    virtual bool Play(uint32_t object);
    virtual void Q9();
    virtual void Q10();
    virtual void Q11();
    virtual void Q12();
    virtual bool Create(uint32_t kind, uint32_t iid, uint32_t* out, uint32_t id, uint32_t a, uint32_t b, uint32_t c);
};

// STUB: 0x00913c9e
cSS_addd50* Fn00913c9e();

// A reference-counting pointer slot the original assigns through a helper.
struct RefSlot_addd50 {
    void* p;
    // STUB: 0x005447b0
    void Fn005447b0(void* value);
};

// The message server the accessor 0x00913b97 gives; slot 3 sends a message.
struct cMS_addd50 {
    virtual void M0();
    virtual void M1();
    virtual void M2();
    virtual void Send(void* message);
};

// STUB: 0x00913b97
cMS_addd50* Fn00913b97();

struct Msg_addd50 {
    uint32_t type;
    uint32_t a;
    uint32_t b;
    uint32_t c;
};

// The tooltip description the message carries.
struct TipInfo_addd50 {
    uint32_t v[11];
    void Fn009b035d();
};

// STUB: 0x008d9900
void Fn008d9900(void* context, void* rect, uint32_t color, bool raised, bool fill);

// STUB: 0x008d9360
void Fn008d9360(void* context, void* rect, uint32_t color, uint32_t width);

// STUB: 0x008d8800
void Fn008d8800(void* context, void* bitmap, void* source, void* destination, bool stretch);

// The draw context the button paints through: the slots used.
struct cDraw_addd50 {
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
    virtual void Blt(void* bitmap, void* source, void* destination);
    virtual void D53();
    virtual void D54();
};

inline const int32_t* AreaOf_addd50(const cUnk00addd50* p)
{
    return reinterpret_cast<const int32_t*>(&p->field24);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b035d score 25
void TipInfo_addd50::Fn009b035d()
{
    v[0] = 1;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
    v[5] = 0;
    v[6] = 0;
    v[7] = 0;
    v[8] = 0xffffe0;
    v[9] = 0;
    v[10] = 0;
}
#endif

// FUNCTION: 0x009b101e
bool cUnk00addd50::hide_tip()
{
    cMS_addd50* ms = Fn00913b97();
    if (ms) {
        Msg_addd50 m;
        m.b = 0;
        m.c = 0;
        m.a = mnTipId;
        m.type = 0x22c010d8;
        ms->Send(&m);
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b071a score 2
void cUnk00addd50::Fn009b071a(uint32_t index)
{
    if (mnSounds[index] != 0) {
        cSS_addd50* ss = Fn00913c9e();
        if (ss) {
            uint32_t out = 0;
            if (ss->Create(1, 0x5b523ba4, &out, mnSounds[index], 0, 0, 0)) {
                ss->Play(out);
                if (out) {
                    OB_PTR(cIGZUnknown, out)->Release();
                }
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b12ef score 27
bool cUnk00addd50::Slot19_adda20(uint32_t font)
{
    if (mpFontObj != font) {
        reinterpret_cast<RefSlot_addd50*>(&mpFontObj)->Fn005447b0(OB_PTR(void, font));
        if (mpFontObj) {
            Font_addd50* f = OB_PTR(Font_addd50, mpFontObj);
            uint32_t c0 = f->Slot12();
            uint32_t c1 = f->Slot13();
            if (mnColors[0] == 0x8000000) {
                mnColors[0] = c0;
            }
            if (mnColors[1] == 0x8000000) {
                mnColors[1] = c1;
            }
            if (mnColors[2] == 0x8000000) {
                mnColors[2] = c0;
            }
            if (mnColors[3] == 0x8000000) {
                mnColors[3] = c1;
            }
            if (mnColors[4] == 0x8000000) {
                mnColors[4] = c0;
            }
            if (mnColors[5] == 0x8000000) {
                mnColors[5] = c1;
            }
        }
    }
    on_layout(GetW(), GetH());
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b066c score 34
bool cUnk00addd50::btn_paint_flat()
{
    if (!(mnBtnFlags & 0x10)) {
        bool raised = true;
        if (mnMode == 2) {
            raised = !(mnBtnFlags & 0x1000);
        } else if (mnMode >= 2 && mnMode <= 4) {
            if ((mnBtnFlags & 0x1000) || (mnBtnFlags & 1)) {
                raised = false;
            }
        }
        const int32_t* area = AreaOf_addd50(this);
        Fn008d9900(OB_PTR(void, field6c), const_cast<int32_t*>(area), GetFillColorRGB(), raised, true);
        if (mnBtnFlags & 0x2000) {
            int32_t r[4];
            r[0] = area[0] + 1;
            r[1] = area[1] + 1;
            r[2] = area[2] - 1;
            r[3] = area[3] - 1;
            Fn008d9360(OB_PTR(void, field6c), r, 0xffffffff, 1);
        }
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b0575 score 87
bool cUnk00addd50::btn_paint_bmp()
{
    const int32_t* area = AreaOf_addd50(this);
    int32_t w = mnRect[2] - mnRect[0];
    int32_t h = mnRect[3] - mnRect[1];
    int32_t src[4];
    src[0] = mnLabelX;
    src[1] = mnRect[1];
    src[2] = w + mnLabelX;
    src[3] = mnRect[1] + h;
    if ((!(mnBtnFlags & 0x20) || (mnBtnFlags & 4)) && (area[2] - area[0] != mnRect[2] - mnRect[0]) && mnMode != 4) {
        int32_t part[4];
        part[0] = src[0];
        part[1] = src[1];
        part[2] = (src[2] - src[0]) / 3 + src[0];
        part[3] = (src[3] - src[1]) / 3 + src[1];
        Fn008d8800(OB_PTR(void, field6c), OB_PTR(void, mpBitmap), part, const_cast<int32_t*>(area), true);
    } else {
        int32_t dst[4];
        dst[0] = mnLabelY + area[0];
        dst[1] = mnLabelZ + area[1];
        dst[2] = dst[0] + w;
        dst[3] = dst[1] + h;
        OB_PTR(cDraw_addd50, field6c)->Blt(OB_PTR(void, mpBitmap), src, dst);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b1179 score 69
bool cUnk00addd50::Slot12_adda20(uint32_t mode, uint32_t bitmap, uint32_t rect)
{
    if (mode == 0) {
        mnLayout = 0;
        return false;
    }
    mnMode = mode;
    uint8_t divisor;
    if (mode == 1) {
        mnLayout = 0;
        return false;
    } else if (mode <= 3) {
        mnLayout = 1;
        divisor = 4;
    } else if (mode == 4) {
        reinterpret_cast<Self_addd50*>(this)->SetFlag(0x80, 0);
        mnLayout = 2;
        divisor = 8;
    } else {
        mnLayout = 0;
        return false;
    }
    if (mpBitmap != bitmap) {
        reinterpret_cast<RefSlot_addd50*>(&mpBitmap)->Fn005447b0(OB_PTR(void, bitmap));
    }
    if (rect) {
        const int32_t* r = OB_PTR(const int32_t, rect);
        mnRect[0] = r[0];
        mnRect[1] = r[1];
        mnRect[2] = (r[2] - r[0]) / divisor + mnRect[0];
        mnRect[3] = r[3] - r[1] + mnRect[1];
    } else {
        Bitmap_addd50* b = OB_PTR(Bitmap_addd50, bitmap);
        mnRect[0] = 0;
        mnRect[1] = 0;
        mnRect[2] = b->GetWidth() / divisor;
        mnRect[3] = b->GetHeight();
    }
    on_layout(GetW(), GetH());
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b16b0 score 30
bool cUnk00addd50::GZOnKeyDown(uint32_t key, uint32_t flags)
{
    if (key == 0xd) {
        Slot51_addd50();
    } else {
        WinView_addd50* win = reinterpret_cast<WinView_addd50*>(static_cast<cGZWin*>(this));
        if (key != 0x20) {
            return win->SendMsg(field4c, 5, key, flags, 0);
        }
        if (!(mnBtnFlags & 0x4000)) {
            set_btn_flag(0x4000, 1);
            win->SendMsg(OB_ADDR(static_cast<cGZWin*>(this)), 7, 1, 1, flags);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b1722 score 21
bool cUnk00addd50::GZOnKeyUp(uint32_t key, uint32_t flags)
{
    WinView_addd50* win = reinterpret_cast<WinView_addd50*>(static_cast<cGZWin*>(this));
    if (key != 0x20) {
        return win->SendMsg(field4c, 6, key, flags, 0);
    }
    set_btn_flag(0x4000, 0);
    return win->SendMsg(OB_ADDR(static_cast<cGZWin*>(this)), 10, 1, 1, flags);
}
#endif

// FUNCTION: 0x009b038a
bool cUnk00addd50::Slot03_ae1d24()
{
    if (!get_init_flag()) {
        cGZWin::Slot03_ae1d24();
        cWCM_addd50* wcm = Fn00913c72();
        if ((mnBtnFlags & 4) && mpFontObj == 0 && wcm) {
            uint32_t key = mnFontId;
            if (!key) {
                key = 0x68963c4c;
            }
            Slot19_adda20(OB_ADDR(wcm->GetFont(key)));
        }
        if (mnMode == 0) {
            if (wcm) {
                Font_addd50* obj = static_cast<Font_addd50*>(wcm->GetClass(0xe8963ef1));
                if (obj) {
                    Slot12_adda20(2, OB_ADDR(obj), obj->Slot12());
                } else {
                    Slot12_adda20(2, 0, 0);
                }
            } else {
                Slot12_adda20(2, 0, 0);
            }
        }
        if (mnBtnFlags & 0x20) {
            Slot33_adda20();
        }
        if (wcm) {
            for (int32_t i = 0; i < 3; i++) {
                if (mnSounds[i] == 0) {
                    Slot45_adda20(i, wcm->GetSound(i));
                }
            }
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b1ac0 score 103
bool cUnk00addd50::show_tip()
{
    if ((mnBtnFlags & 0x100) && mText.size() != 0) {
        TipInfo_addd50 tip;
        tip.Fn009b035d();
        tip.v[2] = OB_ADDR(&mText);
        if (mnBtnFlags & 0x200) {
            tip.v[1] |= 1;
        }
        if (mnBtnFlags & 0x400) {
            tip.v[1] |= 2;
        }
        tip.v[1] |= mn174;
        if (tip.v[1] & 0x10000) {
            int32_t x = msPosX;
            int32_t y = msPosY;
            WinView_addd50* win = reinterpret_cast<WinView_addd50*>(static_cast<cGZWin*>(this));
            (void)win;
            tip.v[3] = x;
            tip.v[4] = y;
            tip.v[5] = x;
            tip.v[6] = y;
        } else {
            const Quad_addd50* q = reinterpret_cast<const Quad_addd50*>(&field14);
            tip.v[3] = q->v[0];
            tip.v[4] = q->v[1];
            tip.v[5] = q->v[2];
            tip.v[6] = q->v[3];
        }
        tip.v[7] = mnTextColors[0];
        tip.v[8] = mnTextColors[1];
        tip.v[9] = mnTextColors[2];
        cMS_addd50* ms = Fn00913b97();
        if (ms) {
            Msg_addd50 m;
            m.b = 0;
            m.c = 0;
            m.a = OB_ADDR(&tip);
            m.type = 0x22c010d0;
            ms->Send(&m);
            mnTipId = m.type;
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b1541 score 97
void cUnk00addd50::btn_paint_label()
{
    if ((mnBtnFlags & 4) && mpFontObj != 0) {
        uint32_t c0;
        uint32_t c1;
        if (Slot67_adc8d8(2)) {
            if (mnBtnFlags & 0x2000) {
                c0 = mnColors[4];
                c1 = mnColors[5];
            } else {
                c0 = mnColors[0];
                c1 = mnColors[1];
            }
        } else {
            c0 = mnColors[2];
            c1 = mnColors[3];
        }
        uint32_t shift = 0;
        if ((mnBtnFlags & 0x80) && (mnBtnFlags & 0x1000)) {
            shift = 1;
        }
        const int32_t* area = AreaOf_addd50(this);
        Font_addd50* font = OB_PTR(Font_addd50, mpFontObj);
        if (mnBtnFlags & 0x40) {
            int32_t r[4];
            r[0] = msLabelX + area[0] + shift;
            r[1] = msLabelY + area[1] + shift;
            r[2] = r[0] + msTextX;
            r[3] = r[1] + msTextY;
            if (r[1] < area[1]) {
                r[1] = area[1];
            }
            font->Slot43(OB_ADDR(r), mnRect[2], mnRect[3]);
        } else {
            font->Slot43(msLabelX + area[0] + shift, msLabelY + area[1] + shift, mnRect[2]);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b13dd score 53
bool cUnk00addd50::set_btn_flag(int32_t flag, uint32_t on)
{
    uint32_t old = mnBtnFlags;
    uint32_t now;
    if (on) {
        now = old | flag;
    } else {
        now = old & ~flag;
    }
    if (now != old) {
        mnBtnFlags = now;
        switch (flag) {
        case 1:
            PostMsg(field4c, 3, 0x287259f7, Slot48_adda20(), on != 0);
            break;
        case 0x1000:
            PostMsg(field4c, 3, 0x287259f8, Slot48_adda20(), on != 0);
            break;
        case 0x2000:
            PostMsg(field4c, 3, 0x287259f9, Slot48_adda20(), on != 0);
            break;
        case 0x1000000:
            InvalidateSelfAndParents();
            return true;
        case 4:
        case 0x20:
        case 0x40:
            break;
        default:
            return true;
        }
        on_layout(GetW(), GetH());
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b0c08 score 264
bool cUnk00addd50::on_layout(int32_t width, int32_t height)
{
    InvalidateSelfAndParents();
    update_text_size();
    int32_t bh = mnRect[3] - mnRect[1];
    int32_t bw = mnRect[2] - mnRect[0];
    bool flash = (mnFlash & 1) != 0;
    switch (mnLayout) {
    case 0:
        mnLabelX = mnRect[0];
        if (Slot67_adc8d8(2)) {
            if (flash || !(mnBtnFlags & 0x1000)) {
                mnLabelX += bw;
            } else {
                mnLabelX += bw * 2;
            }
        }
        mnLabelY = 0;
        mnLabelZ = (height - bh) / 2;
        break;
    case 1:
        mnLabelX = mnRect[0];
        if (Slot67_adc8d8(2)) {
            if (!flash && (mnBtnFlags & 0x1000)) {
                mnLabelX += bw * 4;
            } else if (mnBtnFlags & 1) {
                mnLabelX += bw * 6;
            } else {
                mnLabelX += bw * 7;
            }
        } else {
            mnLabelX += bw * 3;
        }
        mnLabelY = 0;
        mnLabelZ = (height - bh) / 2;
        break;
    case 2:
        mnLabelX = mnRect[0];
        if (Slot67_adc8d8(2)) {
            if (!flash && ((mnBtnFlags & 0x1000) || (mnBtnFlags & 1) || (mnBtnFlags & 0x2000))) {
                mnLabelX += bw * 2;
            } else {
                mnLabelX += bw;
            }
        }
        mnLabelY = 0;
        mnLabelZ = 0;
        break;
    default:
        return false;
    }
    if (mnBtnFlags & 4) {
        int32_t r[4];
        r[0] = mnMarginL;
        r[1] = mnMarginT;
        r[2] = width - mnMarginR;
        r[3] = height - mnMarginB;
        Fn009b0b87(r);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b09b7 score 155
void cUnk00addd50::update_text_size()
{
    if (mpFontObj == 0) {
        cWCM_addd50* wcm = Fn00913c72();
        if (wcm) {
            if (mnFontId) {
                reinterpret_cast<RefSlot_addd50*>(&mpFontObj)->Fn005447b0(wcm->GetFont(mnFontId));
            }
            if (mpFontObj == 0) {
                reinterpret_cast<RefSlot_addd50*>(&mpFontObj)->Fn005447b0(wcm->GetFont(0x68963c54));
            }
            if (mpFontObj == 0) {
                reinterpret_cast<RefSlot_addd50*>(&mpFontObj)->Fn005447b0(wcm->GetFont(0x68963c4c));
            }
        }
    }
    Font_addd50* font = OB_PTR(Font_addd50, mpFontObj);
    if (font && (mnBtnFlags & 4)) {
        int32_t avail = GetW() - mnMarginR - mnMarginL;
        if ((mnBtnFlags & 0x40) && mnMode == 4) {
            avail -= mnRect[2] - mnRect[0];
        }
        if (mnBtnFlags & 0x40) {
            uint32_t lines = font->Slot43(0, 0, avail);
            int16_t th = static_cast<int16_t>(font->Slot37(0, 0) * lines);
            msTextY = th;
            if (lines == 1) {
                int32_t box[4];
                font->Slot47(0, 0, box);
                msTextX = static_cast<int16_t>(box[2] - box[0]);
            } else {
                msTextX = static_cast<int16_t>(font->Slot44(0, 0, th));
            }
        } else {
            int32_t box[4];
            font->Slot47(0, 0, box);
            msTextX = static_cast<int16_t>(box[2] - box[0]);
            msTextY = static_cast<int16_t>(box[3] - box[1]);
        }
    } else {
        msTextX = 0;
        msTextY = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b07b7 score 200
bool cUnk00addd50::Slot34_adda20(uint32_t outp)
{
    int32_t* o = OB_PTR(int32_t, outp);
    int32_t bw = mnRect[2] - mnRect[0];
    int32_t bh = mnRect[3] - mnRect[1];
    int32_t tw = mnMarginR + msTextX + mnMarginL;
    int32_t th = msTextY + mnMarginB + mnMarginT;
    const int32_t maxv = 0x7fffffff;
    switch (mnMode) {
    case 1:
        o[0] = tw;
        o[1] = th;
        o[2] = maxv;
        o[3] = maxv;
        break;
    case 2:
    case 3:
        if (mpBitmap) {
            o[0] = bw;
            o[1] = bh;
            if (mnBtnFlags & 4) {
                if (o[0] < msTextX) {
                    o[0] = msTextX;
                }
                if (o[1] < msTextY) {
                    o[1] = msTextY;
                }
            }
        } else if (mnBtnFlags & 4) {
            o[0] = msTextX;
            o[1] = msTextY;
        } else {
            const int32_t* area = AreaOf_addd50(this);
            o[0] = area[2] - area[0];
            o[1] = area[3] - area[1];
        }
        o[2] = o[0] > 0 ? o[0] : maxv;
        o[3] = o[1] > 0 ? o[1] : maxv;
        break;
    case 4:
        o[0] = bw + tw;
        o[1] = bh < th ? th : bh;
        o[2] = maxv;
        o[3] = o[1] > 0 ? o[1] : maxv;
        break;
    default:
        o[0] = bw;
        o[1] = bh;
        o[2] = maxv;
        o[3] = maxv;
        break;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b10d0 score 5
bool cUnk00addd50::Slot04_ae1d24()
{
    if (get_init_flag()) {
        cTimer_addd50* timer = reinterpret_cast<cTimer_addd50*>(mFlashTimer);
        if (timer->IsRunning()) {
            timer->Stop();
        }
        hide_tip();
        HideWindow();
        reinterpret_cast<RefSlot_addd50*>(&mpBitmap)->Fn005447b0(0);
        reinterpret_cast<RefSlot_addd50*>(&mpFontObj)->Fn005447b0(0);
        cGZWin::Slot04_ae1d24();
        return true;
    }
    return false;
}
#endif
