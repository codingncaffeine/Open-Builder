// Shape families of packet top_shape07_game, written by scratch/s16/gen/top_shape07_game/gen.py.
#include "common/types.h"
#include "common/compiler.h"

#ifdef _MSC_VER
#define OB_CDECL_TS07 __cdecl
#else
#define OB_CDECL_TS07
#endif

struct Str_top_shape07_game {
    uint16_t* mpStart;
    uint16_t* mpFinish;
    uint32_t pad8;
    uint32_t padC;
    uint32_t pad10;
    // STUB: 0x00408a70
    Str_top_shape07_game& AssignDispatch(uint16_t* pFirst, uint16_t* pLast, const void* pTag);
};

struct StrHolder_top_shape07_game {
    uint32_t pad0;
    Str_top_shape07_game mStr;
};

struct Elem12_top_shape07_game {
    uint32_t a;
    uint32_t b;
    uint32_t c;
};

struct View_00602c90_top_shape07_game {
    uint8_t pad[0x18];
    Str_top_shape07_game mStr;
    void Fn00602c90(StrHolder_top_shape07_game* pOther);
};

// FUNCTION: 0x00602c90
void View_00602c90_top_shape07_game::Fn00602c90(StrHolder_top_shape07_game* pOther)
{
    Str_top_shape07_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
}

struct Dst_00447350_top_shape07_game {
    uint32_t pad[3];
    // STUB: 0x004470a0
    void Copy(const Elem12_top_shape07_game* pSrc);
};

// FUNCTION: 0x00447350
Dst_00447350_top_shape07_game* Fn00447350(const Elem12_top_shape07_game* pFirst, const Elem12_top_shape07_game* pLast, Dst_00447350_top_shape07_game* pDst)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        pDst->Copy(pFirst);
        ++pFirst;
        ++pDst;
    }
    return pDst;
}

struct Dst_005867b0_top_shape07_game {
    uint32_t pad[3];
    // STUB: 0x00464430
    void Copy(const Elem12_top_shape07_game* pSrc);
};

// FUNCTION: 0x005867b0
Dst_005867b0_top_shape07_game* Fn005867b0(const Elem12_top_shape07_game* pFirst, const Elem12_top_shape07_game* pLast, Dst_005867b0_top_shape07_game* pDst)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        pDst->Copy(pFirst);
        ++pFirst;
        ++pDst;
    }
    return pDst;
}

struct Dst_005f3b90_top_shape07_game {
    uint32_t pad[3];
    // STUB: 0x005f3940
    void Copy(const Elem12_top_shape07_game* pSrc);
};

// FUNCTION: 0x005f3b90
Dst_005f3b90_top_shape07_game* Fn005f3b90(const Elem12_top_shape07_game* pFirst, const Elem12_top_shape07_game* pLast, Dst_005f3b90_top_shape07_game* pDst)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        pDst->Copy(pFirst);
        ++pFirst;
        ++pDst;
    }
    return pDst;
}

struct Dst_00611c60_top_shape07_game {
    uint32_t pad[3];
    // STUB: 0x00611b00
    void Copy(const Elem12_top_shape07_game* pSrc);
};

// FUNCTION: 0x00611c60
Dst_00611c60_top_shape07_game* Fn00611c60(const Elem12_top_shape07_game* pFirst, const Elem12_top_shape07_game* pLast, Dst_00611c60_top_shape07_game* pDst)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        pDst->Copy(pFirst);
        ++pFirst;
        ++pDst;
    }
    return pDst;
}

struct View_004f0240_top_shape07_game {
    uint8_t pad[0x1c];
    uint32_t mnRefs;
    uint32_t Fn004f0240();
};

// FUNCTION: 0x004f0240
uint32_t View_004f0240_top_shape07_game::Fn004f0240()
{
    return ++mnRefs;
}

struct View_005af940_top_shape07_game {
    uint8_t pad[0x204];
    uint32_t mnRefs;
    uint32_t Fn005af940();
};

