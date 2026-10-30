#include "classes/cUnk00adbbf0.h"
#include "gzcom/RZTextEncoding.h"
#include "gzcom/cRZString.h"

#include <string>
#include <vector>

// The text-input window's helper objects, seen through the slots this class calls (arguments as the original passes them).

// The base window's own functions (called with the window subobject at +8 as this).
struct Win_adbbf0 {
    // STUB: 0x0099bc31
    bool Fn0099bc31();
    // STUB: 0x0099bdfe
    bool Fn0099bdfe();
    // STUB: 0x0099be0a
    bool Fn0099be0a();
    // STUB: 0x0099be1e
    void Fn0099be1e();
    // STUB: 0x009bd399
    bool Fn009bd399(void* p);
};

// The primary vtable with the argument types the calls here use (the base class declares fewer).
struct Prim_adbbf0 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03();
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07(void* p);
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13();
    virtual void Fn14();
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18();
    virtual void Fn19(uint32_t a);
    virtual void Fn20();
    virtual void Fn21();
    virtual void Fn22();
    virtual void Fn23();
    virtual void Fn24();
    virtual void Fn25();
    virtual void Fn26();
    virtual void Fn27();
    virtual void Fn28();
    virtual void Fn29();
    virtual void Fn30();
    virtual void Fn31();
    virtual void Fn32();
    virtual void Fn33();
};

// The text-edit interface at +0xe0 with typed arguments.
struct Edit_adbbf0 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03();
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07();
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12(uint32_t index, uint32_t value);
    virtual void Fn13();
    virtual void Fn14(uint32_t index, uint32_t* pValue);
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18();
    virtual void Fn19();
    virtual void Fn20();
    virtual void Fn21();
    virtual uint32_t Fn22();
    virtual void Fn23();
    virtual void Fn24();
    virtual void Fn25();
    virtual void Fn26();
    virtual void Fn27();
    virtual void Fn28();
    virtual void Fn29();
    virtual void Fn30();
    virtual void Fn31();
    virtual void Fn32();
    virtual void Fn33();
    virtual void Fn34();
    virtual void Fn35();
    virtual void Fn36();
    virtual void Fn37();
    virtual void Fn38();
    virtual void Fn39();
    virtual void Fn40();
    virtual void Fn41();
    virtual void Fn42();
    virtual void Fn43();
    virtual void Fn44();
    virtual void Fn45();
    virtual void Fn46();
    virtual void Fn47();
    virtual void Fn48(void* pString, uint32_t flags);
    virtual void Fn49();
    virtual void Fn50();
    virtual void Fn51();
    virtual void Fn52();
    virtual void Fn53();
    virtual void Fn54();
    virtual void Fn55();
    virtual void Fn56();
    virtual void Fn57();
    virtual void Fn58();
    virtual void Fn59();
    virtual void Fn60(int32_t a, int32_t b, int32_t* pX, int32_t* pY);
    virtual void Fn61(int32_t* pA, int32_t* pB, int32_t position);
};

// The font the window measures text with.
struct Font_adbbf0 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03();
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07();
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13();
    virtual void Fn14();
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18();
    virtual void Fn19();
    virtual void Fn20();
    virtual void Fn21();
    virtual void Fn22();
    virtual void Fn23();
    virtual void Fn24();
    virtual void Fn25();
    virtual void Fn26();
    virtual void Fn27();
    virtual void Fn28();
    virtual void Fn29();
    virtual void Fn30();
    virtual void Fn31();
    virtual void Fn32();
    virtual void Fn33();
    virtual void Fn34();
    virtual void Fn35();
    virtual void Fn36();
    virtual uint32_t Fn37(uint32_t a, uint32_t b);
    virtual uint32_t Fn38();
    virtual void Fn39();
    virtual int32_t Fn40(const char* text, int32_t length);
    virtual void Fn41();
    virtual void Fn42();
    virtual void Fn43();
    virtual void Fn44();
    virtual void Fn45();
    virtual void Fn46();
    virtual void Fn47();
    virtual int32_t Fn48(const char* text, int32_t length);
};

