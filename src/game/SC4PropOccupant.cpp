#include <cmath>
#include <string>
#include <vector>
#include <cstddef>

#include "common/types.h"
#include "common/compiler.h"
#include "classes/cUnk00aa44c4.h"
#include "game/Globals.h"
#include "gzcom/cRZString.h"

// The prop occupant family (SC4000/SC4Lib/source/SC4PropOccupant.cpp): cSC4PropOccupant (vtable 0x00aa4900) and the
// classes built on it: the terrain decal (0x00aa4790), the burnt building (0x00aa4b30), a second effect class
// (0x00aa4d28) and the visual effect (0x00aa4ed8). No class header exists for any of them (the class map could not
// build them), so every method is written on a view struct that names its `this`: the full object, or the base
// subobject the method's vtable belongs to (offsets in each view are from its own `this`).
// Views and helper types end in the tag of the file's main class, aa4900.

// ---- shared pieces -------------------------------------------------------------------------------------------------

// A pointer test the original keeps (a null this or a null upcast source); a function so the portable compilers do not
// reject comparing this with null.
inline bool IsSet_aa4900(const void* p)
{
    return p != 0;
}
inline void* OffsetIfSet_aa4900(void* p, int32_t nOffset)
{
    return p ? reinterpret_cast<char*>(p) + nOffset : 0;
}


// The list of every prop type id seen so far (a vector<unsigned long> the program keeps at 0x00b231a4); a prop stores
// the index of its type in it.
struct TypeList_aa4900 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x0051ca60
    void Fn0051ca60(uint32_t* pos, const uint32_t* pValue, void* pTag, uint32_t nFill, uint32_t nAtEnd);
};
// GLOBAL: 0x00b231a4
extern TypeList_aa4900 gB231a4;

// A fixed-size block pool: the object keeps the pointer to the block header at +4 (free list at +8, count at +0xc).
struct PoolNode_aa4900 {
    PoolNode_aa4900* mpNext;
};
struct PoolBlock_aa4900 {
    uint8_t mPad00[8];
    PoolNode_aa4900* mpFree;
    uint32_t mnCount;
};
struct Pool_aa4900 {
    uint32_t mnField00;
    PoolBlock_aa4900* mpBlock;
    // STUB: 0x0090cf9a
    PoolNode_aa4900* Refill();
    // STUB: 0x0090d031
    void ReleaseBlock(PoolBlock_aa4900* pBlock);
    // STUB: 0x0090cff9
    void Relink(PoolBlock_aa4900* pBlock);
    void Free4c(PoolNode_aa4900* pNode);
    void Free52(PoolNode_aa4900* pNode);
    void Free38(PoolNode_aa4900* pNode);
    void Free5a(PoolNode_aa4900* pNode);
};
// GLOBAL: 0x00b0a8e4
extern Pool_aa4900 gB0a8e4;
// GLOBAL: 0x00b0a8f0
extern Pool_aa4900 gB0a8f0;
// GLOBAL: 0x00b0a8fc
extern Pool_aa4900 gB0a8fc;
// GLOBAL: 0x00b0a908
extern Pool_aa4900 gB0a908;
// GLOBAL: 0x00b0a914
extern Pool_aa4900 gB0a914;

// A date the occupant keeps twice (a first and a last day): 0x10 bytes, destroyed through the framework's cGZDate.
struct GZDate_aa4900 {
    uint32_t mn00;
    uint32_t mn04;
    uint32_t mn08;              // (the date interface starts here: vtable pointer at +8 of the date)
    uint32_t mn0c;
    // STUB: 0x00913177
    void Construct();
    // STUB: 0x00912e7b
    void ConstructFrom(uint32_t nDay);
    // STUB: 0x009128bf
    void Destroy();
};

// What the date-range pointer of a prop (0x54) points at.
struct DateInfo_aa4900 {
    uint32_t mnStart;           // 0x00
    uint32_t mnEnd;             // 0x04
    GZDate_aa4900 mFirst;       // 0x08
    GZDate_aa4900 mLast;        // 0x18
    DateInfo_aa4900()
    {
        mFirst.Construct();
        mLast.Construct();
    }
};

// A 3-vector the program default-fills from one float it keeps at 0x00b231a0 (copied as bits).
// GLOBAL: 0x00b231a0
extern uint32_t gB231a0;
struct Vec3Bits_aa4900 {
    uint32_t mBits[3];
    Vec3Bits_aa4900()
    {
        mBits[0] = gB231a0;
        mBits[1] = gB231a0;
        mBits[2] = gB231a0;
    }
};

// The random number source at 0x00b231b0.
struct Rng_aa4900 {
    // STUB: 0x00913a06
    uint32_t Rand(uint32_t limit);
};
// GLOBAL: 0x00b231b0
extern Rng_aa4900 gB231b0;

// A stack array with eight inline slots (the first request is served from them, a larger one from the heap).
struct SmallArray_aa4900 {
    int32_t mnCount;            // -1 until a request was made
    uint32_t* mpHeap;           // 4
    uint32_t mInline[8];        // 8
    uint32_t* New(uint32_t n);
};

// A model the prop shows: the calls used here.
struct cModel_aa4900 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual uint32_t GetCount();
    virtual void GetInstances(void** pOut, uint32_t* pCount);
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void SetVisible(bool bVisible);
};

// The occupant manager (a global at 0x00b43d0c).
struct cOccMgr_aa4900 {
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
    virtual bool AddOccupant(void* pOccupant, bool bFlag);
    virtual void RemoveOccupant(void* pOccupant, bool bFlagA, bool bFlagB);
};
// GLOBAL: 0x00b43d0c
extern cOccMgr_aa4900* gpB43d0c;

// The framework's streams: only the slots used here are named (cIGZOStream / cIGZIStream).
struct cOStream_aa4900 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void SetSint8(int8_t value);
    virtual void SetUint8(uint8_t value);
    virtual void Pad06();
    virtual void SetUint16(uint16_t value);
    virtual void Pad08();
    virtual void SetUint32(uint32_t value);
    virtual void Pad10();
    virtual void Pad11();
    virtual void SetFloat32(float value);
    virtual void Pad13();
    virtual void Pad14();
    virtual void SetGZStr(const void* pString);
    virtual void Pad16();
    virtual void Pad17();
    virtual bool GetError();
};
struct cIStream_aa4900 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void GetSint8(int8_t* pValue);
    virtual void GetUint8(uint8_t* pValue);
    virtual void Pad06();
    virtual void GetUint16(uint16_t* pValue);
    virtual void Pad08();
    virtual void GetUint32(uint32_t* pValue);
    virtual void Pad10();
    virtual void Pad11();
    virtual void GetFloat32(float* pValue);
    virtual void Pad13();
    virtual void Pad14();
    virtual void GetGZStr(void* pString);
    virtual void Pad16();
    virtual void Pad17();
    virtual bool GetError();
};
// STUB: 0x005da0a0
void Fn005da0a0(cOStream_aa4900* pStream, const void* pKey);
// STUB: 0x005da520
void Fn005da520(cOStream_aa4900* pStream, const void* pVec2);
// STUB: 0x005da070
void Fn005da070(cIStream_aa4900* pStream, void* pKey);
// STUB: 0x005da4f0
void Fn005da4f0(cIStream_aa4900* pStream, void* pVec2);

// The tick manager (SL::ATM): objects register to be ticked with a message mask.
struct cATM_aa4900 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Register(void* pTarget, uint32_t nMask);
    virtual void Unregister(void* pTarget, uint32_t nMask);
};
// STUB: 0x00602600
cATM_aa4900* Fn00602600();

// The decal manager a terrain decal draws through (its pointer is at +0x9c of the decal), addressed by decal id.
struct cDecalMgr_aa4790 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual uint32_t Create(const void* pKey, const void* pVec2, float fSize, uint32_t nFlags);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void SetVec(uint32_t nId, const float* pVec);
    virtual void GetVec(uint32_t nId, float* pVec);
    virtual void Remove(uint32_t nId);
    virtual void SetVisible(uint32_t nId, bool bVisible);
    virtual void SetSize(uint32_t nId, float fSize);
};

// ---- views ---------------------------------------------------------------------------------------------------------

// cSC4PropOccupant seen from its first byte (vtable 0x00aa4900 = the prop interface).
struct cPropOcc_aa4900 {
    virtual bool QueryInterface(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void* AsOccupant();
    virtual void SetBoundingBox(void*, void*);
    virtual uint32_t GetPropPlacementProperties();
    virtual void SetPropPlacementProperties(void*);
    virtual uint32_t GetPropType();
    virtual void SetPropType(uint32_t);
    virtual uint32_t GetOrientation();
    virtual bool SetOrientation(int32_t);
    virtual void SetState(uint32_t);
    virtual uint32_t GetState();
    virtual void SetTimeOfDayRange(float, float);
    virtual void GetTimeOfDayRange(float*, float*);
    virtual void SetSimulatorDateRange(uint32_t, uint32_t, uint8_t, uint8_t);
    virtual void TickSimulatorDate(void*);
    virtual void SetRandomChance(uint8_t);
    virtual bool GetRandomChance();
    virtual uint32_t GetPropTimerBitfield();
    virtual bool GetPropTimerState(uint8_t);
    virtual void SetPropTimerState(uint8_t, bool);
    virtual bool GetPropUsage();
    virtual void SetPropUsage(uint8_t);
    uint8_t mPad04[0x28];       // 0x04 (the other vtable pointers, the occupant base's fields)
    uint32_t mnOccupantType;    // 0x2c
    uint8_t mPad30[6];          // 0x30
    uint8_t mnFlags36;          // 0x36
    uint8_t mnFlags37;          // 0x37 bit 0: in the occupant manager, bit 1: shown
    uint8_t mPad38[4];          // 0x38
    float mBoxMin[3];           // 0x3c
    float mBoxMax[3];           // 0x48
    DateInfo_aa4900* mpDateRange;   // 0x54
    uint32_t mnLotTag;          // 0x58
    uint16_t mnTypeIndex;       // 0x5c
    uint8_t mnTimeStart;        // 0x5e
    uint8_t mnTimeEnd;          // 0x5f
    uint8_t mnTimerBits;        // 0x60
    uint8_t mnOrientation;      // 0x61
    uint8_t mnRandomChance;     // 0x62
    uint8_t mnState;            // 0x63
    uint8_t mn64;               // 0x64
    // STUB: 0x005ee050
    cPropOcc_aa4900();
    // STUB: 0x005ee1a0
    bool PlaceInOccupantManager(bool bPlace);
    bool PlaceInRenderer(bool bPlace);
    // STUB: 0x005ed220
    void SetSize(const float* pSize);
    void* DeletingDestructor(uint32_t nFlags);
    static void* operator new(size_t)
    {
        PoolNode_aa4900* pNode = gB0a8e4.mpBlock->mpFree;
        if (!pNode) {
            pNode = gB0a8e4.Refill();
        }
        gB0a8e4.mpBlock->mpFree = pNode->mpNext;
        ++gB0a8e4.mpBlock->mnCount;
        return pNode;
    }
    static void operator delete(void*) {}
};

// The occupant base subobject of cSC4PropOccupant (at +8, vtable 0x00aa4868); offsets from the subobject.
struct cOccPart_aa4868 {
    // STUB: 0x005e89c0
    virtual bool QueryInterface(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual bool Init();
    virtual bool Shutdown();
    virtual bool IsInitialized();
    virtual void* GetPropertyHolder();
    virtual void Pad07();
    virtual void GetCenter(float* pOut);
    virtual void SetCenter(const float* pIn);
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual cModel_aa4900* GetModel();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual bool GetLotTag(uint32_t* pTag);
    virtual void Pad28();
    virtual void Pad29();
    // STUB: 0x005e8b90
    virtual void SetFlags(uint32_t nFlags);
    uint8_t mPad04[0x2a];       // 0x04
    uint8_t mnFlags2e;          // 0x2e
    uint8_t mnFlags2f;          // 0x2f
    uint8_t mPad30[4];          // 0x30
    float mBoxMin[3];           // 0x34
    float mBoxMax[3];           // 0x40
    DateInfo_aa4900* mpDateRange; // 0x4c
    uint32_t mnLotTag;          // 0x50
    uint8_t mPad54[0x0c];       // 0x54
    // STUB: 0x005e89b0
    uint32_t Fn005e89b0();
    // STUB: 0x005e9220
    void Fn005e9220();
    // STUB: 0x005e8c40
    void Fn005e8c40();
    // STUB: 0x005e8c90
    void Fn005e8c90();
    // STUB: 0x005e8980
    bool Fn005e8980();
};

// The occupant base at +8 of a prop.
inline cOccPart_aa4868* OccPartOf_aa4900(cPropOcc_aa4900* pProp)
{
    return reinterpret_cast<cOccPart_aa4868*>(reinterpret_cast<char*>(pProp) + 8);
}
inline cPropOcc_aa4900* PropOf8_aa4900(cOccPart_aa4868* pOcc)
{
    return reinterpret_cast<cPropOcc_aa4900*>(reinterpret_cast<char*>(pOcc) - 8);
}

// More framework helpers the stream code calls (all free cdecl functions).
// STUB: 0x005da580
void Fn005da580(cOStream_aa4900* pStream, const float* pVec3);
// STUB: 0x005da550
void Fn005da550(cIStream_aa4900* pStream, float* pVec3);
// STUB: 0x005d9fd0
void Fn005d9fd0(cOStream_aa4900* pStream, bool bValue);
// STUB: 0x005d9fa0
void Fn005d9fa0(cIStream_aa4900* pStream, bool* pValue);
// STUB: 0x005da1a0
void Fn005da1a0(cOStream_aa4900* pStream, const void* pDate);
// STUB: 0x005da170
void Fn005da170(cIStream_aa4900* pStream, void* pDate);

// The persistence part of a prop (+0xc, vtable 0x00aa484c): the occupant base's own Write/Read come first.
struct cPropIo_aa484c {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual bool Write(cOStream_aa4900* pStream);
    virtual bool Read(cIStream_aa4900* pStream);
    // STUB: 0x005e8cd0
    bool Fn005e8cd0(cOStream_aa4900* pStream);
    // STUB: 0x005e8d60
    bool Fn005e8d60(cIStream_aa4900* pStream);
};
inline cPropOcc_aa4900* PropOfIo_aa4900(cPropIo_aa484c* p)
{
    return reinterpret_cast<cPropOcc_aa4900*>(reinterpret_cast<char*>(p) - 0xc);
}

// The date interface (the part of a date from +8 on: vtable pointer first) and the simulator's calendar.
struct cDate_aa4900 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Set(uint32_t nMonth, uint32_t nDay, uint32_t nYear);
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual uint32_t GetYear();
    virtual void Pad14();
    virtual uint32_t GetDayOfMonth();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual uint32_t GetMonth();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual bool IsBefore(const cDate_aa4900* pOther);
    virtual bool IsAfter(const cDate_aa4900* pOther);
    virtual void Pad29();
    virtual bool IsOnOrAfter(const cDate_aa4900* pOther);
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual uint32_t AddDays(uint32_t nDays);
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void SetYear(uint32_t nYear);
};
inline cDate_aa4900* DateIfaceOf_aa4900(GZDate_aa4900* p)
{
    return reinterpret_cast<cDate_aa4900*>(&p->mn08);
}

// ---- the persistence factory's records (vtable 0x00aa45b0, 0xb8 bytes) ----------------------------------------------

// The serialiser a record is read from / written to: the calls used here (a wider interface than the plain streams).
struct cSer_aa4900 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void GetUint8(uint8_t* pValue);
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
    virtual void GetFloat32(float* pValue);
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void GetBytes(void* pBuffer, uint32_t nCount);
    virtual void Pad28();
    virtual void SetUint8(uint32_t nValue);
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
    virtual void SetFloat32(float fValue);
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
    virtual void SetBytes(const void* pBuffer, uint32_t nCount);
};
struct Record_aa4900 {
    virtual bool QueryInterface(uint32_t nIid, void** ppObject);
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
    virtual void Destroy(uint32_t nFlags);
    uint8_t mPad04[0x1c];       // 0x04
    Vec3Bits_aa4900 mVec[4];    // 0x20
    uint8_t mPad50[0x68];       // 0x50
    // STUB: 0x005ed0c0
    Record_aa4900();
};
// STUB: 0x00975633
void Fn00975633(void* pObject);

