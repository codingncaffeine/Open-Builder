#include <stddef.h>
#include <new>
#include <deque>
#include <list>
#include <map>
#include <math.h>

#include "classes/cSC4MySim.h"
#include "gzcom/cIGZString.h"
#include "gzcom/cRZString.h"
#include "gzcom/cIGZUnknown.h"
#include "game/Globals.h"

// ---- views ---------------------------------------------------------------------------------------------------------

#ifdef _MSC_VER
#define NOINLINE_a85218 __declspec(noinline)
#else
#define NOINLINE_a85218
#endif

struct cLocation_a85218;
class cSC4MySim;
struct cDispatch_a85218;
struct cCommuteSim_a85218;
struct Key_a85218;

// A node of the doubly linked lists the balloon queues are (a sentinel node first, the value after the two links).
struct ListNode_a85218 {
    ListNode_a85218* mpNext;
    ListNode_a85218* mpPrev;
    int32_t mnValue;
};

inline bool IsEmpty_a85218(ListNode_a85218* head)
{
    return head->mpNext == head;
}
inline int32_t Front_a85218(ListNode_a85218* head)
{
    return head->mpNext->mnValue;
}

// An element of the table of balloon advices (twelve bytes each).
struct cAdvice_a85218;
struct Advice_a85218 {
    cAdvice_a85218* mpObj;
    uint32_t mnTime;
    uint32_t mn8;
};

// The framework's streams: only the slots used here are named (cIGZOStream / cIGZIStream).
struct cOStream_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void SetSint8(int8_t value);
    virtual void SetUint8(uint8_t value);
    virtual void Pad06();
    virtual void SetUint16(uint16_t value);
    virtual void SetSint32(int32_t value);
    virtual void SetUint32(uint32_t value);
    virtual void Pad10();
    virtual void SetUint64(uint64_t value);
    virtual void SetFloat32(float value);
    virtual void Pad13();
    virtual void Pad14();
    virtual void SetGZStr(const void* pString);
    virtual void Pad16();
    virtual void Pad17();
    virtual bool GetError();
};
struct cIStream_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void GetSint8(int8_t* pValue);
    virtual void GetUint8(uint8_t* pValue);
    virtual void Pad06();
    virtual void GetUint16(uint16_t* pValue);
    virtual void GetSint32(int32_t* pValue);
    virtual void GetUint32(uint32_t* pValue);
    virtual void Pad10();
    virtual void GetUint64(uint64_t* pValue);
    virtual void GetFloat32(float* pValue);
    virtual void Pad13();
    virtual void Pad14();
    virtual void GetGZStr(void* pString);
    virtual void Pad16();
    virtual void Pad17();
    virtual bool GetError();
};

// What a model object hands out from its slot 3 (the thing its slots 18 and 70 are called on).
struct cModelPart_a85218 {
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
    virtual void Fn18(uint32_t value, uint32_t flag);
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
    virtual void Fn70();
};
struct cModel_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual cModelPart_a85218* Fn3();
    virtual void Pad04();
    virtual void Fn5();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Fn11(uint32_t value);
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Fn15(void* pPoint);
    virtual bool Fn16();
    virtual void Fn17(void* pOccupant);
    virtual void* Fn18();
};

// The sim's timer (cRZTimer): 0x18 bytes of units, start and elapsed time.
struct cTimer_a85218 {
    uint8_t mData[0x18];
    // STUB: 0x00890198
    uint32_t GetElapsedTime();
    // STUB: 0x0088ff0a
    void Reset();
    // STUB: 0x00890181
    void SetUnits(uint32_t units);
    // STUB: 0x0089045a
    void Fn0089045a(uint64_t elapsed);
    // STUB: 0x008905c4
    void Start();
    // STUB: 0x008905f0
    void Stop();
    // STUB: 0x0088fef8
    uint8_t GetUnits();
    // STUB: 0x00890279
    void Fn00890279(uint64_t* pElapsed);
    // STUB: 0x0088fefb
    bool IsTimerRunning();
};

// The city's terrain (SL::spTerrain): only the two slots used here are named.
struct cTerrain_a85218 {
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
    virtual float Fn13(float x, float z);
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
    virtual float Fn29();
};
// GLOBAL: 0x00b43cf4
extern cTerrain_a85218* gpB43cf4;

// A node of the red-black tree the grade table is (the key and the value sit after the links).
struct GradeNode_a85218 {
    uint8_t mPad00[0x10];
    uint32_t mnKey;
    uint32_t mnValue;
};
// The table of local grades (a map from a building kind to a grade), seen from its header node.
struct GradeMap_a85218 {
    GradeNode_a85218* mpHeader;
    // STUB: 0x00497520
    void Fn00497520(GradeNode_a85218** pResult, const uint32_t* pKey);
};

// The script context the sim keeps its Lua table in: only the two slots used here are named.
struct cLuaContext_a85218 {
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
    virtual void Fn43(int32_t table);
    virtual void Fn44();
    virtual void Fn45(const char* name);
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual uint32_t Fn50(uint32_t flag);
};

// What the building occupant's slot 3 hands out: the occupant, with its bounding box in slot 10.
struct cBoxOcc_a85218 : public cIGZUnknown {
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn8(float* pPosition);
    virtual void Pad09();
    virtual void Fn10(float* pMin, float* pMax);
    virtual void Fn11(float* pRect);
};
struct cBuildingOcc_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual cBoxOcc_a85218* Fn3();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual uint32_t Fn9(void* pSelf);
    // STUB: 0x00425030
    void Fn00425030(int32_t* pX, int32_t* pY);
};
// The view utilities (SL::spViewUtilities).
struct cViewUtil_a85218 {
    // STUB: 0x007f78e0
    void Fn007f78e0(float* pPoint);
};
// GLOBAL: 0x00b43dd8
extern cViewUtil_a85218* gpB43dd8;

// The sim's ambient sound prop and what its slot 3 hands out.
struct cHomeSoundOcc_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Fn9(const float* pPosition);
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
    virtual bool Fn32(bool flag);
};
struct cHomeSound_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual cHomeSoundOcc_a85218* Fn3();
};
// The prop manager (SL::spPropManager).
struct cPropMgr_a85218 {
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
    virtual bool Fn16(const Key_a85218* pKey, void** ppOut);
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
    virtual void Fn29(void* pOccupant);
};
// GLOBAL: 0x00b43d10
extern cPropMgr_a85218* gpB43d10;

// A rectangle of the dispatch manager's records.
struct Rect_a85218 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
};
// The record table behind the dispatch manager's slot 22 (a map by id; the end node is at +0x48).
struct cDispRecords_a85218 {
    uint8_t mPad00[0x48];
    void* mpEnd;              // 0x48
    // STUB: 0x0046be40
    void Fn0046be40(void** pResult, uint32_t id);
    Rect_a85218* Fn0046bfa0(uint32_t id);
};
struct cDispMgr_a85218 {
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
    virtual cDispRecords_a85218* Fn22();
};
// GLOBAL: 0x00b43d04
extern cDispMgr_a85218* gpB43d04;

// The traffic simulator (SL::spTrafficSim): slot 6 hands out the traffic network.
struct cTrafficSim_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Fn6(void** ppOut);
};
// GLOBAL: 0x00b43da8
extern cTrafficSim_a85218* gpB43da8;

// The 3D view (SL::spView3D): only the slot that takes the new dispatch tool is named.
struct cView3D_a85218 {
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
    virtual cDispatch_a85218* Fn24();
    virtual void Fn25(cDispatch_a85218* pTool, uint32_t mode);
    virtual void Fn26(uint32_t flag);
};
// GLOBAL: 0x00b43dc4
extern cView3D_a85218* gpB43dc4;
// GLOBAL: 0x00b20e0c
extern cDispatch_a85218* gpB20e0c;

// STUB: 0x00603040
void SC4LoadString(cIGZString* pString, uint32_t group, uint32_t instance, void* pDetokenizer);

template <class T>
inline void ResetRef_a85218(T*& ref)
{
    T* old = ref;
    if (old) {
        ref = 0;
        old->Release();
    }
}

inline void ResetRef_a85218(void*& ref)
{
    cIGZUnknown* old = static_cast<cIGZUnknown*>(ref);
    if (old) {
        ref = 0;
        old->Release();
    }
}

// The sim's place (cSC4MySimDispatch::cLocation): a ref-counted occupant and where it is.
struct cLocation_a85218 {
    cIGZUnknown* mpOccupant;  // 0x00
    float mfX;                // 0x04
    float mfZ;                // 0x08
    int32_t mnCellX;          // 0x0c
    int32_t mnCellZ;          // 0x10
    uint32_t mn14;            // 0x14
    uint32_t mn18;            // 0x18
    uint8_t mbSet;            // 0x1c
    bool mbFlag1d;            // 0x1d
    uint8_t mPad1e[2];        // 0x1e
    uint32_t mn20;            // 0x20
    uint32_t mn24;            // 0x24
    cLocation_a85218() {}
    // STUB: 0x00431320
    void Fn00431320();
    // STUB: 0x00425890
    cLocation_a85218(const cLocation_a85218& other);
    ~cLocation_a85218()
    {
        if (mpOccupant) {
            mpOccupant->Release();
        }
    }
    // STUB: 0x00425f80
    cLocation_a85218& operator=(const cLocation_a85218& other);
    // STUB: 0x00434f90
    bool IsValid() const;
    // STUB: 0x00431430
    bool SetByOccupant(void* pOccupant);
    NOINLINE_a85218 bool Fn004311e0();
    NOINLINE_a85218 uint32_t Fn00431640(const cLocation_a85218& other) const;
};

// The third reference of the dispatch tool and what its slot 3 hands out.
struct cRef1cPart_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn5();
};
struct cRef1c_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual cRef1cPart_a85218* Fn3();
};

// The key frames of the dispatch tool (a map from an id to four words).
struct KeyFrame_a85218 {
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    uint32_t mnW;
};
struct cKeyMap_a85218 {
    std::map<int32_t, KeyFrame_a85218> mMap;
    // STUB: 0x00434f00
    NOINLINE_a85218 KeyFrame_a85218* Fn00434f00(const int32_t& key);
};

