// Shape families of packet shape04_game, written by scratch/s16/gen/shape04_game/gen.sh.
#include "common/types.h"

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

// The header node of an STL tree container.
struct Node_shape04_game {
    uint32_t mnColor;
    Node_shape04_game* mpRoot;
    Node_shape04_game* mpLeft;
    Node_shape04_game* mpRight;
};

// A counted interface (slot 2 releases).
struct Iface_shape04_game {
    virtual void Slot0();
    virtual void Slot1();
    virtual void Release();
};

struct Holder_shape04_game {
    Iface_shape04_game* mpObj;
    ~Holder_shape04_game()
    {
        if (mpObj) {
            mpObj->Release();
        }
    }
};

struct View_40e960_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0040dab0
    void Erase(Node_shape04_game* pNode);
    void Fn0040e960();
};

// FUNCTION: 0x0040e960
void View_40e960_shape04_game::Fn0040e960()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_40ece0_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0040e050
    void Erase(Node_shape04_game* pNode);
    void Fn0040ece0();
};

// FUNCTION: 0x0040ece0
void View_40ece0_shape04_game::Fn0040ece0()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_41be50_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0041b890
    void Erase(Node_shape04_game* pNode);
    void Fn0041be50();
};

// FUNCTION: 0x0041be50
void View_41be50_shape04_game::Fn0041be50()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_459000_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x00458e00
    void Erase(Node_shape04_game* pNode);
    void Fn00459000();
};

// FUNCTION: 0x00459000
void View_459000_shape04_game::Fn00459000()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_46c1a0_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0046b7b0
    void Erase(Node_shape04_game* pNode);
    void Fn0046c1a0();
};

// FUNCTION: 0x0046c1a0
void View_46c1a0_shape04_game::Fn0046c1a0()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_46f9d0_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0046f820
    void Erase(Node_shape04_game* pNode);
    void Fn0046f9d0();
};

// FUNCTION: 0x0046f9d0
void View_46f9d0_shape04_game::Fn0046f9d0()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_4b6400_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x004b6250
    void Erase(Node_shape04_game* pNode);
    void Fn004b6400();
};

// FUNCTION: 0x004b6400
void View_4b6400_shape04_game::Fn004b6400()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_4fb780_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x004fb270
    void Erase(Node_shape04_game* pNode);
    void Fn004fb780();
};

// FUNCTION: 0x004fb780
void View_4fb780_shape04_game::Fn004fb780()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_6225d0_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x00622190
    void Erase(Node_shape04_game* pNode);
    void Fn006225d0();
};

// FUNCTION: 0x006225d0
void View_6225d0_shape04_game::Fn006225d0()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_671290_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0066f6f0
    void Erase(Node_shape04_game* pNode);
    void Fn00671290();
};

// FUNCTION: 0x00671290
void View_671290_shape04_game::Fn00671290()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_6a2d60_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x006a25c0
    void Erase(Node_shape04_game* pNode);
    void Fn006a2d60();
};

// FUNCTION: 0x006a2d60
void View_6a2d60_shape04_game::Fn006a2d60()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_713660_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x00426a60
    void Erase(Node_shape04_game* pNode);
    void Fn00713660();
};

// FUNCTION: 0x00713660
void View_713660_shape04_game::Fn00713660()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_76b9f0_shape04_game {
    Node_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0076b9b0
    void Erase(Node_shape04_game* pNode);
    void Fn0076b9f0();
};

// FUNCTION: 0x0076b9f0
void View_76b9f0_shape04_game::Fn0076b9f0()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

