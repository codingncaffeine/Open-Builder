#include "classes/cGZWinHTML.h"
#include <string>
#include <algorithm>
#include "gzcom/cIGZString.h"

// A 16-byte rectangle.
struct Rect_acd0d8 {
    int32_t v[4];
};

// A queried/held reference-counted object.
struct cRef_acd0d8 {
    virtual void D0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void* GetWindow();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
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
};

// The document, seen through the slots used.
struct cDoc_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void* GetData();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void* GetRoot();
    virtual void* FindAnchor(uint32_t name);
    virtual bool IsLayoutDone();
    virtual void SetLayoutDone(uint32_t v);
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
};

// A document element (the part read here).
struct cElem_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual int32_t HitTest(uint32_t out, int32_t x, int32_t y);
    virtual void D8();
    virtual void D9();
};

// A scroll bar, seen through the slots used.
struct cScroll_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual uint32_t Release();
    virtual void* GetWindow();
    virtual void D4();
    virtual void SetPosition(int32_t value);
    virtual int32_t GetPosition();
    virtual void SetRange(int32_t a, int32_t b);
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void SetPage(int32_t a, int32_t b);
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
};


// An embedded sub-object, seen through the slot used.
struct cSub_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void Slot13();
};

// A command message the load cancel sends.
struct Msg_acd0d8 {
    uint32_t id;
    void* sender;
    uint32_t a;
    uint32_t b;
};

// FUNCTION: 0x008fa40c
bool cGZWinHTML::QueryInterface(uint32_t iid, void** ppv)
{
    void** out = ppv;
    switch (iid) {
    case 1:
    case 0x4a11fd4a:
        *out = static_cast<cUnk00accfb8*>(this);
        break;
    case 0x22ba0121:
        *out = this;
        break;
    case 0x452294aa:
        *out = static_cast<cUnk00aaaa9c*>(this);
        break;
    default:
        return cGZWin::QueryInterface(iid, out);
    }
    AddRef();
    return true;
}

// FUNCTION: 0x008fa45d
void cGZWinHTML::Slot26_accfb8(uint32_t a)
{
    if (!(a & mnFlags)) {
        Slot27_accfb8(mnFlags | a);
    }
}

// FUNCTION: 0x008fa478
void cGZWinHTML::Slot28_accfb8(uint32_t a)
{
    if (a & mnFlags) {
        Slot27_accfb8(~a & mnFlags);
    }
}

// FUNCTION: 0x008fa495
uint32_t cGZWinHTML::Slot29_accfb8(uint32_t a)
{
    return (mnFlags & a) != 0;
}

// FUNCTION: 0x008fa4a8
void cGZWinHTML::Slot27_accfb8(uint32_t a)
{
    uint32_t* p = &mnFlags;
    if (a != *p) {
        *p = a;
    }
}

// FUNCTION: 0x008fa4bb
void cGZWinHTML::Slot31_accfb8(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(int32_t, a) = mnGutter[0];
    *OB_PTR(int32_t, b) = mnGutter[1];
    *OB_PTR(int32_t, c) = mnGutter[2];
    *OB_PTR(int32_t, d) = mnGutter[3];
}

// FUNCTION: 0x008fa5f3
bool cGZWinHTML::Slot04_accfb8(uint32_t a)
{
    cRef_acd0d8* www = OB_PTR(cRef_acd0d8, a);
    if (mpWWW != www) {
        if (www) {
            www->AddRef();
        }
        cRef_acd0d8* old = static_cast<cRef_acd0d8*>(mpWWW);
        if (old) {
            old->Release();
        }
        mpWWW = www;
    }
    return true;
}

// FUNCTION: 0x008fa62a
void cGZWinHTML::SetFillColor(uint32_t r, uint32_t g, uint32_t b)
{
    cGZWin::SetFillColor(r, g, b);
    mnFillColor = MakeFillColor(r, g, b);
}

// FUNCTION: 0x008fa65c
void cGZWinHTML::Slot06_accfb8(uint32_t a, uint32_t b)
{
    *OB_PTR(int32_t, a) = mnViewRect[0];
    *OB_PTR(int32_t, b) = mnViewRect[1];
}

// FUNCTION: 0x008fa671
bool cGZWinHTML::Slot08_accfb8(uint32_t a, uint32_t b)
{
    uint8_t* e = static_cast<uint8_t*>(static_cast<cDoc_acd0d8*>(mpDocument)->FindAnchor(a));
    if (e && e[9]) {
        *OB_PTR(Rect_acd0d8, b) = *reinterpret_cast<Rect_acd0d8*>(e + 0xc);
        return true;
    }
    return false;
}

