#include <cstddef>
#include <vector>

#include "classes/cUnk00a9e5f4.h"
#include "classes/cUnk00a8edbc.h"
#include "classes/cUnk00a949b8.h"
#include "game/Globals.h"

// A node of the intrusive lists the class keeps (next, previous, the value).
struct cOccupant_a9e5f4;
struct cNewFire_a9e5f4;
struct Iter_a9e5f4;
struct Node_a9e5f4 {
    Node_a9e5f4* mpNext;
    Node_a9e5f4* mpPrev;
    cOccupant_a9e5f4* mpValue;
};

// A fire occupant (its view interface sits at +4).
struct cOccView_a9e5f4 {
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
    virtual void GetBounds(int32_t* out);
};
struct cOccupant_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    cOccView_a9e5f4 mView;
    // STUB: 0x00470250
    void SetVisible(bool);
    // STUB: 0x00472790
    void ViewUpdate();
};

// The message handed to Slot03_aaaa9c.
struct cMessage_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual uint32_t GetType();
};

// The 3D view global.
struct cView3D_a9e5f4 {
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
    virtual uint32_t GetViewType();
};
// GLOBAL: 0x00b43dc4
extern cView3D_a9e5f4* gpB43dc4_a9e5f4;

// The random generator and the timer the class keeps by value.
struct cRandom_a9e5f4 {
    // STUB: 0x00913696
    uint32_t RandomUint32Uniform();
    // STUB: 0x009136b1
    uint32_t RandomUint32UniformN(uint32_t);
    // STUB: 0x00913761
    float RandomFloatRange(double, double);
};
struct cTimer_a9e5f4 {
    // STUB: 0x00890181
    void SetUnits(uint32_t);
    // STUB: 0x0089058f
    void Restart();
    // STUB: 0x00890198
    uint32_t GetElapsedTime();
};

// A fire occupant as the class sees it: its remaining life sits at +0x50.
struct cFire_a9e5f4 {
    uint8_t mPad00[0x50];
    uint32_t mnLife;
    // STUB: 0x0046fe00
    void Fn0046fe00(uint32_t);
};

// The city and the objects it hands out.
struct cLayerItem_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Fn08(void*);
    virtual void Fn09(void*);
};
struct cLayer_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual cLayerItem_a9e5f4* Fn07(uint32_t);
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Fn13(void* listener, uint32_t a, uint32_t b, void* occupant, bool flagC4, bool flag);
    virtual void Fn14(void*);
};
struct cLayerU_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void* Fn07(uint32_t);
};
struct cSim_a9e5f4 {
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
    virtual void Fn20(void* listener);
};
struct cCity_a9e5f4 {
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
    virtual cSim_a9e5f4* Fn50();
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
    virtual cLayer_a9e5f4* Fn72();
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
    virtual float Fn91();
    virtual void Pad92();
    virtual uint32_t Fn93();
    virtual uint32_t Fn94();
    virtual void Pad95();
    virtual void Pad96();
    virtual void Fn97(int32_t, int32_t, void*, void*);
};
// GLOBAL: 0x00b43cec
extern cCity_a9e5f4* gpB43cec_a9e5f4;

// The message object the allocator hands out (vtable 0x00acec00).
// STUB: 0x009133da
void* Fn009133da(uint32_t size);
struct cMade_a9e5f4 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05(uint32_t);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Fn11(uint32_t);
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Fn16(uint32_t);
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
    virtual void Fn33(void*);
    uint8_t mData[0x28];
    // STUB: 0x009134d6
    cMade_a9e5f4();
    static void* operator new(size_t size) { return Fn009133da(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};
struct cRef_a9e5f4 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};
struct cOccIface_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual cRef_a9e5f4* Fn05();
};

// The game's pool allocator (global 0x00b207e4), fetched through a provider the first time it is needed.
struct Pool_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual Node_a9e5f4* Alloc(uint32_t size);
    virtual void Free(Node_a9e5f4* node);
};
// GLOBAL: 0x00b207e4
extern Pool_a9e5f4* gpB207e4_a9e5f4;

