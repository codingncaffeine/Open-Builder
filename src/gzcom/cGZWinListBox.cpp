#include "classes/cGZWinListBox.h"
#include <stdio.h>
#include "gzcom/cIGZUnknown.h"
#include "gzcom/cRZString.h"

// This object seen through the primary vtable (slots whose declared signature differs from the call).
struct cPrim_ae1780 {
// VIEW-BEGIN
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void* GetWindowManager();
    virtual void P7();
    virtual void P8();
    virtual void P9();
    virtual void P10();
    virtual void* GetParentWin();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void P15();
    virtual bool ChildDelete(void* child);
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
    virtual bool GetChildAs(uint32_t id, uint32_t iid, void** out);
    virtual void P37();
    virtual void P38();
    virtual void P39();
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void GetArea(void* rect);
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
    virtual bool WindowToWindowCoordinates(void* win, int32_t* x, int32_t* y);
    virtual void P62();
    virtual void P63();
    virtual void P64();
    virtual void P65();
    virtual void P66();
    virtual void P67();
    virtual void P68();
    virtual void P69();
    virtual void P70();
    virtual void P71();
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
    virtual void P85();
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
    virtual bool SendMsg5(uint32_t target, uint32_t msg, uint32_t a, uint32_t b, uint32_t c);
    virtual void P145();
    virtual bool PostMsg5(uint32_t target, uint32_t msg, uint32_t a, uint32_t b, uint32_t c);
    virtual void P147();
    virtual void P148();
    virtual void P149();
    virtual void P150();
    virtual void P151();
    virtual void P152();
    virtual void P153();
    virtual void P154();
    virtual void P155();
    virtual void P156();
    virtual void P157();
    virtual void P158();
    virtual void P159();
    virtual void P160();
    virtual void P161();
    virtual void P162();
    virtual void P163();
    virtual void P164();
    virtual void P165();
    virtual void P166();
    virtual void P167();
    virtual void P168();
// VIEW-END
};

// ---- batch 1: the small methods ----

// FUNCTION: 0x009ca9fa
void cGZWinListBox::Slot167_ae1780()
{
    emit_selection_changed_msg();
}

// FUNCTION: 0x009caa02
void cGZWinListBox::Slot168_ae1780()
{
    emit_dblclick_msg();
}

// FUNCTION: 0x009c8f3c
void cGZWinListBox::Slot14_ae1560()
{
    if (!mbShouldSort) {
        mbShouldSort = true;
        Slot16_ae1560();
    }
}

// FUNCTION: 0x009c912b
bool cGZWinListBox::Slot35_ae1560(uint32_t a, uint32_t b)
{
    mbVScrollEnabled = *reinterpret_cast<bool*>(&a);
    mbHScrollEnabled = *reinterpret_cast<bool*>(&b);
    return true;
}

// FUNCTION: 0x009c89cb
void cGZWinListBox::Slot41_ae1560(uint32_t a)
{
    Slot39_ae1560(a, 0xdeadbeef);
}

// FUNCTION: 0x009c8877
bool cGZWinListBox::Slot58_ae1560(void* a, void* b)
{
    *static_cast<int8_t*>(a) = mcScrollbarGutterX;
    *static_cast<int8_t*>(b) = mcScrollbarGutterY;
    return true;
}

// FUNCTION: 0x009c88bd
bool cGZWinListBox::Slot60_ae1560(void* a, void* b)
{
    *static_cast<int8_t*>(a) = mcTextGutterX;
    *static_cast<int8_t*>(b) = mcTextGutterY;
    return true;
}

// FUNCTION: 0x009c913e
bool cGZWinListBox::Slot36_ae1560(void* a, void* b)
{
    *static_cast<bool*>(a) = mbVScrollEnabled;
    *static_cast<bool*>(b) = mbHScrollEnabled;
    return true;
}

