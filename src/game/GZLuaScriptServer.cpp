#include <cstddef>
#include <algorithm>
#include <cstring>
#include <new>
#include "classes/cGZLuaScriptServer.h"
#include "classes/cGZWinLuaScriptView.h"
#include "classes/cGZWinLuaScriptViewCallStack.h"
#include "classes/cGZWinLuaScriptViewVariables.h"
#include "classes/cGZWinLuaScriptViewBreakpoints.h"
#include "classes/cGZWinLuaScriptConsole.h"
#include "classes/cUnk00ac7b68.h"
#include "common/compiler.h"
#include "gzcom/cIGZString.h"
#include "gzcom/cRZString.h"

// ---- views of the objects the server and its windows hold (tag ac7368) ----
struct ThreadData_ac7368 {
    virtual void V00() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual void V03() = 0;
    virtual void V04() = 0;
    virtual void V05() = 0;
    virtual void V06() = 0;
    virtual void V07() = 0;
    virtual void V08() = 0;
    virtual void V09() = 0;
    virtual uint32_t GetScriptID() = 0;
};
struct ThreadRef_ac7368 {
    ThreadData_ac7368* mpData;
};

// ---- more views ----
struct lua_State;
struct LuaDebug_ac7368 {
    uint8_t unknown0[0x60];
};
// STUB: 0x008b97e0
int lua_getstack(lua_State* L, int level, LuaDebug_ac7368* ar);
struct LuaThread_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual lua_State* GetState() = 0;
};
struct Grid_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual void P14() = 0;
    virtual void P18() = 0;
    virtual void P1c() = 0;
    virtual void P20() = 0;
    virtual void P24() = 0;
    virtual void P28() = 0;
    virtual void P2c() = 0;
    virtual void P30() = 0;
    virtual void P34() = 0;
    virtual void P38() = 0;
    virtual void P3c() = 0;
    virtual void P40() = 0;
    virtual void P44() = 0;
    virtual void P48() = 0;
    virtual void P4c() = 0;
    virtual void P50() = 0;
    virtual void P54() = 0;
    virtual void P58() = 0;
    virtual void P5c() = 0;
    virtual void P60() = 0;
    virtual void P64() = 0;
    virtual void P68() = 0;
    virtual void P6c() = 0;
    virtual void P70() = 0;
    virtual void P74() = 0;
    virtual void P78() = 0;
    virtual void P7c() = 0;
    virtual void P80() = 0;
    virtual void P84() = 0;
    virtual void P88() = 0;
    virtual void P8c() = 0;
    virtual void P90() = 0;
    virtual void P94() = 0;
    virtual void P98() = 0;
    virtual void P9c() = 0;
    virtual void Pa0() = 0;
    virtual void Pa4() = 0;
    virtual void Pa8() = 0;
    virtual void Pac() = 0;
    virtual void Pb0() = 0;
    virtual void Pb4() = 0;
    virtual void Pb8() = 0;
    virtual void Pbc() = 0;
    virtual void Pc0() = 0;
    virtual void Pc4() = 0;
    virtual void SC8(int32_t* rect) = 0;
    virtual void SCC(int32_t* rect) = 0;
    virtual void Pd0() = 0;
    virtual void Pd4() = 0;
    virtual void Pd8() = 0;
    virtual void Pdc() = 0;
    virtual void Pe0() = 0;
    virtual void Pe4() = 0;
    virtual void Pe8() = 0;
    virtual void Pec() = 0;
    virtual void Pf0() = 0;
    virtual void Pf4() = 0;
    virtual void Pf8() = 0;
    virtual void Pfc() = 0;
    virtual void P100() = 0;
    virtual void P104() = 0;
    virtual void P108() = 0;
    virtual void P10c() = 0;
    virtual void P110() = 0;
    virtual void P114() = 0;
    virtual void P118() = 0;
    virtual void P11c() = 0;
    virtual void P120() = 0;
    virtual void P124() = 0;
    virtual void P128() = 0;
    virtual void P12c() = 0;
    virtual void P130() = 0;
    virtual void P134() = 0;
    virtual void P138() = 0;
    virtual void P13c() = 0;
    virtual void P140() = 0;
    virtual void P144() = 0;
    virtual void P148() = 0;
    virtual void P14c() = 0;
    virtual void P150() = 0;
    virtual void P154() = 0;
    virtual void P158() = 0;
    virtual void P15c() = 0;
    virtual void P160() = 0;
    virtual void P164() = 0;
    virtual void P168() = 0;
    virtual void P16c() = 0;
    virtual void P170() = 0;
    virtual void P174() = 0;
    virtual void P178() = 0;
    virtual void P17c() = 0;
    virtual void P180() = 0;
    virtual void P184() = 0;
    virtual void P188() = 0;
    virtual void P18c() = 0;
    virtual void P190() = 0;
    virtual void P194() = 0;
    virtual void P198() = 0;
    virtual void P19c() = 0;
    virtual bool S1a0(uint32_t x, int32_t y) = 0;
    virtual void S1a4(uint32_t x, int32_t y) = 0;
};
struct Msg_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual uint32_t GetType() = 0;
};
struct Entry_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual void P14() = 0;
    virtual void P18() = 0;
    virtual void P1c() = 0;
    virtual void P20() = 0;
    virtual bool S24(uint32_t, uint32_t) = 0;
};
struct Obj2_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual void P14() = 0;
    virtual void P18() = 0;
    virtual void P1c() = 0;
    virtual void P20() = 0;
    virtual void P24() = 0;
    virtual void P28() = 0;
    virtual void P2c() = 0;
    virtual void P30() = 0;
    virtual void P34() = 0;
    virtual void P38() = 0;
    virtual void P3c() = 0;
    virtual void P40() = 0;
    virtual void P44() = 0;
    virtual void P48() = 0;
    virtual void P4c() = 0;
    virtual void P50() = 0;
    virtual void P54() = 0;
    virtual void P58() = 0;
    virtual void P5c() = 0;
    virtual void P60() = 0;
    virtual void P64() = 0;
    virtual void P68() = 0;
    virtual void P6c() = 0;
    virtual void P70() = 0;
    virtual void P74() = 0;
    virtual void P78() = 0;
    virtual void P7c() = 0;
    virtual void P80() = 0;
    virtual void P84() = 0;
    virtual void P88() = 0;
    virtual void P8c() = 0;
    virtual void P90() = 0;
    virtual void P94() = 0;
    virtual void P98() = 0;
    virtual void P9c() = 0;
    virtual void Pa0() = 0;
    virtual void Pa4() = 0;
    virtual void Pa8() = 0;
    virtual void Pac() = 0;
    virtual void Pb0() = 0;
    virtual void Pb4() = 0;
    virtual void Pb8() = 0;
    virtual void Pbc() = 0;
    virtual void Pc0() = 0;
    virtual void Pc4() = 0;
    virtual void Pc8() = 0;
    virtual void Pcc() = 0;
    virtual void Pd0() = 0;
    virtual void Pd4() = 0;
    virtual void Pd8() = 0;
    virtual void Pdc() = 0;
    virtual void Pe0() = 0;
    virtual void Pe4() = 0;
    virtual void Pe8() = 0;
    virtual void Pec() = 0;
    virtual void Pf0() = 0;
    virtual void Pf4() = 0;
    virtual void Pf8() = 0;
    virtual void Pfc() = 0;
    virtual void P100() = 0;
    virtual void P104() = 0;
    virtual void P108() = 0;
    virtual void P10c() = 0;
    virtual void P110() = 0;
    virtual void S114() = 0;
    virtual void S118() = 0;
};
struct WinObj_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual Obj2_ac7368* S14() = 0;
};
struct LocalWin_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void Release() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual Obj2_ac7368* S14() = 0;
};
struct TextWin_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void Release() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual void P14() = 0;
    virtual void P18() = 0;
    virtual void P1c() = 0;
    virtual void P20() = 0;
    virtual void P24() = 0;
    virtual void S28(uint32_t) = 0;
    virtual void P2c() = 0;
    virtual void S30(uint32_t) = 0;
    virtual void P34() = 0;
    virtual void P38() = 0;
    virtual void P3c() = 0;
    virtual void P40() = 0;
    virtual void S44(uint32_t, uint32_t) = 0;
    virtual void P48() = 0;
    virtual void P4c() = 0;
    virtual void P50() = 0;
    virtual void P54() = 0;
    virtual void P58() = 0;
    virtual void P5c() = 0;
    virtual void P60() = 0;
    virtual void P64() = 0;
    virtual void P68() = 0;
    virtual void P6c() = 0;
    virtual void P70() = 0;
    virtual void P74() = 0;
    virtual void S78(uint32_t, uint32_t, uint32_t) = 0;
};
struct ListNode_ac7368 {
    ListNode_ac7368* mpNext;
    ListNode_ac7368* mpPrev;
    uint8_t mEntry[0x3c];
    WinObj_ac7368* mpWin;
};
struct IUnk_ac7368 {
    virtual void P00() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};
