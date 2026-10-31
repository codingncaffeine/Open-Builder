#include <cstddef>
#include <stddef.h>
#include <new>
#include "classes/cGZCommandParameterSet.h"
#include "classes/cGZCommandServer.h"
#include "classes/cGZMessage2CommandDispatcher.h"
#include "classes/cGZStringCommandGenerator.h"
#include "classes/cUnk00ad1638.h"
#include "gzcom/cRZString.h"
#include "gzcom/cIGZString.h"
#include <string.h>

// A tree node's links (color, parent, left, right) and the key that follows them.
struct RbNode_ad1660 {
    uint32_t mColor;
    RbNode_ad1660* mpParent;
    RbNode_ad1660* mpLeft;
    RbNode_ad1660* mpRight;
    uint32_t mKey;
};

// A variant value (20 bytes).
struct Variant_ad1660 {
    uint8_t mBytes[0x14];

    // STUB: 0x009166d4
    Variant_ad1660();
    // STUB: 0x00915d94
    Variant_ad1660(int32_t value);
    // STUB: 0x00916712
    Variant_ad1660(const Variant_ad1660& src);
    // STUB: 0x00915cde
    Variant_ad1660(const cIGZString& text);
    // STUB: 0x00915eb5
    ~Variant_ad1660();
    // STUB: 0x009161db
    Variant_ad1660& operator=(const Variant_ad1660& src);
};

// The smart pointer assignments (two instantiations).
struct RefA_ad1660 {
    void* mp;

    // STUB: 0x0094909a
    void Set(void* p);
};

struct RefB_ad1660 {
    void* mp;

    // STUB: 0x005447b0
    void Set(void* p);
};

// An object reached through its vtable only.
struct Obj_ad1660 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
};

struct Disp_ad1660 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual bool Init();
    virtual bool Shutdown();
    virtual uint32_t ExecuteCommand(uint32_t a, uint32_t b, uint32_t c);
};

struct Gen_ad1660 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual bool Init();
    virtual bool Shutdown();
    virtual void CommandRegistered(uint32_t id, const void* name, const void* desc);
    virtual void CommandUnregistered(uint32_t id, const void* name, const void* desc);
    virtual void V7();
    virtual uint32_t ExecuteCommand(uint32_t a, uint32_t b, uint32_t c);
    virtual bool ConvertStringToCommand(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
    virtual bool ConvertCommandToString(uint32_t a, uint32_t b, uint32_t c);
    virtual bool ConvertCommandOutputToString(uint32_t a, uint32_t b);
};

// The tree helpers of the standard library, shared by every instantiation.
// STUB: 0x0040d4c0
RbNode_ad1660* Fn0040d4c0(RbNode_ad1660* node);
// STUB: 0x0040d500
RbNode_ad1660* Fn0040d500(RbNode_ad1660* node);
// STUB: 0x0040d5e0
void Fn0040d5e0(RbNode_ad1660* node, RbNode_ad1660** root);
// STUB: 0x0040daf0
RbNode_ad1660* Fn0040daf0(RbNode_ad1660* node, RbNode_ad1660** root, RbNode_ad1660** leftmost, RbNode_ad1660** rightmost);
// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);
// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// An iterator, passed by value.
struct Iter_ad1660 {
    RbNode_ad1660* mpNode;

    Iter_ad1660(RbNode_ad1660* node)
        : mpNode(node)
    {
    }
};

// The fields every tree has, and the lookup by key that the instantiations share.
struct TreeBase_ad1660 {
    RbNode_ad1660* mpHeader;
    uint32_t mnCount;
    uint32_t mCompare;

    // STUB: 0x0098129c
    RbNode_ad1660* Find_98129c(const void* key);
    // STUB: 0x009492cb
    RbNode_ad1660* LowerBound_9492cb(const void* key);
    // STUB: 0x00939d41
    void Ctor_939d41();
};

// The result of an insertion: the node and whether it is new.
struct InsertResult_ad1660 {
    RbNode_ad1660* mpNode;
    bool mbInserted;
};

// A node the tree of parameters holds: the key, then the variant.
struct ParamPair_ad1660 {
    uint32_t mFirst;
    Variant_ad1660 mSecond;

    ParamPair_ad1660(const ParamPair_ad1660& other);
    ParamPair_ad1660(const uint32_t& key, const Variant_ad1660& value);
    // STUB: 0x00929911
    void Dtor(uint32_t flags);
};

struct ParamNode_ad1660 : RbNode_ad1660 {
    Variant_ad1660 mValue;
};

struct ParamTree_ad1660 : TreeBase_ad1660 {
    void EraseSubtree_929d69(ParamNode_ad1660* node);
    void Erase_929cad(Iter_ad1660 pos);
    void Clear_929f15();
    void Dtor_92a278();
    ParamNode_ad1660* NewNode_929dd7(const ParamPair_ad1660* v);
    RbNode_ad1660** Insert_929f7e(RbNode_ad1660** out, RbNode_ad1660* x, RbNode_ad1660* y, const ParamPair_ad1660* v, uint32_t w);
    // STUB: 0x0092a006
    InsertResult_ad1660* InsertUnique_92a006(InsertResult_ad1660* out, const ParamPair_ad1660* key);
    // STUB: 0x0092a337
    RbNode_ad1660** InsertHint_92a337(RbNode_ad1660** out, Iter_ad1660 position, const ParamPair_ad1660* v);
    // STUB: 0x0092a593
    RbNode_ad1660** InsertHint_92a593(RbNode_ad1660** out, RbNode_ad1660* position, const ParamPair_ad1660* v);
    // STUB: 0x0092ab69
    Variant_ad1660* Index_92ab69(const uint32_t* key);
};

// A value of the tree of ulongs.
struct SetVal_ad1660 {
    uint32_t mFirst;

    // STUB: 0x00966956
    SetVal_ad1660(const SetVal_ad1660& other);
    // STUB: 0x0093ab29
    void Dtor(uint32_t flags);
};

struct SetNode_ad1660 : RbNode_ad1660 {
};

struct SetTree_ad1660 : TreeBase_ad1660 {
    void EraseSubtree_929da0(SetNode_ad1660* node);
    void Erase_929cea(Iter_ad1660 pos);
    void Clear_929f3e();
    void Dtor_92a28f();
    SetNode_ad1660* NewNode_929df8(const SetVal_ad1660* v);
    RbNode_ad1660** Insert_92a08a(RbNode_ad1660** out, RbNode_ad1660* x, RbNode_ad1660* y, const SetVal_ad1660* v, uint32_t w);
    // STUB: 0x0092a476
    InsertResult_ad1660* InsertUnique_92a476(InsertResult_ad1660* out, const SetVal_ad1660* key);
    void Insert_92a53f(InsertResult_ad1660* out, const SetVal_ad1660* value);
};

// A command's two strings and its id.
struct CmdValue_ad1660 {
    uint32_t mId;
    cRZString mName;
    cRZString mDesc;

    CmdValue_ad1660();
    ~CmdValue_ad1660();
    CmdValue_ad1660(const CmdValue_ad1660& other);
};

