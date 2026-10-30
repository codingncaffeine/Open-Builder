#include "classes/cUnk00ac188c.h"
#include <stddef.h>
#include <string.h>

// The 15/16-bit span renderer: the table at 0xac188c holds the five thiscall entries every pixel format shares
// (fill, gradient fill, blt dispatch) and the blit kernels, which are plain cdecl functions taking the spans, their
// count and the destination, source and parameter records by value; Slot05 picks one from the table at 0xac26b0.

// A surface as the span renderers take it: bits, stride, size, pixel format and bytes per pixel.
struct Surface_ac188c {
    uint8_t* mpBits;
    int32_t mnStride;
    uint32_t mnWidth;
    uint32_t mnHeight;
    int32_t mnType;
    uint32_t mnBytesPerPixel;
};

// The source parameters of a Blt: texture start, step, pixel format, colour and the transparent colour.
struct BltParams_ac188c {
    int32_t mnU;
    int32_t mnV;
    int32_t mnStepX;
    int32_t mnStepY;
    int32_t mnFormat;
    uint32_t mnColor;
    uint32_t mnTransparent;
    bool mbTransparent;
};

// The colour components of a pixel while it is converted (a record, so the compiler keeps the masks where each lands).
struct Rgb_ac188c {
    uint32_t mnRed;
    uint32_t mnGreen;
    uint32_t mnBlue;
    uint32_t mnAlpha;
};

// The gradient of a gradient fill: start value and per-pixel and per-row steps, at 0xc, 0x1c and 0x2c.
struct Gradient_ac188c {
    uint32_t mnUnused00;
    uint32_t mnUnused04;
    uint32_t mnUnused08;
    int32_t mnStart;
    uint32_t mnUnused10;
    uint32_t mnUnused14;
    uint32_t mnUnused18;
    int32_t mnStepX;
    uint32_t mnUnused20;
    uint32_t mnUnused24;
    uint32_t mnUnused28;
    int32_t mnStepY;
};

typedef void (*BlitFn_ac188c)(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src,
                              BltParams_ac188c params);

// The rounding term of the colour modulation: 0x80 in each of the four words (the compiler keeps it in read-only data).
#ifdef _MSC_VER
const uint64_t kRound_ac188c = 0x0080008000800080ULL;
#endif

// The blit tables, one per (pixel format, transparent) pair.
// GLOBAL: 0x00ac26b0
extern BlitFn_ac188c* gac26b0[];

// The 32-bit address a slot's argument holds, as the pointer it is.

// A pixel times a colour, per byte: (pixel * colour + 0x80) >> 8. The original does it in MMX and leaves the result in eax.
#ifdef _MSC_VER
__forceinline uint32_t Modulate_ac188c(uint32_t pixel, uint32_t color)
{
    __asm {
        movd mm0, pixel
        pxor mm7, mm7
        movd mm1, color
        punpcklbw mm0, mm7
        movq mm2, kRound_ac188c
        punpcklbw mm1, mm7
        pmullw mm0, mm1
        paddw mm0, kRound_ac188c
        psrlw mm0, 8
        packuswb mm0, mm0
        movd eax, mm0
    }
}
#define EMMS_ac188c() __asm emms
#else
inline uint32_t Modulate_ac188c(uint32_t pixel, uint32_t color)
{
    uint32_t result = 0;
    for (int shift = 0; shift < 32; shift += 8) {
        uint32_t value = (((pixel >> shift) & 0xff) * ((color >> shift) & 0xff) + 0x80) >> 8;
        result |= (value > 0xff ? 0xff : value) << shift;
    }
    return result;
}
#define EMMS_ac188c()
#endif

