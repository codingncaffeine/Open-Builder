#include <stddef.h>
#include "classes/cHitChannel.h"

// The remapping of a register id (0x009377c9).
// STUB: 0x009377c9
uint32_t Fn009377c9(uint32_t reg);

// A smart pointer (assignment at 0x005447b0, and at 0x0094909a).
struct cAutoRefB_ad3fc0 {
    void* mp;
    // STUB: 0x005447b0
    cAutoRefB_ad3fc0& Assign(void* p);
};
struct cAutoRef_ad3fc0 {
    void* mp;
    // STUB: 0x0094909a
    cAutoRef_ad3fc0& Assign(void* p);
};

// The effects interface of the sound (asked for by id 0x4b79c1a9).
struct cEffects_ad3fc0 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
    virtual bool Fn3(float level);
    virtual bool Fn4(float level);
    virtual bool Fn5(int32_t value);
    virtual bool Fn6(int32_t value);
    virtual bool Fn7(float value);
};

// The rolloff interface of the sound (id 0x6b0446eb).
struct cRolloff_ad3fc0 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Fn6(float value);
    virtual void Fn7(float* out);
};

// The sound object this channel plays through (this+0x24).
struct cSndObj_ad3fc0 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Fn6(uint32_t a, uint32_t b, uint32_t c);
    virtual bool Fn7();
    virtual void Pad08();
    virtual void Fn9();
    virtual void Pad10();
    virtual void Pad11();
    virtual uint32_t Fn12();
    virtual void Fn13(uint32_t id);
    virtual bool Fn14();
    virtual bool Fn15();
    virtual bool Fn16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Fn21(uint32_t value);
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Fn25(uint32_t value);
    virtual int32_t Fn26();
    virtual bool Fn27(int32_t freq);
    virtual uint32_t Fn28();
};

// A receiver object handed to a register list (a vtable and one value).
struct cRegValue_ad3fc0 {
    virtual void Fn0();
    int32_t mnValue;
};
struct cRegFloat_ad3fc0 {
    virtual void Fn0();
    float mfValue;
};

// A register provider in the list at this+0x34 (slots 3 set, 4 clear, 8 get, 9 has).
struct cRegProvider_ad3fc0 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Fn3(uint32_t* key, void* receiver);
    virtual void Fn4(uint32_t* key);
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual bool Fn8(uint32_t* key, void* receiver);
    virtual bool Fn9(uint32_t* key);
};

struct ListNode_ad3fc0 {
    ListNode_ad3fc0* mpNext;
    ListNode_ad3fc0* mpPrev;
    uint32_t mnValue;
};
struct cList_ad3fc0 {
    ListNode_ad3fc0* mpHead;
};

// The object at this+0x28; slot 4 gives a value.
struct cField28_ad3fc0 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Fn3(void* value, uint32_t mode);
    virtual uint32_t Fn4();
};

// FUNCTION: 0x0093ec35
bool cHitChannel::QueryInterface(uint32_t id, void** out)
{
    void** pp = out;
    if (id == 0x206077d2) {
        *pp = static_cast<cHitChannel_0*>(this);
    } else if (id == 0x306077d2) {
        *pp = static_cast<cUnk00ac2d78*>(this);
    } else if (id == 0xfd584467) {
        *pp = static_cast<cUnk00ad2bc8*>(this);
    } else if (id == 0x5b34f0af) {
        *pp = static_cast<cUnk00a943c0*>(this);
    } else if (id == 0xaa11a64f) {
        *pp = static_cast<cUnk00ad2bec*>(this);
    } else if (id == 0x9d002d2) {
        *pp = static_cast<cUnk00ac2bdc*>(this);
    } else {
        return false;
    }
    AddRef();
    return true;
}

// FUNCTION: 0x0093ec9f
uint32_t cHitChannel::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x0093eca6
unsigned int cHitChannel::Release()
{
    if (mnRefCount <= 1) {
        delete this;
        return 0;
    }
    return --mnRefCount;
}

// FUNCTION: 0x0093ecc0
uint32_t cHitChannel::GetPan()
{
    return Slot04_ad2bc8(0xff3ec880);
}

