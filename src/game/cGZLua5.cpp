#include <cstddef>
#include <cstring>

#include "classes/cGZLua5.h"

// The embedded Lua 5.0 interpreter's state is only ever handled through pointers here.
struct lua_State;
typedef int (*lua_CFunction_ac9144)(lua_State*);

struct luaL_reg_ac9144 {
    const char* name;
    lua_CFunction_ac9144 func;
};

// Helpers the original keeps out of line (their callers call them): the 2003 compiler would inline them here.
#ifdef _MSC_VER
#define NOINLINE_ac9144 __declspec(noinline)
#else
#define NOINLINE_ac9144
#endif

// Pointers the interface passes (or stores) as 32-bit values (the base classes still declare uint32_t) go through
// OB_PTR / OB_ADDR (common/compiler.h): macros, because an inline helper is evaluated before the other arguments.

// The x87 precision control word: 0x892a0a reads which precision is set (0 = none of the Lua-friendly ones), 0x8929e0
// sets one (1 = double).
// STUB: 0x00892a0a
uint32_t Fn00892a0a();
// STUB: 0x008929e0
void Fn008929e0(uint32_t precision);

// Every call into Lua runs with double precision: when the precision is not set, set it for the call and put it back.
struct FpuScope_ac9144 {
    uint32_t mPrevious;
    bool mbSet;
    FpuScope_ac9144() : mPrevious(Fn00892a0a()), mbSet(mPrevious == 0)
    {
        if (mbSet) {
            Fn008929e0(1);
        }
    }
    ~FpuScope_ac9144()
    {
        if (mbSet) {
            Fn008929e0(mPrevious);
        }
    }
};

// The Lua 5.0 API (the cdecl functions of the statically linked interpreter).
// STUB: 0x008bc0f0
int lua_yield(lua_State* L, int nresults);
// STUB: 0x008ba6d0
int lua_gettop(lua_State* L);
// STUB: 0x008ba6e0
void lua_settop(lua_State* L, int index);
// STUB: 0x008ba850
void lua_pushvalue(lua_State* L, int index);
// STUB: 0x008ba740
void lua_remove(lua_State* L, int index);
// STUB: 0x008ba7a0
void lua_insert(lua_State* L, int index);
// STUB: 0x008ba800
void lua_replace(lua_State* L, int index);
// STUB: 0x008ba630
void lua_xmove(lua_State* from, lua_State* to, int n);
// STUB: 0x008ba5d0
int lua_checkstack(lua_State* L, int size);
// STUB: 0x008ba890
int lua_type(lua_State* L, int index);
// STUB: 0x008ba8c0
const char* lua_typename(lua_State* L, int type);
// STUB: 0x008ba920
int lua_isnumber(lua_State* L, int index);
// STUB: 0x008ba970
int lua_isstring(lua_State* L, int index);
// STUB: 0x008ba8e0
int lua_iscfunction(lua_State* L, int index);
// STUB: 0x008ba9b0
int lua_isuserdata(lua_State* L, int index);
// STUB: 0x008baa60
int lua_equal(lua_State* L, int index1, int index2);
// STUB: 0x008ba9f0
int lua_rawequal(lua_State* L, int index1, int index2);
// STUB: 0x008baae0
int lua_lessthan(lua_State* L, int index1, int index2);
// STUB: 0x008bab50
double lua_tonumber(lua_State* L, int index);
// STUB: 0x008baba0
int lua_toboolean(lua_State* L, int index);
// STUB: 0x008babe0
const char* lua_tostring(lua_State* L, int index);
// STUB: 0x008bac50
size_t lua_strlen(lua_State* L, int index);
// STUB: 0x008bacb0
void* lua_tocfunction(lua_State* L, int index);  // returns a lua_CFunction (a function-pointer return type has no stub spelling)
// STUB: 0x008bacf0
void* lua_touserdata(lua_State* L, int index);
// STUB: 0x008bad30
lua_State* lua_tothread(lua_State* L, int index);
// STUB: 0x008badd0
void lua_pushnil(lua_State* L);
// STUB: 0x008badf0
void lua_pushnumber(lua_State* L, double n);
// STUB: 0x008bae10
void lua_pushlstring(lua_State* L, const char* s, size_t len);
// STUB: 0x008bae60
void lua_pushstring(lua_State* L, const char* s);
// STUB: 0x008baf30
void lua_pushcclosure(lua_State* L, lua_CFunction_ac9144 fn, int n);
// STUB: 0x008bafc0
void lua_pushboolean(lua_State* L, int b);
// STUB: 0x008baff0
void lua_pushlightuserdata(lua_State* L, void* p);
// STUB: 0x008bb670
void* lua_newuserdata(lua_State* L, size_t size);
// STUB: 0x008bb010
void lua_gettable(lua_State* L, int index);
// STUB: 0x008bb060
void lua_rawget(lua_State* L, int index);
// STUB: 0x008bb0b0
void lua_rawgeti(lua_State* L, int index, int n);
// STUB: 0x008bb100
void lua_newtable(lua_State* L);
// STUB: 0x008bb1b0
void lua_getfenv(lua_State* L, int index);
// STUB: 0x008bb140
int lua_getmetatable(lua_State* L, int index);
// STUB: 0x008bb200
void lua_settable(lua_State* L, int index);
// STUB: 0x008bb240
void lua_rawset(lua_State* L, int index);
// STUB: 0x008bb2a0
void lua_rawseti(lua_State* L, int index, int n);
// STUB: 0x008bb370
int lua_setfenv(lua_State* L, int index);
// STUB: 0x008bb300
int lua_setmetatable(lua_State* L, int index);
// STUB: 0x008bb3e0
void lua_call(lua_State* L, int nargs, int nresults);
// STUB: 0x008be580
int lua_dofile(lua_State* L, const char* filename);
// STUB: 0x008be620
int lua_dostring(lua_State* L, const char* str);
// STUB: 0x008be5c0
int lua_dobuffer(lua_State* L, const char* buff, size_t size, const char* name);
// STUB: 0x008bb490
int lua_load(lua_State* L, void* reader, void* data, const char* chunkname);
// STUB: 0x008bb590
int lua_error(lua_State* L);
// STUB: 0x008bb5a0
int lua_next(lua_State* L, int index);
// STUB: 0x008bb5f0
void lua_concat(lua_State* L, int n);
// STUB: 0x008be160
int luaL_ref(lua_State* L, int t);
// STUB: 0x008be230
void luaL_unref(lua_State* L, int t, int ref);
// STUB: 0x008bb540
int lua_getgccount(lua_State* L);
// STUB: 0x008bb530
int lua_getgcthreshold(lua_State* L);
// STUB: 0x008bb550
void lua_setgcthreshold(lua_State* L, int newthreshold);
// STUB: 0x008bdbd0
void luaL_openlib(lua_State* L, const char* libname, const luaL_reg_ac9144* l, int nup);

// Lua 5.0's state: the global state sits at +0x10, and its main thread (whose user data word, the 4 bytes before the
// state, holds the thread object of the interface) at +0x50 of that.
struct LuaGlobal_ac9144 {
    uint8_t unknown0[0x50];
    lua_State* mpMainThread;
};
struct LuaCallInfo_ac9144 {
    void* mpBase;
};
struct LuaState_ac9144 {
    uint8_t unknown0[8];
    void* mpTop;
    void* mpBase;
    LuaGlobal_ac9144* mpGlobal;
    LuaCallInfo_ac9144* mpCI;
    uint8_t unknown18[4];
    void* mpStack;
    uint8_t unknown20[8];
    LuaCallInfo_ac9144* mpBaseCI;
    uint16_t mnSizeCI;
    uint16_t mnCalls;
    uint8_t unknown30[0x2c];
    int32_t mnErrFunc;
};

