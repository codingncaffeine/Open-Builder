// Shape families of packet shape02_game, written by scratch/s16/gen/shape02_game/gen.sh, then finished by hand: the pool
// frees are methods of their allocator (its block release and trim are its own methods). Do not regenerate.
#include <new>
#include "common/types.h"
#include "common/compiler.h"

struct PoolBlock_shape02_game {
    uint32_t pad0;
    uint32_t pad4;
    void* mpFree;
    uint32_t mnUsed;
};

// The allocator the pool frees belong to: its block release and trim are its own methods, so this stays in ecx
// for their tail calls.
struct PoolAlloc_shape02_game {
    void Fn00458f00(void* pItem);
    void Fn004f5670(void* pItem);
    void Fn004f59c0(void* pItem);
    void Fn004f82a0(void* pItem);
    void Fn0053dc10(void* pItem);
    void Fn005579e0(void* pItem);
    void Fn0055f600(void* pItem);
    void Fn005cd210(void* pItem);
    void Fn005dfd90(void* pItem);
    void Fn005e1780(void* pItem);
    void Fn005e32f0(void* pItem);
    void Fn005ec150(void* pItem);
    void Fn005f82a0(void* pItem);
    void Fn005fe890(void* pItem);
    void Fn005fe8d0(void* pItem);
    void Fn0061bd40(void* pItem);
    void Fn0064abb0(void* pItem);
    void Fn006bfff0(void* pItem);
    void Fn0070fd50(void* pItem);
    void Fn007c5690(void* pItem);
    void Fn007fd820(void* pItem);
    void Fn008020f0(void* pItem);
    // STUB: 0x0090d031
    void FreeBlock(PoolBlock_shape02_game* pBlock);
    // STUB: 0x0090cff9
    void TrimBlock(PoolBlock_shape02_game* pBlock);
};

// STUB: 0x0090d031
void OB_STDCALL Fn0090d031(PoolBlock_shape02_game* pBlock);

// STUB: 0x0090cff9
void OB_STDCALL Fn0090cff9(PoolBlock_shape02_game* pBlock);

struct Obj_4121a0_shape02_game {
    // STUB: 0x412100
    Obj_4121a0_shape02_game* Ctor();
};

// FUNCTION: 0x004121a0
void* Fn004121a0()
{
    void* p = ::operator new(0xdc);
    if (p) {
        Obj_4121a0_shape02_game* r = static_cast<Obj_4121a0_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x8;
        }
    }
    return 0;
}

struct Obj_41c170_shape02_game {
    // STUB: 0x41c080
    Obj_41c170_shape02_game* Ctor();
};

// FUNCTION: 0x0041c170
void* Fn0041c170()
{
    void* p = ::operator new(0xd0);
    if (p) {
        Obj_41c170_shape02_game* r = static_cast<Obj_41c170_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x8;
        }
    }
    return 0;
}

struct Obj_423dd0_shape02_game {
    // STUB: 0x423470
    Obj_423dd0_shape02_game* Ctor();
};

// FUNCTION: 0x00423dd0
void* Fn00423dd0()
{
    void* p = ::operator new(0x19c);
    if (p) {
        Obj_423dd0_shape02_game* r = static_cast<Obj_423dd0_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x4;
        }
    }
    return 0;
}

struct Obj_42a9f0_shape02_game {
    // STUB: 0x429890
    Obj_42a9f0_shape02_game* Ctor();
};

// FUNCTION: 0x0042a9f0
void* Fn0042a9f0()
{
    void* p = ::operator new(0x2b8);
    if (p) {
        Obj_42a9f0_shape02_game* r = static_cast<Obj_42a9f0_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0xb8;
        }
    }
    return 0;
}

struct Obj_42fb10_shape02_game {
    // STUB: 0x42fa70
    Obj_42fb10_shape02_game* Ctor();
};

// FUNCTION: 0x0042fb10
void* Fn0042fb10()
{
    void* p = ::operator new(0x104);
    if (p) {
        Obj_42fb10_shape02_game* r = static_cast<Obj_42fb10_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0xc0;
        }
    }
    return 0;
}

struct Obj_43dfa0_shape02_game {
    // STUB: 0x43d5f0
    Obj_43dfa0_shape02_game* Ctor();
};

// FUNCTION: 0x0043dfa0
void* Fn0043dfa0()
{
    void* p = ::operator new(0x2c8);
    if (p) {
        Obj_43dfa0_shape02_game* r = static_cast<Obj_43dfa0_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x2b8;
        }
    }
    return 0;
}

// FUNCTION: 0x00458f00
void PoolAlloc_shape02_game::Fn00458f00(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffffe000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000042) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x004f5670
void PoolAlloc_shape02_game::Fn004f5670(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffffe000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000050) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x004f59c0
void PoolAlloc_shape02_game::Fn004f59c0(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xfffff800);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x4000005f) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x004f82a0
void PoolAlloc_shape02_game::Fn004f82a0(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffffe000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x4000003f) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x0053dc10
void PoolAlloc_shape02_game::Fn0053dc10(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xfffff000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000033) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x005579e0
void PoolAlloc_shape02_game::Fn005579e0(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffff0000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000045) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x0055f600
void PoolAlloc_shape02_game::Fn0055f600(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffff0000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000046) {
            TrimBlock(pBlock);
        }
    }
}

struct Obj_5763f0_shape02_game {
    // STUB: 0x576150
    Obj_5763f0_shape02_game* Ctor();
};

// FUNCTION: 0x005763f0
void* Fn005763f0()
{
    void* p = ::operator new(0x120);
    if (p) {
        Obj_5763f0_shape02_game* r = static_cast<Obj_5763f0_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x8;
        }
    }
    return 0;
}

