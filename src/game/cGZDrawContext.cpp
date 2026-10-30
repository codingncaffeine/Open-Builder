#include "classes/cGZDrawContext.h"

#include <new>

// A rectangle: left, top, right, bottom.
struct Rect_ac16c8 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;

    Rect_ac16c8& operator=(const Rect_ac16c8& o)
    {
        mnLeft = o.mnLeft;
        mnTop = o.mnTop;
        mnRight = o.mnRight;
        mnBottom = o.mnBottom;
        return *this;
    }

    // STUB: 0x0079dd60
    void Fn0079dd60(const Rect_ac16c8* a, const Rect_ac16c8* b);
};

struct Point_ac16c8 {
    int32_t mnX;
    int32_t mnY;
};

// The drawing engine behind the context (cIGZDrawContextEngine), slots by their offsets.
struct Engine_ac16c8 {
    virtual bool QueryInterface(uint32_t iid, void** out) = 0;
    virtual void AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void SetTarget(void* buffer) = 0;
    virtual void Detach() = 0;
    virtual void SetClipBase(const void* rect) = 0;
    virtual void SetClip(const void* rect) = 0;
    virtual void SetColorTable(int32_t first, int32_t count, const void* colors) = 0;
    virtual void SetAlphaBlend(int32_t mode) = 0;
    virtual void SetModulate(uint32_t on) = 0;
    virtual void SetAntialiasing(bool on) = 0;
    virtual void SetLineThickness(float width) = 0;
    virtual void SetGradient(int32_t a, int32_t b, int32_t c) = 0;
    virtual bool SetBlt(void* buffer, float x, float y, float sx, float sy, void* outRect) = 0;
    virtual void ClearTiling() = 0;
    virtual void SetTiling(const void* rect) = 0;
    virtual void Suspend() = 0;
    virtual void Slot17() = 0;
    virtual void Resume() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual uint32_t Slot21(uint32_t a, const void* pts, uint32_t n) = 0;
};

// The engine seen with its gradient slot taking no arguments.
struct EngineB_ac16c8 {
    virtual void Fn00() = 0;
    virtual void Fn01() = 0;
    virtual void Fn02() = 0;
    virtual void Fn03() = 0;
    virtual void Fn04() = 0;
    virtual void Fn05() = 0;
    virtual void Fn06() = 0;
    virtual void Fn07() = 0;
    virtual void Fn08() = 0;
    virtual void Fn09() = 0;
    virtual void Fn10() = 0;
    virtual void Fn11() = 0;
    virtual void ClearGradient() = 0;
};

// The target buffer, as far as the context calls it.
struct Buffer_ac16c8 {
    virtual bool QueryInterface(uint32_t iid, void** out) = 0;
    virtual void AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual const Rect_ac16c8* GetArea() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual uint32_t ConvertRGB(uint32_t r, uint32_t g, uint32_t b) = 0;
};

// Re-applies the clip after the blit source changed: the clip, cut by the blit rectangle unless it tiles.
inline void RecomputeClip_ac16c8(cGZDrawContext* c)
{
    if (c->mbBlt && !c->mbBltTiling) {
        Rect_ac16c8 r;
        r.Fn0079dd60(reinterpret_cast<Rect_ac16c8*>(c->mnClip), reinterpret_cast<Rect_ac16c8*>(c->mnBltRect));
        static_cast<Engine_ac16c8*>(c->mpEngine)->SetClip(&r);
    } else {
        static_cast<Engine_ac16c8*>(c->mpEngine)->SetClip(c->mnClip);
    }
}

// A saved copy of the offset and clip (what PushTransform stores).
struct Transform_ac16c8 {
    float mfOffsetX;
    float mfOffsetY;
    int32_t mnClip[4];

    Transform_ac16c8& operator=(const Transform_ac16c8& o)
    {
        mfOffsetX = o.mfOffsetX;
        mfOffsetY = o.mfOffsetY;
        mnClip[0] = o.mnClip[0];
        mnClip[1] = o.mnClip[1];
        mnClip[2] = o.mnClip[2];
        mnClip[3] = o.mnClip[3];
        return *this;
    }
};

