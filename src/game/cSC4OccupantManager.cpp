#include <cstddef>

#include "classes/cSC4OccupantManager.h"

// A field of this object by its offset (the class header has the bytes unnamed).
#define FLD_a8f7f0(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

// A node of the circular lists the game keeps (head node = the list object's first word).
struct Node_a8f7f0 {
    Node_a8f7f0* mpNext;
    Node_a8f7f0* mpPrev;
    uint32_t mValue;
};

struct List_a8f7f0 {
    Node_a8f7f0* mpHead;
    // STUB: 0x00413e60
    void Fn00413e60();
};

// The record at +0x34: the forwarding methods store their pointer argument in its word 3.
struct Rec_a8f7f0 {
    uint32_t mWords[3];
    uint32_t mValue;
};

// An object released through its slot 2.
struct OB_NOVTABLE Rel_a8f7f0 {
    virtual void Pad00_a8f7f0(); virtual void Pad01_a8f7f0(); 
    virtual uint32_t Release_a8f7f0() = 0;
};

// The object at +0x14: slot 1 takes a lock, slot 2 gives it back.
struct OB_NOVTABLE Lock_a8f7f0 {
    virtual void Pad00_a8f7f0();
    virtual void Enter_a8f7f0() = 0;
    virtual void Leave_a8f7f0() = 0;
};

// An object whose slot 4 is called with no arguments.
struct OB_NOVTABLE Obj4_a8f7f0 {
    virtual void Pad00_a8f7f0(); virtual void Pad01_a8f7f0(); virtual void Pad02_a8f7f0(); virtual void Pad03_a8f7f0(); 
    virtual void Slot04_a8f7f0() = 0;
};

// FUNCTION: 0x006b8aa0
bool cSC4OccupantManager::Slot03_aaaa9c(void* a)
{
    static_cast<Obj4_a8f7f0*>(a)->Slot04_a8f7f0();
    return true;
}

// FUNCTION: 0x0049d9d0
void cSC4OccupantManager::GetOccupantManagerCellCount(uint32_t a, uint32_t b)
{
    *OB_PTR(int32_t, a) = FLD_a8f7f0(int32_t, 0x24);
    *OB_PTR(int32_t, b) = FLD_a8f7f0(int32_t, 0x28);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0049db80 score 4
void cSC4OccupantManager::Slot23_a8f7f0(uint32_t a, uint32_t b, uint32_t c)
{
    Rec_a8f7f0* r = FLD_a8f7f0(Rec_a8f7f0*, 0x34);
    r->mValue = a;
    Slot22_a8f7f0(OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)), b, c);
}
#endif

// FUNCTION: 0x0049d990
void cSC4OccupantManager::GetOccupantManagerCellSizes(uint32_t a, uint32_t b)
{
    *OB_PTR(float, a) = 64.0f;
    *OB_PTR(float, b) = 64.0f;
}

// FUNCTION: 0x0049d9b0
void cSC4OccupantManager::GetWorldCellCount(uint32_t a, uint32_t b)
{
    *OB_PTR(int32_t, a) = 0xc0;
    *OB_PTR(int32_t, b) = 0xc0;
}

// FUNCTION: 0x0049d9f0
void cSC4OccupantManager::WorldCellToOccupantManagerCell(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(int32_t, c) = static_cast<int32_t>(a) - 0x40;
    *OB_PTR(int32_t, d) = static_cast<int32_t>(b) - 0x40;
}

// FUNCTION: 0x0049da10
void cSC4OccupantManager::OccupantManagerCellToWorldCell(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(int32_t, c) = static_cast<int32_t>(a) + 0x40;
    *OB_PTR(int32_t, d) = static_cast<int32_t>(b) + 0x40;
}

// FUNCTION: 0x0049da30
void cSC4OccupantManager::WorldCellToStandardCityCell(uint32_t /*a*/, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(int32_t, c) = (static_cast<int32_t>(b) - 0x40) * 4;
    *OB_PTR(int32_t, d) = *OB_PTR(int32_t, d) * 4;
}

// FUNCTION: 0x0049da50
void cSC4OccupantManager::StandardCityCellToWorldCell(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(int32_t, c) = static_cast<int32_t>(a) / 4 + 0x40;
    *OB_PTR(int32_t, d) = static_cast<int32_t>(b) / 4 + 0x40;
}

// FUNCTION: 0x0049daf0
void cSC4OccupantManager::OccupantManagerCellToPosition(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(float, c) = static_cast<float>(static_cast<int32_t>(a) << 6);
    *OB_PTR(float, d) = static_cast<float>(static_cast<int32_t>(b) << 6);
}

// FUNCTION: 0x0049db20
void cSC4OccupantManager::StandardCityCellToPosition(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(float, c) = static_cast<float>(static_cast<int32_t>(a) << 4);
    *OB_PTR(float, d) = static_cast<float>(static_cast<int32_t>(b) << 4);
}

// FUNCTION: 0x0049da80
void cSC4OccupantManager::WorldCellToPosition(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(float, c) = static_cast<float>((static_cast<int32_t>(a) - 0x40) << 6);
    *OB_PTR(float, d) = static_cast<float>((static_cast<int32_t>(b) - 0x40) << 6);
}

// FUNCTION: 0x0049db50
void cSC4OccupantManager::GetOccupantManagerCellBounds(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *OB_PTR(int32_t, a) = 0x40;
    *OB_PTR(int32_t, b) = 0x40;
    *OB_PTR(int32_t, c) = FLD_a8f7f0(int32_t, 0x24) + 0x3f;
    *OB_PTR(int32_t, d) = FLD_a8f7f0(int32_t, 0x28) + 0x3f;
}

// FUNCTION: 0x0049dc80
bool cSC4OccupantManager::GetFirstOccupantByPosition_2(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    if (FLD_a8f7f0(bool, 0xc)) {
        FLD_a8f7f0(Rec_a8f7f0*, 0x34)->mValue = d;
        return GetFirstOccupantByPosition(a, b, c, OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)));
    }
    return false;
}

// FUNCTION: 0x0049dcb0
bool cSC4OccupantManager::GetFirstOccupant_2(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    if (FLD_a8f7f0(bool, 0xc)) {
        FLD_a8f7f0(Rec_a8f7f0*, 0x34)->mValue = d;
        return GetFirstOccupant(a, b, c, OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)));
    }
    return false;
}

// FUNCTION: 0x0049dce0
bool cSC4OccupantManager::GetFirstOccupantByStandardCityCell_2(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    if (FLD_a8f7f0(bool, 0xc)) {
        FLD_a8f7f0(Rec_a8f7f0*, 0x34)->mValue = d;
        return GetFirstOccupantByStandardCityCell(a, b, c, OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)));
    }
    return false;
}

// FUNCTION: 0x0049dd10
bool cSC4OccupantManager::GetFirstOccupantByStandardCityCells(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    if (FLD_a8f7f0(bool, 0xc)) {
        FLD_a8f7f0(Rec_a8f7f0*, 0x34)->mValue = d;
        return Slot34_a8f7f0(a, b, c, OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)));
    }
    return false;
}

// FUNCTION: 0x0049dd40
bool cSC4OccupantManager::GetOccupantsByBBox_2(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    if (FLD_a8f7f0(bool, 0xc)) {
        if (d) {
            FLD_a8f7f0(Rec_a8f7f0*, 0x34)->mValue = d;
            return GetOccupantsByBBox(a, b, c, OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)), e);
        }
        return GetOccupantsByBBox(a, b, c, 0, e);
    }
    return false;
}

// FUNCTION: 0x0049dd80
bool cSC4OccupantManager::GetOccupantsByOccupantManagerCells_2(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    if (FLD_a8f7f0(bool, 0xc)) {
        if (d) {
            FLD_a8f7f0(Rec_a8f7f0*, 0x34)->mValue = d;
            return GetOccupantsByOccupantManagerCells(a, b, c, OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)), e);
        }
        return GetOccupantsByOccupantManagerCells(a, b, c, 0, e);
    }
    return false;
}

// FUNCTION: 0x0049ddc0
bool cSC4OccupantManager::GetOccupantsByStandardCityCells_2(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    if (FLD_a8f7f0(bool, 0xc)) {
        if (d) {
            FLD_a8f7f0(Rec_a8f7f0*, 0x34)->mValue = d;
            return GetOccupantsByStandardCityCells(a, b, c, OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)), e);
        }
        return GetOccupantsByStandardCityCells(a, b, c, 0, e);
    }
    return false;
}

// FUNCTION: 0x0049de00
bool cSC4OccupantManager::IterateOccupantsByBBox(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    if (FLD_a8f7f0(bool, 0xc)) {
        if (e) {
            FLD_a8f7f0(Rec_a8f7f0*, 0x34)->mValue = e;
            return Slot42_a8f7f0(a, b, c, d, OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)));
        }
        return Slot42_a8f7f0(a, b, c, d, 0);
    }
    return false;
}

// FUNCTION: 0x0049de40
bool cSC4OccupantManager::IterateOccupants_2(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    if (FLD_a8f7f0(bool, 0xc)) {
        if (e) {
            FLD_a8f7f0(Rec_a8f7f0*, 0x34)->mValue = e;
            return IterateOccupants(a, b, c, d, OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)));
        }
        return IterateOccupants(a, b, c, d, 0);
    }
    return false;
}