// FUNCTION: 0x0085e640
void cUnk00ac188c::Slot01_ac17ac(uint32_t spans, uint32_t count, uint32_t dest, uint32_t color)
{
    const uint32_t* span = OB_PTR(const uint32_t, spans);
    const Surface_ac188c* dst = OB_PTR(const Surface_ac188c, dest);
    do {
        uint32_t start = span[0];
        uint32_t end = span[1];
        span += 2;
        memset(dst->mpBits + (start >> 16) * dst->mnStride + (start & 0xffff), color,
               end - start);
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0085e6a0 score 40 (same logic; register choice and where the gradient pointer lives differ)
void cUnk00ac188c::Slot02_ac17ac(uint32_t spans, uint32_t count, uint32_t dest, uint32_t gradient)
{
    const Gradient_ac188c* grad = OB_PTR(const Gradient_ac188c, gradient);
    int32_t stepX = grad->mnStepX;
    do {
        const uint32_t* span = OB_PTR(const uint32_t, spans);
        uint32_t start = span[0];
        uint32_t end = span[1];
        spans += 8;
        const Surface_ac188c* dst = OB_PTR(const Surface_ac188c, dest);
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint8_t* d = dst->mpBits + dst->mnStride * y + x;
        uint32_t value = grad->mnStepY * y + grad->mnStepX * x + grad->mnStart;
        for (uint32_t n = end - start; n != 0; --n) {
            *d++ = static_cast<uint8_t>(value >> 16);
            value += stepX;
        }
    } while (--count);
}
#endif

// FUNCTION: 0x0085e720
void cUnk00ac188c::Slot03_ac17ac(uint32_t spans, uint32_t count, uint32_t dest, uint32_t color, uint32_t)
{
    Slot01_ac17ac(spans, count, dest, color);
}

// FUNCTION: 0x0085e740
void cUnk00ac188c::Slot04_ac17ac(uint32_t spans, uint32_t count, uint32_t dest, uint32_t gradient)
{
    Slot02_ac17ac(spans, count, dest, gradient);
}

// FUNCTION: 0x0085e750
void cUnk00ac188c::Slot05_ac17ac(uint32_t spans, uint32_t count, uint32_t dest, uint32_t source, uint32_t params,
                                 uint32_t flags)
{
    const BltParams_ac188c* p = OB_PTR(const BltParams_ac188c, params);
    BlitFn_ac188c* table = gac26b0[p->mnFormat * 2 + p->mbTransparent];
    table[flags](OB_PTR(const uint32_t, spans), count, *OB_PTR(const Surface_ac188c, dest),
                 *OB_PTR(const Surface_ac188c, source), *p);
}

// The blend of two 15-bit pixels: dst moved towards src by alpha/32 per component.
#ifdef _MSC_VER
#pragma auto_inline(off)
#endif
// FUNCTION: 0x0083c490
uint32_t Fn0083c490(uint32_t dst, uint32_t src, uint32_t alpha)
{
    uint32_t green = (((src & 0x3e0) - (dst & 0x3e0)) * alpha + (((dst & 0xffffffe0) + 0x10) << 5)) & 0x7c00;
    uint32_t outer = (((src & 0x7c1f) - (dst & 0x7c1f)) * alpha + ((dst & 0xfffffc1f) << 5) + 0x4010) & 0xf83e0;
    return ((green + outer) | 0x100000) >> 5;
}
#ifdef _MSC_VER
#pragma auto_inline()
#endif

// The blend of Fn0083c490 expanded in place (the compiler inlined it into these kernels).
#ifdef _MSC_VER
__forceinline
#else
inline
#endif
uint32_t BlendInline_ac188c(uint32_t dst, uint32_t src, uint32_t alpha)
{
    uint32_t green = (((src & 0x3e0) - (dst & 0x3e0)) * alpha + (((dst & 0xffffffe0) + 0x10) << 5)) & 0x7c00;
    uint32_t outer = (((src & 0x7c1f) - (dst & 0x7c1f)) * alpha + ((dst & 0xfffffc1f) << 5) + 0x4010) & 0xf83e0;
    return ((green + outer) | 0x100000) >> 5;
}

// A 32-bit pixel as 1555 (the alpha is the top bit of the pixel).
inline uint32_t Pack8888_ac188c(uint32_t pixel)
{
    Rgb_ac188c c;
    c.mnGreen = (pixel >> 6) & 0x3e0;
    c.mnBlue = (pixel >> 3) & 0x1f;
    c.mnAlpha = (pixel >> 16) & 0x8000;
    c.mnRed = (pixel >> 9) & 0x7c00;
    return (c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00);
}

// 16-bit pixels widened to 32 bits (each component's top bits repeated into the low bits).
inline uint32_t Expand555_ac188c(uint32_t pixel)
{
    uint32_t v = (pixel & 0x1f) + ((pixel & 0x3e0) + 0x3fc0000 + (pixel & 0x7c00) * 8) * 8;
    return ((v >> 2) & 0x70707) + v * 8;
}

inline uint32_t Expand1555_ac188c(uint32_t pixel)
{
    uint32_t v = ((0 - (pixel >> 15)) & 0xff000000) + ((pixel & 0x1f) + ((pixel & 0x3e0) + (pixel & 0x7c00) * 8) * 8) * 8;
    return ((v >> 5) & 0x70707) + v;
}

inline uint32_t Expand4444_ac188c(uint32_t pixel)
{
    uint32_t v = (((pixel & 0xfffff000) * 0x10 + (pixel & 0xf00)) * 0x10 + (pixel & 0xf0)) * 0x10 + (pixel & 0xf);
    return (v & 0xf0f0f0f) + v * 0x10;
}

inline uint32_t Expand565_ac188c(uint32_t pixel)
{
    uint32_t v = ((((pixel & 0x7e0) >> 1) + (pixel & 0x7e0) * 0x20) & 0xff00) +
                 (((pixel & 0xf800) + 0xff0000) * 0x20 + (pixel & 0x1f)) * 8;
    return ((v >> 5) & 0x70007) + v;
}

// FUNCTION: 0x00848160
void Fn00848160(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t y = start >> 16;
        uint32_t x = start & 0xffff;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            *d++ = *s++;
        }
    } while (--count);
}

// FUNCTION: 0x00834050
void Fn00834050(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t y = start >> 16;
        uint32_t x = start & 0xffff;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(pixel);
            }
            ++d;
            ++s;
        }
    } while (--count);
}

// FUNCTION: 0x00834ee0
void Fn00834ee0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t y = start >> 16;
        uint32_t x = start & 0xffff;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            *d++ = static_cast<uint16_t>((*s++ & 0x7fff) + 0x8000);
        }
    } while (--count);
}

// FUNCTION: 0x0083d0b0
void Fn0083d0b0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* s = src.mpBits + src.mnStride * y + x;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if (p.mnTransparent != 0) {
                Rgb_ac188c c;
                c.mnRed = 0x7c00;
                c.mnGreen = 0x3e0;
                c.mnBlue = 0x1f;
                c.mnAlpha = (pixel & 0x80) << 8;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00));
            }
            ++d;
            ++s;
        }
    } while (--count);
}

// FUNCTION: 0x0083c370
void Fn0083c370(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* s = src.mpBits + src.mnStride * y + x;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnRed = 0x7c00;
            c.mnGreen = 0x3e0;
            c.mnBlue = 0x1f;
            c.mnAlpha = (pixel & 0x80) << 8;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00));
            ++d;
            ++s;
        }
    } while (--count);
}

// FUNCTION: 0x00835c70
void Fn00835c70(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t y = start >> 16;
        uint32_t x = start & 0xffff;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>((pixel & 0x7fff) + 0x8000);
            }
            ++d;
            ++s;
        }
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x008333e0 score 24 (same logic; spans pointer in ebp, and the or/push order differ)
void Fn008333e0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(Fn0083c490(*d, *s | 0xffff0000, alpha));
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

// FUNCTION: 0x00833730
void Fn00833730(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t y = start >> 16;
        uint32_t x = start & 0xffff;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            *d++ = row[u >> 16];
            u += p.mnStepX;
        }
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00834f60 score 16 (alpha-set source pixel: the original adds 0x8000 without the narrowing, ours subtracts or narrows)
void Fn00834f60(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t opaque = *s & 0x7fff;
            opaque += 0x8000;
            *d = static_cast<uint16_t>(Fn0083c490(*d, opaque | 0xffff0000, alpha));
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

// FUNCTION: 0x008352a0
void Fn008352a0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t y = start >> 16;
        uint32_t x = start & 0xffff;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>((row[u >> 16] & 0x7fff) + 0x8000);
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00836af0 score 4 (565 to 555: the original masks each component twice, ours folds the second and)
void Fn00836af0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t half = pixel >> 1;
            Rgb_ac188c c;
            c.mnRed = half & 0x7c00;
            c.mnGreen = half & 0x3e0;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + (pixel & 0x1f) + 0x8000);
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

