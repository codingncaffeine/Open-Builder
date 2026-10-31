// Shape families of packet shaped01_game (pairs written by hand).
#include "common/types.h"
#include <stdio.h>

// A generic object with virtual slots, used only through pointers (never constructed here).
struct Obj_shaped01_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05(uint32_t a) = 0;
    virtual void Slot06() = 0;
    virtual void Slot07(uint32_t a) = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12(uint32_t a) = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual bool Slot18() = 0;
};

// ---- flag byte tests
struct View_a87320_shaped01_game {
    uint8_t pad[0x55];
    uint8_t mbFlags;
    uint32_t Fn00458870();
};

// FUNCTION: 0x00458870
uint32_t View_a87320_shaped01_game::Fn00458870()
{
    return mbFlags & 1;
}

struct View_604dc0_shaped01_game {
    uint8_t pad[0x104];
    uint8_t mbFlags;
    uint32_t Fn00604dc0();
};

// FUNCTION: 0x00604dc0
uint32_t View_604dc0_shaped01_game::Fn00604dc0()
{
    return mbFlags & 0x7f;
}

// ---- store of a dereferenced argument
struct View_458820_shaped01_game {
    uint8_t pad[0x58];
    uint32_t mnValue;
    void Fn00458820(const uint32_t* pValue);
};

// FUNCTION: 0x00458820
void View_458820_shaped01_game::Fn00458820(const uint32_t* pValue)
{
    mnValue = *pValue;
}

struct View_6a9760_shaped01_game {
    uint8_t pad[0x38];
    uint32_t mnValue;
    void Fn006a9760(const uint32_t* pValue);
};

// FUNCTION: 0x006a9760
void View_6a9760_shaped01_game::Fn006a9760(const uint32_t* pValue)
{
    mnValue = *pValue;
}

// ---- nonzero test
struct View_5773f0_shaped01_game {
    uint8_t pad[0x40];
    uint32_t mnValue;
    uint32_t Fn005773f0();
};

// FUNCTION: 0x005773f0
uint32_t View_5773f0_shaped01_game::Fn005773f0()
{
    return 0 < mnValue;
}

struct View_459920_shaped01_game {
    uint8_t pad[0xf8];
    uint32_t mnValue;
    uint32_t Fn00459920();
};

// FUNCTION: 0x00459920
uint32_t View_459920_shaped01_game::Fn00459920()
{
    return 0 < mnValue;
}

// ---- table lookup
struct View_497740_shaped01_game {
    uint8_t pad[0x14];
    uint32_t* mpTable;
    uint32_t Fn00497740(uint32_t nIndex);
};

// FUNCTION: 0x00497740
uint32_t View_497740_shaped01_game::Fn00497740(uint32_t nIndex)
{
    return mpTable[nIndex];
}

struct View_418c30_shaped01_game {
    uint8_t pad[0x80];
    uint32_t* mpTable;
    uint32_t Fn00418c30(uint32_t nIndex);
};

// FUNCTION: 0x00418c30
uint32_t View_418c30_shaped01_game::Fn00418c30(uint32_t nIndex)
{
    return mpTable[nIndex];
}

// ---- the 24-hour clock
struct Clock_a86490_shaped01_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual uint32_t Slot10() = 0;
    virtual void Slot11() = 0;
    virtual uint32_t Slot12() = 0;
    virtual uint32_t Slot13() = 0;
    virtual void Slot14() = 0;
    virtual uint32_t Slot15() = 0;
    uint8_t pad[0x40];
    uint32_t mnTime;
    uint32_t mnVisualTime;
    uint32_t Fn00444ec0();
    uint32_t Fn00444ed0();
    uint32_t Fn00444ee0();
    uint32_t Fn00444f10();
    uint32_t Fn00444f80();
    uint32_t Fn00444fb0();
};

// FUNCTION: 0x00444ec0
uint32_t Clock_a86490_shaped01_game::Fn00444ec0()
{
    return mnTime / 3600;
}

// FUNCTION: 0x00444ed0
uint32_t Clock_a86490_shaped01_game::Fn00444ed0()
{
    return mnVisualTime / 3600;
}

// FUNCTION: 0x00444ee0
uint32_t Clock_a86490_shaped01_game::Fn00444ee0()
{
    return (mnTime - Slot10() * 3600) / 60;
}

