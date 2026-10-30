#include <cstddef>
#include <string.h>

#include "classes/cGZBuffer.h"

// The hardware cache a buffer keeps (field48): told when the transparent colour changes.
struct OB_NOVTABLE HardwareCache_ac1400 {
    virtual bool QueryInterface(uint32_t iid, void** ppOut) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual bool Attach(cGZBuffer* pBuffer) = 0;
    virtual void Slot04_ac1400c() = 0;
    virtual void Slot05_ac1400c() = 0;
    virtual void Slot06_ac1400c() = 0;
    virtual void Slot07_ac1400c() = 0;
    virtual void TransparencyChanged() = 0;
};

// A rectangle: left, top, right and bottom.
struct Rect_ac1400 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
};

// What the graphics system reports for the screen: a pixel format and its bits per pixel (returned through a
// hidden pointer, so the type has a constructor).
struct PixelFormat_ac1400 {
    uint32_t mnFormat;
    uint32_t mnBitsPerPixel;
    PixelFormat_ac1400();
};

// A display mode as the display device (0xc47b747c) describes it: colour depth in the low six bits.
struct DisplayMode_ac1400 {
    uint32_t mnDepth : 6;
    uint32_t mbFlag40 : 1;
    uint32_t mbFlag80 : 1;
    uint32_t mbFlag100 : 1;
    uint32_t mnRest : 23;
    uint32_t mnValues[7];
};

struct OB_NOVTABLE DisplayDevice_ac1400 {
    virtual bool QueryInterface(uint32_t iid, void** ppOut) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Slot03_ac1400d() = 0;
    virtual void Slot04_ac1400d() = 0;
    virtual void Slot05_ac1400d() = 0;
    virtual void Slot06_ac1400d() = 0;
    virtual void Slot07_ac1400d() = 0;
    virtual void Slot08_ac1400d() = 0;
    virtual void Slot09_ac1400d() = 0;
    virtual void Slot10_ac1400d() = 0;
    virtual void Slot11_ac1400d() = 0;
    virtual void Slot12_ac1400d() = 0;
    virtual void Slot13_ac1400d() = 0;
    virtual void Slot14_ac1400d() = 0;
    virtual void GetDisplayMode(DisplayMode_ac1400* pMode) = 0;
};

struct OB_NOVTABLE GraphicsSystem_ac1400 {
    virtual bool QueryInterface(uint32_t iid, void** ppOut) = 0;
    virtual void Slot01_ac1400g() = 0;
    virtual void Slot02_ac1400g() = 0;
    virtual void Slot03_ac1400g() = 0;
    virtual void Slot04_ac1400g() = 0;
    virtual void Slot05_ac1400g() = 0;
    virtual void Slot06_ac1400g() = 0;
    virtual void Slot07_ac1400g() = 0;
    virtual void Slot08_ac1400g() = 0;
    virtual PixelFormat_ac1400 GetPixelFormat() = 0;
};

// RZ::GS(): the graphics system.
// STUB: 0x00913c1a
GraphicsSystem_ac1400* Fn00913c1a();

// The colour type: format and bits per pixel.
struct ColorType_ac1400 {
    uint32_t mnFormat;
    uint32_t mnBitsPerPixel;
};

// FUNCTION: 0x00825ce0
bool cGZBuffer::Shutdown()
{
    DestroySurfaces();
    field8 = false;
    return true;
}

// FUNCTION: 0x00825d60
uint32_t cGZBuffer::Slot01_ac1400()
{
    return ++mnRefCount;
}

// FUNCTION: 0x00825d70
uint32_t cGZBuffer::Slot02_ac1400()
{
    if (mnRefCount == 1) {
        mnRefCount = 0;
        delete this;
        return 0;
    }
    return --mnRefCount;
}

// FUNCTION: 0x00826330
uint32_t cGZBuffer::GetMemoryUsage()
{
    if (field3c) {
        return (((field1c - 1) | 3) + 1) * (field10 >> 3) * field20;
    }
    return 0;
}

// FUNCTION: 0x00826350
bool cGZBuffer::CreateSurfaces()
{
    if (!InitializeSurfaces()) {
        field3c = 0;
        return false;
    }
    return true;
}

// FUNCTION: 0x00826370
bool cGZBuffer::DestroySurfaces()
{
    operator delete(field3c);
    field3c = 0;
    return true;
}

// FUNCTION: 0x00826490
bool cGZBuffer::Slot07_ac1400(uint32_t flags)
{
    mnLockFlags &= ~flags;
    --mnLockCount;
    return true;
}

