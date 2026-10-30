#include <cstddef>
#include "classes/cSC4Simulator.h"

// Views in the original's layout: the simulator seen from its first byte.
struct View_ab2fb8 {
    void* mpVtable0;           // 0x0
    void* mpVtable4;           // 0x4
    void* mpVtable8;           // 0x8
    void* mpVtableC;           // 0xc
    uint32_t mnRefCount10;     // 0x10
    uint8_t mPad14[0x10];      // 0x14
    void* mpVtable24;          // 0x24
    int32_t mnRefCount;        // 0x28
    uint32_t mnFlag2c;         // 0x2c
    int32_t mnPause;           // 0x30
    int32_t mnHiddenPause;     // 0x34
    int32_t mnEmergencyPause;  // 0x38
    int32_t mnSpeed;           // 0x3c
    uint8_t mPad40[4];         // 0x40
    uint8_t mbRunning;         // 0x44
};

// A message object (vtable slots by their offsets).
struct Message_ab2fb8 {
    virtual void Pad0() = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void SetType(uint32_t a) = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void SetData1(uint32_t a) = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void SetData2(uint32_t a) = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad20() = 0;
    virtual void SetData3(uint32_t a) = 0;
};

// The message server (slot 4 posts a message).
struct Server_ab2fb8 {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual bool Post(Message_ab2fb8* message, uint32_t flags) = 0;
};

// The date object at +0xf0 (slots by offset 0x30..0x68).
struct Date_ab2fb8 {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void SetDate(uint32_t month, uint32_t day, uint32_t year) = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual uint32_t GetDay() = 0;
    virtual uint32_t GetMonth() = 0;
    virtual uint32_t GetDayOfWeek() = 0;
    virtual uint32_t GetYear() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual uint32_t GetYearOffset() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual uint32_t GetDayOfYear() = 0;
};

// STUB: 0x009133da
void* Fn009133da_ab2fb8(uint32_t size);
struct MessageInit_ab2fb8 {
    // STUB: 0x009134d6
    Message_ab2fb8* Fn009134d6();
};

// FUNCTION: 0x00447e30
uint32_t cSC4Simulator::AddRef()
{
    View_ab2fb8* self = reinterpret_cast<View_ab2fb8*>(this);
    self->mnRefCount = self->mnRefCount + 1;
    return self->mnRefCount;
}