// FUNCTION: 0x00834470
void Fn00834470(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t y = start >> 16;
        uint32_t x = start & 0xffff;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(pixel);
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0083c3f0 score 8 (logic follows the asm; instruction order or registers differ)
void Fn0083c3f0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* s = src.mpBits + src.mnStride * y + x;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnRed = 0x7c00;
            c.mnGreen = 0x3e0;
            c.mnBlue = 0x1f;
            c.mnAlpha = (pixel & 0x80) << 8;
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(Fn0083c490(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            ++d;
            ++s;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008340d0 score 4 (only the pixel register differs)
void Fn008340d0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Fn0083c490(*d, pixel | 0xffff0000, alpha));
            }
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00835cf0 score 15 (alpha-set source pixel: add or sub 0x8000)
void Fn00835cf0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s & 0x7fff;
            if (pixel != p.mnTransparent) {
                uint32_t opaque = pixel;
                opaque += 0x8000;
                *d = static_cast<uint16_t>(Fn0083c490(*d, opaque | 0xffff0000, alpha));
            }
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00842c50 score 4 (only a register choice differs)
void Fn00842c50(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            *d = *s;
            ++s;
            ++d;
            ++u;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083cc00 score 19 (logic follows the asm; instruction order or registers differ)
void Fn0083cc00(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint8_t* row = src.mpBits + (v % src.mnHeight) * src.mnStride;
        const uint8_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnRed = 0x7c00;
            c.mnGreen = 0x3e0;
            c.mnBlue = 0x1f;
            c.mnAlpha = (pixel & 0x80) << 8;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

// FUNCTION: 0x00831510
void Fn00831510(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t v = (pixel & 0xf0) + (pixel & 0xf00) * 2;
            v = (pixel & 0xf) + v * 2;
            v = (pixel & 0x8000) + v * 2;
            *d = static_cast<uint16_t>(v + ((v >> 4) & 0x421));
            ++d;
            ++s;
        }
    } while (--count);
}

// FUNCTION: 0x0083c760
void Fn0083c760(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* row = src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16);
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            Rgb_ac188c c;
            c.mnRed = 0x7c00;
            c.mnGreen = 0x3e0;
            c.mnBlue = 0x1f;
            c.mnAlpha = (pixel & 0x80) << 8;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0083a6d0 score 24 (888 to 555: the original masks each component twice)
void Fn0083a6d0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnRed = (pixel >> 9) & 0x7c00;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + 0x8000 + (c.mnRed & 0x7c00));
            ++d;
            ++s;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083d130 score 8 (logic follows the asm; instruction order or registers differ)
void Fn0083d130(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* s = src.mpBits + src.mnStride * y + x;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if (p.mnTransparent != 0) {
                Rgb_ac188c c;
                c.mnRed = 0x7c00;
                c.mnGreen = 0x3e0;
                c.mnBlue = 0x1f;
                c.mnAlpha = (pixel & 0x80) << 8;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(Fn0083c490(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            }
            ++d;
            ++s;
        }
    } while (--count);
}
#endif


#ifdef OB_DRAFTS
// CLOSE: 0x008389b0 score 32 (888 to 1555: the original masks each component twice)
void Fn008389b0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnAlpha = (pixel >> 16) & 0x8000;
            c.mnRed = (pixel >> 9) & 0x7c00;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                       (c.mnRed & 0x7c00));
            ++d;
            ++s;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008379a0 score 6 (logic follows the asm; instruction order or registers differ)
void Fn008379a0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffff) != p.mnTransparent) {
                uint32_t half = pixel >> 1;
                Rgb_ac188c c;
                c.mnRed = half & 0x7c00;
                c.mnGreen = half & 0x3e0;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + (pixel & 0x1f) + 0x8000);
            }
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