// FUNCTION: 0x005af940
uint32_t View_005af940_top_shape07_game::Fn005af940()
{
    return ++mnRefs;
}

struct View_005d7b40_top_shape07_game {
    uint8_t pad[0x24];
    uint32_t mnRefs;
    uint32_t Fn005d7b40();
};

// FUNCTION: 0x005d7b40
uint32_t View_005d7b40_top_shape07_game::Fn005d7b40()
{
    return ++mnRefs;
}

struct View_0060c730_top_shape07_game {
    uint8_t pad[0x6c];
    uint32_t mnRefs;
    uint32_t Fn0060c730();
};

// FUNCTION: 0x0060c730
uint32_t View_0060c730_top_shape07_game::Fn0060c730()
{
    return ++mnRefs;
}

struct View_0098ae40_top_shape07_game {
    uint8_t pad[0x48];
    uint32_t mnRefs;
    uint32_t Fn0098ae40();
};

// FUNCTION: 0x0098ae40
uint32_t View_0098ae40_top_shape07_game::Fn0098ae40()
{
    return ++mnRefs;
}

struct View_0098b820_top_shape07_game {
    uint8_t pad[0x30];
    uint32_t mnRefs;
    uint32_t Fn0098b820();
};

// FUNCTION: 0x0098b820
uint32_t View_0098b820_top_shape07_game::Fn0098b820()
{
    return ++mnRefs;
}

struct Last_005fd390_top_shape07_game {
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
    virtual bool Op(uint32_t w);
};

struct Mid_005fd390_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Last_005fd390_top_shape07_game* GetLast();
};

struct Obj_005fd390_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual Mid_005fd390_top_shape07_game* GetMid(uint32_t v);
};

// FUNCTION: 0x005fd390
bool Fn005fd390(Obj_005fd390_top_shape07_game* pObj, uint32_t v, uint32_t w)
{
    bool bResult = false;
    Mid_005fd390_top_shape07_game* pMid = pObj->GetMid(v);
    if (pMid) {
        bResult = pMid->GetLast()->Op(w);
    }
    return bResult;
}

struct Last_005fd3c0_top_shape07_game {
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
    virtual bool Op(uint32_t w);
};

struct Mid_005fd3c0_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Last_005fd3c0_top_shape07_game* GetLast();
};

struct Obj_005fd3c0_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual Mid_005fd3c0_top_shape07_game* GetMid(uint32_t v);
};

// FUNCTION: 0x005fd3c0
bool Fn005fd3c0(Obj_005fd3c0_top_shape07_game* pObj, uint32_t v, uint32_t w)
{
    bool bResult = false;
    Mid_005fd3c0_top_shape07_game* pMid = pObj->GetMid(v);
    if (pMid) {
        bResult = pMid->GetLast()->Op(w);
    }
    return bResult;
}

struct Last_005fd3f0_top_shape07_game {
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
    virtual bool Op(uint32_t w);
};

struct Mid_005fd3f0_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Last_005fd3f0_top_shape07_game* GetLast();
};

struct Obj_005fd3f0_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual Mid_005fd3f0_top_shape07_game* GetMid(uint32_t v);
};

// FUNCTION: 0x005fd3f0
bool Fn005fd3f0(Obj_005fd3f0_top_shape07_game* pObj, uint32_t v, uint32_t w)
{
    bool bResult = false;
    Mid_005fd3f0_top_shape07_game* pMid = pObj->GetMid(v);
    if (pMid) {
        bResult = pMid->GetLast()->Op(w);
    }
    return bResult;
}

struct Last_005fd420_top_shape07_game {
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
    virtual bool Op(uint32_t w);
};

struct Mid_005fd420_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Last_005fd420_top_shape07_game* GetLast();
};

struct Obj_005fd420_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual Mid_005fd420_top_shape07_game* GetMid(uint32_t v);
};

