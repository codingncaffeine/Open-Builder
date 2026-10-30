#include "classes/cGZDrawContextRenderToBuffer.h"

#include <math.h>
#include <new>

#include "classes/cUnk00ac182c.h"
#include "classes/cUnk00ac1844.h"
#include "classes/cUnk00ac185c.h"
#include "classes/cUnk00ac1874.h"
#include "classes/cUnk00ac188c.h"

// A COM-style object seen through its first three slots.
struct Unknown_ac17d0 {
    virtual bool QueryInterface(uint32_t iid, void** out) = 0;
    virtual void AddRef() = 0;
    virtual uint32_t Release() = 0;
};

// What the buffer reports about its pixel format (the first word is the format; the buffer fills both).
struct ColorType_ac17d0 {
    int32_t mnFormat;
    int32_t mnExtra;
};

// The buffer interface (GZIID 0x20732180), as far as this class calls it; slots by their offsets.
struct Buffer_ac17d0 {
    virtual bool QueryInterface(uint32_t iid, void** out) = 0;
    virtual void AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual bool Lock(uint32_t flags) = 0;
    virtual void Unlock(uint32_t flags) = 0;
    virtual void Slot08() = 0;
    virtual uint32_t Width() = 0;
    virtual uint32_t Height() = 0;
    virtual void GetBufferArea(void* rect) = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual ColorType_ac17d0* GetColorType(ColorType_ac17d0* out) = 0;
    virtual void Slot16() = 0;
    virtual uint32_t GetBytesPerPixel() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual bool GetTransparentColor(uint32_t* out) = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual uint32_t ConvertRGBValueToNative(uint32_t r, uint32_t g, uint32_t b) = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual uint32_t GetColorSurfaceBits() = 0;
    virtual uint32_t GetColorSurfaceStride() = 0;
};

// The span renderers (one per pixel format) the context draws through.
struct SpanRender_ac17d0 {
    virtual ~SpanRender_ac17d0() {}
    virtual void Fill(const void* spans, int32_t count, const void* dest, uint32_t color) = 0;
    virtual void FillGradient(const void* spans, int32_t count, const void* dest, const void* gradient) = 0;
    virtual void FillBlend(const void* spans, int32_t count, const void* dest, uint32_t color, uint32_t raw) = 0;
    virtual void FillGradientBlend(const void* spans, int32_t count, const void* dest, const void* gradient) = 0;
    virtual void Blt(const void* spans, int32_t count, const void* dest, const void* source, const void* params,
                     uint32_t flags) = 0;
};

// A rectangle: left, top, right, bottom.
struct Rect_ac17d0 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
    void Offset(int32_t dx, int32_t dy)
    {
        mnLeft += dx;
        mnRight += dx;
        mnTop += dy;
        mnBottom += dy;
    }
};

// A surface as the buffer describes it: bits, stride, size, pixel format and bytes per pixel.
struct Surface_ac17d0 {
    uint32_t mnBits;
    uint32_t mnStride;
    uint32_t mnWidth;
    uint32_t mnHeight;
    int32_t mnType;
    uint32_t mnBytesPerPixel;
};

// The source parameters of a Blt: texture start, step, pixel format and transparent colour.
struct BltParams_ac17d0 {
    int32_t mnU;
    int32_t mnV;
    int32_t mnStepX;
    int32_t mnStepY;
    int32_t mnFormat;
    uint32_t mnColor;
    uint32_t mnTransparent;
    bool mbTransparent;
};

inline Buffer_ac17d0* BufferOf_ac17d0(void* p)
{
    return static_cast<Buffer_ac17d0*>(p);
}

// Float to int the way the FPU rounds it (the game's inline conversion), not truncation.
inline int32_t Round_ac17d0(float value)
{
#ifdef _MSC_VER
    __asm {
        fld value
        push eax
        fistp DWORD PTR [esp]
        pop eax
    }
#else
    return static_cast<int32_t>(lrintf(value));
#endif
}