// ---- helpers of the prop's own methods -------------------------------------------------------------------------------

// The model's instances: an object that answers QueryInterface; the animation interface it yields has a virtual base.
struct cModelInst_aa4900 {
    virtual bool QueryInterface(uint32_t nIid, void** ppObject);
};
struct cAnimBase_aa4900 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
};
struct cAnim_aa4900 {
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
    virtual void SetState(uint32_t nState);
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Tick(float fDelta);
};
inline void ReleaseAnim_aa4900(cAnim_aa4900* pAnim)
{
    char* pBase = reinterpret_cast<char*>(pAnim);
    cAnimBase_aa4900* pVirtualBase = reinterpret_cast<cAnimBase_aa4900*>(
        pBase + 4 + *reinterpret_cast<int32_t*>(*reinterpret_cast<char**>(pBase + 4) + 4));
    pVirtualBase->Release();
}

// The message the prop posts (0x2c bytes from the program's allocator).
// STUB: 0x009133da
void* Fn009133da(uint32_t nSize);
struct cMsg_aa4900 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetType(uint32_t nType);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void SetSender(void* pSender);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void SetData(uint32_t nData);
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
    virtual void SetTarget(void* pTarget);
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    cMsg_aa4900();
    static void* operator new(size_t nSize) { return Fn009133da(static_cast<uint32_t>(nSize)); }
    static void operator delete(void*) {}
};

// The prop's second (+0x10) role: whether a property is present.
struct cPropRole10_aa47e8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual bool HasProperty(uint32_t nId);
};

// The 24-hour clock (a global at 0x00b43dbc).
struct cClock_aa4900 {
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
    virtual uint32_t GetHour();
    virtual void Pad11();
    virtual void Pad12();
    virtual uint32_t GetMinute();
};
// GLOBAL: 0x00b43dbc
extern cClock_aa4900* gpB43dbc;

// The simulator (a global at 0x00b43d5c): slot 32 is the speed of time.
struct cSimulator_aa4900 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual cDate_aa4900* GetDate();
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
    virtual float GetTimeSpeed();
};
// GLOBAL: 0x00b43d5c
extern cSimulator_aa4900* gpB43d5c;

// A message as the tick handler reads it.
struct cMsgIn_aa4900 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual uint32_t GetType();
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
    virtual uint32_t GetData1();
};

// The prop's message-target role (+4, vtable 0x00aa48f0).
struct cPropMsg_aa48f0 {
    bool DoMessage(cMsgIn_aa4900* pMessage);
};
inline cPropOcc_aa4900* PropOfMsg_aa4900(cPropMsg_aa48f0* p)
{
    return reinterpret_cast<cPropOcc_aa4900*>(reinterpret_cast<char*>(p) - 4);
}

// ---- the terrain decal (vtable 0x00aa4790) --------------------------------------------------------------------------

// The service that hands out the decal manager (a free function at 0x00602160 returns it).
struct cDecalSvc_aa4790 {
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
    virtual cDecalMgr_aa4790* GetManager(uint32_t nMode);
};
// STUB: 0x00602160
cDecalSvc_aa4790* Fn00602160();

// A counted pointer to the decal manager (assignment releases the old one and adds a reference to the new).
struct MgrRef_aa4790 {
    cDecalMgr_aa4790* mpMgr;
    // STUB: 0x005447b0
    void Assign(cDecalMgr_aa4790* pMgr);
};

// The decal's own interface (vtable pointer at +0).
struct cDecalIface_aa4790 {
    virtual bool QueryInterface(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void SetDecalTexture(const uint32_t* pKey, float fSize);
    virtual void SetOpacity(float fOpacity);
    virtual void SetOpacityFade(float fDuration, uint32_t nAction, float fFrom, float fTo);
    virtual void SetDecalSize(float fSize);
};

// cSC4PropOccupantTerrainDecal: the interface at +0, the prop at +4, the decal's own fields from +0x6c.
class cDecal_aa4790 : public cDecalIface_aa4790, public cPropOcc_aa4900 {
public:
    virtual bool QueryInterface(uint32_t nIid, void** ppObject);
    uint32_t mnDecalId;         // 0x6c
    uint32_t mKey[3];           // 0x70 (type, group, instance of the texture)
    float mfSize;               // 0x7c
    float mVec2[2];             // 0x80
    float mfOpacity;            // 0x88
    float mfFadeFrom;           // 0x8c
    float mfFadeTo;             // 0x90
    float mfFadeRate;           // 0x94
    uint8_t mnFadeAction;       // 0x98
    uint8_t mbFadeRef;          // 0x99
    uint8_t mbRegistered;       // 0x9a
    cDecalMgr_aa4790* mpDecalMgr;   // 0x9c
    virtual void SetDecalTexture(const uint32_t* pKey, float fSize);
    virtual void SetOpacity(float fOpacity);
    virtual void SetOpacityFade(float fDuration, uint32_t nAction, float fFrom, float fTo);
    virtual void SetDecalSize(float fSize);
    // STUB: 0x005ee360
    cDecal_aa4790();
    static void* operator new(size_t)
    {
        PoolNode_aa4900* pNode = gB0a8f0.mpBlock->mpFree;
        if (!pNode) {
            pNode = gB0a8f0.Refill();
        }
        gB0a8f0.mpBlock->mpFree = pNode->mpNext;
        ++gB0a8f0.mpBlock->mnCount;
        return pNode;
    }
    static void operator delete(void* pMem)
    {
        PoolNode_aa4900* pNode = static_cast<PoolNode_aa4900*>(pMem);
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mpFree = pNode;
        pBlock->mnCount = n;
        if (n == 0) {
            gB0a8f0.ReleaseBlock(pBlock);
        } else if (n == 0x4000004c) {
            gB0a8f0.Relink(pBlock);
        }
    }
    // STUB: 0x005ed500
    void Destroy();
    void* DeletingDestructor(uint32_t nFlags);
};

// The decal seen from its message-target subobject (+8), occupant base (+0xc) and stream part (+0x10).
struct cDecalMsg_aa4720 {
    bool DoMessage(void* pMessage);
};
struct cDecalOcc_aa4698 : public cOccPart_aa4868 {
    uint32_t mnDecalId;         // 0x60
    uint32_t mKey[3];           // 0x64
    float mfSize;               // 0x70
    float mVec2[2];             // 0x74
    float mfOpacity;            // 0x7c
    float mfFadeFrom;           // 0x80
    float mfFadeTo;             // 0x84
    float mfFadeRate;           // 0x88
    uint8_t mnFadeAction;       // 0x8c
    uint8_t mbFadeRef;          // 0x8d
    uint8_t mbRegistered;       // 0x8e
    cDecalMgr_aa4790* mpDecalMgr;   // 0x90
    virtual bool Init();
    virtual bool Shutdown();
    virtual void SetCenter(const float* pCenter);
    virtual void SetFlags(uint32_t nFlags);
};
struct cDecalIo_aa467c : public cPropIo_aa484c {
    virtual bool Write(cOStream_aa4900* pStream);
    virtual bool Read(cIStream_aa4900* pStream);
};
inline cDecal_aa4790* DecalOfMsg_aa4790(cDecalMsg_aa4720* p)
{
    return reinterpret_cast<cDecal_aa4790*>(reinterpret_cast<char*>(p) - 8);
}
inline cDecal_aa4790* DecalOfOcc_aa4790(cDecalOcc_aa4698* p)
{
    return reinterpret_cast<cDecal_aa4790*>(reinterpret_cast<char*>(p) - 0xc);
}
inline cDecal_aa4790* DecalOfIo_aa4790(cDecalIo_aa467c* p)
{
    return reinterpret_cast<cDecal_aa4790*>(reinterpret_cast<char*>(p) - 0x10);
}

// ---- the visual effect (vtable 0x00aa4ed8) ---------------------------------------------------------------------------

// The effect object a prop plays (its counted pointer is at +0x6c of the prop).
struct cEffect_aa4ed8 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Play(bool bPlay);
    virtual void Stop(bool bStop);
    virtual void Pad05();
    virtual void Pad06();
    virtual void SetTransform(const void* pTransform);
};

// The effects manager (a global at 0x00b43d1c).
struct cEffectsMgr_aa4ed8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual bool CreateById(uint32_t nType, uint32_t nId, cEffect_aa4ed8** ppEffect);
    virtual bool CreateByName(const char* pName, cEffect_aa4ed8** ppEffect);
};
// GLOBAL: 0x00b43d1c
extern cEffectsMgr_aa4ed8* gpB43d1c;

// A property holder: the calls used here.
struct cPropHolder_aa4ed8 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual bool HasProperty(uint32_t nId);
};
// STUB: 0x005fd570
bool Fn005fd570(cPropHolder_aa4ed8* pHolder, uint32_t nId, void* pString);
// STUB: 0x005fd480
bool Fn005fd480(cPropHolder_aa4ed8* pHolder, uint32_t nId, uint32_t* pValue);
// STUB: 0x005ffcc0
bool Fn005ffcc0(cPropHolder_aa4ed8* pHolder, uint32_t nId, void* pVector);
// STUB: 0x00418a40
bool Fn00418a40(const void* pString, const char* pLiteral);

// The transform an effect is given: counts, a 3x3 rotation, a position and a scale.
struct Transform_aa4ed8 {
    uint8_t mnCount;
    uint8_t mnMask;
    float mRot[9];
    float mPos[3];
    float mfScale;
};

