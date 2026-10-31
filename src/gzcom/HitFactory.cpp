#include <stddef.h>
#include "classes/cGZAny_AnyString.h"
#include "classes/cHitList.h"
#include "classes/cHitResourceFactory.h"
#include "classes/cHitResource_cHitList.h"
#include "classes/cGZPersistResourceFactory.h"
#include "classes/cGZPropertySetT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612.h"
#include "classes/cGZPropertySetSerializerBinaryT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612.h"
#include "classes/cHitPropertySetTrackResource.h"
#include "classes/cHitResource_cHitTrackPlayer.h"
#include "classes/cGZPropertySetSerializerXmlT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612.h"

typedef cGZPropertySetT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612 cPropSet_ad27d4;
typedef cGZPropertySetSerializerBinaryT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612 cPropSerBin_ad4468;
typedef cGZPropertySetSerializerXmlT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612 cPropSerXml_ad442c;

// The copy constructor of the string (a copy of another any).
struct cAnyString_ad43d8 {
    // STUB: 0x00940627
    void* CopyConstruct(const cGZAny_AnyString* pSource);
};

// The list of longs the hit list keeps (its size() is at 0x00940695).
struct cListLong_ad4648 {
    void* mpNode;
    // STUB: 0x00940695
    uint32_t size();
};

// The red-black tree of the property set (find by key is the library's 0x0098129c).
struct cNode_ad27d4 {
    uint32_t mColor;
    cNode_ad27d4* mpParent;
    cNode_ad27d4* mpLeft;
    cNode_ad27d4* mpRight;
    uint32_t mKey;
    void* mpValue;
};
struct cTree_ad27d4 {
    cNode_ad27d4* mpHeader;
    // STUB: 0x0098129c
    cNode_ad27d4* Find(const uint32_t& key);
};

// The tree iterator step (a free function of the library).
// STUB: 0x0040d4c0
cNode_ad27d4* Fn0040d4c0_ad27d4(cNode_ad27d4* pNode);

// A value holder: the property set hands values through slot 1.
struct cValue_ad27d4 {
    virtual void Pad0();
    virtual bool Slot1(void* pValue);
};

// The counted pointer the string keeps (assignment at 0x0094909a).
struct cAutoRef_ad43d8 {
    void* mp;
    // STUB: 0x0094909a
    cAutoRef_ad43d8& Assign(void* p);
};

// The string object behind an any-string (slot 12 assigns from another).
struct cStrObj_ad43d8 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Fn12(void* pSource, uint32_t nFlag);
};

// FUNCTION: 0x00940dac
uint32_t cGZAny_AnyString::Slot06_ad251c()
{
    return Slot05_ad251c() - 4;
}

// FUNCTION: 0x009404c2
bool cHitList::SetCriterion(uint32_t aCriterion)
{
    mnCriterion = static_cast<int32_t>(aCriterion);
    mbCriterionSet = 1;
    return true;
}

// FUNCTION: 0x0093ff38
uint32_t cHitResourceFactory::Release()
{
    if (--mnRefCount == 0) {
        delete this;
        return 0;
    }
    return mnRefCount;
}

// FUNCTION: 0x0093ffd4
uint32_t cGZPropertySetSerializerBinaryT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612::Release()
{
    if (--mnRefCount <= 0) {
        delete this;
        return 0;
    }
    return mnRefCount;
}

// FUNCTION: 0x00940613
void cGZAny_AnyString::Slot03_ad251c(uint32_t aDest)
{
    if (aDest) {
        OB_PTR(cAnyString_ad43d8, aDest)->CopyConstruct(this);
    }
}

// FUNCTION: 0x00939279
uint32_t cGZPropertySetT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612::Release()
{
    if (mnRefCount <= 1) {
        delete this;
        return 0;
    }
    return --mnRefCount;
}

// FUNCTION: 0x0093feeb
void cHitResourceFactory::CreateInstance_4(uint32_t a, uint32_t b, uint32_t c)
{
    CreateInstance(a, b, OB_PTR(void, c), 0, 0);
}