// The library tables of the interpreter's own libraries (name, function) as 0x8bfaa0 and 0x8c2470 register them.
// GLOBAL: 0x00aca890
extern luaL_reg_ac9144 gAca890[];
// GLOBAL: 0x00acac70
extern luaL_reg_ac9144 gAcac70[];

// The default error reporter the interface installs.
// STUB: 0x008b9360
void Fn008b9360(void* thread, int32_t status, const char* message);

// The vector of child states a thread record carries (an STLport vector of lua_State pointers).
struct ThreadVector_ac9144 {
    lua_State** mpBegin;
    lua_State** mpEnd;
    lua_State** mpCapacity;
    // Assigns the other vector to this one.
    // STUB: 0x0072bd50
    void Fn0072bd50(const ThreadVector_ac9144& other);
    // Appends a state.
    // STUB: 0x007ebd30
    void Fn007ebd30(lua_State* const& state);
    // Builds this vector as a copy of the other.
    // STUB: 0x004b03e0
    void Fn004b03e0(const ThreadVector_ac9144& other);
};

// What the registry knows about a thread: its state, the state it was started from, its child states, the flags it
// was created with (0x10 = child of the creating thread) and the class id of its thread object.
struct ThreadRecord_ac9144 {
    lua_State* mpThread;
    lua_State* mpParent;
    ThreadVector_ac9144 mVector;
    uint32_t mnFlags;
    int32_t mnClassID;
};

// A hash node of the thread registry: the thread id is the key.
struct ThreadNode_ac9144 {
    ThreadNode_ac9144* mpNext;
    int32_t mnID;
    ThreadRecord_ac9144 mRecord;
};

// The map's value type: key and record.
struct ThreadPair_ac9144 {
    int32_t mnID;
    ThreadRecord_ac9144 mRecord;
};

// An STLport iterator over the registry's nodes.
struct cThreadRegistry_ac9144;
struct ThreadIterator_ac9144 {
    ThreadNode_ac9144* mpNode;
    cThreadRegistry_ac9144* mpTable;
};

// The class factory of the game (cIGZCOM): slot 3 creates an object of a class and asks it for an interface.
struct GZCOM_ac9144 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual bool Fn03(uint32_t classID, uint32_t iid, void** out);
};
// STUB: 0x0090ddf1
GZCOM_ac9144* Fn0090ddf1();
// STUB: 0x008ba690
lua_State* lua_newthread(lua_State* L);

// The registry of the Lua threads (a hash map from the thread id to its record) that sits at +0x20 of the interface.
struct BucketVector_ac9144 {
    ThreadNode_ac9144** mpBegin;
    ThreadNode_ac9144** mpEnd;
    ThreadNode_ac9144** mpCapacity;
    uint32_t size() const { return static_cast<uint32_t>(mpEnd - mpBegin); }
    ThreadNode_ac9144* operator[](uint32_t n) const { return mpBegin[n]; }
};

struct cThreadRegistry_ac9144 {
    uint32_t mHashPad;
    BucketVector_ac9144 mBuckets;
    uint32_t mnCount;
    cUnk00ac8d7c* mpOwner;
    int32_t mnNextID;

    lua_State* Fn008bc700(uint32_t id);
    int32_t Fn008bc540(uint32_t id);
    // The map's operator[]: the record of the key, added (default constructed) when missing.
    // STUB: 0x008bcb40
    ThreadRecord_ac9144* Fn008bcb40(const int32_t* key);
    // The map's find: an iterator at the key's node, or at the end (a null node).
    // STUB: 0x006f1530
    ThreadIterator_ac9144 Fn006f1530(const int32_t* key);
    // The map's insert of a new pair: the pair as stored.
    // STUB: 0x008bcaf0
    ThreadPair_ac9144* Fn008bcaf0(const ThreadPair_ac9144* pair);
    // The body of the destroy-thread method continues elsewhere in the original.
    // STUB: 0x008bcee0
    bool Fn008bcee0(lua_State* L, int32_t id);
    // The registry is set up for an interface: the first state's thread object is created and registered.
    // STUB: 0x008bcc50
    bool Fn008bcc50(cUnk00ac8d7c* owner, lua_State* L);
    // Creates a thread of the given kind (flags, class id) in the state and registers it: its id, or -1.
    // STUB: 0x008bcd50
    int32_t Fn008bcd50(lua_State* L, uint32_t flags, uint32_t classID);
    // Resumes the thread registered under the id with the given number of arguments: 0 or an error code.
    // STUB: 0x008bd040
    int32_t Fn008bd040(lua_State* L, int32_t id, int32_t nargs);
    // Destroys every registered thread and lets go of the owner.
    // STUB: 0x008bd630
    bool Fn008bd630();
};

// The registry of the main thread's interface object.
// STUB: 0x008bc500
NOINLINE_ac9144 cThreadRegistry_ac9144* Fn008bc500(lua_State* L);

// FUNCTION: 0x00880a40
uint32_t cGZLua5::Slot03_ac8d7c()
{
    cUnk00ac8bf8* thread = this;
    return OB_ADDR(thread);
}

// FUNCTION: 0x008b83e0
void cGZLua5::Slot85_ac8bf8(uint32_t ref)
{
    luaL_unref(OB_PTR(lua_State, field8), -10000, static_cast<int>(ref));
}

// FUNCTION: 0x008b96d0
void cGZLua5::Slot13_ac8d7c(uint32_t reporter, uint32_t useDefault)
{
    mpErrorReporter = OB_PTR(void, reporter);
    if (reporter == 0) {
        if (*reinterpret_cast<bool*>(&useDefault)) {
            mpErrorReporter = reinterpret_cast<void*>(&Fn008b9360);
        }
    }
}

// FUNCTION: 0x008bfaa0
uint32_t Fn008bfaa0(lua_State* L)
{
    luaL_openlib(L, "table", gAca890, 0);
    return 1;
}

// FUNCTION: 0x008c2470
uint32_t Fn008c2470(lua_State* L)
{
    luaL_openlib(L, "string", gAcac70, 0);
    return 1;
}

// FUNCTION: 0x008bc700
lua_State* cThreadRegistry_ac9144::Fn008bc700(uint32_t id)
{
    ThreadNode_ac9144* node = mBuckets[id % mBuckets.size()];
    while (node && static_cast<uint32_t>(node->mnID) != id) {
        node = node->mpNext;
    }
    ThreadNode_ac9144* found = node;
    if (found) {
        return found->mRecord.mpThread;
    }
    return 0;
}

// FUNCTION: 0x008b6df0
uint32_t cGZLua5::Slot14_ac8bf8()
{
    FpuScope_ac9144 scope;
    return lua_gettop(OB_PTR(lua_State, field8));
}

// FUNCTION: 0x008b78d0
void cGZLua5::Slot48_ac8bf8()
{
    FpuScope_ac9144 scope;
    lua_pushnil(OB_PTR(lua_State, field8));
}

// FUNCTION: 0x008b7c30
void cGZLua5::Slot56_ac8bf8()
{
    FpuScope_ac9144 scope;
    lua_newtable(OB_PTR(lua_State, field8));
}

// FUNCTION: 0x008b8240
uint32_t cGZLua5::Slot82_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return -10001 - index;
}

