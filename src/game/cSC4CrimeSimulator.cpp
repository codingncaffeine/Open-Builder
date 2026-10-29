#include "classes/cSC4CrimeSimulator.h"
#include "classes/cUnk00a878c0.h"
#include "gzcom/cRZString.h"

// The object seen as its four vtable pointers and the data after them (offsets from the object).
struct Vec_ab0dc8 {
    void** mpBegin;
    void** mpEnd;
    void** mpCap;
    uint32_t size() const { return static_cast<uint32_t>(mpEnd - mpBegin); }
    void* operator[](uint32_t i) const { return mpBegin[i]; }
    // STUB: 0x0051ca60
    void Fn0051ca60(void** pos, void** a, void** b, uint32_t n, uint32_t m);
};

struct View_ab0dc8 {
    void* mpVtables[4];      // 0x0
    uint8_t mbInitialized;   // 0x10
    uint8_t mbFlag11;        // 0x11
    int32_t mnRefCount;      // 0x14
    uint8_t mRegion18[0x30]; // 0x18
    void* mpApp48;           // 0x48
    void* mpRegistry4c;      // 0x4c
    void* mpObj50;           // 0x50
    void* mpObj54;           // 0x54
    void* mpObj58;           // 0x58
    void* mpGrid5c;          // 0x5c
    void* mpGrid60;          // 0x60
    uint32_t mn64;           // 0x64
    uint32_t mn68;           // 0x68
    float mf6c;              // 0x6c
    Vec_ab0dc8 mItems;       // 0x70
    uint32_t mn7c;           // 0x7c
    int32_t mn80;            // 0x80
    int32_t mn84;            // 0x84
    int32_t mn88;            // 0x88
    float mf8c;              // 0x8c
    uint8_t mbState90;       // 0x90
    uint8_t mPad91[0x47];    // 0x91
    uint32_t mnD8;           // 0xd8
    uint32_t mnDc;           // 0xdc: an object, used by address
};

// The same data seen from the subobject at +0x4 (offsets are the object's minus 4).
struct Sub4_ab0dc8 {
    uint8_t mPad[0x50];
    void* mpObj54;
    uint8_t mPad54[0x34];
    float mf8c;
    uint8_t mbState90;
};

struct Item_ab0dc8 {
    uint8_t pad[0x28];
    bool mbFlag;
};

// FUNCTION: 0x0069f350
int32_t cSC4CrimeSimulator::Slot06_ab0dc8()
{
    return static_cast<int32_t>(reinterpret_cast<View_ab0dc8*>(this)->mf6c);
}

// FUNCTION: 0x0069f5d0
uint32_t cSC4CrimeSimulator::Slot02_ab0dc8()
{
    View_ab0dc8* self = reinterpret_cast<View_ab0dc8*>(this);
    if (self->mnRefCount > 1) {
        self->mnRefCount = self->mnRefCount - 1;
        return self->mnRefCount;
    }
    Shutdown();
    delete this;
    return 0;
}

// FUNCTION: 0x0069f9a0
bool cSC4CrimeSimulator::GetVisualsCreated(uint32_t index)
{
    View_ab0dc8* self = reinterpret_cast<View_ab0dc8*>(this);
    if (index < self->mItems.size()) {
        return static_cast<Item_ab0dc8*>(self->mItems[index])->mbFlag;
    }
    return false;
}

// FUNCTION: 0x0069fd40
bool cSC4CrimeSimulator::SetVisualsCreated(uint32_t index, uint32_t value)
{
    View_ab0dc8* self = reinterpret_cast<View_ab0dc8*>(this);
    if (index < self->mItems.size()) {
        static_cast<Item_ab0dc8*>(self->mItems[index])->mbFlag = *reinterpret_cast<bool*>(&value);
        return true;
    }
    return false;
}

