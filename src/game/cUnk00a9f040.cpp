#include "classes/cUnk00a9f040.h"
#include <algorithm>
#include <new>
#include <ctype.h>
#include <string.h>

// The 12-byte std::string of the framework (begin, end, capacity) that the object keeps its lookup key in.
struct Str_a9f040 {
    char* mpBegin;
    char* mpEnd;
    char* mpCap;
    // STUB: 0x0044d3a0
    Str_a9f040* Assign(const char* first, const char* last);
};

// std::transform(first, last, result, op) instantiated for characters.
// STUB: 0x00586ac0
char* Transform_a9f040(char* first, char* last, char* result, int (*op)(int));

// The STL allocator's new and delete.
// STUB: 0x0090cf54
void* StlNew_a9f040(uint32_t size);
// STUB: 0x0090cf63
void StlDelete_a9f040(void* p);

struct Node_a9f040 {
    Node_a9f040* mpNext;
    Str_a9f040 mKey;
    int32_t mnValue;
};

struct Pair_a9f040;
struct Range_a9f040;
struct Iter_a9f040 {
    void* mpCur;
    void* mpTable;
};

// The hash map of a name table (STLport's hashtable: three empty functors, the buckets vector, the element count).
struct HashMap_a9f040 {
    uint32_t mn0;
    Node_a9f040** mpBucketsStart;
    Node_a9f040** mpBucketsFinish;
    Node_a9f040** mpBucketsEnd;
    uint32_t mnElements;
    // STUB: 0x00586ef0
    void EqualRange(Range_a9f040* result, const Str_a9f040* key);
    // STUB: 0x00587010
    void Resize(uint32_t hint);
    // STUB: 0x00589e80
    Iter_a9f040 InsertEqualNoResize(const Pair_a9f040& value);
    void InsertEqual(const Pair_a9f040& value)
    {
        Resize(mnElements + 1);
        InsertEqualNoResize(value);
    }
};

// STLport's hashtable iterator and the pair of them that equal_range returns.
struct HIter_a9f040 {
    Node_a9f040* mpCur;
    HashMap_a9f040* mpTable;
    void Advance()
    {
        Node_a9f040* old = mpCur;
        mpCur = old->mpNext;
        if (!mpCur) {
            uint32_t hash = 0;
            for (uint32_t i = 0; i < static_cast<uint32_t>(old->mKey.mpEnd - old->mKey.mpBegin); ++i) {
                hash = hash * 5 + old->mKey.mpBegin[i];
            }
            uint32_t bucket = hash % static_cast<uint32_t>(mpTable->mpBucketsFinish - mpTable->mpBucketsStart);
            while (!mpCur) {
                ++bucket;
                if (bucket >= static_cast<uint32_t>(mpTable->mpBucketsFinish - mpTable->mpBucketsStart)) {
                    break;
                }
                mpCur = mpTable->mpBucketsStart[bucket];
            }
        }
    }
};
struct Range_a9f040 {
    HIter_a9f040 mFirst;
    HIter_a9f040 mLast;
};

// The vector behind a name table (begin, end, capacity) with the framework's out-of-line member functions for the
// element types.
struct VecAny_a9f040 {
    void* mpStart;
    void* mpFinish;
    void* mpEnd;
    // STUB: 0x0058adc0
    void Resize64(uint32_t size, const void* value);
    // STUB: 0x0058ae30
    void Resize1c(uint32_t size, const void* value);
    // STUB: 0x0058a700
    void Resize28(uint32_t size, const void* value);
};

// The second table's elements: a particle description each (the object is 0x208 bytes).
struct Desc_a9f040 {
    uint8_t mBytes[0x208];
    // STUB: 0x005b1660
    Desc_a9f040();
    // STUB: 0x005af940
    void AddRef();
    // STUB: 0x005b1c80
    void Release();
    // STUB: 0x005b1cb0
    void Assign(void* source);
};
struct DescVec_a9f040 {
    Desc_a9f040** mpStart;
    Desc_a9f040** mpFinish;
    Desc_a9f040** mpEnd;
    // STUB: 0x00587850
    void Clear();
};
// Copies the elements of [first, last) to result, ending with the new element x.
// STUB: 0x00586bf0
Desc_a9f040** CopyDescs_a9f040(Desc_a9f040** first, Desc_a9f040** last, Desc_a9f040** result, Desc_a9f040** x);