// FUNCTION: 0x0093ecce
void cHitChannel::SetPan(uint32_t value)
{
    Slot03_ad2bc8(0xff3ec880, value, 0);
}

// FUNCTION: 0x0093ece4
uint32_t cHitChannel::GetFrequency()
{
    return Slot04_ad2bc8(0xff099db2);
}

// FUNCTION: 0x0093ecf2
void cHitChannel::SetFrequency(uint32_t value)
{
    Slot03_ad2bc8(0xff099db2, value, 0);
}

// FUNCTION: 0x0093ed08
void cHitChannel::SetVolume(uint32_t value)
{
    Slot03_ad2bc8(0xff90aac8, value, 0);
}

// FUNCTION: 0x0093ed1e
uint32_t cHitChannel::GetVolume()
{
    return Slot04_ad2bc8(0xff90aac8);
}

// FUNCTION: 0x0093efe0
void cHitChannel::Slot11_ac2d78(uint32_t /*out*/)
{
    Slot04_ad2bc8(0xffaab623);
}

// FUNCTION: 0x0093eff0
bool cHitChannel::Slot12_ac2d78(uint32_t value)
{
    float f = *reinterpret_cast<float*>(&value);
    return Slot03_ad2bc8(0xffaab623, static_cast<int32_t>(f), 0);
}

// FUNCTION: 0x0093f012
void cHitChannel::Slot13_ac2d78(uint32_t /*out*/)
{
    Slot04_ad2bc8(0xffa6a614);
}

// FUNCTION: 0x0093f022
bool cHitChannel::Slot14_ac2d78(uint32_t value)
{
    float f = *reinterpret_cast<float*>(&value);
    return Slot03_ad2bc8(0xffa6a614, static_cast<int32_t>(f), 0);
}

// FUNCTION: 0x0093f044
bool cHitChannel::Slot15_ac2d78(bool flag)
{
    return Slot03_ad2bc8(0xffcaa344, flag, 0);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093f05c score 5
bool cHitChannel::Slot16_ac2d78()
{
    return Slot04_ad2bc8(0xffcaa344) != 0;
}
#endif

// FUNCTION: 0x0093f06f
bool cHitChannel::Unload()
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    if (snd) {
        snd->Fn15();
    }
    return true;
}

// FUNCTION: 0x0093f2f3
bool cHitChannel::Slot03_ac2bdc(uint32_t value, uint32_t /*unused*/)
{
    reinterpret_cast<cAutoRef_ad3fc0*>(&mpSmart2c)->Assign(OB_PTR(void, value));
    return true;
}

// FUNCTION: 0x0093f44e
uint32_t cHitChannel::GetOriginalFrequency()
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    if (snd) {
        return snd->Fn28();
    }
    return 0;
}

// FUNCTION: 0x0093f45d
uint32_t cHitChannel::GetID()
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    if (snd) {
        return snd->Fn12();
    }
    return 0;
}

// FUNCTION: 0x0093f46c
void cHitChannel::SetID(uint32_t id)
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    if (snd) {
        snd->Fn13(id);
    }
}

// FUNCTION: 0x0093f47b
void cHitChannel::SetRolloffFactor(uint32_t value)
{
    float f = *reinterpret_cast<float*>(&value);
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    cRolloff_ad3fc0* iface = 0;
    if (snd) {
        if (snd->QueryInterface(0x6b0446eb, reinterpret_cast<void**>(&iface))) {
            iface->Fn6(f);
        }
        if (iface) {
            iface->Release();
        }
    }
}

// FUNCTION: 0x0093f4ba
void cHitChannel::GetRolloffFactor(uint32_t out)
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    cRolloff_ad3fc0* iface = 0;
    if (snd) {
        if (snd->QueryInterface(0x6b0446eb, reinterpret_cast<void**>(&iface))) {
            iface->Fn7(OB_PTR(float, out));
        }
        if (iface) {
            iface->Release();
        }
    }
}

