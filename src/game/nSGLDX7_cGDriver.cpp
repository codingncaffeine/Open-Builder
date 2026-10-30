#include <cmath>
#include <cstddef>
#include <cstring>

#include "classes/nSGLDX7_cGDriver.h"
#include "common/winapi.h"
#include "game/Globals.h"

// The helpers the original keeps out of line (their callers call them): the 2003 compiler would inline them here.
#ifdef _MSC_VER
#define NOINLINE_ac47ec __declspec(noinline)
#define STDCALL_ac47ec __stdcall
#else
#define NOINLINE_ac47ec
#define STDCALL_ac47ec
#endif

// The embedded object at +0x10 (cUnk00ace624), its slot 0 is the deleting destructor (flag 1 = delete).
struct Deleter_ac47ec {
    virtual void Destroy(uint32_t flags);
};

// A COM object seen through its three base slots (the callee pops, the object pushed last).
struct Unknown_ac47ec {
    virtual uint32_t STDCALL_ac47ec QueryInterface(const void* iid, void** object);
    virtual uint32_t STDCALL_ac47ec AddRef();
    virtual uint32_t STDCALL_ac47ec Release();
};

// The Direct3D 7 device (IDirect3DDevice7): the slot numbers are the interface's.
struct Device7_ac47ec {
    virtual uint32_t STDCALL_ac47ec QueryInterface(const void* iid, void** object);
    virtual uint32_t STDCALL_ac47ec AddRef();
    virtual uint32_t STDCALL_ac47ec Release();
    virtual uint32_t STDCALL_ac47ec GetCaps(void* caps);
    virtual uint32_t STDCALL_ac47ec EnumTextureFormats(void* callback, void* context);
    virtual uint32_t STDCALL_ac47ec BeginScene();
    virtual uint32_t STDCALL_ac47ec EndScene();
    virtual uint32_t STDCALL_ac47ec GetDirect3D(void** d3d);
    virtual uint32_t STDCALL_ac47ec SetRenderTarget(void* surface, uint32_t flags);
    virtual uint32_t STDCALL_ac47ec GetRenderTarget(void** surface);
    virtual uint32_t STDCALL_ac47ec Clear(uint32_t count, const void* rects, uint32_t flags, uint32_t color, float z, uint32_t stencil);
    virtual uint32_t STDCALL_ac47ec SetTransform(uint32_t state, const void* matrix);
    virtual uint32_t STDCALL_ac47ec GetTransform(uint32_t state, void* matrix);
    virtual uint32_t STDCALL_ac47ec SetViewport(const void* viewport);
    virtual uint32_t STDCALL_ac47ec MultiplyTransform(uint32_t state, const void* matrix);
    virtual uint32_t STDCALL_ac47ec GetViewport(void* viewport);
    virtual uint32_t STDCALL_ac47ec SetMaterial(const void* material);
    virtual uint32_t STDCALL_ac47ec GetMaterial(void* material);
    virtual uint32_t STDCALL_ac47ec SetLight(uint32_t index, const void* light);
    virtual uint32_t STDCALL_ac47ec GetLight(uint32_t index, void* light);
    virtual uint32_t STDCALL_ac47ec SetRenderState(uint32_t state, uint32_t value);
    virtual uint32_t STDCALL_ac47ec GetRenderState(uint32_t state, uint32_t* value);
    virtual uint32_t STDCALL_ac47ec BeginStateBlock();
    virtual uint32_t STDCALL_ac47ec EndStateBlock(uint32_t* block);
    virtual uint32_t STDCALL_ac47ec PreLoad(void* texture);
    virtual uint32_t STDCALL_ac47ec DrawPrimitive(uint32_t type, uint32_t format, void* vertices, uint32_t count, uint32_t flags);
    virtual uint32_t STDCALL_ac47ec DrawIndexedPrimitive(uint32_t type, uint32_t format, void* vertices, uint32_t count, void* indices, uint32_t indexCount, uint32_t flags);
    virtual uint32_t STDCALL_ac47ec SetClipStatus(const void* status);
    virtual uint32_t STDCALL_ac47ec GetClipStatus(void* status);
    virtual uint32_t STDCALL_ac47ec DrawPrimitiveStrided(uint32_t type, uint32_t format, void* data, uint32_t count, uint32_t flags);
    virtual uint32_t STDCALL_ac47ec DrawIndexedPrimitiveStrided(uint32_t type, uint32_t format, void* data, uint32_t count, void* indices, uint32_t indexCount, uint32_t flags);
    virtual uint32_t STDCALL_ac47ec DrawPrimitiveVB(uint32_t type, void* buffer, uint32_t start, uint32_t count, uint32_t flags);
    virtual uint32_t STDCALL_ac47ec DrawIndexedPrimitiveVB(uint32_t type, void* buffer, uint32_t start, uint32_t count, void* indices, uint32_t indexCount, uint32_t flags);
    virtual uint32_t STDCALL_ac47ec ComputeSphereVisibility(void* centers, float* radii, uint32_t count, uint32_t flags, uint32_t* result);
    virtual uint32_t STDCALL_ac47ec GetTexture(uint32_t stage, void** texture);
    virtual uint32_t STDCALL_ac47ec SetTexture(uint32_t stage, void* texture);
    virtual uint32_t STDCALL_ac47ec GetTextureStageState(uint32_t stage, uint32_t type, uint32_t* value);
    virtual uint32_t STDCALL_ac47ec SetTextureStageState(uint32_t stage, uint32_t type, uint32_t value);
    virtual uint32_t STDCALL_ac47ec ValidateDevice(uint32_t* passes);
    virtual uint32_t STDCALL_ac47ec ApplyStateBlock(uint32_t block);
    virtual uint32_t STDCALL_ac47ec CaptureStateBlock(uint32_t block);
    virtual uint32_t STDCALL_ac47ec DeleteStateBlock(uint32_t block);
    virtual uint32_t STDCALL_ac47ec CreateStateBlock(uint32_t type, uint32_t* block);
    virtual uint32_t STDCALL_ac47ec Load(void* destination, void* destinationPoint, void* source, void* sourceRect, uint32_t flags);
    virtual uint32_t STDCALL_ac47ec LightEnable(uint32_t index, uint32_t enable);
    virtual uint32_t STDCALL_ac47ec GetLightEnable(uint32_t index, uint32_t* enable);
    virtual uint32_t STDCALL_ac47ec SetClipPlane(uint32_t index, float* plane);
    virtual uint32_t STDCALL_ac47ec GetClipPlane(uint32_t index, float* plane);
    virtual uint32_t STDCALL_ac47ec GetInfo(uint32_t id, void* info, uint32_t size);
};

struct TexMgr_ac47ec;

// One texture stage's record (0x80 bytes each, the stage index shifted left by 7).
struct Stage_ac47ec {
    uint8_t mbDirty;
    uint8_t mb01;
    uint8_t mb02;
    uint8_t mPad03;
    uint32_t mnTexture;
    uint32_t mn08;
    uint32_t mn0c;
    uint32_t mn10;
    uint32_t mn14;
    uint32_t mn18;
    uint32_t mnTexEnvMode;
    uint32_t mn20;
    uint32_t mn24;
    uint32_t mn28;
    uint32_t mn2c;
    uint32_t mn30;
    uint32_t mn34;
    uint32_t mn38;
    uint32_t mn3c;
    uint32_t mn40;
    uint32_t mn44;
    uint32_t mn48;
    uint32_t mn4c;
    uint32_t mn50;
    uint32_t mn54;
    uint32_t mn58;
    uint32_t mn5c;
    uint32_t mn60;
    uint8_t mPad64[0x80 - 0x64];
    // STUB: 0x00884320
    NOINLINE_ac47ec bool Fn00884320(uint32_t index, Device7_ac47ec* device, TexMgr_ac47ec* textures);
    bool Fn00884320Draft_ac47ec(uint32_t index, Device7_ac47ec* device, TexMgr_ac47ec* textures);
    NOINLINE_ac47ec void Fn00884500(uint32_t index, Device7_ac47ec* device);
    // STUB: 0x00882100
    NOINLINE_ac47ec void Fn00882100(uint32_t index, Device7_ac47ec* device);
    // STUB: 0x00882300
    NOINLINE_ac47ec void Fn00882300(uint32_t index, Device7_ac47ec* device);
};

// One recorded draw call of the primitive manager (0x14 bytes).
struct DrawRecord_ac47ec {
    uint32_t mnPrimitive;
    uint32_t mnStartVertex;
    uint32_t mnVertexCount;
    void* mpIndices;
    uint32_t mnIndexCount;
};

// The primitive manager's list of recorded draw calls (begin, end, capacity).
struct DrawList_ac47ec {
    DrawRecord_ac47ec* mpBegin;
    DrawRecord_ac47ec* mpEnd;
    DrawRecord_ac47ec* mpCap;
    // STUB: 0x00889b00
    NOINLINE_ac47ec void Fn00889b00();
};

// A vector of 16-bit indices (begin, end, capacity).
struct WordVec_ac47ec {
    uint16_t* mpBegin;
    uint16_t* mpEnd;
    uint16_t* mpCap;
    // STUB: 0x00465710
    void Fn00465710(uint32_t size, const uint16_t* value);
};

// The wrapper that holds the primitive manager's vertex buffer (the Direct3D buffer sits at +8).
struct VertexBufferHolder_ac47ec {
    uint8_t mPad[8];
    void* mpBuffer;
};

// The vertex buffer reference at +0x34 of the primitive manager: the holder and two more words.
struct VBRef_ac47ec {
    VertexBufferHolder_ac47ec* mpHolder;
    uint32_t mn04;
    uint32_t mn08;
    // STUB: 0x00889ce0
    NOINLINE_ac47ec void Fn00889ce0(VertexBufferHolder_ac47ec* holder, uint32_t value);
};

// The driver's primitive manager (nSGLDX7_cPrimitiveManager, class 0xac4f10; another task's class): only the fields
// and helpers this class's code needs are declared.
struct PrimMgr_ac47ec {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Slot11();
    uint8_t mPad04[0xc - 0x4];
    void* mp0c;
    void* mp10;
    Device7_ac47ec* mpDevice;
    DrawList_ac47ec mList;
    WordVec_ac47ec mIndices;
    uint32_t mn30;
    VBRef_ac47ec mVertexBuffer;
    // STUB: 0x00889bf0
    NOINLINE_ac47ec uint32_t Fn00889bf0();
    uint32_t Fn00889bf0Draft_ac47ec();
    NOINLINE_ac47ec uint32_t Fn00889de0();
    // STUB: 0x0088a1a0
    NOINLINE_ac47ec void Fn0088a1a0();
    void Fn0088a1a0Draft_ac47ec();
    // STUB: 0x0088a240
    NOINLINE_ac47ec uint16_t* Fn0088a240(uint32_t count);
    uint16_t* Fn0088a240Draft_ac47ec(uint32_t count);
    // STUB: 0x00889b60
    NOINLINE_ac47ec void Fn00889b60();
    NOINLINE_ac47ec void Fn00889260(void* a, void* b, Device7_ac47ec* device);
    // STUB: 0x00889e00
    NOINLINE_ac47ec uint32_t Fn00889e00(uint32_t format, uint32_t primitive, uint32_t stride, uint32_t start, uint32_t count, uint32_t vertices, uint32_t indexCount, uint16_t* indices);
};

// The DirectDraw surface object seen through the slots the driver uses (callee pops, object pushed last).
struct Surface7_ac47ec {
    virtual uint32_t STDCALL_ac47ec QueryInterface(const void* iid, void** object);
    virtual uint32_t STDCALL_ac47ec AddRef();
    virtual uint32_t STDCALL_ac47ec Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual uint32_t STDCALL_ac47ec GetAttachedSurface(const void* caps, Surface7_ac47ec** surface);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual uint32_t STDCALL_ac47ec Lock(const void* rect, void* desc, uint32_t flags, void* event);
    virtual void Pad26();
    virtual uint32_t STDCALL_ac47ec Restore();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual uint32_t STDCALL_ac47ec Unlock(const void* rect);
};

// The reference to a texture's surface (the texture record holds it at +0x2c).
struct SurfaceRef_ac47ec {
    Unknown_ac47ec* mp;
    // STUB: 0x008846d0
    NOINLINE_ac47ec uint32_t Fn008846d0();
};

// One texture of the texture manager (0x30 bytes).
struct Tex_ac47ec {
    bool mbUsed;
    uint8_t mPad01[3];
    uint32_t mnWidth;
    uint32_t mnHeight;
    uint32_t mnLevels;
    float mfPriority;
    uint32_t mnFormat;
    uint32_t mnHints;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
    uint32_t mn28;
    Unknown_ac47ec* mpSurface;
    NOINLINE_ac47ec Tex_ac47ec* Fn0088a810(const Tex_ac47ec& other);
};

// One entry of the texture format table (40 bytes: a DirectDraw pixel format and more).
struct FormatEntry_ac47ec {
    uint32_t mnWords[10];
};

// The four sampler settings of a texture (wrap and filter modes) as the texture manager hands them out.
struct SamplerInfo_ac47ec {
    uint32_t mn00;
    uint32_t mn04;
    uint32_t mn08;
    uint32_t mn0c;
};

// A vector of ids (begin, end, capacity).
struct IdVec_ac47ec {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x0051ca60
    void Fn0051ca60(uint32_t* pos, const uint32_t* value, const void* tag, uint32_t count, uint32_t atEnd);
};

// A vector of textures (begin, end, capacity).
struct TexVec_ac47ec {
    Tex_ac47ec* mpBegin;
    Tex_ac47ec* mpEnd;
    Tex_ac47ec* mpCap;
    uint32_t size() const
    {
        return static_cast<uint32_t>(mpEnd - mpBegin);
    }
    Tex_ac47ec& operator[](uint32_t index) const
    {
        return mpBegin[index];
    }
    // STUB: 0x0088af90
    NOINLINE_ac47ec void Fn0088af90(Tex_ac47ec* pos, const Tex_ac47ec* value, const void* tag, uint32_t count, uint32_t atEnd);
    void Fn0088af90Draft_ac47ec(Tex_ac47ec* pos, const Tex_ac47ec* value, const void* tag, uint32_t count, uint32_t atEnd);
    // STUB: 0x0088aed0
    NOINLINE_ac47ec void Fn0088aed0(Tex_ac47ec* first, Tex_ac47ec* last);
    // STUB: 0x0088ae90
    NOINLINE_ac47ec void Fn0088ae90();
};

// The driver's texture manager: the table of DirectDraw textures.
struct TexMgr_ac47ec {
    uint8_t mPad00[0x8];
    Unknown_ac47ec* mpDirectDraw;
    Unknown_ac47ec* mpDevice;
    FormatEntry_ac47ec mFormats[8];
    void* mConverters[120];
    TexVec_ac47ec mTextures;
    IdVec_ac47ec mFreeIds;
    // STUB: 0x0088a450
    NOINLINE_ac47ec bool Fn0088a450(uint32_t id);
    bool Fn0088a450Draft_ac47ec(uint32_t id);
    // STUB: 0x0088a550
    NOINLINE_ac47ec Tex_ac47ec* Fn0088a550(uint32_t id);
    Tex_ac47ec* Fn0088a550Draft_ac47ec(uint32_t id);
    // STUB: 0x0088a490
    NOINLINE_ac47ec bool Fn0088a490(uint32_t id);
    bool Fn0088a490Draft_ac47ec(uint32_t id);
    // STUB: 0x0088a4f0
    NOINLINE_ac47ec bool Fn0088a4f0(uint32_t id);
    bool Fn0088a4f0Draft_ac47ec(uint32_t id);
    // STUB: 0x0088a5a0
    NOINLINE_ac47ec void Fn0088a5a0(uint32_t id, float priority);
    void Fn0088a5a0Draft_ac47ec(uint32_t id, float priority);
    // STUB: 0x0088adf0
    NOINLINE_ac47ec void Fn0088adf0(uint32_t id);
    void Fn0088adf0Draft_ac47ec(uint32_t id);
    // STUB: 0x0088b160
    NOINLINE_ac47ec uint32_t Fn0088b160();
    uint32_t Fn0088b160Draft_ac47ec();
    // STUB: 0x0088a900
    NOINLINE_ac47ec bool Fn0088a900(uint32_t id, uint32_t hints, uint32_t format, uint32_t width, uint32_t height, uint32_t levels);
    bool Fn0088a900Draft_ac47ec(uint32_t id, uint32_t hints, uint32_t format, uint32_t width, uint32_t height, uint32_t levels);
    // STUB: 0x0088a720
    NOINLINE_ac47ec bool Fn0088a720(FormatEntry_ac47ec* entry, uint32_t hints, uint32_t width, uint32_t height, uint32_t levels, uint32_t surface);
    NOINLINE_ac47ec void Fn0088ac40(Unknown_ac47ec* device);
    NOINLINE_ac47ec void Fn0088b0d0();
    // STUB: 0x0088acd0
    NOINLINE_ac47ec bool Fn0088acd0(uint32_t id, uint32_t level, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t format, uint32_t type, uint32_t rowLength, const void* pixels);
    bool Fn0088acd0Draft_ac47ec(uint32_t id, uint32_t level, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t format, uint32_t type, uint32_t rowLength, const void* pixels);
    // STUB: 0x0088a6b0
    NOINLINE_ac47ec bool Fn0088a6b0(uint32_t id, SamplerInfo_ac47ec* info);
    // STUB: 0x0088a610
    NOINLINE_ac47ec bool Fn0088a610(uint32_t id, uint32_t parameter, uint32_t value);
    bool Fn0088a610Draft_ac47ec(uint32_t id, uint32_t parameter, uint32_t value);
};

// A reference-counted object whose Release is an ordinary member call (this in ecx).
struct ReleasableObject_ac47ec {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
};

// A smart pointer to a COM object.
struct ComPtr_ac47ec {
    Unknown_ac47ec* mp;
    NOINLINE_ac47ec ComPtr_ac47ec* Fn00886ef0(Unknown_ac47ec* p);
};

// The driver maps a failed Direct3D call to its error code: 0 for a lost surface, 1 for anything else. A switch in an
// inline function (the result comes back through eax).
static inline uint32_t ErrorFromHr_ac47ec(uint32_t hr)
{
    switch (hr) {
    case 0x887601c2u:
        return 0;
    default:
        return 1;
    }
}

