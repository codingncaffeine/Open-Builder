#include "classes/cGZDBSegmentPackedFile.h"
#include "classes/cUnk00ad80e8.h"
#include "classes/cUnk00ad82e8.h"
#include "classes/cUnk00ad8628.h"
#include "classes/cGZDBSerialRecordAsIGZFile.h"
#include <algorithm>
#include <string.h>
#include "gzcom/cRZString.h"


// The lock embedded at offset 0xc (a vtable and one word); only the slots used here are named.
struct Lock_gzdbpf {
    virtual void Pad0_gzdbpf();
    virtual void Enter_gzdbpf();
    virtual void Leave_gzdbpf();
};

// A scope guard over the embedded lock: the constructor takes it, the destructor lets it go.
struct Guard_gzdbpf {
    uint32_t mPad;
    Lock_gzdbpf* mpLock;

    // STUB: 0x0048c9f0
    Guard_gzdbpf(Lock_gzdbpf* lock);
    ~Guard_gzdbpf() { mpLock->Leave_gzdbpf(); }
};

// The stream object embedded at 0x2c; only slot 13 is used here.
struct Stream_gzdbpf {
    virtual void Pad00_gzdbpf();
    virtual void Pad01_gzdbpf();
    virtual void Pad02_gzdbpf();
    virtual void Pad03_gzdbpf();
    virtual void Pad04_gzdbpf();
    virtual void Pad05_gzdbpf();
    virtual void Pad06_gzdbpf();
    virtual void Pad07_gzdbpf();
    virtual void Pad08_gzdbpf();
    virtual void Pad09_gzdbpf();
    virtual void Pad0a_gzdbpf();
    virtual void Pad0b_gzdbpf();
    virtual void Pad0c_gzdbpf();
    virtual void Fn0d_gzdbpf(uint32_t value);
};

// The object embedded at 0x40; only slot 31 is used here.
// BEGIN INNER
struct Inner_gzdbpf {
    virtual void Pad00_gzdbpf();
    virtual void Pad01_gzdbpf();
    virtual void Pad02_gzdbpf();
    virtual void Pad03_gzdbpf();
    virtual bool Fn04_gzdbpf();
    virtual void Pad05_gzdbpf();
    virtual void Pad06_gzdbpf();
    virtual uint32_t Fn07_gzdbpf();
    virtual bool Fn08_gzdbpf(uint32_t a);
    virtual void Pad09_gzdbpf();
    virtual void Pad0a_gzdbpf();
    virtual void Pad0b_gzdbpf();
    virtual uint32_t Fn0c_gzdbpf(uint32_t position);
    virtual void Pad0d_gzdbpf();
    virtual bool Fn0e_gzdbpf(uint32_t a, uint32_t b);
    virtual bool Fn0f_gzdbpf(uint32_t a, uint32_t b);
    virtual bool Fn10_gzdbpf(uint32_t a, uint32_t b);
    virtual void Pad11_gzdbpf();
    virtual bool Fn12_gzdbpf();
    virtual void Pad13_gzdbpf();
    virtual void Pad14_gzdbpf();
    virtual void Pad15_gzdbpf();
    virtual void Pad16_gzdbpf();
    virtual void Pad17_gzdbpf();
    virtual void Pad18_gzdbpf();
    virtual void Pad19_gzdbpf();
    virtual void Pad1a_gzdbpf();
    virtual void Pad1b_gzdbpf();
    virtual void Pad1c_gzdbpf();
    virtual void Pad1d_gzdbpf();
    virtual void Pad1e_gzdbpf();
    virtual bool Fn1f_gzdbpf(uint32_t a, uint32_t b);
};
// END INNER

// A key of the file index (three words).
struct Key_gzdbpf {
    uint32_t a;
    uint32_t b;
    uint32_t c;

    uint32_t Equals(const Key_gzdbpf* other) const;
};

// An entry of the index.
struct Entry_gzdbpf {
    uint8_t mPad[0x10];
    uint32_t mn10;
    uint32_t mn14;
};

// The index object (field 0x24).
struct Index_gzdbpf {
    uint8_t mPad[0x10];
    uint32_t mnCount;
    // STUB: 0x0097c081
    void Begin_gzdbpf(void** iterator);
    // STUB: 0x0096f5b7
    void Next_gzdbpf(void** iterator);
    // STUB: 0x0096eea9
    Entry_gzdbpf* Find(const Key_gzdbpf* key);
};

// The cursor at 0xd8.
struct CursorNode_gzdbpf;
struct Cursor_gzdbpf {
    uint32_t mnValue;
    // STUB: 0x0097989f
    uint32_t Fn0097989f(uint32_t value);
};

// The sub-object a cursor entry points at (field 0x1c of the entry): its second base reports flags.
struct CursorEntry_gzdbpf {
    uint8_t mPad[0x1c];
    void* mpSub;
};

// A node of the record map (field 0x14c).
struct Node_gzdbpf {
    uint8_t mPad[8];
    Node_gzdbpf* mpFirst;
    uint8_t mPad0c[8];
    uint32_t mnSize;
};

// STUB: 0x0040d4c0
Node_gzdbpf* Fn0040d4c0(Node_gzdbpf* node);

struct InsertResult_gzdbpf {
    void* mpNode;
    uint8_t mbNew;
};

struct Found_gzdbpf {
    void* mpNode;
    void* mpOwner;
};

// The table at 0x1b0: looks a key up.
struct Table_gzdbpf {
    // STUB: 0x0097c049
    void* Lookup(uint32_t key);
    // STUB: 0x0096f290
    Found_gzdbpf* Find(Found_gzdbpf* out, uint32_t key);
};

// The map at 0x14c: inserts a pair.
struct Pair_gzdbpf {
    uint32_t a;
    uint32_t b;
};
struct Map_gzdbpf {
    // STUB: 0x0096f594
    void Insert(InsertResult_gzdbpf* out, const Pair_gzdbpf* pair);
    // STUB: 0x0096f12d
    void Fn0096f12d(InsertResult_gzdbpf* out, const Pair_gzdbpf* pair);
    // STUB: 0x0096ee20
    void* Fn0096ee20(void* a, void* b, void* c, void* d, uint32_t e);
};

// The sets at 0x188 and 0x19c.
struct SetResult_gzdbpf {
    uint32_t mWords[3];
};
struct Set_gzdbpf {
    // STUB: 0x0045d650
    void Insert(SetResult_gzdbpf* out, const uint32_t* value);
    // STUB: 0x0045d460
    void Erase(const uint32_t* value);
    // STUB: 0x006f1530
    bool Find_gzdbpf(const uint32_t* value);
};

#define LOCK_GZDBPF (reinterpret_cast<Lock_gzdbpf*>(&mLock[0]))
#define STREAM_GZDBPF (reinterpret_cast<Stream_gzdbpf*>(reinterpret_cast<char*>(this) + 0x2c))
#define INNER_GZDBPF (reinterpret_cast<Inner_gzdbpf*>(reinterpret_cast<char*>(this) + 0x40))






















