#include <cstddef>
#include <cstring>

#include "classes/cGZLua5.h"
#include "classes/cGZLua5Thread.h"
#include "classes/cUnk00ac8d7c.h"

// The embedded Lua 5.0 interpreter's state is only ever handled through pointers here.
struct lua_State;
typedef int (*lua_CFunction_ac8f54)(lua_State*);

// Helpers the original keeps out of line (their callers call them): the 2003 compiler would inline them here.
#ifdef _MSC_VER
#define NOINLINE_ac8f54 __declspec(noinline)
#else
#define NOINLINE_ac8f54
#endif

// A pointer the interface passes (or stores) as a 32-bit value: the base class still declares uint32_t.
// A macro, not an inline function: the 2003 compiler expands an inlined call ahead of the call it is an argument of and
// so loads the arguments in another order (the original loads the last argument first).
#define PTR_ac8f54(Type, value) reinterpret_cast<Type*>(static_cast<uintptr_t>(value))
// A pointer handed back through a slot the base class declares as uint32_t (a macro for the same reason).
#define ADDR_ac8f54(p) static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p))

// The x87 precision control word: 0x892a0a reads which precision is set (0 = none of the Lua-friendly ones), 0x8929e0
// sets one (1 = double).
// STUB: 0x00892a0a
uint32_t Fn00892a0a();
// STUB: 0x008929e0
void Fn008929e0(uint32_t precision);

// Every call into Lua runs with double precision: when the precision is not set, set it for the call and put it back.
struct FpuScope_ac8f54 {
    uint32_t mPrevious;
    bool mbSet;
    FpuScope_ac8f54() : mPrevious(Fn00892a0a()), mbSet(mPrevious == 0)
    {
        if (mbSet) {
            Fn008929e0(1);
        }
    }
    ~FpuScope_ac8f54()
    {
        if (mbSet) {
            Fn008929e0(mPrevious);
        }
    }
};

// The Lua 5.0 API (the cdecl functions of the statically linked interpreter).
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
// STUB: 0x008bb670
void* lua_newuserdata(lua_State* L, size_t size);
// STUB: 0x008bb140
int lua_getmetatable(lua_State* L, int index);
// STUB: 0x008be580
int lua_dofile(lua_State* L, const char* filename);
// STUB: 0x008be620
int lua_dostring(lua_State* L, const char* str);
// STUB: 0x008be5c0
int lua_dobuffer(lua_State* L, const char* buff, size_t size, const char* name);
// STUB: 0x008bb490
int lua_load(lua_State* L, void* reader, void* data, const char* chunkname);
// STUB: 0x008bb5a0
int lua_next(lua_State* L, int index);
// STUB: 0x008ba850
void lua_pushvalue(lua_State* L, int index);
// STUB: 0x008ba800
void lua_replace(lua_State* L, int index);
// STUB: 0x008ba6e0
void lua_settop(lua_State* L, int index);
// STUB: 0x008bae10
void lua_pushlstring(lua_State* L, const char* s, size_t len);
// STUB: 0x008bb060
void lua_rawget(lua_State* L, int index);
// STUB: 0x008ba7a0
void lua_insert(lua_State* L, int index);
// STUB: 0x008ba740
void lua_remove(lua_State* L, int index);
// STUB: 0x008bb420
int lua_pcall(lua_State* L, int nargs, int nresults, int errfunc);
// STUB: 0x008be310
int luaL_loadfile(lua_State* L, const char* filename);
// STUB: 0x008be4e0
int luaL_loadbuffer(lua_State* L, const char* buff, size_t size, const char* name);

// The error reporter is called with the thread object, the status code and the message.
typedef void (*ErrorReporter_ac8f54)(void* thread, int32_t status, const char* message);

// The registry of the Lua threads (an STLport hash map from the thread id to its record) that sits at +0x20 of the
// interface: only the two functions the thread wrappers call.
struct cThreadRegistry_ac8f54 {
    // Resume state of the thread registered under the id: -1 unknown, 0 finished, 1 running, 2 a flagged thread.
    // STUB: 0x008bc540
    int32_t Fn008bc540(uint32_t id);
    // Destroys the thread registered under the id.
    // STUB: 0x008bcee0
    bool Fn008bcee0(lua_State* L, int32_t id);
};

