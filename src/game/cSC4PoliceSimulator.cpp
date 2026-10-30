#include <cstddef>
#include "classes/cSC4PoliceSimulator.h"
#include "game/Globals.h"
#include "gzcom/cRZString.h"

// A field of this object by its offset (the class header has the bytes unnamed).
#define FLD_ab23fc(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

// A node of the circular lists the simulator keeps (head node = the list object's first word).
struct Node_ab23fc {
    Node_ab23fc* mpNext;
    Node_ab23fc* mpPrev;
    uint32_t mValue;
};

// STUB: 0x00413dd0
Node_ab23fc* OB_STDCALL Fn00413dd0(uint32_t count, uint32_t hint);

struct List_ab23fc {
    Node_ab23fc* mpHead;
    void PushBack(uint32_t* pValue);
};

// FUNCTION: 0x00467b50
void List_ab23fc::PushBack(uint32_t* pValue)
{
    Node_ab23fc* head = mpHead;
    Node_ab23fc* node = Fn00413dd0(1, 0);
    uint32_t* pv = &node->mValue;
    if (pv) {
        *pv = *pValue;
    }
    Node_ab23fc* prev = head->mpPrev;
    node->mpNext = head;
    node->mpPrev = prev;
    prev->mpNext = node;
    head->mpPrev = node;
}

// The object whose slot 6 hands out the object the helpers below query.
struct OB_NOVTABLE Msg_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    
    virtual struct Obj3_ab23fc* Get06_ab23fc() = 0;
};

// The simulator seen through its own slots with their real signatures.
struct OB_NOVTABLE Self_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); virtual void Pad22_ab23fc(); virtual void Pad23_ab23fc(); 
    virtual void Pad24_ab23fc(); virtual void Pad25_ab23fc(); virtual void Pad26_ab23fc(); virtual void Pad27_ab23fc(); virtual void Pad28_ab23fc(); virtual void Pad29_ab23fc(); 
    virtual void Pad30_ab23fc(); virtual void Pad31_ab23fc(); virtual void Pad32_ab23fc(); 
    virtual bool Slot33_ab23fc(uint32_t a) = 0;
    virtual void Pad34_ab23fc(); virtual void Pad35_ab23fc(); 
    
    virtual void Slot36_ab23fc(uint32_t a, uint32_t b) = 0;
};

// What the city's slot 72 hands out.
struct OB_NOVTABLE Disaster_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); 
    virtual bool Slot10_ab23fc() = 0;
};

struct OB_NOVTABLE Del_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc();
    virtual void Delete04_ab23fc(uint32_t flag) = 0;
};

// The chain Slot15 walks: object at +0x6c -> its slot 50 -> its slot 7 -> its slot 26 (a tick count).
struct OB_NOVTABLE Chain3_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); virtual void Pad22_ab23fc(); virtual void Pad23_ab23fc(); 
    virtual void Pad24_ab23fc(); virtual void Pad25_ab23fc(); 
    virtual uint32_t Get26_ab23fc() = 0;
};
struct OB_NOVTABLE Chain2_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); 
    virtual uint32_t Get07_ab23fc() = 0;
};
struct OB_NOVTABLE Chain1_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); virtual void Pad22_ab23fc(); virtual void Pad23_ab23fc(); 
    virtual void Pad24_ab23fc(); virtual void Pad25_ab23fc(); virtual void Pad26_ab23fc(); virtual void Pad27_ab23fc(); virtual void Pad28_ab23fc(); virtual void Pad29_ab23fc(); 
    virtual void Pad30_ab23fc(); virtual void Pad31_ab23fc(); virtual void Pad32_ab23fc(); virtual void Pad33_ab23fc(); virtual void Pad34_ab23fc(); virtual void Pad35_ab23fc(); 
    virtual void Pad36_ab23fc(); virtual void Pad37_ab23fc(); virtual void Pad38_ab23fc(); virtual void Pad39_ab23fc(); virtual void Pad40_ab23fc(); virtual void Pad41_ab23fc(); 
    virtual void Pad42_ab23fc(); virtual void Pad43_ab23fc(); virtual void Pad44_ab23fc(); virtual void Pad45_ab23fc(); virtual void Pad46_ab23fc(); virtual void Pad47_ab23fc(); 
    virtual void Pad48_ab23fc(); virtual void Pad49_ab23fc(); 
    virtual uint32_t Get50_ab23fc() = 0;
};

// STUB: 0x005fd480
bool Fn005fd480(void* obj, uint32_t iid, void* out);
// STUB: 0x005fe3c0
void Fn005fe3c0(void* obj, uint32_t iid, uint32_t value);

// The protection simulator at +8 (the subobject these methods hand to the shared list helper).
struct Prot_ab23fc {
    // STUB: 0x006dfc70
    bool CopyOccupantList(uint32_t a, void* list);
    // STUB: 0x006f6a70
    void Fn006f6a70(uint32_t a);
    // STUB: 0x006f56f0
    bool Fn006f56f0();
};

// What the object a message hands out offers at its slot 3.
struct OB_NOVTABLE Obj3_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); 
    virtual uint32_t Slot03_ab23fc(uint32_t id) = 0;
};

// Methods whose slot the base class declares with another signature than the original's code has: the
// original's real signature, written on a view of the object (this = the original's ecx).
struct Fix_ab23fc {
    uint32_t Slot24_ab2348();
    uint32_t Slot35_ab2348();
    uint32_t Slot22_ab2348(uint32_t a);
    uint32_t Slot33_ab2348(uint32_t a);
    bool Slot42_ab2348(uint32_t a);
    bool Slot17_ab2348(uint32_t a);
    int32_t Slot27_ab2348();
    uint32_t Slot26_ab2348();
    bool Slot12_ab2b10(uint32_t a, uint32_t b);
    void Slot11_ab2348(uint32_t a);
    void Slot09_ab2b10(uint32_t a);
    void Slot17_ab2b10();
    bool Slot07_ab0fb0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
    bool Slot11_ab2b10(uint32_t a, uint32_t b);
    bool Slot07_ab2348(uint32_t a, uint32_t b, uint32_t c);
    bool Slot20_ab2348(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
    int32_t Slot37_ab2348(uint32_t a);
    bool Slot14_ab2b10(uint32_t a, uint32_t b);
    void Slot06_ab2b10();
    void Slot08_ab2b10(uint32_t a);
    void Slot07_ab2b10(uint32_t a);
    bool Slot03_ab2b10(uint32_t msg);
};

// A record the object at +0x6c / +0x74 fills in (eight words; the callers read words 4 and 7).
struct Rec_ab23fc {
    uint32_t w[8];
};

// The object at +0x6c / +0x74: its slot 51 looks a record up.
struct OB_NOVTABLE Q_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); virtual void Pad22_ab23fc(); virtual void Pad23_ab23fc(); 
    virtual void Pad24_ab23fc(); virtual void Pad25_ab23fc(); virtual void Pad26_ab23fc(); virtual void Pad27_ab23fc(); virtual void Pad28_ab23fc(); virtual void Pad29_ab23fc(); 
    virtual void Pad30_ab23fc(); virtual void Pad31_ab23fc(); virtual void Pad32_ab23fc(); virtual void Pad33_ab23fc(); virtual void Pad34_ab23fc(); virtual void Pad35_ab23fc(); 
    virtual void Pad36_ab23fc(); virtual void Pad37_ab23fc(); virtual void Pad38_ab23fc(); virtual void Pad39_ab23fc(); virtual void Pad40_ab23fc(); virtual void Pad41_ab23fc(); 
    virtual void Pad42_ab23fc(); virtual void Pad43_ab23fc(); virtual void Pad44_ab23fc(); virtual void Pad45_ab23fc(); virtual void Pad46_ab23fc(); virtual void Pad47_ab23fc(); 
    virtual void Pad48_ab23fc(); virtual void Pad49_ab23fc(); virtual void Pad50_ab23fc(); 
    virtual bool Slot51_ab23fc(void* obj, uint32_t index, Rec_ab23fc* out) = 0;
};

// A vector of words as the helpers below receive it from the query function.
struct Vec_ab23fc {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
};

// STUB: 0x005ff510
bool Fn005ff510(void* obj, uint32_t iid, void* out);
// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// An object released through its slot 2; the one at +0xc8 also has a non-virtual shutdown.
struct OB_NOVTABLE Rel_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); 
    virtual uint32_t Release_ab23fc() = 0;
    // STUB: 0x006ac860
    bool Fn006ac860();
};

// The city's occupant manager: slot 48 hands out a list of occupants into the list it is given.
struct OB_NOVTABLE OccMgr_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); virtual void Pad22_ab23fc(); virtual void Pad23_ab23fc(); 
    virtual void Pad24_ab23fc(); virtual void Pad25_ab23fc(); virtual void Pad26_ab23fc(); virtual void Pad27_ab23fc(); virtual void Pad28_ab23fc(); virtual void Pad29_ab23fc(); 
    virtual void Pad30_ab23fc(); virtual void Pad31_ab23fc(); virtual void Pad32_ab23fc(); virtual void Pad33_ab23fc(); virtual void Pad34_ab23fc(); virtual void Pad35_ab23fc(); 
    virtual void Pad36_ab23fc(); virtual void Pad37_ab23fc(); virtual void Pad38_ab23fc(); virtual void Pad39_ab23fc(); virtual void Pad40_ab23fc(); virtual void Pad41_ab23fc(); 
    virtual void Pad42_ab23fc(); virtual void Pad43_ab23fc(); virtual void Pad44_ab23fc(); virtual void Pad45_ab23fc(); virtual void Pad46_ab23fc(); virtual void Pad47_ab23fc(); 
    
    virtual void Slot48_ab23fc(void* list) = 0;
};

// STUB: 0x009133da
void* Fn009133da(uint32_t size);

// The 0x2c-byte message object the allocator hands out; only the slots used here are named.
struct M_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void AddRef_ab23fc();
    virtual void Release_ab23fc();
    virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); 
    virtual void Set05_ab23fc(uint32_t);
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    
    virtual void Set12_ab23fc(uint32_t);
    virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); virtual void Pad22_ab23fc(); virtual void Pad23_ab23fc(); 
    virtual void Pad24_ab23fc(); virtual void Pad25_ab23fc(); virtual void Pad26_ab23fc(); virtual void Pad27_ab23fc(); virtual void Pad28_ab23fc(); virtual void Pad29_ab23fc(); 
    virtual void Pad30_ab23fc(); virtual void Pad31_ab23fc(); virtual void Pad32_ab23fc(); 
    virtual void Set33_ab23fc(uint32_t);
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    M_ab23fc();
    static void* operator new(size_t size) { return Fn009133da(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// The simulator's own slot 22, as the ab2b10 methods reach it from their subobject.
struct OB_NOVTABLE Self22_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); 
    virtual bool Slot22_ab23fc(uint32_t a) = 0;
};

// Any object with a QueryInterface in slot 0 and a Release in slot 2.
struct OB_NOVTABLE Unk_ab23fc {
    virtual bool QueryInterface_ab23fc(uint32_t iid, void* out) = 0;
    virtual void Pad01_ab23fc();
    virtual uint32_t Release_ab23fc() = 0;
};

// What the global at 0xb43dc0 offers at its slot 12 (set a value by key).
struct OB_NOVTABLE G43dc0_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    
    virtual void Set12_ab23fc(uint32_t key, int32_t value) = 0;
};

// STUB: 0x006f6250
struct ProtB_ab23fc {
    // STUB: 0x006f6250
    void Fn006f6250(uint32_t a);
};

// GLOBAL: 0x00b43dc0
extern G43dc0_ab23fc* gpB43dc0_ab23fc;

