#include "classes/cGZDBSegmentPackedFile.h"
#include "classes/cUnk00ad80e8.h"
#include "classes/cUnk00ad82e8.h"
#include <algorithm>
#include "gzcom/cRZString.h"


// The lock embedded at offset 0xc (a vtable and one word); only the slots used here are named.
struct Lock_ad87d0 {
    virtual void Pad0_ad87d0();
    virtual void Enter_ad87d0();
    virtual void Leave_ad87d0();
};

// A scope guard over the embedded lock: the constructor takes it, the destructor lets it go.
struct Guard_ad87d0 {
    uint32_t mPad;
    Lock_ad87d0* mpLock;

    // STUB: 0x0048c9f0
    Guard_ad87d0(Lock_ad87d0* lock);
    ~Guard_ad87d0() { mpLock->Leave_ad87d0(); }
};

// The stream object embedded at 0x2c; only slot 13 is used here.
struct Stream_ad87d0 {
    virtual void Pad00_ad87d0();
    virtual void Pad01_ad87d0();
    virtual void Pad02_ad87d0();
    virtual void Pad03_ad87d0();
    virtual void Pad04_ad87d0();
    virtual void Pad05_ad87d0();
    virtual void Pad06_ad87d0();
    virtual void Pad07_ad87d0();
    virtual void Pad08_ad87d0();
    virtual void Pad09_ad87d0();
    virtual void Pad0a_ad87d0();
    virtual void Pad0b_ad87d0();
    virtual void Pad0c_ad87d0();
    virtual void Fn0d_ad87d0(uint32_t value);
};

// The object embedded at 0x40; only slot 31 is used here.
// BEGIN INNER
struct Inner_ad87d0 {
    virtual void Pad00_ad87d0();
    virtual void Pad01_ad87d0();
    virtual void Pad02_ad87d0();
    virtual void Pad03_ad87d0();
    virtual bool Fn04_ad87d0();
    virtual void Pad05_ad87d0();
    virtual void Pad06_ad87d0();
    virtual uint32_t Fn07_ad87d0();
    virtual bool Fn08_ad87d0(uint32_t a);
    virtual void Pad09_ad87d0();
    virtual void Pad0a_ad87d0();
    virtual void Pad0b_ad87d0();
    virtual uint32_t Fn0c_ad87d0(uint32_t position);
    virtual void Pad0d_ad87d0();
    virtual bool Fn0e_ad87d0(uint32_t a, uint32_t b);
    virtual bool Fn0f_ad87d0(uint32_t a, uint32_t b);
    virtual bool Fn10_ad87d0(uint32_t a, uint32_t b);
    virtual void Pad11_ad87d0();
    virtual bool Fn12_ad87d0();
    virtual void Pad13_ad87d0();
    virtual void Pad14_ad87d0();
    virtual void Pad15_ad87d0();
    virtual void Pad16_ad87d0();
    virtual void Pad17_ad87d0();
    virtual void Pad18_ad87d0();
    virtual void Pad19_ad87d0();
    virtual void Pad1a_ad87d0();
    virtual void Pad1b_ad87d0();
    virtual void Pad1c_ad87d0();
    virtual void Pad1d_ad87d0();
    virtual void Pad1e_ad87d0();
    virtual bool Fn1f_ad87d0(uint32_t a, uint32_t b);
};
// END INNER

// A key of the file index (three words).
struct Key_ad87d0 {
    uint32_t a;
    uint32_t b;
    uint32_t c;

    uint32_t Equals(const Key_ad87d0* other) const;
};

// An entry of the index.
struct Entry_ad87d0 {
    uint8_t mPad[0x10];
    uint32_t mn10;
    uint32_t mn14;
};

// The index object (field 0x24).
struct Index_ad87d0 {
    uint8_t mPad[0x10];
    uint32_t mnCount;
    // STUB: 0x0097c081
    void Begin_ad87d0(void** iterator);
    // STUB: 0x0096f5b7
    void Next_ad87d0(void** iterator);
    // STUB: 0x0096eea9
    Entry_ad87d0* Find(const Key_ad87d0* key);
};

// The cursor at 0xd8.
struct CursorNode_ad87d0;
struct Cursor_ad87d0 {
    uint32_t mnValue;
    // STUB: 0x0097989f
    uint32_t Fn0097989f(uint32_t value);
};

// The sub-object a cursor entry points at (field 0x1c of the entry): its second base reports flags.
struct CursorEntry_ad87d0 {
    uint8_t mPad[0x1c];
    void* mpSub;
};

// A node of the record map (field 0x14c).
struct Node_ad87d0 {
    uint8_t mPad[8];
    Node_ad87d0* mpFirst;
    uint8_t mPad0c[8];
    uint32_t mnSize;
};

// STUB: 0x0040d4c0
Node_ad87d0* Fn0040d4c0(Node_ad87d0* node);

struct InsertResult_ad87d0 {
    void* mpNode;
    uint8_t mbNew;
};

// The table at 0x1b0: looks a key up.
struct Table_ad87d0 {
    // STUB: 0x0096f290
    void Find(InsertResult_ad87d0* out, uint32_t key);
};

// The map at 0x14c: inserts a pair.
struct Pair_ad87d0 {
    uint32_t a;
    uint32_t b;
};
struct Map_ad87d0 {
    // STUB: 0x0096f594
    void Insert(InsertResult_ad87d0* out, const Pair_ad87d0* pair);
    // STUB: 0x0096f12d
    void Fn0096f12d(InsertResult_ad87d0* out, const Pair_ad87d0* pair);
    // STUB: 0x0096ee20
    void* Fn0096ee20(void* a, void* b, void* c, void* d, uint32_t e);
};

// The sets at 0x188 and 0x19c.
struct SetResult_ad87d0 {
    uint32_t mWords[3];
};
struct Set_ad87d0 {
    // STUB: 0x0045d650
    void Insert(SetResult_ad87d0* out, const uint32_t* value);
    // STUB: 0x0045d460
    void Erase(const uint32_t* value);
    // STUB: 0x006f1530
    bool Find_ad87d0(const uint32_t* value);
};

#define LOCK_AD87D0 (reinterpret_cast<Lock_ad87d0*>(&mLock[0]))
#define STREAM_AD87D0 (reinterpret_cast<Stream_ad87d0*>(reinterpret_cast<char*>(this) + 0x2c))
#define INNER_AD87D0 (reinterpret_cast<Inner_ad87d0*>(reinterpret_cast<char*>(this) + 0x40))

// FUNCTION: 0x0096df0a
bool cGZDBSegmentPackedFile::Slot00_ad8fc8(uint32_t id, void* out)
{
    if (id == 0x286d4a6a) {
        *static_cast<void**>(out) = this;
        Slot01_ad8fc8();
        return true;
    }
    return cUnk00ad8ca0::Slot00_ad8fc8(id, out);
}

// FUNCTION: 0x0096df3c
void cGZDBSegmentPackedFile::Slot31_ad8ca0()
{
    if (mnFlags & 3) {
        Slot08_ad8ca0();
    }
    if (mbOpen) {
        Slot06_ad8fc8();
    }
    cUnk00ad8ca0::Slot31_ad8ca0();
}

// FUNCTION: 0x0096df60
bool cGZDBSegmentPackedFile::Slot04_ad8fc8(uint32_t a, uint32_t b, uint32_t /*c*/)
{
    if (!mbOpen) {
        mbOpen = true;
        if (b) {
            STREAM_AD87D0->Fn0d_ad87d0(b);
        }
        mn18 = a;
    }
    return true;
}

// FUNCTION: 0x0096df8d
bool cGZDBSegmentPackedFile::Slot06_ad8fc8()
{
    if (mbOpen) {
        mbOpen = false;
        if (mnFlags & 3) {
            Slot08_ad8ca0();
        }
        operator delete(mpBuffer);
        mpBuffer = 0;
    }
    return true;
}

// FUNCTION: 0x0096dfbd
bool cGZDBSegmentPackedFile::Slot07_ad8ca0()
{
    return (mnFlags & 3) != 0;
}

// FUNCTION: 0x0096dfc9
bool cGZDBSegmentPackedFile::Slot15_ad8ca0(uint32_t source)
{
    mn18 = *OB_PTR(uint32_t, source);
    return true;
}

// FUNCTION: 0x0096dfd7
bool cGZDBSegmentPackedFile::Slot07_ad8488(uint32_t value)
{
    if (mnFlags & 3) {
        return false;
    }
    mnC0 = value;
    return true;
}

// FUNCTION: 0x0096dff0
bool cGZDBSegmentPackedFile::Slot09_ad8fc8(uint32_t value)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    bool ok;
    if (!(mnFlags & 3)) {
        STREAM_AD87D0->Fn0d_ad87d0(value);
        ok = true;
    } else {
        ok = false;
    }
    return ok;
}

// FUNCTION: 0x0096e02c
void cGZDBSegmentPackedFile::Slot10_ad8488(uint32_t outA, uint32_t outB)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    *OB_PTR(uint32_t, outA) = mnF0;
    *OB_PTR(uint32_t, outB) = mnF4;
}

// FUNCTION: 0x0096e063
void cGZDBSegmentPackedFile::Slot11_ad8488(uint32_t outA, uint32_t outB)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    *OB_PTR(uint32_t, outA) = mnCc;
    *OB_PTR(uint32_t, outB) = mnD0;
}

// FUNCTION: 0x0096e09a
void cGZDBSegmentPackedFile::Slot12_ad8488(uint32_t a, uint32_t b)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    mnCc = a;
    mnD0 = b;
}

// FUNCTION: 0x0096e0cd
bool cGZDBSegmentPackedFile::GetModificationTime(uint32_t outA, uint32_t outB)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    bool ok = false;
    if (mnFlags & 3) {
        *OB_PTR(uint32_t, outA) = mnFc;
        *OB_PTR(uint32_t, outB) = mn100;
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x0096e112
bool cGZDBSegmentPackedFile::Slot13_ad8488(uint32_t a, uint32_t b)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    bool ok;
    if (INNER_AD87D0->Fn1f_ad87d0(a, b)) {
        mnC4 = a;
        mnC8 = b;
        ok = true;
    } else {
        ok = false;
    }
    return ok;
}

// FUNCTION: 0x0096e15f
bool cGZDBSegmentPackedFile::Slot14_ad8488(uint32_t value)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    mn144 = value;
    return true;
}

// FUNCTION: 0x0096e198
bool cGZDBSegmentPackedFile::SeekAbsolute(uint32_t position)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    bool ok;
    if (mnFlags & 3) {
        ok = INNER_AD87D0->Fn0c_ad87d0(mnC0 + position) == mnC0 + position;
    } else {
        ok = false;
    }
    return ok;
}

// FUNCTION: 0x0096e1e5
bool cGZDBSegmentPackedFile::ReadFileSpan(uint32_t a, uint32_t position, uint32_t c)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    bool ok = false;
    if (mnFlags & 3) {
        if (INNER_AD87D0->Fn0c_ad87d0(mnC0 + position) == mnC0 + position) {
            if (INNER_AD87D0->Fn0e_ad87d0(a, c)) {
                ok = true;
            }
        }
    }
    return ok;
}

// FUNCTION: 0x0096e246
bool cGZDBSegmentPackedFile::ReadFileSpanWithCount(uint32_t a, uint32_t position, uint32_t c)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    bool ok = false;
    if (mnFlags & 3) {
        if (INNER_AD87D0->Fn0c_ad87d0(mnC0 + position) == mnC0 + position) {
            if (INNER_AD87D0->Fn0f_ad87d0(a, c)) {
                ok = true;
            }
        }
    }
    return ok;
}

// FUNCTION: 0x0096e2a7
bool cGZDBSegmentPackedFile::WriteFileSpan(uint32_t a, uint32_t position, uint32_t c)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        if (INNER_AD87D0->Fn0c_ad87d0(mnC0 + position) == mnC0 + position) {
            if (INNER_AD87D0->Fn10_ad87d0(a, c)) {
                ok = true;
            }
        }
    }
    return ok;
}