// The surface the underline is drawn on.
struct Canvas_adbbf0 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03();
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07();
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13();
    virtual void Fn14();
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18();
    virtual void Fn19();
    virtual void Fn20();
    virtual void Fn21(uint32_t color);
    virtual void Fn22();
    virtual void Fn23();
    virtual void Fn24();
    virtual void Fn25();
    virtual void Fn26();
    virtual void Fn27();
    virtual void Fn28();
    virtual void Fn29();
    virtual void Fn30();
    virtual void Fn31();
    virtual void Fn32();
    virtual void Fn33();
    virtual void Fn34(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
};

// The window manager the parent hands out (slots 36 and 37 of the parent).
struct Owner_adbbf0 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03();
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07();
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13();
    virtual void Fn14();
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18();
    virtual void Fn19();
    virtual void Fn20();
    virtual void Fn21();
    virtual void Fn22();
    virtual void Fn23();
    virtual void Fn24();
    virtual void Fn25();
    virtual void Fn26();
    virtual void Fn27();
    virtual void Fn28();
    virtual void Fn29();
    virtual void Fn30();
    virtual void Fn31();
    virtual void Fn32();
    virtual void Fn33();
    virtual void Fn34();
    virtual void Fn35();
    virtual void* Fn36();
    virtual void Fn37(void* p);
};

// The first counted object (slot 3 takes a message): the input manager.
struct Mgr_adbbf0 {
    virtual bool QueryInterface(uint32_t iid, void* ppOut);
    virtual void AddRef();
    virtual void Release();
    virtual bool Fn03(void* msg);
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07();
    virtual void Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13();
    virtual void Fn14();
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18();
    virtual void Fn19();
    virtual void Fn20();
    virtual void Fn21();
    virtual void Fn22();
    virtual void Fn23();
    virtual void Fn24();
    virtual void Fn25();
    virtual void Fn26();
    virtual void Fn27();
    virtual void Fn28();
    virtual void Fn29();
    virtual void Fn30();
    virtual void Fn31();
    virtual void Fn32();
    virtual void Fn33();
    virtual void Fn34();
    virtual void Fn35();
    virtual void Fn36();
    virtual void Fn37();
    virtual void Fn38();
    virtual void Fn39();
    virtual void Fn40();
    virtual int32_t Fn41();
    virtual int32_t Fn42();
    virtual void Fn43();
    virtual void Fn44();
    virtual void Fn45();
    virtual void Fn46();
    virtual void Fn47();
    virtual void Fn48();
    virtual void Fn49();
    virtual void Fn50();
    virtual void Fn51();
    virtual void Fn52();
    virtual void Fn53();
    virtual void Fn54();
    virtual void Fn55();
    virtual void Fn56();
    virtual void Fn57();
    virtual void Fn58();
    virtual void Fn59();
    virtual void Fn60();
    virtual void Fn61(uint32_t a, int32_t* pB, int32_t* pC);
    virtual void Fn62();
    virtual void Fn63();
    virtual void Fn64();
    virtual void Fn65();
    virtual void Fn66();
    virtual void Fn67();
    virtual void Fn68();
    virtual void Fn69();
    virtual void Fn70();
    virtual void Fn71();
    virtual void Fn72();
    virtual void Fn73();
    virtual void Fn74();
    virtual void Fn75();
    virtual void Fn76();
    virtual void Fn77();
    virtual void Fn78();
    virtual void Fn79();
    virtual void Fn80();
    virtual void Fn81();
    virtual void Fn82();
    virtual void Fn83();
    virtual void Fn84();
    virtual void Fn85();
    virtual void Fn86();
    virtual void Fn87();
    virtual void Fn88();
    virtual void Fn89();
    virtual void Fn90();
    virtual void Fn91();
    virtual void Fn92();
    virtual void Fn93();
    virtual void Fn94();
    virtual void Fn95();
    virtual void Fn96();
    virtual void Fn97();
    virtual void Fn98();
    virtual void Fn99();
    virtual void Fn100();
    virtual void Fn101();
    virtual void Fn102();
    virtual uint32_t Fn103();
};