struct cAutomaton_a85218 : public cIGZUnknown {
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
    virtual bool Fn31(uint32_t flag);
};
// The sim's dispatch tool (cSC4MySimDispatch), pointed at from +0x20c of the sim.
struct cDispatch_a85218 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual bool Fn3();
    virtual void Pad04();
    virtual void Pad05();
    virtual bool Fn6();
    virtual bool Fn7();
    virtual bool Fn8();
    uint8_t mPad04[0x0c];
    uint8_t mbFollowCamera;   // 0x10
    uint8_t mPad11[3];
    cIGZUnknown* mpRef14;     // 0x14
    cIGZUnknown* mpRef18;     // 0x18
    cRef1c_a85218* mpRef1c;   // 0x1c
    uint8_t mPad20[0x14];
    uint32_t mn34;            // 0x34
    uint8_t mPad38[4];
    uint32_t mnTrackHandle;   // 0x3c
    uint32_t mnState40;       // 0x40
    uint8_t mPad44[4];
    uint32_t mnFlags;         // 0x48
    uint8_t mPad4c[8];
    uint8_t mbFlag54;         // 0x54
    uint8_t mPad55[7];
    cLocation_a85218 mLoc5c;  // 0x5c
    cLocation_a85218 mLoc84;  // 0x84
    uint8_t mPadAc[0x28];
    cLocation_a85218 mLocD4;  // 0xd4
    uint8_t mPadFc[0x1c];
    cIGZUnknown* mpOwner118;  // 0x118
    uint8_t mPad11c[4];
    cIGZUnknown* mpRef120;    // 0x120
    cIGZUnknown* mpRef124;    // 0x124
    uint8_t mPad128[0x28];
    cKeyMap_a85218 mKeys;     // 0x150
    uint8_t mPad15c[4];
    std::deque<cLocation_a85218> mQueue;  // 0x160
    uint8_t mbFlag188;        // 0x188
    // STUB: 0x00431f70
    void Fn00431f70();
    // STUB: 0x00432ee0
    void Fn00432ee0();
    // STUB: 0x00433eb0
    bool Fn00433eb0();
    // STUB: 0x004365c0
    void Fn004365c0();
    // STUB: 0x004320d0
    void Fn004320d0();
    // STUB: 0x00437130
    bool GoTo(const cLocation_a85218& location);
    // STUB: 0x004312b0
    cLocation_a85218* Fn004312b0();
    // STUB: 0x004312a0
    cLocation_a85218* Fn004312a0();
    // STUB: 0x00431c70
    void Fn00431c70();
    // STUB: 0x0068d1b0
    uint32_t Fn0068d1b0();
    // STUB: 0x00431290
    cLocation_a85218* Fn00431290();
    // STUB: 0x00698cd0
    cLocation_a85218* Fn00698cd0();
    // STUB: 0x00439e50
    cDispatch_a85218* Fn00439e50(cSC4MySim* pOwner);
    // STUB: 0x00435610
    uint32_t Fn00435610(uint32_t id, cRZString* pName);
    // STUB: 0x00434080
    bool Fn00434080();
    // STUB: 0x00434ba0
    NOINLINE_a85218 bool Fn00434ba0(const cLocation_a85218& location, uint32_t flags);
    // STUB: 0x00431a30
    void Fn00431a30(uint32_t id, uint32_t a, uint32_t b, uint32_t c);
    // STUB: 0x00432f50
    bool Fn00432f50(const cLocation_a85218& location);
    // STUB: 0x00434670
    NOINLINE_a85218 bool Fn00434670();
    // STUB: 0x004350d0
    NOINLINE_a85218 bool SetCurrentCommuteDestination(const cLocation_a85218& location, bool flag);
    uint32_t Fn00431260(uint32_t mask);
    bool Fn004317f0(void** ppOut);
    // STUB: 0x00430530
    NOINLINE_a85218 bool Fn00430530();
    // STUB: 0x00434ff0
    NOINLINE_a85218 bool Fn00434ff0(int32_t key, const uint32_t* pVec, uint32_t w);
    // STUB: 0x00435030
    NOINLINE_a85218 bool Fn00435030(const cLocation_a85218& location);
};

// What an advice's slot 4 hands out (its slot 16 gives a time).
struct cOccupant2_a85218 {
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
    virtual uint32_t Fn16();
};
// An advice (balloon) object the sim keeps in its table: only the slots used here are named.
struct cAdvice_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual cOccupant2_a85218* Fn4();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual bool Fn12();
    virtual void Fn13(uint32_t a, uint32_t b);
    virtual bool Fn14(uint32_t kind);
};

// A zone/building record: its slot 11 points at the kind.
struct cBuilding2_a85218 {
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
    virtual int32_t* Fn11();
};

// The standard message object (0x2c bytes): only the slots used here are named.
struct cMessage_a85218 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn5(uint32_t type);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Fn11(uint32_t value);
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Fn16(uint32_t value);
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
    virtual void Fn33(void* pObject);
    // STUB: 0x009134d6
    cMessage_a85218* Fn009134d6();
};
// STUB: 0x009133da
void* Fn009133da(uint32_t size);

// The service registry (found by the same call everywhere): slot 3 hands out an object by class and interface id.
struct Registry_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual bool Fn3(uint32_t classId, uint32_t interfaceId, void** ppOut);
};
// STUB: 0x0090ddf1
Registry_a85218* Fn0090ddf1();

// A counted reference held in a local: the address handed out first lets go of what it held.
struct Ref_a85218 {
    cIGZUnknown* mp;
    Ref_a85218() : mp(0) {}
    ~Ref_a85218()
    {
        if (mp) {
            mp->Release();
        }
    }
    void** AddressOf()
    {
        if (mp) {
            cIGZUnknown* old = mp;
            mp = 0;
            old->Release();
        }
        return reinterpret_cast<void**>(&mp);
    }
};

// The disaster effect object the registry hands out.
struct cDisaster_a85218 : public cIGZUnknown {
    virtual void Fn3(float a, float b);
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Fn7(void* pBuilding);
    virtual void Pad08();
    virtual void Pad09();
    virtual void Fn10(int32_t distance);
};

// What the building list's records answer for an occupant type.
struct cOccType_a85218 : public cIGZUnknown {
    virtual void Pad03();
    virtual uint32_t Fn4();
};

// The city (SL::spCity), only the slots used here, with their types.
struct cBldgSim_a85218 {
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
    virtual std::list<cBoxOcc_a85218*>* Fn44();
};
struct cPedMgr_a85218;
struct cOccMgr2_a85218 {
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
    virtual void Fn20(void* pOccupant, uint32_t flag);
};
struct cCity_a85218 {
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
    virtual cOccMgr2_a85218* Fn34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual cPedMgr_a85218* Fn44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual cBldgSim_a85218* Fn53();
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
    virtual cCommuteSim_a85218* Fn69();
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
    virtual void Pad93();
    virtual void Pad94();
    virtual void Pad95();
    virtual void Pad96();
    virtual void Fn97(int32_t a, int32_t b, float* pX, float* pZ);
};
// GLOBAL: 0x00b43cec
extern cCity_a85218* gpB43cec_a85218;

// A resource key: type, group, instance.
struct Key_a85218 {
    uint32_t mnType;
    uint32_t mnGroup;
    uint32_t mnInstance;
};


// The tick manager (SL::ATM()): only the slot that drops a target is named.
struct cATM_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn5(void* pTarget, uint32_t mask);
    virtual void Fn6(void* pTarget, uint32_t mask);
};
// STUB: 0x00602600
cATM_a85218* Fn00602600();

// The game application (SL::spSC4): slot 61 fills in the city's name.
struct cApp_a85218 {
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
    virtual void Fn61(cRZString* pName);
};
// GLOBAL: 0x00b43c94
extern cApp_a85218* gpB43c94;

// The lot manager (SL::spLotManager) and the lot it hands out.
struct cLotItem_a85218 : public cIGZUnknown {
    virtual cIGZUnknown* Fn3();
};
struct cLot_a85218 {
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
    virtual uint32_t Fn41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual cLotItem_a85218* Fn48();
};
struct cLotMgr_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual cLot_a85218* Fn6(int32_t x, int32_t z, uint32_t flag);
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual cLot_a85218* Fn14(void* pOccupant);
};
// GLOBAL: 0x00b43d08
extern cLotMgr_a85218* gpB43d08;

// The object that tests whether a building can be a home (0x10 bytes).
struct cTester_a85218 : public cIGZUnknown {
    virtual bool Fn3(void* pOccupant);
    // STUB: 0x00424ab0
    cTester_a85218* Fn00424ab0(uint32_t flag);
};

// An exemplar: slot 6 hands out its property list.
struct cExemplar_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void* Fn6();
};
// STUB: 0x005fd5b0
bool Fn005fd5b0(void* pProperties, uint32_t id, float* pOut);
// STUB: 0x005fd450
bool Fn005fd450(void* pProperties, uint32_t id, uint32_t* pOut);
// The resource manager (SL::spRM): slot 3 loads a resource.
struct cResMgr_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual bool Fn3(const void* pKey, uint32_t type, void** ppOut, uint32_t a, uint32_t b);
};
// GLOBAL: 0x00b43ca8
extern cResMgr_a85218* gpB43ca8;
// GLOBAL: 0x00b07d8c
extern float g00b07d8c[3];

// The pedestrian manager and the pedestrian it creates.
struct cPed_a85218 : public cIGZUnknown {
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
    virtual void Fn13(uint32_t flag);
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
    virtual void Pad93();
    virtual void Pad94();
    virtual void Pad95();
    virtual float* Fn96(float* pTemp, uint32_t flag);
};
struct cPedMgr_a85218 {
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
    virtual cPed_a85218* Fn15(uint32_t type, const float* pPosition, uint32_t a, float* pOut, uint32_t b, uint32_t c, uint32_t d);
};

// The clock (SL::sp24HourClock): slot 10 gives the hour.
struct cClock_a85218 {
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
    virtual int32_t Fn10();
};
// GLOBAL: 0x00b43dbc
extern cClock_a85218* gpB43dbc;
// GLOBAL: 0x00b07d98
extern float g00b07d98[3];

// The system services (found by a call): slot 5 hands out a service by class and interface id.
struct cSysServ_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn5(uint32_t classId, uint32_t interfaceId, void** ppOut);
};
// STUB: 0x008793ec
cSysServ_a85218* Fn008793ec();
// The window manager: slot 42 tells whether input is blocked.
struct cWinMgr_a85218 : public cIGZUnknown {
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
    virtual bool Fn42();
};

// A rectangle of four words passed by value to the commute route.
struct Span_a85218 {
    uint32_t mn0;
    uint32_t mn1;
    uint32_t mn2;
    uint32_t mn3;
};
// The route a commute is computed on (from the city's commute simulator, slot 6).
struct cRoute_a85218 : public cIGZUnknown {
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn5(uint32_t a);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Fn9(uint32_t a);
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Fn18(uint32_t a);
    virtual void Fn19(Span_a85218 from);
    virtual void Fn20(Span_a85218 to);
    virtual void Pad21();
    virtual void Pad22();
    virtual uint32_t Fn23();
    virtual void Pad24();
    virtual void Pad25();
    virtual float Fn26();
};
struct cCommuteSim_a85218 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Fn6(cRoute_a85218** ppRoute);
};

// The pylon occupant the dispatch tool places: only the slots used here are named.
struct cPylon_a85218 : public cIGZUnknown {
    virtual cHomeSoundOcc_a85218* Fn3();
    virtual void Fn4();
    virtual void Pad05();
    virtual void Fn6(uint32_t value);
    virtual void Pad07();
    virtual void Fn8(uint32_t id, cRZString* pName);
    virtual void Fn9(uint32_t value);
    virtual void Pad10();
    virtual void Fn11(uint32_t value);
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Fn19(void* pTool);
    // STUB: 0x005f1730
    cPylon_a85218* Fn005f1730(uint32_t flag);
};

struct cAutomaton2_a85218 : public cIGZUnknown {
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
    virtual void Fn13(uint32_t value);
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
    virtual void Fn40(void* pTarget);
};
// ---- methods ---------------------------------------------------------------------------------------------------------

// FUNCTION: 0x004311e0
bool cLocation_a85218::Fn004311e0()
{
    return mbFlag1d = true;
}

// FUNCTION: 0x00449550
bool cSC4MySim::Slot20_a84c10()
{
    return mnState != 0;
}

// FUNCTION: 0x004275e0
void cSC4MySim::Slot60_a84c10()
{
    Fn00427540(2);
}

// FUNCTION: 0x004275f0
void cSC4MySim::Slot61_a84c10()
{
    Fn00427540(1);
}

// FUNCTION: 0x00426570
void cSC4MySim::DispatchToolSetFollowCamera(uint32_t a)
{
    static_cast<cDispatch_a85218*>(mpDispatch)->mbFollowCamera = static_cast<uint8_t>(a);
}

// FUNCTION: 0x00431260
uint32_t cDispatch_a85218::Fn00431260(uint32_t mask)
{
    return (mnFlags & mask) != 0;
}

// FUNCTION: 0x00425dd0
uint32_t cSC4MySim::Slot25_a84c10()
{
    uint32_t name = mnHomeName;
    if (!name) {
        name = mnUnknownName;
    }
    return name;
}

// FUNCTION: 0x00429c90
uint32_t cSC4MySim::Slot03_a84c10()
{
    return OB_ADDR(static_cast<cUnk00a81120*>(this));
}

// FUNCTION: 0x00426950
uint32_t cSC4MySim::get_track_handle()
{
    if (mpDispatch) {
        return static_cast<cDispatch_a85218*>(mpDispatch)->mnTrackHandle;
    }
    return mnTrackHandle;
}