// Lua 5.0's state: the global state sits at +0x10, and its main thread (whose user data word, the 4 bytes before the
// state, holds the thread object of the interface) at +0x50 of that.
struct LuaGlobal_ac8f54 {
    uint8_t unknown0[0x50];
    lua_State* mpMainThread;
};
struct LuaState_ac8f54 {
    uint8_t unknown0[0x10];
    LuaGlobal_ac8f54* mpGlobal;
};

// The Lua C functions the interface hands to the interpreter.
// STUB: 0x008b8d70
int Fn008b8d70(lua_State* L);
// STUB: 0x008be990
int Fn008be990(lua_State* L);
// STUB: 0x008be930
int Fn008be930(lua_State* L);

// Something reference counted: slot 1 adds a reference, slot 2 drops one.
struct Unknown_ac8f54 {
    virtual void Pad00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

// The registry of the main thread's interface object.
// STUB: 0x008bc500
NOINLINE_ac8f54 cThreadRegistry_ac8f54* Fn008bc500(lua_State* L);

// The registry of the main thread's interface object: the user data word before the main state is the interface.
// The draft is named apart from the STUB above on purpose: a body the compiler can see changes how the callers keep
// the state and the thread id in registers (the original keeps the helper in another translation unit).
#ifdef OB_DRAFTS
// CLOSE: 0x008bc500 score 7
NOINLINE_ac8f54 cThreadRegistry_ac8f54* Fn008bc500Draft_ac8f54(lua_State* L)
{
    LuaState_ac8f54* state = reinterpret_cast<LuaState_ac8f54*>(L);
    cUnk00ac8bf8* thread = reinterpret_cast<cUnk00ac8bf8**>(state->mpGlobal->mpMainThread)[-1];
    cGZLua5* lua = static_cast<cGZLua5*>(thread);
    return reinterpret_cast<cThreadRegistry_ac8f54*>(lua->mThreadRegistry);
}
#endif

// FUNCTION: 0x008b8840
bool cGZLua5Thread::QueryInterface(unsigned int iid, void** out)
{
    *out = 0;
    if (iid != 0xeb2810f1) {
        return cUnk0090da1e::QueryInterface(iid, out);
    }
    cUnk00ac8bf8* thread = this;
    *out = thread;
    AddRef();
    return true;
}

// FUNCTION: 0x008b70b0
uint32_t cGZLua5Thread::Slot23_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_type(PTR_ac8f54(lua_State, field8), index);
}

// FUNCTION: 0x008b7100
uint32_t cGZLua5Thread::Slot24_ac8bf8(uint32_t type)
{
    FpuScope_ac8f54 scope;
    return ADDR_ac8f54(lua_typename(PTR_ac8f54(lua_State, field8), type));
}

// FUNCTION: 0x008b7740
uint32_t cGZLua5Thread::Slot43_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return ADDR_ac8f54(lua_tostring(PTR_ac8f54(lua_State, field8), index));
}

// FUNCTION: 0x008b7790
uint32_t cGZLua5Thread::Slot44_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_strlen(PTR_ac8f54(lua_State, field8), index);
}

// FUNCTION: 0x008b77e0
uint32_t cGZLua5Thread::Slot45_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return ADDR_ac8f54(lua_tocfunction(PTR_ac8f54(lua_State, field8), index));
}

// FUNCTION: 0x008b7830
uint32_t cGZLua5Thread::Slot46_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return ADDR_ac8f54(lua_touserdata(PTR_ac8f54(lua_State, field8), index));
}

// FUNCTION: 0x008b7880
uint32_t cGZLua5Thread::Slot47_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return ADDR_ac8f54(lua_tothread(PTR_ac8f54(lua_State, field8), index));
}

// FUNCTION: 0x008b7af0
uint32_t cGZLua5Thread::Slot55_ac8bf8(uint32_t size)
{
    FpuScope_ac8f54 scope;
    return ADDR_ac8f54(lua_newuserdata(PTR_ac8f54(lua_State, field8), size));
}

// FUNCTION: 0x008b7cc0
uint32_t cGZLua5Thread::Slot61_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_getmetatable(PTR_ac8f54(lua_State, field8), index);
}

// FUNCTION: 0x008b7f90
uint32_t cGZLua5Thread::Slot71_ac8bf8(uint32_t filename)
{
    FpuScope_ac8f54 scope;
    return lua_dofile(PTR_ac8f54(lua_State, field8), PTR_ac8f54(const char, filename));
}