// The interface of cSC4PropOccupantVisualEffect (vtable pointer at +0).
struct cVisEffIface_aa4ed8 {
    virtual bool QueryInterface(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetEffectType(uint32_t nId);
    virtual void SetEffectType(const char* pName);
    virtual bool StartEffect(bool bStart);
    virtual bool StopEffect(bool bStop);
};

// The visual effect: the interface at +0, the prop at +4, the effect's fields from +0x6c.
class cVisEff_aa4ed8 : public cVisEffIface_aa4ed8, public cPropOcc_aa4900 {
public:
    virtual bool QueryInterface(uint32_t nIid, void** ppObject);
    cEffect_aa4ed8* mpEffect;   // 0x6c
    cRZString mName;            // 0x70
    uint32_t mnEffectId;        // 0x84
    uint32_t mnNameCount;       // 0x88
    uint32_t mnIdCount;         // 0x8c
    uint8_t mbStarted;          // 0x90
    uint8_t mb91;               // 0x91
    virtual void SetEffectType(uint32_t nId);
    virtual void SetEffectType(const char* pName);
    virtual bool StartEffect(bool bStart);
    virtual bool StopEffect(bool bStop);
    // STUB: 0x005f0210
    cVisEff_aa4ed8();
    // STUB: 0x005ee9c0
    void RestartEffect();
    // STUB: 0x005ee800
    void UpdateTransform();
    static void* operator new(size_t)
    {
        PoolNode_aa4900* pNode = gB0a8fc.mpBlock->mpFree;
        if (!pNode) {
            pNode = gB0a8fc.Refill();
        }
        gB0a8fc.mpBlock->mpFree = pNode->mpNext;
        ++gB0a8fc.mpBlock->mnCount;
        return pNode;
    }
    static void operator delete(void* pMem)
    {
        PoolNode_aa4900* pNode = static_cast<PoolNode_aa4900*>(pMem);
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mpFree = pNode;
        pBlock->mnCount = n;
        if (n == 0) {
            gB0a8fc.ReleaseBlock(pBlock);
        } else if (n == 0x40000052) {
            gB0a8fc.Relink(pBlock);
        }
    }
    // STUB: 0x005f0340
    void Destroy();
    void* DeletingDestructor(uint32_t nFlags);
};

// The effect seen from its prop subobject (+4), occupant base (+0xc) and stream part (+0x10).
struct cVisPart_aa4e78 : public cPropOcc_aa4900 {
    virtual void SetState(uint32_t nState);
    virtual bool SetOrientation(int32_t nOrientation);
};
struct cVisOcc_aa4de0 : public cOccPart_aa4868 {
    cEffect_aa4ed8* mpEffect;   // 0x60
    cRZString mName;            // 0x64
    uint32_t mnEffectId;        // 0x78
    uint32_t mnNameCount;       // 0x7c
    uint32_t mnIdCount;         // 0x80
    uint8_t mbStarted;          // 0x84
    uint8_t mbPaused;           // 0x85
    virtual bool Init();
    virtual bool Shutdown();
    virtual void SetCenter(const float* pCenter);
    virtual void SetFlags(uint32_t nFlags);
};
struct cVisIo_aa4dc4 : public cPropIo_aa484c {
    virtual bool Write(cOStream_aa4900* pStream);
    virtual bool Read(cIStream_aa4900* pStream);
};
inline cVisEff_aa4ed8* VisOfPart_aa4ed8(cVisPart_aa4e78* p)
{
    return reinterpret_cast<cVisEff_aa4ed8*>(reinterpret_cast<char*>(p) - 4);
}
inline cVisEff_aa4ed8* VisOfOcc_aa4ed8(cVisOcc_aa4de0* p)
{
    return reinterpret_cast<cVisEff_aa4ed8*>(reinterpret_cast<char*>(p) - 0xc);
}
inline cVisEff_aa4ed8* VisOfIo_aa4ed8(cVisIo_aa4dc4* p)
{
    return reinterpret_cast<cVisEff_aa4ed8*>(reinterpret_cast<char*>(p) - 0x10);
}

// ---- the second effect class (vtable 0x00aa4d28: the automata controller prop) ---------------------------------------

// The controller object a prop holds (counted pointer at +0x6c) and the manager that creates and removes them.
struct cCtrl_aa4d28 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
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
    virtual void SetActive(bool bActive);
};
struct cCtrlMgr_aa4d28 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual cCtrl_aa4d28* Create(void* pOccupant, const void* pName, uint32_t nFlags);
    virtual void Pad06();
    virtual void Remove(cCtrl_aa4d28* pCtrl);
};
// The city as this file needs it: slot 47 hands out the controller manager.
struct cCity_aa4d28 {
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
    virtual cCtrlMgr_aa4d28* GetAutomataControllerManager();
};
// GLOBAL: 0x00b43cec
extern cCity_aa4d28* gpB43cec_aa4d28;

struct cCtrlIface_aa4d28 {
    virtual bool QueryInterface(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetControllerName(const char* pName);
    virtual bool SetControllerFlag(bool bFlag);
};

// The controller prop: the interface at +0, the prop at +4, the controller pointer at +0x6c, its name at +0x70.
class cCtrlProp_aa4d28 : public cCtrlIface_aa4d28, public cPropOcc_aa4900 {
public:
    virtual bool QueryInterface(uint32_t nIid, void** ppObject);
    cCtrl_aa4d28* mpCtrl;       // 0x6c
    cRZString mName;            // 0x70
    bool mbFlag;                // 0x84
    virtual void SetControllerName(const char* pName);
    virtual bool SetControllerFlag(bool bFlag);
    // STUB: 0x005efdb0
    cCtrlProp_aa4d28();
    // STUB: 0x005f00b0
    void RestartController();
    static void* operator new(size_t)
    {
        PoolNode_aa4900* pNode = gB0a914.mpBlock->mpFree;
        if (!pNode) {
            pNode = gB0a914.Refill();
        }
        gB0a914.mpBlock->mpFree = pNode->mpNext;
        ++gB0a914.mpBlock->mnCount;
        return pNode;
    }
    static void operator delete(void* pMem)
    {
        PoolNode_aa4900* pNode = static_cast<PoolNode_aa4900*>(pMem);
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mpFree = pNode;
        pBlock->mnCount = n;
        if (n == 0) {
            gB0a914.ReleaseBlock(pBlock);
        } else if (n == 0x4000005a) {
            gB0a914.Relink(pBlock);
        }
    }
    // STUB: 0x005efef0
    void Destroy();
    void* DeletingDestructor(uint32_t nFlags);
};
struct cCtrlPart_aa4cc8 : public cPropOcc_aa4900 {
    virtual void SetState(uint32_t nState);
};
struct cCtrlOcc_aa4c30 : public cOccPart_aa4868 {
    cCtrl_aa4d28* mpCtrl;       // 0x60
    cRZString mName;            // 0x64
    bool mbFlag;                // 0x78
    virtual bool Init();
    virtual bool Shutdown();
};
struct cCtrlIo_aa4c14 : public cPropIo_aa484c {
    virtual bool Write(cOStream_aa4900* pStream);
    virtual bool Read(cIStream_aa4900* pStream);
};
inline cCtrlProp_aa4d28* CtrlOfPart_aa4d28(cCtrlPart_aa4cc8* p)
{
    return reinterpret_cast<cCtrlProp_aa4d28*>(reinterpret_cast<char*>(p) - 4);
}
inline cCtrlProp_aa4d28* CtrlOfOcc_aa4d28(cCtrlOcc_aa4c30* p)
{
    return reinterpret_cast<cCtrlProp_aa4d28*>(reinterpret_cast<char*>(p) - 0xc);
}
inline cCtrlProp_aa4d28* CtrlOfIo_aa4d28(cCtrlIo_aa4c14* p)
{
    return reinterpret_cast<cCtrlProp_aa4d28*>(reinterpret_cast<char*>(p) - 0x10);
}

// ---- the burnt building (vtable 0x00aa4b30: the prop at +0, a virtual base 0x00abd4b4 near the end) ------------------

// The renderer (a global at 0x00b43dd0): the calls used here take the burnt building's virtual base.
struct cRenderer_aa4b30 {
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
    virtual bool IsRegistered(void* pBase);
    virtual void Register(void* pBase);
    virtual void Unregister(void* pBase);
};
// GLOBAL: 0x00b43dd0
extern cRenderer_aa4b30* gpB43dd0;

// An occupant as the bounds setter sees it.
struct cOccupant_aa4b30 {
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
    virtual void GetBoundingBox(float* pMin, float* pMax);
};

struct Vec3_aa4b30 {
    uint32_t v[3];
};

// The float at 0x00b0a8d8 (a world scale) the rebuilt position is multiplied by.
// GLOBAL: 0x00b0a8d8
extern float gfB0a8d8;

class cBurnt_aa4b30 : public cPropOcc_aa4900 {
public:
    uint8_t mPad68[0x2c];       // 0x68 (the virtual base pointer and the base's own data)
    uint32_t* mpTextures;       // 0x94 (vector of texture bindings: begin, end, cap)
    uint32_t* mpTexturesEnd;    // 0x98
    uint32_t* mpTexturesCap;    // 0x9c
    Vec3_aa4b30 mBBoxMin;       // 0xa0
    Vec3_aa4b30 mBBoxMax;       // 0xac
    float* mpQuad;              // 0xb8
    uint8_t mPadBc[8];          // 0xbc (the packed render state)
    Vec3_aa4b30 mCorner;        // 0xc4
    // STUB: 0x005ef810
    cBurnt_aa4b30(int nMostDerived);
    void Rebuild();
    void SetBoundsFromOccupant(cOccupant_aa4b30* pOccupant);
    static void* operator new(size_t)
    {
        PoolNode_aa4900* pNode = gB0a908.mpBlock->mpFree;
        if (!pNode) {
            pNode = gB0a908.Refill();
        }
        gB0a908.mpBlock->mpFree = pNode->mpNext;
        ++gB0a908.mpBlock->mnCount;
        return pNode;
    }
    static void operator delete(void* pMem)
    {
        PoolNode_aa4900* pNode = static_cast<PoolNode_aa4900*>(pMem);
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mpFree = pNode;
        pBlock->mnCount = n;
        if (n == 0) {
            gB0a908.ReleaseBlock(pBlock);
        } else if (n == 0x40000038) {
            gB0a908.Relink(pBlock);
        }
    }
    // STUB: 0x005efb20
    void Destroy();
    void* DeletingDestructor(uint32_t nFlags);
};
struct cBurntIo_aa4a7c : public cPropIo_aa484c {
    uint8_t mPad04[0x98];       // 0x04
    Vec3_aa4b30 mBBoxMin;       // 0x9c? (the box starts at 0x94 from here)
    virtual bool Write(cOStream_aa4900* pStream);
    virtual bool Read(cIStream_aa4900* pStream);
};
// STUB: 0x005da600
void Fn005da600(cOStream_aa4900* pStream, const void* pBox);
// STUB: 0x005da5b0
void Fn005da5b0(cIStream_aa4900* pStream, void* pBox);

// A texture binding (counted; Release at 0x008090e0).
struct TexBinding_aa4b30 {
    // STUB: 0x008090e0
    void Release();
};

// The render-state packer the burnt building owns (at +0xbc of the building).
struct PackedState_aa4b30 {
    uint8_t mData[8];
    // STUB: 0x007d2b50
    void Pack(bool bA, bool bB, bool bC, uint32_t nD, uint32_t nE, uint32_t nF, uint32_t nG, uint32_t nH, uint32_t nI,
        uint32_t nJ, uint32_t nK, float fL, bool bM, uint32_t nN);
};

// The resource manager the building's textures come from.
struct cResHolder_aa4b30 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void GetResource(const void* pKey, TexBinding_aa4b30** ppOut);
};
struct cResMgr_aa4b30 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Open(uint32_t nType, uint32_t nGroup, cResHolder_aa4b30** ppOut);
};
// STUB: 0x008793ec
cResMgr_aa4b30* Fn008793ec();

// The burnt building seen from its occupant base (+8): the building's own fields in that base's offsets.
struct cBurntOcc_aa4a98 : public cOccPart_aa4868 {
    uint8_t mPad60[4];          // 0x60
    char* mpVbTable;            // 0x64
    uint8_t mPad68[0x24];       // 0x68
    TexBinding_aa4b30** mpTextures;     // 0x8c
    TexBinding_aa4b30** mpTexturesEnd;  // 0x90
    TexBinding_aa4b30** mpTexturesCap;  // 0x94
    uint8_t mPad98[0x18];       // 0x98
    float* mpQuad;              // 0xb0
    PackedState_aa4b30 mState;  // 0xb4
    virtual bool Init();
    virtual bool Shutdown();
    virtual void SetFlags(uint32_t nFlags);
    // STUB: 0x0049fc70
    void FillInsert(TexBinding_aa4b30** pPos, uint32_t nCount, TexBinding_aa4b30* const* pValue);
};
inline char* BurntBaseOf_aa4b30(cBurntOcc_aa4a98* p)
{
    char* pVb = reinterpret_cast<char*>(p) + 0x64;
    return pVb + *reinterpret_cast<int32_t*>(*reinterpret_cast<char**>(pVb) + 4);
}

// ---- functions -----------------------------------------------------------------------------------------------------

// FUNCTION: 0x005ece60
void* Fn005ece60()
{
    PoolNode_aa4900* pNode = gB0a8e4.mpBlock->mpFree;
    if (!pNode) {
        pNode = gB0a8e4.Refill();
    }
    gB0a8e4.mpBlock->mpFree = pNode->mpNext;
    ++gB0a8e4.mpBlock->mnCount;
    return pNode;
}

// FUNCTION: 0x005ed6e0
void* Fn005ed6e0()
{
    PoolNode_aa4900* pNode = gB0a8f0.mpBlock->mpFree;
    if (!pNode) {
        pNode = gB0a8f0.Refill();
    }
    gB0a8f0.mpBlock->mpFree = pNode->mpNext;
    ++gB0a8f0.mpBlock->mnCount;
    return pNode;
}

// FUNCTION: 0x005ed9a0
void* Fn005ed9a0()
{
    PoolNode_aa4900* pNode = gB0a8fc.mpBlock->mpFree;
    if (!pNode) {
        pNode = gB0a8fc.Refill();
    }
    gB0a8fc.mpBlock->mpFree = pNode->mpNext;
    ++gB0a8fc.mpBlock->mnCount;
    return pNode;
}

// FUNCTION: 0x005edae0
void* Fn005edae0()
{
    PoolNode_aa4900* pNode = gB0a908.mpBlock->mpFree;
    if (!pNode) {
        pNode = gB0a908.Refill();
    }
    gB0a908.mpBlock->mpFree = pNode->mpNext;
    ++gB0a908.mpBlock->mnCount;
    return pNode;
}

// FUNCTION: 0x005edd80
void* Fn005edd80()
{
    PoolNode_aa4900* pNode = gB0a914.mpBlock->mpFree;
    if (!pNode) {
        pNode = gB0a914.Refill();
    }
    gB0a914.mpBlock->mpFree = pNode->mpNext;
    ++gB0a914.mpBlock->mnCount;
    return pNode;
}

// FUNCTION: 0x005eef50
cPropOcc_aa4900* Fn005eef50()
{
    return new cPropOcc_aa4900();
}

// FUNCTION: 0x005ed280
uint32_t cPropOcc_aa4900::GetPropType()
{
    return gB231a4.mpBegin[mnTypeIndex];
}

// FUNCTION: 0x005ed590
bool cPropOcc_aa4900::GetPropTimerState(uint8_t mask)
{
    return (mnTimerBits & mask) != 0;
}

