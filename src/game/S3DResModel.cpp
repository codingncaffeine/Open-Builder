#include <new>
#include "classes/cS3DResModel.h"
#include "classes/cUnk00abd594.h"
#include "common/compiler.h"
#include "gzcom/cRZString.h"

// The refcounted objects the model's containers hold; the count is a 16-bit field at the offset each type has.
struct RefAt0_abd5d4 {
    uint16_t mnRef;
};
struct RefAt2_abd5d4 {
    uint16_t mnPad;
    uint16_t mnRef;
};
struct RefAtC_abd5d4 {
    uint8_t mPad[0xc];
    uint16_t mnRef;
};

// An interface object reached through a pointer (only its three first slots are called).
struct Unknown_abd5d4 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

// The model instance classes: one with a counted subobject at 8, one at 4 (animated, 0xa4 bytes).
struct InstBase_abd5d4 : Unknown_abd5d4 {
    // STUB: 0x00801c40
    void SetModelResource(cUnk00abd5d4* res);
};
struct InstAnim_abd5d4 {
    // STUB: 0x00802950
    InstAnim_abd5d4* Fn00802950(int flag);
};
struct Inst_abd5d4 {
    // STUB: 0x007fd870
    Inst_abd5d4* Fn007fd870(int flag);
};
struct MeshMat_abd5d4 {
    // STUB: 0x00802900
    MeshMat_abd5d4* Fn00802900();
};

// STUB: 0x00801b00
void* Fn00801b00(uint32_t size);
// STUB: 0x007fb640
void* Fn007fb640(uint32_t size);

// A 0x34-byte material and a 0xc-byte record that are copied element by element.
struct Material_abd5d4 {
    // STUB: 0x00802130
    Material_abd5d4(const Material_abd5d4& other);
    // STUB: 0x00802240
    Material_abd5d4& operator=(const Material_abd5d4& other);
    uint8_t mData[0x34];
};
struct Record_abd5d4 {
    // STUB: 0x008024f0
    Record_abd5d4& operator=(const Record_abd5d4& other);
    uint8_t mData[0xc];
};

#ifdef OB_DRAFTS
// CLOSE: 0x00804090 score 23
bool cS3DResModel::QueryInterface(unsigned int id, void** out)
{
    *out = 0;
    if (id == 0x456b8f1d) {
        *out = static_cast<cGZPersistResource*>(this);
    } else if (id == 0x9ad0e7e3) {
        *out = this;
    } else {
        *out = 0;
        return false;
    }
    if (*out == 0) {
        return false;
    }
    AddRef();
    return true;
}
#endif

// FUNCTION: 0x008040e0
bool cS3DResModel::Slot05_abd5d4(uint32_t id, void* out)
{
    void* mem = Fn00801b00(0xa4);
    InstAnim_abd5d4* inst;
    if (mem) {
        inst = static_cast<InstAnim_abd5d4*>(mem)->Fn00802950(1);
    } else {
        inst = 0;
    }
    InstBase_abd5d4* sub = reinterpret_cast<InstBase_abd5d4*>(inst);
    sub->AddRef();
    if (Slot08_abd5d4(id, reinterpret_cast<char*>(inst) + 4)) {
        sub->SetModelResource(this);
        char* base = reinterpret_cast<char*>(inst);
        int32_t* vbtable = *reinterpret_cast<int32_t**>(base + 0x20);
        *static_cast<char**>(out) = base + vbtable[1] + 0x20;
        return true;
    }
    sub->Release();
    return false;
}

// FUNCTION: 0x00804150
bool cS3DResModel::Slot04_abd5d4(uint32_t id, void* out)
{
    void* mem = Fn007fb640(0xd0);
    Inst_abd5d4* inst;
    if (mem) {
        inst = static_cast<Inst_abd5d4*>(mem)->Fn007fd870(1);
    } else {
        inst = 0;
    }
    InstBase_abd5d4* sub = reinterpret_cast<InstBase_abd5d4*>(reinterpret_cast<char*>(inst) + 8);
    sub->AddRef();
    if (Slot08_abd5d4(id, reinterpret_cast<char*>(inst) + 0xc)) {
        sub->SetModelResource(this);
        *static_cast<Inst_abd5d4**>(out) = inst;
        return true;
    }
    sub->Release();
    return false;
}