// FUNCTION: 0x0083d470
void Fn0083d470(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t y = start >> 16;
        uint32_t x = start & 0xffff;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* row = src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16);
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if (p.mnTransparent != 0) {
                Rgb_ac188c c;
                c.mnRed = 0x7c00;
                c.mnGreen = 0x3e0;
                c.mnBlue = 0x1f;
                c.mnAlpha = (pixel & 0x80) << 8;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00835760 score 4 (tiled alpha-set: register choice only)
void Fn00835760(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>((*s & 0x7fff) + 0x8000);
            ++s;
            ++u;
            ++d;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00834980 score 15 (tiled colour key: pixel load and add order)
void Fn00834980(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            if ((*s & 0x7fff) != p.mnTransparent) {
                *d = *s;
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

// FUNCTION: 0x00836080
void Fn00836080(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>((pixel & 0x7fff) + 0x8000);
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00836f10 score 6 (textured 565 to 555: double masks)
void Fn00836f10(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t half = pixel >> 1;
            Rgb_ac188c c;
            c.mnRed = half & 0x7c00;
            c.mnGreen = half & 0x3e0;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + (pixel & 0x1f) + 0x8000);
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083d940 score 22 (logic follows the asm; instruction order or registers differ)
void Fn0083d940(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint8_t* row = src.mpBits + (v % src.mnHeight) * src.mnStride;
        const uint8_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if (p.mnTransparent != 0) {
                Rgb_ac188c c;
                c.mnRed = 0x7c00;
                c.mnGreen = 0x3e0;
                c.mnBlue = 0x1f;
                c.mnAlpha = (pixel & 0x80) << 8;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00836590 score 15 (tiled key + alpha-set: load and add order)
void Fn00836590(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            if ((*s & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>((*s & 0x7fff) + 0x8000);
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

// FUNCTION: 0x008323d0
void Fn008323d0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xfff) != p.mnTransparent) {
                uint32_t v = (pixel & 0xf0) + (pixel & 0xf00) * 2;
                v = (pixel & 0xf) + v * 2;
                v = (pixel & 0x8000) + v * 2;
                *d = static_cast<uint16_t>(v + ((v >> 4) & 0x421));
            }
            ++d;
            ++s;
        }
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0083a770 score 38 (888 to 555 blend: double masks)
void Fn0083a770(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnRed = (pixel >> 9) & 0x7c00;
            *d = static_cast<uint16_t>(Fn0083c490(
                *d, ((c.mnBlue & 0x1f) + (c.mnGreen & 0x3e0) + 0x8000 + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            ++d;
            ++s;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083b490 score 38 (888 to 555 with key: double masks)
void Fn0083b490(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnRed = (pixel >> 9) & 0x7c00;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnRed & 0x7c00) + 0x8000);
            }
            ++d;
            ++s;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00836b80 score 44 (565 to 555 blend: double masks)
void Fn00836b80(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t half = pixel >> 1;
            Rgb_ac188c c;
            c.mnRed = half & 0x7c00;
            c.mnGreen = half & 0x3e0;
            *d = static_cast<uint16_t>(
                Fn0083c490(*d, ((c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + (pixel & 0x1f) + 0x8000) | 0xffff0000, alpha));
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008315b0 score 38 (logic follows the asm; instruction order or registers differ)
void Fn008315b0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t v = (pixel & 0xf0) + (pixel & 0xf00) * 2;
            v = (pixel & 0xf) + v * 2;
            v = (pixel & 0x8000) + v * 2;
            *d = static_cast<uint16_t>(Fn0083c490(*d, (((v >> 4) & 0x421) + v) | 0xffff0000, alpha));
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00831e80 score 10 (logic follows the asm; instruction order or registers differ)
void Fn00831e80(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t c = (pixel & 0xf0) + (pixel & 0xf00) * 2;
            c = (pixel & 0xf) + c * 2;
            c = (pixel & 0x8000) + c * 2;
            *d = static_cast<uint16_t>(((c >> 4) & 0x421) + c);
            ++d;
            ++s;
            ++u;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00837440 score 16 (logic follows the asm; instruction order or registers differ)
void Fn00837440(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t half = pixel >> 1;
            Rgb_ac188c c;
            c.mnRed = half & 0x7c00;
            c.mnGreen = half & 0x3e0;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + (pixel & 0x1f) + 0x8000);
            ++s;
            ++d;
            ++u;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00837e40 score 56 (logic follows the asm; instruction order or registers differ)
void Fn00837e40(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffff) != p.mnTransparent) {
                uint32_t half = pixel >> 1;
                Rgb_ac188c c;
                c.mnRed = half & 0x7c00;
                c.mnGreen = half & 0x3e0;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + (pixel & 0x1f) + 0x8000);
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

// FUNCTION: 0x00831940
void Fn00831940(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t v = (pixel & 0xf0) + (pixel & 0xf00) * 2;
            v = (pixel & 0xf) + v * 2;
            v = (pixel & 0x8000) + v * 2;
            *d = static_cast<uint16_t>(((v >> 4) & 0x421) + v);
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0083aab0 score 77 (logic follows the asm; instruction order or registers differ)
void Fn0083aab0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnRed = (pixel >> 9) & 0x7c00;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + 0x8000 + (c.mnRed & 0x7c00));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00839790 score 40 (logic follows the asm; instruction order or registers differ)
void Fn00839790(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnAlpha = (pixel >> 16) & 0x8000;
                c.mnRed = (pixel >> 9) & 0x7c00;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                           (c.mnRed & 0x7c00));
            }
            ++d;
            ++s;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083af90 score 59 (logic follows the asm; instruction order or registers differ)
void Fn0083af90(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnRed = (pixel >> 9) & 0x7c00;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + 0x8000 + (c.mnRed & 0x7c00));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00838a60 score 63 (logic follows the asm; instruction order or registers differ)
void Fn00838a60(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnRed = (pixel >> 9) & 0x7c00;
            c.mnAlpha = (pixel >> 16) & 0x8000;
            *d = static_cast<uint16_t>(Fn0083c490(*d,
                                                  ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnRed & 0x7c00) +
                                                   (c.mnAlpha & 0x8000)) | 0xffff0000,
                                                  alpha));
            ++d;
            ++s;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00838d90 score 50 (logic follows the asm; instruction order or registers differ)
void Fn00838d90(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnAlpha = (pixel >> 16) & 0x8000;
            c.mnRed = (pixel >> 9) & 0x7c00;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                       (c.mnRed & 0x7c00));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

// FUNCTION: 0x00832870
void Fn00832870(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        spans += 2;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xfff) != p.mnTransparent) {
                uint32_t v = (pixel & 0xf0) + (pixel & 0xf00) * 2;
                v = (pixel & 0xf) + v * 2;
                v = (pixel & 0x8000) + v * 2;
                *d = static_cast<uint16_t>(((v >> 4) & 0x421) + v);
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0083b8d0 score 81 (logic follows the asm; instruction order or registers differ)
void Fn0083b8d0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnRed = (pixel >> 9) & 0x7c00;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + 0x8000 + (c.mnRed & 0x7c00));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00837a50 score 59 (logic follows the asm; instruction order or registers differ)
void Fn00837a50(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffff) != p.mnTransparent) {
                uint32_t half = pixel >> 1;
                Rgb_ac188c c;
                c.mnRed = half & 0x7c00;
                c.mnGreen = half & 0x3e0;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(Fn0083c490(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + (pixel & 0x1f) + 0x8000) | 0xffff0000, alpha));
            }
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00832490 score 28 (logic follows the asm; instruction order or registers differ)
void Fn00832490(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xfff) != p.mnTransparent) {
                uint32_t v = (pixel & 0xf0) + (pixel & 0xf00) * 2;
                v = (pixel & 0xf) + v * 2;
                v = (pixel & 0x8000) + v * 2;
                *d = static_cast<uint16_t>(Fn0083c490(*d, (((v >> 4) & 0x421) + v) | 0xffff0000, alpha));
            }
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00839270 score 58 (logic follows the asm; instruction order or registers differ)
void Fn00839270(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnAlpha = (pixel >> 16) & 0x8000;
            c.mnRed = (pixel >> 9) & 0x7c00;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                       (c.mnRed & 0x7c00));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083b550 score 65 (logic follows the asm; instruction order or registers differ)
void Fn0083b550(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnRed = (pixel >> 9) & 0x7c00;
                *d = static_cast<uint16_t>(Fn0083c490(
                    *d, ((c.mnBlue & 0x1f) + (c.mnGreen & 0x3e0) + 0x8000 + (c.mnRed & 0x7c00)) | 0xffff0000,
                    alpha));
            }
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00838b30 score 28 (logic follows the asm; instruction order or registers differ)
void Fn00838b30(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = Modulate_ac188c(*s, p.mnColor);
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnAlpha = (pixel >> 16) & 0x8000;
            c.mnRed = (pixel >> 9) & 0x7c00;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                       (c.mnRed & 0x7c00));
            ++d;
            ++s;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00832e00 score 12 (logic follows the asm; instruction order or registers differ)
void Fn00832e00(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xfff) != p.mnTransparent) {
                uint32_t c = (pixel & 0xf0) + (pixel & 0xf00) * 2;
                c = (pixel & 0xf) + c * 2;
                c = (pixel & 0x8000) + c * 2;
                *d = static_cast<uint16_t>(((c >> 4) & 0x421) + c);
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083c500 score 28 (logic follows the asm; instruction order or registers differ)
void Fn0083c500(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* s = src.mpBits + src.mnStride * y + x;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = Modulate_ac188c(*s * 0x1000000 + 0xffffff, p.mnColor);
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnAlpha = (pixel >> 16) & 0x8000;
            c.mnRed = (pixel >> 9) & 0x7c00;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                       (c.mnRed & 0x7c00));
            ++d;
            ++s;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083a830 score 28 (logic follows the asm; instruction order or registers differ)
void Fn0083a830(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = Modulate_ac188c((*s & 0xffffff) - 0x1000000, p.mnColor);
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnAlpha = (pixel >> 16) & 0x8000;
            c.mnRed = (pixel >> 9) & 0x7c00;
            *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                       (c.mnRed & 0x7c00));
            ++d;
            ++s;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008383c0 score 41 (logic follows the asm; instruction order or registers differ)
void Fn008383c0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffff) != p.mnTransparent) {
                uint32_t half = pixel >> 1;
                Rgb_ac188c c;
                c.mnRed = half & 0x7c00;
                c.mnGreen = half & 0x3e0;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + (pixel & 0x1f) + 0x8000);
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083be00 score 105 (logic follows the asm; instruction order or registers differ)
void Fn0083be00(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnRed = (pixel >> 9) & 0x7c00;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + 0x8000 + (c.mnRed & 0x7c00));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00839bf0 score 94 (logic follows the asm; instruction order or registers differ)
void Fn00839bf0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnAlpha = (pixel >> 16) & 0x8000;
                c.mnRed = (pixel >> 9) & 0x7c00;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                           (c.mnRed & 0x7c00));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00839860 score 67 (logic follows the asm; instruction order or registers differ)
void Fn00839860(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnRed = (pixel >> 9) & 0x7c00;
                c.mnAlpha = (pixel >> 16) & 0x8000;
                *d = static_cast<uint16_t>(Fn0083c490(*d,
                                                      ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnRed & 0x7c00) +
                                                       (c.mnAlpha & 0x8000)) | 0xffff0000,
                                                      alpha));
            }
            ++s;
            ++d;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083a140 score 72 (logic follows the asm; instruction order or registers differ)
