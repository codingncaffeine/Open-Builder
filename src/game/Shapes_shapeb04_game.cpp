// Shape families of packet shapeb04_game, written by scratch/s16/gen/shapeb04_game/gen.py.
#include "common/types.h"
#include "common/compiler.h"

// A field of a view by its offset from the object start.
#define AT_shapeb04_game(T, p, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(p) + (off)))

struct View_004f6240_shapeb04_game {
    bool Get();
};

// FUNCTION: 0x004f6240
bool View_004f6240_shapeb04_game::Get()
{
    return AT_shapeb04_game(bool, this, 0x80);
}

struct View_005f1a60_shapeb04_game {
    bool Get();
};

// FUNCTION: 0x005f1a60
bool View_005f1a60_shapeb04_game::Get()
{
    return AT_shapeb04_game(bool, this, 0x1a5);
}

struct View_00604de0_shapeb04_game {
    bool Get();
};

// FUNCTION: 0x00604de0
bool View_00604de0_shapeb04_game::Get()
{
    return AT_shapeb04_game(bool, this, 0x104);
}

struct View_00619880_shapeb04_game {
    bool Get();
};

// FUNCTION: 0x00619880
bool View_00619880_shapeb04_game::Get()
{
    return AT_shapeb04_game(bool, this, 0x105);
}

struct View_00649240_shapeb04_game {
    bool Get();
};

// FUNCTION: 0x00649240
bool View_00649240_shapeb04_game::Get()
{
    return AT_shapeb04_game(bool, this, 0x118);
}

struct View_00764820_shapeb04_game {
    bool Get();
};

// FUNCTION: 0x00764820
bool View_00764820_shapeb04_game::Get()
{
    return AT_shapeb04_game(bool, this, 0x19d);
}

struct View_0076b6a0_shapeb04_game {
    bool Get();
};

// FUNCTION: 0x0076b6a0
bool View_0076b6a0_shapeb04_game::Get()
{
    return AT_shapeb04_game(bool, this, 0x28);
}

struct Tgt_007c22d0_shapeb04_game {
    // STUB: 0x7ce080
    void Run();
};

struct View_007c22d0_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x007c22d0
void View_007c22d0_shapeb04_game::Fwd()
{
    AT_shapeb04_game(Tgt_007c22d0_shapeb04_game*, this, 0x8c)->Run();
}

struct Tgt_007c22e0_shapeb04_game {
    // STUB: 0x7ce0e0
    void Run();
};

struct View_007c22e0_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x007c22e0
void View_007c22e0_shapeb04_game::Fwd()
{
    AT_shapeb04_game(Tgt_007c22e0_shapeb04_game*, this, 0x8c)->Run();
}

struct Tgt_007c22f0_shapeb04_game {
    // STUB: 0x7cd540
    void Run();
};

struct View_007c22f0_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x007c22f0
void View_007c22f0_shapeb04_game::Fwd()
{
    AT_shapeb04_game(Tgt_007c22f0_shapeb04_game*, this, 0x8c)->Run();
}

struct Tgt_007c2300_shapeb04_game {
    // STUB: 0x7cd6a0
    void Run();
};

struct View_007c2300_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x007c2300
void View_007c2300_shapeb04_game::Fwd()
{
    AT_shapeb04_game(Tgt_007c2300_shapeb04_game*, this, 0x8c)->Run();
}

struct Tgt_007c2310_shapeb04_game {
    // STUB: 0x7cd6c0
    void Run();
};

struct View_007c2310_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x007c2310
void View_007c2310_shapeb04_game::Fwd()
{
    AT_shapeb04_game(Tgt_007c2310_shapeb04_game*, this, 0x8c)->Run();
}

struct Tgt_007c2320_shapeb04_game {
    // STUB: 0x7cde60
    void Run();
};

struct View_007c2320_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x007c2320
void View_007c2320_shapeb04_game::Fwd()
{
    AT_shapeb04_game(Tgt_007c2320_shapeb04_game*, this, 0x8c)->Run();
}

struct Tgt_008834c0_shapeb04_game {
    // STUB: 0x88a450
    void Run();
};

struct View_008834c0_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x008834c0
void View_008834c0_shapeb04_game::Fwd()
{
    AT_shapeb04_game(Tgt_008834c0_shapeb04_game*, this, 0xc)->Run();
}

struct OB_NOVTABLE Sub_004595a0_shapeb04_game {
    virtual void Pad00_004595a0_shapeb04_game();
    virtual void Pad01_004595a0_shapeb04_game();
    virtual void Pad02_004595a0_shapeb04_game();
    virtual void Pad03_004595a0_shapeb04_game();
    virtual void Pad04_004595a0_shapeb04_game();
    virtual void Pad05_004595a0_shapeb04_game();
    virtual void Pad06_004595a0_shapeb04_game();
    virtual void Pad07_004595a0_shapeb04_game();
    virtual void Pad08_004595a0_shapeb04_game();
    virtual void Pad09_004595a0_shapeb04_game();
    virtual void Pad10_004595a0_shapeb04_game();
    virtual void Pad11_004595a0_shapeb04_game();
    virtual void Pad12_004595a0_shapeb04_game();
    virtual void Slot13_004595a0_shapeb04_game() = 0;
};

struct View_004595a0_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x004595a0
void View_004595a0_shapeb04_game::Fwd()
{
    reinterpret_cast<Sub_004595a0_shapeb04_game*>(reinterpret_cast<char*>(this) + 0x4c)->Slot13_004595a0_shapeb04_game();
}

struct OB_NOVTABLE Sub_004abb50_shapeb04_game {
    virtual void Pad00_004abb50_shapeb04_game();
    virtual void Pad01_004abb50_shapeb04_game();
    virtual void Pad02_004abb50_shapeb04_game();
    virtual void Pad03_004abb50_shapeb04_game();
    virtual void Pad04_004abb50_shapeb04_game();
    virtual void Pad05_004abb50_shapeb04_game();
    virtual void Pad06_004abb50_shapeb04_game();
    virtual void Pad07_004abb50_shapeb04_game();
    virtual void Pad08_004abb50_shapeb04_game();
    virtual void Pad09_004abb50_shapeb04_game();
    virtual void Pad10_004abb50_shapeb04_game();
    virtual void Pad11_004abb50_shapeb04_game();
    virtual void Pad12_004abb50_shapeb04_game();
    virtual void Slot13_004abb50_shapeb04_game() = 0;
};

struct View_004abb50_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x004abb50
void View_004abb50_shapeb04_game::Fwd()
{
    reinterpret_cast<Sub_004abb50_shapeb04_game*>(reinterpret_cast<char*>(this) + 0xbc)->Slot13_004abb50_shapeb04_game();
}

struct OB_NOVTABLE Sub_004abb80_shapeb04_game {
    virtual void Pad00_004abb80_shapeb04_game();
    virtual void Pad01_004abb80_shapeb04_game();
    virtual void Pad02_004abb80_shapeb04_game();
    virtual void Pad03_004abb80_shapeb04_game();
    virtual void Pad04_004abb80_shapeb04_game();
    virtual void Pad05_004abb80_shapeb04_game();
    virtual void Pad06_004abb80_shapeb04_game();
    virtual void Pad07_004abb80_shapeb04_game();
    virtual void Pad08_004abb80_shapeb04_game();
    virtual void Pad09_004abb80_shapeb04_game();
    virtual void Pad10_004abb80_shapeb04_game();
    virtual void Pad11_004abb80_shapeb04_game();
    virtual void Pad12_004abb80_shapeb04_game();
    virtual void Slot13_004abb80_shapeb04_game() = 0;
};

struct View_004abb80_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x004abb80
void View_004abb80_shapeb04_game::Fwd()
{
    reinterpret_cast<Sub_004abb80_shapeb04_game*>(reinterpret_cast<char*>(this) + 0xd0)->Slot13_004abb80_shapeb04_game();
}

struct OB_NOVTABLE Sub_004abbb0_shapeb04_game {
    virtual void Pad00_004abbb0_shapeb04_game();
    virtual void Pad01_004abbb0_shapeb04_game();
    virtual void Pad02_004abbb0_shapeb04_game();
    virtual void Pad03_004abbb0_shapeb04_game();
    virtual void Pad04_004abbb0_shapeb04_game();
    virtual void Pad05_004abbb0_shapeb04_game();
    virtual void Pad06_004abbb0_shapeb04_game();
    virtual void Pad07_004abbb0_shapeb04_game();
    virtual void Pad08_004abbb0_shapeb04_game();
    virtual void Pad09_004abbb0_shapeb04_game();
    virtual void Pad10_004abbb0_shapeb04_game();
    virtual void Pad11_004abbb0_shapeb04_game();
    virtual void Pad12_004abbb0_shapeb04_game();
    virtual void Slot13_004abbb0_shapeb04_game() = 0;
};

struct View_004abbb0_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x004abbb0
void View_004abbb0_shapeb04_game::Fwd()
{
    reinterpret_cast<Sub_004abbb0_shapeb04_game*>(reinterpret_cast<char*>(this) + 0xf8)->Slot13_004abbb0_shapeb04_game();
}

struct OB_NOVTABLE Sub_004abbe0_shapeb04_game {
    virtual void Pad00_004abbe0_shapeb04_game();
    virtual void Pad01_004abbe0_shapeb04_game();
    virtual void Pad02_004abbe0_shapeb04_game();
    virtual void Pad03_004abbe0_shapeb04_game();
    virtual void Pad04_004abbe0_shapeb04_game();
    virtual void Pad05_004abbe0_shapeb04_game();
    virtual void Pad06_004abbe0_shapeb04_game();
    virtual void Pad07_004abbe0_shapeb04_game();
    virtual void Pad08_004abbe0_shapeb04_game();
    virtual void Pad09_004abbe0_shapeb04_game();
    virtual void Pad10_004abbe0_shapeb04_game();
    virtual void Pad11_004abbe0_shapeb04_game();
    virtual void Pad12_004abbe0_shapeb04_game();
    virtual void Slot13_004abbe0_shapeb04_game() = 0;
};

struct View_004abbe0_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x004abbe0
void View_004abbe0_shapeb04_game::Fwd()
{
    reinterpret_cast<Sub_004abbe0_shapeb04_game*>(reinterpret_cast<char*>(this) + 0x154)->Slot13_004abbe0_shapeb04_game();
}

struct OB_NOVTABLE Sub_004abc10_shapeb04_game {
    virtual void Pad00_004abc10_shapeb04_game();
    virtual void Pad01_004abc10_shapeb04_game();
    virtual void Pad02_004abc10_shapeb04_game();
    virtual void Pad03_004abc10_shapeb04_game();
    virtual void Pad04_004abc10_shapeb04_game();
    virtual void Pad05_004abc10_shapeb04_game();
    virtual void Pad06_004abc10_shapeb04_game();
    virtual void Pad07_004abc10_shapeb04_game();
    virtual void Pad08_004abc10_shapeb04_game();
    virtual void Pad09_004abc10_shapeb04_game();
    virtual void Pad10_004abc10_shapeb04_game();
    virtual void Pad11_004abc10_shapeb04_game();
    virtual void Pad12_004abc10_shapeb04_game();
    virtual void Slot13_004abc10_shapeb04_game() = 0;
};

struct View_004abc10_shapeb04_game {
    void Fwd();
};

// FUNCTION: 0x004abc10
void View_004abc10_shapeb04_game::Fwd()
{
    reinterpret_cast<Sub_004abc10_shapeb04_game*>(reinterpret_cast<char*>(this) + 0x120)->Slot13_004abc10_shapeb04_game();
}

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct View_0094cb20_shapeb04_game {
    void* mpBuf;
    // STUB: 0x94c94c
    void Inner();
    void Fn();
};