// FUNCTION: 0x0093f4f5
bool cHitChannel::SetInputDryLevel(uint32_t value)
{
    float f = *reinterpret_cast<float*>(&value);
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    cEffects_ad3fc0* iface = 0;
    if (snd) {
        if (snd->QueryInterface(0x4b79c1a9, reinterpret_cast<void**>(&iface))) {
            bool result = iface->Fn3(f);
            if (iface) {
                iface->Release();
            }
            return result;
        }
        if (iface) {
            iface->Release();
        }
    }
    return false;
}

// FUNCTION: 0x0093f547
bool cHitChannel::SetInputEffectLevel(uint32_t value)
{
    float f = *reinterpret_cast<float*>(&value);
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    cEffects_ad3fc0* iface = 0;
    if (snd) {
        if (snd->QueryInterface(0x4b79c1a9, reinterpret_cast<void**>(&iface))) {
            bool result = iface->Fn4(f);
            if (iface) {
                iface->Release();
            }
            return result;
        }
        if (iface) {
            iface->Release();
        }
    }
    return false;
}

// FUNCTION: 0x0093f599
bool cHitChannel::SetLowPassCutoff(uint32_t value)
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    cEffects_ad3fc0* iface = 0;
    if (snd) {
        if (snd->QueryInterface(0x4b79c1a9, reinterpret_cast<void**>(&iface))) {
            bool result = iface->Fn5(value);
            if (iface) {
                iface->Release();
            }
            return result;
        }
        if (iface) {
            iface->Release();
        }
    }
    return false;
}

// FUNCTION: 0x0093f5e7
bool cHitChannel::SetHighPassCutoff(uint32_t value)
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    cEffects_ad3fc0* iface = 0;
    if (snd) {
        if (snd->QueryInterface(0x4b79c1a9, reinterpret_cast<void**>(&iface))) {
            bool result = iface->Fn6(value);
            if (iface) {
                iface->Release();
            }
            return result;
        }
        if (iface) {
            iface->Release();
        }
    }
    return false;
}

