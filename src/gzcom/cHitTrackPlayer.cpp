#include <stddef.h>
#include "classes/cHitTrackPlayer.h"
#include "classes/cUnk00ad2540.h"

// STUB: 0x009377c9
uint32_t Fn009377c9(uint32_t reg);

// The hit manager service pointer (ids 0x1b2ce671 / 0xbb1bd9a8).
struct cHitSvcPtr_ad3e48 {
    cUnk00ad2540* mp;
    // STUB: 0x004ed100
    cHitSvcPtr_ad3e48();
    // STUB: 0x004ed130
    ~cHitSvcPtr_ad3e48();
};

// A smart pointer (assignment at 0x005447b0, and at 0x0094909a).
struct cAutoRefB_ad3e48 {
    void* mp;
    // STUB: 0x005447b0
    cAutoRefB_ad3e48& Assign(void* p);
};
struct cAutoRef_ad3e48 {
    void* mp;
    // STUB: 0x0094909a
    cAutoRef_ad3e48& Assign(void* p);
};

struct cUnk_ad3e48 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
};

// A register provider (slots 3 set, 5 reset, 8 get, 9 has).
struct cProvider_ad3e48 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void Pad1();
    virtual void Pad2();
    virtual void Fn3(uint32_t* key, void* receiver);
    virtual void Pad4();
    virtual void Fn5();
    virtual void Pad6();
    virtual void Pad7();
    virtual bool Fn8(uint32_t* key, void* receiver);
    virtual bool Fn9(uint32_t* key);
};

// A receiver object handed to a provider (a vtable and one value).
struct cRegValue_ad3e48 {
    virtual void Fn0();
    int32_t mnValue;
};
struct cRegFloat_ad3e48 {
    // STUB: 0x00940bc5
    virtual void Fn0();
    float mfValue;
};

// The data block (slot 3 gives its base address).
struct cDataBlock_ad3e48 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual uint32_t Fn3();
};

// The 0x88 object: slot 5 takes the two ends of a connection.
struct cNotifier_ad3e48 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Fn5(void* a, void* b);
};

// The sound object behind 0x80 (slots 7 / 8 / 9 / 14 / 15 / 17 / 18 as used).
struct cSndObj_ad3e48 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
    virtual void Fn3(uint32_t key, int32_t value, uint32_t flag);
    virtual void Fn4();
    virtual void Pad5();
    virtual void Pad6();
    virtual bool Fn7();
    virtual bool Fn8();
    virtual void Fn9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Fn14();
    virtual void Fn15();
    virtual void Pad16();
    virtual void Fn17(uint32_t flag);
};

// The embedded name object at this+0x20: slot 14 copies in or out.
struct cNameObj_ad3e48 {
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
    virtual void Fn14(void* other);
};

// FUNCTION: 0x0087b103
uint32_t cHitTrackPlayer::Slot33_ad3e48(uint32_t reg)
{
    return Slot04_ad2bc8(reg);
}

// FUNCTION: 0x0093a810
bool cHitTrackPlayer::QueryInterface(uint32_t id, void** out)
{
    void** pp = out;
    if (id == 1) {
        *pp = static_cast<cHitTrackPlayer_0*>(this);
    } else if (id == 0xfd584467) {
        *pp = static_cast<cUnk00ad2bc8*>(this);
    } else if (id == 0x5b34f0af) {
        *pp = static_cast<cUnk00a943c0*>(this);
    } else if (id == 0xaa11a64f) {
        *pp = static_cast<cUnk00ad2bec*>(this);
    } else if (id == 0xbb1be367) {
        *pp = static_cast<cHitTrackPlayer_0*>(this);
    } else if (id == 0x206077d2) {
        *pp = static_cast<cUnk00ac2b18*>(this);
    } else if (id == 0x306077d2) {
        *pp = static_cast<cUnk00ac2d78*>(this);
    } else if (id == 0xdd583e2d) {
        *pp = static_cast<cUnk00ad2bfc*>(this);
    } else if (id == 0xe9d00a9a) {
        *pp = static_cast<cUnk00ac2bf0*>(this);
    } else {
        return false;
    }
    AddRef();
    return true;
}

// FUNCTION: 0x0093a897
uint32_t cHitTrackPlayer::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x0093a89e
unsigned int cHitTrackPlayer::Release()
{
    if (mnRefCount <= 1) {
        delete this;
        return 0;
    }
    return --mnRefCount;
}

// FUNCTION: 0x0093a8b5
void cHitTrackPlayer::Slot13_ad3e48(uint32_t a)
{
    Slot24_ad3e48(a);
}