// The third table's elements: reference counted objects of 0x40 bytes.
struct Obj40_a9f040 {
    virtual void Slot0();
    virtual void Release();
    virtual void AddRef();
    uint8_t mBytes[0x3c];
    // STUB: 0x005836a0
    Obj40_a9f040();
    // STUB: 0x00583750
    void Assign(void* source);
};

// The fourth table's elements: 0x64 bytes each.
struct Elem64_a9f040 {
    uint8_t mBytes[0x64];
    // STUB: 0x00582fe0
    Elem64_a9f040* Init();
    // STUB: 0x00583130
    void Destroy();
    // STUB: 0x005833f0
    void Assign(void* source);
};

struct Vec1_a9f040 {
    uint32_t mn0;
    uint32_t mn1;
    uint32_t mn2;
    // STUB: 0x00464430
    void Assign464430(const Vec1_a9f040* source);
};
struct Vec2_a9f040 {
    uint32_t mn0;
    uint32_t mn1;
    uint32_t mn2;
    // STUB: 0x0050c540
    void Assign50c540(const Vec2_a9f040* source);
};

// The fifth table's elements: two numbers and two vectors, 0x28 bytes each.
struct Elem28_a9f040 {
    uint32_t mn0;
    uint32_t mn4;
    Vec1_a9f040 mA;
    Vec1_a9f040 mB;
    uint32_t mn20;
    uint32_t mn24;
    Elem28_a9f040()
    {
        mA.mn0 = 0;
        mA.mn1 = 0;
        mA.mn2 = 0;
        mB.mn0 = 0;
        mB.mn1 = 0;
        mB.mn2 = 0;
    }
    // STUB: 0x00588080
    void Assign(void* source);
};

// The sixth table's elements: two vectors and a number.
struct Rec1c_a9f040 {
    Vec2_a9f040 mA;
    Vec1_a9f040 mB;
    uint32_t mn18;
};

