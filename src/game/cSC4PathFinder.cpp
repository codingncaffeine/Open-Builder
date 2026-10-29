#include "classes/cSC4PathFinder.h"
#include "game/Globals.h"

// The class has no known size yet, so its data cannot be declared in the header: this view names what the methods
// below touch (offsets from the object's start; the vtable pointer sits in front).
struct Vec4_ab2150 {
    uint32_t mn[4];
    void Set(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
    {
        mn[0] = a;
        mn[1] = b;
        mn[2] = c;
        mn[3] = d;
    }
};

// A std::vector-like triple (begin, end, capacity); the resize-style method at 0x006d6920 is the original's.
struct Vec_ab2150 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x006d6920
    void Fn006d6920(uint32_t count, uint32_t* fill);
};

struct Data_ab2150 {
    const void* mpVtable;
    bool mbActive;                // 0x04
    uint32_t mnRefCount;          // 0x08
    void* mpMap;                  // 0x0c
    void* mpPath;                 // 0x10
    uint8_t mPad14[4];
    Vec4_ab2150 mVecA;             // 0x18
    Vec4_ab2150 mVecB;             // 0x28
    uint8_t mPad38[0x58 - 0x38];
    uint32_t mnValueA;            // 0x58
    uint32_t mnValueB;            // 0x5c
    float mfScale;                // 0x60
    uint16_t mnMaskA;             // 0x64
    uint16_t mnMaskB;             // 0x66
    uint8_t mPad68[0x70 - 0x68];
    uint32_t mnFlags;             // 0x70
    uint8_t mPad74[0x84 - 0x74];
    uint8_t mnFlags8;             // 0x84
    uint8_t mPad85[0xb8 - 0x85];
    uint32_t mnWidth;             // 0xb8
    uint32_t mnHeight;            // 0xbc
    uint8_t mPadC0[4];
    uint8_t mnByteC4;             // 0xc4
    uint8_t mPadC5[0xf4 - 0xc5];
    Vec_ab2150 mListA;             // 0xf4
    Vec_ab2150 mListB;             // 0x100
    uint32_t* mpDataA;            // 0x10c
    uint32_t* mpDataB;            // 0x110
    uint8_t mPad114[0x120 - 0x114];
    uint32_t mnField120;          // 0x120
    uint8_t mPad124[0x12c - 0x124];
    uint8_t mBuffer[0xc07];       // 0x12c
    uint8_t mPad1d33[0x3148 - 0x12c - 0xc07];
    uint8_t** mpBufferOwner;      // 0x3148
    uint8_t mPad314c[0x3154 - 0x314c];
    uint8_t* mpBufferBegin;       // 0x3154
    uint8_t* mpBufferEnd;         // 0x3158
    uint32_t mnField315c;         // 0x315c
};

static inline Data_ab2150* Of_ab2150(cSC4PathFinder* p)
{
    return reinterpret_cast<Data_ab2150*>(p);
}

// A cell of the map: two tables of nine and thirteen words and a flag byte.
struct Cell_ab2150 {
    uint16_t mnWordsA[9];
    uint16_t mnWordsB[13];
    uint8_t mnFlags;
    uint8_t mPad2d;
};

// The map object at +0xc: slot 15 is its scale.
struct cMap_ab2150 {
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
    virtual float Fn15();
    uint8_t mPad04[0x58 - 4];
    Cell_ab2150* mpCells;
};

// The path node at +0x10: next link, an edge byte, a type byte and the cell it sits in.
struct cNode_ab2150 {
    uint8_t mPad00[4];
    cNode_ab2150* mpNext;
    uint8_t mPad08[0x12 - 8];
    uint8_t mnEdge;
    bool mbByte13;
    int16_t mnX;
    int16_t mnY;
};