// FUNCTION: 0x00444f10
uint32_t Clock_a86490_shaped01_game::Fn00444f10()
{
    return (mnVisualTime - Slot12() * 3600) / 60;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00444f80 score 11
uint32_t Clock_a86490_shaped01_game::Fn00444f80()
{
    uint32_t nHours = Slot10();
    uint32_t nMinutes = nHours * 60 + Slot13();
    return mnTime - nMinutes * 60;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00444fb0 score 11
uint32_t Clock_a86490_shaped01_game::Fn00444fb0()
{
    uint32_t nHours = Slot12();
    uint32_t nMinutes = nHours * 60 + Slot15();
    return mnVisualTime - nMinutes * 60;
}
#endif

// ---- float or the default
// GLOBAL: 0x00a81054
extern const float gfA81054;

struct View_a81058_shaped01_game {
    uint8_t pad4[4];
    uint8_t mbSet;
    uint8_t pad5[3];
    float mfX;
    float mfY;
    float Fn0040ce10();
    float Fn0040ce30();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0040ce10 score 2
float View_a81058_shaped01_game::Fn0040ce10()
{
    if (mbSet) {
        return mfX;
    }
    return gfA81054;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0040ce30 score 2
float View_a81058_shaped01_game::Fn0040ce30()
{
    if (mbSet) {
        return mfY;
    }
    return gfA81054;
}
#endif

// ---- decrement a counter that stays at zero
struct View_a873c0_shaped01_game {
    uint8_t pad[0xf8];
    uint32_t mnLockA;
    uint32_t mnLockB;
    void Fn004598f0();
    void Fn00459940();
};

// FUNCTION: 0x004598f0
void View_a873c0_shaped01_game::Fn004598f0()
{
    if (mnLockA > 0) {
        --mnLockA;
    }
}

// FUNCTION: 0x00459940
void View_a873c0_shaped01_game::Fn00459940()
{
    if (mnLockB > 0) {
        --mnLockB;
    }
}

// ---- Init: set the id, then the base Init
struct View_cInput_shaped01_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08(uint32_t nId) = 0;
    // STUB: 0x005fb1d0
    bool Fn005fb1d0();
    bool Fn00439f80();
    bool Fn0043e740();
};

// FUNCTION: 0x00439f80
bool View_cInput_shaped01_game::Fn00439f80()
{
    Slot08(0x43401c71);
    return Fn005fb1d0();
}

// FUNCTION: 0x0043e740
bool View_cInput_shaped01_game::Fn0043e740()
{
    Slot08(0xebf9c962);
    return Fn005fb1d0();
}

// ---- call a slot of the argument, return it
// FUNCTION: 0x0040cef0
Obj_shaped01_game* Fn0040cef0(Obj_shaped01_game* pObj, uint32_t nValue)
{
    pObj->Slot12(nValue);
    return pObj;
}

// FUNCTION: 0x005d9fd0
Obj_shaped01_game* Fn005d9fd0(Obj_shaped01_game* pObj, uint32_t nValue)
{
    pObj->Slot05(nValue);
    return pObj;
}

// ---- call the sibling, then ask the argument
struct View_a80784_shaped01_game {
    // STUB: 0x004251a0
    bool Fn004251a0(void* pObj);
    // STUB: 0x00425490
    bool Fn00425490(void* pObj);
    bool Fn0043d1b0(Obj_shaped01_game* pObj);
    bool Fn0043d1d0(Obj_shaped01_game* pObj);
};

// FUNCTION: 0x0043d1b0
bool View_a80784_shaped01_game::Fn0043d1b0(Obj_shaped01_game* pObj)
{
    Fn004251a0(pObj);
    return !pObj->Slot18();
}

// FUNCTION: 0x0043d1d0
bool View_a80784_shaped01_game::Fn0043d1d0(Obj_shaped01_game* pObj)
{
    Fn00425490(pObj);
    return !pObj->Slot18();
}

// ---- Write: one slot with a constant, then ask
struct View_cWrite_shaped01_game {
    uint32_t Fn0042e440(Obj_shaped01_game* pStream);
    uint32_t Fn005e97c0(Obj_shaped01_game* pStream);
};

// FUNCTION: 0x0042e440
uint32_t View_cWrite_shaped01_game::Fn0042e440(Obj_shaped01_game* pStream)
{
    pStream->Slot07(1);
    return !pStream->Slot18();
}

// FUNCTION: 0x005e97c0
uint32_t View_cWrite_shaped01_game::Fn005e97c0(Obj_shaped01_game* pStream)
{
    pStream->Slot07(3);
    return !pStream->Slot18();
}

// ---- Release with the count floored at one
struct Sub_shaped01_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03(uint32_t a) = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22(uint32_t a) = 0;
};

struct View_447e40_shaped01_game {
    uint8_t pad[0x10];
    uint8_t* mpSub;
    uint8_t pad2[0x14];
    uint32_t mnRefs;
    uint32_t Fn00447e40();
};

// FUNCTION: 0x00447e40
uint32_t View_447e40_shaped01_game::Fn00447e40()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    reinterpret_cast<Sub_shaped01_game*>(&mpSub)->Slot03(1);
    return 0;
}

struct View_6bfe40_shaped01_game {
    uint8_t pad[0x8];
    uint8_t* mpSub;
    uint32_t mnRefs;
    uint32_t Fn006bfe40();
};

// FUNCTION: 0x006bfe40
uint32_t View_6bfe40_shaped01_game::Fn006bfe40()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    reinterpret_cast<Sub_shaped01_game*>(&mpSub)->Slot22(1);
    return 0;
}

// ---- float compare
struct View_cmp_shaped01_game {
    float mfValue;
    uint32_t Fn00437ad0(const float* pOther);
    uint32_t Fn004c3730(const float* pOther);
};