// FUNCTION: 0x008fa69f
bool cGZWinHTML::Slot13_accfb8(uint32_t a, uint32_t b)
{
    *OB_PTR(void*, a) = mpVScrollImage;
    *OB_PTR(Rect_acd0d8, b) = *reinterpret_cast<Rect_acd0d8*>(mnVScrollRect);
    return *OB_PTR(void*, a) != 0;
}

// FUNCTION: 0x008fa6c9
bool cGZWinHTML::Slot14_accfb8(uint32_t a, uint32_t b)
{
    *OB_PTR(void*, a) = mpHScrollImage;
    *OB_PTR(Rect_acd0d8, b) = *reinterpret_cast<Rect_acd0d8*>(mnHScrollRect);
    return *OB_PTR(void*, a) != 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008fa9a7 score 21 (logic matches; register/order differ)
bool cGZWinHTML::Slot24_accfb8()
{
    if (mnLoadState == 1) {
        mnLoadState = 0;
        Msg_acd0d8 m;
        m.id = 0xe4a85d8f;
        m.sender = static_cast<cGZWin*>(this);
        m.a = 0;
        m.b = 1;
        SendMsg_2(field4c, OB_ADDR(&m));
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008fa4ee score 8 (logic matches; register/order differ)
bool cGZWinHTML::GZOnMouseWheel(uint32_t, uint32_t, uint32_t, uint32_t d)
{
    if (GZAmCapturing()) {
        return true;
    }
    uint32_t f = mnFlags | 0x10;
    int32_t delta = static_cast<int32_t>(d);
    if (delta > 0) {
        int32_t n = delta / 100;
        if (n > 0) {
            do {
                GZOnKeyDown(0x26, 0);
                n--;
            } while (n != 0);
        }
    } else if (delta < 0) {
        int32_t n = delta / -100;
        if (n > 0) {
            do {
                GZOnKeyDown(0x28, 0);
                n--;
            } while (n != 0);
        }
    }
    mnFlags = f;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008fa57d score 14 (logic matches; register/order differ)
bool cGZWinHTML::PickElement(uint32_t a, int32_t x, int32_t y)
{
    if (mpDocument) {
        cElem_acd0d8* e = static_cast<cElem_acd0d8*>(static_cast<cDoc_acd0d8*>(mpDocument)->GetRoot());
        if (e && reinterpret_cast<uint8_t*>(e)[9]) {
            if (IsPointInWindowWindowCoordinates(x, y)) {
                int32_t ey = mnViewRect[1] - mnOffsetY + y;
                int32_t ex = mnViewRect[0] - mnOffsetX + x;
                return e->HitTest(a, ex, ey) == 2;
            }
        }
    }
    return false;
}
#endif

// FUNCTION: 0x008fa6f3
void cGZWinHTML::RemoveScrollBar(bool vertical, bool horizontal)
{
    bool removed = false;
    if (vertical && mpVScroll) {
        cScroll_acd0d8* s = static_cast<cScroll_acd0d8*>(mpVScroll);
        removed = true;
        Slot16_adc8d8(OB_ADDR(s->GetWindow()));
        static_cast<cScroll_acd0d8*>(mpVScroll)->Release();
        mpVScroll = 0;
    }
    if (horizontal && mpHScroll) {
        cScroll_acd0d8* s = static_cast<cScroll_acd0d8*>(mpHScroll);
        removed = true;
        Slot16_adc8d8(OB_ADDR(s->GetWindow()));
        static_cast<cScroll_acd0d8*>(mpHScroll)->Release();
        mpHScroll = 0;
    }
    if (removed) {
        Fn008fa559();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x008fa776 score 27 (logic matches; reg/order)
void cGZWinHTML::SetScrollBarValues(bool reset)
{
    if (mpDocument) {
        cDoc_acd0d8* doc = static_cast<cDoc_acd0d8*>(mpDocument);
        if (doc->GetRoot()) {
            int32_t* root = static_cast<int32_t*>(doc->GetRoot());
            if (mpVScroll) {
                if (reset) {
                    int32_t total = root[6];
                    int32_t step = total / 20;
                    int32_t visible = mnViewRect[3] - mnViewRect[1];
                    int32_t range = total - visible;
                    if (range < 0) {
                        range = 0;
                    }
                    static_cast<cScroll_acd0d8*>(mpVScroll)->SetRange(0, range);
                    static_cast<cScroll_acd0d8*>(mpVScroll)->SetPage(step, total / visible + 1);
                }
                static_cast<cScroll_acd0d8*>(mpVScroll)->SetPosition(mnViewRect[1]);
            }
            if (mpHScroll) {
                if (reset) {
                    int32_t total = root[5];
                    int32_t visible = mnViewRect[2] - mnViewRect[0];
                    int32_t step = total / 15;
                    int32_t range = total - visible;
                    if (range < 0) {
                        range = 0;
                    }
                    static_cast<cScroll_acd0d8*>(mpVScroll)->SetRange(0, range);
                    static_cast<cScroll_acd0d8*>(mpVScroll)->SetPage(step, total / visible + 1);
                }
                static_cast<cScroll_acd0d8*>(mpVScroll)->SetPosition(mnViewRect[0]);
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008fa9f4 score 40 (logic matches; reg/order)
bool cGZWinHTML::GZOnCommand(uint32_t a, uint32_t b)
{
    if (a != 0x887113a3) {
        return false;
    }
    if (mpVScroll && b == static_cast<cGZWin*>(static_cast<cScroll_acd0d8*>(mpVScroll)->GetWindow())->Slot48_adda20()) {
        int32_t h = mnViewRect[3] - mnViewRect[1];
        mnViewRect[1] = static_cast<cScroll_acd0d8*>(mpVScroll)->GetPosition();
        mnViewRect[3] = mnViewRect[1] + h;
        InvalidateSelfAndParents();
    } else if (mpHScroll && b == static_cast<cGZWin*>(static_cast<cScroll_acd0d8*>(mpHScroll)->GetWindow())->Slot48_adda20()) {
        int32_t w = mnViewRect[2] - mnViewRect[0];
        mnViewRect[0] = static_cast<cScroll_acd0d8*>(mpHScroll)->GetPosition();
        mnViewRect[2] = mnViewRect[0] + w;
        InvalidateSelfAndParents();
    }
    return true;
}
#endif

// STUB: 0x00462d10
void CopyTable_acd0d8(const uint32_t* begin, const uint32_t* end, uint32_t* dest, char tag);

#ifdef OB_DRAFTS
// CLOSE: 0x008fb654 score 3 (logic matches; reg/order)
void Fn008fb654(const uint32_t* begin, const uint32_t* end, uint32_t* dest)
{
    char tag;
    CopyTable_acd0d8(begin, end, dest, tag);
}
#endif

// FUNCTION: 0x008fb127
void cGZWinHTML::Slot32_accfb8(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    mnGutter[0] = a;
    mnGutter[1] = b;
    mnGutter[2] = c;
    mnGutter[3] = d;
    SetHTMLPaintArea();
    Fn008fa559();
}

#ifdef OB_DRAFTS
// CLOSE: 0x008fb66f score 2 (logic matches; reg/order)
void cGZWinHTML::Slot33_accfb8(uint32_t a)
{
    const uint32_t* table = OB_PTR(const uint32_t, a);
    Fn008fb654(table, table + 7, reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) + 0x12c));
}
#endif

// FUNCTION: 0x008fb73a
void cGZWinHTML::Slot23_accfb8()
{
    reinterpret_cast<cSub_acd0d8*>(reinterpret_cast<char*>(this) + 0x16c)->Slot13();
}

#ifdef OB_DRAFTS
// CLOSE: 0x008fbf73 score 27 (logic matches; reg/order)
bool cGZWinHTML::Slot22_accfb8(uint32_t a, uint32_t b)
{
    if (InternalSetDocument(a, b)) {
        uint32_t old = mnLoadState;
        if (old != 2) {
            mnLoadState = 2;
            Msg_acd0d8 m;
            m.id = 0xe4a85d8f;
            m.sender = static_cast<cGZWin*>(this);
            m.a = 2;
            m.b = old;
            SendMsg_2(field4c, OB_ADDR(&m));
        }
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}
#endif

// ---- batch 4 ----
#define HTML_I32(base, off) (*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + (off)))
#define HTML_PTR(base, off) (*reinterpret_cast<void**>(reinterpret_cast<char*>(base) + (off)))

// A two-integer size.
struct Size_acd0d8 {
    int32_t w;
    int32_t h;
    // STUB: 0x00798070
    bool Equals(const Size_acd0d8* other) const;
};

// A rectangle that can compare itself.
struct RectEq_acd0d8 {
    int32_t v[4];
    // STUB: 0x005dc950
    bool Equals(const RectEq_acd0d8* other) const;
};

// A document element, seen through the slots used (data read by offset).
struct cEl2_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void Layout(void* context);
    virtual void Finish();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void OnMouseDown(void* owner);
    virtual void OnMouseUp(void* owner);
};

// The document data (text), seen through the slots used.
struct cData_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual const char* GetText();
    virtual uint32_t GetLength();
};

// A scroll bar image holder, seen through the slots used.
struct cImg_acd0d8 {
    virtual void D0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void* GetRegion();
};

// A scroll bar, seen through the slot that takes an image.
struct cScrollImg_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void SetImage(const void* region, void* image, uint32_t flag);
};

// The timer at +0x1dc, seen through the slot used.
struct cTimer_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void Stop();
};

// The manager and the resource holder reached while initialising.
struct cRes_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual cRef_acd0d8* Get(uint32_t id);
};
struct cWM_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
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
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual cRes_acd0d8* GetResources();
};
struct cCOM_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual bool GetClass(uint32_t clsid, uint32_t iid, void** out);
};
struct cSvc_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual bool GetService(uint32_t clsid, uint32_t iid, void** out);
};

// STUB: 0x00913c72
void* WCM_acd0d8();

// STUB: 0x0090ddf1
cCOM_acd0d8* GZCOM_acd0d8();

// STUB: 0x008793ec
cSvc_acd0d8* Fn008793ec();

// STUB: 0x007c1870
bool Fn007c1870();

// STUB: 0x0090cf63
void StlDelete_acd0d8(void* p);

// The service pointer helper (an object holding one reference).
struct cWWWPtr_acd0d8 {
    cRef_acd0d8* mpObj;
    // STUB: 0x008fa948
    cWWWPtr_acd0d8* Construct();
    cWWWPtr_acd0d8* Fn008fa948Draft_acd0d8();
    // STUB: 0x008fa96d
    void Destruct();
    void Fn008fa96dDraft_acd0d8();
};

// A reference held on the window for the length of a handler.
struct cAuto_acd0d8 {
    cRef_acd0d8* mp;
    // STUB: 0x0096e773
    cAuto_acd0d8(void* target);
    ~cAuto_acd0d8()
    {
        if (mp) {
            mp->Release();
        }
    }
};

// The lock taken for the length of a handler.
struct cLock_acd0d8 {
    void* mpVtable;
    cRef_acd0d8* mpMutex;
    // STUB: 0x0048c9f0
    cLock_acd0d8(void* target);
    ~cLock_acd0d8()
    {
        mpMutex->Release();
    }
};

// A URL, seen through the slots used.
struct cRZURL_acd0d8 {
    char mData[0xc0];
    // STUB: 0x008216c0
    const cRZString* GetFullURL() const;
    // STUB: 0x00821c60
    cRZURL_acd0d8(const cRZString* source);
    // STUB: 0x008128a0
    ~cRZURL_acd0d8();
};

// The draw context at +0xe0.
struct cDrawCtx_acd0d8 {
    int32_t m[0x13];
    // STUB: 0x008fde62
    void InitForFreshPainting();
    void Fn008fde62Draft_acd0d8();
};

// The window's own vtable, for slots called with a different argument list.
struct cWinSelf_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual cWM_acd0d8* GetWM();
};