// The integer part of a value by the float-bits trick (adding 1.5 * 2^23 leaves the integer in the mantissa).
#ifdef _MSC_VER
__forceinline
#else
inline
#endif
int32_t Floor_ac17d0(float value)
{
    union {
        float f;
        int32_t i;
    } bits;
    float half = value + 0.5f;
    bits.f = half + 12582912.0f;
    int32_t result = bits.i - 0x4b400000;
    int32_t below = result - 1;
    if (value == static_cast<float>(below)) {
        result = below;
    }
    return result;
}

// FUNCTION: 0x005f47f0
uint32_t cGZDrawContextRenderToBuffer::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x0082fd60
bool cGZDrawContextRenderToBuffer::QueryInterface(uint32_t iid, void* out)
{
    switch (iid) {
    case 1:
    case 0x2ae78a07:
        *static_cast<void**>(out) = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

// FUNCTION: 0x0082fd90
void cGZDrawContextRenderToBuffer::SetClipRect(const void* rect)
{
    *reinterpret_cast<Rect_ac17d0*>(mnClip) = *static_cast<const Rect_ac17d0*>(rect);
}

// FUNCTION: 0x0082fe60
void cGZDrawContextRenderToBuffer::ClearBltTiling()
{
    mbTiling = false;
}

// FUNCTION: 0x0082fe70
void cGZDrawContextRenderToBuffer::SetBltTiling(const void* rect)
{
    mbTiling = true;
    *reinterpret_cast<Rect_ac17d0*>(mnTile) = *static_cast<const Rect_ac17d0*>(rect);
}

// FUNCTION: 0x0082fea0
void cGZDrawContextRenderToBuffer::SetAlphaBlend(int32_t alpha)
{
    mbAlphaBlend = alpha > 0;
}

// FUNCTION: 0x0082fed0
bool cGZDrawContextRenderToBuffer::LockTarget(void* desc, bool)
{
    *static_cast<Surface_ac17d0*>(desc) = *reinterpret_cast<Surface_ac17d0*>(mnSurface);
    return true;
}

// FUNCTION: 0x00a64430
void cGZDrawContextRenderToBuffer::Slot05_ac17d0(void* rect)
{
    BufferOf_ac17d0(mpTarget)->GetBufferArea(rect);
}

// FUNCTION: 0x0082fdb0
void cGZDrawContextRenderToBuffer::SetGradientTransform(const void* matrix, float a, float b)
{
    if (matrix) {
        const float* m = static_cast<const float*>(matrix);
        for (int32_t i = 0; i < 4; ++i) {
            mnGradientB[i] = Round_ac17d0(static_cast<float>(m[4 + i] * 16711680.0));
            mnGradientC[i] = Round_ac17d0(static_cast<float>(m[8 + i] * 16711680.0));
            int32_t base = Round_ac17d0(static_cast<float>(m[i] * 16711680.0)) + 0x8000;
            float pb = static_cast<float>(mnGradientB[i]) * a;
            float pc = static_cast<float>(mnGradientC[i]) * b;
            mnGradientA[i] = static_cast<int32_t>(static_cast<float>(base) - (pb + pc));
        }
        mbGradient = true;
    } else {
        mbGradient = false;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082ff70 score 6
// (the original keeps the count in its argument slot and stores it once before the loop)
void cGZDrawContextRenderToBuffer::SetColorTable(int32_t first, int32_t count, const void* colors)
{
    if (count) {
        const uint32_t* c = static_cast<const uint32_t*>(colors);
        do {
            uint32_t color = *c++;
            mnColors[first] = color;
            mnNatives[first] = BufferOf_ac17d0(mpTarget)->ConvertRGBValueToNative(color >> 16, color >> 8, color);
            ++first;
        } while (--count);
    }
}
#endif

// FUNCTION: 0x0082ff20
void cGZDrawContextRenderToBuffer::Shutdown()
{
    if (mpRender) {
        delete static_cast<SpanRender_ac17d0*>(mpRender);
        mpRender = 0;
    }
    if (mpTarget) {
        if (mbActive) {
            BufferOf_ac17d0(mpTarget)->Unlock(0x8040);
        }
        Unknown_ac17d0* old = static_cast<Unknown_ac17d0*>(mpTarget);
        if (old) {
            mpTarget = 0;
            old->Release();
        }
    }
}

// FUNCTION: 0x008302a0
void cGZDrawContextRenderToBuffer::Suspend()
{
    if (mbActive) {
        BufferOf_ac17d0(mpTarget)->Unlock(0x8040);
        mbActive = false;
    }
}

// FUNCTION: 0x008302c0
void cGZDrawContextRenderToBuffer::Resume()
{
    if (!mbActive) {
        BufferOf_ac17d0(mpTarget)->Lock(0x8040);
        mbActive = true;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00831000 score 20
// (registers match; the original loads the points pointer only after the count test, and op 8 reads it unloaded)
uint32_t cGZDrawContextRenderToBuffer::Slot21_ac17d0(uint32_t op, const void* points, int32_t count)
{
    if (mbEnabled) {
        const float* p = static_cast<const float*>(points);
        if (op == 6) {
            if (count >= 3) {
                uint32_t n = static_cast<uint32_t>(count) / 3;
                do {
                    Fn008308d0(p, 3);
                    p += 6;
                    --n;
                } while (n);
            }
        } else if (op == 7) {
            if (count >= 4) {
                uint32_t n = static_cast<uint32_t>(count) >> 2;
                do {
                    Fn008308d0(p, 4);
                    p += 8;
                    --n;
                } while (n);
            }
        } else if (op == 8) {
            Fn008308d0(p, count);
        } else {
            return 1;
        }
        return 0;
    }
    return 2;
}
#endif

// FUNCTION: 0x0082ffd0
bool cGZDrawContextRenderToBuffer::SetBltSource(void* source, float x, float y, float scaleX, float scaleY, void* outRect)
{
    if (source) {
        Unknown_ac17d0* old = static_cast<Unknown_ac17d0*>(mpSource);
        if (old) {
            mpSource = 0;
            old->Release();
        }
        if (static_cast<Unknown_ac17d0*>(source)->QueryInterface(0x20732180, &mpSource)) {
            Rect_ac17d0 area;
            Rect_ac17d0* out = static_cast<Rect_ac17d0*>(outRect);
            BufferOf_ac17d0(mpSource)->GetBufferArea(&area);
            mnScaleX = Round_ac17d0(static_cast<float>(scaleX * 65536.0));
            mnScaleY = Round_ac17d0(static_cast<float>(scaleY * 65536.0));
            mnInvScaleX = Round_ac17d0(static_cast<float>(65536.0 / scaleX));
            mnInvScaleY = Round_ac17d0(static_cast<float>(65536.0 / scaleY));
            if (mnScaleX == 0x10000 && mnScaleY == 0x10000) {
                mnSourceX = Round_ac17d0(x);
                mnSourceY = Round_ac17d0(y);
                mbScaled = false;
                *out = area;
                out->Offset(mnSourceX, mnSourceY);
            } else {
                mnSourceX = Round_ac17d0(static_cast<float>(mnInvScaleX) * x);
                mnSourceY = Round_ac17d0(static_cast<float>(mnInvScaleY) * y);
                mbScaled = true;
                out->mnLeft = Floor_ac17d0(x - 0.5);
                out->mnTop = Floor_ac17d0(y - 0.5);
                out->mnRight = Floor_ac17d0(static_cast<float>(area.mnRight - area.mnLeft) * scaleX + x - 0.5);
                out->mnBottom = Floor_ac17d0(static_cast<float>(area.mnBottom - area.mnTop) * scaleY + y - 0.5);
            }
            mnDestWidth = out->mnRight - out->mnLeft;
            mnDestHeight = out->mnBottom - out->mnTop;
        }
        return true;
    }
    Unknown_ac17d0* old = static_cast<Unknown_ac17d0*>(mpSource);
    if (old) {
        mpSource = 0;
        old->Release();
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008302e0 score 112
// (instruction scheduling of the parameter stores differs; the permuter only helped by swapping Blt and Unlock, rejected)
void cGZDrawContextRenderToBuffer::DrawPreclippedSpanList(const void* spans, int32_t count)
{
    if (0 != mpSource) {
        if (0 == BufferOf_ac17d0(mpSource)->Lock(0x800)) {
            return;
        } else {
            Surface_ac17d0 srcDesc;
            BltParams_ac17d0 params;
            srcDesc.mnWidth = BufferOf_ac17d0(mpSource)->Width();
            ColorType_ac17d0 colorType;
            srcDesc.mnHeight = BufferOf_ac17d0(mpSource)->Height();
            srcDesc.mnType = BufferOf_ac17d0(mpSource)->GetColorType(&colorType)->mnFormat;
            srcDesc.mnBits = BufferOf_ac17d0(mpSource)->GetColorSurfaceBits();
            srcDesc.mnStride = BufferOf_ac17d0(mpSource)->GetColorSurfaceStride();
            srcDesc.mnBytesPerPixel = BufferOf_ac17d0(mpSource)->GetBytesPerPixel();
            switch (srcDesc.mnType) {
            case 7:
                params.mnFormat = 0;
                break;
            case 6:
                params.mnFormat = 1;
                break;
            case 4:
                params.mnFormat = 2;
                break;
            case 5:
                params.mnFormat = 3;
                break;
            case 9:
                params.mnFormat = 4;
                break;
            case 8:
                params.mnFormat = 5;
                break;
            case 2:
                params.mnFormat = 6;
                break;
            default:
                BufferOf_ac17d0(mpSource)->Unlock(0x800);
                return;
            }
            params.mbTransparent = BufferOf_ac17d0(mpSource)->GetTransparentColor(&params.mnTransparent);
            if (params.mbTransparent != 0) {
                switch (params.mnFormat) {
                case 0:
                    params.mnTransparent &= 0xfff;
                    break;
                case 1:
                case 2:
                    params.mnTransparent &= 0x7fff;
                    break;
                case 3:
                    params.mnTransparent &= 0xffff;
                    break;
                case 4:
                case 5:
                    params.mnTransparent &= 0xffffff;
                    break;
                case 6:
                    params.mbTransparent = false;
                    break;
                }
            }
            params.mnColor = mnColors[0];
            uint32_t flags;
            if (mbAlphaBlend != 0) {
                flags = (mbFlag42 ? 1 : 0) * 2 + 1;
            } else {
                flags = mbFlag42 ? 2 : 0;
            }
            if (mbTiling != 0) {
                srcDesc.mnWidth = mnTile[2] - mnTile[0];
                srcDesc.mnBits = mnTile[0] * srcDesc.mnBytesPerPixel + srcDesc.mnBits + mnTile[1] * srcDesc.mnStride;
                srcDesc.mnHeight = mnTile[3] - mnTile[1];
                params.mnU = (0x7fffffffu - 0x7fffffffu % srcDesc.mnWidth - mnSourceX) % srcDesc.mnWidth;
                params.mnV = (0x7fffffffu - 0x7fffffffu % srcDesc.mnHeight - mnSourceY) % srcDesc.mnHeight;
                flags |= 8;
                static_cast<SpanRender_ac17d0*>(mpRender)->Blt(spans, count, mnSurface, &srcDesc, &params, flags);
                BufferOf_ac17d0(mpSource)->Unlock(0x800);
            } else if (0 != mbScaled) {
                flags |= 4;
                params.mnStepX = mnInvScaleX;
                params.mnU = (params.mnStepX >> 1) - mnSourceX;
                params.mnStepY = mnInvScaleY;
                params.mnV = (params.mnStepY >> 1) - mnSourceY;
                static_cast<SpanRender_ac17d0*>(mpRender)->Blt(spans, count, mnSurface, &srcDesc, &params, flags);
                BufferOf_ac17d0(mpSource)->Unlock(0x800);
            } else {
                srcDesc.mnBits = srcDesc.mnBits - (mnSourceX * srcDesc.mnBytesPerPixel + mnSourceY * srcDesc.mnStride);
                static_cast<SpanRender_ac17d0*>(mpRender)->Blt(spans, count, mnSurface, &srcDesc, &params, flags);
                BufferOf_ac17d0(mpSource)->Unlock(0x800);
            }
        }
    } else if (0 != mbGradient) {
        if (mbAlphaBlend) {
            static_cast<SpanRender_ac17d0*>(mpRender)->FillGradientBlend(spans, count, mnSurface, mnGradientA);
        } else {
            static_cast<SpanRender_ac17d0*>(mpRender)->FillGradient(spans, count, mnSurface, mnGradientA);
        }
    } else if (mbAlphaBlend != 0) {
        static_cast<SpanRender_ac17d0*>(mpRender)->FillBlend(spans, count, mnSurface, mnNatives[0], mnColors[0]);
    } else {
        static_cast<SpanRender_ac17d0*>(mpRender)->Fill(spans, count, mnSurface, mnNatives[0]);
    }
}
#endif

// FUNCTION: 0x00830710
bool cGZDrawContextRenderToBuffer::Init(void* unknown)
{
    Shutdown();
    Unknown_ac17d0* old = static_cast<Unknown_ac17d0*>(mpTarget);
    if (old) {
        mpTarget = 0;
        old->Release();
    }
    if (static_cast<Unknown_ac17d0*>(unknown)->QueryInterface(0x20732180, &mpTarget)) {
        if (BufferOf_ac17d0(mpTarget)->Lock(0x8040)) {
            ColorType_ac17d0 colorType;
            cUnk00ac17ac* render;
            switch (BufferOf_ac17d0(mpTarget)->GetColorType(&colorType)->mnFormat) {
            case 4:
            case 6:
                render = new cUnk00ac182c;
                break;
            case 5:
                render = new cUnk00ac1844;
                break;
            case 7:
                render = new cUnk00ac185c;
                break;
            case 8:
            case 9:
                render = new cUnk00ac1874;
                break;
            case 2:
                render = new cUnk00ac188c;
                break;
            default:
                old = static_cast<Unknown_ac17d0*>(mpTarget);
                if (old) {
                    mpTarget = 0;
                    old->Release();
                }
                return false;
            }
            mpRender = render;
            mnSurface[2] = BufferOf_ac17d0(mpTarget)->Width();
            mnSurface[3] = BufferOf_ac17d0(mpTarget)->Height();
            mnSurface[4] = BufferOf_ac17d0(mpTarget)->GetColorType(&colorType)->mnFormat;
            mnSurface[0] = BufferOf_ac17d0(mpTarget)->GetColorSurfaceBits();
            mnSurface[1] = BufferOf_ac17d0(mpTarget)->GetColorSurfaceStride();
            mnSurface[5] = BufferOf_ac17d0(mpTarget)->GetBytesPerPixel();
            mnWidth = mnSurface[2];
            mnHeight = mnSurface[3];
            mnBytesPerPixel = BufferOf_ac17d0(mpTarget)->GetBytesPerPixel();
            mbTiling = false;
            return mbActive = true;
        }
        old = static_cast<Unknown_ac17d0*>(mpTarget);
        if (old) {
            mpTarget = 0;
            old->Release();
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008306c0 score 9
// (only the destructor's vtable store is missing: the class needs an inline ~cGZDrawContextRenderToBuffer in its header)
uint32_t cGZDrawContextRenderToBuffer::Release()
{
    uint32_t count = --mnRefCount;
    if (count == 0) {
        if (mpRender) {
            delete static_cast<SpanRender_ac17d0*>(mpRender);
        }
        if (mpSource) {
            static_cast<Unknown_ac17d0*>(mpSource)->Release();
        }
        if (mpTarget) {
            static_cast<Unknown_ac17d0*>(mpTarget)->Release();
        }
        ::operator delete(this);
    }
    return count;
}
#endif
