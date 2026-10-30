#include <stddef.h>

#include "classes/cGZWinGen.h"

// A 16-byte rectangle copied as a whole.
struct Rect_adc678 {
    int32_t v[4];
    // STUB: 0x0043fde0
    bool Contains(int32_t x, int32_t y);
};

// A message record handed to the message target.
struct Msg_adc678 {
    uint32_t id;
    uint32_t p;
    uint32_t a;
    uint32_t b;
};

// The message target (field 0x10c) seen through the slots this class calls.
struct cTarget_adc678 {
    virtual bool Slot00(uint32_t a, uint32_t b);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual bool Slot03(void* win, void* msg);
    virtual bool Slot04(void* win, uint32_t id, uint32_t p, uint32_t a, uint32_t b);
};

// The background buffer (field 0xf8).
struct cBuf_adc678 {
    virtual uint32_t Slot00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual uint32_t Slot03();
    virtual uint32_t Slot04();
    virtual uint32_t Slot05();
    virtual uint32_t Slot06();
    virtual uint32_t Slot07();
    virtual uint32_t Slot08();
    virtual uint32_t GetWidth();
    virtual uint32_t GetHeight();
    virtual uint32_t Slot11();
    virtual uint32_t GetEdge(void* rect, uint32_t a, uint32_t b);
};

// The draw context (field 0x6c).
struct cDraw_adc678 {
    virtual void D00();
    virtual void D01();
    virtual void D02();
    virtual void D03();
    virtual void D04();
    virtual void D05();
    virtual void D06();
    virtual void D07();
    virtual void D08();
    virtual void D09();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void SetColor(uint32_t color);
    virtual void D21();
    virtual void FillRect(const void* rect);
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual void D32();
    virtual void D33();
    virtual void D34();
    virtual void D35();
    virtual void D36();
    virtual void D37();
    virtual void D38(void* buf, uint32_t color, const void* rect);
    virtual void D39(void* buf, uint32_t color, const void* rect, uint32_t a, uint32_t b);
};

// The window manager (field4).
struct cMgr_adc678 {
    virtual void M00();
    virtual void M01();
    virtual void M02();
    virtual void M03();
    virtual void M04();
    virtual void M05();
    virtual void M06();
    virtual void M07();
    virtual void M08();
    virtual uint32_t Notify(uint32_t what, uint32_t win, uint32_t arg);
};



// The window's own vtable, for slots whose real arguments differ from the declared ones.
struct cWinV_adc678 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual bool V14(void* child);
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual uint32_t P20();
    virtual uint32_t P21();
    virtual uint32_t P22();
    virtual uint32_t P23();
    virtual uint32_t P24();
    virtual uint32_t P25();
    virtual uint32_t P26();
    virtual uint32_t P27();
    virtual uint32_t P28();
    virtual bool V29(uint32_t a, uint32_t b, uint32_t c, const void* rect);
    virtual uint32_t P30();
    virtual uint32_t P31();
    virtual uint32_t P32();
    virtual uint32_t P33();
    virtual uint32_t P34();
    virtual uint32_t P35();
    virtual uint32_t P36();
    virtual uint32_t P37();
    virtual uint32_t P38();
    virtual uint32_t P39();
};

// The factory the original reaches through a global getter (slot 3 creates an instance).
struct cFactory_adc678 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual bool Create(uint32_t clsid, uint32_t iid, void* out);
};

// The colour bar object created by the factory.
struct cBar_adc678 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t Release();
    virtual cGZWin* GetWin();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual void SetA(uint32_t v);
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual void SetB(uint32_t v);
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual void SetC(uint32_t v);
    virtual uint32_t P19();
};

// The window manager (slot 23 removes a window).
struct cWM_adc678 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual uint32_t P20();
    virtual uint32_t P21();
    virtual uint32_t P22();
    virtual void Remove(void* win);
};

// The auto pointer the original keeps on the stack (set up and torn down by two helpers).
struct cParamHolder_adc678 {
    struct cSrc_adc678* p;
    // STUB: 0x007b2480
    void Init();
    // STUB: 0x007b24b0
    void Fini();
};

// The object the holder points at.
struct cSrc_adc678 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual uint32_t P20();
    virtual uint32_t P21();
    virtual uint32_t P22();
    virtual uint32_t P23();
    virtual uint32_t P24();
    virtual uint32_t P25();
    virtual uint32_t P26();
    virtual uint32_t P27();
    virtual uint32_t P28();
    virtual uint32_t P29();
    virtual uint32_t P30();
    virtual uint32_t P31();
    virtual uint32_t GetParam(uint32_t id);
    virtual uint32_t P33();
};

// The map of user data (header node and count) and its tree nodes.
struct Node_adc678 {
    uint32_t color;
    Node_adc678* parent;
    Node_adc678* left;
    Node_adc678* right;
    uint32_t key;
    void* value;
};

struct Iter_adc678 {
    Node_adc678* node;
    Iter_adc678() {}
    explicit Iter_adc678(Node_adc678* n) : node(n) {}
};

struct cUserData_adc678 {
    virtual uint32_t Slot00(uint32_t a, uint32_t b);
};

// STUB: 0x0090cf63
void StlDelete_adc678(void* p);

struct Pair_adc678 {
    // STUB: 0x009491ff
    void Fn009491ff(uint32_t flag);
};

struct cPair_adc678;

struct Tree_adc678 {
    Node_adc678* header;
    uint32_t count;
    // STUB: 0x0098129c
    Node_adc678* Find(const uint32_t* key);
    // STUB: 0x00968d88
    void Erase(Iter_adc678 it);
    // STUB: 0x0096a233
    void Insert(Iter_adc678* out, const cPair_adc678* v);
    void EraseSubtree(Node_adc678* node);
    void Clear();
};

// STUB: 0x0090ddf1
cFactory_adc678* Fn0090ddf1();

struct AutoRef_adc678 {
    // STUB: 0x005447b0
    void* Assign(uint32_t p);
};


