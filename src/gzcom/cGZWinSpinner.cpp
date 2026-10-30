#include <stddef.h>

#include "classes/cGZWinSpinner.h"

// A 16-byte rectangle record (left, top, right, bottom).
struct Rect_ae0b90 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
};

// A smart pointer member: assigning it adds a reference to the new object and drops the old one.
struct RefPtr_ae0b90 {
    void* mpObject;
    // STUB: 0x005447b0
    void Fn005447b0(void* object);
};

// The image object the spinner draws its buttons from.
struct Image_ae0b90 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void GetRect(Rect_ae0b90* rect);
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual int32_t GetWidth(uint32_t a, uint32_t b);
};

// The window-class manager, as far as the spinner calls it.
struct Wcm_ae0b90 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* Find(uint32_t id);
    virtual void V6();
    virtual void* Find2(uint32_t id, uint32_t flag);
};

// STUB: 0x00913c72
Wcm_ae0b90* Fn00913c72();

// FUNCTION: 0x00999055
uint32_t cGZWinSpinner::Slot07_ae0b00(uint32_t mask)
{
    return (mnFlags & mask) != 0;
}

// FUNCTION: 0x009c4745
bool cGZWinSpinner::QueryInterface(uint32_t iid, void** outv)
{
    void** out = outv;
    if (iid == 0x612ce0c3) {
        *out = static_cast<cUnk00ae0b00*>(this);
        AddRef();
        return true;
    }
    return cGZWin::QueryInterface(iid, out);
}

// FUNCTION: 0x009c4772
bool cGZWinSpinner::Slot18_ae0b00(uint32_t out)
{
    *OB_PTR(Rect_ae0b90, out) = *reinterpret_cast<Rect_ae0b90*>(mnRect);
    return true;
}