// FUNCTION: 0x00437ad0
uint32_t View_cmp_shaped01_game::Fn00437ad0(const float* pOther)
{
    if (mfValue >= *pOther) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x004c3730
uint32_t View_cmp_shaped01_game::Fn004c3730(const float* pOther)
{
    if (mfValue > *pOther) {
        return 1;
    }
    return 0;
}

// ---- Release with the count floored at one, a virtual call first
struct View_a86490r_shaped01_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    uint8_t pad[0xc];
    uint8_t* mpSub;
    uint8_t pad2[0x18];
    uint32_t mnRefs;
    uint32_t Fn004451f0();
};

// FUNCTION: 0x004451f0
uint32_t View_a86490r_shaped01_game::Fn004451f0()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Slot04();
    reinterpret_cast<Sub_shaped01_game*>(&mpSub)->Slot03(1);
    return 0;
}

struct View_a873c0r_shaped01_game {
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    uint8_t pad[0x8];
    uint8_t* mpSub;
    uint8_t pad2[0x10];
    uint32_t mnRefs;
    uint32_t Fn004599b0();
};

// FUNCTION: 0x004599b0
uint32_t View_a873c0r_shaped01_game::Fn004599b0()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Slot04();
    reinterpret_cast<Sub_shaped01_game*>(&mpSub)->Slot22(1);
    return 0;
}

// ---- clamp an orientation to 0..3
struct View_a87320o_shaped01_game {
    uint8_t pad[0x54];
    uint8_t mnOrientation;
    bool Fn00458840(int32_t nOrientation);
};

// FUNCTION: 0x00458840
bool View_a87320o_shaped01_game::Fn00458840(int32_t nOrientation)
{
    if (nOrientation < 0) {
        nOrientation = 0;
    } else if (nOrientation > 3) {
        nOrientation = 3;
    }
    mnOrientation = static_cast<uint8_t>(nOrientation);
    return true;
}

struct View_aa29d4_shaped01_game {
    uint8_t pad[0x59];
    uint8_t mnOrientation;
    bool Fn005d61a0(int32_t nOrientation);
};

// FUNCTION: 0x005d61a0
bool View_aa29d4_shaped01_game::Fn005d61a0(int32_t nOrientation)
{
    if (nOrientation < 0) {
        nOrientation = 0;
    } else if (nOrientation > 3) {
        nOrientation = 3;
    }
    mnOrientation = static_cast<uint8_t>(nOrientation);
    return true;
}

// ---- zone type to density
// FUNCTION: 0x00458960
uint32_t Fn00458960(uint32_t nType)
{
    switch (nType) {
    case 1:
    case 4:
        return 1;
    case 2:
    case 5:
        return 2;
    case 3:
    case 6:
    case 7:
    case 8:
    case 9:
        return 3;
    }
    return 0;
}

// FUNCTION: 0x006b3890
uint32_t Fn006b3890(uint32_t nType)
{
    switch (nType) {
    case 1:
    case 2:
    case 3:
        return 1;
    case 4:
    case 5:
    case 6:
        return 2;
    case 7:
    case 8:
    case 9:
        return 3;
    }
    return 0;
}

// ---- red-black tree rotations
struct Node_shaped01_game {
    uint32_t mnColor;
    Node_shaped01_game* mpParent;
    Node_shaped01_game* mpLeft;
    Node_shaped01_game* mpRight;
};

// FUNCTION: 0x0040d540
void Fn0040d540(Node_shaped01_game* pNode, Node_shaped01_game** ppRoot)
{
    Node_shaped01_game* pChild = pNode->mpRight;
    pNode->mpRight = pChild->mpLeft;
    if (pChild->mpLeft) {
        pChild->mpLeft->mpParent = pNode;
    }
    pChild->mpParent = pNode->mpParent;
    if (pNode == *ppRoot) {
        *ppRoot = pChild;
    } else if (pNode == pNode->mpParent->mpLeft) {
        pNode->mpParent->mpLeft = pChild;
    } else {
        pNode->mpParent->mpRight = pChild;
    }
    pChild->mpLeft = pNode;
    pNode->mpParent = pChild;
}

// FUNCTION: 0x0040d590
void Fn0040d590(Node_shaped01_game* pNode, Node_shaped01_game** ppRoot)
{
    Node_shaped01_game* pChild = pNode->mpLeft;
    pNode->mpLeft = pChild->mpRight;
    if (pChild->mpRight) {
        pChild->mpRight->mpParent = pNode;
    }
    pChild->mpParent = pNode->mpParent;
    if (pNode == *ppRoot) {
        *ppRoot = pChild;
    } else if (pNode == pNode->mpParent->mpRight) {
        pNode->mpParent->mpRight = pChild;
    } else {
        pNode->mpParent->mpLeft = pChild;
    }
    pChild->mpRight = pNode;
    pNode->mpParent = pChild;
}

// ---- vector destructor
namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