#ifdef OB_DRAFTS
// CLOSE: 0x0096f0c3 score 13
bool cGZDBSegmentPackedFile::Slot38_ad8488(uint32_t outCount, uint32_t outSize)
{
    uint32_t* count = OB_PTR(uint32_t, outCount);
    uint32_t* size = OB_PTR(uint32_t, outSize);
    *count = 0;
    *size = 0;
    if (mnFlags & 3) {
        Node_gzdbpf* end = static_cast<Node_gzdbpf*>(mpMap);
        for (Node_gzdbpf* n = end->mpFirst; n != end; n = Fn0040d4c0(n)) {
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
    Guard_gzdbpf guard(LOCK_GZDBPF);
    Cursor_gzdbpf* cursor = reinterpret_cast<Cursor_gzdbpf*>(reinterpret_cast<char*>(this) + 0xd8);
    uint32_t before = cursor->mnValue;
    uint32_t after = cursor->Fn0097989f(a);
    return after != before;
}
#endif


#ifdef OB_DRAFTS
// CLOSE: 0x0096f7cd score 49
uint32_t cGZDBSegmentPackedFile::Slot18_ad8488(uint32_t keyAddress)
{
    Key_gzdbpf key;
    Guard_gzdbpf guard(LOCK_GZDBPF);
    uint32_t r = 0xffffffff;
    if (mnFlags & 3) {
        key = *OB_PTR(const Key_gzdbpf, keyAddress);
        Entry_gzdbpf* e = static_cast<Index_gzdbpf*>(mpIndex)->Find(&key);
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
    Key_gzdbpf key;
    Guard_gzdbpf guard(LOCK_GZDBPF);
    uint32_t r = 0xffffffff;
    if (mnFlags & 3) {
        key = *OB_PTR(const Key_gzdbpf, keyAddress);
        Entry_gzdbpf* e = static_cast<Index_gzdbpf*>(mpIndex)->Find(&key);
        if (e) {
            r = e->mn10;
        }
    }
    return r;
}
#endif


#ifdef OB_DRAFTS
// CLOSE: 0x00970030 score 13
uint32_t cGZDBSegmentPackedFile::Fn00970030(uint32_t key)
{
    Found_gzdbpf found;
    reinterpret_cast<Table_gzdbpf*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, key);
    uint32_t r = 0xffffffff;
    if (found.mpNode) {
        r = static_cast<Entry_gzdbpf*>(found.mpNode)->mn10;
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096fa30 score 13
bool cGZDBSegmentPackedFile::Slot32_ad8488(uint32_t key)
{
    Guard_gzdbpf guard(LOCK_GZDBPF);
    Found_gzdbpf found;
    reinterpret_cast<Table_gzdbpf*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, key);
    return found.mpNode != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096fde2 score 6
bool cGZDBSegmentPackedFile::Slot36_ad8488(uint32_t a, uint32_t b)
{
    if (a && b) {
        InsertResult_gzdbpf result;
        Pair_gzdbpf pair;
        pair.a = a;
        pair.b = b;
        reinterpret_cast<Map_gzdbpf*>(reinterpret_cast<char*>(this) + 0x14c)->Insert(&result, &pair);
        mbDirty = true;
        return true;
    }
    return false;
}
#endif



#ifdef OB_DRAFTS
// CLOSE: 0x009714ff score 8
bool cGZDBSegmentPackedFile::Slot30_ad8488(uint32_t key, bool insert)
{
    Guard_gzdbpf guard(LOCK_GZDBPF);
    Set_gzdbpf* set = reinterpret_cast<Set_gzdbpf*>(reinterpret_cast<char*>(this) + 0x188);
    if (insert) {
        SetResult_gzdbpf result;
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
    Guard_gzdbpf guard(LOCK_GZDBPF);
    Set_gzdbpf* set = reinterpret_cast<Set_gzdbpf*>(reinterpret_cast<char*>(this) + 0x19c);
    if (insert) {
        SetResult_gzdbpf result;
        set->Insert(&result, &key);
    } else {
        set->Erase(&key);
    }
    return false;
}
#endif


// Fields reached by offset where no name is known yet.
#define U32_GZDBPF(off) (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) + (off)))
#define U8_GZDBPF(off) (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(this) + (off)))

// GLOBAL: 0x00b6363c
extern uint32_t gB6363c;

// STUB: 0x009efb59
uint32_t Fn009efb59(uint32_t zero);


#ifdef OB_DRAFTS
// CLOSE: 0x0096e407 score 6
bool cGZDBSegmentPackedFile::Fn0096e407()
{
    bool ok = false;
    if (U32_GZDBPF(0xe4) == gB6363c && U32_GZDBPF(0xe8) <= 1) {
        Inner_gzdbpf* inner = INNER_GZDBPF;
        if (U32_GZDBPF(0x108) < 0x7ffffff) {
            if (U32_GZDBPF(0x10c) < inner->Fn07_gzdbpf()) {
                if (U32_GZDBPF(0x110) + U32_GZDBPF(0x10c) <= inner->Fn07_gzdbpf()) {
                    if (U32_GZDBPF(0x114) < 0x7ffffff) {
                        if (U32_GZDBPF(0x118) < inner->Fn07_gzdbpf()) {
                            if (U32_GZDBPF(0x11c) + U32_GZDBPF(0x118) <= inner->Fn07_gzdbpf()) {
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
    uint32_t n = U32_GZDBPF(0x118);
    if (n != 0) {
        if (n >= 0x60 && n >= INNER_GZDBPF->Fn07_gzdbpf()) {
            ok = false;
        }
        if (U32_GZDBPF(0x114) != (U32_GZDBPF(0x11c) >> 3)) {
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
    uint32_t* header = &U32_GZDBPF(0xe4);
    for (int i = 0; i < 24; ++i) {
        header[i] = 0;
    }
    header[0] = gB6363c;
    U32_GZDBPF(0xf0) = mnCc;
    U32_GZDBPF(0xe8) = 1;
    U32_GZDBPF(0xec) = 0;
    U32_GZDBPF(0xf4) = mnD0;
    U32_GZDBPF(0xf8) = 0;
    U32_GZDBPF(0xfc) = Fn009efb59(0);
    U32_GZDBPF(0x100) = Fn009efb59(0);
    U32_GZDBPF(0x104) = 7;
    U32_GZDBPF(0x108) = 0;
    U32_GZDBPF(0x10c) = 0;
    U32_GZDBPF(0x110) = 0;
    U32_GZDBPF(0x114) = 0;
    U32_GZDBPF(0x118) = 0;
    U32_GZDBPF(0x11c) = 0;
    if (Fn0096e37b()) {
        INNER_GZDBPF->Fn08_gzdbpf(0x60);
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
            if (U32_GZDBPF(0x1c4) == 0) {
                U32_GZDBPF(0x1c4) = OB_ADDR(operator new(0x800));
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
struct RbNode_gzdbpf {
    uint32_t mnColor;
    RbNode_gzdbpf* mpParent;
    RbNode_gzdbpf* mpLeft;
    RbNode_gzdbpf* mpRight;
    uint32_t mnKey;
    uint32_t mnValue;
};

// The map object: its head node and the element count.
struct RbMap_gzdbpf {
    RbNode_gzdbpf* mpHead;
    uint32_t mnCount;
    void Fn0096eaf5(RbNode_gzdbpf* node);
    void Fn0096ed93();
    // STUB: 0x0096f2ab
    void Fn0096f2ab(RbNode_gzdbpf** out, uint32_t flag, RbNode_gzdbpf* where, RbNode_gzdbpf* parent, const Pair_gzdbpf* value);
    RbNode_gzdbpf** Fn0096f5cd(RbNode_gzdbpf** out, const Pair_gzdbpf* value);
};

// STUB: 0x0040d500
RbNode_gzdbpf* Fn0040d500(RbNode_gzdbpf* node);


#ifdef OB_DRAFTS
// CLOSE: 0x0096ef83 score 111
bool cGZDBSegmentPackedFile::Fn0096ef83()
{
    bool ok = true;
    if ((mnFlags & 3) && (mnFlags & 2) && mbDirty) {
        uint32_t wanted = U32_GZDBPF(0x150);
        if (wanted != U32_GZDBPF(0x114)) {
            ok = Slot36_ad8488(U32_GZDBPF(0x118), U32_GZDBPF(0x11c));
            if (ok) {
                if (wanted) {
                    U32_GZDBPF(0x11c) = wanted << 3;
                    ok = Slot35_ad8488(OB_ADDR(&U32_GZDBPF(0x118)), wanted << 3);
                }
                if (ok) {
                    if (wanted == 0) {
                        U32_GZDBPF(0x118) = 0;
                    } else {
                        U32_GZDBPF(0x11c) = wanted << 3;
                        U32_GZDBPF(0x114) = wanted;
                        uint32_t* table = static_cast<uint32_t*>(operator new(wanted << 3));
                        RbNode_gzdbpf* head = static_cast<RbNode_gzdbpf*>(mpMap);
                        uint32_t* out = table;
                        for (RbNode_gzdbpf* n = head->mpLeft; n != head; n = reinterpret_cast<RbNode_gzdbpf*>(Fn0040d4c0(reinterpret_cast<Node_gzdbpf*>(n)))) {
                            out[0] = n->mnKey;
                            out[1] = n->mnValue;
                            out += 2;
                        }
                        ok = WriteFileSpan(OB_ADDR(table), U32_GZDBPF(0x118), U32_GZDBPF(0x11c));
                        operator delete(table);
                    }
                }
            }
        } else {
            U32_GZDBPF(0x118) = 0;
            U32_GZDBPF(0x114) = 0;
            U32_GZDBPF(0x11c) = 0;
        }
        if (ok) {
            mbDirty = false;
        }
    }
    return ok;
}
#endif


#ifdef OB_DRAFTS
// CLOSE: 0x0096f12d score 85
void Map_gzdbpf::Fn0096f12d(InsertResult_gzdbpf* out, const Pair_gzdbpf* pair)
{
    RbMap_gzdbpf* map = reinterpret_cast<RbMap_gzdbpf*>(this);
    RbNode_gzdbpf* head = map->mpHead;
    RbNode_gzdbpf* parent = head;
    RbNode_gzdbpf* node = head->mpParent;
    bool left = true;
    while (node) {
        parent = node;
        left = pair->b < node->mnKey;
        node = left ? node->mpLeft : node->mpRight;
    }
    RbNode_gzdbpf* prev = parent;
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
struct HashNode_gzdbpf {
    HashNode_gzdbpf* mpNext;
    Key_gzdbpf mKey;
    uint32_t mnValue;
};
struct Hash_gzdbpf {
    uint32_t mPad0;
    HashNode_gzdbpf** mppBegin;
    HashNode_gzdbpf** mppEnd;
    uint32_t mPadC;
    uint32_t mnCount;
    // STUB: 0x0096edd3
    HashNode_gzdbpf* Fn0096edd3(const Key_gzdbpf* key);
    // STUB: 0x0096f614
    void Fn0096f614(uint32_t count);
    void* Fn0097005c(void* out, const Key_gzdbpf* key);
    HashNode_gzdbpf* Fn0096eea9(const Key_gzdbpf* key);
    uint32_t Fn0097e4b6(const Key_gzdbpf* key);
    // STUB: 0x0096f209
    void Fn0096f209(void* out, const Key_gzdbpf* key);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096f209 score 21
void Hash_gzdbpf::Fn0096f209(void* out, const Key_gzdbpf* key)
{
    uint32_t* result = static_cast<uint32_t*>(out);
    uint32_t bucket = key->c % static_cast<uint32_t>(mppEnd - mppBegin);
    HashNode_gzdbpf* first = mppBegin[bucket];
    for (HashNode_gzdbpf* n = first; n; n = n->mpNext) {
        if (n->mKey.Equals(key)) {
            result[0] = OB_ADDR(n);
            result[1] = OB_ADDR(this);
            reinterpret_cast<uint8_t*>(result)[8] = 0;
            return;
        }
    }
    HashNode_gzdbpf* made = Fn0096edd3(key);
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
        if (U32_GZDBPF(0xdc) != 0) {
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
    if ((mnFlags & 3) && (mnFlags & 2) && U8_GZDBPF(0x28)) {
        uint32_t count = *reinterpret_cast<uint32_t*>(static_cast<char*>(mpIndex) + 0x10);
        uint32_t bytes = count * 20;
        uint32_t current = U32_GZDBPF(0x110);
        if (bytes == current) {
            // same size: rewrite in place
        }
        if (current) {
            ok = Slot36_ad8488(U32_GZDBPF(0x10c), current);
        }
        U32_GZDBPF(0x108) = count;
        U32_GZDBPF(0x110) = bytes;
        if (bytes) {
            ok = Slot35_ad8488(OB_ADDR(&U32_GZDBPF(0x10c)), bytes);
            if (ok) {
                uint32_t* out = static_cast<uint32_t*>(operator new(bytes));
                ok = WriteFileSpan(OB_ADDR(out), U32_GZDBPF(0x10c), bytes);
                operator delete(out);
            }
        }
        U8_GZDBPF(0x28) = 0;
    }
    return ok;
}
#endif

// A std::vector of words: begin, end, capacity.
struct Vec_gzdbpf {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x0096f6be
    uint32_t* Fn0096f6be(uint32_t count, uint32_t* from, uint32_t* to);
    void Reserve_gzdbpf(uint32_t count);
};

// STUB: 0x00459d80
uint32_t* Fn00459d80(uint32_t count);

// STUB: 0x0090cf63
void StlDelete_gzdbpf(void* p);

#ifdef OB_DRAFTS
// CLOSE: 0x00970080 score 53
void Vec_gzdbpf::Reserve_gzdbpf(uint32_t count)
{
    if (static_cast<uint32_t>(mpCap - mpBegin) < count) {
        uint32_t used = mpEnd - mpBegin;
        uint32_t* fresh;
        if (mpBegin) {
            fresh = Fn0096f6be(count, mpBegin, mpEnd);
            if (mpBegin) {
                StlDelete_gzdbpf(mpBegin);
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


#ifdef OB_DRAFTS
// CLOSE: 0x0096fc95 score 38
bool cGZDBSegmentPackedFile::Fn0096fc95()
{
    bool ok = true;
    uint32_t size = INNER_GZDBPF->Fn07_gzdbpf();
    Index_gzdbpf* index = static_cast<Index_gzdbpf*>(mpIndex);
    (void)index;
    for (RbNode_gzdbpf* n = static_cast<RbNode_gzdbpf*>(mpIndex); n; n = 0) {
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
    if (U32_GZDBPF(0x114) != 0) {
        if (INNER_GZDBPF->Fn0c_gzdbpf(mnC0 + U32_GZDBPF(0x118)) == mnC0 + U32_GZDBPF(0x118)) {
            uint32_t count = U32_GZDBPF(0x114);
            uint32_t* table = static_cast<uint32_t*>(operator new(count << 3));
            if (INNER_GZDBPF->Fn0e_gzdbpf(OB_ADDR(table), U32_GZDBPF(0x114) << 3)) {
                uint32_t* p = table;
                for (uint32_t i = 0; i < U32_GZDBPF(0x114); ++i) {
                    Pair_gzdbpf pair;
                    InsertResult_gzdbpf result;
                    pair.a = p[0];
                    pair.b = p[1];
                    reinterpret_cast<Map_gzdbpf*>(reinterpret_cast<char*>(this) + 0x14c)->Insert(&result, &pair);
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
    if ((mnFlags & 3) && (mnFlags & 2) && U8_GZDBPF(0x184)) {
        uint32_t header[3];
        header[0] = 0xe86b1eef;
        header[1] = 0xe86b1eef;
        header[2] = 0x286b1f03;
        uint32_t count = U32_GZDBPF(0x1c0);
        uint32_t* buffer = static_cast<uint32_t*>(operator new(count << 4));
        uint32_t* out = buffer;
        
        ok = Slot20_ad8488(OB_ADDR(header), OB_ADDR(buffer), count << 4);
        if (ok) {
            U8_GZDBPF(0x184) = 0;
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
        const Key_gzdbpf* k = static_cast<const Key_gzdbpf*>(key);
        if (k->a != 0xe86b1eef) {
            if (!mbFlag185) {
                if (U32_GZDBPF(0x198) != 0) {
                    if (reinterpret_cast<Set_gzdbpf*>(reinterpret_cast<char*>(this) + 0x188)->Find_gzdbpf(&k->a)) {
                        return false;
                    }
                }
                if (U32_GZDBPF(0x1ac) != 0) {
                    if (reinterpret_cast<Set_gzdbpf*>(reinterpret_cast<char*>(this) + 0x19c)->Find_gzdbpf(&k->b)) {
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
    const Key_gzdbpf* source = static_cast<const Key_gzdbpf*>(keyPointer);
    Found_gzdbpf found;
    reinterpret_cast<Table_gzdbpf*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, OB_ADDR(source));
    if (found.mpNode) {
        Key_gzdbpf key = *source;
        Entry_gzdbpf* e = static_cast<Index_gzdbpf*>(mpIndex)->Find(&key);
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
    Guard_gzdbpf guard(LOCK_GZDBPF);
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
struct RecBase_gzdbpf {
    uint32_t w[0x18];
    // STUB: 0x00975cb5
    void Fn00975cb5(uint32_t a, void* b, uint32_t c);
    // the record constructors (cUnk00ad7ee8, cUnk00ad80e8, cUnk00ad82e8) as the drafts call them
    // STUB: 0x0096d859
    RecBase_gzdbpf* Fn0096d859(uint32_t kind, uint32_t a, void* b, uint32_t c);
    // STUB: 0x0096d8d0
    RecBase_gzdbpf* Fn0096d8d0(uint32_t a, uint32_t b, uint32_t c, void* d, uint32_t e);
    // STUB: 0x0096d9d1
    RecBase_gzdbpf* Fn0096d9d1(uint32_t* a, uint32_t b, uint32_t c, void* d, uint32_t e);
    RecBase_gzdbpf* Fn0096da30(uint32_t a, uint32_t b, uint32_t c, void* d, uint32_t e);
    RecBase_gzdbpf* Fn00970e67(const void* data, uint32_t length, uint32_t c, void* d, uint32_t e);
    RecBase_gzdbpf* Fn00970c4d(uint32_t data, uint32_t length, const Key_gzdbpf* key, void* d, uint32_t e);
    // STUB: 0x00478aa0
    void Fn00478aa0(uint32_t length);
};

// Not hooked: run in the game, a constructor installs our stand-in vtables (their destructors are not the original's
// yet) in place of the original's.




// An object with a size field and two helpers (a string-like buffer).
struct CountNode_gzdbpf {
    uint32_t mPad[2];
    int32_t mnCount;
};
struct EraseArg_gzdbpf {
    CountNode_gzdbpf* mpNode;
    void* mpTable;
};
struct Buffer_gzdbpf {
    uint32_t w[8];
    // STUB: 0x0058efe0
    CountNode_gzdbpf* Find(const int32_t* key);
    // STUB: 0x0092dc3a
    void Erase(EraseArg_gzdbpf where);
    // STUB: 0x005e06d0
    void* Fn005e06d0(void* out, const void* pair);
    // STUB: 0x004f0940
    void Fn004f0940(uint32_t count);
    // STUB: 0x005e04a0
    void Fn005e04a0(uint32_t a, uint32_t b);
    uint32_t Fn005e06d0(uint32_t a, uint32_t b);
};


// A second container with the same insert shape.
struct Buffer2_gzdbpf {
    uint32_t w[8];
    // STUB: 0x0096f614
    void Fn0096f614(uint32_t count);
    // STUB: 0x0097c0c5
    void Fn0097c0c5(uint32_t a, uint32_t b);
    uint32_t Fn0097c51a(uint32_t a, uint32_t b);
};


#ifdef OB_DRAFTS
// CLOSE: 0x0096eea9 score 14
HashNode_gzdbpf* Hash_gzdbpf::Fn0096eea9(const Key_gzdbpf* key)
{
    uint32_t bucket = key->c % static_cast<uint32_t>(mppEnd - mppBegin);
    HashNode_gzdbpf* n = mppBegin[bucket];
    for (; n; n = n->mpNext) {
        if (n->mKey.Equals(key)) {
            break;
        }
    }
    return n;
}
#endif




#ifdef OB_DRAFTS
// CLOSE: 0x0096f5cd score 46
RbNode_gzdbpf** RbMap_gzdbpf::Fn0096f5cd(RbNode_gzdbpf** out, const Pair_gzdbpf* value)
{
    RbNode_gzdbpf* parent = mpHead;
    RbNode_gzdbpf* node = parent->mpParent;
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
void RbMap_gzdbpf::Fn0096f2ab(RbNode_gzdbpf** out, uint32_t flag, RbNode_gzdbpf* where, RbNode_gzdbpf* parent, const Pair_gzdbpf* value)
{
    RbNode_gzdbpf* created = 0;
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



// The primary view of the packed file seen from a pointer to its second base; slot 62 is called.
struct Primary_gzdbpf {
    virtual void Pad00_gzdbpf();
    virtual void Pad01_gzdbpf();
    virtual void Pad02_gzdbpf();
    virtual void Pad03_gzdbpf();
    virtual void Pad04_gzdbpf();
    virtual void Pad05_gzdbpf();
    virtual void Pad06_gzdbpf();
    virtual void Pad07_gzdbpf();
    virtual void Pad08_gzdbpf();
    virtual void Pad09_gzdbpf();
    virtual void Pad0a_gzdbpf();
    virtual void Pad0b_gzdbpf();
    virtual void Pad0c_gzdbpf();
    virtual void Pad0d_gzdbpf();
    virtual void Pad0e_gzdbpf();
    virtual void Pad0f_gzdbpf();
    virtual void Pad10_gzdbpf();
    virtual void Pad11_gzdbpf();
    virtual void Pad12_gzdbpf();
    virtual void Pad13_gzdbpf();
    virtual void Pad14_gzdbpf();
    virtual void Pad15_gzdbpf();
    virtual void Pad16_gzdbpf();
    virtual void Pad17_gzdbpf();
    virtual void Pad18_gzdbpf();
    virtual void Pad19_gzdbpf();
    virtual void Pad1a_gzdbpf();
    virtual void Pad1b_gzdbpf();
    virtual void Pad1c_gzdbpf();
    virtual void Pad1d_gzdbpf();
    virtual void Pad1e_gzdbpf();
    virtual void Pad1f_gzdbpf();
    virtual void Pad20_gzdbpf();
    virtual void Pad21_gzdbpf();
    virtual void Pad22_gzdbpf();
    virtual void Pad23_gzdbpf();
    virtual void Pad24_gzdbpf();
    virtual void Pad25_gzdbpf();
    virtual void Pad26_gzdbpf();
    virtual void Pad27_gzdbpf();
    virtual void Pad28_gzdbpf();
    virtual void Pad29_gzdbpf();
    virtual void Pad2a_gzdbpf();
    virtual void Pad2b_gzdbpf();
    virtual void Pad2c_gzdbpf();
    virtual void Pad2d_gzdbpf();
    virtual void Pad2e_gzdbpf();
    virtual void Pad2f_gzdbpf();
    virtual void Pad30_gzdbpf();
    virtual void Pad31_gzdbpf();
    virtual void Pad32_gzdbpf();
    virtual void Pad33_gzdbpf();
    virtual void Pad34_gzdbpf();
    virtual void Pad35_gzdbpf();
    virtual void Pad36_gzdbpf();
    virtual void Pad37_gzdbpf();
    virtual void Pad38_gzdbpf();
    virtual void Pad39_gzdbpf();
    virtual void Pad3a_gzdbpf();
    virtual void Pad3b_gzdbpf();
    virtual void Pad3c_gzdbpf();
    virtual void Pad3d_gzdbpf();
    virtual void Fn3e_gzdbpf();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096e363 score 3
void Fn0096e363(void* second)
{
    Primary_gzdbpf* primary = second ? reinterpret_cast<Primary_gzdbpf*>(static_cast<char*>(second) - 4) : 0;
    primary->Fn3e_gzdbpf();
}
#endif

// The compressor used to size and pack records.
struct Compressor_gzdbpf {
    uint32_t w[8];
    // STUB: 0x00a6e193
    Compressor_gzdbpf();
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
        Compressor_gzdbpf compressor;
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
struct File_gzdbpf {
    uint32_t w[26];
    // STUB: 0x00918c00
    File_gzdbpf(cRZString* name);
    // STUB: 0x00919b00
    bool Open(uint32_t a, uint32_t b, uint32_t c);
    // STUB: 0x009188a5
    void Close();
    // STUB: 0x00918c70
    ~File_gzdbpf();
};

// A sink object: slot 3 receives (data, length); slot 5 gives a number for the temporary name.
struct Sink_gzdbpf {
    virtual void Pad0_gzdbpf();
    virtual void Pad1_gzdbpf();
    virtual void Pad2_gzdbpf();
    virtual void Pad3_gzdbpf();
    virtual void Pad4_gzdbpf();
    virtual uint32_t Fn5_gzdbpf(uint32_t seed, uint32_t counter);
};


// STUB: 0x009f19b0
void* Fn009f19b0(void* to, const void* from, uint32_t count);

#ifdef OB_DRAFTS
// CLOSE: 0x00970e67 score 15
RecBase_gzdbpf* RecBase_gzdbpf::Fn00970e67(const void* data, uint32_t length, uint32_t c, void* d, uint32_t e)
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
    if (U8_GZDBPF(0x15a)) {
        Buffer_gzdbpf* types = reinterpret_cast<Buffer_gzdbpf*>(reinterpret_cast<char*>(this) + 0x15c);
        int32_t typeKey = type;
        CountNode_gzdbpf* node = types->Find(&typeKey);
        if (node) {
            if (add) {
                ++node->mnCount;
            } else if (node->mnCount > 1) {
                --node->mnCount;
            } else {
                EraseArg_gzdbpf where;
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
        if (U8_GZDBPF(0x15a)) {
            Buffer_gzdbpf* groups = reinterpret_cast<Buffer_gzdbpf*>(reinterpret_cast<char*>(this) + 0x170);
            int32_t groupKey = group;
            node = groups->Find(&groupKey);
            if (node) {
                if (add) {
                    ++node->mnCount;
                } else if (node->mnCount > 1) {
                    --node->mnCount;
                } else {
                    EraseArg_gzdbpf where;
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
    Buffer2_gzdbpf* table = reinterpret_cast<Buffer2_gzdbpf*>(reinterpret_cast<char*>(this) + 0x1b0);
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


// A file used for large records (a temporary file object, 0x80 bytes).
struct TempFile_gzdbpf {
    virtual void Pad0_gzdbpf();
    virtual void Pad1_gzdbpf();
    virtual void Pad2_gzdbpf();
    virtual void Pad3_gzdbpf();
    virtual void Pad4_gzdbpf();
    virtual void Pad5_gzdbpf();
    virtual void Pad6_gzdbpf();
    virtual void Pad7_gzdbpf();
    virtual void Pad8_gzdbpf();
    virtual void Pad9_gzdbpf();
    virtual void Pad10_gzdbpf();
    virtual void Pad11_gzdbpf();
    virtual bool Open_gzdbpf(uint32_t a, uint32_t b, uint32_t c);
    virtual void Pad13_gzdbpf();
    virtual void Pad14_gzdbpf();
    virtual void Pad15_gzdbpf();
    virtual bool Close_gzdbpf();
    virtual void Pad17_gzdbpf();
    virtual void Pad18_gzdbpf();
    virtual void Pad19_gzdbpf();
    virtual void Pad20_gzdbpf();
    virtual void Pad21_gzdbpf();
    virtual void Pad22_gzdbpf();
    virtual void Pad23_gzdbpf();
    virtual void Pad24_gzdbpf();
    virtual uint32_t Fn18_gzdbpf();
};

// STUB: 0x0091a497
bool Fn0091a497(cRZString* name, uint32_t flag);

// STUB: 0x0091a1a6
void Fn0091a1a6(uint32_t value);

#ifdef OB_DRAFTS
// CLOSE: 0x00970c4d score 158
RecBase_gzdbpf* RecBase_gzdbpf::Fn00970c4d(uint32_t data, uint32_t length, const Key_gzdbpf* key, void* d, uint32_t e)
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
    reinterpret_cast<Vec_gzdbpf*>(&w[0x11])->Reserve_gzdbpf(0x80);
    if (length) {
        if (length > 0x1e8480 && !reinterpret_cast<uint8_t*>(w)[0x58]) {
            cRZString name;
            reinterpret_cast<uint8_t*>(w)[0x58] = 1;
            name.Sprintf("%s", key);
            if (Fn0091a497(&name, 0)) {
                TempFile_gzdbpf* file = static_cast<TempFile_gzdbpf*>(operator new(0x80));
                w[0x15] = OB_ADDR(file);
                if (file->Open_gzdbpf(3, 3, 1)) {
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
                        file->Close_gzdbpf();
                        Fn0091a1a6(file->Fn18_gzdbpf());
                        w[0x15] = 0;
                    }
                }
            }
        }
        if (w[0x15] == 0) {
            if (w[6]) {
                reinterpret_cast<Vec_gzdbpf*>(&w[0x11])->Reserve_gzdbpf(length);
            }
        }
    }
    return this;
}
#endif


// The object behind a cursor entry (second base at +4, flags from its slot 4).
struct SubObject_gzdbpf {
    virtual void Pad0_gzdbpf();
    virtual void Pad1_gzdbpf();
    virtual void Pad2_gzdbpf();
    virtual void Pad3_gzdbpf();
    virtual uint32_t GetFlags_gzdbpf();
};

// A serial record adapter (vtable 0x00ad...), built around a record.
struct SerialRec_gzdbpf {
    uint32_t w[4];
    // STUB: 0x0096ec7c
    SerialRec_gzdbpf(void* record);
};
struct Counted_gzdbpf {
    virtual void Pad0_gzdbpf();
    virtual void AddRef_gzdbpf();
};



#ifdef OB_DRAFTS
// CLOSE: 0x0096f4ce score 99
bool cGZDBSegmentPackedFile::Slot35_ad8488(uint32_t outPosition, uint32_t size)
{
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        uint32_t end = INNER_GZDBPF->Fn07_gzdbpf();
        RbNode_gzdbpf* head = static_cast<RbNode_gzdbpf*>(mpMap);
        RbNode_gzdbpf* n = head->mpLeft;
        if (mn144 & 2) {
            while (n != head) {
                if (n->mnValue >= size) {
                    break;
                }
                n = reinterpret_cast<RbNode_gzdbpf*>(Fn0040d4c0(reinterpret_cast<Node_gzdbpf*>(n)));
            }
        } else {
            n = head;
        }
        if (n != head) {
            uint32_t position = n->mnKey;
            uint32_t rest = n->mnValue - size;
            *OB_PTR(uint32_t, outPosition) = position;
            RbMap_gzdbpf* map = reinterpret_cast<RbMap_gzdbpf*>(reinterpret_cast<char*>(this) + 0x14c);
            (void)map;
            Slot36_ad8488(position + size, rest);
            ok = true;
        } else {
            *OB_PTR(uint32_t, outPosition) = end;
            ok = INNER_GZDBPF->Fn08_gzdbpf(end + size);
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f879 score 61
uint32_t cGZDBSegmentPackedFile::Slot22_ad8488()
{
    Guard_gzdbpf guard(LOCK_GZDBPF);
    uint32_t r = U32_GZDBPF(0x16c);
    if (r == 0) {
        RbNode_gzdbpf* head = static_cast<RbNode_gzdbpf*>(static_cast<void*>(*reinterpret_cast<void**>(&U32_GZDBPF(0xd8))));
        uint32_t best = 0;
        for (RbNode_gzdbpf* n = head ? head->mpLeft : 0; n && n != head; n = reinterpret_cast<RbNode_gzdbpf*>(Fn0040d4c0(reinterpret_cast<Node_gzdbpf*>(n)))) {
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
    Guard_gzdbpf guard(LOCK_GZDBPF);
    uint32_t r = U32_GZDBPF(0x180);
    if (r == 0) {
        RbNode_gzdbpf* head = static_cast<RbNode_gzdbpf*>(static_cast<void*>(*reinterpret_cast<void**>(&U32_GZDBPF(0xd8))));
        uint32_t best = 0;
        for (RbNode_gzdbpf* n = head ? head->mpLeft : 0; n && n != head; n = reinterpret_cast<RbNode_gzdbpf*>(Fn0040d4c0(reinterpret_cast<Node_gzdbpf*>(n)))) {
            ++best;
        }
        r = best;
    }
    return r;
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

// STUB: 0x00919672
bool Fullpath(cRZString& out, const cRZString& in);

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
        File_gzdbpf file(reinterpret_cast<cRZString*>(OB_PTR(void, path)));
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
    Guard_gzdbpf guard(LOCK_GZDBPF);
    uint32_t r = 0xffffffff;
    if ((mnFlags & 3) && (mnFlags & 1)) {
        Cursor_gzdbpf* cursor = reinterpret_cast<Cursor_gzdbpf*>(reinterpret_cast<char*>(this) + 0xd8);
        if (mnFlags & 2) {
            uint32_t entry = cursor->Fn0097989f(keyAddress);
            if (entry != cursor->mnValue) {
                SubObject_gzdbpf* sub = static_cast<SubObject_gzdbpf*>(OB_PTR(CursorEntry_gzdbpf, entry)->mpSub);
                if (sub->GetFlags_gzdbpf() & 2) {
                    *OB_PTR(uint32_t, outSize) = 0;
                    return 0xffffffff;
                }
            }
        }
        Key_gzdbpf key = *OB_PTR(const Key_gzdbpf, keyAddress);
        Entry_gzdbpf* e = static_cast<Index_gzdbpf*>(mpIndex)->Find(&key);
        if (e) {
            if (buffer) {
                uint32_t want = e->mn14;
                uint32_t have = *OB_PTR(uint32_t, outSize);
                uint32_t take = want < have ? want : have;
                if (INNER_GZDBPF->Fn0c_gzdbpf(mnC0 + e->mn10) == mnC0 + e->mn10) {
                    if (INNER_GZDBPF->Fn0e_gzdbpf(buffer, take)) {
                        r = take;
                    }
                }
                *OB_PTR(uint32_t, outSize) = r;
            } else {
                Found_gzdbpf found;
                reinterpret_cast<Table_gzdbpf*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, keyAddress);
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
// CLOSE: 0x00971178 score 156
bool cGZDBSegmentPackedFile::DoOpenRecordForWrite(uint32_t keyAddress, uint32_t out)
{
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        Cursor_gzdbpf* cursor = reinterpret_cast<Cursor_gzdbpf*>(reinterpret_cast<char*>(this) + 0xd8);
        if (cursor->Fn0097989f(keyAddress) == cursor->mnValue) {
            Key_gzdbpf key = *OB_PTR(const Key_gzdbpf, keyAddress);
            Entry_gzdbpf* e = static_cast<Index_gzdbpf*>(mpIndex)->Find(&key);
            if (e) {
                Found_gzdbpf found;
                reinterpret_cast<Table_gzdbpf*>(reinterpret_cast<char*>(this) + 0x1b0)->Find(&found, keyAddress);
                RecBase_gzdbpf* record = static_cast<RecBase_gzdbpf*>(operator new(0x5c));
                if (found.mpNode) {
                    uint32_t data = 0;
                    uint32_t length = 0;
                    if (!DecompressRecord(e->mn10, e->mn14, &data, &length)) {
                        return false;
                    }
                    record->Fn00970e67(OB_PTR(void, data), length, keyAddress, this, 1);
                    operator delete(OB_PTR(void, data));
                } else {
                    record->Fn00970c4d(e->mn10, e->mn14, OB_PTR(const Key_gzdbpf, keyAddress), this, 1);
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
    Guard_gzdbpf guard(LOCK_GZDBPF);
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
// CLOSE: 0x00971587 score 42
void cGZDBSegmentPackedFile::Slot33_ad8488(uint32_t keyAddress, uint32_t set, uint32_t value)
{
    Guard_gzdbpf guard(LOCK_GZDBPF);
    Buffer2_gzdbpf* table = reinterpret_cast<Buffer2_gzdbpf*>(reinterpret_cast<char*>(this) + 0x1b0);
    Found_gzdbpf found;
    reinterpret_cast<Table_gzdbpf*>(table)->Find(&found, keyAddress);
    bool exists = found.mpNode != 0;
    if (set & 0xff) {
        if (exists) {
            static_cast<Entry_gzdbpf*>(found.mpNode)->mn10 = value;
        } else {
            uint32_t record[5];
            const Key_gzdbpf* key = OB_PTR(const Key_gzdbpf, keyAddress);
            record[0] = key->a;
            record[1] = key->b;
            record[2] = key->c;
            record[3] = value;
            uint32_t out[3];
            table->Fn0097c51a(OB_ADDR(out), OB_ADDR(record));
        }
    } else if (exists) {
        reinterpret_cast<Hash_gzdbpf*>(table)->Fn0097e4b6(OB_PTR(const Key_gzdbpf, keyAddress));
    }
    mbFlag184 = true;
}
#endif




#ifdef OB_DRAFTS
// CLOSE: 0x00971fe2 score 96
uint32_t cGZDBSegmentPackedFile::Slot20_ad8488(uint32_t keyAddress, uint32_t data, uint32_t size)
{
    Guard_gzdbpf guard(LOCK_GZDBPF);
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        Cursor_gzdbpf* cursor = reinterpret_cast<Cursor_gzdbpf*>(reinterpret_cast<char*>(this) + 0xd8);
        if (cursor->Fn0097989f(keyAddress) == cursor->mnValue) {
            Key_gzdbpf key = *OB_PTR(const Key_gzdbpf, keyAddress);
            Entry_gzdbpf* e = static_cast<Index_gzdbpf*>(mpIndex)->Find(&key);
            if (e) {
                uint32_t oldPosition = e->mn10;
                uint32_t oldLength = e->mn14;
                const Key_gzdbpf* k = OB_PTR(const Key_gzdbpf, keyAddress);
                IncrementTypeAndGroupUse(k->a, k->b, false);
                Slot33_ad8488(keyAddress, 0, 0);
                Fn0097c221(mpIndex, e, 0);
                Slot36_ad8488(oldPosition, oldLength);
                U8_GZDBPF(0x28) = 1;
            }
            uint32_t position = 0;
            if (Slot35_ad8488(OB_ADDR(&position), size)) {
                if (WriteFileSpan(data, position, size)) {
                    uint32_t out[3];
                    static_cast<Hash_gzdbpf*>(mpIndex)->Fn0097005c(out, OB_PTR(const Key_gzdbpf, keyAddress));
                    const Key_gzdbpf* k2 = OB_PTR(const Key_gzdbpf, keyAddress);
                    IncrementTypeAndGroupUse(k2->a, k2->b, true);
                    U8_GZDBPF(0x28) = 1;
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


#ifdef OB_DRAFTS
// CLOSE: 0x00972542 score 76
uint32_t cGZDBSegmentPackedFile::Slot25_ad8488(uint32_t path, uint32_t a, uint32_t b, uint32_t c)
{
    Guard_gzdbpf guard(LOCK_GZDBPF);
    uint32_t r = 0xffffffff;
    void* memory = operator new(0x1c8);
    cGZDBSegmentPackedFile* other = static_cast<cGZDBSegmentPackedFile*>(memory ?  static_cast<cGZDBSegmentPackedFile*>(memory)->Fn0097212d() : 0);
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
    Guard_gzdbpf guard(LOCK_GZDBPF);
    const Key_gzdbpf* k = OB_PTR(const Key_gzdbpf, keyAddress);
    bool ok = false;
    if ((mnFlags & 3) && (mnFlags & 2)) {
        Cursor_gzdbpf* cursor = reinterpret_cast<Cursor_gzdbpf*>(reinterpret_cast<char*>(this) + 0xd8);
        if (cursor->Fn0097989f(keyAddress) == cursor->mnValue) {
            Key_gzdbpf key = *OB_PTR(const Key_gzdbpf, keyAddress);
            Entry_gzdbpf* e = static_cast<Index_gzdbpf*>(mpIndex)->Find(&key);
            if (e) {
                uint32_t oldPosition = e->mn10;
                uint32_t oldLength = e->mn14;
                IncrementTypeAndGroupUse(k->a, k->b, false);
                Slot33_ad8488(keyAddress, 0, 0);
                Fn0097c221(mpIndex, e, 0);
                Slot36_ad8488(oldPosition, oldLength);
                U8_GZDBPF(0x28) = 1;
            }
            File_gzdbpf file(reinterpret_cast<cRZString*>(OB_PTR(void, path)));
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
                                    static_cast<Hash_gzdbpf*>(mpIndex)->Fn0097005c(out, OB_PTR(const Key_gzdbpf, keyAddress));
                                    IncrementTypeAndGroupUse(k->a, k->b, true);
                                    Slot33_ad8488(keyAddress, 1, length);
                                    U8_GZDBPF(0x28) = 1;
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
                            static_cast<Hash_gzdbpf*>(mpIndex)->Fn0097005c(out, OB_PTR(const Key_gzdbpf, keyAddress));
                            IncrementTypeAndGroupUse(k->a, k->b, true);
                            U8_GZDBPF(0x28) = 1;
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
// CLOSE: 0x00971481 score 32
void cGZDBSegmentPackedFile::Slot24_ad8488(uint32_t enable)
{
    Guard_gzdbpf guard(LOCK_GZDBPF);
    if (U8_GZDBPF(0x15a) != static_cast<uint8_t>(enable)) {
        U8_GZDBPF(0x15a) = static_cast<uint8_t>(enable);
        Fn008eba60(&U32_GZDBPF(0x15c));
        Fn008eba60(&U32_GZDBPF(0x170));
        if (U8_GZDBPF(0x15a)) {
            void* it = 0;
            static_cast<Index_gzdbpf*>(mpIndex)->Begin_gzdbpf(&it);
            while (it) {
                const uint32_t* node = static_cast<const uint32_t*>(it);
                IncrementTypeAndGroupUse(node[1], node[2], true);
                static_cast<Index_gzdbpf*>(mpIndex)->Next_gzdbpf(&it);
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
        const Key_gzdbpf* k = static_cast<const Key_gzdbpf*>(keyPointer);
        Key_gzdbpf key = *k;
        Entry_gzdbpf* e = static_cast<Index_gzdbpf*>(mpIndex)->Find(&key);
        if (e) {
            uint32_t oldPosition = e->mn10;
            uint32_t oldLength = e->mn14;
            IncrementTypeAndGroupUse(k->a, k->b, false);
            Slot33_ad8488(keyAddress, 0, 0);
            Fn0097c221(mpIndex, e, 0);
            Slot36_ad8488(oldPosition, oldLength);
            U8_GZDBPF(0x28) = 1;
        }
        RecBase_gzdbpf* source = static_cast<RecBase_gzdbpf*>(record);
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
                        static_cast<Hash_gzdbpf*>(mpIndex)->Fn0097005c(out, k);
                        IncrementTypeAndGroupUse(k->a, k->b, true);
                        Slot33_ad8488(keyAddress, 1, length);
                        U8_GZDBPF(0x28) = 1;
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
                static_cast<Hash_gzdbpf*>(mpIndex)->Fn0097005c(out, k);
                IncrementTypeAndGroupUse(k->a, k->b, true);
                U8_GZDBPF(0x28) = 1;
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
    Guard_gzdbpf guard(LOCK_GZDBPF);
    bool ok = false;
    if (!U8_GZDBPF(0x159)) {
        U8_GZDBPF(0x159) = 1;
        if (mnFlags & 3) {
            if (U32_GZDBPF(0x150) == 0) {
                ok = true;
            }
            if (U32_GZDBPF(0x150) != 0 && (mnFlags & 2) && U32_GZDBPF(0xdc) == 0) {
                Slot35_ad8488(OB_ADDR(&U32_GZDBPF(0x118)), 0);
                cRZString backup(".bak");
                cRZString temp(".tmp");
                cRZString source;
                Fn0091a847(OB_ADDR(&U32_GZDBPF(0x2c)), &source);
                void* memory = operator new(0x1c8);
                cGZDBSegmentPackedFile* fresh = static_cast<cGZDBSegmentPackedFile*>(memory ?  static_cast<cGZDBSegmentPackedFile*>(memory)->Fn0097212d() : 0);
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
        U8_GZDBPF(0x159) = 0;
    }
    return ok;
}
#endif

// ---------------------------------------------------------------------------------------------------------------
// The helpers of the file: the node containers behind the index, and the in-memory record class cUnk00ad8628.

// STUB: 0x0090cf63
void StlDelete_gzdbpf(void* block);

#define W16_GZDBPF(off) (*reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(this) + (off)))
#define P32_GZDBPF(off) (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + (off)))

// A reference-counted object (only AddRef is used).
struct Unknown_gzdbpf {
    virtual void Pad0_gzdbpf();
    virtual uint32_t AddRef_gzdbpf();
    virtual uint32_t Release_gzdbpf();
};

// A holder of one counted pointer.
struct Holder_gzdbpf {
    Unknown_gzdbpf* mpObject;
    // STUB: 0x0096e773
    Holder_gzdbpf* Fn0096e773(Unknown_gzdbpf* object);
};

// FUNCTION: 0x0096e773
Holder_gzdbpf* Holder_gzdbpf::Fn0096e773(Unknown_gzdbpf* object)
{
    mpObject = object;
    if (object) {
        object->AddRef_gzdbpf();
    }
    return this;
}

// The iterator of the record map: moves to the next node.
struct Iterator_gzdbpf {
    void** mpNode;
    // STUB: 0x0097c1ea
    void** Advance();
    // STUB: 0x0096f5b7
    Iterator_gzdbpf* Fn0096f5b7();
};

// FUNCTION: 0x0096f5b7
Iterator_gzdbpf* Iterator_gzdbpf::Fn0096f5b7()
{
    void** next = static_cast<void**>(*mpNode);
    if (!next) {
        next = Advance();
    }
    mpNode = next;
    return this;
}

struct TreeNode_gzdbpf {
    uint32_t mnPad0;
    TreeNode_gzdbpf* mpParent;
    TreeNode_gzdbpf* mpLeft;
    TreeNode_gzdbpf* mpRight;
    uint32_t mnPad10;
    uint32_t mnKey;
};

// STUB: 0x0040d5e0
void Rebalance_gzdbpf(TreeNode_gzdbpf* node, TreeNode_gzdbpf** root);

// A tree header: the root pointer sits first, the count second.
struct Tree_gzdbpf {
    void* mpHeader;
    uint32_t mnCount;
    // STUB: 0x0096eac8
    void EraseFrom(void* node);
    // STUB: 0x0096ed6a
    void Fn0096ed6a();
    // STUB: 0x0096ed93
    void Fn0096ed93();
    // STUB: 0x0096f0ff
    void Fn0096f0ff();
    // STUB: 0x0096f116
    void Fn0096f116();
    // STUB: 0x009dbb99
    TreeNode_gzdbpf* CreateNode(const uint32_t* value);
    // STUB: 0x0096ee20
    void Fn0096ee20(TreeNode_gzdbpf** out, uint32_t addLeft, TreeNode_gzdbpf* where, const uint32_t* value, uint32_t addRight);
};


// FUNCTION: 0x0096eac8
void Tree_gzdbpf::EraseFrom(void* node)
{
    TreeNode_gzdbpf* n = static_cast<TreeNode_gzdbpf*>(node);
    while (n) {
        EraseFrom(n->mpRight);
        TreeNode_gzdbpf* left = n->mpLeft;
        StlDelete_gzdbpf(n);
        n = left;
    }
}

// FUNCTION: 0x0096ed6a
void Tree_gzdbpf::Fn0096ed6a()
{
    if (mnCount) {
        TreeNode_gzdbpf* header = static_cast<TreeNode_gzdbpf*>(mpHeader);
        EraseFrom(header->mpParent);
        header = static_cast<TreeNode_gzdbpf*>(mpHeader);
        header->mpLeft = header;
        header = static_cast<TreeNode_gzdbpf*>(mpHeader);
        header->mpParent = 0;
        header = static_cast<TreeNode_gzdbpf*>(mpHeader);
        header->mpRight = header;
        mnCount = 0;
    }
}

// FUNCTION: 0x0096f0ff
void Tree_gzdbpf::Fn0096f0ff()
{
    Fn0096ed6a();
    if (mpHeader) {
        StlDelete_gzdbpf(mpHeader);
    }
}

// FUNCTION: 0x0096f116
void Tree_gzdbpf::Fn0096f116()
{
    Fn0096ed93();
    if (mpHeader) {
        StlDelete_gzdbpf(mpHeader);
    }
}

// The pair stored in the index: a key and two values.
struct IndexPair_gzdbpf {
    Key_gzdbpf mKey;
    uint32_t mnPosition;
    uint32_t mnSize;
    // STUB: 0x0096e78b
    IndexPair_gzdbpf* Fn0096e78b(const IndexPair_gzdbpf* other);
};

// FUNCTION: 0x0096e78b
IndexPair_gzdbpf* IndexPair_gzdbpf::Fn0096e78b(const IndexPair_gzdbpf* other)
{
    mKey = other->mKey;
    mnPosition = other->mnPosition;
    mnSize = other->mnSize;
    return this;
}

// The cursor object returned by a table lookup.
// FUNCTION: 0x0096f290
Found_gzdbpf* Table_gzdbpf::Find(Found_gzdbpf* out, uint32_t key)
{
    out->mpNode = Lookup(key);
    out->mpOwner = this;
    return out;
}

// The view of an open stream (the file object at 0x54 of a record): only the used slots are named.
struct RecordFile_gzdbpf {
    virtual void Pad00_gzdbpf();
    virtual void Pad01_gzdbpf();
    virtual void Pad02_gzdbpf();
    virtual bool Open_gzdbpf(uint32_t a, uint32_t b, uint32_t c);
    virtual bool IsOpen_gzdbpf();
    virtual void Close_gzdbpf();
    virtual uint32_t Tell_gzdbpf();
    virtual uint32_t Size_gzdbpf();
    virtual bool SetSize_gzdbpf(uint32_t size);
    virtual void Pad09_gzdbpf();
    virtual void Pad0a_gzdbpf();
    virtual void Pad0b_gzdbpf();
    virtual void Seek_gzdbpf(uint32_t position);
    virtual void Pad0d_gzdbpf();
    virtual bool Read_gzdbpf(void* buffer, uint32_t length);
    virtual void Pad0f_gzdbpf();
    virtual bool Write_gzdbpf(const void* buffer, uint32_t length);
    virtual void Pad11_gzdbpf();
    virtual void Pad12_gzdbpf();
    virtual void Pad13_gzdbpf();
    virtual void Pad14_gzdbpf();
    virtual void Pad15_gzdbpf();
    virtual void Pad16_gzdbpf();
    virtual void Pad17_gzdbpf();
    virtual uint32_t Path_gzdbpf();
    virtual void Pad19_gzdbpf();
    virtual void Pad1a_gzdbpf();
    virtual void Pad1b_gzdbpf();
    virtual void Pad1c_gzdbpf();
    virtual void Pad1d_gzdbpf();
    virtual void Pad1e_gzdbpf();
    virtual void Pad1f_gzdbpf();
    virtual void Destroy_gzdbpf(uint32_t flag);
};

// The sink a record copies its bytes to (the second base of its owner): slot 0x2e takes (source, destination, length).
struct SinkOf_gzdbpf {
    virtual void Pad00_gzdbpf();
    virtual void Pad01_gzdbpf();
    virtual void Pad02_gzdbpf();
    virtual void Pad03_gzdbpf();
    virtual void Pad04_gzdbpf();
    virtual void Pad05_gzdbpf();
    virtual void Pad06_gzdbpf();
    virtual void Pad07_gzdbpf();
    virtual void Pad08_gzdbpf();
    virtual void Pad09_gzdbpf();
    virtual void Pad0a_gzdbpf();
    virtual void Pad0b_gzdbpf();
    virtual void Pad0c_gzdbpf();
    virtual void Pad0d_gzdbpf();
    virtual void Pad0e_gzdbpf();
    virtual void Pad0f_gzdbpf();
    virtual void Pad10_gzdbpf();
    virtual void Pad11_gzdbpf();
    virtual void Pad12_gzdbpf();
    virtual void Pad13_gzdbpf();
    virtual void Pad14_gzdbpf();
    virtual void Pad15_gzdbpf();
    virtual void Pad16_gzdbpf();
    virtual void Pad17_gzdbpf();
    virtual void Pad18_gzdbpf();
    virtual void Pad19_gzdbpf();
    virtual void Pad1a_gzdbpf();
    virtual void Pad1b_gzdbpf();
    virtual void Pad1c_gzdbpf();
    virtual void Pad1d_gzdbpf();
    virtual void Pad1e_gzdbpf();
    virtual void Pad1f_gzdbpf();
    virtual void Pad20_gzdbpf();
    virtual void Pad21_gzdbpf();
    virtual void Pad22_gzdbpf();
    virtual void Pad23_gzdbpf();
    virtual void Pad24_gzdbpf();
    virtual void Pad25_gzdbpf();
    virtual void Pad26_gzdbpf();
    virtual void Pad27_gzdbpf();
    virtual void Pad28_gzdbpf();
    virtual void Pad29_gzdbpf();
    virtual void Pad2a_gzdbpf();
    virtual void Pad2b_gzdbpf();
    virtual void Pad2c_gzdbpf();
    virtual void Pad2d_gzdbpf();
    virtual bool Copy_gzdbpf(const void* source, uint32_t destination, uint32_t length);
};

// The vector of bytes embedded at 0x44 of a record.
struct Bytes_gzdbpf {
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    // STUB: 0x00478aa0
    void Resize(uint32_t size);
    // STUB: 0x00478890
    void PushBack(const uint8_t* value);
    // STUB: 0x004610a0
    void Grow(uint32_t size, const uint8_t* value);
    // STUB: 0x0040e490
    void Erase(uint8_t* first, uint8_t* last);
};

// STUB: 0x0091a1a6
void Fn0091a1a6(uint32_t path);

#define FILE_GZDBPF (*reinterpret_cast<RecordFile_gzdbpf**>(reinterpret_cast<char*>(this) + 0x54))
#define BYTES_GZDBPF (reinterpret_cast<Bytes_gzdbpf*>(reinterpret_cast<char*>(this) + 0x44))
#define SINK_GZDBPF_OF(p) ((p) ? reinterpret_cast<SinkOf_gzdbpf*>(reinterpret_cast<char*>(p) - 4) : 0)

// FUNCTION: 0x0096e91b
uint32_t cUnk00ad8628::Slot03_ad9030()
{
    if (W16_GZDBPF(0xa)) {
        if (FILE_GZDBPF) {
            return FILE_GZDBPF->Size_gzdbpf();
        }
        return static_cast<uint32_t>(BYTES_GZDBPF->mpEnd - BYTES_GZDBPF->mpBegin);
    }
    return 0;
}


// The embedded parts of the file object, reached by offset: only their constructors and destructors are called here.
struct Part_gzdbpf {
    // STUB: 0x0099784e
    void M0099784e();
    // STUB: 0x0058f3a0
    void M0058f3a0();
    // STUB: 0x00918c70
    void M00918c70();
    // STUB: 0x00414250
    void M00414250();
    // STUB: 0x00578390
    void M00578390();
    // STUB: 0x00918b96
    void M00918b96();
    // STUB: 0x0096f57b
    void M0096f57b();
    // STUB: 0x0096d8bc
    void M0096d8bc();
    // STUB: 0x0092e6c9
    void M0092e6c9();
    // STUB: 0x0060ee30
    void M0060ee30();
    // STUB: 0x00969ad5
    void M00969ad5();
};
#define PART_GZDBPF(off) (reinterpret_cast<Part_gzdbpf*>(reinterpret_cast<char*>(this) + (off)))

// The constructor of the file object at 0x54 of a record: runs on raw memory.
struct FileCtor_gzdbpf {
    // STUB: 0x00918c00
    RecordFile_gzdbpf* Construct(const cRZString* path);
};

// STUB: 0x0091a497
bool Fn0091a497(cRZString* path, uint32_t zero);

// FUNCTION: 0x00970ee5
bool cUnk00ad8628::Slot53_ad8d88(uint32_t size)
{
    if (W16_GZDBPF(0xa)) {
        if (FILE_GZDBPF) {
            return FILE_GZDBPF->SetSize_gzdbpf(size);
        }
        BYTES_GZDBPF->Resize(size);
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096eb2a score 22
bool cUnk00ad8628::Slot04_ad9030(uint32_t destination, uint32_t length)
{
    if (W16_GZDBPF(0xa)) {
        if (FILE_GZDBPF) {
            return FILE_GZDBPF->Read_gzdbpf(OB_PTR(void, destination), length);
        }
        if (U32_GZDBPF(0x50) + length <= static_cast<uint32_t>(BYTES_GZDBPF->mpEnd - BYTES_GZDBPF->mpBegin)) {
            memcpy(OB_PTR(void, destination), BYTES_GZDBPF->mpBegin + U32_GZDBPF(0x50), length);
            U32_GZDBPF(0x50) += length;
            return true;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x0096f70f
void cUnk00ad8628::Slot62_ad7ee8()
{
    W16_GZDBPF(0xa) = 0;
    Unknown_gzdbpf* owner = static_cast<Unknown_gzdbpf*>(P32_GZDBPF(0x18));
    if (owner) {
        owner->Release_gzdbpf();
        P32_GZDBPF(0x18) = 0;
    }
    if (FILE_GZDBPF) {
        if (FILE_GZDBPF->IsOpen_gzdbpf()) {
            FILE_GZDBPF->Close_gzdbpf();
            Fn0091a1a6(FILE_GZDBPF->Path_gzdbpf());
        }
        if (FILE_GZDBPF) {
            FILE_GZDBPF->Destroy_gzdbpf(1);
        }
        FILE_GZDBPF = 0;
    }
    Bytes_gzdbpf* bytes = BYTES_GZDBPF;
    bytes->Erase(bytes->mpBegin, bytes->mpEnd);
    U32_GZDBPF(0x50) = 0;
    U8_GZDBPF(0x58) = 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0096eb78 score 60
bool cUnk00ad8628::Slot63_ad8628(uint32_t destination, uint32_t length)
{
    uint32_t done;
    uint8_t* chunk;
    uint32_t saved;
    bool ok = false;
    if (W16_GZDBPF(0xa)) {
        SinkOf_gzdbpf* sink;
        if (FILE_GZDBPF) {
            saved = FILE_GZDBPF->Tell_gzdbpf();
            done = 0;
            chunk = static_cast<uint8_t*>(operator new(0x4000));
            FILE_GZDBPF->Seek_gzdbpf(0);
            ok = true;
            while (length > 0 && ok) {
                uint32_t n;
                if (done + 0x4000 > length) {
                    n = length - done;
                } else {
                    n = 0x4000;
                }
                ok = FILE_GZDBPF->Read_gzdbpf(chunk, n);
                if (ok) {
                    sink = SINK_GZDBPF_OF(P32_GZDBPF(0x18));
                    ok = sink->Copy_gzdbpf(chunk, destination, n);
                    done += n;
                    destination += n;
                }
                if (done >= length) {
                    break;
                }
            }
            operator delete(chunk);
            FILE_GZDBPF->Seek_gzdbpf(saved);
        } else {
            uint32_t size = static_cast<uint32_t>(BYTES_GZDBPF->mpEnd - BYTES_GZDBPF->mpBegin);
            if (length > size) {
                length = size;
            }
            sink = SINK_GZDBPF_OF(P32_GZDBPF(0x18));
            ok = sink->Copy_gzdbpf(BYTES_GZDBPF->mpBegin, destination, length);
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096ec7c score 5
uint32_t cGZDBSerialRecordAsIGZFile::Fn0096ec7c(void* target)
{
    mnRefCount = 0;
    mpTarget = target;
    if (target) {
        static_cast<Unknown_gzdbpf*>(target)->AddRef_gzdbpf();
    }
    return OB_ADDR(this);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096e93a score 12
void cGZDBSerialRecordAsIGZFile::Fn0096e93a()
{
    if (mpTarget) {
        Slot05_abfe50();
    }
}
#endif

// FUNCTION: 0x0096ee20
void Tree_gzdbpf::Fn0096ee20(TreeNode_gzdbpf** out, uint32_t addLeft, TreeNode_gzdbpf* where, const uint32_t* value, uint32_t addRight)
{
    TreeNode_gzdbpf* parent = where;
    TreeNode_gzdbpf* node;
    TreeNode_gzdbpf* header;
    bool left = true;
    if (parent != mpHeader) {
        if (addRight || (!addLeft && value[1] >= parent->mnKey)) {
            left = false;
        }
    }
    if (!left) {
        node = CreateNode(value);
        parent->mpRight = node;
        header = static_cast<TreeNode_gzdbpf*>(mpHeader);
        if (parent == header->mpRight) {
            header->mpRight = node;
        }
    } else {
        node = CreateNode(value);
        parent->mpLeft = node;
        header = static_cast<TreeNode_gzdbpf*>(mpHeader);
        if (parent == header) {
            header->mpParent = node;
            header = static_cast<TreeNode_gzdbpf*>(mpHeader);
            header->mpRight = node;
        } else if (parent == header->mpLeft) {
            header->mpLeft = node;
        }
    }
    node->mpLeft = 0;
    node->mpRight = 0;
    node->mpParent = parent;
    Rebalance_gzdbpf(node, &static_cast<TreeNode_gzdbpf*>(mpHeader)->mpParent);
    ++mnCount;
    *out = node;
}

// A hash table of word keys (bucket vector at 0x4, allocator at 0x8).
struct HashBucketNode_gzdbpf {
    HashBucketNode_gzdbpf* mpNext;
    uint32_t mnPad[2];
    uint32_t mnHash;
};

struct BucketVector_gzdbpf {
    HashBucketNode_gzdbpf** mpBegin;
    // STUB: 0x0097c01d
    BucketVector_gzdbpf* Construct(uint32_t count, const uint32_t* value, const uint8_t* allocator);
    // STUB: 0x0096edf7
    void Swap(BucketVector_gzdbpf* other);
};

struct Allocator_gzdbpf {
    // STUB: 0x00459d80
    void* Allocate(uint32_t count);
};

// STUB: 0x006d6880
void Fn006d6880(void* a, void* b, void* c, char* fill);

struct HashTable_gzdbpf {
    uint32_t mnPad0;
    HashBucketNode_gzdbpf** mpBegin;
    HashBucketNode_gzdbpf** mpEnd;
    // STUB: 0x0090df7c
    uint32_t NextSize(uint32_t hint) const;
    // STUB: 0x0096f614
    void Fn0096f614(uint32_t hint);
    // STUB: 0x0096f6be
    void* Fn0096f6be(uint32_t count, void* a, void* b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096f614 score 61
void HashTable_gzdbpf::Fn0096f614(uint32_t hint)
{
    uint32_t size = static_cast<uint32_t>(mpEnd - mpBegin);
    if (hint > size) {
        uint32_t wanted = NextSize(hint);
        if (wanted > size) {
            uint32_t index = 0;
            uint8_t allocator;
            BucketVector_gzdbpf fresh;
            fresh.Construct(wanted, &index, &allocator);
            for (index = 0; index < size; ++index) {
                HashBucketNode_gzdbpf* first = mpBegin[index];
                while (first) {
                    uint32_t slot = first->mnHash % wanted;
                    mpBegin[index] = first->mpNext;
                    first->mpNext = fresh.mpBegin[slot];
                    fresh.mpBegin[slot] = first;
                    first = mpBegin[index];
                }
            }
            reinterpret_cast<BucketVector_gzdbpf*>(&mpBegin)->Swap(&fresh);
            if (fresh.mpBegin) {
                StlDelete_gzdbpf(fresh.mpBegin);
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0096f6be score 6
void* HashTable_gzdbpf::Fn0096f6be(uint32_t count, void* a, void* b)
{
    char fill = 0;
    void* block = reinterpret_cast<Allocator_gzdbpf*>(reinterpret_cast<char*>(this) + 8)->Allocate(count);
    Fn006d6880(a, b, block, &fill);
    return block;
}
#endif

// The destructor body of the file object.
#ifdef OB_DRAFTS
// CLOSE: 0x009700e5 score 10
void cGZDBSegmentPackedFile::Fn009700e5()
{
    Slot06_ad8fc8();
    PART_GZDBPF(0x1b0)->M0099784e();
    PART_GZDBPF(0x19c)->M0058f3a0();
    PART_GZDBPF(0x188)->M0058f3a0();
    PART_GZDBPF(0x170)->M0058f3a0();
    PART_GZDBPF(0x15c)->M0058f3a0();
    reinterpret_cast<Tree_gzdbpf*>(reinterpret_cast<char*>(this) + 0x14c)->Fn0096f116();
    reinterpret_cast<Tree_gzdbpf*>(reinterpret_cast<char*>(this) + 0xd8)->Fn0096f0ff();
    PART_GZDBPF(0x40)->M00918c70();
    PART_GZDBPF(0x2c)->M00414250();
}
#endif

// The constructor body of the file object (without the vtable stores).
#ifdef OB_DRAFTS
// CLOSE: 0x0097212d score 10
void* cGZDBSegmentPackedFile::Fn0097212d()
{
    mbOpen = false;
    mn18 = 0;
    mnFlags = 0;
    U32_GZDBPF(0x20) = 0;
    mpIndex = 0;
    U8_GZDBPF(0x28) = 0;
    PART_GZDBPF(0x2c)->M00578390();
    PART_GZDBPF(0x40)->M00918b96();
    mnC4 = 0xffffffff;
    mnC8 = 0xffffffff;
    mnC0 = 0;
    mnCc = 0;
    mnD0 = 0;
    U32_GZDBPF(0xd4) = 0x200;
    PART_GZDBPF(0xd8)->M0096f57b();
    PART_GZDBPF(0xe4)->M0096d8bc();
    mn144 = 3;
    U32_GZDBPF(0x148) = 0x3e19999a;
    PART_GZDBPF(0x14c)->M0092e6c9();
    mbDirty = false;
    U8_GZDBPF(0x159) = 0;
    U8_GZDBPF(0x15a) = 0;
    PART_GZDBPF(0x15c)->M0060ee30();
    PART_GZDBPF(0x170)->M0060ee30();
    mbFlag184 = false;
    mbFlag185 = true;
    PART_GZDBPF(0x188)->M0060ee30();
    PART_GZDBPF(0x19c)->M0060ee30();
    PART_GZDBPF(0x1b0)->M00969ad5();
    mpBuffer = 0;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00970f0f score 86
bool cUnk00ad8628::Slot05_ad9030(uint32_t source, uint32_t length)
{
    bool ok = false;
    if (W16_GZDBPF(0xa)) {
        if (FILE_GZDBPF) {
            return FILE_GZDBPF->Write_gzdbpf(OB_PTR(const void, source), length);
        }
        uint32_t end = U32_GZDBPF(0x50) + length;
        if (end >= 2000000 && !U8_GZDBPF(0x58)) {
            cRZString path;
            U8_GZDBPF(0x58) = 1;
            path.Sprintf("Record_%08x_", P32_GZDBPF(0xc));
            if (Fn0091a497(&path, 0)) {
                void* memory = operator new(0x80);
                RecordFile_gzdbpf* file = 0;
                if (memory) {
                    file = reinterpret_cast<FileCtor_gzdbpf*>(memory)->Construct(&path);
                }
                FILE_GZDBPF = file;
                if (file->Open_gzdbpf(3, 3, 1)) {
                    FILE_GZDBPF->Seek_gzdbpf(0);
                    FILE_GZDBPF->SetSize_gzdbpf(0);
                    uint32_t size = static_cast<uint32_t>(BYTES_GZDBPF->mpEnd - BYTES_GZDBPF->mpBegin);
                    if (FILE_GZDBPF->Write_gzdbpf(BYTES_GZDBPF->mpBegin, size)) {
                        FILE_GZDBPF->Write_gzdbpf(OB_PTR(const void, source), length);
                        BYTES_GZDBPF->Resize(0);
                        U32_GZDBPF(0x50) = 0;
                        return true;
                    }
                }
                if (FILE_GZDBPF->IsOpen_gzdbpf()) {
                    FILE_GZDBPF->Close_gzdbpf();
                }
                Fn0091a1a6(FILE_GZDBPF->Path_gzdbpf());
                if (FILE_GZDBPF) {
                    FILE_GZDBPF->Destroy_gzdbpf(1);
                }
                FILE_GZDBPF = 0;
            }
        }
        if (!FILE_GZDBPF) {
            uint32_t position = U32_GZDBPF(0x50);
            uint32_t size = static_cast<uint32_t>(BYTES_GZDBPF->mpEnd - BYTES_GZDBPF->mpBegin);
            uint8_t value;
            if (position == size && length < 0x40) {
                for (uint32_t i = 0; i < length; ++i) {
                    value = OB_PTR(const uint8_t, source)[i];
                    BYTES_GZDBPF->PushBack(&value);
                }
            } else {
                if (end > size) {
                    value = 0;
                    BYTES_GZDBPF->Grow(position + length, &value);
                }
                memcpy(BYTES_GZDBPF->mpBegin + U32_GZDBPF(0x50), OB_PTR(const void, source), length);
            }
            U32_GZDBPF(0x50) += length;
            ok = true;
        }
    }
    return ok;
}
#endif
