// Shape families of packet shape07_game, written by scratch/s16/gen/shape07_game/gen.sh.
#include "common/types.h"

struct Str_shape07_game {
    uint16_t* mpStart;
    uint16_t* mpFinish;
    uint32_t pad8;
    uint32_t padC;
    uint32_t pad10;
    // STUB: 0x00408a70
    Str_shape07_game& AssignDispatch(uint16_t* pFirst, uint16_t* pLast, const void* pTag);
};

struct StrHolder_shape07_game {
    uint32_t pad0;
    Str_shape07_game mStr;
};

struct Elem12_shape07_game {
    uint32_t a;
    uint32_t b;
    uint32_t c;
};

struct Query_shape07_game {
    uint32_t v[4];
};

struct QueryObj_shape07_game {
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
    virtual void GetQuery(Query_shape07_game* pOut);
};

struct View_008196b0_shape07_game {
    uint8_t pad[0x58];
    Str_shape07_game mStr;
    void Fn008196b0(StrHolder_shape07_game* pOther);
};

// FUNCTION: 0x008196b0
void View_008196b0_shape07_game::Fn008196b0(StrHolder_shape07_game* pOther)
{
    Str_shape07_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
}

struct View_00822000_shape07_game {
    uint8_t pad[0x20];
    Str_shape07_game mStr;
    void Fn00822000(StrHolder_shape07_game* pOther);
};

// FUNCTION: 0x00822000
void View_00822000_shape07_game::Fn00822000(StrHolder_shape07_game* pOther)
{
    Str_shape07_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
}

struct View_00822030_shape07_game {
    uint8_t pad[0x34];
    Str_shape07_game mStr;
    void Fn00822030(StrHolder_shape07_game* pOther);
};

// FUNCTION: 0x00822030
void View_00822030_shape07_game::Fn00822030(StrHolder_shape07_game* pOther)
{
    Str_shape07_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
}

struct View_00822060_shape07_game {
    uint8_t pad[0x48];
    Str_shape07_game mStr;
    void Fn00822060(StrHolder_shape07_game* pOther);
};

// FUNCTION: 0x00822060
void View_00822060_shape07_game::Fn00822060(StrHolder_shape07_game* pOther)
{
    Str_shape07_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
}

struct View_00822090_shape07_game {
    uint8_t pad[0x5c];
    Str_shape07_game mStr;
    void Fn00822090(StrHolder_shape07_game* pOther);
};

// FUNCTION: 0x00822090
void View_00822090_shape07_game::Fn00822090(StrHolder_shape07_game* pOther)
{
    Str_shape07_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
}

struct View_008220c0_shape07_game {
    uint8_t pad[0x70];
    Str_shape07_game mStr;
    void Fn008220c0(StrHolder_shape07_game* pOther);
};

// FUNCTION: 0x008220c0
void View_008220c0_shape07_game::Fn008220c0(StrHolder_shape07_game* pOther)
{
    Str_shape07_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
}

struct View_008220f0_shape07_game {
    uint8_t pad[0x84];
    Str_shape07_game mStr;
    void Fn008220f0(StrHolder_shape07_game* pOther);
};

// FUNCTION: 0x008220f0
void View_008220f0_shape07_game::Fn008220f0(StrHolder_shape07_game* pOther)
{
    Str_shape07_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
}

struct View_00822120_shape07_game {
    uint8_t pad[0x98];
    Str_shape07_game mStr;
    void Fn00822120(StrHolder_shape07_game* pOther);
};

// FUNCTION: 0x00822120
void View_00822120_shape07_game::Fn00822120(StrHolder_shape07_game* pOther)
{
    Str_shape07_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
}

struct View_00822150_shape07_game {
    uint8_t pad[0xac];
    Str_shape07_game mStr;
    void Fn00822150(StrHolder_shape07_game* pOther);
};

// FUNCTION: 0x00822150
void View_00822150_shape07_game::Fn00822150(StrHolder_shape07_game* pOther)
{
    Str_shape07_game* pSrc = pOther ? &pOther->mStr : 0;
    if (pSrc != &mStr) {
        mStr.AssignDispatch(pSrc->mpStart, pSrc->mpFinish, &pOther);
    }
}

// STUB: 0x004c3d70
bool Fn004c3d70(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t q0, uint32_t q1);

