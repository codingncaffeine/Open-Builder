#include "classes/cSC4Advisor.h"
#include "game/Globals.h"

#include <new>

// An embedded component the first two slots forward to (only its slot 14 is called here).
struct ObSubObject {
    virtual void Fn0() = 0;
    virtual void Fn1() = 0;
    virtual void Fn2() = 0;
    virtual void Fn3() = 0;
    virtual void Fn4() = 0;
    virtual void Fn5() = 0;
    virtual void Fn6() = 0;
    virtual void Fn7() = 0;
    virtual void Fn8() = 0;
    virtual void Fn9() = 0;
    virtual void Fn10() = 0;
    virtual void Fn11() = 0;
    virtual void Fn12() = 0;
    virtual void Fn13() = 0;
    virtual void Fn14() = 0;
};

// What an entry of the list at +0x84 points at (a component; only some slots are known).
struct ObItem : public cIGZUnknown {
    virtual void Fn3() = 0;
    virtual void Fn4() = 0;
    virtual void Fn5() = 0;
    virtual void Fn6() = 0;
    virtual void Fn7() = 0;
    virtual bool Fn8() = 0;
    virtual void Fn9() = 0;
    virtual uint32_t Fn10() = 0;
    virtual void Fn11() = 0;
    virtual void Fn12() = 0;
    virtual uint32_t Fn13() = 0;
    virtual void Fn14() = 0;
    virtual bool Fn15(uint32_t) = 0;
    virtual void Fn16() = 0;
    virtual void Fn17() = 0;
    virtual void Fn18() = 0;
    virtual void Fn19() = 0;
    virtual void Fn20() = 0;
    virtual void Fn21() = 0;
    virtual void Fn22() = 0;
    virtual void Fn23() = 0;
    virtual void Fn24() = 0;
    virtual void Fn25() = 0;
    virtual uint32_t Fn26() = 0;
    virtual uint32_t Fn27() = 0;
};

// An element of the entry list: an object pointer and 12 more bytes.
struct ObEntry {
    ObItem* mpObject;
    uint32_t mUnknown[3];
};

// FUNCTION: 0x0040d3b0
void cSC4Advisor::Slot07_a81120()
{
    reinterpret_cast<ObSubObject*>(field18)->Fn14();
}

// FUNCTION: 0x0040d3c0
void cSC4Advisor::Slot09_a81120()
{
    reinterpret_cast<ObSubObject*>(field38)->Fn14();
}

// FUNCTION: 0x0040d430
bool cSC4Advisor::QueryInterface(unsigned int riid, void** ppvObj)
{
    switch (riid) {
    case 0x452294aa:
        *ppvObj = static_cast<cUnk00aaaa9c*>(this);
        break;
    case 0xca09f544:
        *ppvObj = static_cast<cUnk00a81120*>(this);
        break;
    case 0xe4fda3d4:
        *ppvObj = static_cast<cUnk00a80784*>(this);
        break;
    default:
        return cUnk0090da1e::QueryInterface(riid, ppvObj);
    }
    AddRef();
    return true;
}


// FUNCTION: 0x0040d870
uint32_t cSC4Advisor::Slot15_a81120(uint32_t a)
{
    if (static_cast<uint8_t>(a)) {
        return mpListAEnd - mpListABegin;
    }
    return mpListBEnd - mpListBBegin;
}

// FUNCTION: 0x0040d3e0
bool cSC4Advisor::Slot16_a81120(uint32_t a, uint32_t b)
{
    int32_t index = static_cast<int32_t>(b);
    if (index >= 0) {
        if (index < static_cast<int32_t>(Slot15_a81120(a))) {
            mnIndex = index;
            mbFlag = static_cast<uint8_t>(a);
            return true;
        }
    }
    mnIndex = -1;
    return false;
}

// FUNCTION: 0x0040d7a0
void* cSC4Advisor::Slot12_a81120(uint32_t a)
{
    ObEntry* p = reinterpret_cast<ObEntry*>(mpEntriesBegin);
    if (p != reinterpret_cast<ObEntry*>(mpEntriesEnd)) {
        do {
            if (p->mpObject->Fn10() == a) {
                return p->mpObject;
            }
            p += 1;
        } while (p != reinterpret_cast<ObEntry*>(mpEntriesEnd));
    }
    return 0;
}

