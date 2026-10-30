#include "classes/cGZFont.h"

#include <math.h>
#include <new>
#include <stdio.h>
#include <string.h>

// A string object reached through its virtual slots (the framework's string interface).
struct String_ac55d8 {
    virtual void Fn0();
    virtual void Fn1();
    virtual void Fn2();
    virtual void Fn3();
    virtual void FromChar(const char* text);
    virtual const char* ToChar();
};

// The string interface the caller passes in (cIGZString): the slots used here.
struct StringOut_ac55d8 {
    virtual void Fn0();
    virtual void Fn1();
    virtual void Fn2();
    virtual void Fn3();
    virtual void FromChar(const char* text);
    virtual const char* ToChar();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0089626e score 8
bool cGZFont::QueryInterface(uint32_t iid, uint32_t out)
{
    bool r;
    if (iid == 0x10673960 || iid == 1) {
        *OB_PTR(cGZFont*, out) = this;
        this->AddRef();
        r = true;
    } else {
        r = false;
    }
    return r;
}
#endif

// FUNCTION: 0x008962a9
void cGZFont::SetStyle(uint32_t style, bool on)
{
    uint32_t bits = style & 0x3c;
    if (on) {
        mnStyle |= bits;
    } else {
        mnStyle &= ~bits;
    }
}

// FUNCTION: 0x008962c4
void* cGZFont::GetAppropriateCachedBitmapData()
{
    uint8_t* p = reinterpret_cast<uint8_t*>(this) + 0x104;
    if (mnAntialiasing != 1) {
        p = reinterpret_cast<uint8_t*>(this) + 0x130;
    }
    return p;
}

// FUNCTION: 0x00896654
void cGZFont::SetAntialiasing(uint32_t mode)
{
    if (mode != 0) {
        mnAntialiasing = mode;
    }
}

// FUNCTION: 0x0089666a
bool cGZFont::GetCodePage(void* out)
{
    *static_cast<uint32_t*>(out) = mnCodePage;
    return true;
}

// FUNCTION: 0x00896684
bool cGZFont::IsCharEncodingAvailable(uint32_t encoding)
{
    bool ok = false;
    if (encoding == 2) {
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x00896692
void cGZFont::GetScaling(void* x, void* y)
{
    *static_cast<float*>(x) = mfScaleX;
    *static_cast<float*>(y) = mfScaleY;
}

// FUNCTION: 0x008966a7
void cGZFont::GetAdvanceScaling(void* x, void* y)
{
    *static_cast<float*>(x) = mfAdvanceScale;
    *static_cast<float*>(y) = 1.0f;
}

// FUNCTION: 0x008966bb
void cGZFont::GetSpacingAdjustment(void* x, void* y)
{
    *static_cast<int32_t*>(x) = mnSpacingX;
    *static_cast<int32_t*>(y) = mnSpacingY;
}

// FUNCTION: 0x008966d0
void cGZFont::SetSpacingAdjustment(uint32_t x, uint32_t y)
{
    if (mnSpacingX != static_cast<int32_t>(x)) {
        mnSpacingX = x;
    }
    if (mnSpacingY != static_cast<int32_t>(y)) {
        mnSpacingY = y;
    }
}

// FUNCTION: 0x008966eb
uint32_t cGZFont::GetLineHeight()
{
    return mnSpacingY + mnHeight;
}

// FUNCTION: 0x008966f8
uint32_t cGZFont::GetSizeAboveBaseline()
{
    return mnAscent + mnSpacingY;
}

// FUNCTION: 0x00896702
uint32_t cGZFont::GetSizeBelowBaseline()
{
    uint32_t above = GetSizeAboveBaseline();
    uint32_t line = GetLineHeight();
    return line - above;
}

// FUNCTION: 0x008972a8
uint32_t cGZFont::Release()
{
    if (mnRefCount > 1) {
        mnRefCount = mnRefCount - 1;
        return mnRefCount;
    }
    Fn00896293();
    return 0;
}

// FUNCTION: 0x008989e5
void cGZFont::GetName(void* out)
{
    String_ac55d8* name = reinterpret_cast<String_ac55d8*>(mName);
    StringOut_ac55d8* o = static_cast<StringOut_ac55d8*>(out);
    o->FromChar(name->ToChar());
}

// FUNCTION: 0x00898a00
uint32_t cGZFont::GetStyle(uint32_t style)
{
    return !((mnStyle & style) - style);
}

// FUNCTION: 0x00898a13
void cGZFont::SetFontColor(uint32_t fore, uint32_t back)
{
    mnFontColor = fore;
    mnBackColor = back;
}

// FUNCTION: 0x00898a24
void cGZFont::GetFilePath(void* out)
{
    String_ac55d8* path = reinterpret_cast<String_ac55d8*>(mPath);
    StringOut_ac55d8* o = static_cast<StringOut_ac55d8*>(out);
    o->FromChar(path->ToChar());
}

// FUNCTION: 0x00898a3f
void cGZFont::SetFilePath(void* in)
{
    String_ac55d8* path = reinterpret_cast<String_ac55d8*>(mPath);
    StringOut_ac55d8* i = static_cast<StringOut_ac55d8*>(in);
    path->FromChar(i->ToChar());
}

// FUNCTION: 0x0089603d
uint32_t cGZFont::Fn0089603d()
{
    return GetStyle_2() - mnLockCount;
}

// FUNCTION: 0x00896618
uint32_t cGZFont::Fn00896618()
{
    if (mnSize < 0x10) {
        return 1;
    }
    if (mnSize < 0x1a) {
        return 2;
    }
    return (mnSize < 0x24) ? 3 : 4;
}

// FUNCTION: 0x00896636
uint32_t cGZFont::Fn00896636()
{
    if (mnSize < 0x18) {
        return 1;
    }
    if (mnSize < 0x30) {
        return 2;
    }
    return (mnSize < 0x48) ? 3 : 4;
}

// FUNCTION: 0x00896b2c
uint32_t Fn00896b2c(uint32_t kind)
{
    switch (kind) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        return 1;
    }
}

// STUB: 0x004c37a0
float Fn004c37a0(float a, float b);

#ifdef OB_DRAFTS
// CLOSE: 0x004c37a0 score 8
float Fn004c37a0Draft_ac55d8(float a, float b)
{
    return static_cast<float>(pow(a, b));
}
#endif

// The font renderer object (cIGZFontRenderer), as far as the font calls it.
struct Renderer_ac55d8 {
    virtual void Fn0();
    virtual void AddRef();
    virtual void Release();
    virtual void Attach(cGZFont* font);
    virtual void Detach(cGZFont* font);
    virtual void Lock(cGZFont* font, void* surface, uint32_t mode);
    virtual void Unlock(cGZFont* font, void* surface, uint32_t mode);
};

// The renderer interface as the font calls it: slot 4 detaches, slot 2 releases.
struct RendererB_ac55d8 {
    virtual void Fn0();
    virtual void Fn1();
    virtual void Release();
    virtual void Fn3();
    virtual void Detach(cGZFont* font);
};

// The glyph cache's hash table, found by a character code.
struct GlyphTable_ac55d8 {
    // STUB: 0x00968cd9
    void* Fn00968cd9(const uint32_t* key);
};

// The glyph caches (two per font), cleared on a scale change.
struct GlyphCache_ac55d8 {
    // STUB: 0x008982ba
    void Fn008982ba();
};

// The per-glyph record a cache holds: its bounds and offsets.
struct Glyph_ac55d8 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
    int16_t mnXOffset;
    int16_t mnPad12;
    int16_t mnAdvance;
};

// FUNCTION: 0x00896b45
void cGZFont::SetRenderer(void* renderer)
{
    Renderer_ac55d8* r = static_cast<Renderer_ac55d8*>(renderer);
    if (renderer != mpRenderer) {
        if (r) {
            r->AddRef();
            r->Attach(this);
        }
        RendererB_ac55d8* old = static_cast<RendererB_ac55d8*>(mpRenderer);
        if (old) {
            old->Detach(this);
            static_cast<RendererB_ac55d8*>(mpRenderer)->Release();
        }
        mpRenderer = renderer;
    }
}

// FUNCTION: 0x00896b8e
bool cGZFont::LockSurfaceForFontUse(void* surface)
{
    if (mnLockCount == 0) {
        Renderer_ac55d8* r = static_cast<Renderer_ac55d8*>(mpRenderer);
        r->Lock(this, surface, Fn00896b2c(mnAntialiasing));
    }
    mnLockCount++;
    return true;
}

// FUNCTION: 0x00896bc2
bool cGZFont::UnlockSurfaceForFontUse(void* surface)
{
    if (mnLockCount == 1) {
        Renderer_ac55d8* r = static_cast<Renderer_ac55d8*>(mpRenderer);
        r->Unlock(this, surface, Fn00896b2c(mnAntialiasing));
    }
    mnLockCount--;
    return true;
}

// FUNCTION: 0x008972bd
int32_t cGZFont::CharWidth(const void* text, uint32_t length)
{
    if (mbReady) {
        uint32_t ch;
        if (mnCodePage == 0x10) {
            ch = *static_cast<const uint16_t*>(text);
        } else {
            ch = ConvertCharToUnicode(text, length, 0);
        }
        const Glyph_ac55d8* g = static_cast<const Glyph_ac55d8*>(GetCharData(ch));
        if (g) {
            return g->mnRight - g->mnLeft;
        }
    }
    return 0;
}

// FUNCTION: 0x00897304
int32_t cGZFont::GetXOffset(const void* text, uint32_t length)
{
    if (mbReady) {
        uint32_t ch;
        if (mnCodePage == 0x10) {
            ch = *static_cast<const uint16_t*>(text);
        } else {
            ch = ConvertCharToUnicode(text, length, 0);
        }
        const Glyph_ac55d8* g = static_cast<const Glyph_ac55d8*>(GetCharData(ch));
        if (g) {
            return g->mnXOffset;
        }
    }
    return 0;
}

// FUNCTION: 0x00897348
int32_t cGZFont::GetAdvanceWidth(const void* text, uint32_t length)
{
    if (mbReady) {
        uint32_t ch;
        if (mnCodePage == 0x10) {
            ch = *static_cast<const uint16_t*>(text);
        } else {
            ch = ConvertCharToUnicode(text, length, 0);
        }
        const Glyph_ac55d8* g = static_cast<const Glyph_ac55d8*>(GetCharData(ch));
        if (g) {
            return g->mnAdvance + mnSpacingX;
        }
    }
    return 0;
}

// FUNCTION: 0x0089834c
void* cGZFont::GetCharData(uint32_t ch)
{
    uint8_t* cache = static_cast<uint8_t*>(GetAppropriateCachedBitmapData());
    if (cache) {
        uint8_t* entry = static_cast<uint8_t*>(reinterpret_cast<GlyphTable_ac55d8*>(cache + 0x18)->Fn00968cd9(&ch));
        if (entry == 0) {
            return AddCharData(ch, cache);
        }
        return entry + 8;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0089865f score 17
void cGZFont::SetAdvanceScaling(float x, float y)
{
    float v = x;
    if (v < 0.1f) {
        v = 0.1f;
    } else if (v > 10.0f) {
        v = 10.0f;
    }
    if (v != mfAdvanceScale) {
        mfAdvanceScale = v;
        reinterpret_cast<GlyphCache_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x104)->Fn008982ba();
        reinterpret_cast<GlyphCache_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x130)->Fn008982ba();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00899987 score 17
void cGZFont::SetAntialiasingGammaCorrection(float gamma)
{
    float v = gamma;
    if (v < 0.0f) {
        v = 0.0f;
    } else if (v > 10.0f) {
        v = 10.0f;
    }
    if (v != mfGamma) {
        mfGamma = v;
        Fn008993bb();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008999ce score 15
void cGZFont::SetAntialiasingSharpness(float sharpness)
{
    float v = sharpness;
    if (v < -1.0f) {
        v = -1.0f;
    } else if (v > 1.0f) {
        v = 1.0f;
    }
    if (v != mfSharpness) {
        mfSharpness = v;
        Fn008993bb();
    }
}
#endif

// STUB: 0x0089f538
uint32_t Fn0089f538(uint32_t face, uint32_t code, uint32_t flags, void* out);
// STUB: 0x00912588
uint32_t Fn00912588(const void* text, uint32_t length, int32_t codePage);
// STUB: 0x00896254
bool Fn00896254(uint32_t ch);
// STUB: 0x00910855
uint32_t Fn00910855(const void* text, uint32_t count, int32_t codePage);

// FUNCTION: 0x00899ca7
bool cGZFont::IsCharAvailable(const void* text, uint32_t length)
{
    bool ok = true;
    if (length != 0) {
        const uint16_t* u;
        uint32_t n;
        GetTextAsUnicode(text, length, &u, &n, 0, false);
        uint32_t saved = mnCodePage;
        const uint16_t* end = u + n;
        mnCodePage = 0x10;
        for (const uint16_t* p = u; p < end; p++) {
            uint32_t tmp;
            if (Fn0089f538(*(reinterpret_cast<const uint32_t*>(static_cast<const uint8_t*>(mpFT) + 8)), *p, 0, &tmp) == 0) {
                ok = false;
                break;
            }
        }
        mnCodePage = saved;
    }
    return ok;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00899d2a score 25
bool cGZFont::PreloadChars(const void* text, uint32_t length)
{
    bool ready = mbReady;
    if (ready && length != 0) {
        const uint16_t* u;
        uint32_t n;
        GetTextAsUnicode(text, length, &u, &n, 0, false);
        for (uint32_t i = 0; i < n; i++) {
            GetCharData(u[i]);
        }
    }
    return ready;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00899f71 score 17
int32_t cGZFont::GetStringWidth(const void* text, uint32_t length)
{
    int32_t width = 0;
    if (length != 0) {
        const uint16_t* u;
        uint32_t n;
        GetTextAsUnicode(text, length, &u, &n, 4, false);
        uint32_t saved = mnCodePage;
        const uint16_t* end = u + n;
        mnCodePage = 0x10;
        for (const uint16_t* p = u; p < end;) {
            width += GetAdvanceWidth(p, 1);
            p += Fn00912588(p, end - p, mnCodePage);
        }
        mnCodePage = saved;
    }
    return width;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00899ff4 score 68
int32_t cGZFont::GetStringVisibleWidth(const void* text, uint32_t length, void* outLength)
{
    uint32_t* out = static_cast<uint32_t*>(outLength);
    int32_t width = 0;
    *out = 0;
    if (length != 0) {
        const uint16_t* u;
        uint32_t n;
        GetTextAsUnicode(text, length, &u, &n, 3, false);
        const uint16_t* p = u + n - 1;
        while (p >= u && Fn00896254(*p)) {
            n--;
            p--;
        }
        if (n != 0) {
            uint32_t saved = mnCodePage;
            mnCodePage = 0x10;
            width = GetStringWidth(u, n);
            mnCodePage = saved;
            if (saved != 0x10 && saved != 0) {
                n = Fn00910855(text, *out, saved);
            }
            *out = n;
        }
    }
    return width;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00896886 score 41
uint32_t cGZFont::CalculateNumberOfLines(const void* text, uint32_t length, uint32_t width)
{
    uint32_t lines = 0;
    if (width == 0) {
        width = 1;
    }
    const uint8_t* p = static_cast<const uint8_t*>(text);
    const uint8_t* end = p + ((mnCodePage == 0x10) ? length * 2 : length);
    while (p < end) {
        uint32_t used = CalculateWordsToFitInWidth(p, length, width, 0, 2);
        if (mnCodePage == 0x10) {
            p += used * 2;
        } else {
            p += used;
        }
        length -= used;
        lines++;
    }
    return lines;
}
#endif

// STUB: 0x009106a9
int32_t Fn009106a9(const void* text, int32_t length, int32_t codePage);

// A rectangle: left, top, right, bottom.
struct Rect_ac55d8 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
};

#ifdef OB_DRAFTS
// CLOSE: 0x008968eb score 31
uint32_t cGZFont::CalculateWidthOfLines(const void* text, uint32_t length, uint32_t height)
{
    uint32_t lineHeight = GetLineHeight();
    uint32_t low = 2;
    uint32_t high = 400;
    uint32_t maxLines = height / lineHeight;
    for (;;) {
        uint32_t mid = (high + low) >> 1;
        uint32_t lines = CalculateNumberOfLines(text, length, mid * 10);
        if (lines > maxLines) {
            low = mid + 1;
            mid = high;
        } else if (high == low) {
            return high * 10;
        }
        high = mid;
        if (low > high) {
            break;
        }
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00896808 score 48
uint32_t cGZFont::CalculateCharsToFitInWidth(const void* text, uint32_t length, uint32_t maxWidth, void* outWidth)
{
    uint32_t width = 0;
    uint32_t pos = 0;
    uint32_t prevWidth = 0;
    uint32_t prevPos = 0;
    if (length != 0) {
        while (width < maxWidth) {
            prevWidth = width;
            prevPos = pos;
            int32_t cp = mnCodePage;
            const uint8_t* p = static_cast<const uint8_t*>(text);
            if (cp == 0x10) {
                p += pos * 2;
            } else {
                p += pos;
            }
            pos += Fn009106a9(p, length - pos, cp);
            width = GetStringWidth(text, pos);
            if (pos >= length) {
                break;
            }
        }
        if (width > maxWidth) {
            pos = prevPos;
            width = prevWidth;
        }
    }
    if (outWidth) {
        *static_cast<uint32_t*>(outWidth) = width;
    }
    return pos;
}
#endif

// FUNCTION: 0x008969f2
void cGZFont::TextArea(const void* text, uint32_t length, void* rect)
{
    Rect_ac55d8* r = static_cast<Rect_ac55d8*>(rect);
    uint32_t height = CharHeight(0, 0);
    r->mnLeft = 0;
    r->mnTop = 0;
    r->mnRight = 0;
    r->mnBottom = height;
    r->mnRight = GetStringWidth(text, length);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00896957 score 37
void cGZFont::CalculateTextArea_2(const void* text, uint32_t length, void* rect, bool singleLine, bool wrap)
{
    Rect_ac55d8* r = static_cast<Rect_ac55d8*>(rect);
    if (length == 0 || text == 0) {
        r->mnRight = r->mnLeft;
    } else {
        if (singleLine) {
            if (wrap) {
                int32_t lineHeight = GetLineHeight();
                int32_t lines = CalculateNumberOfLines(text, length, r->mnRight - r->mnLeft);
                r->mnBottom = lineHeight * lines + r->mnTop;
                return;
            }
            r->mnRight = CalculateWidthOfLines(text, length, r->mnBottom - r->mnTop) + r->mnLeft;
            return;
        }
        int32_t left = r->mnLeft;
        r->mnRight = left + GetStringWidth(text, length);
    }
    r->mnBottom = r->mnTop + GetLineHeight();
}
#endif

// A glyph cache's source bitmap record.
struct SourceData_ac55d8 {
    uint8_t* mpBase;
    uint8_t* mpPixels;
    uint32_t mnWidth;
    uint32_t mnHeight;
    uint32_t mnPitch;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0089632d score 2
bool cGZFont::ReallocateSourceData(void* cache, uint32_t width, uint32_t height)
{
    SourceData_ac55d8* c = static_cast<SourceData_ac55d8*>(cache);
    if (width > c->mnWidth || height > c->mnHeight) {
        uint32_t bytes = (height + 4) * width;
        uint8_t* block = static_cast<uint8_t*>(::operator new(bytes));
        memset(block, 0, bytes);
        uint8_t* pixels = block + width * 2;
        if (c->mpPixels != 0) {
            uint8_t* dst = pixels;
            for (uint32_t row = 0; row < c->mnHeight; row++) {
                memcpy(dst, c->mpPixels + c->mnPitch * row, c->mnWidth);
                dst += width;
            }
            ::operator delete(c->mpBase);
        }
        c->mpBase = block;
        c->mpPixels = pixels;
        c->mnWidth = width;
        c->mnHeight = height;
        c->mnPitch = width;
    }
    return true;
}
#endif

// STUB: 0x0089dc9a
void Fn0089dc9a(uint32_t face, uint32_t a, uint32_t b, uint32_t c, void* matrix, uint32_t d, void* pen);

#ifdef OB_DRAFTS
// CLOSE: 0x0089854e score 74
void cGZFont::SetScaling(float x, float y)
{
    float sx = x;
    if (sx < 0.01f) {
        sx = 0.01f;
    } else if (sx > 1000.0f) {
        sx = 1000.0f;
    }
    float sy = y;
    if (sy < 0.01f) {
        sy = 0.01f;
    } else if (sy > 1000.0f) {
        sy = 1000.0f;
    }
    if (sx != mfScaleX || sy != mfScaleY) {
        mfScaleX = sx;
        mfScaleY = sy;
        reinterpret_cast<GlyphCache_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x104)->Fn008982ba();
        reinterpret_cast<GlyphCache_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x130)->Fn008982ba();
        float size = static_cast<float>(static_cast<int32_t>(mnSize));
        int32_t m[4];
        float pen[2];
        m[0] = static_cast<int32_t>(mfScaleX * 65536.0f * size);
        m[1] = 0;
        m[2] = 0;
        m[3] = static_cast<int32_t>(mfScaleY * 65536.0f * size);
        pen[0] = 0.0f;
        Fn0089dc9a(*(reinterpret_cast<const uint32_t*>(static_cast<const uint8_t*>(mpFT) + 8)), 1, 0x48, 0x48, m, 1, pen);
    }
}
#endif

// ---- wave 9, second hand: batch 1 (helpers on tables, trees, caches) ----

// GLOBAL: 0x00b54418
extern uint8_t g00b54418[0x8000];
// GLOBAL: 0x00b5c418
extern uint8_t g00b5c418;

#ifdef OB_DRAFTS
// CLOSE: 0x0089618d score 6
bool Fn0089618d()
{
    int32_t i = 0;
    uint8_t* p = g00b54418;
    do {
        int32_t j = 0;
        do {
            int32_t k = 0;
            do {
                float t = float(k) * 0.032258064f;
                p[k] = static_cast<uint8_t>(int32_t(float(i) * t + (1.0f - t) * float(j)));
                k++;
            } while (k < 32);
            j++;
            p += 32;
        } while (j < 32);
        i++;
    } while (p < g00b54418 + 0x8000);
    return true;
}
#endif

// A stream object of the font file reader: opened through its virtual slots.
struct Stream_ac55d8 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual bool Open(uint32_t a, uint32_t b, uint32_t c);
    virtual bool IsOpen();
    virtual void V5();
    virtual void V6();
    virtual uint32_t Size();
    virtual void V8();
    virtual void Rewind();
    virtual void V10();
    virtual void V11();
    virtual void Seek(uint32_t pos);
    virtual void V13();
    virtual uint32_t Read(void* buf, uint32_t n);
    uint8_t mPad_ac55d8[0x7c];
    uint32_t mnKind;
    uint32_t mnSignature;
    uint8_t mbFlag;
    // STUB: 0x00918c00
    void Fn00918c00(void* arg);
    // STUB: 0x00896d2f
    Stream_ac55d8* Fn00896d2f(void* arg);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00896d2f score 66
Stream_ac55d8* Stream_ac55d8::Fn00896d2f(void* arg)
{
    uint32_t tmp;
    Fn00918c00(arg);
    mnKind = 0;
    mnSignature = 0;
    mbFlag = 0;
    if (Open(2, 1, 1) && Size() > 9) {
        Rewind();
        Read(&tmp, 4);
        tmp = ((tmp & 0xff) << 24) | ((tmp & 0xff00) << 8) | ((tmp >> 8) & 0xff00) | (tmp >> 24);
        if (tmp == 0x4d58464e) {
            mnKind = 9;
            Read(&mnSignature, 4);
            mnSignature = ((mnSignature & 0xff) << 24) | ((mnSignature & 0xff00) << 8) | ((mnSignature >> 8) & 0xff00) | (mnSignature >> 24);
            Read(&mbFlag, 1);
        }
    }
    return this;
}
#endif

// FUNCTION: 0x0089738f
uint32_t cGZFont::Find(const void* text, uint32_t len, uint32_t ch)
{
    const uint8_t* start = static_cast<const uint8_t*>(text);
    const uint8_t* end = start + len;
    const uint8_t* p = start;
    uint32_t used;
    while (p < end) {
        if (ConvertCharToUnicode(p, len, &used) == ch) {
            return static_cast<uint32_t>(p - start);
        }
        p += used;
    }
    return 0xffffffff;
}

// A node of the glyph-range tree (an STL map keyed by a 16-bit code).
struct TreeNode_ac55d8 {
    TreeNode_ac55d8* mpUnused;
    TreeNode_ac55d8* mpParent;
    TreeNode_ac55d8* mpLeft;
    TreeNode_ac55d8* mpRight;
    uint16_t mnKey;
};

struct Tree_ac55d8 {
    TreeNode_ac55d8* mpHead;
    uint32_t mnPad;
    uint32_t mnPad2;
    uint32_t mnPad3;
    uint32_t mnSize;
    TreeNode_ac55d8* Fn0089762f(const uint16_t* key);
    TreeNode_ac55d8** Fn00897e7c(TreeNode_ac55d8** out, const uint16_t* key);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0089762f score 25
TreeNode_ac55d8* Tree_ac55d8::Fn0089762f(const uint16_t* key)
{
    TreeNode_ac55d8* head = mpHead;
    TreeNode_ac55d8* node = head->mpParent;
    TreeNode_ac55d8* best = head;
    while (node) {
        if (node->mnKey >= *key) {
            best = node;
            node = node->mpLeft;
        } else {
            node = node->mpRight;
        }
    }
    if (best == head || *key < best->mnKey) {
        best = head;
    }
    return best;
}
#endif

// A cache of glyph blocks: five owned buffers cleaned one by one.
// STUB: 0x0089f3e6
void Fn0089f3e6(void* p, void* alloc);
// STUB: 0x0089cabe
void Fn0089cabe(void* p, void* alloc);
// STUB: 0x0089ae0c
void Fn0089ae0c(void* p, void* alloc);
// STUB: 0x0089a8a7
void Fn0089a8a7(void* p);

struct FileObject_ac55d8 {
    // STUB: 0x00918c70
    void Fn00918c70();
};

struct BlockSet_ac55d8 {
    void* mpA;
    void* mpB;
    void* mpC;
    FileObject_ac55d8* mpFile;
    void* mpD;
    bool Fn008976a4();
    BlockSet_ac55d8* Fn00897722();
};

// FUNCTION: 0x008976a4
bool BlockSet_ac55d8::Fn008976a4()
{
    void* alloc = 0;
    if (mpC != 0) {
        Fn0089f3e6(mpC, &alloc);
        mpC = 0;
    }
    if (mpB != 0) {
        Fn0089cabe(mpB, &alloc);
        mpB = 0;
    }
    if (mpD != 0) {
        Fn0089ae0c(mpD, &alloc);
        mpD = 0;
    }
    FileObject_ac55d8* f = mpFile;
    if (f != 0) {
        f->Fn00918c70();
        ::operator delete(f);
        mpFile = 0;
    }
    if (mpA != 0) {
        Fn0089a8a7(mpA);
        mpA = 0;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00897722 score 3
BlockSet_ac55d8* BlockSet_ac55d8::Fn00897722()
{
    mpB = 0;
    if (g00b5c418 == 0) {
        Fn0089618d();
        g00b5c418 = 1;
    }
    return this;
}
#endif

// A bucket hash table (vector of chains) keyed by a 32-bit code.
struct HashNode_ac55d8 {
    HashNode_ac55d8* mpNext;
    uint32_t mnKey;
};

struct HashResult_ac55d8 {
    HashNode_ac55d8* mpNode;
    void* mpTable;
    bool mbInserted;
};

struct HashTable_ac55d8 {
    uint32_t mnPad;
    HashNode_ac55d8** mpBegin;
    HashNode_ac55d8** mpEnd;
    uint32_t mnPad2;
    uint32_t mnCount;
    // STUB: 0x00897a6e
    HashNode_ac55d8* Fn00897a6e(const uint32_t* key);
    // STUB: 0x00897cb2
    HashResult_ac55d8* Fn00897cb2(HashResult_ac55d8* out, const uint32_t* key);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00897cb2 score 40
HashResult_ac55d8* HashTable_ac55d8::Fn00897cb2(HashResult_ac55d8* out, const uint32_t* key)
{
    uint32_t k = *key;
    uint32_t n = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t idx = k % n;
    HashNode_ac55d8* first = mpBegin[idx];
    HashNode_ac55d8* node = first;
    while (node) {
        if (node->mnKey == k) {
            out->mpNode = node;
            out->mpTable = this;
            out->mbInserted = false;
            return out;
        }
        node = node->mpNext;
    }
    HashNode_ac55d8* made = Fn00897a6e(key);
    made->mpNext = first;
    mpBegin[idx] = made;
    mnCount++;
    out->mpNode = made;
    out->mpTable = this;
    out->mbInserted = true;
    return out;
}
#endif

// STUB: 0x0040d500
TreeNode_ac55d8* Fn0040d500(TreeNode_ac55d8* node);

struct TreeInsert_ac55d8 {
    TreeNode_ac55d8* mpHead;
    // STUB: 0x00897dac
    TreeNode_ac55d8** Fn00897dac(const uint16_t** key, TreeNode_ac55d8* x, TreeNode_ac55d8* y, const uint16_t* v, uint32_t flag);
    void* Fn00897e7c(void* out, const uint16_t* key);
};

// FUNCTION: 0x00897e7c
void* TreeInsert_ac55d8::Fn00897e7c(void* out, const uint16_t* key)
{
    TreeNode_ac55d8* head = mpHead;
    TreeNode_ac55d8* x = head->mpParent;
    TreeNode_ac55d8* y = head;
    bool left = true;
    while (x) {
        y = x;
        left = *key < x->mnKey;
        x = left ? x->mpLeft : x->mpRight;
    }
    TreeNode_ac55d8* j = y;
    if (left) {
        if (y == head->mpLeft) {
            TreeNode_ac55d8** it = Fn00897dac(&key, x, y, key, 0);
            *static_cast<TreeNode_ac55d8**>(out) = *it;
            static_cast<uint8_t*>(out)[4] = 1;
            return out;
        }
        j = Fn0040d500(y);
    }
    if (j->mnKey < *key) {
        TreeNode_ac55d8** it = Fn00897dac(&key, x, y, key, 0);
        *static_cast<TreeNode_ac55d8**>(out) = *it;
        static_cast<uint8_t*>(out)[4] = 1;
        return out;
    }
    *static_cast<TreeNode_ac55d8**>(out) = j;
    static_cast<uint8_t*>(out)[4] = 0;
    return out;
}

// A glyph cache's bitmap record (Draft of the cache clear the glyph tables call).
struct CacheInner_ac55d8 {
    // STUB: 0x0097c1a2
    void Fn0097c1a2();
};

struct CachedBitmap_ac55d8 {
    void* mpData;
    uint32_t mnF4;
    uint32_t mnF8;
    uint32_t mnFc;
    uint32_t mnF10;
    uint32_t mnF14;
    CacheInner_ac55d8 mInner;
    void Fn008982baDraft_ac55d8();
};

// FUNCTION: 0x008982ba
void CachedBitmap_ac55d8::Fn008982baDraft_ac55d8()
{
    ::operator delete(mpData);
    mpData = 0;
    mnF4 = 0;
    mnF8 = 0;
    mnFc = 0;
    mnF10 = 0;
    mnF14 = 0;
    mInner.Fn0097c1a2();
}

// ---- batch 2 ----

#define FONT_AT_AC55D8(Type, base, off) (*reinterpret_cast<Type*>(reinterpret_cast<uint8_t*>(base) + (off)))

// A string object reached through its slots: 6 = text, 7 = length, 15 = truncate, 17 = append.
struct Str_ac55d8 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual const char* ToChar();
    virtual uint32_t Length();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void Truncate(uint32_t n);
    virtual void V16();
    virtual void Append(const char* text, uint32_t n);
};

// A growable array of two pointers (begin, end) read as a width.
struct Span_ac55d8 {
    uint32_t mpBegin;
    uint32_t mpPad;
    uint32_t mpEnd;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00896a2d score 2
uint32_t cGZFont::FormatForEllipsis(uint32_t s, uint32_t t, uint32_t span, uint32_t skip)
{
    Str_ac55d8* S = OB_PTR(Str_ac55d8, s);
    uint32_t n = S->Length();
    if (!static_cast<uint8_t>(skip)) {
        Span_ac55d8* sp = OB_PTR(Span_ac55d8, span);
        uint32_t w = sp->mpEnd - sp->mpBegin;
        uint32_t fit = CalculateCharsToFitInWidth(S->ToChar(), n, w, 0);
        if (fit < n) {
            Str_ac55d8* T = OB_PTR(Str_ac55d8, t);
            int32_t tw = GetStringWidth(T->ToChar(), T->Length());
            if (tw >= static_cast<int32_t>(w)) {
                S->Truncate(0);
            } else {
                uint32_t idx = CalculateCharsToFitInWidth(S->ToChar(), n, w - tw, 0);
                S->Truncate(idx);
                while (S->Length() != 0) {
                    const char* p = S->ToChar();
                    uint32_t len = S->Length();
                    if (p[len - 1] != ' ') {
                        break;
                    }
                    S->Truncate(S->Length() - 1);
                }
                S->Append(T->ToChar(), T->Length());
            }
        }
    }
    return n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008973d4 score 110
bool cGZFont::CalculateTextArea(uint32_t text, uint32_t len, uint32_t rectp, uint32_t maxW, uint32_t wrapW, uint32_t maxH)
{
    int32_t* rect = OB_PTR(int32_t, rectp);
    const void* txt = OB_PTR(const void, text);
    int32_t w = 1;
    int32_t lh = static_cast<int32_t>(GetLineHeight());
    int32_t limitH = static_cast<int32_t>(maxH);
    int32_t mw = static_cast<int32_t>(maxW);
    int32_t ww = static_cast<int32_t>(wrapW);
    if (limitH < lh) {
        limitH = lh;
    }
    if (mw == -1 || ww == -1) {
        char a = 'a';
        int32_t cw = CharWidth(&a, 1);
        if (mw == -1) {
            mw = cw * 12;
        }
        if (ww == -1) {
            ww = cw << 5;
        }
        if (ww <= mw) {
            ww = mw * 2;
        }
    }
    if (Find(txt, len, 10) == 0xffffffff) {
        w = GetStringWidth(txt, len);
        if (w < mw && lh <= limitH) {
            rect[2] = rect[0] + w;
            rect[3] = rect[1] + lh;
            return true;
        }
        if (w < mw * 2) {
            int32_t h2 = lh * 2;
            uint32_t two = CalculateWidthOfLines(txt, len, h2);
            if (two < static_cast<uint32_t>(ww) && h2 <= limitH) {
                rect[2] = rect[0] + two;
                rect[3] = rect[1] + h2;
                return true;
            }
        }
        if (w < ww && lh <= limitH) {
            rect[2] = rect[0] + w;
            rect[3] = rect[1] + lh;
            return true;
        }
    }
    int32_t maxLines = limitH / lh;
    int32_t i = w / ww + 1;
    if (i < maxLines) {
        int32_t h = i * lh;
        do {
            uint32_t found = CalculateWidthOfLines(txt, len, h);
            if (found != 0 && found < static_cast<uint32_t>(ww) && h <= limitH) {
                rect[2] = rect[0] + found;
                rect[3] = i * lh + rect[1];
                return true;
            }
            h += lh;
            i++;
        } while (i < maxLines);
    }
    rect[2] = rect[0];
    rect[3] = rect[1];
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00897ab1 score 32
bool cGZFont::SetSize(uint32_t size)
{
    if (size == 0 || FONT_AT_AC55D8(uint32_t, this, 0x12c) != 0 || FONT_AT_AC55D8(uint32_t, this, 0x158) != 0) {
        return false;
    }
    if (size > 0x800) {
        size = 0x800;
    }
    uint8_t* face = static_cast<uint8_t*>(mpFT);
    mnSize = size;
    if (face == 0 || FONT_AT_AC55D8(uint32_t, face, 8) == 0) {
        return true;
    }
    uint8_t* ft = reinterpret_cast<uint8_t*>(FONT_AT_AC55D8(uint32_t, face, 8));
    int32_t matrix[4];
    uint32_t err = 0;
    float f = static_cast<float>(size);
    matrix[0] = static_cast<int32_t>(65536.0f * mfScaleX * f);
    matrix[1] = 0;
    matrix[2] = 0;
    matrix[3] = static_cast<int32_t>(65536.0f * mfScaleY * f);
    Fn0089dc9a(OB_ADDR(ft), 1, 0x48, 0x48, matrix, 1, &err);
    uint8_t* rec = reinterpret_cast<uint8_t*>(FONT_AT_AC55D8(uint32_t, face, 8));
    FONT_AT_AC55D8(int32_t, this, 0x88) = FONT_AT_AC55D8(int32_t, rec, 0x7c) / 0x10000;
    rec = reinterpret_cast<uint8_t*>(FONT_AT_AC55D8(uint32_t, face, 8));
    FONT_AT_AC55D8(int32_t, this, 0x84) = (FONT_AT_AC55D8(int32_t, rec, 0x7c) + FONT_AT_AC55D8(int32_t, rec, 0x6c)) / 0x10000;
    rec = reinterpret_cast<uint8_t*>(FONT_AT_AC55D8(uint32_t, face, 8));
    int32_t h = (FONT_AT_AC55D8(int32_t, rec, 0x7c) - FONT_AT_AC55D8(int32_t, rec, 0x74) + FONT_AT_AC55D8(int32_t, rec, 0x6c)) / 0x10000;
    mnHeight = h;
    if (h <= 0) {
        mnHeight = 1;
    }
    uint32_t kind = FONT_AT_AC55D8(uint32_t, face, 0x24);
    if (kind == 2 || kind == 3) {
        mnHeight++;
        if (static_cast<uint32_t>(mnHeight) > 0x1c) {
            mnHeight++;
        }
    }
    return err == 0;
}
#endif

struct ListNode_ac55d8 {
    ListNode_ac55d8* mpNext;
    ListNode_ac55d8* mpPrev;
    void* mpData;
};

struct ListHead_ac55d8 {
    ListNode_ac55d8* mpHead;
    // STUB: 0x009a841f
    void Fn009a841f();
};

// FUNCTION: 0x008982e1
bool cGZFont::Shutdown()
{
    if (mbReady) {
        SetRenderer(0);
        reinterpret_cast<GlyphCache_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x104)->Fn008982ba();
        reinterpret_cast<GlyphCache_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x130)->Fn008982ba();
        FONT_AT_AC55D8(uint32_t, this, 0xfc) = 0;
        ListHead_ac55d8* list = reinterpret_cast<ListHead_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x100);
        ListNode_ac55d8* node = list->mpHead->mpNext;
        while (node != list->mpHead) {
            ::operator delete(node->mpData);
            node = node->mpNext;
        }
        list->Fn009a841f();
        static_cast<BlockSet_ac55d8*>(mpFT)->Fn008976a4();
        mbReady = 0;
    }
    return true;
}

// STUB: 0x009978af
uint32_t OB_STDCALL Fn009978af(uint32_t count);


struct HashTableB_ac55d8 : HashTable_ac55d8 {
    HashResult_ac55d8* Fn008986bf(HashResult_ac55d8* out, const uint32_t* key);
};

// FUNCTION: 0x008986bf
HashResult_ac55d8* HashTableB_ac55d8::Fn008986bf(HashResult_ac55d8* out, const uint32_t* key)
{
    Fn009978af(mnCount + 1);
    Fn00897cb2(out, key);
    return out;
}

struct Pair_ac55d8 {
    uint16_t mnKey;
    uint32_t mnValue;
};

// GLOBAL: 0x00b150f0
extern Pair_ac55d8 g00b150f0[];
// GLOBAL: 0x00b5c41c
extern TreeInsert_ac55d8 g00b5c41c;

#ifdef OB_DRAFTS
// CLOSE: 0x008988f1 score 7
void Fn008988f1()
{
    for (uint32_t i = 0; i < 0xef8; i += 8) {
        Pair_ac55d8 p;
        uint8_t result[8];
        p.mnKey = *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(g00b150f0) + i);
        p.mnValue = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(g00b150f0) + i + 4);
        g00b5c41c.Fn00897e7c(result, &p.mnKey);
    }
}
#endif

// A byte buffer (begin, end) the reader fills.
struct Buffer_ac55d8 {
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    // STUB: 0x0040e490
    void Fn0040e490(uint8_t* begin, uint8_t* end);
    // STUB: 0x00478aa0
    void Fn00478aa0(uint32_t n);
};

struct Stream2_ac55d8 : Stream_ac55d8 {
    // STUB: 0x00896ddd
    bool Fn00896ddd(uint8_t* dst, uint32_t offset, uint32_t n);
    bool Fn00898c6b(Buffer_ac55d8* buf, uint32_t n);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00898c6b score 20
bool Stream2_ac55d8::Fn00898c6b(Buffer_ac55d8* buf, uint32_t n)
{
    bool ok = false;
    buf->Fn0040e490(buf->mpBegin, buf->mpEnd);
    if (IsOpen()) {
        uint32_t avail = Size() - mnKind;
        uint32_t take = avail < n ? avail : n;
        buf->Fn00478aa0(take);
        Seek(mnKind);
        ok = Fn00896ddd(buf->mpBegin, 0, take);
    }
    return ok;
}
#endif

// ---- batch 3 ----

// STUB: 0x00910e18
uint32_t ConvertStringEncoding_ac55d8(const void* text, uint32_t n, int32_t codePage, void* out, void* outCount, uint32_t flags);

#ifdef OB_DRAFTS
// CLOSE: 0x0089671f score 63
uint32_t cGZFont::ConvertCharToUnicode(const void* text, uint32_t n, void* used)
{
    if (n == 0) {
        return 0;
    }
    uint32_t cp = mnCodePage;
    const uint8_t* p = static_cast<const uint8_t*>(text);
    uint16_t wide;
    uint32_t count;
    if (cp == 0) {
        if (*p <= 0x7f) {
            if (used) {
                *static_cast<uint32_t*>(used) = 1;
            }
            return *p;
        }
        count = 1;
        ConvertStringEncoding_ac55d8(p, 1, 0, &wide, &count, 0x10);
        if (used) {
            *static_cast<uint32_t*>(used) = 1;
        }
        return wide;
    }
    if (cp == 0x10) {
        if (used) {
            *static_cast<uint32_t*>(used) = 2;
        }
        return *reinterpret_cast<const uint16_t*>(p);
    }
    if (*p <= 0x7f) {
        if (used) {
            *static_cast<uint32_t*>(used) = 1;
        }
        return *p;
    }
    int32_t size = Fn009106a9(p, n, cp);
    count = 1;
    uint32_t r = ConvertStringEncoding_ac55d8(p, size, cp, &wide, &count, 0x10);
    if (used) {
        *static_cast<uint32_t*>(used) = r;
    }
    return wide;
}
#endif

struct VecU32_ac55d8 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x007ebd30
    void Fn007ebd30(const uint32_t* v);
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

#ifdef OB_DRAFTS
// CLOSE: 0x00898a5a score 94
bool cGZFont::IsCodePageAvailable(uint32_t cp)
{
    VecU32_ac55d8 chars;
    uint32_t code;
    uint32_t i = 0;
    bool ok;
    chars.mpBegin = 0;
    chars.mpEnd = 0;
    chars.mpCap = 0;
    code = cp;
    if (cp == 0) {
        code = 0x61;
        chars.Fn007ebd30(&code);
    } else if (cp == 8 || cp == 0x10) {
        return true;
    } else {
        switch (cp) {
        case 874:
            code = 0xe01;
            chars.Fn007ebd30(&code);
            code = 0xe2c;
            break;
        case 932:
            code = 0x3061;
            chars.Fn007ebd30(&code);
            code = 0x30a4;
            break;
        case 936:
            code = 0x70a7;
            chars.Fn007ebd30(&code);
            code = 0x7535;
            break;
        case 949:
            code = 0xc2b9;
            chars.Fn007ebd30(&code);
            code = 0xc9d1;
            break;
        case 950:
            code = 0x6f54;
            chars.Fn007ebd30(&code);
            code = 0x70b5;
            break;
        case 1250:
            code = 0x142;
            break;
        case 1251:
            code = 0x401;
            break;
        case 1252:
            code = 0x61;
            break;
        case 1253:
            code = 0x370;
            chars.Fn007ebd30(&code);
            code = 0x393;
            break;
        case 1254:
            code = 0x11e;
            break;
        case 1255:
            code = 0x5d0;
            chars.Fn007ebd30(&code);
            code = 0x5e2;
            break;
        case 1256:
            code = 0x621;
            chars.Fn007ebd30(&code);
            code = 0x641;
            break;
        case 1257:
            code = 0x160;
            break;
        default:
            goto scan;
        }
        chars.Fn007ebd30(&code);
    }
scan:
    {
        int32_t n = static_cast<int32_t>(chars.mpEnd - chars.mpBegin);
        ok = true;
        if (n > 0) {
            do {
                if (Fn0089f538(*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(mpFT) + 8), chars.mpBegin[i], 0, &code) == 0) {
                    ok = false;
                    break;
                }
                i++;
            } while (static_cast<int32_t>(i) < n);
        }
    }
    if (chars.mpBegin != 0) {
        Fn0090cf63(chars.mpBegin);
    }
    return ok;
}
#endif

// The FreeType side of a font: library, size object, face, file, data, buffer.
// STUB: 0x0089a594
void* Fn0089a594(uint32_t* err);
// STUB: 0x0089ad13
void* Fn0089ad13(void* lib, void* file, void (*callback)(), uint32_t arg, uint32_t* err);

// STUB: 0x00896e4a
void Fn00896e4a();
// STUB: 0x008a1c10
uint32_t Fn008a1c10(void* data, uint32_t* err);
// STUB: 0x0089f7c6
void Fn0089f7c6(uint8_t* data, uint32_t* n, uint32_t* err);
// STUB: 0x0089ac7e
void* Fn0089ac7e(void* lib, uint8_t* data, uint32_t n, uint32_t* err);
// STUB: 0x0089d662
void* Fn0089d662(void* lib, uint32_t kind, uint32_t a, void* data, uint32_t b, uint32_t c, uint32_t* err);
// STUB: 0x0089d8dc
void* Fn0089d8dc(void* lib, void* size, uint32_t* err);
// STUB: 0x0089f4f3
uint32_t Fn0089f4f3(void* face, const void* arg, uint32_t* err);
// STUB: 0x0089f4b2
uint32_t Fn0089f4b2(void* face, uint32_t glyph, uint32_t* err);

struct FtFont_ac55d8 : BlockSet_ac55d8 {
    // BlockSet: mpA = library (0), mpB = size (4), mpC = face (8), mpFile (0xc), mpD = data (0x10)
    Buffer_ac55d8 mBuffer;
    uint32_t mnPad1c;
    uint8_t mnFlagsLo;
    uint8_t mnFlagsHi;
    uint16_t mnPad22;
    uint32_t mnType;
    TreeInsert_ac55d8 mTree;
    // STUB: 0x00898cd9
    bool Fn00898cd9(void* arg);
    // STUB: 0x00898eb2
    uint32_t Fn00898eb2(uint32_t code);
    // STUB: 0x0089801e
    bool Fn0089801e(void* name, uint32_t mode);
    // STUB: 0x0089883f
    uint32_t Fn0089883f();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00898cd9 score 101
bool FtFont_ac55d8::Fn00898cd9(void* arg)
{
    uint32_t err = 0;
    Fn008976a4();
    mpA = Fn0089a594(&err);
    if (mpA != 0 && err == 0) {
        void* mem = ::operator new(0x8c);
        Stream_ac55d8* s = 0;
        if (mem != 0) {
            s = static_cast<Stream_ac55d8*>(mem)->Fn00896d2f(arg);
        }
        mpFile = reinterpret_cast<FileObject_ac55d8*>(s);
        mpD = Fn0089ad13(mpA, mpFile, Fn00896e4a, 0, &err);
        if (mpD != 0 && err == 0) {
            uint16_t kind = static_cast<uint16_t>(Fn008a1c10(mpD, &err));
            if (kind == 1) {
                mnType = 2;
            } else if (kind == 0x16) {
                mnType = 3;
            } else if (kind == 7) {
                mnType = 4;
            } else if (kind == 2) {
                mnType = 1;
            } else {
                mnType = 0;
            }
            if (mnType != 0 && err == 0) {
                if (mnType == 2) {
                    if (static_cast<Stream2_ac55d8*>(reinterpret_cast<Stream_ac55d8*>(mpFile))->Fn00898c6b(&mBuffer, 0xffffffff)) {
                        uint32_t n = static_cast<uint32_t>(mBuffer.mpEnd - mBuffer.mpBegin);
                        Fn0089f7c6(mBuffer.mpBegin, &n, &err);
                        if (err == 0) {
                            mBuffer.Fn00478aa0(n);
                            void* data = Fn0089ac7e(mpA, mBuffer.mpBegin, static_cast<uint32_t>(mBuffer.mpEnd - mBuffer.mpBegin), &err);
                            Fn0089ae0c(mpD, &err);
                            mpD = data;
                        }
                    }
                }
                if (mpA != 0 && err == 0) {
                    mpB = Fn0089d662(mpA, kind, 0, mpD, 0, 0, &err);
                    if (mpB != 0 && err == 0) {
                        mpC = Fn0089d8dc(mpA, mpB, &err);
                        if (mpC != 0 && err == 0) {
                            uint8_t* face = static_cast<uint8_t*>(mpC);
                            *reinterpret_cast<uint16_t*>(*reinterpret_cast<uint8_t**>(face + 0x180) + 0x74) = 3;
                            uint8_t* face2 = static_cast<uint8_t*>(mpC);
                            *reinterpret_cast<uint16_t*>(*reinterpret_cast<uint8_t**>(face2 + 0x180) + 0x76) = 1;
                            *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(mpC) + 0x48) = 1;
                            if (kind == 2 || kind == 7) {
                                mnFlagsLo |= 0x80;
                            } else {
                                *reinterpret_cast<uint16_t*>(&mnFlagsLo) |= 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return mpC != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00898eb2 score 38
uint32_t FtFont_ac55d8::Fn00898eb2(uint32_t code)
{
    uint32_t err = 0;
    uint32_t key = code;
    Tree_ac55d8* tree = reinterpret_cast<Tree_ac55d8*>(&mTree);
    TreeNode_ac55d8* it = tree->Fn0089762f(reinterpret_cast<const uint16_t*>(&key));
    if (it != tree->mpHead) {
        return *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(it) + 0x14);
    }
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(&g00b5c41c) + 4) == 0) {
        Fn008988f1();
    }
    Tree_ac55d8* global = reinterpret_cast<Tree_ac55d8*>(&g00b5c41c);
    key = code;
    TreeNode_ac55d8* g = global->Fn0089762f(reinterpret_cast<const uint16_t*>(&key));
    if (g != global->mpHead) {
        uint32_t glyph = Fn0089f4f3(mpC, OB_PTR(const void, *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(g) + 0x14)), &err);
        if (glyph != 0) {
            uint32_t idx = Fn0089f4b2(mpC, glyph, &err) & 0xffff;
            if (idx != 0) {
                Pair_ac55d8 p;
                uint8_t result[8];
                p.mnKey = static_cast<uint16_t>(code);
                p.mnValue = idx;
                mTree.Fn00897e7c(result, &p.mnKey);
                return idx;
            }
        }
    }
    char name[0x18];
    sprintf(name, "uni%04X", code & 0xffff);
    uint32_t glyph = Fn0089f4f3(mpC, name, &err);
    if (glyph != 0) {
        uint32_t idx = Fn0089f4b2(mpC, glyph, &err) & 0xffff;
        if (idx != 0) {
            Pair_ac55d8 p;
            uint8_t result[8];
            p.mnKey = static_cast<uint16_t>(code);
            p.mnValue = idx;
            mTree.Fn00897e7c(result, &p.mnKey);
            return idx;
        }
    }
    return 0;
}
#endif

// A vector of 0x24-byte records.
struct Elem36_ac55d8 {
    uint8_t mData[0x24];
};

struct Vec36_ac55d8 {
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    // STUB: 0x00897e56
    void Fn00897e56(uint8_t* first, uint8_t* last);
    // STUB: 0x0089874d
    void Fn0089874d(uint8_t* where, uint32_t count, const Elem36_ac55d8* fill);
    // STUB: 0x00899513
    void Fn00899513(uint32_t n, const Elem36_ac55d8* fill);
    void Fn00899a73(uint32_t n);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00899513 score 3
void Vec36_ac55d8::Fn00899513(uint32_t n, const Elem36_ac55d8* fill)
{
    uint8_t* last = mpEnd;
    uint8_t* first = mpBegin;
    uint32_t size = static_cast<uint32_t>((last - first) / 0x24);
    if (n < size) {
        Fn00897e56(first + n * 0x24, last);
    } else {
        uint8_t* e = mpEnd;
        Fn0089874d(e, n - static_cast<uint32_t>((e - first) / 0x24), fill);
    }
}
#endif

// FUNCTION: 0x00899a73
void Vec36_ac55d8::Fn00899a73(uint32_t n)
{
    Elem36_ac55d8 blank;
    Fn00899513(n, &blank);
}

struct VecU16_ac55d8 {
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    // STUB: 0x0049d0c0
    void Fn0049d0c0(uint32_t n);
};

// A text conversion: returns the number of 16-bit units written.
struct Converter_ac55d8 {
    uint8_t mPad[0x7c];
    int32_t mnCodePage;
    uint32_t Fn00899a15(const void* text, uint32_t n, VecU16_ac55d8* out);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00899a15 score 2
uint32_t Converter_ac55d8::Fn00899a15(const void* text, uint32_t n, VecU16_ac55d8* out)
{
    int32_t cp = mnCodePage;
    if (cp == 0x10) {
        out->Fn0049d0c0(n);
        memcpy(out->mpBegin, text, n * 2);
        return n;
    }
    uint32_t count = static_cast<uint32_t>(out->mpEnd - out->mpBegin) >> 1;
    ConvertStringEncoding_ac55d8(text, n, cp, out->mpBegin, &count, 0x10);
    return count;
}
#endif

// ---- batch 4 (text conversion, init, antialiasing table) ----

// STUB: 0x0091169f
int32_t Fn0091169f(uint32_t ch);
// STUB: 0x00897599
uint16_t* Fn00897599(uint16_t* first, uint16_t* last, const uint32_t* value);
// STUB: 0x00645ca0
void OB_STDCALL Fn00645ca0(uint8_t* where, const uint32_t* value);
// STUB: 0x00910014
uint32_t Fn00910014();
// STUB: 0x0091227b
uint32_t Fn0091227b(const uint16_t* text, uint32_t n);
// STUB: 0x009100de
bool Fn009100de(uint32_t ch);
// STUB: 0x00911cde
uint32_t Fn00911cde(const uint16_t* text, uint32_t n);
// STUB: 0x00919e96
bool Fn00919e96(void* path);

struct Vec16B_ac55d8 {
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    uint8_t* mpCap;
    // STUB: 0x008986e3
    void Fn008986e3(uint32_t n);
    // STUB: 0x0049d0c0
    void Fn0049d0c0(uint32_t n);
    // STUB: 0x00897bdc
    void Fn00897bdc(uint8_t* where, const uint16_t* value);
    // STUB: 0x00800540
    void Fn00800540(const uint16_t* value);
    // STUB: 0x0040e490
    void Fn0040e490(uint8_t* begin, uint8_t* end);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00899665 score 342
void cGZFont::MakeSubstitutedString(void* textv, uint32_t n, void* outpv, void* outnv, bool flag)
{
    uint16_t* text = static_cast<uint16_t*>(textv);
    uint16_t** outp = static_cast<uint16_t**>(outpv);
    uint32_t* outn = static_cast<uint32_t*>(outnv);
    *outp = text;
    *outn = n;
    if (n == 0) {
        return;
    }
    Vec16B_ac55d8* v = reinterpret_cast<Vec16B_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0xcc);
    for (;;) {
        uint32_t key = 0xe33;
        uint16_t* end = text + n;
        uint16_t* hit = Fn00897599(text, end, &key);
        if (hit != end) {
            if (static_cast<uint32_t>(v->mpCap - v->mpBegin) >> 1 < n * 2) {
                v->Fn008986e3(n * 2);
            }
            v->Fn0049d0c0(0);
            uint32_t pos = 0;
            uint16_t* p = text;
            for (; p < end; p++) {
                if (*p == 0xe33) {
                    uint32_t idx = pos >> 1;
                    uint16_t val;
                    if (p > text && Fn0091169f(p[-1]) == 9) {
                        val = 0xe4d;
                        v->Fn00897bdc(v->mpBegin + (v->mpEnd - v->mpBegin) - 2, &val);
                        if (flag) {
                            uint8_t* vec = reinterpret_cast<uint8_t*>(this) + 0xd8;
                            Fn00645ca0(*reinterpret_cast<uint8_t**>(vec) + ((*reinterpret_cast<uint8_t**>(vec + 4) - *reinterpret_cast<uint8_t**>(vec)) >> 2) * 4 - 4, &idx);
                        }
                    } else {
                        val = 0xe4d;
                        v->Fn00800540(&val);
                        if (flag) {
                            reinterpret_cast<VecU32_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0xd8)->Fn007ebd30(&idx);
                        }
                    }
                    val = 0xe32;
                    v->Fn00800540(&val);
                } else {
                    v->Fn00800540(p);
                    if (flag) {
                        uint32_t idx = pos >> 1;
                        reinterpret_cast<VecU32_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0xd8)->Fn007ebd30(&idx);
                    }
                }
                pos += 2;
            }
            uint32_t total = static_cast<uint32_t>(p - text);
            reinterpret_cast<VecU32_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0xd8)->Fn007ebd30(&total);
            text = reinterpret_cast<uint16_t*>(v->mpBegin);
            n = static_cast<uint32_t>(v->mpEnd - v->mpBegin) >> 1;
            *outp = text;
            *outn = n;
            flag = false;
            if (n != 0) {
                continue;
            }
            return;
        }
        uint16_t cur = text[0];
        uint32_t curType = Fn0091169f(cur);
        uint16_t prev = 0;
        uint32_t prevType = 0;
        uint32_t state = 0;
        for (uint32_t i = 0; i < n; i++) {
            uint32_t t = curType;
            uint16_t next;
            uint32_t nextType;
            if (i < n - 1) {
                next = text[i + 1];
                nextType = next != 0 ? Fn0091169f(next) : 0;
            } else {
                nextType = 0;
                next = 0;
            }
            uint32_t old = state;
            state = 0;
            uint16_t out = text[i];
            if (cur == 0xe0d && nextType >= 6 && nextType <= 8) {
                out = static_cast<uint16_t>(GetSubstitutionChar(0xe0d, 1));
            } else if (t < 0x10) {
                uint32_t bit = 1u << t;
                if (bit & 0xee00) {
                    if (old == 1 || prev == 0xe1b || prev == 0xe1d || prev == 0xe1f || prev == 0xe2c) {
                        state = 1;
                    }
                    if ((t == 9 || cur == 0xe4c) && prevType < 10) {
                        state += 2;
                    }
                    if (state != 0) {
                        out = static_cast<uint16_t>(GetSubstitutionChar(cur, state));
                    }
                } else if ((bit & 0xc0) && (prev == 0xe1b || prev == 0xe1d || prev == 0xe1f || prev == 0xe2c)) {
                    state = 1;
                }
            }
            (*outp)[i] = out;
            prev = cur;
            cur = next;
            prevType = t;
            curType = nextType;
        }
        return;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00899bca score 40
void GetTextAsUnicodeDraft_ac55d8(cGZFont* self, const void* text, uint32_t n, void* outp, void* outn, int32_t index, bool flag)
{
    Vec16B_ac55d8* buf = reinterpret_cast<Vec16B_ac55d8*>(reinterpret_cast<uint8_t*>(self) + (index * 3 + 0x24) * 4);
    uint16_t** pp = static_cast<uint16_t**>(outp);
    uint32_t* pn = static_cast<uint32_t*>(outn);
    if (flag) {
        Vec16B_ac55d8* map = reinterpret_cast<Vec16B_ac55d8*>(reinterpret_cast<uint8_t*>(self) + 0xd8);
        map->Fn0040e490(map->mpBegin, map->mpEnd);
    }
    if (self->mnCodePage == 0x10) {
        if (self->Fn00896425(text, n)) {
            if ((static_cast<uint32_t>(buf->mpEnd - buf->mpBegin) >> 1) < n * 2) {
                buf->Fn0049d0c0(n * 2);
            }
            uint32_t count = reinterpret_cast<Converter_ac55d8*>(self)->Fn00899a15(text, n, reinterpret_cast<VecU16_ac55d8*>(buf));
            *pn = count;
            self->MakeSubstitutedString(reinterpret_cast<uint16_t*>(buf->mpBegin), count, pp, pn, flag);
        } else {
            *pp = static_cast<uint16_t*>(const_cast<void*>(text));
            *pn = n;
        }
    } else {
        if ((static_cast<uint32_t>(buf->mpEnd - buf->mpBegin) >> 1) < n * 12) {
            buf->Fn0049d0c0(n * 12);
        }
        uint32_t count = reinterpret_cast<Converter_ac55d8*>(self)->Fn00899a15(text, n, reinterpret_cast<VecU16_ac55d8*>(buf));
        *pn = count;
        uint16_t* p = reinterpret_cast<uint16_t*>(buf->mpBegin);
        if (self->Fn00896425(p, count)) {
            self->MakeSubstitutedString(p, count, pp, pn, flag);
        } else {
            *pp = p;
        }
    }
}
#endif

struct Smoothing_ac55d8 {
    virtual void V0();
    virtual void AddRef();
    uint32_t mnPad4;
    // STUB: 0x00897722
    Smoothing_ac55d8* Fn00897722();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0089955c score 45
bool cGZFont::Init()
{
    if (!mbReady && FONT_AT_AC55D8(uint32_t, this, 0x10) != FONT_AT_AC55D8(uint32_t, this, 0x14)) {
        void* path = reinterpret_cast<uint8_t*>(this) + 0xc;
        if (Fn00919e96(path)) {
            FtFont_ac55d8* ft = static_cast<FtFont_ac55d8*>(mpFT);
            if (ft->Fn00898cd9(path)) {
                uint32_t err = 0;
                bool good = true;
                if (mnSize != 0) {
                    good = SetSize(mnSize);
                }
                if (good) {
                    ft->Fn0089801e(reinterpret_cast<uint8_t*>(this) + 0x20, 1);
                    uint32_t bits = mnStyle & 0x3c;
                    mnStyle = ft->Fn0089883f() | bits;
                    uint8_t* face = static_cast<uint8_t*>(ft->mpC);
                    field34 = (FONT_AT_AC55D8(uint32_t, face, 0x5c) != 0) + 1;
                    uint32_t idx = Fn0089f4b2(ft->mpC, FONT_AT_AC55D8(uint16_t, this, 0xe4), &err) & 0xffff;
                    FONT_AT_AC55D8(uint32_t, this, 0xe8) = idx;
                    if (err != 0) {
                        FONT_AT_AC55D8(uint32_t, this, 0xe8) = 0;
                    }
                    mbReady = FONT_AT_AC55D8(uint32_t, this, 0x24) != FONT_AT_AC55D8(uint32_t, this, 0x28);
                }
            }
        }
        if (mbReady) {
            if (mpRenderer == 0) {
                void* mem = ::operator new(8);
                Smoothing_ac55d8* made = 0;
                if (mem != 0) {
                    made = static_cast<Smoothing_ac55d8*>(mem)->Fn00897722();
                }
                mpRenderer = made;
            }
            {
                static_cast<Smoothing_ac55d8*>(mpRenderer)->AddRef();
            }
            Fn008993bb();
        }
    }
    return mbReady != 0;
}
#endif

struct ByteVec_ac55d8 {
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    // STUB: 0x004610a0
    void Fn004610a0(uint32_t n, const uint8_t* fill);
    // STUB: 0x0040e490
    void Fn0040e490(uint8_t* begin, uint8_t* end);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008993bb score 24
void cGZFont::Fn008993bb()
{
    ByteVec_ac55d8* table = reinterpret_cast<ByteVec_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x5c);
    if (mfGamma == 1.0f && mfSharpness == 0.0f) {
        table->Fn0040e490(table->mpBegin, table->mpEnd);
        reinterpret_cast<GlyphCache_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x130)->Fn008982ba();
        return;
    }
    uint8_t zero = 0;
    table->Fn004610a0(0x100, &zero);
    reinterpret_cast<GlyphCache_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x130)->Fn008982ba();
    float p = static_cast<float>(pow(mfSharpness + 0.5, 0.5 / log10(0.5)));
    for (int32_t i = 0; i <= 0xff; i++) {
        float t = static_cast<float>(i) * 0.003921569f;
        if (mfGamma != 1.0f) {
            t = Fn004c37a0(t, mfGamma);
        }
        if (mfSharpness != 0.0f) {
            if (t > 1.0f) {
                t = 1.0f;
            }
            if (i <= 0x7f) {
                t = Fn004c37a0(t + t, p) * 0.5f;
            } else {
                t = 1.0f - Fn004c37a0((1.0f - t) + (1.0f - t), p) * 0.5f;
            }
        }
        table->mpBegin[i] = static_cast<uint8_t>(static_cast<int32_t>(t * 255.0f));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00899d81 score 188
uint32_t cGZFont::CalculateWordsToFitInWidth(const void* text, uint32_t n, uint32_t width, uint32_t outWidth, uint32_t mode)
{
    uint32_t* outW = OB_PTR(uint32_t, outWidth);
    uint32_t consumed = 0;
    if (width == 0 || n == 0) {
        if (outW != 0) {
            *outW = 0;
        }
        return 0;
    }
    uint16_t* uni;
    uint32_t len = n;
    GetTextAsUnicode(text, n, &uni, &len, 2, true);
    uint32_t saved = mnCodePage;
    mnCodePage = 0x10;
    uint32_t acc = 0;
    uint32_t tmp = 0;
    const uint16_t* p = uni;
    while (consumed < len) {
        if (*p == 0xa || *p == 0xd) {
            consumed++;
            break;
        }
        uint32_t k = Fn0091227b(p, len - consumed);
        uint32_t vis = GetStringVisibleWidth(p, k, &tmp);
        if (vis + acc > width) {
            break;
        }
        acc += GetStringWidth(p, k);
        consumed += k;
        p += k;
        if (vis > width) {
            break;
        }
    }
    if (consumed == 0) {
        if (mode == 1) {
            while (consumed < len) {
                uint16_t c = uni[consumed];
                if (c == 0 || c == 0xa || c == 0xd || Fn00896254(c)) {
                    break;
                }
                consumed += Fn0091227b(uni + consumed, len - consumed);
            }
            if (consumed > 1 && !Fn00896254(uni[consumed - 1]) && consumed < len && Fn00896254(uni[consumed])) {
                consumed++;
            }
        } else if (mode == 2) {
            if (width > consumed) {
                uint32_t start = 0;
                do {
                    start = consumed;
                    uint32_t k = 1;
                    if (Fn009100de(uni[consumed])) {
                        k = Fn00911cde(uni + consumed, len - consumed);
                    }
                    consumed += k;
                } while (static_cast<uint32_t>(GetStringWidth(uni, consumed)) < width);
                if (start > 0) {
                    consumed = start;
                }
            }
        }
    }
    mnCodePage = saved;
    uint32_t idx = consumed;
    uint32_t* map = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(this) + 0xd8);
    if (map != *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(this) + 0xdc)) {
        idx = map[consumed];
    }
    uint32_t r = Fn00910855(text, idx, saved);
    if (outW != 0) {
        *outW = GetStringWidth(text, r);
    }
    return r;
}
#endif

// ---- batch 5 (character classes) ----

// GLOBAL: 0x00ace910
extern uint16_t g00ace910[0x49];
// GLOBAL: 0x00ace8c8
extern uint16_t g00ace8c8[0x21];
// GLOBAL: 0x00ace7a8
extern uint16_t g00ace7a8[0x90];
// GLOBAL: 0x00ace774
extern uint16_t g00ace774[0x17];
// GLOBAL: 0x00ace760
extern uint16_t g00ace760[0xa];
// GLOBAL: 0x00b168dc
extern uint16_t g00b168dc[0xf];
// GLOBAL: 0x00b168c4
extern uint16_t g00b168c4[0xb];
// GLOBAL: 0x00b168b8
extern uint16_t g00b168b8[6];
// GLOBAL: 0x00b168a0
extern uint16_t g00b168a0[0xb];
// GLOBAL: 0x00b16890
extern uint16_t g00b16890[7];

inline bool InTable_ac55d8(const uint16_t* table, uint32_t count, uint32_t ch)
{
    for (uint32_t i = 0; i < count; i++) {
        if (table[i] == ch) {
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x0091009b
uint32_t Fn0091009b(uint32_t c)
{
    if (c >= 0x2e80 && c <= 0xe000) {
        return 1;
    }
    if (c >= 0xf900 && c <= 0xfaff) {
        return 1;
    }
    if (c >= 0xfe30 && c <= 0xfe4f) {
        return 1;
    }
    if (c >= 0xff10 && c <= 0xffee) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00910855
uint32_t Fn00910855Draft_ac55d8(const void* text, uint32_t count, int32_t codePage)
{
    uint32_t total = 0;
    if (codePage == -2) {
        codePage = 8;
    } else if (codePage == -1) {
        codePage = static_cast<int32_t>(Fn00910014());
    }
    const uint8_t* p = static_cast<const uint8_t*>(text);
    while (count != 0) {
        uint32_t unit = (codePage == 0x10) ? 2 : 1;
        int32_t size = Fn009106a9(p, 0x3fffffff, codePage);
        total += size;
        p += unit * size;
        count--;
    }
    return total;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00911b3e score 145
bool Fn00911b3e(uint32_t ch)
{
    if (ch < 0xe31 || ch > 0xe4e) {
        return false;
    }
    static const uint16_t marks[] = { 0xe38, 0xe39, 0xe3a, 0xe48, 0xe49, 0xe4a, 0xe4b, 0xe4c, 0xe4d, 0xe47, 0xe4e, 0xe34, 0xe31, 0xe36, 0xe35, 0xe37 };
    return InTable_ac55d8(marks, 16, ch);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00911cde score 43
uint32_t Fn00911cde(const uint16_t* text, uint32_t n)
{
    if (n < 1) {
        return 0;
    }
    if (n < 2) {
        return 1;
    }
    uint16_t c = text[1];
    if (c == 0xe33) {
        return 2;
    }
    if (!Fn00911b3e(c)) {
        return 1;
    }
    if (n < 3) {
        return 2;
    }
    c = text[2];
    if (c == 0xe33) {
        return 3;
    }
    if (!Fn00911b3e(c)) {
        return 2;
    }
    return 3 + (text[3] == 0xe33 ? 1 : 0);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00911d4a score 126
bool Fn00911d4a(uint32_t ch)
{
    return !(InTable_ac55d8(g00ace910, 0x49, ch) || InTable_ac55d8(g00ace8c8, 0x21, ch) || InTable_ac55d8(g00ace7a8, 0x90, ch)
        || InTable_ac55d8(g00ace774, 0x17, ch) || InTable_ac55d8(g00ace760, 0xa, ch));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00911e46 score 126
bool Fn00911e46(uint32_t ch)
{
    return !(InTable_ac55d8(g00b168dc, 0xf, ch) || InTable_ac55d8(g00b168c4, 0xb, ch) || InTable_ac55d8(g00b168b8, 6, ch)
        || InTable_ac55d8(g00b168a0, 0xb, ch) || InTable_ac55d8(g00b16890, 7, ch));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00911f42 score 75
bool Fn00911f42(uint32_t ch)
{
    return ch == 0xa || ch == 0xd || ch == 0x85 || ch == 0x2028 || ch == 0x2029;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00911ffe score 216
bool Fn00911ffe(uint32_t ch)
{
    static const uint32_t marks[] = { 0x82, 0x20, 0x2002, 0x2003, 0x2004, 0x2005, 0x2006, 0x2007, 0x2008, 0x2009, 0x200a, 0x200b, 0x3000, 0x2d,
        0x2010, 0x2012, 0x2013, 0x2014, 0x2015, 0x203e, 0x301c, 0xfe31, 0xfe32, 0xfe58 };
    for (uint32_t i = 0; i < 24; i++) {
        if (marks[i] == ch) {
            return true;
        }
    }
    uint16_t c = static_cast<uint16_t>(ch);
    return c <= 0x20 && c != 0xa && c != 0xd;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0091227b score 120
uint32_t Fn0091227b(const uint16_t* text, uint32_t n)
{
    uint32_t len = 0;
    if (n == 0) {
        return 0;
    }
    const uint16_t* p = text;
    const uint16_t* end = text + n;
    uint32_t ch = *p++;
    len = 1;
    bool prevB;
    bool prevC;
    bool prevD;
    bool prevE;
    Fn00911d4a(ch);
    prevB = Fn00911e46(ch);
    prevC = Fn00911f42(ch);
    prevD = Fn00911ffe(ch);
    prevE = Fn0091009b(ch) != 0;
    while (p < end) {
        if (ch == 0xe46) {
            break;
        }
        ch = *p++;
        bool a = Fn00911d4a(ch);
        bool b = Fn00911e46(ch);
        bool c = Fn00911f42(ch);
        bool d = Fn00911ffe(ch);
        bool e = Fn0091009b(ch) != 0;
        if (prevC || c) {
            break;
        }
        if (a && prevB) {
            if (prevE || e) {
                break;
            }
            if (prevD && !d) {
                break;
            }
        }
        len++;
        prevB = b;
        prevC = false;
        prevD = d;
        prevE = e;
    }
    return len;
}
#endif

// ---- batch 6 (the font file library glue) ----

// STUB: 0x009f24d8
int32_t Fn009f24d8(void* jumpBuffer, int32_t value);
// STUB: 0x0089a632
void Fn0089a632(void* memory);
// STUB: 0x0089d5d9
uint32_t Fn0089d5d9(void* size, uint32_t arg);
// STUB: 0x0089c7ec
uint32_t Fn0089c7ec(void* size, const void* name);
// STUB: 0x008a1bd8
uint32_t OB_STDCALL Fn008a1bd8(void* data);
// STUB: 0x0089a670
void* Fn0089a670(void* memory, uint32_t size);
// STUB: 0x0089e1f5
void Fn0089e1f5(void* object, uint32_t arg);

// Two views of the library objects the helpers walk: +4 is the memory object whose +0x10 holds the jump buffer.
#define FT_MEM_AC55D8(obj) (reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(static_cast<uint8_t*>(obj) + 4)) + 0x10)

#ifdef OB_DRAFTS
// CLOSE: 0x0089e29e score 21
void Fn0089e29e(void* object, uint32_t arg, uint32_t* err)
{
    *err = Fn009f24d8(FT_MEM_AC55D8(object), 0);
    if (*err == 0) {
        Fn0089e1f5(object, arg);
    } else {
        Fn0089a632(*reinterpret_cast<void**>(static_cast<uint8_t*>(object) + 4));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089f4b2 score 26
uint32_t Fn0089f4b2(void* face, uint32_t glyph, uint32_t* err)
{
    uint8_t* f = static_cast<uint8_t*>(face);
    *err = Fn009f24d8(FT_MEM_AC55D8(face), 0);
    if (*err == 0) {
        return Fn0089d5d9(*reinterpret_cast<void**>(f + 0x180), glyph);
    }
    Fn0089a632(*reinterpret_cast<void**>(f + 4));
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089f4f3 score 29
uint32_t Fn0089f4f3(void* face, const void* name, uint32_t* err)
{
    uint8_t* f = static_cast<uint8_t*>(face);
    *err = Fn009f24d8(FT_MEM_AC55D8(face), 0);
    if (*err == 0) {
        return Fn0089c7ec(*reinterpret_cast<void**>(f + 0x180), name) & 0xffff;
    }
    Fn0089a632(*reinterpret_cast<void**>(f + 4));
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089f538 score 65
uint32_t Fn0089f538Draft_ac55d8(void* face, uint32_t code, uint32_t flags, uint32_t* err)
{
    uint8_t* f = static_cast<uint8_t*>(face);
    uint32_t r = 1;
    *err = 0;
    if (flags & 8) {
        return 1;
    }
    *err = Fn009f24d8(FT_MEM_AC55D8(face), 0);
    if (*err == 0) {
        uint8_t* size = *reinterpret_cast<uint8_t**>(f + 0x180);
        if (static_cast<uint16_t>(Fn0089d5d9(size, code)) == 0) {
            uint8_t* sub = *reinterpret_cast<uint8_t**>(size + 0x20);
            r = 0;
            if (sub != 0) {
                r = *reinterpret_cast<uint32_t*>(sub + 0x220);
            }
        }
    } else {
        Fn0089a632(*reinterpret_cast<void**>(f + 4));
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008a1c10 score 25
uint32_t Fn008a1c10(void* object, uint32_t* err)
{
    uint8_t* o = static_cast<uint8_t*>(object);
    *err = Fn009f24d8(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(o + 0x22c)) + 0x10, 0);
    if (*err == 0) {
        return Fn008a1bd8(object) & 0xffff;
    }
    Fn0089a632(*reinterpret_cast<void**>(o + 0x22c));
    return *err & 0xffff;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089f7c6 score 77
void Fn0089f7c6(uint8_t* data, uint32_t* n, uint32_t* err)
{
    *err = 0x2729;
    uint8_t* src = data;
    uint8_t* dst = data;
    if (*n != 0) {
        do {
            if (src[0] != 0x80) {
                return;
            }
            if (src[1] == 3) {
                break;
            }
            uint32_t len = (static_cast<uint32_t>(src[5]) << 24) | (static_cast<uint32_t>(src[4]) << 16) | (static_cast<uint32_t>(src[3]) << 8) | src[2];
            src += 6;
            if (len > *n) {
                return;
            }
            while (len != 0) {
                *dst++ = *src++;
                len--;
            }
        } while (static_cast<uint32_t>(src - data) < *n);
    }
    *err = 0;
    *n = static_cast<uint32_t>(dst - data);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089ac7e score 61
void* Fn0089ac7e(void* library, uint8_t* data, uint32_t size, uint32_t* err)
{
    if (err != 0) {
        *err = Fn009f24d8(static_cast<uint8_t*>(library) + 0x10, 0);
        if (*err != 0) {
            Fn0089a632(library);
            return 0;
        }
    }
    uint8_t* obj = static_cast<uint8_t*>(Fn0089a670(library, 0x23c));
    *reinterpret_cast<uint8_t**>(obj) = data;
    *reinterpret_cast<void**>(obj + 0x22c) = library;
    *reinterpret_cast<uint32_t*>(obj + 4) = 0;
    *reinterpret_cast<uint32_t*>(obj + 8) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x214) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x218) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x21c) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x224) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x220) = size;
    *reinterpret_cast<uint32_t*>(obj + 0x230) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x234) = 0;
    obj[0x228] = 3;
    obj[0x238] = 0;
    return obj;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089ad13 score 58
void* Fn0089ad13(void* library, void* file, void (*callback)(), uint32_t size, uint32_t* err)
{
    if (err != 0) {
        *err = Fn009f24d8(static_cast<uint8_t*>(library) + 0x10, 0);
        if (*err != 0) {
            Fn0089a632(library);
            return 0;
        }
    }
    uint8_t* obj = static_cast<uint8_t*>(Fn0089a670(library, 0x23c));
    *reinterpret_cast<void**>(obj + 4) = reinterpret_cast<void*>(callback);
    *reinterpret_cast<void**>(obj + 8) = file;
    *reinterpret_cast<void**>(obj + 0x22c) = library;
    *reinterpret_cast<uint32_t*>(obj) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x214) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x218) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x21c) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x224) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x220) = size;
    *reinterpret_cast<uint32_t*>(obj + 0x230) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x234) = 0;
    obj[0x228] = 4;
    obj[0x238] = 0;
    return obj;
}
#endif

// ---- batch 7 ----

// A string object (cRZString): text begin/end at +4/+8, Find is slot 26 (+0x68).
struct RZStr_ac55d8 {
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
    virtual int32_t Find(const char* text, int32_t from, int32_t flags);
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    // STUB: 0x004425c0
    void Fn004425c0(int32_t pos, int32_t count);
    // STUB: 0x0090e8a6
    void Fn0090e8a6();
};

// STUB: 0x0089f353
void Fn0089f353(void* face, uint32_t language, uint32_t kind, uint32_t* err);
// STUB: 0x00911358
uint32_t Fn00911358(const void* text, uint32_t count, uint32_t encoding, void* out);
// STUB: 0x0079ca50
void Fn0079ca50(void* result, const void* source, const uint8_t* alloc);
// STUB: 0x00408000
void Fn00408000(void* result, const void* source, const uint8_t* alloc);

#ifdef OB_DRAFTS
// CLOSE: 0x0089801e score 262
bool FtFont_ac55d8::Fn0089801e(void* nameOut, uint32_t mode)
{
    RZStr_ac55d8* out = static_cast<RZStr_ac55d8*>(nameOut);
    uint8_t* face = static_cast<uint8_t*>(mpC);
    if (face != 0) {
        bool bold = mode == 1;
        bool italic = mode == 2;
        uint32_t err = 0;
        Fn0089f353(face, 0x409, mode, &err);
        static const uint32_t langs[4] = { 0x409, 0, 0x409, 0 };
        for (uint32_t step = 0; step < 7; step++) {
            uint32_t lang = langs[(step + 1) >> 1];
            uint32_t kind = step < 2 ? mode : (step < 3 ? mode : 4);
            face = static_cast<uint8_t*>(mpC);
            if ((step & 1) == 0) {
                if (*reinterpret_cast<uint32_t*>(face + 0x54) == 0 && *reinterpret_cast<uint32_t*>(face + 0x50) == 0) {
                    Fn0089f353(face, lang, kind, &err);
                }
            } else {
                if (*reinterpret_cast<uint32_t*>(face + 0x54) == 0 && *reinterpret_cast<uint32_t*>(face + 0x50) == 0) {
                    uint8_t* size = *reinterpret_cast<uint8_t**>(face + 0x180);
                    *reinterpret_cast<uint16_t*>(size + 0x76) = 0;
                    Fn0089f353(face, lang, kind, &err);
                    size = *reinterpret_cast<uint8_t**>(static_cast<uint8_t*>(mpC) + 0x180);
                    *reinterpret_cast<uint16_t*>(size + 0x76) = 1;
                }
            }
        }
        face = static_cast<uint8_t*>(mpC);
        uint8_t alloc;
        void* wide = *reinterpret_cast<void**>(face + 0x54);
        if (wide != 0) {
            uint32_t tmp[4];
            Fn0079ca50(tmp, wide, &alloc);
            uint16_t* b = reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(tmp[0]));
            Fn00911358(b, 0, 0x10, out);
        } else if (*reinterpret_cast<void**>(face + 0x50) != 0) {
            uint32_t tmp[4];
            Fn00408000(tmp, *reinterpret_cast<void**>(face + 0x50), &alloc);
            Fn00911358(&tmp, 0, 0x4e4, out);
        } else if (out->mpBegin != out->mpEnd) {
            *out->mpBegin = 0;
            out->mpEnd = out->mpBegin;
        }
        if (bold || italic) {
            int32_t a = out->Find("italic", -1, 0);
            int32_t b = out->Find("bold", -1, 0);
            if (bold) {
                if (a != -1) {
                    out->Fn004425c0(a, -1);
                }
                if (b != -1) {
                    out->Fn004425c0(b, -1);
                }
            } else if (italic) {
                int32_t pos = b < a ? b : a;
                if (pos != -1) {
                    out->Fn004425c0(0, pos);
                }
            }
            out->Fn0090e8a6();
        }
    }
    return static_cast<RZStr_ac55d8*>(nameOut)->mpBegin != static_cast<RZStr_ac55d8*>(nameOut)->mpEnd;
}
#endif

struct StringBuf_ac55d8 {
    uint8_t mBytes[0x14];
    // STUB: 0x00578390
    void Fn00578390();
    // STUB: 0x00442850
    int32_t Fn00442850(const char* text, int32_t from);
    // STUB: 0x0090eac5
    void MakeLower();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0089883f score 32
uint32_t FtFont_ac55d8::Fn0089883f()
{
    uint32_t flags = 0;
    uint8_t* face = static_cast<uint8_t*>(mpC);
    if (face != 0) {
        uint8_t* rec = *reinterpret_cast<uint8_t**>(face + 0x180);
        if (rec != 0) {
            uint8_t* info = *reinterpret_cast<uint8_t**>(rec + 0x3c);
            if (info != 0 && (*(info + 0x30) & 1)) {
                flags++;
            }
            if (rec != 0) {
                info = *reinterpret_cast<uint8_t**>(rec + 0x3c);
                if (info != 0 && (*(info + 0x30) & 2)) {
                    flags |= 2;
                }
            }
        }
        StringBuf_ac55d8 name;
        name.Fn00578390();
        Fn0089801e(&name, 2);
        uint8_t* begin = *reinterpret_cast<uint8_t**>(name.mBytes + 4);
        uint8_t* end = *reinterpret_cast<uint8_t**>(name.mBytes + 8);
        if (begin != end) {
            name.MakeLower();
            if (name.Fn00442850("bold", 0) != -1) {
                flags |= 2;
            }
            if (name.Fn00442850("italic", 0) != -1) {
                flags |= 1;
            }
        }
        if (*reinterpret_cast<uint8_t**>(name.mBytes + 4) != 0) {
            Fn0090cf63(*reinterpret_cast<uint8_t**>(name.mBytes + 4));
        }
    }
    return flags;
}
#endif

// A glyph cache record and one glyph's detail record, as CopyGlyphToSourceData uses them.
struct CacheRec_ac55d8 {
    uint32_t mnPad0;
    uint8_t* mpPixels;
    uint32_t mnWidthCap;
    uint32_t mnHeightCap;
    uint32_t mnPitch;
    uint32_t mnCursor;
};

struct GlyphDetail_ac55d8 {
    int32_t mnX;
    int32_t mnPad4;
    int32_t mnEnd;
    int32_t mnBottom;
    int16_t mnPad;
    int16_t mnAscentDelta;
    int16_t mnMinWidth;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00897748 score 101
bool cGZFont::CopyGlyphToSourceData(void* cacheArg, void* detailArg, uint32_t x, uint32_t y, const void* srcArg, uint32_t w, uint32_t h, uint32_t srcPitch, uint32_t mode)
{
    uint8_t* tmp = 0;
    CacheRec_ac55d8* cache = static_cast<CacheRec_ac55d8*>(cacheArg);
    GlyphDetail_ac55d8* detail = static_cast<GlyphDetail_ac55d8*>(detailArg);
    const uint8_t* src = static_cast<const uint8_t*>(srcArg);
    uint32_t gw = w;
    if (mnStyle & 0xc) {
        int16_t minW = detail->mnMinWidth;
        if (minW > 0) {
            gw = static_cast<uint32_t>(minW);
            if (w > gw) {
                gw = w;
            }
        }
        int16_t pad = static_cast<int16_t>(*reinterpret_cast<int16_t*>(reinterpret_cast<uint8_t*>(detail) + 0x10));
        if (pad > 0) {
            gw += pad;
            detail->mnX += pad;
            detail->mnEnd += pad;
            *reinterpret_cast<int16_t*>(reinterpret_cast<uint8_t*>(detail) + 0x10) = 0;
        }
    }
    uint32_t end = gw + x;
    cache->mnCursor = end;
    if (end >= cache->mnWidthCap) {
        uint32_t hh = cache->mnHeightCap;
        if (hh < static_cast<uint32_t>(mnHeight)) {
            hh = static_cast<uint32_t>(mnHeight);
        }
        ReallocateSourceData(cache, gw * 0x20 + x, hh);
    }
    if (y + h > cache->mnHeightCap) {
        ReallocateSourceData(cache, cache->mnWidthCap, y + h);
        if (cache->mnHeightCap < y) {
            h = 0;
        } else {
            h = cache->mnHeightCap - y;
        }
    }
    if (w != 0) {
        if (mode == 2) {
            tmp = static_cast<uint8_t*>(::operator new(w * h));
            uint8_t* d = tmp;
            uint32_t rowStart = 0;
            for (uint32_t r = 0; r < h; r++) {
                for (uint32_t i = 0; i < w; i++) {
                    d[i] = static_cast<uint8_t>(-((src[rowStart + (i >> 3)] & (0x80 >> (i & 7))) != 0));
                }
                rowStart += srcPitch;
                d += w;
            }
            src = tmp;
            srcPitch = w;
        }
        uint8_t* dst = cache->mpPixels + cache->mnPitch * y + detail->mnX;
        while (h != 0) {
            memcpy(dst, src, w);
            if (mnAntialiasing != 1 && FONT_AT_AC55D8(uint32_t, this, 0x5c) != FONT_AT_AC55D8(uint32_t, this, 0x60)) {
                for (uint8_t* p = dst; p < dst + w; p++) {
                    *p = reinterpret_cast<uint8_t*>(FONT_AT_AC55D8(uint32_t, this, 0x5c))[*p];
                }
            }
            dst += cache->mnPitch;
            src += srcPitch;
            h--;
        }
        ::operator delete(tmp);
    }
    uint32_t style = mnStyle;
    if (style & 4) {
        int32_t n = static_cast<int32_t>(Fn00896618());
        int32_t row = mnAscent - detail->mnAscentDelta + n;
        if (row >= 0 && static_cast<uint32_t>(row) < static_cast<uint32_t>(mnHeight)) {
            int32_t cnt = 0;
            if (n > 0) {
                uint32_t r = static_cast<uint32_t>(row);
                do {
                    if (r >= static_cast<uint32_t>(mnHeight)) {
                        break;
                    }
                    memset(cache->mpPixels + cache->mnPitch * r + x, 0xff, gw);
                    cnt++;
                    r++;
                } while (cnt < n);
            }
            if (detail->mnBottom < row + cnt) {
                detail->mnBottom = row + cnt;
            }
        }
    }
    if (mnStyle & 8) {
        int32_t n = static_cast<int32_t>(Fn00896636());
        int32_t row = mnAscent - static_cast<int32_t>(static_cast<uint32_t>(mnHeight) >> 2) - detail->mnAscentDelta;
        if (row >= 0 && static_cast<uint32_t>(row) < static_cast<uint32_t>(mnHeight)) {
            int32_t cnt = 0;
            if (n > 0) {
                uint32_t r = static_cast<uint32_t>(row);
                do {
                    if (r >= static_cast<uint32_t>(mnHeight)) {
                        break;
                    }
                    memset(cache->mpPixels + cache->mnPitch * r + x, 0xff, gw);
                    cnt++;
                    r++;
                } while (cnt < n);
            }
            if (detail->mnBottom < row + cnt) {
                detail->mnBottom = row + cnt;
            }
        }
    }
    detail->mnX = static_cast<int32_t>(x);
    if (x != 0) {
        detail->mnEnd = static_cast<int32_t>(end);
    }
    return true;
}
#endif

// STUB: 0x0089f23b
void Fn0089f23b(void* face, uint32_t glyph, uint32_t a, uint32_t b, uint32_t loadMode, uint32_t flags, uint32_t* err);

// A bordered box bitmap (all 0xff on the border, 0 inside): the missing-glyph picture.
#ifdef OB_DRAFTS
// CLOSE: 0x008962d7 score 33
inline uint8_t* Fn008962d7Draft_ac55d8(int32_t w, int32_t h)
{
    uint8_t* block = static_cast<uint8_t*>(::operator new(w * h));
    for (int32_t x = 0; x < w; x++) {
        for (int32_t y = 0; y < h; y++) {
            uint8_t* p = block + x + y * w;
            if (x != 0 && y != 0 && x != w - 1 && y != h - 1) {
                *p = 0;
            } else {
                *p = 0xff;
            }
        }
    }
    return block;
}
#endif

struct HashTableC_ac55d8 : HashTableB_ac55d8 {
};

struct Entry_ac55d8 {
    uint32_t mnCode;
    GlyphDetail_ac55d8 mDetail;
    int16_t mnPad;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00898fdc score 506
void* cGZFont::AddCharData(uint32_t code, void* cacheArg)
{
    FtFont_ac55d8* ft = static_cast<FtFont_ac55d8*>(mpFT);
    CacheRec_ac55d8* cache = static_cast<CacheRec_ac55d8*>(cacheArg);
    uint32_t err = 1;
    uint32_t glyph = 0;
    uint32_t mode = 0;
    bool empty = false;
    Entry_ac55d8 entry;
    uint8_t* face = ft != 0 ? static_cast<uint8_t*>(ft->mpC) : 0;
    if (ft != 0 && face != 0) {
        uint32_t type = ft->mnType;
        if (code < 0x80 || (type != 2 && type != 3)) {
            glyph = Fn0089f4b2(face, code, &err) & 0xffff;
            if (err != 0) {
                glyph = 0;
            }
        }
        if (glyph == 0) {
            if (code >= 0x20 && (type == 2 || type == 3)) {
                glyph = ft->Fn00898eb2(code);
            }
            if (glyph == 0) {
                glyph = FONT_AT_AC55D8(uint32_t, this, 0xe8);
            }
        }
        if (glyph != 0) {
            bool aa = mnAntialiasing != 1;
            mode = aa ? 0x100 : 2;
            Fn0089f23b(face, glyph, 0, 0, aa ? 3 : 0, *reinterpret_cast<uint16_t*>(&ft->mnFlagsLo), &err);
            if (err == 0) {
                uint8_t* f = static_cast<uint8_t*>(ft->mpC);
                if (FONT_AT_AC55D8(uint32_t, f, 0x118) == 0) {
                    empty = true;
                }
                entry.mnCode = code;
                entry.mDetail.mnX = static_cast<int32_t>(cache->mnCursor);
                entry.mDetail.mnPad4 = 0;
                int32_t bearingX = empty ? 0 : FONT_AT_AC55D8(int32_t, f, 0x10c);
                entry.mDetail.mnEnd = bearingX + static_cast<int32_t>(cache->mnCursor);
                entry.mDetail.mnBottom = empty ? 0 : FONT_AT_AC55D8(int32_t, f, 0x110);
                uint8_t* rec = reinterpret_cast<uint8_t*>(FONT_AT_AC55D8(uint32_t, ft->mpC, 0) /* unused */);
                (void)rec;
                uint8_t* sz = static_cast<uint8_t*>(*reinterpret_cast<void**>(static_cast<uint8_t*>(ft->mpC) + 0x180));
                (void)sz;
                entry.mDetail.mnPad = static_cast<int16_t>(FONT_AT_AC55D8(int32_t, f, 0xe4) / 0x40);
                entry.mDetail.mnAscentDelta = static_cast<int16_t>((FONT_AT_AC55D8(int32_t, f, 0x7c) + FONT_AT_AC55D8(int32_t, f, 0x6c)) / 0x10000 - FONT_AT_AC55D8(int32_t, f, 0xe0) / 0x40);
                uint32_t height = FONT_AT_AC55D8(uint32_t, f, 0x5c) != 0 ? FONT_AT_AC55D8(uint32_t, f, 0x80) : FONT_AT_AC55D8(uint32_t, f, 0xd0);
                if (mfAdvanceScale != 1.0f) {
                    entry.mDetail.mnMinWidth = static_cast<int16_t>(static_cast<int32_t>(static_cast<float>(height) * mfAdvanceScale * 0.015625f));
                } else {
                    entry.mDetail.mnMinWidth = static_cast<int16_t>(static_cast<int32_t>(static_cast<float>(height) * mfAdvanceScale * 0.015625f));
                }
                if (code == 0x200b || code == 0xfeff) {
                    entry.mDetail.mnMinWidth = 0;
                }
                if (empty) {
                    CopyGlyphToSourceData(cache, &entry.mDetail, 0, 0, 0, 0, 0, 0, 2);
                } else {
                    CopyGlyphToSourceData(cache, &entry.mDetail, cache->mnCursor, 0, 0, 0, 0, 0, mode);
                }
                uint8_t result[0x14];
                reinterpret_cast<HashTableB_ac55d8*>(reinterpret_cast<uint8_t*>(cache) + 0x18)->Fn008986bf(reinterpret_cast<HashResult_ac55d8*>(result), &entry.mnCode);
                void* r = GetCharData(code);
                uint32_t err2 = 0;
                Fn0089e29e(ft->mpC, 1, &err2);
                if (err2 == 0 && glyph != 0) {
                    return r;
                }
            }
        }
    }
    uint32_t half = static_cast<uint32_t>(mnHeight) >> 1;
    entry.mnCode = code;
    entry.mDetail.mnX = static_cast<int32_t>(cache->mnCursor);
    entry.mDetail.mnPad4 = 0;
    entry.mDetail.mnEnd = static_cast<int32_t>(cache->mnCursor + half);
    entry.mDetail.mnBottom = static_cast<int32_t>(half);
    entry.mDetail.mnPad = 0;
    entry.mDetail.mnAscentDelta = 0;
    int32_t boxW = static_cast<int32_t>(half);
    entry.mDetail.mnMinWidth = static_cast<int16_t>(static_cast<int32_t>(static_cast<float>(boxW) * mfAdvanceScale));
    if (code == 0x200b || code == 0xfeff) {
        entry.mDetail.mnMinWidth = 0;
        CopyGlyphToSourceData(cache, &entry.mDetail, cache->mnCursor, 0, 0, 0, 0, 0, 2);
    } else {
        uint8_t* bits = Fn008962d7Draft_ac55d8(boxW, boxW);
        CopyGlyphToSourceData(cache, &entry.mDetail, cache->mnCursor, 0, bits, boxW, boxW, boxW, 0x100);
        ::operator delete(bits);
    }
    uint8_t result[0x14];
    reinterpret_cast<HashTableB_ac55d8*>(reinterpret_cast<uint8_t*>(cache) + 0x18)->Fn008986bf(reinterpret_cast<HashResult_ac55d8*>(result), &entry.mnCode);
    return GetCharData(code);
}
#endif

// ---- batch 8 (drawing) ----

// The renderer as DrawTextLine calls it: lock, unlock, draw.
struct Renderer2_ac55d8 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual bool Lock(cGZFont* font, void* surface, uint32_t mode);
    virtual void Unlock(cGZFont* font, void* surface, uint32_t mode);
    virtual void Draw(cGZFont* font, void* surface, void* glyphs, uint32_t count, uint32_t mode, const void* color, const void* clip);
};

struct GlyphDraw_ac55d8 {
    int32_t mnX1;
    int32_t mnY1;
    int32_t mnX2;
    int32_t mnY2;
    uint8_t* mpSource;
    uint32_t mnPitch;
    uint32_t mnWidth;
    uint32_t mnHeight;
    uint32_t mnChar;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0089a099 score 201
bool cGZFont::DrawTextLine(void* surface, int32_t x, int32_t y, const void* text, uint32_t len, uint32_t color, uint32_t back, const void* clipv, void* pointv)
{
    bool ready = mbReady != 0;
    const int32_t* clip = static_cast<const int32_t*>(clipv);
    int32_t* point = static_cast<int32_t*>(pointv);
    if (ready && len != 0) {
        uint16_t* uni;
        GetTextAsUnicodeDraft_ac55d8(this, text, len, &uni, &len, 1, false);
        int32_t curX = x;
        int32_t curY = y;
        uint32_t style = mnAntialiasing;
        CacheRec_ac55d8* cache = static_cast<CacheRec_ac55d8*>(GetAppropriateCachedBitmapData());
        if (style == 2) {
            if (back == 0x8000000 && FONT_AT_AC55D8(uint32_t, this, 0x50) == 2) {
                style = 2;
                back = (color != 0) - 1;
            }
            SetCurrentPalette(color, back);
        }
        if (color == 0x8000000) {
            color = mnFontColor;
        }
        bool locked = false;
        Renderer2_ac55d8* renderer = static_cast<Renderer2_ac55d8*>(mpRenderer);
        if (surface != 0 && mnLockCount == 0) {
            if (!renderer->Lock(this, surface, Fn00896b2c(style))) {
                return false;
            }
            mnLockCount++;
            locked = true;
        }
        if (point != 0) {
            curX = point[0];
            curY = point[1];
        }
        Vec36_ac55d8* vec = reinterpret_cast<Vec36_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0xf0);
        if (static_cast<uint32_t>((vec->mpEnd - vec->mpBegin) / 0x24) < len) {
            vec->Fn00899a73(len);
        }
        GlyphDraw_ac55d8* base = reinterpret_cast<GlyphDraw_ac55d8*>(vec->mpBegin);
        uint32_t i = 0;
        for (i = 0; i < len; i++) {
            GetCharData(uni[i]);
        }
        uint32_t count = 0;
        GlyphDraw_ac55d8* rec = base;
        for (i = 0; i < len; i++) {
            uint32_t ch = uni[i];
            Glyph_ac55d8* g = static_cast<Glyph_ac55d8*>(GetCharData(ch));
            if (g == 0) {
                ch = FONT_AT_AC55D8(uint32_t, this, 0xe4);
                g = static_cast<Glyph_ac55d8*>(GetCharData(ch));
                if (g == 0) {
                    continue;
                }
            }
            int32_t h = g->mnBottom - g->mnTop;
            int32_t w = g->mnRight - g->mnLeft;
            rec->mnX1 = g->mnXOffset + curX;
            rec->mnY1 = g->mnPad12 + mnSpacingY + curY;
            rec->mnX2 = rec->mnX1 + w;
            rec->mnY2 = rec->mnY1 + h;
            if ((clip == 0 || (rec->mnX1 < clip[2] && rec->mnY1 < clip[3] && rec->mnX2 > clip[0] && rec->mnY2 > clip[1])) && w != 0 && h != 0) {
                rec->mpSource = cache->mpPixels + cache->mnPitch * g->mnTop + g->mnLeft;
                rec->mnPitch = cache->mnPitch;
                rec->mnWidth = w;
                rec->mnHeight = h;
                rec->mnChar = ch;
                rec++;
                curX += g->mnAdvance + mnSpacingX;
                count++;
            } else {
                curX += g->mnAdvance + mnSpacingX;
            }
        }
        if (surface != 0 && count != 0) {
            const void* colorPtr = style == 2 ? reinterpret_cast<const void*>(&FONT_AT_AC55D8(uint32_t, this, 0xfc)) : &color;
            renderer->Draw(this, surface, base, count, Fn00896b2c(style), colorPtr, clip);
        }
        if (point != 0) {
            point[0] = curX;
            point[1] = curY;
        }
        if (locked) {
            renderer->Unlock(this, surface, Fn00896b2c(style));
            mnLockCount--;
        }
    }
    return ready;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089a35b score 156
bool cGZFont::DrawTextParagraph(void* surface, const void* rectv, const void* textv, uint32_t len, int32_t align, uint32_t color, uint32_t back, const void* clip, void* pointv)
{
    bool ready = mbReady != 0;
    const int32_t* rect = static_cast<const int32_t*>(rectv);
    const uint16_t* text;
    int32_t* point = static_cast<int32_t*>(pointv);
    if (ready && len != 0) {
        uint16_t* uni;
        uint32_t n = len;
        GetTextAsUnicodeDraft_ac55d8(this, textv, len, &uni, &n, 0, false);
        text = uni;
        uint32_t savedPage = mnCodePage;
        mnCodePage = 0x10;
        bool locked = false;
        Renderer2_ac55d8* renderer = static_cast<Renderer2_ac55d8*>(mpRenderer);
        if (surface != 0 && mnLockCount == 0) {
            if (!renderer->Lock(this, surface, Fn00896b2c(mnAntialiasing))) {
                mnCodePage = savedPage;
                return false;
            }
            mnLockCount++;
            locked = true;
        }
        int32_t y = rect[1];
        int32_t x = rect[0];
        int32_t lineHeight = static_cast<int32_t>(GetLineHeight());
        int32_t* result = 0;
        int32_t width = rect[2] - rect[0];
        int32_t out[2];
        const uint16_t* end = text + n;
        if (width > 0) {
            if (point != 0 && point[0] != rect[0]) {
                x = point[0];
            }
            while (y < rect[3] && text < end) {
                int32_t lineLen = static_cast<int32_t>(CalculateWordsToFitInWidth(text, n, width, 0, 2));
                if (align == 1) {
                    x = (width / 2) - GetStringWidth(text, lineLen) / 2 + rect[0];
                } else if (align == 2) {
                    x = rect[2] - GetStringWidth(text, lineLen);
                } else if (align == 0) {
                    x = rect[0];
                }
                if (point != 0) {
                    out[1] = y;
                    out[0] = x;
                    result = out;
                }
                if (surface != 0) {
                    int32_t trimmed = lineLen;
                    while (trimmed > 0 && (text[trimmed - 1] == 10 || text[trimmed - 1] == 13)) {
                        trimmed--;
                    }
                    if (trimmed != 0) {
                        DrawTextLine(surface, x, y, text, trimmed, color, back, clip, result);
                    }
                }
                n -= lineLen;
                text += lineLen;
                y += lineHeight;
            }
            if (point != 0) {
                point[0] = out[0];
                point[1] = out[1];
            }
        }
        if (locked) {
            renderer->Unlock(this, surface, Fn00896b2c(mnAntialiasing));
            mnLockCount--;
        }
        mnCodePage = savedPage;
    }
    return ready;
}
#endif

// The graphics server (RZ::GS): colour packing and unpacking through its slots 0x8c / 0x90.
struct GraphicsServer_ac55d8 {
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
    virtual void Pack(uint32_t* out, uint32_t r, uint32_t g, uint32_t b);
    virtual void Unpack(uint32_t color, uint8_t* a, uint8_t* b, uint8_t* c);
};

// STUB: 0x00913c1a
GraphicsServer_ac55d8* Fn00913c1a();
// STUB: 0x00910003
void Fn00910003(void* dst, uint32_t value, uint32_t count);
// STUB: 0x009d74d9
void Fn009d74d9(void* list, void* value);
// STUB: 0x00949259
void Fn00949259(void* list, const uint32_t* key, void* node);

#ifdef OB_DRAFTS
// CLOSE: 0x0089838c score 194
void cGZFont::SetCurrentPalette(uint32_t fg, uint32_t bg)
{
    uint8_t* cur = reinterpret_cast<uint8_t*>(FONT_AT_AC55D8(uint32_t*, this, 0xfc));
    if (cur != 0 && *reinterpret_cast<uint32_t*>(cur + 0x1fc) == fg && *reinterpret_cast<uint32_t*>(cur) == bg) {
        return;
    }
    ListHead_ac55d8* list = reinterpret_cast<ListHead_ac55d8*>(reinterpret_cast<uint8_t*>(this) + 0x100);
    ListNode_ac55d8* head = list->mpHead;
    for (ListNode_ac55d8* node = head->mpNext; node != head; node = node->mpNext) {
        uint8_t* p = static_cast<uint8_t*>(node->mpData);
        if (*reinterpret_cast<uint32_t*>(p + 0x1fc) == fg && *reinterpret_cast<uint32_t*>(p) == bg) {
            if (node != head->mpNext) {
                Fn00949259(list, &fg, node);
                Fn009d74d9(list, &node);
            }
            FONT_AT_AC55D8(void*, this, 0xfc) = p;
            return;
        }
    }
    uint8_t* buf = static_cast<uint8_t*>(::operator new(0x200));
    FONT_AT_AC55D8(void*, this, 0xfc) = buf;
    memset(buf, 0, 0x200);
    GraphicsServer_ac55d8* gs = Fn00913c1a();
    uint8_t fgC[3];
    uint8_t bgC[3];
    gs->Unpack(fg & 0xffff, &fgC[0], &fgC[1], &fgC[2]);
    gs->Unpack(bg & 0xffff, &bgC[0], &bgC[1], &bgC[2]);
    for (uint32_t off = 0; off < 0x20; off += 4) {
        *reinterpret_cast<uint32_t*>(buf + off) = bg;
    }
    int32_t i = 0;
    uint32_t off = 0x20;
    for (int32_t k = 0; k < 15; k++) {
        uint32_t color;
        gs->Pack(&color, (fgC[0] - bgC[0]) * i / 16 + bgC[0], (fgC[1] - bgC[1]) * i / 16 + bgC[1], (fgC[2] - bgC[2]) * i / 16 + bgC[2]);
        Fn00910003(buf + off, color, 8);
        off += 0x20;
        i++;
    }
    for (uint32_t o = 0x1e0; o < 0x200; o += 4) {
        *reinterpret_cast<uint32_t*>(buf + o) = fg;
    }
    uint32_t count = 0;
    for (ListNode_ac55d8* node = list->mpHead->mpNext; node != list->mpHead; node = node->mpNext) {
        count++;
    }
    if (count >= 4) {
        Fn00949259(list, &fg, list->mpHead->mpPrev);
    }
    Fn009d74d9(list, &FONT_AT_AC55D8(void*, this, 0xfc));
}
#endif

// ---- batch 9 (font file library objects) ----

// STUB: 0x0089a578
void Fn0089a578(void* memory, uint32_t code);
// STUB: 0x0089a7c6
void Fn0089a7c6(void* memory, void* block);
// STUB: 0x0089a878
void Fn0089a878(void* memory);
// STUB: 0x0089b530
void Fn0089b530();
// STUB: 0x0089b2b6
void Fn0089b2b6(void* p);
// STUB: 0x0089b497
void Fn0089b497(void* p);
// STUB: 0x008a18f7
void Fn008a18f7(void* p);
// STUB: 0x008a7af6
void Fn008a7af6(void* p);
// STUB: 0x008a7f84
void Fn008a7f84(void* p);
// STUB: 0x008a7545
void Fn008a7545(void* p);
// STUB: 0x008a4792
void Fn008a4792(void* p);
// STUB: 0x0089c808
void Fn0089c808();
// STUB: 0x0089cf9e
uint32_t Fn0089cf9e(void* obj, void* a, void* b);
// STUB: 0x0089ab40
uint32_t Fn0089ab40(void* a);
// STUB: 0x008a1834
void* Fn008a1834(void* a, void* b, uint32_t c);
// STUB: 0x0089c1ff
uint32_t Fn0089c1ff(void* obj);
// STUB: 0x008a3343
uint32_t Fn008a3343(void* a, uint32_t b);
// STUB: 0x0089c567
uint32_t Fn0089c567(void* obj);

#ifdef OB_DRAFTS
// CLOSE: 0x0089f3e6 score 59
void Fn0089f3e6(void* faceArg, void* errArg)
{
    uint8_t* face = static_cast<uint8_t*>(faceArg);
    uint32_t* err = static_cast<uint32_t*>(errArg);
    *err = Fn009f24d8(FT_MEM_AC55D8(face), 0);
    if (*err == 0) {
        void* mem = *reinterpret_cast<void**>(face + 4);
        if (*reinterpret_cast<uint32_t*>(face) != 0x5a1234a5 || *reinterpret_cast<uint32_t*>(face + 0x188) != 0xa5fedc5a) {
            Fn0089a578(mem, 0x2717);
        }
        Fn0089e1f5(face, 2);
        uint8_t* size = *reinterpret_cast<uint8_t**>(face + 0x180);
        Fn0089a7c6(mem, *reinterpret_cast<void**>(size + 0x8c));
        *reinterpret_cast<uint32_t*>(size + 0x8c) = 0;
        Fn0089a7c6(mem, *reinterpret_cast<void**>(face + 0x50));
        Fn0089a7c6(mem, *reinterpret_cast<void**>(face + 0x54));
        uint8_t* extra = *reinterpret_cast<uint8_t**>(face + 0x18);
        if (extra != 0) {
            Fn0089a7c6(mem, *reinterpret_cast<void**>(extra + 0x10));
            Fn0089a7c6(mem, *reinterpret_cast<void**>(extra));
        }
        Fn0089a878(mem);
        Fn0089a7c6(mem, face);
    } else {
        Fn0089a632(*reinterpret_cast<void**>(face + 4));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089cabe score 78
void Fn0089cabe(void* objArg, void* errArg)
{
    uint8_t* obj = static_cast<uint8_t*>(objArg);
    uint32_t* err = static_cast<uint32_t*>(errArg);
    if (err != 0) {
        *err = Fn009f24d8(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(obj + 0xc8)) + 0x10, 0);
        if (*err != 0) {
            Fn0089a632(*reinterpret_cast<void**>(obj + 0xc8));
            return;
        }
    }
    void* mem = *reinterpret_cast<void**>(obj + 0xc8);
    Fn0089b530();
    Fn0089b2b6(*reinterpret_cast<void**>(obj));
    void* p = *reinterpret_cast<void**>(obj + 0x3c);
    if (p != 0) {
        Fn0089a7c6(mem, *reinterpret_cast<void**>(p));
    }
    p = *reinterpret_cast<void**>(obj + 0x4c);
    if (p != 0) {
        Fn0089a7c6(mem, *reinterpret_cast<void**>(p));
    }
    p = *reinterpret_cast<void**>(obj + 0x50);
    if (p != 0) {
        Fn0089a7c6(mem, *reinterpret_cast<void**>(p));
    }
    Fn0089b497(*reinterpret_cast<void**>(obj + 0x54));
    Fn0089b497(*reinterpret_cast<void**>(obj + 0x58));
    p = *reinterpret_cast<void**>(obj + 0x40);
    if (p != 0) {
        Fn0089a7c6(mem, *reinterpret_cast<void**>(p));
    }
    Fn008a18f7(*reinterpret_cast<void**>(obj + 0x20));
    Fn008a7af6(*reinterpret_cast<void**>(obj + 0x24));
    Fn008a7f84(*reinterpret_cast<void**>(obj + 0x28));
    Fn008a7545(*reinterpret_cast<void**>(obj + 0x30));
    Fn008a4792(*reinterpret_cast<void**>(obj + 0x34));
    Fn0089a7c6(mem, *reinterpret_cast<void**>(obj + 0x14));
    Fn0089a7c6(mem, obj);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089d8dc score 38
void* Fn0089d8dc(void* library, void* size, uint32_t* err)
{
    if (library == 0) {
        *err = 0x2710;
        return 0;
    }
    *err = Fn009f24d8(static_cast<uint8_t*>(library) + 0x10, 0);
    if (*err != 0) {
        Fn0089a632(library);
        return 0;
    }
    uint8_t* face = static_cast<uint8_t*>(Fn0089a670(library, 0x18c));
    uint8_t* sz = static_cast<uint8_t*>(size);
    *reinterpret_cast<void**>(face + 4) = library;
    *reinterpret_cast<uint32_t*>(face) = 0x5a1234a5;
    *reinterpret_cast<void**>(face + 0x180) = size;
    *reinterpret_cast<uint32_t*>(face + 0x16c) = 0xffffffff;
    *reinterpret_cast<uint32_t*>(face + 0x168) = 0xffffffff;
    *reinterpret_cast<uint32_t*>(face + 0x58) = *reinterpret_cast<uint32_t*>(sz + 0xd4);
    *reinterpret_cast<uint32_t*>(face + 0x188) = 0xa5fedc5a;
    *reinterpret_cast<uint32_t*>(face + 0x104) = 0;
    *reinterpret_cast<uint16_t*>(face + 0x108) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x184) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x118) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x11c) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x30) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x34) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x50) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x54) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x20) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x24) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x38) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x3c) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x40) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x44) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x48) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x4c) = 0;
    *reinterpret_cast<uint32_t*>(face + 0x5c) = *reinterpret_cast<uint32_t*>(sz + 0x7c);
    *reinterpret_cast<uint16_t*>(face + 0x60) = *reinterpret_cast<uint16_t*>(sz + 0x80);
    *reinterpret_cast<uint16_t*>(face + 0x62) = *reinterpret_cast<uint16_t*>(sz + 0x82);
    *reinterpret_cast<uint16_t*>(sz + 0x74) = 0xffff;
    *reinterpret_cast<uint16_t*>(*reinterpret_cast<uint8_t**>(face + 0x180) + 0x76) = 0xffff;
    *reinterpret_cast<uint32_t*>(face + 0x18) = 0;
    return face;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089d662 score 181
void* Fn0089d662(void* library, uint32_t kind, uint32_t a, void* data, uint32_t b, uint32_t c, uint32_t* err)
{
    if (err == 0) {
        return 0;
    }
    *err = Fn009f24d8(static_cast<uint8_t*>(library) + 0x10, 0);
    if (*err != 0) {
        Fn0089a632(library);
        return 0;
    }
    uint8_t* obj = static_cast<uint8_t*>(Fn0089a670(library, 0xd8));
    *reinterpret_cast<void**>(obj + 0xbc) = data;
    *reinterpret_cast<uint32_t*>(obj + 0xc0) = b;
    *reinterpret_cast<void**>(obj + 0xc8) = library;
    *reinterpret_cast<uint32_t*>(obj + 0xc4) = 0;
    for (uint32_t off = 4; off <= 0x18; off += 4) {
        *reinterpret_cast<uint32_t*>(obj + off) = 0;
    }
    *reinterpret_cast<uint32_t*>(obj + 0xd4) = 1;
    *reinterpret_cast<uint32_t*>(obj) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x3c) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x4c) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x50) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x54) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x58) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x40) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x44) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x5c) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x60) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x48) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0xcc) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x24) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x28) = 0;
    *reinterpret_cast<uint16_t*>(obj + 0x1c) = 0;
    Fn0089c808();
    *reinterpret_cast<uint32_t*>(obj + 0x84) = 0xffffffff;
    *reinterpret_cast<uint32_t*>(obj + 0x88) = 0xffffffff;
    *reinterpret_cast<uint32_t*>(obj + 0x8c) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x20) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x30) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x34) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x38) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0xa8) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0xac) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0xb0) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x64) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x68) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x6c) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x70) = 0;
    if (static_cast<uint16_t>(kind) != 7 || Fn0089cf9e(obj, *reinterpret_cast<void**>(obj + 0xbc), data) != 0) {
        uint16_t k = static_cast<uint16_t>(kind);
        if (k == 2 || k == 5 || (k == 7 && *reinterpret_cast<uint32_t*>(obj + 0x68) == 0) || k == 1) {
            uint32_t v = Fn0089ab40(data);
            *reinterpret_cast<void**>(obj + 0x20) = Fn008a1834(library, data, v);
            *reinterpret_cast<uint32_t*>(obj + 0x34) = Fn008a3343(library, Fn0089c1ff(obj));
            *reinterpret_cast<uint32_t*>(obj + 0xc) = 0x8a1267;
            *reinterpret_cast<uint32_t*>(obj + 0x10) = *reinterpret_cast<uint32_t*>(obj + 0x20);
            uint8_t* t = *reinterpret_cast<uint8_t**>(obj + 0x20);
            *reinterpret_cast<uint32_t*>(obj + 0x7c) = *reinterpret_cast<uint32_t*>(t + 0x214);
            *reinterpret_cast<uint16_t*>(obj + 0x80) = *reinterpret_cast<uint16_t*>(t + 0x218);
            *reinterpret_cast<uint16_t*>(obj + 0x82) = *reinterpret_cast<uint16_t*>(t + 0x21a);
            if (*reinterpret_cast<uint32_t*>(obj + 0x54) != 0) {
                *reinterpret_cast<uint32_t*>(obj + 4) = 0x89c848;
                *reinterpret_cast<uint32_t*>(obj + 8) = *reinterpret_cast<uint32_t*>(obj + 0x54);
            } else {
                *reinterpret_cast<uint32_t*>(obj + 4) = 0x89c859;
                *reinterpret_cast<void**>(obj + 8) = obj;
                *reinterpret_cast<uint32_t*>(obj + 0xd0) = Fn0089c567(obj);
            }
            return obj;
        }
        *err = 0x2729;
        return 0;
    }
    *err = 0x2729;
    return 0;
}
#endif

