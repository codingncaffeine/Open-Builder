#include <cmath>
#include <cstddef>

#include "classes/cSC4TrafficAutomataManager.h"
#include "game/Globals.h"

struct Dest2_a9bd88;
struct Dest_a9bd88;
struct Path_a9bd88;
struct Counted_a9bd88;
struct Lead_a9bd88;
struct Loc_a9bd88;

// A field of the base class (cSC4AutomataManager reaches to 0xa88; its header does not name these yet).
#define A9BD88_FIELD(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(this) + (off)))

// GLOBAL: 0x00b21bf4
extern float gfB21bf4;
// GLOBAL: 0x00b21c08
extern float gfB21c08;
// GLOBAL: 0x00b21c1c
extern float gfB21c1c;
// GLOBAL: 0x00b21c30
extern float gfB21c30;
// GLOBAL: 0x00b21c44
extern float gfB21c44;
// GLOBAL: 0x00b21c04
extern float gfB21c04;
// GLOBAL: 0x00b21c18
extern float gfB21c18;
// GLOBAL: 0x00b21c2c
extern float gfB21c2c;
// GLOBAL: 0x00b21c40
extern float gfB21c40;
// GLOBAL: 0x00b21c54
extern float gfB21c54;

// An automaton as seen through its second subobject (+4) and its own slots.
struct Auto_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void* S14_a9bd88();
};

struct Typed_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual uint32_t S1c_a9bd88();
};

struct Trait_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual bool S20_a9bd88(uint32_t);
};

struct Rect_a9bd88 {
    int32_t mnMinX;
    int32_t mnMinY;
    int32_t mnMaxX;
    int32_t mnMaxY;
};

struct NetMap_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual Trait_a9bd88* S2c_a9bd88(int32_t, int32_t);
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual Rect_a9bd88* S44_a9bd88();
};

struct Check_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual bool S58_a9bd88(uint32_t);
};

struct Scale_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual float S5c_a9bd88(uint32_t);
};

struct PathAuto_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual void Pad7c();
    virtual void Pad80();
    virtual void Pad84();
    virtual void Pad88();
    virtual void Pad8c();
    virtual void Pad90();
    virtual void Pad94();
    virtual void Pad98();
    virtual void Pad9c();
    virtual void Pada0();
    virtual void Pada4();
    virtual void Pada8();
    virtual void Padac();
    virtual void Padb0();
    virtual void Padb4();
    virtual void Padb8();
    virtual void Padbc();
    virtual void Padc0();
    virtual void Padc4();
    virtual void Padc8();
    virtual void Padcc();
    virtual void Padd0();
    virtual void Padd4();
    virtual void Padd8();
    virtual void Paddc();
    virtual void Pade0();
    virtual void Pade4();
    virtual void Pade8();
    virtual void Padec();
    virtual void Padf0();
    virtual void Padf4();
    virtual void Padf8();
    virtual void Padfc();
    virtual void Pad100();
    virtual void Pad104();
    virtual void Pad108();
    virtual void Pad10c();
    virtual void Pad110();
    virtual void Pad114();
    virtual void Pad118();
    virtual void Pad11c();
    virtual void Pad120();
    virtual void Pad124();
    virtual void Pad128();
    virtual void Pad12c();
    virtual void Pad130();
    virtual void Pad134();
    virtual void Pad138();
    virtual void Pad13c();
    virtual void Pad140();
    virtual void Pad144();
    virtual void Pad148();
    virtual void Pad14c();
    virtual void Pad150();
    virtual void Pad154();
    virtual void Pad158();
    virtual void Pad15c();
    virtual void Pad160();
    virtual void Pad164();
    virtual void Pad168();
    virtual void Pad16c();
    virtual void Pad170();
    virtual void Pad174();
    virtual void Pad178();
    virtual void Pad17c();
    virtual void Pad180();
    virtual void Pad184();
    virtual void Pad188();
    virtual void Pad18c();
    virtual void Pad190();
    virtual void Pad194();
    virtual void Pad198();
    virtual void Pad19c();
    virtual void Pad1a0();
    virtual void Pad1a4();
    virtual void Pad1a8();
    virtual void Pad1ac();
    virtual void Pad1b0();
    virtual void Pad1b4();
    virtual void Pad1b8();
    virtual void Pad1bc();
    virtual void Pad1c0();
    virtual void Pad1c4();
    virtual void Pad1c8();
    virtual void Pad1cc();
    virtual void Pad1d0();
    virtual void Pad1d4();
    virtual void Pad1d8();
    virtual void Pad1dc();
    virtual void Pad1e0();
    virtual void Pad1e4();
    virtual void Pad1e8();
    virtual void Pad1ec();
    virtual void Pad1f0();
    virtual void Pad1f4();
    virtual void Pad1f8();
    virtual void Pad1fc();
    virtual void Pad200();
    virtual void Pad204();
    virtual void Pad208();
    virtual void Pad20c();
    virtual void Pad210();
    virtual void Pad214();
    virtual void Pad218();
    virtual void Pad21c();
    virtual void Pad220();
    virtual void Pad224();
    virtual void Pad228();
    virtual void Pad22c();
    virtual void Pad230();
    virtual bool S234_a9bd88();
};