// FUNCTION: 0x008b7fe0
uint32_t cGZLua5Thread::Slot72_ac8bf8(uint32_t string)
{
    FpuScope_ac8f54 scope;
    return lua_dostring(PTR_ac8f54(lua_State, field8), PTR_ac8f54(const char, string));
}

// FUNCTION: 0x008b8130
uint32_t cGZLua5Thread::Slot79_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_next(PTR_ac8f54(lua_State, field8), index);
}

// FUNCTION: 0x008b7640
uint32_t cGZLua5Thread::Slot39_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return static_cast<uint32_t>(lua_tonumber(PTR_ac8f54(lua_State, field8), index));
}

// FUNCTION: 0x008b7060
bool cGZLua5Thread::Slot22_ac8bf8(uint32_t size)
{
    FpuScope_ac8f54 scope;
    return lua_checkstack(PTR_ac8f54(lua_State, field8), size) != 0;
}

// FUNCTION: 0x008b7150
bool cGZLua5Thread::Slot25_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_isnumber(PTR_ac8f54(lua_State, field8), index) != 0;
}

// FUNCTION: 0x008b71a0
bool cGZLua5Thread::Slot26_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_isstring(PTR_ac8f54(lua_State, field8), index) != 0;
}

// FUNCTION: 0x008b71f0
bool cGZLua5Thread::Slot27_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_iscfunction(PTR_ac8f54(lua_State, field8), index) != 0;
}

// FUNCTION: 0x008b7300
bool cGZLua5Thread::Slot30_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_isuserdata(PTR_ac8f54(lua_State, field8), index) != 0;
}

// FUNCTION: 0x008b74d0
bool cGZLua5Thread::Slot35_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_type(PTR_ac8f54(lua_State, field8), index) <= 0;
}

// FUNCTION: 0x008b76f0
bool cGZLua5Thread::Slot42_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_toboolean(PTR_ac8f54(lua_State, field8), index) != 0;
}

// FUNCTION: 0x008b7240
bool cGZLua5Thread::Slot28_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_type(PTR_ac8f54(lua_State, field8), index) == 6;
}

// FUNCTION: 0x008b72a0
bool cGZLua5Thread::Slot29_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_type(PTR_ac8f54(lua_State, field8), index) == 5;
}

// FUNCTION: 0x008b7350
bool cGZLua5Thread::Slot31_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_type(PTR_ac8f54(lua_State, field8), index) == 2;
}

// FUNCTION: 0x008b7470
bool cGZLua5Thread::Slot34_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_type(PTR_ac8f54(lua_State, field8), index) == -1;
}

// FUNCTION: 0x008b8030
uint32_t cGZLua5Thread::Slot73_ac8bf8(uint32_t buffer, uint32_t size, uint32_t name)
{
    FpuScope_ac8f54 scope;
    return lua_dobuffer(PTR_ac8f54(lua_State, field8), PTR_ac8f54(const char, buffer), size, PTR_ac8f54(const char, name));
}

// FUNCTION: 0x008b8090
uint32_t cGZLua5Thread::Slot74_ac8bf8(uint32_t reader, uint32_t data, uint32_t name)
{
    FpuScope_ac8f54 scope;
    return lua_load(PTR_ac8f54(lua_State, field8), PTR_ac8f54(void, reader), PTR_ac8f54(void, data),
                    PTR_ac8f54(const char, name));
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b8ed0 score 2
bool cGZLua5Thread::Slot08_ac8bf8()
{
    FpuScope_ac8f54 scope;
    field8 = 0;
    if (fieldc) {
        Unknown_ac8f54* owner = PTR_ac8f54(Unknown_ac8f54, fieldc);
        fieldc = 0;
        owner->Release();
    }
    field4 = 0xffffffff;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008b7690 score 13
float cGZLua5Thread::Slot41_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return static_cast<float>(lua_tonumber(PTR_ac8f54(lua_State, field8), index));
}
#endif

// FUNCTION: 0x008b7520
bool cGZLua5Thread::Slot36_ac8bf8(uint32_t index1, uint32_t index2)
{
    FpuScope_ac8f54 scope;
    return lua_equal(PTR_ac8f54(lua_State, field8), index1, index2) != 0;
}

// FUNCTION: 0x008b7580
bool cGZLua5Thread::Slot37_ac8bf8(uint32_t index1, uint32_t index2)
{
    FpuScope_ac8f54 scope;
    return lua_rawequal(PTR_ac8f54(lua_State, field8), index1, index2) != 0;
}

// FUNCTION: 0x008b75e0
bool cGZLua5Thread::Slot38_ac8bf8(uint32_t index1, uint32_t index2)
{
    FpuScope_ac8f54 scope;
    return lua_lessthan(PTR_ac8f54(lua_State, field8), index1, index2) != 0;
}

// FUNCTION: 0x008b7410
bool cGZLua5Thread::Slot33_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_type(PTR_ac8f54(lua_State, field8), index) == 0;
}