// FUNCTION: 0x008041c0
bool cS3DResModel::Slot06_abd5d4(uint32_t id, void* out)
{
    void* mem = operator new(0x20);
    MeshMat_abd5d4* mesh;
    if (mem) {
        mesh = static_cast<MeshMat_abd5d4*>(mem)->Fn00802900();
    } else {
        mesh = 0;
    }
    Unknown_abd5d4* unk = reinterpret_cast<Unknown_abd5d4*>(mesh);
    unk->AddRef();
    if (Slot08_abd5d4(id, reinterpret_cast<char*>(mesh) + 4)) {
        *static_cast<MeshMat_abd5d4**>(out) = mesh;
        return true;
    }
    unk->Release();
    return false;
}

// Destroys a held reference: releases the object when there is one.
#ifdef OB_DRAFTS
// CLOSE: 0x00804220 score 32
void Fn00804220(Unknown_abd5d4** held)
{
    if (*held) {
        (*held)->Release();
    }
}
#endif

// Copies the pointers of [first, last) to dest, counting a reference for each.
#ifdef OB_DRAFTS
// CLOSE: 0x008042e0 score 20
void Fn008042e0(RefAtC_abd5d4** first, RefAtC_abd5d4** last, RefAtC_abd5d4** dest)
{
    for (; first != last; ++first, ++dest) {
        if (dest) {
            RefAtC_abd5d4* v = *first;
            *dest = v;
            if (v) {
                ++v->mnRef;
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00804340 score 20
void Fn00804340(RefAt0_abd5d4** first, RefAt0_abd5d4** last, RefAt0_abd5d4** dest)
{
    for (; first != last; ++first, ++dest) {
        if (dest) {
            RefAt0_abd5d4* v = *first;
            *dest = v;
            if (v) {
                ++v->mnRef;
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008043a0 score 20
void Fn008043a0(RefAt2_abd5d4** first, RefAt2_abd5d4** last, RefAt2_abd5d4** dest)
{
    for (; first != last; ++first, ++dest) {
        if (dest) {
            RefAt2_abd5d4* v = *first;
            *dest = v;
            if (v) {
                ++v->mnRef;
            }
        }
    }
}
#endif

// Fills count slots at dest with the pointer held in *value, counting a reference for each.
#ifdef OB_DRAFTS
// CLOSE: 0x00804310 score 20
void Fn00804310(RefAtC_abd5d4** dest, uint32_t count, RefAtC_abd5d4* const* value)
{
    for (; count > 0; --count, ++dest) {
        if (dest) {
            RefAtC_abd5d4* v = *value;
            *dest = v;
            if (v) {
                ++v->mnRef;
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00804370 score 20
void Fn00804370(RefAt0_abd5d4** dest, uint32_t count, RefAt0_abd5d4* const* value)
{
    for (; count > 0; --count, ++dest) {
        if (dest) {
            RefAt0_abd5d4* v = *value;
            *dest = v;
            if (v) {
                ++v->mnRef;
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008043d0 score 20
void Fn008043d0(RefAt2_abd5d4** dest, uint32_t count, RefAt2_abd5d4* const* value)
{
    for (; count > 0; --count, ++dest) {
        if (dest) {
            RefAt2_abd5d4* v = *value;
            *dest = v;
            if (v) {
                ++v->mnRef;
            }
        }
    }
}
#endif

// Assigns *value to every material of [first, last).
// FUNCTION: 0x00804680
void Fn00804680(Material_abd5d4* first, Material_abd5d4* last, const Material_abd5d4* value)
{
    for (; first != last; ++first) {
        *first = *value;
    }
}

// FUNCTION: 0x00804dc0
void Fn00804dc0(Record_abd5d4* first, Record_abd5d4* last, const Record_abd5d4* value)
{
    for (; first != last; ++first) {
        *first = *value;
    }
}

// Copy-constructs count materials at dest from *value; returns the end.
#ifdef OB_DRAFTS
// CLOSE: 0x008046b0 score 12
Material_abd5d4* Fn008046b0(Material_abd5d4* dest, uint32_t count, const Material_abd5d4* value)
{
    for (uint32_t n = count; n > 0; --n, ++dest) {
        if (dest) {
            new (dest) Material_abd5d4(*value);
        }
    }
    return dest;
}
#endif

// A texture binding held by an index array (released through its own method).
struct TexBind_abd5d4 {
    // STUB: 0x008090e0
    uint32_t Release();
};
struct Binding_abd5d4 {
    TexBind_abd5d4* mpBinding;
    uint8_t mPad[0x10];
    ~Binding_abd5d4()
    {
        if (mpBinding) {
            mpBinding->Release();
        }
    }
};

// The index array: a 16-bit count at 2 and two 0x14-byte bindings from 0x10 on. The STUB view is what the callers use;
// the Draft view carries the body of 0x008045b0.
struct IndexArrData_abd5d4 {
    uint16_t mnPad0;
    uint16_t mnRef;
    uint8_t mPad[0xc];
    Binding_abd5d4 mBindings[2];
};
struct IndexArr_abd5d4 : IndexArrData_abd5d4 {
    // STUB: 0x008045b0
    uint32_t Release();
};
struct IndexArrDraft_abd5d4 : IndexArrData_abd5d4 {
    uint32_t Release();
};

// The vertex data: a vector of 16-bit values (begin at 0, end of storage at 8) and a count at 0xc.
struct Alloc_abd5d4 {
    uint16_t* mpEnd;
    // STUB: 0x00614380
    void Fn00614380(void* p, uint32_t count);
};
struct VertexData_abd5d4 {
    uint16_t* mpBegin;
    uint16_t* mpFinish;
    Alloc_abd5d4 mAlloc;
    uint16_t mnRef;
    ~VertexData_abd5d4()
    {
        if (mpBegin) {
            mAlloc.Fn00614380(mpBegin, static_cast<uint32_t>(mAlloc.mpEnd - mpBegin));
        }
    }
    // STUB: 0x00800ec0
    static void operator delete(void* p, size_t size);
};
struct VertexDataRef_abd5d4 {
    // STUB: 0x00616490
    uint32_t Release();
    uint16_t mnRef;
};

// FUNCTION: 0x008045b0
uint32_t IndexArrDraft_abd5d4::Release()
{
    if (mnRef > 1) {
        return --mnRef;
    }
    delete this;
    return 0;
}

// Assigns *value to every slot of [first, last), counting and releasing references.
// FUNCTION: 0x00804800
void Fn00804800(IndexArr_abd5d4** first, IndexArr_abd5d4** last, IndexArr_abd5d4* const* value)
{
    for (; first != last; ++first) {
        if (value != first) {
            IndexArr_abd5d4* a = *value;
            IndexArr_abd5d4* old = *first;
            if (a != old) {
                if (a) {
                    ++a->mnRef;
                }
                *first = a;
                if (old) {
                    old->Release();
                }
            }
        }
    }
}

// Copies [first, last) backwards to end at dest; returns the new start.
// FUNCTION: 0x00804730
IndexArr_abd5d4** Fn00804730(IndexArr_abd5d4** first, IndexArr_abd5d4** last, IndexArr_abd5d4** dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        --last;
        --dest;
        if (last != dest) {
            IndexArr_abd5d4* a = *last;
            IndexArr_abd5d4* old = *dest;
            if (a != old) {
                if (a) {
                    ++a->mnRef;
                }
                *dest = a;
                if (old) {
                    old->Release();
                }
            }
        }
    }
    return dest;
}

// Copies [first, last) forwards to dest; returns the new end.
// FUNCTION: 0x008048d0
IndexArr_abd5d4** Fn008048d0(IndexArr_abd5d4** first, IndexArr_abd5d4** last, IndexArr_abd5d4** dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        if (first != dest) {
            IndexArr_abd5d4* a = *first;
            IndexArr_abd5d4* old = *dest;
            if (a != old) {
                if (a) {
                    ++a->mnRef;
                }
                *dest = a;
                if (old) {
                    old->Release();
                }
            }
        }
        ++first;
        ++dest;
    }
    return dest;
}

// Releases every index array of [first, last) (the release inlined).
// FUNCTION: 0x008049c0
void Fn008049c0(IndexArrDraft_abd5d4** first, IndexArrDraft_abd5d4** last)
{
    for (; first != last; ++first) {
        if (*first) {
            (*first)->Release();
        }
    }
}

// Assigns *value to every slot of [first, last) (vertex data references).
// FUNCTION: 0x00804790
void Fn00804790(VertexData_abd5d4** first, VertexData_abd5d4** last, VertexData_abd5d4* const* value)
{
    for (; first != last; ++first) {
        if (value != first) {
            VertexData_abd5d4* a = *value;
            VertexData_abd5d4* old = *first;
            if (a != old) {
                if (a) {
                    ++a->mnRef;
                }
                *first = a;
                if (old) {
                    if (old->mnRef > 1) {
                        --old->mnRef;
                    } else {
                        delete old;
                    }
                }
            }
        }
    }
}

// FUNCTION: 0x00804930
VertexData_abd5d4** Fn00804930(VertexData_abd5d4** first, VertexData_abd5d4** last, VertexData_abd5d4** dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        --last;
        --dest;
        if (last != dest) {
            VertexData_abd5d4* a = *last;
            VertexData_abd5d4* old = *dest;
            if (a != old) {
                if (a) {
                    ++a->mnRef;
                }
                *dest = a;
                if (old) {
                    if (old->mnRef > 1) {
                        --old->mnRef;
                    } else {
                        delete old;
                    }
                }
            }
        }
    }
    return dest;
}

// FUNCTION: 0x00804a20
void Fn00804a20(VertexDataRef_abd5d4** first, VertexDataRef_abd5d4** last, VertexDataRef_abd5d4* const* value)
{
    for (; first != last; ++first) {
        if (value != first) {
            VertexDataRef_abd5d4* a = *value;
            VertexDataRef_abd5d4* old = *first;
            if (a != old) {
                if (a) {
                    ++a->mnRef;
                }
                *first = a;
                if (old) {
                    old->Release();
                }
            }
        }
    }
}

// Assigns [first, last) backwards to end at dest, material by material.
// FUNCTION: 0x008046e0
Material_abd5d4* Fn008046e0(Material_abd5d4* first, Material_abd5d4* last, Material_abd5d4* dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        --last;
        --dest;
        *dest = *last;
    }
    return dest;
}

// The pool a freed block returns to: the page header sits at the 8 KB boundary below the block.
struct PoolPage_abd5d4 {
    uint8_t mPad[8];
    void* mpFree;
    uint32_t mnUsed;
};
// STUB: 0x0090d8e0
void* Fn0090d8e0(uint32_t kind);
// STUB: 0x0090d031
void OB_STDCALL Fn0090d031(void* page);
// STUB: 0x0090cff9
void OB_STDCALL Fn0090cff9(void* page);

#ifdef OB_DRAFTS
// CLOSE: 0x00804270 score 2
void Fn00804270()
{
    PoolPage_abd5d4* page = static_cast<PoolPage_abd5d4*>(Fn0090d8e0(0xd));
    uint8_t* cur = reinterpret_cast<uint8_t*>(page) + 0x1f10;
    void* prev = 0;
    void* last = 0;
    for (int32_t n = 0x41; n > 0; --n) {
        *reinterpret_cast<void**>(cur) = prev;
        last = cur;
        prev = cur;
        cur -= 0x7c;
    }
    page->mpFree = last;
    page->mnUsed = 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00804570 score 28
void OB_STDCALL Fn00804570(void* block)
{
    if (block) {
        PoolPage_abd5d4* page = reinterpret_cast<PoolPage_abd5d4*>(reinterpret_cast<uintptr_t>(block) & ~static_cast<uintptr_t>(0x1fff));
        *reinterpret_cast<void**>(block) = page->mpFree;
        page->mpFree = block;
        uint32_t used = page->mnUsed - 1;
        page->mnUsed = used;
        if (used == 0) {
            Fn0090d031(page);
        } else if (used == 0x40000030) {
            Fn0090cff9(page);
        }
    }
}
#endif

// FUNCTION: 0x00804a60
VertexDataRef_abd5d4** Fn00804a60(VertexDataRef_abd5d4** first, VertexDataRef_abd5d4** last, VertexDataRef_abd5d4** dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        if (first != dest) {
            VertexDataRef_abd5d4* a = *first;
            VertexDataRef_abd5d4* old = *dest;
            if (a != old) {
                if (a) {
                    ++a->mnRef;
                }
                *dest = a;
                if (old) {
                    old->Release();
                }
            }
        }
        ++first;
        ++dest;
    }
    return dest;
}

// FUNCTION: 0x00804ac0
VertexDataRef_abd5d4** Fn00804ac0(VertexDataRef_abd5d4** first, VertexDataRef_abd5d4** last, VertexDataRef_abd5d4** dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        --last;
        --dest;
        if (last != dest) {
            VertexDataRef_abd5d4* a = *last;
            VertexDataRef_abd5d4* old = *dest;
            if (a != old) {
                if (a) {
                    ++a->mnRef;
                }
                *dest = a;
                if (old) {
                    old->Release();
                }
            }
        }
    }
    return dest;
}

// FUNCTION: 0x00804b20
Record_abd5d4* Fn00804b20(Record_abd5d4* first, Record_abd5d4* last, Record_abd5d4* dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        --last;
        --dest;
        *dest = *last;
    }
    return dest;
}

// Releases every vertex data of [first, last) (the release inlined).
// FUNCTION: 0x00804e70
void Fn00804e70(VertexData_abd5d4** first, VertexData_abd5d4** last)
{
    for (; first != last; ++first) {
        VertexData_abd5d4* data = *first;
        if (data) {
            if (data->mnRef > 1) {
                --data->mnRef;
            } else {
                delete data;
            }
        }
    }
}

// A record of two numbers and two names (0x2c bytes).
struct NamePair_abd5d4 {
    uint16_t mnFirst;
    uint16_t mnSecond;
    cRZString mName1;
    cRZString mName2;
    NamePair_abd5d4(const NamePair_abd5d4& other);
    NamePair_abd5d4& operator=(const NamePair_abd5d4& other);
};

// FUNCTION: 0x00804df0
NamePair_abd5d4::NamePair_abd5d4(const NamePair_abd5d4& other)
    : mnFirst(other.mnFirst), mnSecond(other.mnSecond), mName1(other.mName1), mName2(other.mName2)
{
}

// A map node: balance data, the two children, the key and the value string.
struct TreeNode_abd5d4 {
    uint8_t mPad[8];
    TreeNode_abd5d4* mpLeft;
    TreeNode_abd5d4* mpRight;
    cRZString mKey;
    std::string mValue;
};
// STUB: 0x0090cf63
void Fn0090cf63(void* block);
struct Tree_abd5d4 {
    void Erase(TreeNode_abd5d4* node);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00804ed0 score 13
void Tree_abd5d4::Erase(TreeNode_abd5d4* node)
{
    while (node) {
        Erase(node->mpRight);
        TreeNode_abd5d4* left = node->mpLeft;
        node->mValue.~basic_string();
        node->mKey.~cRZString();
        Fn0090cf63(node);
        node = left;
    }
}
#endif

// A bounding box: the minimum corner, then the maximum corner; an empty box has its minimum above its maximum.
struct BBox_abd5d4 {
    float mfMinX;
    float mfMinY;
    float mfMinZ;
    float mfMaxX;
    float mfMaxY;
    float mfMaxZ;
};
// One mesh of the model: 0x1c bytes, its frame entries (8 bytes each, the vertex array index first) at 0x18.
struct ResMesh_abd5d4 {
    uint8_t mPad[0x18];
    int16_t* mpFrames;
};
// A vertex array: the box of its vertices at 0x14.
struct VertexArr_abd5d4 {
    uint8_t mPad[0x14];
    BBox_abd5d4 mBounds;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00804400 score 114
void cS3DResModel::Slot07_abd5d4(void* box)
{
    BBox_abd5d4* bounds = static_cast<BBox_abd5d4*>(box);
    bounds->mfMinX = 1.0f;
    bounds->mfMinY = 1.0f;
    bounds->mfMinZ = 1.0f;
    bounds->mfMaxX = 0.0f;
    bounds->mfMaxY = 0.0f;
    bounds->mfMaxZ = 0.0f;
    for (int32_t frame = 0; frame < mnFrameCount; ++frame) {
        for (int32_t mesh = 0; mesh < mnMeshCount; ++mesh) {
            ResMesh_abd5d4* part = reinterpret_cast<ResMesh_abd5d4*>(static_cast<uint8_t*>(mpMeshes) + mesh * 0x1c);
            VertexArr_abd5d4** arrays = static_cast<VertexArr_abd5d4**>(mpVertexArrays);
            const BBox_abd5d4* other = &arrays[part->mpFrames[frame * 4]]->mBounds;
            if (other->mfMinX <= other->mfMaxX) {
                if (bounds->mfMinX <= bounds->mfMaxX) {
                    if (bounds->mfMaxX <= other->mfMaxX) {
                        bounds->mfMaxX = other->mfMaxX;
                    }
                    if (bounds->mfMinX >= other->mfMinX) {
                        bounds->mfMinX = other->mfMinX;
                    }
                    if (bounds->mfMaxY <= other->mfMaxY) {
                        bounds->mfMaxY = other->mfMaxY;
                    }
                    if (bounds->mfMinY >= other->mfMinY) {
                        bounds->mfMinY = other->mfMinY;
                    }
                    if (bounds->mfMaxZ <= other->mfMaxZ) {
                        bounds->mfMaxZ = other->mfMaxZ;
                    }
                    if (bounds->mfMinZ >= other->mfMinZ) {
                        bounds->mfMinZ = other->mfMinZ;
                    }
                } else {
                    *bounds = *other;
                }
            }
        }
    }
}
#endif

// An entry of a list of names: a number, a name, and a pointer-sized tail (0x1c bytes).
struct NameEntry_abd5d4 {
    uint32_t mnValue;
    cRZString mName;
    uint32_t mnTail;
};

// Destroys the entries of [first, last).
// FUNCTION: 0x00805150
void Fn00805150(NameEntry_abd5d4* first, NameEntry_abd5d4* last)
{
    for (; first != last; ++first) {
        first->~NameEntry_abd5d4();
    }
}

// The assignment of the two-name record.
// FUNCTION: 0x00805200
NamePair_abd5d4& NamePair_abd5d4::operator=(const NamePair_abd5d4& other)
{
    mnSecond = other.mnSecond;
    mnFirst = other.mnFirst;
    mName1 = other.mName1;
    mName2 = other.mName2;
    return *this;
}

// A counted vector of records (count at 0, begin at 4, end of storage at 0xc).
struct AllocR_abd5d4 {
    Record_abd5d4* mpEnd;
    // STUB: 0x00614380
    void Fn00614380(void* p, uint32_t count);
};
struct RecordVec_abd5d4 {
    uint16_t mnRef;
    uint16_t mnPad;
    Record_abd5d4* mpBegin;
    Record_abd5d4* mpFinish;
    AllocR_abd5d4 mAlloc;
    ~RecordVec_abd5d4()
    {
        if (mpBegin) {
            mAlloc.Fn00614380(mpBegin, static_cast<uint32_t>(mAlloc.mpEnd - mpBegin));
        }
    }
    // STUB: 0x00800ec0
    static void operator delete(void* p, size_t size);
};

// Releases every record vector of [first, last) (the release inlined).
#ifdef OB_DRAFTS
// CLOSE: 0x008050e0 score 13
void Fn008050e0(RecordVec_abd5d4** first, RecordVec_abd5d4** last)
{
    for (; first != last; ++first) {
        RecordVec_abd5d4* data = *first;
        if (data) {
            if (data->mnRef > 1) {
                --data->mnRef;
            } else {
                delete data;
            }
        }
    }
}
#endif

// The factory of the model resource: the class id picks it, the interface id is asked of the new object.
struct ModelPool_abd5d4 {
    // STUB: 0x0090cf9a
    void* Fn0090cf9a();
};
// GLOBAL: 0x00b0e38c
extern PoolPage_abd5d4* gpB0e38c;
// GLOBAL: 0x00b0e388
extern ModelPool_abd5d4 gB0e388;
struct ModelNew_abd5d4 {
    // STUB: 0x008061b0
    Unknown_abd5d4* Fn008061b0();
};
struct Deletable_abd5d4 {
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
    virtual void Delete(uint32_t flags);
};

// FUNCTION: 0x008065c0
bool cUnk00abd594::Slot09_ad8c20(uint32_t clsid, uint32_t iid, uint32_t out)
{
    void** result = OB_PTR(void*, out);
    if (clsid == 0x5ad0e817) {
        void** block = static_cast<void**>(gpB0e38c->mpFree);
        if (block == 0) {
            block = static_cast<void**>(gB0e388.Fn0090cf9a());
        }
        gpB0e38c->mpFree = *block;
        ++gpB0e38c->mnUsed;
        Unknown_abd5d4* model = static_cast<ModelNew_abd5d4*>(static_cast<void*>(block))->Fn008061b0();
        if (model->QueryInterface(iid, result)) {
            return true;
        }
        Deletable_abd5d4* sub = reinterpret_cast<Deletable_abd5d4*>(reinterpret_cast<char*>(model) + 4);
        sub->Delete(1);
    }
    *result = 0;
    return false;
}

// The header node of an ordered map (0x30 bytes): colour, parent, and the two ends, which point at itself when empty.
struct MapHeader_abd5d4 {
    uint8_t mbColor;
    uint8_t mPad[3];
    void* mpParent;
    MapHeader_abd5d4* mpLeft;
    MapHeader_abd5d4* mpRight;
};
// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

// The model's info block at 0x4c: counts, flags and an ordered map (0x24 bytes).
struct ModelInfo_abd5d4 {
    uint16_t mnFrames;
    uint16_t mnSecond;
    uint8_t mbMode;
    uint8_t mbFlag;
    uint32_t mn8;
    uint16_t mnC;
    uint32_t mn10;
    uint32_t mn14;
    MapHeader_abd5d4* mpHeader;
    uint32_t mnSize;
    ModelInfo_abd5d4();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00806040 score 2
ModelInfo_abd5d4::ModelInfo_abd5d4()
{
    mnFrames = 0;
    mnSecond = 0;
    mbMode = 3;
    mbFlag = 0;
    mn8 = 0;
    mnC = 0;
    mn10 = 0;
    mn14 = 0;
    mpHeader = 0;
    mpHeader = static_cast<MapHeader_abd5d4*>(Fn0090cf54(0x30));
    mnSize = 0;
    mpHeader->mbColor = 0;
    mpHeader->mpParent = 0;
    mpHeader->mpLeft = mpHeader;
    mpHeader->mpRight = mpHeader;
}
#endif

// Two vectors of counted pointers: the Resize that shrinks by erasing the tail or grows by filling.
// STUB: 0x00804840
VertexData_abd5d4** Fn00804840(VertexData_abd5d4** first, VertexData_abd5d4** last, VertexData_abd5d4** dest);
struct VecVD_abd5d4 {
    VertexData_abd5d4** mpBegin;
    VertexData_abd5d4** mpEnd;
    // STUB: 0x00805b30
    void Fn00805b30(VertexData_abd5d4** where, uint32_t count, VertexData_abd5d4* const* value);
    void Resize(uint32_t count, VertexData_abd5d4* const* value);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00806230 score 9
void VecVD_abd5d4::Resize(uint32_t count, VertexData_abd5d4* const* value)
{
    VertexData_abd5d4** end = mpEnd;
    uint32_t size = static_cast<uint32_t>(end - mpBegin);
    if (count < size) {
        VertexData_abd5d4** newEnd = Fn00804840(end, end, mpBegin + count);
        Fn00804e70(newEnd, mpEnd);
        mpEnd = newEnd;
    } else {
        Fn00805b30(end, count - size, value);
    }
}
#endif

struct VecRV_abd5d4 {
    RecordVec_abd5d4** mpBegin;
    RecordVec_abd5d4** mpEnd;
    // STUB: 0x00806090
    void Fn00806090(RecordVec_abd5d4** where, uint32_t count, RecordVec_abd5d4* const* value);
    void Resize(uint32_t count, RecordVec_abd5d4* const* value);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008068e0 score 9
void VecRV_abd5d4::Resize(uint32_t count, RecordVec_abd5d4* const* value)
{
    RecordVec_abd5d4** end = mpEnd;
    uint32_t size = static_cast<uint32_t>(end - mpBegin);
    if (count < size) {
        RecordVec_abd5d4** newEnd = reinterpret_cast<RecordVec_abd5d4**>(
            Fn00804a60(reinterpret_cast<VertexDataRef_abd5d4**>(end), reinterpret_cast<VertexDataRef_abd5d4**>(end),
                       reinterpret_cast<VertexDataRef_abd5d4**>(mpBegin + count)));
        Fn008050e0(newEnd, mpEnd);
        mpEnd = newEnd;
    } else {
        Fn00806090(end, count - size, value);
    }
}
#endif