// FUNCTION: 0x0054d150
uint32_t OB_STDCALL Fn0054d150(void* pAutomaton)
{
    Auto_a9bd88* p = static_cast<Auto_a9bd88*>(pAutomaton);
    if (p) {
        if (static_cast<Typed_a9bd88*>(p->S14_a9bd88())->S1c_a9bd88() == 0xc7cc75f1) {
            return 1;
        }
        if (static_cast<Typed_a9bd88*>(p->S14_a9bd88())->S1c_a9bd88() == 0x496e5783) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x0054d1a0
uint32_t OB_STDCALL Fn0054d1a0(uint32_t t)
{
    if (t == 0x4005 || t == 0x4201 || t == 0x4203 || t == 0x4215 || t == 0x4216 || t == 0x4208 || t == 0x4217
        || t == 0x422d || t == 0x422c || t == 0x422f || t == 0x422e || t == 0x4230 || t == 0x4233) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x0054d210
uint32_t OB_STDCALL Fn0054d210(uint32_t t)
{
    if (t == 0x422d || t == 0x422c) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x0054d230
uint32_t OB_STDCALL Fn0054d230(uint32_t t)
{
    if (t == 0x422f || t == 0x422e) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x0054d260
bool cSC4TrafficAutomataManager::IsOffscreenEntryEdge(void* /*pTile*/, int32_t x, int32_t y, uint8_t dir)
{
    Rect_a9bd88* r = A9BD88_FIELD(NetMap_a9bd88*, 0xa7c)->S44_a9bd88();
    switch (dir) {
    case 0:
        x = x - 1;
        break;
    case 1:
        y = y - 1;
        break;
    case 2:
        x = x + 1;
        break;
    case 3:
        y = y + 1;
        break;
    }
    if (x >= r->mnMinX && y >= r->mnMinY && x <= r->mnMaxX && y <= r->mnMaxY) {
        Trait_a9bd88* t = A9BD88_FIELD(NetMap_a9bd88*, 0xa7c)->S2c_a9bd88(x, y);
        if (t && !t->S20_a9bd88(0x200000)) {
            return false;
        }
    }
    return true;
}

// FUNCTION: 0x0054d300
uint32_t cSC4TrafficAutomataManager::Slot91_a9bd88(uint32_t pObj, uint32_t kind)
{
    Trait_a9bd88* t = OB_PTR(Trait_a9bd88, pObj);
    switch (kind) {
    case 1:
    case 2:
        if (t->S20_a9bd88(2)) {
            return 2;
        }
        if (t->S20_a9bd88(6)) {
            return 6;
        }
        if (t->S20_a9bd88(0)) {
            return 0;
        }
        if (t->S20_a9bd88(3)) {
            return 3;
        }
        break;
    case 3:
        if (t->S20_a9bd88(1)) {
            return 1;
        }
        break;
    case 4:
        if (t->S20_a9bd88(7)) {
            return 7;
        }
        break;
    }
    return 0xffffffff;
}

// FUNCTION: 0x0054d3c0
uint32_t cSC4TrafficAutomataManager::Slot73_a9bd88(uint32_t type)
{
    uint32_t def = mnA8c;
    switch (type) {
    case 4:
    case 5:
        return 3;
    case 6:
        return 4;
    case 9:
        return 6;
    case 10:
        return 7;
    }
    return def;
}

// FUNCTION: 0x0054d420
uint32_t cSC4TrafficAutomataManager::Slot74_a9bd88(uint32_t type)
{
    uint32_t def = A9BD88_FIELD(uint32_t, 0xa44);
    switch (type) {
    case 2:
        return 0x4200;
    case 3:
        return 0x4204;
    case 8:
        return 0x4102;
    case 5:
        return 0x4216;
    case 4:
        return 0x4215;
    case 6:
        return 0x4217;
    case 9:
        return 0x422c;
    case 10:
        return 0x422e;
    }
    return def;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0054d4a0 score 44
void cSC4TrafficAutomataManager::Slot88_a9bd88(void* pAuto, void* pInfo, float scale, void* pOut)
{
    float f = Slot87_a9bd88(pAuto, 7);
    const uint16_t* m = reinterpret_cast<const uint16_t*>(static_cast<char*>(pInfo) + 0x34);
    float* out = static_cast<float*>(pOut);
    if (scale >= 0.0f) {
        int32_t i = 4;
        do {
            int32_t j = 4;
            do {
                *out++ = static_cast<float>(*m++) * f * scale;
                --j;
            } while (j);
            --i;
        } while (i);
    } else {
        scale = -scale;
        int32_t i = 4;
        do {
            int32_t j = 4;
            const uint16_t* c = m;
            do {
                *out++ = static_cast<float>(*c) * f * scale;
                c += 4;
                --j;
            } while (j);
            m += 1;
            --i;
        } while (i);
    }
}
#endif

// FUNCTION: 0x0054d560
void* cSC4TrafficAutomataManager::Slot85_a9bd88(uint32_t type)
{
    switch (type) {
    case 2:
        return &gfB21c08;
    case 3:
        return &gfB21c44;
    case 5:
        return &gfB21c1c;
    case 4:
    case 6:
    case 9:
    case 10:
        return &gfB21c30;
    }
    return &gfB21bf4;
}

// FUNCTION: 0x0054d5c0
float cSC4TrafficAutomataManager::Slot86_a9bd88(uint32_t type)
{
    switch (type) {
    case 2:
        return gfB21c18;
    case 3:
        return gfB21c54;
    case 5:
        return gfB21c2c;
    case 4:
    case 6:
    case 9:
    case 10:
        return gfB21c40;
    }
    return gfB21c04;
}

// FUNCTION: 0x0054d630
float cSC4TrafficAutomataManager::Slot87_a9bd88(void* pAuto, uint32_t /*unused*/)
{
    if (!A9BD88_FIELD(bool, 0xa3d)) {
        return 1.0f;
    }
    float v = 1.0f - A9BD88_FIELD(Scale_a9bd88*, 0xa84)->S5c_a9bd88(OB_ADDR(pAuto)) * 0.01f;
    if (v < 0.0f) {
        return 0.0f;
    }
    if (v > 0.5f) {
        v = 0.5f;
    }
    return v;
}

// FUNCTION: 0x0054d690
bool cSC4TrafficAutomataManager::RemoveAutomaton(uint32_t a, uint32_t b)
{
    bool r = cSC4AutomataManager::RemoveAutomaton(a, b);
    RecalculateLeaders(a);
    return r;
}

// FUNCTION: 0x0054d6c0
uint32_t cSC4TrafficAutomataManager::GetDefaultPathType(uint32_t pAuto)
{
    PathAuto_a9bd88* p = OB_PTR(PathAuto_a9bd88, pAuto);
    if (p->S234_a9bd88()) {
        Check_a9bd88* q = reinterpret_cast<Check_a9bd88*>(reinterpret_cast<char*>(p) + 4);
        if (q->S58_a9bd88(0x422f) || q->S58_a9bd88(0x422e)) {
            return 7;
        }
        if (q->S58_a9bd88(0x422d) || q->S58_a9bd88(0x422c)) {
            return 6;
        }
        if (q->S58_a9bd88(0x4208) || q->S58_a9bd88(0x4217)) {
            return 4;
        }
        return 3;
    }
    return mnA8c;
}

// ---- batch 2 ----

// GLOBAL: 0x00b43d08
extern void* gpB43d08;
// GLOBAL: 0x00b21b9c
extern bool gbB21b9c;
// GLOBAL: 0x00b2293c
extern float gfB2293c;


struct Stream_a9bd88;

// The object at this+0xab0 (a response-list record set).

struct Timer_a9bd88 {
    // STUB: 0x008905c4
    void Start();
};

struct Curve_a9bd88 {
    // STUB: 0x005f4250
    float GetOutputValue(float x);
};

struct Rec_a9bd88 {
    uint32_t mn[7];
};

struct Key_a9bd88 {
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
};

struct Node_a9bd88 {
    Node_a9bd88* mpNext;
    Node_a9bd88* mpPrev;
    void* mpData;
};

struct Stream_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual bool S1c_a9bd88(uint32_t);
    virtual void S20_a9bd88(uint32_t);
    virtual void S24_a9bd88(uint32_t);
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual bool S48_a9bd88();
};

struct Mgr_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual bool S50_a9bd88(void*, void*);
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void* S64_a9bd88(void*, uint32_t, uint32_t, uint32_t);
};

struct Sim_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual uint16_t* S30_a9bd88(uint32_t, uint32_t, uint32_t, uint32_t);
};

struct Cnt_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual uint32_t S40_a9bd88();
};

struct Clock_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void S50_a9bd88(float*);
};

struct Counted_a9bd88 {
    virtual void Pad00();
    virtual void S04_a9bd88();
    virtual void S08_a9bd88();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void S20_a9bd88(float*);
};

struct Loc_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void S2c_a9bd88(void*);
};

struct Own_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual void Pad7c();
    virtual void Pad80();
    virtual void Pad84();
    virtual void Pad88();
    virtual void Pad8c();
    virtual void Pad90();
    virtual void Pad94();
    virtual void Pad98();
    virtual void Pad9c();
    virtual void Pada0();
    virtual void Pada4();
    virtual void Pada8();
    virtual void Padac();
    virtual void Padb0();
    virtual void Padb4();
    virtual void Padb8();
    virtual void Padbc();
    virtual Loc_a9bd88* Sc0_a9bd88();
};

struct Lead_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void S1c_a9bd88(void*);
    virtual void S20_a9bd88(void*);
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void S34_a9bd88(uint32_t);
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual bool S7c_a9bd88(uint32_t);
    virtual float S80_a9bd88();
    virtual void Pad84();
    virtual void Pad88();
    virtual void Pad8c();
    virtual void Pad90();
    virtual void Pad94();
    virtual void Pad98();
    virtual void Pad9c();
    virtual void Pada0();
    virtual void Pada4();
    virtual void Pada8();
    virtual void Padac();
    virtual void Padb0();
    virtual void Padb4();
    virtual void Padb8();
    virtual void Padbc();
    virtual void Padc0();
    virtual void Padc4();
    virtual void Padc8();
    virtual void Padcc();
    virtual void Padd0();
    virtual void Padd4();
    virtual void Padd8();
    virtual void Paddc();
    virtual void Pade0();
    virtual void Pade4();
    virtual void Pade8();
    virtual void Padec();
    virtual void Padf0();
    virtual void Padf4();
    virtual void Padf8();
    virtual void Padfc();
    virtual void Pad100();
    virtual void Pad104();
    virtual void Pad108();
    virtual void Pad10c();
    virtual void Pad110();
    virtual void Pad114();
    virtual void Pad118();
    virtual void Pad11c();
    virtual void Pad120();
    virtual void Pad124();
    virtual void Pad128();
    virtual void Pad12c();
    virtual void Pad130();
    virtual void Pad134();
    virtual void Pad138();
    virtual void Pad13c();
    virtual void Pad140();
    virtual void Pad144();
    virtual void Pad148();
    virtual void Pad14c();
    virtual void Pad150();
    virtual void Pad154();
    virtual void Pad158();
    virtual void Pad15c();
    virtual void Pad160();
    virtual void Pad164();
    virtual void Pad168();
    virtual void Pad16c();
    virtual void Pad170();
    virtual void Pad174();
    virtual void Pad178();
    virtual void Pad17c();
    virtual void Pad180();
    virtual void Pad184();
    virtual void Pad188();
    virtual void Pad18c();
    virtual void Pad190();
    virtual void Pad194();
    virtual void Pad198();
    virtual void Pad19c();
    virtual void Pad1a0();
    virtual void Pad1a4();
    virtual void Pad1a8();
    virtual void Pad1ac();
    virtual void Pad1b0();
    virtual void Pad1b4();
    virtual void Pad1b8();
    virtual void Pad1bc();
    virtual void Pad1c0();
    virtual void Pad1c4();
    virtual void Pad1c8();
    virtual void Pad1cc();
    virtual void Pad1d0();
    virtual void Pad1d4();
    virtual void Pad1d8();
    virtual void Pad1dc();
    virtual void Pad1e0();
    virtual void Pad1e4();
    virtual void Pad1e8();
    virtual void Pad1ec();
    virtual void Pad1f0();
    virtual void Pad1f4();
    virtual void Pad1f8();
    virtual void Pad1fc();
    virtual void Pad200();
    virtual void Pad204();
    virtual void Pad208();
    virtual void Pad20c();
    virtual void S210_a9bd88(uint32_t, uint32_t, uint32_t, uint32_t);
    virtual void Pad214();
    virtual void Pad218();
    virtual void S21c_a9bd88();
    virtual uint32_t S220_a9bd88();
    virtual void Pad224();
    virtual void Pad228();
    virtual void Pad22c();
    virtual void Pad230();
    virtual void Pad234();
    virtual void Pad238();
    virtual uint32_t S23c_a9bd88(uint32_t, uint32_t);
    virtual void Pad240();
    virtual void Pad244();
    virtual void Pad248();
    virtual void Pad24c();
    virtual Counted_a9bd88* S250_a9bd88();
    virtual void Pad254();
    virtual bool S258_a9bd88();
    void Fn0054e690(uint32_t a);
};