// FUNCTION: 0x008268b0
bool cGZBuffer::IsLocked()
{
    return mnLockCount != 0;
}

// FUNCTION: 0x008268d0
void cGZBuffer::GetBufferArea(uint32_t pOut)
{
    *OB_PTR(Rect_ac1400, pOut) = *reinterpret_cast<const Rect_ac1400*>(field14);
}

// FUNCTION: 0x008268f0
void cGZBuffer::GetColorType(uint32_t pOut)
{
    ColorType_ac1400* out = OB_PTR(ColorType_ac1400, pOut);
    out->mnFormat = mnColorType;
    out->mnBitsPerPixel = field10;
}

// FUNCTION: 0x00826910
uint32_t cGZBuffer::GetBytesPerPixel()
{
    return field10 >> 3;
}

// FUNCTION: 0x00826920
uint32_t cGZBuffer::GetTransparency()
{
    return (mnFlags >> 1) & 1;
}

// FUNCTION: 0x00826a10
void cGZBuffer::SetTransparency(uint32_t color)
{
    mnTransparentColor = color;
    mnFlags |= 2;
    if (field48) {
        static_cast<HardwareCache_ac1400*>(field48)->TransparencyChanged();
    }
}

// FUNCTION: 0x00826a30
void cGZBuffer::RemoveTransparency()
{
    mnFlags &= ~2u;
    if (field48) {
        static_cast<HardwareCache_ac1400*>(field48)->TransparencyChanged();
    }
}

// FUNCTION: 0x00826620
bool cGZBuffer::GetTransparentColor(uint32_t pColor)
{
    if (mnFlags & 2) {
        *OB_PTR(uint32_t, pColor) = mnTransparentColor;
        return true;
    }
    return false;
}

// FUNCTION: 0x00825d00
bool cGZBuffer::QueryInterface(uint32_t iid, uint32_t pOut)
{
    switch (iid) {
    case 0x86d72b57:
        *OB_PTR(cUnk00ac13d8*, pOut) = static_cast<cUnk00ac13d8*>(this);
        Slot01_ac1400();
        return true;
    case 1:
    case 0x20732180:
        *OB_PTR(cGZBuffer_0*, pOut) = this;
        Slot01_ac1400();
        return true;
    }
    return false;
}

