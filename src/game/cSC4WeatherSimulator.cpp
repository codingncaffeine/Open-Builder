#include "classes/cSC4WeatherSimulator.h"
#include "game/Globals.h"
#include "gzcom/cRZString.h"
#include <string.h>

// The simulator seen from the city's clock: only the date it hands out is used.
struct Date_ab3610 {
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
    virtual uint32_t GetMonth();
};

struct Unknown_ab3610 {
    virtual bool QueryInterface(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

struct Simulator_ab3610 : Unknown_ab3610 {
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual Date_ab3610* GetSimDate2();
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
    virtual void AddAgent(void* agent, uint32_t kind, void* name, uint32_t flags);
    virtual void RemoveAgent1(void* agent);
};

// A grid of columns kept as the standard vectors keep them (begin, end, capacity).
struct Column_ab3610 {
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    uint8_t* mpCap;
};

struct Columns_ab3610 {
    Column_ab3610* mpBegin;
    Column_ab3610* mpEnd;
    Column_ab3610* mpCap;
};

// FUNCTION: 0x007255c0
void cSC4WeatherSimulator::PositionToCell(float x, float z, void* pCellX, void* pCellZ)
{
    *static_cast<int32_t*>(pCellX) = static_cast<int32_t>(x / mfCellW);
    *static_cast<int32_t*>(pCellZ) = static_cast<int32_t>(z / mfCellH);
}

// FUNCTION: 0x007255f0
void cSC4WeatherSimulator::CellToPosition(int32_t cellX, int32_t cellZ, void* pX, void* pZ)
{
    *static_cast<float*>(pX) = cellX * mfCellW;
    *static_cast<float*>(pZ) = cellZ * mfCellH;
}

// FUNCTION: 0x00725610
void cSC4WeatherSimulator::CellToStandardCityCell(int32_t cellX, int32_t /*cellZ*/, void* pX, void* pZ)
{
    *static_cast<int32_t*>(pX) = mnStdCellX * cellX;
    *static_cast<int32_t*>(pZ) = mnStdCellZ * cellX;
}

// FUNCTION: 0x00725640
void cSC4WeatherSimulator::StandardCityCellToCell(int32_t cellX, int32_t cellZ, void* pX, void* pZ)
{
    *static_cast<int32_t*>(pX) = cellX / mnStdCellX;
    *static_cast<int32_t*>(pZ) = cellZ / mnStdCellZ;
}

// FUNCTION: 0x00725660
uint32_t cSC4WeatherSimulator::GetCurrentSeason()
{
    return (static_cast<int32_t>(GetCurrentSeasonMonth()) - 1) / 3;
}

// FUNCTION: 0x00725680
uint32_t cSC4WeatherSimulator::GetCurrentSeasonMonth()
{
    uint32_t hemisphere = static_cast<cISC4City*>(mpCity)->GetWorldHemisphere();
    int32_t month = static_cast<Simulator_ab3610*>(mpSimulator)->GetSimDate2()->GetMonth();
    if (hemisphere != 1) {
        month = (month + 5) % 12 + 1;
    }
    return month;
}

// FUNCTION: 0x007256c0
void cSC4WeatherSimulator::GetMoistureValueMapPtr(void* pMap)
{
    *static_cast<void**>(pMap) = &mGridMoisture;
}

// FUNCTION: 0x007256d0
uint32_t cSC4WeatherSimulator::GetMoistureType(float x, float z)
{
    return GetMoistureValue(x, z) >> 4;
}

// FUNCTION: 0x007256f0
float cSC4WeatherSimulator::GetHumidity(float /*x*/, float /*z*/)
{
    return mfF8 + (1.0f - mfF8) * 0.5f;
}

// FUNCTION: 0x00725710
float cSC4WeatherSimulator::GetWindAtCell(int32_t /*cellX*/, int32_t /*cellZ*/, void* pWind)
{
    return GetAmbientWind(pWind);
}

// STUB: 0x005d76d0
void ScaleVector2D_ab3610(float* vector, float factor);

// FUNCTION: 0x00725a00
float cSC4WeatherSimulator::GetAmbientWind(void* pWind)
{
    float speed = mfWindSpeed;
    float* out = static_cast<float*>(pWind);
    if (out) {
        out[0] = mfWindX;
        out[1] = mfWindZ;
        ScaleVector2D_ab3610(out, speed);
    }
    return speed;
}

// FUNCTION: 0x00725a40
uint32_t cSC4WeatherSimulator::Slot02_ab3610()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Shutdown();
    delete this;
    return 0;
}

// The interface subobject at an offset of the object; a null object stays null, as the base-class conversion does.
inline void* SubObject_ab3610(cSC4WeatherSimulator* self, uint32_t offset)
{
    return self ? reinterpret_cast<char*>(self) + offset : 0;
}

// FUNCTION: 0x00725720
bool cSC4WeatherSimulator::QueryInterface(uint32_t riid, void* ppv)
{
    void** out = static_cast<void**>(ppv);
    switch (riid) {
    case 0xc6c66245:
    case 1:
        *out = this;
        Slot01_ab3610();
        return true;
    case 0x452294aa:
        *out = SubObject_ab3610(this, 8);
        Slot01_ab3610();
        return true;
    case 0xe98b2f57:
        *out = SubObject_ab3610(this, 4);
        Slot01_ab3610();
        return true;
    case 0xe4fda3d4:
        *out = SubObject_ab3610(this, 0xc);
        Slot01_ab3610();
        return true;
    }
    return false;
}

// FUNCTION: 0x00725940
bool cSC4WeatherSimulator::Shutdown()
{
    if (mbInitialized) {
        if (mpTerrain) {
            static_cast<Unknown_ab3610*>(mpTerrain)->Release();
            mpTerrain = 0;
        }
        if (mpSimulator) {
            static_cast<Simulator_ab3610*>(mpSimulator)->RemoveAgent1(reinterpret_cast<char*>(this) + 8);
            static_cast<Simulator_ab3610*>(mpSimulator)->Release();
            mpSimulator = 0;
        }
        if (mpCity) {
            static_cast<Unknown_ab3610*>(mpCity)->Release();
            mpCity = 0;
        }
        if (gpB43ccc) {
            gpB43ccc->RemoveNotification(reinterpret_cast<char*>(this) + 8, 0x26d31ec1);
        }
        mbInitialized = false;
    }
    return true;
}

// FUNCTION: 0x007296f0
bool cSC4WeatherSimulator::DoPostCityInit()
{
    if (!mbPostInitDone) {
        Fn00729630(1, 0);
        while (!Fn00728a40(0, 0)) {
        }
        mbPostInitDone = true;
    }
    return true;
}

// FUNCTION: 0x00727f90
void cSC4WeatherSimulator::UpdateMoisture(void* pRect)
{
    if (mpTerrain) {
        const int32_t* rect = static_cast<const int32_t*>(pRect);
        int32_t cells[4];
        cells[0] = rect[0] / 16;
        cells[1] = rect[1] / 16;
        cells[2] = (rect[2] + 15) / 16;
        cells[3] = (rect[3] + 15) / 16;
        Fn00726bf0(cells);
    }
}

// The float's integer floor through the rounding trick: the sum with 1.5 * 2^23 leaves the rounded value in the
// low mantissa bits.
inline int32_t Floor_ab3610(float value)
{
    union {
        float f;
        int32_t i;
    } bits;
    bits.f = value - 0.5f + 12582912.0f;
    int32_t result = bits.i - 0x4b400000;
    bits.i = result + 1;
    if (value == static_cast<float>(bits.i)) {
        result = bits.i;
    }
    return result;
}

// FUNCTION: 0x00726150
uint32_t cSC4WeatherSimulator::GetMoistureValue(float x, float z)
{
    if (mbInitialized) {
        if (x < 0.0f) {
            x = 0.0f;
        } else if (x >= mfSizeX) {
            x = mfSizeX - 1.0f;
        }
        if (z < 0.0f) {
            z = 0.0f;
        } else if (z >= mfSizeZ) {
            z = mfSizeZ - 1.0f;
        }
        int32_t column = Floor_ab3610(x * mfInvW);
        int32_t row = Floor_ab3610(z * mfInvH);
        return reinterpret_cast<Columns_ab3610*>(mGridMoisture)->mpBegin[column].mpBegin[row];
    }
    return 0;
}

// FUNCTION: 0x00726250
void cSC4WeatherSimulator::Slot20_ab3610(float x0, float z0, float x1, float z1, float amount)
{
    float level = amount;
    if (amount < 0.0f) {
        level = 0.0f;
    } else if (amount > 255.0f) {
        level = 255.0f;
    }
    union {
        float f;
        uint8_t b[4];
    } scaled;
    scaled.f = level * 1.275f + 12582912.0f;
    int32_t beginX = static_cast<int32_t>(x0 * mfInvW);
    int32_t beginZ = static_cast<int32_t>(z0 * mfInvH);
    int32_t endX = static_cast<int32_t>(x1 * mfInvW);
    int32_t endZ = static_cast<int32_t>(z1 * mfInvH);
    if (beginX < 0) {
        beginX = 0;
    } else if (endX >= mnCellsX) {
        endX = mnCellsX - 1;
    }
    if (beginZ < 0) {
        beginZ = 0;
    } else if (endZ >= mnCellsZ) {
        endZ = mnCellsZ - 1;
    }
    for (int32_t x = beginX; x < endX; ++x) {
        for (int32_t z = beginZ; z < endZ; ++z) {
            reinterpret_cast<Columns_ab3610*>(mGridC)->mpBegin[x].mpBegin[z] = scaled.b[0];
        }
    }
}

// A column of the grids as the standard vectors keep it, with the out-of-line members the original calls.
struct Row_ab3610 {
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    uint8_t* mpCap;
    // STUB: 0x004618e0
    void FillInsert(uint8_t* pos, uint32_t count, const uint8_t& fill);
    uint32_t size() const { return static_cast<uint32_t>(mpEnd - mpBegin); }
    void Erase(uint8_t* first, uint8_t* last);
    void Resize(uint32_t count, const uint8_t& fill)
    {
        if (count < size()) {
            Erase(mpBegin + count, mpEnd);
        } else {
            FillInsert(mpEnd, count - size(), fill);
        }
    }
};

struct Rows_ab3610 {
    Row_ab3610* mpBegin;
    Row_ab3610* mpEnd;
    Row_ab3610* mpCap;
    // STUB: 0x00461120
    void ResizeFill(uint32_t count, const Column_ab3610& fill);
    // STUB: 0x00461190
    void Erase(Row_ab3610* first, Row_ab3610* last);
    // STUB: 0x00461310
    void Insert(Row_ab3610* pos, uint32_t count, const Row_ab3610& fill);
    int32_t size() const { return static_cast<int32_t>(mpEnd - mpBegin); }
};

// A vector of bits and the grid of them.
struct Bits_ab3610 {
    uint32_t mpStart;
    uint32_t mnOffset;
    uint32_t mpFinish;
    uint32_t mnFinishOffset;
    uint32_t mpCap;
    // STUB: 0x00478140
    void Resize(uint32_t count, bool fill);
};

struct BitRows_ab3610 {
    Bits_ab3610* mpBegin;
    Bits_ab3610* mpEnd;
    Bits_ab3610* mpCap;
    // STUB: 0x005db690
    void Erase(Bits_ab3610* first, Bits_ab3610* last);
    // STUB: 0x005db800
    void Insert(Bits_ab3610* pos, uint32_t count, const Bits_ab3610& fill);
    int32_t size() const { return static_cast<int32_t>(mpEnd - mpBegin); }
};

// The memmove copy the standard library inlines for plain bytes.
inline uint8_t* CopyBytes_ab3610(const uint8_t* first, const uint8_t* last, uint8_t* result)
{
    if (first == last) {
        return result;
    }
    uint32_t count = static_cast<uint32_t>(last - first);
    return static_cast<uint8_t*>(memmove(result, first, count)) + count;
}

inline void Row_ab3610::Erase(uint8_t* first, uint8_t* last)
{
    uint8_t* i = CopyBytes_ab3610(last, mpEnd, first);
    mpEnd = i;
}

// The grid walker kept at +0x98: only the part Init sets is named.
struct Rect_ab3610 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
    void Set(int32_t left, int32_t top, int32_t right, int32_t bottom)
    {
        mnLeft = left;
        mnTop = top;
        mnRight = right;
        mnBottom = bottom;
    }
};