struct Path_a9bd88 {
    virtual void Pad00();
    virtual void S04_a9bd88();
    virtual void S08_a9bd88();
    virtual uint32_t S0c_a9bd88(uint32_t, uint32_t);
};

struct Base1_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual void Pad7c();
    virtual void Pad80();
    virtual void Pad84();
    virtual void Pad88();
    virtual void Pad8c();
    virtual void Pad90();
    virtual void Pad94();
    virtual void Pad98();
    virtual void Pad9c();
    virtual void Pada0();
    virtual void Pada4();
    virtual void Pada8();
    virtual void Padac();
    virtual void Padb0();
    virtual void Padb4();
    virtual void Padb8();
    virtual void Padbc();
    virtual void Padc0();
    virtual Path_a9bd88* Sc4_a9bd88();
};

struct Ctl_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void S38_a9bd88(uint32_t);
};

struct Dest_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void S38_a9bd88(void*);
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual void Pad7c();
    virtual void Pad80();
    virtual void Pad84();
    virtual void Pad88();
    virtual void Pad8c();
    virtual void Pad90();
    virtual void Pad94();
    virtual void Pad98();
    virtual void Pad9c();
    virtual void Pada0();
    virtual void Pada4();
    virtual void Pada8();
    virtual void Padac();
    virtual void Padb0();
    virtual void Padb4();
    virtual void Padb8();
    virtual void Padbc();
    virtual void Padc0();
    virtual Dest2_a9bd88* Sc4_a9bd88();
};

struct NetLot_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual Dest_a9bd88* S18_a9bd88(uint32_t, uint32_t, uint32_t);
};

struct Dest2_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual bool S54_a9bd88(uint32_t, uint32_t);
};

struct Net2_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual Dest_a9bd88* S2c_a9bd88(uint32_t, uint32_t);
};

struct CityPos_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual void Pad7c();
    virtual void Pad80();
    virtual void Pad84();
    virtual void Pad88();
    virtual void Pad8c();
    virtual void Pad90();
    virtual void Pad94();
    virtual void Pad98();
    virtual void Pad9c();
    virtual void Pada0();
    virtual void Pada4();
    virtual void Pada8();
    virtual void Padac();
    virtual void Padb0();
    virtual void Padb4();
    virtual void Padb8();
    virtual void Padbc();
    virtual void Padc0();
    virtual void Padc4();
    virtual void Padc8();
    virtual void Padcc();
    virtual void Padd0();
    virtual void Padd4();
    virtual void Padd8();
    virtual void Paddc();
    virtual void Pade0();
    virtual void Pade4();
    virtual void Pade8();
    virtual void Padec();
    virtual void Padf0();
    virtual void Padf4();
    virtual void Padf8();
    virtual void Padfc();
    virtual void Pad100();
    virtual void Pad104();
    virtual void Pad108();
    virtual void Pad10c();
    virtual void Pad110();
    virtual void Pad114();
    virtual void Pad118();
    virtual void Pad11c();
    virtual void Pad120();
    virtual void Pad124();
    virtual void Pad128();
    virtual void Pad12c();
    virtual void Pad130();
    virtual void Pad134();
    virtual void Pad138();
    virtual void Pad13c();
    virtual void Pad140();
    virtual void Pad144();
    virtual void Pad148();
    virtual void Pad14c();
    virtual void Pad150();
    virtual void Pad154();
    virtual void Pad158();
    virtual void Pad15c();
    virtual void Pad160();
    virtual void Pad164();
    virtual void Pad168();
    virtual void Pad16c();
    virtual void Pad170();
    virtual void Pad174();
    virtual void Pad178();
    virtual void S17c_a9bd88(float, float, void*, void*);
};

struct Timer2_a9bd88 {
    uint8_t mData[0x18];
    // STUB: 0x00890198
    uint32_t GetElapsedTime() const;
};

struct Link2_a9bd88 {
    Link2_a9bd88* mpNext;
    Link2_a9bd88* mpPrev;
    int32_t mn[11];
    Counted_a9bd88* mpObj;
    uint8_t mbFlag;
    uint8_t mPad[3];
    uint32_t mnTimer;
};

struct Link_a9bd88 {
    Link_a9bd88* mpNext;
    uint8_t mPad04[0x10];
    int32_t mnR1[4];
    int32_t mnR2[4];
};

struct Zone_a9bd88 {
    Link_a9bd88* mpHead;
    uint32_t Fn00551630(int32_t x, int32_t y);
};

struct Eff_a9bd88 {
    Link2_a9bd88* mpHead;
    uint32_t mnPad04;
    Timer2_a9bd88 mTimer;
    uint32_t mnNext;
    uint32_t mnLast;
    // STUB: 0x00551fc0
    void Fn00551fc0();
    // STUB: 0x0054ec60
    void Fn0054ec60(Link2_a9bd88* pItem);
    void Fn00552a20();
    // STUB: 0x00552bd0
    void Fn00552bd0();
};

struct In_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual bool S1c_a9bd88(void*);
    virtual void Pad20();
    virtual bool S24_a9bd88(void*);
};

struct Link4_a9bd88;
struct Link5_a9bd88 {
    Link5_a9bd88* mpNext;
    uint32_t mnPad04;
    uint32_t mnId;
};
struct Vec2_a9bd88 {
    Lead_a9bd88** mpBegin;
    Lead_a9bd88** mpEnd;
    Lead_a9bd88** mpCap;
    // STUB: 0x007ebd30
    void Fn007ebd30(Lead_a9bd88** pItem);
};
struct Link4_a9bd88 {
    Link4_a9bd88* mpNext;
    Link4_a9bd88* mpPrev;
    Lead_a9bd88* mpData;
};

struct Resp_a9bd88 {
    // STUB: 0x00553e90
    bool Fn00553e90(In_a9bd88* pStream);
    Link2_a9bd88* mpHead;
    // STUB: 0x00552a80
    bool Fn00552a80(Stream_a9bd88* pStream);
};

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

#define A9BD88_AT(T, p, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(p) + (off)))

// FUNCTION: 0x0054db50
Rec_a9bd88* Fn0054db50(Rec_a9bd88* first, Rec_a9bd88* last, Rec_a9bd88* dest, void* /*pTag*/, uint32_t /*zero*/)
{
    int32_t n = last - first;
    while (n > 0) {
        *dest = *first;
        ++first;
        ++dest;
        --n;
    }
    return dest;
}