#ifdef _MSC_VER
#pragma optimize("s", on)
#endif
// FUNCTION: 0x0094cb20
void View_0094cb20_shapeb04_game::Fn()
{
    Inner();
    if (mpBuf) {
        _STL::__stl_delete(mpBuf);
    }
}
#ifdef _MSC_VER
#pragma optimize("", on)
#endif

struct View_0096a580_shapeb04_game {
    void* mpBuf;
    // STUB: 0x96a516
    void Inner();
    void Fn();
};

#ifdef _MSC_VER
#pragma optimize("s", on)
#endif
// FUNCTION: 0x0096a580
void View_0096a580_shapeb04_game::Fn()
{
    Inner();
    if (mpBuf) {
        _STL::__stl_delete(mpBuf);
    }
}
#ifdef _MSC_VER
#pragma optimize("", on)
#endif

struct View_00969110_shapeb04_game {
    void* mpBuf;
    // STUB: 0x968d5f
    void Inner();
    void Fn();
};

#ifdef _MSC_VER
#pragma optimize("s", on)
#endif
// FUNCTION: 0x00969110
void View_00969110_shapeb04_game::Fn()
{
    Inner();
    if (mpBuf) {
        _STL::__stl_delete(mpBuf);
    }
}
#ifdef _MSC_VER
#pragma optimize("", on)
#endif

struct View_00937e50_shapeb04_game {
    void* mpBuf;
    // STUB: 0x937ce0
    void Inner();
    void Fn();
};

#ifdef _MSC_VER
#pragma optimize("s", on)
#endif
// FUNCTION: 0x00937e50
void View_00937e50_shapeb04_game::Fn()
{
    Inner();
    if (mpBuf) {
        _STL::__stl_delete(mpBuf);
    }
}
#ifdef _MSC_VER
#pragma optimize("", on)
#endif

struct View_00892000_shapeb04_game {
    void* mpBuf;
    // STUB: 0x891ee6
    void Inner();
    void Fn();
};

#ifdef _MSC_VER
#pragma optimize("s", on)
#endif
// FUNCTION: 0x00892000
void View_00892000_shapeb04_game::Fn()
{
    Inner();
    if (mpBuf) {
        _STL::__stl_delete(mpBuf);
    }
}
#ifdef _MSC_VER
#pragma optimize("", on)
#endif

struct View_00939220_shapeb04_game {
    void* mpBuf;
    // STUB: 0x939017
    void Inner();
    void Fn();
};

#ifdef _MSC_VER
#pragma optimize("s", on)
#endif
// FUNCTION: 0x00939220
void View_00939220_shapeb04_game::Fn()
{
    Inner();
    if (mpBuf) {
        _STL::__stl_delete(mpBuf);
    }
}
#ifdef _MSC_VER
#pragma optimize("", on)
#endif

struct View_00949370_shapeb04_game {
    void* mpBuf;
    // STUB: 0x949279
    void Inner();
    void Fn();
};

#ifdef _MSC_VER
#pragma optimize("s", on)
#endif
// FUNCTION: 0x00949370
void View_00949370_shapeb04_game::Fn()
{
    Inner();
    if (mpBuf) {
        _STL::__stl_delete(mpBuf);
    }
}
#ifdef _MSC_VER
#pragma optimize("", on)
#endif

struct OB_NOVTABLE View_007ff040_shapeb04_game {
    virtual void Slot00_007ff040_shapeb04_game() = 0;
    virtual uint32_t Slot01_007ff040_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x007ff040
bool View_007ff040_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x1 && iid != 0xe9c6262a) {
        return false;
    }
    *ppv = this;
    Slot01_007ff040_shapeb04_game();
    return true;
}

struct OB_NOVTABLE View_004ed0d0_shapeb04_game {
    virtual void Slot00_004ed0d0_shapeb04_game() = 0;
    virtual uint32_t Slot01_004ed0d0_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x004ed0d0
bool View_004ed0d0_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x1 && iid != 0xaa355871) {
        return false;
    }
    *ppv = this;
    Slot01_004ed0d0_shapeb04_game();
    return true;
}

struct OB_NOVTABLE View_005f47c0_shapeb04_game {
    virtual void Slot00_005f47c0_shapeb04_game() = 0;
    virtual uint32_t Slot01_005f47c0_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005f47c0
bool View_005f47c0_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x1 && iid != 0x8aa22237) {
        return false;
    }
    *ppv = this;
    Slot01_005f47c0_shapeb04_game();
    return true;
}

struct OB_NOVTABLE View_005fb100_shapeb04_game {
    virtual void Slot00_005fb100_shapeb04_game() = 0;
    virtual uint32_t Slot01_005fb100_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005fb100
bool View_005fb100_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x1 && iid != 0xc6bb8345) {
        return false;
    }
    *ppv = this;
    Slot01_005fb100_shapeb04_game();
    return true;
}

struct OB_NOVTABLE View_005ffe60_shapeb04_game {
    virtual void Slot00_005ffe60_shapeb04_game() = 0;
    virtual uint32_t Slot01_005ffe60_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x005ffe60
bool View_005ffe60_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x1 && iid != 0x8a2c3240) {
        return false;
    }
    *ppv = this;
    Slot01_005ffe60_shapeb04_game();
    return true;
}

struct OB_NOVTABLE View_0060c800_shapeb04_game {
    virtual void Slot00_0060c800_shapeb04_game() = 0;
    virtual uint32_t Slot01_0060c800_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0060c800
bool View_0060c800_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x1 && iid != 0x89a5ba66) {
        return false;
    }
    *ppv = this;
    Slot01_0060c800_shapeb04_game();
    return true;
}

struct OB_NOVTABLE View_00734b60_shapeb04_game {
    virtual void Slot00_00734b60_shapeb04_game() = 0;
    virtual uint32_t Slot01_00734b60_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00734b60
bool View_00734b60_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid != 0x1 && iid != 0xc6ae7085) {
        return false;
    }
    *ppv = this;
    Slot01_00734b60_shapeb04_game();
    return true;
}

struct Node_shapeb04_game {
    uint32_t mnColor;
    Node_shapeb04_game* mpRoot;
    Node_shapeb04_game* mpLeft;
    Node_shapeb04_game* mpRight;
};

struct View_004b6310_shapeb04_game {
    Node_shapeb04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x4b6250
    void Erase(Node_shapeb04_game* pNode);
    void Fn();
};

// FUNCTION: 0x004b6310
void View_004b6310_shapeb04_game::Fn()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
}

struct View_00510c40_shapeb04_game {
    Node_shapeb04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x50f1e0
    void Erase(Node_shapeb04_game* pNode);
    void Fn();
};

// FUNCTION: 0x00510c40
void View_00510c40_shapeb04_game::Fn()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
}

struct View_006b08c0_shapeb04_game {
    Node_shapeb04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x6b04b0
    void Erase(Node_shapeb04_game* pNode);
    void Fn();
};

// FUNCTION: 0x006b08c0
void View_006b08c0_shapeb04_game::Fn()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
}

struct View_004de720_shapeb04_game {
    Node_shapeb04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x4de6e0
    void Erase(Node_shapeb04_game* pNode);
    void Fn();
};

// FUNCTION: 0x004de720
void View_004de720_shapeb04_game::Fn()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
}

struct View_0065e780_shapeb04_game {
    Node_shapeb04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x65e740
    void Erase(Node_shapeb04_game* pNode);
    void Fn();
};

// FUNCTION: 0x0065e780
void View_0065e780_shapeb04_game::Fn()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
}

struct View_00662af0_shapeb04_game {
    Node_shapeb04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x662a60
    void Erase(Node_shapeb04_game* pNode);
    void Fn();
};

// FUNCTION: 0x00662af0
void View_00662af0_shapeb04_game::Fn()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
}

struct View_0081d170_shapeb04_game {
    Node_shapeb04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x81d0f0
    void Erase(Node_shapeb04_game* pNode);
    void Fn();
};

// FUNCTION: 0x0081d170
void View_0081d170_shapeb04_game::Fn()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
}

struct Tag_shapeb04_game {
};

// STUB: 0x761630
void* Fn00761630(void* a, void* b, void* c, Tag_shapeb04_game* tag, uint32_t z);

// STUB: 0x761710
void Fn00761710(void* a, void* b, Tag_shapeb04_game* tag);

struct View_00761870_shapeb04_game {
    void* mpBegin;
    void* mpEnd;
    void Fn();
};

// FUNCTION: 0x00761870
void View_00761870_shapeb04_game::Fn()
{
    Tag_shapeb04_game tag;
    void* pBegin = mpBegin;
    void* pEnd = mpEnd;
    void* pNew = Fn00761630(pEnd, pEnd, pBegin, &tag, 0);
    Fn00761710(pNew, mpEnd, &tag);
    mpEnd = pNew;
}

// STUB: 0x43b360
void* Fn0043b360(void* a, void* b, void* c, Tag_shapeb04_game* tag, uint32_t z);

// STUB: 0x43b180
void Fn0043b180(void* a, void* b, Tag_shapeb04_game* tag);

struct View_0043bb90_shapeb04_game {
    void* mpBegin;
    void* mpEnd;
    void Fn();
};

// FUNCTION: 0x0043bb90
void View_0043bb90_shapeb04_game::Fn()
{
    Tag_shapeb04_game tag;
    void* pBegin = mpBegin;
    void* pEnd = mpEnd;
    void* pNew = Fn0043b360(pEnd, pEnd, pBegin, &tag, 0);
    Fn0043b180(pNew, mpEnd, &tag);
    mpEnd = pNew;
}

// STUB: 0x570d60
void* Fn00570d60(void* a, void* b, void* c, Tag_shapeb04_game* tag, uint32_t z);

// STUB: 0x56f740
void Fn0056f740(void* a, void* b, Tag_shapeb04_game* tag);

struct View_005734e0_shapeb04_game {
    void* mpBegin;
    void* mpEnd;
    void Fn();
};

// FUNCTION: 0x005734e0
void View_005734e0_shapeb04_game::Fn()
{
    Tag_shapeb04_game tag;
    void* pBegin = mpBegin;
    void* pEnd = mpEnd;
    void* pNew = Fn00570d60(pEnd, pEnd, pBegin, &tag, 0);
    Fn0056f740(pNew, mpEnd, &tag);
    mpEnd = pNew;
}

// STUB: 0x714000
void* Fn00714000(void* a, void* b, void* c, Tag_shapeb04_game* tag, uint32_t z);

// STUB: 0x716a70
void Fn00716a70(void* a, void* b, Tag_shapeb04_game* tag);

struct View_0071de80_shapeb04_game {
    void* mpBegin;
    void* mpEnd;
    void Fn();
};

// FUNCTION: 0x0071de80
void View_0071de80_shapeb04_game::Fn()
{
    Tag_shapeb04_game tag;
    void* pBegin = mpBegin;
    void* pEnd = mpEnd;
    void* pNew = Fn00714000(pEnd, pEnd, pBegin, &tag, 0);
    Fn00716a70(pNew, mpEnd, &tag);
    mpEnd = pNew;
}

// STUB: 0x76ce00
void* Fn0076ce00(void* a, void* b, void* c, Tag_shapeb04_game* tag, uint32_t z);

// STUB: 0x76ca20
void Fn0076ca20(void* a, void* b, Tag_shapeb04_game* tag);

struct View_0076d2b0_shapeb04_game {
    void* mpBegin;
    void* mpEnd;
    void Fn();
};

// FUNCTION: 0x0076d2b0
void View_0076d2b0_shapeb04_game::Fn()
{
    Tag_shapeb04_game tag;
    void* pBegin = mpBegin;
    void* pEnd = mpEnd;
    void* pNew = Fn0076ce00(pEnd, pEnd, pBegin, &tag, 0);
    Fn0076ca20(pNew, mpEnd, &tag);
    mpEnd = pNew;
}

