// The graphics driver interface: a fixed-function rendering API close to OpenGL 1.x, implemented by the OpenGL,
// DirectX and software drivers. Everything that draws goes through it, so it is also where the native port puts its
// own renderer.
//
// Slot order checked against the original: each slot's argument bytes agree with the "ret N" of all three drivers,
// and the OpenGL driver's slots call the GL function of their name. The compiler lays a run of overloads out in
// reverse declaration order (TexEnv, Fog, TexStageCombine, MakeVertexFormat, GetVideoModeInfo, SetViewport).
// Unlike the framework's interfaces, this one has a vtable of its own in the original (every slot _purecall).
#ifndef OB_ENGINE_CIGZGDRIVER_H
#define OB_ENGINE_CIGZGDRIVER_H

#include "common/types.h"
#include "gzcom/cIGZUnknown.h"

static const uint32_t GZIID_cIGZGDriver = 0xa4554849;

struct sGDMode;
class cGDCombiner;

// The four kinds of texture-stage combiner setting (each its own type, so each is its own overload).
enum eGDTextureStageCombineMode { kGDTextureStageCombineModeDummy };
enum eGDTextureStageCombineSource { kGDTextureStageCombineSourceDummy };
enum eGDTextureStageCombineOperand { kGDTextureStageCombineOperandDummy };
enum eGDTextureStageCombineScale { kGDTextureStageCombineScaleDummy };
enum eGDTextureStageCombineValue { kGDTextureStageCombineValueDummy };

// VTABLE: 0x00ac3538
// SIZE 0x4
class cIGZGDriver : public cIGZUnknown {
public:
    // Drawing
    virtual void DrawArrays(uint32_t primitive, int32_t first, int32_t count) = 0;
    virtual void DrawElements(uint32_t primitive, int32_t count, uint32_t indexType, const void* indices) = 0;
    virtual void InterleavedArrays(uint32_t vertexFormat, int32_t stride, const void* vertices) = 0;

    // Vertex formats
    virtual uint32_t MakeVertexFormat(uint32_t elementCount, const uint32_t* elementTypes) = 0;
    virtual uint32_t MakeVertexFormat(uint32_t vertexFormat) = 0;
    virtual uint32_t VertexFormatStride(uint32_t vertexFormat) = 0;
    virtual uint32_t VertexFormatElementOffset(uint32_t vertexFormat, uint32_t elementType, uint32_t index) = 0;
    virtual uint32_t VertexFormatNumElements(uint32_t vertexFormat, uint32_t elementType) = 0;

    // Frame buffer state
    virtual void Clear(uint32_t buffers) = 0;
    virtual void ClearColor(float red, float green, float blue, float alpha) = 0;
    virtual void ClearDepth(double depth) = 0;
    virtual void ClearStencil(int32_t value) = 0;
    virtual void ColorMask(bool write) = 0;
    virtual void DepthFunc(uint32_t test) = 0;
    virtual void DepthMask(bool write) = 0;
    virtual void StencilFunc(uint32_t test, int32_t reference, uint32_t mask) = 0;
    virtual void StencilMask(uint32_t mask) = 0;
    virtual void StencilOp(uint32_t fail, uint32_t depthFail, uint32_t pass) = 0;
    virtual void BlendFunc(uint32_t source, uint32_t destination) = 0;
    virtual void AlphaFunc(uint32_t test, float reference) = 0;
    virtual void ShadeModel(uint32_t model) = 0;

    // Textures
    virtual void BindTexture(uint32_t target, uint32_t texture) = 0;
    virtual void TexImage2D(uint32_t target, int32_t level, int32_t internalFormat, int32_t width, int32_t height,
                            int32_t border, uint32_t format, uint32_t type, const void* pixels) = 0;
    virtual void PixelStore(uint32_t parameter, int32_t value) = 0;
    virtual void TexEnv(uint32_t target, uint32_t parameter, int32_t value) = 0;
    virtual void TexEnv(uint32_t target, uint32_t parameter, const float* values) = 0;
    virtual void TexParameter(uint32_t target, uint32_t parameter, int32_t value) = 0;
    virtual void Fog(uint32_t parameter, uint32_t value) = 0;
    virtual void Fog(uint32_t parameter, const float* values) = 0;
    virtual void ColorMultiplier(float red, float green, float blue) = 0;
    virtual void AlphaMultiplier(float alpha) = 0;
    virtual void EnableVertexColors(bool diffuse, bool specular) = 0;
    virtual void GenTextures(int32_t count, uint32_t* textures) = 0;
    virtual void DeleteTextures(int32_t count, const uint32_t* textures) = 0;
    virtual bool IsTexture(uint32_t texture) = 0;
    virtual void PrioritizeTextures(int32_t count, const uint32_t* textures, const float* priorities) = 0;
    virtual bool AreTexturesResident(int32_t count, const uint32_t* textures, bool* resident) = 0;

