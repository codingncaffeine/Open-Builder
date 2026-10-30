#include <stddef.h>
#include <time.h>

#include "classes/cGZWin.h"
#include "gzcom/cIGZString.h"

// A 16-byte record (a rectangle) copied as a whole.
struct Rect_adc8d8 {
    int32_t v[4];
};

// A word seen as the pointer it holds (the class keeps pointers in 32-bit fields).

// The cursor manager (slot 32 of the window manager) and the cursor it makes.
struct Cursor_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void Activate(uint32_t on);
};

struct CursorMgr_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void P05();
    virtual void P06();
    virtual void P07();
    virtual void P08();
    virtual uint32_t CreateCursor(uint32_t kind);
};

// The window manager (field4), seen through the slots this class calls.
struct WinMgr_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void* GetMainWindow();
    virtual void P04();
    virtual void P05();
    virtual void P06();
    virtual void AppendToPlotStrategy(void* win);
    virtual void ExecutePlotStrategy();
    virtual void P09();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void PostMessageToTarget2(uint32_t win, uint32_t msg);
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void CleanUpWindowReferences(void* win);
    virtual bool DestroyWindow(void* win);
    virtual bool IsWindowValid(void* win);
    virtual void* GetWindowFromPoint(int32_t x, int32_t y);
    virtual void SetCurrentMouseWin(void* win);
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual CursorMgr_adc8d8* GetCursorManager();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void* GZGetFocus();
};

// This window seen through the slots whose declared signature (a pointer passed as a word, a result the header
// leaves out) differs from the call.
struct Self_adc8d8 {
    virtual void Q000();
    virtual void Q001();
    virtual void Q002();
    virtual void Q003();
    virtual void Q004();
    virtual void Q005();
    virtual void Q006();
    virtual void Q007();
    virtual void Q008();
    virtual void Q009();
    virtual void Q010();
    virtual void Q011();
    virtual void Q012();
    virtual void Q013();
    virtual void Q014();
    virtual void Q015();
    virtual void Q016();
    virtual void Q017();
    virtual void Q018();
    virtual void Q019();
    virtual void Q020();
    virtual void Q021();
    virtual void Q022();
    virtual void Q023();
    virtual void Q024();
    virtual void Q025();
    virtual void Q026();
    virtual void Q027();
    virtual void Q028();
    virtual void Q029();
    virtual void Q030();
    virtual void Q031();
    virtual void Q032();
    virtual void Q033();
    virtual void Q034();
    virtual void Q035();
    virtual void Q036();
    virtual void Q037();
    virtual void Q038();
    virtual void Q039();
    virtual void Q040();
    virtual void Q041();
    virtual void Q042();
    virtual void Q043();
    virtual void Q044();
    virtual void Q045();
    virtual void Q046();
    virtual void GetArea(void* rect);
    virtual void Q048();
    virtual void Q049();
    virtual void Q050();
    virtual void Q051();
    virtual void Q052();
    virtual void Q053();
    virtual void SetArea(const void* rect);
    virtual void Q055();
    virtual void Q056();
    virtual void Q057();
    virtual void Q058();
    virtual void Q059();
    virtual void Q060();
    virtual void Q061();
    virtual void Q062();
    virtual void Q063();
    virtual void Q064();
    virtual void Q065();
    virtual void Q066();
    virtual void Q067();
    virtual void Q068();
    virtual void Q069();
    virtual void Q070();
    virtual bool IsVisible();
    virtual bool IsEnabled();
    virtual void Q073();
    virtual void Q074();
    virtual void Q075();
    virtual void Q076();
    virtual void Q077();
    virtual void Q078();
    virtual void Q079();
    virtual void Q080();
    virtual void Q081();
    virtual void Q082();
    virtual void Q083();
    virtual void Q084();
    virtual void Q085();
    virtual void Q086();
    virtual void Q087();
    virtual void Q088();
    virtual void Q089();
    virtual void Q090();
    virtual void Q091();
    virtual void Q092();
    virtual void Q093();
    virtual void Q094();
    virtual void Q095();
    virtual void Q096();
    virtual void Q097();
    virtual void Q098();
    virtual void Q099();
    virtual void Q100();
    virtual void Q101();
    virtual void Q102();
    virtual void Q103();
    virtual void Q104();
    virtual void Q105();
    virtual void Q106();
    virtual void Q107();
    virtual void Q108();
    virtual void Q109();
    virtual void GetFadeEffectPeriod(void* fadeIn, void* fadeOut);
    virtual void Q111();
    virtual void Q112();
    virtual void Q113();
    virtual void Q114();
    virtual void Q115();
    virtual void Q116();
    virtual void Q117();
    virtual void Q118();
    virtual void Q119();
    virtual void Q120();
    virtual void Q121();
    virtual void Q122();
    virtual void Q123();
    virtual void Q124();
    virtual void Q125();
    virtual void Q126();
    virtual void Q127();
    virtual void Q128();
    virtual bool GZOnCharacter(uint8_t ch);
    virtual void Q130();
    virtual void Q131();
    virtual void Q132();
    virtual void Q133();
    virtual void Q134();
    virtual void Q135();
    virtual void Q136();
    virtual void Q137();
    virtual void Q138();
    virtual void Q139();
    virtual void Q140();
    virtual void Q141();
    virtual void Q142();
    virtual void Q143();
    virtual void Q144();
    virtual bool SendMsg_2(void* win, void* msg);
    virtual void Q146();
    virtual bool PostMsg_2(void* win, void* msg);
    virtual void Q148();
    virtual bool is_point_transparent(int32_t x, int32_t y);
};

// A rectangle (left, top, right, bottom) and its inline accessors.
struct RectBox_adc8d8 {
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
    int32_t Width() const { return right - left; }
    int32_t Height() const { return bottom - top; }
    // Moves the rectangle so its corner is at the point.
    void Fn0082ae40(const int32_t* point);
    // The rectangles overlap.
    uint32_t Fn0099c1e1(const RectBox_adc8d8* other);
};

// The keyboard accelerator (field78).
struct KeyAccel_adc8d8 {
    virtual void P00();
    virtual void AddRef();
    virtual void Release();
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
    virtual bool Accelerate(uint32_t msg);
};

// An 8-byte format record the buffer takes by value.
struct Fmt_adc8d8 {
    uint32_t a;
    uint32_t b;
    // STUB: 0x0044a490
    Fmt_adc8d8(uint32_t kind);
};

// A width and a height, compared by an out-of-line function.
struct Size_adc8d8 {
    int32_t w;
    int32_t h;
    // STUB: 0x00798070
    bool Equals(const Size_adc8d8* other);
};

// A pixel buffer (the private buffer at +0x64, the buffer to draw to at +0x68).
struct Buf_adc8d8 {
    virtual bool QueryInterface(uint32_t iid, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual bool Init(uint32_t width, uint32_t height, Fmt_adc8d8 format);
    virtual void Reset();
    virtual void P05();
    virtual bool Lock(uint32_t flags);
    virtual bool Unlock(uint32_t flags);
    virtual void P08();
    virtual void P09();
    virtual void P10();
    virtual void P11();
    virtual const RectBox_adc8d8* GetBufferArea_2();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual bool Fill_3(uint32_t color, void* rect, uint32_t flags);
    virtual void P21();
    virtual void P22();
    virtual void SetTransparency(uint32_t color);
    virtual bool GetTransparency();
    virtual bool IsPixelTransparent(int32_t x, int32_t y);
    virtual bool GetTransparentColor(uint32_t* color);
    virtual void RemoveTransparency();
    virtual void P28();
    virtual bool Blt(uint32_t source, void* clip, void* rect, uint32_t flags);
    virtual uint32_t ConvertRGBValueToNative(uint8_t r, uint8_t g, uint8_t b);
    virtual bool ConvertNativeValueToRGB(uint32_t color, uint8_t* r, uint8_t* g, uint8_t* b);
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
    virtual void P38();
    virtual bool Slot39();
};

// The graphics service the framework's global accessor returns.
struct Gfx_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual bool CreateBuffer(void* out);
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
    virtual uint32_t RGBToNative(uint32_t r, uint32_t g, uint32_t b);
    virtual void P35();
    virtual bool NativeToRGB(uint32_t color, void* r, void* g, void* b);
};

// STUB: 0x00913c1a
Gfx_adc8d8* Fn00913c1a();

// The same service, for the callers that pass the three components as bytes.
struct GfxBytes_adc8d8 {
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
    virtual uint32_t RGBToNative(uint8_t r, uint8_t g, uint8_t b);
};


// FUNCTION: 0x0099becc
void cGZWin::InvalidateSelf()
{
    mbInvalid = true;
}

// FUNCTION: 0x0094c47c
uint32_t cGZWin::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x0099b833
bool cGZWin::Slot16_adc8d8(uint32_t win)
{
    return OB_PTR(WinMgr_adc8d8, field4)->DestroyWindow(OB_PTR(void, win));
}

// FUNCTION: 0x0099be2a
void* cGZWin::Slot10_adc8d8()
{
    return OB_PTR(WinMgr_adc8d8, field4)->GetMainWindow();
}

// FUNCTION: 0x0099be3a
void* cGZWin::Slot38_adc8d8(int32_t x, int32_t y)
{
    return OB_PTR(WinMgr_adc8d8, field4)->GetWindowFromPoint(x, y);
}

// FUNCTION: 0x0099be54
void cGZWin::Slot49_adda20(uint32_t str)
{
    *reinterpret_cast<cIGZString*>(field50) = *OB_PTR(cIGZString, str);
}

// FUNCTION: 0x0099bdce
void cGZWin::IsVisible()
{
    Slot67_adc8d8(1);
}

// FUNCTION: 0x0099bdd9
void cGZWin::IsEnabled()
{
    Slot67_adc8d8(2);
}

// FUNCTION: 0x0099c82a
uint32_t cGZWin::GetH()
{
    return fieldb4 - fieldac;
}

// FUNCTION: 0x0099c81b
uint32_t cGZWin::GetW()
{
    return reinterpret_cast<RectBox_adc8d8*>(&unknowna0[8])->Width();
}

// FUNCTION: 0x0099ca9e
void cGZWin::GetShadeColor(uint32_t color)
{
    *OB_PTR(uint32_t, color) = fieldd0;
}

// FUNCTION: 0x0099ca1e
bool cGZWin::GetFillColor(uint32_t color)
{
    *OB_PTR(uint32_t, color) = fieldd4;
    return true;
}

// FUNCTION: 0x0099bd01
void cGZWin::GetAreaAbsolute(uint32_t rect)
{
    *OB_PTR(Rect_adc8d8, rect) = *reinterpret_cast<Rect_adc8d8*>(field14);
}

// FUNCTION: 0x0099b980
bool cGZWin::AccelerateKeyboardMsg(uint32_t msg)
{
    if (field78 != 0) {
        return reinterpret_cast<KeyAccel_adc8d8*>(static_cast<uintptr_t>(field78))->Accelerate(msg);
    }
    return false;
}

// FUNCTION: 0x0099bdbb
uint32_t cGZWin::Slot67_adc8d8(uint32_t mask)
{
    return (mnFlags & mask) != 0;
}

// FUNCTION: 0x0099bf01
bool cGZWin::SetKeyboard(uint32_t keyboard)
{
    field8 = keyboard;
    return keyboard != 0;
}

// FUNCTION: 0x0099ca0b
bool cGZWin::SetWindowManager(uint32_t winMgr)
{
    field4 = winMgr;
    return winMgr != 0;
}

// FUNCTION: 0x0099bd13
void cGZWin::Slot118_adc8d8(uint32_t size)
{
    const int32_t* p = OB_PTR(int32_t, size);
    SetSize_2(p[0], p[1]);
}