// The second counted object: the colour source.
struct Palette_adbbf0 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03();
    virtual void Fn04();
    virtual void Fn05();
    virtual void Fn06();
    virtual void Fn07();
    virtual void* Fn08();
    virtual void Fn09();
    virtual void Fn10();
    virtual void Fn11();
    virtual void Fn12();
    virtual void Fn13();
    virtual void Fn14(uint32_t index, uint32_t* pColor);
    virtual void Fn15();
    virtual void Fn16();
    virtual void Fn17();
    virtual void Fn18();
    virtual void Fn19();
    virtual void Fn20();
    virtual void Fn21();
    virtual void Fn22();
    virtual void Fn23();
    virtual void Fn24();
    virtual void Fn25();
    virtual void Fn26();
    virtual void Fn27();
    virtual void Fn28();
    virtual void Fn29();
    virtual void Fn30();
    virtual void Fn31();
    virtual void Fn32();
    virtual void Fn33();
    virtual void Fn34();
    virtual void Fn35();
    virtual void Fn36();
    virtual void Fn37();
    virtual void Fn38();
    virtual void Fn39();
    virtual void Fn40();
    virtual void Fn41();
    virtual void Fn42();
    virtual void Fn43();
    virtual void Fn44();
    virtual void Fn45();
    virtual void Fn46();
    virtual void Fn47();
    virtual void Fn48();
    virtual void Fn49();
    virtual void Fn50();
    virtual void Fn51();
    virtual void Fn52();
    virtual void Fn53();
    virtual void Fn54();
    virtual void Fn55();
    virtual void Fn56();
    virtual void Fn57();
    virtual void Fn58();
    virtual void Fn59();
    virtual void Fn60(int32_t a, int32_t b, int32_t* pW, int32_t* pH);
    virtual void Fn61();
    virtual void Fn62();
    virtual void Fn63();
    virtual void Fn64();
    virtual void Fn65();
    virtual void Fn66();
    virtual void Fn67();
    virtual void Fn68();
    virtual void Fn69(int32_t* pA, int32_t* pB);
};

// The smart pointer members at +0x2bc and +0x2c0: assignment and address-of are out-of-line functions.
struct Slot_adbbf0 {
    void* mp;
    // STUB: 0x005447b0
    void Assign(void* p);
};

struct OutRef_adbbf0 {
    void* mp;
    // STUB: 0x004f20a0
    void** operator&();
};

// The service object looked up by the first holder (slot 5 answers an interface id).
struct Factory_adbbf0 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03();
    virtual void Fn04();
    virtual void* Fn05(uint32_t iid);
};

struct HolderA_adbbf0 {
    Factory_adbbf0* mp;
    HolderA_adbbf0() { Init(); }
    ~HolderA_adbbf0() { Done(); }
    // STUB: 0x007b2480
    void Init();
    // STUB: 0x007b24b0
    void Done();
};

// The notifier the second holder gives (slot 5 registers a window for a message, slot 6 removes it).
struct Notifier_adbbf0 {
    virtual void Fn00();
    virtual void Fn01();
    virtual void Fn02();
    virtual void Fn03();
    virtual void Fn04();
    virtual void Fn05(void* window, uint32_t id);
    virtual void Fn06(void* window, uint32_t id);
};

struct HolderB_adbbf0 {
    Notifier_adbbf0* mp;
    HolderB_adbbf0() { Init(); }
    ~HolderB_adbbf0() { Done(); }
    // STUB: 0x004d7bb0
    void Init();
    // STUB: 0x004d7b60
    void Done();
};

// The message the window gets and the record it carries.
struct MsgData_adbbf0 {
    char mUnused[0x10];
    int32_t mnMode;
};

struct Msg_adbbf0 {
    uint32_t mnType;
    MsgData_adbbf0* mpData;
};

// The composition record: text, per-character attributes, their count and the cursor position.
struct Comp_adbbf0 {
    const uint16_t* mpString;
    const uint8_t* mpAttrs;
    uint32_t mnCount;
    uint32_t mnCursor;
};

// The attribute vector at +0x2c8 (begin, end, capacity), its resize an out-of-line function.
struct Bytes_adbbf0 {
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    uint8_t* mpCap;
    // STUB: 0x00478aa0
    void Resize(uint32_t n);
    uint8_t& operator[](uint32_t i) { return mpBegin[i]; }
};

// The text buffer at +0xe8 (begin, end, capacity).
struct Text_adbbf0 {
    const char* mpBegin;
    const char* mpEnd;
    const char* mpCap;
    uint32_t size() const
    {
        return mpEnd - mpBegin;
    }
};