// FUNCTION: 0x008b80f0
void cGZLua5::Slot78_ac8bf8(uint32_t /*message*/)
{
    FpuScope_ac9144 scope;
    lua_error(OB_PTR(lua_State, field8));
}

// FUNCTION: 0x008b7d10
void cGZLua5::Slot62_ac8bf8()
{
    FpuScope_ac9144 scope;
    lua_pushvalue(OB_PTR(lua_State, field8), -10000);
}

// FUNCTION: 0x008b7d60
void cGZLua5::Slot63_ac8bf8()
{
    FpuScope_ac9144 scope;
    lua_pushvalue(OB_PTR(lua_State, field8), -10001);
}

// FUNCTION: 0x008b6c30
void cGZLua5::Slot09_ac8bf8(uint32_t nresults)
{
    FpuScope_ac9144 scope;
    lua_yield(OB_PTR(lua_State, field8), nresults);
}

// FUNCTION: 0x008b6e30
void cGZLua5::Slot15_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_settop(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b6e80
void cGZLua5::Slot16_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_pushvalue(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b6ed0
void cGZLua5::Slot17_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_remove(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b6f20
void cGZLua5::Slot18_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_insert(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b6f70
void cGZLua5::Slot19_ac8bf8(uint32_t count)
{
    FpuScope_ac9144 scope;
    lua_settop(OB_PTR(lua_State, field8), -1 - static_cast<int>(count));
}

// FUNCTION: 0x008b6fc0
void cGZLua5::Slot20_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_replace(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b7010
void cGZLua5::Slot21_ac8bf8(uint32_t to, uint32_t count)
{
    FpuScope_ac9144 scope;
    lua_xmove(OB_PTR(lua_State, field8), OB_PTR(lua_State, to), count);
}

// FUNCTION: 0x008b7060
bool cGZLua5::Slot22_ac8bf8(uint32_t size)
{
    FpuScope_ac9144 scope;
    return lua_checkstack(OB_PTR(lua_State, field8), size) != 0;
}

// FUNCTION: 0x008b70b0
uint32_t cGZLua5::Slot23_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_type(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b7100
uint32_t cGZLua5::Slot24_ac8bf8(uint32_t type)
{
    FpuScope_ac9144 scope;
    return OB_ADDR(lua_typename(OB_PTR(lua_State, field8), type));
}

// FUNCTION: 0x008b7150
bool cGZLua5::Slot25_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_isnumber(OB_PTR(lua_State, field8), index) != 0;
}

// FUNCTION: 0x008b71a0
bool cGZLua5::Slot26_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_isstring(OB_PTR(lua_State, field8), index) != 0;
}

// FUNCTION: 0x008b71f0
bool cGZLua5::Slot27_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_iscfunction(OB_PTR(lua_State, field8), index) != 0;
}

// FUNCTION: 0x008b7240
bool cGZLua5::Slot28_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_type(OB_PTR(lua_State, field8), index) == 6;
}

// FUNCTION: 0x008b72a0
bool cGZLua5::Slot29_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_type(OB_PTR(lua_State, field8), index) == 5;
}

// FUNCTION: 0x008b7300
bool cGZLua5::Slot30_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_isuserdata(OB_PTR(lua_State, field8), index) != 0;
}

// FUNCTION: 0x008b7350
bool cGZLua5::Slot31_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_type(OB_PTR(lua_State, field8), index) == 2;
}

// FUNCTION: 0x008b73b0
bool cGZLua5::Slot32_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_type(OB_PTR(lua_State, field8), index) == 1;
}

// FUNCTION: 0x008b7410
bool cGZLua5::Slot33_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_type(OB_PTR(lua_State, field8), index) == 0;
}

// FUNCTION: 0x008b7470
bool cGZLua5::Slot34_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_type(OB_PTR(lua_State, field8), index) == -1;
}

// FUNCTION: 0x008b74d0
bool cGZLua5::Slot35_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_type(OB_PTR(lua_State, field8), index) <= 0;
}

// FUNCTION: 0x008b7520
bool cGZLua5::Slot36_ac8bf8(uint32_t index1, uint32_t index2)
{
    FpuScope_ac9144 scope;
    return lua_equal(OB_PTR(lua_State, field8), index1, index2) != 0;
}

// FUNCTION: 0x008b7580
bool cGZLua5::Slot37_ac8bf8(uint32_t index1, uint32_t index2)
{
    FpuScope_ac9144 scope;
    return lua_rawequal(OB_PTR(lua_State, field8), index1, index2) != 0;
}

// FUNCTION: 0x008b75e0
bool cGZLua5::Slot38_ac8bf8(uint32_t index1, uint32_t index2)
{
    FpuScope_ac9144 scope;
    return lua_lessthan(OB_PTR(lua_State, field8), index1, index2) != 0;
}

// FUNCTION: 0x008b7640
uint32_t cGZLua5::Slot39_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return static_cast<uint32_t>(lua_tonumber(OB_PTR(lua_State, field8), index));
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b7690 score 13
float cGZLua5::Slot41_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return static_cast<float>(lua_tonumber(OB_PTR(lua_State, field8), index));
}
#endif

// FUNCTION: 0x008b76f0
bool cGZLua5::Slot42_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_toboolean(OB_PTR(lua_State, field8), index) != 0;
}

// FUNCTION: 0x008b7740
uint32_t cGZLua5::Slot43_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return OB_ADDR(lua_tostring(OB_PTR(lua_State, field8), index));
}

// FUNCTION: 0x008b7790
uint32_t cGZLua5::Slot44_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_strlen(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b77e0
uint32_t cGZLua5::Slot45_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return OB_ADDR(lua_tocfunction(OB_PTR(lua_State, field8), index));
}

// FUNCTION: 0x008b7830
uint32_t cGZLua5::Slot46_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return OB_ADDR(lua_touserdata(OB_PTR(lua_State, field8), index));
}

// FUNCTION: 0x008b7880
uint32_t cGZLua5::Slot47_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return OB_ADDR(lua_tothread(OB_PTR(lua_State, field8), index));
}

// FUNCTION: 0x008b7910
void cGZLua5::Slot49_ac8bf8(uint32_t numberLow, uint32_t /*numberHigh*/)
{
    FpuScope_ac9144 scope;
    double number = *reinterpret_cast<double*>(&numberLow);
    lua_pushnumber(OB_PTR(lua_State, field8), number);
}

// FUNCTION: 0x008b7960
void cGZLua5::Slot50_ac8bf8(uint32_t string, uint32_t length)
{
    FpuScope_ac9144 scope;
    lua_pushlstring(OB_PTR(lua_State, field8), OB_PTR(const char, string), length);
}

// FUNCTION: 0x008b79b0
void cGZLua5::Slot51_ac8bf8(uint32_t string)
{
    FpuScope_ac9144 scope;
    lua_pushstring(OB_PTR(lua_State, field8), OB_PTR(const char, string));
}

// FUNCTION: 0x008b7a00
void cGZLua5::Slot52_ac8bf8(uint32_t function, uint32_t upvalues)
{
    FpuScope_ac9144 scope;
    lua_pushcclosure(OB_PTR(lua_State, field8), reinterpret_cast<lua_CFunction_ac9144>(OB_PTR(void, function)),
                     upvalues);
}

// FUNCTION: 0x008b7a50
void cGZLua5::Slot53_ac8bf8(uint32_t value)
{
    FpuScope_ac9144 scope;
    lua_pushboolean(OB_PTR(lua_State, field8), *reinterpret_cast<bool*>(&value) != 0);
}

