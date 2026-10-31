#include <new>
#include <cstddef>

#include "classes/cSC4TrafficNetworkMap.h"

#define OB_FIELD(Type, base, off) (*reinterpret_cast<Type*>(reinterpret_cast<char*>(base) + (off)))

// GLOBAL: 0x00b217f0
extern float gfB217f0;

// GLOBAL: 0x00a84d2c
extern const float gfA84d2c;

// GLOBAL: 0x00a8fdf4
extern const float gfA8fdf4;

struct PosB_a8fed8;

struct OccA_a8fed8 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual void Pad7c();
    virtual void Pad80();
    virtual void Pad84();
    virtual void Pad88();
    virtual void Pad8c();
    virtual void Pad90();
    virtual void Pad94();
    virtual void Pad98();
    virtual void Pad9c();
    virtual void Pada0();
    virtual void Pada4();
    virtual void Pada8();
    virtual void Padac();
    virtual void Padb0();
    virtual void Padb4();
    virtual void Padb8();
    virtual void Padbc();
    virtual PosB_a8fed8* S_c0();
    virtual void* S_c4();
    virtual void Padc8();
    virtual void Padcc();
    virtual void Padd0();
    virtual char S_d4(uint32_t, uint32_t, uint32_t);
    virtual void Padd8();
    virtual void Paddc();
    virtual void Pade0();
    virtual void Pade4();
    virtual void Pade8();
    virtual void S_ec(void*, void*);
};

struct ObjB_a8fed8 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual bool S_34(uint32_t);
};

struct AutoA_a8fed8 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual void Pad7c();
    virtual void Pad80();
    virtual void Pad84();
    virtual void Pad88();
    virtual void Pad8c();
    virtual void Pad90();
    virtual void Pad94();
    virtual void Pad98();
    virtual void Pad9c();
    virtual void Pada0();
    virtual void Pada4();
    virtual void Pada8();
    virtual void Padac();
    virtual void Padb0();
    virtual void Padb4();
    virtual void Padb8();
    virtual void Padbc();
    virtual void Padc0();
    virtual void Padc4();
    virtual void Padc8();
    virtual void Padcc();
    virtual void Padd0();
    virtual void Padd4();
    virtual void Padd8();
    virtual void Paddc();
    virtual void Pade0();
    virtual void Pade4();
    virtual void Pade8();
    virtual void Padec();
    virtual void Padf0();
    virtual void Padf4();
    virtual void Padf8();
    virtual void Padfc();
    virtual void Pad100();
    virtual void Pad104();
    virtual void Pad108();
    virtual void Pad10c();
    virtual void Pad110();
    virtual void Pad114();
    virtual void Pad118();
    virtual void Pad11c();
    virtual void Pad120();
    virtual void Pad124();
    virtual void Pad128();
    virtual void Pad12c();
    virtual void Pad130();
    virtual void Pad134();
    virtual void Pad138();
    virtual void Pad13c();
    virtual void Pad140();
    virtual void Pad144();
    virtual void Pad148();
    virtual void Pad14c();
    virtual void Pad150();
    virtual bool S_154();
    virtual void Pad158();
    virtual void Pad15c();
    virtual void Pad160();
    virtual void Pad164();
    virtual void Pad168();
    virtual void Pad16c();
    virtual void Pad170();
    virtual void Pad174();
    virtual void Pad178();
    virtual void Pad17c();
    virtual void Pad180();
    virtual void Pad184();
    virtual void Pad188();
    virtual void Pad18c();
    virtual void Pad190();
    virtual void Pad194();
    virtual void Pad198();
    virtual void Pad19c();
    virtual void Pad1a0();
    virtual void Pad1a4();
    virtual void Pad1a8();
    virtual void Pad1ac();
    virtual void Pad1b0();
    virtual void Pad1b4();
    virtual void Pad1b8();
    virtual void Pad1bc();
    virtual void Pad1c0();
    virtual void Pad1c4();
    virtual void Pad1c8();
    virtual void Pad1cc();
    virtual void Pad1d0();
    virtual void Pad1d4();
    virtual void Pad1d8();
    virtual void Pad1dc();
    virtual void Pad1e0();
    virtual void Pad1e4();
    virtual void Pad1e8();
    virtual void Pad1ec();
    virtual void Pad1f0();
    virtual void Pad1f4();
    virtual void Pad1f8();
    virtual void Pad1fc();
    virtual void Pad200();
    virtual void Pad204();
    virtual void Pad208();
    virtual void Pad20c();
    virtual void Pad210();
    virtual void Pad214();
    virtual void Pad218();
    virtual void Pad21c();
    virtual uint32_t S_220();
};

struct PosB_a8fed8 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void S_20(void*);
};

struct LNodeA_a8fed8 {
    LNodeA_a8fed8* mpNext;
    LNodeA_a8fed8* mpPrev;
    void* mpData;
};


// A tile's record in the tile table: the network occupant first, the next record of the cell at +0x54.
struct TileInfo_a8fed8 {
    void* mpOccupant;
    char pad04[0x50];
    TileInfo_a8fed8* mpNext;
};

// FUNCTION: 0x004b3ac0
void* cSC4TrafficNetworkMap::GetTileInfoAtCell(uint32_t x, uint32_t y)
{
    return mpTileInfo[(y << mnShift) + x];
}

// FUNCTION: 0x004ae0c0
void* cSC4TrafficNetworkMap::SafeGetTileInfoAtCell(int32_t x, int32_t y)
{
    void* result = 0;
    if (x >= 0 && x < mnWidth && y >= 0 && y < mnHeight) {
        result = GetTileInfoAtCell(x, y);
    }
    return result;
}

// FUNCTION: 0x004ae140
void* cSC4TrafficNetworkMap::FindNetworkOccupant_5(int32_t x, int32_t y)
{
    TileInfo_a8fed8* info = static_cast<TileInfo_a8fed8*>(SafeGetTileInfoAtCell(x, y));
    if (info) {
        return info->mpOccupant;
    }
    return 0;
}

// FUNCTION: 0x004ae160
void* cSC4TrafficNetworkMap::FindNetworkOccupant_4(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    TileInfo_a8fed8* info = static_cast<TileInfo_a8fed8*>(FindNetworkTile(a, b, c, d));
    if (info) {
        return info->mpOccupant;
    }
    return 0;
}

// FUNCTION: 0x004ae190
void cSC4TrafficNetworkMap::FindNetworkOccupant(uint32_t pos, uint32_t a, uint32_t b)
{
    const float* p = OB_PTR(const float, pos);
    FindNetworkOccupant_2(static_cast<int32_t>(p[0] * 0.0625f), static_cast<int32_t>(p[2] * 0.0625f), a, b);
}

