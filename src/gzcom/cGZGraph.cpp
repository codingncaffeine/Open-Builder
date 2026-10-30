#include "classes/cGZGraph.h"
#include <algorithm>
#include "gzcom/cIGZUnknown.h"
#include "classes/cUnk00ade0d4.h"

// A 16-byte record (a rectangle) copied as a whole.
struct Rect_ade188 {
    int32_t v[4];
};

// A rectangle with named sides.
struct Sides_ade188 {
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
};

// The drawing buffer the class draws into, seen through the slots it calls (slot numbers follow the buffer interface).
// A color type: two words built by the constructor from a kind.
struct ColorType_ade188 {
    uint32_t mWords[2];
    // STUB: 0x0044a490
    ColorType_ade188(uint32_t kind);
};

struct Buffer_ade188 {
    virtual void P00();
    virtual void P01();
    virtual uint32_t Release();
    virtual bool Init(uint32_t width, uint32_t height, ColorType_ade188 type);
    virtual void P04();
    virtual void P05();
    virtual bool Lock(uint32_t flags);
    virtual bool Unlock(uint32_t flags);
    virtual bool IsLocked();
    virtual void P09();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual uint32_t Slot17();
    virtual bool Fill1(uint32_t color, const void* rect);
    virtual void P19();
    virtual bool Fill3(uint32_t color, const void* rect, uint32_t flags);
    virtual void P21();
    virtual void P22();
    virtual void SetTransparency(uint32_t color);
    virtual bool Slot24();
    virtual void P25();
    virtual bool GetTransparentColor(uint32_t* color);
    virtual void P27();
    virtual bool DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color, uint32_t flags);
    virtual bool Blt(uint32_t source, uint32_t sourceRect, uint32_t destRect, uint32_t flags);
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual uint8_t* GetColorSurfaceBits();
    virtual int32_t GetColorSurfaceStride();
};

// STUB: 0x00931180
void Fn00931180(uint32_t buffer, uint32_t rect, uint32_t outlineColor, uint32_t fillColor);

// FUNCTION: 0x009b1eb0
bool cGZGraph::GZOnMouseDownL(uint32_t, uint32_t, uint32_t)
{
    Fn0099bdfe();
    return true;
}

// FUNCTION: 0x009b1ea0
bool cGZGraph::GZPaint()
{
    Slot14_addff8(0);
    return true;
}

// SetGraphAreaOutlineAndFill: the two arguments are really bools (the slot is declared in cUnk00addff8 with uint32_t).
// FUNCTION: 0x009b1f69
void cGZGraph::Slot08_addff8(uint32_t outline, uint32_t fill)
{
    mbGraphAreaOutline = *reinterpret_cast<bool*>(&outline);
    mbGraphAreaFill = *reinterpret_cast<bool*>(&fill);
}

// SetGraphArea(const cRZRect&): the argument is a pointer.
// FUNCTION: 0x009b1f1d
void cGZGraph::Slot12_addff8(uint32_t rect)
{
    *reinterpret_cast<Rect_ade188*>(&mnGraphArea[0]) = *OB_PTR(const Rect_ade188, rect);
}

// GetGraphArea(cRZRect&): the argument is a pointer.
// FUNCTION: 0x009b1f2f
void cGZGraph::Slot13_addff8(uint32_t rect)
{
    *OB_PTR(Rect_ade188, rect) = *reinterpret_cast<const Rect_ade188*>(&mnGraphArea[0]);
}

// SetAxisMinValue(Axis, float): the value is a float.
// FUNCTION: 0x009b1fdc
void cGZGraph::Slot15_addff8(uint32_t axis, uint32_t value)
{
    mfAxisMin[axis] = *reinterpret_cast<float*>(&value);
}

// SetAxisMaxValue(Axis, float)
// FUNCTION: 0x009b1fee
void cGZGraph::Slot16_addff8(uint32_t axis, uint32_t value)
{
    mfAxisMax[axis] = *reinterpret_cast<float*>(&value);
}

// SetAxisZeroPosition(Axis, long)
// FUNCTION: 0x009b2000
void cGZGraph::Slot17_addff8(uint32_t axis, uint32_t position)
{
    mnAxisZeroPosition[axis] = position;
}

// SetAxisLabelRotation(Axis, GraphRotation)
// FUNCTION: 0x009b207b
void cGZGraph::Slot22_addff8(uint32_t axis, uint32_t rotation)
{
    mnAxisLabelRotation[axis] = rotation;
}

// SetMajorTickSpacing(Axis, float)
// FUNCTION: 0x009b20a0
void cGZGraph::Slot24_addff8(uint32_t axis, uint32_t spacing)
{
    mfMajorTickSpacing[axis] = *reinterpret_cast<float*>(&spacing);
}

// SetMajorTickLength(Axis, long)
// FUNCTION: 0x009b214f
void cGZGraph::Slot28_addff8(uint32_t axis, uint32_t length)
{
    mnMajorTickLength[axis] = length;
}

// SetMinorTickSpacing(Axis, float)
// FUNCTION: 0x009b21d3
void cGZGraph::Slot33_addff8(uint32_t axis, uint32_t spacing)
{
    mfMinorTickSpacing[axis] = *reinterpret_cast<float*>(&spacing);
}

// SetMinorTickLength(Axis, long)
// FUNCTION: 0x009b2296
void cGZGraph::Slot36_addff8(uint32_t axis, uint32_t length)
{
    mnMinorTickLength[axis] = length;
}

// SetTitlePosition(cRZRect&): the argument is a pointer.
// FUNCTION: 0x009b22b5
void cGZGraph::Slot38_addff8(uint32_t rect)
{
    *reinterpret_cast<Rect_ade188*>(&mnTitleArea[0]) = *OB_PTR(const Rect_ade188, rect);
}

// ---- batch 2 ----

// The container of the dynamic objects: the graph holds one word of it, its member functions are the original's.
struct DynamicList_ade188 {
    // STUB: 0x0092f4d7
    void Fn0092f4d7(const uint32_t* object);
    // STUB: 0x008f6e80
    void Fn008f6e80(const uint32_t* object);
};

// SetMajorTickUsage(Axis, Usage)
// FUNCTION: 0x009b208d
void cGZGraph::Slot23_addff8(uint32_t axis, uint32_t usage)
{
    mbMajorTickUsage[axis] = usage != 0;
}

// SetMajorTickGridUsage(Axis, Usage)
// FUNCTION: 0x009b211a
void cGZGraph::Slot26_addff8(uint32_t axis, uint32_t usage)
{
    mbMajorTickGrid[axis] = usage != 0;
}

// SetAxisTickTextDrawing(Axis, Usage)
// FUNCTION: 0x009b2161
void cGZGraph::Slot30_addff8(uint32_t axis, uint32_t usage)
{
    mbTickText[axis] = usage != 0;
}

// SetMinorTickUsage(Axis, Usage)
// FUNCTION: 0x009b21c0
void cGZGraph::Slot32_addff8(uint32_t axis, uint32_t usage)
{
    mbMinorTickUsage[axis] = usage == 1;
}

// SetMinorTickGridUsage(Axis, Usage)
// FUNCTION: 0x009b2283
void cGZGraph::Slot35_addff8(uint32_t axis, uint32_t usage)
{
    mbMinorTickGrid[axis] = usage == 1;
}

// SetMajorTickDecimalPlaces(Axis, long): the count is kept between 0 and 9.
// FUNCTION: 0x009b212d
void cGZGraph::Slot27_addff8(uint32_t axis, uint32_t places)
{
    int32_t count = places;
    if (count < 0) {
        count = 0;
    } else if (count > 9) {
        count = 9;
    }
    mnMajorTickDecimals[axis] = static_cast<uint8_t>(count);
}

// FUNCTION: 0x009b1eba
bool cGZGraph::GZOnMouseUpL(uint32_t, uint32_t, uint32_t)
{
    if (GZAmCapturing()) {
        GZReleaseCapture();
    }
    return true;
}

// FUNCTION: 0x009b1ed3
bool cGZGraph::GZOnMouseMove(uint32_t x, uint32_t y, uint32_t)
{
    if (GZAmCapturing()) {
        IsPointInWindowWindowCoordinates(x, y);
    }
    return true;
}

// SetArea(long, long, long, long)
// FUNCTION: 0x009b1ef7
void cGZGraph::Slot07_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    cGZWin::Slot07_add348(a, b, c, d);
    InvalidateSelfAndParents();
}

// SetBackgroundPattern(cIGZBuffer*): the argument is a pointer; the pattern is a counted reference.
// FUNCTION: 0x009b1f8e
void cGZGraph::Slot07_addff8(uint32_t pattern)
{
    cIGZUnknown* held = OB_PTR(cIGZUnknown, pattern);
    if (held) {
        held->AddRef();
    }
    cIGZUnknown* old = static_cast<cIGZUnknown*>(mpBackgroundPattern);
    if (old) {
        old->Release();
    }
    mpBackgroundPattern = held;
}