// FUNCTION: 0x008b7aa0
void cGZLua5::Slot54_ac8bf8(uint32_t pointer)
{
    FpuScope_ac9144 scope;
    lua_pushlightuserdata(OB_PTR(lua_State, field8), OB_PTR(void, pointer));
}

// FUNCTION: 0x008b7af0
uint32_t cGZLua5::Slot55_ac8bf8(uint32_t size)
{
    FpuScope_ac9144 scope;
    return OB_ADDR(lua_newuserdata(OB_PTR(lua_State, field8), size));
}

// FUNCTION: 0x008b7b40
void cGZLua5::Slot57_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_gettable(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b7b90
void cGZLua5::Slot58_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_rawget(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b7be0
void cGZLua5::Slot59_ac8bf8(uint32_t index, uint32_t n)
{
    FpuScope_ac9144 scope;
    lua_rawgeti(OB_PTR(lua_State, field8), index, n);
}

// FUNCTION: 0x008b7c70
void cGZLua5::Slot60_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_getfenv(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b7cc0
uint32_t cGZLua5::Slot61_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_getmetatable(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b7db0
void cGZLua5::Slot64_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_settable(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b7e00
void cGZLua5::Slot65_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_rawset(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b7e50
void cGZLua5::Slot66_ac8bf8(uint32_t index, uint32_t n)
{
    FpuScope_ac9144 scope;
    lua_rawseti(OB_PTR(lua_State, field8), index, n);
}

// FUNCTION: 0x008b7ea0
void cGZLua5::Slot67_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_setfenv(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b7ef0
void cGZLua5::Slot68_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    lua_setmetatable(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b7f40
void cGZLua5::Slot69_ac8bf8(uint32_t nargs, uint32_t nresults)
{
    FpuScope_ac9144 scope;
    lua_call(OB_PTR(lua_State, field8), nargs, nresults);
}

// FUNCTION: 0x008b7f90
uint32_t cGZLua5::Slot71_ac8bf8(uint32_t filename)
{
    FpuScope_ac9144 scope;
    return lua_dofile(OB_PTR(lua_State, field8), OB_PTR(const char, filename));
}

// FUNCTION: 0x008b7fe0
uint32_t cGZLua5::Slot72_ac8bf8(uint32_t string)
{
    FpuScope_ac9144 scope;
    return lua_dostring(OB_PTR(lua_State, field8), OB_PTR(const char, string));
}

// FUNCTION: 0x008b8030
uint32_t cGZLua5::Slot73_ac8bf8(uint32_t buffer, uint32_t size, uint32_t name)
{
    FpuScope_ac9144 scope;
    return lua_dobuffer(OB_PTR(lua_State, field8), OB_PTR(const char, buffer), size,
                        OB_PTR(const char, name));
}

// FUNCTION: 0x008b8090
uint32_t cGZLua5::Slot74_ac8bf8(uint32_t reader, uint32_t data, uint32_t name)
{
    FpuScope_ac9144 scope;
    return lua_load(OB_PTR(lua_State, field8), OB_PTR(void, reader), OB_PTR(void, data),
                    OB_PTR(const char, name));
}

// FUNCTION: 0x008b8130
uint32_t cGZLua5::Slot79_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return lua_next(OB_PTR(lua_State, field8), index);
}

// FUNCTION: 0x008b8180
void cGZLua5::Slot80_ac8bf8(uint32_t count)
{
    FpuScope_ac9144 scope;
    lua_concat(OB_PTR(lua_State, field8), count);
}

// The Lua C functions the interface hands to the interpreter, and the debug record lua_getstack fills.
// STUB: 0x008b8d70
int Fn008b8d70(lua_State* L);
// STUB: 0x008bee20
int Fn008bee20(lua_State* L);
// STUB: 0x008be990
int Fn008be990(lua_State* L);
// STUB: 0x008bec80
int Fn008bec80(lua_State* L);
// STUB: 0x008bef00
int Fn008bef00(lua_State* L);
// STUB: 0x008be930
int Fn008be930(lua_State* L);
// STUB: 0x008befe0
int Fn008befe0(lua_State* L);

struct LuaDebug_ac9144 {
    uint8_t unknown0[0x60];
};

// STUB: 0x008b97e0
int lua_getstack(lua_State* L, int level, LuaDebug_ac9144* ar);
// STUB: 0x008bb420
int lua_pcall(lua_State* L, int nargs, int nresults, int errfunc);

// The thread interface as the tag-cloning slot calls it: slots 91 and 93 each take one argument there.
struct ThreadView_ac9144 {
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
    virtual uint32_t Fn91(uint32_t);
    virtual void Pad92();
    virtual uint32_t Fn93(uint32_t);
};

// Something reference counted: slot 1 adds a reference, slot 2 drops one.
struct Unknown_ac9144 {
    virtual void Pad00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

// FUNCTION: 0x008bee90
void Fn008bee90(lua_State* L, int tag)
{
    FpuScope_ac9144 scope;
    lua_pushcclosure(L, Fn008bee20, 0);
    lua_pushvalue(L, -2);
    lua_pushnumber(L, static_cast<double>(tag));
    lua_pcall(L, 2, 0, 0);
}

// FUNCTION: 0x008bf100
void Fn008bf100(lua_State* L, void* pointer, int tag)
{
    FpuScope_ac9144 scope;
    if (tag == 0) {
        tag = 0;
    }
    lua_newuserdata(L, 4);
    void** data = static_cast<void**>(lua_touserdata(L, -1));
    *data = pointer;
    Fn008bee90(L, tag);
}

// FUNCTION: 0x008bc540
int32_t cThreadRegistry_ac9144::Fn008bc540(uint32_t id)
{
    LuaDebug_ac9144 ar;
    ThreadNode_ac9144* node = mBuckets[id % mBuckets.size()];
    while (node && static_cast<uint32_t>(node->mnID) != id) {
        node = node->mpNext;
    }
    ThreadNode_ac9144* found = node;
    if (found) {
        if (found->mRecord.mnFlags & 0x10000000) {
            return 2;
        }
        if (lua_getstack(found->mRecord.mpThread, 0, &ar) == 0) {
            if (lua_gettop(found->mRecord.mpThread) == 0) {
                return 0;
            }
        }
        return 1;
    }
    return -1;
}

// FUNCTION: 0x008b6c80
bool cGZLua5::Slot11_ac8bf8()
{
    FpuScope_ac9144 scope;
    bool valid;
    lua_State* L = OB_PTR(lua_State, field8);
    if (L != 0 && reinterpret_cast<cUnk00ac8bf8**>(L)[-1] == static_cast<cUnk00ac8bf8*>(this) && field4 != 0xffffffff) {
        valid = true;
    } else {
        valid = false;
    }
    return valid;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b6cf0 score 36
bool cGZLua5::Slot12_ac8bf8()
{
    FpuScope_ac9144 scope;
    bool result;
    if (field8) {
        cThreadRegistry_ac9144* registry = Fn008bc500(OB_PTR(lua_State, field8));
        if (registry && registry->Fn008bcee0(OB_PTR(lua_State, field8), field4)) {
            result = true;
        } else {
            result = false;
        }
        return result;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b6d70 score 6
uint32_t cGZLua5::Slot13_ac8bf8()
{
    FpuScope_ac9144 scope;
    if (field8 && field4 != 0xffffffff) {
        cThreadRegistry_ac9144* registry = Fn008bc500(OB_PTR(lua_State, field8));
        if (registry) {
            return registry->Fn008bc540(field4);
        }
    }
    return -1;
}
#endif

// FUNCTION: 0x008b81d0
void cGZLua5::Slot81_ac8bf8(uint32_t function, uint32_t name)
{
    FpuScope_ac9144 scope;
    lua_pushstring(OB_PTR(lua_State, field8), OB_PTR(const char, name));
    lua_pushcclosure(OB_PTR(lua_State, field8), reinterpret_cast<lua_CFunction_ac9144>(OB_PTR(void, function)), 0);
    lua_settable(OB_PTR(lua_State, field8), -10001);
}

// FUNCTION: 0x008b8280
void cGZLua5::Slot87_ac8bf8(uint32_t name)
{
    FpuScope_ac9144 scope;
    lua_pushstring(OB_PTR(lua_State, field8), OB_PTR(const char, name));
    lua_gettable(OB_PTR(lua_State, field8), -10001);
}

// FUNCTION: 0x008b82e0
void cGZLua5::Slot86_ac8bf8(uint32_t name)
{
    FpuScope_ac9144 scope;
    lua_pushstring(OB_PTR(lua_State, field8), OB_PTR(const char, name));
    lua_insert(OB_PTR(lua_State, field8), -2);
    lua_settable(OB_PTR(lua_State, field8), -10001);
}

// FUNCTION: 0x008b8340
uint32_t cGZLua5::Slot83_ac8bf8()
{
    FpuScope_ac9144 scope;
    return luaL_ref(OB_PTR(lua_State, field8), -10000);
}

// FUNCTION: 0x008b8390
void cGZLua5::Slot84_ac8bf8(uint32_t ref)
{
    FpuScope_ac9144 scope;
    lua_rawgeti(OB_PTR(lua_State, field8), -10000, ref);
}

// FUNCTION: 0x008b8400
uint32_t cGZLua5::Slot88_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    int32_t tag;
    lua_pushvalue(OB_PTR(lua_State, field8), index);
    lua_pushvalue(OB_PTR(lua_State, field8), -1);
    Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008be990)), 0);
    lua_replace(OB_PTR(lua_State, field8), -3);
    if (Slot70_ac8bf8(1, 1, 0, 1) == 0) {
        tag = static_cast<int32_t>(lua_tonumber(OB_PTR(lua_State, field8), -1));
        lua_settop(OB_PTR(lua_State, field8), -2);
        if (tag == 0) {
            tag = -1;
        }
    } else {
        tag = -1;
    }
    return tag;
}

// FUNCTION: 0x008b84b0
void cGZLua5::Slot89_ac8bf8(uint32_t tag, uint32_t name)
{
    FpuScope_ac9144 scope;
    Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008bec80)), 0);
    lua_pushnumber(OB_PTR(lua_State, field8), static_cast<int32_t>(tag));
    lua_pushstring(OB_PTR(lua_State, field8), OB_PTR(const char, name));
    if (Slot70_ac8bf8(2, 1, 0, 1) != 0) {
        lua_pushnil(OB_PTR(lua_State, field8));
    }
}

// FUNCTION: 0x008b8540
void cGZLua5::Slot90_ac8bf8(uint32_t tag, uint32_t name)
{
    FpuScope_ac9144 scope;
    Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008bef00)), 0);
    lua_pushnumber(OB_PTR(lua_State, field8), static_cast<int32_t>(tag));
    lua_pushstring(OB_PTR(lua_State, field8), OB_PTR(const char, name));
    lua_pushvalue(OB_PTR(lua_State, field8), -4);
    Slot70_ac8bf8(3, 0, 0, 1);
    lua_settop(OB_PTR(lua_State, field8), -2);
}

// FUNCTION: 0x008b85e0
uint32_t cGZLua5::Slot91_ac8bf8()
{
    FpuScope_ac9144 scope;
    int32_t tag = -1;
    Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008be930)), 0);
    if (Slot70_ac8bf8(0, 1, 0, 1) == 0) {
        tag = static_cast<int32_t>(lua_tonumber(OB_PTR(lua_State, field8), 1));
        lua_settop(OB_PTR(lua_State, field8), -2);
        if (tag <= 0) {
            tag = -1;
        }
    }
    return tag;
}