// FUNCTION: 0x0096e30d
bool cGZDBSegmentPackedFile::Slot28_ad8488()
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    return (mnFlags & 3) != 0;
}

// FUNCTION: 0x0096e337
bool cGZDBSegmentPackedFile::Slot29_ad8488(bool value)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    mbFlag185 = value;
    return true;
}

// FUNCTION: 0x0096ed23
uint32_t cGZDBSegmentPackedFile::Slot16_ad8ca0(uint32_t a)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    uint32_t r;
    if (a) {
        r = Slot18_ad8ca0(0, a);
    } else {
        Index_ad87d0* index = static_cast<Index_ad87d0*>(mpIndex);
        if (index) {
            r = index->mnCount;
        } else {
            r = 0;
        }
    }
    return r;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096f0c3 score 13
bool cGZDBSegmentPackedFile::Slot38_ad8488(uint32_t outCount, uint32_t outSize)
{
    uint32_t* count = OB_PTR(uint32_t, outCount);
    uint32_t* size = OB_PTR(uint32_t, outSize);
    *count = 0;
    *size = 0;
    if (mnFlags & 3) {
        Node_ad87d0* end = static_cast<Node_ad87d0*>(mpMap);
        for (Node_ad87d0* n = end->mpFirst; n != end; n = Fn0040d4c0(n)) {
            ++*count;
            *size += n->mnSize;
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f494 score 10
bool cGZDBSegmentPackedFile::Slot16_ad8488(uint32_t a)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
    uint32_t before = cursor->mnValue;
    uint32_t after = cursor->Fn0097989f(a);
    return after != before;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f779 score 44
bool cGZDBSegmentPackedFile::Slot32_ad8ca0(uint32_t keyAddress)
{
    bool ok = false;
    if (mnFlags & 3) {
        const Key_ad87d0* source = OB_PTR(const Key_ad87d0, keyAddress);
        Key_ad87d0 key = *source;
        if (!static_cast<Index_ad87d0*>(mpIndex)->Find(&key)) {
            Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
            if (cursor->Fn0097989f(keyAddress) != cursor->mnValue) {
                ok = true;
            }
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f7cd score 49
uint32_t cGZDBSegmentPackedFile::Slot18_ad8488(uint32_t keyAddress)
{
    Key_ad87d0 key;
    Guard_ad87d0 guard(LOCK_AD87D0);
    uint32_t r = 0xffffffff;
    if (mnFlags & 3) {
        key = *OB_PTR(const Key_ad87d0, keyAddress);
        Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
        if (e) {
            r = e->mn14;
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f823 score 49
uint32_t cGZDBSegmentPackedFile::Slot21_ad8488(uint32_t keyAddress)
{
    Key_ad87d0 key;
    Guard_ad87d0 guard(LOCK_AD87D0);
    uint32_t r = 0xffffffff;
    if (mnFlags & 3) {
        key = *OB_PTR(const Key_ad87d0, keyAddress);
        Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
        if (e) {
            r = e->mn10;
        }
    }
    return r;
}
#endif

// FUNCTION: 0x0096d895
uint32_t Key_ad87d0::Equals(const Key_ad87d0* other) const
{
    if (a == other->a && b == other->b && c == other->c) {
        return 1;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00970030 score 13
uint32_t cGZDBSegmentPackedFile::Fn00970030(uint32_t key)
{
    InsertResult_ad87d0 found;
    reinterpret_cast<Table_ad87d0*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, key);
    uint32_t r = 0xffffffff;
    if (found.mpNode) {
        r = static_cast<Entry_ad87d0*>(found.mpNode)->mn10;
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096fa30 score 13
bool cGZDBSegmentPackedFile::Slot32_ad8488(uint32_t key)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    InsertResult_ad87d0 found;
    reinterpret_cast<Table_ad87d0*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, key);
    return found.mpNode != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096fde2 score 6
bool cGZDBSegmentPackedFile::Slot36_ad8488(uint32_t a, uint32_t b)
{
    if (a && b) {
        InsertResult_ad87d0 result;
        Pair_ad87d0 pair;
        pair.a = a;
        pair.b = b;
        reinterpret_cast<Map_ad87d0*>(reinterpret_cast<char*>(this) + 0x14c)->Insert(&result, &pair);
        mbDirty = true;
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x0096ffe3
uint32_t cGZDBSegmentPackedFile::Slot34_ad8488(uint32_t key)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    InsertResult_ad87d0 found;
    uint32_t r = 0xffffffff;
    reinterpret_cast<Table_ad87d0*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, key);
    if (found.mpNode) {
        r = Slot18_ad8488(key);
    }
    return r;
}

// FUNCTION: 0x0097932b
bool cGZDBSegmentPackedFile::Slot05_ad8fc8()
{
    if (!mbOpen) {
        mbOpen = true;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009714ff score 8
bool cGZDBSegmentPackedFile::Slot30_ad8488(uint32_t key, bool insert)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    Set_ad87d0* set = reinterpret_cast<Set_ad87d0*>(reinterpret_cast<char*>(this) + 0x188);
    if (insert) {
        SetResult_ad87d0 result;
        set->Insert(&result, &key);
    } else {
        set->Erase(&key);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00971543 score 8
bool cGZDBSegmentPackedFile::Slot31_ad8488(uint32_t key, bool insert)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    Set_ad87d0* set = reinterpret_cast<Set_ad87d0*>(reinterpret_cast<char*>(this) + 0x19c);
    if (insert) {
        SetResult_ad87d0 result;
        set->Insert(&result, &key);
    } else {
        set->Erase(&key);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00970193 score 50
bool cGZDBSegmentPackedFile::Slot09_ad8ca0()
{
    bool ok = true;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        if (!Fn0096fe20()) {
            return false;
        }
        if (mn144 & 1) {
            if (Fn0096ef02()) {
                Slot27_ad8488();
            }
        }
        if (!Fn0096fb0f()) {
            return false;
        }
        if (!Fn0096ef83()) {
            return false;
        }
        if (!Fn0096e37b()) {
            return false;
        }
        return INNER_AD87D0->Fn12_ad87d0();
    }
    return ok;
}
#endif

// Fields reached by offset where no name is known yet.
#define U32_AD87D0(off) (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) + (off)))
#define U8_AD87D0(off) (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(this) + (off)))

// GLOBAL: 0x00b6363c
extern uint32_t gB6363c;

// STUB: 0x009efb59
uint32_t Fn009efb59(uint32_t zero);

// FUNCTION: 0x0096e37b
bool cGZDBSegmentPackedFile::Fn0096e37b()
{
    bool ok = false;
    if (mnFlags & 2) {
        Inner_ad87d0* inner = INNER_AD87D0;
        if (inner->Fn04_ad87d0()) {
            if (inner->Fn0c_ad87d0(mnC0) == mnC0) {
                uint32_t rec[24];
                const uint32_t* source = &U32_AD87D0(0xe4);
                for (int i = 0; i < 24; ++i) {
                    rec[i] = source[i];
                }
                rec[2] = 0;
                rec[0] = gB6363c;
                rec[1] = 1;
                rec[4] = mnD0;
                rec[7] = Fn009efb59(0);
                if (inner->Fn10_ad87d0(OB_ADDR(rec), 0x60)) {
                    ok = true;
                }
            }
        }
    }
    return ok;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096e407 score 6
bool cGZDBSegmentPackedFile::Fn0096e407()
{
    bool ok = false;
    if (U32_AD87D0(0xe4) == gB6363c && U32_AD87D0(0xe8) <= 1) {
        Inner_ad87d0* inner = INNER_AD87D0;
        if (U32_AD87D0(0x108) < 0x7ffffff) {
            if (U32_AD87D0(0x10c) < inner->Fn07_ad87d0()) {
                if (U32_AD87D0(0x110) + U32_AD87D0(0x10c) <= inner->Fn07_ad87d0()) {
                    if (U32_AD87D0(0x114) < 0x7ffffff) {
                        if (U32_AD87D0(0x118) < inner->Fn07_ad87d0()) {
                            if (U32_AD87D0(0x11c) + U32_AD87D0(0x118) <= inner->Fn07_ad87d0()) {
                                ok = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096e49d score 18
bool cGZDBSegmentPackedFile::Fn0096e49d()
{
    bool ok = true;
    uint32_t n = U32_AD87D0(0x118);
    if (n != 0) {
        if (n >= 0x60 && n >= INNER_AD87D0->Fn07_ad87d0()) {
            ok = false;
        }
        if (U32_AD87D0(0x114) != (U32_AD87D0(0x11c) >> 3)) {
            ok = false;
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096e99a score 44
void cGZDBSegmentPackedFile::Fn0096e99a()
{
    uint32_t* header = &U32_AD87D0(0xe4);
    for (int i = 0; i < 24; ++i) {
        header[i] = 0;
    }
    header[0] = gB6363c;
    U32_AD87D0(0xf0) = mnCc;
    U32_AD87D0(0xe8) = 1;
    U32_AD87D0(0xec) = 0;
    U32_AD87D0(0xf4) = mnD0;
    U32_AD87D0(0xf8) = 0;
    U32_AD87D0(0xfc) = Fn009efb59(0);
    U32_AD87D0(0x100) = Fn009efb59(0);
    U32_AD87D0(0x104) = 7;
    U32_AD87D0(0x108) = 0;
    U32_AD87D0(0x10c) = 0;
    U32_AD87D0(0x110) = 0;
    U32_AD87D0(0x114) = 0;
    U32_AD87D0(0x118) = 0;
    U32_AD87D0(0x11c) = 0;
    if (Fn0096e37b()) {
        INNER_AD87D0->Fn08_ad87d0(0x60);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096e617 score 46
bool cGZDBSegmentPackedFile::DecompressData(void* buffer, uint32_t size, void* outBuffer, void* outLength)
{
    uint32_t** out = static_cast<uint32_t**>(outBuffer);
    bool ok = false;
    if (*out == 0 && size != 0) {
        uint32_t length = size;
        *static_cast<uint32_t*>(outLength) = length;
        *out = static_cast<uint32_t*>(operator new(length));
        ok = true;
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096e6f4 score 21
bool cGZDBSegmentPackedFile::DecompressRecord(uint32_t position, uint32_t size, void* outBuffer, void* outLength)
{
    bool ok = false;
    if (position != 0) {
        uint32_t extra;
        char* buffer;
        if (size <= 0x800) {
            if (U32_AD87D0(0x1c4) == 0) {
                U32_AD87D0(0x1c4) = OB_ADDR(operator new(0x800));
            }
            buffer = static_cast<char*>(mpBuffer);
            extra = 0;
        } else {
            buffer = static_cast<char*>(operator new(size));
            extra = OB_ADDR(buffer);
        }
        if (ReadFileSpan(OB_ADDR(buffer), position, size)) {
            ok = DecompressData(buffer, size, outBuffer, outLength);
        }
        operator delete(buffer);
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096ea47 score 48
bool cGZDBSegmentPackedFile::Fn0096ea47(uint32_t position, uint32_t size, void* outBuffer, void* outLength)
{
    uint32_t* out = static_cast<uint32_t*>(outBuffer);
    uint32_t* length = static_cast<uint32_t*>(outLength);
    *out = 0;
    *length = 0;
    bool ok = false;
    if (size >= 0x32 && size <= 0xf42400) {
        if (DecompressRecord(position, size, outBuffer, outLength)) {
            ok = true;
        } else {
            operator delete(reinterpret_cast<void*>(*out));
            *out = 0;
            *length = 0;
        }
    }
    return ok;
}
#endif

// A node of the record map: links at +4/+8/+0xc, key at +0x10, value at +0x14.
struct RbNode_ad87d0 {
    uint32_t mnColor;
    RbNode_ad87d0* mpParent;
    RbNode_ad87d0* mpLeft;
    RbNode_ad87d0* mpRight;
    uint32_t mnKey;
    uint32_t mnValue;
};

// The map object: its head node and the element count.
struct RbMap_ad87d0 {
    RbNode_ad87d0* mpHead;
    uint32_t mnCount;
    void Fn0096eaf5(RbNode_ad87d0* node);
    void Fn0096ed93();
    // STUB: 0x0096f2ab
    void Fn0096f2ab(RbNode_ad87d0** out, uint32_t flag, RbNode_ad87d0* where, RbNode_ad87d0* parent, const Pair_ad87d0* value);
    RbNode_ad87d0** Fn0096f5cd(RbNode_ad87d0** out, const Pair_ad87d0* value);
};

// STUB: 0x0040d500
RbNode_ad87d0* Fn0040d500(RbNode_ad87d0* node);

// FUNCTION: 0x0096ef02
bool cGZDBSegmentPackedFile::Fn0096ef02()
{
    bool ok = false;
    if (mnFlags & 3) {
        uint32_t total = INNER_AD87D0->Fn07_ad87d0();
        RbNode_ad87d0* head = static_cast<RbNode_ad87d0*>(mpMap);
        uint32_t sum = 0;
        for (RbNode_ad87d0* n = head->mpLeft; n != head; n = reinterpret_cast<RbNode_ad87d0*>(Fn0040d4c0(reinterpret_cast<Node_ad87d0*>(n)))) {
            sum += n->mnValue;
        }
        if (sum < total) {
            float a = static_cast<float>(sum);
            float b = static_cast<float>(total - sum);
            if (a / b > *reinterpret_cast<float*>(&mn148)) {
                ok = true;
            }
        }
    }
    return ok;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096ef83 score 111
bool cGZDBSegmentPackedFile::Fn0096ef83()
{
    bool ok = true;
    if ((mnFlags & 3) && (mnFlags & 2) && mbDirty) {
        uint32_t wanted = U32_AD87D0(0x150);
        if (wanted != U32_AD87D0(0x114)) {
            ok = Slot36_ad8488(U32_AD87D0(0x118), U32_AD87D0(0x11c));
            if (ok) {
                if (wanted) {
                    U32_AD87D0(0x11c) = wanted << 3;
                    ok = Slot35_ad8488(OB_ADDR(&U32_AD87D0(0x118)), wanted << 3);
                }
                if (ok) {
                    if (wanted == 0) {
                        U32_AD87D0(0x118) = 0;
                    } else {
                        U32_AD87D0(0x11c) = wanted << 3;
                        U32_AD87D0(0x114) = wanted;
                        uint32_t* table = static_cast<uint32_t*>(operator new(wanted << 3));
                        RbNode_ad87d0* head = static_cast<RbNode_ad87d0*>(mpMap);
                        uint32_t* out = table;
                        for (RbNode_ad87d0* n = head->mpLeft; n != head; n = reinterpret_cast<RbNode_ad87d0*>(Fn0040d4c0(reinterpret_cast<Node_ad87d0*>(n)))) {
                            out[0] = n->mnKey;
                            out[1] = n->mnValue;
                            out += 2;
                        }
                        ok = WriteFileSpan(OB_ADDR(table), U32_AD87D0(0x118), U32_AD87D0(0x11c));
                        operator delete(table);
                    }
                }
            }
        } else {
            U32_AD87D0(0x118) = 0;
            U32_AD87D0(0x114) = 0;
            U32_AD87D0(0x11c) = 0;
        }
        if (ok) {
            mbDirty = false;
        }
    }
    return ok;
}
#endif

// FUNCTION: 0x0096f594
void Map_ad87d0::Insert(InsertResult_ad87d0* out, const Pair_ad87d0* pair)
{
    InsertResult_ad87d0 result;
    Fn0096f12d(&result, pair);
    out->mpNode = result.mpNode;
    out->mbNew = result.mbNew;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096f12d score 85
void Map_ad87d0::Fn0096f12d(InsertResult_ad87d0* out, const Pair_ad87d0* pair)
{
    RbMap_ad87d0* map = reinterpret_cast<RbMap_ad87d0*>(this);
    RbNode_ad87d0* head = map->mpHead;
    RbNode_ad87d0* parent = head;
    RbNode_ad87d0* node = head->mpParent;
    bool left = true;
    while (node) {
        parent = node;
        left = pair->b < node->mnKey;
        node = left ? node->mpLeft : node->mpRight;
    }
    RbNode_ad87d0* prev = parent;
    if (left) {
        if (parent != head->mpLeft) {
            prev = Fn0040d500(parent);
        } else {
            out->mpNode = Fn0096ee20(0, 0, 0, 0, 0);
            out->mbNew = 1;
            return;
        }
    }
    if (prev->mnKey < pair->b) {
        out->mpNode = Fn0096ee20(0, 0, parent, 0, 0);
        out->mbNew = 1;
    } else {
        out->mpNode = prev;
        out->mbNew = 0;
    }
}
#endif

// A hash table of keyed entries (bucket vector at +4, element count at +0x10).
struct HashNode_ad87d0 {
    HashNode_ad87d0* mpNext;
    Key_ad87d0 mKey;
    uint32_t mnValue;
};
struct Hash_ad87d0 {
    uint32_t mPad0;
    HashNode_ad87d0** mppBegin;
    HashNode_ad87d0** mppEnd;
    uint32_t mPadC;
    uint32_t mnCount;
    // STUB: 0x0096edd3
    HashNode_ad87d0* Fn0096edd3(const Key_ad87d0* key);
    // STUB: 0x0096f614
    void Fn0096f614(uint32_t count);
    void* Fn0097005c(void* out, const Key_ad87d0* key);
    HashNode_ad87d0* Fn0096eea9(const Key_ad87d0* key);
    uint32_t Fn0097e4b6(const Key_ad87d0* key);
    // STUB: 0x0096f209
    void Fn0096f209(void* out, const Key_ad87d0* key);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096f209 score 21
void Hash_ad87d0::Fn0096f209(void* out, const Key_ad87d0* key)
{
    uint32_t* result = static_cast<uint32_t*>(out);
    uint32_t bucket = key->c % static_cast<uint32_t>(mppEnd - mppBegin);
    HashNode_ad87d0* first = mppBegin[bucket];
    for (HashNode_ad87d0* n = first; n; n = n->mpNext) {
        if (n->mKey.Equals(key)) {
            result[0] = OB_ADDR(n);
            result[1] = OB_ADDR(this);
            reinterpret_cast<uint8_t*>(result)[8] = 0;
            return;
        }
    }
    HashNode_ad87d0* made = Fn0096edd3(key);
    made->mpNext = first;
    mppBegin[bucket] = made;
    ++mnCount;
    result[0] = OB_ADDR(made);
    result[1] = OB_ADDR(this);
    reinterpret_cast<uint8_t*>(result)[8] = 1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096fa6b score 68
bool cGZDBSegmentPackedFile::Fn0096fa6b()
{
    bool ok = false;
    if (mnFlags & 3) {
        if (U32_AD87D0(0xdc) != 0) {
            // Collects the tracked objects, then notifies each (rough draft of the original's loops).
            ok = true;
        } else {
            ok = true;
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096fb0f score 125
bool cGZDBSegmentPackedFile::Fn0096fb0f()
{
    bool ok = true;
    if ((mnFlags & 3) && (mnFlags & 2) && U8_AD87D0(0x28)) {
        uint32_t count = *reinterpret_cast<uint32_t*>(static_cast<char*>(mpIndex) + 0x10);
        uint32_t bytes = count * 20;
        uint32_t current = U32_AD87D0(0x110);
        if (bytes == current) {
            // same size: rewrite in place
        }
        if (current) {
            ok = Slot36_ad8488(U32_AD87D0(0x10c), current);
        }
        U32_AD87D0(0x108) = count;
        U32_AD87D0(0x110) = bytes;
        if (bytes) {
            ok = Slot35_ad8488(OB_ADDR(&U32_AD87D0(0x10c)), bytes);
            if (ok) {
                uint32_t* out = static_cast<uint32_t*>(operator new(bytes));
                ok = WriteFileSpan(OB_ADDR(out), U32_AD87D0(0x10c), bytes);
                operator delete(out);
            }
        }
        U8_AD87D0(0x28) = 0;
    }
    return ok;
}
#endif

// A std::vector of words: begin, end, capacity.
struct Vec_ad87d0 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x0096f6be
    uint32_t* Fn0096f6be(uint32_t count, uint32_t* from, uint32_t* to);
    void Reserve_ad87d0(uint32_t count);
};

// STUB: 0x00459d80
uint32_t* Fn00459d80(uint32_t count);

// STUB: 0x0090cf63
void StlDelete_ad87d0(void* p);

#ifdef OB_DRAFTS
// CLOSE: 0x00970080 score 53
void Vec_ad87d0::Reserve_ad87d0(uint32_t count)
{
    if (static_cast<uint32_t>(mpCap - mpBegin) < count) {
        uint32_t used = mpEnd - mpBegin;
        uint32_t* fresh;
        if (mpBegin) {
            fresh = Fn0096f6be(count, mpBegin, mpEnd);
            if (mpBegin) {
                StlDelete_ad87d0(mpBegin);
            }
        } else {
            fresh = Fn00459d80(count);
        }
        mpEnd = fresh + used;
        mpBegin = fresh;
        mpCap = fresh + count;
    }
}
#endif

// FUNCTION: 0x0097005c
void* Hash_ad87d0::Fn0097005c(void* out, const Key_ad87d0* key)
{
    Fn0096f614(mnCount + 1);
    Fn0096f209(out, key);
    return out;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096fc95 score 38
bool cGZDBSegmentPackedFile::Fn0096fc95()
{
    bool ok = true;
    uint32_t size = INNER_AD87D0->Fn07_ad87d0();
    Index_ad87d0* index = static_cast<Index_ad87d0*>(mpIndex);
    (void)index;
    for (RbNode_ad87d0* n = static_cast<RbNode_ad87d0*>(mpIndex); n; n = 0) {
        uint32_t offset = n->mnKey;
        if (offset < 0x60 || offset >= size || offset + n->mnValue > size) {
            ok = false;
            break;
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096fce8 score 92
bool cGZDBSegmentPackedFile::Fn0096fce8()
{
    bool ok = false;
    if (U32_AD87D0(0x114) != 0) {
        if (INNER_AD87D0->Fn0c_ad87d0(mnC0 + U32_AD87D0(0x118)) == mnC0 + U32_AD87D0(0x118)) {
            uint32_t count = U32_AD87D0(0x114);
            uint32_t* table = static_cast<uint32_t*>(operator new(count << 3));
            if (INNER_AD87D0->Fn0e_ad87d0(OB_ADDR(table), U32_AD87D0(0x114) << 3)) {
                uint32_t* p = table;
                for (uint32_t i = 0; i < U32_AD87D0(0x114); ++i) {
                    Pair_ad87d0 pair;
                    InsertResult_ad87d0 result;
                    pair.a = p[0];
                    pair.b = p[1];
                    reinterpret_cast<Map_ad87d0*>(reinterpret_cast<char*>(this) + 0x14c)->Insert(&result, &pair);
                    p += 2;
                }
                if (Fn0096e49d()) {
                    mbDirty = false;
                    ok = true;
                }
            }
            operator delete(table);
        }
    } else {
        ok = true;
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096fe20 score 80
bool cGZDBSegmentPackedFile::Fn0096fe20()
{
    bool ok = true;
    if ((mnFlags & 3) && (mnFlags & 2) && U8_AD87D0(0x184)) {
        uint32_t header[3];
        header[0] = 0xe86b1eef;
        header[1] = 0xe86b1eef;
        header[2] = 0x286b1f03;
        uint32_t count = U32_AD87D0(0x1c0);
        uint32_t* buffer = static_cast<uint32_t*>(operator new(count << 4));
        uint32_t* out = buffer;
        
        ok = Slot20_ad8488(OB_ADDR(header), OB_ADDR(buffer), count << 4);
        if (ok) {
            U8_AD87D0(0x184) = 0;
        }
        operator delete(buffer);
        (void)out;
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096ff01 score 52
bool cGZDBSegmentPackedFile::ShouldRecordBeCompressed(void* key, uint32_t size)
{
    bool ok = false;
    if (size >= 0x32 && size <= 0xf42400) {
        const Key_ad87d0* k = static_cast<const Key_ad87d0*>(key);
        if (k->a != 0xe86b1eef) {
            if (!mbFlag185) {
                if (U32_AD87D0(0x198) != 0) {
                    if (reinterpret_cast<Set_ad87d0*>(reinterpret_cast<char*>(this) + 0x188)->Find_ad87d0(&k->a)) {
                        return false;
                    }
                }
                if (U32_AD87D0(0x1ac) != 0) {
                    if (reinterpret_cast<Set_ad87d0*>(reinterpret_cast<char*>(this) + 0x19c)->Find_ad87d0(&k->b)) {
                        return false;
                    }
                }
            }
            ok = true;
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096ff7e score 40
bool cGZDBSegmentPackedFile::Fn0096ff7e(void* keyPointer, uint32_t outBuffer, void* outLength)
{
    bool ok = false;
    const Key_ad87d0* source = static_cast<const Key_ad87d0*>(keyPointer);
    InsertResult_ad87d0 found;
    reinterpret_cast<Table_ad87d0*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, OB_ADDR(source));
    if (found.mpNode) {
        Key_ad87d0 key = *source;
        Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
        if (e) {
            ok = DecompressRecord(e->mn10, e->mn14, reinterpret_cast<void*>(outBuffer), outLength);
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009708be score 243
bool cGZDBSegmentPackedFile::Fn009708be(void* source, void* key, bool convert, bool keep)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    bool ok = false;
    cGZDBSegmentPackedFile* other = static_cast<cGZDBSegmentPackedFile*>(source);
    uint32_t size = other->Slot18_ad8488(OB_ADDR(key));
    if (size != 0xffffffff) {
        char* buffer = static_cast<char*>(operator new(size));
        uint32_t length = size;
        if (other->Slot19_ad8488(OB_ADDR(key), OB_ADDR(buffer), OB_ADDR(&length)) != 0xffffffff) {
            if (Slot20_ad8488(OB_ADDR(key), OB_ADDR(buffer), length)) {
                ok = true;
                if (!keep) {
                    other->Slot27_ad8488();
                }
            }
        }
        operator delete(buffer);
    }
    return ok;
}
#endif

// The base object of the record readers (a word array; vtables at 0, 4, 0x1c and 0x2c).
struct RecBase_ad87d0 {
    uint32_t w[0x18];
    // STUB: 0x00975cb5
    void Fn00975cb5(uint32_t a, void* b, uint32_t c);
    // the record constructors (cUnk00ad7ee8, cUnk00ad80e8, cUnk00ad82e8) as the drafts call them
    // STUB: 0x0096d859
    RecBase_ad87d0* Fn0096d859(uint32_t kind, uint32_t a, void* b, uint32_t c);
    // STUB: 0x0096d8d0
    RecBase_ad87d0* Fn0096d8d0(uint32_t a, uint32_t b, uint32_t c, void* d, uint32_t e);
    // STUB: 0x0096d9d1
    RecBase_ad87d0* Fn0096d9d1(uint32_t* a, uint32_t b, uint32_t c, void* d, uint32_t e);
    RecBase_ad87d0* Fn0096da30(uint32_t a, uint32_t b, uint32_t c, void* d, uint32_t e);
    RecBase_ad87d0* Fn00970e67(const void* data, uint32_t length, uint32_t c, void* d, uint32_t e);
    RecBase_ad87d0* Fn00970c4d(uint32_t data, uint32_t length, const Key_ad87d0* key, void* d, uint32_t e);
    // STUB: 0x00478aa0
    void Fn00478aa0(uint32_t length);
};

// Not hooked: run in the game, a constructor installs our stand-in vtables (their destructors are not the original's
// yet) in place of the original's.
// FUNCTION: 0x0096d859 nohook
cUnk00ad7ee8::cUnk00ad7ee8(uint32_t kind, uint32_t a, void* b, uint32_t c)
    : cUnk00ad7cf0(a, b, c)
{
    mnKind = kind;
}

// FUNCTION: 0x0096d8d0 nohook
cUnk00ad80e8::cUnk00ad80e8(uint32_t a, uint32_t b, uint32_t c, void* d, uint32_t e)
    : cUnk00ad7ee8(1, c, d ? static_cast<char*>(d) + 4 : 0, e)
{
    mnField48 = 0;
    mnValue = a;
    mnField4c = b;
    field6 = 1;
}

// FUNCTION: 0x0096d9d1 nohook
cUnk00ad82e8::cUnk00ad82e8(uint32_t* a, uint32_t b, uint32_t c, void* d, uint32_t e)
    : cUnk00ad7ee8(2, c, d ? static_cast<char*>(d) + 4 : 0, e)
{
    mnField48 = 0;
    mpShared = a;
    mnField4c = b;
    ++a[1];
    field6 = 1;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096da30 score 4
RecBase_ad87d0* RecBase_ad87d0::Fn0096da30(uint32_t a, uint32_t b, uint32_t c, void* d, uint32_t e)
{
    Fn0096d859(2, c, d ? static_cast<char*>(d) + 4 : 0, e);
    w[0] = 0xad82e8;
    w[1] = 0xad82a8;
    w[7] = 0xad8248;
    w[0xb] = 0xad81e8;
    uint32_t* shared = static_cast<uint32_t*>(operator new(8));
    if (shared) {
        shared[1] = 0;
        shared[0] = a;
    }
    w[0x12] = 0;
    w[0x11] = OB_ADDR(shared);
    w[0x13] = b;
    ++shared[1];
    reinterpret_cast<uint16_t*>(w)[5] = 1;
    return this;
}
#endif

// An object with a size field and two helpers (a string-like buffer).
struct CountNode_ad87d0 {
    uint32_t mPad[2];
    int32_t mnCount;
};
struct EraseArg_ad87d0 {
    CountNode_ad87d0* mpNode;
    void* mpTable;
};
struct Buffer_ad87d0 {
    uint32_t w[8];
    // STUB: 0x0058efe0
    CountNode_ad87d0* Find(const int32_t* key);
    // STUB: 0x0092dc3a
    void Erase(EraseArg_ad87d0 where);
    // STUB: 0x005e06d0
    void* Fn005e06d0(void* out, const void* pair);
    // STUB: 0x004f0940
    void Fn004f0940(uint32_t count);
    // STUB: 0x005e04a0
    void Fn005e04a0(uint32_t a, uint32_t b);
    uint32_t Fn005e06d0(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005e06d0 score 10
uint32_t Buffer_ad87d0::Fn005e06d0(uint32_t a, uint32_t b)
{
    Fn004f0940(w[4] + 1);
    Fn005e04a0(a, b);
    return a;
}
#endif

// A second container with the same insert shape.
struct Buffer2_ad87d0 {
    uint32_t w[8];
    // STUB: 0x0096f614
    void Fn0096f614(uint32_t count);
    // STUB: 0x0097c0c5
    void Fn0097c0c5(uint32_t a, uint32_t b);
    uint32_t Fn0097c51a(uint32_t a, uint32_t b);
};

// FUNCTION: 0x0097c51a
uint32_t Buffer2_ad87d0::Fn0097c51a(uint32_t a, uint32_t b)
{
    Fn0096f614(w[4] + 1);
    Fn0097c0c5(a, b);
    return a;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096eea9 score 14
HashNode_ad87d0* Hash_ad87d0::Fn0096eea9(const Key_ad87d0* key)
{
    uint32_t bucket = key->c % static_cast<uint32_t>(mppEnd - mppBegin);
    HashNode_ad87d0* n = mppBegin[bucket];
    for (; n; n = n->mpNext) {
        if (n->mKey.Equals(key)) {
            break;
        }
    }
    return n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097e4b6 score 22
uint32_t Hash_ad87d0::Fn0097e4b6(const Key_ad87d0* key)
{
    uint32_t removed = 0;
    uint32_t bucket = key->c % static_cast<uint32_t>(mppEnd - mppBegin);
    HashNode_ad87d0* first = mppBegin[bucket];
    if (first) {
        HashNode_ad87d0* prev = first;
        HashNode_ad87d0* n = first->mpNext;
        while (n) {
            if (n->mKey.Equals(key)) {
                prev->mpNext = n->mpNext;
                StlDelete_ad87d0(n);
                n = prev->mpNext;
                ++removed;
                --mnCount;
            } else {
                prev = n;
                n = n->mpNext;
            }
        }
        if (first->mKey.Equals(key)) {
            mppBegin[bucket] = first->mpNext;
            StlDelete_ad87d0(first);
            ++removed;
            --mnCount;
        }
    }
    return removed;
}
#endif

// FUNCTION: 0x0096eaf5
void RbMap_ad87d0::Fn0096eaf5(RbNode_ad87d0* node)
{
    while (node) {
        Fn0096eaf5(node->mpRight);
        RbNode_ad87d0* next = node->mpLeft;
        StlDelete_ad87d0(node);
        node = next;
    }
}

// FUNCTION: 0x0096ed93
void RbMap_ad87d0::Fn0096ed93()
{
    if (mnCount) {
        Fn0096eaf5(mpHead->mpParent);
        mpHead->mpLeft = mpHead;
        mpHead->mpParent = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096f5cd score 46
RbNode_ad87d0** RbMap_ad87d0::Fn0096f5cd(RbNode_ad87d0** out, const Pair_ad87d0* value)
{
    RbNode_ad87d0* parent = mpHead;
    RbNode_ad87d0* node = parent->mpParent;
    while (node) {
        parent = node;
        if (node->mnKey < value->a) {
            node = node->mpRight;
        } else {
            node = node->mpLeft;
        }
    }
    Fn0096f2ab(out, 0, node, parent, value);
    return out;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f2ab score 63
void RbMap_ad87d0::Fn0096f2ab(RbNode_ad87d0** out, uint32_t flag, RbNode_ad87d0* where, RbNode_ad87d0* parent, const Pair_ad87d0* value)
{
    RbNode_ad87d0* created = 0;
    (void)flag;
    (void)where;
    (void)parent;
    (void)value;
    ++mnCount;
    *out = created;
}
#endif

// STUB: 0x005f8fe0
bool Fn005f8fe0(int32_t character);

// STUB: 0x00917ae0
bool Fn00917ae0(int32_t character);

// STUB: 0x009f5105
int32_t Fn009f5105();

// STUB: 0x009f50be
char* Fn009f50be(int32_t drive, char* buffer, int32_t size);

// STUB: 0x009f17e0
uint32_t Fn009f17e0(const char* text);

// STUB: 0x00917e7c
char* Fn00917e7c(char* out, const char* path, uint32_t size, const char* base);

#ifdef OB_DRAFTS
// CLOSE: 0x009185c4 score 85
char* Fn009185c4(char* out, const char* path, uint32_t size)
{
    char base[0x208];
    int32_t first = static_cast<uint8_t>(path[0]);
    if (first) {
        if (path[1] && Fn005f8fe0(first) && Fn005f8fe0(static_cast<uint8_t>(path[1]))) {
            base[0] = '\\';
            base[1] = '\\';
            base[2] = 0;
            path += 2;
            return Fn00917e7c(out, path, size, base);
        }
        int32_t drive;
        int32_t letter;
        if (path[1] == ':' && Fn00917ae0(first)) {
            letter = first;
            if (first >= 'a') {
                letter = static_cast<char>(first - 0x20);
            }
            drive = letter - 0x40;
            path += 2;
        } else {
            drive = Fn009f5105();
            letter = drive ? drive + 0x40 : 0x43;
        }
        if (Fn005f8fe0(static_cast<uint8_t>(path[0]))) {
            base[0] = static_cast<char>(letter);
            base[1] = ':';
            base[2] = '\\';
            base[3] = 0;
            path += 1;
        } else {
            if (!Fn009f50be(drive, base, 0x209)) {
                return 0;
            }
            char* end = base + Fn009f17e0(base);
            if (!Fn005f8fe0(static_cast<uint8_t>(end[-1]))) {
                end[0] = '\\';
                end[1] = 0;
            }
        }
        return Fn00917e7c(out, path, size, base);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00919672 score 6
bool Fullpath(cRZString& out, const cRZString& in)
{
    char buffer[0x218];
    if (Fn009185c4(buffer, in.c_str(), 0x208)) {
        cRZString text(buffer);
        out = text;
        return true;
    }
    return false;
}
#endif

// The primary view of the packed file seen from a pointer to its second base; slot 62 is called.
struct Primary_ad87d0 {
    virtual void Pad00_ad87d0();
    virtual void Pad01_ad87d0();
    virtual void Pad02_ad87d0();
    virtual void Pad03_ad87d0();
    virtual void Pad04_ad87d0();
    virtual void Pad05_ad87d0();
    virtual void Pad06_ad87d0();
    virtual void Pad07_ad87d0();
    virtual void Pad08_ad87d0();
    virtual void Pad09_ad87d0();
    virtual void Pad0a_ad87d0();
    virtual void Pad0b_ad87d0();
    virtual void Pad0c_ad87d0();
    virtual void Pad0d_ad87d0();
    virtual void Pad0e_ad87d0();
    virtual void Pad0f_ad87d0();
    virtual void Pad10_ad87d0();
    virtual void Pad11_ad87d0();
    virtual void Pad12_ad87d0();
    virtual void Pad13_ad87d0();
    virtual void Pad14_ad87d0();
    virtual void Pad15_ad87d0();
    virtual void Pad16_ad87d0();
    virtual void Pad17_ad87d0();
    virtual void Pad18_ad87d0();
    virtual void Pad19_ad87d0();
    virtual void Pad1a_ad87d0();
    virtual void Pad1b_ad87d0();
    virtual void Pad1c_ad87d0();
    virtual void Pad1d_ad87d0();
    virtual void Pad1e_ad87d0();
    virtual void Pad1f_ad87d0();
    virtual void Pad20_ad87d0();
    virtual void Pad21_ad87d0();
    virtual void Pad22_ad87d0();
    virtual void Pad23_ad87d0();
    virtual void Pad24_ad87d0();
    virtual void Pad25_ad87d0();
    virtual void Pad26_ad87d0();
    virtual void Pad27_ad87d0();
    virtual void Pad28_ad87d0();
    virtual void Pad29_ad87d0();
    virtual void Pad2a_ad87d0();
    virtual void Pad2b_ad87d0();
    virtual void Pad2c_ad87d0();
    virtual void Pad2d_ad87d0();
    virtual void Pad2e_ad87d0();
    virtual void Pad2f_ad87d0();
    virtual void Pad30_ad87d0();
    virtual void Pad31_ad87d0();
    virtual void Pad32_ad87d0();
    virtual void Pad33_ad87d0();
    virtual void Pad34_ad87d0();
    virtual void Pad35_ad87d0();
    virtual void Pad36_ad87d0();
    virtual void Pad37_ad87d0();
    virtual void Pad38_ad87d0();
    virtual void Pad39_ad87d0();
    virtual void Pad3a_ad87d0();
    virtual void Pad3b_ad87d0();
    virtual void Pad3c_ad87d0();
    virtual void Pad3d_ad87d0();
    virtual void Fn3e_ad87d0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096e363 score 3
void Fn0096e363(void* second)
{
    Primary_ad87d0* primary = second ? reinterpret_cast<Primary_ad87d0*>(static_cast<char*>(second) - 4) : 0;
    primary->Fn3e_ad87d0();
}
#endif

// The compressor used to size and pack records.
struct Compressor_ad87d0 {
    uint32_t w[8];
    // STUB: 0x00a6e193
    Compressor_ad87d0();
    // STUB: 0x00a6d979
    uint32_t GetMaxLength(uint32_t size);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096e4dc score 40
bool Fn0096e4dc(uint32_t source, uint32_t size, uint32_t** outBuffer, uint32_t* outLength)
{
    bool ok = false;
    bool allocate = *outBuffer == 0;
    if (size < 0x2625a00) {
        Compressor_ad87d0 compressor;
        if (allocate) {
            *outLength = compressor.GetMaxLength(size);
            *outBuffer = static_cast<uint32_t*>(operator new(*outLength));
        }
        (void)source;
        ok = true;
    }
    return ok;
}
#endif

// A file object used while writing a temporary file.
struct File_ad87d0 {
    uint32_t w[26];
    // STUB: 0x00918c00
    File_ad87d0(cRZString* name);
    // STUB: 0x00919b00
    bool Open(uint32_t a, uint32_t b, uint32_t c);
    // STUB: 0x009188a5
    void Close();
    // STUB: 0x00918c70
    ~File_ad87d0();
};

// A sink object: slot 3 receives (data, length); slot 5 gives a number for the temporary name.
struct Sink_ad87d0 {
    virtual void Pad0_ad87d0();
    virtual void Pad1_ad87d0();
    virtual void Pad2_ad87d0();
    virtual void Pad3_ad87d0();
    virtual void Pad4_ad87d0();
    virtual uint32_t Fn5_ad87d0(uint32_t seed, uint32_t counter);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0091a686 score 153
void Fn0091a686(Sink_ad87d0* sink, cIGZString* source, cIGZString* extension)
{
    uint32_t seed = Fn009efb59(0);
    cRZString name;
    cRZString text(*source);
    cRZString suffix;
    if (extension) {
        suffix = *static_cast<cRZString*>(extension);
    } else {
        suffix = cRZString("");
    }
    for (uint32_t counter = 0; counter < 10000; ++counter) {
        cRZString path;
        uint32_t id = sink->Fn5_ad87d0(seed, counter);
        path.Sprintf("%s%u%s", text.ToChar(), id, suffix.ToChar());
        File_ad87d0 file(&path);
        if (file.Open(3, 0, 0)) {
            file.Close();
            return;
        }
    }
}
#endif

// STUB: 0x009f19b0
void* Fn009f19b0(void* to, const void* from, uint32_t count);

#ifdef OB_DRAFTS
// CLOSE: 0x00970e67 score 15
RecBase_ad87d0* RecBase_ad87d0::Fn00970e67(const void* data, uint32_t length, uint32_t c, void* d, uint32_t e)
{
    Fn0096d859(3, c, d ? static_cast<char*>(d) + 4 : 0, e);
    w[0] = 0xad8628;
    w[1] = 0xad85e8;
    w[7] = 0xad8588;
    w[0xb] = 0xad8528;
    w[0x11] = 0;
    w[0x12] = 0;
    w[0x13] = 0;
    w[0x14] = 0;
    w[0x15] = 0;
    reinterpret_cast<uint8_t*>(w)[0x58] = 0;
    reinterpret_cast<uint16_t*>(w)[5] = 3;
    Fn00478aa0(length);
    Fn009f19b0(reinterpret_cast<void*>(w[0x11]), data, length);
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097139c score 74
void cGZDBSegmentPackedFile::IncrementTypeAndGroupUse(uint32_t type, uint32_t group, bool add)
{
    if (U8_AD87D0(0x15a)) {
        Buffer_ad87d0* types = reinterpret_cast<Buffer_ad87d0*>(reinterpret_cast<char*>(this) + 0x15c);
        int32_t typeKey = type;
        CountNode_ad87d0* node = types->Find(&typeKey);
        if (node) {
            if (add) {
                ++node->mnCount;
            } else if (node->mnCount > 1) {
                --node->mnCount;
            } else {
                EraseArg_ad87d0 where;
                where.mpNode = node;
                where.mpTable = types;
                types->Erase(where);
            }
        } else if (add) {
            uint32_t pair[2];
            pair[0] = type;
            pair[1] = 1;
            uint32_t out[3];
            types->Fn005e06d0(out, pair);
        }
        if (U8_AD87D0(0x15a)) {
            Buffer_ad87d0* groups = reinterpret_cast<Buffer_ad87d0*>(reinterpret_cast<char*>(this) + 0x170);
            int32_t groupKey = group;
            node = groups->Find(&groupKey);
            if (node) {
                if (add) {
                    ++node->mnCount;
                } else if (node->mnCount > 1) {
                    --node->mnCount;
                } else {
                    EraseArg_ad87d0 where;
                    where.mpNode = node;
                    where.mpTable = groups;
                    groups->Erase(where);
                }
            } else if (add) {
                uint32_t pair[2];
                pair[0] = group;
                pair[1] = 1;
                uint32_t out[3];
                groups->Fn005e06d0(out, pair);
            }
        }
    }
}
#endif

// STUB: 0x0097c1a2
void Fn0097c1a2(void* table);

#ifdef OB_DRAFTS
// CLOSE: 0x009718b9 score 58
bool cGZDBSegmentPackedFile::Fn009718b9()
{
    bool ok = false;
    Buffer2_ad87d0* table = reinterpret_cast<Buffer2_ad87d0*>(reinterpret_cast<char*>(this) + 0x1b0);
    Fn0097c1a2(table);
    uint32_t key[3];
    key[0] = 0xe86b1eef;
    key[1] = 0xe86b1eef;
    key[2] = 0x286b1f03;
    uint32_t size = 0;
    size = Slot39_ad8ca0(OB_ADDR(key), 0, OB_ADDR(&size));
    if (size != 0xffffffff) {
        uint32_t* buffer = static_cast<uint32_t*>(operator new(size + 4));
        if (Slot39_ad8ca0(OB_ADDR(key), OB_ADDR(buffer), OB_ADDR(&size))) {
            uint32_t count = size >> 4;
            uint32_t* entry = buffer + 2;
            while (count) {
                uint32_t record[5];
                record[0] = entry[-2];
                record[1] = entry[-1];
                record[2] = entry[0];
                record[4] = entry[1];
                uint32_t out[3];
                table->Fn0097c51a(OB_ADDR(out), OB_ADDR(record));
                entry += 4;
                --count;
            }
            ok = true;
            operator delete(buffer);
        } else {
            ok = true;
        }
    } else {
        ok = true;
    }
    return ok;
}
#endif

// GLOBAL: 0x00b63638
extern uint8_t gB63638;

#ifdef OB_DRAFTS
// CLOSE: 0x00972999 score 35
bool cGZDBSegmentPackedFile::Fn00972999()
{
    bool ok = false;
    if (INNER_AD87D0->Fn0c_ad87d0(mnC0) == mnC0 && INNER_AD87D0->Fn0e_ad87d0(OB_ADDR(&U32_AD87D0(0xe4)), 0x60)) {
        if (Fn0096e407()) {
            ok = true;
        }
    } else {
        uint32_t next = Fn009725fb();
        mnC0 = next;
        if (next == 0xffffffff) {
            mnC0 = 0;
        } else if (!gB63638) {
            gB63638 = 1;
            ok = Fn00972999();
            gB63638 = 0;
        }
    }
    return ok;
}
#endif

// A file used for large records (a temporary file object, 0x80 bytes).
struct TempFile_ad87d0 {
    virtual void Pad0_ad87d0();
    virtual void Pad1_ad87d0();
    virtual void Pad2_ad87d0();
    virtual void Pad3_ad87d0();
    virtual void Pad4_ad87d0();
    virtual void Pad5_ad87d0();
    virtual void Pad6_ad87d0();
    virtual void Pad7_ad87d0();
    virtual void Pad8_ad87d0();
    virtual void Pad9_ad87d0();
    virtual void Pad10_ad87d0();
    virtual void Pad11_ad87d0();
    virtual bool Open_ad87d0(uint32_t a, uint32_t b, uint32_t c);
    virtual void Pad13_ad87d0();
    virtual void Pad14_ad87d0();
    virtual void Pad15_ad87d0();
    virtual bool Close_ad87d0();
    virtual void Pad17_ad87d0();
    virtual void Pad18_ad87d0();
    virtual void Pad19_ad87d0();
    virtual void Pad20_ad87d0();
    virtual void Pad21_ad87d0();
    virtual void Pad22_ad87d0();
    virtual void Pad23_ad87d0();
    virtual void Pad24_ad87d0();
    virtual uint32_t Fn18_ad87d0();
};

// STUB: 0x0091a497
bool Fn0091a497(cRZString* name, uint32_t flag);

// STUB: 0x0091a1a6
void Fn0091a1a6(uint32_t value);

#ifdef OB_DRAFTS
// CLOSE: 0x00970c4d score 158
RecBase_ad87d0* RecBase_ad87d0::Fn00970c4d(uint32_t data, uint32_t length, const Key_ad87d0* key, void* d, uint32_t e)
{
    Fn0096d859(3, key->a, d ? static_cast<char*>(d) + 4 : 0, e);
    w[0] = 0xad8628;
    w[1] = 0xad85e8;
    w[7] = 0xad8588;
    w[0xb] = 0xad8528;
    w[0x11] = 0;
    w[0x12] = 0;
    w[0x13] = 0;
    w[0x14] = 0;
    w[0x15] = 0;
    reinterpret_cast<uint8_t*>(w)[0x58] = 0;
    reinterpret_cast<uint16_t*>(w)[5] = 3;
    reinterpret_cast<Vec_ad87d0*>(&w[0x11])->Reserve_ad87d0(0x80);
    if (length) {
        if (length > 0x1e8480 && !reinterpret_cast<uint8_t*>(w)[0x58]) {
            cRZString name;
            reinterpret_cast<uint8_t*>(w)[0x58] = 1;
            name.Sprintf("%s", key);
            if (Fn0091a497(&name, 0)) {
                TempFile_ad87d0* file = static_cast<TempFile_ad87d0*>(operator new(0x80));
                w[0x15] = OB_ADDR(file);
                if (file->Open_ad87d0(3, 3, 1)) {
                    uint32_t done = data;
                    char* chunk = static_cast<char*>(operator new(0x4000));
                    bool ok = true;
                    while (done < length && ok) {
                        uint32_t n = done + 0x4000 > length ? length - done : 0x4000;
                        ok = true;
                        done += n;
                    }
                    operator delete(chunk);
                    if (!ok) {
                        file->Close_ad87d0();
                        Fn0091a1a6(file->Fn18_ad87d0());
                        w[0x15] = 0;
                    }
                }
            }
        }
        if (w[0x15] == 0) {
            if (w[6]) {
                reinterpret_cast<Vec_ad87d0*>(&w[0x11])->Reserve_ad87d0(length);
            }
        }
    }
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00972761 score 150
bool cGZDBSegmentPackedFile::Fn00972761()
{
    bool ok = false;
    if (U32_AD87D0(0x108) != 0) {
        if (INNER_AD87D0->Fn0c_ad87d0(mnC0 + U32_AD87D0(0x10c)) == mnC0 + U32_AD87D0(0x10c)) {
            uint32_t count = U32_AD87D0(0x108);
            uint32_t* records = static_cast<uint32_t*>(operator new(count * 20));
            if (INNER_AD87D0->Fn0e_ad87d0(OB_ADDR(records), U32_AD87D0(0x108) * 20)) {
                Hash_ad87d0* table = static_cast<Hash_ad87d0*>(mpIndex);
                (void)table;
                uint32_t* entry = records;
                for (uint32_t i = 0; i < U32_AD87D0(0x108); ++i) {
                    uint32_t key[5];
                    key[0] = entry[0];
                    key[1] = entry[1];
                    key[2] = entry[2];
                    key[3] = entry[3];
                    key[4] = entry[4];
                    uint32_t out[3];
                    static_cast<Hash_ad87d0*>(mpIndex)->Fn0097005c(out, reinterpret_cast<Key_ad87d0*>(key));
                    IncrementTypeAndGroupUse(entry[0], entry[1], true);
                    entry += 5;
                }
                if (Fn0096fc95()) {
                    U8_AD87D0(0x28) = 0;
                    ok = true;
                }
            }
            operator delete(records);
        }
    } else {
        ok = true;
    }
    return ok;
}
#endif

// The object behind a cursor entry (second base at +4, flags from its slot 4).
struct SubObject_ad87d0 {
    virtual void Pad0_ad87d0();
    virtual void Pad1_ad87d0();
    virtual void Pad2_ad87d0();
    virtual void Pad3_ad87d0();
    virtual uint32_t GetFlags_ad87d0();
};

// A serial record adapter (vtable 0x00ad...), built around a record.
struct SerialRec_ad87d0 {
    uint32_t w[4];
    // STUB: 0x0096ec7c
    SerialRec_ad87d0(void* record);
};
struct Counted_ad87d0 {
    virtual void Pad0_ad87d0();
    virtual void AddRef_ad87d0();
};

// FUNCTION: 0x0096ecc9
bool cGZDBSegmentPackedFile::Slot17_ad8488(uint32_t record, uint32_t out)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    SerialRec_ad87d0* made = new SerialRec_ad87d0(record ? OB_PTR(void, record - 4) : 0);
    Counted_ad87d0* second = made ? reinterpret_cast<Counted_ad87d0*>(reinterpret_cast<char*>(made) + 4) : 0;
    *OB_PTR(Counted_ad87d0*, out) = second;
    second->AddRef_ad87d0();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096f3ed score 70
bool cGZDBSegmentPackedFile::Slot37_ad8ca0(void* record)
{
    bool ok = false;
    if (mnFlags & 3) {
        uint32_t key[3];
        Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
        (void)key;
        (void)cursor;
        Fn0096e363(record);
        ok = true;
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f4ce score 99
bool cGZDBSegmentPackedFile::Slot35_ad8488(uint32_t outPosition, uint32_t size)
{
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        uint32_t end = INNER_AD87D0->Fn07_ad87d0();
        RbNode_ad87d0* head = static_cast<RbNode_ad87d0*>(mpMap);
        RbNode_ad87d0* n = head->mpLeft;
        if (mn144 & 2) {
            while (n != head) {
                if (n->mnValue >= size) {
                    break;
                }
                n = reinterpret_cast<RbNode_ad87d0*>(Fn0040d4c0(reinterpret_cast<Node_ad87d0*>(n)));
            }
        } else {
            n = head;
        }
        if (n != head) {
            uint32_t position = n->mnKey;
            uint32_t rest = n->mnValue - size;
            *OB_PTR(uint32_t, outPosition) = position;
            RbMap_ad87d0* map = reinterpret_cast<RbMap_ad87d0*>(reinterpret_cast<char*>(this) + 0x14c);
            (void)map;
            Slot36_ad8488(position + size, rest);
            ok = true;
        } else {
            *OB_PTR(uint32_t, outPosition) = end;
            ok = INNER_AD87D0->Fn08_ad87d0(end + size);
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f879 score 61
uint32_t cGZDBSegmentPackedFile::Slot22_ad8488()
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    uint32_t r = U32_AD87D0(0x16c);
    if (r == 0) {
        RbNode_ad87d0* head = static_cast<RbNode_ad87d0*>(static_cast<void*>(*reinterpret_cast<void**>(&U32_AD87D0(0xd8))));
        uint32_t best = 0;
        for (RbNode_ad87d0* n = head ? head->mpLeft : 0; n && n != head; n = reinterpret_cast<RbNode_ad87d0*>(Fn0040d4c0(reinterpret_cast<Node_ad87d0*>(n)))) {
            ++best;
        }
        r = best;
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f912 score 61
uint32_t cGZDBSegmentPackedFile::Slot23_ad8488()
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    uint32_t r = U32_AD87D0(0x180);
    if (r == 0) {
        RbNode_ad87d0* head = static_cast<RbNode_ad87d0*>(static_cast<void*>(*reinterpret_cast<void**>(&U32_AD87D0(0xd8))));
        uint32_t best = 0;
        for (RbNode_ad87d0* n = head ? head->mpLeft : 0; n && n != head; n = reinterpret_cast<RbNode_ad87d0*>(Fn0040d4c0(reinterpret_cast<Node_ad87d0*>(n)))) {
            ++best;
        }
        r = best;
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f9ab score 54
uint32_t cGZDBSegmentPackedFile::Slot18_ad8ca0(uint32_t a, uint32_t b)
{
    uint32_t count = 0;
    if (mnFlags & 3) {
        Index_ad87d0* index = static_cast<Index_ad87d0*>(mpIndex);
        (void)index;
        (void)a;
        (void)b;
    }
    return count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097042e score 66
uint32_t cGZDBSegmentPackedFile::Slot33_ad8ca0(uint32_t keyAddress)
{
    uint32_t r = 0xffffffff;
    if (mnFlags & 3) {
        Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
        if (mnFlags & 2) {
            uint32_t entry = cursor->Fn0097989f(keyAddress);
            if (entry != cursor->mnValue) {
                SubObject_ad87d0* sub = static_cast<SubObject_ad87d0*>(OB_PTR(CursorEntry_ad87d0, entry)->mpSub);
                (void)sub;
                r = 0;
            }
        }
        if (r == 0xffffffff) {
            if (Slot32_ad8488(keyAddress)) {
                r = Fn00970030(keyAddress);
            } else {
                Key_ad87d0 key = *OB_PTR(const Key_ad87d0, keyAddress);
                Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
                if (e) {
                    r = e->mn14;
                }
            }
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009704bd score 140
uint32_t cGZDBSegmentPackedFile::Slot39_ad8ca0(uint32_t keyAddress, uint32_t buffer, uint32_t outSize)
{
    uint32_t r = 0xffffffff;
    if ((mnFlags & 3) && (mnFlags & 1)) {
        Key_ad87d0 key = *OB_PTR(const Key_ad87d0, keyAddress);
        Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
        if (e) {
            InsertResult_ad87d0 found;
            reinterpret_cast<Table_ad87d0*>(reinterpret_cast<char*>(this) + 0x1ac)->Find(&found, keyAddress);
            if (buffer) {
                if (found.mpNode) {
                    uint32_t length = *OB_PTR(uint32_t, outSize);
                    if (Fn0096ff7e(OB_PTR(void, keyAddress), buffer, OB_PTR(void, outSize))) {
                        r = length;
                    }
                } else {
                    uint32_t want = e->mn14;
                    uint32_t have = *OB_PTR(uint32_t, outSize);
                    uint32_t take = want < have ? want : have;
                    if (INNER_AD87D0->Fn0c_ad87d0(mnC0 + e->mn10) == mnC0 + e->mn10) {
                        if (INNER_AD87D0->Fn0e_ad87d0(buffer, take)) {
                            r = take;
                        }
                    }
                }
                *OB_PTR(uint32_t, outSize) = r;
            } else {
                *OB_PTR(uint32_t, outSize) = 0;
                r = e->mn14;
            }
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009701fd score 203
bool cGZDBSegmentPackedFile::Slot34_ad8ca0(uint32_t keyAddress, uint32_t out, uint32_t flags)
{
    bool made = false;
    if (mnFlags & 3) {
        if (flags & 2) {
            made = DoOpenRecordForWrite(keyAddress, out);
        } else if (flags & 1) {
            Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
            uint32_t entry = cursor->Fn0097989f(keyAddress);
            if (entry != cursor->mnValue) {
                SubObject_ad87d0* sub = static_cast<SubObject_ad87d0*>(OB_PTR(CursorEntry_ad87d0, entry)->mpSub);
                if (!(sub->GetFlags_ad87d0() & 2)) {
                    return false;
                }
            }
            Key_ad87d0 key = *OB_PTR(const Key_ad87d0, keyAddress);
            Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
            if (e) {
                RecBase_ad87d0* record = 0;
                (void)record;
                made = true;
            }
        }
    }
    return made;
}
#endif

// STUB: 0x0091a847
void Fn0091a847(uint32_t path, cRZString* out);

// STUB: 0x009186e7
bool Fn009186e7(cRZString* path);

// STUB: 0x0091b6ca
bool Fn0091b6ca(cRZString* path);

// STUB: 0x0091b738
void Fn0091b738(cRZString* path);

// STUB: 0x008eba60
void Fn008eba60(void* table);

// STUB: 0x0099784e
void Fn0099784e(void* object);

#ifdef OB_DRAFTS
// CLOSE: 0x0097060c score 128
void cGZDBSegmentPackedFile::DoReadRecord(uint32_t keyAddress, uint32_t path)
{
    bool ok = false;
    uint32_t size = Slot33_ad8ca0(keyAddress);
    if (size != 0xffffffff) {
        cRZString full;
        Fn0091a847(path, &full);
        if (!Fn009186e7(&full)) {
            Fullpath(full, full);
            if (!Fn0091b6ca(&full)) {
                Fn0091b738(&full);
            }
        }
        File_ad87d0 file(reinterpret_cast<cRZString*>(OB_PTR(void, path)));
        if (file.Open(2, 3, 1)) {
            void* record = 0;
            if (Slot35_ad8488(keyAddress, OB_ADDR(&record))) {
                ok = true;
            }
            file.Close();
        }
        if (!ok) {
            Fn0091a1a6(path);
        }
    }
    (void)ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0097078f score 143
uint32_t cGZDBSegmentPackedFile::Slot19_ad8488(uint32_t keyAddress, uint32_t buffer, uint32_t outSize)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    uint32_t r = 0xffffffff;
    if ((mnFlags & 3) && (mnFlags & 1)) {
        Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
        if (mnFlags & 2) {
            uint32_t entry = cursor->Fn0097989f(keyAddress);
            if (entry != cursor->mnValue) {
                SubObject_ad87d0* sub = static_cast<SubObject_ad87d0*>(OB_PTR(CursorEntry_ad87d0, entry)->mpSub);
                if (sub->GetFlags_ad87d0() & 2) {
                    *OB_PTR(uint32_t, outSize) = 0;
                    return 0xffffffff;
                }
            }
        }
        Key_ad87d0 key = *OB_PTR(const Key_ad87d0, keyAddress);
        Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
        if (e) {
            if (buffer) {
                uint32_t want = e->mn14;
                uint32_t have = *OB_PTR(uint32_t, outSize);
                uint32_t take = want < have ? want : have;
                if (INNER_AD87D0->Fn0c_ad87d0(mnC0 + e->mn10) == mnC0 + e->mn10) {
                    if (INNER_AD87D0->Fn0e_ad87d0(buffer, take)) {
                        r = take;
                    }
                }
                *OB_PTR(uint32_t, outSize) = r;
            } else {
                InsertResult_ad87d0 found;
                reinterpret_cast<Table_ad87d0*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, keyAddress);
                *OB_PTR(uint32_t, outSize) = 0;
                if (found.mpNode) {
                    r = Fn00970030(keyAddress);
                } else {
                    r = e->mn14;
                }
            }
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009710f2 score 40
bool cGZDBSegmentPackedFile::Slot08_ad8ca0()
{
    bool ok = true;
    if (mnFlags & 3) {
        if (mnFlags & 2) {
            ok = Fn0096fa6b();
            if (ok) {
                ok = Slot09_ad8ca0();
            }
        }
        void* extra = reinterpret_cast<void*>(U32_AD87D0(0x24));
        if (extra) {
            Fn0099784e(extra);
            operator delete(extra);
            U32_AD87D0(0x24) = 0;
        }
        Fn008eba60(&U32_AD87D0(0x15c));
        Fn008eba60(&U32_AD87D0(0x170));
        reinterpret_cast<RbMap_ad87d0*>(&U32_AD87D0(0x14c))->Fn0096ed93();
        Fn0097c1a2(&U32_AD87D0(0x1b0));
        INNER_AD87D0->Fn07_ad87d0();
        mnFlags = 0;
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00971178 score 156
bool cGZDBSegmentPackedFile::DoOpenRecordForWrite(uint32_t keyAddress, uint32_t out)
{
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
        if (cursor->Fn0097989f(keyAddress) == cursor->mnValue) {
            Key_ad87d0 key = *OB_PTR(const Key_ad87d0, keyAddress);
            Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
            if (e) {
                InsertResult_ad87d0 found;
                reinterpret_cast<Table_ad87d0*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, keyAddress);
                RecBase_ad87d0* record = static_cast<RecBase_ad87d0*>(operator new(0x5c));
                if (found.mpNode) {
                    uint32_t data = 0;
                    uint32_t length = 0;
                    if (!DecompressRecord(e->mn10, e->mn14, &data, &length)) {
                        return false;
                    }
                    record->Fn00970e67(OB_PTR(void, data), length, keyAddress, this, 1);
                    operator delete(OB_PTR(void, data));
                } else {
                    record->Fn00970c4d(e->mn10, e->mn14, OB_PTR(const Key_ad87d0, keyAddress), this, 1);
                }
                *OB_PTR(void*, out) = reinterpret_cast<char*>(record) + 4;
                ok = true;
            }
        }
    } else {
        ok = Slot35_ad8488(keyAddress, out);
    }
    return ok;
}
#endif

// STUB: 0x00974e7a
void* Fn00974e7a(void* memory);

// STUB: 0x00667a60
void Fn00667a60(void* iterator);

// STUB: 0x0097c221
void Fn0097c221(void* table, void* node, void* owner);

#ifdef OB_DRAFTS
// CLOSE: 0x00970b4f score 86
uint32_t cGZDBSegmentPackedFile::Slot26_ad8488(uint32_t other, uint32_t b, uint32_t keep, uint32_t c)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    uint32_t copied = 0;
    cGZDBSegmentPackedFile* source = OB_PTR(cGZDBSegmentPackedFile, other);
    source->Slot28_ad8488();
    Slot28_ad8488();
    void* memory = operator new(0x40);
    void* list = memory ? Fn00974e7a(memory) : 0;
    (void)b;
    (void)c;
    (void)keep;
    if (list) {
        // The original walks the key list and copies each record that exists in the source.
    }
    return copied;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009712d7 score 84
bool cGZDBSegmentPackedFile::Slot35_ad8ca0(uint32_t keyAddress, uint32_t out)
{
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        Key_ad87d0 key = *OB_PTR(const Key_ad87d0, keyAddress);
        if (!static_cast<Index_ad87d0*>(mpIndex)->Find(&key)) {
            Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
            if (cursor->Fn0097989f(keyAddress) == cursor->mnValue) {
                RecBase_ad87d0* record = static_cast<RecBase_ad87d0*>(operator new(0x5c));
                record->Fn00970c4d(0, 0, OB_PTR(const Key_ad87d0, keyAddress), this, 1);
                *OB_PTR(void*, out) = reinterpret_cast<char*>(record) + 4;
                ok = true;
            }
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00971587 score 42
void cGZDBSegmentPackedFile::Slot33_ad8488(uint32_t keyAddress, uint32_t set, uint32_t value)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    Buffer2_ad87d0* table = reinterpret_cast<Buffer2_ad87d0*>(reinterpret_cast<char*>(this) + 0x1b0);
    InsertResult_ad87d0 found;
    reinterpret_cast<Table_ad87d0*>(table)->Find(&found, keyAddress);
    bool exists = found.mpNode != 0;
    if (set & 0xff) {
        if (exists) {
            static_cast<Entry_ad87d0*>(found.mpNode)->mn10 = value;
        } else {
            uint32_t record[5];
            const Key_ad87d0* key = OB_PTR(const Key_ad87d0, keyAddress);
            record[0] = key->a;
            record[1] = key->b;
            record[2] = key->c;
            record[3] = value;
            uint32_t out[3];
            table->Fn0097c51a(OB_ADDR(out), OB_ADDR(record));
        }
    } else if (exists) {
        reinterpret_cast<Hash_ad87d0*>(table)->Fn0097e4b6(OB_PTR(const Key_ad87d0, keyAddress));
    }
    mbFlag184 = true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00971991 score 80
bool cGZDBSegmentPackedFile::Slot36_ad8ca0(void* record)
{
    bool ok = false;
    if (mnFlags & 3) {
        uint32_t key[3];
        Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
        (void)key;
        uint32_t entry = cursor->Fn0097989f(OB_ADDR(key));
        if (entry != cursor->mnValue) {
            Fn0096e363(record);
            ok = true;
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00971a55 score 82
bool cGZDBSegmentPackedFile::Slot38_ad8ca0(uint32_t keyAddress)
{
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
        if (cursor->Fn0097989f(keyAddress) == cursor->mnValue) {
            Key_ad87d0 key = *OB_PTR(const Key_ad87d0, keyAddress);
            Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
            if (e) {
                uint32_t position = e->mn10;
                uint32_t length = e->mn14;
                const Key_ad87d0* k = OB_PTR(const Key_ad87d0, keyAddress);
                IncrementTypeAndGroupUse(k->a, k->b, false);
                Slot33_ad8488(keyAddress, 0, 0);
                Fn0097c221(mpIndex, e, 0);
                Slot36_ad8488(position, length);
                U8_AD87D0(0x28) = 1;
                ok = true;
            }
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00971b1d score 149
bool cGZDBSegmentPackedFile::Slot40_ad8ca0(uint32_t keyAddress, uint32_t data, uint32_t size)
{
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
        if (cursor->Fn0097989f(keyAddress) == cursor->mnValue) {
            Key_ad87d0 key = *OB_PTR(const Key_ad87d0, keyAddress);
            Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
            if (e) {
                uint32_t oldPosition = e->mn10;
                uint32_t oldLength = e->mn14;
                const Key_ad87d0* k = OB_PTR(const Key_ad87d0, keyAddress);
                IncrementTypeAndGroupUse(k->a, k->b, false);
                Slot33_ad8488(keyAddress, 0, 0);
                Fn0097c221(mpIndex, e, 0);
                Slot36_ad8488(oldPosition, oldLength);
                U8_AD87D0(0x28) = 1;
            }
            bool compressed = false;
            if (ShouldRecordBeCompressed(OB_PTR(void, keyAddress), size)) {
                uint32_t packedLength = 0;
                uint32_t packedData = 0;
                if (Fn0096ea47(data, size, &packedData, &packedLength)) {
                    Slot33_ad8488(keyAddress, 1, size);
                    data = packedData;
                    size = packedLength;
                    compressed = true;
                }
            }
            uint32_t position = 0;
            if (Slot35_ad8488(OB_ADDR(&position), size)) {
                if (WriteFileSpan(data, position, size)) {
                    Pair_ad87d0 pair;
                    pair.a = position;
                    pair.b = size;
                    uint32_t out[3];
                    static_cast<Hash_ad87d0*>(mpIndex)->Fn0097005c(out, OB_PTR(const Key_ad87d0, keyAddress));
                    IncrementTypeAndGroupUse(OB_PTR(const Key_ad87d0, keyAddress)->a, OB_PTR(const Key_ad87d0, keyAddress)->b, true);
                    U8_AD87D0(0x28) = 1;
                    ok = true;
                } else {
                    Slot36_ad8488(position, size);
                }
            }
            if (compressed) {
                operator delete(OB_PTR(void, data));
            }
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00971fe2 score 96
uint32_t cGZDBSegmentPackedFile::Slot20_ad8488(uint32_t keyAddress, uint32_t data, uint32_t size)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
        if (cursor->Fn0097989f(keyAddress) == cursor->mnValue) {
            Key_ad87d0 key = *OB_PTR(const Key_ad87d0, keyAddress);
            Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
            if (e) {
                uint32_t oldPosition = e->mn10;
                uint32_t oldLength = e->mn14;
                const Key_ad87d0* k = OB_PTR(const Key_ad87d0, keyAddress);
                IncrementTypeAndGroupUse(k->a, k->b, false);
                Slot33_ad8488(keyAddress, 0, 0);
                Fn0097c221(mpIndex, e, 0);
                Slot36_ad8488(oldPosition, oldLength);
                U8_AD87D0(0x28) = 1;
            }
            uint32_t position = 0;
            if (Slot35_ad8488(OB_ADDR(&position), size)) {
                if (WriteFileSpan(data, position, size)) {
                    uint32_t out[3];
                    static_cast<Hash_ad87d0*>(mpIndex)->Fn0097005c(out, OB_PTR(const Key_ad87d0, keyAddress));
                    const Key_ad87d0* k2 = OB_PTR(const Key_ad87d0, keyAddress);
                    IncrementTypeAndGroupUse(k2->a, k2->b, true);
                    U8_AD87D0(0x28) = 1;
                    ok = true;
                } else {
                    Slot36_ad8488(position, size);
                }
            }
        }
    }
    return ok;
}
#endif

// STUB: 0x0097212d
void* Fn0097212d(void* memory);

#ifdef OB_DRAFTS
// CLOSE: 0x00972542 score 76
uint32_t cGZDBSegmentPackedFile::Slot25_ad8488(uint32_t path, uint32_t a, uint32_t b, uint32_t c)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    uint32_t r = 0xffffffff;
    void* memory = operator new(0x1c8);
    cGZDBSegmentPackedFile* other = static_cast<cGZDBSegmentPackedFile*>(memory ? Fn0097212d(memory) : 0);
    other->Slot01_ad8fc8();
    if (other->Slot06_ad8fc8()) {
        r = 0;
    }
    other->Slot02_ad8fc8();
    (void)path;
    (void)a;
    (void)b;
    (void)c;
    return r;
}
#endif

// STUB: 0x00969ad5
void* Fn00969ad5(void* memory);

#ifdef OB_DRAFTS
// CLOSE: 0x00971cc7 score 256
void cGZDBSegmentPackedFile::DoWriteRecord(uint32_t keyAddress, uint32_t path)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    const Key_ad87d0* k = OB_PTR(const Key_ad87d0, keyAddress);
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        Cursor_ad87d0* cursor = reinterpret_cast<Cursor_ad87d0*>(reinterpret_cast<char*>(this) + 0xd8);
        if (cursor->Fn0097989f(keyAddress) == cursor->mnValue) {
            Key_ad87d0 key = *OB_PTR(const Key_ad87d0, keyAddress);
            Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
            if (e) {
                uint32_t oldPosition = e->mn10;
                uint32_t oldLength = e->mn14;
                IncrementTypeAndGroupUse(k->a, k->b, false);
                Slot33_ad8488(keyAddress, 0, 0);
                Fn0097c221(mpIndex, e, 0);
                Slot36_ad8488(oldPosition, oldLength);
                U8_AD87D0(0x28) = 1;
            }
            File_ad87d0 file(reinterpret_cast<cRZString*>(OB_PTR(void, path)));
            if (file.Open(1, 2, 1)) {
                uint32_t length = file.w[0];
                if (length) {
                    uint32_t position = 0;
                    if (ShouldRecordBeCompressed(OB_PTR(void, keyAddress), length)) {
                        char* buffer = static_cast<char*>(operator new(length + 2));
                        uint32_t packed = 0;
                        uint32_t packedLength = 0;
                        buffer[length + 1] = 0;
                        buffer[length] = 0;
                        if (Fn0096ea47(OB_ADDR(buffer), length, &packed, &packedLength)) {
                            if (Slot35_ad8488(OB_ADDR(&position), packedLength)) {
                                if (WriteFileSpan(packed, position, packedLength)) {
                                    uint32_t out[3];
                                    static_cast<Hash_ad87d0*>(mpIndex)->Fn0097005c(out, OB_PTR(const Key_ad87d0, keyAddress));
                                    IncrementTypeAndGroupUse(k->a, k->b, true);
                                    Slot33_ad8488(keyAddress, 1, length);
                                    U8_AD87D0(0x28) = 1;
                                    ok = true;
                                } else {
                                    Slot36_ad8488(position, packedLength);
                                }
                            }
                            operator delete(reinterpret_cast<void*>(packed));
                        }
                        operator delete(buffer);
                    }
                    if (!ok && Slot35_ad8488(OB_ADDR(&position), length)) {
                        char* chunk = static_cast<char*>(operator new(0x4000));
                        file.Close();
                        uint32_t done = 0;
                        bool good = true;
                        while (done < length && good) {
                            uint32_t n = done + 0x4000 > length ? length - done : 0x4000;
                            good = WriteFileSpan(OB_ADDR(chunk), position + done, n);
                            done += n;
                        }
                        if (good) {
                            uint32_t out[3];
                            static_cast<Hash_ad87d0*>(mpIndex)->Fn0097005c(out, OB_PTR(const Key_ad87d0, keyAddress));
                            IncrementTypeAndGroupUse(k->a, k->b, true);
                            U8_AD87D0(0x28) = 1;
                            ok = true;
                        } else {
                            Slot36_ad8488(position, length);
                        }
                        operator delete(chunk);
                    }
                }
                file.Close();
            }
        }
    }
    (void)ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00972a17 score 131
bool cGZDBSegmentPackedFile::Slot06_ad8ca0(uint32_t readAccess, uint32_t writeAccess)
{
    bool ok = false;
    if (!(mnFlags & 3) && U32_AD87D0(0x30) != U32_AD87D0(0x34) && mbOpen) {
        if ((readAccess & 0xff) || (writeAccess & 0xff)) {
            uint32_t flags = 0;
            uint32_t mode = 2;
            mnFlags = 0;
            if (readAccess & 0xff) {
                flags = 1;
                mnFlags = 1;
                mode = 2;
            }
            if (writeAccess & 0xff) {
                mnFlags |= 3;
                flags |= 3;
                mode = 3;
            }
            Inner_ad87d0* inner = INNER_AD87D0;
            (void)mode;
            if (inner->Fn07_ad87d0() == 0) {
                if (mnFlags & 2) {
                    Fn0096e99a();
                    ok = true;
                }
            } else {
                ok = Fn00972999() && Fn00972761() && Fn0096fce8() && Fn009718b9();
            }
            if (ok && U32_AD87D0(0x24) == 0) {
                void* memory = operator new(0x14);
                U32_AD87D0(0x24) = OB_ADDR(memory ? Fn00969ad5(memory) : 0);
            }
            if (!ok) {
                mnFlags = 0;
            }
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00971481 score 32
void cGZDBSegmentPackedFile::Slot24_ad8488(uint32_t enable)
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    if (U8_AD87D0(0x15a) != static_cast<uint8_t>(enable)) {
        U8_AD87D0(0x15a) = static_cast<uint8_t>(enable);
        Fn008eba60(&U32_AD87D0(0x15c));
        Fn008eba60(&U32_AD87D0(0x170));
        if (U8_AD87D0(0x15a)) {
            void* it = 0;
            static_cast<Index_ad87d0*>(mpIndex)->Begin_ad87d0(&it);
            while (it) {
                const uint32_t* node = static_cast<const uint32_t*>(it);
                IncrementTypeAndGroupUse(node[1], node[2], true);
                static_cast<Index_ad87d0*>(mpIndex)->Next_ad87d0(&it);
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00971617 score 248
bool cGZDBSegmentPackedFile::Fn00971617(void* record, void* keyPointer)
{
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        uint32_t keyAddress = OB_ADDR(keyPointer);
        const Key_ad87d0* k = static_cast<const Key_ad87d0*>(keyPointer);
        Key_ad87d0 key = *k;
        Entry_ad87d0* e = static_cast<Index_ad87d0*>(mpIndex)->Find(&key);
        if (e) {
            uint32_t oldPosition = e->mn10;
            uint32_t oldLength = e->mn14;
            IncrementTypeAndGroupUse(k->a, k->b, false);
            Slot33_ad8488(keyAddress, 0, 0);
            Fn0097c221(mpIndex, e, 0);
            Slot36_ad8488(oldPosition, oldLength);
            U8_AD87D0(0x28) = 1;
        }
        RecBase_ad87d0* source = static_cast<RecBase_ad87d0*>(record);
        uint32_t data = source->w[0x11];
        uint32_t length = source->w[0x12] - data;
        uint32_t position = 0;
        if (ShouldRecordBeCompressed(keyPointer, length)) {
            uint32_t packed = 0;
            uint32_t packedLength = 0;
            if (Fn0096ea47(data, length, &packed, &packedLength)) {
                if (Slot35_ad8488(OB_ADDR(&position), packedLength)) {
                    if (WriteFileSpan(packed, position, packedLength)) {
                        uint32_t out[3];
                        static_cast<Hash_ad87d0*>(mpIndex)->Fn0097005c(out, k);
                        IncrementTypeAndGroupUse(k->a, k->b, true);
                        Slot33_ad8488(keyAddress, 1, length);
                        U8_AD87D0(0x28) = 1;
                        ok = true;
                    } else {
                        Slot36_ad8488(position, packedLength);
                    }
                }
                operator delete(reinterpret_cast<void*>(packed));
            }
        }
        if (!ok && Slot35_ad8488(OB_ADDR(&position), length)) {
            if (WriteFileSpan(data, position, length)) {
                uint32_t out[3];
                static_cast<Hash_ad87d0*>(mpIndex)->Fn0097005c(out, k);
                IncrementTypeAndGroupUse(k->a, k->b, true);
                U8_AD87D0(0x28) = 1;
                ok = true;
            } else {
                Slot36_ad8488(position, length);
            }
        }
    }
    return ok;
}
#endif

// STUB: 0x00919e96
bool Fn00919e96(cRZString* path);

// STUB: 0x0091a225
bool Fn0091a225(cRZString* from, cRZString* to);

#ifdef OB_DRAFTS
// CLOSE: 0x00972233 score 228
bool cGZDBSegmentPackedFile::Slot27_ad8488()
{
    Guard_ad87d0 guard(LOCK_AD87D0);
    bool ok = false;
    if (!U8_AD87D0(0x159)) {
        U8_AD87D0(0x159) = 1;
        if (mnFlags & 3) {
            if (U32_AD87D0(0x150) == 0) {
                ok = true;
            }
            if (U32_AD87D0(0x150) != 0 && (mnFlags & 2) && U32_AD87D0(0xdc) == 0) {
                Slot35_ad8488(OB_ADDR(&U32_AD87D0(0x118)), 0);
                cRZString backup(".bak");
                cRZString temp(".tmp");
                cRZString source;
                Fn0091a847(OB_ADDR(&U32_AD87D0(0x2c)), &source);
                void* memory = operator new(0x1c8);
                cGZDBSegmentPackedFile* fresh = static_cast<cGZDBSegmentPackedFile*>(memory ? Fn0097212d(memory) : 0);
                fresh->Slot01_ad8fc8();
                if (fresh->Slot06_ad8fc8()) {
                    ok = true;
                    Fn0091a225(&source, &temp);
                    Fn0091a225(&temp, &backup);
                }
                fresh->Slot02_ad8fc8();
                if (Fn00919e96(&temp)) {
                    Fn0091a1a6(OB_ADDR(&temp));
                }
            }
        }
        U8_AD87D0(0x159) = 0;
    }
    return ok;
}
#endif