struct ListWin_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual void S10(const void*, uint32_t) = 0;
    virtual void P14() = 0;
    virtual void P18() = 0;
    virtual void S1c() = 0;
    virtual void P20() = 0;
    virtual void S24(int32_t*) = 0;
};
struct Poster_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual void S10(void*, uint32_t) = 0;
};
struct PostMsg_ac7368 {
    virtual void P00() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual void S14(uint32_t) = 0;
    virtual void P18() = 0;
    virtual void P1c() = 0;
    virtual void P20() = 0;
    virtual void P24() = 0;
    virtual void P28() = 0;
    virtual void S2c(uint32_t) = 0;
    virtual void P30() = 0;
    virtual void P34() = 0;
    virtual void P38() = 0;
    virtual void P3c() = 0;
    virtual void S40(uint32_t) = 0;
    // STUB: 0x009134d6
    PostMsg_ac7368* Construct();
};
struct ServiceMgr_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual bool Query(uint32_t id1, uint32_t id2, void* out) = 0;
};
struct Svc2_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void* S0c() = 0;
    virtual void P10() = 0;
    virtual void P14() = 0;
    virtual void P18() = 0;
    virtual void P1c() = 0;
    virtual void P20() = 0;
    virtual void P24() = 0;
    virtual void P28() = 0;
    virtual void P2c() = 0;
    virtual void P30() = 0;
    virtual void P34() = 0;
    virtual void P38() = 0;
    virtual void P3c() = 0;
    virtual void P40() = 0;
    virtual void P44() = 0;
    virtual void P48() = 0;
    virtual void P4c() = 0;
    virtual void P50() = 0;
    virtual void P54() = 0;
    virtual void P58() = 0;
    virtual void S5c(void* view) = 0;
};
struct WinEnum_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual void P14() = 0;
    virtual void P18() = 0;
    virtual void P1c() = 0;
    virtual void P20() = 0;
    virtual void P24() = 0;
    virtual void P28() = 0;
    virtual void P2c() = 0;
    virtual void P30() = 0;
    virtual void P34() = 0;
    virtual void P38() = 0;
    virtual void P3c() = 0;
    virtual void P40() = 0;
    virtual void P44() = 0;
    virtual void P48() = 0;
    virtual void P4c() = 0;
    virtual void P50() = 0;
    virtual void P54() = 0;
    virtual void P58() = 0;
    virtual void P5c() = 0;
    virtual void P60() = 0;
    virtual void P64() = 0;
    virtual void P68() = 0;
    virtual void P6c() = 0;
    virtual void P70() = 0;
    virtual void P74() = 0;
    virtual void P78() = 0;
    virtual void P7c() = 0;
    virtual void S80(uint32_t iid, void* callback, void* user) = 0;
};
struct Ref3_ac7368 {
    Svc2_ac7368* mp;
    Ref3_ac7368() : mp(0) {}
    ~Ref3_ac7368() { Done(); }
    // STUB: 0x004177f0
    void Done();
};
struct Ref_ac7368 {
    Poster_ac7368* mp;
    Ref_ac7368() : mp(0) {}
    ~Ref_ac7368() { Done(); }
    // STUB: 0x004495c0
    void Done();
};

// STUB: 0x008793ec
ServiceMgr_ac7368* Fn008793ec();

// STUB: 0x009133da
void* Fn009133da(uint32_t size);
struct BreakRec_ac7368 {
    uint32_t mnScriptID;
    cRZString mName;
    int32_t mnLine;
    bool mbEnabled;
    cRZString mCondition;
    BreakRec_ac7368();
    BreakRec_ac7368(const BreakRec_ac7368& other);
};
struct Alloc_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void* S0c(uint32_t size) = 0;
    virtual void S10(void* p) = 0;
};
struct Ref2_ac7368 {
    Alloc_ac7368* mp;
    Ref2_ac7368() : mp(0) {}
    ~Ref2_ac7368() { Done(); }
    // STUB: 0x00411870
    void Done();
};
// STUB: 0x008793ec is declared above
// GLOBAL: 0x00b5c42c
extern Alloc_ac7368* gpB5c42c;
// GLOBAL: 0x00b5c430
extern Alloc_ac7368* gpB5c430;

struct IRef_ac7368 {
    virtual void P00() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};
struct Variant_ac7368 {
    uint8_t mBytes[0x14];
    // STUB: 0x00916712
    Variant_ac7368(const Variant_ac7368& other);
    // STUB: 0x00915eb5
    ~Variant_ac7368();
};
struct VarRec_ac7368 {
    int32_t mnA;
    int32_t mnB;
    cRZString mS;
    Variant_ac7368 mV;
    VarRec_ac7368(const VarRec_ac7368& other);
};
struct VarNode_ac7368 {
    VarNode_ac7368* mpNext;
    VarNode_ac7368* mpPrev;
    VarRec_ac7368 mRec;
};
struct VarList_ac7368 {
    VarNode_ac7368* mpHead;
    void Clear();
};
struct Rec590_ac7368 {
    cRZString mA;
    int32_t mn14;
    cRZString mB;
    int32_t mn2c;
    Rec590_ac7368();
    Rec590_ac7368(const Rec590_ac7368& other);
};
struct Rec590Node_ac7368 {
    Rec590Node_ac7368* mpNext;
    Rec590Node_ac7368* mpPrev;
    Rec590_ac7368 mRec;
};
struct List590_ac7368 {
    Rec590Node_ac7368* mpHead;
    void Clear();
};
struct Rec600_ac7368 {
    cRZString mA;
    cRZString mB;
    cRZString mC;
    IRef_ac7368* mpRef;
    int32_t mn40;
    Rec600_ac7368();
    Rec600_ac7368(const Rec600_ac7368& other);
    ~Rec600_ac7368() {
        if (mpRef) {
            mpRef->Release();
        }
    }
    void Fn008b0cd0();
};
struct Rec600Node_ac7368 {
    Rec600Node_ac7368* mpNext;
    Rec600Node_ac7368* mpPrev;
    Rec600_ac7368 mRec;
};
struct List600_ac7368 {
    Rec600Node_ac7368* mpHead;
    void Clear();
};
struct BreakNode_ac7368 {
    BreakNode_ac7368* mpNext;
    BreakNode_ac7368* mpPrev;
    BreakRec_ac7368 mRec;
};
struct ListBreak_ac7368 {
    BreakNode_ac7368* mpHead;
    void Clear();
    void Fn008b1d00();
    ListBreak_ac7368* Fn008b02b0(void* unused);
    BreakNode_ac7368* Fn008b1f30(const BreakRec_ac7368& rec);
    void Fn008b1540(BreakNode_ac7368** out, BreakNode_ac7368* node);
};
struct LuaRef_ac7368 {
    ThreadData_ac7368* mp;
    LuaRef_ac7368() : mp(0) {}
    ~LuaRef_ac7368() {
        if (mp) {
            mp->Release();
        }
    }
};
struct ThreadInfo_ac7368 {
    LuaRef_ac7368 mpLuaRef;
    cRZString mName;
    cRZString mFile;
    cRZString m2c;
    int32_t mn40;
    int32_t mn44;
    bool mb48;
    bool mbAutoYield;
    int32_t mn4c;
    ListBreak_ac7368 mBreakList;
    ThreadInfo_ac7368();
    ~ThreadInfo_ac7368();
};
struct AllocUtil_ac7368 {
    void Fn008b0160(void* p, uint32_t n);
};
#define GET_ALLOC_AC7368(g)                                  \
    if (!g) {                                                \
        Ref2_ac7368 r;                                       \
        ServiceMgr_ac7368* svc = Fn008793ec();               \
        if (svc) {                                           \
            svc->Query(0x3ae4bea3, 0x3ae4beab, &r);          \
        }                                                    \
        g = r.mp;                                            \
    }