// FUNCTION: 0x005ec9e0
bool cPropOcc_aa4900::SetOrientation(int32_t orientation)
{
    int32_t v = orientation < 0 ? 0 : (orientation > 3 ? 3 : orientation);
    mnOrientation = static_cast<uint8_t>(v);
    return true;
}

// FUNCTION: 0x005eca10
void cPropOcc_aa4900::GetTimeOfDayRange(float* pStart, float* pEnd)
{
    *pStart = static_cast<float>(mnTimeStart) * 0.1f;
    *pEnd = static_cast<float>(mnTimeEnd) * 0.1f;
}

// FUNCTION: 0x005ec940
bool cOccPart_aa4868::Init()
{
    if (!IsInitialized()) {
        Fn005e8c90();
    }
    return true;
}

// FUNCTION: 0x005ecac0
bool cOccPart_aa4868::GetLotTag(uint32_t* pTag)
{
    if (mnLotTag == 0xffffffff) {
        return false;
    }
    *pTag = mnLotTag;
    return true;
}

// ---- batch 2 ----

// The type index lookup the matched code calls: the original's until the draft matches in the full build.
// STUB: 0x005ef2e0
uint16_t GetPropTypeIndex(uint32_t type);

// FUNCTION: 0x005ef2e0
uint16_t GetPropTypeIndexDraft_aa4900(uint32_t type)
{
    int32_t n = static_cast<int32_t>(gB231a4.mpEnd - gB231a4.mpBegin);
    int32_t i = 0;
    for (; i < n; i++) {
        if (gB231a4.mpBegin[i] == type) {
            break;
        }
    }
    if (i == n) {
        if (gB231a4.mpEnd != gB231a4.mpCap) {
            if (gB231a4.mpEnd) {
                *gB231a4.mpEnd = type;
            }
            gB231a4.mpEnd += 1;
        } else {
            char tag;
            gB231a4.Fn0051ca60(gB231a4.mpEnd, &type, &tag, 1, 1);
        }
    }
    return static_cast<uint16_t>(i);
}

// FUNCTION: 0x005ef4c0
void cPropOcc_aa4900::SetPropType(uint32_t type)
{
    mnTypeIndex = GetPropTypeIndex(type);
}

// FUNCTION: 0x005ee160
bool cOccPart_aa4868::Shutdown()
{
    DateInfo_aa4900* pInfo = mpDateRange;
    if (pInfo) {
        pInfo->mLast.Destroy();
        pInfo->mFirst.Destroy();
        delete pInfo;
        mpDateRange = 0;
    }
    return Fn005e8980();
}