// FUNCTION: 0x007020a0
unsigned int cSC4Simulator::Release()
{
    View_ab2fb8* self = reinterpret_cast<View_ab2fb8*>(this);
    if (static_cast<uint32_t>(self->mnRefCount) > 1) {
        self->mnRefCount = self->mnRefCount - 1;
        return self->mnRefCount;
    }
    delete this;
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00702040 score ?
bool cSC4Simulator::QueryInterface(uint32_t iid, void** ppvArg)
{
    void** ppv = ppvArg;
    if (iid == 0x8695664e) {
        *ppv = this;
    } else if (iid == 0xe4fda3d4) {
        cUnk00a80784* base = this;
        *ppv = base;
    } else {
        return cRZSystemService::QueryInterface(iid, ppv);
    }
    if (*ppv) {
        AddRef();
    }
    return true;
}
#endif

// The simulator through its own vtable where a base slot is declared with fewer arguments than the code uses.
struct Sim_ab2fb8 {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad20() = 0;
    virtual bool RemoveAgentFrom(void* target, int32_t index) = 0;
};

// STUB: 0x00b43d44
// (the vehicle manager: a global pointer to an object whose slot 13 answers a bool)
struct VehicleManager_ab2fb8 {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual bool IsBusy() = 0;
};
// GLOBAL: 0x00b43d44
extern VehicleManager_ab2fb8* gpB43d44_ab2fb8;

inline Date_ab2fb8* DateOf_ab2fb8(cSC4Simulator* self)
{
    return reinterpret_cast<Date_ab2fb8*>(reinterpret_cast<char*>(self) + 0xf0);
}

// FUNCTION: 0x00702150
void cSC4Simulator::Slot06_ab2e68(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t* pa = reinterpret_cast<uint32_t*>(a);
    uint32_t* pb = reinterpret_cast<uint32_t*>(b);
    uint32_t* pc = reinterpret_cast<uint32_t*>(c);
    uint32_t* pd = reinterpret_cast<uint32_t*>(d);
    uint32_t* pe = reinterpret_cast<uint32_t*>(e);
    if (pa) {
        *pa = DateOf_ab2fb8(this)->GetMonth();
    }
    if (pb) {
        *pb = DateOf_ab2fb8(this)->GetYearOffset();
    }
    if (pc) {
        *pc = DateOf_ab2fb8(this)->GetYear();
    }
    if (pd) {
        *pd = DateOf_ab2fb8(this)->GetDayOfWeek();
    }
    if (pe) {
        *pe = DateOf_ab2fb8(this)->GetDay();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x007020e0 score ?  (builds a message, fills its four fields and posts it on the message server at +0xf8)
void cSC4Simulator::PostMessageServerMessage(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    void* mem = Fn009133da_ab2fb8(0x2c);
    Message_ab2fb8* message = 0;
    if (mem) {
        message = static_cast<MessageInit_ab2fb8*>(mem)->Fn009134d6();
    }
    message->AddRef();
    message->SetType(a);
    message->SetData1(b);
    message->SetData2(c);
    message->SetData3(d);
    Server_ab2fb8* server = *reinterpret_cast<Server_ab2fb8**>(reinterpret_cast<char*>(this) + 0xf8);
    server->Post(message, 0);
    message->Release();
}
#endif

// FUNCTION: 0x007021e0
void cSC4Simulator::Slot09_ab2e68()
{
    View_ab2fb8* self = reinterpret_cast<View_ab2fb8*>(this);
    ++self->mnPause;
    if (self->mnPause == 1) {
        PostMessageServerMessage(0xaa7fb7e0, self->mnPause, 0, 0);
    }
}

// FUNCTION: 0x00702200
void cSC4Simulator::Slot10_ab2e68()
{
    View_ab2fb8* self = reinterpret_cast<View_ab2fb8*>(this);
    ++self->mnHiddenPause;
    if (self->mnHiddenPause == 1) {
        PostMessageServerMessage(0x4a7fb7e2, self->mnHiddenPause, 0, 0);
    }
}

// FUNCTION: 0x00702220
void cSC4Simulator::Slot12_ab2e68()
{
    View_ab2fb8* self = reinterpret_cast<View_ab2fb8*>(this);
    if (self->mbRunning) {
        --self->mnPause;
        if (self->mnPause == 0) {
            PostMessageServerMessage(0xaa7fb7e0, 0, 0, 0);
        }
    }
}

// FUNCTION: 0x00702240
void cSC4Simulator::Slot13_ab2e68()
{
    View_ab2fb8* self = reinterpret_cast<View_ab2fb8*>(this);
    --self->mnHiddenPause;
    if (self->mnHiddenPause == 0) {
        PostMessageServerMessage(0x4a7fb7e2, 0, 0, 0);
    }
}

// FUNCTION: 0x00702260
bool cSC4Simulator::Slot20_ab2e68(uint32_t target)
{
    bool removed = false;
    for (int32_t i = 0; i < 11; ++i) {
        if (reinterpret_cast<Sim_ab2fb8*>(this)->RemoveAgentFrom(reinterpret_cast<void*>(target), i)) {
            removed = true;
        }
    }
    return removed;
}

// FUNCTION: 0x007024a0
void cSC4Simulator::Slot05_ab2e68(uint32_t date)
{
    reinterpret_cast<Date_ab2fb8*>(date)->SetDate(1, 1, 2000);
}

// FUNCTION: 0x00702540
void cSC4Simulator::Slot11_ab2e68()
{
    View_ab2fb8* self = reinterpret_cast<View_ab2fb8*>(this);
    Slot09_ab2e68();
    if (self->mbRunning) {
        self->mbRunning = 0;
    }
    ++self->mnEmergencyPause;
    if (self->mnEmergencyPause == 1) {
        PostMessageServerMessage(0x4a7fb807, self->mnEmergencyPause, 0, 0);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00702580 score ?
void cSC4Simulator::Slot14_ab2e68()
{
    View_ab2fb8* self = reinterpret_cast<View_ab2fb8*>(this);
    if (self->mbRunning != 1) {
        self->mbRunning = 1;
        Slot12_ab2e68();
    }
    --self->mnEmergencyPause;
    if (self->mnEmergencyPause == 0) {
        PostMessageServerMessage(0x4a7fb807, 0, 0, 0);
    }
}
#endif

// FUNCTION: 0x007026d0
bool cSC4Simulator::Slot28_ab2e68(uint32_t speed)
{
    View_ab2fb8* self = reinterpret_cast<View_ab2fb8*>(this);
    if (!self->mbRunning) {
        return false;
    }
    if (self->mnSpeed != static_cast<int32_t>(speed)) {
        DoSetSimSpeed(static_cast<int32_t>(speed));
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007026f0 score ?
float cSC4Simulator::Slot32_ab2e68()
{
    float* table = *reinterpret_cast<float**>(reinterpret_cast<char*>(this) + 0x108);
    if (Slot17_ab2e68()) {
        return table[4];
    }
    if (gpB43d44_ab2fb8->IsBusy()) {
        return table[4];
    }
    if (Slot15_ab2e68()) {
        return table[0];
    }
    uint32_t kind = Slot27_ab2e68();
    if (kind == 1) {
        return table[2];
    }
    if (kind == 2) {
        return table[3];
    }
    return table[1];
}
#endif

// FUNCTION: 0x00703d20
uint32_t cSC4Simulator::Slot07_ab2e68()
{
    char* self = reinterpret_cast<char*>(this);
    char* base = self + 0xe8;  // the null check a base-class conversion makes
    if (base) {
        return OB_ADDR(self + 0xf0);
    }
    return 0;
}

// FUNCTION: 0x00703d50
bool cSC4Simulator::Slot15_ab2e68()
{
    return reinterpret_cast<View_ab2fb8*>(this)->mnPause > 0;
}

// FUNCTION: 0x00703d60
bool cSC4Simulator::Slot16_ab2e68()
{
    return reinterpret_cast<View_ab2fb8*>(this)->mnHiddenPause > 0;
}

// FUNCTION: 0x00703d70
bool cSC4Simulator::Slot17_ab2e68()
{
    return reinterpret_cast<View_ab2fb8*>(this)->mnEmergencyPause > 0;
}

// FUNCTION: 0x00703d80
uint32_t cSC4Simulator::Slot18_ab2e68()
{
    View_ab2fb8* self = reinterpret_cast<View_ab2fb8*>(this);
    if (self->mnPause > 0 || self->mnHiddenPause > 0 || self->mnEmergencyPause > 0) {
        return 1;
    }
    return 0;
}

// ---- the agents: eleven red-black trees at +0x114 (a header, a count, a pad each) ----
struct StrObj_ab2fb8 {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual bool Equals(const void* other, uint32_t flags) = 0;
};

struct AgentNode_ab2fb8 {
    uint32_t mnColor;        // 0x0
    AgentNode_ab2fb8* mpParent; // 0x4
    AgentNode_ab2fb8* mpLeft;   // 0x8
    AgentNode_ab2fb8* mpRight;  // 0xc
    uint32_t mnKey;          // 0x10
    uint8_t mbEnabled;       // 0x14
    uint8_t mPad15[3];
    uint8_t mName[0x18];     // 0x18: a string object (vtable first)
};

struct AgentTree_ab2fb8 {
    AgentNode_ab2fb8* mpHeader; // 0x0: header->mpLeft is the first node
    uint32_t mnCount;           // 0x4
    uint32_t mnPad;             // 0x8
};

// The in-order successor the original's iterator computes.
inline AgentNode_ab2fb8* NextAgent_ab2fb8(AgentNode_ab2fb8* n)
{
    AgentNode_ab2fb8* r = n->mpRight;
    if (r) {
        n = r;
        while (n->mpLeft) {
            n = n->mpLeft;
        }
        return n;
    }
    AgentNode_ab2fb8* p = n->mpParent;
    while (n == p->mpRight) {
        n = p;
        p = p->mpParent;
    }
    if (n->mpRight != p) {
        n = p;
    }
    return n;
}

inline AgentTree_ab2fb8* TreeOf_ab2fb8(cSC4Simulator* self, int32_t i)
{
    return reinterpret_cast<AgentTree_ab2fb8*>(reinterpret_cast<char*>(self) + 0x114 + i * 12);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00703080 score ?  (GetAgentEnabled: looks an agent up by name in all eleven trees)
bool cSC4Simulator::Slot25_ab2e68(uint32_t nameArg)
{
    for (int32_t i = 0; i < 11; ++i) {
        AgentTree_ab2fb8* tree = TreeOf_ab2fb8(this, i);
        AgentNode_ab2fb8* header = tree->mpHeader;
        AgentNode_ab2fb8* n = header->mpLeft;
        while (n != header) {
            if (reinterpret_cast<StrObj_ab2fb8*>(n->mName)->Equals(reinterpret_cast<void*>(nameArg), 0)) {
                if (n->mbEnabled) {
                    return true;
                }
            }
            n = NextAgent_ab2fb8(n);
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00703120 score ?  (SetAgentEnabled: the original has two arguments, a name and a flag; the base slot has none)
void Fn00703120Draft_ab2fb8(cSC4Simulator* self, const void* name, bool enabled)
{
    for (int32_t i = 0; i < 11; ++i) {
        AgentTree_ab2fb8* tree = TreeOf_ab2fb8(self, i);
        AgentNode_ab2fb8* header = tree->mpHeader;
        AgentNode_ab2fb8* n = header->mpLeft;
        while (n != header) {
            if (reinterpret_cast<StrObj_ab2fb8*>(n->mName)->Equals(name, 0)) {
                n->mbEnabled = enabled;
            }
            n = NextAgent_ab2fb8(n);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007031c0 score ?
void cSC4Simulator::Slot33_ab2e68(uint32_t established)
{
    char* self = reinterpret_cast<char*>(this);
    bool wanted = static_cast<uint8_t>(established) != 0;
    if (wanted != (self[0x2e] != 0)) {
        self[0x2e] = static_cast<char>(established);
        for (int32_t i = 0; i < 11; ++i) {
            AgentTree_ab2fb8* tree = TreeOf_ab2fb8(this, i);
            AgentNode_ab2fb8* header = tree->mpHeader;
            for (AgentNode_ab2fb8* n = header->mpLeft; n != header; n = NextAgent_ab2fb8(n)) {
                uint8_t flags = n->mName[0x14];
                if (self[0x2e]) {
                    n->mbEnabled = (flags >> 1) & 1;
                } else {
                    n->mbEnabled = flags & 1;
                }
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00703fb0 score ?  (RemoveAllAgents(priority class): empties one tree)
bool cSC4Simulator::Slot22_ab2e68(uint32_t index)
{
    if (static_cast<int32_t>(index) < 11) {
        AgentTree_ab2fb8* tree = TreeOf_ab2fb8(this, static_cast<int32_t>(index));
        if (tree->mnCount) {
            // the original erases the nodes with 0x703850 and resets the header here
            tree->mpHeader->mpLeft = tree->mpHeader;
            tree->mpHeader->mpParent = 0;
            tree->mpHeader->mpRight = tree->mpHeader;
            tree->mnCount = 0;
        }
        *reinterpret_cast<AgentNode_ab2fb8**>(reinterpret_cast<char*>(this) + 0x1b0 + index * 4) = tree->mpHeader;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00704010 score ?  (RemoveAllAgents(): empties all eleven trees)
bool cSC4Simulator::Slot23_ab2e68()
{
    for (int32_t i = 0; i < 11; ++i) {
        Slot22_ab2e68(i);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00703af0 score ?  (IsAgentRegistered(class, priority): true when a node of that priority is there; fills the cursor then)
bool Fn00703af0Draft_ab2fb8(cSC4Simulator* self, int32_t index, uint32_t key)
{
    if (index < 11) {
        AgentTree_ab2fb8* tree = TreeOf_ab2fb8(self, index);
        AgentNode_ab2fb8* header = tree->mpHeader;
        for (AgentNode_ab2fb8* n = header->mpLeft; n != header; n = NextAgent_ab2fb8(n)) {
            if (n->mnKey == key) {
                *reinterpret_cast<AgentNode_ab2fb8**>(reinterpret_cast<char*>(self) + 0x1b0 + index * 4) = n;
                return true;
            }
        }
    }
    return false;
}
#endif

// FUNCTION: 0x005da1a0
void* Fn005da1a0_ab2fb8(void* stream, void* timer)
{
    struct Stream_ab2fb8 {
        virtual void Pad0() = 0;
        virtual void Pad1() = 0;
        virtual void Pad2() = 0;
        virtual void Pad3() = 0;
        virtual void Pad4() = 0;
        virtual void Pad5() = 0;
        virtual void Pad6() = 0;
        virtual void Pad7() = 0;
        virtual void Pad8() = 0;
        virtual void WriteTime(uint32_t t) = 0;
    };
    Stream_ab2fb8* s = static_cast<Stream_ab2fb8*>(stream);
    s->WriteTime(*(reinterpret_cast<uint32_t*>(timer) + 1));
    return stream;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00703e70 score ?  (OnTick of the system service: advance the simulation until the frame budget is spent)
// The part that needs the timers (calibrator tick, elapsed-time calls) is shortened to their calls.
bool Fn00703e70Draft_ab2fb8(cSC4Simulator* self)
{
    char* base = reinterpret_cast<char*>(self);
    // STUB-like: the real code reads the timer at +0x58 and the tunable at +0x7c; here only the loop skeleton stays
    if (base[0x24] && !base[0x25]) {
        base[0x25] = 1;
        if (!(*reinterpret_cast<int32_t*>(base + 0x2c) > 0)) {
            if (!(*reinterpret_cast<int32_t*>(base + 0x28) > 0)) {
                self->SimulateTimePassage();
                self->SimulateAgents();
            }
            if (!(*reinterpret_cast<int32_t*>(base + 0x2c) > 0)) {
                self->SimulateIdleTime();
            }
        }
        base[0x25] = 0;
    }
    return true;
}
#endif

// The streams the simulator saves to and loads from (slots by their offsets).
struct OStream_ab2fb8 {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void WriteUint8(uint32_t v) = 0;
    virtual void Pad6() = 0;
    virtual void WriteUint16(uint32_t v) = 0;
    virtual void WriteUint32(uint32_t v) = 0;
    virtual void WriteFloat(uint32_t v) = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual bool HasError() = 0;
};

struct IStream_ab2fb8 {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void ReadUint8(void* v) = 0;
    virtual void Pad6() = 0;
    virtual void ReadUint16(void* v) = 0;
    virtual void ReadUint32(void* v) = 0;
    virtual void ReadFloat(void* v) = 0;
};

// A timer object (an elapsed-time counter).
struct Timer_ab2fb8 {
    // STUB: 0x0089058f
    void Restart();
    // STUB: 0x00890198
    uint32_t GetElapsedTime() const;
    // STUB: 0x008905c4
    void Start();
};

// STUB: 0x005d9fd0
void Fn005d9fd0_ab2fb8(OStream_ab2fb8* stream, uint32_t value);
// STUB: 0x005d9fa0
void Fn005d9fa0_ab2fb8(IStream_ab2fb8* stream, void* value);

#ifdef OB_DRAFTS
// CLOSE: 0x00702290 score ?
bool cSC4Simulator::Slot03_a80784(void* streamArg)
{
    char* self = reinterpret_cast<char*>(this);
    OStream_ab2fb8* stream = static_cast<OStream_ab2fb8*>(streamArg);
    stream->WriteUint16(4);
    stream->WriteUint8(static_cast<uint8_t>(self[0x29]));
    stream->WriteUint8(static_cast<uint8_t>(self[0x2a]));
    stream->WriteUint32(*reinterpret_cast<uint32_t*>(self + 0x2c));
    stream->WriteUint32(*reinterpret_cast<uint32_t*>(self + 0x38));
    stream->WriteUint32(*reinterpret_cast<uint32_t*>(self + 0x3c));
    stream->WriteFloat(*reinterpret_cast<uint32_t*>(self + 0x74));
    for (int32_t i = 0; i < 11; ++i) {
        stream->WriteFloat(*reinterpret_cast<uint32_t*>(self + 0xac + i * 4));
        Fn005d9fd0_ab2fb8(stream, static_cast<uint8_t>(self[0xd8 + i]));
    }
    Fn005da1a0_ab2fb8(stream, self + 0xe4);
    return !stream->HasError();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00702340 score ?  (the tail that fixes up older saves is left out)
bool cSC4Simulator::Slot04_a80784(void* streamArg)
{
    char* self = reinterpret_cast<char*>(this);
    IStream_ab2fb8* stream = static_cast<IStream_ab2fb8*>(streamArg);
    uint16_t version = 0;
    stream->ReadUint16(&version);
    if (version > 4) {
        return false;
    }
    stream->ReadUint8(self + 0x29);
    stream->ReadUint8(self + 0x2a);
    stream->ReadUint32(self + 0x2c);
    stream->ReadUint32(self + 0x38);
    stream->ReadUint32(self + 0x3c);
    stream->ReadFloat(self + 0x74);
    for (int32_t i = 0; i < 11; ++i) {
        stream->ReadFloat(self + 0xac + i * 4);
        Fn005d9fa0_ab2fb8(stream, self + 0xd8 + i);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00702430 score ?
void cSC4Simulator::DoSetSimSpeed(int32_t speed)
{
    char* self = reinterpret_cast<char*>(this);
    switch (speed) {
    case 0:
        *reinterpret_cast<uint32_t*>(self + 0x84) = 0x1e;
        break;
    case 1:
        *reinterpret_cast<uint32_t*>(self + 0x84) = 0x14;
        break;
    case 2:
        *reinterpret_cast<uint32_t*>(self + 0x84) = 0xf;
        break;
    default:
        return;
    }
    *reinterpret_cast<int32_t*>(self + 0x3c) = speed;
    *reinterpret_cast<uint32_t*>(self + 0x80) = *reinterpret_cast<uint32_t*>(self + speed * 4 + 0xfc);
    reinterpret_cast<Timer_ab2fb8*>(self + 0x48)->Restart();
    PostMessageServerMessage(0x4a7fb7e9, speed, 0, 0);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007025b0 score ?  (the tunable values: defaults, then the ones read from the game's property table)
void cSC4Simulator::ReadSimulatorTunableValues()
{
    char* self = reinterpret_cast<char*>(this);
    *reinterpret_cast<uint32_t*>(self + 0xfc) = 0x1388;
    *reinterpret_cast<uint32_t*>(self + 0x100) = 0x3e8;
    *reinterpret_cast<uint32_t*>(self + 0x104) = 0x64;
    float* table = *reinterpret_cast<float**>(self + 0x108);
    table[0] = 0.0f;
    table[1] = 1.0f;
    table[2] = 1.5f;
    table[3] = 2.0f;
    table[4] = 1.0f;
    // the original now looks the table up in the resource manager (0xb43ca8) and overwrites these from it
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007024c0 score ?  (builds a message and delivers it to a target at once: the target's slot 3)
bool Fn007024c0Draft_ab2fb8(void** target, uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Message_ab2fb8* message = 0;
    void* mem = Fn009133da_ab2fb8(0x2c);
    if (mem) {
        message = static_cast<MessageInit_ab2fb8*>(mem)->Fn009134d6();
    }
    message->AddRef();
    message->SetType(a);
    message->SetData1(b);
    message->SetData2(c);
    message->SetData3(d);
    struct Target3_ab2fb8 {
        virtual void Pad0() = 0;
        virtual void Pad1() = 0;
        virtual void Pad2() = 0;
        virtual bool DoMessage(Message_ab2fb8* m) = 0;
    };
    bool r = static_cast<Target3_ab2fb8*>(*target ? reinterpret_cast<Target3_ab2fb8*>(*target) : 0)->DoMessage(message);
    message->Release();
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00702760 score ?  (std::find over 0x14-byte string records: the first one equal to a name)
uint32_t Fn00702760Draft_ab2fb8(uint8_t* first, uint8_t* last, const void* name)
{
    for (uint8_t* p = first; p != last; p += 0x14) {
        if (reinterpret_cast<StrObj_ab2fb8*>(p)->Equals(name, 0)) {
            return static_cast<uint32_t>(p - first);
        }
    }
    return static_cast<uint32_t>(last - first);
}
#endif

#ifdef OB_DRAFTS
// DRAFT (not a function start in the map): 0x0091270e score ?  (a small date-view object: its vtable and the value read through slot 26 of the source)
struct DateView_ab2fb8 {
    void* mpVtable;
    uint32_t mnDay;
};
DateView_ab2fb8* Fn0091270eDraft_ab2fb8(DateView_ab2fb8* self, Date_ab2fb8* src)
{
    self->mnDay = src->GetDayOfYear();
    return self;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00702a80 score ?  (SimulateTimePassage: the day, week, month and year messages the clock produces)
// Written from the reference build's shape; the calendar flags live in the byte array at +0xcc.. of it, +0xd8.. here.
void cSC4Simulator::SimulateTimePassage()
{
    char* self = reinterpret_cast<char*>(this);
    for (int32_t i = 0; i < 11; ++i) {
        self[0xd8 + i] = 0;
    }
    if (*reinterpret_cast<int32_t*>(self + 0x13c) == 0 && *reinterpret_cast<int32_t*>(self + 0x120) == 0) {
        bool timerDone = reinterpret_cast<Timer_ab2fb8*>(self + 0x48)->GetElapsedTime() >= *reinterpret_cast<uint32_t*>(self + 0x78);
        Date_ab2fb8* date = DateOf_ab2fb8(this);
        if (timerDone) {
            self[0xda] = 1;
        }
        (void)date;
        // the clock steps through minutes, hours and days here and posts 0x66956814..0x66956817
        PostMessageServerMessage(0x66956814, 0, 0, 0);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00702df0 score ?  (SimulateIdleTime: while the budget lasts, sends the idle message to the next agent)
void cSC4Simulator::SimulateIdleTime()
{
    char* self = reinterpret_cast<char*>(this);
    if (*reinterpret_cast<int32_t*>(self + 0x34) > 0) {
        return;
    }
    AgentNode_ab2fb8* cursor = *reinterpret_cast<AgentNode_ab2fb8**>(self + 0x1d8);
    AgentNode_ab2fb8* header = *reinterpret_cast<AgentNode_ab2fb8**>(self + 0x18c);
    if (!*reinterpret_cast<uint32_t*>(self + 0x190)) {
        return;
    }
    if (cursor == header) {
        cursor = header->mpLeft;
    }
    uint32_t budget = *reinterpret_cast<uint32_t*>(self + 0x78);
    uint32_t elapsed = reinterpret_cast<Timer_ab2fb8*>(self + 0x198)->GetElapsedTime();
    while (elapsed < budget) {
        AgentNode_ab2fb8* node = cursor;
        cursor = NextAgent_ab2fb8(cursor);
        *reinterpret_cast<AgentNode_ab2fb8**>(self + 0x1d8) = cursor;
        if (node->mbEnabled) {
            // the original sends 0x6695681a (idle) with the day number and the remaining budget through 0x7024c0
        }
        if (cursor == header) {
            break;
        }
        elapsed = reinterpret_cast<Timer_ab2fb8*>(self + 0x198)->GetElapsedTime();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00702f10 score ?  (sends the per-day message to the agents of one class: cursor-driven, see SimulateIdleTime)
void cSC4Simulator::Fn00702f10(uint32_t klass)
{
    char* self = reinterpret_cast<char*>(this);
    AgentTree_ab2fb8* tree = TreeOf_ab2fb8(this, static_cast<int32_t>(klass));
    if (!tree->mnCount) {
        return;
    }
    AgentNode_ab2fb8* header = tree->mpHeader;
    AgentNode_ab2fb8* cursor = *reinterpret_cast<AgentNode_ab2fb8**>(self + 0x1b0 + klass * 4);
    while (cursor != header) {
        AgentNode_ab2fb8* node = cursor;
        cursor = NextAgent_ab2fb8(cursor);
        *reinterpret_cast<AgentNode_ab2fb8**>(self + 0x1b0 + klass * 4) = cursor;
        if (node->mbEnabled) {
            PostMessageServerMessage(0x66956810 + klass, 0, 0, 0);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007038b0 score ?  (SimulateAgents: classes 2..7 whose day flag is set run at once; the others take one agent a tick)
void cSC4Simulator::SimulateAgents()
{
    char* self = reinterpret_cast<char*>(this);
    for (int32_t k = 2; k <= 7; ++k) {
        if (self[0xdc + k - 2 + 2]) {
            Fn00702f10(k);
        }
    }
    for (int32_t k = 0; k < 10; ++k) {
        AgentTree_ab2fb8* tree = TreeOf_ab2fb8(this, k);
        AgentNode_ab2fb8* cursor = *reinterpret_cast<AgentNode_ab2fb8**>(self + 0x1b0 + k * 4);
        if (tree->mnCount && cursor != tree->mpHeader && cursor->mbEnabled) {
            PostMessageServerMessage(0x66956810 + k, 0, 0, 0);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// DRAFT (not a function start in the map): 0x005d9370 score ?  (cSC4LimitTimerCalibrator::Tick: compares the cycle counter with the performance counter and
// folds the ratio into a running estimate at +0)
struct Calibrator_ab2fb8 {
    float mfEstimate;     // 0x0
    uint32_t mPad4;       // 0x4
    int64_t mnLastCounter;// 0x8
    int64_t mnLastCycles; // 0x10
    int64_t mnMinCycles;  // 0x18
    float mfScale;        // 0x20
};
// STUB: 0x0088ff19
void Fn0088ff19_ab2fb8(int64_t* counter);
// STUB: 0x00ffffff
// (the cycle counter read: cpuid + rdtsc is an instruction, not expressible in C++)
void CalibratorTickDraft_ab2fb8(Calibrator_ab2fb8* self, int64_t cycles)
{
    int64_t counter = 0;
    Fn0088ff19_ab2fb8(&counter);
    int64_t cycleDelta = cycles - self->mnLastCycles;
    if (cycleDelta > self->mnMinCycles) {
        int64_t counterDelta = counter - self->mnLastCounter;
        if (counterDelta > 0) {
            self->mfEstimate = (self->mfScale / static_cast<float>(counterDelta)) * static_cast<float>(cycleDelta) * 1.0f + self->mfEstimate * 0.5f;
        }
        self->mnLastCycles = cycles;
        self->mnLastCounter = counter;
    }
}
#endif

// ---- the service life cycle ----
// STUB: 0x00949ade
struct SystemBase_ab2fb8 {
    // STUB: 0x00949ade
    bool Fn00949ade();
};

// A service with two calls the life cycle uses (message server and command manager style objects).
struct Service_ab2fb8 {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void RemoveNotification(const void* target, uint32_t id) = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00703250 score ?  (Init: reads the tunables, registers for messages and starts the timers; the string/registry part is left out)
bool cSC4Simulator::Slot03_ae1d24()
{
    char* self = reinterpret_cast<char*>(this);
    if (self[0x2c]) {
        return true;
    }
    self[0x2c] = 1;
    *reinterpret_cast<uint32_t*>(self + 0x34) = 1;
    reinterpret_cast<SystemBase_ab2fb8*>(self + 8)->Fn00949ade();
    ReadSimulatorTunableValues();
    for (int32_t i = 0; i < 11; ++i) {
        *reinterpret_cast<AgentNode_ab2fb8**>(self + 0x1b0 + i * 4) = TreeOf_ab2fb8(this, i)->mpHeader;
    }
    int32_t speed = *reinterpret_cast<int32_t*>(self + 0x3c);
    if (speed == 3) {
        Slot28_ab2e68(0);
    } else {
        DoSetSimSpeed(speed);
    }
    reinterpret_cast<Timer_ab2fb8*>(self + 0x48)->Start();
    reinterpret_cast<Timer_ab2fb8*>(self + 0x60)->Start();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00702950 score ?  (Shutdown: unregisters from the message server and the command manager)
bool cSC4Simulator::Slot04_ae1d24()
{
    char* self = reinterpret_cast<char*>(this);
    if (!self[0x2c]) {
        return true;
    }
    self[0x2c] = 0;
    Service_ab2fb8* server = *reinterpret_cast<Service_ab2fb8**>(self + 0xf8);
    if (server) {
        server->RemoveNotification(self + 0x24, 0x26d31ec1);
        server->RemoveNotification(self + 0x24, 0x8bac4b43);
    }
    reinterpret_cast<SystemBase_ab2fb8*>(self + 8)->Fn00949ade();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00703540 score ?  (DoMessage: the init message answers the six clock queries, the others (un)register)
bool cSC4Simulator::Slot03_aaaa9c(void* messageArg)
{
    (void)messageArg;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00704360 score ?  (AddAgent(target, priority, name, flags): puts a record into the tree of that class)
bool cSC4Simulator::Slot19_ab2e68(uint32_t target, uint32_t klass, uint32_t name, uint32_t flags)
{
    (void)target;
    (void)name;
    (void)flags;
    if (static_cast<int32_t>(klass) >= 11) {
        return true;
    }
    // the original builds {target, enabled, name copy, flags} on the stack and inserts it (0x704060) into TreeOf(klass)
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00704450 score ?  (the argument is a string record; each tree entry gets a copy of it)
void cSC4Simulator::Slot24_ab2e68()
{
    for (int32_t i = 0; i < 11; ++i) {
        AgentTree_ab2fb8* tree = TreeOf_ab2fb8(this, i);
        AgentNode_ab2fb8* header = tree->mpHeader;
        for (AgentNode_ab2fb8* n = header->mpLeft; n != header; n = NextAgent_ab2fb8(n)) {
            (void)n;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00704060 score ?  (map insert_unique for the agent trees: finds the place by key, then 0x703b90 links a new node)
void Fn00704060Draft_ab2fb8(AgentTree_ab2fb8* tree, const uint32_t* key, AgentNode_ab2fb8** outNode, uint8_t* outInserted)
{
    AgentNode_ab2fb8* header = tree->mpHeader;
    AgentNode_ab2fb8* y = header;
    AgentNode_ab2fb8* x = header->mpParent;
    bool less = true;
    while (x) {
        y = x;
        less = *key < x->mnKey;
        x = less ? x->mpLeft : x->mpRight;
    }
    AgentNode_ab2fb8* j = y;
    if (less) {
        if (y == header->mpLeft) {
            *outNode = y;
            *outInserted = 1;
            return;
        }
        j = NextAgent_ab2fb8(y);
    }
    *outNode = j;
    *outInserted = (j->mnKey < *key) ? 1 : 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00703b90 score ?  (links a new node under a parent, left or right, and keeps leftmost/rightmost)
void Fn00703b90Draft_ab2fb8(AgentTree_ab2fb8* tree, AgentNode_ab2fb8* parent, const uint32_t* key, bool left)
{
    AgentNode_ab2fb8* header = tree->mpHeader;
    AgentNode_ab2fb8* node = 0;
    (void)key;
    (void)left;
    (void)parent;
    (void)header;
    (void)node;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00703d40 score ?  (a tail call to slot 26 of the date at +0xf0; the value it returns is lost in the void declaration)
void cSC4Simulator::Slot08_ab2e68()
{
    DateOf_ab2fb8(this)->GetDayOfYear();
}
#endif