struct MgrRef_adbbf0 {
    Mgr_adbbf0* mp;
    Mgr_adbbf0* operator->() const
    {
        return mp;
    }
};

inline Mgr_adbbf0* MgrOf_adbbf0(cUnk00adbbf0* p)
{
    return static_cast<Mgr_adbbf0*>(p->mpManager);
}

inline Palette_adbbf0* PaletteOf_adbbf0(cUnk00adbbf0* p)
{
    return static_cast<Palette_adbbf0*>(p->mpColors);
}

struct Point_adbbf0 {
    int32_t x;
    int32_t y;
};

struct Rect_adbbf0 {
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
};

inline Prim_adbbf0* Prim_adbbf0_Of(cUnk00adbbf0* p)
{
    return reinterpret_cast<Prim_adbbf0*>(p);
}

inline Win_adbbf0* WinOf_adbbf0(cUnk00adbbf0* p)
{
    return reinterpret_cast<Win_adbbf0*>(reinterpret_cast<char*>(p) + 8);
}

inline Edit_adbbf0* EditOf_adbbf0(cUnk00adbbf0* p)
{
    return reinterpret_cast<Edit_adbbf0*>(reinterpret_cast<char*>(p) + 0xe0);
}

inline Font_adbbf0* FontOf_adbbf0(cUnk00adbbf0* p)
{
    return *reinterpret_cast<Font_adbbf0**>(reinterpret_cast<char*>(p) + 0x1a8);
}

// The text's std::string (inside the base's cRZString mText, 4 bytes in, at +0xe0) seen as the begin/end/capacity
// record. Plain pointer arithmetic: an upcast to the string base makes the compiler null-check the address.
#define TEXT_adbbf0(p) reinterpret_cast<Text_adbbf0*>(reinterpret_cast<char*>(&(p)->mText) + 4)

inline const char* TextBegin_adbbf0(cUnk00adbbf0* p)
{
    return TEXT_adbbf0(p)->mpBegin;
}

inline const char* TextEnd_adbbf0(cUnk00adbbf0* p)
{
    return TEXT_adbbf0(p)->mpEnd;
}

// FUNCTION: 0x0094bc5d
void* cUnk00adbbf0::Slot03_adb6a8()
{
    return static_cast<cGZWinTextEdit*>(this);
}

// FUNCTION: 0x00993686
bool cUnk00adbbf0::QueryInterface(unsigned int iid, void** ppv)
{
    if (iid == 0x2ac44a90) {
        *ppv = this;
        AddRef();
        return true;
    }
    return cGZWinTextEdit::QueryInterface(iid, ppv);
}

// FUNCTION: 0x009936ce
bool cUnk00adbbf0::Slot08_adb6a8(uint32_t id, uint32_t pOut)
{
    int32_t n = static_cast<int32_t>(id);
    if (n < 8) {
        if (n < 9) {
            return cGZWinTextEdit::Slot14_adf900(n, pOut);
        }
        *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(pOut)) = mnValues[n];
        return true;
    }
    return false;
}

// FUNCTION: 0x00993704
bool cUnk00adbbf0::Slot09_adb6a8(uint32_t id, uint32_t value)
{
    int32_t n = static_cast<int32_t>(id);
    if (n < 8) {
        if (n < 9) {
            cGZWinTextEdit::Slot12_adf900(n, value);
        }
        mnValues[n] = value;
        return true;
    }
    return false;
}

// FUNCTION: 0x00993746
void cUnk00adbbf0::Slot11_adb6a8(uint32_t a)
{
    reinterpret_cast<Win_adbbf0*>(reinterpret_cast<char*>(this) + 0xe0)->Fn009bd399(&a);
}

// FUNCTION: 0x009937bf
void cUnk00adbbf0::Slot25_adb6a8(uint32_t mask)
{
    uint32_t flags = mnFlags;
    if (!(mask & flags)) {
        Slot77_adf900(flags | mask);
    }
}

// FUNCTION: 0x009937e3
void cUnk00adbbf0::Slot26_adb6a8(uint32_t value)
{
    if (value != mnFlags) {
        uint32_t changed = mnFlags ^ value;
        mnFlags = value;
        if (WinOf_adbbf0(this)->Fn0099bc31() && (changed & 1)) {
            if (mnFlags & 1) {
                cGZWinTextEdit::Slot76_adf900(0x10);
            } else {
                cGZWinTextEdit::Slot78_adf900(0x10);
            }
        }
    }
}