// FUNCTION: 0x0099b856
bool cGZWin::PullToFront()
{
    if (field48) {
        return reinterpret_cast<cGZWin*>(static_cast<uintptr_t>(field48))->ChildToFront_2(this);
    }
    return false;
}

// FUNCTION: 0x0099b86b
bool cGZWin::SendToBack()
{
    if (field48) {
        return reinterpret_cast<cGZWin*>(static_cast<uintptr_t>(field48))->ChildToBack(this);
    }
    return false;
}

// FUNCTION: 0x0099bcec
void cGZWin::GetArea(uint32_t rect)
{
    *OB_PTR(Rect_adc8d8, rect) = *reinterpret_cast<Rect_adc8d8*>(&unknowna0[8]);
}

// FUNCTION: 0x0099bd5e
void cGZWin::WindowToScreenCoordinates(void* x, void* y)
{
    *static_cast<int32_t*>(x) += reinterpret_cast<int32_t*>(field14)[0];
    *static_cast<int32_t*>(y) += reinterpret_cast<int32_t*>(field14)[1];
}

// FUNCTION: 0x0099c011
bool cGZWin::PostMsg_2(uint32_t win, uint32_t msg)
{
    reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->PostMessageToTarget2(win, msg);
    return true;
}

// FUNCTION: 0x0099beb6
uint32_t cGZWin::MakeKeyEquivalent(uint32_t key, uint32_t modifiers)
{
    return (modifiers << 16) | (key & 0xffff);
}

// FUNCTION: 0x0099c25f
void cGZWin::SetFadeEffectPeriod(uint32_t fadeIn, uint32_t fadeOut)
{
    mnFadeInTime = fadeIn;
    mnFadeOutTime = fadeOut;
}

// FUNCTION: 0x0099c276
void cGZWin::GetFadeEffectPeriod(uint32_t fadeIn, uint32_t fadeOut)
{
    *OB_PTR(int32_t, fadeIn) = mnFadeInTime;
    *OB_PTR(int32_t, fadeOut) = mnFadeOutTime;
}

// FUNCTION: 0x0099b993
void cGZWin::SetCursor(uint32_t cursor, uint32_t update)
{
    mpCursor = cursor;
    if (static_cast<uint8_t>(update) != 0) {
        UpdateCursor();
    }
}

// FUNCTION: 0x009d7d97
void cGZWin::SetArea(uint32_t area)
{
    const int32_t* r = OB_PTR(int32_t, area);
    Slot07_add348(r[0], r[1], r[2], r[3]);
}

// FUNCTION: 0x0099b83b
void cGZWin::ChildToFront(uint32_t id)
{
    ChildToFront_2(GetChildWindowFromID(id));
}

// FUNCTION: 0x0099b7a3
unsigned int cGZWin::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete this;
    return 0;
}

// The child windows' interface (slot 0 is QueryInterface, as in every component).
struct Unknown_adc8d8 {
    virtual bool QueryInterface(uint32_t iid, uint32_t out);
};

// The 16-byte rectangle at +0xa8, its function out of line.
struct AreaRect_adc8d8 {
    // STUB: 0x00664c60
    uint8_t Contains(int32_t x, int32_t y);
};

// FUNCTION: 0x0099b929
bool cGZWin::IsWinInParentChain(uint32_t win)
{
    uint32_t parent = GetParentWin();
    while (parent != 0) {
        if (parent == win) {
            return true;
        }
        parent = reinterpret_cast<cGZWin*>(static_cast<uintptr_t>(parent))->GetParentWin();
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099b774 score 19
bool cGZWin::QueryInterface(unsigned int riid, void** ppv)
{
    if (riid == 1 || riid == 0x22ba0121 || riid == 0xe98b2f57) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x0099bfac
void cGZWin::SetFillColor(uint32_t r, uint32_t g, uint32_t b)
{
    fieldd4 = ((static_cast<uint8_t>(r) << 8 | static_cast<uint8_t>(g)) << 8) | static_cast<uint8_t>(b);
}

// FUNCTION: 0x0099bfc9
void cGZWin::GetFillColor_3(uint32_t r, uint32_t g, uint32_t b)
{
    const uint8_t* c = reinterpret_cast<const uint8_t*>(&fieldd4);
    *OB_PTR(uint8_t, r) = c[2];
    *OB_PTR(uint8_t, g) = c[1];
    *OB_PTR(uint8_t, b) = c[0];
}

// FUNCTION: 0x0099be94
uint32_t cGZWin::CheckKeyEquivalent(uint32_t key, uint32_t modifiers)
{
    return MakeKeyEquivalent(key, modifiers) == field9c;
}

// FUNCTION: 0x0099c960
bool cGZWin::IsPointInWindowParentCoordinates(uint32_t x, uint32_t y)
{
    return reinterpret_cast<AreaRect_adc8d8*>(&unknowna0[8])->Contains(x, y) != 0;
}

// FUNCTION: 0x0099cf49
bool cGZWin::GZOnSetFocus(uint32_t)
{
    if (!static_cast<uint8_t>(Slot67_adc8d8(1))) {
        SetFocusTo(OB_PTR(void, field4c));
    }
    return false;
}

// FUNCTION: 0x0099b8ab
bool cGZWin::GetChildAs(uint32_t id, uint32_t iid, uint32_t out)
{
    void* child = GetChildWindowFromID(id);
    if (child) {
        return static_cast<Unknown_adc8d8*>(child)->QueryInterface(iid, out);
    }
    return false;
}

// FUNCTION: 0x0099b8d0
bool cGZWin::GetChildAsRecursive(uint32_t id, uint32_t iid, uint32_t out)
{
    void* child = GetChildWindowFromIDRecursive(id);
    if (child) {
        return static_cast<Unknown_adc8d8*>(child)->QueryInterface(iid, out);
    }
    return false;
}

// FUNCTION: 0x0099bfec
bool cGZWin::SendMsg_2(uint32_t win, uint32_t msg)
{
    WinMgr_adc8d8* mgr = reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4));
    if (mgr->IsWindowValid(OB_PTR(void, win))) {
        return OB_PTR(cGZWin, win)->DoMessage(msg);
    }
    return false;
}

// FUNCTION: 0x0099bc68
void cGZWin::SetH(uint32_t size)
{
    int32_t left = *reinterpret_cast<int32_t*>(&unknowna0[8]);
    Slot07_add348(left, fieldac, size + left, fieldb4);
}

// FUNCTION: 0x0099bc8f
void cGZWin::SetSize(uint32_t size)
{
    int32_t top = fieldac;
    Slot07_add348(*reinterpret_cast<int32_t*>(&unknowna0[8]), top, fieldb0, size + top);
}

// FUNCTION: 0x0099bed1
void cGZWin::InvalidateSelfAndParents()
{
    InvalidateSelf();
    if (!static_cast<uint8_t>(Slot67_adc8d8(0x8000000))) {
        InvalidateAllParents();
    }
}

// FUNCTION: 0x0099bcb6
void cGZWin::SetSize_2(uint32_t width, uint32_t height)
{
    int32_t top = fieldac;
    int32_t left = *reinterpret_cast<int32_t*>(&unknowna0[8]);
    Slot07_add348(left, top, left + width, top + height);
}

// FUNCTION: 0x0099bd27
void cGZWin::GZWinOffset(uint32_t dx, uint32_t dy)
{
    Slot07_add348(*reinterpret_cast<int32_t*>(&unknowna0[8]) + dx, fieldac + dy, fieldb0 + dx, fieldb4 + dy);
}

// FUNCTION: 0x0099bd73
void cGZWin::ScreenToWindowCoordinates(void* x, void* y)
{
    int32_t offsetX = 0;
    int32_t offsetY = 0;
    WindowToScreenCoordinates(&offsetX, &offsetY);
    *static_cast<int32_t*>(x) -= offsetX;
    *static_cast<int32_t*>(y) -= offsetY;
}

// FUNCTION: 0x0099b955
void cGZWin::SetKeyboardAccelerator(uint32_t accelerator)
{
    uint32_t old = field78;
    if (accelerator != old) {
        if (old != 0) {
            reinterpret_cast<KeyAccel_adc8d8*>(static_cast<uintptr_t>(old))->Release();
        }
        field78 = accelerator;
        if (accelerator != 0) {
            reinterpret_cast<KeyAccel_adc8d8*>(static_cast<uintptr_t>(accelerator))->AddRef();
        }
    }
}

// FUNCTION: 0x0099badc
uint32_t cGZWin::MakeFillColor(uint32_t r, uint32_t g, uint32_t b)
{
    if (field68 != 0) {
        return reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field68))->ConvertRGBValueToNative(r, g, b);
    }
    Gfx_adc8d8* gfx = Fn00913c1a();
    if (gfx) {
        return gfx->RGBToNative(r, g, b);
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099bb08 score 22
uint32_t cGZWin::ConvertPackedRGBToNative(uint32_t packed)
{
    uint8_t r = static_cast<uint8_t>(packed >> 16);
    uint8_t g = static_cast<uint8_t>(packed >> 8);
    if (field68 != 0) {
        return reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field68))->ConvertRGBValueToNative(r, g, packed);
    }
    Gfx_adc8d8* gfx = Fn00913c1a();
    if (gfx) {
        return gfx->RGBToNative(r, g, packed);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099bb5a score 9
uint32_t cGZWin::ConvertNativeToPackedRGB(uint32_t color)
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    if (field68 != 0) {
        reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field68))->ConvertNativeValueToRGB(color, &r, &g, &b);
    } else {
        Gfx_adc8d8* gfx = Fn00913c1a();
        if (gfx) {
            gfx->NativeToRGB(color, &r, &g, &b);
        }
    }
    return (r << 16) | (g << 8) | b | 0xff000000;
}
#endif

// FUNCTION: 0x0099bf7a
void cGZWin::GetFillColor_2()
{
    GfxBytes_adc8d8* gfx = reinterpret_cast<GfxBytes_adc8d8*>(Fn00913c1a());
    const uint8_t* c = reinterpret_cast<const uint8_t*>(&fieldd4);
    gfx->RGBToNative(c[2], c[1], c[0]);
}

// FUNCTION: 0x0099bf1f
void cGZWin::Slot08_ae1a28(uint32_t color)
{
    int32_t r;
    int32_t g;
    int32_t b;
    Fn00913c1a()->NativeToRGB(color, &r, &g, &b);
    SetFillColor(r, g, b);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099bbbe score 38
void cGZWin::is_point_transparent(uint32_t x, uint32_t y)
{
    if (field64 != 0) {
        Buf_adc8d8* buf = reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64));
        if (buf->GetTransparency() && buf->Lock(0x800)) {
            buf->IsPixelTransparent(x, y);
            buf->Unlock(0x800);
        }
    }
}
#endif

// A variant the parameter table holds, seen through the slots this class calls.
struct Variant_adc8d8 {
    virtual void P00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
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
    virtual void SetByte(uint8_t value);
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
    virtual void SetClock(int32_t value);
    virtual void P27();
    virtual void P28();
    virtual void SetLong(int32_t value);
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
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
    virtual void P48();
    virtual void P49();
    virtual void P50();
    virtual void P51();
    virtual void P52();
    virtual void P53();
    virtual void P54();
    virtual void P55();
    virtual void P56();
    virtual void P57();
    virtual void P58();
    virtual void P59();
    virtual void P60();
    virtual void P61();
    virtual void P62();
    virtual void P63();
    virtual void P64();
    virtual uint8_t* GetBytePtr();
    virtual void P66();
    virtual void P67();
    virtual void P68();
    virtual void P69();
    virtual void P70();
    virtual void P71();
    virtual void P72();
    virtual int32_t* GetClockPtr();
    virtual void P74();
    virtual uint8_t* GetValuePtr();
};