// The objects of the 13 types: slot 0 tells the type, slots 4 and 5 count references.
struct Obj_a9f040 {
    virtual uint32_t GetType() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

// The first table's elements (0x38 bytes): a model with a name, its parts and its slots.
struct Part_a9f040 {
    Str_a9f040 mName;
    int32_t mnKind;
    uint8_t mPad_10[0x58];
    int32_t mnResolved;
};
struct Slot_a9f040 {
    uint32_t mnFlags;
    Str_a9f040 mName;
    int32_t mnResolved;
    uint32_t mn14;
};
struct Model_a9f040 {
    uint32_t mn0;
    uint32_t mnId;
    Part_a9f040* mpPartsStart;
    Part_a9f040* mpPartsFinish;
    Part_a9f040* mpPartsEnd;
    Slot_a9f040* mpSlotsStart;
    Slot_a9f040* mpSlotsFinish;
    Slot_a9f040* mpSlotsEnd;
    uint8_t mPad_20[0xc];
    Str_a9f040 mName;
    // STUB: 0x0058b4a0
    void Assign(const void* source);
};
struct ModelVec_a9f040 {
    Model_a9f040* mpStart;
    Model_a9f040* mpFinish;
    Model_a9f040* mpEnd;
    // STUB: 0x0058d4d0
    void Resize(uint32_t size);
};

struct Obj40Vec_a9f040 {
    Obj40_a9f040** mpStart;
    Obj40_a9f040** mpFinish;
    Obj40_a9f040** mpEnd;
    // STUB: 0x00588260
    void InsertOverflow(Obj40_a9f040** pos, Obj40_a9f040* const* x, const void* tag, uint32_t count, bool atEnd);
};

struct ObjVec_a9f040 {
    Obj_a9f040** mpStart;
    Obj_a9f040** mpFinish;
    Obj_a9f040** mpEnd;
    // STUB: 0x00588850
    void PushBack(Obj_a9f040* const* x);
    // STUB: 0x005880c0
    void InsertOverflow(Obj_a9f040** pos, Obj_a9f040* const* x, const void* tag, uint32_t count, bool atEnd);
};

// The vector of a name table, seen as the element type of the table.
union Vectors_a9f040 {
    VecAny_a9f040 mAny;
    DescVec_a9f040 mDesc;
    Obj40Vec_a9f040 mObj40;
    ObjVec_a9f040 mObj;
    ModelVec_a9f040 mModel;
};

// A name table: the hash map from name to index, then the vector of the things the index leads to.
struct Table_a9f040 {
    HashMap_a9f040 mMap;
    Vectors_a9f040 mVec;
    // STUB: 0x0051c9f0
    Node_a9f040* Find(const Str_a9f040* key);
    // STUB: 0x0058a670
    int32_t* Index(const Str_a9f040* key);
};

template <class T>
inline T* ElemAt_a9f040(const Table_a9f040* table, int32_t index)
{
    return static_cast<T*>(table->mVec.mAny.mpStart) + index;
}

struct Record_a9f040 {
    Vec1_a9f040 mVec;
    uint32_t mn0c;
    uint32_t mn10;
    uint32_t mn14;
    uint32_t mn18;
};

// The empty allocator (and tag) objects the framework passes by reference.
struct Empty_a9f040 {
    Empty_a9f040() {}
};

// A string a function builds on its stack (the framework's constructors are out of line).
struct LocalStr_a9f040 {
    char* mpBegin;
    char* mpEnd;
    char* mpCap;
    LocalStr_a9f040()
        : mpBegin(0)
        , mpEnd(0)
        , mpCap(0)
    {
    }
    enum RangeTag {
        kRange
    };
    LocalStr_a9f040(const char* text, const Empty_a9f040& allocator)
        : mpBegin(0)
        , mpEnd(0)
        , mpCap(0)
    {
        InitFromText(text, text + strlen(text), allocator);
    }
    LocalStr_a9f040(RangeTag, const char* first, const char* last, const Empty_a9f040& allocator)
        : mpBegin(0)
        , mpEnd(0)
        , mpCap(0)
    {
        InitFromRange(first, last, allocator);
    }
    ~LocalStr_a9f040()
    {
        if (mpBegin) {
            StlDelete_a9f040(mpBegin);
        }
    }
    int32_t Lookup(cUnk00a9f040* self, uint32_t id)
    {
        return self->Fn00587170(this, id);
    }
    // STUB: 0x00407fa0
    void InitFromText(const char* first, const char* last, const Empty_a9f040& allocator);
    // STUB: 0x00408420
    void InitFromRange(const char* first, const char* last, const Empty_a9f040& allocator);
};

// A name and an index, as the first table stores them.
struct Pair_a9f040 {
    LocalStr_a9f040 mName;
    int32_t mnValue;
    Pair_a9f040(const char* first, const char* last, int32_t value)
        : mName(LocalStr_a9f040::kRange, first, last, Empty_a9f040())
        , mnValue(value)
    {
    }
};

// STUB: 0x009dd1d0
void StlThrowLength_a9f040(const char* what);

// The framework's std::string built from a C string, all inline.
struct CStr_a9f040 {
    char* mpBegin;
    char* mpEnd;
    char* mpCap;
    explicit CStr_a9f040(const char* text)
        : mpBegin(0)
        , mpEnd(0)
        , mpCap(0)
    {
        uint32_t length = static_cast<uint32_t>(strlen(text));
        uint32_t size = length + 1;
        if (size == 0) {
            StlThrowLength_a9f040("basic_string");
        } else {
            mpBegin = static_cast<char*>(StlNew_a9f040(size));
            mpCap = mpBegin + size;
        }
        char* end = mpBegin;
        if (text != text + length) {
            end = static_cast<char*>(memmove(mpBegin, text, length)) + length;
        }
        mpEnd = end;
        *mpEnd = 0;
    }
    ~CStr_a9f040()
    {
        if (mpBegin) {
            StlDelete_a9f040(mpBegin);
        }
    }
    int32_t Lookup(cUnk00a9f040* self, uint32_t id)
    {
        return self->Fn00587170(this, id);
    }
};

// What the vector at 0xf0 holds: a name and two numbers.
struct Entry_a9f040 {
    LocalStr_a9f040 mName;
    uint32_t mn0;
    uint32_t mn1;
};

struct VecF0_a9f040 {
    // STUB: 0x0058ad50
    void PushBack(const Entry_a9f040* entry);
    // STUB: 0x0058aea0
    void Destroy(void* first, void* last);
    void* mpStart;
    void* mpFinish;
    void* mpEnd;
};
struct VecFC_a9f040 {
    // STUB: 0x0058aff0
    void Destroy(void* first, void* last);
    void* mpStart;
    void* mpFinish;
    void* mpEnd;
};

// The object's own storage, seen from outside: the six name tables, the table of the 13 object types, the loaded
// record, two vectors and the key the lookups lower-case the name into.
struct Body_a9f040 {
    uint8_t mVptr[4];
    Table_a9f040 mTable[6];
    Table_a9f040* mpTypeTables;
    uint8_t mPad_c8[8];
    bool mbLoaded;
    uint8_t mPad_d1[3];
    Record_a9f040 mRecord;
    VecF0_a9f040 mVecF0;
    VecFC_a9f040 mVecFC;
    uint8_t mPad_108[4];
    Str_a9f040 mKey;
};
inline Body_a9f040* BodyOf_a9f040(cUnk00a9f040* p)
{
    return reinterpret_cast<Body_a9f040*>(p);
}

// FUNCTION: 0x00588810
void cUnk00a9f040::Slot19_a9f040(void* source)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    const Record_a9f040* from = static_cast<const Record_a9f040*>(source);
    Record_a9f040* to = &body->mRecord;
    to->mVec.Assign464430(&from->mVec);
    to->mn0c = from->mn0c;
    to->mn10 = from->mn10;
    to->mn14 = from->mn14;
    to->mn18 = from->mn18;
    body->mbLoaded = true;
}