// FUNCTION: 0x008b73b0
bool cGZLua5Thread::Slot32_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    return lua_type(PTR_ac8f54(lua_State, field8), index) == 1;
}

// FUNCTION: 0x008b6d70
uint32_t cGZLua5Thread::Slot13_ac8bf8()
{
    FpuScope_ac8f54 scope;
    if (field8 && field4 != 0xffffffff) {
        cThreadRegistry_ac8f54* registry = Fn008bc500(PTR_ac8f54(lua_State, field8));
        if (registry) {
            return registry->Fn008bc540(field4);
        }
    }
    return -1;
}

// FUNCTION: 0x008b6cf0
bool cGZLua5Thread::Slot12_ac8bf8()
{
    FpuScope_ac8f54 scope;
    bool result;
    if (field8) {
        cThreadRegistry_ac8f54* registry = Fn008bc500(PTR_ac8f54(lua_State, field8));
        if (registry && registry->Fn008bcee0(PTR_ac8f54(lua_State, field8), field4)) {
            result = true;
        } else {
            result = false;
        }
        return result;
    }
    return false;
}

// FUNCTION: 0x008b85e0
uint32_t cGZLua5Thread::Slot91_ac8bf8()
{
    FpuScope_ac8f54 scope;
    int32_t tag = -1;
    Slot52_ac8bf8(ADDR_ac8f54(reinterpret_cast<void*>(&Fn008be930)), 0);
    if (Slot70_ac8bf8(0, 1, 0, 1) == 0) {
        tag = static_cast<int32_t>(lua_tonumber(PTR_ac8f54(lua_State, field8), 1));
        lua_settop(PTR_ac8f54(lua_State, field8), -2);
        if (tag <= 0) {
            tag = -1;
        }
    }
    return tag;
}

