#include "classes/cUnk00a9ea60.h"
#include "game/Globals.h"

// The interface a caller hands to Slot03_aaaa9c (reached through its slot 0 query).
struct cIface_a9ea60 {
    virtual bool QueryInterface(uint32_t, void**);
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual uint32_t Fn04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void* Fn09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual uint32_t Fn14();
};

// The host object (mpHost) and the interface it keeps at +8.
struct cHost_a9ea60 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};
struct cHostIf_a9ea60 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Fn09(void*);
};

// The effect object (mpEffect).
struct cEffect_a9ea60 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual void Fn03(uint32_t);
    virtual void Fn04(uint32_t);
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn08(void*);
    virtual void Pad09();
    virtual void Fn10(uint32_t, void*);
};

// The factory object (mpFactory): slot 7 makes the named effect into the out pointer.
struct cFactory_a9ea60 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual bool Fn07(const char*, void**);
};

// The metrics object (mpMetrics): slot 13 gives a float for a position.
struct cMetrics_a9ea60 {
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
    virtual float Fn13(float, float);
};

// The transform record Slot13_a9ea60 hands to the effect.
struct cXform_a9ea60 {
    uint8_t mnCount;
    uint8_t mnFlags;
    float mfRot[9];
    float mfPos[3];
    float mfScale;
};

// A list the curve lookups hang from (20-byte records); slot 0x005f4250 reads a curve at a time.
struct cRec_a9ea60 {
    uint8_t mData[20];
};
struct cCurveList_a9ea60 {
    cRec_a9ea60* mpBegin;
    cRec_a9ea60* mpEnd;
    // STUB: 0x005f4250
    float Fn005f4250(float);
};

// The scene object the screen global hands out (slot 72).
struct cScene_a9ea60 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void* Fn07(uint32_t);
    virtual void Fn08(void*);
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Fn13(void*, float, float, uint32_t, uint32_t, uint32_t);
};

// The registry at 0x00b43ccc as this class uses it: slot 5 registers, slot 6 unregisters an object under an id.
struct cRegistry_a9ea60 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05(void* object, uint32_t id);
    virtual void Fn06(void* object, uint32_t id);
};

// The screen object at 0x00b43cec; only the slots used here are named.
struct cScreen_a9ea60 {
    virtual void Pad000();
    virtual void Pad001();
    virtual void Pad002();
    virtual void Pad003();
    virtual void Pad004();
    virtual void Pad005();
    virtual void Pad006();
    virtual void Pad007();
    virtual void Pad008();
    virtual void Pad009();
    virtual void Pad010();
    virtual void Pad011();
    virtual void Pad012();
    virtual void Pad013();
    virtual void Pad014();
    virtual void Pad015();
    virtual void Pad016();
    virtual void Pad017();
    virtual void Pad018();
    virtual void Pad019();
    virtual void Pad020();
    virtual void Pad021();
    virtual void Pad022();
    virtual void Pad023();
    virtual void Pad024();
    virtual void Pad025();
    virtual void Pad026();
    virtual void Pad027();
    virtual void Pad028();
    virtual void Pad029();
    virtual void Pad030();
    virtual void Pad031();
    virtual void Pad032();
    virtual void Pad033();
    virtual void Pad034();
    virtual void Pad035();
    virtual void Pad036();
    virtual void Pad037();
    virtual void Pad038();
    virtual void Pad039();
    virtual void Pad040();
    virtual void Pad041();
    virtual void Pad042();
    virtual void Pad043();
    virtual void Pad044();
    virtual void Pad045();
    virtual void Pad046();
    virtual void Pad047();
    virtual void Pad048();
    virtual void Pad049();
    virtual void Pad050();
    virtual void Pad051();
    virtual void Pad052();
    virtual void Pad053();
    virtual void Pad054();
    virtual void Pad055();
    virtual void Pad056();
    virtual void Pad057();
    virtual void Pad058();
    virtual void Pad059();
    virtual void Pad060();
    virtual void Pad061();
    virtual void Pad062();
    virtual void Pad063();
    virtual void Pad064();
    virtual void Pad065();
    virtual void Pad066();
    virtual void Pad067();
    virtual void Pad068();
    virtual void Pad069();
    virtual void Pad070();
    virtual void Pad071();
    virtual cScene_a9ea60* Fn72();
    virtual void Pad073();
    virtual void Pad074();
    virtual void Pad075();
    virtual void Pad076();
    virtual void Pad077();
    virtual void Pad078();
    virtual void Pad079();
    virtual void Pad080();
    virtual void Pad081();
    virtual void Pad082();
    virtual void Pad083();
    virtual cHost_a9ea60* Fn84();
    virtual cHost_a9ea60* Fn85();
    virtual void Pad086();
    virtual void Pad087();
    virtual void Pad088();
    virtual float Fn89();
    virtual float Fn90();
    virtual void Pad091();
    virtual void Pad092();
    virtual void Pad093();
    virtual void Pad094();
    virtual void Fn95(float, float, float*, float*);
};