void Fn0083a140(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnAlpha = (pixel >> 16) & 0x8000;
                c.mnRed = (pixel >> 9) & 0x7c00;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                           (c.mnRed & 0x7c00));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00839960 score 33 (logic follows the asm; instruction order or registers differ)
void Fn00839960(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                pixel = Modulate_ac188c(pixel, p.mnColor);
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnAlpha = (pixel >> 16) & 0x8000;
                c.mnRed = (pixel >> 9) & 0x7c00;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                           (c.mnRed & 0x7c00));
            }
            ++d;
            ++s;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083d1d0 score 28 (logic follows the asm; instruction order or registers differ)
void Fn0083d1d0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* s = src.mpBits + src.mnStride * y + x;
        for (uint32_t n = end - start; n != 0; --n) {
            if (p.mnTransparent != 0) {
                uint32_t pixel = Modulate_ac188c(*s * 0x1000000 + 0xffffff, p.mnColor);
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnAlpha = (pixel >> 16) & 0x8000;
                c.mnRed = (pixel >> 9) & 0x7c00;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                           (c.mnRed & 0x7c00));
            }
            ++d;
            ++s;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083b640 score 28 (logic follows the asm; instruction order or registers differ)
void Fn0083b640(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            if ((*s & 0xffffff) != p.mnTransparent) {
                uint32_t pixel = Modulate_ac188c((*s & 0xffffff) - 0x1000000, p.mnColor);
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnAlpha = (pixel >> 16) & 0x8000;
                c.mnRed = (pixel >> 9) & 0x7c00;
                *d = static_cast<uint16_t>((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) +
                                           (c.mnRed & 0x7c00));
            }
            ++d;
            ++s;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008337c0 score 34 (logic follows the asm; instruction order or registers differ)
void Fn008337c0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t dstPixel = *d;
            uint32_t srcPixel = row[u >> 16];
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, srcPixel | 0xffff0000, alpha));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00834ff0 score 31 (logic follows the asm; instruction order or registers differ)
void Fn00834ff0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand555_ac188c(*s), p.mnColor)));
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00835330 score 34 (logic follows the asm; instruction order or registers differ)
void Fn00835330(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t dstPixel = *d;
            uint32_t srcPixel = (row[u >> 16] & 0x7fff) - 0x8000;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, srcPixel | 0xffff0000, alpha));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00838fb0 score 58 (logic follows the asm; instruction order or registers differ)
void Fn00838fb0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(row[u >> 16], p.mnColor)));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00834510 score 58 (logic follows the asm; instruction order or registers differ)
void Fn00834510(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t srcPixel = row[u >> 16];
            if ((srcPixel & 0x7fff) != p.mnTransparent) {
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, srcPixel | 0xffff0000, alpha));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00833470 score 27 (logic follows the asm; instruction order or registers differ)
void Fn00833470(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand1555_ac188c(*s), p.mnColor)));
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00831680 score 29 (logic follows the asm; instruction order or registers differ)
void Fn00831680(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand4444_ac188c(*s), p.mnColor)));
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00833c00 score 27 (logic follows the asm; instruction order or registers differ)
void Fn00833c00(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, *s | 0xffff0000, alpha));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00836130 score 36 (logic follows the asm; instruction order or registers differ)
void Fn00836130(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t srcPixel = row[u >> 16] & 0x7fff;
            if (srcPixel != p.mnTransparent) {
                uint32_t dstPixel = *d;
                srcPixel -= 0x8000;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, srcPixel | 0xffff0000, alpha));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083c800 score 61 (logic follows the asm; instruction order or registers differ)
void Fn0083c800(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* row = src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16);
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            Rgb_ac188c c;
            c.mnRed = 0x7c00;
            c.mnGreen = 0x3e0;
            c.mnBlue = 0x1f;
            c.mnAlpha = (pixel & 0x80) << 8;
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00836c40 score 45 (logic follows the asm; instruction order or registers differ)
void Fn00836c40(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand565_ac188c(*s), p.mnColor)));
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008394c0 score 61 (logic follows the asm; instruction order or registers differ)
void Fn008394c0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(*s, p.mnColor)));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083c930 score 56 (logic follows the asm; instruction order or registers differ)
void Fn0083c930(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* row = src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16);
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(
                Pack8888_ac188c(Modulate_ac188c(row[u >> 16] * 0x1000000 + 0xffffff, p.mnColor)));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083acc0 score 56 (logic follows the asm; instruction order or registers differ)
void Fn0083acc0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(
                Pack8888_ac188c(Modulate_ac188c((row[u >> 16] & 0xffffff) - 0x1000000, p.mnColor)));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00835810 score 27 (logic follows the asm; instruction order or registers differ)
void Fn00835810(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t dstPixel = *d;
            uint32_t srcPixel = (*s & 0x7fff) - 0x8000;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, srcPixel | 0xffff0000, alpha));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00839e60 score 57 (logic follows the asm; instruction order or registers differ)
