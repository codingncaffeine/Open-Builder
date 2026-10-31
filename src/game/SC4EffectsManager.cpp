#include "classes/cSC4EffectsManager.h"
#include "game/Globals.h"
#include <new>
#include <string.h>
#include <ctype.h>

// The original's STL delete (operator delete wrapper).
// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// A reference counted object as the effect containers hold it: AddRef at slot 1 (+4), Release at slot 8 (+0x20).
struct Unknown_a9f0d8 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Release();
};

// The same kind of object with AddRef at slot 7 (+0x1c) and Release at slot 8 (+0x20).
struct Effect_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void AddRef();
    virtual void Release();
    uint8_t mPad04[0x20];
    uint32_t mnFlags;
};

// The effects the manager indexes: slot 8 takes the address of the block at +0x6c.
struct IndexedEffect_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void SetState(uint32_t n);
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Notify(void* p);
    uint32_t mnPad04;
    uint32_t mnState;
    uint8_t mPad0c[0x1c];
    uint32_t mnFlags;
    uint8_t mPad2c[0x40];
    uint8_t mBlock[4];
};

struct EffectSmartPtr_a9f0d8 {
    Effect_a9f0d8* mpObj;

    EffectSmartPtr_a9f0d8* Assign(Effect_a9f0d8* p);
};

struct PtrVector_a9f0d8 {
    Effect_a9f0d8** mpBegin;
    Effect_a9f0d8** mpEnd;
    Effect_a9f0d8** mpCap;

    void Destroy();
    void Fn0058ff70(Effect_a9f0d8** pos, Effect_a9f0d8* const* x, uint32_t tag, uint32_t n, bool atEnd);
};

struct Record44_a9f0d8 {
    uint8_t mPad[0x38];
    Effect_a9f0d8* mpObj;
    uint8_t mPad3c[0x8];
};

struct RecordVector_a9f0d8 {
    Record44_a9f0d8* mpBegin;
    Record44_a9f0d8* mpEnd;
    Record44_a9f0d8* mpCap;

    void Destroy();
};

struct Pair_a9f0d8 {
    float mfKey;
    void* mpValue;
};

// FUNCTION: 0x0058d840
uint32_t cSC4EffectsManager::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x0058d850
void cSC4EffectsManager::FinalRelease()
{
    Slot04_a9f0d8();
    delete this;
}