// The curve object (mpCurve).
struct cCurve_a9ea60 {
    // STUB: 0x0075d640
    float Fn0075d640(uint32_t, uint32_t);
    // STUB: 0x0075d5b0
    void Fn0075d5b0(float);
    // STUB: 0x0075d5c0
    void Fn0075d5c0(float);
};

// GLOBAL: 0x00b43cec
extern cScreen_a9ea60* gpB43cec;

// GLOBAL: 0x00b22bb9
extern bool gb22bb9;

// GLOBAL: 0x00b22bb4
extern cCurveList_a9ea60* gpB22bb4;

// GLOBAL: 0x00b22bb0
extern cCurveList_a9ea60* gpB22bb0;

// GLOBAL: 0x00b0a1fc
extern float gb0a1fc;

// GLOBAL: 0x00b0a1f8
extern float gb0a1f8;

// STUB: 0x00602600
cRegistry_a9ea60* Fn00602600();

// STUB: 0x0057f9f0
void Fn0057f9f0();

// STUB: 0x0057ffe0
void Fn0057ffe0(cUnk00a9ea60* p);

// FUNCTION: 0x00472e60
void* cUnk00a9ea60::Slot03_a9ea08()
{
    return this;
}

// FUNCTION: 0x0057f430
void* cUnk00a9ea60::Slot04_a9ea60()
{
    if (mpHost) {
        return static_cast<uint8_t*>(mpHost) + 8;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0057f440 score 1
uint32_t cUnk00a9ea60::Slot07_a9ea60()
{
    uint32_t r = 2;
    switch (mnState) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 2;
        break;
    case 2:
    case 3:
        r = 1;
        break;
    case 4:
        r = 3;
        break;
    }
    return r;
}
#endif

// FUNCTION: 0x0057f480
bool cUnk00a9ea60::QueryInterface(unsigned int iid, void** ppv)
{
    *ppv = 0;
    switch (iid) {
    case 0x22223ba4:
        *ppv = this;
        break;
    case 0x29b5ab88:
        *ppv = static_cast<cUnk00a9ea08*>(this);
        break;
    }
    if (*ppv) {
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x0057f4d0
unsigned int cUnk00a9ea60::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x0057f4f0
void cUnk00a9ea60::Slot10_a9ea60()
{
    if (!mbFlag41) {
        Slot13_a9ea60("volcano_control", &mfSizeX, true, &mpEffect);
        mbFlag41 = true;
    }
}

// FUNCTION: 0x0057f520
void cUnk00a9ea60::Slot11_a9ea60()
{
    if (!mbFlag40) {
        AddRef();
        reinterpret_cast<cHostIf_a9ea60*>(static_cast<uint8_t*>(mpHost) + 8)->Fn09(this);
        Slot03_a9ea60();
        Release();
    }
}

// FUNCTION: 0x0057f550
float cUnk00a9ea60::Slot06_a9ea08(uint32_t a, uint32_t b)
{
    if (!mpCurve) {
        return 0.0f;
    }
    return static_cast<cCurve_a9ea60*>(mpCurve)->Fn0075d640(a, b);
}

// FUNCTION: 0x0057f6c0
bool cUnk00a9ea60::Slot03_aaaa9c(void* p)
{
    cIface_a9ea60* pIface = 0;
    static_cast<cIface_a9ea60*>(p)->QueryInterface(0x65297976, reinterpret_cast<void**>(&pIface));
    switch (pIface->Fn04()) {
    case 0x86ad10ee:
        Slot14_a9ea60(pIface->Fn14());
        break;
    case 0xca493c1d:
        if (pIface->Fn09() == this) {
            Slot08_a9ea08(7);
        }
        break;
    }
    if (pIface) {
        pIface->Release();
    }
    return true;
}

// FUNCTION: 0x0057f7a0
bool cUnk00a9ea60::Slot05_a9ea08(uint32_t a)
{
    const int32_t* p = reinterpret_cast<const int32_t*>(a);
    mnPosX = p[0];
    mnPosY = p[1];
    float fA = 0.0f;
    float fB = 0.0f;
    cScreen_a9ea60* pScreen = gpB43cec;
    pScreen->Fn95(static_cast<float>(p[0]), static_cast<float>(p[1]), &fA, &fB);
    pScreen->Fn72()->Fn13(this, fA, fB, 0, 0, 0);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0057f820 score 36
bool cUnk00a9ea60::Slot08_a9ea08(uint32_t newState)
{
    if (newState == mnState) {
        return false;
    }
    mnState = newState;
    switch (newState) {
    case 3:
        Slot10_a9ea60();
        if (gb22bb9 && !mbFlag43 && !mbFlag40) {
            Fn0057f360();
            Slot08_a9ea08(5);
            return true;
        }
        break;
    case 5:
        if (gb22bb9 && !mbFlag40) {
            Fn0057f3d0();
            return true;
        }
        break;
    case 7:
        mbFlag42 = true;
        if (!gb22bb9 || !mbFlag40) {
            Slot08_a9ea08(8);
            return true;
        }
        Slot08_a9ea08(5);
        return true;
    case 8:
        if (gb22bb9) {
            Fn0057f740();
        }
        Slot11_a9ea60();
        break;
    }
    return true;
}
#endif

// FUNCTION: 0x0057f920
bool cUnk00a9ea60::Slot03_a9ea60()
{
    if (!mbActive) {
        return false;
    }
    mbActive = false;
    cRegistry_a9ea60* pReg = Fn00602600();
    if (pReg) {
        pReg->Fn06(static_cast<cUnk00aaaa9c*>(this), 0xc0);
    }
    if (mbFlag41) {
        if (mpEffect) {
            static_cast<cEffect_a9ea60*>(mpEffect)->Fn04(1);
            static_cast<cEffect_a9ea60*>(mpEffect)->Release();
        }
        mbFlag41 = false;
    }
    cRegistry_a9ea60* pGlobal = reinterpret_cast<cRegistry_a9ea60*>(gpB43ccc);
    if (pGlobal) {
        pGlobal->Fn06(static_cast<cUnk00aaaa9c*>(this), 0xca493c1d);
    }
    if (mbFlag40 || mbFlag44) {
        Fn0057f740();
    }
    cHostIf_a9ea60* pIf = static_cast<cHostIf_a9ea60*>(Slot04_a9ea60());
    if (pIf) {
        pIf->Fn09(this);
    }
    if (mpMetrics) {
        static_cast<cHost_a9ea60*>(mpMetrics)->Release();
        mpMetrics = 0;
    }
    if (mpHost) {
        static_cast<cHost_a9ea60*>(mpHost)->Release();
        mpHost = 0;
    }
    if (mpFactory) {
        static_cast<cHost_a9ea60*>(mpFactory)->Release();
        mpFactory = 0;
    }
    Release();
    return true;
}

// FUNCTION: 0x0057fb90
void cUnk00a9ea60::Slot14_a9ea60(uint32_t dt)
{
    if (gb22bb9 && mbFlag40) {
        mnTimer += dt;
        float t = static_cast<float>(mnTimer) * 0.000001f;
        if (t > gb0a1fc) {
            Fn0057f740();
            if (!mbFlag42) {
                Slot08_a9ea08(3);
            } else {
                Slot08_a9ea08(8);
            }
        } else if (mnState == 5) {
            float fA = 0.0f;
            float fB = 0.0f;
            if (gpB22bb4->mpEnd - gpB22bb4->mpBegin != 0) {
                fA = gpB22bb4->Fn005f4250(t / gb0a1fc) * gb0a1f8 * 0.00001f;
            }
            if (gpB22bb4->mpEnd - gpB22bb4->mpBegin != 0) {
                fB = gpB22bb0->Fn005f4250(t / gb0a1fc) * 0.00001f;
            }
            static_cast<cCurve_a9ea60*>(mpCurve)->Fn0075d5b0(fA);
            static_cast<cCurve_a9ea60*>(mpCurve)->Fn0075d5c0(fB);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0057fce0 score 2
void cUnk00a9ea60::Slot13_a9ea60(const char* name, const void* b, bool c, void* d)
{
    cEffect_a9ea60** pp = static_cast<cEffect_a9ea60**>(d);
    const float* pos = static_cast<const float*>(b);
    *pp = 0;
    if (static_cast<cFactory_a9ea60*>(mpFactory)->Fn07(name, reinterpret_cast<void**>(pp))) {
        cXform_a9ea60 x;
        cEffect_a9ea60* e;
        e = *pp;
        x.mfRot[0] = 1.0f;
        x.mfRot[3] = 0.0f;
        x.mfRot[6] = 0.0f;
        x.mfRot[1] = 0.0f;
        x.mfRot[4] = 1.0f;
        x.mfRot[7] = 0.0f;
        x.mfRot[2] = 0.0f;
        x.mfRot[5] = 0.0f;
        x.mfRot[8] = 1.0f;
        x.mfScale = 1.0f;
        x.mfPos[0] = 0.0f;
        x.mfPos[1] = 0.0f;
        x.mfPos[2] = 0.0f;
        x.mnFlags = 0;
        x.mnCount = 0;
        e->Fn10(0xca493c1d, this);
        float v[3];
        v[0] = pos[0];
        v[2] = pos[1];
        x.mfPos[1] = static_cast<cMetrics_a9ea60*>(mpMetrics)->Fn13(v[0], v[2]);
        x.mfPos[0] = v[0];
        x.mfPos[2] = v[2];
        x.mnFlags |= 1;
        x.mnCount++;
        (*pp)->Fn08(&x);
        (*pp)->Fn03(0);
        if (!c) {
            (*pp)->Release();
            *pp = 0;
        }
    }
}
#endif

// FUNCTION: 0x00580070
bool cUnk00a9ea60::Slot09_a9ea60()
{
    mbActive = true;
    Fn0057ffe0(this);
    cScreen_a9ea60* pScreen = gpB43cec;
    mpMetrics = pScreen->Fn84();
    if (mpMetrics) {
        static_cast<cHost_a9ea60*>(mpMetrics)->AddRef();
    }
    cScene_a9ea60* pScene = pScreen->Fn72();
    uint8_t* q = static_cast<uint8_t*>(pScene->Fn07(0xc4c90997));
    if (q) {
        mpHost = q - 8;
        static_cast<cHost_a9ea60*>(mpHost)->AddRef();
    }
    mpFactory = pScreen->Fn85();
    if (mpFactory) {
        static_cast<cHost_a9ea60*>(mpFactory)->AddRef();
    }
    cRegistry_a9ea60* pGlobal = reinterpret_cast<cRegistry_a9ea60*>(gpB43ccc);
    if (pGlobal) {
        pGlobal->Fn05(static_cast<cUnk00aaaa9c*>(this), 0xca493c1d);
    }
    int32_t x = mnPosX;
    if (x < 0) {
        mnPosX = 0;
    } else if (static_cast<float>(x) > pScreen->Fn89() - 1.0f) {
        mnPosX = static_cast<int32_t>(pScreen->Fn89() - 1.0f);
    }
    int32_t y = mnPosY;
    if (y < 0) {
        mnPosY = 0;
    } else if (static_cast<float>(y) > pScreen->Fn90() - 1.0f) {
        mnPosY = static_cast<int32_t>(pScreen->Fn90() - 1.0f);
    }
    Fn0057f9f0();
    mnTimer = 0;
    cRegistry_a9ea60* pReg = Fn00602600();
    if (pReg) {
        pReg->Fn05(static_cast<cUnk00aaaa9c*>(this), 0xc0);
    }
    mfSizeX = static_cast<float>(mnPosX);
    mfSizeY = static_cast<float>(mnPosY);
    Slot08_a9ea08(1);
    float fA;
    float fB;
    pScreen->Fn95(mfSizeX, mfSizeY, &fA, &fB);
    pScene->Fn13(this, fA, fB, 0, 0, 0);
    pScene->Fn08(this);
    mbFlag44 = true;
    return true;
}