#ifdef OB_DRAFTS
// CLOSE: 0x008fa948 score 0 (logic follows the asm)
cWWWPtr_acd0d8* cWWWPtr_acd0d8::Fn008fa948Draft_acd0d8()
{
    mpObj = 0;
    cSvc_acd0d8* svc = Fn008793ec();
    if (svc) {
        svc->GetService(0x449b1939, 0x449b1912, reinterpret_cast<void**>(&mpObj));
    }
    return this;
}

// CLOSE: 0x008fa96d score 21 (logic follows the asm)
void cWWWPtr_acd0d8::Fn008fa96dDraft_acd0d8()
{
    if (mpObj) {
        mpObj->Release();
    }
}

// CLOSE: 0x008fde62 score 0 (logic follows the asm)
void cDrawCtx_acd0d8::Fn008fde62Draft_acd0d8()
{
    m[0xb] = 0;
    m[0xc] = 0;
    m[0xd] = m[3];
    m[0xe] = m[4] - m[8];
    m[0x10] = m[3] - m[7];
    m[0x11] = m[0x10];
    m[0x12] = m[5] - m[7];
}

#endif

// FUNCTION: 0x008fa329
bool cGZWinHTML::Slot04_ae1d24()
{
    if (get_init_flag()) {
        Slot24_accfb8();
        reinterpret_cast<cTimer_acd0d8*>(reinterpret_cast<char*>(this) + 0x1dc)->Stop();
        if (mp1d8) {
            static_cast<cRef_acd0d8*>(mp1d8)->Release();
            mp1d8 = 0;
        }
        if (mpWWW) {
            static_cast<cRef_acd0d8*>(mpWWW)->Release();
            mpWWW = 0;
        }
        if (mpFont164) {
            static_cast<cRef_acd0d8*>(mpFont164)->Release();
            mpFont164 = 0;
        }
        if (mpFont168) {
            static_cast<cRef_acd0d8*>(mpFont168)->Release();
            mpFont168 = 0;
        }
        if (mpDocument) {
            static_cast<cRef_acd0d8*>(mpDocument)->Release();
            mpDocument = 0;
        }
        if (mpVScroll) {
            static_cast<cRef_acd0d8*>(mpVScroll)->Release();
            mpVScroll = 0;
        }
        if (mpHScroll) {
            static_cast<cRef_acd0d8*>(mpHScroll)->Release();
            mpHScroll = 0;
        }
        if (mpVScrollImage) {
            static_cast<cRef_acd0d8*>(mpVScrollImage)->Release();
            mpVScrollImage = 0;
        }
        if (mpHScrollImage) {
            static_cast<cRef_acd0d8*>(mpHScrollImage)->Release();
            mpHScrollImage = 0;
        }
        return cGZWin::Slot04_ae1d24();
    }
    return true;
}

