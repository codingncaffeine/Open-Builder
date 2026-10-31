// Shape families of packet shape01_game, written by scratch/s16/gen/shape01_game/gen.sh.
#include "common/types.h"

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// STUB: 0x0090d8e0
void* Fn0090d8e0(uint32_t shift);

struct TreeNode_shape01_game {
    uint32_t pad0;
    uint32_t pad4;
    TreeNode_shape01_game* mpNext;
    TreeNode_shape01_game* mpChild;
};

struct PoolNode_shape01_game {
    PoolNode_shape01_game* mpNext;
};

struct PoolBlock_shape01_game {
    uint32_t pad0;
    uint32_t pad4;
    PoolNode_shape01_game* mpFree;
    uint32_t mnUsed;
};

struct View_418b10_shape01_game {
    void Fn00418b10(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x00418b10
void View_418b10_shape01_game::Fn00418b10(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn00418b10(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_426a60_shape01_game {
    void Fn00426a60(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x00426a60
void View_426a60_shape01_game::Fn00426a60(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn00426a60(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x004589b0
PoolBlock_shape01_game* Fn004589b0()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xd));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x1f54;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x58;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x5c;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_458e00_shape01_game {
    void Fn00458e00(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x00458e00
void View_458e00_shape01_game::Fn00458e00(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn00458e00(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_46b770_shape01_game {
    void Fn0046b770(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0046b770
void View_46b770_shape01_game::Fn0046b770(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0046b770(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_46b7b0_shape01_game {
    void Fn0046b7b0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0046b7b0
void View_46b7b0_shape01_game::Fn0046b7b0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0046b7b0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_46b7f0_shape01_game {
    void Fn0046b7f0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0046b7f0
void View_46b7f0_shape01_game::Fn0046b7f0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0046b7f0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_46f820_shape01_game {
    void Fn0046f820(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0046f820
void View_46f820_shape01_game::Fn0046f820(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0046f820(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_473c60_shape01_game {
    void Fn00473c60(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x00473c60
void View_473c60_shape01_game::Fn00473c60(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn00473c60(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_473ca0_shape01_game {
    void Fn00473ca0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x00473ca0
void View_473ca0_shape01_game::Fn00473ca0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn00473ca0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_4899b0_shape01_game {
    void Fn004899b0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x004899b0
void View_4899b0_shape01_game::Fn004899b0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn004899b0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_497320_shape01_game {
    void Fn00497320(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x00497320
void View_497320_shape01_game::Fn00497320(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn00497320(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_4a4660_shape01_game {
    void Fn004a4660(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x004a4660
void View_4a4660_shape01_game::Fn004a4660(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn004a4660(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_4c56f0_shape01_game {
    void Fn004c56f0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x004c56f0
void View_4c56f0_shape01_game::Fn004c56f0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn004c56f0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_4dc6d0_shape01_game {
    void Fn004dc6d0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x004dc6d0
void View_4dc6d0_shape01_game::Fn004dc6d0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn004dc6d0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x004f5290
PoolBlock_shape01_game* Fn004f5290()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xb));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7f0;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x7f;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x10;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x004f52d0
PoolBlock_shape01_game* Fn004f52d0()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xd));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x1f88;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x6b;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x4c;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x004f7c10
PoolBlock_shape01_game* Fn004f7c10()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xd));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x1f90;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x55;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x60;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_4fb270_shape01_game {
    void Fn004fb270(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x004fb270
void View_4fb270_shape01_game::Fn004fb270(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn004fb270(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x0053d0c0
PoolBlock_shape01_game* Fn0053d0c0()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xc));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfc4;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x44;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x3c;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005447e0
PoolBlock_shape01_game* Fn005447e0()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0x10));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfd90;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x69;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x270;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x00557250
PoolBlock_shape01_game* Fn00557250()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0x10));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfd28;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x5c;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x2c8;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x0055b780
PoolBlock_shape01_game* Fn0055b780()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0x10));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfce8;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x5e;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x2b8;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_5776f0_shape01_game {
    void Fn005776f0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x005776f0
void View_5776f0_shape01_game::Fn005776f0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn005776f0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_577730_shape01_game {
    void Fn00577730(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x00577730
void View_577730_shape01_game::Fn00577730(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn00577730(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x005d53d0
PoolBlock_shape01_game* Fn005d53d0()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0x10));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfbe0;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x67;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x278;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005deb50
PoolBlock_shape01_game* Fn005deb50()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xe));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x3ee0;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x44;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0xf0;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005e1300
PoolBlock_shape01_game* Fn005e1300()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xe));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x3f50;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x5d;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0xb0;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005e2950
PoolBlock_shape01_game* Fn005e2950()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xd));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x1f48;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x4b;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x6c;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005ebdb0
PoolBlock_shape01_game* Fn005ebdb0()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xc));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfd0;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x55;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x30;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005fd650
PoolBlock_shape01_game* Fn005fd650()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xb));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7d4;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x48;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x1c;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005fd6b0
PoolBlock_shape01_game* Fn005fd6b0()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xc));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xf98;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x48;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x38;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_6000b0_shape01_game {
    void Fn006000b0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006000b0
void View_6000b0_shape01_game::Fn006000b0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006000b0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6038d0_shape01_game {
    void Fn006038d0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006038d0
void View_6038d0_shape01_game::Fn006038d0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006038d0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x00619d50
PoolBlock_shape01_game* Fn00619d50()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xf));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7e10;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x55;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x180;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_624ce0_shape01_game {
    void Fn00624ce0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x00624ce0
void View_624ce0_shape01_game::Fn00624ce0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn00624ce0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x006497e0
PoolBlock_shape01_game* Fn006497e0()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xf));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7eac;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x70;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x124;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_6679b0_shape01_game {
    void Fn006679b0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006679b0
void View_6679b0_shape01_game::Fn006679b0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006679b0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_68c140_shape01_game {
    void Fn0068c140(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0068c140
void View_68c140_shape01_game::Fn0068c140(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0068c140(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6903a0_shape01_game {
    void Fn006903a0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006903a0
void View_6903a0_shape01_game::Fn006903a0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006903a0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6a2500_shape01_game {
    void Fn006a2500(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006a2500
void View_6a2500_shape01_game::Fn006a2500(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006a2500(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6a2540_shape01_game {
    void Fn006a2540(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006a2540
void View_6a2540_shape01_game::Fn006a2540(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006a2540(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6a2580_shape01_game {
    void Fn006a2580(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006a2580
void View_6a2580_shape01_game::Fn006a2580(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006a2580(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6a25c0_shape01_game {
    void Fn006a25c0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006a25c0
void View_6a25c0_shape01_game::Fn006a25c0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006a25c0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6a9c50_shape01_game {
    void Fn006a9c50(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006a9c50
void View_6a9c50_shape01_game::Fn006a9c50(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006a9c50(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6a9c90_shape01_game {
    void Fn006a9c90(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006a9c90
void View_6a9c90_shape01_game::Fn006a9c90(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006a9c90(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6a9cd0_shape01_game {
    void Fn006a9cd0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006a9cd0
void View_6a9cd0_shape01_game::Fn006a9cd0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006a9cd0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6b04b0_shape01_game {
    void Fn006b04b0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006b04b0
void View_6b04b0_shape01_game::Fn006b04b0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006b04b0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6b3e00_shape01_game {
    void Fn006b3e00(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006b3e00
void View_6b3e00_shape01_game::Fn006b3e00(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006b3e00(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6bd9f0_shape01_game {
    void Fn006bd9f0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006bd9f0
void View_6bd9f0_shape01_game::Fn006bd9f0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006bd9f0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x006bf3f0
PoolBlock_shape01_game* Fn006bf3f0()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xe));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x3ef4;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x74;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x8c;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_6bfe60_shape01_game {
    void Fn006bfe60(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x006bfe60
void View_6bfe60_shape01_game::Fn006bfe60(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn006bfe60(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x0070e220
PoolBlock_shape01_game* Fn0070e220()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xb));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7d8;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x54;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x18;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_70eed0_shape01_game {
    void Fn0070eed0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0070eed0
void View_70eed0_shape01_game::Fn0070eed0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0070eed0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_70ef10_shape01_game {
    void Fn0070ef10(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0070ef10
void View_70ef10_shape01_game::Fn0070ef10(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0070ef10(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_70ef50_shape01_game {
    void Fn0070ef50(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0070ef50
void View_70ef50_shape01_game::Fn0070ef50(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0070ef50(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_743990_shape01_game {
    void Fn00743990(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x00743990
void View_743990_shape01_game::Fn00743990(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn00743990(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_7439d0_shape01_game {
    void Fn007439d0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x007439d0
void View_7439d0_shape01_game::Fn007439d0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn007439d0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_75e1f0_shape01_game {
    void Fn0075e1f0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0075e1f0
void View_75e1f0_shape01_game::Fn0075e1f0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0075e1f0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_75e230_shape01_game {
    void Fn0075e230(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0075e230
void View_75e230_shape01_game::Fn0075e230(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0075e230(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_76b9b0_shape01_game {
    void Fn0076b9b0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0076b9b0
void View_76b9b0_shape01_game::Fn0076b9b0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0076b9b0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_76e9b0_shape01_game {
    void Fn0076e9b0(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0076e9b0
void View_76e9b0_shape01_game::Fn0076e9b0(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0076e9b0(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_78dd40_shape01_game {
    void Fn0078dd40(TreeNode_shape01_game* pNode);
};

// FUNCTION: 0x0078dd40
void View_78dd40_shape01_game::Fn0078dd40(TreeNode_shape01_game* pNode)
{
    while (pNode) {
        Fn0078dd40(pNode->mpChild);
        TreeNode_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x007c2e10
PoolBlock_shape01_game* Fn007c2e10()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xc));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfb4;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x4e;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x34;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x008019a0
PoolBlock_shape01_game* Fn008019a0()
{
    PoolBlock_shape01_game* pBlock = static_cast<PoolBlock_shape01_game*>(Fn0090d8e0(0xe));
    PoolNode_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x3ed8;
    PoolNode_shape01_game* pNode;
    uint32_t nLeft = 0x63;
    do {
        pNode = reinterpret_cast<PoolNode_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0xa4;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