// FUNCTION: 0x008b8400
uint32_t cGZLua5Thread::Slot88_ac8bf8(uint32_t index)
{
    FpuScope_ac8f54 scope;
    int32_t tag;
    lua_pushvalue(PTR_ac8f54(lua_State, field8), index);
    lua_pushvalue(PTR_ac8f54(lua_State, field8), -1);
    Slot52_ac8bf8(ADDR_ac8f54(reinterpret_cast<void*>(&Fn008be990)), 0);
    lua_replace(PTR_ac8f54(lua_State, field8), -3);
    if (Slot70_ac8bf8(1, 1, 0, 1) == 0) {
        tag = static_cast<int32_t>(lua_tonumber(PTR_ac8f54(lua_State, field8), -1));
        lua_settop(PTR_ac8f54(lua_State, field8), -2);
        if (tag == 0) {
            tag = -1;
        }
    } else {
        tag = -1;
    }
    return tag;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b8e20 score 6
bool cGZLua5Thread::Slot07_ac8bf8(uint32_t owner, uint32_t state, uint32_t id)
{
    FpuScope_ac8f54 scope;
    Unknown_ac8f54* current = PTR_ac8f54(Unknown_ac8f54, owner);
    field4 = id;
    field8 = state;
    if (current != PTR_ac8f54(Unknown_ac8f54, fieldc)) {
        Unknown_ac8f54* previous = PTR_ac8f54(Unknown_ac8f54, fieldc);
        if (current) {
            current->AddRef();
        }
        fieldc = owner;
        if (previous) {
            previous->Release();
        }
    }
    Slot51_ac8bf8(ADDR_ac8f54("_ALERT"));
    Slot52_ac8bf8(ADDR_ac8f54(reinterpret_cast<void*>(&Fn008b8d70)), 0);
    Slot65_ac8bf8(-10001);
    return true;
}
#endif

// FUNCTION: 0x008b9050
uint32_t cGZLua5Thread::Slot75_ac8bf8(uint32_t filename)
{
    FpuScope_ac8f54 scope;
    uint32_t status = luaL_loadfile(PTR_ac8f54(lua_State, field8), PTR_ac8f54(const char, filename));
    if (status != 0) {
        if (Slot23_ac8bf8(-1) == 4) {
            uint32_t message = Slot43_ac8bf8(-1);
            cUnk00ac8d7c* lua = PTR_ac8f54(cUnk00ac8d7c, Slot03_ac8bf8());
            if (lua) {
                ErrorReporter_ac8f54 reporter = reinterpret_cast<ErrorReporter_ac8f54>(static_cast<uintptr_t>(lua->Slot14_ac8d7c()));
                if (reporter) {
                    reporter(reinterpret_cast<char*>(this) + 8, status, PTR_ac8f54(const char, message));
                }
            }
        }
    }
    return status;
}

// FUNCTION: 0x008b90f0
uint32_t cGZLua5Thread::Slot76_ac8bf8(uint32_t string)
{
    FpuScope_ac8f54 scope;
    const char* text = PTR_ac8f54(const char, string);
    uint32_t status = luaL_loadbuffer(PTR_ac8f54(lua_State, field8), text, std::strlen(text), text);
    if (status != 0) {
        if (Slot23_ac8bf8(-1) == 4) {
            uint32_t message = Slot43_ac8bf8(-1);
            cUnk00ac8d7c* lua = PTR_ac8f54(cUnk00ac8d7c, Slot03_ac8bf8());
            if (lua) {
                ErrorReporter_ac8f54 reporter = reinterpret_cast<ErrorReporter_ac8f54>(static_cast<uintptr_t>(lua->Slot14_ac8d7c()));
                if (reporter) {
                    reporter(reinterpret_cast<char*>(this) + 8, status, PTR_ac8f54(const char, message));
                }
            }
        }
    }
    return status;
}

// FUNCTION: 0x008b91a0
uint32_t cGZLua5Thread::Slot77_ac8bf8(uint32_t buffer, uint32_t size, uint32_t name)
{
    FpuScope_ac8f54 scope;
    uint32_t status = luaL_loadbuffer(PTR_ac8f54(lua_State, field8), PTR_ac8f54(const char, buffer), size,
                                      PTR_ac8f54(const char, name));
    if (status != 0) {
        if (Slot23_ac8bf8(-1) == 4) {
            uint32_t message = Slot43_ac8bf8(-1);
            cUnk00ac8d7c* lua = PTR_ac8f54(cUnk00ac8d7c, Slot03_ac8bf8());
            if (lua) {
                ErrorReporter_ac8f54 reporter = reinterpret_cast<ErrorReporter_ac8f54>(static_cast<uintptr_t>(lua->Slot14_ac8d7c()));
                if (reporter) {
                    reporter(reinterpret_cast<char*>(this) + 8, status, PTR_ac8f54(const char, message));
                }
            }
        }
    }
    return status;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008b8f30 score 28
uint32_t cGZLua5Thread::Slot70_ac8bf8(uint32_t nargs, uint32_t nresults, uint32_t errfunc, uint32_t popMessage)
{
    FpuScope_ac8f54 scope;
    uint32_t status;
    Slot14_ac8bf8();
    if (errfunc == 0 && fieldc != 0 && PTR_ac8f54(cUnk00ac8d7c, fieldc)->Slot14_ac8d7c() != 0) {
        int32_t base = Slot14_ac8bf8() - nargs;
        lua_pushlstring(PTR_ac8f54(lua_State, field8), "_TRACEBACK", 10);
        lua_rawget(PTR_ac8f54(lua_State, field8), -10001);
        lua_insert(PTR_ac8f54(lua_State, field8), base);
        status = lua_pcall(PTR_ac8f54(lua_State, field8), nargs, nresults, base);
        lua_remove(PTR_ac8f54(lua_State, field8), base);
    } else {
        status = lua_pcall(PTR_ac8f54(lua_State, field8), nargs, nresults, errfunc);
    }
    if (status != 0) {
        uint32_t message = Slot43_ac8bf8(-1);
        cUnk00ac8bf8* thread = this;
        cUnk00ac8d7c* lua = PTR_ac8f54(cUnk00ac8d7c, thread->Slot03_ac8bf8());
        if (lua) {
            ErrorReporter_ac8f54 reporter = reinterpret_cast<ErrorReporter_ac8f54>(static_cast<uintptr_t>(lua->Slot14_ac8d7c()));
            if (reporter) {
                reporter(thread, status, PTR_ac8f54(const char, message));
            }
        }
        if (*reinterpret_cast<bool*>(&popMessage)) {
            Slot19_ac8bf8(1);
        }
    }
    return status;
}
#endif
