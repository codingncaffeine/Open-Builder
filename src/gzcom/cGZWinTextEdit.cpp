#include "classes/cGZWinTextEdit.h"
#include "gzcom/cIGZString.h"
#include <cstring>
#include <set>

// This object's text-edit interface (the second base) seen through the slots that take a pointer.
struct cIf_adfbd0 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void SetFont(void* font);
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual bool GetColor(uint32_t index, uint32_t* color);
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void D29();
    virtual void D30();
    virtual void D31();
    virtual void D32();
    virtual void D33();
    virtual void D34();
    virtual void D35();
    virtual void D36();
    virtual void D37();
    virtual void D38();
    virtual void D39();
    virtual void D40();
    virtual void D41();
    virtual void D42();
    virtual void D43();
    virtual void D44();
    virtual void D45();
    virtual void D46();
    virtual void D47();
    virtual void D48();
    virtual bool SetTextC(const char* text, uint32_t length, uint32_t flag);
    virtual void D50();
    virtual uint32_t InsertText(const char* text, uint32_t length, uint32_t index);
    virtual bool RemoveChar(uint32_t index, uint32_t flag, cIGZString* removed);
    virtual void D53();
    virtual void D54();
    virtual uint32_t RemoveText(uint32_t index, uint32_t count, cIGZString* removed);
    virtual void D56();
    virtual void D57();
    virtual void GetColumnFromPosition(uint32_t line, uint32_t* col, int32_t x);
    virtual void GetLineAndColumnFromPosition(uint32_t* line, uint32_t* col, int32_t x, int32_t y);
    virtual void GetPositionFromLineAndColumn(uint32_t line, uint32_t col, int32_t* x, int32_t* y);
    virtual void GetLineAndColumnFromIndex(uint32_t* line, uint32_t* col, uint32_t index);
    virtual bool GetIndexFromLineAndColumn(uint32_t line, uint32_t col, uint32_t* index);
    virtual void D63();
    virtual void D64();
    virtual void D65();
    virtual void D66();
    virtual void D67();
    virtual void D68();
    virtual void D69();
    virtual void D70();
    virtual void D71();
    virtual void D72();
    virtual void D73();
    virtual bool GetSelection(uint32_t* start, uint32_t* end);
    virtual void D75();
    virtual void D76();
    virtual void D77();
    virtual void D78();
    virtual void D79();
    virtual void D80();
    virtual void D81();
    virtual void D82();
    virtual void D83();
    virtual void D84();
    virtual void D85();
    virtual void D86();
    virtual void D87();
    virtual void D88();
    virtual void D89();
};

// This object's own vtable (cGZWin's slots, then its own) seen through the slots that take a pointer or return a bool.
struct cPrim_adfbd0 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void P11();
    virtual void P12();
    virtual void P13();
    virtual void AddChild(void* window);
    virtual void P15();
    virtual bool ChildRemove(void* window);
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
    virtual void P38();
    virtual void P39();
    virtual void P40();
    virtual uint32_t GetW();
    virtual uint32_t GetH();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual void P48();
    virtual void P49();
    virtual void P50();
    virtual void P51();
    virtual void P52();
    virtual void P53();
    virtual void P54();
    virtual void P55();
    virtual void P56();
    virtual void P57();
    virtual void P58();
    virtual void P59();
    virtual void P60();
    virtual void P61();
    virtual void P62();
    virtual void P63();
    virtual void P64();
    virtual void P65();
    virtual void P66();
    virtual void P67();
    virtual void P68();
    virtual void P69();
    virtual void P70();
    virtual bool IsVisible();
    virtual void P72();
    virtual void P73();
    virtual void P74();
    virtual void P75();
    virtual void P76();
    virtual void P77();
    virtual void P78();
    virtual void P79();
    virtual void P80();
    virtual void P81();
    virtual void P82();
    virtual void P83();
    virtual void P84();
    virtual void SetCursorObject(void* cursor);
    virtual void P86();
    virtual void P87();
    virtual void P88();
    virtual void P89();
    virtual void P90();
    virtual void P91();
    virtual void P92();
    virtual void P93();
    virtual void P94();
    virtual void P95();
    virtual void P96();
    virtual void P97();
    virtual void P98();
    virtual void P99();
    virtual void P100();
    virtual void P101();
    virtual void P102();
    virtual void P103();
    virtual void P104();
    virtual void P105();
    virtual void P106();
    virtual void P107();
    virtual void P108();
    virtual void P109();
    virtual void P110();
    virtual void P111();
    virtual void P112();
    virtual void P113();
    virtual void P114();
    virtual void P115();
    virtual void P116();
    virtual void P117();
    virtual void P118();
    virtual void P119();
    virtual void P120();
    virtual void P121();
    virtual void P122();
    virtual void P123();
    virtual void P124();
    virtual void P125();
    virtual void P126();
    virtual void P127();
    virtual void P128();
    virtual void P129();
    virtual void P130();
    virtual void P131();
    virtual void P132();
    virtual void P133();
    virtual void P134();
    virtual void P135();
    virtual void P136();
    virtual void P137();
    virtual void P138();
    virtual void P139();
    virtual void P140();
    virtual void P141();
    virtual void P142();
    virtual void P143();
    virtual bool SendMsg5(uint32_t target, uint32_t msg, void* sender, uint32_t a, uint32_t b);
    virtual void P145();
    virtual void P146();
    virtual void P147();
    virtual void P148();
    virtual void P149();
    virtual void P150();
    virtual void P151();
    virtual void P152();
    virtual void P153();
    virtual void P154();
    virtual void P155();
};

// Timers the object owns (their own classes are not declared yet): the slots used.
struct cTimer_adfbd0 {
    virtual void T0();
    virtual void T1();
    virtual void T2();
    virtual void T3();
    virtual void T4();
    virtual void StartPeriodic(uint32_t period, void* target);
    virtual void T6();
    virtual void Stop();
    virtual bool IsRunning();
    virtual void SetCallbackFunction(void (*fn)(void*), void* context);
};

// The component manager the accessor 0x00913c72 gives; slot 5 finds a font by its id.
struct cWCM_adfbd0 {
    virtual void W0();
    virtual void W1();
    virtual void W2();
    virtual void W3();
    virtual void W4();
    virtual void* GetFont(uint32_t id);
    virtual void W6();
    virtual void W7();
    virtual void W8();
    virtual void W9();
    virtual void W10();
    virtual void W11();
    virtual void W12();
    virtual void W13();
    virtual void W14();
    virtual void W15();
    virtual void W16();
    virtual void* CreateScrollBar(uint32_t kind, uint32_t orientation, uint32_t a, uint32_t b, uint32_t c);
};

// STUB: 0x00913c72
cWCM_adfbd0* Fn00913c72();

// The line-start vector as the original's standard library lays it out.
struct LineVec_adfbd0 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x006bdf10
    void Resize(uint32_t size, const uint32_t& value);
    // STUB: 0x0050c4c0
    void Reserve(uint32_t count);
    // STUB: 0x0040e490
    void Erase(uint32_t* first, uint32_t* last);
    // STUB: 0x00423db0
    void Truncate(uint32_t size);
    // STUB: 0x007ebd30
    void PushBack(const uint32_t& value);
};

// The object at the service accessor 0x008793ec, asked for a component by two ids.
struct ServiceMgr_adfbd0 {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual bool Query(uint32_t id1, uint32_t id2, void* out);
};

// STUB: 0x008793ec
ServiceMgr_adfbd0* Fn008793ec();

// The clipboard manager's service pointer.
struct cSysServPtrClipboard_adfbd0 {
    void* mpService;
    cSysServPtrClipboard_adfbd0();
};

// The font object (cIGZFont), seen through the slots used.
struct cFont_adfbd0 {
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8();
    virtual void F9();
    virtual void F10();
    virtual void F11();
    virtual void F12();
    virtual void F13();
    virtual void F14();
    virtual void F15();
    virtual void F16();
    virtual void F17();
    virtual void F18();
    virtual void F19();
    virtual void F20();
    virtual void F21();
    virtual void F22();
    virtual void F23();
    virtual void F24();
    virtual void F25();
    virtual void F26();
    virtual void F27();
    virtual void F28();
    virtual void F29();
    virtual void F30();
    virtual void F31();
    virtual void F32();
    virtual void F33();
    virtual void F34();
    virtual void F35();
    virtual void F36();
    virtual void F37();
    virtual void F38();
    virtual void F39();
    virtual void F40();
    virtual uint32_t Slot41(const char* text, uint32_t length, uint32_t width, uint32_t a, uint32_t b);
    virtual void F42();
    virtual void F43();
    virtual void F44();
    virtual void F45();
    virtual void F46();
    virtual void F47();
    virtual uint32_t Slot48(const char* text, uint32_t length);
    virtual void F49();
    virtual void F50();
    virtual void DrawText(void* buffer, int32_t x, int32_t y, const char* text, uint32_t length, uint32_t color, uint32_t color2, const int32_t* clip, uint32_t flag);
};

// The second base seen through the interface view. A pointer upcast is checked for null, which the original's calls on this are not.
inline cIf_adfbd0* IfOf_adfbd0(cGZWinTextEdit* t)
{
#ifdef _MSC_VER
    __assume(t != 0);
#endif
    return reinterpret_cast<cIf_adfbd0*>(static_cast<cUnk00adf900*>(t));
}

// The standard string as the original's library lays it out; the slot-less member is the case-blind search.
struct StdString_adfbd0 {
    // STUB: 0x005c23e0
    uint32_t FindNoCase(const char* text, uint32_t pos, uint32_t n) const;
};

// The vertical scroll bar object, seen through the slot used.
struct cScrollBar_adfbd0 {
    virtual void B0();
    virtual void B1();
    virtual void Release();
    virtual void* AsIGZWin();
    virtual void B4();
    virtual void SetValue(int32_t value);
    virtual int32_t GetValue();
    virtual void SetRange(int32_t low, int32_t high);
    virtual void B8();
    virtual void B9();
    virtual void B10();
    virtual void B11();
    virtual void B12();
    virtual void B13();
    virtual void B14();
    virtual void SetPage(int32_t position, int32_t pages);
    virtual void B16();
    virtual void SetImage(const void* rect, void* image, uint32_t flag);
};

// An image object, seen through the slots used.
struct cImage_adfbd0 {
    virtual void I0();
    virtual void AddRef();
    virtual void Release();
    virtual void I3();
    virtual void I4();
    virtual void I5();
    virtual void I6();
    virtual void I7();
    virtual void I8();
    virtual void I9();
    virtual void I10();
    virtual void I11();
    virtual void* GetRect();
};

// The sound system the accessor 0x00913c9e gives.
struct cSS_adfbd0 {
    virtual void Q0();
    virtual void Q1();
    virtual void Q2();
    virtual void Q3();
    virtual void Q4();
    virtual void Q5();
    virtual void Q6();
    virtual void Q7();
    virtual bool Play(void* object);
    virtual void Q9();
    virtual void Q10();
    virtual void Q11();
    virtual void Q12();
    virtual bool Create(uint32_t kind, uint32_t iid, void** out, uint32_t id, uint32_t a, uint32_t b, uint32_t c);
};

// STUB: 0x00913c9e
cSS_adfbd0* Fn00913c9e();

// STUB: 0x007c1870
bool Fn007c1870();

// STUB: 0x009107d8
int32_t RZCharacterCount(const char* text, int32_t length, int32_t codePage);

// STUB: 0x0091073c
uint32_t GetPreviousCharLength(const void* text, uint32_t position, int32_t codePage);

// The reference-counted pointer to the font (cRZAutoRefCount) seen through its assignment.
struct AutoRef_adfbd0 {
    // STUB: 0x005447b0
    void Assign(void* pointer);
};

// The window manager (field4), seen through the slot used.
struct cWinMgr_adfbd0 {
    virtual void M0();
    virtual void M1();
    virtual void M2();
    virtual void M3();
    virtual void M4();
    virtual void M5();
    virtual void M6();
    virtual void M7();
    virtual void M8();
    virtual void M9();
    virtual void M10();
    virtual void M11();
    virtual void M12();
    virtual void M13();
    virtual void M14();
    virtual void M15();
    virtual void M16();
    virtual void M17();
    virtual void M18();
    virtual void M19();
    virtual void M20();
    virtual void M21();
    virtual void M22();
    virtual void M23();
    virtual void M24();
    virtual void M25();
    virtual void M26();
    virtual void M27();
    virtual void M28();
    virtual void M29();
    virtual void M30();
    virtual void M31();
    virtual void M32();
    virtual void M33();
    virtual void GetCursorPoint(void* window, int32_t* x, int32_t* y);
};

// The plain timer the object keeps first (its members are called directly).
struct cRZTimer_adfbd0 {
    // STUB: 0x0088fefb
    bool IsTimerRunning() const;
    // STUB: 0x00890198
    uint32_t GetElapsedTime() const;
    // STUB: 0x0088ff0a
    void Reset();
    // STUB: 0x0089058f
    void Restart();
    // STUB: 0x00890181
    void SetUnits(uint32_t units);
};

// Five dwords copied as a whole.
struct Five_adfbd0 {
    uint32_t v[5];
};

// The keyboard object (field8), seen through the slot used.
struct cKbd_adfbd0 {
    virtual void K0();
    virtual void K1();
    virtual void K2();
    virtual void K3(uint32_t key);
};

// The cursor manager the member 0x0099bf14 gives.
struct cCursorMgr_adfbd0 {
    virtual void C0();
    virtual void C1();
    virtual void C2();
    virtual void C3();
    virtual void C4();
    virtual void C5();
    virtual void C6();
    virtual void C7();
    virtual void C8();
    virtual void* GetCursor(uint32_t kind, uint32_t flag);
};



// STUB: 0x009108b4
bool IsLeadByte(char c, int32_t codePage);

// STUB: 0x009108ed
uint32_t GetFollowByteCount(char c, int32_t codePage);

// STUB: 0x00940da8
uint32_t Fn00940da8();

// STUB: 0x009bd16c
void CaretTimerCallback_adfbd0(void* context);

// STUB: 0x009bccaf
void ScrollTimerCallback_adfbd0(void* context);

// One undo or redo record (0x3c bytes).
struct UndoRecord_adfbd0 {
    uint8_t mbIsInsert;
    uint32_t mnPosition;
    uint32_t mnLength;
    bool mbHasText;
    uint32_t mnTextPosition;
    cRZString mText;
    Five_adfbd0 mInsertion;
    // STUB: 0x009be9ce
    UndoRecord_adfbd0();
    // STUB: 0x009be9af
    void Destroy(uint32_t flags);
};

// The undo or redo vector as the original's library lays it out.
struct UndoVec_adfbd0 {
    UndoRecord_adfbd0* mpBegin;
    UndoRecord_adfbd0* mpEnd;
    UndoRecord_adfbd0* mpCap;
    // STUB: 0x009c04cb
    void Erase(UndoRecord_adfbd0* first, UndoRecord_adfbd0* last);
    // STUB: 0x009c0145
    void PushBack(const UndoRecord_adfbd0& value);
};