struct ThreadInfo_ac7368;
struct MapNode_ac7368 {
    uint8_t unknown0[0x10];
    int32_t mnKey;
    ThreadInfo_ac7368* mpValue;
};
struct ThreadMap_ac7368 {
    MapNode_ac7368* mpEnd;
    uint32_t mnCount;
    // STUB: 0x006c0030
    void Find(MapNode_ac7368** out, const int32_t* key);
};
struct TreeNode_ac7368 {
    uint32_t unknown0;
    TreeNode_ac7368* mpParent;
    TreeNode_ac7368* mpLeft;
    TreeNode_ac7368* mpRight;
};
struct TreeIter_ac7368 {
    TreeNode_ac7368* mpNode;
    void Fn008afcf0(TreeIter_ac7368* ret, int32_t unused);
};
struct RbHeader_ac7368 {
    uint32_t unknown0;
    TreeNode_ac7368* mpRoot;
    TreeNode_ac7368* mpLeftmost;
    TreeNode_ac7368* mpRightmost;
};
struct Svc3_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual void P14() = 0;
    virtual void P18() = 0;
    virtual void P1c() = 0;
    virtual void P20() = 0;
    virtual void P24() = 0;
    virtual void S28(void* p) = 0;
};
struct Ref38Obj_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void Release() = 0;
    virtual Ref38Obj_ac7368* S0c() = 0;
    virtual void S10() = 0;
};
struct Mgr14_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void Release() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual void S14() = 0;
};
struct Tree_ac7368 {
    uint32_t unknown0[3];
    void Erase(TreeNode_ac7368* node);
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// STUB: 0x0040daf0
void* Fn0040daf0(void* node, void* root, void* leftmost, void* rightmost);

struct Manager_ac7368 {
    virtual void P00() = 0;
    virtual void P04() = 0;
    virtual void P08() = 0;
    virtual void P0c() = 0;
    virtual void P10() = 0;
    virtual void P14() = 0;
    virtual void P18() = 0;
    virtual void S1c(uint32_t scriptID) = 0;
};

// STUB: 0x008af6c0
void Fn008af6c0(int32_t id, bool show);


// FUNCTION: 0x008afc40
void cGZWinLuaScriptViewCallStack::DoRequestClose()
{
    static_cast<cGZWinLuaScriptView*>(mpScriptView)->ViewCallStack(false);
}

// FUNCTION: 0x008afc70
void cGZWinLuaScriptViewVariables::DoRequestClose()
{
    static_cast<cGZWinLuaScriptView*>(mpScriptView)->ViewVariables(false);
}

// FUNCTION: 0x008afce0
void cGZWinLuaScriptViewBreakpoints::DoRequestClose()
{
    static_cast<cGZWinLuaScriptView*>(mpScriptView)->ViewBreakpoints(false);
}

// FUNCTION: 0x008ae810
unsigned int cGZLuaScriptServer::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    FinalRelease();
    return 0;
}

// FUNCTION: 0x008ae830
void cGZLuaScriptServer::FinalRelease()
{
    Slot04_ae1d24();
    delete this;
}

// FUNCTION: 0x008af910
bool cGZWinLuaScriptView::Fn008af910()
{
    return static_cast<cUnk00ac7368*>(mpServer)->Slot08_ac7368(mnScriptID);
}

// FUNCTION: 0x008ae980
void cGZWinLuaScriptView::FinalRelease()
{
    Slot04_ae1d24();
    delete this;
}

// FUNCTION: 0x008aecf0
uint32_t cGZLuaScriptServer::Slot21_ac7368()
{
    ThreadRef_ac7368* ref = reinterpret_cast<ThreadRef_ac7368*>(mpCurrentThread);
    if (ref && ref->mpData) {
        return ref->mpData->GetScriptID();
    }
    return 0xffffffff;
}

// FUNCTION: 0x008aead0
void cGZWinLuaScriptViewVariables::SetCurrentCallLevel(int32_t level, bool refresh)
{
    mnCallLevel = level;
    if (refresh) {
        RefreshView();
    }
}

// FUNCTION: 0x008ae7d0
bool cGZLuaScriptServer::QueryInterface(unsigned int iid, void** out)
{
    switch (iid) {
    case 1:
    case 0x4bd10129:
        *out = this;
        AddRef();
        return true;
    }
    return cRZSystemService::QueryInterface(iid, out);
}

// FUNCTION: 0x008ae930
bool cGZWinLuaScriptConsole::QueryInterface(unsigned int iid, void** out)
{
    if (iid == 0xeba2be1a) {
        *out = this;
        AddRef();
        return true;
    }
    return cGZWinGen::QueryInterface(iid, out);
}

// FUNCTION: 0x008aea30
bool cGZWinLuaScriptViewBreakpoints::QueryInterface(unsigned int iid, void** out)
{
    if (iid == 0x4bd93e62) {
        *out = this;
        AddRef();
        return true;
    }
    return cGZWinGen::QueryInterface(iid, out);
}

// FUNCTION: 0x008ae9b0
bool cGZWinLuaScriptView::QueryInterface(unsigned int iid, void** out)
{
    if (iid == 0x452294aa) {
        *out = static_cast<cUnk00aaaa9c*>(this);
        AddRef();
        return true;
    }
    if (iid == 0x6ba6cd0c) {
        *out = this;
        AddRef();
        return true;
    }
    return cGZWinGen::QueryInterface(iid, out);
}

// FUNCTION: 0x008aea60
bool cUnk00ac7b68::DoMessage(uint32_t msg)
{
    const uint32_t* m = OB_PTR(const uint32_t, msg);
    switch (m[0]) {
    case 3:
        if (m[1] == 0x287259f6 && m[2] == 0x42b7c353) {
            DoRequestClose();
        }
        return true;
    case 0x8ba2bc62:
        PostInit();
        return true;
    }
    return cGZWinGen::DoMessage(msg);
}

// FUNCTION: 0x008afc50
bool cGZWinLuaScriptViewVariables::DoMessage(uint32_t msg)
{
    if (*OB_PTR(const uint32_t, msg) != 0x9a1552d4) {
        return reinterpret_cast<cUnk00ac7b68*>(this)->cUnk00ac7b68::DoMessage(msg);
    }
    return true;
}