void Fn00839e60(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffffff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(pixel, p.mnColor)));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083cde0 score 59 (logic follows the asm; instruction order or registers differ)
void Fn0083cde0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint8_t* row = src.mpBits + (v % src.mnHeight) * src.mnStride;
        const uint8_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(*s * 0x1000000 + 0xffffff, p.mnColor)));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083d520 score 61 (logic follows the asm; instruction order or registers differ)
void Fn0083d520(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* row = src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16);
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if (p.mnTransparent != 0) {
                Rgb_ac188c c;
                c.mnRed = 0x7c00;
                c.mnGreen = 0x3e0;
                c.mnBlue = 0x1f;
                c.mnAlpha = (pixel & 0x80) << 8;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083b1b0 score 59 (logic follows the asm; instruction order or registers differ)
void Fn0083b1b0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c((*s & 0xffffff) - 0x1000000, p.mnColor)));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083bb10 score 76 (logic follows the asm; instruction order or registers differ)
void Fn0083bb10(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16] & 0xffffff;
            if (pixel != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(pixel - 0x1000000, p.mnColor)));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083d650 score 56 (logic follows the asm; instruction order or registers differ)
void Fn0083d650(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* row = src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16);
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            if (p.mnTransparent != 0) {
                *d = static_cast<uint16_t>(
                    Pack8888_ac188c(Modulate_ac188c(row[u >> 16] * 0x1000000 + 0xffffff, p.mnColor)));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083cca0 score 20 (logic follows the asm; instruction order or registers differ)
void Fn0083cca0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint8_t* row = src.mpBits + (v % src.mnHeight) * src.mnStride;
        const uint8_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnRed = 0x7c00;
            c.mnGreen = 0x3e0;
            c.mnBlue = 0x1f;
            c.mnAlpha = (pixel & 0x80) << 8;
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00835d90 score 39 (logic follows the asm; instruction order or registers differ)
void Fn00835d90(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor)));
            }
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00836fd0 score 98 (logic follows the asm; instruction order or registers differ)
void Fn00836fd0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t half = pixel >> 1;
            Rgb_ac188c c;
            c.mnRed = half & 0x7c00;
            c.mnGreen = half & 0x3e0;
            uint32_t dstPixel = *d;
            uint32_t srcPixel = (c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + 0x8000 + (pixel & 0x1f);
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, srcPixel | 0xffff0000, alpha));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083a3d0 score 79 (logic follows the asm; instruction order or registers differ)
void Fn0083a3d0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(pixel, p.mnColor)));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00834a30 score 26 (logic follows the asm; instruction order or registers differ)
void Fn00834a30(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t srcPixel = *s;
            if ((srcPixel & 0x7fff) != p.mnTransparent) {
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, srcPixel | 0xffff0000, alpha));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083db50 score 72 (logic follows the asm; instruction order or registers differ)
void Fn0083db50(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint8_t* row = src.mpBits + (v % src.mnHeight) * src.mnStride;
        const uint8_t* s = row + u;
        for (; n != 0; --n) {
            if (p.mnTransparent != 0) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(*s * 0x1000000 + 0xffffff, p.mnColor)));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00836650 score 26 (logic follows the asm; instruction order or registers differ)
void Fn00836650(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            if ((*s & 0x7fff) != p.mnTransparent) {
                uint32_t dstPixel = *d;
                uint32_t srcPixel = (*s & 0x7fff) - 0x8000;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, srcPixel | 0xffff0000, alpha));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00837510 score 17 (logic follows the asm; instruction order or registers differ)
