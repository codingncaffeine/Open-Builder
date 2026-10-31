// Shape families of packet shapeb06_game, written by scratch/s16/gen/shapeb06_game/gen.sh.
#include "common/types.h"
#include <new>
#include "gzcom/cGZAllocatorServiceSTLAllocator.h"

namespace _STL {
    // STUB: 0x009dd0a0
    void __stl_throw_out_of_range(const char* msg);
    // STUB: 0x009dd1d0
    void __stl_throw_length_error(const char* msg);
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

class cISC4Occupant;

struct Node_b207dc_shapeb06_game {
    uint8_t mData[12];
};

template <>
struct cGZAllocatorServiceCache<Node_b207dc_shapeb06_game> {
    // GLOBAL: 0x00b207dc
    static cIGZAllocatorService* spService;
};

struct View_411b00_shapeb06_game {
    void* Fn00411b00(uint32_t n, const void* hint);
};

// FUNCTION: 0x00411b00
void* View_411b00_shapeb06_game::Fn00411b00(uint32_t n, const void* hint)
{
    if (!cGZAllocatorServiceCache<Node_b207dc_shapeb06_game>::spService) {
        cGZAllocatorServiceRef ref;
        ref.mpService = 0;
        cIGZFrameWork_Services* framework = RZGetFramework();
        if (framework) {
            framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService, reinterpret_cast<void**>(&ref.mpService));
        }
        cGZAllocatorServiceCache<Node_b207dc_shapeb06_game>::spService = ref.mpService;
        ref.Release();
    }
    return cGZAllocatorServiceCache<Node_b207dc_shapeb06_game>::spService->Allocate(n * 12);
}

struct Node_b207e0_shapeb06_game {
    uint8_t mData[12];
};

template <>
struct cGZAllocatorServiceCache<Node_b207e0_shapeb06_game> {
    // GLOBAL: 0x00b207e0
    static cIGZAllocatorService* spService;
};

struct View_411b60_shapeb06_game {
    void* Fn00411b60(uint32_t n, const void* hint);
};

// FUNCTION: 0x00411b60
void* View_411b60_shapeb06_game::Fn00411b60(uint32_t n, const void* hint)
{
    if (!cGZAllocatorServiceCache<Node_b207e0_shapeb06_game>::spService) {
        cGZAllocatorServiceRef ref;
        ref.mpService = 0;
        cIGZFrameWork_Services* framework = RZGetFramework();
        if (framework) {
            framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService, reinterpret_cast<void**>(&ref.mpService));
        }
        cGZAllocatorServiceCache<Node_b207e0_shapeb06_game>::spService = ref.mpService;
        ref.Release();
    }
    return cGZAllocatorServiceCache<Node_b207e0_shapeb06_game>::spService->Allocate(n * 12);
}

struct NodeOcc_shapeb06_game {
    uint8_t mData[12];
};

struct View_413dd0_shapeb06_game {
    void* Fn00413dd0(uint32_t n, const void* hint);
};

// FUNCTION: 0x00413dd0
void* View_413dd0_shapeb06_game::Fn00413dd0(uint32_t n, const void* hint)
{
    if (!cGZAllocatorServiceCache<cISC4Occupant*>::spService) {
        cGZAllocatorServiceRef ref;
        ref.mpService = 0;
        cIGZFrameWork_Services* framework = RZGetFramework();
        if (framework) {
            framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService, reinterpret_cast<void**>(&ref.mpService));
        }
        cGZAllocatorServiceCache<cISC4Occupant*>::spService = ref.mpService;
        ref.Release();
    }
    return cGZAllocatorServiceCache<cISC4Occupant*>::spService->Allocate(n * 12);
}

struct Node_b20d58_shapeb06_game {
    uint8_t mData[12];
};

template <>
struct cGZAllocatorServiceCache<Node_b20d58_shapeb06_game> {
    // GLOBAL: 0x00b20d58
    static cIGZAllocatorService* spService;
};

struct View_420fd0_shapeb06_game {
    void* Fn00420fd0(uint32_t n, const void* hint);
};

// FUNCTION: 0x00420fd0
void* View_420fd0_shapeb06_game::Fn00420fd0(uint32_t n, const void* hint)
{
    if (!cGZAllocatorServiceCache<Node_b20d58_shapeb06_game>::spService) {
        cGZAllocatorServiceRef ref;
        ref.mpService = 0;
        cIGZFrameWork_Services* framework = RZGetFramework();
        if (framework) {
            framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService, reinterpret_cast<void**>(&ref.mpService));
        }
        cGZAllocatorServiceCache<Node_b20d58_shapeb06_game>::spService = ref.mpService;
        ref.Release();
    }
    return cGZAllocatorServiceCache<Node_b20d58_shapeb06_game>::spService->Allocate(n * 12);
}

struct Node_b45238_shapeb06_game {
    uint8_t mData[12];
};

template <>
struct cGZAllocatorServiceCache<Node_b45238_shapeb06_game> {
    // GLOBAL: 0x00b45238
    static cIGZAllocatorService* spService;
};

struct View_611240_shapeb06_game {
    void* Fn00611240(uint32_t n, const void* hint);
};

// FUNCTION: 0x00611240
void* View_611240_shapeb06_game::Fn00611240(uint32_t n, const void* hint)
{
    if (!cGZAllocatorServiceCache<Node_b45238_shapeb06_game>::spService) {
        cGZAllocatorServiceRef ref;
        ref.mpService = 0;
        cIGZFrameWork_Services* framework = RZGetFramework();
        if (framework) {
            framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService, reinterpret_cast<void**>(&ref.mpService));
        }
        cGZAllocatorServiceCache<Node_b45238_shapeb06_game>::spService = ref.mpService;
        ref.Release();
    }
    return cGZAllocatorServiceCache<Node_b45238_shapeb06_game>::spService->Allocate(n * 12);
}

struct Elem_4470a0_shapeb06_game {
    uint8_t mData[12];
    // STUB: 0x004470a0
    void Assign(const Elem_4470a0_shapeb06_game& other);
};

// FUNCTION: 0x004473a0
Elem_4470a0_shapeb06_game* Fn004473a0(const Elem_4470a0_shapeb06_game* pFirst, const Elem_4470a0_shapeb06_game* pLast, Elem_4470a0_shapeb06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        --pLast;
        --pDest;
        pDest->Assign(*pLast);
    }
    return pDest;
}

struct Elem_5f3940_shapeb06_game {
    uint8_t mData[12];
    // STUB: 0x005f3940
    void Assign(const Elem_5f3940_shapeb06_game& other);
};

// FUNCTION: 0x005f3be0
Elem_5f3940_shapeb06_game* Fn005f3be0(const Elem_5f3940_shapeb06_game* pFirst, const Elem_5f3940_shapeb06_game* pLast, Elem_5f3940_shapeb06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        --pLast;
        --pDest;
        pDest->Assign(*pLast);
    }
    return pDest;
}

struct Elem_464430_shapeb06_game {
    uint8_t mData[12];
    // STUB: 0x00464430
    void Assign(const Elem_464430_shapeb06_game& other);
};

// FUNCTION: 0x00586800
Elem_464430_shapeb06_game* Fn00586800(const Elem_464430_shapeb06_game* pFirst, const Elem_464430_shapeb06_game* pLast, Elem_464430_shapeb06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        --pLast;
        --pDest;
        pDest->Assign(*pLast);
    }
    return pDest;
}

struct Elem_611b00_shapeb06_game {
    uint8_t mData[12];
    // STUB: 0x00611b00
    void Assign(const Elem_611b00_shapeb06_game& other);
};

// FUNCTION: 0x00611cb0
Elem_611b00_shapeb06_game* Fn00611cb0(const Elem_611b00_shapeb06_game* pFirst, const Elem_611b00_shapeb06_game* pLast, Elem_611b00_shapeb06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        --pLast;
        --pDest;
        pDest->Assign(*pLast);
    }
    return pDest;
}

struct Elem_4e3f80_shapeb06_game {
    uint8_t mData[12];
    // STUB: 0x004e3f80
    void Assign(const Elem_4e3f80_shapeb06_game& other);
};

// FUNCTION: 0x006c0b40
Elem_4e3f80_shapeb06_game* Fn006c0b40(const Elem_4e3f80_shapeb06_game* pFirst, const Elem_4e3f80_shapeb06_game* pLast, Elem_4e3f80_shapeb06_game* pDest)
{
    for (int32_t nLeft = pLast - pFirst; nLeft > 0; --nLeft) {
        --pLast;
        --pDest;
        pDest->Assign(*pLast);
    }
    return pDest;
}

struct View_411f80_shapeb06_game {
    void* mpData;
    // STUB: 0x00411d70
    void Clear();
    void Fn00411f80();
};