// SetGraphBackgroundPattern(cIGZBuffer*)
// FUNCTION: 0x009b1fb5
void cGZGraph::Slot11_addff8(uint32_t pattern)
{
    cIGZUnknown* held = OB_PTR(cIGZUnknown, pattern);
    if (held) {
        held->AddRef();
    }
    cIGZUnknown* old = static_cast<cIGZUnknown*>(mpGraphBackgroundPattern);
    if (old) {
        old->Release();
    }
    mpGraphBackgroundPattern = held;
}

// SetAxisLabelPosition(Axis, cRZRect&): the rectangle is a pointer.
// FUNCTION: 0x009b2012
void cGZGraph::Slot20_addff8(uint32_t axis, uint32_t rect)
{
    reinterpret_cast<Rect_ade188*>(mnAxisLabelArea)[axis] = *OB_PTR(const Rect_ade188, rect);
}

// RemoveDynamicGraphObject(DynamicGraphObject*): the argument is a pointer, passed on by address.
// FUNCTION: 0x009b695c
void cGZGraph::Slot48_addff8(uint32_t object)
{
    reinterpret_cast<DynamicList_ade188*>(&mpDynamicObjects)->Fn0092f4d7(&object);
}

// AddDynamicGraphObject(DynamicGraphObject*)
// FUNCTION: 0x009b6a64
void cGZGraph::Slot47_addff8(uint32_t object)
{
    reinterpret_cast<DynamicList_ade188*>(&mpDynamicObjects)->Fn008f6e80(&object);
}

// GetAutomaticAxisMinorTickSpacing(Axis, float&): half the major spacing.
// FUNCTION: 0x009b2417
void cGZGraph::Slot177_ade188(uint32_t axis, uint32_t spacing)
{
    *OB_PTR(float, spacing) = mfMajorTickSpacing[axis] * 0.5f;
}

// ---- batch 3 ----

// GetAutomaticAxisMinValue(Axis, float&): the lowest value, stretched by a ninth when negative, else 0.
// FUNCTION: 0x009b2301
void cGZGraph::Slot174_ade188(uint32_t axis, uint32_t value)
{
    float low = Slot165_ade188(axis);
    float* out = OB_PTR(float, value);
    *out = low;
    if (low >= 0.0f) {
        low = 0.0f;
    } else {
        low = low * 1.1111112f;
    }
    *out = low;
}

// GetAutomaticAxisMaxValue(Axis, float&)
// FUNCTION: 0x009b2333
void cGZGraph::Slot175_ade188(uint32_t axis, uint32_t value)
{
    float high = Slot164_ade188(axis);
    float* out = OB_PTR(float, value);
    *out = high;
    if (high <= 0.0f) {
        high = 0.0f;
    } else {
        high = high * 1.1111112f;
    }
    *out = high;
}

// SetTitleFont(cIGZFont*, unsigned long): the font is a pointer, held by a counted reference.
// FUNCTION: 0x009b22c7
void cGZGraph::Slot39_addff8(uint32_t font, uint32_t color)
{
    cIGZUnknown* held = OB_PTR(cIGZUnknown, font);
    if (held != mpTitleFont) {
        if (held) {
            held->AddRef();
        }
        cIGZUnknown* old = static_cast<cIGZUnknown*>(mpTitleFont);
        if (old) {
            old->Release();
        }
        mpTitleFont = held;
    }
    if (color != 0x80000000) {
        mnTitleFontColor = color;
    }
}

// SetAxisLabelFont(Axis, cIGZFont*, unsigned long)
// FUNCTION: 0x009b202f
void cGZGraph::Slot21_addff8(uint32_t axis, uint32_t font, uint32_t color)
{
    void** slot = &mpAxisLabelFont[axis];
    cIGZUnknown* held = OB_PTR(cIGZUnknown, font);
    if (held != *slot) {
        if (held) {
            held->AddRef();
        }
        cIGZUnknown* old = static_cast<cIGZUnknown*>(*slot);
        if (old) {
            old->Release();
        }
        *slot = held;
    }
    if (color != 0x80000000) {
        mnAxisLabelFontColor[axis] = color;
    }
}

// SetAxisTickFont(Axis, cIGZFont*, unsigned long)
// FUNCTION: 0x009b2174
void cGZGraph::Slot29_addff8(uint32_t axis, uint32_t font, uint32_t color)
{
    void** slot = &mpAxisTickFont[axis];
    cIGZUnknown* held = OB_PTR(cIGZUnknown, font);
    if (held != *slot) {
        if (held) {
            held->AddRef();
        }
        cIGZUnknown* old = static_cast<cIGZUnknown*>(*slot);
        if (old) {
            old->Release();
        }
        *slot = held;
    }
    if (color != 0x80000000) {
        mnAxisTickFontColor[axis] = color;
    }
}

// AllocateHitTestData(unsigned long): a new block when the old one is too small.
// FUNCTION: 0x009b25cc
bool cGZGraph::Slot41_addff8(uint32_t size)
{
    if (size > mnHitTestCapacity) {
        operator delete(mpHitTestData);
    }
    mnHitTestCapacity = size;
    mpHitTestData = operator new(size);
    return true;
}

// WindowPixelToGraphPixel(Axis, long)
// FUNCTION: 0x009b257a
uint32_t cGZGraph::Slot167_ade188(uint32_t axis, uint32_t pixel)
{
    if (axis == 0) {
        return pixel - mnGraphArea[0];
    }
    if (axis == 1) {
        return pixel - mnGraphArea[1];
    }
    return 0;
}

// GraphPixelToWindowPixel(Axis, long)
#ifdef OB_DRAFTS
// CLOSE: 0x009b25a5 score 7
uint32_t cGZGraph::Slot168_ade188(uint32_t axis, uint32_t pixel)
{
    uint32_t origin;
    if (axis == 0) {
        origin = mnGraphArea[0];
    } else if (axis == 1) {
        origin = mnGraphArea[1];
    } else {
        return 0;
    }
    return origin + pixel;
}
#endif

// DrawRectangleOutline(cIGZBuffer*, cRZRect const&, unsigned long, unsigned long)
// FUNCTION: 0x009b265d
void cGZGraph::Slot44_addff8(uint32_t buffer, uint32_t rect, uint32_t outlineColor, uint32_t fillColor)
{
    Fn00931180(buffer, rect, outlineColor, fillColor);
}

// DrawLine(cIGZBuffer*, long, long, long, long, long, unsigned long): locks the buffer when it is not locked yet.
// FUNCTION: 0x009b2602
bool cGZGraph::Slot43_addff8(uint32_t buffer, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color,
                             uint32_t flags)
{
    Buffer_ade188* target = OB_PTR(Buffer_ade188, buffer);
    bool locked = false;
    if (!target->IsLocked()) {
        if (!target->Lock(0x8004)) {
            return false;
        }
        locked = true;
    }
    bool result = target->DrawLine(x1, y1, x2, y2, color, flags);
    if (locked) {
        target->Unlock(0x8004);
    }
    return result;
}

// Blt(cIGZBuffer*, cIGZBuffer*, cRZRect const&, cRZRect const&): draws into the second buffer.
// FUNCTION: 0x009b2678
bool cGZGraph::Slot46_addff8(uint32_t source, uint32_t destination, uint32_t sourceRect, uint32_t destRect)
{
    Buffer_ade188* target = OB_PTR(Buffer_ade188, destination);
    bool locked = false;
    if (!target->IsLocked()) {
        if (!target->Lock(0x8010)) {
            return false;
        }
        locked = true;
    }
    bool result = target->Blt(source, sourceRect, destRect, 0);
    if (locked) {
        target->Unlock(0x8010);
    }
    return result;
}

// Init(): sets the initialised flag (0x10000) through the window flags, then runs the window's own step.
// FUNCTION: 0x009b1e4a
bool cGZGraph::Slot03_ae1d24()
{
    if (get_init_flag()) {
        return true;
    }
    Slot68_adc8d8(0x10000, 1);
    return cGZWin::Slot03_ae1d24();
}

// QueryInterface: answers the graph interface with the second base, else asks the window.
// FUNCTION: 0x009b1e73
bool cGZGraph::QueryInterface(unsigned int iid, void** out)
{
    if (iid != 0x02cf2351) {
        return cGZWin::QueryInterface(iid, out);
    }
    *out = static_cast<cUnk00addff8*>(this);
    AddRef();
    return true;
}

// ---- batch 4 ----

