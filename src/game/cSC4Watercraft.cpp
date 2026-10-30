#include <cmath>
#include <cstddef>
#include <cstring>

#include "classes/cSC4Watercraft.h"
#include "gzcom/cRZString.h"
#include "game/Globals.h"

struct Vec3_a9dbb8 {
    float x;
    float y;
    float z;
};

struct Vec3u_a9dbb8 {
    uint32_t x;
    uint32_t y;
    uint32_t z;
};

// A state with the float table at +0x7c (also readable as raw words).
struct FloatState_a9dbb8 {
    uint8_t mPad[0x7c];
    union {
        float mf7c[1];
        uint32_t mn7c[1];
    };
};

// GLOBAL: 0x00b21c84
extern float gfB21c84;

// Two bytes stored as one 16-bit value.
struct Pair_a9dbb8 {
    uint8_t lo;
    uint8_t hi;
};

// The object seen from the subobject at +0x4 (offsets are the object's minus 4).
struct Sub4_a9dbb8 {
    uint8_t mPad[0x28];
    uint8_t mBytes28[4];
    uint8_t mb2c;
    uint8_t mb2d;
    uint8_t mbFlags2e;
    uint8_t mbFlags2f;
    void* mp30;
    uint8_t mPad34[0x16c - 0x34];
    float mf16c;
    float mf170;
    float mf174;
    float mf178;
    float mf17c;
    float mf180;
};

// An effect handle the embedded object hands out; only the slot called here is named.
struct Effect_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Fn03(uint32_t);
};

// The object embedded at +0x18c (its vtable pointer first); only the slots called here are named.
struct Embedded_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Fn02(uint32_t);
    virtual void Pad03();
    virtual void Fn04(const void*, const void*, float);
    virtual void Pad05();
    virtual void Pad06();
    virtual void Fn07(uint32_t);
    virtual void Pad08();
    virtual Effect_a9dbb8* Fn09(void*, void*);
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13(uint32_t, uint32_t);
    virtual void Fn14(uint32_t, uint32_t, uint32_t);
    virtual void Fn15(uint32_t, uint32_t, uint32_t);
};

inline Embedded_a9dbb8* EmbeddedOf_a9dbb8(cSC4Watercraft* self)
{
    return reinterpret_cast<Embedded_a9dbb8*>(reinterpret_cast<char*>(self) + 0x18c);
}

// A group template: its parent link sits at +0xc.
struct cOccupantGroup_a9dbb8 {
    uint8_t mPad[0xc];
    cOccupantGroup_a9dbb8* mpParent;
    uint32_t mnId10;
    uint8_t mPad14[0x44];
    float mf58;
    float mf5c;
    uint8_t mPad60[0x70 - 0x60];
    uint8_t mEffects[0x10];
    uint32_t mnEffectCount80;
    int32_t GetGroupHierarchyDepth();
    float Fn00505300();
    // STUB: 0x0046b4a0
    void* Fn0046b4a0();
};


// FUNCTION: 0x00458a40
uint32_t cSC4Watercraft_4::Slot05_a9dbb8_4()
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    return self->mbFlags2e & 1;
}

// FUNCTION: 0x00458a50
uint32_t cSC4Watercraft_4::Slot16_a9dbb8_4()
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    return self->mbFlags2e >> 4;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004fad60 score 8
bool cSC4Watercraft::CheckAutomataFlag(uint32_t flag)
{
    return (flag & mnAutomataFlags) != 0;
}
#endif

// FUNCTION: 0x004fad70
bool cSC4Watercraft::GetDisabled()
{
    return CheckAutomataFlag(0x8000000);
}

// FUNCTION: 0x004fad80
bool cSC4Watercraft::GetMarkedForRemove()
{
    return CheckAutomataFlag(1);
}

// FUNCTION: 0x004fad90
bool cSC4Watercraft::GetSelfControlling()
{
    return CheckAutomataFlag(2);
}

// FUNCTION: 0x004fada0
bool cSC4Watercraft::GetReachedDestination()
{
    return CheckAutomataFlag(4);
}

// FUNCTION: 0x004fadb0
bool cSC4Watercraft::GetSpecialRouteFlag()
{
    return CheckAutomataFlag(0x40);
}

// FUNCTION: 0x004fadc0
void cSC4Watercraft::SetMarkedForRemove(bool value)
{
    SetAutomataFlag(1, value);
}

// FUNCTION: 0x004fadd0
void cSC4Watercraft::SetSpecialRouteFlag(bool value)
{
    SetAutomataFlag(0x40, value);
}

// FUNCTION: 0x004fade0
void cSC4Watercraft::SetSelfControlling(bool value)
{
    SetAutomataFlag(2, value);
}

#ifdef OB_DRAFTS
// CLOSE: 0x004fadf0 score 2
void cSC4Watercraft::Slot44_a9dbb8()
{
    Embedded_a9dbb8* p = EmbeddedOf_a9dbb8(this);
    p->Fn12();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005059a0 score 2
void cSC4Watercraft::Slot42_a9dbb8()
{
    Embedded_a9dbb8* p = EmbeddedOf_a9dbb8(this);
    p->Fn10();
}
#endif

// FUNCTION: 0x005059b0
void cSC4Watercraft::Slot43_a9dbb8()
{
    EmbeddedOf_a9dbb8(this)->Fn11();
}

// ---- batch 2 ----

// The vector embedded at +0x14 (begin, end); Erase is the vector's erase(first, last).
struct Vec14_a9dbb8 {
    void* mpBegin;
    void* mpEnd;
    // STUB: 0x0077c420
    void Erase(void* first, void* last);
};

// A state record: the depth of the state stack when it was pushed sits at +0xc.
struct State_a9dbb8 {
    uint8_t mPad0[4];
    uint32_t mnBehavior;
    void* mpObj8;
    uint32_t mnDepth;
    float mf10;
    uint8_t mb14;
    uint8_t mPad15[3];
    uint32_t mn18;
    uint32_t mn1c;
    uint8_t mPad20[4];
    void* mp24;
    void* mpTarget;
};

// The _8 subobject's own save routine (this = the subobject).
struct View8_a9dbb8 {
    // STUB: 0x0050ac00
    bool Fn0050ac00(void* stream);
    // STUB: 0x0050dfd0
    bool Fn0050dfd0(void* stream);
};

// The stream the object is written to: slot 7 writes a 16-bit value.
// STUB-free helpers defined at the end of the file; declared here for their callers.
void** Fn005ebdf0(uint32_t);
float OB_STDCALL Fn00566e00(float value);

struct StreamOut_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Wr07(uint16_t);
};

// A smart-pointer-like element: its pointer sits first.
struct Holder_a9dbb8 {
    void* mp;
    void* Get() { return mp; }
};

// A resource key: type, group, instance.
struct Key_a9dbb8 {
    uint32_t mnType;
    uint32_t mnGroup;
    uint32_t mnInstance;
};

// GLOBAL: 0x00b21bd0
extern uint32_t gB21bd0;

#ifdef OB_DRAFTS
// CLOSE: 0x00505540 score 3
bool cSC4Watercraft::Slot15_a9dbb8(void* pOut)
{
    Vec3_a9dbb8* out = static_cast<Vec3_a9dbb8*>(pOut);
    out->x = mfVec58X;
    out->y = mfVec58Y;
    out->z = mfVec58Z;
    return true;
}
#endif

// FUNCTION: 0x005ff3c0
void cSC4Watercraft_c::Slot18_a9dbb8_c(uint32_t)
{
    Vec14_a9dbb8* v = reinterpret_cast<Vec14_a9dbb8*>(reinterpret_cast<char*>(this) + 8);
    v->Erase(v->mpBegin, v->mpEnd);
}

// FUNCTION: 0x005e8bc0
bool cSC4Watercraft_4::Slot32_a9dbb8_4(uint32_t mask)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    return (self->mbFlags2f & mask) == mask;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004fb340 score 5
void* cSC4Watercraft::GetModelInstance()
{
    if (mpModelsBegin != mpModelsEnd) {
        return reinterpret_cast<Holder_a9dbb8*>(mpModelsBegin)->Get();
    }
    return 0;
}
#endif

// FUNCTION: 0x004adb30
void cSC4Watercraft::GetTransform(void* pOut)
{
    Vec3_a9dbb8* out = static_cast<Vec3_a9dbb8*>(pOut);
    out->x = mfDestX;
    out->y = mfDestY;
    out->z = mfDestZ;
}

// FUNCTION: 0x00505520
void cSC4Watercraft::SetVisible(void* pOut)
{
    Vec3_a9dbb8* out = static_cast<Vec3_a9dbb8*>(pOut);
    out->x = mfPosX;
    out->y = mfPosY;
    out->z = mfPosZ;
}

// FUNCTION: 0x00505560
void cSC4Watercraft::GetDestination(void* pIn)
{
    Vec3_a9dbb8* in = static_cast<Vec3_a9dbb8*>(pIn);
    mfDestX = in->x;
    mfDestY = in->y;
    mfDestZ = in->z;
}

// FUNCTION: 0x00505860
void cSC4Watercraft::Slot80_a9dbb8(uint32_t, uint32_t)
{
    Slot102_a9dbb8(6, 0);
}

#ifdef OB_DRAFTS
// CLOSE: 0x005098e0 score 7
void* cSC4Watercraft::GetState()
{
    if (mpStateEnd == mpStateBegin) {
        return 0;
    }
    return mpStateEnd[-1];
}
#endif

// FUNCTION: 0x00505880
void cSC4Watercraft::PlayAnimByName(void* pName)
{
    PlayAnim(Slot76_a9dbb8(pName));
}

// FUNCTION: 0x005e8ba0
void cSC4Watercraft_4::Slot31_a9dbb8_4(uint32_t mask)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    uint32_t flags = self->mbFlags2f;
    uint32_t cleared = flags & ~mask;
    if (cleared != flags) {
        Slot30_a9dbb8_4(cleared);
    }
}

// FUNCTION: 0x00505af0
float cSC4Watercraft::GetMaxSpeed()
{
    return static_cast<float>(gB21bd0) * 2.77777814e-4f;
}

// FUNCTION: 0x00509900
void* cSC4Watercraft::PrevState(void* pState)
{
    void* result = 0;
    if (pState != 0) {
        uint32_t depth = static_cast<State_a9dbb8*>(pState)->mnDepth;
        if (depth > 0) {
            result = mpStateBegin[depth - 1];
        }
    }
    return result;
}

// FUNCTION: 0x00566ee0
bool cSC4Watercraft_8::Write(void* pStream)
{
    StreamOut_a9dbb8* stream = static_cast<StreamOut_a9dbb8*>(pStream);
    stream->Wr07(2);
    return reinterpret_cast<View8_a9dbb8*>(this)->Fn0050ac00(pStream);
}

// FUNCTION: 0x005e8b70
void cSC4Watercraft_4::Slot29_a9dbb8_4(uint32_t mask)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    uint32_t flags = self->mbFlags2f;
    uint32_t set = flags | mask;
    if (set != flags) {
        Slot30_a9dbb8_4(set);
    }
}

// FUNCTION: 0x005e8c20
void cSC4Watercraft_4::Slot26_a9dbb8_4(void* pIn)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    const uint8_t* in = static_cast<const uint8_t*>(pIn);
    self->mBytes28[0] = in[0];
    self->mBytes28[1] = in[1];
    self->mBytes28[2] = in[2];
    self->mBytes28[3] = in[3];
}

// ---- batch 3 ----

// A controller's target: slot 5 hands out the automaton interface (slots used: 25, 55, 57, 60).
struct Obj2_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual uint32_t Fn04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual bool Fn25(uint32_t);
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual bool Fn55(uint32_t);
    virtual void Pad56();
    virtual bool Fn57(uint32_t, uint32_t);
    virtual void Pad58();
    virtual void Pad59();
    virtual bool Fn60(uint32_t, uint32_t);
    virtual void Pad61();
    virtual void Pad62();
    virtual void Pad63();
    virtual void Pad64();
    virtual void Pad65();
    virtual void Pad66();
    virtual void Pad67();
    virtual void Pad68();
    virtual void Pad69();
    virtual void Pad70();
    virtual void Pad71();
    virtual void Pad72();
    virtual void Pad73();
    virtual void Pad74();
    virtual void Pad75();
    virtual void Pad76();
    virtual void Pad77();
    virtual void Pad78();
    virtual void Pad79();
    virtual void Pad80();
    virtual void Pad81();
    virtual void Pad82();
    virtual void Pad83();
    virtual void Pad84();
    virtual void Pad85();
    virtual void Pad86();
    virtual void Pad87();
    virtual void Pad88();
    virtual void Pad89();
    virtual void Pad90();
    virtual void Pad91();
    virtual void Pad92();
    virtual void Pad93();
    virtual void Pad94();
    virtual void Pad95();
    virtual void Pad96();
    virtual void Pad97();
    virtual void Pad98();
    virtual void Pad99();
    virtual void Pad100();
    virtual void Pad101();
    virtual void Pad102();
    virtual uint32_t* Fn103();
};

struct StateObj_a9dbb8 {
    virtual void Fn00(void*);
};

// What the _c subobject's lookup (Slot09_a9dbb8_c) hands out.
struct Obj1_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Obj2_a9dbb8* Fn05();
};

// The reference-counted base interface: slot 1 adds a reference, slot 2 releases one.
struct Unknown_a9dbb8 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};

// A behavior template: the speed at +0x28.
struct BehaviorTemplate_a9dbb8 {
    uint32_t mnId;
    uint8_t mPad4[0xc];
    uint8_t* mpRecBegin;
    uint8_t* mpRecEnd;
    uint8_t mPad18[4];
    int32_t* mpIntBegin;
    int32_t* mpIntEnd;
    uint8_t mPad24[4];
    float mf28;
    uint8_t mb2c;
    uint8_t mPad2d[3];
    float mf30;
    float mf34;
    int32_t mn38;
    int32_t mn3c;
    float mf40;
    float Fn00514c70();
};

// The pool of 0xb0a8c8 (a free-list allocator); the block it works from is at +4.
struct PoolBlock_a9dbb8 {
    uint8_t mPad[8];
    void** mpFree;
    int32_t mnCount;
};

struct Pool_a9dbb8 {
    uint8_t mPad[4];
    PoolBlock_a9dbb8* mpBlock;
    // STUB: 0x0090cf9a
    void** Refill();
};

// GLOBAL: 0x00b0a8c8
extern Pool_a9dbb8 gB0a8c8;





#ifdef OB_DRAFTS
// CLOSE: 0x00509920 score 13
uint32_t cSC4Watercraft::GetBehavior()
{
    void** end = mpStateEnd;
    void** begin = mpStateBegin;
    uint32_t result = 0;
    if (begin != end) {
        result = static_cast<State_a9dbb8*>(mpStateEnd[-1])->mnBehavior;
    }
    return result;
}
#endif

// FUNCTION: 0x00505940
void cSC4Watercraft::UpdateEffects()
{
    EmbeddedOf_a9dbb8(this)->Fn04(&mfPosX, &mfVec58X, field94);
}

// FUNCTION: 0x00566f30
bool cSC4Watercraft::QueryInterface(uint32_t iid, void* ppv)
{
    if (iid != 0x096e75f5) {
        return Fn00505d80(iid, ppv);
    }
    *static_cast<cSC4Watercraft**>(ppv) = this;
    AsOccupant();
    return true;
}

// FUNCTION: 0x005055c0
bool cSC4Watercraft::DoIdleTick(uint32_t)
{
    if (GetMarkedForRemove()) {
        return false;
    }
    UpdateAttraction();
    return true;
}

// FUNCTION: 0x00505970
void cSC4Watercraft::AddRegEffect(void* a, void* b)
{
    Effect_a9dbb8* effect = EmbeddedOf_a9dbb8(this)->Fn09(a, b);
    if (effect != 0) {
        effect->Fn03(0);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00510210 score 19
bool cSC4Watercraft::PlayAnim_2(void* pKey)
{
    if (static_cast<Key_a9dbb8*>(pKey)->mnInstance != 0) {
        if (mpModelsBegin != mpModelsEnd) {
            ReplaceModelInstance(*mpModelsBegin, pKey);
        }
    }
    return true;
}
#endif

// FUNCTION: 0x005fd230
bool cSC4Watercraft_c::Slot08_a9dbb8_c(uint32_t a, uint32_t b)
{
    Obj1_a9dbb8* obj = static_cast<Obj1_a9dbb8*>(Slot09_a9dbb8_c(a));
    if (obj != 0) {
        return obj->Fn05()->Fn25(b);
    }
    return false;
}

// FUNCTION: 0x005fd260
bool cSC4Watercraft_c::Slot07_a9dbb8_c(uint32_t a, uint32_t b)
{
    Obj1_a9dbb8* obj = static_cast<Obj1_a9dbb8*>(Slot09_a9dbb8_c(a));
    if (obj != 0) {
        return obj->Fn05()->Fn55(b);
    }
    return false;
}

// FUNCTION: 0x005fd290
bool cSC4Watercraft_c::Slot05_a9dbb8_c(uint32_t a, uint32_t b, uint32_t c)
{
    Obj1_a9dbb8* obj = static_cast<Obj1_a9dbb8*>(Slot09_a9dbb8_c(a));
    if (obj != 0) {
        return obj->Fn05()->Fn57(b, c);
    }
    return false;
}

// FUNCTION: 0x005fd2d0
bool cSC4Watercraft_c::Slot06_a9dbb8_c(uint32_t a, uint32_t b, uint32_t c)
{
    Obj1_a9dbb8* obj = static_cast<Obj1_a9dbb8*>(Slot09_a9dbb8_c(a));
    if (obj != 0) {
        return obj->Fn05()->Fn60(b, c);
    }
    return false;
}

// FUNCTION: 0x004fae00
void cSC4Watercraft::Slot45_a9dbb8(uint32_t a, uint32_t b)
{
    EmbeddedOf_a9dbb8(this)->Fn13(a, b);
    UpdateEffects();
}

// FUNCTION: 0x004fae30
void cSC4Watercraft::Slot46_a9dbb8(uint32_t a, uint32_t b, uint32_t c)
{
    EmbeddedOf_a9dbb8(this)->Fn14(a, b, c);
    UpdateEffects();
}

// FUNCTION: 0x004fae60
void cSC4Watercraft::Slot47_a9dbb8(uint32_t a, uint32_t b, uint32_t c)
{
    EmbeddedOf_a9dbb8(this)->Fn15(a, b, c);
    UpdateEffects();
}

// FUNCTION: 0x0050b710
void* cSC4Watercraft::FindState(uint32_t id)
{
    void** end = mpStateEnd;
    void** begin = mpStateBegin;
    while (end != begin) {
        State_a9dbb8* state = static_cast<State_a9dbb8*>(end[-1]);
        if (state->mnBehavior == id) {
            return state;
        }
        --end;
    }
    return 0;
}

// FUNCTION: 0x005e8bf0
bool cSC4Watercraft_4::Slot25_a9dbb8_4(void* pOut)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    uint8_t* out = static_cast<uint8_t*>(pOut);
    uint8_t first = self->mBytes28[0];
    if (first == 0xff) {
        return false;
    }
    out[0] = first;
    out[1] = self->mBytes28[1];
    out[2] = self->mBytes28[2];
    out[3] = self->mBytes28[3];
    return true;
}

// FUNCTION: 0x005e8ae0
bool cSC4Watercraft_4::Slot14_a9dbb8_4(uint32_t which)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    uint8_t kind = static_cast<uint8_t>(which);
    if (kind & 1) {
        return self->mb2d == 0;
    }
    if (kind & 2) {
        return self->mb2c == 0;
    }
    return true;
}

// FUNCTION: 0x00458e60
void cSC4Watercraft_20::SetDefaultExemplar(void* pExemplar)
{
    Unknown_a9dbb8* exemplar = static_cast<Unknown_a9dbb8*>(pExemplar);
    Unknown_a9dbb8* old = static_cast<Unknown_a9dbb8*>(mpDefaultExemplar);
    if (exemplar != old) {
        if (exemplar != 0) {
            exemplar->AddRef();
        }
        mpDefaultExemplar = exemplar;
        if (old != 0) {
            old->Release();
        }
    }
}

// FUNCTION: 0x0078daf0
void cSC4Watercraft_4::Slot21_a9dbb8_4(void* pObject)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    Unknown_a9dbb8* object = static_cast<Unknown_a9dbb8*>(pObject);
    Unknown_a9dbb8* old = static_cast<Unknown_a9dbb8*>(self->mp30);
    if (object != old) {
        if (object != 0) {
            object->AddRef();
        }
        self->mp30 = object;
        if (old != 0) {
            old->Release();
        }
    }
}

