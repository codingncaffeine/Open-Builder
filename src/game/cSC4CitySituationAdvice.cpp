#include <cstddef>

#include "classes/cSC4CitySituationAdvice.h"
#include "game/Globals.h"

// A field of this object by its offset (the class header has the bytes unnamed).
#define FLD_a843c8(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

struct OB_NOVTABLE Lua_a843c8 {
    virtual void Pad00_a843c8();
    virtual void Pad01_a843c8();
    virtual void Pad02_a843c8();
    virtual void Pad03_a843c8();
    virtual void Pad04_a843c8();
    virtual void Pad05_a843c8();
    virtual uint32_t GetTop_a843c8() = 0;
    virtual void SetTop_a843c8(uint32_t n) = 0;
    virtual void Pad08_a843c8();
    virtual void Pad09_a843c8();
    virtual void Pad10_a843c8();
    virtual void Pop_a843c8(int32_t n) = 0;
    virtual void Pad12_a843c8();
    virtual void Pad13_a843c8();
    virtual void Pad14_a843c8();
    virtual void Pad15_a843c8();
    virtual void Pad16_a843c8();
    virtual void Pad17_a843c8();
    virtual void Pad18_a843c8();
    virtual void Pad19_a843c8();
    virtual void Pad20_a843c8();
    virtual void Pad21_a843c8();
    virtual uint32_t ToSint32_a843c8(int32_t i) = 0;
    virtual void Pad23_a843c8();
    virtual void Pad24_a843c8();
    virtual void Pad25_a843c8();
    virtual void Pad26_a843c8();
    virtual void Pad27_a843c8();
    virtual void Pad28_a843c8();
    virtual void Pad29_a843c8();
    virtual void Pad30_a843c8();
    virtual void Pad31_a843c8();
    virtual void Pad32_a843c8();
    virtual void PushString_a843c8(const char* s) = 0;
    virtual void Pad34_a843c8();
    virtual void Pad35_a843c8();
    virtual void Pad36_a843c8();
    virtual void Pad37_a843c8();
    virtual void GetTable_a843c8(int32_t i) = 0;
    virtual void Pad39_a843c8();
    virtual void Pad40_a843c8();
    virtual void Pad41_a843c8();
    virtual void Pad42_a843c8();
    virtual void GetRef_a843c8(uint32_t ref) = 0;
    virtual void Pad44_a843c8();
    virtual void Pad45_a843c8();
    virtual void Pad46_a843c8();
    virtual void Pad47_a843c8();
    virtual void Pad48_a843c8();
    virtual void Pad49_a843c8();
    virtual void Pad50_a843c8();
    virtual void Pad51_a843c8();
    virtual void Pad52_a843c8();
    virtual void Pad53_a843c8();
    virtual void Pad54_a843c8();
    virtual void Pad55_a843c8();
    virtual void Pad56_a843c8();
    virtual void Pad57_a843c8();
    virtual void Pad58_a843c8();
    virtual void Pad59_a843c8();
    virtual void Pad60_a843c8();
    virtual void Pad61_a843c8();
    virtual void Unref_a843c8(uint32_t ref) = 0;
    virtual void Pad63_a843c8();
    virtual void Pad64_a843c8();
    virtual void Pad65_a843c8();
    virtual void Pad66_a843c8();
    virtual void Pad67_a843c8();
    virtual void Pad68_a843c8();
    virtual void Pad69_a843c8();
    virtual void Pad70_a843c8();
    virtual void Pad71_a843c8();
    virtual void Pad72_a843c8();
    virtual void Pad73_a843c8();
    virtual bool IsNil_a843c8(int32_t i) = 0;
};

// GLOBAL: 0x00b43ce8
extern Lua_a843c8* gpB43ce8_a843c8;
struct OB_NOVTABLE Sink_a843c8 {
    virtual void Pad00_a843c8();
    virtual void Pad01_a843c8();
    virtual void Pad02_a843c8();
    virtual void Pad03_a843c8();
    virtual void Pad04_a843c8();
    virtual void Pad05_a843c8();
    virtual void Pad06_a843c8();
    virtual void Pad07_a843c8();
    virtual void Pad08_a843c8();
    virtual void Put9_a843c8(void* a, void* b) = 0;
    virtual void Put10_a843c8(uint32_t v) = 0;
    virtual bool Get11_a843c8() = 0;
};

// GLOBAL: 0x00b43cdc
extern Sink_a843c8* gpB43cdc;
// GLOBAL: 0x00b20de4
extern uint32_t gB20de4;

// STUB: 0x005fb550
void Fn005fb550(Lua_a843c8* lua, const char* name, uint32_t* out, uint32_t index);
// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);
// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// A list node holding a 4-byte record; the list head is the first word of the list object.
struct Node_a843c8 {
    Node_a843c8* mpNext;
    Node_a843c8* mpPrev;
    uint16_t mA;
    uint16_t mB;
};