// CalculateAxisZeroPosition(Axis): the pixel the value 0 lies on, from the axis range and the graph area.
#ifdef OB_DRAFTS
// CLOSE: 0x009b2365 score 16
void cGZGraph::Slot166_ade188(uint32_t axis)
{
    int32_t position;
    if (mfAxisMin[axis] == 0.0f) {
        if (axis == 0) {
            position = mnGraphArea[0];
        } else {
            position = mnGraphArea[3];
        }
    } else if (mfAxisMax[axis] == 0.0f) {
        if (axis == 0) {
            position = mnGraphArea[2];
        } else {
            position = mnGraphArea[1];
        }
    } else {
        int32_t amount = Slot162_ade188(axis, mfAxisMax[axis]);
        if (axis == 0) {
            position = mnGraphArea[2] - amount;
        } else {
            position = amount + mnGraphArea[1];
        }
    }
    mnAxisZeroPosition[axis] = position;
}
#endif

// SetMajorTickDivisions(Axis, unsigned long, bool): the spacing, at least 4 pixels when asked to adjust.
// FUNCTION: 0x009b20b2
void cGZGraph::Slot25_addff8(uint32_t axis, uint32_t divisions, uint32_t adjust)
{
    float spacing = (mfAxisMax[axis] - mfAxisMin[axis]) / static_cast<float>(divisions);
    if (*reinterpret_cast<bool*>(&adjust)) {
        int32_t pixels = Slot162_ade188(axis, spacing);
        if (pixels <= 4) {
            pixels = 4;
        }
        spacing = Slot163_ade188(axis, pixels);
    }
    mfMajorTickSpacing[axis] = spacing;
}

// SetMinorTickDivisions(Axis, unsigned long, bool): the spacing, at least 2 pixels when asked to adjust.
// FUNCTION: 0x009b21e5
void cGZGraph::Slot34_addff8(uint32_t axis, uint32_t divisions, uint32_t adjust)
{
    float spacing = mfMajorTickSpacing[axis] / static_cast<float>(divisions);
    float* minor = &mfMinorTickSpacing[axis];
    Slot162_ade188(axis, *minor);
    if (*reinterpret_cast<bool*>(&adjust)) {
        if (Slot162_ade188(axis, spacing) < 2) {
            spacing = Slot163_ade188(axis, 2);
            if (spacing > mfMajorTickSpacing[axis] * 0.5f) {
                mbMinorTickUsage[axis] = false;
            }
        }
    }
    *minor = spacing;
}

// CompleteRedraw(cIGZBuffer*): draws everything into the buffer (the window's own when none is given).
// FUNCTION: 0x009b2431
void cGZGraph::Slot14_addff8(uint32_t buffer)
{
    int32_t axis = 0;
    uint32_t target = buffer;
    if (target == 0) {
        target = field68;
        if (target == 0) {
            return;
        }
    }
    if (!mbFontsLoaded) {
        LoadDefaultFonts();
    }
    CommitDefaultValues();
    do {
        Slot166_ade188(axis);
        axis++;
    } while (axis < 2);
    DrawBackground(target);
    DrawGraphAreaBackground(target);
    DrawAxes(target);
    Slot155_ade188(target, 7);
    Slot156_ade188(target, 7);
    DrawGraphData(target);
    DrawDynamicObjects(target);
    DrawTitles(target);
}

// DrawAxes(cIGZBuffer*): the two axis lines along the left and bottom of the graph area.
// FUNCTION: 0x009b24e1
void cGZGraph::DrawAxes(uint32_t buffer)
{
    if (mbDrawAxes) {
        Buffer_ade188* target = OB_PTR(Buffer_ade188, buffer);
        if (target->Lock(0x8004)) {
            Slot43_addff8(buffer, mnGraphArea[0], mnGraphArea[1], mnGraphArea[0], mnGraphArea[3], mnAxisColor, 1);
            Slot43_addff8(buffer, mnGraphArea[0], mnGraphArea[3], mnGraphArea[2], mnGraphArea[3], mnAxisColor, 1);
            target->Unlock(0x8004);
        }
    }
}

// GetMaxTickLengthForAxis(Axis): the longer of the used major and minor tick lengths.
// FUNCTION: 0x009b35d3
uint32_t cGZGraph::Slot169_ade188(uint32_t axis)
{
    int32_t length = 0;
    if (mbMajorTickUsage[axis]) {
        length = std::max(length, mnMajorTickLength[axis]);
    }
    if (mbMinorTickUsage[axis]) {
        length = std::max(length, mnMinorTickLength[axis]);
    }
    return length;
}

// GetAutomaticTitleRect(cRZRect&): a strip along the top, as wide as the window.
// FUNCTION: 0x009b387a
void cGZGraph::GetAutomaticTitleRect(uint32_t rect)
{
    int32_t bottom = mnTitleTextHeight + 4;
    int32_t right = GetW() - 4;
    int32_t* area = OB_PTR(int32_t, rect);
    area[0] = 4;
    area[1] = 4;
    area[3] = bottom;
    area[2] = right;
}

// ValueAmountToPixelAmount(Axis, float): the original reads an unset scale for an axis other than 0 and 1.
#ifdef OB_DRAFTS
// CLOSE: 0x009b3efb score 17
int32_t cGZGraph::Slot162_ade188(uint32_t axis, float amount)
{
    float scale;
    if (axis == 0) {
        scale = (mfAxisMax[0] - mfAxisMin[0]) / (mnGraphArea[2] - mnGraphArea[0]);
    } else if (axis == 1) {
        scale = (mfAxisMax[1] - mfAxisMin[1]) / (mnGraphArea[3] - mnGraphArea[1]);
    } else {
        return 0;
    }
    return static_cast<int32_t>(amount / scale);
}
#endif

// PixelAmountToValueAmount(Axis, long): the same unset scale for another axis.
#ifdef OB_DRAFTS
// CLOSE: 0x009b3f5c score 15
float cGZGraph::Slot163_ade188(uint32_t axis, int32_t pixels)
{
    float scale;
    if (axis == 0) {
        scale = (mfAxisMax[0] - mfAxisMin[0]) / (mnGraphArea[2] - mnGraphArea[0]);
    } else if (axis == 1) {
        scale = (mfAxisMax[1] - mfAxisMin[1]) / (mnGraphArea[3] - mnGraphArea[1]);
    } else {
        return 0.0f;
    }
    return scale * pixels;
}
#endif

// ValueToPixel(Axis, float, bool): the original returns an unset position for another axis.
#ifdef OB_DRAFTS
// CLOSE: 0x009b3d71 score 49
int32_t cGZGraph::Slot160_ade188(uint32_t axis, float value, bool clamp)
{
    int32_t position;
    if (axis == 0) {
        float scale = (mfAxisMax[0] - mfAxisMin[0]) / (mnGraphArea[2] - mnGraphArea[0]);
        position = static_cast<int32_t>(value / scale) + mnAxisZeroPosition[0];
        if (clamp) {
            if (position < mnGraphArea[0]) {
                position = mnGraphArea[0];
            }
            if (position > mnGraphArea[2]) {
                position = mnGraphArea[2];
            }
        }
    } else if (axis == 1) {
        float scale = (mfAxisMax[1] - mfAxisMin[1]) / (mnGraphArea[3] - mnGraphArea[1]);
        position = mnAxisZeroPosition[1] - static_cast<int32_t>(value / scale);
        if (clamp) {
            if (position < mnGraphArea[1]) {
                position = mnGraphArea[1];
            }
            if (position > mnGraphArea[3]) {
                position = mnGraphArea[3];
            }
        }
    } else {
        return 0;
    }
    return position;
}
#endif

// PixelToValue(Axis, long, bool): the original returns an unset value for another axis.
#ifdef OB_DRAFTS
// CLOSE: 0x009b3e23 score 57
float cGZGraph::Slot161_ade188(uint32_t axis, int32_t pixel, bool clamp)
{
    float value;
    if (axis == 0) {
        float scale = (mfAxisMax[0] - mfAxisMin[0]) / (mnGraphArea[2] - mnGraphArea[0]);
        value = scale * (pixel - mnAxisZeroPosition[0]);
        if (clamp) {
            if (value < mfAxisMin[0]) {
                value = mfAxisMin[0];
            }
            if (value > mfAxisMax[0]) {
                value = mfAxisMax[0];
            }
        }
    } else if (axis == 1) {
        float scale = (mfAxisMax[1] - mfAxisMin[1]) / (mnGraphArea[3] - mnGraphArea[1]);
        value = scale * (mnAxisZeroPosition[1] - pixel);
        if (clamp) {
            if (value < mfAxisMin[1]) {
                value = mfAxisMin[1];
            }
            if (value > mfAxisMax[1]) {
                value = mfAxisMax[1];
            }
        }
    } else {
        return 0.0f;
    }
    return value;
}
#endif