// The colour manager the framework's second global accessor returns.
struct Wcm_adc8d8 {
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
    virtual uint32_t GetColor(uint32_t id);
};

// STUB: 0x00913c72
Wcm_adc8d8* Fn00913c72();

// A node of the parameter table (a red-black tree keyed by a word).
struct TreeNode_adc8d8 {
    uint32_t color;
    TreeNode_adc8d8* parent;
    TreeNode_adc8d8* left;
    TreeNode_adc8d8* right;
    uint32_t key;
    Variant_adc8d8* value;
};

// STUB: 0x0040d4c0
TreeNode_adc8d8* Next_adc8d8(TreeNode_adc8d8* node);

// STUB: 0x0090cf63
void StlDelete_adc8d8(void* p);

// A position in the parameter table (a class with constructors: the original passes and returns it as an object).
struct TreeIter_adc8d8 {
    TreeNode_adc8d8* node;
    TreeIter_adc8d8()
        : node(0)
    {
    }
    TreeIter_adc8d8(TreeNode_adc8d8* n)
        : node(n)
    {
    }
};

struct TreeInsertResult_adc8d8 {
    TreeIter_adc8d8 first;
    bool second;
    TreeInsertResult_adc8d8()
        : second(false)
    {
    }
};

// The record a node holds after its colour and links: the key and the variant.
struct TreePair_adc8d8 {
    uint32_t key;
    Variant_adc8d8* value;
};

// STUB: 0x0040d500
TreeNode_adc8d8* Prev_adc8d8(TreeNode_adc8d8* node);

// The parameter table at +0x7c: the header node, then the node count.
struct Tree_adc8d8 {
    TreeNode_adc8d8* header;
    uint32_t count;
    // STUB: 0x0098129c
    TreeNode_adc8d8* Find(const uint32_t* key);
    // STUB: 0x008920a7
    TreeIter_adc8d8 Insert(TreeNode_adc8d8* x, TreeNode_adc8d8* y, const TreePair_adc8d8* v, TreeNode_adc8d8* w);
    // STUB: 0x0094950a
    TreeInsertResult_adc8d8 InsertUnique(const TreePair_adc8d8* v);
    // STUB: 0x00927cf8
    void Erase(TreeIter_adc8d8 position);
    TreeIter_adc8d8 Fn00981404(TreeIter_adc8d8 hint, const TreePair_adc8d8* v);
    TreeIter_adc8d8 Fn009dc50a(TreeIter_adc8d8 hint, const TreePair_adc8d8* v);
    void Fn0099cca3(TreeNode_adc8d8* node);
    void Fn0099d229();
};

// The child list: the circular list of children (a sentinel node, next / previous / window), then the number of
// readers walking it at the moment.
struct ListNode_adc8d8 {
    ListNode_adc8d8* next;
    ListNode_adc8d8* prev;
    cGZWin* data;
};

// A position in the list (a class with constructors, so the original returns it through a hidden pointer).
struct ListIter_adc8d8 {
    ListNode_adc8d8* node;
    ListIter_adc8d8()
        : node(0)
    {
    }
    ListIter_adc8d8(ListNode_adc8d8* n)
        : node(n)
    {
    }
};

// An empty tag the search algorithm takes.
struct Tag_adc8d8 {
};

struct ChildList_adc8d8 {
    ListNode_adc8d8* head;
    int32_t readers;
    // STUB: 0x0072ba10
    ListIter_adc8d8 Insert(ListIter_adc8d8 pos, void* const* value);
    // STUB: 0x0099d8f3
    void Fn0099d8f3(const ChildList_adc8d8* other);
    // The copy: the list's copy, no readers.
    ChildList_adc8d8* Fn0099d922(const ChildList_adc8d8* other);
    // STUB: 0x00943995
    void Remove(void* const* value);
    // STUB: 0x004b0be0
    void PushBack(void* const* value);
    // STUB: 0x0099d291
    void PushFront(void* const* value);
    // STUB: 0x0049eaa0
    ListIter_adc8d8 Erase(ListIter_adc8d8 pos);
    // STUB: 0x0099cc80
    void Splice(ListIter_adc8d8 pos, ChildList_adc8d8& other, ListIter_adc8d8 item);
};

// STUB: 0x009d07a0
ListIter_adc8d8 Fn009d07a0(ListIter_adc8d8 first, ListIter_adc8d8 last, void* const& value);

// The same search over the filter list (the one shared function in the original).
// STUB: 0x009d07a0
ListIter_adc8d8 Fn009d07a0Filter(ListIter_adc8d8 first, ListIter_adc8d8 last, const struct AutoRef_adc8d8& value);

// The window's child list (the pointer at +0x44).
inline ChildList_adc8d8*& ChildListOf_adc8d8(cGZWin* win)
{
    return *reinterpret_cast<ChildList_adc8d8**>(&win->field24[0x20]);
}

// The filter objects of the message filter lists.
struct Filter_adc8d8 {
    virtual void P00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

struct AutoRef_adc8d8 {
    Filter_adc8d8* mp;
    // STUB: 0x004f20c0
    AutoRef_adc8d8(Filter_adc8d8* filter);
    // STUB: 0x00966956
    AutoRef_adc8d8(const AutoRef_adc8d8& other);
    ~AutoRef_adc8d8()
    {
        if (mp) {
            mp->Release();
        }
    }
};

struct FilterList_adc8d8 {
    ListNode_adc8d8* head;
    // STUB: 0x009677e6
    void Clear();
    // STUB: 0x0090dbcd
    void PushBack(const AutoRef_adc8d8* value);
    // STUB: 0x00968c53
    ListIter_adc8d8 Erase(ListIter_adc8d8 pos);
};

// The fade interface a buffer is asked for (slot 3 sets the fade colour and level).
struct FadeBuf_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual uint32_t Release();
    virtual void Fade(uint32_t r, uint32_t g, uint32_t b, uint8_t level);
};

// The record every parameter is stored as (20 bytes).
struct cRZVariant_adc8d8 : Variant_adc8d8 {
    uint32_t pad[4];
    // STUB: 0x009166d4
    cRZVariant_adc8d8();
};

// The object at the service accessor 0x008793ec, asked for a component by two ids.
struct ServiceMgr_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual bool Query(uint32_t id1, uint32_t id2, void* out);
};

// STUB: 0x008793ec
ServiceMgr_adc8d8* Fn008793ec();

// The draw system the service accessor 0x00449720 finds (slot 5 makes a buffer).
struct DrawSys_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual bool CreateBuffer(void* out, uint32_t width, uint32_t height, uint32_t kind);
};

// The graphics system the service accessor 0x00449560 finds (slot 8 gives the default buffer).
struct GfxSys_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void P05();
    virtual void P06();
    virtual void P07();
    virtual uint32_t GetDefaultBuffer();
};

struct GfxHolder_adc8d8 {
    GfxSys_adc8d8* mp;
    // STUB: 0x00449560
    void Init();
    // STUB: 0x004495c0
    void Done();
};

// The interface a buffer is asked for by 0xab300b2b (slot 4 gives the drawing context).
struct Context_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual uint32_t Release();
    virtual void P03();
    virtual uint32_t GetContext();
};

// The holder a component reference lives in.
struct Holder_adc8d8 {
    DrawSys_adc8d8* mp;
    Holder_adc8d8* Fn00449720();
    // STUB: 0x004495c0
    void Done();
};

// A window the fade window takes the buffer of (this object is a cGZWin: only its address is used).
struct FadeTmpWin_adc8d8 {
    FadeTmpWin_adc8d8* Fn0099ea30();
    bool StealBuffer(void* win);
};

// The canvas the drawing interface of a buffer hands out.
struct Canvas_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual uint32_t Release();
    virtual void Enter();
    virtual void Begin();
    virtual void P05();
    virtual void SetClip(void* rect);
    virtual void P07();
    virtual void SetOrigin(void* point);
    virtual void Leave();
    virtual void Reset();
    virtual void End();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void SetColor(uint32_t color);
    virtual void SetFlagA(uint8_t on);
    virtual void SetFlagB(uint32_t on);
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
    virtual void P37();
    virtual void Draw(uint32_t buffer, void* clip, void* rect);
    virtual void P39();
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
};

struct DrawIface_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual Canvas_adc8d8* GetCanvas();
    virtual void Release2();
};

// The fade interface of a buffer, asked for its colour (slot 4: four bytes out).
struct FadeColor_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual uint32_t Release();
    virtual void P03();
    virtual bool GetColor(uint8_t* a, uint8_t* b, uint8_t* c, uint8_t* d);
};

// The list of rectangles the composite plot has covered so far (begin, end, capacity).
struct RectVector_adc8d8 {
    RectBox_adc8d8* begin;
    RectBox_adc8d8* end;
    RectBox_adc8d8* capacity;
    // STUB: 0x004b2400
    void PushBack(const RectBox_adc8d8* value);
};

// STUB: 0x0099b9ac
bool Fn0099b9ac(cGZWin* win, uint32_t id, void* child, void* context);

// A four-word message (the component model's cGZMessage).
struct Message_adc8d8 {
    uint32_t v[4];
};

// FUNCTION: 0x0099b8f5
bool cGZWin::WindowToWindowCoordinates(uint32_t win, uint32_t x, uint32_t y)
{
    if (win != 0) {
        WindowToScreenCoordinates(OB_PTR(void, x), OB_PTR(void, y));
        OB_PTR(cGZWin, win)->ScreenToWindowCoordinates(OB_PTR(void, x), OB_PTR(void, y));
        return true;
    }
    return false;
}

