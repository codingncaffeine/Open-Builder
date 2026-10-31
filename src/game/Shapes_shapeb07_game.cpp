// Shape families of packet shapeb07_game, written by scratch/s16/gen/shapeb07_game/gen.sh.
#include "common/types.h"
#include <new>

// STUB: 0x005e55e0
void* Fn005e55e0(uint32_t nBytes);

// STUB: 0x00544890
void* Fn00544890(uint32_t nBytes);

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t nBytes);

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

struct ListNode_shapeb07_game {
    ListNode_shapeb07_game* mpNext;
};

struct View_0069e5d0_shapeb07_game {
    uint8_t pad[0x44];
    ListNode_shapeb07_game* mpList;
    uint32_t Fn0069e5d0();
};

// FUNCTION: 0x0069e5d0
uint32_t View_0069e5d0_shapeb07_game::Fn0069e5d0()
{
    ListNode_shapeb07_game* pHead = mpList;
    uint32_t n = 0;
    for (ListNode_shapeb07_game* p = pHead->mpNext; p != pHead; p = p->mpNext) {
        n++;
    }
    return n;
}

struct View_006e50d0_shapeb07_game {
    uint8_t pad[0x6c];
    ListNode_shapeb07_game* mpList;
    uint32_t Fn006e50d0();
};

// FUNCTION: 0x006e50d0
uint32_t View_006e50d0_shapeb07_game::Fn006e50d0()
{
    ListNode_shapeb07_game* pHead = mpList;
    uint32_t n = 0;
    for (ListNode_shapeb07_game* p = pHead->mpNext; p != pHead; p = p->mpNext) {
        n++;
    }
    return n;
}

struct View_006e50f0_shapeb07_game {
    uint8_t pad[0x70];
    ListNode_shapeb07_game* mpList;
    uint32_t Fn006e50f0();
};

// FUNCTION: 0x006e50f0
uint32_t View_006e50f0_shapeb07_game::Fn006e50f0()
{
    ListNode_shapeb07_game* pHead = mpList;
    uint32_t n = 0;
    for (ListNode_shapeb07_game* p = pHead->mpNext; p != pHead; p = p->mpNext) {
        n++;
    }
    return n;
}

struct View_006e5110_shapeb07_game {
    uint8_t pad[0x74];
    ListNode_shapeb07_game* mpList;
    uint32_t Fn006e5110();
};

// FUNCTION: 0x006e5110
uint32_t View_006e5110_shapeb07_game::Fn006e5110()
{
    ListNode_shapeb07_game* pHead = mpList;
    uint32_t n = 0;
    for (ListNode_shapeb07_game* p = pHead->mpNext; p != pHead; p = p->mpNext) {
        n++;
    }
    return n;
}

struct View_006e5130_shapeb07_game {
    uint8_t pad[0x68];
    ListNode_shapeb07_game* mpList;
    uint32_t Fn006e5130();
};

// FUNCTION: 0x006e5130
uint32_t View_006e5130_shapeb07_game::Fn006e5130()
{
    ListNode_shapeb07_game* pHead = mpList;
    uint32_t n = 0;
    for (ListNode_shapeb07_game* p = pHead->mpNext; p != pHead; p = p->mpNext) {
        n++;
    }
    return n;
}

// GLOBAL: 0x00b49b6c
extern float gfShapeb49b6c_shapeb07_game;

// FUNCTION: 0x006e3190
float Fn006e3190()
{
    return gfShapeb49b6c_shapeb07_game;
}

// GLOBAL: 0x00b0d588
extern float gfShapeb0d588_shapeb07_game;

// FUNCTION: 0x0074c660
float Fn0074c660()
{
    return gfShapeb0d588_shapeb07_game;
}

// GLOBAL: 0x00b0d5e0
extern float gfShapeb0d5e0_shapeb07_game;

// FUNCTION: 0x0074c690
float Fn0074c690()
{
    return gfShapeb0d5e0_shapeb07_game;
}

// GLOBAL: 0x00b0d5dc
extern float gfShapeb0d5dc_shapeb07_game;

// FUNCTION: 0x0074c6a0
float Fn0074c6a0()
{
    return gfShapeb0d5dc_shapeb07_game;
}

// GLOBAL: 0x00b54370
extern float gfShapeb54370_shapeb07_game;

// FUNCTION: 0x0088ff40
float Fn0088ff40()
{
    return gfShapeb54370_shapeb07_game;
}

struct View_00801700_shapeb07_game {
    uint32_t Fn00801700();
};

// FUNCTION: 0x00801700
uint32_t View_00801700_shapeb07_game::Fn00801700()
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) - 0x10);
}

struct View_00801850_shapeb07_game {
    uint32_t Fn00801850();
};

// FUNCTION: 0x00801850
uint32_t View_00801850_shapeb07_game::Fn00801850()
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) - 0x28);
}

struct View_00801890_shapeb07_game {
    uint32_t Fn00801890();
};

// FUNCTION: 0x00801890
uint32_t View_00801890_shapeb07_game::Fn00801890()
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) - 0x24);
}

struct View_008018e0_shapeb07_game {
    uint32_t Fn008018e0();
};

// FUNCTION: 0x008018e0
uint32_t View_008018e0_shapeb07_game::Fn008018e0()
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) - 0x1c);
}

struct View_00801b40_shapeb07_game {
    uint32_t Fn00801b40();
};

// FUNCTION: 0x00801b40
uint32_t View_00801b40_shapeb07_game::Fn00801b40()
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) - 0x7c);
}

struct View_00595d20_shapeb07_game {
    uint32_t mVtbl;
    View_00595d20_shapeb07_game* Fn00595d20();
};

// FUNCTION: 0x00595d20
View_00595d20_shapeb07_game* View_00595d20_shapeb07_game::Fn00595d20()
{
    mVtbl = 0xa9fb68;
    return this;
}

struct View_00595d30_shapeb07_game {
    uint32_t mVtbl;
    View_00595d30_shapeb07_game* Fn00595d30();
};

// FUNCTION: 0x00595d30
View_00595d30_shapeb07_game* View_00595d30_shapeb07_game::Fn00595d30()
{
    mVtbl = 0xa9fb58;
    return this;
}

struct View_005fb290_shapeb07_game {
    uint32_t mVtbl;
    View_005fb290_shapeb07_game* Fn005fb290();
};

// FUNCTION: 0x005fb290
View_005fb290_shapeb07_game* View_005fb290_shapeb07_game::Fn005fb290()
{
    mVtbl = 0x0;
    return this;
}

struct View_0080ae60_shapeb07_game {
    uint32_t mVtbl;
    View_0080ae60_shapeb07_game* Fn0080ae60();
};

// FUNCTION: 0x0080ae60
View_0080ae60_shapeb07_game* View_0080ae60_shapeb07_game::Fn0080ae60()
{
    mVtbl = 0xabd92c;
    return this;
}

struct View_009edf90_shapeb07_game {
    uint32_t mVtbl;
    View_009edf90_shapeb07_game* Fn009edf90();
};

// FUNCTION: 0x009edf90
View_009edf90_shapeb07_game* View_009edf90_shapeb07_game::Fn009edf90()
{
    mVtbl = 0xae5cbc;
    return this;
}