// Fill(cIGZBuffer*, unsigned long, cRZRect const&, float): fills a copy of the rectangle (never reads `this`).
// FUNCTION: 0x009b3fb4
bool cGZGraph::Slot45_addff8(uint32_t buffer, uint32_t color, uint32_t rect, uint32_t)
{
    Buffer_ade188* target = OB_PTR(Buffer_ade188, buffer);
    bool locked = false;
    if (!target->IsLocked()) {
        if (!target->Lock(0x8001)) {
            return false;
        }
        locked = true;
    }
    const Sides_ade188* source = OB_PTR(const Sides_ade188, rect);
    Sides_ade188 area;
    area.left = source->left;
    area.top = source->top;
    area.right = source->right;
    area.bottom = source->bottom;
    bool result = target->Fill3(color, &area, 0);
    if (locked) {
        target->Unlock(0x8001);
    }
    return result;
}

// ---- batch 5 ----

// A dynamic graph object: drawn after the data, deleted with the graph.
struct DynamicObject_ade188 {
    virtual ~DynamicObject_ade188();
    virtual void Draw(cUnk00addff8* graph, uint32_t buffer);
};

// One link of the std::list of dynamic objects, and the list (one pointer to the sentinel link).
struct Link_ade188 {
    Link_ade188* mpNext;
    Link_ade188* mpPrev;
    DynamicObject_ade188* mpObject;
};

struct ObjectList_ade188 {
    Link_ade188* mpHead;
    // STUB: 0x009a841f
    void Clear();
};

// The objects the Add... methods make, built by their constructors.
struct MiscPicture_ade188 {
    uint32_t mWords[6];
    // STUB: 0x009b286a
    MiscPicture_ade188();
};

struct MiscRect_ade188 {
    uint32_t mWords[11];
    // STUB: 0x009b40eb
    MiscRect_ade188();
};

struct MiscArrow_ade188 {
    uint32_t mWords[11];
    // STUB: 0x009b410b
    MiscArrow_ade188();
};

struct MiscTextInfo_ade188 {
    uint32_t mWords[18];
    // STUB: 0x009b810f
    MiscTextInfo_ade188();
};

// SetAxisLabel(Axis, cRZString const&, bool): the string is a reference; with the flag the label gets an automatic place.
// FUNCTION: 0x009ba932
void cGZGraph::Slot19_addff8(uint32_t axis, uint32_t text, uint32_t automatic)
{
    mAxisLabel[axis] = *OB_PTR(const cRZString, text);
    if (*reinterpret_cast<bool*>(&automatic)) {
        reinterpret_cast<Rect_ade188*>(mnAxisLabelArea)[axis].v[0] = 0x7fffffff;
    }
}

// SetTitle(cRZString const&, bool)
// FUNCTION: 0x009ba967
void cGZGraph::Slot37_addff8(uint32_t text, uint32_t automatic)
{
    mTitle = *OB_PTR(const cRZString, text);
    if (*reinterpret_cast<bool*>(&automatic)) {
        mnTitleArea[0] = 0x7fffffff;
    }
}

// DrawDynamicObjects(cIGZBuffer*): every object draws itself onto the graph.
#ifdef OB_DRAFTS
// CLOSE: 0x009b5ade score 10
void cGZGraph::DrawDynamicObjects(uint32_t buffer)
{
    Link_ade188* head = static_cast<Link_ade188*>(mpDynamicObjects);
    if (head->mpNext == head) {
        return;
    }
    Link_ade188* link = head->mpNext;
    if (link != head) {
        do {
            link->mpObject->Draw(this, buffer);
            link = link->mpNext;
        } while (link != static_cast<Link_ade188*>(mpDynamicObjects));
    }
}
#endif

// Shutdown(): deletes the dynamic objects, lets go of the fonts and patterns and the hit-test data.
#ifdef OB_DRAFTS
// CLOSE: 0x009b5990 score 38
bool cGZGraph::Slot04_ae1d24()
{
    ObjectList_ade188* list = reinterpret_cast<ObjectList_ade188*>(&mpDynamicObjects);
    Link_ade188* head = list->mpHead;
    if (head->mpNext != head) {
        Link_ade188* link = head->mpNext;
        if (link != head) {
            do {
                delete link->mpObject;
                link = link->mpNext;
            } while (link != list->mpHead);
        }
        list->Clear();
    }
    void** field = &mpTitleFont;
    if (*field) {
        static_cast<cIGZUnknown*>(*field)->Release();
        *field = 0;
    }
    field = &mpBackgroundPattern;
    if (*field) {
        static_cast<cIGZUnknown*>(*field)->Release();
        *field = 0;
    }
    field = &mpGraphBackgroundPattern;
    if (*field) {
        static_cast<cIGZUnknown*>(*field)->Release();
        *field = 0;
    }
    for (int32_t i = 0; i < 2; i++) {
        if (mpAxisLabelFont[i]) {
            static_cast<cIGZUnknown*>(mpAxisLabelFont[i])->Release();
            mpAxisLabelFont[i] = 0;
        }
        if (mpAxisTickFont[i]) {
            static_cast<cIGZUnknown*>(mpAxisTickFont[i])->Release();
            mpAxisTickFont[i] = 0;
        }
    }
    field = &mpHitTestData;
    if (*field) {
        operator delete(*field);
        *field = 0;
    }
    mbFontsLoaded = false;
    return cGZWin::Slot04_ae1d24();
}
#endif

// DrawBackground(cIGZBuffer*): the pattern, or the fill and the outline, over the whole window.
#ifdef OB_DRAFTS
// CLOSE: 0x009b38a5 score 34
void cGZGraph::DrawBackground(uint32_t buffer)
{
    Sides_ade188 area = *reinterpret_cast<const Sides_ade188*>(&field24[0]);
    int32_t dy = -area.top;
    int32_t dx = -area.left;
    area.top += dy;
    area.bottom += dy;
    area.left += dx;
    area.right += dx;
    uint32_t flags;
    Buffer_ade188* target = OB_PTR(Buffer_ade188, buffer);
    if (mpBackgroundPattern) {
        Sides_ade188 source = area;
        if (!target->Lock(flags = 0x8010)) {
            return;
        }
        Slot46_addff8(OB_ADDR(mpBackgroundPattern), buffer, OB_ADDR(&source), OB_ADDR(&area));
    } else {
        if (mbBackgroundFill) {
            flags = 0x8001;
            if (target->Lock(flags)) {
                target->Fill1(mnBackgroundFillColor, &area);
                target->Unlock(flags);
            }
        }
        if (!mbBackgroundOutline) {
            return;
        }
        if (!target->Lock(flags = 0x8008)) {
            return;
        }
        Slot44_addff8(buffer, OB_ADDR(&area), mnBackgroundOutlineColor, 1);
    }
    target->Unlock(flags);
}
#endif

// DrawGraphAreaBackground(cIGZBuffer*): the pattern, or the fill and the outline, over the graph area.
#ifdef OB_DRAFTS
// CLOSE: 0x009b3994 score 34
void cGZGraph::DrawGraphAreaBackground(uint32_t buffer)
{
    uint32_t flags;
    Buffer_ade188* target;
    if (mpGraphBackgroundPattern) {
        Sides_ade188 source = *reinterpret_cast<const Sides_ade188*>(&mnGraphArea[0]);
        int32_t dy = -source.top;
        int32_t dx = -source.left;
        target = OB_PTR(Buffer_ade188, buffer);
        source.top += dy;
        source.bottom += dy;
        source.left += dx;
        source.right += dx;
        if (!target->Lock(flags = 0x8010)) {
            return;
        }
        Slot46_addff8(OB_ADDR(mpGraphBackgroundPattern), buffer, OB_ADDR(&source), OB_ADDR(&mnGraphArea[0]));
    } else {
        target = OB_PTR(Buffer_ade188, buffer);
        if (mbGraphAreaFill) {
            flags = 0x8001;
            if (target->Lock(flags)) {
                target->Fill1(mnGraphAreaFillColor, &mnGraphArea[0]);
                target->Unlock(flags);
            }
        }
        if (!mbGraphAreaOutline) {
            return;
        }
        if (!target->Lock(flags = 0x8008)) {
            return;
        }
        Slot44_addff8(buffer, OB_ADDR(&mnGraphArea[0]), mnGraphAreaOutlineColor, 1);
    }
    target->Unlock(flags);
}
#endif

// AddMiscGraphPicture(): makes a picture object and adds it as a dynamic object.
// FUNCTION: 0x009b361a
uint32_t cGZGraph::Slot53_addff8()
{
    MiscPicture_ade188* picture = new MiscPicture_ade188;
    Slot47_addff8(OB_ADDR(picture));
    return OB_ADDR(picture);
}

// AddMiscGraphLine(): its constructor is inline (three words set).
#ifdef OB_DRAFTS
// CLOSE: 0x009b5a50 score 13
uint32_t cGZGraph::Slot50_addff8()
{
    cUnk00ade0d4* line = new cUnk00ade0d4;
    if (line) {
        *reinterpret_cast<uint32_t*>(&line->unknown4[0x14]) = 0;
        *reinterpret_cast<uint32_t*>(&line->unknown4[0x18]) = 1;
    }
    Slot47_addff8(OB_ADDR(line));
    return OB_ADDR(line);
}
#endif