// FUNCTION: 0x0093a8ba
bool cHitTrackPlayer::Slot06_ac2b18(uint32_t a, uint32_t /*b*/, uint32_t /*c*/)
{
    return Slot05_ac2b18(a, 0, 0, 0);
}

// FUNCTION: 0x0093a94c
bool cHitTrackPlayer::GetSourceFilenameAndLineNum(uint32_t /*name*/, uint32_t /*line*/)
{
    Slot07_ac2b18();
    return false;
}

// FUNCTION: 0x0093a959
bool cHitTrackPlayer::CurrentPlayPosition(uint32_t out)
{
    void** pos = OB_PTR(void*, out);
    if (Slot07_ac2b18()) {
        *pos = mpPos1;
    } else {
        *pos = mpPos2;
    }
    return true;
}

// FUNCTION: 0x0093a97c
bool cHitTrackPlayer::Slot03_ac2bf0(uint32_t notification)
{
    if (mpCompletion) {
        static_cast<cUnk_ad3e48*>(mpCompletion)->Release();
    }
    cUnk_ad3e48* object = OB_PTR(cUnk_ad3e48, notification);
    mpCompletion = object;
    if (object) {
        object->AddRef();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093a9a3 score 2
bool cHitTrackPlayer::Slot04_ac2bf0()
{
    if (mpCompletion) {
        static_cast<cUnk_ad3e48*>(mpCompletion)->Release();
    }
    mpCompletion = 0;
    return true;
}
#endif

// FUNCTION: 0x0093aa6f
void cHitTrackPlayer::SetErrorCondition()
{
    fieldc4 = true;
}

// FUNCTION: 0x0093a9bc
void cHitTrackPlayer::Slot04_ac2d78(uint32_t pa, uint32_t pb, uint32_t pc)
{
    *OB_PTR(float, pa) = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xffcc4d2d)));
    *OB_PTR(float, pb) = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xff4a01d6)));
    *OB_PTR(float, pc) = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xff469820)));
}