// FUNCTION: 0x0054dba0
bool cSC4TrafficAutomataManager::Init()
{
    if (!A9BD88_FIELD(bool, 0x34)) {
        cSC4AutomataManager::Init();
        mnA9c = 0xffffffff;
        mnAa0 = 0xffffffff;
        if (gpB43cec) {
            Counted_a9bd88* sim = OB_PTR(Counted_a9bd88, gpB43cec->GetTrafficSimulator());
            mpA88 = sim;
            sim->S04_a9bd88();
        }
        reinterpret_cast<Timer_a9bd88*>(reinterpret_cast<char*>(this) + 0xac0)->Start();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0054dbf0 score 13
uint32_t cSC4TrafficAutomataManager::Dispatch_2(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, uint32_t a7)
{
    uint32_t loc[4];
    Key_a9bd88 key = *OB_PTR(Key_a9bd88, a6);
    Rec_a9bd88* found = 0;
    if (key.mnC == 0) {
        if (reinterpret_cast<Mgr_a9bd88*>(this)->S50_a9bd88(OB_PTR(void, a2), loc)) {
            found = static_cast<Rec_a9bd88*>(reinterpret_cast<Mgr_a9bd88*>(this)->S64_a9bd88(OB_PTR(void, a1), 0, loc[0], loc[1]));
            if (found) {
                key.mnA = found->mn[4];
                key.mnB = found->mn[5];
                key.mnC = found->mn[6];
            }
        }
    }
    void* car = CreateAutomatonInternal(a1, a4, &key, OB_ADDR(found), a7);
    if (car) {
        AddAutomaton(car);
        uint32_t result = Dispatch(OB_ADDR(car), a2, a3, a4, a5);
        OB_PTR(Counted_a9bd88, OB_ADDR(car))->S08_a9bd88();
        if (!result) {
            RemoveAutomaton(OB_ADDR(car), 1);
            return result;
        }
        if (!A9BD88_FIELD(bool, 0x4c)) {
            if (!OB_PTR(Lead_a9bd88, OB_ADDR(car))->S7c_a9bd88(0x80)) {
                OB_PTR(Stream_a9bd88, result)->S24_a9bd88(0);
            }
        }
        return result;
    }
    return OB_ADDR(car);
}
#endif

// FUNCTION: 0x0054df40
float cSC4TrafficAutomataManager::Slot75_a9bd88(uint32_t a)
{
    Cnt_a9bd88* sim = OB_PTR(Cnt_a9bd88, gpB43cec->GetResidentialSimulator());
    int32_t n = static_cast<int32_t>(sim->S40_a9bd88());
    float v;
    OB_PTR(Clock_a9bd88, gpB43cec->Get24HourClock())->S50_a9bd88(&v);
    Curve_a9bd88* c = static_cast<Curve_a9bd88*>(Slot85_a9bd88(a));
    float o = c->GetOutputValue(static_cast<float>(n));
    return o * (v * 0.00027777778f);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0054dfb0 score 26
bool cSC4TrafficAutomataManager::IsAutomatonOnscreen(void* pAuto)
{
    bool r = false;
    if (pAuto) {
        float x0 = mfView14[0] - 48.0f;
        float z0 = mfView14[1] - 48.0f;
        float x1 = mfView14[2] + 48.0f;
        float z1 = mfView14[3] + 48.0f;
        float pos[4];
        static_cast<Lead_a9bd88*>(pAuto)->S1c_a9bd88(pos);
        if (pos[0] >= x0 && pos[2] >= z0 && pos[0] <= x1 && pos[2] <= z1) {
            r = true;
        }
    }
    return r;
}
#endif

// FUNCTION: 0x0054fbc0
void cSC4TrafficAutomataManager::RecalculateLeaders(uint32_t pAuto)
{
    Node_a9bd88* n = static_cast<Node_a9bd88*>(mpAutomataList)->mpNext;
    while (n != mpAutomataList) {
        Lead_a9bd88* a = static_cast<Lead_a9bd88*>(n->mpData);
        if (A9BD88_AT(uint32_t, a, 0xb0) == pAuto) {
            Counted_a9bd88* x = a->S250_a9bd88();
            Counted_a9bd88* old = A9BD88_AT(Counted_a9bd88*, a, 0xb0);
            if (x != old) {
                if (x) {
                    x->S04_a9bd88();
                }
                A9BD88_AT(Counted_a9bd88*, a, 0xb0) = x;
                if (old) {
                    old->S08_a9bd88();
                }
            }
        }
        n = n->mpNext;
    }
}

// FUNCTION: 0x005516c0
bool cSC4TrafficAutomataManager::HandleRemoveOccupant(uint32_t pOcc)
{
    if (pOcc) {
        Rec_a9bd88* it = static_cast<Rec_a9bd88*>(mpRespBegin);
        if (it != mpRespEnd) {
            do {
                if (OB_PTR(Counted_a9bd88, it->mn[1]) == OB_PTR(Counted_a9bd88, pOcc)) {
                    OB_PTR(Counted_a9bd88, it->mn[1])->S08_a9bd88();
                    Rec_a9bd88* next = it + 1;
                    if (next != mpRespEnd) {
                        uint32_t tag;
                        Fn0054db50(next, static_cast<Rec_a9bd88*>(mpRespEnd), it, &tag, 0);
                    }
                    mpRespEnd = static_cast<Rec_a9bd88*>(mpRespEnd) - 1;
                } else {
                    ++it;
                }
            } while (it != mpRespEnd);
        }
    }
    return cSC4AutomataManager::HandleRemoveOccupant(pOcc);
}

// FUNCTION: 0x00553300
void cSC4TrafficAutomataManager::DoAnimationTick(uint32_t a, uint32_t b)
{
    reinterpret_cast<Eff_a9bd88*>(reinterpret_cast<char*>(this) + 0xab8)->Fn00552bd0();
    if (static_cast<int32_t>(mnMaxCount) > 0 && !mbPaused && !gbB21b9c) {
        if (A9BD88_FIELD(bool, 0x4c)) {
            Slot76_a9bd88(*reinterpret_cast<float*>(&b));
        }
        if (mpRespBegin != mpRespEnd) {
            UpdateResponseList(b);
        }
    }
    cSC4AutomataManager::DoAnimationTick(a, b);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00553570 score 6
bool cSC4TrafficAutomataManager::Slot03_a80784(void* pStream)
{
    Stream_a9bd88* s = static_cast<Stream_a9bd88*>(pStream);
    s->S1c_a9bd88(3);
    bool ok = cSC4AutomataManager::Slot03_a80784(pStream);
    if (ok) {
        s->S24_a9bd88(OB_ADDR(A9BD88_FIELD(void*, 0xa8c)));
        uint32_t v = 0;
        if (A9BD88_FIELD(uint32_t, 0xa98) != A9BD88_FIELD(uint32_t, 0xa94)) {
            v = A9BD88_AT(uint32_t, A9BD88_FIELD(void*, 0xa98), 8);
        }
        s->S24_a9bd88(v);
        return reinterpret_cast<Resp_a9bd88*>(reinterpret_cast<char*>(this) + 0xab8)->Fn00552a80(s);
    }
    return ok;
}
#endif

// FUNCTION: 0x0054dd50
void cSC4TrafficAutomataManager::Fn0054dd50(uint32_t a1, void* pAuto, uint32_t a3, void* pOut)
{
    int32_t loc[4];
    Loc_a9bd88* l = static_cast<Own_a9bd88*>(pAuto)->Sc0_a9bd88();
    l->S2c_a9bd88(loc);
    Rec_a9bd88* r = static_cast<Rec_a9bd88*>(reinterpret_cast<Mgr_a9bd88*>(this)->S64_a9bd88(OB_PTR(void, a1), a3, loc[0], loc[1]));
    if (r) {
        uint32_t* out = static_cast<uint32_t*>(pOut);
        out[0] = r->mn[4];
        out[1] = r->mn[5];
        out[2] = r->mn[6];
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x0054ddb0 score 27
void cSC4TrafficAutomataManager::Slot72_a9bd88(void* a1, void* a2, uint32_t a3, float a4, void* a5)
{
    uint32_t type;
    switch (a3) {
    case 1:
        type = mnA90;
        break;
    case 2:
        type = 2;
        break;
    case 3:
        type = 4;
        break;
    case 4:
        type = 3;
        break;
    case 5:
        type = 5;
        break;
    case 6:
        type = 6;
        break;
    case 7:
    case 8:
        Slot88_a9bd88(a1, a2, a4, a5);
        return;
    case 9:
        type = 7;
        break;
    case 10:
        type = 8;
        break;
    default: {
        uint32_t* z = static_cast<uint32_t*>(a5);
        for (int32_t i = 0; i < 16; ++i) {
            z[i] = 0;
        }
        return;
    }
    }
    float f = Slot87_a9bd88(a1, a3);
    int32_t loc[4];
    static_cast<Own_a9bd88*>(a1)->Sc0_a9bd88()->S2c_a9bd88(loc);
    bool neg = a4 < 0.0f;
    a4 = std::fabs(a4);
    const uint16_t* m = static_cast<Sim_a9bd88*>(mpA88)->S30_a9bd88(loc[0], loc[1], type, neg);
    float* out = static_cast<float*>(a5);
    int32_t i = 4;
    do {
        int32_t j = 4;
        do {
            *out++ = static_cast<float>(*m++) * f * a4;
            --j;
        } while (j);
        --i;
    } while (i);
}
#endif

// ---- batch 3 ----

struct Vec_a9bd88 {
    Rec_a9bd88* mpBegin;
    Rec_a9bd88* mpEnd;
    Rec_a9bd88* mpCap;
    // STUB: 0x00748f20
    void Fn00748f20(Rec_a9bd88* pos, void* pTag, Rec_a9bd88* pVal, uint32_t n, uint32_t bFlag);
};

struct Rng_a9bd88 {
    // STUB: 0x00913a06
    uint32_t Fn00913a06(uint32_t n);
};

// STUB: 0x005d99a0
uint32_t Fn005d99a0(Stream_a9bd88* pStream, uint32_t value);
// STUB: 0x005d9fd0
uint32_t Fn005d9fd0(Stream_a9bd88* pStream, uint32_t value);

// FUNCTION: 0x0054e690
void Lead_a9bd88::Fn0054e690(uint32_t a)
{
    Path_a9bd88* p = A9BD88_AT(Path_a9bd88*, this, 0x1ec);
    if (p) {
        p->S04_a9bd88();
    }
    uint32_t b = A9BD88_AT(uint32_t, this, 0x1f4);
    S210_a9bd88(0, b, 0, 1);
    A9BD88_AT(uint32_t, this, 0x1e4) = a;
    S210_a9bd88(OB_ADDR(p), b, 0, 1);
    if (p) {
        p->S08_a9bd88();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00551630 score 29
uint32_t Zone_a9bd88::Fn00551630(int32_t x, int32_t y)
{
    uint32_t r = 0;
    Link_a9bd88* head = mpHead;
    Link_a9bd88* n = head->mpNext;
    while (n != head) {
        Link_a9bd88* cur = n;
        n = n->mpNext;
        if (x >= cur->mnR1[0] && y >= cur->mnR1[1] && x <= cur->mnR1[2] && y <= cur->mnR1[3]) {
            r |= 1;
            if (x >= cur->mnR2[0] && y >= cur->mnR2[1] && x <= cur->mnR2[2] && y <= cur->mnR2[3]) {
                r |= 2;
            }
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00552a20 score 6
void Eff_a9bd88::Fn00552a20()
{
    Link2_a9bd88* head = mpHead;
    for (Link2_a9bd88* n = head->mpNext; n != mpHead; n = n->mpNext) {
        if (n->mbFlag && n->mpObj) {
            Ctl_a9bd88* ctl = OB_PTR(Ctl_a9bd88, gpB43cec->GetAutomataControllerManager());
            ctl->S38_a9bd88(OB_ADDR(n->mpObj));
            n->mbFlag = 0;
            if (n->mpObj) {
                Counted_a9bd88* o = n->mpObj;
                n->mpObj = 0;
                o->S08_a9bd88();
            }
            n->mnTimer = 0;
        }
    }
    Fn00551fc0();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00552a80 score 5
bool Resp_a9bd88::Fn00552a80(Stream_a9bd88* s)
{
    s->S1c_a9bd88(1);
    uint32_t count = 0;
    for (Link2_a9bd88* c = mpHead->mpNext; c != mpHead; c = c->mpNext) {
        ++count;
    }
    s->S24_a9bd88(count);
    for (Link2_a9bd88* p = mpHead->mpNext; p != mpHead; p = p->mpNext) {
        s->S20_a9bd88(p->mn[0]);
        s->S20_a9bd88(p->mn[1]);
        s->S24_a9bd88(p->mn[2]);
        s->S20_a9bd88(p->mn[3]);
        s->S20_a9bd88(p->mn[4]);
        s->S20_a9bd88(p->mn[5]);
        s->S20_a9bd88(p->mn[6]);
        s->S20_a9bd88(p->mn[7]);
        s->S20_a9bd88(p->mn[8]);
        s->S20_a9bd88(p->mn[9]);
        s->S20_a9bd88(p->mn[10]);
        Fn005d99a0(s, OB_ADDR(p->mpObj));
        Fn005d9fd0(s, p->mbFlag);
        s->S24_a9bd88(p->mnTimer);
    }
    return !s->S48_a9bd88();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00552bd0 score 148
void Eff_a9bd88::Fn00552bd0()
{
    uint32_t now = mTimer.GetElapsedTime();
    if (now >= mnNext) {
        mnNext = now + 500;
        uint32_t dt = now - mnLast;
        Link2_a9bd88* head = mpHead;
        Link2_a9bd88* n = head->mpNext;
        while (n != mpHead) {
            Link2_a9bd88* cur = n;
            n = n->mpNext;
            if (cur->mnTimer < dt) {
                if (cur->mbFlag && cur->mpObj) {
                    Ctl_a9bd88* ctl = OB_PTR(Ctl_a9bd88, gpB43cec->GetAutomataControllerManager());
                    ctl->S38_a9bd88(OB_ADDR(cur->mpObj));
                }
                cur->mbFlag = 0;
                if (cur->mpObj) {
                    Counted_a9bd88* o = cur->mpObj;
                    cur->mpObj = 0;
                    o->S08_a9bd88();
                }
                cur->mnTimer = 0;
                cur->mpPrev->mpNext = cur->mpNext;
                cur->mpNext->mpPrev = cur->mpPrev;
                if (cur->mpObj) {
                    cur->mpObj->S08_a9bd88();
                }
                Fn0090cf63(cur);
            } else {
                cur->mnTimer = cur->mnTimer - dt;
                if (cur->mpObj) {
                    float pos[3];
                    int32_t cell[2];
                    cur->mpObj->S20_a9bd88(pos);
                    float* pf = pos;
                    gpB43cec->PositionToCell(pf[0], pf[2], &cell[0], &cell[1]);
                    if (cur->mn[0] != cell[0] || cur->mn[1] != cell[1]) {
                        cur->mn[1] = cell[1];
                        cur->mn[0] = cell[0];
                        Fn0054ec60(cur);
                    }
                }
            }
        }
        mnLast = now;
    }
}
#endif

struct HNode_a9bd88;

struct Curve2_a9bd88 {
    uint8_t mData[0x10];
    // STUB: 0x005f4430
    void Fn005f4430(const Curve2_a9bd88* pSrc);
    // STUB: 0x007d0410
    void Fn007d0410();
};

struct Val_a9bd88 {
    uint32_t mn[4];
    Curve2_a9bd88 mCurve;
};

struct Pair_a9bd88 {
    uint32_t mnKey;
    Val_a9bd88 mVal;
};

struct HNode_a9bd88 {
    HNode_a9bd88* mpNext;
    Pair_a9bd88 mPair;
};

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

struct Hash_a9bd88 {
    uint32_t mnPad00;
    HNode_a9bd88** mpBuckets;
    HNode_a9bd88** mpBucketsEnd;
    uint32_t mnPad0c;
    uint32_t mnCount;
    // STUB: 0x004f0940
    void Fn004f0940(uint32_t n);
    // STUB: 0x00555350
    Pair_a9bd88* Fn00555350(const Pair_a9bd88* pPair);
    Pair_a9bd88* Fn00555350Draft(const Pair_a9bd88* pPair);
    void* Fn00555400(const uint32_t* pKey);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00555350 score 67
Pair_a9bd88* Hash_a9bd88::Fn00555350Draft(const Pair_a9bd88* pPair)
{
    Fn004f0940(mnCount + 1);
    uint32_t idx = pPair->mnKey % static_cast<uint32_t>(mpBucketsEnd - mpBuckets);
    HNode_a9bd88* first = mpBuckets[idx];
    HNode_a9bd88* n = static_cast<HNode_a9bd88*>(Fn0090cf54(0x28));
    n->mpNext = 0;
    n->mPair.mnKey = pPair->mnKey;
    n->mPair.mVal.mn[0] = pPair->mVal.mn[0];
    n->mPair.mVal.mn[1] = pPair->mVal.mn[1];
    n->mPair.mVal.mn[2] = pPair->mVal.mn[2];
    n->mPair.mVal.mn[3] = pPair->mVal.mn[3];
    n->mPair.mVal.mCurve.Fn005f4430(&pPair->mVal.mCurve);
    n->mpNext = first;
    mpBuckets[idx] = n;
    ++mnCount;
    return &n->mPair;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00555400 score 98
void* Hash_a9bd88::Fn00555400(const uint32_t* pKey)
{
    uint32_t key = *pKey;
    HNode_a9bd88* n = mpBuckets[key % static_cast<uint32_t>(mpBucketsEnd - mpBuckets)];
    while (n) {
        if (n->mPair.mnKey == key) {
            return &n->mPair.mVal;
        }
        n = n->mpNext;
    }
    Pair_a9bd88 tmp;
    tmp.mVal.mCurve.Fn007d0410();
    tmp.mnKey = key;
    tmp.mVal.mn[0] = 0;
    tmp.mVal.mn[1] = 0;
    tmp.mVal.mn[2] = 0;
    tmp.mVal.mn[3] = 0;
    return &Fn00555350(&tmp)->mVal;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00552450 score 80
bool cSC4TrafficAutomataManager::GetDispatchDestinationPoint(void* pAuto, void* pOut)
{
    bool r = false;
    uint8_t* a = static_cast<uint8_t*>(pAuto);
    if (A9BD88_AT(uint8_t*, a, 0x23c) != A9BD88_AT(uint8_t*, a, 0x22c)) {
        uint8_t* cur = A9BD88_AT(uint8_t*, a, 0x23c);
        uint8_t* back;
        if (cur == A9BD88_AT(uint8_t*, a, 0x240)) {
            back = A9BD88_AT(uint8_t*, A9BD88_AT(uint8_t**, a, 0x248), -4) + 0x7b;
        } else {
            back = cur - 3;
        }
        uint8_t rx = back[0];
        uint8_t ry = back[1];
        Dest_a9bd88* d = A9BD88_FIELD(Net2_a9bd88*, 0xa7c)->S2c_a9bd88(rx, ry);
        if (d) {
            Dest2_a9bd88* d2 = d->Sc4_a9bd88();
            if (d2) {
                uint32_t t = Slot73_a9bd88(A9BD88_AT(uint32_t, a, 0x1e4));
                uint32_t v = static_cast<Lead_a9bd88*>(pAuto)->S23c_a9bd88(OB_ADDR(pOut), 0);
                return d2->S54_a9bd88(t, v);
            }
        }
    }
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00552d00 score 69
bool cSC4TrafficAutomataManager::Shutdown()
{
    if (A9BD88_FIELD(bool, 0x34)) {
        if (mpA88) {
            static_cast<Counted_a9bd88*>(mpA88)->S08_a9bd88();
            mpA88 = 0;
        }
        for (Rec_a9bd88* it = static_cast<Rec_a9bd88*>(mpRespBegin); it != mpRespEnd; ++it) {
            if (it->mn[1]) {
                OB_PTR(Counted_a9bd88, it->mn[1])->S08_a9bd88();
            }
        }
        mpRespEnd = mpRespBegin;
        reinterpret_cast<Eff_a9bd88*>(reinterpret_cast<char*>(this) + 0xab8)->Fn00552a20();
    }
    return cSC4AutomataManager::Shutdown();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005538d0 score 98
bool cSC4TrafficAutomataManager::DispatchResponseAutomata(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6)
{
    if (!a2) {
        return false;
    }
    Rec_a9bd88 rec;
    rec.mn[0] = 0;
    rec.mn[1] = 0;
    rec.mn[2] = 0;
    rec.mn[3] = 0;
    rec.mn[4] = 0;
    rec.mn[5] = 0;
    rec.mn[6] = 0;
    Vec_a9bd88* v = reinterpret_cast<Vec_a9bd88*>(reinterpret_cast<char*>(this) + 0xaa8);
    if (v->mpEnd != v->mpCap) {
        if (v->mpEnd) {
            *v->mpEnd = rec;
        }
        v->mpEnd = v->mpEnd + 1;
    } else {
        Rec_a9bd88 copy = rec;
        v->Fn00748f20(v->mpEnd, &rec, &copy, 1, 1);
    }
    Rec_a9bd88* p = v->mpEnd - 1;
    p->mn[0] = a1;
    p->mn[1] = a2;
    OB_PTR(Counted_a9bd88, a2)->S04_a9bd88();
    p->mn[2] = a3;
    reinterpret_cast<uint8_t*>(p)[0xc] = static_cast<uint8_t>(a4);
    reinterpret_cast<uint8_t*>(p)[0xd] = static_cast<uint8_t>(a5);
    p->mn[4] = a6 | 0x2000000;
    p->mn[6] = 0;
    p->mn[5] = 0;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005539a0 score 118
void cSC4TrafficAutomataManager::Slot81_a9bd88(void* pGroup, uint32_t kind)
{
    Link4_a9bd88* head = A9BD88_AT(Link4_a9bd88*, pGroup, 0x1c);
    Vec2_a9bd88 vec;
    vec.mpBegin = 0;
    vec.mpEnd = 0;
    vec.mpCap = 0;
    for (Link4_a9bd88* n = head->mpNext; n != head; n = n->mpNext) {
        Lead_a9bd88* a = n->mpData;
        if (((a->S220_a9bd88() >> 24) & 0xf) == kind && a->S7c_a9bd88(2) && !a->S7c_a9bd88(0x200000)
            && !a->S7c_a9bd88(0x80) && !a->S7c_a9bd88(0x2000000) && a->S80_a9bd88() > 0.0f) {
            vec.Fn007ebd30(&a);
        }
    }
    if (vec.mpBegin != vec.mpEnd) {
        uint32_t n = static_cast<uint32_t>(vec.mpEnd - vec.mpBegin);
        uint32_t r = reinterpret_cast<Rng_a9bd88*>(reinterpret_cast<char*>(this) + 0x50)->Fn00913a06(n);
        OB_PTR(Counted_a9bd88, OB_ADDR(vec.mpBegin[r]))->S08_a9bd88();
    }
    if (vec.mpBegin) {
        Fn0090cf63(vec.mpBegin);
    }
}
#endif

// FUNCTION: 0x0054f7b0
void cSC4TrafficAutomataManager::HandlePostCityInit()
{
    cSC4AutomataManager::HandlePostCityInit();
    if (A9BD88_FIELD(bool, 0x10)) {
        Node_a9bd88* head = static_cast<Node_a9bd88*>(mpAutomataList);
        for (Node_a9bd88* n = head->mpNext; n != mpAutomataList; n = n->mpNext) {
            Lead_a9bd88* a = static_cast<Lead_a9bd88*>(n->mpData);
            Base1_a9bd88* b = A9BD88_AT(Base1_a9bd88*, a, 0x1ec);
            if (b) {
                Path_a9bd88* path = b->Sc4_a9bd88();
                Path_a9bd88* old = A9BD88_AT(Path_a9bd88*, a, 0x1f0);
                if (path != old) {
                    if (path) {
                        path->S04_a9bd88();
                    }
                    A9BD88_AT(Path_a9bd88*, a, 0x1f0) = path;
                    if (old) {
                        old->S08_a9bd88();
                    }
                }
                Path_a9bd88* cur = A9BD88_AT(Path_a9bd88*, a, 0x1f0);
                if (cur) {
                    A9BD88_AT(uint32_t, a, 0x1f8) = cur->S0c_a9bd88(A9BD88_AT(uint32_t, a, 0x1f4), 0);
                }
            }
            if (a->S258_a9bd88()) {
                Counted_a9bd88* x = a->S250_a9bd88();
                Counted_a9bd88* old = A9BD88_AT(Counted_a9bd88*, a, 0xb0);
                if (x != old) {
                    if (x) {
                        x->S04_a9bd88();
                    }
                    A9BD88_AT(Counted_a9bd88*, a, 0xb0) = x;
                    if (old) {
                        old->S08_a9bd88();
                    }
                }
            }
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00554410 score 35
bool cSC4TrafficAutomataManager::Slot04_a80784(void* pStream)
{
    In_a9bd88* s = static_cast<In_a9bd88*>(pStream);
    uint16_t ver;
    s->S1c_a9bd88(&ver);
    if (ver != 2 && ver != 3) {
        return false;
    }
    bool ok = cSC4AutomataManager::Slot04_a80784(pStream);
    if (ok) {
        uint32_t tmp;
        s->S24_a9bd88(&tmp);
        A9BD88_FIELD(void*, 0xa98) = *A9BD88_FIELD(void**, 0xa94);
        uint32_t id;
        s->S24_a9bd88(&id);
        if (id && A9BD88_FIELD(void*, 0xa98) != A9BD88_FIELD(void*, 0xa94)) {
            Link5_a9bd88* c = A9BD88_FIELD(Link5_a9bd88*, 0xa98);
            while (c->mnId != id) {
                c = c->mpNext;
                A9BD88_FIELD(Link5_a9bd88*, 0xa98) = c;
                if (c == A9BD88_FIELD(void*, 0xa94)) {
                    break;
                }
            }
        }
        if (ver > 2) {
            ok = reinterpret_cast<Resp_a9bd88*>(reinterpret_cast<char*>(this) + 0xab8)->Fn00553e90(s);
        }
    }
    return ok;
}
#endif

// ---- batch 4 ----

struct PtrVec_a9bd88 {
    void** mpBegin;
    void** mpEnd;
    void** mpCap;
    // STUB: 0x007ebd30
    void Fn007ebd30(void** pItem);
};

struct NetQ_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual Dest_a9bd88* S38_a9bd88(uint32_t, uint32_t);
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual void Pad48();
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual bool S64_a9bd88(void*, uint32_t, uint32_t, uint32_t, uint32_t);
    virtual bool S68_a9bd88(void*, uint32_t, uint32_t, uint32_t, uint32_t);
};
struct Mgr2_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual void Pad38();
    virtual void Pad3c();
    virtual void Pad40();
    virtual void Pad44();
    virtual uint32_t S48_a9bd88(void*, void*, void*, uint32_t, void*, uint32_t, void*);
    virtual void Pad4c();
    virtual void Pad50();
    virtual void Pad54();
    virtual void Pad58();
    virtual void Pad5c();
    virtual void Pad60();
    virtual void Pad64();
    virtual void Pad68();
    virtual void Pad6c();
    virtual void Pad70();
    virtual void Pad74();
    virtual void Pad78();
    virtual void Pad7c();
    virtual void Pad80();
    virtual void Pad84();
    virtual void Pad88();
    virtual void Pad8c();
    virtual void Pad90();
    virtual void Pad94();
    virtual void Pad98();
    virtual void Pad9c();
    virtual void Pada0();
    virtual void Pada4();
    virtual void Pada8();
    virtual void Padac();
    virtual void Padb0();
    virtual void Padb4();
    virtual void Padb8();
    virtual void Padbc();
    virtual void Padc0();
    virtual void Padc4();
    virtual void Padc8();
    virtual void Padcc();
    virtual void Padd0();
    virtual void Padd4();
    virtual void Padd8();
    virtual void Paddc();
    virtual void Pade0();
    virtual void Pade4();
    virtual void Pade8();
    virtual void Padec();
    virtual void Padf0();
    virtual void Padf4();
    virtual void Padf8();
    virtual void Padfc();
    virtual void Pad100();
    virtual void Pad104();
    virtual void Pad108();
    virtual void Pad10c();
    virtual void Pad110();
    virtual void Pad114();
    virtual void Pad118();
    virtual uint32_t S11c_a9bd88(void*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
    virtual void Pad120();
    virtual void Pad124();
    virtual void Pad128();
    virtual void Pad12c();
    virtual void Pad130();
    virtual void Pad134();
    virtual void Pad138();
    virtual void Pad13c();
    virtual void Pad140();
    virtual void Pad144();
    virtual void Pad148();
    virtual void Pad14c();
    virtual void Pad150();
    virtual void Pad154();
    virtual void Pad158();
    virtual void Pad15c();
    virtual void Pad160();
    virtual bool S164_a9bd88(uint32_t, void*, uint32_t, uint32_t, uint32_t);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00552de0 score 258
bool cSC4TrafficAutomataManager::UpdateResponseList(uint32_t b)
{
    float dt = *reinterpret_cast<float*>(&b);
    Rec_a9bd88* it = static_cast<Rec_a9bd88*>(mpRespBegin);
    while (it != mpRespEnd) {
        float t = *reinterpret_cast<float*>(&it->mn[5]) - dt;
        *reinterpret_cast<float*>(&it->mn[5]) = t;
        if (t > 0.0f) {
            ++it;
            continue;
        }
        bool done = false;
        uint32_t x;
        uint32_t y;
        if (reinterpret_cast<uint8_t*>(it)[0xc]) {
            x = 0;
            y = 1;
        } else {
            x = reinterpret_cast<uint8_t*>(it)[0xd];
            y = x + 2;
        }
        PtrVec_a9bd88 vec;
        vec.mpBegin = 0;
        vec.mpEnd = 0;
        vec.mpCap = 0;
        if (A9BD88_FIELD(NetQ_a9bd88*, 0xa7c)->S68_a9bd88(&vec, it->mn[1], y, x, 0xc49)) {
            uint32_t n = it->mn[2];
            for (uint32_t i = 0; i < n && vec.mpBegin != vec.mpEnd; ++i) {
                uint32_t k = reinterpret_cast<Rng_a9bd88*>(reinterpret_cast<char*>(this) + 0x50)->Fn00913a06(static_cast<uint32_t>(vec.mpEnd - vec.mpBegin));
                void* pick = vec.mpBegin[k];
                uint32_t r;
                if (reinterpret_cast<uint8_t*>(it)[0xc]) {
                    r = reinterpret_cast<Mgr2_a9bd88*>(this)->S11c_a9bd88(pick, reinterpret_cast<uint8_t*>(it)[0xd], it->mn[0], it->mn[4], 0, 0);
                } else {
                    uint32_t key[3] = {0, 0, 0};
                    r = reinterpret_cast<Mgr2_a9bd88*>(this)->S48_a9bd88(pick, &it->mn[0], key, 3, 0, 0, 0);
                }
                if (r) {
                    it->mn[2] = it->mn[2] - 1;
                    if (pick) {
                        for (void** p = vec.mpBegin; p != vec.mpEnd; ++p) {
                            if (*p == pick) {
                                OB_PTR(Counted_a9bd88, OB_ADDR(pick))->S08_a9bd88();
                                for (void** q = p; q + 1 != vec.mpEnd; ++q) {
                                    *q = *(q + 1);
                                }
                                --vec.mpEnd;
                                break;
                            }
                        }
                    }
                }
            }
            if (it->mn[2] == 0) {
                done = true;
            }
            for (void** p = vec.mpBegin; p != vec.mpEnd; ++p) {
                OB_PTR(Counted_a9bd88, OB_ADDR(*p))->S08_a9bd88();
            }
            vec.mpEnd = vec.mpBegin;
        }
        if (!done) {
            it->mn[6] = it->mn[6] + 1;
            if (it->mn[6] <= 5) {
                *reinterpret_cast<float*>(&it->mn[5]) = 1000.0f;
                ++it;
                if (vec.mpBegin) {
                    Fn0090cf63(vec.mpBegin);
                }
                continue;
            }
        }
        OB_PTR(Counted_a9bd88, it->mn[1])->S08_a9bd88();
        Rec_a9bd88* next = it + 1;
        if (next != mpRespEnd) {
            uint32_t tag;
            Fn0054db50(next, static_cast<Rec_a9bd88*>(mpRespEnd), it, &tag, 0);
        }
        mpRespEnd = static_cast<Rec_a9bd88*>(mpRespEnd) - 1;
        if (vec.mpBegin) {
            Fn0090cf63(vec.mpBegin);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00553080 score 0
bool cSC4TrafficAutomataManager::GetRandomCreationPoint(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, uint32_t a7)
{
    if (!(a6 & 0x22000)) {
        if (!CanCreateGroup(a1)) {
            return false;
        }
        bool ok = false;
        uint32_t mask;
        if (a1 == 0x4208 || a1 == 0x4217) {
            mask = 0x80;
        } else if (Fn0054d210(a1)) {
            mask = 0x100;
        } else if (Fn0054d230(a1)) {
            mask = 0x200;
        } else {
            mask = Fn0054d1a0(a1) ? 0 : 0xc49;
        }
        const float* pos = OB_PTR(const float, a2);
        int32_t cell[2];
        int32_t rect[4];
        gpB43cec->PositionToCell(pos[0], pos[2], &cell[0], &cell[1]);
        if (gpB43d08) {
            Dest_a9bd88* lot = static_cast<NetLot_a9bd88*>(gpB43d08)->S18_a9bd88(cell[0], cell[1], 0);
            if (lot) {
                lot->S38_a9bd88(rect);
            } else {
                rect[0] = cell[0];
                rect[2] = cell[0];
                rect[1] = cell[1];
                rect[3] = cell[1];
            }
        } else {
            rect[0] = cell[0];
            rect[2] = cell[0];
            rect[1] = cell[1];
            rect[3] = cell[1];
        }
        float size = static_cast<float>(gpB43cec->CellCountX()) * gpB43cec->CellWidthX();
        float lo = *reinterpret_cast<float*>(&a3);
        float hi = *reinterpret_cast<float*>(&a4);
        float v = hi;
        if (v > lo) {
            v = lo;
        } else if (v < size) {
            v = size;
        }
        PtrVec_a9bd88 vec;
        vec.mpBegin = 0;
        vec.mpEnd = 0;
        vec.mpCap = 0;
        if (A9BD88_FIELD(NetQ_a9bd88*, 0xa7c)->S64_a9bd88(&vec, static_cast<int32_t>(v * 0.0625f) , static_cast<int32_t>(size * 0.0625f), mask, 0)) {
            uint32_t k = reinterpret_cast<Rng_a9bd88*>(reinterpret_cast<char*>(this) + 0x50)->Fn00913a06(static_cast<uint32_t>(vec.mpEnd - vec.mpBegin));
            Lead_a9bd88* pick = static_cast<Lead_a9bd88*>(vec.mpBegin[k]);
            if (pick) {
                float p3[3];
                int32_t c2[2];
                pick->S20_a9bd88(p3);
                gpB43cec->PositionToCell(p3[0], p3[2], &c2[0], &c2[1]);
                float* out = OB_PTR(float, a5);
                out[0] = 0.0f;
                (void)c2;
            }
            ok = true;
            for (void** p = vec.mpBegin; p != vec.mpEnd; ++p) {
                OB_PTR(Counted_a9bd88, OB_ADDR(*p))->S08_a9bd88();
            }
            vec.mpEnd = vec.mpBegin;
        }
        if (vec.mpBegin) {
            Fn0090cf63(vec.mpBegin);
        }
        return ok;
    }
    return cSC4AutomataManager::GetRandomCreationPoint(a1, a2, a3, a4, a5, a6, a7);
}
#endif

// ---- batch 5 ----

// GLOBAL: 0x00b43d70
extern void* gpB43d70;
// GLOBAL: 0x00a9bd10
extern const int32_t gnA9bd10[8][2];

struct Timer3_a9bd88 {
    uint8_t mData[0x18];
    // STUB: 0x0088fedf
    void Fn0088fedf(uint32_t n);
    // STUB: 0x008905c4
    void Start();
    // STUB: 0x00890377
    uint32_t GetElapsedTime(float& rOut) const;
    // STUB: 0x00a6d837
    void Fn00a6d837();
};

struct Crime_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual bool S2c_a9bd88(void*);
    virtual void S30_a9bd88(uint32_t, uint32_t);
};
struct Net3_a9bd88 {
    virtual void Pad00();
    virtual void Pad04();
    virtual void Pad08();
    virtual void Pad0c();
    virtual void Pad10();
    virtual void Pad14();
    virtual void Pad18();
    virtual void Pad1c();
    virtual void Pad20();
    virtual void Pad24();
    virtual void Pad28();
    virtual void Pad2c();
    virtual void Pad30();
    virtual void Pad34();
    virtual Dest_a9bd88* S38_a9bd88(int32_t, int32_t);
    virtual void Pad3c();
    virtual void Pad40();
    virtual Rect_a9bd88* S44_a9bd88();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00553370 score 0
bool cSC4TrafficAutomataManager::Slot83_a9bd88()
{
    bool timedOut = false;
    Timer3_a9bd88 timer;
    timer.Fn0088fedf(4);
    if (gpB43d70) {
        Rect_a9bd88* r = A9BD88_FIELD(Net3_a9bd88*, 0xa7c)->S44_a9bd88();
        Vec_a9bd88 vec;
        vec.mpBegin = 0;
        vec.mpEnd = 0;
        vec.mpCap = 0;
        if (static_cast<Crime_a9bd88*>(gpB43d70)->S2c_a9bd88(&vec)) {
            timer.Start();
            uint32_t n = static_cast<uint32_t>(vec.mpEnd - vec.mpBegin);
            for (uint32_t i = 0; i < n; ++i) {
                Rec_a9bd88* rec = &vec.mpBegin[i];
                if (!reinterpret_cast<uint8_t*>(rec)[0xc]) {
                    int32_t x = static_cast<int32_t>(rec->mn[0]);
                    int32_t z = static_cast<int32_t>(rec->mn[1]);
                    if (x >= r->mnMinX && z >= r->mnMinY && x <= r->mnMaxX && z <= r->mnMaxY) {
                        Net3_a9bd88* net = A9BD88_FIELD(Net3_a9bd88*, 0xa7c);
                        Dest_a9bd88* found = net->S38_a9bd88(x, z);
                        if (!found) {
                            uint8_t d = 0;
                            do {
                                found = A9BD88_FIELD(Net3_a9bd88*, 0xa7c)->S38_a9bd88(x + gnA9bd10[d][0], z + gnA9bd10[d][1]);
                                ++d;
                            } while (!found && d < 8);
                        }
                        if (found) {
                            uint32_t dup = 0;
                            for (Rec_a9bd88* q = vec.mpBegin; q != vec.mpEnd; ++q) {
                                if (q->mn[0] == rec->mn[0] && q->mn[1] == rec->mn[1]) {
                                    ++dup;
                                }
                            }
                            if (PopulateNetworkOccupantForCrimeLayer(*reinterpret_cast<uint32_t*>(found), OB_ADDR(found), dup, 0, rec->mn[2])) {
                                static_cast<Crime_a9bd88*>(gpB43d70)->S30_a9bd88(i, 1);
                                float el;
                                timer.GetElapsedTime(el);
                                if (el >= 5.0f) {
                                    timedOut = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (vec.mpBegin) {
            Fn0090cf63(vec.mpBegin);
        }
    }
    timer.Fn00a6d837();
    return !timedOut;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0054ed90 score 0
bool cSC4TrafficAutomataManager::HandleRemoveNetworkOccupant(uint32_t pOcc)
{
    bool r = Fn004fc900(pOcc);
    int32_t rect[4];
    if (pOcc) {
        OB_PTR(Own_a9bd88, pOcc)->Sc0_a9bd88()->S2c_a9bd88(rect);
    }
    Node_a9bd88* head = static_cast<Node_a9bd88*>(mpAutomataList);
    for (Node_a9bd88* n = head->mpNext; n != mpAutomataList;) {
        Lead_a9bd88* a = static_cast<Lead_a9bd88*>(n->mpData);
        n = n->mpNext;
        if (A9BD88_AT(uint32_t, a, 0x1ec) == pOcc) {
            a->S210_a9bd88(0, 0, 0, 0);
            a->S21c_a9bd88();
        } else if (a->S7c_a9bd88(0x2000) && !a->S7c_a9bd88(0x20000)) {
            float pos[3];
            pos[0] = gfB2293c;
            pos[1] = gfB2293c;
            pos[2] = gfB2293c;
            a->S1c_a9bd88(pos);
            int32_t cx = static_cast<int32_t>(std::floor(pos[0] * 0.0625f));
            int32_t cz = static_cast<int32_t>(std::floor(pos[2] * 0.0625f));
            if (cx >= rect[0] && cz >= rect[1] && cx <= rect[2] && cz <= rect[3]) {
                a->S21c_a9bd88();
            }
        }
    }
    return r;
}
#endif
