#include <cstddef>

#include "classes/cSC4Demand.h"
#include "game/Globals.h"

// STUB: 0x009133da
void* Fn009133da(uint32_t size);

// The 0x2c-byte object the allocator hands out (vtable 0x00acec00); only the calls used here are named.
struct cMade_aa2758 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05(uint32_t);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Fn11(uint32_t);
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Fn16(uint32_t);
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    cMade_aa2758();
    static void* operator new(size_t size) { return Fn009133da(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// The object behind the global at 0xb43cec: only AddRef and Release are used here.
struct cB43cec_aa2758 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};

// GLOBAL: 0x00b43cec
extern cB43cec_aa2758* gpB43cec_aa2758;

// The object behind the global at 0xb43ccc (see Globals.h): slots 1 and 2 are used here besides slot 4.
struct cB43ccc_aa2758 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Fn04(void* object, uint32_t id);
};

// GLOBAL: 0x00b23028
extern bool gB23028;

// The stream the object is read from: only the slots used here are named.
struct StreamIn_aa2758 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Rd05(uint8_t*);
    virtual void Pad06();
    virtual void Rd07(uint16_t*);
    virtual void Pad08();
    virtual void Rd09(int32_t*);
    virtual void Pad10();
    virtual void Pad11();
    virtual void Rd12(float*);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual bool Fn18();
};

// The stream the object is written to.
struct StreamOut_aa2758 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Wr07(uint16_t);
    virtual void Pad08();
    virtual void Wr09(int32_t);
    virtual void Pad10();
    virtual void Pad11();
    virtual void Wr12(float);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual bool Fn18();
};

// STUB: 0x005d9fa0
void Fn005d9fa0(StreamIn_aa2758* stream, bool* pOut);

// STUB: 0x005d9fd0
void Fn005d9fd0(StreamOut_aa2758* stream, bool value);

// FUNCTION: 0x005d4c60
bool cSC4Demand::AddToSupplyValue(float a)
{
    mfDeltaA += a;
    return true;
}

// FUNCTION: 0x005d4c70
bool cSC4Demand::AddToDemandValue(float a)
{
    mfDeltaB += a;
    return true;
}

// FUNCTION: 0x005d4c80
bool cSC4Demand::SetSupplyValue(float a)
{
    mfPos = a;
    return true;
}

// FUNCTION: 0x005d4c90
bool cSC4Demand::SetDemandValue(float a)
{
    mfTarget = a;
    return true;
}

// FUNCTION: 0x005d4ca0
void cSC4Demand::SetActiveDemandMax(float a)
{
    mfMax = a;
    if (a < mfMin) {
        mfMax = mfMin;
    }
}

// FUNCTION: 0x005d4cc0
void cSC4Demand::SetActiveDemandMin(float a)
{
    mfMin = a;
    if (a > mfMax) {
        mfMin = mfMax;
    }
}

// FUNCTION: 0x005d4ce0
void cSC4Demand::SetDemandCap(void* p)
{
    mfF44 = *static_cast<float*>(p);
}

// FUNCTION: 0x005d4d90
unsigned int cSC4Demand::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Shutdown();
    delete this;
    return 0;
}

// FUNCTION: 0x005d4af0
bool cSC4Demand::QueryInterface(unsigned int id, void** ppOut)
{
    if (id != 1 && id != 0x797a4e8) {
        if (id != 0xe4fda3d4) {
            return false;
        }
        *ppOut = static_cast<cUnk00a80784*>(this);
        AddRef();
        return true;
    }
    *ppOut = this;
    AddRef();
    return true;
}

// FUNCTION: 0x005d4b50
bool cSC4Demand::Shutdown()
{
    if (mbOpen) {
        mbOpen = false;
        cB43cec_aa2758* a = static_cast<cB43cec_aa2758*>(mpA);
        if (a) {
            a->Release();
            mpA = 0;
        }
        cB43ccc_aa2758* b = static_cast<cB43ccc_aa2758*>(mpB);
        if (b) {
            b->Release();
            mpB = 0;
        }
    }
    return true;
}

// FUNCTION: 0x005d4cf0
bool cSC4Demand::EndOfCycle()
{
    bool changed = (mfDeltaA != 0.0f || mfDeltaB != 0.0f);
    mfPos = mfDeltaA + mfPos;
    mfDeltaA = 0.0f;
    mfTarget = mfDeltaB + mfTarget;
    mfDeltaB = 0.0f;
    CalculateActiveDemand(false);
    return changed;
}

// FUNCTION: 0x005d4dc0
bool cSC4Demand::Init()
{
    if (!mbOpen) {
        mbOpen = true;
        if (!gB23028) {
            gB23028 = true;
        }
        if (!mbLoaded) {
            mnId = 0;
            mfPos = 0.0f;
            mfTarget = 0.0f;
            mfDeltaA = 0.0f;
            mfDeltaB = 0.0f;
            mfF24 = 0.0f;
            mfF28 = 0.0f;
            mfMax = 8.50705867e37f;
            mfMin = -8.50705867e37f;
            mfValue = 0.0f;
            mbF38 = true;
            mfF3c = 0.0f;
            mfF40 = 0.0f;
            mfF44 = 0.0f;
        }
        if (!mpA) {
            mpA = gpB43cec_aa2758;
            cB43cec_aa2758* a = static_cast<cB43cec_aa2758*>(mpA);
            if (!a) {
                return false;
            }
            a->AddRef();
        }
        if (!mpB) {
            mpB = gpB43ccc;
            cB43ccc_aa2758* b = static_cast<cB43ccc_aa2758*>(mpB);
            if (!b) {
                return false;
            }
            b->AddRef();
        }
    }
    return true;
}