// FUNCTION: 0x00826aa0
bool cGZBuffer::Slot06_ac1400(uint32_t flags)
{
    if (field3c) {
        if (flags & 0x8000) {
            field30++;
        }
        mnLockFlags |= flags;
        ++mnLockCount;
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00826a50 score 5
bool cGZBuffer::InitializeSurfaces()
{
    Slot45_ac1400();
    uint32_t bytes = field10 >> 3;
    uint32_t stride = (field1c * bytes + 3) & ~3u;
    field3c = operator new(field20 * stride);
    field40 = stride;
    mnBytesPerPixel = static_cast<uint8_t>(bytes);
    field30++;
    return true;
}
#endif

// FUNCTION: 0x00826950
bool cGZBuffer::SetHardwareCache(void* pCache)
{
    HardwareCache_ac1400* cache = static_cast<HardwareCache_ac1400*>(pCache);
    if (field48) {
        HardwareCache_ac1400* old = static_cast<HardwareCache_ac1400*>(field48);
        field48 = 0;
        old->Release();
    }
    if (cache->Attach(this)) {
        HardwareCache_ac1400* old = static_cast<HardwareCache_ac1400*>(field48);
        if (cache != old) {
            cache->AddRef();
            field48 = cache;
            if (old) {
                old->Release();
            }
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x008269b0
bool cGZBuffer::Slot03_ac1400(uint32_t width, uint32_t height, uint32_t colorType, uint32_t bitsPerPixel)
{
    if (!field8 && width && height) {
        field1c = width;
        field20 = height;
        *reinterpret_cast<int32_t*>(field14) = 0;
        *reinterpret_cast<int32_t*>(field14 + 4) = 0;
        mnColorType = colorType;
        field10 = bitsPerPixel;
        if (CreateSurfaces()) {
            field8 = true;
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x00826650
bool cGZBuffer::Slot03_ac13d8(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
    mnShadeColor = ((((static_cast<uint8_t>(a) << 8) | static_cast<uint8_t>(b)) << 8) | static_cast<uint8_t>(g)) << 8
        | static_cast<uint8_t>(r);
    return true;
}

// FUNCTION: 0x00826680
bool cGZBuffer::Slot04_ac13d8(uint32_t pR, uint32_t pG, uint32_t pB, uint32_t pA)
{
    if (mnShadeColor != 0xffffffff) {
        const uint8_t* bytes = reinterpret_cast<const uint8_t*>(&mnShadeColor);
        *OB_PTR(uint8_t, pR) = bytes[0];
        *OB_PTR(uint8_t, pG) = bytes[1];
        *OB_PTR(uint8_t, pB) = bytes[2];
        *OB_PTR(uint8_t, pA) = bytes[3];
        return true;
    }
    return false;
}

// FUNCTION: 0x00826510
uint32_t cGZBuffer::GetPixel(uint32_t x, uint32_t y)
{
    uint32_t bytes = mnBytesPerPixel;
    const uint8_t* p = static_cast<const uint8_t*>(field3c) + y * field40 + bytes * x;
    switch (bytes) {
    case 2:
        return *reinterpret_cast<const uint16_t*>(p);
    case 3:
        return (static_cast<uint32_t>(p[2]) << 8 | p[1]) << 8 | p[0];
    case 4:
        return *reinterpret_cast<const uint32_t*>(p);
    }
    return *p;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00826560 score 33
void cGZBuffer::SetPixel(uint32_t x, uint32_t y, uint32_t color)
{
    uint32_t bytes = mnBytesPerPixel;
    uint8_t* p = static_cast<uint8_t*>(field3c) + y * field40 + bytes * x;
    if (bytes == 3) {
        p[2] = static_cast<uint8_t>(color >> 16);
        p[1] = static_cast<uint8_t>(color >> 8);
        p[0] = static_cast<uint8_t>(color);
    } else if (bytes == 4) {
        *reinterpret_cast<uint32_t*>(p) = color;
    } else if (bytes == 2) {
        *reinterpret_cast<uint16_t*>(p) = static_cast<uint16_t>(color);
    }
}
#endif

// FUNCTION: 0x008264c0
uint32_t Fn008264c0(const uint32_t* pColorType)
{
    switch (*pColorType) {
    case 4:
        return 0;
    case 5:
        return 1;
    case 6:
        return 2;
    case 7:
        return 3;
    case 8:
        return 4;
    case 9:
        return 5;
    }
    return 0;
}

// FUNCTION: 0x00991950
bool cGZBuffer::Fill(uint32_t color, uint32_t pClip)
{
    return Fill_3(color, OB_ADDR(GetBufferArea_2()), pClip);
}

// FUNCTION: 0x0082b2f0
bool cGZBuffer::Fill_2(uint32_t color, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t pClip)
{
    Rect_ac1400 rect;
    rect.mnLeft = x;
    rect.mnTop = y;
    rect.mnRight = width;
    rect.mnBottom = height;
    return Fill_3(color, OB_ADDR(&rect), pClip);
}

// FUNCTION: 0x00825da0
uint32_t cGZBuffer::ConvertRGBValueToNative(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t result = 0;
    switch (mnColorType) {
    case 4:
    case 6:
        result = (r & 0xf8) * 0x80 + (g & 0xf8) * 4 + 0x8000 + (b >> 3);
        break;
    case 5:
        result = (r & 0xf8) * 0x100 + (g & 0xfc) * 8 + (b >> 3);
        break;
    case 7:
        result = (r & 0xf0) * 0x10 + (g & 0xf0) + 0xf000 + (b >> 4);
        break;
    case 8:
    case 9:
        result = r * 0x10000 + g * 0x100 + 0xff000000 + b;
        break;
    }
    return result;
}

// FUNCTION: 0x00825e80
uint32_t cGZBuffer::ConvertRGBAValueToNative(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    uint32_t result = 0;
    switch (mnColorType) {
    case 4:
    case 6:
        result = (a & 0x80) * 0x100 + (r & 0xf8) * 0x80 + (g & 0xf8) * 4 + (b >> 3);
        break;
    case 5:
        result = (r & 0xf8) * 0x100 + (g & 0xfc) * 8 + (b >> 3);
        break;
    case 7:
        result = (a & 0xf0) * 0x100 + (r & 0xf0) * 0x10 + (g & 0xf0) + (b >> 4);
        break;
    case 8:
    case 9:
        result = a * 0x1000000 + r * 0x10000 + g * 0x100 + b;
        break;
    }
    return result;
}

// FUNCTION: 0x00825f80
bool cGZBuffer::ConvertNativeValueToRGB(uint32_t value, void* pR, void* pG, void* pB)
{
    uint8_t* r = static_cast<uint8_t*>(pR);
    uint8_t* g = static_cast<uint8_t*>(pG);
    uint8_t* b = static_cast<uint8_t*>(pB);
    switch (mnColorType) {
    case 4:
    case 6:
        *r = static_cast<uint8_t>((value & 0x7c00) * 0x21 >> 12);
        *g = static_cast<uint8_t>((value & 0x3e0) * 0x21 >> 7);
        *b = static_cast<uint8_t>((value & 0x1f) * 0x21 >> 2);
        return true;
    case 5:
        *r = static_cast<uint8_t>((value & 0xf800) * 0x21 >> 13);
        *g = static_cast<uint8_t>((value & 0x7e0) * 0x41 >> 9);
        *b = static_cast<uint8_t>((value & 0x1f) * 0x21 >> 2);
        return true;
    case 7:
        *r = static_cast<uint8_t>((value & 0xf00) * 0x11 >> 8);
        *g = static_cast<uint8_t>((value & 0xf0) * 0x11 >> 4);
        *b = static_cast<uint8_t>((value & 0xf) * 0x11);
        return true;
    case 8:
    case 9:
        *r = static_cast<uint8_t>(value >> 16);
        *g = static_cast<uint8_t>(value >> 8);
        *b = static_cast<uint8_t>(value);
        return true;
    }
    return false;
}

// FUNCTION: 0x008260a0
bool cGZBuffer::ConvertNativeValueToRGBA(uint32_t value, void* pR, void* pG, void* pB, void* pA)
{
    uint8_t* r = static_cast<uint8_t*>(pR);
    uint8_t* g = static_cast<uint8_t*>(pG);
    uint8_t* b = static_cast<uint8_t*>(pB);
    uint8_t* a = static_cast<uint8_t*>(pA);
    switch (mnColorType) {
    case 4:
    case 6: {
        uint8_t alpha = static_cast<uint8_t>((value & 0x8000) * 0x21 >> 13);
        *a = alpha;
        if (alpha == 1) {
            *a = 0xff;
        }
        *r = static_cast<uint8_t>((value & 0x7c00) * 0x21 >> 12);
        *g = static_cast<uint8_t>((value & 0x3e0) * 0x21 >> 7);
        *b = static_cast<uint8_t>((value & 0x1f) * 0x21 >> 2);
        return true;
    }
    case 5:
        *a = 0xff;
        *r = static_cast<uint8_t>((value & 0xf800) * 0x21 >> 13);
        *g = static_cast<uint8_t>((value & 0x7e0) * 0x41 >> 9);
        *b = static_cast<uint8_t>((value & 0x1f) * 0x21 >> 2);
        return true;
    case 7: {
        uint8_t alpha = static_cast<uint8_t>(static_cast<uint8_t>((value & 0xf000) * 0x11 >> 12) << 4);
        *a = alpha;
        if (alpha == 0xf0) {
            *a = 0xff;
        }
        *r = static_cast<uint8_t>((value & 0xf00) * 0x11 >> 8);
        *g = static_cast<uint8_t>((value & 0xf0) * 0x11 >> 4);
        *b = static_cast<uint8_t>((value & 0xf) * 0x11);
        return true;
    }
    case 8:
    case 9:
        *a = static_cast<uint8_t>(value >> 24);
        *r = static_cast<uint8_t>(value >> 16);
        *g = static_cast<uint8_t>(value >> 8);
        *b = static_cast<uint8_t>(value);
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00826210 score 46
bool cGZBuffer::GenericBufferClip(void* pBuffer, void* pSrcRect, void* pDstRect, const void* pClip)
{
    cGZBuffer_0* buffer = static_cast<cGZBuffer_0*>(pBuffer);
    Rect_ac1400* dst = static_cast<Rect_ac1400*>(pDstRect);
    Rect_ac1400* src = static_cast<Rect_ac1400*>(pSrcRect);
    const Rect_ac1400* clip = static_cast<const Rect_ac1400*>(pClip);
    int32_t right = dst->mnRight;
    int32_t over = right - static_cast<Rect_ac1400*>(buffer->GetBufferArea_2())->mnRight;
    if (over > 0) {
        dst->mnRight = right - over;
        src->mnRight -= over;
        if (dst->mnRight <= dst->mnLeft) {
            return false;
        }
    }
    int32_t left = dst->mnLeft;
    over = -left;
    if (over > 0) {
        dst->mnLeft = left + over;
        src->mnLeft += over;
        if (dst->mnLeft >= dst->mnRight) {
            return false;
        }
    }
    int32_t bottom = dst->mnBottom;
    over = bottom - static_cast<Rect_ac1400*>(buffer->GetBufferArea_2())->mnBottom;
    if (over > 0) {
        dst->mnBottom = bottom - over;
        src->mnBottom -= over;
        if (dst->mnBottom <= dst->mnTop) {
            return false;
        }
    }
    int32_t top = dst->mnTop;
    over = -top;
    if (over > 0) {
        dst->mnTop = top + over;
        src->mnTop += over;
        if (dst->mnTop >= dst->mnBottom) {
            return false;
        }
    }
    if (clip) {
        right = dst->mnRight;
        over = right - clip->mnRight;
        if (over > 0) {
            dst->mnRight = right - over;
            src->mnRight -= over;
        }
        left = dst->mnLeft;
        over = clip->mnLeft - left;
        if (over > 0) {
            dst->mnLeft = left + over;
            src->mnLeft += over;
        }
        bottom = dst->mnBottom;
        over = bottom - clip->mnBottom;
        if (over > 0) {
            dst->mnBottom = bottom - over;
            src->mnBottom -= over;
        }
        top = dst->mnTop;
        over = clip->mnTop - top;
        if (over > 0) {
            dst->mnTop = top + over;
            src->mnTop += over;
        }
    }
    if (dst->mnLeft >= dst->mnRight) {
        return false;
    }
    if (dst->mnTop >= dst->mnBottom) {
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00826ad0 score 55
bool cGZBuffer::Blt(uint32_t pSource, uint32_t pSrcRect, uint32_t pDstRect, uint32_t pClip)
{
    Rect_ac1400 src = *OB_PTR(Rect_ac1400, pSrcRect);
    Rect_ac1400 dst = *OB_PTR(Rect_ac1400, pDstRect);
    dst.mnRight = src.mnRight - src.mnLeft + dst.mnLeft;
    dst.mnBottom = src.mnBottom - src.mnTop + dst.mnTop;
    if (!GenericBufferClip(this, &src, &dst, OB_PTR(const void, pClip))) {
        return false;
    }
    return Slot46_ac1400(OB_PTR(void, pSource), &src, &dst);
}
#endif

// DeterminePixelFormat: a buffer of an unset colour type (1 or 3) takes the screen's.
// FUNCTION: 0x00826390
void cGZBuffer::Slot45_ac1400()
{
    if (mnColorType == 3 || mnColorType == 1) {
        GraphicsSystem_ac1400* system = Fn00913c1a();
        DisplayDevice_ac1400* device = 0;
        if (system) {
            if (system->QueryInterface(0xc47b747c, reinterpret_cast<void**>(&device))) {
                DisplayMode_ac1400 mode;
                mode.mnDepth = 0;
                mode.mbFlag40 = 1;
                mode.mbFlag80 = 0;
                mode.mbFlag100 = 0;
                mode.mnValues[0] = 0;
                mode.mnValues[1] = 0;
                mode.mnValues[2] = 0;
                mode.mnValues[3] = 0;
                device->GetDisplayMode(&mode);
                mode.mbFlag80 = 1;
                if (mode.mnDepth > 16) {
                    field10 = 0x20;
                    mnColorType = 9;
                } else {
                    field10 = 0x10;
                    mnColorType = 7;
                }
                device->Release();
            } else {
                PixelFormat_ac1400 format = system->GetPixelFormat();
                mnColorType = format.mnFormat;
                field10 = format.mnBitsPerPixel;
            }
        } else {
            mnColorType = 5;
            field10 = 0x10;
        }
    }
}

// Clips a line to a rectangle (Cohen-Sutherland): the outcode has 4 for left of the rectangle, 8 for right, 1 for
// above and 2 for below. Moves the end points that lie outside onto the border.
#ifdef OB_DRAFTS
// CLOSE: 0x00930f70 score 288
bool Fn00930f70(int32_t* x0, int32_t* y0, int32_t* x1, int32_t* y1, int32_t left, int32_t top, int32_t right, int32_t bottom)
{
    int32_t code0 = 0;
    if (*x0 < left) {
        code0 = 4;
    }
    if (right < *x0) {
        code0 += 8;
    }
    if (*y0 < top) {
        code0 += 1;
    }
    if (bottom < *y0) {
        code0 += 2;
    }
    int32_t code1 = 0;
    if (*x1 < left) {
        code1 = 4;
    }
    if (right < *x1) {
        code1 += 8;
    }
    if (*y1 < top) {
        code1 += 1;
    }
    if (bottom < *y1) {
        code1 += 2;
    }
    for (;;) {
        if (code0 == 0 && code1 == 0) {
            return true;
        }
        if ((code0 & code1) != 0) {
            return false;
        }
        int32_t code = code1;
        if (code0 != 0) {
            code = code0;
        }
        int32_t x = 0;
        int32_t y = 0;
        if ((code & 1) != 0) {
            y = top;
            x = (top - *y0) * (*x1 - *x0) / (*y1 - *y0) + *x0;
        } else if ((code & 2) != 0) {
            y = bottom;
            x = (bottom - *y0) * (*x1 - *x0) / (*y1 - *y0) + *x0;
        } else if ((code & 8) != 0) {
            x = right;
            y = (right - *x0) * (*y1 - *y0) / (*x1 - *x0) + *y0;
        } else if ((code & 4) != 0) {
            x = left;
            y = (left - *x0) * (*y1 - *y0) / (*x1 - *x0) + *y0;
        }
        if (code == code0) {
            *x0 = x;
            *y0 = y;
            code0 = 0;
            if (*x0 < left) {
                code0 = 4;
            }
            if (right < *x0) {
                code0 += 8;
            }
            if (y < top) {
                code0 += 1;
            }
            if (bottom < y) {
                code0 += 2;
            }
        } else {
            *x1 = x;
            *y1 = y;
            code1 = 0;
            if (*x1 < left) {
                code1 = 4;
            }
            if (right < *x1) {
                code1 += 8;
            }
            if (y < top) {
                code1 += 1;
            }
            if (bottom < y) {
                code1 += 2;
            }
        }
    }
}
#endif

// STUB: 0x0090ffc8
void memset16(void* destination, uint16_t value, uint32_t count);
// STUB: 0x00910003
void memset32(void* destination, uint32_t value, uint32_t count);

#ifdef OB_DRAFTS
// CLOSE: 0x00826ec0 score 254
bool cGZBuffer::Fill_3(uint32_t color, uint32_t pRect, uint32_t pClip)
{
    const Rect_ac1400* rect = OB_PTR(const Rect_ac1400, pRect);
    Rect_ac1400 area;
    area.mnLeft = 0;
    area.mnTop = 0;
    area.mnRight = rect->mnRight - rect->mnLeft;
    area.mnBottom = rect->mnBottom - rect->mnTop;
    Rect_ac1400 target;
    target.mnLeft = rect->mnLeft;
    target.mnTop = rect->mnTop;
    target.mnRight = rect->mnRight;
    target.mnBottom = rect->mnBottom;
    if (!GenericBufferClip(this, &area, &target, OB_PTR(const void, pClip))) {
        return false;
    }
    if (field10 == 0x10) {
        uint8_t* bits = static_cast<uint8_t*>(field3c);
        uint32_t stride = GetColorSurfaceStride() >> 1;
        uint16_t* row = reinterpret_cast<uint16_t*>(bits) + (stride * target.mnTop + target.mnLeft);
        for (uint32_t y = target.mnTop; y < static_cast<uint32_t>(target.mnBottom); ++y) {
            memset16(row, static_cast<uint16_t>(color), target.mnRight - target.mnLeft);
            row += stride;
        }
    } else if (field10 == 8) {
        uint8_t* bits = static_cast<uint8_t*>(field3c);
        uint32_t stride = GetColorSurfaceStride();
        uint8_t* row = bits + stride * target.mnTop + target.mnLeft;
        for (uint32_t y = target.mnTop; y < static_cast<uint32_t>(target.mnBottom); ++y) {
            memset(row, color & 0xff, target.mnRight - target.mnLeft);
            row += stride;
        }
    } else if (field10 != 0x18 && field10 == 0x20) {
        uint8_t* bits = static_cast<uint8_t*>(field3c);
        uint32_t stride = GetColorSurfaceStride() >> 2;
        uint32_t* row = reinterpret_cast<uint32_t*>(bits) + (stride * target.mnTop + target.mnLeft);
        for (uint32_t y = target.mnTop; y < static_cast<uint32_t>(target.mnBottom); ++y) {
            memset32(row, color, target.mnRight - target.mnLeft);
            row += stride;
        }
    }
    ++field30;
    return true;
}
#endif

#ifdef OB_DRAFTS
// The surface a blitting loop reads from or writes to, and what it needs besides (the transparent colour).
struct BltTarget_ac1400 {
    uint8_t* mpBits;
    int32_t mnStride;
    int32_t mnWidth;
    int32_t mnHeight;
    uint32_t mnFormat;
    uint32_t mnBytesPerPixel;
};

struct BltOptions_ac1400 {
    uint32_t mnReserved[6];
    uint32_t mnTransparentColor;
    uint32_t mbTransparent;
};

typedef void (*Blitter_ac1400)(int32_t width, int32_t height, BltTarget_ac1400 destination, BltTarget_ac1400 source,
                               BltOptions_ac1400 options);

// The blitting loops for a pair of colour types: the opaque one and the one that skips the transparent colour.
struct BlitterPair_ac1400 {
    Blitter_ac1400 mpOpaque;
    Blitter_ac1400 mpTransparent;
};

// GLOBAL: 0x00b105a0
extern BlitterPair_ac1400 gB105a0[];

// The colour bits a colour type uses (0x00825c90 takes its argument in eax, which C++ cannot say).
inline uint32_t ColorMask_ac1400(uint32_t format)
{
    switch (format) {
    case 4:
    case 6:
        return 0x7fff;
    case 5:
        return 0xffff;
    case 7:
        return 0xfff;
    case 8:
    case 9:
        return 0xffffff;
    }
    return 0xffffffff;
}

inline uint32_t BytesOfFormat_ac1400(uint32_t format)
{
    switch (format) {
    case 4:
    case 5:
    case 6:
    case 7:
        return 2;
    case 8:
    case 9:
        return 4;
    }
    return 0;
}

// CLOSE: 0x00826b80 score 333
bool cGZBuffer::Slot46_ac1400(void* pSource, void* pSrcRect, void* pDstRect)
{
    cGZBuffer_0* source = static_cast<cGZBuffer_0*>(pSource);
    const Rect_ac1400* srcRect = static_cast<const Rect_ac1400*>(pSrcRect);
    const Rect_ac1400* dstRect = static_cast<const Rect_ac1400*>(pDstRect);
    ++field30;
    ColorType_ac1400 sourceColor;
    source->Slot15_ac1400(OB_ADDR(&sourceColor));
    int32_t sourceStride = source->GetColorSurfaceStride();
    int32_t targetStride = GetColorSurfaceStride();
    int32_t width = dstRect->mnRight - dstRect->mnLeft;
    int32_t height = dstRect->mnBottom - dstRect->mnTop;
    int32_t sourceBytes = BytesOfFormat_ac1400(sourceColor.mnFormat);
    int32_t targetBytes = BytesOfFormat_ac1400(mnColorType);
    uint32_t index = Fn008264c0(&sourceColor.mnFormat) + Fn008264c0(&mnColorType) * 6;
    Blitter_ac1400 transparentBlitter = gB105a0[index].mpTransparent;
    Blitter_ac1400 opaqueBlitter = gB105a0[index].mpOpaque;
    uint8_t* targetBits = static_cast<uint8_t*>(GetColorSurfaceBits());
    uint8_t* sourceBits = static_cast<uint8_t*>(source->GetColorSurfaceBits());
    if (targetBits && sourceBits) {
        uint8_t* targetPtr = targetBits + dstRect->mnLeft * targetBytes + dstRect->mnTop * targetStride;
        uint8_t* sourcePtr = sourceBits + srcRect->mnLeft * sourceBytes + srcRect->mnTop * sourceStride;
        if (source == this && srcRect->mnTop < dstRect->mnBottom && srcRect->mnBottom > dstRect->mnTop) {
            // the rectangles overlap in a buffer: copy from the bottom up
            targetPtr += (dstRect->mnBottom - dstRect->mnTop - 1) * targetStride;
            sourcePtr += (srcRect->mnBottom - srcRect->mnTop - 1) * sourceStride;
            sourceStride = -sourceStride;
            targetStride = -targetStride;
        }
        BltOptions_ac1400 options;
        for (int i = 0; i < 6; ++i) {
            options.mnReserved[i] = 0;
        }
        options.mnTransparentColor = 0;
        uint32_t color = 0;
        options.mbTransparent = source->GetTransparentColor(OB_ADDR(&color));
        BltTarget_ac1400 target = { targetPtr, targetStride, width, height, mnColorType, static_cast<uint32_t>(targetBytes) };
        BltTarget_ac1400 from = { sourcePtr, sourceStride, width, height, sourceColor.mnFormat, static_cast<uint32_t>(sourceBytes) };
        if (options.mbTransparent) {
            options.mnTransparentColor = color & ColorMask_ac1400(sourceColor.mnFormat);
            transparentBlitter(width, height, target, from, options);
        } else {
            opaqueBlitter(width, height, target, from, options);
        }
    }
    return true;
}

// CLOSE: 0x00827380 score 818
bool cGZBuffer::DrawLine(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint32_t color, uint32_t thickness)
{
    int32_t ax = x0;
    int32_t ay = y0;
    int32_t bx = x1;
    int32_t by = y1;
    uint8_t* bits = static_cast<uint8_t*>(GetColorSurfaceBits());
    uint32_t stride = GetColorSurfaceStride();
    int32_t maxX = field1c - thickness;
    int32_t maxY = field20 - thickness;
    if (!Fn00930f70(&ax, &ay, &bx, &by, 0, 0, maxX, maxY)) {
        return true;
    }
    if (ay == by) {
        int32_t left = ax;
        int32_t right = bx;
        if (bx < ax) {
            left = bx;
            right = ax;
        }
        Fill_2(color, left, ay, right + 1, thickness + ay, 0);
        return true;
    }
    if (ax == bx) {
        int32_t top = ay;
        int32_t bottom = by;
        if (by < ay) {
            top = by;
            bottom = ay;
        }
        Fill_2(color, ax, top, thickness + ax, bottom + 1, 0);
        return true;
    }
    if (bits == 0) {
        return true;
    }
    int32_t dx = bx - ax;
    if (dx < 0) {
        dx = -dx;
    }
    int32_t dy = by - ay;
    if (dy < 0) {
        dy = -dy;
    }
    bool steep = dx < dy;
    int32_t step2;
    int32_t error;
    int32_t errorStep;
    int32_t count;
    if (steep) {
        step2 = dx * 2;
        error = step2 - dy;
        errorStep = dx - dy;
        count = dy;
    } else {
        step2 = dy * 2;
        error = step2 - dx;
        errorStep = dy - dx;
        count = dx;
    }
    errorStep *= 2;
    count += 1;
    int32_t minorX = steep ? 0 : 1;
    int32_t minorY = steep ? 1 : 0;
    int32_t majorX = 1;
    int32_t majorY = 1;
    if (bx < ax) {
        minorX = -minorX;
        majorX = -1;
    }
    if (by < ay) {
        minorY = -minorY;
        majorY = -1;
    }
    int32_t x = ax;
    int32_t y = ay;
    if (thickness != 1) {
        if (thickness == 0) {
            return true;
        }
        uint32_t pitch = (stride >> 1) & 0xffff;
        for (int32_t i = 0; i != count; ++i) {
            uint16_t* p = reinterpret_cast<uint16_t*>(bits) + (y * pitch + x);
            for (uint32_t row = 0; row != (thickness & 0xffff); ++row) {
                for (uint32_t column = 0; column < thickness; ++column) {
                    p[column] = static_cast<uint16_t>(color);
                }
                p += (majorY == -1 ? -static_cast<int32_t>(pitch) : static_cast<int32_t>(pitch));
            }
            if (error < 0) {
                x += minorX;
                y += minorY;
                error += step2;
            } else {
                x += majorX;
                y += majorY;
                error += errorStep;
            }
        }
        return true;
    }
    uint32_t bpp = GetBitsPerPixel();
    if (bpp == 0x10) {
        uint8_t* row = bits + y * stride;
        for (int32_t i = 1; i <= count; ++i) {
            *reinterpret_cast<uint16_t*>(row + x * 2) = static_cast<uint16_t>(color);
            if (error < 0) {
                error += step2;
                x += minorX;
                row += minorY * stride;
            } else {
                error += errorStep;
                x += majorX;
                row += majorY * stride;
            }
        }
    } else if (bpp == 8) {
        uint8_t* row = bits + y * stride;
        for (int32_t i = 1; i <= count; ++i) {
            row[x] = static_cast<uint8_t>(color);
            if (error < 0) {
                error += step2;
                x += minorX;
                row += minorY * stride;
            } else {
                error += errorStep;
                x += majorX;
                row += majorY * stride;
            }
        }
    } else if (bpp == 0x18) {
        uint8_t* row = bits + y * stride;
        for (int32_t i = 1; i <= count; ++i) {
            row[x * 3] = static_cast<uint8_t>(color);
            row[x * 3 + 1] = static_cast<uint8_t>(color >> 8);
            row[x * 3 + 2] = static_cast<uint8_t>(color >> 16);
            if (error < 0) {
                error += step2;
                x += minorX;
                row += minorY * stride;
            } else {
                error += errorStep;
                x += majorX;
                row += majorY * stride;
            }
        }
    } else if (bpp == 0x20) {
        uint8_t* row = bits + y * stride;
        for (int32_t i = 1; i <= count; ++i) {
            *reinterpret_cast<uint32_t*>(row + x * 4) = color;
            if (error < 0) {
                error += step2;
                x += minorX;
                row += minorY * stride;
            } else {
                error += errorStep;
                x += majorX;
                row += majorY * stride;
            }
        }
    }
    return true;
}
#endif
