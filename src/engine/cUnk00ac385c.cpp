// The OpenGL graphics driver: the graphics driver interface (engine/cIGZGDriver.h) on OpenGL 1.1, each call
// translated through a table from the interface's values to OpenGL's.
#include "classes/cUnk00ac385c.h"
#include "engine/gl.h"

// The translation tables, in the order the original keeps them (its data from 0x00b12010).
static GLenum sDataTypes[8] = {GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT, GL_UNSIGNED_SHORT, GL_INT, GL_UNSIGNED_INT, GL_FLOAT,
                               GL_DOUBLE};
static GLenum sPrimitives[8] = {GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_POINTS, GL_LINES, GL_LINE_STRIP,
                                GL_QUADS, GL_QUAD_STRIP};
static GLenum sCompareFuncs[8] = {GL_NEVER, GL_LESS, GL_EQUAL, GL_LEQUAL, GL_GREATER, GL_NOTEQUAL, GL_GEQUAL, GL_ALWAYS};
static GLenum sBlendFactors[11] = {GL_ZERO, GL_ONE, GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR, GL_SRC_ALPHA,
                                   GL_ONE_MINUS_SRC_ALPHA, GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_DST_COLOR,
                                   GL_ONE_MINUS_DST_COLOR, GL_SRC_ALPHA_SATURATE};
static GLenum sStencilOps[6] = {GL_ZERO, GL_KEEP, GL_REPLACE, GL_INCR, GL_DECR, GL_INVERT};
static GLenum sShadeModels[2] = {GL_FLAT, GL_SMOOTH};
static GLenum sMatrixModes[2] = {GL_MODELVIEW, GL_PROJECTION};
static GLenum sTextureTargets[1] = {GL_TEXTURE_2D};
static GLenum sFogParameters[6] = {GL_FOG_MODE, GL_FOG_COLOR, GL_FOG_DENSITY, GL_FOG_START, GL_FOG_END,
                                   GL_FOG_COORDINATE_SOURCE_EXT};
static GLenum sTexEnvTargets[1] = {GL_TEXTURE_ENV};
static GLenum sTexEnvParameters[2] = {GL_TEXTURE_ENV_MODE, GL_TEXTURE_ENV_COLOR};
static GLenum sTexEnvModes[6] = {GL_REPLACE, GL_MODULATE, GL_DECAL, GL_BLEND, GL_COMBINE_ARB, GL_COMBINE4_NV};
static GLenum sTexParameters[4] = {GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T};
static GLenum sTexParameterValues[8] = {GL_NEAREST, GL_LINEAR, GL_CLAMP, GL_REPEAT, GL_NEAREST_MIPMAP_NEAREST,
                                        GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR};
static GLenum sFogModes[4] = {GL_EXP, GL_EXP2, GL_LINEAR, GL_FOG_COORDINATE_EXT};
static GLenum sCapabilities[7] = {GL_ALPHA_TEST, GL_DEPTH_TEST, GL_STENCIL_TEST, GL_CULL_FACE, GL_BLEND, GL_TEXTURE_2D,
                                  GL_FOG};
static GLenum sCombineModes[2] = {GL_COMBINE_RGB_ARB, GL_COMBINE_ALPHA_ARB};
static GLenum sCombineValues[6] = {GL_REPLACE, GL_MODULATE, GL_ADD, GL_ADD_SIGNED_ARB, GL_INTERPOLATE_ARB, GL_DOT3_RGB_EXT};
static GLenum sCombineSources[8] = {GL_SOURCE0_RGB_ARB, GL_SOURCE1_RGB_ARB, GL_SOURCE2_RGB_ARB, GL_SOURCE3_RGB_NV,
                                    GL_SOURCE0_ALPHA_ARB, GL_SOURCE1_ALPHA_ARB, GL_SOURCE2_ALPHA_ARB, GL_SOURCE3_ALPHA_NV};