// FUNCTION: 0x005fd420
bool Fn005fd420(Obj_005fd420_top_shape07_game* pObj, uint32_t v, uint32_t w)
{
    bool bResult = false;
    Mid_005fd420_top_shape07_game* pMid = pObj->GetMid(v);
    if (pMid) {
        bResult = pMid->GetLast()->Op(w);
    }
    return bResult;
}

struct Last_005fd450_top_shape07_game {
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
    virtual bool Op(uint32_t w);
};

struct Mid_005fd450_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Last_005fd450_top_shape07_game* GetLast();
};

struct Obj_005fd450_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual Mid_005fd450_top_shape07_game* GetMid(uint32_t v);
};

// FUNCTION: 0x005fd450
bool Fn005fd450(Obj_005fd450_top_shape07_game* pObj, uint32_t v, uint32_t w)
{
    bool bResult = false;
    Mid_005fd450_top_shape07_game* pMid = pObj->GetMid(v);
    if (pMid) {
        bResult = pMid->GetLast()->Op(w);
    }
    return bResult;
}

struct Last_005fd480_top_shape07_game {
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
    virtual bool Op(uint32_t w);
};

struct Mid_005fd480_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Last_005fd480_top_shape07_game* GetLast();
};

struct Obj_005fd480_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual Mid_005fd480_top_shape07_game* GetMid(uint32_t v);
};

// FUNCTION: 0x005fd480
bool Fn005fd480(Obj_005fd480_top_shape07_game* pObj, uint32_t v, uint32_t w)
{
    bool bResult = false;
    Mid_005fd480_top_shape07_game* pMid = pObj->GetMid(v);
    if (pMid) {
        bResult = pMid->GetLast()->Op(w);
    }
    return bResult;
}

struct Last_005fd4b0_top_shape07_game {
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
    virtual bool Op(uint32_t w);
};

struct Mid_005fd4b0_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Last_005fd4b0_top_shape07_game* GetLast();
};

struct Obj_005fd4b0_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual Mid_005fd4b0_top_shape07_game* GetMid(uint32_t v);
};

// FUNCTION: 0x005fd4b0
bool Fn005fd4b0(Obj_005fd4b0_top_shape07_game* pObj, uint32_t v, uint32_t w)
{
    bool bResult = false;
    Mid_005fd4b0_top_shape07_game* pMid = pObj->GetMid(v);
    if (pMid) {
        bResult = pMid->GetLast()->Op(w);
    }
    return bResult;
}

struct Last_005fd4f0_top_shape07_game {
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
    virtual bool Op(uint32_t w);
};

struct Mid_005fd4f0_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Last_005fd4f0_top_shape07_game* GetLast();
};

struct Obj_005fd4f0_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual Mid_005fd4f0_top_shape07_game* GetMid(uint32_t v);
};

// FUNCTION: 0x005fd4f0
bool Fn005fd4f0(Obj_005fd4f0_top_shape07_game* pObj, uint32_t v, uint32_t w)
{
    bool bResult = false;
    Mid_005fd4f0_top_shape07_game* pMid = pObj->GetMid(v);
    if (pMid) {
        bResult = pMid->GetLast()->Op(w);
    }
    return bResult;
}

struct Last_005fd530_top_shape07_game {
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
    virtual bool Op(uint32_t w);
};

struct Mid_005fd530_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Last_005fd530_top_shape07_game* GetLast();
};

struct Obj_005fd530_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual Mid_005fd530_top_shape07_game* GetMid(uint32_t v);
};

// FUNCTION: 0x005fd530
bool Fn005fd530(Obj_005fd530_top_shape07_game* pObj, uint32_t v, uint32_t w)
{
    bool bResult = false;
    Mid_005fd530_top_shape07_game* pMid = pObj->GetMid(v);
    if (pMid) {
        bResult = pMid->GetLast()->Op(w);
    }
    return bResult;
}

struct Last_005fd570_top_shape07_game {
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
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual bool Op(uint32_t w);
};

struct Mid_005fd570_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual Last_005fd570_top_shape07_game* GetLast();
};