// FUNCTION: 0x00993832
void cUnk00adbbf0::Slot27_adb6a8(uint32_t mask)
{
    uint32_t flags = mnFlags;
    if (mask & flags) {
        Slot77_adf900(flags & ~mask);
    }
}

// FUNCTION: 0x00993858
uint32_t cUnk00adbbf0::Slot28_adb6a8(uint32_t mask)
{
    return (mnFlags & mask) != 0;
}

// FUNCTION: 0x00994cf8
uint32_t cUnk00adbbf0::Slot24_adb6a8()
{
    return TEXT_adbbf0(this)->size();
}

// FUNCTION: 0x00994b08
void cUnk00adbbf0::Slot33_adbbf0(void* arg)
{
    Comp_adbbf0* p = static_cast<Comp_adbbf0*>(arg);
    uint32_t i = 0;
    if (p) {
        int32_t pos = 0;
        for (; i < p->mnCursor; i++) {
            Text_adbbf0* text = TEXT_adbbf0(this);
            const char* begin = text->mpBegin;
            pos += RZCharacterSize(begin + pos, (text->mpEnd - begin) - pos, kRZEncodingString);
        }
        Slot66_adf900(pos);
    }
}

// FUNCTION: 0x00993ea8
bool cUnk00adbbf0::Slot03_ae1d24()
{
    Win_adbbf0* win = WinOf_adbbf0(this);
    if (!win->Fn0099bc31()) {
        Slot68_adc8d8(0x10000, 1);
        Slot47_adda20(0xac57ece);
        Slot76_adf900(0x200);
        Slot78_adf900(0x10);
        Slot78_adf900(1);
        mbCaretVisible = true;  // +0x228
        Slot78_adf900(0x1000);
        Slot17_adb6a8(0);
        Prim_adbbf0_Of(this)->Fn19(0);
        if (FontOf_adbbf0(this) == 0) {
            HolderA_adbbf0 factory;
            if (factory.mp) {
                Prim_adbbf0_Of(this)->Fn07(factory.mp->Fn05(0x68963c4c));
            }
        }
        cGZWinTextEdit::Slot03_ae1d24();
        Owner_adbbf0* owner = reinterpret_cast<Owner_adbbf0*>(static_cast<uintptr_t>(field4));
        reinterpret_cast<Slot_adbbf0*>(&mpManager)->Assign(owner->Fn36());
        MgrRef_adbbf0* mgr = reinterpret_cast<MgrRef_adbbf0*>(&mpManager);
        if (mgr->mp) {
            (*mgr)->QueryInterface(0x231a1c57, &(*reinterpret_cast<OutRef_adbbf0*>(&mpColors)));
        }
        Slot31_adbbf0();
        Slot30_adbbf0();
        win->Fn0099bdfe();
        HolderB_adbbf0 notifier;
        if (notifier.mp) {
            notifier.mp->Fn05(win, 0x2ac44c14);
            notifier.mp->Fn05(win, 0x2ac44c1a);
            notifier.mp->Fn05(win, 0x2ac44c1b);
        }
    }
    return true;
}

// FUNCTION: 0x00994005
bool cUnk00adbbf0::Slot04_ae1d24()
{
    Win_adbbf0* win = WinOf_adbbf0(this);
    if (win->Fn0099bc31()) {
        if (win->Fn0099be0a()) {
            win->Fn0099be1e();
        }
        if (mpManager) {
            Owner_adbbf0* owner = reinterpret_cast<Owner_adbbf0*>(static_cast<uintptr_t>(field4));
            owner->Fn37(mpManager);
            reinterpret_cast<Slot_adbbf0*>(&mpManager)->Assign(0);
        }
        reinterpret_cast<Slot_adbbf0*>(&mpColors)->Assign(0);
        HolderB_adbbf0 notifier;
        if (notifier.mp) {
            notifier.mp->Fn06(win, 0x2ac44c14);
            notifier.mp->Fn06(win, 0x2ac44c1a);
            notifier.mp->Fn06(win, 0x2ac44c1b);
        }
    }
    return cGZWinTextEdit::Slot04_ae1d24();
}