struct CmdPair_ad1660 {
    uint32_t mFirst;
    CmdValue_ad1660 mSecond;

    CmdPair_ad1660(const CmdPair_ad1660& other);
    CmdPair_ad1660(const uint32_t& key, const CmdValue_ad1660& value);
    // STUB: 0x0092abcc
    void Dtor(uint32_t flags);
};

struct CmdNode_ad1660 : RbNode_ad1660 {
    CmdValue_ad1660 mValue;
};

struct CmdTree_ad1660 : TreeBase_ad1660 {
    void EraseSubtree_92ac76(CmdNode_ad1660* node);
    void Erase_92ac39(Iter_ad1660 pos);
    void Clear_92ace7();
    void Dtor_92adc9();
    // STUB: 0x0092ade0
    CmdNode_ad1660* NewNode_92ade0(const CmdPair_ad1660* v);
    RbNode_ad1660** Insert_92aeec(RbNode_ad1660** out, RbNode_ad1660* x, RbNode_ad1660* y, const CmdPair_ad1660* v, uint32_t w);
    // STUB: 0x0092aff1
    InsertResult_ad1660* InsertUnique_92aff1(InsertResult_ad1660* out, const CmdPair_ad1660* key);
};

// The fields past the base classes of the message, of the parameter set and of the command server.
struct MsgView_ad1660 {
    uint8_t mPad[0x30];
    void* mpData1;
    void* mpData2;
};

struct ParamSetView_ad1660 {
    void* mpVtbl;
    uint32_t mnRefCount;
    ParamTree_ad1660 mParams;
    Variant_ad1660 mStatus;
};

// The message's second base subobject (cRZMessage2Standard) reached by its slots.
struct Msg2If_ad1660 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void SetType(uint32_t type);
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void SetVoid1(void* data);
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void SetVoid2(void* data);
};

struct MsgSrv_ad1660 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void Send(cRZMessage2Standard* msg);
};

// A variant reached by its slots.
struct VarIf_ad1660 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual uint32_t AsInt();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual bool ToString(cIGZString* out);
};

// The command server reached by its slots.
struct SrvIf_ad1660 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual bool RegisterCommand(uint32_t id, const char* name, const char* desc);
    virtual void V7();
    virtual bool RegisterCommandParameterInfo(uint32_t id, const char* text);
    virtual bool UnregisterCommand(uint32_t id);
    virtual void V10();
    virtual bool GetCommandInfo(uint32_t id, cIGZString* name, cIGZString* desc);
    virtual uint32_t GetCommandID(const cIGZString* name);
    virtual void V13();
    virtual void V14();
    virtual bool RegisterCommandGenerator(void* generator);
    virtual void V16();
    virtual void* GetCommandDispatcher();
    virtual bool SetCommandDispatcher(void* dispatcher);
    virtual uint32_t ExecuteCommandByString(const char* text, uint32_t length, void* params);
    virtual uint32_t ExecuteCommandById(uint32_t id, void* params, void* output);
};

struct CmdInfo_ad1660 {
    uint32_t mId;
    const char* mpName;
    const char* mpDesc;
};

struct ServerView_ad1660 {
    uint8_t mPad[0x24];
    CmdTree_ad1660 mCommands;
    void* mpDispatcher;
    void* mpDefaultDispatcher;
    void* mpGenerator;
    SetTree_ad1660 mGenerators;
    bool mbFlag;

    bool Notify_929e54(const CmdValue_ad1660* info, bool registered, void* generator);
};

#define OB_MSGIF(p) reinterpret_cast<Msg2If_ad1660*>(reinterpret_cast<char*>(p) + 4)

// Objects the original builds with `new`; their constructors (which store the vtable) stay the original's.
struct DispObj_ad1660 {
    uint8_t mBytes[0x1c];

    // STUB: 0x00929c74
    DispObj_ad1660();
};

struct GenObj_ad1660 {
    uint8_t mBytes[0x1c];

    // STUB: 0x0092a6c4
    GenObj_ad1660();
};

struct ParamSetObj_ad1660 {
    uint8_t mBytes[0x28];

    // STUB: 0x0092a5b0
    ParamSetObj_ad1660();
};

struct MsgObj_ad1660 {
    uint8_t mBytes[0x38];

    // STUB: 0x00929c2b
    MsgObj_ad1660();
};

// A reference held on a generator (taken by the constructor, left in the destructor).
struct GenHold_ad1660 {
    void* mp;

    // STUB: 0x0096e773
    GenHold_ad1660(void* p);
    ~GenHold_ad1660()
    {
        if (mp) {
            reinterpret_cast<Obj_ad1660*>(mp)->V2();
        }
    }
};

// The service handle the generator's Init takes and gives back.
struct SrvHold_ad1660 {
    void* mp;

    // STUB: 0x00562da0
    SrvHold_ad1660();
    // STUB: 0x00562dd0
    ~SrvHold_ad1660();
};

// A vector of strings.
struct StrVec_ad1660 {
    cRZString* mpStart;
    cRZString* mpFinish;
    cRZString* mpEnd;

    // STUB: 0x005c87a0
    void Resize_5c87a0(uint32_t size);
};

// STUB: 0x00910bd3
bool Fn00910bd3(const char* text, uint32_t length, uint32_t separator, cRZString* token, int32_t* found);
// STUB: 0x009133da
void* Fn009133da(uint32_t size);

// A vector of ulongs.
struct Vec_ad1660 {
    uint32_t* mpStart;
    uint32_t* mpFinish;
    uint32_t* mpEnd;

    // STUB: 0x0092a2a6
    void InsertOverflow_92a2a6(uint32_t* position, const uint32_t* value, const void* tag, uint32_t count, bool atEnd);
    // STUB: 0x0092a562
    void PushBack_92a562(const uint32_t* value);
};

// The allocator the containers use (reached through a global).
struct Alloc_ad1660 {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void* Alloc(uint32_t size);
    virtual void Free(void* p);
};

struct AllocHold_ad1660 {
    void* mp;

    // STUB: 0x00411840
    AllocHold_ad1660();
    // STUB: 0x00411870
    ~AllocHold_ad1660();
};

// GLOBAL: 0x00b629e8
extern Alloc_ad1660* gpB629e8_ad1660;

// STUB: 0x00407a50
void* Fn00407a50(const void* first, const void* last, void* dest);
// STUB: 0x004186f0
uint32_t* Fn004186f0(uint32_t* dest, uint32_t count, const uint32_t* value);

// FUNCTION: 0x00929bcc
bool cGZCommandServer::Slot22_ad1660(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Gen_ad1660* gen = reinterpret_cast<Gen_ad1660*>(mpGenerator);
    if (gen) {
        return gen->ConvertStringToCommand(a, b, c, d);
    }
    return false;
}

// FUNCTION: 0x00929bdd
bool cGZCommandServer::Slot23_ad1660(uint32_t a, uint32_t b, uint32_t c)
{
    Gen_ad1660* gen = reinterpret_cast<Gen_ad1660*>(mpGenerator);
    if (gen) {
        return gen->ConvertCommandToString(a, b, c);
    }
    return false;
}