struct Obj_005fd570_top_shape07_game {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual Mid_005fd570_top_shape07_game* GetMid(uint32_t v);
};

// FUNCTION: 0x005fd570
bool Fn005fd570(Obj_005fd570_top_shape07_game* pObj, uint32_t v, uint32_t w)
{
    bool bResult = false;
    Mid_005fd570_top_shape07_game* pMid = pObj->GetMid(v);
    if (pMid) {
        bResult = pMid->GetLast()->Op(w);
    }
    return bResult;
}

// STUB: 0x000088ca80
void Fn000088ca80();

// STUB: 0x000088d820
void Fn000088d820();

// STUB: 0x000088c9c0
void Fn000088c9c0();

// STUB: 0x000088dec0
void Fn000088dec0();

// STUB: 0x000088c990
void Fn000088c990();

// FUNCTION: 0x0088f310
void* Fn0088f310(uint32_t n)
{
    switch (n) {
    case 7:
        return reinterpret_cast<void*>(&Fn000088ca80);
    case 3:
        return reinterpret_cast<void*>(&Fn000088d820);
    case 4:
    case 5:
        return reinterpret_cast<void*>(&Fn000088c9c0);
    case 0:
        return reinterpret_cast<void*>(&Fn000088dec0);
    case 1:
    case 2:
        return reinterpret_cast<void*>(&Fn000088c990);
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    default:
        return 0;
    }
}

// STUB: 0x000088e9f0
void Fn000088e9f0();

// STUB: 0x000088e5c0
void Fn000088e5c0();

// STUB: 0x000088e340
void Fn000088e340();

// STUB: 0x000088ee80
void Fn000088ee80();

// STUB: 0x000088cd60
void Fn000088cd60();

// FUNCTION: 0x0088f380
void* Fn0088f380(uint32_t n)
{
    switch (n) {
    case 7:
        return reinterpret_cast<void*>(&Fn000088e9f0);
    case 3:
        return reinterpret_cast<void*>(&Fn000088e5c0);
    case 4:
    case 5:
        return reinterpret_cast<void*>(&Fn000088e340);
    case 0:
        return reinterpret_cast<void*>(&Fn000088ee80);
    case 1:
    case 2:
        return reinterpret_cast<void*>(&Fn000088cd60);
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    default:
        return 0;
    }
}

// STUB: 0x000088dae0
void Fn000088dae0();

// STUB: 0x000088ce10
void Fn000088ce10();

// STUB: 0x000088d580
void Fn000088d580();

// STUB: 0x000088de80
void Fn000088de80();

// STUB: 0x000088cb40
void Fn000088cb40();

// FUNCTION: 0x0088f3f0
void* Fn0088f3f0(uint32_t n)
{
    switch (n) {
    case 7:
        return reinterpret_cast<void*>(&Fn000088dae0);
    case 3:
        return reinterpret_cast<void*>(&Fn000088ce10);
    case 4:
    case 5:
        return reinterpret_cast<void*>(&Fn000088d580);
    case 0:
        return reinterpret_cast<void*>(&Fn000088de80);
    case 1:
    case 2:
        return reinterpret_cast<void*>(&Fn000088cb40);
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    default:
        return 0;
    }
}

// STUB: 0x000088e900
void Fn000088e900();

// STUB: 0x000088ced0
void Fn000088ced0();

// STUB: 0x000088e250
void Fn000088e250();

// STUB: 0x000088ed90
void Fn000088ed90();

// STUB: 0x000088ccb0
void Fn000088ccb0();

// FUNCTION: 0x0088f460
void* Fn0088f460(uint32_t n)
{
    switch (n) {
    case 7:
        return reinterpret_cast<void*>(&Fn000088e900);
    case 3:
        return reinterpret_cast<void*>(&Fn000088ced0);
    case 4:
    case 5:
        return reinterpret_cast<void*>(&Fn000088e250);
    case 0:
        return reinterpret_cast<void*>(&Fn000088ed90);
    case 1:
    case 2:
        return reinterpret_cast<void*>(&Fn000088ccb0);
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    default:
        return 0;
    }
}

