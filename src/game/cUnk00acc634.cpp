#include "classes/cUnk00acc634.h"
#include <algorithm>
#include <new>
#include <string.h>

// The software graphics driver: the driver interface (engine/cIGZGDriver.h) on the game's own span renderers.

// Helpers the original keeps out of line (their callers call them): the 2003 compiler would inline them here.
#ifdef _MSC_VER
#define NOINLINE_acc634 __declspec(noinline)
#else
#define NOINLINE_acc634
#endif

// One mip level of a texture: whether it is stored, the pool block holding it and where in it, and its buffer.
struct Level_acc634 {
    uint32_t mbStored;
    uint32_t mnBlock;
    uint32_t mnOffset;
    void* mpData;
    uint8_t mbFlag;
    uint8_t mpad11[3];

    NOINLINE_acc634 bool Fn008de530(uint32_t size, bool flag);
};

// The record of the texture table: nine mip levels, the size and the per-texture settings.
struct Texture_acc634 {
    Level_acc634 mLevels[9];
    int32_t mnWidth;
    int32_t mnHeight;
    uint8_t mbUsed;
    uint8_t mpadBd[3];
    uint32_t mnC0;
    uint8_t mbC4;
    uint8_t mbC5;
    uint8_t mbC6;
    uint8_t mbC7;
    uint8_t mbC8;
    uint8_t mpadC9[3];

    Texture_acc634()
    {
        mLevels[0].mbStored = 0;
        mLevels[0].mpData = 0;
        mLevels[1].mbStored = 0;
        mLevels[1].mpData = 0;
        mLevels[2].mbStored = 0;
        mLevels[2].mpData = 0;
        mLevels[3].mbStored = 0;
        mLevels[3].mpData = 0;
        mLevels[4].mbStored = 0;
        mLevels[4].mpData = 0;
        mLevels[5].mbStored = 0;
        mLevels[5].mpData = 0;
        mLevels[6].mbStored = 0;
        mLevels[6].mpData = 0;
        mLevels[7].mbStored = 0;
        mLevels[7].mpData = 0;
        mLevels[8].mbStored = 0;
        mLevels[8].mpData = 0;
        mbUsed = 0;
    }
};

// A block of the pool the mip levels are packed into (0x30 bytes).
struct Block_acc634 {
    void* mpData;
    uint32_t mn04;
    uint32_t mnFirst;
    uint32_t mnLast;
    uint8_t mpad10[0x20];

    // STUB: 0x008de470
    void Fn008de470(uint32_t offset, uint32_t size);
};

// The texture table: the records, the pool the mip levels live in and the number of free records.
struct TexTab_acc634 {
    Texture_acc634* mpTextures;
    Texture_acc634* mpTexturesEnd;
    Texture_acc634* mpTexturesCapacity;
    Block_acc634* mpPool;
    uint8_t mbPoolFlag;
    uint8_t mpad11[7];
    uint32_t mnFree;

    NOINLINE_acc634 uint8_t Fn008de7f0(uint32_t index);
    NOINLINE_acc634 uint8_t Fn008de810(uint32_t index);
    NOINLINE_acc634 uint8_t Fn008de8c0(uint32_t index);
    NOINLINE_acc634 void Fn008de830(uint32_t index, uint8_t value);
    NOINLINE_acc634 void Fn008de880(uint32_t index, uint8_t value);
    NOINLINE_acc634 void Fn008de8a0(uint32_t index, uint8_t value);
    NOINLINE_acc634 void Fn008de8e0(uint32_t index, uint8_t value);
    NOINLINE_acc634 void Fn008de850(uint32_t index, uint8_t* a, uint8_t* b);
    NOINLINE_acc634 void Fn008de900(uint32_t index, uint32_t* width, uint32_t* height);
    void Fn008dea60(uint32_t index);
    bool Fn008deb20(uint32_t index, int32_t width, int32_t height);
    bool Fn008deba0(int32_t count, const uint32_t* indices, uint32_t current);
    // STUB: 0x008df330
    void Fn008df330(int32_t count, uint32_t* indices);
    void Fn008df260(uint32_t count);
    // STUB: 0x008df870
    bool Fn008df870(uint32_t index, int32_t level, int32_t x, int32_t y, int32_t width, int32_t height, uint32_t format,
                    uint32_t type, const void* pixels, int32_t rowLength);
    // STUB: 0x008df550
    bool Fn008df550(uint32_t index, int32_t level, int32_t x, int32_t y, int32_t width, int32_t height, uint32_t format,
                    uint32_t type, const void* pixels, int32_t rowLength);
    // STUB: 0x008df1f0
    void Fn008df1f0(uint32_t count, const Texture_acc634* value);
    // STUB: 0x008de930
    void Fn008de930();
};

// A stage of the texture unit: the bound texture and its size, and the stage's own switches.
struct Stage_acc634 {
    uint32_t mnTexture;
    float mfWidth;
    float mfHeight;
    uint32_t mnCoordA;
    uint32_t mnCoordB;
    uint32_t mnEnvA;
    uint32_t mnEnvB;
    uint8_t mnFlags;
    uint8_t mpad1d[3];
};

// The state word at 0x98: switches the span renderers read.
struct Flags_acc634 {
    uint32_t mnBlendSrc : 3;
    uint32_t mnBlendDst : 3;
    uint32_t mnAlphaFunc : 3;
    uint32_t mnDepthFunc : 3;
    uint32_t mbDepthMask : 1;
    uint32_t mbColorMask : 1;
    uint32_t mbTexture : 1;
    uint32_t mnMid : 2;
    uint32_t mnTexEnv : 3;
    uint32_t mbBit20 : 1;
    uint32_t mnCombineModeRgb : 3;
    uint32_t mnCombineModeAlpha : 3;
    uint32_t mnCombineSourceRgb : 2;
    uint32_t mnCombineSourceAlpha : 2;
    uint32_t mbBit31 : 1;
};

// The second state word at 0x9c: the texture-combine sources and scales, two bits each.
struct Flags2_acc634 {
    uint32_t mnSource0 : 2;
    uint32_t mnSource1 : 2;
    uint32_t mnSource2 : 2;
    uint32_t mnSource3 : 2;
    uint32_t mnScaleRgb : 2;
    uint32_t mnScaleAlpha : 2;
    uint32_t mnHigh : 20;
};

// The window-system device the driver holds (only its fifth slot is used here).
struct Device_acc634 {
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual bool Slot20();
};


// A video mode as the driver reports it (13 words).
struct sGDMode {
    uint32_t mnFields[13];
};

// GLOBAL: 0x00b5c444
extern const char* gpB5c444;

// FUNCTION: 0x008dc730
const char* cUnk00acc634::GetDriverInfo() const
{
    return gpB5c444;
}

// FUNCTION: 0x008dac10
void cUnk00acc634::ClearStencil(int)
{
    mnError = 3;
}

// FUNCTION: 0x008dac20
void cUnk00acc634::StencilFunc(unsigned int, int, unsigned int)
{
    mnError = 3;
}

// FUNCTION: 0x008dbd60
void cUnk00acc634::GetInteger(unsigned int, int* values)
{
    *values = mnRowLength;
}

// FUNCTION: 0x008dbd70
void cUnk00acc634::GetFloat(unsigned int, float* values)
{
    *values = static_cast<float>(static_cast<int32_t>(mnRowLength));
}

// FUNCTION: 0x008dcbe0
bool cUnk00acc634::IsDeviceReady()
{
    return mnMode[0] != 0xffffffff;
}

// FUNCTION: 0x008db700
unsigned int cUnk00acc634::GetTexture(unsigned int stage)
{
    return reinterpret_cast<Stage_acc634*>(mStages)[stage].mnTexture;
}

// FUNCTION: 0x008dbd80
unsigned int cUnk00acc634::GetError()
{
    uint32_t error = mnError;
    mnError = 0;
    return error;
}

// FUNCTION: 0x008dbd40
void cUnk00acc634::GetBoolean(unsigned int, bool* values)
{
    *values = mnRowLength != 0;
}

// FUNCTION: 0x008db1f0
void cUnk00acc634::PixelStore(unsigned int parameter, int value)
{
    if (parameter == 0) {
        mnRowLength = value;
    }
}

// FUNCTION: 0x008dcbc0
unsigned int cUnk00acc634::GetGZCLSID() const
{
    return mbState7 ? 0x086bb8c1 : 0x7aca35c6;
}

// FUNCTION: 0x008e1140
void cUnk00acc634::DrawElements(unsigned int primitive, int count, unsigned int type, const void* indices)
{
    uint32_t drawn = mnDrawCount + 1;
    mnFirst = 0;
    mnDrawCount = drawn;
    Fn008e07a0(primitive, count, type, indices);
}

// FUNCTION: 0x008e1110
void cUnk00acc634::DrawArrays(unsigned int primitive, int first, int count)
{
    mnDrawCount++;
    mnFirst = first;
    Fn008e07a0(primitive, count, 1, 0);
}

// FUNCTION: 0x008db7f0
void cUnk00acc634::EnableVertexColors(bool diffuse, bool specular)
{
    mbDiffuseColors = diffuse;
    mbSpecularColors = specular;
}

// FUNCTION: 0x008dc320
void cUnk00acc634::GetVideoModeInfo(sGDMode& mode)
{
    mode = *reinterpret_cast<sGDMode*>(mnMode);
}

