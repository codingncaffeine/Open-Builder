#include <stddef.h>
#include "classes/cGZWinScrollbar.h"

// The press timer embedded at 0x130.
struct Timer_ae0810 {
    uint32_t mPad[6];

    // STUB: 0x0089058f
    void Restart_ae0810();
    // STUB: 0x00890198
    uint32_t GetElapsedTime_ae0810() const;
};

// A rectangle copied as a whole.
struct Rect_ae0810 {
    int32_t l;
    int32_t t;
    int32_t r;
    int32_t b;

    // STUB: 0x0082ae40
    void Fn0082ae40(const int32_t* point);
    // STUB: 0x00776f50
    void Fn00776f50(int32_t a, int32_t b);
};

// The drawing target at 0x6c: slot 38 draws a part of a buffer, slot 39 the same with two more arguments.
struct Dev_ae0810 {
    virtual void Pad0_ae0810();
    virtual void Pad1_ae0810();
    virtual void Pad2_ae0810();
    virtual void Pad3_ae0810();
    virtual void Pad4_ae0810();
    virtual void Pad5_ae0810();
    virtual void Pad6_ae0810();
    virtual void Pad7_ae0810();
    virtual void Pad8_ae0810();
    virtual void Pad9_ae0810();
    virtual void Pad10_ae0810();
    virtual void Pad11_ae0810();
    virtual void Pad12_ae0810();
    virtual void Pad13_ae0810();
    virtual void Pad14_ae0810();
    virtual void Pad15_ae0810();
    virtual void Pad16_ae0810();
    virtual void Pad17_ae0810();
    virtual void Pad18_ae0810();
    virtual void Pad19_ae0810();
    virtual void Pad20_ae0810();
    virtual void SetColor21_ae0810(uint32_t color);
    virtual void Pad22_ae0810();
    virtual void Pad23_ae0810();
    virtual void Pad24_ae0810();
    virtual void Pad25_ae0810();
    virtual void Pad26_ae0810();
    virtual void Pad27_ae0810();
    virtual void Pad28_ae0810();
    virtual void Pad29_ae0810();
    virtual void Pad30_ae0810();
    virtual void Pad31_ae0810();
    virtual void Pad32_ae0810();
    virtual void Pad33_ae0810();
    virtual void Pad34_ae0810();
    virtual void Fill35_ae0810(const Rect_ae0810* rect);
    virtual void Pad36_ae0810();
    virtual void Pad37_ae0810();
    virtual void Draw38_ae0810(void* buffer, const Rect_ae0810* src, const Rect_ae0810* dst);
    virtual void Draw39_ae0810(void* buffer, const Rect_ae0810* src, const Rect_ae0810* dst, uint32_t a, uint32_t b);
};

// The image buffer: AddRef and Release, and the rectangle slot.
struct Buf_ae0810 {
    virtual void Pad0_ae0810();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad3_ae0810();
    virtual void Pad4_ae0810();
    virtual void Pad5_ae0810();
    virtual void Pad6_ae0810();
    virtual void Pad7_ae0810();
    virtual void Pad8_ae0810();
    virtual void Pad9_ae0810();
    virtual void Pad10_ae0810();
    virtual void Pad11_ae0810();
    virtual const Rect_ae0810* GetRect12_ae0810();
};