static GLenum sCombineSourceValues[4] = {GL_TEXTURE, GL_PREVIOUS_ARB, GL_CONSTANT_ARB, GL_PRIMARY_COLOR_ARB};
static GLenum sCombineOperands[8] = {GL_OPERAND0_RGB_ARB, GL_OPERAND1_RGB_ARB, GL_OPERAND2_RGB_ARB, GL_OPERAND3_RGB_NV,
                                     GL_OPERAND0_ALPHA_ARB, GL_OPERAND1_ALPHA_ARB, GL_OPERAND2_ALPHA_ARB,
                                     GL_OPERAND3_ALPHA_NV};
static GLenum sCombineScales[2] = {GL_RGB_SCALE_ARB, GL_ALPHA_SCALE};
static GLfloat sCombineScaleValues[3] = {1.0f, 2.0f, 4.0f};
static GLenum sParameters[1] = {GL_UNPACK_ROW_LENGTH};

// The buffer-region extension, as the original looked it up (wglGetProcAddress) into its own pointers.
typedef void(OB_GLCALL* tDeleteBufferRegion)(GLuint region);
typedef void(OB_GLCALL* tReadBufferRegion)(GLuint region, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void(OB_GLCALL* tDrawBufferRegion)(GLuint region, GLint x, GLint y, GLsizei width, GLsizei height,
                                           GLint xDest, GLint yDest);
// GLOBAL: 0x00b541c4
extern tDeleteBufferRegion gpDeleteBufferRegion;
typedef GLuint(OB_GLCALL* tNewBufferRegion)(GLenum type);
// GLOBAL: 0x00b541c0
extern tNewBufferRegion gpNewBufferRegion;
typedef GLuint(OB_GLCALL* tBufferRegionEnabled)();
// GLOBAL: 0x00b541c8
extern tReadBufferRegion gpReadBufferRegion;
// GLOBAL: 0x00b541cc
extern tDrawBufferRegion gpDrawBufferRegion;
// GLOBAL: 0x00b541d0
extern tBufferRegionEnabled gpBufferRegionEnabled;

// Multitexturing (ARB_multitexture), looked up the same way.
typedef void(OB_GLCALL* tActiveTexture)(GLenum texture);
// GLOBAL: 0x00b54108
extern tActiveTexture gpActiveTexture;

// The name of the driver's window class.
// GLOBAL: 0x00b12260
extern const char* gpszWindowClass;

// The OpenGL driver, once its window is created.
// GLOBAL: 0x00b541f0
extern cUnk00ac385c* gpOpenGLDriver;

// The driver window's procedure.
// STUB: 0x0087ee10
long OB_STDCALL Fn0087ee10(void* window, unsigned int message, unsigned int wParam, long lParam);

// The vertex formats are the engine's, shared by every driver.
// STUB: 0x008d01f0
uint32_t Fn008d01f0(uint32_t format);
// STUB: 0x008d02c0
uint32_t Fn008d02c0(uint32_t elementCount, const uint32_t* elementTypes);
// STUB: 0x008d04a0
uint32_t Fn008d04a0(uint32_t format, uint32_t elementType, uint32_t index);
// STUB: 0x008d0370
uint32_t Fn008d0370(uint32_t format);
// STUB: 0x008d04f0
uint32_t Fn008d04f0(uint32_t format, uint32_t elementType);

// FUNCTION: 0x0087c520
void cUnk00ac385c::ClearDepth(double depth)
{
    glClearDepth(depth);
}

// FUNCTION: 0x0087c550
void cUnk00ac385c::DepthFunc(unsigned int func)
{
    glDepthFunc(sCompareFuncs[func]);
}

// FUNCTION: 0x0087c570
void cUnk00ac385c::ColorMask(bool mask)
{
    glColorMask(mask, mask, mask, mask);
}

// FUNCTION: 0x0087c5d0
void cUnk00ac385c::StencilMask(unsigned int mask)
{
    if (mbStencil) {
        glStencilMask(mask);
    }
}

// FUNCTION: 0x0087c660
void cUnk00ac385c::AlphaFunc(unsigned int func, float ref)
{
    glAlphaFunc(sCompareFuncs[func], ref);
}

// FUNCTION: 0x0087c680
void cUnk00ac385c::ShadeModel(unsigned int model)
{
    glShadeModel(sShadeModels[model]);
}

// FUNCTION: 0x0087c6a0
void cUnk00ac385c::BindTexture(unsigned int target, unsigned int texture)
{
    glBindTexture(sTextureTargets[target], texture);
}

// FUNCTION: 0x0087c740
void cUnk00ac385c::PixelStore(unsigned int name, int value)
{
    glPixelStorei(sParameters[name], value);
}

// FUNCTION: 0x0087cc20
void cUnk00ac385c::Fog(unsigned int name, const float* values)
{
    glFogfv(sFogParameters[name], values);
}

// FUNCTION: 0x0087cdd0
bool cUnk00ac385c::IsTexture(unsigned int texture)
{
    return glIsTexture(texture) != 0;
}

// FUNCTION: 0x0087ce20
void cUnk00ac385c::MatrixMode(unsigned int mode)
{
    glMatrixMode(sMatrixModes[mode]);
}

// FUNCTION: 0x0087cee0
void cUnk00ac385c::GetBoolean(unsigned int name, bool* values)
{
    glGetBooleanv(sParameters[name], reinterpret_cast<GLboolean*>(values));
}

// FUNCTION: 0x0087cf00
void cUnk00ac385c::GetInteger(unsigned int name, int* values)
{
    glGetIntegerv(sParameters[name], values);
}

// FUNCTION: 0x0087cf20
void cUnk00ac385c::GetFloat(unsigned int name, float* values)
{
    glGetFloatv(sParameters[name], values);
}

// FUNCTION: 0x0087d2c0
bool cUnk00ac385c::Slot05_ac34cc(uint32_t region)
{
    gpDeleteBufferRegion(region);
    return true;
}

// The bitmap transfers are not supported by this driver: each one only records the error.
// FUNCTION: 0x0087d5c0
void cUnk00ac385c::BitBlt(int, int, int, int, unsigned int, unsigned int, const void*, bool, const void*)
{
    mnLastError = 3;
}

// FUNCTION: 0x0087d5d0
void cUnk00ac385c::StretchBlt(int, int, int, int, int, int, unsigned int, unsigned int, const void*, bool, const void*)
{
    mnLastError = 3;
}

// FUNCTION: 0x0087d5e0
void cUnk00ac385c::BitBltAlpha(int, int, int, int, unsigned int, unsigned int, const void*, bool, const void*,
                               unsigned int)
{
    mnLastError = 3;
}

// FUNCTION: 0x0087d5f0
void cUnk00ac385c::StretchBltAlpha(int, int, int, int, int, int, unsigned int, unsigned int, const void*, bool,
                                   const void*, unsigned int)
{
    mnLastError = 3;
}

// FUNCTION: 0x0087d860
void cUnk00ac385c::AlphaMultiplier(float alpha)
{
    mfAlphaMultiplier = alpha;
    Fn0087cc40();
}

// FUNCTION: 0x008da980
unsigned int cUnk00ac385c::MakeVertexFormat(unsigned int format)
{
    return Fn008d01f0(format);
}

// FUNCTION: 0x008da990
unsigned int cUnk00ac385c::VertexFormatStride(unsigned int format)
{
    return Fn008d0370(format);
}

// FUNCTION: 0x00881f30
unsigned int cUnk00ac385c::MakeVertexFormat(unsigned int elementCount, const unsigned int* elementTypes)
{
    return Fn008d02c0(elementCount, elementTypes);
}

// FUNCTION: 0x00881f50
unsigned int cUnk00ac385c::VertexFormatNumElements(unsigned int format, unsigned int elementType)
{
    return Fn008d04f0(format, elementType);
}

// FUNCTION: 0x0087c4c0
unsigned int cUnk00ac385c::VertexFormatElementOffset(unsigned int format, unsigned int elementType, unsigned int index)
{
    return Fn008d04a0(format, elementType, index);
}

// FUNCTION: 0x0087c5a0
void cUnk00ac385c::StencilFunc(unsigned int func, int ref, unsigned int mask)
{
    if (mbStencil) {
        glStencilFunc(sCompareFuncs[func], ref, mask);
    }
}

// FUNCTION: 0x0087c630
void cUnk00ac385c::BlendFunc(unsigned int source, unsigned int destination)
{
    glBlendFunc(sBlendFactors[source], sBlendFactors[destination]);
}

// FUNCTION: 0x0087c7a0
void cUnk00ac385c::TexEnv(unsigned int target, unsigned int name, const float* values)
{
    glTexEnvfv(sTexEnvTargets[target], sTexEnvParameters[name], values);
}

// FUNCTION: 0x0087cbf0
void cUnk00ac385c::Fog(unsigned int name, unsigned int value)
{
    glFogi(sFogParameters[name], sFogModes[value]);
}

// FUNCTION: 0x0087ce00
bool cUnk00ac385c::AreTexturesResident(int count, const unsigned int* textures, bool* resident)
{
    return glAreTexturesResident(count, textures, reinterpret_cast<GLboolean*>(resident)) != 0;
}

// FUNCTION: 0x0087cec0
bool cUnk00ac385c::IsEnabled(unsigned int capability)
{
    GLenum cap = sCapabilities[capability];
    return glIsEnabled(cap) != 0;
}

// FUNCTION: 0x0087d230
void cUnk00ac385c::PolygonOffset(int units)
{
    glPolygonOffset(0.0f, static_cast<float>(static_cast<uint32_t>(units)));
}

// FUNCTION: 0x0087d260
uint32_t cUnk00ac385c::Slot03_ac34cc()
{
    if (gpBufferRegionEnabled && gpBufferRegionEnabled()) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x0087d330
void cUnk00ac385c::Slot03_ac3508(bool on)
{
    if (on) {
        glEnable(GL_LIGHTING);
    } else {
        glDisable(GL_LIGHTING);
    }
}

// FUNCTION: 0x0087d750
uint32_t cUnk00ac385c::Slot11_ac385c()
{
    Shutdown();
    delete this;
    return 0;
}

// The driver window's class (the start of a WNDCLASSA): redrawn whole on resizing, its own device context.
struct sWindowClass_ac385c {
    uint32_t mnStyle;
    long(OB_STDCALL* mpProcedure)(void*, unsigned int, unsigned int, long);
    uint32_t mnUnused[7];
    const char* mpszName;
};

// FUNCTION: 0x0087f120
uint32_t cUnk00ac385c::Slot04_ac3684(void* windowClass)
{
    sWindowClass_ac385c* wc = static_cast<sWindowClass_ac385c*>(windowClass);
    const char* name = gpszWindowClass;
    wc->mnStyle = 0x23;
    wc->mpProcedure = Fn0087ee10;
    wc->mpszName = name;
    return 1;
}

// FUNCTION: 0x0087c4e0
void cUnk00ac385c::Clear(unsigned int buffers)
{
    glClear((((buffers >> 1) & 0x800) | (buffers & 0x2000)) >> 3 | (buffers & 0x4000));
}

// FUNCTION: 0x0087c810
void cUnk00ac385c::SetTexture(unsigned int texture, unsigned int stage)
{
    gpActiveTexture(GL_TEXTURE0_ARB + stage);
    glBindTexture(sTextureTargets[0], texture);
}

// FUNCTION: 0x0087c840
unsigned int cUnk00ac385c::GetTexture(unsigned int stage)
{
    gpActiveTexture(GL_TEXTURE0_ARB + stage);
    GLint texture;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &texture);
    return texture;
}

// FUNCTION: 0x0087d2d0
bool cUnk00ac385c::Slot06_ac34cc(uint32_t region, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t,
                                 uint32_t)
{
    gpReadBufferRegion(region, x, y, width, height);
    return true;
}

// FUNCTION: 0x0087d300
bool cUnk00ac385c::Slot07_ac34cc(uint32_t region, uint32_t x, uint32_t y, uint32_t width, uint32_t height,
                                 uint32_t xDest, uint32_t yDest)
{
    gpDrawBufferRegion(region, x, y, width, height, xDest, yDest);
    return true;
}

// FUNCTION: 0x0087d600
void cUnk00ac385c::SetViewport()
{
    glViewport(0, 0, mnWidth, mnHeight);
    glDisable(GL_SCISSOR_TEST);
}

// FUNCTION: 0x0087d830
void cUnk00ac385c::ColorMultiplier(float red, float green, float blue)
{
    mfRedMultiplier = red;
    mfGreenMultiplier = green;
    mfBlueMultiplier = blue;
    Fn0087cc40();
}

// FUNCTION: 0x0087ed20
void cUnk00ac385c::Flush()
{
    glFlush();
    if (mbDoubleBuffer) {
        void* dc = wglGetCurrentDC();
        if (dc) {
            SwapBuffers(dc);
        }
    }
}

// FUNCTION: 0x0087c760
void cUnk00ac385c::TexEnv(unsigned int target, unsigned int name, int value)
{
    glTexEnvi(sTexEnvTargets[target], sTexEnvParameters[name], sTexEnvModes[value]);
}

// FUNCTION: 0x0087c7d0
void cUnk00ac385c::TexParameter(unsigned int target, unsigned int name, int value)
{
    glTexParameteri(sTextureTargets[target], sTexParameters[name], sTexParameterValues[value]);
}

// FUNCTION: 0x0087cf40
unsigned int cUnk00ac385c::GetError()
{
    uint32_t error = mnLastError;
    mnLastError = 0;
    if (mbIgnoreGLError) {
        mbIgnoreGLError = false;
    } else if (error == 0) {
        error = glGetError();
    } else {
        glGetError();
    }
    if (error == 0) {
        return 0;
    }
    return error - 0x4ff;
}

// FUNCTION: 0x0087cf80
void cUnk00ac385c::TexStage(unsigned int stage)
{
    if (mbMultitexture || stage != 0) {
        if (stage >= mnStageCount) {
            mnLastError = GL_INVALID_VALUE;
        } else {
            mnStage = stage;
            gpActiveTexture(GL_TEXTURE0_ARB + stage);
        }
    }
}

// FUNCTION: 0x0087d280
uint32_t cUnk00ac385c::Slot04_ac34cc(uint32_t type)
{
    uint32_t region = 0;
    if (gpNewBufferRegion) {
        switch (type) {
        case 0:
            region = gpNewBufferRegion(1);
            break;
        case 1:
            region = gpNewBufferRegion(2);
            break;
        case 2:
            region = gpNewBufferRegion(3);
            break;
        }
    }
    return region;
}

// FUNCTION: 0x0087d350
void cUnk00ac385c::Slot04_ac3508(uint32_t light, bool on)
{
    if (on) {
        glEnable(GL_LIGHT0 + light);
    } else {
        glDisable(GL_LIGHT0 + light);
    }
}

// FUNCTION: 0x0087d380
void cUnk00ac385c::Slot05_ac3508(float a, float b, float c, float d)
{
    float ambient[4] = {a, c, b, d};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
}

// FUNCTION: 0x0087d630
void cUnk00ac385c::SetViewport(int x, int y, int width, int height)
{
    glViewport(x, y, width, height);
    glScissor(x, y, width, height);
    glEnable(GL_SCISSOR_TEST);
}

// The driver window's creation parameters (a CREATESTRUCTA): 800 by 600, clipping its children and siblings.
struct sWindowCreate_ac385c {
    uint32_t mnUnused[4];
    int32_t mnHeight;
    int32_t mnWidth;
    uint32_t mnUnused18[2];
    uint32_t mnStyle;
    const char* mpszName;
    const char* mpszClass;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0087f0e0 score 6 (the original reads, ors and writes the style through a register; ours ors in memory)
uint32_t cUnk00ac385c::Slot03_ac3684(void* create)
{
    sWindowCreate_ac385c* cs = static_cast<sWindowCreate_ac385c*>(create);
    cs->mpszClass = gpszWindowClass;
    cs->mnStyle |= 0x6080000;
    cs->mnWidth = 800;
    cs->mnHeight = 600;
    gpOpenGLDriver = this;
    return 1;
}
#endif

// FUNCTION: 0x0087c330
void cUnk00ac385c::DrawArrays(unsigned int primitive, int first, int count)
{
    Fn0087c240();
    Fn0087c1b0(first, count);
    glDrawArrays(sPrimitives[primitive], first, count);
    glGetError();
    Fn0087c1b0(first, count);
}

// FUNCTION: 0x0087c5f0
void cUnk00ac385c::StencilOp(unsigned int fail, unsigned int depthFail, unsigned int pass)
{
    if (mbStencil) {
        glStencilOp(sStencilOps[fail], sStencilOps[depthFail], sStencilOps[pass]);
    }
}

// FUNCTION: 0x0087d130
void cUnk00ac385c::TexStageCombine(eGDTextureStageCombineMode mode, eGDTextureStageCombineValue value)
{
    if (!mbCombine) {
        mnLastError = GL_INVALID_VALUE;
        return;
    }
    glTexEnvi(sTexEnvTargets[0], sCombineModes[mode], sCombineValues[value]);
}

// The viewport as its corners: left, top, right, bottom.
#ifdef OB_DRAFTS
// CLOSE: 0x0087dab0 score 27 (the original keeps the pointer in ebx and computes both sums before storing)
void cUnk00ac385c::GetViewport(int* corners)
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    int left = viewport[0];
    int top = viewport[1];
    int right = viewport[2] + left;
    int bottom = viewport[3] + top;
    corners[0] = left;
    corners[1] = top;
    corners[2] = right;
    corners[3] = bottom;
}
#endif

// FUNCTION: 0x0087d170
void cUnk00ac385c::TexStageCombine(eGDTextureStageCombineSource source, eGDTextureStageCombineValue value)
{
    if (!mbCombine) {
        mnLastError = GL_INVALID_VALUE;
        return;
    }
    glTexEnvi(sTexEnvTargets[0], sCombineSources[source], sCombineSourceValues[value]);
}

// FUNCTION: 0x0087d1b0
void cUnk00ac385c::TexStageCombine(eGDTextureStageCombineOperand operand, eGDTextureStageCombineValue value)
{
    if (!mbCombine) {
        mnLastError = GL_INVALID_VALUE;
        return;
    }
    glTexEnvi(sTexEnvTargets[0], sCombineOperands[operand], sBlendFactors[value]);
}

// FUNCTION: 0x0087d1f0
void cUnk00ac385c::TexStageCombine(eGDTextureStageCombineScale scale, eGDTextureStageCombineValue value)
{
    if (!mbCombine) {
        mnLastError = GL_INVALID_VALUE;
        return;
    }
    glTexEnvfv(sTexEnvTargets[0], sCombineScales[scale], &sCombineScaleValues[value]);
}

// FUNCTION: 0x0087de80
void cUnk00ac385c::DrawElements(unsigned int primitive, int count, unsigned int indexType, const void* indices)
{
    Fn0087c240();
    Fn0087dca0(count, indexType, indices);
    glDrawElements(sPrimitives[primitive], count, sDataTypes[indexType], indices);
    Fn0087dca0(count, indexType, indices);
}

// A light's colours, each one set when given. The original passes the ambient colour for all three (its bug, kept).
// FUNCTION: 0x0087d430
void cUnk00ac385c::Slot06_ac3508(uint32_t light, const void* ambient, const void* diffuse, const void* specular)
{
    if (ambient) {
        glLightfv(GL_LIGHT0 + light, GL_AMBIENT, static_cast<const GLfloat*>(ambient));
    }
    if (diffuse) {
        glLightfv(GL_LIGHT0 + light, GL_DIFFUSE, static_cast<const GLfloat*>(ambient));
    }
    if (specular) {
        glLightfv(GL_LIGHT0 + light, GL_SPECULAR, static_cast<const GLfloat*>(ambient));
    }
}