// FUNCTION: 0x008b8670
void cGZLua5::Slot92_ac8bf8(uint32_t tag)
{
    FpuScope_ac9144 scope;
    Fn008bee90(OB_PTR(lua_State, field8), tag);
}

// FUNCTION: 0x008b86c0
uint32_t cGZLua5::Slot93_ac8bf8(uint32_t tag, uint32_t other)
{
    FpuScope_ac9144 scope;
    Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008befe0)), 0);
    lua_pushnumber(OB_PTR(lua_State, field8), static_cast<int32_t>(tag));
    lua_pushnumber(OB_PTR(lua_State, field8), static_cast<int32_t>(other));
    Slot70_ac8bf8(2, 0, 0, 1);
    return tag;
}

// FUNCTION: 0x008b8750
uint32_t cGZLua5::Slot94_ac8bf8(uint32_t tag)
{
    FpuScope_ac9144 scope;
    ThreadView_ac9144* view = reinterpret_cast<ThreadView_ac9144*>(reinterpret_cast<char*>(this) + 8);
    return view->Fn93(view->Fn91(tag));
}

// FUNCTION: 0x008b87a0
void cGZLua5::Slot95_ac8bf8(uint32_t pointer, uint32_t tag)
{
    FpuScope_ac9144 scope;
    Fn008bf100(OB_PTR(lua_State, field8), OB_PTR(void, pointer), tag);
}

// FUNCTION: 0x008b87f0
uint32_t cGZLua5::Slot96_ac8bf8(uint32_t index)
{
    FpuScope_ac9144 scope;
    return *OB_PTR(uint32_t, Slot46_ac8bf8(index));
}

// FUNCTION: 0x008b8c20
uint32_t cGZLua5::Slot10_ac8d7c()
{
    FpuScope_ac9144 scope;
    return lua_getgccount(OB_PTR(lua_State, field8));
}

// FUNCTION: 0x008b8c60
uint32_t cGZLua5::Slot11_ac8d7c()
{
    FpuScope_ac9144 scope;
    return lua_getgcthreshold(OB_PTR(lua_State, field8));
}

// FUNCTION: 0x008b8ca0
void cGZLua5::Slot12_ac8d7c(uint32_t threshold)
{
    FpuScope_ac9144 scope;
    lua_setgcthreshold(OB_PTR(lua_State, field8), threshold);
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b8cf0 score 22
bool cGZLua5::QueryInterface(unsigned int iid, void** out)
{
    *out = 0;
    if (iid == 0x6b2811a6) {
        cUnk00ac8d7c* lua = this;
        *out = lua;
        AddRef();
        return true;
    }
    *out = 0;
    if (iid == 0xeb2810f1) {
        cUnk00ac8bf8* thread = this;
        *out = thread;
        AddRef();
        return true;
    }
    return cUnk0090da1e::QueryInterface(iid, out);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b8e20 score 6
bool cGZLua5::Slot07_ac8bf8(uint32_t owner, uint32_t state, uint32_t id)
{
    FpuScope_ac9144 scope;
    Unknown_ac9144* current = OB_PTR(Unknown_ac9144, owner);
    field4 = id;
    field8 = state;
    Unknown_ac9144* previous = OB_PTR(Unknown_ac9144, fieldc);
    if (current != previous) {
        if (current) {
            current->AddRef();
        }
        fieldc = owner;
        if (previous) {
            previous->Release();
        }
    }
    Slot51_ac8bf8(OB_ADDR("_ALERT"));
    Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008b8d70)), 0);
    Slot65_ac8bf8(-10001);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b8ed0 score 2