// FUNCTION: 0x00588dd0
bool cUnk00a9f040::Slot08_a9f040(const char* name, void* out)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[1].Find(&body->mKey);
    if (!node) {
        return false;
    }
    if (out) {
        static_cast<Desc_a9f040*>(out)->Assign(ElemAt_a9f040<void*>(&body->mTable[1], node->mnValue)[0]);
    }
    return true;
}

// FUNCTION: 0x00588e50
bool cUnk00a9f040::Slot10_a9f040(const char* name, void* out)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[2].Find(&body->mKey);
    if (!node) {
        return false;
    }
    if (out) {
        static_cast<Obj40_a9f040*>(out)->Assign(ElemAt_a9f040<void*>(&body->mTable[2], node->mnValue)[0]);
    }
    return true;
}

// FUNCTION: 0x00588ed0
bool cUnk00a9f040::Slot12_a9f040(const char* name, void* out)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[3].Find(&body->mKey);
    if (!node) {
        return false;
    }
    if (out) {
        static_cast<Elem64_a9f040*>(out)->Assign(ElemAt_a9f040<Elem64_a9f040>(&body->mTable[3], node->mnValue));
    }
    return true;
}

// FUNCTION: 0x00588f50
bool cUnk00a9f040::Slot14_a9f040(const char* name, void* out)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[4].Find(&body->mKey);
    if (!node) {
        return false;
    }
    if (out) {
        static_cast<Elem28_a9f040*>(out)->Assign(ElemAt_a9f040<Elem28_a9f040>(&body->mTable[4], node->mnValue));
    }
    return true;
}

// FUNCTION: 0x00588fd0
bool cUnk00a9f040::Slot16_a9f040(const char* name, void* out)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[5].Find(&body->mKey);
    if (!node) {
        return false;
    }
    if (out) {
        Rec1c_a9f040* to = static_cast<Rec1c_a9f040*>(out);
        Rec1c_a9f040* from = ElemAt_a9f040<Rec1c_a9f040>(&body->mTable[5], node->mnValue);
        to->mA.Assign50c540(&from->mA);
        to->mB.Assign464430(&from->mB);
        to->mn18 = from->mn18;
    }
    return true;
}

// FUNCTION: 0x00589070
bool cUnk00a9f040::Slot18_a9f040(const char* name, uint32_t type, void* out)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    Table_a9f040* table = body->mpTypeTables + (type - 3);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = table->Find(&body->mKey);
    if (!node) {
        return false;
    }
    if (out) {
        Obj_a9f040* object = ElemAt_a9f040<Obj_a9f040*>(table, node->mnValue)[0];
        *static_cast<Obj_a9f040**>(out) = object;
        object->AddRef();
    }
    return true;
}

// FUNCTION: 0x0058b500
bool cUnk00a9f040::Slot06_a9f040(const char* name, void* out)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[0].Find(&body->mKey);
    if (!node) {
        return false;
    }
    if (out) {
        static_cast<Model_a9f040*>(out)->Assign(ElemAt_a9f040<Model_a9f040>(&body->mTable[0], node->mnValue));
    }
    return true;
}

// FUNCTION: 0x0058bef0
void cUnk00a9f040::Slot03_a9f040()
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mVecFC.Destroy(body->mVecFC.mpStart, body->mVecFC.mpFinish);
    body->mVecF0.Destroy(body->mVecF0.mpStart, body->mVecF0.mpFinish);
    body->mbLoaded = false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0058a980 score 94
