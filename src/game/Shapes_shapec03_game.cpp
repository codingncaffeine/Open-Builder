// Shape families of packet shapec03_game, written by scratch/s17/gen/shapec03_game/*.py.
#include "common/types.h"
#include "common/compiler.h"

struct View_009ec140_shapec03_game {
    uint8_t Fn009ec140();
};

// FUNCTION: 0x009ec140
uint8_t View_009ec140_shapec03_game::Fn009ec140()
{
    return 0x2e;
}

struct View_009ec150_shapec03_game {
    uint8_t Fn009ec150();
};

// FUNCTION: 0x009ec150
uint8_t View_009ec150_shapec03_game::Fn009ec150()
{
    return 0x2c;
}

struct View_009ec380_shapec03_game {
    uint8_t Fn009ec380();
};

// FUNCTION: 0x009ec380
uint8_t View_009ec380_shapec03_game::Fn009ec380()
{
    return 0x1;
}

struct View_009edcb0_shapec03_game {
    uint8_t Fn009edcb0();
};

// FUNCTION: 0x009edcb0
uint8_t View_009edcb0_shapec03_game::Fn009edcb0()
{
    return 0x20;
}

struct View_0042f750_shapec03_game {
    void* Fn0042f750();
};

// FUNCTION: 0x0042f750
void* View_0042f750_shapec03_game::Fn0042f750()
{
    return reinterpret_cast<uint8_t*>(this) - 0xc0;
}

struct View_00669250_shapec03_game {
    void* Fn00669250();
};

// FUNCTION: 0x00669250
void* View_00669250_shapec03_game::Fn00669250()
{
    return reinterpret_cast<uint8_t*>(this) - 0xe4;
}

struct View_00793f80_shapec03_game {
    void* Fn00793f80();
};

// FUNCTION: 0x00793f80
void* View_00793f80_shapec03_game::Fn00793f80()
{
    return reinterpret_cast<uint8_t*>(this) - 0xe0;
}

struct View_0043f650_shapec03_game {
    uint8_t pad[0x1f];
    uint8_t mFlag;
    bool Fn0043f650();
};

// FUNCTION: 0x0043f650
bool View_0043f650_shapec03_game::Fn0043f650()
{
    return mFlag != 0;
}

struct View_004596b0_shapec03_game {
    uint8_t pad[0x25];
    uint8_t mFlag;
    bool Fn004596b0();
};

// FUNCTION: 0x004596b0
bool View_004596b0_shapec03_game::Fn004596b0()
{
    return mFlag != 0;
}

struct View_005d16b0_shapec03_game {
    uint8_t pad[0x4];
    uint8_t mFlag;
    bool Fn005d16b0();
};

// FUNCTION: 0x005d16b0
bool View_005d16b0_shapec03_game::Fn005d16b0()
{
    return mFlag == 0;
}

struct View_00418820_shapec03_game {
    uint8_t pad[0x5c];
    struct Target_00418820* mpTarget;
    void Fn00418820();
};

struct Target_00418820 {
    // STUB: 0x0041d650
    void Callee();
};

// FUNCTION: 0x00418820
void View_00418820_shapec03_game::Fn00418820()
{
    if (mpTarget) {
        mpTarget->Callee();
    }
}

struct View_00418830_shapec03_game {
    uint8_t pad[0x5c];
    struct Target_00418830* mpTarget;
    void Fn00418830();
};

struct Target_00418830 {
    // STUB: 0x0041d710
    void Callee();
};

// FUNCTION: 0x00418830
void View_00418830_shapec03_game::Fn00418830()
{
    if (mpTarget) {
        mpTarget->Callee();
    }
}

struct View_004410a0_shapec03_game {
    uint8_t pad[0xf8];
    uint8_t mFlag;
    bool Fn004410a0();
};

// FUNCTION: 0x004410a0
bool View_004410a0_shapec03_game::Fn004410a0()
{
    return mFlag == 0;
}

struct View_00649230_shapec03_game {
    uint8_t pad[0x112];
    uint8_t mFlag;
    bool Fn00649230();
};

// FUNCTION: 0x00649230
bool View_00649230_shapec03_game::Fn00649230()
{
    return mFlag != 0;
}

struct View_0070c850_shapec03_game {
    uint8_t pad[0x12c];
    uint8_t mFlag;
    bool Fn0070c850();
};

// FUNCTION: 0x0070c850
bool View_0070c850_shapec03_game::Fn0070c850()
{
    return mFlag == 0;
}

struct View_00751ed0_shapec03_game {
    uint8_t pad[0x60];
    struct Target_00751ed0* mpTarget;
    void Fn00751ed0();
};

struct Target_00751ed0 {
    // STUB: 0x00750ca0
    void Callee();
};

// FUNCTION: 0x00751ed0
void View_00751ed0_shapec03_game::Fn00751ed0()
{
    if (mpTarget) {
        mpTarget->Callee();
    }
}

// STUB: 0x00409cb0
void Fn00409cb0(uint32_t a, uint32_t b);

// FUNCTION: 0x00409e10
void Fn00409e10(uint32_t a)
{
    Fn00409cb0(a, 0x0);
}

// FUNCTION: 0x00409e20
void Fn00409e20(uint32_t a)
{
    Fn00409cb0(a, 0x1);
}

// FUNCTION: 0x00409e30
void Fn00409e30(uint32_t a)
{
    Fn00409cb0(a, 0x2);
}

struct View_0042f7d0_shapec03_game {
    uint8_t pad[0x34];
    uint32_t mFlags;
    bool Fn0042f7d0(uint32_t mask);
};

// FUNCTION: 0x0042f7d0
bool View_0042f7d0_shapec03_game::Fn0042f7d0(uint32_t mask)
{
    return (mFlags & mask) != 0;
}

struct View_00604d30_shapec03_game {
    uint8_t pad[0x13c];
    uint32_t mFlags;
    bool Fn00604d30(uint32_t mask);
};

// FUNCTION: 0x00604d30
bool View_00604d30_shapec03_game::Fn00604d30(uint32_t mask)
{
    return (mFlags & mask) != 0;
}