struct PoolRef_a9e5f4 {
    Pool_a9e5f4* mp;
    // STUB: 0x00411870
    void Drop();
};

struct Provider_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn05(uint32_t a, uint32_t b, PoolRef_a9e5f4* out);
};

// STUB: 0x008793ec
Provider_a9e5f4* Fn008793ec();

inline Pool_a9e5f4* GetPool_a9e5f4()
{
    if (!gpB207e4_a9e5f4) {
        PoolRef_a9e5f4 ref;
        ref.mp = 0;
        Provider_a9e5f4* provider = Fn008793ec();
        if (provider) {
            provider->Fn05(0x3ae4bea3, 0x3ae4beab, &ref);
        }
        gpB207e4_a9e5f4 = ref.mp;
        ref.Drop();
    }
    return gpB207e4_a9e5f4;
}

// The list the occupant manager fills; the original clears it out of line.
struct List_a9e5f4 {
    Node_a9e5f4* mpHead;
    // STUB: 0x00413e60
    void Clear();
};

struct Cell_a9e5f4 {
    int32_t mnX;
    int32_t mnY;
};

// The occupant manager (global 0x00b43d0c).
struct cOccMgr_a9e5f4 {
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
    virtual void Fn20(void* object, uint32_t arg);
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
    virtual void Fn40(List_a9e5f4* list, Cell_a9e5f4* from, Cell_a9e5f4* to, void* filter, int32_t flags);
};
// GLOBAL: 0x00b43d0c
extern cOccMgr_a9e5f4* gpB43d0c_a9e5f4;

// The fire list (an object whose first field is the head node) and the tree of toasts.
struct FireList_a9e5f4 {
    Node_a9e5f4* mpHead;
    // STUB: 0x00473ec0
    void Clear();
    // STUB: 0x007e98c0
    void PushBack(cNewFire_a9e5f4** value);
};
struct TreeNode_a9e5f4 {
    uint32_t mnColour;
    TreeNode_a9e5f4* mpRoot;
    TreeNode_a9e5f4* mpLeft;
    TreeNode_a9e5f4* mpRight;
};
struct Tree_a9e5f4 {
    TreeNode_a9e5f4* mpHeader;
    uint32_t mnSize;
    // STUB: 0x0046f820
    void Erase(TreeNode_a9e5f4* node);
    // STUB: 0x00497520
    void Find(Iter_a9e5f4* out, const uint32_t* key);
    // STUB: 0x0049a050
    void Insert(Iter_a9e5f4* out, const uint32_t* key);
};
// The curves cSC4FireOccupant keeps for its fires.
// GLOBAL: 0x00b2163c
extern void* gpB2163c;
// GLOBAL: 0x00b21638
extern void* gpB21638;


// The demolition utility (global 0x00b43d00): only its reference count is used here.
// GLOBAL: 0x00b43d00
extern cRef_a9e5f4* gpB43d00_a9e5f4;

// A response curve (the original's 0x005f4250 evaluates it at a value).
struct Curve_a9e5f4 {
    // STUB: 0x005f4250
    float Eval(float x);
};

// The flammability simulator (global 0x00b43d7c) and the grid it hands out.
struct cFlammGrid_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual uint8_t Fn07(uint32_t x, uint32_t z);
};
struct cFlammSim_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual cFlammGrid_a9e5f4* Fn05();
};
// GLOBAL: 0x00b43d7c
extern cFlammSim_a9e5f4* gpB43d7c_a9e5f4;

// The a9e460 interface with the pointer arguments the base's declaration lacks (slot 6 takes the occupant).
struct cFireIface_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual bool Fn06(void* occupant, uint32_t force, uint32_t seed, bool flag);
};

// The simulator global at 0x00b43d5c (two state queries).
struct cSimState_a9e5f4 {
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
    virtual bool Fn15();
    virtual void Pad16();
    virtual bool Fn17();
};
// GLOBAL: 0x00b43d5c
extern cSimState_a9e5f4* gpB43d5c_a9e5f4;