// FUNCTION: 0x0099b880
bool cGZWin::MoveRelativeTo(void* win, uint32_t flag)
{
    if (GetParentWin() != 0) {
        return OB_PTR(cGZWin, GetParentWin())->ChildMoveRelative(this, win, flag);
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099c3df score 26
uint32_t cGZWin::FitRectToWindow(uint32_t rect, uint32_t margin)
{
    RectBox_adc8d8* area = reinterpret_cast<RectBox_adc8d8*>(&unknowna0[8]);
    int32_t width = area->Width();
    int32_t height = area->Height();
    RectBox_adc8d8* r = OB_PTR(RectBox_adc8d8, rect);
    int32_t m = margin;
    int32_t right;
    int32_t bottom;
    if (r->left < 0) {
        right = r->right;
        r->left = m;
        r->right = right;
    }
    if (r->top < 0) {
        bottom = r->bottom;
        r->top = m;
        r->bottom = bottom;
    }
    right = r->right;
    if (right > width) {
        r->left += width - right - m;
        r->right = width - m;
    }
    bottom = r->bottom;
    if (bottom > height) {
        r->top += height - bottom - m;
        r->bottom = height - m;
    }
    if (r->Width() + m <= width) {
        if (r->Height() + m <= height) {
            return true;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x0099c8c5
void cGZWin::GZWinMoveTo(uint32_t x, uint32_t y)
{
    RectBox_adc8d8* area = reinterpret_cast<RectBox_adc8d8*>(&unknowna0[8]);
    Slot07_add348(x, y, x + area->Width(), y + area->Height());
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099c8f5 score 27
bool cGZWin::IsPointInWindowWindowCoordinates(uint32_t x, uint32_t y)
{
    RectBox_adc8d8* area = reinterpret_cast<RectBox_adc8d8*>(&unknowna0[8]);
    bool inside = static_cast<int32_t>(y) >= 0 && static_cast<int32_t>(x) >= 0 &&
                  static_cast<int32_t>(y) < area->Height() && static_cast<int32_t>(x) < area->Width();
    if (static_cast<uint8_t>(Slot67_adc8d8(0x80000)) && inside) {
        inside = !reinterpret_cast<Self_adc8d8*>(this)->is_point_transparent(x, y);
    }
    return inside;
}
#endif

// FUNCTION: 0x0099c97c
bool cGZWin::IsPointInWindowScreenCoordinates(uint32_t x, uint32_t y)
{
    bool inside = reinterpret_cast<AreaRect_adc8d8*>(field14)->Contains(x, y) != 0;
    if (static_cast<uint8_t>(Slot67_adc8d8(0x80000)) && inside) {
        ScreenToWindowCoordinates(&x, &y);
        inside = !reinterpret_cast<Self_adc8d8*>(this)->is_point_transparent(x, y);
    }
    return inside;
}

// FUNCTION: 0x0099c468
void cGZWin::UpdateCursor()
{
    if (mpCursor == 0) {
        mpCursor = reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->GetCursorManager()->CreateCursor(1);
    }
    if (mpCursor != 0) {
        reinterpret_cast<Cursor_adc8d8*>(static_cast<uintptr_t>(mpCursor))->Activate(1);
    }
}

// FUNCTION: 0x0099ca2f
void cGZWin::SendMsg(uint32_t win, uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Message_adc8d8 msg;
    msg.v[0] = a;
    msg.v[1] = b;
    msg.v[2] = c;
    msg.v[3] = d;
    reinterpret_cast<Self_adc8d8*>(this)->SendMsg_2(OB_PTR(void, win), &msg);
}

// FUNCTION: 0x0099ca60
void cGZWin::PostMsg(uint32_t win, uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Message_adc8d8 msg;
    msg.v[0] = a;
    msg.v[1] = b;
    msg.v[2] = c;
    msg.v[3] = d;
    reinterpret_cast<Self_adc8d8*>(this)->PostMsg_2(OB_PTR(void, win), &msg);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099c837 score 2
void cGZWin::Slot07_add348(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
    RectBox_adc8d8* area = reinterpret_cast<RectBox_adc8d8*>(&unknowna0[8]);
    int32_t width = x2 - x1;
    int32_t height = y2 - y1;
    bool changed = !(width == area->Width() && height == area->Height());
    area->left = x1;
    area->top = y1;
    area->right = x1 + width;
    area->bottom = y1 + height;
    if ((mnFlags & 0x10000) && changed) {
        PrivateBuffer(1);
    }
    CalcAbsoluteArea();
    SetAreaToDrawToRecursive();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099c303 score 49
void cGZWin::CenterWindowInRect_2(uint32_t rect)
{
    if (rect != 0) {
        const RectBox_adc8d8* r = OB_PTR(RectBox_adc8d8, rect);
        RectBox_adc8d8* area = reinterpret_cast<RectBox_adc8d8*>(&unknowna0[8]);
        int32_t x = r->left + ((r->right - r->left) - (area->right - area->left)) / 2;
        int32_t y = r->top + ((r->bottom - r->top) - (area->bottom - area->top)) / 2;
        Slot07_add348(x, y, (area->right - area->left) + x, y + (area->bottom - area->top));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099c373 score 51
void cGZWin::CenterWindowInRect(uint32_t rect)
{
    const RectBox_adc8d8* r = OB_PTR(RectBox_adc8d8, rect);
    RectBox_adc8d8* area = reinterpret_cast<RectBox_adc8d8*>(&unknowna0[8]);
    int32_t x = r->left + ((r->right - r->left) - (area->right - area->left)) / 2;
    int32_t y = r->top + ((r->bottom - r->top) - (area->bottom - area->top)) / 2;
    Slot07_add348(x, y, (area->right - area->left) + x, y + (area->bottom - area->top));
}
#endif

// FUNCTION: 0x0099c1e1
uint32_t RectBox_adc8d8::Fn0099c1e1(const RectBox_adc8d8* other)
{
    if (right > other->left && left < other->right && bottom > other->top && top < other->bottom) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x0099cca3
void Tree_adc8d8::Fn0099cca3(TreeNode_adc8d8* node)
{
    while (node != 0) {
        Fn0099cca3(node->right);
        TreeNode_adc8d8* left = node->left;
        StlDelete_adc8d8(node);
        node = left;
    }
}

// FUNCTION: 0x0099d229
void Tree_adc8d8::Fn0099d229()
{
    if (count != 0) {
        Fn0099cca3(header->parent);
        header->left = header;
        header->parent = 0;
        header->right = header;
        count = 0;
    }
}

// FUNCTION: 0x0099b7f2
bool cGZWin::SetParentWin(uint32_t parent)
{
    uint32_t current = field48;
    if (current != parent) {
        if (current != 0 && parent != 0) {
            if (!OB_PTR(cGZWin, current)->Slot15_adc8d8(this)) {
                return false;
            }
            if (field4c == current) {
                field4c = 0;
            }
        }
        if (field4c == 0) {
            field4c = parent;
        }
        field48 = parent;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099ba3e score 6
bool cGZWin::fill_private_buffer_with_transparent_color()
{
    if (field64 == 0) {
        return false;
    }
    if (reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->Lock(0x8001)) {
        uint32_t color;
        if (reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->GetTransparentColor(&color)) {
            reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->Fill_3(color, field24, 0);
        }
        reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->Unlock(0x8001);
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099ba92 score 12
bool cGZWin::set_private_buffer_transparency(bool enable)
{
    if (field64 != 0) {
        if (enable) {
            Wcm_adc8d8* wcm = Fn00913c72();
            if (wcm == 0) {
                return false;
            }
            reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->SetTransparency(wcm->GetColor(0x8963f6c));
        } else {
            reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->RemoveTransparency();
        }
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x0099c20d
bool cGZWin::fade_in_progress()
{
    bool inProgress = false;
    uint32_t flags = mnFlags;
    if ((flags & 0x20) && (flags & 0x10000)) {
        Variant_adc8d8* variant = 0;
        uint8_t value = 0;
        if (GetParam(0xe6e998fd, &variant)) {
            value = *variant->GetValuePtr();
            variant->Release();
        }
        inProgress = value != 0;
    }
    return inProgress;
}

// FUNCTION: 0x0099d1aa
void cGZWin::ShowWindow()
{
    if (!static_cast<uint8_t>(Slot67_adc8d8(1))) {
        Slot68_adc8d8(1, 1);
        if (static_cast<uint8_t>(Slot67_adc8d8(0x20))) {
            set_fade_state(0, mnFadeInTime);
        }
    }
}

// FUNCTION: 0x0099d1ea
void cGZWin::HideWindow()
{
    if (static_cast<uint8_t>(Slot67_adc8d8(1))) {
        Slot68_adc8d8(1, 0);
        if (static_cast<uint8_t>(Slot67_adc8d8(0x20))) {
            set_fade_state(0xff, 0);
        }
    }
}

// FUNCTION: 0x0099c2c3
bool cGZWin::Slot03_ae1d24()
{
    if (!get_init_flag()) {
        set_init_flag(true);
        if ((mnFlags & 0x10000) && (mnFlags & 1)) {
            PrivateBuffer(1);
        }
        SetBufferToDrawToRecursive();
    }
    return true;
}

// FUNCTION: 0x0099d388
bool cGZWin::GetParam(uint32_t id, void* out)
{
    Tree_adc8d8* tree = reinterpret_cast<Tree_adc8d8*>(&unknown7c[0]);
    TreeNode_adc8d8* node = tree->Find(&id);
    if (node == tree->header) {
        return false;
    }
    Variant_adc8d8* variant = node->value;
    *static_cast<Variant_adc8d8**>(out) = variant;
    variant->AddRef();
    return true;
}

// FUNCTION: 0x0099d252
bool cGZWin::EnumParams(void* callback, void* context)
{
    typedef bool (*EnumFn_adc8d8)(cGZWin* win, uint32_t key, Variant_adc8d8* value, void* context);
    Tree_adc8d8* tree = reinterpret_cast<Tree_adc8d8*>(&unknown7c[0]);
    for (TreeNode_adc8d8* node = tree->header->left; node != tree->header; node = Next_adc8d8(node)) {
        uint32_t key = node->key;
        Variant_adc8d8* value = node->value;
        if (!reinterpret_cast<EnumFn_adc8d8>(callback)(this, key, value, context)) {
            return false;
        }
    }
    return true;
}

// The message fields the dispatcher reads at their byte offsets (words, signed or unsigned halves).
inline int32_t MsgS16_adc8d8(const Message_adc8d8* m, int offset)
{
    return *reinterpret_cast<const int16_t*>(reinterpret_cast<const uint8_t*>(m) + offset);
}

inline uint32_t MsgU16_adc8d8(const Message_adc8d8* m, int offset)
{
    return *reinterpret_cast<const uint16_t*>(reinterpret_cast<const uint8_t*>(m) + offset);
}

// A message filter, seen through the one slot the dispatcher calls (slot 3).
struct MsgFilter_adc8d8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual bool Process(cGZWin* win, void* msg);
};

// FUNCTION: 0x009cc8e2
ListIter_adc8d8 Fn009cc8e2(ListIter_adc8d8 first, ListIter_adc8d8 last, void* const& value, const Tag_adc8d8&)
{
    while (first.node != last.node && first.node->data != value) {
        first.node = first.node->next;
    }
    return first;
}

// FUNCTION: 0x0099ccd0
ListIter_adc8d8 Fn0099ccd0(ListIter_adc8d8 first, ListIter_adc8d8 last, void* const& value)
{
    return Fn009cc8e2(first, last, value, Tag_adc8d8());
}

// FUNCTION: 0x0099d922
ChildList_adc8d8* ChildList_adc8d8::Fn0099d922(const ChildList_adc8d8* other)
{
    Fn0099d8f3(other);
    readers = 0;
    return this;
}

// FUNCTION: 0x0099d57e
void cGZWin::SetBufferToDrawToRecursive()
{
    SetBufferToDrawTo();
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        node->data->SetBufferToDrawToRecursive();
    }
    unlock_child_list_read(list);
}

// FUNCTION: 0x0099d5b7
void cGZWin::SetAreaToDrawToRecursive()
{
    SetAreaToDrawTo();
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        node->data->SetAreaToDrawToRecursive();
    }
    unlock_child_list_read(list);
}

// FUNCTION: 0x0099d5f0
void* cGZWin::IsChildKeyEquivalent(uint32_t key, uint32_t modifiers)
{
    cGZWin* found = 0;
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        cGZWin* child = node->data;
        if (static_cast<uint8_t>(child->CheckKeyEquivalent(key, modifiers))) {
            found = child;
            break;
        }
    }
    unlock_child_list_read(list);
    return found;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099d645 score 22
bool cGZWin::child_private_buffers(bool flag)
{
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    bool failed = false;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        cGZWin* child = node->data;
        if (!static_cast<uint8_t>(child->Slot67_adc8d8(0x10000))) {
            child->child_private_buffers(flag);
        } else if (flag) {
            if (reinterpret_cast<Self_adc8d8*>(child)->IsVisible()) {
                failed |= !child->PrivateBuffer(1);
            } else {
                child->child_private_buffers(false);
            }
        } else {
            failed |= !child->PrivateBuffer(0);
        }
        if (flag) {
            child->GZWinMoveTo(child->GetL(), child->GetT());
        }
    }
    unlock_child_list_read(list);
    return !failed;
}
#endif

// FUNCTION: 0x0099ddb3
uint32_t cGZWin::GetChildCount()
{
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    list->readers++;
    ListNode_adc8d8* head = list->head;
    uint32_t count = 0;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        count++;
    }
    unlock_child_list_read(list);
    return count;
}

// FUNCTION: 0x0099de74
void* cGZWin::GetChildWindowFromID(uint32_t id)
{
    cGZWin* found = 0;
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        cGZWin* child = node->data;
        if (child->Slot48_adda20() == id) {
            found = child;
            break;
        }
    }
    unlock_child_list_read(list);
    return found;
}

// FUNCTION: 0x0099dec4
void* cGZWin::GetChildWindowFromIDRecursive(uint32_t id)
{
    void* found = 0;
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        found = node->data->GetChildWindowFromIDRecursive(id);
        if (found) {
            break;
        }
    }
    unlock_child_list_read(list);
    if (found == 0) {
        if (Slot48_adda20() == id) {
            found = this;
        }
    }
    return found;
}

// FUNCTION: 0x0099de2a
bool cGZWin::ChildExists(uint32_t id)
{
    bool found = false;
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        if (node->data->Slot48_adda20() == id) {
            found = true;
            break;
        }
    }
    unlock_child_list_read(list);
    return found;
}

// FUNCTION: 0x0099e03e
bool cGZWin::IsWinInChildChain(uint32_t win)
{
    bool found = false;
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        cGZWin* child = node->data;
        if (child == OB_PTR(cGZWin, win)) {
            found = true;
            break;
        }
        found = child->IsWinInChildChain(win);
        if (found) {
            break;
        }
    }
    unlock_child_list_read(list);
    return found;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099e08f score 20
void* cGZWin::lock_child_list_write()
{
    ChildList_adc8d8* copy = 0;
    if (ChildListOf_adc8d8(this)->readers != 0) {
        ChildList_adc8d8* memory = static_cast<ChildList_adc8d8*>(operator new(sizeof(ChildList_adc8d8)));
        if (memory) {
            copy = memory->Fn0099d922(ChildListOf_adc8d8(this));
        }
        ListNode_adc8d8* head = copy->head;
        for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
            reinterpret_cast<Filter_adc8d8*>(node->data)->AddRef();
        }
        ChildListOf_adc8d8(this) = copy;
    }
    return ChildListOf_adc8d8(this);
}
#endif

// FUNCTION: 0x0099dd6f
bool cGZWin::ChildDeleteAll()
{
    bool failed = false;
    for (;;) {
        ChildList_adc8d8* list = ChildListOf_adc8d8(this);
        ListNode_adc8d8* head = list->head;
        cGZWin* first = 0;
        list->readers++;
        ListNode_adc8d8* node = head->next;
        if (node != head) {
            first = node->data;
        }
        unlock_child_list_read(list);
        if (first == 0) {
            break;
        }
        failed |= !reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->DestroyWindow(first);
    }
    return !failed;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099ddd5 score 42
bool cGZWin::ChildExists_2(void* win)
{
    if (reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->IsWindowValid(win)) {
        ChildList_adc8d8* list = ChildListOf_adc8d8(this);
        list->readers++;
        ListNode_adc8d8* head = list->head;
        bool found = Fn0099ccd0(head->next, head, win).node != head;
        unlock_child_list_read(list);
        return found;
    }
    return false;
}
#endif

// FUNCTION: 0x0099d832
bool cGZWin::AddMessageFilter(uint32_t filter)
{
    AutoRef_adc8d8 ref(OB_PTR(Filter_adc8d8, filter));
    reinterpret_cast<FilterList_adc8d8*>(&unknown7c[0x0c])->PushBack(&ref);
    return true;
}

// FUNCTION: 0x0099df28
void* cGZWin::GetChildWindowFromPoint(uint32_t x, uint32_t y)
{
    void* found = 0;
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    list->readers++;
    ListNode_adc8d8* head = list->head;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        cGZWin* child = node->data;
        if (static_cast<uint8_t>(child->Slot67_adc8d8(1))) {
            found = child->GetChildWindowFromPoint(x, y);
            if (found) {
                break;
            }
        }
    }
    unlock_child_list_read(list);
    if (found == 0) {
        if (IsPointInWindowScreenCoordinates(x, y)) {
            found = this;
        }
    }
    return found;
}

// FUNCTION: 0x0099dfa9
void* cGZWin::GetChildWindowFromCursorPoint(uint32_t x, uint32_t y)
{
    void* found = 0;
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    list->readers++;
    ListNode_adc8d8* head = list->head;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        cGZWin* child = node->data;
        if (static_cast<uint8_t>(child->Slot67_adc8d8(1)) && !static_cast<uint8_t>(child->Slot67_adc8d8(0x200000))) {
            found = child->GetChildWindowFromCursorPoint(x, y);
            if (found) {
                break;
            }
        }
    }
    unlock_child_list_read(list);
    if (found == 0) {
        if (IsPointInWindowScreenCoordinates(x, y)) {
            found = this;
        }
    }
    return found;
}

// FUNCTION: 0x0099dce4
void cGZWin::CalcAbsoluteArea()
{
    RectBox_adc8d8 area = *static_cast<RectBox_adc8d8*>(GetArea_2());
    for (uint32_t parent = GetParentWin(); parent != 0; parent = OB_PTR(cGZWin, parent)->GetParentWin()) {
        cGZWin* p = OB_PTR(cGZWin, parent);
        int32_t top = p->GetT();
        int32_t left = p->GetL();
        area.left += left;
        area.right += left;
        area.top += top;
        area.bottom += top;
    }
    *reinterpret_cast<RectBox_adc8d8*>(field14) = area;
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        node->data->CalcAbsoluteArea();
    }
    unlock_child_list_read(list);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099d865 score 25
bool cGZWin::RemoveMessageFilter(uint32_t filter)
{
    AutoRef_adc8d8 ref(OB_PTR(Filter_adc8d8, filter));
    FilterList_adc8d8* list = reinterpret_cast<FilterList_adc8d8*>(&unknown7c[0x0c]);
    ListIter_adc8d8 it = Fn009d07a0Filter(list->head->next, list->head, ref);
    if (it.node != list->head) {
        if (unknown7c[0x14] != 0) {
            reinterpret_cast<FilterList_adc8d8*>(&unknown7c[0x10])->PushBack(reinterpret_cast<const AutoRef_adc8d8*>(&it.node->data));
        } else {
            list->Erase(it);
        }
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099e2bd score 37
bool cGZWin::child_remove_absolute(void* win)
{
    bool valid = reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->IsWindowValid(win);
    ChildList_adc8d8* list = static_cast<ChildList_adc8d8*>(lock_child_list_write());
    ListIter_adc8d8 it = Fn009d07a0(list->head->next, list->head, win);
    if (it.node == list->head) {
        return false;
    }
    if (valid) {
        reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->CleanUpWindowReferences(win);
        static_cast<cGZWin*>(win)->SetParentWin(0);
        static_cast<cGZWin*>(win)->Release();
    }
    list->Erase(it);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099e344 score 11
bool cGZWin::ChildDeleteAbsolute(uint32_t win)
{
    bool pinned = false;
    if (reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->IsWindowValid(OB_PTR(void, win))) {
        OB_PTR(cGZWin, win)->AddRef();
        pinned = OB_PTR(cGZWin, win)->Slot04_ae1d24();
    }
    bool failed = !child_remove_absolute(OB_PTR(void, win));
    failed |= !pinned;
    reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->DestroyWindow(OB_PTR(void, win));
    OB_PTR(cGZWin, win)->Release();
    return !failed;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099e3a8 score 46
bool cGZWin::ChildToFront_2(void* win)
{
    if (reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->IsWindowValid(win)) {
        ChildList_adc8d8* list = ChildListOf_adc8d8(this);
        ListNode_adc8d8* head = list->head;
        list->readers++;
        ListIter_adc8d8 it = Fn0099ccd0(head->next, head, win);
        bool wasFirst = it.node == head->next;
        unlock_child_list_read(list);
        if (it.node == head) {
            return false;
        }
        if (GetParentWin() != 0) {
            OB_PTR(cGZWin, GetParentWin())->ChildToFront_2(this);
        }
        if (!static_cast<uint8_t>(static_cast<cGZWin*>(win)->Slot67_adc8d8(0x800))) {
            return false;
        }
        if (!wasFirst) {
            ChildList_adc8d8* writable = static_cast<ChildList_adc8d8*>(lock_child_list_write());
            writable->Remove(&win);
            writable->PushBack(&win);
        }
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099e457 score 10
bool cGZWin::ChildToBack(void* win)
{
    cGZWin* w = static_cast<cGZWin*>(win);
    if (!(reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->IsWindowValid(w) && ChildExists_2(w) &&
          static_cast<uint8_t>(w->Slot67_adc8d8(0x800)))) {
        return false;
    }
    ChildList_adc8d8* list = static_cast<ChildList_adc8d8*>(lock_child_list_write());
    list->Remove(&win);
    list->PushFront(&win);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099e4b7 score 38
bool cGZWin::ChildStepFront(uint32_t win)
{
    if (reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->IsWindowValid(OB_PTR(void, win))) {
        ChildList_adc8d8* list = static_cast<ChildList_adc8d8*>(lock_child_list_write());
        void* key = OB_PTR(void, win);
        bool done = false;
        ListIter_adc8d8 it = Fn009d07a0(list->head->next, list->head, key);
        if (it.node != list->head) {
            if (it.node != list->head->next) {
                list->Splice(it.node->prev, *list, it);
            }
            done = true;
        }
        return done;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099e525 score 42
bool cGZWin::ChildStepBack(uint32_t win)
{
    if (reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->IsWindowValid(OB_PTR(void, win))) {
        ChildList_adc8d8* list = static_cast<ChildList_adc8d8*>(lock_child_list_write());
        void* key = OB_PTR(void, win);
        bool done = false;
        ListIter_adc8d8 it = Fn009d07a0(list->head->next, list->head, key);
        if (it.node != list->head) {
            if (it.node->next != list->head) {
                list->Splice(it.node->next->next, *list, it);
            }
            done = true;
        }
        return done;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099e594 score 50
bool cGZWin::ChildMoveRelative(void* source, void* target, uint32_t after)
{
    if (ChildExists_2(source) && ChildExists_2(target)) {
        ChildList_adc8d8* list = static_cast<ChildList_adc8d8*>(lock_child_list_write());
        ListIter_adc8d8 from = Fn009d07a0(list->head->next, list->head, source);
        ListIter_adc8d8 to = Fn009d07a0(list->head->next, list->head, target);
        ListNode_adc8d8* pos = to.node;
        if (!static_cast<uint8_t>(after)) {
            pos = pos->next;
        }
        if (pos != from.node) {
            list->Splice(pos, *list, from);
        }
        return true;
    }
    return false;
}
#endif

// These two helpers were compiled for speed (the game folder), unlike the rest of this file.
#ifdef _MSC_VER
#pragma optimize("s", off)
#pragma optimize("t", on)
#endif
// FUNCTION: 0x00449720
Holder_adc8d8* Holder_adc8d8::Fn00449720()
{
    mp = 0;
    ServiceMgr_adc8d8* manager = Fn008793ec();
    if (manager) {
        manager->Query(0xeb2ea3cb, 0x4b2ea3b3, this);
    }
    return this;
}

// FUNCTION: 0x0082ae40
void RectBox_adc8d8::Fn0082ae40(const int32_t* point)
{
    int32_t dx = point[0] - left;
    int32_t dy = point[1] - top;
    left += dx;
    top += dy;
    right += dx;
    bottom += dy;
}
#ifdef _MSC_VER
#pragma optimize("", on)
#endif

// FUNCTION: 0x0099ba07
bool cGZWin::Plot()
{
    bool ok;
    if (PlotComposite() && PlotPresent()) {
        ok = true;
    } else {
        ok = false;
    }
    if (!mbDeferStrategy) {
        reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->ExecutePlotStrategy();
    }
    return ok;
}

// FUNCTION: 0x0099c7ba
bool cGZWin::recalc_blt_area()
{
    uint32_t parent = GetParentWin();
    RectBox_adc8d8* blt = reinterpret_cast<RectBox_adc8d8*>(&unknownb8[0]);
    reinterpret_cast<Self_adc8d8*>(this)->GetArea(blt);
    for (; parent != 0; parent = OB_PTR(cGZWin, parent)->GetParentWin()) {
        cGZWin* p = OB_PTR(cGZWin, parent);
        if (p->GetPrivateBuffer() != 0) {
            break;
        }
        int32_t top = p->GetT();
        int32_t left = p->GetL();
        blt->left += left;
        blt->right += left;
        blt->top += top;
        blt->bottom += top;
    }
    return true;
}

// FUNCTION: 0x0099d2fe
bool cGZWin::Slot04_ae1d24()
{
    if (get_init_flag()) {
        set_init_flag(false);
        if (field78 != 0) {
            reinterpret_cast<KeyAccel_adc8d8*>(static_cast<uintptr_t>(field78))->Release();
            field78 = 0;
        }
        reinterpret_cast<FilterList_adc8d8*>(&unknown7c[0x0c])->Clear();
        reinterpret_cast<FilterList_adc8d8*>(&unknown7c[0x10])->Clear();
        HideWindow();
        ChildDeleteAll();
        PrivateBuffer(0);
        Tree_adc8d8* tree = reinterpret_cast<Tree_adc8d8*>(&unknown7c[0]);
        for (TreeNode_adc8d8* node = tree->header->left; node != tree->header; node = Next_adc8d8(node)) {
            Variant_adc8d8* value = node->value;
            if (value != 0) {
                value->Release();
            }
        }
        tree->Fn0099d229();
    }
    return true;
}

// FUNCTION: 0x0099d708
bool cGZWin::EnumChildren(uint32_t iid, void* callback, void* context)
{
    typedef bool (*EnumChildFn_adc8d8)(cGZWin* win, uint32_t id, void* iface, void* context);
    if (callback == 0) {
        return false;
    }
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    ListNode_adc8d8* node = head->next;
    if (node == head) {
        unlock_child_list_read(list);
        return false;
    }
    int32_t failures = 0;
    do {
        cGZWin* child = node->data;
        if (iid == 0x22ba0121) {
            failures += !reinterpret_cast<EnumChildFn_adc8d8>(callback)(this, child->Slot48_adda20(), child, context);
        } else {
            void* iface;
            if (child->QueryInterface(iid, &iface)) {
                failures += !reinterpret_cast<EnumChildFn_adc8d8>(callback)(this, child->Slot48_adda20(), iface, context);
                child->Release();
            }
        }
        node = node->next;
    } while (node != head);
    unlock_child_list_read(list);
    return failures == 0;
}

// FUNCTION: 0x0099caad
void cGZWin::set_fade_state(uint8_t state, int32_t period)
{
    if ((mnFlags & 0x20) && (mnFlags & 0x10000)) {
        cRZVariant_adc8d8* variant = new cRZVariant_adc8d8;
        variant->SetByte(state);
        SetParam(0xe6e998fb, variant);
        clock_t now = clock();
        variant = new cRZVariant_adc8d8;
        variant->SetClock(now);
        SetParam(0xe6e998fc, variant);
        variant = new cRZVariant_adc8d8;
        variant->SetLong(period);
        SetParam(0xe6e998fd, variant);
        if (field64 != 0) {
            FadeBuf_adc8d8* fade = 0;
            if (reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->QueryInterface(0x86d72b57, reinterpret_cast<void**>(&fade))) {
                fade->Fade(0xff, 0xff, 0xff, state);
            }
            if (fade != 0) {
                fade->Release();
            }
        }
    }
}

// FUNCTION: 0x0099cbb0
bool FadeTmpWin_adc8d8::StealBuffer(void* win)
{
    cGZWin* self = reinterpret_cast<cGZWin*>(this);
    cGZWin* source = static_cast<cGZWin*>(win);
    if (source->GetParentWin() != 0) {
        OB_PTR(cGZWin, source->GetParentWin())->Slot14_adc8d8(self);
        reinterpret_cast<Self_adc8d8*>(self)->SetArea(source->GetArea_2());
        self->MoveRelativeTo(win, 0);
    } else {
        static_cast<cGZWin*>(self->Slot10_adc8d8())->Slot14_adc8d8(self);
        reinterpret_cast<Self_adc8d8*>(self)->SetArea(source->GetAreaAbsolute_2());
    }
    self->mnFlags = (self->mnFlags & 0xfffbffff) | 0x230021;
    self->field64 = source->GetPrivateBuffer();
    if (self->field64 != 0) {
        reinterpret_cast<KeyAccel_adc8d8*>(static_cast<uintptr_t>(self->field64))->AddRef();
    }
    self->SetBufferToDrawTo();
    int32_t fadeIn;
    int32_t fadeOut;
    reinterpret_cast<Self_adc8d8*>(source)->GetFadeEffectPeriod(&fadeIn, &fadeOut);
    self->set_fade_state(0xff, -fadeOut);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099ea30 score 5
FadeTmpWin_adc8d8* FadeTmpWin_adc8d8::Fn0099ea30()
{
    cGZWin* self = reinterpret_cast<cGZWin*>(this);
    self->Fn0099d938();
    cRZVariant_adc8d8* variant = new cRZVariant_adc8d8;
    self->cGZWin::SetParam(0xe6e998fe, variant);
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00981404 score 150
TreeIter_adc8d8 Tree_adc8d8::Fn00981404(TreeIter_adc8d8 hint, const TreePair_adc8d8* v)
{
    TreeNode_adc8d8* position = hint.node;
    if (position == header->left) {
        if (count <= 0) {
            return InsertUnique(v).first;
        }
        if (v->key < position->key) {
            return Insert(position, position, v, 0);
        }
        bool less = position->key < v->key;
        if (less == false) {
            return hint;
        }
        TreeNode_adc8d8* after = Next_adc8d8(position);
        if (after == header) {
            return Insert(0, position, v, position);
        }
        if (v->key < after->key) {
            if (position->right == 0) {
                return Insert(0, position, v, position);
            }
            return Insert(after, after, v, 0);
        }
        return InsertUnique(v).first;
    }
    if (position == header) {
        if (header->right->key < v->key) {
            return Insert(0, header->right, v, position);
        }
        return InsertUnique(v).first;
    }
    TreeNode_adc8d8* before = Prev_adc8d8(position);
    bool vLess = v->key < position->key;
    if (vLess && before->key < v->key) {
        if (before->right == 0) {
            return Insert(0, before, v, before);
        }
        return Insert(position, position, v, 0);
    }
    TreeNode_adc8d8* after = Next_adc8d8(position);
    bool posLess = !vLess;
    if (!vLess) {
        posLess = position->key < v->key;
    }
    if (!vLess && posLess && (after == header || v->key < after->key)) {
        if (position->right == 0) {
            return Insert(0, position, v, position);
        }
        return Insert(after, after, v, 0);
    }
    if (vLess == posLess) {
        return hint;
    }
    return InsertUnique(v).first;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dc50a score 5
TreeIter_adc8d8 Tree_adc8d8::Fn009dc50a(TreeIter_adc8d8 hint, const TreePair_adc8d8* v)
{
    return Fn00981404(TreeIter_adc8d8(hint.node), v);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099d7c8 score 23
bool cGZWin::SetParam(uint32_t id, void* variant)
{
    Tree_adc8d8* tree = reinterpret_cast<Tree_adc8d8*>(&unknown7c[0]);
    TreeNode_adc8d8* node = tree->Find(&id);
    if (node != tree->header) {
        Variant_adc8d8* old = node->value;
        if (old != 0) {
            old->Release();
        }
        tree->Erase(TreeIter_adc8d8(node));
    }
    Variant_adc8d8* entry = static_cast<Variant_adc8d8*>(variant);
    if (entry != 0) {
        entry->AddRef();
        TreePair_adc8d8 pair;
        pair.key = id;
        pair.value = entry;
        tree->Fn009dc50a(TreeIter_adc8d8(tree->header), &pair);
    }
    return true;
}
#endif

// STUB: 0x0099bc0e
bool Fn0099bc0e(void* a, void* b, void* context);

#ifdef OB_DRAFTS
// CLOSE: 0x0099c6f8 score 29
void cGZWin::SetBufferToDrawTo()
{
    field68 = GetPrivateBuffer();
    mbDeferStrategy = true;
    if (field68 == 0) {
        for (cGZWin* p = this; (p = OB_PTR(cGZWin, p->GetParentWin())) != 0;) {
            uint32_t buffer = p->GetPrivateBuffer();
            if (buffer != 0) {
                field68 = buffer;
                break;
            }
            if (static_cast<uint8_t>(Slot67_adc8d8(0x8000000))) {
                break;
            }
        }
        if (field68 == 0) {
            GfxHolder_adc8d8 graphics;
            graphics.Init();
            if (graphics.mp) {
                field68 = graphics.mp->GetDefaultBuffer();
                mbDeferStrategy = false;
            }
            graphics.Done();
        }
    }
    Context_adc8d8* context = 0;
    field6c = 0;
    if (field68 != 0) {
        if (reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field68))->QueryInterface(0xab300b2b, reinterpret_cast<void**>(&context))) {
            field6c = context->GetContext();
        }
        if (context != 0) {
            context->Release();
        }
    }
    SetAreaToDrawToRecursive();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099d0ed score 85
bool cGZWin::create_private_buffer(uint32_t width, uint32_t height)
{
    bool ok = false;
    if (static_cast<int32_t>(width) > 0 || static_cast<int32_t>(height) > 0) {
        Holder_adc8d8 draw;
        draw.Fn00449720();
        if (draw.mp != 0) {
            if (field64 != 0) {
                reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->Reset();
                reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->Release();
                field64 = 0;
            }
            if (draw.mp->CreateBuffer(&field64, width, height, 1)) {
                ok = true;
            }
        } else {
            bool ready = true;
            if (field64 == 0) {
                Gfx_adc8d8* gfx = Fn00913c1a();
                ready = false;
                if (gfx) {
                    gfx->CreateBuffer(&field64);
                    ready = field64 != 0;
                }
            } else {
                reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->Reset();
            }
            if (ready) {
                if (reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->Init(width, height, Fmt_adc8d8(1))) {
                    ok = true;
                } else {
                    reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->Release();
                    field64 = 0;
                }
            }
        }
        draw.Done();
        return ok;
    }
    if (field64 != 0) {
        reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->Release();
        field64 = 0;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099e0d6 score 113
bool cGZWin::SortChildren(void* callback, void* context, uint32_t includeLocked)
{
    typedef bool (*CompareFn_adc8d8)(void* a, void* b, void* context);
    CompareFn_adc8d8 compare = reinterpret_cast<CompareFn_adc8d8>(callback);
    if (compare == 0) {
        compare = Fn0099bc0e;
    }
    ChildList_adc8d8* list = static_cast<ChildList_adc8d8*>(lock_child_list_write());
    ListNode_adc8d8* head = list->head;
    if (head->next == head) {
        return false;
    }
    uint32_t count = 0;
    for (ListNode_adc8d8* p = head->next; p != head; p = p->next) {
        count++;
    }
    if (count < 2) {
        return false;
    }
    ListNode_adc8d8* sorted = list->head->next;
    for (;;) {
        ListNode_adc8d8* node = sorted->next;
        if (node == list->head) {
            return true;
        }
        cGZWin* window = node->data;
        if (!static_cast<uint8_t>(includeLocked) && static_cast<uint8_t>(window->Slot67_adc8d8(0x800))) {
            sorted = node;
            continue;
        }
        if (compare(window, sorted->data, context)) {
            list->Erase(ListIter_adc8d8(node));
            ListNode_adc8d8* position = list->head->next;
            while (position != list->head && !compare(window, position->data, context)) {
                position = position->next;
            }
            list->Insert(ListIter_adc8d8(position), reinterpret_cast<void* const*>(&window));
            sorted = list->head->next;
        } else {
            sorted = node;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099db6b score 57
uint32_t cGZWin::Slot68_adc8d8(uint32_t flag, uint32_t on)
{
    if (static_cast<uint8_t>(on)) {
        mnFlags |= flag;
    } else {
        mnFlags &= ~flag;
    }
    switch (flag) {
    case 1:
        if (static_cast<uint8_t>(Slot67_adc8d8(0x10000))) {
            PrivateBuffer(on);
        } else {
            child_private_buffers(on);
        }
        if (!static_cast<uint8_t>(on)) {
            if (reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->GZGetFocus() == this) {
                SetFocusTo(OB_PTR(void, field4c));
            }
        }
        if (field48 != 0) {
            OB_PTR(cGZWin, field48)->InvalidateSelfAndParents();
        }
        mnFlags &= 0xffbfffff;
        break;
    case 2:
        if (!static_cast<uint8_t>(on)) {
            if (GZAmCapturing()) {
                GZReleaseCapture();
            }
            if (reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->GZGetFocus() == this) {
                SetFocusTo(OB_PTR(void, field4c));
            }
        }
        break;
    case 0x20:
        if (static_cast<uint8_t>(on)) {
            set_fade_state(0, mnFadeInTime);
        } else {
            set_fade_state(0xff, 0);
        }
        break;
    case 0x10000:
        if (static_cast<uint8_t>(on) && reinterpret_cast<Self_adc8d8*>(this)->IsVisible()) {
            PrivateBuffer(1);
        } else {
            PrivateBuffer(0);
        }
        break;
    case 0x20000:
        if (static_cast<uint8_t>(Slot67_adc8d8(0x10000))) {
            set_private_buffer_transparency(static_cast<uint8_t>(on) != 0);
            InvalidateSelfAndParents();
        }
        break;
    case 0x8000000:
        SetBufferToDrawToRecursive();
        SetAreaToDrawToRecursive();
        break;
    }
    return mnFlags;
}
#endif

// FUNCTION: 0x0099d40b
bool cGZWin::ProcessCursorMessage(uint32_t msg)
{
    Message_adc8d8* message = OB_PTR(Message_adc8d8, msg);
    uint32_t type = message->v[0];
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    for (ListNode_adc8d8* node = head->next; node != head; node = node->next) {
        cGZWin* child = node->data;
        if (reinterpret_cast<Self_adc8d8*>(child)->IsVisible() && !static_cast<uint8_t>(child->Slot67_adc8d8(0x200000)) &&
            child->IsPointInWindowScreenCoordinates(message->v[1], message->v[2]) &&
            (type == 0xd || reinterpret_cast<Self_adc8d8*>(child)->IsEnabled())) {
            unlock_child_list_read(list);
            return child->ProcessCursorMessage(msg);
        }
    }
    unlock_child_list_read(list);
    if (!static_cast<uint8_t>(Slot67_adc8d8(0x200000)) && reinterpret_cast<Self_adc8d8*>(this)->IsVisible()) {
        if (reinterpret_cast<Self_adc8d8*>(this)->IsEnabled()) {
            if (type == 7 || type == 8 || type == 9) {
                PullToFront();
                GZSetCapture();
            }
            ScreenToWindowCoordinates(&message->v[1], &message->v[2]);
            if (type == 0xd) {
                UpdateCursor();
            }
        } else {
            if (type != 0xd) {
                return false;
            }
            ScreenToWindowCoordinates(&message->v[1], &message->v[2]);
        }
        reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4))->SetCurrentMouseWin(this);
        return DoMessage(msg);
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099ccf0 score 119
bool cGZWin::DoMessage(uint32_t msg)
{
    const Message_adc8d8* m = OB_PTR(Message_adc8d8, msg);
    FilterList_adc8d8* filters = reinterpret_cast<FilterList_adc8d8*>(&unknown7c[0x0c]);
    ListNode_adc8d8* node = filters->head->next;
    bool handled = false;
    uint8_t busy = unknown7c[0x14];
    unknown7c[0x14] = 1;
    while (node != filters->head) {
        handled |= reinterpret_cast<MsgFilter_adc8d8*>(node->data)->Process(this, OB_PTR(void, msg));
        node = node->next;
        if (handled) {
            break;
        }
    }
    unknown7c[0x14] = busy;
    if (handled) {
        return true;
    }
    switch (m->v[0]) {
    case 0xd:
        return GZOnMouseMove(MsgS16_adc8d8(m, 4), MsgS16_adc8d8(m, 8), MsgU16_adc8d8(m, 0xe));
    case 4:
        return GZOnCharacter(static_cast<uint8_t>(m->v[1]));
    case 5:
        if (field78 == 0) {
            return GZOnKeyDown(m->v[1], m->v[2]);
        }
        if (GZOnKeyDown(m->v[1], m->v[2])) {
            return true;
        }
        return AccelerateKeyboardMsg(msg);
    case 6:
        if (field78 == 0) {
            return GZOnKeyUp(m->v[1], m->v[2]);
        }
        if (GZOnKeyUp(m->v[1], m->v[2])) {
            return true;
        }
        return AccelerateKeyboardMsg(msg);
    case 7:
        return GZOnMouseDownL(MsgS16_adc8d8(m, 4), MsgS16_adc8d8(m, 8), MsgU16_adc8d8(m, 0xe));
    case 8:
        return GZOnMouseDownR(MsgS16_adc8d8(m, 4), MsgS16_adc8d8(m, 8), MsgU16_adc8d8(m, 0xe));
    case 0xa:
        return GZOnMouseUpL(MsgS16_adc8d8(m, 4), MsgS16_adc8d8(m, 8), MsgU16_adc8d8(m, 0xe));
    case 0xb:
        return GZOnMouseUpR(MsgS16_adc8d8(m, 4), MsgS16_adc8d8(m, 8), MsgU16_adc8d8(m, 0xe));
    case 0xe:
        return GZOnMouseWheel(m->v[1], m->v[2], MsgU16_adc8d8(m, 0xe), MsgS16_adc8d8(m, 0xc));
    case 3:
        return GZOnCommand(m->v[1], m->v[2]);
    case 1:
        return Slot16_adc8d8(m->v[1]);
    case 0x11:
        return GZOnSetFocus(m->v[1]);
    case 0x10:
        return GZOnKillFocus(m->v[1]);
    case 0x12:
        return GZOnCaptureChanged(m->v[1], m->v[2]);
    case 0x13:
        return GZOnMouseEnter(m->v[1]);
    case 0x14:
        return GZOnMouseExit(m->v[1]);
    }
    return false;
}
#endif

// The function-local flag "a draw system exists" and its initialisation guard.
// GLOBAL: 0x00bac05c
extern uint8_t gBac05c;
// GLOBAL: 0x00bac060
extern uint32_t gBac060;

#ifdef OB_DRAFTS
// CLOSE: 0x0099cf6a score 115
void cGZWin::SetAreaToDrawTo()
{
    RectBox_adc8d8* area = reinterpret_cast<RectBox_adc8d8*>(&unknowna0[8]);
    RectBox_adc8d8* clip = reinterpret_cast<RectBox_adc8d8*>(&field24[0]);
    RectBox_adc8d8* blt = reinterpret_cast<RectBox_adc8d8*>(&field24[0x10]);
    if (field64 != 0) {
        clip->bottom = area->Height();
        clip->left = 0;
        clip->top = 0;
        clip->right = area->Width();
        recalc_blt_area();
    } else {
        *clip = *area;
        RectBox_adc8d8 local = *area;
        for (cGZWin* p = OB_PTR(cGZWin, GetParentWin()); p != 0; p = OB_PTR(cGZWin, p->GetParentWin())) {
            if (p->GetPrivateBuffer() != 0) {
                break;
            }
            if (static_cast<uint8_t>(Slot67_adc8d8(0x8000000))) {
                local = *reinterpret_cast<RectBox_adc8d8*>(field14);
                break;
            }
            int32_t top = p->GetT();
            int32_t left = p->GetL();
            local.left += left;
            local.right += left;
            local.top += top;
            local.bottom += top;
        }
        *clip = local;
        if (!(gBac060 & 1)) {
            gBac060 |= 1;
            Holder_adc8d8 draw;
            draw.Fn00449720();
            gBac05c = draw.mp != 0;
            draw.Done();
        }
        if (gBac05c) {
            int32_t origin[2];
            origin[0] = 0;
            origin[1] = 0;
            clip->Fn0082ae40(origin);
        }
    }
    *blt = *clip;
    for (cGZWin* p = this; p->GetPrivateBuffer() == 0;) {
        if (static_cast<uint8_t>(p->Slot67_adc8d8(0x8000000))) {
            RectBox_adc8d8* absolute = static_cast<RectBox_adc8d8*>(p->GetAreaAbsolute_2());
            blt->left += absolute->left;
            blt->right += absolute->left;
            blt->top += absolute->top;
            blt->bottom += absolute->top;
            break;
        }
        RectBox_adc8d8* relative = static_cast<RectBox_adc8d8*>(p->GetArea_2());
        blt->top += relative->top;
        blt->bottom += relative->top;
        blt->left += relative->left;
        blt->right += relative->left;
        p = OB_PTR(cGZWin, p->GetParentWin());
        if (p == 0) {
            break;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099c026 score 114
void cGZWin::fade_advance()
{
    if ((mnFlags & 0x20) && (mnFlags & 0x10000)) {
        Variant_adc8d8* variant = 0;
        if (GetParam(0xe6e998fd, &variant)) {
            int32_t period = *reinterpret_cast<int32_t*>(variant->GetValuePtr());
            variant->Release();
            variant = 0;
            if (period != 0) {
                if (GetParam(0xe6e998fb, &variant)) {
                    uint8_t state = *variant->GetBytePtr();
                    variant->Release();
                    variant = 0;
                    if (GetParam(0xe6e998fc, &variant)) {
                        uint32_t start = *variant->GetClockPtr();
                        variant->Release();
                        variant = 0;
                        uint32_t elapsed = clock() - start;
                        double level = static_cast<double>(elapsed) * 255.0 / period + state;
                        uint8_t value;
                        if (level < 0.0 || level >= 256.0) {
                            GetParam(0xe6e998fd, &variant);
                            variant->SetLong(0);
                            variant->Release();
                            value = 0xff;
                            if (level < 0.0) {
                                value = 0;
                            }
                        } else {
                            value = static_cast<uint8_t>(static_cast<int32_t>(level));
                        }
                        if ((mnFlags & 0x20) && (mnFlags & 0x10000) && field64 != 0) {
                            FadeBuf_adc8d8* fade = 0;
                            if (reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->QueryInterface(0x86d72b57, reinterpret_cast<void**>(&fade))) {
                                fade->Fade(0xff, 0xff, 0xff, value);
                                fade->Release();
                            }
                        }
                    }
                }
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099ea70 score 52
bool cGZWin::PrivateBuffer(uint32_t enable)
{
    bool result = false;
    if (static_cast<uint8_t>(enable)) {
        for (cGZWin* p = OB_PTR(cGZWin, GetParentWin()); p != 0; p = OB_PTR(cGZWin, p->GetParentWin())) {
            if (!reinterpret_cast<Self_adc8d8*>(p)->IsVisible()) {
                enable = 0;
                break;
            }
        }
    }
    if (static_cast<uint8_t>(enable)) {
        mnFlags |= 0x10000;
        Buf_adc8d8* buf = reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64));
        if (buf != 0) {
            RectBox_adc8d8* area = reinterpret_cast<RectBox_adc8d8*>(&unknowna0[8]);
            Size_adc8d8 wanted;
            wanted.w = area->Width();
            wanted.h = area->Height();
            const RectBox_adc8d8* have = buf->GetBufferArea_2();
            Size_adc8d8 current;
            current.w = have->Width();
            current.h = have->Height();
            if (current.Equals(&wanted)) {
                result = true;
                goto finish;
            }
        }
        {
            RectBox_adc8d8* area = reinterpret_cast<RectBox_adc8d8*>(&unknowna0[8]);
            if (!create_private_buffer(area->Width(), area->Height())) {
                goto finish;
            }
        }
        if (static_cast<uint8_t>(Slot67_adc8d8(0x20000))) {
            set_private_buffer_transparency(true);
        }
        Slot07_add348(*reinterpret_cast<int32_t*>(&unknowna0[8]), fieldac, fieldb0, fieldb4);
    } else {
        Buf_adc8d8* buf = reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64));
        if (buf != 0) {
            if (buf->Slot39()) {
                bool pending = false;
                if (static_cast<uint8_t>(Slot67_adc8d8(0x20)) && static_cast<uint8_t>(Slot67_adc8d8(0x400000))) {
                    Variant_adc8d8* variant = 0;
                    if (GetParam(0xe6e998fe, &variant)) {
                        variant->Release();
                        variant = 0;
                    } else {
                        pending = true;
                    }
                    Slot68_adc8d8(0x400000, 0);
                    for (cGZWin* p = OB_PTR(cGZWin, GetParentWin()); p != 0; p = OB_PTR(cGZWin, p->GetParentWin())) {
                        if (!reinterpret_cast<Self_adc8d8*>(p)->IsVisible()) {
                            pending = false;
                            break;
                        }
                    }
                    if (pending) {
                        void* memory = operator new(0xd8);
                        FadeTmpWin_adc8d8* fade = 0;
                        if (memory) {
                            fade = static_cast<FadeTmpWin_adc8d8*>(memory)->Fn0099ea30();
                        }
                        reinterpret_cast<cGZWin*>(fade)->Slot68_adc8d8(4, 1);
                        fade->StealBuffer(this);
                        goto release;
                    }
                }
                buf->Reset();
            }
        release:
            buf->Release();
            field64 = 0;
        }
    }
    result = true;
finish:
    SetBufferToDrawToRecursive();
    child_private_buffers(Slot67_adc8d8(1));
    InvalidateSelfAndParents();
    return result;
}
#endif

// The graphics system the function-local pointer of PlotPresent keeps.
// GLOBAL: 0x00bac058
extern GfxSys_adc8d8* gBac058;

#ifdef OB_DRAFTS
// CLOSE: 0x0099c498 score 62
bool cGZWin::PlotPresent()
{
    if (field64 == 0) {
        return true;
    }
    uint32_t buffer = 0;
    RectBox_adc8d8 clip = *reinterpret_cast<RectBox_adc8d8*>(&unknownb8[0]);
    bool resolved = false;
    if (static_cast<uint8_t>(Slot67_adc8d8(0x4000000))) {
        if (field48 != 0) {
            GfxHolder_adc8d8 graphics;
            graphics.Init();
            if (graphics.mp) {
                buffer = graphics.mp->GetDefaultBuffer();
            }
            clip = *reinterpret_cast<RectBox_adc8d8*>(field14);
            Slot68_adc8d8(0x4000000, 0);
            graphics.Done();
            resolved = true;
        }
    } else if (field48 != 0 && OB_PTR(cGZWin, field48)->GetBufferToDrawTo() != 0) {
        buffer = OB_PTR(cGZWin, field48)->GetBufferToDrawTo();
        resolved = true;
    }
    if (!resolved) {
        if (gBac058 == 0) {
            GfxHolder_adc8d8 graphics;
            graphics.Init();
            gBac058 = graphics.mp;
            graphics.Done();
        }
        if (gBac058) {
            buffer = gBac058->GetDefaultBuffer();
        }
    }
    Buf_adc8d8* target = reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(buffer));
    if (target == 0) {
        return true;
    }
    DrawIface_adc8d8* draw = 0;
    if (target->QueryInterface(0xab300b2b, reinterpret_cast<void**>(&draw))) {
        Canvas_adc8d8* canvas = draw->GetCanvas();
        canvas->Begin();
        int32_t origin[2];
        origin[0] = 0;
        origin[1] = 0;
        canvas->SetOrigin(origin);
        canvas->Reset();
        canvas->SetFlagA(static_cast<uint8_t>(Slot67_adc8d8(4)));
        canvas->SetFlagB(Slot67_adc8d8(4));
        if (static_cast<uint8_t>(Slot67_adc8d8(8))) {
            canvas->SetColor(fieldd0);
        } else {
            canvas->SetColor(0xffffffff);
        }
        FadeColor_adc8d8* fade = 0;
        if (reinterpret_cast<Buf_adc8d8*>(static_cast<uintptr_t>(field64))->QueryInterface(0x86d72b57, reinterpret_cast<void**>(&fade))) {
            uint8_t alpha;
            uint8_t red;
            uint8_t green;
            uint8_t blue;
            if (fade->GetColor(&red, &green, &blue, &alpha)) {
                if (static_cast<uint8_t>(Slot67_adc8d8(8))) {
                    const uint8_t* c = reinterpret_cast<const uint8_t*>(&fieldd0);
                    canvas->SetColor((((alpha * 0x100 + c[2]) << 8) + c[1]) * 0x100 + c[0]);
                } else {
                    canvas->SetColor((((alpha * 0x100 + red) << 8) + green) * 0x100 + blue);
                }
            }
        }
        canvas->Draw(field64, field24, &clip);
        canvas->End();
        draw->Release2();
        if (fade != 0) {
            fade->Release();
        }
    } else {
        if (target->Lock(0x8010)) {
            target->Blt(field64, field24, &clip, 0);
            target->Unlock(0x8010);
        }
    }
    if (draw != 0) {
        reinterpret_cast<Filter_adc8d8*>(draw)->Release();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099e62d score 314
bool cGZWin::PlotComposite()
{
    uint32_t visible = mnFlags & 1;
    if (mnFlags & 0x20) {
        if (!visible && !fade_in_progress()) {
            return false;
        }
        fade_advance();
    } else if (!visible) {
        return false;
    }
    Message_adc8d8 msg;
    msg.v[1] = 0;
    msg.v[2] = 0;
    msg.v[3] = 0;
    FilterList_adc8d8* filters = reinterpret_cast<FilterList_adc8d8*>(&unknown7c[0x0c]);
    uint8_t busy = unknown7c[0x14];
    msg.v[0] = 0x16;
    unknown7c[0x14] = 1;
    ListNode_adc8d8* node = filters->head->next;
    bool handled = false;
    while (node != filters->head) {
        handled |= reinterpret_cast<MsgFilter_adc8d8*>(node->data)->Process(this, &msg);
        node = node->next;
        if (handled) {
            break;
        }
    }
    unknown7c[0x14] = busy;
    if (!busy) {
        FilterList_adc8d8* pending = reinterpret_cast<FilterList_adc8d8*>(&unknown7c[0x10]);
        for (ListNode_adc8d8* p = pending->head->next; p != pending->head; p = p->next) {
            AutoRef_adc8d8 ref(*reinterpret_cast<const AutoRef_adc8d8*>(&p->data));
            ListIter_adc8d8 it = Fn009d07a0Filter(filters->head->next, filters->head, ref);
            if (p != filters->head) {
                filters->Erase(it);
            }
        }
        pending->Clear();
    }
    if (handled) {
        return true;
    }
    if (!mbInvalid) {
        EnumChildren(0x22ba0121, reinterpret_cast<void*>(Fn0099b9ac), OB_PTR(void, field4));
        return true;
    }
    if (field64 != 0) {
        if (field48 != 0) {
            mbInvalid = false;
        }
        if ((mnFlags & 0x20000) && (mnFlags & 0x40000)) {
            fill_private_buffer_with_transparent_color();
        }
    }
    AutoRef_adc8d8 context(OB_PTR(Filter_adc8d8, field6c));
    Canvas_adc8d8* canvas = reinterpret_cast<Canvas_adc8d8*>(context.mp);
    if (canvas) {
        canvas->Enter();
        canvas->SetOrigin(&field24[0x10]);
        canvas->SetClip(&field24[0x10]);
        canvas->Begin();
        canvas->P15();
        canvas->Reset();
        canvas->P19();
        bool plain;
        if (static_cast<uint8_t>(Slot67_adc8d8(4)) && !static_cast<uint8_t>(Slot67_adc8d8(0x10000))) {
            plain = true;
        } else {
            plain = false;
        }
        canvas->SetFlagA(plain);
        canvas->SetFlagB(plain);
        if (static_cast<uint8_t>(Slot67_adc8d8(8)) && !static_cast<uint8_t>(Slot67_adc8d8(0x10000))) {
            canvas->SetColor(fieldd0);
        } else {
            canvas->SetColor(0xffffffff);
        }
        canvas->P43();
    }
    GZPaint();
    if (field64 != 0) {
        mnFlags |= 0x400000;
    }
    if (canvas) {
        canvas->P42();
        canvas->End();
        canvas->Leave();
        canvas->Release();
    }
    ChildList_adc8d8* list = ChildListOf_adc8d8(this);
    ListNode_adc8d8* head = list->head;
    list->readers++;
    ListNode_adc8d8* begin = head->next;
    ListNode_adc8d8* cursor = head;
    WinMgr_adc8d8* mgr = reinterpret_cast<WinMgr_adc8d8*>(static_cast<uintptr_t>(field4));
    if (static_cast<uint8_t>(Slot67_adc8d8(0x8000000))) {
        for (; cursor != begin; cursor = cursor->prev) {
            cGZWin* child = cursor->prev->data;
            child->Slot68_adc8d8(0x4000000, 1);
            mgr->AppendToPlotStrategy(child);
        }
    } else {
        RectVector_adc8d8 covered;
        covered.begin = 0;
        covered.end = 0;
        covered.capacity = 0;
        for (; cursor != begin; cursor = cursor->prev) {
            cGZWin* child = cursor->prev->data;
            if (reinterpret_cast<Self_adc8d8*>(child)->IsVisible()) {
                if (static_cast<uint8_t>(child->Slot67_adc8d8(0x8000000))) {
                    child->Slot68_adc8d8(0x4000000, 1);
                    mgr->AppendToPlotStrategy(child);
                    covered.PushBack(static_cast<RectBox_adc8d8*>(child->GetAreaAbsolute_2()));
                } else {
                    if (covered.begin != covered.end) {
                        RectBox_adc8d8 area = *static_cast<RectBox_adc8d8*>(child->GetAreaAbsolute_2());
                        uint32_t count = covered.end - covered.begin;
                        uint32_t i = 0;
                        RectBox_adc8d8* other = covered.begin;
                        if (count != 0) {
                            do {
                                if (area.Fn0099c1e1(other)) {
                                    covered.PushBack(&area);
                                    child->Slot68_adc8d8(0x4000000, 1);
                                    mgr->AppendToPlotStrategy(child);
                                    goto next;
                                }
                                other++;
                                i++;
                            } while (i < count);
                        }
                    }
                    child->Plot();
                }
            }
        next:;
        }
        if (covered.begin != 0) {
            StlDelete_adc8d8(covered.begin);
        }
    }
    unlock_child_list_read(list);
    return true;
}
#endif