struct Iterator_ab3610 {
    bool mbFlag0;
    bool mbFlag1;
    bool mbFlag2;
    uint8_t mPad3;
    Rect_ab3610 mRect;
    // STUB: 0x0049d1c0
    void Reset(bool flag);
};

// STUB: 0x00b43cf4
// GLOBAL: 0x00b43cf4
extern Unknown_ab3610* gpB43cf4;
// GLOBAL: 0x00b43d5c
extern Simulator_ab3610* gpB43d5c;

#ifdef OB_DRAFTS
// CLOSE: 0x00729900 score 151 (the row-resize loops schedule their loads differently, the iterator rectangle is stored through a second pointer, register choice for the vtable loads)
bool cSC4WeatherSimulator::Init()
{
    if (!mbInitialized) {
        Fn00725af0();
        if (gpB43ccc) {
            gpB43ccc->AddNotification(reinterpret_cast<char*>(this) + 8, 0x26d31ec1);
        }
        if (!mpCity) {
            mpCity = gpB43cec;
            static_cast<cISC4City*>(mpCity)->AddRef();
        }
        if (!mbGridLoaded) {
            mfSizeX = static_cast<cISC4City*>(mpCity)->SizeX();
            mfSizeZ = static_cast<cISC4City*>(mpCity)->SizeZ();
            mnCellsX = static_cast<int32_t>(mfSizeX * 0.0625f);
            mnCellsZ = static_cast<int32_t>(mfSizeZ * 0.0625f);
            mfCellW = 16.0f;
            mfCellH = 16.0f;
            mfInvW = 0.0625f;
            mfInvH = 0.0625f;
            mnStdCellX = static_cast<int32_t>(mfCellW / static_cast<cISC4City*>(mpCity)->CellWidthX());
            mnStdCellZ = static_cast<int32_t>(mfCellH / static_cast<cISC4City*>(mpCity)->CellWidthZ());
            mnC8 = mnCellsZ * mnCellsX / 8;
            {
                Rows_ab3610* grid = reinterpret_cast<Rows_ab3610*>(mGridA);
                Column_ab3610 empty = {0, 0, 0};
                grid->ResizeFill(mnCellsX, empty);
                uint8_t fill = 0x7f;
                int32_t count = grid->size();
                for (int32_t i = 0; i < count; ++i) {
                    Row_ab3610* row = &grid->mpBegin[i];
                    uint32_t cellsZ = mnCellsZ;
                    uint8_t* pEnd = row->mpEnd;
                    uint8_t* pBegin = row->mpBegin;
                    if (cellsZ < static_cast<uint32_t>(pEnd - pBegin)) {
                        row->mpEnd = CopyBytes_ab3610(pEnd, row->mpEnd, pBegin + cellsZ);
                    } else {
                        row->FillInsert(pEnd, cellsZ - (pEnd - pBegin), fill);
                    }
                }
            }
            {
                Rows_ab3610* grid = reinterpret_cast<Rows_ab3610*>(mGridMoisture);
                Column_ab3610 empty = {0, 0, 0};
                grid->ResizeFill(mnCellsX, empty);
                uint8_t fill = 0x40;
                int32_t count = grid->size();
                for (int32_t i = 0; i < count; ++i) {
                    Row_ab3610* row = &grid->mpBegin[i];
                    uint32_t cellsZ = mnCellsZ;
                    uint8_t* pEnd = row->mpEnd;
                    uint8_t* pBegin = row->mpBegin;
                    if (cellsZ < static_cast<uint32_t>(pEnd - pBegin)) {
                        row->mpEnd = CopyBytes_ab3610(pEnd, row->mpEnd, pBegin + cellsZ);
                    } else {
                        row->FillInsert(pEnd, cellsZ - (pEnd - pBegin), fill);
                    }
                }
            }
            {
                BitRows_ab3610* grid = reinterpret_cast<BitRows_ab3610*>(mGridBits);
                Bits_ab3610 empty = {0, 0, 0, 0, 0};
                uint32_t cells = mnCellsX;
                if (cells < static_cast<uint32_t>(grid->size())) {
                    grid->Erase(grid->mpBegin + cells, grid->mpEnd);
                } else {
                    grid->Insert(grid->mpEnd, cells - grid->size(), empty);
                }
                int32_t count = grid->size();
                for (int32_t i = 0; i < count; ++i) {
                    grid->mpBegin[i].Resize(mnCellsZ, false);
                }
            }
            {
                uint32_t cells = mnCellsX;
                Rows_ab3610* grid = reinterpret_cast<Rows_ab3610*>(mGridC);
                Row_ab3610 empty = {0, 0, 0};
                uint8_t fill;
                if (cells < static_cast<uint32_t>(grid->size())) {
                    grid->Erase(grid->mpBegin + cells, grid->mpEnd);
                } else {
                    grid->Insert(grid->mpEnd, cells - grid->size(), empty);
                }
                fill = 0;
                int32_t count = grid->size();
                int32_t i = 0;
                while (i < count) {
                    Row_ab3610* row = &grid->mpBegin[i];
                    uint32_t cellsZ = mnCellsZ;
                    uint8_t* pEnd = row->mpEnd;
                    uint8_t* pBegin = row->mpBegin;
                    if (cellsZ < static_cast<uint32_t>(pEnd - pBegin)) {
                        row->mpEnd = CopyBytes_ab3610(pEnd, row->mpEnd, pBegin + cellsZ);
                    } else {
                        row->FillInsert(pEnd, cellsZ - (pEnd - pBegin), fill);
                    }
                    i++;
                }
            }
            Fn00726400();
        }
        if (!mpTerrain) {
            Unknown_ab3610* terrain = gpB43cf4;
            mpTerrain = terrain;
            terrain->AddRef();
        }
        if (!mpSimulator) {
            mpSimulator = gpB43d5c;
            static_cast<Simulator_ab3610*>(mpSimulator)->AddRef();
            cRZString name("cSC4WeatherSimulator");
            static_cast<Simulator_ab3610*>(mpSimulator)->AddAgent(reinterpret_cast<char*>(this) + 8, 6, &name, 2);
            static_cast<Simulator_ab3610*>(mpSimulator)->AddAgent(reinterpret_cast<char*>(this) + 8, 5, &name, 2);
            static_cast<Simulator_ab3610*>(mpSimulator)->AddAgent(reinterpret_cast<char*>(this) + 8, 4, &name, 2);
        }
        Iterator_ab3610* iterator = reinterpret_cast<Iterator_ab3610*>(mIterator);
        Rect_ab3610* rect = &iterator->mRect;
        rect->Set(0, 0, mnCellsX - 1, mnCellsZ - 1);
        int32_t left = rect->mnLeft;
        if (iterator->mRect.mnRight < left) {
            iterator->mRect.mnRight = left;
        }
        if (iterator->mRect.mnBottom < iterator->mRect.mnTop) {
            iterator->mRect.mnBottom = iterator->mRect.mnTop;
        }
        iterator->mbFlag2 = true;
        if (iterator->mbFlag1 != true) {
            iterator->mbFlag1 = true;
            iterator->mbFlag2 = true;
        }
        iterator->Reset(true);
        mnC8 = mnCellsZ * mnCellsX / mn54;
        mfF4 = mfF8;
        mn70 = mn64;
        mbInitialized = true;
    }
    return true;
}
#endif