// STUB: 0x00459170
void Fn00459170(void* pFirst, void* pLast, char* pTag);
// STUB: 0x007cf620
void Fn007cf620(void* pFirst, void* pLast, char* pTag);

struct View_459220_shaped01_game {
    uint8_t pad[0xc];
    void* mpFirst;
    void* mpLast;
    void Fn00459220();
};

// FUNCTION: 0x00459220
void View_459220_shaped01_game::Fn00459220()
{
    char cTag;
    Fn00459170(mpFirst, mpLast, &cTag);
    if (mpFirst) {
        _STL::__stl_delete(mpFirst);
    }
}

struct View_7d01c0_shaped01_game {
    uint8_t pad[0x4];
    void* mpFirst;
    void* mpLast;
    void Fn007d01c0();
};

// FUNCTION: 0x007d01c0
void View_7d01c0_shaped01_game::Fn007d01c0()
{
    char cTag;
    Fn007cf620(mpFirst, mpLast, &cTag);
    if (mpFirst) {
        _STL::__stl_delete(mpFirst);
    }
}

// ---- remove a value from a ring list
struct ListNode_shaped01_game {
    ListNode_shaped01_game* mpNext;
    ListNode_shaped01_game* mpPrev;
    Obj_shaped01_game* mpValue;
};