// FUNCTION: 0x0049de80
bool cSC4OccupantManager::IterateOccupantsByStandardCityCell(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    if (FLD_a8f7f0(bool, 0xc)) {
        if (e) {
            FLD_a8f7f0(Rec_a8f7f0*, 0x34)->mValue = e;
            return IterateOccupantsByStandardCityCell_2(a, b, c, d, OB_ADDR(FLD_a8f7f0(Rec_a8f7f0*, 0x34)));
        }
        return IterateOccupantsByStandardCityCell_2(a, b, c, d, 0);
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0049df80 score 23
uint32_t cSC4OccupantManager::AddRef()
{
    Lock_a8f7f0* lock = reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14);
    lock->Enter_a8f7f0();
    uint32_t n = FLD_a8f7f0(uint32_t, 0x10) + 1;
    FLD_a8f7f0(uint32_t, 0x10) = n;
    lock->Leave_a8f7f0();
    return n;
}
#endif

// FUNCTION: 0x0049ef30
void cSC4OccupantManager::ReleaseOccupantList(uint32_t a)
{
    List_a8f7f0* l = OB_PTR(List_a8f7f0, a);
    Node_a8f7f0* head = l->mpHead;
    for (Node_a8f7f0* p = head->mpNext; p != head; p = p->mpNext) {
        OB_PTR(Rel_a8f7f0, p->mValue)->Release_a8f7f0();
    }
    l->Fn00413e60();
}

// An array of cell rows: three words per column, the first a pointer to the column's cells.
struct Col_a8f7f0 {
    List_a8f7f0** mppCells;
    uint32_t mUnused[2];
};

// FUNCTION: 0x0049e490
bool cSC4OccupantManager::IsCellEmpty(uint32_t a, uint32_t b)
{
    int32_t x = static_cast<int32_t>(a);
    int32_t y = static_cast<int32_t>(b);
    if (x >= 0 && x < 0xc0 && y >= 0 && y < 0xc0) {
        List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
        if (l) {
            if (l->mpHead->mpNext != l->mpHead) {
                return false;
            }
        }
    }
    return true;
}

// FUNCTION: 0x0049e000
bool cSC4OccupantManager::Shutdown()
{
    Lock_a8f7f0* lock = reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14);
    lock->Enter_a8f7f0();
    if (FLD_a8f7f0(bool, 0xc)) {
        Slot22_a8f7f0(0, 1, 0);
        if (FLD_a8f7f0(Rel_a8f7f0*, 0x34)) {
            FLD_a8f7f0(Rel_a8f7f0*, 0x34)->Release_a8f7f0();
            FLD_a8f7f0(Rel_a8f7f0*, 0x34) = 0;
        }
        FLD_a8f7f0(bool, 0xc) = false;
    }
    lock->Leave_a8f7f0();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0049dfb0 score 2
uint32_t cSC4OccupantManager::Release()
{
    Lock_a8f7f0* lock = reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14);
    lock->Enter_a8f7f0();
    uint32_t n = FLD_a8f7f0(uint32_t, 0x10);
    if (n > 1) {
        uint32_t m = n - 1;
        FLD_a8f7f0(uint32_t, 0x10) = m;
        lock->Leave_a8f7f0();
        return m;
    }
    lock->Leave_a8f7f0();
    Shutdown();
    delete this;
    return 0;
}
#endif

// FUNCTION: 0x0049d910
bool cSC4OccupantManager::QueryInterface(uint32_t iid, void** out)
{
    void** pp = out;
    switch (iid) {
    case 1:
    case 0xc6bb8334:
        *pp = this;
        AddRef();
        return true;
    case 0x452294aa:
        *pp = static_cast<cUnk00aaaa9c*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *pp = static_cast<cUnk00a80784*>(this);
        AddRef();
        return true;
    }
    return false;
}

// The float-bits trick: the nearest integer of a value (adding 1.5 * 2^23 leaves it in the mantissa).
union Bits_a8f7f0 {
    float f;
    int32_t i;
};

// FUNCTION: 0x0049e150
void cSC4OccupantManager::PositionToOccupantManagerCell(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Bits_a8f7f0 x;
    x.f = *reinterpret_cast<float*>(&a) * 0.015625f - 0.499f + 12582912.0f;
    *OB_PTR(int32_t, c) = x.i - 0x4b400000;
    Bits_a8f7f0 y;
    y.f = *reinterpret_cast<float*>(&b) * 0.015625f - 0.499f + 12582912.0f;
    *OB_PTR(int32_t, d) = y.i - 0x4b400000;
}

// FUNCTION: 0x0049e0e0
void cSC4OccupantManager::PositionToWorldCell(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Bits_a8f7f0 x;
    x.f = (*reinterpret_cast<float*>(&a) + 4096.0f) * 0.015625f - 0.499f + 12582912.0f;
    *OB_PTR(int32_t, c) = x.i - 0x4b400000;
    Bits_a8f7f0 y;
    y.f = (*reinterpret_cast<float*>(&b) + 4096.0f) * 0.015625f - 0.499f + 12582912.0f;
    *OB_PTR(int32_t, d) = y.i - 0x4b400000;
}

// FUNCTION: 0x0049e1b0
void cSC4OccupantManager::PositionToStandardCityCell(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    float fa = *reinterpret_cast<float*>(&a) * 0.0625f;
    Bits_a8f7f0 x;
    x.f = (fa - 0.5f) + 12582912.0f;
    int32_t rx = x.i - 0x4b400000;
    if (fa == static_cast<float>(rx + 1)) {
        rx = rx + 1;
    }
    *OB_PTR(int32_t, c) = rx;
    float fb = *reinterpret_cast<float*>(&b) * 0.0625f;
    Bits_a8f7f0 y;
    y.f = (fb - 0.5f) + 12582912.0f;
    int32_t ry = y.i - 0x4b400000;
    if (fb == static_cast<float>(ry + 1)) {
        ry = ry + 1;
    }
    *OB_PTR(int32_t, d) = ry;
}

// FUNCTION: 0x0049dac0
void cSC4OccupantManager::Fn0049dac0(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    int32_t x;
    int32_t y;
    PositionToWorldCell(a, b, OB_ADDR(&x), OB_ADDR(&y));
    *OB_PTR(uint8_t, c) = static_cast<uint8_t>(x);
    *OB_PTR(uint8_t, d) = static_cast<uint8_t>(y);
}

// Holds the lock of the manager for the length of a method.
struct Guard_a8f7f0 {
    Lock_a8f7f0* mpLock;
    Guard_a8f7f0(Lock_a8f7f0* lock)
    {
        mpLock = lock;
        mpLock->Enter_a8f7f0();
    }
    ~Guard_a8f7f0() { mpLock->Leave_a8f7f0(); }
};

// An occupant: slot 1 adds a reference.
struct OB_NOVTABLE Occ_a8f7f0 {
    virtual void Pad00_a8f7f0();
    virtual void AddRef_a8f7f0() = 0;
};

// An occupant filter: slot 3 says whether an occupant passes.
struct OB_NOVTABLE Filter_a8f7f0 {
    virtual void Pad00_a8f7f0(); virtual void Pad01_a8f7f0(); virtual void Pad02_a8f7f0();
    virtual bool Pass_a8f7f0(Occ_a8f7f0* occ) = 0;
};

// FUNCTION: 0x0049e050
bool cSC4OccupantManager::SetCitySize(uint32_t a, uint32_t b)
{
    Lock_a8f7f0* lock = reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14);
    lock->Enter_a8f7f0();
    if (!FLD_a8f7f0(bool, 0xc)) {
        FLD_a8f7f0(uint32_t, 0x1c) = a;
        FLD_a8f7f0(uint32_t, 0x20) = b;
        FLD_a8f7f0(int32_t, 0x24) = static_cast<int32_t>(*reinterpret_cast<float*>(&a) * 0.015625f);
        FLD_a8f7f0(int32_t, 0x28) = static_cast<int32_t>(*reinterpret_cast<float*>(&b) * 0.015625f);
        FLD_a8f7f0(int32_t, 0x2c) = static_cast<int32_t>(*reinterpret_cast<float*>(&a) * 0.0625f);
        FLD_a8f7f0(int32_t, 0x30) = static_cast<int32_t>(*reinterpret_cast<float*>(&b) * 0.0625f);
        lock->Leave_a8f7f0();
        return true;
    }
    lock->Leave_a8f7f0();
    return false;
}