// AddMiscGraphRect()
// FUNCTION: 0x009b5a84
uint32_t cGZGraph::Slot51_addff8()
{
    MiscRect_ade188* rect = new MiscRect_ade188;
    Slot47_addff8(OB_ADDR(rect));
    return OB_ADDR(rect);
}

// AddMiscGraphArrow()
// FUNCTION: 0x009b5ab1
uint32_t cGZGraph::Slot52_addff8()
{
    MiscArrow_ade188* arrow = new MiscArrow_ade188;
    Slot47_addff8(OB_ADDR(arrow));
    return OB_ADDR(arrow);
}

// AddMiscGraphTextInfo()
// FUNCTION: 0x009b963d
uint32_t cGZGraph::Slot49_addff8()
{
    MiscTextInfo_ade188* info = new MiscTextInfo_ade188;
    Slot47_addff8(OB_ADDR(info));
    return OB_ADDR(info);
}

// ---- batch 6 ----

// The "value not set" marker of the graph's float properties.
// GLOBAL: 0x00b17c1c
extern float g00b17c1c;

// CommitDefaultValues(): fills in the properties still at their default from the automatic values.
// FUNCTION: 0x009b3647
void cGZGraph::CommitDefaultValues()
{
    float automatic;
    Rect_ade188 area;
    for (int32_t i = 0; i < 2; i++) {
        bool bothDefault = true;
        if (mfAxisMin[i] == g00b17c1c) {
            Slot174_ade188(i, OB_ADDR(&automatic));
            mfAxisMin[i] = automatic;
        } else {
            bothDefault = false;
        }
        if (mfAxisMax[i] == g00b17c1c) {
            Slot175_ade188(i, OB_ADDR(&automatic));
            mfAxisMax[i] = automatic;
        } else {
            bothDefault = false;
        }
        if (bothDefault) {
            if (mfAxisMin[i] == mfAxisMax[i]) {
                if (mfAxisMax[i] != 0.0f) {
                    mfAxisMax[i] = mfAxisMax[i] * 1.1111112f;
                } else {
                    mfAxisMax[i] = 1.0f;
                }
            }
        }
        if (mnMajorTickDecimals[i] == 0x80) {
            float span = mfAxisMax[i] - mfAxisMin[i];
            if (span < 10.0f) {
                if (span < 0.0001f) {
                    mnMajorTickDecimals[i] = 5;
                } else if (span < 0.001f) {
                    mnMajorTickDecimals[i] = 4;
                } else if (span < 0.01f) {
                    mnMajorTickDecimals[i] = 3;
                } else if (span < 0.1f) {
                    mnMajorTickDecimals[i] = 2;
                } else {
                    mnMajorTickDecimals[i] = 1;
                }
            } else {
                mnMajorTickDecimals[i] = 0;
            }
        }
    }
    if (mnGraphArea[0] == 0x7fffffff) {
        GetAutomaticGraphAreaRect(OB_ADDR(&area));
        Slot12_addff8(OB_ADDR(&area));
    }
    if (mnTitleArea[0] == 0x7fffffff) {
        GetAutomaticTitleRect(OB_ADDR(&area));
        *reinterpret_cast<Rect_ade188*>(mnTitleArea) = area;
    }
    for (int32_t i = 0; i < 2; i++) {
        if (reinterpret_cast<Rect_ade188*>(mnAxisLabelArea)[i].v[0] == 0x7fffffff) {
            Slot173_ade188(i, OB_ADDR(&area));
            reinterpret_cast<Rect_ade188*>(mnAxisLabelArea)[i] = area;
        }
        if (mfMajorTickSpacing[i] == g00b17c1c) {
            Slot176_ade188(i, OB_ADDR(&automatic));
            mfMajorTickSpacing[i] = automatic;
        }
        if (mfMinorTickSpacing[i] == g00b17c1c) {
            Slot177_ade188(i, OB_ADDR(&automatic));
            mfMinorTickSpacing[i] = automatic;
        }
        Slot166_ade188(i);
    }
}

#ifdef OB_DRAFTS
// The constructors of the objects the Add... methods make, over stand-in classes (the vtable each one stores is the
// stand-in's own, not the original's).
struct MiscPictureDraft_ade188 {
    virtual ~MiscPictureDraft_ade188();
    uint32_t mWord4;
    uint32_t mWord8;
    uint32_t mWordC;
    uint32_t mWord10;
    bool mFlag14;
    MiscPictureDraft_ade188();
};

struct MiscRectDraft_ade188 {
    virtual ~MiscRectDraft_ade188();
    uint32_t mWord4[5];
    bool mFlag18;
    uint8_t mPad19[3];
    uint32_t mWord1C;
    uint32_t mWord20;
    bool mFlag24;
    uint8_t mPad25[3];
    int32_t mWord28;
    MiscRectDraft_ade188();
};

struct MiscArrowDraft_ade188 {
    virtual ~MiscArrowDraft_ade188();
    uint32_t mWord4[5];
    uint32_t mWord18;
    uint32_t mWord1C;
    bool mFlag20;
    bool mFlag21;
    uint8_t mPad22[2];
    uint32_t mWord24;
    uint32_t mWord28;
    MiscArrowDraft_ade188();
};

struct MiscTextInfoDraft_ade188 {
    virtual ~MiscTextInfoDraft_ade188();
    uint32_t mWord4;
    cRZString mText;
    uint32_t mWord1C[4];
    uint32_t mWord2C;
    bool mFlag30;
    uint8_t mPad31[3];
    uint32_t mWord34;
    bool mFlag38;
    uint8_t mPad39[3];
    int32_t mWord3C;
    uint32_t mWord40;
    uint32_t mWord44;
    MiscTextInfoDraft_ade188();
};

// CLOSE: 0x009b286a score 0 (stand-in vtable)
MiscPictureDraft_ade188::MiscPictureDraft_ade188()
{
    mWord8 = 0;
    mWordC = 0;
    mWord10 = 0;
    mFlag14 = false;
}

// CLOSE: 0x009b40eb score 0 (stand-in vtable)
MiscRectDraft_ade188::MiscRectDraft_ade188()
{
    mWord20 = 0;
    mWord28 = -1;
    mFlag18 = true;
    mWord1C = 1;
    mFlag24 = false;
}

// CLOSE: 0x009b410b score 0 (stand-in vtable)
MiscArrowDraft_ade188::MiscArrowDraft_ade188()
{
    mWord18 = 0;
    mWord1C = 1;
    mFlag20 = true;
    mFlag21 = false;
    mWord24 = 8;
    mWord28 = 0x3f490ff9;
}

// CLOSE: 0x009b810f score 0 (stand-in vtable)
MiscTextInfoDraft_ade188::MiscTextInfoDraft_ade188()
{
    mWord3C = -1;
    mWord2C = 0;
    mFlag30 = false;
    mWord34 = 0;
    mFlag38 = false;
    mWord40 = 0;
    mWord44 = 0x80000000;
}
#endif

// ---- batch 7 ----

// The font a window draws text with, seen through the slots this class calls.
struct Font_ade188 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void P05();
    virtual void P06();
    virtual void P07();
    virtual void P08();
    virtual void P09();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual uint32_t GetLineHeight(uint32_t a, uint32_t b);
    virtual void P38();
    virtual void P39();
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual uint32_t GetStringWidth(const char* text, uint32_t length);
    virtual void P49();
    virtual void P50();
    virtual void P51();
    virtual uint32_t DrawTextLine(uint32_t buffer, const int32_t* area, const char* text, uint32_t length,
                                  uint32_t align, uint32_t color, uint32_t background, uint32_t a, uint32_t b);
};

// The font system RZ::FO(): makes fonts by name.
struct FontSystem_ade188 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void P05();
    virtual void P06();
    virtual void P07();
    virtual void P08();
    virtual void P09();
    virtual void P10();
    virtual cIGZUnknown* CreateFont(const cRZString& name, uint32_t style, uint32_t size, uint32_t a, uint32_t b);
};

// STUB: 0x00913d22
FontSystem_ade188* Fn00913d22();

