// Shape families of packet top_shape01_game, written by scratch/s16/gen/top_shape01_game/gen.sh.
#include "common/types.h"

// STUB: 0x0090cf63
void Fn0090cf63(void* p);

// STUB: 0x0090d8e0
void* Fn0090d8e0(uint32_t shift);

struct TreeNode_top_shape01_game {
    uint32_t pad0;
    uint32_t pad4;
    TreeNode_top_shape01_game* mpNext;
    TreeNode_top_shape01_game* mpChild;
};

struct PoolNode_top_shape01_game {
    PoolNode_top_shape01_game* mpNext;
};

struct PoolBlock_top_shape01_game {
    uint32_t pad0;
    uint32_t pad4;
    PoolNode_top_shape01_game* mpFree;
    uint32_t mnUsed;
};

struct View_40d9d0_top_shape01_game {
    void Fn0040d9d0(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0040d9d0
void View_40d9d0_top_shape01_game::Fn0040d9d0(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0040d9d0(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_40dab0_top_shape01_game {
    void Fn0040dab0(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0040dab0
void View_40dab0_top_shape01_game::Fn0040dab0(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0040dab0(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_41b890_top_shape01_game {
    void Fn0041b890(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0041b890
void View_41b890_top_shape01_game::Fn0041b890(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0041b890(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_41d7f0_top_shape01_game {
    void Fn0041d7f0(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0041d7f0
void View_41d7f0_top_shape01_game::Fn0041d7f0(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0041d7f0(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x004771d0
PoolBlock_top_shape01_game* Fn004771d0()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xd));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x1f58;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x4e;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x68;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_47b790_top_shape01_game {
    void Fn0047b790(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0047b790
void View_47b790_top_shape01_game::Fn0047b790(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0047b790(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_47b7d0_top_shape01_game {
    void Fn0047b7d0(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0047b7d0
void View_47b7d0_top_shape01_game::Fn0047b7d0(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0047b7d0(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_499f10_top_shape01_game {
    void Fn00499f10(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x00499f10
void View_499f10_top_shape01_game::Fn00499f10(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn00499f10(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_499f50_top_shape01_game {
    void Fn00499f50(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x00499f50
void View_499f50_top_shape01_game::Fn00499f50(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn00499f50(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x005ca860
PoolBlock_top_shape01_game* Fn005ca860()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xf));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7d30;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x4e;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x1a0;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005e5670
PoolBlock_top_shape01_game* Fn005e5670()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xb));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7f8;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0xfe;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x8;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005e56d0
PoolBlock_top_shape01_game* Fn005e56d0()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xc));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfd0;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x7f;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x20;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005e5730
PoolBlock_top_shape01_game* Fn005e5730()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xd));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x1f90;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x7f;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x40;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005e5790
PoolBlock_top_shape01_game* Fn005e5790()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xe));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x3f10;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x7f;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x80;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005e57d0
PoolBlock_top_shape01_game* Fn005e57d0()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xf));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7e10;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x7f;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x100;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005e5830
PoolBlock_top_shape01_game* Fn005e5830()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0x10));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfc10;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x7f;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x200;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005e5870
PoolBlock_top_shape01_game* Fn005e5870()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0x10));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xf810;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x3f;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x400;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005e58b0
PoolBlock_top_shape01_game* Fn005e58b0()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0x10));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xf010;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x1f;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x800;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005f49a0
PoolBlock_top_shape01_game* Fn005f49a0()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0x10));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfa60;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x2e;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x590;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x005f7680
PoolBlock_top_shape01_game* Fn005f7680()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xe));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x3f38;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x57;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0xbc;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x00604c60
PoolBlock_top_shape01_game* Fn00604c60()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xf));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7e00;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x42;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x1f0;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x0061d090
PoolBlock_top_shape01_game* Fn0061d090()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xf));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7d70;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x45;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x1d8;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_61fcd0_top_shape01_game {
    void Fn0061fcd0(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0061fcd0
void View_61fcd0_top_shape01_game::Fn0061fcd0(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0061fcd0(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x006471f0
PoolBlock_top_shape01_game* Fn006471f0()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xf));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7db0;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x44;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x1e0;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x00648580
PoolBlock_top_shape01_game* Fn00648580()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0x10));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfc90;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x66;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x280;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x00652e00
PoolBlock_top_shape01_game* Fn00652e00()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0x10));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfd28;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x5a;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x2d8;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_65e740_top_shape01_game {
    void Fn0065e740(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0065e740
void View_65e740_top_shape01_game::Fn0065e740(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0065e740(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_6645b0_top_shape01_game {
    void Fn006645b0(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x006645b0
void View_6645b0_top_shape01_game::Fn006645b0(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn006645b0(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_66e140_top_shape01_game {
    void Fn0066e140(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0066e140
void View_66e140_top_shape01_game::Fn0066e140(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0066e140(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_704990_top_shape01_game {
    void Fn00704990(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x00704990
void View_704990_top_shape01_game::Fn00704990(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn00704990(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_7049d0_top_shape01_game {
    void Fn007049d0(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x007049d0
void View_7049d0_top_shape01_game::Fn007049d0(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn007049d0(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_704a10_top_shape01_game {
    void Fn00704a10(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x00704a10
void View_704a10_top_shape01_game::Fn00704a10(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn00704a10(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_704a50_top_shape01_game {
    void Fn00704a50(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x00704a50
void View_704a50_top_shape01_game::Fn00704a50(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn00704a50(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_72abe0_top_shape01_game {
    void Fn0072abe0(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0072abe0
void View_72abe0_top_shape01_game::Fn0072abe0(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0072abe0(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_72ac20_top_shape01_game {
    void Fn0072ac20(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0072ac20
void View_72ac20_top_shape01_game::Fn0072ac20(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0072ac20(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

struct View_72acc0_top_shape01_game {
    void Fn0072acc0(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0072acc0
void View_72acc0_top_shape01_game::Fn0072acc0(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0072acc0(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

// FUNCTION: 0x007fb450
PoolBlock_top_shape01_game* Fn007fb450()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xe));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x3ea0;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x4e;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0xd0;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x007fb490
PoolBlock_top_shape01_game* Fn007fb490()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xc));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0xfb4;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x5c;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x2c;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

// FUNCTION: 0x007fb4d0
PoolBlock_top_shape01_game* Fn007fb4d0()
{
    PoolBlock_top_shape01_game* pBlock = static_cast<PoolBlock_top_shape01_game*>(Fn0090d8e0(0xf));
    PoolNode_top_shape01_game* pPrev = 0;
    char* pCur = reinterpret_cast<char*>(pBlock) + 0x7e7c;
    PoolNode_top_shape01_game* pNode;
    uint32_t nLeft = 0x58;
    do {
        pNode = reinterpret_cast<PoolNode_top_shape01_game*>(pCur);
        pNode->mpNext = pPrev;
        pPrev = pNode;
        pCur -= 0x174;
        --nLeft;
    } while (nLeft != 0);
    pBlock->mpFree = pNode;
    pBlock->mnUsed = 0;
    return pBlock;
}

struct View_98ef10_top_shape01_game {
    void Fn0098ef10(TreeNode_top_shape01_game* pNode);
};

// FUNCTION: 0x0098ef10
void View_98ef10_top_shape01_game::Fn0098ef10(TreeNode_top_shape01_game* pNode)
{
    while (pNode) {
        Fn0098ef10(pNode->mpChild);
        TreeNode_top_shape01_game* pNext = pNode->mpNext;
        Fn0090cf63(pNode);
        pNode = pNext;
    }
}

