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
struct CfgMgr_a8d888 {
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