bool cGZLua5::Slot08_ac8bf8()
{
    FpuScope_ac9144 scope;
    Unknown_ac9144* owner = OB_PTR(Unknown_ac9144, fieldc);
    field8 = 0;
    if (owner) {
        fieldc = 0;
        owner->Release();
    }
    field4 = 0xffffffff;
    return true;
}
#endif

// The registry of the main thread's interface object: the user data word before the main state is the interface.
#ifdef OB_DRAFTS
// CLOSE: 0x008bc500 score 7
NOINLINE_ac9144 cThreadRegistry_ac9144* Fn008bc500(lua_State* L)
{
    LuaState_ac9144* state = reinterpret_cast<LuaState_ac9144*>(L);
    cUnk00ac8bf8* thread = reinterpret_cast<cUnk00ac8bf8**>(state->mpGlobal->mpMainThread)[-1];
    cGZLua5* lua = static_cast<cGZLua5*>(thread);
    return reinterpret_cast<cThreadRegistry_ac9144*>(lua->mThreadRegistry);
}
#endif

// The interpreter's loaders and the registry's resume, which the thread interface wraps.
// STUB: 0x008be310
int luaL_loadfile(lua_State* L, const char* filename);
// STUB: 0x008be4e0
int luaL_loadbuffer(lua_State* L, const char* buff, size_t size, const char* name);
// STUB: 0x008c52c0
lua_State* lua_open();
// STUB: 0x008c4f30
int luaopen_base(lua_State* L);
// STUB: 0x008c3ad0
int luaopen_io(lua_State* L);
// STUB: 0x008c0b40
int luaopen_math(lua_State* L);
// STUB: 0x008c0450
int luaopen_debug(lua_State* L);

// The two library openers the interface calls, defined by other parts of the game.
namespace nsGZLua5ThreadLib {
bool OpenLib(cUnk00ac8d7c* lua);
}
namespace nsGZLua5CompatWithLua4 {
bool OpenLib(cUnk00ac8d7c* lua);
}
// STUB: 0x008c5360
void lua_close(lua_State* L);

// The error reporter is called with the thread object, the status code and the message.
typedef void (*ErrorReporter_ac9144)(void* thread, int32_t status, const char* message);

// FUNCTION: 0x008b9050
uint32_t cGZLua5::Slot75_ac8bf8(uint32_t filename)
{
    FpuScope_ac9144 scope;
    uint32_t status = luaL_loadfile(OB_PTR(lua_State, field8), OB_PTR(const char, filename));
    if (status != 0) {
        if (Slot23_ac8bf8(-1) == 4) {
            uint32_t message = Slot43_ac8bf8(-1);
            cUnk00ac8d7c* lua = OB_PTR(cUnk00ac8d7c, Slot03_ac8bf8());
            if (lua) {
                ErrorReporter_ac9144 reporter = reinterpret_cast<ErrorReporter_ac9144>(OB_PTR(void, lua->Slot14_ac8d7c()));
                if (reporter) {
                    reporter(reinterpret_cast<char*>(this) + 8, status, OB_PTR(const char, message));
                }
            }
        }
    }
    return status;
}

// FUNCTION: 0x008b90f0
uint32_t cGZLua5::Slot76_ac8bf8(uint32_t string)
{
    FpuScope_ac9144 scope;
    const char* text = OB_PTR(const char, string);
    uint32_t status = luaL_loadbuffer(OB_PTR(lua_State, field8), text, std::strlen(text), text);
    if (status != 0) {
        if (Slot23_ac8bf8(-1) == 4) {
            uint32_t message = Slot43_ac8bf8(-1);
            cUnk00ac8d7c* lua = OB_PTR(cUnk00ac8d7c, Slot03_ac8bf8());
            if (lua) {
                ErrorReporter_ac9144 reporter = reinterpret_cast<ErrorReporter_ac9144>(OB_PTR(void, lua->Slot14_ac8d7c()));
                if (reporter) {
                    reporter(reinterpret_cast<char*>(this) + 8, status, OB_PTR(const char, message));
                }
            }
        }
    }
    return status;
}