// ---- batch 4 ----

struct ScriptSys_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void* Fn06(uint32_t);
};

struct WatercraftMgr_a9dbb8;

struct Terrain_a9dbb8 {
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
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual float Fn18(float, float);
};

struct AutoMgr_a9dbb8 {
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
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void* Fn22(void*, void*, void*, void*);
};

struct City_a9dbb8 {
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
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual Terrain_a9dbb8* Fn40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual WatercraftMgr_a9dbb8* Fn46();
    virtual AutoMgr_a9dbb8* Fn47();
    virtual ScriptSys_a9dbb8* Fn48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual void Pad55();
    virtual void Pad56();
    virtual void Pad57();
    virtual void Pad58();
    virtual void Pad59();
    virtual void Pad60();
    virtual void Pad61();
    virtual void Pad62();
    virtual void Pad63();
    virtual void Pad64();
    virtual void Pad65();
    virtual void Pad66();
    virtual void Pad67();
    virtual void Pad68();
    virtual void Pad69();
    virtual void Pad70();
    virtual void Pad71();
    virtual void Pad72();
    virtual void Pad73();
    virtual void Pad74();
    virtual void Pad75();
    virtual void Pad76();
    virtual void Pad77();
    virtual void Pad78();
    virtual void Pad79();
    virtual void Pad80();
    virtual void Pad81();
    virtual void Pad82();
    virtual void Pad83();
    virtual void Pad84();
    virtual void Pad85();
    virtual void Pad86();
    virtual void Pad87();
    virtual void Pad88();
    virtual void Pad89();
    virtual void Pad90();
    virtual void Pad91();
    virtual void Pad92();
    virtual int32_t Fn93();
    virtual int32_t Fn94();
    virtual void Fn95(float, float, int32_t*, int32_t*);
    virtual void Pad96();
    virtual void Pad97();
    virtual void Pad98();
    virtual bool Fn99(int32_t, int32_t);
};

// GLOBAL: 0x00b43cec
extern City_a9dbb8* gpB43cec_a9dbb8;

// GLOBAL: 0x00b09964
extern float gfB09964;

struct Releasable53_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
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
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Fn53();
};

// The interface the model instances share through their virtual base (the base sits after the vtable pointer and the base pointer).
struct ModelVBase_a9dbb8 {
    virtual void VPad00();
    virtual void AddRef();
    virtual void Release();
    virtual void VPad03();
    virtual void VPad04();
    virtual void VPad05();
    virtual void VPad06();
    virtual void VPad07();
    virtual void Fn08(void*);
    virtual void Fn09(void*);
    virtual void Fn10(void*);
    virtual void VPad11();
    virtual void VPad12();
    virtual void VPad13();
    virtual void VPad14();
    virtual void Fn15(void*);
    virtual void Fn16(void*);
};

// A model instance: its own slots, and a virtual base reached through the base pointer at +4.
struct ModelInst_a9dbb8 : virtual ModelVBase_a9dbb8 {
    using ModelVBase_a9dbb8::Fn08;  // the overloads below hide these otherwise (name lookup only, no code)
    using ModelVBase_a9dbb8::Fn15;
    using ModelVBase_a9dbb8::Fn16;
    virtual void* Fn00();
    virtual void Fn01(void*);
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn08(uint32_t, uint32_t);
    virtual void Pad09();
    virtual void Pad10();
    virtual int32_t Fn11();
    virtual int32_t Fn12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Fn15(float);
    virtual void Fn16(uint32_t);
    virtual void Pad17();
    virtual void Fn18(uint32_t, float);
};

struct StreamIn_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Rd07(uint16_t*);
};

// The ramped value embedded at +0x1a0: where it started, where it is going, and the rest of the ramp.
struct Ramp_a9dbb8 {
    float mfFrom;
    float mfTo;
    float mfB;
    union {
        uint32_t mnC;
        float mfC;
    };
    // STUB: 0x004fa960
    float Fn004fa960();
};

// A node of the callback list: next, previous, the callback.
struct ListNode_a9dbb8 {
    ListNode_a9dbb8* mpNext;
    ListNode_a9dbb8* mpPrev;
    Unknown_a9dbb8* mpValue;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* block);

// A node of the key-effect hashtable: next link, then the unsigned-char key.
struct HNode_a9dbb8 {
    HNode_a9dbb8* mpNext;
    uint8_t mnKey;
};

struct HTable_a9dbb8 {
    uint32_t mnPad0;
    HNode_a9dbb8** mpBegin;
    HNode_a9dbb8** mpEnd;
};

struct HIter_a9dbb8 {
    HNode_a9dbb8* mpCur;
    HTable_a9dbb8* mpTable;
    HNode_a9dbb8* Fn0050bbe0();
};

// The string argument of the group lookup: the base at +4 is what the table takes.
struct StrBase_a9dbb8 {
    virtual void Pad00();
};

struct StrOwner_a9dbb8 {
    virtual void Pad00();
};

struct Str_a9dbb8 : StrOwner_a9dbb8, StrBase_a9dbb8 {
};

struct GroupNode_a9dbb8 {
    uint8_t mPad[0x10];
    uint32_t mnValue;
};

struct GroupTable_a9dbb8 {
    // STUB: 0x0051c9f0
    GroupNode_a9dbb8* Find(StrBase_a9dbb8* name);
};

struct GroupMgr_a9dbb8 {
    uint8_t mPad[0x34];
    GroupTable_a9dbb8 mTable;
    bool Fn0051d970(Str_a9dbb8* name, uint32_t* pOut);
};



