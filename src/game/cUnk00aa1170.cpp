#include <cstddef>

#include "classes/cUnk00aa1170.h"
#include "game/Globals.h"

// STUB: 0x009133da
void* Fn009133da(uint32_t size);

// The 0x2c-byte object the allocator hands out (vtable 0x00acec00); only the calls used here are named.
struct cMade_aa1170 {
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
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Fn16(uint32_t);
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
    virtual void Fn33(void*);
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    cMade_aa1170();
    static void* operator new(size_t size) { return Fn009133da(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// FUNCTION: 0x004bdf00
uint32_t cUnk00aa1170::Slot01_aa1170()
{
    return ++mnRefCount;
}

// FUNCTION: 0x006ce090
void cUnk00aa1170::Slot10_aa1170(uint32_t a, uint32_t b)
{
    mnValueA = a;
    mnValueB = b;
}

// FUNCTION: 0x005be840
uint32_t cUnk00aa1170::Slot02_aa1170()
{
    int32_t n = mnRefCount - 1;
    mnRefCount = n;
    if (n == 0) {
        delete this;
        n = 0;
    }
    return n;
}

// FUNCTION: 0x005be860
void cUnk00aa1170::Slot07_aa1170(void* a)
{
    Slot03_a9ebe4(&mnBlockB[0], a);
}

// FUNCTION: 0x005be880
void cUnk00aa1170::Slot08_aa1170(void* a)
{
    Slot03_a9ebe4(a, &mnBlockA[0]);
}

static inline bool BitIsSet(uint32_t word, uint32_t pos)
{
    return ((word >> pos) & 1) != 0;
}
struct cOwner_aa1170 {
    // STUB: 0x0058e340
    void Fn0058e340(void* node);
    // STUB: 0x005908a0
    void Fn005908a0(void* node);
};
struct cChildObj_aa1170 {
    virtual void Fn0(uint32_t) = 0;
    virtual void Fn1(uint32_t) = 0;
    virtual bool Fn2() = 0;
    virtual void Fn3() = 0;
    virtual void Fn4(uint32_t) = 0;
    virtual bool Fn5(uint32_t, uint32_t, uint32_t) = 0;
    virtual bool Fn6(uint32_t, void*, uint32_t) = 0;
};
struct cChild_aa1170 {
    uint8_t mPad[0x38];
    cChildObj_aa1170* mpObj;
    uint8_t mPad2[0x8];
};
struct Rec_aa1170 {
    uint8_t mnCount;
    uint8_t mnByte;
    uint16_t mnPad;
    uint32_t mnV[13];
};

// FUNCTION: 0x005bea60
void cUnk00aa1170::Slot14_aa1170(uint32_t a)
{
    Rec_aa1170* r = reinterpret_cast<Rec_aa1170*>(a);
    r->mnCount++;
    r->mnV[0] = mnBlockA[1];
    r->mnV[1] = mnBlockA[2];
    r->mnV[2] = mnBlockA[3];
    r->mnV[3] = mnBlockA[4];
    r->mnV[4] = mnBlockA[5];
    r->mnV[5] = mnBlockA[6];
    r->mnV[6] = mnBlockA[7];
    r->mnV[7] = mnBlockA[8];
    r->mnV[8] = mnBlockA[9];
    r->mnV[9] = mnBlockA[10];
    r->mnV[10] = mnBlockA[11];
    r->mnV[11] = mnBlockA[12];
    r->mnV[12] = mnBlockA[13];
    r->mnByte = reinterpret_cast<uint8_t*>(mnBlockA)[1];
}

// FUNCTION: 0x005beac0
void cUnk00aa1170::Slot15_aa1170(uint32_t a)
{
    Rec_aa1170* r = reinterpret_cast<Rec_aa1170*>(a);
    r->mnCount++;
    r->mnV[0] = mnBlockB[1];
    r->mnV[1] = mnBlockB[2];
    r->mnV[2] = mnBlockB[3];
    r->mnV[3] = mnBlockB[4];
    r->mnV[4] = mnBlockB[5];
    r->mnV[5] = mnBlockB[6];
    r->mnV[6] = mnBlockB[7];
    r->mnV[7] = mnBlockB[8];
    r->mnV[8] = mnBlockB[9];
    r->mnV[9] = mnBlockB[10];
    r->mnV[10] = mnBlockB[11];
    r->mnV[11] = mnBlockB[12];
    r->mnV[12] = mnBlockB[13];
    r->mnByte = reinterpret_cast<uint8_t*>(mnBlockB)[1];
}

// FUNCTION: 0x005bea10
void cUnk00aa1170::Slot04_a9ebe4(uint32_t a)
{
    cChild_aa1170* it = reinterpret_cast<cChild_aa1170*>(mpChildBegin);
    while (it != reinterpret_cast<cChild_aa1170*>(mpChildEnd)) {
        if (it->mpObj->Fn2()) {
            it->mpObj->Fn4(a);
        }
        ++it;
    }
}

// FUNCTION: 0x005beba0
void cUnk00aa1170::Slot04_aa1170(uint32_t a)
{
    if (mpOwner) {
        uint32_t m = a;
        if (m == 0) {
            if (BitIsSet(mnFlags, 2)) {
                m = 1;
            }
        }
        cChild_aa1170* it = reinterpret_cast<cChild_aa1170*>(mpChildBegin);
        while (it != reinterpret_cast<cChild_aa1170*>(mpChildEnd)) {
            it->mpObj->Fn1(m);
            ++it;
        }
        if (m != 2) {
            if (mnIndex >= 0) {
                reinterpret_cast<cOwner_aa1170*>(mpOwner)->Fn0058e340(this);
            }
        }
        if (m != 0) {
            mbActive = false;
            field25 = false;
        } else {
            field25 = true;
        }
    }
}

// FUNCTION: 0x005be920
void cUnk00aa1170::Slot03_aa1170(uint32_t a)
{
    if (mpOwner) {
        cChild_aa1170* it = reinterpret_cast<cChild_aa1170*>(mpChildBegin);
        while (it != reinterpret_cast<cChild_aa1170*>(mpChildEnd)) {
            it->mpObj->Fn0(a);
            ++it;
        }
        if (a != 2) {
            if (mnIndex >= 0) {
                reinterpret_cast<cOwner_aa1170*>(mpOwner)->Fn005908a0(this);
            }
        }
        if (mnMadeA) {
            cB43ccc* g = gpB43ccc;
            if (g) {
                cMade_aa1170* made = new cMade_aa1170;
                if (made) {
                    made->AddRef();
                }
                made->Fn05(mnMadeA);
                made->Fn11(mnMadeB);
                made->Fn16(mnMadeC);
                made->Fn33(this);
                g->Fn04(made, 0);
                made->Release();
            }
        }
        mbActive = true;
        field25 = false;
    }
}

// STUB: 0x009dd0a0
void StlThrow(const char* msg);

// FUNCTION: 0x005be7f0
bool cUnk00aa1170::Slot00_aa1170(uint32_t iid, uint32_t ppv)
{
    void** out = reinterpret_cast<void**>(ppv);
    switch (iid) {
    case 1:
        *out = this;
        Slot01_aa1170();
        return true;
    case 0x2c279933:
        *out = static_cast<cUnk00a9ebe4*>(this);
        Slot01_aa1170();
        return true;
    }
    return false;
}

// FUNCTION: 0x005bfc20
bool cUnk00aa1170::Slot13_aa1170(uint32_t a, void* b, uint32_t c)
{
    if (BitIsSet(mnFlags, 4)) {
        return false;
    }
    bool r = false;
    cChild_aa1170* it = reinterpret_cast<cChild_aa1170*>(mpChildBegin);
    while (it != reinterpret_cast<cChild_aa1170*>(mpChildEnd)) {
        if (it->mpObj->Fn6(a, b, c) || r) {
            r = true;
        }
        ++it;
    }
    return r;
}

// FUNCTION: 0x005bfc90
uint32_t cUnk00aa1170::Slot17_aa1170(uint32_t pos)
{
    if (pos >= 9) {
        StlThrow("bitset");
    }
    return (mnFlags & (1u << (pos & 31))) != 0;
}

// FUNCTION: 0x005bea50
bool cUnk00aa1170::Slot11_aa1170(uint32_t a, uint32_t b, uint32_t c)
{
    return Slot12_aa1170(a, b, c * 3);
}

struct Entry_aa1170 {
    uint16_t mnStart;
    uint16_t mnCount;
};
struct EntryVec_aa1170 {
    Entry_aa1170* volatile mpBegin;
    Entry_aa1170* mpEnd;
    // STUB: 0x007169c0
    void Fn007169c0(uint32_t n, Entry_aa1170* fill);
};
struct WordVec_aa1170 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    // STUB: 0x00464130
    void Fn00464130(uint32_t n, uint32_t* fill);
};
struct Made_aa1170 {
    uint32_t mnV[2];
};
// STUB: 0x005bff50
void Fn005bff50(Made_aa1170* out, uint32_t b, uint32_t c, uint32_t* p);


// CLOSE: 0x005c05e0 score 71 (this/a swap ebp/edi)
bool cUnk00aa1170::Slot12_aa1170(uint32_t a, uint32_t b, uint32_t c)
{
    if (BitIsSet(this->mnFlags, 4)) {
        return false;
    }
    int32_t nZero = 0;
    if (static_cast<int32_t>(c) <= nZero) {
        return false;
    }
    if (a > 0x13) {
        return false;
    }
    EntryVec_aa1170* v = reinterpret_cast<EntryVec_aa1170*>(&mpIndexBegin);
    if (v->mpBegin == v->mpEnd) {
        Entry_aa1170 zero;
        zero.mnStart = static_cast<uint16_t>(nZero);
        zero.mnCount = static_cast<uint16_t>(nZero);
        v->Fn007169c0(0x13, &zero);
    }
    uint16_t cnt = v->mpBegin[a].mnCount;
    if (cnt == 0) {
        v->mpBegin[a].mnStart = static_cast<uint16_t>(mpWordEnd - mpWordBegin);
        v->mpBegin[a].mnCount = static_cast<uint16_t>(c);
        uint32_t fill = 0;
        reinterpret_cast<WordVec_aa1170*>(&mpWordBegin)->Fn00464130(v->mpBegin[a].mnStart + c, &fill);
    } else if (c != cnt) {
        return false;
    }
    Made_aa1170 made;
    Fn005bff50(&made, b, c, mpWordBegin + v->mpBegin[a].mnStart);
    bool r = false;
    cChild_aa1170* it = reinterpret_cast<cChild_aa1170*>(this->mpChildBegin);
    while (it != reinterpret_cast<cChild_aa1170*>(this->mpChildEnd)) {
        if (it->mpObj->Fn5(a, b, c) || r) {
            r = true;
        }
        ++it;
    }
    return r;
}

struct RecF_aa1170 {
    uint8_t mnCount;
    uint8_t mnByte;
    uint16_t mnPad;
    float mfV[13];
};
// The object the argument hands out through its slot 19.
struct cLookup_aa1170 {
    virtual void Pad0();
    virtual void AddRef();
    virtual void Release();
    virtual uint32_t Fn3();
    virtual void Fn4(uint32_t** out, uint32_t* key);
};
struct cLookupSource_aa1170 {
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
    virtual cLookup_aa1170* Fn19();
};
struct cTarget_aa1170 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Fn9(RecF_aa1170* out);
};
// The small holder the key lookup builds: a tag and a buffer released again when the tag says it owns one.
struct cHolder_aa1170 {
    int32_t mnTag;
    void* mpBuf;
    uint8_t mData[0x88 - 8];
    // STUB: 0x005be8a0
    uint32_t** Fn005be8a0(uint32_t key);
};
// STUB: 0x005e5620
void FnDelete(void* p);

// CLOSE: 0x005bfac0 score 53 (the original keeps the target in memory and reloads it; the null-lookup return sits out of line)
bool cUnk00aa1170::Slot09_aa1170(uint32_t a)
{
    cTarget_aa1170* volatile target = 0;
    cLookup_aa1170* look = reinterpret_cast<cLookupSource_aa1170*>(a)->Fn19();
    if (look == 0) {
        return false;
    }
    look->AddRef();
    uint32_t key = look->Fn3();
    if (key != 0) {
        cHolder_aa1170 holder;
        holder.mnTag = -1;
        holder.mpBuf = 0;
        uint32_t** res = holder.Fn005be8a0(key);
        look->Fn4(res, &key);
        target = reinterpret_cast<cTarget_aa1170*>(**res);
        if (holder.mnTag != -1 && holder.mpBuf) {
            FnDelete(holder.mpBuf);
        }
    }
    if (target == 0) {
        look->Release();
        return false;
    }
    mnFlags = mnFlags & 0xfffffffe;
    RecF_aa1170 rec;
    rec.mfV[0] = 1.0f;
    rec.mfV[3] = 0.0f;
    rec.mfV[6] = 0.0f;
    rec.mfV[1] = 0.0f;
    rec.mfV[4] = 1.0f;
    rec.mfV[7] = 0.0f;
    rec.mfV[2] = 0.0f;
    rec.mfV[5] = 0.0f;
    rec.mfV[8] = 1.0f;
    rec.mfV[12] = 1.0f;
    rec.mfV[9] = 0.0f;
    rec.mfV[10] = 0.0f;
    rec.mfV[11] = 0.0f;
    rec.mnByte = 0;
    rec.mnCount = 0;
    target->Fn9(&rec);
    Slot08_aa1170(&rec);
    Slot13_aa1170(7, &key, 1);
    look->Release();
    return true;
}