// FUNCTION: 0x008b91a0
uint32_t cGZLua5::Slot77_ac8bf8(uint32_t buffer, uint32_t size, uint32_t name)
{
    FpuScope_ac9144 scope;
    uint32_t status = luaL_loadbuffer(OB_PTR(lua_State, field8), OB_PTR(const char, buffer), size,
                                      OB_PTR(const char, name));
    if (status != 0) {
        if (Slot23_ac8bf8(-1) == 4) {
            uint32_t message = Slot43_ac8bf8(-1);
            cUnk00ac8d7c* lua = OB_PTR(cUnk00ac8d7c, Slot03_ac8bf8());
            if (lua) {
                ErrorReporter_ac9144 reporter = reinterpret_cast<ErrorReporter_ac9144>(OB_PTR(void, lua->Slot14_ac8d7c()));
                if (reporter) {
                    reporter(reinterpret_cast<char*>(this) + 8, status, OB_PTR(const char, message));
                }
            }
        }
    }
    return status;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b8f30 score 28
uint32_t cGZLua5::Slot70_ac8bf8(uint32_t nargs, uint32_t nresults, uint32_t errfunc, uint32_t popMessage)
{
    FpuScope_ac9144 scope;
    uint32_t status;
    Slot14_ac8bf8();
    if (errfunc == 0 && fieldc != 0 && OB_PTR(cUnk00ac8d7c, fieldc)->Slot14_ac8d7c() != 0) {
        int32_t base = Slot14_ac8bf8() - nargs;
        lua_pushlstring(OB_PTR(lua_State, field8), "_TRACEBACK", 10);
        lua_rawget(OB_PTR(lua_State, field8), -10001);
        lua_insert(OB_PTR(lua_State, field8), base);
        status = lua_pcall(OB_PTR(lua_State, field8), nargs, nresults, base);
        lua_remove(OB_PTR(lua_State, field8), base);
    } else {
        status = lua_pcall(OB_PTR(lua_State, field8), nargs, nresults, errfunc);
    }
    if (status != 0) {
        uint32_t message = Slot43_ac8bf8(-1);
        cUnk00ac8bf8* thread = this;
        cUnk00ac8d7c* lua = OB_PTR(cUnk00ac8d7c, thread->Slot03_ac8bf8());
        if (lua) {
            ErrorReporter_ac9144 reporter = reinterpret_cast<ErrorReporter_ac9144>(OB_PTR(void, lua->Slot14_ac8d7c()));
            if (reporter) {
                reporter(thread, status, OB_PTR(const char, message));
            }
        }
        if (*reinterpret_cast<bool*>(&popMessage)) {
            Slot19_ac8bf8(1);
        }
    }
    return status;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b8890 score 89
bool cGZLua5::Slot04_ac8d7c(uint32_t libraries)
{
    FpuScope_ac9144 scope;
    if (field8 == 0) {
        lua_State* L = lua_open();
        if (L) {
            cThreadRegistry_ac9144* registry = reinterpret_cast<cThreadRegistry_ac9144*>(mThreadRegistry);
            if (registry->Fn008bcc50(this, L)) {
                luaopen_base(OB_PTR(lua_State, field8));
                if (libraries & 2) {
                    luaopen_io(OB_PTR(lua_State, field8));
                }
                if (libraries & 4) {
                    Fn008c2470(OB_PTR(lua_State, field8));
                }
                if (libraries & 8) {
                    luaopen_math(OB_PTR(lua_State, field8));
                }
                if (libraries & 0x10) {
                    luaopen_debug(OB_PTR(lua_State, field8));
                }
                if (libraries & 0x20) {
                    Fn008bfaa0(OB_PTR(lua_State, field8));
                }
                if (libraries & 0x40) {
                    nsGZLua5CompatWithLua4::OpenLib(this);
                }
                nsGZLua5ThreadLib::OpenLib(this);
                lua_settop(OB_PTR(lua_State, field8), 0);
                return true;
            }
        }
    }
    return false;
}
#endif

// FUNCTION: 0x008b89b0
bool cGZLua5::Slot05_ac8d7c()
{
    FpuScope_ac9144 scope;
    lua_State* L = OB_PTR(lua_State, field8);
    if (L) {
        reinterpret_cast<cThreadRegistry_ac9144*>(mThreadRegistry)->Fn008bd630();
        lua_close(L);
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b8a00 score 17
uint32_t cGZLua5::Slot06_ac8d7c(uint32_t pThread, uint32_t flags, uint32_t classID)
{
    FpuScope_ac9144 scope;
    cUnk00ac8bf8** out = OB_PTR(cUnk00ac8bf8*, pThread);
    *out = 0;
    cThreadRegistry_ac9144* registry = reinterpret_cast<cThreadRegistry_ac9144*>(mThreadRegistry);
    int32_t id = registry->Fn008bcd50(OB_PTR(lua_State, field8), flags, classID);
    if (id != -1) {
        lua_State* thread = registry->Fn008bc700(id);
        *out = reinterpret_cast<cUnk00ac8bf8**>(thread)[-1];
        (*out)->AddRef();
    }
    return id;
}
#endif

// FUNCTION: 0x008b8a80
uint32_t cGZLua5::Slot09_ac8d7c(uint32_t id)
{
    FpuScope_ac9144 scope;
    lua_State* thread = reinterpret_cast<cThreadRegistry_ac9144*>(mThreadRegistry)->Fn008bc700(id);
    if (thread) {
        return OB_ADDR(reinterpret_cast<cUnk00ac8bf8**>(thread)[-1]);
    }
    return 0;
}

// FUNCTION: 0x008b8ae0
bool cGZLua5::Slot07_ac8d7c(uint32_t id)
{
    FpuScope_ac9144 scope;
    return reinterpret_cast<cThreadRegistry_ac9144*>(mThreadRegistry)->Fn008bcee0(OB_PTR(lua_State, field8), id);
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b8b30 score 70
bool cGZLua5::Slot08_ac8d7c(uint32_t id, uint32_t nargs, uint32_t pCount)
{
    FpuScope_ac9144 scope;
    cThreadRegistry_ac9144* registry = reinterpret_cast<cThreadRegistry_ac9144*>(mThreadRegistry);
    int32_t top = lua_gettop(OB_PTR(lua_State, field8)) - nargs;
    int32_t status = registry->Fn008bd040(OB_PTR(lua_State, field8), id, nargs);
    if (status != 0 && mpErrorReporter != 0) {
        lua_State* thread = registry->Fn008bc700(id);
        void* threadObject = 0;
        if (thread) {
            threadObject = reinterpret_cast<void**>(thread)[-1];
        }
        const char* message = lua_tostring(OB_PTR(lua_State, field8), -1);
        if (message == 0) {
            message = "<unknown description>";
        }
        reinterpret_cast<ErrorReporter_ac9144>(mpErrorReporter)(threadObject, status, message);
    }
    int32_t count = lua_gettop(OB_PTR(lua_State, field8)) - top;
    if (pCount == 0) {
        lua_settop(OB_PTR(lua_State, field8), -1 - count);
    } else {
        *OB_PTR(int32_t, pCount) = count;
    }
    return status == 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008bd630 score 31
bool cThreadRegistry_ac9144::Fn008bd630()
{
    mpOwner->Slot03_ac8d7c();
    while (mnCount != 0) {
        ThreadNode_ac9144* node = 0;
        for (uint32_t n = 0; n < mBuckets.size(); ++n) {
            if (mBuckets[n]) {
                node = mBuckets[n];
                break;
            }
        }
        Fn008bcee0(0, node->mnID);
    }
    if (mpOwner) {
        cUnk00ac8d7c* owner = mpOwner;
        mpOwner = 0;
        owner->Release();
    }
    return true;
}
#endif

// The coroutine functions the thread library registers (Lua C functions defined elsewhere).
namespace nsGZLua5ThreadLib {
// STUB: 0x008bd170
int Resume(lua_State* L);
// STUB: 0x008bd2c0
int Create(lua_State* L);
// STUB: 0x008bd460
int Wrap(lua_State* L);
// STUB: 0x008bd4b0
int Destroy(lua_State* L);
// STUB: 0x008bc740
int Valid(lua_State* L);
// STUB: 0x008bc490
int ID(lua_State* L);
// STUB: 0x008bc850
int Status(lua_State* L);
// STUB: 0x008bc7d0
int Class(lua_State* L);
// STUB: 0x008bc8e0
int Parent(lua_State* L);
}

// The Lua 4 compatibility script the library runs, and its last function.
// GLOBAL: 0x00b15ffc
extern const char* gB15ffc;
// STUB: 0x008bea30
int Fn008bea30(lua_State* L);

// FUNCTION: 0x008bd6a0
bool nsGZLua5ThreadLib::OpenLib(cUnk00ac8d7c* lua)
{
    FpuScope_ac9144 scope;
    cUnk00ac8bf8* thread = OB_PTR(cUnk00ac8bf8, lua->Slot03_ac8d7c());
    uint32_t top = thread->Slot14_ac8bf8();
    bool result = false;
    thread->Slot87_ac8bf8(OB_ADDR("coroutine"));
    if (thread->Slot23_ac8bf8(-1) == 5) {
        thread->Slot51_ac8bf8(OB_ADDR("resume"));
        thread->Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Resume)), 0);
        thread->Slot65_ac8bf8(-3);
        thread->Slot51_ac8bf8(OB_ADDR("create"));
        thread->Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Create)), 0);
        thread->Slot65_ac8bf8(-3);
        thread->Slot51_ac8bf8(OB_ADDR("wrap"));
        thread->Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Wrap)), 0);
        thread->Slot65_ac8bf8(-3);
        thread->Slot51_ac8bf8(OB_ADDR("destroy"));
        thread->Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Destroy)), 0);
        thread->Slot65_ac8bf8(-3);
        thread->Slot51_ac8bf8(OB_ADDR("valid"));
        thread->Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Valid)), 0);
        thread->Slot65_ac8bf8(-3);
        thread->Slot51_ac8bf8(OB_ADDR("id"));
        thread->Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&ID)), 0);
        thread->Slot65_ac8bf8(-3);
        thread->Slot51_ac8bf8(OB_ADDR("status"));
        thread->Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Status)), 0);
        thread->Slot65_ac8bf8(-3);
        thread->Slot51_ac8bf8(OB_ADDR("class"));
        thread->Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Class)), 0);
        thread->Slot65_ac8bf8(-3);
        thread->Slot51_ac8bf8(OB_ADDR("parent"));
        thread->Slot52_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Parent)), 0);
        thread->Slot65_ac8bf8(-3);
        result = true;
    }
    thread->Slot15_ac8bf8(top);
    return result;
}