// FUNCTION: 0x0040d7e0
void* cSC4Advisor::Slot13_a81120(uint32_t a)
{
    ObEntry* p = reinterpret_cast<ObEntry*>(mpEntriesBegin);
    if (p != reinterpret_cast<ObEntry*>(mpEntriesEnd)) {
        do {
            if (p->mpObject->Fn13() == a) {
                return p->mpObject;
            }
            p += 1;
        } while (p != reinterpret_cast<ObEntry*>(mpEntriesEnd));
    }
    return 0;
}

// The component behind the global at 0xb43d5c: slot 7 answers an object whose slot 26 answers a value.
struct cB43d5cInner {
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
    virtual uint32_t Fn26();
};

struct cB43d5c {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual cB43d5cInner* Fn07();
};
// GLOBAL: 0x00b43d5c
extern cB43d5c* gpB43d5c;

// FUNCTION: 0x0040d820
bool cSC4Advisor::Slot14_a81120(uint32_t a)
{
    if (a == 0) {
        mnValue5c = gpB43d5c->Fn07()->Fn26();
        simulate_day();
        return true;
    }
    if (a == 1) {
        ++mnRefA;
        simulate_month();
    }
    return true;
}

// STUB: 0x0090cf63
void Fn0090cf63(void* p);   // the STL allocator's delete

// GLOBAL: 0x00b07c98
extern const char* gpAdvisorHeads;   // a pointer to a string

// What a handler answers to the lookup result: only slot 7 is used.
struct ObLookupHandler {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Fn07(uint32_t);
};

// A lookup result of 0x24 bytes that owns a heap buffer at +0x14.
struct ObLookup {
    uint32_t mnObject;
    uint32_t mn4;
    ObLookupHandler* mpHandler;
    uint8_t mbFound;
    uint8_t mPad0d[3];
    uint32_t mn10;
    void* mpBuffer;
    uint32_t mUnknown18[3];

    ~ObLookup()
    {
        if (mpBuffer) {
            Fn0090cf63(mpBuffer);
        }
    }

    // STUB: 0x004084e0
    void Fn004084e0(cB207c0Item* a, const char* b, uint32_t c);
    // STUB: 0x0040d330
    uint32_t Fn0040d330(uint32_t a);
};

// FUNCTION: 0x0040f3a0
uint32_t cSC4Advisor::Slot17_a81120(uint32_t a)
{
    uint32_t** pList = &mpListABegin;
    if (!mbFlag) {
        pList = &mpListBBegin;
    }
    if (mnIndex >= 0 && static_cast<uint32_t>(mnIndex) < static_cast<uint32_t>(pList[1] - pList[0])) {
        ObLookup result;
        cB207c0Item* source = gpB207c0->Fn10();
        result.Fn004084e0(source, gpAdvisorHeads, pList[0][mnIndex]);
        if (result.mbFound) {
            uint32_t r = result.Fn0040d330(a);
            result.mpHandler->Fn07(result.mnObject);
            return r;
        }
    }
    return 0;
}

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);   // the STL allocator's new

// A (key, component) pair that holds a reference on the component.
struct ObPair {
    uint32_t mnKey;
    cIGZUnknown* mpObject;

    ObPair(uint32_t key, cIGZUnknown* object) : mnKey(key), mpObject(object)
    {
        if (mpObject) {
            mpObject->AddRef();
        }
    }
};

// A node of the circular list at +0xb0: the links, then the pair.
struct ObListNode {
    ObListNode* mpNext;
    ObListNode* mpPrev;
    ObPair mValue;
};

// FUNCTION: 0x0040eec0
bool cSC4Advisor::Slot18_a81120(uint32_t a, uint32_t b)
{
    cIGZUnknown* object = reinterpret_cast<cIGZUnknown*>(b);
    if (object) {
        object->AddRef();
        object->AddRef();
    }
    ObListNode* head = static_cast<ObListNode*>(mpNodes);
    ObListNode* node = static_cast<ObListNode*>(Fn0090cf54(sizeof(ObListNode)));
    new (&node->mValue) ObPair(a, object);
    ObListNode* prev = head->mpPrev;
    node->mpNext = head;
    node->mpPrev = prev;
    prev->mpNext = node;
    head->mpPrev = node;
    if (object) {
        object->Release();
        object->Release();
    }
    return true;
}