// FUNCTION: 0x00411f80
void View_411f80_shapeb06_game::Fn00411f80()
{
    Clear();
    void* pBlock = mpData;
    if (!cGZAllocatorServiceCache<Node_b207dc_shapeb06_game>::spService) {
        cGZAllocatorServiceRef ref;
        ref.mpService = 0;
        cIGZFrameWork_Services* framework = RZGetFramework();
        if (framework) {
            framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService, reinterpret_cast<void**>(&ref.mpService));
        }
        cGZAllocatorServiceCache<Node_b207dc_shapeb06_game>::spService = ref.mpService;
        ref.Release();
    }
    cGZAllocatorServiceCache<Node_b207dc_shapeb06_game>::spService->Deallocate(pBlock);
}

struct View_411fe0_shapeb06_game {
    void* mpData;
    // STUB: 0x00411df0
    void Clear();
    void Fn00411fe0();
};

// FUNCTION: 0x00411fe0
void View_411fe0_shapeb06_game::Fn00411fe0()
{
    Clear();
    void* pBlock = mpData;
    if (!cGZAllocatorServiceCache<Node_b207e0_shapeb06_game>::spService) {
        cGZAllocatorServiceRef ref;
        ref.mpService = 0;
        cIGZFrameWork_Services* framework = RZGetFramework();
        if (framework) {
            framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService, reinterpret_cast<void**>(&ref.mpService));
        }
        cGZAllocatorServiceCache<Node_b207e0_shapeb06_game>::spService = ref.mpService;
        ref.Release();
    }
    cGZAllocatorServiceCache<Node_b207e0_shapeb06_game>::spService->Deallocate(pBlock);
}

struct View_421760_shapeb06_game {
    void* mpData;
    // STUB: 0x00421660
    void Clear();
    void Fn00421760();
};

// FUNCTION: 0x00421760
void View_421760_shapeb06_game::Fn00421760()
{
    Clear();
    void* pBlock = mpData;
    if (!cGZAllocatorServiceCache<Node_b20d58_shapeb06_game>::spService) {
        cGZAllocatorServiceRef ref;
        ref.mpService = 0;
        cIGZFrameWork_Services* framework = RZGetFramework();
        if (framework) {
            framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService, reinterpret_cast<void**>(&ref.mpService));
        }
        cGZAllocatorServiceCache<Node_b20d58_shapeb06_game>::spService = ref.mpService;
        ref.Release();
    }
    cGZAllocatorServiceCache<Node_b20d58_shapeb06_game>::spService->Deallocate(pBlock);
}

struct View_611aa0_shapeb06_game {
    void* mpData;
    // STUB: 0x00611a20
    void Clear();
    void Fn00611aa0();
};

// FUNCTION: 0x00611aa0
void View_611aa0_shapeb06_game::Fn00611aa0()
{
    Clear();
    void* pBlock = mpData;
    if (!cGZAllocatorServiceCache<Node_b45238_shapeb06_game>::spService) {
        cGZAllocatorServiceRef ref;
        ref.mpService = 0;
        cIGZFrameWork_Services* framework = RZGetFramework();
        if (framework) {
            framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService, reinterpret_cast<void**>(&ref.mpService));
        }
        cGZAllocatorServiceCache<Node_b45238_shapeb06_game>::spService = ref.mpService;
        ref.Release();
    }
    cGZAllocatorServiceCache<Node_b45238_shapeb06_game>::spService->Deallocate(pBlock);
}

struct View_413fe0_shapeb06_game {
    void* mpData;
    // STUB: 0x00413e60
    void Clear();
    void Fn00413fe0();
};

// FUNCTION: 0x00413fe0
void View_413fe0_shapeb06_game::Fn00413fe0()
{
    Clear();
    void* pBlock = mpData;
    if (!cGZAllocatorServiceCache<cISC4Occupant*>::spService) {
        cGZAllocatorServiceRef ref;
        ref.mpService = 0;
        cIGZFrameWork_Services* framework = RZGetFramework();
        if (framework) {
            framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService, reinterpret_cast<void**>(&ref.mpService));
        }
        cGZAllocatorServiceCache<cISC4Occupant*>::spService = ref.mpService;
        ref.Release();
    }
    cGZAllocatorServiceCache<cISC4Occupant*>::spService->Deallocate(pBlock);
}

struct Rec_shapeb06_game {
    uint32_t mnLen;
    uint32_t mnCount;
    uint8_t mBuf[16];
    uint32_t mn18;
    uint32_t mn1c;
    uint32_t mn20;
    uint32_t mn24;
};

struct Deque_shapeb06_game {
    uint32_t mPad[4];
    Rec_shapeb06_game* mpCur;
    Rec_shapeb06_game* mpFirst;
    Rec_shapeb06_game* mpLast;
    // STUB: 0x008ecc20
    void PushAux(Rec_shapeb06_game* pItem);
};