// FUNCTION: 0x0093f635
bool cHitChannel::SetTimeMultiplier(uint32_t value)
{
    float f = *reinterpret_cast<float*>(&value);
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    cEffects_ad3fc0* iface = 0;
    if (snd) {
        if (snd->QueryInterface(0x4b79c1a9, reinterpret_cast<void**>(&iface))) {
            bool result = iface->Fn7(f);
            if (iface) {
                iface->Release();
            }
            return result;
        }
        if (iface) {
            iface->Release();
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093f6ba score 13
uint32_t cHitChannel::Slot04_ad2bc8(uint32_t reg)
{
    uint32_t key = reg;
    if (reg <= 0xff) {
        uint32_t mapped = Fn009377c9(reg);
        if (mapped) {
            key = mapped;
        }
    }
    cList_ad3fc0* list = static_cast<cList_ad3fc0*>(mpRegLists);
    cRegValue_ad3fc0 receiver;
    receiver.mnValue = 0;
    ListNode_ad3fc0* head = list->mpHead;
    ListNode_ad3fc0* node = head->mpNext;
    while (node != head) {
        cRegProvider_ad3fc0* provider = OB_PTR(cRegProvider_ad3fc0, node->mnValue);
        if (provider) {
            if (provider->Fn8(&key, &receiver)) {
                return receiver.mnValue;
            }
        }
        node = node->mpNext;
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093f71b score 13
float cHitChannel::Slot08_ad2bc8(uint32_t reg)
{
    uint32_t key = reg;
    if (reg <= 0xff) {
        uint32_t mapped = Fn009377c9(reg);
        if (mapped) {
            key = mapped;
        }
    }
    cList_ad3fc0* list = static_cast<cList_ad3fc0*>(mpRegLists);
    cRegFloat_ad3fc0 receiver;
    receiver.mfValue = 0.0f;
    ListNode_ad3fc0* head = list->mpHead;
    ListNode_ad3fc0* node = head->mpNext;
    while (node != head) {
        cRegProvider_ad3fc0* provider = OB_PTR(cRegProvider_ad3fc0, node->mnValue);
        if (provider) {
            if (provider->Fn8(&key, &receiver)) {
                return receiver.mfValue;
            }
        }
        node = node->mpNext;
    }
    return 0.0f;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093f781 score 14
void cHitChannel::Slot05_ad2bc8(uint32_t reg, uint32_t flag)
{
    uint32_t key = reg;
    if (reg <= 0xff) {
        Fn009377c9(reg);
    }
    cList_ad3fc0* list = static_cast<cList_ad3fc0*>(mpRegLists);
    OB_PTR(cRegProvider_ad3fc0, list->mpHead->mnValue)->Fn4(&key);
}
#endif

// FUNCTION: 0x0093f7b4
void cHitChannel::Slot06_ad2bc8(uint32_t reg)
{
    uint32_t key = reg;
    if (reg <= 0xff) {
        uint32_t mapped = Fn009377c9(reg);
        if (mapped) {
            key = mapped;
        }
    }
    cList_ad3fc0* list = static_cast<cList_ad3fc0*>(mpRegLists);
    OB_PTR(cRegProvider_ad3fc0, list->mpHead->mnValue)->Fn9(&key);
}

// FUNCTION: 0x0093f84d
bool cHitChannel::Load()
{
    bool result = true;
    UpdatePatch();
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    if (snd) {
        result = snd->Fn14();
        UpdatePatch();
        UpdatePitch();
    }
    return result;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093f806 score 23
bool cHitChannel::NoteOn()
{
    UpdatePatch();
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    if (snd) {
        if (Load()) {
            bool flag = Slot04_ad2bc8(0xfff7b8df) != 0;
            snd->Fn6(mnField1c, flag, 1);
        }
    }
    return true;
}
#endif

// FUNCTION: 0x0093f933
void* cHitChannel::Slot03_ad3e48()
{
    return static_cast<cHitChannel_0*>(this);
}

// FUNCTION: 0x0093f937
bool cHitChannel::Shutdown()
{
    mnRefCount = 0;
    return true;
}

// FUNCTION: 0x0093f93e
void cHitChannel::Slot06_ad3fc0(uint32_t /*a*/, uint32_t /*b*/, uint32_t /*c*/)
{
    NoteOn();
}

// FUNCTION: 0x0093f949
void cHitChannel::Play(uint32_t /*a*/, uint32_t /*b*/, uint32_t /*c*/, uint32_t /*d*/)
{
    NoteOn();
}

// FUNCTION: 0x0093f954
void cHitChannel::Slot07_ad3fc0()
{
    NoteIsPlaying();
}

// FUNCTION: 0x0093f95c
void cHitChannel::Slot08_ad3fc0()
{
    Slot41_ad3fc0();
}

// FUNCTION: 0x0093f964
void cHitChannel::Slot09_ad3fc0()
{
    NoteKill();
}

// FUNCTION: 0x0093f96c
bool cHitChannel::Pause(uint32_t /*flag*/)
{
    Slot03_ad2bc8(0x18, 1, 0);
    return true;
}

// FUNCTION: 0x0093f97f
bool cHitChannel::Unpause()
{
    Slot03_ad2bc8(0x18, 0, 0);
    return true;
}

// FUNCTION: 0x0093f990
uint32_t cHitChannel::IsPaused()
{
    return Slot04_ad2bc8(0x18) != 0;
}

// FUNCTION: 0x0093fa19
uint32_t cHitChannel::Slot04_ac2bdc()
{
    return static_cast<cField28_ad3fc0*>(mpField28)->Fn4();
}

// FUNCTION: 0x0093fa21
bool cHitChannel::Slot04_ad3fc0()
{
    reinterpret_cast<cAutoRefB_ad3fc0*>(&mpSnd)->Assign(0);
    return true;
}

// FUNCTION: 0x0093fa2e
bool cHitChannel::NoteKill()
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    if (snd) {
        snd->Fn9();
    }
    return true;
}

// FUNCTION: 0x0093fa3d
bool cHitChannel::NoteIsPlaying()
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    if (!snd) {
        return false;
    }
    return snd->Fn7();
}

// FUNCTION: 0x0093fa4c
bool cHitChannel::IsLoaded()
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    if (snd) {
        return snd->Fn16();
    }
    return false;
}

// The register subobject (this+0xc) with the return types the original shows.
struct cRegsView_ad3fc0 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual bool Fn3(uint32_t id, int32_t value, uint32_t flag);
    virtual uint32_t Fn4(uint32_t id);
    virtual void Pad5();
    virtual bool Fn6(uint32_t id);
    virtual void Pad7();
    virtual float Fn8(uint32_t id);
};

// FUNCTION: 0x0093ed2c
void cHitChannel::Slot04_ac2d78(uint32_t pa, uint32_t pb, uint32_t pc)
{
    float* x = OB_PTR(float, pa);
    float* y = OB_PTR(float, pb);
    float* z = OB_PTR(float, pc);
    if (x) {
        *x = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xffcc4d2d)));
    }
    if (y) {
        *y = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xff4a01d6)));
    }
    if (z) {
        *z = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xff469820)));
    }
}