// FUNCTION: 0x005d4b90
bool cSC4Demand::SimulationBegin()
{
    if (!mbLoaded) {
        CalculateActiveDemand(false);
    }
    int32_t n;
    if (mfValue < 0.0f) {
        n = static_cast<int32_t>(mfValue / mfMin * -1000.0f);
    } else {
        n = static_cast<int32_t>(mfValue / mfMax * 1000.0f);
    }
    cMade_aa2758* m = new cMade_aa2758;
    m->AddRef();
    m->Fn05(0x426840a0);
    m->Fn11(mnId);
    m->Fn16(n);
    static_cast<cB43ccc_aa2758*>(mpB)->Fn04(m, 0);
    m->Release();
    return true;
}

// FUNCTION: 0x005d5080
bool cSC4Demand::Slot03_a80784(void* pStream)
{
    StreamOut_aa2758* s = static_cast<StreamOut_aa2758*>(pStream);
    s->Wr07(2);
    s->Wr09(mnId);
    s->Wr12(mfPos);
    s->Wr12(mfTarget);
    s->Wr12(mfDeltaA);
    s->Wr12(mfDeltaB);
    s->Wr12(mfF24);
    s->Wr12(mfF28);
    s->Wr12(mfMin);
    s->Wr12(mfMax);
    s->Wr12(mfValue);
    Fn005d9fd0(s, mbF38);
    s->Wr12(mfF3c);
    s->Wr12(mfF40);
    s->Wr12(mfF44);
    bool r = !s->Fn18();
    return r;
}

// FUNCTION: 0x005d5150
bool cSC4Demand::Slot04_a80784(void* pStream)
{
    StreamIn_aa2758* s = static_cast<StreamIn_aa2758*>(pStream);
    uint16_t version;
    mbLoaded = true;
    s->Rd07(&version);
    if (version > 2) {
        return false;
    }
    s->Rd09(&mnId);
    s->Rd12(&mfPos);
    s->Rd12(&mfTarget);
    s->Rd12(&mfDeltaA);
    s->Rd12(&mfDeltaB);
    s->Rd12(&mfF24);
    s->Rd12(&mfF28);
    s->Rd12(&mfMin);
    s->Rd12(&mfMax);
    s->Rd12(&mfValue);
    Fn005d9fa0(s, &mbF38);
    s->Rd12(&mfF3c);
    s->Rd12(&mfF40);
    if (version == 1) {
        uint8_t b;
        s->Rd05(&b);
        mfF44 = b * 0.01f;
    } else {
        float f;
        s->Rd12(&f);
        mfF44 = f;
    }
    bool r = !s->Fn18();
    return r;
}

union FloatBits_aa2758 {
    float f;
    int32_t i;
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d4e60 score 22 (identical instructions; the dead-zone branch is laid out differently)
void cSC4Demand::CalculateActiveDemand(bool snap)
{
    float d = mfTarget - mfPos;
    if (d > mfMax) {
        d = mfMax;
    } else if (d < mfMin) {
        d = mfMin;
    }
    float s = mfF40 + mfF3c;
    float a = s * mfMax;
    float b = s * mfTarget;
    if (a > b) {
        a = b;
    }
    float r = a + d;
    if (r > mfMax) {
        r = mfMax;
    } else if (r < mfMin) {
        r = mfMin;
    }
    float mx = mfMax;
    float t = mx - mx * mfF44;
    if (r > t) {
        r = t;
    }
    if (r < mfMin) {
        r = mfMin;
    }
    if (snap) {
        float step = (mfMax - mfMin) * 0.07f;
        float diff = r - mfValue;
        if (diff < step && diff > -step) {
            goto store;
        }
        if (diff > 0.0f) {
            if (r > 0.0f && mfValue < 0.0f && step + mfValue < 0.0f) {
                mfValue = 0.0f;
                goto done;
            }
            r = step + mfValue;
        } else {
            if (r < 0.0f && mfValue > 0.0f && mfValue - step > 0.0f) {
                mfValue = 0.0f;
                goto done;
            }
            r = mfValue - step;
        }
    }
store:
    mfValue = r;
done:
    FloatBits_aa2758 u;
    if (mfValue < 0.0f) {
        u.f = 12582912.0f - mfValue / mfMin * 1000.0f;
    } else {
        u.f = mfValue / mfMax * 1000.0f + 12582912.0f;
    }
    int32_t n = u.i - 0x4b400000;
    cMade_aa2758* m = new cMade_aa2758;
    m->AddRef();
    m->Fn05(0x426840a0);
    m->Fn11(mnId);
    m->Fn16(n);
    static_cast<cB43ccc_aa2758*>(mpB)->Fn04(m, 0);
    m->Release();
}
#endif