struct View_8ee7b0_shapeb06_game {
    uint32_t mPad[2];
    Rec_shapeb06_game mRec;
    Deque_shapeb06_game mDeque;
    // STUB: 0x008ec190
    void Append(uint32_t nCode, uint32_t nShifted, uint32_t* pValue);
    void Fn008ee7b0(uint32_t* pValue, uint32_t nShift);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ee7b0 score 67
void View_8ee7b0_shapeb06_game::Fn008ee7b0(uint32_t* pValue, uint32_t nShift)
{
    Rec_shapeb06_game* pRec = &mRec;
    ++pRec->mnCount;
    pRec->mnLen = 0;
    pRec->mBuf[pRec->mnLen] = 0xf;
    ++pRec->mnLen;
    Append(0xdb, static_cast<uint8_t>(nShift << 3), pValue);
    uint32_t nBit = 0x100 << nShift;
    mRec.mn24 = 2;
    mRec.mn18 = 1;
    mRec.mn1c = nBit | *pValue;
    mRec.mn20 = nBit;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct View_8eeb30_shapeb06_game {
    uint32_t mPad[2];
    Rec_shapeb06_game mRec;
    Deque_shapeb06_game mDeque;
    // STUB: 0x008ec190
    void Append(uint32_t nCode, uint32_t nShifted, uint32_t* pValue);
    void Fn008eeb30(uint32_t* pValue, uint32_t nShift);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008eeb30 score 67
void View_8eeb30_shapeb06_game::Fn008eeb30(uint32_t* pValue, uint32_t nShift)
{
    Rec_shapeb06_game* pRec = &mRec;
    ++pRec->mnCount;
    pRec->mnLen = 0;
    pRec->mBuf[pRec->mnLen] = 0xf;
    ++pRec->mnLen;
    Append(0xed, static_cast<uint8_t>(nShift << 3), pValue);
    uint32_t nBit = 0x100 << nShift;
    mRec.mn24 = 2;
    mRec.mn18 = 1;
    mRec.mn1c = nBit | *pValue;
    mRec.mn20 = nBit;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct View_8eec80_shapeb06_game {
    uint32_t mPad[2];
    Rec_shapeb06_game mRec;
    Deque_shapeb06_game mDeque;
    // STUB: 0x008ec190
    void Append(uint32_t nCode, uint32_t nShifted, uint32_t* pValue);
    void Fn008eec80(uint32_t* pValue, uint32_t nShift);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008eec80 score 67
void View_8eec80_shapeb06_game::Fn008eec80(uint32_t* pValue, uint32_t nShift)
{
    Rec_shapeb06_game* pRec = &mRec;
    ++pRec->mnCount;
    pRec->mnLen = 0;
    pRec->mBuf[pRec->mnLen] = 0xf;
    ++pRec->mnLen;
    Append(0xfe, static_cast<uint8_t>(nShift << 3), pValue);
    uint32_t nBit = 0x100 << nShift;
    mRec.mn24 = 2;
    mRec.mn18 = 1;
    mRec.mn1c = nBit | *pValue;
    mRec.mn20 = nBit;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct View_8eedd0_shapeb06_game {
    uint32_t mPad[2];
    Rec_shapeb06_game mRec;
    Deque_shapeb06_game mDeque;
    // STUB: 0x008ec190
    void Append(uint32_t nCode, uint32_t nShifted, uint32_t* pValue);
    void Fn008eedd0(uint32_t* pValue, uint32_t nShift);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008eedd0 score 67
void View_8eedd0_shapeb06_game::Fn008eedd0(uint32_t* pValue, uint32_t nShift)
{
    Rec_shapeb06_game* pRec = &mRec;
    ++pRec->mnCount;
    pRec->mnLen = 0;
    pRec->mBuf[pRec->mnLen] = 0xf;
    ++pRec->mnLen;
    Append(0xe9, static_cast<uint8_t>(nShift << 3), pValue);
    uint32_t nBit = 0x100 << nShift;
    mRec.mn24 = 2;
    mRec.mn18 = 1;
    mRec.mn1c = nBit | *pValue;
    mRec.mn20 = nBit;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct View_8eee70_shapeb06_game {
    uint32_t mPad[2];
    Rec_shapeb06_game mRec;
    Deque_shapeb06_game mDeque;
    // STUB: 0x008ec190
    void Append(uint32_t nCode, uint32_t nShifted, uint32_t* pValue);
    void Fn008eee70(uint32_t* pValue, uint32_t nShift);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008eee70 score 67
void View_8eee70_shapeb06_game::Fn008eee70(uint32_t* pValue, uint32_t nShift)
{
    Rec_shapeb06_game* pRec = &mRec;
    ++pRec->mnCount;
    pRec->mnLen = 0;
    pRec->mBuf[pRec->mnLen] = 0xf;
    ++pRec->mnLen;
    Append(0xd9, static_cast<uint8_t>(nShift << 3), pValue);
    uint32_t nBit = 0x100 << nShift;
    mRec.mn24 = 2;
    mRec.mn18 = 1;
    mRec.mn1c = nBit | *pValue;
    mRec.mn20 = nBit;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct View_8ef5f0_shapeb06_game {
    uint32_t mPad[2];
    Rec_shapeb06_game mRec;
    Deque_shapeb06_game mDeque;
    // STUB: 0x008ec190
    void Append(uint32_t nCode, uint32_t nShifted, uint32_t* pValue);
    void Fn008ef5f0(uint32_t* pValue, uint32_t nShift);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ef5f0 score 67
void View_8ef5f0_shapeb06_game::Fn008ef5f0(uint32_t* pValue, uint32_t nShift)
{
    Rec_shapeb06_game* pRec = &mRec;
    ++pRec->mnCount;
    pRec->mnLen = 0;
    pRec->mBuf[pRec->mnLen] = 0xf;
    ++pRec->mnLen;
    Append(0xe5, static_cast<uint8_t>(nShift << 3), pValue);
    uint32_t nBit = 0x100 << nShift;
    mRec.mn24 = 2;
    mRec.mn18 = 1;
    mRec.mn1c = nBit | *pValue;
    mRec.mn20 = nBit;
    if (mDeque.mpCur != mDeque.mpLast - 1) {
        if (mDeque.mpCur) {
            *mDeque.mpCur = mRec;
        }
        ++mDeque.mpCur;
    } else {
        mDeque.PushAux(&mRec);
    }
}
#endif

struct Pair_shapeb06_game {
    uint32_t mnA;
    uint32_t mnB;
};

struct Res_shapeb06_game {
    uint32_t mnA;
    uint32_t mnB;
    Res_shapeb06_game() {}
};

// STUB: 0x009ddbf0
Res_shapeb06_game Fn009ddbf0(const Pair_shapeb06_game& first, const Pair_shapeb06_game& second, uint32_t nA, uint32_t nB, uint32_t nC, uint32_t nFlag);

struct View_9ddbc0_shapeb06_game {
    Res_shapeb06_game Fn009ddbc0(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC);
};

// FUNCTION: 0x009ddbc0
Res_shapeb06_game View_9ddbc0_shapeb06_game::Fn009ddbc0(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC)
{
    return Fn009ddbf0(first, second, nA, nB, nC, 0);
}

// STUB: 0x009de4f0
Res_shapeb06_game Fn009de4f0(const Pair_shapeb06_game& first, const Pair_shapeb06_game& second, uint32_t nA, uint32_t nB, uint32_t nC, uint32_t nFlag);

struct View_9de4c0_shapeb06_game {
    Res_shapeb06_game Fn009de4c0(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC);
};

// FUNCTION: 0x009de4c0
Res_shapeb06_game View_9de4c0_shapeb06_game::Fn009de4c0(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC)
{
    return Fn009de4f0(first, second, nA, nB, nC, 0);
}

// STUB: 0x009de7b0
Res_shapeb06_game Fn009de7b0(const Pair_shapeb06_game& first, const Pair_shapeb06_game& second, uint32_t nA, uint32_t nB, uint32_t nC, uint32_t nFlag);

struct View_9de780_shapeb06_game {
    Res_shapeb06_game Fn009de780(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC);
};

// FUNCTION: 0x009de780
Res_shapeb06_game View_9de780_shapeb06_game::Fn009de780(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC)
{
    return Fn009de7b0(first, second, nA, nB, nC, 0);
}

// STUB: 0x009ded40
Res_shapeb06_game Fn009ded40(const Pair_shapeb06_game& first, const Pair_shapeb06_game& second, uint32_t nA, uint32_t nB, uint32_t nC, uint32_t nFlag);

struct View_9ded10_shapeb06_game {
    Res_shapeb06_game Fn009ded10(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC);
};

// FUNCTION: 0x009ded10
Res_shapeb06_game View_9ded10_shapeb06_game::Fn009ded10(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC)
{
    return Fn009ded40(first, second, nA, nB, nC, 0);
}

// STUB: 0x009df690
Res_shapeb06_game Fn009df690(const Pair_shapeb06_game& first, const Pair_shapeb06_game& second, uint32_t nA, uint32_t nB, uint32_t nC, uint32_t nFlag);

struct View_9df660_shapeb06_game {
    Res_shapeb06_game Fn009df660(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC);
};

// FUNCTION: 0x009df660
Res_shapeb06_game View_9df660_shapeb06_game::Fn009df660(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC)
{
    return Fn009df690(first, second, nA, nB, nC, 0);
}

// STUB: 0x009df950
Res_shapeb06_game Fn009df950(const Pair_shapeb06_game& first, const Pair_shapeb06_game& second, uint32_t nA, uint32_t nB, uint32_t nC, uint32_t nFlag);

struct View_9df920_shapeb06_game {
    Res_shapeb06_game Fn009df920(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC);
};

// FUNCTION: 0x009df920
Res_shapeb06_game View_9df920_shapeb06_game::Fn009df920(Pair_shapeb06_game first, Pair_shapeb06_game second, uint32_t nA, uint32_t nB, uint32_t nC)
{
    return Fn009df950(first, second, nA, nB, nC, 0);
}

struct Obj_shapeb06_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Release();
};

struct Node_473ec0_shapeb06_game {
    Node_473ec0_shapeb06_game* mpNext;
    Node_473ec0_shapeb06_game* mpPrev;
    Obj_shapeb06_game* mpObj;
};

struct View_473ec0_shapeb06_game {
    Node_473ec0_shapeb06_game* mpHead;
    void Fn00473ec0();
};

// FUNCTION: 0x00473ec0
void View_473ec0_shapeb06_game::Fn00473ec0()
{
    Node_473ec0_shapeb06_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_473ec0_shapeb06_game* pCur = pNode;
        pNode = pNode->mpNext;
        Obj_shapeb06_game* pObj = pCur->mpObj;
        if (pObj) {
            pObj->Release();
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

struct Node_4e6300_shapeb06_game {
    Node_4e6300_shapeb06_game* mpNext;
    Node_4e6300_shapeb06_game* mpPrev;
    uint8_t mPad[0x18];
    Obj_shapeb06_game* mpObj;
};

struct View_4e6300_shapeb06_game {
    Node_4e6300_shapeb06_game* mpHead;
    void Fn004e6300();
};

// FUNCTION: 0x004e6300
void View_4e6300_shapeb06_game::Fn004e6300()
{
    Node_4e6300_shapeb06_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_4e6300_shapeb06_game* pCur = pNode;
        pNode = pNode->mpNext;
        Obj_shapeb06_game* pObj = pCur->mpObj;
        if (pObj) {
            pObj->Release();
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

struct Node_551fc0_shapeb06_game {
    Node_551fc0_shapeb06_game* mpNext;
    Node_551fc0_shapeb06_game* mpPrev;
    uint8_t mPad[0x2c];
    Obj_shapeb06_game* mpObj;
};

struct View_551fc0_shapeb06_game {
    Node_551fc0_shapeb06_game* mpHead;
    void Fn00551fc0();
};

// FUNCTION: 0x00551fc0
void View_551fc0_shapeb06_game::Fn00551fc0()
{
    Node_551fc0_shapeb06_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_551fc0_shapeb06_game* pCur = pNode;
        pNode = pNode->mpNext;
        Obj_shapeb06_game* pObj = pCur->mpObj;
        if (pObj) {
            pObj->Release();
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

struct Node_57d620_shapeb06_game {
    Node_57d620_shapeb06_game* mpNext;
    Node_57d620_shapeb06_game* mpPrev;
    uint8_t mPad[0x10];
    Obj_shapeb06_game* mpObj;
};

struct View_57d620_shapeb06_game {
    Node_57d620_shapeb06_game* mpHead;
    void Fn0057d620();
};

// FUNCTION: 0x0057d620
void View_57d620_shapeb06_game::Fn0057d620()
{
    Node_57d620_shapeb06_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_57d620_shapeb06_game* pCur = pNode;
        pNode = pNode->mpNext;
        Obj_shapeb06_game* pObj = pCur->mpObj;
        if (pObj) {
            pObj->Release();
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

struct Node_584210_shapeb06_game {
    Node_584210_shapeb06_game* mpNext;
    Node_584210_shapeb06_game* mpPrev;
    uint8_t mPad[0x4];
    Obj_shapeb06_game* mpObj;
};

struct View_584210_shapeb06_game {
    Node_584210_shapeb06_game* mpHead;
    void Fn00584210();
};

// FUNCTION: 0x00584210
void View_584210_shapeb06_game::Fn00584210()
{
    Node_584210_shapeb06_game* pNode = mpHead->mpNext;
    while (pNode != mpHead) {
        Node_584210_shapeb06_game* pCur = pNode;
        pNode = pNode->mpNext;
        Obj_shapeb06_game* pObj = pCur->mpObj;
        if (pObj) {
            pObj->Release();
        }
        _STL::__stl_delete(pCur);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

struct Ref_shapeb06_game {
    virtual void Pad0();
    virtual void AddRef();
};

struct Base_604bc0_shapeb06_game {
    // STUB: 0x0061d060
    bool QueryInterface(uint32_t iid, uint32_t ppv);
};

struct View_604bc0_shapeb06_game : Base_604bc0_shapeb06_game {
    bool Fn00604bc0(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x00604bc0
bool View_604bc0_shapeb06_game::Fn00604bc0(uint32_t iid, uint32_t ppv)
{
    if (iid == 0x49cc1bcd) {
        *reinterpret_cast<void**>(ppv) = this;
        reinterpret_cast<Ref_shapeb06_game*>(this)->AddRef();
        return true;
    }
    return Base_604bc0_shapeb06_game::QueryInterface(iid, ppv);
}

struct Base_61d060_shapeb06_game {
    // STUB: 0x006192c0
    bool QueryInterface(uint32_t iid, uint32_t ppv);
};

struct View_61d060_shapeb06_game : Base_61d060_shapeb06_game {
    bool Fn0061d060(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x0061d060
bool View_61d060_shapeb06_game::Fn0061d060(uint32_t iid, uint32_t ppv)
{
    if (iid == 0x49c1a034) {
        *reinterpret_cast<void**>(ppv) = this;
        reinterpret_cast<Ref_shapeb06_game*>(this)->AddRef();
        return true;
    }
    return Base_61d060_shapeb06_game::QueryInterface(iid, ppv);
}

struct Base_647170_shapeb06_game {
    // STUB: 0x0061d060
    bool QueryInterface(uint32_t iid, uint32_t ppv);
};

struct View_647170_shapeb06_game : Base_647170_shapeb06_game {
    bool Fn00647170(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x00647170
bool View_647170_shapeb06_game::Fn00647170(uint32_t iid, uint32_t ppv)
{
    if (iid == 0x8a4bd52b) {
        *reinterpret_cast<void**>(ppv) = this;
        reinterpret_cast<Ref_shapeb06_game*>(this)->AddRef();
        return true;
    }
    return Base_647170_shapeb06_game::QueryInterface(iid, ppv);
}

struct Base_648080_shapeb06_game {
    // STUB: 0x00654030
    bool QueryInterface(uint32_t iid, uint32_t ppv);
};

struct View_648080_shapeb06_game : Base_648080_shapeb06_game {
    bool Fn00648080(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x00648080
bool View_648080_shapeb06_game::Fn00648080(uint32_t iid, uint32_t ppv)
{
    if (iid == 0xea0a5acf) {
        *reinterpret_cast<void**>(ppv) = this;
        reinterpret_cast<Ref_shapeb06_game*>(this)->AddRef();
        return true;
    }
    return Base_648080_shapeb06_game::QueryInterface(iid, ppv);
}

struct Base_652aa0_shapeb06_game {
    // STUB: 0x00654030
    bool QueryInterface(uint32_t iid, uint32_t ppv);
};

struct View_652aa0_shapeb06_game : Base_652aa0_shapeb06_game {
    bool Fn00652aa0(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x00652aa0
bool View_652aa0_shapeb06_game::Fn00652aa0(uint32_t iid, uint32_t ppv)
{
    if (iid == 0xca15ed6b) {
        *reinterpret_cast<void**>(ppv) = this;
        reinterpret_cast<Ref_shapeb06_game*>(this)->AddRef();
        return true;
    }
    return Base_652aa0_shapeb06_game::QueryInterface(iid, ppv);
}

struct Base_652d00_shapeb06_game {
    // STUB: 0x0065a080
    bool QueryInterface(uint32_t iid, uint32_t ppv);
};

struct View_652d00_shapeb06_game : Base_652d00_shapeb06_game {
    bool Fn00652d00(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x00652d00
bool View_652d00_shapeb06_game::Fn00652d00(uint32_t iid, uint32_t ppv)
{
    if (iid == 0xca16374f) {
        *reinterpret_cast<void**>(ppv) = this;
        reinterpret_cast<Ref_shapeb06_game*>(this)->AddRef();
        return true;
    }
    return Base_652d00_shapeb06_game::QueryInterface(iid, ppv);
}

struct View_45d280_shapeb06_game {
    bool Fn0045d280(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x0045d280
bool View_45d280_shapeb06_game::Fn0045d280(uint32_t iid, uint32_t ppv)
{
    void** out = reinterpret_cast<void**>(ppv);
    Ref_shapeb06_game* self = reinterpret_cast<Ref_shapeb06_game*>(this);
    switch (iid) {
    case 1:
    case 0x6ad4b9f1:
        *out = self;
        self->AddRef();
        return true;
    case 0xe4fda3d4:
        void* p;
        if (this) {
            p = reinterpret_cast<char*>(this) + 0x4;
        } else {
            p = 0;
        }
        *out = p;
        self->AddRef();
        return true;
    }
    return false;
}

struct View_475660_shapeb06_game {
    bool Fn00475660(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x00475660
bool View_475660_shapeb06_game::Fn00475660(uint32_t iid, uint32_t ppv)
{
    void** out = reinterpret_cast<void**>(ppv);
    Ref_shapeb06_game* self = reinterpret_cast<Ref_shapeb06_game*>(this);
    switch (iid) {
    case 1:
    case 0x69f4a803:
        *out = self;
        self->AddRef();
        return true;
    case 0xe4fda3d4:
        void* p;
        if (this) {
            p = reinterpret_cast<char*>(this) + 0x8;
        } else {
            p = 0;
        }
        *out = p;
        self->AddRef();
        return true;
    }
    return false;
}

struct View_4896a0_shapeb06_game {
    bool Fn004896a0(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x004896a0
bool View_4896a0_shapeb06_game::Fn004896a0(uint32_t iid, uint32_t ppv)
{
    void** out = reinterpret_cast<void**>(ppv);
    Ref_shapeb06_game* self = reinterpret_cast<Ref_shapeb06_game*>(this);
    switch (iid) {
    case 1:
    case 0xc8edbec0:
        *out = self;
        self->AddRef();
        return true;
    case 0xe4fda3d4:
        void* p;
        if (this) {
            p = reinterpret_cast<char*>(this) + 0x8;
        } else {
            p = 0;
        }
        *out = p;
        self->AddRef();
        return true;
    }
    return false;
}

struct View_6bf390_shapeb06_game {
    bool Fn006bf390(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x006bf390
bool View_6bf390_shapeb06_game::Fn006bf390(uint32_t iid, uint32_t ppv)
{
    void** out = reinterpret_cast<void**>(ppv);
    Ref_shapeb06_game* self = reinterpret_cast<Ref_shapeb06_game*>(this);
    switch (iid) {
    case 1:
    case 0x6a233069:
        *out = self;
        self->AddRef();
        return true;
    case 0xe4fda3d4:
        void* p;
        if (this) {
            p = reinterpret_cast<char*>(this) + 0x4;
        } else {
            p = 0;
        }
        *out = p;
        self->AddRef();
        return true;
    }
    return false;
}

struct View_6f0e30_shapeb06_game {
    bool Fn006f0e30(uint32_t iid, uint32_t ppv);
};

// FUNCTION: 0x006f0e30
bool View_6f0e30_shapeb06_game::Fn006f0e30(uint32_t iid, uint32_t ppv)
{
    void** out = reinterpret_cast<void**>(ppv);
    Ref_shapeb06_game* self = reinterpret_cast<Ref_shapeb06_game*>(this);
    switch (iid) {
    case 1:
    case 0x89c498be:
        *out = self;
        self->AddRef();
        return true;
    case 0xe4fda3d4:
        void* p;
        if (this) {
            p = reinterpret_cast<char*>(this) + 0x4;
        } else {
            p = 0;
        }
        *out = p;
        self->AddRef();
        return true;
    }
    return false;
}

struct View_5fd630_shapeb06_game {
    uint8_t mPad[0x4];
    float mfValue;
    float Fn005fd630();
};

// FUNCTION: 0x005fd630
float View_5fd630_shapeb06_game::Fn005fd630()
{
    return mfValue;
}

struct View_4abca0_shapeb06_game {
    uint8_t mPad[0x150];
    float mfValue;
    float Fn004abca0();
};

// FUNCTION: 0x004abca0
float View_4abca0_shapeb06_game::Fn004abca0()
{
    return mfValue;
}

struct View_4e0900_shapeb06_game {
    uint8_t mPad[0x118];
    float mfValue;
    float Fn004e0900();
};

// FUNCTION: 0x004e0900
float View_4e0900_shapeb06_game::Fn004e0900()
{
    return mfValue;
}

struct View_623b90_shapeb06_game {
    uint8_t mPad[0x204];
    float mfValue;
    float Fn00623b90();
};

// FUNCTION: 0x00623b90
float View_623b90_shapeb06_game::Fn00623b90()
{
    return mfValue;
}

struct View_6d6e90_shapeb06_game {
    uint8_t mPad[0x60];
    float mfValue;
    float Fn006d6e90();
};

// FUNCTION: 0x006d6e90
float View_6d6e90_shapeb06_game::Fn006d6e90()
{
    return mfValue;
}

// STUB: 0x8929e0
void Fn008929e0(uint32_t value);

// FUNCTION: 0x005f85e0
void Fn005f85e0()
{
    Fn008929e0(0);
}

// STUB: 0x5f87d0
void Fn005f87d0(uint32_t value);

// FUNCTION: 0x005f88c0
void Fn005f88c0()
{
    Fn005f87d0(0);
}

// STUB: 0x865c20
void Fn00865c20(uint32_t value);

// FUNCTION: 0x00865c10
void Fn00865c10()
{
    Fn00865c20(0);
}

// FUNCTION: 0x00407c40
void Fn00407c40()
{
    _STL::__stl_throw_out_of_range("vector");
}

// FUNCTION: 0x0079c6e0
void Fn0079c6e0()
{
    _STL::__stl_throw_length_error("vector");
}

// STUB: 0x0090d91c
void Fn0090d91c(uint32_t value, uint32_t kind);

struct View_55b7c0_shapeb06_game {
    void Slot03(uint32_t value);
};

// FUNCTION: 0x0055b7c0
void View_55b7c0_shapeb06_game::Slot03(uint32_t value)
{
    Fn0090d91c(value, 0x10);
}

struct View_5deb90_shapeb06_game {
    void Slot03(uint32_t value);
};

// FUNCTION: 0x005deb90
void View_5deb90_shapeb06_game::Slot03(uint32_t value)
{
    Fn0090d91c(value, 0xe);
}

struct View_5e56b0_shapeb06_game {
    void Slot03(uint32_t value);
};

// FUNCTION: 0x005e56b0
void View_5e56b0_shapeb06_game::Slot03(uint32_t value)
{
    Fn0090d91c(value, 0xb);
}

struct View_5e5710_shapeb06_game {
    void Slot03(uint32_t value);
};

// FUNCTION: 0x005e5710
void View_5e5710_shapeb06_game::Slot03(uint32_t value)
{
    Fn0090d91c(value, 0xc);
}

struct View_5e5770_shapeb06_game {
    void Slot03(uint32_t value);
};

// FUNCTION: 0x005e5770
void View_5e5770_shapeb06_game::Slot03(uint32_t value)
{
    Fn0090d91c(value, 0xd);
}

struct View_5e5810_shapeb06_game {
    void Slot03(uint32_t value);
};

// FUNCTION: 0x005e5810
void View_5e5810_shapeb06_game::Slot03(uint32_t value)
{
    Fn0090d91c(value, 0xf);
}

struct Iface_45f9f0_shapeb06_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void SlotA();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
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
    virtual void SlotB(uint32_t value);
};

struct View_45f9f0_shapeb06_game {
    void Fn0045f9f0();
};

// FUNCTION: 0x0045f9f0
void View_45f9f0_shapeb06_game::Fn0045f9f0()
{
    Iface_45f9f0_shapeb06_game* p = reinterpret_cast<Iface_45f9f0_shapeb06_game*>(this);
    p->SlotA();
    p->SlotB(1);
}

struct Iface_5b9dd0_shapeb06_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void SlotB(uint32_t value);
    virtual void Pad4();
    virtual void SlotA();
};

struct View_5b9dd0_shapeb06_game {
    void Fn005b9dd0();
};

// FUNCTION: 0x005b9dd0
void View_5b9dd0_shapeb06_game::Fn005b9dd0()
{
    Iface_5b9dd0_shapeb06_game* p = reinterpret_cast<Iface_5b9dd0_shapeb06_game*>(this);
    p->SlotA();
    p->SlotB(1);
}

struct Iface_5fb0e0_shapeb06_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void SlotA();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
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
    virtual void SlotB(uint32_t value);
};

struct View_5fb0e0_shapeb06_game {
    void Fn005fb0e0();
};

// FUNCTION: 0x005fb0e0
void View_5fb0e0_shapeb06_game::Fn005fb0e0()
{
    Iface_5fb0e0_shapeb06_game* p = reinterpret_cast<Iface_5fb0e0_shapeb06_game*>(this);
    p->SlotA();
    p->SlotB(1);
}

struct Iface_6e8fb0_shapeb06_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void SlotA();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void SlotB(uint32_t value);
};

struct View_6e8fb0_shapeb06_game {
    void Fn006e8fb0();
};

// FUNCTION: 0x006e8fb0
void View_6e8fb0_shapeb06_game::Fn006e8fb0()
{
    Iface_6e8fb0_shapeb06_game* p = reinterpret_cast<Iface_6e8fb0_shapeb06_game*>(this);
    p->SlotA();
    p->SlotB(1);
}

struct Iface_81e880_shapeb06_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void SlotA();
    virtual void SlotB(uint32_t value);
};

struct View_81e880_shapeb06_game {
    void Fn0081e880();
};

// FUNCTION: 0x0081e880
void View_81e880_shapeb06_game::Fn0081e880()
{
    Iface_81e880_shapeb06_game* p = reinterpret_cast<Iface_81e880_shapeb06_game*>(this);
    p->SlotA();
    p->SlotB(1);
}

// STUB: 0x00988f60
void Fn00988f60(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);

struct View_9895f0_shapeb06_game {
    void Fn009895f0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
};

// FUNCTION: 0x009895f0
void View_9895f0_shapeb06_game::Fn009895f0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn00988f60(a, b, c, d, e, f);
}

// STUB: 0x00989000
void Fn00989000(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);

struct View_989620_shapeb06_game {
    void Fn00989620(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
};

// FUNCTION: 0x00989620
void View_989620_shapeb06_game::Fn00989620(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn00989000(a, b, c, d, e, f);
}

// STUB: 0x009890a0
void Fn009890a0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);

struct View_989650_shapeb06_game {
    void Fn00989650(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
};

// FUNCTION: 0x00989650
void View_989650_shapeb06_game::Fn00989650(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn009890a0(a, b, c, d, e, f);
}

// STUB: 0x00989320
void Fn00989320(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);

struct View_989770_shapeb06_game {
    void Fn00989770(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
};

// FUNCTION: 0x00989770
void View_989770_shapeb06_game::Fn00989770(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn00989320(a, b, c, d, e, f);
}

// STUB: 0x009893c0
void Fn009893c0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);

struct View_9897a0_shapeb06_game {
    void Fn009897a0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
};

// FUNCTION: 0x009897a0
void View_9897a0_shapeb06_game::Fn009897a0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn009893c0(a, b, c, d, e, f);
}

// STUB: 0x00989500
void Fn00989500(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);

struct View_989800_shapeb06_game {
    void Fn00989800(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
};

// FUNCTION: 0x00989800
void View_989800_shapeb06_game::Fn00989800(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    Fn00989500(a, b, c, d, e, f);
}

// STUB: 0x008d1030
void Fn008d1030(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f);

// FUNCTION: 0x0080a6a0
void Fn0080a6a0(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f)
{
    Fn008d1030(a, c, b, e >> 2, e >> 2, f >> 2);
}

// STUB: 0x008d1a30
void Fn008d1a30(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f);

// FUNCTION: 0x0080a6d0
void Fn0080a6d0(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f)
{
    Fn008d1a30(a, c, b, e >> 2, e >> 2, f >> 2);
}

// STUB: 0x008d1f80
void Fn008d1f80(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f);

// FUNCTION: 0x0088cf90
void Fn0088cf90(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f)
{
    Fn008d1f80(a, c, b, e >> 2, e >> 2, f >> 2);
}

// STUB: 0x008d2140
void Fn008d2140(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f);

// FUNCTION: 0x0088cfc0
void Fn0088cfc0(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f)
{
    Fn008d2140(a, c, b, e >> 2, e >> 2, f >> 2);
}

// STUB: 0x008d1240
void Fn008d1240(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f);

// FUNCTION: 0x0088cff0
void Fn0088cff0(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f)
{
    Fn008d1240(a, c, b, e >> 2, e >> 2, f >> 2);
}

// STUB: 0x008d1630
void Fn008d1630(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f);

// FUNCTION: 0x0088d020
void Fn0088d020(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f)
{
    Fn008d1630(a, c, b, e >> 2, e >> 2, f >> 2);
}

namespace _STL {
    // STUB: 0x0090cf54
    void* __stl_new(unsigned int size);
}

struct CNode_418e00_shapeb06_game {
    uint8_t mcColor;
    CNode_418e00_shapeb06_game* mpParent;
    CNode_418e00_shapeb06_game* mpLeft;
    CNode_418e00_shapeb06_game* mpRight;
    int32_t mnValue;
};

struct View_418e00_shapeb06_game {
    CNode_418e00_shapeb06_game* Fn00418e00(CNode_418e00_shapeb06_game* pX, CNode_418e00_shapeb06_game* pParent);
};

// FUNCTION: 0x00418e00
CNode_418e00_shapeb06_game* View_418e00_shapeb06_game::Fn00418e00(CNode_418e00_shapeb06_game* pX, CNode_418e00_shapeb06_game* pParent)
{
    CNode_418e00_shapeb06_game* pTop = static_cast<CNode_418e00_shapeb06_game*>(_STL::__stl_new(0x14));
    new (&pTop->mnValue) int32_t(pX->mnValue);
    pTop->mcColor = pX->mcColor;
    pTop->mpLeft = 0;
    pTop->mpRight = 0;
    pTop->mpParent = pParent;
    if (pX->mpRight) {
        pTop->mpRight = Fn00418e00(pX->mpRight, pTop);
    }
    CNode_418e00_shapeb06_game* pCur = pTop;
    pX = pX->mpLeft;
    while (pX) {
        CNode_418e00_shapeb06_game* pNew = static_cast<CNode_418e00_shapeb06_game*>(_STL::__stl_new(0x14));
        new (&pNew->mnValue) int32_t(pX->mnValue);
        pNew->mcColor = pX->mcColor;
        pNew->mpLeft = 0;
        pNew->mpRight = 0;
        pCur->mpLeft = pNew;
        pNew->mpParent = pCur;
        if (pX->mpRight) {
            pNew->mpRight = Fn00418e00(pX->mpRight, pNew);
        }
        pCur = pNew;
        pX = pX->mpLeft;
    }
    return pTop;
}

struct CNode_690ae0_shapeb06_game {
    uint8_t mcColor;
    CNode_690ae0_shapeb06_game* mpParent;
    CNode_690ae0_shapeb06_game* mpLeft;
    CNode_690ae0_shapeb06_game* mpRight;
    int32_t mnValue;
};

struct View_690ae0_shapeb06_game {
    CNode_690ae0_shapeb06_game* Fn00690ae0(CNode_690ae0_shapeb06_game* pX, CNode_690ae0_shapeb06_game* pParent);
};

// FUNCTION: 0x00690ae0
CNode_690ae0_shapeb06_game* View_690ae0_shapeb06_game::Fn00690ae0(CNode_690ae0_shapeb06_game* pX, CNode_690ae0_shapeb06_game* pParent)
{
    CNode_690ae0_shapeb06_game* pTop = static_cast<CNode_690ae0_shapeb06_game*>(_STL::__stl_new(0x14));
    new (&pTop->mnValue) int32_t(pX->mnValue);
    pTop->mcColor = pX->mcColor;
    pTop->mpLeft = 0;
    pTop->mpRight = 0;
    pTop->mpParent = pParent;
    if (pX->mpRight) {
        pTop->mpRight = Fn00690ae0(pX->mpRight, pTop);
    }
    CNode_690ae0_shapeb06_game* pCur = pTop;
    pX = pX->mpLeft;
    while (pX) {
        CNode_690ae0_shapeb06_game* pNew = static_cast<CNode_690ae0_shapeb06_game*>(_STL::__stl_new(0x14));
        new (&pNew->mnValue) int32_t(pX->mnValue);
        pNew->mcColor = pX->mcColor;
        pNew->mpLeft = 0;
        pNew->mpRight = 0;
        pCur->mpLeft = pNew;
        pNew->mpParent = pCur;
        if (pX->mpRight) {
            pNew->mpRight = Fn00690ae0(pX->mpRight, pNew);
        }
        pCur = pNew;
        pX = pX->mpLeft;
    }
    return pTop;
}

struct CNode_705380_shapeb06_game {
    uint8_t mcColor;
    CNode_705380_shapeb06_game* mpParent;
    CNode_705380_shapeb06_game* mpLeft;
    CNode_705380_shapeb06_game* mpRight;
    int32_t mnValue;
};

struct View_705380_shapeb06_game {
    CNode_705380_shapeb06_game* Fn00705380(CNode_705380_shapeb06_game* pX, CNode_705380_shapeb06_game* pParent);
};

// FUNCTION: 0x00705380
CNode_705380_shapeb06_game* View_705380_shapeb06_game::Fn00705380(CNode_705380_shapeb06_game* pX, CNode_705380_shapeb06_game* pParent)
{
    CNode_705380_shapeb06_game* pTop = static_cast<CNode_705380_shapeb06_game*>(_STL::__stl_new(0x14));
    new (&pTop->mnValue) int32_t(pX->mnValue);
    pTop->mcColor = pX->mcColor;
    pTop->mpLeft = 0;
    pTop->mpRight = 0;
    pTop->mpParent = pParent;
    if (pX->mpRight) {
        pTop->mpRight = Fn00705380(pX->mpRight, pTop);
    }
    CNode_705380_shapeb06_game* pCur = pTop;
    pX = pX->mpLeft;
    while (pX) {
        CNode_705380_shapeb06_game* pNew = static_cast<CNode_705380_shapeb06_game*>(_STL::__stl_new(0x14));
        new (&pNew->mnValue) int32_t(pX->mnValue);
        pNew->mcColor = pX->mcColor;
        pNew->mpLeft = 0;
        pNew->mpRight = 0;
        pCur->mpLeft = pNew;
        pNew->mpParent = pCur;
        if (pX->mpRight) {
            pNew->mpRight = Fn00705380(pX->mpRight, pNew);
        }
        pCur = pNew;
        pX = pX->mpLeft;
    }
    return pTop;
}

struct CNode_705430_shapeb06_game {
    uint8_t mcColor;
    CNode_705430_shapeb06_game* mpParent;
    CNode_705430_shapeb06_game* mpLeft;
    CNode_705430_shapeb06_game* mpRight;
    int32_t mnValue;
};

struct View_705430_shapeb06_game {
    CNode_705430_shapeb06_game* Fn00705430(CNode_705430_shapeb06_game* pX, CNode_705430_shapeb06_game* pParent);
};

// FUNCTION: 0x00705430
CNode_705430_shapeb06_game* View_705430_shapeb06_game::Fn00705430(CNode_705430_shapeb06_game* pX, CNode_705430_shapeb06_game* pParent)
{
    CNode_705430_shapeb06_game* pTop = static_cast<CNode_705430_shapeb06_game*>(_STL::__stl_new(0x14));
    new (&pTop->mnValue) int32_t(pX->mnValue);
    pTop->mcColor = pX->mcColor;
    pTop->mpLeft = 0;
    pTop->mpRight = 0;
    pTop->mpParent = pParent;
    if (pX->mpRight) {
        pTop->mpRight = Fn00705430(pX->mpRight, pTop);
    }
    CNode_705430_shapeb06_game* pCur = pTop;
    pX = pX->mpLeft;
    while (pX) {
        CNode_705430_shapeb06_game* pNew = static_cast<CNode_705430_shapeb06_game*>(_STL::__stl_new(0x14));
        new (&pNew->mnValue) int32_t(pX->mnValue);
        pNew->mcColor = pX->mcColor;
        pNew->mpLeft = 0;
        pNew->mpRight = 0;
        pCur->mpLeft = pNew;
        pNew->mpParent = pCur;
        if (pX->mpRight) {
            pNew->mpRight = Fn00705430(pX->mpRight, pNew);
        }
        pCur = pNew;
        pX = pX->mpLeft;
    }
    return pTop;
}

struct CNode_78e560_shapeb06_game {
    uint8_t mcColor;
    CNode_78e560_shapeb06_game* mpParent;
    CNode_78e560_shapeb06_game* mpLeft;
    CNode_78e560_shapeb06_game* mpRight;
    int32_t mnValue;
};

struct View_78e560_shapeb06_game {
    CNode_78e560_shapeb06_game* Fn0078e560(CNode_78e560_shapeb06_game* pX, CNode_78e560_shapeb06_game* pParent);
};

// FUNCTION: 0x0078e560
CNode_78e560_shapeb06_game* View_78e560_shapeb06_game::Fn0078e560(CNode_78e560_shapeb06_game* pX, CNode_78e560_shapeb06_game* pParent)
{
    CNode_78e560_shapeb06_game* pTop = static_cast<CNode_78e560_shapeb06_game*>(_STL::__stl_new(0x14));
    new (&pTop->mnValue) int32_t(pX->mnValue);
    pTop->mcColor = pX->mcColor;
    pTop->mpLeft = 0;
    pTop->mpRight = 0;
    pTop->mpParent = pParent;
    if (pX->mpRight) {
        pTop->mpRight = Fn0078e560(pX->mpRight, pTop);
    }
    CNode_78e560_shapeb06_game* pCur = pTop;
    pX = pX->mpLeft;
    while (pX) {
        CNode_78e560_shapeb06_game* pNew = static_cast<CNode_78e560_shapeb06_game*>(_STL::__stl_new(0x14));
        new (&pNew->mnValue) int32_t(pX->mnValue);
        pNew->mcColor = pX->mcColor;
        pNew->mpLeft = 0;
        pNew->mpRight = 0;
        pCur->mpLeft = pNew;
        pNew->mpParent = pCur;
        if (pX->mpRight) {
            pNew->mpRight = Fn0078e560(pX->mpRight, pNew);
        }
        pCur = pNew;
        pX = pX->mpLeft;
    }
    return pTop;
}

struct SubNode_shapeb06_game {
    uint32_t mnColor;
    SubNode_shapeb06_game* mpRoot;
    SubNode_shapeb06_game* mpLeft;
    SubNode_shapeb06_game* mpRight;
};

struct Sub_5d2fe0_shapeb06_game {
    SubNode_shapeb06_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x005d2880
    void Erase(SubNode_shapeb06_game* pNode);
};

struct Node_5d2fe0_shapeb06_game {
    uint32_t mnColor;
    Node_5d2fe0_shapeb06_game* mpParent;
    Node_5d2fe0_shapeb06_game* mpLeft;
    Node_5d2fe0_shapeb06_game* mpRight;
    uint8_t mPad[0xc];
    Sub_5d2fe0_shapeb06_game mSub;
};

struct View_5d2fe0_shapeb06_game {
    void Fn005d2fe0(Node_5d2fe0_shapeb06_game* pNode);
};

// FUNCTION: 0x005d2fe0
void View_5d2fe0_shapeb06_game::Fn005d2fe0(Node_5d2fe0_shapeb06_game* pNode)
{
    while (pNode) {
        Fn005d2fe0(pNode->mpRight);
        Node_5d2fe0_shapeb06_game* pNext = pNode->mpLeft;
        Sub_5d2fe0_shapeb06_game* pSub = &pNode->mSub;
        if (pSub->mnCount != 0) {
            pSub->Erase(pSub->mpHead->mpRoot);
            pSub->mpHead->mpLeft = pSub->mpHead;
            pSub->mpHead->mpRoot = 0;
            pSub->mpHead->mpRight = pSub->mpHead;
            pSub->mnCount = 0;
        }
        if (pSub->mpHead) {
            _STL::__stl_delete(pSub->mpHead);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}

struct Sub_672260_shapeb06_game {
    SubNode_shapeb06_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0066f6a0
    void Erase(SubNode_shapeb06_game* pNode);
};

struct Node_672260_shapeb06_game {
    uint32_t mnColor;
    Node_672260_shapeb06_game* mpParent;
    Node_672260_shapeb06_game* mpLeft;
    Node_672260_shapeb06_game* mpRight;
    uint8_t mPad[0x4];
    Sub_672260_shapeb06_game mSub;
};

struct View_672260_shapeb06_game {
    void Fn00672260(Node_672260_shapeb06_game* pNode);
};

// FUNCTION: 0x00672260
void View_672260_shapeb06_game::Fn00672260(Node_672260_shapeb06_game* pNode)
{
    while (pNode) {
        Fn00672260(pNode->mpRight);
        Node_672260_shapeb06_game* pNext = pNode->mpLeft;
        Sub_672260_shapeb06_game* pSub = &pNode->mSub;
        if (pSub->mnCount != 0) {
            pSub->Erase(pSub->mpHead->mpRoot);
            pSub->mpHead->mpLeft = pSub->mpHead;
            pSub->mpHead->mpRoot = 0;
            pSub->mpHead->mpRight = pSub->mpHead;
            pSub->mnCount = 0;
        }
        if (pSub->mpHead) {
            _STL::__stl_delete(pSub->mpHead);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}

struct Sub_6722e0_shapeb06_game {
    SubNode_shapeb06_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0066f6f0
    void Erase(SubNode_shapeb06_game* pNode);
};

struct Node_6722e0_shapeb06_game {
    uint32_t mnColor;
    Node_6722e0_shapeb06_game* mpParent;
    Node_6722e0_shapeb06_game* mpLeft;
    Node_6722e0_shapeb06_game* mpRight;
    uint8_t mPad[0x4];
    Sub_6722e0_shapeb06_game mSub;
};

struct View_6722e0_shapeb06_game {
    void Fn006722e0(Node_6722e0_shapeb06_game* pNode);
};

// FUNCTION: 0x006722e0
void View_6722e0_shapeb06_game::Fn006722e0(Node_6722e0_shapeb06_game* pNode)
{
    while (pNode) {
        Fn006722e0(pNode->mpRight);
        Node_6722e0_shapeb06_game* pNext = pNode->mpLeft;
        Sub_6722e0_shapeb06_game* pSub = &pNode->mSub;
        if (pSub->mnCount != 0) {
            pSub->Erase(pSub->mpHead->mpRoot);
            pSub->mpHead->mpLeft = pSub->mpHead;
            pSub->mpHead->mpRoot = 0;
            pSub->mpHead->mpRight = pSub->mpHead;
            pSub->mnCount = 0;
        }
        if (pSub->mpHead) {
            _STL::__stl_delete(pSub->mpHead);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}

struct Sub_70c3f0_shapeb06_game {
    SubNode_shapeb06_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0070be40
    void Erase(SubNode_shapeb06_game* pNode);
};

struct Node_70c3f0_shapeb06_game {
    uint32_t mnColor;
    Node_70c3f0_shapeb06_game* mpParent;
    Node_70c3f0_shapeb06_game* mpLeft;
    Node_70c3f0_shapeb06_game* mpRight;
    uint8_t mPad[0x4];
    Sub_70c3f0_shapeb06_game mSub;
};

struct View_70c3f0_shapeb06_game {
    void Fn0070c3f0(Node_70c3f0_shapeb06_game* pNode);
};

// FUNCTION: 0x0070c3f0
void View_70c3f0_shapeb06_game::Fn0070c3f0(Node_70c3f0_shapeb06_game* pNode)
{
    while (pNode) {
        Fn0070c3f0(pNode->mpRight);
        Node_70c3f0_shapeb06_game* pNext = pNode->mpLeft;
        Sub_70c3f0_shapeb06_game* pSub = &pNode->mSub;
        if (pSub->mnCount != 0) {
            pSub->Erase(pSub->mpHead->mpRoot);
            pSub->mpHead->mpLeft = pSub->mpHead;
            pSub->mpHead->mpRoot = 0;
            pSub->mpHead->mpRight = pSub->mpHead;
            pSub->mnCount = 0;
        }
        if (pSub->mpHead) {
            _STL::__stl_delete(pSub->mpHead);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}

struct Sub_734580_shapeb06_game {
    SubNode_shapeb06_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x00732830
    void Erase(SubNode_shapeb06_game* pNode);
};

struct Node_734580_shapeb06_game {
    uint32_t mnColor;
    Node_734580_shapeb06_game* mpParent;
    Node_734580_shapeb06_game* mpLeft;
    Node_734580_shapeb06_game* mpRight;
    uint8_t mPad[0x4];
    Sub_734580_shapeb06_game mSub;
};

struct View_734580_shapeb06_game {
    void Fn00734580(Node_734580_shapeb06_game* pNode);
};

// FUNCTION: 0x00734580
void View_734580_shapeb06_game::Fn00734580(Node_734580_shapeb06_game* pNode)
{
    while (pNode) {
        Fn00734580(pNode->mpRight);
        Node_734580_shapeb06_game* pNext = pNode->mpLeft;
        Sub_734580_shapeb06_game* pSub = &pNode->mSub;
        if (pSub->mnCount != 0) {
            pSub->Erase(pSub->mpHead->mpRoot);
            pSub->mpHead->mpLeft = pSub->mpHead;
            pSub->mpHead->mpRoot = 0;
            pSub->mpHead->mpRight = pSub->mpHead;
            pSub->mnCount = 0;
        }
        if (pSub->mpHead) {
            _STL::__stl_delete(pSub->mpHead);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}

struct Sub_734600_shapeb06_game {
    SubNode_shapeb06_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x00734580
    void Erase(SubNode_shapeb06_game* pNode);
};

struct Node_734600_shapeb06_game {
    uint32_t mnColor;
    Node_734600_shapeb06_game* mpParent;
    Node_734600_shapeb06_game* mpLeft;
    Node_734600_shapeb06_game* mpRight;
    uint8_t mPad[0x4];
    Sub_734600_shapeb06_game mSub;
};

struct View_734600_shapeb06_game {
    void Fn00734600(Node_734600_shapeb06_game* pNode);
};

// FUNCTION: 0x00734600
void View_734600_shapeb06_game::Fn00734600(Node_734600_shapeb06_game* pNode)
{
    while (pNode) {
        Fn00734600(pNode->mpRight);
        Node_734600_shapeb06_game* pNext = pNode->mpLeft;
        Sub_734600_shapeb06_game* pSub = &pNode->mSub;
        if (pSub->mnCount != 0) {
            pSub->Erase(pSub->mpHead->mpRoot);
            pSub->mpHead->mpLeft = pSub->mpHead;
            pSub->mpHead->mpRoot = 0;
            pSub->mpHead->mpRight = pSub->mpHead;
            pSub->mnCount = 0;
        }
        if (pSub->mpHead) {
            _STL::__stl_delete(pSub->mpHead);
        }
        _STL::__stl_delete(pNode);
        pNode = pNext;
    }
}

struct TNode_shapeb06_game {
    uint32_t mnColor;
    TNode_shapeb06_game* mpParent;
    TNode_shapeb06_game* mpLeft;
    TNode_shapeb06_game* mpRight;
    int32_t mnKey;
};

struct TIter_432c80_shapeb06_game {
    TNode_shapeb06_game* mpNode;
    TIter_432c80_shapeb06_game(TNode_shapeb06_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_432c80_shapeb06_game {
    TNode_shapeb06_game* mpNode;
    bool mbInserted;
    TRes_432c80_shapeb06_game(TNode_shapeb06_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

struct View_432c80_shapeb06_game {
    TNode_shapeb06_game* mpHead;
    // STUB: 0x004322f0
    TIter_432c80_shapeb06_game Insert(TNode_shapeb06_game* pX, TNode_shapeb06_game* pY, const int32_t* pValue, uint32_t nFlag);
    TRes_432c80_shapeb06_game Fn00432c80(const int32_t* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00432c80 score 39
TRes_432c80_shapeb06_game View_432c80_shapeb06_game::Fn00432c80(const int32_t* pValue)
{
    TNode_shapeb06_game* pHead = mpHead;
    TNode_shapeb06_game* pX = pHead->mpParent;
    TNode_shapeb06_game* pY = pHead;
    bool bLess = true;
    for (; pX; ) {
        pY = pX;
        bLess = *pValue < pX->mnKey;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_432c80_shapeb06_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_432c80_shapeb06_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    if (it.mpNode->mnKey < *pValue) {
        return TRes_432c80_shapeb06_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_432c80_shapeb06_game(it.mpNode, false);
}
#endif

struct TIter_4a85a0_shapeb06_game {
    TNode_shapeb06_game* mpNode;
    TIter_4a85a0_shapeb06_game(TNode_shapeb06_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_4a85a0_shapeb06_game {
    TNode_shapeb06_game* mpNode;
    bool mbInserted;
    TRes_4a85a0_shapeb06_game(TNode_shapeb06_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

struct View_4a85a0_shapeb06_game {
    TNode_shapeb06_game* mpHead;
    // STUB: 0x004a83a0
    TIter_4a85a0_shapeb06_game Insert(TNode_shapeb06_game* pX, TNode_shapeb06_game* pY, const int32_t* pValue, uint32_t nFlag);
    TRes_4a85a0_shapeb06_game Fn004a85a0(const int32_t* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004a85a0 score 39
TRes_4a85a0_shapeb06_game View_4a85a0_shapeb06_game::Fn004a85a0(const int32_t* pValue)
{
    TNode_shapeb06_game* pHead = mpHead;
    TNode_shapeb06_game* pX = pHead->mpParent;
    TNode_shapeb06_game* pY = pHead;
    bool bLess = true;
    for (; pX; ) {
        pY = pX;
        bLess = *pValue < pX->mnKey;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_4a85a0_shapeb06_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_4a85a0_shapeb06_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    if (it.mpNode->mnKey < *pValue) {
        return TRes_4a85a0_shapeb06_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_4a85a0_shapeb06_game(it.mpNode, false);
}
#endif

struct TIter_4a9d20_shapeb06_game {
    TNode_shapeb06_game* mpNode;
    TIter_4a9d20_shapeb06_game(TNode_shapeb06_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_4a9d20_shapeb06_game {
    TNode_shapeb06_game* mpNode;
    bool mbInserted;
    TRes_4a9d20_shapeb06_game(TNode_shapeb06_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

struct View_4a9d20_shapeb06_game {
    TNode_shapeb06_game* mpHead;
    // STUB: 0x004a9c50
    TIter_4a9d20_shapeb06_game Insert(TNode_shapeb06_game* pX, TNode_shapeb06_game* pY, const int32_t* pValue, uint32_t nFlag);
    TRes_4a9d20_shapeb06_game Fn004a9d20(const int32_t* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004a9d20 score 39
TRes_4a9d20_shapeb06_game View_4a9d20_shapeb06_game::Fn004a9d20(const int32_t* pValue)
{
    TNode_shapeb06_game* pHead = mpHead;
    TNode_shapeb06_game* pX = pHead->mpParent;
    TNode_shapeb06_game* pY = pHead;
    bool bLess = true;
    for (; pX; ) {
        pY = pX;
        bLess = *pValue < pX->mnKey;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_4a9d20_shapeb06_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_4a9d20_shapeb06_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    if (it.mpNode->mnKey < *pValue) {
        return TRes_4a9d20_shapeb06_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_4a9d20_shapeb06_game(it.mpNode, false);
}
#endif

struct TIter_63dc70_shapeb06_game {
    TNode_shapeb06_game* mpNode;
    TIter_63dc70_shapeb06_game(TNode_shapeb06_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_63dc70_shapeb06_game {
    TNode_shapeb06_game* mpNode;
    bool mbInserted;
    TRes_63dc70_shapeb06_game(TNode_shapeb06_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

struct View_63dc70_shapeb06_game {
    TNode_shapeb06_game* mpHead;
    // STUB: 0x0063dae0
    TIter_63dc70_shapeb06_game Insert(TNode_shapeb06_game* pX, TNode_shapeb06_game* pY, const int32_t* pValue, uint32_t nFlag);
    TRes_63dc70_shapeb06_game Fn0063dc70(const int32_t* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0063dc70 score 39
TRes_63dc70_shapeb06_game View_63dc70_shapeb06_game::Fn0063dc70(const int32_t* pValue)
{
    TNode_shapeb06_game* pHead = mpHead;
    TNode_shapeb06_game* pX = pHead->mpParent;
    TNode_shapeb06_game* pY = pHead;
    bool bLess = true;
    for (; pX; ) {
        pY = pX;
        bLess = *pValue < pX->mnKey;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_63dc70_shapeb06_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_63dc70_shapeb06_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    if (it.mpNode->mnKey < *pValue) {
        return TRes_63dc70_shapeb06_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_63dc70_shapeb06_game(it.mpNode, false);
}
#endif

struct TIter_70cb90_shapeb06_game {
    TNode_shapeb06_game* mpNode;
    TIter_70cb90_shapeb06_game(TNode_shapeb06_game* pNode) : mpNode(pNode) {}
    // STUB: 0x006809e0
    void Dec();
};

struct TRes_70cb90_shapeb06_game {
    TNode_shapeb06_game* mpNode;
    bool mbInserted;
    TRes_70cb90_shapeb06_game(TNode_shapeb06_game* pNode, bool bInserted) : mpNode(pNode), mbInserted(bInserted) {}
};

struct View_70cb90_shapeb06_game {
    TNode_shapeb06_game* mpHead;
    // STUB: 0x0070cac0
    TIter_70cb90_shapeb06_game Insert(TNode_shapeb06_game* pX, TNode_shapeb06_game* pY, const int32_t* pValue, uint32_t nFlag);
    TRes_70cb90_shapeb06_game Fn0070cb90(const int32_t* pValue);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0070cb90 score 39
TRes_70cb90_shapeb06_game View_70cb90_shapeb06_game::Fn0070cb90(const int32_t* pValue)
{
    TNode_shapeb06_game* pHead = mpHead;
    TNode_shapeb06_game* pX = pHead->mpParent;
    TNode_shapeb06_game* pY = pHead;
    bool bLess = true;
    for (; pX; ) {
        pY = pX;
        bLess = *pValue < pX->mnKey;
        pX = bLess ? pX->mpLeft : pX->mpRight;
    }
    TIter_70cb90_shapeb06_game it(pY);
    if (bLess) {
        if (pY == pHead->mpLeft) {
            return TRes_70cb90_shapeb06_game(Insert(pX, pY, pValue, 0).mpNode, true);
        }
        it.Dec();
    }
    if (it.mpNode->mnKey < *pValue) {
        return TRes_70cb90_shapeb06_game(Insert(pX, pY, pValue, 0).mpNode, true);
    }
    return TRes_70cb90_shapeb06_game(it.mpNode, false);
}
#endif