// FUNCTION: 0x0093ed8d
bool cHitChannel::Slot05_ac2d78(uint32_t a, uint32_t b, uint32_t c)
{
    float x = *reinterpret_cast<float*>(&a);
    float y = *reinterpret_cast<float*>(&b);
    float z = *reinterpret_cast<float*>(&c);
    Slot03_ad2bc8(0xffcc4d2d, static_cast<int32_t>(x), 0);
    Slot03_ad2bc8(0xff4a01d6, static_cast<int32_t>(y), 0);
    Slot03_ad2bc8(0xff469820, static_cast<int32_t>(z), 0);
    return true;
}

// FUNCTION: 0x0093ede1
void cHitChannel::Slot06_ac2d78(uint32_t pa, uint32_t pb, uint32_t pc)
{
    float* x = OB_PTR(float, pa);
    float* y = OB_PTR(float, pb);
    float* z = OB_PTR(float, pc);
    if (x) {
        *x = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xff444c9a)));
    }
    if (y) {
        *y = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xffc20061)));
    }
    if (z) {
        *z = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xffce9997)));
    }
}

// FUNCTION: 0x0093ee42
bool cHitChannel::Slot07_ac2d78(uint32_t a, uint32_t b, uint32_t c)
{
    float x = *reinterpret_cast<float*>(&a);
    float y = *reinterpret_cast<float*>(&b);
    float z = *reinterpret_cast<float*>(&c);
    Slot03_ad2bc8(0xff444c9a, static_cast<int32_t>(x), 0);
    Slot03_ad2bc8(0xffc20061, static_cast<int32_t>(y), 0);
    Slot03_ad2bc8(0xffce9997, static_cast<int32_t>(z), 0);
    return true;
}

// FUNCTION: 0x0093ee96
void cHitChannel::Slot08_ac2d78(uint32_t pa, uint32_t pb, uint32_t pc, uint32_t pd, uint32_t pe, uint32_t pf)
{
    float* x = OB_PTR(float, pa);
    float* y = OB_PTR(float, pb);
    float* z = OB_PTR(float, pc);
    float* vx = OB_PTR(float, pd);
    float* vy = OB_PTR(float, pe);
    float* vz = OB_PTR(float, pf);
    if (vx) {
        *vx = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xff444c9a)));
    }
    if (vy) {
        *vy = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xffc20061)));
    }
    if (vz) {
        *vz = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xffce9997)));
    }
    if (x) {
        *x = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xffcc4d2d)));
    }
    if (y) {
        *y = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xff4a01d6)));
    }
    if (z) {
        *z = static_cast<float>(static_cast<int32_t>(Slot04_ad2bc8(0xff469820)));
    }
}

// FUNCTION: 0x0093ef4b
bool cHitChannel::Slot09_ac2d78(uint32_t a, uint32_t b, uint32_t /*c*/, uint32_t d, uint32_t e, uint32_t f)
{
    float x = *reinterpret_cast<float*>(&a);
    float y = *reinterpret_cast<float*>(&b);
    float vx = *reinterpret_cast<float*>(&d);
    float vy = *reinterpret_cast<float*>(&e);
    float vz = *reinterpret_cast<float*>(&f);
    Slot03_ad2bc8(0xff444c9a, static_cast<int32_t>(vx), 0);
    Slot03_ad2bc8(0xffc20061, static_cast<int32_t>(vy), 0);
    int32_t v = static_cast<int32_t>(vz);
    Slot03_ad2bc8(0xffce9997, v, 0);
    Slot03_ad2bc8(0xffcc4d2d, static_cast<int32_t>(x), 0);
    Slot03_ad2bc8(0xff4a01d6, static_cast<int32_t>(y), 0);
    Slot03_ad2bc8(0xff469820, v, 0);
    return true;
}