    // Matrices and state
    virtual void MatrixMode(uint32_t mode) = 0;
    virtual void LoadMatrix(const float* matrix) = 0;
    virtual void LoadIdentity() = 0;
    virtual void Flush() = 0;
    virtual void Enable(uint32_t state) = 0;
    virtual void Disable(uint32_t state) = 0;
    virtual bool IsEnabled(uint32_t state) = 0;
    virtual void GetBoolean(uint32_t parameter, bool* values) = 0;
    virtual void GetInteger(uint32_t parameter, int32_t* values) = 0;
    virtual void GetFloat(uint32_t parameter, float* values) = 0;
    virtual uint32_t GetError() = 0;

    // Texture stages
    virtual void TexStage(uint32_t stage) = 0;
    virtual void TexStageCoord(uint32_t source) = 0;
    virtual void TexStageMatrix(const float* matrix, uint32_t dimensions, uint32_t unused, uint32_t flags) = 0;
    virtual void TexStageCombine(eGDTextureStageCombineMode parameter, eGDTextureStageCombineValue value) = 0;
    virtual void TexStageCombine(eGDTextureStageCombineSource parameter, eGDTextureStageCombineValue value) = 0;
    virtual void TexStageCombine(eGDTextureStageCombineOperand parameter, eGDTextureStageCombineValue value) = 0;
    virtual void TexStageCombine(eGDTextureStageCombineScale parameter, eGDTextureStageCombineValue value) = 0;

    // Driver-managed textures
    virtual void SetTexture(uint32_t texture, uint32_t stage) = 0;
    virtual uint32_t GetTexture(uint32_t stage) = 0;
    virtual uint32_t CreateTexture(uint32_t internalFormat, uint32_t width, uint32_t height, uint32_t levels,
                                   uint32_t hints) = 0;
    virtual void LoadTextureLevel(uint32_t texture, int32_t level, int32_t x, int32_t y, int32_t width, int32_t height,
                                  uint32_t format, uint32_t type, uint32_t rowLength, const void* pixels) = 0;
    virtual void SetCombiner(const cGDCombiner& combiner, uint32_t stage) = 0;

    // Video modes
    virtual uint32_t CountVideoModes() const = 0;
    virtual void GetVideoModeInfo(uint32_t index, sGDMode& mode) = 0;
    virtual void GetVideoModeInfo(sGDMode& mode) = 0;
    virtual void SetVideoMode(int32_t index, void* window, bool fullScreen, bool force) = 0;
    virtual void PolygonOffset(int32_t offset) = 0;

    // Blits
    virtual void BitBlt(int32_t x, int32_t y, int32_t width, int32_t height, uint32_t format, uint32_t type,
                        const void* pixels, bool colorKeyed, const void* colorKey) = 0;
    virtual void StretchBlt(int32_t x, int32_t y, int32_t width, int32_t height, int32_t sourceWidth,
                            int32_t sourceHeight, uint32_t format, uint32_t type, const void* pixels, bool colorKeyed,
                            const void* colorKey) = 0;
    virtual void BitBltAlpha(int32_t x, int32_t y, int32_t width, int32_t height, uint32_t format, uint32_t type,
                             const void* pixels, bool colorKeyed, const void* colorKey, uint32_t alpha) = 0;
    virtual void StretchBltAlpha(int32_t x, int32_t y, int32_t width, int32_t height, int32_t sourceWidth,
                                 int32_t sourceHeight, uint32_t format, uint32_t type, const void* pixels,
                                 bool colorKeyed, const void* colorKey, uint32_t alpha) = 0;
    virtual void BitBltAlphaModulate(int32_t x, int32_t y, int32_t width, int32_t height, uint32_t format,
                                     uint32_t type, const void* pixels, bool colorKeyed, const void* colorKey,
                                     uint32_t alpha) = 0;
    virtual void StretchBltAlphaModulate(int32_t x, int32_t y, int32_t width, int32_t height, int32_t sourceWidth,
                                         int32_t sourceHeight, uint32_t format, uint32_t type, const void* pixels,
                                         bool colorKeyed, const void* colorKey, uint32_t alpha) = 0;

    // Viewport and the driver itself
    virtual void SetViewport() = 0;
    virtual void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) = 0;
    virtual void GetViewport(int32_t* viewport) = 0;
    virtual const char* GetDriverInfo() const = 0;
    virtual uint32_t GetGZCLSID() const = 0;
    virtual bool Init() = 0;
    virtual bool Shutdown() = 0;
    virtual bool IsDeviceReady() = 0;
    virtual bool Punt(uint32_t message, void* data) = 0;
};

#endif
