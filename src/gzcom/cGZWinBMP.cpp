#include "gzcom/cIGZUnknown.h"
#include "classes/cGZWinBMP.h"

namespace {
// A 16-byte record copied as a whole.
struct Quad_adf6a0 {
    int32_t v[4];
};
}

// The child object seen through the interface the original calls it by (arguments as plain words).
struct cChild_adf6a0 {
    virtual bool Slot00(uint32_t a, uint32_t b);
    virtual uint32_t Slot01();
    virtual uint32_t Slot02();
    virtual uint32_t Slot03();
    virtual uint32_t Slot04();
    virtual uint32_t Slot05();
    virtual uint32_t Slot06();
    virtual uint32_t Slot07();
    virtual uint32_t Slot08();
    virtual int32_t GetWidth();
    virtual int32_t GetHeight();
    virtual uint32_t Slot11();
    virtual const int32_t* GetRect();
};

// FUNCTION: 0x0095ba6f
void* cGZWinBMP::Slot03_adf63c()
{
    return this;
}

// FUNCTION: 0x009bc06a
bool cGZWinBMP::QueryInterface(unsigned int iid, void** ppv)
{
    switch (iid) {
    case 0xc12cea13:
        *ppv = static_cast<cUnk00adf63c*>(this);
        AddRef();
        return true;
    default:
        return cGZWin::QueryInterface(iid, ppv);
    }
}

// FUNCTION: 0x009bc097
bool cGZWinBMP::Slot04_ae1d24()
{
    if (mpChild) {
        mpChild->Release();
        mpChild = 0;
    }
    return cGZWin::Slot04_ae1d24();
}

// FUNCTION: 0x009bc0bd
bool cGZWinBMP::Slot05_adf63c(uint32_t a, uint32_t b)
{
    if (mpChild) {
        return reinterpret_cast<cChild_adf6a0*>(mpChild)->Slot00(a, b);
    }
    return false;
}