// FUNCTION: 0x00566f00
bool cSC4Watercraft_8::Read(void* pStream)
{
    StreamIn_a9dbb8* stream = static_cast<StreamIn_a9dbb8*>(pStream);
    uint16_t version;
    stream->Rd07(&version);
    if (version != 2) {
        return false;
    }
    return reinterpret_cast<View8_a9dbb8*>(this)->Fn0050dfd0(pStream);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00509400 score 25
bool cSC4Watercraft::Remove(void* arg)
{
    void** begin = mpModelsBegin;
    void** end = mpModelsEnd;
    if (begin != end) {
        ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*begin);
        ModelVBase_a9dbb8& base = *model;
        base.Fn09(arg);
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005e8a60 score 27
void cSC4Watercraft_4::Slot12_a9dbb8_4(uint32_t which)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    Pair_a9dbb8 v = { self->mb2c, self->mb2d };
    if (which & 1) {
        v.hi = v.hi + 1;
        *reinterpret_cast<Pair_a9dbb8*>(&self->mb2c) = v;
    }
    if (which & 2) {
        v.lo = v.lo + 1;
        *reinterpret_cast<Pair_a9dbb8*>(&self->mb2c) = v;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005e8aa0 score 27
void cSC4Watercraft_4::Slot13_a9dbb8_4(uint32_t which)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    Pair_a9dbb8 v = { self->mb2c, self->mb2d };
    if (which & 1) {
        v.hi = v.hi - 1;
        *reinterpret_cast<Pair_a9dbb8*>(&self->mb2c) = v;
    }
    if (which & 2) {
        v.lo = v.lo - 1;
        *reinterpret_cast<Pair_a9dbb8*>(&self->mb2c) = v;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004fad20 score 15
void cSC4Watercraft::SetAutomataFlag(uint32_t flag, bool on)
{
    if (on) {
        mnAutomataFlags |= flag;
    } else {
        mnAutomataFlags &= ~flag;
    }
}
#endif

// FUNCTION: 0x00507d50
void cSC4Watercraft::SetLeader(void* pLeader)
{
    Unknown_a9dbb8* leader = static_cast<Unknown_a9dbb8*>(pLeader);
    Unknown_a9dbb8* old = static_cast<Unknown_a9dbb8*>(mpLeader);
    if (leader != old) {
        if (leader != 0) {
            leader->AddRef();
        }
        mpLeader = leader;
        if (old != 0) {
            old->Release();
        }
    }
}

// FUNCTION: 0x00505ab0
float cSC4Watercraft::GetSpeedModifier()
{
    if (CheckAutomataFlag(0x80)) {
        if (gfB09964 > 0.0f) {
            return 1.0f;
        }
        return 0.0f;
    }
    return gfB09964;
}

// FUNCTION: 0x00505b10
void cSC4Watercraft::SetBehavior(void* a, void* b)
{
    HandleExitState(GetState());
    ClearStateStack();
    PushBehavior(a, b);
}

// FUNCTION: 0x004fb570
void cSC4Watercraft::SetSpeed(float speed, float b)
{
    Ramp_a9dbb8* ramp = reinterpret_cast<Ramp_a9dbb8*>(reinterpret_cast<char*>(this) + 0x1a0);
    if (speed != ramp->mfTo) {
        ramp->mfFrom = ramp->Fn004fa960();
        ramp->mfTo = speed;
        ramp->mfB = b;
        ramp->mnC = 0;
    }
}

// FUNCTION: 0x00505d40
void* cSC4Watercraft::GetAutomataGroup()
{
    void* result = 0;
    if (mnGroupId != 0) {
        if (gpB43cec_a9dbb8 != 0) {
            ScriptSys_a9dbb8* system = gpB43cec_a9dbb8->Fn48();
            if (system != 0) {
                result = system->Fn06(mnGroupId);
            }
        }
    }
    return result;
}

// FUNCTION: 0x00505580
void cSC4Watercraft_4::Slot10_a9dbb8_4(void* pA, void* pB)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    Vec3_a9dbb8* a = static_cast<Vec3_a9dbb8*>(pA);
    Vec3_a9dbb8* b = static_cast<Vec3_a9dbb8*>(pB);
    a->x = self->mf16c;
    a->y = self->mf170;
    a->z = self->mf174;
    b->x = self->mf178;
    b->y = self->mf17c;
    b->z = self->mf180;
}

// FUNCTION: 0x00505820
void cSC4Watercraft::HandleReachedRouteDestination()
{
    SetAutomataFlag(4, true);
    SetAutomataFlag(0x20, true);
    Slot102_a9dbb8(5, 0);
    if (!CheckAutomataFlag(0x1000000)) {
        SetOrientation(0);
    }
}

// FUNCTION: 0x00509660
void cSC4Watercraft::SetZoomAndRotation(uint32_t zoom, uint32_t rotation)
{
    if (mpModelsBegin != mpModelsEnd) {
        void** it = mpModelsBegin;
        do {
            ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
            if (model != 0) {
                model->Fn08(zoom, rotation);
            }
            ++it;
        } while (it != mpModelsEnd);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0050bb90 score 21
void cSC4Watercraft::RemoveCallback(void* pCallback)
{
    ListNode_a9dbb8* head = static_cast<ListNode_a9dbb8*>(mpCallbacks);
    ListNode_a9dbb8* node;
    for (node = head->mpNext; node != head; node = node->mpNext) {
        if (node->mpValue == pCallback) {
            break;
        }
    }
    if (node != head) {
        ListNode_a9dbb8* prev = node->mpPrev;
        ListNode_a9dbb8* next = node->mpNext;
        prev->mpNext = next;
        next->mpPrev = prev;
        if (node->mpValue != 0) {
            node->mpValue->Release();
        }
        Fn0090cf63(node);
    }
}
#endif


// ---- batch 5 ----

struct Target_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Fn07(void*);
};

struct Renderer_a9dbb8 {
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
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual bool Fn27(void*);
    virtual bool Fn28(void*);
    virtual void Fn29(void*);
    virtual void Fn30(void*);
    virtual void Fn31(void*);
};

// GLOBAL: 0x00b43dd0
extern Renderer_a9dbb8* gpB43dd0;

// The object at +0x12c: a smart pointer whose assignment returns whether it took the value.
struct Light_a9dbb8 {
    void* mpValue;
    // STUB: 0x008038d0
    bool Fn008038d0(void* value);
    // STUB: 0x00803e10
    void Fn00803e10(void* manager, uint32_t flag);
};

// A 0x30-byte record from the pool allocator (vtable 0x00aa4468), reference counted through slots 1 and 2.
struct Record_a9dbb8 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    uint8_t mData[0x2c];
    // STUB: 0x005ec370
    Record_a9dbb8();
    static void* operator new(size_t size) { return Fn005ebdf0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// STUB: 0x005e5620
void Fn005e5620(void* block);

// STUB: 0x005fe940
void* Fn005fe940(void* first, void* last, void* pProbe, uint32_t key, uint32_t zero);

// STUB: 0x004696c0
void* Fn004696c0(void* first, void* last, const uint32_t* pValue, const uint32_t* pTag);

// A sorted (key, value) table at +0x14 of the object (begin, end, capacity), elements of 8 bytes.
struct Vec8_a9dbb8 {
    char* mpBegin;
    char* mpEnd;
    char* mpCap;
    // STUB: 0x005fea70
    Vec8_a9dbb8(const Vec8_a9dbb8& other);
    // STUB: 0x005fead0
    void Erase(char* pos);
    // STUB: 0x005ff5d0
    void Insert(char* pos, const void* pValue);
    // STUB: 0x005ff0c0
    void Fn005ff0c0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00505a40 score 20
void cSC4Watercraft::GetCollidePosition(void* pOut)
{
    Vec3_a9dbb8* out = static_cast<Vec3_a9dbb8*>(pOut);
    out->x = mfPosX;
    out->y = mfPosY;
    out->z = mfPosZ;
    float length = mfLength;
    float dx = length * mfVec58X;
    float dy = length * mfVec58Y;
    float dz = length * mfVec58Z;
    out->x -= dx;
    out->y -= dy;
    out->z -= dz;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00509440 score 7
bool cSC4Watercraft::SetTransform(void* pTransform)
{
    if (mpModelsBegin != mpModelsEnd) {
        void** it = mpModelsBegin;
        do {
            ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
            if (model != 0) {
                ModelVBase_a9dbb8& base = *model;
                base.Fn10(pTransform);
            }
            ++it;
        } while (it != mpModelsEnd);
    }
    return mpModelsEnd != mpModelsBegin;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00510240 score 15
bool cSC4Watercraft::PlayAnim(uint32_t index)
{
    Key_a9dbb8 key = { mnAnimKeyType, mnAnimKeyGroup, mnAnimKeyInstance };
    if (key.mnInstance != 0) {
        if (mpModelsBegin != mpModelsEnd) {
            key.mnInstance = key.mnInstance + index;
            ReplaceModelInstance(*mpModelsBegin, &key);
        }
    }
    return true;
}
#endif

// FUNCTION: 0x005e91c0
void* cSC4Watercraft_4::Slot20_a9dbb8_4()
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    if (self->mp30 == 0) {
        Record_a9dbb8* record = new Record_a9dbb8;
        Unknown_a9dbb8* old = static_cast<Unknown_a9dbb8*>(self->mp30);
        if (record != static_cast<Record_a9dbb8*>(static_cast<void*>(old))) {
            if (record != 0) {
                record->AddRef();
            }
            self->mp30 = record;
            if (old != 0) {
                old->Release();
            }
        }
    }
    return self->mp30;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ff160 score 34
void cSC4Watercraft_c::Slot21_a9dbb8_c()
{
    Vec8_a9dbb8* v = reinterpret_cast<Vec8_a9dbb8*>(reinterpret_cast<char*>(this) + 8);
    if (((v->mpEnd - v->mpBegin) ^ (v->mpCap - v->mpBegin)) & ~7) {
        Vec8_a9dbb8 copy(*v);
        char* t = copy.mpBegin;
        copy.mpBegin = v->mpBegin;
        v->mpBegin = t;
        t = copy.mpEnd;
        copy.mpEnd = v->mpEnd;
        v->mpEnd = t;
        t = copy.mpCap;
        copy.mpCap = v->mpCap;
        v->mpCap = t;
        copy.Fn005ff0c0();
    }
}
#endif

// FUNCTION: 0x00509600
bool cSC4Watercraft::GetChaseVector(void* pOut)
{
    if (GetBehavior() == 0x34) {
        State_a9dbb8* state = static_cast<State_a9dbb8*>(GetState());
        if (state != 0) {
            Target_a9dbb8* target = static_cast<Target_a9dbb8*>(state->mpTarget);
            if (target != 0) {
                Vec3_a9dbb8* out = static_cast<Vec3_a9dbb8*>(pOut);
                target->Fn07(out);
                out->x -= mfPosX;
                out->y -= mfPosY;
                out->z -= mfPosZ;
                return true;
            }
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005e8b10 score 4
void cSC4Watercraft_4::Slot18_a9dbb8_4(bool on, bool notify)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    uint8_t flags = self->mbFlags2f;
    if (on) {
        if (!(flags & 4)) {
            self->mbFlags2f = flags | 4;
            if (notify) {
                Slot15_a9dbb8_4(0x99ef1145, 0);
            }
        }
    } else {
        if (flags & 4) {
            self->mbFlags2f = flags & 0xfb;
            if (notify) {
                Slot15_a9dbb8_4(0x99ef1145, 0);
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005febc0 score 33
bool cSC4Watercraft_c::Slot17_a9dbb8_c(uint32_t a, uint32_t)
{
    Vec8_a9dbb8* v = reinterpret_cast<Vec8_a9dbb8*>(reinterpret_cast<char*>(this) + 8);
    uint32_t probe[2] = { a, 0 };
    char* found = static_cast<char*>(Fn005fe940(v->mpBegin, v->mpEnd, probe, a, 0));
    if (found != v->mpEnd) {
        if (*reinterpret_cast<uint32_t*>(found) == a) {
            v->Erase(found);
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005e92d0 score 2
bool cSC4Watercraft_4::Slot22_a9dbb8_4(uint32_t value)
{
    bool result = false;
    cSC4Watercraft_c* sub = static_cast<cSC4Watercraft_c*>(Slot06_a9dbb8_4());
    Obj1_a9dbb8* controller = static_cast<Obj1_a9dbb8*>(sub->Slot09_a9dbb8_c(0xaa1dd396));
    if (controller != 0) {
        Obj2_a9dbb8* list = controller->Fn05();
        uint32_t* first = list->Fn103();
        uint32_t* last = first + list->Fn04();
        result = Fn004696c0(first, last, &value, &value) != last;
    }
    return result;
}
#endif

// FUNCTION: 0x005093a0
void cSC4Watercraft::InitLighting()
{
    if (mpModelsBegin != mpModelsEnd) {
        if (!CheckAutomataFlag(0x100000)) {
            ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*mpModelsBegin);
            void* value = model->Fn00();
            if (mpLight12c != value) {
                if (reinterpret_cast<Light_a9dbb8*>(&mpLight12c)->Fn008038d0(value)) {
                    return;
                }
            }
        }
    }
    if (mpLight12c != 0) {
        reinterpret_cast<Light_a9dbb8*>(&mpLight12c)->Fn008038d0(0);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00508d00 score 28
void cSC4Watercraft::ShutdownGhostModel()
{
    if (mpGhost != 0) {
        ModelInst_a9dbb8* ghost = static_cast<ModelInst_a9dbb8*>(mpGhost);
        if (gpB43dd0->Fn27(ghost->Fn00())) {
            ghost = static_cast<ModelInst_a9dbb8*>(mpGhost);
            gpB43dd0->Fn29(ghost->Fn00());
        }
        ghost = static_cast<ModelInst_a9dbb8*>(mpGhost);
        if (ghost != 0) {
            mpGhost = 0;
            ModelVBase_a9dbb8& base = *ghost;
            base.Release();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050d510 score 52
void cSC4Watercraft::ClearStateStack()
{
    for (void** it = mpStateBegin; it != mpStateEnd; ++it) {
        StateObj_a9dbb8* state = static_cast<StateObj_a9dbb8*>(*it);
        if (state != 0) {
            state->Fn00(this);
            Fn005e5620(state);
        }
    }
    mpStateEnd = mpStateBegin;
}
#endif


// ---- batch 6 ----

// The message the sound/state code posts (vtable 0x00acec00, 0x2c bytes from the pool); slots as used in cSC4Demand.cpp.
// STUB: 0x009133da is the pool allocator the original's `new` calls.
// STUB: 0x009133da
void* Fn009133da(uint32_t size);

struct Msg_a9dbb8 {
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
    virtual void Fn12(void*);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Fn16(uint32_t);
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Fn21(uint32_t);
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Fn26(uint32_t);
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Fn33(void*);
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    Msg_a9dbb8();
    static void* operator new(size_t size) { return Fn009133da(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

// The in-game data registry and the smart pointer the unregister code holds on to.
struct Registry_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05(uint32_t, uint32_t, void*);
};

struct Slot7Target_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Fn07(void*);
};

// STUB: 0x008793ec
Registry_a9dbb8* Fn008793ec();

struct SmartHolder_a9dbb8 {
    void* mp;
    // STUB: 0x00424e70
    void Fn00424e70();
};

// STUB: 0x005ff510
bool Fn005ff510(void* controller, uint32_t key, void* pVec);

inline Sub4_a9dbb8* Sub4Of_a9dbb8(cSC4Watercraft* self)
{
    return reinterpret_cast<Sub4_a9dbb8*>(reinterpret_cast<char*>(self) + 4);
}

// FUNCTION: 0x005fd7e0
void* cSC4Watercraft::AsOccupant_2()
{
    return static_cast<cSC4Watercraft_4*>(this);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00505690 score 4
bool cSC4Watercraft::DoBumpedTick(uint32_t)
{
    return !CheckAutomataFlag(1);
}
#endif

// FUNCTION: 0x00507d90
void cSC4Watercraft::SetDestination(void* pPos)
{
    Sub4_a9dbb8* sub = Sub4Of_a9dbb8(this);
    uint8_t flags = sub->mbFlags2f;
    if ((flags & 1) && (flags & 2)) {
        MoveTo(pPos, 0);
        return;
    }
    Vec3_a9dbb8* pos = static_cast<Vec3_a9dbb8*>(pPos);
    Vec3_a9dbb8* dst = reinterpret_cast<Vec3_a9dbb8*>(&mfPosX);
    dst->x = pos->x;
    dst->y = pos->y;
    dst->z = pos->z;
    for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
        static_cast<ModelInst_a9dbb8*>(*it)->Fn01(dst);
    }
}

// FUNCTION: 0x0050e390
void cSC4Watercraft::Slot09_a9dbb8(bool visible)
{
    cSC4Watercraft_4* sub = reinterpret_cast<cSC4Watercraft_4*>(reinterpret_cast<char*>(this) + 4);
    sub->Slot18_a9dbb8_4(visible, false);
    if (static_cast<uint8_t>(sub->Slot05_a9dbb8_4()) != 0) {
        PlaceInRenderer(visible);
        if (!visible) {
            EmbeddedOf_a9dbb8(this)->Fn07(1);
        } else {
            Fn0050d6a0();
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00507e00 score 45
void cSC4Watercraft::Slot96_a9dbb8(uint32_t index, void* pOut)
{
    Vec3u_a9dbb8* begin = static_cast<Vec3u_a9dbb8*>(mpPathBegin);
    uint32_t count = static_cast<Vec3u_a9dbb8*>(mpPathEnd) - begin;
    uint32_t x = 0;
    uint32_t y = 0;
    uint32_t z = 0;
    if (index < count) {
        const Vec3u_a9dbb8& v = static_cast<Vec3u_a9dbb8*>(mpPathBegin)[index];
        x = v.x;
        y = v.y;
        z = v.z;
    }
    Vec3u_a9dbb8* out = static_cast<Vec3u_a9dbb8*>(pOut);
    out->x = x;
    out->y = y;
    out->z = z;
}
#endif

// FUNCTION: 0x00567d80
void cSC4Watercraft::MoveTo(void* pFrom, void* pTo)
{
    const Vec3_a9dbb8* from = static_cast<const Vec3_a9dbb8*>(pFrom);
    const Vec3_a9dbb8* to = static_cast<const Vec3_a9dbb8*>(pTo);
    if (from != 0) {
        mfMoveFromX = from->x;
        mfMoveFromY = from->y;
        mfMoveFromZ = from->z;
    }
    if (to != 0) {
        mfMoveToX = to->x;
        mfMoveToY = to->y;
        mfMoveToZ = to->z;
    }
    AutomatonMoveTo(pFrom, pTo);
    UpdateEffects();
    UpdateLighting();
}

// FUNCTION: 0x005059c0
bool cSC4Watercraft::ShouldCollide(void* pOther)
{
    bool result = false;
    cSC4Watercraft* other = static_cast<cSC4Watercraft*>(pOther);
    if (other != 0 && other != this) {
        if (other->CheckAutomataFlag(8)) {
            if (!other->GetMarkedForRemove()) {
                result = true;
                if (CheckAutomataFlag(0x200000)) {
                    if (!other->CheckAutomataFlag(0x200000)) {
                        cSC4Watercraft_4& otherSub = *other;
                        if (!(otherSub.Slot33_a9dbb8_4() & 4)) {
                            result = false;
                        }
                    }
                }
            }
        }
        return result;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0050d490 score 18
void cSC4Watercraft::AddCallback(void* pCallback)
{
    Unknown_a9dbb8* callback = static_cast<Unknown_a9dbb8*>(pCallback);
    if (callback != 0) {
        ListNode_a9dbb8* head = static_cast<ListNode_a9dbb8*>(mpCallbacks);
        ListNode_a9dbb8* node = head->mpNext;
        while (node != head) {
            if (node->mpValue == callback) {
                break;
            }
            node = node->mpNext;
        }
        if (node == head) {
            callback->AddRef();
            ListNode_a9dbb8* end = static_cast<ListNode_a9dbb8*>(mpCallbacks);
            ListNode_a9dbb8* added = static_cast<ListNode_a9dbb8*>(Fn0090cf54(sizeof(ListNode_a9dbb8)));
            if (&added->mpValue != 0) {
                added->mpValue = callback;
                callback->AddRef();
            }
            ListNode_a9dbb8* prev = end->mpPrev;
            added->mpNext = end;
            added->mpPrev = prev;
            prev->mpNext = added;
            end->mpPrev = added;
            callback->Release();
        }
    }
}
#endif

// FUNCTION: 0x00505b50
bool cSC4Watercraft::StopSFX(uint32_t arg)
{
    if (mnSfx8c != 0) {
        Msg_a9dbb8* msg = new Msg_a9dbb8;
        msg->AddRef();
        msg->Fn05(0xaa396960);
        msg->Fn33(Slot05_a9dbb8());
        msg->Fn11(arg);
        msg->Fn16(mnSfx8c);
        gpB43ccc->MessagePost(msg, false);
        msg->Release();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005056a0 score 2
bool cSC4Watercraft::Slot60_a9dbb8(uint32_t index, bool flag)
{
    FloatState_a9dbb8* state = static_cast<FloatState_a9dbb8*>(FindState(0x10));
    if (state != 0) {
        if (flag) {
            if (state->mf7c[index] < 0.0f) {
                state->mn7c[index] = 0;
                Slot102_a9dbb8(0xe, index);
            }
            return true;
        }
        if (state->mf7c[index] >= 0.0f) {
            Slot102_a9dbb8(0xf, index);
        }
        state->mn7c[index] = 0xbf800000;
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x00509130
void cSC4Watercraft::SetOrientation(bool flag)
{
    SetAutomataFlag(1, true);
    SetAutomataFlag(0x10000000, true);
    if (flag) {
        SetOpacity(0, 0);
        EmbeddedOf_a9dbb8(this)->Fn07(0);
    } else {
        Slot102_a9dbb8(2, 0);
        SetOpacity(0, gfB21c84);
        Embedded_a9dbb8* emb = EmbeddedOf_a9dbb8(this);
        emb->Fn07(1);
        emb->Fn02(0);
    }
}

// FUNCTION: 0x00509860
bool cSC4Watercraft::SetState(uint32_t a, void* b, float c, uint8_t d, uint32_t e, uint32_t f, void* g)
{
    while (mpStateBegin != mpStateEnd) {
        State_a9dbb8* state = static_cast<State_a9dbb8*>(GetState());
        if (state != 0) {
            if (state->mb14 != 0) {
                return false;
            }
        }
        if (!PopState()) {
            break;
        }
    }
    return PushState(a, b, c, d, e, f, g);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0050c330 score 49
void cSC4Watercraft::EnableActiveSound(bool enable)
{
    if (!mbActiveSound1dc) {
        if (enable) {
            mpVec1c8End = mpVec1c8Begin;
            Fn005ff510(Slot06_a9dbb8_4(), 0x6c044bb5, &mpVec1c8Begin);
        }
        mbActiveSound1dc = enable;
    } else {
        mbActiveSound1dc = enable;
    }
}
#endif

// FUNCTION: 0x0050b5e0
void cSC4Watercraft::UnregisterInGameDataRegistry()
{
    Slot05_a9dbb8();
    SmartHolder_a9dbb8 holder = { 0 };
    Registry_a9dbb8* registry = Fn008793ec();
    if (registry != 0) {
        registry->Fn05(0xebe0e860, 0xe898ed03, &holder.mp);
    }
    Slot7Target_a9dbb8* target = static_cast<Slot7Target_a9dbb8*>(holder.mp);
    if (target != 0) {
        Unknown_a9dbb8* me = 0;
        QueryInterface(1, &me);
        target->Fn07(me);
        if (me != 0) {
            me->Release();
        }
    }
    holder.Fn00424e70();
}


// ---- batch 7 ----

struct CallbackObj_a9dbb8 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Fn03(void*);
};

struct PropOwner_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual bool Fn03(uint32_t);
    virtual bool Fn04(void*);
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void* Fn09(uint32_t);
};

struct ParentObj_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual PropOwner_a9dbb8* Fn07();
};

// The random generator object at 0xb21d78 (cRZRandomSuper): a count, an integer range and a double range.
struct Random_a9dbb8 {
    // STUB: 0x00913a06
    uint32_t Fn00913a06(uint32_t count);
    // STUB: 0x00913a14
    int32_t Fn00913a14(int32_t low, int32_t high);
    // STUB: 0x00913a46
    double Fn00913a46(double low, double high);
    // STUB: 0x00913a29
    double Fn00913a29();
};

// GLOBAL: 0x00b21d78
extern Random_a9dbb8 gB21d78;

#ifdef OB_DRAFTS
// CLOSE: 0x005feda0 score 31
void* cSC4Watercraft_c::Slot09_a9dbb8_c(uint32_t key)
{
    Vec8_a9dbb8* v = reinterpret_cast<Vec8_a9dbb8*>(reinterpret_cast<char*>(this) + 8);
    uint32_t probe[2] = { key, 0 };
    char* found = static_cast<char*>(Fn005fe940(v->mpBegin, v->mpEnd, probe, key, 0));
    if (found != v->mpEnd) {
        if (*reinterpret_cast<uint32_t*>(found) == key) {
            void* value = *reinterpret_cast<void**>(found + 4);
            if (value != 0) {
                return value;
            }
        }
    }
    ParentObj_a9dbb8* parent = *reinterpret_cast<ParentObj_a9dbb8**>(reinterpret_cast<char*>(this) + 0x18);
    if (parent != 0) {
        return parent->Fn07()->Fn09(key);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005fec20 score 41
bool cSC4Watercraft_c::Slot03_a9dbb8_c(uint32_t key)
{
    Vec8_a9dbb8* v = reinterpret_cast<Vec8_a9dbb8*>(reinterpret_cast<char*>(this) + 8);
    uint32_t probe[2] = { key, 0 };
    char* found = static_cast<char*>(Fn005fe940(v->mpBegin, v->mpEnd, probe, key, 0));
    if (found != v->mpEnd) {
        if (*reinterpret_cast<uint32_t*>(found) == key) {
            return true;
        }
    }
    ParentObj_a9dbb8* parent = *reinterpret_cast<ParentObj_a9dbb8**>(reinterpret_cast<char*>(this) + 0x18);
    if (parent != 0) {
        if (parent->Fn07()->Fn03(key)) {
            return true;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x0050b540
void cSC4Watercraft::Slot102_a9dbb8(uint32_t a, uint32_t b)
{
    ListNode_a9dbb8* head = static_cast<ListNode_a9dbb8*>(mpCallbacks);
    if (head->mpNext != head) {
        Msg_a9dbb8* msg = new Msg_a9dbb8;
        msg->AddRef();
        msg->Fn05(0x09d92fc3);
        msg->Fn12(this);
        msg->Fn16(a);
        msg->Fn21(b);
        ListNode_a9dbb8* node = static_cast<ListNode_a9dbb8*>(mpCallbacks)->mpNext;
        while (node != static_cast<ListNode_a9dbb8*>(mpCallbacks)) {
            CallbackObj_a9dbb8* callback = reinterpret_cast<CallbackObj_a9dbb8*>(node->mpValue);
            node = node->mpNext;
            if (callback != 0) {
                callback->Fn03(msg);
            }
        }
        msg->Release();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00505780 score 19
void cSC4Watercraft::SetSpeedFromBehaviorTemplate(void* pTemplate)
{
    BehaviorTemplate_a9dbb8* t = static_cast<BehaviorTemplate_a9dbb8*>(pTemplate);
    float speed = field80;
    int32_t low = t->mn38;
    if (low > 0 && t->mn3c > 0) {
        int32_t value;
        if (low == t->mn3c) {
            value = low;
        } else {
            value = gB21d78.Fn00913a14(low, t->mn3c);
        }
        speed = static_cast<float>(value) * 2.77777814e-4f;
    }
    float result;
    if (t->mf34 != t->mf30) {
        result = static_cast<float>(gB21d78.Fn00913a46(t->mf30, t->mf34)) * speed;
    } else {
        result = speed * t->mf30;
    }
    SetSpeed(result, t->mf40);
}
#endif

// FUNCTION: 0x0050b360
void cSC4Watercraft::SetOpacity(float opacity, float alpha)
{
    Ramp_a9dbb8* ramp = reinterpret_cast<Ramp_a9dbb8*>(reinterpret_cast<char*>(this) + 0x1b0);
    if (opacity != ramp->mfTo) {
        ramp->mfFrom = ramp->Fn004fa960();
        ramp->mfTo = opacity;
        ramp->mfB = alpha;
        ramp->mnC = 0;
    }
    if (alpha < 0.001f) {
        if (mpModelsBegin != mpModelsEnd) {
            void** it = mpModelsBegin;
            do {
                ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
                if (model != 0) {
                    if (opacity < 1.0f) {
                        model->Fn18(1, opacity);
                    } else {
                        model->Fn18(0, 1.0f);
                    }
                }
                ++it;
            } while (it != mpModelsEnd);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0050b740 score 83
bool cSC4Watercraft::PushBehavior(void* pTemplate, void* x)
{
    BehaviorTemplate_a9dbb8* t = static_cast<BehaviorTemplate_a9dbb8*>(pTemplate);
    if (t == 0) {
        return false;
    }
    int32_t chosenInt = 0;
    if (t->mpIntBegin != t->mpIntEnd) {
        uint32_t index = gB21d78.Fn00913a06(static_cast<uint32_t>(t->mpIntEnd - t->mpIntBegin));
        chosenInt = t->mpIntBegin[index];
    }
    uint32_t anim = 0;
    if (t->mpRecBegin != t->mpRecEnd) {
        uint32_t index = gB21d78.Fn00913a06(static_cast<uint32_t>((t->mpRecEnd - t->mpRecBegin) / 20));
        anim = index;
        Slot76_a9dbb8(t->mpRecBegin + index * 20);
    }
    return PushState(t->mnId, x, t->Fn00514c70(), t->mb2c, anim, chosenInt, t);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050b660 score 42
bool cSC4Watercraft::PopState()
{
    if (mpStateBegin != mpStateEnd) {
        State_a9dbb8* state = static_cast<State_a9dbb8*>(mpStateEnd[-1]);
        HandleExitState(state);
        if (state->mb14 != 0 && state->mnBehavior != 1) {
            PushState(1, 0, -1.0f, 0, 0, 0, 0);
            return true;
        }
        if (state->mpObj8 != 0) {
            static_cast<Unknown_a9dbb8*>(state->mpObj8)->Release();
        }
        mpStateEnd = mpStateEnd - 1;
        Fn005e5620(state);
        if (!GetMarkedForRemove()) {
            if (mpStateBegin != mpStateEnd) {
                HandleEnterState(mpStateEnd[-1]);
            }
        }
        return true;
    }
    return false;
}
#endif


// ---- batch 8 ----

struct OccMgr_a9dbb8 {
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
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Fn17(float, float, int32_t*, int32_t*);
    virtual void Pad18();
    virtual void Pad19();
    virtual bool Fn20(void*, uint32_t);
    virtual void Fn21(void*, uint32_t, uint32_t);
    virtual void Pad22();
    virtual void Pad23();
    virtual void Fn24(void*, uint32_t);
};

// GLOBAL: 0x00b43d0c
extern OccMgr_a9dbb8* gpB43d0c;

struct Sim_a9dbb8 {
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
    virtual void Pad13();
    virtual void Pad14();
    virtual bool Fn15();
    virtual void Pad16();
    virtual bool Fn17();
};

// GLOBAL: 0x00b43d5c
extern Sim_a9dbb8* gpB43d5c;

// A jump state: the target height at +0x28 and the vertical speed at +0x2c.
struct PlopState_a9dbb8 {
    uint8_t mPad[0x28];
    float mf28;
    float mf2c;
};

// The function-local statics of DoPlopJumpTick: a guard bit and the gravity it initialises.
// GLOBAL: 0x00b22744
extern uint32_t gnB22744;

// GLOBAL: 0x00b22740
extern float gfB22740;

#ifdef OB_DRAFTS
// CLOSE: 0x00508d70 score 39
bool cSC4Watercraft::DoCollideTick(uint32_t)
{
    if (CheckAutomataFlag(1)) {
        return false;
    }
    if (Sub4Of_a9dbb8(this)->mbFlags2f & 2) {
        Slot09_a9dbb8(false);
    }
    if (mpModelsBegin != mpModelsEnd) {
        ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*mpModelsBegin);
        ModelVBase_a9dbb8* base = model;
        base->Fn08(&mfVec170X);
    }
    if (Sub4Of_a9dbb8(this)->mbFlags2f & 1) {
        gpB43d0c->Fn24(Sub4Of_a9dbb8(this), 0);
    }
    if (mf1c0 > 100.0f) {
        Slot102_a9dbb8(9, 0);
        mf1c0 = 0.0f;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050f140 score 51
void cSC4Watercraft::SetAutomataGroup(void* pGroup)
{
    cOccupantGroup_a9dbb8* group = static_cast<cOccupantGroup_a9dbb8*>(pGroup);
    if (group != 0) {
        mnGroupId = group->mnId10;
        if (group->mf58 > 0.0f) {
            float high;
            if (group->mf5c > 0.0f) {
                high = group->mf5c;
            } else if (group->mpParent != 0) {
                high = group->mpParent->Fn00505300();
            } else {
                high = 0.0f;
            }
            float speed = static_cast<float>(gB21d78.Fn00913a46(group->mf58, high)) * 2.77777814e-4f;
            field80 = speed;
            SetSpeed(speed, 0);
        }
        Fn0050d870();
        ApplyAutomataGroup();
    }
}
#endif

// FUNCTION: 0x005055f0
bool cSC4Watercraft::DoPlopJumpTick(float dt)
{
    if (!(gnB22744 & 1)) {
        gnB22744 |= 1;
        gfB22740 = -5.55555634e-05f;
    }
    if (CheckAutomataFlag(1)) {
        return false;
    }
    PlopState_a9dbb8* state = static_cast<PlopState_a9dbb8*>(GetState());
    Vec3_a9dbb8 v;
    v.x = mfPosX;
    v.y = mfPosY;
    v.z = mfPosZ;
    v.y = dt * state->mf2c + v.y;
    if (v.y < state->mf28) {
        v.y = state->mf28;
    } else {
        state->mf2c = gfB22740 * dt + state->mf2c;
    }
    MoveTo(&v, 0);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005089f0 score 35
bool cSC4Watercraft::Slot103_a9dbb8(float dt)
{
    if (gpB43d5c->Fn17() || !gpB43d5c->Fn15()) {
        for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
            ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
            if (model != 0) {
                model->Fn15(dt);
            }
        }
        ListNode_a9dbb8* head = static_cast<ListNode_a9dbb8*>(mpCallbacks);
        if (head->mpNext != head && mpModelsBegin != mpModelsEnd) {
            ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*mpModelsBegin);
            int32_t last = model->Fn12() - 1;
            if (model->Fn11() >= last) {
                Slot102_a9dbb8(1, 0);
            }
        }
        mf1c0 = dt + mf1c0;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005058a0 score 24
uint32_t cSC4Watercraft::Slot76_a9dbb8(void* pKey)
{
    cSC4Watercraft_c* controllers = reinterpret_cast<cSC4Watercraft_c*>(reinterpret_cast<char*>(this) + 0xc);
    Obj1_a9dbb8* obj = static_cast<Obj1_a9dbb8*>(controllers->Slot09_a9dbb8_c(0xaa1dd396));
    if (obj != 0) {
        ScriptSys_a9dbb8* system = gpB43cec_a9dbb8->Fn48();
        Obj2_a9dbb8* list = obj->Fn05();
        uint32_t* ids = list->Fn103();
        for (uint32_t i = 0; i < list->Fn04(); ++i) {
            GroupMgr_a9dbb8* group = static_cast<GroupMgr_a9dbb8*>(system->Fn06(ids[i]));
            if (group != 0) {
                uint32_t out;
                if (group->Fn0051d970(static_cast<Str_a9dbb8*>(pKey), &out)) {
                    return out;
                }
            }
        }
        return 0;
    }
    return 0;
}
#endif


// ---- batch 9 ----

// A state record of the animation kind: the model at +0x28 (smart pointer), a byte at +0x2c and a word at +0x30.
struct AnimState_a9dbb8 {
    uint8_t mPad[0x28];
    ModelInst_a9dbb8* mpModel28;
    uint8_t mb2c;
    uint8_t mPad2d[3];
    int32_t mn30;
};

// GLOBAL: 0x00b09978
extern float gfB09978;

// STUB: 0x005fd5b0
bool Fn005fd5b0(void* controller, uint32_t key, void* pOut);

// STUB: 0x004ecd60
void* Fn004ecd60();

// STUB: 0x004f7bb0
uint32_t Fn004f7bb0();

#ifdef OB_DRAFTS
// CLOSE: 0x0050eb20 score 45
bool cSC4Watercraft::LoadAuxiliaryModel(uint32_t kind, void* pOut)
{
    Key_a9dbb8 key = { 0, 0, 0 };
    uint32_t instance;
    switch (kind) {
    case 1:
        instance = 0x09c80417;
        break;
    case 2:
        instance = 0xc9e69af6;
        break;
    case 3:
        instance = 0xec214180;
        break;
    default:
        instance = kind;
        break;
    }
    if (Fn005fd5b0(Slot06_a9dbb8_4(), instance, &key)) {
        ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(AddModelInstance(&key));
        *static_cast<ModelInst_a9dbb8**>(pOut) = model;
        if (model != 0) {
            ModelVBase_a9dbb8* base = model;
            base->AddRef();
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005102a0 score 44
bool cSC4Watercraft::Slot22_a9dbb8(void* pKey, uint32_t b, bool c, float d)
{
    bool result = false;
    if (PushState(0x13, 0, d, 0, 0, 0, 0)) {
        AnimState_a9dbb8* state = static_cast<AnimState_a9dbb8*>(GetState());
        state->mb2c = c;
        state->mn30 = b;
        ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(AddModelInstance(pKey));
        ModelInst_a9dbb8* old = state->mpModel28;
        if (model != old) {
            if (model != 0) {
                ModelVBase_a9dbb8* base = model;
                base->AddRef();
            }
            state->mpModel28 = model;
            if (old != 0) {
                ModelVBase_a9dbb8* oldBase = old;
                oldBase->Release();
            }
        }
        if (state->mpModel28 != 0) {
            state->mpModel28->Fn16(b);
            state->mpModel28->Fn18(1, 0.0f);
            return true;
        }
        return false;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050af10 score 42
void cSC4Watercraft::GetOrientation(void* pDir)
{
    Sub4_a9dbb8* sub = Sub4Of_a9dbb8(this);
    uint8_t flags = sub->mbFlags2f;
    if ((flags & 1) && (flags & 2)) {
        MoveTo(0, pDir);
        return;
    }
    const Vec3_a9dbb8* dir = static_cast<const Vec3_a9dbb8*>(pDir);
    mfVec58X = dir->x;
    mfVec58Y = dir->y;
    mfVec58Z = dir->z;
    float length = static_cast<float>(std::sqrt(static_cast<double>(mfVec58X * mfVec58X + mfVec58Y * mfVec58Y + mfVec58Z * mfVec58Z)));
    float scale = gfB09978 / length;
    mfVec58X = mfVec58X * scale;
    mfVec58Y = mfVec58Y * scale;
    mfVec58Z = mfVec58Z * scale;
    for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
        ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
        ModelVBase_a9dbb8* base = model;
        PositionModelInstance(base);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005091c0 score 8
void cSC4Watercraft::UpdateOpacity(float dt)
{
    Ramp_a9dbb8* ramp = reinterpret_cast<Ramp_a9dbb8*>(reinterpret_cast<char*>(this) + 0x1b0);
    float before = ramp->Fn004fa960();
    if (ramp->mfC < ramp->mfB) {
        ramp->mfC = dt * 0.001f + ramp->mfC;
        if (ramp->mfC >= ramp->mfB) {
            ramp->mfFrom = ramp->mfTo;
            ramp->mnC = 0;
            ramp->mfB = 0.0f;
        }
    }
    float after = ramp->Fn004fa960();
    if (before != after) {
        for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
            ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
            if (model != 0) {
                if (after < 1.0f) {
                    model->Fn18(1, after);
                } else {
                    model->Fn18(0, 1.0f);
                }
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00509950 score 64
bool cSC4Watercraft::StartSFX(uint32_t id)
{
    if (id != 0) {
        Fn004ecd60();
        mnSfx8c = Fn004f7bb0();
        Msg_a9dbb8* msg = new Msg_a9dbb8;
        msg->AddRef();
        msg->Fn05(0x8a385dd8);
        msg->Fn33(Slot05_a9dbb8());
        msg->Fn11(id);
        msg->Fn16(mnSfx8c);
        gpB43ccc->MessagePost(msg, false);
        msg->Release();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050d3c0 score 41
bool cSC4Watercraft::UnloadModels()
{
    if (Sub4Of_a9dbb8(this)->mbFlags2f & 2) {
        PlaceInRenderer(false);
    }
    reinterpret_cast<Light_a9dbb8*>(&mpLight12c)->Fn008038d0(0);
    for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
        ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
        if (model != 0) {
            ModelVBase_a9dbb8* base = model;
            base->Release();
        }
    }
    mpModelsEnd = mpModelsBegin;
    mpPathEnd = mpPathBegin;
    InitLighting();
    return true;
}
#endif


// ---- batch 10 ----

struct PropList_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Fn09(void*);
    virtual void Pad10();
    virtual void Pad11();
    virtual bool Fn12(uint32_t, void*);
};

struct Prop_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual uint32_t Fn03();
};

// The own-property part of the _c subobject (the property holder base), called with this = the subobject.
struct PropHolder_a9dbb8 {
    // STUB: 0x005fda80
    void EnumOwn(void* filter, void* visit, void* context);
    // STUB: 0x005fd9f0
    bool GetOwnList(void** pOut);
};

// lower_bound over the (key, value) vector of 8-byte elements, as the original's inlined search does it.
inline char* LowerBound_a9dbb8(char* first, char* last, uint32_t id)
{
    int32_t count = (last - first) >> 3;
    while (count > 0) {
        int32_t half = count >> 1;
        if (*reinterpret_cast<uint32_t*>(first + half * 8) < id) {
            first = first + half * 8 + 8;
            count = count - (half + 1);
        } else {
            count = half;
        }
    }
    return first;
}

typedef void (*PropVisit_a9dbb8)(void* prop, void* context);
typedef bool (*PropFilter_a9dbb8)(void* prop, void* context);

// FUNCTION: 0x005fee10
void cSC4Watercraft_c::Slot20_a9dbb8_c(void* pVisit, void* context)
{
    PropVisit_a9dbb8 visit = reinterpret_cast<PropVisit_a9dbb8>(pVisit);
    Vec8_a9dbb8* v = reinterpret_cast<Vec8_a9dbb8*>(reinterpret_cast<char*>(this) + 8);
    char* end = v->mpEnd;
    for (char* p = v->mpBegin; p != end; p += 8) {
        visit(*reinterpret_cast<void**>(p + 4), context);
    }
    ParentObj_a9dbb8* parent = *reinterpret_cast<ParentObj_a9dbb8**>(reinterpret_cast<char*>(this) + 0x18);
    if (parent != 0) {
        PropList_a9dbb8* list;
        if (parent->Fn07()->Fn04(&list)) {
            Prop_a9dbb8* prop;
            while (list->Fn12(0x452160ec, &prop)) {
                uint32_t id = prop->Fn03();
                char* found = LowerBound_a9dbb8(v->mpBegin, v->mpEnd, id);
                if (found == v->mpEnd || *reinterpret_cast<uint32_t*>(found) != id) {
                    visit(prop, context);
                }
                prop->Release();
            }
            list->Release();
        }
    }
}

// FUNCTION: 0x005fef00
void cSC4Watercraft_c::Slot19_a9dbb8_c(void* pFilter, void* pVisit, void* context)
{
    PropFilter_a9dbb8 filter = reinterpret_cast<PropFilter_a9dbb8>(pFilter);
    PropVisit_a9dbb8 visit = reinterpret_cast<PropVisit_a9dbb8>(pVisit);
    Vec8_a9dbb8* v = reinterpret_cast<Vec8_a9dbb8*>(reinterpret_cast<char*>(this) + 8);
    reinterpret_cast<PropHolder_a9dbb8*>(this)->EnumOwn(pFilter, pVisit, context);
    ParentObj_a9dbb8* parent = *reinterpret_cast<ParentObj_a9dbb8**>(reinterpret_cast<char*>(this) + 0x18);
    if (parent != 0) {
        PropList_a9dbb8* list;
        if (parent->Fn07()->Fn04(&list)) {
            Prop_a9dbb8* prop;
            while (list->Fn12(0x452160ec, &prop)) {
                uint32_t id = prop->Fn03();
                char* found = LowerBound_a9dbb8(v->mpBegin, v->mpEnd, id);
                if (found == v->mpEnd || *reinterpret_cast<uint32_t*>(found) != id) {
                    if (filter(prop, context)) {
                        visit(prop, context);
                    }
                }
                prop->Release();
            }
            list->Release();
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x005feca0 score 99
bool cSC4Watercraft_c::Slot04_a9dbb8_c(void* pOut)
{
    if (pOut != 0) {
        PropList_a9dbb8* own;
        if (reinterpret_cast<PropHolder_a9dbb8*>(this)->GetOwnList(reinterpret_cast<void**>(&own))) {
            Vec8_a9dbb8* v = reinterpret_cast<Vec8_a9dbb8*>(reinterpret_cast<char*>(this) + 8);
            ParentObj_a9dbb8* parent = *reinterpret_cast<ParentObj_a9dbb8**>(reinterpret_cast<char*>(this) + 0x18);
            if (parent != 0) {
                PropList_a9dbb8* list;
                if (parent->Fn07()->Fn04(&list)) {
                    Prop_a9dbb8* prop;
                    while (list->Fn12(0x452160ec, &prop)) {
                        uint32_t id = prop->Fn03();
                        uint32_t probe[2] = { id, 0 };
                        char* found = static_cast<char*>(Fn005fe940(v->mpBegin, v->mpEnd, probe, id, 0));
                        if (found == v->mpEnd || *reinterpret_cast<uint32_t*>(found) != id) {
                            own->Fn09(prop);
                        }
                        prop->Release();
                    }
                    list->Release();
                }
            }
            *static_cast<PropList_a9dbb8**>(pOut) = own;
            return true;
        }
    }
    return false;
}
#endif


// ---- batch 11 ----

// The values of the property table: a variant object with a 0x14-byte base (cRZVariant) at +4 and its id at +0x18.
struct Inner_a9dbb8 {
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
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Fn26(uint32_t);
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual void Pad55();
    virtual void Fn56(uint32_t);
    virtual void Pad57();
    virtual void Fn58(uint32_t, uint32_t);
    virtual void Pad59();
    virtual void Pad60();
    virtual void Fn61(uint32_t);
};

struct VariantPrimary_a9dbb8 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual uint32_t Fn03();
    virtual void Pad04();
    virtual Inner_a9dbb8* Fn05();
    virtual void Pad06();
    virtual void Fn07(void*);
};

struct VariantBase_a9dbb8 {
    virtual void PadBase();
    uint8_t mData[0x10];
    // STUB: 0x009166d4
    VariantBase_a9dbb8();
};

// GLOBAL: 0x00b0a9e8
extern Pool_a9dbb8 gB0a9e8;

struct Variant_a9dbb8 : VariantPrimary_a9dbb8, VariantBase_a9dbb8 {
    uint32_t mnId;
    explicit Variant_a9dbb8(uint32_t id) : mnId(id) {}
    static void* operator new(size_t)
    {
        void** node = gB0a9e8.mpBlock->mpFree;
        if (node == 0) {
            node = gB0a9e8.Refill();
        }
        gB0a9e8.mpBlock->mpFree = static_cast<void**>(*node);
        gB0a9e8.mpBlock->mnCount = gB0a9e8.mpBlock->mnCount + 1;
        return node;
    }
    static void operator delete(void*) {}
};

// One (key, value) element of the property vector.
struct PropEntry_a9dbb8 {
    uint32_t mnKey;
    Variant_a9dbb8* mpValue;
};

inline Vec8_a9dbb8* PropsOf_a9dbb8(cSC4Watercraft_c* self)
{
    return reinterpret_cast<Vec8_a9dbb8*>(reinterpret_cast<char*>(self) + 8);
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ff770 score 80
void cSC4Watercraft_c::Slot13_a9dbb8_c(uint32_t key, uint32_t value, uint32_t)
{
    Vec8_a9dbb8* v = PropsOf_a9dbb8(this);
    uint32_t probe[2] = { key, 0 };
    PropEntry_a9dbb8* found = static_cast<PropEntry_a9dbb8*>(Fn005fe940(v->mpBegin, v->mpEnd, probe, key, 0));
    if (found != reinterpret_cast<PropEntry_a9dbb8*>(v->mpEnd) && found->mnKey == key) {
        found->mpValue->Fn05()->Fn26(value);
        return;
    }
    Variant_a9dbb8* variant = new Variant_a9dbb8(key);
    variant->AddRef();
    variant->Fn05()->Fn26(value);
    PropEntry_a9dbb8 entry = { key, variant };
    v->Insert(reinterpret_cast<char*>(found), &entry);
    variant->Release();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ff860 score 80
void cSC4Watercraft_c::Slot12_a9dbb8_c(uint32_t key, uint32_t value, uint32_t)
{
    Vec8_a9dbb8* v = PropsOf_a9dbb8(this);
    uint32_t probe[2] = { key, 0 };
    PropEntry_a9dbb8* found = static_cast<PropEntry_a9dbb8*>(Fn005fe940(v->mpBegin, v->mpEnd, probe, key, 0));
    if (found != reinterpret_cast<PropEntry_a9dbb8*>(v->mpEnd) && found->mnKey == key) {
        found->mpValue->Fn05()->Fn56(value);
        return;
    }
    Variant_a9dbb8* variant = new Variant_a9dbb8(key);
    variant->AddRef();
    variant->Fn05()->Fn56(value);
    PropEntry_a9dbb8 entry = { key, variant };
    v->Insert(reinterpret_cast<char*>(found), &entry);
    variant->Release();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ff950 score 80
void cSC4Watercraft_c::Slot11_a9dbb8_c(uint32_t key, uint32_t value, uint32_t)
{
    Vec8_a9dbb8* v = PropsOf_a9dbb8(this);
    uint32_t probe[2] = { key, 0 };
    PropEntry_a9dbb8* found = static_cast<PropEntry_a9dbb8*>(Fn005fe940(v->mpBegin, v->mpEnd, probe, key, 0));
    if (found != reinterpret_cast<PropEntry_a9dbb8*>(v->mpEnd) && found->mnKey == key) {
        found->mpValue->Fn05()->Fn61(value);
        return;
    }
    Variant_a9dbb8* variant = new Variant_a9dbb8(key);
    variant->AddRef();
    variant->Fn05()->Fn61(value);
    PropEntry_a9dbb8 entry = { key, variant };
    v->Insert(reinterpret_cast<char*>(found), &entry);
    variant->Release();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ffa40 score 82
void cSC4Watercraft_c::Slot10_a9dbb8_c(uint32_t key, uint32_t a, uint32_t b, uint32_t)
{
    Vec8_a9dbb8* v = PropsOf_a9dbb8(this);
    uint32_t probe[2] = { key, 0 };
    PropEntry_a9dbb8* found = static_cast<PropEntry_a9dbb8*>(Fn005fe940(v->mpBegin, v->mpEnd, probe, key, 0));
    if (found != reinterpret_cast<PropEntry_a9dbb8*>(v->mpEnd) && found->mnKey == key) {
        found->mpValue->Fn05()->Fn58(a, b);
        return;
    }
    Variant_a9dbb8* variant = new Variant_a9dbb8(key);
    variant->AddRef();
    variant->Fn05()->Fn58(a, b);
    PropEntry_a9dbb8 entry = { key, variant };
    v->Insert(reinterpret_cast<char*>(found), &entry);
    variant->Release();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005fdef0 score 4
void cSC4Watercraft_c::Slot14_a9dbb8_c(void* pValue, uint32_t id, void* arg3)
{
    if (pValue != 0) {
        Variant_a9dbb8* variant = new Variant_a9dbb8(id);
        variant->AddRef();
        variant->Fn07(pValue);
        Slot15_a9dbb8_c(variant, arg3);
        variant->Release();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005fdfd0 score 27
void cSC4Watercraft_c::Slot16_a9dbb8_c(void* pProp, void* arg2)
{
    Variant_a9dbb8* variant = new Variant_a9dbb8(0);
    VariantPrimary_a9dbb8* prop = static_cast<VariantPrimary_a9dbb8*>(pProp);
    uint32_t id = prop->Fn03();
    variant->mnId = id;
    variant->AddRef();
    variant->Fn07(prop->Fn05());
    Slot15_a9dbb8_c(variant, arg2);
    variant->Release();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ff6d0 score 51
void cSC4Watercraft_c::Slot15_a9dbb8_c(void* pProp, void*)
{
    VariantPrimary_a9dbb8* prop = static_cast<VariantPrimary_a9dbb8*>(pProp);
    uint32_t id = prop->Fn03();
    Vec8_a9dbb8* v = PropsOf_a9dbb8(this);
    char* end = v->mpEnd;
    uint32_t probe[2] = { id, 0 };
    PropEntry_a9dbb8* found = static_cast<PropEntry_a9dbb8*>(Fn005fe940(v->mpBegin, end, probe, 0, 0));
    if (found != reinterpret_cast<PropEntry_a9dbb8*>(end) && found->mnKey == id) {
        VariantPrimary_a9dbb8* old = found->mpValue;
        if (prop != old) {
            prop->AddRef();
            found->mpValue = static_cast<Variant_a9dbb8*>(prop);
            if (old != 0) {
                old->Release();
            }
        }
        return;
    }
    prop->AddRef();
    PropEntry_a9dbb8 entry = { id, static_cast<Variant_a9dbb8*>(prop) };
    v->Insert(reinterpret_cast<char*>(found), &entry);
    prop->Release();
}
#endif


// ---- batch 12 ----

// The cached message server (a global the original fills from the service locator on first use).
// GLOBAL: 0x00b23194
extern cIGZMessageServer2* gpB23194;

// A node of the set<uint32_t> the group collectors fill: header-based red-black tree, value at +0x10.
struct SetNode_a9dbb8 {
    uint8_t mPad[4];
    SetNode_a9dbb8* mpParent;
    SetNode_a9dbb8* mpLeft;
    SetNode_a9dbb8* mpRight;
    uint32_t mnValue;
};

struct Set_a9dbb8 {
    SetNode_a9dbb8* mpHead;
    uint32_t mnCount;
    // STUB: 0x0046f820
    void Fn0046f820(SetNode_a9dbb8* root);
    // STUB: 0x0049a050
    void Fn0049a050(void* pResult, const uint32_t* pValue);
};

// A vector of 32-bit words as the callee fills it.
struct WordVec_a9dbb8 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x0051ca60
    void Fn0051ca60(uint32_t* pos, const uint32_t* pValue, uint32_t a, uint32_t b);
};

// STUB: 0x005fe6b0
void Fn005fe6b0(void* controller, uint32_t key, void* pVec);

// FUNCTION: 0x005e9010
void cSC4Watercraft_4::Slot15_a9dbb8_4(uint32_t type, uint32_t extra)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    if (gpB23194 == 0) {
        gpB23194 = gpB43ccc;
    }
    Msg_a9dbb8* msg = new Msg_a9dbb8;
    msg->AddRef();
    msg->Fn05(type);
    msg->Fn12(this);
    msg->Fn33(this);
    msg->Fn16(Slot32_a9dbb8_4(4));
    msg->Fn21(Slot07_a9dbb8_4());
    msg->Fn26(extra);
    if (type == 0x99ef1146 && self->mp30 != 0) {
        gpB23194->MessageSend(msg);
    } else {
        gpB23194->MessagePost(msg, false);
    }
    msg->Release();
}

#ifdef OB_DRAFTS
// CLOSE: 0x005e90e0 score 30
void cSC4Watercraft_4::Slot17_a9dbb8_4(uint32_t level, bool notify)
{
    Sub4_a9dbb8* self = reinterpret_cast<Sub4_a9dbb8*>(this);
    uint32_t old = Slot16_a9dbb8_4();
    if (old != level) {
        self->mbFlags2e = static_cast<uint8_t>((self->mbFlags2e & 0xf) + static_cast<uint8_t>(level << 4));
        if (static_cast<uint8_t>(Slot05_a9dbb8_4()) != 0) {
            if (gpB23194 == 0) {
                gpB23194 = gpB43ccc;
            }
            if (notify) {
                Slot15_a9dbb8_4(0x99ef1145, 0);
                return;
            }
            Msg_a9dbb8* msg = new Msg_a9dbb8;
            msg->AddRef();
            msg->Fn05(0xe6e85114);
            msg->Fn12(this);
            msg->Fn16(old);
            msg->Fn21(level);
            gpB23194->MessagePost(msg, false);
            msg->Release();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005e9410 score 42
bool cSC4Watercraft_4::Slot24_a9dbb8_4(void* pSet)
{
    Set_a9dbb8* set = static_cast<Set_a9dbb8*>(pSet);
    if (set->mnCount != 0) {
        set->Fn0046f820(set->mpHead->mpParent);
        set->mpHead->mpLeft = set->mpHead;
        set->mpHead->mpParent = 0;
        set->mpHead->mpRight = set->mpHead;
        set->mnCount = 0;
    }
    WordVec_a9dbb8 ids = { 0, 0, 0 };
    Fn005ff510(Slot06_a9dbb8_4(), 0xaa1dd396, &ids);
    uint32_t count = ids.mpEnd - ids.mpBegin;
    for (uint32_t i = 0; i < count; ++i) {
        uint32_t id = ids.mpBegin[i];
        if (id != 0) {
            SetNode_a9dbb8* head = set->mpHead;
            SetNode_a9dbb8* node = head;
            SetNode_a9dbb8* walk = head->mpParent;
            while (walk != 0) {
                if (walk->mnValue < id) {
                    walk = walk->mpRight;
                } else {
                    node = walk;
                    walk = walk->mpLeft;
                }
            }
            if (node == head || id < node->mnValue) {
                node = head;
            }
            if (node == head) {
                uint8_t result[8];
                set->Fn0049a050(result, &id);
            }
        }
    }
    bool nonEmpty = set->mpHead != 0;
    if (ids.mpBegin != 0) {
        Fn0090cf63(ids.mpBegin);
    }
    return nonEmpty;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005e9350 score 84
void cSC4Watercraft_4::Slot23_a9dbb8_4(uint32_t id)
{
    void* controller = Slot06_a9dbb8_4();
    WordVec_a9dbb8 ids = { 0, 0, 0 };
    Fn005ff510(controller, 0xaa1dd396, &ids);
    if (Fn004696c0(ids.mpBegin, ids.mpEnd, &id, &id) == ids.mpEnd) {
        if (ids.mpEnd != ids.mpCap) {
            if (ids.mpEnd != 0) {
                *ids.mpEnd = id;
            }
            ++ids.mpEnd;
        } else {
            ids.Fn0051ca60(ids.mpEnd, &id, 1, 1);
        }
        Fn005fe6b0(controller, 0xaa1dd396, &ids);
        Slot15_a9dbb8_4(0xebff18a3, id);
    }
    if (ids.mpBegin != 0) {
        Fn0090cf63(ids.mpBegin);
    }
}
#endif


// ---- batch 13 ----

// What a model hands back for its animation progress (slot 15 of the virtual base): the progress at +0x10, the rate at +0x18.
struct AnimInfo_a9dbb8 {
    float mf0;
    float mf4;
    float mf8;
    float mfc;
    float mf10;
    float mf14;
    float mf18;
};

// GLOBAL: 0x00b43ddc
extern void* gpB43ddc;

// The view utilities (zoom level at +0xc).
struct ViewUtil_a9dbb8 {
    uint8_t mPad[0xc];
    int32_t mnZoom;
    // STUB: 0x007f66a0
    void GetZoomAndRotation(int32_t* pZoom, int32_t* pRotation);
};

// GLOBAL: 0x00b43dd8
extern ViewUtil_a9dbb8* gpB43dd8;

// GLOBAL: 0x00a95554
extern const float gaA95554[];

// GLOBAL: 0x00a95540
extern const float gaA95540[];

#ifdef OB_DRAFTS
// CLOSE: 0x00508f80 score 79
bool cSC4Watercraft::DoAttachAnimTick(float)
{
    if (CheckAutomataFlag(1)) {
        return false;
    }
    AnimState_a9dbb8* state = static_cast<AnimState_a9dbb8*>(GetState());
    if (state->mpModel28 != 0) {
        AnimInfo_a9dbb8 info;
        ModelVBase_a9dbb8* base = state->mpModel28;
        base->Fn15(&info);
        if (info.mf10 < 1.0f) {
            float step = info.mf18 / (gfB21c84 * 0.5f);
            info.mf18 = 1.0f;
            info.mf10 = step + info.mf10;
            const float* value = &info.mf18;
            if (!(1.0f < info.mf10)) {
                value = &info.mf10;
            }
            state->mpModel28->Fn18(1, *value);
        }
    }
    if (!(state->mn30 >= 2 && state->mn30 <= 3)) {
        if (state->mpModel28 != 0) {
            int32_t last = state->mpModel28->Fn12() - 1;
            if (state->mpModel28->Fn11() >= last) {
                PopState();
                return true;
            }
        }
    }
    return state->mb2c;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00507e60 score 122
bool cSC4Watercraft::Slot70_a9dbb8(bool on)
{
    bool result = false;
    uint8_t flags = Sub4Of_a9dbb8(this)->mbFlags2f;
    uint8_t current = flags & 1;
    if (current != on) {
        if (gpB43d0c == 0) {
            return result;
        }
        cSC4Watercraft_4* sub = reinterpret_cast<cSC4Watercraft_4*>(reinterpret_cast<char*>(this) + 4);
        if (current) {
            if (flags & 2) {
                if (gpB43dd0 != 0) {
                    for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
                        ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
                        if (model != 0) {
                            gpB43dd0->Fn29(model->Fn00());
                        }
                    }
                }
                sub->Slot31_a9dbb8_4(2);
            }
            gpB43d0c->Fn21(sub, 0, 0);
            sub->Slot31_a9dbb8_4(1);
            return true;
        }
        if (mpModelsBegin != mpModelsEnd) {
            ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*mpModelsBegin);
            if (model != 0) {
                ModelVBase_a9dbb8* base = model;
                if (base != 0) {
                    base->Fn08(&mfVec170X);
                }
            }
        }
        if (gpB43d0c->Fn20(sub, 0)) {
            sub->Slot29_a9dbb8_4(1);
            return true;
        }
        return result;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00509290 score 58
void cSC4Watercraft::UpdateLighting()
{
    void* lighting = gpB43ddc;
    if (!CheckAutomataFlag(0x100000) && lighting != 0 && mpLight12c != 0) {
        int32_t zoom = 0;
        if (gpB43dd8 != 0) {
            zoom = gpB43dd8->mnZoom;
        }
        float dx = mfVec58X - mfDirOldX;
        float dy = mfVec58Y - mfDirOldY;
        float dz = mfVec58Z - mfDirOldZ;
        const float* limits = &gaA95554[zoom * 3];
        bool still = std::fabs(dx) <= limits[0] && std::fabs(dy) <= limits[1] && std::fabs(dz) <= limits[2];
        if (still) {
            float px = mfPosX - mfPosOldX;
            float py = mfPosY - mfPosOldY;
            float pz = mfPosZ - mfPosOldZ;
            if (px * px + py * py + pz * pz <= gaA95540[zoom]) {
                return;
            }
        }
        reinterpret_cast<Light_a9dbb8*>(&mpLight12c)->Fn00803e10(lighting, 0);
        mfPosOldX = mfPosX;
        mfPosOldY = mfPosY;
        mfPosOldZ = mfPosZ;
        mfDirOldX = mfVec58X;
        mfDirOldY = mfVec58Y;
        mfDirOldZ = mfVec58Z;
    }
}
#endif


// ---- batch 14 ----

struct Boat_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Fn07(void*);
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual float Fn17();
};

// A node of the manager's docking table: next, the lot, and two slots holding a boat each.
struct DockNode_a9dbb8 {
    DockNode_a9dbb8* mpNext;
    void* mpLot;
    void* mpBoatA;
    void* mpBoatB;
};

// cSC4WatercraftManager: the boats list head at +0x44, the docking hashtable buckets at +0xa90.
struct WatercraftMgr_a9dbb8 {
    uint8_t mPad0[0x44];
    ListNode_a9dbb8* mpBoats;
    uint8_t mPad48[0xa90 - 0x48];
    DockNode_a9dbb8** mpBucketsBegin;
    DockNode_a9dbb8** mpBucketsEnd;
    uint8_t mPada98[4];
    uint32_t mnA9c;
    uint8_t mPadaa0[0xac4 - 0xaa0];
    uint32_t mnAc4;
    // STUB: 0x0056cfe0
    void DoneDocking(void* lot, void* boat);
    // STUB: 0x0056d060
    void Fn0056d060(void* lot, void* boat);
    void* LookForBoatsAtPosition(Vec3_a9dbb8 position, Boat_a9dbb8* skip);
};

// GLOBAL: 0x00b0a158
extern float gfB0a158;

// GLOBAL: 0x00b22a80
extern float gfB22a80;

// FUNCTION: 0x0056d4d0
void cSC4Watercraft::EndDocking()
{
    if (mpLot24c != 0 && mbDocking274) {
        mb2b0 = false;
        WatercraftMgr_a9dbb8* manager = gpB43cec_a9dbb8->Fn46();
        if (manager != 0) {
            manager->DoneDocking(mpLot24c, this);
            mbDocking274 = false;
            SetAutomataFlag(0x10000000, false);
        }
    }
}

// FUNCTION: 0x005698e0
bool cSC4Watercraft::Fn005698e0()
{
    if (!CheckAutomataFlag(1)) {
        if (Fn005681b0()) {
            PushState(0x48, 0, -1.0f, 0, 0, 0, 0);
        } else if (GetBehavior() != 0x46 && GetBehavior() != 0x47) {
            return true;
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005681b0 score 18
bool cSC4Watercraft::Fn005681b0()
{
    int32_t rect[4];
    cSC4Watercraft_4* sub = reinterpret_cast<cSC4Watercraft_4*>(reinterpret_cast<char*>(this) + 4);
    sub->Slot11_a9dbb8_4(rect);
    int32_t xs[4] = { rect[0], rect[0], rect[2], rect[2] };
    int32_t zs[4] = { rect[1], rect[3], rect[1], rect[3] };
    for (int32_t i = 0; i < 4; ++i) {
        if (!gpB43cec_a9dbb8->Fn99(xs[i], zs[i])) {
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0056cfe0 score 36
void WatercraftMgr_a9dbb8::DoneDocking(void* lot, void* boat)
{
    Unknown_a9dbb8* held = static_cast<Unknown_a9dbb8*>(lot);
    if (held != 0) {
        held->AddRef();
    }
    uint32_t count = mpBucketsEnd - mpBucketsBegin;
    uint32_t index = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(lot)) % count;
    DockNode_a9dbb8* node = mpBucketsBegin[index];
    while (node != 0 && node->mpLot != lot) {
        node = node->mpNext;
    }
    if (held != 0) {
        held->Release();
    }
    if (node != 0 && node->mpBoatA == boat) {
        Unknown_a9dbb8* stored = static_cast<Unknown_a9dbb8*>(node->mpBoatA);
        if (stored != 0) {
            node->mpBoatA = 0;
            stored->Release();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0056d060 score 36
void WatercraftMgr_a9dbb8::Fn0056d060(void* lot, void* boat)
{
    Unknown_a9dbb8* held = static_cast<Unknown_a9dbb8*>(lot);
    if (held != 0) {
        held->AddRef();
    }
    uint32_t count = mpBucketsEnd - mpBucketsBegin;
    uint32_t index = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(lot)) % count;
    DockNode_a9dbb8* node = mpBucketsBegin[index];
    while (node != 0 && node->mpLot != lot) {
        node = node->mpNext;
    }
    if (held != 0) {
        held->Release();
    }
    if (node != 0 && node->mpBoatB == boat) {
        Unknown_a9dbb8* stored = static_cast<Unknown_a9dbb8*>(node->mpBoatB);
        if (stored != 0) {
            node->mpBoatB = 0;
            stored->Release();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00568c10 score 15
void* WatercraftMgr_a9dbb8::LookForBoatsAtPosition(Vec3_a9dbb8 position, Boat_a9dbb8* skip)
{
    for (ListNode_a9dbb8* node = mpBoats->mpNext; node != mpBoats; node = node->mpNext) {
        Boat_a9dbb8* boat = reinterpret_cast<Boat_a9dbb8*>(node->mpValue);
        Vec3_a9dbb8 where = { gfB22a80, gfB22a80, gfB22a80 };
        if (boat != 0 && boat != skip) {
            boat->Fn07(&where);
            float dx = position.x - where.x;
            float dy = position.y - where.y;
            float dz = position.z - where.z;
            float distance = static_cast<float>(std::sqrt(static_cast<double>(dx * dx + dy * dy + dz * dz)));
            if (distance < boat->Fn17() * gfB0a158) {
                return boat;
            }
        }
    }
    return 0;
}
#endif


// ---- batch 15 ----

// STUB: 0x005d17c0
SetNode_a9dbb8* SetNext_a9dbb8(SetNode_a9dbb8* node);

#ifdef OB_DRAFTS
// CLOSE: 0x0050b290 score 24
bool cSC4Watercraft::HandleRemoveController(void* pController)
{
    Unknown_a9dbb8* controller = static_cast<Unknown_a9dbb8*>(pController);
    if (controller != 0) {
        State_a9dbb8* top = static_cast<State_a9dbb8*>(GetState());
        while (top != 0 && top->mpObj8 == controller) {
            PopState();
            top = static_cast<State_a9dbb8*>(GetState());
        }
        void** it = mpStateBegin;
        while (it != mpStateEnd) {
            State_a9dbb8* state = static_cast<State_a9dbb8*>(*it);
            if (state->mpObj8 == controller) {
                controller->Release();
                if (it + 1 != mpStateEnd) {
                    std::memmove(it, it + 1, (mpStateEnd - (it + 1)) * sizeof(void*));
                }
                mpStateEnd = mpStateEnd - 1;
                Fn005e5620(state);
            } else {
                ++it;
            }
        }
        if (controller == mpLinked98) {
            Unknown_a9dbb8* linked = static_cast<Unknown_a9dbb8*>(mpLinked98);
            if (linked != 0) {
                mpLinked98 = 0;
                linked->Release();
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00570140 score 22
void cSC4Watercraft::HandleExitState(void* pState)
{
    State_a9dbb8* state = static_cast<State_a9dbb8*>(pState);
    if (state != 0) {
        switch (state->mnBehavior) {
        case 0x10:
            EnableActiveSound(true);
            Fn00567e80();
            break;
        case 0x4a:
            mb288 = false;
            Fn0056f700();
            break;
        case 0x4b:
            SetAutomataFlag(0x10000000, false);
            mb289 = false;
            break;
        case 0x4d: {
            SetAutomataFlag(0x10000000, false);
            Releasable53_a9dbb8* other = static_cast<Releasable53_a9dbb8*>(mpObj284);
            if (other != 0) {
                void** partnerSlot = reinterpret_cast<void**>(reinterpret_cast<char*>(other) + 0x280);
                Unknown_a9dbb8* partner = static_cast<Unknown_a9dbb8*>(*partnerSlot);
                if (partner != 0) {
                    *partnerSlot = 0;
                    partner->Release();
                }
                Unknown_a9dbb8* mine = static_cast<Unknown_a9dbb8*>(mpObj284);
                if (mine != 0) {
                    mpObj284 = 0;
                    mine->Release();
                }
            }
            break;
        }
        default:
            break;
        }
    }
    AutomatonHandleExitState(pState);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050ce60 score 131
bool cSC4Watercraft::PostInit()
{
    if (mb3c) {
        if (mnGroupId == 0) {
            ScriptSys_a9dbb8* system = gpB43cec_a9dbb8->Fn48();
            SetNode_a9dbb8* head = static_cast<SetNode_a9dbb8*>(Fn0090cf54(0x14));
            head->mpParent = 0;
            head->mpLeft = head;
            head->mpRight = head;
            Set_a9dbb8 set = { head, 0 };
            if (system != 0) {
                cSC4Watercraft_4* sub = reinterpret_cast<cSC4Watercraft_4*>(reinterpret_cast<char*>(this) + 4);
                if (sub->Slot24_a9dbb8_4(&set)) {
                    for (SetNode_a9dbb8* it = set.mpHead->mpLeft; it != set.mpHead; it = SetNext_a9dbb8(it)) {
                        uint32_t id = it->mnValue;
                        if (mnGroupId != 0) {
                            cOccupantGroup_a9dbb8* group = static_cast<cOccupantGroup_a9dbb8*>(system->Fn06(id));
                            group->GetGroupHierarchyDepth();
                        }
                        mnGroupId = id;
                    }
                }
            }
            if (set.mnCount != 0) {
                set.Fn0046f820(set.mpHead->mpParent);
                set.mpHead->mpLeft = set.mpHead;
                set.mpHead->mpParent = 0;
                set.mpHead->mpRight = set.mpHead;
            }
            if (set.mpHead != 0) {
                Fn0090cf63(set.mpHead);
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050ef50 score 152
bool cSC4Watercraft::PushState(uint32_t id, void* obj, float f3, uint8_t flag, uint32_t a5, uint32_t a6, void* a7)
{
    bool result = false;
    if (id == 0 && obj == 0) {
        if (mpStateBegin != mpStateEnd) {
            SetState(0, 0, f3, flag, a5, a6, a7);
            return true;
        }
        return result;
    }
    if (mpStateBegin != mpStateEnd) {
        if (static_cast<State_a9dbb8*>(GetState())->mnBehavior == id) {
            if (static_cast<State_a9dbb8*>(GetState())->mpObj8 == obj) {
                return false;
            }
        }
    }
    HandleExitState(GetState());
    State_a9dbb8* state = static_cast<State_a9dbb8*>(CreateAutomataState(id));
    WordVec_a9dbb8* stack = reinterpret_cast<WordVec_a9dbb8*>(&mpStateBegin);
    if (stack->mpEnd != stack->mpCap) {
        if (stack->mpEnd != 0) {
            *reinterpret_cast<State_a9dbb8**>(stack->mpEnd) = state;
        }
        stack->mpEnd = stack->mpEnd + 1;
    } else {
        stack->Fn0051ca60(stack->mpEnd, reinterpret_cast<uint32_t*>(&state), 1, 1);
    }
    state->mnBehavior = id;
    state->mpObj8 = obj;
    state->mf10 = f3;
    state->mb14 = flag;
    state->mn1c = a5;
    state->mn18 = a6;
    state->mp24 = a7;
    if (obj != 0) {
        static_cast<Unknown_a9dbb8*>(obj)->AddRef();
    }
    state->mnDepth = (stack->mpEnd - stack->mpBegin) - 1;
    HandleEnterState(state);
    return true;
}
#endif


// ---- batch 16 ----

// GLOBAL: 0x00b22aa4
extern cRZString gResult_a9dbb8;

#ifdef OB_DRAFTS
// CLOSE: 0x00573340 score 38
bool cSC4Watercraft::DoStateTick(float dt)
{
    switch (GetBehavior()) {
    case 7:
        mf2bc = dt + mf2bc;
        if (mf2bc <= 60000.0f) {
            break;
        }
        PushState(0x49, 0, -1.0f, 0, 0, 0, 0);
        mf2c0 = dt + mf2c0;
        Fn00570270(dt);
        break;
    case 0x46:
    case 0x47:
        mf2c0 = dt + mf2c0;
        Fn00570270(dt);
        break;
    case 0x48:
        SetOrientation(true);
        return true;
    case 0x49:
        SetOrientation(false);
        return true;
    case 0x4a:
        if (!DoDockingTick(dt)) {
            PopState();
        }
        break;
    case 0x4b:
        Fn005704d0();
        break;
    case 0x4d:
        Fn005694b0(dt);
        break;
    case 0x4e:
        if (!Fn0056bd80(dt)) {
            PopState();
        }
        break;
    default:
        break;
    }
    return AutomatonDoStateTick(dt);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00570ae0 score 85
void* cSC4Watercraft::GetDebugExtraText()
{
    WatercraftMgr_a9dbb8* manager = gpB43cec_a9dbb8->Fn46();
    int32_t cellX = -1;
    int32_t cellZ = -1;
    gpB43cec_a9dbb8->Fn95(mfMoveFromX, mfMoveFromZ, &cellX, &cellZ);
    gResult_a9dbb8.Sprintf("Tow: %d, (FT,MT): (%d,%d), (Q,D): (%d,%d), Turn: %3.2f, Speed: %3.2f, Cell(%3d,%3d), Pos(%3.2f,%3.2f,%3.2f), Ornt<%3.2f,%3.2f,%3.2f>",
                           mpObj280 != 0, manager->mnA9c, manager->mnAc4, mb289, mb288,
                           static_cast<double>(mfTurn2e0), static_cast<double>(mfSpeed2dc), cellX, cellZ,
                           static_cast<double>(mfMoveFromX), static_cast<double>(mfMoveFromY), static_cast<double>(mfMoveFromZ),
                           static_cast<double>(mfMoveToX), static_cast<double>(mfMoveToY), static_cast<double>(mfMoveToZ));
    return &gResult_a9dbb8;
}
#endif


// ---- batch 17 ----

struct Anim_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Fn04(void*);
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Fn14(uint32_t);
};

// A 3-by-3 matrix of floats and the transform record the models take (flag bytes, matrix at +8, position at +0x30).
struct Matrix3_a9dbb8 {
    float m[9];
};

struct Transform_a9dbb8 {
    uint8_t mCount;
    uint8_t mFlags;
    uint8_t mPad2[2];
    Matrix3_a9dbb8 mMatrix;
    float mPos[3];
    float mScale;
};

// STUB: 0x0080b830
void Fn0080b830(const void* pDirection, Matrix3_a9dbb8* pOut);

// STUB: 0x007fede0
bool Fn007fede0(const void* pKey, void* pModelOut);

// GLOBAL: 0x00b21ba4
extern float gfB21ba4;

// The vector of resource keys at +0xc0 (12-byte elements).
struct KeyVec_a9dbb8 {
    void* mpBegin;
    void* mpEnd;
    void* mpCap;
    // STUB: 0x0050da30
    void Fn0050da30(const void* pKey);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005094a0 score 113
void cSC4Watercraft::PositionModelInstance(void* pBase)
{
    ModelVBase_a9dbb8* base = static_cast<ModelVBase_a9dbb8*>(pBase);
    Transform_a9dbb8 transform;
    transform.mCount = 0;
    transform.mFlags = 0;
    for (int32_t i = 0; i < 9; ++i) {
        transform.mMatrix.m[i] = (i % 4 == 0) ? 1.0f : 0.0f;
    }
    transform.mPos[0] = 0.0f;
    transform.mPos[1] = 0.0f;
    transform.mPos[2] = 0.0f;
    transform.mScale = 1.0f;
    base->Fn09(&transform);
    Matrix3_a9dbb8 rotation;
    for (int32_t i = 0; i < 9; ++i) {
        rotation.m[i] = gfB21ba4;
    }
    Fn0080b830(&mfVec58X, &rotation);
    transform.mPos[0] = mfPosX;
    transform.mPos[1] = mfPosY;
    transform.mPos[2] = mfPosZ;
    transform.mFlags = transform.mFlags | 1;
    transform.mCount = transform.mCount + 1;
    transform.mMatrix = rotation;
    transform.mFlags = transform.mFlags | 4;
    transform.mCount = transform.mCount + 1;
    base->Fn10(&transform);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050e4d0 score 94
void* cSC4Watercraft::AddModelInstance(void* pKey)
{
    const Key_a9dbb8* key = static_cast<const Key_a9dbb8*>(pKey);
    ModelInst_a9dbb8* model = 0;
    if (key->mnInstance != 0) {
        if (mnAnimKeyInstance == 0) {
            mnAnimKeyType = key->mnType;
            mnAnimKeyGroup = key->mnGroup;
            mnAnimKeyInstance = key->mnInstance;
            mn128 = key->mnInstance;
        }
        bool wasPlaced = ((Sub4Of_a9dbb8(this)->mbFlags2f >> 1) & 1) != 0;
        if (wasPlaced) {
            PlaceInRenderer(false);
        }
        if (Fn007fede0(key, &model)) {
            Anim_a9dbb8* anim = static_cast<Anim_a9dbb8*>(model->Fn00());
            anim->Fn04(Sub4Of_a9dbb8(this));
            anim->Fn14(1);
            int32_t zoom;
            int32_t rotation;
            gpB43dd8->GetZoomAndRotation(&zoom, &rotation);
            model->Fn08(zoom, rotation);
            ModelVBase_a9dbb8* base = model;
            PositionModelInstance(base);
            WordVec_a9dbb8* models = reinterpret_cast<WordVec_a9dbb8*>(&mpModelsBegin);
            if (models->mpEnd != models->mpCap) {
                if (models->mpEnd != 0) {
                    *reinterpret_cast<ModelInst_a9dbb8**>(models->mpEnd) = model;
                }
                models->mpEnd = models->mpEnd + 1;
            } else {
                models->Fn0051ca60(models->mpEnd, reinterpret_cast<uint32_t*>(&model), 1, 1);
            }
            reinterpret_cast<KeyVec_a9dbb8*>(&mpPathBegin)->Fn0050da30(key);
        }
        if (wasPlaced) {
            PlaceInRenderer(true);
        }
        InitLighting();
    }
    return model;
}
#endif


// ---- batch 18 ----

struct ModelInst3_a9dbb8 {
    virtual void* Fn00(uint32_t);
};

struct NameStr_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual const char* Fn05();
};

// A key-effect node of the group's hashtable: next link, then two strings (the effect and the registration point).
struct KeyEffect_a9dbb8 {
    KeyEffect_a9dbb8* mpNext;
    uint8_t mPad4[4];
    NameStr_a9dbb8 mPointName;
    uint8_t mPadc[0x1c - 0xc];
    NameStr_a9dbb8 mEffectName;
    uint8_t mPad20[4];
    char* mpEffectBegin;
    char* mpEffectEnd;
};

// The hashtable of key effects inside a group template (at +0x70; its element count sits at +0x80).
struct EffectTable_a9dbb8 {
    // STUB: 0x004b0390
    void Fn004b0390(HIter_a9dbb8* pOut);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00507f70 score 104
bool cSC4Watercraft::PlaceInRenderer(bool on)
{
    bool result = false;
    uint8_t flags = Sub4Of_a9dbb8(this)->mbFlags2f;
    uint8_t placed = (flags >> 1) & 1;
    if (placed != on) {
        if (gpB43dd0 != 0) {
            cSC4Watercraft_4* sub = reinterpret_cast<cSC4Watercraft_4*>(reinterpret_cast<char*>(this) + 4);
            if (placed) {
                for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
                    ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
                    if (model != 0) {
                        gpB43dd0->Fn29(model->Fn00());
                    }
                }
                sub->Slot31_a9dbb8_4(2);
                return true;
            }
            if (!(flags & 1)) {
                Slot70_a9dbb8(true);
            }
            if (Sub4Of_a9dbb8(this)->mbFlags2f & 1) {
                float opacity = reinterpret_cast<Ramp_a9dbb8*>(reinterpret_cast<char*>(this) + 0x1b0)->Fn004fa960();
                bool ok = true;
                for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
                    if (!ok) {
                        return false;
                    }
                    ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
                    if (model != 0) {
                        if (opacity < 1.0f) {
                            model->Fn18(1, opacity);
                        } else {
                            model->Fn18(0, 1.0f);
                        }
                        ok = gpB43dd0->Fn28(model->Fn00()) != 0;
                    }
                }
                if (ok) {
                    sub->Slot29_a9dbb8_4(2);
                }
            }
            return false;
        }
        return result;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00508610 score 98
void cSC4Watercraft::FinishMove(bool a, bool b)
{
    if (mpModelsBegin != mpModelsEnd) {
        ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*mpModelsBegin);
        ModelVBase_a9dbb8* base = model;
        base->Fn08(&mfVec170X);
    }
    cSC4Watercraft_4* sub = reinterpret_cast<cSC4Watercraft_4*>(reinterpret_cast<char*>(this) + 4);
    if (sub->Slot32_a9dbb8_4(4)) {
        uint8_t flags = Sub4Of_a9dbb8(this)->mbFlags2f;
        if (flags & 2) {
            for (void** it = mpModelsBegin; it != mpModelsEnd; ++it) {
                ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*it);
                if (model != 0) {
                    if (a) {
                        gpB43dd0->Fn30(model->Fn00());
                    } else if (b) {
                        gpB43dd0->Fn31(static_cast<ModelInst3_a9dbb8*>(static_cast<void*>(model))->Fn00(3));
                    }
                }
            }
            if (Sub4Of_a9dbb8(this)->mbFlags2f & 1) {
                gpB43d0c->Fn24(sub, 0);
            }
        } else {
            if (flags & 1) {
                gpB43d0c->Fn24(sub, 0);
            } else {
                Slot70_a9dbb8(true);
            }
            if (Sub4Of_a9dbb8(this)->mbFlags2f & 1) {
                PlaceInRenderer(true);
            }
        }
    }
    if (mf1c0 > 100.0f) {
        Slot102_a9dbb8(9, 0);
        mf1c0 = 0.0f;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050d580 score 106
void cSC4Watercraft::ApplyAutomataGroup()
{
    cOccupantGroup_a9dbb8* group = static_cast<cOccupantGroup_a9dbb8*>(GetAutomataGroup());
    if (group != 0 && group->mnEffectCount80 != 0) {
        HIter_a9dbb8 it;
        reinterpret_cast<EffectTable_a9dbb8*>(reinterpret_cast<char*>(group) + 0x70)->Fn004b0390(&it);
        while (it.mpCur != 0) {
            KeyEffect_a9dbb8* node = reinterpret_cast<KeyEffect_a9dbb8*>(it.mpCur);
            if (node->mpEffectEnd != node->mpEffectBegin) {
                if (EmbeddedOf_a9dbb8(this)->Fn09(&node->mEffectName, &node->mPointName) == 0) {
                    cRZString text;
                    text.Sprintf("Warning: Could not create effect named '%s' attached to reg. point named '%s' for automata group '%d'.\n", node->mPointName.Fn05(), node->mEffectName.Fn05(), group->mnId10);
                }
            }
            HNode_a9dbb8* next = it.mpCur->mpNext;
            if (next == 0) {
                next = it.Fn0050bbe0();
            }
            it.mpCur = next;
        }
    }
}
#endif


// ---- batch 19 ----

struct Target11_a9dbb8 {
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
    virtual void Fn11(void*);
};

struct SoundSvc_a9dbb8 {
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
    virtual void Fn11(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
};

struct VehMgr_a9dbb8 {
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
    virtual bool Fn13();
};

// STUB: 0x00913c9e
SoundSvc_a9dbb8* Fn00913c9e();

// STUB: 0x004bb9e0
void Fn004bb9e0();

// GLOBAL: 0x00b43d44
extern VehMgr_a9dbb8* gpB43d44;

#ifdef OB_DRAFTS
// CLOSE: 0x00508e10 score 84
bool cSC4Watercraft::DoMagnetTick(float)
{
    if (CheckAutomataFlag(1)) {
        return false;
    }
    State_a9dbb8* state = static_cast<State_a9dbb8*>(GetState());
    if (state->mpObj8 != 0) {
        Vec3_a9dbb8 target = { gfB21ba4, gfB21ba4, gfB21ba4 };
        static_cast<Target11_a9dbb8*>(state->mpObj8)->Fn11(&target);
        float dx = target.x - mfPosX;
        float dy = target.y - mfPosY;
        float dz = target.z - mfPosZ;
        float length = static_cast<float>(std::sqrt(static_cast<double>(dx * dx + dy * dy + dz * dz)));
        if (length > 0.0001f) {
            float scale = gfB09978 / length;
            float speed = reinterpret_cast<Ramp_a9dbb8*>(reinterpret_cast<char*>(this) + 0x1a0)->Fn004fa960();
            Vec3_a9dbb8 step;
            step.x = dx * scale * speed + mfPosX;
            step.y = dy * scale * speed + mfPosY;
            step.z = dz * scale * speed + mfPosZ;
            if (!CheckAutomataFlag(0x40000)) {
                step.y = gpB43cec_a9dbb8->Fn40()->Fn18(step.x, step.z);
            }
            MoveTo(&step, 0);
        }
    }
    UpdateAttraction();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050a130 score 34
void cSC4Watercraft::UpdateActiveSound(float dt)
{
    if (Fn00913c9e() != 0) {
        uint32_t count = static_cast<uint32_t*>(mpVec1c8End) - static_cast<uint32_t*>(mpVec1c8Begin);
        if (count != 0) {
            mf1e0 = dt + mf1e0;
            if (mf1e0 > 100.0f) {
                mf1e0 = 0.0f;
                uint32_t index = gpB43dd8->mnZoom;
                if (index >= count) {
                    index = count - 1;
                }
                uint32_t sound = 0;
                if (mbActiveSound1dc && !gpB43d44->Fn13()) {
                    sound = static_cast<uint32_t*>(mpVec1c8Begin)[index];
                }
                if (mnSfxId1d4 != 0) {
                    if (sound != mnSfxKind1d8) {
                        Fn00913c9e()->Fn11(0x6a451908, mnSfxId1d4, 0, 0, 0);
                        mnSfxId1d4 = 0;
                        mnSfxKind1d8 = 0;
                    }
                }
                if (mnSfxId1d4 == 0) {
                    if (sound != 0) {
                        Fn004bb9e0();
                        mnSfxId1d4 = Fn004f7bb0();
                        mnSfxKind1d8 = sound;
                        Fn00913c9e()->Fn11(0xea451903, mnSfxKind1d8, mnSfxId1d4, 0, 0);
                    }
                }
                if (mnSfxId1d4 != 0) {
                    Vec3_a9dbb8 where = { gfB21ba4, gfB21ba4, gfB21ba4 };
                    SetVisible(&where);
                    SoundSvc_a9dbb8* service = Fn00913c9e();
                    service->Fn11(0xca45190f, mnSfxId1d4, static_cast<int32_t>(where.x), static_cast<int32_t>(where.y), static_cast<int32_t>(where.z));
                }
            }
        }
    }
}
#endif


// ---- batch 20 ----

// The state records CreateAutomataState allocates (vtable at +0, the behavior id at +4); each kind has its own
// out-of-line constructor and size. STUB: 0x005e55e0 is the plain operator new they all use.
// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t size);

struct StateRec_a9dbb8 {
    virtual void PadRec();
    uint32_t mnBehavior;
};

struct StateRecA_a9dbb8 : StateRec_a9dbb8 {
    uint8_t mData[0x34 - 8];
    // STUB: 0x00505290
    StateRecA_a9dbb8();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecB_a9dbb8 : StateRec_a9dbb8 {
    uint8_t mData[0x40 - 8];
    // STUB: 0x00505bf0
    StateRecB_a9dbb8();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecC_a9dbb8 : StateRec_a9dbb8 {
    uint8_t mData[0x40 - 8];
    // STUB: 0x00505c70
    StateRecC_a9dbb8();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecD_a9dbb8 : StateRec_a9dbb8 {
    uint8_t mData[0x30 - 8];
    // STUB: 0x00505c40
    StateRecD_a9dbb8();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecE_a9dbb8 : StateRec_a9dbb8 {
    uint8_t mData[0x274 - 8];
    // STUB: 0x00506370
    StateRecE_a9dbb8();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecF_a9dbb8 : StateRec_a9dbb8 {
    uint8_t mData[0x58 - 8];
    // STUB: 0x00505ca0
    StateRecF_a9dbb8();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecG_a9dbb8 : StateRec_a9dbb8 {
    uint8_t mData[0x34 - 8];
    // STUB: 0x00509a20
    StateRecG_a9dbb8();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecH_a9dbb8 : StateRec_a9dbb8 {
    uint8_t mData[0x2c - 8];
    // STUB: 0x005052d0
    StateRecH_a9dbb8();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecI_a9dbb8 : StateRec_a9dbb8 {
    uint8_t mData[0x44 - 8];
    // STUB: 0x00506330
    StateRecI_a9dbb8();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

struct StateRecJ_a9dbb8 : StateRec_a9dbb8 {
    uint8_t mData[0x2c - 8];
    // STUB: 0x00506420
    StateRecJ_a9dbb8();
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// The generic 0x28-byte record: its constructor is inlined at the call site.
struct StateRecK_a9dbb8 : StateRec_a9dbb8 {
    uint32_t mn8;
    uint32_t mnc;
    uint32_t mn10;
    uint8_t mb14;
    uint32_t mn18;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
    StateRecK_a9dbb8() : mn8(0), mnc(0), mn10(0), mb14(0), mn18(0), mn1c(0), mn20(0), mn24(0) { mnBehavior = 0; }
    static void* operator new(size_t size) { return Fn005e55e0(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050b7f0 score 18
void* cSC4Watercraft::CreateAutomataState(uint32_t id)
{
    StateRec_a9dbb8* state;
    switch (id) {
    case 8:
        state = new StateRecA_a9dbb8;
        break;
    case 11:
        state = new StateRecB_a9dbb8;
        break;
    case 14:
        state = new StateRecC_a9dbb8;
        break;
    case 15:
        state = new StateRecD_a9dbb8;
        break;
    case 16:
        state = new StateRecE_a9dbb8;
        break;
    case 17:
        state = new StateRecF_a9dbb8;
        break;
    case 19:
        state = new StateRecG_a9dbb8;
        break;
    case 20:
        state = new StateRecH_a9dbb8;
        break;
    case 21:
        state = new StateRecI_a9dbb8;
        break;
    case 0x34:
        state = new StateRecJ_a9dbb8;
        break;
    default:
        state = new StateRecK_a9dbb8;
        break;
    }
    if (state != 0) {
        state->mnBehavior = id;
    }
    return state;
}
#endif


// ---- batch 21 ----

// An attraction record: id first, the chance at +8.
struct Item_a9dbb8 {
    uint32_t mnId;
    uint8_t mPad4[4];
    float mf8;
};

struct Linked_a9dbb8 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual uint32_t Fn06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual Item_a9dbb8* Fn32(uint32_t, void*);
};

// STUB: 0x00913a29
// (a member of the random object: a double in [0, 1))

#ifdef OB_DRAFTS
// CLOSE: 0x005096b0 score 104
void cSC4Watercraft::UpdateAttraction()
{
    if (!CheckAutomataFlag(0x4000)) {
        AutoMgr_a9dbb8* manager = gpB43cec_a9dbb8->Fn47();
        Unknown_a9dbb8* target = static_cast<Unknown_a9dbb8*>(manager->Fn22(Sub4Of_a9dbb8(this), &mnA4, &mn9c, &mnA0));
        if (target != 0) {
            target->AddRef();
        }
        Unknown_a9dbb8* old = static_cast<Unknown_a9dbb8*>(mpLinked98);
        if (target != old) {
            if (old != 0) {
                State_a9dbb8* top = static_cast<State_a9dbb8*>(GetState());
                while (top != 0 && top->mpObj8 == mpLinked98) {
                    PopState();
                    top = static_cast<State_a9dbb8*>(GetState());
                }
            }
            Unknown_a9dbb8* previous = static_cast<Unknown_a9dbb8*>(mpLinked98);
            if (target != previous) {
                if (target != 0) {
                    target->AddRef();
                }
                mpLinked98 = target;
                if (previous != 0) {
                    previous->Release();
                }
            }
        }
        Linked_a9dbb8* current = static_cast<Linked_a9dbb8*>(mpLinked98);
        if (current != 0) {
            Item_a9dbb8* item = current->Fn32(mn9c, &mfPosX);
            if (item != 0) {
                float limit = item->mf8;
                double roll = gB21d78.Fn00913a29();
                if (!(limit < roll)) {
                    State_a9dbb8* state = static_cast<State_a9dbb8*>(GetState());
                    bool push = true;
                    while (state != 0) {
                        if (state->mpObj8 != 0) {
                            Linked_a9dbb8* linked = static_cast<Linked_a9dbb8*>(mpLinked98);
                            if (static_cast<Linked_a9dbb8*>(state->mpObj8)->Fn06() == linked->Fn06() && state->mnBehavior != item->mnId) {
                                PopState();
                                state = static_cast<State_a9dbb8*>(GetState());
                                continue;
                            }
                        }
                        if (state->mp24 == item) {
                            push = false;
                        }
                        break;
                    }
                    if (push) {
                        PushBehavior(item, mpLinked98);
                    }
                }
            }
        }
        if (target != 0) {
            target->Release();
        }
    }
}
#endif


// ---- batch 22 ----

// The tint record the ghost model is given: flag byte at +0, colour at +4 (r, g, b), alpha-ish at +0x10.
struct Tint_a9dbb8 {
    uint8_t mFlags;
    uint8_t mPad1[3];
    float mf4;
    float mf8;
    float mfc;
    float mf10;
    uint8_t mPad14[0x30];
};

// The small holder at +0xd0 the ghost is registered with.
struct GhostHolder_a9dbb8 {
    void* mpValue;
    // STUB: 0x00513ff0
    void Fn00513ff0(void* value);
    // STUB: 0x008038d0
    bool Fn008038d0(void* value);
};

// STUB: 0x00803060
void* Fn00803060(void* pTemp);

// STUB: 0x008030a0
void Fn008030a0(void* pTemp);

#ifdef OB_DRAFTS
// CLOSE: 0x00514340 score 129
void cSC4Watercraft::InitGhostModel()
{
    cSC4Watercraft_4* sub = reinterpret_cast<cSC4Watercraft_4*>(reinterpret_cast<char*>(this) + 4);
    if (sub->Slot07_a9dbb8_4() != 0x496e5783 || sub->Slot07_a9dbb8_4() != 0x897f7ec2) {
        if (mpPathBegin != mpPathEnd) {
            ModelInst_a9dbb8* ghost = static_cast<ModelInst_a9dbb8*>(mpGhost);
            if (ghost != 0) {
                mpGhost = 0;
                ModelVBase_a9dbb8* base = ghost;
                base->Release();
            }
            ghost = static_cast<ModelInst_a9dbb8*>(mpGhost);
            if (ghost != 0) {
                mpGhost = 0;
                ModelVBase_a9dbb8* base = ghost;
                base->Release();
            }
            if (Fn007fede0(mpPathBegin, &mpGhost)) {
                ModelVBase_a9dbb8* base = static_cast<ModelInst_a9dbb8*>(mpGhost);
                Tint_a9dbb8 tint;
                base->Fn15(&tint);
                tint.mFlags = tint.mFlags | 0x20;
                tint.mf10 = 0.5f;
                tint.mf4 = 0.6f;
                tint.mf8 = 1.0f;
                tint.mfc = 0.6f;
                ModelVBase_a9dbb8* base2 = static_cast<ModelInst_a9dbb8*>(mpGhost);
                base2->Fn16(&tint);
                Transform_a9dbb8 transform;
                transform.mCount = 0;
                transform.mFlags = 0;
                for (int32_t i = 0; i < 9; ++i) {
                    transform.mMatrix.m[i] = (i % 4 == 0) ? 1.0f : 0.0f;
                }
                            transform.mPos[0] = 0.0f;
                transform.mPos[1] = 0.0f;
                transform.mPos[2] = 0.0f;
                transform.mScale = 1.0f;
                ModelVBase_a9dbb8* first = static_cast<ModelInst_a9dbb8*>(*mpModelsBegin);
                first->Fn09(&transform);
                ModelVBase_a9dbb8* ghostBase = static_cast<ModelInst_a9dbb8*>(mpGhost);
                ghostBase->Fn10(&transform);
                ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(mpGhost);
                gpB43dd0->Fn28(model->Fn00());
                uint8_t temp[0x30];
                GhostHolder_a9dbb8* holder = reinterpret_cast<GhostHolder_a9dbb8*>(reinterpret_cast<char*>(this) + 0xd0);
                holder->Fn00513ff0(Fn00803060(temp));
                Fn008030a0(temp);
                holder->Fn008038d0(static_cast<ModelInst_a9dbb8*>(mpGhost)->Fn00());
            }
        }
    }
}
#endif


// ---- batch 23 ----

// The original's float-to-cell conversion: the scaled value is turned into an integer through the 1.5 * 2^23 bit trick,
// then corrected by one when it lands exactly on the next cell.
inline int32_t CellOf_a9dbb8(float scaled)
{
    float t = (scaled - 0.5f) + 12582912.0f;
    int32_t cell = *reinterpret_cast<int32_t*>(&t) - 0x4b400000;
    if (static_cast<float>(cell + 1) == scaled) {
        cell = cell + 1;
    }
    return cell;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005e8e20 score 26
void cSC4Watercraft_4::Slot11_a9dbb8_4(void* pOut)
{
    float a[3];
    float b[3];
    Slot10_a9dbb8_4(a, b);
    int32_t* out = static_cast<int32_t*>(pOut);
    float ax = a[0] + 0.01f;
    a[2] = a[2] + 0.01f;
    out[0] = CellOf_a9dbb8(ax * 0.0625f);
    out[1] = CellOf_a9dbb8(a[2] * 0.0625f);
    float bx = b[0] - 0.01f;
    b[2] = b[2] - 0.01f;
    out[2] = CellOf_a9dbb8(bx * 0.0625f);
    out[3] = CellOf_a9dbb8(b[2] * 0.0625f);
}
#endif


// ---- batch 24 ----

// A boat's position as seen by another boat (the towing partner).
struct PartnerPos_a9dbb8 {
    uint8_t mPad[0x40];
    float mfX;
    float mfY;
    float mfZ;
};

// The player-drive state: the two drive command axes at +0x7c and +0x80.
struct DriveState_a9dbb8 {
    uint8_t mPad[0x7c];
    float mfCommandA;
    float mfCommandB;
};

// GLOBAL: 0x00b0a18c
extern float gfB0a18c;

// GLOBAL: 0x00a952e0
extern const float gfDriveCommandInactive_a9dbb8;

#ifdef OB_DRAFTS
// CLOSE: 0x0056d310 score 116
bool cSC4Watercraft::DoPlayerDriveTick(float dt)
{
    AutomatonDoPlayerDriveTick(dt);
    if (mpObj280 != 0) {
        PartnerPos_a9dbb8* partner = static_cast<PartnerPos_a9dbb8*>(mpObj280);
        float dx = partner->mfX - mfPosX;
        float dy = partner->mfY - mfPosY;
        float dz = partner->mfZ - mfPosZ;
        float inverse = gfB0a18c / static_cast<float>(std::sqrt(static_cast<double>(dz * dz + dy * dy + dx * dx)));
        float dot = dz * inverse * mfVec58Z + dy * inverse * mfVec58Y + dx * inverse * mfVec58X;
        if (dot > 0.0f) {
            Fn00567e80();
        }
    }
    DriveState_a9dbb8* state = static_cast<DriveState_a9dbb8*>(GetState());
    if (state != 0) {
        if (gfDriveCommandInactive_a9dbb8 == state->mfCommandA && gfDriveCommandInactive_a9dbb8 == state->mfCommandB && mfSpeed2dc != 0.0f) {
            bool before = Fn00566e00(mfSpeed2dc) > 0.0f;
            mfSpeed2dc = mfSpeed2dc - dt * 0.001f * mf350 * Fn00566e00(mfSpeed2dc);
            bool after = Fn00566e00(mfSpeed2dc) > 0.0f;
            if (before != after) {
                mfSpeed2dc = 0.0f;
            }
        }
    }
    if (Fn005698e0()) {
        float step;
        if (dt >= 0.0f) {
            step = mf3d0;
            if (dt <= mf3d0) {
                step = dt;
            }
        } else {
            step = 0.0f;
        }
        MovementPositionNew(&step);
        Fn0056c090();
    }
    return true;
}
#endif


// ---- batch 25 ----

// The drive/tow state the enter handler fills: scalar members at +0x30, +0x34, +0x144, +0x178, +0x1ac, +0x234.
struct TowState_a9dbb8 {
    uint8_t mPad0[4];
    uint32_t mnBehavior;
    uint8_t mPad8[0x30 - 8];
    uint32_t mn30;
    float mf34;
    uint8_t mPad38[0x144 - 0x38];
    uint32_t mn144;
    uint8_t mPad148[0x178 - 0x148];
    uint32_t mn178;
    uint8_t mPad17c[0x1ac - 0x17c];
    float mf1ac;
    uint8_t mPad1b0[0x234 - 0x1b0];
    uint32_t mn234;
};

// FUNCTION: 0x0056e340
bool cSC4Watercraft::HandleEnterState(void* pState)
{
    TowState_a9dbb8* state = static_cast<TowState_a9dbb8*>(pState);
    bool result = AutomatonHandleEnterState(pState);
    if (state != 0) {
        switch (state->mnBehavior) {
        case 0x10: {
            EnableActiveSound(false);
            state->mn30 = 0;
            state->mn234 = mn394;
            cOccupantGroup_a9dbb8* group = static_cast<cOccupantGroup_a9dbb8*>(GetAutomataGroup());
            if (group != 0) {
                float* value = static_cast<float*>(group->Fn0046b4a0());
                if (value != 0) {
                    state->mf34 = value[2];
                } else {
                    state->mf34 = 1.0f;
                }
            }
            state->mn144 = 0xf;
            state->mn178 = 0;
            state->mf1ac = 2000.0f;
            Fn00567e80();
            EndDocking();
            break;
        }
        case 0x46:
        case 0x47:
            SetAutomataFlag(0x10000000, true);
            SetAutomataFlag(0x8000000, true);
            Slot102_a9dbb8(0xb, 0);
            mf2c0 = 0.0f;
            Fn00567e80();
            EndDocking();
            break;
        case 0x48:
            SetAutomataFlag(0x10000000, true);
            SetAutomataFlag(0x8000000, true);
            SetOrientation(true);
            Fn00567e80();
            EndDocking();
            break;
        case 0x49:
            SetAutomataFlag(0x10000000, true);
            SetAutomataFlag(0x8000000, true);
            SetOrientation(false);
            Fn00567e80();
            EndDocking();
            break;
        case 0x4a:
            SetAutomataFlag(0x10000000, true);
            mb288 = true;
            mb2b0 = true;
            Fn00567e80();
            break;
        case 0x4b:
            SetAutomataFlag(0x10000000, true);
            mb289 = true;
            mfSpeed2dc = 0.0f;
            mfTurn2e0 = 0.0f;
            Fn00567e80();
            break;
        case 0x4c:
            mfSpeed2dc = 0.0f;
            mfTurn2e0 = 0.0f;
            Fn00567e80();
            EndDocking();
            break;
        case 0x4d:
            mb2cb = true;
            SetAutomataFlag(0x10000000, true);
            EndDocking();
            break;
        default:
            break;
        }
    }
    return result;
}


// ---- batch 26 ----

struct Target32_a9dbb8 {
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
    virtual void Pad13();
    virtual void Pad14();
    virtual void Fn15(void*);
};

struct Msg2_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual uint32_t Fn04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual Target32_a9dbb8* Fn32();
};

struct BoatIface_a9dbb8 {
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
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual bool Fn22(uint32_t);
};

struct BoatObj_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual BoatIface_a9dbb8* Fn05();
};

// A smart-pointer slot: assignment is out of line.
struct SmartSlot_a9dbb8 {
    void* mp;
    // STUB: 0x005447b0
    void Assign(void* value);
};

struct View38_a9dbb8 {
    // STUB: 0x00507cd0
    bool Fn00507cd0(void* message);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00569230 score 163
uint32_t cSC4Watercraft_38::DoMessage(void* pMessage)
{
    Msg2_a9dbb8* message = static_cast<Msg2_a9dbb8*>(pMessage);
    cSC4Watercraft* boatSelf = reinterpret_cast<cSC4Watercraft*>(reinterpret_cast<char*>(this) - 0x38);
    bool handled = false;
    uint32_t type = message->Fn04();
    if (type == 0x26d31ec1) {
        boatSelf->Fn00567310();
        handled = true;
    } else if (type == 0xac400a31 && boatSelf->mb2d8) {
        boatSelf->mb2d8 = false;
        Target32_a9dbb8* source = message->Fn32();
        if (source != 0) {
            Transform_a9dbb8 transform;
            transform.mCount = 0;
            transform.mFlags = 0;
            for (int32_t i = 0; i < 9; ++i) {
                transform.mMatrix.m[i] = (i % 4 == 0) ? 1.0f : 0.0f;
            }
            transform.mPos[0] = 0.0f;
            transform.mPos[1] = 0.0f;
            transform.mPos[2] = 0.0f;
            transform.mScale = 1.0f;
            source->Fn15(&transform);
            if (transform.mFlags & 1) {
                Vec3_a9dbb8 where = { transform.mPos[0], transform.mPos[1], transform.mPos[2] };
                WatercraftMgr_a9dbb8* manager = gpB43cec_a9dbb8->Fn46();
                if (manager != 0) {
                    BoatObj_a9dbb8* other = static_cast<BoatObj_a9dbb8*>(manager->LookForBoatsAtPosition(where, reinterpret_cast<Boat_a9dbb8*>(boatSelf)));
                    if (other != 0 && other != reinterpret_cast<BoatObj_a9dbb8*>(boatSelf)) {
                        if (other->Fn05()->Fn22(0x4417)) {
                            cSC4Watercraft* otherBoat = reinterpret_cast<cSC4Watercraft*>(other);
                            if (otherBoat->GetBehavior() != 0x46 && otherBoat->GetBehavior() != 0x47 && otherBoat->GetBehavior() != 0x49 && otherBoat->GetBehavior() != 0x48) {
                                SmartSlot_a9dbb8* mine = reinterpret_cast<SmartSlot_a9dbb8*>(&boatSelf->mpObj280);
                                mine->Assign(otherBoat);
                                reinterpret_cast<SmartSlot_a9dbb8*>(&static_cast<cSC4Watercraft*>(mine->mp)->mpObj284)->Assign(boatSelf);
                                cSC4Watercraft* partner = static_cast<cSC4Watercraft*>(mine->mp);
                                if (partner->GetBehavior() == 0x4a || partner->GetBehavior() == 0x4b || partner->GetBehavior() == 0x4c) {
                                    partner->PopState();
                                }
                                partner->PushState(0x4d, 0, -1.0f, 0, 0, 0, 0);
                                Unknown_a9dbb8* held = static_cast<Unknown_a9dbb8*>(boatSelf->mpObj284);
                                if (held != 0) {
                                    boatSelf->mpObj284 = 0;
                                    held->Release();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (!reinterpret_cast<View38_a9dbb8*>(this)->Fn00507cd0(pMessage) && !handled) {
        return 0;
    }
    return 1;
}
#endif


// ---- batch 27 ----

struct Obj4_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual void Pad03();
    virtual void Fn04(uint32_t);
};

// The tow partner: its PushState is slot 52 (0xd0).
struct StateRunner_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
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
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual bool Fn52(uint32_t, void*, float, uint32_t, uint32_t, uint32_t, void*);
};

inline void ClearSlot_a9dbb8(void** slot)
{
    Unknown_a9dbb8* held = static_cast<Unknown_a9dbb8*>(*slot);
    if (held != 0) {
        *slot = 0;
        held->Release();
    }
}

inline void ShutdownSlot_a9dbb8(void** slot)
{
    Obj4_a9dbb8* held = static_cast<Obj4_a9dbb8*>(*slot);
    if (held != 0) {
        held->Fn04(1);
        ClearSlot_a9dbb8(slot);
    }
}

// FUNCTION: 0x0056d0e0
void cSC4Watercraft::Slot04_a9dbb8()
{
    cSC4Watercraft_4* sub = reinterpret_cast<cSC4Watercraft_4*>(reinterpret_cast<char*>(this) + 4);
    if (static_cast<uint8_t>(sub->Slot05_a9dbb8_4()) != 0) {
        StateRunner_a9dbb8* partner = static_cast<StateRunner_a9dbb8*>(mpObj280);
        if (partner != 0) {
            partner->Fn52(0x49, 0, -1.0f, 0, 0, 0, 0);
            ClearSlot_a9dbb8(&mpObj280);
        }
        ClearSlot_a9dbb8(&mpObj284);
        WatercraftMgr_a9dbb8* manager = gpB43cec_a9dbb8->Fn46();
        if (manager != 0) {
            if (mb215) {
                manager->Fn0056d060(mpLot1e4, this);
                manager->DoneDocking(mpLot1e4, this);
            }
            if (mb249) {
                manager->Fn0056d060(mpLot218, this);
                manager->DoneDocking(mpLot218, this);
            }
        }
        if (gpB43ccc != 0) {
            gpB43ccc->RemoveNotification(reinterpret_cast<char*>(this) + 0x38, 0xac400a31);
        }
        mb215 = false;
        ClearSlot_a9dbb8(&mpLot1e4);
        mb249 = false;
        ClearSlot_a9dbb8(&mpLot218);
        mb27d = false;
        ClearSlot_a9dbb8(&mpLot24c);
        ClearSlot_a9dbb8(&mp318);
        ShutdownSlot_a9dbb8(&mpObjDb0);
        ShutdownSlot_a9dbb8(&mpObjDb4);
        ShutdownSlot_a9dbb8(&mpObjDb8);
        ShutdownSlot_a9dbb8(&mpObjDbc);
        ShutdownSlot_a9dbb8(&mpObjDc0);
        ShutdownSlot_a9dbb8(&mpObjDc4);
    }
    Fn0050ba50();
}


// ---- batch 28 ----

struct BoxSource_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn08(void*);
};

// What the first model reports about itself (slot 8 of the primary vtable): a box, of which the depth is used.
struct ModelBox_a9dbb8 {
    float mf0;
    float mf4;
    float mf8;
    float mfc;
    float mf10;
    float mf14;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050e8b0 score 141
bool cSC4Watercraft::LoadModels()
{
    WordVec_a9dbb8* models = reinterpret_cast<WordVec_a9dbb8*>(&mpModelsBegin);
    bool loadedAny = false;
    ModelInst_a9dbb8* model = 0;
    if (models->mpBegin == models->mpEnd) {
        KeyVec_a9dbb8* keys = reinterpret_cast<KeyVec_a9dbb8*>(&mpPathBegin);
        if (keys->mpBegin == keys->mpEnd && mnAnimKeyInstance != 0) {
            keys->Fn0050da30(&mnAnimKeyType);
        }
        for (Key_a9dbb8* key = static_cast<Key_a9dbb8*>(keys->mpBegin); key != static_cast<Key_a9dbb8*>(mpPathEnd); ++key) {
            Key_a9dbb8 current = *key;
            if (!Fn007fede0(&current, &model)) {
                return false;
            }
            if (models->mpEnd != models->mpCap) {
                if (models->mpEnd != 0) {
                    *reinterpret_cast<ModelInst_a9dbb8**>(models->mpEnd) = model;
                }
                models->mpEnd = models->mpEnd + 1;
            } else {
                models->Fn0051ca60(models->mpEnd, reinterpret_cast<uint32_t*>(&model), 1, 1);
            }
            ModelInst_a9dbb8* inner = static_cast<ModelInst_a9dbb8*>(model->Fn00());
            if (key == static_cast<Key_a9dbb8*>(mpPathBegin)) {
                ModelBox_a9dbb8 box = { 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f };
                mfLength = (box.mfc - box.mf4) * 0.5f;
                if (!(mfLength <= 32.0f)) {
                    mfLength = 32.0f;
                }
            }
            model->Fn18(1, 0.0f);
            PositionModelInstance(inner);
            Anim_a9dbb8* anim = reinterpret_cast<Anim_a9dbb8*>(inner);
            anim->Fn04(Sub4Of_a9dbb8(this));
            anim->Fn14(3);
            int32_t zoom;
            int32_t rotation;
            gpB43dd8->GetZoomAndRotation(&zoom, &rotation);
            model->Fn08(zoom, rotation);
            loadedAny = true;
        }
        WordVec_a9dbb8 ids = { 0, 0, 0 };
        if (Fn005ff510(Slot06_a9dbb8_4(), 0xcc21420d, &ids) && ids.mpBegin != ids.mpEnd) {
            for (uint32_t* id = ids.mpBegin; id != ids.mpEnd; ++id) {
                if (*id > 0 && *id < 4) {
                    ModelInst_a9dbb8* aux = 0;
                    LoadAuxiliaryModel(*id, &aux);
                    if (aux != 0) {
                        ModelVBase_a9dbb8* base = aux;
                        base->Release();
                    }
                }
            }
        }
        if (ids.mpBegin != 0) {
            Fn0090cf63(ids.mpBegin);
        }
    }
    UpdateOpacity(0.0f);
    InitLighting();
    return loadedAny;
}
#endif


// ---- batch 29 ----

struct GhostProbe_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
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
    virtual bool Fn13();
};

struct VehMgrQ_a9dbb8 {
    virtual bool Fn00(uint32_t iid, void* pOut);
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
    virtual bool Fn13();
};

// The state the ghost compares against: its cell at +0x26c / +0x270.
struct CellState_a9dbb8 {
    uint8_t mPad[0x26c];
    int32_t mnCellA;
    int32_t mnCellB;
};

// The object the global at 0xb21d74 points to: the boat being placed sits at +0x30.
struct Placing_a9dbb8 {
    uint8_t mPad[0x30];
    cSC4Watercraft* mpBoat;
};

// GLOBAL: 0x00b09968
extern uint8_t gbB09968;

// GLOBAL: 0x00b21d74
extern Placing_a9dbb8* gpB21d74;

// GLOBAL: 0x00b43ddc
extern void* gpLighting_a9dbb8;

#ifdef OB_DRAFTS
// CLOSE: 0x0050afd0 score 243
void cSC4Watercraft::UpdateGhostModel()
{
    cSC4Watercraft_4* sub = reinterpret_cast<cSC4Watercraft_4*>(reinterpret_cast<char*>(this) + 4);
    if (sub->Slot07_a9dbb8_4() == 0x496e5783 && sub->Slot07_a9dbb8_4() == 0x897f7ec2) {
        return;
    }
    if (gbB09968 == 0) {
        ShutdownGhostModel();
        return;
    }
    bool match = false;
    VehMgrQ_a9dbb8* manager = reinterpret_cast<VehMgrQ_a9dbb8*>(gpB43d44);
    if (manager->Fn13()) {
        if (mpGhost == 0 && mpModelsBegin != mpModelsEnd) {
            GhostProbe_a9dbb8* probe = 0;
            manager->Fn00(0x098f9bf4, &probe);
            if (probe != 0) {
                if (gpB21d74 != 0) {
                    if (probe->Fn13()) {
                        if (gpB21d74->mpBoat != 0) {
                            CellState_a9dbb8* other = static_cast<CellState_a9dbb8*>(gpB21d74->mpBoat->FindState(0x10));
                            if (other != 0) {
                                int32_t cellA;
                                int32_t cellB;
                                gpB43d0c->Fn17(mfPosX, mfPosZ, &cellA, &cellB);
                                if (other->mnCellA == cellA && other->mnCellB == cellB) {
                                    match = true;
                                }
                            }
                        }
                    }
                }
                probe->Release();
            }
            if (match) {
                if (mpGhost == 0) {
                    InitGhostModel();
                    return;
                }
            }
        }
    }
    if (mpGhost != 0 && mpModelsBegin != mpModelsEnd) {
        ModelInst_a9dbb8* model = static_cast<ModelInst_a9dbb8*>(*mpModelsBegin);
        Transform_a9dbb8 transform;
        transform.mCount = 0;
        transform.mFlags = 0;
        for (int32_t i = 0; i < 9; ++i) {
            transform.mMatrix.m[i] = (i % 4 == 0) ? 1.0f : 0.0f;
        }
        transform.mPos[0] = 0.0f;
        transform.mPos[1] = 0.0f;
        transform.mPos[2] = 0.0f;
        transform.mScale = 1.0f;
        ModelVBase_a9dbb8* base = model;
        base->Fn09(&transform);
        ModelBox_a9dbb8 box;
        reinterpret_cast<BoxSource_a9dbb8*>(model->Fn00())->Fn08(&box);
        float shift = (box.mf10 - box.mf4) * 1.5f;
        transform.mPos[0] = transform.mPos[0] - shift * gpB43dd8->mnZoom;
        ModelVBase_a9dbb8* ghostBase = static_cast<ModelInst_a9dbb8*>(mpGhost);
        ghostBase->Fn10(&transform);
        gpB43dd0->Fn30(static_cast<ModelInst_a9dbb8*>(mpGhost)->Fn00());
        if (mpLight0xd0 != 0) {
            reinterpret_cast<Light_a9dbb8*>(&mpLight0xd0)->Fn00803e10(gpLighting_a9dbb8, 0);
        }
    }
}
#endif


// ---- batch 30 ----

struct RegTarget_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual uint32_t Fn09(void*);
};

// STUB: 0x0068c180
void Fn0068c180(void* self, const char* name, void* system, uint32_t a, uint32_t b, void* registry);

// STUB: 0x00524970
void Fn00524970(void* field, const char* name, void* callback, void* self, uint32_t flags, uint32_t zero, void* registry);

// STUB: 0x0058de80
void Fn0058de80(uint32_t zero, const char* name, void* callback, void* self, uint32_t zero2, void* self2, void* registry);

// STUB: 0x00505210
void Fn00505210();

// STUB: 0x00509a50
void Fn00509a50();

// STUB: 0x00509ab0
void Fn00509ab0();

// STUB: 0x00509b10
void Fn00509b10();

// STUB: 0x0050d910
void Fn0050d910();

// STUB: 0x00509bd0
void Fn00509bd0();

// STUB: 0x00509c40
void Fn00509c40();

inline void AcquireRegistry_a9dbb8(SmartHolder_a9dbb8* holder)
{
    holder->mp = 0;
    Registry_a9dbb8* registry = Fn008793ec();
    if (registry != 0) {
        registry->Fn05(0xebe0e860, 0xe898ed03, &holder->mp);
    }
}

// FUNCTION: 0x0050ec10
void cSC4Watercraft::RegisterInGameDataRegistry()
{
    void* self5 = Slot05_a9dbb8();
    ScriptSys_a9dbb8* system = gpB43cec_a9dbb8->Fn48();
    SmartHolder_a9dbb8 holder;
    AcquireRegistry_a9dbb8(&holder);
    RegTarget_a9dbb8* target = static_cast<RegTarget_a9dbb8*>(holder.mp);
    holder.Fn00424e70();
    if (target->Fn09(self5)) {
        return;
    }
    AcquireRegistry_a9dbb8(&holder);
    Fn0068c180(self5, "", system, 0, 0, holder.mp);
    holder.Fn00424e70();
    AcquireRegistry_a9dbb8(&holder);
    Fn00524970(&mfPosX, "x", reinterpret_cast<void*>(&Fn00505210), this, 2, 0, holder.mp);
    holder.Fn00424e70();
    AcquireRegistry_a9dbb8(&holder);
    Fn00524970(&mfPosY, "y", reinterpret_cast<void*>(&Fn00505210), this, 2, 0, holder.mp);
    holder.Fn00424e70();
    AcquireRegistry_a9dbb8(&holder);
    Fn00524970(&mfPosZ, "z", reinterpret_cast<void*>(&Fn00505210), this, 2, 0, holder.mp);
    holder.Fn00424e70();
    AcquireRegistry_a9dbb8(&holder);
    Fn0058de80(0, "fade_out", reinterpret_cast<void*>(&Fn00509a50), self5, 0, self5, holder.mp);
    holder.Fn00424e70();
    AcquireRegistry_a9dbb8(&holder);
    Fn0058de80(0, "remove", reinterpret_cast<void*>(&Fn00509ab0), self5, 0, self5, holder.mp);
    holder.Fn00424e70();
    AcquireRegistry_a9dbb8(&holder);
    Fn0058de80(0, "attach_anim", reinterpret_cast<void*>(&Fn00509b10), self5, 0, self5, holder.mp);
    holder.Fn00424e70();
    AcquireRegistry_a9dbb8(&holder);
    Fn0058de80(0, "play_anim", reinterpret_cast<void*>(&Fn0050d910), self5, 0, self5, holder.mp);
    holder.Fn00424e70();
    AcquireRegistry_a9dbb8(&holder);
    Fn0058de80(0, "play_sfx", reinterpret_cast<void*>(&Fn00509bd0), self5, 0, self5, holder.mp);
    holder.Fn00424e70();
    AcquireRegistry_a9dbb8(&holder);
    Fn0058de80(0, "push_state", reinterpret_cast<void*>(&Fn00509c40), self5, 0, self5, holder.mp);
    holder.Fn00424e70();
}



// ---- batch 31 ----

struct LotMgr_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void* Fn06(int32_t, int32_t, int32_t);
};

// GLOBAL: 0x00b43d08
extern LotMgr_a9dbb8* gpB43d08;

// The static debug text (a cRZString at 0xb22760, its std::string part at 0xb22764); string members are out of line.
struct DbgString_a9dbb8 {
    // STUB: 0x0040ebc0
    void* Append(const char* first, const char* last, const uint8_t* tag);
    // STUB: 0x00410f00
    void* AppendText(const char* text);
    // STUB: 0x00408a70
    void* Assign(const void* first, const void* last, const uint8_t* tag);
};

// A temporary string built from a character range.
struct TempString_a9dbb8 {
    void* mpBegin;
    void* mpEnd;
    void* mpCap;
    // STUB: 0x00407fa0
    void Build(const char* first, const char* last, const uint8_t* tag);
};

// GLOBAL: 0x00b22764
extern DbgString_a9dbb8 gDbgString_a9dbb8;

// GLOBAL: 0x00b22760
extern uint8_t gDbgText_a9dbb8[];

#ifdef OB_DRAFTS
// CLOSE: 0x00511a90 score 183
void* cSC4Watercraft::GetDebugFlagsText()
{
    uint8_t tag;
    TempString_a9dbb8 temp = { 0, 0, 0 };
    temp.Build("", "", &tag);
    gDbgString_a9dbb8.Assign(temp.mpBegin, temp.mpEnd, &tag);
    if (temp.mpBegin != 0) {
        Fn0090cf63(temp.mpBegin);
    }
    if (CheckAutomataFlag(0x1)) {
        const char* text = " (remove)";
        gDbgString_a9dbb8.Append(text, text + 9, &tag);
    }
    if (CheckAutomataFlag(0x2)) {
        const char* text = " (self control)";
        gDbgString_a9dbb8.Append(text, text + 15, &tag);
    }
    if (CheckAutomataFlag(0x4)) {
        const char* text = " (reached dest)";
        gDbgString_a9dbb8.Append(text, text + 15, &tag);
    }
    if (CheckAutomataFlag(0x8)) {
        const char* text = " (collide)";
        gDbgString_a9dbb8.Append(text, text + 10, &tag);
    }
    if (CheckAutomataFlag(0x10)) {
        const char* text = " (stop light)";
        gDbgString_a9dbb8.Append(text, text + 13, &tag);
    }
    if (CheckAutomataFlag(0x20)) {
        const char* text = " (stopped)";
        gDbgString_a9dbb8.Append(text, text + 10, &tag);
    }
    if (CheckAutomataFlag(0x40)) {
        const char* text = " (special route)";
        gDbgString_a9dbb8.Append(text, text + 16, &tag);
    }
    if (CheckAutomataFlag(0x80)) {
        const char* text = " (Emergency!)";
        gDbgString_a9dbb8.Append(text, text + 13, &tag);
    }
    if (CheckAutomataFlag(0x100)) {
        const char* text = " (idle)";
        gDbgString_a9dbb8.Append(text, text + 7, &tag);
    }
    if (CheckAutomataFlag(0x200)) {
        const char* text = " (repathing)";
        gDbgString_a9dbb8.Append(text, text + 12, &tag);
    }
    if (CheckAutomataFlag(0x400)) {
        const char* text = " (teleporting)";
        gDbgString_a9dbb8.Append(text, text + 14, &tag);
    }
    if (CheckAutomataFlag(0x800)) {
        const char* text = " (ignore lights)";
        gDbgString_a9dbb8.Append(text, text + 16, &tag);
    }
    if (CheckAutomataFlag(0x1000)) {
        const char* text = " (ignore speed limit)";
        gDbgString_a9dbb8.Append(text, text + 21, &tag);
    }
    if (CheckAutomataFlag(0x2000)) {
        const char* text = " (ignore paths)";
        gDbgString_a9dbb8.Append(text, text + 15, &tag);
    }
    if (CheckAutomataFlag(0x4000)) {
        const char* text = " (ignore attractors)";
        gDbgString_a9dbb8.Append(text, text + 20, &tag);
    }
    if (CheckAutomataFlag(0x20000)) {
        const char* text = " (ignore roads)";
        gDbgString_a9dbb8.Append(text, text + 15, &tag);
    }
    if (CheckAutomataFlag(0x400000)) {
        const char* text = " (avoid lots)";
        gDbgString_a9dbb8.Append(text, text + 13, &tag);
    }
    if (CheckAutomataFlag(0x800000)) {
        const char* text = " (avoid roads)";
        gDbgString_a9dbb8.Append(text, text + 14, &tag);
    }
    if (gpB43d08 != 0) {
        int32_t cellX = CellOf_a9dbb8(mfPosX * 0.0625f);
        int32_t cellZ = CellOf_a9dbb8(mfPosZ * 0.0625f);
        if (cellX >= 0 && cellZ >= 0 && cellX < gpB43cec_a9dbb8->Fn93() && cellZ < gpB43cec_a9dbb8->Fn94()) {
            if (gpB43d08->Fn06(cellX, cellZ, 0) != 0) {
                gDbgString_a9dbb8.AppendText(" [ON LOT]");
            }
        }
    }
    return gDbgText_a9dbb8;
}
#endif


// ---- batch 32 ----

struct SoundObj_a9dbb8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Fn03(uint32_t);
    virtual void Pad04();
    virtual bool Fn05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn08(void*);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00570270 score 137
void cSC4Watercraft::Fn00570270(float dt)
{
    if (Fn005681b0()) {
        PushState(0x48, 0, -1.0f, 0, 0, 0, 0);
        return;
    }
    Transform_a9dbb8 transform;
    transform.mCount = 0;
    transform.mFlags = 0;
    for (int32_t i = 0; i < 9; ++i) {
        transform.mMatrix.m[i] = (i % 4 == 0) ? 1.0f : 0.0f;
    }
    transform.mPos[0] = 0.0f;
    transform.mPos[1] = 0.0f;
    transform.mPos[2] = 0.0f;
    transform.mScale = 1.0f;
    switch (GetBehavior()) {
    case 0x46: {
        mf2c0 = dt + mf2c0;
        Fn0056efe0();
        Ramp_a9dbb8* ramp = reinterpret_cast<Ramp_a9dbb8*>(reinterpret_cast<char*>(this) + 0x1a0);
        if (ramp->mfTo != 0.0f) {
            ramp->mfFrom = ramp->Fn004fa960();
            ramp->mfTo = 0.0f;
            ramp->mfB = 0.0f;
            ramp->mnC = 0;
        }
        Remove(&transform);
        SoundObj_a9dbb8* sound = static_cast<SoundObj_a9dbb8*>(mpObjDb4);
        if (sound != 0 && !sound->Fn05()) {
            sound->Fn08(&transform);
            static_cast<SoundObj_a9dbb8*>(mpObjDb4)->Fn03(0);
        } else {
            static_cast<SoundObj_a9dbb8*>(mpObjDb4)->Fn08(&transform);
        }
        Fn0056af90(dt);
        break;
    }
    case 0x47: {
        mf2c0 = dt + mf2c0;
        Fn0056efe0();
        Ramp_a9dbb8* ramp = reinterpret_cast<Ramp_a9dbb8*>(reinterpret_cast<char*>(this) + 0x1a0);
        if (ramp->mfTo != 0.0f) {
            ramp->mfFrom = ramp->Fn004fa960();
            ramp->mfTo = 0.0f;
            ramp->mfB = 0.0f;
            ramp->mnC = 0;
        }
        if (mb2b2) {
            Remove(&transform);
            SoundObj_a9dbb8* sound = static_cast<SoundObj_a9dbb8*>(mpObjDb0);
            if (sound != 0 && !sound->Fn05()) {
                sound->Fn08(&transform);
                static_cast<SoundObj_a9dbb8*>(mpObjDb0)->Fn03(0);
            } else {
                static_cast<SoundObj_a9dbb8*>(mpObjDb0)->Fn08(&transform);
            }
        }
        Remove(&transform);
        SoundObj_a9dbb8* sound = static_cast<SoundObj_a9dbb8*>(mpObjDb8);
        if (sound != 0 && !sound->Fn05()) {
            sound->Fn08(&transform);
            static_cast<SoundObj_a9dbb8*>(mpObjDb8)->Fn03(0);
        }
        Fn0056a440();
        break;
    }
    default:
        break;
    }
}
#endif

// ==== helpers: defined last so they stay out-of-line like the original's separate units ====
#ifdef _MSC_VER
#pragma auto_inline(off)
#endif

// FUNCTION: 0x0051c4a0
int32_t cOccupantGroup_a9dbb8::GetGroupHierarchyDepth()
{
    int32_t depth = 0;
    for (cOccupantGroup_a9dbb8* g = this; g != 0; g = g->mpParent) {
        depth = depth + 1;
    }
    return depth;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00505300 score 14
float cOccupantGroup_a9dbb8::Fn00505300()
{
    cOccupantGroup_a9dbb8* group = this;
    for (;;) {
        if (group->mf5c > 0.0f) {
            return group->mf5c;
        }
        group = group->mpParent;
        if (group == 0) {
            return 0.0f;
        }
    }
}
#endif

// FUNCTION: 0x00514c70
float BehaviorTemplate_a9dbb8::Fn00514c70()
{
    if (mf28 > 0.0f) {
        return mf28 * 1000.0f;
    }
    return -1.0f;
}

// FUNCTION: 0x00566e00
float OB_STDCALL Fn00566e00(float value)
{
    if (value < 0.0f) {
        return -1.0f;
    }
    return 1.0f;
}

// FUNCTION: 0x005ebdf0
void** Fn005ebdf0(uint32_t)
{
    void** node = gB0a8c8.mpBlock->mpFree;
    if (node == 0) {
        node = gB0a8c8.Refill();
    }
    gB0a8c8.mpBlock->mpFree = static_cast<void**>(*node);
    gB0a8c8.mpBlock->mnCount = gB0a8c8.mpBlock->mnCount + 1;
    return node;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0051d970 score 14
bool GroupMgr_a9dbb8::Fn0051d970(Str_a9dbb8* name, uint32_t* pOut)
{
    bool found = false;
    GroupNode_a9dbb8* node = mTable.Find(name);
    if (node != 0) {
        *pOut = node->mnValue;
        return true;
    }
    return found;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0050bbe0 score 45
HNode_a9dbb8* HIter_a9dbb8::Fn0050bbe0()
{
    HTable_a9dbb8* table = mpTable;
    uint32_t size = table->mpEnd - table->mpBegin;
    uint32_t index = mpCur->mnKey % size;
    size = table->mpEnd - table->mpBegin;
    HNode_a9dbb8* result = 0;
    for (++index; index < size; ++index) {
        result = mpTable->mpBegin[index];
        if (result != 0) {
            break;
        }
    }
    return result;
}
#endif

// FUNCTION: 0x00567e80
void cSC4Watercraft::Fn00567e80()
{
    Releasable53_a9dbb8* a = static_cast<Releasable53_a9dbb8*>(mpObj280);
    if (a != 0) {
        a->Fn53();
    }
    a = static_cast<Releasable53_a9dbb8*>(mpObj280);
    if (a != 0) {
        mpObj280 = 0;
        a->Release();
    }
    Releasable53_a9dbb8* b = static_cast<Releasable53_a9dbb8*>(mpObj284);
    if (b != 0) {
        mpObj284 = 0;
        b->Release();
    }
}