#define TM_ac47ec reinterpret_cast<TexMgr_ac47ec*>(mpTexMgr)
#define PM_ac47ec reinterpret_cast<PrimMgr_ac47ec*>(mpPrimMgr)
#define DEV_ac47ec reinterpret_cast<Device7_ac47ec*>(mpDevice)
#define STG_ac47ec reinterpret_cast<Stage_ac47ec*>(mpStages)
#define MAT_ac47ec reinterpret_cast<Material_ac47ec*>(mMaterial)
#define LIGHTS_ac47ec reinterpret_cast<LightVec_ac47ec*>(&mpLightsBegin)
#define MODE_ac47ec reinterpret_cast<ModeView_ac47ec*>(mCurrentMode)

// The frame-buffer-wide pieces of the 52-byte video mode record.
struct Mode_ac47ec {
    uint32_t mnWords[13];
};

struct BufferRegion_ac47ec;

// The list of buffer regions as a vector (begin, end, capacity); the overflow insert is the original's.
struct BufferRegionVec_ac47ec {
    BufferRegion_ac47ec* mpBegin;
    BufferRegion_ac47ec* mpEnd;
    BufferRegion_ac47ec* mpCap;
    // STUB: 0x00748f20
    NOINLINE_ac47ec void Fn00748f20(BufferRegion_ac47ec* position, const BufferRegion_ac47ec* value, const BufferRegion_ac47ec* tag, uint32_t count, uint32_t atEnd);
};

// The D3DLIGHT7 record the driver keeps per light (104 bytes), zeroed but for a point light with unit falloff.
struct D3DLight_ac47ec {
    uint32_t mnType;
    float mDiffuse[4];
    float mSpecular[4];
    float mAmbient[4];
    float mPosition[3];
    float mDirection[3];
    float mfRange;
    float mfFalloff;
    float mfAttenuation[3];
    float mfTheta;
    float mfPhi;
    D3DLight_ac47ec();
};

// The Direct3D material (D3DMATERIAL7) the driver keeps: four colours and the power.
struct Material_ac47ec {
    float mDiffuse[4];
    float mAmbient[4];
    float mSpecular[4];
    float mEmissive[4];
    float mfPower;
};

// The lights the driver keeps (D3DLight_ac47ec, 0x68 bytes each) as a vector; the resize helper is the original's.
struct LightVec_ac47ec {
    D3DLight_ac47ec* mpBegin;
    D3DLight_ac47ec* mpEnd;
    D3DLight_ac47ec* mpCap;
    uint32_t size() const
    {
        return static_cast<uint32_t>(mpEnd - mpBegin);
    }
    NOINLINE_ac47ec void Fn00886b30(uint32_t size, const D3DLight_ac47ec& fill);
    // STUB: 0x008865a0
    NOINLINE_ac47ec void Fn008865a0(D3DLight_ac47ec* position, uint32_t count, const D3DLight_ac47ec& fill);
};

// The video mode record (13 words, the part this driver names): flags sit in the bytes of its later words.
struct ModeView_ac47ec {
    uint32_t mnIndex;
    uint32_t mnWidth;
    uint32_t mnHeight;
    uint8_t mPad0c[0x20 - 0xc];
    bool mbFullscreen;
    bool mbStencil;
    uint8_t mPad22[0x29 - 0x22];
    bool mbCombine;
    uint8_t mPad2a[0x34 - 0x2a];
};

// One entry of the video mode list (56 bytes: the 52-byte record and a word).
struct ModeEntry_ac47ec {
    Mode_ac47ec mMode;
    uint32_t mnExtra;
};

// One entry of the buffer region list (28 bytes, the id first).
struct BufferRegion_ac47ec {
    uint32_t mnId;
    uint32_t mn04;
    Unknown_ac47ec* mpSurface;
    uint32_t mn0c;
    uint32_t mn10;
    uint32_t mn14;
    uint32_t mn18;
};

// GLOBAL: 0x00b54340
extern const char* gpB54340;
// GLOBAL: 0x00b542f8
extern float gfB542f8[16];
// GLOBAL: 0x00ac45f4
extern const uint32_t gnAc45f4[];
// Translation tables (the interface's enumerations to Direct3D's): depth test, shade model, blend factor.
// GLOBAL: 0x00ac44ec
extern const uint32_t gnAc44ec[];
// GLOBAL: 0x00ac4524
extern const uint32_t gnAc4524[];
// GLOBAL: 0x00ac452c
extern const uint32_t gnAc452c[];
// GLOBAL: 0x00ac45dc
extern const uint32_t gnAc45dc[];
// GLOBAL: 0x00ac450c
extern const uint32_t gnAc450c[];
// GLOBAL: 0x00ac45f8
extern const uint32_t gnAc45f8[];
// GLOBAL: 0x00ac44cc
extern const uint32_t gnAc44cc[];

// A DirectDraw result that is neither success nor a lost surface.
// FUNCTION: 0x00881a90
uint32_t Fn00881a90(uint32_t hr)
{
    return hr != 0x887601c2 && hr != 0;
}

// FUNCTION: 0x00881df0
bool nSGLDX7_cGDriver::Init()
{
    bool result = false;
    mnError = 0;
    if (!mbInitialised) {
        mbInitialised = true;
        mnTexStage = 0;
        mnTexStageCount = 0;
        mn138 = 7;
        mCurrentMode[0] = 0xffffffff;
        result = Fn00888a30();
    }
    return result;
}

// FUNCTION: 0x00881e40
bool nSGLDX7_cGDriver::Shutdown()
{
    bool result = mbInitialised;
    if (result) {
        mbInitialised = false;
        result = Fn008880f0();
    }
    return result;
}

// FUNCTION: 0x00881e80
uint32_t nSGLDX7_cGDriver::FinalRelease()
{
    Shutdown();
    reinterpret_cast<Deleter_ac47ec*>(reinterpret_cast<char*>(this) + 0x10)->Destroy(1);
    return 0;
}

// FUNCTION: 0x00881eb0
void nSGLDX7_cGDriver::LoadIdentity()
{
    LoadMatrix(gfB542f8);
}

// FUNCTION: 0x00881fa0
void nSGLDX7_cGDriver::ClearDepth(double depth)
{
    mfClearDepth = static_cast<float>(depth);
}

// FUNCTION: 0x00881fc0
void nSGLDX7_cGDriver::PixelStore(uint32_t parameter, int32_t value)
{
    if (parameter == 0) {
        mnPixelStore = value;
    }
}

// FUNCTION: 0x00881fe0
void nSGLDX7_cGDriver::GetInteger(uint32_t parameter, int32_t* values)
{
    if (gnAc45f4[parameter] == 0) {
        *values = mnPixelStore;
    }
}

// FUNCTION: 0x00882000
uint32_t nSGLDX7_cGDriver::GetError()
{
    uint32_t error = mnError;
    mnError = 0;
    return error;
}

// FUNCTION: 0x00882020
void nSGLDX7_cGDriver::TexStage(uint32_t stage)
{
    if (stage >= mnTexStageCount) {
        mnError = 2;
    } else {
        mnTexStage = stage;
    }
}

// FUNCTION: 0x00882050
void nSGLDX7_cGDriver::BitBlt(int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, const void*, bool, const void*)
{
    mnError = 3;
}

// FUNCTION: 0x00882060
void nSGLDX7_cGDriver::StretchBlt(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, const void*, bool, const void*)
{
    mnError = 3;
}

// FUNCTION: 0x00882070
void nSGLDX7_cGDriver::BitBltAlphaModulate(int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, const void*, bool, const void*, uint32_t)
{
    mnError = 3;
}

// FUNCTION: 0x00882080
void nSGLDX7_cGDriver::StretchBltAlphaModulate(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t, const void*, bool, const void*, uint32_t)
{
    mnError = 3;
}

// FUNCTION: 0x00882d10
void nSGLDX7_cGDriver::ColorMask(bool)
{
    PM_ac47ec->Fn00889de0();
}

// FUNCTION: 0x00884860
uint32_t nSGLDX7_cGDriver::GetTexture(uint32_t stage)
{
    return STG_ac47ec[stage].mnTexture;
}

// FUNCTION: 0x00886380
bool nSGLDX7_cGDriver::IsDeviceReady()
{
    return !mbDeviceLost;
}

// FUNCTION: 0x00886e10
void nSGLDX7_cGDriver::GetVideoModeInfo(sGDMode& mode)
{
    *reinterpret_cast<Mode_ac47ec*>(&mode) = *reinterpret_cast<const Mode_ac47ec*>(mCurrentMode);
}

// FUNCTION: 0x008870a0
const char* nSGLDX7_cGDriver::GetDriverInfo() const
{
    return gpB54340;
}

// A colour as four bytes from four floats in 0..1 (the float is shifted into a fixed-point fraction by adding 49152.0f).
// FUNCTION: 0x00881ab0
uint32_t Fn00881ab0(float r, float g, float b, float a)
{
    float fa = a + 49152.0f;
    int32_t ia = reinterpret_cast<int32_t&>(fa) - 0x47400000;
    float fr = r + 49152.0f;
    int32_t ir = reinterpret_cast<int32_t&>(fr) - 0x47400000;
    float fg = g + 49152.0f;
    int32_t ig = reinterpret_cast<int32_t&>(fg) - 0x47400000;
    float fb = b + 49152.0f;
    int32_t ib = reinterpret_cast<int32_t&>(fb) - 0x47400000;
    return (static_cast<uint8_t>(ia - (static_cast<uint32_t>(ia) >> 8)) << 24) |
           (static_cast<uint8_t>(ir - (static_cast<uint32_t>(ir) >> 8)) << 16) |
           (static_cast<uint8_t>(ig - (static_cast<uint32_t>(ig) >> 8)) << 8) |
           static_cast<uint8_t>(ib - (static_cast<uint32_t>(ib) >> 8));
}

#ifdef OB_DRAFTS
// CLOSE: 0x00889bf0 score 56 (logic equal; register and spill order differ)
uint32_t PrimMgr_ac47ec::Fn00889bf0Draft_ac47ec()
{
    uint32_t hr = 0;
    if (mList.mpBegin != mList.mpEnd) {
        if (!mp10) {
            return 0x80004005;
        }
        DrawRecord_ac47ec* end = mList.mpEnd;
        DrawRecord_ac47ec* it = mList.mpBegin;
        if (it != end) {
            void* buffer = mVertexBuffer.mpHolder->mpBuffer;
            Device7_ac47ec* device = mpDevice;
            do {
                if (it->mpIndices) {
                    hr = device->DrawIndexedPrimitiveVB(it->mnPrimitive, buffer, it->mnStartVertex, it->mnVertexCount, it->mpIndices, it->mnIndexCount, 0);
                } else {
                    hr = device->DrawPrimitiveVB(it->mnPrimitive, buffer, it->mnStartVertex, it->mnVertexCount, 0);
                }
                ++it;
            } while (it != end);
        }
        mList.Fn00889b00();
    }
    return hr;
}
#endif

// FUNCTION: 0x00889de0
uint32_t PrimMgr_ac47ec::Fn00889de0()
{
    uint32_t hr = Fn00889bf0();
    mn30 = 0;
    return hr;
}

// FUNCTION: 0x00889260
void PrimMgr_ac47ec::Fn00889260(void* a, void* b, Device7_ac47ec* device)
{
    mp0c = a;
    mp10 = b;
    mpDevice = device;
    Slot11();
}