struct View_00762550_shapec03_game {
    uint8_t pad[0x104];
    uint32_t mFlags;
    bool Fn00762550(uint32_t mask);
};

// FUNCTION: 0x00762550
bool View_00762550_shapec03_game::Fn00762550(uint32_t mask)
{
    return (mFlags & mask) != 0;
}

struct Iface_009e45f0_shapec03_game {
    virtual void Slot0(uint32_t p) = 0;
    virtual void Slot1(uint32_t p) = 0;
    virtual void Slot2(uint32_t p) = 0;
    virtual void Slot3(uint32_t p) = 0;
    virtual void Slot4(uint32_t p) = 0;
    virtual void Slot5(uint32_t p) = 0;
    virtual void Slot6(uint32_t p) = 0;
};

struct View_009e45f0_shapec03_game {
    uint32_t Fn009e45f0(uint32_t p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009e45f0 score 5
uint32_t View_009e45f0_shapec03_game::Fn009e45f0(uint32_t p)
{
    uint32_t zero = 0;
    (void)zero;
    reinterpret_cast<Iface_009e45f0_shapec03_game*>(this)->Slot6(p);
    return p;
}
#endif

struct Iface_009e4ff0_shapec03_game {
    virtual void Slot0(uint32_t p) = 0;
    virtual void Slot1(uint32_t p) = 0;
    virtual void Slot2(uint32_t p) = 0;
    virtual void Slot3(uint32_t p) = 0;
    virtual void Slot4(uint32_t p) = 0;
};

struct View_009e4ff0_shapec03_game {
    uint32_t Fn009e4ff0(uint32_t p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009e4ff0 score 5
uint32_t View_009e4ff0_shapec03_game::Fn009e4ff0(uint32_t p)
{
    uint32_t zero = 0;
    (void)zero;
    reinterpret_cast<Iface_009e4ff0_shapec03_game*>(this)->Slot4(p);
    return p;
}
#endif

struct Iface_009e5010_shapec03_game {
    virtual void Slot0(uint32_t p) = 0;
    virtual void Slot1(uint32_t p) = 0;
    virtual void Slot2(uint32_t p) = 0;
    virtual void Slot3(uint32_t p) = 0;
    virtual void Slot4(uint32_t p) = 0;
    virtual void Slot5(uint32_t p) = 0;
};

struct View_009e5010_shapec03_game {
    uint32_t Fn009e5010(uint32_t p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009e5010 score 5
uint32_t View_009e5010_shapec03_game::Fn009e5010(uint32_t p)
{
    uint32_t zero = 0;
    (void)zero;
    reinterpret_cast<Iface_009e5010_shapec03_game*>(this)->Slot5(p);
    return p;
}
#endif

struct Iface_009e8b40_shapec03_game {
    virtual void Slot0(uint32_t p) = 0;
    virtual void Slot1(uint32_t p) = 0;
    virtual void Slot2(uint32_t p) = 0;
    virtual void Slot3(uint32_t p) = 0;
};

struct View_009e8b40_shapec03_game {
    uint32_t Fn009e8b40(uint32_t p);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009e8b40 score 5
uint32_t View_009e8b40_shapec03_game::Fn009e8b40(uint32_t p)
{
    uint32_t zero = 0;
    (void)zero;
    reinterpret_cast<Iface_009e8b40_shapec03_game*>(this)->Slot3(p);
    return p;
}
#endif

struct Dest_00459dc0_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3(const char* p, uint32_t n) = 0;
};

struct View_00459dc0_shapec03_game {
    uint8_t pad[0x78];
    const char* mpBegin;
    const char* mpEnd;
    uint32_t Size() const { return static_cast<uint32_t>(mpEnd - mpBegin); }
    void Fn00459dc0(Dest_00459dc0_shapec03_game* pDest);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00459dc0 score 17
void View_00459dc0_shapec03_game::Fn00459dc0(Dest_00459dc0_shapec03_game* pDest)
{
    pDest->Slot3(mpBegin, Size());
}
#endif

struct Dest_00459de0_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3(const char* p, uint32_t n) = 0;
};

struct View_00459de0_shapec03_game {
    uint8_t pad[0xa0];
    const char* mpBegin;
    const char* mpEnd;
    uint32_t Size() const { return static_cast<uint32_t>(mpEnd - mpBegin); }
    void Fn00459de0(Dest_00459de0_shapec03_game* pDest);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00459de0 score 17
void View_00459de0_shapec03_game::Fn00459de0(Dest_00459de0_shapec03_game* pDest)
{
    pDest->Slot3(mpBegin, Size());
}
#endif

struct Dest_00459e10_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3(const char* p, uint32_t n) = 0;
};

struct View_00459e10_shapec03_game {
    uint8_t pad[0xc8];
    const char* mpBegin;
    const char* mpEnd;
    uint32_t Size() const { return static_cast<uint32_t>(mpEnd - mpBegin); }
    void Fn00459e10(Dest_00459e10_shapec03_game* pDest);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00459e10 score 17
void View_00459e10_shapec03_game::Fn00459e10(Dest_00459e10_shapec03_game* pDest)
{
    pDest->Slot3(mpBegin, Size());
}
#endif

// STUB: 0x009e58a0
void Fn9e58a0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);

struct View_009e5860_shapec03_game {
    uint32_t Fn009e5860(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);
};

// FUNCTION: 0x009e5860
uint32_t View_009e5860_shapec03_game::Fn009e5860(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    Fn9e58a0(a, b, c, d, e, f, g);
    return a;
}

// STUB: 0x009e5c40
void Fn9e5c40(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);

struct View_009e5c00_shapec03_game {
    uint32_t Fn009e5c00(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);
};

// FUNCTION: 0x009e5c00
uint32_t View_009e5c00_shapec03_game::Fn009e5c00(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    Fn9e5c40(a, b, c, d, e, f, g);
    return a;
}

// STUB: 0x009e61a0
void Fn9e61a0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);

struct View_009e6160_shapec03_game {
    uint32_t Fn009e6160(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);
};

// FUNCTION: 0x009e6160
uint32_t View_009e6160_shapec03_game::Fn009e6160(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    Fn9e61a0(a, b, c, d, e, f, g);
    return a;
}

// STUB: 0x009e6530
void Fn9e6530(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);

struct View_009e64f0_shapec03_game {
    uint32_t Fn009e64f0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);
};

// FUNCTION: 0x009e64f0
uint32_t View_009e64f0_shapec03_game::Fn009e64f0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    Fn9e6530(a, b, c, d, e, f, g);
    return a;
}

struct Item_0042e4c0_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0042e4c0 score 6
Item_0042e4c0_shapec03_game** Fn0042e4c0(Item_0042e4c0_shapec03_game** pFirst, Item_0042e4c0_shapec03_game** pLast, Item_0042e4c0_shapec03_game** pDest)
{
    while (pFirst != pLast) {
        if (pDest) {
            Item_0042e4c0_shapec03_game* pItem = *pFirst;
            *pDest = pItem;
            if (pItem) {
                pItem->Slot1();
            }
        }
        ++pFirst;
        ++pDest;
    }
    return pDest;
}
#endif

struct Item_00586b70_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00586b70 score 6
Item_00586b70_shapec03_game** Fn00586b70(Item_00586b70_shapec03_game** pFirst, Item_00586b70_shapec03_game** pLast, Item_00586b70_shapec03_game** pDest)
{
    while (pFirst != pLast) {
        if (pDest) {
            Item_00586b70_shapec03_game* pItem = *pFirst;
            *pDest = pItem;
            if (pItem) {
                pItem->Slot4();
            }
        }
        ++pFirst;
        ++pDest;
    }
    return pDest;
}
#endif

struct Item_00586c70_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00586c70 score 6
Item_00586c70_shapec03_game** Fn00586c70(Item_00586c70_shapec03_game** pFirst, Item_00586c70_shapec03_game** pLast, Item_00586c70_shapec03_game** pDest)
{
    while (pFirst != pLast) {
        if (pDest) {
            Item_00586c70_shapec03_game* pItem = *pFirst;
            *pDest = pItem;
            if (pItem) {
                pItem->Slot2();
            }
        }
        ++pFirst;
        ++pDest;
    }
    return pDest;
}
#endif

struct View_0045ddb0_shapec03_game {
    uint32_t mVt0;
    uint32_t mVt1;
    uint8_t mFlag;
    uint8_t pad9[3];
    uint32_t mC;
    uint32_t mId;
    uint32_t pad14;
    uint32_t m18;
    uint8_t pad1c[0x1c];
    uint32_t m38;
    uint32_t m3c;
    uint32_t m40;
    void BaseInit() { mVt1 = 0xa80784; }
    View_0045ddb0_shapec03_game* Fn0045ddb0(uint32_t /*a*/);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0045ddb0 score 1
View_0045ddb0_shapec03_game* View_0045ddb0_shapec03_game::Fn0045ddb0(uint32_t /*a*/)
{
    BaseInit();
    mVt0 = 0xa878c0;
    mVt1 = 0xa878a4;
    mFlag = 0;
    mC = 0;
    mId = 0x49b9e602;
    m18 = 0;
    m38 = 0;
    m3c = 0;
    m40 = 0;
    return this;
}
#endif

struct View_0045e410_shapec03_game {
    uint32_t mVt0;
    uint32_t mVt1;
    uint8_t mFlag;
    uint8_t pad9[3];
    uint32_t mC;
    uint32_t mId;
    uint32_t pad14;
    uint32_t m18;
    uint8_t pad1c[0x1c];
    uint32_t m38;
    uint32_t m3c;
    uint32_t m40;
    void BaseInit() { mVt1 = 0xa80784; }
    View_0045e410_shapec03_game* Fn0045e410(uint32_t /*a*/);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0045e410 score 1
View_0045e410_shapec03_game* View_0045e410_shapec03_game::Fn0045e410(uint32_t /*a*/)
{
    BaseInit();
    mVt0 = 0xa879e0;
    mVt1 = 0xa879c4;
    mFlag = 0;
    mC = 0;
    mId = 0x49b9e605;
    m18 = 0;
    m38 = 0;
    m3c = 0;
    m40 = 0;
    return this;
}
#endif

struct View_0045f9b0_shapec03_game {
    uint32_t mVt0;
    uint32_t mVt1;
    uint8_t mFlag;
    uint8_t pad9[3];
    uint32_t mC;
    uint32_t mId;
    uint32_t pad14;
    uint32_t m18;
    uint8_t pad1c[0x1c];
    uint32_t m38;
    uint32_t m3c;
    uint32_t m40;
    void BaseInit() { mVt1 = 0xa80784; }
    View_0045f9b0_shapec03_game* Fn0045f9b0(uint32_t /*a*/);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0045f9b0 score 1
View_0045f9b0_shapec03_game* View_0045f9b0_shapec03_game::Fn0045f9b0(uint32_t /*a*/)
{
    BaseInit();
    mVt0 = 0xa87d40;
    mVt1 = 0xa87d24;
    mFlag = 0;
    mC = 0;
    mId = 0x49b9e604;
    m18 = 0;
    m38 = 0;
    m3c = 0;
    m40 = 0;
    return this;
}
#endif

struct Obj_00420e60_shapec03_game {
    uint32_t mVt0;
    uint32_t mVt1;
    uint32_t pad8;
    uint32_t mVt3;
    // STUB: 0x004085d0
    void Base();
};

// FUNCTION: 0x00420e60
Obj_00420e60_shapec03_game* Fn00420e60()
{
    Obj_00420e60_shapec03_game* p = static_cast<Obj_00420e60_shapec03_game*>(::operator new(0xc4));
    if (p) {
        p->Base();
        p->mVt0 = 0xa83be8;
        p->mVt1 = 0xa83bcc;
        p->mVt3 = 0xa83bb4;
        return p;
    }
    return 0;
}

struct Obj_004250c0_shapec03_game {
    uint32_t mVt0;
    uint32_t mVt1;
    uint32_t pad8;
    uint32_t mVt3;
    // STUB: 0x004085d0
    void Base();
};

// FUNCTION: 0x004250c0
Obj_004250c0_shapec03_game* Fn004250c0()
{
    Obj_004250c0_shapec03_game* p = static_cast<Obj_004250c0_shapec03_game*>(::operator new(0xc0));
    if (p) {
        p->Base();
        p->mVt0 = 0xa84b90;
        p->mVt1 = 0xa84b78;
        p->mVt3 = 0xa84b60;
        return p;
    }
    return 0;
}

struct Obj_0043ebd0_shapec03_game {
    uint32_t mVt0;
    uint32_t mVt1;
    uint32_t pad8;
    uint32_t mVt3;
    // STUB: 0x004085d0
    void Base();
};

// FUNCTION: 0x0043ebd0
Obj_0043ebd0_shapec03_game* Fn0043ebd0()
{
    Obj_0043ebd0_shapec03_game* p = static_cast<Obj_0043ebd0_shapec03_game*>(::operator new(0xc0));
    if (p) {
        p->Base();
        p->mVt0 = 0xa85ff8;
        p->mVt1 = 0xa85fe0;
        p->mVt3 = 0xa85fc8;
        return p;
    }
    return 0;
}

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct Node_00459ef0_shapec03_game {
    Node_00459ef0_shapec03_game* mpNext;
    Node_00459ef0_shapec03_game* mpPrev;
    uint8_t pad[0x14 - 8];
    void* mpData;
};

struct View_00459ef0_shapec03_game {
    Node_00459ef0_shapec03_game* mpHead;
    void Fn00459ef0();
};

// FUNCTION: 0x00459ef0
void View_00459ef0_shapec03_game::Fn00459ef0()
{
    Node_00459ef0_shapec03_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_00459ef0_shapec03_game* pCur = pNode;
        pNode = pNode->mpNext;
        if (pCur->mpData) {
            _STL::__stl_delete(pCur->mpData);
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

struct Node_004e9d60_shapec03_game {
    Node_004e9d60_shapec03_game* mpNext;
    Node_004e9d60_shapec03_game* mpPrev;
    uint8_t pad[0x18 - 8];
    void* mpData;
};

struct View_004e9d60_shapec03_game {
    Node_004e9d60_shapec03_game* mpHead;
    void Fn004e9d60();
};

// FUNCTION: 0x004e9d60
void View_004e9d60_shapec03_game::Fn004e9d60()
{
    Node_004e9d60_shapec03_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_004e9d60_shapec03_game* pCur = pNode;
        pNode = pNode->mpNext;
        if (pCur->mpData) {
            _STL::__stl_delete(pCur->mpData);
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

struct Node_0057caf0_shapec03_game {
    Node_0057caf0_shapec03_game* mpNext;
    Node_0057caf0_shapec03_game* mpPrev;
    uint8_t pad[0xc - 8];
    void* mpData;
};

struct View_0057caf0_shapec03_game {
    Node_0057caf0_shapec03_game* mpHead;
    void Fn0057caf0();
};

// FUNCTION: 0x0057caf0
void View_0057caf0_shapec03_game::Fn0057caf0()
{
    Node_0057caf0_shapec03_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_0057caf0_shapec03_game* pCur = pNode;
        pNode = pNode->mpNext;
        if (pCur->mpData) {
            _STL::__stl_delete(pCur->mpData);
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

struct View_005755b0_shapec03_game {
    uint8_t pad[0x30];
    float mMaxX;
    float mMaxY;
    bool Fn005755b0(float x, float y);
};

// FUNCTION: 0x005755b0
bool View_005755b0_shapec03_game::Fn005755b0(float x, float y)
{
    return x >= 0.0f && x <= mMaxX && y >= 0.0f && y <= mMaxY;
}

struct View_0074c610_shapec03_game {
    uint8_t pad[0x50];
    float mMaxX;
    float mMaxY;
    bool Fn0074c610(float x, float y);
};

// FUNCTION: 0x0074c610
bool View_0074c610_shapec03_game::Fn0074c610(float x, float y)
{
    return x >= 0.0f && x <= mMaxX && y >= 0.0f && y <= mMaxY;
}

struct View_00459470_shapec03_game {
    uint8_t pad[0x100];
    float mMaxX;
    float mMaxY;
    bool Fn00459470(float x, float y);
};

// FUNCTION: 0x00459470
bool View_00459470_shapec03_game::Fn00459470(float x, float y)
{
    return x >= 0.0f && x < mMaxX && y >= 0.0f && y < mMaxY;
}

struct Item_0042fe10_shapec03_game {
    virtual void Slot0(uint32_t n) = 0;
};

// STUB: 0x0042fdc0
uint8_t* Fn42fdc0_0042fe10(uint32_t a, uint8_t* pEnd, uint32_t b, uint32_t* pOut, uint32_t z);

struct View_0042fe10_shapec03_game {
    uint32_t pad0;
    uint8_t* mpEnd;
    uint32_t Fn0042fe10(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0042fe10 score 24
uint32_t View_0042fe10_shapec03_game::Fn0042fe10(uint32_t a, uint32_t b)
{
    uint8_t* pNew = Fn42fdc0_0042fe10(b, mpEnd, a, &a, 0);
    uint8_t* pEnd = mpEnd;
    for (uint8_t* p = pNew; p != pEnd; p += 0x30) {
        reinterpret_cast<Item_0042fe10_shapec03_game*>(p)->Slot0(0);
    }
    mpEnd = pNew;
    return a;
}
#endif

struct Item_005aac40_shapec03_game {
    virtual void Slot0(uint32_t n) = 0;
};

// STUB: 0x005a9d80
uint8_t* Fn5a9d80_005aac40(uint32_t a, uint8_t* pEnd, uint32_t b, uint32_t* pOut, uint32_t z);

struct View_005aac40_shapec03_game {
    uint32_t pad0;
    uint8_t* mpEnd;
    uint32_t Fn005aac40(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005aac40 score 24
uint32_t View_005aac40_shapec03_game::Fn005aac40(uint32_t a, uint32_t b)
{
    uint8_t* pNew = Fn5a9d80_005aac40(b, mpEnd, a, &a, 0);
    uint8_t* pEnd = mpEnd;
    for (uint8_t* p = pNew; p != pEnd; p += 0x40) {
        reinterpret_cast<Item_005aac40_shapec03_game*>(p)->Slot0(0);
    }
    mpEnd = pNew;
    return a;
}
#endif

struct Item_006bbb10_shapec03_game {
    virtual void Slot0(uint32_t n) = 0;
};

// STUB: 0x006ba220
uint8_t* Fn6ba220_006bbb10(uint32_t a, uint8_t* pEnd, uint32_t b, uint32_t* pOut, uint32_t z);

struct View_006bbb10_shapec03_game {
    uint32_t pad0;
    uint8_t* mpEnd;
    uint32_t Fn006bbb10(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006bbb10 score 24
uint32_t View_006bbb10_shapec03_game::Fn006bbb10(uint32_t a, uint32_t b)
{
    uint8_t* pNew = Fn6ba220_006bbb10(b, mpEnd, a, &a, 0);
    uint8_t* pEnd = mpEnd;
    for (uint8_t* p = pNew; p != pEnd; p += 0x20) {
        reinterpret_cast<Item_006bbb10_shapec03_game*>(p)->Slot0(0);
    }
    mpEnd = pNew;
    return a;
}
#endif

struct Obj_00413980_shapec03_game {
    uint32_t mVt0;
    uint32_t pad4;
    uint32_t mVt2;
    uint32_t mVt3;
    uint32_t mVt4;
    uint8_t pad14[0xac];
    uint8_t mFlag;
    // STUB: 0x0040fff0
    void Base();
};

// FUNCTION: 0x00413980
uint32_t* Fn00413980()
{
    Obj_00413980_shapec03_game* p = static_cast<Obj_00413980_shapec03_game*>(::operator new(0xc4));
    if (p) {
        p->Base();
        p->mVt0 = 0xa81d4c;
        p->mVt3 = 0xa81ce0;
        p->mVt4 = 0xa81cd0;
        p->mFlag = 0;
        p->mVt2 = 0xa81cf8;
        return &p->mVt2;
    }
    return 0;
}

struct Obj_00413d40_shapec03_game {
    uint32_t mVt0;
    uint32_t pad4;
    uint32_t mVt2;
    uint32_t mVt3;
    uint32_t mVt4;
    uint8_t pad14[0xac];
    uint8_t mFlag;
    // STUB: 0x0040fff0
    void Base();
};

// FUNCTION: 0x00413d40
uint32_t* Fn00413d40()
{
    Obj_00413d40_shapec03_game* p = static_cast<Obj_00413d40_shapec03_game*>(::operator new(0xc4));
    if (p) {
        p->Base();
        p->mVt0 = 0xa81fdc;
        p->mVt3 = 0xa81f70;
        p->mVt4 = 0xa81f60;
        p->mFlag = 0;
        p->mVt2 = 0xa81f88;
        return &p->mVt2;
    }
    return 0;
}

struct Obj_00420dd0_shapec03_game {
    uint32_t mVt0;
    uint32_t pad4;
    uint32_t mVt2;
    uint32_t mVt3;
    uint32_t mVt4;
    uint8_t pad14[0xac];
    uint8_t mFlag;
    // STUB: 0x0040fff0
    void Base();
};

// FUNCTION: 0x00420dd0
uint32_t* Fn00420dd0()
{
    Obj_00420dd0_shapec03_game* p = static_cast<Obj_00420dd0_shapec03_game*>(::operator new(0xc4));
    if (p) {
        p->Base();
        p->mVt0 = 0xa83b8c;
        p->mVt3 = 0xa83b20;
        p->mVt4 = 0xa83b10;
        p->mFlag = 0;
        p->mVt2 = 0xa83b38;
        return &p->mVt2;
    }
    return 0;
}

struct Ref_00437b20_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Release() = 0;
};

struct View_00437b20_shapec03_game {
    uint32_t mVt;
    uint8_t pad4[36];
    Ref_00437b20_shapec03_game* mp0x28;
    Ref_00437b20_shapec03_game* mp0x2c;
    uint8_t pad30[4];
    Ref_00437b20_shapec03_game* mp0x34;
    Ref_00437b20_shapec03_game* mp0x38;
    Ref_00437b20_shapec03_game* mp0x3c;
    Ref_00437b20_shapec03_game* mp0x40;
    // STUB: 0x005fafc0
    void Base();
    void Fn00437b20();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00437b20 score 2
void View_00437b20_shapec03_game::Fn00437b20()
{
    mVt = 0xa85800;
    if (mp0x40) {
        mp0x40->Release();
    }
    if (mp0x3c) {
        mp0x3c->Release();
    }
    if (mp0x38) {
        mp0x38->Release();
    }
    if (mp0x34) {
        mp0x34->Release();
    }
    if (mp0x2c) {
        mp0x2c->Release();
    }
    if (mp0x28) {
        mp0x28->Release();
    }
    Base();
}
#endif

struct Ref_00438770_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Release() = 0;
};

struct View_00438770_shapec03_game {
    uint32_t mVt;
    uint8_t pad4[36];
    Ref_00438770_shapec03_game* mp0x28;
    Ref_00438770_shapec03_game* mp0x2c;
    uint8_t pad30[4];
    Ref_00438770_shapec03_game* mp0x34;
    Ref_00438770_shapec03_game* mp0x38;
    Ref_00438770_shapec03_game* mp0x3c;
    Ref_00438770_shapec03_game* mp0x40;
    // STUB: 0x005fafc0
    void Base();
    void Fn00438770();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00438770 score 2
void View_00438770_shapec03_game::Fn00438770()
{
    mVt = 0xa858d0;
    if (mp0x40) {
        mp0x40->Release();
    }
    if (mp0x3c) {
        mp0x3c->Release();
    }
    if (mp0x38) {
        mp0x38->Release();
    }
    if (mp0x34) {
        mp0x34->Release();
    }
    if (mp0x2c) {
        mp0x2c->Release();
    }
    if (mp0x28) {
        mp0x28->Release();
    }
    Base();
}
#endif

struct Ref_00439ff0_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Release() = 0;
};

struct View_00439ff0_shapec03_game {
    uint32_t mVt;
    uint8_t pad4[36];
    Ref_00439ff0_shapec03_game* mp0x28;
    Ref_00439ff0_shapec03_game* mp0x2c;
    uint8_t pad30[4];
    Ref_00439ff0_shapec03_game* mp0x34;
    Ref_00439ff0_shapec03_game* mp0x38;
    Ref_00439ff0_shapec03_game* mp0x3c;
    Ref_00439ff0_shapec03_game* mp0x40;
    // STUB: 0x005fafc0
    void Base();
    void Fn00439ff0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00439ff0 score 2
void View_00439ff0_shapec03_game::Fn00439ff0()
{
    mVt = 0xa85a20;
    if (mp0x40) {
        mp0x40->Release();
    }
    if (mp0x3c) {
        mp0x3c->Release();
    }
    if (mp0x38) {
        mp0x38->Release();
    }
    if (mp0x34) {
        mp0x34->Release();
    }
    if (mp0x2c) {
        mp0x2c->Release();
    }
    if (mp0x28) {
        mp0x28->Release();
    }
    Base();
}
#endif

struct Item_00586cf0_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
};

// FUNCTION: 0x00586cf0
Item_00586cf0_shapec03_game** Fn00586cf0(Item_00586cf0_shapec03_game** pFirst, Item_00586cf0_shapec03_game** pLast, Item_00586cf0_shapec03_game** pDest)
{
    int32_t n = static_cast<int32_t>(pLast - pFirst);
    for (; n > 0; --n) {
        --pLast;
        --pDest;
        if (pLast != pDest) {
            Item_00586cf0_shapec03_game* pNew = *pLast;
            Item_00586cf0_shapec03_game* pOld = *pDest;
            if (pNew != pOld) {
                if (pNew) {
                    pNew->Slot4();
                }
                *pDest = pNew;
                if (pOld) {
                    pOld->Slot5();
                }
            }
        }
    }
    return pDest;
}

struct Item_00586e90_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
};

// FUNCTION: 0x00586e90
Item_00586e90_shapec03_game** Fn00586e90(Item_00586e90_shapec03_game** pFirst, Item_00586e90_shapec03_game** pLast, Item_00586e90_shapec03_game** pDest)
{
    int32_t n = static_cast<int32_t>(pLast - pFirst);
    for (; n > 0; --n) {
        --pLast;
        --pDest;
        if (pLast != pDest) {
            Item_00586e90_shapec03_game* pNew = *pLast;
            Item_00586e90_shapec03_game* pOld = *pDest;
            if (pNew != pOld) {
                if (pNew) {
                    pNew->Slot2();
                }
                *pDest = pNew;
                if (pOld) {
                    pOld->Slot1();
                }
            }
        }
    }
    return pDest;
}

struct OB_NOVTABLE Svc_shapec03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void S4() = 0;
    virtual void GetService(uint32_t id, uint32_t iid, void** ppOut) = 0;
};

struct OB_NOVTABLE Alloc_shapec03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void S2() = 0;
    virtual void S3() = 0;
    virtual void Deallocate(void* p) = 0;
};

struct OB_NOVTABLE Data_shapec03_game {
    virtual void S0() = 0;
    virtual void S1() = 0;
    virtual void Release() = 0;
};

struct Ref_shapec03_game {
    Alloc_shapec03_game* mpService;
    // STUB: 0x00411870
    void Release();
};

// STUB: 0x008793ec
Svc_shapec03_game* Fn008793ec();

struct Node_shapec03_game {
    Node_shapec03_game* mpNext;
    Node_shapec03_game* mpPrev;
    Data_shapec03_game* mpData;
};

// GLOBAL: 0x00b20d58
extern Alloc_shapec03_game* gpb20d58_004216e0;

#ifdef OB_DRAFTS
// CLOSE: 0x004216e0 score 4
void OB_STDCALL Fn004216e0(Node_shapec03_game** ppOut, Node_shapec03_game* pNode)
{
    Node_shapec03_game* pPrev = pNode->mpPrev;
    Node_shapec03_game* pNext = pNode->mpNext;
    pPrev->mpNext = pNext;
    pNext->mpPrev = pPrev;
    Data_shapec03_game* pData = pNode->mpData;
    if (pData) {
        pData->Release();
    }
    if (!gpb20d58_004216e0) {
        Ref_shapec03_game ref;
        ref.mpService = 0;
        Svc_shapec03_game* pSvc = Fn008793ec();
        if (pSvc) {
            pSvc->GetService(0x3ae4bea3, 0x3ae4beab, reinterpret_cast<void**>(&ref.mpService));
        }
        gpb20d58_004216e0 = ref.mpService;
        ref.Release();
    }
    gpb20d58_004216e0->Deallocate(pNode);
    *ppOut = pNext;
}
#endif

// GLOBAL: 0x00b207dc
extern Alloc_shapec03_game* gpb207dc_0041c000;

#ifdef OB_DRAFTS
// CLOSE: 0x0041c000 score 4
void OB_STDCALL Fn0041c000(Node_shapec03_game** ppOut, Node_shapec03_game* pNode)
{
    Node_shapec03_game* pPrev = pNode->mpPrev;
    Node_shapec03_game* pNext = pNode->mpNext;
    pPrev->mpNext = pNext;
    pNext->mpPrev = pPrev;
    Data_shapec03_game* pData = pNode->mpData;
    if (pData) {
        pData->Release();
    }
    if (!gpb207dc_0041c000) {
        Ref_shapec03_game ref;
        ref.mpService = 0;
        Svc_shapec03_game* pSvc = Fn008793ec();
        if (pSvc) {
            pSvc->GetService(0x3ae4bea3, 0x3ae4beab, reinterpret_cast<void**>(&ref.mpService));
        }
        gpb207dc_0041c000 = ref.mpService;
        ref.Release();
    }
    gpb207dc_0041c000->Deallocate(pNode);
    *ppOut = pNext;
}
#endif

// GLOBAL: 0x00b207e0
extern Alloc_shapec03_game* gpb207e0_004a4a50;

#ifdef OB_DRAFTS
// CLOSE: 0x004a4a50 score 4
void OB_STDCALL Fn004a4a50(Node_shapec03_game** ppOut, Node_shapec03_game* pNode)
{
    Node_shapec03_game* pPrev = pNode->mpPrev;
    Node_shapec03_game* pNext = pNode->mpNext;
    pPrev->mpNext = pNext;
    pNext->mpPrev = pPrev;
    Data_shapec03_game* pData = pNode->mpData;
    if (pData) {
        pData->Release();
    }
    if (!gpb207e0_004a4a50) {
        Ref_shapec03_game ref;
        ref.mpService = 0;
        Svc_shapec03_game* pSvc = Fn008793ec();
        if (pSvc) {
            pSvc->GetService(0x3ae4bea3, 0x3ae4beab, reinterpret_cast<void**>(&ref.mpService));
        }
        gpb207e0_004a4a50 = ref.mpService;
        ref.Release();
    }
    gpb207e0_004a4a50->Deallocate(pNode);
    *ppOut = pNext;
}
#endif

// GLOBAL: 0x00b207dc
extern Alloc_shapec03_game* gpb207dc_00411d70;

struct View_00411d70_shapec03_game {
    Node_shapec03_game* mpHead;
    void Fn00411d70();
};

// FUNCTION: 0x00411d70
void View_00411d70_shapec03_game::Fn00411d70()
{
    Node_shapec03_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_shapec03_game* pCur = pNode;
        pNode = pNode->mpNext;
        Data_shapec03_game* pData = pCur->mpData;
        if (pData) {
            pData->Release();
        }
    if (!gpb207dc_00411d70) {
        Ref_shapec03_game ref;
        ref.mpService = 0;
        Svc_shapec03_game* pSvc = Fn008793ec();
        if (pSvc) {
            pSvc->GetService(0x3ae4bea3, 0x3ae4beab, reinterpret_cast<void**>(&ref.mpService));
        }
        gpb207dc_00411d70 = ref.mpService;
        ref.Release();
    }
        gpb207dc_00411d70->Deallocate(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

// GLOBAL: 0x00b207e0
extern Alloc_shapec03_game* gpb207e0_00411df0;

struct View_00411df0_shapec03_game {
    Node_shapec03_game* mpHead;
    void Fn00411df0();
};

// FUNCTION: 0x00411df0
void View_00411df0_shapec03_game::Fn00411df0()
{
    Node_shapec03_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_shapec03_game* pCur = pNode;
        pNode = pNode->mpNext;
        Data_shapec03_game* pData = pCur->mpData;
        if (pData) {
            pData->Release();
        }
    if (!gpb207e0_00411df0) {
        Ref_shapec03_game ref;
        ref.mpService = 0;
        Svc_shapec03_game* pSvc = Fn008793ec();
        if (pSvc) {
            pSvc->GetService(0x3ae4bea3, 0x3ae4beab, reinterpret_cast<void**>(&ref.mpService));
        }
        gpb207e0_00411df0 = ref.mpService;
        ref.Release();
    }
        gpb207e0_00411df0->Deallocate(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

// GLOBAL: 0x00b20d58
extern Alloc_shapec03_game* gpb20d58_00421660;

struct View_00421660_shapec03_game {
    Node_shapec03_game* mpHead;
    void Fn00421660();
};

// FUNCTION: 0x00421660
void View_00421660_shapec03_game::Fn00421660()
{
    Node_shapec03_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_shapec03_game* pCur = pNode;
        pNode = pNode->mpNext;
        Data_shapec03_game* pData = pCur->mpData;
        if (pData) {
            pData->Release();
        }
    if (!gpb20d58_00421660) {
        Ref_shapec03_game ref;
        ref.mpService = 0;
        Svc_shapec03_game* pSvc = Fn008793ec();
        if (pSvc) {
            pSvc->GetService(0x3ae4bea3, 0x3ae4beab, reinterpret_cast<void**>(&ref.mpService));
        }
        gpb20d58_00421660 = ref.mpService;
        ref.Release();
    }
        gpb20d58_00421660->Deallocate(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

namespace _STL {
    // STUB: 0x0090cf54
    void* __stl_new(unsigned int n);
}

struct Item_00430a90_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
};

// STUB: 0x0042e4c0
Item_00430a90_shapec03_game** Cp42e4c0_00430a90(Item_00430a90_shapec03_game** pFirst, Item_00430a90_shapec03_game** pLast, Item_00430a90_shapec03_game** pDest, bool* pFlag);

// STUB: 0x0058df60
Item_00430a90_shapec03_game** Fl58df60_00430a90(Item_00430a90_shapec03_game** pDest, uint32_t n, Item_00430a90_shapec03_game** pValue, bool* pFlag);

struct View_00430a90_shapec03_game {
    Item_00430a90_shapec03_game** mpBegin;
    Item_00430a90_shapec03_game** mpEnd;
    Item_00430a90_shapec03_game** mpCap;
    // STUB: 0x006c6e90
    void Base();
    void Fn00430a90(Item_00430a90_shapec03_game** pPos, Item_00430a90_shapec03_game** pValue, uint32_t /*unused*/, uint32_t n, bool bFlag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00430a90 score 19
void View_00430a90_shapec03_game::Fn00430a90(Item_00430a90_shapec03_game** pPos, Item_00430a90_shapec03_game** pValue, uint32_t /*unused*/, uint32_t n, bool bFlag)
{
    Item_00430a90_shapec03_game** pOldBegin = mpBegin;
    uint32_t nOld = static_cast<uint32_t>(mpEnd - pOldBegin);
    const uint32_t* pMax = (nOld < n) ? &n : &nOld;
    uint32_t nNew = *pMax + nOld;
    Item_00430a90_shapec03_game** pNewBegin = nNew != 0 ? static_cast<Item_00430a90_shapec03_game**>(_STL::__stl_new(nNew * 4)) : 0;
    Item_00430a90_shapec03_game** pNewEnd = Cp42e4c0_00430a90(pOldBegin, pPos, pNewBegin, &bFlag);
    if (n == 1) {
        if (pNewEnd) {
            Item_00430a90_shapec03_game* pItem = *pValue;
            *pNewEnd = pItem;
            if (pItem) {
                pItem->Slot1();
            }
        }
        pNewEnd = pNewEnd + 1;
    } else {
        pNewEnd = Fl58df60_00430a90(pNewEnd, n, pValue, &bFlag);
    }
    if (!bFlag) {
        pNewEnd = Cp42e4c0_00430a90(pPos, mpEnd, pNewEnd, &bFlag);
    }
    Base();
    mpBegin = pNewBegin;
    mpEnd = pNewEnd;
    mpCap = pNewBegin + nNew;
}
#endif

struct Item_005880c0_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
};

// STUB: 0x00586b70
Item_005880c0_shapec03_game** Cp586b70_005880c0(Item_005880c0_shapec03_game** pFirst, Item_005880c0_shapec03_game** pLast, Item_005880c0_shapec03_game** pDest, bool* pFlag);

// STUB: 0x00586bb0
Item_005880c0_shapec03_game** Fl586bb0_005880c0(Item_005880c0_shapec03_game** pDest, uint32_t n, Item_005880c0_shapec03_game** pValue, bool* pFlag);

struct View_005880c0_shapec03_game {
    Item_005880c0_shapec03_game** mpBegin;
    Item_005880c0_shapec03_game** mpEnd;
    Item_005880c0_shapec03_game** mpCap;
    // STUB: 0x00587810
    void Base();
    void Fn005880c0(Item_005880c0_shapec03_game** pPos, Item_005880c0_shapec03_game** pValue, uint32_t /*unused*/, uint32_t n, bool bFlag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005880c0 score 19
void View_005880c0_shapec03_game::Fn005880c0(Item_005880c0_shapec03_game** pPos, Item_005880c0_shapec03_game** pValue, uint32_t /*unused*/, uint32_t n, bool bFlag)
{
    Item_005880c0_shapec03_game** pOldBegin = mpBegin;
    uint32_t nOld = static_cast<uint32_t>(mpEnd - pOldBegin);
    const uint32_t* pMax = (nOld < n) ? &n : &nOld;
    uint32_t nNew = *pMax + nOld;
    Item_005880c0_shapec03_game** pNewBegin = nNew != 0 ? static_cast<Item_005880c0_shapec03_game**>(_STL::__stl_new(nNew * 4)) : 0;
    Item_005880c0_shapec03_game** pNewEnd = Cp586b70_005880c0(pOldBegin, pPos, pNewBegin, &bFlag);
    if (n == 1) {
        if (pNewEnd) {
            Item_005880c0_shapec03_game* pItem = *pValue;
            *pNewEnd = pItem;
            if (pItem) {
                pItem->Slot4();
            }
        }
        pNewEnd = pNewEnd + 1;
    } else {
        pNewEnd = Fl586bb0_005880c0(pNewEnd, n, pValue, &bFlag);
    }
    if (!bFlag) {
        pNewEnd = Cp586b70_005880c0(pPos, mpEnd, pNewEnd, &bFlag);
    }
    Base();
    mpBegin = pNewBegin;
    mpEnd = pNewEnd;
    mpCap = pNewBegin + nNew;
}
#endif

struct Item_00588260_shapec03_game {
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
};

// STUB: 0x00586c70
Item_00588260_shapec03_game** Cp586c70_00588260(Item_00588260_shapec03_game** pFirst, Item_00588260_shapec03_game** pLast, Item_00588260_shapec03_game** pDest, bool* pFlag);

// STUB: 0x00586cb0
Item_00588260_shapec03_game** Fl586cb0_00588260(Item_00588260_shapec03_game** pDest, uint32_t n, Item_00588260_shapec03_game** pValue, bool* pFlag);

struct View_00588260_shapec03_game {
    Item_00588260_shapec03_game** mpBegin;
    Item_00588260_shapec03_game** mpEnd;
    Item_00588260_shapec03_game** mpCap;
    // STUB: 0x005877d0
    void Base();
    void Fn00588260(Item_00588260_shapec03_game** pPos, Item_00588260_shapec03_game** pValue, uint32_t /*unused*/, uint32_t n, bool bFlag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00588260 score 19
void View_00588260_shapec03_game::Fn00588260(Item_00588260_shapec03_game** pPos, Item_00588260_shapec03_game** pValue, uint32_t /*unused*/, uint32_t n, bool bFlag)
{
    Item_00588260_shapec03_game** pOldBegin = mpBegin;
    uint32_t nOld = static_cast<uint32_t>(mpEnd - pOldBegin);
    const uint32_t* pMax = (nOld < n) ? &n : &nOld;
    uint32_t nNew = *pMax + nOld;
    Item_00588260_shapec03_game** pNewBegin = nNew != 0 ? static_cast<Item_00588260_shapec03_game**>(_STL::__stl_new(nNew * 4)) : 0;
    Item_00588260_shapec03_game** pNewEnd = Cp586c70_00588260(pOldBegin, pPos, pNewBegin, &bFlag);
    if (n == 1) {
        if (pNewEnd) {
            Item_00588260_shapec03_game* pItem = *pValue;
            *pNewEnd = pItem;
            if (pItem) {
                pItem->Slot2();
            }
        }
        pNewEnd = pNewEnd + 1;
    } else {
        pNewEnd = Fl586cb0_00588260(pNewEnd, n, pValue, &bFlag);
    }
    if (!bFlag) {
        pNewEnd = Cp586c70_00588260(pPos, mpEnd, pNewEnd, &bFlag);
    }
    Base();
    mpBegin = pNewBegin;
    mpEnd = pNewEnd;
    mpCap = pNewBegin + nNew;
}
#endif