void Fn00837510(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t half = pixel >> 1;
            Rgb_ac188c c;
            c.mnRed = half & 0x7c00;
            c.mnGreen = half & 0x3e0;
            uint32_t dstPixel = *d;
            uint32_t srcPixel = (c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + 0x8000 + (pixel & 0x1f);
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, srcPixel | 0xffff0000, alpha));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00831a10 score 53 (logic follows the asm; instruction order or registers differ)
void Fn00831a10(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t v = (pixel & 0xf) + ((pixel & 0xf0) + (pixel & 0xf00) * 2) * 2;
            v = ((v >> 3) & 0x421) + v * 2;
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, v | 0xffff0000, alpha));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083d2e0 score 29 (logic follows the asm; instruction order or registers differ)
void Fn0083d2e0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* s = src.mpBits + src.mnStride * y + x;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if (p.mnTransparent != 0) {
                uint32_t modulated = Modulate_ac188c(pixel * 0x1000000 + 0xffffff, p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            ++s;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083d790 score 79 (logic follows the asm; instruction order or registers differ)
void Fn0083d790(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* row = src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16);
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if (p.mnTransparent != 0) {
                uint32_t modulated = Modulate_ac188c(pixel * 0x1000000 + 0xffffff, p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083da00 score 36 (logic follows the asm; instruction order or registers differ)
void Fn0083da00(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint8_t* row = src.mpBits + (v % src.mnHeight) * src.mnStride;
        const uint8_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if (p.mnTransparent != 0) {
                Rgb_ac188c c;
                c.mnRed = 0x7c00;
                c.mnGreen = 0x3e0;
                c.mnBlue = 0x1f;
                c.mnAlpha = (pixel & 0x80) << 8;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083dc90 score 61 (logic follows the asm; instruction order or registers differ)
void Fn0083dc90(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint8_t* row = src.mpBits + (v % src.mnHeight) * src.mnStride;
        const uint8_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if (p.mnTransparent != 0) {
                uint32_t modulated = Modulate_ac188c(pixel * 0x1000000 + 0xffffff, p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083c5f0 score 31 (logic follows the asm; instruction order or registers differ)
void Fn0083c5f0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* s = src.mpBits + src.mnStride * y + x;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(pixel * 0x1000000 + 0xffffff, p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            ++s;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083ca60 score 77 (logic follows the asm; instruction order or registers differ)
void Fn0083ca60(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint8_t* row = src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16);
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t modulated = Modulate_ac188c(pixel * 0x1000000 + 0xffffff, p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083cf10 score 56 (logic follows the asm; instruction order or registers differ)
void Fn0083cf10(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint8_t* row = src.mpBits + (v % src.mnHeight) * src.mnStride;
        const uint8_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(pixel * 0x1000000 + 0xffffff, p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083b750 score 29 (logic follows the asm; instruction order or registers differ)
void Fn0083b750(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c((pixel & 0xffffff) - 0x1000000, p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083b9b0 score 95 (logic follows the asm; instruction order or registers differ)
void Fn0083b9b0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnRed = (pixel >> 9) & 0x7c00;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + 0x8000 + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083bc50 score 81 (logic follows the asm; instruction order or registers differ)
void Fn0083bc50(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffffff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c((pixel & 0xffffff) - 0x1000000, p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083bf00 score 62 (logic follows the asm; instruction order or registers differ)
void Fn0083bf00(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnRed = (pixel >> 9) & 0x7c00;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + 0x8000 + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083c070 score 72 (logic follows the asm; instruction order or registers differ)
void Fn0083c070(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c((pixel & 0xffffff) - 0x1000000, p.mnColor)));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083c1b0 score 59 (logic follows the asm; instruction order or registers differ)
void Fn0083c1b0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c((pixel & 0xffffff) - 0x1000000, p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083a930 score 33 (logic follows the asm; instruction order or registers differ)
void Fn0083a930(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c((pixel & 0xffffff) - 0x1000000, p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            ++s;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083ab80 score 73 (logic follows the asm; instruction order or registers differ)
void Fn0083ab80(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnRed = (pixel >> 9) & 0x7c00;
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + 0x8000 + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083adf0 score 77 (logic follows the asm; instruction order or registers differ)
void Fn0083adf0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t modulated = Modulate_ac188c((pixel & 0xffffff) - 0x1000000, p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083b060 score 28 (logic follows the asm; instruction order or registers differ)
void Fn0083b060(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnRed = (pixel >> 9) & 0x7c00;
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + 0x8000 + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083b2e0 score 55 (logic follows the asm; instruction order or registers differ)
void Fn0083b2e0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c((pixel & 0xffffff) - 0x1000000, p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00839a70 score 50 (logic follows the asm; instruction order or registers differ)
void Fn00839a70(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(pixel, p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00839cf0 score 108 (logic follows the asm; instruction order or registers differ)
void Fn00839cf0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnAlpha = (pixel >> 16) & 0x8000;
                c.mnRed = (pixel >> 9) & 0x7c00;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00839f90 score 123 (logic follows the asm; instruction order or registers differ)
void Fn00839f90(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffffff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(pixel, p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083a240 score 69 (logic follows the asm; instruction order or registers differ)
void Fn0083a240(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                Rgb_ac188c c;
                c.mnGreen = (pixel >> 6) & 0x3e0;
                c.mnBlue = (pixel >> 3) & 0x1f;
                c.mnAlpha = (pixel >> 16) & 0x8000;
                c.mnRed = (pixel >> 9) & 0x7c00;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0083a510 score 74 (logic follows the asm; instruction order or registers differ)
void Fn0083a510(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffffff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(pixel, p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00838c20 score 37 (logic follows the asm; instruction order or registers differ)
void Fn00838c20(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* s = reinterpret_cast<const uint32_t*>(src.mpBits + src.mnStride * y + x * 4);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(pixel, p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            ++s;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00838e60 score 128 (logic follows the asm; instruction order or registers differ)
void Fn00838e60(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnAlpha = (pixel >> 16) & 0x8000;
            c.mnRed = (pixel >> 9) & 0x7c00;
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008390d0 score 77 (logic follows the asm; instruction order or registers differ)
void Fn008390d0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint32_t* row = reinterpret_cast<const uint32_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t modulated = Modulate_ac188c(pixel, p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00839350 score 84 (logic follows the asm; instruction order or registers differ)
void Fn00839350(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            Rgb_ac188c c;
            c.mnGreen = (pixel >> 6) & 0x3e0;
            c.mnBlue = (pixel >> 3) & 0x1f;
            c.mnAlpha = (pixel >> 16) & 0x8000;
            c.mnRed = (pixel >> 9) & 0x7c00;
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnBlue & 0x1f) + (c.mnAlpha & 0x8000) + (c.mnRed & 0x7c00)) | 0xffff0000, alpha));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008395f0 score 55 (logic follows the asm; instruction order or registers differ)
void Fn008395f0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint32_t* row = reinterpret_cast<const uint32_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint32_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(pixel, p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00837b30 score 55 (logic follows the asm; instruction order or registers differ)
void Fn00837b30(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor)));
            }
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00837c80 score 76 (logic follows the asm; instruction order or registers differ)
void Fn00837c80(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00837f10 score 100 (logic follows the asm; instruction order or registers differ)
void Fn00837f10(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffff) != p.mnTransparent) {
                uint32_t half = pixel >> 1;
                Rgb_ac188c c;
                c.mnRed = half & 0x7c00;
                c.mnGreen = half & 0x3e0;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + (pixel & 0x1f) + 0x8000) | 0xffff0000, alpha));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00838060 score 49 (logic follows the asm; instruction order or registers differ)
void Fn00838060(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor)));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008381d0 score 132 (logic follows the asm; instruction order or registers differ)
void Fn008381d0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t y = start >> 16;
        uint32_t x = start & 0xffff;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xffff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008384c0 score 26 (logic follows the asm; instruction order or registers differ)
void Fn008384c0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffff) != p.mnTransparent) {
                uint32_t half = pixel >> 1;
                Rgb_ac188c c;
                c.mnRed = half & 0x7c00;
                c.mnGreen = half & 0x3e0;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, ((c.mnGreen & 0x3e0) + (c.mnRed & 0x7c00) + (pixel & 0x1f) + 0x8000) | 0xffff0000, alpha));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00838630 score 103 (logic follows the asm; instruction order or registers differ)
void Fn00838630(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor)));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008387b0 score 96 (logic follows the asm; instruction order or registers differ)
void Fn008387b0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xffff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00836d70 score 64 (logic follows the asm; instruction order or registers differ)
void Fn00836d70(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00837110 score 79 (logic follows the asm; instruction order or registers differ)
void Fn00837110(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor)));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00837270 score 96 (logic follows the asm; instruction order or registers differ)
void Fn00837270(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t modulated = Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00837650 score 78 (logic follows the asm; instruction order or registers differ)
void Fn00837650(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor)));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008377c0 score 76 (logic follows the asm; instruction order or registers differ)
void Fn008377c0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(Expand565_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00835ed0 score 42 (logic follows the asm; instruction order or registers differ)
void Fn00835ed0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00836260 score 33 (logic follows the asm; instruction order or registers differ)
void Fn00836260(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor)));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008363c0 score 88 (logic follows the asm; instruction order or registers differ)
void Fn008363c0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0x7fff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00836790 score 79 (logic follows the asm; instruction order or registers differ)
void Fn00836790(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor)));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00836900 score 74 (logic follows the asm; instruction order or registers differ)
void Fn00836900(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00835110 score 46 (logic follows the asm; instruction order or registers differ)
void Fn00835110(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00835450 score 65 (logic follows the asm; instruction order or registers differ)
void Fn00835450(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor)));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008355a0 score 86 (logic follows the asm; instruction order or registers differ)
void Fn008355a0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t modulated = Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00835940 score 61 (logic follows the asm; instruction order or registers differ)
void Fn00835940(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor)));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00835aa0 score 74 (logic follows the asm; instruction order or registers differ)
void Fn00835aa0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(Expand555_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00834170 score 35 (logic follows the asm; instruction order or registers differ)
void Fn00834170(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor)));
            }
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008342b0 score 32 (logic follows the asm; instruction order or registers differ)
void Fn008342b0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00834630 score 29 (logic follows the asm; instruction order or registers differ)
void Fn00834630(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor)));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008347a0 score 80 (logic follows the asm; instruction order or registers differ)
void Fn008347a0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0x7fff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00834b70 score 65 (logic follows the asm; instruction order or registers differ)
void Fn00834b70(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor)));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00834cf0 score 62 (logic follows the asm; instruction order or registers differ)
void Fn00834cf0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0x7fff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00833590 score 30 (logic follows the asm; instruction order or registers differ)
void Fn00833590(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008338d0 score 61 (logic follows the asm; instruction order or registers differ)
void Fn008338d0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor)));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00833a30 score 82 (logic follows the asm; instruction order or registers differ)
void Fn00833a30(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t modulated = Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00833d20 score 55 (logic follows the asm; instruction order or registers differ)
void Fn00833d20(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor)));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00833e80 score 56 (logic follows the asm; instruction order or registers differ)
void Fn00833e80(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(Expand1555_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00832570 score 37 (logic follows the asm; instruction order or registers differ)
void Fn00832570(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xfff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor)));
            }
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008326b0 score 34 (logic follows the asm; instruction order or registers differ)
void Fn008326b0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xfff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00832950 score 94 (logic follows the asm; instruction order or registers differ)
void Fn00832950(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xfff) != p.mnTransparent) {
                uint32_t v = (pixel & 0xf0) + (pixel & 0xf00) * 2;
                v = (pixel & 0xf) + v * 2;
                v = (pixel & 0x8000) + v * 2;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, (((v >> 4) & 0x421) + v) | 0xffff0000, alpha));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00832ab0 score 31 (logic follows the asm; instruction order or registers differ)
void Fn00832ab0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xfff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor)));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00832c20 score 86 (logic follows the asm; instruction order or registers differ)
void Fn00832c20(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            if ((pixel & 0xfff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00832ef0 score 41 (logic follows the asm; instruction order or registers differ)
void Fn00832ef0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xfff) != p.mnTransparent) {
                uint32_t v = (pixel & 0xf0) + (pixel & 0xf00) * 2;
                v = (pixel & 0xf) + v * 2;
                v = (pixel & 0x8000) + v * 2;
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, (((v >> 4) & 0x421) + v) | 0xffff0000, alpha));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00833070 score 73 (logic follows the asm; instruction order or registers differ)
void Fn00833070(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xfff) != p.mnTransparent) {
                *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor)));
            }
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008331f0 score 66 (logic follows the asm; instruction order or registers differ)
void Fn008331f0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            if ((pixel & 0xfff) != p.mnTransparent) {
                uint32_t modulated = Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor);
                uint32_t rgb = Pack8888_ac188c(modulated);
                uint32_t dstPixel = *d;
                *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            }
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008317a0 score 32 (logic follows the asm; instruction order or registers differ)
void Fn008317a0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        const uint16_t* s = reinterpret_cast<const uint16_t*>(src.mpBits + src.mnStride * y + x * 2);
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++s;
            ++d;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00831b50 score 63 (logic follows the asm; instruction order or registers differ)