// FUNCTION: 0x0093f687
bool cHitChannel::UpdatePatch()
{
    if (mpSnd == 0) {
        CreateSnd();
    }
    static_cast<cField28_ad3fc0*>(mpField28)->Fn3(mpSmart2c, 2);
    UpdateVolPan();
    UpdatePitch();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0093f07e score 23
bool cHitChannel::UpdatePitch()
{
    cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
    if (snd) {
        if (snd->Fn16()) {
            cRegsView_ad3fc0* regs = reinterpret_cast<cRegsView_ad3fc0*>(reinterpret_cast<char*>(this) + 0xc);
            float ratio = 1.0f;
            if (regs->Fn6(0xff3071b9)) {
                ratio = regs->Fn8(0xff3071b9);
            }
            uint32_t result = 0;
            if (regs->Fn6(0xff099db2)) {
                int32_t freq = static_cast<int32_t>(regs->Fn4(0xff099db2));
                result = static_cast<cSndObj_ad3fc0*>(mpSnd)->Fn27(static_cast<int32_t>(freq * ratio));
            } else {
                int32_t original = snd->Fn26();
                regs->Fn3(0xff099db2, static_cast<int32_t>(original * ratio), 1);
            }
            return result == 0;
        }
    }
    return false;
}
#endif

// The 3D sound interface of the sound object (id 0x306077d2).
struct cSnd3D_ad3fc0 {
    virtual bool QueryInterface(uint32_t id, void** out);
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Fn5(float x, float y, float z);
    virtual void Pad06();
    virtual void Fn7(float x, float y, float z);
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Fn12(float value);
    virtual void Pad13();
    virtual void Fn14(float value);
    virtual void Fn15(bool flag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0093f136 score 59
bool cHitChannel::UpdateVolPan()
{
    if (mpSnd) {
        cRegsView_ad3fc0* regs = reinterpret_cast<cRegsView_ad3fc0*>(reinterpret_cast<char*>(this) + 0xc);
        if (regs->Fn4(0xffcc156f)) {
            cSnd3D_ad3fc0* iface = 0;
            cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
            if (snd && snd->QueryInterface(0x306077d2, reinterpret_cast<void**>(&iface)) && iface) {
                iface->Fn12(static_cast<float>(static_cast<int32_t>(regs->Fn4(0xffaab623))));
                float maxDistance = static_cast<float>(static_cast<int32_t>(regs->Fn4(0xffa6a614)));
                if (maxDistance == 0.0f) {
                    maxDistance = 100000.0f;
                }
                iface->Fn14(maxDistance);
                float x = static_cast<float>(static_cast<int32_t>(regs->Fn4(0xffcc4d2d)));
                float y = static_cast<float>(static_cast<int32_t>(regs->Fn4(0xff4a01d6)));
                float z = static_cast<float>(static_cast<int32_t>(regs->Fn4(0xff469820)));
                iface->Fn5(x, y, z);
                float vx = static_cast<float>(static_cast<int32_t>(regs->Fn4(0xff444c9a)));
                float vy = static_cast<float>(static_cast<int32_t>(regs->Fn4(0xffc20061)));
                float vz = static_cast<float>(static_cast<int32_t>(regs->Fn4(0xffce9997)));
                iface->Fn7(vx, vy, vz);
                iface->Release();
            }
        } else {
            cSndObj_ad3fc0* snd = static_cast<cSndObj_ad3fc0*>(mpSnd);
            snd->Fn25(regs->Fn4(0xff3ec880));
            int32_t volume = static_cast<int32_t>(regs->Fn4(0xff90aac8));
            int32_t scale = static_cast<int32_t>(regs->Fn4(0xff53dbf3));
            mnField1c = (scale * volume) / 0x400;
            static_cast<cSndObj_ad3fc0*>(mpSnd)->Fn21(mnField1c);
        }
    }
    return true;
}
#endif

// The object at this+0x30 hands out the id of the sound to create (slots 9 and 11).
struct cFactory_ad3fc0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Fn9(uint32_t* out);
    virtual void Pad10();
    virtual void Fn11(uint32_t* out);
};

// The framework object (GZCOM): slot 3 creates a component by id.
struct cGZCOM_ad3fc0 {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Fn3(uint32_t cls, uint32_t iid, void** out);
};
// STUB: 0x0090ddf1
cGZCOM_ad3fc0* Fn0090ddf1();

// A smart-pointer slot: taking its address releases what it holds first (0x004f20a0 / 0x00874da3).
struct cOutSlot_ad3fc0 {
    void* mp;
    // STUB: 0x004f20a0
    void** Address();
};
struct cOutSlotB_ad3fc0 {
    void* mp;
    // STUB: 0x00874da3
    void** Address();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0093f304 score 68
bool cHitChannel::CreateSnd()
{
    cRegsView_ad3fc0* regs = reinterpret_cast<cRegsView_ad3fc0*>(reinterpret_cast<char*>(this) + 0xc);
    uint32_t cls[2];
    if (regs->Fn4(0xffcc156f)) {
        static_cast<cFactory_ad3fc0*>(mpFactory)->Fn11(cls);
    } else {
        static_cast<cFactory_ad3fc0*>(mpFactory)->Fn9(cls);
    }
    cGZCOM_ad3fc0* com = Fn0090ddf1();
    com->Fn3(cls[0], 0x206077d2, reinterpret_cast<cOutSlot_ad3fc0*>(&mpSnd)->Address());
    if (mpSnd) {
        static_cast<cSndObj_ad3fc0*>(mpSnd)->AddRef();
        static_cast<cSndObj_ad3fc0*>(mpSnd)->QueryInterface(0x9d002d2, reinterpret_cast<cOutSlotB_ad3fc0*>(&mpField28)->Address());
    }
    if (regs->Fn4(0xffcc156f)) {
        cSnd3D_ad3fc0* iface = 0;
        static_cast<cSndObj_ad3fc0*>(mpSnd)->QueryInterface(0x306077d2, reinterpret_cast<void**>(&iface));
        iface->Fn15(regs->Fn4(0xffcaa344) != 0);
        if (regs->Fn4(0xffaab623)) {
            iface->Fn12(static_cast<float>(static_cast<int32_t>(regs->Fn4(0xffaab623))));
        }
        if (regs->Fn4(0xffa6a614)) {
            iface->Fn14(static_cast<float>(static_cast<int32_t>(regs->Fn4(0xffa6a614))));
        }
        if (iface) {
            iface->Release();
        }
    }
    return mpField28 != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093fd3c score 28
bool cHitChannel::Slot03_ad2bc8(uint32_t reg, uint32_t value, uint32_t skipNotify)
{
    if (reg <= 0xff) {
        uint32_t mapped = Fn009377c9(reg);
        if (mapped) {
            reg = mapped;
        }
    }
    cList_ad3fc0* list = static_cast<cList_ad3fc0*>(mpRegLists);
    cRegValue_ad3fc0 receiver;
    receiver.mnValue = value;
    OB_PTR(cRegProvider_ad3fc0, list->mpHead->mnValue)->Fn3(&reg, &receiver);
    if (!(skipNotify & 0xff)) {
        Fn0093fa5b(reg);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0093fd99 score 28
bool cHitChannel::Slot07_ad2bc8(uint32_t reg, uint32_t value, uint32_t skipNotify)
{
    if (reg <= 0xff) {
        uint32_t mapped = Fn009377c9(reg);
        if (mapped) {
            reg = mapped;
        }
    }
    cList_ad3fc0* list = static_cast<cList_ad3fc0*>(mpRegLists);
    cRegFloat_ad3fc0 receiver;
    receiver.mfValue = *reinterpret_cast<float*>(&value);
    OB_PTR(cRegProvider_ad3fc0, list->mpHead->mnValue)->Fn3(&reg, &receiver);
    if (!(skipNotify & 0xff)) {
        Fn0093fa5b(reg);
    }
    return true;
}
#endif