// The control manager (field of a holder) and its factory-like slot 7.
struct cCtlMgr_adc678 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t GetCtrl(uint32_t id);
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual uint32_t P20();
    virtual uint32_t P21();
    virtual uint32_t P22();
    virtual uint32_t P23();
    virtual uint32_t P24();
    virtual uint32_t P25();
    virtual uint32_t P26();
    virtual uint32_t P27();
    virtual uint32_t P28();
    virtual uint32_t P29();
    virtual uint32_t P30();
    virtual uint32_t GetParam(uint32_t id);
    virtual uint32_t GetParamPlain(uint32_t id);
    virtual uint32_t P33();
};

// The message server holder.
struct cMsgSvc_adc678 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void Add(void* win, uint32_t id);
    virtual void Remove(void* win, uint32_t id);
};

struct cMsgSvcHolder_adc678 {
    cMsgSvc_adc678* p;
    // STUB: 0x004d7bb0
    void Init();
    // STUB: 0x004d7b60
    void Fini();
};

struct cCtlMgrHolder_adc678 {
    cCtlMgr_adc678* p;
    // STUB: 0x007b2480
    void Init();
    // STUB: 0x007b24b0
    void Fini();
};

// A reference holder keeping a window alive for the length of a call.
struct cKeep_adc678 {
    cGZWin* p;
    // STUB: 0x0096e773
    void Init(cGZWin* w);
};

// A reference to the original's map item, built from a pointer (the original's smart pointer).
struct cRef_adc678 {
    void* p;
    // STUB: 0x004f20c0
    void Init(void* obj);
};

struct cPair_adc678 {
    uint32_t key;
    void* value;
    // STUB: 0x00966956
    void Init(cRef_adc678* ref);
};

// A message record with the three words the handlers pass on.
struct MsgFull_adc678 {
    uint32_t id;
    uint32_t a;
    uint32_t b;
    uint32_t c;
};

// The cursor manager.
struct cCurMgr_adc678 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual void* CreateCursor(uint32_t kind);
};

// One of the title bar's controls.
struct cCtl_adc678 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual cGZWin* GetWin();
};

// The title bar's text object (slot 37).
struct cCaption_adc678 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual uint32_t P20();
    virtual uint32_t P21();
    virtual uint32_t P22();
    virtual uint32_t P23();
    virtual uint32_t P24();
    virtual uint32_t P25();
    virtual uint32_t P26();
    virtual uint32_t P27();
    virtual uint32_t P28();
    virtual uint32_t P29();
    virtual uint32_t P30();
    virtual uint32_t P31();
    virtual uint32_t P32();
    virtual uint32_t P33();
    virtual uint32_t P34();
    virtual uint32_t P35();
    virtual uint32_t P36();
    virtual int32_t Measure(uint32_t a, uint32_t b);
    virtual uint32_t P38();
    virtual uint32_t P39();
};

struct cSecV_adc678 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual void SetA(uint32_t v);
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual void SetB(uint32_t v);
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual void SetRect(const void* r);
    virtual void SetC(uint32_t v);
    virtual uint32_t P19();
};

// The title bar: a window with a few more fields.
struct cTitleBar_adc678 : public cGZWin, public cSecV_adc678 {
    char pad_adc678[0x18];
    uint32_t mnTitleFlags;
    cCaption_adc678* mpCaption;
    char pad2_adc678[0x10];
    int32_t mnRight;
    cCtl_adc678* mpCtl1;
    cCtl_adc678* mpCtl2;
    cCtl_adc678* mpCtl3;
    // STUB: 0x0099a67e
    void Ctor();
    // STUB: 0x0099b0eb
    void calc_display_caption();
    bool GetMinSize(int32_t& w, int32_t& h);
    bool place_controls();
    bool SetTitleBarFlag(int32_t flag, bool on);
};

// STUB: 0x008d8800
void RZDrawBltEdge_adc678(cDraw_adc678* context, void* buffer, const Rect_adc678* edge, const Rect_adc678* area, bool flag);

// STUB: 0x008d9470
void RZDraw3DRectangleOutline_adc678(cDraw_adc678* context, const Rect_adc678* area, uint32_t colorA, uint32_t colorB);

// STUB: 0x008d9900
void RZDrawRaisedRect_adc678(cDraw_adc678* context, const Rect_adc678* area, uint32_t color, bool a, bool b);

// STUB: 0x00999b84
bool EnumFlatRects_adc678(void* win, void* data);

// FUNCTION: 0x009993f7
bool cGZWinGen::kill_self(int32_t msg)
{
    if (static_cast<uint8_t>(Slot67_adc8d8(0x1000))) {
        OB_PTR(cMgr_adc678, field4)->Notify(0xf, OB_ADDR(Slot03_adb720()), msg);
    } else {
        PostMsg(field48, 1, OB_ADDR(Slot03_adb720()), 0, 0);
    }
    return true;
}

// FUNCTION: 0x00998f83
bool cGZWinGen::QueryInterface(uint32_t iid, void** out)
{
    void** ppv = out;
    if (iid == 0x5386d516) {
        *ppv = static_cast<cUnk00adc2b0*>(this);
        AddRef();
        return true;
    }
    return cGZWin::QueryInterface(iid, ppv);
}

// FUNCTION: 0x00998fb0
void cGZWinGen::Slot49_adda20(uint32_t a)
{
    cGZWin::Slot49_adda20(a);
    if (mpTitleBar) {
        mpTitleBar->Slot49_adda20(a);
    }
}

