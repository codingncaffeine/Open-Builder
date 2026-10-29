#include "classes/cUnk00a879e0.h"
#include <new>
#include <vector>

// A grid of cells the object keeps at +0x38 (one std::vector per column; the member is the 12-byte vector's storage).
typedef std::vector<std::vector<int16_t> > Cells_a879e0;

static inline Cells_a879e0& CellsOf_a879e0(cUnk00a879e0* p)
{
    return *reinterpret_cast<Cells_a879e0*>(&p->field38);
}

// The same storage seen as the original's out-of-line calls (Slot09 and Slot04 call these instead of inlining them).
// STUB: 0x00407a50
void* CopyTrivial_a879e0(const void* first, const void* last, void* result);

// STLport's deallocation the containers call out of line.
// STUB: 0x0090cf63
void StlDelete_a879e0(void* p);

// An empty allocator, and a vector of cells made by the original's out-of-line constructor.
struct Alloc_a879e0 {
};

struct Temp_a879e0 {
    int16_t* mpBegin;
    int16_t* mpEnd;
    int16_t* mpCap;
    // STUB: 0x0045bb10
    void Init(const Alloc_a879e0& alloc);
    ~Temp_a879e0()
    {
        if (mpBegin) {
            StlDelete_a879e0(mpBegin);
        }
    }
};

struct Row_a879e0 {
    int16_t* mpBegin;
    int16_t* mpEnd;
    int16_t* mpCap;
    // STUB: 0x00462130
    void Resize(uint32_t count, const int16_t& fill);
    // STUB: 0x00462170
    void FillInsert(int16_t* pos, uint32_t count, const int16_t& fill);
};

struct Rows_a879e0 {
    Row_a879e0* mpBegin;
    Row_a879e0* mpEnd;
    Row_a879e0* mpCap;
    // STUB: 0x004623b0
    void Resize(uint32_t count);
    // STUB: 0x004623f0
    void ResizeFill(uint32_t count, const Temp_a879e0& fill);
};

// The stream the grid is read from: only the slots used here are named.
struct StreamIn_a879e0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Rd04(int8_t*);
    virtual void Rd05(uint8_t*);
    virtual void Rd06(int16_t*);
    virtual void Rd07(uint16_t*);
    virtual void Rd08(int32_t*);
    virtual void Rd09(int32_t*);
    virtual void Pad10();
    virtual void Pad11();
    virtual void Rd12(float*);
};

// The stream the grid is written to.
struct StreamOut_a879e0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Wr04(uint8_t);
    virtual void Wr05(uint8_t);
    virtual void Wr06(uint16_t);
    virtual void Wr07(uint16_t);
    virtual void Wr08(int32_t);
    virtual void Wr09(int32_t);
    virtual void Pad10();
    virtual void Pad11();
    virtual void Wr12(float);
};

// STUB: 0x005d9fa0
void Fn005d9fa0(StreamIn_a879e0* stream, bool* pOut);

// STUB: 0x005d9fd0
void Fn005d9fd0(StreamOut_a879e0* stream, bool value);

// The object behind the global at 0xb43cec: only the slots used here are named.
struct cB43cec_a879e0 {
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
    virtual float Fn91();
    virtual float Fn92();
    virtual int32_t Fn93();
    virtual int32_t Fn94();
};

// GLOBAL: 0x00b43cec
extern cB43cec_a879e0* gpB43cec_a879e0;

// Two float constants of the original's data.
// FUNCTION: 0x0045ddf0 nohook
void cUnk00a879e0::Slot19_a879e0(float x, float y, void* pOutX, void* pOutY)
{
    *static_cast<int32_t*>(pOutX) = static_cast<int32_t>(x * mfInvW);
    *static_cast<int32_t*>(pOutY) = static_cast<int32_t>(y * mfInvH);
}

// FUNCTION: 0x0045e470
int16_t cUnk00a879e0::Slot07_a879e0(int32_t x, int32_t y)
{
    return CellsOf_a879e0(this)[x >> mnShift][y >> mnShift];
}