// The simulator's slots 36 and 41 with their real signatures.
struct OB_NOVTABLE Self2_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); virtual void Pad22_ab23fc(); virtual void Pad23_ab23fc(); 
    virtual void Pad24_ab23fc(); virtual void Pad25_ab23fc(); virtual void Pad26_ab23fc(); virtual void Pad27_ab23fc(); virtual void Pad28_ab23fc(); virtual void Pad29_ab23fc(); 
    virtual void Pad30_ab23fc(); virtual void Pad31_ab23fc(); virtual void Pad32_ab23fc(); virtual void Pad33_ab23fc(); virtual void Pad34_ab23fc(); virtual void Pad35_ab23fc(); 
    
    virtual void Slot36_ab23fc(void* out) = 0;
    virtual void Pad37_ab23fc(); virtual void Pad38_ab23fc(); virtual void Pad39_ab23fc(); virtual void Pad40_ab23fc(); 
    virtual void Slot41_ab23fc(uint32_t value) = 0;
};

// A response curve: maps a percentage to a fraction.
struct Curve_ab23fc {
    // STUB: 0x005f4250
    float Fn005f4250(float x);
};

// GLOBAL: 0x00b49b64
extern float g00b49b64;

// The object at +0x74 seen at its slot 28 (finds a target), and that target's slot 24.
struct OB_NOVTABLE Target_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); virtual void Pad22_ab23fc(); virtual void Pad23_ab23fc(); 
    
    virtual void Slot24_ab23fc(void* obj, uint32_t b, uint32_t c) = 0;
};
struct OB_NOVTABLE Qb_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); virtual void Pad22_ab23fc(); virtual void Pad23_ab23fc(); 
    virtual void Pad24_ab23fc(); virtual void Pad25_ab23fc(); virtual void Pad26_ab23fc(); virtual void Pad27_ab23fc(); 
    virtual Target_ab23fc* Slot28_ab23fc(uint32_t key) = 0;
};

// The simulator's slot 25 (hands back a pointer to a value), reached from its ab2b10 subobject.
struct OB_NOVTABLE Self25_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc(); virtual void Pad05_ab23fc(); 
    virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc(); virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); 
    virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc(); virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc(); 
    virtual void Pad18_ab23fc(); virtual void Pad19_ab23fc(); virtual void Pad20_ab23fc(); virtual void Pad21_ab23fc(); virtual void Pad22_ab23fc(); virtual void Pad23_ab23fc(); 
    virtual void Pad24_ab23fc(); 
    virtual uint32_t* Slot25_ab23fc(void* out, uint32_t a) = 0;
};

// STUB: 0x005fd450
bool Fn005fd450(void* obj, uint32_t iid, void* out);
// STUB: 0x005fd4f0
bool Fn005fd4f0(void* obj, uint32_t iid, void* out);

struct ProtC_ab23fc {
    // STUB: 0x006f56a0
    void Fn006f56a0(void* buf, uint32_t value);
};

// GLOBAL: 0x00b0d3fc
extern float g00b0d3fc;

// FUNCTION: 0x006e0210
bool cSC4PoliceSimulator::Slot03_ab0fb0(uint32_t a)
{
    return a == 0;
}

// FUNCTION: 0x006acf70
void cSC4PoliceSimulator::Slot05_ab2b10(uint32_t a)
{
    FLD_ab23fc(float, 0xa0) = 1.0f;
    reinterpret_cast<Prot_ab23fc*>(reinterpret_cast<char*>(this) + 8)->Fn006f6a70(a);
}

// FUNCTION: 0x006e0180
void cSC4PoliceSimulator::Slot21_ab2348(uint32_t a)
{
    reinterpret_cast<Prot_ab23fc*>(reinterpret_cast<char*>(this) + 8)->CopyOccupantList(a, &FLD_ab23fc(List_ab23fc, 0x88));
}

// FUNCTION: 0x006e01a0
void cSC4PoliceSimulator::Slot32_ab2348(uint32_t a)
{
    reinterpret_cast<Prot_ab23fc*>(reinterpret_cast<char*>(this) + 8)->CopyOccupantList(a, &FLD_ab23fc(List_ab23fc, 0xd4));
}

// FUNCTION: 0x006e02d0
void cSC4PoliceSimulator::Slot15_ab2b10(uint32_t a, uint32_t b)
{
    Fn005fe3c0(OB_PTR(Msg_ab23fc, a)->Get06_ab23fc(), 0x48d71ed7, b);
}

