#include <cstring>
#include <vector>

#include "gzcom/cRZString.h"
#include "classes/cSC4WinLotConfigurationEditor.h"
#include "classes/cUnk00a8d424.h"
#include "classes/cUnk00a8d4e0.h"
#include "classes/cUnk00ac7630.h"

// A rectangle of floats (left/right style pairs at +4 and +0xc are used by the editor).
struct Rect_a8d888 {
    float f0;
    float f4;
    float f8;
    float fc;
};

// The lot configuration manager (global 0x00b43d18).
struct Counted_a8d888;
struct CfgMgr_a8d888 {
    virtual void P0(); virtual void P1(); virtual void P2(); virtual void P3();
    virtual void P4(); virtual void P5(); virtual void P6(); virtual void P7();
    virtual Counted_a8d888* Lookup(uint32_t id);
    // STUB: 0x00489700
    bool WriteLotConfiguration(void* key, void* config, void* segment);
};
// GLOBAL: 0x00b43d18
extern CfgMgr_a8d888* gpB43d18_a8d888;

// A reference counted object held by the editor (field 0x15c).
struct Counted_a8d888 {
    virtual bool Qi(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual uint32_t Fn3();
};

// A child view of the chooser (field 0x12c); only the slot the chooser calls.
struct ChildView_a8d4e0 {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual void S8();
    virtual void S9();
    virtual void S10();
    virtual void S11();
    virtual void S12();
    virtual void S13();
    virtual void S14();
    virtual void S15();
    virtual void S16();
    virtual void S17();
    virtual void S18();
    virtual void S19();
    virtual void S20();
    virtual void S21();
    virtual void S22();
    virtual void S23();
    virtual void S24();
    virtual void S25();
    virtual void S26();
    virtual void S27();
    virtual void S28();
    virtual void S29();
    virtual void S30();
    virtual void S31();
    virtual void S32();
    virtual void S33();
    virtual void S34();
    virtual void S35();
    virtual void S36();
    virtual void S37();
    virtual void S38();
    virtual void S39();
    virtual void S40();
    virtual void S41();
    virtual void S42();
    virtual void S43();
    virtual void S44();
    virtual void S45();
    virtual void S46();
    virtual void S47();
    virtual void S48();
    virtual void S49();
    virtual void S50();
    virtual void S51();
    virtual void S52();
    virtual void S53();
    virtual void S54();
    virtual void S55();
    virtual void S56();
    virtual void S57();
    virtual void S58();
    virtual void S59();
    virtual void S60();
    virtual void S61();
    virtual void S62();
    virtual void S63();
    virtual void S64();
    virtual void S65();
    virtual void S66();
    virtual void S67();
    virtual void S68();
    virtual void S69();
    virtual void S70();
    virtual void S71();
    virtual void S72();
    virtual void S73();
    virtual void S74();
    virtual void S75();
    virtual void S76();
    virtual void S77();
    virtual void S78();
    virtual void S79();
    virtual void S80();
    virtual void S81();
    virtual void S82();
    virtual void S83();
    virtual void S84();
    virtual void S85();
    virtual void S86();
    virtual void S87();
    virtual void S88();
    virtual void S89();
    virtual void S90();
    virtual void S91();
    virtual void S92();
    virtual void S93();
    virtual void S94();
    virtual void S95();
    virtual void S96();
    virtual void S97();
    virtual void S98();
    virtual void S99();
    virtual void S100();
    virtual void S101();
    virtual void S102();
    virtual void S103();
    virtual void S104();
    virtual void S105();
    virtual void S106();
    virtual void S107();
    virtual void S108();
    virtual void S109();
    virtual void S110();
    virtual void S111();
    virtual void S112();
    virtual void S113();
    virtual void S114();
    virtual void S115();
    virtual void S116();
    virtual void S117();
    virtual void S118();
    virtual void S119();
    virtual void S120();
    virtual void S121();
    virtual void S122();
    virtual void S123();
    virtual void S124();
    virtual void S125();
    virtual void S126();
    virtual void S127();
    virtual void S128();
    virtual void S129();
    virtual void S130();
    virtual void Fn20c(uint32_t, uint32_t, uint32_t, uint32_t);
};

// A small node: its text buffer at +0xc is freed with it.
struct Node_a8d888 {
    uint32_t f0;
    uint32_t f4;
    uint32_t mVt8;
    void* mpBuf;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);
// STUB: 0x0051ff00
uint32_t Fn0051ff00(uint32_t, uint32_t, uint32_t, char*, uint32_t);

// FUNCTION: 0x00480590
void cSC4WinLotConfigurationEditor::SetDataHasChanged(bool b)
{
    mbDataChanged12c = b;
    SetTitle();
}

// FUNCTION: 0x0047e870
void cSC4WinLotConfigurationEditor::TriggerLotConfigurationRedraw()
{
    Fn0047e060();
    InvalidateSelfAndParents();
}

// FUNCTION: 0x00485280
uint32_t Fn00485280(uint32_t a, uint32_t b, uint32_t c)
{
    char flag;
    return Fn0051ff00(a, b, c, &flag, 0);
}

// FUNCTION: 0x0047a8c0
void cSC4WinLotConfigurationEditor::CycleViewMode()
{
    if (++mnViewMode1dc == 7) {
        mnViewMode1dc = 0;
    }
    Refresh3DView();
}

// FUNCTION: 0x0047b0a0
void cSC4WinLotConfigurationEditor::Fn0047b0a0()
{
    if (mnCursorMode19c != 4) {
        mnCursorMode19c = 4;
        SetCursor(mCursor150, 1);
    }
}

// FUNCTION: 0x0047b0d0
void cSC4WinLotConfigurationEditor::Fn0047b0d0()
{
    if (mnCursorMode19c != 8) {
        mnCursorMode19c = 8;
        SetCursor(mCursor158, 1);
    }
}

// FUNCTION: 0x0047a890
bool cSC4WinLotConfigurationEditor::DoEditMouseUpL(int32_t /*x*/, int32_t /*y*/, uint32_t /*flags*/)
{
    if (mbCapturing1b8) {
        mbCapturing1b8 = 0;
        if (GZAmCapturing()) {
            GZReleaseCapture();
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0047ab70 score 8
bool cSC4WinLotConfigurationEditor::WriteLotData()
{
    CfgMgr_a8d888* m = gpB43d18_a8d888;
    if (m) {
        return m->WriteLotConfiguration(&mKey168, mpConfig190, mpSegment188);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0047aa00 score 4
bool cUnk00a8d424::Slot04_aa42c8(uint32_t id)
{
    if (id == 0x278128a0 || id == 0x74758926 || id == 0xa823821e || id == 0xc772bf98) {
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0047ea10 score 4
void OB_STDCALL Fn0047ea10(Node_a8d888* p)
{
    p->mVt8 = 0xa80810;
    if (p->mpBuf) {
        Fn0090cf63(p->mpBuf);
    }
    if (p) {
        Fn0090cf63(p);
    }
}
#endif

// FUNCTION: 0x0047aaf0
void cUnk00a8d4e0::Fn0047aaf0(uint32_t a, uint32_t b)
{
    if (mpWin12c) {
        mn14c = a;
        mn150 = b;
        static_cast<ChildView_a8d4e0*>(mpWin12c)->Fn20c(a, b, 1, 0);
    }
}

// FUNCTION: 0x0047a8f0
void cSC4WinLotConfigurationEditor::Fn0047a8f0(void* rect, int32_t x, int32_t y, void* outX, void* outY)
{
    Rect_a8d888* r = static_cast<Rect_a8d888*>(rect);
    float* px = static_cast<float*>(outX);
    float* py = static_cast<float*>(outY);
    *px = x * mfScale1ac;
    *py = y * mfScale1ac;
    *px = *px - r->f4;
    *py = *py - r->fc;
}

// FUNCTION: 0x0047ab30
void cSC4WinLotConfigurationEditor::Fn0047ab30(void* p)
{
    Counted_a8d888* old = static_cast<Counted_a8d888*>(mpOwner15c);
    Counted_a8d888* n = static_cast<Counted_a8d888*>(p);
    if (n != old) {
        if (n) {
            n->AddRef();
        }
        mpOwner15c = n;
        if (old) {
            old->Release();
        }
    }
}

// FUNCTION: 0x00484dd0
void cSC4WinLotConfigurationEditor::MirrorObject(void* obj, uint32_t /*b*/, uint32_t /*c*/)
{
    uint8_t* o = static_cast<uint8_t*>(obj);
    if (o[0] == 2) {
        o[3] = (o[3] == 0);
        mbDataChanged12c = 1;
        SetTitle();
        TriggerLotConfigurationRedraw();
    }
}

// STUB: 0x0090fcef
uint32_t Fn0090fcef(const char* s);

// A list cell as the sorted lists hold it: a string object at +0xc.
struct Str_a8d888 {
    uint32_t f0;
    uint32_t mpChars;
};
struct Cell_a8d888 {
    uint32_t f0;
    uint32_t f4;
    uint32_t f8;
    uint32_t mpStr;
};

// STUB: 0x0047b050
int Fn0047b050(Cell_a8d888* a, Cell_a8d888* b);

#ifdef OB_DRAFTS
// CLOSE: 0x0047b050 score 12
int Fn0047b050Draft_a8d888(Cell_a8d888* a, Cell_a8d888* b)
{
    uint32_t x = Fn0090fcef(OB_PTR(const char, OB_PTR(Str_a8d888, a->mpStr)->mpChars));
    uint32_t y = Fn0090fcef(OB_PTR(const char, OB_PTR(Str_a8d888, b->mpStr)->mpChars));
    int d = static_cast<int>(x & 0xf000) - static_cast<int>(y & 0xf000);
    if (d != 0) {
        return d;
    }
    return y < x ? 1 : -1;
}
#endif

// A lot configuration's record list (vector of 0x34 byte records at +0x90).
struct Rec_a8d888 {
    uint8_t mType;
    uint8_t pad[0x1f];
    uint32_t mf20;
    uint8_t pad2[0x10];
};
struct Config_a8d888 {
    uint8_t pad[0x20];
    uint8_t mW;
    uint8_t mH;
    uint8_t pad2[0x6e];
    uint32_t mRecBegin;
    uint32_t mRecEnd;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0047b420 score 33
uint32_t cSC4WinLotConfigurationEditor::Fn0047b420()
{
    Config_a8d888* c = static_cast<Config_a8d888*>(mpConfig190);
    int n = static_cast<int>(c->mRecEnd - c->mRecBegin) / 0x34;
    for (int i = 0; i < n; i++) {
        Rec_a8d888* r = OB_PTR(Rec_a8d888, c->mRecBegin) + i;
        if (r->mType == 3) {
            return r->mf20;
        }
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0047ba80 score 14
bool cSC4WinLotConfigurationEditor::DoMessage(uint32_t m)
{
    uint32_t* msg = OB_PTR(uint32_t, m);
    switch (msg[0]) {
    case 3:
        if (msg[1] == 0x287259f6 && msg[2] == 0x42b7c353) {
            Close(1, 1);
        }
        break;
    case 0x920b687:
        PostInit();
        break;
    default:
        return cGZWinGen::DoMessage(m);
    }
    return true;
}
#endif


// FUNCTION: 0x004838c0
bool cSC4WinLotConfigurationEditor::DoSelectLotBaseTexturesUI(void* a, void* b)
{
    std::vector<uint32_t> v;
    Fn0047fc50(&v);
    bool r = DoSelectTexturesUI(a, b, reinterpret_cast<void*>(&Fn0047b050));
    return r;
}

// The vector of picked ids the editor keeps at +0x1a0.
inline std::vector<uint32_t>& IdsOf_a8d888(uint8_t* p)
{
    return *reinterpret_cast<std::vector<uint32_t>*>(p);
}

// FUNCTION: 0x0047c8d0
void cSC4WinLotConfigurationEditor::Fn0047c8d0()
{
    if (mnCursorMode19c != 6) {
        IdsOf_a8d888(mVec1a0).clear();
        mnCursorMode19c = 6;
        SetCursor(mCursor14c, 1);
    }
}

// FUNCTION: 0x0047c930
void cSC4WinLotConfigurationEditor::Fn0047c930()
{
    if (mnCursorMode19c != 7) {
        IdsOf_a8d888(mVec1a0).clear();
        mnCursorMode19c = 7;
        SetCursor(mCursor14c, 1);
    }
}

// FUNCTION: 0x00483920
void cSC4WinLotConfigurationEditor::DoAddNewBuilding()
{
    if (mnCursorMode19c != 1) {
        std::vector<uint32_t>& v = IdsOf_a8d888(mVec1a0);
        v.clear();
        if (DoSelectBuildingFamiliesUI(&v, 0) && !v.empty()) {
            mnCursorMode19c = 1;
            SetCursor(mCursor144, 1);
        }
    }
}

// FUNCTION: 0x004839a0
void cSC4WinLotConfigurationEditor::DoAddNewFlora()
{
    if (mnCursorMode19c != 2) {
        std::vector<uint32_t>& v = IdsOf_a8d888(mVec1a0);
        v.clear();
        if (DoSelectFloraFamiliesUI(&v, 0) && !v.empty()) {
            mnCursorMode19c = 2;
            SetCursor(mCursor148, 1);
        }
    }
}

// FUNCTION: 0x00483a20
void cSC4WinLotConfigurationEditor::DoAddNewProp(bool a, bool b)
{
    if (mnCursorMode19c != 3) {
        std::vector<uint32_t>& v = IdsOf_a8d888(mVec1a0);
        v.clear();
        if (DoSelectPropFamiliesUI(&v, 0, a, b) && !v.empty()) {
            mnCursorMode19c = 3;
            SetCursor(mCursor14c, 1);
        }
    }
}

// FUNCTION: 0x00483aa0
void cSC4WinLotConfigurationEditor::DoAddNewLotBaseTexture()
{
    if (mnCursorMode19c != 5) {
        std::vector<uint32_t>& v = IdsOf_a8d888(mVec1a0);
        v.clear();
        if (DoSelectLotBaseTexturesUI(&v, 0) && !v.empty()) {
            mnCursorMode19c = 5;
            SetCursor(mCursor154, 1);
        }
    }
}

struct Obj_a8d888;
// STUB: 0x0047b2a0
bool OB_STDCALL Fn0047b2a0(Obj_a8d888* o, Rect_a8d888* r);

// A placed object of the lot configuration (type, rotation, flip, then its bounds).
struct Obj_a8d888 {
    uint8_t mType;
    uint8_t mb1;
    uint8_t mRot;
    uint8_t mFlip;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00484d40 score 2
void cSC4WinLotConfigurationEditor::RotateObject(void* obj, uint32_t b, uint32_t c)
{
    Obj_a8d888* o = static_cast<Obj_a8d888*>(obj);
    uint8_t r = o->mRot + 1;
    o->mRot = r % 4;
    float w = o->f10 - o->f18;
    float h = o->f14 - o->f1c;
    float hh = h * 0.5f;
    o->f18 = o->f4 - hh;
    float wh = w * 0.5f;
    o->f1c = o->fc - wh;
    o->f10 = hh + o->f4;
    o->f14 = wh + o->fc;
    mbDataChanged12c = 1;
    SetTitle();
    TriggerLotConfigurationRedraw();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004851b0 score 12
void cSC4WinLotConfigurationEditor::MoveObjectF(void* obj, float x, float y)
{
    Obj_a8d888* o = static_cast<Obj_a8d888*>(obj);
    float dx = x - o->f4;
    float dy = y - o->fc;
    o->f4 = o->f4 + dx;
    o->fc = o->fc + dy;
    o->f18 = o->f18 + dx;
    o->f10 = o->f10 + dx;
    o->f1c = o->f1c + dy;
    o->f14 = o->f14 + dy;
    MoveObjectToWithinLotBounds(o, o->mType != 4);
    mbDataChanged12c = 1;
    SetTitle();
    TriggerLotConfigurationRedraw();
}
#endif

// STUB: 0x00891ae4
bool Fn00891ae4(uint32_t key);

#ifdef OB_DRAFTS
// CLOSE: 0x00485040 score 88
void cSC4WinLotConfigurationEditor::MoveObject(void* obj, uint32_t key, uint32_t flags)
{
    Obj_a8d888* o = static_cast<Obj_a8d888*>(obj);
    float step = 0.25f;
    if (flags & 2) {
        step = 0.5f;
    }
    if (flags & 1) {
        step = step * 4.0f;
    }
    if ((flags >> 2) & 1) {
        step = step * 8.0f;
    }
    if (key == 0x25) {
        o->f4 = o->f4 - step;
        o->f18 = o->f18 - step;
        o->f10 = o->f10 - step;
    } else if (key == 0x26) {
        if (Fn00891ae4(0x20)) {
            if (o->mType == 1) {
                o->f8 = step + o->f8;
            }
        } else {
            o->fc = o->fc - step;
            o->f1c = o->f1c - step;
            o->f14 = o->f14 - step;
        }
    } else if (key == 0x27) {
        o->f4 = step + o->f4;
        o->f18 = step + o->f18;
        o->f10 = step + o->f10;
    } else if (key == 0x28) {
        if (Fn00891ae4(0x20)) {
            if (o->mType == 1) {
                o->f8 = o->f8 - step;
            }
        } else {
            o->fc = step + o->fc;
            o->f1c = step + o->f1c;
            o->f14 = step + o->f14;
        }
    }
    MoveObjectToWithinLotBounds(o, o->mType != 4);
    mbDataChanged12c = 1;
    SetTitle();
    TriggerLotConfigurationRedraw();
}
#endif

inline uint32_t CountOf_a8d888(Config_a8d888* c)
{
    return static_cast<uint32_t>(static_cast<int>(c->mRecEnd - c->mRecBegin) / 0x34);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0047b100 score 25
void cSC4WinLotConfigurationEditor::SetSelectedLotConfigurationObject(void* obj)
{
    if (mpSelected1b0 != obj) {
        if (mbCapturing1b8) {
            mbCapturing1b8 = 0;
            if (GZAmCapturing()) {
                GZReleaseCapture();
            }
        }
        mpSelected1b0 = obj;
        if (obj != 0) {
            mnSelected1b4 = -1;
            for (uint32_t i = 0; i < CountOf_a8d888(static_cast<Config_a8d888*>(mpConfig190)); i++) {
                Config_a8d888* c = static_cast<Config_a8d888*>(mpConfig190);
                if (obj == OB_PTR(Rec_a8d888, c->mRecBegin) + i) {
                    mnSelected1b4 = i;
                }
            }
            if (mnSelected1b4 != -1) {
                return;
            }
        }
        mnSelected1b4 = 0;
    }
}
#endif

// STUB: 0x0047b1f0
bool Fn0047b1f0(void* key, void* info);

#ifdef OB_DRAFTS
// CLOSE: 0x00486530
bool cSC4WinLotConfigurationEditor::Open(void* key)
{
    PostInit();
    uint32_t* k = static_cast<uint32_t*>(key);
    bool ok;
    if (*k == 0) {
        ok = CreateNewLotConfiguration();
    } else {
        ok = ReadLotConfigurationExemplar(OB_ADDR(key));
    }
    if (!ok) {
        return false;
    }
    if (*k != 0) {
        if (!Fn0047b1f0(key, &mIdentity164)) {
            return false;
        }
    }
    SetTitle();
    Config_a8d888* c = static_cast<Config_a8d888*>(mpConfig190);
    SetLotSize(c->mW, c->mH, false);
    Fn00484330();
    Fn0047bba0();
    GoTo3DView();
    Refresh3DView();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0047b2a0 score 39
bool OB_STDCALL Fn0047b2a0Draft_a8d888(Obj_a8d888* o, Rect_a8d888* r)
{
    float right = o->f10;
    float top = o->f14;
    float bottom = o->f1c;
    if (o->f18 <= r->f8 && r->f0 <= right && r->fc >= bottom && r->f4 <= top) {
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0047b310 score 24
void cSC4WinLotConfigurationEditor::Fn0047b310(void* obj, void* out)
{
    Obj_a8d888* o = static_cast<Obj_a8d888*>(obj);
    int32_t* r = static_cast<int32_t*>(out);
    float a = o->f1c;
    float b = o->f10;
    float c = o->f14;
    r[0] = static_cast<int32_t>(o->f18 / mfScale1ac);
    r[1] = static_cast<int32_t>(a / mfScale1ac);
    r[2] = static_cast<int32_t>(b / mfScale1ac);
    r[3] = static_cast<int32_t>(c / mfScale1ac);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0047b390 score 10
void cSC4WinLotConfigurationEditor::Fn0047b390(void* out)
{
    Config_a8d888* c = static_cast<Config_a8d888*>(mpConfig190);
    float w = static_cast<float>(c->mW << 4);
    float h = static_cast<float>(c->mH << 4);
    int32_t* r = static_cast<int32_t*>(out);
    r[0] = static_cast<int32_t>(0.0f / mfScale1ac);
    r[1] = static_cast<int32_t>(0.0f / mfScale1ac);
    r[2] = static_cast<int32_t>(w / mfScale1ac);
    r[3] = static_cast<int32_t>(h / mfScale1ac);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0047b640 score 32
bool cSC4WinLotConfigurationEditor::Fn0047b640(void* obj, bool flag)
{
    Obj_a8d888* o = static_cast<Obj_a8d888*>(obj);
    Config_a8d888* c = static_cast<Config_a8d888*>(mpConfig190);
    float w = static_cast<float>(c->mW << 4);
    float h = static_cast<float>(c->mH << 4);
    if (flag) {
        if (o->f18 >= 0.0f && o->f1c >= 0.0f && o->f10 <= w && o->f14 <= h) {
            return true;
        }
        return false;
    }
    if (o->f10 >= 0.0f && o->f14 >= 0.0f && o->f18 <= w && o->f1c <= h) {
        return true;
    }
    return false;
}
#endif

// The object at field 0x138 hands out the view the editor draws in (slot 3).
struct Holder_a8d888 {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void* GetView();
};

// FUNCTION: 0x0047ad40
bool cSC4WinLotConfigurationEditor::GZOnMouseUpL(uint32_t x, uint32_t y, uint32_t flags)
{
    cGZWin* v = static_cast<cGZWin*>(static_cast<Holder_a8d888*>(mpHolder138)->GetView());
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) + 0xe0) != 0) {
        return cGZWinGen::GZOnMouseUpL(x, y, flags);
    }
    WindowToWindowCoordinates(OB_ADDR(v), OB_ADDR(&x), OB_ADDR(&y));
    if (static_cast<int32_t>(x) >= 0 && static_cast<int32_t>(y) >= 0 && static_cast<int32_t>(x) < static_cast<int32_t>(v->GetW()) && static_cast<int32_t>(y) < static_cast<int32_t>(v->GetH())) {
        DoEditMouseUpL(x, y, flags);
    } else {
        cGZWin* v2 = static_cast<cGZWin*>(static_cast<Holder_a8d888*>(mpHolder138)->GetView());
        v2->WindowToWindowCoordinates(OB_ADDR(this), OB_ADDR(&x), OB_ADDR(&y));
        cGZWinGen::GZOnMouseUpL(x, y, flags);
    }
    return true;
}

// FUNCTION: 0x00487100
bool cSC4WinLotConfigurationEditor::GZOnMouseDownL(uint32_t x, uint32_t y, uint32_t flags)
{
    cGZWin* v = static_cast<cGZWin*>(static_cast<Holder_a8d888*>(mpHolder138)->GetView());
    WindowToWindowCoordinates(OB_ADDR(v), OB_ADDR(&x), OB_ADDR(&y));
    if (static_cast<int32_t>(x) >= 0 && static_cast<int32_t>(y) >= 0 && static_cast<int32_t>(x) < static_cast<int32_t>(v->GetW()) && static_cast<int32_t>(y) < static_cast<int32_t>(v->GetH())) {
        Fn00486770(x, y, flags);
        return true;
    }
    cGZWin* v2 = static_cast<cGZWin*>(static_cast<Holder_a8d888*>(mpHolder138)->GetView());
    v2->WindowToWindowCoordinates(OB_ADDR(this), OB_ADDR(&x), OB_ADDR(&y));
    cGZWinGen::GZOnMouseDownL(x, y, flags);
    return true;
}

// FUNCTION: 0x004895a0
bool cSC4WinLotConfigurationEditor::GZOnMouseDownR(uint32_t x, uint32_t y, uint32_t flags)
{
    cGZWin* v = static_cast<cGZWin*>(static_cast<Holder_a8d888*>(mpHolder138)->GetView());
    WindowToWindowCoordinates(OB_ADDR(v), OB_ADDR(&x), OB_ADDR(&y));
    if (static_cast<int32_t>(x) >= 0 && static_cast<int32_t>(y) >= 0 && static_cast<int32_t>(x) < static_cast<int32_t>(v->GetW()) && static_cast<int32_t>(y) < static_cast<int32_t>(v->GetH())) {
        Fn004893e0(x, y, flags);
        return true;
    }
    cGZWin* v2 = static_cast<cGZWin*>(static_cast<Holder_a8d888*>(mpHolder138)->GetView());
    v2->WindowToWindowCoordinates(OB_ADDR(this), OB_ADDR(&x), OB_ADDR(&y));
    DoOutsideAreaMenu(x, y);
    return true;
}

// The status line (field 0x13c): slot 4 takes the string to show.
struct Status_a8d888 {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void SetText(cRZString* text);
};

// FUNCTION: 0x00486690
bool cSC4WinLotConfigurationEditor::GZOnMouseMove(uint32_t x, uint32_t y, uint32_t flags)
{
    cGZWin* v = static_cast<cGZWin*>(static_cast<Holder_a8d888*>(mpHolder138)->GetView());
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(this) + 0xe0) != 0) {
        return cGZWinGen::GZOnMouseMove(x, y, flags);
    }
    WindowToWindowCoordinates(OB_ADDR(v), OB_ADDR(&x), OB_ADDR(&y));
    if (static_cast<int32_t>(x) >= 0 && static_cast<int32_t>(y) >= 0 && static_cast<int32_t>(x) < static_cast<int32_t>(v->GetW()) && static_cast<int32_t>(y) < static_cast<int32_t>(v->GetH())) {
        DoEditMouseMove(x, y, flags);
    } else {
        cGZWin* v2 = static_cast<cGZWin*>(static_cast<Holder_a8d888*>(mpHolder138)->GetView());
        v2->WindowToWindowCoordinates(OB_ADDR(this), OB_ADDR(&x), OB_ADDR(&y));
        cGZWinGen::GZOnMouseMove(x, y, flags);
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004859e0 score 54
bool cSC4WinLotConfigurationEditor::DoEditMouseMove(int32_t x, int32_t y, uint32_t flags)
{
    if (mbCapturing1b8 != 0) {
        if (GZAmCapturing()) {
            Obj_a8d888* o = static_cast<Obj_a8d888*>(mpSelected1b0);
            float ax;
            float ay;
            Fn0047a8f0(o, x, y, &ax, &ay);
            MoveObjectF(o, (ax - mfGrabX1bc) + o->f4, (ay - mfGrabY1c0) + o->fc);
        }
    }
    cRZString text;
    Obj_a8d888* sel = static_cast<Obj_a8d888*>(mpSelected1b0);
    uint32_t id = 0;
    if (sel != 0) {
        id = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(sel) + 0x24);
    }
    text.Sprintf("%08x: Pixel: (%d,%d) World: (%.1f,%.1f)", id, x, y, static_cast<double>(x * mfScale1ac), static_cast<double>(y * mfScale1ac));
    static_cast<Status_a8d888*>(mpStatus13c)->SetText(&text);
    return true;
}
#endif

// FUNCTION: 0x0047a930
void OB_STDCALL Fn0047a930(Obj_a8d888* o, uint8_t* r, uint8_t* g, uint8_t* b, float* alpha)
{
    *alpha = 0.5f;
    switch (o->mType) {
    case 0:
        *r = 0;
        *g = 0;
        *b = 0x80;
        break;
    case 1:
        *r = 0x80;
        *g = 0;
        *b = 0x80;
        break;
    case 2:
        *r = 0;
        *g = 0x80;
        *b = 0x80;
        break;
    case 3:
        *r = 0;
        *g = 0x48;
        *b = 0x48;
        break;
    case 4:
        *r = 0;
        *g = 0x80;
        *b = 0;
        break;
    default:
        *r = 0x80;
        *g = 0x80;
        *b = 0x80;
        break;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0047b480 score 94
void cSC4WinLotConfigurationEditor::MoveObjectToWithinLotBounds(void* obj, bool flag)
{
    Obj_a8d888* o = static_cast<Obj_a8d888*>(obj);
    Config_a8d888* c = static_cast<Config_a8d888*>(mpConfig190);
    float w = static_cast<float>(c->mW << 4);
    float h = static_cast<float>(c->mH << 4);
    if (flag) {
        if (o->f18 < 0.05f) {
            float d = 0.05f - o->f18;
            o->f4 = d + o->f4;
            o->f18 = d + o->f18;
            o->f10 = d + o->f10;
        }
        if (o->f1c < 0.05f) {
            float d = 0.05f - o->f1c;
            o->fc = d + o->fc;
            o->f1c = d + o->f1c;
            o->f14 = d + o->f14;
        }
        if (w - 0.05f < o->f10) {
            float d = o->f10 - (w - 0.05f);
            o->f4 = o->f4 - d;
            o->f18 = o->f18 - d;
            o->f10 = o->f10 - d;
        }
        if (h - 0.05f < o->f14) {
            float d = o->f14 - (h - 0.05f);
            o->fc = o->fc - d;
            o->f1c = o->f1c - d;
            o->f14 = o->f14 - d;
        }
    } else {
        float x = o->f4;
        if (x < 0.05f) {
            float d = 0.05f - x;
            x = x + d;
            o->f4 = x;
            o->f18 = d + o->f18;
            o->f10 = d + o->f10;
        }
        float y = o->fc;
        if (y < 0.05f) {
            float d = 0.05f - y;
            y = y + d;
            o->fc = y;
            o->f1c = d + o->f1c;
            o->f14 = d + o->f14;
        }
        if (w - 0.05f < x) {
            float d = x - (w - 0.05f);
            o->f4 = x - d;
            o->f18 = o->f18 - d;
            o->f10 = o->f10 - d;
        }
        if (h - 0.05f < y) {
            float d = y - (h - 0.05f);
            o->fc = y - d;
            o->f1c = o->f1c - d;
            o->f14 = o->f14 - d;
        }
    }
    if (o->f4 < 0.0f) {
        o->f4 = 0.0f;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0047bb40 score 21
bool cSC4WinLotConfigurationEditor::Fn0047bb40(void* obj)
{
    Config_a8d888* c = static_cast<Config_a8d888*>(mpConfig190);
    float w = static_cast<float>(c->mW << 4);
    float h = static_cast<float>(c->mH << 4);
    Rect_a8d888 r;
    r.f0 = 0.0f;
    r.f4 = 0.0f;
    r.f8 = w;
    r.fc = h;
    return Fn0047b2a0(static_cast<Obj_a8d888*>(obj), &r);
}
#endif

// ---- Agent 2 additions ----

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);
// STUB: 0x0049a7f0
uint32_t Fn0049a7f0();
// STUB: 0x004f0940
void OB_STDCALL Fn004f0940(uint32_t n);
// STUB: 0x0090fe93
void* Fn0090fe93(uint32_t v);
// STUB: 0x0047d870
void Fn0047d870(uint32_t* first, uint32_t* last, void* cmp);
// STUB: 0x0047b810
void Fn0047b810(uint32_t* first, uint32_t* last, uint32_t n, void* cmp);
// STUB: 0x0047ea40
void Fn0047ea40(uint32_t* first, uint32_t* last, uint32_t n, uint32_t depth, void* cmp);
// STUB: 0x00611840
uint32_t* Fn00611840(uint32_t* first, uint32_t* last, uint32_t pivot, void* cmp);
// STUB: 0x0048a4b0
void Fn0048a4b0(uint32_t* first, uint32_t* mid, uint32_t* last, uint32_t n, void* cmp);
// STUB: 0x00602230
void Fn00602230(void* p);
// STUB: 0x00408480
void Fn00408480(void* self, const char* s);

// A string object as the hash nodes hold it.
struct StrObj_a8d888 {
    void* mpBegin;
    // STUB: 0x004089b0
    void Ctor(const void* src, uint32_t pos, int32_t n, void* alloc);
    // STUB: 0x00408a70
    void Assign(const void* first, const void* last, void* alloc);
};

// A hash node: next, key, then a value (vtable word, string, tail).
struct HNode_a8d888 {
    HNode_a8d888* mpNext;
    uint32_t mnKey;
    uint32_t mVt8;
    StrObj_a8d888 mStr;
    uint32_t mnTail;
};

// A key record with its string.
struct HRec_a8d888 {
    uint32_t mnKey;
    StrObj_a8d888 mStr;
};

// A hash table: buckets as a vector at +4, element count at +0x10.
struct HTable_a8d888 {
    uint32_t f0;
    HNode_a8d888** mpBegin;
    HNode_a8d888** mpEnd;
    HNode_a8d888** mpCap;
    uint32_t mnCount;
    // STUB: 0x00480400
    HNode_a8d888* NewNode(HRec_a8d888* rec);
    // STUB: 0x00485230
    uint32_t* Insert(HRec_a8d888* rec);
    // STUB: 0x004862f0
    void* FindOrInsert(uint32_t* key);
    void Clear();
};

struct HIter_a8d888 {
    HNode_a8d888* mpCur;
    HTable_a8d888* mpTab;
    HNode_a8d888* NextBucket();
};

// A set node (red-black tree): +4 parent, +8 left, +0xc right, +0x10 the value.
struct TNode_a8d888 {
    uint32_t f0;
    TNode_a8d888* mpParent;
    TNode_a8d888* mpLeft;
    TNode_a8d888* mpRight;
    void* mpVal;
};

// Entries of the chooser's set: the part that has a selection id at +0x164.
struct Sel_a8d888 {
    uint8_t pad[0x164];
    uint32_t mnId;
};

// A window-like object: slot 2 releases, slot 5 takes a flag.
struct Win_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void Release2();
    virtual void P3();
    virtual void P4();
    virtual void Flag5(uint32_t);
};

// A tree value with a bool slot at 0x264.
struct Item_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
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
    virtual void P65();
    virtual void P66();
    virtual void P67();
    virtual void P68();
    virtual void P69();
    virtual void P70();
    virtual void P71();
    virtual void P72();
    virtual void P73();
    virtual void P74();
    virtual void P75();
    virtual void P76();
    virtual void P77();
    virtual void P78();
    virtual void P79();
    virtual void P80();
    virtual void P81();
    virtual void P82();
    virtual void P83();
    virtual void P84();
    virtual void P85();
    virtual void P86();
    virtual void P87();
    virtual void P88();
    virtual void P89();
    virtual void P90();
    virtual void P91();
    virtual void P92();
    virtual void P93();
    virtual void P94();
    virtual void P95();
    virtual void P96();
    virtual void P97();
    virtual void P98();
    virtual void P99();
    virtual void P100();
    virtual void P101();
    virtual void P102();
    virtual void P103();
    virtual void P104();
    virtual void P105();
    virtual void P106();
    virtual void P107();
    virtual void P108();
    virtual void P109();
    virtual void P110();
    virtual void P111();
    virtual void P112();
    virtual void P113();
    virtual void P114();
    virtual void P115();
    virtual void P116();
    virtual void P117();
    virtual void P118();
    virtual void P119();
    virtual void P120();
    virtual void P121();
    virtual void P122();
    virtual void P123();
    virtual void P124();
    virtual void P125();
    virtual void P126();
    virtual void P127();
    virtual void P128();
    virtual void P129();
    virtual void P130();
    virtual void P131();
    virtual void P132();
    virtual void P133();
    virtual void P134();
    virtual void P135();
    virtual void P136();
    virtual void P137();
    virtual void P138();
    virtual void P139();
    virtual void P140();
    virtual void P141();
    virtual void P142();
    virtual void P143();
    virtual void P144();
    virtual void P145();
    virtual void P146();
    virtual void P147();
    virtual void P148();
    virtual void P149();
    virtual void P150();
    virtual void P151();
    virtual void P152();
    virtual bool Fn264(uint32_t, uint32_t);
};

// The chooser as a flat view (fields 0x128..0x150).
struct Chooser_a8d888 {
    uint8_t pad0[0x128];
    Win_a8d888* mpWin128;
    Win_a8d888* mpWin12c;
    Win_a8d888* mpWin130;
    TNode_a8d888* mpSet134;
    uint32_t mnSetCount138;
    uint8_t pad13c[4];
    TNode_a8d888* mpSet140;
    uint32_t mnSetCount144;
    uint32_t Fn0047c150();
    bool Fn0047d940();
    void Fn0047c4b0(void* key);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0047c1a0 score 43
HNode_a8d888* HIter_a8d888::NextBucket()
{
    HTable_a8d888* t = mpTab;
    uint32_t n = mpCur->mnKey >> 2;
    uint32_t idx = n % static_cast<uint32_t>(t->mpEnd - t->mpBegin);
    HNode_a8d888* r = 0;
    for (;;) {
        ++idx;
        if (idx >= static_cast<uint32_t>(mpTab->mpEnd - mpTab->mpBegin)) {
            break;
        }
        r = mpTab->mpBegin[idx];
        if (r) {
            break;
        }
    }
    return r;
}
#endif

// A 0x2c-byte record: a string-like buffer at +0x14 and a vtable word at +0x10.
struct Rec2c_a8d888 {
    uint32_t f0;
    uint32_t f4;
    uint32_t f8;
    uint32_t fc;
    uint32_t mVt10;
    uint8_t* mpBegin14;
    uint8_t* mpEnd18;
    uint8_t* mpCap1c;
    uint32_t f20;
    uint32_t f24;
    uint32_t f28;
    Rec2c_a8d888* Init();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0047d8f0 score 8
Rec2c_a8d888* Rec2c_a8d888::Init()
{
    f0 = 0;
    f4 = 0;
    f8 = 0;
    fc = 0;
    mpBegin14 = 0;
    mpEnd18 = 0;
    mpCap1c = 0;
    uint8_t* p = static_cast<uint8_t*>(Fn0090cf54(8));
    mpBegin14 = p;
    mpEnd18 = p;
    mpCap1c = p + 8;
    *p = 0;
    f20 = 0;
    mVt10 = 0xa80810;
    f24 = 0;
    f28 = 0;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0047c150 score 10
uint32_t Chooser_a8d888::Fn0047c150()
{
    while (mnSetCount144) {
        Item_a8d888* it = static_cast<Item_a8d888*>(mpSet140->mpLeft->mpVal);
        if (!it->Fn264(1, 1)) {
            return 0;
        }
    }
    if (mpWin128) {
        mpWin128->Flag5(0);
    }
    return 0;
}

// CLOSE: 0x0047d940 score 20
bool Chooser_a8d888::Fn0047d940()
{
    bool found = false;
    if (mnSetCount144) {
        uint32_t id = Fn0049a7f0();
        TNode_a8d888* head = mpSet140;
        TNode_a8d888* n = head->mpLeft;
        while (n != head) {
            if (static_cast<Sel_a8d888*>(n->mpVal)->mnId == id) {
                return true;
            }
            if (n->mpRight) {
                n = n->mpRight;
                while (n->mpLeft) {
                    n = n->mpLeft;
                }
            } else {
                TNode_a8d888* p = n->mpParent;
                while (n == p->mpRight) {
                    n = p;
                    p = p->mpParent;
                }
                if (n->mpRight != p) {
                    n = p;
                }
            }
        }
    }
    return found;
}

// CLOSE: 0x00485230 score 61
uint32_t* HTable_a8d888::Insert(HRec_a8d888* rec)
{
    Fn004f0940(mnCount + 1);
    uint32_t idx = rec->mnKey % static_cast<uint32_t>(mpEnd - mpBegin);
    HNode_a8d888* first = mpBegin[idx];
    HNode_a8d888* node = NewNode(rec);
    node->mpNext = first;
    mpBegin[idx] = node;
    ++mnCount;
    return &node->mnKey;
}

// CLOSE: 0x00480400 score 32
HNode_a8d888* HTable_a8d888::NewNode(HRec_a8d888* rec)
{
    HNode_a8d888* n = static_cast<HNode_a8d888*>(Fn0090cf54(0x1c));
    n->mpNext = 0;
    n->mnKey = rec->mnKey;
    n->mStr.Ctor(&rec->mStr, 0, -1, &rec);
    n->mVt8 = 0xa80810;
    n->mnTail = 0;
    return n;
}

// CLOSE: 0x0047eaf0 score 4
void HTable_a8d888::Clear()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        HNode_a8d888* n = mpBegin[i];
        while (n) {
            HNode_a8d888* next = n->mpNext;
            n->mVt8 = 0xa80810;
            if (n->mStr.mpBegin) {
                Fn0090cf63(n->mStr.mpBegin);
            }
            Fn0090cf63(n);
            n = next;
        }
        mpBegin[i] = 0;
    }
    mnCount = 0;
}
#endif

#ifdef OB_DRAFTS
#endif

// FUNCTION: 0x0047e530
void Fn0047e530(uint32_t* first, uint32_t* last, void* cmp)
{
    if ((last - first) > 16) {
        Fn0047d870(first, first + 16, cmp);
        Fn0047b810(first + 16, last, 0, cmp);
    } else {
        Fn0047d870(first, last, cmp);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0047eb60 score 15
void Fn0047eb60(uint32_t* first, uint32_t* last, void* cmp)
{
    if (first != last) {
        uint32_t n = static_cast<uint32_t>(last - first);
        uint32_t depth = 0;
        while (n != 1) {
            n >>= 1;
            ++depth;
        }
        Fn0047ea40(first, last, 0, depth + depth, cmp);
        Fn0047e530(first, last, cmp);
    }
}

#endif

// FUNCTION: 0x0047e580
bool OB_STDCALL Fn0047e580(uint32_t* out)
{
    uint32_t id = Fn0049a7f0();
    if (id && gpB43d18_a8d888) {
        Counted_a8d888* c = reinterpret_cast<Counted_a8d888*>(gpB43d18_a8d888->Lookup(id));
        if (c) {
            uint32_t r = c->Fn3();
            out[2] = r;
            out[0] = 0x6534284a;
            out[1] = 0xa8fbd372;
            return true;
        }
    }
    return false;
}


// ---- batch B ----

// A string-keyed lookup table: names by object id (the globals at 0xb2167c, 0xb21690, 0xb216a4).
// GLOBAL: 0x00b2167c
extern HTable_a8d888 gB2167c;
// GLOBAL: 0x00b21690
extern HTable_a8d888 gB21690;
// GLOBAL: 0x00b216a4
extern HTable_a8d888 gB216a4;

// An object whose slot 5 yields an id.
struct IdSrc_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual uint32_t Id5();
};

// A string with begin/end pointers as the table nodes hold it.
struct SStr_a8d888 {
    void* mpBegin;
    void* mpEnd;
};

struct HVal_a8d888 {
    uint32_t mVt;
    StrObj_a8d888 mStr;
};

// A prop name sink.
struct Sink_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void Set13(void* s);
};

// A property manager.
struct PropMgr_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual bool Has8(uint32_t id);
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void* Get12(uint32_t id);
    virtual void P13();
    virtual void P14();
    virtual bool Has15(uint32_t id);
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
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void* Get37(uint32_t id);
};

// GLOBAL: 0x00b43dd0
extern void* gpB43dd0_a8d888;
// GLOBAL: 0x00b43cf4
extern void* gpB43cf4_a8d888;

// The renderer's camera object takes a position vector.
struct Cam_a8d888 {
    // STUB: 0x007cd810
    void Fn007cd810(float* v);
};

struct Rend_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual Cam_a8d888* Cam16();
};

struct Terr_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual float Height14(uint32_t x, uint32_t z);
};

// Lot configuration data: width at +0x20, depth at +0x21.
struct LotCfg_a8d888 {
    uint8_t pad[0x20];
    uint8_t mnW;
    uint8_t mnD;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00486440 score 20
void Fn00486440(IdSrc_a8d888* a)
{
    SStr_a8d888* s = static_cast<SStr_a8d888*>(Fn0090fe93(a->Id5()));
    HVal_a8d888* v = static_cast<HVal_a8d888*>(gB2167c.FindOrInsert(reinterpret_cast<uint32_t*>(&s)));
    if (s && reinterpret_cast<uint8_t*>(s) + 4 != reinterpret_cast<uint8_t*>(&v->mStr)) {
        v->mStr.Assign(s->mpBegin, s->mpEnd, &s);
    }
}

// CLOSE: 0x00486490 score 20
void Fn00486490(IdSrc_a8d888* a)
{
    SStr_a8d888* s = static_cast<SStr_a8d888*>(Fn0090fe93(a->Id5()));
    HVal_a8d888* v = static_cast<HVal_a8d888*>(gB21690.FindOrInsert(reinterpret_cast<uint32_t*>(&s)));
    if (s && reinterpret_cast<uint8_t*>(s) + 4 != reinterpret_cast<uint8_t*>(&v->mStr)) {
        v->mStr.Assign(s->mpBegin, s->mpEnd, &s);
    }
}

// CLOSE: 0x004864e0 score 20
void Fn004864e0(IdSrc_a8d888* a)
{
    SStr_a8d888* s = static_cast<SStr_a8d888*>(Fn0090fe93(a->Id5()));
    HVal_a8d888* v = static_cast<HVal_a8d888*>(gB216a4.FindOrInsert(reinterpret_cast<uint32_t*>(&s)));
    if (s && reinterpret_cast<uint8_t*>(s) + 4 != reinterpret_cast<uint8_t*>(&v->mStr)) {
        v->mStr.Assign(s->mpBegin, s->mpEnd, &s);
    }
}

// CLOSE: 0x0047eff0 score 25
void OB_STDCALL Fn0047eff0(uint8_t* s)
{
    Fn00602230(s);
    // appends of two literal paths with a backslash between
}

// CLOSE: 0x0047fa00 score 31
void OB_STDCALL Fn0047fa00(uint32_t id, Sink_a8d888* out, PropMgr_a8d888* pm)
{
    if (pm->Has8(id)) {
        out->Set13(pm->Get12(id));
    } else {
        uint8_t tmp[0x20];
        Fn00408480(tmp, "");
    }
}

// CLOSE: 0x0047f6c0 score 31
void OB_STDCALL Fn0047f6c0(uint32_t id, Sink_a8d888* out, PropMgr_a8d888* pm)
{
    if (pm->Has15(id)) {
        out->Set13(pm->Get37(id));
    } else {
        uint8_t tmp[0x20];
        Fn00408480(tmp, "");
    }
}

// CLOSE: 0x0047b700 score 22
uint32_t cSC4WinLotConfigurationEditor::GoTo3DView()
{
    Cam_a8d888* cam = static_cast<Rend_a8d888*>(gpB43dd0_a8d888)->Cam16();
    LotCfg_a8d888* cfg = static_cast<LotCfg_a8d888*>(mpConfig190);
    uint32_t x = cfg ? (cfg->mnW >> 1) + 2 : 3;
    uint32_t z = cfg ? (cfg->mnD >> 1) + 2 : 3;
    float v[3];
    v[1] = static_cast<Terr_a8d888*>(gpB43cf4_a8d888)->Height14(x, z);
    v[0] = static_cast<float>(static_cast<int32_t>(x << 4));
    v[2] = static_cast<float>(static_cast<int32_t>(z << 4));
    cam->Fn007cd810(v);
    return 0;
}
#endif

// ---- batch C ----
// STUB: 0x00497520
TNode_a8d888* Fn00497520(TNode_a8d888** set, void* key);
// STUB: 0x0040daf0
TNode_a8d888* Fn0040daf0(TNode_a8d888* n);
struct Win2_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void Flag4(uint32_t);
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void Query18(uint32_t* out);
};

struct Msg_a8d888 {
    uint32_t mnType;
    uint32_t mnA;
    uint32_t mnC;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0047bad0 score 5
bool Fn0047bad0(uint32_t id, void* info)
{
    uint32_t key[3];
    key[0] = 0x6534284a;
    key[1] = 0x67cd5fa1;
    key[2] = id;
    CfgMgr_a8d888* m = gpB43d18_a8d888;
    if (m) {
        Counted_a8d888* c = m->Lookup(id);
        if (c) {
            key[2] = c->Fn3();
            key[1] = 0xa8fbd372;
            return Fn0047b1f0(key, info);
        }
    }
    return false;
}

// CLOSE: 0x0047dd60 score 47
bool cSC4WinLotConfigurationEditor::Slot03_a86864(uint32_t a, uint32_t b)
{
    Msg_a8d888* m = OB_PTR(Msg_a8d888, b);
    if (m->mnType == 3) {
        if (m->mnA == 0x287259f6) {
            uint32_t v = m->mnC;
            if (v == 0x6987b3fa || v == 0x69433011 || v == 0x69433012 || v == 0x97cefb2 || v == 0x97cefb3
                || v == 0xe9432dd7 || v == 0xe9432dd8) {
                DoDialogBoxGridSort(v);
                return true;
            }
        }
    } else if (m->mnType != 5) {
        return false;
    }
    if (m->mnA >= 0x41 && m->mnA <= 0x5a) {
        Fn0047ca60(a, m->mnA);
        return true;
    }
    return false;
}

// CLOSE: 0x0047aa50 score 44
bool cUnk00ac7630::SendMsg_2(uint32_t a, uint32_t b)
{
    Msg_a8d888* m = OB_PTR(Msg_a8d888, b);
    Win2_a8d888* w = reinterpret_cast<Win2_a8d888*>(reinterpret_cast<uint8_t*>(this) - 4);
    if (m->mnType == 0x7abe7204) {
        if (*OB_PTR(uint32_t, m->mnC) == 2) {
            w->Flag4(1);
        }
    } else if (m->mnType == 3) {
        if (m->mnC == 0xbaa55d58) {
            uint32_t q;
            w->Query18(&q);
            if (q == 2) {
                w->Flag4(1);
            }
            return true;
        }
        if (m->mnC == 0xbaa55d59) {
            w->Flag4(0);
            return true;
        }
    }
    return cGZWin::SendMsg_2(a, b);
}

// CLOSE: 0x004893e0 score 2
bool cSC4WinLotConfigurationEditor::Fn004893e0(uint32_t x, uint32_t y, uint32_t flags)
{
    if (mnCursorMode19c == 0) {
        uint32_t out;
        uint32_t r = Fn00483dc0(x, y, flags, OB_ADDR(&out));
        if (r == 0) {
            DoEditAreaMenu(x, y);
        } else if (r == 1) {
            DoEditAreaMenu(x, y);
        } else if (r == 2) {
            DoLotFoundationMenu(x, y);
        } else if (r == 3) {
            DoFenceMenu(x, y);
        } else if (r >= 100) {
            DoLotConfigurationObjectMenu(x, y, reinterpret_cast<void*>(static_cast<uintptr_t>(out)));
        }
    }
    return true;
}

// CLOSE: 0x0047c4b0 score 43
void Chooser_a8d888::Fn0047c4b0(void* key)
{
    TNode_a8d888* found = Fn00497520(&mpSet140, key);
    if (found != mpSet140) {
        static_cast<Win_a8d888*>(found->mpVal)->Release2();
        Fn0040daf0(found);
        Fn0090cf63(found);
        --mnSetCount144;
    }
}
#endif

// ---- batch D ----
// STUB: 0x0040d5e0
void Fn0040d5e0(TNode_a8d888* n, TNode_a8d888** root);
struct Win3_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual void Fn16(void* p);
};
struct Svc44_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
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
    virtual uint32_t Fn44(void* a, void* tmp, uint32_t b, uint32_t c, uint32_t d);
};
struct Cfg4_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void Fn4(void* tmp);
};

// The set of selected ids: head node and element count.
struct TreeSet_a8d888 {
    TNode_a8d888* mpHead;
    uint32_t mnCount;
    // STUB: 0x0047c090
    void Insert(TNode_a8d888** out, bool left, TNode_a8d888* parent, uint32_t* v, bool force);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0047c090 score 98
void TreeSet_a8d888::Insert(TNode_a8d888** out, bool left, TNode_a8d888* parent, uint32_t* v, bool force)
{
    TNode_a8d888* n;
    TNode_a8d888* head = mpHead;
    if (parent == head || force || left || *v < *reinterpret_cast<uint32_t*>(&parent->mpVal)) {
        n = static_cast<TNode_a8d888*>(Fn0090cf54(0x14));
        *reinterpret_cast<uint32_t*>(&n->mpVal) = *v;
        parent->mpLeft = n;
        head = mpHead;
        if (parent == head) {
            head->mpParent = n;
            head->mpRight = n;
        } else if (parent == head->mpLeft) {
            head->mpLeft = n;
        }
    } else {
        n = static_cast<TNode_a8d888*>(Fn0090cf54(0x14));
        *reinterpret_cast<uint32_t*>(&n->mpVal) = *v;
        parent->mpRight = n;
        if (parent == mpHead->mpRight) {
            mpHead->mpRight = n;
        }
    }
    n->mpParent = parent;
    n->mpLeft = 0;
    n->mpRight = 0;
    Fn0040d5e0(n, &mpHead->mpParent);
    ++mnCount;
    *out = n;
}

// CLOSE: 0x0047d610 score 52
uint32_t cSC4WinLotConfigurationEditor::Fn0047d610(void* str, uint32_t flag)
{
    uint8_t tmp[0x14];
    Fn0090cf54(8);
    Cfg4_a8d888* cfg = static_cast<Cfg4_a8d888*>(mpConfig190);
    if (cfg) {
        cfg->Fn4(tmp);
    }
    Svc44_a8d888* svc = *reinterpret_cast<Svc44_a8d888**>(reinterpret_cast<uint8_t*>(this) + 4);
    return svc->Fn44(str, tmp, flag, 1, 0);
}

// CLOSE: 0x004865d0 score 84
bool cSC4WinLotConfigurationEditor::Close(uint32_t a, uint32_t b)
{
    bool r = false;
    bool go = false;
    if (a && mbDataChanged12c) {
        cRZString s("");
        uint32_t id = Fn0047d610(&s, 4);
        if (id == 0x5301814c) {
            go = true;
        } else if (id == 0x53018149) {
            r = true;
            goto done;
        } else if (id == 0x53018147) {
            return false;
        }
    } else {
        go = true;
    }
    if (go) {
        r = true;
    }
    if (b && mbDataChanged12c) {
        r = Fn004852a0(0, 1) != 0;
    }
    if (!r) {
        return r;
    }
done:
    if (mpOwner15c) {
        static_cast<Chooser_a8d888*>(mpOwner15c)->Fn0047c4b0(this);
    }
    (*reinterpret_cast<Win3_a8d888**>(reinterpret_cast<uint8_t*>(this) + 0x48))->Fn16(this);
    return r;
}
#endif

// ---- batch E ----
// GLOBAL: 0x00b216a8
extern HNode_a8d888** gpB216a8;
// GLOBAL: 0x00b216ac
extern HNode_a8d888** gpB216ac;
// GLOBAL: 0x00b216b8
extern uint8_t gbB216b8;
// GLOBAL: 0x00b43ca8
extern void* gpB43ca8_a8d888;

#ifdef OB_DRAFTS
// CLOSE: 0x0047d870 score 57
void Fn0047d870(uint32_t* first, uint32_t* last, void* cmp)
{
    if (first == last) {
        return;
    }
    for (uint32_t* i = first + 1; i != last; ++i) {
        uint32_t v = *i;
        if (v < *first) {
            for (uint32_t* j = i; j != first; --j) {
                *j = *(j - 1);
            }
            *first = v;
        } else {
            uint32_t* j = i;
            uint32_t prev = *(j - 1);
            while (v < prev) {
                *j = prev;
                --j;
                prev = *(j - 1);
            }
            *j = v;
        }
    }
}

#endif

// FUNCTION: 0x0047ea40
void Fn0047ea40(uint32_t* first, uint32_t* last, uint32_t /*n*/, uint32_t depth, void* cmp)
{
    while ((last - first) > 16) {
        if (depth == 0) {
            Fn0048a4b0(first, last, last, 0, cmp);
            return;
        }
        --depth;
        uint32_t a = *first;
        uint32_t* mid = first + (last - first) / 2;
        uint32_t m = *mid;
        uint32_t* lp = last - 1;
        uint32_t c = *lp;
        uint32_t* pick;
        if (a < m) {
            if (m < c) {
                pick = mid;
            } else if (a < c) {
                pick = lp;
            } else {
                pick = first;
            }
        } else if (a < c) {
            pick = first;
        } else if (m < c) {
            pick = lp;
        } else {
            pick = mid;
        }
        uint32_t* cut = Fn00611840(first, last, *pick, cmp);
        Fn0047ea40(cut, last, 0, depth, cmp);
        last = cut;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0047f950 score 54
void OB_STDCALL Fn0047f950(uint32_t id, Sink_a8d888* out)
{
    uint32_t idx = id % static_cast<uint32_t>(gpB216ac - gpB216a8);
    HNode_a8d888* n = gpB216a8[idx];
    while (n && n->mnKey != id) {
        n = n->mpNext;
    }
    if (!n) {
        uint8_t tmp[0x20];
        Fn00408480(tmp, "");
        return;
    }
    HVal_a8d888* v = reinterpret_cast<HVal_a8d888*>(&n->mVt8);
    if (reinterpret_cast<uint8_t*>(&v->mStr) != reinterpret_cast<uint8_t*>(out) + 4) {
        v->mStr.Assign(v->mStr.mpBegin, 0, out);
    }
}

// CLOSE: 0x004852a0 score 81
uint32_t cSC4WinLotConfigurationEditor::Fn004852a0(uint32_t a, uint32_t b)
{
    uint32_t r = 0;
    if (mIdentity164 == 0) {
        gbB216b8 = 1;
        Slot152_a8d888(0, a, b);
        gbB216b8 = 0;
        return 0;
    }
    if (Fn0047d6b0(1, 1)) {
        if (gpB43d18_a8d888 && WriteLotData()) {
            r = 1;
            mbDataChanged12c = 0;
            SetTitle();
            if (a) {
                cRZString s("");
                Fn0047d610(&s, 0);
            }
        } else if (b) {
            cRZString s("");
            Fn0047d610(&s, 0x10000);
        }
    }
    return r;
}
#endif

// ---- batch F ----
struct Win4_a8d888 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual bool Fn3(uint32_t k);
};

// A 0x34-byte record of the lot configuration's object list (string at +0x20).
struct Obj34_a8d888 {
    uint8_t mnKind;
    uint8_t mb1;
    uint8_t mb2;
    uint8_t mb3;
    uint8_t pad4[0x1c];
    uint32_t mw20;
    // STUB: 0x00462c10
    void CopyStr(const void* src);
    uint8_t pad24[0x34 - 0x24];
};

struct Chooser2_a8d888 {
    // STUB: 0x00480460
    void Fn00480460();
    // STUB: 0x0047ed90
    void Fn0047ed90();
    // STUB: 0x00486d30
    void Fn00486d30(uint32_t v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00489490 score 108
bool cUnk00a8d4e0::DoMessage(uint32_t b)
{
    Msg_a8d888* m = OB_PTR(Msg_a8d888, b);
    Chooser2_a8d888* c = reinterpret_cast<Chooser2_a8d888*>(this);
    if (m->mnType == 3) {
        if (m->mnA == 0x287259f6) {
            uint32_t v = m->mnC;
            if (v == 0x942d1cb || v == 0x942d1cc) {
                Win4_a8d888* w = *reinterpret_cast<Win4_a8d888**>(reinterpret_cast<uint8_t*>(this) + 8);
                uint32_t on = 0;
                if (w->Fn3(0x11) || w->Fn3(0x10)) {
                    on = 1;
                }
                Fn0047aaf0(v == 0x942d1cc, on);
            } else if (v == 0x91c91bb) {
                c->Fn00486d30(1);
            } else if (v == 0x91c91bc) {
                c->Fn00486d30(0);
            } else if (v == 0x91c91bd) {
                c->Fn0047ed90();
            } else if (v == 0x42b7c353) {
                reinterpret_cast<Chooser_a8d888*>(this)->Fn0047c150();
            }
        }
        return true;
    }
    if (m->mnType == 0x920b687) {
        c->Fn00480460();
        return true;
    }
    return cGZWinGen::DoMessage(b);
}

// CLOSE: 0x0047d6b0 score 84
bool cSC4WinLotConfigurationEditor::Fn0047d6b0(uint32_t a, uint32_t b)
{
    uint8_t* cfg = static_cast<uint8_t*>(mpConfig190);
    Obj34_a8d888* it = *reinterpret_cast<Obj34_a8d888**>(cfg + 0x90);
    Obj34_a8d888* end = *reinterpret_cast<Obj34_a8d888**>(cfg + 0x94);
    for (; it != end; it = reinterpret_cast<Obj34_a8d888*>(reinterpret_cast<uint8_t*>(it) + 0x34)) {
        uint8_t k = it->mnKind;
        if (k == 0 || k == 4 || k == 1) {
            if (!Fn0047b640(it, b != 0)) {
                if (a) {
                    cRZString s("");
                    uint32_t r = Fn0047d610(&s, 1);
                    if (r == 0x5301814a) {
                        return true;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// CLOSE: 0x0047d790 score 53
Obj34_a8d888* Fn0047d790(Obj34_a8d888* first, Obj34_a8d888* last, Obj34_a8d888* dest)
{
    int32_t n = static_cast<int32_t>(last - first);
    for (; n > 0; --n) {
        --last;
        --dest;
        dest->mnKind = last->mnKind;
        dest->mb1 = last->mb1;
        dest->mb2 = last->mb2;
        dest->mb3 = last->mb3;
        std::memcpy(dest->pad4, last->pad4, sizeof(dest->pad4));
        dest->CopyStr(&last->mw20);
    }
    return dest;
}
#endif