// FUNCTION: 0x00929bee
bool cGZCommandServer::Slot24_ad1660(uint32_t a, uint32_t b)
{
    Gen_ad1660* gen = reinterpret_cast<Gen_ad1660*>(mpGenerator);
    if (gen) {
        return gen->ConvertCommandOutputToString(a, b);
    }
    return false;
}

// FUNCTION: 0x00929ba8
uint32_t cGZCommandServer::Slot20_ad1660(uint32_t a, uint32_t b, uint32_t c)
{
    Disp_ad1660* disp = reinterpret_cast<Disp_ad1660*>(mpDispatcher);
    if (disp) {
        return disp->ExecuteCommand(a, b, c);
    }
    return 2;
}

// FUNCTION: 0x00929bba
uint32_t cGZCommandServer::Slot19_ad1660(uint32_t a, uint32_t b, uint32_t c)
{
    Gen_ad1660* gen = reinterpret_cast<Gen_ad1660*>(mpGenerator);
    if (gen) {
        return gen->ExecuteCommand(a, b, c);
    }
    return 2;
}

// FUNCTION: 0x00929e40
uint32_t cGZCommandParameterSet::GetFirstParameterID()
{
    if (mnParamCount) {
        RbNode_ad1660* header = reinterpret_cast<RbNode_ad1660*>(mpParamHeader);
        return header->mpLeft->mKey;
    }
    return 0xffffffff;
}

// FUNCTION: 0x00929b92
bool cGZCommandServer::Slot18_ad1660(uint32_t a)
{
    RefA_ad1660* ref = reinterpret_cast<RefA_ad1660*>(&mpDispatcher);
    void* p = OB_PTR(void, a);
    if (ref->mp != p) {
        ref->Set(p);
    }
    return true;
}