struct View_004e4a70_shapeb07_game {
    virtual void Pad00_004e4a70() = 0;
    virtual void AddRef_004e4a70() = 0;
    bool Fn004e4a70(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004e4a70 score 8
bool View_004e4a70_shapeb07_game::Fn004e4a70(uint32_t iid, void** ppv)
{
    if (iid == 1) {
    } else if (iid != 0x4e4a80) {
        return false;
    }
    *ppv = this;
    AddRef_004e4a70();
    return true;
}
#endif

struct View_004f7b70_shapeb07_game {
    virtual void Pad00_004f7b70() = 0;
    virtual void AddRef_004f7b70() = 0;
    bool Fn004f7b70(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004f7b70 score 8
bool View_004f7b70_shapeb07_game::Fn004f7b70(uint32_t iid, void** ppv)
{
    if (iid == 1) {
    } else if (iid != 0x4f7b80) {
        return false;
    }
    *ppv = this;
    AddRef_004f7b70();
    return true;
}
#endif

struct View_0078c200_shapeb07_game {
    virtual void Pad00_0078c200() = 0;
    virtual void AddRef_0078c200() = 0;
    bool Fn0078c200(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0078c200 score 8
bool View_0078c200_shapeb07_game::Fn0078c200(uint32_t iid, void** ppv)
{
    if (iid == 0x22e85d8e) {
    } else if (iid != 1) {
        return false;
    }
    *ppv = this;
    AddRef_0078c200();
    return true;
}
#endif

struct View_0079a040_shapeb07_game {
    virtual void Pad00_0079a040() = 0;
    virtual void AddRef_0079a040() = 0;
    bool Fn0079a040(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0079a040 score 8
bool View_0079a040_shapeb07_game::Fn0079a040(uint32_t iid, void** ppv)
{
    if (iid == 0x49d98263) {
    } else if (iid != 1) {
        return false;
    }
    *ppv = this;
    AddRef_0079a040();
    return true;
}
#endif

struct View_00812080_shapeb07_game {
    virtual void Pad00_00812080() = 0;
    virtual void AddRef_00812080() = 0;
    bool Fn00812080(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00812080 score 8
bool View_00812080_shapeb07_game::Fn00812080(uint32_t iid, void** ppv)
{
    if (iid == 0x452294aa) {
    } else if (iid != 1) {
        return false;
    }
    *ppv = this;
    AddRef_00812080();
    return true;
}
#endif

struct View_00776bf0_shapeb07_game {
    virtual void Pad00_00776bf0() = 0;
    virtual void AddRef_00776bf0() = 0;
    bool Fn00776bf0(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00776bf0 score 14
bool View_00776bf0_shapeb07_game::Fn00776bf0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x776c13:
        *ppv = this;
        AddRef_00776bf0();
        return true;
    case 1:
        *ppv = this;
        AddRef_00776bf0();
        return true;
    }
    return false;
}
#endif

struct View_007a7930_shapeb07_game {
    virtual void Pad00_007a7930() = 0;
    virtual void AddRef_007a7930() = 0;
    bool Fn007a7930(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007a7930 score 14
bool View_007a7930_shapeb07_game::Fn007a7930(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x7a7953:
        *ppv = this;
        AddRef_007a7930();
        return true;
    case 1:
        *ppv = this;
        AddRef_007a7930();
        return true;
    }
    return false;
}
#endif

struct View_007b23a0_shapeb07_game {
    virtual void Pad00_007b23a0() = 0;
    virtual void AddRef_007b23a0() = 0;
    bool Fn007b23a0(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007b23a0 score 14
bool View_007b23a0_shapeb07_game::Fn007b23a0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x7b23c3:
        *ppv = this;
        AddRef_007b23a0();
        return true;
    case 1:
        *ppv = this;
        AddRef_007b23a0();
        return true;
    }
    return false;
}
#endif

struct View_0082b850_shapeb07_game {
    virtual void Pad00_0082b850() = 0;
    virtual void AddRef_0082b850() = 0;
    bool Fn0082b850(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0082b850 score 14
bool View_0082b850_shapeb07_game::Fn0082b850(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x82b873:
        *ppv = this;
        AddRef_0082b850();
        return true;
    case 1:
        *ppv = this;
        AddRef_0082b850();
        return true;
    }
    return false;
}
#endif

struct View_0088bd70_shapeb07_game {
    virtual void Pad00_0088bd70() = 0;
    virtual void AddRef_0088bd70() = 0;
    bool Fn0088bd70(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0088bd70 score 14
bool View_0088bd70_shapeb07_game::Fn0088bd70(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x88bd93:
        *ppv = this;
        AddRef_0088bd70();
        return true;
    case 1:
        *ppv = this;
        AddRef_0088bd70();
        return true;
    }
    return false;
}
#endif

struct Arg_004fb060_shapeb07_game {
    virtual void Pad0_004fb060() = 0;
    virtual void Pad1_004fb060() = 0;
    virtual void Pad2_004fb060() = 0;
    virtual void Pad3_004fb060() = 0;
    virtual void Pad4_004fb060() = 0;
    virtual void Pad5_004fb060() = 0;
    virtual void Pad6_004fb060() = 0;
    virtual void Notify_004fb060(uint32_t n) = 0;
};

struct View_004fb060_shapeb07_game {
    // STUB: 0x0050ac00
    bool Base_004fb060(Arg_004fb060_shapeb07_game* p);
    bool Fn004fb060(Arg_004fb060_shapeb07_game* p);
};

// FUNCTION: 0x004fb060
bool View_004fb060_shapeb07_game::Fn004fb060(Arg_004fb060_shapeb07_game* p)
{
    p->Notify_004fb060(1);
    return Base_004fb060(p);
}

struct Arg_00504bf0_shapeb07_game {
    virtual void Pad0_00504bf0() = 0;
    virtual void Pad1_00504bf0() = 0;
    virtual void Pad2_00504bf0() = 0;
    virtual void Pad3_00504bf0() = 0;
    virtual void Pad4_00504bf0() = 0;
    virtual void Pad5_00504bf0() = 0;
    virtual void Pad6_00504bf0() = 0;
    virtual void Notify_00504bf0(uint32_t n) = 0;
};

struct View_00504bf0_shapeb07_game {
    // STUB: 0x0052fa60
    bool Base_00504bf0(Arg_00504bf0_shapeb07_game* p);
    bool Fn00504bf0(Arg_00504bf0_shapeb07_game* p);
};

// FUNCTION: 0x00504bf0
bool View_00504bf0_shapeb07_game::Fn00504bf0(Arg_00504bf0_shapeb07_game* p)
{
    p->Notify_00504bf0(1);
    return Base_00504bf0(p);
}

struct Arg_00524160_shapeb07_game {
    virtual void Pad0_00524160() = 0;
    virtual void Pad1_00524160() = 0;
    virtual void Pad2_00524160() = 0;
    virtual void Pad3_00524160() = 0;
    virtual void Pad4_00524160() = 0;
    virtual void Pad5_00524160() = 0;
    virtual void Pad6_00524160() = 0;
    virtual void Notify_00524160(uint32_t n) = 0;
};

struct View_00524160_shapeb07_game {
    // STUB: 0x0055f640
    bool Base_00524160(Arg_00524160_shapeb07_game* p);
    bool Fn00524160(Arg_00524160_shapeb07_game* p);
};

// FUNCTION: 0x00524160
bool View_00524160_shapeb07_game::Fn00524160(Arg_00524160_shapeb07_game* p)
{
    p->Notify_00524160(2);
    return Base_00524160(p);
}

struct Arg_0053cb30_shapeb07_game {
    virtual void Pad0_0053cb30() = 0;
    virtual void Pad1_0053cb30() = 0;
    virtual void Pad2_0053cb30() = 0;
    virtual void Pad3_0053cb30() = 0;
    virtual void Pad4_0053cb30() = 0;
    virtual void Pad5_0053cb30() = 0;
    virtual void Pad6_0053cb30() = 0;
    virtual void Notify_0053cb30(uint32_t n) = 0;
};

struct View_0053cb30_shapeb07_game {
    // STUB: 0x00557930
    bool Base_0053cb30(Arg_0053cb30_shapeb07_game* p);
    bool Fn0053cb30(Arg_0053cb30_shapeb07_game* p);
};

// FUNCTION: 0x0053cb30
bool View_0053cb30_shapeb07_game::Fn0053cb30(Arg_0053cb30_shapeb07_game* p)
{
    p->Notify_0053cb30(1);
    return Base_0053cb30(p);
}

struct Arg_0068b3e0_shapeb07_game {
    virtual void Pad0_0068b3e0() = 0;
    virtual void Pad1_0068b3e0() = 0;
    virtual void Pad2_0068b3e0() = 0;
    virtual void Pad3_0068b3e0() = 0;
    virtual void Pad4_0068b3e0() = 0;
    virtual void Pad5_0068b3e0() = 0;
    virtual void Pad6_0068b3e0() = 0;
    virtual void Notify_0068b3e0(uint32_t n) = 0;
};

struct View_0068b3e0_shapeb07_game {
    // STUB: 0x006e9850
    bool Base_0068b3e0(Arg_0068b3e0_shapeb07_game* p);
    bool Fn0068b3e0(Arg_0068b3e0_shapeb07_game* p);
};

// FUNCTION: 0x0068b3e0
bool View_0068b3e0_shapeb07_game::Fn0068b3e0(Arg_0068b3e0_shapeb07_game* p)
{
    p->Notify_0068b3e0(2);
    return Base_0068b3e0(p);
}

struct Obj_00580e90_shapeb07_game {
    // STUB: 0x00580ba0
    Obj_00580e90_shapeb07_game* Init(void* pOwner);
};

struct View_00580e90_shapeb07_game {
    Obj_00580e90_shapeb07_game* Fn00580e90();
};

// FUNCTION: 0x00580e90
Obj_00580e90_shapeb07_game* View_00580e90_shapeb07_game::Fn00580e90()
{
    Obj_00580e90_shapeb07_game* p = static_cast<Obj_00580e90_shapeb07_game*>(Fn005e55e0(0x2c));
    if (p) {
        return p->Init(this);
    }
    return 0;
}

struct Obj_00581d60_shapeb07_game {
    // STUB: 0x00581ca0
    Obj_00581d60_shapeb07_game* Init(void* pOwner);
};

struct View_00581d60_shapeb07_game {
    Obj_00581d60_shapeb07_game* Fn00581d60();
};

// FUNCTION: 0x00581d60
Obj_00581d60_shapeb07_game* View_00581d60_shapeb07_game::Fn00581d60()
{
    Obj_00581d60_shapeb07_game* p = static_cast<Obj_00581d60_shapeb07_game*>(Fn005e55e0(0x24));
    if (p) {
        return p->Init(this);
    }
    return 0;
}

struct Obj_005bda60_shapeb07_game {
    // STUB: 0x005bd710
    Obj_005bda60_shapeb07_game* Init(void* pOwner);
};

struct View_005bda60_shapeb07_game {
    Obj_005bda60_shapeb07_game* Fn005bda60();
};

// FUNCTION: 0x005bda60
Obj_005bda60_shapeb07_game* View_005bda60_shapeb07_game::Fn005bda60()
{
    Obj_005bda60_shapeb07_game* p = static_cast<Obj_005bda60_shapeb07_game*>(Fn005e55e0(0xa8));
    if (p) {
        return p->Init(this);
    }
    return 0;
}

struct Obj_005be6d0_shapeb07_game {
    // STUB: 0x005be370
    Obj_005be6d0_shapeb07_game* Init(void* pOwner);
};

struct View_005be6d0_shapeb07_game {
    Obj_005be6d0_shapeb07_game* Fn005be6d0();
};

// FUNCTION: 0x005be6d0
Obj_005be6d0_shapeb07_game* View_005be6d0_shapeb07_game::Fn005be6d0()
{
    Obj_005be6d0_shapeb07_game* p = static_cast<Obj_005be6d0_shapeb07_game*>(Fn005e55e0(0x30));
    if (p) {
        return p->Init(this);
    }
    return 0;
}

struct Obj_005bca40_shapeb07_game {
    // STUB: 0x005bc310
    Obj_005bca40_shapeb07_game* Init(void* pOwner);
};

struct View_005bca40_shapeb07_game {
    Obj_005bca40_shapeb07_game* Fn005bca40();
};

// FUNCTION: 0x005bca40
Obj_005bca40_shapeb07_game* View_005bca40_shapeb07_game::Fn005bca40()
{
    Obj_005bca40_shapeb07_game* p = static_cast<Obj_005bca40_shapeb07_game*>(Fn005e55e0(0x5c));
    if (p) {
        return p->Init(this);
    }
    return 0;
}

struct Obj_005f2060_shapeb07_game {
    // STUB: 0x005f1730
    Obj_005f2060_shapeb07_game* Init(uint32_t n);
};

// FUNCTION: 0x005f2060
Obj_005f2060_shapeb07_game* Fn005f2060()
{
    Obj_005f2060_shapeb07_game* p = static_cast<Obj_005f2060_shapeb07_game*>(Fn005e55e0(0x1cc));
    if (p) {
        return p->Init(0x1);
    }
    return 0;
}

struct Obj_00648440_shapeb07_game {
    // STUB: 0x006483c0
    Obj_00648440_shapeb07_game* Init(uint32_t n);
};

// FUNCTION: 0x00648440
Obj_00648440_shapeb07_game* Fn00648440()
{
    Obj_00648440_shapeb07_game* p = static_cast<Obj_00648440_shapeb07_game*>(Fn005e55e0(0x250));
    if (p) {
        return p->Init(0x1);
    }
    return 0;
}

struct Obj_00652cb0_shapeb07_game {
    // STUB: 0x00652c30
    Obj_00652cb0_shapeb07_game* Init(uint32_t n);
};

// FUNCTION: 0x00652cb0
Obj_00652cb0_shapeb07_game* Fn00652cb0()
{
    Obj_00652cb0_shapeb07_game* p = static_cast<Obj_00652cb0_shapeb07_game*>(Fn005e55e0(0x250));
    if (p) {
        return p->Init(0x1);
    }
    return 0;
}

struct Obj_00514780_shapeb07_game {
    // STUB: 0x0054a2a0
    Obj_00514780_shapeb07_game* Init(uint32_t n);
};

// FUNCTION: 0x00514780
Obj_00514780_shapeb07_game* Fn00514780()
{
    Obj_00514780_shapeb07_game* p = static_cast<Obj_00514780_shapeb07_game*>(Fn00544890(0x2c4));
    if (p) {
        return p->Init(0x0);
    }
    return 0;
}

struct Obj_005147a0_shapeb07_game {
    // STUB: 0x00547800
    Obj_005147a0_shapeb07_game* Init(uint32_t n);
};

// FUNCTION: 0x005147a0
Obj_005147a0_shapeb07_game* Fn005147a0()
{
    Obj_005147a0_shapeb07_game* p = static_cast<Obj_005147a0_shapeb07_game*>(Fn00544890(0x27c));
    if (p) {
        return p->Init(0x0);
    }
    return 0;
}

struct Obj_00605450_shapeb07_game {
    // STUB: 0x00605160
    Obj_00605450_shapeb07_game* Init(uint32_t n);
};

struct Node_00605450_shapeb07_game {
    Node_00605450_shapeb07_game* mpNext;
};

struct PoolState_00605450_shapeb07_game {
    uint32_t pad0;
    uint32_t pad4;
    Node_00605450_shapeb07_game* mpFree;
    uint32_t mnCount;
};

struct PoolMgr_00605450_shapeb07_game {
    // STUB: 0x0090cf9a
    Node_00605450_shapeb07_game* Refill();
};

// GLOBAL: 0x00b0b2d0
extern PoolMgr_00605450_shapeb07_game gPoolMgr00b0b2d0_shapeb07_game;

// GLOBAL: 0x00b0b2d4
extern PoolState_00605450_shapeb07_game* gpPool00b0b2d4_shapeb07_game;

// FUNCTION: 0x00605450
void* Fn00605450()
{
    Node_00605450_shapeb07_game* pNode = gpPool00b0b2d4_shapeb07_game->mpFree;
    if (!pNode) {
        pNode = gPoolMgr00b0b2d0_shapeb07_game.Refill();
    }
    gpPool00b0b2d4_shapeb07_game->mpFree = pNode->mpNext;
    gpPool00b0b2d4_shapeb07_game->mnCount++;
    Obj_00605450_shapeb07_game* p = reinterpret_cast<Obj_00605450_shapeb07_game*>(pNode)->Init(1);
    if (p) {
        return reinterpret_cast<char*>(p) + 4;
    }
    return 0;
}

struct Obj_006489b0_shapeb07_game {
    // STUB: 0x006488f0
    Obj_006489b0_shapeb07_game* Init(uint32_t n);
};

struct Node_006489b0_shapeb07_game {
    Node_006489b0_shapeb07_game* mpNext;
};

struct PoolState_006489b0_shapeb07_game {
    uint32_t pad0;
    uint32_t pad4;
    Node_006489b0_shapeb07_game* mpFree;
    uint32_t mnCount;
};

struct PoolMgr_006489b0_shapeb07_game {
    // STUB: 0x0090cf9a
    Node_006489b0_shapeb07_game* Refill();
};

// GLOBAL: 0x00b0bec0
extern PoolMgr_006489b0_shapeb07_game gPoolMgr00b0bec0_shapeb07_game;

// GLOBAL: 0x00b0bec4
extern PoolState_006489b0_shapeb07_game* gpPool00b0bec4_shapeb07_game;

// FUNCTION: 0x006489b0
void* Fn006489b0()
{
    Node_006489b0_shapeb07_game* pNode = gpPool00b0bec4_shapeb07_game->mpFree;
    if (!pNode) {
        pNode = gPoolMgr00b0bec0_shapeb07_game.Refill();
    }
    gpPool00b0bec4_shapeb07_game->mpFree = pNode->mpNext;
    gpPool00b0bec4_shapeb07_game->mnCount++;
    Obj_006489b0_shapeb07_game* p = reinterpret_cast<Obj_006489b0_shapeb07_game*>(pNode)->Init(1);
    if (p) {
        return reinterpret_cast<char*>(p) + 4;
    }
    return 0;
}

struct Obj_00653560_shapeb07_game {
    // STUB: 0x006530b0
    Obj_00653560_shapeb07_game* Init(uint32_t n);
};

struct Node_00653560_shapeb07_game {
    Node_00653560_shapeb07_game* mpNext;
};

struct PoolState_00653560_shapeb07_game {
    uint32_t pad0;
    uint32_t pad4;
    Node_00653560_shapeb07_game* mpFree;
    uint32_t mnCount;
};

struct PoolMgr_00653560_shapeb07_game {
    // STUB: 0x0090cf9a
    Node_00653560_shapeb07_game* Refill();
};

// GLOBAL: 0x00b0cdb8
extern PoolMgr_00653560_shapeb07_game gPoolMgr00b0cdb8_shapeb07_game;

// GLOBAL: 0x00b0cdbc
extern PoolState_00653560_shapeb07_game* gpPool00b0cdbc_shapeb07_game;

// FUNCTION: 0x00653560
void* Fn00653560()
{
    Node_00653560_shapeb07_game* pNode = gpPool00b0cdbc_shapeb07_game->mpFree;
    if (!pNode) {
        pNode = gPoolMgr00b0cdb8_shapeb07_game.Refill();
    }
    gpPool00b0cdbc_shapeb07_game->mpFree = pNode->mpNext;
    gpPool00b0cdbc_shapeb07_game->mnCount++;
    Obj_00653560_shapeb07_game* p = reinterpret_cast<Obj_00653560_shapeb07_game*>(pNode)->Init(1);
    if (p) {
        return reinterpret_cast<char*>(p) + 4;
    }
    return 0;
}

struct Obj_0061e820_shapeb07_game {
    // STUB: 0x0061e1a0
    Obj_0061e820_shapeb07_game* Init(uint32_t n);
};

struct Node_0061e820_shapeb07_game {
    Node_0061e820_shapeb07_game* mpNext;
};

struct PoolState_0061e820_shapeb07_game {
    uint32_t pad0;
    uint32_t pad4;
    Node_0061e820_shapeb07_game* mpFree;
    uint32_t mnCount;
};

struct PoolMgr_0061e820_shapeb07_game {
    // STUB: 0x0090cf9a
    Node_0061e820_shapeb07_game* Refill();
};

// GLOBAL: 0x00b0b3a8
extern PoolMgr_0061e820_shapeb07_game gPoolMgr00b0b3a8_shapeb07_game;

// GLOBAL: 0x00b0b3ac
extern PoolState_0061e820_shapeb07_game* gpPool00b0b3ac_shapeb07_game;

// FUNCTION: 0x0061e820
void* Fn0061e820()
{
    Node_0061e820_shapeb07_game* pNode = gpPool00b0b3ac_shapeb07_game->mpFree;
    if (!pNode) {
        pNode = gPoolMgr00b0b3a8_shapeb07_game.Refill();
    }
    gpPool00b0b3ac_shapeb07_game->mpFree = pNode->mpNext;
    gpPool00b0b3ac_shapeb07_game->mnCount++;
    Obj_0061e820_shapeb07_game* p = reinterpret_cast<Obj_0061e820_shapeb07_game*>(pNode)->Init(1);
    if (p) {
        return reinterpret_cast<char*>(p) + 4;
    }
    return 0;
}

struct Obj_006477f0_shapeb07_game {
    // STUB: 0x006476f0
    Obj_006477f0_shapeb07_game* Init(uint32_t n);
};

struct Node_006477f0_shapeb07_game {
    Node_006477f0_shapeb07_game* mpNext;
};

struct PoolState_006477f0_shapeb07_game {
    uint32_t pad0;
    uint32_t pad4;
    Node_006477f0_shapeb07_game* mpFree;
    uint32_t mnCount;
};

struct PoolMgr_006477f0_shapeb07_game {
    // STUB: 0x0090cf9a
    Node_006477f0_shapeb07_game* Refill();
};

// GLOBAL: 0x00b0b570
extern PoolMgr_006477f0_shapeb07_game gPoolMgr00b0b570_shapeb07_game;

// GLOBAL: 0x00b0b574
extern PoolState_006477f0_shapeb07_game* gpPool00b0b574_shapeb07_game;

// FUNCTION: 0x006477f0
void* Fn006477f0()
{
    Node_006477f0_shapeb07_game* pNode = gpPool00b0b574_shapeb07_game->mpFree;
    if (!pNode) {
        pNode = gPoolMgr00b0b570_shapeb07_game.Refill();
    }
    gpPool00b0b574_shapeb07_game->mpFree = pNode->mpNext;
    gpPool00b0b574_shapeb07_game->mnCount++;
    Obj_006477f0_shapeb07_game* p = reinterpret_cast<Obj_006477f0_shapeb07_game*>(pNode)->Init(1);
    if (p) {
        return reinterpret_cast<char*>(p) + 4;
    }
    return 0;
}

struct Obj_0080bf30_shapeb07_game {
    uint32_t mVtbl0;
    uint32_t mVtbl4;
    uint32_t mVtbl8;
    uint8_t pad0C[0x10];
    uint32_t mVtbl1C;
    uint8_t pad20[0x80];
    uint32_t mnField;
    uint32_t pada4;
    // STUB: 0x0080cc50
    Obj_0080bf30_shapeb07_game* BaseInit();
};

// FUNCTION: 0x0080bf30
Obj_0080bf30_shapeb07_game* Fn0080bf30()
{
    Obj_0080bf30_shapeb07_game* p = static_cast<Obj_0080bf30_shapeb07_game*>(Fn005e55e0(0xa8));
    if (p) {
        p->BaseInit();
        p->mVtbl0 = 0xabdd38;
        p->mVtbl4 = 0xabdd1c;
        p->mVtbl8 = 0xabdcb8;
        p->mVtbl1C = 0xabdca0;
        p->mnField = 0;
        return p;
    }
    return 0;
}

struct Obj_0080c0a0_shapeb07_game {
    uint32_t mVtbl0;
    uint32_t mVtbl4;
    uint32_t mVtbl8;
    uint8_t pad0C[0x10];
    uint32_t mVtbl1C;
    uint8_t pad20[0x80];
    uint32_t mnField;
    uint32_t pada4;
    // STUB: 0x0080cc50
    Obj_0080c0a0_shapeb07_game* BaseInit();
};

// FUNCTION: 0x0080c0a0
Obj_0080c0a0_shapeb07_game* Fn0080c0a0()
{
    Obj_0080c0a0_shapeb07_game* p = static_cast<Obj_0080c0a0_shapeb07_game*>(Fn005e55e0(0xa8));
    if (p) {
        p->BaseInit();
        p->mVtbl0 = 0xabde58;
        p->mVtbl4 = 0xabde3c;
        p->mVtbl8 = 0xabddd8;
        p->mVtbl1C = 0xabddc0;
        p->mnField = 0;
        return p;
    }
    return 0;
}

struct Obj_0080c600_shapeb07_game {
    uint32_t mVtbl0;
    uint32_t mVtbl4;
    uint32_t mVtbl8;
    uint8_t pad0C[0x10];
    uint32_t mVtbl1C;
    uint8_t pad20[0x80];
    uint32_t mnField;
    uint32_t pada4;
    // STUB: 0x0080cc50
    Obj_0080c600_shapeb07_game* BaseInit();
};

// FUNCTION: 0x0080c600
Obj_0080c600_shapeb07_game* Fn0080c600()
{
    Obj_0080c600_shapeb07_game* p = static_cast<Obj_0080c600_shapeb07_game*>(Fn005e55e0(0xa8));
    if (p) {
        p->BaseInit();
        p->mVtbl0 = 0xabe2d8;
        p->mVtbl4 = 0xabe2bc;
        p->mVtbl8 = 0xabe258;
        p->mVtbl1C = 0xabe240;
        p->mnField = 0;
        return p;
    }
    return 0;
}

struct Obj_0080c850_shapeb07_game {
    uint32_t mVtbl0;
    uint32_t mVtbl4;
    uint32_t mVtbl8;
    uint8_t pad0C[0x10];
    uint32_t mVtbl1C;
    uint8_t pad20[0x80];
    uint32_t mnField;
    uint32_t pada4;
    // STUB: 0x0080cc50
    Obj_0080c850_shapeb07_game* BaseInit();
};

// FUNCTION: 0x0080c850
Obj_0080c850_shapeb07_game* Fn0080c850()
{
    Obj_0080c850_shapeb07_game* p = static_cast<Obj_0080c850_shapeb07_game*>(Fn005e55e0(0xa8));
    if (p) {
        p->BaseInit();
        p->mVtbl0 = 0xabe758;
        p->mVtbl4 = 0xabe73c;
        p->mVtbl8 = 0xabe6d8;
        p->mVtbl1C = 0xabe6c0;
        p->mnField = 0;
        return p;
    }
    return 0;
}

struct Obj_0080eb30_shapeb07_game {
    uint32_t mVtbl0;
    uint32_t mVtbl4;
    uint32_t mVtbl8;
    uint8_t pad0C[0x10];
    uint32_t mVtbl1C;
    uint8_t pad20[0x80];
    uint32_t mnField;
    uint32_t pada4;
    // STUB: 0x0080cc50
    Obj_0080eb30_shapeb07_game* BaseInit();
};

// FUNCTION: 0x0080eb30
Obj_0080eb30_shapeb07_game* Fn0080eb30()
{
    Obj_0080eb30_shapeb07_game* p = static_cast<Obj_0080eb30_shapeb07_game*>(Fn005e55e0(0xa8));
    if (p) {
        p->BaseInit();
        p->mVtbl0 = 0xabece8;
        p->mVtbl4 = 0xabeccc;
        p->mVtbl8 = 0xabec68;
        p->mVtbl1C = 0xabec50;
        p->mnField = 0;
        return p;
    }
    return 0;
}

struct Elem_005f3690_shapeb07_game {
    uint32_t v[4];
};

struct Tag_005f3690_shapeb07_game {
    uint8_t pad;
};

// STUB: 0x005f36f0
Elem_005f3690_shapeb07_game* Fn005f36f0(const Elem_005f3690_shapeb07_game* pFirst, const Elem_005f3690_shapeb07_game* pLast, Elem_005f3690_shapeb07_game* pDest, Tag_005f3690_shapeb07_game* pTag);

struct View_005f3690_shapeb07_game {
    Elem_005f3690_shapeb07_game* mpFirst;
    Elem_005f3690_shapeb07_game* mpLast;
    Elem_005f3690_shapeb07_game* mpEnd;
    View_005f3690_shapeb07_game* Fn005f3690(const View_005f3690_shapeb07_game* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005f3690 score 54
View_005f3690_shapeb07_game* View_005f3690_shapeb07_game::Fn005f3690(const View_005f3690_shapeb07_game* pOther)
{
    int32_t n = pOther->mpLast - pOther->mpFirst;
    mpFirst = 0;
    mpLast = 0;
    mpEnd = 0;
    if (n != 0) {
        Elem_005f3690_shapeb07_game* p = static_cast<Elem_005f3690_shapeb07_game*>(Fn0090cf54(n * sizeof(Elem_005f3690_shapeb07_game)));
        Tag_005f3690_shapeb07_game tag;
        mpEnd = p + n;
        mpFirst = p;
        mpLast = p;
        mpLast = Fn005f36f0(pOther->mpFirst, pOther->mpLast, p, &tag);
    }
    return this;
}
#endif

struct Elem_00624ea0_shapeb07_game {
    uint32_t v[8];
};

struct Tag_00624ea0_shapeb07_game {
    uint8_t pad;
};

// STUB: 0x0062e970
Elem_00624ea0_shapeb07_game* Fn0062e970(const Elem_00624ea0_shapeb07_game* pFirst, const Elem_00624ea0_shapeb07_game* pLast, Elem_00624ea0_shapeb07_game* pDest, Tag_00624ea0_shapeb07_game* pTag);

struct View_00624ea0_shapeb07_game {
    Elem_00624ea0_shapeb07_game* mpFirst;
    Elem_00624ea0_shapeb07_game* mpLast;
    Elem_00624ea0_shapeb07_game* mpEnd;
    View_00624ea0_shapeb07_game* Fn00624ea0(const View_00624ea0_shapeb07_game* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00624ea0 score 54
View_00624ea0_shapeb07_game* View_00624ea0_shapeb07_game::Fn00624ea0(const View_00624ea0_shapeb07_game* pOther)
{
    int32_t n = pOther->mpLast - pOther->mpFirst;
    mpFirst = 0;
    mpLast = 0;
    mpEnd = 0;
    if (n != 0) {
        Elem_00624ea0_shapeb07_game* p = static_cast<Elem_00624ea0_shapeb07_game*>(Fn0090cf54(n * sizeof(Elem_00624ea0_shapeb07_game)));
        Tag_00624ea0_shapeb07_game tag;
        mpEnd = p + n;
        mpFirst = p;
        mpLast = p;
        mpLast = Fn0062e970(pOther->mpFirst, pOther->mpLast, p, &tag);
    }
    return this;
}
#endif

struct Elem_00625190_shapeb07_game {
    uint32_t v[4];
};

struct Tag_00625190_shapeb07_game {
    uint8_t pad;
};

// STUB: 0x00624e60
Elem_00625190_shapeb07_game* Fn00624e60(const Elem_00625190_shapeb07_game* pFirst, const Elem_00625190_shapeb07_game* pLast, Elem_00625190_shapeb07_game* pDest, Tag_00625190_shapeb07_game* pTag);

struct View_00625190_shapeb07_game {
    Elem_00625190_shapeb07_game* mpFirst;
    Elem_00625190_shapeb07_game* mpLast;
    Elem_00625190_shapeb07_game* mpEnd;
    View_00625190_shapeb07_game* Fn00625190(const View_00625190_shapeb07_game* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00625190 score 54
View_00625190_shapeb07_game* View_00625190_shapeb07_game::Fn00625190(const View_00625190_shapeb07_game* pOther)
{
    int32_t n = pOther->mpLast - pOther->mpFirst;
    mpFirst = 0;
    mpLast = 0;
    mpEnd = 0;
    if (n != 0) {
        Elem_00625190_shapeb07_game* p = static_cast<Elem_00625190_shapeb07_game*>(Fn0090cf54(n * sizeof(Elem_00625190_shapeb07_game)));
        Tag_00625190_shapeb07_game tag;
        mpEnd = p + n;
        mpFirst = p;
        mpLast = p;
        mpLast = Fn00624e60(pOther->mpFirst, pOther->mpLast, p, &tag);
    }
    return this;
}
#endif

struct Elem_0064f610_shapeb07_game {
    uint32_t v[4];
};

struct Tag_0064f610_shapeb07_game {
    uint8_t pad;
};

// STUB: 0x0064f5d0
Elem_0064f610_shapeb07_game* Fn0064f5d0(const Elem_0064f610_shapeb07_game* pFirst, const Elem_0064f610_shapeb07_game* pLast, Elem_0064f610_shapeb07_game* pDest, Tag_0064f610_shapeb07_game* pTag);

struct View_0064f610_shapeb07_game {
    Elem_0064f610_shapeb07_game* mpFirst;
    Elem_0064f610_shapeb07_game* mpLast;
    Elem_0064f610_shapeb07_game* mpEnd;
    View_0064f610_shapeb07_game* Fn0064f610(const View_0064f610_shapeb07_game* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0064f610 score 54
View_0064f610_shapeb07_game* View_0064f610_shapeb07_game::Fn0064f610(const View_0064f610_shapeb07_game* pOther)
{
    int32_t n = pOther->mpLast - pOther->mpFirst;
    mpFirst = 0;
    mpLast = 0;
    mpEnd = 0;
    if (n != 0) {
        Elem_0064f610_shapeb07_game* p = static_cast<Elem_0064f610_shapeb07_game*>(Fn0090cf54(n * sizeof(Elem_0064f610_shapeb07_game)));
        Tag_0064f610_shapeb07_game tag;
        mpEnd = p + n;
        mpFirst = p;
        mpLast = p;
        mpLast = Fn0064f5d0(pOther->mpFirst, pOther->mpLast, p, &tag);
    }
    return this;
}
#endif

struct Elem_006bbab0_shapeb07_game {
    uint32_t v[8];
};

struct Tag_006bbab0_shapeb07_game {
    uint8_t pad;
};

// STUB: 0x006bb5c0
Elem_006bbab0_shapeb07_game* Fn006bb5c0(const Elem_006bbab0_shapeb07_game* pFirst, const Elem_006bbab0_shapeb07_game* pLast, Elem_006bbab0_shapeb07_game* pDest, Tag_006bbab0_shapeb07_game* pTag);

struct View_006bbab0_shapeb07_game {
    Elem_006bbab0_shapeb07_game* mpFirst;
    Elem_006bbab0_shapeb07_game* mpLast;
    Elem_006bbab0_shapeb07_game* mpEnd;
    View_006bbab0_shapeb07_game* Fn006bbab0(const View_006bbab0_shapeb07_game* pOther);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006bbab0 score 54
View_006bbab0_shapeb07_game* View_006bbab0_shapeb07_game::Fn006bbab0(const View_006bbab0_shapeb07_game* pOther)
{
    int32_t n = pOther->mpLast - pOther->mpFirst;
    mpFirst = 0;
    mpLast = 0;
    mpEnd = 0;
    if (n != 0) {
        Elem_006bbab0_shapeb07_game* p = static_cast<Elem_006bbab0_shapeb07_game*>(Fn0090cf54(n * sizeof(Elem_006bbab0_shapeb07_game)));
        Tag_006bbab0_shapeb07_game tag;
        mpEnd = p + n;
        mpFirst = p;
        mpLast = p;
        mpLast = Fn006bb5c0(pOther->mpFirst, pOther->mpLast, p, &tag);
    }
    return this;
}
#endif

struct Str3_0059d9b0_shapeb07_game {
    uint16_t* mpStart;
    uint16_t* mpFinish;
    uint16_t* mpEnd;
    // STUB: 0x00407fa0
    void InitRange(uint16_t* pFirst, uint16_t* pLast, void* pTag);
    // STUB: 0x00408a70
    Str3_0059d9b0_shapeb07_game& AssignDispatch(uint16_t* pFirst, uint16_t* pLast, void* pTag);
};

struct Frame_0059d9b0_shapeb07_game {
    uint32_t padLow;
    Str3_0059d9b0_shapeb07_game mStr;
    uint32_t padHigh;
};

struct Dev_0059d9b0_shapeb07_game {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Notify(uint16_t* pName, void* pField) = 0;
};

struct Target_0059d9b0_shapeb07_game {
    uint8_t pad0[0x90];
    Dev_0059d9b0_shapeb07_game* mpDev;
    uint8_t pad94[0x4c];
    Str3_0059d9b0_shapeb07_game mName;
    uint32_t mnPad;
    uint32_t mField;
};

struct Caller_0059d9b0_shapeb07_game {
    void Fn0059d9b0(Target_0059d9b0_shapeb07_game* pTarget);
};

const uint16_t kEmpty_0059d9b0_shapeb07_game[1] = { 0 };

#ifdef OB_DRAFTS
// CLOSE: 0x0059d9b0 score 38
void Caller_0059d9b0_shapeb07_game::Fn0059d9b0(Target_0059d9b0_shapeb07_game* pTarget)
{
    if (pTarget->mpDev) {
        pTarget->mpDev->Notify(pTarget->mName.mpStart, &pTarget->mField);
    }
    Frame_0059d9b0_shapeb07_game frame;
    Str3_0059d9b0_shapeb07_game& empty = frame.mStr;
    empty.mpStart = 0;
    empty.mpFinish = 0;
    empty.mpEnd = 0;
    empty.InitRange(const_cast<uint16_t*>(kEmpty_0059d9b0_shapeb07_game), const_cast<uint16_t*>(kEmpty_0059d9b0_shapeb07_game), &pTarget);
    uint16_t* pBegin = empty.mpStart;
    if (&empty != &pTarget->mName) {
        pTarget->mName.AssignDispatch(empty.mpStart, empty.mpFinish, &pTarget);
    }
    if (pBegin) {
        Fn0090cf63(pBegin);
    }
}
#endif

struct Str3_0059dcf0_shapeb07_game {
    uint16_t* mpStart;
    uint16_t* mpFinish;
    uint16_t* mpEnd;
    // STUB: 0x00407fa0
    void InitRange(uint16_t* pFirst, uint16_t* pLast, void* pTag);
    // STUB: 0x00408a70
    Str3_0059dcf0_shapeb07_game& AssignDispatch(uint16_t* pFirst, uint16_t* pLast, void* pTag);
};

struct Frame_0059dcf0_shapeb07_game {
    uint32_t padLow;
    Str3_0059dcf0_shapeb07_game mStr;
    uint32_t padHigh;
};

struct Dev_0059dcf0_shapeb07_game {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Notify(uint16_t* pName, void* pField) = 0;
};

struct Target_0059dcf0_shapeb07_game {
    uint8_t pad0[0x90];
    Dev_0059dcf0_shapeb07_game* mpDev;
    uint8_t pad94[0x268];
    Str3_0059dcf0_shapeb07_game mName;
    uint32_t mnPad;
    uint32_t mField;
};

struct Caller_0059dcf0_shapeb07_game {
    void Fn0059dcf0(Target_0059dcf0_shapeb07_game* pTarget);
};

const uint16_t kEmpty_0059dcf0_shapeb07_game[1] = { 0 };

#ifdef OB_DRAFTS
// CLOSE: 0x0059dcf0 score 38
void Caller_0059dcf0_shapeb07_game::Fn0059dcf0(Target_0059dcf0_shapeb07_game* pTarget)
{
    if (pTarget->mpDev) {
        pTarget->mpDev->Notify(pTarget->mName.mpStart, &pTarget->mField);
    }
    Frame_0059dcf0_shapeb07_game frame;
    Str3_0059dcf0_shapeb07_game& empty = frame.mStr;
    empty.mpStart = 0;
    empty.mpFinish = 0;
    empty.mpEnd = 0;
    empty.InitRange(const_cast<uint16_t*>(kEmpty_0059dcf0_shapeb07_game), const_cast<uint16_t*>(kEmpty_0059dcf0_shapeb07_game), &pTarget);
    uint16_t* pBegin = empty.mpStart;
    if (&empty != &pTarget->mName) {
        pTarget->mName.AssignDispatch(empty.mpStart, empty.mpFinish, &pTarget);
    }
    if (pBegin) {
        Fn0090cf63(pBegin);
    }
}
#endif

struct Str3_0059df50_shapeb07_game {
    uint16_t* mpStart;
    uint16_t* mpFinish;
    uint16_t* mpEnd;
    // STUB: 0x00407fa0
    void InitRange(uint16_t* pFirst, uint16_t* pLast, void* pTag);
    // STUB: 0x00408a70
    Str3_0059df50_shapeb07_game& AssignDispatch(uint16_t* pFirst, uint16_t* pLast, void* pTag);
};

struct Frame_0059df50_shapeb07_game {
    uint32_t padLow;
    Str3_0059df50_shapeb07_game mStr;
    uint32_t padHigh;
};

struct Dev_0059df50_shapeb07_game {
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
    virtual void Notify(uint16_t* pName, void* pField) = 0;
};

struct Target_0059df50_shapeb07_game {
    uint8_t pad0[0x90];
    Dev_0059df50_shapeb07_game* mpDev;
    uint8_t pad94[0x2bc];
    Str3_0059df50_shapeb07_game mName;
    uint32_t mnPad;
    uint32_t mField;
};

struct Caller_0059df50_shapeb07_game {
    void Fn0059df50(Target_0059df50_shapeb07_game* pTarget);
};

const uint16_t kEmpty_0059df50_shapeb07_game[1] = { 0 };

#ifdef OB_DRAFTS
// CLOSE: 0x0059df50 score 38
void Caller_0059df50_shapeb07_game::Fn0059df50(Target_0059df50_shapeb07_game* pTarget)
{
    if (pTarget->mpDev) {
        pTarget->mpDev->Notify(pTarget->mName.mpStart, &pTarget->mField);
    }
    Frame_0059df50_shapeb07_game frame;
    Str3_0059df50_shapeb07_game& empty = frame.mStr;
    empty.mpStart = 0;
    empty.mpFinish = 0;
    empty.mpEnd = 0;
    empty.InitRange(const_cast<uint16_t*>(kEmpty_0059df50_shapeb07_game), const_cast<uint16_t*>(kEmpty_0059df50_shapeb07_game), &pTarget);
    uint16_t* pBegin = empty.mpStart;
    if (&empty != &pTarget->mName) {
        pTarget->mName.AssignDispatch(empty.mpStart, empty.mpFinish, &pTarget);
    }
    if (pBegin) {
        Fn0090cf63(pBegin);
    }
}
#endif

struct Str3_0059e260_shapeb07_game {
    uint16_t* mpStart;
    uint16_t* mpFinish;
    uint16_t* mpEnd;
    // STUB: 0x00407fa0
    void InitRange(uint16_t* pFirst, uint16_t* pLast, void* pTag);
    // STUB: 0x00408a70
    Str3_0059e260_shapeb07_game& AssignDispatch(uint16_t* pFirst, uint16_t* pLast, void* pTag);
};

struct Frame_0059e260_shapeb07_game {
    uint32_t padLow;
    Str3_0059e260_shapeb07_game mStr;
    uint32_t padHigh;
};

struct Dev_0059e260_shapeb07_game {
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
    virtual void Notify(uint16_t* pName, void* pField) = 0;
};

struct Target_0059e260_shapeb07_game {
    uint8_t pad0[0x90];
    Dev_0059e260_shapeb07_game* mpDev;
    uint8_t pad94[0x334];
    Str3_0059e260_shapeb07_game mName;
    uint32_t mnPad;
    uint32_t mField;
};

struct Caller_0059e260_shapeb07_game {
    void Fn0059e260(Target_0059e260_shapeb07_game* pTarget);
};

const uint16_t kEmpty_0059e260_shapeb07_game[1] = { 0 };

#ifdef OB_DRAFTS
// CLOSE: 0x0059e260 score 38
void Caller_0059e260_shapeb07_game::Fn0059e260(Target_0059e260_shapeb07_game* pTarget)
{
    if (pTarget->mpDev) {
        pTarget->mpDev->Notify(pTarget->mName.mpStart, &pTarget->mField);
    }
    Frame_0059e260_shapeb07_game frame;
    Str3_0059e260_shapeb07_game& empty = frame.mStr;
    empty.mpStart = 0;
    empty.mpFinish = 0;
    empty.mpEnd = 0;
    empty.InitRange(const_cast<uint16_t*>(kEmpty_0059e260_shapeb07_game), const_cast<uint16_t*>(kEmpty_0059e260_shapeb07_game), &pTarget);
    uint16_t* pBegin = empty.mpStart;
    if (&empty != &pTarget->mName) {
        pTarget->mName.AssignDispatch(empty.mpStart, empty.mpFinish, &pTarget);
    }
    if (pBegin) {
        Fn0090cf63(pBegin);
    }
}
#endif

struct Str3_0059eb50_shapeb07_game {
    uint16_t* mpStart;
    uint16_t* mpFinish;
    uint16_t* mpEnd;
    // STUB: 0x00407fa0
    void InitRange(uint16_t* pFirst, uint16_t* pLast, void* pTag);
    // STUB: 0x00408a70
    Str3_0059eb50_shapeb07_game& AssignDispatch(uint16_t* pFirst, uint16_t* pLast, void* pTag);
};

struct Frame_0059eb50_shapeb07_game {
    uint32_t padLow;
    Str3_0059eb50_shapeb07_game mStr;
    uint32_t padHigh;
};

struct Dev_0059eb50_shapeb07_game {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Notify(uint16_t* pName, void* pField) = 0;
};

struct Target_0059eb50_shapeb07_game {
    uint8_t pad0[0x90];
    Dev_0059eb50_shapeb07_game* mpDev;
    uint8_t pad94[0x3a0];
    Str3_0059eb50_shapeb07_game mName;
    uint32_t mnPad;
    uint32_t mField;
};

struct Caller_0059eb50_shapeb07_game {
    void Fn0059eb50(Target_0059eb50_shapeb07_game* pTarget);
};

const uint16_t kEmpty_0059eb50_shapeb07_game[1] = { 0 };

#ifdef OB_DRAFTS
// CLOSE: 0x0059eb50 score 38
void Caller_0059eb50_shapeb07_game::Fn0059eb50(Target_0059eb50_shapeb07_game* pTarget)
{
    if (pTarget->mpDev) {
        pTarget->mpDev->Notify(pTarget->mName.mpStart, &pTarget->mField);
    }
    Frame_0059eb50_shapeb07_game frame;
    Str3_0059eb50_shapeb07_game& empty = frame.mStr;
    empty.mpStart = 0;
    empty.mpFinish = 0;
    empty.mpEnd = 0;
    empty.InitRange(const_cast<uint16_t*>(kEmpty_0059eb50_shapeb07_game), const_cast<uint16_t*>(kEmpty_0059eb50_shapeb07_game), &pTarget);
    uint16_t* pBegin = empty.mpStart;
    if (&empty != &pTarget->mName) {
        pTarget->mName.AssignDispatch(empty.mpStart, empty.mpFinish, &pTarget);
    }
    if (pBegin) {
        Fn0090cf63(pBegin);
    }
}
#endif

struct Second_005104f0_shapeb07_game {
    uint8_t mBytes[12];
    // STUB: 0x00462f00
    void InitCopy(const Second_005104f0_shapeb07_game* pOther);
};

struct Pair_005104f0_shapeb07_game {
    uint32_t mKey;
    Second_005104f0_shapeb07_game mSecond;
    Pair_005104f0_shapeb07_game(const Pair_005104f0_shapeb07_game& other) : mKey(other.mKey)
    {
        mSecond.InitCopy(&other.mSecond);
    }
};

struct Node_005104f0_shapeb07_game {
    uint32_t mColor;
    Node_005104f0_shapeb07_game* mpParent;
    Node_005104f0_shapeb07_game* mpLeft;
    Node_005104f0_shapeb07_game* mpRight;
    Pair_005104f0_shapeb07_game mValue;
};

// STUB: 0x0040d5e0
void Fn0040d5e0_005104f0(Node_005104f0_shapeb07_game* pNode, Node_005104f0_shapeb07_game** ppRoot);

struct View_005104f0_shapeb07_game {
    Node_005104f0_shapeb07_game* mpHeader;
    uint32_t mnCount;
    void Fn005104f0(Node_005104f0_shapeb07_game** ppOut, Node_005104f0_shapeb07_game* pX, Node_005104f0_shapeb07_game* pY, const Pair_005104f0_shapeb07_game* pValue, uint32_t bRight);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005104f0 score 4
void View_005104f0_shapeb07_game::Fn005104f0(Node_005104f0_shapeb07_game** ppOut, Node_005104f0_shapeb07_game* pX, Node_005104f0_shapeb07_game* pY, const Pair_005104f0_shapeb07_game* pValue, uint32_t bRight)
{
    Node_005104f0_shapeb07_game* pNode;
    if (pY == mpHeader || (bRight == 0 && (pX != 0 || pValue->mKey < pY->mValue.mKey))) {
        pNode = static_cast<Node_005104f0_shapeb07_game*>(Fn0090cf54(0x20));
        new (&pNode->mValue) Pair_005104f0_shapeb07_game(*pValue);
        pY->mpLeft = pNode;
        if (pY == mpHeader) {
            mpHeader->mpParent = pNode;
            mpHeader->mpRight = pNode;
        } else if (pY == mpHeader->mpLeft) {
            mpHeader->mpLeft = pNode;
        }
    } else {
        pNode = static_cast<Node_005104f0_shapeb07_game*>(Fn0090cf54(0x20));
        new (&pNode->mValue) Pair_005104f0_shapeb07_game(*pValue);
        pY->mpRight = pNode;
        if (pY == mpHeader->mpRight) {
            mpHeader->mpRight = pNode;
        }
    }
    pNode->mpParent = pY;
    pNode->mpLeft = 0;
    pNode->mpRight = 0;
    Fn0040d5e0_005104f0(pNode, &mpHeader->mpParent);
    mnCount++;
    *ppOut = pNode;
}
#endif

struct Second_00671700_shapeb07_game {
    uint8_t mBytes[112];
    // STUB: 0x0066ed80
    void InitCopy(const Second_00671700_shapeb07_game* pOther);
};

struct Pair_00671700_shapeb07_game {
    uint32_t mKey;
    Second_00671700_shapeb07_game mSecond;
    Pair_00671700_shapeb07_game(const Pair_00671700_shapeb07_game& other) : mKey(other.mKey)
    {
        mSecond.InitCopy(&other.mSecond);
    }
};

struct Node_00671700_shapeb07_game {
    uint32_t mColor;
    Node_00671700_shapeb07_game* mpParent;
    Node_00671700_shapeb07_game* mpLeft;
    Node_00671700_shapeb07_game* mpRight;
    Pair_00671700_shapeb07_game mValue;
};

// STUB: 0x0040d5e0
void Fn0040d5e0_00671700(Node_00671700_shapeb07_game* pNode, Node_00671700_shapeb07_game** ppRoot);

struct View_00671700_shapeb07_game {
    Node_00671700_shapeb07_game* mpHeader;
    uint32_t mnCount;
    void Fn00671700(Node_00671700_shapeb07_game** ppOut, Node_00671700_shapeb07_game* pX, Node_00671700_shapeb07_game* pY, const Pair_00671700_shapeb07_game* pValue, uint32_t bRight);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00671700 score 4
void View_00671700_shapeb07_game::Fn00671700(Node_00671700_shapeb07_game** ppOut, Node_00671700_shapeb07_game* pX, Node_00671700_shapeb07_game* pY, const Pair_00671700_shapeb07_game* pValue, uint32_t bRight)
{
    Node_00671700_shapeb07_game* pNode;
    if (pY == mpHeader || (bRight == 0 && (pX != 0 || pValue->mKey < pY->mValue.mKey))) {
        pNode = static_cast<Node_00671700_shapeb07_game*>(Fn0090cf54(0x84));
        new (&pNode->mValue) Pair_00671700_shapeb07_game(*pValue);
        pY->mpLeft = pNode;
        if (pY == mpHeader) {
            mpHeader->mpParent = pNode;
            mpHeader->mpRight = pNode;
        } else if (pY == mpHeader->mpLeft) {
            mpHeader->mpLeft = pNode;
        }
    } else {
        pNode = static_cast<Node_00671700_shapeb07_game*>(Fn0090cf54(0x84));
        new (&pNode->mValue) Pair_00671700_shapeb07_game(*pValue);
        pY->mpRight = pNode;
        if (pY == mpHeader->mpRight) {
            mpHeader->mpRight = pNode;
        }
    }
    pNode->mpParent = pY;
    pNode->mpLeft = 0;
    pNode->mpRight = 0;
    Fn0040d5e0_00671700(pNode, &mpHeader->mpParent);
    mnCount++;
    *ppOut = pNode;
}
#endif

struct Second_006730d0_shapeb07_game {
    uint8_t mBytes[12];
    // STUB: 0x00672060
    void InitCopy(const Second_006730d0_shapeb07_game* pOther);
};

struct Pair_006730d0_shapeb07_game {
    uint32_t mKey;
    Second_006730d0_shapeb07_game mSecond;
    Pair_006730d0_shapeb07_game(const Pair_006730d0_shapeb07_game& other) : mKey(other.mKey)
    {
        mSecond.InitCopy(&other.mSecond);
    }
};

struct Node_006730d0_shapeb07_game {
    uint32_t mColor;
    Node_006730d0_shapeb07_game* mpParent;
    Node_006730d0_shapeb07_game* mpLeft;
    Node_006730d0_shapeb07_game* mpRight;
    Pair_006730d0_shapeb07_game mValue;
};

// STUB: 0x0040d5e0
void Fn0040d5e0_006730d0(Node_006730d0_shapeb07_game* pNode, Node_006730d0_shapeb07_game** ppRoot);

struct View_006730d0_shapeb07_game {
    Node_006730d0_shapeb07_game* mpHeader;
    uint32_t mnCount;
    void Fn006730d0(Node_006730d0_shapeb07_game** ppOut, Node_006730d0_shapeb07_game* pX, Node_006730d0_shapeb07_game* pY, const Pair_006730d0_shapeb07_game* pValue, uint32_t bRight);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006730d0 score 4
void View_006730d0_shapeb07_game::Fn006730d0(Node_006730d0_shapeb07_game** ppOut, Node_006730d0_shapeb07_game* pX, Node_006730d0_shapeb07_game* pY, const Pair_006730d0_shapeb07_game* pValue, uint32_t bRight)
{
    Node_006730d0_shapeb07_game* pNode;
    if (pY == mpHeader || (bRight == 0 && (pX != 0 || pValue->mKey < pY->mValue.mKey))) {
        pNode = static_cast<Node_006730d0_shapeb07_game*>(Fn0090cf54(0x20));
        new (&pNode->mValue) Pair_006730d0_shapeb07_game(*pValue);
        pY->mpLeft = pNode;
        if (pY == mpHeader) {
            mpHeader->mpParent = pNode;
            mpHeader->mpRight = pNode;
        } else if (pY == mpHeader->mpLeft) {
            mpHeader->mpLeft = pNode;
        }
    } else {
        pNode = static_cast<Node_006730d0_shapeb07_game*>(Fn0090cf54(0x20));
        new (&pNode->mValue) Pair_006730d0_shapeb07_game(*pValue);
        pY->mpRight = pNode;
        if (pY == mpHeader->mpRight) {
            mpHeader->mpRight = pNode;
        }
    }
    pNode->mpParent = pY;
    pNode->mpLeft = 0;
    pNode->mpRight = 0;
    Fn0040d5e0_006730d0(pNode, &mpHeader->mpParent);
    mnCount++;
    *ppOut = pNode;
}
#endif

struct Second_00673260_shapeb07_game {
    uint8_t mBytes[12];
    // STUB: 0x00672110
    void InitCopy(const Second_00673260_shapeb07_game* pOther);
};

struct Pair_00673260_shapeb07_game {
    uint32_t mKey;
    Second_00673260_shapeb07_game mSecond;
    Pair_00673260_shapeb07_game(const Pair_00673260_shapeb07_game& other) : mKey(other.mKey)
    {
        mSecond.InitCopy(&other.mSecond);
    }
};

struct Node_00673260_shapeb07_game {
    uint32_t mColor;
    Node_00673260_shapeb07_game* mpParent;
    Node_00673260_shapeb07_game* mpLeft;
    Node_00673260_shapeb07_game* mpRight;
    Pair_00673260_shapeb07_game mValue;
};

// STUB: 0x0040d5e0
void Fn0040d5e0_00673260(Node_00673260_shapeb07_game* pNode, Node_00673260_shapeb07_game** ppRoot);

struct View_00673260_shapeb07_game {
    Node_00673260_shapeb07_game* mpHeader;
    uint32_t mnCount;
    void Fn00673260(Node_00673260_shapeb07_game** ppOut, Node_00673260_shapeb07_game* pX, Node_00673260_shapeb07_game* pY, const Pair_00673260_shapeb07_game* pValue, uint32_t bRight);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00673260 score 4
void View_00673260_shapeb07_game::Fn00673260(Node_00673260_shapeb07_game** ppOut, Node_00673260_shapeb07_game* pX, Node_00673260_shapeb07_game* pY, const Pair_00673260_shapeb07_game* pValue, uint32_t bRight)
{
    Node_00673260_shapeb07_game* pNode;
    if (pY == mpHeader || (bRight == 0 && (pX != 0 || pValue->mKey < pY->mValue.mKey))) {
        pNode = static_cast<Node_00673260_shapeb07_game*>(Fn0090cf54(0x20));
        new (&pNode->mValue) Pair_00673260_shapeb07_game(*pValue);
        pY->mpLeft = pNode;
        if (pY == mpHeader) {
            mpHeader->mpParent = pNode;
            mpHeader->mpRight = pNode;
        } else if (pY == mpHeader->mpLeft) {
            mpHeader->mpLeft = pNode;
        }
    } else {
        pNode = static_cast<Node_00673260_shapeb07_game*>(Fn0090cf54(0x20));
        new (&pNode->mValue) Pair_00673260_shapeb07_game(*pValue);
        pY->mpRight = pNode;
        if (pY == mpHeader->mpRight) {
            mpHeader->mpRight = pNode;
        }
    }
    pNode->mpParent = pY;
    pNode->mpLeft = 0;
    pNode->mpRight = 0;
    Fn0040d5e0_00673260(pNode, &mpHeader->mpParent);
    mnCount++;
    *ppOut = pNode;
}
#endif

struct Second_0074f970_shapeb07_game {
    uint8_t mBytes[112];
    // STUB: 0x0074d4f0
    void InitCopy(const Second_0074f970_shapeb07_game* pOther);
};

struct Pair_0074f970_shapeb07_game {
    uint32_t mKey;
    Second_0074f970_shapeb07_game mSecond;
    Pair_0074f970_shapeb07_game(const Pair_0074f970_shapeb07_game& other) : mKey(other.mKey)
    {
        mSecond.InitCopy(&other.mSecond);
    }
};

struct Node_0074f970_shapeb07_game {
    uint32_t mColor;
    Node_0074f970_shapeb07_game* mpParent;
    Node_0074f970_shapeb07_game* mpLeft;
    Node_0074f970_shapeb07_game* mpRight;
    Pair_0074f970_shapeb07_game mValue;
};

// STUB: 0x0040d5e0
void Fn0040d5e0_0074f970(Node_0074f970_shapeb07_game* pNode, Node_0074f970_shapeb07_game** ppRoot);

struct View_0074f970_shapeb07_game {
    Node_0074f970_shapeb07_game* mpHeader;
    uint32_t mnCount;
    void Fn0074f970(Node_0074f970_shapeb07_game** ppOut, Node_0074f970_shapeb07_game* pX, Node_0074f970_shapeb07_game* pY, const Pair_0074f970_shapeb07_game* pValue, uint32_t bRight);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0074f970 score 4
void View_0074f970_shapeb07_game::Fn0074f970(Node_0074f970_shapeb07_game** ppOut, Node_0074f970_shapeb07_game* pX, Node_0074f970_shapeb07_game* pY, const Pair_0074f970_shapeb07_game* pValue, uint32_t bRight)
{
    Node_0074f970_shapeb07_game* pNode;
    if (pY == mpHeader || (bRight == 0 && (pX != 0 || pValue->mKey < pY->mValue.mKey))) {
        pNode = static_cast<Node_0074f970_shapeb07_game*>(Fn0090cf54(0x84));
        new (&pNode->mValue) Pair_0074f970_shapeb07_game(*pValue);
        pY->mpLeft = pNode;
        if (pY == mpHeader) {
            mpHeader->mpParent = pNode;
            mpHeader->mpRight = pNode;
        } else if (pY == mpHeader->mpLeft) {
            mpHeader->mpLeft = pNode;
        }
    } else {
        pNode = static_cast<Node_0074f970_shapeb07_game*>(Fn0090cf54(0x84));
        new (&pNode->mValue) Pair_0074f970_shapeb07_game(*pValue);
        pY->mpRight = pNode;
        if (pY == mpHeader->mpRight) {
            mpHeader->mpRight = pNode;
        }
    }
    pNode->mpParent = pY;
    pNode->mpLeft = 0;
    pNode->mpRight = 0;
    Fn0040d5e0_0074f970(pNode, &mpHeader->mpParent);
    mnCount++;
    *ppOut = pNode;
}
#endif