// STUB: 0x000088daa0
void Fn000088daa0();

// STUB: 0x000088d740
void Fn000088d740();

// STUB: 0x000088d4b0
void Fn000088d4b0();

// STUB: 0x000088dda0
void Fn000088dda0();

// STUB: 0x000088d320
void Fn000088d320();

// FUNCTION: 0x0088f4d0
void* Fn0088f4d0(uint32_t n)
{
    switch (n) {
    case 7:
        return reinterpret_cast<void*>(&Fn000088daa0);
    case 3:
        return reinterpret_cast<void*>(&Fn000088d740);
    case 4:
    case 5:
        return reinterpret_cast<void*>(&Fn000088d4b0);
    case 0:
        return reinterpret_cast<void*>(&Fn000088dda0);
    case 1:
    case 2:
        return reinterpret_cast<void*>(&Fn000088d320);
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    default:
        return 0;
    }
}

// STUB: 0x000088e840
void Fn000088e840();

// STUB: 0x000088e4f0
void Fn000088e4f0();

// STUB: 0x000088e180
void Fn000088e180();

// STUB: 0x000088ecb0
void Fn000088ecb0();

// STUB: 0x000088f130
void Fn000088f130();

// FUNCTION: 0x0088f540
void* Fn0088f540(uint32_t n)
{
    switch (n) {
    case 7:
        return reinterpret_cast<void*>(&Fn000088e840);
    case 3:
        return reinterpret_cast<void*>(&Fn000088e4f0);
    case 4:
    case 5:
        return reinterpret_cast<void*>(&Fn000088e180);
    case 0:
        return reinterpret_cast<void*>(&Fn000088ecb0);
    case 1:
    case 2:
        return reinterpret_cast<void*>(&Fn000088f130);
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    default:
        return 0;
    }
}

// STUB: 0x000088d8f0
void Fn000088d8f0();

// STUB: 0x000088d670
void Fn000088d670();

// STUB: 0x000088c960
void Fn000088c960();

// STUB: 0x000088dbd0
void Fn000088dbd0();

// STUB: 0x000088df00
void Fn000088df00();

// FUNCTION: 0x0088f5b0
void* Fn0088f5b0(uint32_t n)
{
    switch (n) {
    case 7:
        return reinterpret_cast<void*>(&Fn000088d8f0);
    case 3:
        return reinterpret_cast<void*>(&Fn000088d670);
    case 4:
    case 5:
        return reinterpret_cast<void*>(&Fn000088c960);
    case 0:
        return reinterpret_cast<void*>(&Fn000088dbd0);
    case 1:
    case 2:
        return reinterpret_cast<void*>(&Fn000088df00);
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    default:
        return 0;
    }
}

// STUB: 0x000088e690
void Fn000088e690();

// STUB: 0x000088e420
void Fn000088e420();

// STUB: 0x000088cbe0
void Fn000088cbe0();

// STUB: 0x000088ead0
void Fn000088ead0();

// STUB: 0x000088ef60
void Fn000088ef60();

// FUNCTION: 0x0088f620
void* Fn0088f620(uint32_t n)
{
    switch (n) {
    case 7:
        return reinterpret_cast<void*>(&Fn000088e690);
    case 3:
        return reinterpret_cast<void*>(&Fn000088e420);
    case 4:
    case 5:
        return reinterpret_cast<void*>(&Fn000088cbe0);
    case 0:
        return reinterpret_cast<void*>(&Fn000088ead0);
    case 1:
    case 2:
        return reinterpret_cast<void*>(&Fn000088ef60);
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    default:
        return 0;
    }
}

// STUB: 0x000088d9d0
void Fn000088d9d0();

// STUB: 0x000088f210
void Fn000088f210();

// STUB: 0x000088d3f0
void Fn000088d3f0();

// STUB: 0x000088dcb0
void Fn000088dcb0();