// FUNCTION: 0x00929724
uint32_t cGZStringCommandGenerator::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete this;
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00929676 score 17
bool cGZCommandParameterSet::QueryInterface(uint32_t a, uint32_t b)
{
    if (a == 0x4b8c39e4 || a == 0x4b8c39e5 || a == 1) {
        *OB_PTR(cGZCommandParameterSet*, b) = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009296f5 score 17
bool cGZStringCommandGenerator::QueryInterface(uint32_t a, uint32_t b)
{
    if (a == 0x0b90251f || a == 0x0b90251e || a == 1) {
        *OB_PTR(cGZStringCommandGenerator*, b) = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009297de score 17
bool cGZMessage2CommandDispatcher::QueryInterface(uint32_t a, uint32_t b)
{
    if (a == 0x0b903cc3 || a == 0x0b903cc4 || a == 1) {
        *OB_PTR(cGZMessage2CommandDispatcher*, b) = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092980d score 23
bool cGZCommandServer::QueryInterface(unsigned int a, void** b)
{
    if (a == 0xcb90253a || a == 0xcb90253b || a == 1) {
        *b = this;
        AddRef();
        return true;
    }
    return cRZSystemService::QueryInterface(a, b);
}
#endif

// FUNCTION: 0x009296d5
bool cGZCommandParameterSet::ValidateParameter(uint32_t a, uint32_t b)
{
    if (GetParameter(a) && b == 0xff) {
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009296a5 score 9
void cGZCommandParameterSet::SetStatusParameterValue(uint32_t a)
{
    Variant_ad1660 value(static_cast<int32_t>(a));
    SetParameter(0x2b999d2b, &value);
}
#endif

// FUNCTION: 0x00929979
bool cGZStringCommandGenerator::Shutdown()
{
    reinterpret_cast<RefB_ad1660*>(&mpObjA)->Set(0);
    reinterpret_cast<RefB_ad1660*>(&mpParamSet)->Set(0);
    return true;
}

// FUNCTION: 0x00929a90
bool cGZMessage2CommandDispatcher::Shutdown()
{
    reinterpret_cast<RefB_ad1660*>(&mpServer)->Set(0);
    reinterpret_cast<RefA_ad1660*>(&mpMessage)->Set(0);
    reinterpret_cast<RefB_ad1660*>(&mpInput)->Set(0);
    reinterpret_cast<RefB_ad1660*>(&mpOutput)->Set(0);
    Obj_ad1660* obj = reinterpret_cast<Obj_ad1660*>(mpGenerator);
    if (obj) {
        obj->V4();
        reinterpret_cast<RefA_ad1660*>(&mpGenerator)->Set(0);
    }
    return true;
}

// FUNCTION: 0x00929930
ParamPair_ad1660::ParamPair_ad1660(const ParamPair_ad1660& other)
    : mFirst(other.mFirst), mSecond(other.mSecond)
{
}

// FUNCTION: 0x009298f4
ParamPair_ad1660::ParamPair_ad1660(const uint32_t& key, const Variant_ad1660& value)
    : mFirst(key), mSecond(value)
{
}

// FUNCTION: 0x0092aa1f
CmdValue_ad1660::CmdValue_ad1660()
    : mName(), mDesc()
{
}

// FUNCTION: 0x0092aa36
CmdValue_ad1660::~CmdValue_ad1660()
{
}

// FUNCTION: 0x0092ac06
CmdValue_ad1660::CmdValue_ad1660(const CmdValue_ad1660& other)
    : mId(other.mId), mName(other.mName), mDesc(other.mDesc)
{
}

// FUNCTION: 0x0092acad
CmdPair_ad1660::CmdPair_ad1660(const CmdPair_ad1660& other)
    : mFirst(other.mFirst), mSecond(other.mSecond)
{
}

// FUNCTION: 0x0092acca
CmdPair_ad1660::CmdPair_ad1660(const uint32_t& key, const CmdValue_ad1660& value)
    : mFirst(key), mSecond(value)
{
}

// FUNCTION: 0x00929dd7
ParamNode_ad1660* ParamTree_ad1660::NewNode_929dd7(const ParamPair_ad1660* v)
{
    ParamNode_ad1660* node = static_cast<ParamNode_ad1660*>(Fn0090cf54(0x28));
    // the pair is the node from its key on: addressed through the node, which holds all of it
    new (reinterpret_cast<char*>(node) + offsetof(RbNode_ad1660, mKey)) ParamPair_ad1660(*v);
    return node;
}

// FUNCTION: 0x00929df8
SetNode_ad1660* SetTree_ad1660::NewNode_929df8(const SetVal_ad1660* v)
{
    SetNode_ad1660* node = static_cast<SetNode_ad1660*>(Fn0090cf54(0x14));
    new (&node->mKey) SetVal_ad1660(*v);
    return node;
}

// FUNCTION: 0x00929d69
void ParamTree_ad1660::EraseSubtree_929d69(ParamNode_ad1660* node)
{
    while (node) {
        EraseSubtree_929d69(static_cast<ParamNode_ad1660*>(node->mpRight));
        ParamNode_ad1660* left = static_cast<ParamNode_ad1660*>(node->mpLeft);
        reinterpret_cast<ParamPair_ad1660*>(&node->mKey)->Dtor(0);
        Fn0090cf63(node);
        node = left;
    }
}

// FUNCTION: 0x00929cad
void ParamTree_ad1660::Erase_929cad(Iter_ad1660 pos)
{
    RbNode_ad1660* header = mpHeader;
    ParamNode_ad1660* node = static_cast<ParamNode_ad1660*>(Fn0040daf0(pos.mpNode, &header->mpParent, &header->mpLeft, &header->mpRight));
    reinterpret_cast<ParamPair_ad1660*>(&node->mKey)->Dtor(0);
    if (node) {
        Fn0090cf63(node);
    }
    --mnCount;
}

// FUNCTION: 0x00929f15
void ParamTree_ad1660::Clear_929f15()
{
    if (mnCount) {
        EraseSubtree_929d69(static_cast<ParamNode_ad1660*>(mpHeader->mpParent));
        mpHeader->mpLeft = mpHeader;
        mpHeader->mpParent = 0;
        mpHeader->mpRight = mpHeader;
        mnCount = 0;
    }
}

// FUNCTION: 0x0092a278
void ParamTree_ad1660::Dtor_92a278()
{
    Clear_929f15();
    if (mpHeader) {
        Fn0090cf63(mpHeader);
    }
}

// FUNCTION: 0x00929f7e
RbNode_ad1660** ParamTree_ad1660::Insert_929f7e(RbNode_ad1660** out, RbNode_ad1660* x, RbNode_ad1660* y, const ParamPair_ad1660* v, uint32_t w)
{
    RbNode_ad1660* node;
    if (y == mpHeader || (w == 0 && (x != 0 || v->mFirst < y->mKey))) {
        node = NewNode_929dd7(v);
        y->mpLeft = node;
        if (y == mpHeader) {
            mpHeader->mpParent = node;
            mpHeader->mpRight = node;
        } else if (y == mpHeader->mpLeft) {
            mpHeader->mpLeft = node;
        }
    } else {
        node = NewNode_929dd7(v);
        y->mpRight = node;
        if (y == mpHeader->mpRight) {
            mpHeader->mpRight = node;
        }
    }
    node->mpLeft = 0;
    node->mpRight = 0;
    node->mpParent = y;
    Fn0040d5e0(node, &mpHeader->mpParent);
    ++mnCount;
    *out = node;
    return out;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092a006 score 49
InsertResult_ad1660* ParamTree_ad1660::InsertUnique_92a006(InsertResult_ad1660* out, const ParamPair_ad1660* key)
{
    RbNode_ad1660* y = mpHeader;
    RbNode_ad1660* x = y->mpParent;
    bool comp = true;
    while (x) {
        y = x;
        comp = key->mFirst < x->mKey;
        x = comp ? x->mpLeft : x->mpRight;
    }
    RbNode_ad1660* j = y;
    RbNode_ad1660* it;
    if (comp) {
        if (y == mpHeader->mpLeft) {
            goto insert;
        }
        j = Fn0040d500(y);
    }
    if (j->mKey < key->mFirst) {
insert:
        Insert_929f7e(&it, x, y, key, 0);
        out->mpNode = it;
        out->mbInserted = true;
        return out;
    }
    out->mpNode = j;
    out->mbInserted = false;
    return out;
}
#endif

// FUNCTION: 0x00929da0
void SetTree_ad1660::EraseSubtree_929da0(SetNode_ad1660* node)
{
    while (node) {
        EraseSubtree_929da0(static_cast<SetNode_ad1660*>(node->mpRight));
        SetNode_ad1660* left = static_cast<SetNode_ad1660*>(node->mpLeft);
        reinterpret_cast<SetVal_ad1660*>(&node->mKey)->Dtor(0);
        Fn0090cf63(node);
        node = left;
    }
}

// FUNCTION: 0x00929cea
void SetTree_ad1660::Erase_929cea(Iter_ad1660 pos)
{
    RbNode_ad1660* header = mpHeader;
    SetNode_ad1660* node = static_cast<SetNode_ad1660*>(Fn0040daf0(pos.mpNode, &header->mpParent, &header->mpLeft, &header->mpRight));
    reinterpret_cast<SetVal_ad1660*>(&node->mKey)->Dtor(0);
    if (node) {
        Fn0090cf63(node);
    }
    --mnCount;
}

// FUNCTION: 0x00929f3e
void SetTree_ad1660::Clear_929f3e()
{
    if (mnCount) {
        EraseSubtree_929da0(static_cast<SetNode_ad1660*>(mpHeader->mpParent));
        mpHeader->mpLeft = mpHeader;
        mpHeader->mpParent = 0;
        mpHeader->mpRight = mpHeader;
        mnCount = 0;
    }
}

// FUNCTION: 0x0092a28f
void SetTree_ad1660::Dtor_92a28f()
{
    Clear_929f3e();
    if (mpHeader) {
        Fn0090cf63(mpHeader);
    }
}

// FUNCTION: 0x0092a08a
RbNode_ad1660** SetTree_ad1660::Insert_92a08a(RbNode_ad1660** out, RbNode_ad1660* x, RbNode_ad1660* y, const SetVal_ad1660* v, uint32_t w)
{
    RbNode_ad1660* node;
    if (y == mpHeader || (w == 0 && (x != 0 || v->mFirst < y->mKey))) {
        node = NewNode_929df8(v);
        y->mpLeft = node;
        if (y == mpHeader) {
            mpHeader->mpParent = node;
            mpHeader->mpRight = node;
        } else if (y == mpHeader->mpLeft) {
            mpHeader->mpLeft = node;
        }
    } else {
        node = NewNode_929df8(v);
        y->mpRight = node;
        if (y == mpHeader->mpRight) {
            mpHeader->mpRight = node;
        }
    }
    node->mpLeft = 0;
    node->mpRight = 0;
    node->mpParent = y;
    Fn0040d5e0(node, &mpHeader->mpParent);
    ++mnCount;
    *out = node;
    return out;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092a476 score 49
InsertResult_ad1660* SetTree_ad1660::InsertUnique_92a476(InsertResult_ad1660* out, const SetVal_ad1660* key)
{
    RbNode_ad1660* y = mpHeader;
    RbNode_ad1660* x = y->mpParent;
    bool comp = true;
    while (x) {
        y = x;
        comp = key->mFirst < x->mKey;
        x = comp ? x->mpLeft : x->mpRight;
    }
    RbNode_ad1660* j = y;
    RbNode_ad1660* it;
    if (comp) {
        if (y == mpHeader->mpLeft) {
            goto insert;
        }
        j = Fn0040d500(y);
    }
    if (j->mKey < key->mFirst) {
insert:
        Insert_92a08a(&it, x, y, key, 0);
        out->mpNode = it;
        out->mbInserted = true;
        return out;
    }
    out->mpNode = j;
    out->mbInserted = false;
    return out;
}
#endif

// FUNCTION: 0x0092ac76
void CmdTree_ad1660::EraseSubtree_92ac76(CmdNode_ad1660* node)
{
    while (node) {
        EraseSubtree_92ac76(static_cast<CmdNode_ad1660*>(node->mpRight));
        CmdNode_ad1660* left = static_cast<CmdNode_ad1660*>(node->mpLeft);
        reinterpret_cast<CmdPair_ad1660*>(&node->mKey)->Dtor(0);
        Fn0090cf63(node);
        node = left;
    }
}

// FUNCTION: 0x0092ac39
void CmdTree_ad1660::Erase_92ac39(Iter_ad1660 pos)
{
    RbNode_ad1660* header = mpHeader;
    CmdNode_ad1660* node = static_cast<CmdNode_ad1660*>(Fn0040daf0(pos.mpNode, &header->mpParent, &header->mpLeft, &header->mpRight));
    reinterpret_cast<CmdPair_ad1660*>(&node->mKey)->Dtor(0);
    if (node) {
        Fn0090cf63(node);
    }
    --mnCount;
}

// FUNCTION: 0x0092ace7
void CmdTree_ad1660::Clear_92ace7()
{
    if (mnCount) {
        EraseSubtree_92ac76(static_cast<CmdNode_ad1660*>(mpHeader->mpParent));
        mpHeader->mpLeft = mpHeader;
        mpHeader->mpParent = 0;
        mpHeader->mpRight = mpHeader;
        mnCount = 0;
    }
}

// FUNCTION: 0x0092adc9
void CmdTree_ad1660::Dtor_92adc9()
{
    Clear_92ace7();
    if (mpHeader) {
        Fn0090cf63(mpHeader);
    }
}

// FUNCTION: 0x0092aeec
RbNode_ad1660** CmdTree_ad1660::Insert_92aeec(RbNode_ad1660** out, RbNode_ad1660* x, RbNode_ad1660* y, const CmdPair_ad1660* v, uint32_t w)
{
    RbNode_ad1660* node;
    if (y == mpHeader || (w == 0 && (x != 0 || v->mFirst < y->mKey))) {
        node = NewNode_92ade0(v);
        y->mpLeft = node;
        if (y == mpHeader) {
            mpHeader->mpParent = node;
            mpHeader->mpRight = node;
        } else if (y == mpHeader->mpLeft) {
            mpHeader->mpLeft = node;
        }
    } else {
        node = NewNode_92ade0(v);
        y->mpRight = node;
        if (y == mpHeader->mpRight) {
            mpHeader->mpRight = node;
        }
    }
    node->mpLeft = 0;
    node->mpRight = 0;
    node->mpParent = y;
    Fn0040d5e0(node, &mpHeader->mpParent);
    ++mnCount;
    *out = node;
    return out;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092aff1 score 49
InsertResult_ad1660* CmdTree_ad1660::InsertUnique_92aff1(InsertResult_ad1660* out, const CmdPair_ad1660* key)
{
    RbNode_ad1660* y = mpHeader;
    RbNode_ad1660* x = y->mpParent;
    bool comp = true;
    while (x) {
        y = x;
        comp = key->mFirst < x->mKey;
        x = comp ? x->mpLeft : x->mpRight;
    }
    RbNode_ad1660* j = y;
    RbNode_ad1660* it;
    if (comp) {
        if (y == mpHeader->mpLeft) {
            goto insert;
        }
        j = Fn0040d500(y);
    }
    if (j->mKey < key->mFirst) {
insert:
        Insert_92aeec(&it, x, y, key, 0);
        out->mpNode = it;
        out->mbInserted = true;
        return out;
    }
    out->mpNode = j;
    out->mbInserted = false;
    return out;
}
#endif

// FUNCTION: 0x00929e54
bool ServerView_ad1660::Notify_929e54(const CmdValue_ad1660* info, bool registered, void* generator)
{
    if (info) {
        Gen_ad1660* gen = reinterpret_cast<Gen_ad1660*>(generator);
        if (gen) {
            if (registered) {
                gen->CommandRegistered(info->mId, &info->mName, &info->mDesc);
            } else {
                gen->CommandUnregistered(info->mId, &info->mName, &info->mDesc);
            }
        } else {
            RbNode_ad1660* header = mGenerators.mpHeader;
            RbNode_ad1660* it = header->mpLeft;
            while (it != header) {
                Notify_929e54(info, registered, OB_PTR(void, it->mKey));
                it = Fn0040d4c0(it);
            }
        }
    } else {
        RbNode_ad1660* header = mCommands.mpHeader;
        RbNode_ad1660* it = header->mpLeft;
        while (it != header) {
            Notify_929e54(&static_cast<CmdNode_ad1660*>(it)->mValue, registered, generator);
            it = Fn0040d4c0(it);
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00929ad5 score 14
uint32_t cGZMessage2CommandDispatcher::ExecuteCommand(uint32_t a, void* b, void* c)
{
    uint32_t result = 2;
    if (mpServer) {
        if (!b) {
            reinterpret_cast<cGZCommandParameterSet*>(mpInput)->SetParameterCount(0);
            b = mpInput;
        }
        if (!c) {
            reinterpret_cast<cGZCommandParameterSet*>(mpOutput)->SetParameterCount(0);
            c = mpOutput;
        }
        OB_MSGIF(mpMessage)->SetType(a);
        OB_MSGIF(mpMessage)->SetVoid1(b);
        reinterpret_cast<RefA_ad1660*>(&reinterpret_cast<MsgView_ad1660*>(mpMessage)->mpData1)->Set(b);
        OB_MSGIF(mpMessage)->SetVoid2(c);
        reinterpret_cast<RefA_ad1660*>(&reinterpret_cast<MsgView_ad1660*>(mpMessage)->mpData2)->Set(c);
        reinterpret_cast<MsgSrv_ad1660*>(mpServer)->Send(reinterpret_cast<cUnk00ad1638*>(mpMessage));
        cGZCommandParameterSet* output = reinterpret_cast<cGZCommandParameterSet*>(c);
        result = 0;
        void* status = output->GetParameter(0x2b999d2b);
        if (status) {
            result = reinterpret_cast<VarIf_ad1660*>(status)->AsInt();
        } else {
            output->SetStatusParameterValue(0);
        }
    }
    return result;
}
#endif

// FUNCTION: 0x00929994
uint32_t cGZStringCommandGenerator::ExecuteCommand(const char* a, uint32_t b, void* c)
{
    cGZCommandParameterSet* params = 0;
    if (mpObjA) {
        uint32_t id;
        if (ConvertStringToCommand(a, b, &id, &params)) {
            uint32_t r = reinterpret_cast<SrvIf_ad1660*>(mpObjA)->ExecuteCommandById(id, params, c);
            if (params) {
                params->Release();
            }
            return r;
        }
        if (params) {
            params->Release();
        }
    }
    return 2;
}

// FUNCTION: 0x00929740
void cGZStringCommandGenerator::ConvertStringToArgumentString(const void* a, void* b)
{
    const cIGZString& source = *reinterpret_cast<const cIGZString*>(a);
    cIGZString& dest = *reinterpret_cast<cIGZString*>(b);
    if (&dest != &source) {
        dest = source;
    }
    if (source.Find(" ", 0, true) == -1 && source.Find("\t", 0, true) == -1) {
        return;
    }
    dest.Insert(0, "\"", 1);
    dest.Append("\"", 1);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00929844 score 17
bool cGZCommandServer::Slot07_ad1660(uint32_t a, uint32_t b)
{
    if (b) {
        const CmdInfo_ad1660* info = OB_PTR(const CmdInfo_ad1660, a);
        do {
            if (info->mId == 0 || info->mpName == 0 || *info->mpName == 0) {
                break;
            }
            reinterpret_cast<SrvIf_ad1660*>(this)->RegisterCommand(info->mId, info->mpName, info->mpDesc);
            info = reinterpret_cast<const CmdInfo_ad1660*>(reinterpret_cast<const char*>(info) + sizeof(CmdInfo_ad1660));
        } while (--b);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00929881 score 20
bool cGZCommandServer::Slot10_ad1660(uint32_t a, uint32_t b)
{
    if (b) {
        const CmdInfo_ad1660* info = OB_PTR(const CmdInfo_ad1660, a);
        do {
            if (info->mId == 0) {
                break;
            }
            reinterpret_cast<SrvIf_ad1660*>(this)->UnregisterCommand(info->mId);
            ++info;
        } while (--b);
    }
    return true;
}
#endif

// FUNCTION: 0x00929ee0
uint32_t cGZCommandServer::Slot12_ad1660(uint32_t a)
{
    ServerView_ad1660* view = reinterpret_cast<ServerView_ad1660*>(this);
    RbNode_ad1660* header = view->mCommands.mpHeader;
    RbNode_ad1660* it = header->mpLeft;
    while (it != header) {
        CmdNode_ad1660* node = static_cast<CmdNode_ad1660*>(it);
        if (static_cast<cIGZString&>(node->mValue.mName).CompareTo(*OB_PTR(cIGZString, a), false) == 0) {
            return node->mValue.mId;
        }
        it = Fn0040d4c0(it);
    }
    return 0;
}

// FUNCTION: 0x0092a1f6
bool cGZCommandServer::Slot11_ad1660(uint32_t a, uint32_t b, uint32_t c)
{
    ServerView_ad1660* view = reinterpret_cast<ServerView_ad1660*>(this);
    CmdNode_ad1660* node = static_cast<CmdNode_ad1660*>(view->mCommands.Find_98129c(&a));
    if (node != view->mCommands.mpHeader) {
        *OB_PTR(cIGZString, b) = node->mValue.mName;
        cIGZString* desc = OB_PTR(cIGZString, c);
        if (desc) {
            *desc = node->mValue.mDesc;
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x0092a162
void* cGZCommandParameterSet::Slot05_ad16c8(uint32_t a)
{
    ParamSetView_ad1660* view = reinterpret_cast<ParamSetView_ad1660*>(this);
    ParamNode_ad1660* node = static_cast<ParamNode_ad1660*>(view->mParams.Find_98129c(&a));
    if (node != view->mParams.mpHeader) {
        return &node->mValue;
    }
    return &view->mStatus;
}

// FUNCTION: 0x0092a186
void* cGZCommandParameterSet::GetParameter(uint32_t a)
{
    ParamSetView_ad1660* view = reinterpret_cast<ParamSetView_ad1660*>(this);
    ParamNode_ad1660* node = static_cast<ParamNode_ad1660*>(view->mParams.Find_98129c(&a));
    if (node != view->mParams.mpHeader) {
        return &node->mValue;
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092a1a5 score 6
void cGZCommandParameterSet::RemoveParameter(uint32_t a)
{
    ParamSetView_ad1660* view = reinterpret_cast<ParamSetView_ad1660*>(this);
    ParamTree_ad1660* tree = &view->mParams;
    RbNode_ad1660* node = tree->Find_98129c(&a);
    if (node != tree->mpHeader) {
        tree->Erase_929cad(Iter_ad1660(node));
    }
}
#endif

// FUNCTION: 0x0092a1c9
uint32_t cGZCommandParameterSet::GetNextParameterID(uint32_t a)
{
    ParamSetView_ad1660* view = reinterpret_cast<ParamSetView_ad1660*>(this);
    ParamTree_ad1660* tree = &view->mParams;
    RbNode_ad1660* node = tree->Find_98129c(&a);
    RbNode_ad1660* header = tree->mpHeader;
    if (node != header) {
        node = Fn0040d4c0(node);
        if (node != header) {
            return node->mKey;
        }
    }
    return 0xffffffff;
}

// FUNCTION: 0x00929e19
void cGZCommandParameterSet::AppendParameter(void* a)
{
    ParamSetView_ad1660* view = reinterpret_cast<ParamSetView_ad1660*>(this);
    uint32_t id = 0;
    if (view->mParams.mnCount) {
        id = Fn0040d500(view->mParams.mpHeader)->mKey + 1;
    }
    SetParameter(id, a);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092a112 score 25
void cGZCommandParameterSet::SetParameterCount(uint32_t a)
{
    ParamSetView_ad1660* view = reinterpret_cast<ParamSetView_ad1660*>(this);
    while (view->mParams.mnCount < a) {
        AppendParameter(&const_cast<Variant_ad1660&>(static_cast<const Variant_ad1660&>(Variant_ad1660())));
    }
    if (view->mParams.mnCount > a) {
        ParamTree_ad1660* tree = &view->mParams;
        do {
            tree->Erase_929cad(Iter_ad1660(Fn0040d500(tree->mpHeader)));
        } while (tree->mnCount > a);
    }
}
#endif

// FUNCTION: 0x0092aa4a
uint32_t cGZCommandServer::Slot13_ad1660(uint32_t a, uint32_t b)
{
    const char* text = OB_PTR(const char, a);
    if (text) {
        if (b == 0xffffffff) {
            b = strlen(text);
        }
        cRZString token[1];
        int32_t found = 1;
        if (Fn00910bd3(text, b, 0x20, token, &found) && found) {
            return reinterpret_cast<SrvIf_ad1660*>(this)->GetCommandID(token);
        }
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092a236 score 10
bool cGZCommandServer::Slot16_ad1660(uint32_t a)
{
    GenHold_ad1660 hold(OB_PTR(void, a));
    SetTree_ad1660* tree = &reinterpret_cast<ServerView_ad1660*>(this)->mGenerators;
    RbNode_ad1660* node = tree->Find_98129c(&hold.mp);
    if (node != tree->mpHeader) {
        tree->Erase_929cea(Iter_ad1660(node));
    }
    return true;
}
#endif

// FUNCTION: 0x0092a982
bool cGZCommandServer::Slot03_ae1d24()
{
    ServerView_ad1660* view = reinterpret_cast<ServerView_ad1660*>(this);
    SrvIf_ad1660* srv = reinterpret_cast<SrvIf_ad1660*>(this);
    if (!srv->GetCommandDispatcher()) {
        reinterpret_cast<RefA_ad1660*>(&view->mpDefaultDispatcher)->Set(new DispObj_ad1660);
        reinterpret_cast<Disp_ad1660*>(view->mpDefaultDispatcher)->Init();
        srv->SetCommandDispatcher(view->mpDefaultDispatcher);
    }
    reinterpret_cast<RefA_ad1660*>(&view->mpGenerator)->Set(new GenObj_ad1660);
    reinterpret_cast<Gen_ad1660*>(view->mpGenerator)->Init();
    srv->RegisterCommandGenerator(view->mpGenerator);
    return true;
}

// FUNCTION: 0x0092ae88
bool cGZCommandServer::Slot04_ae1d24()
{
    ServerView_ad1660* view = reinterpret_cast<ServerView_ad1660*>(this);
    view->mCommands.Clear_92ace7();
    reinterpret_cast<SrvIf_ad1660*>(this)->SetCommandDispatcher(0);
    Disp_ad1660* disp = reinterpret_cast<Disp_ad1660*>(view->mpDefaultDispatcher);
    if (disp) {
        disp->Shutdown();
        reinterpret_cast<RefA_ad1660*>(&view->mpDefaultDispatcher)->Set(0);
    }
    Gen_ad1660* gen = reinterpret_cast<Gen_ad1660*>(view->mpGenerator);
    if (gen) {
        gen->Shutdown();
        reinterpret_cast<RefA_ad1660*>(&view->mpGenerator)->Set(0);
    }
    SetTree_ad1660* tree = &view->mGenerators;
    RbNode_ad1660* header = tree->mpHeader;
    RbNode_ad1660* it = header->mpLeft;
    while (it != header) {
        it = Fn0040d4c0(it);
    }
    tree->Clear_929f3e();
    return true;
}

// FUNCTION: 0x0092a9f8
void cGZCommandServer::Slot05_ad1660(uint32_t a)
{
    cGZCommandParameterSet* set = reinterpret_cast<cGZCommandParameterSet*>(new ParamSetObj_ad1660);
    *OB_PTR(cGZCommandParameterSet*, a) = set;
    set->AddRef();
}

// FUNCTION: 0x0092aad8
void cGZCommandServer::Slot14_ad1660(uint32_t a)
{
    ServerView_ad1660* view = reinterpret_cast<ServerView_ad1660*>(this);
    RbNode_ad1660* header = view->mCommands.mpHeader;
    RbNode_ad1660* it = header->mpLeft;
    while (it != header) {
        uint32_t id = it->mKey;
        OB_PTR(Vec_ad1660, a)->PushBack_92a562(&id);
        it = Fn0040d4c0(it);
    }
}

// FUNCTION: 0x0092ab0b
bool cGZCommandServer::Slot15_ad1660(uint32_t a)
{
    ServerView_ad1660* view = reinterpret_cast<ServerView_ad1660*>(this);
    GenHold_ad1660 hold(OB_PTR(void, a));
    SetTree_ad1660* tree = &view->mGenerators;
    if (tree->Find_98129c(&hold.mp) == tree->mpHeader) {
        InsertResult_ad1660 result;
        tree->Insert_92a53f(&result, reinterpret_cast<const SetVal_ad1660*>(&hold.mp));
        if (view->mCommands.mnCount) {
            view->Notify_929e54(0, true, OB_PTR(void, a));
        }
    }
    return true;
}

// FUNCTION: 0x0092a53f
void SetTree_ad1660::Insert_92a53f(InsertResult_ad1660* out, const SetVal_ad1660* value)
{
    InsertResult_ad1660 result;
    InsertUnique_92a476(&result, value);
    out->mpNode = result.mpNode;
    out->mbInserted = result.mbInserted;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092ad10 score 2
bool cGZCommandServer::Slot08_ad1660(uint32_t a, uint32_t b)
{
    ServerView_ad1660* view = reinterpret_cast<ServerView_ad1660*>(this);
    CmdNode_ad1660* node = static_cast<CmdNode_ad1660*>(view->mCommands.Find_98129c(&a));
    if (node != view->mCommands.mpHeader) {
        const char* text = OB_PTR(const char, b);
        if (text && *text) {
            node->mValue.mDesc = cRZString(text);
        } else if (view->mbFlag) {
            static_cast<cIGZString&>(node->mValue.mDesc).Sprintf("Format: %s\nOutput: <none>", node->mValue.mName.c_str());
        }
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092ad88 score 8
bool cGZCommandServer::Slot09_ad1660(uint32_t a)
{
    ServerView_ad1660* view = reinterpret_cast<ServerView_ad1660*>(this);
    CmdNode_ad1660* node = static_cast<CmdNode_ad1660*>(view->mCommands.Find_98129c(&a));
    if (node != view->mCommands.mpHeader) {
        view->Notify_929e54(&node->mValue, false, 0);
        view->mCommands.Erase_92ac39(Iter_ad1660(node));
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092b075 score 26
bool cGZCommandServer::Slot06_ad1660(uint32_t a, uint32_t b, uint32_t c)
{
    ServerView_ad1660* view = reinterpret_cast<ServerView_ad1660*>(this);
    if (a && b) {
        CmdTree_ad1660* tree = &view->mCommands;
        if (tree->Find_98129c(&a) == tree->mpHeader) {
            CmdPair_ad1660 pair(a, CmdValue_ad1660());
            InsertResult_ad1660 result;
            tree->InsertUnique_92aff1(&result, &pair);
            CmdValue_ad1660* value = &static_cast<CmdNode_ad1660*>(result.mpNode)->mValue;
            value->mId = a;
            value->mName = cRZString(OB_PTR(const char, b));
            reinterpret_cast<SrvIf_ad1660*>(this)->RegisterCommandParameterInfo(a, OB_PTR(const char, c));
            view->Notify_929e54(value, true, 0);
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092a5ed score 33
bool cGZCommandParameterSet::CompareParameterString(uint32_t a, const char* b, bool c)
{
    if (a == 0xfffffffe) {
        RbNode_ad1660* header = reinterpret_cast<RbNode_ad1660*>(mpParamHeader);
        RbNode_ad1660* it = header->mpLeft;
        while (it != header) {
            if (CompareParameterString(it->mKey, b, c)) {
                return true;
            }
            it = Fn0040d4c0(it);
        }
        return false;
    }
    VarIf_ad1660* value = reinterpret_cast<VarIf_ad1660*>(GetParameter(a));
    if (value) {
        cRZString text;
        if (value->ToString(&text)) {
            return text.Find(b, 0, c) != -1 && text.size() == strlen(b);
        }
    }
    return false;
}
#endif

// FUNCTION: 0x0092a810
bool cGZStringCommandGenerator::ConvertCommandOutputToString(void* a, void* b)
{
    cRZString text;
    cIGZString* out = reinterpret_cast<cIGZString*>(b);
    out->Resize(0);
    cGZCommandParameterSet* params = reinterpret_cast<cGZCommandParameterSet*>(a);
    uint32_t first = params->GetFirstParameterID();
    uint32_t id = first;
    while (id != 0xffffffff) {
        reinterpret_cast<VarIf_ad1660*>(params->Slot05_ad16c8(id))->ToString(&text);
        ConvertStringToArgumentString(&text, &text);
        if (id != first) {
            out->Append(" ", 1);
        }
        out->Append(text);
        id = params->GetNextParameterID(id);
    }
    return true;
}

// FUNCTION: 0x0092a720
bool cGZStringCommandGenerator::ConvertCommandToString(uint32_t a, void* b, void* c)
{
    cIGZString* out = reinterpret_cast<cIGZString*>(c);
    out->Erase(0, 0xffffffff);
    if (mpObjA) {
        cRZString text;
        if (reinterpret_cast<SrvIf_ad1660*>(mpObjA)->GetCommandInfo(a, &text, 0)) {
            ConvertStringToArgumentString(&text, &text);
            out->Append(text);
            cGZCommandParameterSet* params = reinterpret_cast<cGZCommandParameterSet*>(b);
            if (params) {
                uint32_t id = params->GetFirstParameterID();
                while (id != 0xffffffff) {
                    reinterpret_cast<VarIf_ad1660*>(params->Slot05_ad16c8(id))->ToString(&text);
                    ConvertStringToArgumentString(&text, &text);
                    out->Append(" ", 1);
                    out->Append(text);
                    id = params->GetNextParameterID(id);
                }
            }
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x0092994d
bool cGZStringCommandGenerator::Init()
{
    RefB_ad1660* ref = reinterpret_cast<RefB_ad1660*>(&mpObjA);
    if (ref->mp == 0) {
        SrvHold_ad1660 hold;
        ref->Set(hold.mp);
    }
    return true;
}

// FUNCTION: 0x00929bff
Alloc_ad1660* Fn00929bff()
{
    if (gpB629e8_ad1660 == 0) {
        AllocHold_ad1660 hold;
        gpB629e8_ad1660 = reinterpret_cast<Alloc_ad1660*>(hold.mp);
    }
    return gpB629e8_ad1660;
}

// FUNCTION: 0x00929f67
void* OB_STDCALL Fn00929f67(uint32_t count)
{
    return Fn00929bff()->Alloc(count * 4);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092a2a6 score 26
void Vec_ad1660::InsertOverflow_92a2a6(uint32_t* position, const uint32_t* value, const void* tag, uint32_t count, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpFinish - mpStart);
    uint32_t grow = oldSize < count ? count : oldSize;
    uint32_t newSize = grow + oldSize;
    uint32_t** pEnd = &mpEnd;
    uint32_t* newStart = static_cast<uint32_t*>(Fn00929f67(newSize));
    uint32_t* cur = static_cast<uint32_t*>(Fn00407a50(mpStart, position, newStart));
    cur = Fn004186f0(cur, count, value);
    if (!atEnd) {
        cur = static_cast<uint32_t*>(Fn00407a50(position, mpFinish, cur));
    }
    Fn00929bff()->Free(mpStart);
    mpFinish = cur;
    mpStart = newStart;
    *pEnd = newStart + newSize;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092a562 score 16
void Vec_ad1660::PushBack_92a562(const uint32_t* value)
{
    if (mpFinish != mpEnd) {
        if (mpFinish) {
            *mpFinish = *value;
        }
        ++mpFinish;
    } else {
        InsertOverflow_92a2a6(mpFinish, value, value, 1, true);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092ab69 score 9
Variant_ad1660* ParamTree_ad1660::Index_92ab69(const uint32_t* key)
{
    RbNode_ad1660* node = LowerBound_9492cb(key);
    if (node == mpHeader || *key < node->mKey) {
        Variant_ad1660 defaultValue;
        ParamPair_ad1660 pair(*key, defaultValue);
        RbNode_ad1660* inserted;
        InsertHint_92a593(&inserted, node, &pair);
        node = inserted;
    }
    return &static_cast<ParamNode_ad1660*>(node)->mValue;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092abeb score 4
void cGZCommandParameterSet::SetParameter(uint32_t a, void* b)
{
    ParamSetView_ad1660* view = reinterpret_cast<ParamSetView_ad1660*>(this);
    *view->mParams.Index_92ab69(&a) = *reinterpret_cast<const Variant_ad1660*>(b);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092a593 score 5
RbNode_ad1660** ParamTree_ad1660::InsertHint_92a593(RbNode_ad1660** out, RbNode_ad1660* position, const ParamPair_ad1660* v)
{
    InsertHint_92a337(out, Iter_ad1660(position), v);
    return out;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092a337 score 126
RbNode_ad1660** ParamTree_ad1660::InsertHint_92a337(RbNode_ad1660** out, Iter_ad1660 position, const ParamPair_ad1660* v)
{
    RbNode_ad1660* pos = position.mpNode;
    RbNode_ad1660* header = mpHeader;
    InsertResult_ad1660 unique;
    if (pos == header->mpLeft) {
        if (mnCount > 0 && v->mFirst < pos->mKey) {
            return Insert_929f7e(out, pos, pos, v, 0);
        }
    } else if (pos == header) {
        RbNode_ad1660* last = header->mpRight;
        if (last->mKey < v->mFirst) {
            return Insert_929f7e(out, 0, last, v, 0);
        }
    } else {
        RbNode_ad1660* before = Fn0040d500(pos);
        if (before->mKey < v->mFirst && v->mFirst < pos->mKey) {
            if (before->mpRight == 0) {
                return Insert_929f7e(out, 0, before, v, 0);
            }
            return Insert_929f7e(out, pos, pos, v, 0);
        }
    }
    InsertUnique_92a006(&unique, v);
    *out = unique.mpNode;
    return out;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0092b139 score 133
bool cGZStringCommandGenerator::ConvertStringToCommand(const char* a, uint32_t b, void* c, void* d)
{
    if (mpObjA == 0) {
        return false;
    }
    if (b == 0xffffffff) {
        b = strlen(a);
    }
    StrVec_ad1660* tokens = reinterpret_cast<StrVec_ad1660*>(&mpVecBegin);
    uint32_t count = 1;
    tokens->Resize_5c87a0(count);
    while (static_cast<uint32_t>(tokens->mpFinish - tokens->mpStart) < 0x200) {
        count = static_cast<uint32_t>(tokens->mpFinish - tokens->mpStart);
        bool done = Fn00910bd3(a, b, 0x20, tokens->mpStart, reinterpret_cast<int32_t*>(&count));
        tokens->Resize_5c87a0(static_cast<uint32_t>(tokens->mpFinish - tokens->mpStart) * 2);
        if (done) {
            break;
        }
    }
    if (count < 1) {
        return false;
    }
    uint32_t id = reinterpret_cast<SrvIf_ad1660*>(mpObjA)->GetCommandID(tokens->mpStart);
    *reinterpret_cast<uint32_t*>(c) = id;
    if (id == 0) {
        return false;
    }
    cGZCommandParameterSet* params = reinterpret_cast<cGZCommandParameterSet*>(new ParamSetObj_ad1660);
    *reinterpret_cast<cGZCommandParameterSet**>(d) = params;
    params->AddRef();
    for (uint32_t i = 1; i < count; ++i) {
        Variant_ad1660 value(tokens->mpStart[i]);
        params->SetParameter(i - 1, &value);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009297b0 score 10
bool cUnk00ad1638::Slot00_ad1590(uint32_t a, uint32_t b)
{
    if (a == 0x4b99446a || a == 0x0b903cc5) {
        *OB_PTR(cUnk00ad1638*, b) = this;
        Slot01_ad1590();
        return true;
    }
    return cRZMessage2Standard::Slot00_ad1590(a, b);
}
#endif