// FUNCTION: 0x009940aa
bool cUnk00adbbf0::DoMessage(uint32_t message)
{
    Msg_adbbf0* msg = reinterpret_cast<Msg_adbbf0*>(static_cast<uintptr_t>(message));
    switch (msg->mnType) {
    case 4:
        if (mpManager) {
            return static_cast<Mgr_adbbf0*>(mpManager)->Fn03(msg);
        }
        break;
    case 0x2ac44c14: {
        MsgData_adbbf0* data = msg->mpData;
        Slot32_adbbf0(data);
        int32_t mode = data->mnMode;
        if (mnMode != mode) {
            mnMode = mode;
            Slot31_adbbf0();
        }
        break;
    }
    case 0x2ac44c1a:
        Slot33_adbbf0(msg->mpData);
        break;
    case 0x2ac44c1b:
        Slot30_adbbf0();
        break;
    }
    return cGZWin::DoMessage(message);
}

// FUNCTION: 0x0099412d
void cUnk00adbbf0::Slot30_adbbf0()
{
    // One frame of five words: the position pair and the size pair overlap the default pair (matches the original's frame).
    int32_t v[5];
    if (mpManager) {
        if (mpColors) {
            void* anchor = PaletteOf_adbbf0(this)->Fn08();
            if (anchor) {
                Prim_adbbf0_Of(this)->Fn07(anchor);
            }
            PaletteOf_adbbf0(this)->Fn69(&v[1], &v[2]);
            PaletteOf_adbbf0(this)->Fn60(v[1], v[2], &v[3], &v[4]);
            if (v[3] > MgrOf_adbbf0(this)->Fn41()) {
                v[3] = MgrOf_adbbf0(this)->Fn41();
            }
            if (v[4] > MgrOf_adbbf0(this)->Fn42()) {
                v[4] = MgrOf_adbbf0(this)->Fn42();
            }
            MgrOf_adbbf0(this)->Fn61(field48, &v[3], &v[4]);
            GZWinMoveTo(v[3], v[4]);
        } else {
            v[0] = 2;
            v[1] = 2;
            MgrOf_adbbf0(this)->Fn61(field48, &v[0], &v[1]);
            GZWinMoveTo(v[0], v[1]);
        }
    } else {
        GZWinMoveTo(2, 2);
    }
    Slot20_adb6a8();
    if (mnMode != 0x14) {
        SetSize(GetH() + 2);
    }
}

// FUNCTION: 0x0099425f
void cUnk00adbbf0::Slot31_adbbf0()
{
    uint32_t color;
    Slot09_adb6a8(0, MakeFillColor(0, 0, 0));
    Slot09_adb6a8(1, MakeFillColor(0xff, 0xff, 0xff));
    Slot09_adb6a8(2, MakeFillColor(0, 0, 0));
    Slot09_adb6a8(3, MakeFillColor(0xff, 0xff, 0xff));
    Slot09_adb6a8(4, MakeFillColor(0, 0, 0));
    Slot09_adb6a8(5, MakeFillColor(0xff, 0xff, 0xff));
    Slot09_adb6a8(6, MakeFillColor(0xff, 0, 0));
    Slot09_adb6a8(7, MakeFillColor(0x80, 0x80, 0x80));
    mnColors[0] = MakeFillColor(0xff, 0xff, 0xff);
    mnColors[1] = MakeFillColor(0, 0, 0);
    mnColors[2] = MakeFillColor(0, 0, 0);
    mnColors[3] = MakeFillColor(0xc0, 0, 0);
    Slot08_ae1a28(MakeFillColor(0xff, 0xff, 0xff));
    if (mpColors) {
        PaletteOf_adbbf0(this)->Fn14(0, &color);
        Slot12_adf900(0, color);
        mnColors[1] = color;
        mnColors[2] = color;
        PaletteOf_adbbf0(this)->Fn14(1, &color);
        Slot12_adf900(1, color);
        mnColors[0] = color;
        PaletteOf_adbbf0(this)->Fn14(2, &color);
        Slot12_adf900(2, color);
        PaletteOf_adbbf0(this)->Fn14(3, &color);
        Slot12_adf900(3, color);
        PaletteOf_adbbf0(this)->Fn14(4, &color);
        Slot12_adf900(4, color);
        PaletteOf_adbbf0(this)->Fn14(5, &color);
        Slot12_adf900(5, color);
        Slot08_ae1a28(MgrOf_adbbf0(this)->Fn103());
    }
    if (mnMode == 0x14) {
        EditOf_adbbf0(this)->Fn14(4, &color);
        Slot12_adf900(0, color);
        color = EditOf_adbbf0(this)->Fn22();
        Slot12_adf900(1, color);
        Slot08_ae1a28(color);
    }
}