struct View_41d9b0_shaped01_game {
    uint8_t pad[0x60];
    ListNode_shaped01_game* mpHead;
    void Fn0041d9b0(Obj_shaped01_game* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0041d9b0 score 8
void View_41d9b0_shaped01_game::Fn0041d9b0(Obj_shaped01_game* pValue)
{
    ListNode_shaped01_game* pHead = mpHead;
    for (ListNode_shaped01_game* pNode = pHead->mpNext; pNode != pHead; pNode = pNode->mpNext) {
        if (pNode->mpValue == pValue) {
            ListNode_shaped01_game* pPrev = pNode->mpPrev;
            ListNode_shaped01_game* pNext = pNode->mpNext;
            pPrev->mpNext = pNext;
            pNext->mpPrev = pPrev;
            Obj_shaped01_game* pObj = pNode->mpValue;
            if (pObj) {
                pObj->Slot02();
            }
            _STL::__stl_delete(pNode);
            return;
        }
    }
}
#endif

struct View_ab5164_shaped01_game {
    uint8_t pad[0x40];
    ListNode_shaped01_game* mpHead;
    void Fn00772e90(Obj_shaped01_game* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00772e90 score 8
void View_ab5164_shaped01_game::Fn00772e90(Obj_shaped01_game* pValue)
{
    ListNode_shaped01_game* pHead = mpHead;
    for (ListNode_shaped01_game* pNode = pHead->mpNext; pNode != pHead; pNode = pNode->mpNext) {
        if (pNode->mpValue == pValue) {
            ListNode_shaped01_game* pPrev = pNode->mpPrev;
            ListNode_shaped01_game* pNext = pNode->mpNext;
            pPrev->mpNext = pNext;
            pNext->mpPrev = pPrev;
            Obj_shaped01_game* pObj = pNode->mpValue;
            if (pObj) {
                pObj->Slot02();
            }
            _STL::__stl_delete(pNode);
            return;
        }
    }
}
#endif

// ---- erase a tree entry, release its object
struct Header_shaped01_game {
    uint32_t mnColor;
    uint32_t mpRoot;
    uint32_t mpLeft;
    uint32_t mpRight;
};

struct Entry_shaped01_game {
    uint8_t pad[0x10];
    Obj_shaped01_game* mpA;
    Obj_shaped01_game* mpB;
};

// STUB: 0x0040daf0
Entry_shaped01_game* Fn0040daf0(uint32_t nKey, uint32_t* pRoot, uint32_t* pLeft, uint32_t* pRight);

struct View_tree_shaped01_game {
    Header_shaped01_game* mpHeader;
    uint32_t mnCount;
    void Fn0040e440(uint32_t nKey);
    void Fn00418db0(uint32_t nKey);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0040e440 score 4
void View_tree_shaped01_game::Fn0040e440(uint32_t nKey)
{
    Entry_shaped01_game* pEntry = Fn0040daf0(nKey, &mpHeader->mpRoot, &mpHeader->mpLeft, &mpHeader->mpRight);
    Obj_shaped01_game* pObj = pEntry->mpA;
    if (pObj) {
        pObj->Slot02();
    }
    if (pEntry) {
        _STL::__stl_delete(pEntry);
    }
    mnCount = mnCount - 1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00418db0 score 4
void View_tree_shaped01_game::Fn00418db0(uint32_t nKey)
{
    Entry_shaped01_game* pEntry = Fn0040daf0(nKey, &mpHeader->mpRoot, &mpHeader->mpLeft, &mpHeader->mpRight);
    Obj_shaped01_game* pObj = pEntry->mpB;
    if (pObj) {
        pObj->Slot02();
    }
    if (pEntry) {
        _STL::__stl_delete(pEntry);
    }
    mnCount = mnCount - 1;
}
#endif

// ---- pick a string id by thresholds
// STUB: 0x00603040
uint32_t SC4LoadString(void* pString, uint32_t nGroup, uint32_t nInstance, void* pDetokenizer);

// FUNCTION: 0x00437a30
uint32_t Fn00437a30(float fValue, void* pString)
{
    uint32_t nId;
    if (fValue < 50.0f) {
        nId = 0xea5b8c93;
    } else if (fValue < 100.0f) {
        nId = 0xea5b8c94;
    } else {
        nId = 0xea5b8c95;
    }
    return SC4LoadString(pString, 0xea231e96, nId, 0);
}

// FUNCTION: 0x00437a80
uint32_t Fn00437a80(float fValue, void* pString)
{
    uint32_t nId;
    if (fValue < 50.0f) {
        nId = 0xea5b8c90;
    } else if (fValue < 100.0f) {
        nId = 0xea5b8c91;
    } else {
        nId = 0xea5b8c92;
    }
    return SC4LoadString(pString, 0xea231e96, nId, 0);
}

// ---- vector push_back of a reference-counted pointer
struct View_vec_shaped01_game {
    uint8_t pad[4];
    Obj_shaped01_game** mpEnd;
    Obj_shaped01_game** mpCapacity;
    // STUB: 0x00430a90
    void Fn00430a90(Obj_shaped01_game** pPos, Obj_shaped01_game* const* pValue, Obj_shaped01_game* const* const* ppValue, uint32_t nA, uint32_t nB);
    // STUB: 0x005880c0
    void Fn005880c0(Obj_shaped01_game** pPos, Obj_shaped01_game* const* pValue, Obj_shaped01_game* const* const* ppValue, uint32_t nA, uint32_t nB);
    void Fn00442e40(Obj_shaped01_game* const* pValue);
    void Fn00588850(Obj_shaped01_game* const* pValue);
};

// FUNCTION: 0x00442e40
void View_vec_shaped01_game::Fn00442e40(Obj_shaped01_game* const* pValue)
{
    Obj_shaped01_game** pPos = mpEnd;
    if (pPos != mpCapacity) {
        if (pPos) {
            Obj_shaped01_game* pObj = *pValue;
            *pPos = pObj;
            if (pObj) {
                pObj->Slot01();
            }
        }
        mpEnd = mpEnd + 1;
    } else {
        Fn00430a90(pPos, pValue, &pValue, 1, 1);
    }
}

// FUNCTION: 0x00588850
void View_vec_shaped01_game::Fn00588850(Obj_shaped01_game* const* pValue)
{
    Obj_shaped01_game** pPos = mpEnd;
    if (pPos != mpCapacity) {
        if (pPos) {
            Obj_shaped01_game* pObj = *pValue;
            *pPos = pObj;
            if (pObj) {
                pObj->Slot04();
            }
        }
        mpEnd = mpEnd + 1;
    } else {
        Fn005880c0(pPos, pValue, &pValue, 1, 1);
    }
}

// ---- hour of the day, DST-adjusted
// GLOBAL: 0x00b18ba8
extern uint32_t gnB18ba8;

struct Time_shaped01_game {
    uint32_t mnValue;
    // STUB: 0x00417730
    uint32_t Fn00417730();
};

struct View_time_shaped01_game {
    uint32_t mnTime;
    uint32_t Fn00417870();
    uint32_t Fn004178b0();
};

// FUNCTION: 0x00417870
uint32_t View_time_shaped01_game::Fn00417870()
{
    uint32_t nBase = gnB18ba8;
    uint32_t nTime = mnTime - nBase;
    Time_shaped01_game tTime;
    tTime.mnValue = nTime;
    if (tTime.Fn00417730()) {
        nTime += 3600;
    }
    return (nTime % 86400) / 3600;
}

// FUNCTION: 0x004178b0
uint32_t View_time_shaped01_game::Fn004178b0()
{
    uint32_t nBase = gnB18ba8;
    uint32_t nTime = mnTime - nBase;
    Time_shaped01_game tTime;
    tTime.mnValue = nTime;
    if (tTime.Fn00417730()) {
        nTime += 3600;
    }
    return (nTime % 3600) / 60;
}

// ---- query an interface, take a reference, call through it
struct Iface_shaped01_game {
    virtual bool Slot00(uint32_t nId, void** ppOut) = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual uint32_t Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual Iface_shaped01_game* Slot25() = 0;
};

// FUNCTION: 0x0045ba70
uint32_t Fn0045ba70(Iface_shaped01_game* pObj)
{
    Iface_shaped01_game* pFound = 0;
    pObj->Slot00(0x4999a8f5, reinterpret_cast<void**>(&pFound));
    Iface_shaped01_game* pQuery = pFound;
    if (pQuery) {
        pQuery->Slot02();
        Iface_shaped01_game* pTarget = pQuery->Slot25();
        if (pTarget) {
            return pTarget->Slot03();
        }
    }
    return 0;
}

// FUNCTION: 0x0045bac0
uint32_t Fn0045bac0(Iface_shaped01_game* pObj)
{
    Iface_shaped01_game* pFound = 0;
    pObj->Slot00(0x6999a8fb, reinterpret_cast<void**>(&pFound));
    Iface_shaped01_game* pQuery = pFound;
    if (pQuery) {
        pQuery->Slot02();
        Iface_shaped01_game* pTarget = pQuery->Slot25();
        if (pTarget) {
            return pTarget->Slot03();
        }
    }
    return 0;
}

// ---- notify the five listeners
struct Wide_shaped01_game {
    virtual bool Slot00(uint32_t nId, void** ppOut) = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual void Slot34() = 0;
    virtual void Slot35() = 0;
    virtual void Slot36() = 0;
    virtual void Slot37() = 0;
    virtual void Slot38() = 0;
    virtual void Slot39() = 0;
    virtual void Slot40() = 0;
    virtual void Slot41() = 0;
    virtual void Slot42(void* pArg) = 0;
    virtual void Slot43(void* pArg) = 0;
    virtual void Slot44() = 0;
    virtual void Slot45() = 0;
    virtual void Slot46(uint32_t a, uint32_t b) = 0;
    virtual void Slot47(uint32_t a, uint32_t b) = 0;
    virtual void Slot48() = 0;
    virtual void Slot49() = 0;
    virtual void Slot50() = 0;
    virtual void Slot51() = 0;
    virtual void Slot52() = 0;
    virtual void Slot53() = 0;
    virtual void Slot54() = 0;
    virtual void Slot55() = 0;
    virtual void Slot56() = 0;
    virtual void Slot57() = 0;
    virtual void Slot58() = 0;
    virtual void Slot59() = 0;
    virtual void Slot60() = 0;
    virtual void Slot61() = 0;
    virtual void Slot62() = 0;
    virtual void Slot63() = 0;
    virtual void Slot64() = 0;
    virtual void Slot65() = 0;
    virtual void Slot66() = 0;
    virtual void Slot67() = 0;
    virtual void Slot68() = 0;
    virtual void Slot69() = 0;
    virtual void Slot70() = 0;
    virtual void Slot71() = 0;
    virtual void Slot72() = 0;
    virtual void Slot73() = 0;
    virtual void Slot74() = 0;
    virtual void Slot75() = 0;
    virtual void Slot76() = 0;
    virtual void Slot77() = 0;
    virtual void Slot78() = 0;
    virtual void Slot79() = 0;
    virtual void Slot80() = 0;
    virtual void Slot81() = 0;
    virtual void Slot82() = 0;
    virtual void Slot83() = 0;
    virtual void Slot84() = 0;
    virtual void Slot85() = 0;
    virtual void Slot86() = 0;
    virtual void Slot87() = 0;
    virtual void Slot88() = 0;
    virtual void Slot89() = 0;
    virtual void Slot90() = 0;
    virtual void Slot91() = 0;
    virtual void Slot92() = 0;
    virtual void Slot93() = 0;
    virtual void Slot94() = 0;
    virtual void Slot95() = 0;
    virtual void Slot96() = 0;
    virtual void Slot97(uint32_t a, uint32_t b, uint32_t* pA, uint32_t* pB) = 0;
};

struct View_listen_shaped01_game {
    uint8_t pad[0x14];
    Wide_shaped01_game** mpListeners;
    uint8_t pad2[0x18];
    Wide_shaped01_game* mpManager;
    void Fn0042e690(Wide_shaped01_game* pSource);
    void Fn0042e6f0(Wide_shaped01_game* pSource);
    void Fn0042e7a0(uint32_t nA, uint32_t nB);
    void Fn0042e7f0(uint32_t nA, uint32_t nB);
};

// FUNCTION: 0x0042e690
void View_listen_shaped01_game::Fn0042e690(Wide_shaped01_game* pSource)
{
    Wide_shaped01_game* pFound = 0;
    if (pSource->Slot00(0x87dda3a9, reinterpret_cast<void**>(&pFound))) {
        for (int32_t i = 0; i < 5; ++i) {
            Wide_shaped01_game* pListener = mpListeners[i];
            if (pListener) {
                pListener->Slot42(pFound);
            }
        }
    }
    if (pFound) {
        pFound->Slot02();
    }
}

// FUNCTION: 0x0042e6f0
void View_listen_shaped01_game::Fn0042e6f0(Wide_shaped01_game* pSource)
{
    Wide_shaped01_game* pFound = 0;
    if (pSource->Slot00(0x87dda3a9, reinterpret_cast<void**>(&pFound))) {
        for (int32_t i = 0; i < 5; ++i) {
            Wide_shaped01_game* pListener = mpListeners[i];
            if (pListener) {
                pListener->Slot43(pFound);
            }
        }
    }
    if (pFound) {
        pFound->Slot02();
    }
}

// FUNCTION: 0x0042e7a0
void View_listen_shaped01_game::Fn0042e7a0(uint32_t nA, uint32_t nB)
{
    mpManager->Slot97(nA, nB, &nA, &nB);
    for (int32_t i = 0; i < 5; ++i) {
        Wide_shaped01_game* pListener = mpListeners[i];
        if (pListener) {
            pListener->Slot46(nA, nB);
        }
    }
}

// FUNCTION: 0x0042e7f0
void View_listen_shaped01_game::Fn0042e7f0(uint32_t nA, uint32_t nB)
{
    mpManager->Slot97(nA, nB, &nA, &nB);
    for (int32_t i = 0; i < 5; ++i) {
        Wide_shaped01_game* pListener = mpListeners[i];
        if (pListener) {
            pListener->Slot47(nA, nB);
        }
    }
}

// ---- pause counters of the clock
struct Timer_shaped01_game {
    // STUB: 0x008905f0
    void Fn008905f0();
    // STUB: 0x008905c4
    void Fn008905c4();
};

struct View_pause_shaped01_game {
    uint8_t pad[0x30];
    int32_t mnPauses;
    int32_t mnHiddenPauses;
    uint8_t pad2[0x18];
    Timer_shaped01_game mTimer;
    // STUB: 0x004454b0
    void Fn004454b0(uint32_t nMessage, uint32_t nA, uint32_t nB);
    bool Fn00445540(bool bPause);
    bool Fn004455b0(bool bPause);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00445540 score 4
bool View_pause_shaped01_game::Fn00445540(bool bPause)
{
    if (bPause) {
        ++mnPauses;
        if (mnPauses == 1) {
            if (mnHiddenPauses == 0) {
                mTimer.Fn008905f0();
                Fn004454b0(0x44778235, 1, 0);
            }
        }
        return true;
    } else if (mnPauses > 0) {
        --mnPauses;
        if (mnPauses == 0) {
            if (mnHiddenPauses == 0) {
                mTimer.Fn008905c4();
                Fn004454b0(0x44778235, 0, 0);
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004455b0 score 4
bool View_pause_shaped01_game::Fn004455b0(bool bPause)
{
    if (bPause) {
        ++mnHiddenPauses;
        if (mnHiddenPauses == 1) {
            if (mnPauses == 0) {
                mTimer.Fn008905f0();
                Fn004454b0(0x44778236, 1, 0);
            }
        }
        return true;
    } else if (mnHiddenPauses > 0) {
        --mnHiddenPauses;
        if (mnHiddenPauses == 0) {
            if (mnPauses == 0) {
                mTimer.Fn008905c4();
                Fn004454b0(0x44778236, 0, 0);
            }
        }
    }
    return true;
}
#endif

// ---- add a reference-counted pointer to a vector member
struct Vec_shaped01_game {
    uint8_t pad[4];
    Obj_shaped01_game** mpEnd;
    Obj_shaped01_game** mpCapacity;
    // STUB: 0x00430a90
    void Fn00430a90(Obj_shaped01_game** pPos, Obj_shaped01_game** pValue, Obj_shaped01_game** pValue2, uint32_t nA, uint32_t nB);
};

struct View_a82930_shaped01_game {
    uint8_t pad[0x74];
    Vec_shaped01_game mVec;
    void Fn00419840(Obj_shaped01_game* pAdvice);
};

struct View_dispatch_shaped01_game {
    uint8_t pad[0x40];
    Vec_shaped01_game mVec;
    void Fn0046ae00(Obj_shaped01_game* pAdvice);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00419840 score 17
void View_a82930_shaped01_game::Fn00419840(Obj_shaped01_game* pAdvice)
{
    Obj_shaped01_game* pLocal = pAdvice;
    if (pAdvice) {
        pAdvice->Slot01();
    }
    Obj_shaped01_game** pPos = mVec.mpEnd;
    Obj_shaped01_game** pCapacity = mVec.mpCapacity;
    Vec_shaped01_game* pVec = &mVec;
    if (pPos != pCapacity) {
        if (pPos) {
            *pPos = pAdvice;
            if (pAdvice) {
                pAdvice->Slot01();
            }
        }
        pVec->mpEnd = pVec->mpEnd + 1;
    } else {
        pVec->Fn00430a90(pPos, &pLocal, &pLocal, 1, 1);
    }
    if (pAdvice) {
        pAdvice->Slot02();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0046ae00 score 17
void View_dispatch_shaped01_game::Fn0046ae00(Obj_shaped01_game* pAdvice)
{
    Obj_shaped01_game* pLocal = pAdvice;
    if (pAdvice) {
        pAdvice->Slot01();
    }
    Obj_shaped01_game** pPos = mVec.mpEnd;
    Obj_shaped01_game** pCapacity = mVec.mpCapacity;
    Vec_shaped01_game* pVec = &mVec;
    if (pPos != pCapacity) {
        if (pPos) {
            *pPos = pAdvice;
            if (pAdvice) {
                pAdvice->Slot01();
            }
        }
        pVec->mpEnd = pVec->mpEnd + 1;
    } else {
        pVec->Fn00430a90(pPos, &pLocal, &pLocal, 1, 1);
    }
    if (pAdvice) {
        pAdvice->Slot02();
    }
}
#endif

// ---- parse a position out of a text
struct Record_shaped01_game {
    uint32_t mnType;
    uint32_t mnId;
    uint32_t mnValue;
};

// GLOBAL: 0x00b07ce4
extern const char* gpFormatsA[4];
// GLOBAL: 0x00b07e84
extern const char* gpFormatsB[4];

struct View_scan_shaped01_game {
    // STUB: 0x00602f90
    void Fn00602f90(Record_shaped01_game* pRecord);
    void Fn004178f0(const char* pText, uint32_t /*nUnused*/);
    void Fn00440370(const char* pText, uint32_t /*nUnused*/);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004178f0 score 16
void View_scan_shaped01_game::Fn004178f0(const char* pText, uint32_t /*nUnused*/)
{
    uint32_t nValue;
    Record_shaped01_game tRecord;
    tRecord.mnType = 0x2026960b;
    tRecord.mnId = 0x6a231ea4;
    tRecord.mnValue = 0;
    if (sscanf(pText, gpFormatsA[0], &nValue) == 1 || sscanf(pText, gpFormatsA[1], &nValue) == 1 ||
        sscanf(pText, gpFormatsA[2], &nValue) == 1 || sscanf(pText, gpFormatsA[3], &nValue) == 1) {
        tRecord.mnValue = nValue;
        Fn00602f90(&tRecord);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00440370 score 16
void View_scan_shaped01_game::Fn00440370(const char* pText, uint32_t /*nUnused*/)
{
    uint32_t nValue;
    Record_shaped01_game tRecord;
    tRecord.mnType = 0x2026960b;
    tRecord.mnId = 0xca554b03;
    tRecord.mnValue = 0;
    if (sscanf(pText, gpFormatsB[0], &nValue) == 1 || sscanf(pText, gpFormatsB[1], &nValue) == 1 ||
        sscanf(pText, gpFormatsB[2], &nValue) == 1 || sscanf(pText, gpFormatsB[3], &nValue) == 1) {
        tRecord.mnValue = nValue;
        Fn00602f90(&tRecord);
    }
}
#endif

// ---- QueryInterface over four bases
struct QiBaseA_shaped01_game {
    virtual void QA0() = 0;
};

struct QiBaseB_shaped01_game {
    virtual void QB0() = 0;
};

struct QiPad_shaped01_game {
    virtual void QP0() = 0;
};

struct QiBase0_shaped01_game {
    virtual void Slot00() = 0;
    virtual void AddRef() = 0;
};

struct QiBaseC_shaped01_game {
    virtual void QC0() = 0;
};

struct QiBaseD_shaped01_game {
    // STUB: 0x009457c6
    bool Fn009457c6(uint32_t nId, void** ppOut);
    virtual void QD0() = 0;
};

struct View_qi_00418640_shaped01_game : public QiBase0_shaped01_game, public QiBaseA_shaped01_game, public QiBaseB_shaped01_game, public QiPad_shaped01_game, public QiBaseC_shaped01_game, public QiBaseD_shaped01_game {
    bool Fn00418640(uint32_t nId, void** ppOut);
};

struct View_qi_0043efe0_shaped01_game : public QiBase0_shaped01_game, public QiBaseA_shaped01_game, public QiBaseB_shaped01_game, public QiPad_shaped01_game, public QiBaseC_shaped01_game, public QiBaseD_shaped01_game {
    bool Fn0043efe0(uint32_t nId, void** ppOut);
};

// FUNCTION: 0x00418640
bool View_qi_00418640_shaped01_game::Fn00418640(uint32_t nId, void** ppOut)
{
    switch (nId) {
    case 0xe4fda3d4:
        *ppOut = static_cast<QiBaseC_shaped01_game*>(this);
        AddRef();
        return true;
    case 0x452294aa:
        *ppOut = static_cast<QiBaseA_shaped01_game*>(this);
        AddRef();
        return true;
    case 0x4a0dd617:
        *ppOut = static_cast<QiBase0_shaped01_game*>(this);
        AddRef();
        return true;
    case 0xe98b2f57:
        *ppOut = static_cast<QiBaseB_shaped01_game*>(this);
        AddRef();
        return true;
    }
    return QiBaseD_shaped01_game::Fn009457c6(nId, ppOut);
}

// FUNCTION: 0x0043efe0
bool View_qi_0043efe0_shaped01_game::Fn0043efe0(uint32_t nId, void** ppOut)
{
    switch (nId) {
    case 0xe4fda3d4:
        *ppOut = static_cast<QiBaseC_shaped01_game*>(this);
        AddRef();
        return true;
    case 0x452294aa:
        *ppOut = static_cast<QiBaseA_shaped01_game*>(this);
        AddRef();
        return true;
    case 0xaa3836f6:
        *ppOut = static_cast<QiBase0_shaped01_game*>(this);
        AddRef();
        return true;
    case 0xe98b2f57:
        *ppOut = static_cast<QiBaseB_shaped01_game*>(this);
        AddRef();
        return true;
    }
    return QiBaseD_shaped01_game::Fn009457c6(nId, ppOut);
}
