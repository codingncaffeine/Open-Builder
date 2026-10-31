#include <stddef.h>
#include <new>
#include <deque>
#include <map>

#include "classes/cSC4MySimDispatch.h"
#include "gzcom/cIGZUnknown.h"
#include "common/compiler.h"
#include "game/Globals.h"

// ---- views ---------------------------------------------------------------------------------------------------------

#ifdef _MSC_VER
#define NOINLINE_a857cc __declspec(noinline)
#else
#define NOINLINE_a857cc
#endif

// The framework's streams: only the slots used here are named (cIGZOStream / cIGZIStream).
struct cOStream_a857cc {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void SetSint32(int32_t value);
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void SetFloat32(float value);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual bool GetError();
};
struct cIStream_a857cc {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void GetSint32(int32_t* pValue);
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void GetFloat32(float* pValue);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual bool GetError();
};

// The automaton the dispatch tool drives (an occupant's interface 0xa9b40f05): only the slots used here are named.
struct cAutomaton_a857cc : public cIGZUnknown {
    virtual void Pad03();
    virtual void Pad04();
    virtual void* Fn05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Fn13(uint32_t a);
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual bool Fn19(uint32_t a);
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
    virtual void Fn40(void* a);
};
// The path finder the dispatch tool uses.
struct cPathFinder_a857cc {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn08(void* a);
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Fn15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Fn22();
};

struct Node_a857cc;

// The sim dispatch tool's place: a ref-counted occupant and where it is (cSC4MySimDispatch::cLocation).
struct cLocation_a857cc {
    cIGZUnknown* mpOccupant;  // 0x00
    float mfX;                // 0x04
    float mfZ;                // 0x08
    int32_t mnCellX;          // 0x0c
    int32_t mnCellZ;          // 0x10
    uint32_t mn14;            // 0x14
    uint32_t mn18;            // 0x18
    bool mbSet;               // 0x1c
    bool mbFlag1d;            // 0x1d
    uint8_t mPad1e[2];        // 0x1e
    uint32_t mn20;            // 0x20
    uint32_t mn24;            // 0x24
    cLocation_a857cc();
    cLocation_a857cc(const cLocation_a857cc& other);
    ~cLocation_a857cc()
    {
        if (mpOccupant) {
            mpOccupant->Release();
        }
    }
    cLocation_a857cc& operator=(const cLocation_a857cc& other);
    bool IsValid() const;
    // STUB: 0x00434520
    bool AnyTravelConnectionExists(int32_t a, int32_t b);
    bool SetByOccupant(cIGZUnknown* pOccupant);
    bool Differs(const cLocation_a857cc& other) const;
    bool HasInterface(cIGZUnknown** ppObject);
    bool Write(cOStream_a857cc* pStream) const;
    bool Read(cIStream_a857cc* pStream);
    // STUB: 0x00431640
    bool Equals(const cLocation_a857cc& other) const;
    void SetCellPosition(int32_t x, int32_t z);
    void SetPosition(float x, float z);
    void Reset();
};

// A rectangle of two corners.
struct Rect_a857cc {
    int32_t mnX0;
    int32_t mnY0;
    int32_t mnX1;
    int32_t mnY1;
    void Normalize();
};

// A node of the red-black tree the maps are (links, then the value).
struct Node_a857cc {
    uint32_t mnColour;
    Node_a857cc* mpParent;
    Node_a857cc* mpLeft;
    Node_a857cc* mpRight;
};
struct Tree_a857cc {
    // STUB: 0x00431b80
    void EraseSubtree(Node_a857cc* pNode);
};