// FUNCTION: 0x004c5310
bool Fn004c5310(uint32_t a1, uint32_t a2, uint32_t a3, QueryObj_shape07_game* pObj)
{
    if (pObj) {
        Query_shape07_game q;
        pObj->GetQuery(&q);
        return Fn004c3d70(a1, a2, a3, q.v[0], q.v[1]);
    }
    return false;
}

// STUB: 0x004c5280
bool Fn004c5280(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t q0, uint32_t q1);

// FUNCTION: 0x004c67f0
bool Fn004c67f0(uint32_t a1, uint32_t a2, uint32_t a3, QueryObj_shape07_game* pObj)
{
    if (pObj) {
        Query_shape07_game q;
        pObj->GetQuery(&q);
        return Fn004c5280(a1, a2, a3, q.v[0], q.v[1]);
    }
    return false;
}

// STUB: 0x004c7690
bool Fn004c7690(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t q0, uint32_t q1);

// FUNCTION: 0x004c9e60
bool Fn004c9e60(uint32_t a1, uint32_t a2, uint32_t a3, QueryObj_shape07_game* pObj)
{
    if (pObj) {
        Query_shape07_game q;
        pObj->GetQuery(&q);
        return Fn004c7690(a1, a2, a3, q.v[0], q.v[1]);
    }
    return false;
}

// STUB: 0x004c76f0
bool Fn004c76f0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t q0, uint32_t q1);

// FUNCTION: 0x004c9ea0
bool Fn004c9ea0(uint32_t a1, uint32_t a2, uint32_t a3, QueryObj_shape07_game* pObj)
{
    if (pObj) {
        Query_shape07_game q;
        pObj->GetQuery(&q);
        return Fn004c76f0(a1, a2, a3, q.v[0], q.v[1]);
    }
    return false;
}

// STUB: 0x004c7760
bool Fn004c7760(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t q0, uint32_t q1);

// FUNCTION: 0x004c9ee0
bool Fn004c9ee0(uint32_t a1, uint32_t a2, uint32_t a3, QueryObj_shape07_game* pObj)
{
    if (pObj) {
        Query_shape07_game q;
        pObj->GetQuery(&q);
        return Fn004c7760(a1, a2, a3, q.v[0], q.v[1]);
    }
    return false;
}

// STUB: 0x004c77d0
bool Fn004c77d0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t q0, uint32_t q1);

// FUNCTION: 0x004c9f20
bool Fn004c9f20(uint32_t a1, uint32_t a2, uint32_t a3, QueryObj_shape07_game* pObj)
{
    if (pObj) {
        Query_shape07_game q;
        pObj->GetQuery(&q);
        return Fn004c77d0(a1, a2, a3, q.v[0], q.v[1]);
    }
    return false;
}

// STUB: 0x004c7840
bool Fn004c7840(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t q0, uint32_t q1);

// FUNCTION: 0x004c9f60
bool Fn004c9f60(uint32_t a1, uint32_t a2, uint32_t a3, QueryObj_shape07_game* pObj)
{
    if (pObj) {
        Query_shape07_game q;
        pObj->GetQuery(&q);
        return Fn004c7840(a1, a2, a3, q.v[0], q.v[1]);
    }
    return false;
}

// STUB: 0x004c78b0
bool Fn004c78b0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t q0, uint32_t q1);

// FUNCTION: 0x004c9fa0
bool Fn004c9fa0(uint32_t a1, uint32_t a2, uint32_t a3, QueryObj_shape07_game* pObj)
{
    if (pObj) {
        Query_shape07_game q;
        pObj->GetQuery(&q);
        return Fn004c78b0(a1, a2, a3, q.v[0], q.v[1]);
    }
    return false;
}

// STUB: 0x004cade0
bool Fn004cade0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t q0, uint32_t q1);

// FUNCTION: 0x004cc120
bool Fn004cc120(uint32_t a1, uint32_t a2, uint32_t a3, QueryObj_shape07_game* pObj)
{
    if (pObj) {
        Query_shape07_game q;
        pObj->GetQuery(&q);
        return Fn004cade0(a1, a2, a3, q.v[0], q.v[1]);
    }
    return false;
}

// STUB: 0x004cc160
bool Fn004cc160(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t q0, uint32_t q1);

// FUNCTION: 0x004cdc80
bool Fn004cdc80(uint32_t a1, uint32_t a2, uint32_t a3, QueryObj_shape07_game* pObj)
{
    if (pObj) {
        Query_shape07_game q;
        pObj->GetQuery(&q);
        return Fn004cc160(a1, a2, a3, q.v[0], q.v[1]);
    }
    return false;
}