// FUNCTION: 0x009c4786
bool cGZWinSpinner::GZOnMouseUpL(uint32_t /*a*/, uint32_t /*b*/, uint32_t /*c*/)
{
    mnState = 0x190;
    if (mnCaptured == 0) {
        GZReleaseCapture();
    }
    mnHeld = 0;
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009c47b8
bool cGZWinSpinner::GZOnCaptureChanged(uint32_t /*a*/, uint32_t b)
{
    if (OB_PTR(cGZWinSpinner, b) != this) {
        mnHeld = 0;
        InvalidateSelfAndParents();
    }
    return true;
}

// FUNCTION: 0x009c48d2
bool cGZWinSpinner::Slot10_ae0b00(uint32_t lo, uint32_t hi)
{
    mnMin = lo;
    mnMax = hi;
    return true;
}

// FUNCTION: 0x009c48e5
bool cGZWinSpinner::Slot11_ae0b00(uint32_t lo, uint32_t hi)
{
    *OB_PTR(int32_t, lo) = mnMin;
    *OB_PTR(int32_t, hi) = mnMax;
    return true;
}

// FUNCTION: 0x009c4908
bool cGZWinSpinner::Slot13_ae0b00(uint32_t out)
{
    *OB_PTR(int32_t, out) = mnStep;
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c4916 score 15
bool cGZWinSpinner::Slot20_ae0b00(uint32_t id)
{
    mnImageId = id;
    if (Fn0099bc31()) {
        Wcm_ae0b90* wcm = Fn00913c72();
        void* found = wcm->Find(mnImageId);
        if (found != 0) {
            ChildExists_2(found);
        }
    }
    return true;
}
#endif

// FUNCTION: 0x009c4950
bool cGZWinSpinner::Slot21_ae0b00(uint32_t out)
{
    *OB_PTR(uint32_t, out) = mnImageId;
    return true;
}

// FUNCTION: 0x009c495e
bool cGZWinSpinner::Slot23_ae0b00(uint32_t index, uint32_t color)
{
    uint32_t packed = ConvertNativeToPackedRGB(color);
    if (mnColors[index] != packed) {
        mnColors[index] = packed;
        InvalidateSelfAndParents();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c4995 score 6
bool cGZWinSpinner::Slot25_ae0b00(uint32_t index, uint32_t out)
{
    uint32_t value = mnColors[index];
    if (value == 0xdeadbeef) {
        return false;
    }
    *OB_PTR(uint32_t, out) = ConvertPackedRGBToNative(value);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c49c2 score 6
bool cGZWinSpinner::Slot24_ae0b00(uint32_t index, uint32_t out)
{
    uint32_t value = mnColors[index];
    if (value == 0xdeadbeef) {
        return false;
    }
    *OB_PTR(uint32_t, out) = value;
    return true;
}
#endif

// FUNCTION: 0x009c49e0
bool cGZWinSpinner::Slot26_ae0b00(uint32_t index)
{
    Slot23_ae0b00(index, 0xdeadbeef);
    return true;
}

// FUNCTION: 0x009c49f3
bool cGZWinSpinner::Slot27_ae0b00(uint32_t mode)
{
    switch (mode) {
    case 0:
        mnButtonMode = 0;
        break;
    case 1:
        mnButtonMode = 1;
        break;
    case 2:
        mnButtonMode = 2;
        break;
    default:
        return false;
    }
    InvalidateSelfAndParents();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c4a29 score 14
bool cGZWinSpinner::Slot28_ae0b00(uint32_t out)
{
    switch (mnButtonMode) {
    case 0:
        *OB_PTR(uint32_t, out) = 0;
        break;
    case 1:
        *OB_PTR(uint32_t, out) = 1;
        break;
    case 2:
        *OB_PTR(uint32_t, out) = 2;
        break;
    default:
        return false;
    }
    return true;
}
#endif

// FUNCTION: 0x009c4a5f
bool cGZWinSpinner::Slot30_ae0b00(uint32_t a, uint32_t b)
{
    *OB_PTR(uint8_t, a) = mbFlag154;
    *OB_PTR(uint8_t, b) = mbFlag155;
    return true;
}

// FUNCTION: 0x009c521a
bool cGZWinSpinner::Slot29_ae0b00(uint32_t a, uint32_t b)
{
    mbFlag154 = static_cast<uint8_t>(a);
    mbFlag155 = static_cast<uint8_t>(b);
    Fn009c4bbc();
    return true;
}

// FUNCTION: 0x009c4adf
bool cGZWinSpinner::Slot33_ae0b00(uint32_t index, uint32_t value)
{
    mnTextColors[index] = *OB_PTR(uint32_t, value);
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009c4b03
bool cGZWinSpinner::Slot34_ae0b00(uint32_t index, uint32_t out)
{
    *OB_PTR(uint32_t, out) = mnTextColors[index];
    return true;
}

// FUNCTION: 0x009c594e
bool cGZWinSpinner::Slot22_ae0b00(uint32_t index, uint32_t value)
{
    if (mnColors[index] != value) {
        mnColors[index] = value;
        InvalidateSelfAndParents();
    }
    return true;
}

// FUNCTION: 0x009c4a76
bool cGZWinSpinner::Slot32_ae0b00(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(uint32_t, a) = ConvertPackedRGBToNative(mnTextColors[0]);
    *OB_PTR(uint32_t, b) = ConvertPackedRGBToNative(mnTextColors[1]);
    *OB_PTR(uint32_t, c) = ConvertPackedRGBToNative(mnTextColors[2]);
    *OB_PTR(uint32_t, d) = ConvertPackedRGBToNative(mnTextColors[3]);
    return true;
}

// FUNCTION: 0x009c4bbc
void cGZWinSpinner::Fn009c4bbc()
{
    Rect_ae0b90 r = *static_cast<Rect_ae0b90*>(GetArea_2());
    Slot07_add348(r.mnLeft, r.mnTop, r.mnRight, r.mnBottom);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c4d02 score 14
void cGZWinSpinner::Fn009c4d02()
{
    if (mpImage != 0) {
        Rect_ae0b90 r;
        if (mnFlags & 0x8000) {
            r = *reinterpret_cast<Rect_ae0b90*>(mnRect);
        } else {
            static_cast<Image_ae0b90*>(mpImage)->GetRect(&r);
        }
        int32_t x = r.mnLeft;
        int32_t y = r.mnTop;
        mnBtnY = static_cast<int16_t>(y);
        mnBtnX = static_cast<int16_t>(x);
        mnBtnW = (r.mnRight - x) / 4;
        mnBtnH = (r.mnBottom - y) / 2;
    }
}
#endif

// FUNCTION: 0x009c4cd5
bool cGZWinSpinner::Slot04_ae1d24()
{
    HideWindow();
    reinterpret_cast<RefPtr_ae0b90*>(&mpImage)->Fn005447b0(0);
    reinterpret_cast<RefPtr_ae0b90*>(&mpImageSmall)->Fn005447b0(0);
    return cGZWin::Slot04_ae1d24();
}

// FUNCTION: 0x009c4dd7
bool cGZWinSpinner::Slot15_ae0b00(uint32_t image)
{
    reinterpret_cast<RefPtr_ae0b90*>(&mpImage)->Fn005447b0(OB_PTR(void, image));
    Fn009c4d02();
    Fn009c4bbc();
    return true;
}

// FUNCTION: 0x009c4e00
bool cGZWinSpinner::Slot17_ae0b00(uint32_t rect)
{
    *reinterpret_cast<Rect_ae0b90*>(mnRect) = *OB_PTR(Rect_ae0b90, rect);
    Fn009c4d02();
    Fn009c4bbc();
    return true;
}

// FUNCTION: 0x009c4e28
bool cGZWinSpinner::Slot16_ae0b00(uint32_t out)
{
    *OB_PTR(void*, out) = mpImage;
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c5141 score 4
bool cGZWinSpinner::Slot04_ae0b00(uint32_t style)
{
    if (style != 0) {
        if (static_cast<int32_t>(style) < 0 || style > 2) {
            return false;
        }
        if (mpImageSmall == 0) {
            Slot20_ae0b00(mnImageId);
        }
    }
    mnButtonStyle = style;
    Fn009c4bbc();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c4d72 score 21
bool cGZWinSpinner::Slot14_ae0b00(uint32_t image, uint32_t rect)
{
    reinterpret_cast<RefPtr_ae0b90*>(&mpImage)->Fn005447b0(OB_PTR(void, image));
    if (rect != 0) {
        mnFlags |= 0x8000;
        Rect_ae0b90 r = *OB_PTR(Rect_ae0b90, rect);
        *reinterpret_cast<Rect_ae0b90*>(mnRect) = r;
    } else {
        mnFlags &= ~0x8000u;
        Fn009c4d02();
        Fn009c4bbc();
    }
    return true;
}
#endif

// ---- batch 2 ----

#define SP_AT_AE0B90(Type, base, off) (*reinterpret_cast<Type*>(reinterpret_cast<uint8_t*>(base) + (off)))

// The draw context the spinner paints through (slots used: 21 colour, 34 line, 35 fill, 38 image).
struct DrawCtx_ae0b90 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void SetColor(uint32_t color);
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
    virtual void FillRect(const Rect_ae0b90* rect);
    virtual void V36();
    virtual void V37();
    virtual void DrawImage(void* image, const Rect_ae0b90* src, const Rect_ae0b90* dest);
};

// The text object painted on the spinner (slot 52 draws a string).
struct TextObj_ae0b90 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void DrawText(void* ctx, const Rect_ae0b90* rect, const void* text, uint32_t length, uint32_t mode, uint32_t color, uint32_t back, uint32_t a, uint32_t b);
};

// The caption string at +0x50: a string object whose slot 27 formats.
struct Caption_ae0b90 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void Sprintf(const char* format, ...);
};

struct Timer_ae0b90 {
    // STUB: 0x0089058f
    void Restart();
    // STUB: 0x00890198
    uint32_t GetElapsedTime() const;
};

// The two formatters reached through the graphics manager (slots 16 and 18).
struct Formatter_ae0b90 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void FormatA(int32_t lo, int32_t hi, void* caption, uint32_t flag);
    virtual void V17();
    virtual void FormatB(int32_t lo, int32_t hi, void* caption);
};
struct Manager_ae0b90 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual Formatter_ae0b90* GetFormatter(uint32_t id);
};

// The interface half of the spinner, called by slot number where a pointer travels in a 32-bit slot.
struct Iface_ae0b90 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual bool Slot14(void* image, void* rect);
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual bool Slot19(void* image);
};

// STUB: 0x00913d7a
Manager_ae0b90* Fn00913d7a();
// STUB: 0x008d9900
void Fn008d9900(void* ctx, const Rect_ae0b90* rect, uint32_t color, bool raised, bool flag);
// STUB: 0x005dc950
bool Fn005dc950(const Rect_ae0b90* area, const Rect_ae0b90* other);

#ifdef OB_DRAFTS
// CLOSE: 0x009c4840 score 34
bool cGZWinSpinner::calc_mouse_pos(void* outv, int32_t x, int32_t y)
{
    int32_t* out = static_cast<int32_t*>(outv);
    if (!IsPointInWindowWindowCoordinates(x, y)) {
        *out = 0;
        return false;
    }
    int32_t half = GetH() / 2;
    if (mnButtonStyle == 0 || (mnButtonStyle == 1 && x >= static_cast<int32_t>(GetW()) - mnBtnW) || (mnButtonStyle != 0 && mnButtonStyle != 1 && x <= mnBtnW)) {
        *out = (y >= half) + 1;
        return true;
    }
    *out = 0;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c47d2 score 2
bool cGZWinSpinner::GZOnKeyDown(uint32_t key, uint32_t b)
{
    switch (key) {
    case 0x23:
        Slot09_ae0b00(mnMax);
        break;
    case 0x24:
        Slot09_ae0b00(mnMin);
        break;
    case 0x26:
        Slot09_ae0b00(mnStep + mnValue);
        break;
    case 0x28:
        Slot09_ae0b00(mnValue - mnStep);
        break;
    default:
        SendMsg(field4c, 5, key, b, 0);
        break;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c5073 score 4
bool cGZWinSpinner::GZOnMouseDownL(uint32_t a, uint32_t b, uint32_t c)
{
    calc_mouse_pos(&mnHeld, b, a);
    mnState = 0x190;
    reinterpret_cast<Timer_ae0b90*>(reinterpret_cast<uint8_t*>(this) + 0xe8)->Restart();
    if (mnHeld == 1) {
        Slot09_ae0b00(mnStep + mnValue);
    } else if (mnHeld == 2) {
        Slot09_ae0b00(mnValue - mnStep);
    }
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c50e3 score 4
bool cGZWinSpinner::GZOnMouseMove(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t before = mnCaptured;
    calc_mouse_pos(&mnCaptured, b, a);
    if (mnHeld != 0) {
        if (before == mnCaptured) {
            return true;
        }
        mnState = 0x190;
    } else {
        int32_t now = mnCaptured;
        if (before == now) {
            return true;
        }
        if (now == 0) {
            GZReleaseCapture();
        } else {
            Fn0099bdfe();
        }
    }
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c4b19 score 64
bool cGZWinSpinner::set_caption_from_value()
{
    if (mnFlags & 0x1000) {
        Caption_ae0b90* caption = reinterpret_cast<Caption_ae0b90*>(reinterpret_cast<uint8_t*>(this) + 0x50);
        if (mnFlags & 0x2000) {
            Manager_ae0b90* manager = Fn00913d7a();
            if (manager != 0) {
                Formatter_ae0b90* formatter = manager->GetFormatter(0);
                if (formatter != 0) {
                    formatter->FormatB(mnValue, mnValue >> 31, caption);
                }
            }
        } else if (mnFlags & 0x4000) {
            Manager_ae0b90* manager = Fn00913d7a();
            if (manager != 0) {
                Formatter_ae0b90* formatter = manager->GetFormatter(0);
                if (formatter != 0) {
                    formatter->FormatA(mnValue, mnValue >> 31, caption, 0);
                }
            }
        } else {
            caption->Sprintf("%d", mnValue);
        }
    }
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c4bfe score 52
bool cGZWinSpinner::Slot03_ae1d24()
{
    if (mnButtonStyle < 0 || mnButtonStyle > 2) {
        return false;
    }
    Wcm_ae0b90* wcm = Fn00913c72();
    if (mpImage == 0) {
        if (wcm != 0) {
            void* image = wcm->Find2(0x68963ed6, 0);
            reinterpret_cast<Iface_ae0b90*>(static_cast<cUnk00ae0b00*>(this))->Slot14(image, 0);
        }
    }
    if (wcm != 0 && mpImageSmall == 0 && mnButtonStyle != 0) {
        void* small = wcm->Find(mnImageId);
        if (small == 0) {
            small = wcm->Find(0x68963c4c);
        }
        reinterpret_cast<Iface_ae0b90*>(static_cast<cUnk00ae0b00*>(this))->Slot19(small);
    }
    if (GetW() < 1) {
        SetH(1);
    }
    if (GetH() < 1) {
        SetSize(1);
    }
    set_caption_from_value();
    return cGZWin::Slot03_ae1d24();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c4e36 score 41
void cGZWinSpinner::paint_btns_flat(int32_t offset)
{
    Rect_ae0b90 r;
    int32_t left = SP_AT_AE0B90(int32_t, this, 0x24) + offset;
    r.mnLeft = left;
    r.mnTop = SP_AT_AE0B90(int32_t, this, 0x28);
    r.mnRight = mnBtnW + left;
    r.mnBottom = mnBtnH + r.mnTop;
    void* ctx = SP_AT_AE0B90(void*, this, 0x6c);
    bool pressed = mnHeld == 1 && mnCaptured == 1;
    Fn008d9900(ctx, &r, mnFrameColor, !pressed, true);
    r.mnTop += mnBtnH;
    r.mnBottom = SP_AT_AE0B90(int32_t, this, 0x30);
    pressed = mnHeld == 2 && mnCaptured == 2;
    Fn008d9900(ctx, &r, mnFrameColor, !pressed, true);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c4ed7 score 77
void cGZWinSpinner::paint_btns_image(int32_t offset)
{
    int32_t half = static_cast<int32_t>(GetH()) / 2;
    bool enabled = Slot67_adc8d8(2) != 0;
    int32_t left = SP_AT_AE0B90(int32_t, this, 0x24) + offset;
    Rect_ae0b90 dest;
    Rect_ae0b90 src;
    dest.mnLeft = left;
    dest.mnTop = (half - mnBtnH) / 2 + SP_AT_AE0B90(int32_t, this, 0x28);
    dest.mnRight = mnBtnW + left;
    dest.mnBottom = dest.mnTop + mnBtnH;
    src.mnTop = mnBtnY;
    src.mnBottom = src.mnTop + mnBtnH;
    DrawCtx_ae0b90* ctx = SP_AT_AE0B90(DrawCtx_ae0b90*, this, 0x6c);
    if (enabled) {
        int32_t x;
        if (mnHeld == 0) {
            x = mnCaptured == 1 ? mnBtnX + mnBtnW * 3 : mnBtnX + mnBtnW;
        } else if (mnHeld == 1) {
            x = mnCaptured == 1 ? mnBtnX + mnBtnW * 2 : mnBtnX + mnBtnW;
        } else {
            x = mnBtnX + mnBtnW;
        }
        src.mnLeft = x;
        src.mnRight = mnBtnW + x;
        ctx->DrawImage(mpImage, &src, &dest);
        src.mnTop += mnBtnH;
        src.mnBottom += mnBtnH;
        dest.mnTop += half;
        dest.mnBottom += half;
        if (mnHeld == 0) {
            x = mnCaptured == 2 ? mnBtnX + mnBtnW * 3 : mnBtnX + mnBtnW;
        } else if (mnHeld == 2) {
            x = mnCaptured == 2 ? mnBtnX + mnBtnW * 2 : mnBtnX + mnBtnW;
        } else {
            x = mnBtnX + mnBtnW;
        }
        src.mnLeft = x;
        src.mnRight = mnBtnW + x;
    } else {
        src.mnLeft = mnBtnX;
        src.mnRight = mnBtnW + mnBtnX;
        ctx->DrawImage(mpImage, &src, &dest);
        src.mnTop += mnBtnH;
        src.mnBottom += mnBtnH;
        dest.mnTop += half;
        dest.mnBottom += half;
    }
    ctx = SP_AT_AE0B90(DrawCtx_ae0b90*, this, 0x6c);
    ctx->DrawImage(mpImage, &src, &dest);
}
#endif

// FUNCTION: 0x009c517b
bool cGZWinSpinner::Slot09_ae0b00(uint32_t value)
{
    int32_t v = static_cast<int32_t>(value);
    if (v < mnMin) {
        v = mnMin;
    }
    if (v > mnMax) {
        v = mnMax;
    }
    bool changed = mnValue != v;
    mnValue = v;
    if (changed) {
        set_caption_from_value();
        SendMsg(field4c, 0x682876c9, Slot48_adda20(), mnValue, 0);
    }
    return true;
}

// FUNCTION: 0x009c51db
bool cGZWinSpinner::Slot19_ae0b00(uint32_t image)
{
    void* img = OB_PTR(void, image);
    if (img != mpImageSmall) {
        reinterpret_cast<RefPtr_ae0b90*>(&mpImageSmall)->Fn005447b0(img);
        if (mpImageSmall != 0) {
            mnImageWidth = static_cast<uint16_t>(reinterpret_cast<Image_ae0b90*>(mpImageSmall)->GetWidth(0, 0));
        }
        Fn009c4bbc();
    }
    return true;
}

// FUNCTION: 0x009c5238
bool cGZWinSpinner::Slot31_ae0b00(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    mnTextColors[0] = ConvertNativeToPackedRGB(a);
    mnTextColors[1] = ConvertNativeToPackedRGB(b);
    mnTextColors[2] = ConvertNativeToPackedRGB(c);
    mnTextColors[3] = ConvertNativeToPackedRGB(d);
    InvalidateSelfAndParents();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c52a3 score 54
bool cGZWinSpinner::Slot06_ae0b00(uint32_t flag, uint32_t on)
{
    if (static_cast<uint8_t>(on) != 0) {
        mnFlags |= flag;
    } else {
        mnFlags &= ~flag;
    }
    int32_t f = static_cast<int32_t>(flag);
    if (f > 0) {
        if (f <= 2) {
            InvalidateSelfAndParents();
        } else if (f == 0x2000) {
            if (static_cast<uint8_t>(on) != 0) {
                SP_AT_AE0B90(uint8_t, this, 0xdd) &= 0xbf;
            }
            set_caption_from_value();
        } else if (f == 0x4000) {
            if (static_cast<uint8_t>(on) != 0) {
                SP_AT_AE0B90(uint8_t, this, 0xdd) &= 0xdf;
            }
            set_caption_from_value();
        } else if (f == 0x8000) {
            Fn009c4d02();
            Fn009c4bbc();
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c54a2 score 24
void cGZWinSpinner::Slot07_add348(uint32_t l, uint32_t t, uint32_t r, uint32_t b)
{
    int32_t w = static_cast<int32_t>(r - l);
    int32_t h = static_cast<int32_t>(b - t);
    if (mpImage != 0) {
        int32_t minW;
        int32_t minH;
        if (mnButtonStyle == 0) {
            minH = mnBtnH * 2;
            minW = mnBtnW;
        } else {
            minW = mnBtnW + mbFlag154 * 2;
            minH = mnImageWidth + mbFlag155 * 2;
            if (mnBtnH * 2 > minH) {
                minH = mnBtnH * 2;
            }
        }
        if (w < minW) {
            w = minW;
        }
        if (h < minH) {
            h = minH;
        }
    } else if (mnButtonStyle == 0) {
        int32_t m = mnMinBtn;
        if (w < m) {
            w = m;
        }
        if (h < m) {
            h = m;
        }
        mnBtnH = h / 2;
        mnBtnW = w;
    } else {
        int32_t minH = mnImageWidth + mbFlag155 * 2;
        int32_t minW = mnMinBtn + mbFlag154 * 2;
        if (h < minH) {
            h = minH;
        }
        if (w < minW) {
            w = minW;
        }
        int32_t half = h / 2;
        mnBtnH = half;
        mnBtnW = half;
        if (half < static_cast<int32_t>(mnMinBtn)) {
            mnBtnW = mnMinBtn;
        } else if (half > static_cast<int32_t>(mnMaxBtn)) {
            mnBtnW = mnMaxBtn;
        }
    }
    Rect_ae0b90 area;
    area.mnLeft = l;
    area.mnTop = t;
    area.mnRight = l + w;
    area.mnBottom = h + t;
    if (!Fn005dc950(static_cast<const Rect_ae0b90*>(GetArea_2()), &area)) {
        cGZWin::Slot07_add348(l, t, area.mnRight, area.mnBottom);
        InvalidateSelfAndParents();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c55f3 score 338
bool cGZWinSpinner::GZPaint()
{
    Rect_ae0b90 text;
    Rect_ae0b90 frame;
    int32_t offset = 0;
    bool hasText;
    bool fill;
    bool border;
    int32_t style = mnButtonStyle;
    if (style == 1) {
        int32_t base = static_cast<int32_t>(GetW()) - mnBtnW;
        int32_t left = SP_AT_AE0B90(int32_t, this, 0x24);
        frame.mnTop = SP_AT_AE0B90(int32_t, this, 0x28);
        frame.mnLeft = left;
        frame.mnRight = left - mbFlag154 + base;
        frame.mnBottom = SP_AT_AE0B90(int32_t, this, 0x30);
        text.mnLeft = left + mbFlag154;
        text.mnTop = (static_cast<int32_t>(GetH()) - static_cast<int16_t>(mnImageWidth)) / 2 + SP_AT_AE0B90(int32_t, this, 0x28);
        text.mnRight = frame.mnRight - mbFlag154;
        text.mnBottom = static_cast<int16_t>(mnImageWidth) + text.mnTop;
        offset = base;
    } else if (style == 2) {
        int32_t left = SP_AT_AE0B90(int32_t, this, 0x24) + mnBtnW + mbFlag154;
        frame.mnTop = SP_AT_AE0B90(int32_t, this, 0x28);
        frame.mnLeft = left;
        frame.mnRight = SP_AT_AE0B90(int32_t, this, 0x2c);
        frame.mnBottom = SP_AT_AE0B90(int32_t, this, 0x30);
        text.mnLeft = left + mbFlag154;
        text.mnTop = (static_cast<int32_t>(GetH()) - static_cast<int16_t>(mnImageWidth)) / 2 + SP_AT_AE0B90(int32_t, this, 0x28);
        text.mnRight = SP_AT_AE0B90(int32_t, this, 0x2c) - mbFlag154;
        text.mnBottom = static_cast<int16_t>(mnImageWidth) + text.mnTop;
    }
    hasText = (style == 1 || style == 2) && mpImageSmall != 0;
    fill = (style == 1 || style == 2) && ((mnFlags >> 1) & 1);
    border = (style == 1 || style == 2) && (mnFlags & 1);
    DrawCtx_ae0b90* ctx = SP_AT_AE0B90(DrawCtx_ae0b90*, this, 0x6c);
    if (border) {
        int32_t bottom = frame.mnBottom - 1;
        int32_t right = frame.mnRight - 1;
        int32_t l = frame.mnLeft;
        int32_t t = frame.mnTop;
        ctx->SetColor(mnTextColors[0]);
        ctx->DrawLine(l, t, l, bottom);
        ctx->SetColor(mnTextColors[1]);
        ctx->DrawLine(l, t, right, t);
        ctx->SetColor(mnTextColors[2]);
        ctx->DrawLine(right, t, right, bottom);
        ctx->SetColor(mnTextColors[3]);
        ctx->DrawLine(l, bottom, right, bottom);
        frame.mnLeft++;
        frame.mnRight--;
        frame.mnTop++;
        frame.mnBottom--;
    }
    if (fill) {
        ctx->SetColor(GetFillColorRGB());
        ctx->FillRect(&frame);
    }
    if (mpImage == 0) {
        paint_btns_flat(offset);
    } else {
        paint_btns_image(offset);
    }
    if (hasText) {
        uint32_t color;
        if (!Slot67_adc8d8(2)) {
            color = mnColors[2];
        } else if (mnCaptured == 0) {
            color = mnColors[0];
        } else {
            color = mnColors[1];
        }
        TextObj_ae0b90* obj = reinterpret_cast<TextObj_ae0b90*>(mpImageSmall);
        void* ctx2 = SP_AT_AE0B90(void*, this, 0x68);
        const void* begin = SP_AT_AE0B90(const void*, this, 0x54);
        uint32_t len = SP_AT_AE0B90(uint32_t, this, 0x58) - SP_AT_AE0B90(uint32_t, this, 0x54);
        if (color == 0xdeadbeef) {
            if (obj != 0) {
                obj->DrawText(ctx2, &text, begin, len, mnButtonMode, 0x8000000, 0x8000000, 0, 0);
            }
        } else if (obj != 0) {
            obj->DrawText(ctx2, &text, begin, len, mnButtonMode, ConvertPackedRGBToNative(color), 0x8000000, 0, 0);
        }
    }
    int32_t dir;
    if (mnHeld == 2 && mnCaptured == 2) {
        dir = -1;
    } else {
        dir = 1;
        if (mnHeld != 1 || mnCaptured != 1) {
            return true;
        }
    }
    Timer_ae0b90* timer = reinterpret_cast<Timer_ae0b90*>(reinterpret_cast<uint8_t*>(this) + 0xe8);
    if (timer->GetElapsedTime() > static_cast<uint32_t>(mnState) && dir != 0) {
        if (dir > 0) {
            Slot09_ae0b00(mnStep + mnValue);
        } else {
            Slot09_ae0b00(mnValue - mnStep);
        }
        if (static_cast<uint32_t>(mnState) > 0x32) {
            mnState -= 0x32;
        }
        timer->Restart();
        InvalidateSelfAndParents();
    }
    return true;
}
#endif