// The three-byte records (a cell and a flag) of the dispatch tool's route.
struct Tri_a857cc {
    uint8_t mnB[3];
};
struct TriIt_a857cc {
    Tri_a857cc* mpCur;
    Tri_a857cc* mpFirst;
    Tri_a857cc* mpLast;
    Tri_a857cc** mpNode;
    void Advance(int32_t n);
    void Increment()
    {
        ++mpCur;
        if (mpCur == mpLast) {
            ++mpNode;
            mpFirst = *mpNode;
            mpLast = mpFirst + 42;
            mpCur = mpFirst;
        }
    }
};
struct TriDeque_a857cc {
    Tri_a857cc* mpStartCur;     // 0x00
    Tri_a857cc* mpStartFirst;   // 0x04
    Tri_a857cc* mpStartLast;    // 0x08
    Tri_a857cc** mpStartNode;   // 0x0c
    Tri_a857cc* mpFinishCur;    // 0x10
    Tri_a857cc* mpFinishFirst;  // 0x14
    Tri_a857cc* mpFinishLast;   // 0x18
    Tri_a857cc** mpFinishNode;  // 0x1c
    void PushBack(const Tri_a857cc& value);
    int32_t Size() const;
    // STUB: 0x006db440
    void Clear();
    Tri_a857cc** mpMap;
    uint32_t mnMapSize;
    // STUB: 0x00432ba0
    Tri_a857cc& At(int32_t n) const;
    // STUB: 0x004344a0
    TriDeque_a857cc* Construct(TriIt_a857cc first, TriIt_a857cc last);
    // STUB: 0x00432d90
    void RangeInit(TriIt_a857cc first, TriIt_a857cc last, uint32_t tag);
    // STUB: 0x00431e00
    void InitializeMap(uint32_t nodes);
    // STUB: 0x004321b0
    void ReallocateMap(uint32_t nodes, bool atFront);
    // STUB: 0x004335f0
    void PushBackAux(const Tri_a857cc& value);
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// The key frames (a map from an id to four words, a node's links first).
struct KeyFrame_a857cc {
    uint32_t mnX;
    uint32_t mnY;
    uint32_t mnZ;
    uint32_t mnW;
};
struct KeyNode_a857cc {
    uint32_t mnColour;
    KeyNode_a857cc* mpParent;
    KeyNode_a857cc* mpLeft;
    KeyNode_a857cc* mpRight;
    int32_t mnKey;
    KeyFrame_a857cc mFrame;
};
struct KeyIt_a857cc {
    KeyNode_a857cc* mpNode;
};
struct KeyTree_a857cc {
    KeyNode_a857cc* mpHeader;
    uint32_t mnSize;
    // STUB: 0x006c0030
    KeyIt_a857cc* Find(KeyIt_a857cc* pOut, const int32_t* pKey) const;
    // STUB: 0x00434f00
    KeyFrame_a857cc* Index(const int32_t* pKey);
    // STUB: 0x00433660
    KeyIt_a857cc* InsertHint(KeyIt_a857cc* pOut, KeyIt_a857cc hint, const KeyNode_a857cc* pPair);
};

#define KEYS_a857cc(self) reinterpret_cast<KeyTree_a857cc*>(reinterpret_cast<char*>(self) + 0x150)
#define PATH_a857cc(self) reinterpret_cast<TriDeque_a857cc*>(reinterpret_cast<char*>(self) + 0x128)

// STUB: 0x00424ec0
bool Fn00424ec0(const uint32_t* a, const uint32_t* b);


// The deque of locations (forty-byte records, three to a node): an iterator is four words, a deque two iterators and the map.
struct LocIt_a857cc {
    cLocation_a857cc* mpCur;
    cLocation_a857cc* mpFirst;
    cLocation_a857cc* mpLast;
    cLocation_a857cc** mpNode;
};
struct LocDeque_a857cc {
    LocIt_a857cc mStart;          // 0x00
    LocIt_a857cc mFinish;         // 0x10
    cLocation_a857cc** mpMap;     // 0x20
    uint32_t mnMapSize;           // 0x24
    // STUB: 0x00432c20
    void PopFrontAux();
    // STUB: 0x00433870
    void Clear();
    // STUB: 0x00433550
    void Destroy();
    // STUB: 0x008ec5b0
    void ReallocateMap(uint32_t nodes, bool atFront);
    // STUB: 0x00433950
    void PushBackAux(const cLocation_a857cc& value);
    // STUB: 0x004339e0
    void PushFrontAux(const cLocation_a857cc& value);
    // STUB: 0x006da8d0
    void DestroyNodes(cLocation_a857cc** pFrom, cLocation_a857cc** pTo);
};

// STUB: 0x009eeb70
void* Fn009eeb70(void* pTo, const void* pFrom, uint32_t nBytes);
// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t nBytes);


// The traffic network map: only the slots used here are named.
struct cTrafficMap_a857cc {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual uint32_t Fn08(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
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
    virtual bool Fn25(void* a, uint32_t b, uint32_t c, uint32_t d);
};
// GLOBAL: 0x00b43d54
extern cTrafficMap_a857cc* gpB43d54;

// A message the dispatch tool tells its target (the slots used are named).
struct cMessage_a857cc {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetType(uint32_t type);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void SetA(uint32_t a);
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void SetB(uint32_t b);
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void SetC(uint32_t c);
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void SetD(uint32_t d);
    // STUB: 0x009134d6
    cMessage_a857cc* Construct();
};
struct cSink_a857cc {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Send(cMessage_a857cc* pMessage);
};
struct cTarget_a857cc {
    uint32_t mPad[4];
    cSink_a857cc mSink;
};
// STUB: 0x009133da
void* Fn009133da(uint32_t nBytes);


// The notification-sending parts of the world the dispatch tool uses at start (only the slots used are named).
struct cTrafficSim_a857cc {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void GetPathFinder(void** ppOut);
};
// GLOBAL: 0x00b43da8
extern cTrafficSim_a857cc* gpB43da8;
// GLOBAL: 0x00b43dbc
extern cIGZUnknown* gpB43dbc;
struct cAtm_a857cc {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05(void* pTarget, uint32_t id);
    virtual void Fn06(void* pTarget, uint32_t id);
};
// STUB: 0x00602600
cAtm_a857cc* Fn00602600();


// The lot manager and the lots it hands out (the slots used are named).
struct cLot_a857cc {
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
    virtual void GetRect(void* pOut);
};
struct cLotManager_a857cc {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual cLot_a857cc* FindLotAt(int32_t x, int32_t z, uint32_t flags);
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual cLot_a857cc* FindLotOf(cIGZUnknown* pOccupant);
};
// GLOBAL: 0x00b43d08
extern cLotManager_a857cc* gpB43d08;

// STUB: 0x00431370
void Fn00431370(float x, float z, int32_t* pCellX, int32_t* pCellZ);

// ---- functions ---------------------------------------------------------------------------------------------------------

#ifdef OB_DRAFTS
// CLOSE: 0x00431270 score 12
bool cSC4MySimDispatch::Fn00431270(uint32_t value)
{
    uint32_t old = mnFn50;
    mnFn50 = value;
    if (value != old) {
        ++mnChangeCount;
    }
    return true;
}
#endif

// FUNCTION: 0x00431300
const float* Fn00431300(const float* a, const float* b)
{
    return (*b < *a) ? b : a;
}

// FUNCTION: 0x004312e0
void Rect_a857cc::Normalize()
{
    int32_t a = mnX0;
    int32_t b = mnX1;
    if (a > b) {
        mnX0 = b;
        mnX1 = a;
    }
    a = mnY0;
    b = mnY1;
    if (a > b) {
        mnY0 = b;
        mnY1 = a;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x004312c0 score 14
int32_t cSC4MySimDispatch::GetTransitSwitchWaitTimeMunutes()
{
    if (!((mnFlags >> 4) & 1)) {
        if (mnClock - mnTransitSwitchStart > 15) {
            mnTransitSwitchStart = 0;
        }
    }
    return mnTransitSwitchStart;
}
#endif

// FUNCTION: 0x00434620
cSC4MySimDispatch_c* GZCOM_CreatecSC4MySimDispatch()
{
    void* mem = operator new(0x18c);
    cSC4MySimDispatch* p = 0;
    if (mem) {
        p = static_cast<cSC4MySimDispatch*>(static_cast<cSC4MySimDispatch*>(mem)->Fn00433a60(0));
    }
    return p;
}

// FUNCTION: 0x00431400
void cLocation_a857cc::SetPosition(float x, float z)
{
    mfX = x;
    mfZ = z;
    Fn00431370(x, z, &mnCellX, &mnCellZ);
}

// FUNCTION: 0x004311b0
void cLocation_a857cc::SetCellPosition(int32_t x, int32_t z)
{
    mnCellX = x;
    mnCellZ = z;
    mfX = static_cast<float>(x << 4);
    mfZ = static_cast<float>(z << 4);
}

// FUNCTION: 0x00434470
void TriDeque_a857cc::PushBack(const Tri_a857cc& value)
{
    if (mpFinishCur != mpFinishLast - 1) {
        if (mpFinishCur) {
            *mpFinishCur = value;
        }
        ++mpFinishCur;
    } else {
        PushBackAux(value);
    }
}

// FUNCTION: 0x004316f0
void cLocation_a857cc::Reset()
{
    cIGZUnknown* old = mpOccupant;
    mbFlag1d = false;
    mbSet = 1;
    if (old) {
        mpOccupant = 0;
        old->Release();
    }
    mnCellX = -1;
    mnCellZ = -1;
    mfX = -16.0f;
    mfZ = -16.0f;
}

// FUNCTION: 0x00431b80
void Tree_a857cc::EraseSubtree(Node_a857cc* pNode)
{
    while (pNode) {
        EraseSubtree(pNode->mpRight);
        Node_a857cc* pLeft = pNode->mpLeft;
        Fn0090cf63(pNode);
        pNode = pLeft;
    }
}

// ---- batch 2 -----------------------------------------------------------------------------------------------------------

#define LOC_AT_a857cc(self, off) reinterpret_cast<cLocation_a857cc*>(reinterpret_cast<char*>(self) + (off))

// STUB: 0x005d99a0
void Fn005d99a0(cOStream_a857cc* stream, cIGZUnknown* value);
// STUB: 0x005d9fd0
void Fn005d9fd0(cOStream_a857cc* stream, bool value);
// STUB: 0x005d9730
void Fn005d9730(cIStream_a857cc* stream, uint32_t id, void* object, uint32_t flags);
// STUB: 0x005d9fa0
void Fn005d9fa0(cIStream_a857cc* stream, uint8_t* pValue);
#ifdef OB_DRAFTS
// CLOSE: 0x00431320 score 23
cLocation_a857cc::cLocation_a857cc()
{
    mpOccupant = 0;
    mnCellX = -1;
    mnCellZ = -1;
    mn14 = 0xffffffff;
    mn18 = 0xffffffff;
    mbFlag1d = false;
    mn20 = 0;
    mn24 = 0;
    mbSet = true;
    SetCellPosition(mnCellX, mnCellZ);
}
#endif

// FUNCTION: 0x00425890
cLocation_a857cc::cLocation_a857cc(const cLocation_a857cc& other)
{
    cIGZUnknown* pOcc = other.mpOccupant;
    mpOccupant = pOcc;
    if (pOcc) {
        pOcc->AddRef();
    }
    mfX = other.mfX;
    mfZ = other.mfZ;
    mnCellX = other.mnCellX;
    mnCellZ = other.mnCellZ;
    mn14 = other.mn14;
    mn18 = other.mn18;
    mbSet = other.mbSet;
    mbFlag1d = other.mbFlag1d;
    mn20 = other.mn20;
    mn24 = other.mn24;
}

// FUNCTION: 0x00425f80
cLocation_a857cc& cLocation_a857cc::operator=(const cLocation_a857cc& other)
{
    if (&other != this) {
        cIGZUnknown* pNew = other.mpOccupant;
        cIGZUnknown* pOld = mpOccupant;
        if (pNew != pOld) {
            if (pNew) {
                pNew->AddRef();
            }
            mpOccupant = pNew;
            if (pOld) {
                pOld->Release();
            }
        }
    }
    mfX = other.mfX;
    mfZ = other.mfZ;
    mnCellX = other.mnCellX;
    mnCellZ = other.mnCellZ;
    mn14 = other.mn14;
    mn18 = other.mn18;
    mbSet = other.mbSet;
    mbFlag1d = other.mbFlag1d;
    mn20 = other.mn20;
    mn24 = other.mn24;
    return *this;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00431430 score 39
bool cLocation_a857cc::SetByOccupant(cIGZUnknown* pOccupant)
{
    cLocation_a857cc blank;
    *this = blank;
    mbSet = true;
    cIGZUnknown* pOld = mpOccupant;
    if (pOccupant != pOld) {
        if (pOccupant) {
            pOccupant->AddRef();
        }
        mpOccupant = pOccupant;
        if (pOld) {
            pOld->Release();
        }
    }
    if (mpOccupant) {
        float pos[3];
        (*reinterpret_cast<void (**)(void*, float*)>(*reinterpret_cast<char**>(mpOccupant) + 0x20))(mpOccupant, pos);
        mfX = pos[0];
        mfZ = pos[2];
        Fn00431370(pos[0], pos[2], &mnCellX, &mnCellZ);
    }
    return true;
}
#endif

// FUNCTION: 0x00434f90
bool cLocation_a857cc::IsValid() const
{
    if (mbSet) {
        if (mnCellX >= 0 && mnCellZ >= 0 && mnCellX < static_cast<int32_t>(gpB43cec->CellCountX())
            && mnCellZ < static_cast<int32_t>(gpB43cec->CellCountZ())) {
            return true;
        }
        return false;
    }
    return const_cast<cLocation_a857cc*>(this)->AnyTravelConnectionExists(mn14, mn18);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00431690 score 51
bool cLocation_a857cc::Differs(const cLocation_a857cc& other) const
{
    bool same = false;
    if (mbSet == other.mbSet && mpOccupant == other.mpOccupant && mbFlag1d == other.mbFlag1d
        && mnCellX == other.mnCellX && mnCellZ == other.mnCellZ) {
        same = Fn00424ec0(&mn14, &other.mn14);
    }
    return !same;
}
#endif

// FUNCTION: 0x00431730
bool cLocation_a857cc::HasInterface(cIGZUnknown** ppObject)
{
    cIGZUnknown* found = 0;
    cIGZUnknown* pObject = *ppObject;
    if (pObject) {
        if (pObject->QueryInterface(0x87dda3a9, reinterpret_cast<void**>(&found))) {
            if (found) {
                found->Release();
            }
            return true;
        }
        if (found) {
            found->Release();
        }
    }
    return false;
}

// FUNCTION: 0x004314f0
bool cLocation_a857cc::Write(cOStream_a857cc* pStream) const
{
    Fn005d99a0(pStream, mpOccupant);
    pStream->SetFloat32(mfX);
    pStream->SetFloat32(mfZ);
    pStream->SetSint32(mnCellX);
    pStream->SetSint32(mnCellZ);
    pStream->SetSint32(static_cast<int32_t>(mn14));
    pStream->SetSint32(static_cast<int32_t>(mn18));
    Fn005d9fd0(pStream, mbSet);
    Fn005d9fd0(pStream, mbFlag1d);
    pStream->SetSint32(static_cast<int32_t>(mn20));
    pStream->SetSint32(static_cast<int32_t>(mn24));
    return !pStream->GetError();
}

#ifdef OB_DRAFTS
// CLOSE: 0x00431590 score 42
bool cLocation_a857cc::Read(cIStream_a857cc* pStream)
{
    if (mpOccupant) {
        cIGZUnknown* pOld = mpOccupant;
        mpOccupant = 0;
        pOld->Release();
    }
    Fn005d9730(pStream, 0x26bb767e, this, 0);
    pStream->GetFloat32(&mfX);
    pStream->GetFloat32(&mfZ);
    pStream->GetSint32(&mnCellX);
    pStream->GetSint32(&mnCellZ);
    pStream->GetSint32(reinterpret_cast<int32_t*>(&mn14));
    pStream->GetSint32(reinterpret_cast<int32_t*>(&mn18));
    Fn005d9fa0(pStream, reinterpret_cast<uint8_t*>(&mbSet));
    Fn005d9fa0(pStream, reinterpret_cast<uint8_t*>(&mbFlag1d));
    pStream->GetSint32(reinterpret_cast<int32_t*>(&mn20));
    pStream->GetSint32(reinterpret_cast<int32_t*>(&mn24));
    return !pStream->GetError();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00431bc0 score 21
bool cSC4MySimDispatch::SetFlag(uint32_t mask, bool set)
{
    uint32_t old = mnFlags;
    if (set) {
        mnFlags = old | mask;
    } else {
        mnFlags = old & ~mask;
    }
    if (old != mnFlags) {
        Notify(0x4bb2d020, old, mnFlags, 0);
        ++mnChangeCount;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00431fe0 score 4
void cSC4MySimDispatch::Fn00431fe0()
{
    bool bit = ((mnFlags >> 8) & 1) != 0;
    Fn00431f70();
    uint32_t old = mnFlags;
    uint32_t now;
    if (bit) {
        now = old | 0x100;
    } else {
        now = old & ~0x100u;
    }
    mnFlags = now;
    if (old != now) {
        Notify(0x4bb2d020, old, now, 0);
        ++mnChangeCount;
    }
}
#endif

// FUNCTION: 0x00431c10
bool cSC4MySimDispatch::SetState(uint32_t state)
{
    mnPrevState = mnState;
    mnState = state;
    if (state == 3) {
        uint32_t old = mnFlags;
        mnFlags = old | 2;
        if (old != mnFlags) {
            Notify(0x4bb2d020, old, mnFlags, 0);
            ++mnChangeCount;
        }
    }
    if (mnPrevState != mnState) {
        Notify(0x4bb2cfc0, mnPrevState, mnState, 0);
        ++mnChangeCount;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00431c70 score 9
void cSC4MySimDispatch::Fn00431c70()
{
    *LOC_AT_a857cc(this, 0x5c) = *LOC_AT_a857cc(this, 0xd4);
    if (mnFn50 != 0xfe) {
        ++mnChangeCount;
    }
    uint32_t state = mnState;
    ++mnChangeCount;
    mnFn50 = 0xfe;
    LOC_AT_a857cc(this, 0x5c)->mn24 = LOC_AT_a857cc(this, 0x5c)->mn20 + mnClock;
    uint32_t old = mnFlags;
    uint32_t now = old | 2;
    mnPrevState = state;
    mnState = 3;
    mnFlags = now;
    if (old != now) {
        Notify(0x4bb2d020, old, now, 0);
        ++mnChangeCount;
    }
    if (mnPrevState != mnState) {
        Notify(0x4bb2cfc0, mnPrevState, mnState, 0);
        ++mnChangeCount;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00431780 score 59
void* cSC4MySimDispatch::Fn00431780()
{
    void* result = 0;
    uint32_t flags = mnFlags;
    if (!((flags >> 2) & 1) && ((flags >> 8) & 1)) {
        cIGZUnknown* pAuto = static_cast<cIGZUnknown*>(mpAutomaton);
        if (pAuto) {
            result = pAuto;
        }
        if (mnState == 3 || ((flags >> 4) & 1)) {
            cIGZUnknown* pOcc = *reinterpret_cast<cIGZUnknown**>(LOC_AT_a857cc(this, 0x5c));
            if (pOcc) {
                cIGZUnknown* pFound = 0;
                if (!pOcc->QueryInterface(0xc9b6d7d6, reinterpret_cast<void**>(&pFound))) {
                    result = pOcc;
                }
                if (pFound) {
                    pFound->Release();
                }
            }
        }
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00431d00 score 41
bool cSC4MySimDispatch::CanUDriveIt()
{
    cIGZUnknown* pFound = 0;
    if (mnState == 2) {
        pFound = 0;
        cIGZUnknown* pAuto = static_cast<cIGZUnknown*>(mpAutomaton);
        if (pAuto) {
            if (pAuto->QueryInterface(0xa9b40f05, reinterpret_cast<void**>(&pFound)) && mnFn50 == 1) {
                if (pFound) {
                    pFound->Release();
                }
                return true;
            }
        }
    }
    cIGZUnknown* pKeep = pFound;
    if (mnState == 3) {
        cLocation_a857cc* pHere = LOC_AT_a857cc(this, 0x5c);
        if (pHere->Equals(*LOC_AT_a857cc(this, 0x84)) || pHere->Equals(*LOC_AT_a857cc(this, 0xd4))) {
            if (pKeep) {
                pKeep->Release();
            }
            return true;
        }
    }
    if (pKeep) {
        pKeep->Release();
    }
    return false;
}
#endif

// ---- the deques of the route (three-byte records) ------------------------------------------------------------------------

// FUNCTION: 0x00431db0
int32_t TriDeque_a857cc::Size() const
{
    return (mpFinishNode - mpStartNode - 1) * 42 + (mpFinishCur - mpFinishFirst) + (mpStartLast - mpStartCur);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00431af0 score 8
void TriIt_a857cc::Advance(int32_t n)
{
    int32_t off = n + (mpCur - mpFirst);
    if (off >= 0 && off < 42) {
        mpCur += n;
    } else {
        int32_t step;
        if (off > 0) {
            step = off / 42;
        } else {
            step = -((-off - 1) / 42) - 1;
        }
        mpNode += step;
        mpFirst = *mpNode;
        mpLast = mpFirst + 42;
        mpCur = mpFirst + (off - step * 42);
    }
}
#endif

// ---- batch 3 -----------------------------------------------------------------------------------------------------------

// What the dispatch manager hands out from its slot 22.
struct cTrackSet_a857cc {
    // STUB: 0x0046efb0
    void Fn0046efb0(int32_t handle, uint32_t flag);
};
struct cDispatchManager_a857cc {
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
    virtual cTrackSet_a857cc* Fn22();
};
// GLOBAL: 0x00b43d04
extern cDispatchManager_a857cc* gpB43d04;
// GLOBAL: 0x00b43d44
extern void* gpB43d44;
// GLOBAL: 0x00b43d48
extern void* gpB43d48;

// FUNCTION: 0x00431820
void* OB_STDCALL Fn00431820(int32_t id)
{
    switch (id) {
    case 0x4107:
    case 0x4149:
    case 0x414a:
        return gpB43d48;
    case 0x4200:
    case 0x420b:
    case 0x4215:
    case 0x4217:
    case 0x422c:
    case 0x422e:
        return gpB43d44;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004320d0 score 17
void cSC4MySimDispatch::Fn004320d0()
{
    uint32_t flags = mnFlags;
    if ((flags & 0x12) || mnFn50 <= 1) {
        if (!(mnFlags & 1)) {
            uint32_t now = flags | 0x2401;
            mnFlags = now;
            if (flags != now) {
                Notify(0x4bb2d020, flags, now, 0);
                ++mnChangeCount;
            }
        }
    }
    uint32_t old = mnFlags;
    uint32_t now = old | 0x440;
    mnFlags = now;
    if (old != now) {
        Notify(0x4bb2d020, old, now, 0);
        ++mnChangeCount;
    }
    Notify(0xeba06c12, 0, 0, 0);
}
#endif

// FUNCTION: 0x00432030
bool cSC4MySimDispatch::Fn00432030(void* pNew)
{
    if (mpFc != pNew) {
        Fn00431fe0();
    }
    cAutomaton_a857cc* pFound = 0;
    cIGZUnknown* pAuto = static_cast<cIGZUnknown*>(mpAutomaton);
    if (pAuto) {
        if (pAuto->QueryInterface(0xa9b40f05, reinterpret_cast<void**>(&pFound))) {
            if (pFound->Fn05() != pNew) {
                pFound->Fn40(reinterpret_cast<char*>(this) + 8);
                pFound->Fn13(0);
            }
        }
    }
    cIGZUnknown* pOld = static_cast<cIGZUnknown*>(mpAutomaton);
    if (pNew != pOld) {
        if (pNew) {
            static_cast<cIGZUnknown*>(pNew)->AddRef();
        }
        mpAutomaton = pNew;
        if (pOld) {
            pOld->Release();
        }
    }
    ++mnChangeCount;
    if (pFound) {
        pFound->Release();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00432860 score 58
bool cSC4MySimDispatch::Fn00432860(int32_t key, uint32_t value, bool flag)
{
    KeyTree_a857cc* pKeys = KEYS_a857cc(this);
    KeyIt_a857cc it;
    pKeys->Find(&it, &key);
    if (it.mpNode == pKeys->mpHeader) {
        return false;
    }
    it.mpNode->mFrame.mnW = value;
    if (flag) {
        cAutomaton_a857cc* pFound = 0;
        cIGZUnknown* pAuto = static_cast<cIGZUnknown*>(mpAutomaton);
        if (pAuto) {
            if (pAuto->QueryInterface(0xa9b40f05, reinterpret_cast<void**>(&pFound))) {
                bool result = pFound->Fn19(value);
                if (pFound) {
                    pFound->Release();
                }
                return result;
            }
            if (pFound) {
                pFound->Release();
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00432900 score 31
void cSC4MySimDispatch::Fn00432900(void* pOut, int32_t key)
{
    KeyTree_a857cc* pKeys = KEYS_a857cc(this);
    KeyIt_a857cc it;
    pKeys->Find(&it, &key);
    uint32_t* pValue = static_cast<uint32_t*>(pOut);
    if (it.mpNode != pKeys->mpHeader) {
        pValue[0] = it.mpNode->mFrame.mnX;
        pValue[1] = it.mpNode->mFrame.mnY;
        pValue[2] = it.mpNode->mFrame.mnZ;
    } else {
        pValue[0] = 0;
        pValue[1] = 0;
        pValue[2] = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00432960 score 10
int32_t cSC4MySimDispatch::Fn00432960(int32_t key)
{
    KeyTree_a857cc* pKeys = KEYS_a857cc(this);
    KeyIt_a857cc it;
    pKeys->Find(&it, &key);
    if (it.mpNode != pKeys->mpHeader) {
        return static_cast<int32_t>(it.mpNode->mFrame.mnW);
    }
    return -1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00434ff0 score 12
bool cSC4MySimDispatch::Fn00434ff0(int32_t key, const void* pVec, uint32_t w)
{
    const uint32_t* pIn = static_cast<const uint32_t*>(pVec);
    uint32_t x = pIn[0];
    uint32_t y = pIn[1];
    uint32_t z = pIn[2];
    KeyFrame_a857cc* pFrame = KEYS_a857cc(this)->Index(&key);
    pFrame->mnY = y;
    pFrame->mnX = x;
    pFrame->mnZ = z;
    pFrame->mnW = w;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00431f70 score 12
bool cSC4MySimDispatch::Fn00431f70()
{
    uint32_t old = mnFlags;
    uint32_t now = old & ~0x100u;
    mnFlags = now;
    if (old != now) {
        Notify(0x4bb2d020, old, now, 0);
        ++mnChangeCount;
    }
    if (mnTrackHandle != -1) {
        cDispatchManager_a857cc* pManager = gpB43d04;
        if (pManager) {
            pManager->Fn22()->Fn0046efb0(mnTrackHandle, 0);
            mnTrackHandle = -1;
        }
    }
    cIGZUnknown* pRef = static_cast<cIGZUnknown*>(mpFc);
    if (pRef) {
        mpFc = 0;
        pRef->Release();
    }
    return true;
}
#endif

// ---- batch 4: the containers ---------------------------------------------------------------------------------------------

// FUNCTION: 0x00431ed0
void Fn00431ed0(LocIt_a857cc first, LocIt_a857cc last)
{
    while (first.mpCur != last.mpCur) {
        if (first.mpCur->mpOccupant) {
            first.mpCur->mpOccupant->Release();
        }
        first.mpCur += 1;
        if (first.mpCur == first.mpLast) {
            ++first.mpNode;
            first.mpFirst = *first.mpNode;
            first.mpLast = first.mpFirst + 3;
            first.mpCur = first.mpFirst;
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00431f10 score 44
Tri_a857cc* Fn00431f10(TriIt_a857cc first, TriIt_a857cc last, Tri_a857cc* pDest)
{
    while (first.mpCur != last.mpCur) {
        if (pDest) {
            *pDest = *first.mpCur;
        }
        first.Increment();
        ++pDest;
    }
    return pDest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004323e0 score 24
void Fn004323e0(TriIt_a857cc first, TriIt_a857cc last)
{
    while (first.mpCur != last.mpCur) {
        first.Increment();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004321b0 score 134
void TriDeque_a857cc::ReallocateMap(uint32_t nodes, bool atFront)
{
    uint32_t oldNodes = static_cast<uint32_t>(mpFinishNode - mpStartNode) + 1;
    uint32_t newNodes = nodes + oldNodes;
    Tri_a857cc** pNewStart;
    if (mnMapSize > 2 * newNodes) {
        pNewStart = mpMap + (mnMapSize - newNodes) / 2 + (atFront ? nodes : 0);
        if (pNewStart < mpStartNode) {
            Fn009eeb70(pNewStart, mpStartNode, oldNodes * 4);
        } else {
            Fn009eeb70(pNewStart + oldNodes - oldNodes, mpStartNode, oldNodes * 4);
        }
    } else {
        uint32_t add = mnMapSize < nodes ? nodes : mnMapSize;
        uint32_t newSize = mnMapSize + add + 2;
        Tri_a857cc** pNewMap = newSize ? static_cast<Tri_a857cc**>(Fn0090cf54(newSize * 4)) : 0;
        pNewStart = pNewMap + (newSize - newNodes) / 2 + (atFront ? nodes : 0);
        Fn009eeb70(pNewStart, mpStartNode, oldNodes * 4);
        if (mpMap) {
            Fn0090cf63(mpMap);
        }
        mpMap = pNewMap;
        mnMapSize = newSize;
    }
    mpStartNode = pNewStart;
    mpStartFirst = *pNewStart;
    mpStartLast = mpStartFirst + 42;
    mpFinishNode = pNewStart + oldNodes - 1;
    mpFinishFirst = *mpFinishNode;
    mpFinishLast = mpFinishFirst + 42;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004335f0 score 4
void TriDeque_a857cc::PushBackAux(const Tri_a857cc& value)
{
    Tri_a857cc copy = value;
    if (mnMapSize - (mpFinishNode - mpMap) < 2) {
        ReallocateMap(1, false);
    }
    mpFinishNode[1] = static_cast<Tri_a857cc*>(Fn0090cf54(0x7e));
    if (mpFinishCur) {
        *mpFinishCur = copy;
    }
    ++mpFinishNode;
    mpFinishFirst = *mpFinishNode;
    mpFinishLast = mpFinishFirst + 42;
    mpFinishCur = mpFinishFirst;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00433950 score 11
void LocDeque_a857cc::PushBackAux(const cLocation_a857cc& value)
{
    cLocation_a857cc copy(value);
    if (mnMapSize - (mFinish.mpNode - mpMap) < 2) {
        ReallocateMap(1, false);
    }
    mFinish.mpNode[1] = static_cast<cLocation_a857cc*>(Fn0090cf54(0x78));
    if (mFinish.mpCur) {
        new (mFinish.mpCur) cLocation_a857cc(copy);
    }
    ++mFinish.mpNode;
    mFinish.mpFirst = *mFinish.mpNode;
    mFinish.mpLast = mFinish.mpFirst + 3;
    mFinish.mpCur = mFinish.mpFirst;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004339e0 score 17
void LocDeque_a857cc::PushFrontAux(const cLocation_a857cc& value)
{
    cLocation_a857cc copy(value);
    if (mStart.mpNode - mpMap < 1) {
        ReallocateMap(1, true);
    }
    mStart.mpNode[-1] = static_cast<cLocation_a857cc*>(Fn0090cf54(0x78));
    --mStart.mpNode;
    mStart.mpFirst = *mStart.mpNode;
    mStart.mpLast = mStart.mpFirst + 3;
    mStart.mpCur = mStart.mpLast - 1;
    if (mStart.mpCur) {
        new (mStart.mpCur) cLocation_a857cc(copy);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00432c20 score 24
void LocDeque_a857cc::PopFrontAux()
{
    if (mStart.mpCur->mpOccupant) {
        mStart.mpCur->mpOccupant->Release();
    }
    if (mStart.mpFirst) {
        Fn0090cf63(mStart.mpFirst);
    }
    ++mStart.mpNode;
    mStart.mpFirst = *mStart.mpNode;
    mStart.mpLast = mStart.mpFirst + 3;
    mStart.mpCur = mStart.mpFirst;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00433870 score 111
void LocDeque_a857cc::Clear()
{
    for (cLocation_a857cc** pNode = mStart.mpNode + 1; pNode < mFinish.mpNode; ++pNode) {
        for (cLocation_a857cc* p = *pNode; p != *pNode + 3; ++p) {
            if (p->mpOccupant) {
                p->mpOccupant->Release();
            }
        }
        if (*pNode) {
            Fn0090cf63(*pNode);
        }
    }
    if (mStart.mpNode != mFinish.mpNode) {
        for (cLocation_a857cc* p = mStart.mpCur; p != mStart.mpLast; ++p) {
            if (p->mpOccupant) {
                p->mpOccupant->Release();
            }
        }
        for (cLocation_a857cc* p = mFinish.mpFirst; p != mFinish.mpCur; ++p) {
            if (p->mpOccupant) {
                p->mpOccupant->Release();
            }
        }
        if (mFinish.mpFirst) {
            Fn0090cf63(mFinish.mpFirst);
        }
    } else {
        for (cLocation_a857cc* p = mStart.mpCur; p != mFinish.mpCur; ++p) {
            if (p->mpOccupant) {
                p->mpOccupant->Release();
            }
        }
    }
    mFinish = mStart;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00433550 score 58
void LocDeque_a857cc::Destroy()
{
    Fn00431ed0(mStart, mFinish);
    if (mpMap) {
        DestroyNodes(mStart.mpNode, mFinish.mpNode + 1);
        if (mpMap) {
            Fn0090cf63(mpMap);
        }
    }
}
#endif

// ---- batch 5 -----------------------------------------------------------------------------------------------------------

#ifdef OB_DRAFTS
// CLOSE: 0x00431a30 score 18
void cSC4MySimDispatch::Notify(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    cTarget_a857cc* pTarget = static_cast<cTarget_a857cc*>(mpTarget);
    if (pTarget) {
        void* pMem = Fn009133da(0x2c);
        cMessage_a857cc* pMessage = pMem ? static_cast<cMessage_a857cc*>(pMem)->Construct() : 0;
        if (pMessage) {
            pMessage->AddRef();
        }
        pMessage->SetType(0x2ba06b99);
        pMessage->SetA(a);
        pMessage->SetB(b);
        pMessage->SetC(c);
        pMessage->SetD(d);
        pTarget->mSink.Send(pMessage);
        pMessage->Release();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00434f00 score 58
KeyFrame_a857cc* KeyTree_a857cc::Index(const int32_t* pKey)
{
    KeyNode_a857cc* pHeader = mpHeader;
    KeyNode_a857cc* pNode = pHeader->mpParent;
    KeyNode_a857cc* pBest = pHeader;
    while (pNode) {
        if (pNode->mnKey < *pKey) {
            pNode = pNode->mpRight;
        } else {
            pBest = pNode;
            pNode = pNode->mpLeft;
        }
    }
    if (pBest == pHeader || *pKey < pBest->mnKey) {
        KeyNode_a857cc pair;
        pair.mnKey = *pKey;
        pair.mFrame.mnX = 0;
        pair.mFrame.mnY = 0;
        pair.mFrame.mnZ = 0;
        pair.mFrame.mnW = 0;
        KeyIt_a857cc hint;
        hint.mpNode = pBest;
        KeyIt_a857cc out;
        InsertHint(&out, hint, &pair);
        pBest = out.mpNode;
    }
    return &pBest->mFrame;
}
#endif

// FUNCTION: 0x00434df0
bool cSC4MySimDispatch::Fn00434df0()
{
    if (mnPathIndex < mnPathCount) {
        Fn00434230();
        if (mnPathIndex < mnPathCount) {
            if (PATH_a857cc(this)->At(mnPathIndex).mnB[2] != 0xfe) {
                return true;
            }
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00433200 score 99
bool cSC4MySimDispatch::Fn00433200()
{
    cTrafficMap_a857cc* pMap = gpB43d54;
    if (mnPathIndex < mnPathCount) {
        TriDeque_a857cc* pPath = PATH_a857cc(this);
        int32_t i = mnPathIndex;
        do {
            TriIt_a857cc itX = *reinterpret_cast<TriIt_a857cc*>(pPath);
            itX.Advance(i);
            TriIt_a857cc itZ = *reinterpret_cast<TriIt_a857cc*>(pPath);
            itZ.Advance(i);
            if (pMap->Fn08(itX.mpCur->mnB[0], itZ.mpCur->mnB[1], 0x1fcf, 0) != 0) {
                return true;
            }
            i = ++mnPathIndex;
        } while (i < mnPathCount);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00434230 score 66
void cSC4MySimDispatch::Fn00434230()
{
    TriDeque_a857cc* pPath = PATH_a857cc(this);
    int32_t size;
    do {
        int32_t i = mnPathCount;
        mnPathIndex = i;
        size = pPath->Size();
        TriIt_a857cc itFirst = *reinterpret_cast<TriIt_a857cc*>(pPath);
        itFirst.Advance(i);
        uint32_t first = itFirst.mpCur->mnB[2];
        if (size > i) {
            do {
                i = mnPathCount;
                TriIt_a857cc it = *reinterpret_cast<TriIt_a857cc*>(pPath);
                it.Advance(i);
                if (first != it.mpCur->mnB[2]) {
                    break;
                }
                ++i;
                mnPathCount = i;
            } while (size > i);
        }
        if (Fn00433200()) {
            return;
        }
        if (mnPathIndex != mnPathCount) {
            return;
        }
        if (first == 0xfe) {
            return;
        }
    } while (mnPathIndex < size);
}
#endif

// ---- batch 6 -----------------------------------------------------------------------------------------------------------

#ifdef OB_DRAFTS
// CLOSE: 0x00433eb0 score 34
bool cSC4MySimDispatch::Init()
{
    cIGZUnknown* pFinder = static_cast<cIGZUnknown*>(mpPathFinder);
    if (!pFinder) {
        cSC4MySimDispatch_8* pSelf = static_cast<cSC4MySimDispatch_8*>(this);
        gpB43ccc->AddNotification(pSelf, 0x44778231);
        gpB43ccc->AddNotification(pSelf, 0x8bbbd22a);
        gpB43ccc->AddNotification(pSelf, 0xa6b79601);
        gpB43ccc->AddNotification(pSelf, 0xa6b79611);
        cAtm_a857cc* pAtm = Fn00602600();
        if (pAtm) {
            pAtm->Fn05(pSelf, 0xff);
        }
        cTrafficSim_a857cc* pTraffic = gpB43da8;
        if (mpPathFinder) {
            cIGZUnknown* pOld = static_cast<cIGZUnknown*>(mpPathFinder);
            mpPathFinder = 0;
            pOld->Release();
        }
        pTraffic->GetPathFinder(&mpPathFinder);
    }
    if (!mbInitPending) {
        cIGZUnknown* pClock = gpB43dbc;
        cIGZUnknown* pOldClock = static_cast<cIGZUnknown*>(mpClock);
        if (pClock != pOldClock) {
            if (pClock) {
                pClock->AddRef();
            }
            mpClock = pClock;
            if (pOldClock) {
                pOldClock->Release();
            }
        }
        cLocation_a857cc blank;
        *LOC_AT_a857cc(this, 0x84) = blank;
        cLocation_a857cc blank2;
        cLocation_a857cc* pCommute = LOC_AT_a857cc(this, 0xd4);
        *pCommute = blank2;
        pCommute->mbFlag1d = true;
        *LOC_AT_a857cc(this, 0x5c) = *pCommute;
        SetState(3);
        ResetPath();
        mbFollowCamera = false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00434080 score 31
bool cSC4MySimDispatch::Fn00434080()
{
    Fn00431f70();
    cAutomaton_a857cc* pFound = 0;
    cIGZUnknown* pAuto = static_cast<cIGZUnknown*>(mpAutomaton);
    if (pAuto) {
        if (pAuto->QueryInterface(0xa9b40f05, reinterpret_cast<void**>(&pFound))) {
            pFound->Fn40(static_cast<cSC4MySimDispatch_8*>(this));
            pFound->Fn13(0);
        }
    }
    uint32_t flags = mnFlags;
    mnFlags = 0;
    if (flags != 0) {
        Notify(0x4bb2d020, flags, 0, 0);
        ++mnChangeCount;
    }
    reinterpret_cast<LocDeque_a857cc*>(reinterpret_cast<char*>(this) + 0x160)->Clear();
    {
        cLocation_a857cc blank;
        *LOC_AT_a857cc(this, 0x5c) = blank;
    }
    {
        cLocation_a857cc blank;
        *LOC_AT_a857cc(this, 0xac) = blank;
    }
    {
        cLocation_a857cc blank;
        *LOC_AT_a857cc(this, 0x84) = blank;
    }
    if (mnFn50 != 0xff) {
        ++mnChangeCount;
        mnFn50 = 0xff;
    }
    uint32_t prev = mnState;
    mnPrevState = prev;
    mnState = 0xffffffff;
    if (prev != 0xffffffff) {
        Notify(0x4bb2cfc0, prev, 0xffffffff, 0);
        ++mnChangeCount;
    }
    ResetPath();
    cIGZUnknown* pOccupant = static_cast<cIGZUnknown*>(mpAutomaton);
    if (pOccupant) {
        mpAutomaton = 0;
        pOccupant->Release();
    }
    if (pFound) {
        pFound->Release();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00433d70 score 99
void cSC4MySimDispatch::Fn00433d70()
{
    cIGZUnknown* pTarget = static_cast<cIGZUnknown*>(mpTarget);
    if (pTarget) {
        mpTarget = 0;
        pTarget->Release();
    }
    reinterpret_cast<LocDeque_a857cc*>(reinterpret_cast<char*>(this) + 0x160)->Destroy();
    KeyTree_a857cc* pKeys = KEYS_a857cc(this);
    if (pKeys->mnSize) {
        reinterpret_cast<Tree_a857cc*>(pKeys)->EraseSubtree(reinterpret_cast<Node_a857cc*>(pKeys->mpHeader->mpParent));
        pKeys->mpHeader->mpLeft = pKeys->mpHeader;
        pKeys->mpHeader->mpParent = 0;
        pKeys->mpHeader->mpRight = pKeys->mpHeader;
        pKeys->mnSize = 0;
    }
    Fn0090cf63(pKeys->mpHeader);
    cIGZUnknown* pRef = static_cast<cIGZUnknown*>(mpPathFinder);
    if (pRef) {
        pRef->Release();
    }
    pRef = static_cast<cIGZUnknown*>(mpClock);
    if (pRef) {
        pRef->Release();
    }
    pRef = static_cast<cIGZUnknown*>(mpTarget);
    if (pRef) {
        pRef->Release();
    }
    pRef = static_cast<cIGZUnknown*>(mpAutomaton);
    if (pRef) {
        pRef->Release();
    }
    cIGZUnknown* pFc = static_cast<cIGZUnknown*>(mpFc);
    if (pFc) {
        pFc->Release();
    }
}
#endif

// ---- batch 7 -----------------------------------------------------------------------------------------------------------

#ifdef OB_DRAFTS
// CLOSE: 0x00434360 score 17
bool cSC4MySimDispatch::ExitUDriveIt()
{
    if (reinterpret_cast<uint8_t*>(this)[0x4a] & 1) {
        cAutomaton_a857cc* pFound = 0;
        cIGZUnknown* pAuto = static_cast<cIGZUnknown*>(mpAutomaton);
        if (pAuto) {
            if (pAuto->QueryInterface(0xa9b40f05, reinterpret_cast<void**>(&pFound))) {
                pFound->Fn40(static_cast<cSC4MySimDispatch_8*>(this));
                pFound->Fn13(0);
            }
        }
        reinterpret_cast<LocDeque_a857cc*>(reinterpret_cast<char*>(this) + 0x160)->Clear();
        cLocation_a857cc* pDefault = LOC_AT_a857cc(this, 0x84);
        *LOC_AT_a857cc(this, 0x5c) = *pDefault;
        *LOC_AT_a857cc(this, 0xac) = *pDefault;
        if (mnFn50 != 0xff) {
            ++mnChangeCount;
            mnFn50 = 0xff;
        }
        uint32_t prev = mnState;
        mnPrevState = prev;
        mnState = 0xffffffff;
        if (prev != 0xffffffff) {
            Notify(0x4bb2cfc0, prev, 0xffffffff, 0);
            ++mnChangeCount;
        }
        ResetPath();
        cIGZUnknown* pOccupant = static_cast<cIGZUnknown*>(mpAutomaton);
        if (pOccupant) {
            mpAutomaton = 0;
            pOccupant->Release();
        }
        if (pFound) {
            pFound->Release();
        }
    }
    uint32_t old = mnFlags;
    uint32_t now = old & 0xfffcffff;
    mnFlags = now;
    if (old != now) {
        Notify(0x4bb2d020, old, now, 0);
        ++mnChangeCount;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004350d0 score 4
bool cSC4MySimDispatch::SetCurrentCommuteDestination(void* pLocation, bool notify)
{
    cLocation_a857cc target(*static_cast<cLocation_a857cc*>(pLocation));
    if (!target.IsValid()) {
        if (!notify) {
            return false;
        }
        if (mnState != 2) {
            if (!Fn00432f50(&target)) {
                return false;
            }
        }
    }
    *LOC_AT_a857cc(this, 0xd4) = target;
    if (notify) {
        Notify(0xeba06bf4, 0, 0, 0);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00435030 score 62
bool cSC4MySimDispatch::Fn00435030(void* pLocation)
{
    cLocation_a857cc* pNew = static_cast<cLocation_a857cc*>(pLocation);
    if (pNew->IsValid() && pNew->mbSet && !pNew->mbFlag1d) {
        cLocation_a857cc* pHere = LOC_AT_a857cc(this, 0x5c);
        cLocation_a857cc* pDefault = LOC_AT_a857cc(this, 0x84);
        bool result = true;
        if (pHere->Equals(*pDefault) && pHere->mpOccupant) {
            cIGZUnknown* pOld = pHere->mpOccupant;
            pHere->mpOccupant = 0;
            pOld->Release();
        }
        *pDefault = *pNew;
        ++mnChangeCount;
        uint32_t old = mnFlags;
        uint32_t now;
        if (result) {
            now = old | 0x80;
        } else {
            now = old & 0xffffff7f;
        }
        mnFlags = now;
        if (old != now) {
            Notify(0x4bb2d020, old, now, 0);
            ++mnChangeCount;
        }
        return result;
    }
    return false;
}
#endif

// ---- batch 8 -----------------------------------------------------------------------------------------------------------

#ifdef OB_DRAFTS
// CLOSE: 0x00434670 score 62
bool cSC4MySimDispatch::Fn00434670()
{
    if (mpPathFinder) {
        cAtm_a857cc* pAtm = Fn00602600();
        cSC4MySimDispatch_8* pSelf = static_cast<cSC4MySimDispatch_8*>(this);
        if (pAtm) {
            pAtm->Fn06(pSelf, 0xff);
        }
        gpB43ccc->RemoveNotification(pSelf, 0x44778231);
        gpB43ccc->RemoveNotification(pSelf, 0x8bbbd22a);
        gpB43ccc->RemoveNotification(pSelf, 0xa6b79601);
        gpB43ccc->RemoveNotification(pSelf, 0xa6b79611);
        bool bit = ((mnFlags >> 8) & 1) != 0;
        Fn00431f70();
        SetFlag(0x100, bit);
        Fn00434080();
        cIGZUnknown* pClock = static_cast<cIGZUnknown*>(mpClock);
        if (pClock) {
            mpClock = 0;
            pClock->Release();
        }
        cIGZUnknown* pFinder = static_cast<cIGZUnknown*>(mpPathFinder);
        if (pFinder) {
            mpPathFinder = 0;
            pFinder->Release();
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00435780 score 53
bool cSC4MySimDispatch::Fn00435780()
{
    if (mnSeenChangeCount == mnChangeCount) {
        if (mpFc == Fn00431780()) {
            return true;
        }
    }
    bool bit = ((mnFlags >> 8) & 1) != 0;
    if (mpFc || mnTrackHandle != -1) {
        Fn00431f70();
        SetFlag(0x100, bit);
    }
    if (bit) {
        StartTracking(mnTrackedId, reinterpret_cast<char*>(this) + 0x104);
    }
    SetFlag(0x100, bit);
    return true;
}
#endif

// ---- batch 9 -----------------------------------------------------------------------------------------------------------

#ifdef OB_DRAFTS
// CLOSE: 0x00431880 score 23
void* cSC4MySimDispatch::Fn00431880(void* pOutRaw, const void* pLocRaw)
{
    Rect_a857cc* pOut = static_cast<Rect_a857cc*>(pOutRaw);
    const cLocation_a857cc* pLoc = static_cast<const cLocation_a857cc*>(pLocRaw);
    cLotManager_a857cc* pManager = gpB43d08;
    cLot_a857cc* pLot;
    if (pLoc->mpOccupant) {
        pLot = pManager->FindLotOf(pLoc->mpOccupant);
    } else {
        pLot = pManager->FindLotAt(pLoc->mnCellX, pLoc->mnCellZ, 0);
    }
    Rect_a857cc rect;
    if (pLot) {
        pLot->GetRect(&rect);
    } else {
        rect.mnX0 = pLoc->mnCellX;
        rect.mnY0 = pLoc->mnCellZ;
        rect.mnX1 = pLoc->mnCellX;
        rect.mnY1 = pLoc->mnCellZ;
    }
    *pOut = rect;
    return pOut;
}
#endif

// ---- batch 10 -----------------------------------------------------------------------------------------------------------

#ifdef OB_DRAFTS
// CLOSE: 0x004344a0 score 39
TriDeque_a857cc* TriDeque_a857cc::Construct(TriIt_a857cc first, TriIt_a857cc last)
{
    mpStartCur = 0;
    mpStartFirst = 0;
    mpStartLast = 0;
    mpStartNode = 0;
    mpFinishCur = 0;
    mpFinishFirst = 0;
    mpFinishLast = 0;
    mpFinishNode = 0;
    mpMap = 0;
    mnMapSize = 0;
    RangeInit(first, last, 0);
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00432d90 score 104
void TriDeque_a857cc::RangeInit(TriIt_a857cc first, TriIt_a857cc last, uint32_t tag)
{
    int32_t count = (last.mpNode - first.mpNode - 1) * 42 + (last.mpCur - last.mpFirst) + (first.mpLast - first.mpCur);
    InitializeMap(count);
    Tri_a857cc** pNode = mpStartNode;
    if (pNode < mpFinishNode) {
        for (; pNode < mpFinishNode; ++pNode) {
            TriIt_a857cc mid = first;
            mid.Advance(42);
            Fn00431f10(first, mid, *pNode);
            first = mid;
        }
    }
    Fn00431f10(first, last, mpFinishFirst);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00433a60 score 243
void* cSC4MySimDispatch::Fn00433a60(uint32_t)
{
    mnFn50 = 0xff;
    mnChangeCount = 0;
    mnSeenChangeCount = 0;
    mnFlags = 0;
    mnClock = 0;
    mnTransitSwitchStart = 0;
    mnTrackHandle = -1;
    mnState = 0xffffffff;
    mnPrevState = 0xffffffff;
    cLocation_a857cc* pHere = new (LOC_AT_a857cc(this, 0x5c)) cLocation_a857cc;
    (void)pHere;
    new (LOC_AT_a857cc(this, 0x84)) cLocation_a857cc;
    new (LOC_AT_a857cc(this, 0xac)) cLocation_a857cc;
    new (LOC_AT_a857cc(this, 0xd4)) cLocation_a857cc;
    mpFc = 0;
    mpPathFinder = 0;
    mpAutomaton = 0;
    mpClock = 0;
    mpTarget = 0;
    mbInitPending = false;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004311f0 score 29
bool cSC4MySimDispatch::QueryInterface(unsigned int iid, void** ppObject)
{
    *ppObject = 0;
    if (iid == 0x452294aa) {
        *ppObject = static_cast<cSC4MySimDispatch_8*>(this);
    } else if (iid == 0xe4fda3d4) {
        *ppObject = static_cast<cSC4MySimDispatch_c*>(this);
    } else if (iid == 0xeb8b6f9a) {
        *ppObject = this;
        if (!*ppObject) {
            return cUnk0090da1e::QueryInterface(1, ppObject);
        }
    } else {
        return cUnk0090da1e::QueryInterface(1, ppObject);
    }
    AddRef();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00434e30 score 67
bool cSC4MySimDispatch::Fn00434e30(void* pOutRaw, bool keep)
{
    TriDeque_a857cc* pOut = static_cast<TriDeque_a857cc*>(pOutRaw);
    if (!keep) {
        pOut->Clear();
    }
    int32_t added = 0;
    for (int32_t i = mnPathIndex; i < mnPathCount; ++i) {
        TriIt_a857cc it = *reinterpret_cast<TriIt_a857cc*>(PATH_a857cc(this));
        it.Advance(i);
        pOut->PushBack(*it.mpCur);
        ++added;
    }
    return added > 0;
}
#endif
