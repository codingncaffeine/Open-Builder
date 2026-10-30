#include <algorithm>
#include "classes/cGZWinSlider.h"

// A 16-byte record copied as a whole.
struct Rect_ae04d8 {
    int32_t v[4];
};

// The child object seen through the interface the original calls it by.
struct cChild_ae04d8 {
    virtual bool Slot00(uint32_t a, void** b);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void GetRect(int32_t* rect);
};

static inline int32_t Width_ae04d8(const int32_t* r)
{
    return r[2] - r[0];
}

// This object seen through slots whose declared signature (in another class's header) differs from the call.
struct cSelf_ae04d8 {
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
    virtual void D32();
    virtual void D33();
    virtual void D34();
    virtual void D35();
    virtual void D36();
    virtual void D37();
    virtual void D38();
    virtual void D39();
    virtual void D40();
    virtual void D41();
    virtual void D42();
    virtual void D43();
    virtual void D44();
    virtual void D45();
    virtual void D46();
    virtual void D47();
    virtual void D48();
    virtual void D49();
    virtual void D50();
    virtual void D51();
    virtual void D52();
    virtual void D53();
    virtual void D54();
    virtual void D55();
    virtual void D56();
    virtual void D57();
    virtual void D58();
    virtual void D59();
    virtual void D60();
    virtual void D61();
    virtual void D62();
    virtual uint32_t Slot63(uint32_t a);
    virtual void D64();
    virtual void D65();
    virtual void D66();
    virtual void D67();
    virtual void D68();
    virtual void D69();
    virtual void D70();
    virtual void D71();
    virtual void D72();
    virtual void D73();
    virtual void D74();
    virtual void D75();
    virtual void D76();
    virtual void D77();
    virtual void D78();
    virtual void D79();
    virtual void D80();
    virtual void D81();
    virtual void D82();
    virtual void D83();
    virtual void D84();
    virtual void D85();
    virtual void D86();
    virtual void D87();
    virtual void D88();
    virtual void D89();
    virtual void D90();
    virtual void D91();
    virtual void D92();
    virtual void D93();
    virtual void D94();
    virtual void D95();
    virtual void D96();
    virtual void D97();
    virtual void D98();
    virtual void D99();
    virtual void D100();
    virtual void D101();
    virtual void D102();
    virtual void D103();
    virtual void D104();
    virtual void D105();
    virtual void D106();
    virtual void D107();
    virtual void D108();
    virtual void D109();
    virtual void D110();
    virtual void D111();
    virtual void D112();
    virtual void D113();
    virtual void D114();
    virtual void D115();
    virtual void D116();
    virtual void D117();
    virtual void D118();
    virtual void D119();
    virtual void D120();
    virtual void D121();
    virtual void D122();
    virtual void D123();
    virtual void D124();
    virtual void D125();
    virtual void D126();
    virtual void D127();
    virtual void D128();
    virtual void D129();
    virtual void D130();
    virtual void D131();
    virtual void D132();
    virtual void D133();
    virtual void D134();
    virtual void D135();
    virtual void D136();
    virtual void D137();
    virtual void D138();
    virtual void D139();
    virtual void D140();
    virtual void D141();
    virtual void D142();
    virtual void D143();
    virtual void Slot144(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
};

// FUNCTION: 0x009c2e0e
bool cGZWinSlider::QueryInterface(unsigned int iid, void** ppv)
{
    switch (iid) {
    case 0x21325207:
        *ppv = static_cast<cUnk00ae074c*>(this);
        AddRef();
        return true;
    default:
        return cGZWin::QueryInterface(iid, ppv);
    }
}

// FUNCTION: 0x009c2e3b
void cGZWinSlider::Slot11_ae074c(uint32_t a)
{
    *reinterpret_cast<uint32_t*>(a) = mnMode;
}

// FUNCTION: 0x009c2e47
bool cGZWinSlider::Slot03_ae1d24()
{
    if (!Fn0099bc31()) {
        Slot153_ae04d8();
    }
    return cGZWin::Slot03_ae1d24();
}

// FUNCTION: 0x009c2e65
bool cGZWinSlider::Slot04_ae1d24()
{
    cChild_ae04d8** pp = reinterpret_cast<cChild_ae04d8**>(&mpChild);
    if (*pp) {
        (*pp)->Release();
        *pp = 0;
    }
    return cGZWin::Slot04_ae1d24();
}

// FUNCTION: 0x009c2e86
bool cGZWinSlider::GZOnMouseDownL(uint32_t a, uint32_t b, uint32_t)
{
    if (Fn0099bdfe()) {
        float v;
        if (ConvertCursorPositionToPercentage(&v, a, b)) {
            SetPercentage(v);
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x009c2ec9
bool cGZWinSlider::GZOnMouseUpL(uint32_t a, uint32_t b, uint32_t)
{
    if (Fn0099be0a()) {
        Fn0099be1e();
        float f;
        if (ConvertCursorPositionToPercentage(&f, a, b)) {
            SetPercentage(f);
            cSelf_ae04d8* v = reinterpret_cast<cSelf_ae04d8*>(this);
            v->Slot144(field4c, 3, 0x887113a4, v->Slot63(0));
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x009c2f35
bool cGZWinSlider::GZOnMouseMove(uint32_t a, uint32_t b, uint32_t)
{
    if (Fn0099be0a()) {
        float v;
        if (ConvertCursorPositionToPercentage(&v, a, b)) {
            SetPercentage(v);
            return true;
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c2f78 score 23 (register roles: original keeps &mnF8 in edi in one branch only, no address CSE in the other)
void cGZWinSlider::Slot153_ae04d8()
{
    if (mnMode == 1) {
        int32_t* p = &mnF8;
        mnEC = *p;
        int32_t n = GetW();
        n -= *p;
        mnF4 = n - GetThumbWidth();
    } else {
        int32_t n = GetH();
        n -= mnF8;
        n -= GetThumbHeight();
        mnEC = n;
        mnF4 = mnF8;
    }
    CalculateThumbPosition();
    InvalidateSelfAndParents();
}
#endif

// FUNCTION: 0x009c2ff9
void cGZWinSlider::CalculateThumbPosition()
{
    if (!(mnMax - mnMin)) {
        mnF0 = mnEC;
    } else {
        int32_t base = mnEC;
        if (mnMode == 1) {
            mnF0 = base + static_cast<int32_t>(static_cast<float>(mnF4 - base) * mfRatio);
        } else {
            mnF0 = base - static_cast<int32_t>(static_cast<float>(base - mnF4) * mfRatio);
        }
    }
    if (mnMode == 1) {
        mnFC = mnF0;
        mn104 = GetThumbWidth() + mnFC;
        int32_t h = static_cast<int32_t>(GetThumbHeight()) / 2;
        mn100 = static_cast<int32_t>(GetH()) / 2 - h;
        mn108 = GetThumbHeight() + mn100;
    } else {
        int32_t h = static_cast<int32_t>(GetThumbWidth()) / 2;
        mnFC = static_cast<int32_t>(GetW()) / 2 - h;
        mn104 = GetThumbWidth() + mnFC;
        mn100 = mnF0;
        mn108 = GetThumbHeight() + mn100;
    }
}

// FUNCTION: 0x009c312d
uint32_t cGZWinSlider::Slot04_ae074c()
{
    int32_t lo = mnMin;
    return lo + static_cast<int32_t>(static_cast<float>(mnMax - lo) * mfRatio + 0.5f);
}

// FUNCTION: 0x009c3153
bool cGZWinSlider::Slot05_ae074c(uint32_t a)
{
    if (mbBusy) {
        return false;
    }
    mbBusy = true;
    if (static_cast<int32_t>(a) == static_cast<int32_t>(Slot04_ae074c())) {
        mbBusy = false;
        return false;
    }
    {
            int32_t v = static_cast<int32_t>(a);
            int32_t hi = mnMax;
            if (v > hi) {
                v = hi;
            }
            int32_t lo = mnMin;
            if (v < lo) {
                v = lo;
            }
            mfRatio = static_cast<float>(v - lo) / (hi - lo);
            CalculateThumbPosition();
            cSelf_ae04d8* s = reinterpret_cast<cSelf_ae04d8*>(this);
            s->Slot144(field4c, 3, 0x887113a3, s->Slot63(0));
            mbBusy = false;
            InvalidateSelfAndParents();
        return true;
    }
}

// FUNCTION: 0x009c31e7
bool cGZWinSlider::SetPercentage(float f)
{
    if (mbBusy) {
        return false;
    }
    mbBusy = true;
    if (f == mfRatio) {
        mbBusy = false;
        return false;
    }
    {
            if (f < 0.0f) {
                f = 0.0f;
            }
            if (f > 1.0f) {
                f = 1.0f;
            }
            mfRatio = f;
            CalculateThumbPosition();
            cSelf_ae04d8* s = reinterpret_cast<cSelf_ae04d8*>(this);
            s->Slot144(field4c, 3, 0x887113a3, s->Slot63(0));
            mbBusy = false;
            InvalidateSelfAndParents();
        return true;
    }
}

// FUNCTION: 0x009c3286
void cGZWinSlider::Slot06_ae074c(uint32_t a)
{
    mnMin = static_cast<int32_t>(a);
    Slot153_ae04d8();
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009c32b0
void cGZWinSlider::Slot08_ae074c(uint32_t a)
{
    mnMax = static_cast<int32_t>(a);
    Slot153_ae04d8();
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009c32d6
bool cGZWinSlider::Slot13_ae074c(uint32_t a, uint32_t b)
{
    *reinterpret_cast<void**>(a) = mpChild;
    *reinterpret_cast<Rect_ae04d8*>(b) = *reinterpret_cast<Rect_ae04d8*>(mnRect);
    return true;
}

// FUNCTION: 0x009c331a
void cGZWinSlider::Slot07_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    if (mpChild) {
        if (mnMode == 2) {
            cGZWin::Slot07_add348(a, b, Width_ae04d8(mnRect) + a, d);
        } else if (mnMode == 1) {
            cGZWin::Slot07_add348(a, b, c, mnRect[3] - mnRect[1] + b);
        }
    } else {
        cGZWin::Slot07_add348(a, b, c, d);
    }
    Slot153_ae04d8();
}

// FUNCTION: 0x009c3623
bool cGZWinSlider::GZPaint()
{
    if (mpChild) {
        Fn009c34a3();
    } else {
        Fn009c3381();
    }
    return true;
}

// FUNCTION: 0x009c363b
bool cGZWinSlider::ConvertCursorPositionToPercentage(void* out, uint32_t b, uint32_t c)
{
    int32_t span = mnF4 - mnEC;
    int32_t pos;
    if (mnMode == 1) {
        pos = static_cast<int32_t>(b) - static_cast<int32_t>(GetThumbWidth()) / 2;
    } else {
        pos = static_cast<int32_t>(c) - static_cast<int32_t>(GetThumbHeight()) / 2;
    }
    int32_t r;
    if (span >= 0) {
        r = std::min(std::max(mnEC, pos), mnF4);
    } else {
        r = std::min(std::max(mnF4, pos), mnEC);
    }
    *static_cast<float*>(out) = static_cast<float>(r - mnEC) / (mnF4 - mnF8 * 2 - mnEC);
    return true;
}

// FUNCTION: 0x009c36e7
bool cGZWinSlider::Slot12_ae074c(uint32_t a, uint32_t b)
{
    bool result = false;
    cChild_ae04d8* p = reinterpret_cast<cChild_ae04d8*>(a);
    if (p) {
        p->AddRef();
    }
    if (mpChild) {
        static_cast<cChild_ae04d8*>(mpChild)->Release();
    }
    mpChild = p;
    Rect_ae04d8 rc;
    if (p) {
        p->GetRect(rc.v);
    } else {
        mnRect[0] = 0;
        mnRect[1] = 0;
        mnRect[2] = 16;
        mnRect[3] = 16;
    }
    if (b) {
        rc = *reinterpret_cast<Rect_ae04d8*>(b);
    }
    switch (mnMode) {
    case 1:
        if (mpChild) {
            int32_t l = rc.v[0];
            mnRect[0] = l;
            int32_t w = (rc.v[2] - l) / 4;
            int32_t t = rc.v[1];
            mnRect[1] = t;
            mnRect[2] = w;
            mnRect[3] = rc.v[3] - t;
        }
        SetSize(mnRect[3] - mnRect[1]);
        result = true;
        break;
    case 2:
        if (mpChild) {
            mnRect[0] = rc.v[0];
            mnRect[1] = rc.v[1];
            mnRect[2] = rc.v[2] - rc.v[0];
            mnRect[3] = (rc.v[3] - rc.v[1]) / 4;
        }
        SetH(mnRect[2] - mnRect[0]);
        result = true;
        break;
    }
    return result;
}

// FUNCTION: 0x009c37da
uint32_t cGZWinSlider::GetThumbWidth()
{
    if (mpChild) {
        return Width_ae04d8(mnRect);
    }
    if (mnMode == 1) {
        return GetH();
    }
    return GetW();
}

// FUNCTION: 0x009c3809
uint32_t cGZWinSlider::GetThumbHeight()
{
    if (mpChild) {
        return mnRect[3] - mnRect[1];
    }
    if (mnMode == 1) {
        return GetH();
    }
    return GetW();
}