// An item record the container below hands out: the number of its slot is at +0x14.
struct ObRecord {
    uint32_t mUnknown[5];
    uint32_t mnSlot;
};

// A position in the container (passed by value).
struct ObIterator {
    ObRecord* mpNode;

    ObIterator(ObRecord* node) : mpNode(node) {}
    ObIterator(const ObIterator& other) : mpNode(other.mpNode) {}
};

// The container embedded at +0x78 of the whole object.
struct ObContainer {
    // STUB: 0x0040de90
    ObRecord* Fn0040de90(cIGZUnknown** key);
    // STUB: 0x0040e440
    void Fn0040e440(ObIterator it);
};

// FUNCTION: 0x0040e9b0
bool cSC4Advisor::Slot20_a81120(uint32_t a)
{
    ObItem* item = reinterpret_cast<ObItem*>(a);
    if (!(item && item->Fn15(2))) {
        return false;
    } else {
        cIGZUnknown* key = reinterpret_cast<cIGZUnknown*>(item);
        item->AddRef();
        ObContainer* container = reinterpret_cast<ObContainer*>(field78);
        ObRecord* record = container->Fn0040de90(&key);
        item->Release();
        ObIterator it(record);
        ObEntry* entry = reinterpret_cast<ObEntry*>(mpEntriesBegin) + record->mnSlot;
        container->Fn0040e440(it);
        Fn0040df90(entry);
        return true;
    }
}


// FUNCTION: 0x0040d8a0
bool cSC4Advisor::Slot19_a81120(uint32_t a)
{
    int32_t count = (reinterpret_cast<ObEntry*>(mpEntriesEnd) - reinterpret_cast<ObEntry*>(mpEntriesBegin));
    if (count != 0) {
        int32_t offset = count << 4;
        do {
            offset -= 0x10;
            ObEntry* entry = reinterpret_cast<ObEntry*>(reinterpret_cast<char*>(mpEntriesBegin) + offset);
            count -= 1;
            if (!entry->mpObject->Fn15(0x40)) {
                if (entry->mpObject->Fn27() == a) {
                    if (entry->mpObject->Fn8()) {
                        return true;
                    }
                }
            }
        } while (count != 0);
    }
    return false;
}


// A record of the list at +0x6c.
struct ObRecordInner {
    uint32_t mUnknown[4];
    uint32_t mnId;
};
struct ObRecordNode {
    uint32_t mUnknown[2];
    ObRecordInner* mpInner;
    uint32_t mUnknown2;
};

// ecx = the object, three stack arguments the caller pops: no standard convention (VC7.1 gives static functions
// a custom one under whole-program optimisation, /GL); only a CLOSE attempt calls it
// STUB: 0x0040da10
void Fn0040da10(cSC4Advisor* self, ...);

// STUB: 0x0040daf0
void* Fn0040daf0(ObRecordInner* inner, void* a, void* b, void* c);

// The map embedded at +0x78: a header node and the node count.
struct ObMapNode {
    uint32_t mUnknown[1];
    ObMapNode* mpParent;
    ObMapNode* mpLeft;
    ObMapNode* mpRight;
};
struct ObMap {
    ObMapNode* mpHeader;
    uint32_t mnSize;

