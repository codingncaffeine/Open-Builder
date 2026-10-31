#include <cstddef>
#include <new>

#include "classes/cSC4AutomataScriptSystem.h"

// STUB: 0x00e5e5620
// (the global operator delete is declared by the compiler)

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

// STUB: 0x0090cf63
void Fn0090cf63(void* block);

// The string argument of the lookups: the string base sits at +4 of the caller's object.
struct StrBase_a96ba8 {
    virtual void Pad00();
};

struct StrOwner_a96ba8 {
    virtual void Pad00();
};

struct Str_a96ba8 : StrOwner_a96ba8, StrBase_a96ba8 {
};

// A node of a string-keyed hashtable: next link, the key string, the value at +0x10.
struct StrNode_a96ba8 {
    uint8_t mPad[0x10];
    uint32_t mnValue;
};

struct StrTable_a96ba8 {
    // STUB: 0x0051c9f0
    StrNode_a96ba8* Find(StrBase_a96ba8* name);
};

// A node of a number-keyed hashtable: next link, key, value.
struct NumNode_a96ba8 {
    NumNode_a96ba8* mpNext;
    uint32_t mnKey;
    uint32_t mnValue;
};

struct NumTable_a96ba8 {
    uint32_t mnPad0;
    NumNode_a96ba8** mpBegin;
    NumNode_a96ba8** mpEnd;
};

inline StrTable_a96ba8* StrTableAt_a96ba8(cSC4AutomataScriptSystem* p, uint32_t offset)
{
    return reinterpret_cast<StrTable_a96ba8*>(reinterpret_cast<char*>(p) + offset);
}

// The two member sub-objects of a record that are copied through calls (12 bytes each).
struct RecSubA_a96ba8 {
    uint8_t mBytes[0xc];
    // STUB: 0x0051fe90
    void Fn0051fe90(const RecSubA_a96ba8* other);
    // STUB: 0x00520970
    RecSubA_a96ba8* Fn00520970(const RecSubA_a96ba8* other);
};

struct RecSubB_a96ba8 {
    uint8_t mBytes[0xc];
    // STUB: 0x00462f00
    void Fn00462f00(const RecSubB_a96ba8* other);
    // STUB: 0x00462c10
    RecSubB_a96ba8* Fn00462c10(const RecSubB_a96ba8* other);
};

// One 0x7c-byte record (the elements of the vectors the sorts and copies below work on): two words keyed
// by a float at +4 and a count at +0xc.
struct Rec_a96ba8 {
    uint32_t mn00;
    float mfKey;
    uint32_t mn08;
    uint32_t mnOrder;
    RecSubA_a96ba8 mA;
    RecSubB_a96ba8 mB;
    uint32_t mn28;
    uint8_t mb2c;
    uint8_t mPad2d[3];
    uint32_t mn30;
    uint32_t mn34;
    uint32_t mn38;
    uint32_t mn3c;
    uint32_t mn40;
    uint8_t mb44;
    uint8_t mb45;
    uint8_t mb46;
    uint8_t mb47;
    uint8_t mb48;
    uint8_t mb49;
    uint8_t mPad4a[2];
    uint32_t mnTail[13];
    // STUB: 0x005205d0
    Rec_a96ba8(const Rec_a96ba8& other);
    // STUB: 0x0050bde0
    ~Rec_a96ba8();
    // STUB: 0x00521470
    Rec_a96ba8* Fn00521470(const Rec_a96ba8* other);
};

// A group template: its name table at +0x34.
struct OccGroup_a96ba8 {
    uint8_t mPad[0x34];
    StrTable_a96ba8 mTable;
    bool Fn0051d970(Str_a96ba8* name, uint32_t* pOut);
};