// The hot flag and the part pressed, and the slider-level setters this class reaches.
inline Timer_ae0810* TimerOf_ae0810(uint8_t* p)
{
    return reinterpret_cast<Timer_ae0810*>(p);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c38fd score 4
bool cGZWinScrollbar::QueryInterface(uint32_t riid, void** out)
{
    if (riid == 0x61325a2d) {
        *out = static_cast<cUnk00ae0ab0*>(this);
        AddRef();
        return true;
    }
    return cGZWinSlider::QueryInterface(riid, out);
}
#endif

// FUNCTION: 0x009c392a
bool cGZWinScrollbar::GZOnMouseDownL(uint32_t a, uint32_t b, uint32_t /*c*/)
{
    if (DoCursorPositionHitTest(OB_ADDR(&mnPressedPart), a, b)) {
        mbPressedHot = true;
        if (Fn0099bdfe()) {
            TimerOf_ae0810(mTimer)->Restart_ae0810();
            InvalidateSelfAndParents();
            int32_t part = mnPressedPart;
            if (part == 1) {
                MoveLinePrevious();
            } else if (part == 2) {
                MoveLineNext();
            } else if (part == 3) {
                MovePagePrevious();
            } else if (part == 4) {
                MovePageNext();
            }
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c39bb score 13
bool cGZWinScrollbar::GZOnMouseUpL(uint32_t a, uint32_t b, uint32_t c)
{
    if (Fn0099be0a()) {
        Fn0099be1e();
        if (mnPressedPart == 5) {
            float percent;
            if (ConvertCursorPositionToPercentage(&percent, a, b)) {
                SetPercentage(percent);
            }
        }
        mnPressedPart = 0;
        InvalidateSelfAndParents();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c3a1c score 24
bool cGZWinScrollbar::GZOnMouseMove(uint32_t a, uint32_t b, uint32_t c)
{
    if (Fn0099be0a()) {
        if (mnPressedPart == 5) {
            float percent;
            if (ConvertCursorPositionToPercentage(&percent, a, b)) {
                SetPercentage(percent);
            }
        } else {
            int32_t part;
            if (!DoCursorPositionHitTest(OB_ADDR(&part), a, b)) {
                mbPressedHot = false;
            } else {
                mbPressedHot = part == mnPressedPart;
            }
        }
    }
    return true;
}
#endif

// FUNCTION: 0x009c3a92
void cGZWinScrollbar::MoveLinePrevious()
{
    if (mnLineCount != 0) {
        uint32_t step = static_cast<uint32_t>(mnMax - mnMin) / mnLineCount;
        cUnk00ae074c* slider = this;
        slider->Slot05_ae074c(slider->Slot04_ae074c() - step);
    }
}

// FUNCTION: 0x009c3aca
void cGZWinScrollbar::MoveLineNext()
{
    if (mnLineCount != 0) {
        uint32_t step = static_cast<uint32_t>(mnMax - mnMin) / mnLineCount;
        cUnk00ae074c* slider = this;
        slider->Slot05_ae074c(slider->Slot04_ae074c() + step);
    }
}

// FUNCTION: 0x009c3b02
void cGZWinScrollbar::MovePagePrevious()
{
    if (mnPageCount != 0) {
        uint32_t step = static_cast<uint32_t>(mnMax - mnMin + 1) / mnPageCount;
        cUnk00ae074c* slider = this;
        slider->Slot05_ae074c(slider->Slot04_ae074c() - step);
    }
}

// FUNCTION: 0x009c3b3b
void cGZWinScrollbar::MovePageNext()
{
    if (mnPageCount != 0) {
        uint32_t step = static_cast<uint32_t>(mnMax - mnMin + 1) / mnPageCount;
        cUnk00ae074c* slider = this;
        slider->Slot05_ae074c(slider->Slot04_ae074c() + step);
    }
}

// FUNCTION: 0x009c3b74
void cGZWinScrollbar::Slot15_ae0ab0(uint32_t a, uint32_t b)
{
    if (a == 0) {
        a = static_cast<uint32_t>(mnMax - mnMin);
    }
    mnLineCount = a;
    if (b == 0) {
        mnPageCount = 1;
    } else {
        mnPageCount = b;
    }
    Slot153_ae04d8();
}

// FUNCTION: 0x009c3baa
void cGZWinScrollbar::Slot16_ae0ab0(uint32_t a, uint32_t b)
{
    *OB_PTR(uint32_t, a) = mnLineCount;
    *OB_PTR(uint32_t, b) = mnPageCount;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c3bbf score 21
uint32_t cGZWinScrollbar::GetCurrentLine()
{
    int32_t range = mnMax - mnMin;
    if (mnLineCount == 1) {
        return 0;
    }
    cUnk00ae074c* slider = this;
    int32_t pos = static_cast<int32_t>(slider->Slot04_ae074c()) - mnMin;
    return static_cast<uint32_t>(static_cast<double>(pos) * static_cast<double>(mnLineCount - 1) / static_cast<double>(range));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c3c20 score 8
uint32_t cGZWinScrollbar::GetValueOfGivenLine(uint32_t line)
{
    uint32_t lines = mnLineCount;
    if (lines == 1) {
        return mnMin;
    }
    int32_t base = mnMin;
    int32_t range = mnMax - base;
    return static_cast<uint32_t>(static_cast<double>(range) * static_cast<double>(line) / static_cast<double>(lines - 1)) + base;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c3c7d score 21
uint32_t cGZWinScrollbar::GetCurrentPage()
{
    int32_t range = mnMax - mnMin;
    if (mnPageCount == 1) {
        return 0;
    }
    cUnk00ae074c* slider = this;
    int32_t pos = static_cast<int32_t>(slider->Slot04_ae074c()) - mnMin;
    return static_cast<uint32_t>(static_cast<double>(pos) * static_cast<double>(mnPageCount - 1) / static_cast<double>(range));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c3cde score 8
uint32_t cGZWinScrollbar::GetValueOfGivenPage(uint32_t page)
{
    uint32_t pages = mnPageCount;
    if (pages == 1) {
        return mnMin;
    }
    int32_t base = mnMin;
    int32_t range = mnMax - base;
    return static_cast<uint32_t>(static_cast<double>(range) * static_cast<double>(page) / static_cast<double>(pages - 1)) + base;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c3d3b score 68
bool cGZWinScrollbar::DoCursorPositionHitTest(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t* out = OB_PTR(uint32_t, a);
    if (!IsPointInWindowWindowCoordinates(b, c)) {
        *out = 0;
        return false;
    }
    int32_t end;
    int32_t pos;
    if (mnMode == 1) {
        int32_t lead = Slot162_ae0810();
        c = lead;
        if (static_cast<int32_t>(b) < lead) {
            *out = 1;
            return true;
        }
        pos = b;
        if (pos < mnF0) {
            *out = 3;
            return true;
        }
        if (pos < static_cast<int32_t>(GetThumbWidth()) + mnF0) {
            *out = 5;
            return true;
        }
        end = GetW() - lead;
    } else {
        int32_t lead = Slot163_ae0810();
        b = lead;
        pos = static_cast<int32_t>(c);
        if (pos < lead) {
            *out = 1;
            return true;
        }
        if (pos < mnF0) {
            *out = 3;
            return true;
        }
        if (pos < static_cast<int32_t>(GetThumbHeight()) + mnF0) {
            *out = 5;
            return true;
        }
        end = GetH() - lead;
    }
    *out = (pos < end) ? 4 : 2;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c3e16 score 16
void cGZWinScrollbar::Slot153_ae04d8()
{
    int32_t lead;
    int32_t extent;
    int32_t thumb;
    if (mnMode == 1) {
        mnEC = Slot162_ae0810();
        lead = Slot162_ae0810();
        extent = GetW() - lead;
        thumb = GetThumbWidth();
    } else {
        mnEC = Slot163_ae0810();
        lead = Slot163_ae0810();
        extent = GetH() - lead;
        thumb = GetThumbHeight();
    }
    mnF4 = extent - thumb;
    CalculateThumbPosition();
}
#endif

// FUNCTION: 0x009c3e9d
uint32_t cGZWinScrollbar::Slot162_ae0810()
{
    return GetThumbWidth();
}

// FUNCTION: 0x009c3ea5
uint32_t cGZWinScrollbar::Slot163_ae0810()
{
    return GetThumbHeight();
}

// FUNCTION: 0x009c3eb7
uint32_t cGZWinScrollbar::Slot04_ae0ab0()
{
    return OB_ADDR(static_cast<cUnk00ae074c*>(this));
}

// FUNCTION: 0x009c3ec7
bool cGZWinScrollbar::Slot09_ae0ab0(uint32_t a)
{
    switch (a) {
    case 1:
        mnMode = 1;
        break;
    case 2:
        mnMode = 2;
        break;
    default:
        mnMode = 0;
        break;
    }
    return true;
}

// FUNCTION: 0x009c3eec
uint32_t cGZWinScrollbar::Slot10_ae0ab0()
{
    switch (mnMode) {
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        return 0;
    }
}

// FUNCTION: 0x009c3f00
bool cGZWinScrollbar::Slot11_ae0ab0(uint32_t a)
{
    if (a == 0) {
        return false;
    }
    mnPageCount = (mnMax - mnMin) / static_cast<int32_t>(a);
    Slot153_ae04d8();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c3f2f score 13
void cGZWinScrollbar::Slot12_ae0ab0()
{
    // The original returns the page size in eax; the base declares void.
    if (mnPageCount != 0) {
        uint32_t size = static_cast<uint32_t>(mnMax - mnMin + 1) / mnPageCount;
        (void)size;
    }
}
#endif

// FUNCTION: 0x009c3f48
bool cGZWinScrollbar::Slot13_ae0ab0(uint32_t a)
{
    if (a == 0) {
        return false;
    }
    mnLineCount = (mnMax - mnMin) / static_cast<int32_t>(a);
    Slot153_ae04d8();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c3f77 score 12
void cGZWinScrollbar::Slot14_ae0ab0()
{
    // The original returns the line size in eax; the base declares void.
    if (mnLineCount != 0) {
        uint32_t size = static_cast<uint32_t>(mnMax - mnMin) / mnLineCount;
        (void)size;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c3f8f score 6
bool cGZWinScrollbar::Slot07_ae0ab0(uint32_t a, uint32_t b)
{
    cUnk00ae074c* slider = this;
    slider->Slot06_ae074c(a);
    slider->Slot08_ae074c(b);
    return true;
}
#endif

// FUNCTION: 0x009c3faf
bool cGZWinScrollbar::Slot08_ae0ab0(uint32_t a, uint32_t b)
{
    *OB_PTR(int32_t, a) = mnMin;
    *OB_PTR(int32_t, b) = mnMax;
    return true;
}

// FUNCTION: 0x009c3fc6
void cGZWinScrollbar::Slot17_ae0ab0(uint32_t a, uint32_t b, uint32_t /*c*/)
{
    Slot12_ae074c(b, a);
}

// FUNCTION: 0x009c3fd9
bool cGZWinScrollbar::Slot18_ae0ab0(uint32_t a, uint32_t b, uint32_t c)
{
    *OB_PTR(Rect_ae0810, a) = *reinterpret_cast<Rect_ae0810*>(mnRect);
    void** buffer = OB_PTR(void*, b);
    *buffer = mpChild;
    *OB_PTR(uint32_t, c) = 0;
    return *buffer != 0;
}

// FUNCTION: 0x009c4004
bool cGZWinScrollbar::Slot19_ae0ab0(uint32_t a)
{
    int32_t* rect = OB_PTR(int32_t, a);
    if (mnMode == 1) {
        rect[0] = GetThumbWidth() * 3;
        rect[1] = GetThumbHeight();
        rect[2] = 0xffff;
        rect[3] = GetThumbHeight();
    } else if (mnMode == 2) {
        rect[0] = GetThumbWidth();
        rect[1] = GetThumbHeight() * 3;
        rect[2] = GetThumbWidth();
        rect[3] = 0xffff;
    } else {
        return false;
    }
    return true;
}

// FUNCTION: 0x009c453d
bool cGZWinScrollbar::GZPaint()
{
    if (Fn0099be0a() && mbPressedHot && mnPressedPart >= 1 && mnPressedPart <= 4) {
        Timer_ae0810* timer = TimerOf_ae0810(mTimer);
        if (timer->GetElapsedTime_ae0810() > 200) {
            int32_t part = mnPressedPart;
            if (part == 1) {
                MoveLinePrevious();
            } else if (part == 2) {
                MoveLineNext();
            } else if (part == 3) {
                MovePagePrevious();
            } else if (part == 4) {
                MovePageNext();
            }
            timer->Restart_ae0810();
        }
        InvalidateSelfAndParents();
    }
    if (mpChild != 0) {
        PaintBmp();
    } else {
        PaintFlat();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c45f0 score 23
bool cGZWinScrollbar::Slot12_ae074c(uint32_t a, uint32_t b)
{
    Buf_ae0810* buffer = OB_PTR(Buf_ae0810, a);
    if (buffer) {
        buffer->AddRef();
    }
    Buf_ae0810* old = static_cast<Buf_ae0810*>(mpChild);
    if (old) {
        old->Release();
    }
    mpChild = buffer;
    if (!buffer) {
        return true;
    }
    bool done = false;
    Rect_ae0810 rect = *buffer->GetRect12_ae0810();
    if (b) {
        rect = *OB_PTR(Rect_ae0810, b);
    }
    int32_t cell = (rect.r - rect.l) / 12;
    mnRect[0] = rect.l;
    mnRect[1] = rect.t;
    mnRect[2] = rect.l + cell;
    mnRect[3] = rect.t + (rect.b - rect.t);
    if (mnMode == 1) {
        SetH(cell);
        mnRect[0] += cell * 6;
        mnRect[2] += cell * 6;
        done = true;
    } else if (mnMode == 2) {
        SetSize(rect.b - rect.t);
        done = true;
    }
    return done;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c4342 score 197
bool cGZWinScrollbar::PaintFlat()
{
    int32_t tw = GetThumbWidth();
    int32_t th = GetThumbHeight();
    Dev_ae0810* dev = OB_PTR(Dev_ae0810, field6c);
    int32_t* box = reinterpret_cast<int32_t*>(&field24[0]);
    Rect_ae0810 r;
    int32_t lim;
    if (mnMode == 1) {
        dev->SetColor21_ae0810(GetFillColorRGB());
        r.l = box[0];
        r.t = box[1];
        r.r = box[0] + tw;
        r.b = box[1] + th;
        dev->Fill35_ae0810(&r);
        lim = box[2] - tw;
        dev->SetColor21_ae0810(~GetFillColorRGB());
        r.l = box[0] + tw;
        r.t = box[1];
        r.r = lim;
        r.b = box[1] + th;
        dev->Fill35_ae0810(&r);
        dev->SetColor21_ae0810(GetFillColorRGB());
        r.l = lim;
        r.t = box[1];
        r.r = lim + tw;
        r.b = box[1] + th;
        dev->Fill35_ae0810(&r);
        r.l = mnFC + box[0];
        r.t = box[1];
    } else {
        dev->SetColor21_ae0810(GetFillColorRGB());
        r.l = box[0];
        r.t = box[1];
        r.r = box[0] + tw;
        r.b = box[1] + th;
        dev->Fill35_ae0810(&r);
        lim = box[3] - th;
        dev->SetColor21_ae0810(~GetFillColorRGB());
        r.l = box[0];
        r.t = box[1] + th;
        r.r = box[0] + tw;
        r.b = lim;
        dev->Fill35_ae0810(&r);
        dev->SetColor21_ae0810(GetFillColorRGB());
        r.l = box[0];
        r.t = lim;
        r.r = box[0] + tw;
        r.b = lim + th;
        dev->Fill35_ae0810(&r);
        r.l = box[0];
        r.t = mn100 + box[1];
    }
    r.r = r.l + tw;
    r.b = r.t + th;
    dev->Fill35_ae0810(&r);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c40f4 score 224
bool cGZWinScrollbar::PaintBmp()
{
    Rect_ae0810* rc = reinterpret_cast<Rect_ae0810*>(mnRect);
    int32_t cell = rc->r - rc->l;
    int32_t cellH = rc->b - rc->t;
    Rect_ae0810 src = *rc;
    Rect_ae0810 dst = *rc;
    Dev_ae0810* dev = OB_PTR(Dev_ae0810, field6c);
    int32_t* box = reinterpret_cast<int32_t*>(&field24[0]);
    if (mnMode == 1) {
        if (mnPressedPart == 1) {
            src.l += cell;
            src.r += cell;
        }
        dst.Fn0082ae40(box);
        dev->Draw38_ae0810(mpChild, &src, &dst);
        src = *rc;
        src.l += cell * 3;
        src.r += cell * 3;
        dst.l = dst.r;
        dst.r = box[2] - cell;
        dev->Draw39_ae0810(mpChild, &src, &dst, 0, 0);
        src = *rc;
        src.l += (mnPressedPart == 2) ? cell * 5 : cell * 4;
        src.r += (mnPressedPart == 2) ? cell * 5 : cell * 4;
        dst.l = dst.r;
        dst.r = box[2];
        dev->Draw38_ae0810(mpChild, &src, &dst);
        src = *rc;
        src.l += cell * 2;
        src.r += cell * 2;
        dst = src;
        dst.Fn00776f50(box[0] + mnF8 + cell, box[1] + cellH);
        dev->Draw38_ae0810(mpChild, &src, &dst);
    } else {
        if (mnPressedPart == 1) {
            src.l += cell;
            src.r += cell;
        }
        dst.Fn0082ae40(box);
        dev->Draw38_ae0810(mpChild, &src, &dst);
        src = *rc;
        src.l += cell * 3;
        src.r += cell * 3;
        dst.t = dst.b;
        dst.b = box[3] - cellH;
        dev->Draw39_ae0810(mpChild, &src, &dst, 0, 0);
        src = *rc;
        src.l += (mnPressedPart == 2) ? cell * 5 : cell * 4;
        src.r += (mnPressedPart == 2) ? cell * 5 : cell * 4;
        dst.t = dst.b;
        dst.b = box[3];
        dev->Draw38_ae0810(mpChild, &src, &dst);
        src = *rc;
        src.l += cell * 2;
        src.r += cell * 2;
        dst = src;
        dst.Fn00776f50(box[0] + cell, box[1] + mn100 + cellH);
        dev->Draw38_ae0810(mpChild, &src, &dst);
    }
    return true;
}
#endif