// FUNCTION: 0x006e02f0
void cSC4PoliceSimulator::Slot10_ab2b10(uint32_t a, uint32_t b)
{
    Fn005fe3c0(OB_PTR(Msg_ab23fc, a)->Get06_ab23fc(), 0x48d71ed8, b);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006ad1b0 score 1
void cSC4PoliceSimulator::Slot02_ab2348()
{
    if (FLD_ab23fc(int32_t, 0xc4) > 1) {
        FLD_ab23fc(int32_t, 0xc4) = FLD_ab23fc(int32_t, 0xc4) - 1;
        return;
    }
    Slot04_ab2348();
    reinterpret_cast<Del_ab23fc*>(reinterpret_cast<char*>(this) + 8)->Delete04_ab23fc(1);
}
#endif

// FUNCTION: 0x006e0f60
float cSC4PoliceSimulator::Slot23_ab2348(uint32_t a)
{
    float buf[6];
    if (reinterpret_cast<cUnk00ab2b10_0*>(reinterpret_cast<char*>(this) + 8)->Slot12_ab2b10(a, OB_ADDR(buf))) {
        return buf[2];
    }
    return 0.0f;
}

// FUNCTION: 0x006e0140
uint32_t cSC4PoliceSimulator::Slot15_ab2348()
{
    if (FLD_ab23fc(uint32_t, 0xa8) != 0) {
        return OB_PTR(Chain3_ab23fc, OB_PTR(Chain2_ab23fc, OB_PTR(Chain1_ab23fc, FLD_ab23fc(uint32_t, 0x6c))->Get50_ab23fc())->Get07_ab23fc())->Get26_ab23fc() - FLD_ab23fc(uint32_t, 0xa8);
    }
    return 0xffffffff;
}

// FUNCTION: 0x006e0c00
bool cSC4PoliceSimulator::Slot11_ab0fb0(uint32_t /*a*/, uint32_t b, uint32_t c, uint32_t d, uint32_t /*e*/)
{
    Disaster_ab23fc* layer = OB_PTR(Disaster_ab23fc, gpB43cec->GetDisasterLayer());
    bool flag = layer->Slot10_ab23fc();
    *OB_PTR(uint32_t, b) = flag ? 0x4207 : 0x4228;
    OB_PTR(uint32_t, c)[0] = 0;
    OB_PTR(uint32_t, c)[1] = 0;
    OB_PTR(uint32_t, c)[2] = 0;
    *OB_PTR(uint32_t, d) = 0x11882;
    return true;
}

// FUNCTION: 0x006e1070
bool cSC4PoliceSimulator::Slot39_ab2348(uint32_t a)
{
    if (a) {
        if (reinterpret_cast<Self_ab23fc*>(this)->Slot33_ab23fc(a)) {
            Node_ab23fc* head = FLD_ab23fc(List_ab23fc, 0x164).mpHead;
            Node_ab23fc* p = head->mpNext;
            if (p != head) {
                do {
                    if (a == p->mValue) {
                        break;
                    }
                    p = p->mpNext;
                } while (p != head);
            }
            return p != head;
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e0b30 score 10
void cSC4PoliceSimulator::Slot36_ab2348(uint32_t a)
{
    int32_t n = FLD_ab23fc(int32_t, 0xe0);
    int32_t d = FLD_ab23fc(int32_t, 0xd8);
    float t;
    const uint32_t* pr;
    if (n <= d) {
        t = static_cast<float>(n) / d;
        pr = reinterpret_cast<const uint32_t*>(&t);
    } else {
        pr = reinterpret_cast<const uint32_t*>(&g00b0d3fc);
    }
    *OB_PTR(uint32_t, a) = *pr;
}
#endif

// FUNCTION: 0x006ada30
uint32_t Fix_ab23fc::Slot24_ab2348()
{
    uint32_t n = 0;
    Node_ab23fc* head = reinterpret_cast<List_ab23fc*>(reinterpret_cast<char*>(this) + 0x88)->mpHead;
    for (Node_ab23fc* p = head->mpNext; p != head; p = p->mpNext) {
        ++n;
    }
    return n;
}

// FUNCTION: 0x006e14b0
uint32_t Fix_ab23fc::Slot35_ab2348()
{
    uint32_t n = 0;
    Node_ab23fc* head = reinterpret_cast<List_ab23fc*>(reinterpret_cast<char*>(this) + 0xd4)->mpHead;
    for (Node_ab23fc* p = head->mpNext; p != head; p = p->mpNext) {
        ++n;
    }
    return n;
}

// FUNCTION: 0x006e01c0
uint32_t Fix_ab23fc::Slot22_ab2348(uint32_t a)
{
    return OB_PTR(Msg_ab23fc, a)->Get06_ab23fc()->Slot03_ab23fc(0x48d71ed2);
}

// FUNCTION: 0x006e01e0
uint32_t Fix_ab23fc::Slot33_ab2348(uint32_t a)
{
    return OB_PTR(Msg_ab23fc, a)->Get06_ab23fc()->Slot03_ab23fc(0x48d71ee0);
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e08a0 score 2
bool Fix_ab23fc::Slot42_ab2348(uint32_t a)
{
    List_ab23fc* list = reinterpret_cast<List_ab23fc*>(reinterpret_cast<char*>(this) + 0x164);
    if (list->mpHead->mpNext != list->mpHead) {
        return reinterpret_cast<Prot_ab23fc*>(reinterpret_cast<char*>(this) + 8)->CopyOccupantList(a, list);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006f6f30 score 21
bool Fix_ab23fc::Slot17_ab2348(uint32_t a)
{
    uint32_t v = 0;
    if (Fn005fd480(OB_PTR(Msg_ab23fc, a)->Get06_ab23fc(), 0xeaa69f83, &v)) {
        return v != 0;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e0a00 score 12
int32_t Fix_ab23fc::Slot27_ab2348()
{
    int32_t t = static_cast<int32_t>(static_cast<float>(*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(this) + 0xd8)) * *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xfc));
    int32_t cur = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(this) + 0xe0);
    int32_t r = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(this) + 0xf4);
    *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(this) + 0xf4) = 0;
    if (cur >= t) {
        r = r - t + cur;
        *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(this) + 0xe0) = t;
    }
    return r;
}
#endif

// FUNCTION: 0x006e1520
uint32_t cSC4PoliceSimulator::Slot44_ab2348(uint32_t a)
{
    uint32_t r = 0;
    Vec_ab23fc v;
    v.mpBegin = 0;
    v.mpEnd = 0;
    v.mpCap = 0;
    if (Fn005ff510(OB_PTR(Msg_ab23fc, a)->Get06_ab23fc(), 0x8a70a0b9, &v)) {
        r = v.mpBegin[0];
    }
    if (v.mpBegin) {
        Fn0090cf63(v.mpBegin);
    }
    return r;
}

// FUNCTION: 0x006e14d0
uint32_t cSC4PoliceSimulator::Slot43_ab2348(uint32_t a)
{
    uint32_t r = 0;
    Vec_ab23fc v;
    v.mpBegin = 0;
    v.mpEnd = 0;
    v.mpCap = 0;
    if (Fn005ff510(OB_PTR(Msg_ab23fc, a)->Get06_ab23fc(), 0x8a70a0b9, &v)) {
        r = v.mpBegin[1];
    }
    if (v.mpBegin) {
        Fn0090cf63(v.mpBegin);
    }
    return r;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e1390 score 19
uint32_t Fix_ab23fc::Slot26_ab2348()
{
    uint32_t sum = 0;
    List_ab23fc* list = reinterpret_cast<List_ab23fc*>(reinterpret_cast<char*>(this) + 0x88);
    for (Node_ab23fc* p = list->mpHead->mpNext; p != list->mpHead; p = p->mpNext) {
        uint32_t x = 0;
        if (Fn005fd480(OB_PTR(Msg_ab23fc, p->mValue)->Get06_ab23fc(), 0x48d71ed5, &x)) {
            sum += x;
        }
    }
    return sum;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e0c50 score 11
bool Fix_ab23fc::Slot11_ab2b10(uint32_t a, uint32_t b)
{
    Obj3_ab23fc* obj = OB_PTR(Msg_ab23fc, a)->Get06_ab23fc();
    if (b) {
        Rec_ab23fc rec;
        rec.w[7] = 0;
        if (!OB_PTR(Q_ab23fc, *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) + 0x6c))->Slot51_ab23fc(obj, *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) + 0xa8), &rec)) {
            return false;
        }
        *OB_PTR(uint32_t, b) = rec.w[4];
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x006e08d0
bool Fix_ab23fc::Slot07_ab2348(uint32_t a, uint32_t b, uint32_t c)
{
    Rec_ab23fc rec;
    rec.w[7] = 0;
    if (!OB_PTR(Q_ab23fc, *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) + 0x74))->Slot51_ab23fc(OB_PTR(Msg_ab23fc, a)->Get06_ab23fc(), *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) + 0xb0), &rec)) {
        return false;
    }
    if (c) {
        *OB_PTR(uint32_t, c) = rec.w[7];
    }
    if (b) {
        *OB_PTR(uint32_t, b) = rec.w[4];
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e0060 score 4
bool cSC4PoliceSimulator::Slot00_ab2348(uint32_t iid, uint32_t out)
{
    void** pp = OB_PTR(void*, out);
    switch (iid) {
    case 1:
    case 0x67659895:
        *pp = this;
        Slot01_ab2348();
        return true;
    case 0x452294aa:
        *pp = static_cast<cUnk00ab2b10_0*>(this);
        Slot01_ab2348();
        return true;
    case 0xc9c00435:
        *pp = static_cast<cSC4PoliceSimulator_10*>(this);
        Slot01_ab2348();
        return true;
    case 0xe4fda3d4:
        *pp = static_cast<cUnk00ab0fb0*>(this);
        Slot01_ab2348();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e0220 score 41
bool Fix_ab23fc::Slot07_ab0fb0(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Obj3_ab23fc* m = OB_PTR(Msg_ab23fc, a)->Get06_ab23fc();
    uint32_t x;
    if (!Fn005fd480(m, 0x48d71ed5, &x)) {
        return false;
    }
    if (d) {
        *OB_PTR(uint32_t, d) = x;
    }
    if (b) {
        uint32_t y;
        if (!Fn005fd480(m, 0x48d71ed8, &y)) {
            return false;
        }
        y = y & ((1u << x) - 1);
        *OB_PTR(uint32_t, b) = y;
    }
    if (c) {
        uint32_t z;
        if (!Fn005fd480(m, 0x48d71ed7, &z)) {
            return false;
        }
        *OB_PTR(uint32_t, c) = z;
    }
    return true;
}
#endif

// FUNCTION: 0x006e0310
bool cSC4PoliceSimulator::Slot04_ab2348()
{
    if (FLD_ab23fc(bool, 0xc0)) {
        FLD_ab23fc(bool, 0xc0) = false;
        if (FLD_ab23fc(Rel_ab23fc*, 0xc8)) {
            FLD_ab23fc(Rel_ab23fc*, 0xc8)->Fn006ac860();
            if (FLD_ab23fc(Rel_ab23fc*, 0xc8)) {
                Rel_ab23fc* t = FLD_ab23fc(Rel_ab23fc*, 0xc8);
                FLD_ab23fc(Rel_ab23fc*, 0xc8) = 0;
                t->Release_ab23fc();
            }
        }
        if (FLD_ab23fc(cIGZMessageServer2*, 0x70)) {
            FLD_ab23fc(cIGZMessageServer2*, 0x70)->RemoveNotification(reinterpret_cast<char*>(this) + 8, 0xa159d95);
        }
        reinterpret_cast<Prot_ab23fc*>(reinterpret_cast<char*>(this) + 8)->Fn006f56f0();
        OccMgr_ab23fc* om = OB_PTR(OccMgr_ab23fc, gpB43cec->GetOccupantManager());
        om->Slot48_ab23fc(&FLD_ab23fc(List_ab23fc, 0xd4));
        om->Slot48_ab23fc(&FLD_ab23fc(uint8_t, 0xf8));
        om->Slot48_ab23fc(&FLD_ab23fc(List_ab23fc, 0x164));
        if (FLD_ab23fc(Rel_ab23fc*, 0xcc)) {
            FLD_ab23fc(Rel_ab23fc*, 0xcc)->Release_ab23fc();
            FLD_ab23fc(Rel_ab23fc*, 0xcc) = 0;
        }
        if (FLD_ab23fc(Rel_ab23fc*, 0x7c)) {
            FLD_ab23fc(Rel_ab23fc*, 0x7c)->Release_ab23fc();
            FLD_ab23fc(Rel_ab23fc*, 0x7c) = 0;
        }
        if (FLD_ab23fc(Rel_ab23fc*, 0xd0)) {
            FLD_ab23fc(Rel_ab23fc*, 0xd0)->Release_ab23fc();
            FLD_ab23fc(Rel_ab23fc*, 0xd0) = 0;
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e0830 score 14
bool cSC4PoliceSimulator::Slot13_ab2348()
{
    if (!FLD_ab23fc(bool, 0xa4)) {
        return false;
    }
    FLD_ab23fc(bool, 0xa4) = false;
    FLD_ab23fc(uint32_t, 0xa8) = 0;
    M_ab23fc* m = new M_ab23fc();
    if (m) {
        m->AddRef_ab23fc();
        m->Set05_ab23fc(0xa8daf512);
    }
    FLD_ab23fc(cIGZMessageServer2*, 0x70)->MessagePost(m, false);
    m->Release_ab23fc();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e0780 score 18
bool cSC4PoliceSimulator::Slot12_ab2348(uint32_t a)
{
    if (FLD_ab23fc(bool, 0xa4)) {
        return false;
    }
    FLD_ab23fc(bool, 0xa4) = true;
    FLD_ab23fc(uint32_t, 0xa8) = OB_PTR(Chain3_ab23fc, OB_PTR(Chain2_ab23fc, OB_PTR(Chain1_ab23fc, FLD_ab23fc(uint32_t, 0x6c))->Get50_ab23fc())->Get07_ab23fc())->Get26_ab23fc();
    M_ab23fc* m = new M_ab23fc();
    if (m) {
        m->AddRef_ab23fc();
        m->Set05_ab23fc(0xa8daf511);
        m->Set12_ab23fc(a);
        m->Set33_ab23fc(a);
    }
    FLD_ab23fc(cIGZMessageServer2*, 0x70)->MessagePost(m, false);
    m->Release_ab23fc();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e0b80 score 4
void Fix_ab23fc::Slot09_ab2b10(uint32_t a)
{
    reinterpret_cast<ProtB_ab23fc*>(this)->Fn006f6250(a);
    Self22_ab23fc* self = reinterpret_cast<Self22_ab23fc*>(reinterpret_cast<char*>(this) - 8);
    if (self->Slot22_ab23fc(a)) {
        M_ab23fc* m = new M_ab23fc();
        if (m) {
            m->AddRef_ab23fc();
            m->Set05_ab23fc(0xa949569a);
            m->Set33_ab23fc(OB_ADDR(self));
        }
        (*reinterpret_cast<cIGZMessageServer2**>(reinterpret_cast<char*>(this) + 0x68))->MessagePost(m, false);
        m->Release_ab23fc();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e0610 score 9
void Fix_ab23fc::Slot17_ab2b10()
{
    uint32_t local = 0;
    reinterpret_cast<Unk_ab23fc*>(reinterpret_cast<char*>(this) - 8)->QueryInterface_ab23fc(1, &local);
    gpB43dc0_ab23fc->Set12_ab23fc(0x4a11d354, static_cast<int32_t>(*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x94) * 100.0f));
    gpB43dc0_ab23fc->Set12_ab23fc(0x4a11d355, static_cast<int32_t>(*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x90)));
    M_ab23fc* m = new M_ab23fc();
    if (m) {
        m->AddRef_ab23fc();
        m->Set05_ab23fc(0xa8daf510);
        m->Set12_ab23fc(local);
        m->Set33_ab23fc(local);
    }
    (*reinterpret_cast<cIGZMessageServer2**>(reinterpret_cast<char*>(this) + 0x68))->MessagePost(m, false);
    m->Release_ab23fc();
    if (local) {
        OB_PTR(Unk_ab23fc, local)->Release_ab23fc();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e0f90 score 89
void cSC4PoliceSimulator::Slot11_ab2348(uint32_t a)
{
    float acc = g00b49b64;
    if (FLD_ab23fc(bool, 0xa4)) {
        *OB_PTR(float, a) = g00b0d3fc;
        return;
    }
    Node_ab23fc* head = FLD_ab23fc(List_ab23fc, 0x88).mpHead;
    for (Node_ab23fc* p = head->mpNext; p != head; p = p->mpNext) {
        float f = g00b0d3fc;
        Rec_ab23fc rec;
        rec.w[7] = 0;
        if (OB_PTR(Q_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot51_ab23fc(OB_PTR(Msg_ab23fc, p->mValue)->Get06_ab23fc(), FLD_ab23fc(uint32_t, 0xb0), &rec)) {
            f = *reinterpret_cast<float*>(&rec.w[7]);
            float v = reinterpret_cast<Curve_ab23fc*>(&FLD_ab23fc(uint8_t, 0x134))->Fn005f4250(f * 100.0f) * 0.01f;
            acc = acc + v - acc * v;
        }
    }
    *OB_PTR(float, a) = acc;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e11f0 score 2
void cSC4PoliceSimulator::Fn006e11f0()
{
    Node_ab23fc* head = FLD_ab23fc(List_ab23fc, 0x164).mpHead;
    Node_ab23fc* p = head->mpNext;
    if (p != head) {
        do {
            uint32_t v = p->mValue;
            p = p->mpNext;
            float f;
            reinterpret_cast<Self2_ab23fc*>(this)->Slot36_ab23fc(&f);
            if (f <= FLD_ab23fc(float, 0x160)) {
                reinterpret_cast<Self2_ab23fc*>(this)->Slot41_ab23fc(v);
            }
        } while (p != FLD_ab23fc(List_ab23fc, 0x164).mpHead);
    }
}
#endif

// FUNCTION: 0x006ad530
bool cSC4PoliceSimulator::Slot08_ab2348(uint32_t a, uint32_t b)
{
    Rec_ab23fc rec;
    rec.w[7] = 0;
    if (!OB_PTR(Q_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot51_ab23fc(OB_PTR(Msg_ab23fc, a)->Get06_ab23fc(), FLD_ab23fc(uint32_t, 0xb0), &rec)) {
        return false;
    }
    Target_ab23fc* t = OB_PTR(Qb_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot28_ab23fc(rec.w[0]);
    if (!t) {
        return false;
    }
    t->Slot24_ab23fc(OB_PTR(Msg_ab23fc, a)->Get06_ab23fc(), b, FLD_ab23fc(uint32_t, 0xb0));
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e0cb0 score 13
bool Fix_ab23fc::Slot12_ab2b10(uint32_t a, uint32_t b)
{
    Obj3_ab23fc* o = OB_PTR(Msg_ab23fc, a)->Get06_ab23fc();
    uint32_t* buf = OB_PTR(uint32_t, b);
    buf[0] = 0;
    buf[1] = 0;
    buf[3] = 0;
    Fn005fd450(o, 0x48d71ed9, &buf[3]);
    if (!buf[3]) {
        return false;
    }
    Fn005fd450(o, 0x48d71eda, &buf[4]);
    Fn005fd4f0(o, 0x48d71edb, &buf[2]);
    buf[5] = buf[3];
    uint32_t tmp;
    uint32_t* r = reinterpret_cast<Self25_ab23fc*>(reinterpret_cast<char*>(this) - 8)->Slot25_ab23fc(&tmp, a);
    reinterpret_cast<ProtC_ab23fc*>(this)->Fn006f56a0(buf, *r);
    return true;
}
#endif

// ---- wave 11b: remainders ----
struct OB_NOVTABLE OccB_ab23fc {
    virtual bool QI_ab23fc(uint32_t iid, void* out) = 0;
    virtual void AddRef_ab23fc() = 0;
    virtual uint32_t Release_ab23fc() = 0;
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void* Props_ab23fc() = 0;
    virtual void Pad07_ab23fc();
    virtual void Pos_ab23fc(void* out) = 0;
};
struct OB_NOVTABLE TgtX_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual float* Slot10_ab23fc() = 0;
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual void Pad18_ab23fc();
    virtual void Pad19_ab23fc();
    virtual void Pad20_ab23fc();
    virtual void Pad21_ab23fc();
    virtual void Slot22_ab23fc(void* props, uint32_t key) = 0;
    virtual void Pad23_ab23fc();
    virtual void Pad24_ab23fc();
    virtual void Pad25_ab23fc();
    virtual void Pad26_ab23fc();
    virtual void Pad27_ab23fc();
    virtual bool Has28_ab23fc(void* obj, uint32_t key) = 0;
};
struct OB_NOVTABLE SelfS_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual bool Slot10_ab23fc() = 0;
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual bool Slot17_ab23fc(uint32_t a) = 0;
};

// A forward iterator of the circular lists (a class with a constructor: returned through a hidden pointer).
struct It_ab23fc {
    Node_ab23fc* mpNode;
    It_ab23fc(Node_ab23fc* n) : mpNode(n) {}
};
// STUB: 0x004dc710
It_ab23fc Fn004dc710(It_ab23fc first, It_ab23fc last, const uint32_t* pValue);

struct Rand_ab23fc {
    // STUB: 0x0091372e
    double Fn0091372e();
};

struct Base_ab23fc {
    // STUB: 0x00407990
    void Fn00407990();
};

#ifdef OB_DRAFTS
// CLOSE: 0x006e0940 score 24
bool Fix_ab23fc::Slot20_ab2348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t buf[6];
    if (!reinterpret_cast<cUnk00ab2b10_0*>(reinterpret_cast<char*>(this) + 8)->Slot14_ab2b10(a, OB_ADDR(buf))) {
        return false;
    }
    *OB_PTR(float, d) = *reinterpret_cast<float*>(&buf[2]);
    uint32_t n = static_cast<uint32_t>(static_cast<float>(buf[5]) * *OB_PTR(float, b));
    if (n > buf[3]) {
        *OB_PTR(uint32_t, c) = 0;
        return true;
    }
    if (n < buf[4]) {
        *OB_PTR(float, c) = *reinterpret_cast<float*>(&buf[2]);
        return true;
    }
    *OB_PTR(float, c) = static_cast<float>(buf[3] - n) * *reinterpret_cast<float*>(&buf[2]) / static_cast<float>(buf[3] - buf[4]);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e0a40 score 39
int32_t Fix_ab23fc::Slot37_ab2348(uint32_t a)
{
    int64_t cost = 0;
    float pct = g00b49b64;
    Rec_ab23fc rec;
    rec.w[7] = 0;
    if (OB_PTR(Q_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot51_ab23fc(OB_PTR(OccB_ab23fc, a)->Props_ab23fc(), 0xea56768a, &rec)) {
        cost = *reinterpret_cast<int64_t*>(&rec.w[2]);
        pct = *reinterpret_cast<float*>(&rec.w[5]);
    }
    return static_cast<int32_t>(static_cast<double>(cost) * pct);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e06e0 score 34
void cSC4PoliceSimulator::Fn006e06e0(void* out, uint32_t obj)
{
    float v = g00b0d3fc;
    Rec_ab23fc rec;
    rec.w[7] = 0;
    if (OB_PTR(Q_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot51_ab23fc(OB_PTR(void, obj), 0xea56768a, &rec)) {
        TgtX_ab23fc* t = reinterpret_cast<TgtX_ab23fc*>(OB_PTR(Qb_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot28_ab23fc(rec.w[0]));
        if (t) {
            if (t->Has28_ab23fc(OB_PTR(void, obj), 0xea56768a)) {
                v = *reinterpret_cast<float*>(&rec.w[7]);
            } else {
                v = *t->Slot10_ab23fc();
            }
        }
    }
    *OB_PTR(float, OB_ADDR(out)) = reinterpret_cast<Curve_ab23fc*>(&FLD_ab23fc(uint8_t, 0x110))->Fn005f4250(v * 100.0f) * 0.01f;
}
#endif

// FUNCTION: 0x006e0ac0
uint32_t cSC4PoliceSimulator::Slot28_ab2348(uint32_t a)
{
    void* p = OB_PTR(OccB_ab23fc, a)->Props_ab23fc();
    float f;
    Fn006e06e0(&f, OB_ADDR(p));
    uint32_t cnt = 0;
    Fn005fd480(p, 0x48d71ee0, &cnt);
    float r = static_cast<float>(cnt) * f + 12582912.0f;
    return *reinterpret_cast<uint32_t*>(&r) - 0x4b400000u;
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e10c0 score 68
void cSC4PoliceSimulator::Fn006e10c0(void* out, uint32_t obj)
{
    float v = g00b49b64;
    if (obj) {
        if (reinterpret_cast<Self_ab23fc*>(this)->Slot33_ab23fc(obj)) {
            if (FLD_ab23fc(int32_t, 0xdc) > 0) {
                It_ab23fc it = Fn004dc710(It_ab23fc(FLD_ab23fc(List_ab23fc, 0x164).mpHead->mpNext), It_ab23fc(FLD_ab23fc(List_ab23fc, 0x164).mpHead), &obj);
                if (it.mpNode != FLD_ab23fc(List_ab23fc, 0x164).mpHead) {
                    v = g00b49b64;
                } else {
                    float f;
                    reinterpret_cast<Self2_ab23fc*>(this)->Slot36_ab23fc(&f);
                    f = reinterpret_cast<Curve_ab23fc*>(&FLD_ab23fc(uint8_t, 0x148))->Fn005f4250(f * 100.0f) * 0.01f;
                    v = f;
                }
            }
        }
    }
    *OB_PTR(float, OB_ADDR(out)) = v;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e1190 score 41
void cSC4PoliceSimulator::Fn006e1190()
{
    Node_ab23fc* head = FLD_ab23fc(List_ab23fc, 0xd4).mpHead;
    for (Node_ab23fc* p = head->mpNext; p != head; p = p->mpNext) {
        uint32_t obj = p->mValue;
        float f;
        Fn006e10c0(&f, obj);
        if (f > g00b49b64) {
            if (reinterpret_cast<Rand_ab23fc*>(&FLD_ab23fc(uint8_t, 0x18))->Fn0091372e() < f) {
                Slot40_ab2348(obj);
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e0e70 score 50
void cSC4PoliceSimulator::Slot25_ab2348(uint32_t out, uint32_t occ)
{
    void* p = OB_PTR(OccB_ab23fc, occ)->Props_ab23fc();
    float v = 0.0f;
    Rec_ab23fc rec;
    rec.w[7] = 0;
    if (OB_PTR(Q_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot51_ab23fc(p, FLD_ab23fc(uint32_t, 0xb0), &rec)) {
        TgtX_ab23fc* t = reinterpret_cast<TgtX_ab23fc*>(OB_PTR(Qb_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot28_ab23fc(rec.w[0]));
        if (t) {
            if (t->Has28_ab23fc(p, FLD_ab23fc(uint32_t, 0xb0))) {
                v = *reinterpret_cast<float*>(&rec.w[7]);
            } else {
                v = *t->Slot10_ab23fc();
            }
        } else {
            v = g00b0d3fc;
        }
    }
    v = reinterpret_cast<Curve_ab23fc*>(&FLD_ab23fc(uint8_t, 0x100))->Fn005f4250(v * 100.0f) * 0.01f;
    if (reinterpret_cast<SelfS_ab23fc*>(this)->Slot17_ab23fc(occ)) {
        *OB_PTR(float, out) = v * FLD_ab23fc(float, 0x128);
    } else {
        *OB_PTR(float, out) = v;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e0d50 score 8
bool Fix_ab23fc::Slot14_ab2b10(uint32_t a, uint32_t b)
{
    OccB_ab23fc* occ = OB_PTR(OccB_ab23fc, a);
    uint32_t* o = OB_PTR(uint32_t, b);
    void* p = occ->Props_ab23fc();
    o[3] = 0;
    Fn005fd450(p, 0x48d71ed0, &o[3]);
    if (!o[3]) {
        return false;
    }
    Fn005fd450(p, 0x48d71ed1, &o[4]);
    Fn005fd4f0(p, 0x48d71ed2, &o[2]);
    uint32_t pos[3];
    occ->Pos_ab23fc(pos);
    o[1] = pos[2];
    o[0] = pos[0];
    o[5] = o[3];
    uint32_t held = 0;
    float v;
    if (occ->QI_ab23fc(0xe9793a65, &held)) {
        v = reinterpret_cast<Curve_ab23fc*>(&FLD_ab23fc(uint8_t, 0xf8))->Fn005f4250(*OB_PTR(TgtX_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot10_ab23fc() * 100.0f) * 0.01f;
    } else {
        uint32_t tmp;
        v = *reinterpret_cast<float*>(reinterpret_cast<Self25_ab23fc*>(reinterpret_cast<char*>(this) - 8)->Slot25_ab23fc(&tmp, a));
    }
    reinterpret_cast<ProtC_ab23fc*>(this)->Fn006f56a0(o, *reinterpret_cast<uint32_t*>(&v));
    if (held) {
        OB_PTR(Unk_ab23fc, held)->Release_ab23fc();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e1a00 score 68
uint32_t cSC4PoliceSimulator::Slot16_ab2348(uint32_t a)
{
    if (!reinterpret_cast<SelfS_ab23fc*>(this)->Slot10_ab23fc()) {
        return 0;
    }
    uint32_t n = 0;
    Node_ab23fc* head = FLD_ab23fc(List_ab23fc, 0x88).mpHead;
    for (Node_ab23fc* p = head->mpNext; p != head; p = p->mpNext) {
        uint32_t obj = p->mValue;
        if (reinterpret_cast<SelfS_ab23fc*>(this)->Slot17_ab23fc(obj)) {
            OB_PTR(OccB_ab23fc, obj)->AddRef_ab23fc();
            OB_PTR(List_ab23fc, a)->PushBack(&obj);
            ++n;
        }
    }
    return n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e2a80 score 5
void Fix_ab23fc::Slot06_ab2b10()
{
    reinterpret_cast<Base_ab23fc*>(this)->Fn00407990();
    cSC4PoliceSimulator* self = reinterpret_cast<cSC4PoliceSimulator*>(reinterpret_cast<char*>(this) - 8);
    float x = static_cast<float>(FLD_ab23fc(int32_t, 0xd8)) * *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x124) + 12582912.0f;
    int32_t n = static_cast<int32_t>(*reinterpret_cast<uint32_t*>(&x) - 0x4b400000u);
    if (n != 0) {
        int32_t* pc = reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0xe0);
        *pc = *pc - n;
        if (*pc < 0) {
            *pc = 0;
        }
        self->Fn006e1240();
    }
    self->Fn006e2570();
    Node_ab23fc* head = FLD_ab23fc(List_ab23fc, 0xcc).mpHead;
    for (Node_ab23fc* p = head->mpNext; p != head;) {
        uint32_t obj = p->mValue;
        p = p->mpNext;
        void* props = OB_PTR(OccB_ab23fc, obj)->Props_ab23fc();
        uint32_t a0 = 0, a1 = 0, a2 = 0;
        Fn005fd480(props, 0x48d71ee0, &a0);
        Fn005fd480(props, 0x48d71ee1, &a1);
        Fn005fd480(props, 0x48d71ee4, &a2);
    }
    self->Fn006e11f0();
    self->Fn006e1190();
}
#endif

// ---- wave 11b batch 2 ----
struct OB_NOVTABLE OccC_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void AddRef_ab23fc() = 0;
    virtual uint32_t Release_ab23fc() = 0;
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void* Props_ab23fc() = 0;
    virtual uint32_t Id_ab23fc() = 0;
};
struct OB_NOVTABLE LogX_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Log10_ab23fc(const cRZString* s, void* obj, uint32_t flag) = 0;
    virtual void Pad11_ab23fc();
    virtual void Log12_ab23fc(const cRZString* s, void* obj) = 0;
};
struct OB_NOVTABLE CityX_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual void Pad18_ab23fc();
    virtual void Pad19_ab23fc();
    virtual void Pad20_ab23fc();
    virtual void Pad21_ab23fc();
    virtual void Pad22_ab23fc();
    virtual void Pad23_ab23fc();
    virtual void Pad24_ab23fc();
    virtual void Pad25_ab23fc();
    virtual void Pad26_ab23fc();
    virtual void Pad27_ab23fc();
    virtual void Pad28_ab23fc();
    virtual void Pad29_ab23fc();
    virtual void Pad30_ab23fc();
    virtual void Pad31_ab23fc();
    virtual void Pad32_ab23fc();
    virtual void Pad33_ab23fc();
    virtual void Pad34_ab23fc();
    virtual void Pad35_ab23fc();
    virtual void Pad36_ab23fc();
    virtual void Pad37_ab23fc();
    virtual void Pad38_ab23fc();
    virtual void Pad39_ab23fc();
    virtual void Pad40_ab23fc();
    virtual void Pad41_ab23fc();
    virtual void Pad42_ab23fc();
    virtual void Pad43_ab23fc();
    virtual void Pad44_ab23fc();
    virtual void Pad45_ab23fc();
    virtual void Pad46_ab23fc();
    virtual LogX_ab23fc* GetLog47_ab23fc() = 0;
};

// GLOBAL: 0x00b43cec
extern CityX_ab23fc* gpB43cec_ab23fc;
// GLOBAL: 0x00b0d3f8
extern const char* gpB0d3f8;
// GLOBAL: 0x00b0d3f4
extern const char* gpB0d3f4;

struct ListE_ab23fc {
    // STUB: 0x00413f70
    It_ab23fc Erase(It_ab23fc it);
};

struct ProtF_ab23fc {
    // STUB: 0x006f5c30
    void Fn006f5c30();
    // STUB: 0x006f64f0
    void Fn006f64f0(uint32_t a);
    // STUB: 0x006f6610
    void Fn006f6610(uint32_t a);
};

struct RandF_ab23fc {
    // STUB: 0x00913761
    double Fn00913761(double lo, double hi);
};

// FUNCTION: 0x006e2570
void cSC4PoliceSimulator::Fn006e2570()
{
    bool striking = false;
    uint32_t cnt = 0;
    Node_ab23fc* head = FLD_ab23fc(List_ab23fc, 0x88).mpHead;
    for (Node_ab23fc* p = head->mpNext; p != head; p = p->mpNext) {
        uint32_t obj = p->mValue;
        if (UpdateStrikingState(obj)) {
            striking = true;
        }
        if (reinterpret_cast<SelfS_ab23fc*>(this)->Slot17_ab23fc(obj)) {
            ++cnt;
            if (striking) {
                Slot12_ab2348(obj);
            }
        }
    }
    if (striking) {
        if (cnt == 0 && Slot10_ab2348()) {
            Slot13_ab2348();
        }
        reinterpret_cast<ProtF_ab23fc*>(reinterpret_cast<char*>(this) + 8)->Fn006f5c30();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e1240 score 49
void cSC4PoliceSimulator::Fn006e1240()
{
    Node_ab23fc* head = FLD_ab23fc(List_ab23fc, 0xd4).mpHead;
    FLD_ab23fc(int32_t, 0xd8) = 0;
    FLD_ab23fc(int32_t, 0xdc) = 0;
    for (Node_ab23fc* p = head->mpNext; p != head; p = p->mpNext) {
        FLD_ab23fc(int32_t, 0xd8) += Slot28_ab2348(p->mValue);
    }
    int32_t total = FLD_ab23fc(int32_t, 0xd8);
    float ratio = 0.0f;
    if (total > 0) {
        int32_t cur = FLD_ab23fc(int32_t, 0xe0);
        if (cur <= total) {
            ratio = static_cast<float>(cur) / total;
        } else {
            ratio = 1.0f;
        }
    }
    Node_ab23fc* h2 = FLD_ab23fc(List_ab23fc, 0xd4).mpHead;
    for (Node_ab23fc* p = h2->mpNext; p != h2; p = p->mpNext) {
        void* props = OB_PTR(OccC_ab23fc, p->mValue)->Props_ab23fc();
        uint32_t cnt = 0;
        Fn005fd480(props, 0x48d71ee0, &cnt);
        float f;
        Fn006e06e0(&f, OB_ADDR(props));
        float x = static_cast<float>(cnt) * f + 12582912.0f;
        uint32_t n = *reinterpret_cast<uint32_t*>(&x) - 0x4b400000u;
        float y = static_cast<float>(n) * ratio + 12582912.0f;
        uint32_t m = *reinterpret_cast<uint32_t*>(&y) - 0x4b400000u;
        Fn005fe3c0(props, 0x48d71ee1, m);
        FLD_ab23fc(int32_t, 0xdc) += m;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e1830 score 158
bool cSC4PoliceSimulator::UpdateStrikingState(uint32_t occ)
{
    uint32_t now = OB_PTR(Chain3_ab23fc, OB_PTR(Chain2_ab23fc, OB_PTR(Chain1_ab23fc, FLD_ab23fc(uint32_t, 0x6c))->Get50_ab23fc())->Get07_ab23fc())->Get26_ab23fc();
    uint32_t start = 0;
    OccC_ab23fc* o = OB_PTR(OccC_ab23fc, occ);
    Fn005fd480(o->Props_ab23fc(), 0xeaa69f83, &start);
    uint32_t newStart = start;
    if (start) {
        if (now - start > FLD_ab23fc(uint32_t, 0x12c)) {
            newStart = 0;
        } else {
            float f = g00b0d3fc;
            Rec_ab23fc rec;
            rec.w[7] = 0;
            if (OB_PTR(Q_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot51_ab23fc(o->Props_ab23fc(), FLD_ab23fc(uint32_t, 0xb0), &rec)) {
                f = *reinterpret_cast<float*>(&rec.w[7]);
            }
            if (!(f < FLD_ab23fc(float, 0x130))) {
                newStart = 0;
            }
        }
    } else {
        float f = g00b0d3fc;
        Rec_ab23fc rec;
        rec.w[7] = 0;
        if (OB_PTR(Q_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Slot51_ab23fc(o->Props_ab23fc(), FLD_ab23fc(uint32_t, 0xb0), &rec)) {
            f = *reinterpret_cast<float*>(&rec.w[7]);
        }
        f = reinterpret_cast<Curve_ab23fc*>(&FLD_ab23fc(uint8_t, 0x134))->Fn005f4250(f * 100.0f);
        double roll = reinterpret_cast<Rand_ab23fc*>(&FLD_ab23fc(uint8_t, 0x18))->Fn0091372e();
        if (f * 0.01f > roll) {
            newStart = now;
        }
    }
    if (newStart == start) {
        return false;
    }
    Fn005fe3c0(o->Props_ab23fc(), 0xeaa69f83, newStart);
    LogX_ab23fc* log = gpB43cec_ab23fc->GetLog47_ab23fc();
    if (log) {
        cRZString s(gpB0d3f8);
        if (newStart) {
            log->Log10_ab23fc(&s, o, 0);
        } else {
            log->Log12_ab23fc(&s, o);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e1af0 score 65
bool cSC4PoliceSimulator::Slot40_ab2348(uint32_t occ)
{
    if (!occ) {
        return false;
    }
    if (!reinterpret_cast<Self_ab23fc*>(this)->Slot33_ab23fc(occ)) {
        return false;
    }
    List_ab23fc* list = &FLD_ab23fc(List_ab23fc, 0x164);
    Node_ab23fc* head = list->mpHead;
    Node_ab23fc* n = head->mpNext;
    if (n != head) {
        do {
            if (occ == n->mValue) {
                break;
            }
            n = n->mpNext;
        } while (n != list->mpHead);
    }
    if (n != head) {
        return false;
    }
    list->PushBack(&occ);
    OB_PTR(OccC_ab23fc, occ)->AddRef_ab23fc();
    float r = static_cast<float>(reinterpret_cast<RandF_ab23fc*>(&FLD_ab23fc(uint8_t, 0x18))->Fn00913761(FLD_ab23fc(float, 0x158), FLD_ab23fc(float, 0x15c)));
    int32_t base = static_cast<int32_t>(Slot28_ab2348(occ));
    float x = static_cast<float>(base) * r + 12582912.0f;
    int32_t n2 = static_cast<int32_t>(*reinterpret_cast<uint32_t*>(&x) - 0x4b400000u);
    if (n2 != 0) {
        FLD_ab23fc(int32_t, 0xe0) -= n2;
        if (FLD_ab23fc(int32_t, 0xe0) < 0) {
            FLD_ab23fc(int32_t, 0xe0) = 0;
        }
        Fn006e1240();
    }
    M_ab23fc* m = new M_ab23fc();
    if (m) {
        m->AddRef_ab23fc();
    }
    m->Set05_ab23fc(0x2a614891);
    m->Set12_ab23fc(OB_ADDR(this));
    m->Set33_ab23fc(occ);
    FLD_ab23fc(cIGZMessageServer2*, 0x70)->MessagePost(m, false);
    LogX_ab23fc* log = gpB43cec_ab23fc->GetLog47_ab23fc();
    if (log) {
        cRZString s(gpB0d3f4);
        log->Log10_ab23fc(&s, OB_PTR(void, occ), 0);
    }
    m->Release_ab23fc();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e1c90 score 33
bool cSC4PoliceSimulator::Slot41_ab2348(uint32_t occ)
{
    if (!occ) {
        return false;
    }
    if (!reinterpret_cast<Self_ab23fc*>(this)->Slot33_ab23fc(occ)) {
        return false;
    }
    LogX_ab23fc* log = gpB43cec_ab23fc->GetLog47_ab23fc();
    if (log) {
        cRZString s(gpB0d3f4);
        log->Log12_ab23fc(&s, OB_PTR(void, occ));
    }
    List_ab23fc* list = &FLD_ab23fc(List_ab23fc, 0x164);
    Node_ab23fc* head = list->mpHead;
    Node_ab23fc* n = head->mpNext;
    if (n != head) {
        do {
            if (occ == n->mValue) {
                break;
            }
            n = n->mpNext;
        } while (n != head);
        if (n != head) {
            M_ab23fc* m = new M_ab23fc();
            if (m) {
                m->AddRef_ab23fc();
            }
            m->Set05_ab23fc(0x2a614892);
            m->Set12_ab23fc(OB_ADDR(this));
            m->Set33_ab23fc(occ);
            FLD_ab23fc(cIGZMessageServer2*, 0x70)->MessagePost(m, false);
            reinterpret_cast<ListE_ab23fc*>(list)->Erase(It_ab23fc(n));
            OB_PTR(OccC_ab23fc, occ)->Release_ab23fc();
            m->Release_ab23fc();
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e1570 score 105
void Fix_ab23fc::Slot08_ab2b10(uint32_t a)
{
    OccC_ab23fc* o = OB_PTR(OccC_ab23fc, a);
    cSC4PoliceSimulator* self = reinterpret_cast<cSC4PoliceSimulator*>(reinterpret_cast<char*>(this) - 8);
    if (o->Id_ab23fc() == 0x278128a0) {
        List_ab23fc* l1 = &FLD_ab23fc(List_ab23fc, 0xf0);
        Node_ab23fc* head = l1->mpHead;
        Node_ab23fc* n = head->mpNext;
        while (n != head && n->mValue != a) {
            n = n->mpNext;
        }
        if (n != l1->mpHead) {
            OB_PTR(OccC_ab23fc, n->mValue)->Release_ab23fc();
            reinterpret_cast<ListE_ab23fc*>(l1)->Erase(It_ab23fc(n));
        }
        List_ab23fc* l2 = &FLD_ab23fc(List_ab23fc, 0xcc);
        head = l2->mpHead;
        n = head->mpNext;
        while (n != head && n->mValue != a) {
            n = n->mpNext;
        }
        if (n != l2->mpHead) {
            o->AddRef_ab23fc();
            OB_PTR(OccC_ab23fc, n->mValue)->Release_ab23fc();
            reinterpret_cast<ListE_ab23fc*>(l2)->Erase(It_ab23fc(n));
            void* props = o->Props_ab23fc();
            Rec_ab23fc rec;
            rec.w[7] = 0;
            if (OB_PTR(Q_ab23fc, FLD_ab23fc(uint32_t, 0x6c))->Slot51_ab23fc(props, 0xea56768a, &rec)) {
                TgtX_ab23fc* t = reinterpret_cast<TgtX_ab23fc*>(OB_PTR(Qb_ab23fc, FLD_ab23fc(uint32_t, 0x6c))->Slot28_ab23fc(rec.w[0]));
                t->Slot22_ab23fc(props, 0xea56768a);
            }
            self->Fn006e1240();
            o->Release_ab23fc();
        }
    }
    reinterpret_cast<ProtF_ab23fc*>(this)->Fn006f64f0(a);
    if (reinterpret_cast<Self22_ab23fc*>(self)->Slot22_ab23fc(a)) {
        M_ab23fc* m = new M_ab23fc();
        if (m) {
            m->AddRef_ab23fc();
        }
        m->Set05_ab23fc(0xa949569a);
        m->Set33_ab23fc(OB_ADDR(self));
        (*reinterpret_cast<cIGZMessageServer2**>(reinterpret_cast<char*>(this) + 0x68))->MessagePost(m, false);
        m->Release_ab23fc();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e1db0 score 149
void Fix_ab23fc::Slot07_ab2b10(uint32_t a)
{
    OccC_ab23fc* o = OB_PTR(OccC_ab23fc, a);
    cSC4PoliceSimulator* self = reinterpret_cast<cSC4PoliceSimulator*>(reinterpret_cast<char*>(this) - 8);
    reinterpret_cast<ProtF_ab23fc*>(this)->Fn006f6610(a);
    if (o->Id_ab23fc() == 0x278128a0) {
        if (reinterpret_cast<Self22_ab23fc*>(self)->Slot22_ab23fc(a)) {
            M_ab23fc* m = new M_ab23fc();
            if (m) {
                m->AddRef_ab23fc();
            }
            m->Set05_ab23fc(0xa949569a);
            m->Set33_ab23fc(OB_ADDR(self));
            (*reinterpret_cast<cIGZMessageServer2**>(reinterpret_cast<char*>(this) + 0x68))->MessagePost(m, false);
            m->Release_ab23fc();
        }
        if (reinterpret_cast<Self_ab23fc*>(self)->Slot33_ab23fc(a)) {
            void* props = o->Props_ab23fc();
            o->AddRef_ab23fc();
            FLD_ab23fc(List_ab23fc, 0xcc).PushBack(&a);
            Rec_ab23fc rec;
            rec.w[7] = 0;
            if (OB_PTR(Q_ab23fc, FLD_ab23fc(uint32_t, 0x6c))->Slot51_ab23fc(props, 0xea56768a, &rec)) {
                if (OB_PTR(Qb_ab23fc, FLD_ab23fc(uint32_t, 0x6c))->Slot28_ab23fc(rec.w[0])) {
                    List_ab23fc* l1 = &FLD_ab23fc(List_ab23fc, 0xf0);
                    It_ab23fc it = Fn004dc710(It_ab23fc(l1->mpHead->mpNext), It_ab23fc(l1->mpHead), &a);
                    if (it.mpNode == l1->mpHead) {
                        o->AddRef_ab23fc();
                        l1->PushBack(&a);
                    }
                    Rec_ab23fc rec2;
                    rec2.w[7] = 0;
                    if (OB_PTR(Q_ab23fc, FLD_ab23fc(uint32_t, 0x6c))->Slot51_ab23fc(o->Props_ab23fc(), 0xea56768a, &rec2)) {
                        TgtX_ab23fc* t = reinterpret_cast<TgtX_ab23fc*>(OB_PTR(Qb_ab23fc, FLD_ab23fc(uint32_t, 0x6c))->Slot28_ab23fc(rec2.w[0]));
                        t->Slot22_ab23fc(o->Props_ab23fc(), 0xea56768a);
                    }
                }
            }
            self->Fn006e1240();
        }
    }
}
#endif

// ---- wave 11b batch 3 ----
struct ObjR_ab23fc; struct ObjQ_ab23fc; struct ObjP_ab23fc;
struct OB_NOVTABLE CityY_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual void Pad18_ab23fc();
    virtual void Pad19_ab23fc();
    virtual void Pad20_ab23fc();
    virtual void Pad21_ab23fc();
    virtual void Pad22_ab23fc();
    virtual void Pad23_ab23fc();
    virtual void Pad24_ab23fc();
    virtual void Pad25_ab23fc();
    virtual void Pad26_ab23fc();
    virtual void Pad27_ab23fc();
    virtual void Pad28_ab23fc();
    virtual void Pad29_ab23fc();
    virtual void Pad30_ab23fc();
    virtual void Pad31_ab23fc();
    virtual void Pad32_ab23fc();
    virtual void Pad33_ab23fc();
    virtual ObjR_ab23fc* S34_ab23fc() = 0;
    virtual void Pad35_ab23fc();
    virtual void Pad36_ab23fc();
    virtual void Pad37_ab23fc();
    virtual void Pad38_ab23fc();
    virtual ObjQ_ab23fc* S39_ab23fc() = 0;
    virtual void Pad40_ab23fc();
    virtual void Pad41_ab23fc();
    virtual void Pad42_ab23fc();
    virtual void Pad43_ab23fc();
    virtual void Pad44_ab23fc();
    virtual void Pad45_ab23fc();
    virtual void Pad46_ab23fc();
    virtual void Pad47_ab23fc();
    virtual void Pad48_ab23fc();
    virtual void Pad49_ab23fc();
    virtual ObjP_ab23fc* S50_ab23fc() = 0;
};
struct OB_NOVTABLE ObjR_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual void Pad18_ab23fc();
    virtual void Pad19_ab23fc();
    virtual void Pad20_ab23fc();
    virtual void Pad21_ab23fc();
    virtual void Pad22_ab23fc();
    virtual void Pad23_ab23fc();
    virtual void Pad24_ab23fc();
    virtual void Pad25_ab23fc();
    virtual void Pad26_ab23fc();
    virtual void Pad27_ab23fc();
    virtual void Pad28_ab23fc();
    virtual void Pad29_ab23fc();
    virtual void Pad30_ab23fc();
    virtual void Pad31_ab23fc();
    virtual void Pad32_ab23fc();
    virtual void Pad33_ab23fc();
    virtual void Pad34_ab23fc();
    virtual void Pad35_ab23fc();
    virtual void Pad36_ab23fc();
    virtual void Pad37_ab23fc();
    virtual void Pad38_ab23fc();
    virtual void Pad39_ab23fc();
    virtual void Pad40_ab23fc();
    virtual void Pad41_ab23fc();
    virtual void Pad42_ab23fc();
    virtual void Pad43_ab23fc();
    virtual void Pad44_ab23fc();
    virtual void Pad45_ab23fc();
    virtual void Pad46_ab23fc();
    virtual void Pad47_ab23fc();
    virtual void S48_ab23fc(void* p) = 0;
};
struct OB_NOVTABLE ObjQ_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void S14_ab23fc(void* p) = 0;
};
struct OB_NOVTABLE ObjP_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual void Pad18_ab23fc();
    virtual void Pad19_ab23fc();
    virtual void S20_ab23fc(void* p) = 0;
};
struct OB_NOVTABLE RelS_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual uint32_t Release_ab23fc() = 0;
    virtual void Pad03_ab23fc();
    virtual void S4_ab23fc() = 0;
};
struct OB_NOVTABLE RelT_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual uint32_t Release_ab23fc() = 0;
};
struct OB_NOVTABLE DispM_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Reg_ab23fc(void* p) = 0;
};
struct ZObj2_ab23fc;
// STUB: 0x006e0100
void Fn006e0100();
// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t size);
struct OB_NOVTABLE SC4G_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual void Pad18_ab23fc();
    virtual void Pad19_ab23fc();
    virtual void Pad20_ab23fc();
    virtual void Pad21_ab23fc();
    virtual void Pad22_ab23fc();
    virtual void Pad23_ab23fc();
    virtual void Pad24_ab23fc();
    virtual void Pad25_ab23fc();
    virtual void Pad26_ab23fc();
    virtual void Pad27_ab23fc();
    virtual void Pad28_ab23fc();
    virtual void Pad29_ab23fc();
    virtual void Pad30_ab23fc();
    virtual void Pad31_ab23fc();
    virtual void Pad32_ab23fc();
    virtual void Pad33_ab23fc();
    virtual void Pad34_ab23fc();
    virtual void Pad35_ab23fc();
    virtual void Pad36_ab23fc();
    virtual void Pad37_ab23fc();
    virtual void Pad38_ab23fc();
    virtual void Pad39_ab23fc();
    virtual void Pad40_ab23fc();
    virtual void Pad41_ab23fc();
    virtual void Pad42_ab23fc();
    virtual void Pad43_ab23fc();
    virtual void Pad44_ab23fc();
    virtual void Pad45_ab23fc();
    virtual void Pad46_ab23fc();
    virtual void Pad47_ab23fc();
    virtual void Pad48_ab23fc();
    virtual void Pad49_ab23fc();
    virtual void Pad50_ab23fc();
    virtual void Pad51_ab23fc();
    virtual void Pad52_ab23fc();
    virtual void Pad53_ab23fc();
    virtual void Pad54_ab23fc();
    virtual void Pad55_ab23fc();
    virtual void Pad56_ab23fc();
    virtual void Pad57_ab23fc();
    virtual void Pad58_ab23fc();
    virtual void Pad59_ab23fc();
    virtual void Pad60_ab23fc();
    virtual void Pad61_ab23fc();
    virtual void Pad62_ab23fc();
    virtual void Pad63_ab23fc();
    virtual void Pad64_ab23fc();
    virtual void Pad65_ab23fc();
    virtual void Pad66_ab23fc();
    virtual void Pad67_ab23fc();
    virtual void Pad68_ab23fc();
    virtual void Reg_ab23fc(void (*cb)(), uint32_t a) = 0;
};
// GLOBAL: 0x00b43c94
extern SC4G_ab23fc* gpB43c94_ab23fc;
// GLOBAL: 0x00b49b60
extern bool g00b49b60;
// GLOBAL: 0x00b43d70
extern Unk_ab23fc* gpB43d70_ab23fc;

struct ProtG_ab23fc {
    // STUB: 0x006f6bc0
    bool ProtectionInit();
};

// The fire-plane dispatch source the simulator holds at +0xc8 (a reference-counted object).
struct OB_NOVTABLE FireSrc_ab23fc {
    virtual void Pad00_ab23fc();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    // STUB: 0x006dff70
    FireSrc_ab23fc* Fn006dff70();
    // STUB: 0x006df8c0
    bool Init();
    bool InitDraft_ab23fc();
    bool ShutdownDraft_ab23fc();
};
struct OB_NOVTABLE StrmW_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Ver_ab23fc(uint32_t v) = 0;
    virtual void Put_ab23fc(uint32_t v) = 0;
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual bool Err_ab23fc() = 0;
};
struct OB_NOVTABLE StrmR_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Ver_ab23fc(uint16_t* v) = 0;
    virtual void Get_ab23fc(void* out) = 0;
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual bool Err_ab23fc() = 0;
};
struct OB_NOVTABLE YObj_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual void Pad18_ab23fc();
    virtual void Pad19_ab23fc();
    virtual void Pad20_ab23fc();
    virtual void Pad21_ab23fc();
    virtual void Pad22_ab23fc();
    virtual void Pad23_ab23fc();
    virtual void Pad24_ab23fc();
    virtual void* Make25_ab23fc(uint32_t a, uint32_t b) = 0;
};
struct OB_NOVTABLE ZObj_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void AddRef_ab23fc() = 0;
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void S5_ab23fc(uint32_t a, uint32_t b) = 0;
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void S13_ab23fc(void* p) = 0;
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual ZObj2_ab23fc* S17_ab23fc(uint32_t a, uint32_t b) = 0;
};
struct OB_NOVTABLE MsgT_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Add_ab23fc(void* target, uint32_t id) = 0;
    virtual void Rem_ab23fc(uint32_t id) = 0;
};
struct OB_NOVTABLE MsgX_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual uint32_t Kind_ab23fc() = 0;
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual uint32_t Arg9_ab23fc() = 0;
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual uint32_t Arg14_ab23fc() = 0;
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual void Pad18_ab23fc();
    virtual void Pad19_ab23fc();
    virtual void Pad20_ab23fc();
    virtual void Pad21_ab23fc();
    virtual void Pad22_ab23fc();
    virtual void Pad23_ab23fc();
    virtual void Pad24_ab23fc();
    virtual void Pad25_ab23fc();
    virtual void Pad26_ab23fc();
    virtual void Pad27_ab23fc();
    virtual void Pad28_ab23fc();
    virtual void Pad29_ab23fc();
    virtual void Pad30_ab23fc();
    virtual void Pad31_ab23fc();
    virtual void* Slot32_ab23fc() = 0;
};
struct OB_NOVTABLE VObj_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual void Pad07_ab23fc();
    virtual void Pad08_ab23fc();
    virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc();
    virtual void Pad11_ab23fc();
    virtual void Pad12_ab23fc();
    virtual void Pad13_ab23fc();
    virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc();
    virtual void Pad16_ab23fc();
    virtual void Pad17_ab23fc();
    virtual void Pad18_ab23fc();
    virtual void Pad19_ab23fc();
    virtual void Pad20_ab23fc();
    virtual void S21_ab23fc(uint32_t* a, uint32_t* b) = 0;
};
struct OB_NOVTABLE WObj_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual void Pad03_ab23fc();
    virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc();
    virtual void Pad06_ab23fc();
    virtual bool S7_ab23fc(uint32_t a, uint32_t b) = 0;
};
struct OB_NOVTABLE CObj_ab23fc {
    virtual void Pad00_ab23fc();
    virtual void Pad01_ab23fc();
    virtual void Pad02_ab23fc();
    virtual uint32_t Get3_ab23fc() = 0;
};

struct OB_NOVTABLE ZObj2_ab23fc {
    virtual void Pad00_ab23fc(); virtual void Pad01_ab23fc(); virtual void Pad02_ab23fc(); virtual void Pad03_ab23fc(); virtual void Pad04_ab23fc();
    virtual void Pad05_ab23fc(); virtual void Pad06_ab23fc(); virtual void Pad07_ab23fc(); virtual void Pad08_ab23fc(); virtual void Pad09_ab23fc();
    virtual void Pad10_ab23fc(); virtual void Pad11_ab23fc(); virtual void Pad12_ab23fc(); virtual void Pad13_ab23fc(); virtual void Pad14_ab23fc();
    virtual void Pad15_ab23fc(); virtual void Pad16_ab23fc(); virtual void Pad17_ab23fc();
    virtual void S18_ab23fc(uint32_t a, uint32_t b) = 0;
};

// STUB: 0x005d99a0
void Fn005d99a0(void* stream, void* value);
// STUB: 0x005daff0
void Fn005daff0(void* stream, void* p);
// STUB: 0x005db3c0
void Fn005db3c0(void* stream, void* p);
// STUB: 0x005d9730
void Fn005d9730(void* stream, uint32_t key, void* p, uint32_t flag);
// STUB: 0x005fe6b0
void Fn005fe6b0(void* obj, uint32_t iid, void* p);
// STUB: 0x005ff510 is declared above (Fn005ff510)

struct Base2ac4_ab23fc {
    // STUB: 0x006f5850
    bool Fn006f5850(void* stream);
    // STUB: 0x006f5920
    bool Fn006f5920(void* stream);
    // STUB: 0x006f62c0
    bool Fn006f62c0(uint32_t msg);
};

// The serialization interface at +0x10 seen with the original's return types and this = its ecx.
struct Ser_ab23fc {
    uint32_t Write(uint32_t a);
    bool Read(uint32_t a);
};

struct VecI_ab23fc {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x00423320
    void Fn00423320(uint32_t* where, uint32_t count, const uint32_t* value);
};

// FUNCTION: 0x006e03f0
uint32_t Ser_ab23fc::Write(uint32_t a)
{
    StrmW_ab23fc* s = OB_PTR(StrmW_ab23fc, a);
    s->Ver_ab23fc(8);
    if (reinterpret_cast<Base2ac4_ab23fc*>(this)->Fn006f5850(s)) {
        Fn005d99a0(s, reinterpret_cast<void*>(static_cast<uintptr_t>(FLD_ab23fc(uint32_t, 0xc0))));
        Fn005daff0(s, &FLD_ab23fc(uint8_t, 0xe8));
        Fn005daff0(s, &FLD_ab23fc(uint8_t, 0xc4));
        s->Put_ab23fc(FLD_ab23fc(uint32_t, 0xc8));
        s->Put_ab23fc(FLD_ab23fc(uint32_t, 0xcc));
        s->Put_ab23fc(FLD_ab23fc(uint32_t, 0xd0));
        s->Put_ab23fc(FLD_ab23fc(uint32_t, 0xd4));
        s->Put_ab23fc(FLD_ab23fc(uint32_t, 0xdc));
        s->Put_ab23fc(FLD_ab23fc(uint32_t, 0xe4));
        s->Put_ab23fc(FLD_ab23fc(uint32_t, 0xd8));
        s->Put_ab23fc(FLD_ab23fc(uint32_t, 0xe0));
        char* obj = FLD_ab23fc(char*, 0xb8);
        Fn005d99a0(s, obj ? obj + 8 : 0);
    }
    return !s->Err_ab23fc();
}

// FUNCTION: 0x006e04e0
bool Ser_ab23fc::Read(uint32_t a)
{
    StrmR_ab23fc* s = OB_PTR(StrmR_ab23fc, a);
    uint16_t ver;
    s->Ver_ab23fc(&ver);
    if (ver > 8) {
        return false;
    }
    if (reinterpret_cast<Base2ac4_ab23fc*>(this)->Fn006f5920(s)) {
        Fn005d9730(s, 0x223e2b67, &FLD_ab23fc(uint8_t, 0xc0), 0);
        Fn005db3c0(s, &FLD_ab23fc(uint8_t, 0xe8));
        Fn005db3c0(s, &FLD_ab23fc(uint8_t, 0xc4));
        s->Get_ab23fc(&FLD_ab23fc(uint8_t, 0xc8));
        s->Get_ab23fc(&FLD_ab23fc(uint8_t, 0xcc));
        s->Get_ab23fc(&FLD_ab23fc(uint8_t, 0xd0));
        s->Get_ab23fc(&FLD_ab23fc(uint8_t, 0xd4));
        s->Get_ab23fc(&FLD_ab23fc(uint8_t, 0xdc));
        s->Get_ab23fc(&FLD_ab23fc(uint8_t, 0xe4));
        s->Get_ab23fc(&FLD_ab23fc(uint8_t, 0xd8));
        s->Get_ab23fc(&FLD_ab23fc(uint8_t, 0xe0));
        if (ver > 7) {
            Unk_ab23fc* old = FLD_ab23fc(Unk_ab23fc*, 0xb8);
            if (old) {
                FLD_ab23fc(Unk_ab23fc*, 0xb8) = 0;
                old->Release_ab23fc();
            }
            Fn005d9730(s, 0xc9c00435, &FLD_ab23fc(uint8_t, 0xb8), 0);
        }
    }
    FLD_ab23fc(bool, 0xb1) = true;
    return !s->Err_ab23fc();
}

#ifdef OB_DRAFTS
// CLOSE: 0x006e2b50 score 59
void cSC4PoliceSimulator::Slot38_ab2348()
{
    if (FLD_ab23fc(int32_t, 0xec) > 0) {
        FLD_ab23fc(int32_t, 0xe0) += FLD_ab23fc(int32_t, 0xec);
        if (FLD_ab23fc(int32_t, 0xe0) < 0) {
            FLD_ab23fc(int32_t, 0xe0) = 0;
        }
        Fn006e1240();
    }
    FLD_ab23fc(uint32_t, 0xe4) = FLD_ab23fc(uint32_t, 0xec);
    uint32_t t = FLD_ab23fc(uint32_t, 0xf0);
    FLD_ab23fc(uint32_t, 0xec) = 0;
    FLD_ab23fc(uint32_t, 0xe8) = t;
    FLD_ab23fc(uint32_t, 0xf0) = 0;
    Node_ab23fc* head = FLD_ab23fc(List_ab23fc, 0x88).mpHead;
    for (Node_ab23fc* p = head->mpNext; p != FLD_ab23fc(List_ab23fc, 0x88).mpHead; p = p->mpNext) {
        OccC_ab23fc* o = OB_PTR(OccC_ab23fc, p->mValue);
        VecI_ab23fc v;
        v.mpBegin = 0;
        v.mpEnd = 0;
        v.mpCap = 0;
        if (!Fn005ff510(o->Props_ab23fc(), 0x8a70a0b9, &v)) {
            uint32_t zero = 0;
            uint32_t n = static_cast<uint32_t>(v.mpEnd - v.mpBegin);
            if (n > 4) {
                v.mpEnd = v.mpBegin + 4;
            } else {
                v.Fn00423320(v.mpEnd, 4 - n, &zero);
            }
            for (uint32_t i = 0; i < 4; ++i) {
                v.mpBegin[i] = 0;
            }
        }
        v.mpBegin[1] = v.mpBegin[3];
        v.mpBegin[0] = v.mpBegin[2];
        v.mpBegin[3] = 0;
        v.mpBegin[2] = 0;
        Fn005fe6b0(o->Props_ab23fc(), 0x8a70a0b9, &v);
        if (v.mpBegin) {
            Fn0090cf63(v.mpBegin);
        }
    }
    gpB43dc0_ab23fc->Set12_ab23fc(0xa5cc155, FLD_ab23fc(int32_t, 0xe8));
    gpB43dc0_ab23fc->Set12_ab23fc(0xa5cc156, FLD_ab23fc(int32_t, 0xe4));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e2920 score 86
bool Fix_ab23fc::Slot03_ab2b10(uint32_t msg)
{
    MsgX_ab23fc* m = OB_PTR(MsgX_ab23fc, msg);
    reinterpret_cast<Base2ac4_ab23fc*>(this)->Fn006f62c0(msg);
    uint32_t kind = m->Kind_ab23fc();
    cSC4PoliceSimulator* self = reinterpret_cast<cSC4PoliceSimulator*>(reinterpret_cast<char*>(this) - 8);
    if (kind == 0x8dac3e7) {
        uint32_t cur = OB_PTR(CObj_ab23fc, FLD_ab23fc(uint32_t, 0xc8))->Get3_ab23fc();
        if (m->Arg14_ab23fc() == cur) {
            self->Fn006e1240();
        }
    } else if (kind == 0xa159d95) {
        Unk_ab23fc* x = reinterpret_cast<Unk_ab23fc*>(m->Slot32_ab23fc());
        VObj_ab23fc* v = 0;
        x->QueryInterface_ab23fc(0xe818fced, &v);
        if (v) {
            uint32_t b, a;
            v->S21_ab23fc(&a, &b);
            bool flag = OB_PTR(WObj_ab23fc, FLD_ab23fc(uint32_t, 0x78))->S7_ab23fc(a, b);
            uint32_t r = self->Fn006e13f0(a, b);
            if (static_cast<int32_t>(flag) > FLD_ab23fc(int32_t, 0x13c)) {
                FLD_ab23fc(int32_t, 0xe4) = FLD_ab23fc(int32_t, 0xe4) + 1;
                if (r) {
                    self->Fn006e2610(r, 1);
                }
            } else {
                FLD_ab23fc(int32_t, 0xec) = FLD_ab23fc(int32_t, 0xec) + 1;
                if (r) {
                    self->Fn006e2610(r, 0);
                }
            }
            FLD_ab23fc(int32_t, 0xe8) = FLD_ab23fc(int32_t, 0xe8) + 1;
            reinterpret_cast<Unk_ab23fc*>(v)->Release_ab23fc();
        }
    } else if (kind == 0xc53d10aa) {
        uint32_t a = m->Arg9_ab23fc();
        uint32_t b = m->Arg14_ab23fc();
        if (a == 0xe7e2c2db && b == 0x28dfcf89) {
            self->ReadSimulatorTunableValues();
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006e2740 score 54
bool cSC4PoliceSimulator::Slot03_ab2348()
{
    if (!FLD_ab23fc(bool, 0xc0)) {
        FLD_ab23fc(bool, 0xc0) = true;
        if (!g00b49b60) {
            g00b49b60 = true;
            gpB43c94_ab23fc->Reg_ab23fc(Fn006e0100, 0);
        }
        ReadSimulatorTunableValues();
        char* sub = reinterpret_cast<char*>(this) + 8;
        reinterpret_cast<ProtG_ab23fc*>(sub)->ProtectionInit();
        FLD_ab23fc(uint32_t, 0xb0) = 0xa567baa;
        if (!FLD_ab23fc(uint32_t, 0x7c)) {
            ZObj_ab23fc* z = reinterpret_cast<ZObj_ab23fc*>(OB_PTR(YObj_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Make25_ab23fc(0xa2963983, 0x4a357b40));
            FLD_ab23fc(ZObj_ab23fc*, 0x7c) = z;
            z->AddRef_ab23fc();
            FLD_ab23fc(ZObj_ab23fc*, 0x7c)->S5_ab23fc(0x6a3ff01c, 0xaa493855);
            FLD_ab23fc(ZObj_ab23fc*, 0x7c)->S13_ab23fc(&FLD_ab23fc(uint8_t, 0x120));
            FLD_ab23fc(ZObj_ab23fc*, 0x7c)->S17_ab23fc(1, 1)->S18_ab23fc(1, 0);
        }
        if (!FLD_ab23fc(uint32_t, 0xd0)) {
            ZObj_ab23fc* z = reinterpret_cast<ZObj_ab23fc*>(OB_PTR(YObj_ab23fc, FLD_ab23fc(uint32_t, 0x74))->Make25_ab23fc(0xa2963984, 0x4a357b40));
            FLD_ab23fc(ZObj_ab23fc*, 0xd0) = z;
            z->AddRef_ab23fc();
            FLD_ab23fc(ZObj_ab23fc*, 0xd0)->S5_ab23fc(0x6a3ff01c, 0x4a4fc955);
            FLD_ab23fc(ZObj_ab23fc*, 0xd0)->S13_ab23fc(&FLD_ab23fc(uint8_t, 0x120));
            FLD_ab23fc(ZObj_ab23fc*, 0xd0)->S17_ab23fc(1, 1)->S18_ab23fc(1, 0);
        }
        if (!FLD_ab23fc(uint32_t, 0xcc)) {
            Unk_ab23fc* c = gpB43d70_ab23fc;
            FLD_ab23fc(Unk_ab23fc*, 0xcc) = c;
            reinterpret_cast<ZObj_ab23fc*>(c)->AddRef_ab23fc();
        }
        if (FLD_ab23fc(MsgT_ab23fc*, 0x70)) {
            FLD_ab23fc(MsgT_ab23fc*, 0x70)->Add_ab23fc(sub, 0xa159d95);
        }
        if (FLD_ab23fc(MsgT_ab23fc*, 0x80)) {
            FLD_ab23fc(MsgT_ab23fc*, 0x80)->Rem_ab23fc(0x49d5bbb9);
        }
        if (FLD_ab23fc(MsgT_ab23fc*, 0x84)) {
            FLD_ab23fc(MsgT_ab23fc*, 0x84)->Rem_ab23fc(0x49d5bbce);
        }
        if (!FLD_ab23fc(FireSrc_ab23fc*, 0xc8)) {
            FireSrc_ab23fc* fresh = 0;
            void* mem = Fn005e55e0(0x28);
            if (mem) {
                fresh = reinterpret_cast<FireSrc_ab23fc*>(mem)->Fn006dff70();
            }
            FireSrc_ab23fc* old = FLD_ab23fc(FireSrc_ab23fc*, 0xc8);
            if (fresh != old) {
                if (fresh) {
                    fresh->AddRef();
                }
                FLD_ab23fc(FireSrc_ab23fc*, 0xc8) = fresh;
                if (old) {
                    old->Release();
                }
            }
        }
        if (FLD_ab23fc(FireSrc_ab23fc*, 0xc8)) {
            FLD_ab23fc(FireSrc_ab23fc*, 0xc8)->Init();
        }
    }
    return true;
}
#endif

// GLOBAL: 0x00b43cec
extern CityY_ab23fc* gpB43cec_y;
// GLOBAL: 0x00b43d04
extern DispM_ab23fc* gpB43d04_ab23fc;

#ifdef OB_DRAFTS
// CLOSE: 0x006df8c0 score 20
bool FireSrc_ab23fc::InitDraft_ab23fc()
{
    if (!FLD_ab23fc(bool, 0xc)) {
        FLD_ab23fc(bool, 0xc) = true;
        if (!FLD_ab23fc(uint32_t, 0x18)) {
            cISC4City* c = gpB43cec;
            FLD_ab23fc(cISC4City*, 0x18) = c;
            c->AddRef();
        }
        if (!FLD_ab23fc(uint32_t, 0x20)) {
            cIGZMessageServer2* ms = gpB43ccc;
            FLD_ab23fc(cIGZMessageServer2*, 0x20) = ms;
            ms->AddRef();
            void* t = &FLD_ab23fc(uint8_t, 4);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->AddNotification(t, 0x99ef1142);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->AddNotification(t, 0x99ef1143);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->AddNotification(t, 0xe94671eb);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->AddNotification(t, 0x894671f6);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->AddNotification(t, 0xe94671ec);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->AddNotification(t, 0xe94671ed);
        }
        gpB43d04_ab23fc->Reg_ab23fc(this);
    }
    return true;
}
#endif

// FUNCTION: 0x006ac860
bool FireSrc_ab23fc::ShutdownDraft_ab23fc()
{
    if (FLD_ab23fc(bool, 0xc)) {
        FLD_ab23fc(bool, 0xc) = false;
        gpB43cec_y->S39_ab23fc()->S14_ab23fc(this);
        gpB43cec_y->S34_ab23fc()->S48_ab23fc(&FLD_ab23fc(uint8_t, 0x1c));
        if (FLD_ab23fc(uint32_t, 0x20)) {
            void* t = &FLD_ab23fc(uint8_t, 4);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->RemoveNotification(t, 0x99ef1142);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->RemoveNotification(t, 0x99ef1143);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->RemoveNotification(t, 0xe94671eb);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->RemoveNotification(t, 0xe94671ec);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->RemoveNotification(t, 0xe94671ed);
            FLD_ab23fc(cIGZMessageServer2*, 0x20)->RemoveNotification(t, 0x894671f6);
            FLD_ab23fc(RelT_ab23fc*, 0x20)->Release_ab23fc();
            FLD_ab23fc(uint32_t, 0x20) = 0;
        }
        if (FLD_ab23fc(uint32_t, 0x18)) {
            FLD_ab23fc(RelT_ab23fc*, 0x18)->Release_ab23fc();
            FLD_ab23fc(uint32_t, 0x18) = 0;
        }
    }
    return true;
}

// The protection simulator (the subobject at +8) seen with this = its ecx; a draft of its shutdown.
struct ProtShut_ab23fc {
    bool ShutdownDraft_ab23fc();
};

#ifdef OB_DRAFTS
// CLOSE: 0x006f56f0 score 89
bool ProtShut_ab23fc::ShutdownDraft_ab23fc()
{
    void* t = this ? &FLD_ab23fc(uint8_t, 4) : 0;
    gpB43cec_y->S39_ab23fc()->S14_ab23fc(t);
    gpB43cec_y->S34_ab23fc()->S48_ab23fc(&FLD_ab23fc(uint8_t, 0x80));
    if (FLD_ab23fc(uint32_t, 0x68)) {
        cIGZMessageServer2* ms = FLD_ab23fc(cIGZMessageServer2*, 0x68);
        ms->RemoveNotification(this, 0x99ef1142);
        ms->RemoveNotification(this, 0x99ef1143);
        ms->RemoveNotification(this, 0xc8dac052);
        ms->RemoveNotification(this, 0x8dac3e7);
        ms->RemoveNotification(this, 0xe94671eb);
        ms->RemoveNotification(this, 0xe94671ec);
        ms->RemoveNotification(this, 0xe94671ed);
        ms->RemoveNotification(this, 0x894671f6);
        ms->RemoveNotification(this, 0xc53d10aa);
        FLD_ab23fc(RelT_ab23fc*, 0x68)->Release_ab23fc();
        FLD_ab23fc(uint32_t, 0x68) = 0;
    }
    ObjP_ab23fc* x = gpB43cec_y->S50_ab23fc();
    if (x) {
        x->S20_ab23fc(this);
    }
    if (FLD_ab23fc(uint32_t, 0x78)) {
        FLD_ab23fc(RelS_ab23fc*, 0x78)->S4_ab23fc();
        FLD_ab23fc(RelS_ab23fc*, 0x78)->Release_ab23fc();
        FLD_ab23fc(uint32_t, 0x78) = 0;
    }
    if (FLD_ab23fc(uint32_t, 0x7c)) {
        FLD_ab23fc(RelS_ab23fc*, 0x7c)->S4_ab23fc();
        FLD_ab23fc(RelS_ab23fc*, 0x7c)->Release_ab23fc();
        FLD_ab23fc(uint32_t, 0x7c) = 0;
    }
    if (FLD_ab23fc(uint32_t, 0x70)) {
        FLD_ab23fc(RelT_ab23fc*, 0x70)->Release_ab23fc();
        FLD_ab23fc(uint32_t, 0x70) = 0;
    }
    if (FLD_ab23fc(uint32_t, 0x6c)) {
        FLD_ab23fc(RelT_ab23fc*, 0x6c)->Release_ab23fc();
        FLD_ab23fc(uint32_t, 0x6c) = 0;
    }
    if (FLD_ab23fc(uint32_t, 0x64)) {
        FLD_ab23fc(RelT_ab23fc*, 0x64)->Release_ab23fc();
        FLD_ab23fc(uint32_t, 0x64) = 0;
    }
    return true;
}
#endif