// FUNCTION: 0x008b4580
bool cGZWinLuaScriptConsole::Slot03_aaaa9c(void* msg)
{
    uint32_t type = static_cast<Msg_ac7368*>(msg)->GetType();
    if (type == 0x6ba990d8 || type == 0xcba990d3 || type == 0xebaaf9be) {
        RefreshView();
    }
    return true;
}

// FUNCTION: 0x008aea10
bool Fn008aea10(uint32_t /*a*/, uint32_t /*b*/, cGZWinLuaScriptView* view, int32_t* query)
{
    if (view && view->mnScriptID == query[0]) {
        reinterpret_cast<cGZWinLuaScriptView**>(query)[1] = view;
        return true;
    }
    return false;
}

// FUNCTION: 0x008b04a0
bool cGZLuaScriptServer::Slot22_ac7368(uint32_t id)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        return it->mpValue->mbAutoYield;
    }
    return false;
}

// FUNCTION: 0x008b04e0
bool cGZLuaScriptServer::Slot23_ac7368(uint32_t id, uint32_t enable)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        it->mpValue->mbAutoYield = *reinterpret_cast<bool*>(&enable);
        return true;
    }
    return false;
}

// FUNCTION: 0x008b10f0
void cGZWinLuaScriptConsole::Fn008b10f0()
{
    uint32_t id = Fn008b09e0();
    if (id != 0xffffffff) {
        Fn008af6c0(id, true);
    }
}

// FUNCTION: 0x008b3750
void cGZWinLuaScriptConsole::Fn008b3750()
{
    uint32_t id = Fn008b09e0();
    if (id != 0xffffffff) {
        static_cast<cUnk00ac7368*>(mpServer)->Slot08_ac7368(id);
        RefreshView();
    }
}

// FUNCTION: 0x008afd40
void Tree_ac7368::Erase(TreeNode_ac7368* node)
{
    while (node) {
        Erase(node->mpRight);
        TreeNode_ac7368* left = node->mpLeft;
        Fn0090cf63(node);
        node = left;
    }
}

// FUNCTION: 0x008aff20
int32_t cGZWinLuaScriptView::Fn008aff20(uint32_t arg)
{
    ListNode_ac7368* head = reinterpret_cast<ListNode_ac7368*>(mpList);
    int32_t index = 0;
    for (ListNode_ac7368* n = head->mpNext; n != head; n = n->mpNext) {
        if (reinterpret_cast<Entry_ac7368*>(n->mEntry)->S24(arg, 0)) {
            return index;
        }
        ++index;
    }
    return -1;
}

// FUNCTION: 0x008afe40
void* cGZWinLuaScriptView::Fn008afe40(uint32_t arg)
{
    for (ListNode_ac7368* n = reinterpret_cast<ListNode_ac7368*>(mpList)->mpNext; n != reinterpret_cast<ListNode_ac7368*>(mpList); n = n->mpNext) {
        Entry_ac7368* e = reinterpret_cast<Entry_ac7368*>(n->mEntry);
        if (e->S24(arg, 0)) {
            return e;
        }
    }
    return 0;
}

// FUNCTION: 0x008aebc0
void cGZLuaScriptServer::PostScriptChangeMessage(int32_t id, uint32_t type, int32_t data)
{
    Ref_ac7368 poster;
    ServiceMgr_ac7368* svc = Fn008793ec();
    if (svc) {
        svc->Query(0x4fa845b, 0x652294c7, &poster);
    }
    if (poster.mp) {
        void* mem = Fn009133da(0x2c);
        PostMsg_ac7368* msg = mem ? static_cast<PostMsg_ac7368*>(mem)->Construct() : 0;
        if (msg) {
            msg->AddRef();
        }
        msg->S14(type);
        msg->S2c(id);
        msg->S40(data);
        poster.mp->S10(msg, 0);
        msg->Release();
    }
}

// FUNCTION: 0x008aec60
void cGZLuaScriptServer::PostBreakpointChangedMessage(uint32_t id)
{
    Ref_ac7368 poster;
    ServiceMgr_ac7368* svc = Fn008793ec();
    if (svc) {
        svc->Query(0x4fa845b, 0x652294c7, &poster);
    }
    if (poster.mp) {
        void* mem = Fn009133da(0x2c);
        PostMsg_ac7368* msg = mem ? static_cast<PostMsg_ac7368*>(mem)->Construct() : 0;
        if (msg) {
            msg->AddRef();
        }
        msg->S14(0x8bd13ee2);
        msg->S2c(id);
        poster.mp->S10(msg, 0);
        msg->Release();
    }
}

// FUNCTION: 0x008afe90
void* cGZWinLuaScriptView::Fn008afe90()
{
    int32_t index;
    static_cast<ListWin_ac7368*>(mpListWin)->S24(&index);
    ListNode_ac7368* head = reinterpret_cast<ListNode_ac7368*>(mpList);
    int32_t i = 0;
    for (ListNode_ac7368* n = head->mpNext; n != head; n = n->mpNext) {
        if (i == index) {
            return n->mEntry;
        }
        ++i;
    }
    return 0;
}

// FUNCTION: 0x008afed0
void cGZWinLuaScriptView::Fn008afed0()
{
    static_cast<ListWin_ac7368*>(mpListWin)->S1c();
    int32_t i = 0;
    for (ListNode_ac7368* n = reinterpret_cast<ListNode_ac7368*>(mpList)->mpNext; n != reinterpret_cast<ListNode_ac7368*>(mpList); n = n->mpNext) {
        static_cast<ListWin_ac7368*>(mpListWin)->S10(n->mEntry + 0x14, i);
        ++i;
    }
}