#ifdef OB_DRAFTS

// CLOSE: 0x008fac01 score 27 (logic follows the asm)
bool cGZWinHTML::SetHTMLPaintArea()
{
    RectEq_acd0d8 before = *reinterpret_cast<RectEq_acd0d8*>(&mnOffsetX);
    int32_t gx = mnGutter[0];
    RectEq_acd0d8* r = reinterpret_cast<RectEq_acd0d8*>(&mnOffsetX);
    *r = *reinterpret_cast<const RectEq_acd0d8*>(&field24[0]);
    r->v[0] += gx;
    r->v[2] -= mnGutter[2];
    r->v[1] += mnGutter[1];
    r->v[3] -= mnGutter[3];
    mnViewRect[2] = mnViewRect[0] + r->v[2] - r->v[0];
    mnViewRect[3] = mnViewRect[1] - r->v[1] + r->v[3];
    return !before.Equals(r);
}

// CLOSE: 0x008fac82 score 8 (logic follows the asm)
void cGZWinHTML::Slot07_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Size_acd0d8 before;
    before.w = HTML_I32(this, 0xb0) - HTML_I32(this, 0xa8);
    before.h = HTML_I32(this, 0xb4) - HTML_I32(this, 0xac);
    cGZWin::Slot07_add348(a, b, c, d);
    SetHTMLPaintArea();
    Size_acd0d8 after;
    after.w = HTML_I32(this, 0xb0) - HTML_I32(this, 0xa8);
    after.h = HTML_I32(this, 0xb4) - HTML_I32(this, 0xac);
    if (before.Equals(&after)) {
        if (field48) {
            OB_PTR(cGZWin, field48)->InvalidateSelfAndParents();
        }
    } else {
        Fn008fa559();
    }
}