void cUnk00a9f040::Slot07_a9f040(const char* name, void* source)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[1].Find(&body->mKey);
    int32_t index;
    if (!node) {
        DescVec_a9f040* vec = &body->mTable[1].mVec.mDesc;
        index = static_cast<int32_t>(vec->mpFinish - vec->mpStart);
        *body->mTable[1].Index(&body->mKey) = index;
        Desc_a9f040* made = new Desc_a9f040();
        Desc_a9f040* held = made;
        if (made) {
            made->AddRef();
        }
        if (vec->mpFinish != vec->mpEnd) {
            if (vec->mpFinish) {
                *vec->mpFinish = made;
                if (made) {
                    made->AddRef();
                }
            }
            ++vec->mpFinish;
        } else {
            Desc_a9f040** start = vec->mpStart;
            uint32_t oldSize = static_cast<uint32_t>(vec->mpFinish - start);
            const uint32_t one = 1;
            uint32_t length = oldSize + std::max(oldSize, one);
            Desc_a9f040** fresh = 0;
            if (length) {
                fresh = static_cast<Desc_a9f040**>(StlNew_a9f040(length * 4));
            }
            Desc_a9f040** end = CopyDescs_a9f040(start, vec->mpFinish, fresh, &held);
            if (end) {
                *end = held;
                if (held) {
                    held->AddRef();
                }
            }
            ++end;
            vec->Clear();
            vec->mpStart = fresh;
            vec->mpFinish = end;
            vec->mpEnd = fresh + length;
            made = held;
        }
        if (made) {
            made->Release();
        }
    } else {
        index = node->mnValue;
    }
    body->mTable[1].mVec.mDesc.mpStart[index]->Assign(source);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0058ab10 score 2
void cUnk00a9f040::Slot09_a9f040(const char* name, void* source)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[2].Find(&body->mKey);
    int32_t index;
    if (!node) {
        Obj40Vec_a9f040* vec = &body->mTable[2].mVec.mObj40;
        index = static_cast<int32_t>(vec->mpFinish - vec->mpStart);
        *body->mTable[2].Index(&body->mKey) = index;
        Obj40_a9f040* made = new Obj40_a9f040();
        Obj40_a9f040* held = made;
        if (made) {
            made->AddRef();
        }
        if (vec->mpFinish != vec->mpEnd) {
            if (vec->mpFinish) {
                *vec->mpFinish = made;
                if (made) {
                    made->AddRef();
                }
            }
            ++vec->mpFinish;
        } else {
            vec->InsertOverflow(vec->mpFinish, &held, &held, 1, true);
        }
        if (made) {
            made->Release();
        }
    } else {
        index = node->mnValue;
    }
    body->mTable[2].mVec.mObj40.mpStart[index]->Assign(source);
}
#endif

// FUNCTION: 0x0058bf30
void cUnk00a9f040::Slot11_a9f040(const char* name, void* source)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[3].Find(&body->mKey);
    int32_t index;
    if (!node) {
        VecAny_a9f040* vec = &body->mTable[3].mVec.mAny;
        index = static_cast<int32_t>(static_cast<Elem64_a9f040*>(vec->mpFinish) - static_cast<Elem64_a9f040*>(vec->mpStart));
        Elem64_a9f040 blank;
        vec->Resize64(index + 1, blank.Init());
        blank.Destroy();
        *body->mTable[3].Index(&body->mKey) = index;
    } else {
        index = node->mnValue;
    }
    (static_cast<Elem64_a9f040*>(body->mTable[3].mVec.mAny.mpStart) + index)->Assign(source);
}