// FUNCTION: 0x008dc340
void cUnk00acc634::SetViewport()
{
    SetViewport(0, 0, mnWidth, mnHeight);
}

// FUNCTION: 0x008daf00
void cUnk00acc634::ShadeModel(unsigned int model)
{
    mbSmooth = model == 1;
    mbDirty = true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008dc4a0 score 6
uint32_t cUnk00acc634::Slot12_acc634()
{
    Shutdown();
    cUnk00ace624& base = *this;
    delete &base;
    return 0;
}
#endif

// FUNCTION: 0x008dc6c0
unsigned int cUnk00acc634::CountVideoModes() const
{
    return (static_cast<char*>(mpModesEnd) - static_cast<char*>(mpModesBegin)) / 52;
}

// FUNCTION: 0x008dbad0
void cUnk00acc634::Flush()
{
    Fn008e0100();
    Fn008e1f00();
    reinterpret_cast<TexTab_acc634*>(mTexTab)->Fn008de930();
}

// FUNCTION: 0x008db870
bool cUnk00acc634::AreTexturesResident(int count, const unsigned int*, bool* resident)
{
    if (count) {
        memset(resident, 1, count);
    }
    return true;
}

// A 3-component colour (and alpha) as the 32-bit pixel the clear and the span fills use, 0xAARRGGBB: each component
// is clamped to 0..1, scaled to 0..256 by the float-bias trick and folded to 0..255.
// FUNCTION: 0x008da4a0
uint32_t Fn008da4a0(float red, float green, float blue, float alpha)
{
    if (red < 0.0f) {
        red = 0.0f;
    } else if (red > 1.0f) {
        red = 1.0f;
    }
    if (green < 0.0f) {
        green = 0.0f;
    } else if (green > 1.0f) {
        green = 1.0f;
    }
    if (blue < 0.0f) {
        blue = 0.0f;
    } else if (blue > 1.0f) {
        blue = 1.0f;
    }
    if (alpha < 0.0f) {
        alpha = 0.0f;
    } else if (alpha > 1.0f) {
        alpha = 1.0f;
    }
    float bias = red + 49152.0f;
    uint32_t r = *reinterpret_cast<uint32_t*>(&bias) - 0x47400000;
    bias = green + 49152.0f;
    uint32_t g = *reinterpret_cast<uint32_t*>(&bias) - 0x47400000;
    bias = blue + 49152.0f;
    uint32_t b = *reinterpret_cast<uint32_t*>(&bias) - 0x47400000;
    bias = alpha + 49152.0f;
    uint32_t a = *reinterpret_cast<uint32_t*>(&bias) - 0x47400000;
    uint32_t cr = static_cast<uint8_t>(r - (r >> 8));
    uint32_t cg = static_cast<uint8_t>(g - (g >> 8));
    uint32_t cb = static_cast<uint8_t>(b - (b >> 8));
    uint32_t ca = static_cast<uint8_t>(a - (a >> 8));
    return (((((ca << 8) + cr) << 8) + cg) << 8) + cb;
}

// The clear colour twice over, the 64-bit pattern the clearing fill stores.
// GLOBAL: 0x00b5c490
extern uint64_t gB5c490;

// FUNCTION: 0x008da9e0
void cUnk00acc634::ClearColor(float red, float green, float blue, float alpha)
{
    uint64_t color = Fn008da4a0(red, green, blue, alpha);
    gB5c490 = (color << 32) | color;
}

// FUNCTION: 0x008db780
void cUnk00acc634::ColorMultiplier(float red, float green, float blue)
{
    mnColor = Fn008da4a0(red, green, blue, 0.0f) | (mnColor & 0xff000000);
}

// FUNCTION: 0x008db7c0
void cUnk00acc634::AlphaMultiplier(float alpha)
{
    mnColor = Fn008da4a0(0.0f, 0.0f, 0.0f, alpha) | (mnColor & 0x00ffffff);
}

// FUNCTION: 0x008dabb0
void cUnk00acc634::ColorMask(bool mask)
{
    reinterpret_cast<Flags_acc634*>(&mnFlags)->mbColorMask = mask;
    mbDirty = true;
}

// FUNCTION: 0x008dabe0
void cUnk00acc634::DepthMask(bool mask)
{
    mbDepthMask = mask;
    reinterpret_cast<Flags_acc634*>(&mnFlags)->mbDepthMask = mask;
    mbDirty = true;
}

// FUNCTION: 0x008dbcc0
bool cUnk00acc634::IsEnabled(unsigned int state)
{
    switch (state) {
    case 0:
        return mbAlphaTest;
    case 1:
        return mbDepthTest;
    case 3:
        return mbCullFace;
    case 4:
        return mbBlend;
    case 5:
        return reinterpret_cast<Stage_acc634*>(mStages)[mnStage].mnFlags & 1;
    case 7:
        return mbState7;
    }
    return false;
}

// FUNCTION: 0x008dbb00
void cUnk00acc634::Enable(unsigned int state)
{
    switch (state) {
    case 5:
        reinterpret_cast<Stage_acc634*>(mStages)[mnStage].mnFlags |= 1;
        if (mnStage == 0) {
            mnFlags |= 0x4000;
        }
        break;
    case 4:
        mbBlend = true;
        break;
    case 0:
        mbAlphaTest = true;
        break;
    case 1:
        mbDepthTest = true;
        break;
    case 3:
        mbCullFace = true;
        break;
    case 7:
        Fn008e0100();
        mbState7 = true;
        break;
    }
    mbDirty = true;
}

// FUNCTION: 0x008dbbe0
void cUnk00acc634::Disable(unsigned int state)
{
    switch (state) {
    case 5:
        reinterpret_cast<Stage_acc634*>(mStages)[mnStage].mnFlags &= ~1;
        if (mnStage == 0) {
            mnFlags &= ~0x4000;
        }
        break;
    case 4:
        mbBlend = false;
        break;
    case 0:
        mbAlphaTest = false;
        break;
    case 1:
        mbDepthTest = false;
        break;
    case 3:
        mbCullFace = false;
        break;
    case 7:
        Fn008e0100();
        mbState7 = false;
        break;
    }
    mbDirty = true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008dc400 score 7
bool cUnk00acc634::Punt(unsigned int id, void* data)
{
    if (id == 0x6c4236e7) {
        mbPunt1d1 = *static_cast<bool*>(data);
        return false;
    }
    if (id == 0x8a8cafb7) {
        return (mnFlags & 7) != 0;
    }
    return false;
}
#endif

// std::fill of a video mode over a range of them.
// FUNCTION: 0x0087f010
void Fn0087f010(sGDMode* first, sGDMode* last, const sGDMode* value)
{
    for (; first != last; ++first) {
        *first = *value;
    }
}

// std::copy of a range of video modes, constructing each in place (a null destination is skipped).
#ifdef OB_DRAFTS
// CLOSE: 0x0087f150 score 16
void Fn0087f150(const sGDMode* first, const sGDMode* last, sGDMode* dest)
{
    for (; first != last; ++first, ++dest) {
        if (dest) {
            *dest = *first;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008dc920 score 18
void cUnk00acc634::GetVideoModeInfo(unsigned int index, sGDMode& mode)
{
    if (index >= CountVideoModes()) {
        mnError = 2;
        return;
    }
    mode = static_cast<sGDMode*>(mpModesBegin)[index];
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008dc6e0 score 27
void cUnk00acc634::GetViewport(int* viewport)
{
    int32_t height = mnViewportHeight;
    int32_t full = mnHeight;
    int32_t x = mnViewportX;
    int32_t y = mnViewportY;
    int32_t width = mnViewportWidth;
    int32_t top = full - y - height;
    int* out = viewport;
    out[0] = x;
    out[1] = top;
    out[2] = width + x;
    out[3] = height + top;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008eaf00 score 4
bool cUnk00acc634::Slot08_ac34cc(unsigned int region)
{
    if (region >= 1 && region <= mnRegionCount && static_cast<uint8_t*>(mpRegions)[region * 0x2c - 4]) {
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x008ea320
void cUnk00acc634::BitBlt(int x, int y, int width, int height, unsigned int format, unsigned int type, const void* pixels,
                          bool colorKeyed, const void* colorKey)
{
    StretchBlt(x, y, width, height, width, height, format, type, pixels, colorKeyed, colorKey);
}

// FUNCTION: 0x008ea360
void cUnk00acc634::BitBltAlpha(int x, int y, int width, int height, unsigned int format, unsigned int type,
                               const void* pixels, bool colorKeyed, const void* colorKey, unsigned int alpha)
{
    StretchBltAlpha(x, y, width, height, width, height, format, type, pixels, colorKeyed, colorKey, alpha);
}

// FUNCTION: 0x008ea3b0
void cUnk00acc634::BitBltAlphaModulate(int x, int y, int width, int height, unsigned int format, unsigned int type,
                                       const void* pixels, bool colorKeyed, const void* colorKey, unsigned int alpha)
{
    StretchBltAlphaModulate(x, y, width, height, width, height, format, type, pixels, colorKeyed, colorKey, alpha);
}

// Replaces a level's buffer with a new one of the given size.
// FUNCTION: 0x008de530
bool Level_acc634::Fn008de530(uint32_t size, bool flag)
{
    mbFlag = flag;
    ::operator delete(mpData);
    mpData = ::operator new(size);
    return mpData != 0;
}

// Gives back every mip level of one texture.
// FUNCTION: 0x008dea60
void TexTab_acc634::Fn008dea60(uint32_t index)
{
    Texture_acc634* texture = mpTextures + index;
    for (int32_t i = 0; i < 9; ++i) {
        Level_acc634* level = &texture->mLevels[i];
        if (level->mbStored) {
            Block_acc634* block = mpPool + level->mnBlock;
            block->Fn008de470(level->mnOffset, ((texture->mnWidth - 1) >> i) + 1);
            level->mbStored = 0;
            if (block->mnFirst == block->mnLast) {
                uint32_t blockIndex = level->mnBlock;
                ::operator delete(mpPool[blockIndex].mpData);
                mpPool[blockIndex].mpData = 0;
                mpPool[blockIndex].mnFirst = 0;
            }
        }
        ::operator delete(level->mpData);
        level->mpData = 0;
    }
}

// Sizes a texture record (at most 256 on a side); a record that held another size gives its levels back.
// FUNCTION: 0x008deb20
bool TexTab_acc634::Fn008deb20(uint32_t index, int32_t width, int32_t height)
{
    if (std::max(width, height) > 0x100) {
        return false;
    }
    if (mpTextures[index].mLevels[0].mbStored) {
        if (mpTextures[index].mnWidth != width || mpTextures[index].mnHeight != height) {
            Fn008dea60(index);
        }
    }
    mpTextures[index].mnWidth = width;
    mpTextures[index].mnHeight = height;
    mpTextures[index].mbC4 = 0;
    return true;
}

// Deletes textures; true when the one currently bound was among them.
// FUNCTION: 0x008deba0
bool TexTab_acc634::Fn008deba0(int32_t count, const uint32_t* indices, uint32_t current)
{
    bool found = false;
    if (count) {
        for (; count != 0; --count, ++indices) {
            if (*indices) {
                Fn008dea60(*indices);
                ++mnFree;
                if (*indices == current) {
                    found = true;
                }
                mpTextures[*indices].mbUsed = 0;
                mpTextures[*indices].mnC0 = 0;
            }
        }
    }
    return found;
}

// FUNCTION: 0x008df260
void TexTab_acc634::Fn008df260(uint32_t count)
{
    Texture_acc634 blank;
    Fn008df1f0(count, &blank);
}

// Takes up to count free records (record 0 is never given out) and writes their indices.
#ifdef OB_DRAFTS
// CLOSE: 0x008df330 score 86
void TexTab_acc634::Fn008df330(int32_t count, uint32_t* indices)
{
    if (count > static_cast<int32_t>(mnFree)) {
        Fn008df260(count - mnFree + (mpTexturesEnd - mpTextures));
        mnFree = count;
    }
    int32_t total = mpTexturesEnd - mpTextures;
    int32_t i = 1;
    int32_t found = 0;
    for (; i < total && found < count; ++i) {
        if (!mpTextures[i].mbUsed) {
            mpTextures[i].mbUsed = 1;
            mpTextures[i].mnC0 = 0;
            mpTextures[i].mbC5 = 0;
            mpTextures[i].mbC6 = 0;
            mpTextures[i].mbC7 = 0;
            mpTextures[i].mbC8 = 0;
            mpTextures[i].mnWidth = 0;
            mpTextures[i].mnHeight = 0;
            indices[found] = i;
            ++found;
            --mnFree;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008db680 score 23
void cUnk00acc634::SetTexture(unsigned int texture, unsigned int stage)
{
    uint32_t width;
    uint32_t height;
    reinterpret_cast<TexTab_acc634*>(mTexTab)->Fn008de900(texture, &width, &height);
    Stage_acc634* record = reinterpret_cast<Stage_acc634*>(mStages) + stage;
    record->mnTexture = texture;
    record->mfWidth = static_cast<float>(static_cast<int32_t>(width << 4));
    record->mfHeight = static_cast<float>(static_cast<int32_t>(height << 4));
    mbDirty = true;
    mbFlag1d7 = false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008db720 score 20
unsigned int cUnk00acc634::CreateTexture(unsigned int, unsigned int width, unsigned int height, unsigned int,
                                         unsigned int)
{
    Fn008e0100();
    uint32_t texture = 0;
    reinterpret_cast<TexTab_acc634*>(mTexTab)->Fn008df330(1, &texture);
    if (!reinterpret_cast<TexTab_acc634*>(mTexTab)->Fn008deb20(texture, width, height)) {
        mnError = 3;
        return 0;
    }
    return texture;
}
#endif

// FUNCTION: 0x008db820
void cUnk00acc634::DeleteTextures(int count, const unsigned int* textures)
{
    Fn008e0100();
    if (reinterpret_cast<TexTab_acc634*>(mTexTab)->Fn008deba0(count, textures,
                                                             reinterpret_cast<Stage_acc634*>(mStages)[0].mnTexture)) {
        SetTexture(0, 0);
    }
}

// FUNCTION: 0x008db8a0
void cUnk00acc634::MatrixMode(unsigned int mode)
{
    switch (mode) {
    case 0:
        mpMatrix = mModelView;
        break;
    case 1:
        mpMatrix = mProjection;
        break;
    }
}

// FUNCTION: 0x008dc0f0
void cUnk00acc634::PolygonOffset(int offset)
{
    mnPolygonOffset = offset;
    switch (reinterpret_cast<Flags_acc634*>(&mnFlags)->mnDepthFunc) {
    case 2:
    case 3:
        mfPolygonBias = 0.5f - offset;
        break;
    case 4:
    case 5:
        mfPolygonBias = 0.5f + offset;
        break;
    default:
        mfPolygonBias = 0.5f;
        break;
    }
}

// FUNCTION: 0x008dc4c0
bool cUnk00acc634::QueryInterface(unsigned int id, void** object)
{
    switch (id) {
    case 0x669565fe:
        *object = this;
        cUnk00ace624::AddRef();
        return true;
    case 1:
    case 0xa4554849:
        *object = static_cast<cIGZGDriver*>(this);
        cUnk00ace624::AddRef();
        return true;
    case 0xe69bfe2a:
        *object = static_cast<cUnk00ac34f8*>(this);
        cUnk00ace624::AddRef();
        return true;
    }
    return false;
}

// The small accessors of the texture table, defined after their callers so the compiler keeps the calls.
// FUNCTION: 0x008de7f0
uint8_t TexTab_acc634::Fn008de7f0(uint32_t index)
{
    return mpTextures[index].mbC4;
}

// FUNCTION: 0x008de810
uint8_t TexTab_acc634::Fn008de810(uint32_t index)
{
    return mpTextures[index].mbC5;
}

// FUNCTION: 0x008de8c0
uint8_t TexTab_acc634::Fn008de8c0(uint32_t index)
{
    return mpTextures[index].mbC8;
}

// FUNCTION: 0x008de830
void TexTab_acc634::Fn008de830(uint32_t index, uint8_t value)
{
    mpTextures[index].mbC5 = value;
}

// FUNCTION: 0x008de880
void TexTab_acc634::Fn008de880(uint32_t index, uint8_t value)
{
    mpTextures[index].mbC6 = value;
}

// FUNCTION: 0x008de8a0
void TexTab_acc634::Fn008de8a0(uint32_t index, uint8_t value)
{
    mpTextures[index].mbC7 = value;
}

// FUNCTION: 0x008de8e0
void TexTab_acc634::Fn008de8e0(uint32_t index, uint8_t value)
{
    mpTextures[index].mbC8 = value;
}

// FUNCTION: 0x008de850
void TexTab_acc634::Fn008de850(uint32_t index, uint8_t* a, uint8_t* b)
{
    *a = mpTextures[index].mbC6;
    *b = mpTextures[index].mbC7;
}

// FUNCTION: 0x008de900
void TexTab_acc634::Fn008de900(uint32_t index, uint32_t* width, uint32_t* height)
{
    *width = mpTextures[index].mnWidth;
    *height = mpTextures[index].mnHeight;
}


// The depth clear value repeated in the four 16-bit lanes of a 64-bit pattern.
// GLOBAL: 0x00b16080
extern uint64_t gB16080;

#ifdef OB_DRAFTS
// CLOSE: 0x008daa20 score 21
void cUnk00acc634::ClearDepth(double depth)
{
    if (depth < -1.0) {
        depth = -1.0;
    } else if (depth > 1.0) {
        depth = 1.0;
    }
    uint64_t value = static_cast<uint32_t>(static_cast<int32_t>((depth * 0.25 + 0.75 - 0.5) * 131070.0 + 0.5));
    uint32_t pair = static_cast<uint32_t>((value << 16) | value);
    gB16080 = (static_cast<uint64_t>(pair) << 32) | pair;
}
#endif

// The comparison codes are bits 9..11 of the state word: bit 0 = equal, bit 1 = less, bit 2 = greater.
// FUNCTION: 0x008daaa0
void cUnk00acc634::DepthFunc(unsigned int test)
{
    Flags_acc634* flags = reinterpret_cast<Flags_acc634*>(&mnFlags);
    switch (test) {
    case 7:
        flags->mnDepthFunc = 7;
        break;
    case 1:
        flags->mnDepthFunc = 2;
        break;
    case 3:
        flags->mnDepthFunc = 3;
        break;
    case 2:
        flags->mnDepthFunc = 1;
        break;
    case 4:
        flags->mnDepthFunc = 4;
        break;
    case 6:
        flags->mnDepthFunc = 5;
        break;
    case 5:
        flags->mnDepthFunc = 6;
        break;
    case 0:
        flags->mnDepthFunc = 0;
        break;
    }
    PolygonOffset(mnPolygonOffset);
    mbDirty = true;
}

// FUNCTION: 0x008dac30
void cUnk00acc634::BlendFunc(unsigned int source, unsigned int destination)
{
    Flags_acc634* flags = reinterpret_cast<Flags_acc634*>(&mnFlags);
    switch (source) {
    case 0:
        flags->mnBlendSrc = 0;
        break;
    case 1:
        flags->mnBlendSrc = 1;
        break;
    case 8:
        flags->mnBlendSrc = 6;
        break;
    case 9:
        flags->mnBlendSrc = 7;
        break;
    case 4:
        flags->mnBlendSrc = 4;
        break;
    case 5:
        flags->mnBlendSrc = 5;
        break;
    }
    switch (destination) {
    case 0:
        flags->mnBlendDst = 0;
        break;
    case 1:
        flags->mnBlendDst = 1;
        break;
    case 2:
        flags->mnBlendDst = 2;
        break;
    case 3:
        flags->mnBlendDst = 3;
        break;
    case 4:
        flags->mnBlendDst = 4;
        break;
    case 5:
        flags->mnBlendDst = 5;
        break;
    }
    mbDirty = true;
}

// FUNCTION: 0x008dada0
void cUnk00acc634::AlphaFunc(unsigned int test, float reference)
{
    reference += 49152.0f;
    uint32_t fixed = *reinterpret_cast<uint32_t*>(&reference) - 0x47400000;
    mnAlphaRef = static_cast<uint8_t>(fixed - (fixed >> 8));
    Flags_acc634* flags = reinterpret_cast<Flags_acc634*>(&mnFlags);
    switch (test) {
    case 7:
        flags->mnAlphaFunc = 7;
        break;
    case 4:
        flags->mnAlphaFunc = 4;
        break;
    case 0:
        flags->mnAlphaFunc = 0;
        break;
    case 1:
        flags->mnAlphaFunc = 2;
        break;
    case 2:
        flags->mnAlphaFunc = 1;
        break;
    case 3:
        flags->mnAlphaFunc = 3;
        break;
    case 5:
        flags->mnAlphaFunc = 6;
        break;
    case 6:
        flags->mnAlphaFunc = 5;
        break;
    }
    mbDirty = true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008db210 score 20
void cUnk00acc634::TexEnv(unsigned int, unsigned int, int mode)
{
    if (mnStage == 0) {
        Flags_acc634* flags = reinterpret_cast<Flags_acc634*>(&mnFlags);
        Stage_acc634* stage = reinterpret_cast<Stage_acc634*>(mStages);
        switch (mode) {
        case 0:
            flags->mnTexEnv = 0;
            stage->mnEnvA = 0xffffffff;
            stage->mnEnvB = 0xffffff;
            break;
        case 1:
            stage->mnEnvA = 0;
            stage->mnEnvB = 0;
            flags->mnTexEnv = 1;
            break;
        case 3:
            flags->mnTexEnv = 3;
            stage->mnEnvA = 0;
            stage->mnEnvB = 0;
            break;
        case 2:
            stage->mnEnvA = 0;
            stage->mnEnvB = 0;
            flags->mnTexEnv = 2;
            break;
        case 4:
            flags->mnTexEnv = 4;
            stage->mnEnvA = 0;
            stage->mnEnvB = 0;
            break;
        }
        mbDirty = true;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008db550 score 93
void cUnk00acc634::TexParameter(unsigned int, unsigned int name, int value)
{
    uint8_t* flagsByte = &reinterpret_cast<Stage_acc634*>(mStages)[mnStage].mnFlags;
    uint32_t old = *flagsByte;
    uint32_t bits = old;
    switch (name) {
    case 1:
        switch (value) {
        case 0:
            bits &= ~0xc;
            break;
        case 1:
            bits = (bits & ~8) | 4;
            break;
        case 4:
        case 6:
            bits = (bits & ~4) | 8;
            break;
        case 5:
        case 7:
            bits |= 0xc;
            break;
        }
        break;
    case 0:
        switch (value) {
        case 0:
            bits &= ~2;
            break;
        case 1:
            bits |= 2;
            break;
        }
        break;
    case 2:
    case 3:
        switch (value) {
        case 2:
            bits |= 0x10;
            break;
        case 3:
            bits &= ~0x10;
            break;
        }
        break;
    }
    if (old != bits) {
        *flagsByte = bits;
        mbDirty = true;
        if (mbFlag1d7) {
            TexTab_acc634* table = reinterpret_cast<TexTab_acc634*>(mTexTab);
            uint32_t texture = reinterpret_cast<Stage_acc634*>(mStages)[mnStage].mnTexture;
            table->Fn008de880(texture, (bits >> 1) & 1);
            table->Fn008de8a0(texture, (bits >> 2) & 1);
            table->Fn008de830(texture, (bits >> 3) & 1);
            table->Fn008de8e0(texture, (bits >> 4) & 1);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008daf20 score 51
void cUnk00acc634::BindTexture(unsigned int, unsigned int texture)
{
    TexTab_acc634* table = reinterpret_cast<TexTab_acc634*>(mTexTab);
    uint32_t width;
    uint32_t height;
    table->Fn008de900(texture, &width, &height);
    Stage_acc634* stages = reinterpret_cast<Stage_acc634*>(mStages);
    stages[mnStage].mnTexture = texture;
    stages[mnStage].mfWidth = static_cast<float>(static_cast<int32_t>(width << 4));
    stages[mnStage].mfHeight = static_cast<float>(static_cast<int32_t>(height << 4));
    uint32_t bits = stages[mnStage].mnFlags & 1;
    if (table->Fn008de810(texture)) {
        bits |= 8;
    }
    if (table->Fn008de8c0(texture)) {
        bits |= 0x10;
    }
    uint8_t wrapS;
    uint8_t wrapT;
    table->Fn008de850(texture, &wrapS, &wrapT);
    if (wrapS) {
        bits |= 2;
    }
    if (wrapT) {
        bits |= 4;
    }
    if (stages[mnStage].mnFlags != bits) {
        stages[mnStage].mnFlags = bits;
        mbDirty = true;
    }
    mbFlag1d7 = true;
}
#endif

// A 4x4 matrix product: out = a * b (row vectors times columns).
// FUNCTION: 0x008da610
void Fn008da610(float* out, const float* a, const float* b)
{
    out[0] = a[0] * b[0] + a[1] * b[4] + a[2] * b[8] + a[3] * b[12];
    out[1] = a[0] * b[1] + a[1] * b[5] + a[2] * b[9] + a[3] * b[13];
    out[2] = a[0] * b[2] + a[1] * b[6] + a[2] * b[10] + a[3] * b[14];
    out[3] = a[0] * b[3] + a[1] * b[7] + a[2] * b[11] + a[3] * b[15];
    out[4] = a[4] * b[0] + a[5] * b[4] + a[6] * b[8] + a[7] * b[12];
    out[5] = a[4] * b[1] + a[5] * b[5] + a[6] * b[9] + a[7] * b[13];
    out[6] = a[4] * b[2] + a[5] * b[6] + a[6] * b[10] + a[7] * b[14];
    out[7] = a[4] * b[3] + a[5] * b[7] + a[6] * b[11] + a[7] * b[15];
    out[8] = a[8] * b[0] + a[9] * b[4] + a[10] * b[8] + a[11] * b[12];
    out[9] = a[8] * b[1] + a[9] * b[5] + a[10] * b[9] + a[11] * b[13];
    out[10] = a[8] * b[2] + a[9] * b[6] + a[10] * b[10] + a[11] * b[14];
    out[11] = a[8] * b[3] + a[9] * b[7] + a[10] * b[11] + a[11] * b[15];
    out[12] = a[12] * b[0] + a[13] * b[4] + a[14] * b[8] + a[15] * b[12];
    out[13] = a[12] * b[1] + a[13] * b[5] + a[14] * b[9] + a[15] * b[13];
    out[14] = a[12] * b[2] + a[13] * b[6] + a[14] * b[10] + a[15] * b[14];
    out[15] = a[12] * b[3] + a[13] * b[7] + a[14] * b[11] + a[15] * b[15];
}

// A 4-vector times a 4x4 matrix.
// FUNCTION: 0x008da830
void Fn008da830(float* out, const float* v, const float* m)
{
    out[0] = v[0] * m[0] + v[1] * m[4] + v[2] * m[8] + v[3] * m[12];
    out[1] = v[0] * m[1] + v[1] * m[5] + v[2] * m[9] + v[3] * m[13];
    out[2] = v[0] * m[2] + v[1] * m[6] + v[2] * m[10] + v[3] * m[14];
    out[3] = v[0] * m[3] + v[1] * m[7] + v[2] * m[11] + v[3] * m[15];
}

// STUB: 0x00910003
void* Fn00910003(void* destination, int value, uint32_t count);

// The window-to-clip scale for the current viewport, and the combined transform of the pipeline with the light
// vectors carried through the model-view matrix.
// FUNCTION: 0x008db8d0
void cUnk00acc634::Fn008db8d0()
{
    Fn00910003(mScreenMatrix, 0, 16);
    double width = mnViewportWidth;
    mScreenMatrix[0] = static_cast<float>(8.0 * width);
    mScreenMatrix[3] = static_cast<float>((mnViewportX + width * 0.5) * 16.0);
    double height = mnViewportHeight;
    mScreenMatrix[5] = static_cast<float>(-8.0 * height);
    mScreenMatrix[7] = static_cast<float>((mnViewportY + height * 0.5) * 16.0);
    mScreenMatrix[10] = 0.5f;
    mScreenMatrix[11] = 0.5f;
    mScreenMatrix[15] = 1.0f;
    mfDepthScale = (mProjection[10] + mProjection[14]) / mProjection[14] * 0.5f;
    mfDepthBias = mProjection[11] * 0.5f;
    float combined[16];
    Fn008da610(combined, mScreenMatrix, mProjection);
    Fn008da610(mScreenMatrix, combined, mModelView);
    Fn008da830(mTexOutA, mTexColA, mModelView);
    Fn008da830(mTexOutB, mTexColB, mModelView);
}

// FUNCTION: 0x008dba30
void cUnk00acc634::LoadIdentity()
{
    for (int i = 0; i < 16; ++i) {
        static_cast<float*>(mpMatrix)[i] = 0.0f;
    }
    static_cast<float*>(mpMatrix)[0] = 1.0f;
    static_cast<float*>(mpMatrix)[5] = 1.0f;
    static_cast<float*>(mpMatrix)[10] = 1.0f;
    static_cast<float*>(mpMatrix)[15] = 1.0f;
    Fn008db8d0();
}

// FUNCTION: 0x008dc360
void cUnk00acc634::SetViewport(int x, int y, int width, int height)
{
    if (static_cast<uint32_t>(x) > mnWidth) {
        x = mnWidth;
    }
    if (static_cast<uint32_t>(y) > mnHeight) {
        y = mnHeight;
    }
    if (static_cast<uint32_t>(x + width) > mnWidth) {
        width = mnWidth - x;
    }
    if (static_cast<uint32_t>(y + height) > mnHeight) {
        height = mnHeight - y;
    }
    mnViewportX = x;
    mnViewportY = mnHeight - y - height;
    mnViewportHeight = height;
    mnViewportWidth = width;
    Fn008db8d0();
    Fn008dc160(mnViewportX, mnViewportY, mnViewportWidth + mnViewportX, mnViewportHeight + mnViewportY);
}

// FUNCTION: 0x008dbda0
void cUnk00acc634::TexStageCoord(unsigned int source)
{
    Stage_acc634* stages = reinterpret_cast<Stage_acc634*>(mStages);
    if (source == 0x10) {
        mbCoordGen = true;
        stages[mnStage].mnCoordA = mnStage * 8;
        stages[mnStage].mnCoordB = mnCoordBase + mnStage * 8;
    } else {
        stages[mnStage].mnCoordA = source * 8;
        stages[mnStage].mnCoordB = mnCoordBase + source * 8;
    }
}

// The screen rectangle the clip planes and the depth range are set from: the original's tail jumps into a
// routine that takes its table in a register, so it stays a declaration.
// STUB: 0x008e3040
void Fn008e3040(float x, float y, float width, float height, float near, float far);

// GLOBAL: 0x00b160c8
extern int32_t gB160c8;
// GLOBAL: 0x00b160cc
extern int32_t gB160cc;
// GLOBAL: 0x00b5c590
extern int32_t gB5c590;
// GLOBAL: 0x00b5c594
extern int32_t gB5c594;

// Sets the clip planes for a rectangle of the viewport (in 1/16 pixels) and the depth range of the projection.
#ifdef OB_DRAFTS
// CLOSE: 0x008dc160 score 113
void cUnk00acc634::Fn008dc160(uint32_t left, uint32_t top, uint32_t right, uint32_t bottom)
{
    float near;
    float far;
    if (mProjection[14] != 0.0f) {
        mbFlag1a4 = false;
        float scale = 1.0f / mProjection[11];
        near = (mProjection[10] - 1.0f) * scale;
        far = (mProjection[10] + 1.0f) * scale;
    } else {
        near = 1.5f;
        far = 0.5f;
        mbFlag1a4 = true;
    }
    float x = static_cast<float>(static_cast<int32_t>(left << 4));
    float y = static_cast<float>(static_cast<int32_t>(top << 4));
    float width = static_cast<float>(static_cast<int32_t>((right - left) << 4));
    float height = static_cast<float>(static_cast<int32_t>((bottom - top) << 4));
    Fn008e3040(x, y, width, height, near, far);
    float x1 = static_cast<float>(static_cast<int32_t>(right << 4));
    gB160c8 = (right << 4) - 16;
    float y1 = static_cast<float>(static_cast<int32_t>(bottom << 4));
    gB5c590 = left << 4;
    gB5c594 = top << 4;
    gB160cc = (bottom << 4) - 16;
    mfClip[0] = -x;
    mfClip[1] = -y;
    mfClip[2] = -x1;
    mfClip[3] = -y1;
    mfClipNear = near;
    mfClipFar = far;
}
#endif

// FUNCTION: 0x008dc560
void cUnk00acc634::LoadMatrix(const float* matrix)
{
    for (int k = 0; k < 16; ++k) {
        static_cast<float*>(mpMatrix)[k] = matrix[(k >> 2) + ((k & 3) << 2)];
    }
    Fn008db8d0();
    if (mpMatrix == mProjection) {
        Fn008dc160(mnViewportX, mnViewportY, mnViewportWidth + mnViewportX, mnViewportHeight + mnViewportY);
    }
}

// std::copy_backward of a range of video modes; returns the new start of the destination.
// FUNCTION: 0x0087f090
sGDMode* Fn0087f090(const sGDMode* first, const sGDMode* last, sGDMode* destEnd)
{
    for (int32_t n = last - first; n > 0; --n) {
        --last;
        --destEnd;
        *destEnd = *last;
    }
    return destEnd;
}

// The MMX span helpers: each walks its rows with the registers it names, so the bodies are the original's.
#ifdef _MSC_VER
// GLOBAL: 0x00b16080
extern uint64_t gB16080;
// GLOBAL: 0x00b5c490
extern uint64_t gB5c490;

// Fills rows of 16-bit depth values with the depth clear pattern.
// FUNCTION: 0x008dd310
void Fn008dd310(int width, int rows, void* destination, int pitch)
{
    __asm {
        mov edx, destination
        mov ebx, pitch
        mov esi, rows
        movq mm7, gB16080
    row:
        mov ecx, width
        mov edi, edx
    column:
        movq qword ptr [edi], mm7
        movq qword ptr [edi + 8], mm7
        add edi, 16
        sub ecx, 8
        jg column
        add edx, ebx
        dec esi
        jne row
        emms
    }
}

// Fills rows of 32-bit colour values with the colour clear pattern.
// FUNCTION: 0x008dd350
void Fn008dd350(int width, int rows, void* destination, int pitch)
{
    __asm {
        mov edx, destination
        mov ebx, pitch
        mov esi, rows
        movq mm7, gB5c490
    row:
        mov ecx, width
        mov edi, edx
    column:
        movq qword ptr [edi], mm7
        movq qword ptr [edi + 8], mm7
        movq qword ptr [edi + 16], mm7
        movq qword ptr [edi + 24], mm7
        add edi, 32
        sub ecx, 8
        jg column
        add edx, ebx
        dec esi
        jne row
        emms
    }
}

// Copies rows of 32-bit pixels, 16 bytes at a time.
// FUNCTION: 0x008dd210
void Fn008dd210(const void* source, void* destination, uint32_t width, int height, int sourcePitch, int destinationPitch)
{
    uint32_t count = width >> 2;
    int rows = height;
    __asm {
        push esi
        push edi
        mov edx, source
        mov ebx, destination
    row:
        mov edi, ebx
        mov esi, edx
        mov ecx, count
    column:
        movq mm0, qword ptr [esi]
        movq mm2, qword ptr [esi + 8]
        movq qword ptr [edi], mm0
        movq qword ptr [edi + 8], mm2
        add esi, 16
        add edi, 16
        dec ecx
        jne column
        add edx, sourcePitch
        add ebx, destinationPitch
        dec rows
        jne row
        pop edi
        pop esi
        emms
    }
}

// Packs rows of 32-bit pixels into 24-bit pixels, four pixels (16 bytes) to twelve bytes at a time.
// FUNCTION: 0x008dd270
void Fn008dd270(const void* source, void* destination, uint32_t width, int height, int sourcePitch,
                int destinationPitch)
{
    uint32_t count = width >> 2;
    int rows = height;
    uint32_t mask24 = 0xffffff;
    uint32_t mask16 = 0xffff;
    __asm {
        push esi
        push edi
        mov edx, source
        mov ebx, destination
    row:
        mov edi, ebx
        mov esi, edx
        mov ecx, count
        movd mm6, mask16
        movd mm7, mask24
    column:
        movd mm0, dword ptr [esi]
        movd mm1, dword ptr [esi + 4]
        pand mm0, mm7
        movd mm2, dword ptr [esi + 8]
        psllq mm1, 24
        movd mm3, dword ptr [esi + 12]
        por mm0, mm1
        movd dword ptr [edi], mm0
        psrlq mm1, 32
        pand mm2, mm7
        pand mm3, mm7
        pand mm1, mm6
        psllq mm2, 16
        por mm1, mm2
        psrlq mm2, 32
        movd dword ptr [edi + 4], mm1
        pslld mm3, 8
        por mm2, mm3
        add esi, 16
        movd dword ptr [edi + 8], mm2
        add edi, 12
        dec ecx
        jne column
        add edx, sourcePitch
        add ebx, destinationPitch
        dec rows
        jne row
        pop edi
        pop esi
        emms
    }
}

// Whether the CPU has the MMX integer extensions (pminsw faults without them; the handler is empty).
#ifdef OB_DRAFTS
// CLOSE: 0x008e11d0 score 10
bool Fn008e11d0()
{
    __try {
        __asm {
            pminsw mm0, mm0
            emms
        }
    } __except (1) {
    }
    return true;
}
#endif
#endif

// STUB: 0x008d01f0
uint32_t Fn008d01f0(int32_t value);
// STUB: 0x008d0370
uint32_t Fn008d0370(uint32_t value);
// STUB: 0x008d04a0
NOINLINE_acc634 uint32_t Fn008d04a0(int32_t a, int32_t b, int32_t c);

// GLOBAL: 0x00acc0ac
extern uint32_t gAcc0ac[];
// GLOBAL: 0x00acc120
extern uint32_t gAcc120[];

#ifdef OB_DRAFTS
// CLOSE: 0x008d04a0 score 16
uint32_t Fn008d04a0(int32_t a, int32_t b, int32_t c)
{
    uint32_t result = gAcc0ac[b] * c;
    if (a >= 0) {
        a = Fn008d01f0(a);
    }
    if (b > 0) {
        result += Fn008d0370((gAcc120[b] | 0x80000000) & a);
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008eadf0 score 7
void cUnk00acc634::StretchBlt(int x, int y, int width, int height, int sourceWidth, int sourceHeight, unsigned int format,
                              unsigned int type, const void* pixels, bool colorKeyed, const void* colorKey)
{
    Fn008ea950(x, y, width, height, sourceWidth, sourceHeight, format, type, pixels, colorKeyed, colorKey, -1, 0,
               mbPunt1d1);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008eae40 score 2
void cUnk00acc634::StretchBltAlpha(int x, int y, int width, int height, int sourceWidth, int sourceHeight,
                                   unsigned int format, unsigned int type, const void* pixels, bool colorKeyed,
                                   const void* colorKey, unsigned int alpha)
{
    Fn008ea950(x, y, width, height, sourceWidth, sourceHeight, format, type, pixels, colorKeyed, colorKey, alpha, 1, 0);
}
#endif

// FUNCTION: 0x008eb0c0
bool cUnk00acc634::Slot05_ac34cc(unsigned int region)
{
    if (Slot08_ac34cc(region)) {
        uint8_t* regions = static_cast<uint8_t*>(mpRegions);
        --region;
        regions[region * 0x2c + 0x28] = 0;
        ::operator delete(*reinterpret_cast<void**>(static_cast<uint8_t*>(mpRegions) + region * 0x2c));
        --mnRegionLive;
        return true;
    }
    return false;
}

// FUNCTION: 0x008eb110
bool cUnk00acc634::Slot11_acc634()
{
    for (int32_t i = 0; i < static_cast<int32_t>(mnRegionCount); ++i) {
        if (static_cast<uint8_t*>(mpRegions)[i * 0x2c + 0x28]) {
            Slot05_ac34cc(i + 1);
        }
    }
    ::operator delete(mpRegions);
    mpRegions = 0;
    mnRegionCount = 0;
    return true;
}

// GLOBAL: 0x00a800f0
extern void* (OB_STDCALL* gpA800f0)(const char* moduleName);
// GLOBAL: 0x00a80538
extern int (OB_STDCALL* gpA80538)(const char* className, void* instance);
// GLOBAL: 0x00b16108
extern const char* gB16108;

#ifdef OB_DRAFTS
// CLOSE: 0x008e1240 score 12
bool cUnk00acc634::Shutdown()
{
    if ((static_cast<char*>(mpModesEnd) - static_cast<char*>(mpModesBegin)) / 52 != 0) {
        static_cast<Device_acc634*>(mpDevice)->Slot4();
        SetVideoMode(-1, 0, false, false);
        return gpA80538(gB16108, gpA800f0(0)) != 0;
    }
    return false;
}
#endif

// The value conversions of the texture-stage combiner (each a switch with the value itself as the default).
inline uint32_t Map3_acc634(uint32_t value)
{
    switch (value) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    }
    return value;
}

inline uint32_t Map5_acc634(uint32_t value)
{
    switch (value) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    }
    return value;
}

inline uint32_t MapSource_acc634(uint32_t value)
{
    switch (value) {
    case 0:
        return 0;
    case 2:
        return 2;
    case 1:
    case 3:
        return 1;
    }
    return value;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008dc080 score 21
void cUnk00acc634::TexStageCombine(eGDTextureStageCombineScale scale, eGDTextureStageCombineValue value)
{
    uint32_t mapped = Map3_acc634(value);
    Flags2_acc634* flags = reinterpret_cast<Flags2_acc634*>(&mnFlags2);
    mbDirty = true;
    switch (scale) {
    case 0:
        flags->mnScaleRgb = mapped;
        break;
    case 1:
        flags->mnScaleAlpha = mapped;
        break;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008dbed0 score 16
void cUnk00acc634::TexStageCombine(eGDTextureStageCombineMode mode, eGDTextureStageCombineValue value)
{
    uint32_t mapped = Map5_acc634(value);
    Flags_acc634* flags = reinterpret_cast<Flags_acc634*>(&mnFlags);
    mbDirty = true;
    switch (mode) {
    case 0:
        flags->mnCombineModeRgb = mapped;
        break;
    case 1:
        flags->mnCombineModeAlpha = mapped;
        break;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008dbf70 score 28
void cUnk00acc634::TexStageCombine(eGDTextureStageCombineSource source, eGDTextureStageCombineValue value)
{
    uint32_t mapped = MapSource_acc634(value);
    Flags_acc634* flags = reinterpret_cast<Flags_acc634*>(&mnFlags);
    Flags2_acc634* flags2 = reinterpret_cast<Flags2_acc634*>(&mnFlags2);
    switch (source) {
    case 0:
        flags->mnCombineSourceRgb = mapped;
        break;
    case 1:
        flags->mnCombineSourceAlpha = mapped;
        break;
    case 2:
        flags2->mnSource0 = mapped;
        break;
    case 4:
        flags2->mnSource1 = mapped;
        break;
    case 5:
        flags2->mnSource2 = mapped;
        break;
    case 6:
        flags2->mnSource3 = mapped;
        break;
    }
    mbDirty = true;
}
#endif

// FUNCTION: 0x008dbe20
void cUnk00acc634::TexStageMatrix(const float* matrix, unsigned int, unsigned int, unsigned int)
{
    if (mnStage <= 0) {
        if (matrix) {
            mbTexMatrix = true;
            mTexColA[0] = matrix[0];
            mTexColB[0] = matrix[1];
            mTexColA[1] = matrix[4];
            mTexColB[1] = matrix[5];
            mTexColA[2] = matrix[8];
            mTexColB[2] = matrix[9];
            mTexColA[3] = matrix[12];
            mTexColB[3] = matrix[13];
            Fn008da830(mTexOutA, mTexColA, mModelView);
            Fn008da830(mTexOutB, mTexColB, mModelView);
        } else {
            mbTexMatrix = false;
        }
    }
}

// STUB: 0x008d04f0
uint32_t Fn008d04f0(uint32_t format, uint32_t kind);

#ifdef OB_DRAFTS
// CLOSE: 0x008da8c0 score 5
void cUnk00acc634::InterleavedArrays(unsigned int format, int stride, const void* vertices)
{
    if (stride == 0) {
        stride = Fn008d0370(format);
    }
    mbHasColor = Fn008d04f0(format, 5) > 0;
    mnTexCoordSize = Fn008d04f0(format, 7);
    mbHasTexCoord = mnTexCoordSize > 0;
    mnCoordBase = Fn008d04a0(format, 7, 0);
    mnColorOffset = Fn008d04a0(format, 5, 0);
    mnFormat = format;
    mnStride = stride;
    mpVertices = vertices;
    Stage_acc634* stages = reinterpret_cast<Stage_acc634*>(mStages);
    if (mbHasTexCoord) {
        stages[0].mnCoordB = mnCoordBase + stages[0].mnCoordA;
    } else {
        stages[0].mnCoordB = 0;
    }
}
#endif

// GLOBAL: 0x00b16130
extern uint8_t gB16130;
// The software triangle routine the original has behind a function pointer (three vertices, stdcall).
// GLOBAL: 0x00b603b8
extern uint32_t (OB_STDCALL* gpB603b8)(const void* a, const void* b, const void* c);
// STUB: 0x008ea090
uint32_t Fn008ea090(const void* vertices, const uint8_t* color, uint32_t mask, uint32_t count);

// Draws a triangle whose vertices are pointed to: flat unless the colour mask asks for the slow path.
#ifdef OB_DRAFTS
// CLOSE: 0x008ea0f0 score 29
uint32_t Fn008ea0f0(const uint32_t* vertices, const uint8_t* color)
{
    uint8_t mask = (color[1] | color[2] | color[0]) & gB16130;
    if (mask == 0) {
        return gpB603b8(reinterpret_cast<const void*>(vertices[0]), reinterpret_cast<const void*>(vertices[1]),
                        reinterpret_cast<const void*>(vertices[2]));
    }
    return Fn008ea090(vertices, color, mask, 3);
}
#endif

// Uploads a rectangle of one mip level: the compressed formats (7, 8, 9) are copied block row by block row into a
// buffer of the level, every other format goes through the general routine.
#ifdef OB_DRAFTS
// CLOSE: 0x008df870 score 288
bool TexTab_acc634::Fn008df870(uint32_t index, int32_t level, int32_t x, int32_t y, int32_t width, int32_t height,
                               uint32_t format, uint32_t type, const void* pixels, int32_t rowLength)
{
    Level_acc634* target = &mpTextures[index].mLevels[level];
    if (format != 7 && format != 8 && format != 9) {
        ::operator delete(target->mpData);
        target->mpData = 0;
        return Fn008df550(index, level, x, y, width, height, format, type, pixels, rowLength);
    }
    int32_t levelWidth = mpTextures[index].mnWidth >> level;
    int32_t levelHeight = mpTextures[index].mnHeight >> level;
    if (level < 0 || (levelWidth == 0 && levelHeight == 0)) {
        return false;
    }
    levelWidth = std::max(levelWidth, 4);
    levelHeight = std::max(levelHeight, 4);
    if ((x | y) < 0 || x + width > levelWidth || y + height > levelHeight || (width | height) < 0 ||
        ((x | y | width | height) & 3) != 0) {
        return false;
    }
    bool sixteen = format == 9;
    int32_t blockBytes = sixteen * 8 + 8;
    x >>= 2;
    width >>= 2;
    height >>= 2;
    y >>= 2;
    rowLength >>= 2;
    if (width == 0) {
        width = 1;
    }
    if (height == 0) {
        height = 1;
    }
    if (rowLength == 0) {
        rowLength = 1;
    }
    if (!target->mpData || target->mbFlag != sixteen) {
        if (!target->Fn008de530(blockBytes * width * height, sixteen)) {
            return false;
        }
    }
    int32_t destinationRow = (levelWidth >> 2) * blockBytes;
    const uint8_t* source = static_cast<const uint8_t*>(pixels);
    uint8_t* destination = static_cast<uint8_t*>(target->mpData) + destinationRow * y + blockBytes * x;
    for (int32_t row = height; row != 0; --row) {
        memcpy(destination, source, blockBytes * width);
        source += blockBytes * rowLength;
        destination += destinationRow;
    }
    mpTextures[index].mLevels[level].mnBlock = 0;
    return true;
}
#endif

// FUNCTION: 0x008db190
void cUnk00acc634::LoadTextureLevel(unsigned int texture, int level, int x, int y, int width, int height,
                                    unsigned int format, unsigned int type, unsigned int rowLength, const void* pixels)
{
    Fn008e0100();
    if (rowLength == 0) {
        rowLength = width;
    }
    if (!reinterpret_cast<TexTab_acc634*>(mTexTab)->Fn008df870(texture, level, x, y, width, height, format, type,
                                                              pixels, rowLength)) {
        mnError = 3;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x008db030 score 92
void cUnk00acc634::TexImage2D(unsigned int, int level, int, int width, int height, int, unsigned int format,
                              unsigned int type, const void* pixels)
{
    Fn008e0100();
    int32_t rowLength = mnRowLength;
    if (rowLength == 0) {
        rowLength = width;
    }
    int32_t levelWidth;
    int32_t levelHeight;
    Stage_acc634* stages = reinterpret_cast<Stage_acc634*>(mStages);
    reinterpret_cast<TexTab_acc634*>(mTexTab)->Fn008de900(stages[mnStage].mnTexture,
                                                         reinterpret_cast<uint32_t*>(&levelWidth),
                                                         reinterpret_cast<uint32_t*>(&levelHeight));
    if (levelWidth != 0 && levelHeight != 0) {
        levelWidth = ((levelWidth - 1) >> level) + 1;
        levelHeight = ((levelHeight - 1) >> level) + 1;
    }
    if (levelWidth == width && levelHeight == height &&
        reinterpret_cast<TexTab_acc634*>(mTexTab)->Fn008deb20(stages[mnStage].mnTexture, width << level,
                                                             height << level)) {
        if (pixels) {
            if (!reinterpret_cast<TexTab_acc634*>(mTexTab)->Fn008df870(stages[mnStage].mnTexture, level, 0, 0, width,
                                                                      height, format, type, pixels, rowLength)) {
                mnError = 3;
            }
        }
        stages[mnStage].mfWidth = static_cast<float>(width << (level + 4));
        stages[mnStage].mfHeight = static_cast<float>(height << (level + 4));
    } else {
        mnError = 3;
    }
}
#endif

// GLOBAL: 0x00b623e4
extern int32_t gB623e4;

// A region is a saved screen rectangle: 0x2c bytes, the flag at 0x28 says the record is in use.
struct Region_acc634 {
    void* mpData;
    uint32_t mnId;
    uint32_t mn08;
    uint32_t mn0c;
    uint32_t mn10;
    uint32_t mn14;
    uint32_t mn18;
    uint32_t mnBytesPerPixel;
    uint32_t mn20;
    uint32_t mnType;
    uint8_t mbUsed;
    uint8_t mpad29[3];
};

// FUNCTION: 0x008eaf30
unsigned int cUnk00acc634::Slot04_ac34cc(unsigned int type)
{
    if (type != 0 && type != 1) {
        return 0;
    }
    if (mnRegionLive >= mnRegionCount) {
        Region_acc634* grown = static_cast<Region_acc634*>(::operator new((mnRegionCount + 16) * sizeof(Region_acc634)));
        for (int32_t i = 0; i < mnRegionCount; ++i) {
            grown[i] = static_cast<Region_acc634*>(mpRegions)[i];
        }
        for (int32_t i = 0; i < 16; ++i) {
            grown[mnRegionCount + i].mbUsed = 0;
        }
        mnRegionCount += 16;
        ::operator delete(mpRegions);
        mpRegions = grown;
    }
    for (int32_t i = 0; i < mnRegionCount; ++i) {
        Region_acc634* regions = static_cast<Region_acc634*>(mpRegions);
        if (!regions[i].mbUsed) {
            ++mnRegionLive;
            static_cast<Region_acc634*>(mpRegions)[i].mbUsed = 1;
            static_cast<Region_acc634*>(mpRegions)[i].mpData = 0;
            static_cast<Region_acc634*>(mpRegions)[i].mnType = type;
            int32_t id = gB623e4;
            if (id == 0) {
                id = 1;
            }
            static_cast<Region_acc634*>(mpRegions)[i].mnId = id;
            gB623e4 = id + 1;
            static_cast<Region_acc634*>(mpRegions)[i].mn14 = 0;
            static_cast<Region_acc634*>(mpRegions)[i].mn18 = 0;
            static_cast<Region_acc634*>(mpRegions)[i].mn0c = 0;
            static_cast<Region_acc634*>(mpRegions)[i].mn10 = 0;
            switch (type) {
            case 0:
                static_cast<Region_acc634*>(mpRegions)[i].mnBytesPerPixel = 4;
                break;
            case 1:
                static_cast<Region_acc634*>(mpRegions)[i].mnBytesPerPixel = 2;
                break;
            }
            return i + 1;
        }
    }
    return 0;
}

// GLOBAL: 0x00b5caa0
extern int32_t gB5caa0;
// GLOBAL: 0x00a800f4
extern int (OB_STDCALL* gpA800f4)(void* versionInfo);

// The operating-system version record (OSVERSIONINFOA).
struct VersionInfo_acc634 {
    uint32_t mnSize;
    uint32_t mnMajor;
    uint32_t mnMinor;
    uint32_t mnBuild;
    uint32_t mnPlatform;
    char mszCsd[128];
};

// Whether the system is the first generation of the consumer line (platform 1, version 4.0); the answer is cached.
#ifdef OB_DRAFTS
// CLOSE: 0x008e1160 score 24
bool Fn008e1160()
{
    if (gB5caa0 == 0) {
        VersionInfo_acc634 info;
        info.mnSize = sizeof(VersionInfo_acc634);
        if (gpA800f4(&info) && (info.mnPlatform != 1 || info.mnMajor != 4 || info.mnMinor != 0)) {
            gB5caa0 = 2;
            return false;
        }
        gB5caa0 = 1;
        return true;
    }
    return gB5caa0 == 1;
}
#endif

// GLOBAL: 0x00a80590
extern uint32_t (OB_STDCALL* gpA80590)(void* window, uint32_t id, uint32_t elapse, void* callback);

// A list of buffers (begin, end, capacity of 32-bit words).
struct Buffer_acc634 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCapacity;
};

// Restarts the device's timer when it is not running and clears every buffer in the list.
#ifdef OB_DRAFTS
// CLOSE: 0x008e1570 score 22
void cUnk00acc634::Fn008e1570()
{
    Device_acc634* device = static_cast<Device_acc634*>(mpDevice);
    if (!device->Slot20()) {
        static_cast<Device_acc634*>(mpDevice)->Slot11();
        gpA80590(mhWnd, 0x39a6, 1000, 0);
    }
    int32_t count = (static_cast<Buffer_acc634*>(mpBuffersEnd) - static_cast<Buffer_acc634*>(mpBuffersBegin));
    for (int32_t i = 0; i < count; ++i) {
        Buffer_acc634* buffer = static_cast<Buffer_acc634*>(mpBuffersBegin) + i;
        memset(buffer->mpBegin, 0, (buffer->mpEnd - buffer->mpBegin) * 4);
    }
}
#endif

#ifdef _MSC_VER
// GLOBAL: 0x00b16088
extern uint64_t gB16088[];
// GLOBAL: 0x00b5c458
extern uint64_t gB5c458;
// GLOBAL: 0x00b5c460
extern uint64_t gB5c460;
// GLOBAL: 0x00b5c468
extern uint64_t gB5c468;
// GLOBAL: 0x00b5c470
extern uint64_t gB5c470;
// GLOBAL: 0x00b5c478
extern uint64_t gB5c478;
// GLOBAL: 0x00b5c480
extern uint64_t gB5c480;

// Converts rows of 32-bit pixels to 16-bit with an ordered dither (the dither row repeats every four rows).
// FUNCTION: 0x008dd390
void Fn008dd390(const void* source, void* destination, uint32_t width, int height, int sourcePitch,
                int destinationPitch)
{
    uint32_t count = width >> 2;
    int rows = height;
    __asm {
        push esi
        push edi
        mov edx, source
        mov ebx, destination
        movq mm5, gB5c470
        pxor mm4, mm4
        movq mm6, gB5c468
        movq mm7, gB5c480
        xor eax, eax
    row:
        push eax
        and eax, 3
        shl eax, 4
        movq mm0, qword ptr [eax + gB16088]
        movq mm1, qword ptr [eax + gB16088 + 8]
        movq gB5c460, mm0
        movq gB5c458, mm1
        mov edi, ebx
        mov esi, edx
        mov ecx, count
        movq mm0, qword ptr [esi]
        movq mm2, qword ptr [esi + 8]
    column:
        paddusb mm0, gB5c460
        paddusb mm2, gB5c458
        movq mm1, mm0
        movq mm3, mm2
        pand mm0, mm5
        pmaddwd mm0, gB5c478
        pand mm2, mm5
        pmaddwd mm2, gB5c478
        pand mm1, mm6
        psrld mm1, mm7
        pand mm3, mm6
        psrld mm3, mm7
        add esi, 16
        psrld mm0, 6
        add edi, 8
        psrld mm2, 6
        por mm0, mm1
        por mm2, mm3
        movq mm1, mm0
        movq mm3, mm2
        psrlq mm1, 16
        por mm1, mm0
        movq mm0, qword ptr [esi]
        psrlq mm3, 16
        por mm3, mm2
        movq mm2, qword ptr [esi + 8]
        punpckldq mm1, mm3
        movq qword ptr [edi - 8], mm1
        dec ecx
        jne column
        add edx, sourcePitch
        add ebx, destinationPitch
        pop eax
        inc eax
        mov ecx, rows
        cmp ecx, eax
        jne row
        pop edi
        pop esi
        emms
    }
}
#endif

// A triangle's vertex record (eight words).
struct Vertex_acc634 {
    uint32_t mnWords[8];
};

// Draws a flat-shaded triangle from three vertex pointers: copies the vertices, gives all three the first one's
// colour word and sends them to the triangle routine (or to the general routine when the colour mask asks).
#ifdef OB_DRAFTS
// CLOSE: 0x008ea140 score 40
uint32_t Fn008ea140(const Vertex_acc634* const* vertices, const uint8_t* color)
{
    Vertex_acc634 copy[3];
    copy[0] = *vertices[0];
    copy[1] = *vertices[1];
    copy[2] = *vertices[2];
    copy[2].mnWords[4] = copy[0].mnWords[4];
    copy[1].mnWords[4] = copy[0].mnWords[4];
    uint8_t mask = (color[1] | color[2] | color[0]) & gB16130;
    if (mask == 0) {
        return gpB603b8(&copy[0], &copy[1], &copy[2]);
    }
    const Vertex_acc634* list[3] = {&copy[0], &copy[1], &copy[2]};
    return Fn008ea090(list, color, mask, 3);
}
#endif

// A colour component in 0..1 as 0..255 (clamped; the float-bias trick of Fn008da4a0 does the rounding).
inline int32_t ByteOf_acc634(float value)
{
    if (value < 0.0f) {
        return 0;
    }
    if (value > 1.0f) {
        return 0xff;
    }
    value += 49152.0f;
    uint32_t fixed = *reinterpret_cast<uint32_t*>(&value) - 0x47400000;
    return static_cast<uint8_t>(fixed - (fixed >> 8));
}

// The texture environment colour as 64-bit lane patterns: 16-bit lanes of the four components in three arrangements.
// GLOBAL: 0x00b5c9c8
extern int64_t gB5c9c8;
// GLOBAL: 0x00b5c9d0
extern uint64_t gB5c9d0;
// GLOBAL: 0x00b5c9d8
extern int64_t gB5c9d8;

#ifdef OB_DRAFTS
// CLOSE: 0x008db320 score 156
void cUnk00acc634::TexEnv(unsigned int, unsigned int, const float* color)
{
    Fn008e0100();
    int32_t c0 = ByteOf_acc634(color[0]);
    int32_t c1 = ByteOf_acc634(color[1]);
    int32_t c2 = ByteOf_acc634(color[2]);
    int32_t c3 = ByteOf_acc634(color[3]);
    gB5c9c8 = (static_cast<int64_t>(c0) * 0x10000 + c1) * 0x10000 + c2;
    gB5c9d8 = ((static_cast<int64_t>(c3) * 0x10000 + c0) * 0x10000 + c1) * 0x10000 + c2;
    gB5c9d0 = (static_cast<uint64_t>(gB5c9d8 * 0x101) & 0xfffefffefffefffeULL) >> 1;
}
#endif

// Programs a texture stage from a combiner description: bytes 0..3 are the colour-side modes and sources, 4..7 the
// alpha-side ones (high nibble: operand, low nibble: source), 8 and 9 the scales.
// FUNCTION: 0x0087ca30
void cUnk00acc634::SetCombiner(const cGDCombiner& combiner, unsigned int stage)
{
    uint32_t operands[8];
    operands[0] = 2;
    operands[1] = 3;
    operands[2] = 4;
    operands[3] = 5;
    operands[4] = 4;
    operands[5] = 5;
    operands[6] = 4;
    operands[7] = 5;
    TexStage(stage);
    TexEnv(0, 0, 4);
    const uint8_t* c = reinterpret_cast<const uint8_t*>(&combiner);
    TexStageCombine(static_cast<eGDTextureStageCombineMode>(0), static_cast<eGDTextureStageCombineValue>(c[0]));
    TexStageCombine(static_cast<eGDTextureStageCombineScale>(0), static_cast<eGDTextureStageCombineValue>(c[8]));
    TexStageCombine(static_cast<eGDTextureStageCombineOperand>(0),
                    static_cast<eGDTextureStageCombineValue>(operands[c[1] >> 4]));
    TexStageCombine(static_cast<eGDTextureStageCombineSource>(0), static_cast<eGDTextureStageCombineValue>(c[1] & 0xf));
    TexStageCombine(static_cast<eGDTextureStageCombineOperand>(1),
                    static_cast<eGDTextureStageCombineValue>(operands[c[2] >> 4]));
    TexStageCombine(static_cast<eGDTextureStageCombineSource>(1), static_cast<eGDTextureStageCombineValue>(c[2] & 0xf));
    TexStageCombine(static_cast<eGDTextureStageCombineOperand>(2),
                    static_cast<eGDTextureStageCombineValue>(operands[c[3] >> 4]));
    TexStageCombine(static_cast<eGDTextureStageCombineSource>(2), static_cast<eGDTextureStageCombineValue>(c[3] & 0xf));
    TexStageCombine(static_cast<eGDTextureStageCombineMode>(1), static_cast<eGDTextureStageCombineValue>(c[4]));
    TexStageCombine(static_cast<eGDTextureStageCombineScale>(1), static_cast<eGDTextureStageCombineValue>(c[9]));
    TexStageCombine(static_cast<eGDTextureStageCombineOperand>(4),
                    static_cast<eGDTextureStageCombineValue>(operands[4 + (c[5] >> 4)]));
    TexStageCombine(static_cast<eGDTextureStageCombineSource>(4), static_cast<eGDTextureStageCombineValue>(c[5] & 0xf));
    TexStageCombine(static_cast<eGDTextureStageCombineOperand>(5),
                    static_cast<eGDTextureStageCombineValue>(operands[4 + (c[6] >> 4)]));
    TexStageCombine(static_cast<eGDTextureStageCombineSource>(5), static_cast<eGDTextureStageCombineValue>(c[6] & 0xf));
    TexStageCombine(static_cast<eGDTextureStageCombineOperand>(6),
                    static_cast<eGDTextureStageCombineValue>(operands[4 + (c[7] >> 4)]));
    TexStageCombine(static_cast<eGDTextureStageCombineSource>(6), static_cast<eGDTextureStageCombineValue>(c[7] & 0xf));
}