// FUNCTION: 0x006d5d20
bool cSC4PathFinder::QueryInterface(uint32_t id, void* out)
{
    if (id == 1 || id == 0xaa0db766) {
        *static_cast<cSC4PathFinder**>(out) = this;
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x006d5d50
bool cSC4PathFinder::Shutdown()
{
    Data_ab2150* d = Of_ab2150(this);
    if (d->mbActive) {
        d->mbActive = false;
        ReleasePathNodes();
        d->mpDataA = 0;
        d->mpDataB = 0;
        return true;
    }
    return false;
}

// FUNCTION: 0x006d6030
float cSC4PathFinder::GetTripLengthScaledForDisplay()
{
    Data_ab2150* d = Of_ab2150(this);
    return static_cast<cMap_ab2150*>(d->mpMap)->Fn15() * d->mfScale;
}

// FUNCTION: 0x006d6cf0
void cSC4PathFinder::Slot05_ab2150(uint32_t a)
{
    Of_ab2150(this)->mnFlags |= a;
}

// FUNCTION: 0x006d6d00
void cSC4PathFinder::Slot06_ab2150(uint32_t a)
{
    Of_ab2150(this)->mnFlags &= ~a;
}

// FUNCTION: 0x006d6d20
void cSC4PathFinder::ClearAllFlags()
{
    Of_ab2150(this)->mnFlags = 0;
}

// FUNCTION: 0x006d6d40
void cSC4PathFinder::Slot10_ab2150(uint32_t a)
{
    Of_ab2150(this)->mnFlags8 |= static_cast<uint8_t>(a);
}

// FUNCTION: 0x006d6d60
void cSC4PathFinder::Slot11_ab2150(uint32_t a)
{
    Of_ab2150(this)->mnFlags8 &= static_cast<uint8_t>(~a);
}

// FUNCTION: 0x006d6d80
void cSC4PathFinder::ClearAllDestinationFlags()
{
    Of_ab2150(this)->mnFlags8 = 0;
}

// FUNCTION: 0x006d6d90
void cSC4PathFinder::Slot13_ab2150(uint32_t a, uint32_t b)
{
    Data_ab2150* d = Of_ab2150(this);
    d->mnMaskA |= static_cast<uint16_t>(a);
    if (static_cast<uint8_t>(b)) {
        d->mnMaskB |= static_cast<uint16_t>(a);
    }
}

// FUNCTION: 0x006d6db0
void cSC4PathFinder::Slot14_ab2150(uint32_t a)
{
    Data_ab2150* d = Of_ab2150(this);
    d->mnMaskA &= static_cast<uint16_t>(~a);
    d->mnMaskB &= static_cast<uint16_t>(~a);
}

// FUNCTION: 0x006d6dd0
void cSC4PathFinder::ClearAllTravelTypeFlags()
{
    Data_ab2150* d = Of_ab2150(this);
    d->mnMaskB = 0;
    d->mnMaskA = 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006d6e10 score 9 (the original adds 0x18 to ecx once and stores through [ecx+n]; the compiler folds the offset into every store)
void cSC4PathFinder::Slot19_ab2150(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Of_ab2150(this)->mVecA.Set(a, b, c, d);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006d6e40 score 9 (same as 0x006d6e10, offset 0x28)
void cSC4PathFinder::Slot20_ab2150(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Of_ab2150(this)->mVecB.Set(a, b, c, d);
}
#endif

// FUNCTION: 0x006d6e80
void cSC4PathFinder::Reset()
{
    Of_ab2150(this)->mnByteC4 = 0;
}

// FUNCTION: 0x006d6ea0
void cSC4PathFinder::GetEndCell(void* a, void* b)
{
    Data_ab2150* d = Of_ab2150(this);
    *static_cast<uint32_t*>(a) = d->mnValueA;
    *static_cast<uint32_t*>(b) = d->mnValueB;
}

// FUNCTION: 0x006d6ec0
bool cSC4PathFinder::GetLastTravelType()
{
    cNode_ab2150* n = static_cast<cNode_ab2150*>(Of_ab2150(this)->mpPath);
    if (n) {
        return n->mbByte13;
    }
    return false;
}

// FUNCTION: 0x006d61b0
uint32_t cSC4PathFinder::Release()
{
    Data_ab2150* d = Of_ab2150(this);
    if (d->mnRefCount > 1) {
        return --d->mnRefCount;
    }
    if (d->mbActive) {
        Shutdown();
    }
    delete this;
    return 0;
}

// STUB: 0x00910003
void* Fn00910003(void* dst, int value, uint32_t size);

// FUNCTION: 0x006d6730
void cSC4PathFinder::ReleasePathNodes()
{
    Data_ab2150* d = Of_ab2150(this);
    d->mpBufferBegin = *d->mpBufferOwner;
    int zero = 0;
    d->mpBufferEnd = d->mpBufferBegin + 0x24000;
    d->mnField315c = zero;
    Fn00910003(d->mBuffer, zero, 0xc07);
    if (d->mnField120 != 0) {
        d->mnField120 = zero;
    }
    d->mpPath = 0;
}

// The object behind the global at 0xb43cec: only its slots 93 and 94 are used here.
struct cB43cec_ab2150 {
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
    virtual uint32_t Fn93();
    virtual uint32_t Fn94();
};

// GLOBAL: 0x00b43cec
extern cB43cec_ab2150* gpB43cec;

// FUNCTION: 0x006d78b0
bool cSC4PathFinder::Init()
{
    Data_ab2150* d = Of_ab2150(this);
    if (!d->mbActive) {
        d->mbActive = true;
        d->mnWidth = gpB43cec->Fn93();
        d->mnHeight = gpB43cec->Fn94();
        uint32_t fill = 0;
        d->mListA.Fn006d6920(d->mnWidth + 2, &fill);
        fill = 0;
        d->mListB.Fn006d6920(d->mnHeight + 2, &fill);
        d->mpDataA = d->mListA.mpBegin + 1;
        d->mpDataB = d->mListB.mpBegin + 1;
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006d61e0 score 204 (register allocation: the original keeps node/next in esi/edi and y, ny, dir, width on the stack)
bool cSC4PathFinder::WasTripReversible()
{
    cNode_ab2150* node = static_cast<cNode_ab2150*>(Of_ab2150(this)->mpPath);
    if (!node) {
        return true;
    }
    uint32_t prevType = node->mbByte13;
    uint32_t dir = 0xffffffff;
    cNode_ab2150* next;
    if (node->mpNext) {
        uint32_t width = Of_ab2150(this)->mnWidth;
        do {
            uint8_t type = node->mbByte13;
            next = node->mpNext;
            uint32_t x = node->mnX;
            uint32_t y = node->mnY;
            uint32_t nx = next->mnX;
            uint32_t ny = next->mnY;
            if (x < width && y < Of_ab2150(this)->mnHeight && nx < width && ny < Of_ab2150(this)->mnHeight && (x != nx || y != ny)) {
                Cell_ab2150* cells = static_cast<cMap_ab2150*>(Of_ab2150(this)->mpMap)->mpCells;
                Cell_ab2150* cell = &cells[x << 8 | y];
                if ((cell->mnFlags & 2) && (cells[nx << 8 | ny].mnFlags & 2)) {
                    dir = 0xffffffff;
                } else {
                    if (dir != 0xffffffff) {
                        if (prevType == type) {
                            if (static_cast<uint8_t>(next->mbByte13) == type) {
                                if ((cell->mnWordsA[type] & (1 << (node->mnEdge + (dir << 2)))) == 0) {
                                    return false;
                                }
                            }
                        } else if ((static_cast<uint8_t>(cell->mnWordsB[type] >> static_cast<uint8_t>(dir << 2)) & 0xf) == 0xf) {
                            return false;
                        }
                    }
                    uint8_t step;
                    if (static_cast<int>(x) < next->mnX) {
                        step = 0;
                    } else if (next->mnX < static_cast<int>(x)) {
                        step = 2;
                    } else {
                        step = static_cast<uint8_t>((static_cast<int>(ny) <= static_cast<int>(y)) * 2 + 1);
                    }
                    dir = step;
                }
            } else {
                dir = 0xffffffff;
            }
            prevType = type;
            node = next;
        } while (next->mpNext);
    }
    return true;
}
#endif