// FUNCTION: 0x00426a00
bool cSC4MySim::Slot64_a84c10()
{
    if (mnState) {
        return static_cast<cDispatch_a85218*>(mpDispatch)->Fn6();
    }
    return false;
}

// FUNCTION: 0x00426a20
bool cSC4MySim::Slot65_a84c10()
{
    if (Slot64_a84c10()) {
        return static_cast<cDispatch_a85218*>(mpDispatch)->Fn7();
    }
    return false;
}

// FUNCTION: 0x00426a40
bool cSC4MySim::Slot66_a84c10()
{
    if (mnState) {
        return static_cast<cDispatch_a85218*>(mpDispatch)->Fn8();
    }
    return false;
}

// FUNCTION: 0x00424c80
void cSC4MySim::Slot15_a84c10(uint32_t a)
{
    float* out = OB_PTR(float, a);
    out[0] = mfLocX;
    out[1] = mfLocY;
    out[2] = mfLocZ;
}

// FUNCTION: 0x00426460
void cSC4MySim::Slot49_a84c10(uint32_t /*a*/, uint32_t /*b*/)
{
    if (mnState) {
        if (mpJobOther) {
            mbNeighborConnectionRemoved = true;
        }
    }
}

// FUNCTION: 0x00429cb0
uint32_t cSC4MySim::Slot59_a84c10(uint32_t a)
{
    if (static_cast<uint8_t>(a)) {
        return mnModelButtonBitmapA;
    }
    return mnModelButtonBitmapB;
}

// FUNCTION: 0x00425f00
void cSC4MySim::Slot36_a84c10(uint32_t a)
{
    cModel_a85218* pylon = static_cast<cModel_a85218*>(mpPylon);
    if (pylon) {
        pylon->Fn3()->Fn18(a, 1);
    }
}

// FUNCTION: 0x004288d0
void cSC4MySim::Slot35_a84c10()
{
    static_cast<cDispatch_a85218*>(mpDispatch)->Fn00431f70();
    Fn00427690();
    mbLocationShown = false;
}

// FUNCTION: 0x0042c020
void cSC4MySim::Slot43_a84c10(uint32_t a)
{
    if (mnState) {
        if (a == OB_ADDR(mpResidence) || a == OB_ADDR(mpJobBuilding)) {
            UpdateVariables();
        }
    }
}