// STUB: 0x8b63d0
void* Fn008b63d0(void* a, void* b, void* c, Tag_shapeb04_game* tag, uint32_t z);

// STUB: 0x8b5ed0
void Fn008b5ed0(void* a, void* b, Tag_shapeb04_game* tag);

struct View_008b66a0_shapeb04_game {
    void* mpBegin;
    void* mpEnd;
    void Fn();
};

// FUNCTION: 0x008b66a0
void View_008b66a0_shapeb04_game::Fn()
{
    Tag_shapeb04_game tag;
    void* pBegin = mpBegin;
    void* pEnd = mpEnd;
    void* pNew = Fn008b63d0(pEnd, pEnd, pBegin, &tag, 0);
    Fn008b5ed0(pNew, mpEnd, &tag);
    mpEnd = pNew;
}

struct OB_NOVTABLE Item_0040f170_shapeb04_game {
    virtual void Pad00_0040f170_shapeb04_game();
    virtual void Pad01_0040f170_shapeb04_game();
    virtual void Slot2_0040f170_shapeb04_game() = 0;
};

struct Elem_0040f170_shapeb04_game {
    Item_0040f170_shapeb04_game* mpItem;
    uint32_t mPad[3];
};

struct View_0040f170_shapeb04_game {
    Elem_0040f170_shapeb04_game* mpBegin;
    Elem_0040f170_shapeb04_game* mpEnd;
    void Fn();
};