struct ListS_a843c8 {
    Node_a843c8* mpHead;
    void PushBack(const uint16_t* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00423430 score 8
void ListS_a843c8::PushBack(const uint16_t* v)
{
    Node_a843c8* head = mpHead;
    Node_a843c8* node = static_cast<Node_a843c8*>(Fn0090cf54(0xc));
    uint16_t* pv = &node->mA;
    if (pv) {
        pv[0] = v[0];
        pv[1] = v[1];
    }
    Node_a843c8* prev = head->mpPrev;
    node->mpNext = head;
    node->mpPrev = prev;
    prev->mpNext = node;
    head->mpPrev = node;
}
#endif

// The slots of the advice seen with the original's return types (the base declares them void).
struct Fix_a843c8 {
    bool Slot54_a843c8(uint32_t a);
};

// FUNCTION: 0x00423020
bool cSC4CitySituationAdvice::QueryInterface(uint32_t iid, void** out)
{
    if (iid == 0x6beb1e8a) {
        *out = this;
        AddRef();
        return true;
    }
    return cSC4Advice::QueryInterface(iid, out);
}

// FUNCTION: 0x00423090
bool cSC4CitySituationAdvice::Slot04_a80710()
{
    cSC4Advice::Slot04_a80710();
    if (gpB43ce8_a843c8 && FLD_a843c8(int32_t, 0x198) != -2) {
        gpB43ce8_a843c8->Unref_a843c8(FLD_a843c8(uint32_t, 0x198));
        FLD_a843c8(int32_t, 0x198) = -2;
    }
    return true;
}

// FUNCTION: 0x004230d0
uint32_t cSC4CitySituationAdvice::ReadUint32FromTable(const char* name)
{
    uint32_t result = 0;
    if (FLD_a843c8(int32_t, 0x198) != -2) {
        Lua_a843c8* lua = gpB43ce8_a843c8;
        if (lua) {
            uint32_t top = lua->GetTop_a843c8();
            lua->GetRef_a843c8(FLD_a843c8(uint32_t, 0x198));
            uint32_t top2 = lua->GetTop_a843c8();
            if (top2 != top) {
                Fn005fb550(lua, name, &result, top2);
            }
            lua->SetTop_a843c8(top);
        }
    }
    return result;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00423140 score 6
float cSC4CitySituationAdvice::Slot09_a843c8()
{
    if (FLD_a843c8(float, 0xd4) > 0.0f) {
        return FLD_a843c8(float, 0xd4);
    }
    cISC4City* city = gpB43cec;
    float n = static_cast<float>(static_cast<int32_t>(city->CellCountX()));
    return city->CellWidthX() * n;
}
#endif

// A pair of calls on an object the advice's occupant list hands over.
struct OB_NOVTABLE Q2_a843c8 {
    virtual void Pad00_a843c8(); virtual void Pad01_a843c8(); virtual void Pad02_a843c8(); virtual void Pad03_a843c8(); virtual void Pad04_a843c8();
    virtual void Pad05_a843c8(); virtual void Pad06_a843c8(); virtual void Pad07_a843c8(); virtual void Pad08_a843c8(); virtual void Pad09_a843c8();
    virtual void Pad10_a843c8(); virtual void Pad11_a843c8(); virtual void Pad12_a843c8(); virtual void Pad13_a843c8(); virtual void Pad14_a843c8();
    virtual void Pad15_a843c8(); virtual void Pad16_a843c8(); virtual void Pad17_a843c8(); virtual void Pad18_a843c8(); virtual void Pad19_a843c8();
    virtual void Pad20_a843c8(); virtual void Pad21_a843c8();
    virtual bool Slot22_a843c8(uint32_t v) = 0;
};
struct OB_NOVTABLE Q1_a843c8 {
    virtual void Pad00_a843c8(); virtual void Pad01_a843c8(); virtual void Pad02_a843c8(); virtual void Pad03_a843c8(); virtual void Pad04_a843c8();
    virtual Q2_a843c8* Slot05_a843c8() = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00423190 score 36
bool cSC4CitySituationAdvice::Slot53_a843c8(uint32_t a)
{
    bool r = false;
    if (a) {
        uint32_t* end = FLD_a843c8(uint32_t*, 0xe8);
        for (uint32_t* p = FLD_a843c8(uint32_t*, 0xe4); p != end; ++p) {
            if (OB_PTR(Q1_a843c8, a)->Slot05_a843c8()->Slot22_a843c8(*p)) {
                return true;
            }
            end = FLD_a843c8(uint32_t*, 0xe8);
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004231f0 score 42
bool Fix_a843c8::Slot54_a843c8(uint32_t a)
{
    uint32_t* first = *OB_PTR(uint32_t*, a);
    uint32_t n = static_cast<uint32_t>(OB_PTR(uint32_t*, a)[1] - first);
    bool found = false;
    if (n > 0) {
        uint32_t* end = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(this) + 0xe8);
        for (uint32_t* p = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(this) + 0xe4); p != end; ++p) {
            if (found) {
                break;
            }
            uint32_t v = *p;
            for (uint32_t i = 0; i < n; ++i) {
                if (first[i] == v) {
                    found = true;
                    break;
                }
            }
        }
    }
    return found;
}
#endif

// FUNCTION: 0x00423270
void cSC4CitySituationAdvice::Slot25_a843c8()
{
    ReadUint32FromTable("image");
}

// FUNCTION: 0x00423280
void cSC4CitySituationAdvice::Slot26_a843c8()
{
    if (ReadUint32FromTable("success_image") == 0) {
        Slot25_a843c8();
    }
}

// FUNCTION: 0x004232a0
void cSC4CitySituationAdvice::Slot35_a843c8()
{
    if (ReadUint32FromTable("reward_unlocked_image") == 0) {
        Slot26_a843c8();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x004232c0 score 5
void cSC4CitySituationAdvice::Slot27_a843c8()
{
    if (ReadUint32FromTable("success_mood") == 0) {
        cSC4Advice::Slot06_a80710();
    }
}
#endif

// FUNCTION: 0x004232e0
void cSC4CitySituationAdvice::Slot28_a843c8()
{
    if (ReadUint32FromTable("failure_image") == 0) {
        Slot25_a843c8();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00423300 score 5
void cSC4CitySituationAdvice::Slot29_a843c8()
{
    if (ReadUint32FromTable("failure_mood") == 0) {
        cSC4Advice::Slot06_a80710();
    }
}
#endif

// FUNCTION: 0x00423660
uint32_t cSC4CitySituationAdvice::Slot15_a843c8(uint32_t a)
{
    return (FLD_a843c8(uint32_t, 0xe0) & a) != 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004236b0 score 2
bool cSC4CitySituationAdvice::Slot17_a843c8()
{
    return (FLD_a843c8(uint32_t, 0xe0) >> 2) & 1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00423760 score 6
void cSC4CitySituationAdvice::Slot45_a843c8(uint32_t a)
{
    *OB_PTR(uint32_t, a) = FLD_a843c8(uint32_t, 0x154);
}
#endif

// FUNCTION: 0x00423770
uint32_t cSC4CitySituationAdvice::Slot46_a843c8(uint32_t a, uint32_t b)
{
    *OB_PTR(uint32_t, a) = FLD_a843c8(uint32_t, 0x158);
    *OB_PTR(uint32_t, b) = FLD_a843c8(uint32_t, 0x15c);
    if (*OB_PTR(float, a) > 0.0f) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x004237b0
uint32_t cSC4CitySituationAdvice::Slot48_a843c8(uint32_t a)
{
    int64_t v = FLD_a843c8(int32_t, 0x174);
    *OB_PTR(int64_t, a) = v;
    if (v != 0) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x004237e0
uint32_t cSC4CitySituationAdvice::Slot49_a843c8(uint32_t a, uint32_t b)
{
    *OB_PTR(uint32_t, a) = FLD_a843c8(uint32_t, 0x178);
    *OB_PTR(uint32_t, b) = FLD_a843c8(uint32_t, 0x17c);
    if (*OB_PTR(float, a) > 0.0f) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00423820
uint32_t cSC4CitySituationAdvice::Slot51_a843c8(uint32_t a)
{
    int64_t v = FLD_a843c8(int32_t, 0x194);
    *OB_PTR(int64_t, a) = v;
    if (v != 0) {
        return 1;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00423900 score 9
bool cSC4CitySituationAdvice::Slot19_a843c8()
{
    return FLD_a843c8(uint32_t, 0x118) != FLD_a843c8(uint32_t, 0x11c);
}
#endif

// FUNCTION: 0x00424750
void* cSC4CitySituationAdvice::Slot18_a80710()
{
    return ReadStringFromTable("progress_title");
}

// FUNCTION: 0x004249d0
void cSC4CitySituationAdvice::Slot22_a843c8()
{
    ReadStringFromTable("success_text");
}

// FUNCTION: 0x004249e0
void cSC4CitySituationAdvice::Slot23_a843c8()
{
    ReadStringFromTable("failure_text");
}

// FUNCTION: 0x004249f0
void cSC4CitySituationAdvice::Slot33_a843c8()
{
    ReadStringFromTable("reward_progress_text");
}

// FUNCTION: 0x00424a00
void cSC4CitySituationAdvice::Slot34_a843c8()
{
    ReadStringFromTable("reward_unlocked_text");
}

#ifdef OB_DRAFTS
// CLOSE: 0x005fb5c0 score 32
bool Fn005fb5c0(Lua_a843c8* lua, const char* key, uint32_t* out, int32_t index)
{
    bool ok = false;
    lua->PushString_a843c8(key);
    lua->GetTable_a843c8(index);
    if (!lua->IsNil_a843c8(-1)) {
        *out = lua->ToSint32_a843c8(-1);
        ok = true;
        lua->Pop_a843c8(1);
        return ok;
    }
    *out = 0;
    lua->Pop_a843c8(1);
    return ok;
}
#endif

// ---- batch 2 ----
// A wide string as the original keeps it: a vtable word, then begin and end of the characters.
struct WStrW_a843c8 {
    uint32_t mVt;
    uint16_t* mpBegin;
    uint16_t* mpEnd;
};
struct WStr_a843c8 {
    uint16_t* mpBegin;
    uint16_t* mpEnd;
    // STUB: 0x00408a70
    void Assign(const uint16_t* first, const uint16_t* last);
};
// A localized string object built from a (group, instance) pair.
struct SLStr_a843c8 {
    uint8_t mData[0x24];
    // STUB: 0x00603580
    SLStr_a843c8(uint32_t group, uint32_t instance, bool flag);
    ~SLStr_a843c8()
    {
        void* p = *reinterpret_cast<void**>(&mData[8]);
        if (p) {
            Fn0090cf63(p);
        }
    }
};
struct OB_NOVTABLE Reg_a843c8 {
    virtual void Pad00_a843c8();
    virtual void Pad01_a843c8();
    virtual void Pad02_a843c8();
    virtual void Pad03_a843c8();
    virtual void Pad04_a843c8();
    virtual void Pad05_a843c8();
    virtual void Pad06_a843c8();
    virtual void Pad07_a843c8();
    virtual void Pad08_a843c8();
    virtual void Pad09_a843c8();
    virtual void Pad10_a843c8();
    virtual void Pad11_a843c8();
    virtual void Pad12_a843c8();
    virtual void Pad13_a843c8();
    virtual void Pad14_a843c8();
    virtual void Pad15_a843c8();
    virtual void Pad16_a843c8();
    virtual void Pad17_a843c8();
    virtual void Add18_a843c8(void* p) = 0;
    virtual void Del19_a843c8() = 0;
};
struct OB_NOVTABLE Lua2_a843c8 {
    virtual void Pad00_a843c8();
    virtual void Pad01_a843c8();
    virtual void Pad02_a843c8();
    virtual void Pad03_a843c8();
    virtual void Pad04_a843c8();
    virtual void Pad05_a843c8();
    virtual uint32_t GetTop_a843c8() = 0;
    virtual void SetTop_a843c8(uint32_t n) = 0;
    virtual void PushValue_a843c8(uint32_t n) = 0;
    virtual void Pad09_a843c8();
    virtual void Pad10_a843c8();
    virtual void Pop_a843c8(int32_t n) = 0;
    virtual void Pad12_a843c8();
    virtual void Pad13_a843c8();
    virtual bool IsNumber_a843c8(int32_t i) = 0;
    virtual void Pad15_a843c8();
    virtual void Pad16_a843c8();
    virtual void Pad17_a843c8();
    virtual void Pad18_a843c8();
    virtual void Pad19_a843c8();
    virtual void Pad20_a843c8();
    virtual void Pad21_a843c8();
    virtual void Pad22_a843c8();
    virtual double ToNumber_a843c8(int32_t i) = 0;
    virtual void Pad24_a843c8();
    virtual void Pad25_a843c8();
    virtual void Pad26_a843c8();
    virtual void Pad27_a843c8();
    virtual void Pad28_a843c8();
    virtual void Pad29_a843c8();
    virtual void Pad30_a843c8();
    virtual void PushNumber_a843c8(double d) = 0;
    virtual void Pad32_a843c8();
    virtual void Pad33_a843c8();
    virtual void Pad34_a843c8();
    virtual void Pad35_a843c8();
    virtual void Pad36_a843c8();
    virtual void GetGlobal_a843c8(const char* s) = 0;
    virtual void GetTable_a843c8(int32_t i) = 0;
    virtual void Pad39_a843c8();
    virtual void Pad40_a843c8();
    virtual void Pad41_a843c8();
    virtual void Pad42_a843c8();
    virtual void GetRef_a843c8(uint32_t ref) = 0;
    virtual void Pad44_a843c8();
    virtual void Pad45_a843c8();
    virtual void Pad46_a843c8();
    virtual void Pad47_a843c8();
    virtual void Pad48_a843c8();
    virtual void Pad49_a843c8();
    virtual uint32_t Ref_a843c8(int32_t lock) = 0;
    virtual void Pad51_a843c8();
    virtual void Pad52_a843c8();
    virtual void Pad53_a843c8();
    virtual void Pad54_a843c8();
    virtual void Pad55_a843c8();
    virtual void Pad56_a843c8();
    virtual void Pad57_a843c8();
    virtual void Pad58_a843c8();
    virtual void Pad59_a843c8();
    virtual void Pad60_a843c8();
    virtual void Pad61_a843c8();
    virtual void Pad62_a843c8();
    virtual void Pad63_a843c8();
    virtual void Pad64_a843c8();
    virtual void Pad65_a843c8();
    virtual void Pad66_a843c8();
    virtual void Pad67_a843c8();
    virtual void Pad68_a843c8();
    virtual void Pad69_a843c8();
    virtual void Pad70_a843c8();
    virtual void Pad71_a843c8();
    virtual bool IsTable_a843c8(int32_t i) = 0;
};
struct OB_NOVTABLE StrOut_a843c8 {
    virtual void Pad00_a843c8();
    virtual void Pad01_a843c8();
    virtual void Pad02_a843c8();
    virtual void Pad03_a843c8();
    virtual void Pad04_a843c8();
    virtual void Pad05_a843c8();
    virtual void Pad06_a843c8();
    virtual void Pad07_a843c8();
    virtual void Pad08_a843c8();
    virtual void Pad09_a843c8();
    virtual void Pad10_a843c8();
    virtual void Pad11_a843c8();
    virtual void Pad12_a843c8();
    virtual void Put13_a843c8(void* s) = 0;
};
struct OB_NOVTABLE ModeX_a843c8 {
    virtual void Pad00_a843c8();
    virtual void Pad01_a843c8();
    virtual void Pad02_a843c8();
    virtual void Pad03_a843c8();
    virtual uint32_t Mode4_a843c8() = 0;
};

// GLOBAL: 0x00b207c0
extern Reg_a843c8* gpB207c0_a843c8;
// GLOBAL: 0x00b07d48
extern const char* gpB07d48;

// A growable vector of 32-bit words as the lua helpers fill it.
struct Vec_a843c8 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x00423db0
    void Fn00423db0(uint32_t n);
};

// STUB: 0x005fb4e0
void Fn005fb4e0(Lua2_a843c8* lua, const char* name, float* out, uint32_t index);
// STUB: 0x005fb550 is declared above with the other Lua type
// STUB: 0x005fb630
void Fn005fb630(Lua2_a843c8* lua, const char* name, bool* out, uint32_t index);
// STUB: 0x005fb6a0
bool Fn005fb6a0(Lua2_a843c8* lua, const char* name, uint32_t index);
// STUB: 0x005fbe40
void Fn005fbe40(Lua2_a843c8* lua, void* vec, int32_t index);
// STUB: 0x005fc9b0
void Fn005fc9b0(Lua2_a843c8* lua, const char* name, void* out, uint32_t index);
// STUB: 0x005fb550
void Fn005fb550b(Lua2_a843c8* lua, const char* name, uint32_t* out, uint32_t index);
// STUB: 0x005fb5c0
bool Fn005fb5c0b(Lua2_a843c8* lua, const char* name, void* out, uint32_t index);

// The iterator over a lua table.
struct TableRef_a843c8 {
    uint8_t mData[0x20];
    // STUB: 0x005fb9c0
    TableRef_a843c8(Lua2_a843c8* lua, int32_t index);
    // STUB: 0x005fb730
    void begin();
    // STUB: 0x005fb770
    void next();
    bool AtEnd() { return mData[0x1c] != 0; }
    ~TableRef_a843c8()
    {
        void* p = *reinterpret_cast<void**>(&mData[8]);
        if (p) {
            Fn0090cf63(p);
        }
    }
};

struct ListC_a843c8 {
    // STUB: 0x0050a2a0
    void Fn0050a2a0();
    // STUB: 0x00423430 is ListS_a843c8::PushBack
};

#ifdef OB_DRAFTS
// CLOSE: 0x00423e20 score 71
void cSC4CitySituationAdvice::Slot55_a843c8()
{
    Lua2_a843c8* lua = reinterpret_cast<Lua2_a843c8*>(gpB43ce8_a843c8);
    if (!lua || FLD_a843c8(int32_t, 0x198) == -2) {
        return;
    }
    uint32_t top = lua->GetTop_a843c8();
    lua->GetRef_a843c8(FLD_a843c8(uint32_t, 0x198));
    uint32_t idx = lua->GetTop_a843c8();
    uint32_t tmp;
    Fn005fb550b(lua, "condition", &tmp, idx);
    FLD_a843c8(uint32_t, 0xc4) = tmp;
    Fn005fb4e0(lua, "time_limit", &FLD_a843c8(float, 0xc8), idx);
    Fn005fb4e0(lua, "success_distance", &FLD_a843c8(float, 0xcc), idx);
    Fn005fb4e0(lua, "min_target_distance", &FLD_a843c8(float, 0xd0), idx);
    Fn005fb4e0(lua, "max_target_distance", &FLD_a843c8(float, 0xd4), idx);
    Fn005fb4e0(lua, "success_timeout", &FLD_a843c8(float, 0xd8), idx);
    Fn005fb4e0(lua, "delay_after_disabled", &FLD_a843c8(float, 0xdc), idx);
    Fn005fb4e0(lua, "active_radius", &FLD_a843c8(float, 0x114), idx);
    bool flag = false;
    Fn005fb630(lua, "service_mission", &flag, idx);
    if (flag) {
        FLD_a843c8(uint32_t, 0xe0) |= 8;
    }
    bool flag2 = false;
    Fn005fb630(lua, "use_lot_boundary", &flag2, idx);
    if (flag2) {
        FLD_a843c8(uint32_t, 0xe0) |= 0x10;
    }
    bool flag3 = false;
    Fn005fb630(lua, "mysim_mission", &flag3, idx);
    if (flag3) {
        FLD_a843c8(uint32_t, 0xe0) |= 0x20;
    }
    bool flag4 = false;
    Fn005fb630(lua, "pursuit_mission", &flag4, idx);
    if (flag4) {
        FLD_a843c8(uint32_t, 0xe0) |= 0x80;
    }
    if (Fn005fb6a0(lua, "evade_list", idx)) {
        if (!flag4) {
            FLD_a843c8(uint32_t, 0xe0) |= 2;
        }
        Fn005fbe40(lua, &FLD_a843c8(uint8_t, 0x118), -1);
        Fn005fb4e0(lua, "evade_distance", &FLD_a843c8(float, 0x124), idx);
        Fn005fb4e0(lua, "evade_timeout", &FLD_a843c8(float, 0x128), idx);
    }
    uint32_t type;
    Fn005fb550b(lua, "coverage_type", &type, idx);
    FLD_a843c8(uint32_t, 0x12c) = type;
    switch (type) {
    case 1: {
        uint32_t zone;
        Fn005fb550b(lua, "coverage_zone", &zone, idx);
        FLD_a843c8(uint32_t, 0x130) = zone;
        break;
    }
    case 2:
        Fn005fb550b(lua, "coverage_lot", &FLD_a843c8(uint32_t, 0x134), idx);
        break;
    case 3:
        Fn005fb550b(lua, "coverage_network", &FLD_a843c8(uint32_t, 0x138), idx);
        break;
    case 4: {
        uint16_t rect[4] = {0, 0, 0, 0};
        FLD_a843c8(uint32_t, 0x13c) = *reinterpret_cast<uint32_t*>(&rect[0]);
        FLD_a843c8(uint32_t, 0x140) = *reinterpret_cast<uint32_t*>(&rect[2]);
        Vec_a843c8 vec;
        vec.mpBegin = 0;
        vec.mpEnd = 0;
        vec.mpCap = 0;
        if (Fn005fb6a0(lua, "coverage_rect", idx)) {
            Fn005fbe40(lua, &vec, -1);
            if (static_cast<uint32_t>(vec.mpEnd - vec.mpBegin) < 4) {
                vec.Fn00423db0(4);
            }
            FLD_a843c8(uint16_t, 0x13c) = static_cast<uint16_t>(vec.mpBegin[0]);
            FLD_a843c8(uint16_t, 0x13e) = static_cast<uint16_t>(vec.mpBegin[1]);
            FLD_a843c8(uint16_t, 0x140) = static_cast<uint16_t>(vec.mpBegin[2]);
            FLD_a843c8(uint16_t, 0x142) = static_cast<uint16_t>(vec.mpBegin[3]);
        }
        if (vec.mpBegin) {
            Fn0090cf63(vec.mpBegin);
        }
        break;
    }
    case 7: {
        reinterpret_cast<ListC_a843c8*>(&FLD_a843c8(uint8_t, 0x144))->Fn0050a2a0();
        if (Fn005fb6a0(lua, "coverage_cells", idx)) {
            TableRef_a843c8 ref(lua, -1);
            ref.begin();
            while (!ref.AtEnd()) {
                if (lua->IsTable_a843c8(-1)) {
                    Vec_a843c8 pair;
                    pair.mpBegin = 0;
                    pair.mpEnd = 0;
                    pair.mpCap = 0;
                    Fn005fbe40(lua, &pair, -1);
                    if (static_cast<uint32_t>(pair.mpEnd - pair.mpBegin) >= 2) {
                        uint16_t pt[2];
                        pt[0] = static_cast<uint16_t>(pair.mpBegin[0]);
                        pt[1] = static_cast<uint16_t>(pair.mpBegin[1]);
                        reinterpret_cast<ListS_a843c8*>(&FLD_a843c8(uint8_t, 0x144))->PushBack(pt);
                    }
                    if (pair.mpBegin) {
                        Fn0090cf63(pair.mpBegin);
                    }
                }
                ref.next();
            }
            lua->Pop_a843c8(1);
        }
        break;
    }
    default:
        break;
    }
    Fn005fb550b(lua, "coverage_cells_min", &FLD_a843c8(uint32_t, 0x148), idx);
    Fn005fb550b(lua, "coverage_cells_max", &FLD_a843c8(uint32_t, 0x14c), idx);
    Fn005fb550b(lua, "coverage_success_count", &FLD_a843c8(uint32_t, 0x150), idx);
    float pct = 100.0f;
    Fn005fb4e0(lua, "coverage_success_pct", &pct, idx);
    FLD_a843c8(float, 0x154) = pct * 0.01f;
    Fn005fb550b(lua, "evil_twin", &FLD_a843c8(uint32_t, 0x108), idx);
    Fn005fb550b(lua, "reward_guid", &FLD_a843c8(uint32_t, 0x110), idx);
    Fn005fb4e0(lua, "success_aura_radius", &FLD_a843c8(float, 0x158), idx);
    Fn005fb4e0(lua, "success_aura_magnitude", &FLD_a843c8(float, 0x15c), idx);
    Fn005fc9b0(lua, "success_effect", &FLD_a843c8(uint8_t, 0x160), idx);
    Fn005fb5c0b(lua, "success_money", &FLD_a843c8(uint8_t, 0x174), idx);
    Fn005fb4e0(lua, "failure_aura_radius", &FLD_a843c8(float, 0x178), idx);
    Fn005fb4e0(lua, "failure_aura_magnitude", &FLD_a843c8(float, 0x17c), idx);
    Fn005fc9b0(lua, "failure_effect", &FLD_a843c8(uint8_t, 0x180), idx);
    Fn005fb5c0b(lua, "failure_money", &FLD_a843c8(uint8_t, 0x194), idx);
    lua->SetTop_a843c8(top);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004239d0 score 166
bool cSC4CitySituationAdvice::Slot03_a80710(uint32_t a)
{
    bool ok = cSC4Advice::Slot03_a80710(a);
    Slot14_a80710(0x2000, 1);
    Lua2_a843c8* lua = reinterpret_cast<Lua2_a843c8*>(gpB43ce8_a843c8);
    if (lua) {
        uint8_t* flagByte = static_cast<uint8_t*>(Fn0090cf54(8));
        *flagByte = 0;
        Reg_a843c8* reg = gpB207c0_a843c8;
        reg->Add18_a843c8(static_cast<cSC4Advice*>(this));
        uint32_t top = lua->GetTop_a843c8();
        lua->GetGlobal_a843c8(gpB07d48);
        lua->PushNumber_a843c8(static_cast<double>(FLD_a843c8(int32_t, 0x8c)));
        lua->GetTable_a843c8(-2);
        if (!lua->IsTable_a843c8(-1)) {
            lua->SetTop_a843c8(top);
            reg->Del19_a843c8();
            Fn0090cf63(flagByte);
            return false;
        }
        uint32_t idx = lua->GetTop_a843c8();
        lua->PushValue_a843c8(idx);
        FLD_a843c8(uint32_t, 0x198) = lua->Ref_a843c8(1);
        if (Fn005fb6a0(lua, "evade_list", idx)) {
            if (lua->IsTable_a843c8(-1)) {
                Fn005fbe40(lua, &FLD_a843c8(uint8_t, 0xe4), -1);
            } else if (lua->IsNumber_a843c8(-1)) {
                uint32_t v = static_cast<uint32_t>(lua->ToNumber_a843c8(-1));
                FLD_a843c8(Vec_a843c8, 0xe4).mpEnd = FLD_a843c8(Vec_a843c8, 0xe4).mpEnd;
                (void)v;
            }
            lua->Pop_a843c8(1);
        }
        if (Fn005fb6a0(lua, "target_list", idx)) {
            FLD_a843c8(uint32_t, 0xe0) |= 4;
            lua->Pop_a843c8(1);
        }
        bool b1 = false;
        Fn005fb630(lua, "service_mission", &b1, idx);
        if (b1) {
            FLD_a843c8(uint32_t, 0xe0) |= 1;
        }
        bool b2 = false;
        Fn005fb630(lua, "use_lot_boundary", &b2, idx);
        if (b2) {
            FLD_a843c8(uint32_t, 0xe0) |= 0x100;
        }
        bool b3 = false;
        Fn005fb630(lua, "mysim_mission", &b3, idx);
        if (b3) {
            FLD_a843c8(uint32_t, 0xe0) |= 0x40;
        }
        Slot55_a843c8();
        lua->SetTop_a843c8(top);
        Fn0090cf63(flagByte);
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00423d20 score 29
bool cSC4CitySituationAdvice::Slot05_a843c8(uint32_t a)
{
    uint32_t id;
    switch (Slot04_a843c8()) {
    case 1:
        id = 0xc2bd5fb;
        break;
    case 2:
        id = 0x2c2bd613;
        break;
    case 3:
        id = 0xc2bd605;
        break;
    case 5:
        id = 0x8c2bd60a;
        break;
    default:
        return false;
    }
    SLStr_a843c8 text(0x6a231ea4, id, true);
    OB_PTR(StrOut_a843c8, a)->Put13_a843c8(&text);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004243b0 score 28
uint32_t cSC4CitySituationAdvice::Slot47_a843c8(uint32_t a)
{
    WStrW_a843c8* src = &FLD_a843c8(WStrW_a843c8, 0x160);
    WStr_a843c8* dst = reinterpret_cast<WStr_a843c8*>(OB_PTR(uint8_t, a) + 4);
    if (reinterpret_cast<uint8_t*>(src) + 4 != reinterpret_cast<uint8_t*>(dst)) {
        dst->Assign(src->mpBegin, src->mpEnd);
    }
    return dst->mpEnd != dst->mpBegin;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00424400 score 28
uint32_t cSC4CitySituationAdvice::Slot50_a843c8(uint32_t a)
{
    WStrW_a843c8* src = &FLD_a843c8(WStrW_a843c8, 0x180);
    WStr_a843c8* dst = reinterpret_cast<WStr_a843c8*>(OB_PTR(uint8_t, a) + 4);
    if (reinterpret_cast<uint8_t*>(src) + 4 != reinterpret_cast<uint8_t*>(dst)) {
        dst->Assign(src->mpBegin, src->mpEnd);
    }
    return dst->mpEnd != dst->mpBegin;
}
#endif

// ---- batch 3 ----
// The adviser's text object: a script-localised string with a wide string inside.
struct ADV_a843c8 {
    uint8_t mData[0x20];
    // STUB: 0x00603000
    void Fn00603000();
    // STUB: 0x004179f0
    void FromScriptText(const char* text, uint32_t length);
    // STUB: 0x00603300
    bool Load(bool a, bool b);
    // STUB: 0x00424380
    void Assign(const void* other);
    // STUB: 0x00602fb0
    bool Fn00602fb0(void* detokenizer, uint32_t flag);
    // STUB: 0x00408a70
    void AssignWide(const uint16_t* first, const uint16_t* last, void* tag);
};

// GLOBAL: 0x00b20dbc
extern ADV_a843c8 gB20dbc;
// GLOBAL: 0x00b20ddc
extern uint32_t gB20ddc;
// GLOBAL: 0x00b20d98
extern ADV_a843c8 gB20d98;
// GLOBAL: 0x00b20db8
extern uint32_t gB20db8;
// GLOBAL: 0x00b20de0
extern ADV_a843c8 gB20de0;

// A string of the runtime's own kind that the table helpers fill.
struct RZStr_a843c8 {
    uint8_t mData[0x14];
    // STUB: 0x00578390
    RZStr_a843c8();
    // STUB: 0x0090e4b6
    uint32_t Strlen() const;
    // STUB: 0x009d7e63
    const char* ToChar();
    ~RZStr_a843c8()
    {
        void* p = *reinterpret_cast<void**>(&mData[4]);
        if (p) {
            Fn0090cf63(p);
        }
    }
};

#ifdef OB_DRAFTS
// CLOSE: 0x00424600 score 125
void* cSC4CitySituationAdvice::ReadStringFromTable(const char* name)
{
    if (!(gB20ddc & 1)) {
        gB20ddc |= 1;
        gB20dbc.Fn00603000();
    }
    gB20dbc.AssignWide(0, 0, 0);
    if (FLD_a843c8(int32_t, 0x198) != -2) {
        Lua2_a843c8* lua = reinterpret_cast<Lua2_a843c8*>(gpB43ce8_a843c8);
        if (lua) {
            uint32_t top = lua->GetTop_a843c8();
            lua->GetRef_a843c8(FLD_a843c8(uint32_t, 0x198));
            uint32_t idx = lua->GetTop_a843c8();
            if (idx != top) {
                RZStr_a843c8 tmp;
                Fn005fc9b0(lua, name, &tmp, idx);
                uint32_t len = tmp.Strlen();
                gB20dbc.FromScriptText(tmp.ToChar(), len);
                if (!gB20dbc.Load(true, true)) {
                    gB20dbc.Assign(&tmp);
                    gB20dbc.Fn00602fb0(0, 1);
                }
            }
            lua->SetTop_a843c8(top);
        }
    }
    return &gB20dbc;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00424450 score 141
uint32_t cSC4CitySituationAdvice::Slot24_a843c8(uint32_t n)
{
    if (!(gB20db8 & 1)) {
        gB20db8 |= 1;
        gB20d98.Fn00603000();
    }
    gB20d98.AssignWide(0, 0, 0);
    uint16_t which = static_cast<uint16_t>(n);
    if (which != 0 && FLD_a843c8(int32_t, 0x198) != -2) {
        Lua2_a843c8* lua = reinterpret_cast<Lua2_a843c8*>(gpB43ce8_a843c8);
        if (lua) {
            uint32_t top = lua->GetTop_a843c8();
            lua->GetRef_a843c8(FLD_a843c8(uint32_t, 0x198));
            uint32_t idx = lua->GetTop_a843c8();
            if (idx != top && Fn005fb6a0(lua, "progress_text", idx)) {
                struct StrVec_a843c8 {
                    uint8_t* mpBegin;
                    uint8_t* mpEnd;
                    uint8_t* mpCap;
                } strings;
                strings.mpBegin = 0;
                strings.mpEnd = 0;
                strings.mpCap = 0;
                Fn005fb6a0(lua, "progress_text", idx);
                uint32_t count = static_cast<uint32_t>(strings.mpEnd - strings.mpBegin) / 0x14;
                uint32_t pick = static_cast<uint32_t>(which - 1) & 0xffff;
                if (count <= pick) {
                    pick = 0;
                }
                if (pick < count) {
                    RZStr_a843c8* s = reinterpret_cast<RZStr_a843c8*>(strings.mpBegin + pick * 0x14);
                    gB20d98.FromScriptText(s->ToChar(), s->Strlen());
                    if (!gB20d98.Load(true, true)) {
                        gB20d98.Assign(s);
                        gB20d98.Fn00602fb0(0, 1);
                    }
                }
            }
            lua->SetTop_a843c8(top);
        }
    }
    return OB_ADDR(&gB20d98);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00424760 score 203
void* cSC4CitySituationAdvice::Slot20_a80710()
{
    if (!(gB20de4 & 1)) {
        gB20de4 |= 1;
        gB20de0.Fn00603000();
    }
    void* message = ReadStringFromTable("message");
    RZStr_a843c8 text;
    (void)message;
    if (FLD_a843c8(uint32_t, 0x104) != 0) {
        cSC4Advice::Slot11_a80710();
        SLStr_a843c8 fmt(0x6a231ea4, 0x2c104d8c, false);
        ADV_a843c8 formatted;
        formatted.Fn00603000();
        formatted.Fn00602fb0(0, 1);
        gB20de0.Assign(&formatted);
    }
    return &gB20de0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00602fb0 score 10
bool ADV_a843c8::Fn00602fb0(void* detokenizer, uint32_t flag)
{
    Sink_a843c8* sink = reinterpret_cast<Sink_a843c8*>(detokenizer);
    if (!sink) {
        sink = gpB43cdc;
    }
    if (sink) {
        bool saved = sink->Get11_a843c8();
        sink->Put10_a843c8(flag);
        sink->Put9_a843c8(this, this);
        sink->Put10_a843c8(saved);
    }
    return false;
}
#endif