// FUNCTION: 0x0093aa0e
bool cHitTrackPlayer::Slot05_ac2d78(uint32_t a, uint32_t b, uint32_t c)
{
    float x = *reinterpret_cast<float*>(&a);
    float y = *reinterpret_cast<float*>(&b);
    float z = *reinterpret_cast<float*>(&c);
    Slot03_ad2bc8(0xffcc4d2d, static_cast<int32_t>(x), 0);
    Slot03_ad2bc8(0xff4a01d6, static_cast<int32_t>(y), 0);
    Slot03_ad2bc8(0xff469820, static_cast<int32_t>(z), 0);
    return Slot03_ad2bc8(0xffcc156f, 0, 0);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093ac5d score 4
bool cHitTrackPlayer::Slot04_ac2b18()
{
    if (mpSmart80) {
        static_cast<cSndObj_ad3e48*>(mpSmart80)->Fn4();
    }
    reinterpret_cast<cAutoRefB_ad3e48*>(&mpSmart7c)->Assign(0);
    reinterpret_cast<cAutoRefB_ad3e48*>(&mpSmart80)->Assign(0);
    return true;
}
#endif

// FUNCTION: 0x0093ac87
bool cHitTrackPlayer::GetTrackDef(uint32_t id, uint32_t out)
{
    cProvider_ad3e48** providers = static_cast<cProvider_ad3e48**>(mpProvidersBegin);
    cProvider_ad3e48* second = providers[1];
    if (second) {
        return second->QueryInterface(id, OB_PTR(void*, out));
    }
    return false;
}

// FUNCTION: 0x0093ac9d
bool cHitTrackPlayer::SetHitList(uint32_t hitList)
{
    reinterpret_cast<cAutoRef_ad3e48*>(&mpHitList)->Assign(OB_PTR(void, hitList));
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093acb1 score 17
bool cHitTrackPlayer::GetHitList(uint32_t id, uint32_t out)
{
    if (mpHitListB0) {
        return static_cast<cUnk_ad3e48*>(mpHitListB0)->QueryInterface(id, OB_PTR(void*, out));
    }
    return false;
}
#endif

// FUNCTION: 0x0093adaa
bool cHitTrackPlayer::Reset()
{
    cProvider_ad3e48** providers = static_cast<cProvider_ad3e48**>(mpProvidersBegin);
    providers[0]->Fn5();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093adba score 10
bool cHitTrackPlayer::CancelNote()
{
    if (mpSmart7c) {
        cSndObj_ad3e48* snd = static_cast<cSndObj_ad3e48*>(mpSmart80);
        if (snd->Fn7()) {
            snd->Fn9();
        }
    }
    return true;
}
#endif

// FUNCTION: 0x0093addd
float cHitTrackPlayer::Slot08_ad2bc8(uint32_t reg)
{
    float result = 0.0f;
    cProvider_ad3e48** it = static_cast<cProvider_ad3e48**>(mpProvidersBegin);
    cProvider_ad3e48** end = static_cast<cProvider_ad3e48**>(mpProvidersEnd);
    cRegFloat_ad3e48 receiver;
    receiver.mfValue = result;
    while (it != end) {
        if (*it) {
            if ((*it)->Fn8(&reg, &receiver)) {
                return receiver.mfValue;
            }
        }
        ++it;
    }
    return 0.0f;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093ae2d score 14
void cHitTrackPlayer::Slot06_ad2bc8(uint32_t reg)
{
    if (reg <= 0xff) {
        uint32_t mapped = Fn009377c9(reg);
        if (mapped) {
            reg = mapped;
        }
    }
    cProvider_ad3e48** providers = static_cast<cProvider_ad3e48**>(mpProvidersBegin);
    if (providers[0]->Fn9(&reg)) {
        return;
    }
    providers[1]->Fn9(&reg);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093ae8c score 23
void cHitTrackPlayer::Slot03_ad2bec()
{
    if (mpSmart7c && mpSmart88) {
        static_cast<cNotifier_ad3e48*>(mpSmart88)->Fn5(mpSmart7c, static_cast<cUnk00ad2bc8*>(this));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093aeb1 score 9
bool cHitTrackPlayer::SetTrackDataEntryPoint(uint32_t id)
{
    uint32_t offset;
    cDataBlock_ad3e48* block;
    bool ok = false;
    cHitSvcPtr_ad3e48 service;
    offset = 0;
    block = 0;
    if (service.mp->Slot13_ad2540(id, OB_ADDR(&block), OB_ADDR(&offset))) {
        uint32_t base = block->Fn3();
        mnDataBase = base;
        base += offset;
        mpPos1 = OB_PTR(void, base);
        mpPos2 = OB_PTR(void, base);
        mpPos3 = OB_PTR(void, base);
        ok = true;
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093af0d score 7
bool cHitTrackPlayer::Slot27_ac2b18(uint32_t value)
{
    Slot03_ad2bc8(0xff099db2, value, 0);
    if (mpSmart7c) {
        static_cast<cSndObj_ad3e48*>(mpSmart7c)->Fn3(0xff099db2, value, 0);
        return true;
    }
    return true;
}
#endif

// FUNCTION: 0x0093af41
bool cHitTrackPlayer::Slot14_ac2b18()
{
    ++mnLoadCount;
    if (mnLoadCount == 1 && mpSmart7c) {
        static_cast<cSndObj_ad3e48*>(mpSmart80)->Fn14();
    }
    return true;
}

// FUNCTION: 0x0093af5d
bool cHitTrackPlayer::Slot15_ac2b18()
{
    --mnLoadCount;
    if (mnLoadCount == 0 && mpSmart7c) {
        static_cast<cSndObj_ad3e48*>(mpSmart80)->Fn15();
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093af73 score 5
bool cHitTrackPlayer::Slot07_ad2bfc()
{
    Slot03_ad2bec();
    return true;
}
#endif

// FUNCTION: 0x0093e43d
uint32_t cHitTrackPlayer::AsIGZSndMultipleSources()
{
    return OB_ADDR(static_cast<cUnk00ad2bfc*>(this));
}

// FUNCTION: 0x0093e453
uint32_t cHitTrackPlayer::Slot31_ac2b18()
{
    return Slot04_ad2bc8(0x13);
}

// FUNCTION: 0x0093e45e
void cHitTrackPlayer::Slot32_ac2b18(uint32_t value)
{
    Slot03_ad2bc8(0x13, value, 0);
}

// FUNCTION: 0x0093e471
uint32_t cHitTrackPlayer::Slot28_ac2b18()
{
    return Slot04_ad2bc8(0x49);
}

// FUNCTION: 0x0093e482
bool cHitTrackPlayer::Slot16_ac2b18()
{
    return mnLoadCount != 0;
}

// FUNCTION: 0x0093e48b
bool cHitTrackPlayer::Slot19_ac2b18()
{
    return mnPauseFlag != 0;
}

// FUNCTION: 0x0093e494
uint32_t cHitTrackPlayer::Slot20_ac2b18()
{
    return Slot04_ad2bc8(0x15);
}

// FUNCTION: 0x0093e49f
bool cHitTrackPlayer::Slot21_ac2b18(uint32_t value)
{
    return Slot03_ad2bc8(0x15, value, 0);
}

// FUNCTION: 0x0093e4b2
void cHitTrackPlayer::SetEffectsLevel(uint32_t value)
{
    Slot03_ad2bc8(0x17, value, 0);
}

// FUNCTION: 0x0093e4c5
uint32_t cHitTrackPlayer::Slot24_ac2b18()
{
    return Slot04_ad2bc8(0x16);
}

// FUNCTION: 0x0093e4d0
bool cHitTrackPlayer::Slot25_ac2b18(uint32_t value)
{
    return Slot03_ad2bc8(0x16, value, 0);
}

// FUNCTION: 0x0093e4e3
void cHitTrackPlayer::SetPitch(uint32_t value)
{
    Slot03_ad2bc8(0x19, value, 0);
}

// FUNCTION: 0x0093e4f6
void cHitTrackPlayer::SetEffectsType(uint32_t value)
{
    Slot03_ad2bc8(0x1a, value, 0);
}

// FUNCTION: 0x0093e509
bool cHitTrackPlayer::Slot23_ac2b18()
{
    return Slot04_ad2bc8(0x2a) != 0;
}

// FUNCTION: 0x0093e51a
uint32_t cHitTrackPlayer::Slot26_ac2b18()
{
    return Slot04_ad2bc8(0x17);
}

// FUNCTION: 0x0093e525
bool cHitTrackPlayer::Slot33_ac2b18(uint32_t other)
{
    reinterpret_cast<cNameObj_ad3e48*>(&mNameVptr)->Fn14(OB_PTR(void, other));
    return true;
}

// FUNCTION: 0x0093e536
bool cHitTrackPlayer::Slot34_ac2b18(uint32_t other)
{
    OB_PTR(cNameObj_ad3e48, other)->Fn14(&mNameVptr);
    return true;
}

// ---- batch 2

// The list of children (this+0x98): a std::list node holds the child pointer.
struct ListNode_ad3e48 {
    ListNode_ad3e48* mpNext;
    ListNode_ad3e48* mpPrev;
    uint32_t mnValue;
};
struct cList_ad3e48 {
    ListNode_ad3e48* mpHead;
};

// A child track player, seen through the slots used.
struct cChild_ad3e48 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual bool Fn7();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Fn17(uint32_t flag);
    virtual void Fn18();
};

// The service object RZ::SS() hands out: slot 31 takes the sound manager interface (and a flag).
struct cSS1_ad3e48 {
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
    virtual void Fn31(void* sink);
};
struct cSS2_ad3e48 {
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
    virtual void Fn31(void* sink, uint32_t id);
};
// STUB: 0x00913c9e
cSS1_ad3e48* Fn00913c9e();

// The sound object behind 0x80 also answers slots 19 and 18 (unpause).
struct cSndObjB_ad3e48 {
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
    virtual void Fn18();
    virtual bool Fn19();
};

// FUNCTION: 0x0093a8cb
void cHitTrackPlayer::Fn0093a8cb(uint32_t a, uint32_t b)
{
    int32_t x = static_cast<int32_t>(a);
    int32_t y = static_cast<int32_t>(b);
    mbCmpEqual = x == y;
    mbCmpGreater = x > y;
    mbCmpLess = x < y;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093a8f9 score 27
void cHitTrackPlayer::Fn0093a8f9(uint32_t a, uint32_t b)
{
    float x = *reinterpret_cast<float*>(&a);
    float y = *reinterpret_cast<float*>(&b);
    mbCmpEqual = x == y;
    mbCmpGreater = x > y;
    mbCmpLess = x < y;
}
#endif

// FUNCTION: 0x0093aa7e
double Fn0093aa7e(double x, int32_t n)
{
    uint32_t e = n < 0 ? static_cast<uint32_t>(-n) : static_cast<uint32_t>(n);
    double r = 1.0;
    for (;;) {
        if (e & 1) {
            r *= x;
        }
        e >>= 1;
        if (!e) {
            break;
        }
        x *= x;
    }
    if (n < 0) {
        return 1.0 / r;
    }
    return r;
}

// FUNCTION: 0x0093ae78
bool cHitTrackPlayer::Fn0093ae78()
{
    if (mpSmart7c) {
        return static_cast<cSndObj_ad3e48*>(mpSmart80)->Fn8();
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093afee score 11
bool cHitTrackPlayer::Slot07_ac2b18()
{
    if (mbPlaying) {
        return true;
    }
    cList_ad3e48* list = static_cast<cList_ad3e48*>(mpChildList);
    ListNode_ad3e48* head = list->mpHead;
    ListNode_ad3e48* node = head->mpNext;
    while (node != head) {
        if (OB_PTR(cChild_ad3e48, node->mnValue)->Fn7()) {
            return true;
        }
        node = node->mpNext;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093b01e score 13
bool cHitTrackPlayer::Slot17_ac2b18(uint32_t flag)
{
    cList_ad3e48* list = static_cast<cList_ad3e48*>(mpChildList);
    mnPauseFlag = 1;
    ListNode_ad3e48* head = list->mpHead;
    ListNode_ad3e48* node = head->mpNext;
    while (node != head) {
        OB_PTR(cChild_ad3e48, node->mnValue)->Fn17(flag);
        node = node->mpNext;
    }
    if (Slot07_ac2b18()) {
        if ((flag & 0xff) && mpSmart7c) {
            static_cast<cSndObj_ad3e48*>(mpSmart80)->Fn17(flag);
        }
        reinterpret_cast<cSS1_ad3e48*>(Fn00913c9e())->Fn31(static_cast<cUnk00a943c0*>(this));
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093b08b score 24
bool cHitTrackPlayer::Slot18_ac2b18()
{
    cList_ad3e48* list = static_cast<cList_ad3e48*>(mpChildList);
    mnPauseFlag = 0;
    ListNode_ad3e48* head = list->mpHead;
    ListNode_ad3e48* node = head->mpNext;
    while (node != head) {
        OB_PTR(cChild_ad3e48, node->mnValue)->Fn18();
        node = node->mpNext;
    }
    if (mpSmart7c) {
        cSndObjB_ad3e48* snd = static_cast<cSndObjB_ad3e48*>(mpSmart80);
        if (snd->Fn19()) {
            snd->Fn18();
        }
    }
    Slot24_ad3e48(0);
    if (Slot07_ac2b18()) {
        reinterpret_cast<cSS2_ad3e48*>(Fn00913c9e())->Fn31(static_cast<cUnk00a943c0*>(this), 0x14);
    }
    return !GetErrorCondition();
}
#endif

// FUNCTION: 0x0093e2d8
void cHitTrackPlayer::Slot18_ad3e48()
{
    if (!Slot07_ac2b18()) {
        PlayPause();
    }
    Slot17_ac2b18(0);
    DoCommand();
}

// ---- batch 3

// The object a source map is copied into (0x0093e773 copies a map in).
struct cMapCopy_ad3e48 {
    // STUB: 0x0093e773
    void Fn0093e773(void* map);
};

// A smart pointer copied from a slot (0x00966956): holds one more reference.
struct cSlotRef_ad3e48 {
    cProvider_ad3e48* mp;
    // STUB: 0x00966956
    cSlotRef_ad3e48(void* slot);
};

// What a child hands out for a register: slot 3 sets, slot 5 clears.
struct cRegSink_ad3e48 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Fn3(uint32_t* key, uint32_t value, uint32_t flag);
    virtual void Pad4();
    virtual void Fn5(uint32_t key, uint32_t flag);
};

// A register query interface of a child (slot 9: has the register).
struct cRegQuery_ad3e48 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual bool Fn9(uint32_t* key);
    virtual void Release();
};

// A child as the register paths see it.
struct cChildB_ad3e48 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual cRegSink_ad3e48* Fn6();
    virtual void Pad7();
    virtual bool Fn8(uint32_t id, void** out);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0093b268 score 58
bool cHitTrackPlayer::Slot03_ad2bc8(uint32_t reg, uint32_t value, uint32_t skipNotify)
{
    if (reg <= 0xff) {
        uint32_t mapped = Fn009377c9(reg);
        if (mapped) {
            reg = mapped;
        }
    }
    uint32_t v = value;
    Fn0093a8cb(v, 0);
    cSlotRef_ad3e48 first(mpProvidersBegin);
    cRegValue_ad3e48 receiver;
    receiver.mnValue = v;
    first.mp->Fn3(&reg, &receiver);
    cList_ad3e48* list = static_cast<cList_ad3e48*>(mpChildList);
    ListNode_ad3e48* head = list->mpHead;
    ListNode_ad3e48* node = head->mpNext;
    while (node != head) {
        cChildB_ad3e48* child = 0;
        if (OB_PTR(cUnk_ad3e48, node->mnValue)->QueryInterface(0xbb1be367, reinterpret_cast<void**>(&child))) {
            cRegQuery_ad3e48* query = 0;
            child->Fn8(0xebb10cdd, reinterpret_cast<void**>(&query));
            if (query) {
                if (!query->Fn9(&reg)) {
                    child->Fn6()->Fn3(&reg, v, skipNotify);
                }
                query->Release();
            }
        }
        if (child) {
            child->Release();
        }
        node = node->mpNext;
    }
    bool result = true;
    if (!(skipNotify & 0xff)) {
        result = HandleNotifySetPropertyValue(reg);
    }
    reinterpret_cast<cUnk_ad3e48*>(first.mp)->Release();
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093b481 score 15
void cHitTrackPlayer::Slot05_ad2bc8(uint32_t reg, uint32_t skipNotify)
{
    uint32_t key = reg;
    if (reg <= 0xff) {
        uint32_t mapped = Fn009377c9(reg);
        if (mapped) {
            key = mapped;
        }
    }
    cList_ad3e48* list = static_cast<cList_ad3e48*>(mpChildList);
    ListNode_ad3e48* head = list->mpHead;
    ListNode_ad3e48* node = head->mpNext;
    while (node != head) {
        cChildB_ad3e48* child = 0;
        if (OB_PTR(cUnk_ad3e48, node->mnValue)->QueryInterface(0xbb1be367, reinterpret_cast<void**>(&child))) {
            child->Fn6()->Fn5(key, 0);
        }
        if (child) {
            child->Release();
        }
        node = node->mpNext;
    }
    if (!(skipNotify & 0xff)) {
        HandleNotifySetPropertyValue(key);
    }
}
#endif

// FUNCTION: 0x0093e75c
uint32_t cHitTrackPlayer::Slot03_ad2bfc(uint32_t other)
{
    OB_PTR(cMapCopy_ad3e48, other)->Fn0093e773(&mpSourceMapHeader);
    return other;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093b36f score 52
bool cHitTrackPlayer::Slot07_ad2bc8(uint32_t reg, uint32_t value, uint32_t skipNotify)
{
    float f = *reinterpret_cast<float*>(&value);
    Fn0093a8f9(value, 0);
    cSlotRef_ad3e48 first(mpProvidersBegin);
    cRegFloat_ad3e48 receiver;
    receiver.mfValue = f;
    first.mp->Fn3(&reg, &receiver);
    cList_ad3e48* list = static_cast<cList_ad3e48*>(mpChildList);
    ListNode_ad3e48* head = list->mpHead;
    ListNode_ad3e48* node = head->mpNext;
    while (node != head) {
        cChildB_ad3e48* child = 0;
        if (OB_PTR(cUnk_ad3e48, node->mnValue)->QueryInterface(0xbb1be367, reinterpret_cast<void**>(&child))) {
            cRegQuery_ad3e48* query = 0;
            child->Fn8(0xebb10cdd, reinterpret_cast<void**>(&query));
            if (query) {
                if (!query->Fn9(&reg)) {
                    child->Fn6()->Fn3(&reg, static_cast<int32_t>(f), skipNotify);
                }
                query->Release();
            }
        }
        if (child) {
            child->Release();
        }
        node = node->mpNext;
    }
    bool result = true;
    if (!(skipNotify & 0xff)) {
        result = HandleNotifySetPropertyValue(reg);
    }
    reinterpret_cast<cUnk_ad3e48*>(first.mp)->Release();
    return result;
}
#endif

// ---- batch 4: the source map (std::map<unsigned long, ...>, header pointer then count)

struct TreeNode_ad3e48 {
    uint32_t mnColor;
    TreeNode_ad3e48* mpParent;
    TreeNode_ad3e48* mpLeft;
    TreeNode_ad3e48* mpRight;
    uint32_t mnKey;
    void* mpValue;
};

// An iterator handed by value (it has a copy constructor, so the compiler builds it in place).
struct Iter_ad3e48 {
    TreeNode_ad3e48* mpNode;
    Iter_ad3e48(TreeNode_ad3e48* node)
        : mpNode(node)
    {
    }
    Iter_ad3e48(const Iter_ad3e48& other)
        : mpNode(other.mpNode)
    {
    }
};

struct InsertResult_ad3e48 {
    TreeNode_ad3e48* mpNode;
    bool mbInserted;
};

// The node pool (0x0093af7e): slot 3 allocates, slot 4 frees.
struct cPool_ad3e48 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual TreeNode_ad3e48* Alloc(uint32_t size);
    virtual void Free(TreeNode_ad3e48* node);
};
// STUB: 0x0093af7e
cPool_ad3e48* Fn0093af7e();

// STUB: 0x0040daf0
TreeNode_ad3e48* Fn0040daf0(TreeNode_ad3e48* node, TreeNode_ad3e48** root, TreeNode_ad3e48** leftmost, TreeNode_ad3e48** rightmost);

struct cSrcMap_ad3e48 {
    TreeNode_ad3e48* mpHeader;
    uint32_t mnCount;
    // STUB: 0x0098129c
    TreeNode_ad3e48* Find(const uint32_t* key);
    // STUB: 0x0093bb6c
    InsertResult_ad3e48* Fn0093bb6c(InsertResult_ad3e48* out, const uint32_t* key);
    // STUB: 0x0093c099
    void Clear();
    cSrcMap_ad3e48* Fn0093bb06(const char* allocator);
    InsertResult_ad3e48* Fn0093c041(InsertResult_ad3e48* out, const uint32_t* key);
    void Fn0093c064(Iter_ad3e48 node);
};

// FUNCTION: 0x0093bb06
cSrcMap_ad3e48* cSrcMap_ad3e48::Fn0093bb06(const char* /*allocator*/)
{
    mpHeader = 0;
    mpHeader = Fn0093af7e()->Alloc(0x14);
    return this;
}

// FUNCTION: 0x0093c041
InsertResult_ad3e48* cSrcMap_ad3e48::Fn0093c041(InsertResult_ad3e48* out, const uint32_t* key)
{
    InsertResult_ad3e48 result;
    Fn0093bb6c(&result, key);
    out->mpNode = result.mpNode;
    out->mbInserted = result.mbInserted;
    return out;
}

// FUNCTION: 0x0093c064
void cSrcMap_ad3e48::Fn0093c064(Iter_ad3e48 node)
{
    TreeNode_ad3e48* header = mpHeader;
    TreeNode_ad3e48* removed = Fn0040daf0(node.mpNode, &header->mpParent, &header->mpLeft, &header->mpRight);
    Fn0093af7e()->Free(removed);
    --mnCount;
}

// FUNCTION: 0x0093de0f
void cHitTrackPlayer::Slot04_ad2bfc(uint32_t id)
{
    cSrcMap_ad3e48* map = reinterpret_cast<cSrcMap_ad3e48*>(&mpSourceMapHeader);
    if (map->Find(&id) != map->mpHeader) {
        InsertResult_ad3e48 result;
        map->Fn0093c041(&result, &id);
    }
    Slot07_ad2bfc();
}

// FUNCTION: 0x0093e303
bool cHitTrackPlayer::Slot05_ad2bfc(uint32_t id)
{
    cSrcMap_ad3e48* map = reinterpret_cast<cSrcMap_ad3e48*>(&mpSourceMapHeader);
    TreeNode_ad3e48* node = map->Find(&id);
    if (node != map->mpHeader) {
        map->Fn0093c064(node);
        return Slot07_ad2bfc();
    }
    return false;
}

// FUNCTION: 0x0093e339
void cHitTrackPlayer::Slot06_ad2bfc()
{
    reinterpret_cast<cSrcMap_ad3e48*>(&mpSourceMapHeader)->Clear();
    Slot07_ad2bfc();
}

// ---- batch 5

// GLOBAL: 0x00b628cc
extern void* gpB628cc;

// A system service pointer (0x004edfd0 / 0x004edf00).
struct cSvcPtrC_ad3e48 {
    void* mp;
    // STUB: 0x004edfd0
    cSvcPtrC_ad3e48();
    // STUB: 0x004edf00
    ~cSvcPtrC_ad3e48();
};

// FUNCTION: 0x00913cca
void* Fn00913cca()
{
    if (gpB628cc == 0) {
        cSvcPtrC_ad3e48 service;
        gpB628cc = service.mp;
    }
    return gpB628cc;
}

// The record the track definition hands out (field 8 is the length).
struct TrackRec_ad3e48 {
    uint32_t mnPad0;
    uint32_t mnPad1;
    uint32_t mnLength;
};

// The track definition object: slot 4 gives the track, slot 10 the position, slot 16 the record.
struct cTrackDef_ad3e48 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual uint32_t Fn10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual TrackRec_ad3e48* Fn16();
};

// A smart pointer built from a raw pointer (0x0096e773).
struct cSmartRef_ad3e48 {
    cTrackDef_ad3e48* mp;
    // STUB: 0x0096e773
    cSmartRef_ad3e48(void* p);
};

struct cHolder_ad3e48 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
    virtual void Pad3();
    virtual void* Fn4();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0093acd6 score 80
float cHitTrackPlayer::CompletionTime()
{
    cHolder_ad3e48* holder = static_cast<cHolder_ad3e48*>(mpSmart7c);
    if (holder) {
        cHolder_ad3e48* iface = 0;
        if (holder->QueryInterface(0x9d002d2, reinterpret_cast<void**>(&iface))) {
            cSmartRef_ad3e48 track(iface->Fn4());
            if (track.mp) {
                TrackRec_ad3e48* record = track.mp->Fn16();
                if (record && record->mnLength) {
                    uint32_t position = track.mp->Fn10();
                    float result = static_cast<float>(position) / static_cast<float>(record->mnLength);
                    track.mp->Release();
                    iface->Release();
                    return result;
                }
                track.mp->Release();
                iface->Release();
                return 0.0f;
            }
        }
        if (iface) {
            iface->Release();
        }
    }
    return 0.0f;
}
#endif

// A smart-pointer slot: taking its address releases what it holds first (0x004f20a0).
struct cOutSlot_ad3e48 {
    void* mp;
    // STUB: 0x004f20a0
    void** Address();
};

// The error log object RZ::HM() hands out: slot 29 logs a message for an object.
struct cLog_ad3e48 {
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
    virtual void Fn29(void* object, const char* message);
};
// STUB: 0x00913cf6
cLog_ad3e48* Fn00913cf6();

// The sample service (this+0x94): slot 18 loads a sample by id.
struct cSampleSvc_ad3e48 {
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
    virtual bool Fn18(uint32_t id, uint32_t a, uint32_t b, uint32_t iid, void** out);
};

// The hit-sem lookup object (this+0x8c): slot 22 finds a sem by id.
struct cSemLookup_ad3e48 {
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
    virtual void* Fn22(uint32_t id);
};

// A sem: slot 6 binds a register set and a sound.
struct cSem_ad3e48 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Fn6(void* regs, void* snd);
};

// The sound object (this+0x7c) slot 3 sets a register.
struct cSndB_ad3e48 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
    virtual void Fn3(uint32_t key, uint32_t value, uint32_t flag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0093b9ae score 44
bool cHitTrackPlayer::UpdatePatch()
{
    uint32_t id = Slot04_ad2bc8(0xffaec905);
    uint32_t link = Slot04_ad2bc8(0xff6f9546);
    if (link != 0 && id == link) {
        Fn00913cf6()->Fn29(this, "Recursive sound id");
        return false;
    }
    if (id != mnSoundId) {
        reinterpret_cast<cAutoRefB_ad3e48*>(&mpSmart7c)->Assign(0);
        reinterpret_cast<cAutoRefB_ad3e48*>(&mpSmart80)->Assign(0);
        mnSoundId = id;
    }
    if (mpSmart7c == 0 && id != 0) {
        cSampleSvc_ad3e48* service = static_cast<cSampleSvc_ad3e48*>(mpService);
        if (!service->Fn18(id, 0, 0, 0xfd584467, reinterpret_cast<cOutSlot_ad3e48*>(&mpSmart7c)->Address())) {
            Fn00913cf6()->Fn29(this, "Sample file not found");
            return false;
        }
    }
    if (mpSmart7c) {
        cSndB_ad3e48* snd = static_cast<cSndB_ad3e48*>(mpSmart7c);
        snd->QueryInterface(0x206077d2, reinterpret_cast<cOutSlot_ad3e48*>(&mpSmart80)->Address());
        uint32_t sem = Slot04_ad2bc8(0xff891eaa);
        if (sem) {
            reinterpret_cast<cAutoRefB_ad3e48*>(&mpSmart88)->Assign(static_cast<cSemLookup_ad3e48*>(mpField8c)->Fn22(sem));
            if (mpSmart88) {
                static_cast<cSem_ad3e48*>(mpSmart88)->Fn6(static_cast<cUnk00ad2bc8*>(this), mpSmart7c);
            }
        }
        static_cast<cSndB_ad3e48*>(mpSmart7c)->Fn3(0xfff7b8df, Slot04_ad2bc8(0xfff7b8df), 0);
    }
    Slot03_ad2bec();
    UpdatePitch();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093b200 score 20
uint32_t cHitTrackPlayer::Slot04_ad2bc8(uint32_t reg)
{
    if (reg <= 0xff) {
        uint32_t mapped = Fn009377c9(reg);
        if (mapped) {
            reg = mapped;
        }
    }
    cProvider_ad3e48** it = static_cast<cProvider_ad3e48**>(mpProvidersBegin);
    cRegValue_ad3e48 receiver;
    receiver.mnValue = 0;
    cProvider_ad3e48** end = static_cast<cProvider_ad3e48**>(mpProvidersEnd);
    while (it != end) {
        if (*it) {
            if ((*it)->Fn8(&reg, &receiver)) {
                return receiver.mnValue;
            }
        }
        ++it;
    }
    return 0;
}
#endif