struct Dst_0050dca0_shape07_game {
    uint32_t pad[3];
    // STUB: 0x00461210
    void Copy(const Elem12_shape07_game* pSrc);
};

// FUNCTION: 0x0050dca0
Dst_0050dca0_shape07_game* Fn0050dca0(const Elem12_shape07_game* pFirst, const Elem12_shape07_game* pLast, Dst_0050dca0_shape07_game* pDst)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        pDst->Copy(pFirst);
        ++pFirst;
        ++pDst;
    }
    return pDst;
}

struct Dst_0064b5c0_shape07_game {
    uint32_t pad[3];
    // STUB: 0x0050c540
    void Copy(const Elem12_shape07_game* pSrc);
};

// FUNCTION: 0x0064b5c0
Dst_0064b5c0_shape07_game* Fn0064b5c0(const Elem12_shape07_game* pFirst, const Elem12_shape07_game* pLast, Dst_0064b5c0_shape07_game* pDst)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        pDst->Copy(pFirst);
        ++pFirst;
        ++pDst;
    }
    return pDst;
}

struct Dst_0064fa10_shape07_game {
    uint32_t pad[3];
    // STUB: 0x0064f770
    void Copy(const Elem12_shape07_game* pSrc);
};

// FUNCTION: 0x0064fa10
Dst_0064fa10_shape07_game* Fn0064fa10(const Elem12_shape07_game* pFirst, const Elem12_shape07_game* pLast, Dst_0064fa10_shape07_game* pDst)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        pDst->Copy(pFirst);
        ++pFirst;
        ++pDst;
    }
    return pDst;
}

struct Dst_0064faf0_shape07_game {
    uint32_t pad[3];
    // STUB: 0x0050db90
    void Copy(const Elem12_shape07_game* pSrc);
};

// FUNCTION: 0x0064faf0
Dst_0064faf0_shape07_game* Fn0064faf0(const Elem12_shape07_game* pFirst, const Elem12_shape07_game* pLast, Dst_0064faf0_shape07_game* pDst)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        pDst->Copy(pFirst);
        ++pFirst;
        ++pDst;
    }
    return pDst;
}

struct Dst_0068d690_shape07_game {
    uint32_t pad[3];
    // STUB: 0x00465a10
    void Copy(const Elem12_shape07_game* pSrc);
};

// FUNCTION: 0x0068d690
Dst_0068d690_shape07_game* Fn0068d690(const Elem12_shape07_game* pFirst, const Elem12_shape07_game* pLast, Dst_0068d690_shape07_game* pDst)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        pDst->Copy(pFirst);
        ++pFirst;
        ++pDst;
    }
    return pDst;
}

struct Dst_00706ef0_shape07_game {
    uint32_t pad[3];
    // STUB: 0x00462c10
    void Copy(const Elem12_shape07_game* pSrc);
};

// FUNCTION: 0x00706ef0
Dst_00706ef0_shape07_game* Fn00706ef0(const Elem12_shape07_game* pFirst, const Elem12_shape07_game* pLast, Dst_00706ef0_shape07_game* pDst)
{
    for (int32_t n = pLast - pFirst; n > 0; --n) {
        pDst->Copy(pFirst);
        ++pFirst;
        ++pDst;
    }
    return pDst;
}

struct View_00459530_shape07_game {
    uint8_t pad[0x34];
    uint32_t mnRefs;
    uint32_t Fn00459530();
};

// FUNCTION: 0x00459530
uint32_t View_00459530_shape07_game::Fn00459530()
{
    return ++mnRefs;
}

struct View_004f1f60_shape07_game {
    uint8_t pad[0x7c];
    uint32_t mnRefs;
    uint32_t Fn004f1f60();
};

// FUNCTION: 0x004f1f60
uint32_t View_004f1f60_shape07_game::Fn004f1f60()
{
    return ++mnRefs;
}

struct View_0060c830_shape07_game {
    uint8_t pad[0x68];
    uint32_t mnRefs;
    uint32_t Fn0060c830();
};

// FUNCTION: 0x0060c830
uint32_t View_0060c830_shape07_game::Fn0060c830()
{
    return ++mnRefs;
}

struct View_0079a070_shape07_game {
    uint8_t pad[0x3c];
    uint32_t mnRefs;
    uint32_t Fn0079a070();
};

// FUNCTION: 0x0079a070
uint32_t View_0079a070_shape07_game::Fn0079a070()
{
    return ++mnRefs;
}