// FUNCTION: 0x0058bff0
void cUnk00a9f040::Slot15_a9f040(const char* name, void* source)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[5].Find(&body->mKey);
    int32_t index;
    if (!node) {
        VecAny_a9f040* vec = &body->mTable[5].mVec.mAny;
        index = static_cast<int32_t>(static_cast<Rec1c_a9f040*>(vec->mpFinish) - static_cast<Rec1c_a9f040*>(vec->mpStart));
        Rec1c_a9f040 blank;
        blank.mA.mn0 = 0;
        blank.mA.mn1 = 0;
        blank.mA.mn2 = 0;
        blank.mB.mn0 = 0;
        blank.mB.mn1 = 0;
        blank.mB.mn2 = 0;
        blank.mn18 = 0x40000000;
        vec->Resize1c(index + 1, &blank);
        *body->mTable[5].Index(&body->mKey) = index;
    } else {
        index = node->mnValue;
    }
    Rec1c_a9f040* to = static_cast<Rec1c_a9f040*>(body->mTable[5].mVec.mAny.mpStart) + index;
    const Rec1c_a9f040* from = static_cast<const Rec1c_a9f040*>(source);
    to->mA.Assign50c540(&from->mA);
    to->mB.Assign464430(&from->mB);
    to->mn18 = from->mn18;
}

// FUNCTION: 0x0058b3a0
void cUnk00a9f040::Slot13_a9f040(const char* name, void* source)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = body->mTable[4].Find(&body->mKey);
    int32_t index;
    if (!node) {
        VecAny_a9f040* vec = &body->mTable[4].mVec.mAny;
        index = static_cast<int32_t>(static_cast<Elem28_a9f040*>(vec->mpFinish) - static_cast<Elem28_a9f040*>(vec->mpStart));
        Elem28_a9f040 blank;
        vec->Resize28(index + 1, &blank);
        *body->mTable[4].Index(&body->mKey) = index;
    } else {
        index = node->mnValue;
    }
    Elem28_a9f040* to = static_cast<Elem28_a9f040*>(body->mTable[4].mVec.mAny.mpStart) + index;
    const Elem28_a9f040* from = static_cast<const Elem28_a9f040*>(source);
    to->mn0 = from->mn0;
    to->mn4 = from->mn4;
    to->mA.Assign464430(&from->mA);
    to->mB.Assign464430(&from->mB);
    to->mn20 = from->mn20;
    to->mn24 = from->mn24;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0058b580 score 58
void cUnk00a9f040::Slot20_a9f040(const char* name, uint32_t first, uint32_t second)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    LocalStr_a9f040 text;
    Empty_a9f040 allocator;
    text.InitFromText(name, name + strlen(name), allocator);
    Entry_a9f040 entry;
    entry.mName.InitFromRange(text.mpBegin, text.mpEnd, allocator);
    entry.mn0 = first;
    entry.mn1 = second;
    body->mVecF0.PushBack(&entry);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0058ac10 score 36
uint32_t cUnk00a9f040::Slot17_a9f040(const char* name, void* object)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    Obj_a9f040* obj = static_cast<Obj_a9f040*>(object);
    int32_t type = static_cast<int32_t>(obj->GetType());
    Table_a9f040* table = body->mpTypeTables + (type - 3);
    if (!name) {
        ObjVec_a9f040* vec = &table->mVec.mObj;
        uint32_t index = static_cast<uint32_t>(vec->mpFinish - vec->mpStart);
        Obj_a9f040* held = obj;
        obj->AddRef();
        if (vec->mpFinish != vec->mpEnd) {
            if (vec->mpFinish) {
                *vec->mpFinish = obj;
                obj->AddRef();
            }
            ++vec->mpFinish;
        } else {
            vec->InsertOverflow(vec->mpFinish, &held, &held, 1, true);
        }
        obj->Release();
        return index;
    }
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Node_a9f040* node = table->Find(&body->mKey);
    if (!node) {
        ObjVec_a9f040* vec = &table->mVec.mObj;
        uint32_t index = static_cast<uint32_t>(vec->mpFinish - vec->mpStart);
        Obj_a9f040* held = obj;
        obj->AddRef();
        vec->PushBack(&held);
        obj->Release();
        *table->Index(&body->mKey) = index;
        return index;
    } else {
        uint32_t index = node->mnValue;
        Obj_a9f040** slot = table->mVec.mObj.mpStart + index;
        Obj_a9f040* old = *slot;
        if (obj != old) {
            *slot = obj;
            obj->AddRef();
            if (old) {
                old->Release();
            }
        }
        return index;
    }
}
#endif