// FUNCTION: 0x0093ff03
void cGZPersistResourceFactory::Slot08_ad8c20(uint32_t a, uint32_t b, uint32_t c)
{
    CreateInstance(a, b, c, 0, 0);
}

// FUNCTION: 0x0094067a
uint32_t cHitList::NumItems()
{
    cListLong_ad4648* pB = reinterpret_cast<cListLong_ad4648*>(&mpListB);
    uint32_t n = pB->size();
    return reinterpret_cast<cListLong_ad4648*>(&mpListA)->size() + n;
}

// FUNCTION: 0x0093932e
bool cGZPropertySetT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612::HasValue(uint32_t aKey)
{
    cTree_ad27d4* pTree = reinterpret_cast<cTree_ad27d4*>(&mpTreeHeader);
    return pTree->Find(*OB_PTR(uint32_t, aKey)) != pTree->mpHeader;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00940649 score 9
void cGZAny_AnyString::Slot08_ad251c(uint32_t aOther)
{
    cGZAny_AnyString* pOther = OB_PTR(cGZAny_AnyString, aOther);
    cStrObj_ad43d8* pMine = static_cast<cStrObj_ad43d8*>(mpString);
    void* pSource = pOther->mpString;
    pMine->Fn12(pSource, 1);
}
#endif

// FUNCTION: 0x0094070e
uint32_t cGZPropertySetSerializerXmlT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612::Slot02_ad442c()
{
    if (--mnRefCount <= 0) {
        delete this;
        return 0;
    }
    return mnRefCount;
}

// FUNCTION: 0x009405d9
bool cGZAny_AnyString::Slot02_ad251c(uint32_t aSource)
{
    cGZAny_AnyString* pSource = OB_PTR(cGZAny_AnyString, aSource);
    uint32_t nOther = pSource->Slot04_ad251c();
    if (nOther == Slot04_ad251c()) {
        if (&pSource->mpString != &mpString) {
            reinterpret_cast<cAutoRef_ad43d8*>(&mpString)->Assign(pSource->mpString);
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x0094059b
bool cGZAny_AnyString::Slot01_ad251c(uint32_t aSource)
{
    cGZAny_AnyString* pSource = OB_PTR(cGZAny_AnyString, aSource);
    if (pSource) {
        uint32_t nOther = pSource->Slot04_ad251c();
        if (Slot04_ad251c() == nOther) {
            if (&pSource->mpString != &mpString) {
                reinterpret_cast<cAutoRef_ad43d8*>(&mpString)->Assign(pSource->mpString);
            }
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x00939254
bool cGZPropertySetT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612::QueryInterface(unsigned int aId, void** ppOut)
{
    if (aId == 1 || aId == 0xebb10cdd) {
        *ppOut = this;
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x0093ffe8
bool cGZPropertySetSerializerBinaryT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612::QueryInterface(uint32_t aId, uint32_t aOut)
{
    if (aId == 1 || aId == 0xebe701f3) {
        *OB_PTR(void*, aOut) = this;
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x00939306
bool cGZPropertySetT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612::Value(uint32_t aKey, uint32_t aOut)
{
    cTree_ad27d4* pTree = reinterpret_cast<cTree_ad27d4*>(&mpTreeHeader);
    cNode_ad27d4* pNode = pTree->Find(*OB_PTR(uint32_t, aKey));
    if (pNode != pTree->mpHeader) {
        void* pValue = pNode->mpValue;
        return OB_PTR(cValue_ad27d4, aOut)->Slot1(pValue);
    }
    return false;
}

// FUNCTION: 0x00939290
bool cGZPropertySetT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612::FirstKeyAndValue(uint32_t aKeyOut, uint32_t aValueOut)
{
    uint32_t* pKey = OB_PTR(uint32_t, aKeyOut);
    void** ppValue = OB_PTR(void*, aValueOut);
    if (pKey && ppValue) {
        cNode_ad27d4* pFirst = static_cast<cNode_ad27d4*>(mpTreeHeader)->mpLeft;
        bool bFound = pFirst != mpTreeHeader;
        mpCursor = pFirst;
        if (bFound) {
            *pKey = pFirst->mKey;
            *ppValue = pFirst->mpValue;
        }
        return bFound;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009392c7 score 20
bool cGZPropertySetT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612::NextKeyAndValue(uint32_t aKeyOut, uint32_t aValueOut)
{
    cNode_ad27d4* pNext = Fn0040d4c0_ad27d4(static_cast<cNode_ad27d4*>(mpCursor));
    uint32_t* pKey = OB_PTR(uint32_t, aKeyOut);
    mpCursor = pNext;
    if (pKey) {
        void** ppValue = OB_PTR(void*, aValueOut);
        if (ppValue) {
            bool bFound = pNext != mpTreeHeader;
            if (bFound) {
                *pKey = pNext->mKey;
                *ppValue = pNext->mpValue;
            }
            return bFound;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009404d2 score 2
bool cHitResource_cHitList::QueryInterface(unsigned int aId, void** ppOut)
{
    if (aId == 0x3b93c5e7 || aId == 0x456b8f1d) {
        *ppOut = static_cast<cUnk00ad2620*>(this);
        AddRef();
        return true;
    }
    return cHitList::QueryInterface(aId, ppOut);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00940312 score 2
bool cHitResource_cHitTrackPlayer::QueryInterface(unsigned int aId, void** ppOut)
{
    if (aId == 0x3b93c5e7 || aId == 0x456b8f1d) {
        *ppOut = static_cast<cUnk00ad2620*>(this);
        AddRef();
        return true;
    }
    return cHitTrackPlayer::QueryInterface(aId, ppOut);
}
#endif

// FUNCTION: 0x00939796
bool cHitPropertySetTrackResource::QueryInterface(unsigned int aId, void** ppOut)
{
    if (aId == 0x3b93c5e7 || aId == 0x456b8f1d) {
        *ppOut = static_cast<cUnk00ad2620*>(this);
        ++mnRefCount;
        return true;
    }
    return cPropSet_ad27d4::QueryInterface(aId, ppOut);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00940722 score 25
bool cGZPropertySetSerializerXmlT_cKeyStandardTraitsT_unsigned_long_340718371_1806839612::QueryInterface(uint32_t aId, uint32_t aOut)
{
    void** ppOut = OB_PTR(void*, aOut);
    if (aId == 1 || aId == 0x4b6b9c9b || aId == 0xebe701f3) {
        if (aId == 0x4b6b9c9b) {
            *ppOut = static_cast<cUnk00ad21ec*>(this);
        } else {
            *ppOut = this;
        }
        Slot01_ad442c();
        return true;
    }
    return false;
}
#endif

// An interface of the stream or record objects the factory is handed (slot 0 asks for another interface).
struct cStream_ad40d0 {
    virtual bool QueryInterface(uint32_t id, void** ppOut);
    virtual void AddRef();
    virtual void Release();
};

// A resource the factory made: slot 4 sets its key, slot 12 reads and slot 13 writes it through a stream.
struct cPersistRes_ad40d0 {
    virtual bool QueryInterface(uint32_t id, void** ppOut);
    virtual void AddRef();
    virtual void Release();
    virtual void Pad3();
    virtual void SetKey(uint32_t* pKey);
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual bool Read(void* pStream, uint32_t aFlags, uint32_t aUser);
    virtual bool Write(void* pStream, uint32_t aFlags, uint32_t aUser);
};

// The database record: slot 3 gives the key of the record.
struct cRecord_ad40d0 {
    virtual bool QueryInterface(uint32_t id, void** ppOut);
    virtual void AddRef();
    virtual void Release();
    virtual uint32_t* GetKey(uint32_t* pBuffer);
};

// FUNCTION: 0x00940041
bool cHitResourceFactory::Write(uint32_t aResource, uint32_t aRecord)
{
    cStream_ad40d0* pStream = 0;
    if (OB_PTR(cStream_ad40d0, aRecord)->QueryInterface(0xc51b11cb, reinterpret_cast<void**>(&pStream))) {
        cPersistRes_ad40d0* pPersist = 0;
        OB_PTR(cStream_ad40d0, aResource)->QueryInterface(0x3b93c5e7, reinterpret_cast<void**>(&pPersist));
        bool bOk = pPersist->Write(pStream, 0, 0);
        if (pPersist) {
            pPersist->Release();
        }
        if (pStream) {
            pStream->Release();
        }
        return bOk;
    }
    if (pStream) {
        pStream->Release();
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009400b2 score 36
bool cHitResourceFactory::Slot03_ad40d0(uint32_t aRecord, uint32_t aId, uint32_t aOut, uint32_t aFlags, uint32_t aUser)
{
    cPersistRes_ad40d0* pCreated = 0;
    cRecord_ad40d0* pRecord = OB_PTR(cRecord_ad40d0, aRecord);
    uint32_t aKey[3];
    if (CreateInstance(*pRecord->GetKey(aKey), 0x3b93c5e7, &pCreated, aFlags, aUser)) {
        pCreated->SetKey(pRecord->GetKey(aKey));
        cStream_ad40d0* pStream = 0;
        if (pRecord->QueryInterface(0x051b11bd, reinterpret_cast<void**>(&pStream))
            && pCreated->QueryInterface(aId, reinterpret_cast<void**>(aOut))
            && pCreated->Read(pStream, aFlags, aUser)) {
            if (pStream) {
                pStream->Release();
            }
            if (pCreated) {
                pCreated->Release();
            }
            return true;
        }
        if (pStream) {
            pStream->Release();
        }
    }
    if (pCreated) {
        pCreated->Release();
    }
    return false;
}
#endif

// A counted object held by pointer in the lists below.
struct cCounted_ad27d4 {
    virtual bool QueryInterface(uint32_t id, void** ppOut);
    virtual void AddRef();
    virtual void Release();
};

// A node of the doubly linked list of counted pointers.
struct cListNode_ad27d4 {
    cListNode_ad27d4* mpNext;
    cListNode_ad27d4* mpPrev;
    cCounted_ad27d4* mpItem;
};

// The library's node release (0x0090cf63) and allocation (0x0090cf54).
// STUB: 0x0090cf63
void Fn0090cf63_ad27d4(void* pBlock);
// STUB: 0x0090cf54
void* Fn0090cf54_ad27d4(uint32_t nBytes);

#ifdef OB_DRAFTS
// CLOSE: 0x00943489 score 27
cCounted_ad27d4** Fn00943489(cCounted_ad27d4** pFirst, cCounted_ad27d4** pLast, cCounted_ad27d4** pDest)
{
    for (; pFirst != pLast; ++pFirst, ++pDest) {
        if (pDest) {
            cCounted_ad27d4* pItem = *pFirst;
            *pDest = pItem;
            if (pItem) {
                pItem->AddRef();
            }
        }
    }
    return pDest;
}
#endif

// FUNCTION: 0x009437db
void OB_STDCALL Fn009437db(cListNode_ad27d4** ppResult, cListNode_ad27d4* pNode)
{
    cListNode_ad27d4* pNext = pNode->mpNext;
    cListNode_ad27d4* pPrev = pNode->mpPrev;
    pPrev->mpNext = pNext;
    pNext->mpPrev = pPrev;
    cCounted_ad27d4* pItem = pNode->mpItem;
    if (pItem) {
        pItem->Release();
    }
    Fn0090cf63_ad27d4(pNode);
    *ppResult = pNext;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009418a0 score 17
void OB_STDCALL Fn009418a0(cListNode_ad27d4** ppResult, cListNode_ad27d4* pFirst, cListNode_ad27d4* pLast)
{
    while (pFirst != pLast) {
        cListNode_ad27d4* pNode = pFirst;
        cListNode_ad27d4* pNext = pNode->mpNext;
        pFirst = pNode->mpNext;
        pNode->mpPrev->mpNext = pNext;
        pNext->mpPrev = pNode->mpPrev;
        Fn0090cf63_ad27d4(pNode);
    }
    *ppResult = pLast;
}
#endif

// FUNCTION: 0x00940512
void cHitResource_cHitList::Slot03_ad2620(uint32_t aOut)
{
    uint32_t* pOut = OB_PTR(uint32_t, aOut);
    pOut[0] = field1c;
    pOut[1] = field20;
    pOut[2] = field24;
}