// The draw context (field64), seen through the slots used.
struct cDC_adfbd0 {
    virtual void X0();
    virtual void X1();
    virtual void X2();
    virtual void X3();
    virtual void X4();
    virtual void X5();
    virtual void X6();
    virtual void X7();
    virtual void X8();
    virtual void X9();
    virtual void X10();
    virtual void X11();
    virtual void X12();
    virtual void X13();
    virtual void X14();
    virtual void X15();
    virtual void X16();
    virtual void X17();
    virtual void X18();
    virtual void X19();
    virtual void X20();
    virtual void SetColor(uint32_t color);
    virtual void X22();
    virtual void X23();
    virtual void X24();
    virtual void SetLineWidth(float width);
    virtual void X26();
    virtual void X27();
    virtual void X28();
    virtual void X29();
    virtual void X30();
    virtual void X31();
    virtual void X32();
    virtual void X33();
    virtual void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
    virtual void FillRect(const int32_t* rect);
    virtual void X36();
    virtual void X37();
    virtual void X38();
    virtual void Blt(void* image, const int32_t* source, const int32_t* destination, uint32_t a, uint32_t b);
};

// STUB: 0x008d8800
void RZDrawBltEdge(void* context, void* image, const int32_t* source, const int32_t* destination, bool flag);

// STUB: 0x008d9360
void RZDrawRectangleOutline(void* context, const int32_t* rect, uint32_t color, uint32_t width);

// The clipboard manager (field 0x28c), seen through the slots used.
struct cClip_adfbd0 {
    virtual void L0();
    virtual void L1();
    virtual void L2();
    virtual void L3();
    virtual void L4();
    virtual void L5();
    virtual void L6();
    virtual void L7();
    virtual void L8();
    virtual void L9();
    virtual void L10();
    virtual void L11();
    virtual void L12();
    virtual void L13();
    virtual void L14();
    virtual void L15();
    virtual void L16();
    virtual void L17();
    virtual bool GetText(void* text, uint32_t flag);
    virtual void L19();
    virtual void SetText(void* text, uint32_t flag, uint32_t other);
};

// Four int32 copied as a whole.
struct Rect_adfbd0 {
    int32_t v[4];
};