// FUNCTION: 0x0040f170
void View_0040f170_shapeb04_game::Fn()
{
    Elem_0040f170_shapeb04_game* pEnd = mpEnd;
    for (Elem_0040f170_shapeb04_game* p = mpBegin; p != pEnd; ++p) {
        if (p->mpItem) {
            p->mpItem->Slot2_0040f170_shapeb04_game();
        }
    }
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct OB_NOVTABLE Item_00510410_shapeb04_game {
    virtual void Pad00_00510410_shapeb04_game();
    virtual void Pad01_00510410_shapeb04_game();
    virtual void Slot2_00510410_shapeb04_game() = 0;
};

struct Elem_00510410_shapeb04_game {
    Item_00510410_shapeb04_game* mpItem;
    uint32_t mPad[14];
};

struct View_00510410_shapeb04_game {
    Elem_00510410_shapeb04_game* mpBegin;
    Elem_00510410_shapeb04_game* mpEnd;
    void Fn();
};

// FUNCTION: 0x00510410
void View_00510410_shapeb04_game::Fn()
{
    Elem_00510410_shapeb04_game* pEnd = mpEnd;
    for (Elem_00510410_shapeb04_game* p = mpBegin; p != pEnd; ++p) {
        if (p->mpItem) {
            p->mpItem->Slot2_00510410_shapeb04_game();
        }
    }
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct OB_NOVTABLE Item_0077c480_shapeb04_game {
    virtual void Pad00_0077c480_shapeb04_game();
    virtual void Pad01_0077c480_shapeb04_game();
    virtual void Slot2_0077c480_shapeb04_game() = 0;
};

struct Elem_0077c480_shapeb04_game {
    Item_0077c480_shapeb04_game* mpItem;
    uint32_t mPad[2];
};

struct View_0077c480_shapeb04_game {
    Elem_0077c480_shapeb04_game* mpBegin;
    Elem_0077c480_shapeb04_game* mpEnd;
    void Fn();
};

// FUNCTION: 0x0077c480
void View_0077c480_shapeb04_game::Fn()
{
    Elem_0077c480_shapeb04_game* pEnd = mpEnd;
    for (Elem_0077c480_shapeb04_game* p = mpBegin; p != pEnd; ++p) {
        if (p->mpItem) {
            p->mpItem->Slot2_0077c480_shapeb04_game();
        }
    }
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct OB_NOVTABLE Item_007b3bd0_shapeb04_game {
    virtual void Pad00_007b3bd0_shapeb04_game();
    virtual void Pad01_007b3bd0_shapeb04_game();
    virtual void Slot2_007b3bd0_shapeb04_game() = 0;
};

struct Elem_007b3bd0_shapeb04_game {
    Item_007b3bd0_shapeb04_game* mpItem;
    uint32_t mPad[1];
};

struct View_007b3bd0_shapeb04_game {
    Elem_007b3bd0_shapeb04_game* mpBegin;
    Elem_007b3bd0_shapeb04_game* mpEnd;
    void Fn();
};

// FUNCTION: 0x007b3bd0
void View_007b3bd0_shapeb04_game::Fn()
{
    Elem_007b3bd0_shapeb04_game* pEnd = mpEnd;
    for (Elem_007b3bd0_shapeb04_game* p = mpBegin; p != pEnd; ++p) {
        if (p->mpItem) {
            p->mpItem->Slot2_007b3bd0_shapeb04_game();
        }
    }
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct OB_NOVTABLE Item_005877d0_shapeb04_game {
    virtual void Pad00_005877d0_shapeb04_game();
    virtual void Slot1_005877d0_shapeb04_game() = 0;
};

struct Elem_005877d0_shapeb04_game {
    Item_005877d0_shapeb04_game* mpItem;
};

struct View_005877d0_shapeb04_game {
    Elem_005877d0_shapeb04_game* mpBegin;
    Elem_005877d0_shapeb04_game* mpEnd;
    void Fn();
};

// FUNCTION: 0x005877d0
void View_005877d0_shapeb04_game::Fn()
{
    Elem_005877d0_shapeb04_game* pEnd = mpEnd;
    for (Elem_005877d0_shapeb04_game* p = mpBegin; p != pEnd; ++p) {
        if (p->mpItem) {
            p->mpItem->Slot1_005877d0_shapeb04_game();
        }
    }
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct OB_NOVTABLE Item_00587810_shapeb04_game {
    virtual void Pad00_00587810_shapeb04_game();
    virtual void Pad01_00587810_shapeb04_game();
    virtual void Pad02_00587810_shapeb04_game();
    virtual void Pad03_00587810_shapeb04_game();
    virtual void Pad04_00587810_shapeb04_game();
    virtual void Slot5_00587810_shapeb04_game() = 0;
};

struct Elem_00587810_shapeb04_game {
    Item_00587810_shapeb04_game* mpItem;
};

struct View_00587810_shapeb04_game {
    Elem_00587810_shapeb04_game* mpBegin;
    Elem_00587810_shapeb04_game* mpEnd;
    void Fn();
};

// FUNCTION: 0x00587810
void View_00587810_shapeb04_game::Fn()
{
    Elem_00587810_shapeb04_game* pEnd = mpEnd;
    for (Elem_00587810_shapeb04_game* p = mpBegin; p != pEnd; ++p) {
        if (p->mpItem) {
            p->mpItem->Slot5_00587810_shapeb04_game();
        }
    }
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct Elem_0081abe0_shapeb04_game {
    uint8_t mData[24];
    // STUB: 0x818400
    void Copy(Elem_0081abe0_shapeb04_game* pSrc);
};

struct View_0081abe0_shapeb04_game {
    uint32_t mnPad;
    Elem_0081abe0_shapeb04_game* mpEnd;
    Elem_0081abe0_shapeb04_game* mpCap;
    // STUB: 0x81aaa0
    void Insert(Elem_0081abe0_shapeb04_game* pAt, Elem_0081abe0_shapeb04_game* pSrc, Elem_0081abe0_shapeb04_game** ppSrc, uint32_t n, uint32_t m);
    void Push(Elem_0081abe0_shapeb04_game* pSrc);
};

// FUNCTION: 0x0081abe0
void View_0081abe0_shapeb04_game::Push(Elem_0081abe0_shapeb04_game* pSrc)
{
    if (mpEnd != mpCap) {
        if (mpEnd) {
            mpEnd->Copy(pSrc);
        }
        ++mpEnd;
        return;
    }
    Insert(mpEnd, pSrc, &pSrc, 1, 1);
}

struct Elem_007d1070_shapeb04_game {
    uint8_t mData[124];
    // STUB: 0x7d0580
    void Copy(Elem_007d1070_shapeb04_game* pSrc);
};

struct View_007d1070_shapeb04_game {
    uint32_t mnPad;
    Elem_007d1070_shapeb04_game* mpEnd;
    Elem_007d1070_shapeb04_game* mpCap;
    // STUB: 0x7d0eb0
    void Insert(Elem_007d1070_shapeb04_game* pAt, Elem_007d1070_shapeb04_game* pSrc, Elem_007d1070_shapeb04_game** ppSrc, uint32_t n, uint32_t m);
    void Push(Elem_007d1070_shapeb04_game* pSrc);
};

// FUNCTION: 0x007d1070
void View_007d1070_shapeb04_game::Push(Elem_007d1070_shapeb04_game* pSrc)
{
    if (mpEnd != mpCap) {
        if (mpEnd) {
            mpEnd->Copy(pSrc);
        }
        ++mpEnd;
        return;
    }
    Insert(mpEnd, pSrc, &pSrc, 1, 1);
}

struct Elem_00479be0_shapeb04_game {
    uint8_t mData[52];
    // STUB: 0x4788d0
    void Copy(Elem_00479be0_shapeb04_game* pSrc);
};

struct View_00479be0_shapeb04_game {
    uint32_t mnPad;
    Elem_00479be0_shapeb04_game* mpEnd;
    Elem_00479be0_shapeb04_game* mpCap;
    // STUB: 0x479910
    void Insert(Elem_00479be0_shapeb04_game* pAt, Elem_00479be0_shapeb04_game* pSrc, Elem_00479be0_shapeb04_game** ppSrc, uint32_t n, uint32_t m);
    void Push(Elem_00479be0_shapeb04_game* pSrc);
};

// FUNCTION: 0x00479be0
void View_00479be0_shapeb04_game::Push(Elem_00479be0_shapeb04_game* pSrc)
{
    if (mpEnd != mpCap) {
        if (mpEnd) {
            mpEnd->Copy(pSrc);
        }
        ++mpEnd;
        return;
    }
    Insert(mpEnd, pSrc, &pSrc, 1, 1);
}

struct Elem_0043b6d0_shapeb04_game {
    uint8_t mData[48];
    // STUB: 0x43b100
    void Copy(Elem_0043b6d0_shapeb04_game* pSrc);
};

struct View_0043b6d0_shapeb04_game {
    uint32_t mnPad;
    Elem_0043b6d0_shapeb04_game* mpEnd;
    Elem_0043b6d0_shapeb04_game* mpCap;
    // STUB: 0x43b450
    void Insert(Elem_0043b6d0_shapeb04_game* pAt, Elem_0043b6d0_shapeb04_game* pSrc, Elem_0043b6d0_shapeb04_game** ppSrc, uint32_t n, uint32_t m);
    void Push(Elem_0043b6d0_shapeb04_game* pSrc);
};

// FUNCTION: 0x0043b6d0
void View_0043b6d0_shapeb04_game::Push(Elem_0043b6d0_shapeb04_game* pSrc)
{
    if (mpEnd != mpCap) {
        if (mpEnd) {
            mpEnd->Copy(pSrc);
        }
        ++mpEnd;
        return;
    }
    Insert(mpEnd, pSrc, &pSrc, 1, 1);
}

struct Elem_005137d0_shapeb04_game {
    uint8_t mData[108];
    // STUB: 0x510fa0
    void Copy(Elem_005137d0_shapeb04_game* pSrc);
};

struct View_005137d0_shapeb04_game {
    uint32_t mnPad;
    Elem_005137d0_shapeb04_game* mpEnd;
    Elem_005137d0_shapeb04_game* mpCap;
    // STUB: 0x512b60
    void Insert(Elem_005137d0_shapeb04_game* pAt, Elem_005137d0_shapeb04_game* pSrc, Elem_005137d0_shapeb04_game** ppSrc, uint32_t n, uint32_t m);
    void Push(Elem_005137d0_shapeb04_game* pSrc);
};

// FUNCTION: 0x005137d0
void View_005137d0_shapeb04_game::Push(Elem_005137d0_shapeb04_game* pSrc)
{
    if (mpEnd != mpCap) {
        if (mpEnd) {
            mpEnd->Copy(pSrc);
        }
        ++mpEnd;
        return;
    }
    Insert(mpEnd, pSrc, &pSrc, 1, 1);
}

struct Elem_006312c0_shapeb04_game {
    uint8_t mData[80];
    // STUB: 0x6267d0
    void Copy(Elem_006312c0_shapeb04_game* pSrc);
};

struct View_006312c0_shapeb04_game {
    uint32_t mnPad;
    Elem_006312c0_shapeb04_game* mpEnd;
    Elem_006312c0_shapeb04_game* mpCap;
    // STUB: 0x6310f0
    void Insert(Elem_006312c0_shapeb04_game* pAt, Elem_006312c0_shapeb04_game* pSrc, Elem_006312c0_shapeb04_game** ppSrc, uint32_t n, uint32_t m);
    void Push(Elem_006312c0_shapeb04_game* pSrc);
};

// FUNCTION: 0x006312c0
void View_006312c0_shapeb04_game::Push(Elem_006312c0_shapeb04_game* pSrc)
{
    if (mpEnd != mpCap) {
        if (mpEnd) {
            mpEnd->Copy(pSrc);
        }
        ++mpEnd;
        return;
    }
    Insert(mpEnd, pSrc, &pSrc, 1, 1);
}

struct Vec_shapeb04_game {
    void* mpBegin;
    void* mpEnd;
    void* mpCap;
};

struct View_004610e0_shapeb04_game {
    // STUB: 0x461120
    void Fn00461120(uint32_t a, Vec_shapeb04_game* pVec);
    void Fn(uint32_t a);
};

// FUNCTION: 0x004610e0
void View_004610e0_shapeb04_game::Fn(uint32_t a)
{
    Vec_shapeb04_game v;
    v.mpBegin = 0;
    v.mpEnd = 0;
    v.mpCap = 0;
    Fn00461120(a, &v);
    if (v.mpBegin) {
        _STL::__stl_delete(v.mpBegin);
    }
}

struct View_00461ae0_shapeb04_game {
    // STUB: 0x461b20
    void Fn00461b20(uint32_t a, Vec_shapeb04_game* pVec);
    void Fn(uint32_t a);
};

// FUNCTION: 0x00461ae0
void View_00461ae0_shapeb04_game::Fn(uint32_t a)
{
    Vec_shapeb04_game v;
    v.mpBegin = 0;
    v.mpEnd = 0;
    v.mpCap = 0;
    Fn00461b20(a, &v);
    if (v.mpBegin) {
        _STL::__stl_delete(v.mpBegin);
    }
}

struct View_004623b0_shapeb04_game {
    // STUB: 0x4623f0
    void Fn004623f0(uint32_t a, Vec_shapeb04_game* pVec);
    void Fn(uint32_t a);
};

// FUNCTION: 0x004623b0
void View_004623b0_shapeb04_game::Fn(uint32_t a)
{
    Vec_shapeb04_game v;
    v.mpBegin = 0;
    v.mpEnd = 0;
    v.mpCap = 0;
    Fn004623f0(a, &v);
    if (v.mpBegin) {
        _STL::__stl_delete(v.mpBegin);
    }
}

struct View_00462ae0_shapeb04_game {
    // STUB: 0x462b20
    void Fn00462b20(uint32_t a, Vec_shapeb04_game* pVec);
    void Fn(uint32_t a);
};

// FUNCTION: 0x00462ae0
void View_00462ae0_shapeb04_game::Fn(uint32_t a)
{
    Vec_shapeb04_game v;
    v.mpBegin = 0;
    v.mpEnd = 0;
    v.mpCap = 0;
    Fn00462b20(a, &v);
    if (v.mpBegin) {
        _STL::__stl_delete(v.mpBegin);
    }
}

struct View_00463bc0_shapeb04_game {
    // STUB: 0x463c00
    void Fn00463c00(uint32_t a, Vec_shapeb04_game* pVec);
    void Fn(uint32_t a);
};

// FUNCTION: 0x00463bc0
void View_00463bc0_shapeb04_game::Fn(uint32_t a)
{
    Vec_shapeb04_game v;
    v.mpBegin = 0;
    v.mpEnd = 0;
    v.mpCap = 0;
    Fn00463c00(a, &v);
    if (v.mpBegin) {
        _STL::__stl_delete(v.mpBegin);
    }
}

struct View_00464e90_shapeb04_game {
    // STUB: 0x464ed0
    void Fn00464ed0(uint32_t a, Vec_shapeb04_game* pVec);
    void Fn(uint32_t a);
};

// FUNCTION: 0x00464e90
void View_00464e90_shapeb04_game::Fn(uint32_t a)
{
    Vec_shapeb04_game v;
    v.mpBegin = 0;
    v.mpEnd = 0;
    v.mpCap = 0;
    Fn00464ed0(a, &v);
    if (v.mpBegin) {
        _STL::__stl_delete(v.mpBegin);
    }
}

namespace _STL {
    // STUB: 0x0090cf54
    void* __stl_new(unsigned int size);
}

struct Elem_0050f260_shapeb04_game {
    uint32_t mData[3];
    // STUB: 0x50bcb0
    void Copy(Elem_0050f260_shapeb04_game* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0050f260 score 23
Elem_0050f260_shapeb04_game* OB_STDCALL Fn0050f260(uint32_t n, Elem_0050f260_shapeb04_game* pFirst, Elem_0050f260_shapeb04_game* pLast)
{
    Elem_0050f260_shapeb04_game* pBuf;
    if (n) {
        pBuf = static_cast<Elem_0050f260_shapeb04_game*>(_STL::__stl_new(n * 12));
    } else {
        pBuf = 0;
    }
    Elem_0050f260_shapeb04_game* pDst = pBuf;
    while (pFirst != pLast) {
        if (pDst) {
            pDst->Copy(pFirst);
        }
        ++pFirst;
        ++pDst;
    }
    return pBuf;
}
#endif

struct Elem_00510490_shapeb04_game {
    uint32_t mData[3];
    // STUB: 0x459e80
    void Copy(Elem_00510490_shapeb04_game* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00510490 score 23
Elem_00510490_shapeb04_game* OB_STDCALL Fn00510490(uint32_t n, Elem_00510490_shapeb04_game* pFirst, Elem_00510490_shapeb04_game* pLast)
{
    Elem_00510490_shapeb04_game* pBuf;
    if (n) {
        pBuf = static_cast<Elem_00510490_shapeb04_game*>(_STL::__stl_new(n * 12));
    } else {
        pBuf = 0;
    }
    Elem_00510490_shapeb04_game* pDst = pBuf;
    while (pFirst != pLast) {
        if (pDst) {
            pDst->Copy(pFirst);
        }
        ++pFirst;
        ++pDst;
    }
    return pBuf;
}
#endif

struct Elem_0068de60_shapeb04_game {
    uint32_t mData[3];
    // STUB: 0x462620
    void Copy(Elem_0068de60_shapeb04_game* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0068de60 score 23
Elem_0068de60_shapeb04_game* OB_STDCALL Fn0068de60(uint32_t n, Elem_0068de60_shapeb04_game* pFirst, Elem_0068de60_shapeb04_game* pLast)
{
    Elem_0068de60_shapeb04_game* pBuf;
    if (n) {
        pBuf = static_cast<Elem_0068de60_shapeb04_game*>(_STL::__stl_new(n * 12));
    } else {
        pBuf = 0;
    }
    Elem_0068de60_shapeb04_game* pDst = pBuf;
    while (pFirst != pLast) {
        if (pDst) {
            pDst->Copy(pFirst);
        }
        ++pFirst;
        ++pDst;
    }
    return pBuf;
}
#endif

struct Elem_00706e40_shapeb04_game {
    uint32_t mData[3];
    // STUB: 0x462f00
    void Copy(Elem_00706e40_shapeb04_game* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00706e40 score 23
Elem_00706e40_shapeb04_game* OB_STDCALL Fn00706e40(uint32_t n, Elem_00706e40_shapeb04_game* pFirst, Elem_00706e40_shapeb04_game* pLast)
{
    Elem_00706e40_shapeb04_game* pBuf;
    if (n) {
        pBuf = static_cast<Elem_00706e40_shapeb04_game*>(_STL::__stl_new(n * 12));
    } else {
        pBuf = 0;
    }
    Elem_00706e40_shapeb04_game* pDst = pBuf;
    while (pFirst != pLast) {
        if (pDst) {
            pDst->Copy(pFirst);
        }
        ++pFirst;
        ++pDst;
    }
    return pBuf;
}
#endif

struct Elem_0043b290_shapeb04_game {
    uint32_t mData[3];
    // STUB: 0x43b100
    void Copy(Elem_0043b290_shapeb04_game* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0043b290 score 27
Elem_0043b290_shapeb04_game* OB_STDCALL Fn0043b290(uint32_t n, Elem_0043b290_shapeb04_game* pFirst, Elem_0043b290_shapeb04_game* pLast)
{
    Elem_0043b290_shapeb04_game* pBuf;
    if (n) {
        pBuf = static_cast<Elem_0043b290_shapeb04_game*>(_STL::__stl_new(n * 12));
    } else {
        pBuf = 0;
    }
    Elem_0043b290_shapeb04_game* pDst = pBuf;
    while (pFirst != pLast) {
        if (pDst) {
            pDst->Copy(pFirst);
        }
        ++pFirst;
        ++pDst;
    }
    return pBuf;
}
#endif

struct Elem_004e4040_shapeb04_game {
    uint32_t mData[3];
    // STUB: 0x4c9470
    void Copy(Elem_004e4040_shapeb04_game* pSrc);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004e4040 score 23
Elem_004e4040_shapeb04_game* OB_STDCALL Fn004e4040(uint32_t n, Elem_004e4040_shapeb04_game* pFirst, Elem_004e4040_shapeb04_game* pLast)
{
    Elem_004e4040_shapeb04_game* pBuf;
    if (n) {
        pBuf = static_cast<Elem_004e4040_shapeb04_game*>(_STL::__stl_new(n * 12));
    } else {
        pBuf = 0;
    }
    Elem_004e4040_shapeb04_game* pDst = pBuf;
    while (pFirst != pLast) {
        if (pDst) {
            pDst->Copy(pFirst);
        }
        ++pFirst;
        ++pDst;
    }
    return pBuf;
}
#endif

struct Pad_004ede80_shapeb04_game { uint8_t b[4]; };
struct B1_004ede80_shapeb04_game { uint8_t b[4]; };
struct B2_004ede80_shapeb04_game { uint8_t b[4]; };

struct OB_NOVTABLE View_004ede80_shapeb04_game : public Pad_004ede80_shapeb04_game, public B1_004ede80_shapeb04_game, public B2_004ede80_shapeb04_game {
    virtual void Slot00_004ede80_shapeb04_game() = 0;
    virtual uint32_t Slot01_004ede80_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x004ede80
bool View_004ede80_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x1:
    case 0xbb523bb2:
        *ppv = this;
        Slot01_004ede80_shapeb04_game();
        return true;
    case 0x452294aa:
        *ppv = static_cast<B1_004ede80_shapeb04_game*>(this);
        Slot01_004ede80_shapeb04_game();
        return true;
    case 0x89e51472:
        *ppv = static_cast<B2_004ede80_shapeb04_game*>(this);
        Slot01_004ede80_shapeb04_game();
        return true;
    }
    return false;
}

struct B1_006b37a0_shapeb04_game { uint8_t b[4]; };
struct B2_006b37a0_shapeb04_game { uint8_t b[4]; };

struct OB_NOVTABLE View_006b37a0_shapeb04_game : public B1_006b37a0_shapeb04_game, public B2_006b37a0_shapeb04_game {
    virtual void Slot00_006b37a0_shapeb04_game() = 0;
    virtual uint32_t Slot01_006b37a0_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006b37a0
bool View_006b37a0_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x1:
    case 0xe7cdd662:
        *ppv = this;
        Slot01_006b37a0_shapeb04_game();
        return true;
    case 0x452294aa:
        *ppv = static_cast<B1_006b37a0_shapeb04_game*>(this);
        Slot01_006b37a0_shapeb04_game();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<B2_006b37a0_shapeb04_game*>(this);
        Slot01_006b37a0_shapeb04_game();
        return true;
    }
    return false;
}

struct B1_006bd4c0_shapeb04_game { uint8_t b[4]; };
struct B2_006bd4c0_shapeb04_game { uint8_t b[4]; };

struct OB_NOVTABLE View_006bd4c0_shapeb04_game : public B1_006bd4c0_shapeb04_game, public B2_006bd4c0_shapeb04_game {
    virtual void Slot00_006bd4c0_shapeb04_game() = 0;
    virtual uint32_t Slot01_006bd4c0_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006bd4c0
bool View_006bd4c0_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x1:
    case 0xe7781d8c:
        *ppv = this;
        Slot01_006bd4c0_shapeb04_game();
        return true;
    case 0x452294aa:
        *ppv = static_cast<B1_006bd4c0_shapeb04_game*>(this);
        Slot01_006bd4c0_shapeb04_game();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<B2_006bd4c0_shapeb04_game*>(this);
        Slot01_006bd4c0_shapeb04_game();
        return true;
    }
    return false;
}

struct B1_006eabc0_shapeb04_game { uint8_t b[4]; };
struct B2_006eabc0_shapeb04_game { uint8_t b[4]; };

struct OB_NOVTABLE View_006eabc0_shapeb04_game : public B1_006eabc0_shapeb04_game, public B2_006eabc0_shapeb04_game {
    virtual void Slot00_006eabc0_shapeb04_game() = 0;
    virtual uint32_t Slot01_006eabc0_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006eabc0
bool View_006eabc0_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x1:
    case 0xe9e7bff5:
        *ppv = this;
        Slot01_006eabc0_shapeb04_game();
        return true;
    case 0x452294aa:
        *ppv = static_cast<B1_006eabc0_shapeb04_game*>(this);
        Slot01_006eabc0_shapeb04_game();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<B2_006eabc0_shapeb04_game*>(this);
        Slot01_006eabc0_shapeb04_game();
        return true;
    }
    return false;
}

struct B1_006f0d80_shapeb04_game { uint8_t b[4]; };
struct B2_006f0d80_shapeb04_game { uint8_t b[4]; };

struct OB_NOVTABLE View_006f0d80_shapeb04_game : public B1_006f0d80_shapeb04_game, public B2_006f0d80_shapeb04_game {
    virtual void Slot00_006f0d80_shapeb04_game() = 0;
    virtual uint32_t Slot01_006f0d80_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006f0d80
bool View_006f0d80_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x1:
    case 0xe9a1f4b6:
        *ppv = this;
        Slot01_006f0d80_shapeb04_game();
        return true;
    case 0x452294aa:
        *ppv = static_cast<B1_006f0d80_shapeb04_game*>(this);
        Slot01_006f0d80_shapeb04_game();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<B2_006f0d80_shapeb04_game*>(this);
        Slot01_006f0d80_shapeb04_game();
        return true;
    }
    return false;
}

struct B1_007a9240_shapeb04_game { uint8_t b[216]; };
struct B2_007a9240_shapeb04_game { uint8_t b[4]; };

struct OB_NOVTABLE View_007a9240_shapeb04_game : public B1_007a9240_shapeb04_game, public B2_007a9240_shapeb04_game {
    virtual void Slot00_007a9240_shapeb04_game() = 0;
    virtual uint32_t Slot01_007a9240_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x007a9240
bool View_007a9240_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x1:
    case 0x89e1574c:
        *ppv = this;
        Slot01_007a9240_shapeb04_game();
        return true;
    case 0x22ba0121:
        *ppv = static_cast<B1_007a9240_shapeb04_game*>(this);
        Slot01_007a9240_shapeb04_game();
        return true;
    case 0x452294aa:
        *ppv = static_cast<B2_007a9240_shapeb04_game*>(this);
        Slot01_007a9240_shapeb04_game();
        return true;
    }
    return false;
}

struct B1_007bec90_shapeb04_game { uint8_t b[216]; };
struct B2_007bec90_shapeb04_game { uint8_t b[4]; };

struct OB_NOVTABLE View_007bec90_shapeb04_game : public B1_007bec90_shapeb04_game, public B2_007bec90_shapeb04_game {
    virtual void Slot00_007bec90_shapeb04_game() = 0;
    virtual uint32_t Slot01_007bec90_shapeb04_game() = 0;
    bool QueryInterface(uint32_t iid, void** ppv);
};

// FUNCTION: 0x007bec90
bool View_007bec90_shapeb04_game::QueryInterface(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x1:
    case 0xca5c2f84:
        *ppv = this;
        Slot01_007bec90_shapeb04_game();
        return true;
    case 0x22ba0121:
        *ppv = static_cast<B1_007bec90_shapeb04_game*>(this);
        Slot01_007bec90_shapeb04_game();
        return true;
    case 0x452294aa:
        *ppv = static_cast<B2_007bec90_shapeb04_game*>(this);
        Slot01_007bec90_shapeb04_game();
        return true;
    }
    return false;
}

struct OB_NOVTABLE Obj_0082e9d0_shapeb04_game {
    virtual uint32_t Pad00_0082e9d0_shapeb04_game();
    virtual uint32_t Pad01_0082e9d0_shapeb04_game();
    virtual uint32_t Pad02_0082e9d0_shapeb04_game();
    virtual uint32_t Pad03_0082e9d0_shapeb04_game();
    virtual uint32_t Pad04_0082e9d0_shapeb04_game();
    virtual uint32_t Pad05_0082e9d0_shapeb04_game();
    virtual uint32_t Pad06_0082e9d0_shapeb04_game();
    virtual uint32_t Pad07_0082e9d0_shapeb04_game();
    virtual uint32_t Pad08_0082e9d0_shapeb04_game();
    virtual uint32_t Pad09_0082e9d0_shapeb04_game();
    virtual uint32_t Pad10_0082e9d0_shapeb04_game();
    virtual uint32_t Pad11_0082e9d0_shapeb04_game();
    virtual uint32_t Pad12_0082e9d0_shapeb04_game();
    virtual uint32_t Pad13_0082e9d0_shapeb04_game();
    virtual uint32_t Pad14_0082e9d0_shapeb04_game();
    virtual uint32_t Pad15_0082e9d0_shapeb04_game();
    virtual uint32_t Pad16_0082e9d0_shapeb04_game();
    virtual uint32_t Pad17_0082e9d0_shapeb04_game();
    virtual uint32_t Pad18_0082e9d0_shapeb04_game();
    virtual uint32_t Pad19_0082e9d0_shapeb04_game();
    virtual uint32_t Pad20_0082e9d0_shapeb04_game();
    virtual int32_t Slot21_0082e9d0_shapeb04_game(uint32_t k, uint32_t a, uint32_t b) = 0;
};

struct View_0082e9d0_shapeb04_game {
    uint8_t mPad[0x28];
    Obj_0082e9d0_shapeb04_game* mpObj;
    // STUB: 0x82cc60
    void Case2(uint32_t a, uint32_t b);
    // STUB: 0x82db00
    void Case1(uint32_t a, uint32_t b);
    void Fn(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0082e9d0 score 6
void View_0082e9d0_shapeb04_game::Fn(uint32_t a, uint32_t b)
{
    switch (mpObj->Slot21_0082e9d0_shapeb04_game(0x4, a, b)) {
    case 0:
        break;
    case 1:
        Case1(a, b);
        break;
    case 2:
        Case2(a, b);
        break;
    }
}
#endif

struct OB_NOVTABLE Obj_0082fa50_shapeb04_game {
    virtual uint32_t Pad00_0082fa50_shapeb04_game();
    virtual uint32_t Pad01_0082fa50_shapeb04_game();
    virtual uint32_t Pad02_0082fa50_shapeb04_game();
    virtual uint32_t Pad03_0082fa50_shapeb04_game();
    virtual uint32_t Pad04_0082fa50_shapeb04_game();
    virtual uint32_t Pad05_0082fa50_shapeb04_game();
    virtual uint32_t Pad06_0082fa50_shapeb04_game();
    virtual uint32_t Pad07_0082fa50_shapeb04_game();
    virtual uint32_t Pad08_0082fa50_shapeb04_game();
    virtual uint32_t Pad09_0082fa50_shapeb04_game();
    virtual uint32_t Pad10_0082fa50_shapeb04_game();
    virtual uint32_t Pad11_0082fa50_shapeb04_game();
    virtual uint32_t Pad12_0082fa50_shapeb04_game();
    virtual uint32_t Pad13_0082fa50_shapeb04_game();
    virtual uint32_t Pad14_0082fa50_shapeb04_game();
    virtual uint32_t Pad15_0082fa50_shapeb04_game();
    virtual uint32_t Pad16_0082fa50_shapeb04_game();
    virtual uint32_t Pad17_0082fa50_shapeb04_game();
    virtual uint32_t Pad18_0082fa50_shapeb04_game();
    virtual uint32_t Pad19_0082fa50_shapeb04_game();
    virtual uint32_t Pad20_0082fa50_shapeb04_game();
    virtual int32_t Slot21_0082fa50_shapeb04_game(uint32_t k, uint32_t a, uint32_t b) = 0;
};

struct View_0082fa50_shapeb04_game {
    uint8_t mPad[0x28];
    Obj_0082fa50_shapeb04_game* mpObj;
    // STUB: 0x82d5a0
    void Case2(uint32_t a, uint32_t b);
    // STUB: 0x82efe0
    void Case1(uint32_t a, uint32_t b);
    void Fn(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0082fa50 score 6
void View_0082fa50_shapeb04_game::Fn(uint32_t a, uint32_t b)
{
    switch (mpObj->Slot21_0082fa50_shapeb04_game(0x2, a, b)) {
    case 0:
        break;
    case 1:
        Case1(a, b);
        break;
    case 2:
        Case2(a, b);
        break;
    }
}
#endif

struct OB_NOVTABLE Obj_0082faa0_shapeb04_game {
    virtual uint32_t Pad00_0082faa0_shapeb04_game();
    virtual uint32_t Pad01_0082faa0_shapeb04_game();
    virtual uint32_t Pad02_0082faa0_shapeb04_game();
    virtual uint32_t Pad03_0082faa0_shapeb04_game();
    virtual uint32_t Pad04_0082faa0_shapeb04_game();
    virtual uint32_t Pad05_0082faa0_shapeb04_game();
    virtual uint32_t Pad06_0082faa0_shapeb04_game();
    virtual uint32_t Pad07_0082faa0_shapeb04_game();
    virtual uint32_t Pad08_0082faa0_shapeb04_game();
    virtual uint32_t Pad09_0082faa0_shapeb04_game();
    virtual uint32_t Pad10_0082faa0_shapeb04_game();
    virtual uint32_t Pad11_0082faa0_shapeb04_game();
    virtual uint32_t Pad12_0082faa0_shapeb04_game();
    virtual uint32_t Pad13_0082faa0_shapeb04_game();
    virtual uint32_t Pad14_0082faa0_shapeb04_game();
    virtual uint32_t Pad15_0082faa0_shapeb04_game();
    virtual uint32_t Pad16_0082faa0_shapeb04_game();
    virtual uint32_t Pad17_0082faa0_shapeb04_game();
    virtual uint32_t Pad18_0082faa0_shapeb04_game();
    virtual uint32_t Pad19_0082faa0_shapeb04_game();
    virtual uint32_t Pad20_0082faa0_shapeb04_game();
    virtual int32_t Slot21_0082faa0_shapeb04_game(uint32_t k, uint32_t a, uint32_t b) = 0;
};

struct View_0082faa0_shapeb04_game {
    uint8_t mPad[0x28];
    Obj_0082faa0_shapeb04_game* mpObj;
    // STUB: 0x82f240
    void Case2(uint32_t a, uint32_t b);
    // STUB: 0x82f1b0
    void Case1(uint32_t a, uint32_t b);
    void Fn(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0082faa0 score 6
void View_0082faa0_shapeb04_game::Fn(uint32_t a, uint32_t b)
{
    switch (mpObj->Slot21_0082faa0_shapeb04_game(0x3, a, b)) {
    case 0:
        break;
    case 1:
        Case1(a, b);
        break;
    case 2:
        Case2(a, b);
        break;
    }
}
#endif

struct OB_NOVTABLE Obj_0082faf0_shapeb04_game {
    virtual uint32_t Pad00_0082faf0_shapeb04_game();
    virtual uint32_t Pad01_0082faf0_shapeb04_game();
    virtual uint32_t Pad02_0082faf0_shapeb04_game();
    virtual uint32_t Pad03_0082faf0_shapeb04_game();
    virtual uint32_t Pad04_0082faf0_shapeb04_game();
    virtual uint32_t Pad05_0082faf0_shapeb04_game();
    virtual uint32_t Pad06_0082faf0_shapeb04_game();
    virtual uint32_t Pad07_0082faf0_shapeb04_game();
    virtual uint32_t Pad08_0082faf0_shapeb04_game();
    virtual uint32_t Pad09_0082faf0_shapeb04_game();
    virtual uint32_t Pad10_0082faf0_shapeb04_game();
    virtual uint32_t Pad11_0082faf0_shapeb04_game();
    virtual uint32_t Pad12_0082faf0_shapeb04_game();
    virtual uint32_t Pad13_0082faf0_shapeb04_game();
    virtual uint32_t Pad14_0082faf0_shapeb04_game();
    virtual uint32_t Pad15_0082faf0_shapeb04_game();
    virtual uint32_t Pad16_0082faf0_shapeb04_game();
    virtual uint32_t Pad17_0082faf0_shapeb04_game();
    virtual uint32_t Pad18_0082faf0_shapeb04_game();
    virtual uint32_t Pad19_0082faf0_shapeb04_game();
    virtual uint32_t Pad20_0082faf0_shapeb04_game();
    virtual int32_t Slot21_0082faf0_shapeb04_game(uint32_t k, uint32_t a, uint32_t b) = 0;
};

struct View_0082faf0_shapeb04_game {
    uint8_t mPad[0x28];
    Obj_0082faf0_shapeb04_game* mpObj;
    // STUB: 0x82e130
    void Case2(uint32_t a, uint32_t b);
    // STUB: 0x82f440
    void Case1(uint32_t a, uint32_t b);
    void Fn(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0082faf0 score 6
void View_0082faf0_shapeb04_game::Fn(uint32_t a, uint32_t b)
{
    switch (mpObj->Slot21_0082faf0_shapeb04_game(0x5, a, b)) {
    case 0:
        break;
    case 1:
        Case1(a, b);
        break;
    case 2:
        Case2(a, b);
        break;
    }
}
#endif

struct OB_NOVTABLE Obj_0082fb40_shapeb04_game {
    virtual uint32_t Pad00_0082fb40_shapeb04_game();
    virtual uint32_t Pad01_0082fb40_shapeb04_game();
    virtual uint32_t Pad02_0082fb40_shapeb04_game();
    virtual uint32_t Pad03_0082fb40_shapeb04_game();
    virtual uint32_t Pad04_0082fb40_shapeb04_game();
    virtual uint32_t Pad05_0082fb40_shapeb04_game();
    virtual uint32_t Pad06_0082fb40_shapeb04_game();
    virtual uint32_t Pad07_0082fb40_shapeb04_game();
    virtual uint32_t Pad08_0082fb40_shapeb04_game();
    virtual uint32_t Pad09_0082fb40_shapeb04_game();
    virtual uint32_t Pad10_0082fb40_shapeb04_game();
    virtual uint32_t Pad11_0082fb40_shapeb04_game();
    virtual uint32_t Pad12_0082fb40_shapeb04_game();
    virtual uint32_t Pad13_0082fb40_shapeb04_game();
    virtual uint32_t Pad14_0082fb40_shapeb04_game();
    virtual uint32_t Pad15_0082fb40_shapeb04_game();
    virtual uint32_t Pad16_0082fb40_shapeb04_game();
    virtual uint32_t Pad17_0082fb40_shapeb04_game();
    virtual uint32_t Pad18_0082fb40_shapeb04_game();
    virtual uint32_t Pad19_0082fb40_shapeb04_game();
    virtual uint32_t Pad20_0082fb40_shapeb04_game();
    virtual int32_t Slot21_0082fb40_shapeb04_game(uint32_t k, uint32_t a, uint32_t b) = 0;
};

struct View_0082fb40_shapeb04_game {
    uint8_t mPad[0x28];
    Obj_0082fb40_shapeb04_game* mpObj;
    // STUB: 0x82e5c0
    void Case2(uint32_t a, uint32_t b);
    // STUB: 0x82f5d0
    void Case1(uint32_t a, uint32_t b);
    void Fn(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0082fb40 score 6
void View_0082fb40_shapeb04_game::Fn(uint32_t a, uint32_t b)
{
    switch (mpObj->Slot21_0082fb40_shapeb04_game(0x7, a, b)) {
    case 0:
        break;
    case 1:
        Case1(a, b);
        break;
    case 2:
        Case2(a, b);
        break;
    }
}
#endif

struct OB_NOVTABLE Obj_0082fb90_shapeb04_game {
    virtual uint32_t Pad00_0082fb90_shapeb04_game();
    virtual uint32_t Pad01_0082fb90_shapeb04_game();
    virtual uint32_t Pad02_0082fb90_shapeb04_game();
    virtual uint32_t Pad03_0082fb90_shapeb04_game();
    virtual uint32_t Pad04_0082fb90_shapeb04_game();
    virtual uint32_t Pad05_0082fb90_shapeb04_game();
    virtual uint32_t Pad06_0082fb90_shapeb04_game();
    virtual uint32_t Pad07_0082fb90_shapeb04_game();
    virtual uint32_t Pad08_0082fb90_shapeb04_game();
    virtual uint32_t Pad09_0082fb90_shapeb04_game();
    virtual uint32_t Pad10_0082fb90_shapeb04_game();
    virtual uint32_t Pad11_0082fb90_shapeb04_game();
    virtual uint32_t Pad12_0082fb90_shapeb04_game();
    virtual uint32_t Pad13_0082fb90_shapeb04_game();
    virtual uint32_t Pad14_0082fb90_shapeb04_game();
    virtual uint32_t Pad15_0082fb90_shapeb04_game();
    virtual uint32_t Pad16_0082fb90_shapeb04_game();
    virtual uint32_t Pad17_0082fb90_shapeb04_game();
    virtual uint32_t Pad18_0082fb90_shapeb04_game();
    virtual uint32_t Pad19_0082fb90_shapeb04_game();
    virtual uint32_t Pad20_0082fb90_shapeb04_game();
    virtual int32_t Slot21_0082fb90_shapeb04_game(uint32_t k, uint32_t a, uint32_t b) = 0;
};

struct View_0082fb90_shapeb04_game {
    uint8_t mPad[0x28];
    Obj_0082fb90_shapeb04_game* mpObj;
    // STUB: 0x82e740
    void Case2(uint32_t a, uint32_t b);
    // STUB: 0x82f810
    void Case1(uint32_t a, uint32_t b);
    void Fn(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0082fb90 score 6
void View_0082fb90_shapeb04_game::Fn(uint32_t a, uint32_t b)
{
    switch (mpObj->Slot21_0082fb90_shapeb04_game(0x8, a, b)) {
    case 0:
        break;
    case 1:
        Case1(a, b);
        break;
    case 2:
        Case2(a, b);
        break;
    }
}
#endif

struct OB_NOVTABLE Obj_0082fbe0_shapeb04_game {
    virtual uint32_t Pad00_0082fbe0_shapeb04_game();
    virtual uint32_t Pad01_0082fbe0_shapeb04_game();
    virtual uint32_t Pad02_0082fbe0_shapeb04_game();
    virtual uint32_t Pad03_0082fbe0_shapeb04_game();
    virtual uint32_t Pad04_0082fbe0_shapeb04_game();
    virtual uint32_t Pad05_0082fbe0_shapeb04_game();
    virtual uint32_t Pad06_0082fbe0_shapeb04_game();
    virtual uint32_t Pad07_0082fbe0_shapeb04_game();
    virtual uint32_t Pad08_0082fbe0_shapeb04_game();
    virtual uint32_t Pad09_0082fbe0_shapeb04_game();
    virtual uint32_t Pad10_0082fbe0_shapeb04_game();
    virtual uint32_t Pad11_0082fbe0_shapeb04_game();
    virtual uint32_t Pad12_0082fbe0_shapeb04_game();
    virtual uint32_t Pad13_0082fbe0_shapeb04_game();
    virtual uint32_t Pad14_0082fbe0_shapeb04_game();
    virtual uint32_t Pad15_0082fbe0_shapeb04_game();
    virtual uint32_t Pad16_0082fbe0_shapeb04_game();
    virtual uint32_t Pad17_0082fbe0_shapeb04_game();
    virtual uint32_t Pad18_0082fbe0_shapeb04_game();
    virtual uint32_t Pad19_0082fbe0_shapeb04_game();
    virtual uint32_t Pad20_0082fbe0_shapeb04_game();
    virtual int32_t Slot21_0082fbe0_shapeb04_game(uint32_t k, uint32_t a, uint32_t b) = 0;
};

struct View_0082fbe0_shapeb04_game {
    uint8_t mPad[0x28];
    Obj_0082fbe0_shapeb04_game* mpObj;
    // STUB: 0x82e8a0
    void Case2(uint32_t a, uint32_t b);
    // STUB: 0x82f9c0
    void Case1(uint32_t a, uint32_t b);
    void Fn(uint32_t a, uint32_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0082fbe0 score 6
void View_0082fbe0_shapeb04_game::Fn(uint32_t a, uint32_t b)
{
    switch (mpObj->Slot21_0082fbe0_shapeb04_game(0x1, a, b)) {
    case 0:
        break;
    case 1:
        Case1(a, b);
        break;
    case 2:
        Case2(a, b);
        break;
    }
}
#endif

struct Rec_shapeb04_game {
    uint32_t mnLen;
    uint32_t mnCount;
    uint8_t mBuf[16];
    uint32_t mn20;
    uint32_t mn24;
    uint32_t mn28;
    uint32_t mn2c;
};

struct Deque_008eefc0_shapeb04_game {
    uint32_t mPad[4];
    Rec_shapeb04_game* mpCur;
    Rec_shapeb04_game* mpFirst;
    Rec_shapeb04_game* mpLast;
    // STUB: 0x008ecc20
    void PushAux(Rec_shapeb04_game* pItem);
};

struct View_008eefc0_shapeb04_game {
    uint32_t mnPad0;
    uint32_t mnPad4;
    Rec_shapeb04_game mRec;
    Deque_008eefc0_shapeb04_game mDeque;
    void Fn(uint32_t a, uint8_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008eefc0 score 44
void View_008eefc0_shapeb04_game::Fn(uint32_t a, uint8_t b)
{
    mRec.mnLen = 0;
    ++mRec.mnCount;
    mRec.mBuf[mRec.mnLen++] = 0xf;
    mRec.mBuf[mRec.mnLen++] = 0x71;
    mRec.mBuf[mRec.mnLen++] = static_cast<uint8_t>(a - 0x10);
    mRec.mBuf[mRec.mnLen++] = b;
    uint32_t t = 0x100 << a;
    mRec.mn2c = 1;
    mRec.mn20 = 0;
    mRec.mn24 = t;
    mRec.mn28 = t;
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

struct Deque_008ef070_shapeb04_game {
    uint32_t mPad[4];
    Rec_shapeb04_game* mpCur;
    Rec_shapeb04_game* mpFirst;
    Rec_shapeb04_game* mpLast;
    // STUB: 0x008ecc20
    void PushAux(Rec_shapeb04_game* pItem);
};

struct View_008ef070_shapeb04_game {
    uint32_t mnPad0;
    uint32_t mnPad4;
    Rec_shapeb04_game mRec;
    Deque_008ef070_shapeb04_game mDeque;
    void Fn(uint32_t a, uint8_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ef070 score 44
void View_008ef070_shapeb04_game::Fn(uint32_t a, uint8_t b)
{
    mRec.mnLen = 0;
    ++mRec.mnCount;
    mRec.mBuf[mRec.mnLen++] = 0xf;
    mRec.mBuf[mRec.mnLen++] = 0x72;
    mRec.mBuf[mRec.mnLen++] = static_cast<uint8_t>(a - 0x10);
    mRec.mBuf[mRec.mnLen++] = b;
    uint32_t t = 0x100 << a;
    mRec.mn2c = 1;
    mRec.mn20 = 0;
    mRec.mn24 = t;
    mRec.mn28 = t;
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

struct Deque_008ef120_shapeb04_game {
    uint32_t mPad[4];
    Rec_shapeb04_game* mpCur;
    Rec_shapeb04_game* mpFirst;
    Rec_shapeb04_game* mpLast;
    // STUB: 0x008ecc20
    void PushAux(Rec_shapeb04_game* pItem);
};

struct View_008ef120_shapeb04_game {
    uint32_t mnPad0;
    uint32_t mnPad4;
    Rec_shapeb04_game mRec;
    Deque_008ef120_shapeb04_game mDeque;
    void Fn(uint32_t a, uint8_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ef120 score 44
void View_008ef120_shapeb04_game::Fn(uint32_t a, uint8_t b)
{
    mRec.mnLen = 0;
    ++mRec.mnCount;
    mRec.mBuf[mRec.mnLen++] = 0xf;
    mRec.mBuf[mRec.mnLen++] = 0x71;
    mRec.mBuf[mRec.mnLen++] = static_cast<uint8_t>(a - 0x30);
    mRec.mBuf[mRec.mnLen++] = b;
    uint32_t t = 0x100 << a;
    mRec.mn2c = 1;
    mRec.mn20 = 0;
    mRec.mn24 = t;
    mRec.mn28 = t;
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

struct Deque_008ef1d0_shapeb04_game {
    uint32_t mPad[4];
    Rec_shapeb04_game* mpCur;
    Rec_shapeb04_game* mpFirst;
    Rec_shapeb04_game* mpLast;
    // STUB: 0x008ecc20
    void PushAux(Rec_shapeb04_game* pItem);
};

struct View_008ef1d0_shapeb04_game {
    uint32_t mnPad0;
    uint32_t mnPad4;
    Rec_shapeb04_game mRec;
    Deque_008ef1d0_shapeb04_game mDeque;
    void Fn(uint32_t a, uint8_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ef1d0 score 44
void View_008ef1d0_shapeb04_game::Fn(uint32_t a, uint8_t b)
{
    mRec.mnLen = 0;
    ++mRec.mnCount;
    mRec.mBuf[mRec.mnLen++] = 0xf;
    mRec.mBuf[mRec.mnLen++] = 0x72;
    mRec.mBuf[mRec.mnLen++] = static_cast<uint8_t>(a - 0x30);
    mRec.mBuf[mRec.mnLen++] = b;
    uint32_t t = 0x100 << a;
    mRec.mn2c = 1;
    mRec.mn20 = 0;
    mRec.mn24 = t;
    mRec.mn28 = t;
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

struct Deque_008ef280_shapeb04_game {
    uint32_t mPad[4];
    Rec_shapeb04_game* mpCur;
    Rec_shapeb04_game* mpFirst;
    Rec_shapeb04_game* mpLast;
    // STUB: 0x008ecc20
    void PushAux(Rec_shapeb04_game* pItem);
};

struct View_008ef280_shapeb04_game {
    uint32_t mnPad0;
    uint32_t mnPad4;
    Rec_shapeb04_game mRec;
    Deque_008ef280_shapeb04_game mDeque;
    void Fn(uint32_t a, uint8_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ef280 score 44
void View_008ef280_shapeb04_game::Fn(uint32_t a, uint8_t b)
{
    mRec.mnLen = 0;
    ++mRec.mnCount;
    mRec.mBuf[mRec.mnLen++] = 0xf;
    mRec.mBuf[mRec.mnLen++] = 0x73;
    mRec.mBuf[mRec.mnLen++] = static_cast<uint8_t>(a - 0x30);
    mRec.mBuf[mRec.mnLen++] = b;
    uint32_t t = 0x100 << a;
    mRec.mn2c = 1;
    mRec.mn20 = 0;
    mRec.mn24 = t;
    mRec.mn28 = t;
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

struct Deque_008ef330_shapeb04_game {
    uint32_t mPad[4];
    Rec_shapeb04_game* mpCur;
    Rec_shapeb04_game* mpFirst;
    Rec_shapeb04_game* mpLast;
    // STUB: 0x008ecc20
    void PushAux(Rec_shapeb04_game* pItem);
};

struct View_008ef330_shapeb04_game {
    uint32_t mnPad0;
    uint32_t mnPad4;
    Rec_shapeb04_game mRec;
    Deque_008ef330_shapeb04_game mDeque;
    void Fn(uint32_t a, uint8_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ef330 score 44
void View_008ef330_shapeb04_game::Fn(uint32_t a, uint8_t b)
{
    mRec.mnLen = 0;
    ++mRec.mnCount;
    mRec.mBuf[mRec.mnLen++] = 0xf;
    mRec.mBuf[mRec.mnLen++] = 0x71;
    mRec.mBuf[mRec.mnLen++] = static_cast<uint8_t>(a - 0x20);
    mRec.mBuf[mRec.mnLen++] = b;
    uint32_t t = 0x100 << a;
    mRec.mn2c = 1;
    mRec.mn20 = 0;
    mRec.mn24 = t;
    mRec.mn28 = t;
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

struct Deque_008ef3e0_shapeb04_game {
    uint32_t mPad[4];
    Rec_shapeb04_game* mpCur;
    Rec_shapeb04_game* mpFirst;
    Rec_shapeb04_game* mpLast;
    // STUB: 0x008ecc20
    void PushAux(Rec_shapeb04_game* pItem);
};

struct View_008ef3e0_shapeb04_game {
    uint32_t mnPad0;
    uint32_t mnPad4;
    Rec_shapeb04_game mRec;
    Deque_008ef3e0_shapeb04_game mDeque;
    void Fn(uint32_t a, uint8_t b);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ef3e0 score 44
void View_008ef3e0_shapeb04_game::Fn(uint32_t a, uint8_t b)
{
    mRec.mnLen = 0;
    ++mRec.mnCount;
    mRec.mBuf[mRec.mnLen++] = 0xf;
    mRec.mBuf[mRec.mnLen++] = 0x72;
    mRec.mBuf[mRec.mnLen++] = static_cast<uint8_t>(a - 0x20);
    mRec.mBuf[mRec.mnLen++] = b;
    uint32_t t = 0x100 << a;
    mRec.mn2c = 1;
    mRec.mn20 = 0;
    mRec.mn24 = t;
    mRec.mn28 = t;
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

inline const uint32_t& Max_shapeb04_game(const uint32_t& a, const uint32_t& b)
{
    return a < b ? b : a;
}

struct Elem_00802330_shapeb04_game {
    uint8_t mData[52];
    // STUB: 0x802130
    void Copy(Elem_00802330_shapeb04_game* pSrc);
};

// STUB: 0x8022b0
Elem_00802330_shapeb04_game* Fn008022b0_00802330(Elem_00802330_shapeb04_game* pFirst, Elem_00802330_shapeb04_game* pLast, Elem_00802330_shapeb04_game* pDest, bool* pTag);

// STUB: 0x8021f0
void Fn008021f0_00802330(Elem_00802330_shapeb04_game* pFirst, Elem_00802330_shapeb04_game* pLast, bool* pTag);

struct View_00802330_shapeb04_game {
    Elem_00802330_shapeb04_game* mpBegin;
    Elem_00802330_shapeb04_game* mpEnd;
    Elem_00802330_shapeb04_game* mpCap;
    void Fn(Elem_00802330_shapeb04_game* pPos, Elem_00802330_shapeb04_game* pVal, uint32_t unused, uint32_t n, bool atEnd);
};

// FUNCTION: 0x00802330
void View_00802330_shapeb04_game::Fn(Elem_00802330_shapeb04_game* pPos, Elem_00802330_shapeb04_game* pVal, uint32_t /*unused*/, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t len = Max_shapeb04_game(oldSize, n) + oldSize;
    Elem_00802330_shapeb04_game* pBuf;
    if (len) {
        pBuf = static_cast<Elem_00802330_shapeb04_game*>(_STL::__stl_new(len * 52));
    } else {
        pBuf = 0;
    }
    Elem_00802330_shapeb04_game* pDst = pBuf;
    for (Elem_00802330_shapeb04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t m = n;
    if (m == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; m > 0; --m) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!atEnd) {
        pDst = Fn008022b0_00802330(pPos, mpEnd, pDst, &atEnd);
    }
    Fn008021f0_00802330(mpBegin, mpEnd, &atEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
    mpEnd = pDst;
    mpCap = pBuf + len;
    mpBegin = pBuf;
}

struct Elem_0074efc0_shapeb04_game {
    uint8_t mData[76];
    // STUB: 0x749040
    void Copy(Elem_0074efc0_shapeb04_game* pSrc);
};

// STUB: 0x749f20
Elem_0074efc0_shapeb04_game* Fn00749f20_0074efc0(Elem_0074efc0_shapeb04_game* pFirst, Elem_0074efc0_shapeb04_game* pLast, Elem_0074efc0_shapeb04_game* pDest, bool* pTag);

// STUB: 0x749f50
void Fn00749f50_0074efc0(Elem_0074efc0_shapeb04_game* pFirst, Elem_0074efc0_shapeb04_game* pLast, bool* pTag);

struct View_0074efc0_shapeb04_game {
    Elem_0074efc0_shapeb04_game* mpBegin;
    Elem_0074efc0_shapeb04_game* mpEnd;
    Elem_0074efc0_shapeb04_game* mpCap;
    void Fn(Elem_0074efc0_shapeb04_game* pPos, Elem_0074efc0_shapeb04_game* pVal, uint32_t unused, uint32_t n, bool atEnd);
};

// FUNCTION: 0x0074efc0
void View_0074efc0_shapeb04_game::Fn(Elem_0074efc0_shapeb04_game* pPos, Elem_0074efc0_shapeb04_game* pVal, uint32_t /*unused*/, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t len = Max_shapeb04_game(oldSize, n) + oldSize;
    Elem_0074efc0_shapeb04_game* pBuf;
    if (len) {
        pBuf = static_cast<Elem_0074efc0_shapeb04_game*>(_STL::__stl_new(len * 76));
    } else {
        pBuf = 0;
    }
    Elem_0074efc0_shapeb04_game* pDst = pBuf;
    for (Elem_0074efc0_shapeb04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t m = n;
    if (m == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; m > 0; --m) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!atEnd) {
        pDst = Fn00749f20_0074efc0(pPos, mpEnd, pDst, &atEnd);
    }
    Fn00749f50_0074efc0(mpBegin, mpEnd, &atEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
    mpEnd = pDst;
    mpCap = pBuf + len;
    mpBegin = pBuf;
}

struct Elem_00512b60_shapeb04_game {
    uint8_t mData[108];
    // STUB: 0x510fa0
    void Copy(Elem_00512b60_shapeb04_game* pSrc);
};

// STUB: 0x511960
Elem_00512b60_shapeb04_game* Fn00511960_00512b60(Elem_00512b60_shapeb04_game* pFirst, Elem_00512b60_shapeb04_game* pLast, Elem_00512b60_shapeb04_game* pDest, bool* pTag);

// STUB: 0x510650
void Fn00510650_00512b60(Elem_00512b60_shapeb04_game* pFirst, Elem_00512b60_shapeb04_game* pLast, bool* pTag);

struct View_00512b60_shapeb04_game {
    Elem_00512b60_shapeb04_game* mpBegin;
    Elem_00512b60_shapeb04_game* mpEnd;
    Elem_00512b60_shapeb04_game* mpCap;
    void Fn(Elem_00512b60_shapeb04_game* pPos, Elem_00512b60_shapeb04_game* pVal, uint32_t unused, uint32_t n, bool atEnd);
};

// FUNCTION: 0x00512b60
void View_00512b60_shapeb04_game::Fn(Elem_00512b60_shapeb04_game* pPos, Elem_00512b60_shapeb04_game* pVal, uint32_t /*unused*/, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t len = Max_shapeb04_game(oldSize, n) + oldSize;
    Elem_00512b60_shapeb04_game* pBuf;
    if (len) {
        pBuf = static_cast<Elem_00512b60_shapeb04_game*>(_STL::__stl_new(len * 108));
    } else {
        pBuf = 0;
    }
    Elem_00512b60_shapeb04_game* pDst = pBuf;
    for (Elem_00512b60_shapeb04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t m = n;
    if (m == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; m > 0; --m) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!atEnd) {
        pDst = Fn00511960_00512b60(pPos, mpEnd, pDst, &atEnd);
    }
    Fn00510650_00512b60(mpBegin, mpEnd, &atEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
    mpEnd = pDst;
    mpCap = pBuf + len;
    mpBegin = pBuf;
}

struct Elem_006818c0_shapeb04_game {
    uint8_t mData[44];
    // STUB: 0x680d20
    void Copy(Elem_006818c0_shapeb04_game* pSrc);
};

// STUB: 0x6812c0
Elem_006818c0_shapeb04_game* Fn006812c0_006818c0(Elem_006818c0_shapeb04_game* pFirst, Elem_006818c0_shapeb04_game* pLast, Elem_006818c0_shapeb04_game* pDest, bool* pTag);

// STUB: 0x680d90
void Fn00680d90_006818c0(Elem_006818c0_shapeb04_game* pFirst, Elem_006818c0_shapeb04_game* pLast, bool* pTag);

struct View_006818c0_shapeb04_game {
    Elem_006818c0_shapeb04_game* mpBegin;
    Elem_006818c0_shapeb04_game* mpEnd;
    Elem_006818c0_shapeb04_game* mpCap;
    void Fn(Elem_006818c0_shapeb04_game* pPos, Elem_006818c0_shapeb04_game* pVal, uint32_t unused, uint32_t n, bool atEnd);
};

// FUNCTION: 0x006818c0
void View_006818c0_shapeb04_game::Fn(Elem_006818c0_shapeb04_game* pPos, Elem_006818c0_shapeb04_game* pVal, uint32_t /*unused*/, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t len = Max_shapeb04_game(oldSize, n) + oldSize;
    Elem_006818c0_shapeb04_game* pBuf;
    if (len) {
        pBuf = static_cast<Elem_006818c0_shapeb04_game*>(_STL::__stl_new(len * 44));
    } else {
        pBuf = 0;
    }
    Elem_006818c0_shapeb04_game* pDst = pBuf;
    for (Elem_006818c0_shapeb04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t m = n;
    if (m == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; m > 0; --m) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!atEnd) {
        pDst = Fn006812c0_006818c0(pPos, mpEnd, pDst, &atEnd);
    }
    Fn00680d90_006818c0(mpBegin, mpEnd, &atEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
    mpEnd = pDst;
    mpCap = pBuf + len;
    mpBegin = pBuf;
}

struct Elem_00589260_shapeb04_game {
    uint8_t mData[100];
    // STUB: 0x587890
    void Copy(Elem_00589260_shapeb04_game* pSrc);
};

// STUB: 0x588330
Elem_00589260_shapeb04_game* Fn00588330_00589260(Elem_00589260_shapeb04_game* pFirst, Elem_00589260_shapeb04_game* pLast, Elem_00589260_shapeb04_game* pDest, bool* pTag);

// STUB: 0x588760
void Fn00588760_00589260(Elem_00589260_shapeb04_game* pFirst, Elem_00589260_shapeb04_game* pLast, bool* pTag);

struct View_00589260_shapeb04_game {
    Elem_00589260_shapeb04_game* mpBegin;
    Elem_00589260_shapeb04_game* mpEnd;
    Elem_00589260_shapeb04_game* mpCap;
    void Fn(Elem_00589260_shapeb04_game* pPos, Elem_00589260_shapeb04_game* pVal, uint32_t unused, uint32_t n, bool atEnd);
};

// FUNCTION: 0x00589260
void View_00589260_shapeb04_game::Fn(Elem_00589260_shapeb04_game* pPos, Elem_00589260_shapeb04_game* pVal, uint32_t /*unused*/, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t len = Max_shapeb04_game(oldSize, n) + oldSize;
    Elem_00589260_shapeb04_game* pBuf;
    if (len) {
        pBuf = static_cast<Elem_00589260_shapeb04_game*>(_STL::__stl_new(len * 100));
    } else {
        pBuf = 0;
    }
    Elem_00589260_shapeb04_game* pDst = pBuf;
    for (Elem_00589260_shapeb04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t m = n;
    if (m == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; m > 0; --m) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!atEnd) {
        pDst = Fn00588330_00589260(pPos, mpEnd, pDst, &atEnd);
    }
    Fn00588760_00589260(mpBegin, mpEnd, &atEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
    mpEnd = pDst;
    mpCap = pBuf + len;
    mpBegin = pBuf;
}

struct Elem_0064e0e0_shapeb04_game {
    uint8_t mData[44];
    // STUB: 0x64cfa0
    void Copy(Elem_0064e0e0_shapeb04_game* pSrc);
};

// STUB: 0x64d270
Elem_0064e0e0_shapeb04_game* Fn0064d270_0064e0e0(Elem_0064e0e0_shapeb04_game* pFirst, Elem_0064e0e0_shapeb04_game* pLast, Elem_0064e0e0_shapeb04_game* pDest, bool* pTag);

// STUB: 0x64d450
void Fn0064d450_0064e0e0(Elem_0064e0e0_shapeb04_game* pFirst, Elem_0064e0e0_shapeb04_game* pLast, bool* pTag);

struct View_0064e0e0_shapeb04_game {
    Elem_0064e0e0_shapeb04_game* mpBegin;
    Elem_0064e0e0_shapeb04_game* mpEnd;
    Elem_0064e0e0_shapeb04_game* mpCap;
    void Fn(Elem_0064e0e0_shapeb04_game* pPos, Elem_0064e0e0_shapeb04_game* pVal, uint32_t unused, uint32_t n, bool atEnd);
};

// FUNCTION: 0x0064e0e0
void View_0064e0e0_shapeb04_game::Fn(Elem_0064e0e0_shapeb04_game* pPos, Elem_0064e0e0_shapeb04_game* pVal, uint32_t /*unused*/, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t len = Max_shapeb04_game(oldSize, n) + oldSize;
    Elem_0064e0e0_shapeb04_game* pBuf;
    if (len) {
        pBuf = static_cast<Elem_0064e0e0_shapeb04_game*>(_STL::__stl_new(len * 44));
    } else {
        pBuf = 0;
    }
    Elem_0064e0e0_shapeb04_game* pDst = pBuf;
    for (Elem_0064e0e0_shapeb04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t m = n;
    if (m == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; m > 0; --m) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!atEnd) {
        pDst = Fn0064d270_0064e0e0(pPos, mpEnd, pDst, &atEnd);
    }
    Fn0064d450_0064e0e0(mpBegin, mpEnd, &atEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
    mpEnd = pDst;
    mpCap = pBuf + len;
    mpBegin = pBuf;
}

struct Elem_008b5ff0_shapeb04_game {
    uint8_t mData[44];
    // STUB: 0x8b5f20
    void Copy(Elem_008b5ff0_shapeb04_game* pSrc);
};

// STUB: 0x8b5f90
Elem_008b5ff0_shapeb04_game* Fn008b5f90_008b5ff0(Elem_008b5ff0_shapeb04_game* pFirst, Elem_008b5ff0_shapeb04_game* pLast, Elem_008b5ff0_shapeb04_game* pDest, bool* pTag);

// STUB: 0x8b5ed0
void Fn008b5ed0_008b5ff0(Elem_008b5ff0_shapeb04_game* pFirst, Elem_008b5ff0_shapeb04_game* pLast, bool* pTag);

struct View_008b5ff0_shapeb04_game {
    Elem_008b5ff0_shapeb04_game* mpBegin;
    Elem_008b5ff0_shapeb04_game* mpEnd;
    Elem_008b5ff0_shapeb04_game* mpCap;
    void Fn(Elem_008b5ff0_shapeb04_game* pPos, Elem_008b5ff0_shapeb04_game* pVal, uint32_t unused, uint32_t n, bool atEnd);
};

// FUNCTION: 0x008b5ff0
void View_008b5ff0_shapeb04_game::Fn(Elem_008b5ff0_shapeb04_game* pPos, Elem_008b5ff0_shapeb04_game* pVal, uint32_t /*unused*/, uint32_t n, bool atEnd)
{
    uint32_t oldSize = static_cast<uint32_t>(mpEnd - mpBegin);
    uint32_t len = Max_shapeb04_game(oldSize, n) + oldSize;
    Elem_008b5ff0_shapeb04_game* pBuf;
    if (len) {
        pBuf = static_cast<Elem_008b5ff0_shapeb04_game*>(_STL::__stl_new(len * 44));
    } else {
        pBuf = 0;
    }
    Elem_008b5ff0_shapeb04_game* pDst = pBuf;
    for (Elem_008b5ff0_shapeb04_game* p = mpBegin; p != pPos; ++p) {
        if (pDst) {
            pDst->Copy(p);
        }
        ++pDst;
    }
    uint32_t m = n;
    if (m == 1) {
        if (pDst) {
            pDst->Copy(pVal);
        }
        ++pDst;
    } else {
        for (; m > 0; --m) {
            if (pDst) {
                pDst->Copy(pVal);
            }
            ++pDst;
        }
    }
    if (!atEnd) {
        pDst = Fn008b5f90_008b5ff0(pPos, mpEnd, pDst, &atEnd);
    }
    Fn008b5ed0_008b5ff0(mpBegin, mpEnd, &atEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
    mpEnd = pDst;
    mpCap = pBuf + len;
    mpBegin = pBuf;
}