// LoadDefaultFonts(): arial (else helvetica) for the title, the axis labels and the tick texts that have none.
// FUNCTION: 0x009b7774
void cGZGraph::LoadDefaultFonts()
{
    if (!mpTitleFont) {
        FontSystem_ade188* fonts = Fn00913d22();
        if (fonts) {
            cIGZUnknown* font = fonts->CreateFont(cRZString("arial"), 0, 24, 0, 1);
            if (!font) {
                font = fonts->CreateFont(cRZString("helvetica"), 0, 24, 0, 1);
            }
            if (font) {
                Slot39_addff8(OB_ADDR(font), 0x80000000);
                font->Release();
            }
        }
    }
    for (int32_t axis = 0; axis < 2; axis++) {
        if (!mpAxisLabelFont[axis]) {
            FontSystem_ade188* fonts = Fn00913d22();
            if (fonts) {
                cIGZUnknown* font = fonts->CreateFont(cRZString("arial"), 0, 16, 0, 1);
                if (!font) {
                    font = fonts->CreateFont(cRZString("helvetica"), 0, 16, 0, 1);
                }
                if (font) {
                    Slot21_addff8(axis, OB_ADDR(font), 0x80000000);
                    font->Release();
                }
            }
        }
        if (!mpAxisTickFont[axis]) {
            FontSystem_ade188* fonts = Fn00913d22();
            if (fonts) {
                cIGZUnknown* font = fonts->CreateFont(cRZString("arial"), 0, 14, 0, 1);
                if (!font) {
                    font = fonts->CreateFont(cRZString("helvetica"), 0, 14, 0, 1);
                }
                if (font) {
                    Slot29_addff8(axis, OB_ADDR(font), 0x80000000);
                    font->Release();
                }
            }
        }
    }
    mbFontsLoaded = true;
}

// GetAutomaticGraphAreaRect(cRZRect&): the window less the room the titles, tick texts and labels need.
#ifdef OB_DRAFTS
// CLOSE: 0x009b799d score 12
void cGZGraph::GetAutomaticGraphAreaRect(uint32_t rect)
{
    int32_t axis;
    int32_t tickTextSize[2];
    int32_t labelSize[2];
    int32_t tickLength[2];
    for (axis = 0; axis < 2; axis++) {
        if (mbMajorTickUsage[axis]) {
            tickLength[axis] = mnMajorTickLength[axis];
        } else {
            tickLength[axis] = 0;
        }
        if (mbTickText[axis]) {
            if (mpAxisTickFont[axis]) {
                if (axis == 0) {
                    tickTextSize[0] = static_cast<Font_ade188*>(mpAxisTickFont[0])->GetLineHeight(0, 0);
                } else {
                    char format[5] = "%._f";
                    cRZString text;
                    format[2] = static_cast<char>(mnMajorTickDecimals[axis] + '0');
                    text.Sprintf(format, static_cast<double>(mfAxisMax[axis]));
                    tickTextSize[axis] =
                        static_cast<Font_ade188*>(mpAxisTickFont[axis])->GetStringWidth(text.c_str(), text.length());
                }
            } else {
                tickTextSize[axis] = 16;
            }
        } else {
            tickTextSize[axis] = 0;
        }
        if (mAxisLabel[axis].length() != 0) {
            if (mpAxisLabelFont[axis]) {
                labelSize[axis] = static_cast<Font_ade188*>(mpAxisLabelFont[axis])->GetLineHeight(0, 0);
            } else {
                labelSize[axis] = 16;
            }
        } else {
            labelSize[axis] = 0;
        }
    }
    int32_t height = GetH();
    int32_t width = GetW();
    int32_t* out = OB_PTR(int32_t, rect);
    out[3] = height - 16;
    out[0] = 16;
    out[1] = 16;
    out[2] = width - 16;
    if (mnTitleArea[0] == 0x7fffffff) {
        out[1] = mnTitleTextHeight + 4;
    }
    if (reinterpret_cast<Rect_ade188*>(mnAxisLabelArea)[0].v[0] == 0x7fffffff) {
        out[3] = GetH() + (-4 - labelSize[0] - tickTextSize[0] - tickLength[0]);
    }
    if (reinterpret_cast<Rect_ade188*>(mnAxisLabelArea)[1].v[0] == 0x7fffffff) {
        out[0] = labelSize[1] + tickTextSize[1] + tickLength[1] + 4;
    }
}
#endif

// GetAutomaticAxisLabelRect(Axis, cRZRect&): where an axis label goes, from the graph area and the label sizes.
#ifdef OB_DRAFTS
// CLOSE: 0x009b7b57 score 156
void cGZGraph::Slot173_ade188(uint32_t axis, uint32_t rect)
{
    int32_t tickTextSize;
    int32_t tickLength;
    int32_t labelHeight;
    int32_t labelWidth;
    if (mbMajorTickUsage[axis]) {
        tickLength = mnMajorTickLength[axis];
    } else {
        tickLength = 0;
    }
    if (mbTickText[axis]) {
        if (mpAxisTickFont[axis]) {
            if (axis == 0) {
                tickTextSize = static_cast<Font_ade188*>(mpAxisTickFont[0])->GetLineHeight(0, 0);
            } else {
                char format[5] = "%._f";
                cRZString text;
                format[2] = static_cast<char>(mnMajorTickDecimals[axis] + '0');
                text.Sprintf(format, static_cast<double>(mfAxisMax[axis]));
                tickTextSize =
                    static_cast<Font_ade188*>(mpAxisTickFont[axis])->GetStringWidth(text.c_str(), text.length());
            }
        } else {
            tickTextSize = 16;
        }
    } else {
        tickTextSize = 0;
    }
    if (mAxisLabel[axis].length() != 0) {
        if (mpAxisLabelFont[axis]) {
            labelHeight = static_cast<Font_ade188*>(mpAxisLabelFont[axis])->GetLineHeight(0, 0);
            labelWidth = static_cast<Font_ade188*>(mpAxisLabelFont[axis])
                             ->GetStringWidth(mAxisLabel[axis].c_str(), mAxisLabel[axis].length());
        } else {
            labelWidth = mnGraphArea[2] - mnGraphArea[0];
            labelHeight = 16;
        }
    } else {
        labelWidth = 0;
        labelHeight = 0;
    }
    int32_t* out = OB_PTR(int32_t, rect);
    if (axis == 0) {
        int32_t bottom = mnGraphArea[3];
        int32_t outer = bottom + labelHeight;
        int32_t left = mnGraphArea[0];
        int32_t half = labelWidth / 2;
        int32_t right = (mnGraphArea[2] - mnGraphArea[0]) / 2 + half + left + 1;
        outer += tickTextSize;
        outer += tickLength;
        int32_t top = bottom + tickTextSize + tickLength;
        out[1] = top;
        out[0] = (mnGraphArea[2] - left) / 2 - half + left;
        out[2] = right;
        out[3] = outer;
    } else if (axis == 1) {
        if (mnAxisLabelRotation[1] != 0 && mnAxisLabelRotation[1] != 2) {
            int32_t top = mnGraphArea[1];
            int32_t half = labelWidth / 2;
            int32_t lower = (mnGraphArea[3] - top) / 2 + top + half + 1;
            int32_t left = mnGraphArea[0];
            int32_t inner = left;
            int32_t outer = left - labelHeight;
            out[1] = (mnGraphArea[3] - mnGraphArea[1]) / 2 - half + top;
            inner -= tickTextSize;
            outer -= tickTextSize;
            inner -= tickLength;
            outer -= tickLength;
            out[2] = inner;
            out[0] = outer;
            out[3] = lower;
        } else {
            int32_t top = mnGraphArea[1];
            int32_t half = labelHeight / 2;
            int32_t lower = (mnGraphArea[3] - top) / 2 + half + top + 1;
            int32_t left = mnGraphArea[0];
            int32_t inner = left;
            int32_t outer = left - labelWidth;
            out[1] = (mnGraphArea[3] - mnGraphArea[1]) / 2 - half + top;
            inner -= tickTextSize;
            outer -= tickTextSize;
            inner -= tickLength;
            outer -= tickLength;
            out[2] = inner;
            out[0] = outer;
            out[3] = lower;
        }
    }
}
#endif

// ---- batch 8 ----