// FUNCTION: 0x009100de
uint32_t Fn009100de(uint32_t c)
{
    if (c >= 0xe00 && c <= 0xe7f) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x009bc5cc
uint32_t Fn009bc5cc(uint8_t c)
{
    if (c == ' ' || c == '\n') {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00994a39
uint32_t cGZWinTextEdit::Slot24_adb6a8()
{
    return mText.size();
}

// FUNCTION: 0x00994ff2
uint32_t cGZWinTextEdit::Slot35_adf900()
{
    return mpLineEnd - mpLineBegin;
}

// FUNCTION: 0x009bcb14
uint32_t cGZWinTextEdit::Slot65_adf900()
{
    return ~(mnTextFlags >> 14) & 1;
}

// FUNCTION: 0x009bcb20
bool cGZWinTextEdit::Slot67_adf900(uint32_t a)
{
    *reinterpret_cast<uint32_t*>(a) = mnInsertionIndex;
    return true;
}

// FUNCTION: 0x009bc854
uint32_t cGZWinTextEdit::Slot79_adf900(uint32_t a)
{
    return (mnTextFlags & a) != 0;
}

// FUNCTION: 0x009be99f
void cGZWinTextEdit::ShowWindow()
{
    UpdateScrollBarsAndWindowPosition();
    cGZWin::ShowWindow();
}

// FUNCTION: 0x009bc967
bool cGZWinTextEdit::Slot15_adf900(uint32_t a, uint32_t b)
{
    mnColors[a] = b;
    return true;
}

// FUNCTION: 0x009bc97b
bool cGZWinTextEdit::Slot16_adf900(uint32_t a, uint32_t b)
{
    *reinterpret_cast<uint32_t*>(b) = mnColors[a];
    return true;
}

// FUNCTION: 0x009bcafe
bool cGZWinTextEdit::Slot64_adf900(uint32_t a)
{
    if (*reinterpret_cast<bool*>(&a)) {
        mnTextFlags &= ~0x4000;
    } else {
        mnTextFlags |= 0x4000;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bd47f score 6 (the original loads the field into eax before the this adjustment)
void cGZWinTextEdit::Slot22_adf900()
{
    uint32_t c = mnHighlightFillColor;
    ConvertPackedRGBToNative(c);
}
#endif

// FUNCTION: 0x00994ec0
void cGZWinTextEdit::Slot49_adda20(uint32_t a)
{
    Slot48_adf900(a, 0);
}

// FUNCTION: 0x009bcb2e
bool cGZWinTextEdit::Slot69_adf900(uint32_t a, uint32_t b)
{
    *reinterpret_cast<uint32_t*>(a) = mnInsertionLine;
    *reinterpret_cast<uint32_t*>(b) = mnInsertionColumn;
    return true;
}

// FUNCTION: 0x009bcbae
bool cGZWinTextEdit::Slot74_adf900(uint32_t a, uint32_t b)
{
    *reinterpret_cast<uint32_t*>(a) = mnSelectionStart;
    *reinterpret_cast<uint32_t*>(b) = mnSelectionEnd;
    return true;
}

// FUNCTION: 0x0091880e
void cGZWinTextEdit::Slot22_adb6a8(uint32_t a)
{
    cIGZString* s = reinterpret_cast<cIGZString*>(a);
    s->FromChar(mText.data(), mText.size());
}

// FUNCTION: 0x009bc94e
bool cGZWinTextEdit::Slot11_adf900(uint32_t a)
{
    if (mnFontStyle) {
        *reinterpret_cast<uint32_t*>(a) = mnFontStyle;
        return true;
    }
    return false;
}

// FUNCTION: 0x009bd495
void cGZWinTextEdit::Slot23_adf900(uint32_t a)
{
    mnHighlightFillColor = ConvertPackedRGBToNative(a);
}

// FUNCTION: 0x009bd37a
void cGZWinTextEdit::Slot11_adb6a8(uint32_t a)
{
    mnCaretColor = ConvertNativeToPackedRGB(a);
}

// FUNCTION: 0x009bd399
bool cGZWinTextEdit::Slot10_adb6a8(uint32_t a)
{
    uint32_t c = mnCaretColor;
    *reinterpret_cast<uint32_t*>(a) = ConvertPackedRGBToNative(c);
    return true;
}

// FUNCTION: 0x009bd3c0
bool cGZWinTextEdit::Slot13_adf900(uint32_t a)
{
    mnColors[0] = ConvertNativeToPackedRGB(a);
    return true;
}

// FUNCTION: 0x009bd3e1
void cGZWinTextEdit::Slot12_adf900(uint32_t a, uint32_t b)
{
    uint32_t c = ConvertNativeToPackedRGB(b);
    Slot15_adf900(a, c);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bd406 score 15 (needs a pointer argument to a base-declared slot: the pointer view of the second base is null-checked here, the original calls the slot on this)
bool cGZWinTextEdit::Slot14_adf900(uint32_t a, uint32_t b)
{
    uint32_t c = 0xff000000;
    if (IfOf_adfbd0(this)->GetColor(a, &c)) {
        *reinterpret_cast<uint32_t*>(b) = ConvertPackedRGBToNative(c);
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x009bd447
bool cGZWinTextEdit::Slot17_adf900(uint32_t a)
{
    if (a == 0 || a == 2) {
        mnColors[a] = 0xff000000;
    } else if (a == 4) {
        mnColors[a] = 0xffffffff;
    } else {
        mnColors[a] = 0x40000000;
    }
    return true;
}

// FUNCTION: 0x009bc81c
void cGZWinTextEdit::Slot76_adf900(uint32_t a)
{
    uint32_t f = mnTextFlags;
    if (!(f & a)) {
        Slot77_adf900(f | a);
    }
}

// FUNCTION: 0x009bc837
void cGZWinTextEdit::Slot78_adf900(uint32_t a)
{
    uint32_t f = mnTextFlags;
    if (a & f) {
        Slot77_adf900(f & ~a);
    }
}

// FUNCTION: 0x009bcc57
bool cGZWinTextEdit::Slot89_adf900(uint32_t a, uint32_t b)
{
    if (static_cast<int32_t>(a) < 4) {
        mnSoundIDs[a] = b;
        return true;
    }
    return false;
}

// FUNCTION: 0x009bc991
void cGZWinTextEdit::Slot24_adf900(uint32_t a, uint32_t b)
{
    *reinterpret_cast<void**>(a) = mpBackgroundImage;
    *reinterpret_cast<bool*>(b) = mbBackgroundTile;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004d7b30 score 2 (the original was built with the game flags: mov [esi],0 where this folder has and [esi],0)
cSysServPtrClipboard_adfbd0::cSysServPtrClipboard_adfbd0()
{
    mpService = 0;
    ServiceMgr_adfbd0* m = Fn008793ec();
    if (m) {
        m->Query(0x27ebfffd, 0x7ec0010, this);
    }
}
#endif

// FUNCTION: 0x009bcc93
void cGZWinTextEdit::StopScrollTimer()
{
    cTimer_adfbd0* t = reinterpret_cast<cTimer_adfbd0*>(mScrollTimer);
    if (t->IsRunning()) {
        t->Stop();
    }
}

// FUNCTION: 0x009bcc74
void cGZWinTextEdit::Fn009bcc74()
{
    cTimer_adfbd0* t = reinterpret_cast<cTimer_adfbd0*>(mScrollTimer);
    if (!t->IsRunning()) {
        t->StartPeriodic(100, 0);
    }
}

// FUNCTION: 0x009be9ed
void cGZWinTextEdit::Fn009be9ed()
{
    LineVec_adfbd0* v = reinterpret_cast<LineVec_adfbd0*>(&mpLineBegin);
    if (v->mpBegin == v->mpEnd) {
        uint32_t zero = 0;
        v->PushBack(zero);
    }
}

// FUNCTION: 0x009bc60e
void cGZWinTextEdit::ToggleCaretVisibility()
{
    if (Fn0099bdf3() == this) {
        mbCaretVisible = !mbCaretVisible;
        InvalidateSelfAndParents();
    }
}

// FUNCTION: 0x009bc635
void cGZWinTextEdit::Fn009bc635()
{
    if (Fn0099bdf3() == this) {
        if (!mbCaretVisible) {
            mbCaretVisible = true;
            InvalidateSelfAndParents();
        }
    }
}

// FUNCTION: 0x009be945
void cGZWinTextEdit::UpdateScrollBarsAndWindowPosition()
{
    if (get_init_flag()) {
        PutInsertionPositionInView();
        TestForPossibleScrollBarAdditionOrRemoval();
    }
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009bc864
bool cGZWinTextEdit::Slot85_adf900(uint32_t a, uint32_t b)
{
    void** image = reinterpret_cast<void**>(a);
    *image = mpScrollBarImageV;
    *reinterpret_cast<Rect_adfbd0*>(b) = *reinterpret_cast<Rect_adfbd0*>(mnScrollBarRectV);
    return *image != 0;
}

// FUNCTION: 0x009bc88e
bool cGZWinTextEdit::Slot86_adf900(uint32_t a, uint32_t b)
{
    void** image = reinterpret_cast<void**>(a);
    *image = mpScrollBarImageH;
    *reinterpret_cast<Rect_adfbd0*>(b) = *reinterpret_cast<Rect_adfbd0*>(mnScrollBarRectH);
    return *image != 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bc904 score 27 (SetFont takes a pointer: same null-checked second-base view as 9bd406)
bool cGZWinTextEdit::Slot10_adf900(uint32_t a)
{
    mnFontStyle = a;
    if (get_init_flag()) {
        uint32_t id = mnFontStyle;
        if (!id) {
            id = 0x68963c4c;
        }
        void* font = Fn00913c72()->GetFont(id);
        if (font) {
            IfOf_adfbd0(this)->SetFont(font);
        }
    }
    return true;
}
#endif

// FUNCTION: 0x009bd1cd
bool cGZWinTextEdit::GZOnMouseUpL(uint32_t, uint32_t, uint32_t)
{
    if (mnTextFlags & 1) {
        if (GZAmCapturing()) {
            GZReleaseCapture();
            StopScrollTimer();
        }
    }
    return true;
}

// FUNCTION: 0x009bc6b5
bool cGZWinTextEdit::GZOnKeyUp(uint32_t a, uint32_t b)
{
    if (a == 0x1b) {
        return reinterpret_cast<cPrim_adfbd0*>(this)->SendMsg5(field4c, 6, reinterpret_cast<void*>(0x1b), b, 0);
    }
    return true;
}

// FUNCTION: 0x009bc5e1
bool cGZWinTextEdit::QueryInterface(unsigned int iid, void** ppv)
{
    if (iid == 0x231a1c57) {
        *ppv = static_cast<cUnk00adf900*>(this);
        AddRef();
        return true;
    }
    return cGZWin::QueryInterface(iid, ppv);
}

// FUNCTION: 0x009bc6d8
bool cGZWinTextEdit::GZOnMouseDownR(uint32_t a, uint32_t b, uint32_t)
{
    if (!(mnTextFlags & 1)) {
        cUnk00adf900& r = *this;
        reinterpret_cast<cPrim_adfbd0*>(this)->SendMsg5(field4c, 0x9b1552d7, &r, a, b);
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00994e8c score 19 (SetText(const char*, len, flag) takes a pointer: same null-checked second-base view as 9bd406)
void cGZWinTextEdit::Slot48_adf900(uint32_t a, uint32_t b)
{
    cIGZString* s = reinterpret_cast<cIGZString*>(a);
    IfOf_adfbd0(this)->SetTextC(s->Data(), s->Strlen(), b);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bddc2 score 2 (only the order of the loads of mpFont and the text pointer differs)
uint32_t cGZWinTextEdit::Fn009bddc2()
{
    if (mnTextFlags & 0x200) {
        return reinterpret_cast<cFont_adfbd0*>(mpFont)->Slot48(mText.c_str(), mnHScrollChars);
    }
    return mnHScrollPixels;
}
#endif

// FUNCTION: 0x009bde57
bool cGZWinTextEdit::Slot26_adf900()
{
    if (mnFirstVisibleLine > 0) {
        --mnFirstVisibleLine;
        Fn009bdcd1(0);
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bca39 score 9 (logic matches; register choice and instruction order differ)
void cGZWinTextEdit::Slot50_adf900(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    IfOf_adfbd0(this)->GetIndexFromLineAndColumn(c, d, &d);
    Slot51_adf900(a, b, d);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bca6b score 9 (logic matches; register choice and instruction order differ)
void cGZWinTextEdit::Slot54_adf900(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    IfOf_adfbd0(this)->GetIndexFromLineAndColumn(a, b, &b);
    Slot55_adf900(b, c, d);
}
#endif

// FUNCTION: 0x009bd0af
void cGZWinTextEdit::Fn009bd0af()
{
    uint32_t i = mnInsertionIndex;
    if (i > 0) {
        uint32_t* pc = &mnInsertionColumn;
        uint32_t c = *pc;
        if (c > 0) {
            if (mText[i - 1] == '\n') {
                --c;
                --i;
                *pc = c;
                mnInsertionIndex = i;
            }
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bd19b score 24 (logic matches; register choice and instruction order differ)
void cGZWinTextEdit::Slot07_adf900(uint32_t a)
{
    int32_t* r = reinterpret_cast<int32_t*>(a);
    r[0] = mnTextAreaX;
    r[1] = mnTextAreaY;
    r[2] = mnTextAreaX + mnTextAreaW;
    r[3] = mnTextAreaY + mnTextAreaH;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009be96a score 12 (logic matches; register choice and instruction order differ)
uint32_t cGZWinTextEdit::Slot56_adf900(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    const char* text = reinterpret_cast<const char*>(a);
    uint32_t r;
    if (*reinterpret_cast<bool*>(&d)) {
        r = mText.find(text, c, b);
    } else {
        r = reinterpret_cast<const StdString_adfbd0*>(static_cast<const std::string*>(&mText))->FindNoCase(text, c, b);
    }
    if (r >= mText.size()) {
        r = 0xffffffff;
    }
    return r;
}
#endif

// FUNCTION: 0x009bc7dd
uint32_t cGZWinTextEdit::Slot68_adc8d8(uint32_t a, uint32_t b)
{
    if (a == 1) {
        if (*reinterpret_cast<bool*>(&b)) {
            uint32_t f = mnTextFlags;
            if ((f & 0x40) && (f & 1)) {
                StartCaretTimer(true);
            }
        } else {
            StartCaretTimer(false);
        }
    }
    return cGZWin::Slot68_adc8d8(a, b);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bd554 score 24 (logic matches; register choice and instruction order differ)
uint32_t cGZWinTextEdit::Slot63_adf900(uint32_t a)
{
    if (mText.empty()) {
        return 0;
    }
    uint32_t n = mpLineEnd - mpLineBegin;
    if (a < n - 1) {
        return mpLineBegin[a + 1] - mpLineBegin[a];
    }
    return mText.size() - mpLineBegin[n - 1];
}
#endif

// FUNCTION: 0x009bc75d
bool cGZWinTextEdit::GZOnSetFocus(uint32_t a)
{
    InvalidateSelfAndParents();
    if (mnTextFlags & 0x20000) {
        reinterpret_cast<cPrim_adfbd0*>(this)->SendMsg5(field4c, 0x9b1552da, IfOf_adfbd0(this), 0, 0);
    }
    return cGZWin::GZOnSetFocus(a);
}

// FUNCTION: 0x009bc79d
bool cGZWinTextEdit::GZOnKillFocus(uint32_t a)
{
    InvalidateSelfAndParents();
    if (mnTextFlags & 0x8000) {
        reinterpret_cast<cPrim_adfbd0*>(this)->SendMsg5(field4c, 0x9b1552d9, IfOf_adfbd0(this), 0, 0);
    }
    return cGZWin::GZOnKillFocus(a);
}

// FUNCTION: 0x009bde87
bool cGZWinTextEdit::Slot27_adf900()
{
    int32_t n = mpLineEnd - mpLineBegin;
    n -= mnVisibleLineCount;
    n -= mnFirstVisibleLine;
    if (n > 0) {
        ++mnFirstVisibleLine;
        Fn009bdcd1(0);
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bdfc7 score 19 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::Slot28_adf900()
{
    if (!mnFirstVisibleLine && !mnHScrollChars) {
        return false;
    }
    mnHScrollChars = 0;
    mnHScrollPixels = 0;
    mnFirstVisibleLine = 0;
    Fn009bdcd1(0);
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bd510 score 10 (logic matches; register choice and instruction order differ)
void cGZWinTextEdit::Slot57_adf900(uint32_t a, uint32_t b, uint32_t c)
{
    if (mText.size() == 0) {
        *reinterpret_cast<uint32_t*>(a) = 0;
    } else {
        IfOf_adfbd0(this)->GetLineAndColumnFromPosition(&c, &b, b, c);
        *reinterpret_cast<uint32_t*>(a) = mpLineBegin[c] + b;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bd66e score 41 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::Slot66_adf900(uint32_t a)
{
    if (a > mText.size() || a == 0xffffffff) {
        a = mText.size();
    }
    mnInsertionIndex = a;
    IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, a);
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009be063 score 10 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::Slot30_adf900()
{
    int32_t f = mnFirstVisibleLine;
    if (!f) {
        return false;
    }
    int32_t v = mnVisibleLineCount;
    if (f >= v) {
        mnFirstVisibleLine = f - v;
    } else {
        mnFirstVisibleLine = 0;
    }
    Fn009bdcd1(0);
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009be009 score 31 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::Slot29_adf900()
{
    int32_t v = mnVisibleLineCount;
    int32_t n = mpLineEnd - mpLineBegin;
    if (n - v - mnFirstVisibleLine > 0) {
        mnFirstVisibleLine = (mpLineEnd - mpLineBegin) - v;
        mnHScrollChars = 0;
        mnHScrollPixels = 0;
        Fn009bdcd1(0);
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bd997 score 55 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::Slot75_adf900(uint32_t a, uint32_t b)
{
    uint32_t s = a;
    if (s > mText.size()) {
        s = mText.size();
    }
    uint32_t e = b;
    if (e > mText.size()) {
        e = mText.size();
    }
    mnSelectionEnd = e;
    mnInsertionIndex = e;
    mnSelectionStart = s;
    IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, e);
    InvalidateSelfAndParents();
    return true;
}
#endif

// FUNCTION: 0x009bc9ac
void cGZWinTextEdit::Slot25_adf900(uint32_t a, uint32_t b)
{
    bool changed = false;
    cIGZUnknown* img = reinterpret_cast<cIGZUnknown*>(a);
    if (mpBackgroundImage != img) {
        if (img) {
            img->AddRef();
        }
        if (mpBackgroundImage) {
            reinterpret_cast<cIGZUnknown*>(mpBackgroundImage)->Release();
        }
        mpBackgroundImage = img;
        changed = true;
    }
    bool tile = *reinterpret_cast<bool*>(&b);
    if (mbBackgroundTile != tile) {
        mbBackgroundTile = tile;
        changed = true;
    }
    if (changed) {
        InvalidateSelfAndParents();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bd610 score 60 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::Slot62_adf900(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t* out = reinterpret_cast<uint32_t*>(c);
    if (mpLineBegin != mpLineEnd && !mText.empty()) {
        uint32_t n = mpLineEnd - mpLineBegin;
        uint32_t base;
        if (a < n) {
            base = mpLineBegin[a];
        } else {
            base = mpLineBegin[n - 1];
        }
        *out = base + b;
        if (*out <= mText.size()) {
            return true;
        }
        *out = mText.size();
    } else {
        *out = 0;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bca9d score 19 (logic matches; register choice and instruction order differ)
void cGZWinTextEdit::Slot53_adf900(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t)
{
    IfOf_adfbd0(this)->GetIndexFromLineAndColumn(a, b, &b);
    IfOf_adfbd0(this)->GetIndexFromLineAndColumn(c, d, &a);
    if (b > a) {
        Slot55_adf900(b, b - a, 0);
    } else {
        Slot55_adf900(b, a - b, 0);
    }
}
#endif

// FUNCTION: 0x009bc705
bool cGZWinTextEdit::GZOnMouseWheel(uint32_t, uint32_t, uint32_t, uint32_t d)
{
    if (!GZAmCapturing()) {
        int32_t delta = static_cast<int32_t>(d);
        if (delta > 0) {
            for (int32_t i = 0; i < delta / 100; ++i) {
                Slot26_adf900();
            }
        } else if (delta < 0) {
            for (int32_t i = 0; i < delta / -100; ++i) {
                Slot27_adf900();
            }
        }
    }
    return true;
}

// FUNCTION: 0x009bcb45
bool cGZWinTextEdit::Slot13_adb6a8(uint32_t a)
{
    mnCaretPeriod = a;
    if (mnCaretPeriod < 250) {
        mnCaretPeriod = 250;
    }
    if (mnCaretPeriod > 10000) {
        mnCaretPeriod = 10000;
    }
    if (get_init_flag()) {
        if (mnTextFlags & 0x40) {
            Slot78_adf900(0x40);
            Slot76_adf900(0x40);
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bc65c score 32 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::StartCaretTimer(bool on)
{
    bool result = false;
    cTimer_adfbd0* t = reinterpret_cast<cTimer_adfbd0*>(mCaretTimer);
    if (on) {
        if (!t->IsRunning()) {
            t->StartPeriodic(mnCaretPeriod >> 1, IfOf_adfbd0(this));
            result = true;
        }
    } else {
        if (t->IsRunning()) {
            t->Stop();
            result = true;
        }
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bcbc5 score 17 (logic matches; register choice and instruction order differ)
uint32_t cGZWinTextEdit::CalculateVisibleWidth()
{
    uint32_t bar = 0;
    if (mpVScrollBar) {
        void* w = reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar)->AsIGZWin();
        bar = reinterpret_cast<cPrim_adfbd0*>(w)->GetW();
    }
    uint32_t margin = mnTextAreaX * 2;
    uint32_t w = GetW();
    if (w < margin + bar) {
        return 0;
    }
    return w - margin - bar;
}
#endif

// FUNCTION: 0x009bfe03
void cGZWinTextEdit::Slot17_adb6a8(uint32_t a)
{
    if (mnTextAreaX != static_cast<int32_t>(a)) {
        mnTextAreaX = a;
        mnTextAreaW = CalculateVisibleWidth();
        RecalculateAll();
        if (get_init_flag()) {
            InvalidateSelfAndParents();
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bf2e5 score 38 (logic matches; register choice and instruction order differ)
void cGZWinTextEdit::Fn009bf2e5(uint32_t a, uint32_t b)
{
    LineVec_adfbd0* v = reinterpret_cast<LineVec_adfbd0*>(&mpLineBegin);
    uint32_t n = v->mpEnd - v->mpBegin;
    if (b > n) {
        uint32_t pos = a + v->mpBegin[b - 2];
        v->Resize(b, pos);
    } else if (b > 1) {
        v->mpBegin[b - 1] = v->mpBegin[b - 2] + a;
    } else {
        *v->mpBegin = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bd6b4 score 39 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::Slot68_adf900(uint32_t a, uint32_t b)
{
    if (mpLineBegin == mpLineEnd) {
        mnInsertionLine = mnInsertionColumn = mnInsertionIndex = 0;
    } else {
        uint32_t line = a;
        if (line >= static_cast<uint32_t>(mpLineEnd - mpLineBegin)) {
            line = (mpLineEnd - mpLineBegin) - 1;
        }
        uint32_t count = Slot63_adf900(line);
        uint32_t col = b;
        if (col > count) {
            col = count;
        }
        mnInsertionColumn = col;
        mnInsertionLine = line;
        IfOf_adfbd0(this)->GetIndexFromLineAndColumn(line, col, &mnInsertionIndex);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009be0a9 score 39 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::Slot31_adf900()
{
    int32_t v = mnVisibleLineCount;
    int32_t f = mnFirstVisibleLine;
    if (static_cast<int32_t>(mpLineEnd - mpLineBegin) - v - f > 0) {
        if (static_cast<uint32_t>(f) < static_cast<uint32_t>((mpLineEnd - mpLineBegin) - v)) {
            mnFirstVisibleLine = v + f;
        } else {
            mnFirstVisibleLine = (mpLineEnd - mpLineBegin) - 1;
        }
        Fn009bdcd1(0);
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bdec9 score 4 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::ScrollLeft()
{
    uint32_t f = mnTextFlags;
    if (f & 0x200) {
        int32_t pos = mnHScrollChars;
        if (pos > 0) {
            mnHScrollChars -= GetPreviousCharLength(mText.data() + pos, pos, mnCodePage);
        }
    } else {
        if (!mpHScrollBar && (f & 2)) {
            return true;
        }
        if (mnHScrollPixels > 0) {
            mnHScrollPixels -= mnLineHeight;
        }
        Fn009bdcd1(0);
    }
    InvalidateSelfAndParents();
    return true;
}
#endif

// FUNCTION: 0x009bd9f2
bool cGZWinTextEdit::PlaySoundA(uint32_t a)
{
    uint32_t* p = &mnSoundIDs[a];
    if (*p != 0) {
        cSS_adfbd0* ss = Fn00913c9e();
        if (ss) {
            cIGZUnknown* obj = 0;
            if (ss->Create(5, 0x5b523ba4, reinterpret_cast<void**>(&obj), *p, 0, 0, 0)) {
                bool r = ss->Play(obj);
                if (obj) {
                    obj->Release();
                }
                return r;
            }
            if (obj) {
                obj->Release();
            }
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bd593 score 52 (logic matches; register choice and instruction order differ)
void cGZWinTextEdit::Slot61_adf900(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t* line = reinterpret_cast<uint32_t*>(a);
    uint32_t* col = reinterpret_cast<uint32_t*>(b);
    uint32_t i = 0;
    uint32_t n = mpLineEnd - mpLineBegin;
    if (n != 0 && !mText.empty() && c != 0) {
        --n;
        if (n != 0) {
            const uint32_t* p = mpLineBegin;
            do {
                if (!(p[0] > c)) {
                    if (p[1] > c) {
                        *line = i;
                        *col = c - mpLineBegin[i];
                        return;
                    }
                    ++i;
                    ++p;
                }
            } while (i < n);
        }
        if (mText[c - 1] == '\n') {
            *line = i;
            *col = 0;
        } else {
            *line = n;
            *col = c - mpLineBegin[n];
        }
    } else {
        *col = 0;
        *line = 0;
    }
}
#endif

// FUNCTION: 0x009bd1f6
bool cGZWinTextEdit::GZOnMouseMove(uint32_t a, uint32_t b, uint32_t)
{
    if (mnTextFlags & 1) {
        if (GZAmCapturing()) {
            uint32_t col;
            uint32_t line;
            Fn009bcc74();
            IfOf_adfbd0(this)->GetLineAndColumnFromPosition(&line, &col, a, b);
            Slot68_adf900(line, col);
            Fn009bd0af();
            uint32_t i = mnInsertionIndex;
            if (mnSelectionEnd != i) {
                mnSelectionEnd = i;
                InvalidateSelfAndParents();
            }
        } else {
            StopScrollTimer();
        }
    }
    return true;
}

// FUNCTION: 0x009bcdba
void cGZWinTextEdit::RemoveScrollBar(bool v, bool h)
{
    bool removed = false;
    if (v && mpVScrollBar) {
        removed = true;
        reinterpret_cast<cPrim_adfbd0*>(this)->ChildRemove(reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar)->AsIGZWin());
        reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar)->Release();
        mpVScrollBar = 0;
    }
    if (h && mpHScrollBar) {
        removed = true;
        reinterpret_cast<cPrim_adfbd0*>(this)->ChildRemove(reinterpret_cast<cScrollBar_adfbd0*>(mpHScrollBar)->AsIGZWin());
        reinterpret_cast<cScrollBar_adfbd0*>(mpHScrollBar)->Release();
        mpHScrollBar = 0;
    }
    if (removed) {
        RecalculateAll();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009bdb00 score 48 (logic matches; register choice and instruction order differ)
uint32_t cGZWinTextEdit::GetPixelWidthOfLongestLine(bool all)
{
    uint32_t best = 0;
    uint32_t i;
    uint32_t end;
    if (all) {
        end = mpLineEnd - mpLineBegin;
        i = 0;
    } else {
        i = mnFirstVisibleLine;
        end = mnVisibleLineCount + i;
    }
    for (; i < end; ++i) {
        const char* p = mText.data() + mpLineBegin[i];
        uint32_t w = reinterpret_cast<cFont_adfbd0*>(mpFont)->Slot48(p, Slot63_adf900(i));
        if (w > best) {
            best = w;
        }
    }
    return best;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bd0e1 score 44 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::DoMessage(uint32_t a)
{
    const uint32_t* m = reinterpret_cast<const uint32_t*>(a);
    switch (m[0]) {
    case 3:
        if (m[1] == 0x887113a3) {
            void* bar;
            int32_t* field;
            if (m[2] == 0) {
                bar = mpVScrollBar;
                field = &mnFirstVisibleLine;
            } else if (m[2] == 1) {
                bar = mpHScrollBar;
                field = &mnHScrollPixels;
            } else {
                break;
            }
            if (bar) {
                int32_t v = reinterpret_cast<cScrollBar_adfbd0*>(bar)->GetValue();
                if (v != *field) {
                    *field = v;
                    InvalidateSelfAndParents();
                }
            }
            return true;
        }
        break;
    case 0x631b56cc:
        ToggleCaretVisibility();
        return true;
    case 0x631b56cd:
        DoCursorScroll();
        return true;
    }
    return cGZWin::DoMessage(a);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bd278 score 44 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::Slot87_adf900(uint32_t a, uint32_t b)
{
    cImage_adfbd0* img = reinterpret_cast<cImage_adfbd0*>(a);
    if (img) {
        img->AddRef();
    }
    cImage_adfbd0** slot = reinterpret_cast<cImage_adfbd0**>(&mpScrollBarImageV);
    if (*slot) {
        (*slot)->Release();
    }
    *slot = img;
    *reinterpret_cast<Rect_adfbd0*>(mnScrollBarRectV) = *reinterpret_cast<Rect_adfbd0*>(b);
    int32_t* r = mnScrollBarRectV;
    if (img) {
        cScrollBar_adfbd0* bar = reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar);
        if (bar) {
            if (Fn007c1870()) {
                bar->SetImage(img->GetRect(), img, 0);
            } else {
                bar->SetImage(r, img, 0);
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bd2f9 score 44 (logic matches; register choice and instruction order differ)
bool cGZWinTextEdit::Slot88_adf900(uint32_t a, uint32_t b)
{
    cImage_adfbd0* img = reinterpret_cast<cImage_adfbd0*>(a);
    if (img) {
        img->AddRef();
    }
    cImage_adfbd0** slot = reinterpret_cast<cImage_adfbd0**>(&mpScrollBarImageH);
    if (*slot) {
        (*slot)->Release();
    }
    *slot = img;
    *reinterpret_cast<Rect_adfbd0*>(mnScrollBarRectH) = *reinterpret_cast<Rect_adfbd0*>(b);
    int32_t* r = mnScrollBarRectH;
    if (img) {
        cScrollBar_adfbd0* bar = reinterpret_cast<cScrollBar_adfbd0*>(mpHScrollBar);
        if (bar) {
            if (Fn007c1870()) {
                bar->SetImage(img->GetRect(), img, 0);
            } else {
                bar->SetImage(r, img, 0);
            }
        }
    }
    return true;
}
#endif

// STUB: 0x00910e18
uint32_t ConvertStringEncoding(const void* source, uint32_t length, int32_t fromCodePage, void* dest, uint32_t& destLength, int32_t toCodePage);

// STUB: 0x00910855
uint32_t LengthFromGlyphCount(const void* text, uint32_t glyphs, int32_t codePage);

// STUB: 0x009106a9
int32_t RZCharacterSize(const char* text, int32_t length, int32_t codePage);

// STUB: 0x0091169f
int32_t UTF16GetThaiCharType(uint32_t c);

#ifdef OB_DRAFTS
// CLOSE: 0x00911b3e score 51 (the original keeps a function-local set whose insert and find are out-of-line library calls at fixed addresses; this draft states the logic with the standard set)
bool UTF16IsThaiDecorationChar(uint32_t c)
{
    if (c < 0xe31 || c > 0xe4e) {
        return false;
    }
    static std::set<uint32_t> s;
    if (s.empty()) {
        s.insert(0xe38);
        s.insert(0xe39);
        s.insert(0xe3a);
        for (uint32_t i = 0xe48; i <= 0xe4b; ++i) {
            s.insert(i);
        }
        s.insert(0xe4c);
        s.insert(0xe4d);
        s.insert(0xe47);
        s.insert(0xe4e);
        s.insert(0xe34);
        s.insert(0xe31);
        s.insert(0xe36);
        s.insert(0xe35);
        s.insert(0xe37);
    }
    return s.find(c) != s.end();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00911cde score 34 (logic matches; branch layout of the early returns differs)
uint32_t UTF16ThaiCharGroupLength(const uint16_t* s, uint32_t n)
{
    if (n < 1) {
        return 0;
    }
    if (n < 2) {
        return 1;
    }
    if (s[1] != 0xe33) {
        if (!UTF16IsThaiDecorationChar(s[1])) {
            return 1;
        }
        if (n >= 3) {
            if (s[2] == 0xe33) {
                return 3;
            }
            if (UTF16IsThaiDecorationChar(s[2])) {
                return 3 + (s[3] == 0xe33);
            }
        }
    }
    return 2;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00911a40 score 60 (logic from the Mac switch; case grouping or block order differs)
uint32_t UTF16GetThaiCharLevel(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t t = UTF16GetThaiCharType(a);
    switch (t) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 0x10:
    case 0x11:
        if (a == 0xe33) {
            int32_t t2 = UTF16GetThaiCharType(b);
            if (t2 != 1 && t2 != 9) {
                return 0;
            }
        }
        return 4;
    case 6:
    case 7:
    case 8:
        if (UTF16GetThaiCharType(b) != 1) {
            return 0;
        }
        return 5;
    case 9:
    case 10:
    case 11: {
        int32_t t2 = UTF16GetThaiCharType(b);
        if (t == 9) {
            if (t2 >= 0xd && t2 <= 0xf) {
                return 2;
            }
            if (t2 == 1) {
                if (c != 0xe33) {
                    return 3;
                }
                return 2;
            }
            if (t2 == 6 || t2 == 7) {
                return 3;
            }
            return 0;
        }
        if (t == 10 || t == 11) {
            if (t2 == 1) {
                return 3;
            }
            if (t2 >= 6 && t2 <= 7) {
                return 3;
            }
            if (t2 >= 0xd && t2 <= 0xf) {
                return 2;
            }
            return 0;
        }
        return 3;
    }
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
        if (UTF16GetThaiCharType(b) != 1) {
            return 0;
        }
        return 3;
    default:
        return 1;
    }
}
#endif

// FUNCTION: 0x009115f0
uint16_t GetUTF16Character(const void* p, uint32_t& length, int32_t codePage)
{
    uint32_t out = 0;
    uint32_t n = length;
    if (n != 0) {
        const uint8_t* b = static_cast<const uint8_t*>(p);
        if (codePage == 0x10 || *b >= 0x7f) {
            uint32_t got = 1;
            length = ConvertStringEncoding(p, n, codePage, &out, got, 0x10);
        } else {
            return *b;
        }
    }
    return static_cast<uint16_t>(out);
}

// FUNCTION: 0x0091163f
uint16_t GetPreviousUTF16Character(const void* p, uint32_t& length, int32_t codePage)
{
    uint32_t out = 0;
    uint32_t n = length;
    if (n != 0) {
        const uint8_t* b = static_cast<const uint8_t*>(p);
        if (codePage == 0x10 || b[-1] >= 0x7f) {
            uint32_t got = 1;
            uint32_t prev = GetPreviousCharLength(p, n, codePage);
            length = prev;
            length = ConvertStringEncoding(b - prev, prev, codePage, &out, got, 0x10);
        } else {
            return b[-1];
        }
    }
    return static_cast<uint16_t>(out);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00912588 score 27 (logic matches; branch layout differs)
uint32_t GetComposedCharLength(const void* p, uint32_t n, int32_t codePage)
{
    if (n != 0) {
        const uint8_t* b = static_cast<const uint8_t*>(p);
        if (codePage == 8) {
            if (*b <= 0x7f) {
                return 1;
            }
            uint16_t buf[4];
            uint32_t got = 3;
            if (ConvertStringEncoding(p, n, 8, buf, got, 0x10) != 0 && static_cast<uint8_t>(Fn009100de(buf[0]))) {
                return LengthFromGlyphCount(p, UTF16ThaiCharGroupLength(buf, got), 8);
            }
        } else if (codePage == 0x10) {
            const uint16_t* w = static_cast<const uint16_t*>(p);
            if (static_cast<uint8_t>(Fn009100de(*w))) {
                return UTF16ThaiCharGroupLength(w, n);
            }
            return 1;
        }
        return RZCharacterSize(static_cast<const char*>(p), n, codePage);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00912632 score 30 (logic matches; branch layout differs)
uint32_t GetPreviousComposedCharLength(const void* p, uint32_t n, int32_t codePage)
{
    if (n != 0) {
        if (codePage == 8) {
            const uint8_t* q = static_cast<const uint8_t*>(p);
            if (q[-1] > 0x7f) {
                uint16_t ch;
                do {
                    uint32_t prev = GetPreviousCharLength(q, n, 8);
                    uint32_t got = 1;
                    q -= prev;
                    ConvertStringEncoding(q, prev, 8, &ch, got, 0x10);
                    if (!UTF16IsThaiDecorationChar(ch)) {
                        break;
                    }
                    n -= prev;
                } while (n != 0);
                return static_cast<const uint8_t*>(p) - q;
            }
            return 1;
        } else if (codePage == 0x10) {
            const uint16_t* r = static_cast<const uint16_t*>(p);
            if (r[-1] > 0x7f) {
                const uint16_t* q = r;
                do {
                    --q;
                    if (!UTF16IsThaiDecorationChar(*q)) {
                        break;
                    }
                } while (--n != 0);
                return r - q;
            }
            return 1;
        }
        return GetPreviousCharLength(p, n, codePage);
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bdf39 score 20 (logic matches; register choice and block order differ)
bool cGZWinTextEdit::ScrollRight()
{
    uint32_t f = mnTextFlags;
    if (f & 0x200) {
        uint32_t pos = mnHScrollChars;
        if (pos < mText.size()) {
            mnHScrollChars += RZCharacterSize(mText.data() + pos, mText.size() - pos, mnCodePage);
        }
    } else {
        if (!mpHScrollBar && (f & 2)) {
            return true;
        }
        int32_t w = mnTextAreaW;
        int32_t* px = &mnHScrollPixels;
        if (!(*px > w)) {
            *px = *px + mnLineHeight;
        }
        if (*px > w) {
            *px = w;
        }
        Fn009bdcd1(0);
    }
    InvalidateSelfAndParents();
    return true;
}
#endif

// FUNCTION: 0x009bda65
void cGZWinTextEdit::Fn009bda65()
{
    if (mText.empty()) {
        mnInsertionLine = mnInsertionColumn = mnInsertionIndex = mnSelectionStart = mnSelectionEnd = 0;
        return;
    }
    if (mnInsertionIndex > mText.size()) {
        mnInsertionIndex = mText.size();
    }
    IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, mnInsertionIndex);
    if (mnSelectionEnd > mText.size()) {
        mnSelectionEnd = mText.size();
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009be239 score 34 (logic matches; register choice and block order differ)
void cGZWinTextEdit::Slot60_adf900(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    int32_t* px = reinterpret_cast<int32_t*>(c);
    int32_t* py = reinterpret_cast<int32_t*>(d);
    uint32_t n = mpLineEnd - mpLineBegin;
    if (n != 0) {
        uint32_t line = a;
        if (line >= n) {
            line = n - 1;
        }
        uint32_t start = mpLineBegin[line];
        const char* text = mText.data() + start;
        uint32_t len = b;
        if (start + len >= mText.size()) {
            len = mText.size() - mpLineBegin[line];
        }
        *px = reinterpret_cast<cFont_adfbd0*>(mpFont)->Slot48(text, len) + mnTextAreaX;
        *py = static_cast<int32_t>(line - mnFirstVisibleLine) * mnLineHeight + mnTextAreaY;
    } else {
        *px = mnTextAreaX;
        *py = mnTextAreaY;
    }
    *px -= Fn009bddc2();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bd7fa score 12 (logic matches; register choice and block order differ)
void cGZWinTextEdit::Slot70_adf900(uint32_t a)
{
    int32_t cp = mnCodePage;
    if (cp != 8 && cp != 0x64) {
        mnInsertionIndex += a;
    } else {
        int32_t d = static_cast<int32_t>(a);
        if (d > 0) {
            do {
                mnInsertionIndex += RZCharacterSize(mText.data() + mnInsertionIndex, mText.size() - mnInsertionIndex, mnCodePage);
            } while (--d != 0);
        } else if (d < 0) {
            d = -d;
            do {
                mnInsertionIndex -= GetPreviousCharLength(mText.data() + mnInsertionIndex, mnInsertionIndex, mnCodePage);
            } while (--d != 0);
        }
    }
    if (static_cast<int32_t>(mnInsertionIndex) < 0) {
        mnInsertionIndex = 0;
    } else if (mnInsertionIndex > mText.size()) {
        mnInsertionIndex = mText.size();
    }
    IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, mnInsertionIndex);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bd71a score 22 (logic matches; register choice and block order differ)
void cGZWinTextEdit::IncrementInsertionPositionByComposedCharacter(uint32_t a)
{
    int32_t cp = mnCodePage;
    if (cp != 8 && cp < 0x64) {
        mnInsertionIndex += a;
    } else {
        int32_t d = static_cast<int32_t>(a);
        if (d > 0) {
            do {
                mnInsertionIndex += GetComposedCharLength(mText.data() + mnInsertionIndex, mText.size() - mnInsertionIndex, mnCodePage);
            } while (--d != 0);
        }
        if (d < 0) {
            d = -d;
            do {
                mnInsertionIndex -= GetPreviousComposedCharLength(mText.data() + mnInsertionIndex, mnInsertionIndex, mnCodePage);
            } while (--d != 0);
        }
    }
    if (static_cast<int32_t>(mnInsertionIndex) < 0) {
        mnInsertionIndex = 0;
    } else if (mnInsertionIndex > mText.size()) {
        mnInsertionIndex = mText.size();
    }
    IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, mnInsertionIndex);
}
#endif

// FUNCTION: 0x009bd003
bool cGZWinTextEdit::Slot04_ae1d24()
{
    reinterpret_cast<AutoRef_adfbd0*>(&mpFont)->Assign(0);
    cTimer_adfbd0* t = reinterpret_cast<cTimer_adfbd0*>(mCaretTimer);
    if (t->IsRunning()) {
        t->Stop();
    }
    t = reinterpret_cast<cTimer_adfbd0*>(mScrollTimer);
    if (t->IsRunning()) {
        t->Stop();
    }
    void** p = &mpVScrollBar;
    if (*p) {
        reinterpret_cast<cIGZUnknown*>(*p)->Release();
        *p = 0;
    }
    p = &mpHScrollBar;
    if (*p) {
        reinterpret_cast<cIGZUnknown*>(*p)->Release();
        *p = 0;
    }
    p = &mpScrollBarImageV;
    if (*p) {
        reinterpret_cast<cIGZUnknown*>(*p)->Release();
        *p = 0;
    }
    p = &mpScrollBarImageH;
    if (*p) {
        reinterpret_cast<cIGZUnknown*>(*p)->Release();
        *p = 0;
    }
    p = &mp28C;
    if (*p) {
        reinterpret_cast<cIGZUnknown*>(*p)->Release();
        *p = 0;
    }
    return cGZWin::Slot04_ae1d24();
}

#ifdef OB_DRAFTS
// CLOSE: 0x009be179 score 61 (logic matches; register choice and block order differ)
void cGZWinTextEdit::Slot58_adf900(uint32_t a, uint32_t b, uint32_t c)
{
    c += Fn009bddc2() - mnTextAreaX;
    if (mpLineBegin != mpLineEnd && static_cast<int32_t>(c) > 0) {
        uint32_t* col = reinterpret_cast<uint32_t*>(b);
        *col = 0;
        uint32_t count = Slot63_adf900(a);
        const char* start = mText.data() + mpLineBegin[a];
        const char* end = mText.data() + mText.size();
        if (*col < count) {
            for (;;) {
                uint32_t step = RZCharacterSize(start + *col, end - (start + *col), mnCodePage);
                uint32_t w = reinterpret_cast<cFont_adfbd0*>(mpFont)->Slot48(start, *col + step);
                if (static_cast<int32_t>(c) <= static_cast<int32_t>(w)) {
                    break;
                }
                *col += step;
                if (!(*col < count)) {
                    *col = count;
                    break;
                }
            }
        } else {
            *col = count;
        }
    } else {
        *reinterpret_cast<uint32_t*>(b) = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009be7af score 40 (logic matches; register choice and block order differ)
bool cGZWinTextEdit::TestForPossibleScrollBarAdditionOrRemoval()
{
    if (mnTextFlags & 8) {
        if ((mpLineEnd - mpLineBegin) > static_cast<int32_t>(mnVisibleLineCount) && mnTextAreaW != 0 && mnTextAreaH != 0) {
            if (!mpVScrollBar) {
                AddScrollBar(true, false);
            }
        } else if (mpVScrollBar) {
            RemoveScrollBar(true, false);
        }
    }
    uint32_t f = mnTextFlags;
    if ((f & 4) && !(f & 2)) {
        int32_t w = GetPixelWidthOfLongestLine(true);
        if (w > mnTextAreaW && mnTextAreaW != 0 && mnTextAreaH != 0) {
            if (!mpHScrollBar) {
                AddScrollBar(false, true);
            }
        } else if (mpHScrollBar) {
            RemoveScrollBar(false, true);
        }
    }
    return true;
}
#endif

// FUNCTION: 0x009bccce
void cGZWinTextEdit::DoCursorScroll()
{
    if (GZAmCapturing()) {
        int32_t w = GetW();
        int32_t h = GetH();
        int32_t x;
        int32_t y;
        reinterpret_cast<cWinMgr_adfbd0*>(field4)->GetCursorPoint(this, &x, &y);
        if (y < -2) {
            if (Slot26_adf900()) {
                GZOnMouseMove(x, mnLineHeight >> 1, 0);
            }
        } else if (y >= h + 2) {
            if (Slot27_adf900()) {
                GZOnMouseMove(x, h - (mnLineHeight >> 1), 0);
            }
        } else if (x < -2) {
            if (ScrollLeft()) {
                GZOnMouseMove(0, y, 0);
            }
        } else if (x >= w + 2) {
            if (ScrollRight()) {
                GZOnMouseMove(GetW(), y, 0);
            }
        }
    }
}

// FUNCTION: 0x009bdcd1
void cGZWinTextEdit::Fn009bdcd1(bool update)
{
    if (mpVScrollBar) {
        if (update && mnVisibleLineCount != 0) {
            int32_t max = Slot35_adf900() - mnVisibleLineCount;
            if (max < 0) {
                max = 0;
            }
            reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar)->SetRange(0, max);
            reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar)->SetPage(max, Slot35_adf900() / static_cast<uint32_t>(mnVisibleLineCount) + 1);
        }
        reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar)->SetValue(mnFirstVisibleLine);
    }
    if (mpHScrollBar) {
        if (update && mnVisibleLineCount != 0) {
            int32_t total = GetPixelWidthOfLongestLine(true);
            int32_t max = total - mnTextAreaW;
            if (max < 0) {
                max = 0;
            }
            reinterpret_cast<cScrollBar_adfbd0*>(mpHScrollBar)->SetRange(0, max);
            reinterpret_cast<cScrollBar_adfbd0*>(mpHScrollBar)->SetPage(max, total / mnTextAreaW + 1);
        }
        reinterpret_cast<cScrollBar_adfbd0*>(mpHScrollBar)->SetValue(mnHScrollPixels);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009be6ce score 44 (logic matches; register choice and block order differ)
bool cGZWinTextEdit::Fn009be6ce()
{
    if (mText.empty()) {
        return false;
    }
    uint32_t i = mnInsertionIndex;
    const char* t = mText.data();
    bool scan = true;
    if (Fn009bc5cc(static_cast<uint8_t>(t[i]))) {
        if (i > 0 && !Fn009bc5cc(static_cast<uint8_t>(t[i - 1]))) {
            mnInsertionIndex = mnSelectionEnd = mnSelectionStart = i - 1;
        } else {
            scan = false;
        }
    }
    if (scan) {
        while (mnSelectionStart > 0) {
            uint32_t s = mnSelectionStart;
            if (Fn009bc5cc(static_cast<uint8_t>(t[s - 1]))) {
                break;
            }
            mnSelectionStart = s - 1;
        }
        while (mnSelectionEnd < mText.size()) {
            uint32_t s = mnSelectionEnd;
            if (Fn009bc5cc(static_cast<uint8_t>(t[s]))) {
                break;
            }
            mnSelectionEnd = mnInsertionIndex = s + 1;
        }
        Fn009bda65();
    }
    PutInsertionPositionInView();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009be862 score 15 (logic matches; register choice and block order differ)
bool cGZWinTextEdit::GZOnMouseDownL(uint32_t a, uint32_t b, uint32_t c)
{
    if (mnTextFlags & 1) {
        uint32_t col;
        uint32_t line;
        bool dbl = false;
        cRZTimer_adfbd0* timer = reinterpret_cast<cRZTimer_adfbd0*>(mTimer);
        if (timer->IsTimerRunning() && timer->GetElapsedTime() < mn220) {
            dbl = true;
            timer->Reset();
        } else {
            timer->Restart();
        }
        GZSetCapture();
        IfOf_adfbd0(this)->GetLineAndColumnFromPosition(&line, &col, a, b);
        Slot68_adf900(line, col);
        Fn009bd0af();
        uint32_t i = mnInsertionIndex;
        mnSelectionEnd = i;
        if (!(c & 1)) {
            mnSelectionStart = i;
        }
        if (dbl) {
            Fn009be6ce();
        }
        InvalidateSelfAndParents();
        mn170 = -1;
    } else {
        reinterpret_cast<cPrim_adfbd0*>(this)->SendMsg5(field4c, 0x9b1552d6, IfOf_adfbd0(this), a, b);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bd89d score 26 (logic matches; register choice and block order differ)
void cGZWinTextEdit::Slot71_adf900(uint32_t a)
{
    if (mText.size() != 0) {
        int32_t d = static_cast<int32_t>(a);
        if (d > 0) {
            int32_t count = 0;
            while (count < d) {
                int32_t last = mText.size() - 1;
                int32_t i = mnInsertionIndex;
                if (i >= last) {
                    mnInsertionIndex = mText.size();
                    break;
                }
                const char* t = mText.data();
                bool found = false;
                do {
                    if (Fn009bc5cc(static_cast<uint8_t>(t[i])) && !Fn009bc5cc(static_cast<uint8_t>(t[i + 1]))) {
                        found = true;
                        break;
                    }
                    ++i;
                } while (i < last);
                if (!found) {
                    mnInsertionIndex = mText.size();
                    break;
                }
                ++i;
                ++count;
                mnInsertionIndex = i;
            }
        } else if (d < 0) {
            int32_t count = 0;
            while (count > d) {
                int32_t i = mnInsertionIndex - 1;
                if (i <= 0) {
                    mnInsertionIndex = 0;
                    break;
                }
                const char* t = mText.data();
                bool found = false;
                do {
                    if (Fn009bc5cc(static_cast<uint8_t>(t[i - 1])) && !Fn009bc5cc(static_cast<uint8_t>(t[i]))) {
                        found = true;
                        break;
                    }
                    --i;
                } while (i > 0);
                if (!found) {
                    mnInsertionIndex = 0;
                    break;
                }
                --count;
                mnInsertionIndex = i;
            }
        }
        if (static_cast<int32_t>(mnInsertionIndex) < 0) {
            mnInsertionIndex = 0;
        } else if (mnInsertionIndex > mText.size()) {
            mnInsertionIndex = mText.size();
        }
        IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, mnInsertionIndex);
    }
}
#endif

// FUNCTION: 0x009bf335
uint32_t cGZWinTextEdit::Fn009bf335(char* text, void* pLength)
{
    uint32_t* length = static_cast<uint32_t*>(pLength);
    uint32_t count = 0;
    if (mnTextFlags & 0x200) {
        uint32_t n = *length;
        cRZString kept;
        uint32_t pos = 0;
        if (n > pos) {
            do {
                const char* q = text + pos;
                uint32_t step = RZCharacterSize(q, n - pos, mnCodePage);
                if (*q == '\n') {
                    count += step;
                } else {
                    kept.append(q, step);
                }
                pos += step;
            } while (pos < n);
            if (count != 0) {
                strncpy(text, kept.data(), *length);
                *length = kept.size();
            }
        }
    }
    return count;
}

// FUNCTION: 0x009bf578
uint32_t cGZWinTextEdit::Fn009bf578(void* p)
{
    cRZString* s = static_cast<cRZString*>(p);
    uint32_t n = s->size();
    uint32_t r = Fn009bf335(const_cast<char*>(s->data()), &n);
    if (n != s->size()) {
        s->resize(n, 0);
    }
    return r;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009be614 score 37 (logic matches; register choice and block order differ)
uint32_t cGZWinTextEdit::FixBadCharacterComposition(void* dstp, void* srcp, uint32_t position)
{
    cRZString* dst = static_cast<cRZString*>(dstp);
    cRZString* src = static_cast<cRZString*>(srcp);
    uint32_t remaining = position;
    uint32_t removed = 0;
    uint32_t i = 0;
    uint16_t previous = GetPreviousUTF16Character(src->data() + position, remaining, mnCodePage);
    while (i < dst->size()) {
        remaining = dst->size() - i;
        uint16_t current = GetUTF16Character(dst->data() + i, remaining, mnCodePage);
        if (remaining != 0 && UTF16GetThaiCharLevel(current, previous, 0) != 0) {
            i += remaining;
            previous = current;
        } else {
            if (remaining == 0) {
                remaining = dst->size() - i;
            }
            removed += remaining;
            dst->erase(i, remaining);
        }
    }
    return removed;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c068d score 28 (logic matches; register choice and block order differ)
bool cGZWinTextEdit::AddUndoRecordForTextInsertion(void* position, uint32_t a, char*, uint32_t b, char* old, uint32_t oldLength)
{
    if (!(mnTextFlags & 0x100)) {
        return false;
    }
    UndoVec_adfbd0* undo = reinterpret_cast<UndoVec_adfbd0*>(mUndoVec);
    uint32_t n = undo->mpEnd - undo->mpBegin;
    if (n >= mnMaxUndoLevels) {
        undo->Erase(undo->mpBegin, undo->mpBegin + (n >> 2));
    }
    UndoRecord_adfbd0 record;
    record.mbIsInsert = 1;
    record.mnPosition = a;
    record.mnLength = b;
    if (old && oldLength) {
        record.mnTextPosition = a;
        record.mbHasText = true;
        record.mText.assign(old, old + oldLength);
    } else {
        record.mnTextPosition = 0;
        record.mbHasText = false;
    }
    record.mInsertion = *static_cast<Five_adfbd0*>(position);
    undo->PushBack(record);
    UndoVec_adfbd0* redo = reinterpret_cast<UndoVec_adfbd0*>(mRedoVec);
    redo->Erase(redo->mpBegin, redo->mpEnd);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bfcef score 39 (draft from the asm and the Mac function)
void cGZWinTextEdit::Slot77_adf900(uint32_t a)
{
    uint32_t old = mnTextFlags;
    if (a != old) {
        uint32_t changed = old ^ a;
        mnTextFlags = a;
        if (a & 0x2000) {
            mnTextFlags = (a & ~6u) | 0x200;
        }
        if (mnTextFlags & 0x200) {
            mnTextFlags &= ~6u;
        }
        if (mnTextFlags & 2) {
            mnTextFlags &= ~4u;
        }
        if (get_init_flag()) {
            if (changed & 0x41) {
                bool on = false;
                if (reinterpret_cast<cPrim_adfbd0*>(this)->IsVisible() && (mnTextFlags & 0x40) && (mnTextFlags & 1)) {
                    on = true;
                }
                StartCaretTimer(on);
            }
            if (changed & 0xb) {
                RecalculateAll();
                InvalidateSelfAndParents();
                if (a & 1) {
                    reinterpret_cast<cPrim_adfbd0*>(this)->SetCursorObject(reinterpret_cast<cCursorMgr_adfbd0*>(Fn0099bf14())->GetCursor(3, 0));
                } else {
                    SetCursor(0, 0);
                }
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bfb9c score 6 (draft from the asm and the Mac function)
bool cGZWinTextEdit::Slot03_ae1d24()
{
    if (!get_init_flag()) {
        cGZWin::Slot03_ae1d24();
        if (!mpFont) {
            cWCM_adfbd0* wcm = Fn00913c72();
            if (wcm) {
                uint32_t id = mnFontStyle;
                if (!id) {
                    id = 0x68963c4c;
                }
                void* font = wcm->GetFont(id);
                if (!font) {
                    font = wcm->GetFont(0x68963c4c);
                }
                IfOf_adfbd0(this)->SetFont(font);
            }
        }
        LineVec_adfbd0* lines = reinterpret_cast<LineVec_adfbd0*>(&mpLineBegin);
        lines->Reserve(0x10);
        mnTextAreaW = CalculateVisibleWidth();
        if (mnTextFlags & 1) {
            reinterpret_cast<cPrim_adfbd0*>(this)->SetCursorObject(reinterpret_cast<cCursorMgr_adfbd0*>(Fn0099bf14())->GetCursor(3, 0));
        }
        if (reinterpret_cast<cPrim_adfbd0*>(this)->IsVisible() && (mnTextFlags & 0x40) && (mnTextFlags & 1)) {
            StartCaretTimer(true);
        }
        mnCodePage = Fn00940da8();
        if (!mp28C) {
            cSysServPtrClipboard_adfbd0 service;
            mp28C = service.mpService;
            if (service.mpService) {
                reinterpret_cast<cIGZUnknown*>(service.mpService)->AddRef();
            }
        }
        RecalculateAll();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c027e score 80 (draft from the asm and the Mac function)
bool cGZWinTextEdit::Slot83_adf900()
{
    if (!(mnTextFlags & 0x100)) {
        return false;
    }
    UndoVec_adfbd0* undo = reinterpret_cast<UndoVec_adfbd0*>(mUndoVec);
    if (undo->mpBegin == undo->mpEnd) {
        return false;
    }
    UndoRecord_adfbd0* last = undo->mpEnd - 1;
    UndoRecord_adfbd0 redo;
    if (last->mbHasText) {
        redo.mnPosition = last->mnTextPosition;
        redo.mbIsInsert = 1;
        redo.mnLength = last->mText.size();
    }
    if (last->mbIsInsert) {
        redo.mnTextPosition = last->mnPosition;
        redo.mbHasText = true;
        redo.mText.assign(mText.data() + last->mnPosition, mText.data() + last->mnPosition + last->mnLength);
    }
    redo.mInsertion = *reinterpret_cast<Five_adfbd0*>(&mnInsertionLine);
    reinterpret_cast<UndoVec_adfbd0*>(mRedoVec)->PushBack(redo);
    if (last->mbIsInsert) {
        mText.erase(last->mnPosition, last->mnLength);
    }
    if (last->mbHasText) {
        mText.insert(last->mnTextPosition, static_cast<const std::string&>(last->mText));
    }
    *reinterpret_cast<Five_adfbd0*>(&mnInsertionLine) = last->mInsertion;
    undo->mpEnd -= 1;
    undo->mpEnd->Destroy(0);
    RecalculateAll();
    PutInsertionPositionInView();
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c0396 score 80 (draft from the asm and the Mac function)
bool cGZWinTextEdit::Slot84_adf900()
{
    if (!(mnTextFlags & 0x100)) {
        return false;
    }
    UndoVec_adfbd0* redoVec = reinterpret_cast<UndoVec_adfbd0*>(mRedoVec);
    if (redoVec->mpBegin == redoVec->mpEnd) {
        return false;
    }
    UndoRecord_adfbd0* last = redoVec->mpEnd - 1;
    UndoRecord_adfbd0 undo;
    if (last->mbHasText) {
        undo.mnPosition = last->mnTextPosition;
        undo.mbIsInsert = 1;
        undo.mnLength = last->mText.size();
    }
    if (last->mbIsInsert) {
        undo.mnTextPosition = last->mnPosition;
        undo.mbHasText = true;
        undo.mText.assign(mText.data() + last->mnPosition, mText.data() + last->mnPosition + last->mnLength);
    }
    undo.mInsertion = *reinterpret_cast<Five_adfbd0*>(&mnInsertionLine);
    reinterpret_cast<UndoVec_adfbd0*>(mUndoVec)->PushBack(undo);
    if (last->mbIsInsert) {
        mText.erase(last->mnPosition, last->mnLength);
    }
    if (last->mbHasText) {
        mText.insert(last->mnTextPosition, static_cast<const std::string&>(last->mText));
    }
    *reinterpret_cast<Five_adfbd0*>(&mnInsertionLine) = last->mInsertion;
    redoVec->mpEnd -= 1;
    redoVec->mpEnd->Destroy(0);
    RecalculateAll();
    PutInsertionPositionInView();
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c0996 score 113 (draft from the asm and the Mac function)
bool cGZWinTextEdit::GZOnCharacter(uint32_t a)
{
    reinterpret_cast<cKbd_adfbd0*>(field8)->K3(0x11);
    reinterpret_cast<cKbd_adfbd0*>(field8)->K3(0x12);
    char* pc = reinterpret_cast<char*>(&a);
    if (mnTextFlags & 1) {
        if (*pc == '\r') {
            *pc = '\n';
        }
        if (static_cast<uint8_t>(*pc) >= 0x20 || *pc == '\n') {
            int32_t cp = mnCodePage;
            if (cp == 8 || cp >= 0x64) {
                std::string& s = mStr130;
                if (s.empty() && IsLeadByte(*pc, cp)) {
                    s.push_back(*pc);
                    return true;
                }
                s.push_back(*pc);
                if (s.size() < GetFollowByteCount(s[0], cp) + 1) {
                    return true;
                }
            } else {
                mStr130.assign(1, *pc);
            }
            if (!GZAmCapturing()) {
                InsertTextHighLevel(&mStr130);
            }
        } else {
            return true;
        }
    }
    mStr130.erase(0, std::string::npos);
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bff6e score 73 (draft from the asm and the Mac function)
void cGZWinTextEdit::InitializeMemberVariables(uint32_t a)
{
    mcPasswordChar = '*';
    mnCodePage = Fn00940da8();
    mStr144 = cRZString(std::string(1, '-'));
    mn1D0 = -1;
    mn170 = -1;
    mnLineHeight = 1;
    mnTextAreaX = 5;
    mnTextAreaY = 0;
    mnTextAreaW = 0;
    mnTextAreaH = 0;
    mnVisibleLineCount = 0;
    mnFirstVisibleLine = 0;
    mnHScrollChars = 0;
    mnHScrollPixels = 0;
    mpBackgroundImage = 0;
    mbBackgroundTile = true;
    mnMaxUndoLevels = 0x4000;
    mbCaretVisible = false;
    mnCaretColor = 0xff000000;
    mn1C8 = 0xff000000;
    reinterpret_cast<AutoRef_adfbd0*>(&mpFont)->Assign(0);
    mnFontStyle = 0;
    mpVScrollBar = 0;
    mpHScrollBar = 0;
    mpScrollBarImageV = 0;
    mpScrollBarImageH = 0;
    mnScrollBarRectV[0] = mnScrollBarRectV[1] = mnScrollBarRectV[2] = mnScrollBarRectV[3] = 0;
    mnScrollBarRectH[0] = mnScrollBarRectH[1] = mnScrollBarRectH[2] = mnScrollBarRectH[3] = 0;
    mnSelectionEnd = mnSelectionStart = mnInsertionIndex = mnInsertionColumn = mnInsertionLine = 0;
    mnHighlightFillColor = 0xff000000;
    SetFillColor(0xff, 0xff, 0xff);
    Slot17_adf900(0);
    Slot17_adf900(1);
    Slot17_adf900(2);
    Slot17_adf900(3);
    Slot17_adf900(4);
    Slot17_adf900(5);
    reinterpret_cast<cRZTimer_adfbd0*>(mTimer)->SetUnits(4);
    mnCaretPeriod = 1000;
    mn220 = 500;
    reinterpret_cast<cTimer_adfbd0*>(mCaretTimer)->SetCallbackFunction(CaretTimerCallback_adfbd0, this);
    reinterpret_cast<cTimer_adfbd0*>(mScrollTimer)->SetCallbackFunction(ScrollTimerCallback_adfbd0, this);
    mp28C = 0;
    Slot77_adf900(a);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bf3e0 score 86 (draft from the asm; the standard string calls and the interface views make the instruction shapes differ)
void cGZWinTextEdit::Fn009bf3e0(uint32_t line)
{
    if (mpFont) {
        LineVec_adfbd0* v = reinterpret_cast<LineVec_adfbd0*>(&mpLineBegin);
        uint32_t n = v->mpEnd - v->mpBegin;
        if (line > n + 1) {
            line = 0;
        }
        if (mText.empty()) {
            v->Erase(v->mpBegin, v->mpEnd);
            mnInsertionLine = mnInsertionColumn = mnInsertionIndex = 0;
        } else {
            const char* p;
            if (line > 0) {
                p = mText.data() + v->mpBegin[line];
            } else {
                if (v->mpBegin == v->mpEnd) {
                    Fn009be9ed();
                }
                p = mText.data();
            }
            const char* end = mText.data() + mText.size();
            ++line;
            while (p < end) {
                uint32_t len;
                if (mnTextAreaW != 0 && !(mnTextFlags & 0x200)) {
                    if (mnTextFlags & 2) {
                        len = reinterpret_cast<cFont_adfbd0*>(mpFont)->Slot41(p, end - p, mnTextAreaW, 0, 2);
                    } else {
                        const char* q = p;
                        while (q < end && *q != '\n') {
                            ++q;
                        }
                        if (q != end && *q == '\n') {
                            ++q;
                        }
                        len = q - p;
                    }
                } else {
                    len = end - p;
                }
                p += len;
                if (p >= end && p[-1] != '\n') {
                    break;
                }
                ++line;
                Fn009bf2e5(len, line);
            }
            if (line != static_cast<uint32_t>(v->mpEnd - v->mpBegin)) {
                v->Truncate(line);
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bf8a8 score 81 (draft from the asm; the standard string calls and the interface views make the instruction shapes differ)
uint32_t cGZWinTextEdit::Slot55_adf900(uint32_t index, uint32_t count, uint32_t out)
{
    std::string& s = mText;
    if (index >= s.size()) {
        return 0;
    }
    if (index + count > s.size()) {
        count = s.size() - index;
    }
    cIGZString* o = reinterpret_cast<cIGZString*>(out);
    if (o) {
        o->FromChar(s.data() + index, count);
    }
    s.erase(index, count);
    mnInsertionIndex = index;
    IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, index);
    Fn009bf3e0(mnInsertionLine - 1);
    Fn009bdcd1(true);
    int32_t n = mnVisibleLineCount - static_cast<int32_t>(mpLineEnd - mpLineBegin) + mnFirstVisibleLine;
    if (n > 0 && mnFirstVisibleLine > 0) {
        mnFirstVisibleLine -= (mnFirstVisibleLine < n) ? mnFirstVisibleLine : n;
        Fn009bdcd1(false);
    }
    PutInsertionPositionInView();
    TestForPossibleScrollBarAdditionOrRemoval();
    InvalidateSelfAndParents();
    return count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bf776 score 105 (draft from the asm; the standard string calls and the interface views make the instruction shapes differ)
bool cGZWinTextEdit::Slot52_adf900(uint32_t index, uint32_t single, uint32_t out)
{
    std::string& s = mText;
    if (index >= s.size()) {
        index = s.size() - 1;
    }
    uint32_t len;
    if (*reinterpret_cast<bool*>(&single)) {
        len = RZCharacterSize(s.data() + index, s.size() - index, mnCodePage);
    } else {
        len = GetComposedCharLength(s.data() + index, s.size() - index, mnCodePage);
    }
    cIGZString* o = reinterpret_cast<cIGZString*>(out);
    if (o) {
        o->FromChar(s.data() + index, len);
    }
    s.erase(index, len);
    if (*reinterpret_cast<bool*>(&single)) {
        Slot70_adf900(0xffffffff);
    }
    mnInsertionIndex = index;
    IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, index);
    Fn009bf3e0(mnInsertionLine - 1);
    Fn009bdcd1(true);
    IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, mnInsertionIndex);
    int32_t n = mnFirstVisibleLine - static_cast<int32_t>(mpLineEnd - mpLineBegin) + mnVisibleLineCount;
    if (n > 0 && mnFirstVisibleLine > 0) {
        mnFirstVisibleLine -= (mnFirstVisibleLine < n) ? mnFirstVisibleLine : n;
        Fn009bdcd1(false);
    }
    PutInsertionPositionInView();
    TestForPossibleScrollBarAdditionOrRemoval();
    if (static_cast<uint32_t>(mpLineEnd - mpLineBegin) <= static_cast<uint32_t>(mnVisibleLineCount)) {
        mnFirstVisibleLine = 0;
        Fn009bdcd1(false);
    }
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bf5b7 score 191 (draft from the asm; the standard string calls and the interface views make the instruction shapes differ)
uint32_t cGZWinTextEdit::Slot51_adf900(uint32_t text, uint32_t len, uint32_t index)
{
    std::string& s = mText;
    if (index > s.size()) {
        index = s.size();
    }
    cRZString tmp(reinterpret_cast<const char*>(text), len);
    uint32_t removed = Fn009bf578(&tmp);
    removed += FixBadCharacterComposition(&tmp, &mText, index);
    if (removed) {
        PlaySoundA(0);
    }
    len = tmp.size();
    if (len != 0) {
        uint32_t max = mn1D0;
        int32_t cp = mnCodePage;
        if (s.size() + len > max) {
            if (cp != 8 && cp != 0x64) {
                len = max - s.size();
            } else {
                uint32_t n = 0;
                if (s.size() < max) {
                    do {
                        n += RZCharacterSize(reinterpret_cast<const char*>(text) + n, len, cp);
                    } while (n + s.size() < max);
                }
                len = n;
            }
            PlaySoundA(1);
        }
        if (mpLineBegin == mpLineEnd) {
            Fn009be9ed();
        }
        s.insert(index, tmp.data(), len);
        Slot70_adf900(RZCharacterCount(tmp.data(), len, mnCodePage));
        if (Slot67_adc8d8(1)) {
            bool update = true;
            if (!(mnTextFlags & 2) && index >= s.size()) {
                update = false;
                for (uint32_t i = 0; i < len; ++i) {
                    if (tmp.data()[i] == '\n') {
                        update = true;
                        break;
                    }
                }
            }
            if (update) {
                uint32_t line;
                uint32_t col;
                IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&line, &col, index);
                Fn009bf3e0(line - 1);
                IfOf_adfbd0(this)->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, mnInsertionIndex);
                Fn009bdcd1(true);
            }
            UpdateScrollBarsAndWindowPosition();
        }
    }
    return len;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009be302 score 72 (draft from the asm and the Mac function; logic follows them, the instruction shapes differ)
void cGZWinTextEdit::PutInsertionPositionInView()
{
    bool changed = false;
    uint32_t line = mnInsertionLine;
    uint32_t first = mnFirstVisibleLine;
    if (line < first) {
        mnFirstVisibleLine = line;
        changed = true;
    } else if (line >= first + mnVisibleLineCount) {
        mnFirstVisibleLine = line - mnVisibleLineCount + 1;
        changed = true;
    }
    void* hbar = mpHScrollBar;
    if (hbar || !(mnTextFlags & 2) || (mnTextFlags & 0x200)) {
        if (mnTextFlags & 0x200) {
            uint32_t col = mnInsertionColumn;
            if (mnHScrollChars > static_cast<int32_t>(col) && static_cast<uint32_t>(mnHScrollChars) > col) {
                mnHScrollChars = col;
            } else {
                int32_t w = reinterpret_cast<cFont_adfbd0*>(mpFont)->Slot48(mText.data(), col);
                if (w - static_cast<int32_t>(Fn009bddc2()) > mnTextAreaW) {
                    while (static_cast<uint32_t>(mnHScrollChars) < mText.size()) {
                        mnHScrollChars += RZCharacterSize(mText.data() + mnHScrollChars, mText.size() - mnHScrollChars, mnCodePage);
                        if (w - static_cast<int32_t>(Fn009bddc2()) < (mnTextAreaW * 3) / 4) {
                            break;
                        }
                    }
                }
            }
            changed = true;
        } else if (hbar || !(mnTextFlags & 2)) {
            int32_t px = reinterpret_cast<cFont_adfbd0*>(mpFont)->Slot48(mText.data() + mpLineBegin[mnInsertionLine], mnInsertionColumn);
            px -= Fn009bddc2();
            if (px < 0) {
                mnHScrollPixels += px;
                changed = true;
            } else if (px >= mnTextAreaW) {
                mnHScrollPixels += px - mnTextAreaW;
                changed = true;
            }
        }
    }
    if (changed) {
        Fn009bdcd1(false);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bf162 score 139 (draft from the asm and the Mac function; logic follows them, the instruction shapes differ)
void cGZWinTextEdit::Slot59_adf900(uint32_t pLine, uint32_t pCol, uint32_t xArg, uint32_t yArg)
{
    int32_t x = xArg;
    int32_t y = yArg;
    int32_t cp = mnCodePage;
    cRZString* str = &mText;
    if (mnTextFlags & 0x2000) {
        uint32_t n = RZCharacterCount(mText.data(), mText.size(), cp);
        if (mStrF0.size() != n) {
            mStrF0.resize(n, mcPasswordChar);
        }
        str = &mStrF0;
        cp = 0;
    }
    if (y < 0) {
        x = 0;
        y = 0;
    }
    if (x < 0) {
        x = 0;
    }
    int32_t px = x - mnTextAreaX;
    px += Fn009bddc2();
    uint32_t* line = reinterpret_cast<uint32_t*>(pLine);
    uint32_t* col = reinterpret_cast<uint32_t*>(pCol);
    *line = mnFirstVisibleLine + static_cast<uint32_t>(y) / mnLineHeight;
    if (*line >= static_cast<uint32_t>(mpLineEnd - mpLineBegin)) {
        *line = (mpLineEnd - mpLineBegin) - 1;
    }
    if (str->empty()) {
        *col = 0;
        *line = 0;
        return;
    }
    const char* p = str->data() + mpLineBegin[*line];
    uint32_t count = Slot63_adf900(*line);
    uint32_t previous = 0;
    uint32_t step = 0;
    *col = 0;
    if (count != 0) {
        do {
            step = RZCharacterSize(p + *col, str->size() - mpLineBegin[*line] - *col, cp);
            *col += step;
            uint32_t w = reinterpret_cast<cFont_adfbd0*>(mpFont)->Slot48(p, *col);
            if (px < static_cast<int32_t>(w)) {
                if (px - static_cast<int32_t>(previous) - 1 < static_cast<int32_t>(w) - px) {
                    *col -= step;
                }
                if (mnTextFlags & 0x2000) {
                    *col = LengthFromGlyphCount(mText.data(), *col, mnCodePage);
                }
                return;
            }
            previous = w;
        } while (*col < count);
    }
    *col = count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c04fe score 87 (draft from the asm and the Mac function; logic follows them, the instruction shapes differ)
bool cGZWinTextEdit::Slot49_adf900(uint32_t textArg, uint32_t lenArg, uint32_t notify)
{
    const char* text = reinterpret_cast<const char*>(textArg);
    uint32_t len = lenArg;
    if (!text) {
        text = "";
    }
    if (!len) {
        len = strlen(text);
    }
    mText.erase(0, std::string::npos);
    cRZString tmp(text, len);
    uint32_t removed = Fn009bf578(&tmp);
    removed += FixBadCharacterComposition(&tmp, &mText, 0);
    if (removed) {
        PlaySoundA(0);
    }
    uint32_t n = tmp.size();
    if (n != 0) {
        uint32_t max = mn1D0;
        if (n > max) {
            if (mnCodePage != 8 && mnCodePage != 0x64) {
                n = max;
            } else {
                uint32_t i = 0;
                if (max != 0) {
                    do {
                        i += RZCharacterSize(text + i, n - i, mnCodePage);
                    } while (i < max);
                }
                n = i;
            }
            PlaySoundA(1);
        }
        mText.assign(tmp.data(), tmp.data() + n);
        Fn009bf3e0(0);
        Fn009bdcd1(true);
        mnInsertionIndex = mnInsertionLine = mnInsertionColumn = mnSelectionEnd = mnSelectionStart = 0;
        TestForPossibleScrollBarAdditionOrRemoval();
        InvalidateSelfAndParents();
    } else {
        RecalculateAll();
        InvalidateSelfAndParents();
    }
    UndoVec_adfbd0* undo = reinterpret_cast<UndoVec_adfbd0*>(mUndoVec);
    undo->Erase(undo->mpBegin, undo->mpEnd);
    UndoVec_adfbd0* redo = reinterpret_cast<UndoVec_adfbd0*>(mRedoVec);
    redo->Erase(redo->mpBegin, redo->mpEnd);
    if (*reinterpret_cast<bool*>(&notify)) {
        reinterpret_cast<cPrim_adfbd0*>(this)->SendMsg5(field4c, 0x9b1552d8, IfOf_adfbd0(this), 0, 0);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bdb83 score 140 (draft from the asm and the Mac function; logic follows them, the instruction shapes differ)
void cGZWinTextEdit::GetHorizontalLineMetrics(uint32_t line, uint32_t x, void* pStartArg, void* pEndArg, void* pOffsetArg)
{
    uint32_t* pStart = static_cast<uint32_t*>(pStartArg);
    uint32_t* pEnd = static_cast<uint32_t*>(pEndArg);
    int32_t* pOffset = static_cast<int32_t*>(pOffsetArg);
    cFont_adfbd0* font = reinterpret_cast<cFont_adfbd0*>(mpFont);
    uint32_t len = Slot63_adf900(line);
    uint32_t base = mpLineBegin[line];
    const char* p = mText.data() + base;
    uint32_t i;
    uint32_t last;
    uint32_t width;
    if (x == 0) {
        i = 0;
        last = 0;
        width = 0;
    } else {
        i = RZCharacterSize(p, len, mnCodePage);
        uint32_t previous = 0;
        width = 0;
        last = i;
        while (i < len) {
            uint32_t w = font->Slot48(p, i);
            if (w > x) {
                break;
            }
            width = previous;
            last = RZCharacterSize(p + i, len - i, mnCodePage);
            i += last;
            previous = w;
        }
    }
    *pStart = (i + base) - last;
    *pOffset = width - x;
    uint32_t s = *pStart;
    if (s < len + base) {
        uint32_t rel = s - base;
        int32_t limit = mnTextAreaW;
        uint32_t j = rel + RZCharacterSize(p + rel, len - rel, mnCodePage);
        while (j < len && static_cast<int32_t>(font->Slot48(p + rel, j - rel)) < limit - static_cast<int32_t>(width - x)) {
            j += RZCharacterSize(p + j, len - j, mnCodePage);
        }
        *pEnd = base + j;
    } else {
        *pEnd = s;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009be477 score 154 (draft from the asm and the Mac function; logic follows them, the instruction shapes differ)
bool cGZWinTextEdit::AddScrollBar(bool vertical, bool horizontal)
{
    bool added = false;
    if (vertical && (mnTextFlags & 8) && !mpVScrollBar) {
        cWCM_adfbd0* wcm = Fn00913c72();
        if (wcm) {
            mpVScrollBar = wcm->CreateScrollBar(0, 2, 0, 100, 0);
        }
        cScrollBar_adfbd0* bar = reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar);
        if (!bar) {
            Slot78_adf900(8);
        } else {
            cImage_adfbd0* img = reinterpret_cast<cImage_adfbd0*>(mpScrollBarImageV);
            if (img) {
                if (mnScrollBarRectV[0] < mnScrollBarRectV[2] && mnScrollBarRectV[1] < mnScrollBarRectV[3]) {
                    bar->SetImage(mnScrollBarRectV, img, 0);
                } else {
                    bar->SetImage(img->GetRect(), img, 0);
                }
                bar = reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar);
            }
            reinterpret_cast<cPrim_adfbd0*>(this)->AddChild(bar->AsIGZWin());
        }
        added = true;
    }
    if (horizontal && (mnTextFlags & 4) && !mpHScrollBar) {
        cWCM_adfbd0* wcm = Fn00913c72();
        if (wcm) {
            mpHScrollBar = wcm->CreateScrollBar(1, 1, 0, 100, 0);
        }
        cScrollBar_adfbd0* bar = reinterpret_cast<cScrollBar_adfbd0*>(mpHScrollBar);
        if (!bar) {
            Slot78_adf900(4);
        } else {
            cImage_adfbd0* img = reinterpret_cast<cImage_adfbd0*>(mpScrollBarImageH);
            if (img) {
                if (mnScrollBarRectH[0] < mnScrollBarRectH[2] && mnScrollBarRectH[1] < mnScrollBarRectH[3]) {
                    bar->SetImage(mnScrollBarRectH, img, 0);
                } else {
                    bar->SetImage(img->GetRect(), img, 0);
                }
                bar = reinterpret_cast<cScrollBar_adfbd0*>(mpHScrollBar);
            }
            reinterpret_cast<cPrim_adfbd0*>(this)->AddChild(bar->AsIGZWin());
        }
    } else if (!added) {
        return true;
    }
    RecalculateAll();
    Fn009bdcd1(true);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c07e1 score 94 (draft from the asm and the Mac function; logic follows them, the instruction shapes differ)
bool cGZWinTextEdit::InsertTextHighLevel(void* strArg)
{
    cRZString* str = static_cast<cRZString*>(strArg);
    if (!(mnTextFlags & 0x200) || (*str)[0] != '\n') {
        cRZString removed;
        Five_adfbd0 snapshot = *reinterpret_cast<Five_adfbd0*>(&mnInsertionLine);
        uint32_t at = mnInsertionIndex;
        if (mnSelectionStart != mnSelectionEnd) {
            uint32_t lo = (mnSelectionEnd < mnSelectionStart) ? mnSelectionEnd : mnSelectionStart;
            uint32_t hi = (mnSelectionStart < mnSelectionEnd) ? mnSelectionEnd : mnSelectionStart;
            at = lo;
            Slot55_adf900(lo, hi - lo, 0);
            Slot66_adf900(lo);
            mnSelectionEnd = mnSelectionStart = mnInsertionIndex;
        }
        if ((mnTextFlags & 0x4000) && removed.empty() && mnInsertionIndex < mText.size()) {
            Slot52_adf900(mnInsertionIndex, 0, 0);
        }
        uint32_t inserted = IfOf_adfbd0(this)->InsertText(str->data(), str->size(), mnInsertionIndex);
        if (inserted == 0) {
            PlaySoundA(1);
        } else {
            AddUndoRecordForTextInsertion(&snapshot, at, const_cast<char*>(mText.data()) + mnInsertionIndex, inserted, const_cast<char*>(removed.data()), removed.size());
        }
        mnSelectionEnd = mnSelectionStart = mnInsertionIndex;
        mn170 = -1;
        PutInsertionPositionInView();
        if (mnTextFlags & 0x800) {
            reinterpret_cast<cPrim_adfbd0*>(this)->SendMsg5(field4c, 0x9b1552d8, IfOf_adfbd0(this), 0, 0);
        }
    } else {
        mnSelectionEnd = mnSelectionStart = mnInsertionIndex;
        InvalidateSelfAndParents();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bea28 score 910 (draft from the Mac function; the draw context, font and scroll bar calls are views, so the instruction shapes differ widely)
bool cGZWinTextEdit::GZPaint()
{
    uint32_t line = mnFirstVisibleLine;
    uint32_t endLine = line + mnVisibleLineCount;
    uint32_t lineStart = 0;
    uint32_t lineEnd = 0;
    int32_t lineOffset = 0;
    bool focused = (Fn0099bdf3() == this);
    uint32_t colorText = ConvertPackedRGBToNative(mnColors[0]);
    uint32_t colorText2 = ConvertPackedRGBToNative(mnColors[1]);
    uint32_t colorSelected = ConvertPackedRGBToNative(mnColors[4]);
    uint32_t colorSelected2 = ConvertPackedRGBToNative(mnColors[5]);
    uint32_t selectionA = mnSelectionStart;
    uint32_t selectionB = mnSelectionEnd;
    cRZString* text = &mText;
    if (mnTextFlags & 0x2000) {
        uint32_t n = RZCharacterCount(mText.data(), mText.size(), mnCodePage);
        if (n != mStrF0.size()) {
            mStrF0.resize(n, mcPasswordChar);
        }
        text = &mStrF0;
        selectionA = RZCharacterCount(mText.data(), mnSelectionStart, mnCodePage);
        selectionB = RZCharacterCount(mText.data(), mnSelectionEnd, mnCodePage);
    }
    uint32_t hscroll = Fn009bddc2();
    if (endLine > static_cast<uint32_t>(mpLineEnd - mpLineBegin)) {
        endLine = mpLineEnd - mpLineBegin;
    }
    cDC_adfbd0* dc = reinterpret_cast<cDC_adfbd0*>(field64);
    int32_t* area = reinterpret_cast<int32_t*>(field24);
    int32_t rectA[4];
    int32_t rectB[4];
    if (mnTextFlags & 0x20) {
        cImage_adfbd0* img = reinterpret_cast<cImage_adfbd0*>(mpBackgroundImage);
        if (!img) {
            dc->SetColor(GetFillColorRGB());
            dc->FillRect(area);
        } else {
            const int32_t* r = static_cast<const int32_t*>(img->GetRect());
            rectA[0] = r[0];
            rectA[1] = r[1];
            rectA[2] = r[2];
            rectA[3] = r[3];
            if (!mbBackgroundTile) {
                dc->Blt(img, rectA, area, 0, 0);
            } else {
                rectB[0] = area[0];
                rectB[1] = area[1];
                rectB[2] = area[2];
                rectB[3] = area[3];
                rectA[2] = rectA[2] / 3;
                rectA[3] = rectA[3] / 3;
                if (mpVScrollBar) {
                    rectB[2] = area[2] - reinterpret_cast<cPrim_adfbd0*>(reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar)->AsIGZWin())->GetW();
                }
                if (mpHScrollBar) {
                    rectB[3] = area[3] - reinterpret_cast<cPrim_adfbd0*>(reinterpret_cast<cScrollBar_adfbd0*>(mpHScrollBar)->AsIGZWin())->GetH();
                }
                RZDrawBltEdge(dc, img, rectA, rectB, true);
            }
        }
    }
    if (mnTextAreaW != 0) {
        int32_t y = area[1] + mnTextAreaY;
        for (; line < endLine; ++line) {
            uint32_t start = mpLineBegin[line];
            int32_t x = area[0] + mnTextAreaX;
            uint32_t length;
            if (!mpVScrollBar && false) {
                length = 0;
            }
            if (!mpHScrollBar && (mnTextFlags & 2) && !(mnTextFlags & 0x200)) {
                length = Slot63_adf900(line);
                lineEnd = start + length;
                lineStart = start;
            } else {
                GetHorizontalLineMetrics(line, hscroll, &lineStart, &lineEnd, &lineOffset);
                length = lineEnd - lineStart;
                x += lineOffset;
            }
            if (length != 0) {
                if ((*text)[lineEnd] == '\n') {
                    --length;
                }
                uint32_t highlightFrom = 0;
                uint32_t highlightTo = 0;
                if (mnSelectionStart != mnSelectionEnd) {
                    uint32_t lo = (selectionB < selectionA) ? selectionB : selectionA;
                    uint32_t hi = (selectionA < selectionB) ? selectionB : selectionA;
                    if (hi > lineStart && length + lineStart > lo) {
                        highlightFrom = (static_cast<int32_t>(lineStart) < static_cast<int32_t>(lo)) ? lo : lineStart;
                        highlightTo = (static_cast<int32_t>(hi) < static_cast<int32_t>(length + lineStart)) ? hi : length + lineStart;
                    }
                }
                rectB[0] = area[0];
                rectB[1] = area[1];
                rectB[2] = area[2];
                rectB[3] = area[3];
                if (mpVScrollBar) {
                    rectB[2] = area[2] - reinterpret_cast<cPrim_adfbd0*>(reinterpret_cast<cScrollBar_adfbd0*>(mpVScrollBar)->AsIGZWin())->GetW();
                }
                if (mpHScrollBar) {
                    rectB[3] = area[3] - reinterpret_cast<cPrim_adfbd0*>(reinterpret_cast<cScrollBar_adfbd0*>(mpHScrollBar)->AsIGZWin())->GetH();
                }
                rectB[0] += mnTextAreaX;
                rectB[2] -= mnTextAreaX;
                rectB[1] += mnTextAreaY;
                rectB[3] -= mnTextAreaY;
                cFont_adfbd0* font = reinterpret_cast<cFont_adfbd0*>(mpFont);
                const char* base = text->data();
                if ((focused || (mnTextFlags & 0x10000)) && highlightTo != highlightFrom && lineStart < highlightTo && highlightFrom <= lineEnd) {
                    uint32_t width = font->Slot48(base + lineStart, length);
                    if (lineStart < highlightFrom || highlightTo < length + lineStart) {
                        font->DrawText(reinterpret_cast<void*>(*reinterpret_cast<uint32_t*>(&field50[0x10])), x, y, base + lineStart, length, colorText, colorText2, rectB, 0);
                        int32_t before = 0;
                        if (highlightFrom != lineStart) {
                            before = font->Slot48(base + lineStart, highlightFrom - lineStart);
                        }
                        int32_t selected = font->Slot48(base + highlightFrom, highlightTo - highlightFrom);
                        int32_t fill[4];
                        fill[0] = before + x;
                        fill[1] = y;
                        fill[2] = selected + fill[0];
                        fill[3] = y + mnLineHeight;
                        dc->SetColor(mnHighlightFillColor);
                        dc->FillRect(fill);
                        font->DrawText(reinterpret_cast<void*>(*reinterpret_cast<uint32_t*>(&field50[0x10])), fill[0], y, base + highlightFrom, highlightTo - highlightFrom, colorSelected, colorSelected2, rectB, 0);
                    } else {
                        int32_t fill[4];
                        fill[0] = x;
                        fill[1] = y;
                        fill[2] = x + width;
                        fill[3] = y + mnLineHeight;
                        dc->SetColor(mnHighlightFillColor);
                        dc->FillRect(fill);
                        font->DrawText(reinterpret_cast<void*>(*reinterpret_cast<uint32_t*>(&field50[0x10])), x, y, base + lineStart, length, colorSelected, colorSelected2, rectB, 0);
                    }
                } else {
                    font->DrawText(reinterpret_cast<void*>(*reinterpret_cast<uint32_t*>(&field50[0x10])), x, y, base + lineStart, length, colorText, colorText2, rectB, 0);
                }
            }
            y += mnLineHeight;
        }
        if (mbCaretVisible && focused) {
            if (mnFirstVisibleLine <= mnInsertionLine && mnInsertionLine < static_cast<uint32_t>(mnFirstVisibleLine + mnVisibleLineCount)) {
                const char* caretText;
                if (mpLineBegin != mpLineEnd) {
                    caretText = text->data() + mpLineBegin[mnInsertionLine];
                } else {
                    caretText = text->data();
                }
                int32_t cx = area[0] + mnTextAreaX + reinterpret_cast<cFont_adfbd0*>(mpFont)->Slot48(caretText, mnInsertionColumn) - hscroll;
                if (mnTextAreaX + area[0] <= cx) {
                    uint32_t lineHeight = mnLineHeight;
                    uint32_t caretWidth = 2 - (lineHeight < 0x18);
                    int32_t right = area[2];
                    int32_t margin = mnTextAreaX;
                    if (cx >= right && (mnTextFlags & 2)) {
                        right = right - margin;
                        cx = right - caretWidth;
                    } else {
                        right = right - margin;
                    }
                    if (cx < right) {
                        int32_t top = area[1] + mnTextAreaY + (mnInsertionLine - mnFirstVisibleLine) * lineHeight;
                        int32_t from = top;
                        if (top < area[1] + 1) {
                            from = area[1] + 1;
                        }
                        int32_t to = area[3] - 1;
                        if (static_cast<int32_t>(lineHeight + top) < area[3] - 1) {
                            to = lineHeight + top;
                        }
                        dc->SetColor(mnCaretColor);
                        dc->SetLineWidth(static_cast<float>(caretWidth));
                        dc->DrawLine(cx, from, cx, to);
                        dc->SetLineWidth(1.0f);
                    }
                }
            }
        }
    }
    if ((mnTextFlags & 0x10) && focused) {
        RZDrawRectangleOutline(dc, area, mn1C8, 1);
    }
    return true;
}
#endif

// The selection follows the insertion index; shift keeps its start.
inline void FollowInsertion_adfbd0(cGZWinTextEdit* t, bool extend)
{
    uint32_t i = t->mnInsertionIndex;
    if (!extend) {
        t->mnSelectionEnd = i;
        t->mnSelectionStart = i;
    } else {
        t->mnSelectionEnd = i;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c0a95 score 1152 (draft from the Mac function; the key cases and their order follow the Mac switch, the many view calls make the instruction shapes differ widely)
bool cGZWinTextEdit::GZOnKeyDown(uint32_t key, uint32_t modifiers)
{
    bool shift = (modifiers & 1) != 0;
    bool ctrl = ((modifiers >> 1) & 1) != 0;
    bool alt = ((modifiers >> 2) & 1) != 0;
    cPrim_adfbd0* self = reinterpret_cast<cPrim_adfbd0*>(this);
    cIf_adfbd0* iface = IfOf_adfbd0(this);
    switch (key) {
    case 8:
    case 0x2e: {
        if (!(mnTextFlags & 1)) {
            return true;
        }
        cRZString removed;
        Five_adfbd0 snapshot = *reinterpret_cast<Five_adfbd0*>(&mnInsertionLine);
        if (mnSelectionStart != mnSelectionEnd) {
            uint32_t lo = (mnSelectionEnd < mnSelectionStart) ? mnSelectionEnd : mnSelectionStart;
            uint32_t hi = (mnSelectionStart < mnSelectionEnd) ? mnSelectionEnd : mnSelectionStart;
            if (iface->RemoveText(lo, hi - lo, &removed) == 0) {
                PlaySoundA(1);
            } else {
                AddUndoRecordForTextDeletion(&snapshot, lo, const_cast<char*>(removed.data()), removed.size());
            }
            Slot66_adf900(lo);
        } else if (key == 8) {
            if (mnInsertionIndex == 0) {
                PlaySoundA(1);
                mnSelectionEnd = mnSelectionStart = mnInsertionIndex;
                mn170 = -1;
                if (mnTextFlags & 0x800) {
                    self->SendMsg5(field4c, 0x9b1552d8, iface, 0, 0);
                }
                return true;
            }
            uint32_t previous = GetPreviousCharLength(mText.data() + mnInsertionIndex, mnInsertionIndex, mnCodePage);
            if (!iface->RemoveChar(mnInsertionIndex - previous, 1, &removed)) {
                PlaySoundA(1);
            } else {
                AddUndoRecordForTextDeletion(&snapshot, mnInsertionIndex - previous, const_cast<char*>(removed.data()), removed.size());
            }
        } else {
            if (mText.size() <= mnInsertionIndex) {
                PlaySoundA(1);
                mnSelectionEnd = mnSelectionStart = mnInsertionIndex;
                mn170 = -1;
                if (mnTextFlags & 0x800) {
                    self->SendMsg5(field4c, 0x9b1552d8, iface, 0, 0);
                }
                return true;
            }
            if (!iface->RemoveChar(mnInsertionIndex, 0, &removed)) {
                PlaySoundA(1);
            } else {
                AddUndoRecordForTextDeletion(&snapshot, mnInsertionIndex, const_cast<char*>(removed.data()), removed.size());
            }
        }
        mnSelectionEnd = mnSelectionStart = mnInsertionIndex;
        mn170 = -1;
        if (mnTextFlags & 0x800) {
            self->SendMsg5(field4c, 0x9b1552d8, iface, 0, 0);
        }
        break;
    }
    case 0xd:
        if (!(mnTextFlags & 0x400)) {
            return true;
        }
        self->SendMsg5(field4c, 0x9b1552d5, iface, 0xd, 0);
        break;
    case 0x1b:
        if (mnTextFlags & 1) {
            if (mnSelectionStart != mnSelectionEnd) {
                mnSelectionEnd = mnSelectionStart = mnInsertionIndex;
                InvalidateSelfAndParents();
            }
            return self->SendMsg5(field4c, 5, reinterpret_cast<void*>(0x1b), modifiers, 0);
        }
        // fall through to the copy handling like the original
    case 0x43:
    case 0x58:
        if (ctrl && !shift && !alt && (mnTextFlags & 0x1000) && !(mnTextFlags & 0x2000) && !GZAmCapturing()) {
            if (mp28C) {
                uint32_t a;
                uint32_t b;
                iface->GetSelection(&a, &b);
                if (a != b) {
                    if (b < a) {
                        uint32_t t = a;
                        a = b;
                        b = t;
                    }
                    cRZString selected(mText.data() + a, b - a);
                    reinterpret_cast<cClip_adfbd0*>(mp28C)->SetText(&selected, 1, 0);
                }
            }
            if (key == 0x58) {
                GZOnKeyDown(0x2e, 0);
            }
        }
        break;
    case 0x21:
    case 0x22:
    case 0x26:
    case 0x28: {
        uint32_t flags = mnTextFlags;
        if (!(flags & 1) || (flags & 0x200)) {
            if (key == 0x26 || key == 0x28) {
                if (!(flags & 0x800)) {
                    return true;
                }
                self->SendMsg5(field4c, 0x9b1552d5, iface, key, 0);
            } else {
                return true;
            }
            break;
        }
        uint32_t lines = mpLineEnd - mpLineBegin;
        bool up = (key == 0x21 || key == 0x26);
        if ((up && mnInsertionLine == 0 && mnSelectionStart == mnSelectionEnd) ||
            (!up && mnInsertionLine >= lines - 1 && mnSelectionStart == mnSelectionEnd)) {
            PlaySoundA(2);
            break;
        }
        uint32_t index = mnInsertionIndex;
        if ((up && mnInsertionLine != 0) || (!up && mnInsertionLine < lines - 1)) {
            int32_t x;
            int32_t y;
            iface->GetPositionFromLineAndColumn(mnInsertionLine, mnInsertionColumn, &x, &y);
            uint32_t step = (key == 0x21 || key == 0x22) ? mnVisibleLineCount : 1;
            if (up) {
                mnInsertionLine = (mnInsertionLine < step) ? 0 : mnInsertionLine - step;
            } else {
                mnInsertionLine = (mnInsertionLine < lines - step) ? mnInsertionLine + step : lines - 1;
            }
            if (mn170 == -1) {
                mn170 = x;
            }
            iface->GetColumnFromPosition(mnInsertionLine, &mnInsertionColumn, mn170);
            iface->GetIndexFromLineAndColumn(mnInsertionLine, mnInsertionColumn, &mnInsertionIndex);
            index = mnInsertionIndex;
            if (index != 0 && mnInsertionColumn != 0 && mText[index - 1] == '\n') {
                --mnInsertionColumn;
                index = --mnInsertionIndex;
            }
        }
        FollowInsertion_adfbd0(this, shift);
        PutInsertionPositionInView();
        if (key == 0x21 || key == 0x22) {
            Fn009bc635();
        }
        InvalidateSelfAndParents();
        mn170 = -1;
        break;
    }
    case 0x23:
    case 0x24:
        if (mnTextFlags & 1) {
            uint32_t endLine = Slot63_adf900(mnInsertionLine);
            bool home = (key == 0x24);
            if (home ? (mnInsertionColumn != 0 || mnSelectionStart != mnSelectionEnd) : (endLine != mnInsertionColumn || mnSelectionStart != mnSelectionEnd)) {
                if (ctrl) {
                    mnInsertionIndex = home ? 0 : mText.size();
                    iface->GetLineAndColumnFromIndex(&mnInsertionLine, &mnInsertionColumn, mnInsertionIndex);
                } else if (home) {
                    if (mnInsertionColumn != 0) {
                        mnInsertionColumn = 0;
                        iface->GetIndexFromLineAndColumn(mnInsertionLine, 0, &mnInsertionIndex);
                    }
                } else if (endLine != mnInsertionColumn) {
                    mnInsertionColumn = endLine;
                    iface->GetIndexFromLineAndColumn(mnInsertionLine, endLine, &mnInsertionIndex);
                    if (mnInsertionIndex != 0 && mnInsertionColumn != 0 && mText[mnInsertionIndex - 1] == '\n') {
                        --mnInsertionColumn;
                        --mnInsertionIndex;
                    }
                }
                FollowInsertion_adfbd0(this, shift);
                PutInsertionPositionInView();
                Fn009bc635();
                InvalidateSelfAndParents();
            }
            mn170 = -1;
        }
        break;
    case 0x25:
    case 0x27:
        if (mnTextFlags & 1) {
            bool left = (key == 0x25);
            if (left ? (mnInsertionIndex != 0 || mnSelectionStart != mnSelectionEnd) : (mnInsertionIndex < mText.size() || mnSelectionStart != mnSelectionEnd)) {
                if (left ? (mnInsertionIndex != 0) : (mnInsertionIndex < mText.size())) {
                    if (alt) {
                        Slot71_adf900(left ? 0xffffffff : 1);
                    } else {
                        Slot70_adf900(left ? 0xffffffff : 1);
                    }
                }
                FollowInsertion_adfbd0(this, shift);
                PutInsertionPositionInView();
                Fn009bc635();
                InvalidateSelfAndParents();
            } else {
                PlaySoundA(2);
            }
            mn170 = -1;
        }
        break;
    case 0x2d:
        if ((mnTextFlags & 1) && (mnTextFlags & 0x80)) {
            mnTextFlags ^= 0x4000;
        }
        break;
    case 0x56:
        if (ctrl && !shift && !alt && !GZAmCapturing() && (mnTextFlags & 0x1000) && mp28C) {
            cRZString pasted;
            if (reinterpret_cast<cClip_adfbd0*>(mp28C)->GetText(&pasted, 0)) {
                InsertTextHighLevel(&pasted);
            }
        }
        break;
    case 0x59:
        if (!ctrl || alt) {
            return true;
        }
        {
            UndoVec_adfbd0* redoVec = reinterpret_cast<UndoVec_adfbd0*>(mRedoVec);
            if (redoVec->mpBegin != redoVec->mpEnd) {
                Slot84_adf900();
                return true;
            }
        }
        PlaySoundA(3);
        break;
    case 0x5a:
        if (!ctrl || alt) {
            return true;
        }
        {
            UndoVec_adfbd0* undoVec = reinterpret_cast<UndoVec_adfbd0*>(mUndoVec);
            if (undoVec->mpBegin != undoVec->mpEnd) {
                Slot83_adf900();
                return true;
            }
        }
        PlaySoundA(3);
        break;
    default:
        break;
    }
    return true;
}
#endif