#endif

// FUNCTION: 0x008faaa8
bool cGZWinHTML::GZOnMouseDownL(uint32_t a, uint32_t b, uint32_t /*c*/)
{
    cAuto_acd0d8 self(this);
    cLock_acd0d8 lock(&HTML_PTR(this, 0x14c));
    cEl2_acd0d8* elem;
    if (PickElement(OB_ADDR(&elem), a, b)) {
        elem->OnMouseDown(&mpOwner);
    }
    return true;
}

#ifdef OB_DRAFTS

#endif

// FUNCTION: 0x008fab08
bool cGZWinHTML::GZOnMouseUpL(uint32_t a, uint32_t b, uint32_t /*c*/)
{
    cAuto_acd0d8 self(this);
    cLock_acd0d8 lock(&HTML_PTR(this, 0x14c));
    cEl2_acd0d8* elem;
    if (PickElement(OB_ADDR(&elem), a, b)) {
        elem->OnMouseUp(&mpOwner);
        if (HTML_I32(elem, 4) == 4) {
            uint32_t target = HTML_I32(elem, 0x2c);
            if (target == 0) {
                target = HTML_I32(elem, 0x28);
            }
            if (target != 0) {
                Slot25_accfb8(target);
            }
        }
    }
    return true;
}

#ifdef OB_DRAFTS

// CLOSE: 0x008fab8b score 23 (logic follows the asm)
bool cGZWinHTML::GZOnMouseMove(uint32_t a, uint32_t b, uint32_t c)
{
    cLock_acd0d8 lock(&HTML_PTR(this, 0x14c));
    if (mnFlags & 0x20) {
        cEl2_acd0d8* elem;
        if (PickElement(OB_ADDR(&elem), a, b) && HTML_I32(elem, 4) == 4 && (HTML_I32(elem, 0x28) != 0 || HTML_I32(elem, 0x2c) != 0)) {
            SetCursor(OB_ADDR(mpFont164), 1);
        } else {
            SetCursor(OB_ADDR(mpFont168), 1);
        }
    }
    return true;
}