// FUNCTION: 0x008aff60
void cGZWinLuaScriptView::Fn008aff60()
{
    for (ListNode_ac7368* n = reinterpret_cast<ListNode_ac7368*>(mpList)->mpNext; n != reinterpret_cast<ListNode_ac7368*>(mpList); n = n->mpNext) {
        n->mpWin->S14()->S118();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b0260 score 18
bool cGZWinLuaScriptView::Fn008b0260(uint32_t index)
{
    bool found = false;
    Fn008aff60();
    ListNode_ac7368* head = reinterpret_cast<ListNode_ac7368*>(mpList);
    int32_t i = 0;
    for (ListNode_ac7368* n = head->mpNext; n != head; n = n->mpNext) {
        if (static_cast<uint32_t>(i) == index) {
            n->mpWin->S14()->S114();
            return true;
        }
        ++i;
    }
    return found;
}
#endif

// FUNCTION: 0x008afb70
bool cGZWinLuaScriptViewBreakpoints::Slot04_ae1d24()
{
    if (get_init_flag()) {
        if (mpRef128) {
            IUnk_ac7368* p = static_cast<IUnk_ac7368*>(mpRef128);
            mpRef128 = 0;
            p->Release();
        }
        if (mpScriptView) {
            IUnk_ac7368* p = static_cast<IUnk_ac7368*>(mpScriptView);
            mpScriptView = 0;
            p->Release();
        }
        if (mpRef130) {
            IUnk_ac7368* p = static_cast<IUnk_ac7368*>(mpRef130);
            mpRef130 = 0;
            p->Release();
        }
        if (mpRef134) {
            IUnk_ac7368* p = static_cast<IUnk_ac7368*>(mpRef134);
            mpRef134 = 0;
            p->Release();
        }
    }
    return cGZWinGen::Slot04_ae1d24();
}

// FUNCTION: 0x008afbe0
void cGZWinLuaScriptViewBreakpoints::Setup(void* a, void* b)
{
    IUnk_ac7368* newA = static_cast<IUnk_ac7368*>(a);
    IUnk_ac7368* oldA = static_cast<IUnk_ac7368*>(mpScriptView);
    if (newA != oldA) {
        if (newA) {
            newA->AddRef();
        }
        mpScriptView = newA;
        if (oldA) {
            oldA->Release();
        }
    }
    IUnk_ac7368* oldB = static_cast<IUnk_ac7368*>(mpRef130);
    IUnk_ac7368* newB = static_cast<IUnk_ac7368*>(b);
    if (newB != oldB) {
        if (newB) {
            newB->AddRef();
        }
        mpRef130 = newB;
        if (oldB) {
            oldB->Release();
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b4e60 score 22
bool cGZLuaScriptServer::Slot11_ac7368(uint32_t id, void* name, int32_t line)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        ThreadInfo_ac7368* t = it->mpValue;
        if (t) {
            return Fn008b42c0(t, name, line, false, reinterpret_cast<bool*>(&id)) != 0;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b4ec0 score 36
bool cGZLuaScriptServer::Slot12_ac7368(uint32_t id, void* name, int32_t line, bool remove)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    bool changed;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        ThreadInfo_ac7368* t = it->mpValue;
        if (t) {
            changed = false;
            if (remove) {
                Fn008b1b80(t, name, line, &changed);
            } else {
                static_cast<BreakRec_ac7368*>(Fn008b42c0(t, name, line, true, &changed))->mbEnabled = true;
            }
            if (changed) {
                PostBreakpointChangedMessage(id);
            }
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b4f60 score 62
bool cGZLuaScriptServer::Slot13_ac7368(uint32_t id, void* name, int32_t line)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    bool changed;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        ThreadInfo_ac7368* t = it->mpValue;
        if (t) {
            changed = false;
            Fn008b1b80(t, name, line, &changed);
            if (!changed) {
                Fn008b42c0(t, name, line, true, &changed);
            }
            if (changed) {
                PostBreakpointChangedMessage(id);
            }
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b5000 score 33
bool cGZLuaScriptServer::Slot14_ac7368(uint32_t id, void* name, int32_t line)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        ThreadInfo_ac7368* t = it->mpValue;
        if (t) {
            BreakRec_ac7368* rec = static_cast<BreakRec_ac7368*>(Fn008b42c0(t, name, line, false, reinterpret_cast<bool*>(&id)));
            if (rec && rec->mbEnabled) {
                return true;
            }
            return false;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b5070 score 56
bool cGZLuaScriptServer::Slot15_ac7368(uint32_t id, void* name, int32_t line, bool enable)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    bool changed;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        ThreadInfo_ac7368* t = it->mpValue;
        if (t) {
            changed = false;
            BreakRec_ac7368* rec = static_cast<BreakRec_ac7368*>(Fn008b42c0(t, name, line, true, &changed));
            if (rec && rec->mbEnabled != enable) {
                rec->mbEnabled = enable;
                PostBreakpointChangedMessage(id);
                return true;
            }
            if (changed) {
                PostBreakpointChangedMessage(id);
            }
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b5110 score 53
bool cGZLuaScriptServer::Slot16_ac7368(uint32_t id, void* name, int32_t line, void* out)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    ThreadInfo_ac7368* t = (it != map->mpEnd) ? it->mpValue : 0;
    cIGZString* str = static_cast<cIGZString*>(out);
    str->Resize(0);
    if (t) {
        BreakRec_ac7368* rec = static_cast<BreakRec_ac7368*>(Fn008b42c0(t, name, line, false, reinterpret_cast<bool*>(&id)));
        if (rec) {
            const std::string& cond = rec->mCondition;
            str->FromChar(cond.c_str(), static_cast<uint32_t>(cond.size()));
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b51a0 score 44
bool cGZLuaScriptServer::Slot17_ac7368(uint32_t id, void* name, int32_t line, void* cond)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    bool changed;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        ThreadInfo_ac7368* t = it->mpValue;
        if (t) {
            changed = false;
            BreakRec_ac7368* rec = static_cast<BreakRec_ac7368*>(Fn008b42c0(t, name, line, true, &changed));
            if (rec) {
                cIGZString* s = &rec->mCondition;
                if (s->IsEqual(static_cast<cIGZString*>(cond), true)) {
                    *s = *static_cast<cIGZString*>(cond);
                    PostBreakpointChangedMessage(id);
                    return true;
                }
            }
            if (changed) {
                PostBreakpointChangedMessage(id);
            }
            return true;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x008b0520
BreakRec_ac7368::BreakRec_ac7368()
    : mnScriptID(0xffffffff), mName(), mnLine(-1), mbEnabled(true), mCondition()
{
}

// FUNCTION: 0x008b0590
Rec590_ac7368::Rec590_ac7368()
    : mA(), mn14(-1), mB(), mn2c(-1)
{
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b0600 score 2
Rec600_ac7368::Rec600_ac7368()
    : mA(), mB(), mC(), mpRef(0), mn40(-1)
{
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b0cd0 score 31
void Rec600_ac7368::Fn008b0cd0()
{
    this->~Rec600_ac7368();
}
#endif

// FUNCTION: 0x008b1710
void List590_ac7368::Clear()
{
    Rec590Node_ac7368* n = mpHead->mpNext;
    while (n != mpHead) {
        Rec590Node_ac7368* cur = n;
        n = n->mpNext;
        cur->mRec.~Rec590_ac7368();
        Fn0090cf63(cur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

// FUNCTION: 0x008b1690
void List600_ac7368::Clear()
{
    Rec600Node_ac7368* n = mpHead->mpNext;
    while (n != mpHead) {
        Rec600Node_ac7368* cur = n;
        n = n->mpNext;
        cur->mRec.~Rec600_ac7368();
        Fn0090cf63(cur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

// FUNCTION: 0x008b15e0
void ListBreak_ac7368::Clear()
{
    BreakNode_ac7368* n = mpHead->mpNext;
    while (n != mpHead) {
        BreakNode_ac7368* cur = n;
        n = n->mpNext;
        cur->mRec.~BreakRec_ac7368();
        GET_ALLOC_AC7368(gpB5c42c)
        gpB5c42c->S10(cur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

// FUNCTION: 0x008b1d00
void ListBreak_ac7368::Fn008b1d00()
{
    Clear();
    BreakNode_ac7368* head = mpHead;
    GET_ALLOC_AC7368(gpB5c42c)
    gpB5c42c->S10(head);
}

// FUNCTION: 0x008b0160
void AllocUtil_ac7368::Fn008b0160(void* p, uint32_t /*n*/)
{
    GET_ALLOC_AC7368(gpB5c430)
    gpB5c430->S10(p);
}

// FUNCTION: 0x008b17c0
BreakRec_ac7368::BreakRec_ac7368(const BreakRec_ac7368& other)
    : mnScriptID(other.mnScriptID), mName(other.mName), mnLine(other.mnLine), mbEnabled(other.mbEnabled), mCondition(other.mCondition)
{
}

// FUNCTION: 0x008b02b0
ListBreak_ac7368* ListBreak_ac7368::Fn008b02b0(void* /*unused*/)
{
    mpHead = 0;
    GET_ALLOC_AC7368(gpB5c42c)
    BreakNode_ac7368* head = static_cast<BreakNode_ac7368*>(gpB5c42c->S0c(0x3c));
    head->mpNext = head;
    head->mpPrev = head;
    mpHead = head;
    return this;
}

// FUNCTION: 0x008b1f30
BreakNode_ac7368* ListBreak_ac7368::Fn008b1f30(const BreakRec_ac7368& rec)
{
    GET_ALLOC_AC7368(gpB5c42c)
    BreakNode_ac7368* node = static_cast<BreakNode_ac7368*>(gpB5c42c->S0c(0x3c));
    ::new (static_cast<void*>(&node->mRec)) BreakRec_ac7368(rec);
    return node;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b1540 score 4
void ListBreak_ac7368::Fn008b1540(BreakNode_ac7368** out, BreakNode_ac7368* node)
{
    BreakNode_ac7368* prev = node->mpPrev;
    BreakNode_ac7368* next = node->mpNext;
    prev->mpNext = next;
    next->mpPrev = prev;
    node->mRec.~BreakRec_ac7368();
    GET_ALLOC_AC7368(gpB5c42c)
    gpB5c42c->S10(node);
    *out = next;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b1b80 score 6
bool cGZLuaScriptServer::Fn008b1b80(void* thread, void* name, int32_t line, void* changed)
{
    *static_cast<bool*>(changed) = false;
    ThreadInfo_ac7368* t = static_cast<ThreadInfo_ac7368*>(thread);
    if (t) {
        ListBreak_ac7368* list = &t->mBreakList;
        for (BreakNode_ac7368* n = list->mpHead->mpNext; n != list->mpHead; n = n->mpNext) {
            if (static_cast<cIGZString*>(&n->mRec.mName)->IsEqual(static_cast<cIGZString*>(name), false) && n->mRec.mnLine == line) {
                list->Fn008b1540(reinterpret_cast<BreakNode_ac7368**>(&thread), n);
                *static_cast<bool*>(changed) = true;
                return true;
            }
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b42c0 score 73
void* cGZLuaScriptServer::Fn008b42c0(void* thread, void* name, int32_t line, bool create, void* changed)
{
    ThreadInfo_ac7368* t = static_cast<ThreadInfo_ac7368*>(thread);
    *static_cast<bool*>(changed) = false;
    if (t) {
        ListBreak_ac7368* list = &t->mBreakList;
        for (BreakNode_ac7368* n = list->mpHead->mpNext; n != list->mpHead; n = n->mpNext) {
            if (static_cast<cIGZString*>(&n->mRec.mName)->IsEqual(static_cast<cIGZString*>(name), false) && n->mRec.mnLine == line) {
                return &n->mRec;
            }
        }
        if (create) {
            BreakRec_ac7368 rec;
            if (t->mpLuaRef.mp) {
                rec.mnScriptID = t->mpLuaRef.mp->GetScriptID();
            } else {
                rec.mnScriptID = 0xffffffff;
            }
            static_cast<cIGZString*>(&rec.mName)->operator=(*static_cast<cIGZString*>(name));
            rec.mnLine = line;
            BreakNode_ac7368* head = list->mpHead;
            BreakNode_ac7368* node = list->Fn008b1f30(rec);
            node->mpNext = head;
            node->mpPrev = head->mpPrev;
            head->mpPrev->mpNext = node;
            head->mpPrev = node;
            *static_cast<bool*>(changed) = true;
            return &list->mpHead->mpPrev->mRec;
        }
    }
    return 0;
}
#endif

// FUNCTION: 0x008af640
cGZWinLuaScriptView* Fn008af640(int32_t scriptID)
{
    struct Query_ac7368 {
        int32_t mnID;
        cGZWinLuaScriptView* mpResult;
    } query;
    query.mnID = scriptID;
    query.mpResult = 0;
    Ref3_ac7368 ref;
    ServiceMgr_ac7368* svc = Fn008793ec();
    if (svc) {
        svc->Query(0xa417445e, 0x5a4, &ref);
    }
    if (ref.mp) {
        WinEnum_ac7368* en = static_cast<WinEnum_ac7368*>(ref.mp->S0c());
        if (en) {
            en->S80(0x6ba6cd0c, reinterpret_cast<void*>(Fn008aea10), &query);
        }
    }
    return query.mpResult;
}

// FUNCTION: 0x008af930
void cGZWinLuaScriptView::Fn008af930()
{
    Ref3_ac7368 ref;
    ServiceMgr_ac7368* svc = Fn008793ec();
    if (svc) {
        svc->Query(0xa417445e, 0x5a4, &ref);
    }
    if (ref.mp) {
        ref.mp->S5c(this);
    }
}

// FUNCTION: 0x008af840
void cGZWinLuaScriptView::Fn008af840()
{
    if (static_cast<cUnk00ac7368*>(mpServer)->Slot20_ac7368(mnScriptID, 0, 0, 0, &mnPauseCount, 0, 0) && mnPauseCount > 0) {
        do {
            mnPauseCount = static_cast<cUnk00ac7368*>(mpServer)->Slot10_ac7368(mnScriptID);
        } while (mnPauseCount > 0);
    }
    mbRefresh = true;
}

// FUNCTION: 0x008af8a0
void cGZWinLuaScriptView::Fn008af8a0()
{
    int32_t count = 0;
    if (static_cast<cUnk00ac7368*>(mpServer)->Slot20_ac7368(mnScriptID, 0, 0, 0, &count, 0, 0)) {
        if (count == 0) {
            static_cast<cUnk00ac7368*>(mpServer)->Slot09_ac7368(mnScriptID);
            return;
        }
        while (count > 0) {
            count = static_cast<cUnk00ac7368*>(mpServer)->Slot10_ac7368(mnScriptID);
        }
    }
}

// FUNCTION: 0x008b1110
void cGZWinLuaScriptConsole::Fn008b1110()
{
    uint32_t id = Fn008b09e0();
    if (id != 0xffffffff) {
        int32_t count = 0;
        if (static_cast<cUnk00ac7368*>(mpServer)->Slot20_ac7368(id, 0, 0, 0, &count, 0, 0)) {
            if (count == 0) {
                static_cast<cUnk00ac7368*>(mpServer)->Slot09_ac7368(id);
                return;
            }
            while (count > 0) {
                count = static_cast<cUnk00ac7368*>(mpServer)->Slot10_ac7368(id);
            }
        }
    }
}

// FUNCTION: 0x008b5960
bool cGZWinLuaScriptViewCallStack::DoMessage(uint32_t msg)
{
    const uint32_t* m = OB_PTR(const uint32_t, msg);
    if (m[0] != 0x9a1552d4) {
        return reinterpret_cast<cUnk00ac7b68*>(this)->cUnk00ac7b68::DoMessage(msg);
    }
    if (m[1] == OB_ADDR(mpRef134)) {
        const uint32_t* d = reinterpret_cast<const uint32_t*>(m[2]);
        if (d[0] == 5) {
            static_cast<cGZWinLuaScriptView*>(mpScriptView)->SetViewByCallLevel(d[2]);
            RefreshView();
        }
    }
    return true;
}

// FUNCTION: 0x008afc80
bool cGZWinLuaScriptViewBreakpoints::DoMessage(uint32_t msg)
{
    const uint32_t* m = OB_PTR(const uint32_t, msg);
    uint32_t type = m[0];
    if (type >= 0x9a1552d3 && type <= 0x9a1552d4) {
        return true;
    }
    switch (type) {
    case 3:
        if (m[1] == 0x287259f6 && m[2] == 0x42b7c353) {
            DoRequestClose();
        }
        return true;
    case 0x8ba2bc62:
        PostInit();
        return true;
    }
    return cGZWinGen::DoMessage(msg);
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b5250 score 42
void cGZWinLuaScriptView::PostInit()
{
    if (mpWin134 == 0) {
        IUnk_ac7368* old = static_cast<IUnk_ac7368*>(mpWin134);
        if (old) {
            mpWin134 = 0;
            old->Release();
        }
        GetChildAs(0x8bab0311, 0x212cdc1f, OB_ADDR(&mpWin134));
        if (mpListWin == 0) {
            IUnk_ac7368* old2 = static_cast<IUnk_ac7368*>(mpListWin);
            if (old2) {
                mpListWin = 0;
                old2->Release();
            }
            GetChildAs(0x6bd68d89, 0xa13351b8, OB_ADDR(&mpListWin));
        }
        LocalWin_ac7368* local = 0;
        GetChildAs(0x2ba7ffce, 0xdaa6b9be, OB_ADDR(&local));
        if (local) {
            local->S14()->S118();
        }
        SetupScriptView();
        if (local) {
            local->Release();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b43e0 score 53
void cGZWinLuaScriptConsole::PostInit()
{
    if (mpTextWin == 0) {
        IUnk_ac7368* old = static_cast<IUnk_ac7368*>(mpTextWin);
        if (old) {
            mpTextWin = 0;
            old->Release();
        }
        GetChildAs(0x4ba2b021, 0xdaa6b9be, OB_ADDR(&mpTextWin));
        static_cast<TextWin_ac7368*>(mpTextWin)->S78(2, 1, 0);
        static_cast<TextWin_ac7368*>(mpTextWin)->S28(0x10000);
        static_cast<TextWin_ac7368*>(mpTextWin)->S28(0x8000);
        static_cast<TextWin_ac7368*>(mpTextWin)->S30(2);
        static_cast<TextWin_ac7368*>(mpTextWin)->S44(MakeFillColor(0, 0, 0), 4);
        static_cast<TextWin_ac7368*>(mpTextWin)->S44(MakeFillColor(0xc0, 0xc0, 0xc0), 5);
        RefreshView();
    }
}
#endif

// FUNCTION: 0x008ae780
int32_t OB_STDCALL Fn008ae780(LuaThread_ac7368* thread)
{
    LuaDebug_ac7368 ar;
    int32_t level = 0;
    lua_State* L = thread->GetState();
    if (lua_getstack(L, level, &ar)) {
        do {
            ++level;
        } while (lua_getstack(L, level, &ar));
    }
    return level;
}

// FUNCTION: 0x008af980
void OB_STDCALL Fn008af980(Grid_ac7368* grid, int32_t line)
{
    int32_t a[4];
    int32_t b[4];
    grid->SC8(a);
    grid->SCC(b);
    if (line < b[1]) {
        line = std::max(line - 12, 0);
    }
    if (line > b[3]) {
        line = std::min(line + 12, a[3]);
    }
    if (!grid->S1a0(0, line)) {
        grid->S1a4(0, line);
    }
}

// FUNCTION: 0x008b2250
ThreadInfo_ac7368::~ThreadInfo_ac7368()
{
    mBreakList.Fn008b1d00();
}

// FUNCTION: 0x008b3200
ThreadInfo_ac7368::ThreadInfo_ac7368()
    : mName(), mFile(), m2c(), mn40(0), mn44(0), mb48(false), mbAutoYield(false), mn4c(-1)
{
    bool allocator;
    mBreakList.Fn008b02b0(&allocator);
}

// FUNCTION: 0x008b18f0
Rec590_ac7368::Rec590_ac7368(const Rec590_ac7368& other)
    : mA(other.mA), mn14(other.mn14), mB(other.mB), mn2c(other.mn2c)
{
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b1840 score 11
Rec600_ac7368::Rec600_ac7368(const Rec600_ac7368& other)
    : mA(other.mA), mB(other.mB), mC(other.mC), mpRef(other.mpRef), mn40(other.mn40)
{
    if (mpRef) {
        mpRef->AddRef();
    }
}
#endif

// FUNCTION: 0x008b1970
VarRec_ac7368::VarRec_ac7368(const VarRec_ac7368& other)
    : mnA(other.mnA), mnB(other.mnB), mS(other.mS), mV(other.mV)
{
}

// FUNCTION: 0x008b1770
void VarList_ac7368::Clear()
{
    VarNode_ac7368* n = mpHead->mpNext;
    while (n != mpHead) {
        VarNode_ac7368* cur = n;
        n = n->mpNext;
        cur->mRec.~VarRec_ac7368();
        Fn0090cf63(cur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b2ac0 score 7
cGZWinLuaScriptView::cGZWinLuaScriptView()
{
    mpServer = 0;
    mpListWin = 0;
    mpWin134 = 0;
    mnScriptID = -1;
    mpWin13c = 0;
    mpWin140 = 0;
    mpWin144 = 0;
    mpWin148 = 0;
    mpList = 0;
    ListNode_ac7368* head = static_cast<ListNode_ac7368*>(::operator new(0x4c));
    head->mpNext = head;
    head->mpPrev = head;
    mpList = head;
    mnPauseCount = 0;
    mbRefresh = false;
    mn164 = 0;
    mnCallLevel = -1;
    mbEnabled = true;
}
#endif

// FUNCTION: 0x008b2bd0
cGZWinLuaScriptView::~cGZWinLuaScriptView()
{
    reinterpret_cast<List600_ac7368*>(&mpList)->Clear();
    if (mpList) {
        Fn0090cf63(mpList);
    }
    IUnk_ac7368* p;
    p = static_cast<IUnk_ac7368*>(mpWin148);
    if (p) {
        p->Release();
    }
    p = static_cast<IUnk_ac7368*>(mpWin144);
    if (p) {
        p->Release();
    }
    p = static_cast<IUnk_ac7368*>(mpWin140);
    if (p) {
        p->Release();
    }
    p = static_cast<IUnk_ac7368*>(mpWin13c);
    if (p) {
        p->Release();
    }
    p = static_cast<IUnk_ac7368*>(mpWin134);
    if (p) {
        p->Release();
    }
    p = static_cast<IUnk_ac7368*>(mpListWin);
    if (p) {
        p->Release();
    }
    p = static_cast<IUnk_ac7368*>(mpServer);
    if (p) {
        p->Release();
    }
}

// FUNCTION: 0x008b0410
bool cGZLuaScriptServer::Slot20_ac7368(uint32_t id, void* outLua, void* outName, void* outFile, void* outLine, void* outLevel, void* outFlag)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        ThreadInfo_ac7368* t = it->mpValue;
        if (outLua) {
            *static_cast<ThreadData_ac7368**>(outLua) = t->mpLuaRef.mp;
            if (t->mpLuaRef.mp) {
                t->mpLuaRef.mp->AddRef();
            }
        }
        if (outName) {
            *static_cast<cIGZString*>(outName) = t->mName;
        }
        if (outFile) {
            *static_cast<cIGZString*>(outFile) = t->mFile;
        }
        if (outLine) {
            *static_cast<int32_t*>(outLine) = t->mn40;
        }
        if (outLevel) {
            *static_cast<int32_t*>(outLevel) = t->mn44;
        }
        if (outFlag) {
            *static_cast<bool*>(outFlag) = t->mb48;
        }
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b22b0 score 64
bool cGZLuaScriptServer::Slot08_ac7368(uint32_t id)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    bool result = false;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        ThreadInfo_ac7368* t = it->mpValue;
        static_cast<Manager_ac7368*>(mpManager)->S1c(t->mpLuaRef.mp->GetScriptID());
        PostScriptChangeMessage(t->mpLuaRef.mp->GetScriptID(), 0xcba990d3, 0);
        if (t->mpLuaRef.mp) {
            ThreadData_ac7368* lua = t->mpLuaRef.mp;
            t->mpLuaRef.mp = 0;
            lua->Release();
        }
        delete t;
        MapNode_ac7368* header = map->mpEnd;
        void* node = Fn0040daf0(it, reinterpret_cast<char*>(header) + 4, reinterpret_cast<char*>(header) + 8, reinterpret_cast<char*>(header) + 0xc);
        if (node) {
            Fn0090cf63(node);
        }
        --map->mnCount;
        return true;
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b4210 score 73
bool cGZLuaScriptServer::Slot18_ac7368(uint32_t id, void* name, void* outList)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    ThreadInfo_ac7368* t;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        t = it->mpValue;
    } else {
        t = 0;
    }
    ListBreak_ac7368* out = static_cast<ListBreak_ac7368*>(outList);
    out->Clear();
    if (t) {
        for (BreakNode_ac7368* n = t->mBreakList.mpHead->mpNext; n != t->mBreakList.mpHead; n = n->mpNext) {
            if (static_cast<cIGZString*>(&n->mRec.mName)->IsEqual(static_cast<cIGZString*>(name), false)) {
                BreakNode_ac7368* head = out->mpHead;
                BreakNode_ac7368* node = out->Fn008b1f30(n->mRec);
                node->mpNext = head;
                node->mpPrev = head->mpPrev;
                head->mpPrev->mpNext = node;
                head->mpPrev = node;
            }
        }
        return true;
    }
    return false;
}
#endif

struct IdVector_ac7368 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
};

#ifdef OB_DRAFTS
// CLOSE: 0x008b1180 score 46
uint32_t cGZLuaScriptServer::Slot09_ac7368(uint32_t id)
{
    if (id == 0xffffffff) {
        IdVector_ac7368 ids;
        ids.mpBegin = 0;
        ids.mpEnd = 0;
        ids.mpCap = 0;
        Slot19_ac7368(&ids);
        uint32_t count = static_cast<uint32_t>(ids.mpEnd - ids.mpBegin);
        for (uint32_t i = 0; i < count; ++i) {
            Slot09_ac7368(ids.mpBegin[i]);
        }
        if (ids.mpBegin) {
            uint32_t* storage = ids.mpBegin;
            GET_ALLOC_AC7368(gpB5c430)
            gpB5c430->S10(storage);
        }
        return 1;
    }
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        ThreadInfo_ac7368* t = it->mpValue;
        ++t->mn40;
        if (t->mn40 == 1) {
            PostScriptChangeMessage(id, 0xebaaf9be, t->mn40);
        }
        return t->mn40;
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b1290 score 80
uint32_t cGZLuaScriptServer::Slot10_ac7368(uint32_t id)
{
    if (id == 0xffffffff) {
        IdVector_ac7368 ids;
        ids.mpBegin = 0;
        ids.mpEnd = 0;
        ids.mpCap = 0;
        Slot19_ac7368(&ids);
        uint32_t count = static_cast<uint32_t>(ids.mpEnd - ids.mpBegin);
        for (uint32_t i = 0; i < count; ++i) {
            Slot10_ac7368(ids.mpBegin[i]);
        }
        if (ids.mpBegin) {
            uint32_t* storage = ids.mpBegin;
            GET_ALLOC_AC7368(gpB5c430)
            gpB5c430->S10(storage);
        }
        return 1;
    }
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    MapNode_ac7368* it;
    map->Find(&it, reinterpret_cast<const int32_t*>(&id));
    if (it != map->mpEnd) {
        ThreadInfo_ac7368* t = it->mpValue;
        --t->mn40;
        if (t->mn40 == 0) {
            PostScriptChangeMessage(id, 0xebaaf9be, 0);
            ++t->mn44;
        }
        return t->mn40;
    }
    return 0;
}
#endif

// FUNCTION: 0x008b0320
cGZLuaScriptServer::~cGZLuaScriptServer()
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    if (map->mnCount) {
        RbHeader_ac7368* header = reinterpret_cast<RbHeader_ac7368*>(map->mpEnd);
        reinterpret_cast<Tree_ac7368*>(map)->Erase(header->mpRoot);
        header = reinterpret_cast<RbHeader_ac7368*>(map->mpEnd);
        header->mpLeftmost = reinterpret_cast<TreeNode_ac7368*>(header);
        header = reinterpret_cast<RbHeader_ac7368*>(map->mpEnd);
        header->mpRoot = 0;
        header = reinterpret_cast<RbHeader_ac7368*>(map->mpEnd);
        header->mpRightmost = reinterpret_cast<TreeNode_ac7368*>(header);
        map->mnCount = 0;
    }
    if (map->mpEnd) {
        Fn0090cf63(map->mpEnd);
    }
    if (mpRef38) {
        static_cast<IUnk_ac7368*>(mpRef38)->Release();
    }
    if (mpManager) {
        static_cast<IUnk_ac7368*>(mpManager)->Release();
    }
}

// FUNCTION: 0x008b01c0
bool cGZLuaScriptServer::Slot04_ae1d24()
{
    if (mbInitialized) {
        mbInitialized = false;
        Svc3_ac7368* svc = reinterpret_cast<Svc3_ac7368*>(Fn008793ec());
        if (svc) {
            svc->S28(reinterpret_cast<char*>(this) + 4);
        }
        ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
        while (map->mnCount) {
            RbHeader_ac7368* header = reinterpret_cast<RbHeader_ac7368*>(map->mpEnd);
            Slot08_ac7368(reinterpret_cast<MapNode_ac7368*>(header->mpLeftmost)->mnKey);
        }
        if (mpRef38) {
            static_cast<Ref38Obj_ac7368*>(mpRef38)->S0c()->S10();
            if (mpRef38) {
                IUnk_ac7368* p = static_cast<IUnk_ac7368*>(mpRef38);
                mpRef38 = 0;
                p->Release();
            }
        }
        if (mpManager) {
            static_cast<Mgr14_ac7368*>(mpManager)->S14();
            if (mpManager) {
                IUnk_ac7368* p = static_cast<IUnk_ac7368*>(mpManager);
                mpManager = 0;
                p->Release();
            }
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008afcf0 score 61
void TreeIter_ac7368::Fn008afcf0(TreeIter_ac7368* ret, int32_t unused)
{
    TreeNode_ac7368* old = mpNode;
    TreeNode_ac7368* n = old;
    if (n->mpRight) {
        n = n->mpRight;
        while (n->mpLeft) {
            n = n->mpLeft;
        }
    } else {
        TreeNode_ac7368* parent = n->mpParent;
        if (n == parent->mpRight) {
            do {
                n = parent;
                parent = parent->mpParent;
            } while (n == parent->mpRight);
        }
        if (n->mpRight != parent) {
            n = parent;
        }
    }
    mpNode = n;
    ret->mpNode = old;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b13a0 score 156
void cGZLuaScriptServer::Slot19_ac7368(void* outIDs)
{
    ThreadMap_ac7368* map = reinterpret_cast<ThreadMap_ac7368*>(mScriptMap);
    IdVector_ac7368* ids = static_cast<IdVector_ac7368*>(outIDs);
    TreeNode_ac7368* n = reinterpret_cast<RbHeader_ac7368*>(map->mpEnd)->mpLeftmost;
    while (n != reinterpret_cast<TreeNode_ac7368*>(map->mpEnd)) {
        uint32_t key = reinterpret_cast<MapNode_ac7368*>(n)->mnKey;
        if (ids->mpEnd != ids->mpCap) {
            if (ids->mpEnd) {
                *ids->mpEnd = key;
            }
            ++ids->mpEnd;
        } else {
            uint32_t oldCount = static_cast<uint32_t>(ids->mpEnd - ids->mpBegin);
            uint32_t grow = oldCount < 1 ? 1 : oldCount;
            uint32_t newCount = grow + oldCount;
            GET_ALLOC_AC7368(gpB5c430)
            uint32_t* storage = static_cast<uint32_t*>(gpB5c430->S0c(newCount * 4));
            uint32_t* fill = storage;
            if (ids->mpBegin != ids->mpEnd) {
                std::memmove(storage, ids->mpBegin, oldCount * 4);
                fill = storage + oldCount;
            }
            *fill = key;
            uint32_t* oldStorage = ids->mpBegin;
            GET_ALLOC_AC7368(gpB5c430)
            gpB5c430->S10(oldStorage);
            ids->mpBegin = storage;
            ids->mpEnd = fill + 1;
            ids->mpCap = storage + newCount;
        }
        TreeIter_ac7368 it;
        TreeIter_ac7368 old;
        it.mpNode = n;
        it.Fn008afcf0(&old, 0);
        n = it.mpNode;
    }
}
#endif