// DrawTicks(cIGZBuffer*, flags): bit 0 the lines across the bottom, bit 1 the lines along the left side.
#ifdef OB_DRAFTS
// CLOSE: 0x009b3a85 score 76
void cGZGraph::Slot155_ade188(uint32_t buffer, uint32_t flags)
{
    float position;
    float minorPosition;
    int32_t minorEnd0;
    int32_t minorEnd1;
    int32_t minorStart0;
    int32_t minorStart1;
    int32_t majorEnd0;
    int32_t majorEnd1;
    int32_t majorStart0;
    int32_t majorStart1;
    if (mbMajorTickUsage[0] || mbMajorTickUsage[1]) {
        Buffer_ade188* target = OB_PTR(Buffer_ade188, buffer);
        if (target->Lock(0x8004)) {
            if ((flags & 1) && mbMajorTickUsage[0]) {
                int32_t bottom = mnGraphArea[3];
                majorEnd0 = mnMajorTickLength[0] + bottom;
                if (mbMajorTickGrid[0]) {
                    majorStart0 = mnGraphArea[1];
                } else {
                    majorStart0 = bottom;
                }
                if (mbMinorTickUsage[0]) {
                    minorEnd0 = mnMinorTickLength[0] + bottom;
                    if (mbMinorTickGrid[0]) {
                        minorStart0 = mnGraphArea[1];
                    } else {
                        minorStart0 = bottom;
                    }
                }
                for (position = mfAxisMin[0]; position <= mfMajorTickSpacing[0] * 0.01f + mfAxisMax[0];
                     position += mfMajorTickSpacing[0]) {
                    int32_t pixel = Slot160_ade188(0, position, false);
                    Slot43_addff8(buffer, pixel, majorStart0, pixel, majorEnd0, mnTickColor, 1);
                    if (mbMinorTickUsage[0]) {
                        for (minorPosition = position + mfMinorTickSpacing[0];
                             minorPosition < position + mfMajorTickSpacing[0];
                             minorPosition += mfMinorTickSpacing[0]) {
                            pixel = Slot160_ade188(0, minorPosition, false);
                            Slot43_addff8(buffer, pixel, minorStart0, pixel, minorEnd0, mnTickColor, 1);
                        }
                    }
                }
            }
            if ((flags & 2) && mbMajorTickUsage[1]) {
                int32_t left = mnGraphArea[0];
                majorStart1 = left - mnMajorTickLength[1];
                if (mbMajorTickGrid[1]) {
                    majorEnd1 = mnGraphArea[2];
                } else {
                    majorEnd1 = left;
                }
                if (mbMinorTickUsage[1]) {
                    minorStart1 = left - mnMinorTickLength[1];
                    if (mbMinorTickGrid[1]) {
                        minorEnd1 = mnGraphArea[2];
                    } else {
                        minorEnd1 = left;
                    }
                }
                for (position = mfAxisMin[1]; position <= mfMajorTickSpacing[1] * 0.01f + mfAxisMax[1];
                     position += mfMajorTickSpacing[1]) {
                    int32_t pixel = Slot160_ade188(1, position, false);
                    Slot43_addff8(buffer, majorStart1, pixel, majorEnd1, pixel, mnTickColor, 1);
                    if (mbMinorTickUsage[1]) {
                        for (minorPosition = position + mfMinorTickSpacing[1];
                             minorPosition < position + mfMajorTickSpacing[1];
                             minorPosition += mfMinorTickSpacing[1]) {
                            pixel = Slot160_ade188(1, minorPosition, false);
                            Slot43_addff8(buffer, minorStart1, pixel, minorEnd1, pixel, mnTickColor, 1);
                        }
                    }
                }
            }
            target->Unlock(0x8004);
        }
    }
}
#endif

// DrawTickText(cIGZBuffer*, flags): the numbers under the bottom ticks (bit 0) and beside the left ticks (bit 1).
#ifdef OB_DRAFTS
// CLOSE: 0x009b7de9 score 84
void cGZGraph::Slot156_ade188(uint32_t buffer, uint32_t flags)
{
    cRZString text;
    char format[5] = "%._f";
    if ((flags & 1) && mbTickText[0] && mpAxisTickFont[0]) {
        int32_t area[4];
        int32_t height = static_cast<Font_ade188*>(mpAxisTickFont[0])->GetLineHeight(0, 0);
        int32_t top = mnMajorTickLength[0] + mnGraphArea[3] + 2;
        area[3] = top + height + 2;
        area[1] = top;
        for (float x = mfAxisMin[0]; x <= mfMajorTickSpacing[0] * 0.25f + mfAxisMax[0]; x += mfMajorTickSpacing[0]) {
            format[2] = static_cast<char>(mnMajorTickDecimals[0] + '0');
            text.Sprintf(format, static_cast<double>(x));
            int32_t width =
                static_cast<Font_ade188*>(mpAxisTickFont[0])->GetStringWidth(text.c_str(), text.length());
            int32_t pixel = Slot160_ade188(0, x, false);
            if (mnTickTextAlign[0] == 0) {
                area[0] = pixel;
                area[2] = pixel + width + 2;
            } else if (mnTickTextAlign[0] == 1) {
                int32_t half = width / 2;
                area[0] = pixel - half - 1;
                area[2] = half + pixel + 1;
            } else {
                area[2] = pixel;
                area[0] = pixel - width - 2;
            }
            if (mnAxisTickFontColor[0] == 0x80000000) {
                static_cast<Font_ade188*>(mpAxisTickFont[0])
                    ->DrawTextLine(buffer, area, text.c_str(), text.length(), mnTickTextAlign[0], 0x8000000,
                                   0x8000000, 0, 0);
            } else {
                static_cast<Font_ade188*>(mpAxisTickFont[0])
                    ->DrawTextLine(buffer, area, text.c_str(), text.length(), mnTickTextAlign[0],
                                   mnAxisTickFontColor[0], 0x8000000, 0, 0);
            }
        }
    }
    if ((flags & 2) && mbTickText[1] && mpAxisTickFont[1]) {
        int32_t area[4];
        int32_t height = static_cast<Font_ade188*>(mpAxisTickFont[1])->GetLineHeight(0, 0);
        area[2] = mnGraphArea[0] - mnMajorTickLength[1] - 2;
        float y = mfAxisMin[1];
        if (y <= mfMajorTickSpacing[1] * 0.01f + mfAxisMax[1]) {
            flags = height / 2;
            do {
                format[2] = static_cast<char>(mnMajorTickDecimals[1] + '0');
                text.Sprintf(format, static_cast<double>(y));
                int32_t width =
                    static_cast<Font_ade188*>(mpAxisTickFont[1])->GetStringWidth(text.c_str(), text.length());
                area[0] = area[2] - width;
                int32_t pixel = Slot160_ade188(1, y, false);
                area[3] = flags + pixel + 2;
                area[1] = pixel - flags;
                if (mnAxisTickFontColor[1] == 0x80000000) {
                    static_cast<Font_ade188*>(mpAxisTickFont[1])
                        ->DrawTextLine(buffer, area, text.c_str(), text.length(), mnTickTextAlign[1], 0x8000000,
                                       0x8000000, 0, 0);
                } else {
                    static_cast<Font_ade188*>(mpAxisTickFont[1])
                        ->DrawTextLine(buffer, area, text.c_str(), text.length(), mnTickTextAlign[1],
                                       mnAxisTickFontColor[1], 0x8000000, 0, 0);
                }
                y += mfMajorTickSpacing[1];
            } while (y <= mfMajorTickSpacing[1] * 0.01f + mfAxisMax[1]);
        }
    }
}
#endif

// ---- batch 9 ----

// The graphics system RZ::GS(): makes drawing buffers.
struct GraphicsSystem_ade188 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual bool CreateBuffer(Buffer_ade188** out);
};

// STUB: 0x00913c1a
GraphicsSystem_ade188* Fn00913c1a();

// The original passes the rectangle, the point and the destination buffer in ecx, eax and edx; no calling convention
// of the 2003 compiler can say that, so this stands for the call with plain arguments (see Fn009b31e1Draft_ade188).
// STUB: 0x009b31e1
bool Fn009b31e1(const int32_t* area, const int32_t* point, Buffer_ade188* destination, Buffer_ade188* source,
                uint32_t angle);