// CLOSE: 0x008fad0e score 98 (logic follows the asm)
void cGZWinHTML::Slot07_accfb8(uint32_t a, uint32_t b)
{
    int32_t x = a;
    int32_t y = b;
    int32_t tmp[2];
    int32_t curX;
    int32_t curY;
    Slot10_accfb8(OB_ADDR(tmp));
    Slot06_accfb8(OB_ADDR(&curX), OB_ADDR(&curY));
    int32_t w = mnViewRect[2] - mnViewRect[0];
    int32_t h = mnViewRect[3] - mnViewRect[1];
    cEl2_acd0d8* root = static_cast<cEl2_acd0d8*>(static_cast<cDoc_acd0d8*>(mpDocument)->GetRoot());
    int32_t maxX = HTML_I32(root, 0x14) - w;
    int32_t zero = 0;
    x = std::max(std::min(x, maxX), zero);
    int32_t maxY = HTML_I32(root, 0x18) - h;
    y = std::max(std::min(y, maxY), zero);
    if (curX != x || curY != y) {
        mnViewRect[0] = x;
        mnViewRect[1] = y;
        mnViewRect[2] = x + w;
        mnViewRect[3] = y + h;
        if (mpHScroll) {
            static_cast<cScroll_acd0d8*>(mpHScroll)->SetPosition(x);
        }
        if (mpVScroll) {
            static_cast<cScroll_acd0d8*>(mpVScroll)->SetPosition(y);
        }
        InvalidateSelfAndParents();
    }
}

#endif