    // STUB: 0x0040e050
    void Fn0040e050(ObMapNode* node);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0040ed30 score 116 (the callee 0x40da10 takes ecx = object and the caller pops its stack arguments: a static helper
// with a custom convention the compiler cannot be asked for from outside; the rest of the body is untuned)
bool cSC4Advisor::Slot04_a81120()
{
    if (mbRegistered) {
        gpB43ccc->Fn06(static_cast<cUnk00aaaa9c*>(this), 0xea917750);
        gpB43ccc->Fn06(static_cast<cUnk00aaaa9c*>(this), 0x8a917759);
        gpB43ccc->Fn06(static_cast<cUnk00aaaa9c*>(this), 0x4a91dd6e);
        gpB43ccc->Fn06(static_cast<cUnk00aaaa9c*>(this), 0x4a92ecef);
        mbRegistered = 0;
    }
    ObMap* map = reinterpret_cast<ObMap*>(field78);
    mnValue5c = 0;
    mnRefA = 0;
    if (map->mnSize != 0) {
        map->Fn0040e050(map->mpHeader->mpParent);
        map->mpHeader->mpLeft = map->mpHeader;
        map->mpHeader->mpParent = 0;
        map->mpHeader->mpRight = map->mpHeader;
        map->mnSize = 0;
    }
    Fn0040da10(this, 0, 0x8a09fa67, 0);
    cB207c0* manager = gpB207c0;
    uint32_t lastId = 0;
    while (mnRecords != 0) {
        ObRecordNode* node = static_cast<ObRecordNode*>(mpRecords);
        uint32_t id = node->mpInner->mnId;
        if (lastId != id) {
            manager->Fn17(id, static_cast<cUnk00a81120*>(this));
            lastId = id;
        }
        void* dead = Fn0040daf0(node->mpInner, reinterpret_cast<char*>(node) + 4, reinterpret_cast<char*>(node) + 8, reinterpret_cast<char*>(node) + 12);
        if (dead) {
            Fn0090cf63(dead);
        }
        mnRecords -= 1;
    }
    if (mpEntriesBegin != mpEntriesEnd) {
        do {
            ObEntry* last = reinterpret_cast<ObEntry*>(mpEntriesEnd) - 1;
            last->mpObject->Fn4();
            mpEntriesEnd = last;
            if (last->mpObject) {
                last->mpObject->Release();
            }
        } while (mpEntriesBegin != mpEntriesEnd);
    }
    return true;
}
#endif

// The stream the object is saved to: only the slots used here are named.
struct ObStream {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void WriteBool(bool value);
    virtual void Pad05();
    virtual void Pad06();
    virtual void WriteHeader(uint32_t version);
    virtual void Write32(uint32_t value);
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void WriteBlock(void* block);
    virtual void Pad16();
    virtual void Pad17();
    virtual bool Failed();
};

// STUB: 0x005d99a0
void Fn005d99a0(ObStream* stream, void* object);   // writes a component by reference

// FUNCTION: 0x0040e2e0
bool cSC4Advisor::Slot03_a80784(void* a)
{
    ObStream* stream = static_cast<ObStream*>(a);
    stream->WriteHeader(3);
    stream->Write32(mnType);
    stream->WriteBlock(field18);
    stream->WriteBlock(field38);
    stream->Write32(mnRefA);
    stream->Write32(mnValue5c);
    stream->Write32(mn60);
    stream->Write32(mn64);
    int32_t count = reinterpret_cast<ObEntry*>(mpEntriesEnd) - reinterpret_cast<ObEntry*>(mpEntriesBegin);
    stream->Write32(count);
    for (int32_t i = 0; i < count; ++i) {
        ObEntry* entry = reinterpret_cast<ObEntry*>(mpEntriesBegin) + i;
        Fn005d99a0(stream, entry->mpObject);
        stream->Write32(entry->mUnknown[1]);
        stream->Write32(entry->mUnknown[2]);
        stream->Write32(entry->mUnknown[0]);
        bool flag = entry->mpObject->Fn15(2) != 0;
        stream->WriteBool(flag);
        uint32_t id = entry->mpObject->Fn26();
        stream->Write32(id);
    }
    ObListNode* head = static_cast<ObListNode*>(mpNodes);
    uint32_t nodes = 0;
    for (ObListNode* node = head->mpNext; node != head; node = node->mpNext) {
        nodes += 1;
    }
    stream->Write32(nodes);
    for (ObListNode* node = static_cast<ObListNode*>(mpNodes)->mpNext; node != static_cast<ObListNode*>(mpNodes); node = node->mpNext) {
        stream->Write32(node->mValue.mnKey);
        Fn005d99a0(stream, node->mValue.mpObject);
    }
    return !stream->Failed();
}