// STUB: 0x000088dfd0
void Fn000088dfd0();

// FUNCTION: 0x0088f690
void* Fn0088f690(uint32_t n)
{
    switch (n) {
    case 7:
        return reinterpret_cast<void*>(&Fn000088d9d0);
    case 3:
        return reinterpret_cast<void*>(&Fn000088f210);
    case 4:
    case 5:
        return reinterpret_cast<void*>(&Fn000088d3f0);
    case 0:
        return reinterpret_cast<void*>(&Fn000088dcb0);
    case 1:
    case 2:
        return reinterpret_cast<void*>(&Fn000088dfd0);
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    default:
        return 0;
    }
}

// STUB: 0x000088e770
void Fn000088e770();

// STUB: 0x000088f250
void Fn000088f250();

// STUB: 0x000088e0b0
void Fn000088e0b0();

// STUB: 0x000088ebb0
void Fn000088ebb0();

// STUB: 0x000088f040
void Fn000088f040();

// FUNCTION: 0x0088f700
void* Fn0088f700(uint32_t n)
{
    switch (n) {
    case 7:
        return reinterpret_cast<void*>(&Fn000088e770);
    case 3:
        return reinterpret_cast<void*>(&Fn000088f250);
    case 4:
    case 5:
        return reinterpret_cast<void*>(&Fn000088e0b0);
    case 0:
        return reinterpret_cast<void*>(&Fn000088ebb0);
    case 1:
    case 2:
        return reinterpret_cast<void*>(&Fn000088f040);
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    default:
        return 0;
    }
}

// STUB: 0x00986a50
void OB_CDECL_TS07 Fn00986a50(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);

// FUNCTION: 0x00988cc0
void OB_STDCALL Fn00988cc0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    Fn00986a50(a1, a2, a3, a4, a5);
}

// STUB: 0x00986e80
void OB_CDECL_TS07 Fn00986e80(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);

// FUNCTION: 0x00988cf0
void OB_STDCALL Fn00988cf0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    Fn00986e80(a1, a2, a3, a4, a5);
}

// STUB: 0x00987220
void OB_CDECL_TS07 Fn00987220(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);

// FUNCTION: 0x00988d20
void OB_STDCALL Fn00988d20(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    Fn00987220(a1, a2, a3, a4, a5);
}

// STUB: 0x00987440
void OB_CDECL_TS07 Fn00987440(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);

// FUNCTION: 0x00988d50
void OB_STDCALL Fn00988d50(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    Fn00987440(a1, a2, a3, a4, a5);
}

// STUB: 0x00987bc0
void OB_CDECL_TS07 Fn00987bc0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);

// FUNCTION: 0x00988e20
void OB_STDCALL Fn00988e20(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    Fn00987bc0(a1, a2, a3, a4, a5);
}

// STUB: 0x00987e60
void OB_CDECL_TS07 Fn00987e60(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);

// FUNCTION: 0x00988e50
void OB_STDCALL Fn00988e50(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    Fn00987e60(a1, a2, a3, a4, a5);
}

// STUB: 0x009885d0
void OB_CDECL_TS07 Fn009885d0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);

// FUNCTION: 0x00988ea0
void OB_STDCALL Fn00988ea0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    Fn009885d0(a1, a2, a3, a4, a5);
}

// STUB: 0x009891e0
void OB_CDECL_TS07 Fn009891e0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);

// FUNCTION: 0x00989710
void OB_STDCALL Fn00989710(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    Fn009891e0(a1, a2, a3, a4, a5);
}

// STUB: 0x00989270
void OB_CDECL_TS07 Fn00989270(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);

// FUNCTION: 0x00989740
void OB_STDCALL Fn00989740(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    Fn00989270(a1, a2, a3, a4, a5);
}

// STUB: 0x00989470
void OB_CDECL_TS07 Fn00989470(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);

// FUNCTION: 0x009897d0
void OB_STDCALL Fn009897d0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    Fn00989470(a1, a2, a3, a4, a5);
}