// A saved copy of the draw state (what PushState stores).
struct State_ac16c8 {
    uint8_t mbAntialias;
    uint8_t mbModulate;
    uint8_t mPad2[2];
    int32_t mnAlphaBlend;
    float mfLineThickness;
    int32_t mnPad12;
};

// FUNCTION: 0x0082be90
bool cGZDrawContext::QueryInterface(uint32_t iid, uint32_t out)
{
    switch (iid) {
    case 1:
    case 0x2ae63219:
        *OB_PTR(cGZDrawContext*, out) = this;
        this->Slot01_ac16c8();
        return true;
    default:
        return false;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082bec0 score 18
void cGZDrawContext::ClipReset()
{
    *reinterpret_cast<Rect_ac16c8*>(mnClip) = *reinterpret_cast<Rect_ac16c8*>(mnBaseClip);
}
#endif

// FUNCTION: 0x0082bee0
void cGZDrawContext::Offset(const void* p)
{
    const Point_ac16c8* pt = static_cast<const Point_ac16c8*>(p);
    mfOffsetX = static_cast<float>(pt->mnX) + mfOffsetX;
    mfOffsetY = static_cast<float>(pt->mnY) + mfOffsetY;
}

// FUNCTION: 0x0082bf00
void cGZDrawContext::OffsetAbsolute(const void* p)
{
    const Point_ac16c8* pt = static_cast<const Point_ac16c8*>(p);
    mfOffsetX = static_cast<float>(pt->mnX);
    mfOffsetY = static_cast<float>(pt->mnY);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082bf20 score 20
void cGZDrawContext::Slot12_ac16c8(void* out)
{
    *static_cast<Rect_ac16c8*>(out) = *reinterpret_cast<Rect_ac16c8*>(mnBaseClip);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082bf50 score 20
void cGZDrawContext::Slot13_ac16c8(void* out)
{
    *static_cast<Rect_ac16c8*>(out) = *reinterpret_cast<Rect_ac16c8*>(mnClip);
}
#endif

// FUNCTION: 0x0082bf80
void cGZDrawContext::Slot19_ac16c8()
{
    SetAlphaBlend(0);
    SetBltModulate(false);
    SetAntialiasing(false);
    SetLineThickness(1.0f);
    ClearBlt();
    ClearBltTiling();
    ClearGradient();
}

// FUNCTION: 0x0082bfc0
void cGZDrawContext::SetColor_2(uint32_t color)
{
    SetColor(0, color);
}

// FUNCTION: 0x0082bfd0
bool cGZDrawContext::IsSuspended()
{
    return mnSuspend > 0;
}

// FUNCTION: 0x0082bfe0
void cGZDrawContext::Clear()
{
    float r[4];
    r[0] = static_cast<float>(mnClip[0]);
    r[1] = static_cast<float>(mnClip[1]);
    r[2] = static_cast<float>(mnClip[2]);
    r[3] = static_cast<float>(mnClip[3]);
    Slot45_ac16c8(3, r, 2);
}

// FUNCTION: 0x0082c020
void cGZDrawContext::Point(int32_t x, int32_t y)
{
    float v[2];
    v[0] = static_cast<float>(x) + 0.5f;
    v[1] = static_cast<float>(y) + 0.5f;
    Slot44_ac16c8(0, v, 1);
}

// FUNCTION: 0x0082c060
void cGZDrawContext::Line(int32_t x0, int32_t y0, int32_t x1, int32_t y1)
{
    float v[4];
    v[0] = static_cast<float>(x0) + 0.5f;
    v[1] = static_cast<float>(y0) + 0.5f;
    v[2] = static_cast<float>(x1) + 0.5f;
    v[3] = static_cast<float>(y1) + 0.5f;
    Slot44_ac16c8(1, v, 2);
}

// FUNCTION: 0x0082c0c0
void cGZDrawContext::Fill(const void* p)
{
    const Rect_ac16c8* r = static_cast<const Rect_ac16c8*>(p);
    float v[4];
    v[0] = static_cast<float>(r->mnLeft);
    v[1] = static_cast<float>(r->mnTop);
    v[2] = static_cast<float>(r->mnRight);
    v[3] = static_cast<float>(r->mnBottom);
    Slot44_ac16c8(3, v, 2);
}

// FUNCTION: 0x0082c100
void cGZDrawContext::Ellipse(int32_t a, int32_t b, int32_t c, int32_t d)
{
    float v[4];
    v[0] = static_cast<float>(a);
    v[1] = static_cast<float>(b);
    v[2] = static_cast<float>(c);
    v[3] = static_cast<float>(d);
    Slot44_ac16c8(5, v, 2);
}

// FUNCTION: 0x0082c190
void cGZDrawContext::ClipAbsolute(const void* p)
{
    Rect_ac16c8* clip = reinterpret_cast<Rect_ac16c8*>(mnClip);
    clip->Fn0079dd60(clip, static_cast<const Rect_ac16c8*>(p));
    static_cast<Engine_ac16c8*>(mpEngine)->SetClip(clip);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082c1c0 score 7
void cGZDrawContext::Slot14_ac16c8(void* out)
{
    Point_ac16c8* pt = static_cast<Point_ac16c8*>(out);
    Point_ac16c8 q;
    q.mnX = static_cast<int32_t>(mfOffsetX);
    q.mnY = static_cast<int32_t>(mfOffsetY);
    *pt = q;
}
#endif

// FUNCTION: 0x0082c1f0
uint32_t cGZDrawContext::GetTransformStackDepth()
{
    return static_cast<uint32_t>((mpTransformEnd - mpTransformBegin) / 24);
}

// FUNCTION: 0x0082c210
bool cGZDrawContext::IsTargetAttached()
{
    return mpBuffer != 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082c220 score 9
void cGZDrawContext::SetColor(uint32_t index, uint32_t color)
{
    mnColor[index] = color;
    mnNative[index] = static_cast<Buffer_ac16c8*>(mpBuffer)->ConvertRGB(color >> 16, color >> 8, color);
    if (mpEngine) {
        static_cast<Engine_ac16c8*>(mpEngine)->SetColorTable(0, 4, mnColor);
    }
}
#endif

// FUNCTION: 0x0082c270
void cGZDrawContext::SetAlphaBlend(int32_t mode)
{
    if (mnAlphaBlend != mode) {
        mnAlphaBlend = mode;
        if (mpEngine) {
            static_cast<Engine_ac16c8*>(mpEngine)->SetAlphaBlend(mode);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082c290 score 7
void cGZDrawContext::SetBltModulate(bool on)
{
    if (mbModulate != on) {
        mbModulate = on;
        if (mpEngine) {
            static_cast<Engine_ac16c8*>(mpEngine)->SetModulate(on);
        }
    }
}
#endif

// FUNCTION: 0x0082c2b0
void cGZDrawContext::SetAntialiasing(bool on)
{
    if (mbAntialias != on) {
        mbAntialias = on;
        if (mpEngine) {
            static_cast<Engine_ac16c8*>(mpEngine)->SetAntialiasing(on);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082c2d0 score 12
void cGZDrawContext::SetLineThickness(float width)
{
    if (width != mfLineThickness) {
        float zero = 0.0f;
        const float* p = (width <= 0.0f) ? &zero : &width;
        float w = *p;
        mfLineThickness = w;
        int32_t n = static_cast<int32_t>(w + 0.5f);
        mnLineThickness = n;
        if (n == 0) {
            mnLineThickness = 1;
        }
        if (mpEngine) {
            static_cast<Engine_ac16c8*>(mpEngine)->SetLineThickness(w);
        }
    }
}
#endif

// FUNCTION: 0x0082c350
void cGZDrawContext::ClearGradient()
{
    static_cast<Engine_ac16c8*>(mpEngine)->SetGradient(0, 0, 0);
}

// FUNCTION: 0x0082c360
void cGZDrawContext::Slot27_ac16c8()
{
    static_cast<EngineB_ac16c8*>(mpEngine)->ClearGradient();
}

// FUNCTION: 0x0082c370
void cGZDrawContext::ClearBlt()
{
    SetBlt(0, 0.0f, 0.0f, 1.0f, 1.0f);
    mbBlt = 0;
    RecomputeClip_ac16c8(this);
}

// FUNCTION: 0x0082c3a0
void cGZDrawContext::SetBlt(void* buffer, float x, float y, float sx, float sy)
{
    mbBlt = static_cast<Engine_ac16c8*>(mpEngine)->SetBlt(buffer, x + mfOffsetX, y + mfOffsetY, sx, sy, mnBltRect);
    RecomputeClip_ac16c8(this);
}

// FUNCTION: 0x0082c420
void cGZDrawContext::ClearBltTiling()
{
    mbBltTiling = 0;
    static_cast<Engine_ac16c8*>(mpEngine)->ClearTiling();
    RecomputeClip_ac16c8(this);
}

// FUNCTION: 0x0082c480
void cGZDrawContext::SetBltTiling(const void* rect)
{
    mbBltTiling = 1;
    static_cast<Engine_ac16c8*>(mpEngine)->SetTiling(rect);
    RecomputeClip_ac16c8(this);
}

// FUNCTION: 0x0082c4e0
void cGZDrawContext::Slot42_ac16c8()
{
    mnSuspend = mnSuspend + 1;
    static_cast<Engine_ac16c8*>(mpEngine)->Suspend();
    static_cast<Engine_ac16c8*>(mpEngine)->Slot17();
}

// FUNCTION: 0x0082c500
void cGZDrawContext::Resume()
{
    if (mnSuspend != 0) {
        mnSuspend = mnSuspend - 1;
        if (mnSuspend == 0) {
            static_cast<Engine_ac16c8*>(mpEngine)->Resume();
        }
    }
}

// FUNCTION: 0x0082c520
void cGZDrawContext::Slot40_ac16c8()
{
    static_cast<Engine_ac16c8*>(mpEngine)->Suspend();
}

// FUNCTION: 0x0082c530
void cGZDrawContext::Blt(void* buffer, const void* srcRect, const void* dstRect)
{
    const Rect_ac16c8* src = static_cast<const Rect_ac16c8*>(srcRect);
    const Rect_ac16c8* dst = static_cast<const Rect_ac16c8*>(dstRect);
    if (src->mnRight > src->mnLeft) {
        if (src->mnBottom > src->mnTop) {
            if (dst->mnRight > dst->mnLeft) {
                if (dst->mnBottom > dst->mnTop) {
                    SetBlt(buffer, static_cast<float>(dst->mnLeft - src->mnLeft),
                           static_cast<float>(dst->mnTop - src->mnTop),
                           static_cast<float>(dst->mnRight - dst->mnLeft) / static_cast<float>(src->mnRight - src->mnLeft),
                           static_cast<float>(dst->mnBottom - dst->mnTop) / static_cast<float>(src->mnBottom - src->mnTop));
                    ClearBltTiling();
                    Fill(dstRect);
                    ClearBlt();
                }
            }
        }
    }
}

// FUNCTION: 0x0082c620
void cGZDrawContext::BltTiled(void* buffer, const void* srcRect, const void* dstRect, int32_t dx, int32_t dy)
{
    const Rect_ac16c8* src = static_cast<const Rect_ac16c8*>(srcRect);
    const Rect_ac16c8* dst = static_cast<const Rect_ac16c8*>(dstRect);
    if (src->mnRight > src->mnLeft && src->mnBottom > src->mnTop && dst->mnRight > dst->mnLeft
        && dst->mnBottom > dst->mnTop) {
        SetBlt(buffer, static_cast<float>(dx + dst->mnLeft), static_cast<float>(dy + dst->mnTop), 1.0f, 1.0f);
        SetBltTiling(srcRect);
        Fill(dstRect);
        ClearBltTiling();
        ClearBlt();
    }
}

// FUNCTION: 0x0082c6b0
void cGZDrawContext::Slot46_ac16c8()
{
    static_cast<Engine_ac16c8*>(mpEngine)->Slot19();
}

// FUNCTION: 0x0082c6c0
void cGZDrawContext::Slot47_ac16c8()
{
    static_cast<Engine_ac16c8*>(mpEngine)->Slot20();
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082c6d0 score 68
void cGZDrawContext::Clip(const void* p)
{
    const Rect_ac16c8* r = static_cast<const Rect_ac16c8*>(p);
    int32_t l = r->mnLeft;
    int32_t t = r->mnTop;
    int32_t rt = r->mnRight;
    int32_t b = r->mnBottom;
    int32_t dy = static_cast<int32_t>(mfOffsetY);
    int32_t dx = static_cast<int32_t>(mfOffsetX);
    Rect_ac16c8 q;
    q.mnLeft = l + dx;
    q.mnTop = t + dy;
    q.mnRight = rt + dx;
    q.mnBottom = b + dy;
    Rect_ac16c8* clip = reinterpret_cast<Rect_ac16c8*>(mnClip);
    clip->Fn0079dd60(clip, &q);
    RecomputeClip_ac16c8(this);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082c780 score 35
void cGZDrawContext::PopTransform()
{
    if (mpTransformBegin != mpTransformEnd) {
        const Transform_ac16c8* t = reinterpret_cast<const Transform_ac16c8*>(mpTransformEnd) - 1;
        *reinterpret_cast<Transform_ac16c8*>(&mfOffsetX) = *t;
        mpTransformEnd -= sizeof(Transform_ac16c8);
        static_cast<Engine_ac16c8*>(mpEngine)->SetClip(mnClip);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082c7d0 score 28
void cGZDrawContext::PopState()
{
    if (mpStateBegin != mpStateEnd) {
        const State_ac16c8* s = reinterpret_cast<const State_ac16c8*>(mpStateEnd) - 1;
        SetAntialiasing(s->mbAntialias);
        SetBltModulate(s->mbModulate);
        SetAlphaBlend(s->mnAlphaBlend);
        SetLineThickness(s->mfLineThickness);
        mpStateEnd -= sizeof(State_ac16c8);
    }
}
#endif

// The vector of transforms (an STLport vector, three pointers).
struct TransformVec_ac16c8 {
    Transform_ac16c8* mpBegin;
    Transform_ac16c8* mpEnd;
    Transform_ac16c8* mpCap;

    // STUB: 0x00627100
    void push_back(const Transform_ac16c8& t);
};

// The vector of draw states.
struct StateVec_ac16c8 {
    State_ac16c8* mpBegin;
    State_ac16c8* mpEnd;
    State_ac16c8* mpCap;

    // STUB: 0x00638c60
    void Fn00638c60(State_ac16c8* pos, const State_ac16c8* x, const void* tag, uint32_t n, uint32_t atEnd);
};

// The scratch vector of floats.
struct FloatVec_ac16c8 {
    float* mpBegin;
    float* mpEnd;
    float* mpCap;

    // STUB: 0x00464130
    void Fn00464130(uint32_t n, const float* fill);
};

// The scratch buffer the quad converter fills.
struct FloatBuf_ac16c8 {
    float* mpData;
    float* mpEnd;
    float* mpCap;

    // STUB: 0x0048c290
    void Fn0048c290(uint32_t n);
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// The framework object the draw system is asked from.
struct Framework_ac16c8 {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual bool GetSystemService(uint32_t clsid, uint32_t iid, void** out) = 0;
};

// The draw system that makes engines.
struct DrawSystem_ac16c8 {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual bool CreateEngine(void* buffer, void** out) = 0;
};

// A system-service smart pointer's release.
struct SysPtr_ac16c8 {
    DrawSystem_ac16c8* mp;

    // STUB: 0x004495c0
    void Fn004495c0();
};

// STUB: 0x008793ec
Framework_ac16c8* Fn008793ec();

#ifdef OB_DRAFTS
// CLOSE: 0x0082cf10 score 15
uint32_t cGZDrawContext::Release()
{
    int32_t n = mnRefCount - 1;
    mnRefCount = n;
    if (n == 0) {
        Fn0082ca40();
        ::operator delete(this);
    }
    return n;
}
#endif

// FUNCTION: 0x0082cfe0
void cGZDrawContext::PushTransform()
{
    reinterpret_cast<TransformVec_ac16c8*>(&mpTransformBegin)->push_back(*reinterpret_cast<Transform_ac16c8*>(&mfOffsetX));
}

#ifdef OB_DRAFTS
// CLOSE: 0x0082cff0 score 14
void cGZDrawContext::PushState()
{
    StateVec_ac16c8* v = reinterpret_cast<StateVec_ac16c8*>(&mpStateBegin);
    const State_ac16c8* s = reinterpret_cast<const State_ac16c8*>(&mbAntialias);
    if (v->mpEnd != v->mpCap) {
        if (v->mpEnd) {
            *v->mpEnd = *s;
        }
        v->mpEnd = v->mpEnd + 1;
    } else {
        uint8_t tag;
        v->Fn00638c60(v->mpEnd, s, &tag, 1, 1);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082ca40 score 23
void cGZDrawContext::Fn0082ca40()
{
    if (mpEngine) {
        static_cast<Engine_ac16c8*>(mpEngine)->Detach();
    }
    if (mpVecB8) {
        Fn0090cf63(mpVecB8);
    }
    if (mpVecAC) {
        Fn0090cf63(mpVecAC);
    }
    if (mpVecA0) {
        Fn0090cf63(mpVecA0);
    }
    if (mpVec94) {
        Fn0090cf63(mpVec94);
    }
    if (mpStateBegin) {
        Fn0090cf63(mpStateBegin);
    }
    if (mpTransformBegin) {
        Fn0090cf63(mpTransformBegin);
    }
    if (mpEngine) {
        static_cast<Engine_ac16c8*>(mpEngine)->Release();
    }
    if (mpBuffer) {
        static_cast<Buffer_ac16c8*>(mpBuffer)->Release();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082cae0 score 90
void cGZDrawContext::Fn0082cae0(const void* pts, uint32_t n)
{
    const float* in = static_cast<const float*>(pts);
    FloatBuf_ac16c8 buf;
    buf.Fn0048c290(n * 4);
    float* out = buf.mpData;
    for (uint32_t i = 0; i < n; i++) {
        float x = in[0];
        float y = in[1];
        out[0] = x - 0.5f;
        out[1] = y - 0.5f;
        out[2] = x + 0.5f;
        out[3] = y + 0.5f;
        in += 2;
        out += 4;
    }
    Slot45_ac16c8(3, buf.mpData, n + n);
    if (buf.mpData) {
        Fn0090cf63(buf.mpData);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082f970 score 6
void cGZDrawContext::Fn0082f970(const void* pts, uint32_t n)
{
    switch (static_cast<Engine_ac16c8*>(mpEngine)->Slot21(0, pts, n)) {
    case 0:
        break;
    case 1:
        Fn0082eba0(pts, n);
        break;
    case 2:
        Fn0082cae0(pts, n);
        break;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082ea60 score 61
void cGZDrawContext::Slot44_ac16c8(uint32_t kind, const void* pts, uint32_t n)
{
    FloatVec_ac16c8* v = reinterpret_cast<FloatVec_ac16c8*>(&mpVec94);
    const float* in = static_cast<const float*>(pts);
    float zero = 0.0f;
    v->Fn00464130(n * 2, &zero);
    for (uint32_t i = 0; i < n; i++) {
        v->mpBegin[i * 2] = mfOffsetX + in[i * 2];
        v->mpBegin[i * 2 + 1] = in[i * 2 + 1] + mfOffsetY;
    }
    Slot45_ac16c8(kind, v->mpBegin, n);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082fc30 score 12
void cGZDrawContext::Slot45_ac16c8(uint32_t kind, const void* pts, uint32_t n)
{
    uint8_t* t0 = mpVecAC;
    uint8_t* t1 = mpVecA0;
    mpVecA0 = t0;
    mpVecAC = t1;
    t0 = mpVecB0;
    t1 = mpVecA4;
    mpVecA4 = t0;
    mpVecB0 = t1;
    t1 = mpVecA8;
    t0 = mpVecB4;
    mpVecA8 = t0;
    mpVecB4 = t1;
    switch (kind) {
    case 0: Fn0082f970(pts, n); break;
    case 1: Fn0082fbe0(pts, n); break;
    case 2: Fn0082fa50(pts, n); break;
    case 3: Fn0082faa0(pts, n); break;
    case 4: Fn0082e9d0(pts, n); break;
    case 5: Fn0082faf0(pts, n); break;
    case 6: Fn0082ea20(pts, n); break;
    case 7: Fn0082fb40(pts, n); break;
    case 8: Fn0082fb90(pts, n); break;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0082c830 score 69
void cGZDrawContext::SetTarget(void* buffer)
{
    Buffer_ac16c8* b = static_cast<Buffer_ac16c8*>(buffer);
    if (mpBuffer != buffer) {
        if (mpEngine) {
            static_cast<Engine_ac16c8*>(mpEngine)->Detach();
            if (mpEngine) {
                Engine_ac16c8* old = static_cast<Engine_ac16c8*>(mpEngine);
                mpEngine = 0;
                old->Release();
            }
        }
        Buffer_ac16c8* prev = static_cast<Buffer_ac16c8*>(mpBuffer);
        if (b != prev) {
            if (b) {
                b->AddRef();
            }
            mpBuffer = b;
            if (prev) {
                prev->Release();
            }
        }
        if (b) {
            const Rect_ac16c8* area = b->GetArea();
            *reinterpret_cast<Rect_ac16c8*>(mnClip) = *area;
            mfOffsetX = 0.0f;
            mfOffsetY = 0.0f;
            SysPtr_ac16c8 sys;
            sys.mp = 0;
            Framework_ac16c8* fw = Fn008793ec();
            if (fw) {
                void* tmp = &sys.mp;
                fw->GetSystemService(0xeb2ea3cb, 0x4b2ea3b3, static_cast<void**>(tmp));
            }
            DrawSystem_ac16c8* ds = sys.mp;
            if (mpEngine) {
                Engine_ac16c8* old = static_cast<Engine_ac16c8*>(mpEngine);
                mpEngine = 0;
                old->Release();
            }
            ds->CreateEngine(buffer, &mpEngine);
            sys.Fn004495c0();
            Engine_ac16c8* e = static_cast<Engine_ac16c8*>(mpEngine);
            e->SetTarget(buffer);
            e = static_cast<Engine_ac16c8*>(mpEngine);
            e->SetClip(mnClip);
            e = static_cast<Engine_ac16c8*>(mpEngine);
            e->SetColorTable(0, 4, mnColor);
            e = static_cast<Engine_ac16c8*>(mpEngine);
            e->SetAlphaBlend(mnAlphaBlend);
            e = static_cast<Engine_ac16c8*>(mpEngine);
            e->SetModulate(mbModulate);
            e = static_cast<Engine_ac16c8*>(mpEngine);
            e->SetAntialiasing(mbAntialias);
            e = static_cast<Engine_ac16c8*>(mpEngine);
            e->SetLineThickness(mfLineThickness);
            Rect_ac16c8 dummy;
            e = static_cast<Engine_ac16c8*>(mpEngine);
            e->SetBlt(0, 0.0f, 0.0f, 0.0f, 0.0f, &dummy);
            e = static_cast<Engine_ac16c8*>(mpEngine);
            e->SetGradient(0, 0, 0);
            e = static_cast<Engine_ac16c8*>(mpEngine);
            e->SetClipBase(mnBaseClip);
            mbBlt = 0;
            mbBltTiling = 0;
            mnSuspend = 0;
        }
    }
}
#endif