// The terrain grid (global 0x00b43d78) hands out an object that rates a block of cells.
struct cCellRater_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual uint8_t Fn08(int32_t x, int32_t z, int32_t w, int32_t h);
};
struct cCellGrid_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual cCellRater_a9e5f4* Fn05();
};
// GLOBAL: 0x00b43d78
extern cCellGrid_a9e5f4* gpB43d78_a9e5f4;

// A rectangle of cells; the original's 0x0048ed90 clips one against another.
struct Rect_a9e5f4 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
    // STUB: 0x0048ed90
    void Clip(Rect_a9e5f4* out, const Rect_a9e5f4* bounds);
};

// STUB: 0x005fd390
void Fn005fd390(void* property, uint32_t id, bool* out);

// The sound/effect global at 0x00b43d60.
struct cPing_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Fn06(float x, float z, uint32_t arg);
};
// GLOBAL: 0x00b43d60
extern cPing_a9e5f4* gpB43d60_a9e5f4;

// The fire the class creates for an occupant (0x6c bytes; its constructor is out of line).
struct cFireView_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Fn03();
};
struct cNewFire_a9e5f4 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Fn04(void* occupant);
    virtual void Pad05();
    virtual void Pad06();
    virtual uint32_t Fn07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Fn10(uint32_t size);
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Fn14(uint32_t seed);
    cFireView_a9e5f4 mView;
    uint8_t mData[0x64];
    // STUB: 0x004711c0
    cNewFire_a9e5f4();
};

// A fire that already burns on an occupant: slots 9 and 10 read and set its intensity.
struct cBurning_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual uint32_t Fn09();
    virtual void Fn10(uint32_t level);
};
struct Iter_a9e5f4 {
    TreeNode_a9e5f4* mpNode;
};
union FloatBits_a9e5f4 {
    float f;
    int32_t i;
};

// An occupant as the ignition code sees it: slot 6 hands out its property set, 7 its type, 8 its position, 11 its cell bounds.
struct cOccProp_a9e5f4 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void* Fn06();
    virtual uint32_t Fn07();
    virtual void Fn08(float* position);
    virtual void Pad09();
    virtual void Pad10();
    virtual void Fn11(Rect_a9e5f4* out);
};

// STUB: 0x005fd480
void Fn005fd480(void* property, uint32_t id, uint32_t* out);

// STUB: 0x005d76a0
float Fn005d76a0(const float* a, const float* b);


// What an occupant answers for the burning interface (iid 0x69d25c60): slot 9 reads the level, slot 10 sets it.
struct cOccQuery_a9e5f4 {
    virtual bool QueryInterface(uint32_t iid, void** out);
    virtual void AddRef();
    virtual void Release();
};
// FUNCTION: 0x00579190
unsigned int cUnk00a9e5f4::Release()
{
    if (refCount == 1) {
        Slot05_a9e460();
    }
    return cUnk0090da1e::Release();
}

// FUNCTION: 0x005791b0
bool cUnk00a9e5f4::QueryInterface(unsigned int iid, void** ppv)
{
    switch (iid) {
    case 0x49b43f58:
        *ppv = static_cast<cUnk00a9e460*>(this);
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<cUnk00aaaa9c*>(this);
        AddRef();
        return true;
    case 0x22223ba4:
        *ppv = static_cast<cUnk00a9e0e4*>(this);
        AddRef();
        return true;
    }
    return cUnk0090da1e::QueryInterface(iid, ppv);
}

// FUNCTION: 0x00579230
uint32_t cUnk00a9e5f4::Slot13_a9e460(uint32_t a)
{
    if (!mnFieldDC) {
        mnFieldDC = a;
    }
    return mnFieldDC;
}

// FUNCTION: 0x00579bd0
void cUnk00a9e5f4::Slot11_a9e460(void* a)
{
    Slot08_a9e5f4(Fn00579a20(a));
}

// FUNCTION: 0x00579bf0
void cUnk00a9e5f4::Slot12_a9e460(void* a)
{
    Slot09_a9e5f4(Fn00579a20(a));
}