struct Obj_578b70_shape02_game {
    // STUB: 0x578a10
    Obj_578b70_shape02_game* Ctor();
};

// FUNCTION: 0x00578b70
void* Fn00578b70()
{
    void* p = ::operator new(0xd8);
    if (p) {
        Obj_578b70_shape02_game* r = static_cast<Obj_578b70_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x8;
        }
    }
    return 0;
}

struct Obj_57bb60_shape02_game {
    // STUB: 0x57ad90
    Obj_57bb60_shape02_game* Ctor();
};

// FUNCTION: 0x0057bb60
void* Fn0057bb60()
{
    void* p = ::operator new(0x100);
    if (p) {
        Obj_57bb60_shape02_game* r = static_cast<Obj_57bb60_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x8;
        }
    }
    return 0;
}

struct Obj_57daa0_shape02_game {
    // STUB: 0x57d9a0
    Obj_57daa0_shape02_game* Ctor();
};

// FUNCTION: 0x0057daa0
void* Fn0057daa0()
{
    void* p = ::operator new(0x30);
    if (p) {
        Obj_57daa0_shape02_game* r = static_cast<Obj_57daa0_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x8;
        }
    }
    return 0;
}

struct Obj_57dfa0_shape02_game {
    // STUB: 0x57dac0
    Obj_57dfa0_shape02_game* Ctor();
};

// FUNCTION: 0x0057dfa0
void* Fn0057dfa0()
{
    void* p = ::operator new(0x78);
    if (p) {
        Obj_57dfa0_shape02_game* r = static_cast<Obj_57dfa0_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x8;
        }
    }
    return 0;
}

// FUNCTION: 0x005cd210
void PoolAlloc_shape02_game::Fn005cd210(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffff8000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x4000003a) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x005dfd90
void PoolAlloc_shape02_game::Fn005dfd90(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffffc000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000033) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x005e1780
void PoolAlloc_shape02_game::Fn005e1780(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffffc000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000045) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x005e32f0
void PoolAlloc_shape02_game::Fn005e32f0(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffffe000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000038) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x005ec150
void PoolAlloc_shape02_game::Fn005ec150(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xfffff000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x4000003f) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x005f82a0
void PoolAlloc_shape02_game::Fn005f82a0(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffffc000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000041) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x005fe890
void PoolAlloc_shape02_game::Fn005fe890(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xfffff800);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000036) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x005fe8d0
void PoolAlloc_shape02_game::Fn005fe8d0(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xfffff000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000036) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x0061bd40
void PoolAlloc_shape02_game::Fn0061bd40(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffff8000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x4000003f) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x0064abb0
void PoolAlloc_shape02_game::Fn0064abb0(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffff8000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000054) {
            TrimBlock(pBlock);
        }
    }
}

struct Obj_658370_shape02_game {
    // STUB: 0x658290
    Obj_658370_shape02_game* Ctor();
};

// FUNCTION: 0x00658370
void* Fn00658370()
{
    void* p = ::operator new(0x18);
    if (p) {
        Obj_658370_shape02_game* r = static_cast<Obj_658370_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x8;
        }
    }
    return 0;
}

struct Obj_658390_shape02_game {
    // STUB: 0x658300
    Obj_658390_shape02_game* Ctor();
};

// FUNCTION: 0x00658390
void* Fn00658390()
{
    void* p = ::operator new(0x18);
    if (p) {
        Obj_658390_shape02_game* r = static_cast<Obj_658390_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0x8;
        }
    }
    return 0;
}

// FUNCTION: 0x006bfff0
void PoolAlloc_shape02_game::Fn006bfff0(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffffc000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x40000057) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x0070fd50
void PoolAlloc_shape02_game::Fn0070fd50(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xfffff800);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x4000003f) {
            TrimBlock(pBlock);
        }
    }
}

struct Obj_7a8af0_shape02_game {
    // STUB: 0x7a8920
    Obj_7a8af0_shape02_game* Ctor();
};

// FUNCTION: 0x007a8af0
void* Fn007a8af0()
{
    void* p = ::operator new(0x96c);
    if (p) {
        Obj_7a8af0_shape02_game* r = static_cast<Obj_7a8af0_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0xd8;
        }
    }
    return 0;
}

// FUNCTION: 0x007c5690
void PoolAlloc_shape02_game::Fn007c5690(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xfffff000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x4000003a) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x007fd820
void PoolAlloc_shape02_game::Fn007fd820(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffffc000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x4000003a) {
            TrimBlock(pBlock);
        }
    }
}

// FUNCTION: 0x008020f0
void PoolAlloc_shape02_game::Fn008020f0(void* pItem)
{
    if (pItem) {
        PoolBlock_shape02_game* pBlock = reinterpret_cast<PoolBlock_shape02_game*>(reinterpret_cast<uintptr_t>(pItem) & 0xffffc000);
        *static_cast<void**>(pItem) = pBlock->mpFree;
        pBlock->mpFree = pItem;
        if (--pBlock->mnUsed == 0) {
            FreeBlock(pBlock);
        } else if (pBlock->mnUsed == 0x4000004a) {
            TrimBlock(pBlock);
        }
    }
}

struct Obj_886700_shape02_game {
    // STUB: 0x885f90
    Obj_886700_shape02_game* Ctor();
};

// FUNCTION: 0x00886700
void* Fn00886700()
{
    void* p = ::operator new(0x2e0);
    if (p) {
        Obj_886700_shape02_game* r = static_cast<Obj_886700_shape02_game*>(p)->Ctor();
        if (r) {
            return reinterpret_cast<char*>(r) + 0xc;
        }
    }
    return 0;
}