// FUNCTION: 0x009bc0cf
void cGZWinBMP::Slot06_adf63c(uint32_t a, uint32_t b)
{
    mbValueA = static_cast<uint8_t>(a);
    mnValueB = b;
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009bc0ee
void cGZWinBMP::Slot07_adf63c(uint32_t a, uint32_t b)
{
    *reinterpret_cast<uint8_t*>(a) = mbValueA;
    *reinterpret_cast<float*>(b) = *reinterpret_cast<float*>(&mnValueB);
}

// FUNCTION: 0x009bc103
void cGZWinBMP::Slot08_adf63c(uint32_t a)
{
    *reinterpret_cast<Quad_adf6a0*>(mnRect) = *reinterpret_cast<Quad_adf6a0*>(a);
    if (mpChild) {
        if (mnRect[0] < 0) {
            mnRect[0] = 0;
        }
        if (mnRect[1] < 0) {
            mnRect[1] = 0;
        }
        if (mnRect[2] > reinterpret_cast<cChild_adf6a0*>(mpChild)->GetWidth()) {
            mnRect[2] = reinterpret_cast<cChild_adf6a0*>(mpChild)->GetWidth();
        }
        if (mnRect[3] > reinterpret_cast<cChild_adf6a0*>(mpChild)->GetHeight()) {
            mnRect[3] = reinterpret_cast<cChild_adf6a0*>(mpChild)->GetHeight();
        }
    }
}

// FUNCTION: 0x009bc15f
void cGZWinBMP::Slot09_adf63c(uint32_t a)
{
    *reinterpret_cast<Quad_adf6a0*>(a) = *reinterpret_cast<Quad_adf6a0*>(mnRect);
}

// FUNCTION: 0x009bc171
bool cGZWinBMP::Slot10_adf63c(uint32_t a)
{
    return (mnFlags & a) != 0;
}

// FUNCTION: 0x009bc181
void cGZWinBMP::Slot11_adf63c(uint32_t a, uint32_t b)
{
    if (static_cast<uint8_t>(b)) {
        mnFlags |= a;
    } else {
        mnFlags &= ~a;
    }
}

// FUNCTION: 0x009bc52d
bool cGZWinBMP::Slot03_ae1d24()
{
    if (Fn0099bc31()) {
        return true;
    }
    uint32_t h = GetH();
    uint32_t r[4];
    r[0] = 0;
    r[1] = 0;
    r[2] = GetW();
    r[3] = h;
    Fn009bc447(r);
    return cGZWin::Slot03_ae1d24();
}

// FUNCTION: 0x009bc57e
void cGZWinBMP::Slot04_adf63c(uint32_t a)
{
    cIGZUnknown* p = reinterpret_cast<cIGZUnknown*>(a);
    if (p != mpChild) {
        if (p) {
            p->AddRef();
        }
        if (mpChild) {
            mpChild->Release();
        }
        mpChild = p;
        Fn009bc447(GetArea_2());
        InvalidateSelfAndParents();
    }
}

// The object field48 holds, seen through the one slot the original calls it by.
struct cTarget_adf6a0 {
    virtual uint32_t Slot00();
    virtual uint32_t Slot01();
    virtual uint32_t Slot02();
    virtual bool Slot03(uint32_t* e);
};

// FUNCTION: 0x009bc199
bool cGZWinBMP::DoMessage(uint32_t a)
{
    uint32_t* e = reinterpret_cast<uint32_t*>(a);
    uint32_t t = e[0];
    if (t == 5 || t == 6) {
        return cGZWin::DoMessage(a);
    }
    if (t == 7 || t == 13 || t == 10) {
        cGZWin::DoMessage(a);
    }
    if (static_cast<uint8_t>(Slot10_adf63c(1)) && field48) {
        if (e[0] >= 7 && e[0] <= 14) {
            e[1] += GetL();
            e[2] += GetT();
        }
        return reinterpret_cast<cTarget_adf6a0*>(field48)->Slot03(e);
    }
    return false;
}

// FUNCTION: 0x009bc251
bool cGZWinBMP::IsPointInWindowScreenCoordinates(uint32_t a, uint32_t b)
{
    if (static_cast<uint8_t>(Slot10_adf63c(4))) {
        return false;
    }
    return cGZWin::IsPointInWindowScreenCoordinates(a, b);
}

// The base's vtable up to its slot 144, whose result the original returns (the base declares it void).
#define OB_V4_ADF6A0(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3();
#define OB_V16_ADF6A0(p) OB_V4_ADF6A0(p##a) OB_V4_ADF6A0(p##b) OB_V4_ADF6A0(p##c) OB_V4_ADF6A0(p##d)
#define OB_V64_ADF6A0(p) OB_V16_ADF6A0(p##a) OB_V16_ADF6A0(p##b) OB_V16_ADF6A0(p##c) OB_V16_ADF6A0(p##d)
struct cBaseView_adf6a0 {
    OB_V64_ADF6A0(sa)
    OB_V64_ADF6A0(sb)
    OB_V16_ADF6A0(sc)
    virtual bool Slot144(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
};

// FUNCTION: 0x009bc21d
bool cGZWinBMP::GZOnKeyDown(uint32_t a, uint32_t b)
{
    return reinterpret_cast<cBaseView_adf6a0*>(this)->Slot144(field4c, 5, a, b, 0);
}

// FUNCTION: 0x009bc237
bool cGZWinBMP::GZOnKeyUp(uint32_t a, uint32_t b)
{
    return reinterpret_cast<cBaseView_adf6a0*>(this)->Slot144(field4c, 6, a, b, 0);
}

// FUNCTION: 0x009bc27c
bool cGZWinBMP::GZOnMouseMove(uint32_t a, uint32_t b, uint32_t)
{
    return reinterpret_cast<cBaseView_adf6a0*>(this)->Slot144(field4c, 0xc89155e3, a, b, Slot48_adda20());
}

// FUNCTION: 0x009bc2a6
bool cGZWinBMP::GZOnMouseDownL(uint32_t a, uint32_t b, uint32_t)
{
    return reinterpret_cast<cBaseView_adf6a0*>(this)->Slot144(field4c, 0x68915615, a, b, Slot48_adda20());
}

// FUNCTION: 0x009bc2d0
bool cGZWinBMP::GZOnMouseUpL(uint32_t a, uint32_t b, uint32_t)
{
    return reinterpret_cast<cBaseView_adf6a0*>(this)->Slot144(field4c, 0x28916985, a, b, Slot48_adda20());
}

// The renderer field6c holds, seen through the slots the original calls it by.
struct cRenderer_adf6a0 {
    virtual uint32_t Slot00();
    virtual uint32_t Slot01();
    virtual uint32_t Slot02();
    virtual uint32_t Slot03();
    virtual uint32_t Slot04();
    virtual uint32_t Slot05();
    virtual uint32_t Slot06();
    virtual uint32_t Slot07();
    virtual uint32_t Slot08();
    virtual uint32_t Slot09();
    virtual uint32_t Slot10();
    virtual uint32_t Slot11();
    virtual uint32_t Slot12();
    virtual uint32_t Slot13();
    virtual uint32_t Slot14();
    virtual uint32_t Slot15();
    virtual uint32_t Slot16();
    virtual uint32_t Slot17();
    virtual uint32_t Slot18();
    virtual uint32_t Slot19();
    virtual uint32_t Slot20();
    virtual void SetValue(uint32_t v);
    virtual uint32_t Slot22();
    virtual uint32_t Slot23();
    virtual uint32_t Slot24();
    virtual uint32_t Slot25();
    virtual uint32_t Slot26();
    virtual uint32_t Slot27();
    virtual uint32_t Slot28();
    virtual uint32_t Slot29();
    virtual uint32_t Slot30();
    virtual uint32_t Slot31();
    virtual uint32_t Slot32();
    virtual uint32_t Slot33();
    virtual uint32_t Slot34();
    virtual void SetRect(const int32_t* r);
    virtual uint32_t Slot36();
    virtual uint32_t Slot37();
    virtual void DrawRects(cIGZUnknown* c, const int32_t* src, const int32_t* dst);
};

// STUB: 0x008d8800
void Fn008d8800(cRenderer_adf6a0* r, cIGZUnknown* c, const int32_t* src, const int32_t* dst, uint32_t v);

inline cRenderer_adf6a0*& Rd_adf6a0(uint32_t& f)
{
    return *reinterpret_cast<cRenderer_adf6a0**>(&f);
}

inline int32_t* Pos_adf6a0(char* f)
{
    return reinterpret_cast<int32_t*>(f);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bc325 score 64 (stack slots of the two rects swapped, the copy source is held in eax first)
bool cGZWinBMP::GZPaint()
{
    if (!(mnFlags & 2)) {
        reinterpret_cast<cRenderer_adf6a0*>(field6c)->SetValue(GetFillColorRGB());
        reinterpret_cast<cRenderer_adf6a0*>(field6c)->SetRect(Pos_adf6a0(field24));
    }
    if (mpChild) {
        const Quad_adf6a0* src;
        if (!static_cast<uint8_t>(Slot10_adf63c(0x10)) && !static_cast<uint8_t>(Slot10_adf63c(0x20))) {
            src = reinterpret_cast<const Quad_adf6a0*>(reinterpret_cast<cChild_adf6a0*>(mpChild)->GetRect());
        } else {
            src = reinterpret_cast<const Quad_adf6a0*>(mnRect);
        }
        Quad_adf6a0 d;
        Quad_adf6a0 r = *src;
        if (!static_cast<uint8_t>(Slot10_adf63c(8))) {
            int32_t x = Pos_adf6a0(field24)[0];
            int32_t y = Pos_adf6a0(field24)[1];
            d.v[0] = x;
            d.v[1] = y;
            d.v[2] = x - r.v[0] + r.v[2];
            d.v[3] = y - r.v[1] + r.v[3];
            if (static_cast<uint8_t>(Slot10_adf63c(0x20))) {
                d.v[0] += r.v[0];
                d.v[2] += r.v[0];
                d.v[1] += r.v[1];
                d.v[3] += r.v[1];
            }
            Rd_adf6a0(field6c)->DrawRects(mpChild, r.v, d.v);
        } else {
            r.v[2] = r.v[2] / 3;
            r.v[3] = r.v[3] / 3;
            Fn008d8800(Rd_adf6a0(field6c), mpChild, r.v, Pos_adf6a0(field24), 1);
        }
    }
    return true;
}
#endif