// FUNCTION: 0x0049df00
void OB_STDCALL Fn0049df00(int32_t* a, int32_t* b, int32_t* c, int32_t* d)
{
    if (*a < 0) {
        *a = 0;
    }
    if (*b < 0) {
        *b = 0;
    }
    if (*a >= 0xc0) {
        *a = 0xbf;
    }
    if (*b >= 0xc0) {
        *b = 0xbf;
    }
    if (*c < 0) {
        *c = 0;
    }
    if (*d < 0) {
        *d = 0;
    }
    if (*c >= 0xc0) {
        *c = 0xbf;
    }
    if (*d >= 0xc0) {
        *d = 0xbf;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0049e5e0 score 16
bool cSC4OccupantManager::GetFirstOccupant(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    bool found = false;
    Guard_a8f7f0 guard(reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14));
    if (FLD_a8f7f0(bool, 0xc)) {
        int32_t x = static_cast<int32_t>(b);
        int32_t y = static_cast<int32_t>(c);
        if (x >= 0 && x < 0xc0 && y >= 0 && y < 0xc0) {
            List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
            if (l) {
                Node_a8f7f0* head = l->mpHead;
                for (Node_a8f7f0* p = head->mpNext; p != head; p = p->mpNext) {
                    Occ_a8f7f0* occ = OB_PTR(Occ_a8f7f0, p->mValue & 0xfffffffe);
                    if (!d || OB_PTR(Filter_a8f7f0, d)->Pass_a8f7f0(occ)) {
                        *OB_PTR(Occ_a8f7f0*, a) = occ;
                        occ->AddRef_a8f7f0();
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    return found;
}
#endif

// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t size);
// STUB: 0x0090cf54
Node_a8f7f0* Fn0090cf54(uint32_t size);

#ifdef OB_DRAFTS
// CLOSE: 0x0049ee80 score 41
void* cSC4OccupantManager::GetOccupantList(int32_t x, int32_t y, bool create)
{
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (x >= 0xc0) {
        x = 0xbf;
    }
    if (y >= 0xc0) {
        y = 0xbf;
    }
    List_a8f7f0* cur = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
    if (!cur && create) {
        List_a8f7f0* nl = static_cast<List_a8f7f0*>(Fn005e55e0(4));
        if (nl) {
            nl->mpHead = 0;
            Node_a8f7f0* n = Fn0090cf54(0xc);
            n->mpNext = n;
            n->mpPrev = n;
            nl->mpHead = n;
        }
        FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y] = nl;
        return nl;
    }
    return cur;
}
#endif

// ---- wave 11b ----
struct OB_NOVTABLE Occ2_a8f7f0 {
    virtual void Pad00_a8f7f0();
    virtual void AddRef_a8f7f0() = 0;
    virtual void Pad02_a8f7f0();
    virtual void Pad03_a8f7f0();
    virtual void Pad04_a8f7f0();
    virtual void Pad05_a8f7f0();
    virtual void Pad06_a8f7f0();
    virtual void Pad07_a8f7f0();
    virtual void Pad08_a8f7f0();
    virtual void Pad09_a8f7f0();
    virtual void GetBounds_a8f7f0(float* lo, float* hi) = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0049dba0 score 6
uint32_t cSC4OccupantManager::GetBoundingCells(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    int32_t x = static_cast<int32_t>(a);
    int32_t y = static_cast<int32_t>(b);
    int32_t* cells = OB_PTR(int32_t, c);
    int32_t* count = OB_PTR(int32_t, d);
    if (x >= 1 && x < 0xbf && y >= 1 && y < 0xbf) {
        cells[0] = x - 1;
        cells[1] = y - 1;
        cells[2] = x - 1;
        cells[3] = y;
        cells[4] = x - 1;
        cells[5] = y + 1;
        cells[6] = x;
        cells[7] = y - 1;
        cells[8] = x;
        cells[9] = y + 1;
        cells[10] = x + 1;
        cells[11] = y - 1;
        cells[12] = x + 1;
        cells[13] = y;
        cells[14] = x + 1;
        cells[15] = y + 1;
        *count = 8;
        return *count;
    }
    *count = 0;
    for (int32_t cx = x - 1; cx <= x + 1; ++cx) {
        for (int32_t cy = y - 1; cy <= y + 1; ++cy) {
            if (cx >= 0 && cx < 0xc0 && cy >= 0 && cy < 0xc0 && (cx != x || cy != y)) {
                cells[*count * 2] = cx;
                cells[*count * 2 + 1] = cy;
                ++*count;
            }
        }
    }
    return *count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0049e250 score 34
bool cSC4OccupantManager::GetOccupantsByStandardCityCells(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    if (!FLD_a8f7f0(bool, 0xc)) {
        return false;
    }
    int32_t x0;
    int32_t y0;
    if (b) {
        x0 = OB_PTR(int32_t, b)[0];
        y0 = OB_PTR(int32_t, b)[1];
        if (x0 < 0) {
            x0 = 0;
        }
        if (y0 < 0) {
            y0 = 0;
        }
        if (x0 >= FLD_a8f7f0(int32_t, 0x2c)) {
            x0 = FLD_a8f7f0(int32_t, 0x2c) - 1;
        }
        if (y0 >= FLD_a8f7f0(int32_t, 0x30)) {
            y0 = FLD_a8f7f0(int32_t, 0x30) - 1;
        }
    } else {
        x0 = 0;
        y0 = 0;
    }
    int32_t x1;
    int32_t y1;
    if (c) {
        x1 = OB_PTR(int32_t, c)[0];
        y1 = OB_PTR(int32_t, c)[1];
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x1 >= FLD_a8f7f0(int32_t, 0x2c)) {
            x1 = FLD_a8f7f0(int32_t, 0x2c) - 1;
        }
        if (y1 >= FLD_a8f7f0(int32_t, 0x30)) {
            y1 = FLD_a8f7f0(int32_t, 0x30) - 1;
        }
    } else {
        x1 = FLD_a8f7f0(int32_t, 0x2c);
        y1 = FLD_a8f7f0(int32_t, 0x30);
    }
    float lo[3];
    float hi[3];
    StandardCityCellToPosition(x0, y0, OB_ADDR(&lo[0]), OB_ADDR(&lo[2]));
    StandardCityCellToPosition(x1 + 1, y1 + 1, OB_ADDR(&hi[0]), OB_ADDR(&hi[2]));
    lo[0] = lo[0] + 0.1f;
    lo[2] = lo[2] + 0.1f;
    hi[0] = hi[0] - 0.1f;
    hi[2] = hi[2] - 0.1f;
    lo[1] = -3.4028235e+38f;
    hi[1] = 3.4028235e+38f;
    return GetOccupantsByBBox(a, OB_ADDR(lo), OB_ADDR(hi), d, e);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0049e370 score 34
bool cSC4OccupantManager::IterateOccupantsByStandardCityCell_2(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    if (!FLD_a8f7f0(bool, 0xc)) {
        return false;
    }
    int32_t x0;
    int32_t y0;
    if (c) {
        x0 = OB_PTR(int32_t, c)[0];
        y0 = OB_PTR(int32_t, c)[1];
        if (x0 < 0) {
            x0 = 0;
        }
        if (y0 < 0) {
            y0 = 0;
        }
        if (x0 >= FLD_a8f7f0(int32_t, 0x2c)) {
            x0 = FLD_a8f7f0(int32_t, 0x2c) - 1;
        }
        if (y0 >= FLD_a8f7f0(int32_t, 0x30)) {
            y0 = FLD_a8f7f0(int32_t, 0x30) - 1;
        }
    } else {
        x0 = 0;
        y0 = 0;
    }
    int32_t x1;
    int32_t y1;
    if (d) {
        x1 = OB_PTR(int32_t, d)[0];
        y1 = OB_PTR(int32_t, d)[1];
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x1 >= FLD_a8f7f0(int32_t, 0x2c)) {
            x1 = FLD_a8f7f0(int32_t, 0x2c) - 1;
        }
        if (y1 >= FLD_a8f7f0(int32_t, 0x30)) {
            y1 = FLD_a8f7f0(int32_t, 0x30) - 1;
        }
    } else {
        x1 = FLD_a8f7f0(int32_t, 0x2c);
        y1 = FLD_a8f7f0(int32_t, 0x30);
    }
    float lo[3];
    float hi[3];
    StandardCityCellToPosition(x0, y0, OB_ADDR(&lo[0]), OB_ADDR(&lo[2]));
    StandardCityCellToPosition(x1 + 1, y1 + 1, OB_ADDR(&hi[0]), OB_ADDR(&hi[2]));
    lo[0] = lo[0] + 0.1f;
    lo[2] = lo[2] + 0.1f;
    hi[0] = hi[0] - 0.1f;
    hi[2] = hi[2] - 0.1f;
    lo[1] = -3.4028235e+38f;
    hi[1] = 3.4028235e+38f;
    return Slot42_a8f7f0(a, b, OB_ADDR(lo), OB_ADDR(hi), e);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0049e4d0 score 52
bool cSC4OccupantManager::GetFirstOccupantByPosition(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    bool found = false;
    Guard_a8f7f0 guard(reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14));
    if (FLD_a8f7f0(bool, 0xc)) {
        int32_t cx;
        int32_t cy;
        PositionToWorldCell(b, c, OB_ADDR(&cx), OB_ADDR(&cy));
        List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[cx].mppCells[cy];
        if (l) {
            Node_a8f7f0* head = l->mpHead;
            for (Node_a8f7f0* p = head->mpNext; p != head; p = p->mpNext) {
                Occ2_a8f7f0* occ = OB_PTR(Occ2_a8f7f0, p->mValue & 0xfffffffe);
                if (d && !OB_PTR(Filter_a8f7f0, d)->Pass_a8f7f0(reinterpret_cast<Occ_a8f7f0*>(occ))) {
                    continue;
                }
                float lo[3];
                float hi[3];
                occ->GetBounds_a8f7f0(lo, hi);
                float px = *reinterpret_cast<float*>(&b);
                float pz = *reinterpret_cast<float*>(&c);
                if (lo[0] <= px && px < hi[0] && lo[2] <= pz && pz < hi[2]) {
                    *OB_PTR(Occ2_a8f7f0*, a) = occ;
                    occ->AddRef_a8f7f0();
                    found = true;
                    break;
                }
            }
        }
    }
    return found;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0049e690 score 106
bool cSC4OccupantManager::GetFirstOccupantByStandardCityCell(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    bool found = false;
    Guard_a8f7f0 guard(reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14));
    if (FLD_a8f7f0(bool, 0xc)) {
        int32_t px = static_cast<int32_t>(b) << 4;
        int32_t py = static_cast<int32_t>(c) << 4;
        float x0 = static_cast<float>(px) + 0.1f;
        float y0 = static_cast<float>(py) + 0.1f;
        float x1 = (static_cast<float>(px) + 16.0f) - 0.1f;
        float y1 = (16.0f + static_cast<float>(py)) - 0.1f;
        int32_t cx;
        int32_t cy;
        PositionToWorldCell(*reinterpret_cast<uint32_t*>(&x0), *reinterpret_cast<uint32_t*>(&y0), OB_ADDR(&cx), OB_ADDR(&cy));
        List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[cx].mppCells[cy];
        if (l) {
            Node_a8f7f0* head = l->mpHead;
            for (Node_a8f7f0* p = head->mpNext; p != head; p = p->mpNext) {
                Occ2_a8f7f0* occ = OB_PTR(Occ2_a8f7f0, p->mValue & 0xfffffffe);
                if (d && !OB_PTR(Filter_a8f7f0, d)->Pass_a8f7f0(reinterpret_cast<Occ_a8f7f0*>(occ))) {
                    continue;
                }
                float lo[3];
                float hi[3];
                occ->GetBounds_a8f7f0(lo, hi);
                if (lo[0] < x1 && x0 < hi[0] && lo[2] < y1 && y0 < hi[2]) {
                    *OB_PTR(Occ2_a8f7f0*, a) = occ;
                    occ->AddRef_a8f7f0();
                    found = true;
                    break;
                }
            }
        }
    }
    return found;
}
#endif

// ---- wave 11b batch 2 ----
struct OB_NOVTABLE Occ3_a8f7f0 {
    virtual void Pad00_a8f7f0();
    virtual void AddRef_a8f7f0() = 0;
    virtual uint32_t Release_a8f7f0() = 0;
    virtual void Pad03_a8f7f0();
    virtual void Slot4_a8f7f0() = 0;
    virtual void Pad05_a8f7f0();
    virtual void* Props_a8f7f0() = 0;
    virtual void Pad07_a8f7f0();
    virtual void Pad08_a8f7f0();
    virtual void Pad09_a8f7f0();
    virtual void Bounds_a8f7f0(float* lo, float* hi) = 0;
    virtual void Pad11_a8f7f0();
    virtual void Pad12_a8f7f0();
    virtual void Pad13_a8f7f0();
    virtual void Pad14_a8f7f0();
    virtual void S15_a8f7f0(uint32_t a, uint32_t b) = 0;
    virtual void Pad16_a8f7f0();
    virtual void Pad17_a8f7f0();
    virtual void Pad18_a8f7f0();
    virtual void Pad19_a8f7f0();
    virtual void Pad20_a8f7f0();
    virtual void Pad21_a8f7f0();
    virtual void Pad22_a8f7f0();
    virtual void Pad23_a8f7f0();
    virtual void Pad24_a8f7f0();
    virtual bool Cells_a8f7f0(uint8_t* out) = 0;
    virtual void SetCells_a8f7f0(uint8_t* in) = 0;
    virtual void Pad27_a8f7f0();
    virtual void Pad28_a8f7f0();
    virtual void Pad29_a8f7f0();
    virtual void Pad30_a8f7f0();
    virtual void S31_a8f7f0(uint32_t a) = 0;
    virtual bool S32_a8f7f0(uint32_t a) = 0;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);
// STUB: 0x005e5620
void Fn005e5620(void* p);

struct ListD_a8f7f0 {
    // STUB: 0x005650a0
    void Fn005650a0();
};

// A node whose value is an occupant pointer with the low bit as a flag; the first with the occupant, or the head.
inline Node_a8f7f0* EncFind_a8f7f0(List_a8f7f0* l, uint32_t occ)
{
    Node_a8f7f0* head = l->mpHead;
    Node_a8f7f0* n = head->mpNext;
    if (n != head) {
        do {
            if (occ == (n->mValue & 0xfffffffe)) {
                break;
            }
            n = n->mpNext;
        } while (n != head);
    }
    return n;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0049f7c0 score 79
void* cSC4OccupantManager::GetOccupantListFor(uint32_t occ, uint32_t px, uint32_t py)
{
    Occ3_a8f7f0* o = OB_PTR(Occ3_a8f7f0, occ);
    if (o->Props_a8f7f0()) {
        uint8_t c[4];
        if (!o->Cells_a8f7f0(c)) {
            float lo[3];
            float hi[3];
            o->Bounds_a8f7f0(lo, hi);
            if (1.0f < hi[0] - lo[0]) {
                lo[0] = lo[0] + 0.1f;
                hi[0] = hi[0] - 0.1f;
            }
            PositionToWorldCell(*reinterpret_cast<uint32_t*>(&lo[0]), *reinterpret_cast<uint32_t*>(&lo[2]), px, py);
        } else {
            *OB_PTR(int32_t, px) = c[0];
            *OB_PTR(int32_t, py) = c[1];
        }
    }
    return GetOccupantList(*OB_PTR(int32_t, px), *OB_PTR(int32_t, py), false);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0049e800 score 305
bool cSC4OccupantManager::Slot34_a8f7f0(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Guard_a8f7f0 guard(reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14));
    if (!FLD_a8f7f0(bool, 0xc)) {
        return false;
    }
    int32_t x0;
    int32_t y0;
    if (b) {
        x0 = OB_PTR(int32_t, b)[0];
        y0 = OB_PTR(int32_t, b)[1];
        if (x0 < 0) {
            x0 = 0;
        }
        if (y0 < 0) {
            y0 = 0;
        }
        if (x0 >= FLD_a8f7f0(int32_t, 0x2c)) {
            x0 = FLD_a8f7f0(int32_t, 0x2c) - 1;
        }
        if (y0 >= FLD_a8f7f0(int32_t, 0x30)) {
            y0 = FLD_a8f7f0(int32_t, 0x30) - 1;
        }
    } else {
        x0 = 0;
        y0 = 0;
    }
    int32_t x1;
    int32_t y1;
    if (c) {
        x1 = OB_PTR(int32_t, c)[0];
        y1 = OB_PTR(int32_t, c)[1];
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x1 >= FLD_a8f7f0(int32_t, 0x2c)) {
            x1 = FLD_a8f7f0(int32_t, 0x2c) - 1;
        }
        if (y1 >= FLD_a8f7f0(int32_t, 0x30)) {
            y1 = FLD_a8f7f0(int32_t, 0x30) - 1;
        }
    } else {
        x1 = FLD_a8f7f0(int32_t, 0x2c);
        y1 = FLD_a8f7f0(int32_t, 0x30);
    }
    float fx0 = static_cast<float>(x0 << 4);
    float fy0 = static_cast<float>(y0 << 4);
    float fx1 = static_cast<float>((x1 + 1) << 4);
    float fy1 = static_cast<float>((y1 + 1) << 4);
    float lx = fx0 + 0.1f;
    float ly = fy0 + 0.1f;
    float hx = fx1 - 0.1f;
    float hy = fy1 - 0.1f;
    int32_t wx0;
    int32_t wy0;
    int32_t wx1;
    int32_t wy1;
    PositionToWorldCell(*reinterpret_cast<uint32_t*>(&lx), *reinterpret_cast<uint32_t*>(&ly), OB_ADDR(&wx0), OB_ADDR(&wy0));
    PositionToWorldCell(*reinterpret_cast<uint32_t*>(&hx), *reinterpret_cast<uint32_t*>(&hy), OB_ADDR(&wx1), OB_ADDR(&wy1));
    for (int32_t cx = wx0; cx <= wx1; ++cx) {
        for (int32_t cy = wy0; cy <= wy1; ++cy) {
            List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[cx].mppCells[cy];
            if (!l) {
                continue;
            }
            Node_a8f7f0* head = l->mpHead;
            for (Node_a8f7f0* p = head->mpNext; p != head; p = p->mpNext) {
                Occ3_a8f7f0* occ = OB_PTR(Occ3_a8f7f0, p->mValue & 0xfffffffe);
                if (OB_PTR(Filter_a8f7f0, d) && !OB_PTR(Filter_a8f7f0, d)->Pass_a8f7f0(reinterpret_cast<Occ_a8f7f0*>(occ))) {
                    continue;
                }
                float lo[3];
                float hi[3];
                occ->Bounds_a8f7f0(lo, hi);
                if (lo[0] < hx && lx < hi[0] && lo[2] < hy && ly < hi[2]) {
                    *OB_PTR(Occ3_a8f7f0*, a) = occ;
                    occ->AddRef_a8f7f0();
                    return true;
                }
            }
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0049f240 score 57
bool cSC4OccupantManager::RemoveOccupant(uint32_t a, uint32_t b, uint32_t c)
{
    Occ3_a8f7f0* occ = OB_PTR(Occ3_a8f7f0, a);
    bool ok = false;
    if (occ) {
        occ->AddRef_a8f7f0();
        if (occ->S32_a8f7f0(1)) {
            Lock_a8f7f0* lock = reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14);
            lock->Enter_a8f7f0();
            uint8_t cells[4];
            if (occ->Props_a8f7f0() && occ->Cells_a8f7f0(cells)) {
                for (int32_t x = cells[0]; x <= cells[2]; ++x) {
                    for (int32_t y = cells[1]; y <= cells[3]; ++y) {
                        List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
                        if (l) {
                            Node_a8f7f0* n = EncFind_a8f7f0(l, a);
                            if (n != l->mpHead) {
                                n->mpNext->mpPrev = n->mpPrev;
                                n->mpPrev->mpNext = n->mpNext;
                                Fn0090cf63(n);
                                if (l->mpHead->mpNext == l->mpHead) {
                                    reinterpret_cast<ListD_a8f7f0*>(l)->Fn005650a0();
                                    Fn005e5620(l);
                                    FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y] = 0;
                                }
                            }
                        }
                    }
                }
                ok = true;
            }
            lock->Leave_a8f7f0();
            if (ok) {
                occ->S15_a8f7f0(0x99ef1143, c);
                occ->S31_a8f7f0(1);
                occ->Release_a8f7f0();
            }
        }
    }
    if (b && occ) {
        occ->Slot4_a8f7f0();
    }
    if (occ) {
        occ->Release_a8f7f0();
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0049fb30 score 128
bool cSC4OccupantManager::FindOccupant(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    bool found = false;
    Guard_a8f7f0 guard(reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14));
    int32_t x;
    int32_t y;
    List_a8f7f0* l = static_cast<List_a8f7f0*>(GetOccupantListFor(a, OB_ADDR(&x), OB_ADDR(&y)));
    if (l) {
        found = EncFind_a8f7f0(l, a) != l->mpHead;
        if (found) {
            return true;
        }
    }
    if (b) {
        Col_a8f7f0* cols = FLD_a8f7f0(Col_a8f7f0*, 0x38);
        for (int32_t cx = 0; cx < 0xc0; ++cx) {
            for (int32_t cy = 0; cy < 0xc0; ++cy) {
                List_a8f7f0* cl = cols[cx].mppCells[cy];
                if (cl && EncFind_a8f7f0(cl, a) != cl->mpHead) {
                    if (c) {
                        *OB_PTR(int32_t, c) = cx;
                    }
                    if (d) {
                        *OB_PTR(int32_t, d) = cy;
                    }
                    return true;
                }
            }
        }
    }
    return found;
}
#endif

// ---- wave 11b batch 3 ----
struct OB_NOVTABLE StrmP_a8f7f0 {
    virtual void Pad00_a8f7f0();
    virtual void Pad01_a8f7f0();
    virtual void Pad02_a8f7f0();
    virtual void Pad03_a8f7f0();
    virtual void Pad04_a8f7f0();
    virtual void Pad05_a8f7f0();
    virtual void Pad06_a8f7f0();
    virtual void Put7_a8f7f0(uint32_t v) = 0;
    virtual void Put8_a8f7f0(uint32_t v) = 0;
    virtual void Put9_a8f7f0(uint32_t v) = 0;
    virtual void Pad10_a8f7f0();
    virtual void Pad11_a8f7f0();
    virtual void Put12_a8f7f0(uint32_t v) = 0;
    virtual void Pad13_a8f7f0();
    virtual void Pad14_a8f7f0();
    virtual void Pad15_a8f7f0();
    virtual void Pad16_a8f7f0();
    virtual void Pad17_a8f7f0();
    virtual bool Err_a8f7f0() = 0;
};
struct OB_NOVTABLE StrmQ_a8f7f0 {
    virtual void Pad00_a8f7f0();
    virtual void Pad01_a8f7f0();
    virtual void Pad02_a8f7f0();
    virtual void Pad03_a8f7f0();
    virtual void Pad04_a8f7f0();
    virtual void Pad05_a8f7f0();
    virtual void Pad06_a8f7f0();
    virtual void Get7_a8f7f0(uint16_t* v) = 0;
    virtual void Get8_a8f7f0(void* p) = 0;
    virtual void Get9_a8f7f0(uint32_t* p) = 0;
    virtual void Pad10_a8f7f0();
    virtual void Pad11_a8f7f0();
    virtual void Get12_a8f7f0(void* p) = 0;
    virtual void Pad13_a8f7f0();
    virtual void Pad14_a8f7f0();
    virtual void Pad15_a8f7f0();
    virtual void Pad16_a8f7f0();
    virtual void Pad17_a8f7f0();
    virtual bool Err_a8f7f0() = 0;
};
struct OB_NOVTABLE CbObj_a8f7f0 {
    virtual void Pad00_a8f7f0();
    virtual void Pad01_a8f7f0();
    virtual void Pad02_a8f7f0();
    virtual bool Pass3_a8f7f0(void* occ) = 0;
};

// STUB: 0x0049d900
bool Fn0049d900(void* occ, void* ctx);
// STUB: 0x005d99a0
void Fn005d99a0(void* stream, void* value);
// STUB: 0x005d9730
bool Fn005d9730(void* stream, uint32_t key, void* out, uint32_t flag);
// STUB: 0x005d1290
// STUB: 0x00467b50 is the out-list push-back
struct OutList_a8f7f0 {
    // STUB: 0x00467b50
    void PushBack(uint32_t* occ);
};
// STUB: 0x00413dd0
Node_a8f7f0* OB_STDCALL Fn00413dd0b(uint32_t count, uint32_t hint);

// The set the manager uses to visit an occupant once (it lives at +0x44).
struct HashSet_a8f7f0 {
    // STUB: 0x004a03b0
    bool Insert(uint32_t occ);
    // STUB: 0x004a01c0
    bool Clear();
};

// The base subobject at +4 seen with this = its ecx (the stream methods).
struct Ser_a8f7f0 {
    bool Write(uint32_t stream);
    bool Read(uint32_t stream);
};

// Two boxes (min, max) overlap on all three axes.
inline bool Overlap_a8f7f0(const float* aLo, const float* aHi, const float* bLo, const float* bHi)
{
    return aLo[0] < bHi[0] && bLo[0] < aHi[0] && aLo[1] < bHi[1] && bLo[1] < aHi[1] && aLo[2] < bHi[2] && bLo[2] < aHi[2];
}

#ifdef OB_DRAFTS
// CLOSE: 0x0049ecf0 score 147
bool Ser_a8f7f0::Write(uint32_t stream)
{
    StrmP_a8f7f0* s = OB_PTR(StrmP_a8f7f0, stream);
    s->Put7_a8f7f0(1);
    s->Put12_a8f7f0(FLD_a8f7f0(uint32_t, 0x18));
    s->Put12_a8f7f0(FLD_a8f7f0(uint32_t, 0x1c));
    s->Put8_a8f7f0(FLD_a8f7f0(uint32_t, 0x20));
    s->Put8_a8f7f0(FLD_a8f7f0(uint32_t, 0x24));
    s->Put8_a8f7f0(FLD_a8f7f0(uint32_t, 0x28));
    s->Put8_a8f7f0(FLD_a8f7f0(uint32_t, 0x2c));
    Col_a8f7f0* cols = FLD_a8f7f0(Col_a8f7f0*, 0x34);
    int32_t ncols = (FLD_a8f7f0(char*, 0x38) - reinterpret_cast<char*>(cols)) / 12;
    s->Put9_a8f7f0(ncols);
    for (int32_t x = 0; x < ncols; ++x) {
        int32_t nrows = (reinterpret_cast<uint8_t*>(cols[x].mUnused[0]) - reinterpret_cast<uint8_t*>(cols[x].mppCells)) / 4;
        s->Put9_a8f7f0(nrows);
        for (int32_t y = 0; y < nrows; ++y) {
            List_a8f7f0* l = cols[x].mppCells[y];
            if (l && l->mpHead->mpNext != l->mpHead) {
                int32_t n = 0;
                for (Node_a8f7f0* p = l->mpHead->mpNext; p != l->mpHead; p = p->mpNext) {
                    ++n;
                }
                s->Put9_a8f7f0(n);
                for (Node_a8f7f0* p = l->mpHead->mpNext; p != l->mpHead; p = p->mpNext) {
                    Fn005d99a0(s, reinterpret_cast<void*>(static_cast<uintptr_t>(p->mValue & 0xfffffffe)));
                }
            } else {
                s->Put9_a8f7f0(0);
            }
        }
    }
    return !s->Err_a8f7f0();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004a1a20 score 314
bool Ser_a8f7f0::Read(uint32_t stream)
{
    StrmQ_a8f7f0* s = OB_PTR(StrmQ_a8f7f0, stream);
    FLD_a8f7f0(bool, 0x9) = true;
    uint16_t version;
    s->Get7_a8f7f0(&version);
    if (version != 1) {
        return false;
    }
    s->Get12_a8f7f0(&FLD_a8f7f0(uint8_t, 0x18));
    s->Get12_a8f7f0(&FLD_a8f7f0(uint8_t, 0x1c));
    s->Get8_a8f7f0(&FLD_a8f7f0(uint8_t, 0x20));
    s->Get8_a8f7f0(&FLD_a8f7f0(uint8_t, 0x24));
    s->Get8_a8f7f0(&FLD_a8f7f0(uint8_t, 0x28));
    s->Get8_a8f7f0(&FLD_a8f7f0(uint8_t, 0x2c));
    uint32_t ncols;
    s->Get9_a8f7f0(&ncols);
    for (uint32_t x = 0; x < ncols; ++x) {
        uint32_t nrows;
        s->Get9_a8f7f0(&nrows);
        for (uint32_t y = 0; y < nrows; ++y) {
            uint32_t n;
            s->Get9_a8f7f0(&n);
            if (n) {
                for (uint32_t k = 0; k < n; ++k) {
                    uint32_t occ = 0;
                    Fn005d9730(s, 0x26bb767e, &occ, 0);
                    if (occ) {
                        reinterpret_cast<HashSet_a8f7f0*>(&FLD_a8f7f0(uint8_t, 0x40))->Insert(occ);
                    }
                }
            }
        }
    }
    FLD_a8f7f0(uint32_t, 0x40) = 0;
    FLD_a8f7f0(uint32_t, 0x44) = 0;
    return !s->Err_a8f7f0();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004a18e0 score 114
bool cSC4OccupantManager::Init()
{
    Guard_a8f7f0 guard(reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14));
    if (!FLD_a8f7f0(bool, 0xc)) {
        FLD_a8f7f0(bool, 0xc) = true;
        if (!FLD_a8f7f0(uint32_t, 0x34)) {
            FLD_a8f7f0(Rel_a8f7f0*, 0x34) = static_cast<Rel_a8f7f0*>(Fn005e55e0(0x10));
        }
        Col_a8f7f0* cols = FLD_a8f7f0(Col_a8f7f0*, 0x38);
        if (FLD_a8f7f0(Col_a8f7f0*, 0x38) == FLD_a8f7f0(Col_a8f7f0*, 0x3c)) {
            (void)cols;
        } else {
            IterateOccupants(OB_ADDR(Fn0049d900), OB_ADDR(this), 0, 0, 0);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0049f3c0 score 580
bool cSC4OccupantManager::MoveOccupant(uint32_t a, uint32_t b)
{
    Occ3_a8f7f0* occ = OB_PTR(Occ3_a8f7f0, a);
    if (!occ || !occ->S32_a8f7f0(1)) {
        return false;
    }
    Lock_a8f7f0* lock = reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14);
    lock->Enter_a8f7f0();
    bool ok;
    uint8_t old[4];
    if (!occ->Props_a8f7f0() || !occ->Cells_a8f7f0(old)) {
        ok = false;
    } else {
        float lo[3];
        float hi[3];
        occ->Bounds_a8f7f0(lo, hi);
        if (1.0f < hi[0] - lo[0]) {
            lo[0] = lo[0] + 0.1f;
            hi[0] = hi[0] - 0.1f;
        }
        if (1.0f < hi[2] - lo[2]) {
            lo[2] = lo[2] + 0.1f;
            hi[2] = hi[2] - 0.1f;
        }
        int32_t cx;
        int32_t cy;
        uint8_t nw[4];
        PositionToWorldCell(*reinterpret_cast<uint32_t*>(&lo[0]), *reinterpret_cast<uint32_t*>(&lo[2]), OB_ADDR(&cx), OB_ADDR(&cy));
        nw[0] = static_cast<uint8_t>(cx);
        nw[1] = static_cast<uint8_t>(cy);
        PositionToWorldCell(*reinterpret_cast<uint32_t*>(&hi[0]), *reinterpret_cast<uint32_t*>(&hi[2]), OB_ADDR(&cx), OB_ADDR(&cy));
        nw[2] = static_cast<uint8_t>(cx);
        nw[3] = static_cast<uint8_t>(cy);
        occ->SetCells_a8f7f0(nw);
        if (old[0] != nw[0] || old[1] != nw[1] || old[2] != nw[2] || old[3] != nw[3]) {
            uint32_t oldFlag = (old[0] < old[2] || old[1] < old[3]) ? 0 : 1;
            for (int32_t x = old[0]; x <= old[2]; ++x) {
                for (int32_t y = old[1]; y <= old[3]; ++y) {
                    if (x < nw[0] || nw[2] < x || y < nw[1] || nw[3] < y) {
                        List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
                        Node_a8f7f0* n = EncFind_a8f7f0(l, a);
                        if (n != l->mpHead) {
                            n->mpNext->mpPrev = n->mpPrev;
                            n->mpPrev->mpNext = n->mpNext;
                            Fn0090cf63(n);
                            if (l->mpHead->mpNext == l->mpHead) {
                                reinterpret_cast<ListD_a8f7f0*>(l)->Fn005650a0();
                                Fn005e5620(l);
                                FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y] = 0;
                            }
                        }
                    }
                }
            }
            uint32_t newFlag = (nw[0] < nw[2] || nw[1] < nw[3]) ? 0 : 1;
            uint32_t enc = a + newFlag;
            for (int32_t x = nw[0]; x <= nw[2]; ++x) {
                for (int32_t y = nw[1]; y <= nw[3]; ++y) {
                    if (x < old[0] || old[2] < x || y < old[1] || old[3] < y) {
                        List_a8f7f0* l = static_cast<List_a8f7f0*>(GetOccupantList(x, y, true));
                        reinterpret_cast<OutList_a8f7f0*>(l)->PushBack(&enc);
                    }
                }
            }
            if (a + oldFlag != enc) {
                int32_t x0 = nw[0] < old[0] ? old[0] : nw[0];
                int32_t y0 = nw[1] < old[1] ? old[1] : nw[1];
                int32_t x1 = nw[2] < old[2] ? nw[2] : old[2];
                int32_t y1 = nw[3] < old[3] ? nw[3] : old[3];
                for (int32_t x = x0; x <= x1; ++x) {
                    for (int32_t y = y0; y <= y1; ++y) {
                        List_a8f7f0* l = static_cast<List_a8f7f0*>(GetOccupantList(x, y, true));
                        Node_a8f7f0* n = EncFind_a8f7f0(l, a);
                        if (n != l->mpHead) {
                            n->mValue = enc;
                        }
                    }
                }
            }
        }
        ok = true;
    }
    lock->Leave_a8f7f0();
    if (ok) {
        if (b) {
            occ->S15_a8f7f0(0x99ef1146, 0);
        }
        return true;
    }
    return false;
}
#endif


#ifdef OB_DRAFTS
// CLOSE: 0x0049ef60 score 298
bool cSC4OccupantManager::Slot20_a8f7f0(uint32_t a)
{
    Occ3_a8f7f0* occ = OB_PTR(Occ3_a8f7f0, a);
    bool added = false;
    if (occ && !occ->S32_a8f7f0(1)) {
        Lock_a8f7f0* lock = reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14);
        lock->Enter_a8f7f0();
        occ->AddRef_a8f7f0();
        occ->Slot4_a8f7f0();
        if (occ->Props_a8f7f0()) {
            float lo[3];
            float hi[3];
            occ->Bounds_a8f7f0(lo, hi);
            if (1.0f < hi[0] - lo[0]) {
                lo[0] = lo[0] + 0.1f;
                hi[0] = hi[0] - 0.1f;
            }
            if (1.0f < hi[2] - lo[2]) {
                lo[2] = lo[2] + 0.1f;
                hi[2] = hi[2] - 0.1f;
            }
            int32_t cx;
            int32_t cy;
            uint8_t cells[4];
            PositionToWorldCell(*reinterpret_cast<uint32_t*>(&lo[0]), *reinterpret_cast<uint32_t*>(&lo[2]), OB_ADDR(&cx), OB_ADDR(&cy));
            cells[0] = static_cast<uint8_t>(cx);
            cells[1] = static_cast<uint8_t>(cy);
            Fn0049dac0(*reinterpret_cast<uint32_t*>(&hi[0]), *reinterpret_cast<uint32_t*>(&hi[2]), OB_ADDR(&cells[2]), OB_ADDR(&cells[3]));
            occ->SetCells_a8f7f0(cells);
            uint32_t flag = (cells[0] < cells[2] || cells[1] < cells[3]) ? 0 : 1;
            uint32_t enc = a + flag;
            for (int32_t x = cells[0]; x <= cells[2]; ++x) {
                for (int32_t y = cells[1]; y <= cells[3]; ++y) {
                    List_a8f7f0* l = static_cast<List_a8f7f0*>(GetOccupantList(x, y, true));
                    if (l) {
                        reinterpret_cast<OutList_a8f7f0*>(l)->PushBack(&enc);
                    }
                }
            }
            added = true;
        }
        lock->Leave_a8f7f0();
    }
    return added;
}
#endif

// ---- wave 11b batch 4 ----
// The occupant filter and the callback shape used by the iterate methods.
struct OB_NOVTABLE Flt2_a8f7f0 {
    virtual void Pad00_a8f7f0(); virtual void Pad01_a8f7f0(); virtual void Pad02_a8f7f0();
    virtual bool Pass_a8f7f0(void* occ) = 0;
};
typedef bool (*Visit_a8f7f0)(void* occ, void* ctx);

// STUB: 0x0049fa80
// STUB: 0x0049f8a0
// The occupant set a visiting method builds on its stack (a hash set of occupants).
struct LocalSet_a8f7f0 {
    uint8_t mData[0x5c];
    // STUB: 0x0049fa80
    LocalSet_a8f7f0();
    // STUB: 0x0049f8a0
    ~LocalSet_a8f7f0();
    // STUB: 0x004a03b0
    bool Insert(uint32_t occ);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004a0670 score 422
bool cSC4OccupantManager::GetOccupantsByBBox(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Guard_a8f7f0 guard(reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14));
    if (!FLD_a8f7f0(bool, 0xc) || e == 0) {
        return false;
    }
    float lo[3];
    float hi[3];
    if (b) {
        lo[0] = OB_PTR(float, b)[0];
        lo[1] = OB_PTR(float, b)[1];
        lo[2] = OB_PTR(float, b)[2];
    } else {
        lo[0] = 0.0f;
        lo[1] = -3.4028235e+38f;
        lo[2] = 0.0f;
    }
    if (c) {
        hi[0] = OB_PTR(float, c)[0];
        hi[1] = OB_PTR(float, c)[1];
        hi[2] = OB_PTR(float, c)[2];
    } else {
        hi[0] = FLD_a8f7f0(float, 0x1c);
        hi[1] = 3.4028235e+38f;
        hi[2] = FLD_a8f7f0(float, 0x20);
    }
    int32_t x0;
    int32_t y0;
    int32_t x1;
    int32_t y1;
    PositionToWorldCell(*reinterpret_cast<uint32_t*>(&lo[0]), *reinterpret_cast<uint32_t*>(&lo[2]), OB_ADDR(&x0), OB_ADDR(&y0));
    PositionToWorldCell(*reinterpret_cast<uint32_t*>(&hi[0]), *reinterpret_cast<uint32_t*>(&hi[2]), OB_ADDR(&x1), OB_ADDR(&y1));
    Fn0049df00(&x0, &y0, &x1, &y1);
    uint32_t count = 0;
    bool single = x0 == x1 && y0 == y1;
    for (int32_t x = x0; x <= x1; ++x) {
        for (int32_t y = y0; y <= y1; ++y) {
            List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
            if (!l) {
                continue;
            }
            for (Node_a8f7f0* p = l->mpHead->mpNext; p != l->mpHead; p = p->mpNext) {
                uint32_t occ = p->mValue & 0xfffffffe;
                if (!single && !(p->mValue & 1) && !reinterpret_cast<HashSet_a8f7f0*>(&FLD_a8f7f0(uint8_t, 0x44))->Insert(occ)) {
                    continue;
                }
                if (d && !OB_PTR(Flt2_a8f7f0, d)->Pass_a8f7f0(OB_PTR(void, occ))) {
                    continue;
                }
                float olo[3];
                float ohi[3];
                OB_PTR(Occ3_a8f7f0, occ)->Bounds_a8f7f0(olo, ohi);
                if (Overlap_a8f7f0(lo, hi, olo, ohi)) {
                    OB_PTR(Occ3_a8f7f0, occ)->AddRef_a8f7f0();
                    reinterpret_cast<OutList_a8f7f0*>(OB_PTR(void, a))->PushBack(&occ);
                    ++count;
                    if (count >= e) {
                        x = x1 + 1;
                        y = y1 + 1;
                        break;
                    }
                }
            }
        }
    }
    if (!single) {
        reinterpret_cast<HashSet_a8f7f0*>(&FLD_a8f7f0(uint8_t, 0x44))->Clear();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004a0a70 score 360
bool cSC4OccupantManager::GetOccupantsByOccupantManagerCells(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Guard_a8f7f0 guard(reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14));
    if (!FLD_a8f7f0(bool, 0xc) || e == 0) {
        return false;
    }
    int32_t x0 = b ? OB_PTR(int32_t, b)[0] + 0x40 : 0x40;
    int32_t y0 = b ? OB_PTR(int32_t, b)[1] + 0x40 : 0x40;
    int32_t x1 = c ? OB_PTR(int32_t, c)[0] + 0x40 : FLD_a8f7f0(int32_t, 0x24) + 0x3f;
    int32_t y1 = c ? OB_PTR(int32_t, c)[1] + 0x40 : FLD_a8f7f0(int32_t, 0x28) + 0x3f;
    Fn0049df00(&x0, &y0, &x1, &y1);
    uint32_t count = 0;
    for (int32_t x = x0; x <= x1; ++x) {
        for (int32_t y = y0; y <= y1; ++y) {
            List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
            if (!l) {
                continue;
            }
            for (Node_a8f7f0* p = l->mpHead->mpNext; p != l->mpHead; p = p->mpNext) {
                uint32_t occ = p->mValue & 0xfffffffe;
                if (!(p->mValue & 1) && !reinterpret_cast<HashSet_a8f7f0*>(&FLD_a8f7f0(uint8_t, 0x44))->Insert(occ)) {
                    continue;
                }
                if (d && !OB_PTR(Flt2_a8f7f0, d)->Pass_a8f7f0(OB_PTR(void, occ))) {
                    continue;
                }
                OB_PTR(Occ3_a8f7f0, occ)->AddRef_a8f7f0();
                reinterpret_cast<OutList_a8f7f0*>(OB_PTR(void, a))->PushBack(&occ);
                ++count;
                if (count >= e) {
                    reinterpret_cast<HashSet_a8f7f0*>(&FLD_a8f7f0(uint8_t, 0x44))->Clear();
                    return true;
                }
            }
        }
    }
    reinterpret_cast<HashSet_a8f7f0*>(&FLD_a8f7f0(uint8_t, 0x44))->Clear();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004a0d70 score 575
bool cSC4OccupantManager::Slot42_a8f7f0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Guard_a8f7f0 guard(reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14));
    if (!FLD_a8f7f0(bool, 0xc)) {
        return false;
    }
    float lo[3];
    float hi[3];
    if (c) {
        lo[0] = OB_PTR(float, c)[0];
        lo[1] = OB_PTR(float, c)[1];
        lo[2] = OB_PTR(float, c)[2];
    } else {
        lo[0] = 0.0f;
        lo[1] = -3.4028235e+38f;
        lo[2] = 0.0f;
    }
    if (d) {
        hi[0] = OB_PTR(float, d)[0];
        hi[1] = OB_PTR(float, d)[1];
        hi[2] = OB_PTR(float, d)[2];
    } else {
        hi[0] = FLD_a8f7f0(float, 0x1c);
        hi[1] = 3.4028235e+38f;
        hi[2] = FLD_a8f7f0(float, 0x20);
    }
    int32_t x0;
    int32_t y0;
    int32_t x1;
    int32_t y1;
    PositionToWorldCell(*reinterpret_cast<uint32_t*>(&lo[0]), *reinterpret_cast<uint32_t*>(&lo[2]), OB_ADDR(&x0), OB_ADDR(&y0));
    PositionToWorldCell(*reinterpret_cast<uint32_t*>(&hi[0]), *reinterpret_cast<uint32_t*>(&hi[2]), OB_ADDR(&x1), OB_ADDR(&y1));
    Fn0049df00(&x0, &y0, &x1, &y1);
    LocalSet_a8f7f0 seen;
    for (int32_t x = x0; x <= x1; ++x) {
        for (int32_t y = y0; y <= y1; ++y) {
            List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
            if (!l) {
                continue;
            }
            for (Node_a8f7f0* p = l->mpHead->mpNext; p != l->mpHead; p = p->mpNext) {
                uint32_t occ = p->mValue & 0xfffffffe;
                if (!(p->mValue & 1) && !seen.Insert(occ)) {
                    continue;
                }
                float olo[3];
                float ohi[3];
                OB_PTR(Occ3_a8f7f0, occ)->Bounds_a8f7f0(olo, ohi);
                if (Overlap_a8f7f0(lo, hi, olo, ohi)) {
                    if (e && !OB_PTR(Flt2_a8f7f0, e)->Pass_a8f7f0(OB_PTR(void, occ))) {
                        continue;
                    }
                    if (!reinterpret_cast<Visit_a8f7f0>(static_cast<uintptr_t>(a))(OB_PTR(void, occ), OB_PTR(void, b))) {
                        return true;
                    }
                }
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004a1360 score 510
bool cSC4OccupantManager::IterateOccupants(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Guard_a8f7f0 guard(reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14));
    if (!FLD_a8f7f0(bool, 0xc)) {
        return false;
    }
    int32_t x0 = c ? OB_PTR(int32_t, c)[0] + 0x40 : 0x40;
    int32_t y0 = c ? OB_PTR(int32_t, c)[1] + 0x40 : 0x40;
    int32_t x1 = d ? OB_PTR(int32_t, d)[0] + 0x40 : FLD_a8f7f0(int32_t, 0x24) + 0x3f;
    int32_t y1 = d ? OB_PTR(int32_t, d)[1] + 0x40 : FLD_a8f7f0(int32_t, 0x28) + 0x3f;
    Fn0049df00(&x0, &y0, &x1, &y1);
    LocalSet_a8f7f0 seen;
    for (int32_t x = x0; x <= x1; ++x) {
        for (int32_t y = y0; y <= y1; ++y) {
            List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
            if (!l) {
                continue;
            }
            for (Node_a8f7f0* p = l->mpHead->mpNext; p != l->mpHead; p = p->mpNext) {
                uint32_t occ = p->mValue & 0xfffffffe;
                if (!(p->mValue & 1) && !seen.Insert(occ)) {
                    continue;
                }
                if (e && !OB_PTR(Flt2_a8f7f0, e)->Pass_a8f7f0(OB_PTR(void, occ))) {
                    continue;
                }
                if (!reinterpret_cast<Visit_a8f7f0>(static_cast<uintptr_t>(a))(OB_PTR(void, occ), OB_PTR(void, b))) {
                    return true;
                }
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0049fcd0 score 493
void cSC4OccupantManager::Slot22_a8f7f0(uint32_t a, uint32_t b, uint32_t c)
{
    Lock_a8f7f0* lock = reinterpret_cast<Lock_a8f7f0*>(reinterpret_cast<char*>(this) + 0x14);
    lock->Enter_a8f7f0();
    uint32_t* picked = 0;
    uint32_t pickedCount = 0;
    uint32_t pickedCap = 0;
    for (int32_t x = 0; x < 0xc0; ++x) {
        for (int32_t y = 0; y < 0xc0; ++y) {
            List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
            if (!l) {
                continue;
            }
            for (Node_a8f7f0* p = l->mpHead->mpNext; p != l->mpHead; p = p->mpNext) {
                uint32_t occ = p->mValue & 0xfffffffe;
                if (a && !OB_PTR(Flt2_a8f7f0, a)->Pass_a8f7f0(OB_PTR(void, occ))) {
                    continue;
                }
                if (pickedCount == pickedCap) {
                    uint32_t ncap = pickedCap ? pickedCap * 2 : 1;
                    uint32_t* grown = static_cast<uint32_t*>(Fn005e55e0(ncap * 4));
                    for (uint32_t i = 0; i < pickedCount; ++i) {
                        grown[i] = picked[i];
                    }
                    if (picked) {
                        Fn0090cf63(picked);
                    }
                    picked = grown;
                    pickedCap = ncap;
                }
                picked[pickedCount++] = occ;
            }
        }
    }
    for (uint32_t i = 0; i < pickedCount; ++i) {
        Occ3_a8f7f0* occ = OB_PTR(Occ3_a8f7f0, picked[i]);
        uint8_t cells[4];
        if (occ->Props_a8f7f0() && occ->Cells_a8f7f0(cells)) {
            for (int32_t x = cells[0]; x <= cells[2]; ++x) {
                for (int32_t y = cells[1]; y <= cells[3]; ++y) {
                    List_a8f7f0* l = FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y];
                    if (l) {
                        Node_a8f7f0* n = EncFind_a8f7f0(l, picked[i]);
                        if (n != l->mpHead) {
                            n->mpNext->mpPrev = n->mpPrev;
                            n->mpPrev->mpNext = n->mpNext;
                            Fn0090cf63(n);
                            if (l->mpHead->mpNext == l->mpHead) {
                                Fn0090cf63(l->mpHead);
                                Fn005e5620(l);
                                FLD_a8f7f0(Col_a8f7f0*, 0x38)[x].mppCells[y] = 0;
                            }
                        }
                    }
                }
            }
        }
        if (b) {
            occ->S31_a8f7f0(1);
        }
        occ->Release_a8f7f0();
    }
    if (picked) {
        Fn0090cf63(picked);
    }
    lock->Leave_a8f7f0();
}
#endif

// ---- the hash set the visiting methods use (STL-shaped internals; rough drafts) ----
struct Bucket_a8f7f0 {
    Bucket_a8f7f0* mpNext;
    uint32_t mKey;
};

// The set object: bucket count / element count, a bucket vector at +8, a spare vector at +0x14, a node deque at +0x20.
struct HashImpl_a8f7f0 {
    uint32_t mCount;
    uint32_t mSize;
    Bucket_a8f7f0** mpBuckets;
    Bucket_a8f7f0** mpBucketsEnd;
    Bucket_a8f7f0** mpBucketsCap;
    uint32_t* mpSpare;
    uint32_t* mpSpareEnd;
    uint32_t* mpSpareCap;
    uint32_t mDeque[0x10];
    // STUB: 0x0049fc70
    void ResizeBuckets(uint32_t n, Bucket_a8f7f0** fill);
    // STUB: 0x004696c0
    uint32_t* FindLinear(uint32_t* first, uint32_t* last, const uint32_t* key);
    // STUB: 0x0051ca60
    void InsertOverflow(uint32_t* where, const uint32_t* v, uint32_t n);
    // STUB: 0x0049eb90
    void InitMap(uint32_t n);
    bool Fn004a01c0Draft_a8f7f0();
    bool Fn004a03b0Draft_a8f7f0(uint32_t key);
    HashImpl_a8f7f0* Fn0049fa80Draft_a8f7f0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x004a01c0 score 87
bool HashImpl_a8f7f0::Fn004a01c0Draft_a8f7f0()
{
    Bucket_a8f7f0** b0 = mpBuckets;
    mpBuckets = reinterpret_cast<Bucket_a8f7f0**>(mpSpare);
    mpSpare = reinterpret_cast<uint32_t*>(b0);
    Bucket_a8f7f0** b1 = mpBucketsEnd;
    mpBucketsEnd = reinterpret_cast<Bucket_a8f7f0**>(mpSpareEnd);
    mpSpareEnd = reinterpret_cast<uint32_t*>(b1);
    Bucket_a8f7f0** b2 = mpBucketsCap;
    mpBucketsCap = reinterpret_cast<Bucket_a8f7f0**>(mpSpareCap);
    mpSpareCap = reinterpret_cast<uint32_t*>(b2);
    Bucket_a8f7f0* zero = 0;
    ResizeBuckets(0x11, &zero);
    for (Bucket_a8f7f0** p = mpBuckets; p != mpBucketsEnd; ++p) {
        *p = 0;
    }
    for (uint32_t* p = mpSpare; p != mpSpareEnd; ++p) {
        uint32_t key = *p;
        uint32_t slot = key % mCount;
        Bucket_a8f7f0* node = new Bucket_a8f7f0;
        node->mpNext = mpBuckets[slot];
        node->mKey = key;
        mpBuckets[slot] = node;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004a03b0 score 172
bool HashImpl_a8f7f0::Fn004a03b0Draft_a8f7f0(uint32_t key)
{
    if (mCount < 0x11) {
        uint32_t* found = FindLinear(mpBuckets ? reinterpret_cast<uint32_t*>(mpBuckets) : 0, reinterpret_cast<uint32_t*>(mpBucketsEnd), &key);
        if (found != reinterpret_cast<uint32_t*>(mpBucketsEnd)) {
            return false;
        }
        if (mpBucketsEnd != mpBucketsCap) {
            *reinterpret_cast<uint32_t*>(mpBucketsEnd) = key;
            ++mpBucketsEnd;
        } else {
            InsertOverflow(reinterpret_cast<uint32_t*>(mpBucketsEnd), &key, 1);
        }
        ++mCount;
        if (mCount >= 0x11) {
            Fn004a01c0Draft_a8f7f0();
        }
        return true;
    }
    uint32_t slot = key % mCount;
    for (Bucket_a8f7f0* n = mpBuckets[slot]; n; n = n->mpNext) {
        if (n->mKey == key) {
            return false;
        }
    }
    Bucket_a8f7f0* node = new Bucket_a8f7f0;
    node->mpNext = mpBuckets[slot];
    node->mKey = key;
    mpBuckets[slot] = node;
    ++mSize;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0049fa80 score 41
HashImpl_a8f7f0* HashImpl_a8f7f0::Fn0049fa80Draft_a8f7f0()
{
    mCount = 0;
    mSize = 0;
    mpBuckets = 0;
    mpBucketsEnd = 0;
    mpBucketsCap = 0;
    mpSpare = 0;
    mpSpareEnd = 0;
    mpSpareCap = 0;
    for (uint32_t i = 0; i < 0x10; ++i) {
        mDeque[i] = 0;
    }
    InitMap(0x12);
    return this;
}
#endif

// The node deque of the set: sixteen records per node, filled with one value.
struct DequeV_a8f7f0 {
    uint32_t* mpMapBegin;
    uint32_t* mpMapEnd;
    uint32_t* mpFirst;
    uint32_t* mpStart;
    uint32_t* mpStartLast;
    uint32_t* mpFinish;
    void Fn0049ec50Draft_a8f7f0(const uint32_t* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0049ec50 score 65
void DequeV_a8f7f0::Fn0049ec50Draft_a8f7f0(const uint32_t* v)
{
    uint32_t** node = reinterpret_cast<uint32_t**>(mpMapBegin);
    for (; node < reinterpret_cast<uint32_t**>(mpMapEnd); ++node) {
        for (uint32_t* p = *node; p != *node + 0x20; p += 2) {
            if (p) {
                p[0] = v[0];
                p[1] = v[1];
            }
        }
    }
    for (uint32_t* p = mpStartLast; p != mpFinish; p += 2) {
        if (p) {
            p[0] = v[0];
            p[1] = v[1];
        }
    }
}
#endif


// A position in the node deque: the current record, its node's bounds and the node's slot in the map.
struct DIt_a8f7f0 {
    uint32_t* mpCur;
    uint32_t* mpFirst;
    uint32_t* mpLast;
    uint32_t** mppNode;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0049ecc0 score 12
void Fn0049ecc0Draft_a8f7f0(DIt_a8f7f0 a, DIt_a8f7f0 b)
{
    uint32_t* cur = a.mpCur;
    while (cur != b.mpCur) {
        cur += 2;
        if (cur == a.mpLast) {
            ++a.mppNode;
            cur = *a.mppNode;
            a.mpLast = cur + 0x20;
        }
    }
}
#endif

// The deque's own storage: iterators for the first and the last record, then the map.
struct DequeD_a8f7f0 {
    DIt_a8f7f0 mStart;
    DIt_a8f7f0 mFinish;
    uint32_t* mpMap;
    // STUB: 0x006da8d0
    void DestroyNodes(uint32_t** first, uint32_t** last);
    void Fn0049f8a0Draft_a8f7f0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0049f8a0 score 62
void DequeD_a8f7f0::Fn0049f8a0Draft_a8f7f0()
{
    DIt_a8f7f0 a = mStart;
    DIt_a8f7f0 b = mFinish;
    Fn0049ecc0Draft_a8f7f0(a, b);
    if (mpMap) {
        DestroyNodes(mStart.mppNode, mFinish.mppNode + 1);
        Fn0090cf63(mpMap);
    }
}
#endif