// FUNCTION: 0x0045fc80
int16_t cUnk00a879e0::Slot22_a879e0(uint32_t x, uint32_t y)
{
    return CellsOf_a879e0(this)[x][y];
}

// FUNCTION: 0x0045fca0
void cUnk00a879e0::Slot26_a879e0(uint32_t x, uint32_t y, int16_t value)
{
    CellsOf_a879e0(this)[x][y] = value;
}

// FUNCTION: 0x0045e110 nohook
bool cUnk00a879e0::Slot03_a879e0()
{
    if (!mbDirty) {
        mbDirty = true;
    }
    return true;
}

// FUNCTION: 0x0045fcc0 nohook
bool cUnk00a879e0::Slot04_a879e0()
{
    if (mbDirty) {
        mbDirty = false;
    }
    return true;
}

// FUNCTION: 0x004664a0 nohook
unsigned int cUnk00a879e0::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x0045e120 nohook
unsigned int cUnk00a879e0::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Fn0045f9f0();
    return 0;
}

// FUNCTION: 0x0045e450 nohook
uint32_t cUnk00a879e0::Slot18_a879e0(uint32_t x, uint32_t y)
{
    if (x < static_cast<uint32_t>(mnCols)) {
        if (y < static_cast<uint32_t>(mnRows)) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x0045e760 nohook
bool cUnk00a879e0::QueryInterface(unsigned int iid, void** ppv)
{
    switch (iid) {
    case 1:
    case 0xc9bd939a:
        *ppv = this;
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<cUnk00a80784*>(this);
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x0045e7c0 nohook
void cUnk00a879e0::Slot21_a879e0(int32_t x, int32_t y, void* pOutX, void* pOutY)
{
    *static_cast<float*>(pOutX) = (x + 0.5f) * mfCellW;
    *static_cast<float*>(pOutY) = (y + 0.5f) * mfCellH;
}

// FUNCTION: 0x0045ece0 nohook
void cUnk00a879e0::Slot20_a879e0(int32_t x, int32_t y, void* pOutX, void* pOutY)
{
    *static_cast<float*>(pOutX) = x * mfCellW;
    *static_cast<float*>(pOutY) = y * mfCellH;
}

// FUNCTION: 0x0045e630
void cUnk00a879e0::Slot27_a879e0(int16_t value)
{
    for (int32_t i = 0; i < mnCols; ++i) {
        for (int32_t j = 0; j < mnRows; ++j) {
            CellsOf_a879e0(this)[i][j] = value;
        }
    }
}

// FUNCTION: 0x0045e4a0
int16_t cUnk00a879e0::Slot08_a879e0(int32_t x, int32_t y, int32_t w, int32_t h)
{
    int64_t sum = 0;
    int32_t xe = x + w;
    int32_t ye = y + h;
    if ((x >> mnShift) == ((xe - 1) >> mnShift) && (y >> mnShift) == ((ye - 1) >> mnShift)) {
        return CellsOf_a879e0(this)[x >> mnShift][y >> mnShift];
    }
    for (int32_t i = x; i < xe; ++i) {
        for (int32_t j = y; j < ye; ++j) {
            sum += CellsOf_a879e0(this)[i >> mnShift][j >> mnShift];
        }
    }
    return static_cast<int16_t>(static_cast<double>(sum) / (w * h));
}

// FUNCTION: 0x0045e590
int16_t cUnk00a879e0::Slot23_a879e0(int32_t x, int32_t y, int32_t w, int32_t h)
{
    int64_t sum = 0;
    int32_t xe = x + w;
    int32_t ye = y + h;
    for (int32_t i = x; i < xe; ++i) {
        for (int32_t j = y; j < ye; ++j) {
            sum += CellsOf_a879e0(this)[i][j];
        }
    }
    return static_cast<int16_t>(static_cast<double>(sum) / (w * h));
}

// FUNCTION: 0x00462050
void cUnk00a879e0::Slot09_a879e0(int32_t size)
{
    if (size != mnCellSize) {
        mnCellSize = size;
        mnShift = 0;
        if (size > 1) {
            int32_t shift = 0;
            do {
                size /= 2;
                ++shift;
            } while (size > 1);
            mnShift = shift;
        }
        cB43cec_a879e0* g = gpB43cec_a879e0;
        mnCols = g->Fn93() >> mnShift;
        mnRows = g->Fn94() >> mnShift;
        mfCellW = g->Fn91() * mnCellSize;
        mfCellH = g->Fn92() * mnCellSize;
        mfInvW = 1.0f / mfCellW;
        mfInvH = 1.0f / mfCellH;
        Rows_a879e0* rows = reinterpret_cast<Rows_a879e0*>(&field38);
        rows->Resize(mnCols);
        for (int32_t i = 0; i < mnCols; ++i) {
            int16_t zero = 0;
            rows->mpBegin[i].Resize(mnRows, zero);
        }
    }
}

// FUNCTION: 0x0045e680
bool cUnk00a879e0::Slot03_a80784(void* pStream)
{
    StreamOut_a879e0* s = static_cast<StreamOut_a879e0*>(pStream);
    s->Wr07(1);
    Fn005d9fd0(s, mbDirty);
    s->Wr09(mnUnk10);
    s->Wr09(mnUnk14);
    s->Wr08(mnCellSize);
    s->Wr08(mnShift);
    s->Wr08(mnCols);
    s->Wr08(mnRows);
    s->Wr12(mfCellW);
    s->Wr12(mfCellH);
    s->Wr12(mfInvW);
    s->Wr12(mfInvH);
    for (int32_t i = 0; i < mnCols; ++i) {
        for (int32_t j = 0; j < mnRows; ++j) {
            s->Wr06(CellsOf_a879e0(this)[i][j]);
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004626e0 score 90 (register choice only: the original keeps the cols/rows field addresses in ebx/ebp and reuses this for the cell vector; the permuter reached 41)
bool cUnk00a879e0::Slot04_a80784(void* pStream)
{
    StreamIn_a879e0* s = static_cast<StreamIn_a879e0*>(pStream);
    uint16_t version;
    s->Rd07(&version);
    if (version != 1) {
        return false;
    }
    Fn005d9fa0(s, &mbDirty);
    s->Rd09(&mnUnk10);
    s->Rd09(&mnUnk14);
    s->Rd08(&mnCellSize);
    s->Rd08(&mnShift);
    s->Rd08(&mnCols);
    s->Rd08(&mnRows);
    s->Rd12(&mfCellW);
    s->Rd12(&mfCellH);
    s->Rd12(&mfInvW);
    s->Rd12(&mfInvH);
    int32_t n = mnCols;
    Rows_a879e0* rows;
    {
        Alloc_a879e0 alloc;
        Temp_a879e0 temp;
        temp.Init(alloc);
        rows = reinterpret_cast<Rows_a879e0*>(&field38);
        rows->ResizeFill(n, temp);
    }
    for (int32_t i = 0; i < mnCols; ++i) {
        Row_a879e0* row = &rows->mpBegin[i];
        uint32_t count = mnRows;
        int16_t zero = 0;
        int16_t* pEnd = row->mpEnd;
        int16_t* pBegin = row->mpBegin;
        if (count < static_cast<uint32_t>(pEnd - pBegin)) {
            row->mpEnd = static_cast<int16_t*>(CopyTrivial_a879e0(pEnd, pEnd, pBegin + count));
        } else {
            row->FillInsert(pEnd, count - (pEnd - pBegin), zero);
        }
        for (int32_t j = 0; j < mnRows; ++j) {
            s->Rd06(&rows->mpBegin[i].mpBegin[j]);
        }
    }
    return true;
}
#endif