// A bundle of three strings (vtable 0xa80810 each, 0x14 apart), built with their one-block buffers.
struct Tri_a96ba8 {
    uint32_t mnVt0;
    char* mpBegin0;
    char* mpEnd0;
    char* mpCap0;
    uint32_t mnPad0;
    uint32_t mnVt1;
    char* mpBegin1;
    char* mpEnd1;
    char* mpCap1;
    uint32_t mnPad1;
    uint32_t mnVt2;
    char* mpBegin2;
    char* mpEnd2;
    char* mpCap2;
    uint32_t mnPad2;
    Tri_a96ba8* Fn0051d040();
    void Fn0051d0d0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0051c4b0 score 6
bool cSC4AutomataScriptSystem_8::Slot03_a96ba8_8(uint32_t a)
{
    return *OB_PTR(uint32_t, a) == 0x87163754;
}
#endif

// FUNCTION: 0x0051cf90
uint32_t cSC4AutomataScriptSystem::GetControllerTemplate(uint32_t a)
{
    Str_a96ba8* s = OB_PTR(Str_a96ba8, a);
    StrNode_a96ba8* node = StrTableAt_a96ba8(this, 0x8c)->Find(s);
    if (node) {
        return node->mnValue;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0051cf60 score 12
uint32_t cSC4AutomataScriptSystem::GetAutomataGroup(uint32_t a)
{
    uint32_t result = 0;
    Str_a96ba8* s = OB_PTR(Str_a96ba8, a);
    StrNode_a96ba8* node = StrTableAt_a96ba8(this, 0x60)->Find(s);
    if (node) {
        return node->mnValue;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051cfc0 score 12
uint32_t cSC4AutomataScriptSystem::GetOccupantGroup_2(uint32_t a)
{
    uint32_t result = 0;
    Str_a96ba8* s = OB_PTR(Str_a96ba8, a);
    StrNode_a96ba8* node = StrTableAt_a96ba8(this, 0x4c)->Find(s);
    if (node) {
        return node->mnValue;
    }
    return result;
}
#endif

// FUNCTION: 0x00521320
unsigned int cSC4AutomataScriptSystem::Release()
{
    uint32_t n = mnRefCount;
    if (n > 1) {
        mnRefCount = n - 1;
        return n - 1;
    }
    Shutdown();
    Fn0051ff70();
    operator delete(this);
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0051cff0 score 36
uint32_t cSC4AutomataScriptSystem::GetOccupantGroup(uint32_t id)
{
    NumTable_a96ba8* t = reinterpret_cast<NumTable_a96ba8*>(reinterpret_cast<char*>(this) + 0x74);
    uint32_t n = static_cast<uint32_t>(t->mpEnd - t->mpBegin);
    uint32_t result = 0;
    NumNode_a96ba8* node = t->mpBegin[id % n];
    while (node) {
        if (node->mnKey == id) {
            return node->mnValue;
        }
        node = node->mpNext;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051d1d0 score 41
uint32_t cSC4AutomataScriptSystem::GetDriveCommand(uint32_t key)
{
    NumTable_a96ba8* t = reinterpret_cast<NumTable_a96ba8*>(reinterpret_cast<char*>(this) + 0xa0);
    uint32_t n = static_cast<uint32_t>(t->mpEnd - t->mpBegin);
    uint32_t result = 0xd;
    NumNode_a96ba8* node = t->mpBegin[key % n];
    while (node) {
        if (node->mnKey == key) {
            return node->mnValue;
        }
        node = node->mpNext;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051d970 score 14
bool OccGroup_a96ba8::Fn0051d970(Str_a96ba8* name, uint32_t* pOut)
{
    bool found = false;
    StrNode_a96ba8* node = mTable.Find(name);
    if (node) {
        *pOut = node->mnValue;
        return true;
    }
    return found;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051d040 score 12
Tri_a96ba8* Tri_a96ba8::Fn0051d040()
{
    mpBegin0 = 0;
    mpEnd0 = 0;
    mpCap0 = 0;
    char* p = static_cast<char*>(Fn0090cf54(8));
    mpBegin0 = p;
    mpEnd0 = p;
    mpCap0 = p + 8;
    *p = 0;
    mnVt0 = 0xa80810;
    mnPad0 = 0;
    mpBegin1 = 0;
    mpEnd1 = 0;
    mpCap1 = 0;
    p = static_cast<char*>(Fn0090cf54(8));
    mpBegin1 = p;
    mpEnd1 = p;
    mpCap1 = p + 8;
    *p = 0;
    mnVt1 = 0xa80810;
    mnPad1 = 0;
    mpBegin2 = 0;
    mpEnd2 = 0;
    mpCap2 = 0;
    p = static_cast<char*>(Fn0090cf54(8));
    mpBegin2 = p;
    mpEnd2 = p;
    mpCap2 = p + 8;
    *p = 0;
    mnPad2 = 0;
    mnVt2 = 0xa80810;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0051d0d0 score 4
void Tri_a96ba8::Fn0051d0d0()
{
    mnVt2 = 0xa80810;
    if (mpBegin2) {
        Fn0090cf63(mpBegin2);
    }
    mnVt1 = 0xa80810;
    if (mpBegin1) {
        Fn0090cf63(mpBegin1);
    }
    mnVt0 = 0xa80810;
    if (mpBegin0) {
        Fn0090cf63(mpBegin0);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00520940 score 10
Rec_a96ba8* Fn00520940(Rec_a96ba8* first, Rec_a96ba8* last, Rec_a96ba8* dest)
{
    for (; first != last; ++first, ++dest) {
        if (dest) {
            new (dest) Rec_a96ba8(*first);
        }
    }
    return dest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00521b20 score 40 (0 without the drafts compiled in, unverified: a CLOSE copy constructor gets inlined)
Rec_a96ba8* Fn00521b20(Rec_a96ba8* first, Rec_a96ba8* last, Rec_a96ba8* dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        dest->Fn00521470(first);
        ++first;
        ++dest;
    }
    return dest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00521620 score 40 (0 without the drafts compiled in, unverified: a CLOSE copy constructor gets inlined)
Rec_a96ba8* Fn00521620(Rec_a96ba8* first, Rec_a96ba8* last, Rec_a96ba8* dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        --last;
        --dest;
        dest->Fn00521470(last);
    }
    return dest;
}
#endif

// STUB: 0x005215a0
void Fn005215a0(Rec_a96ba8* first, int32_t hole, int32_t top, Rec_a96ba8 value, uint32_t cmp);

// STUB: 0x00521bb0
void Fn00521bb0(Rec_a96ba8* first, int32_t hole, int32_t len, Rec_a96ba8 value, uint32_t cmp);

// STUB: 0x00521550
void Fn00521550(Rec_a96ba8* last, Rec_a96ba8 value, uint32_t cmp);

#ifdef OB_DRAFTS
// CLOSE: 0x005205d0 score 33
Rec_a96ba8::Rec_a96ba8(const Rec_a96ba8& o)
    : mn00(o.mn00), mfKey(o.mfKey), mn08(o.mn08), mnOrder(o.mnOrder)
{
    mA.Fn0051fe90(&o.mA);
    mB.Fn00462f00(&o.mB);
    mn28 = o.mn28;
    mb2c = o.mb2c;
    mn30 = o.mn30;
    mn34 = o.mn34;
    mn38 = o.mn38;
    mn3c = o.mn3c;
    mn40 = o.mn40;
    mb44 = o.mb44;
    mb45 = o.mb45;
    mb46 = o.mb46;
    mb47 = o.mb47;
    mb48 = o.mb48;
    mb49 = o.mb49;
    for (int32_t i = 0; i < 13; ++i) {
        mnTail[i] = o.mnTail[i];
    }
}

// CLOSE: 0x00521470 score 33
Rec_a96ba8* Rec_a96ba8::Fn00521470(const Rec_a96ba8* o)
{
    mn00 = o->mn00;
    mfKey = o->mfKey;
    mn08 = o->mn08;
    mnOrder = o->mnOrder;
    mA.Fn00520970(&o->mA);
    mB.Fn00462c10(&o->mB);
    mn28 = o->mn28;
    mb2c = o->mb2c;
    mn30 = o->mn30;
    mn34 = o->mn34;
    mn38 = o->mn38;
    mn3c = o->mn3c;
    mn40 = o->mn40;
    mb44 = o->mb44;
    mb45 = o->mb45;
    mb46 = o->mb46;
    mb47 = o->mb47;
    mb48 = o->mb48;
    mb49 = o->mb49;
    for (int32_t i = 0; i < 13; ++i) {
        mnTail[i] = o->mnTail[i];
    }
    return this;
}

// CLOSE: 0x00521b70 score 8
void Fn00521b70(Rec_a96ba8* first, Rec_a96ba8* last, uint32_t cmp)
{
    if (first != last) {
        do {
            Fn00521550(first, *first, cmp);
            ++first;
        } while (first != last);
    }
}

// CLOSE: 0x00521550 score 21
void Fn00521550(Rec_a96ba8* last, Rec_a96ba8 value, uint32_t cmp)
{
    Rec_a96ba8* prev = last - 1;
    while (value.mfKey < prev->mfKey || value.mnOrder > prev->mnOrder) {
        last->Fn00521470(prev);
        last = prev;
        --prev;
    }
    last->Fn00521470(&value);
}

// CLOSE: 0x00522350 score 28
void Fn00522350(Rec_a96ba8* first, Rec_a96ba8* last, uint32_t cmp)
{
    int32_t len = static_cast<int32_t>(last - first);
    if (len >= 2) {
        int32_t parent = (len - 2) / 2;
        Rec_a96ba8* p = first + parent;
        for (;;) {
            Fn00521bb0(first, parent, len, *p, cmp);
            if (parent == 0) {
                return;
            }
            --parent;
            --p;
        }
    }
}

// CLOSE: 0x00521bb0 score 26
void Fn00521bb0(Rec_a96ba8* first, int32_t hole, int32_t len, Rec_a96ba8 value, uint32_t cmp)
{
    int32_t top = hole;
    int32_t child = 2 * hole + 2;
    while (child < len) {
        if (first[child].mfKey < first[child - 1].mfKey || first[child].mnOrder > first[child - 1].mnOrder) {
            --child;
        }
        first[hole].Fn00521470(&first[child]);
        hole = child;
        child = 2 * child + 2;
    }
    if (child == len) {
        first[hole].Fn00521470(&first[child - 1]);
        hole = child - 1;
    }
    Fn005215a0(first, hole, top, value, cmp);
}
#endif