// FUNCTION: 0x004afaa0
unsigned int cSC4TrafficNetworkMap::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Shutdown();
    delete this;
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004ae000 score 10
bool cSC4TrafficNetworkMap::IsIntersection(void* occupant)
{
    bool result = false;
    if (occupant) {
        ObjB_a8fed8* o = static_cast<ObjB_a8fed8*>(static_cast<OccA_a8fed8*>(occupant)->S_c4());
        if (o) {
            return o->S_34(0);
        }
    }
    return result;
}
#endif

// FUNCTION: 0x004ae090
bool cSC4TrafficNetworkMap::Slot28_a8fed8(void* occupant, uint32_t b, uint32_t c, uint32_t d)
{
    bool result = false;
    if (occupant) {
        result = static_cast<OccA_a8fed8*>(occupant)->S_d4(d, b, c) != 0;
    }
    return result;
}

// FUNCTION: 0x004ae1d0
void cSC4TrafficNetworkMap::Slot24_a8fed8(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Slot23_a8fed8(OB_PTR(void, a), b, (((c << 16) | static_cast<uint8_t>(d)) << 8) | static_cast<uint8_t>(e));
}

// FUNCTION: 0x004ae0f0
void* cSC4TrafficNetworkMap::GetTileInfoByNetwork(void* occupant)
{
    int32_t x;
    int32_t y;
    static_cast<OccA_a8fed8*>(occupant)->S_ec(&x, &y);
    TileInfo_a8fed8* info = static_cast<TileInfo_a8fed8*>(SafeGetTileInfoAtCell(x, y));
    while (info && info->mpOccupant != occupant) {
        info = info->mpNext;
    }
    return info;
}

// ---- STL internals the file instantiates (hash table of intersections, node pool, vector copies) ----

// STUB: 0x0090cf63
void Fn0090cf63(void* p);
// STUB: 0x0090d8e0
void* Fn0090d8e0(uint32_t shift);
// STUB: 0x0090d031
void OB_STDCALL Fn0090d031(void* block);
// STUB: 0x0090cff9
void OB_STDCALL Fn0090cff9(void* block);

struct Unk_a8fed8 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};

struct LNode_a8fed8 {
    LNode_a8fed8* mpNext;
    LNode_a8fed8* mpPrev;
};

struct HNode_a8fed8 {
    HNode_a8fed8* mpNext;
    uint32_t mnKey;
    char mValue[1];
};

struct HTable_a8fed8 {
    uint32_t mnPad0;
    HNode_a8fed8** mpBegin;
    HNode_a8fed8** mpEnd;
    uint32_t mnPadC;
    uint32_t mnCount;

    void Erase(HNode_a8fed8** where);
    // STUB: 0x004b2e70
    void Clear();
    void ClearTrain();
    void InsertTrain(HNode_a8fed8** result, const uint32_t* keyAndValue);
    uint32_t EraseKey(const uint32_t* key);
    void ReleaseVectorsAndClear();
    void ReleaseIntersectionsAndClear();
    void ReleaseOne(void* occupant, struct Tree_a8fed8* unused);
    void Insert(HNode_a8fed8** result, const uint32_t* keyAndValue);
    void ReleaseAndClear();
    void EraseTyped(HNode_a8fed8** where);
    // STUB: 0x00584660
    void ClearStr();
};

// STUB: 0x004b2f30
void OB_STDCALL Fn004b2f30(HNode_a8fed8* node);

// A tree node: left link at +8, right link at +0xc.
struct TNode_a8fed8 {
    char pad00[8];
    TNode_a8fed8* mpLeft;
    TNode_a8fed8* mpRight;
};

struct ListBase_a8fed8 {
    char mpPad[8];
    // STUB: 0x005650a0
    ~ListBase_a8fed8();
};

struct Tree_a8fed8 {
    void DestroySubtree(TNode_a8fed8* node);
};

// A 12-byte vector of the file's element type.
struct Vec12_a8fed8 {
    void* mpBegin;
    void* mpEnd;
    void* mpCap;
    // STUB: 0x00727d70
    Vec12_a8fed8& operator=(const Vec12_a8fed8& other);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004b0070 score 28
void OB_STDCALL Fn004b0070(void* p)
{
    if (p) {
        char* block = reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(p) & 0xffffe000);
        *reinterpret_cast<void**>(p) = *reinterpret_cast<void**>(block + 8);
        *reinterpret_cast<void**>(block + 8) = p;
        int32_t n = *reinterpret_cast<int32_t*>(block + 0xc) - 1;
        *reinterpret_cast<int32_t*>(block + 0xc) = n;
        if (n == 0) {
            Fn0090d031(block);
        } else if (n == 0x40000045) {
            Fn0090cff9(block);
        }
    }
}
#endif

// FUNCTION: 0x004ae3e0
void* Fn004ae3e0()
{
    char* block = static_cast<char*>(Fn0090d8e0(0xd));
    char* link = 0;
    char* cell = block + 0x1f58;
    char* last = 0;
    for (int32_t i = 0x5c; i != 0; --i) {
        *reinterpret_cast<char**>(cell) = link;
        last = cell;
        link = cell;
        cell -= 0x58;
    }
    *reinterpret_cast<char**>(block + 8) = last;
    *reinterpret_cast<uint32_t*>(block + 0xc) = 0;
    return block;
}

// FUNCTION: 0x004afad0
void Tree_a8fed8::DestroySubtree(TNode_a8fed8* node)
{
    while (node) {
        DestroySubtree(node->mpRight);
        TNode_a8fed8* left = node->mpLeft;
        Fn0090cf63(node);
        node = left;
    }
}

// FUNCTION: 0x004b2f30
void OB_STDCALL Fn004b2f30(HNode_a8fed8* node)
{
    void** vec = reinterpret_cast<void**>(reinterpret_cast<char*>(node) + 0x48);
    for (int32_t i = 4; i != 0; --i) {
        vec -= 4;
        if (*vec) {
            Fn0090cf63(*vec);
        }
    }
    if (node) {
        Fn0090cf63(node);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x004b2610 score 2
void OB_STDCALL Fn004b2610(char* obj)
{
    reinterpret_cast<ListBase_a8fed8*>(obj + 0x68)->~ListBase_a8fed8();
    if (*reinterpret_cast<void**>(obj + 0x5c)) {
        Fn0090cf63(*reinterpret_cast<void**>(obj + 0x5c));
    }
    if (obj) {
        Fn0090cf63(obj);
    }
}
#endif

// FUNCTION: 0x004b2330
void Fn004b2330(Vec12_a8fed8* first, Vec12_a8fed8* last, const Vec12_a8fed8& value)
{
    for (; first != last; ++first) {
        *first = value;
    }
}

// FUNCTION: 0x004b2360
Vec12_a8fed8* Fn004b2360(Vec12_a8fed8* first, Vec12_a8fed8* last, Vec12_a8fed8* dest)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        *dest = *first;
        ++first;
        ++dest;
    }
    return dest;
}