// DrawTitles(cIGZBuffer*): the two axis labels (the second one possibly turned) and the title.
#ifdef OB_DRAFTS
// CLOSE: 0x009b5b16 score 83
void cGZGraph::DrawTitles(uint32_t buffer)
{
    if (mAxisLabel[0].length() != 0 && mpAxisLabelFont[0]) {
        if (mnAxisLabelFontColor[0] == 0x80000000) {
            static_cast<Font_ade188*>(mpAxisLabelFont[0])
                ->DrawTextLine(buffer, &mnAxisLabelArea[0], mAxisLabel[0].c_str(), mAxisLabel[0].length(),
                               mnAxisLabelAlign[0], 0x8000000, 0x8000000, 0, 0);
        } else {
            static_cast<Font_ade188*>(mpAxisLabelFont[0])
                ->DrawTextLine(buffer, &mnAxisLabelArea[0], mAxisLabel[0].c_str(), mAxisLabel[0].length(),
                               mnAxisLabelAlign[0], mnAxisLabelFontColor[0], 0x8000000, 0, 0);
        }
    }
    if (mAxisLabel[1].length() != 0 && mpAxisLabelFont[1]) {
        if (mnAxisLabelRotation[1] == 0) {
            if (mnAxisLabelFontColor[1] == 0x80000000) {
                static_cast<Font_ade188*>(mpAxisLabelFont[1])
                    ->DrawTextLine(buffer, &mnAxisLabelArea[4], mAxisLabel[1].c_str(), mAxisLabel[1].length(),
                                   mnAxisLabelAlign[1], 0x8000000, 0x8000000, 0, 0);
            } else {
                static_cast<Font_ade188*>(mpAxisLabelFont[1])
                    ->DrawTextLine(buffer, &mnAxisLabelArea[4], mAxisLabel[1].c_str(), mAxisLabel[1].length(),
                                   mnAxisLabelAlign[1], mnAxisLabelFontColor[1], 0x8000000, 0, 0);
            }
        } else {
            int32_t area[4];
            int32_t point[2];
            Buffer_ade188* temp;
            area[0] = 0;
            area[1] = 0;
            area[2] = 0;
            area[3] = 0;
            temp = 0;
            Fn00913c1a()->CreateBuffer(&temp);
            int32_t width;
            int32_t height;
            if (mnAxisLabelRotation[1] == 0 || mnAxisLabelRotation[1] == 2) {
                width = mnAxisLabelArea[6] - mnAxisLabelArea[4];
                height = mnAxisLabelArea[7] - mnAxisLabelArea[5];
            } else {
                width = mnAxisLabelArea[7] - mnAxisLabelArea[5];
                height = mnAxisLabelArea[6] - mnAxisLabelArea[4];
            }
            area[3] = height + 4;
            area[2] = width + 4;
            temp->Init(area[2] - area[0], area[3] - area[1], ColorType_ade188(3));
            if (temp->Lock(0x8001)) {
                temp->Fill3(mnTransparentColor, area, 0);
                temp->Unlock(0x8001);
            }
            if (mpAxisLabelFont[1]) {
                if (mnAxisLabelFontColor[1] == 0x80000000) {
                    static_cast<Font_ade188*>(mpAxisLabelFont[1])
                        ->DrawTextLine(OB_ADDR(temp), area, mAxisLabel[1].c_str(), mAxisLabel[1].length(),
                                       mnAxisLabelAlign[1], 0x8000000, 0x8000000, 0, 0);
                } else {
                    static_cast<Font_ade188*>(mpAxisLabelFont[1])
                        ->DrawTextLine(OB_ADDR(temp), area, mAxisLabel[1].c_str(), mAxisLabel[1].length(),
                                       mnAxisLabelAlign[1], mnAxisLabelFontColor[1], 0x8000000, 0, 0);
                }
            }
            temp->SetTransparency(mnTransparentColor);
            Buffer_ade188* target = OB_PTR(Buffer_ade188, buffer);
            if (target->Lock(0x8020)) {
                uint32_t angle;
                if (mnAxisLabelRotation[1] == 1) {
                    angle = 0x5a;
                } else if (mnAxisLabelRotation[1] == 2) {
                    angle = 0xb4;
                } else {
                    angle = 0x10e;
                }
                point[0] = mnAxisLabelArea[4];
                point[1] = mnAxisLabelArea[5];
                Fn009b31e1(area, point, target, temp, angle);
                target->Unlock(0x8020);
            }
            temp->Release();
        }
    }
    if (mTitle.length() != 0 && mpTitleFont) {
        if (mnTitleFontColor == 0x80000000) {
            static_cast<Font_ade188*>(mpTitleFont)
                ->DrawTextLine(buffer, &mnTitleArea[0], mTitle.c_str(), mTitle.length(), mnTitleAlign, 0x8000000,
                               0x8000000, 0, 0);
        } else {
            static_cast<Font_ade188*>(mpTitleFont)
                ->DrawTextLine(buffer, &mnTitleArea[0], mTitle.c_str(), mTitle.length(), mnTitleAlign,
                               mnTitleFontColor, 0x8000000, 0, 0);
        }
    }
}
#endif

// ---- batch 10 ----

// The turned pixel copy DrawTitles uses: the area of the source buffer is copied into the destination at a point,
// turned by 0, 90, 180 or 270 degrees (16 or 8 bits per pixel; a transparent color is skipped). The original takes the
// area in ecx, the point in eax and the destination in edx, which no declaration of the 2003 compiler can express, so
// this draft has plain arguments and cannot be matched as it stands.
#ifdef OB_DRAFTS
// CLOSE: 0x009b31e1 score 467
bool Fn009b31e1Draft_ade188(const int32_t* area, const int32_t* point, Buffer_ade188* destination,
                            Buffer_ade188* source, uint32_t angle)
{
    if (!source->Lock(0x8040)) {
        return false;
    }
    uint32_t bits = destination->Slot17();
    if (bits == 16) {
        int32_t width = area[2] - area[0];
        int32_t height = area[3] - area[1];
        int32_t sourceStride = source->GetColorSurfaceStride();
        int32_t destStride = destination->GetColorSurfaceStride();
        uint8_t* sourceBits = source->GetColorSurfaceBits();
        uint8_t* src = sourceBits + area[1] * sourceStride + area[0] * 2;
        int32_t rowSkip = sourceStride - width * 2;
        uint8_t* rowEnd = src + width * 2;
        uint8_t* srcEnd = src + sourceStride * height;
        int32_t doubled = width * 2;
        if (angle >= 0x168) {
            angle = angle % 0x168;
        }
        uint8_t* destBits = destination->GetColorSurfaceBits();
        uint8_t* dst;
        int32_t rowAdjust;
        int32_t step;
        if (angle == 0x5a) {
            rowAdjust = destStride * width + 2;
            dst = destBits + (point[1] - 1 + width) * destStride + point[0] * 2;
            step = -destStride;
        } else if (angle == 0xb4) {
            rowAdjust = doubled - destStride;
            dst = destBits - 2 + (point[1] - 1 + height) * destStride + (point[0] + width) * 2;
            step = -2;
        } else if (angle == 0x10e) {
            dst = destBits - 2 + point[1] * destStride + (point[0] + height) * 2;
            rowAdjust = -2 - destStride * width;
            step = destStride;
        } else {
            dst = destBits + point[1] * destStride + point[0];
            rowAdjust = destStride - doubled;
            step = 2;
        }
        if (!source->Slot24()) {
            for (; src < srcEnd; src += rowSkip) {
                for (; src < rowEnd; src += 2) {
                    *reinterpret_cast<uint16_t*>(dst) = *reinterpret_cast<uint16_t*>(src);
                    dst += step;
                }
                dst += rowAdjust;
                rowEnd += sourceStride;
            }
        } else {
            uint32_t key;
            source->GetTransparentColor(&key);
            for (; src < srcEnd; src += rowSkip) {
                for (; src < rowEnd; src += 2) {
                    if (*reinterpret_cast<uint16_t*>(src) != static_cast<uint16_t>(key)) {
                        *reinterpret_cast<uint16_t*>(dst) = *reinterpret_cast<uint16_t*>(src);
                    }
                    dst += step;
                }
                dst += rowAdjust;
                rowEnd += sourceStride;
            }
        }
    } else if (bits == 8) {
        int32_t width = area[2] - area[0];
        int32_t height = area[3] - area[1];
        int32_t sourceStride = source->GetColorSurfaceStride();
        int32_t destStride = destination->GetColorSurfaceStride();
        uint8_t* sourceBits = source->GetColorSurfaceBits();
        uint8_t* src = sourceBits + area[1] * sourceStride + area[0];
        int32_t rowSkip = sourceStride - width;
        uint8_t* rowEnd = src + width;
        uint8_t* srcEnd = src + sourceStride * height;
        uint8_t* destBits = destination->GetColorSurfaceBits();
        uint8_t* dst;
        int32_t rowAdjust;
        int32_t step;
        if (angle == 0x5a) {
            dst = destBits + (point[1] - 1 + width) * destStride + point[0];
            rowAdjust = destStride * width + 1;
            step = -destStride;
        } else if (angle == 0xb4) {
            dst = destBits + (point[1] - 1 + height) * destStride + point[0] - 1 + width;
            rowAdjust = width - destStride;
            step = -1;
        } else if (angle == 0x10e) {
            dst = destBits + point[1] * destStride + point[0] - 1 + height;
            rowAdjust = -1 - destStride * width;
            step = destStride;
        } else {
            dst = destBits + point[1] * destStride + point[0];
            rowAdjust = destStride - width;
            step = 1;
        }
        if (!source->Slot24()) {
            for (; src < srcEnd; src += rowSkip) {
                for (; src < rowEnd; src++) {
                    *dst = *src;
                    dst += step;
                }
                dst += rowAdjust;
                rowEnd += sourceStride;
            }
        } else {
            uint32_t key;
            source->GetTransparentColor(&key);
            for (; src < srcEnd; src += rowSkip) {
                for (; src < rowEnd; src++) {
                    if (*src != static_cast<uint8_t>(key)) {
                        *dst = *src;
                    }
                    dst += step;
                }
                dst += rowAdjust;
                rowEnd += sourceStride;
            }
        }
    }
    source->Unlock(0x8040);
    return true;
}
#endif

// GetAutomaticAxisMajorTickSpacing(Axis, float&): an eighth of the axis range.
// FUNCTION: 0x009b23f6
void cGZGraph::Slot176_ade188(uint32_t axis, uint32_t spacing)
{
    *OB_PTR(float, spacing) = (mfAxisMax[axis] - mfAxisMin[axis]) * 0.125f;
}