#ifdef OB_DRAFTS
// CLOSE: 0x0088a450 score 6 (branch layout)
bool TexMgr_ac47ec::Fn0088a450Draft_ac47ec(uint32_t id)
{
    if (id < mTextures.size()) {
        return mTextures[id].mbUsed;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088a550 score 11 (branch layout)
Tex_ac47ec* TexMgr_ac47ec::Fn0088a550Draft_ac47ec(uint32_t id)
{
    if (id < mTextures.size()) {
        Tex_ac47ec* texture = &mTextures[id];
        if (texture->mbUsed) {
            return texture;
        }
    }
    return 0;
}
#endif

// FUNCTION: 0x00886ef0
ComPtr_ac47ec* ComPtr_ac47ec::Fn00886ef0(Unknown_ac47ec* p)
{
    Unknown_ac47ec* old = mp;
    if (p != old) {
        if (p) {
            p->AddRef();
        }
        mp = p;
        if (old) {
            old->Release();
        }
    }
    return this;
}

// The bits per pixel of a texture format (0 = not a plain colour format).
// FUNCTION: 0x0088d050
uint32_t Fn0088d050(uint32_t format)
{
    switch (format) {
    case 0:
    case 1:
        return 32;
    case 2:
    case 3:
        return 24;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 16;
    case 12:
    case 14:
        return 8;
    case 10:
        return 4;
    }
    return 0;
}

// FUNCTION: 0x00881f70
void nSGLDX7_cGDriver::ClearColor(float r, float g, float b, float a)
{
    mnClearColor = Fn00881ab0(r, g, b, a);
}

// FUNCTION: 0x00882ce0
void nSGLDX7_cGDriver::DepthFunc(uint32_t test)
{
    PM_ac47ec->Fn00889de0();
    DEV_ac47ec->SetRenderState(23, gnAc44ec[test]);
}

// FUNCTION: 0x00882d20
void nSGLDX7_cGDriver::DepthMask(bool write)
{
    PM_ac47ec->Fn00889de0();
    DEV_ac47ec->SetRenderState(14, write);
}

// FUNCTION: 0x00882f10
void nSGLDX7_cGDriver::BlendFunc(uint32_t source, uint32_t destination)
{
    PM_ac47ec->Fn00889de0();
    DEV_ac47ec->SetRenderState(19, gnAc452c[source]);
    DEV_ac47ec->SetRenderState(20, gnAc452c[destination]);
}

// FUNCTION: 0x00882fc0
void nSGLDX7_cGDriver::ShadeModel(uint32_t model)
{
    PM_ac47ec->Fn00889de0();
    DEV_ac47ec->SetRenderState(9, gnAc4524[model]);
}

// FUNCTION: 0x00884960
void nSGLDX7_cGDriver::TexEnv(uint32_t, uint32_t, int32_t value)
{
    Stage_ac47ec* stage = &STG_ac47ec[mnTexStage];
    mbStagesDirty = true;
    stage->mbDirty = 1;
    stage->mnTexEnvMode = value;
}

// FUNCTION: 0x0088a810
Tex_ac47ec* Tex_ac47ec::Fn0088a810(const Tex_ac47ec& other)
{
    mbUsed = other.mbUsed;
    mnWidth = other.mnWidth;
    mnHeight = other.mnHeight;
    mnLevels = other.mnLevels;
    mfPriority = other.mfPriority;
    mnFormat = other.mnFormat;
    mnHints = other.mnHints;
    mn1c = other.mn1c;
    mn20 = other.mn20;
    mn24 = other.mn24;
    mn28 = other.mn28;
    mpSurface = other.mpSurface;
    if (mpSurface) {
        mpSurface->AddRef();
    }
    return this;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0088a490 score 22 (address arithmetic order)
bool TexMgr_ac47ec::Fn0088a490Draft_ac47ec(uint32_t id)
{
    if (id < mTextures.size()) {
        Tex_ac47ec* texture = &mTextures[id];
        if (!texture->mbUsed) {
            return false;
        }
        return texture->mpSurface != 0;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088a4f0 score 18 (address arithmetic order)
bool TexMgr_ac47ec::Fn0088a4f0Draft_ac47ec(uint32_t id)
{
    if (id < mTextures.size()) {
        Tex_ac47ec* texture = &mTextures[id];
        if (!texture->mbUsed) {
            return false;
        }
        return texture->mnFormat != 0 && texture->mnFormat != 1;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088a5a0 score 14 (address arithmetic order)
void TexMgr_ac47ec::Fn0088a5a0Draft_ac47ec(uint32_t id, float priority)
{
    if (id < mTextures.size()) {
        Tex_ac47ec* texture = &mTextures[id];
        if (texture->mbUsed) {
            texture->mfPriority = priority;
            if (priority == 0.95f) {
                mTextures[id].mnHints |= 1;
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088adf0 score 73 (push_back inline and register order)
void TexMgr_ac47ec::Fn0088adf0Draft_ac47ec(uint32_t id)
{
    if (id < mTextures.size()) {
        Tex_ac47ec* texture = &mTextures[id];
        if (texture->mbUsed) {
            Unknown_ac47ec* surface = texture->mpSurface;
            if (surface) {
                texture->mpSurface = 0;
                surface->Release();
            }
            mTextures[id].mbUsed = false;
            if (mFreeIds.mpEnd != mFreeIds.mpCap) {
                if (mFreeIds.mpEnd) {
                    *mFreeIds.mpEnd = id;
                }
                mFreeIds.mpEnd += 1;
            } else {
                mFreeIds.Fn0051ca60(mFreeIds.mpEnd, &id, &id, 1, 1);
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088b160 score 99 (default record built in another order)
uint32_t TexMgr_ac47ec::Fn0088b160Draft_ac47ec()
{
    uint32_t id;
    if (mFreeIds.mpBegin != mFreeIds.mpEnd) {
        id = mFreeIds.mpEnd[-1];
        mFreeIds.mpEnd -= 1;
    } else {
        id = mTextures.size();
        Tex_ac47ec fresh;
        fresh.mbUsed = false;
        fresh.mnWidth = 0;
        fresh.mnHeight = 0;
        fresh.mnLevels = 0;
        fresh.mfPriority = 0.5f;
        fresh.mnFormat = 4;
        fresh.mnHints = 0;
        fresh.mn1c = 0;
        fresh.mn20 = 0;
        fresh.mn24 = 3;
        fresh.mn28 = 3;
        fresh.mpSurface = 0;
        if (mTextures.mpEnd != mTextures.mpCap) {
            if (mTextures.mpEnd) {
                mTextures.mpEnd->Fn0088a810(fresh);
            }
            mTextures.mpEnd += 1;
        } else {
            char tag;
            mTextures.Fn0088af90(mTextures.mpEnd, &fresh, &tag, 1, 1);
        }
    }
    mTextures[id].mbUsed = true;
    mTextures[id].mnWidth = 0;
    mTextures[id].mnHeight = 0;
    return id;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088a1a0 score 37 (erase(begin,end) inline not reproduced)
void PrimMgr_ac47ec::Fn0088a1a0Draft_ac47ec()
{
    Fn00889b60();
    mIndices.mpEnd = mIndices.mpBegin;
    mVertexBuffer.Fn00889ce0(reinterpret_cast<VertexBufferHolder_ac47ec*>(mVertexBuffer.mpHolder), mVertexBuffer.mn04);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088a240 score 39 (register order)
uint16_t* PrimMgr_ac47ec::Fn0088a240Draft_ac47ec(uint32_t count)
{
    uint32_t needed = mn30 + count;
    if (needed > static_cast<uint32_t>(mIndices.mpEnd - mIndices.mpBegin)) {
        if (needed > static_cast<uint32_t>(mIndices.mpCap - mIndices.mpBegin)) {
            Fn00889bf0();
            mn30 = 0;
            uint16_t zero = 0;
            mIndices.Fn00465710(needed, &zero);
        }
    }
    uint16_t* result = mIndices.mpBegin + mn30;
    mn30 += count;
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00887680 score 15 (register order of the index; push order)
void nSGLDX7_cGDriver::GetVideoModeInfo(uint32_t index, sGDMode& mode)
{
    if (index >= mnModeCount) {
        mnError = 2;
        return;
    }
    *reinterpret_cast<Mode_ac47ec*>(&mode) = reinterpret_cast<ModeEntry_ac47ec*>(mpModes)[index].mMode;
}
#endif

// FUNCTION: 0x00883450
void nSGLDX7_cGDriver::GenTextures(int32_t count, uint32_t* textures)
{
    for (int32_t i = 0; i < count; i++) {
        textures[i] = TM_ac47ec->Fn0088b160();
    }
}

// FUNCTION: 0x008834d0
void nSGLDX7_cGDriver::PrioritizeTextures(int32_t count, const uint32_t* textures, const float* priorities)
{
    for (int32_t i = 0; i < count; i++) {
        TM_ac47ec->Fn0088a5a0(textures[i], priorities[i]);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00883510 score 4 (argument load order)
bool nSGLDX7_cGDriver::AreTexturesResident(int32_t count, const uint32_t* textures, bool* resident)
{
    for (int32_t i = 0; i < count; i++) {
        resident[i] = TM_ac47ec->Fn0088a450(textures[i]);
    }
    return true;
}
#endif

// FUNCTION: 0x00883480
void nSGLDX7_cGDriver::DeleteTextures(int32_t count, const uint32_t* textures)
{
    if (mbTexturesReady) {
        for (int32_t i = 0; i < count;) {
            uint32_t id = textures[i++];
            if (id) {
                TM_ac47ec->Fn0088adf0(id);
            }
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00884810 score 13 (register order)
void nSGLDX7_cGDriver::SetTexture(uint32_t texture, uint32_t stage)
{
    Stage_ac47ec* record = &STG_ac47ec[stage];
    if (texture != record->mnTexture) {
        mb13c = false;
        mbStagesDirty = true;
        record->mbDirty = 1;
        record->mn20 = 0xffffffff;
        record->mnTexture = texture;
        record->mb02 = TM_ac47ec->Fn0088a4f0(texture);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00882ff0 score 14 (argument load order)
uint32_t nSGLDX7_cGDriver::CreateTexture(uint32_t internalFormat, uint32_t width, uint32_t height, uint32_t levels, uint32_t hints)
{
    uint32_t id = TM_ac47ec->Fn0088b160();
    if (!TM_ac47ec->Fn0088a900(id, hints, internalFormat, width, height, levels)) {
        mnError = 3;
    }
    return id;
}
#endif

// FUNCTION: 0x00883ec0
D3DLight_ac47ec::D3DLight_ac47ec()
{
    mnType = 1;
    mDiffuse[0] = 0.0f;
    mDiffuse[1] = 0.0f;
    mDiffuse[2] = 0.0f;
    mDiffuse[3] = 0.0f;
    mSpecular[0] = 0.0f;
    mSpecular[1] = 0.0f;
    mSpecular[2] = 0.0f;
    mSpecular[3] = 0.0f;
    mAmbient[0] = 0.0f;
    mAmbient[1] = 0.0f;
    mAmbient[2] = 0.0f;
    mAmbient[3] = 0.0f;
    mPosition[0] = 0.0f;
    mPosition[1] = 0.0f;
    mPosition[2] = 0.0f;
    mDirection[0] = 0.0f;
    mDirection[1] = 0.0f;
    mDirection[2] = 10.0f;
    mfRange = static_cast<float>(std::sqrt(3.402823466e+38F));
    mfFalloff = 1.0f;
    mfAttenuation[0] = 0.0f;
    mfAttenuation[1] = 0.0f;
    mfAttenuation[2] = 0.0f;
    mfTheta = 0.78f;
    mfPhi = 1.57f;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00885790 score 31 (vector size() load order)
bool nSGLDX7_cGDriver::Slot08_ac34cc(uint32_t id)
{
    BufferRegion_ac47ec* begin = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin);
    BufferRegion_ac47ec* end = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd);
    if (id - 1 <= static_cast<uint32_t>(end - begin)) {
        if (id - 1 == reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin)[id - 1].mnId) {
            return true;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x00883710
void nSGLDX7_cGDriver::PolygonOffset(int32_t offset)
{
    uint32_t hr = PM_ac47ec->Fn00889de0();
    if (hr) {
        mnError = ErrorFromHr_ac47ec(hr);
    }
    hr = DEV_ac47ec->SetRenderState(47, offset);
    if (hr) {
        mnError = ErrorFromHr_ac47ec(hr);
    }
}

// FUNCTION: 0x00882e00
void nSGLDX7_cGDriver::StencilMask(uint32_t mask)
{
    if (MODE_ac47ec->mbStencil) {
        PM_ac47ec->Fn00889de0();
        uint32_t hr = DEV_ac47ec->SetRenderState(59, mask);
        if (hr) {
            mnError = ErrorFromHr_ac47ec(hr);
        }
    } else {
        mnError = 3;
    }
}

// FUNCTION: 0x008830a0
void nSGLDX7_cGDriver::TexEnv(uint32_t, uint32_t, const float* values)
{
    PM_ac47ec->Fn00889de0();
    uint32_t hr = DEV_ac47ec->SetRenderState(60, Fn00881ab0(values[0], values[1], values[2], values[3]));
    if (hr) {
        mnError = ErrorFromHr_ac47ec(hr);
    }
}

// FUNCTION: 0x00882f60
void nSGLDX7_cGDriver::AlphaFunc(uint32_t test, float reference)
{
    PM_ac47ec->Fn00889de0();
    DEV_ac47ec->SetRenderState(25, gnAc44ec[test]);
    float f = reference + 49152.0f;
    int32_t i = reinterpret_cast<int32_t&>(f) - 0x47400000;
    DEV_ac47ec->SetRenderState(24, static_cast<uint8_t>(i - (static_cast<uint32_t>(i) >> 8)));
}

// FUNCTION: 0x00882c80
void nSGLDX7_cGDriver::Clear(uint32_t buffers)
{
    PM_ac47ec->Fn00889de0();
    uint32_t flags = (((buffers >> 3) & 0x800) | (buffers & 0x3000)) >> 11;
    if (!MODE_ac47ec->mbStencil) {
        flags &= ~4u;
    }
    DEV_ac47ec->Clear(0, 0, flags, mnClearColor, mfClearDepth, mnClearStencil);
}

#ifdef OB_DRAFTS
// CLOSE: 0x008833e0 score 13 (argument register order)
void nSGLDX7_cGDriver::EnableVertexColors(bool diffuse, bool specular)
{
    PM_ac47ec->Fn00889de0();
    mbVertexSpecular = specular;
    mbVertexDiffuse = diffuse;
    DEV_ac47ec->SetRenderState(141, 1);
    DEV_ac47ec->SetRenderState(147, diffuse != 0);
    DEV_ac47ec->SetRenderState(145, specular != 0);
}
#endif

// FUNCTION: 0x00885130
void nSGLDX7_cGDriver::TexStageCombine(eGDTextureStageCombineMode parameter, eGDTextureStageCombineValue value)
{
    if (!MODE_ac47ec->mbCombine) {
        mnError = 2;
        return;
    }
    Stage_ac47ec* stage = &STG_ac47ec[mnTexStage];
    mbStagesDirty = true;
    stage->mbDirty = 1;
    stage->mn20 = 0xffffffff;
    switch (static_cast<uint32_t>(parameter)) {
    case 0:
        stage->mn24 = static_cast<uint32_t>(value);
        break;
    case 1:
        stage->mn28 = static_cast<uint32_t>(value);
        break;
    }
}

// FUNCTION: 0x008852d0
void nSGLDX7_cGDriver::TexStageCombine(eGDTextureStageCombineScale parameter, eGDTextureStageCombineValue value)
{
    if (!MODE_ac47ec->mbCombine) {
        mnError = 2;
        return;
    }
    Stage_ac47ec* stage = &STG_ac47ec[mnTexStage];
    mbStagesDirty = true;
    stage->mbDirty = 1;
    stage->mn20 = 0xffffffff;
    if (static_cast<uint32_t>(parameter) == 0) {
        stage->mn5c = static_cast<uint32_t>(value);
    } else if (static_cast<uint32_t>(parameter) == 1) {
        stage->mn60 = static_cast<uint32_t>(value);
    }
}

// FUNCTION: 0x00885190
void nSGLDX7_cGDriver::TexStageCombine(eGDTextureStageCombineSource parameter, eGDTextureStageCombineValue value)
{
    Stage_ac47ec* stage = &STG_ac47ec[mnTexStage];
    mbStagesDirty = true;
    stage->mbDirty = 1;
    stage->mn20 = 0xffffffff;
    switch (static_cast<uint32_t>(parameter)) {
    case 0:
        stage->mn2c = static_cast<uint32_t>(value);
        break;
    case 1:
        stage->mn30 = static_cast<uint32_t>(value);
        break;
    case 2:
        stage->mn34 = static_cast<uint32_t>(value);
        break;
    case 4:
        stage->mn38 = static_cast<uint32_t>(value);
        break;
    case 5:
        stage->mn3c = static_cast<uint32_t>(value);
        break;
    case 6:
        stage->mn40 = static_cast<uint32_t>(value);
        break;
    }
}

// FUNCTION: 0x00885220
void nSGLDX7_cGDriver::TexStageCombine(eGDTextureStageCombineOperand parameter, eGDTextureStageCombineValue value)
{
    if (!MODE_ac47ec->mbCombine) {
        mnError = 2;
        return;
    }
    Stage_ac47ec* stage = &STG_ac47ec[mnTexStage];
    mbStagesDirty = true;
    stage->mbDirty = 1;
    stage->mn20 = 0xffffffff;
    switch (static_cast<uint32_t>(parameter)) {
    case 0:
        stage->mn44 = static_cast<uint32_t>(value);
        break;
    case 1:
        stage->mn48 = static_cast<uint32_t>(value);
        break;
    case 2:
        stage->mn4c = static_cast<uint32_t>(value);
        break;
    case 4:
        stage->mn50 = static_cast<uint32_t>(value);
        break;
    case 5:
        stage->mn54 = static_cast<uint32_t>(value);
        break;
    case 6:
        stage->mn58 = static_cast<uint32_t>(value);
        break;
    }
}

// FUNCTION: 0x00883fa0
void nSGLDX7_cGDriver::Slot04_ac3508(uint32_t light, bool enable)
{
    uint32_t hr = PM_ac47ec->Fn00889de0();
    if (hr) {
        mnError = ErrorFromHr_ac47ec(hr);
    }
    hr = DEV_ac47ec->LightEnable(light, enable);
    if (hr) {
        mnError = ErrorFromHr_ac47ec(hr);
    }
}

// A failed Direct3D call sets the error: 1 for a real failure, 0 for a lost surface.
#define CHECK_ac47ec(hr) \
    if (hr) { \
        mnError = ErrorFromHr_ac47ec(hr); \
    }

// FUNCTION: 0x00884ef0
void nSGLDX7_cGDriver::Enable(uint32_t cap)
{
    switch (cap) {
    case 5:
        mbStagesDirty = true;
        STG_ac47ec[mnTexStage].mb01 = 1;
        STG_ac47ec[mnTexStage].mbDirty = 1;
        break;
    case 3:
        PM_ac47ec->Fn00889de0();
        DEV_ac47ec->SetRenderState(gnAc45dc[cap], 2);
        break;
    case 6:
        if (mnCaps & 4) {
            PM_ac47ec->Fn00889de0();
            DEV_ac47ec->SetRenderState(28, 1);
        }
        break;
    case 7:
        break;
    default:
        PM_ac47ec->Fn00889de0();
        DEV_ac47ec->SetRenderState(gnAc45dc[cap], 1);
        break;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00884fb0 score 26 (shared tail of case 3/default not merged; Fn00881a90 inline-vs-call choice)
void nSGLDX7_cGDriver::Disable(uint32_t cap)
{
    switch (cap) {
    case 5:
        mbStagesDirty = true;
        STG_ac47ec[mnTexStage].mb01 = 0;
        STG_ac47ec[mnTexStage].mbDirty = 1;
        break;
    case 3: {
        PM_ac47ec->Fn00889de0();
        uint32_t hr = DEV_ac47ec->SetRenderState(gnAc45dc[cap], 1);
        mnError = Fn00881a90(hr);
        break;
    }
    case 6:
        if (mnCaps & 4) {
            PM_ac47ec->Fn00889de0();
            uint32_t hr = DEV_ac47ec->SetRenderState(28, 0);
            mnError = Fn00881a90(hr);
        }
        break;
    case 7:
        break;
    default: {
        PM_ac47ec->Fn00889de0();
        uint32_t hr = DEV_ac47ec->SetRenderState(gnAc45dc[cap], 0);
        mnError = Fn00881a90(hr);
        break;
    }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008850a0 score 32 (bool result: original compares memory then sete without xor)
bool nSGLDX7_cGDriver::IsEnabled(uint32_t cap)
{
    if (mbDeviceLost) {
        return false;
    }
    switch (cap) {
    case 3: {
        uint32_t value;
        DEV_ac47ec->GetRenderState(22, &value);
        return value != 1;
    }
    case 5:
        return STG_ac47ec[mnTexStage].mb01 != 0;
    case 7:
        return true;
    default: {
        uint32_t value;
        DEV_ac47ec->GetRenderState(gnAc45dc[cap], &value);
        return value == 1;
    }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00883100 score 24 (error idiom through eax)
void nSGLDX7_cGDriver::Fog(uint32_t parameter, uint32_t value)
{
    PM_ac47ec->Fn00889de0();
    if (mnCaps & 4) {
        if (parameter == 0) {
            uint32_t hr = DEV_ac47ec->SetRenderState(140, gnAc45f8[value]);
            CHECK_ac47ec(hr);
        } else if (parameter > 0 && parameter <= 4) {
            mnError = 1;
        }
    } else {
        mnError = 3;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00883180 score 11 (register order)
void nSGLDX7_cGDriver::Fog(uint32_t parameter, const float* values)
{
    PM_ac47ec->Fn00889de0();
    uint32_t hr;
    switch (parameter) {
    case 0:
        mnError = 1;
        return;
    case 1:
        hr = DEV_ac47ec->SetRenderState(34, Fn00881ab0(values[0], values[1], values[2], values[3]));
        break;
    case 2:
        hr = DEV_ac47ec->SetRenderState(38, *reinterpret_cast<const uint32_t*>(values));
        break;
    case 3:
        hr = DEV_ac47ec->SetRenderState(36, *reinterpret_cast<const uint32_t*>(values));
        break;
    case 4:
        hr = DEV_ac47ec->SetRenderState(37, *reinterpret_cast<const uint32_t*>(values));
        break;
    default:
        return;
    }
    if (hr) {
        mnError = Fn00881a90(hr);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00882d50 score 24 (error idiom through eax)
void nSGLDX7_cGDriver::StencilFunc(uint32_t test, int32_t reference, uint32_t mask)
{
    if (MODE_ac47ec->mbStencil) {
        PM_ac47ec->Fn00889de0();
        uint32_t hr = DEV_ac47ec->SetRenderState(58, mask);
        CHECK_ac47ec(hr);
        hr = DEV_ac47ec->SetRenderState(56, gnAc44ec[test]);
        CHECK_ac47ec(hr);
        hr = DEV_ac47ec->SetRenderState(57, reference);
        CHECK_ac47ec(hr);
    } else {
        mnError = 3;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00882e50 score 28 (error idiom through eax)
void nSGLDX7_cGDriver::StencilOp(uint32_t fail, uint32_t depthFail, uint32_t pass)
{
    if (MODE_ac47ec->mbStencil) {
        PM_ac47ec->Fn00889de0();
        uint32_t hr = DEV_ac47ec->SetRenderState(53, gnAc450c[fail]);
        CHECK_ac47ec(hr);
        hr = DEV_ac47ec->SetRenderState(54, gnAc450c[depthFail]);
        CHECK_ac47ec(hr);
        hr = DEV_ac47ec->SetRenderState(55, gnAc450c[pass]);
        CHECK_ac47ec(hr);
    } else {
        mnError = 3;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00883550 score 35 (error idiom through eax)
void nSGLDX7_cGDriver::TexStageCoord(uint32_t coord)
{
    uint32_t index = coord & 7;
    uint32_t kind = coord & 0xfffffff8;
    uint32_t flags = 0;
    if (kind == 0) {
        flags = 0;
    } else if (kind == 0x10) {
        flags = 0x10000;
    } else if (kind == 0x20) {
        flags = 0x20000;
    } else if (kind == 0x30) {
        flags = 0x30000;
    } else {
        mnError = 2;
        return;
    }
    uint32_t hr = PM_ac47ec->Fn00889de0();
    CHECK_ac47ec(hr);
    if (index >= 8) {
        mnError = 2;
        return;
    }
    hr = DEV_ac47ec->SetTextureStageState(mnTexStage, 11, flags | index);
    CHECK_ac47ec(hr);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008838d0 score 31 (register allocation of the viewport rectangle)
void nSGLDX7_cGDriver::GetViewport(int32_t* viewport)
{
    if (mbDeviceLost) {
        viewport[0] = 0;
        viewport[1] = 0;
        viewport[2] = 0;
        viewport[3] = 0;
        return;
    }
    uint32_t v[6];
    DEV_ac47ec->GetViewport(v);
    int32_t bottom = mViewport[3] - v[3] - v[1];
    int32_t top = bottom + v[3];
    viewport[0] = v[0];
    viewport[1] = bottom;
    viewport[2] = v[2] + v[0];
    viewport[3] = top;
}
#endif

// FUNCTION: 0x00883760
void nSGLDX7_cGDriver::SetViewport()
{
    uint32_t hr = PM_ac47ec->Fn00889de0();
    CHECK_ac47ec(hr);
    hr = DEV_ac47ec->SetViewport(mViewport);
    CHECK_ac47ec(hr);
    uint32_t saved = mn214;
    mn214 = 1;
    LoadMatrix(mMatrix150);
    mn214 = saved;
}

// STUB: 0x008d0370
uint32_t Fn008d0370(uint32_t format);

#ifdef OB_DRAFTS
// CLOSE: 0x00881ec0 score 20 (push/pop order of the saved registers)
void nSGLDX7_cGDriver::InterleavedArrays(uint32_t format, int32_t stride, const void* vertices)
{
    if (!mbInterleaved) {
        mbInterleaved = true;
    }
    mnVertexStride = stride;
    uint32_t size = Fn008d0370(format);
    mnVertexSize = size;
    mnVertexFormat = format;
    if (stride == 0) {
        mnVertexStride = size;
    }
    mpVertices = const_cast<void*>(vertices);
}
#endif

// FUNCTION: 0x00883f30
void nSGLDX7_cGDriver::Slot03_ac3508(bool enable)
{
    if (mbLighting != enable) {
        mbLighting = enable;
        uint32_t hr = PM_ac47ec->Fn00889de0();
        CHECK_ac47ec(hr);
        hr = DEV_ac47ec->SetRenderState(137, enable);
        CHECK_ac47ec(hr);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00885330 score 37 (register allocation (ebx vs esi) of the vector walk)
bool nSGLDX7_cGDriver::Slot05_ac34cc(uint32_t id)
{
    BufferRegion_ac47ec* begin = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin);
    BufferRegion_ac47ec* end = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd);
    uint32_t index = id - 1;
    if (index < static_cast<uint32_t>(end - begin)) {
        BufferRegion_ac47ec* region = &reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin)[index];
        if (index == region->mnId) {
            Unknown_ac47ec* surface = region->mpSurface;
            if (surface) {
                surface->Release();
                region->mpSurface = 0;
            }
            region->mn04 = 0;
            region->mpSurface = 0;
            region->mn0c = 0;
            region->mn10 = 0;
            region->mn14 = 0;
            region->mn18 = 0;
            region->mnId = 0xffffffff;
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00883040 score 26 (argument load order of the ten pushes)
void nSGLDX7_cGDriver::LoadTextureLevel(uint32_t texture, int32_t level, int32_t x, int32_t y, int32_t width, int32_t height, uint32_t format, uint32_t type, uint32_t rowLength, const void* pixels)
{
    PM_ac47ec->Fn00889de0();
    if (!TM_ac47ec->Fn0088acd0(texture, level, x, y, width, height, format, type, rowLength, pixels)) {
        mnError = 3;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00884880 score 65 (register allocation; the rowLength local lives in the dead argument slot)
void nSGLDX7_cGDriver::TexImage2D(uint32_t, int32_t level, int32_t internalFormat, int32_t width, int32_t height, int32_t, uint32_t format, uint32_t type, const void* pixels)
{
    uint32_t texture = STG_ac47ec[mnTexStage].mnTexture;
    if (width >= 1 && height >= 1 && texture != 0) {
        uint32_t rowLength = mnPixelStore;
        if (rowLength == 0) {
            rowLength = width;
        }
        if (!TM_ac47ec->Fn0088a490(texture)) {
            if (!TM_ac47ec->Fn0088a900(texture, TM_ac47ec->Fn0088a550(texture)->mnHints, internalFormat, width, height, 1)) {
                mnError = 2;
                return;
            }
        }
        if (!TM_ac47ec->Fn0088acd0(texture, level, 0, 0, width, height, format, type, rowLength, pixels)) {
            mnError = 3;
        }
        return;
    }
    mnError = 2;
}
#endif

// FUNCTION: 0x00884750
void nSGLDX7_cGDriver::BindTexture(uint32_t target, uint32_t texture)
{
    if (target != 0) {
        mnError = 1;
        return;
    }
    SamplerInfo_ac47ec info;
    info.mn08 = 3;
    info.mn0c = 3;
    mb13c = true;
    info.mn00 = 0;
    info.mn04 = 0;
    if (!TM_ac47ec->Fn0088a6b0(texture, &info)) {
        TM_ac47ec->Fn0088a6b0(0, &info);
    }
    Stage_ac47ec* stage = &STG_ac47ec[mnTexStage];
    mbStagesDirty = true;
    stage->mbDirty = 1;
    stage->mn20 = 0xffffffff;
    stage->mn0c = info.mn00;
    stage->mn10 = info.mn04;
    stage->mn14 = info.mn08;
    stage->mn18 = info.mn0c;
    stage->mnTexture = texture;
    stage->mb02 = TM_ac47ec->Fn0088a4f0(texture);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00884990 score 2 (default case jumps to another copy of the epilogue)
void nSGLDX7_cGDriver::TexParameter(uint32_t, uint32_t parameter, int32_t value)
{
    uint32_t texture = STG_ac47ec[mnTexStage].mnTexture;
    if (mb13c) {
        if (!TM_ac47ec->Fn0088a610(texture, parameter, value)) {
            mnError = 1;
            return;
        }
    }
    Stage_ac47ec* stage = &STG_ac47ec[mnTexStage];
    switch (parameter) {
    case 0:
        if (stage->mn0c != static_cast<uint32_t>(value)) {
            stage->mn0c = value;
            mbStagesDirty = true;
            stage->mbDirty = 1;
        }
        break;
    case 1:
        if (stage->mn10 != static_cast<uint32_t>(value)) {
            stage->mn10 = value;
            mbStagesDirty = true;
            stage->mbDirty = 1;
        }
        break;
    case 2:
        if (stage->mn14 != static_cast<uint32_t>(value)) {
            stage->mn14 = value;
            mbStagesDirty = true;
            stage->mbDirty = 1;
        }
        break;
    case 3:
        if (stage->mn18 != static_cast<uint32_t>(value)) {
            stage->mn18 = value;
            mbStagesDirty = true;
            stage->mbDirty = 1;
        }
        break;
    }
}
#endif

// FUNCTION: 0x00883240
void nSGLDX7_cGDriver::ColorMultiplier(float r, float g, float b)
{
    PM_ac47ec->Fn00889de0();
    if (!mbLighting) {
        mbLighting = true;
        uint32_t hr = DEV_ac47ec->SetRenderState(137, 1);
        CHECK_ac47ec(hr);
    }
    MAT_ac47ec->mAmbient[0] = 1.0f;
    MAT_ac47ec->mAmbient[1] = 1.0f;
    MAT_ac47ec->mAmbient[2] = 1.0f;
    DEV_ac47ec->SetMaterial(MAT_ac47ec);
    uint32_t hr = DEV_ac47ec->SetRenderState(139, Fn00881ab0(r, g, b, 1.0f));
    CHECK_ac47ec(hr);
}

// FUNCTION: 0x00883310
void nSGLDX7_cGDriver::AlphaMultiplier(float alpha)
{
    PM_ac47ec->Fn00889de0();
    if (!mbLighting) {
        mbLighting = true;
        uint32_t hr = DEV_ac47ec->SetRenderState(137, 1);
        CHECK_ac47ec(hr);
    }
    MAT_ac47ec->mDiffuse[3] = alpha;
    uint32_t hr = DEV_ac47ec->SetMaterial(MAT_ac47ec);
    CHECK_ac47ec(hr);
    if (alpha < 1.0) {
        DEV_ac47ec->SetRenderState(145, 0);
    } else if (mbVertexSpecular) {
        DEV_ac47ec->SetRenderState(145, 1);
    }
}

// FUNCTION: 0x00884000
void nSGLDX7_cGDriver::Slot05_ac3508(float r, float g, float b, float)
{
    float fr = r + 49152.0f;
    int32_t ir = reinterpret_cast<int32_t&>(fr) - 0x47400000;
    float fg = g + 49152.0f;
    int32_t ig = reinterpret_cast<int32_t&>(fg) - 0x47400000;
    float fb = b + 49152.0f;
    int32_t ib = reinterpret_cast<int32_t&>(fb) - 0x47400000;
    uint32_t color = (((0xffffff00u | static_cast<uint8_t>(ir - (static_cast<uint32_t>(ir) >> 8))) << 8 |
                       static_cast<uint8_t>(ig - (static_cast<uint32_t>(ig) >> 8))) << 8) |
                     static_cast<uint8_t>(ib - (static_cast<uint32_t>(ib) >> 8));
    uint32_t hr = PM_ac47ec->Fn00889de0();
    CHECK_ac47ec(hr);
    hr = DEV_ac47ec->SetRenderState(139, color);
    CHECK_ac47ec(hr);
}

// FUNCTION: 0x008840d0
void nSGLDX7_cGDriver::Slot11_ac3508(uint32_t parameter, uint32_t values)
{
    const float* v = OB_PTR(const float, values);
    switch (parameter) {
    case 0:
        MAT_ac47ec->mAmbient[0] = v[0];
        MAT_ac47ec->mAmbient[1] = v[1];
        MAT_ac47ec->mAmbient[2] = v[2];
        MAT_ac47ec->mAmbient[3] = v[3];
        break;
    case 1:
        MAT_ac47ec->mDiffuse[0] = v[0];
        MAT_ac47ec->mDiffuse[1] = v[1];
        MAT_ac47ec->mDiffuse[2] = v[2];
        MAT_ac47ec->mDiffuse[3] = v[3];
        break;
    case 2:
        MAT_ac47ec->mSpecular[0] = v[0];
        MAT_ac47ec->mSpecular[1] = v[1];
        MAT_ac47ec->mSpecular[2] = v[2];
        MAT_ac47ec->mSpecular[3] = v[3];
        break;
    case 3:
        MAT_ac47ec->mEmissive[0] = v[0];
        MAT_ac47ec->mEmissive[1] = v[1];
        MAT_ac47ec->mEmissive[2] = v[2];
        MAT_ac47ec->mEmissive[3] = v[3];
        break;
    case 4:
        MAT_ac47ec->mfPower = v[0];
        break;
    }
    uint32_t hr = PM_ac47ec->Fn00889de0();
    CHECK_ac47ec(hr);
    hr = DEV_ac47ec->SetMaterial(MAT_ac47ec);
    CHECK_ac47ec(hr);
}

// FUNCTION: 0x00884200
void nSGLDX7_cGDriver::Slot10_ac3508(uint32_t ambient, uint32_t diffuse, uint32_t specular, uint32_t emissive, uint32_t power)
{
    const float* pAmbient = OB_PTR(const float, ambient);
    const float* pDiffuse = OB_PTR(const float, diffuse);
    const float* pSpecular = OB_PTR(const float, specular);
    const float* pEmissive = OB_PTR(const float, emissive);
    if (pAmbient) {
        MAT_ac47ec->mAmbient[0] = pAmbient[0];
        MAT_ac47ec->mAmbient[1] = pAmbient[1];
        MAT_ac47ec->mAmbient[2] = pAmbient[2];
        MAT_ac47ec->mAmbient[3] = pAmbient[3];
    }
    if (pDiffuse) {
        MAT_ac47ec->mDiffuse[0] = pDiffuse[0];
        MAT_ac47ec->mDiffuse[1] = pDiffuse[1];
        MAT_ac47ec->mDiffuse[2] = pDiffuse[2];
        MAT_ac47ec->mDiffuse[3] = pDiffuse[3];
    }
    if (pSpecular) {
        MAT_ac47ec->mSpecular[0] = pSpecular[0];
        MAT_ac47ec->mSpecular[1] = pSpecular[1];
        MAT_ac47ec->mSpecular[2] = pSpecular[2];
        MAT_ac47ec->mSpecular[3] = pSpecular[3];
    }
    if (pEmissive) {
        MAT_ac47ec->mEmissive[0] = pEmissive[0];
        MAT_ac47ec->mEmissive[1] = pEmissive[1];
        MAT_ac47ec->mEmissive[2] = pEmissive[2];
        MAT_ac47ec->mEmissive[3] = pEmissive[3];
    }
    float fPower = *reinterpret_cast<float*>(&power);
    if (fPower >= 0.0f) {
        MAT_ac47ec->mfPower = fPower;
    }
    uint32_t hr = PM_ac47ec->Fn00889de0();
    CHECK_ac47ec(hr);
    hr = DEV_ac47ec->SetMaterial(MAT_ac47ec);
    CHECK_ac47ec(hr);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00886b90 score 37 (register allocation; the temp light local)
void nSGLDX7_cGDriver::Slot07_ac3508(uint32_t light, uint32_t parameter, uint32_t values)
{
    if (LIGHTS_ac47ec->size() <= light) {
        D3DLight_ac47ec fresh;
        LIGHTS_ac47ec->Fn00886b30(light + 1, fresh);
    }
    D3DLight_ac47ec* entry = &LIGHTS_ac47ec->mpBegin[light];
    const float* v = OB_PTR(const float, values);
    switch (parameter) {
    case 0:
        entry->mAmbient[0] = v[0];
        entry->mAmbient[1] = v[1];
        entry->mAmbient[2] = v[2];
        entry->mAmbient[3] = v[3];
        break;
    case 1:
        entry->mDiffuse[0] = v[0];
        entry->mDiffuse[1] = v[1];
        entry->mDiffuse[2] = v[2];
        entry->mDiffuse[3] = v[3];
        break;
    case 2:
        entry->mSpecular[0] = v[0];
        entry->mSpecular[1] = v[1];
        entry->mSpecular[2] = v[2];
        entry->mSpecular[3] = v[3];
        break;
    }
    uint32_t hr = PM_ac47ec->Fn00889de0();
    CHECK_ac47ec(hr);
    hr = DEV_ac47ec->SetLight(light, entry);
    CHECK_ac47ec(hr);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00886ca0 score 33 (register allocation; the temp light local)
void nSGLDX7_cGDriver::Slot06_ac3508(uint32_t light, const void* ambient, const void* diffuse, const void* specular)
{
    if (LIGHTS_ac47ec->size() <= light) {
        D3DLight_ac47ec fresh;
        LIGHTS_ac47ec->Fn00886b30(light + 1, fresh);
    }
    D3DLight_ac47ec* entry = &LIGHTS_ac47ec->mpBegin[light];
    const float* pAmbient = static_cast<const float*>(ambient);
    const float* pDiffuse = static_cast<const float*>(diffuse);
    const float* pSpecular = static_cast<const float*>(specular);
    if (pAmbient) {
        entry->mAmbient[0] = pAmbient[0];
        entry->mAmbient[1] = pAmbient[1];
        entry->mAmbient[2] = pAmbient[2];
        entry->mAmbient[3] = pAmbient[3];
    }
    if (pDiffuse) {
        entry->mDiffuse[0] = pDiffuse[0];
        entry->mDiffuse[1] = pDiffuse[1];
        entry->mDiffuse[2] = pDiffuse[2];
        entry->mDiffuse[3] = pDiffuse[3];
    }
    if (pSpecular) {
        entry->mSpecular[0] = pSpecular[0];
        entry->mSpecular[1] = pSpecular[1];
        entry->mSpecular[2] = pSpecular[2];
        entry->mSpecular[3] = pSpecular[3];
    }
    uint32_t hr = PM_ac47ec->Fn00889de0();
    CHECK_ac47ec(hr);
    hr = DEV_ac47ec->SetLight(light, entry);
    CHECK_ac47ec(hr);
}
#endif

// The index conversions: write 16-bit indices from a list of 8/16/32-bit ones (or build the lists of a quad, strip or
// fan) and report the smallest and the largest index seen.

#ifdef OB_DRAFTS
// CLOSE: 0x0088b460 score 30 (loop counter and index width)
void Fn0088b460(int32_t count, uint16_t* out)
{
    uint32_t position = 0;
    if (0 < count) {
        int16_t base = 2;
        uint16_t next;
        do {
            uint32_t at = position & 0xffff;
            out[at] = base - 2;
            out[at + 3] = base - 2;
            out[at + 2] = base;
            out[at + 4] = base;
            out[at + 1] = base - 1;
            out[at + 5] = base + 1;
            next = base + 2;
            position = position + 6;
            base = base + 4;
        } while (static_cast<int32_t>(next) < count);
    }
}
#endif

// FUNCTION: 0x0088b4c0
void Fn0088b4c0(int32_t count, uint16_t* out)
{
    int32_t i = 0;
    if (0 < count - 2) {
        uint16_t* p = out + 2;
        do {
            int16_t v = static_cast<int16_t>(i);
            p[-1] = v + 1;
            p[0] = v + 3;
            p[2] = v + 3;
            p[-2] = v;
            p[1] = v;
            p[3] = v + 2;
            i = i + 2;
            p = p + 6;
        } while (i < count - 2);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0088b510 score 45 (strip winding branch layout)
void Fn0088b510(int32_t count, uint16_t* out)
{
    uint32_t n = 0;
    if (0 < count) {
        uint32_t at = 0;
        int16_t base = 2;
        do {
            int16_t other;
            out[at + 2] = base;
            if ((n & 1) == 0) {
                out[at] = base - 2;
                other = base - 1;
            } else {
                out[at] = base - 1;
                other = base - 2;
            }
            n = n + 3;
            out[at + 1] = other;
            at = n & 0xffff;
            base = base + 1;
        } while (static_cast<int32_t>(at) < count);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088b570 score 7 (register order)
void Fn0088b570(int32_t count, uint16_t* out)
{
    uint32_t n = 0;
    if (0 < count) {
        uint32_t at = 0;
        int16_t base = 2;
        do {
            n = n + 3;
            out[at + 2] = base;
            out[at] = 0;
            out[at + 1] = base - 1;
            at = n & 0xffff;
            base = base + 1;
        } while (static_cast<int32_t>(at) < count);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088bba0 score 65 (min/max update branch layout)
void Fn0088bba0(int32_t count, const uint32_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t max = *source;
    uint32_t min = max;
    if (count < 1) {
        *pMin = max;
        *pMax = max;
        return;
    }
    do {
        uint32_t value = *source;
        uint32_t newMin = value;
        if (min <= value) {
            newMin = min;
            if (max < value) {
                max = value;
            }
        }
        *out = static_cast<uint16_t>(*source);
        out = out + 1;
        source = source + 1;
        count = count - 1;
        min = newMin;
    } while (count != 0);
    *pMin = min;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088bc00 score 69 (min/max update branch layout)
void Fn0088bc00(int32_t count, const uint16_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t max = *source;
    uint32_t min = max;
    if (count < 1) {
        *pMin = max;
        *pMax = max;
        return;
    }
    do {
        uint32_t value = *source;
        uint32_t newMin = value;
        if (min <= value) {
            newMin = min;
            if (max < value) {
                max = value;
            }
        }
        *out = *source;
        out = out + 1;
        source = source + 1;
        count = count - 1;
        min = newMin;
    } while (count != 0);
    *pMin = min;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088bc60 score 73 (min/max update branch layout)
void Fn0088bc60(int32_t count, const uint8_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t max = *source;
    uint32_t min = max;
    if (count < 1) {
        *pMin = max;
        *pMax = max;
        return;
    }
    do {
        uint32_t value = *source;
        uint32_t newMin = value;
        if (min <= value) {
            newMin = min;
            if (max < value) {
                max = value;
            }
        }
        *out = static_cast<uint16_t>(*source);
        out = out + 1;
        source = source + 1;
        count = count - 1;
        min = newMin;
    } while (count != 0);
    *pMin = min;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00882800 score 80 (min/max update branch layout)
void Fn00882800(uint32_t count, const uint32_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t first = source[0];
    uint32_t previous = source[1];
    source = source + 2;
    int32_t total = count * 3;
    uint32_t max = first;
    uint32_t min = previous;
    if (first < previous) {
        max = previous;
        min = first;
    }
    if (total != 6) {
        uint16_t* p = out + 2;
        int32_t n = (total - 7u) / 3 + 1;
        uint32_t current = max;
        do {
            uint32_t value = *source;
            source = source + 1;
            p[-2] = static_cast<uint16_t>(first);
            p[-1] = static_cast<uint16_t>(previous);
            p[0] = static_cast<uint16_t>(value);
            max = value;
            if (value <= current) {
                max = current;
                if (value < min) {
                    min = value;
                }
            }
            p = p + 3;
            n = n - 1;
            current = max;
            previous = value;
        } while (n != 0);
    }
    *pMin = min;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00882760 score 98 (min/max update branch layout)
void Fn00882760(uint32_t count, const uint16_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint16_t first = source[0];
    uint16_t previous = source[1];
    source = source + 2;
    int32_t total = count * 3;
    uint16_t hi = first;
    uint16_t lo = previous;
    if (first < previous) {
        hi = previous;
        lo = first;
    }
    uint32_t min = lo;
    uint32_t max = hi;
    if (total != 6) {
        uint16_t* p = out + 2;
        int32_t n = (total - 7u) / 3 + 1;
        uint32_t current = max;
        do {
            uint16_t value = *source;
            p[-1] = previous;
            source = source + 1;
            p[-2] = first;
            p[0] = value;
            max = value;
            if (value <= current) {
                max = current;
                if (value < min) {
                    min = value;
                }
            }
            p = p + 3;
            n = n - 1;
            current = max;
            previous = value;
        } while (n != 0);
    }
    *pMin = min;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00882890 score 107 (min/max update branch layout)
void Fn00882890(int32_t count, const uint8_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint8_t previous = source[1];
    uint8_t first = source[0];
    source = source + 2;
    uint8_t lo = previous;
    uint8_t hi = first;
    if (first < previous) {
        lo = first;
        hi = previous;
    }
    uint32_t max = hi;
    uint32_t min = lo;
    if (count * 3 != 6) {
        uint16_t* p = out + 2;
        int32_t n = (count * 3 - 7u) / 3 + 1;
        uint32_t current = max;
        do {
            uint8_t value = *source;
            p[-2] = first;
            p[-1] = previous;
            p[0] = value;
            source = source + 1;
            max = value;
            if (value <= current) {
                max = current;
                if (value < min) {
                    min = value;
                }
            }
            p = p + 3;
            n = n - 1;
            current = max;
            previous = value;
        } while (n != 0);
    }
    *pMin = min;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00882690 score 137 (min/max update and strip winding branch layout)
void Fn00882690(int32_t count, const uint8_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint8_t a = source[0];
    uint8_t b = source[1];
    source = source + 2;
    uint8_t lo = b;
    uint8_t hi = a;
    if (a < b) {
        lo = a;
        hi = b;
    }
    uint32_t min = lo;
    uint32_t n = 0;
    if (static_cast<uint32_t>(count * 3) == 6) {
        *pMin = min;
        *pMax = hi;
        return;
    }
    uint16_t* p = out + 2;
    uint32_t current = hi;
    uint32_t max;
    do {
        uint8_t value = *source;
        p[-1] = b;
        p[0] = value;
        source = source + 1;
        p[-2] = a;
        max = value;
        if (value <= current) {
            max = current;
            if (value < min) {
                min = value;
            }
        }
        uint8_t next = value;
        if (n & 1) {
            next = a;
            b = value;
        }
        a = next;
        n = n + 3;
        p = p + 3;
        current = max;
    } while (n < static_cast<uint32_t>(count * 3 - 6));
    *pMin = min;
    *pMax = max;
}
#endif

// Copies the lights [first, last) to result and returns the end of the copy (the last two arguments are the
// algorithm's iterator-category and distance tags).
// FUNCTION: 0x00882960
D3DLight_ac47ec* Fn00882960(const D3DLight_ac47ec* first, const D3DLight_ac47ec* last, D3DLight_ac47ec* result, void*, const void*)
{
    int32_t n = static_cast<int32_t>(last - first);
    for (; n > 0; --n) {
        *result = *first;
        ++first;
        ++result;
    }
    return result;
}

// FUNCTION: 0x00886b30
void LightVec_ac47ec::Fn00886b30(uint32_t newSize, const D3DLight_ac47ec& fill)
{
    D3DLight_ac47ec* begin = mpBegin;
    D3DLight_ac47ec* end = mpEnd;
    if (newSize < size()) {
        char tag;
        mpEnd = Fn00882960(end, end, begin + newSize, &tag, 0);
        return;
    }
    Fn008865a0(end, newSize - size(), fill);
}

// Maps a source pixel type and a format to the index of the texture format that holds it (false: no such pair).
#ifdef OB_DRAFTS
// CLOSE: 0x0088d0b0 score 40 (nested switch layout)
bool Fn0088d0b0(uint32_t type, uint32_t format, uint32_t* result)
{
    switch (format) {
    case 0:
    case 1:
        switch (type) {
        case 1:
            *result = 1;
            return true;
        case 3:
            *result = 0;
            return true;
        case 0:
            *result = 3;
            return true;
        case 2:
            *result = 2;
            return true;
        case 7:
        case 8:
            *result = 10;
            return true;
        case 9:
            *result = 12;
            return true;
        case 10:
            *result = 14;
            return true;
        }
        break;
    case 13:
        if (type == 1) {
            *result = 5;
            return true;
        }
        if (type == 3) {
            *result = 4;
            return true;
        }
        break;
    case 10:
        if (type == 1) {
            *result = 7;
            return true;
        }
        if (type == 3) {
            *result = 6;
            return true;
        }
        break;
    case 14:
        if (type == 0) {
            *result = 9;
            return true;
        }
        if (type == 2) {
            *result = 8;
            return true;
        }
        break;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088a610 score 35 (switch case order and vector index arithmetic)
bool TexMgr_ac47ec::Fn0088a610Draft_ac47ec(uint32_t id, uint32_t parameter, uint32_t value)
{
    if (id < mTextures.size()) {
        Tex_ac47ec* texture = &mTextures[id];
        if (texture->mbUsed) {
            switch (parameter) {
            case 2:
                texture->mn24 = value;
                return true;
            case 3:
                texture->mn28 = value;
                return true;
            case 1:
                texture->mn20 = value;
                return true;
            case 0:
                texture->mn1c = value;
                return true;
            }
        }
    }
    return false;
}
#endif

// FUNCTION: 0x0088ac40
void TexMgr_ac47ec::Fn0088ac40(Unknown_ac47ec* device)
{
    Unknown_ac47ec* old = mpDevice;
    if (device != old) {
        if (device) {
            device->AddRef();
        }
        mpDevice = device;
        if (old) {
            old->Release();
        }
    }
    uint32_t count = mTextures.size();
    for (uint32_t i = 0; i < count; i++) {
        Tex_ac47ec* texture = &mTextures[i];
        if (texture->mbUsed && texture->mnWidth) {
            Fn0088a900(i, texture->mnHints, texture->mnFormat, texture->mnWidth, texture->mnHeight, texture->mnLevels);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0088b0d0 score 26 (vector erase and release sequence)
void TexMgr_ac47ec::Fn0088b0d0()
{
    if (mTextures.mpBegin != mTextures.mpEnd) {
        Fn0088adf0(0);
    }
    mTextures.Fn0088aed0(mTextures.mpBegin, mTextures.mpEnd);
    mFreeIds.mpEnd = mFreeIds.mpBegin;
    Unknown_ac47ec* device = mpDevice;
    if (device) {
        mpDevice = 0;
        device->Release();
    }
    Unknown_ac47ec* directDraw = mpDirectDraw;
    if (directDraw) {
        mpDirectDraw = 0;
        directDraw->Release();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088a900 score 14 (register allocation)
bool TexMgr_ac47ec::Fn0088a900Draft_ac47ec(uint32_t id, uint32_t hints, uint32_t format, uint32_t width, uint32_t height, uint32_t levels)
{
    if (id >= mTextures.size()) {
        return false;
    }
    Tex_ac47ec* texture = &mTextures[id];
    if (!texture->mbUsed) {
        return false;
    }
    if (height < 1 || width < 1 || height > 0x1000 || width > 0x1000) {
        return false;
    }
    texture->mnHeight = height;
    texture->mnLevels = levels;
    texture->mnHints = hints;
    texture->mnFormat = format;
    texture->mnWidth = width;
    FormatEntry_ac47ec entry = mFormats[format];
    if (mpDevice) {
        return Fn0088a720(&entry, hints, width, height, levels, reinterpret_cast<SurfaceRef_ac47ec*>(&texture->mpSurface)->Fn008846d0());
    }
    if (texture->mpSurface) {
        Unknown_ac47ec* surface = texture->mpSurface;
        texture->mpSurface = 0;
        surface->Release();
    }
    return true;
}
#endif

// Keeps the smallest and the largest index seen.
#define MINMAX_ac47ec(min, max, value) \
    if ((value) < (min)) { \
        (min) = (value); \
    } else if ((max) < (value)) { \
        (max) = (value); \
    }

#ifdef OB_DRAFTS
// CLOSE: 0x0088b5c0 score 106 (min/max update structure (macro) and loop layout)
void Fn0088b5c0(int32_t count, const uint32_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t min = source[0];
    uint32_t max = min;
    int32_t total = (count / 2) * 3;
    uint16_t at = 0;
    if (total == 0) {
        *pMin = min;
        *pMax = min;
        return;
    }
    uint16_t* p = out + 2;
    int32_t loops = (total - 1u) / 6 + 1;
    do {
        p[-2] = static_cast<uint16_t>(source[at]);
        MINMAX_ac47ec(min, max, source[at]);
        p[-1] = static_cast<uint16_t>(source[at + 1]);
        MINMAX_ac47ec(min, max, source[at + 1]);
        p[0] = static_cast<uint16_t>(source[at + 2]);
        MINMAX_ac47ec(min, max, source[at + 2]);
        p[1] = p[-2];
        p[2] = p[0];
        p[3] = static_cast<uint16_t>(source[at + 3]);
        MINMAX_ac47ec(min, max, source[at + 3]);
        at = at + 4;
        p = p + 6;
        loops = loops - 1;
    } while (loops != 0);
    *pMin = min;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088b6c0 score 125 (min/max update structure (macro) and loop layout)
void Fn0088b6c0(uint32_t count, const uint16_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t max = source[0];
    uint32_t min = max;
    int32_t total = (static_cast<int32_t>(count) / 2) * 3;
    uint32_t at = 0;
    if (total == 0) {
        *pMin = max;
        *pMax = max;
        return;
    }
    uint16_t* p = out + 2;
    int32_t loops = (total - 1u) / 6 + 1;
    do {
        uint32_t i = at & 0xffff;
        p[-2] = source[i];
        MINMAX_ac47ec(min, max, source[i]);
        p[-1] = source[i + 1];
        MINMAX_ac47ec(min, max, source[i + 1]);
        p[0] = source[i + 2];
        MINMAX_ac47ec(min, max, source[i + 2]);
        p[1] = source[i];
        p[2] = source[i + 2];
        p[3] = source[i + 3];
        MINMAX_ac47ec(min, max, source[i + 3]);
        p = p + 6;
        at = at + 4;
        loops = loops - 1;
    } while (loops != 0);
    *pMin = min;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088b7b0 score 76 (min/max update structure (macro) and loop layout)
void Fn0088b7b0(int32_t count, const uint8_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t min = source[0];
    int32_t total = (count / 2) * 3;
    if (total != 0) {
        uint16_t* p = out + 2;
        int32_t loops = (total - 1u) / 6 + 1;
        uint32_t max = min;
        do {
            p[-2] = source[0];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(source[0]));
            p[-1] = source[1];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(source[1]));
            p[0] = source[2];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(source[2]));
            p[1] = source[0];
            p[2] = source[2];
            p[3] = source[3];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(source[3]));
            p = p + 6;
            source = source + 4;
            loops = loops - 1;
        } while (loops != 0);
        *pMin = min;
        *pMax = max;
        return;
    }
    *pMin = min;
    *pMax = min;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088b8b0 score 104 (min/max update structure (macro) and loop layout)
void Fn0088b8b0(int32_t count, const uint32_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t max = source[0];
    uint32_t min = max;
    if (count * 3 == 6) {
        *pMin = max;
        *pMax = max;
        return;
    }
    uint16_t* p = out + 1;
    int32_t loops = (count * 3 - 7u) / 6 + 1;
    do {
        const uint32_t* next = source + 2;
        p[-1] = static_cast<uint16_t>(source[0]);
        MINMAX_ac47ec(min, max, source[0]);
        p[0] = static_cast<uint16_t>(source[1]);
        MINMAX_ac47ec(min, max, source[1]);
        p[1] = static_cast<uint16_t>(*next);
        MINMAX_ac47ec(min, max, *next);
        p[2] = p[0];
        p[3] = static_cast<uint16_t>(source[3]);
        MINMAX_ac47ec(min, max, source[3]);
        p[4] = p[1];
        p = p + 6;
        loops = loops - 1;
        source = next;
    } while (loops != 0);
    *pMin = min;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088baa0 score 123 (min/max update structure (macro) and loop layout)
void Fn0088baa0(int32_t count, const uint8_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t max = source[0];
    uint32_t at = 0;
    if (count * 3 != 6) {
        uint16_t* p = out + 2;
        int32_t loops = (count * 3 - 7u) / 6 + 1;
        uint32_t min = max;
        do {
            const uint8_t* q = source + (at & 0xffff);
            p[-2] = q[0];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(q[0]));
            p[-1] = q[1];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(q[1]));
            p[0] = q[2];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(q[2]));
            p[1] = q[1];
            p[2] = q[3];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(q[3]));
            p[3] = q[2];
            p = p + 6;
            at = at + 2;
            loops = loops - 1;
        } while (loops != 0);
        *pMin = min;
        *pMax = max;
        return;
    }
    *pMin = max;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088b980 score 68 (min/max update structure (macro) and loop layout)
void Fn0088b980(int32_t count, const uint16_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t max = source[0];
    uint32_t at = 0;
    if (count * 3 != 6) {
        uint16_t* p = out + 2;
        int32_t loops = (count * 3 - 7u) / 6 + 1;
        uint32_t min = max;
        do {
            uint32_t i = at & 0xffff;
            p[-2] = source[i];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(source[i]));
            p[-1] = source[i + 1];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(source[i + 1]));
            p[0] = source[i + 2];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(source[i + 2]));
            p[1] = source[i + 1];
            p[2] = source[i + 3];
            MINMAX_ac47ec(min, max, static_cast<uint32_t>(source[i + 3]));
            p[3] = source[i + 2];
            p = p + 6;
            at = at + 2;
            loops = loops - 1;
        } while (loops != 0);
        *pMin = min;
        *pMax = max;
        return;
    }
    *pMin = max;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008824f0 score 135 (min/max update structure (macro) and loop layout)
void Fn008824f0(uint32_t count, const uint16_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint16_t b = source[1];
    uint16_t a = source[0];
    int32_t total = count * 3;
    source = source + 2;
    uint16_t lo = b;
    uint16_t hi = a;
    if (a < b) {
        lo = a;
        hi = b;
    }
    uint32_t max = hi;
    uint32_t min = lo;
    uint32_t n = 0;
    if (total == 6) {
        *pMin = min;
        *pMax = max;
        return;
    }
    uint16_t* p = out + 2;
    do {
        uint16_t value = *source;
        source = source + 1;
        p[-2] = a;
        p[-1] = b;
        p[0] = value;
        uint32_t newMax = value;
        if (value <= max) {
            newMax = max;
            if (value < min) {
                min = value;
            }
        }
        max = newMax;
        if ((n & 1) != 0) {
            b = value;
            value = a;
        }
        n = n + 3;
        p = p + 3;
        a = value;
    } while (n < total - 6u);
    *pMin = min;
    *pMax = max;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008825d0 score 98 (min/max update structure (macro) and loop layout)
void Fn008825d0(uint32_t count, const uint32_t* source, uint16_t* out, uint32_t* pMin, uint32_t* pMax)
{
    uint32_t b = source[1];
    uint32_t a = source[0];
    int32_t total = count * 3;
    source = source + 2;
    uint32_t max = a;
    uint32_t min = b;
    if (a < b) {
        max = b;
        min = a;
    }
    uint32_t n = 0;
    if (total == 6) {
        *pMin = min;
        *pMax = max;
        return;
    }
    uint16_t* p = out + 2;
    uint32_t newMax;
    do {
        uint32_t value = *source;
        source = source + 1;
        p[-2] = static_cast<uint16_t>(a);
        p[-1] = static_cast<uint16_t>(b);
        p[0] = static_cast<uint16_t>(value);
        newMax = value;
        if (value <= max) {
            newMax = max;
            if (value < min) {
                min = value;
            }
        }
        if ((n & 1) != 0) {
            b = value;
            value = a;
        }
        n = n + 3;
        p = p + 3;
        max = newMax;
        a = value;
    } while (n < total - 6u);
    *pMin = min;
    *pMax = newMax;
}
#endif

// FUNCTION: 0x00881970
uint32_t Fn00881970(const float* m)
{
    if (reinterpret_cast<const uint32_t*>(m)[0] == 0x3f800000 && m[1] == 0.0f && m[2] == 0.0f && m[3] == 0.0f &&
        m[4] == 0.0f && reinterpret_cast<const uint32_t*>(m)[5] == 0x3f800000 && m[6] == 0.0f && m[7] == 0.0f &&
        m[8] == 0.0f && m[9] == 0.0f && reinterpret_cast<const uint32_t*>(m)[10] == 0x3f800000 && m[11] == 0.0f &&
        m[12] == 0.0f && m[13] == 0.0f && m[14] == 0.0f && reinterpret_cast<const uint32_t*>(m)[15] == 0x3f800000) {
        return 1;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00882a00 score 48 (switch/compare-tree layout)
bool nSGLDX7_cGDriver::QueryInterface(uint32_t iid, void** object)
{
    switch (iid) {
    case 0x87e2b87d:
        if (this) {
            *object = static_cast<cUnk00ac3508*>(this);
        } else {
            *object = 0;
        }
        cUnk00ace624::AddRef();
        return true;
    case 1:
    case 0xa4554849:
        if (this) {
            *object = static_cast<cIGZGDriver*>(this);
        } else {
            *object = 0;
        }
        cUnk00ace624::AddRef();
        return true;
    case 0x09cd86f9:
        *object = mpPrimMgr;
        reinterpret_cast<Unknown_ac47ec*>(mpPrimMgr)->AddRef();
        return true;
    case 0x6ca5e5fe:
        *object = static_cast<cUnk00ac34cc*>(this);
        cUnk00ace624::AddRef();
        return true;
    case 0xe69bfe2a:
        if (this) {
            *object = static_cast<cUnk00ac34f8*>(this);
        } else {
            *object = 0;
        }
        cUnk00ace624::AddRef();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008837e0 score 2 (register allocation of the clamps)
void nSGLDX7_cGDriver::SetViewport(int32_t x, int32_t y, int32_t width, int32_t height)
{
    uint32_t hr = PM_ac47ec->Fn00889de0();
    CHECK_ac47ec(hr);
    uint32_t maxWidth = mViewport[2];
    uint32_t left = x;
    if (left > maxWidth) {
        left = maxWidth;
    }
    uint32_t maxHeight = mViewport[3];
    uint32_t top = y;
    if (top > maxHeight) {
        top = maxHeight;
    }
    uint32_t w = width;
    if (left + w > maxWidth) {
        w = maxWidth - left;
    }
    uint32_t h = height;
    if (top + h > maxHeight) {
        h = maxHeight - top;
    }
    uint32_t viewport[6];
    viewport[0] = left;
    viewport[1] = maxHeight - top - h;
    viewport[2] = w;
    viewport[3] = h;
    viewport[4] = mViewport[4];
    viewport[5] = mViewport[5];
    hr = DEV_ac47ec->SetViewport(viewport);
    CHECK_ac47ec(hr);
    uint32_t saved = mn214;
    mn214 = 1;
    LoadMatrix(mMatrix150);
    mn214 = saved;
}
#endif

// FUNCTION: 0x00883600
void nSGLDX7_cGDriver::TexStageMatrix(const float* matrix, uint32_t dimensions, uint32_t count, uint32_t flags)
{
    uint32_t hr = PM_ac47ec->Fn00889de0();
    CHECK_ac47ec(hr);
    if (matrix && !Fn00881970(matrix)) {
        float m[16];
        std::memcpy(m, matrix, sizeof m);
        if ((dimensions == 3 && !(flags & 1)) || (dimensions == 4 && (flags & 1))) {
            m[8] = -m[8];
            m[9] = -m[9];
            m[10] = -m[10];
            m[11] = -m[11];
        }
        uint32_t value = count;
        if (flags & 2) {
            value = count | 0x100;
        }
        DEV_ac47ec->SetTextureStageState(mnTexStage, 24, value);
        DEV_ac47ec->SetTransform(16 + mnTexStage, m);
        return;
    }
    DEV_ac47ec->SetTextureStageState(mnTexStage, 24, 0);
}

// FUNCTION: 0x00884a70
void nSGLDX7_cGDriver::SetCombiner(const cGDCombiner& combiner, uint32_t stage)
{
    uint32_t colorTable[4] = {2, 3, 4, 5};
    uint32_t alphaTable[4] = {4, 5, 4, 5};
    PM_ac47ec->Fn00889de0();
    Stage_ac47ec* record = &STG_ac47ec[stage];
    const uint8_t* c = reinterpret_cast<const uint8_t*>(&combiner);
    record->mnTexEnvMode = 4;
    record->mbDirty = 1;
    mbStagesDirty = true;
    if (c[0] != 0xff) {
        record->mn24 = c[0];
        record->mn28 = c[4];
        record->mn2c = c[1] & 0xf;
        record->mn30 = c[2] & 0xf;
        record->mn34 = c[3] & 0xf;
        record->mn38 = c[5] & 0xf;
        record->mn3c = c[6] & 0xf;
        record->mn40 = c[7] & 0xf;
        record->mn44 = colorTable[c[1] >> 4];
        record->mn48 = colorTable[c[2] >> 4];
        record->mn4c = colorTable[c[3] >> 4];
        record->mn50 = alphaTable[c[5] >> 4];
        record->mn54 = alphaTable[c[6] >> 4];
        record->mn58 = alphaTable[c[7] >> 4];
        record->mn5c = c[8];
        record->mn60 = c[9];
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00886a10 score 121 (vector clear/push_back inline expansion)
bool nSGLDX7_cGDriver::DeleteAllBufferRegions()
{
    BufferRegion_ac47ec* begin = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin);
    int32_t count = static_cast<int32_t>(reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd) - begin);
    for (int32_t i = 0; i < count; i++) {
        Unknown_ac47ec* surface = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin)[i].mpSurface;
        if (surface) {
            surface->Release();
            reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin)[i].mpSurface = 0;
        }
    }
    mpBufferRegionsEnd = mpBufferRegionsBegin;
    BufferRegion_ac47ec empty;
    empty.mnId = 0;
    empty.mn04 = 0;
    empty.mpSurface = 0;
    empty.mn0c = 0;
    empty.mn10 = 0;
    empty.mn14 = 0;
    empty.mn18 = 0;
    if (mpBufferRegionsEnd != mpBufferRegionsCap) {
        if (mpBufferRegionsEnd) {
            *reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd) = empty;
        }
        mpBufferRegionsEnd = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd) + 1;
    } else {
        reinterpret_cast<BufferRegionVec_ac47ec*>(&mpBufferRegionsBegin)->Fn00748f20(reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd), &empty, &empty, 1, 1);
    }
    BufferRegion_ac47ec* first = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin);
    first->mnId = 0;
    first->mn04 = 0;
    first->mpSurface = 0;
    first->mn0c = 0;
    first->mn10 = 0;
    first->mn14 = 0;
    first->mn18 = 0;
    return true;
}
#endif

// GLOBAL: 0x00ac4618
extern float gfAc4618[16];

#ifdef OB_DRAFTS
// CLOSE: 0x00882ac0 score 28 (fp expression order of the projection fix-up)
void nSGLDX7_cGDriver::LoadMatrix(const float* matrix)
{
    PM_ac47ec->Fn00889de0();
    if (mn214 == 0) {
        DEV_ac47ec->SetTransform(1, matrix);
        DEV_ac47ec->SetTransform(2, gfAc4618);
        return;
    }
    if (mn214 == 1) {
        std::memcpy(mMatrix150, matrix, sizeof mMatrix150);
        float m[16];
        std::memcpy(m, matrix, sizeof m);
        uint32_t viewport[6];
        DEV_ac47ec->GetViewport(viewport);
        float a = -0.5f / (static_cast<float>(viewport[2]) * 0.5f);
        float b = 0.5f / (static_cast<float>(viewport[3]) * 0.5f);
        m[0] = m[3] * a + m[0];
        m[1] = m[3] * b + m[1];
        m[2] = (m[2] + m[3]) * 0.5f;
        m[4] = m[7] * a + m[4];
        m[5] = m[7] * b + m[5];
        m[6] = (m[6] + m[7]) * 0.5f;
        m[12] = m[15] * a + m[12];
        m[13] = m[15] * b + m[13];
        m[14] = (m[14] + m[15]) * 0.5f;
        m[8] = -(m[11] * a + m[8]);
        m[9] = -(m[11] * b + m[9]);
        m[10] = -((m[10] + m[11]) * 0.5f);
        m[11] = -m[11];
        DEV_ac47ec->SetTransform(3, m);
    }
}
#endif

// Sets the stage up for drawing: the texture and its wrap and filter states (false: no usable texture, the stage is
// switched off).
#ifdef OB_DRAFTS
// CLOSE: 0x00884320 score 3 (a wrap/filter case order)
bool Stage_ac47ec::Fn00884320Draft_ac47ec(uint32_t index, Device7_ac47ec* device, TexMgr_ac47ec* textures)
{
    if (mb01) {
        Tex_ac47ec* texture = textures->Fn0088a550(mnTexture);
        if (texture && texture->mpSurface) {
            device->SetTexture(index, texture->mpSurface);
            switch (mn0c) {
            case 0:
                device->SetTextureStageState(index, 16, 1);
                break;
            case 1:
                device->SetTextureStageState(index, 16, 2);
                break;
            }
            switch (mn10) {
            case 0:
                device->SetTextureStageState(index, 17, 1);
                device->SetTextureStageState(index, 18, 1);
                break;
            case 1:
                device->SetTextureStageState(index, 17, 2);
                device->SetTextureStageState(index, 18, 1);
                break;
            case 4:
                device->SetTextureStageState(index, 17, 1);
                device->SetTextureStageState(index, 18, 2);
                break;
            case 5:
                device->SetTextureStageState(index, 17, 2);
                device->SetTextureStageState(index, 18, 2);
                device->SetTextureStageState(index, 17, 1);
                device->SetTextureStageState(index, 18, 3);
                break;
            case 6:
                device->SetTextureStageState(index, 17, 2);
                device->SetTextureStageState(index, 18, 3);
                break;
            }
            switch (mn14) {
            case 2:
                device->SetTextureStageState(index, 13, 3);
                break;
            case 3:
                device->SetTextureStageState(index, 13, 1);
                break;
            }
            switch (mn18) {
            case 2:
                device->SetTextureStageState(index, 14, 3);
                break;
            case 3:
                device->SetTextureStageState(index, 14, 1);
                break;
            }
            return true;
        }
    }
    mn20 = 0xffffffff;
    device->SetTextureStageState(index, 1, 1);
    device->SetTextureStageState(index, 4, 1);
    return false;
}
#endif

// Sets the stage's texture environment (the fixed combiner modes) for drawing.
// FUNCTION: 0x00884500
void Stage_ac47ec::Fn00884500(uint32_t index, Device7_ac47ec* device)
{
    switch (mnTexEnvMode) {
    case 0:
        device->SetTextureStageState(index, 2, 2);
        device->SetTextureStageState(index, 1, 2);
        device->SetTextureStageState(index, 5, 2);
        device->SetTextureStageState(index, 4, 2);
        break;
    case 1:
        device->SetTextureStageState(index, 1, 4);
        device->SetTextureStageState(index, 2, 2);
        device->SetTextureStageState(index, 3, 1);
        if (mb02) {
            device->SetTextureStageState(index, 4, 4);
            device->SetTextureStageState(index, 5, 2);
            device->SetTextureStageState(index, 6, 1);
        } else {
            device->SetTextureStageState(index, 4, 2);
            device->SetTextureStageState(index, 5, 1);
        }
        break;
    case 2:
        if (mb02) {
            device->SetTextureStageState(index, 2, 2);
            device->SetTextureStageState(index, 1, 13);
            device->SetTextureStageState(index, 3, 1);
            device->SetTextureStageState(index, 4, 3);
            device->SetTextureStageState(index, 6, 1);
        } else {
            device->SetTextureStageState(index, 1, 2);
            device->SetTextureStageState(index, 2, 2);
            device->SetTextureStageState(index, 4, 2);
            device->SetTextureStageState(index, 5, 1);
        }
        break;
    case 3:
        device->SetTextureStageState(index, 1, 1);
        device->SetTextureStageState(index, 4, 1);
        break;
    case 4:
    case 5:
        Fn00882100(index, device);
        Fn00882300(index, device);
        break;
    }
}

// The surface description (DDSURFACEDESC2) fields the converters read.
struct SurfaceDesc_ac47ec {
    uint32_t mnSize;
    uint32_t mnFlags;
    uint32_t mnHeight;
    uint32_t mnWidth;
    uint32_t mnPitch;
    uint8_t mPad14[0x24 - 0x14];
    void* mpSurface;
    uint8_t mPad28[0x54 - 0x28];
    uint32_t mnBitCount;
    uint8_t mPad58[0x7c - 0x58];
};

// A pixel conversion routine: copies and converts a block of pixels.
typedef void (*ConvertFn_ac47ec)(void* dest, const void* source, uint32_t destPitch, uint32_t sourcePitch, uint32_t width, uint32_t height);

// Walks down `levels` attached surfaces from a surface and locks the one reached (restoring it when it was lost);
// returns the locked surface, or 0.
#ifdef OB_DRAFTS
// CLOSE: 0x0088aa10 score 121 (loop and retry layout)
Surface7_ac47ec* Fn0088aa10(Surface7_ac47ec* surface, int32_t levels, SurfaceDesc_ac47ec* desc)
{
    if (!surface) {
        return 0;
    }
    uint32_t caps[4];
    caps[0] = 0;
    caps[1] = 0x401000;
    caps[2] = 0;
    caps[3] = 0;
    Surface7_ac47ec* current = surface;
    Surface7_ac47ec* child = 0;
    if (levels > 0) {
        int32_t n = levels;
        do {
            if (child) {
                Surface7_ac47ec* old = child;
                child = 0;
                old->Release();
            }
            uint32_t hr = current->GetAttachedSurface(caps, &child);
            current = child;
            if (hr) {
                if (child) {
                    child->Release();
                }
                return 0;
            }
            n = n - 1;
        } while (n != 0);
        if (child) {
            child->Release();
        }
    }
    uint32_t hr = current->Lock(0, desc, 0x2821, 0);
    while (hr == 0x887601c2 && static_cast<int32_t>(current->Restore()) >= 0) {
        hr = current->Lock(0, desc, 0x2821, 0);
    }
    return hr != 0 ? 0 : current;
}
#endif

// Converts a block of pixels into a locked surface at (x, y) through the conversion routine.
#ifdef OB_DRAFTS
// CLOSE: 0x0088a380 score 6 (argument push order)
bool Fn0088a380(ConvertFn_ac47ec convert, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t sourcePitch, const void* pixels, SurfaceDesc_ac47ec* desc)
{
    if (!convert) {
        return false;
    }
    if (desc->mnFlags & 0x80000) {
        if (x != 0 || y != 0) {
            return false;
        }
        uint32_t pitch = desc->mnPitch;
        convert(desc->mpSurface, pixels, pitch, pitch, pitch, 1);
        return true;
    }
    uint32_t pitch = desc->mnPitch;
    char* dest = static_cast<char*>(desc->mpSurface) + pitch * y + (desc->mnBitCount >> 3) * x;
    convert(dest, pixels, pitch, sourcePitch, width, height);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0088acd0 score 112 (descriptor setup and push order)
bool TexMgr_ac47ec::Fn0088acd0Draft_ac47ec(uint32_t id, uint32_t level, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t format, uint32_t type, uint32_t rowLength, const void* pixels)
{
    if (!Fn0088a490(id)) {
        return false;
    }
    Tex_ac47ec* texture = &mTextures[id];
    if (level != 0 && level >= texture->mnLevels) {
        return false;
    }
    uint32_t index;
    if (!Fn0088d0b0(format, type, &index)) {
        return false;
    }
    ConvertFn_ac47ec convert = reinterpret_cast<ConvertFn_ac47ec>(mConverters[texture->mnFormat + index * 8]);
    if (!convert) {
        return false;
    }
    uint32_t pitchPixels = rowLength;
    if (pitchPixels == 0) {
        pitchPixels = width;
    }
    uint32_t sourcePitch = (Fn0088d050(index) * pitchPixels) >> 3;
    SurfaceDesc_ac47ec desc;
    std::memset(&desc, 0, sizeof desc);
    desc.mnSize = 0x7c;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(&desc) + 0x48) = 0x20;
    Surface7_ac47ec* locked = Fn0088aa10(reinterpret_cast<Surface7_ac47ec*>(texture->mpSurface), level, &desc);
    if (!locked) {
        return false;
    }
    Fn0088a380(convert, x, y, width, height, sourcePitch, pixels, &desc);
    locked->Unlock(0);
    return true;
}
#endif

// Takes the device down: unbinds the textures, drops the buffer regions and releases every Direct3D and DirectDraw
// object the driver holds.
#ifdef OB_DRAFTS
// CLOSE: 0x008870b0 score 2 (one instruction order)
void nSGLDX7_cGDriver::Fn008870b0()
{
    if (mpDevice) {
        for (uint32_t i = 0; i < mnMaxTextureStages; i++) {
            DEV_ac47ec->SetTexture(i, 0);
        }
    }
    DeleteAllBufferRegions();
    Unknown_ac47ec* object = reinterpret_cast<Unknown_ac47ec*>(mp22c);
    if (object) {
        mp22c = 0;
        object->Release();
    }
    object = reinterpret_cast<Unknown_ac47ec*>(mp228);
    if (object) {
        mp228 = 0;
        object->Release();
    }
    object = reinterpret_cast<Unknown_ac47ec*>(mp230);
    if (object) {
        mp230 = 0;
        object->Release();
    }
    object = reinterpret_cast<Unknown_ac47ec*>(mp234);
    if (object) {
        mp234 = 0;
        object->Release();
    }
    object = reinterpret_cast<Unknown_ac47ec*>(mpDevice);
    if (object) {
        mpDevice = 0;
        object->Release();
    }
    object = reinterpret_cast<Unknown_ac47ec*>(mpDirect3D);
    if (object) {
        mpDirect3D = 0;
        object->Release();
    }
    object = reinterpret_cast<Unknown_ac47ec*>(mpDirectDraw);
    if (object) {
        mpDirectDraw = 0;
        object->Release();
    }
    if (mpObject258) {
        ReleasableObject_ac47ec* held = reinterpret_cast<ReleasableObject_ac47ec*>(mpObject258);
        mpObject258 = 0;
        held->Release();
    }
    mb25c = false;
    mb25d = false;
}
#endif

// The Windows functions the video mode code calls.
OB_WINAPI void* OB_STDCALL LoadLibraryA(const char* name);
OB_WINAPI void* OB_STDCALL GetProcAddress(void* module, const char* name);
OB_WINAPI int32_t OB_STDCALL FreeLibrary(void* module);
OB_WINAPI void* OB_STDCALL GetModuleHandleA(const char* name);
OB_WINAPI void* OB_STDCALL CreateWindowExA(uint32_t exStyle, const char* className, const char* title, uint32_t style, int32_t x, int32_t y, int32_t width, int32_t height, void* parent, void* menu, void* instance, void* param);
OB_WINAPI int32_t OB_STDCALL DestroyWindow(void* window);
OB_WINAPI int32_t OB_STDCALL SetWindowLongA(void* window, int32_t index, int32_t value);
OB_WINAPI int32_t OB_STDCALL AdjustWindowRect(int32_t* rect, uint32_t style, int32_t menu);
OB_WINAPI int32_t OB_STDCALL SetWindowPos(void* window, void* after, int32_t x, int32_t y, int32_t width, int32_t height, uint32_t flags);
OB_WINAPI int32_t OB_STDCALL ShowWindow(void* window, int32_t command);
OB_WINAPI int32_t OB_STDCALL SetForegroundWindow(void* window);

// GLOBAL: 0x00b12288
extern const char* gpB12288;
// GLOBAL: 0x00b1228c
extern const char* gpB1228c;
// GLOBAL: 0x00a804f4
extern void* gpA804f4;
// GLOBAL: 0x00aed0c0
extern const uint8_t gIidAed0c0[16];

// The DirectDraw object (IDirectDraw7), seen through the display-mode enumeration slot.
struct DirectDraw7_ac47ec {
    virtual uint32_t STDCALL_ac47ec QueryInterface(const void* iid, void** object);
    virtual uint32_t STDCALL_ac47ec AddRef();
    virtual uint32_t STDCALL_ac47ec Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual uint32_t STDCALL_ac47ec EnumDisplayModes(uint32_t flags, void* desc, void* context, void* callback);
};

// The callback the mode enumeration calls for each mode (records it in the driver passed as the context).
// STUB: 0x008882f0
int32_t STDCALL_ac47ec Fn008882f0(void* desc, void* context);

typedef int32_t (STDCALL_ac47ec *DirectDrawCreateEx_ac47ec)(void* guid, void** directDraw, const void* iid, void* outer);

// FUNCTION: 0x008885f0
uint32_t nSGLDX7_cGDriver::CountVideoModes() const
{
    if (mnModeCount == 0) {
        void* library = LoadLibraryA("DDRAW.DLL");
        if (library) {
            DirectDrawCreateEx_ac47ec create = reinterpret_cast<DirectDrawCreateEx_ac47ec>(GetProcAddress(library, "DirectDrawCreateEx"));
            if (create) {
                DirectDraw7_ac47ec* directDraw;
                if (create(0, reinterpret_cast<void**>(&directDraw), gIidAed0c0, 0) >= 0) {
                    directDraw->EnumDisplayModes(0, 0, const_cast<nSGLDX7_cGDriver*>(this), reinterpret_cast<void*>(Fn008882f0));
                    directDraw->Release();
                }
            }
            FreeLibrary(library);
        }
    }
    return mnModeCount;
}

// Ends the scene and tears the device down: textures, the stage list, the draw lists and every Direct3D object.
#ifdef OB_DRAFTS
// CLOSE: 0x008881d0 score 65 (vector erase inline, register order)
void nSGLDX7_cGDriver::Fn008881d0()
{
    if (mb260) {
        if (mpDevice) {
            uint32_t hr = DEV_ac47ec->EndScene();
            if (hr) {
                mnError = ErrorFromHr_ac47ec(hr);
            }
        }
        mb260 = false;
    }
    for (uint32_t i = 0; i < mnTexStageCount; i++) {
        if (mpDevice) {
            DEV_ac47ec->SetTexture(i, 0);
        }
    }
    mnTexStageCount = 0;
    mpStagesEnd = mpStages;
    TM_ac47ec->Fn0088b0d0();
    PM_ac47ec->Fn0088a1a0();
    Fn008870b0();
    mbTexturesReady = false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00888f50 score 123 (window creation sequence; Win32 import names guessed from the call shapes)
void nSGLDX7_cGDriver::SetVideoMode(int32_t index, void* window, bool fullScreen, bool force)
{
    if (mb260) {
        if (mpDevice) {
            uint32_t hr = DEV_ac47ec->EndScene();
            if (hr) {
                mnError = ErrorFromHr_ac47ec(hr);
            }
            mb260 = false;
        }
    }
    if (index == -1) {
        if (mCurrentMode[0] == 0xffffffff) {
            return;
        }
        if (mhWnd == 0) {
            return;
        }
        Fn008881d0();
        DestroyWindow(mhWnd);
        mhWnd = 0;
        mCurrentMode[0] = 0xffffffff;
        return;
    }
    mb25f = force;
    void* instance = GetModuleHandleA(0);
    if (static_cast<uint32_t>(index) >= mnModeCount) {
        mnError = 2;
        return;
    }
    if (mCurrentMode[0] != 0xffffffff) {
        SetVideoMode(-1, 0, false, false);
    }
    void* procedure = window;
    if (procedure == 0) {
        procedure = gpA804f4;
    }
    mpWndProc = procedure;
    GetVideoModeInfo(index, *reinterpret_cast<sGDMode*>(mCurrentMode));
    ModeView_ac47ec* mode = MODE_ac47ec;
    if (mode->mbFullscreen) {
        mb25e = false;
        mhWnd = CreateWindowExA(0, gpB12288, gpB1228c, 0x86000000, 0, 0, mode->mnWidth, mode->mnHeight, 0, 0, instance, 0);
        SetWindowLongA(mhWnd, -21, static_cast<int32_t>(OB_ADDR(this)));
    } else {
        int32_t rect[4];
        mb25e = true;
        rect[0] = 0;
        rect[1] = 0;
        rect[2] = mode->mnWidth;
        rect[3] = mode->mnHeight;
        AdjustWindowRect(rect, 0x10cf0000, 0);
        mhWnd = CreateWindowExA(0, gpB12288, gpB1228c, 0x10cf0000, 0, 0, 0, 0, 0, 0, instance, 0);
        SetWindowLongA(mhWnd, -21, static_cast<int32_t>(OB_ADDR(this)));
        SetWindowPos(mhWnd, 0, 0, 0, rect[2] - rect[0], rect[3] - rect[1], 6);
    }
    if (!Fn00888e10()) {
        Fn008881d0();
        DestroyWindow(mhWnd);
        mhWnd = 0;
    }
    if (mhWnd == 0) {
        mnError = 6;
        mCurrentMode[0] = 0xffffffff;
        return;
    }
    if (force) {
        ShowWindow(mhWnd, 5);
        SetForegroundWindow(mhWnd);
    }
}
#endif

// The destination or source surface of a blit (the Blt slot of a DirectDraw surface).
struct BltSurface_ac47ec {
    virtual uint32_t STDCALL_ac47ec QueryInterface(const void* iid, void** object);
    virtual uint32_t STDCALL_ac47ec AddRef();
    virtual uint32_t STDCALL_ac47ec Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual uint32_t STDCALL_ac47ec Blt(const int32_t* destRect, BltSurface_ac47ec* source, const int32_t* sourceRect, uint32_t flags, void* fx);
};

// Copies a rectangle of a buffer region's surface back to the screen buffer it was read from.
#ifdef OB_DRAFTS
// CLOSE: 0x008855f0 score 194 (inline vector index checks and register order)
bool nSGLDX7_cGDriver::Slot07_ac34cc(uint32_t id, uint32_t sourceX, uint32_t sourceY, uint32_t width, uint32_t height, uint32_t destX, uint32_t destY)
{
    if (mbDeviceLost == 0 && static_cast<int32_t>(sourceX) >= 0 && static_cast<int32_t>(sourceY) >= 0) {
        uint32_t right = sourceX + width;
        uint32_t bottom = sourceY + height;
        BufferRegion_ac47ec* begin = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin);
        uint32_t index = id - 1;
        if (right <= mViewport[2] && bottom <= mViewport[3] && index <= static_cast<uint32_t>(reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd) - begin) &&
            index == begin[index].mnId && static_cast<int32_t>(right) <= static_cast<int32_t>(begin[index].mn14) &&
            static_cast<int32_t>(bottom) <= static_cast<int32_t>(begin[index].mn18)) {
            BufferRegion_ac47ec* region = &begin[index];
            uint32_t hr = PM_ac47ec->Fn00889de0();
            if (hr) {
                mnError = ErrorFromHr_ac47ec(hr);
            }
            if (region->mpSurface && mp230) {
                BltSurface_ac47ec* target;
                if (region->mn04 == 0) {
                    target = reinterpret_cast<BltSurface_ac47ec*>(mp22c);
                } else if (region->mn04 == 1) {
                    target = reinterpret_cast<BltSurface_ac47ec*>(mp230);
                } else if (region->mn04 == 2) {
                    target = reinterpret_cast<BltSurface_ac47ec*>(mp234);
                } else {
                    return false;
                }
                if (target) {
                    int32_t destRect[4];
                    int32_t sourceRect[4];
                    destRect[0] = destX;
                    destRect[1] = destY;
                    destRect[2] = width + destX;
                    destRect[3] = height + destY;
                    sourceRect[0] = sourceX;
                    sourceRect[1] = sourceY;
                    sourceRect[2] = right;
                    sourceRect[3] = bottom;
                    uint32_t result = target->Blt(destRect, reinterpret_cast<BltSurface_ac47ec*>(region->mpSurface), sourceRect, 0x1000000, 0);
                    return (~result >> 31) != 0;
                }
            }
        }
    }
    return false;
}
#endif

// Copies a rectangle of a screen buffer into a buffer region's surface.
#ifdef OB_DRAFTS
// CLOSE: 0x008853b0 score 221 (inline vector index checks and register order)
bool nSGLDX7_cGDriver::Slot06_ac34cc(uint32_t id, uint32_t sourceX, uint32_t sourceY, uint32_t width, uint32_t height, uint32_t destX, uint32_t destY)
{
    if (mbDeviceLost == 0 && static_cast<int32_t>(sourceX) >= 0 && static_cast<int32_t>(sourceY) >= 0 &&
        width + sourceX <= mViewport[2] && height + sourceY <= mViewport[3]) {
        uint32_t hr = PM_ac47ec->Fn00889de0();
        if (hr) {
            mnError = ErrorFromHr_ac47ec(hr);
        }
        BufferRegion_ac47ec* region = &reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin)[id - 1];
        if (region->mpSurface) {
            BltSurface_ac47ec* buffer;
            if (region->mn04 == 0) {
                buffer = reinterpret_cast<BltSurface_ac47ec*>(mp22c);
            } else if (region->mn04 == 1) {
                buffer = reinterpret_cast<BltSurface_ac47ec*>(mp230);
            } else if (region->mn04 == 2) {
                buffer = reinterpret_cast<BltSurface_ac47ec*>(mp234);
            } else {
                return false;
            }
            if (buffer) {
                int32_t destRect[4];
                int32_t sourceRect[4];
                sourceRect[0] = destX;
                sourceRect[1] = destY;
                sourceRect[2] = width + destX;
                sourceRect[3] = height + destY;
                destRect[0] = sourceX;
                destRect[1] = sourceY;
                destRect[2] = width + sourceX;
                destRect[3] = height + sourceY;
                uint32_t result = reinterpret_cast<BltSurface_ac47ec*>(region->mpSurface)->Blt(destRect, buffer, sourceRect, 0x1000000, 0);
                return (~result >> 31) != 0;
            }
        }
    }
    return false;
}
#endif

// A DirectDraw surface with the description and creation slots (only the ones called here are named).
struct DrawSurface_ac47ec {
    virtual uint32_t STDCALL_ac47ec QueryInterface(const void* iid, void** object);
    virtual uint32_t STDCALL_ac47ec AddRef();
    virtual uint32_t STDCALL_ac47ec Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual uint32_t STDCALL_ac47ec GetPixelFormat(uint32_t* format);
    virtual uint32_t STDCALL_ac47ec GetSurfaceDesc(uint32_t* desc);
};

// The DirectDraw object's surface creation slot.
struct DrawCreator_ac47ec {
    virtual uint32_t STDCALL_ac47ec QueryInterface(const void* iid, void** object);
    virtual uint32_t STDCALL_ac47ec AddRef();
    virtual uint32_t STDCALL_ac47ec Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual uint32_t STDCALL_ac47ec CreateSurface(uint32_t* desc, Unknown_ac47ec** surface, void* outer);
};

// The Direct3D object's texture-eviction slot.
struct Direct3D7_ac47ec {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual uint32_t STDCALL_ac47ec EvictManagedTextures();
};

// Creates a buffer region for one of the screen buffers (0, 1 or 2): an off-screen surface of the buffer's size and
// format; returns the region's number (1-based) or 0.
#ifdef OB_DRAFTS
// CLOSE: 0x00886750 score 332 (inline vector push_back, loop layout and COM call setup)
uint32_t nSGLDX7_cGDriver::Slot04_ac34cc(uint32_t which)
{
    if (mbDeviceLost) {
        return 0;
    }
    BufferRegion_ac47ec* begin = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin);
    int32_t count = static_cast<int32_t>(reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd) - begin);
    int32_t index = 0;
    uint32_t result = 0;
    BufferRegion_ac47ec* region = 0;
    if (0 < count) {
        BufferRegion_ac47ec* walk = begin;
        do {
            region = walk;
            if (region->mnId == 0xffffffff) {
                break;
            }
            index = index + 1;
            walk = walk + 1;
        } while (index < count);
    }
    if (index == count) {
        BufferRegion_ac47ec empty;
        empty.mnId = 0;
        empty.mn04 = 0;
        empty.mpSurface = 0;
        empty.mn0c = 0;
        empty.mn10 = 0;
        empty.mn14 = 0;
        empty.mn18 = 0;
        if (mpBufferRegionsEnd == mpBufferRegionsCap) {
            reinterpret_cast<BufferRegionVec_ac47ec*>(&mpBufferRegionsBegin)->Fn00748f20(reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd), &empty, &empty, 1, 1);
        } else {
            if (mpBufferRegionsEnd) {
                *reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd) = empty;
            }
            mpBufferRegionsEnd = reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsEnd) + 1;
        }
        region = &reinterpret_cast<BufferRegion_ac47ec*>(mpBufferRegionsBegin)[index];
        region->mnId = 0xffffffff;
        region->mn04 = 0;
        region->mpSurface = 0;
        region->mn0c = 0;
        region->mn10 = 0;
        region->mn14 = 0;
        region->mn18 = 0;
    }
    DrawSurface_ac47ec* source = 0;
    if (which == 0) {
        source = reinterpret_cast<DrawSurface_ac47ec*>(mp22c);
    } else if (which == 1) {
        source = reinterpret_cast<DrawSurface_ac47ec*>(mp230);
    } else if (which == 2) {
        source = reinterpret_cast<DrawSurface_ac47ec*>(mp234);
    } else {
        source = 0;
    }
    if (which <= 2 && source) {
        uint32_t format[8];
        format[0] = 0x20;
        if (static_cast<int32_t>(source->GetPixelFormat(format)) >= 0) {
            uint32_t sourceDesc[31];
            std::memset(sourceDesc, 0, sizeof sourceDesc);
            sourceDesc[0] = 0x7c;
            if (static_cast<int32_t>(source->GetSurfaceDesc(sourceDesc)) >= 0) {
                uint32_t desc[31];
                std::memset(desc, 0, sizeof desc);
                desc[3] = sourceDesc[3];
                desc[2] = sourceDesc[2];
                desc[0] = 0x7c;
                desc[1] = 0x1007;
                for (int32_t i = 0; i < 8; i++) {
                    desc[18 + i] = format[i];
                }
                if (which == 0) {
                    desc[26] |= 0x40;
                } else if (which == 1 || which == 2) {
                    desc[26] |= 0x20000;
                }
                if ((sourceDesc[30] & 0x4000) == 0) {
                    desc[26] |= 0x800;
                } else {
                    desc[26] |= 0x4000;
                }
                DrawCreator_ac47ec* creator = reinterpret_cast<DrawCreator_ac47ec*>(mpDirectDraw);
                if (creator) {
                    Unknown_ac47ec** slot = &region->mpSurface;
                    uint32_t hr = creator->CreateSurface(desc, slot, 0);
                    if (hr == 0x8876017c) {
                        reinterpret_cast<Direct3D7_ac47ec*>(mpDirect3D)->EvictManagedTextures();
                        hr = reinterpret_cast<DrawCreator_ac47ec*>(mpDirectDraw)->CreateSurface(format, slot, 0);
                    }
                    if (static_cast<int32_t>(hr) < 0) {
                        *slot = 0;
                    }
                }
            }
        }
    }
    if (region->mpSurface) {
        region->mnId = index;
        region->mn04 = which;
        region->mn14 = mViewport[2];
        result = index + 1;
        region->mn18 = mViewport[3];
    }
    return result;
}
#endif

// Draws `count` vertices of the interleaved array: brings the dirty texture stages up to date, then hands the
// primitive to the primitive manager (strips, fans and quads are turned into triangle lists first).
#ifdef OB_DRAFTS
// CLOSE: 0x008857e0 score 143 (stage loop and primitive switch layout)
void nSGLDX7_cGDriver::DrawArrays(uint32_t mode, int32_t first, int32_t count)
{
    uint32_t stage = 0;
    if (PM_ac47ec->mp10 == 0) {
        return;
    }
    if (mbStagesDirty) {
        PM_ac47ec->Fn00889de0();
        if (mnTexStageCount != 0) {
            uint32_t offset = 0;
            do {
                Stage_ac47ec* record = reinterpret_cast<Stage_ac47ec*>(reinterpret_cast<char*>(mpStages) + offset);
                if (record->mbDirty) {
                    Device7_ac47ec* device = DEV_ac47ec;
                    TexMgr_ac47ec* textures = TM_ac47ec;
                    record->mbDirty = 0;
                    if (record->Fn00884320(stage, device, textures) && record->mn20 != record->mnTexEnvMode) {
                        record->mn20 = record->mnTexEnvMode;
                        record->Fn00884500(stage, device);
                    }
                }
                stage = stage + 1;
                offset = offset + 0x80;
            } while (stage < mnTexStageCount);
        }
        mbStagesDirty = false;
    }
    if (count < 1) {
        return;
    }
    int32_t vertices = mnVertexStride * first + static_cast<int32_t>(OB_ADDR(mpVertices));
    int32_t total = count;
    uint32_t hr = 0;
    uint32_t indexCount;
    uint16_t* indices;
    switch (mode) {
    case 0:
    case 3:
    case 4:
    case 5:
        hr = PM_ac47ec->Fn00889e00(mnVertexFormat, gnAc44cc[mode], mnVertexStride, 0, total, vertices, 0, 0);
        break;
    case 1:
        indexCount = (count * 3 - 6u) & 0xffff;
        indices = PM_ac47ec->Fn0088a240(indexCount);
        Fn0088b510(indexCount, indices);
        hr = PM_ac47ec->Fn00889e00(mnVertexFormat, 4, mnVertexStride, 0, total, vertices, indexCount, indices);
        break;
    case 2:
        indexCount = (count * 3 - 6u) & 0xffff;
        indices = PM_ac47ec->Fn0088a240(indexCount);
        Fn0088b570(indexCount, indices);
        hr = PM_ac47ec->Fn00889e00(mnVertexFormat, 4, mnVertexStride, 0, total, vertices, indexCount, indices);
        break;
    case 6:
        indexCount = ((count / 2) * 3) & 0xffff;
        indices = PM_ac47ec->Fn0088a240(indexCount);
        Fn0088b460(count, indices);
        hr = PM_ac47ec->Fn00889e00(mnVertexFormat, 4, mnVertexStride, 0, total, vertices, indexCount, indices);
        break;
    case 7:
        indexCount = (count * 3 - 6u) & 0xffff;
        indices = PM_ac47ec->Fn0088a240(indexCount);
        Fn0088b4c0(count, indices);
        hr = PM_ac47ec->Fn00889e00(mnVertexFormat, 4, mnVertexStride, 0, total, vertices, indexCount, indices);
        break;
    }
    if (hr) {
        mnError = ErrorFromHr_ac47ec(hr);
    }
}
#endif

// Draws `count` indexed vertices: like DrawArrays, with the indices converted to 16-bit ones and the vertex range
// worked out from the smallest and largest index.
#ifdef OB_DRAFTS
// CLOSE: 0x00885a00 score 439 (stage loop and nested index-type switches)
void nSGLDX7_cGDriver::DrawElements(uint32_t mode, int32_t count, uint32_t indexType, const void* indices)
{
    uint32_t stage = 0;
    if (PM_ac47ec->mp10 == 0) {
        return;
    }
    if (mbStagesDirty) {
        PM_ac47ec->Fn00889de0();
        if (((reinterpret_cast<char*>(mpStagesEnd) - reinterpret_cast<char*>(mpStages)) >> 7) != 0) {
            uint32_t offset = 0;
            do {
                Stage_ac47ec* record = reinterpret_cast<Stage_ac47ec*>(reinterpret_cast<char*>(mpStages) + offset);
                if (record->mbDirty) {
                    Device7_ac47ec* device = DEV_ac47ec;
                    TexMgr_ac47ec* textures = TM_ac47ec;
                    record->mbDirty = 0;
                    if (record->Fn00884320(stage, device, textures) && record->mn20 != record->mnTexEnvMode) {
                        record->mn20 = record->mnTexEnvMode;
                        record->Fn00884500(stage, device);
                    }
                }
                stage = stage + 1;
                offset = offset + 0x80;
            } while (stage < static_cast<uint32_t>((reinterpret_cast<char*>(mpStagesEnd) - reinterpret_cast<char*>(mpStages)) >> 7));
        }
        mbStagesDirty = false;
    }
    if (count < 1) {
        return;
    }
    uint32_t vertices = OB_ADDR(mpVertices);
    uint32_t minIndex;
    uint32_t maxIndex;
    uint16_t* converted;
    uint32_t indexCount = count;
    uint32_t primitive = 4;
    switch (mode) {
    case 0:
    case 3:
    case 4:
    case 5:
        converted = PM_ac47ec->Fn0088a240(count);
        if (indexType == 1) {
            Fn0088bc60(count, static_cast<const uint8_t*>(indices), converted, &minIndex, &maxIndex);
        } else if (indexType == 3) {
            Fn0088bc00(count, static_cast<const uint16_t*>(indices), converted, &minIndex, &maxIndex);
        } else if (indexType == 5) {
            Fn0088bba0(count, static_cast<const uint32_t*>(indices), converted, &minIndex, &maxIndex);
        }
        primitive = gnAc44cc[mode];
        break;
    case 1:
        indexCount = (count * 3 - 6u) & 0xffff;
        converted = PM_ac47ec->Fn0088a240(indexCount);
        if (indexType == 1) {
            Fn00882690(count, static_cast<const uint8_t*>(indices), converted, &minIndex, &maxIndex);
        } else if (indexType == 3) {
            Fn008824f0(count, static_cast<const uint16_t*>(indices), converted, &minIndex, &maxIndex);
        } else if (indexType == 5) {
            Fn008825d0(count, static_cast<const uint32_t*>(indices), converted, &minIndex, &maxIndex);
        }
        break;
    case 2:
        indexCount = (count * 3 - 6u) & 0xffff;
        converted = PM_ac47ec->Fn0088a240(indexCount);
        if (indexType == 1) {
            Fn00882890(count, static_cast<const uint8_t*>(indices), converted, &minIndex, &maxIndex);
        } else if (indexType == 3) {
            Fn00882760(count, static_cast<const uint16_t*>(indices), converted, &minIndex, &maxIndex);
        } else if (indexType == 5) {
            Fn00882800(count, static_cast<const uint32_t*>(indices), converted, &minIndex, &maxIndex);
        }
        break;
    case 6:
        indexCount = ((count / 2) * 3) & 0xffff;
        converted = PM_ac47ec->Fn0088a240(indexCount);
        if (indexType == 1) {
            Fn0088b7b0(count, static_cast<const uint8_t*>(indices), converted, &minIndex, &maxIndex);
        } else if (indexType == 3) {
            Fn0088b6c0(count, static_cast<const uint16_t*>(indices), converted, &minIndex, &maxIndex);
        } else if (indexType == 5) {
            Fn0088b5c0(count, static_cast<const uint32_t*>(indices), converted, &minIndex, &maxIndex);
        }
        break;
    case 7:
        indexCount = (count * 3 - 6u) & 0xffff;
        converted = PM_ac47ec->Fn0088a240(indexCount);
        if (indexType == 1) {
            Fn0088baa0(count, static_cast<const uint8_t*>(indices), converted, &minIndex, &maxIndex);
        } else if (indexType == 3) {
            Fn0088b980(count, static_cast<const uint16_t*>(indices), converted, &minIndex, &maxIndex);
        } else if (indexType == 5) {
            Fn0088b8b0(count, static_cast<const uint32_t*>(indices), converted, &minIndex, &maxIndex);
        }
        break;
    default:
        return;
    }
    uint32_t hr = PM_ac47ec->Fn00889e00(mnVertexFormat, primitive, mnVertexStride, minIndex, maxIndex - minIndex + 1, vertices, indexCount, converted);
    if (hr) {
        mnError = ErrorFromHr_ac47ec(hr);
    }
}
#endif

// Puts the device's render and texture-stage states back to the driver's defaults and marks every stage dirty.
#ifdef OB_DRAFTS
// CLOSE: 0x008872a0 score 2 (one instruction order)
void nSGLDX7_cGDriver::Fn008872a0()
{
    DEV_ac47ec->SetRenderState(22, 1);
    DEV_ac47ec->SetRenderState(26, 1);
    DEV_ac47ec->SetRenderState(41, 0);
    DEV_ac47ec->SetRenderState(29, 0);
    DEV_ac47ec->SetRenderState(27, 0);
    DEV_ac47ec->SetRenderState(4, 1);
    DEV_ac47ec->SetRenderState(14, 1);
    DEV_ac47ec->SetRenderState(23, 4);
    DEV_ac47ec->SetRenderState(15, 0);
    DEV_ac47ec->SetRenderState(28, 0);
    DEV_ac47ec->SetRenderState(8, 3);
    DEV_ac47ec->SetRenderState(52, 0);
    DEV_ac47ec->SetRenderState(53, 1);
    DEV_ac47ec->SetRenderState(54, 6);
    DEV_ac47ec->SetRenderState(55, 1);
    DEV_ac47ec->SetRenderState(56, 8);
    DEV_ac47ec->SetRenderState(57, 1);
    DEV_ac47ec->SetRenderState(58, 1);
    DEV_ac47ec->SetRenderState(59, 1);
    DEV_ac47ec->SetRenderState(60, 0xffffffff);
    DEV_ac47ec->SetRenderState(139, 0);
    DEV_ac47ec->SetRenderState(137, 0);
    DEV_ac47ec->SetRenderState(147, 1);
    DEV_ac47ec->SetRenderState(145, 1);
    DEV_ac47ec->SetRenderState(146, 0);
    DEV_ac47ec->SetRenderState(141, 1);
    mbLighting = false;
    *(reinterpret_cast<uint8_t*>(this) + 0x2dd) = 0;
    mbVertexDiffuse = true;
    mbVertexSpecular = true;
    DEV_ac47ec->SetTextureStageState(0, 1, 2);
    DEV_ac47ec->SetTextureStageState(0, 12, 1);
    DEV_ac47ec->SetTextureStageState(0, 11, 0);
    DEV_ac47ec->SetTextureStageState(0, 16, 1);
    DEV_ac47ec->SetTextureStageState(0, 17, 1);
    DEV_ac47ec->SetTextureStageState(0, 18, 1);
    DEV_ac47ec->SetTextureStageState(0, 2, 2);
    DEV_ac47ec->SetTextureStageState(0, 3, 0);
    DEV_ac47ec->SetTextureStageState(0, 4, 2);
    DEV_ac47ec->SetTextureStageState(0, 5, 2);
    DEV_ac47ec->SetTextureStageState(0, 6, 0);
    DEV_ac47ec->SetTextureStageState(1, 1, 1);
    DEV_ac47ec->SetTexture(0, 0);
    uint32_t i = 0;
    mbStagesDirty = true;
    if (mnTexStageCount != 0) {
        int32_t offset = 0;
        do {
            *(reinterpret_cast<uint8_t*>(mpStages) + offset) = 1;
            i = i + 1;
            offset = offset + 0x80;
        } while (i < mnTexStageCount);
    }
}
#endif

// The driver's window-system object at +0x258 (a reference-counted object whose methods are ordinary member calls),
// seen through the slots Flush uses.
struct HostDevice_ac47ec {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Unknown_ac47ec* GetDevice();
    virtual Unknown_ac47ec* GetBackBuffer();
    virtual Unknown_ac47ec* GetDepthBuffer();
    virtual int32_t Recover();
    virtual void Done();
    virtual void Present(uint32_t flags);
};

// The DirectDraw cooperative-level test (slot 26 of IDirectDraw7).
struct CoopCheck_ac47ec {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual int32_t STDCALL_ac47ec TestCooperativeLevel();
};

// The render target getter of the device (slot 9 of IDirect3DDevice7).
// STUB: 0x0088a400
void Fn0088a400();
// STUB: 0x0088b440
Unknown_ac47ec* Fn0088b440();

// Presents the frame and keeps the device alive: when the display is lost it lets go of everything (the lost state),
// when it is back it takes the objects over again and re-applies the states; the notifications it posts to the
// framework on those changes are not reproduced.
#ifdef OB_DRAFTS
// CLOSE: 0x00884ba0 score 307 (device-lost notification posting not reproduced; COM call setup)
void nSGLDX7_cGDriver::Flush()
{
    int32_t cooperative = reinterpret_cast<CoopCheck_ac47ec*>(mpDirectDraw)->TestCooperativeLevel();
    if (cooperative < 0) {
        if (!mbDeviceLost) {
            mbDeviceLost = true;
            Fn0088a400();
            PM_ac47ec->Fn00889b60();
            Unknown_ac47ec* device = Fn0088b440();
            reinterpret_cast<ComPtr_ac47ec*>(&mpDevice)->Fn00886ef0(device);
            Unknown_ac47ec* object = reinterpret_cast<Unknown_ac47ec*>(mp230);
            if (object) {
                mp230 = 0;
                object->Release();
            }
            object = reinterpret_cast<Unknown_ac47ec*>(mp228);
            if (object) {
                mp228 = 0;
                object->Release();
            }
            object = reinterpret_cast<Unknown_ac47ec*>(mp22c);
            if (object) {
                mp22c = 0;
                object->Release();
            }
            reinterpret_cast<HostDevice_ac47ec*>(mpObject258)->Done();
        }
        return;
    }
    if (!mbDeviceLost) {
        uint32_t hr = PM_ac47ec->Fn00889de0();
        if (static_cast<int32_t>(hr) < 0) {
            mnError = ErrorFromHr_ac47ec(hr);
        }
        Fn00887260();
        reinterpret_cast<HostDevice_ac47ec*>(mpObject258)->Present(0);
        if (PM_ac47ec->mp10 == 0) {
            PM_ac47ec->Fn00889260(this, mpDirect3D, DEV_ac47ec);
        }
        Fn008871c0();
        return;
    }
    HostDevice_ac47ec* host = reinterpret_cast<HostDevice_ac47ec*>(mpObject258);
    if (host->Recover() < 0) {
        Fn00887260();
        host->Done();
        return;
    }
    mbDeviceLost = false;
    reinterpret_cast<ComPtr_ac47ec*>(&mpDevice)->Fn00886ef0(host->GetDevice());
    reinterpret_cast<ComPtr_ac47ec*>(&mp230)->Fn00886ef0(host->GetDepthBuffer());
    reinterpret_cast<ComPtr_ac47ec*>(&mp228)->Fn00886ef0(host->GetBackBuffer());
    Unknown_ac47ec* old = reinterpret_cast<Unknown_ac47ec*>(mp22c);
    Device7_ac47ec* device = DEV_ac47ec;
    if (old) {
        mp22c = 0;
        old->Release();
    }
    device->GetRenderTarget(&mp22c);
    Fn008872a0();
    if (PM_ac47ec->mp10 == 0) {
        PM_ac47ec->Fn00889260(this, mpDirect3D, DEV_ac47ec);
    }
    TM_ac47ec->Fn0088ac40(reinterpret_cast<Unknown_ac47ec*>(mpDevice));
}
#endif

// The vector of textures grows: allocates the new block, copies the elements before `pos`, the new element(s) and
// (unless the insertion is at the end) the rest, then drops the old block.
// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);
// STUB: 0x0088aaf0
Tex_ac47ec* Fn0088aaf0(Tex_ac47ec* first, Tex_ac47ec* last, Tex_ac47ec* result, const void* tag);
// STUB: 0x0088ab70
Tex_ac47ec* Fn0088ab70(Tex_ac47ec* first, uint32_t count, const Tex_ac47ec* value, const void* tag);

#ifdef OB_DRAFTS
// CLOSE: 0x0088af90 score 43 (unscored)
void TexVec_ac47ec::Fn0088af90Draft_ac47ec(Tex_ac47ec* pos, const Tex_ac47ec* value, const void* tag, uint32_t count, uint32_t atEnd)
{
    uint32_t oldSize = size();
    const uint32_t* larger = oldSize < count ? &count : &oldSize;
    uint32_t newSize = *larger + oldSize;
    Tex_ac47ec* newStart = 0;
    if (newSize != 0) {
        newStart = static_cast<Tex_ac47ec*>(Fn0090cf54(newSize * sizeof(Tex_ac47ec)));
    }
    char marker;
    Tex_ac47ec* newFinish = Fn0088aaf0(mpBegin, pos, newStart, &marker);
    if (count == 1) {
        if (newFinish) {
            newFinish->Fn0088a810(*value);
        }
        newFinish = newFinish + 1;
    } else {
        newFinish = Fn0088ab70(newFinish, count, value, &marker);
    }
    if (!atEnd) {
        newFinish = Fn0088aaf0(pos, mpEnd, newFinish, &marker);
    }
    Fn0088ae90();
    mpEnd = newFinish;
    mpBegin = newStart;
    mpCap = newStart + newSize;
}
#endif