void Fn00831b50(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor)));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00831cb0 score 82 (logic follows the asm; instruction order or registers differ)
void Fn00831cb0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t end = spans[1];
        spans += 2;
        uint32_t x = start & 0xffff;
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + x * 2);
        const uint16_t* row = reinterpret_cast<const uint16_t*>(
            src.mpBits + src.mnStride * ((p.mnStepY * y + p.mnV) >> 16));
        uint32_t u = p.mnStepX * x + p.mnU;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = row[u >> 16];
            uint32_t modulated = Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++d;
            u += p.mnStepX;
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00831f50 score 43 (logic follows the asm; instruction order or registers differ)
void Fn00831f50(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t alpha = p.mnColor >> 27;
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t v = (pixel & 0xf0) + (pixel & 0xf00) * 2;
            v = (pixel & 0xf) + v * 2;
            v = (pixel & 0x8000) + v * 2;
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, (((v >> 4) & 0x421) + v) | 0xffff0000, alpha));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008320a0 score 62 (logic follows the asm; instruction order or registers differ)
void Fn008320a0(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (uint32_t n = end - start; n != 0; --n) {
            uint32_t pixel = *s;
            *d = static_cast<uint16_t>(Pack8888_ac188c(Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor)));
            ++d;
            ++u;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00832200 score 60 (logic follows the asm; instruction order or registers differ)
void Fn00832200(const uint32_t* spans, int32_t count, Surface_ac188c dst, Surface_ac188c src, BltParams_ac188c p)
{
    do {
        uint32_t start = spans[0];
        uint32_t y = start >> 16;
        uint16_t* d = reinterpret_cast<uint16_t*>(dst.mpBits + dst.mnStride * y + (start & 0xffff) * 2);
        uint32_t u = ((start & 0xffff) + p.mnU) % src.mnWidth;
        uint32_t v = p.mnV + y;
        uint32_t end = spans[1];
        spans += 2;
        uint32_t n = end - start;
        const uint16_t* row = reinterpret_cast<const uint16_t*>(src.mpBits + (v % src.mnHeight) * src.mnStride);
        const uint16_t* s = row + u;
        for (; n != 0; --n) {
            uint32_t pixel = *s;
            uint32_t modulated = Modulate_ac188c(Expand4444_ac188c(pixel), p.mnColor);
            uint32_t rgb = Pack8888_ac188c(modulated);
            uint32_t dstPixel = *d;
            *d = static_cast<uint16_t>(BlendInline_ac188c(dstPixel, rgb, modulated >> 27));
            ++u;
            ++d;
            ++s;
            if (u >= src.mnWidth) {
                u = 0;
                s = row;
            }
        }
    } while (--count);
    EMMS_ac188c();
}
#endif