// Lower-cases a string in place the way the framework's transform loop does (no call to the instantiation).
inline void LowerInline_a9f040(Str_a9f040* text)
{
    char* last = text->mpEnd;
    char* out = text->mpBegin;
    for (char* in = text->mpBegin; in != last; ++in, ++out) {
        *out = static_cast<char>(tolower(*in));
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0058d560 score 212
void cUnk00a9f040::Slot05_a9f040(const char* name, void* source)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    int32_t index;
    const Model_a9f040* from = static_cast<const Model_a9f040*>(source);
    index = LocalStr_a9f040(body->mKey.mpBegin, Empty_a9f040()).Lookup(this, from->mnId);
    if (index < 0) {
        index = static_cast<int32_t>(body->mTable[0].mVec.mModel.mpFinish - body->mTable[0].mVec.mModel.mpStart);
        body->mTable[0].mVec.mModel.Resize(index + 1);
        body->mTable[0].mMap.InsertEqual(Pair_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, index));
    }
    Model_a9f040* model = body->mTable[0].mVec.mModel.mpStart + index;
    model->Assign(from);
    if (model->mName.mpBegin != model->mName.mpEnd) {
        Transform_a9f040(model->mName.mpBegin, model->mName.mpEnd, model->mName.mpBegin, tolower);
    }
    for (Part_a9f040* part = model->mpPartsStart; part != model->mpPartsFinish; ++part) {
        if (part->mnResolved < 0) {
            LowerInline_a9f040(&part->mName);
            int32_t kind = part->mnKind;
            Node_a9f040* node;
            if (kind == 0) {
                node = body->mTable[1].Find(&part->mName);
            } else if (kind == 0x10) {
                node = body->mTable[2].Find(&part->mName);
            } else if (kind == 1) {
                node = body->mTable[3].Find(&part->mName);
            } else if (kind == 2) {
                part->mnResolved = 0;
                node = 0;
            } else if (kind >= 3 && kind <= 0xf) {
                node = body->mpTypeTables[kind - 3].Find(&part->mName);
            } else {
                node = 0;
            }
            if (node) {
                part->mnResolved = node->mnValue;
            }
        }
    }
    for (Slot_a9f040* slot = model->mpSlotsStart; slot != model->mpSlotsFinish; ++slot) {
        LowerInline_a9f040(&slot->mName);
        uint32_t flags = slot->mnFlags;
        Node_a9f040* node = 0;
        if (flags & 1) {
            node = body->mTable[4].Find(&slot->mName);
        } else if ((flags & 4) || (flags & 8)) {
            node = body->mTable[5].Find(&slot->mName);
        }
        if (node) {
            slot->mnResolved = node->mnValue;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0058b630 score 267
bool cUnk00a9f040::Slot22_a9f040(const char* name, uint32_t id, const char* newName)
{
    Body_a9f040* body = BodyOf_a9f040(this);
    body->mKey.Assign(name, name + strlen(name));
    Transform_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, body->mKey.mpBegin, tolower);
    Range_a9f040 range;
    body->mTable[0].mMap.EqualRange(&range, &body->mKey);
    HIter_a9f040 first = range.mFirst;
    Node_a9f040* last = range.mLast.mpCur;
    uint32_t distinct = 0;
    for (Node_a9f040* cur = first.mpCur; cur != last;) {
        if (cur == first.mpCur || cur->mnValue != first.mpCur->mnValue) {
            ++distinct;
        }
        Node_a9f040* next = cur->mpNext;
        if (!next) {
            uint32_t hash = 0;
            for (uint32_t i = 0; i < static_cast<uint32_t>(cur->mKey.mpEnd - cur->mKey.mpBegin); ++i) {
                hash = hash * 5 + cur->mKey.mpBegin[i];
            }
            HashMap_a9f040* table = first.mpTable;
            uint32_t bucket = hash % static_cast<uint32_t>(table->mpBucketsFinish - table->mpBucketsStart);
            while (!next) {
                ++bucket;
                if (bucket >= static_cast<uint32_t>(table->mpBucketsFinish - table->mpBucketsStart)) {
                    break;
                }
                next = table->mpBucketsStart[bucket];
            }
        }
        cur = next;
    }
    if (distinct == 0) {
        return false;
    }
    int32_t index = first.mpCur->mnValue;
    body->mTable[0].mVec.mModel.mpStart[index].mnId = id;
    if (newName) {
        body->mKey.Assign(newName, newName + strlen(newName));
    }
    LowerInline_a9f040(&body->mKey);
    int32_t found = CStr_a9f040(body->mKey.mpBegin).Lookup(this, id);
    if (found < 0) {
        body->mTable[0].mMap.InsertEqual(Pair_a9f040(body->mKey.mpBegin, body->mKey.mpEnd, index));
    } else if (found != index) {
        return false;
    }
    return true;
}
#endif