// FUNCTION: 0x00998fd7
bool cGZWinGen::IsPointInWindowScreenCoordinates(uint32_t x, uint32_t y)
{
    ScreenToWindowCoordinates(&x, &y);
    return IsPointInWindowWindowCoordinates(x, y);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00999004 score 3
bool cGZWinGen::GZOnKeyUp(uint32_t a, uint32_t b)
{
    if (static_cast<uint8_t>(Slot67_adc8d8(0x1000))) {
        return false;
    }
    SendMsg(field4c, 6, a, b, 0);
    return true;
}
#endif

// FUNCTION: 0x00999039
bool cGZWinGen::GZOnMouseUpL(uint32_t /*a*/, uint32_t /*b*/, uint32_t /*c*/)
{
    if (mnCaptured) {
        mnCaptured = 0;
        GZReleaseCapture();
        return true;
    }
    return false;
}

// FUNCTION: 0x00999055
uint32_t cGZWinGen::Slot05_adc2b0(uint32_t mask)
{
    return (mnWinFlags & mask) != 0;
}

// FUNCTION: 0x00999065
bool cGZWinGen::Slot10_adc2b0(uint32_t out)
{
    *OB_PTR(Rect_adc678, out) = *reinterpret_cast<Rect_adc678*>(mUserRect);
    return true;
}

// FUNCTION: 0x00999079
bool cGZWinGen::Slot11_adc2b0(uint32_t in)
{
    *reinterpret_cast<Rect_adc678*>(mUserRect) = *OB_PTR(Rect_adc678, in);
    return true;
}

// FUNCTION: 0x00999093
bool cGZWinGen::Slot09_adc2b0(uint32_t a, uint32_t b)
{
    if (!mpMsgTarget) {
        return false;
    }
    return reinterpret_cast<cTarget_adc678*>(mpMsgTarget)->Slot00(a, b);
}

// FUNCTION: 0x009990b0
bool cGZWinGen::Slot13_adc2b0(uint32_t type, uint32_t buffer)
{
    cBuf_adc678* buf = OB_PTR(cBuf_adc678, buffer);
    if (buf != mpBackground || type != mnBgBlitType) {
        if (buf) {
            buf->AddRef();
        }
        if (mpBackground) {
            reinterpret_cast<cBuf_adc678*>(mpBackground)->Release();
        }
        mpBackground = buf;
        mnBgBlitType = type;
    }
    return true;
}

// FUNCTION: 0x009990ec
bool cGZWinGen::Slot12_adc2b0(uint32_t buffer)
{
    cBuf_adc678* buf = OB_PTR(cBuf_adc678, buffer);
    if (buf != mpBackground) {
        if (buf) {
            buf->AddRef();
        }
        if (mpBackground) {
            reinterpret_cast<cBuf_adc678*>(mpBackground)->Release();
        }
        mpBackground = buf;
    }
    return true;
}

// FUNCTION: 0x0099911a
bool cGZWinGen::Slot15_adc2b0(uint32_t outType, uint32_t outBuffer)
{
    *OB_PTR(uint32_t, outType) = mnBgBlitType;
    *OB_PTR(void*, outBuffer) = mpBackground;
    return true;
}

// FUNCTION: 0x00999131
bool cGZWinGen::Slot14_adc2b0(uint32_t outBuffer)
{
    if (outBuffer) {
        *OB_PTR(void*, outBuffer) = mpBackground;
        reinterpret_cast<cBuf_adc678*>(mpBackground)->AddRef();
    }
    return true;
}

// FUNCTION: 0x0099914b
bool cGZWinGen::Slot17_adc2b0(uint32_t outType)
{
    *OB_PTR(uint32_t, outType) = mnBgBlitType;
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00999169 score 4
void cGZWinGen::Slot20_adc2b0(uint32_t a, uint32_t b)
{
    if (a != 0) {
        return;
    }
    Slot19_adc2b0(b);
}
#endif

// FUNCTION: 0x00999180
bool cGZWinGen::Slot23_adc2b0(uint32_t a, uint32_t out)
{
    if (a != 0) {
        return false;
    }
    *OB_PTR(uint32_t, out) = Slot22_adc2b0();
    return true;
}

// FUNCTION: 0x0099919b
bool cGZWinGen::Slot26_adc2b0(uint32_t x, uint32_t y)
{
    mnGutterX = static_cast<uint8_t>(x);
    mnGutterY = static_cast<uint8_t>(y);
    return true;
}

// FUNCTION: 0x009991ae
bool cGZWinGen::Slot28_adc2b0(uint32_t outX, uint32_t outY)
{
    *OB_PTR(int32_t, outX) = mnGutterX;
    *OB_PTR(int32_t, outY) = mnGutterY;
    return true;
}

// FUNCTION: 0x009991c7
void cGZWinGen::Slot25_adc2b0(uint32_t a, uint32_t b, uint32_t /*c*/, uint32_t /*d*/)
{
    Slot26_adc2b0(a, b);
}

// FUNCTION: 0x009991d7
bool cGZWinGen::Slot27_adc2b0(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(int32_t, a) = mnGutterX;
    *OB_PTR(int32_t, b) = mnGutterY;
    *OB_PTR(int32_t, c) = mnGutterX;
    *OB_PTR(int32_t, d) = mnGutterY;
    return true;
}

// FUNCTION: 0x00999204
bool cGZWinGen::Slot31_adc2b0(uint32_t id)
{
    void* child = GetChildWindowFromID(id);
    if (child) {
        Slot16_adc8d8(OB_ADDR(child));
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099922f score 3
bool cGZWinGen::calc_user_area(int32_t width, int32_t height, void* out)
{
    int32_t* r = static_cast<int32_t*>(out);
    r[0] = mnGutterX;
    if (mnWinFlags & 0x10000) {
        r[0] += mnGutterX + 8;
    }
    r[2] = width - mnGutterX;
    if (mpTitleBar) {
        r[1] = mpTitleBar->GetB() + mnGutterY;
    } else {
        r[1] = mnGutterY;
    }
    int32_t h = height - mnGutterY;
    r[3] = h;
    if (h <= r[1]) {
        h = r[1];
        r[3] = h;
    }
    return true;
}
#endif

// FUNCTION: 0x009992ae
bool cGZWinGen::calc_win_area(const void* in, void* out)
{
    *static_cast<Rect_adc678*>(out) = *static_cast<const Rect_adc678*>(in);
    int32_t* r = static_cast<int32_t*>(out);
    r[0] -= mnGutterX;
    if (mnWinFlags & 0x10000) {
        r[0] = r[0] - mnGutterX - 8;
    }
    r[2] += mnGutterX;
    if (mpTitleBar) {
        r[1] -= mpTitleBar->GetH() + mnGutterY * 2;
    } else {
        r[1] -= mnGutterY;
    }
    r[3] += mnGutterY;
    return true;
}

// FUNCTION: 0x0099933c
bool cGZWinGen::destroy_title_bar()
{
    if (mpTitleBar) {
        Slot15_adc8d8(mpTitleBar);
        mpTitleBar->Release();
        mpTitleBar = 0;
        mnGutterW2 = mnGutterX * 2;
        mnGutterH2 = mnGutterY * 2;
        cGZWin* side = static_cast<cGZWin*>(GetChildWindowFromID(0x42b7c352));
        if (side) {
            side->Slot07_add348(mnGutterX, mnGutterY, mnGutterX + 8, GetH() - mnGutterY);
        }
    }
    return true;
}

// FUNCTION: 0x009993d7
bool cGZWinGen::destroy_side_bar()
{
    void* side = GetChildWindowFromID(0x42b7c352);
    if (side) {
        Slot16_adc8d8(OB_ADDR(side));
    }
    return true;
}

// FUNCTION: 0x00999bdd
uint32_t cGZWinGen::place_controls()
{
    uint32_t packed = (static_cast<uint32_t>(mnGutterX) << 16) | mnGutterY;
    return EnumChildren(0xc2afa76f, reinterpret_cast<void*>(&EnumFlatRects_adc678), &packed) != 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00999832 score 12
bool cGZWinGen::GZOnKeyDown(uint32_t key, uint32_t mods)
{
    if (!(mnWinFlags & 4) || (key != 0x1b && (key != 0x73 || !(mods & 4)))) {
        if (static_cast<uint8_t>(Slot67_adc8d8(0x1000))) {
            return false;
        }
        SendMsg(field4c, 5, key, mods, 0);
        return true;
    }
    kill_self(0x42b7c353);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00999896 score 18
bool cGZWinGen::GZOnCommand(uint32_t a, uint32_t b)
{
    if (a == 0x287259f6) {
        int32_t m;
        if (b == 0x42b7c353) {
            m = 0x42b7c353;
        } else if (b == 0x42b7c356) {
            m = 0x42b7c356;
        } else {
            return false;
        }
        kill_self(m);
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099955d score 2
bool cGZWinGen::IsPointInWindowWindowCoordinates(uint32_t x, uint32_t y)
{
    if (mpMsgTarget) {
        char result = 0;
        Msg_adc678 m;
        m.id = 0xa2bf8ad4;
        m.p = (static_cast<uint16_t>(x) << 16) | static_cast<uint16_t>(y);
        m.a = OB_ADDR(&result);
        m.b = 0;
        if (reinterpret_cast<cTarget_adc678*>(mpMsgTarget)->Slot03(this, &m) || (mpMsgTarget && reinterpret_cast<cTarget_adc678*>(mpMsgTarget)->Slot04(this, m.id, m.p, m.a, 0))) {
            return result != 0;
        }
    }
    return cGZWin::IsPointInWindowWindowCoordinates(x, y);
}
#endif

// FUNCTION: 0x0099a5b6
void Tree_adc678::EraseSubtree(Node_adc678* node)
{
    while (node) {
        EraseSubtree(node->right);
        Node_adc678* next = node->left;
        reinterpret_cast<Pair_adc678*>(&node->key)->Fn009491ff(0);
        StlDelete_adc678(node);
        node = next;
    }
}

// FUNCTION: 0x0099a61a
void Tree_adc678::Clear()
{
    if (count) {
        EraseSubtree(header->parent);
        header->left = header;
        header->parent = 0;
        header->right = header;
        count = 0;
    }
}

// FUNCTION: 0x00999b56
void cGZWinGen::SetCursor(uint32_t cursor, uint32_t flag)
{
    reinterpret_cast<AutoRef_adc678*>(&mpCursorRef)->Assign(cursor);
    if (mnFlagE4 == 0) {
        cGZWin::SetCursor(cursor, flag);
    }
}

// FUNCTION: 0x0099a361
bool cGZWinGen::GZOnMouseDownL(uint32_t x, uint32_t y, uint32_t /*c*/)
{
    mnCaptured = calc_size_mode(x, y);
    if (mnCaptured != 0) {
        if (GZSetCapture_2()) {
            *reinterpret_cast<uint32_t*>(&unknowna0[0]) = x;
            *reinterpret_cast<uint32_t*>(&unknowna0[4]) = y;
        } else {
            mnCaptured = 0;
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099a5ed score 6
bool cGZWinGen::Slot21_adc2b0(uint32_t key, uint32_t a, uint32_t b)
{
    Tree_adc678* map = reinterpret_cast<Tree_adc678*>(&mpUserMapHead);
    Node_adc678* it = map->Find(&key);
    if (it != map->header) {
        return static_cast<cUserData_adc678*>(it->value)->Slot00(a, b);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099a643 score 6
void cGZWinGen::Slot24_adc2b0(uint32_t key)
{
    Tree_adc678* map = reinterpret_cast<Tree_adc678*>(&mpUserMapHead);
    Node_adc678* it = map->Find(&key);
    if (it != map->header) {
        map->Erase(Iter_adc678(it));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009998c8 score 4
bool cGZWinGen::Slot07_adc2b0(uint32_t proc)
{
    cTarget_adc678* p = OB_PTR(cTarget_adc678, proc);
    Msg_adc678 m;
    if (p != mpMsgTarget) {
        if (mpMsgTarget) {
            m.id = 0xa2bf8ad6;
            m.p = 0;
            m.a = 0;
            m.b = 0;
            if (!reinterpret_cast<cTarget_adc678*>(mpMsgTarget)->Slot03(static_cast<cGZWin*>(this), &m) && mpMsgTarget) {
                reinterpret_cast<cTarget_adc678*>(mpMsgTarget)->Slot04(static_cast<cGZWin*>(this), m.id, m.p, m.a, m.b);
            }
            reinterpret_cast<cTarget_adc678*>(mpMsgTarget)->Release();
        }
        mpMsgTarget = p;
        if (p) {
            m.id = 0xa2bf8ad5;
            m.p = 0;
            m.a = 0;
            m.b = 0;
            p->AddRef();
            if (!reinterpret_cast<cTarget_adc678*>(mpMsgTarget)->Slot03(static_cast<cGZWin*>(this), &m) && mpMsgTarget) {
                reinterpret_cast<cTarget_adc678*>(mpMsgTarget)->Slot04(static_cast<cGZWin*>(this), m.id, m.p, m.a, m.b);
            }
            m.id = 0xa2bf8ad8;
            if (!reinterpret_cast<cTarget_adc678*>(mpMsgTarget)->Slot03(static_cast<cGZWin*>(this), &m) && mpMsgTarget) {
                reinterpret_cast<cTarget_adc678*>(mpMsgTarget)->Slot04(static_cast<cGZWin*>(this), m.id, m.p, m.a, m.b);
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00999afe score 27
void cGZWinGen::Slot30_adc2b0(uint32_t id, uint32_t y)
{
    int32_t r[4];
    r[0] = (mnWinFlags & 0x10000) ? mnGutterX + 7 : mnGutterX - 1;
    r[1] = y;
    r[2] = static_cast<cGZWin*>(this)->GetW() - mnGutterX;
    r[3] = y + 8;
    Slot29_adc2b0(id, 3, 0xe, OB_ADDR(r));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009999ba score 42
bool cGZWinGen::Slot29_adc2b0(uint32_t id, uint32_t b, uint32_t c, uint32_t rectArg)
{
    cWinV_adc678* pv = reinterpret_cast<cWinV_adc678*>(static_cast<cGZWin*>(this));
    if (static_cast<cGZWin*>(this)->ChildExists(id)) {
        return false;
    }
    cBar_adc678* bar;
    if (!Fn0090ddf1()->Create(0xc2afa76e, 0xc2afa76f, &bar)) {
        return false;
    }
    cGZWin* w = bar->GetWin();
    w->Slot47_adda20(id);
    const Rect_adc678* r = OB_PTR(Rect_adc678, rectArg);
    w->Slot07_add348(r->v[0], r->v[1], r->v[2], r->v[3]);
    cParamHolder_adc678 holder;
    holder.Init();
    uint32_t pa = 0;
    uint32_t pb = 0;
    if (holder.p) {
        pa = holder.p->GetParam(0xbb5b2ec6);
        pb = holder.p->GetParam(0xbb5b2ec7);
    }
    w->Slot68_adc8d8(0x800, 0);
    w->Slot08_ae1a28(pa);
    bar->SetA(static_cast<uint16_t>(pb));
    bar->SetC(static_cast<uint8_t>(b));
    bar->SetB(static_cast<uint8_t>(c));
    if (!pv->V14(w)) {
        reinterpret_cast<cWM_adc678*>(OB_PTR(cWM_adc678, static_cast<cGZWin*>(this)->GetWindowManager()))->Remove(w);
        bar->Release();
        bar = 0;
        holder.Fini();
        return false;
    }
    bar->Release();
    bar = 0;
    holder.Fini();
    return true;
}
#endif

#define OB_TARGET_ADC678 reinterpret_cast<cTarget_adc678*>(mpMsgTarget)

#ifdef OB_DRAFTS
// CLOSE: 0x0099a276 score 109
bool cGZWinGen::DoMessage(uint32_t msgArg)
{
    MsgFull_adc678* msg = OB_PTR(MsgFull_adc678, msgArg);
    if (msg->id == 0xa2bf8ad8) {
        if (msg->a == field10) {
            on_layout();
            return true;
        }
        return false;
    }
    if (msg->id >= 7 && msg->id <= 0xe) {
        if (mpMsgTarget) {
            cKeep_adc678 keep;
            keep.Init(this);
            if (!OB_TARGET_ADC678->Slot03(this, msg) && mpMsgTarget) {
                OB_TARGET_ADC678->Slot04(this, msg->id, msg->a, msg->b, msg->c);
            }
            if (keep.p) {
                keep.p->Release();
            }
        }
    } else if (mpMsgTarget) {
        cKeep_adc678 keep;
        keep.Init(this);
        if (OB_TARGET_ADC678->Slot03(this, msg) || (mpMsgTarget && OB_TARGET_ADC678->Slot04(this, msg->id, msg->a, msg->b, msg->c))) {
            if (keep.p) {
                keep.p->Release();
            }
            return true;
        }
        if (keep.p) {
            keep.p->Release();
        }
    }
    return cGZWin::DoMessage(msgArg);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00999c15 score 47
uint32_t cGZWinGen::calc_size_mode(int32_t x, int32_t y)
{
    uint32_t mode = 0;
    if (reinterpret_cast<Rect_adc678*>(mUserRect)->Contains(x, y)) {
        return mode;
    }
    if (mnWinFlags & 2) {
        if (x < mnGutterX) {
            if (y < mnGutterY) {
                mode = 6;
            } else {
                mode = (y <= static_cast<int32_t>(GetH()) - mnGutterY) ? 2 : 8;
            }
        } else if (x > static_cast<int32_t>(GetW()) - mnGutterX) {
            if (y < mnGutterY) {
                mode = 7;
            } else {
                mode = (y <= static_cast<int32_t>(GetH()) - mnGutterY) ? 3 : 9;
            }
        } else if (y < mnGutterY) {
            mode = 4;
        } else if (y > static_cast<int32_t>(GetH()) - mnGutterY) {
            mode = 5;
        }
    }
    if (mnWinFlags & 1) {
        if (!mpTitleBar || static_cast<Rect_adc678*>(mpTitleBar->GetArea_2())->Contains(x, y)) {
            mode = 1;
        }
    }
    return mode;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00999d43 score 107
bool cGZWinGen::on_layout()
{
    if (!mpMsgTarget) {
        return false;
    }
    Rect_adc678 area = *reinterpret_cast<Rect_adc678*>(mUserRect);
    Rect_adc678 limits;
    limits.v[0] = 0;
    limits.v[1] = 0;
    limits.v[2] = 0x7fffffff;
    limits.v[3] = 0x7fffffff;
    Msg_adc678 m;
    m.id = 0xa2bf8ad2;
    m.p = OB_ADDR(&limits);
    m.a = OB_ADDR(&area);
    m.b = 0;
    if (OB_TARGET_ADC678->Slot03(this, &m) || (mpMsgTarget && OB_TARGET_ADC678->Slot04(this, m.id, m.p, m.a, 0))) {
        int32_t v = limits.v[0];
        if (area.v[2] - area.v[0] < v || (v = limits.v[2], limits.v[2] < area.v[2] - area.v[0])) {
            area.v[2] = area.v[0] + v;
        }
        v = limits.v[1];
        if (area.v[3] - area.v[1] < v || (v = limits.v[3], limits.v[3] < area.v[3] - area.v[1])) {
            area.v[3] = area.v[1] + v;
        }
        Rect_adc678 win;
        calc_win_area(&area, &win);
        int32_t w = win.v[2] - win.v[0];
        int32_t h = win.v[3] - win.v[1];
        if (w != static_cast<int32_t>(GetW()) || h != static_cast<int32_t>(GetH())) {
            SetSize_2(w, h);
            return true;
        }
    }
    Msg_adc678 n;
    n.id = 0xa2bf8ad3;
    n.p = OB_ADDR(mUserRect);
    n.b = 0;
    n.a = OB_ADDR(GetArea_2());
    if (!OB_TARGET_ADC678->Slot03(this, &n) && mpMsgTarget) {
        OB_TARGET_ADC678->Slot04(this, n.id, n.p, n.a, n.b);
    }
    return true;
}
#endif

// FUNCTION: 0x00999eb9
bool cGZWinGen::create_side_bar()
{
    if (ChildExists(0x42b7c352)) {
        return true;
    }
    int32_t r[4];
    if (mpTitleBar) {
        r[1] = mpTitleBar->GetB() - 1;
    } else {
        r[1] = mnGutterY;
    }
    r[3] = GetH() - mnGutterY;
    r[0] = mnGutterX;
    r[2] = r[0] + 8;
    if (!Slot29_adc2b0(0x42b7c352, 4, 0xd, OB_ADDR(r))) {
        return false;
    }
    cGZWin* bar = static_cast<cGZWin*>(GetChildWindowFromID(0x42b7c352));
    if (bar) {
        bar->Slot68_adc8d8(0x800, 1);
        ChildToBack(bar);
        bar->Slot68_adc8d8(0x800, 0);
        if (mpTitleBar) {
            mpTitleBar->Slot68_adc8d8(0x800, 1);
            ChildToBack(mpTitleBar);
            mpTitleBar->Slot68_adc8d8(0x800, 0);
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099a0af score 97
void cGZWinGen::Slot07_add348(uint32_t l, uint32_t t, uint32_t r, uint32_t b)
{
    int32_t h = b - t;
    int32_t w = r - l;
    if (w <= static_cast<int32_t>(mnGutterW2)) {
        w = mnGutterW2;
    }
    if (h <= static_cast<int32_t>(mnGutterH2)) {
        h = mnGutterH2;
    }
    if (w == static_cast<int32_t>(GetW()) && h == static_cast<int32_t>(GetH())) {
        cGZWin::Slot07_add348(l, t, l + w, t + h);
    } else {
        if (mpMsgTarget) {
            Rect_adc678 area;
            calc_user_area(w, h, &area);
            Rect_adc678 limits;
            limits.v[0] = 0;
            limits.v[1] = 0;
            limits.v[2] = 0x7fffffff;
            limits.v[3] = 0x7fffffff;
            Msg_adc678 m;
            m.id = 0xa2bf8ad2;
            m.p = OB_ADDR(&limits);
            m.a = OB_ADDR(&area);
            m.b = 0;
            if (OB_TARGET_ADC678->Slot03(this, &m) || (mpMsgTarget && OB_TARGET_ADC678->Slot04(this, m.id, m.p, m.a, 0))) {
                int32_t v = limits.v[0];
                if (area.v[2] - area.v[0] < v || (v = limits.v[2], limits.v[2] < area.v[2] - area.v[0])) {
                    area.v[2] = area.v[0] + v;
                }
                v = limits.v[1];
                if (area.v[3] - area.v[1] < v || (v = limits.v[3], limits.v[3] < area.v[3] - area.v[1])) {
                    area.v[3] = area.v[1] + v;
                }
                Rect_adc678 win;
                calc_win_area(&area, &win);
                w = win.v[2] - win.v[0];
                h = win.v[3] - win.v[1];
            }
        }
        cGZWin::Slot07_add348(l, t, l + w, t + h);
        place_controls();
        calc_user_area(w, h, mUserRect);
    }
    if (mpMsgTarget) {
        Msg_adc678 n;
        n.id = 0xa2bf8ad3;
        n.p = OB_ADDR(mUserRect);
        n.b = 0;
        n.a = OB_ADDR(GetArea_2());
        if (!OB_TARGET_ADC678->Slot03(this, &n) && mpMsgTarget) {
            OB_TARGET_ADC678->Slot04(this, n.id, n.p, n.a, n.b);
        }
    }
}
#endif

// FUNCTION: 0x0099a804
bool cGZWinGen::Slot04_ae1d24()
{
    if (get_init_flag()) {
    cKeep_adc678 keep;
    keep.Init(this);
    HideWindow();
    cMsgSvcHolder_adc678 svc;
    svc.Init();
    if (svc.p) {
        svc.p->Remove(this, 0xa2bf8ad8);
    }
    if (mpTitleBar) {
        Slot15_adc8d8(mpTitleBar);
        mpTitleBar->Slot04_ae1d24();
        mpTitleBar->Release();
        mpTitleBar = 0;
    }
    if (mpBackground) {
        reinterpret_cast<cBuf_adc678*>(mpBackground)->Release();
        mpBackground = 0;
    }
    if (mpMsgTarget) {
        Msg_adc678 m;
        m.id = 0xa2bf8ad1;
        m.p = 0;
        m.a = 0;
        m.b = 0;
        if (!OB_TARGET_ADC678->Slot03(this, &m) && mpMsgTarget) {
            OB_TARGET_ADC678->Slot04(this, m.id, 0, 0, 0);
        }
    }
    Slot07_adc2b0(0);
    reinterpret_cast<Tree_adc678*>(&mpUserMapHead)->Clear();
    bool result = cGZWin::Slot04_ae1d24();
    svc.Fini();
    if (keep.p) {
        keep.p->Release();
    }
        return result;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099afa8 score 4
bool cGZWinGen::Slot03_ae1d24()
{
    if (!get_init_flag()) {
    cGZWin::Slot03_ae1d24();
    cCtlMgrHolder_adc678 ctl;
    ctl.Init();
    if (ctl.p && !mpBackground) {
        uint32_t o = ctl.p->GetCtrl(0xe2b14588);
        if (o) {
            Slot13_adc2b0(0, o);
        }
    }
    if (!Slot05_adc2b0(0x1000)) {
        create_title_bar();
    }
    place_controls();
    calc_user_area(GetW(), GetH(), mUserRect);
    cMsgSvcHolder_adc678 svc;
    svc.Init();
    if (svc.p) {
        svc.p->Add(this, 0xa2bf8ad8);
    }
    reinterpret_cast<cWM_adc678*>(OB_PTR(cWM_adc678, GetWindowManager()))->Remove(0);
    GZSetCapture();
    if (mpMsgTarget) {
        Msg_adc678 m;
        m.id = 0xa2bf8ad0;
        m.p = 0;
        m.a = 0;
        m.b = 0;
        if (!OB_TARGET_ADC678->Slot03(this, &m) && mpMsgTarget && !OB_TARGET_ADC678->Slot04(this, m.id, 0, 0, 0)) {
            svc.Fini();
            ctl.Fini();
            return false;
        }
    }
    on_layout();
        svc.Fini();
        ctl.Fini();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099b5bf score 88
bool cGZWinGen::Slot06_adc2b0(uint32_t flag, uint32_t onArg)
{
    bool on = onArg != 0;
    if (on) {
        mnWinFlags |= flag;
    } else {
        mnWinFlags &= ~flag;
    }
    if (mpTitleBar) {
        cTitleBar_adc678* tb = static_cast<cTitleBar_adc678*>(mpTitleBar);
        if (flag == 0x10) {
            tb->SetTitleBarFlag(1, on);
        } else if (flag == 0x20) {
            tb->SetTitleBarFlag(2, on);
        } else if (flag == 0x40) {
            tb->SetTitleBarFlag(4, on);
        } else if (flag == 0x100) {
            tb->SetTitleBarFlag(0x100, on);
        } else if (flag == 0x200) {
            tb->SetTitleBarFlag(0x200, on);
        } else if (flag == 0x400) {
            tb->SetTitleBarFlag(0x400, on);
        }
    }
    if (flag == 0x1000) {
        if (on) {
            destroy_title_bar();
        } else {
            create_title_bar();
        }
        calc_user_area(GetH(), GetW(), mUserRect);
        on_layout();
    } else if (flag == 0x10000) {
        if (on) {
            create_side_bar();
        } else {
            destroy_side_bar();
        }
        calc_user_area(GetH(), GetW(), mUserRect);
        on_layout();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099a3a7 score 200
bool cGZWinGen::GZOnMouseMove(uint32_t x, uint32_t y, uint32_t c)
{
    if (mnCaptured == 0) {
        uint32_t mode = calc_size_mode(x, y);
        if (!(mnWinFlags & 2) || !(mnWinFlags & 1) || mnFlagE4 == mode) {
            return true;
        }
        cCurMgr_adc678* mgr = static_cast<cCurMgr_adc678*>(GetCursorManager());
        if (!mgr) {
            return true;
        }
        mnFlagE4 = mode;
        void* cursor;
        switch (mode) {
        case 2:
        case 3:
            cursor = mgr->CreateCursor(10);
            break;
        case 4:
        case 5:
            cursor = mgr->CreateCursor(8);
            break;
        case 6:
        case 9:
            cursor = mgr->CreateCursor(9);
            break;
        case 7:
        case 8:
            cursor = mgr->CreateCursor(7);
            break;
        default:
            cursor = 0;
            if (mpCursorRef) {
                cursor = mpCursorRef;
                cGZWin::SetCursor(OB_ADDR(cursor), 1);
                return true;
            }
            break;
        }
        if (!cursor) {
            cursor = mgr->CreateCursor(mode == 1 || mode == 0 ? 1 : 0x11);
            if (!cursor) {
                return true;
            }
        }
        cGZWin::SetCursor(OB_ADDR(cursor), 1);
        return true;
    }
    int32_t dx = x - *reinterpret_cast<uint32_t*>(&unknowna0[0]);
    int32_t dy = y - *reinterpret_cast<uint32_t*>(&unknowna0[4]);
    int32_t* ap = static_cast<int32_t*>(GetArea_2());
    int32_t r[4];
    r[0] = ap[0];
    r[1] = ap[1];
    r[2] = ap[2];
    r[3] = ap[3];
    switch (mnCaptured) {
    case 1:
        r[0] += dx;
        r[2] += dx;
        r[1] += dy;
        r[3] += dy;
        break;
    case 2:
        r[0] += dx;
        break;
    case 6:
        r[0] += dx;
    case 4:
        r[1] += dy;
        break;
    case 7:
        r[1] += dy;
    case 3:
        r[2] += dx;
        *reinterpret_cast<int32_t*>(&unknowna0[0]) += dx;
        break;
    case 8:
        r[0] += dx;
    case 5:
        r[3] += dy;
        *reinterpret_cast<int32_t*>(&unknowna0[4]) += dy;
        break;
    case 9:
        r[2] += dx;
        *reinterpret_cast<int32_t*>(&unknowna0[0]) += dx;
        r[3] += dy;
        *reinterpret_cast<int32_t*>(&unknowna0[4]) += dy;
        break;
    default:
        return true;
    }
    cGZWin::SetArea(OB_ADDR(r));
    if (mnCaptured == 1) {
        InvalidateAllParents();
    } else {
        InvalidateSelfAndParents();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099a90b score 2
void cGZWinGen::Slot18_adc2b0(uint32_t key, uint32_t obj)
{
    cRef_adc678 ref;
    Iter_adc678 result;
    ref.Init(OB_PTR(void, obj));
    cPair_adc678 pair;
    pair.key = key;
    pair.Init(&ref);
    if (ref.p) {
        reinterpret_cast<cBuf_adc678*>(ref.p)->Release();
    }
    Slot24_adc2b0(key);
    if (obj) {
        Tree_adc678* map = reinterpret_cast<Tree_adc678*>(&mpUserMapHead);
        map->Insert(&result, &pair);
    }
    if (pair.value) {
        reinterpret_cast<cBuf_adc678*>(pair.value)->Release();
    }
}
#endif

// FUNCTION: 0x00998f1d
bool cTitleBar_adc678::GetMinSize(int32_t& w, int32_t& h)
{
    w = 0x80;
    h = 8;
    if (mpCaption) {
        int32_t m = mpCaption->Measure(0, 0) + 8;
        if (h < m) {
            h = m;
        }
    }
    if (mpCtl1) {
        int32_t m = mpCtl1->GetWin()->GetH() + 2;
        if (h < m) {
            h = m;
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0099b50f score 70
bool cTitleBar_adc678::SetTitleBarFlag(int32_t flag, bool on)
{
    cCtl_adc678* ctl;
    if (flag == 4) {
        ctl = mpCtl3;
    } else if (flag > 4) {
        if (flag == 0x200) {
            ctl = mpCtl2;
        } else if (flag == 0x400) {
            ctl = mpCtl3;
        } else if (flag == 0x100) {
            ctl = mpCtl1;
        } else {
            goto done;
        }
        if (ctl) {
            ctl->GetWin()->Slot68_adc8d8(2, !on);
        }
        goto done;
    } else if (flag == 1) {
        ctl = mpCtl1;
    } else if (flag == 2) {
        ctl = mpCtl2;
    } else {
        goto done;
    }
    if (ctl) {
        ctl->GetWin()->Slot68_adc8d8(1, on);
        place_controls();
    }
done:
    if (on) {
        mnTitleFlags |= flag;
    } else {
        mnTitleFlags &= ~flag;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099b285 score 44
bool cTitleBar_adc678::place_controls()
{
    int32_t right = GetW() - 4;
    cGZWin* w = 0;
    if (mpCtl1) {
        w = mpCtl1->GetWin();
        if (w && w->Slot67_adc8d8(1)) {
            w->GZWinMoveTo(right - w->GetW(), (GetH() - w->GetH()) / 2);
            w->Slot68_adc8d8(0x800, 1);
            ChildToBack(w);
            w->Slot68_adc8d8(0x800, 0);
            right = w->GetL();
        }
        w = 0;
    }
    if (mpCtl2) {
        w = mpCtl2->GetWin();
    }
    if (w && w->Slot67_adc8d8(1)) {
        w->GZWinMoveTo(right - w->GetW(), (GetH() - w->GetH()) / 2);
        w->Slot68_adc8d8(0x800, 1);
        ChildToBack(w);
        w->Slot68_adc8d8(0x800, 0);
        right = w->GetL();
        w = 0;
    }
    if (mpCtl3) {
        w = mpCtl3->GetWin();
    }
    if (w && w->Slot67_adc8d8(1)) {
        w->GZWinMoveTo(right - w->GetW(), (GetH() - w->GetH()) / 2);
        w->Slot68_adc8d8(0x800, 1);
        ChildToBack(w);
        w->Slot68_adc8d8(0x800, 0);
        right = w->GetL();
    }
    int32_t old = mnRight;
    mnRight = right;
    if (right > 0 && right != old) {
        calc_display_caption();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0099a96e rough draft, not scored
bool cGZWinGen::create_title_bar()
{
    if (mpTitleBar) {
        return true;
    }
    cCtlMgrHolder_adc678 ctl;
    ctl.Init();
    uint32_t pa = 0;
    uint32_t pb = 0;
    if (ctl.p) {
        pa = ctl.p->GetParamPlain(0xbb5b2ec6);
    }
    if (ctl.p) {
        pb = ctl.p->GetParamPlain(0xbb5b2ec7);
    }
    cTitleBar_adc678* tb = 0;
    void* mem = ::operator new(0x11c);
    if (mem) {
        tb = static_cast<cTitleBar_adc678*>(mem);
        tb->Ctor();
    }
    mpTitleBar = tb;
    mpTitleBar->AddRef();
    mpTitleBar->Slot47_adda20(0x42b7c351);
    mpTitleBar->GZWinMoveTo(mnGutterX, mnGutterY);
    mpTitleBar->Slot68_adc8d8(0x800, 0);
    Slot06_adc2b0(0x10, Slot05_adc2b0(0x10));
    Slot06_adc2b0(0x40, Slot05_adc2b0(0x40));
    Slot06_adc2b0(0x20, Slot05_adc2b0(0x20));
    Slot06_adc2b0(0x100, Slot05_adc2b0(0x100));
    Slot06_adc2b0(0x400, Slot05_adc2b0(0x400));
    Slot06_adc2b0(0x200, Slot05_adc2b0(0x200));
    cSecV_adc678* sec = tb;
    sec->SetB(0xf);
    sec->SetC(5);
    mpTitleBar->Slot08_ae1a28(pa);
    sec->SetA(static_cast<uint16_t>(pb));
    if (reinterpret_cast<cWinV_adc678*>(static_cast<cGZWin*>(this))->V14(mpTitleBar)) {
        Slot49_adda20(OB_ADDR(Slot50_adda20()));
        int32_t h = GetH();
        int32_t gx = mnGutterX;
        int32_t gy = mnGutterY;
        int32_t r[4];
        r[0] = gx;
        r[1] = gy;
        r[2] = GetW() - gx;
        r[3] = h - gy;
        sec->SetRect(r);
        tb->GetMinSize(*reinterpret_cast<int32_t*>(&mnGutterW2), *reinterpret_cast<int32_t*>(&mnGutterH2));
        mnGutterW2 += mnGutterX * 2;
        mnGutterH2 += mnGutterY * 2;
        if (static_cast<int32_t>(GetW()) < static_cast<int32_t>(mnGutterW2) || static_cast<int32_t>(GetH()) < static_cast<int32_t>(mnGutterH2)) {
            SetSize_2(mnGutterW2, mnGutterH2);
        }
        cGZWin* side = static_cast<cGZWin*>(GetChildWindowFromID(0x42b7c352));
        if (side) {
            side->Slot68_adc8d8(0x800, 1);
            ChildToFront_2(side);
            side->Slot68_adc8d8(0x800, 0);
            side->Slot07_add348(mnGutterX + 0, mpTitleBar->GetB() - 1, mnGutterX + 8, GetH() - mnGutterY);
        }
        ctl.Fini();
        return true;
    }
    mpTitleBar->Release();
    mpTitleBar = 0;
    ctl.Fini();
    return false;
}
#endif