// FUNCTION: 0x00579600
bool cUnk00a9e5f4::Slot03_aaaa9c(void* msg)
{
    switch (static_cast<cMessage_a9e5f4*>(msg)->GetType()) {
    case 0x66956813:
    case 0x86ad10ee:
        Slot04_a9e460();
        break;
    case 0x06cdb65b: {
        bool visible = gpB43dc4_a9e5f4->GetViewType() == 1;
        Node_a9e5f4* head = static_cast<Node_a9e5f4*>(mpFireList);
        Node_a9e5f4* n = head->mpNext;
        while (n != head) {
            Node_a9e5f4* cur = n;
            n = n->mpNext;
            cur->mpValue->SetVisible(visible);
        }
        break;
    }
    case 0xa6b79602: {
        Node_a9e5f4* head = static_cast<Node_a9e5f4*>(mpFireList);
        if (head->mpNext != head) {
            Node_a9e5f4* n = static_cast<Node_a9e5f4*>(mpFireList)->mpNext;
            Node_a9e5f4* last = static_cast<Node_a9e5f4*>(mpFireList);
            while (n != last) {
                Node_a9e5f4* cur = n;
                n = n->mpNext;
                cur->mpValue->ViewUpdate();
            }
        }
        break;
    }
    }
    return true;
}

// FUNCTION: 0x00579a60
uint32_t cUnk00a9e5f4::Slot15_a9e460(void* a)
{
    const int32_t* q = static_cast<const int32_t*>(a);
    uint32_t count = 0;
    Node_a9e5f4* head = static_cast<Node_a9e5f4*>(mpFireList);
    if (head->mpNext == head) {
        return 0;
    }
    Node_a9e5f4* n = static_cast<Node_a9e5f4*>(mpFireList)->mpNext;
    Node_a9e5f4* end = static_cast<Node_a9e5f4*>(mpFireList);
    while (n != end) {
        Node_a9e5f4* cur = n;
        n = n->mpNext;
        int32_t r[4];
        cur->mpValue->mView.GetBounds(r);
        if (q[2] >= r[0] && q[0] <= r[2] && q[3] >= r[1] && q[1] <= r[3]) {
            count++;
        }
    }
    return count;
}
// FUNCTION: 0x005793e0
void* cUnk00a9e5f4::Slot04_a9e0e4()
{
    return reinterpret_cast<cLayerU_a9e5f4*>(gpB43cec_a9e5f4->Fn72())->Fn07(0x621cda33);
}