// The glyph loader: the original takes the face in esi.
#ifdef OB_DRAFTS
// CLOSE: 0x0089efd1 score 182
bool Fn0089efd1Draft_ac55d8(uint8_t* face, uint32_t a, uint32_t flags)
{
    bool loaded = false;
    uint8_t* size = *reinterpret_cast<uint8_t**>(face + 0x180);
    if (*reinterpret_cast<uint32_t*>(face + 0x1c) != 0 && *reinterpret_cast<uint32_t*>(size + 0x24) != 0 && *reinterpret_cast<uint32_t*>(size + 0x2c) != 0) {
        *reinterpret_cast<uint32_t*>(face + 0x118) = 0;
        loaded = false;
    }
    return loaded;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0089f23b score 105
void Fn0089f23bDraft_ac55d8(uint8_t* face, uint32_t glyph, uint32_t a, uint32_t b, uint32_t loadMode, uint32_t flags, uint32_t* err)
{
    *err = Fn009f24d8(FT_MEM_AC55D8(face), 0);
    if (*err == 0) {
        void* mem = *reinterpret_cast<void**>(face + 4);
        if (*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(mem) + 0xa8) != 0xaa005501) {
            Fn0089a578(mem, 0x2723);
        }
        uint8_t* size = *reinterpret_cast<uint8_t**>(face + 0x180);
        *reinterpret_cast<uint32_t*>(size + 0xb0) = flags & 0x80;
        *reinterpret_cast<uint32_t*>(size + 0xb8) = loadMode & 0xff;
        flags &= 0xfffe;
        *reinterpret_cast<uint32_t*>(face + 0x28) = (*reinterpret_cast<uint32_t*>(face + 0x24) != 0 && *reinterpret_cast<uint32_t*>(face + 0x40) == 0 && (flags & 0x100) == 0) ? 1 : 0;
        *reinterpret_cast<uint32_t*>(face + 0x2c) = (~(flags >> 8)) & 1;
        if (*reinterpret_cast<uint32_t*>(face + 0x178) != 0 && (flags & 2)) {
            *reinterpret_cast<uint32_t*>(face + 0x120) = 1;
        } else {
            *reinterpret_cast<uint32_t*>(face + 0x120) = 0;
        }
        *reinterpret_cast<uint32_t*>(face + 0xe8) = 0;
        *reinterpret_cast<uint32_t*>(face + 0xcc) = 1;
        void (*hook)(void*, void*) = *reinterpret_cast<void (**)(void*, void*)>(face + 0x40);
        if (hook != 0) {
            hook(face, *reinterpret_cast<void**>(face + 0x44));
        }
    } else {
        Fn0089a632(*reinterpret_cast<void**>(face + 4));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00896425 score 29
bool cGZFont::Fn00896425(const void* text, uint32_t n)
{
    const uint16_t* p = static_cast<const uint16_t*>(text);
    const uint16_t* end = p + n;
    for (; p < end; p++) {
        if (Fn008963c9(*p) != 0) {
            return true;
        }
    }
    return false;
}
#endif