// FUNCTION: 0x009c8783
void cGZWinListBox::Slot51_ae1560(uint32_t a)
{
    mbOutlineDrawing = *reinterpret_cast<bool*>(&a);
    mbDrawSunkenRect = false;
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009c87a3
void cGZWinListBox::Slot53_ae1560(uint32_t a)
{
    mbDrawSunkenRect = *reinterpret_cast<bool*>(&a);
    mbOutlineDrawing = false;
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009c8e29
bool cGZWinListBox::Slot22_ae1560()
{
    if (static_cast<int32_t>(Slot30_ae1560()) > 0) {
        Slot29_ae1560(0);
        return true;
    }
    return false;
}

// FUNCTION: 0x009c8d71
uint32_t cGZWinListBox::Slot26_ae1560(uint32_t a)
{
    int32_t index = static_cast<int32_t>(a);
    if (index >= mnTopIndex && index < mnVisibleLines + mnTopIndex) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x009c8bb0
bool cGZWinListBox::Slot152_ae1780(uint32_t a)
{
    if (!GZAmCapturing()) {
        Slot28_ae1560(a);
    }
    return false;
}

// FUNCTION: 0x009c8cc7
bool cGZWinListBox::GZOnKeyUp(uint32_t a, uint32_t b)
{
    if (mbPopup) {
        return true;
    }
    return reinterpret_cast<cPrim_ae1780*>(this)->SendMsg5(field4c, 6, a, b, 0);
}

// ---- batch 2: the standard-library pieces the entry list uses (a list and a vector of entries) ----

// An entry of the list: the text and the identifier it was added with.
struct Entry_ae1780 {
    cRZString mText;
    uint32_t mnID;
    Entry_ae1780()
        : mnID(0)
    {
    }
    Entry_ae1780(const cIGZString& text, uint32_t id)
        : mText(text)
        , mnID(id)
    {
    }
    // The out-of-line destructor of the original (the list and the vector call it; the inline one is elsewhere).
    // STUB: 0x00414250
    void Destroy();
    // STUB: 0x009ca065
    Entry_ae1780(const Entry_ae1780& other);
};

struct Node_ae1780 {
    Node_ae1780* mpNext;
    Node_ae1780* mpPrev;
    Entry_ae1780 mData;
};

// A position in the list (a class with constructors: the original passes and returns it as an object).
struct Iter_ae1780 {
    Node_ae1780* mpNode;
    Iter_ae1780()
    {
    }
    Iter_ae1780(Node_ae1780* node)
        : mpNode(node)
    {
    }
    Iter_ae1780(const Iter_ae1780& other)
        : mpNode(other.mpNode)
    {
    }
    Iter_ae1780 operator++(int)
    {
        Iter_ae1780 old = *this;
        mpNode = mpNode->mpNext;
        return old;
    }
};

// The empty tag objects the library passes by reference.
struct Tag_ae1780 {
    Tag_ae1780()
    {
    }
};

// STUB: 0x0090cf63
void StlDelete_ae1780(void* p);

struct List_ae1780 {
    Node_ae1780* mpHead;
    Iter_ae1780 erase(Iter_ae1780 pos);
    Iter_ae1780 erase(Iter_ae1780 first, Iter_ae1780 last);
    void pop_front();
    void pop_back();
    Iter_ae1780 insert(Iter_ae1780 pos, const Entry_ae1780& x);
    void push_front(const Entry_ae1780& x);
    void push_back(const Entry_ae1780& x);
    // STUB: 0x009560fe
    Node_ae1780* CreateNode(const Entry_ae1780& x);
};

// FUNCTION: 0x009217c8
Iter_ae1780 List_ae1780::erase(Iter_ae1780 pos)
{
    Node_ae1780* next = pos.mpNode->mpNext;
    Node_ae1780* prev = pos.mpNode->mpPrev;
    prev->mpNext = next;
    next->mpPrev = prev;
    pos.mpNode->mData.Destroy();
    StlDelete_ae1780(pos.mpNode);
    return Iter_ae1780(next);
}

// FUNCTION: 0x009ca04f
void List_ae1780::pop_front()
{
    erase(Iter_ae1780(mpHead->mpNext));
}

// FUNCTION: 0x00955144
void List_ae1780::pop_back()
{
    erase(Iter_ae1780(mpHead->mpPrev));
}

// FUNCTION: 0x009ca01b
Iter_ae1780 List_ae1780::erase(Iter_ae1780 first, Iter_ae1780 last)
{
    while (first.mpNode != last.mpNode) {
        erase(first++);
    }
    return last;
}

// FUNCTION: 0x009caa5c
Iter_ae1780 List_ae1780::insert(Iter_ae1780 pos, const Entry_ae1780& x)
{
    Node_ae1780* tmp = CreateNode(x);
    Node_ae1780* n = pos.mpNode;
    Node_ae1780* p = n->mpPrev;
    tmp->mpNext = n;
    tmp->mpPrev = p;
    p->mpNext = tmp;
    n->mpPrev = tmp;
    return Iter_ae1780(tmp);
}

// FUNCTION: 0x009caa81
void List_ae1780::push_front(const Entry_ae1780& x)
{
    insert(Iter_ae1780(mpHead->mpNext), x);
}

// FUNCTION: 0x009caa9d
void List_ae1780::push_back(const Entry_ae1780& x)
{
    insert(Iter_ae1780(mpHead), x);
}

// FUNCTION: 0x009ca159
void DestroyRange_ae1780(Entry_ae1780* first, Entry_ae1780* last)
{
    for (; first != last; ++first) {
        first->Destroy();
    }
}

// FUNCTION: 0x009c9b72
void AdvanceImpl_ae1780(Iter_ae1780& it, int32_t n, const Tag_ae1780&)
{
    if (n > 0) {
        while (n--) {
            it.mpNode = it.mpNode->mpNext;
        }
    } else {
        while (n++) {
            it.mpNode = it.mpNode->mpPrev;
        }
    }
}

// FUNCTION: 0x009c9e29
void Advance_ae1780(Iter_ae1780& it, int32_t n)
{
    AdvanceImpl_ae1780(it, n, Tag_ae1780());
}

// STUB: 0x009ca172
Entry_ae1780* UninitializedFillN_ae1780(Entry_ae1780* first, int32_t n, const Entry_ae1780& x, const Tag_ae1780&);

// FUNCTION: 0x009ca719
Entry_ae1780* UninitializedFillN2_ae1780(Entry_ae1780* first, int32_t n, const Entry_ae1780& x)
{
    return UninitializedFillN_ae1780(first, n, x, Tag_ae1780());
}

// The vector's storage proxy: the allocator and the end of the storage.
struct AllocProxy_ae1780 {
    Entry_ae1780* mpEnd;
    AllocProxy_ae1780(Entry_ae1780* end)
        : mpEnd(end)
    {
    }
    // STUB: 0x009090e0
    Entry_ae1780* allocate(uint32_t n, const void* hint);
};

struct VecBase_ae1780 {
    Entry_ae1780* mpStart;
    Entry_ae1780* mpFinish;
    AllocProxy_ae1780 mStorage;
    VecBase_ae1780(uint32_t n, const Tag_ae1780&);
};

// FUNCTION: 0x009c9df6
VecBase_ae1780::VecBase_ae1780(uint32_t n, const Tag_ae1780&)
    : mpStart(0)
    , mpFinish(0)
    , mStorage(0)
{
    mpStart = mStorage.allocate(n, 0);
    mpFinish = mpStart;
    mStorage.mpEnd = mpStart + n;
}

struct Vec_ae1780 : public VecBase_ae1780 {
    // STUB: 0x009caab7
    Vec_ae1780(uint32_t n);
    ~Vec_ae1780();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009caab7 score 3 (the inline destructor of the filler also stores the vtable here)
Vec_ae1780::Vec_ae1780(uint32_t n)
    : VecBase_ae1780(n, Tag_ae1780())
{
    Entry_ae1780 filler;
    mpFinish = UninitializedFillN2_ae1780(mpStart, n, filler);
}
#endif

// FUNCTION: 0x009ca6fb
Vec_ae1780::~Vec_ae1780()
{
    DestroyRange_ae1780(mpStart, mpFinish);
    if (mpStart) {
        StlDelete_ae1780(mpStart);
    }
}

// ---- batch 3: sorting the entries (the library's sort over a vector copy of the list) ----

// The comparison the sort uses is a function pointer the component manager hands out.
typedef void* Compare_ae1780;

// The component manager, seen through the one slot the sort uses.
struct cWCM_ae1780 {
    virtual void W0();
    virtual void W1();
    virtual void W2();
    virtual void W3();
    virtual void W4();
    virtual void* GetFont(uint32_t id);
    virtual void W6();
    virtual void* GetBuffer(uint32_t id);
    virtual void W8();
    virtual void W9();
    virtual void W10();
    virtual void W11();
    virtual void W12();
    virtual void W13();
    virtual void W14();
    virtual void W15();
    virtual void W16();
    virtual void* CreateScrollBar(uint32_t id, uint32_t kind, uint32_t a, uint32_t b, uint32_t c);
    virtual void W18();
    virtual void W19();
    virtual void W20();
    virtual void W21();
    virtual void W22();
    virtual void W23();
    virtual void W24();
    virtual void W25();
    virtual void W26();
    virtual void W27();
    virtual void W28();
    virtual void W29();
    virtual void W30();
    virtual void W31();
    virtual uint32_t GetColor(uint32_t id);
    virtual void W33();
    virtual void W34();
    virtual void W35();
    virtual void W36();
    virtual void W37();
    virtual Compare_ae1780 GetSortCompare(uint32_t kind);
    virtual void W39();
    virtual uint32_t GetDoubleClickTime();
};

// STUB: 0x00913d7a
cWCM_ae1780* Fn00913d7a();

// STUB: 0x009cab02
Entry_ae1780* CopyAux_ae1780(Iter_ae1780 first, Iter_ae1780 last, Entry_ae1780* result, const Tag_ae1780&, int32_t* distance);

// FUNCTION: 0x009cacd6
Entry_ae1780* CopyDispatch_ae1780(Iter_ae1780 first, Iter_ae1780 last, Entry_ae1780* result, const Tag_ae1780&)
{
    return CopyAux_ae1780(first, last, result, Tag_ae1780(), 0);
}

// FUNCTION: 0x009cae62
Entry_ae1780* Copy_ae1780(Iter_ae1780 first, Iter_ae1780 last, Entry_ae1780* result)
{
    return CopyDispatch_ae1780(first, last, result, Tag_ae1780());
}

// STUB: 0x009cab28
Iter_ae1780 CopyBackAux_ae1780(Entry_ae1780* first, Entry_ae1780* last, Iter_ae1780 result, const Tag_ae1780&, int32_t* distance);

// STUB: 0x009cacfc
Iter_ae1780 CopyBackDispatch_ae1780(Entry_ae1780* first, Entry_ae1780* last, Iter_ae1780 result, const Tag_ae1780&);

#ifdef OB_DRAFTS
// CLOSE: 0x009cacfc score 2 (the tag temporary sits in another dead argument slot)
Iter_ae1780 CopyBackDispatchDraft_ae1780(Entry_ae1780* first, Entry_ae1780* last, Iter_ae1780 result, const Tag_ae1780&)
{
    return CopyBackAux_ae1780(first, last, result, Tag_ae1780(), 0);
}
#endif

// STUB: 0x009cae86
Iter_ae1780 CopyBack_ae1780(Entry_ae1780* first, Entry_ae1780* last, Iter_ae1780 result);

#ifdef OB_DRAFTS
// CLOSE: 0x009cae86 score 2 (the tag temporary sits in another dead argument slot)
Iter_ae1780 CopyBackDraft_ae1780(Entry_ae1780* first, Entry_ae1780* last, Iter_ae1780 result)
{
    return CopyBackDispatch_ae1780(first, last, result, Tag_ae1780());
}
#endif

// STUB: 0x009cafa2
void InsertionSort_ae1780(Entry_ae1780* first, Entry_ae1780* last, Compare_ae1780 comp);

// STUB: 0x009cad83
void UnguardedInsertionSort_ae1780(Entry_ae1780* first, Entry_ae1780* last, Compare_ae1780 comp);

// FUNCTION: 0x009cb03b
void FinalInsertionSort_ae1780(Entry_ae1780* first, Entry_ae1780* last, Compare_ae1780 comp)
{
    if (last - first > 16) {
        InsertionSort_ae1780(first, first + 16, comp);
        UnguardedInsertionSort_ae1780(first + 16, last, comp);
    } else {
        InsertionSort_ae1780(first, last, comp);
    }
}

// STUB: 0x009cb082
void PartialSort_ae1780(Entry_ae1780* first, Entry_ae1780* middle, Entry_ae1780* last, Compare_ae1780 comp);

// STUB: 0x009c9314
const Entry_ae1780& Median_ae1780(const Entry_ae1780& a, const Entry_ae1780& b, const Entry_ae1780& c, Compare_ae1780 comp);

// STUB: 0x009cad23
Entry_ae1780* UnguardedPartition_ae1780(Entry_ae1780* first, Entry_ae1780* last, Entry_ae1780 pivot, Compare_ae1780 comp);

// FUNCTION: 0x009cb09d
void IntroSortLoop_ae1780(Entry_ae1780* first, Entry_ae1780* last, Entry_ae1780*, int32_t depthLimit, Compare_ae1780 comp)
{
    while (last - first > 16) {
        if (depthLimit == 0) {
            PartialSort_ae1780(first, last, last, comp);
            return;
        }
        --depthLimit;
        Entry_ae1780* cut = UnguardedPartition_ae1780(first, last, Entry_ae1780(Median_ae1780(*first, *(first + (last - first) / 2), *(last - 1), comp)), comp);
        IntroSortLoop_ae1780(cut, last, 0, depthLimit, comp);
        last = cut;
    }
}

// FUNCTION: 0x009cb124
void Sort_ae1780(Entry_ae1780* first, Entry_ae1780* last, Compare_ae1780 comp)
{
    if (first != last) {
        int32_t n = last - first;
        int32_t k = 0;
        for (; n != 1; n >>= 1) {
            ++k;
        }
        IntroSortLoop_ae1780(first, last, 0, k * 2, comp);
        FinalInsertionSort_ae1780(first, last, comp);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009cb16a score 15 (same logic; argument temporaries load in another register order; the index local is initialised, the original reads it unset)
void cGZWinListBox::Slot16_ae1560()
{
    cRZString selected;
    Compare_ae1780 compare = Fn00913d7a()->GetSortCompare(0);
    if (mnSelection >= 0) {
        GetStringFromIndex(mnSelection, &selected);
    }
    Vec_ae1780 vec(mnEntryCount);
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    Copy_ae1780(Iter_ae1780(list->mpHead->mpNext), Iter_ae1780(list->mpHead), vec.mpStart);
    Sort_ae1780(vec.mpStart, vec.mpFinish, compare);
    Iter_ae1780 last = CopyBack_ae1780(vec.mpStart, vec.mpFinish, Iter_ae1780(list->mpHead->mpNext));
    if (mnSelection != -1) {
        int32_t index = 0;
        GetIndexFromString(&index, &selected);
        Slot10_ae1560(index, true);
    }
}
#endif

// ---- batch 4: scroll helpers, colours, buffers, gutters ----

// FUNCTION: 0x009c92ae
void* cGZWinListBox::get_scrollbar_v()
{
    void* bar = 0;
    if (reinterpret_cast<cPrim_ae1780*>(this)->GetChildAs(0x4377ea2c, 0x61325a2d, &bar)) {
        static_cast<cIGZUnknown*>(bar)->Release();
        return bar;
    }
    return 0;
}

// FUNCTION: 0x009c92e1
void* cGZWinListBox::get_scrollbar_h()
{
    void* bar = 0;
    if (reinterpret_cast<cPrim_ae1780*>(this)->GetChildAs(0x4377ea2d, 0x61325a2d, &bar)) {
        static_cast<cIGZUnknown*>(bar)->Release();
        return bar;
    }
    return 0;
}

// FUNCTION: 0x009c9e41
uint32_t cGZWinListBox::Slot13_ae1560()
{
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    Iter_ae1780 it(list->mpHead->mpNext);
    uint32_t selection = mnSelection;
    if (static_cast<int32_t>(selection) < 0 || selection >= static_cast<uint32_t>(mnEntryCount)) {
        return 0;
    }
    Advance_ae1780(it, selection);
    return it.mpNode->mData.mnID;
}

// FUNCTION: 0x009c8e46
bool cGZWinListBox::Slot23_ae1560()
{
    int32_t n = static_cast<int32_t>(Slot30_ae1560());
    if (n > 0) {
        if (mnVisibleLines >= n) {
            Slot29_ae1560(0);
        } else {
            Slot29_ae1560(n - mnVisibleLines);
        }
    }
    return true;
}

// FUNCTION: 0x009c8e72
bool cGZWinListBox::Slot20_ae1560()
{
    if (Slot30_ae1560() != 0 && mnSelection > 0 && mnSelection != -1) {
        Slot10_ae1560(mnSelection - 1, 0);
        return true;
    }
    return false;
}

// FUNCTION: 0x009c8ec4
bool cGZWinListBox::Slot24_ae1560()
{
    if (static_cast<int32_t>(Slot30_ae1560()) > 0) {
        int32_t top = mnTopIndex - mnVisibleLines + 1;
        if (top < 0) {
            top = 0;
        }
        Slot29_ae1560(top);
        Slot10_ae1560(top, 0);
    }
    return true;
}

// FUNCTION: 0x009c8ef3
bool cGZWinListBox::Slot25_ae1560()
{
    int32_t top = mnTopIndex;
    int32_t n = static_cast<int32_t>(Slot30_ae1560());
    if (n > 0) {
        int32_t limit = n - mnVisibleLines;
        if (mnTopIndex < limit) {
            top = top + mnVisibleLines - 1;
            if (mnTopIndex > n - mnVisibleLines) {
                top = limit;
            }
            Slot29_ae1560(top);
            Slot10_ae1560(mnVisibleLines + top, 0);
        }
    }
    return true;
}

// FUNCTION: 0x009c88e2
void cGZWinListBox::Slot37_ae1560(void* a)
{
    cIGZUnknown* buffer = static_cast<cIGZUnknown*>(a);
    if (buffer) {
        buffer->AddRef();
    }
    if (mpLineItemBackground) {
        static_cast<cIGZUnknown*>(mpLineItemBackground)->Release();
    }
    mpLineItemBackground = buffer;
}

// FUNCTION: 0x009c8909
void cGZWinListBox::SetPopupBackgroundBuffer(void* a)
{
    cIGZUnknown* buffer = static_cast<cIGZUnknown*>(a);
    if (buffer) {
        buffer->AddRef();
    }
    if (mpPopupBackground) {
        static_cast<cIGZUnknown*>(mpPopupBackground)->Release();
    }
    mpPopupBackground = buffer;
}

// FUNCTION: 0x009c89a4
bool cGZWinListBox::Slot40_ae1560(int32_t a, void* b)
{
    int32_t index = a;
    if (index < 0 || index >= 3) {
        return false;
    }
    uint32_t color = mnColors[index];
    if (color == 0xdeadbeef) {
        return false;
    }
    *static_cast<uint32_t*>(b) = color;
    return true;
}

// FUNCTION: 0x009c8a09
bool cGZWinListBox::Slot43_ae1560(void* a)
{
    if (mnHighlightColor == 0xdeadbeef) {
        return false;
    }
    *static_cast<uint32_t*>(a) = ConvertPackedRGBToNative(mnHighlightColor);
    return true;
}

// FUNCTION: 0x009c89df
void cGZWinListBox::Slot42_ae1560(uint32_t a)
{
    mnHighlightColor = ConvertNativeToPackedRGB(a);
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009c8f70
bool cGZWinListBox::Slot61_ae1560(uint32_t a)
{
    mnMinLineHeight = *reinterpret_cast<uint8_t*>(&a);
    CalculateAllMetrics();
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009c8848
bool cGZWinListBox::Slot57_ae1560(uint32_t a, uint32_t b)
{
    mcScrollbarGutterX = *reinterpret_cast<int8_t*>(&a);
    mcScrollbarGutterY = *reinterpret_cast<int8_t*>(&b);
    CalculateAllMetrics();
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009c888e
bool cGZWinListBox::Slot59_ae1560(uint32_t a, uint32_t b)
{
    mcTextGutterX = *reinterpret_cast<int8_t*>(&a);
    mcTextGutterY = *reinterpret_cast<int8_t*>(&b);
    CalculateAllMetrics();
    InvalidateSelfAndParents();
    return true;
}

// FUNCTION: 0x009ca6d0
bool cGZWinListBox::GetStringFromIndex(uint32_t a, void* b)
{
    cRZString* text;
    if (GetStringAddressFromIndex(a, &text)) {
        *static_cast<cRZString*>(b) = *text;
        return true;
    }
    return false;
}

// ---- batch 5: interface, fonts, colours, string lookups, scrolling ----

// The window manager, seen through the one slot the dialog end uses.
struct cWM_ae1780 {
    virtual void M0();
    virtual void M1();
    virtual void M2();
    virtual void M3();
    virtual void M4();
    virtual void M5();
    virtual void M6();
    virtual void M7();
    virtual void M8();
    virtual void Notify(uint32_t kind, void* source, uint32_t value);
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
    virtual void* GetCaptureWindow();
    virtual void ReleaseCapture(void* win);
};

// FUNCTION: 0x009c83de
bool cGZWinListBox::QueryInterface(unsigned int riid, void** ppvObj)
{
    if (riid == 0x4132242b) {
        if (ppvObj == 0) {
            return false;
        }
        *ppvObj = static_cast<cUnk00ae1560*>(this);
        AddRef();
        return true;
    }
    return cGZWin::QueryInterface(riid, ppvObj);
}

// FUNCTION: 0x009c8934
void cGZWinListBox::Slot38_ae1560(void* a)
{
    cIGZUnknown* font = static_cast<cIGZUnknown*>(a);
    if (font) {
        font->AddRef();
    }
    if (mpFont) {
        static_cast<cIGZUnknown*>(mpFont)->Release();
    }
    mpFont = font;
    CalculateAllMetrics();
}

// FUNCTION: 0x009c91b4
bool cGZWinListBox::end_dialog(uint32_t a)
{
    if (!mbPopup) {
        return false;
    }
    cWM_ae1780* manager = static_cast<cWM_ae1780*>(reinterpret_cast<cPrim_ae1780*>(this)->GetWindowManager());
    manager->Notify(0xf, Slot03_ae1560(), a);
    return true;
}

// FUNCTION: 0x009c87c3
void cGZWinListBox::Slot55_ae1560(uint32_t a, uint32_t b)
{
    mnOutlineColorA = ConvertNativeToPackedRGB(a);
    mnOutlineColorB = ConvertNativeToPackedRGB(b);
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009c87fe
bool cGZWinListBox::Slot56_ae1560(void* a, void* b)
{
    if (mnOutlineColorA == 0xdeadbeef || mnOutlineColorB == 0xdeadbeef) {
        return false;
    }
    *static_cast<uint32_t*>(a) = ConvertPackedRGBToNative(mnOutlineColorA);
    *static_cast<uint32_t*>(b) = ConvertPackedRGBToNative(mnOutlineColorB);
    return true;
}

// FUNCTION: 0x009c8969
bool cGZWinListBox::Slot39_ae1560(uint32_t a, uint32_t b)
{
    int32_t index = static_cast<int32_t>(a);
    if (index < 0 || index >= 3) {
        return false;
    }
    bool same = mnColors[index] == b;
    mnColors[index] = b;
    if (same) {
        InvalidateSelfAndParents();
    }
    return true;
}

// FUNCTION: 0x009c8a3f
void cGZWinListBox::Slot46_ae1560(float alpha)
{
    mfHighlightFillAlpha = alpha;
    if (alpha > 1.0f) {
        mfHighlightFillAlpha = 1.0f;
    }
    if (mfHighlightFillAlpha < 0.0f) {
        mfHighlightFillAlpha = 0.0f;
    }
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009c9cfa
bool cGZWinListBox::Slot28_ae1560(uint32_t a)
{
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    int32_t index = 0;
    for (Node_ae1780* node = list->mpHead->mpNext; node != list->mpHead; node = node->mpNext) {
        if (node->mData.mText.BeginsWith(reinterpret_cast<const char*>(&a), 1)) {
            Slot10_ae1560(index, true);
            return true;
        }
        ++index;
    }
    return false;
}

// FUNCTION: 0x009c8af2
bool cGZWinListBox::GZCharacter(void* a)
{
    int32_t index;
    if (GetIndexFromString(&index, a)) {
        return Slot04_ae1560(index);
    }
    return false;
}

// FUNCTION: 0x009c9e74
bool cGZWinListBox::Slot05_ae1560(void* a)
{
    cRZString text(*static_cast<cIGZString*>(a));
    return GZCharacter(&text);
}

// FUNCTION: 0x009c9155
void cGZWinListBox::RemoveScrollBar(bool a, bool b)
{
    if (a) {
        void* child = GetChildWindowFromID(0x4377ea2c);
        if (child) {
            reinterpret_cast<cPrim_ae1780*>(this)->ChildDelete(child);
        }
    }
    if (b) {
        void* child = GetChildWindowFromID(0x4377ea2d);
        if (child) {
            reinterpret_cast<cPrim_ae1780*>(this)->ChildDelete(child);
        }
    }
}

// FUNCTION: 0x009c9bd7
bool cGZWinListBox::Slot50_ae1560(void* a, void* b)
{
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    int32_t index = 0;
    for (Node_ae1780* node = list->mpHead->mpNext; node != list->mpHead; node = node->mpNext) {
        if (static_cast<cIGZString*>(b)->IsEqual(node->mData.mText, true)) {
            *static_cast<int32_t*>(a) = index;
            return true;
        }
        ++index;
    }
    return false;
}

// FUNCTION: 0x009c9ebb
bool cGZWinListBox::Slot49_ae1560(int32_t a, void* b)
{
    cRZString text;
    bool found = GetStringFromIndex(a, &text);
    if (found) {
        static_cast<cIGZString*>(b)->Copy(text);
    }
    return found;
}

// FUNCTION: 0x009c8dd1
void cGZWinListBox::Slot29_ae1560(uint32_t a)
{
    mnTopIndex = a;
    if (static_cast<int32_t>(Slot30_ae1560()) > mnVisibleLines) {
        if (mnTopIndex > static_cast<int32_t>(Slot30_ae1560()) - mnVisibleLines) {
            mnTopIndex = static_cast<int32_t>(Slot30_ae1560()) - mnVisibleLines;
        }
    }
    if (mnTopIndex < 0) {
        mnTopIndex = 0;
    }
    SetScrollBarValue();
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009c8d8f
void cGZWinListBox::Slot27_ae1560(uint32_t a)
{
    int32_t index = static_cast<int32_t>(a);
    if (index < mnTopIndex) {
        Slot29_ae1560(index);
    } else if (index > mnVisibleLines + mnTopIndex - 1) {
        Slot29_ae1560(index - mnVisibleLines + 1);
    }
    SetScrollBarValue();
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009c9b9b
bool cGZWinListBox::GetStringAddressFromIndex(uint32_t a, void* b)
{
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    uint32_t count = mnEntryCount;
    if (static_cast<int32_t>(a) <= static_cast<int32_t>(count - 1)) {
        Node_ae1780* node = list->mpHead->mpNext;
        for (uint32_t i = 0; i < count; ++i) {
            if (i == a) {
                *static_cast<cRZString**>(b) = &node->mData.mText;
                return true;
            }
            node = node->mpNext;
        }
    }
    return false;
}

// ---- batch 6: scroll bars, area changes, selection by id, list edits ----

// A rectangle of four coordinates, as the original copies it as a whole.
struct Rect_ae1780 {
    int32_t v[4];
    // STUB: 0x007c1870
    bool IsEmpty() const;
    void Offset(int32_t dx, int32_t dy)
    {
        v[0] += dx;
        v[2] += dx;
        v[1] += dy;
        v[3] += dy;
    }
    void Deflate(int32_t dx, int32_t dy)
    {
        v[0] += dx;
        v[2] -= dx;
        v[1] += dy;
        v[3] -= dy;
    }
};

// An image (a buffer) seen through the one slot used here.
struct cImage_ae1780 {
    virtual void I0();
    virtual void I1();
    virtual void I2();
    virtual void I3();
    virtual void I4();
    virtual void I5();
    virtual void I6();
    virtual void I7();
    virtual void I8();
    virtual int32_t GetWidth();
    virtual int32_t GetHeight();
    virtual void I11();
    virtual const Rect_ae1780* GetRect();
};

// The scroll bar the list finds by its id, seen through the slots used here.
struct cScrollBar_ae1780 {
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void* GetWindow();
    virtual void S4();
    virtual void SetValue(uint32_t value);
    virtual int32_t GetPosition();
    virtual void SetRange(int32_t low, int32_t high);
    virtual void S8();
    virtual void S9();
    virtual void S10();
    virtual void S11();
    virtual void S12();
    virtual void S13();
    virtual void S14();
    virtual void SetPage(int32_t value, int32_t pages);
    virtual void S16();
    virtual void SetImage(const Rect_ae1780* rect, void* image, uint32_t flag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009c9a90 score 31 (same logic; the original schedules the width arithmetic before the height call, other registers)
void cGZWinListBox::SetScrollBarSizes()
{
    cScrollBar_ae1780* bar = static_cast<cScrollBar_ae1780*>(get_scrollbar_v());
    if (bar) {
        int32_t barWidth = static_cast<cGZWin*>(bar->GetWindow())->GetW();
        int32_t width = GetW();
        int32_t height = GetH();
        static_cast<cGZWin*>(bar->GetWindow())->Slot07_add348(width - barWidth, 0, barWidth + (width - barWidth), height);
    }
}
#endif

// FUNCTION: 0x009c9a19
void cGZWinListBox::SetScrollBarValue()
{
    cScrollBar_ae1780* bar = static_cast<cScrollBar_ae1780*>(get_scrollbar_v());
    if (bar && mnVisibleLines != 0) {
        int32_t high = static_cast<int32_t>(Slot30_ae1560()) - mnVisibleLines;
        if (high < 0) {
            high = 0;
        }
        bar->SetRange(0, high);
        bar->SetPage(high, static_cast<int32_t>(Slot30_ae1560()) / mnVisibleLines + 1);
        bar->SetValue(Slot33_ae1560());
    }
}

// FUNCTION: 0x009c870b
void cGZWinListBox::Slot07_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    bool changed;
    if (c - a == GetW() && d - b == GetH()) {
        changed = false;
    } else {
        changed = true;
    }
    cGZWin::Slot07_add348(a, b, c, d);
    CalculateAllMetrics();
    if (changed) {
        SetScrollBarSizes();
        SetScrollBarValue();
    }
    InvalidateSelfAndParents();
}

// FUNCTION: 0x009c9379
uint32_t cGZWinListBox::Slot68_adc8d8(uint32_t a, uint32_t b)
{
    if (a == 2) {
        cScrollBar_ae1780* bar = static_cast<cScrollBar_ae1780*>(get_scrollbar_v());
        if (bar) {
            static_cast<cGZWin*>(bar->GetWindow())->Slot68_adc8d8(2, b);
        }
        bar = static_cast<cScrollBar_ae1780*>(get_scrollbar_h());
        if (bar) {
            static_cast<cGZWin*>(bar->GetWindow())->Slot68_adc8d8(2, b);
        }
    }
    return cGZWin::Slot68_adc8d8(a, b);
}

// FUNCTION: 0x009c91ee
bool cGZWinListBox::emit_selection_changed_msg()
{
    if (mbPostMessages) {
        reinterpret_cast<cPrim_ae1780*>(this)->PostMsg5(field4c, 3, 0x8710e0f, Slot48_adda20(), Slot12_ae1560());
    } else {
        reinterpret_cast<cPrim_ae1780*>(this)->SendMsg5(field4c, 3, 0x8710e0f, Slot48_adda20(), Slot12_ae1560());
    }
    return true;
}

// FUNCTION: 0x009c924e
bool cGZWinListBox::emit_dblclick_msg()
{
    if (mbPostMessages) {
        reinterpret_cast<cPrim_ae1780*>(this)->PostMsg5(field4c, 3, 0x8710e10, Slot48_adda20(), Slot12_ae1560());
    } else {
        reinterpret_cast<cPrim_ae1780*>(this)->SendMsg5(field4c, 3, 0x8710e10, Slot48_adda20(), Slot12_ae1560());
    }
    return true;
}

// FUNCTION: 0x009c8a7e
bool cGZWinListBox::Slot09_ae1560()
{
    if (mnLineHeight == 0) {
        return false;
    }
    int32_t height = GetH();
    int32_t gutter = mcTextGutterY * 2;
    int32_t lines = (height - gutter) / mnLineHeight;
    int32_t newHeight = mnLineHeight * lines + gutter;
    if (newHeight != height) {
        SetSize(newHeight);
        mnVisibleLines = lines;
    }
    SetScrollBarSizes();
    SetScrollBarValue();
    InvalidateSelfAndParents();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ca084 score 8 (same logic; the end iterator temporary is reserved before this is saved)
void cGZWinListBox::Slot06_ae1560()
{
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    list->erase(Iter_ae1780(list->mpHead->mpNext), Iter_ae1780(list->mpHead));
    mnEntryCount = 0;
    mnSelection = -1;
    mnTopIndex = 0;
    CalculateAllMetrics();
    RemoveScrollBar(true, true);
    InvalidateSelfAndParents();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c9c82 score 25 (same logic; the original loop re-reads the list head, Slot26 is tested as a bool)
bool cGZWinListBox::Slot11_ae1560(uint32_t a, uint32_t b)
{
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    Node_ae1780* end = list->mpHead;
    Node_ae1780* node = end->mpNext;
    int32_t index = 0;
    for (; node != list->mpHead; node = node->mpNext) {
        if (node->mData.mnID == a) {
            break;
        }
        ++index;
    }
    if (node == end) {
        return false;
    }
    if (index != mnSelection) {
        mnSelection = index;
        if (index >= 0) {
            if (!static_cast<uint8_t>(Slot26_ae1560(index))) {
                Slot27_ae1560(index);
            }
        }
    }
    if (*reinterpret_cast<bool*>(&b) && !mbPopup) {
        emit_selection_changed_msg();
    }
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c98bd score 29 (same logic; the shared argument pushes sit before the branch in the original)
bool cGZWinListBox::Slot62_ae1560(void* a, void* b)
{
    cIGZUnknown* image = static_cast<cIGZUnknown*>(a);
    if (image) {
        image->AddRef();
    }
    if (mpScrollBarImageV) {
        static_cast<cIGZUnknown*>(mpScrollBarImageV)->Release();
    }
    mpScrollBarImageV = image;
    Rect_ae1780* rect = reinterpret_cast<Rect_ae1780*>(mnScrollBarRectV);
    *rect = *static_cast<Rect_ae1780*>(b);
    cScrollBar_ae1780* bar = static_cast<cScrollBar_ae1780*>(get_scrollbar_v());
    if (bar) {
        cImage_ae1780* img = static_cast<cImage_ae1780*>(mpScrollBarImageV);
        if (img) {
            bar->SetImage(rect->IsEmpty() ? img->GetRect() : rect, img, 0);
        }
    }
    return true;
}
#endif

// FUNCTION: 0x009c8f99
int32_t cGZWinListBox::Slot34_ae1560(int32_t /*a*/, int32_t b, bool c)
{
    int32_t count = static_cast<int32_t>(Slot30_ae1560());
    if (count != 0) {
        int32_t y = b;
        bool clip = c;
        if (y < 0 && clip) {
            y = 0;
        }
        if (y >= static_cast<int32_t>(GetH()) && clip) {
            y = GetH() - 1;
        }
        int32_t index = (y - mcTextGutterY) / mnLineHeight + mnTopIndex;
        if (index < count) {
            return index;
        }
        if (clip) {
            return count - 1;
        }
    }
    return -1;
}

// STUB: 0x0043ab70
bool StringEqual_ae1780(const std::string* a, const std::string* b);

#ifdef OB_DRAFTS
// CLOSE: 0x009c9c20 score 17 (same logic; the null check of the string base is computed from a register in the original)
bool cGZWinListBox::GetIndexFromString(void* a, void* b)
{
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    int32_t index = 0;
    Node_ae1780* node = list->mpHead->mpNext;
    if (node != list->mpHead) {
        const std::string* other = static_cast<cRZString*>(b);
        do {
            if (StringEqual_ae1780(&node->mData.mText, other)) {
                *static_cast<int32_t*>(a) = index;
                return true;
            }
            node = node->mpNext;
            ++index;
        } while (node != list->mpHead);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ca0df score 25 (same logic; the original loop re-reads the list head)
bool cGZWinListBox::RemoveStringAtIndex(uint32_t a)
{
    if (mnEntryCount == 0) {
        return false;
    }
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    int32_t index = static_cast<int32_t>(a);
    if (index == 0) {
        list->pop_front();
    } else if (index != -2 && index < mnEntryCount) {
        int32_t i = 0;
        for (Node_ae1780* node = list->mpHead->mpNext; node != list->mpHead; node = node->mpNext) {
            if (i == index) {
                list->erase(Iter_ae1780(node));
                break;
            }
            ++i;
        }
    } else {
        list->pop_back();
    }
    --mnEntryCount;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009cac56 score 38 (same logic; other registers, the original loop re-reads the list head)
bool cGZWinListBox::InsertEntryAtIndex(uint32_t a, void* b)
{
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    int32_t index = static_cast<int32_t>(a);
    const Entry_ae1780& entry = *static_cast<Entry_ae1780*>(b);
    if (index == 0) {
        list->push_front(entry);
    } else if (index != -2 && index < static_cast<int32_t>(Slot30_ae1560())) {
        int32_t i = 0;
        for (Node_ae1780* node = list->mpHead->mpNext; node != list->mpHead; node = node->mpNext) {
            if (i == index) {
                list->insert(Iter_ae1780(node), entry);
                break;
            }
            ++i;
        }
    } else {
        list->push_back(entry);
    }
    ++mnEntryCount;
    return true;
}
#endif

// ---- batch 7: metrics, sizing to contents, removal, selection ----

// The font, seen through the slots used here.
struct cFont_ae1780 {
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
    virtual int32_t GetLineHeight();
    virtual void F36();
    virtual void F37();
    virtual void F38();
    virtual void F39();
    virtual void F40();
    virtual void F41();
    virtual uint32_t MeasureText(const char* text, uint32_t length, int32_t width, uint32_t flags);
    virtual void F43();
    virtual void F44();
    virtual void F45();
    virtual void F46();
    virtual void F47();
    virtual void F48();
    virtual uint32_t MeasureString(const char* text, uint32_t length, uint32_t* count);
    virtual void F50();
    virtual void DrawText(uint32_t context, int32_t x, int32_t y, const char* text, uint32_t count, uint32_t color, uint32_t flags, uint32_t a, uint32_t b);
};

// STUB: 0x00913c72
cWCM_ae1780* Fn00913c72();

// FUNCTION: 0x009c8e9d
bool cGZWinListBox::Slot21_ae1560()
{
    int32_t n = static_cast<int32_t>(Slot30_ae1560());
    if (n > 0 && mnSelection < n - 1) {
        Slot10_ae1560(mnSelection + 1, 0);
        return true;
    }
    return false;
}

// FUNCTION: 0x009c8cee
bool cGZWinListBox::Slot10_ae1560(uint32_t a, uint32_t b)
{
    int32_t index = static_cast<int32_t>(a);
    if (index != -1) {
        if (index < 0 || index >= static_cast<int32_t>(Slot30_ae1560())) {
            if (index < 0) {
                index = 0;
            }
            if (index >= static_cast<int32_t>(Slot30_ae1560())) {
                index = static_cast<int32_t>(Slot30_ae1560()) - 1;
            }
        }
    }
    if (index != mnSelection) {
        mnSelection = index;
        if (index >= 0) {
            if (!static_cast<uint8_t>(Slot26_ae1560(index))) {
                Slot27_ae1560(index);
            }
        }
    }
    if (*reinterpret_cast<bool*>(&b) && !mbPopup) {
        emit_selection_changed_msg();
    }
    InvalidateSelfAndParents();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c8666 score 21 (same logic; register use, and the original divides signed)
void cGZWinListBox::CalculateAllMetrics()
{
    mnLineHeight = mnMinLineHeight;
    if (mpLineItemBackground) {
        int32_t height = mnLineHeight;
        mnLineHeight = height > static_cast<cImage_ae1780*>(mpLineItemBackground)->GetHeight() ? height : static_cast<cImage_ae1780*>(mpLineItemBackground)->GetHeight();
    }
    if (mpFont) {
        int32_t height = mnLineHeight;
        mnLineHeight = height > static_cast<cFont_ae1780*>(mpFont)->GetLineHeight() ? height : static_cast<cFont_ae1780*>(mpFont)->GetLineHeight();
    }
    if (mnLineHeight == 0) {
        mnVisibleLines = 0;
    } else {
        mnVisibleLines = (static_cast<int32_t>(GetH()) - mcTextGutterY * 2) / mnLineHeight;
    }
}
#endif

// FUNCTION: 0x009c85ee
bool cGZWinListBox::Slot04_ae1d24()
{
    HideWindow();
    if (mpPopupBackground) {
        static_cast<cIGZUnknown*>(mpPopupBackground)->Release();
        mpPopupBackground = 0;
    }
    if (mpLineItemBackground) {
        static_cast<cIGZUnknown*>(mpLineItemBackground)->Release();
        mpLineItemBackground = 0;
    }
    if (mpFont) {
        static_cast<cIGZUnknown*>(mpFont)->Release();
        mpFont = 0;
    }
    if (mpScrollBarImageV) {
        static_cast<cIGZUnknown*>(mpScrollBarImageV)->Release();
        mpScrollBarImageV = 0;
    }
    if (mpScrollBarImageH) {
        static_cast<cIGZUnknown*>(mpScrollBarImageH)->Release();
        mpScrollBarImageH = 0;
    }
    return cGZWin::Slot04_ae1d24();
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c9aeb score 41 (same logic; the rectangle arithmetic is scheduled differently)
void cGZWinListBox::Slot19_ae1560(void* a)
{
    Rect_ae1780* rect = static_cast<Rect_ae1780*>(a);
    reinterpret_cast<cPrim_ae1780*>(this)->GetArea(rect);
    rect->Offset(-rect->v[0], -rect->v[1]);
    rect->Deflate(mcTextGutterX, mcTextGutterY);
    cScrollBar_ae1780* bar = static_cast<cScrollBar_ae1780*>(get_scrollbar_v());
    if (bar) {
        rect->v[2] -= static_cast<cGZWin*>(bar->GetWindow())->GetW() + mcScrollbarGutterX;
    }
}
#endif

// FUNCTION: 0x009c8b24
bool cGZWinListBox::Slot08_ae1560(void* a, int32_t b)
{
    int32_t count = static_cast<int32_t>(Slot30_ae1560());
    if (count == 0) {
        return false;
    }
    int32_t index = b;
    if (index == -2 || index >= count) {
        index = count - 1;
    } else if (index < 0) {
        index = 0;
    }
    cRZString* text;
    if (GetStringAddressFromIndex(index, &text)) {
        text->Copy(*static_cast<cIGZString*>(a));
        if (mbPopup) {
            if (mbFitHeight) {
                Slot47_ae1560();
            }
            if (mbFitWidth) {
                Slot48_ae1560();
            }
        }
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}

// FUNCTION: 0x009c9d3b
bool cGZWinListBox::Slot48_ae1560()
{
    if (mbPopup) {
        mbFitWidth = true;
        List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
        uint32_t widest = 1;
        if (list->mpHead->mpNext != list->mpHead) {
            if (!mpFont) {
                Slot38_ae1560(Fn00913c72()->GetFont(0x68963c4c));
            }
            for (Node_ae1780* node = list->mpHead->mpNext; node != list->mpHead; node = node->mpNext) {
                uint32_t length = node->mData.mText.size();
                uint32_t width = static_cast<cFont_ae1780*>(mpFont)->MeasureString(node->mData.mText.c_str(), length, &length);
                if (widest < width) {
                    widest = width;
                }
            }
        }
        SetH(widest + mcTextGutterX * 2);
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009c93d7 score 6 (same logic; the vtable load of the top-line call is scheduled earlier in the original)
bool cGZWinListBox::Slot04_ae1560(uint32_t a)
{
    int32_t index = static_cast<int32_t>(a);
    int32_t last = static_cast<int32_t>(Slot30_ae1560()) - 1;
    if (index > last) {
        return false;
    }
    RemoveStringAtIndex(index);
    int32_t top = mnTopIndex;
    if (top > index) {
        --top;
    }
    Slot29_ae1560(top);
    if (index == mnSelection) {
        if (index == last) {
            Slot10_ae1560(mnSelection - 1, true);
        }
    } else if (index < mnSelection) {
        Slot10_ae1560(mnSelection - 1, true);
    }
    if (mbPopup) {
        if (mbFitHeight) {
            Slot47_ae1560();
        }
        if (mbFitWidth) {
            Slot48_ae1560();
        }
    }
    if (get_scrollbar_v() && static_cast<int32_t>(Slot30_ae1560()) <= mnVisibleLines) {
        RemoveScrollBar(true, false);
        Slot29_ae1560(0);
    } else {
        SetScrollBarSizes();
        SetScrollBarValue();
    }
    InvalidateSelfAndParents();
    return true;
}
#endif

// ---- batch 8: adding the scroll bar, key presses, inserting strings, fitting the box ----

#ifdef OB_DRAFTS
// CLOSE: 0x009c993a score 32 (same logic; the original reads the image through the address of its field)
bool cGZWinListBox::AddScrollBar(bool a, bool b)
{
    if (a && mbVScrollEnabled) {
        if (!ChildExists(0x4377ea2c)) {
            cScrollBar_ae1780* bar = static_cast<cScrollBar_ae1780*>(Fn00913c72()->CreateScrollBar(0x4377ea2c, 2, 0, 0, 0));
            if (bar && mpScrollBarImageV) {
                cImage_ae1780* img = static_cast<cImage_ae1780*>(mpScrollBarImageV);
                Rect_ae1780* rect = reinterpret_cast<Rect_ae1780*>(mnScrollBarRectV);
                if (rect->IsEmpty()) {
                    bar->SetImage(img->GetRect(), img, 0);
                } else {
                    bar->SetImage(rect, img, 0);
                }
            }
            static_cast<cGZWin*>(bar->GetWindow())->SetH(0x10);
            Slot14_adc8d8(bar->GetWindow());
            ChildToFront_2(bar->GetWindow());
            SetScrollBarSizes();
            SetScrollBarValue();
            static_cast<cIGZUnknown*>(static_cast<void*>(bar))->Release();
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c8bd1 score 76 (same logic and switch; register use and the order of the key subtraction)
bool cGZWinListBox::GZOnKeyDown(uint32_t a, uint32_t b)
{
    int32_t selection = mnSelection;
    switch (a) {
    case 0xd:
        Slot10_ae1560(selection, true);
        if (mbPopup) {
            end_dialog(mnSelection);
            return true;
        }
        return emit_dblclick_msg();
    default:
        if (mbPopup) {
            return true;
        }
        return reinterpret_cast<cPrim_ae1780*>(this)->SendMsg5(field4c, 5, a, b, 0);
    case 0x1b:
        if (mbPopup) {
            end_dialog(-1);
            return true;
        }
        return reinterpret_cast<cPrim_ae1780*>(this)->SendMsg5(field4c, 5, 0x1b, b, 0);
    case 0x21:
        Slot24_ae1560();
        break;
    case 0x22:
        Slot25_ae1560();
        break;
    case 0x26:
        Slot20_ae1560();
        break;
    case 0x28:
        Slot21_ae1560();
        break;
    }
    if (selection != mnSelection) {
        Slot10_ae1560(mnSelection, true);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c9f12 score 43 (same logic; the original keeps the count and index in registers)
bool cGZWinListBox::Slot07_ae1560(void* a, int32_t b, uint32_t c)
{
    int32_t count = static_cast<int32_t>(Slot30_ae1560());
    int32_t index = b;
    if (index == -2 || index > count) {
        index = count;
    } else if (index < 0) {
        index = 0;
    }
    {
        Entry_ae1780 entry(*static_cast<cIGZString*>(a), c);
        InsertEntryAtIndex(index, &entry);
    }
    if (count == 0 && mnSelection != -1) {
        Slot10_ae1560(0, true);
    } else if (index <= mnSelection && mnSelection != -1) {
        Slot10_ae1560(mnSelection + 1, true);
    }
    if (mbPopup) {
        if (mbFitHeight) {
            Slot47_ae1560();
        }
        if (mbFitWidth) {
            Slot48_ae1560();
        }
    }
    if (!get_scrollbar_v() && static_cast<int32_t>(Slot30_ae1560()) > mnVisibleLines) {
        AddScrollBar(true, false);
    } else {
        SetScrollBarSizes();
        SetScrollBarValue();
    }
    InvalidateSelfAndParents();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009c900f score 41 (same logic; register use of the height and available-height temporaries)
bool cGZWinListBox::Slot47_ae1560()
{
    if (mbPopup) {
        int32_t count = static_cast<int32_t>(Slot30_ae1560());
        mbFitHeight = true;
        if (count >= mnVisibleLines && count > 0) {
            int32_t height = mnLineHeight * count + mcTextGutterY * 2;
            int32_t available;
            if (GetParentWin()) {
                available = static_cast<cGZWin*>(reinterpret_cast<cPrim_ae1780*>(this)->GetParentWin())->GetH();
            } else {
                available = 0x7fffffff;
            }
            available = available - GetT() - 1 - 1;
            if (height <= available) {
                SetSize_2(GetW(), height);
                mnVisibleLines = count;
                Slot29_ae1560(0);
                RemoveScrollBar(true, false);
            } else {
                SetSize_2(GetW(), available);
                mnVisibleLines = (available - mcTextGutterY * 2) / mnLineHeight;
                AddScrollBar(true, false);
                Slot09_ae1560();
            }
            SetScrollBarSizes();
            SetScrollBarValue();
            InvalidateSelfAndParents();
            return true;
        }
    }
    return false;
}
#endif

// ---- batch 9: the mouse ----

// A window, seen through the slots used on the scroll bar window.
struct cWin_ae1780 {
    virtual void X0();
    virtual void X1();
    virtual void X2();
    virtual bool DoMessage(void* message);
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
    virtual void X21();
    virtual void X22();
    virtual void X23();
    virtual void X24();
    virtual void X25();
    virtual void X26();
    virtual void X27();
    virtual void X28();
    virtual void X29();
    virtual void X30();
    virtual void X31();
    virtual void X32();
    virtual void X33();
    virtual void X34();
    virtual void X35();
    virtual void X36();
    virtual void X37();
    virtual void X38();
    virtual void X39();
    virtual void X40();
    virtual int32_t GetW();
    virtual int32_t GetH();
};

// The message record handed to a window.
struct Message_ae1780 {
    uint32_t mnType;
    int32_t mnX;
    int32_t mnY;
    uint32_t mnFlags;
};

// The click timer.
struct cTimer_ae1780 {
    // STUB: 0x00890198
    uint32_t GetElapsedTime() const;
    // STUB: 0x0089058f
    void Restart();
};

// STUB: 0x00913c46
cWM_ae1780* Fn00913c46();

#ifdef OB_DRAFTS
// CLOSE: 0x009c94ad score 20 (same logic; the original shares one end_dialog call tail between both exits)
bool cGZWinListBox::GZOnMouseDownL(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t index = Slot34_ae1560(a, b, true);
    if (GZAmCapturing()) {
        if (!IsPointInWindowWindowCoordinates(a, b)) {
            end_dialog(-1);
        } else {
            cScrollBar_ae1780* bar = static_cast<cScrollBar_ae1780*>(get_scrollbar_v());
            if (bar) {
                int32_t x = a;
                int32_t y = b;
                cWin_ae1780* win = static_cast<cWin_ae1780*>(bar->GetWindow());
                reinterpret_cast<cPrim_ae1780*>(this)->WindowToWindowCoordinates(win, &x, &y);
                if (x >= 0 && y >= 0 && x < win->GetW() && y < win->GetH()) {
                    Message_ae1780 message;
                    message.mnType = 7;
                    message.mnX = x;
                    message.mnY = y;
                    message.mnFlags = c;
                    bool result = win->DoMessage(&message);
                    mbScrollBarCapture = Fn00913c46()->GetCaptureWindow() == win;
                    Fn0099bdfe();
                    return result;
                }
            }
            end_dialog(index);
        }
    } else {
        Fn0099bdfe();
        if (index < static_cast<int32_t>(Slot30_ae1560())) {
            if (index != static_cast<int32_t>(Slot12_ae1560())) {
                Slot10_ae1560(index, true);
            }
        }
        if (mnLastClickIndex == index) {
            cWCM_ae1780* manager = Fn00913c72();
            if (static_cast<cTimer_ae1780*>(mpClickTimer)->GetElapsedTime() < manager->GetDoubleClickTime()) {
                mbDoubleClick = true;
            }
        } else {
            mnLastClickIndex = index;
        }
        static_cast<cTimer_ae1780*>(mpClickTimer)->Restart();
    }
    return true;
}
#endif

// FUNCTION: 0x009c9623
bool cGZWinListBox::GZOnMouseUpL(uint32_t a, uint32_t b, uint32_t c)
{
    if (GZAmCapturing()) {
        if (mbPopup && (mbScrollBarCapture || IsPointInWindowWindowCoordinates(a, b))) {
            cScrollBar_ae1780* bar = static_cast<cScrollBar_ae1780*>(get_scrollbar_v());
            if (bar) {
                int32_t y;
                int32_t x = a;
                y = b;
                cWin_ae1780* win = static_cast<cWin_ae1780*>(bar->GetWindow());
                reinterpret_cast<cPrim_ae1780*>(this)->WindowToWindowCoordinates(win, &x, &y);
                if (mbScrollBarCapture || (x >= 0 && y >= 0 && x < win->GetW() && y < win->GetH())) {
                    Message_ae1780 message;
                    message.mnType = 10;
                    message.mnX = x;
                    message.mnY = y;
                    message.mnFlags = c;
                    if (mbScrollBarCapture) {
                        Fn00913c46()->ReleaseCapture(win);
                    }
                    bool result = win->DoMessage(&message);
                    mbScrollBarCapture = Fn00913c46()->GetCaptureWindow() != win;
                    Fn0099bdfe();
                    return result;
                }
            }
        }
        if (!mbPopup) {
            GZReleaseCapture();
        }
        if (mbDoubleClick) {
            emit_dblclick_msg();
            mnLastClickIndex = -1;
            mbDoubleClick = false;
        }
    }
    return true;
}

// FUNCTION: 0x009c9769
bool cGZWinListBox::GZOnMouseMove(uint32_t a, uint32_t b, uint32_t c)
{
    if (GZAmCapturing() && mbPopup && (mbScrollBarCapture || IsPointInWindowWindowCoordinates(a, b))) {
        cScrollBar_ae1780* bar = static_cast<cScrollBar_ae1780*>(get_scrollbar_v());
        if (bar) {
            int32_t y;
            int32_t x = a;
            y = b;
            cWin_ae1780* win = static_cast<cWin_ae1780*>(bar->GetWindow());
            reinterpret_cast<cPrim_ae1780*>(this)->WindowToWindowCoordinates(win, &x, &y);
            if (mbScrollBarCapture || (x >= 0 && y >= 0 && x < win->GetW() && y < win->GetH())) {
                if (mbScrollBarCapture) {
                    Fn00913c46()->ReleaseCapture(win);
                }
                Message_ae1780 message;
                message.mnType = 13;
                message.mnX = x;
                message.mnY = y;
                message.mnFlags = c;
                bool result = win->DoMessage(&message);
                mbScrollBarCapture = Fn00913c46()->GetCaptureWindow() == win;
                Fn0099bdfe();
                return result;
            }
        }
        int32_t index = (static_cast<int32_t>(b) - mcTextGutterY) / mnLineHeight + mnTopIndex;
        if (mnSelection != index && index < static_cast<int32_t>(Slot30_ae1560())) {
            Slot10_ae1560(index, false);
        }
    }
    return true;
}

// ---- batch 10: initialisation ----

// FUNCTION: 0x009c8415
bool cGZWinListBox::Slot03_ae1d24()
{
    if (get_init_flag()) {
        return true;
    }
    cWCM_ae1780* manager = Fn00913c72();
    if (manager) {
        if (!mpFont) {
            Slot38_ae1560(manager->GetFont(0x68963c4c));
        }
        if (mnOutlineColorA == 0xdeadbeef) {
            mnOutlineColorA = ConvertNativeToPackedRGB(manager->GetColor(0xa8963fad));
        }
        if (mnOutlineColorB == 0xdeadbeef) {
            mnOutlineColorB = ConvertNativeToPackedRGB(manager->GetColor(0x08963faf));
        }
        if (mnColors[1] == 0xdeadbeef) {
            Slot39_ae1560(1, manager->GetColor(0x08963fb9));
        }
        if (mnColors[2] == 0xdeadbeef) {
            Slot39_ae1560(2, manager->GetColor(0x28963fbc));
        }
        if (mnHighlightColor == 0xdeadbeef) {
            Slot42_ae1560(manager->GetColor(0x88963fb4));
        }
    }
    if (mbPopup) {
        CalculateAllMetrics();
        if (mbFitHeight) {
            Slot47_ae1560();
        }
        if (mbFitWidth) {
            Slot48_ae1560();
        }
        Slot29_ae1560(0);
        Slot27_ae1560(mnSelection);
        Fn0099bdfe();
        if (!mpPopupBackground && manager) {
            SetPopupBackgroundBuffer(manager->GetBuffer(0xe8963ee5));
        }
    }
    SetScrollBarSizes();
    SetScrollBarValue();
    CalculateAllMetrics();
    return cGZWin::Slot03_ae1d24();
}

// ---- batch 11: painting ----

// The draw context of the window, seen through the slots used here.
struct cDrawContext_ae1780 {
    virtual void C0();
    virtual void C1();
    virtual void C2();
    virtual void C3();
    virtual void C4();
    virtual void C5();
    virtual void C6();
    virtual void C7();
    virtual void C8();
    virtual void C9();
    virtual void C10();
    virtual void C11();
    virtual void C12();
    virtual void C13();
    virtual void C14();
    virtual void C15();
    virtual void C16();
    virtual void C17();
    virtual void C18();
    virtual void C19();
    virtual void C20();
    virtual void SetColor(uint32_t color);
    virtual void C22();
    virtual void C23();
    virtual void C24();
    virtual void C25();
    virtual void C26();
    virtual void C27();
    virtual void C28();
    virtual void C29();
    virtual void C30();
    virtual void C31();
    virtual void C32();
    virtual void C33();
    virtual void C34();
    virtual void FillRect(const Rect_ae1780* rect);
    virtual void C36();
    virtual void C37();
    virtual void C38();
    virtual void DrawBuffer(void* buffer, const Rect_ae1780* source, const Rect_ae1780* destination, uint32_t a, uint32_t b);
};

// The library functions of the original's string the painting calls out of line.
struct StringOps_ae1780 {
    // STUB: 0x00417a70
    void push_back(char c);
    // STUB: 0x004425c0
    StringOps_ae1780& erase(uint32_t position, uint32_t count);
};

// STUB: 0x008d8800
void RZDrawBltEdge_ae1780(cDrawContext_ae1780* context, void* buffer, const Rect_ae1780* edge, const Rect_ae1780* area, bool flag);

// STUB: 0x008d9470
void RZDraw3DRectangleOutline_ae1780(cDrawContext_ae1780* context, const Rect_ae1780* area, uint32_t colorA, uint32_t colorB);

// STUB: 0x008d9360
void RZDrawRectangleOutline_ae1780(cDrawContext_ae1780* context, const Rect_ae1780* area, uint32_t color, uint32_t width);

#ifdef OB_DRAFTS
// CLOSE: 0x009ca19a score 403 (same logic as the original; the frame layout and register use differ, which moves every offset)
bool cGZWinListBox::GZPaint()
{
    Rect_ae1780 area = *reinterpret_cast<Rect_ae1780*>(reinterpret_cast<char*>(this) + 0x24);
    List_ae1780* list = reinterpret_cast<List_ae1780*>(&mpEntryList);
    Node_ae1780* node = list->mpHead->mpNext;
    int32_t index = 0;
    cScrollBar_ae1780* bar = static_cast<cScrollBar_ae1780*>(get_scrollbar_v());
    if (bar) {
        area.v[2] -= static_cast<cGZWin*>(bar->GetWindow())->GetW() + mcScrollbarGutterX;
        mnTopIndex = bar->GetPosition();
    }
    cDrawContext_ae1780* context = OB_PTR(cDrawContext_ae1780, field6c);
    if (mpLineItemBackground) {
        cImage_ae1780* background = static_cast<cImage_ae1780*>(mpLineItemBackground);
        context->DrawBuffer(background, background->GetRect(), &area, 0, 0);
    } else {
        context->SetColor(GetFillColorRGB());
        context->FillRect(&area);
    }
    Rect_ae1780 edge;
    if (mbPopup && mpPopupBackground) {
        cImage_ae1780* popup = static_cast<cImage_ae1780*>(mpPopupBackground);
        uint32_t bottom = static_cast<uint32_t>(popup->GetHeight()) / 3;
        uint32_t right = static_cast<uint32_t>(popup->GetWidth()) / 3;
        edge.v[0] = 0;
        edge.v[1] = 0;
        edge.v[3] = bottom;
        edge.v[2] = right;
        RZDrawBltEdge_ae1780(OB_PTR(cDrawContext_ae1780, field6c), mpPopupBackground, &edge, &area, false);
    }
    if (mbHighlightEnabled && mfHighlightFillAlpha != 0.0f && mnSelection > -1 && static_cast<uint8_t>(Slot26_ae1560(mnSelection))) {
        Rect_ae1780 highlight;
        highlight.v[0] = area.v[0] + 1;
        highlight.v[2] = area.v[2] - 1;
        highlight.v[1] = (mnSelection - mnTopIndex) * mnLineHeight + area.v[1] + mcTextGutterY;
        highlight.v[3] = highlight.v[1] + mnLineHeight;
        if (highlight.v[3] > area.v[3]) {
            highlight.v[3] = area.v[3];
        }
        if (mfHighlightFillAlpha == 1.0f) {
            OB_PTR(cDrawContext_ae1780, field6c)->SetColor(mnHighlightColor);
            OB_PTR(cDrawContext_ae1780, field6c)->FillRect(&highlight);
        }
    }
    if (mpFont) {
        if (mnTopIndex > 0) {
            do {
                if (node == list->mpHead) {
                    break;
                }
                node = node->mpNext;
                ++index;
            } while (index < mnTopIndex);
        }
        Rect_ae1780 line;
        line.v[0] = area.v[0] + mcTextGutterX;
        line.v[2] = area.v[2] - mcTextGutterX;
        int32_t height = mnLineHeight;
        line.v[1] = mcTextGutterY + (height - static_cast<cFont_ae1780*>(mpFont)->GetLineHeight()) / 2 + area.v[1];
        line.v[3] = height + line.v[1];
        cRZString text;
        uint32_t color = 0;
        bool hasColor;
        int32_t width = area.v[2] - line.v[0];
        int32_t lineNumber = 0;
        while (node != list->mpHead) {
            if (lineNumber >= mnVisibleLines) {
                break;
            }
            text = node->mData.mText;
            if (static_cast<uint8_t>(Slot67_adc8d8(2))) {
                uint32_t candidate = (index == mnSelection && mbHighlightEnabled) ? mnColors[2] : mnColors[0];
                hasColor = candidate != 0xdeadbeef;
                if (hasColor) {
                    color = candidate;
                }
                if (text.BeginsWith("#", 1)) {
                    if (text.BeginsWith("##", 2)) {
                        text = text.Mid(1, 0xffffffff);
                    } else if (text.size() >= 7) {
                        hasColor = true;
                        reinterpret_cast<StringOps_ae1780*>(static_cast<std::string*>(&text))->push_back(0);
                        int32_t red;
                        int32_t green;
                        int32_t blue;
                        sscanf(text.c_str(), "#%02x%02x%02x", &red, &green, &blue);
                        color = MakeFillColor(red, green, blue);
                        text = text.Mid(7, 0xffffffff);
                    } else {
                        reinterpret_cast<StringOps_ae1780*>(static_cast<std::string*>(&text))->erase(0, 0xffffffff);
                    }
                }
            } else {
                uint32_t candidate = mnColors[1];
                hasColor = candidate != 0xdeadbeef;
                if (hasColor) {
                    color = candidate;
                }
                if (text.BeginsWith("#", 1)) {
                    if (text.BeginsWith("##", 2)) {
                        text = text.Mid(1, 0xffffffff);
                    } else if (text.size() >= 7) {
                        text = text.Mid(7, 0xffffffff);
                    } else {
                        reinterpret_cast<StringOps_ae1780*>(static_cast<std::string*>(&text))->erase(0, 0xffffffff);
                    }
                }
            }
            if (line.v[3] > area.v[3]) {
                line.v[3] = area.v[3];
            }
            uint32_t length = text.size();
            if (length != 0) {
                Rect_ae1780 where = line;
                uint32_t fit = static_cast<cFont_ae1780*>(mpFont)->MeasureText(text.c_str(), length, width, 0);
                static_cast<cFont_ae1780*>(mpFont)->DrawText(field68, where.v[0], line.v[1], text.c_str(), fit, hasColor ? color : 0, 0x8000000, 0, 0);
            }
            line.v[1] += mnLineHeight;
            line.v[3] += mnLineHeight;
            node = node->mpNext;
            ++index;
            ++lineNumber;
        }
        if (mbDrawSunkenRect) {
            RZDraw3DRectangleOutline_ae1780(OB_PTR(cDrawContext_ae1780, field6c), &area, mnOutlineColorA, mnOutlineColorB);
        } else if (mbOutlineDrawing) {
            RZDrawRectangleOutline_ae1780(OB_PTR(cDrawContext_ae1780, field6c), &area, mnOutlineColorA, 1);
        }
    }
    return true;
}
#endif