// FUNCTION: 0x0058d8d0
EffectSmartPtr_a9f0d8* EffectSmartPtr_a9f0d8::Assign(Effect_a9f0d8* p)
{
    Effect_a9f0d8* old = mpObj;
    if (p != old) {
        if (p) {
            p->AddRef();
        }
        mpObj = p;
        if (old) {
            old->Release();
        }
    }
    return this;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0058df60 score 22
Unknown_a9f0d8** Fn0058df60(Unknown_a9f0d8** dst, uint32_t n, Unknown_a9f0d8* const* src, void* tag)
{
    if (n > 0) {
        do {
            if (dst) {
                *dst = *src;
                if (*dst) {
                    (*dst)->AddRef();
                }
            }
            ++dst;
            --n;
        } while (n != 0);
    }
    return dst;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0058dfa0 score 22
Effect_a9f0d8** Fn0058dfa0(Effect_a9f0d8** dst, uint32_t n, Effect_a9f0d8* const* src, void* tag)
{
    if (n > 0) {
        do {
            if (dst) {
                *dst = *src;
                if (*dst) {
                    (*dst)->AddRef();
                }
            }
            ++dst;
            --n;
        } while (n != 0);
    }
    return dst;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0058dfe0 score 6
Effect_a9f0d8** Fn0058dfe0(Effect_a9f0d8** first, Effect_a9f0d8** last, Effect_a9f0d8** dst, void* tag)
{
    while (first != last) {
        if (dst) {
            *dst = *first;
            if (*dst) {
                (*dst)->AddRef();
            }
        }
        ++first;
        ++dst;
    }
    return dst;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0058d900 score 12
void Fn0058d900(Pair_a9f0d8* last, Pair_a9f0d8 val)
{
    Pair_a9f0d8* prev = last - 1;
    while (val.mfKey < prev->mfKey) {
        *last = *prev;
        last = prev;
        --prev;
    }
    *last = val;
}
#endif

// FUNCTION: 0x0058f940
void PtrVector_a9f0d8::Destroy()
{
    Effect_a9f0d8** it = mpBegin;
    Effect_a9f0d8** end = mpEnd;
    for (; it != end; ++it) {
        if (*it) {
            (*it)->Release();
        }
    }
    if (mpBegin) {
        Fn0090cf63(mpBegin);
    }
}

// FUNCTION: 0x00590040
void RecordVector_a9f0d8::Destroy()
{
    Record44_a9f0d8* it = mpBegin;
    Record44_a9f0d8* end = mpEnd;
    for (; it != end; ++it) {
        Effect_a9f0d8* p = it->mpObj;
        if (p) {
            p->Release();
        }
    }
    if (mpBegin) {
        Fn0090cf63(mpBegin);
    }
}

// FUNCTION: 0x0058e4a0
void cSC4EffectsManager::Fn0058e4a0()
{
    for (uint32_t* it = mpActiveBegin; it != mpActiveEnd; ++it) {
        IndexedEffect_a9f0d8* e = reinterpret_cast<IndexedEffect_a9f0d8**>(mpEffects)[*it];
        if (e->mnFlags & 1) {
            e->Notify(e->mBlock);
        }
    }
}

// Library and framework pieces the next functions call.
struct Str_a9f0d8 {
    char* mpBegin;
    char* mpEnd;
    char* mpCap;
    // STUB: 0x0044d3a0
    Str_a9f0d8* Assign(const char* first, const char* last);
};

// std::transform for characters.
// STUB: 0x00586ac0
char* Transform_a9f0d8(char* first, char* last, char* result, int (*op)(int));

struct NameTable_a9f0d8 {
    // STUB: 0x0051c9f0
    void* Find(const Str_a9f0d8* key);
};

struct VecFloat_a9f0d8 {
    float* mpBegin;
    float* mpEnd;
    float* mpCap;
    // STUB: 0x00464430
    VecFloat_a9f0d8* Assign(const VecFloat_a9f0d8* other);
};

struct LightDesc_a9f0d8 {
    uint8_t mHead[0xc];
    VecFloat_a9f0d8 mValues;
    float mfTime;
    // STUB: 0x0050c540
    void Copy(const LightDesc_a9f0d8* other);
};

struct Vec2_a9f0d8 {
    float mfX;
    float mfY;
};

struct Vec3_a9f0d8 {
    float mfX;
    float mfY;
    float mfZ;
};

struct TerrainMap_a9f0d8 {
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
    virtual float GetHeight(float x, float y);
};

// GLOBAL: 0x00b43cf8
extern TerrainMap_a9f0d8* gpB43cf8_a9f0d8;

struct SnowSource_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual int32_t Create(uint32_t id);
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Destroy(int32_t id);
};

struct TerrainView_a9f0d8 {
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
    virtual SnowSource_a9f0d8* GetSource(uint32_t n);
};

// STUB: 0x00602160
TerrainView_a9f0d8* Fn00602160();

// The packed render state the manager keeps twice at +0xd5c and +0xd64.
struct PackedState_a9f0d8 {
    // STUB: 0x007d2b50
    void Pack(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, uint32_t a7, uint32_t a8,
        uint32_t a9, uint32_t a10, uint32_t a11, float a12, uint32_t a13, uint32_t a14);
};

struct Record44Copy_a9f0d8 {
    uint8_t mnGeneration;
    uint8_t mb01;
    uint16_t mnPad02;
    uint32_t mnW04;
    uint32_t mnW08;
    uint32_t mnW0c;
    uint32_t mnW10;
    uint32_t mnW14;
    uint32_t mnW18;
    uint32_t mnW1c;
    uint32_t mnW20;
    uint32_t mnW24;
    uint32_t mnW28;
    uint32_t mnW2c;
    uint32_t mnW30;
    uint32_t mnW34;
    Effect_a9f0d8* mpObj;
    uint32_t mnW3c;
    uint32_t mnW40;
    Record44Copy_a9f0d8* Fn0058dba0(const Record44Copy_a9f0d8* other);
};

// The interface the QueryInterface/slot-7 pair below works on.
struct Source_a9f0d8 {
    virtual bool QueryInterface(uint32_t id, void** out);
};
struct Sink_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual bool Accept(void* p);
};
struct Held_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058e120 score 34
Record44Copy_a9f0d8* Fn0058e120(Record44Copy_a9f0d8* first, Record44Copy_a9f0d8* last, Record44Copy_a9f0d8* dst)
{
    int32_t n = last - first;
    if (n > 0) {
        do {
            dst->Fn0058dba0(first);
            ++first;
            ++dst;
            --n;
        } while (n != 0);
        return dst;
    }
    return dst;
}
#endif

// FUNCTION: 0x0058df10
bool Fn0058df10(Source_a9f0d8* a, Sink_a9f0d8* b)
{
    if (b && a) {
        Held_a9f0d8* held = 0;
        a->QueryInterface(1, reinterpret_cast<void**>(&held));
        bool ok = b->Accept(held);
        if (held) {
            held->Release();
        }
        return ok;
    }
    return false;
}

// FUNCTION: 0x0058fe70
void cSC4EffectsManager::Fn0058fe70(void* p)
{
    const LightDesc_a9f0d8* src = static_cast<const LightDesc_a9f0d8*>(p);
    LightDesc_a9f0d8* dst = reinterpret_cast<LightDesc_a9f0d8*>(mLightB);
    dst->Copy(src);
    dst->mValues.Assign(&src->mValues);
    dst->mfTime = src->mfTime;
    mnLightB88 = 0;
    mfLightBInv = 1.0f / mfLightBTime;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0058de30 score 32
void OB_STDCALL Fn0058de30(Vec3_a9f0d8* out, const Vec2_a9f0d8* in)
{
    float x = in->mfX;
    float y = in->mfY;
    float h = gpB43cf8_a9f0d8->GetHeight(x, y);
    out->mfX = x;
    out->mfY = h;
    out->mfZ = y;
}
#endif

// FUNCTION: 0x0058dce0
void cSC4EffectsManager::Fn0058dce0()
{
    mnC94 = 0;
    mbFlag1b4 = 1;
    for (uint32_t* it = mpActiveBegin; it != mpActiveEnd; ++it) {
        IndexedEffect_a9f0d8* e = reinterpret_cast<IndexedEffect_a9f0d8**>(mpEffects)[*it];
        if (e->mnState == 1) {
            e->SetState(1);
        }
    }
}

// FUNCTION: 0x00593b90
void cSC4EffectsManager::Fn00593b90()
{
    if (mbActive) {
        for (uint32_t* it = mpActiveBegin; it != mpActiveEnd; ++it) {
            Fn005919d0(reinterpret_cast<void**>(mpEffects)[*it], 0);
        }
        Fn005921b0();
    }
}

// FUNCTION: 0x0058d870
void cSC4EffectsManager::Fn0058d870()
{
    reinterpret_cast<PackedState_a9f0d8*>(mPackedA)->Pack(1, 0, 0, 0, 1, 0, 0, 0xffffffff, 4, 1, 0xffffffff, -1.0f, 0xffffffff, 0xffffffff);
    reinterpret_cast<PackedState_a9f0d8*>(mPackedB)->Pack(1, 0, 0, 0, 1, 0, 0, 0xffffffff, 8, 5, 0xffffffff, -1.0f, 0xffffffff, 0xffffffff);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0058e170 score 56
void Fn0058e170(Pair_a9f0d8* first, Pair_a9f0d8* last)
{
    for (Pair_a9f0d8* i = first; i != last; ++i) {
        Pair_a9f0d8 val = *i;
        Pair_a9f0d8* hole = i;
        Pair_a9f0d8* prev = i - 1;
        while (val.mfKey < prev->mfKey) {
            *hole = *prev;
            hole = prev;
            --prev;
        }
        *hole = val;
    }
}
#endif

// FUNCTION: 0x0058d940
void Fn0058d940(Pair_a9f0d8* first, int32_t hole, int32_t top, Pair_a9f0d8 val, uint32_t /*extra*/)
{
    int32_t parent = (hole - 1) / 2;
    while (hole > top && first[parent].mfKey < val.mfKey) {
        first[hole] = first[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    first[hole] = val;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005916c0 score 24
bool cSC4EffectsManager::Slot05_a9f0d8(uint32_t a)
{
    const char* name = OB_PTR(char, a);
    if (name && *name) {
        Str_a9f0d8* s = reinterpret_cast<Str_a9f0d8*>(reinterpret_cast<char*>(this) + 0x1a0);
        s->Assign(name, name + strlen(name));
        Transform_a9f0d8(s->mpBegin, s->mpEnd, s->mpBegin, tolower);
        NameTable_a9f0d8* table = reinterpret_cast<NameTable_a9f0d8*>(reinterpret_cast<char*>(this) + 0x98);
        return table->Find(s) != 0;
    }
    return false;
}
#endif

// FUNCTION: 0x0058e800
void cSC4EffectsManager::SetSnowlineState(bool on)
{
    TerrainView_a9f0d8* view = Fn00602160();
    if (view) {
        SnowSource_a9f0d8* src = view->GetSource(0);
        if (on) {
            if (mnSnowlineId == -1) {
                mnSnowlineId = src->Create(0x7f94207);
            }
            mnDc0 = 0;
            Fn0058dd30();
        } else if (mnSnowlineId != -1) {
            src->Destroy(mnSnowlineId);
            mnSnowlineId = -1;
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0058e1d0 score 14
void Fn0058e1d0(Pair_a9f0d8* first, int32_t top, int32_t len, Pair_a9f0d8 val, uint32_t extra)
{
    int32_t hole = top;
    int32_t child = 2 * hole + 2;
    while (child < len) {
        if (first[child].mfKey < first[child - 1].mfKey) {
            --child;
        }
        first[hole] = first[child];
        hole = child;
        child = 2 * child + 2;
    }
    if (child == len) {
        first[hole] = first[child - 1];
        hole = child - 1;
    }
    Fn0058d940(first, hole, top, val, extra);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0058f530 score 50
void Fn0058f530(Pair_a9f0d8* first, Pair_a9f0d8* last, uint32_t extra)
{
    while (last - first > 1) {
        --last;
        Pair_a9f0d8 val = *last;
        *last = *first;
        Fn0058e1d0(first, 0, last - first, val, extra);
    }
}
#endif

// STUB: 0x0058f0f0
void Fn0058f0f0(Pair_a9f0d8* first, Pair_a9f0d8* middle, uint32_t extra, uint32_t a, uint32_t b);

#ifdef OB_DRAFTS
// CLOSE: 0x0058f9d0 score 20
void Fn0058f9d0(Pair_a9f0d8* first, Pair_a9f0d8* middle, Pair_a9f0d8* last, uint32_t unused, uint32_t extra)
{
    Fn0058f0f0(first, middle, extra, 0, 0);
    for (Pair_a9f0d8* i = middle; i < last; ++i) {
        if (i->mfKey < first->mfKey) {
            Pair_a9f0d8 val = *i;
            *i = *first;
            Fn0058e1d0(first, 0, middle - first, val, extra);
        }
    }
    Fn0058f530(first, middle, extra);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00590540 score 2
void cSC4EffectsManager::Fn00590540(void* p, uint32_t* pair, uint32_t extra)
{
    const LightDesc_a9f0d8* src = static_cast<const LightDesc_a9f0d8*>(p);
    LightDesc_a9f0d8* dst = reinterpret_cast<LightDesc_a9f0d8*>(mLightA);
    dst->Copy(src);
    dst->mValues.Assign(&src->mValues);
    dst->mfTime = src->mfTime;
    mnLightA44 = 0;
    mfLightAInv = 1.0f / mfLightATime;
    if (pair) {
        mbLightA4c = 1;
        mnLightA50 = pair[0];
        mnLightA54 = pair[1];
        mnLightA58 = extra;
    } else {
        mbLightA4c = 0;
    }
}
#endif

// The message the manager posts (0x2c bytes, built by its constructor).
struct Msg_a9f0d8 {
    // STUB: 0x009134d6
    Msg_a9f0d8* Construct();
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetType(uint32_t type);
};

// STUB: 0x009133da
void* Fn009133da(uint32_t size);

// FUNCTION: 0x0058d9a0
void Fn0058d9a0()
{
    cIGZMessageServer2* server = gpB43ccc;
    if (server) {
        Msg_a9f0d8* msg;
        void* mem = Fn009133da(0x2c);
        if (mem) {
            msg = static_cast<Msg_a9f0d8*>(mem)->Construct();
        } else {
            msg = 0;
        }
        msg->SetType(0x697d01ed);
        server->MessagePost(msg, false);
    }
}

// FUNCTION: 0x0058dba0
Record44Copy_a9f0d8* Record44Copy_a9f0d8::Fn0058dba0(const Record44Copy_a9f0d8* other)
{
    ++mnGeneration;
    mnW04 = other->mnW04;
    mnW08 = other->mnW08;
    mnW0c = other->mnW0c;
    mnW10 = other->mnW10;
    mnW14 = other->mnW14;
    mnW18 = other->mnW18;
    mnW1c = other->mnW1c;
    mnW20 = other->mnW20;
    mnW24 = other->mnW24;
    mnW28 = other->mnW28;
    mnW2c = other->mnW2c;
    mnW30 = other->mnW30;
    mnW34 = other->mnW34;
    mb01 = other->mb01;
    if (&other->mpObj != &mpObj) {
        Effect_a9f0d8* old = mpObj;
        Effect_a9f0d8* p = other->mpObj;
        if (p != old) {
            if (p) {
                p->AddRef();
            }
            mpObj = p;
            if (old) {
                old->Release();
            }
        }
    }
    mnW3c = other->mnW3c;
    mnW40 = other->mnW40;
    return this;
}

struct Forward_a9f0d8 {
    virtual bool QueryInterface(uint32_t id, void** out);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058d9e0 score 23
bool cSC4EffectsManager::QueryInterface(unsigned int id, void** out)
{
    switch (id) {
    case 0xa5eaa1a:
        if (mpDelegate_d98) {
            return static_cast<Forward_a9f0d8*>(mpDelegate_d98)->QueryInterface(0xa5eaa1a, out);
        }
        return false;
    case 1:
        *out = static_cast<cUnk00a9f0d8*>(this);
        AddRef();
        return true;
    case 0x452294aa:
        *out = static_cast<cUnk00aaaa9c*>(this);
        AddRef();
        return true;
    case 0xc97cf5cd:
        *out = static_cast<cUnk00a9f0d8*>(this);
        AddRef();
        return true;
    case 0xc97cf5ce:
        *out = static_cast<cUnk00a9f040*>(this);
        AddRef();
        return true;
    }
    return false;
}
#endif

// The object at +0xc78 and the 3D view the manager notifies.
struct Mode_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual bool IsOn();
    virtual void Pad09();
    virtual uint32_t GetValue();
};

struct View3D_a9f0d8 {
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
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual uint32_t SetValue(uint32_t v);
};

// GLOBAL: 0x00b43dc4
extern View3D_a9f0d8* gpB43dc4_a9f0d8;

struct CountedMsg_a9f0d8 {
    // STUB: 0x009134d6
    CountedMsg_a9f0d8* Construct();
    virtual void Pad00();
    virtual void AddRef();
    virtual uint32_t Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetType(uint32_t type);
};

// FUNCTION: 0x0058e4e0
void cSC4EffectsManager::Fn0058e4e0()
{
    Mode_a9f0d8* mode = *reinterpret_cast<Mode_a9f0d8**>(reinterpret_cast<char*>(this) + 0xc78);
    if (!mode->IsOn()) {
        uint32_t v = (*reinterpret_cast<Mode_a9f0d8**>(reinterpret_cast<char*>(this) + 0xc78))->GetValue();
        if (gpB43dc4_a9f0d8) {
            gpB43dc4_a9f0d8->SetValue(v);
        }
        return;
    }
    if (gpB43dc4_a9f0d8) {
        gpB43dc4_a9f0d8->SetValue(0);
    }
    cIGZMessageServer2* server = gpB43ccc;
    if (server) {
        CountedMsg_a9f0d8* msg;
        void* mem = Fn009133da(0x2c);
        if (mem) {
            msg = static_cast<CountedMsg_a9f0d8*>(mem)->Construct();
        } else {
            msg = 0;
        }
        if (msg) {
            msg->AddRef();
        }
        msg->SetType(0xc9f775bb);
        server->MessagePost(msg, false);
        msg->Release();
    }
}

struct Pad8_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetProperty(uint32_t id, float* values, uint32_t count);
};

struct Frame_a9f0d8 {
    uint8_t mPad[0x38];
    Pad8_a9f0d8* mpTarget;
};

struct Keys_a9f0d8 {
    uint8_t mPad[0x4c];
    uint8_t mnFrom;
    uint8_t mnTo;
    uint8_t mPad4e[6];
    float mfX0;
    float mfX1;
    float mfY0;
    float mfY1;
};

// FUNCTION: 0x0058dc50
void cSC4EffectsManager::Fn0058dc50(void* pKeys, void* pFrame)
{
    const Keys_a9f0d8* keys = static_cast<const Keys_a9f0d8*>(pKeys);
    float x;
    float y;
    if (keys->mnFrom < keys->mnTo - 1) {
        float t = static_cast<float>((mnC84 - keys->mnFrom) / (keys->mnTo - keys->mnFrom - 1));
        float x0 = keys->mfX0;
        x = x0 + (keys->mfX1 - x0) * t;
        float y0 = keys->mfY0;
        y = y0 + (keys->mfY1 - y0) * t;
    } else {
        x = keys->mfX0;
        y = keys->mfY0;
    }
    Pad8_a9f0d8* target = static_cast<Frame_a9f0d8*>(pFrame)->mpTarget;
    float values[2];
    values[0] = x;
    values[1] = y;
    target->SetProperty(0x102, values, 2);
}

struct Held2_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
};

struct Owner_a9f0d8 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void Pad01();
    virtual void Pad02();
    virtual uint32_t Create(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual uint32_t Bind(Held2_a9f0d8* h);
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
    virtual uint32_t Begin();
};

// FUNCTION: 0x0058de80
uint32_t Fn0058de80(uint32_t a1, uint32_t a2, uint32_t a3, Owner_a9f0d8* a4, uint32_t a5, uint32_t a6, Owner_a9f0d8* a7)
{
    if (!a7) {
        return 0;
    }
    uint32_t flags = a5 | 1;
    uint32_t r = a7->Begin();
    Held2_a9f0d8* tmp = 0;
    if (a4) {
        a4->QueryInterface(1, reinterpret_cast<void**>(&tmp));
        r = a7->Bind(tmp);
    }
    if (r) {
        uint32_t res = a7->Create(a1, a2, a3, r, flags, a6);
        if (tmp) {
            tmp->Release();
        }
        return res;
    }
    if (tmp) {
        tmp->Release();
    }
    return 0;
}

struct Renderer_a9f0d8 {
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
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void FreeHandle(uint32_t h);
};

// GLOBAL: 0x00b43dd0
extern Renderer_a9f0d8* gpB43dd0_a9f0d8;

struct Slot38_a9f0d8 {
    uint8_t mPad[0x2c];
    uint32_t mnBegin;
    uint32_t mnEnd;
};

struct Binding_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual void Open(uint32_t flag);
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void SetBlockA(void* p);
    virtual void SetBlockB(void* p);
};

struct SlotRec_a9f0d8 {
    uint8_t mPad[0x20];
    uint32_t mnIndex;
    uint8_t mPad24[0x10];
    uint8_t mBlock34[0x38];
    uint8_t mBlock6c[0xd8];
    uint32_t mnHandle;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058e340 score 11
void cSC4EffectsManager::Fn0058e340(void* pRec)
{
    SlotRec_a9f0d8* rec = static_cast<SlotRec_a9f0d8*>(pRec);
    Slot38_a9f0d8* slot = reinterpret_cast<Slot38_a9f0d8*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0xac) + rec->mnIndex * 0x38);
    if (rec->mnHandle) {
        gpB43dd0_a9f0d8->FreeHandle(rec->mnHandle);
        rec->mnHandle = 0;
    }
    uint32_t begin = slot->mnBegin;
    if (begin != slot->mnEnd) {
        Binding_a9f0d8* tmp = 0;
        if (Slot07_a9f0d8(begin, OB_ADDR(&tmp))) {
            tmp->SetBlockB(rec->mBlock6c);
            tmp->SetBlockA(rec->mBlock34);
            tmp->Open(0);
        }
        if (tmp) {
            tmp->Release();
        }
    }
}
#endif

// STUB: 0x0090fc5b
double RZAtofA(const char* text);

struct CmdArg_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual const char* GetText();
};

struct CmdLine_a9f0d8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual uint32_t GetCount();
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
    virtual CmdArg_a9f0d8* GetArg(uint32_t index);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0058f160 score 50
bool cSC4EffectsManager::DoSnowCheat(void* pCmd)
{
    CmdLine_a9f0d8* cmd = static_cast<CmdLine_a9f0d8*>(pCmd);
    if (cmd->GetCount() > 1) {
        mfSnowDc4 = static_cast<float>(RZAtofA(cmd->GetArg(1)->GetText()));
    }
    if (cmd->GetCount() > 2) {
        mfSnowDc8 = static_cast<float>(RZAtofA(cmd->GetArg(2)->GetText()));
    }
    if (cmd->GetCount() > 3) {
        mfSnowDcc = static_cast<float>(RZAtofA(cmd->GetArg(3)->GetText()));
    }
    if (cmd->GetCount() <= 1 && mnSnowlineId != -1) {
        SetSnowlineState(false);
    } else {
        SetSnowlineState(true);
    }
    return true;
}
#endif

// The STL allocator's new.
// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

#ifdef OB_DRAFTS
// CLOSE: 0x0058ff70 score 70
void PtrVector_a9f0d8::Fn0058ff70(Effect_a9f0d8** pos, Effect_a9f0d8* const* x, uint32_t tag, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t grow = oldSize < n ? n : oldSize;
    uint32_t len = grow + oldSize;
    Effect_a9f0d8** start;
    if (len) {
        start = static_cast<Effect_a9f0d8**>(Fn0090cf54(len * 4));
    } else {
        start = 0;
    }
    Effect_a9f0d8** finish = Fn0058dfe0(mpBegin, pos, start, &atEnd);
    if (n == 1) {
        if (finish) {
            *finish = *x;
            if (*finish) {
                (*finish)->AddRef();
            }
        }
        ++finish;
    } else {
        finish = Fn0058dfa0(finish, n, x, &atEnd);
    }
    if (!atEnd) {
        finish = Fn0058dfe0(pos, mpEnd, finish, &atEnd);
    }
    Destroy();
    mpBegin = start;
    mpEnd = finish;
    mpCap = start + len;
}
#endif