// FUNCTION: 0x00994b5b
bool cUnk00adbbf0::GZPaint()
{
    int32_t i;
    int32_t n;
    int32_t len;
    int32_t y1;
    int32_t x1;
    uint32_t lineHeight;
    uint32_t ascent;
    int32_t count;
    Rect_adbbf0 line;
    int32_t pos;
    cGZWinTextEdit::GZPaint();
    if (mnMode != 0x14) {
        lineHeight = FontOf_adbbf0(this)->Fn37(0, 0);
        ascent = FontOf_adbbf0(this)->Fn38();
        pos = 0;
        i = 0;
        n = mpAttrEnd - mpAttrBegin;
        for (; i < n; i++) {
            Text_adbbf0* text = TEXT_adbbf0(this);
            len = RZCharacterSize(text->mpBegin + pos, text->size() - pos, kRZEncodingString);
            if (mpAttrBegin[i]) {
                EditOf_adbbf0(this)->Fn61(&x1, &y1, pos);
                EditOf_adbbf0(this)->Fn60(x1, y1, &line.left, &line.top);
                uint32_t drop = lineHeight / 5 + ascent;
                uint32_t limit = reinterpret_cast<uint32_t*>(field24)[3];
                if (drop >= limit) {
                    drop = limit - 1;
                }
                line.top += drop;
                line.bottom = line.top;
                line.right = FontOf_adbbf0(this)->Fn40(TextBegin_adbbf0(this) + pos, len) + line.left;
                int32_t* origin = reinterpret_cast<int32_t*>(field24);
                line.top += origin[1];
                line.left += origin[0];
                line.bottom += origin[1];
                line.right += origin[0];
                uint8_t attr = mpAttrBegin[i];
                uint32_t color;
                if (attr < 4) {
                    color = mnColors[attr];
                } else {
                    color = mnColors[0];
                }
                count = (attr == 2) + 1;
                reinterpret_cast<Canvas_adbbf0*>(static_cast<uintptr_t>(field6c))->Fn21(ConvertNativeToPackedRGB(color));
                for (; count != 0; count--) {
                    reinterpret_cast<Canvas_adbbf0*>(static_cast<uintptr_t>(field6c))->Fn34(line.left, line.top, line.right, line.bottom);
                    line.top++;
                    line.bottom++;
                }
            }
            pos += len;
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009959cd score 31 (the original keeps the wide string's data pointer in ebx and tests it in the destructor, and indexes the attribute bytes as [base+index] without a pointer temporary; ours reloads the pointer and adds the address first)
void cUnk00adbbf0::Slot32_adbbf0(void* arg)
{
    Comp_adbbf0* p = static_cast<Comp_adbbf0*>(arg);
    if (p) {
        if (p->mpString) {
            std::basic_string<uint16_t> wide(p->mpString, p->mnCount);
            cRZString text;
            RZEncodingToString(wide.c_str(), wide.size(), kRZEncodingUTF16, text);
            int32_t width = FontOf_adbbf0(this)->Fn48(text.c_str(), text.size());
            SetH(width + mnTextAreaX * 2 + 4);
            EditOf_adbbf0(this)->Fn48(&text, 0);
        }
        if (p->mpAttrs) {
            Bytes_adbbf0* attrs = reinterpret_cast<Bytes_adbbf0*>(&mpAttrBegin);
            attrs->Resize(p->mnCount);
            for (uint32_t i = 0; i < p->mnCount; i++) {
                attrs->mpBegin[i] = p->mpAttrs[i];
                uint8_t* b = attrs->mpBegin;
                if (b[i] >= 4) {
                    b[i] = 0;
                }
            }
        }
        Slot33_adbbf0(p);
    }
}
#endif