// FUNCTION: 0x0069f430
bool cSC4CrimeSimulator::GetCrimeHotspot(void* a, void* b, void* c)
{
    View_ab0dc8* self = reinterpret_cast<View_ab0dc8*>(this);
    if (self->mn88 > 0) {
        if (a) {
            *static_cast<uint8_t*>(a) = static_cast<uint8_t>(self->mn88);
        }
        if (b) {
            *static_cast<int32_t*>(b) = static_cast<cUnk00a878c0*>(self->mpGrid5c)->Slot10_a878c0() * self->mn80;
        }
        if (c) {
            *static_cast<int32_t*>(c) = static_cast<cUnk00a878c0*>(self->mpGrid5c)->Slot10_a878c0() * self->mn84;
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x0069f1b0
bool cSC4CrimeSimulator::QueryInterface(uint32_t iid, void* out)
{
    void** pp = static_cast<void**>(out);
    switch (iid) {
    case 1:
    case 0x67659555:
        *pp = this;
        Slot01_ab0dc8();
        return true;
    case 0x452294aa:
        *pp = static_cast<cSC4CrimeSimulator_4*>(this);
        Slot01_ab0dc8();
        return true;
    case 0x89c498be:
        *pp = static_cast<cSC4CrimeSimulator_8*>(this);
        Slot01_ab0dc8();
        return true;
    case 0xe4fda3d4:
        *pp = static_cast<cSC4CrimeSimulator_c*>(this);
        Slot01_ab0dc8();
        return true;
    }
    return false;
}

// STUB: 0x006a1450
void Fn006a1450();

// Views of the objects this class calls; only the slots it uses are named.
struct Com_ab0dc8 {
    virtual bool QueryInterface(uint32_t, void**);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

struct Listener_ab0dc8 {
    virtual void Pad00_ab0dc8(); virtual void Pad01_ab0dc8(); virtual void Pad02_ab0dc8(); virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8(); virtual void Pad05_ab0dc8(); virtual void Pad06_ab0dc8(); virtual void Pad07_ab0dc8();
    virtual void Pad08_ab0dc8(); virtual void Pad09_ab0dc8(); virtual void Pad10_ab0dc8(); virtual void Pad11_ab0dc8();
    virtual void Pad12_ab0dc8(); virtual void Pad13_ab0dc8(); virtual void Pad14_ab0dc8(); virtual void Pad15_ab0dc8();
    virtual void Pad16_ab0dc8(); virtual void Pad17_ab0dc8(); virtual void Pad18_ab0dc8(); virtual void Pad19_ab0dc8();
    virtual void Fn20_ab0dc8(void* listener);
};

// The object at 0x00b43cec.
struct cB43cec_ab0dc8 : public Com_ab0dc8 {
    virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8(); virtual void Pad05_ab0dc8(); virtual void Pad06_ab0dc8(); virtual void Pad07_ab0dc8();
    virtual void Pad08_ab0dc8(); virtual void Pad09_ab0dc8(); virtual void Pad10_ab0dc8(); virtual void Pad11_ab0dc8();
    virtual void Pad12_ab0dc8(); virtual void Pad13_ab0dc8(); virtual void Pad14_ab0dc8(); virtual void Pad15_ab0dc8();
    virtual void Pad16_ab0dc8(); virtual void Pad17_ab0dc8(); virtual void Pad18_ab0dc8(); virtual void Pad19_ab0dc8();
    virtual void Pad20_ab0dc8(); virtual void Pad21_ab0dc8(); virtual void Pad22_ab0dc8(); virtual void Pad23_ab0dc8();
    virtual void Pad24_ab0dc8(); virtual void Pad25_ab0dc8(); virtual void Pad26_ab0dc8(); virtual void Pad27_ab0dc8();
    virtual void Pad28_ab0dc8(); virtual void Pad29_ab0dc8(); virtual void Pad30_ab0dc8(); virtual void Pad31_ab0dc8();
    virtual void Pad32_ab0dc8(); virtual void Pad33_ab0dc8();
    virtual Com_ab0dc8* Fn34_ab0dc8();
    virtual void Pad35_ab0dc8(); virtual void Pad36_ab0dc8(); virtual void Pad37_ab0dc8(); virtual void Pad38_ab0dc8();
    virtual void Pad39_ab0dc8(); virtual void Pad40_ab0dc8(); virtual void Pad41_ab0dc8(); virtual void Pad42_ab0dc8();
    virtual void Pad43_ab0dc8(); virtual void Pad44_ab0dc8(); virtual void Pad45_ab0dc8(); virtual void Pad46_ab0dc8();
    virtual void Pad47_ab0dc8(); virtual void Pad48_ab0dc8(); virtual void Pad49_ab0dc8();
    virtual Listener_ab0dc8* Fn50_ab0dc8();
    virtual void Pad51_ab0dc8();
    virtual void Pad52_ab0dc8();
    virtual void Pad53_ab0dc8();
    virtual void Pad54_ab0dc8();
    virtual void Pad55_ab0dc8();
    virtual void Pad56_ab0dc8();
    virtual void Pad57_ab0dc8();
    virtual void Pad58_ab0dc8();
    virtual void Pad59_ab0dc8();
    virtual void Pad60_ab0dc8();
    virtual void Pad61_ab0dc8();
    virtual void Pad62_ab0dc8();
    virtual void Pad63_ab0dc8();
    virtual void Pad64_ab0dc8();
    virtual void Pad65_ab0dc8();
    virtual void Pad66_ab0dc8();
    virtual void Pad67_ab0dc8();
    virtual void Pad68_ab0dc8();
    virtual void Pad69_ab0dc8();
    virtual void Pad70_ab0dc8();
    virtual void Pad71_ab0dc8();
    virtual void Pad72_ab0dc8();
    virtual void Pad73_ab0dc8();
    virtual void Pad74_ab0dc8();
    virtual void Pad75_ab0dc8();
    virtual void Pad76_ab0dc8();
    virtual void Pad77_ab0dc8();
    virtual void Pad78_ab0dc8();
    virtual void Pad79_ab0dc8();
    virtual void Pad80_ab0dc8();
    virtual void Pad81_ab0dc8();
    virtual void Pad82_ab0dc8();
    virtual void Pad83_ab0dc8();
    virtual void Pad84_ab0dc8();
    virtual void Pad85_ab0dc8();
    virtual void Pad86_ab0dc8();
    virtual void Pad87_ab0dc8();
    virtual void Pad88_ab0dc8();
    virtual void Pad89_ab0dc8();
    virtual void Pad90_ab0dc8();
    virtual void Pad91_ab0dc8();
    virtual void Pad92_ab0dc8();
    virtual void Pad93_ab0dc8();
    virtual void Pad94_ab0dc8();
    virtual void Fn95_ab0dc8(uint32_t x, uint32_t z, void* a, void* b);
};
// GLOBAL: 0x00b43cec
extern cB43cec_ab0dc8* gpB43cec;

// The registry at 0x00b43ccc is shared: slot 6 unregisters an object under an id.
struct Registry_ab0dc8 : public Com_ab0dc8 {
    virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8();
    virtual void Fn05_ab0dc8(void* object, uint32_t id);
    virtual void Fn06_ab0dc8(void* object, uint32_t id);
};

// The object the message was sent to.
struct Chooser_ab0dc8 {
    virtual void Pad00_ab0dc8(); virtual void Pad01_ab0dc8(); virtual void Pad02_ab0dc8();
    virtual bool Fn03_ab0dc8(uint32_t id);
};

struct Picked_ab0dc8 {
    virtual void Pad00_ab0dc8(); virtual void Pad01_ab0dc8(); virtual void Pad02_ab0dc8(); virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8(); virtual void Pad05_ab0dc8();
    virtual Chooser_ab0dc8* Fn06_ab0dc8();
};

struct Message_ab0dc8 {
    virtual void Pad00_ab0dc8(); virtual void Pad01_ab0dc8(); virtual void Pad02_ab0dc8(); virtual void Pad03_ab0dc8();
    virtual uint32_t Fn04_ab0dc8();
    virtual void Pad05_ab0dc8(); virtual void Pad06_ab0dc8(); virtual void Pad07_ab0dc8(); virtual void Pad08_ab0dc8();
    virtual uint32_t Fn09_ab0dc8();
    virtual Picked_ab0dc8* Fn10_ab0dc8();
    virtual void Pad11_ab0dc8(); virtual void Pad12_ab0dc8(); virtual void Pad13_ab0dc8();
    virtual uint32_t Fn14_ab0dc8();
    virtual void Pad15_ab0dc8(); virtual void Pad16_ab0dc8(); virtual void Pad17_ab0dc8(); virtual void Pad18_ab0dc8();
    virtual uint32_t Fn19_ab0dc8();
};

struct Source_ab0dc8 {
    virtual void Pad00_ab0dc8(); virtual void Pad01_ab0dc8(); virtual void Pad02_ab0dc8(); virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8(); virtual void Pad05_ab0dc8(); virtual void Pad06_ab0dc8(); virtual void Pad07_ab0dc8();
    virtual void Pad08_ab0dc8(); virtual void Pad09_ab0dc8(); virtual void Pad10_ab0dc8(); virtual void Pad11_ab0dc8();
    virtual void Pad12_ab0dc8(); virtual void Pad13_ab0dc8(); virtual void Pad14_ab0dc8(); virtual void Pad15_ab0dc8();
    virtual void Pad16_ab0dc8(); virtual void Pad17_ab0dc8(); virtual void Pad18_ab0dc8(); virtual void Pad19_ab0dc8();
    virtual void Pad20_ab0dc8(); virtual void Pad21_ab0dc8(); virtual void Pad22_ab0dc8(); virtual void Pad23_ab0dc8();
    virtual void Pad24_ab0dc8();
    virtual float Fn25_ab0dc8(uint32_t, uint32_t);
};

// The object at +0xdc: STUB, a random-looking jitter of a float.
struct Jitter_ab0dc8 {
    // STUB: 0x005f4250
    float Fn005f4250(float value);
};

// FUNCTION: 0x0069f710
uint32_t cSC4CrimeSimulator_8::GetRequestedShare(void* rect)
{
    View_ab0dc8& self = *reinterpret_cast<View_ab0dc8*>(reinterpret_cast<char*>(this) - 8);
    const int32_t* r = static_cast<const int32_t*>(rect);
    uint8_t cell = static_cast<cUnk00a878c0*>(self.mpGrid5c)->Slot08_a878c0(r[0], r[1], r[2] - r[0], r[3] - r[1]);
    float f = static_cast<float>(cell) * 0.0039215689f;
    f = reinterpret_cast<Jitter_ab0dc8*>(&self.mnDc)->Fn005f4250(f);
    float t = f + 12582912.0f;
    return *reinterpret_cast<int32_t*>(&t) - 0x4b400000;
}

static inline cSC4CrimeSimulator* Primary4_ab0dc8(void* sub)
{
    return reinterpret_cast<cSC4CrimeSimulator*>(static_cast<char*>(sub) - 4);
}

// FUNCTION: 0x006a21c0
bool cSC4CrimeSimulator_4::Slot03_ab0dc8_4(void* arg)
{
    Sub4_ab0dc8& self = *reinterpret_cast<Sub4_ab0dc8*>(this);
    Message_ab0dc8* msg = static_cast<Message_ab0dc8*>(arg);
    uint32_t type = msg->Fn04_ab0dc8();
    switch (type) {
    case 0x66956814:
        Primary4_ab0dc8(this)->Fn006a1fd0(5);
        return true;
    case 0x66956816:
        if (self.mbState90 == 6) {
            self.mbState90 = 0;
        }
        return true;
    case 0x6695681a:
        Primary4_ab0dc8(this)->Fn006a1fd0(msg->Fn19_ab0dc8());
        return true;
    case 0x99ef1142:
    case 0x99ef1143: {
        Picked_ab0dc8* picked = msg->Fn10_ab0dc8();
        if (!picked->Fn06_ab0dc8()->Fn03_ab0dc8(0x029244db)) {
            Primary4_ab0dc8(this)->Fn0069f260(picked, type == 0x99ef1142);
        }
        return true;
    }
    case 0xc2c09554:
        self.mf8c = reinterpret_cast<Source_ab0dc8*>(self.mpObj54)->Fn25_ab0dc8(0x28ed0380, 0);
        return true;
    case 0xc53d10aa: {
        uint32_t what = msg->Fn09_ab0dc8();
        uint32_t extra = msg->Fn14_ab0dc8();
        if (what == 0xe7e2c2db) {
            if (extra == 0xc8e8f6c5) {
                Primary4_ab0dc8(this)->Fn006a07a0();
            }
        } else if (what == 0xea12f32c) {
            Fn006a1450();
        }
        return true;
    }
    }
    return true;
}

// FUNCTION: 0x006a1860
bool cSC4CrimeSimulator::Shutdown()
{
    View_ab0dc8* self = reinterpret_cast<View_ab0dc8*>(this);
    if (self->mbInitialized) {
        self->mbInitialized = 0;
        if (self->mpGrid5c) {
            static_cast<cUnk00a878c0_0*>(static_cast<cUnk00a878c0*>(self->mpGrid5c))->Slot04_a878c0();
            static_cast<cUnk00a878c0_0*>(static_cast<cUnk00a878c0*>(self->mpGrid5c))->Release();
            self->mpGrid5c = 0;
        }
        if (self->mpGrid60) {
            static_cast<cUnk00a878c0_0*>(static_cast<cUnk00a878c0*>(self->mpGrid60))->Slot04_a878c0();
            static_cast<cUnk00a878c0_0*>(static_cast<cUnk00a878c0*>(self->mpGrid60))->Release();
            self->mpGrid60 = 0;
        }
        if (self->mpObj58) {
            static_cast<Com_ab0dc8*>(self->mpObj58)->Release();
            self->mpObj58 = 0;
        }
        if (self->mpObj54) {
            static_cast<Com_ab0dc8*>(self->mpObj54)->Release();
            self->mpObj54 = 0;
        }
        if (self->mpObj50) {
            static_cast<Com_ab0dc8*>(self->mpObj50)->Release();
            self->mpObj50 = 0;
        }
        if (self->mpApp48) {
            static_cast<Com_ab0dc8*>(self->mpApp48)->Release();
            self->mpApp48 = 0;
        }
        Fn006a1530();
        if (self->mpRegistry4c) {
            void* sub = reinterpret_cast<char*>(this) + 4;
            static_cast<Registry_ab0dc8*>(self->mpRegistry4c)->Fn06_ab0dc8(sub, 0xc2c09554);
            static_cast<Registry_ab0dc8*>(self->mpRegistry4c)->Fn06_ab0dc8(sub, 0xc53d10aa);
            static_cast<Registry_ab0dc8*>(self->mpRegistry4c)->Fn06_ab0dc8(sub, 0x99ef1142);
            static_cast<Registry_ab0dc8*>(self->mpRegistry4c)->Fn06_ab0dc8(sub, 0x99ef1143);
            static_cast<Registry_ab0dc8*>(self->mpRegistry4c)->Release();
            self->mpRegistry4c = 0;
        }
        Listener_ab0dc8* listener = gpB43cec->Fn50_ab0dc8();
        if (listener) {
            listener->Fn20_ab0dc8(reinterpret_cast<char*>(this) + 4);
        }
    }
    return true;
}

// The same data seen from the subobject at +0xc (offsets are the object's minus 0xc).
struct SubC_ab0dc8 {
    uint8_t mPad0[5];
    uint8_t mbFlag11;
    uint8_t mPad6[6];
    uint8_t mRegion18[0x30];
    uint8_t mPad3c[0x14];
    void* mpGrid5c;
    void* mpGrid60;
    uint32_t mn64;
    uint32_t mn68;
    float mf6c;
    Vec_ab0dc8 mItems;
    uint32_t mn7c;
    int32_t mn80;
    int32_t mn84;
    int32_t mn88;
    float mf8c;
};

// An entry of the list at +0x70: a record the stream saves and loads.
struct Entry_ab0dc8 {
    Com_ab0dc8* mpObject;   // 0x0
    uint32_t mnId;          // 0x4
    uint32_t mnTable8;      // 0x8: the name string's vtable pointer
    uint8_t* mpTextBegin;   // 0xc
    uint8_t* mpTextEnd;     // 0x10
    uint8_t* mpTextCap;     // 0x14
    uint32_t mnTextRefs;    // 0x18
    uint32_t mn1c;          // 0x1c
    uint32_t mn20;          // 0x20
    uint32_t mn24;          // 0x24
    bool mbFlag28;          // 0x28 (the flag the item methods read)
};

// The stream a save or load goes through.
struct Stream_ab0dc8 {
    virtual void Pad00_ab0dc8(); virtual void Pad01_ab0dc8(); virtual void Pad02_ab0dc8(); virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8(); virtual void Pad05_ab0dc8(); virtual void Pad06_ab0dc8();
    virtual void Fn07_ab0dc8(uint32_t);
    virtual void Fn08_ab0dc8(uint32_t);
    virtual void Fn09_ab0dc8(uint32_t);
    virtual void Pad10_ab0dc8(); virtual void Pad11_ab0dc8();
    virtual void Fn12_ab0dc8(float);
    virtual void Pad13_ab0dc8(); virtual void Pad14_ab0dc8();
    virtual void Fn15_ab0dc8(void*);
    virtual void Pad16_ab0dc8(); virtual void Pad17_ab0dc8();
    virtual bool Fn18_ab0dc8();
};

// STUB: 0x005d99a0
void Fn005d99a0(Stream_ab0dc8* stream, void* value);
// STUB: 0x005dab70
void Fn005dab70(Stream_ab0dc8* stream, void* region);
// STUB: 0x005da0a0
void Fn005da0a0(Stream_ab0dc8* stream, void* data);

// FUNCTION: 0x0069f600
uint32_t cSC4CrimeSimulator_c::Write(void* arg)
{
    SubC_ab0dc8* self = reinterpret_cast<SubC_ab0dc8*>(this);
    Stream_ab0dc8* s = static_cast<Stream_ab0dc8*>(arg);
    s->Fn07_ab0dc8(6);
    Fn005d99a0(s, self->mpGrid5c);
    Fn005d99a0(s, self->mpGrid60);
    Fn005dab70(s, self->mRegion18);
    s->Fn09_ab0dc8(self->mn64);
    s->Fn09_ab0dc8(self->mn68);
    s->Fn12_ab0dc8(self->mf6c);
    s->Fn12_ab0dc8(self->mf8c);
    s->Fn09_ab0dc8(self->mn7c);
    s->Fn08_ab0dc8(self->mn80);
    s->Fn08_ab0dc8(self->mn84);
    s->Fn08_ab0dc8(self->mn88);
    s->Fn08_ab0dc8(self->mItems.size());
    for (uint32_t i = 0; i < self->mItems.size(); ++i) {
        Entry_ab0dc8* e = static_cast<Entry_ab0dc8*>(self->mItems[i]);
        if (e) {
            Fn005d99a0(s, e->mpObject);
            s->Fn09_ab0dc8(e->mnId);
            s->Fn15_ab0dc8(&e->mnTable8);
            Fn005da0a0(s, &e->mn1c);
        }
    }
    return !s->Fn18_ab0dc8();
}

// The stream a load goes through.
struct Reader_ab0dc8 {
    virtual void Pad00_ab0dc8(); virtual void Pad01_ab0dc8(); virtual void Pad02_ab0dc8(); virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8(); virtual void Pad05_ab0dc8(); virtual void Pad06_ab0dc8();
    virtual void Fn07_ab0dc8(uint16_t*);
    virtual void Fn08_ab0dc8(void*);
    virtual void Fn09_ab0dc8(void*);
    virtual void Pad10_ab0dc8(); virtual void Pad11_ab0dc8();
    virtual void Fn12_ab0dc8(void*);
    virtual void Pad13_ab0dc8(); virtual void Pad14_ab0dc8();
    virtual void Fn15_ab0dc8(void*);
    virtual void Pad16_ab0dc8(); virtual void Pad17_ab0dc8();
    virtual bool Fn18_ab0dc8();
};

// STUB: 0x005d9730
void Fn005d9730(Reader_ab0dc8* stream, uint32_t id, void* object, uint32_t flags);
// STUB: 0x005db280
void Fn005db280(Reader_ab0dc8* stream, void* region);
// STUB: 0x005da070
void Fn005da070(Reader_ab0dc8* stream, void* data);
// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

#ifdef OB_DRAFTS
// CLOSE: 0x006a05e0 score 154 (register allocation: the original keeps this in ebp and the new entry in edi)
bool cSC4CrimeSimulator_c::Read(void* arg)
{
    Reader_ab0dc8* s = static_cast<Reader_ab0dc8*>(arg);
    SubC_ab0dc8* self = reinterpret_cast<SubC_ab0dc8*>(this);
    uint16_t kind;
    s->Fn07_ab0dc8(&kind);
    if (kind != 6) {
        return false;
    }
    Fn005d9730(s, 0xc9bd939a, &self->mpGrid5c, 0);
    Fn005d9730(s, 0xc9bd939a, &self->mpGrid60, 0);
    Fn005db280(s, self->mRegion18);
    s->Fn09_ab0dc8(&self->mn64);
    s->Fn09_ab0dc8(&self->mn68);
    s->Fn12_ab0dc8(&self->mf6c);
    s->Fn12_ab0dc8(&self->mf8c);
    s->Fn09_ab0dc8(&self->mn7c);
    s->Fn08_ab0dc8(&self->mn80);
    s->Fn08_ab0dc8(&self->mn84);
    s->Fn08_ab0dc8(&self->mn88);
    int32_t count;
    s->Fn08_ab0dc8(&count);
    for (int32_t i = 0; i < count; ++i) {
        Entry_ab0dc8* e = new Entry_ab0dc8;
        if (e) {
            e->mpObject = 0;
            e->mpTextBegin = 0;
            e->mpTextEnd = 0;
            e->mpTextCap = 0;
            uint8_t* text = static_cast<uint8_t*>(Fn0090cf54(8));
            e->mpTextBegin = text;
            e->mpTextEnd = text;
            e->mpTextCap = text + 8;
            *text = 0;
            e->mnTable8 = 0x00a80810;
            e->mnTextRefs = 0;
            e->mn1c = 0;
            e->mn20 = 0;
            e->mn24 = 0;
        }
        if (e->mpObject) {
            Com_ab0dc8* old = e->mpObject;
            e->mpObject = 0;
            old->Release();
        }
        Fn005d9730(s, 0xe818fced, e, 0);
        s->Fn09_ab0dc8(&e->mnId);
        s->Fn15_ab0dc8(&e->mnTable8);
        Fn005da070(s, &e->mn1c);
        e->mbFlag28 = false;
        if (self->mItems.mpEnd == self->mItems.mpCap) {
            Entry_ab0dc8* item = e;
            self->mItems.Fn0051ca60(self->mItems.mpEnd, reinterpret_cast<void**>(&item), reinterpret_cast<void**>(&item), 1, 1);
        } else {
            if (self->mItems.mpEnd) {
                *self->mItems.mpEnd = e;
            }
            self->mItems.mpEnd += 1;
        }
    }
    self->mbFlag11 = 1;
    return !s->Fn18_ab0dc8();
}
#endif

// The object an entry holds: slot 15 reports its position.
struct Located_ab0dc8 {
    virtual void Pad00_ab0dc8(); virtual void Pad01_ab0dc8(); virtual void Pad02_ab0dc8(); virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8(); virtual void Pad05_ab0dc8(); virtual void Pad06_ab0dc8(); virtual void Pad07_ab0dc8();
    virtual void Pad08_ab0dc8(); virtual void Pad09_ab0dc8(); virtual void Pad10_ab0dc8(); virtual void Pad11_ab0dc8();
    virtual void Pad12_ab0dc8(); virtual void Pad13_ab0dc8(); virtual void Pad14_ab0dc8();
    virtual void Fn15_ab0dc8(void* position);
};

// One record of the list Slot11 fills.
struct Record_ab0dc8 {
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnId;
    bool mbFlag;
    uint32_t mn10;
    uint32_t mn14;
    uint32_t mn18;
};

struct Records_ab0dc8 {
    char* mpBegin;
    // STUB: 0x006a1380
    void Fn006a1380(int32_t count, Record_ab0dc8* fill);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006a1960 score 6 (only the base/index order of three addresses; the original adds an integer base)
bool cSC4CrimeSimulator::GetCrimeIncidentArray(void* arg)
{
    View_ab0dc8* self = reinterpret_cast<View_ab0dc8*>(this);
    Records_ab0dc8* out = static_cast<Records_ab0dc8*>(arg);
    cB43cec_ab0dc8* app = gpB43cec;
    int32_t n = self->mItems.size();
    Record_ab0dc8 tmp;
    tmp.mn10 = 0;
    tmp.mn14 = 0;
    tmp.mn18 = 0;
    out->Fn006a1380(n, &tmp);
    for (int32_t i = 0, off = 0; i < n; ++i, off += sizeof(Record_ab0dc8)) {
        Entry_ab0dc8* e = static_cast<Entry_ab0dc8*>(self->mItems[i]);
        if (e && e->mpObject) {
            uint32_t pos[3];
            static_cast<Located_ab0dc8*>(static_cast<void*>(e->mpObject))->Fn15_ab0dc8(pos);
            app->Fn95_ab0dc8(pos[0], pos[2], out->mpBegin + off, out->mpBegin + off + 4);
            uint32_t* v = reinterpret_cast<uint32_t*>(off + 0x10 + out->mpBegin);
            v[0] = e->mn1c;
            v[1] = e->mn20;
            v[2] = e->mn24;
            *reinterpret_cast<uint32_t*>(off + 8 + out->mpBegin) = e->mnId;
            *reinterpret_cast<bool*>(off + 0xc + out->mpBegin) = e->mbFlag28;
        }
    }
    return n > 0;
}
#endif

// STUB: 0x006a13e0
void Fn006a13e0();

// The object at 0x00b43c94: slot 69 installs a callback.
struct cB43c94_ab0dc8 {
    virtual void Pad00_ab0dc8();
    virtual void Pad01_ab0dc8();
    virtual void Pad02_ab0dc8();
    virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8();
    virtual void Pad05_ab0dc8();
    virtual void Pad06_ab0dc8();
    virtual void Pad07_ab0dc8();
    virtual void Pad08_ab0dc8();
    virtual void Pad09_ab0dc8();
    virtual void Pad10_ab0dc8();
    virtual void Pad11_ab0dc8();
    virtual void Pad12_ab0dc8();
    virtual void Pad13_ab0dc8();
    virtual void Pad14_ab0dc8();
    virtual void Pad15_ab0dc8();
    virtual void Pad16_ab0dc8();
    virtual void Pad17_ab0dc8();
    virtual void Pad18_ab0dc8();
    virtual void Pad19_ab0dc8();
    virtual void Pad20_ab0dc8();
    virtual void Pad21_ab0dc8();
    virtual void Pad22_ab0dc8();
    virtual void Pad23_ab0dc8();
    virtual void Pad24_ab0dc8();
    virtual void Pad25_ab0dc8();
    virtual void Pad26_ab0dc8();
    virtual void Pad27_ab0dc8();
    virtual void Pad28_ab0dc8();
    virtual void Pad29_ab0dc8();
    virtual void Pad30_ab0dc8();
    virtual void Pad31_ab0dc8();
    virtual void Pad32_ab0dc8();
    virtual void Pad33_ab0dc8();
    virtual void Pad34_ab0dc8();
    virtual void Pad35_ab0dc8();
    virtual void Pad36_ab0dc8();
    virtual void Pad37_ab0dc8();
    virtual void Pad38_ab0dc8();
    virtual void Pad39_ab0dc8();
    virtual void Pad40_ab0dc8();
    virtual void Pad41_ab0dc8();
    virtual void Pad42_ab0dc8();
    virtual void Pad43_ab0dc8();
    virtual void Pad44_ab0dc8();
    virtual void Pad45_ab0dc8();
    virtual void Pad46_ab0dc8();
    virtual void Pad47_ab0dc8();
    virtual void Pad48_ab0dc8();
    virtual void Pad49_ab0dc8();
    virtual void Pad50_ab0dc8();
    virtual void Pad51_ab0dc8();
    virtual void Pad52_ab0dc8();
    virtual void Pad53_ab0dc8();
    virtual void Pad54_ab0dc8();
    virtual void Pad55_ab0dc8();
    virtual void Pad56_ab0dc8();
    virtual void Pad57_ab0dc8();
    virtual void Pad58_ab0dc8();
    virtual void Pad59_ab0dc8();
    virtual void Pad60_ab0dc8();
    virtual void Pad61_ab0dc8();
    virtual void Pad62_ab0dc8();
    virtual void Pad63_ab0dc8();
    virtual void Pad64_ab0dc8();
    virtual void Pad65_ab0dc8();
    virtual void Pad66_ab0dc8();
    virtual void Pad67_ab0dc8();
    virtual void Pad68_ab0dc8();
    virtual void Fn69_ab0dc8(void (*callback)(), uint32_t flags);
};
// GLOBAL: 0x00b43c94
extern cB43c94_ab0dc8* gpB43c94;

// The object at 0x00b43d5c: slot 19 attaches a name to an object.
struct cB43d5c_ab0dc8 {
    virtual void Pad00_ab0dc8();
    virtual void Pad01_ab0dc8();
    virtual void Pad02_ab0dc8();
    virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8();
    virtual void Pad05_ab0dc8();
    virtual void Pad06_ab0dc8();
    virtual void Pad07_ab0dc8();
    virtual void Pad08_ab0dc8();
    virtual void Pad09_ab0dc8();
    virtual void Pad10_ab0dc8();
    virtual void Pad11_ab0dc8();
    virtual void Pad12_ab0dc8();
    virtual void Pad13_ab0dc8();
    virtual void Pad14_ab0dc8();
    virtual void Pad15_ab0dc8();
    virtual void Pad16_ab0dc8();
    virtual void Pad17_ab0dc8();
    virtual void Pad18_ab0dc8();
    virtual void Fn19_ab0dc8(void* object, uint32_t kind, const cRZString* name, uint32_t flags);
};
// GLOBAL: 0x00b43d5c
extern cB43d5c_ab0dc8* gpB43d5c;

// The object at 0x00b43db8: slot 5 announces an object.
struct cB43db8_ab0dc8 {
    virtual void Pad00_ab0dc8();
    virtual void Pad01_ab0dc8();
    virtual void Pad02_ab0dc8();
    virtual void Pad03_ab0dc8();
    virtual void Pad04_ab0dc8();
    virtual void Fn05_ab0dc8(void* object);
};
// GLOBAL: 0x00b43db8
extern cB43db8_ab0dc8* gpB43db8;

// GLOBAL: 0x00b43ccc
extern Registry_ab0dc8* gpB43ccc;
// GLOBAL: 0x00b43d90
extern Com_ab0dc8* gpB43d90;
// GLOBAL: 0x00b43d98
extern Com_ab0dc8* gpB43d98;
// GLOBAL: 0x00b48618
extern bool gB48618;

// The region at +0x18.
struct Region_ab0dc8 {
    // STUB: 0x0049c820
    void Fn0049c820(const int32_t* rect);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006a15b0 score 139 (needs the inline constructor of cUnk00a878c0; register order of the global loads)
bool cSC4CrimeSimulator::Init()
{
    View_ab0dc8* self = reinterpret_cast<View_ab0dc8*>(this);
    if (!self->mbInitialized) {
        self->mbInitialized = 1;
        if (!gB48618) {
            gB48618 = true;
            gpB43c94->Fn69_ab0dc8(Fn006a13e0, 0);
            Fn006a1450();
        }
        Fn006a07a0();
        cB43d5c_ab0dc8* namer = gpB43d5c;
        cRZString name("cSC4CrimeSimulator");
        void* sub = reinterpret_cast<char*>(this) + 4;
        namer->Fn19_ab0dc8(sub, 4, &name, 2);
        namer->Fn19_ab0dc8(sub, 6, &name, 2);
        namer->Fn19_ab0dc8(sub, 10, &name, 2);
        if (self->mpRegistry4c == 0) {
            Registry_ab0dc8* registry = gpB43ccc;
            self->mpRegistry4c = registry;
            registry->AddRef();
            static_cast<Registry_ab0dc8*>(self->mpRegistry4c)->Fn05_ab0dc8(sub, 0x99ef1142);
            static_cast<Registry_ab0dc8*>(self->mpRegistry4c)->Fn05_ab0dc8(sub, 0x99ef1143);
            static_cast<Registry_ab0dc8*>(self->mpRegistry4c)->Fn05_ab0dc8(sub, 0xc2c09554);
            static_cast<Registry_ab0dc8*>(self->mpRegistry4c)->Fn05_ab0dc8(sub, 0xc53d10aa);
        }
        if (self->mpApp48 == 0) {
            cB43cec_ab0dc8* app = gpB43cec;
            self->mpApp48 = app;
            app->AddRef();
        }
        if (self->mpObj50 == 0) {
            Com_ab0dc8* c = static_cast<cB43cec_ab0dc8*>(self->mpApp48)->Fn34_ab0dc8();
            self->mpObj50 = c;
            c->AddRef();
        }
        if (self->mpObj54 == 0) {
            Com_ab0dc8* c = gpB43d90;
            self->mpObj54 = c;
            c->AddRef();
        }
        if (self->mpObj58 == 0) {
            Com_ab0dc8* c = gpB43d98;
            self->mpObj58 = c;
            c->AddRef();
        }
        if (self->mpGrid5c == 0) {
            cUnk00a878c0* grid = new cUnk00a878c0;
            if (grid) {
                grid->mbDirty = false;
                grid->mnRefCount = 0;
                grid->mnUnk10 = 0x49b9e602;
                grid->mnCellSize = 0;
                reinterpret_cast<uint32_t*>(grid->field38)[0] = 0;
                reinterpret_cast<uint32_t*>(grid->field38)[1] = 0;
                reinterpret_cast<uint32_t*>(grid->field38)[2] = 0;
            }
            self->mpGrid5c = grid;
            grid->AddRef();
            static_cast<cUnk00a878c0*>(self->mpGrid5c)->Slot03_a878c0();
            static_cast<cUnk00a878c0*>(self->mpGrid5c)->Slot09_a878c0(self->mnD8);
            static_cast<cUnk00a878c0*>(self->mpGrid5c)->Slot06_a878c0(0x89d5b895);
            static_cast<cUnk00a878c0*>(self->mpGrid5c)->Slot27_a878c0(0);
        }
        if (self->mpGrid60 == 0) {
            cUnk00a878c0* grid = new cUnk00a878c0;
            if (grid) {
                grid->mbDirty = false;
                grid->mnRefCount = 0;
                grid->mnUnk10 = 0x49b9e602;
                grid->mnCellSize = 0;
                reinterpret_cast<uint32_t*>(grid->field38)[0] = 0;
                reinterpret_cast<uint32_t*>(grid->field38)[1] = 0;
                reinterpret_cast<uint32_t*>(grid->field38)[2] = 0;
            }
            self->mpGrid60 = grid;
            grid->AddRef();
            static_cast<cUnk00a878c0*>(self->mpGrid60)->Slot03_a878c0();
            static_cast<cUnk00a878c0*>(self->mpGrid60)->Slot09_a878c0(self->mnD8);
            static_cast<cUnk00a878c0*>(self->mpGrid60)->Slot06_a878c0(0x2a5ba1b3);
            static_cast<cUnk00a878c0*>(self->mpGrid60)->Slot27_a878c0(0);
        }
        if (self->mbFlag11 == 0) {
            int32_t height = static_cast<cUnk00a878c0*>(self->mpGrid5c)->Slot13_a878c0() - 1;
            int32_t rect[4];
            rect[0] = 0;
            rect[1] = 0;
            rect[2] = static_cast<cUnk00a878c0*>(self->mpGrid5c)->Slot12_a878c0() - 1;
            rect[3] = height;
            reinterpret_cast<Region_ab0dc8*>(self->mRegion18)->Fn0049c820(rect);
            gpB43db8->Fn05_ab0dc8(reinterpret_cast<char*>(this) + 8);
        }
        self->mn80 = 0;
        self->mn84 = 0;
        self->mn88 = 0;
        self->mf8c = 1.0f;
    }
    return true;
}
#endif