// FUNCTION: 0x00579250
bool cUnk00a9e5f4::Slot08_a9e5f4(void* p)
{
    cFire_a9e5f4* fire = static_cast<cFire_a9e5f4*>(p);
    if (fire) {
        if (fire->mnLife <= 0) {
            fire->Fn0046fe00(reinterpret_cast<cRandom_a9e5f4*>(mRandom)->RandomUint32UniformN(4000) +
                             reinterpret_cast<cTimer_a9e5f4*>(mTimer)->GetElapsedTime());
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x0057b7b0
bool cUnk00a9e5f4::Slot09_a9e5f4(void* p)
{
    if (!p) {
        return false;
    }
    cOccIface_a9e5f4* occ = static_cast<cOccIface_a9e5f4*>(p);
    cRef_a9e5f4* ref = occ->Fn05();
    if (ref) {
        ref->AddRef();
    }
    Fn0057b640(p);
    ToastOccupant(ref);
    if (ref) {
        ref->Release();
    }
    return true;
}

// FUNCTION: 0x0057bf10
void cUnk00a9e5f4::Slot04_a9e460()
{
    ProcessToastList();
    UpdatePhase();
    Node_a9e5f4* head = static_cast<Node_a9e5f4*>(mpFireList);
    if (head->mpNext != head) {
        uint32_t now = reinterpret_cast<cTimer_a9e5f4*>(mTimer)->GetElapsedTime();
        if (!mnNextUpdate) {
            mnNextUpdate = now;
        }
        if (now >= mnNextUpdate) {
            UpdateAllFires();
            mnNextUpdate += mnUpdateInterval;
        }
    }
    if (mnCountD4 || mnCountD0) {
        cMade_a9e5f4* m = new cMade_a9e5f4;
        m->AddRef();
        m->Fn05(0x49d15b73);
        m->Fn33(this);
        m->Fn11(mnCountD0);
        m->Fn16(mnCountD4);
        gpB43ccc->MessagePost(m, false);
        m->Release();
        mnCountD4 = 0;
        mnCountD0 = 0;
    }
}

// FUNCTION: 0x0057b500
bool cUnk00a9e5f4::Slot09_a9e460(uint32_t a, uint32_t b)
{
    List_a9e5f4 list;
    list.mpHead = 0;
    bool hit = false;
    Node_a9e5f4* head = GetPool_a9e5f4()->Alloc(0xc);
    head->mpNext = head;
    head->mpPrev = head;
    Cell_a9e5f4 from;
    Cell_a9e5f4 to;
    list.mpHead = head;
    from.mnX = a;
    from.mnY = b;
    to.mnX = a;
    to.mnY = b;
    gpB43d0c_a9e5f4->Fn40(&list, &from, &to, mpFilter, -1);
    Node_a9e5f4* n = list.mpHead->mpNext;
    if (n != list.mpHead) {
        do {
            cOccupant_a9e5f4* o = n->mpValue;
            Fn0057ab20(o);
            hit = true;
            o->Release();
            n = n->mpNext;
        } while (n != list.mpHead);
    }
    list.Clear();
    Node_a9e5f4* freed = list.mpHead;
    GetPool_a9e5f4()->Free(freed);
    return hit;
}

// FUNCTION: 0x0057a540
bool cUnk00a9e5f4::Slot05_a9e460()
{
    if (mbInitialized) {
        gpB43cec_a9e5f4->Fn72()->Fn14(static_cast<cUnk00a9e0e4*>(this));
        cIGZMessageServer2* ms = gpB43ccc;
        if (ms) {
            ms->RemoveNotification(static_cast<cUnk00aaaa9c*>(this), 0xa6b79602);
            ms->RemoveNotification(static_cast<cUnk00aaaa9c*>(this), 0x06cdb65b);
        }
        cSim_a9e5f4* sim = gpB43cec_a9e5f4->Fn50();
        sim->Fn20(static_cast<cUnk00aaaa9c*>(this));
        if (mpFilter) {
            cRef_a9e5f4* f = static_cast<cRef_a9e5f4*>(mpFilter);
            mpFilter = 0;
            f->Release();
        }
        Fn0057a200();
        reinterpret_cast<FireList_a9e5f4*>(&mpFireList)->Clear();
        Tree_a9e5f4* tree = reinterpret_cast<Tree_a9e5f4*>(&mpToastTree);
        if (tree->mnSize != 0) {
            tree->Erase(tree->mpHeader->mpRoot);
            tree->mpHeader->mpLeft = tree->mpHeader;
            tree->mpHeader->mpRoot = 0;
            tree->mpHeader->mpRight = tree->mpHeader;
            tree->mnSize = 0;
        }
        while (static_cast<Node_a9e5f4*>(mpToastList)->mpNext != static_cast<Node_a9e5f4*>(mpToastList)) {
            Node_a9e5f4* node = static_cast<Node_a9e5f4*>(mpToastList)->mpNext;
            node->mpValue->Release();
            Node_a9e5f4* next = node->mpNext;
            Node_a9e5f4* prev = node->mpPrev;
            prev->mpNext = next;
            next->mpPrev = prev;
            GetPool_a9e5f4()->Free(node);
        }
        gpB21638 = 0;
        gpB2163c = 0;
        mbInitialized = false;
        if (mpDemolition) {
            static_cast<cRef_a9e5f4*>(mpDemolition)->Release();
            mpDemolition = 0;
        }
        cLayer_a9e5f4* layer = gpB43cec_a9e5f4->Fn72();
        if (layer) {
            cLayerItem_a9e5f4* item = layer->Fn07(0x621cda33);
            if (item) {
                item->Fn09(static_cast<cUnk00a9e0e4*>(this));
            }
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0057a310 score 84
bool cUnk00a9e5f4::Slot03_a9e460()
{
    if (!mbInitialized) {
        ReadTunableValues();
        mbInitialized = true;
        cLayer_a9e5f4* layer = gpB43cec_a9e5f4->Fn72();
        if (layer) {
            cLayerItem_a9e5f4* item = layer->Fn07(0x621cda33);
            if (item) {
                item->Fn08(static_cast<cUnk00a9e0e4*>(this));
            }
        }
        gpB21638 = mTopFireCurve;
        gpB2163c = mSideFireCurve;
        mnCellsX = gpB43cec_a9e5f4->Fn93();
        mnCellsZ = gpB43cec_a9e5f4->Fn94();
        if (!mpDemolition) {
            cRef_a9e5f4* demolition = gpB43d00_a9e5f4;
            mpDemolition = demolition;
            demolition->AddRef();
        }
        reinterpret_cast<cTimer_a9e5f4*>(mTimer)->SetUnits(4);
        reinterpret_cast<cTimer_a9e5f4*>(mTimer)->Restart();
        cUnk00a8edbc* filter = new cUnk00a8edbc;
        cUnk00a8edbc* old = static_cast<cUnk00a8edbc*>(mpFilter);
        if (filter != old) {
            if (filter) {
                filter->AddRef();
            }
            mpFilter = filter;
            if (old) {
                old->Release();
            }
        }
        reinterpret_cast<std::vector<uint32_t>*>(static_cast<uint8_t*>(mpFilter) + 0xc)->push_back(0x74758926);
        reinterpret_cast<std::vector<uint32_t>*>(static_cast<uint8_t*>(mpFilter) + 0xc)->push_back(0x278128a0);
        reinterpret_cast<std::vector<uint32_t>*>(static_cast<uint8_t*>(mpFilter) + 0xc)->push_back(0xa823821e);
        cIGZMessageServer2* ms = gpB43ccc;
        if (ms) {
            ms->AddNotification(static_cast<cUnk00aaaa9c*>(this), 0x06cdb65b);
            ms->AddNotification(static_cast<cUnk00aaaa9c*>(this), 0xa6b79602);
        }
        Slot04_a9e460();
    }
    return true;
}
#endif
#ifdef OB_DRAFTS
// CLOSE: 0x0057a7d0 score 145
bool cUnk00a9e5f4::Slot06_a9e460(void* a, bool b, uint32_t c, bool d)
{
    cOccProp_a9e5f4* occ = static_cast<cOccProp_a9e5f4*>(a);
    uint32_t type = occ->Fn07();
    if (!b && !gpB43d5c_a9e5f4->Fn17() && gpB43d5c_a9e5f4->Fn15()) {
        return false;
    }
    if (type == 0x74758926 || type == 0xa823821e || type == 0x278128a0) {
        uint32_t value = 0;
        Fn005fd480(occ->Fn06(), 0x29244db5, &value);
        if (value == 0) {
            return false;
        }
        if (!b) {
            Rect_a9e5f4 city;
            city.mnLeft = 0;
            city.mnRight = mnCellsX - 1;
            city.mnTop = 0;
            city.mnBottom = mnCellsZ - 1;
            Rect_a9e5f4 box;
            occ->Fn11(&box);
            box.Clip(&box, &city);
            int32_t w;
            w = box.mnRight - box.mnLeft + 1;
            int32_t h = box.mnBottom - box.mnTop + 1;
            int32_t rating;
            rating = gpB43d78_a9e5f4->Fn05()->Fn08(box.mnLeft, box.mnTop, w, h);
            FloatBits_a9e5f4 u;
            u.f = reinterpret_cast<Curve_a9e5f4*>(mFlammCurve)->Eval(static_cast<float>(rating)) + 12582912.0f;
            if (u.i - 0x4b400000 <= 0) {
                return false;
            }
        }
        bool burning = false;
        Fn005fd390(occ->Fn06(), 0x69dbebe1, &burning);
        if (burning) {
            if (!b) {
                return false;
            }
            cBurning_a9e5f4* old;
            old = static_cast<cBurning_a9e5f4*>(Fn00579a20(occ));
            if (old) {
                old->Fn10(old->Fn09() + 1);
            }
            return true;
        }
        if (c == 0) {
            c = reinterpret_cast<cRandom_a9e5f4*>(mRandom)->RandomUint32Uniform();
        }
        cNewFire_a9e5f4* fire = new cNewFire_a9e5f4;
        Iter_a9e5f4 it;
        Tree_a9e5f4* tree = reinterpret_cast<Tree_a9e5f4*>(&mpToastTree);
        tree->Find(&it, &c);
        if (it.mpNode == tree->mpHeader) {
            bool flag = d && tree->mnSize != 0;
            gpB43cec_a9e5f4->Fn72()->Fn13(static_cast<cUnk00a9e0e4*>(this), 0, 0, occ, mbFlagC4, flag);
            tree->Insert(&it, &c);
        }
        cNewFire_a9e5f4* held = fire;
        if (held != 0) {
            held->AddRef();
        }
        reinterpret_cast<FireList_a9e5f4*>(&mpFireList)->PushBack(&held);
        if (fire) {
            fire->Release();
        }
        fire->mView.Fn03();
        fire->Fn04(occ);
        fire->Fn14(c);
        gpB43d0c_a9e5f4->Fn20(&fire->mView, 0);
        if (b) {
            uint32_t flames = *static_cast<uint32_t*>(mpFlameCount);
            uint32_t level = fire->Fn07();
            if (level <= 1) {
                flames >>= 1;
            }
            fire->Fn10(flames);
        }
        float pos[3];
        occ->Fn08(pos);
        gpB43d60_a9e5f4->Fn06(pos[0], pos[2], 0);
        SendIgnitionMessage(&fire->mView, true);
        if (occ->Fn07() == 0x74758926) {
            mnCountD4++;
            UpdatePhase();
            return true;
        }
        if (occ->Fn07() != 0xa823821e) {
            mnCountD0 += 1;
        }
        UpdatePhase();
        return true;
    } else {
        return false;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0057b170 score 22
bool cUnk00a9e5f4::Slot07_a9e460(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    bool result = false;
    int32_t key = gpB43d7c_a9e5f4->Fn05()->Fn07(a, b);
    float chance = reinterpret_cast<Curve_a9e5f4*>(mIgniteCurve)->Eval(static_cast<float>(key));
    if (c & 0xff) {
        if (reinterpret_cast<cRandom_a9e5f4*>(mRandom)->RandomFloatRange(0.0, 100.0) > chance) {
            return false;
        }
    }
    if (e == 0) {
        e = reinterpret_cast<cRandom_a9e5f4*>(mRandom)->RandomUint32Uniform();
    }
    List_a9e5f4 list;
    list.mpHead = 0;
    Node_a9e5f4* head = GetPool_a9e5f4()->Alloc(0xc);
    head->mpNext = head;
    head->mpPrev = head;
    list.mpHead = head;
    Cell_a9e5f4 from;
    Cell_a9e5f4 to;
    from.mnX = a;
    from.mnY = b;
    to.mnX = a;
    to.mnY = b;
    gpB43d0c_a9e5f4->Fn40(&list, &from, &to, mpFilter, -1);
    Node_a9e5f4* n = list.mpHead->mpNext;
    if (n != list.mpHead) {
        do {
            cOccupant_a9e5f4* o = n->mpValue;
            if (reinterpret_cast<cFireIface_a9e5f4*>(reinterpret_cast<uint8_t*>(this) + 8)->Fn06(o, d, e, !static_cast<uint8_t>(d))) {
                result = true;
            }
            o->Release();
            n = n->mpNext;
        } while (n != list.mpHead);
    }
    list.Clear();
    Node_a9e5f4* freed = list.mpHead;
    GetPool_a9e5f4()->Free(freed);
    return result;
}
#endif

// FUNCTION: 0x0057af10
bool cUnk00a9e5f4::Slot10_a9e460(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    bool result = false;
    uint32_t seed = reinterpret_cast<cRandom_a9e5f4*>(mRandom)->RandomUint32Uniform();
    float cellWidth = gpB43cec_a9e5f4->Fn91();
    float outer = static_cast<float>(d) * cellWidth;
    float inner = static_cast<float>(c) * cellWidth;
    float centre[2];
    gpB43cec_a9e5f4->Fn97(a, b, &centre[0], &centre[1]);
    List_a9e5f4 list;
    list.mpHead = 0;
    Node_a9e5f4* head = GetPool_a9e5f4()->Alloc(0xc);
    head->mpNext = head;
    head->mpPrev = head;
    list.mpHead = head;
    Cell_a9e5f4 max;
    Cell_a9e5f4 min;
    min.mnX = a - d;
    min.mnY = b - d;
    max.mnX = a + d;
    max.mnY = b + d;
    if (min.mnX < 0) {
        min.mnX = 0;
    }
    if (min.mnY < 0) {
        min.mnY = 0;
    }
    if (static_cast<uint32_t>(max.mnX) >= mnCellsX) {
        max.mnX = mnCellsX - 1;
    }
    if (static_cast<uint32_t>(max.mnY) >= mnCellsZ) {
        max.mnY = mnCellsZ - 1;
    }
    gpB43d0c_a9e5f4->Fn40(&list, &min, &max, mpFilter, -1);
    Node_a9e5f4* n = list.mpHead->mpNext;
    while (n != list.mpHead) {
        cOccProp_a9e5f4* occ = reinterpret_cast<cOccProp_a9e5f4*>(n->mpValue);
        float pos[3];
        occ->Fn08(pos);
        pos[1] = pos[2];
        float dist = Fn005d76a0(pos, centre);
        if (dist < inner) {
            uint32_t value = 0;
            Fn005fd480(occ->Fn06(), 0x29244db5, &value);
            if (value > 0) {
                Fn0057ab20(occ);
            }
            result = true;
        } else if (dist < outer) {
            if (reinterpret_cast<cFireIface_a9e5f4*>(reinterpret_cast<uint8_t*>(this) + 8)->Fn06(occ, 0, seed, false)) {
                result = true;
            }
        }
        occ->Release();
        n = n->mpNext;
    }
    list.Clear();
    Node_a9e5f4* freed = list.mpHead;
    GetPool_a9e5f4()->Free(freed);
    return result;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0057b350 score 152
bool cUnk00a9e5f4::Slot08_a9e460(uint32_t a, uint32_t b, uint32_t c)
{
    List_a9e5f4 list;
    list.mpHead = 0;
    Node_a9e5f4* head = GetPool_a9e5f4()->Alloc(0xc);
    head->mpNext = head;
    head->mpPrev = head;
    list.mpHead = head;
    {
    cUnk00a949b8 filter;
    filter.AddRef();
    Cell_a9e5f4 from;
    Cell_a9e5f4 to;
    from.mnX = a;
    to.mnX = a;
    from.mnY = b;
    to.mnY = b;
    gpB43d0c_a9e5f4->Fn40(&list, &from, &to, &filter, -1);
    Node_a9e5f4* n = list.mpHead->mpNext;
    while (n != list.mpHead) {
        cOccupant_a9e5f4* o = n->mpValue;
        cBurning_a9e5f4* burn = 0;
        reinterpret_cast<cOccQuery_a9e5f4*>(o)->QueryInterface(0x69d25c60, reinterpret_cast<void**>(&burn));
        if (burn) {
            uint32_t level = burn->Fn09();
            if (level > c) {
                burn->Fn10(level - c);
            } else {
                burn->Fn10(0);
                Slot08_a9e5f4(burn);
            }
        }
        o->Release();
        if (burn) {
            reinterpret_cast<cOccQuery_a9e5f4*>(burn)->Release();
        }
        n = n->mpNext;
    }
    }
    list.Clear();
    Node_a9e5f4* freed = list.mpHead;
    GetPool_a9e5f4()->Free(freed);
    return true;
}
#endif

// FUNCTION: 0x0057a2f0
uint32_t cUnk00a9e5f4::Slot16_a9e460()
{
    uint32_t count = 0;
    void** head = static_cast<void**>(mpFireList);
    for (void** n = static_cast<void**>(*head); n != head; n = static_cast<void**>(*n)) {
        count++;
    }
    return count;
}