// FUNCTION: 0x004b23b0
Vec12_a8fed8* Fn004b23b0(Vec12_a8fed8* first, Vec12_a8fed8* last, Vec12_a8fed8* destEnd)
{
    for (int32_t n = static_cast<int32_t>(last - first); n > 0; --n) {
        --last;
        --destEnd;
        *destEnd = *last;
    }
    return destEnd;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004b3180 score 47
void HTable_a8fed8::Erase(HNode_a8fed8** where)
{
    HNode_a8fed8* node = *where;
    if (node) {
        uint32_t bucket = node->mnKey % static_cast<uint32_t>(mpEnd - mpBegin);
        HNode_a8fed8* cur = mpBegin[bucket];
        if (cur == node) {
            mpBegin[bucket] = cur->mpNext;
            Fn004b2f30(cur);
            --mnCount;
            return;
        }
        HNode_a8fed8* next = cur->mpNext;
        if (next) {
            while (next != node) {
                cur = next;
                next = cur->mpNext;
                if (!next) {
                    return;
                }
            }
            cur->mpNext = next->mpNext;
            Fn004b2f30(next);
            --mnCount;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b2e70 score 75
void HTable_a8fed8::Clear()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        HNode_a8fed8* node = mpBegin[i];
        while (node) {
            HNode_a8fed8* next = node->mpNext;
            char* raw = reinterpret_cast<char*>(node);
            LNode_a8fed8* head = *reinterpret_cast<LNode_a8fed8**>(raw + 0x68);
            for (LNode_a8fed8* l = head->mpNext; l != head;) {
                LNode_a8fed8* following = l->mpNext;
                Fn0090cf63(l);
                l = following;
            }
            head->mpNext = head;
            head->mpPrev = head;
            if (head) {
                Fn0090cf63(head);
            }
            if (*reinterpret_cast<void**>(raw + 0x5c)) {
                Fn0090cf63(*reinterpret_cast<void**>(raw + 0x5c));
            }
            Fn0090cf63(node);
            node = next;
        }
        mpBegin[i] = 0;
    }
    mnCount = 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b19a0 score 16
void cSC4TrafficNetworkMap::Fn004b19a0(void* vec)
{
    void*** v = static_cast<void***>(vec);
    for (void** p = v[0]; p != v[1]; ++p) {
        if (*p) {
            static_cast<Unk_a8fed8*>(*p)->Release();
        }
    }
    v[1] = v[0];
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b27e0 score 29
void cSC4TrafficNetworkMap::UpdateIntersection(void* occupant)
{
    HTable_a8fed8* table = reinterpret_cast<HTable_a8fed8*>(field28);
    uint32_t count = static_cast<uint32_t>(table->mpEnd - table->mpBegin);
    uint32_t key = OB_ADDR(occupant);
    HNode_a8fed8* node = table->mpBegin[key % count];
    while (node && node->mnKey != key) {
        node = node->mpNext;
    }
    if (node) {
        Fn004b2640(occupant, node->mValue);
    }
}
#endif

// ---- Batch 3 ----

// A train junction's four path vectors (0x10 each): the vector and the index of the current path.
struct JVec_a8fed8 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    uint16_t mnCurrent;
};

#ifdef OB_DRAFTS
// CLOSE: 0x004b0930 score 22
uint32_t cSC4TrafficNetworkMap::GetTrainJunctionPath(void* occupant, uint32_t index)
{
    HTable_a8fed8* table = reinterpret_cast<HTable_a8fed8*>(field28 + 0x18);
    uint32_t count = static_cast<uint32_t>(table->mpEnd - table->mpBegin);
    uint32_t key = OB_ADDR(occupant);
    uint32_t result = 0;
    HNode_a8fed8* node = table->mpBegin[key % count];
    while (node && node->mnKey != key) {
        node = node->mpNext;
    }
    if (node) {
        JVec_a8fed8* vec = reinterpret_cast<JVec_a8fed8*>(node->mValue) + static_cast<uint8_t>(index);
        if (vec->mpBegin != vec->mpEnd) {
            result = vec->mpBegin[vec->mnCurrent];
        }
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b0990 score 32
bool cSC4TrafficNetworkMap::ToggleTrainJunction(void* occupant)
{
    HTable_a8fed8* table = reinterpret_cast<HTable_a8fed8*>(field28 + 0x18);
    uint32_t count = static_cast<uint32_t>(table->mpEnd - table->mpBegin);
    uint32_t key = OB_ADDR(occupant);
    bool result = false;
    HNode_a8fed8* node = table->mpBegin[key % count];
    while (node && node->mnKey != key) {
        node = node->mpNext;
    }
    if (node) {
        result = true;
        JVec_a8fed8* vec = reinterpret_cast<JVec_a8fed8*>(node->mValue);
        for (int32_t i = 4; i != 0; --i) {
            if (vec->mpBegin != vec->mpEnd) {
                vec->mnCurrent = static_cast<uint16_t>((vec->mnCurrent + 1u) % static_cast<uint32_t>(vec->mpEnd - vec->mpBegin));
            }
            ++vec;
        }
    }
    return result;
}
#endif

// A tile's automata are kept in a circular list at +0x1c of the tile record.
struct TileList_a8fed8 {
    void* mpOccupant;
    char pad04[0x18];
    LNodeA_a8fed8* mpList;
};

// FUNCTION: 0x004b0000
int16_t cSC4TrafficNetworkMap::GetAutomataCountForLane(void* occupant, uint32_t lane)
{
    int16_t count = 0;
    TileList_a8fed8* info = static_cast<TileList_a8fed8*>(GetTileInfoByNetwork(occupant));
    if (info) {
        for (LNodeA_a8fed8* l = info->mpList->mpNext; l != info->mpList; l = l->mpNext) {
            AutoA_a8fed8* a = static_cast<AutoA_a8fed8*>(l->mpData);
            if (!a->S_154()) {
                if (a->S_220() == lane) {
                    ++count;
                }
            }
        }
    }
    return count;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004ae030 score 27
bool cSC4TrafficNetworkMap::Slot29_a8fed8(int32_t x, int32_t y, void* c, uint32_t d, uint32_t e)
{
    bool result = false;
    TileInfo_a8fed8* info = static_cast<TileInfo_a8fed8*>(SafeGetTileInfoAtCell(x, y));
    if (info) {
        do {
            if (Slot28_a8fed8(info->mpOccupant, OB_ADDR(c), d, e)) {
                return true;
            }
            info = info->mpNext;
        } while (info);
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004ae350 score 4
bool cSC4TrafficNetworkMap::QueryInterface(unsigned int id, void** out)
{
    switch (id) {
    case 0xca0f81b9:
        *out = this;
        break;
    case 1:
        *out = static_cast<cUnk00a8298c*>(this);
        break;
    case 0x452294aa:
        *out = static_cast<cSC4TrafficNetworkMap_8*>(this);
        break;
    case 0xe4fda3d4:
        *out = static_cast<cSC4TrafficNetworkMap_c*>(this);
        break;
    default:
        return false;
    }
    AddRef();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004afa10 score 14
void* cSC4TrafficNetworkMap::FindNetworkTile(uint32_t x, uint32_t y, uint32_t lo, uint32_t hi)
{
    if (!mbActive) {
        return 0;
    }
    float pos[3];
    pos[0] = gfB217f0;
    pos[1] = gfB217f0;
    pos[2] = gfB217f0;
    for (TileInfo_a8fed8* info = static_cast<TileInfo_a8fed8*>(SafeGetTileInfoAtCell(x, y)); info; info = info->mpNext) {
        static_cast<OccA_a8fed8*>(info->mpOccupant)->S_c0()->S_20(pos);
        if (*reinterpret_cast<float*>(&lo) <= pos[1] && pos[1] <= *reinterpret_cast<float*>(&hi)) {
            return info;
        }
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004af970 score 82
void* cSC4TrafficNetworkMap::FindNetworkOccupant_3(void* position)
{
    if (!position) {
        return 0;
    }
    const float* p = static_cast<const float*>(position);
    float fx = p[0] * 0.0625f;
    float fz = p[2] * 0.0625f;
    int32_t ix = static_cast<int32_t>(fx < 0 && fx != static_cast<float>(static_cast<int32_t>(fx)) ? fx - 1.0f : fx);
    int32_t iz = static_cast<int32_t>(fz < 0 && fz != static_cast<float>(static_cast<int32_t>(fz)) ? fz - 1.0f : fz);
    return FindNetworkOccupant_5(ix, iz);
}
#endif

struct Entry_a8fed8 {
    uint32_t mnKey;
    uint32_t mnValue1;
    uint16_t mnValue2;
};

struct EntryVec_a8fed8 {
    Entry_a8fed8* mpBegin;
    Entry_a8fed8* mpEnd;
    Entry_a8fed8* mpCap;
    // STUB: 0x00626240
    void InsertOverflow(Entry_a8fed8* pos, const Entry_a8fed8& value, int32_t* tag, uint32_t count, bool atEnd);
};

struct TileEntries_a8fed8 {
    char pad00[0x10];
    EntryVec_a8fed8 mEntries;
};

#ifdef OB_DRAFTS
// CLOSE: 0x004b2970 score 64
void* cSC4TrafficNetworkMap::Slot20_a8fed8(void* occupant, uint32_t key)
{
    TileEntries_a8fed8* info = static_cast<TileEntries_a8fed8*>(GetTileInfoByNetwork(occupant));
    if (info) {
        for (Entry_a8fed8* e = info->mEntries.mpBegin; e != info->mEntries.mpEnd; ++e) {
            if (e->mnKey == key) {
                return &e->mnValue1;
            }
        }
    }
    Entry_a8fed8 fresh;
    fresh.mnKey = key;
    fresh.mnValue1 = 0;
    fresh.mnValue2 = 0;
    if (info->mEntries.mpEnd == info->mEntries.mpCap) {
        int32_t tag = 0;
        info->mEntries.InsertOverflow(info->mEntries.mpEnd, fresh, &tag, 1, true);
    } else {
        if (info->mEntries.mpEnd) {
            *info->mEntries.mpEnd = fresh;
        }
        ++info->mEntries.mpEnd;
    }
    return &(info->mEntries.mpEnd - 1)->mnValue1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b28c0 score 64
void* cSC4TrafficNetworkMap::Slot22_a8fed8(void* occupant, uint32_t key)
{
    TileEntries_a8fed8* info = static_cast<TileEntries_a8fed8*>(GetTileInfoByNetwork(occupant));
    if (info) {
        for (Entry_a8fed8* e = info->mEntries.mpBegin; e != info->mEntries.mpEnd; ++e) {
            if (e->mnKey == key) {
                return &e->mnValue2;
            }
        }
    }
    Entry_a8fed8 fresh;
    fresh.mnKey = key;
    fresh.mnValue1 = 0;
    fresh.mnValue2 = 0;
    if (info->mEntries.mpEnd == info->mEntries.mpCap) {
        int32_t tag = 0;
        info->mEntries.InsertOverflow(info->mEntries.mpEnd, fresh, &tag, 1, true);
    } else {
        if (info->mEntries.mpEnd) {
            *info->mEntries.mpEnd = fresh;
        }
        ++info->mEntries.mpEnd;
    }
    return &(info->mEntries.mpEnd - 1)->mnValue2;
}
#endif

// ---- Batch 4 ----

// A vector of 12-byte vectors; Erase removes [first, last).
struct VecVec_a8fed8 {
    Vec12_a8fed8* mpBegin;
    Vec12_a8fed8* mpEnd;
    Vec12_a8fed8* mpCap;

    Vec12_a8fed8* Erase(Vec12_a8fed8* first, Vec12_a8fed8* last);
    void Resize(uint32_t count, void* value);
    // STUB: 0x004b3d60
    void FillAt(Vec12_a8fed8* pos, uint32_t count, void* value);
};

// STUB: 0x004b2360
Vec12_a8fed8* Fn004b2360(Vec12_a8fed8* first, Vec12_a8fed8* last, Vec12_a8fed8* dest);

#ifdef OB_DRAFTS
// CLOSE: 0x004b37b0 score 20
Vec12_a8fed8* VecVec_a8fed8::Erase(Vec12_a8fed8* first, Vec12_a8fed8* last)
{
    Vec12_a8fed8* newEnd = Fn004b2360(last, mpEnd, first);
    Vec12_a8fed8* oldEnd = mpEnd;
    for (Vec12_a8fed8* p = newEnd; p != oldEnd; ++p) {
        if (p->mpBegin) {
            Fn0090cf63(p->mpBegin);
        }
    }
    mpEnd = newEnd;
    return first;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b46a0 score 36
void VecVec_a8fed8::Resize(uint32_t count, void* value)
{
    Vec12_a8fed8* begin = mpBegin;
    uint32_t size = static_cast<uint32_t>(mpEnd - begin);
    if (count < size) {
        Erase(begin + count, mpEnd);
        return;
    }
    FillAt(mpEnd, count - size, value);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b3c80 score 41
uint32_t cSC4TrafficNetworkMap::Fn004b3c80(void* occupant)
{
    HTable_a8fed8* table = reinterpret_cast<HTable_a8fed8*>(field28 + 0x18);
    uint32_t key = OB_ADDR(occupant);
    HNode_a8fed8* node = table->mpBegin[key % static_cast<uint32_t>(table->mpEnd - table->mpBegin)];
    if (node) {
        while (node->mnKey != key) {
            node = node->mpNext;
            if (!node) {
                return 0;
            }
        }
        static_cast<Unk_a8fed8*>(occupant)->Release();
        HNode_a8fed8* iterator[2];
        iterator[0] = node;
        iterator[1] = reinterpret_cast<HNode_a8fed8*>(table);
        table->Erase(iterator);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004afb10 score 49
void OB_STDCALL Fn004afb10(void* tileInfo)
{
    TileList_a8fed8* info = static_cast<TileList_a8fed8*>(tileInfo);
    if (info) {
        if (info->mpOccupant) {
            static_cast<Unk_a8fed8*>(info->mpOccupant)->Release();
        }
        LNodeA_a8fed8* head = info->mpList;
        for (LNodeA_a8fed8* l = head->mpNext; l != head; l = l->mpNext) {
            if (l->mpData) {
                static_cast<Unk_a8fed8*>(l->mpData)->Release();
            }
        }
        for (LNodeA_a8fed8* l = head->mpNext; l != head;) {
            LNodeA_a8fed8* following = l->mpNext;
            Fn0090cf63(l);
            l = following;
        }
        head->mpNext = head;
        head->mpPrev = head;
    }
}
#endif

// A 4-element array of vector-and-flag records, copied element by element.
struct VecInt_a8fed8 {
    int32_t* mpBegin;
    int32_t* mpEnd;
    int32_t* mpCap;
    // STUB: 0x004b03e0
    VecInt_a8fed8(const VecInt_a8fed8& other);
};

struct ListInt_a8fed8 {
    ListInt_a8fed8* mpNext;
    ListInt_a8fed8* mpPrev;
    int32_t mnValue;
};

struct ListHolder_a8fed8 {
    ListInt_a8fed8* mpHead;
    // STUB: 0x006f1570
    void InsertRange(ListInt_a8fed8* pos, ListInt_a8fed8* first, ListInt_a8fed8* last);
};

// An intersection-properties record (0x68 bytes) and its copy.
struct Props_a8fed8 {
    uint32_t mData[0x14];
    uint8_t mbFlag50;
    char pad51[3];
    VecInt_a8fed8 mVec;
    ListHolder_a8fed8 mList;
    uint8_t mbFlag64;

    Props_a8fed8* Assign(const Props_a8fed8& src);
};

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

#ifdef OB_DRAFTS
// CLOSE: 0x004b2450 score 56
Props_a8fed8* Props_a8fed8::Assign(const Props_a8fed8& src)
{
    for (int32_t i = 0; i < 0x14; ++i) {
        mData[i] = src.mData[i];
    }
    mbFlag50 = src.mbFlag50;
    new (&mVec) VecInt_a8fed8(src.mVec);
    mList.mpHead = 0;
    ListInt_a8fed8* head = static_cast<ListInt_a8fed8*>(Fn0090cf54(0xc));
    head->mpNext = head;
    head->mpPrev = head;
    mList.mpHead = head;
    ListInt_a8fed8* other = src.mList.mpHead;
    mList.InsertRange(head, other->mpNext, other);
    mbFlag64 = src.mbFlag64;
    return this;
}
#endif

// FUNCTION: 0x004b32e0
void HTable_a8fed8::ClearTrain()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        HNode_a8fed8* node = mpBegin[i];
        while (node) {
            HNode_a8fed8* next = node->mpNext;
            void** vec = reinterpret_cast<void**>(node) + 0x12;
            for (int32_t j = 4; j != 0; --j) {
                vec -= 4;
                if (*vec) {
                    Fn0090cf63(*vec);
                }
            }
            Fn0090cf63(node);
            node = next;
        }
        mpBegin[i] = 0;
    }
    mnCount = 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004b3ce0 score 71
void HTable_a8fed8::ReleaseAndClear()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        for (HNode_a8fed8* node = mpBegin[i]; node; node = node->mpNext) {
            if (node->mnKey) {
                reinterpret_cast<Unk_a8fed8*>(static_cast<uintptr_t>(node->mnKey))->Release();
            }
        }
    }
    ClearTrain();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004ae460 score 61
int32_t* Fn004ae460(int32_t* first, int32_t* last, int32_t* value)
{
    for (; first != last; first += 4) {
        if (*first == *value) {
            return first;
        }
    }
    return last;
}
#endif

// The city object: its slot 0x8c is called before the intersections are walked.
struct City_b43cec {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual void Pad7c();
    virtual void Pad80();
    virtual void Pad84();
    virtual void Pad88();
    virtual void S_8c();
};

// GLOBAL: 0x00b43cec
extern City_b43cec* gpCity_b43cec;

#ifdef OB_DRAFTS
// CLOSE: 0x004b2830 score 65
void cSC4TrafficNetworkMap::Fn004b2830()
{
    gpCity_b43cec->S_8c();
    HTable_a8fed8* table = reinterpret_cast<HTable_a8fed8*>(field28);
    for (uint32_t i = 0; i < static_cast<uint32_t>(table->mpEnd - table->mpBegin); ++i) {
        for (HNode_a8fed8* node = table->mpBegin[i]; node; node = node->mpNext) {
            Fn004b2640(reinterpret_cast<void*>(static_cast<uintptr_t>(node->mnKey)), node->mValue);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b2de0 score 60
void HTable_a8fed8::EraseTyped(HNode_a8fed8** where)
{
    Erase(where);
}
#endif

// FUNCTION: 0x004b3a30
cSC4TrafficNetworkMap::~cSC4TrafficNetworkMap()
{
    HTable_a8fed8* strings = reinterpret_cast<HTable_a8fed8*>(field60 + 0xa10);
    strings->ClearStr();
    if (strings->mpBegin) {
        Fn0090cf63(strings->mpBegin);
    }
    HTable_a8fed8* train = reinterpret_cast<HTable_a8fed8*>(field28 + 0x18);
    train->ClearTrain();
    if (train->mpBegin) {
        Fn0090cf63(train->mpBegin);
    }
    HTable_a8fed8* intersections = reinterpret_cast<HTable_a8fed8*>(field28);
    intersections->Clear();
    if (intersections->mpBegin) {
        Fn0090cf63(intersections->mpBegin);
    }
}

// ---- Batch 5 ----



// A vector of 16-byte records.
struct Vec16_a8fed8 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
};

#ifdef OB_DRAFTS
// CLOSE: 0x004b0110 score 78
Vec16_a8fed8* Fn004b0110(Vec16_a8fed8* dest, int32_t count, const Vec16_a8fed8* src)
{
    for (; count != 0; --count) {
        if (dest) {
            int32_t n = static_cast<int32_t>(src->mpEnd - src->mpBegin) >> 2;
            dest->mpBegin = 0;
            dest->mpEnd = 0;
            dest->mpCap = 0;
            uint32_t* out = 0;
            if (n != 0) {
                out = static_cast<uint32_t*>(Fn0090cf54(n << 4));
            }
            dest->mpBegin = out;
            dest->mpEnd = out;
            dest->mpCap = out + n * 4;
            for (const uint32_t* p = src->mpBegin; p != src->mpEnd; p += 4) {
                if (out) {
                    out[0] = p[0];
                    out[1] = p[1];
                    out[2] = p[2];
                    out[3] = p[3];
                }
                out += 4;
            }
            dest->mpEnd = out;
        }
        ++dest;
    }
    return dest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b0440 score 71
Vec16_a8fed8* Fn004b0440(const Vec16_a8fed8* first, const Vec16_a8fed8* last, Vec16_a8fed8* dest)
{
    for (; first != last; ++first) {
        if (dest) {
            int32_t n = static_cast<int32_t>(first->mpEnd - first->mpBegin) >> 2;
            dest->mpBegin = 0;
            dest->mpEnd = 0;
            dest->mpCap = 0;
            uint32_t* out = 0;
            if (n != 0) {
                out = static_cast<uint32_t*>(Fn0090cf54(n << 4));
            }
            dest->mpBegin = out;
            dest->mpEnd = out;
            dest->mpCap = out + n * 4;
            for (const uint32_t* p = first->mpBegin; p != first->mpEnd; p += 4) {
                if (out) {
                    out[0] = p[0];
                    out[1] = p[1];
                    out[2] = p[2];
                    out[3] = p[3];
                }
                out += 4;
            }
            dest->mpEnd = out;
        }
        ++dest;
    }
    return dest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b3200 score 71
uint32_t HTable_a8fed8::EraseKey(const uint32_t* key)
{
    uint32_t bucket = *key % static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t erased = 0;
    HNode_a8fed8* first = mpBegin[bucket];
    if (first) {
        HNode_a8fed8* prev = first;
        HNode_a8fed8* cur = first->mpNext;
        while (cur) {
            if (cur->mnKey == *key) {
                prev->mpNext = cur->mpNext;
                void** vec = reinterpret_cast<void**>(cur) + 0x12;
                for (int32_t i = 4; i != 0; --i) {
                    vec -= 4;
                    if (*vec) {
                        Fn0090cf63(*vec);
                    }
                }
                Fn0090cf63(cur);
                cur = prev->mpNext;
                ++erased;
                --mnCount;
            } else {
                prev = cur;
                cur = cur->mpNext;
            }
        }
        if (first->mnKey == *key) {
            mpBegin[bucket] = first->mpNext;
            Fn004b2f30(first);
            ++erased;
            --mnCount;
        }
    }
    return erased;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b3580 score 78
void HTable_a8fed8::ReleaseVectorsAndClear()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        for (HNode_a8fed8* node = mpBegin[i]; node; node = node->mpNext) {
            Unk_a8fed8*** vec = reinterpret_cast<Unk_a8fed8***>(node) + 2;
            for (Unk_a8fed8** p = vec[0]; p != vec[1]; ++p) {
                (*p)->Release();
            }
        }
    }
    ClearStr();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b36e0 score 91
void HTable_a8fed8::ReleaseIntersectionsAndClear()
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(mpEnd - mpBegin); ++i) {
        for (HNode_a8fed8* node = mpBegin[i]; node; node = node->mpNext) {
            if (node->mnKey) {
                reinterpret_cast<Unk_a8fed8*>(static_cast<uintptr_t>(node->mnKey))->Release();
            }
            Unk_a8fed8*** vec = reinterpret_cast<Unk_a8fed8***>(node) + 0x17;
            for (Unk_a8fed8** p = vec[0]; p != vec[1]; ++p) {
                if (*p) {
                    (*p)->Release();
                }
            }
            vec[1] = vec[0];
        }
    }
    Clear();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b3620 score 98
void HTable_a8fed8::ReleaseOne(void* occupant, Tree_a8fed8* unused)
{
    uint32_t key = OB_ADDR(occupant);
    HNode_a8fed8* node = mpBegin[key % static_cast<uint32_t>(mpEnd - mpBegin)];
    while (node && node->mnKey != key) {
        node = node->mpNext;
    }
    if (node) {
        static_cast<Unk_a8fed8*>(occupant)->Release();
        LNode_a8fed8* head = *reinterpret_cast<LNode_a8fed8**>(reinterpret_cast<char*>(node) + 0x68);
        for (LNode_a8fed8* l = head->mpNext; l != head; l = l->mpNext) {
            (*reinterpret_cast<Unk_a8fed8**>(reinterpret_cast<char*>(l) + 8))->Release();
        }
        for (LNode_a8fed8* l = head->mpNext; l != head;) {
            LNode_a8fed8* following = l->mpNext;
            Fn0090cf63(l);
            l = following;
        }
        head->mpNext = head;
        head->mpPrev = head;
        HNode_a8fed8* iterator[2];
        iterator[0] = node;
        iterator[1] = reinterpret_cast<HNode_a8fed8*>(this);
        EraseTyped(iterator);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b3810 score 57
void HTable_a8fed8::Insert(HNode_a8fed8** result, const uint32_t* keyAndValue)
{
    uint32_t bucket = *keyAndValue % static_cast<uint32_t>(mpEnd - mpBegin);
    HNode_a8fed8* first = mpBegin[bucket];
    for (HNode_a8fed8* cur = first; cur; cur = cur->mpNext) {
        if (cur->mnKey == *keyAndValue) {
            result[0] = cur;
            result[1] = reinterpret_cast<HNode_a8fed8*>(this);
            *reinterpret_cast<uint8_t*>(result + 2) = 0;
            return;
        }
    }
    HNode_a8fed8* node = static_cast<HNode_a8fed8*>(Fn0090cf54(0x70));
    node->mpNext = 0;
    node->mnKey = *keyAndValue;
    reinterpret_cast<Props_a8fed8*>(node->mValue)->Assign(*reinterpret_cast<const Props_a8fed8*>(keyAndValue + 1));
    node->mpNext = first;
    mpBegin[bucket] = node;
    ++mnCount;
    result[0] = node;
    result[1] = reinterpret_cast<HNode_a8fed8*>(this);
    *reinterpret_cast<uint8_t*>(result + 2) = 1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004afb80 score 36
void cSC4TrafficNetworkMap::Fn004afb80(void* occupant, void* props, float dt)
{
    char* record = static_cast<char*>(props) + 4;
    for (int32_t i = 4; i != 0; --i) {
        if (*reinterpret_cast<int32_t*>(record - 4) == 2) {
            float remaining = *reinterpret_cast<float*>(record + 0xc) - dt;
            *reinterpret_cast<float*>(record + 0xc) = remaining;
            if (remaining <= 0.0f) {
                record[0] = (record[0] == 0);
                record[1] = 0;
                OB_FIELD(uint8_t, props, 0x64) = 1;
                if (record[0] == 0) {
                    *reinterpret_cast<uint32_t*>(record + 0xc) = *reinterpret_cast<uint32_t*>(record + 8);
                } else {
                    *reinterpret_cast<uint32_t*>(record + 0xc) = *reinterpret_cast<uint32_t*>(record + 4);
                }
            } else if (remaining < 1.0f && record[1] == 0) {
                record[1] = 1;
                OB_FIELD(uint8_t, props, 0x64) = 1;
            }
        }
        record += 0x14;
    }
    if (OB_FIELD(uint8_t, props, 0x64)) {
        Fn004ae850(occupant, props, 0);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004afc20 score 63
void cSC4TrafficNetworkMap::Fn004afc20(void* occupant, void* props, void* unused)
{
    void* slots[4] = { 0, 0, 0, 0 };
    char* base = static_cast<char*>(props) + 8;
    if (static_cast<OccA_a8fed8*>(occupant)->S_c4()) {
        OB_FIELD(uint8_t, props, 0x58) = 0;
        OB_FIELD(uint8_t, props, 0x6c) = 1;
        char* rec = base;
        for (uint32_t i = 0; i < 4; ++i) {
            slots[i] = 0;
            void** found = static_cast<void**>(FindNetworkTile(OB_ADDR(occupant), i, 0, 0));
            if (found) {
                slots[i] = *found;
            }
            Fn004ae9e0(occupant, slots[i], base, rec, i);
            rec += 0x14;
        }
        Fn004ae850(occupant, base, 1);
        mbActive = 1;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b1090 score 71
bool cSC4TrafficNetworkMap::HandleTuningParametersChanged()
{
    HTable_a8fed8* table = reinterpret_cast<HTable_a8fed8*>(field28);
    for (uint32_t i = 0; i < static_cast<uint32_t>(table->mpEnd - table->mpBegin); ++i) {
        for (HNode_a8fed8* node = table->mpBegin[i]; node; node = node->mpNext) {
            void* iterator[2];
            iterator[0] = node;
            iterator[1] = table;
            Fn004afc20(reinterpret_cast<void*>(static_cast<uintptr_t>(node->mnKey)), iterator[0], iterator[1]);
        }
    }
    return true;
}
#endif

// ---- Batch 6 ----

struct PredB_b43cec;
struct CityB_b43cec {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void S_34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual void Pad7c();
    virtual void Pad80();
    virtual void Pad84();
    virtual void Pad88();
    virtual void Pad8c();
    virtual void Pad90();
    virtual void Pad94();
    virtual void Pad98();
    virtual void Pad9c();
    virtual void Pada0();
    virtual void Pada4();
    virtual void Pada8();
    virtual PredB_b43cec* S_ac();
    virtual PredB_b43cec* S_b0();
};

struct PredB_b43cec {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual bool S_18();
};

// GLOBAL: 0x00b43cec
extern CityB_b43cec* gpCityB_b43cec;

// A vector of unsigned longs.
struct VecUL_a8fed8 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x00462f00
    VecUL_a8fed8(const VecUL_a8fed8& other);
    // STUB: 0x00462c10
    void Assign(const JVec_a8fed8& other);
};

// A record of four vectors, each with a current index (0x10 bytes each).
struct Quad4_a8fed8 {
    VecUL_a8fed8 mVec[4];
    Quad4_a8fed8* Assign(const Quad4_a8fed8& src);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004b24c0 score 36
Quad4_a8fed8* Quad4_a8fed8::Assign(const Quad4_a8fed8& src)
{
    uint16_t* cur = reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(this) + 0xc);
    const char* from = reinterpret_cast<const char*>(&src);
    for (int32_t i = 0; i < 4; ++i) {
        new (&mVec[i]) VecUL_a8fed8(*reinterpret_cast<const VecUL_a8fed8*>(from));
        *cur = *reinterpret_cast<const uint16_t*>(from + 0xc);
        from += 0x10;
        cur += 8;
    }
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b38b0 score 57
void HTable_a8fed8::InsertTrain(HNode_a8fed8** result, const uint32_t* keyAndValue)
{
    uint32_t bucket = *keyAndValue % static_cast<uint32_t>(mpEnd - mpBegin);
    HNode_a8fed8* first = mpBegin[bucket];
    for (HNode_a8fed8* cur = first; cur; cur = cur->mpNext) {
        if (cur->mnKey == *keyAndValue) {
            result[0] = cur;
            result[1] = reinterpret_cast<HNode_a8fed8*>(this);
            *reinterpret_cast<uint8_t*>(result + 2) = 0;
            return;
        }
    }
    HNode_a8fed8* node = static_cast<HNode_a8fed8*>(Fn0090cf54(0x48));
    node->mpNext = 0;
    node->mnKey = *keyAndValue;
    reinterpret_cast<Quad4_a8fed8*>(node->mValue)->Assign(*reinterpret_cast<const Quad4_a8fed8*>(keyAndValue + 1));
    node->mpNext = first;
    mpBegin[bucket] = node;
    ++mnCount;
    result[0] = node;
    result[1] = reinterpret_cast<HNode_a8fed8*>(this);
    *reinterpret_cast<uint8_t*>(result + 2) = 1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b1b60 score 56
uint32_t cSC4TrafficNetworkMap::GetTrainJunctionKeys(void* occupant, uint32_t index, void* outKeys, void* outCurrent)
{
    VecUL_a8fed8* keys = static_cast<VecUL_a8fed8*>(outKeys);
    uint16_t* current = static_cast<uint16_t*>(outCurrent);
    keys->mpEnd = keys->mpBegin;
    *current = 0;
    HTable_a8fed8* table = reinterpret_cast<HTable_a8fed8*>(field28 + 0x18);
    uint32_t hash = OB_ADDR(occupant);
    HNode_a8fed8* node = table->mpBegin[hash % static_cast<uint32_t>(table->mpEnd - table->mpBegin)];
    while (node && node->mnKey != hash) {
        node = node->mpNext;
    }
    if (node) {
        JVec_a8fed8* vec = reinterpret_cast<JVec_a8fed8*>(node->mValue) + static_cast<uint8_t>(index);
        if (vec->mpBegin != vec->mpEnd) {
            keys->Assign(*vec);
            *current = vec->mnCurrent;
            return static_cast<uint32_t>(keys->mpEnd - keys->mpBegin);
        }
    }
    return 0;
}
#endif

struct ListA_a8fed8 {
    LNodeA_a8fed8* mpHead;
    // STUB: 0x004b0be0
    void PushFront(void* const* value);
};

// STUB: 0x004dc710
LNodeA_a8fed8* Fn004dc710(LNodeA_a8fed8* first, LNodeA_a8fed8* last, void* const* value);

#ifdef OB_DRAFTS
// CLOSE: 0x004b1c00 score 86
bool cSC4TrafficNetworkMap::EnterNetwork(void* automaton, void* occupant)
{
    if (automaton && occupant) {
        TileList_a8fed8* info = static_cast<TileList_a8fed8*>(GetTileInfoByNetwork(occupant));
        if (info) {
            void* item = automaton;
            LNodeA_a8fed8* found = Fn004dc710(info->mpList->mpNext, info->mpList, &item);
            if (found == info->mpList) {
                reinterpret_cast<ListA_a8fed8*>(&info->mpList)->PushFront(&item);
                static_cast<Unk_a8fed8*>(automaton)->AddRef();
                uint32_t type = static_cast<AutoA_a8fed8*>(automaton)->S_220();
                uint16_t* count = static_cast<uint16_t*>(Slot23_a8fed8(occupant, OB_FIELD(uint32_t, automaton, 500), type));
                if (*count != 0xffff) {
                    ++*count;
                }
                count = static_cast<uint16_t*>(Slot22_a8fed8(occupant, (type & 0xf000000) >> 24));
                if (*count != 0xffff) {
                    ++*count;
                }
                return true;
            }
        }
    }
    return false;
}
#endif

// FUNCTION: 0x004b01c0
void cSC4TrafficNetworkMap::DoAnimationTick(uint32_t /*unused*/, float dt)
{
    if (gpCityB_b43cec->S_ac()->S_18() || gpCityB_b43cec->S_b0()->S_18()) {
        TickIntersections(dt);
    }
    if (OB_FIELD(uint8_t, this, 0x5c)) {
        OB_FIELD(uint8_t, this, 0x5c) = 0;
        for (int32_t x = OB_FIELD(int32_t, this, 0x60); x <= OB_FIELD(int32_t, this, 0x68); ++x) {
            for (int32_t y = OB_FIELD(int32_t, this, 0x64); y <= OB_FIELD(int32_t, this, 0x6c); ++y) {
                for (TileInfo_a8fed8* info = static_cast<TileInfo_a8fed8*>(GetTileInfoAtCell(x, y)); info; info = info->mpNext) {
                    if (info->mpOccupant) {
                        Fn004afce0(info->mpOccupant, info);
                        Fn004afe50(info->mpOccupant, info);
                    }
                }
            }
        }
    }
    float total = OB_FIELD(float, this, 0xa8c) + dt;
    OB_FIELD(float, this, 0xa8c) = total;
    if (total >= 1000.0f) {
        OB_FIELD(float, this, 0xa8c) = 0.0f;
        Fn004ae6d0();
    }
}

// ---- Batch 7 ----

#ifdef OB_DRAFTS
// CLOSE: 0x004b02a0 score 109
bool cSC4TrafficNetworkMap::ExitNetwork(void* automaton, void* occupant, uint32_t type)
{
    bool result = false;
    TileList_a8fed8* info = 0;
    if (automaton && occupant) {
        info = static_cast<TileList_a8fed8*>(GetTileInfoByNetwork(occupant));
    }
    if (info) {
        LNodeA_a8fed8* l = info->mpList->mpNext;
        while (l != info->mpList) {
            if (automaton == l->mpData) {
                LNodeA_a8fed8* following = l->mpNext;
                l->mpPrev->mpNext = l->mpNext;
                l->mpNext->mpPrev = l->mpPrev;
                Fn0090cf63(l);
                l = following;
                uint16_t* count = static_cast<uint16_t*>(Slot23_a8fed8(occupant, OB_FIELD(uint32_t, automaton, 500), type));
                if (*count != 0) {
                    --*count;
                }
                count = static_cast<uint16_t*>(Slot22_a8fed8(occupant, (type & 0xf000000) >> 24));
                if (*count != 0) {
                    --*count;
                }
                static_cast<Unk_a8fed8*>(automaton)->Release();
                result = true;
            } else {
                l = l->mpNext;
            }
        }
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004b0840 score 123
void cSC4TrafficNetworkMap::UnmarkTrainInCell(void* automaton, int32_t x, int32_t y)
{
    for (TileInfo_a8fed8* tile = static_cast<TileInfo_a8fed8*>(SafeGetTileInfoAtCell(x, y)); tile; tile = tile->mpNext) {
        HTable_a8fed8* table = reinterpret_cast<HTable_a8fed8*>(field28);
        uint32_t key = OB_ADDR(tile->mpOccupant);
        HNode_a8fed8* node = table->mpBegin[key % static_cast<uint32_t>(table->mpEnd - table->mpBegin)];
        while (node && node->mnKey != key) {
            node = node->mpNext;
        }
        if (node) {
            char* raw = reinterpret_cast<char*>(node);
            LNodeA_a8fed8* head = *reinterpret_cast<LNodeA_a8fed8**>(raw + 0x68);
            LNodeA_a8fed8* l = head->mpNext;
            while (l != head && l->mpData != automaton) {
                l = l->mpNext;
            }
            if (l != head) {
                l->mpPrev->mpNext = l->mpNext;
                l->mpNext->mpPrev = l->mpPrev;
                Fn0090cf63(l);
                static_cast<Unk_a8fed8*>(automaton)->Release();
            }
            if (head->mpNext == head) {
                char* props = raw + 8;
                do {
                    if (props[0x10] == 0) {
                        raw[0x70] = 1;
                    }
                    props[0x10] = 1;
                    props += 0x14;
                } while (props != raw + 0x58);
                if (raw[0x70]) {
                    Fn004ae850(*reinterpret_cast<void**>(raw + 4), raw + 8, 0);
                }
            }
        }
    }
}
#endif