// FUNCTION: 0x008bf160
bool nsGZLua5CompatWithLua4::OpenLib(cUnk00ac8d7c* lua)
{
    FpuScope_ac9144 scope;
    cUnk00ac8bf8* thread = OB_PTR(cUnk00ac8bf8, lua->Slot03_ac8d7c());
    if (thread) {
        thread->AddRef();
    }
    uint32_t error = thread->Slot72_ac8bf8(OB_ADDR(gB15ffc));
    if (error == 0) {
        thread->Slot81_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008be990)), OB_ADDR("tag"));
        thread->Slot81_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008bee20)), OB_ADDR("settag"));
        thread->Slot81_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008bef00)), OB_ADDR("settagmethod"));
        thread->Slot81_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008bec80)), OB_ADDR("gettagmethod"));
        thread->Slot81_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008be930)), OB_ADDR("newtag"));
        thread->Slot81_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008befe0)), OB_ADDR("copytagmethods"));
        thread->Slot81_ac8bf8(OB_ADDR(reinterpret_cast<void*>(&Fn008bea30)), OB_ADDR("globals"));
        thread->Release();
        return true;
    }
    thread->Release();
    return false;
}

// The interpreter's internals lua_close runs (close_state takes its argument in a register in the original).
// STUB: 0x008c54b0
void luaF_close(lua_State* L, void* level);
// STUB: 0x008c7c20
void luaC_separateudata(lua_State* L);
// STUB: 0x008c5350
void callallgcTM(lua_State* L, void* unused);
// STUB: 0x008bb870
int luaD_rawrunprotected(lua_State* L, void (*f)(lua_State*, void*), void* ud);
// STUB: 0x008c5120
void close_state(lua_State* L);

#ifdef OB_DRAFTS
// CLOSE: 0x008c5360 score 6
void lua_close(lua_State* L)
{
    lua_State* main = reinterpret_cast<LuaState_ac9144*>(L)->mpGlobal->mpMainThread;
    LuaState_ac9144* state = reinterpret_cast<LuaState_ac9144*>(main);
    luaF_close(main, state->mpStack);
    luaC_separateudata(main);
    state->mnErrFunc = 0;
    do {
        state->mpCI = state->mpBaseCI;
        state->mpBase = state->mpTop = state->mpCI->mpBase;
        state->mnCalls = 0;
    } while (luaD_rawrunprotected(main, callallgcTM, 0) != 0);
    close_state(main);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008bcb40 score 98
ThreadRecord_ac9144* cThreadRegistry_ac9144::Fn008bcb40(const int32_t* key)
{
    uint32_t id = static_cast<uint32_t>(*key);
    ThreadNode_ac9144* node = mBuckets[id % mBuckets.size()];
    while (node && static_cast<uint32_t>(node->mnID) != id) {
        node = node->mpNext;
    }
    ThreadNode_ac9144* found = node;
    if (found) {
        return &found->mRecord;
    }
    ThreadRecord_ac9144 fresh;
    fresh.mpThread = 0;
    fresh.mpParent = 0;
    fresh.mVector.mpBegin = 0;
    fresh.mVector.mpEnd = 0;
    fresh.mVector.mpCapacity = 0;
    fresh.mnFlags = 0;
    fresh.mnClassID = 0;
    ThreadPair_ac9144 pair;
    pair.mnID = id;
    pair.mRecord.mpThread = fresh.mpThread;
    pair.mRecord.mpParent = fresh.mpParent;
    pair.mRecord.mVector.Fn004b03e0(fresh.mVector);
    pair.mRecord.mnFlags = fresh.mnFlags;
    pair.mRecord.mnClassID = fresh.mnClassID;
    return &Fn008bcaf0(&pair)->mRecord;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008bcc50 score 55
bool cThreadRegistry_ac9144::Fn008bcc50(cUnk00ac8d7c* owner, lua_State* L)
{
    cUnk00ac8d7c* previous = mpOwner;
    if (owner != previous) {
        if (owner) {
            owner->AddRef();
        }
        mpOwner = owner;
        if (previous) {
            previous->Release();
        }
    }
    cUnk00ac8bf8* thread = OB_PTR(cUnk00ac8bf8, mpOwner->Slot03_ac8d7c());
    if (thread->Slot07_ac8bf8(OB_ADDR(owner), OB_ADDR(L), mnNextID)) {
        thread->Slot54_ac8bf8(OB_ADDR(L));
        thread->Slot54_ac8bf8(OB_ADDR(this));
        thread->Slot65_ac8bf8(-10000);
        reinterpret_cast<cUnk00ac8bf8**>(L)[-1] = thread;
        ThreadRecord_ac9144 fresh;
        fresh.mpThread = L;
        fresh.mpParent = 0;
        fresh.mVector.mpBegin = 0;
        fresh.mVector.mpEnd = 0;
        fresh.mVector.mpCapacity = 0;
        fresh.mnFlags = 0x10000000;
        fresh.mnClassID = 0;
        thread->AddRef();
        int32_t id = mnNextID++;
        ThreadRecord_ac9144* record = Fn008bcb40(&id);
        record->mpThread = fresh.mpThread;
        record->mpParent = fresh.mpParent;
        record->mVector.Fn0072bd50(fresh.mVector);
        record->mnClassID = fresh.mnClassID;
        record->mnFlags = fresh.mnFlags;
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008bcd50 score 191
int32_t cThreadRegistry_ac9144::Fn008bcd50(lua_State* L, uint32_t flags, uint32_t classID)
{
    int32_t id = -1;
    lua_State* thread = lua_newthread(L);
    lua_xmove(L, thread, 2);
    ThreadRecord_ac9144 record;
    record.mpThread = 0;
    record.mpParent = 0;
    record.mVector.mpBegin = 0;
    record.mVector.mpEnd = 0;
    record.mVector.mpCapacity = 0;
    record.mnFlags = 0;
    record.mnClassID = 0;
    Unknown_ac9144* object = 0;
    GZCOM_ac9144* com = Fn0090ddf1();
    if (object) {
        Unknown_ac9144* old = object;
        object = 0;
        old->Release();
    }
    cUnk00ac8bf8* threadObject = 0;
    if (com->Fn03(classID, 0xeb2810f1, reinterpret_cast<void**>(&threadObject)) &&
        threadObject->Slot07_ac8bf8(OB_ADDR(mpOwner), OB_ADDR(thread), mnNextID)) {
        record.mpThread = thread;
        record.mnFlags = flags;
        record.mnClassID = classID;
        bool created = true;
        if (flags & 0x10) {
            record.mpParent = L;
            cUnk00ac8bf8* parent = reinterpret_cast<cUnk00ac8bf8**>(L)[-1];
            if (parent == 0) {
                created = false;
            } else {
                int32_t parentID = parent->Slot10_ac8bf8();
                ThreadIterator_ac9144 it = Fn006f1530(&parentID);
                if (it.mpNode == 0) {
                    created = false;
                } else {
                    it.mpNode->mRecord.mVector.Fn007ebd30(thread);
                }
            }
        } else {
            record.mpParent = 0;
        }
        if (created) {
            id = mnNextID++;
            if (id != -1) {
                ThreadRecord_ac9144* slot = Fn008bcb40(&id);
                slot->mpThread = thread;
                slot->mpParent = record.mpParent;
                slot->mVector.Fn0072bd50(record.mVector);
                slot->mnFlags = record.mnFlags;
                slot->mnClassID = classID;
                reinterpret_cast<cUnk00ac8bf8**>(thread)[-1] = threadObject;
                threadObject->AddRef();
                lua_pushlightuserdata(thread, thread);
                lua_pushvalue(thread, -2);
                lua_rawset(thread, -10000);
                lua_settop(thread, 1);
            }
        }
    }
    if (threadObject) {
        threadObject->Release();
    }
    return id;
}
#endif