// FUNCTION: 0x00426ec0
void cSC4MySim::Slot54_a84c10()
{
    if (mnState == 2) {
        PlayHomeSound(mbMale ? 0x6a5fc4f2 : 0x4a5fc52a);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00427410 score 8
uint32_t cSC4MySim::Slot62_a84c10()
{
    ListNode_a85218* head = static_cast<ListNode_a85218*>(mpBalloonList);
    uint32_t result = 0;
    if (!IsEmpty_a85218(head)) {
        result = OB_ADDR(static_cast<Advice_a85218*>(mpBalloonAdvices)[Front_a85218(head)].mpObj);
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00427440 score 8
uint32_t cSC4MySim::Slot63_a84c10()
{
    ListNode_a85218* head = static_cast<ListNode_a85218*>(mpBalloonEventList);
    uint32_t result = 0;
    if (!IsEmpty_a85218(head)) {
        result = OB_ADDR(static_cast<Advice_a85218*>(mpBalloonAdvices)[Front_a85218(head)].mpObj);
    }
    return result;
}
#endif

// FUNCTION: 0x00425e70
void cSC4MySim::Slot33_a84c10()
{
    cModel_a85218* model = static_cast<cModel_a85218*>(mpResidenceModel);
    if (model) {
        model->Fn3()->Fn70();
    }
    mbResidenceShown = false;
}

// GetAge in the reference build
// FUNCTION: 0x00424cb0
uint8_t cSC4MySim::Slot17_a84c10()
{
    return mnAge;
}

// FUNCTION: 0x00424cd0
bool cSC4MySim::Slot29_a84c10(uint32_t a)
{
    cIGZString* text = OB_PTR(cIGZString, a);
    text->Sprintf("%d", static_cast<int32_t>(mfEQ));
    return true;
}

// FUNCTION: 0x004317f0
bool cDispatch_a85218::Fn004317f0(void** ppOut)
{
    *ppOut = 0;
    cIGZUnknown* owner = mpOwner118;
    if (owner) {
        if (owner->QueryInterface(0xa9b40f05, ppOut)) {
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x005da070
cIStream_a85218* Fn005da070(cIStream_a85218* pStream, uint32_t* pKey)
{
    pStream->GetUint32(pKey);
    pStream->GetUint32(pKey + 1);
    pStream->GetUint32(pKey + 2);
    return pStream;
}

inline bool PairEqual_a85218(const uint32_t* a, const uint32_t* b)
{
    return a[0] == b[0] && a[1] == b[1];
}

// FUNCTION: 0x007aa8e0
bool Fn007aa8e0(const uint32_t* a, const uint32_t* b)
{
    return !PairEqual_a85218(a, b);
}

// FUNCTION: 0x00424de0
bool cSC4MySim::Slot56_a84c10()
{
    uint32_t now = reinterpret_cast<cTimer_a85218*>(mTimer)->GetElapsedTime();
    if (mnState) {
        if (now - mnLastSoundTime > 4) {
            mnLastSoundTime = now;
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x00424da0
bool cSC4MySim::Slot19_a81120(uint32_t a)
{
    if (mnState) {
        Slot68_a84c10();
        return cSC4Advisor::Slot19_a81120(a);
    }
    return false;
}

// FUNCTION: 0x00425df0
uint32_t cSC4MySim::Slot26_a84c10()
{
    if (mbRetired) {
        return mnRetiredName;
    }
    if (!mpJobBuilding) {
        if (!mpJobOther) {
            return mnUnemployedName;
        }
    }
    uint32_t name = mnJobName;
    if (!name) {
        name = mnUnknownName;
    }
    return name;
}

// FUNCTION: 0x00425e30
uint32_t cSC4MySim::Slot28_a84c10()
{
    if (mbRetired) {
        return mnRetiredName;
    }
    if (!mpJobBuilding) {
        if (!mpJobOther) {
            return mnUnemployedName;
        }
    }
    uint32_t name = mnJobTitle;
    if (!name) {
        name = mnUnknownName;
    }
    return name;
}

inline void CopyTrackHandle_a85218(cSC4MySim* self)
{
    self->mnTrackHandle = static_cast<cDispatch_a85218*>(self->mpDispatch)->mnTrackHandle;
}

// FUNCTION: 0x00426f60
void cSC4MySim::Slot39_a84c10()
{
    if (mnState == 3 || mnState == 4) {
        if (DispatchCommute()) {
            mnState = 5;
            CopyTrackHandle_a85218(this);
        }
    }
}

// FUNCTION: 0x00427600
uint32_t cSC4MySim::Slot50_a84c10(uint32_t a)
{
    if (mnState) {
        GradeMap_a85218* map = static_cast<GradeMap_a85218*>(mpGradeMap);
        if (map) {
            GradeNode_a85218* node;
            map->Fn00497520(&node, &a);
            if (node != map->mpHeader) {
                return node->mnValue;
            }
        }
    }
    return 0xffffffff;
}

// FUNCTION: 0x00429040
void cSC4MySim::CreateLuaTable()
{
    cLuaContext_a85218* lua = static_cast<cLuaContext_a85218*>(mpLuaContext);
    if (lua) {
        lua->Fn44();
        mnLuaTable = static_cast<cLuaContext_a85218*>(mpLuaContext)->Fn50(1);
        UpdateTripVariables(-1, -1, -1, -1, true);
    }
}

// FUNCTION: 0x00426580
bool cSC4MySim::DispatchToolCanDispatch(float x, float z)
{
    cTerrain_a85218* terrain = gpB43cf4;
    if (terrain) {
        float height = terrain->Fn13(x, z);
        return terrain->Fn29() < height;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004259e0 score 4
bool cSC4MySim::is_pylon_location(void* pLocation)
{
    cModel_a85218* pylon = static_cast<cModel_a85218*>(mpPylon);
    if (pylon) {
        if (mbPylonValid) {
            cLocation_a85218* loc = static_cast<cLocation_a85218*>(pLocation);
            void* first = loc->mpOccupant;
            if (first == pylon->Fn3()) {
                return true;
            }
            void* second = loc->mpOccupant;
            if (second == static_cast<cModel_a85218*>(mpPylon)->Fn18()) {
                return true;
            }
        }
    }
    return false;
}
#endif

// FUNCTION: 0x00426480
bool cSC4MySim::Fn00426480()
{
    cModel_a85218* pylon = static_cast<cModel_a85218*>(mpPylon);
    if (pylon) {
        pylon->Fn5();
        pylon = static_cast<cModel_a85218*>(mpPylon);
        if (pylon) {
            mpPylon = 0;
            pylon->Release();
        }
        mbPylonValid = false;
    }
    return true;
}

// FUNCTION: 0x00427690
void cSC4MySim::Fn00427690()
{
    for (int32_t i = 1000; i != 0; --i) {
        if (!Fn00427490(1, 0xffff)) {
            break;
        }
    }
    for (int32_t j = 1000; j != 0; --j) {
        if (!Fn00427490(2, 0xffff)) {
            break;
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00424b00 score 32
bool cSC4MySim::QueryInterface(unsigned int riid, void** ppvObj)
{
    *ppvObj = 0;
    switch (riid) {
    case 0x0a1da42f:
        *ppvObj = static_cast<cUnk00a84c10*>(this);
        break;
    case 0x8bc01ffe:
        *ppvObj = this;
        break;
    default:
        return cSC4Advisor::QueryInterface(riid, ppvObj);
    }
    AddRef();
    return true;
}
#endif

// FUNCTION: 0x00426000
void cSC4MySim::RemoveHomeSound()
{
    cHomeSound_a85218* sound = static_cast<cHomeSound_a85218*>(mpHomeSound);
    if (sound) {
        if (sound->Fn3()->Fn32(true)) {
            cPropMgr_a85218* mgr = gpB43d10;
            if (mgr) {
                mgr->Fn29(static_cast<cHomeSound_a85218*>(mpHomeSound)->Fn3());
            }
        }
        sound = static_cast<cHomeSound_a85218*>(mpHomeSound);
        if (sound) {
            mpHomeSound = 0;
            sound->Release();
        }
    }
}

// FUNCTION: 0x00426ba0
bool cSC4MySim::Fn00426ba0()
{
    if (mpResidence) {
        ResetRef_a85218(mpResidence);
        cModel_a85218* model = static_cast<cModel_a85218*>(mpResidenceModel);
        if (model) {
            model->Fn3()->Fn70();
        }
        RemoveHomeSound();
    }
    ResetRef_a85218(mpWorkRef);
    mbLocationShown = false;
    return true;
}

// FUNCTION: 0x00429830
bool cSC4MySim::Slot68_a84c10()
{
    if (mpLuaContext) {
        if (mnLuaTable == 0) {
            CreateLuaTable();
        }
        if (mnLuaTable > 0) {
            static_cast<cLuaContext_a85218*>(mpLuaContext)->Fn43(mnLuaTable);
            static_cast<cLuaContext_a85218*>(mpLuaContext)->Fn45("mysim");
            return true;
        }
    }
    return false;
}

inline uint32_t VoiceOf_a85218(cSC4MySim* self)
{
    return self->mbMale ? 0x2a5f9cdc : 0x6a5fb141;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00426ef0 score 2
void cSC4MySim::Slot38_a84c10()
{
    if (mnState == 2 || mnState == 1 || mnState == 5) {
        if (DispatchCommute()) {
            mnState = 4;
            CopyTrackHandle_a85218(this);
        } else {
            PlayHomeSound(VoiceOf_a85218(this));
        }
    }
}
#endif

// FUNCTION: 0x00425d70
bool cSC4MySim::Slot08_a84c10(uint32_t a)
{
    cLocation_a85218 loc;
    loc.Fn00431320();
    loc.SetByOccupant(OB_PTR(cBuildingOcc_a85218, a)->Fn3());
    cDispatch_a85218* dispatch = static_cast<cDispatch_a85218*>(mpDispatch);
    loc.mbFlag1d = true;
    return dispatch->SetCurrentCommuteDestination(loc, true);
}

// FUNCTION: 0x00424d00
bool cSC4MySim::Slot30_a84c10(uint32_t a)
{
    if (!mnState) {
        return false;
    }
    cIGZString* text = OB_PTR(cIGZString, a);
    if (mfHQ < 50.0f) {
        SC4LoadString(text, 0xea5524eb, 0x0a5fe2df, 0);
        return true;
    }
    if (mfHQ < 100.0f) {
        SC4LoadString(text, 0x6a231eaa, 0xaa317340, 0);
        return true;
    }
    SC4LoadString(text, 0xea5524eb, 0x6a5fe294, 0);
    return true;
}

// FUNCTION: 0x004265d0
bool cSC4MySim::Slot14_a84c10(uint32_t a)
{
    cDispatch_a85218* dispatch = static_cast<cDispatch_a85218*>(mpDispatch);
    if (dispatch) {
        cLocation_a85218 loc(*dispatch->Fn00698cd0());
        if (loc.mnCellX >= 0 && loc.mnCellZ >= 0) {
            float* out = OB_PTR(float, a);
            out[0] = loc.mfX;
            out[1] = 0;
            out[2] = loc.mfZ;
            cTerrain_a85218* terrain = gpB43cf4;
            if (terrain) {
                out[1] = terrain->Fn13(loc.mfX, loc.mfZ);
            }
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x00426830
bool cSC4MySim::Slot67_a84c10()
{
    void* raw = operator new(0x90);  // the original allocates 0x90: the view type is wider
    cDispatch_a85218* mem = static_cast<cDispatch_a85218*>(raw);
    cDispatch_a85218* tool = mem ? mem->Fn00439e50(this) : 0;
    if (tool) {
        tool->AddRef();
    }
    if (tool->Fn3()) {
        gpB43dc4->Fn25(tool, 2);
        cDispatch_a85218* old = gpB20e0c;
        if (tool != old) {
            tool->AddRef();
            gpB20e0c = tool;
            if (old) {
                old->Release();
            }
        }
        tool->Release();
        return true;
    }
    tool->Release();
    return false;
}

// FUNCTION: 0x0046bfa0
Rect_a85218* cDispRecords_a85218::Fn0046bfa0(uint32_t id)
{
    void* node;
    Fn0046be40(&node, id);
    if (node != mpEnd) {
        Rect_a85218* rect = reinterpret_cast<Rect_a85218*>(static_cast<uint8_t*>(node) + 0xec);
        if (rect->mnRight - rect->mnLeft != 0 && rect->mnBottom - rect->mnTop != 0) {
            return rect;
        }
    }
    return 0;
}

// FUNCTION: 0x00425f20
bool cSC4MySim::Slot55_a84c10(uint32_t a, uint32_t b)
{
    uint32_t handle = get_track_handle();
    if (handle != 0xffffffff) {
        cDispRecords_a85218* records = gpB43d04->Fn22();
        if (records) {
            Rect_a85218* rect = records->Fn0046bfa0(handle);
            if (rect) {
                int32_t left = rect->mnLeft;
                *OB_PTR(int32_t, a) = left + (rect->mnRight - left) / 2;
                *OB_PTR(int32_t, b) = rect->mnTop + 25;
                return true;
            }
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00425030 score 37
void cBuildingOcc_a85218::Fn00425030(int32_t* pX, int32_t* pY)
{
    cViewUtil_a85218* view = gpB43dd8;
    float lo[2];
    float hi[2];
    Fn3()->Fn10(lo, hi);
    view->Fn007f78e0(lo);
    view->Fn007f78e0(hi);
    *pX = static_cast<int32_t>((lo[0] + hi[0]) * 0.5f);
    if (lo[1] < hi[1]) {
        hi[1] = lo[1];
    }
    *pY = static_cast<int32_t>(hi[1] - 5.0f);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00425ea0 score 28
void cSC4MySim::Slot37_a84c10()
{
    if (mnState) {
        if (mpResidence) {
            if (mpResidenceModel) {
                int32_t point[2];
                static_cast<cBuildingOcc_a85218*>(mpResidence)->Fn00425030(&point[0], &point[1]);
                static_cast<cModel_a85218*>(mpResidenceModel)->Fn15(point);
            }
        }
    }
}
#endif

// STUB: 0x00424ec0
bool Fn00424ec0(const uint32_t* a, const uint32_t* b);
// STUB: 0x00424fe0
void Fn00424fe0();

// FUNCTION: 0x00431640
uint32_t cLocation_a85218::Fn00431640(const cLocation_a85218& other) const
{
    if (mbSet == other.mbSet && mpOccupant == other.mpOccupant && mbFlag1d == other.mbFlag1d &&
        mnCellX == other.mnCellX && mnCellZ == other.mnCellZ && Fn00424ec0(&mn14, &other.mn14)) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00430530
bool cDispatch_a85218::Fn00430530()
{
    if (mbFlag54) {
        ResetRef_a85218(mpRef14);
        ResetRef_a85218(mpRef18);
        if (mpRef1c) {
            mpRef1c->Fn3()->Fn5();
            ResetRef_a85218(mpRef1c);
        }
        mbFlag54 = false;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00434f00 score 57
KeyFrame_a85218* cKeyMap_a85218::Fn00434f00(const int32_t& key)
{
    return &mMap[key];
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00434ff0 score 12
bool cDispatch_a85218::Fn00434ff0(int32_t key, const uint32_t* pVec, uint32_t w)
{
    uint32_t x = pVec[0];
    uint32_t y = pVec[1];
    uint32_t z = pVec[2];
    KeyFrame_a85218* frame = mKeys.Fn00434f00(key);
    frame->mnX = x;
    frame->mnY = y;
    frame->mnZ = z;
    frame->mnW = w;
    return true;
}
#endif

// FUNCTION: 0x005da1c0
cIStream_a85218* Fn005da1c0(cIStream_a85218* pStream, cTimer_a85218* pTimer)
{
    pTimer->Reset();
    uint8_t units;
    pStream->GetUint8(&units);
    pTimer->SetUnits(units);
    uint64_t elapsed;
    pStream->GetUint64(&elapsed);
    pTimer->Fn0089045a(elapsed);
    uint8_t running;
    pStream->GetUint8(&running);
    if (running) {
        pTimer->Start();
    } else {
        pTimer->Stop();
    }
    return pStream;
}

// FUNCTION: 0x005da240
cOStream_a85218* Fn005da240(cOStream_a85218* pStream, cTimer_a85218* pTimer)
{
    uint8_t units = pTimer->GetUnits();
    pStream->SetUint8(units);
    uint64_t elapsed;
    pTimer->Fn00890279(&elapsed);
    pStream->SetUint64(elapsed);
    uint8_t running = pTimer->IsTimerRunning();
    pStream->SetUint8(running);
    return pStream;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004350d0 score 4
bool cDispatch_a85218::SetCurrentCommuteDestination(const cLocation_a85218& location, bool flag)
{
    cLocation_a85218 target(location);
    if (!target.IsValid()) {
        if (!flag) {
            return false;
        }
        if (mnState40 != 2) {
            if (!Fn00432f50(target)) {
                return false;
            }
        }
    }
    mLocD4 = target;
    if (flag) {
        Fn00431a30(0xeba06bf4, 0, 0, 0);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00435030 score 47
bool cDispatch_a85218::Fn00435030(const cLocation_a85218& location)
{
    bool ok = false;
    if (location.IsValid() && location.mbSet && !location.mbFlag1d) {
        ok = true;
        if (mLoc5c.Fn00431640(mLoc84)) {
            ResetRef_a85218(mLoc5c.mpOccupant);
        }
        mLoc84 = location;
        ++mn34;
    }
    uint32_t old = mnFlags;
    uint32_t flags = ok ? (old | 0x80) : (old & ~0x80u);
    mnFlags = flags;
    if (old != flags) {
        Fn00431a30(0x4bb2d020, old, flags, 0);
        ++mn34;
    }
    return ok;
}
#endif

// FUNCTION: 0x00431370
void Fn00431370(float x, float z, int32_t* pCellX, int32_t* pCellZ)
{
    float fx = x * 0.0625f;
    float tx = (fx - 0.5f) + 12582912.0f;
    int32_t cx = *reinterpret_cast<int32_t*>(&tx) - 0x4b400000;
    int32_t nx = cx + 1;
    if (fx == static_cast<float>(nx)) {
        cx = nx;
    }
    float fz = z * 0.0625f;
    float tz = (fz - 0.5f) + 12582912.0f;
    *pCellX = cx;
    int32_t cz = *reinterpret_cast<int32_t*>(&tz) - 0x4b400000;
    int32_t nz = cz + 1;
    if (fz == static_cast<float>(nz)) {
        cz = nz;
    }
    *pCellZ = cz;
}

// FUNCTION: 0x00424b80
int32_t cSC4MySim::Fn00424b80(void* pOccupant)
{
    float pos[3];
    static_cast<cBoxOcc_a85218*>(pOccupant)->Fn8(pos);
    float dx = mfHomeX - pos[0];
    float dz = mfHomeZ - pos[2];
    return static_cast<int32_t>(sqrt(dz * dz + dx * dx));
}

// FUNCTION: 0x00425a30
bool cSC4MySim::Fn00425a30()
{
    cLocation_a85218 loc;
    loc.Fn00431320();
    loc.Fn004311e0();
    return static_cast<cDispatch_a85218*>(mpDispatch)->SetCurrentCommuteDestination(loc, true);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00426fa0 score 4
void cSC4MySim::Fn00426fa0()
{
    if (mnState) {
        Fn00426ba0();
        Slot35_a84c10();
        cDispatch_a85218* dispatch = static_cast<cDispatch_a85218*>(mpDispatch);
        mnState = 0;
        dispatch->Fn00434670();
        mnCarState[0] = 0;
        mnCarState[1] = 0;
        mnCarState[2] = 0;
        mnCarState[3] = 0;
        mnCarState[4] = 0;
        mnCarState[5] = 0;
        Fn00426480();
        Fn00424fe0();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00427490 score 55
bool cSC4MySim::Fn00427490(uint32_t which, uint32_t kind)
{
    std::list<int32_t>& queue = (which == 1) ? *reinterpret_cast<std::list<int32_t>*>(&mpBalloonEventList)
                                             : *reinterpret_cast<std::list<int32_t>*>(&mpBalloonList);
    if (!queue.empty()) {
        int32_t index = queue.front();
        if (index >= 0) {
            Advice_a85218* advices = static_cast<Advice_a85218*>(mpBalloonAdvices);
            if (static_cast<uint32_t>(index) < static_cast<uint32_t>(static_cast<Advice_a85218*>(mpBalloonAdvicesEnd) - advices)) {
                Advice_a85218* advice = &advices[index];
                if (advice->mpObj->Fn14(kind)) {
                    advice->mnTime = advice->mpObj->Fn4()->Fn16() + mnValue5c;
                    advice->mpObj->Fn13(7, 0);
                    queue.pop_front();
                    return true;
                }
            }
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00427540 score 50
void* cSC4MySim::Fn00427540(uint32_t which)
{
    Fn00427490(which, 4);
    std::list<int32_t>& queue = (which == 1) ? *reinterpret_cast<std::list<int32_t>*>(&mpBalloonEventList)
                                             : *reinterpret_cast<std::list<int32_t>*>(&mpBalloonList);
    while (!queue.empty()) {
        int32_t index = queue.front();
        Advice_a85218* advices = static_cast<Advice_a85218*>(mpBalloonAdvices);
        if (index >= 0 && static_cast<uint32_t>(index) < static_cast<uint32_t>(static_cast<Advice_a85218*>(mpBalloonAdvicesEnd) - advices)) {
            cAdvice_a85218* obj = static_cast<Advice_a85218*>(mpBalloonAdvices)[index].mpObj;
            if (!obj->Fn14(4)) {
                if (obj->Fn12()) {
                    return obj;
                }
            }
        }
        Fn00427490(which, 0xffff);
    }
    return 0;
}
#endif

// FUNCTION: 0x004264c0
bool cSC4MySim::DispatchToolEnd()
{
    if (mbToolActive) {
        if (!mbPylonValid) {
            if (mpDispatch) {
                if (mpPylon && static_cast<cDispatch_a85218*>(mpDispatch)->Fn0068d1b0() == 2) {
                    cLocation_a85218 loc(*static_cast<cDispatch_a85218*>(mpDispatch)->Fn00431290());
                    if (!is_pylon_location(&loc) || !loc.mbSet) {
                        Fn00426480();
                    }
                } else {
                    Fn00426480();
                }
            }
        }
    }
    mbToolActive = false;
    return true;
}

// FUNCTION: 0x0042db50
void cSC4MySim::Slot41_a84c10(uint32_t a)
{
    if (mnState) {
        switch (static_cast<int32_t>(a)) {
        case 0x0a57de1f:
            Fn00426fa0();
            break;
        case static_cast<int32_t>(0xea4d269cu):
            Die();
            break;
        case static_cast<int32_t>(0xaa4934b4u):
            Fn0042ca30();
            break;
        case 0x6a47e79b:
            Slot05_a84c10();
            break;
        case 0x6a495f7f:
            Spawn();
            break;
        case 0x6a4a5e9e:
            Fn0042cad0();
            break;
        case 0x6a5e6860:
            Fn0042c050();
            break;
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0042bf70 score 2
void cSC4MySim::Slot40_a84c10()
{
    if (Slot56_a84c10()) {
        void* mem = Fn009133da(0x2c);
        cMessage_a85218* msg = mem ? static_cast<cMessage_a85218*>(mem)->Fn009134d6() : 0;
        if (msg) {
            msg->AddRef();
        }
        msg->Fn5(0xea3ada33);
        msg->Fn33(static_cast<cBuildingOcc_a85218*>(mpResidence)->Fn3());
        msg->Fn11(mbMale);
        msg->Fn16(mnTrackHandle);
        gpB43ccc->MessageSend(msg);
        msg->Release();
    }
    UpdateVariables();
    Slot18_a81120(0xca3e87a8, 0);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00426120 score 10
void cSC4MySim::Slot45_a84c10(uint32_t a, uint32_t b)
{
    if (mnState) {
        Ref_a85218 effect;
        Registry_a85218* registry = Fn0090ddf1();
        if (registry->Fn3(0x6a26d049, 0x6a26d050, effect.AddressOf())) {
            cDisaster_a85218* obj = static_cast<cDisaster_a85218*>(effect.mp);
            float dx = *reinterpret_cast<float*>(&a) - mfHomeX;
            float dz = *reinterpret_cast<float*>(&b) - mfHomeZ;
            obj->Fn10(static_cast<int32_t>(sqrt(dz * dz + dx * dx)));
            Slot18_a81120(0xea5e4e89, OB_ADDR(effect.mp));
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004261d0 score 10
void cSC4MySim::Slot46_a84c10(uint32_t a, uint32_t b)
{
    if (mnState) {
        Ref_a85218 effect;
        Registry_a85218* registry = Fn0090ddf1();
        if (registry->Fn3(0x6a26d049, 0x6a26d050, effect.AddressOf())) {
            cDisaster_a85218* obj = static_cast<cDisaster_a85218*>(effect.mp);
            float dx = *reinterpret_cast<float*>(&a) - mfHomeX;
            float dz = *reinterpret_cast<float*>(&b) - mfHomeZ;
            obj->Fn10(static_cast<int32_t>(sqrt(dz * dz + dx * dx)));
            Slot18_a81120(0x6a5e598c, OB_ADDR(effect.mp));
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00426280 score 10
void cSC4MySim::Slot47_a84c10(uint32_t a, uint32_t b)
{
    if (mnState) {
        Ref_a85218 effect;
        Registry_a85218* registry = Fn0090ddf1();
        if (registry->Fn3(0x6a26d049, 0x6a26d050, effect.AddressOf())) {
            cDisaster_a85218* obj = static_cast<cDisaster_a85218*>(effect.mp);
            float dx = *reinterpret_cast<float*>(&a) - mfHomeX;
            float dz = *reinterpret_cast<float*>(&b) - mfHomeZ;
            obj->Fn10(static_cast<int32_t>(sqrt(dz * dz + dx * dx)));
            Slot18_a81120(0x0a5e8243, OB_ADDR(effect.mp));
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00426060 score 59
void cSC4MySim::Slot42_a84c10(uint32_t a)
{
    if (mnState) {
      if (mpResidence) {
        Ref_a85218 effect;
        Registry_a85218* registry = Fn0090ddf1();
        if (registry->Fn3(0x6a26d049, 0x6a26d050, effect.AddressOf())) {
            cBuildingOcc_a85218* building = OB_PTR(cBuildingOcc_a85218, a);
            int32_t distance = Fn00424b80(building->Fn3());
            cDisaster_a85218* obj = static_cast<cDisaster_a85218*>(effect.mp);
            obj->Fn7(building);
            obj->Fn10(distance);
            Slot18_a81120(0xca4e8986, OB_ADDR(effect.mp));
        }
      }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00424bd0 score 8
void cSC4MySim::Slot27_a84c10(uint32_t a, uint32_t b)
{
    cBuilding2_a85218* building = OB_PTR(cBuilding2_a85218, a);
    if (building) {
        int32_t kind = *building->Fn11();
        uint32_t id;
        switch (mnWealth) {
        case 1:
            if (kind >= 5 && kind <= 8) {
                id = (kind == 5) + 0x8a538a5e;
            } else {
                id = (kind != 2) + 0x8a538a60;
            }
            break;
        case 2:
            if (kind >= 5 && kind <= 8) {
                id = 0x8a538a62;
            } else {
                id = (kind != 2) + 0x8a538a63;
            }
            break;
        case 3:
            if (kind >= 5 && kind <= 8) {
                id = 0x8a538a65;
            } else {
                id = (kind != 2) + 0x8a538a66;
            }
            break;
        default:
            return;
        }
        SC4LoadString(OB_PTR(cIGZString, b), 0xea231e96, id, 0);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00426df0 score 13
void cSC4MySim::PlayHomeSound(uint32_t sound)
{
    if (Slot56_a84c10()) {
        RemoveHomeSound();
        Key_a85218 key;
        key.mnType = 0x6534284a;
        key.mnGroup = 0xc977c536;
        key.mnInstance = sound;
        cPropMgr_a85218* mgr = gpB43d10;
        cHomeSound_a85218* old = static_cast<cHomeSound_a85218*>(mpHomeSound);
        if (old) {
            mpHomeSound = 0;
            old->Release();
        }
        if (mgr->Fn16(&key, &mpHomeSound)) {
            static_cast<cHomeSound_a85218*>(mpHomeSound)->Fn3()->Fn9(&mfHomeX);
            cOccMgr2_a85218* occMgr = gpB43cec_a85218->Fn34();
            occMgr->Fn20(static_cast<cHomeSound_a85218*>(mpHomeSound)->Fn3(), 0);
        }
    }
}
#endif

// FUNCTION: 0x00426ae0
uint32_t cSC4MySim::Slot51_a84c10(uint32_t a)
{
    uint32_t best = 0xffffffff;
    std::list<cBoxOcc_a85218*>* buildings = gpB43cec_a85218->Fn53()->Fn44();
    for (std::list<cBoxOcc_a85218*>::iterator it = buildings->begin(); it != buildings->end(); ++it) {
        cBoxOcc_a85218* building = *it;
        Ref_a85218 type;
        if (building->QueryInterface(0x87dda3a9, reinterpret_cast<void**>(&type.mp))) {
            if (static_cast<cOccType_a85218*>(type.mp)->Fn4() == a) {
                float pos[3];
                building->Fn8(pos);
                float dx = mfHomeX - pos[0];
                float dz = mfHomeZ - pos[2];
                uint32_t distance = static_cast<uint32_t>(static_cast<int32_t>(sqrt(dz * dz + dx * dx)));
                if (distance < best) {
                    best = distance;
                }
            }
        }
    }
    return best;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00431430 score 9
bool cLocation_a85218::SetByOccupant(void* pOccupant)
{
    cLocation_a85218 fresh;
    fresh.mpOccupant = 0;
    fresh.mnCellX = -1;
    fresh.mnCellZ = -1;
    fresh.mn14 = -1;
    fresh.mn18 = -1;
    fresh.mbFlag1d = false;
    fresh.mn20 = 0;
    fresh.mn24 = 0;
    fresh.mfX = static_cast<float>(fresh.mnCellX * 16);
    fresh.mfZ = static_cast<float>(fresh.mnCellZ * 16);
    fresh.mbSet = 1;
    *this = fresh;
    mbSet = 1;
    cIGZUnknown* occupant = static_cast<cIGZUnknown*>(pOccupant);
    cIGZUnknown* old = mpOccupant;
    if (occupant != old) {
        if (occupant) {
            occupant->AddRef();
        }
        mpOccupant = occupant;
        if (old) {
            old->Release();
        }
    }
    if (mpOccupant) {
        float position[3];
        static_cast<cBoxOcc_a85218*>(mpOccupant)->Fn8(position);
        mfX = position[0];
        mfZ = position[2];
        Fn00431370(position[0], position[2], &mnCellX, &mnCellZ);
    }
    return true;
}
#endif

// FUNCTION: 0x00434ba0
bool cDispatch_a85218::Fn00434ba0(const cLocation_a85218& location, uint32_t flags)
{
    if (flags & 4) {
        mQueue.clear();
    }
    if (flags & 1) {
        mQueue.push_front(location);
        return true;
    }
    mQueue.push_back(location);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00434670 score 49
bool cDispatch_a85218::Fn00434670()
{
    if (mpRef124) {
        cATM_a85218* atm = Fn00602600();
        void* target = reinterpret_cast<uint8_t*>(this) + 8;
        if (atm) {
            atm->Fn6(target, 0xff);
        }
        gpB43ccc->RemoveNotification(target, 0x44778231);
        gpB43ccc->RemoveNotification(target, 0x8bbbd22a);
        gpB43ccc->RemoveNotification(target, 0xa6b79601);
        gpB43ccc->RemoveNotification(target, 0xa6b79611);
    }
    bool bit8 = ((mnFlags >> 8) & 1) != 0;
    Fn00431f70();
    uint32_t old = mnFlags;
    uint32_t flags = bit8 ? (old | 0x100) : (old & ~0x100u);
    mnFlags = flags;
    if (old != flags) {
        Fn00431a30(0x4bb2d020, old, flags, 0);
        ++mn34;
    }
    Fn00434080();
    ResetRef_a85218(mpRef120);
    ResetRef_a85218(mpRef124);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0042c820 score 20
void cSC4MySim::Slot34_a84c10()
{
    if (mnState) {
        cRZString name;
        if (mnNameId == 0) {
            gpB43c94->Fn61(&name);
            cRZString* other = reinterpret_cast<cRZString*>(field130);
            std::string* text = other;
            name.append(text->begin(), text->end());
        }
        static_cast<cDispatch_a85218*>(mpDispatch)->Fn00435610(mnNameId, &name);
        mbLocationShown = true;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00426760 score 30
float* cSC4MySim::Fn00426760(float* pOut)
{
    float result[3];
    result[0] = 0;
    result[1] = 0;
    result[2] = 0;
    cPedMgr_a85218* manager = gpB43cec_a85218->Fn44();
    if (manager) {
        float where[3];
        where[0] = 0;
        where[1] = -100.0f;
        where[2] = 0;
        float scratch[3];
        cPed_a85218* ped = manager->Fn15(0x4149, where, 2, scratch, 0, 0xff, 0);
        if (ped) {
            ped->AddRef();
            float temp[3];
            float* found = ped->Fn96(temp, 0);
            result[0] = found[0];
            result[1] = found[1];
            result[2] = found[2];
            ped->Fn13(1);
            ped->Release();
        }
    }
    pOut[0] = result[0];
    pOut[1] = result[1];
    pOut[2] = result[2];
    return pOut;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0042df50 score 2
bool cSC4MySim::Slot09_a84c10()
{
    static_cast<cDispatch_a85218*>(mpDispatch)->Fn00434670();
    Fn00426480();
    mnCarState[0] = 0;
    mnCarState[1] = 0;
    mnCarState[2] = 0;
    mnCarState[3] = 0;
    mnCarState[4] = 0;
    mnCarState[5] = 0;
    Fn00426ba0();
    mnState = 0;
    Slot35_a84c10();
    Fn0042dbf0();
    void* mem = Fn009133da(0x2c);
    cMessage_a85218* msg = mem ? static_cast<cMessage_a85218*>(mem)->Fn009134d6() : 0;
    if (msg) {
        msg->AddRef();
    }
    msg->Fn5(0xaa25827c);
    gpB43ccc->MessageSend(msg);
    msg->Release();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00425ca0 score 74
bool cSC4MySim::Slot07_a84c10(uint32_t a, uint32_t b, uint32_t c)
{
    cBuildingOcc_a85218* building = OB_PTR(cBuildingOcc_a85218, a);
    if (building == mpResidence) {
        return false;
    }
    cLot_a85218* lot = gpB43d08->Fn14(building->Fn3());
    if (static_cast<uint8_t>(c) && lot) {
        if (lot->Fn41() != mnWealth) {
            return false;
        }
    }
    if (building->Fn9(building)) {
        return false;
    }
    if (static_cast<uint8_t>(b)) {
        void* mem = operator new(0x10);
        cTester_a85218* tester = mem ? static_cast<cTester_a85218*>(mem)->Fn00424ab0(1) : 0;
        if (tester) {
            tester->AddRef();
        }
        bool result = tester->Fn3(building->Fn3());
        tester->Release();
        return result;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00426c10 score 38
bool cSC4MySim::Slot06_a84c10(uint32_t a)
{
    cIGZUnknown* old = static_cast<cIGZUnknown*>(mpResidence);
    if (old) {
        old->AddRef();
    }
    if (Slot07_a84c10(a, 0, 0)) {
        Fn00426ba0();
        Slot13_a84c10(a);
        if (Slot19_a81120(0x6a47e79b)) {
            Fn00426ba0();
            Slot13_a84c10(OB_ADDR(old));
        }
        if (mbResidenceShown) {
            Slot32_a84c10();
        }
        mnTrackHandle = static_cast<cDispatch_a85218*>(mpDispatch)->mnTrackHandle;
        if (mpResidence != old) {
            if (mpWorkRef) {
                mnWealth = static_cast<cLot_a85218*>(mpWorkRef)->Fn41();
            }
            mnState = 1;
            if (old) {
                old->Release();
            }
            return true;
        }
    }
    if (old) {
        old->Release();
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0042c940 score 26
void cSC4MySim::Slot44_a84c10(uint32_t a, uint32_t b)
{
    if (mnState) {
        if (mpResidence && OB_ADDR(mpResidence) == a) {
            if (b) {
                mnRemovedFlag = b;
                UpdateVariables();
                Slot18_a81120(0xaa4d2d64, 0);
                Fn00426ba0();
                return;
            }
            Slot18_a81120(0xaa48f5c1, 0);
            Slot05_a84c10();
            return;
        }
        if (mpJobBuilding && OB_ADDR(mpJobBuilding) == a) {
            if (b) {
                mnRemovedFlag = b;
                UpdateVariables();
                Slot18_a81120(0xaa4d2d65, 0);
                Fn0042c050();
                return;
            }
            Slot18_a81120(0xca48f879, 0);
            Fn0042c050();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00426660 score 24
bool cSC4MySim::Slot57_a84c10(uint32_t a)
{
    float defaults[3];
    defaults[0] = g00b07d8c[0];
    defaults[1] = g00b07d8c[1];
    defaults[2] = g00b07d8c[2];
    Ref_a85218 fallback;
    cExemplar_a85218* exemplar = OB_PTR(cExemplar_a85218, a);
    if (!exemplar) {
        gpB43ca8->Fn3(g00b07d8c, 0xa52160f5, fallback.AddressOf(), 0, 0);
        exemplar = reinterpret_cast<cExemplar_a85218*>(fallback.mp);
    }
    mnModelButtonBitmapB = 0;
    mnCarState[0] = 0;
    mnCarState[1] = 0;
    mnCarState[2] = 0;
    if (exemplar) {
        if (Fn005fd5b0(exemplar->Fn6(), 0x09c80416, defaults)) {
            reinterpret_cast<float*>(mnCarState)[0] = defaults[0];
            reinterpret_cast<float*>(mnCarState)[1] = defaults[1];
            reinterpret_cast<float*>(mnCarState)[2] = defaults[2];
        }
        uint32_t bitmap = 0;
        if (Fn005fd450(exemplar->Fn6(), 0xebfc5e5e, &bitmap)) {
            mnModelButtonBitmapB = bitmap;
        }
    }
    static_cast<cDispatch_a85218*>(mpDispatch)->Fn00434ff0(0, mnCarState, 0);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00426ce0 score 51
bool cSC4MySim::DispatchCommute()
{
    if (!mpResidence) {
        return false;
    }
    if (mnState == 2) {
        cLocation_a85218 loc(*static_cast<cDispatch_a85218*>(mpDispatch)->Fn004312b0());
        if (!loc.mbFlag1d || !loc.IsValid()) {
            cLocation_a85218 fresh;
            fresh.Fn00431320();
            loc = fresh;
            loc.Fn004311e0();
        }
        int32_t hour = gpB43dbc->Fn10();
        if (hour < 8) {
            loc.mn20 = 5;
        } else {
            int32_t minutes = (0x11 - hour) * 0x3c;
            loc.mn20 = minutes < 0 ? 5 : minutes;
        }
        static_cast<cDispatch_a85218*>(mpDispatch)->Fn00434ba0(loc, 4);
        return true;
    }
    if (mnState == 3 || mnState == 1) {
        if (mnState == 1) {
            static_cast<cDispatch_a85218*>(mpDispatch)->Fn00431c70();
        }
        cDispatch_a85218* dispatch = static_cast<cDispatch_a85218*>(mpDispatch);
        dispatch->Fn00434ba0(*dispatch->Fn004312a0(), 4);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00426330 score 14
void cSC4MySim::Slot48_a84c10(uint32_t a, uint32_t b, uint32_t c)
{
    if (mnState) {
        if (a == 0xca380b06 || a == 0xc4c90997) {
            Ref_a85218 effect;
            Registry_a85218* registry = Fn0090ddf1();
            if (registry->Fn3(0x6a26d049, 0x6a26d050, effect.AddressOf())) {
                cDisaster_a85218* obj = static_cast<cDisaster_a85218*>(effect.mp);
                obj->Fn3(static_cast<float>(static_cast<int32_t>(c)), static_cast<float>(static_cast<int32_t>(b)));
                float x;
                float z;
                gpB43cec_a85218->Fn97(static_cast<int32_t>(b), static_cast<int32_t>(c), &x, &z);
                x -= mfHomeX;
                z -= mfHomeZ;
                static_cast<cDisaster_a85218*>(effect.mp)->Fn10(static_cast<int32_t>(sqrt(x * x + z * z)));
                if (a == 0xc4c90997) {
                    Slot18_a81120(0x2ac14492, OB_ADDR(effect.mp));
                } else if (a == 0xca380b06) {
                    Slot18_a81120(0x8ac11a9b, OB_ADDR(effect.mp));
                }
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004272b0 score 40
bool cSC4MySim::Slot58_a84c10(uint32_t a)
{
    float defaults[3];
    defaults[0] = g00b07d98[0];
    defaults[1] = g00b07d98[1];
    defaults[2] = g00b07d98[2];
    Ref_a85218 fallback;
    cExemplar_a85218* exemplar = OB_PTR(cExemplar_a85218, a);
    if (!exemplar) {
        gpB43ca8->Fn3(g00b07d98, 0xa52160f5, fallback.AddressOf(), 0, 0);
        exemplar = reinterpret_cast<cExemplar_a85218*>(fallback.mp);
    }
    mnModelButtonBitmapA = 0;
    float* pedestrian = reinterpret_cast<float*>(&mnCarState[3]);
    pedestrian[0] = 0;
    pedestrian[1] = 0;
    pedestrian[2] = 0;
    if (exemplar) {
        if (Fn005fd5b0(exemplar->Fn6(), 0x09c80416, defaults)) {
            pedestrian[0] = defaults[0];
            pedestrian[1] = defaults[1];
            pedestrian[2] = defaults[2];
        }
        uint32_t bitmap = 0;
        if (Fn005fd450(exemplar->Fn6(), 0xebfc5e5e, &bitmap)) {
            mnModelButtonBitmapA = bitmap;
        }
    }
    float buffer[3];
    float* spot = Fn00426760(buffer);
    defaults[0] = spot[0];
    defaults[1] = spot[1];
    defaults[2] = spot[2];
    if (mnCarState[5] == 0) {
        pedestrian[0] = spot[0];
        pedestrian[1] = spot[1];
        pedestrian[2] = spot[2];
    }
    static_cast<cDispatch_a85218*>(mpDispatch)->Fn00434ff0(1, reinterpret_cast<const uint32_t*>(pedestrian), 0);
    static_cast<cDispatch_a85218*>(mpDispatch)->Fn00434ff0(2, reinterpret_cast<const uint32_t*>(defaults), 0);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0042dc90 score 66
void cSC4MySim::simulate_day()
{
    bool blocked;
    if (mnState) {
        Ref_a85218 winMgr;
        cSysServ_a85218* services = Fn008793ec();
        if (services) {
            services->Fn5(0xa417445e, 0x5a4, reinterpret_cast<void**>(&winMgr.mp));
        }
        blocked = static_cast<cWinMgr_a85218*>(winMgr.mp)->Fn42();
    } else {
        blocked = true;
    }
    if (!blocked) {
        if (!mpJobBuilding && !mpJobOther && !mbRetired && mnState == 2 && !Fn00425a30()) {
            ++mnJobSearchDays;
        }
        if (mbNeighborConnectionRemoved) {
            Fn0042d9e0();
            mbNeighborConnectionRemoved = false;
        }
        Slot68_a84c10();
        simulate_balloons(false);
        cSC4Advisor::simulate_day();
        uint32_t now = mnValue5c;
        if (static_cast<int32_t>(now - mnLastTripTime) > 0) {
            mnLastTripTime = now;
            UpdateTripVariables(-1, -1, -1, -1, false);
        }
        if (mpPylon) {
            cTimer_a85218* timer = reinterpret_cast<cTimer_a85218*>(mPylonTimer);
            if (timer->IsTimerRunning()) {
                if (static_cast<cModel_a85218*>(mpPylon)->Fn16()) {
                    timer->Stop();
                } else if (timer->GetElapsedTime() > 5) {
                    Fn00426480();
                    timer->Stop();
                }
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0042ddf0 score 50
void cSC4MySim::simulate_month()
{
    bool blocked;
    if (mnState) {
        Ref_a85218 winMgr;
        cSysServ_a85218* services = Fn008793ec();
        if (services) {
            services->Fn5(0xa417445e, 0x5a4, reinterpret_cast<void**>(&winMgr.mp));
        }
        blocked = static_cast<cWinMgr_a85218*>(winMgr.mp)->Fn42();
    } else {
        blocked = true;
    }
    if (!blocked) {
        if (static_cast<int32_t>(mnRefA) % 12 == mnBirthMonth) {
            ++mnAge;
        }
        if (mpJobBuilding || mpJobOther) {
            Fn0042d9e0();
        }
        UpdateVariables();
        mfEQDelta = mfEQ - mfEQHistory[mnEQIndex];
        mfEQHistory[mnEQIndex] = mfEQ;
        ++mnEQIndex;
        if (mnEQIndex == 6) {
            mnEQIndex = 0;
        }
        mfHQDelta = mfHQ - mfHQHistory[mnHQIndex];
        mfHQHistory[mnHQIndex] = mfHQ;
        ++mnHQIndex;
        if (mnHQIndex == 6) {
            mnHQIndex = 0;
        }
        Slot68_a84c10();
        cSC4Advisor::simulate_month();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0042d9e0 score 49
bool cSC4MySim::Fn0042d9e0()
{
    cCommuteSim_a85218* commute = gpB43cec_a85218->Fn69();
    bool result = false;
    cRoute_a85218* route = 0;
    if (mpJobBuilding || mpJobOther) {
        if (mpResidence) {
            commute->Fn6(&route);
            if (route) {
                Span_a85218 from;
                Span_a85218 to;
                static_cast<cBuildingOcc_a85218*>(mpResidence)->Fn3()->Fn11(reinterpret_cast<float*>(&from));
                if (mpJobBuilding) {
                    static_cast<cBuildingOcc_a85218*>(mpJobBuilding)->Fn3()->Fn11(reinterpret_cast<float*>(&to));
                } else {
                    to.mn0 = reinterpret_cast<uint32_t*>(this)[0xf0 / 4];
                    to.mn1 = reinterpret_cast<uint32_t*>(this)[0xf4 / 4];
                    to.mn2 = to.mn0;
                    to.mn3 = to.mn1;
                }
                route->Fn5(1);
                route->Fn9(3);
                route->Fn18(1);
                route->Fn19(from);
                route->Fn20(to);
                if (route->Fn23() == 1) {
                    result = true;
                    mnCommuteLength = static_cast<uint32_t>(static_cast<int32_t>(route->Fn26()));
                } else {
                    FailCommute();
                }
                route->Release();
            }
        }
    }
    return result;
}
#endif

// STUB: 0x005f98c0
void SC4PostMessage2(uint32_t id, uint32_t a, uint32_t b, uint32_t c, uint32_t d, void* pObject);

#ifdef OB_DRAFTS
// CLOSE: 0x00427120 score 118
bool cSC4MySim::DispatchToolLockPylon(uint32_t a)
{
    uint8_t lock = static_cast<uint8_t>(a);
    if (mpDispatch && lock) {
        cModel_a85218* pylon = static_cast<cModel_a85218*>(mpPylon);
        Ref_a85218 occupant;
        occupant.mp = reinterpret_cast<cIGZUnknown*>(pylon->Fn3());
        if (occupant.mp) {
            occupant.mp->AddRef();
        }
        cLocation_a85218 target;
        target.Fn00431320();
        target.SetByOccupant(occupant.mp);
        cLot_a85218* lot = gpB43d08->Fn6(target.mnCellX, target.mnCellZ, 0);
        if (lot) {
            cLotItem_a85218* item = lot->Fn48();
            if (item) {
                cIGZUnknown* found = item->Fn3();
                if (found != occupant.mp) {
                    if (found) {
                        found->AddRef();
                    }
                    cIGZUnknown* old = occupant.mp;
                    occupant.mp = found;
                    if (old) {
                        old->Release();
                    }
                }
                static_cast<cModel_a85218*>(mpPylon)->Fn17(occupant.mp);
                target.SetByOccupant(occupant.mp);
            }
        }
        cLocation_a85218 current(*static_cast<cDispatch_a85218*>(mpDispatch)->Fn00431290());
        bool go = false;
        if (current.mbSet == target.mbSet) {
            if (Fn007aa8e0(&current.mn14, &target.mn14)) {
                go = true;
            } else if (target.mpOccupant != current.mpOccupant) {
                go = target.mpOccupant && current.mpOccupant;
            }
        }
        if (go) {
            if (static_cast<cDispatch_a85218*>(mpDispatch)->GoTo(target)) {
                static_cast<cModel_a85218*>(mpPylon)->Fn11(3);
                SC4PostMessage2(0x4bc42c48, 0, 0, 0, 0, &mpResidence);
                mnState = 6;
                mnLastTripTime = 0;
                *(reinterpret_cast<uint32_t*>(this) + 0x298 / 4) = mnValue5c;
            } else {
                static_cast<cModel_a85218*>(mpPylon)->Fn11(1);
            }
        }
    }
    mbPylonValid = lock != 0;
    if (!lock) {
        static_cast<cModel_a85218*>(mpPylon)->Fn17(0);
    }
    return true;
}
#endif

inline void SetFlags_a85218(cDispatch_a85218* tool, uint32_t mask, bool on)
{
    uint32_t old = tool->mnFlags;
    uint32_t flags = on ? (old | mask) : (old & ~mask);
    tool->mnFlags = flags;
    if (old != flags) {
        tool->Fn00431a30(0x4bb2d020, old, flags, 0);
        ++tool->mn34;
    }
}

inline int32_t& IntAt_a85218(cDispatch_a85218* tool, uint32_t offset)
{
    return *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(tool) + offset);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00437130 score 142
bool cDispatch_a85218::GoTo(const cLocation_a85218& location)
{
    cLocation_a85218 loc(location);
    if (loc.mpOccupant) {
        int32_t floor = IntAt_a85218(this, 0x20);
        if (floor > static_cast<int32_t>(loc.mn20)) {
            loc.mn20 = floor;
        }
    }
    bool result;
    if (mnState40 == 2) {
        mQueue.clear();
        IntAt_a85218(this, 0xac) = 0;
        void* automaton;
        bool have = Fn004317f0(&automaton);
        if (!have || !static_cast<cAutomaton_a85218*>(automaton)->Fn31(1)) {
            SetFlags_a85218(this, 0x5800, false);
            SetFlags_a85218(this, 0x4000, true);
            Fn004365c0();
            if (IntAt_a85218(this, 0x138) != IntAt_a85218(this, 0x128) && IntAt_a85218(this, 0x30) != IntAt_a85218(this, 0x2c)) {
                result = true;
            } else {
                Fn004320d0();
                result = false;
            }
        } else {
            SetFlags_a85218(this, 0x5800, false);
            SetFlags_a85218(this, 0x4000, false);
            result = true;
        }
        if (automaton) {
            static_cast<cIGZUnknown*>(automaton)->Release();
        }
    } else {
        IntAt_a85218(this, 0x80) = static_cast<int32_t>(mnFlags) - 1;
        result = Fn00434ba0(loc, 4);
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0042cb10 score 76
uint32_t cSC4MySim::DispatchToolBegin()
{
    if (!mpPylon) {
        void* mem = operator new(0x1cc);
        cPylon_a85218* pylon = mem ? static_cast<cPylon_a85218*>(mem)->Fn005f1730(1) : 0;
        cPylon_a85218* old = static_cast<cPylon_a85218*>(mpPylon);
        if (pylon != old) {
            if (pylon) {
                pylon->AddRef();
            }
            mpPylon = pylon;
            if (old) {
                old->Release();
            }
        }
        static_cast<cPylon_a85218*>(mpPylon)->Fn4();
        static_cast<cPylon_a85218*>(mpPylon)->Fn11(0);
        static_cast<cPylon_a85218*>(mpPylon)->Fn9(4);
        static_cast<cPylon_a85218*>(mpPylon)->Fn6(1);
        float origin[3];
        origin[0] = 0;
        origin[1] = 0;
        origin[2] = 0;
        static_cast<cPylon_a85218*>(mpPylon)->Fn3()->Fn9(origin);
        cRZString name;
        gpB43c94->Fn61(&name);
        static_cast<cPylon_a85218*>(mpPylon)->Fn8(mnNameId, &name);
        Ref_a85218 tool;
        QueryInterface(1, reinterpret_cast<void**>(&tool.mp));
        static_cast<cPylon_a85218*>(mpPylon)->Fn19(tool.mp);
        mbPylonValid = false;
    }
    mbToolActive = true;
    cDispatch_a85218* view = gpB43dc4->Fn24();
    cDispatch_a85218* previous = gpB20e0c;
    if (view != previous) {
        if (view) {
            view->AddRef();
        }
        gpB20e0c = view;
        if (previous) {
            previous->Release();
        }
    }
    return OB_ADDR(mpPylon);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00433eb0 score 131
bool cDispatch_a85218::Fn00433eb0()
{
    if (!mpRef124) {
        void* target = reinterpret_cast<uint8_t*>(this) + 8;
        gpB43ccc->AddNotification(target, 0x44778231);
        gpB43ccc->AddNotification(target, 0x8bbbd22a);
        gpB43ccc->AddNotification(target, 0xa6b79601);
        gpB43ccc->AddNotification(target, 0xa6b79611);
        cATM_a85218* atm = Fn00602600();
        if (atm) {
            atm->Fn5(target, 0xff);
        }
        ResetRef_a85218(mpRef124);
        gpB43da8->Fn6(reinterpret_cast<void**>(&mpRef124));
    }
    if (!mbFlag188) {
        cIGZUnknown* clock = reinterpret_cast<cIGZUnknown*>(gpB43dbc);
        if (clock != mpRef120) {
            if (clock) {
                clock->AddRef();
            }
            cIGZUnknown* old = mpRef120;
            mpRef120 = clock;
            if (old) {
                old->Release();
            }
        }
        {
            cLocation_a85218 fresh;
            fresh.Fn00431320();
            mLoc84 = fresh;
        }
        {
            cLocation_a85218 fresh;
            fresh.Fn00431320();
            mLocD4 = fresh;
        }
        mLocD4.mbFlag1d = true;
        mLoc5c = mLocD4;
        mnState40 = 3;
        Fn00432ee0();
        mbFollowCamera = 0;
    }
    return true;
}
#endif

// The input control the sim creates for the move-in tool (0x4c bytes): a base constructor and nine zeroed words.
struct cMoveInTool_a85218 {
    uint32_t mpVtable;        // 0x00
    uint8_t mPad04[0x24];     // 0x04
    uint32_t mn28;
    uint32_t mn2c;
    uint32_t mn30;
    uint32_t mn34;
    uint32_t mn38;
    uint32_t mn3c;
    uint32_t mn40;
    uint32_t mn44;
    uint32_t mn48;
    // STUB: 0x005fb320
    void Fn005fb320();
    // STUB: 0x00439fc0
    cMoveInTool_a85218* Fn00439fc0();
    // STUB: 0x0043a730
    bool Fn0043a730(cSC4MySim* pOwner);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00439fc0 score 2
cMoveInTool_a85218* cMoveInTool_a85218::Fn00439fc0()
{
    Fn005fb320();
    mpVtable = 0xa85a20;
    mn28 = 0;
    mn2c = 0;
    mn30 = 0;
    mn34 = 0;
    mn38 = 0;
    mn3c = 0;
    mn40 = 0;
    mn44 = 0;
    mn48 = 0;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0042d000 score 51
void* cSC4MySim::Slot08_a81120()
{
    if (mnNameKind <= 1) {
        return &field38;
    }
    if (!mpPersonalName) {
        void* mem = operator new(0x14);
        cRZString* name = mem ? new (mem) cRZString() : 0;
        cRZString* old = static_cast<cRZString*>(mpPersonalName);
        if (name != old) {
            if (name) {
                name->AddRef();
            }
            mpPersonalName = name;
            if (old) {
                old->Release();
            }
        }
        if (mnNameKind <= 10) {
            cRZString title;
            SC4LoadString(&title, 0xea231e96, mnNameKind + 0x6a56248e, 0);
            if (title.size() != 0) {
                *static_cast<cRZString*>(mpPersonalName) = *reinterpret_cast<cRZString*>(&field38);
                static_cast<cRZString*>(mpPersonalName)->push_back(' ');
                static_cast<cRZString*>(mpPersonalName)->append(title.begin(), title.end());
                return mpPersonalName;
            }
        }
        static_cast<cRZString*>(mpPersonalName)->Sprintf("%s %d", reinterpret_cast<cRZString*>(&field38)->c_str(), mnNameKind);
    }
    return mpPersonalName;
}
#endif

// STUB: 0x005d99a0
void Fn005d99a0(cOStream_a85218* pStream, void* pObject);
// STUB: 0x005d9fd0
void Fn005d9fd0(cOStream_a85218* pStream, uint32_t value);
// STUB: 0x005da0a0
void Fn005da0a0(cOStream_a85218* pStream, const void* pKey);

inline uint32_t& Word_a85218(cSC4MySim* self, uint32_t offset)
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + offset);
}

#ifdef OB_DRAFTS
// CLOSE: 0x004251a0 score 90
bool cSC4MySim::Slot03_a80784(void* a)
{
    cOStream_a85218* stream = static_cast<cOStream_a85218*>(a);
    stream->SetUint16(0x11);
    uint32_t state = mnState;
    stream->SetUint8(static_cast<uint8_t>(state));
    if (state) {
        stream->SetUint8(fieldbc);
        Fn005d99a0(stream, mpResidence);
        stream->SetUint32(Word_a85218(this, 0xc8));
        stream->SetUint32(Word_a85218(this, 0xcc));
        Fn005d99a0(stream, mpJobBuilding);
        stream->SetSint32(Word_a85218(this, 0xe8));
        stream->SetSint32(Word_a85218(this, 0xec));
        stream->SetSint32(Word_a85218(this, 0xf0));
        stream->SetSint32(Word_a85218(this, 0xf4));
        stream->SetUint32(mnJobSearchDays);
        Fn005da0a0(stream, &mfLocX);
        stream->SetUint8(static_cast<uint8_t>(mnWealth));
        stream->SetUint16(mnNameKind);
        stream->SetUint8(field112);
        Fn005d9fd0(stream, mbMale);
        stream->SetGZStr(field114);
        stream->SetUint8(mnAge);
        stream->SetUint8(mnBirthMonth);
        stream->SetUint32(mnNameId);
        stream->SetGZStr(field130);
        stream->SetUint32(mnCommuteLength);
        Fn005d9fd0(stream, mbRetired);
        stream->SetUint32(mnRemovedFlag);
        for (uint32_t i = 0; i < 3; ++i) {
            stream->SetFloat32(*reinterpret_cast<float*>(&Word_a85218(this, 0xd0 + i * 4)));
        }
        stream->SetUint8(mnEQIndex);
        stream->SetFloat32(mfEQDelta);
        for (uint32_t i = 0; i < 6; ++i) {
            stream->SetFloat32(mfEQHistory[i]);
        }
        stream->SetUint8(mnHQIndex);
        stream->SetFloat32(mfHQDelta);
        for (uint32_t i = 0; i < 6; ++i) {
            stream->SetFloat32(mfHQHistory[i]);
        }
        Fn005da0a0(stream, &mnCarState[0]);
        Fn005da0a0(stream, &mnCarState[3]);
        stream->SetSint32(mnModelButtonBitmapA);
        stream->SetSint32(mnModelButtonBitmapB);
        Fn005d99a0(stream, mpDispatch);
        Fn005da240(stream, reinterpret_cast<cTimer_a85218*>(mPylonTimer));
        bool hasPylon = mpPylon && !static_cast<cModel_a85218*>(mpPylon)->Fn16();
        Fn005d9fd0(stream, hasPylon);
        if (hasPylon) {
            Fn005d99a0(stream, mpPylon);
        }
        Fn005d9fd0(stream, mbPylonValid);
        stream->SetSint32(Word_a85218(this, 0x298));
    }
    return cSC4Advisor::Slot03_a80784(a);
}
#endif

// STUB: 0x005d9730
void Fn005d9730(cIStream_a85218* pStream, void** ppObject);
// STUB: 0x005d9fa0
void Fn005d9fa0(cIStream_a85218* pStream, bool* pValue);

// The newer save formats only: the readers for versions below 0xb differ (an older record is skipped).
#ifdef OB_DRAFTS
// CLOSE: 0x00425490 score 170
bool cSC4MySim::Slot04_a80784(void* a)
{
    cIStream_a85218* stream = static_cast<cIStream_a85218*>(a);
    uint16_t version;
    stream->GetUint16(&version);
    uint8_t state;
    stream->GetUint8(&state);
    mnState = state;
    if (state) {
        stream->GetUint8(reinterpret_cast<uint8_t*>(&fieldbc));
        ResetRef_a85218(mpResidence);
        Fn005d9730(stream, &mpResidence);
        stream->GetUint32(&Word_a85218(this, 0xc8));
        stream->GetUint32(&Word_a85218(this, 0xcc));
        ResetRef_a85218(mpJobBuilding);
        Fn005d9730(stream, &mpJobBuilding);
        stream->GetSint32(reinterpret_cast<int32_t*>(&Word_a85218(this, 0xe8)));
        stream->GetSint32(reinterpret_cast<int32_t*>(&Word_a85218(this, 0xec)));
        stream->GetSint32(reinterpret_cast<int32_t*>(&Word_a85218(this, 0xf0)));
        stream->GetSint32(reinterpret_cast<int32_t*>(&Word_a85218(this, 0xf4)));
        stream->GetUint32(reinterpret_cast<uint32_t*>(&mnJobSearchDays));
        Fn005da070(stream, reinterpret_cast<uint32_t*>(&mfLocX));
        uint8_t wealth;
        stream->GetUint8(&wealth);
        mnWealth = wealth;
        stream->GetUint16(&mnNameKind);
        stream->GetUint8(reinterpret_cast<uint8_t*>(&field112));
        Fn005d9fa0(stream, &mbMale);
        stream->GetGZStr(field114);
        stream->GetUint8(&mnAge);
        stream->GetUint8(&mnBirthMonth);
        stream->GetUint32(&mnNameId);
        stream->GetGZStr(field130);
        stream->GetUint32(&mnCommuteLength);
        Fn005d9fa0(stream, &mbRetired);
        stream->GetUint32(&mnRemovedFlag);
        for (uint32_t i = 0; i < 3; ++i) {
            stream->GetFloat32(reinterpret_cast<float*>(&Word_a85218(this, 0xd0 + i * 4)));
        }
        stream->GetUint8(&mnEQIndex);
        stream->GetFloat32(&mfEQDelta);
        for (uint32_t i = 0; i < 6; ++i) {
            stream->GetFloat32(&mfEQHistory[i]);
        }
        stream->GetUint8(&mnHQIndex);
        stream->GetFloat32(&mfHQDelta);
        for (uint32_t i = 0; i < 6; ++i) {
            stream->GetFloat32(&mfHQHistory[i]);
        }
        if (version >= 0xb) {
            if (version < 0xf) {
                int32_t skipped;
                for (uint32_t i = 0; i < 5; ++i) {
                    stream->GetSint32(&skipped);
                }
            } else {
                Fn005da070(stream, &mnCarState[0]);
                Fn005da070(stream, &mnCarState[3]);
            }
        }
        if (version >= 0x11) {
            stream->GetSint32(reinterpret_cast<int32_t*>(&mnModelButtonBitmapA));
            stream->GetSint32(reinterpret_cast<int32_t*>(&mnModelButtonBitmapB));
        }
        if (version >= 0xc) {
            if (mpDispatch) {
                static_cast<cDispatch_a85218*>(mpDispatch)->Fn00434670();
            }
            ResetRef_a85218(mpDispatch);
            Fn005d9730(stream, &mpDispatch);
            Fn005da1c0(stream, reinterpret_cast<cTimer_a85218*>(mPylonTimer));
            bool hasPylon;
            Fn005d9fa0(stream, &hasPylon);
            if (hasPylon) {
                ResetRef_a85218(mpPylon);
                Fn005d9730(stream, &mpPylon);
            } else {
                ResetRef_a85218(mpPylon);
            }
        }
        if (version >= 0xe) {
            Fn005d9fa0(stream, &mbPylonValid);
        }
        if (version >= 0x10) {
            stream->GetSint32(reinterpret_cast<int32_t*>(&Word_a85218(this, 0x298)));
        }
    }
    return cSC4Advisor::Slot04_a80784(a);
}
#endif

inline void InitFresh_a85218(cLocation_a85218& loc)
{
    loc.mpOccupant = 0;
    loc.mnCellX = -1;
    loc.mnCellZ = -1;
    loc.mn14 = -1;
    loc.mn18 = -1;
    loc.mbFlag1d = false;
    loc.mn20 = 0;
    loc.mn24 = 0;
    loc.mfX = -16.0f;
    loc.mfZ = -16.0f;
    loc.mbSet = 1;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00434080 score 26
bool cDispatch_a85218::Fn00434080()
{
    Fn00431f70();
    void* automaton = 0;
    if (mpOwner118) {
        if (mpOwner118->QueryInterface(0xa9b40f05, &automaton)) {
            static_cast<cAutomaton2_a85218*>(automaton)->Fn40(reinterpret_cast<uint8_t*>(this) + 8);
            static_cast<cAutomaton2_a85218*>(automaton)->Fn13(0);
        }
    }
    uint32_t old = mnFlags;
    mnFlags = 0;
    if (old != 0) {
        Fn00431a30(0x4bb2d020, old, 0, 0);
        ++mn34;
    }
    mQueue.clear();
    cLocation_a85218 fresh;
    InitFresh_a85218(fresh);
    mLoc5c = fresh;
    InitFresh_a85218(fresh);
    *reinterpret_cast<cLocation_a85218*>(reinterpret_cast<uint8_t*>(this) + 0xac) = fresh;
    InitFresh_a85218(fresh);
    mLoc84 = fresh;
    if (IntAt_a85218(this, 0x50) != 0xff) {
        ++mn34;
    }
    IntAt_a85218(this, 0x50) = 0xff;
    int32_t state = static_cast<int32_t>(mnState40);
    IntAt_a85218(this, 0x44) = state;
    mnState40 = static_cast<uint32_t>(-1);
    if (state != -1) {
        Fn00431a30(0x4bb2cfc0, state, -1, 0);
        ++mn34;
    }
    Fn00432ee0();
    ResetRef_a85218(mpOwner118);
    if (automaton) {
        static_cast<cIGZUnknown*>(automaton)->Release();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0042d880 score 164
void cSC4MySim::Slot04_a84c10(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    fieldbc = static_cast<uint8_t>(a);
    reinterpret_cast<cRZString*>(field38)->Copy(*OB_PTR(cRZString, b));
    mbMale = static_cast<uint8_t>(c) != 0;
    field112 = static_cast<uint8_t>(d) != 0;
    mnNameId = f;
    if (f == 0) {
        cRZString* surname = OB_PTR(cRZString, g);
        if (surname) {
            *reinterpret_cast<cRZString*>(field130) = *surname;
        }
    }
    cRZString* nickname = OB_PTR(cRZString, e);
    if (nickname) {
        *reinterpret_cast<cRZString*>(&Word_a85218(this, 0x118)) = *nickname;
    }
    mnBirthMonth = static_cast<uint8_t>(static_cast<int32_t>(mnRefA) % 12);
    mnNameKind = 1;
    cView3D_a85218* view = gpB43dc4;
    if (view) {
        cDispatch_a85218* tool = gpB20e0c;
        if (tool) {
            if (view->Fn24() == tool) {
                view->Fn26(0);
            }
        }
    }
    cDispatch_a85218* old = gpB20e0c;
    if (old) {
        gpB20e0c = 0;
        old->Release();
    }
    void* mem = operator new(0x4c);
    cMoveInTool_a85218* moveIn = mem ? static_cast<cMoveInTool_a85218*>(mem)->Fn00439fc0() : 0;
    if (moveIn->Fn0043a730(this)) {
        cDispatch_a85218* previous = gpB20e0c;
        cDispatch_a85218* tool = reinterpret_cast<cDispatch_a85218*>(moveIn);
        if (tool != previous) {
            if (tool) {
                tool->AddRef();
            }
            gpB20e0c = tool;
            if (previous) {
                previous->Release();
            }
        }
        gpB43dc4->Fn25(gpB20e0c, 2);
    }
    Word_a85218(this, 0x298) = 0;
    Slot34_a84c10();
}
#endif