// FUNCTION: 0x005ed1f0
void cOccPart_aa4868::GetCenter(float* pOut)
{
    pOut[0] = (mBoxMax[0] + mBoxMin[0]) * 0.5f;
    pOut[1] = mBoxMin[1];
    pOut[2] = (mBoxMax[2] + mBoxMin[2]) * 0.5f;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ed220 score 6
void cPropOcc_aa4900::SetSize(const float* pSize)
{
    Vec3Bits_aa4900 center;
    cOccPart_aa4868* pOcc = OccPartOf_aa4900(this);
    pOcc->GetCenter(reinterpret_cast<float*>(&center));
    mBoxMin[0] = 0;
    mBoxMin[1] = 0;
    mBoxMin[2] = 0;
    mBoxMax[0] = pSize[0];
    mBoxMax[1] = pSize[1];
    mBoxMax[2] = pSize[2];
    pOcc->SetCenter(reinterpret_cast<float*>(&center));
}
#endif

// FUNCTION: 0x005eca50
void cPropOcc_aa4900::SetPropTimerState(uint8_t mask, bool bSet)
{
    bool bWasAll = (mnTimerBits & 0xf) == 0xf;
    if (bSet) {
        mnTimerBits = mnTimerBits | mask;
    } else {
        mnTimerBits = ~mask & mnTimerBits;
    }
    bool bIsAll = (mnTimerBits & 0xf) == 0xf;
    if (bIsAll != bWasAll) {
        if (bIsAll) {
            if (gB231b0.Rand(100) < mnRandomChance) {
                SetState(0);
            }
        } else {
            SetState(1);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ed170 score 13
bool cPropOcc_aa4900::PlaceInRenderer(bool bPlace)
{
    if ((((mnFlags37 >> 1) & 1) != bPlace)) {
        cModel_aa4900* pModel = OccPartOf_aa4900(this)->GetModel();
        if (pModel) {
            pModel->AddRef();
            if (bPlace) {
                if (!(mnFlags37 & 1)) {
                    PlaceInOccupantManager(true);
                }
                mnFlags37 = mnFlags37 | 2;
            } else {
                mnFlags37 = mnFlags37 & 0xfd;
            }
            pModel->SetVisible(bPlace);
            pModel->Release();
            return true;
        }
        return false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ee1a0 score 33
bool cPropOcc_aa4900::PlaceInOccupantManager(bool bPlace)
{
    bool bIn = (mnFlags37 & 1) != 0;
    if (bIn != bPlace) {
        cOccMgr_aa4900* pMgr = gpB43d0c;
        if (!pMgr) {
            return false;
        }
        if (bIn) {
            if (mnFlags37 & 2) {
                PlaceInRenderer(false);
            }
            pMgr->RemoveOccupant(OccPartOf_aa4900(this), false, false);
            mnFlags37 = mnFlags37 & 0xfe;
        } else {
            if (!pMgr->AddOccupant(OccPartOf_aa4900(this), false)) {
                return false;
            }
            mnFlags37 = mnFlags37 | 1;
        }
    }
    return true;
}
#endif

// FUNCTION: 0x005eccc0
uint32_t* SmallArray_aa4900::New(uint32_t n)
{
    if (mnCount == -1) {
        mnCount = n;
        if (n < 8) {
            return mInline;
        }
        mpHeap = static_cast<uint32_t*>(operator new(n * 4));
        return mpHeap;
    }
    return static_cast<uint32_t*>(operator new(n * 4));
}

// The pool "free" routines (members of the pool object: push the node on its block's free list, hand the block back
// when it is empty, relink it when it just got a free slot again). One per pool, only the threshold differs.
// FUNCTION: 0x005eee50
void Pool_aa4900::Free4c(PoolNode_aa4900* pNode)
{
    if (pNode) {
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        pBlock->mpFree = pNode;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mnCount = n;
        if (n == 0) {
            ReleaseBlock(pBlock);
        } else if (n == 0x4000004c) {
            Relink(pBlock);
        }
    }
}

// FUNCTION: 0x005eee90
void Pool_aa4900::Free52(PoolNode_aa4900* pNode)
{
    if (pNode) {
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        pBlock->mpFree = pNode;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mnCount = n;
        if (n == 0) {
            ReleaseBlock(pBlock);
        } else if (n == 0x40000052) {
            Relink(pBlock);
        }
    }
}

// FUNCTION: 0x005eeed0
void Pool_aa4900::Free38(PoolNode_aa4900* pNode)
{
    if (pNode) {
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        pBlock->mpFree = pNode;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mnCount = n;
        if (n == 0) {
            ReleaseBlock(pBlock);
        } else if (n == 0x40000038) {
            Relink(pBlock);
        }
    }
}

// FUNCTION: 0x005eef10
void Pool_aa4900::Free5a(PoolNode_aa4900* pNode)
{
    if (pNode) {
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        pBlock->mpFree = pNode;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mnCount = n;
        if (n == 0) {
            ReleaseBlock(pBlock);
        } else if (n == 0x4000005a) {
            Relink(pBlock);
        }
    }
}

// ---- batch 3: the terrain decal ----

// FUNCTION: 0x005ecb90
void cDecal_aa4790::SetOpacityFade(float fDuration, uint32_t nAction, float fFrom, float fTo)
{
    mfFadeFrom = fFrom;
    mfFadeTo = fTo;
    mfFadeRate = (fTo - fFrom) / fDuration;
    mnFadeAction = static_cast<uint8_t>(nAction);
    if (nAction == 2 && !mbFadeRef) {
        static_cast<cDecalIface_aa4790*>(this)->AddRef();
        mbFadeRef = 1;
    }
    cATM_aa4900* pAtm = Fn00602600();
    if (pAtm && !mbRegistered) {
        pAtm->Register(reinterpret_cast<char*>(this) + 8, 0xc0);
        mbRegistered = 1;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ed7e0 score 16
void cDecal_aa4790::SetDecalTexture(const uint32_t* pKey, float fSize)
{
    mfSize = fSize;
    mKey[0] = pKey[0];
    mKey[1] = pKey[1];
    mKey[2] = pKey[2];
    float fHalf = fSize * 0.5f;
    float fNeg = -fHalf;
    mBoxMin[0] = fNeg;
    mBoxMin[1] = -0.1f;
    mBoxMin[2] = fNeg;
    mBoxMax[0] = fHalf;
    mBoxMax[1] = 0.1f;
    mBoxMax[2] = fHalf;
}
#endif

// FUNCTION: 0x005ed840
void cDecal_aa4790::SetOpacity(float fOpacity)
{
    mfOpacity = fOpacity;
    if (mpDecalMgr) {
        mpDecalMgr->SetSize(mnDecalId, fOpacity);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ed870 score 7
void cDecal_aa4790::SetDecalSize(float fSize)
{
    mfSize = fSize;
    if (mpDecalMgr) {
        float vec[3];
        vec[0] = 0;
        vec[1] = 0;
        vec[2] = 0;
        mpDecalMgr->GetVec(mnDecalId, vec);
        vec[2] = mfSize;
        mpDecalMgr->SetVec(mnDecalId, vec);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ed8d0 score 36
void cDecalOcc_aa4698::SetFlags(uint32_t nFlags)
{
    if (((mnFlags2f ^ nFlags) & 2) != 0) {
        cDecalMgr_aa4790* pMgr = mpDecalMgr;
        uint32_t nShown = nFlags & 2;
        if (pMgr) {
            pMgr->SetVisible(mnDecalId, nShown != 0);
        } else if (nShown && mKey[2] != 0 && mfSize > 0.0f) {
            reinterpret_cast<MgrRef_aa4790*>(&mpDecalMgr)->Assign(Fn00602160()->GetManager(fabs(mfFadeRate) < 0.1 ? 0 : 2));
            mnDecalId = mpDecalMgr->Create(&mKey[0], &mVec2[0], mfSize, 0);
            mpDecalMgr->SetSize(mnDecalId, mfOpacity);
        }
    }
    cOccPart_aa4868::SetFlags(nFlags);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ee410 score 6
bool cDecalOcc_aa4698::Init()
{
    if (!IsInitialized()) {
        if (!(mnFlags2e & 2)) {
            mBoxMax[0] = 16.0f;
            mBoxMax[1] = 16.0f;
            mBoxMax[2] = 16.0f;
            mBoxMin[0] = -16.0f;
            mBoxMin[1] = -16.0f;
            mBoxMin[2] = -16.0f;
            mfFadeRate = 0;
        }
        if (!IsInitialized()) {
            Fn005e8c90();
        }
        if ((mnFlags2e & 2) && mbRegistered) {
            cATM_aa4900* pAtm = Fn00602600();
            if (pAtm) {
                cDecal_aa4790* pDecal = DecalOfOcc_aa4790(this);
                pAtm->Register(pDecal ? reinterpret_cast<char*>(pDecal) + 8 : 0, 0xc0);
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ee4b0 score 14
bool cDecalOcc_aa4698::Shutdown()
{
    if (IsInitialized()) {
        if (mpDecalMgr) {
            mpDecalMgr->Remove(mnDecalId);
            mnDecalId = 0xffffffff;
            cDecalMgr_aa4790* pMgr = mpDecalMgr;
            if (pMgr) {
                mpDecalMgr = 0;
                pMgr->Release();
            }
        }
        mKey[2] = 0;
        DateInfo_aa4900* pInfo = mpDateRange;
        if (pInfo) {
            pInfo->mLast.Destroy();
            pInfo->mFirst.Destroy();
            delete pInfo;
            mpDateRange = 0;
        }
        Fn005e8980();
        if (mbRegistered) {
            cATM_aa4900* pAtm = Fn00602600();
            if (pAtm) {
                cDecal_aa4790* pDecal = DecalOfOcc_aa4790(this);
                pAtm->Unregister(pDecal ? reinterpret_cast<char*>(pDecal) + 8 : 0, 0xc0);
            }
            mbRegistered = 0;
        }
        if (mbFadeRef) {
            static_cast<cDecalIface_aa4790*>(DecalOfOcc_aa4790(this))->Release();
            mbFadeRef = 0;
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ee6d0 score 20
void cDecalOcc_aa4698::SetCenter(const float* pCenter)
{
    mVec2[0] = pCenter[0];
    mVec2[1] = pCenter[2];
    float fHalfX = (mBoxMax[0] - mBoxMin[0]) * 0.5f;
    float fHeight = mBoxMax[1] - mBoxMin[1];
    float fHalfZ = (mBoxMax[2] - mBoxMin[2]) * 0.5f;
    mBoxMin[0] = pCenter[0] - fHalfX;
    mBoxMax[0] = fHalfX + pCenter[0];
    mBoxMin[1] = pCenter[1];
    mBoxMax[1] = fHeight + pCenter[1];
    mBoxMin[2] = pCenter[2] - fHalfZ;
    mBoxMax[2] = fHalfZ + pCenter[2];
    if (mpDecalMgr) {
        float vec[3];
        vec[0] = 0;
        vec[1] = 0;
        mpDecalMgr->GetVec(mnDecalId, vec);
        vec[0] = mVec2[0];
        vec[1] = mVec2[1];
        vec[2] = mfSize;
        mpDecalMgr->SetVec(mnDecalId, vec);
    }
}
#endif

// ---- batch 3b: persistence and the rest of the decal ----

// FUNCTION: 0x005ece90
bool cPropIo_aa484c::Write(cOStream_aa4900* pStream)
{
    cPropOcc_aa4900* pProp = PropOfIo_aa4900(this);
    pStream->SetUint16(6);
    if (Fn005e8cd0(pStream)) {
        pStream->SetUint32(gB231a4.mpBegin[pProp->mnTypeIndex]);
        Fn005da580(pStream, &pProp->mBoxMin[0]);
        Fn005da580(pStream, &pProp->mBoxMax[0]);
        pStream->SetSint8(pProp->mnOrientation);
        pStream->SetUint8(pProp->mnState);
        pStream->SetUint8(pProp->mnTimeStart);
        pStream->SetUint8(pProp->mnTimeEnd);
        bool bHasDates = pProp->mpDateRange != 0;
        Fn005d9fd0(pStream, bHasDates);
        if (bHasDates) {
            pStream->SetUint32(pProp->mpDateRange->mnStart);
            pStream->SetUint32(pProp->mpDateRange->mnEnd);
            Fn005da1a0(pStream, &pProp->mpDateRange->mFirst);
            Fn005da1a0(pStream, &pProp->mpDateRange->mLast);
        }
        pStream->SetUint8(pProp->mnRandomChance);
        pStream->SetUint8(pProp->mn64);
        pStream->SetUint32(pProp->mnLotTag);
        pStream->SetUint8(pProp->mnTimerBits);
    }
    return !pStream->GetError();
}

// FUNCTION: 0x005ef360
bool cPropIo_aa484c::Read(cIStream_aa4900* pStream)
{
    cPropOcc_aa4900* pProp = PropOfIo_aa4900(this);
    uint16_t nVersion;
    uint32_t nType;
    bool bHasDates;
    pStream->GetUint16(&nVersion);
    if (Fn005e8d60(pStream)) {
        pStream->GetUint32(&nType);
        pProp->mnTypeIndex = GetPropTypeIndex(nType);
        Fn005da550(pStream, &pProp->mBoxMin[0]);
        Fn005da550(pStream, &pProp->mBoxMax[0]);
        pStream->GetSint8(reinterpret_cast<int8_t*>(&pProp->mnOrientation));
        pStream->GetUint8(&pProp->mnState);
        pStream->GetUint8(&pProp->mnTimeStart);
        pStream->GetUint8(&pProp->mnTimeEnd);
        Fn005d9fa0(pStream, &bHasDates);
        if (bHasDates) {
            pProp->mpDateRange = new DateInfo_aa4900;
            pStream->GetUint32(&pProp->mpDateRange->mnStart);
            pStream->GetUint32(&pProp->mpDateRange->mnEnd);
            Fn005da170(pStream, &pProp->mpDateRange->mFirst);
            Fn005da170(pStream, &pProp->mpDateRange->mLast);
        }
        pStream->GetUint8(&pProp->mnRandomChance);
        pStream->GetUint8(&pProp->mn64);
        pStream->GetUint32(&pProp->mnLotTag);
        if (nVersion > 5) {
            pStream->GetUint8(&pProp->mnTimerBits);
        } else {
            pProp->mnTimerBits = 0xf;
        }
    }
    return !pStream->GetError();
}

// FUNCTION: 0x005ed710
bool cDecalIo_aa467c::Write(cOStream_aa4900* pStream)
{
    cDecal_aa4790* pDecal = DecalOfIo_aa4790(this);
    pStream->SetUint16(3);
    if (cPropIo_aa484c::Write(pStream)) {
        pStream->SetUint32(pDecal->mnDecalId);
        Fn005da0a0(pStream, &pDecal->mKey[0]);
        pStream->SetFloat32(pDecal->mfSize);
        Fn005da520(pStream, &pDecal->mVec2[0]);
        pStream->SetFloat32(pDecal->mfOpacity);
        pStream->SetFloat32(pDecal->mfFadeFrom);
        pStream->SetFloat32(pDecal->mfFadeTo);
        pStream->SetFloat32(pDecal->mfFadeRate);
        pStream->SetSint8(pDecal->mnFadeAction);
        pStream->SetUint8(pDecal->mbFadeRef);
        pStream->SetUint8(pDecal->mbRegistered);
    }
    return !pStream->GetError();
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ef4e0 score 22
bool cDecalIo_aa467c::Read(cIStream_aa4900* pStream)
{
    cDecal_aa4790* pDecal = DecalOfIo_aa4790(this);
    bool bOk = false;
    uint16_t nVersion;
    pStream->GetUint16(&nVersion);
    if (nVersion == 3) {
        if (cPropIo_aa484c::Read(pStream)) {
            uint32_t nId;
            pStream->GetUint32(&nId);
            pDecal->mnDecalId = nId;
            Fn005da070(pStream, &pDecal->mKey[0]);
            pStream->GetFloat32(&pDecal->mfSize);
            Fn005da4f0(pStream, &pDecal->mVec2[0]);
            pStream->GetFloat32(&pDecal->mfOpacity);
            pStream->GetFloat32(&pDecal->mfFadeFrom);
            pStream->GetFloat32(&pDecal->mfFadeTo);
            pStream->GetFloat32(&pDecal->mfFadeRate);
            pStream->GetSint8(reinterpret_cast<int8_t*>(&pDecal->mnFadeAction));
            pStream->GetUint8(&pDecal->mbFadeRef);
            pStream->GetUint8(&pDecal->mbRegistered);
        }
        bOk = !pStream->GetError();
    }
    return bOk;
}
#endif

// FUNCTION: 0x005ef180
cPropOcc_aa4900* Fn005ef180()
{
    return new cDecal_aa4790();
}

// ---- batch 4: the visual effect ----

#ifdef OB_DRAFTS
// CLOSE: 0x005eda50 score 13
bool cVisEff_aa4ed8::StartEffect(bool bStart)
{
    if (mpEffect) {
        if (mnFlags37 & 2) {
            mpEffect->Play(!bStart);
        }
        mbStarted = 1;
        return true;
    }
    if (!mbStarted) {
        mbStarted = 1;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005edaa0 score 13
bool cVisEff_aa4ed8::StopEffect(bool bStop)
{
    if (!mpEffect || !mbStarted) {
        return false;
    }
    if (mnFlags37 & 2) {
        mpEffect->Stop(!bStop);
    }
    mbStarted = 0;
    return true;
}
#endif

// FUNCTION: 0x005ef7d0
void cVisEff_aa4ed8::SetEffectType(uint32_t nId)
{
    if (nId != mnEffectId) {
        mName.clear();
        mnEffectId = nId;
        mnNameCount = 0;
        mnIdCount = 0;
        RestartEffect();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x005f0780 score 51
void cVisEff_aa4ed8::SetEffectType(const char* pName)
{
    if (!(static_cast<std::string&>(mName) == pName)) {
        mnEffectId = 0;
        mName.assign(cRZString(pName));
        mnNameCount = 0;
        mnIdCount = 0;
        RestartEffect();
    }
}
#endif

// FUNCTION: 0x005ef2c0
void cVisPart_aa4e78::SetState(uint32_t nState)
{
    if (nState != mnState) {
        mnState = static_cast<uint8_t>(nState);
        VisOfPart_aa4ed8(this)->RestartEffect();
    }
}

// FUNCTION: 0x005ef280
bool cVisPart_aa4e78::SetOrientation(int32_t nOrientation)
{
    int32_t v = nOrientation < 0 ? 0 : (nOrientation > 3 ? 3 : nOrientation);
    mnOrientation = static_cast<uint8_t>(v);
    VisOfPart_aa4ed8(this)->UpdateTransform();
    return true;
}

// FUNCTION: 0x005ed9d0
void cVisOcc_aa4de0::SetFlags(uint32_t nFlags)
{
    if (mpEffect && mbStarted && ((mnFlags2f ^ nFlags) & 2) != 0) {
        if (nFlags & 2) {
            if (mbPaused) {
                mpEffect->Play(false);
            } else {
                mpEffect->Play(true);
            }
            mbPaused = 0;
        } else {
            mpEffect->Stop(true);
        }
    }
    cOccPart_aa4868::SetFlags(nFlags);
}

// FUNCTION: 0x005ee790
bool cVisOcc_aa4de0::Shutdown()
{
    if (IsInitialized()) {
        if (mpEffect) {
            mpEffect->Stop(false);
            cEffect_aa4ed8* pEffect = mpEffect;
            if (pEffect) {
                mpEffect = 0;
                pEffect->Release();
            }
        }
        DateInfo_aa4900* pInfo = mpDateRange;
        if (pInfo) {
            pInfo->mLast.Destroy();
            pInfo->mFirst.Destroy();
            delete pInfo;
            mpDateRange = 0;
        }
        Fn005e8980();
    }
    return true;
}

// FUNCTION: 0x005ef220
void cVisOcc_aa4de0::SetCenter(const float* pCenter)
{
    float fHalfX = (mBoxMax[0] - mBoxMin[0]) * 0.5f;
    float fHeight = mBoxMax[1] - mBoxMin[1];
    float fHalfZ = (mBoxMax[2] - mBoxMin[2]) * 0.5f;
    mBoxMin[0] = pCenter[0] - fHalfX;
    mBoxMax[0] = fHalfX + pCenter[0];
    mBoxMin[1] = pCenter[1];
    mBoxMax[1] = fHeight + pCenter[1];
    mBoxMin[2] = pCenter[2] - fHalfZ;
    mBoxMax[2] = fHalfZ + pCenter[2];
    VisOfOcc_aa4ed8(this)->UpdateTransform();
}

#ifdef OB_DRAFTS
// CLOSE: 0x005f03b0 score 21
bool cVisIo_aa4dc4::Write(cOStream_aa4900* pStream)
{
    cVisEff_aa4ed8* pVis = VisOfIo_aa4ed8(this);
    pStream->SetUint16(3);
    if (cPropIo_aa484c::Write(pStream)) {
        pStream->SetUint8(pVis->mbStarted);
        pStream->SetUint8(pVis->mb91);
        uint32_t nId;
        if (pVis->mnNameCount == 0 && pVis->mnIdCount == 0) {
            pStream->SetGZStr(&pVis->mName);
            nId = pVis->mnEffectId;
        } else {
            cRZString empty;
            pStream->SetGZStr(&empty);
            nId = 0;
        }
        pStream->SetUint32(nId);
    }
    return !pStream->GetError();
}
#endif

// FUNCTION: 0x005ef750
bool cVisIo_aa4dc4::Read(cIStream_aa4900* pStream)
{
    cVisEff_aa4ed8* pVis = VisOfIo_aa4ed8(this);
    uint16_t nVersion;
    pStream->GetUint16(&nVersion);
    if (nVersion != 3) {
        return false;
    }
    if (cPropIo_aa484c::Read(pStream)) {
        pStream->GetUint8(&pVis->mbStarted);
        pStream->GetUint8(&pVis->mb91);
        pStream->GetGZStr(&pVis->mName);
        pStream->GetUint32(&pVis->mnEffectId);
    }
    return !pStream->GetError();
}

// FUNCTION: 0x005f0560
cPropOcc_aa4900* Fn005f0560()
{
    return new cVisEff_aa4ed8();
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ee9c0 score 153
void cVisEff_aa4ed8::RestartEffect()
{
    bool bWasStarted = mbStarted != 0;
    if (mpEffect) {
        StopEffect(true);
        cEffect_aa4ed8* pOld = mpEffect;
        if (pOld) {
            mpEffect = 0;
            pOld->Release();
        }
    }
    bool bCreated;
    if (mnNameCount > 0) {
        if (mnState >= mnNameCount) {
            mbStarted = 1;
            return;
        }
        cPropHolder_aa4ed8* pHolder = static_cast<cPropHolder_aa4ed8*>(OccPartOf_aa4900(this)->GetPropertyHolder());
        Fn005fd570(pHolder, 0xc98204b8 + mnState, &mName);
        if (mName.empty()) {
            mbStarted = 1;
            return;
        }
        if (Fn00418a40(&mName, "off")) {
            mbStarted = 1;
            return;
        }
        cEffectsMgr_aa4ed8* pMgr = gpB43d1c;
        cEffect_aa4ed8* pOld2 = mpEffect;
        if (pOld2) {
            mpEffect = 0;
            pOld2->Release();
        }
        bCreated = pMgr->CreateByName(mName.c_str(), &mpEffect);
    } else if (mnIdCount > 0) {
        if (mnState >= mnIdCount) {
            mbStarted = 1;
            return;
        }
        cPropHolder_aa4ed8* pHolder = static_cast<cPropHolder_aa4ed8*>(OccPartOf_aa4900(this)->GetPropertyHolder());
        Fn005fd480(pHolder, 0x2a6def88 + mnState, &mnEffectId);
        if (mnEffectId == 0) {
            mbStarted = 1;
            return;
        }
        cEffectsMgr_aa4ed8* pMgr = gpB43d1c;
        cEffect_aa4ed8* pOld2 = mpEffect;
        if (pOld2) {
            mpEffect = 0;
            pOld2->Release();
        }
        bCreated = pMgr->CreateById(0xaa6dec65, mnEffectId, &mpEffect);
    } else if (!mName.empty()) {
        cEffectsMgr_aa4ed8* pMgr = gpB43d1c;
        cEffect_aa4ed8* pOld2 = mpEffect;
        if (pOld2) {
            mpEffect = 0;
            pOld2->Release();
        }
        bCreated = pMgr->CreateByName(mName.c_str(), &mpEffect);
    } else {
        if (mnEffectId == 0) {
            mbStarted = 1;
            return;
        }
        cEffectsMgr_aa4ed8* pMgr = gpB43d1c;
        cEffect_aa4ed8* pOld2 = mpEffect;
        if (pOld2) {
            mpEffect = 0;
            pOld2->Release();
        }
        bCreated = pMgr->CreateById(0xaa6dec65, mnEffectId, &mpEffect);
    }
    if (!bCreated) {
        mbStarted = 1;
        return;
    }
    UpdateTransform();
    if (bWasStarted) {
        StartEffect(true);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ee800 score 139
void cVisEff_aa4ed8::UpdateTransform()
{
    if (mpEffect) {
        float center[3];
        Vec3Bits_aa4900 base;
        reinterpret_cast<cOccPart_aa4868*>(reinterpret_cast<char*>(this) + 0xc)->GetCenter(reinterpret_cast<float*>(&base));
        center[0] = reinterpret_cast<float*>(&base)[0];
        center[1] = reinterpret_cast<float*>(&base)[1];
        center[2] = reinterpret_cast<float*>(&base)[2];
        int32_t nOrientation = static_cast<cPropOcc_aa4900*>(this)->GetOrientation();
        float fAngle = static_cast<float>(-nOrientation) * 1.5707964f;
        float fCos = cosf(fAngle);
        float fSin = sinf(fAngle);
        Transform_aa4ed8 transform;
        transform.mnCount = 2;
        transform.mnMask = 5;
        transform.mRot[0] = fCos;
        transform.mRot[1] = 0;
        transform.mRot[2] = fSin;
        transform.mRot[3] = 0;
        transform.mRot[4] = 1.0f;
        transform.mRot[5] = 0;
        transform.mRot[6] = -fSin;
        transform.mRot[7] = 0;
        transform.mRot[8] = fCos;
        transform.mPos[0] = center[0];
        transform.mPos[1] = center[1];
        transform.mPos[2] = center[2];
        transform.mfScale = 1.0f;
        mpEffect->SetTransform(&transform);
    }
}
#endif

// ---- batch 5: interface queries and pool blocks ----

// FUNCTION: 0x005ec960
bool cPropOcc_aa4900::QueryInterface(uint32_t nIid, void** ppObject)
{
    if (nIid == 0xe9793a65) {
        *ppObject = this;
        AddRef();
        return true;
    }
    if (nIid == 0x452294aa) {
        *ppObject = OffsetIfSet_aa4900(this, 4);
        AddRef();
        return true;
    }
    if (nIid == 0x2977aa47) {
        *ppObject = this;
        AddRef();
        return true;
    }
    return OccPartOf_aa4900(this)->cOccPart_aa4868::QueryInterface(nIid, ppObject);
}

// FUNCTION: 0x005ecb10
bool cDecal_aa4790::QueryInterface(uint32_t nIid, void** ppObject)
{
    if (nIid == 0x452294aa) {
        *ppObject = OffsetIfSet_aa4900(this, 8);
        reinterpret_cast<cOccPart_aa4868*>(reinterpret_cast<char*>(this) + 0xc)->Fn005e89b0();
        return true;
    }
    if (nIid == 0xe982078a) {
        *ppObject = this;
        reinterpret_cast<cOccPart_aa4868*>(reinterpret_cast<char*>(this) + 0xc)->Fn005e89b0();
        return true;
    }
    if (nIid == 0x2977aa48) {
        *ppObject = this;
        static_cast<cDecalIface_aa4790*>(this)->AddRef();
        return true;
    }
    return cPropOcc_aa4900::QueryInterface(nIid, ppObject);
}

// FUNCTION: 0x005ecc10
bool cVisEff_aa4ed8::QueryInterface(uint32_t nIid, void** ppObject)
{
    if (nIid == 0x9820792) {
        *ppObject = this;
        reinterpret_cast<cOccPart_aa4868*>(reinterpret_cast<char*>(this) + 0xc)->Fn005e89b0();
        return true;
    }
    if (nIid == 0x2977aa49) {
        *ppObject = this;
        static_cast<cVisEffIface_aa4ed8*>(this)->AddRef();
        return true;
    }
    return cPropOcc_aa4900::QueryInterface(nIid, ppObject);
}

// STUB: 0x0090d8e0
PoolBlock_aa4900* Fn0090d8e0(uint32_t nKind);

// FUNCTION: 0x005ecd10
PoolBlock_aa4900* Fn005ecd10()
{
    PoolBlock_aa4900* pBlock = Fn0090d8e0(0xe);
    PoolNode_aa4900* pPrev = 0;
    PoolNode_aa4900* pNode = reinterpret_cast<PoolNode_aa4900*>(reinterpret_cast<char*>(pBlock) + 0x3f30);
    PoolNode_aa4900* pHead;
    for (int32_t i = 0x66; i != 0; --i) {
        pNode->mpNext = pPrev;
        pHead = pNode;
        pPrev = pNode;
        pNode = reinterpret_cast<PoolNode_aa4900*>(reinterpret_cast<char*>(pNode) - 0xa0);
    }
    pBlock->mpFree = pHead;
    pBlock->mnCount = 0;
    return pBlock;
}

// FUNCTION: 0x005ecd50
PoolBlock_aa4900* Fn005ecd50()
{
    PoolBlock_aa4900* pBlock = Fn0090d8e0(0xe);
    PoolNode_aa4900* pPrev = 0;
    PoolNode_aa4900* pNode = reinterpret_cast<PoolNode_aa4900*>(reinterpret_cast<char*>(pBlock) + 0x3f14);
    PoolNode_aa4900* pHead;
    for (int32_t i = 0x6e; i != 0; --i) {
        pNode->mpNext = pPrev;
        pHead = pNode;
        pPrev = pNode;
        pNode = reinterpret_cast<PoolNode_aa4900*>(reinterpret_cast<char*>(pNode) - 0x94);
    }
    pBlock->mpFree = pHead;
    pBlock->mnCount = 0;
    return pBlock;
}

// FUNCTION: 0x005ecd90
PoolBlock_aa4900* Fn005ecd90()
{
    PoolBlock_aa4900* pBlock = Fn0090d8e0(0xe);
    PoolNode_aa4900* pPrev = 0;
    PoolNode_aa4900* pNode = reinterpret_cast<PoolNode_aa4900*>(reinterpret_cast<char*>(pBlock) + 0x3e80);
    PoolNode_aa4900* pHead;
    for (int32_t i = 0x4b; i != 0; --i) {
        pNode->mpNext = pPrev;
        pHead = pNode;
        pPrev = pNode;
        pNode = reinterpret_cast<PoolNode_aa4900*>(reinterpret_cast<char*>(pNode) - 0xd8);
    }
    pBlock->mpFree = pHead;
    pBlock->mnCount = 0;
    return pBlock;
}

// FUNCTION: 0x005ecdd0
PoolBlock_aa4900* Fn005ecdd0()
{
    PoolBlock_aa4900* pBlock = Fn0090d8e0(0xe);
    PoolNode_aa4900* pPrev = 0;
    PoolNode_aa4900* pNode = reinterpret_cast<PoolNode_aa4900*>(reinterpret_cast<char*>(pBlock) + 0x3f48);
    PoolNode_aa4900* pHead;
    for (int32_t i = 0x78; i != 0; --i) {
        pNode->mpNext = pPrev;
        pHead = pNode;
        pPrev = pNode;
        pNode = reinterpret_cast<PoolNode_aa4900*>(reinterpret_cast<char*>(pNode) - 0x88);
    }
    pBlock->mpFree = pHead;
    pBlock->mnCount = 0;
    return pBlock;
}

// ---- batch 6: the controller prop ----

// FUNCTION: 0x005ecc70
bool cCtrlProp_aa4d28::QueryInterface(uint32_t nIid, void** ppObject)
{
    if (nIid == 0x8a401788) {
        *ppObject = this;
        reinterpret_cast<cOccPart_aa4868*>(reinterpret_cast<char*>(this) + 0xc)->Fn005e89b0();
        return true;
    }
    if (nIid == 0x2a4017a0) {
        *ppObject = this;
        static_cast<cCtrlIface_aa4d28*>(this)->AddRef();
        return true;
    }
    return cPropOcc_aa4900::QueryInterface(nIid, ppObject);
}

// FUNCTION: 0x005ede00
void cOccPart_aa4868::SetCenter(const float* pCenter)
{
    float fHalfX = (mBoxMax[0] - mBoxMin[0]) * 0.5f;
    float fHeight = mBoxMax[1] - mBoxMin[1];
    float fHalfZ = (mBoxMax[2] - mBoxMin[2]) * 0.5f;
    mBoxMin[0] = pCenter[0] - fHalfX;
    mBoxMax[0] = fHalfX + pCenter[0];
    mBoxMin[1] = pCenter[1];
    mBoxMax[1] = fHeight + pCenter[1];
    mBoxMin[2] = pCenter[2] - fHalfZ;
    mBoxMax[2] = fHalfZ + pCenter[2];
}

// FUNCTION: 0x005ede60
bool cCtrlProp_aa4d28::SetControllerFlag(bool bFlag)
{
    if (mpCtrl) {
        mpCtrl->SetActive(bFlag);
        mbFlag = bFlag;
        return bFlag;
    }
    mbFlag = bFlag;
    return bFlag;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005f06f0 score 28
void cCtrlProp_aa4d28::SetControllerName(const char* pName)
{
    if (!(static_cast<std::string&>(mName) == pName)) {
        mName.assign(cRZString(pName));
        RestartController();
    }
}
#endif

// FUNCTION: 0x005f0530
void cCtrlPart_aa4cc8::SetState(uint32_t nState)
{
    if (nState != mnState) {
        mnState = static_cast<uint8_t>(nState);
        CtrlOfPart_aa4d28(this)->RestartController();
    }
}

// FUNCTION: 0x005eddb0
bool cCtrlIo_aa4c14::Write(cOStream_aa4900* pStream)
{
    cCtrlProp_aa4d28* pCtrl = CtrlOfIo_aa4d28(this);
    pStream->SetUint16(3);
    if (cPropIo_aa484c::Write(pStream)) {
        Fn005d9fd0(pStream, pCtrl->mbFlag);
        pStream->SetGZStr(&pCtrl->mName);
    }
    return !pStream->GetError();
}

// FUNCTION: 0x005efbf0
bool cCtrlIo_aa4c14::Read(cIStream_aa4900* pStream)
{
    cCtrlProp_aa4d28* pCtrl = CtrlOfIo_aa4d28(this);
    uint16_t nVersion;
    pStream->GetUint16(&nVersion);
    if (nVersion != 3) {
        return false;
    }
    if (cPropIo_aa484c::Read(pStream)) {
        Fn005d9fa0(pStream, &pCtrl->mbFlag);
        pStream->GetGZStr(&pCtrl->mName);
    }
    return !pStream->GetError();
}

// FUNCTION: 0x005eedd0
bool cCtrlOcc_aa4c30::Shutdown()
{
    if (IsInitialized()) {
        if (mpCtrl) {
            cCtrlMgr_aa4d28* pMgr = gpB43cec_aa4d28->GetAutomataControllerManager();
            if (pMgr) {
                pMgr->Remove(mpCtrl);
            }
            cCtrl_aa4d28* pCtrl = mpCtrl;
            if (pCtrl) {
                mpCtrl = 0;
                pCtrl->Release();
            }
        }
        DateInfo_aa4900* pInfo = mpDateRange;
        if (pInfo) {
            pInfo->mLast.Destroy();
            pInfo->mFirst.Destroy();
            delete pInfo;
            mpDateRange = 0;
        }
        Fn005e8980();
    }
    return true;
}

// FUNCTION: 0x005f0490
cPropOcc_aa4900* Fn005f0490()
{
    return new cCtrlProp_aa4d28();
}

// FUNCTION: 0x005eff60
bool cCtrlOcc_aa4c30::Init()
{
    if (!IsInitialized()) {
        cPropHolder_aa4ed8* pHolder = static_cast<cPropHolder_aa4ed8*>(GetPropertyHolder());
        std::vector<float> values;
        float size[3] = { 16.0f, 16.0f, 16.0f };
        if (Fn005ffcc0(pHolder, 0x27812810, &values)) {
            size[0] = values[0];
            size[1] = values[1];
            size[2] = values[2];
        }
        PropOf8_aa4900(this)->SetSize(size);
        cRZString name;
        if (!Fn005fd570(pHolder, 0xc98204b8, &name)) {
            Fn005fd570(pHolder, 0x20, &name);
        }
        if (!name.empty()) {
            static_cast<cCtrlIface_aa4d28*>(CtrlOfOcc_aa4d28(this))->SetControllerName(name.c_str());
            mbFlag = true;
        }
        if (!IsInitialized()) {
            Fn005e8c90();
        }
        if (mbFlag && mpCtrl && (mnFlags2f & 2)) {
            mpCtrl->SetActive(true);
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005f00b0 score 20
void cCtrlProp_aa4d28::RestartController()
{
    bool bFlag = mbFlag;
    cCtrlMgr_aa4d28* pMgr = gpB43cec_aa4d28->GetAutomataControllerManager();
    if (mpCtrl) {
        mpCtrl->SetActive(false);
        if (pMgr) {
            pMgr->Remove(mpCtrl);
        }
        cCtrl_aa4d28* pOld = mpCtrl;
        if (pOld) {
            mpCtrl = 0;
            pOld->Release();
        }
    }
    if (!mName.empty()) {
        if (mnState == 0) {
            cCtrl_aa4d28* pNew = pMgr->Create(OccPartOf_aa4900(this), &mName, 0);
            cCtrl_aa4d28* pOld = mpCtrl;
            if (pNew != pOld) {
                if (pNew) {
                    pNew->AddRef();
                }
                mpCtrl = pNew;
                if (pOld) {
                    pOld->Release();
                }
            }
            SetControllerFlag(bFlag);
            return;
        }
        cRZString full;
        full.Sprintf("%s_%d", mName.c_str(), static_cast<int32_t>(mnState));
        cCtrl_aa4d28* pNew = pMgr->Create(OccPartOf_aa4900(this), &full, 0);
        cCtrl_aa4d28* pOld = mpCtrl;
        if (pNew != pOld) {
            if (pNew) {
                pNew->AddRef();
            }
            mpCtrl = pNew;
            if (pOld) {
                pOld->Release();
            }
        }
    }
    SetControllerFlag(bFlag);
}
#endif

// ---- batch 7: the burnt building ----

// FUNCTION: 0x005edb10
bool cBurntIo_aa4a7c::Write(cOStream_aa4900* pStream)
{
    pStream->SetUint16(3);
    if (cPropIo_aa484c::Write(pStream)) {
        Fn005da600(pStream, reinterpret_cast<char*>(this) + 0x94);
    }
    return !pStream->GetError();
}

// FUNCTION: 0x005efba0
bool cBurntIo_aa4a7c::Read(cIStream_aa4900* pStream)
{
    uint16_t nVersion;
    pStream->GetUint16(&nVersion);
    if (nVersion != 3) {
        return false;
    }
    if (cPropIo_aa484c::Read(pStream)) {
        Fn005da5b0(pStream, reinterpret_cast<char*>(this) + 0x94);
    }
    return !pStream->GetError();
}

// FUNCTION: 0x005edc60
void cBurnt_aa4b30::Rebuild()
{
    if (!mpQuad) {
        mpQuad = static_cast<float*>(::operator new(0x50));
    }
    if (mpQuad) {
        mpQuad[1] = mBoxMin[1] + 0.1f;
        mpQuad[6] = mBoxMin[1] + 0.1f;
        mpQuad[11] = mBoxMin[1] + 0.1f;
        mpQuad[16] = mBoxMin[1] + 0.1f;
        mpQuad[0] = mBoxMin[0];
        mpQuad[2] = mBoxMin[2];
        mpQuad[5] = mBoxMax[0];
        mpQuad[7] = mBoxMin[2];
        mpQuad[10] = mBoxMax[0];
        mpQuad[12] = mBoxMax[2];
        mpQuad[15] = mBoxMin[0];
        mpQuad[17] = mBoxMax[2];
    }
    const uint32_t* pBits = reinterpret_cast<const uint32_t*>(&mBoxMin[0]);
    mCorner.v[0] = pBits[0];
    mCorner.v[1] = pBits[1];
    mCorner.v[2] = pBits[2];
    float fScale = gfB0a8d8 * 0.0625f;
    float* pCorner = reinterpret_cast<float*>(&mCorner.v[0]);
    pCorner[0] = fScale * pCorner[0];
    pCorner[1] = fScale * pCorner[1];
    pCorner[2] = fScale * pCorner[2];
}

// FUNCTION: 0x005eeb70
void cBurnt_aa4b30::SetBoundsFromOccupant(cOccupant_aa4b30* pOccupant)
{
    pOccupant->GetBoundingBox(&mBoxMin[0], &mBoxMax[0]);
    const uint32_t* pMin = reinterpret_cast<const uint32_t*>(&mBoxMin[0]);
    const uint32_t* pMax = reinterpret_cast<const uint32_t*>(&mBoxMax[0]);
    mBBoxMin.v[0] = pMin[0];
    mBBoxMin.v[1] = pMin[1];
    mBBoxMin.v[2] = pMin[2];
    mBBoxMax.v[0] = pMax[0];
    mBBoxMax.v[1] = pMax[1];
    mBBoxMax.v[2] = pMax[2];
    Rebuild();
}

// FUNCTION: 0x005efc80
cPropOcc_aa4900* Fn005efc80()
{
    return new cBurnt_aa4b30(1);
}

#ifdef OB_DRAFTS
// CLOSE: 0x005efd20 score 55
bool cBurntOcc_aa4a98::Shutdown()
{
    if (IsInitialized()) {
        Fn005e8980();
        if (mpTextures != mpTexturesEnd) {
            for (int32_t i = 0; i < 5; i++) {
                if (mpTextures[i]) {
                    mpTextures[i]->Release();
                }
            }
            mpTexturesEnd = mpTextures;
        }
        if (mpQuad) {
            operator delete(mpQuad);
            mpQuad = 0;
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005edb50 score 52
void cBurntOcc_aa4a98::SetFlags(uint32_t nFlags)
{
    if (((mnFlags2f ^ nFlags) & 2) != 0) {
        cRenderer_aa4b30* pRenderer = gpB43dd0;
        cBurnt_aa4b30* pBuilding = reinterpret_cast<cBurnt_aa4b30*>(reinterpret_cast<char*>(this) - 8);
        if (nFlags & 2) {
            if (!pRenderer->IsRegistered(pBuilding ? BurntBaseOf_aa4b30(this) : 0)) {
                pRenderer->Register(pBuilding ? BurntBaseOf_aa4b30(this) : 0);
            }
        } else if (pRenderer->IsRegistered(pBuilding ? BurntBaseOf_aa4b30(this) : 0)) {
            pRenderer->Unregister(pBuilding ? BurntBaseOf_aa4b30(this) : 0);
        }
    }
    cOccPart_aa4868::SetFlags(nFlags);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005f0600 score 76
bool cBurntOcc_aa4a98::Init()
{
    if (!IsInitialized()) {
        Fn005e8c90();
        if (mpTextures == mpTexturesEnd) {
            TexBinding_aa4b30* pNull = 0;
            FillInsert(mpTexturesEnd, 5, &pNull);
            cResHolder_aa4b30* pHolder = 0;
            cResMgr_aa4b30* pMgr = Fn008793ec();
            if (pMgr) {
                pMgr->Open(0x1ac0e11a, 0xfac0e219, &pHolder);
            }
            for (int32_t i = 0; i < 5; i++) {
                uint32_t key[3];
                key[0] = 0x7ab50e44;
                key[1] = 0x1abe787d;
                key[2] = 0xa9f0e710;
                pHolder->GetResource(key, &mpTextures[i]);
            }
        }
        mState.Pack(true, true, true, 0, 1, 1, 0, 3, 4, 5, 0xffffffff, -1.0f, true, 0xffffffff);
        if (mnFlags2e & 2) {
            reinterpret_cast<cBurnt_aa4b30*>(reinterpret_cast<char*>(this) - 8)->Rebuild();
        }
    }
    return true;
}
#endif

// ---- batch 8: the scalar deleting destructors ----

// FUNCTION: 0x005ef1c0
void* cDecal_aa4790::DeletingDestructor(uint32_t nFlags)
{
    Destroy();
    if ((nFlags & 1) && IsSet_aa4900(this)) {
        PoolNode_aa4900* pNode = reinterpret_cast<PoolNode_aa4900*>(this);
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mpFree = pNode;
        pBlock->mnCount = n;
        if (n == 0) {
            gB0a8f0.ReleaseBlock(pBlock);
        } else if (n == 0x4000004c) {
            gB0a8f0.Relink(pBlock);
        }
    }
    return this;
}

// FUNCTION: 0x005efcc0
void* cBurnt_aa4b30::DeletingDestructor(uint32_t nFlags)
{
    Destroy();
    if ((nFlags & 1) && IsSet_aa4900(this)) {
        PoolNode_aa4900* pNode = reinterpret_cast<PoolNode_aa4900*>(this);
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mpFree = pNode;
        pBlock->mnCount = n;
        if (n == 0) {
            gB0a908.ReleaseBlock(pBlock);
        } else if (n == 0x40000038) {
            gB0a908.Relink(pBlock);
        }
    }
    return this;
}

// FUNCTION: 0x005f04d0
void* cCtrlProp_aa4d28::DeletingDestructor(uint32_t nFlags)
{
    Destroy();
    if ((nFlags & 1) && IsSet_aa4900(this)) {
        PoolNode_aa4900* pNode = reinterpret_cast<PoolNode_aa4900*>(this);
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mpFree = pNode;
        pBlock->mnCount = n;
        if (n == 0) {
            gB0a914.ReleaseBlock(pBlock);
        } else if (n == 0x4000005a) {
            gB0a914.Relink(pBlock);
        }
    }
    return this;
}

// FUNCTION: 0x005f05a0
void* cVisEff_aa4ed8::DeletingDestructor(uint32_t nFlags)
{
    Destroy();
    if ((nFlags & 1) && IsSet_aa4900(this)) {
        PoolNode_aa4900* pNode = reinterpret_cast<PoolNode_aa4900*>(this);
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffc000);
        pNode->mpNext = pBlock->mpFree;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mpFree = pNode;
        pBlock->mnCount = n;
        if (n == 0) {
            gB0a8fc.ReleaseBlock(pBlock);
        } else if (n == 0x40000052) {
            gB0a8fc.Relink(pBlock);
        }
    }
    return this;
}

// ---- batch 9: the prop's own methods ----

// FUNCTION: 0x005ed400
void cPropOcc_aa4900::SetTimeOfDayRange(float fStart, float fEnd)
{
    mnTimeStart = static_cast<uint8_t>(static_cast<int32_t>(fStart * 10.0f));
    mnTimeEnd = static_cast<uint8_t>(static_cast<int32_t>(fEnd * 10.0f));
    if (fStart != fEnd && fStart >= 0.0f && fEnd >= 0.0f) {
        cClock_aa4900* pClock = gpB43dbc;
        bool bIn = false;
        float fNow = static_cast<float>(pClock->GetHour()) + static_cast<float>(pClock->GetMinute()) * 0.016666668f;
        if (fNow >= fStart && fNow <= fEnd) {
            bIn = true;
        }
        SetPropTimerState(1, bIn);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ed290 score 45
void cPropOcc_aa4900::SetState(uint32_t nState)
{
    if (mnState != nState) {
        cOccPart_aa4868* pOcc = OccPartOf_aa4900(this);
        mnState = static_cast<uint8_t>(nState);
        if (pOcc->IsInitialized()) {
            cMsg_aa4900* pMsg = new cMsg_aa4900();
            pMsg->AddRef();
            pMsg->SetType(0xe9c86ddb);
            pMsg->SetSender(this);
            pMsg->SetTarget(this);
            pMsg->SetData(nState);
            gpB43ccc->MessagePost(pMsg, false);
            pMsg->Release();
        }
        if (reinterpret_cast<cPropRole10_aa47e8*>(reinterpret_cast<char*>(this) + 0x10)->HasProperty(0x4a70d491)) {
            cModel_aa4900* pModel = pOcc->GetModel();
            if (pModel) {
                pModel->AddRef();
                uint32_t nCount = pModel->GetCount();
                if (nCount) {
                    SmallArray_aa4900 array;
                    array.mnCount = -1;
                    array.mpHeap = 0;
                    uint32_t* pItems = array.New(nCount);
                    pModel->GetInstances(reinterpret_cast<void**>(pItems), &nCount);
                    for (uint32_t i = 0; i < nCount; i++) {
                        cAnim_aa4900* pAnim;
                        if (reinterpret_cast<cModelInst_aa4900*>(pItems[i])->QueryInterface(0xa818edd8, reinterpret_cast<void**>(&pAnim))) {
                            pAnim->SetState(nState);
                            ReleaseAnim_aa4900(pAnim);
                        }
                    }
                    if (array.mnCount != -1 && array.mpHeap) {
                        operator delete(array.mpHeap);
                    }
                }
                pModel->Release();
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ecfb0 score 9
bool cPropMsg_aa48f0::DoMessage(cMsgIn_aa4900* pMessage)
{
    if (pMessage->GetType() == 0x86ad10ee) {
        cModel_aa4900* pModel = OccPartOf_aa4900(PropOfMsg_aa4900(this))->GetModel();
        if (pModel) {
            pModel->AddRef();
            uint32_t nCount = pModel->GetCount();
            if (nCount) {
                uint32_t nBits = pMessage->GetData1();
                float fDelta = gpB43d5c->GetTimeSpeed() * *reinterpret_cast<float*>(&nBits);
                SmallArray_aa4900 array;
                array.mnCount = -1;
                array.mpHeap = 0;
                uint32_t* pItems = array.New(nCount);
                pModel->GetInstances(reinterpret_cast<void**>(pItems), &nCount);
                for (uint32_t i = 0; i < nCount; i++) {
                    cAnim_aa4900* pAnim;
                    if (reinterpret_cast<cModelInst_aa4900*>(pItems[i])->QueryInterface(0xa818edd8, reinterpret_cast<void**>(&pAnim))) {
                        pAnim->Tick(fDelta);
                        ReleaseAnim_aa4900(pAnim);
                    }
                }
                if (array.mnCount != -1 && array.mpHeap) {
                    operator delete(array.mpHeap);
                }
            }
            pModel->Release();
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005eeff0 score 87
void cPropOcc_aa4900::SetSimulatorDateRange(uint32_t nStart, uint32_t nEnd, uint8_t nMonth, uint8_t nDay)
{
    if (nStart != 0) {
        if (!mpDateRange) {
            mpDateRange = new DateInfo_aa4900;
        }
        mpDateRange->mnStart = nStart;
        uint32_t nOne = 1;
        const uint32_t* pEnd = nEnd < 1 ? &nOne : &nEnd;
        mpDateRange->mnEnd = *pEnd;
        cDate_aa4900* pToday = gpB43d5c->GetDate();
        DateInfo_aa4900* pInfo = mpDateRange;
        DateIfaceOf_aa4900(&pInfo->mFirst)->Set(nMonth, nDay, pToday->GetYear());
        if (DateIfaceOf_aa4900(&mpDateRange->mFirst)->IsBefore(pToday)) {
            DateIfaceOf_aa4900(&mpDateRange->mFirst)->Set(nMonth, nDay, pToday->GetYear() + 1);
        }
        GZDate_aa4900 later;
        later.ConstructFrom(DateIfaceOf_aa4900(&mpDateRange->mFirst)->AddDays(mpDateRange->mnEnd));
        mpDateRange->mLast.mn04 = later.mn04;
        mpDateRange->mLast.mn0c = later.mn0c;
        later.Destroy();
        bool bInRange = false;
        if (pToday->IsOnOrAfter(DateIfaceOf_aa4900(&mpDateRange->mFirst)) &&
            pToday->IsAfter(DateIfaceOf_aa4900(&mpDateRange->mLast))) {
            bInRange = true;
        }
        SetPropTimerState(2, bInRange);
        return;
    }
    DateInfo_aa4900* pInfo = mpDateRange;
    if (pInfo) {
        pInfo->mLast.Destroy();
        pInfo->mFirst.Destroy();
        delete pInfo;
        mpDateRange = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ee230 score 110
void cPropOcc_aa4900::TickSimulatorDate(void* pDate)
{
    cDate_aa4900* pToday = static_cast<cDate_aa4900*>(pDate);
    if (mpDateRange && mpDateRange->mnStart != 0) {
        if (!GetPropTimerState(2)) {
            if (pToday->IsOnOrAfter(DateIfaceOf_aa4900(&mpDateRange->mFirst))) {
                SetPropTimerState(2, true);
                cDate_aa4900* pFirst = DateIfaceOf_aa4900(&mpDateRange->mFirst);
                if (mpDateRange->mnStart == 0x16d) {
                    pFirst->SetYear(pFirst->GetYear() + 1);
                } else {
                    pFirst->AddDays(mpDateRange->mnStart);
                }
            }
        } else if (pToday->IsAfter(DateIfaceOf_aa4900(&mpDateRange->mLast))) {
            SetPropTimerState(2, false);
            GZDate_aa4900 next;
            next.ConstructFrom(DateIfaceOf_aa4900(&mpDateRange->mFirst)->AddDays(mpDateRange->mnEnd));
            mpDateRange->mLast.mn04 = next.mn04;
            mpDateRange->mLast.mn0c = next.mn0c;
            next.Destroy();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005eef90 score 12
void* cPropOcc_aa4900::DeletingDestructor(uint32_t nFlags)
{
    OccPartOf_aa4900(this)->Fn005e8c40();
    if ((nFlags & 1) && IsSet_aa4900(this)) {
        PoolNode_aa4900* pNode = reinterpret_cast<PoolNode_aa4900*>(this);
        PoolBlock_aa4900* pBlock = reinterpret_cast<PoolBlock_aa4900*>(reinterpret_cast<size_t>(pNode) & 0xffffe000);
        pNode->mpNext = pBlock->mpFree;
        uint32_t n = pBlock->mnCount - 1;
        pBlock->mpFree = pNode;
        pBlock->mnCount = n;
        if (n == 0) {
            gB0a8e4.ReleaseBlock(pBlock);
        } else if (n == 0x4000003a) {
            gB0a8e4.Relink(pBlock);
        }
    }
    return this;
}
#endif

// ---- batch 10: constructors and destructor bodies (drafts: the stores of the subobjects' vtable pointers need the
// ---- class map's multi-base classes; only the field initialisation and the calls are written) ----

#ifdef OB_DRAFTS
// CLOSE: 0x005ee050 score 12
cPropOcc_aa4900::cPropOcc_aa4900()
{
    OccPartOf_aa4900(this)->Fn005e9220();
    mBoxMin[0] = 0;
    mBoxMin[1] = 0;
    mBoxMin[2] = 0;
    mBoxMax[0] = 0;
    mBoxMax[1] = 0;
    mBoxMax[2] = 0;
    mpDateRange = 0;
    mnTypeIndex = 0;
    mnOrientation = 0;
    mnState = 0;
    mn64 = 0;
    mnTimeStart = 0;
    mnTimeEnd = 0;
    mnTimerBits = 0;
    mnLotTag = 0xffffffff;
    mnOccupantType = 0xa823821e;
    mnRandomChance = 0x64;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ee360 score 30
cDecal_aa4790::cDecal_aa4790()
{
    mnDecalId = 0xffffffff;
    mKey[0] = 0;
    mKey[1] = 0;
    mKey[2] = 0;
    mfSize = 0;
    mVec2[0] = *reinterpret_cast<float*>(&gB231a0);
    mVec2[1] = *reinterpret_cast<float*>(&gB231a0);
    mpDecalMgr = 0;
    mfFadeTo = 0;
    mnFadeAction = 0;
    mbFadeRef = 0;
    mbRegistered = 0;
    mfOpacity = 1.0f;
    mfFadeFrom = 1.0f;
    mfFadeRate = 1.0f;
}
#endif

#ifdef _MSC_VER
#pragma auto_inline(off)
#endif
#ifdef OB_DRAFTS
// CLOSE: 0x005ed500 score 23
void cDecal_aa4790::Destroy()
{
    if (mpDecalMgr) {
        mpDecalMgr->Release();
    }
    OccPartOf_aa4900(this)->Fn005e8c40();
}
#endif
#ifdef _MSC_VER
#pragma auto_inline()
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005efdb0 score 7
cCtrlProp_aa4d28::cCtrlProp_aa4d28()
{
    mpCtrl = 0;
    mbFlag = false;
}
#endif

#ifdef _MSC_VER
#pragma auto_inline(off)
#endif
#ifdef OB_DRAFTS
// CLOSE: 0x005efef0 score 30
void cCtrlProp_aa4d28::Destroy()
{
    if (mpCtrl) {
        mpCtrl->Release();
    }
    OccPartOf_aa4900(this)->Fn005e8c40();
}
#endif
#ifdef _MSC_VER
#pragma auto_inline()
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005f0210 score 7
cVisEff_aa4ed8::cVisEff_aa4ed8()
{
    mpEffect = 0;
    mnEffectId = 0;
    mnNameCount = 0;
    mnIdCount = 0;
    mbStarted = 0;
    mb91 = 1;
}
#endif

#ifdef _MSC_VER
#pragma auto_inline(off)
#endif
#ifdef OB_DRAFTS
// CLOSE: 0x005f0340 score 30
void cVisEff_aa4ed8::Destroy()
{
    if (mpEffect) {
        mpEffect->Release();
    }
    OccPartOf_aa4900(this)->Fn005e8c40();
}
#endif
#ifdef _MSC_VER
#pragma auto_inline()
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ef810 score 69
cBurnt_aa4b30::cBurnt_aa4b30(int nMostDerived)
{
    mpTextures = 0;
    mpTexturesEnd = 0;
    mpTexturesCap = 0;
    mBBoxMin.v[0] = 0x3f800000;
    mBBoxMin.v[1] = 0x3f800000;
    mBBoxMin.v[2] = 0x3f800000;
    mBBoxMax.v[0] = 0;
    mBBoxMax.v[1] = 0;
    mBBoxMax.v[2] = 0;
    mpQuad = 0;
    mCorner.v[0] = gB231a0;
    mCorner.v[1] = gB231a0;
    mCorner.v[2] = gB231a0;
}
#endif

// STUB: 0x00801810
void Fn00801810(void* pVirtualBase);

#ifdef OB_DRAFTS
// CLOSE: 0x005efb20 score 50
void cBurnt_aa4b30::Destroy()
{
    if (mpTextures) {
        operator delete(mpTextures);
    }
    Fn00801810(reinterpret_cast<char*>(this) + 0x68);
    OccPartOf_aa4900(this)->Fn005e8c40();
}
#endif

// ---- batch 11: the persistence factory and the remaining drafts ----

#ifdef OB_DRAFTS
// CLOSE: 0x005ed0c0 score 4
Record_aa4900::Record_aa4900()
{
    Fn00975633(this);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005ece10 score 13
cUnk00aa44c4* Fn005ece10()
{
    return new cUnk00aa44c4();
}
#endif

// FUNCTION: 0x005ede90
bool cUnk00aa44c4::Slot09_ad8c20(uint32_t nType, uint32_t nIid, uint32_t pOut)
{
    void** ppOut = reinterpret_cast<void**>(pOut);
    if (nType == 0xa83479d3) {
        Record_aa4900* pRecord = new Record_aa4900();
        if (pRecord->QueryInterface(nIid, ppOut)) {
            return true;
        }
        pRecord->Destroy(1);
    }
    *ppOut = 0;
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005edef0 score 12
bool cUnk00aa44c4::Slot10_ad8c20(uint32_t pRecordAddr, uint32_t pSerAddr)
{
    uint8_t* pRecord = reinterpret_cast<uint8_t*>(pRecordAddr);
    cSer_aa4900* pSer = reinterpret_cast<cSer_aa4900*>(pSerAddr);
    pSer->GetUint8(pRecord + 0x18);
    pSer->GetUint8(pRecord + 0x19);
    for (int32_t i = 0; i < 4; i++) {
        pSer->GetUint8(pRecord + 0x1a + i);
    }
    float* pVec = reinterpret_cast<float*>(pRecord + 0x20);
    for (int32_t i = 0; i < 4; i++) {
        pSer->GetFloat32(pVec);
        pSer->GetFloat32(pVec + 1);
        pSer->GetFloat32(pVec + 2);
        pVec += 3;
    }
    float* pFloats = reinterpret_cast<float*>(pRecord + 0x50);
    for (int32_t i = 0; i < 4; i++) {
        pSer->GetFloat32(pFloats);
        pFloats++;
    }
    pSer->GetBytes(pRecord + 0x68, 0x50);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005edf90 score 46
bool cUnk00aa44c4::Slot11_ad8c20(uint32_t pRecordAddr, uint32_t pSerAddr)
{
    const uint8_t* pRecord = reinterpret_cast<const uint8_t*>(pRecordAddr);
    cSer_aa4900* pSer = reinterpret_cast<cSer_aa4900*>(pSerAddr);
    pSer->SetUint8(pRecord[0x18]);
    pSer->SetUint8(pRecord[0x19]);
    for (int32_t i = 0; i < 4; i++) {
        pSer->SetUint8(pRecord[0x1a + i]);
    }
    const float* pVec = reinterpret_cast<const float*>(pRecord + 0x20);
    for (int32_t i = 0; i < 4; i++) {
        pSer->SetFloat32(pVec[0]);
        pSer->SetFloat32(pVec[1]);
        pSer->SetFloat32(pVec[2]);
        pVec += 3;
    }
    const float* pFloats = reinterpret_cast<const float*>(pRecord + 0x50);
    for (int32_t i = 0; i < 4; i++) {
        pSer->SetFloat32(pFloats[i]);
    }
    pSer->SetBytes(pRecord + 0x68, 0x50);
    return true;
}
#endif

// FUNCTION: 0x005ee580
bool cDecalMsg_aa4720::DoMessage(void* pMessageRaw)
{
    cMsgIn_aa4900* pMessage = static_cast<cMsgIn_aa4900*>(pMessageRaw);
    if (pMessage->GetType() != 0x86ad10ee) {
        return false;
    }
    cDecal_aa4790* pDecal = DecalOfMsg_aa4790(this);
    uint32_t nBits = pMessage->GetData1();
    uint32_t nId = pDecal->mnDecalId;
    if (nId != 0xffffffff && (pDecal->mnFlags37 & 2) && pDecal->mfFadeRate != 0.0f) {
        float fCur = *reinterpret_cast<float*>(&nBits) * pDecal->mfFadeRate * 0.001f + pDecal->mfFadeFrom;
        pDecal->mfFadeFrom = fCur;
        if ((fCur - pDecal->mfFadeTo) * pDecal->mfFadeRate >= 0.0f) {
            switch (static_cast<int8_t>(pDecal->mnFadeAction)) {
            case 0:
                pDecal->mpDecalMgr->SetSize(nId, pDecal->mfOpacity);
                break;
            case 1:
                pDecal->mpDecalMgr->Remove(nId);
                if (pDecal->mpDecalMgr) {
                    cDecalMgr_aa4790* pMgr = pDecal->mpDecalMgr;
                    pDecal->mpDecalMgr = 0;
                    pMgr->Release();
                }
                pDecal->mnDecalId = 0xffffffff;
                break;
            case 2: {
                cOccPart_aa4868* pOcc = reinterpret_cast<cOccPart_aa4868*>(reinterpret_cast<char*>(pDecal) + 0xc);
                if (pOcc->IsInitialized()) {
                    pDecal->PlaceInOccupantManager(false);
                    pOcc->Shutdown();
                }
                break;
            }
            }
        } else {
            pDecal->mfOpacity = fCur;
            pDecal->mpDecalMgr->SetSize(nId, fCur);
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005ef5d0 score 85
bool cVisOcc_aa4de0::Init()
{
    if (!IsInitialized()) {
        cPropHolder_aa4ed8* pHolder = static_cast<cPropHolder_aa4ed8*>(GetPropertyHolder());
        std::vector<float> values;
        float size[3] = { 16.0f, 16.0f, 16.0f };
        if (Fn005ffcc0(pHolder, 0x27812810, &values) && values.size() == 3) {
            size[0] = values[0];
            size[1] = values[1];
            size[2] = values[2];
        }
        PropOf8_aa4900(this)->SetSize(size);
        mnNameCount = 0;
        mnIdCount = 0;
        if (Fn005fd570(pHolder, 0xc98204b8, &mName)) {
            mnNameCount = 1;
            uint32_t nId = 0xc98204b9;
            do {
                if (!pHolder->HasProperty(nId)) {
                    break;
                }
                mnNameCount++;
                nId++;
            } while (nId != 0xc98204c8);
            mbStarted = 1;
        } else if (Fn005fd480(pHolder, 0x2a6def88, &mnEffectId)) {
            mnIdCount = 1;
            uint32_t nId = 0x2a6def89;
            do {
                if (!pHolder->HasProperty(nId)) {
                    break;
                }
                mnIdCount++;
                nId++;
            } while (nId != 0x2a6def98);
            mbStarted = 1;
        }
        if (!IsInitialized()) {
            Fn005e8c90();
        }
        if (!mName.empty() || mnEffectId != 0) {
            VisOfOcc_aa4ed8(this)->RestartEffect();
        }
    }
    return true;
}
#endif