// FUNCTION: 0x008fade4
bool cGZWinHTML::Slot09_accfb8(uint32_t a)
{
    cEl2_acd0d8* e = static_cast<cEl2_acd0d8*>(static_cast<cDoc_acd0d8*>(mpDocument)->FindAnchor(a));
    if (e && reinterpret_cast<uint8_t*>(e)[9]) {
        int32_t dx = HTML_I32(this, 0xb4) - HTML_I32(this, 0x190) - HTML_I32(this, 0x188) - HTML_I32(this, 0xac);
        int32_t dy = HTML_I32(this, 0xb0) - HTML_I32(this, 0x18c) - HTML_I32(this, 0x184) - HTML_I32(this, 0xa8);
        int32_t curX;
        int32_t curY;
        Slot06_accfb8(OB_ADDR(&curX), OB_ADDR(&curY));
        if (HTML_I32(e, 0x14) > curX + dy) {
            curX += HTML_I32(e, 0xc) - HTML_I32(e, 0x14) + dy;
        }
        if (HTML_I32(e, 0xc) < curX) {
            curX = HTML_I32(e, 0xc);
        }
        if (HTML_I32(e, 0x18) > curY + dx) {
            curY += HTML_I32(e, 0x10) - HTML_I32(e, 0x18) + dx;
        }
        if (HTML_I32(e, 0x10) < curY) {
            curY = HTML_I32(e, 0x10);
        }
        Slot07_accfb8(curX, curY);
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS

// CLOSE: 0x008faea0 score 44 (logic follows the asm)
bool cGZWinHTML::Slot11_accfb8(uint32_t a, uint32_t b)
{
    cImg_acd0d8* img = OB_PTR(cImg_acd0d8, a);
    if (img) {
        img->AddRef();
    }
    if (mpVScrollImage) {
        static_cast<cRef_acd0d8*>(mpVScrollImage)->Release();
    }
    mpVScrollImage = img;
    *reinterpret_cast<RectEq_acd0d8*>(mnVScrollRect) = *OB_PTR(RectEq_acd0d8, b);
    int32_t* rect = mnVScrollRect;
    if (img && mpVScroll) {
        cScrollImg_acd0d8* sb = static_cast<cScrollImg_acd0d8*>(mpVScroll);
        if (Fn007c1870()) {
            sb->SetImage(img->GetRegion(), img, 0);
        } else {
            sb->SetImage(rect, img, 0);
        }
    }
    return true;
}

// CLOSE: 0x008faf21 score 44 (logic follows the asm)
bool cGZWinHTML::Slot12_accfb8(uint32_t a, uint32_t b)
{
    cImg_acd0d8* img = OB_PTR(cImg_acd0d8, a);
    if (img) {
        img->AddRef();
    }
    if (mpHScrollImage) {
        static_cast<cRef_acd0d8*>(mpHScrollImage)->Release();
    }
    mpHScrollImage = img;
    *reinterpret_cast<RectEq_acd0d8*>(mnHScrollRect) = *OB_PTR(RectEq_acd0d8, b);
    int32_t* rect = mnHScrollRect;
    if (img && mpHScroll) {
        cScrollImg_acd0d8* sb = static_cast<cScrollImg_acd0d8*>(mpHScroll);
        if (Fn007c1870()) {
            sb->SetImage(img->GetRegion(), img, 0);
        } else {
            sb->SetImage(rect, img, 0);
        }
    }
    return true;
}

// CLOSE: 0x008fb31a score 29 (logic follows the asm)
bool cGZWinHTML::TestForPossibleScrollBarAdditionOrRemoval()
{
    if (mpDocument && static_cast<cDoc_acd0d8*>(mpDocument)->GetRoot()) {
        bool addV = false;
        bool addH = false;
        bool remV = false;
        bool remH = false;
        cEl2_acd0d8* root = static_cast<cEl2_acd0d8*>(static_cast<cDoc_acd0d8*>(mpDocument)->GetRoot());
        if (mnFlags & 8) {
            if (HTML_I32(root, 0x18) > mnViewRect[3] - mnViewRect[1]) {
                if (!mpVScroll) {
                    addV = true;
                }
            } else if (mpVScroll) {
                remV = true;
            }
        }
        if (mnFlags & 4) {
            if (HTML_I32(root, 0x14) > mnViewRect[2] - mnViewRect[0]) {
                if (!mpHScroll) {
                    addH = true;
                }
            } else if (mpHScroll) {
                remH = true;
            }
        }
        if (remV || remH) {
            RemoveScrollBar(remV, remH);
        }
        if (addV || addH) {
            AddScrollBar(addV, addH);
        }
    }
    return true;
}

// CLOSE: 0x008fb5e5 score 49 (logic follows the asm)
void cGZWinHTML::Slot10_accfb8(uint32_t a)
{
    cDoc_acd0d8* doc = static_cast<cDoc_acd0d8*>(mpDocument);
    cEl2_acd0d8* root = static_cast<cEl2_acd0d8*>(doc->GetRoot());
    Size_acd0d8* out = OB_PTR(Size_acd0d8, a);
    if (root) {
        if (!doc->IsLayoutDone()) {
            cDrawCtx_acd0d8* ctx = reinterpret_cast<cDrawCtx_acd0d8*>(&mpOwner);
            ctx->InitForFreshPainting();
            root->Layout(ctx);
            root->Finish();
            doc->SetLayoutDone(1);
            TestForPossibleScrollBarAdditionOrRemoval();
        }
        out->w = HTML_I32(root, 0x14);
        out->h = HTML_I32(root, 0x18);
    } else {
        out->h = 0;
        out->w = 0;
    }
}

// CLOSE: 0x008fb771 score 25 (logic follows the asm)
bool cGZWinHTML::Slot25_accfb8(uint32_t a)
{
    cRZString* str = new cRZString(*OB_PTR(cIGZString, a));
    Msg_acd0d8 m;
    m.id = 0xe4a85d91;
    m.sender = static_cast<cGZWin*>(this);
    m.a = OB_ADDR(str);
    bool r = SendMsg_2(field4c, OB_ADDR(&m));
    if (r && (mnFlags & 0x20)) {
        Slot18_accfb8(OB_ADDR(str), 0);
    }
    if (str) {
        str->Release();
    }
    return r;
}

// CLOSE: 0x008fbbb9 score 7 (logic follows the asm)
bool cGZWinHTML::Slot19_accfb8(uint32_t a)
{
    cRZURL_acd0d8 local(OB_PTR(const cRZString, a));
    (void)local;
    return true;
}

#endif

// FUNCTION: 0x008fbbf7
bool cGZWinHTML::Slot18_accfb8(uint32_t a, uint32_t b)
{
    cRZURL_acd0d8 local(OB_PTR(const cRZString, a));
    bool r = Slot17_accfb8(OB_ADDR(&local), b);
    return r;
}

#ifdef OB_DRAFTS

#endif

// FUNCTION: 0x008fc0c5
bool cGZWinHTML::Slot21_accfb8(uint32_t a)
{
    cData_acd0d8* d = static_cast<cData_acd0d8*>(static_cast<cDoc_acd0d8*>(mpDocument)->GetData());
    uint32_t n = d->GetLength();
    const char* p = d->GetText();
    OB_PTR(std::string, a)->assign(p, p + n);
    return true;
}

#ifdef OB_DRAFTS

// CLOSE: 0x008fc327 score 10 (logic follows the asm)
bool cGZWinHTML::Slot15_accfb8(uint32_t a)
{
    cRZString* out = OB_PTR(cRZString, a);
    *out = *reinterpret_cast<cRZURL_acd0d8*>(reinterpret_cast<char*>(this) + 0x2e0)->GetFullURL();
    return out->size() != 0;
}

// CLOSE: 0x008fc350 score 10 (logic follows the asm)
bool cGZWinHTML::Slot16_accfb8(uint32_t a)
{
    cRZString* out = OB_PTR(cRZString, a);
    *out = *reinterpret_cast<cRZURL_acd0d8*>(reinterpret_cast<char*>(this) + 0x3a0)->GetFullURL();
    return out->size() != 0;
}

#endif

// FUNCTION: 0x008fc2bd
bool cGZWinHTML::Slot20_accfb8(uint32_t a)
{
    cRZString url;
    url = *reinterpret_cast<cRZURL_acd0d8*>(reinterpret_cast<char*>(this) + 0x2e0)->GetFullURL();
    static_cast<std::string&>(url) = *OB_PTR(const cRZString, a);
    bool r = Slot18_accfb8(OB_ADDR(&url), 0);
    return r;
}

#ifdef OB_DRAFTS

// CLOSE: 0x008fc0f6 score 61 (logic follows the asm)
bool cGZWinHTML::Slot03_ae1d24()
{
    if (get_init_flag()) {
        return true;
    }
    bool result = cGZWin::Slot03_ae1d24();
    cRes_acd0d8* res = reinterpret_cast<cWinSelf_acd0d8*>(this)->GetWM()->GetResources();
    cRef_acd0d8* font = res->Get(0x12);
    mpFont164 = font;
    if (!font) {
        mpFont164 = res->Get(0x11);
    }
    if (!mpFont164) {
        mpFont164 = res->Get(1);
    }
    if (mpFont164) {
        static_cast<cRef_acd0d8*>(mpFont164)->AddRef();
    }
    cRef_acd0d8* other = res->Get(1);
    mpFont168 = other;
    if (other) {
        other->AddRef();
    }
    mMissingImage = cRZString("Missing.jpg");
    if (!mp1d8) {
        GZCOM_acd0d8()->GetClass(0xa2ffb5d3, 0x2ffbb60, &mp1d8);
    }
    cRZString title("HTML Window");
    Slot49_adda20(OB_ADDR(&title));
    if (!mpWWW) {
        cWWWPtr_acd0d8 tmp;
        mpWWW = tmp.Construct()->mpObj;
        tmp.Destruct();
        if (mpWWW) {
            static_cast<cRef_acd0d8*>(mpWWW)->AddRef();
        } else {
            GZCOM_acd0d8()->GetClass(0x849b190a, 0x449b1912, &mpWWW);
        }
    }
    mpOwner = this;
    mnE8 = field68;
    SetHTMLPaintArea();
    cRZURL_acd0d8* url = reinterpret_cast<cRZURL_acd0d8*>(reinterpret_cast<char*>(this) + 0x2e0);
    if (url->GetFullURL()->size() != 0 && Slot17_accfb8(OB_ADDR(url), 0)) {
        int32_t x = mnOffsetX;
        int32_t y = mnOffsetY;
        *reinterpret_cast<RectEq_acd0d8*>(mnViewRect) = *reinterpret_cast<const RectEq_acd0d8*>(&mnOffsetX);
        mnViewRect[0] -= x;
        mnViewRect[2] -= x;
        mnViewRect[1] -= y;
        mnViewRect[3] -= y;
    }
    return result;
}
#endif

// The message handed to the loader callback, seen through the slots used.
struct cMsg_acd0d8 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual uint32_t GetType();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void Slot10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual uint32_t Slot14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void* GetData();
};

#ifdef OB_DRAFTS
// CLOSE: 0x008fbfe5 score 50 (logic follows the asm)
bool cGZWinHTML::Slot03_aaaa9c(void* message)
{
    cMsg_acd0d8* msg = static_cast<cMsg_acd0d8*>(message);
    if (msg->GetType() != 0x75758483) {
        return false;
    }
    bool ok = msg->Slot14() != 0;
    msg->Slot10();
    void* data = msg->GetData();
    uint32_t state;
    if (ok) {
        if (mnLoadState != 1) {
            return ok;
        }
        const std::string* text = reinterpret_cast<const std::string*>(reinterpret_cast<char*>(data) + 0x30);
        if (text->size() != 0) {
            const cRZString* url = reinterpret_cast<cRZURL_acd0d8*>(reinterpret_cast<char*>(this) + 0x3a0)->GetFullURL();
            if (!InternalSetDocument(OB_ADDR(text), OB_ADDR(url))) {
                return ok;
            }
        }
        mnLoadState = 2;
        state = 2;
    } else {
        if (mnLoadState != 1) {
            return ok;
        }
        state = mpDocument ? 2 : 0;
        mnLoadState = state;
    }
    Msg_acd0d8 m;
    m.id = 0xe4a85d8f;
    m.sender = static_cast<cGZWin*>(this);
    m.a = state;
    m.b = 1;
    SendMsg_2(field4c, OB_ADDR(&m));
    InvalidateSelf();
    return ok;
}
#endif
