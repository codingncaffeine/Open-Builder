#include <cmath>
#include <new>
#include <vector>

#include "classes/cGZWinTreeView.h"
#include "gzcom/cIGZUnknown.h"
#include "gzcom/cRZString.h"

// The allocator the original's lists are built with (an empty record passed by reference).
struct Alloc_ae3240 {
};

// A std::list<TreeNode*> as the original lays it out: one pointer to the sentinel.
struct TreeNode_ae3240;

struct NodeList_ae3240 {
    void* mpHead;
    // STUB: 0x0093f7eb
    NodeList_ae3240* Fn0093f7eb(const Alloc_ae3240& alloc);
    // STUB: 0x0096edbc
    void Fn0096edbc();
};

// The text of a node: its destructor, called out of line.
struct NodeText_ae3240 {
    // STUB: 0x00414250
    void Fn00414250();
};

// A font, seen through the one slot this class calls (the height of a text).
struct Font_ae3240 {
    virtual void P00(); virtual void P01(); virtual void P02(); virtual void P03();
    virtual void P04(); virtual void P05(); virtual void P06(); virtual void P07();
    virtual void P08(); virtual void P09(); virtual void P10(); virtual void P11();
    virtual void P12(); virtual void P13(); virtual void P14(); virtual void P15();
    virtual void P16(); virtual void P17(); virtual void P18(); virtual void P19();
    virtual void P20(); virtual void P21(); virtual void P22(); virtual void P23();
    virtual void P24(); virtual void P25(); virtual void P26(); virtual void P27();
    virtual void P28(); virtual void P29(); virtual void P30(); virtual void P31();
    virtual void P32(); virtual void P33(); virtual void P34(); virtual void P35();
    virtual void P36();
    virtual uint32_t GetTextHeight(uint32_t a, uint32_t b);
    virtual void P38(); virtual void P39(); virtual void P40(); virtual void P41();
    virtual void P42(); virtual void P43(); virtual void P44(); virtual void P45();
    virtual void P46(); virtual void P47();
    virtual uint32_t GetTextWidth(const char* text, uint32_t length);
    virtual void P49(); virtual void P50();
    virtual void DrawText(void* surface, int32_t x, int32_t y, const char* text, uint32_t length, uint32_t color, uint32_t shadow, uint32_t a, uint32_t b);
};

// One node of the tree (0x8c bytes).
struct TreeNode_ae3240 {
    int32_t mnHandle;       // 0x00
    int32_t mnInsertAfter;  // 0x04
    cRZString mName;        // 0x08
    uint32_t mnUserData;    // 0x1c
    Font_ae3240* mpFont;    // 0x20
    uint32_t mn24;          // 0x24
    uint32_t mn28;          // 0x28
    uint32_t mn2C;          // 0x2c
    uint32_t mn30;          // 0x30
    uint32_t mn34;          // 0x34
    uint32_t mn38;          // 0x38
    uint32_t mn3C;          // 0x3c
    uint32_t mn40;          // 0x40
    bool mbExpanded;        // 0x44
    bool mb45;              // 0x45
    bool mbSelected;        // 0x46
    bool mb47;              // 0x47
    bool mb48;              // 0x48
    bool mb49;              // 0x49
    bool mb4A;              // 0x4a
    bool mbRemove;          // 0x4b
    uint32_t mn4C;          // 0x4c
    uint32_t mn50;          // 0x50
    uint32_t mn54;          // 0x54
    uint32_t mn58;          // 0x58
    uint32_t mn5C;          // 0x5c
    uint32_t mn60;          // 0x60
    uint32_t mn64;          // 0x64
    uint32_t mn68;          // 0x68
    uint32_t mn6C;          // 0x6c
    uint32_t mn70;          // 0x70
    uint32_t mn74;          // 0x74
    uint32_t mn78;          // 0x78
    uint32_t mn7C;          // 0x7c
    TreeNode_ae3240* mpParent;  // 0x80
    NodeList_ae3240 mChildren;  // 0x84
    uint32_t mnChildCount;  // 0x88

    // The constructor's work, run on raw memory (the original's code until the draft below matches).
    // STUB: 0x009d2b42
    TreeNode_ae3240* Fn009d2b42();
#ifdef OB_DRAFTS
    TreeNode_ae3240* Fn009d2b42Draft_ae3240();
#endif
    // The destructor, spelled out: the list's and the text's destructors are called out of line.
    void Fn009d2bd9();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009d2b42 score 8 (the compiler spreads the list constructor's argument setup over the stores differently)
TreeNode_ae3240* TreeNode_ae3240::Fn009d2b42Draft_ae3240()
{
    mnHandle = 0;
    mnInsertAfter = -3;
    new (&mName) cRZString();
    mnUserData = 0;
    mpFont = 0;
    mn24 = 0;
    mn28 = 0;
    mn2C = 0;
    mn30 = 0;
    mn34 = 0;
    mn38 = 0;
    mn3C = 0;
    mn40 = 0;
    mbExpanded = false;
    mb45 = false;
    mbSelected = false;
    mb47 = false;
    mb48 = false;
    mb49 = false;
    mb4A = false;
    mbRemove = false;
    mn4C = 0;
    mn50 = 0;
    mn54 = 0;
    mn58 = 0;
    mn5C = 0;
    mn60 = 0;
    mn64 = 0;
    mn68 = 0;
    mn6C = 0;
    mn70 = 0;
    mn74 = 0;
    mn78 = 0;
    mn7C = 0;
    mpParent = 0;
    Alloc_ae3240 alloc;
    mChildren.Fn0093f7eb(alloc);
    mnChildCount = 0;
    return this;
}
#endif

// FUNCTION: 0x009d2bd9
void TreeNode_ae3240::Fn009d2bd9()
{
    mChildren.Fn0096edbc();
    reinterpret_cast<NodeText_ae3240*>(&mName)->Fn00414250();
}

// The call Release makes: the shared "delete this" of the window classes.
struct Destroy_ae3240 {
    // STUB: 0x009cfa1d
    void Fn009cfa1d();
};

// The tree's selection (the original's std::vector of node pointers, at +0x104).
inline std::vector<TreeNode_ae3240*>& Selection_ae3240(cGZWinTreeView* view)
{
    return *reinterpret_cast<std::vector<TreeNode_ae3240*>*>(view->mSelection);
}

// The allocator service the lists draw their nodes from (slot 3 allocates, slot 4 frees).
struct Allocator_ae3240 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void* Allocate(uint32_t size);
    virtual void Free(void* block);
};

// STUB: 0x009d0747
Allocator_ae3240* Fn009d0747();

// One link of a std::list<long> (the value follows the two pointers).
struct LongLink_ae3240 {
    LongLink_ae3240* mpNext;
    LongLink_ae3240* mpPrev;
    int32_t mnValue;
};

// An object's list of long values (a std::list<long>), as a record the tree-view information holds.
// An iterator of that list (passed by value).
struct LongIter_ae3240 {
    LongLink_ae3240* mpNode;
    LongIter_ae3240 operator++(int)
    {
        LongIter_ae3240 before = *this;
        mpNode = mpNode->mpNext;
        return before;
    }
};

// STUB: 0x009d1f8b
LongLink_ae3240* OB_STDCALL Fn009d1f8b(const int32_t& value);

struct LongList_ae3240 {
    LongLink_ae3240* mpHead;
    // STUB: 0x009d1f4c
    void Fn009d1f4c();
    // The constructor: one sentinel link.
    LongList_ae3240* Fn009d1f2b(const Alloc_ae3240& alloc);
    // Unlinks and frees one link.
    void Fn009d1f03(LongIter_ae3240* result, LongIter_ae3240 position);
    // Links a new value in front of a position.
    LongIter_ae3240* Fn009d2950(LongIter_ae3240* result, LongIter_ae3240 position, const int32_t& value);
    // The erase of a range (the original's code until the draft matches).
    // STUB: 0x009d291c
    void Fn009d291c(LongIter_ae3240* result, LongIter_ae3240 first, LongIter_ae3240 last);
    // STUB: 0x009d31a2
    void Fn009d31a2(const int32_t& value);
    LongIter_ae3240 Begin() const
    {
        LongIter_ae3240 begin;
        begin.mpNode = mpHead->mpNext;
        return begin;
    }
    LongIter_ae3240 End() const
    {
        LongIter_ae3240 end;
        end.mpNode = mpHead;
        return end;
    }
};

// The information record the tree hands out about one node (0x34 bytes).
struct NodeInfo_ae3240 {
    cIGZString* mpText;         // 0x00
    uint32_t mnUserData;        // 0x04
    int32_t mnImage[4];         // 0x08
    Font_ae3240* mpFont;        // 0x18
    uint32_t mnColor0;          // 0x1c
    uint32_t mnColor2;          // 0x20
    uint32_t mnColor1;          // 0x24
    uint32_t mnColor3;          // 0x28
    bool mb2C;                  // 0x2c
    bool mb2D;                  // 0x2d
    bool mb2E;                  // 0x2e
    bool mb2F;                  // 0x2f
    LongList_ae3240 mHandles;   // 0x30

    // The constructor's work, run on a record in memory.
    NodeInfo_ae3240* Fn009d3123();
    void Fn009d318c();
};

// FUNCTION: 0x009d318c
void NodeInfo_ae3240::Fn009d318c()
{
    mpText->Release();
    mpText = 0;
    mHandles.Fn009d1f4c();
}

// FUNCTION: 0x009d1f2b
LongList_ae3240* LongList_ae3240::Fn009d1f2b(const Alloc_ae3240& /*alloc*/)
{
    mpHead = 0;
    LongLink_ae3240* sentinel = static_cast<LongLink_ae3240*>(Fn009d0747()->Allocate(12));
    sentinel->mpNext = sentinel;
    sentinel->mpPrev = sentinel;
    mpHead = sentinel;
    return this;
}

// FUNCTION: 0x009d3123
NodeInfo_ae3240* NodeInfo_ae3240::Fn009d3123()
{
    mnImage[0] = -1;
    mnImage[1] = -1;
    mnImage[2] = -1;
    mnImage[3] = -1;
    mnColor2 = 0xffffffff;
    mnColor1 = 0xffffffff;
    mnUserData = 0;
    mpFont = 0;
    mnColor0 = 0;
    mnColor3 = 0;
    mb2C = true;
    mb2D = false;
    mb2E = true;
    mb2F = false;
    Alloc_ae3240 alloc;
    mHandles.Fn009d1f2b(alloc);
    cRZString* text = new cRZString;
    mpText = text;
    text->AddRef();
    return this;
}

// A std::map<long, TreeNode*> node and the map, as the original lays them out.
struct MapNode_ae3240 {
    uint32_t mnColor;
    MapNode_ae3240* mpParent;
    MapNode_ae3240* mpLeft;
    MapNode_ae3240* mpRight;
    int32_t mnKey;
    TreeNode_ae3240* mpValue;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* block);   // the container library's delete

struct MapIter_ae3240 {
    MapNode_ae3240* mpNode;
};

struct NodeMap_ae3240 {
    MapNode_ae3240* mpHeader;
    uint32_t mnCount;
    // STUB: 0x00927cf8
    void Fn00927cf8(MapIter_ae3240 position);
    // STUB: 0x0094c8f5
    MapNode_ae3240* Find(const int32_t& key);
    // Frees a subtree.
    void Fn009d0773(MapNode_ae3240* node);
    // Frees every node.
    void Fn009d16b0();
};

// FUNCTION: 0x009d0773
void NodeMap_ae3240::Fn009d0773(MapNode_ae3240* node)
{
    while (node != 0) {
        Fn009d0773(node->mpRight);
        MapNode_ae3240* left = node->mpLeft;
        Fn0090cf63(node);
        node = left;
    }
}

// FUNCTION: 0x009d16b0
void NodeMap_ae3240::Fn009d16b0()
{
    if (mnCount != 0) {
        Fn009d0773(mpHeader->mpParent);
        mpHeader->mpLeft = mpHeader;
        mpHeader->mpParent = 0;
        mpHeader->mpRight = mpHeader;
        mnCount = 0;
    }
}

// FUNCTION: 0x009d1ee1
void* cGZWinTreeView::GetNodeByHandle(int32_t handle)
{
    NodeMap_ae3240* map = reinterpret_cast<NodeMap_ae3240*>(mNodeMap);
    MapNode_ae3240* found = map->Find(handle);
    if (found != map->mpHeader) {
        return found->mpValue;
    }
    return 0;
}

// FUNCTION: 0x009cfc13
void cGZWinTreeView::Slot28_ae2ef0()
{
    Slot27_ae2ef0(0);
}

// FUNCTION: 0x009d00b3
uint32_t cGZWinTreeView::Slot53_ae2ef0()
{
    return Selection_ae3240(this).size();
}

// FUNCTION: 0x009cfaa6
uint32_t cGZWinTreeView::Slot04_ae2ef0(uint32_t mask)
{
    return (mnTreeFlags & mask) != 0;
}

// FUNCTION: 0x009cfbf8
void cGZWinTreeView::Slot16_ae2ef0()
{
    ConvertPackedRGBToNative(mnBackgroundColor);
}

// FUNCTION: 0x009d006c
unsigned int cGZWinTreeView::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    reinterpret_cast<Destroy_ae3240*>(this)->Fn009cfa1d();
    return 0;
}

// FUNCTION: 0x009cfb32
void cGZWinTreeView::Slot09_ae2ef0(uint32_t a, uint32_t b)
{
    mnSpacingX = a;
    mnSpacingY = b;
}

// FUNCTION: 0x009cfc50
uint32_t cGZWinTreeView::Slot40_ae2ef0(uint32_t index)
{
    if (static_cast<int32_t>(index) < 4) {
        return mnColors[index];
    }
    return 0;
}

// FUNCTION: 0x009cfc67
void cGZWinTreeView::Slot41_ae2ef0(uint32_t index, uint32_t color)
{
    if (static_cast<int32_t>(index) < 4) {
        mnColors[index] = color;
    }
}

// FUNCTION: 0x009d21f2
uint32_t cGZWinTreeView::Slot33_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        return node->mnUserData;
    }
    return 0;
}

// FUNCTION: 0x009d22bd
uint32_t cGZWinTreeView::Slot38_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        return OB_ADDR(node->mpFont);
    }
    return 0;
}

// FUNCTION: 0x009d23d9
bool cGZWinTreeView::Slot44_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        return node->mbExpanded;
    }
    return false;
}

// FUNCTION: 0x009d24c4
bool cGZWinTreeView::Slot50_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        return node->mbSelected;
    }
    return false;
}

// FUNCTION: 0x009d246b
uint32_t cGZWinTreeView::Slot48_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        return node->mnChildCount;
    }
    return 0;
}

// FUNCTION: 0x009d24fc
uint32_t cGZWinTreeView::Slot52_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        return node->mnInsertAfter;
    }
    return 0xffffffff;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d00fa score 5
uint32_t cGZWinTreeView::Slot54_ae2ef0()
{
    std::vector<TreeNode_ae3240*>& selection = Selection_ae3240(this);
    if (!selection.empty()) {
        return selection.front()->mnHandle;
    }
    return 0xffffffff;
}
#endif

// FUNCTION: 0x009cfaf2
void cGZWinTreeView::Slot06_ae2ef0(uint32_t pX, uint32_t pY)
{
    *OB_PTR(uint32_t, pX) = mnGutterX;
    *OB_PTR(uint32_t, pY) = mnGutterY;
}

// FUNCTION: 0x009cfb49
void cGZWinTreeView::Slot10_ae2ef0(uint32_t pX, uint32_t pY)
{
    *OB_PTR(uint32_t, pX) = mnSpacingX;
    *OB_PTR(uint32_t, pY) = mnSpacingY;
}

// A scrollbar child, seen through the slots this class calls.
struct Scrollbar_ae3240 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void SetPosition(uint32_t position);
    virtual uint32_t GetPosition();
    virtual void SetRange(uint32_t low, uint32_t high);
    virtual void GetRange(uint32_t* low, uint32_t* high);
    virtual void P09(); virtual void P10(); virtual void P11(); virtual void P12();
    virtual void P13(); virtual void P14();
    virtual void SetPage(uint32_t a, uint32_t b);
};

// One link of a node's std::list<TreeNode*>.
struct ListLink_ae3240 {
    ListLink_ae3240* mpNext;
    ListLink_ae3240* mpPrev;
    TreeNode_ae3240* mpNode;
};

// FUNCTION: 0x009cfa42
bool cGZWinTreeView::QueryInterface(unsigned int iid, void** ppv)
{
    if (iid != 0x3ae8bad2) {
        return cGZWin::QueryInterface(iid, ppv);
    }
    *ppv = this;
    AddRef();
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009cfa64 score 29
void cGZWinTreeView::Slot03_ae2ef0(uint32_t mask, uint32_t on)
{
    uint32_t* pFlags = &mnTreeFlags;
    uint32_t flags;
    if (static_cast<uint8_t>(on) != 0) {
        flags = *pFlags;
        if (mask & flags) {
            return;
        }
        flags |= mask;
    } else {
        flags = *pFlags;
        if (!(mask & flags)) {
            return;
        }
        flags &= ~mask;
    }
    mbDirty = true;
    *pFlags = flags;
    InvalidateSelfAndParents();
}
#endif

// FUNCTION: 0x009cfab9
void cGZWinTreeView::Slot05_ae2ef0(uint32_t x, uint32_t y)
{
    if (mnGutterX != x || mnGutterY != y) {
        mnGutterY = y;
        mbDirty = true;
        mnGutterX = x;
        InvalidateSelfAndParents();
    }
}

// FUNCTION: 0x009cfb0d
void cGZWinTreeView::Slot07_ae2ef0(uint32_t gutter)
{
    if (mnIconGutter != gutter) {
        mbDirty = true;
        mnIconGutter = gutter;
        InvalidateSelfAndParents();
    }
}

// FUNCTION: 0x009cfb64
void cGZWinTreeView::Slot11_ae2ef0(uint32_t height)
{
    if (mnRowHeight != height) {
        mbDirty = true;
        mnRowHeight = height;
        InvalidateSelfAndParents();
    }
}

// FUNCTION: 0x009cfb89
void cGZWinTreeView::Slot13_ae2ef0(uint32_t size)
{
    uint32_t limit = mnMaxBoxSize;
    if (size > limit) {
        size = limit;
    }
    if (mnBoxSize != size) {
        mbDirty = true;
        mnBoxSize = size;
        InvalidateSelfAndParents();
    }
}

// FUNCTION: 0x009cfbc1
void cGZWinTreeView::Slot15_ae2ef0(uint32_t color)
{
    uint32_t packed = ConvertNativeToPackedRGB(color);
    if (mnBackgroundColor != packed) {
        mnBackgroundColor = packed;
        mbDirty = true;
        InvalidateSelfAndParents();
    }
}

// FUNCTION: 0x009cfc1b
void cGZWinTreeView::Slot37_ae2ef0(uint32_t font)
{
    cIGZUnknown* newFont = OB_PTR(cIGZUnknown, font);
    if (mpDefaultFont != newFont) {
        if (newFont) {
            newFont->AddRef();
        }
        cIGZUnknown* oldFont = static_cast<cIGZUnknown*>(mpDefaultFont);
        if (oldFont) {
            oldFont->Release();
        }
        mpDefaultFont = newFont;
    }
}

// FUNCTION: 0x009d0081
void cGZWinTreeView::Slot17_ae2ef0(uint32_t color)
{
    if (mnColors[3] != color) {
        mnColors[3] = color;
        if (!Selection_ae3240(this).empty()) {
            mbDirty = true;
            InvalidateSelfAndParents();
        }
    }
}

// FUNCTION: 0x009d00c5
bool cGZWinTreeView::Slot55_ae2ef0(uint32_t out)
{
    std::vector<TreeNode_ae3240*>& selection = Selection_ae3240(this);
    int32_t count = selection.size();
    for (int32_t i = 0; i < count; i++) {
        OB_PTR(int32_t, out)[i] = selection[i]->mnHandle;
    }
    return true;
}

// FUNCTION: 0x009cfce8
void cGZWinTreeView::Slot07_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    cGZWin::Slot07_add348(a, b, c, d);
    mbDirty = true;
}

// FUNCTION: 0x009cff09
bool cGZWinTreeView::GZOnMouseWheel(uint32_t /*a*/, uint32_t /*b*/, uint32_t /*c*/, uint32_t delta)
{
    if (mpScrollbarV) {
        uint32_t row = mnFirstRow;
        if (static_cast<int32_t>(delta) < 0) {
            if (mnVisibleRows2 + row >= mnRowCount) {
                return true;
            }
            row++;
        } else {
            if (row <= 0) {
                return true;
            }
            row--;
        }
        static_cast<Scrollbar_ae3240*>(mpScrollbarV)->SetPosition(row);
    }
    return true;
}

// FUNCTION: 0x009d219b
uint32_t cGZWinTreeView::Slot31_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        return OB_ADDR(&node->mName);
    }
    return OB_ADDR(&mDefaultText);
}

// FUNCTION: 0x009d2209
bool cGZWinTreeView::Slot34_ae2ef0(uint32_t handle, uint32_t data)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        node->mnUserData = data;
        return true;
    }
    return false;
}

// FUNCTION: 0x009d21ba
bool cGZWinTreeView::Slot32_ae2ef0(uint32_t handle, uint32_t text)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        cIGZString* name = &node->mName;
        *name = *OB_PTR(cIGZString, text);
        mbDirty = true;
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}

// FUNCTION: 0x009d2226
uint32_t cGZWinTreeView::Slot35_ae2ef0(uint32_t handle, uint32_t which)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        switch (which) {
        case 0:
            return node->mn34;
        case 1:
            return node->mn38;
        case 2:
            return node->mn3C;
        case 3:
            return node->mn40;
        }
    }
    return 0xffffffff;
}

// FUNCTION: 0x009d2343
uint32_t cGZWinTreeView::Slot42_ae2ef0(uint32_t handle, uint32_t which)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        switch (which) {
        case 0:
            return node->mn24;
        case 1:
            return node->mn2C;
        case 2:
            return node->mn28;
        case 3:
            return node->mn30;
        }
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d2485 score 2
bool cGZWinTreeView::Slot49_ae2ef0(uint32_t handle, uint32_t out)
{
    if (out != 0) {
        TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
        if (node) {
            ListLink_ae3240* head = static_cast<ListLink_ae3240*>(node->mChildren.mpHead);
            int32_t* p = OB_PTR(int32_t, out);
            for (ListLink_ae3240* link = head->mpNext; link != head; link = link->mpNext) {
                *p = link->mpNode->mnHandle;
                p++;
            }
            return true;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x009d24db
uint32_t cGZWinTreeView::Slot51_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        TreeNode_ae3240* parent = node->mpParent;
        if (parent) {
            return parent->mnHandle;
        }
    }
    return 0xffffffff;
}

// FUNCTION: 0x009d3f56
bool cGZWinTreeView::Slot03_ae1d24()
{
    cGZWin::Slot03_ae1d24();
    if (!mbInitialized) {
        InternalInit();
    }
    RecalculateAll();
    return true;
}

// A 16-byte rectangle (left, top, right, bottom).
struct Rect_ae3240 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
    // STUB: 0x0043fde0
    bool Fn0043fde0(int32_t x, int32_t y);
    // STUB: 0x007c1870
    bool Fn007c1870();
};

// The tree's list of visible nodes (a std::vector<TreeNode*>) and its erase.
struct NodeVec_ae3240 {
    TreeNode_ae3240** mpStart;
    TreeNode_ae3240** mpFinish;
    TreeNode_ae3240** mpEnd;
    // STUB: 0x009a1add
    void Fn009a1add(TreeNode_ae3240** first, TreeNode_ae3240** last);
    // STUB: 0x008d3333
    TreeNode_ae3240** Fn008d3333(TreeNode_ae3240** position);
    // STUB: 0x008ff785
    void Fn008ff785(TreeNode_ae3240* const& value);
};

// FUNCTION: 0x009d0626
void* cGZWinTreeView::GetNodeAtCursorPosition(int32_t x, int32_t y)
{
    int32_t cy = y - mnGutterY;
    int32_t cx = x - mnGutterX;
    if (reinterpret_cast<Rect_ae3240*>(mnViewRect)->Fn0043fde0(cx, cy)) {
        uint32_t row = static_cast<uint32_t>(cy) / mnRowHeight;
        uint32_t first = mnFirstRow;
        if (row <= mnLastRow - first) {
            return reinterpret_cast<NodeVec_ae3240*>(mVisibleNodes)->mpStart[first + row];
        }
    }
    return 0;
}

// FUNCTION: 0x009d0f85
void cGZWinTreeView::Fn009d0f85(void* node, uint32_t keep, uint32_t flag)
{
    TreeNode_ae3240* n = static_cast<TreeNode_ae3240*>(node);
    if (n) {
        if (!*reinterpret_cast<bool*>(&keep) && !*reinterpret_cast<bool*>(&flag)) {
            n->mbSelected = false;
        }
        ListLink_ae3240* head = static_cast<ListLink_ae3240*>(n->mChildren.mpHead);
        ListLink_ae3240* link = head->mpNext;
        if (link != head) {
            do {
                Fn009d0f85(link->mpNode, keep, 0);
                link = link->mpNext;
            } while (link != static_cast<ListLink_ae3240*>(n->mChildren.mpHead));
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d0fd1 score 22 (the original reads the vector's end through its own address register)
void cGZWinTreeView::Fn009d0fd1()
{
    std::vector<TreeNode_ae3240*>& sel = Selection_ae3240(this);
    std::vector<TreeNode_ae3240*>::iterator it = sel.begin();
    bool removed = false;
    while (it != sel.end()) {
        if (!(*it)->mbSelected) {
            it = reinterpret_cast<NodeVec_ae3240*>(&sel)->Fn008d3333(it);
            removed = true;
        } else {
            ++it;
        }
    }
    if (removed) {
        SendMsg(field4c, 0x1af5a13a, Slot48_adda20(), 0, 0);
    }
}
#endif

// FUNCTION: 0x009d22d4
bool cGZWinTreeView::Slot39_ae2ef0(uint32_t handle, uint32_t font)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        Font_ae3240* f = OB_PTR(Font_ae3240, font);
        if (!f) {
            f = static_cast<Font_ae3240*>(mpDefaultFont);
        }
        if (node->mpFont != f) {
            node->mpFont = f;
            if (mnRowHeight < f->GetTextHeight(0, 0)) {
                mnRowHeight = node->mpFont->GetTextHeight(0, 0);
            }
            mbDirty = true;
            InvalidateSelfAndParents();
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x009d225f
bool cGZWinTreeView::Slot36_ae2ef0(uint32_t handle, uint32_t which, uint32_t value)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        switch (which) {
        case 0:
            node->mn34 = value;
            break;
        case 1:
            node->mn38 = value;
            break;
        case 2:
            node->mn3C = value;
            break;
        case 3:
            node->mn40 = value;
            break;
        default:
            return false;
        }
        mbDirty = true;
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}

// FUNCTION: 0x009d237b
bool cGZWinTreeView::Slot43_ae2ef0(uint32_t handle, uint32_t which, uint32_t value)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        switch (which) {
        case 0:
            node->mn24 = value;
            break;
        case 1:
            node->mn2C = value;
            break;
        case 2:
            node->mn28 = value;
            break;
        case 3:
            node->mn30 = value;
            break;
        default:
            return false;
        }
        mbDirty = true;
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d23f0 score 4 (the saved vtable pointer goes into another dead argument slot)
bool cGZWinTreeView::Slot45_ae2ef0(uint32_t handle, uint32_t expanded)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        bool e = *reinterpret_cast<bool*>(&expanded);
        if (node->mbExpanded != e) {
            node->mbExpanded = e;
            mbDirty = true;
            InvalidateSelfAndParents();
            if (node->mbExpanded) {
                SendMsg(field4c, 0x1af5a13c, Slot48_adda20(), node->mnHandle, 0);
            } else {
                SendMsg(field4c, 0x1af5a13d, Slot48_adda20(), node->mnHandle, 0);
            }
        }
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x009d3e03
bool cGZWinTreeView::Slot46_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        if (mbDirty) {
            RecalculateAll();
        }
        if (node->mb47) {
            uint32_t row = node->mn7C;
            uint32_t first = mnFirstRow;
            if (row >= first && row < mnVisibleRows2 + first) {
                return true;
            }
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d2514 score 36 (the original's loop tests before the first pass and compares against the end field's address)
bool cGZWinTreeView::Slot58_ae2ef0()
{
    NodeVec_ae3240* selection = reinterpret_cast<NodeVec_ae3240*>(mSelection);
    if (selection->mpStart != selection->mpFinish) {
        TreeNode_ae3240** it = selection->mpStart;
        while (it != selection->mpFinish) {
            TreeNode_ae3240* n = *it;
            ++it;
            n->mbSelected = false;
        }
        selection->Fn009a1add(selection->mpStart, selection->mpFinish);
        InvalidateSelfAndParents();
        SendMsg(field4c, 0x1af5a13a, Slot48_adda20(), 0, 0);
    }
    return true;
}
#endif

// The record InsertNode hands the tree (parent, the node to insert after, then the node's information).
struct InsertInfo_ae3240 {
    int32_t mnParent;
    int32_t mnInsertAfter;
    NodeInfo_ae3240 mNode;
};

// FUNCTION: 0x009d3cba
uint32_t cGZWinTreeView::Slot24_ae2ef0(uint32_t parent, uint32_t after, uint32_t text, uint32_t userData)
{
    if (!mbInitialized) {
        InternalInit();
    }
    InsertInfo_ae3240 info;
    info.mNode.Fn009d3123();
    info.mnParent = parent;
    info.mnInsertAfter = after;
    info.mNode.mpText->Copy(*OB_PTR(cIGZString, text));
    info.mNode.mnImage[0] = 0;
    info.mNode.mnUserData = userData;
    info.mNode.mpFont = static_cast<Font_ae3240*>(mpDefaultFont);
    info.mNode.mnColor0 = mnColors[0];
    info.mNode.mnColor2 = mnColors[2];
    info.mNode.mnColor1 = mnColors[1];
    info.mNode.mnColor3 = mnColors[3];
    info.mNode.mb2C = false;
    info.mNode.mb2D = false;
    info.mNode.mnImage[2] = 2;
    info.mNode.mnImage[3] = 3;
    info.mNode.mnImage[1] = 1;
    uint32_t handle = Slot25_ae2ef0(OB_ADDR(&info));
    info.mNode.Fn009d318c();
    return handle;
}

// FUNCTION: 0x009d3d60
uint32_t cGZWinTreeView::Slot23_ae2ef0(uint32_t parent, uint32_t after, uint32_t text, uint32_t image0, uint32_t image1, uint32_t image2, uint32_t image3)
{
    if (!mbInitialized) {
        InternalInit();
    }
    InsertInfo_ae3240 info;
    info.mNode.Fn009d3123();
    info.mnParent = parent;
    info.mnInsertAfter = after;
    info.mNode.mpText->Copy(*OB_PTR(cIGZString, text));
    info.mNode.mnImage[2] = image2;
    info.mNode.mnImage[3] = image3;
    info.mNode.mnUserData = 0;
    info.mNode.mnImage[0] = image0;
    info.mNode.mnImage[1] = image1;
    info.mNode.mpFont = static_cast<Font_ae3240*>(mpDefaultFont);
    info.mNode.mnColor0 = mnColors[0];
    info.mNode.mnColor2 = mnColors[2];
    info.mNode.mnColor1 = mnColors[1];
    info.mNode.mnColor3 = mnColors[3];
    info.mNode.mb2C = false;
    info.mNode.mb2D = false;
    uint32_t handle = Slot25_ae2ef0(OB_ADDR(&info));
    info.mNode.Fn009d318c();
    return handle;
}

// A bitmap of the tree's icon list (its image object and its rectangle): 0x14 bytes.
struct IconImage_ae3240 {
    cIGZUnknown* mpImage;
    Rect_ae3240 mRect;
};

struct Tag_ae3240 {
    Tag_ae3240() {}
};

// STUB: 0x009d0008
IconImage_ae3240* Fn009d0008(IconImage_ae3240* a, IconImage_ae3240* b, IconImage_ae3240* c, const char& tag, int32_t flag);

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"  // the original hands an untouched stack byte down by reference
#endif
// FUNCTION: 0x009d07ca
IconImage_ae3240* Fn009d07ca(IconImage_ae3240* a, IconImage_ae3240* b, IconImage_ae3240* c, const Tag_ae3240& /*tag*/)
{
    char unused[1];  // the original hands an untouched stack byte down by reference
    return Fn009d0008(a, b, c, unused[0], 0);
}
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

// STUB: 0x009cff64
void Fn009cff64(IconImage_ae3240* place, const IconImage_ae3240& value);

// The tree's icon list, a std::vector<IconImage>.
struct IconVec_ae3240 {
    IconImage_ae3240* mpStart;
    IconImage_ae3240* mpFinish;
    IconImage_ae3240* mpEnd;
    uint32_t size() const
    {
        return mpFinish - mpStart;
    }
    // The erase of a range.
    IconImage_ae3240* Fn009d1f65(IconImage_ae3240* first, IconImage_ae3240* last);
    // STUB: 0x009d2a50
    void Fn009d2a50(IconImage_ae3240* position, uint32_t count, const IconImage_ae3240& value);
    // STUB: 0x009d2992
    void Fn009d2992(IconImage_ae3240* position, const IconImage_ae3240& value, const Tag_ae3240& tag, uint32_t count, bool atEnd);
    void Fn009d390d(uint32_t newSize, const IconImage_ae3240& value);
    void Fn009d3f21(uint32_t newSize);
    void Fn009d31bc(const IconImage_ae3240& value);
};

// FUNCTION: 0x009d1f65
IconImage_ae3240* IconVec_ae3240::Fn009d1f65(IconImage_ae3240* first, IconImage_ae3240* last)
{
    mpFinish = Fn009d07ca(last, mpFinish, first, Tag_ae3240());
    return first;
}

// FUNCTION: 0x009d390d
void IconVec_ae3240::Fn009d390d(uint32_t newSize, const IconImage_ae3240& value)
{
    if (newSize < size()) {
        Fn009d1f65(mpStart + newSize, mpFinish);
    } else {
        Fn009d2a50(mpFinish, newSize - size(), value);
    }
}

// FUNCTION: 0x009d3f21
void IconVec_ae3240::Fn009d3f21(uint32_t newSize)
{
    Rect_ae3240 rect;
    rect.mnLeft = 0;
    rect.mnTop = 0;
    rect.mnRight = 0;
    rect.mnBottom = 0;
    IconImage_ae3240 blank;
    blank.mpImage = 0;
    blank.mRect = rect;
    Fn009d390d(newSize, blank);
}

// FUNCTION: 0x009d31bc
void IconVec_ae3240::Fn009d31bc(const IconImage_ae3240& value)
{
    if (mpFinish != mpEnd) {
        Fn009cff64(mpFinish, value);
        mpFinish++;
    } else {
        Fn009d2992(mpFinish, value, Tag_ae3240(), 1, true);
    }
}

// FUNCTION: 0x009d407e
void cGZWinTreeView::Slot22_ae2ef0()
{
    IconVec_ae3240* icons = reinterpret_cast<IconVec_ae3240*>(mIconImages);
    uint32_t count = icons->size();
    if (count > 4) {
        for (uint32_t i = 4; i != count; i++) {
            cIGZUnknown* image = icons->mpStart[i].mpImage;
            if (image) {
                image->Release();
            }
        }
        icons->Fn009d3f21(4);
    }
}

// STUB: 0x004b5ca0
bool Fn004b5ca0(const std::string* x, const std::string* y);   // the library's string comparison

// FUNCTION: 0x009d1708
bool Fn009d1708(const cRZString* a, const cRZString* b)
{
    return !Fn004b5ca0(b, a);
}

// The list of a node's children: the erase of one link (the original's std::list code).
struct NodeIter_ae3240 {
    ListLink_ae3240* mpNode;
};

struct ChildList_ae3240 {
    ListLink_ae3240* mpHead;
    // STUB: 0x00949259
    NodeIter_ae3240* Fn00949259(NodeIter_ae3240* result, NodeIter_ae3240 position);
    // STUB: 0x009d74d9
    void Fn009d74d9(TreeNode_ae3240* const& value);   // push_front
    // STUB: 0x008f6e80
    void Fn008f6e80(TreeNode_ae3240* const& value);   // push_back
    // STUB: 0x00897c8d
    NodeIter_ae3240* Fn00897c8d(NodeIter_ae3240* result, NodeIter_ae3240 position, TreeNode_ae3240* const& value);   // insert
    // The splice of one link from another list (the original's std::list code).
    // STUB: 0x0099cc80
    void Fn0099cc80(NodeIter_ae3240 position, ChildList_ae3240& other, NodeIter_ae3240 link);
};

// The tree's map from handle to node: the lookup that makes a slot (the original's std::map code).
struct NodeMapIndex_ae3240 {
    // STUB: 0x009389aa
    TreeNode_ae3240** Fn009389aa(const int32_t& key);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009d1735 score 46 (register allocation: the original keeps the node in edi, the child list in ebx, the link in esi)
void cGZWinTreeView::FlagNodeForRemovalRecursively(void* nodeArg)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(nodeArg);
    ChildList_ae3240* children;
    ListLink_ae3240* link;
    if (node) {
        if (node->mnChildCount != 0) {
            children = reinterpret_cast<ChildList_ae3240*>(&node->mChildren);
            link = children->mpHead->mpNext;
            while (link != children->mpHead) {
                FlagNodeForRemovalRecursively(link->mpNode);
                NodeIter_ae3240 next;
                NodeIter_ae3240 at;
                at.mpNode = link;
                children->Fn00949259(&next, at);
                link = next.mpNode;
                node->mnChildCount--;
            }
        }
        if (node->mbSelected) {
            Slot57_ae2ef0(node->mnHandle);
        }
        if (!node->mb45) {
            node->mbRemove = true;
        }
    }
}
#endif

// FUNCTION: 0x009d3312
void cGZWinTreeView::CreateRootNode()
{
    if (mpRootNode == 0) {
        TreeNode_ae3240* node;
        void* raw = ::operator new(sizeof(TreeNode_ae3240));
        if (raw) {
            node = static_cast<TreeNode_ae3240*>(raw)->Fn009d2b42();
        } else {
            node = 0;
        }
        node->mnHandle = 0;
        node->mbExpanded = true;
        node->mb45 = true;
        node->mbSelected = false;
        node->mpParent = 0;
        node->mnUserData = 0;
        node->mbRemove = false;
        node->mn3C = 2;
        node->mn40 = 3;
        node->mn34 = 0;
        node->mn38 = 1;
        node->mpFont = static_cast<Font_ae3240*>(mpDefaultFont);
        node->mn24 = mnColors[0];
        node->mn28 = mnColors[2];
        node->mn2C = mnColors[1];
        node->mn30 = mnColors[3];
        int32_t handle = mnNextHandle++;
        mpRootNode = node;
        *reinterpret_cast<NodeMapIndex_ae3240*>(mNodeMap)->Fn009389aa(handle) = node;
    }
}

// FUNCTION: 0x009d1f03
void LongList_ae3240::Fn009d1f03(LongIter_ae3240* result, LongIter_ae3240 position)
{
    LongLink_ae3240* link = position.mpNode;
    LongLink_ae3240* next = link->mpNext;
    LongLink_ae3240* prev = link->mpPrev;
    prev->mpNext = next;
    next->mpPrev = prev;
    Fn009d0747()->Free(link);
    result->mpNode = next;
}

// FUNCTION: 0x009d2950
LongIter_ae3240* LongList_ae3240::Fn009d2950(LongIter_ae3240* result, LongIter_ae3240 position, const int32_t& value)
{
    LongLink_ae3240* link = Fn009d1f8b(value);
    LongLink_ae3240* before = position.mpNode->mpPrev;
    link->mpNext = position.mpNode;
    link->mpPrev = before;
    before->mpNext = link;
    position.mpNode->mpPrev = link;
    result->mpNode = link;
    return result;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d291c score 26 (the postfix increment copy is passed differently)
void LongList_ae3240::Fn009d291c(LongIter_ae3240* result, LongIter_ae3240 first, LongIter_ae3240 last)
{
    while (first.mpNode != last.mpNode) {
        Fn009d1f03(&first, first++);
    }
    result->mpNode = last.mpNode;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d31a2 score 6 (the iterator argument is built in a reserved stack slot in the original)
void LongList_ae3240::Fn009d31a2(const int32_t& value)
{
    LongIter_ae3240 end;
    Fn009d2950(&end, End(), value);
}
#endif

// The window the tree builds to show a dragged selection: a cGZWin and five fields.
struct DragWin_ae3240 {
    uint8_t mWin[0xd8];
    void* mpView;
    void* mpNodes;
    void* mpBuffer;
    int32_t mnX;
    int32_t mnY;
    DragWin_ae3240* Fn009cfd89(void* view, void* nodes, void* buffer, int32_t x, int32_t y);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009cfd89 score 0 (the vtable store of the drag window, 0x00ae2c90, is left to the class's own constructor)
DragWin_ae3240* DragWin_ae3240::Fn009cfd89(void* view, void* nodes, void* buffer, int32_t x, int32_t y)
{
    reinterpret_cast<cGZWin*>(this)->Fn0099d938();
    mpView = view;
    mpNodes = nodes;
    mpBuffer = buffer;
    mnX = x;
    mnY = y;
    return this;
}
#endif

// STUB: 0x0040d4c0
MapNode_ae3240* Fn0040d4c0(MapNode_ae3240* node);   // the map iterator's step to the next entry

// A picture (the buffer the icons are cut from), seen through the slots this class calls.
struct Picture_ae3240 {
    virtual void P00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void P03(); virtual void P04(); virtual void P05(); virtual void P06();
    virtual void P07(); virtual void P08();
    virtual uint32_t GetWidth();
    virtual uint32_t GetHeight();
};

// FUNCTION: 0x009cfd0b
bool cGZWinTreeView::DoMessage(uint32_t message)
{
    const uint32_t* msg = OB_PTR(uint32_t, message);
    if (msg[0] == 3) {
        if (msg[1] == 0x887113a3 && msg[2] == 0x1756bac7) {
            mnScrollX = static_cast<Scrollbar_ae3240*>(mpScrollbarH)->GetPosition();
        }
        if (msg[1] == 0x887113a3 && msg[2] == 0x1756bac6) {
            mnFirstRow = static_cast<Scrollbar_ae3240*>(mpScrollbarV)->GetPosition();
            mnLastRow = mnFirstRow + mnVisibleRows - 1;
            if (mnLastRow > mnRowCount - 1) {
                mnLastRow = mnRowCount - 1;
            }
        }
    }
    return cGZWin::DoMessage(message);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d081f score 48 (the original keeps zero in ebx and the vtable in ebp)
bool cGZWinTreeView::Slot57_ae2ef0(uint32_t handle)
{
    NodeVec_ae3240* selection = reinterpret_cast<NodeVec_ae3240*>(mSelection);
    TreeNode_ae3240** end = selection->mpFinish;
    for (TreeNode_ae3240** it = selection->mpStart; it != end; ++it) {
        if ((*it)->mnHandle == static_cast<int32_t>(handle)) {
            (*it)->mbSelected = false;
            selection->Fn008d3333(it);
            InvalidateSelfAndParents();
            SendMsg(field4c, 0x1af5a13a, Slot48_adda20(), 0, 0);
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d0c63 score 26 (the original reads the vector start from memory each time instead of caching it)
bool cGZWinTreeView::Slot21_ae2ef0(uint32_t index, uint32_t pImage, uint32_t pRect)
{
    IconVec_ae3240* icons = reinterpret_cast<IconVec_ae3240*>(mIconImages);
    if (index < icons->size()) {
        *OB_PTR(cIGZUnknown*, pImage) = icons->mpStart[index].mpImage;
        *OB_PTR(Rect_ae3240, pRect) = icons->mpStart[index].mRect;
        return true;
    }
    return false;
}
#endif

// STUB: 0x009d07a0
void Fn009d07a0(NodeIter_ae3240* result, NodeIter_ae3240 first, NodeIter_ae3240 last, TreeNode_ae3240** value);   // std::find over a node list

#ifdef OB_DRAFTS
// CLOSE: 0x009d1fab score 88 (list find/splice with by-value iterators; register allocation differs)
void cGZWinTreeView::Slot26_ae2ef0(uint32_t handle, uint32_t newParent, uint32_t insertAfter)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    TreeNode_ae3240* target = static_cast<TreeNode_ae3240*>(GetNodeByHandle(newParent));
    if (node && target) {
        TreeNode_ae3240* oldParent = node->mpParent;
        if (oldParent) {
            ChildList_ae3240* oldList = reinterpret_cast<ChildList_ae3240*>(&oldParent->mChildren);
            NodeIter_ae3240 begin;
            begin.mpNode = oldList->mpHead->mpNext;
            NodeIter_ae3240 end;
            end.mpNode = oldList->mpHead;
            NodeIter_ae3240 found;
            Fn009d07a0(&found, begin, end, &node);
            ChildList_ae3240* newList = reinterpret_cast<ChildList_ae3240*>(&target->mChildren);
            ListLink_ae3240* head = newList->mpHead;
            ListLink_ae3240* position = head->mpNext;
            if (static_cast<int32_t>(insertAfter) != -2) {
                if (static_cast<int32_t>(insertAfter) == -3) {
                    position = head;
                } else if (static_cast<int32_t>(insertAfter) > 0) {
                    ListLink_ae3240* link = head->mpNext;
                    while (link != head && link->mpNode->mnHandle != static_cast<int32_t>(insertAfter)) {
                        link = link->mpNext;
                    }
                    position = link->mpNext;
                }
            }
            NodeIter_ae3240 at;
            at.mpNode = position;
            newList->Fn0099cc80(at, *oldList, found);
            oldParent->mnChildCount--;
            target->mnChildCount++;
            node->mpParent = target;
            mbDirty = true;
            InvalidateSelfAndParents();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d2e07 score 72 (register allocation and loop shape around the list erase and map walk differ)
bool cGZWinTreeView::Slot27_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        TreeNode_ae3240* parent = node->mpParent;
        if (parent) {
            ListLink_ae3240* head = static_cast<ListLink_ae3240*>(parent->mChildren.mpHead);
            for (ListLink_ae3240* link = head->mpNext; link != head; link = link->mpNext) {
                if (link->mpNode->mnHandle == node->mnHandle) {
                    NodeIter_ae3240 at;
                    at.mpNode = link;
                    NodeIter_ae3240 next;
                    reinterpret_cast<ChildList_ae3240*>(&node->mpParent->mChildren)->Fn00949259(&next, at);
                    node->mpParent->mnChildCount--;
                    break;
                }
            }
        }
        FlagNodeForRemovalRecursively(node);
        NodeMap_ae3240* map = reinterpret_cast<NodeMap_ae3240*>(mNodeMap);
        MapNode_ae3240* header = map->mpHeader;
        MapNode_ae3240* entry = header->mpLeft;
        while (entry != header) {
            MapNode_ae3240* current = entry;
            entry = Fn0040d4c0(current);
            TreeNode_ae3240* doomed = current->mpValue;
            if (doomed->mbRemove) {
                doomed->Fn009d2bd9();
                ::operator delete(doomed);
                MapIter_ae3240 at;
                at.mpNode = current;
                map->Fn00927cf8(at);
            }
        }
        mbDirty = true;
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d2ee6 score 111 (the original keeps the changed flag in memory and the node in ebx)
bool cGZWinTreeView::Slot56_ae2ef0(uint32_t handle, uint32_t multi)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        NodeVec_ae3240* selection = reinterpret_cast<NodeVec_ae3240*>(mSelection);
        bool changed = false;
        bool wasSelected = node->mbSelected;
        if (wasSelected && Selection_ae3240(this).size() > 1 || !wasSelected && !Selection_ae3240(this).empty()) {
            if (*reinterpret_cast<bool*>(&multi) || !Slot04_ae2ef0(0x10)) {
                TreeNode_ae3240** it = selection->mpStart;
                while (it != selection->mpFinish) {
                    (*it)->mbSelected = false;
                    it = selection->Fn008d3333(it);
                }
                changed = true;
            }
        }
        if (!node->mbSelected) {
            Slot47_ae2ef0(handle);
            node->mbSelected = true;
            selection->Fn008ff785(node);
            changed = true;
        }
        if (changed) {
            InvalidateSelfAndParents();
            SendMsg(field4c, 0x1af5a13a, Slot48_adda20(), 0, 0);
        }
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x009d2092
bool cGZWinTreeView::Slot30_ae2ef0(uint32_t handle, uint32_t pInfo)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        NodeInfo_ae3240* info = OB_PTR(NodeInfo_ae3240, pInfo);
        bool expanded = info->mb2C;
        if (expanded != node->mbExpanded) {
            node->mbExpanded = expanded;
            if (expanded) {
                SendMsg(field4c, 0x1af5a13c, Slot48_adda20(), node->mnHandle, 0);
            } else {
                SendMsg(field4c, 0x1af5a13d, Slot48_adda20(), node->mnHandle, 0);
            }
        }
        if (info->mb2E) {
            Slot47_ae2ef0(handle);
        }
        if (info->mb2F != node->mbSelected) {
            if (info->mb2F) {
                Slot56_ae2ef0(handle, 0);
            } else {
                Slot57_ae2ef0(handle);
            }
        }
        node->mn3C = info->mnImage[2];
        node->mn40 = info->mnImage[3];
        node->mn34 = info->mnImage[0];
        node->mn38 = info->mnImage[1];
        Slot39_ae2ef0(handle, OB_ADDR(info->mpFont));
        cIGZString* name = &node->mName;
        name->Copy(*info->mpText);
        node->mnUserData = info->mnUserData;
        node->mn2C = info->mnColor1;
        node->mn30 = info->mnColor3;
        node->mn24 = info->mnColor0;
        node->mn28 = info->mnColor2;
        mbDirty = true;
        InvalidateSelfAndParents();
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d33cd score 39 (iterator arguments and register allocation differ)
bool cGZWinTreeView::Slot29_ae2ef0(uint32_t handle, uint32_t pInfo)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        NodeInfo_ae3240* info = OB_PTR(NodeInfo_ae3240, pInfo);
        info->mb2C = node->mbExpanded;
        info->mb2D = node->mb45;
        info->mb2F = node->mbSelected;
        info->mb2E = Slot46_ae2ef0(handle);
        info->mnImage[2] = node->mn3C;
        info->mnImage[3] = node->mn40;
        info->mnImage[0] = node->mn34;
        info->mnImage[1] = node->mn38;
        info->mpFont = node->mpFont;
        info->mpText->Copy(node->mName);
        info->mnUserData = node->mnUserData;
        info->mnColor1 = node->mn2C;
        info->mnColor3 = node->mn30;
        info->mnColor0 = node->mn24;
        info->mnColor2 = node->mn28;
        LongList_ae3240* handles = &info->mHandles;
        LongIter_ae3240 result;
        handles->Fn009d291c(&result, handles->Begin(), handles->End());
        ListLink_ae3240* head = static_cast<ListLink_ae3240*>(node->mChildren.mpHead);
        for (ListLink_ae3240* link = head->mpNext; link != node->mChildren.mpHead; link = link->mpNext) {
            int32_t value = link->mpNode->mnHandle;
            handles->Fn009d31a2(value);
        }
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d320f score 24 (the image release loop is shaped differently)
bool cGZWinTreeView::Slot04_ae1d24()
{
    NodeVec_ae3240* selection = reinterpret_cast<NodeVec_ae3240*>(mSelection);
    selection->Fn009a1add(selection->mpStart, selection->mpFinish);
    NodeVec_ae3240* visible = reinterpret_cast<NodeVec_ae3240*>(mVisibleNodes);
    visible->Fn009a1add(visible->mpStart, visible->mpFinish);
    NodeMap_ae3240* map = reinterpret_cast<NodeMap_ae3240*>(mNodeMap);
    MapNode_ae3240* header = map->mpHeader;
    MapNode_ae3240* entry = header->mpLeft;
    while (entry != header) {
        MapNode_ae3240* current = entry;
        entry = Fn0040d4c0(current);
        TreeNode_ae3240* node = current->mpValue;
        if (node) {
            node->Fn009d2bd9();
            ::operator delete(node);
        }
    }
    map->Fn009d16b0();
    IconVec_ae3240* icons = reinterpret_cast<IconVec_ae3240*>(mIconImages);
    int32_t count = icons->size();
    if (count > 0) {
        for (int32_t i = 0; i < count; i++) {
            cIGZUnknown* image = icons->mpStart[i].mpImage;
            if (image) {
                image->Release();
            }
        }
    }
    icons->Fn009d1f65(icons->mpStart, icons->mpFinish);
    if (mpDefaultFont) {
        static_cast<cIGZUnknown*>(mpDefaultFont)->Release();
    }
    mpDefaultFont = 0;
    if (mpObject14c) {
        static_cast<cIGZUnknown*>(mpObject14c)->Release();
    }
    mpObject14c = 0;
    if (mpScrollbarH) {
        static_cast<cIGZUnknown*>(mpScrollbarH)->Release();
    }
    mpScrollbarH = 0;
    if (mpScrollbarV) {
        static_cast<cIGZUnknown*>(mpScrollbarV)->Release();
    }
    mpScrollbarV = 0;
    return cGZWin::Slot04_ae1d24();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d34a7 score 30 (the rectangle fill keeps height and width in other registers)
uint32_t cGZWinTreeView::Slot20_ae2ef0(uint32_t pBuffer, uint32_t pRect)
{
    cIGZUnknown* buffer = OB_PTR(cIGZUnknown, pBuffer);
    if (buffer) {
        buffer->AddRef();
        IconImage_ae3240 image;
        image.mpImage = buffer;
        image.mRect = *OB_PTR(Rect_ae3240, pRect);
        if (!image.mRect.Fn007c1870()) {
            Picture_ae3240* picture = reinterpret_cast<Picture_ae3240*>(buffer);
            uint32_t height = picture->GetHeight();
            image.mRect.mnLeft = 0;
            image.mRect.mnTop = 0;
            image.mRect.mnRight = picture->GetWidth();
            image.mRect.mnBottom = height;
        }
        uint32_t width = image.mRect.mnRight - image.mRect.mnLeft;
        if (width > mnImageWidth) {
            mnImageWidth = width;
        }
        uint32_t extent = image.mRect.mnBottom - image.mRect.mnTop;
        if (extent > mnRowHeight) {
            mnRowHeight = extent + 2;
        }
        IconVec_ae3240* icons = reinterpret_cast<IconVec_ae3240*>(mIconImages);
        icons->Fn009d31bc(image);
        return icons->size() - 1;
    }
    return 0xffffffff;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d3f7b score 54 (register allocation of the rectangle updates differs)
bool cGZWinTreeView::Slot19_ae2ef0(uint32_t index, uint32_t pBuffer, uint32_t pRect)
{
    if (static_cast<int32_t>(index) < 0 || static_cast<int32_t>(index) >= 4) {
        return false;
    }
    IconVec_ae3240* icons = reinterpret_cast<IconVec_ae3240*>(mIconImages);
    if (index >= icons->size()) {
        icons->Fn009d3f21(index + 1);
    }
    cIGZUnknown* buffer = OB_PTR(cIGZUnknown, pBuffer);
    if (buffer) {
        buffer->AddRef();
    }
    cIGZUnknown* old = icons->mpStart[index].mpImage;
    if (old) {
        old->Release();
    }
    icons->mpStart[index].mpImage = buffer;
    icons->mpStart[index].mRect = *OB_PTR(Rect_ae3240, pRect);
    if (OB_PTR(Picture_ae3240, pBuffer)) {
        Picture_ae3240* picture = OB_PTR(Picture_ae3240, pBuffer);
        if (!icons->mpStart[index].mRect.Fn007c1870()) {
            uint32_t height = picture->GetHeight();
            uint32_t width = picture->GetWidth();
            Rect_ae3240* r = &icons->mpStart[index].mRect;
            r->mnLeft = 0;
            r->mnTop = 0;
            r->mnRight = width;
            r->mnBottom = height;
        }
    }
    Rect_ae3240* rect = &icons->mpStart[index].mRect;
    if (static_cast<uint32_t>(rect->mnRight - rect->mnLeft) > mnImageWidth) {
        mnImageWidth = rect->mnRight - rect->mnLeft;
    }
    if (static_cast<uint32_t>(rect->mnBottom - rect->mnTop) > mnRowHeight) {
        mnRowHeight = rect->mnBottom - rect->mnTop + 2;
    }
    return true;
}
#endif

// FUNCTION: 0x009d3e50
bool cGZWinTreeView::Slot47_ae2ef0(uint32_t handle)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeByHandle(handle));
    if (node) {
        if (mbDirty) {
            RecalculateAll();
        }
        if (!node->mb47) {
            for (TreeNode_ae3240* parent = node->mpParent; parent; parent = parent->mpParent) {
                if (!parent->mbExpanded) {
                    parent->mbExpanded = true;
                    SendMsg(field4c, 0x1af5a13c, Slot48_adda20(), parent->mnHandle, 0);
                }
            }
            RecalculateAll();
        }
        if (node->mb47) {
            uint32_t row = node->mn7C;
            uint32_t first = mnFirstRow;
            if (row < first) {
                if (mpScrollbarV) {
                    static_cast<Scrollbar_ae3240*>(mpScrollbarV)->SetPosition(row);
                }
            } else if (row >= first + mnVisibleRows2) {
                if (mpScrollbarV) {
                    static_cast<Scrollbar_ae3240*>(mpScrollbarV)->SetPosition(row - mnVisibleRows2 + 1);
                }
            }
            return true;
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d2fd6 score 161 (register allocation: the original keeps this in ebx and the node in esi)
void cGZWinTreeView::FindTreeInfo(void* nodeArg, void* pRow, uint32_t depth, void* pMax)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(nodeArg);
    uint32_t* row = static_cast<uint32_t*>(pRow);
    uint32_t* maxWidth = static_cast<uint32_t*>(pMax);
    uint32_t offset = 0;
    if (node) {
        if (!node->mb45 || Slot04_ae2ef0(2)) {
            node->mn7C = *row;
            node->mb47 = true;
            reinterpret_cast<NodeVec_ae3240*>(mVisibleNodes)->Fn008ff785(node);
        }
        uint32_t indent = 0;
        if (Slot04_ae2ef0(4)) {
            if (mnImageWidth > mnBoxSize) {
                indent = (mnImageWidth - mnBoxSize) >> 1;
            }
        }
        if (node->mb45) {
            if (!Slot04_ae2ef0(2)) {
                ListLink_ae3240* head = static_cast<ListLink_ae3240*>(node->mChildren.mpHead);
                for (ListLink_ae3240* link = head->mpNext; link != head; link = link->mpNext) {
                    FindTreeInfo(link->mpNode, pRow, depth, pMax);
                }
                return;
            }
        } else {
            offset = (mnBoxSize + mnIconGutter + indent) * depth + mnBoxSize + mnIconGutter + indent;
        }
        Slot04_ae2ef0(4);
        const std::string& text = node->mName;
        uint32_t width = node->mpFont->GetTextWidth(text.data(), text.size());
        uint32_t extent = offset + (mnIconGutter + mnImageWidth) + width + 3;
        if (extent > *maxWidth) {
            *maxWidth = extent;
        }
        ++*row;
        if (node->mbExpanded) {
            if (!node->mb45) {
                depth++;
            }
            ListLink_ae3240* head = static_cast<ListLink_ae3240*>(node->mChildren.mpHead);
            for (ListLink_ae3240* link = head->mpNext; link != head; link = link->mpNext) {
                FindTreeInfo(link->mpNode, pRow, depth, pMax);
            }
        }
    }
}
#endif

// A pair of words the services take by value; built by the original's constructor from one word.
struct Pair_ae3240 {
    uint32_t mnFirst;
    uint32_t mnSecond;
    // STUB: 0x0044a490
    Pair_ae3240(uint32_t first);
    // Copying a temporary into an argument is done in place by the compiler; never defined.
    Pair_ae3240(const Pair_ae3240& other);
};

// The area the tree scrolls: the object at +0x14c, seen through the slots this class calls.
struct Frame_ae3240 {
    virtual void P00();
    virtual void P01();
    virtual uint32_t Release();
    virtual bool Init(uint32_t width, uint32_t height, Pair_ae3240 flags);
    virtual void P04();
    virtual void P05();
    virtual bool Lock(uint32_t mode);
    virtual void Unlock(uint32_t mode);
    virtual void P08();
    virtual uint32_t GetWidth();
    virtual uint32_t GetHeight();
    virtual void P11();
    virtual const Rect_ae3240* GetRect();
    virtual void P13(); virtual void P14(); virtual void P15(); virtual void P16(); virtual void P17();
    virtual void Fill(uint32_t color, const Rect_ae3240* rect);
    virtual void P19();
    virtual void FillRect(uint32_t color, const Rect_ae3240* rect, uint32_t flags);
    virtual void P21(); virtual void P22();
    virtual void SetColor(uint32_t color);
    virtual void P24(); virtual void P25(); virtual void P26(); virtual void P27(); virtual void P28();
    virtual void Blit(void* image, const Rect_ae3240* source, const Rect_ae3240* destination, uint32_t flags);
    virtual uint32_t MakeColor(uint32_t red, uint32_t green, uint32_t blue);
    virtual void GetColor(uint32_t color, uint8_t* red, uint8_t* green, uint8_t* blue);
};

// The cGZWin area rectangle (left, top, right, bottom).
inline const int32_t* Area_ae3240(cGZWinTreeView* view)
{
    return reinterpret_cast<const int32_t*>(view->field24);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d0331 score 38 (CheckForScrollbars: scheduling of the early loads differs)
void cGZWinTreeView::CheckForScrollbars()
{
    mbShowHScroll = false;
    mbShowVScroll = false;
    uint32_t width = Area_ae3240(this)[2] - Area_ae3240(this)[0];
    int32_t overflowX = static_cast<Frame_ae3240*>(mpObject14c)->GetWidth() + (mnGutterX * 2 - width);
    uint32_t availH = Area_ae3240(this)[3] - mnGutterY * 2 - Area_ae3240(this)[1];
    int32_t overflowY = mnRowCount - static_cast<int32_t>(floor(static_cast<double>(static_cast<float>(availH) / static_cast<float>(mnRowHeight))));
    if (overflowX > 0) {
        Fn009d0112();
        mbShowHScroll = true;
    }
    if (overflowY > 0) {
        Fn009d01c0();
        mbShowVScroll = true;
    }
    if (mbShowHScroll && !mbShowVScroll) {
        if (static_cast<int32_t>(ceil(static_cast<double>(static_cast<float>(mnScrollbarSize) / static_cast<float>(mnRowHeight)))) + overflowY > 0) {
            mbShowVScroll = true;
        }
    }
    if (!mbShowHScroll && mbShowVScroll) {
        if (mnScrollbarSize + overflowX > 0) {
            mbShowHScroll = true;
        }
    }
    if (mbShowHScroll) {
        Fn009d0112();
    } else {
        Fn009cfc7e();
    }
    if (mbShowVScroll) {
        Fn009d01c0();
    } else {
        Fn009cfcb3();
    }
    Fn009d026e();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d049b score 9 (scheduling)
void cGZWinTreeView::UpdateScrollbarValues()
{
    if (mbShowHScroll) {
        uint32_t width = Area_ae3240(this)[2] - Area_ae3240(this)[0];
        uint32_t range = static_cast<Frame_ae3240*>(mpObject14c)->GetWidth() + (mnGutterX * 2 - width);
        if (mbShowVScroll) {
            range += mnScrollbarSize;
        }
        uint32_t low;
        uint32_t high;
        static_cast<Scrollbar_ae3240*>(mpScrollbarH)->GetRange(&low, &high);
        if (high != range) {
            static_cast<Scrollbar_ae3240*>(mpScrollbarH)->SetRange(0, range);
            static_cast<Scrollbar_ae3240*>(mpScrollbarH)->SetPage(range, range);
            if (static_cast<int32_t>(static_cast<Scrollbar_ae3240*>(mpScrollbarH)->GetPosition()) > static_cast<int32_t>(range)) {
                static_cast<Scrollbar_ae3240*>(mpScrollbarH)->SetPosition(range);
            }
        }
    }
    if (mbShowVScroll) {
        uint32_t rowHeight = mnRowHeight;
        uint32_t visible = (Area_ae3240(this)[3] - mnGutterY * 2 - Area_ae3240(this)[1]) / rowHeight;
        uint32_t range = mnRowCount - visible;
        if (mbShowHScroll) {
            range += static_cast<int32_t>(ceil(static_cast<double>(static_cast<float>(mnScrollbarSize) / static_cast<float>(rowHeight))));
        }
        uint32_t low;
        uint32_t high;
        static_cast<Scrollbar_ae3240*>(mpScrollbarV)->GetRange(&low, &high);
        if (high != range) {
            static_cast<Scrollbar_ae3240*>(mpScrollbarV)->SetRange(0, range);
            uint32_t page = range;
            if (visible != 0) {
                page = (mnRowCount + visible - 1) / visible;
            }
            static_cast<Scrollbar_ae3240*>(mpScrollbarV)->SetPage(range, page);
            if (static_cast<int32_t>(static_cast<Scrollbar_ae3240*>(mpScrollbarV)->GetPosition()) > static_cast<int32_t>(range)) {
                static_cast<Scrollbar_ae3240*>(mpScrollbarV)->SetPosition(range);
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d354f score 133 (temporary Pair argument built in a local instead of in the argument area; scheduling)
void cGZWinTreeView::RecalculateAll()
{
    NodeVec_ae3240* visible = reinterpret_cast<NodeVec_ae3240*>(mVisibleNodes);
    visible->Fn009a1add(visible->mpStart, visible->mpFinish);
    NodeMap_ae3240* map = reinterpret_cast<NodeMap_ae3240*>(mNodeMap);
    MapNode_ae3240* header = map->mpHeader;
    MapNode_ae3240* entry = header->mpLeft;
    while (entry != header) {
        entry->mpValue->mb47 = false;
        entry = Fn0040d4c0(entry);
    }
    uint32_t maxWidth = 0;
    mnRowCount = 0;
    FindTreeInfo(mpRootNode, &mnRowCount, 0, &maxWidth);
    uint32_t height = Area_ae3240(this)[3] - Area_ae3240(this)[1];
    uint32_t content = mnRowCount * mnRowHeight;
    if (height < content) {
        content = height + mnRowHeight;
    }
    if (static_cast<Frame_ae3240*>(mpObject14c)->GetWidth() != maxWidth || static_cast<Frame_ae3240*>(mpObject14c)->GetHeight() != content) {
        static_cast<Frame_ae3240*>(mpObject14c)->P05();
        if (mnRowCount == 0) {
            static_cast<Frame_ae3240*>(mpObject14c)->Init(1, 1, Pair_ae3240(1));
        } else {
            static_cast<Frame_ae3240*>(mpObject14c)->Init(maxWidth, content, Pair_ae3240(1));
        }
    }
    CheckForScrollbars();
    UpdateScrollbarValues();
    if (!mbShowHScroll) {
        mnScrollX = 0;
    }
    if (!mbShowVScroll) {
        mnFirstRow = 0;
        mnLastRow = mnRowCount - 1;
    }
    uint32_t availW = Area_ae3240(this)[2] - mnGutterX * 2 - Area_ae3240(this)[0] - (mbShowVScroll ? mnScrollbarSize : 0);
    uint32_t availH = Area_ae3240(this)[3] - mnGutterY * 2 - Area_ae3240(this)[1] - (mbShowHScroll ? mnScrollbarSize : 0);
    if (static_cast<Frame_ae3240*>(mpObject14c)->GetWidth() <= availW) {
        availW = static_cast<Frame_ae3240*>(mpObject14c)->GetWidth();
    }
    if (static_cast<Frame_ae3240*>(mpObject14c)->GetHeight() <= availH) {
        availH = static_cast<Frame_ae3240*>(mpObject14c)->GetHeight();
    }
    mnScreenRect[0] = mnGutterX + Area_ae3240(this)[0];
    mnScreenRect[1] = Area_ae3240(this)[1] + mnGutterY;
    mnScreenRect[2] = mnScreenRect[0] + availW;
    mnScreenRect[3] = mnScreenRect[1] + availH;
    mnViewRect[2] = availW;
    uint32_t rowHeight = mnRowHeight;
    uint32_t rows = availH / rowHeight;
    mnViewRect[0] = 0;
    mnViewRect[1] = 0;
    mnViewRect[3] = availH;
    mnVisibleRows2 = rows;
    uint32_t pageRows = static_cast<int32_t>(ceil(static_cast<double>(static_cast<float>(availH) / static_cast<float>(rowHeight))));
    mnVisibleRows = pageRows;
    mnLastRow = mnFirstRow + pageRows - 1;
    if (mnLastRow - mnFirstRow < pageRows - 1) {
        mnFirstRow = mnRowCount - pageRows - 1;
        mnLastRow = mnFirstRow + pageRows - 1;
        if (mpScrollbarV) {
            static_cast<Scrollbar_ae3240*>(mpScrollbarV)->SetPosition(mnFirstRow);
        }
    }
    mbDirty = false;
}
#endif

// The graphics service the tree asks for its buffers (slot 3 makes one).
struct GraphicsService_ae3240 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual bool CreateBuffer(Frame_ae3240** out);
};

// STUB: 0x00913c1a
GraphicsService_ae3240* Fn00913c1a();

// The window-class manager: slot 5 hands out a font by its id, slot 32 a system color.
struct WindowClassManager_ae3240 {
    virtual void P00(); virtual void P01(); virtual void P02(); virtual void P03(); virtual void P04();
    virtual cIGZUnknown* GetClass(uint32_t id);
    virtual void P06(); virtual void P07(); virtual void P08(); virtual void P09(); virtual void P10();
    virtual void P11(); virtual void P12(); virtual void P13(); virtual void P14(); virtual void P15();
    virtual void P16(); virtual void P17(); virtual void P18(); virtual void P19(); virtual void P20();
    virtual void P21(); virtual void P22(); virtual void P23(); virtual void P24(); virtual void P25();
    virtual void P26(); virtual void P27(); virtual void P28(); virtual void P29(); virtual void P30();
    virtual void P31();
    virtual uint32_t GetSystemColor(uint32_t id);
};

// STUB: 0x00913c72
WindowClassManager_ae3240* Fn00913c72();

// STUB: 0x009328e0
void Fn009328e0(Frame_ae3240* buffer, float x0, float y0, float x1, float y1, float x2, float y2, uint32_t color);   // fills a triangle

// FUNCTION: 0x009d3956
void cGZWinTreeView::InternalInit()
{
    if (!mbInitialized) {
        mbInitialized = true;
        if (mnBackgroundColor == 0xdeadbeef) {
            mnBackgroundColor = 0xffffffff;
        }
        if (mnColors[0] == 0xdeadbeef) {
            mnColors[0] = MakeFillColor(0, 0, 0);
        }
        if (mnColors[1] == 0xdeadbeef) {
            mnColors[1] = MakeFillColor(0xff, 0xff, 0xff);
        }
        if (mnColors[2] == 0xdeadbeef) {
            mnColors[2] = MakeFillColor(0xff, 0xff, 0xff);
        }
        if (mnColors[3] == 0xdeadbeef) {
            mnColors[3] = MakeFillColor(0, 0, 0);
        }
        if (mpDefaultFont == 0) {
            cIGZUnknown* font = Fn00913c72()->GetClass(0x68963c4c);
            mpDefaultFont = font;
            if (font) {
                font->AddRef();
            }
        }
        InitializeImageList();
        if (mpRootNode == 0) {
            CreateRootNode();
        }
        if (mpObject14c == 0) {
            GraphicsService_ae3240* service = Fn00913c1a();
            if (service) {
                if (service->CreateBuffer(reinterpret_cast<Frame_ae3240**>(&mpObject14c))) {
                    if (!static_cast<Frame_ae3240*>(mpObject14c)->Init(1, 1, Pair_ae3240(1))) {
                        static_cast<Frame_ae3240*>(mpObject14c)->Release();
                        mpObject14c = 0;
                    }
                }
            }
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009d0888 score 238 (register allocation (the original keeps zero in edi, the service in ebx))
void cGZWinTreeView::InitializeImageList()
{
    GraphicsService_ae3240* service = Fn00913c1a();
    if (service) {
        WindowClassManager_ae3240* classes = Fn00913c72();
        if (classes) {
            uint32_t colorA = MakeFillColor(0, 0, 0x96);
            uint32_t colorB = MakeFillColor(0xdc, 0, 0);
            uint32_t symbol = classes->GetSystemColor(0x8963f6c);
            Frame_ae3240* image = 0;
            IconVec_ae3240* icons = reinterpret_cast<IconVec_ae3240*>(mIconImages);
            if (icons->size() == 0 || icons->mpStart[0].mpImage == 0) {
                if (service->CreateBuffer(&image)) {
                    uint32_t size = mnMaxBoxSize;
                    if (image->Init(size, size, Pair_ae3240(1))) {
                        if (image->Lock(0x8001)) {
                            image->Fill(colorA, 0);
                            image->Unlock(0x8001);
                        }
                    }
                    Rect_ae3240 rect = { 0, 0, 0, 0 };
                    Slot19_ae2ef0(0, OB_ADDR(image), OB_ADDR(&rect));
                    image->Release();
                    image = 0;
                }
            }
            if (icons->size() <= 1 || icons->mpStart[1].mpImage == 0) {
                if (service->CreateBuffer(&image)) {
                    uint32_t size = mnMaxBoxSize;
                    if (image->Init(size, size, Pair_ae3240(1))) {
                        if (image->Lock(0x8001)) {
                            image->Fill(colorB, 0);
                            image->Unlock(0x8001);
                        }
                    }
                    Rect_ae3240 rect = { 0, 0, 0, 0 };
                    Slot19_ae2ef0(1, OB_ADDR(image), OB_ADDR(&rect));
                    image->Release();
                    image = 0;
                }
            }
            if (icons->size() <= 2 || icons->mpStart[2].mpImage == 0) {
                if (service->CreateBuffer(&image)) {
                    uint32_t size = mnMaxBoxSize;
                    if (image->Init(size, size, Pair_ae3240(1))) {
                        image->SetColor(symbol);
                        if (image->Lock(0x8001)) {
                            image->Fill(symbol, 0);
                            image->Unlock(0x8001);
                        }
                        float edge = static_cast<float>(mnMaxBoxSize);
                        Fn009328e0(image, 0.0f, 0.0f, edge * 0.5f, edge, edge, 0.0f, colorA);
                    }
                    Rect_ae3240 rect = { 0, 0, 0, 0 };
                    Slot19_ae2ef0(2, OB_ADDR(image), OB_ADDR(&rect));
                    image->Release();
                    image = 0;
                }
            }
            if (icons->size() <= 3 || icons->mpStart[3].mpImage == 0) {
                if (service->CreateBuffer(&image)) {
                    uint32_t size = mnMaxBoxSize;
                    if (image->Init(size, size, Pair_ae3240(1))) {
                        image->SetColor(symbol);
                        if (image->Lock(0x8001)) {
                            image->Fill(symbol, 0);
                            image->Unlock(0x8001);
                        }
                        float edge = static_cast<float>(mnMaxBoxSize);
                        Fn009328e0(image, 0.0f, 0.0f, edge * 0.5f, edge, edge, 0.0f, colorB);
                    }
                    Rect_ae3240 rect = { 0, 0, 0, 0 };
                    Slot19_ae2ef0(3, OB_ADDR(image), OB_ADDR(&rect));
                    image->Release();
                }
            }
        }
    }
}
#endif

// The drawing context a window paints through (field6c), seen through the slots this class calls.
struct DrawContext_ae3240 {
    virtual void P00(); virtual void P01(); virtual void P02(); virtual void P03(); virtual void P04();
    virtual void P05(); virtual void P06(); virtual void P07(); virtual void P08(); virtual void P09();
    virtual void P10(); virtual void P11(); virtual void P12(); virtual void P13(); virtual void P14();
    virtual void P15(); virtual void P16(); virtual void P17(); virtual void P18(); virtual void P19();
    virtual void P20();
    virtual void SetColor(uint32_t color);
    virtual void P22(); virtual void P23(); virtual void P24(); virtual void P25(); virtual void P26();
    virtual void P27(); virtual void P28(); virtual void P29(); virtual void P30(); virtual void P31();
    virtual void P32(); virtual void P33(); virtual void P34();
    virtual void FillRect(const void* rect);
    virtual void P36(); virtual void P37();
    virtual void Blit(Frame_ae3240* source, const Rect_ae3240* sourceRect, const void* destination);
};

// The vector<bool> the node painter fills (start, finish, capacity: five words).
struct BoolVector_ae3240 {
    void* mpStart;
    uint32_t mnStartBit;
    void* mpFinish;
    uint32_t mnFinishBit;
    void* mpEnd;
};

#ifdef OB_DRAFTS
// CLOSE: 0x009d37c6 score 4 (Slot04_ae2ef0 is declared uint32_t but the original tests al (a bool return); signature ask)
bool cGZWinTreeView::GZPaint()
{
    if (mbDirty) {
        RecalculateAll();
    }
    if (Slot04_ae2ef0(0x20)) {
        OB_PTR(DrawContext_ae3240, field6c)->SetColor(mnBackgroundColor);
        OB_PTR(DrawContext_ae3240, field6c)->FillRect(&field24[0]);
    }
    uint32_t zero = 0;
    if (mnRowCount > zero) {
        if (mbPending) {
            Fn009d0fd1();
            mbPending = false;
        }
        if (Slot04_ae2ef0(0x20)) {
            if (static_cast<Frame_ae3240*>(mpObject14c)->Lock(0x8001)) {
                const Rect_ae3240* area = static_cast<Frame_ae3240*>(mpObject14c)->GetRect();
                Rect_ae3240 rect;
                rect.mnLeft = area->mnLeft;
                rect.mnTop = area->mnTop;
                rect.mnRight = area->mnRight;
                rect.mnBottom = area->mnBottom;
                static_cast<Frame_ae3240*>(mpObject14c)->FillRect(mnBackgroundColor, &rect, zero);
                static_cast<Frame_ae3240*>(mpObject14c)->Unlock(0x8001);
            }
        }
        BoolVector_ae3240 flags;
        uint32_t row = 0;
        flags.mpStart = 0;
        flags.mnStartBit = 0;
        flags.mpFinish = 0;
        flags.mnFinishBit = 0;
        flags.mpEnd = 0;
        DrawNode(mpRootNode, &row, zero, &flags, zero);
        Rect_ae3240 source = *reinterpret_cast<Rect_ae3240*>(mnViewRect);
        source.mnLeft += mnScrollX;
        source.mnRight += mnScrollX;
        OB_PTR(DrawContext_ae3240, field6c)->Blit(static_cast<Frame_ae3240*>(mpObject14c), &source, mnScreenRect);
        if (flags.mpStart) {
            Fn0090cf63(flags.mpStart);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d135a score 4 (branch layout of the two rectangle tests)
bool cGZWinTreeView::GZOnMouseDownR(uint32_t x, uint32_t y, uint32_t flags)
{
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(GetNodeAtCursorPosition(x, y));
    if (node) {
        Slot47_ae2ef0(node->mnHandle);
        x += mnScrollX - mnGutterX;
        y = y - mnGutterY;
        if (node->mb4A && reinterpret_cast<Rect_ae3240*>(&node->mn6C)->Fn0043fde0(x, y)
            || node->mb49 && reinterpret_cast<Rect_ae3240*>(&node->mn5C)->Fn0043fde0(x, y)) {
            Slot56_ae2ef0(node->mnHandle, 1);
            SendMsg(field4c, 0x1af5a13e, node->mnHandle, 0, 0);
            SendMsg(field4c, 0x1af5a13f, node->mnHandle, 0, 0);
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d14bf score 114 (switch dispatch and the unsigned clamps compile differently (jump table order, register use))
bool cGZWinTreeView::GZOnKeyDown(uint32_t key, uint32_t flags)
{
    if (key == 0x1b) {
        Slot58_ae2ef0();
        return true;
    }
    std::vector<TreeNode_ae3240*>& selection = Selection_ae3240(this);
    if (key == 0xd) {
        for (std::vector<TreeNode_ae3240*>::iterator it = selection.begin(); it != selection.end(); ++it) {
            TreeNode_ae3240* node = *it;
            SendMsg(field4c, 0x1af5a13b, Slot48_adda20(), node->mnHandle, 0);
            if (node->mb48 || node->mb45) {
                node->mbExpanded = !node->mbExpanded;
                if (!node->mbExpanded) {
                    Fn009d0f85(node, 0, 1);
                    mbPending = true;
                }
                mbDirty = true;
                InvalidateSelfAndParents();
                if (node->mbExpanded) {
                    SendMsg(field4c, 0x1af5a13c, Slot48_adda20(), node->mnHandle, 0);
                } else {
                    SendMsg(field4c, 0x1af5a13d, Slot48_adda20(), node->mnHandle, 0);
                }
            }
        }
        return true;
    }
    int32_t count = selection.size();
    uint32_t row;
    if (count == 0) {
        row = 0;
    } else {
        TreeNode_ae3240* last;
        if (count == 1) {
            last = selection[0];
        } else {
            last = selection[count - 1];
        }
        row = last->mn7C;
    }
    NodeVec_ae3240* visible = reinterpret_cast<NodeVec_ae3240*>(mVisibleNodes);
    switch (key) {
    case 0x21:
        row -= mnVisibleRows2;
        break;
    case 0x22:
        row += mnVisibleRows2;
        break;
    case 0x23:
        row = mnRowCount;
        row--;
        break;
    case 0x24:
        row = 0;
        break;
    case 0x25:
        if (count != 0) {
            TreeNode_ae3240* node = visible->mpStart[row];
            if (node->mbExpanded) {
                Slot45_ae2ef0(node->mnHandle, 0);
            } else if (node->mpParent) {
                row = node->mpParent->mn7C;
            }
        }
        break;
    case 0x26:
        row--;
        break;
    case 0x27:
        if (count != 0) {
            TreeNode_ae3240* node = visible->mpStart[row];
            if (!node->mbExpanded) {
                Slot45_ae2ef0(node->mnHandle, 1);
            } else {
                row++;
            }
        }
        break;
    case 0x28:
        row++;
        break;
    default:
        return true;
    }
    if (static_cast<int32_t>(row) < 0) {
        row = 0;
    }
    if (row >= mnRowCount) {
        row = mnRowCount - 1;
    }
    Slot56_ae2ef0(visible->mpStart[row]->mnHandle, 1);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d3a7a score 282 (list insertion branches: the original orders the front/back/insert tests differently; iterator arguments by value)
uint32_t cGZWinTreeView::Slot25_ae2ef0(uint32_t pInfo)
{
    if (!mbInitialized) {
        InternalInit();
    }
    NodeMap_ae3240* map = reinterpret_cast<NodeMap_ae3240*>(mNodeMap);
    if (map->mnCount != 0) {
        InsertInfo_ae3240* info = OB_PTR(InsertInfo_ae3240, pInfo);
        TreeNode_ae3240* parent = static_cast<TreeNode_ae3240*>(GetNodeByHandle(info->mnParent));
        if (parent) {
            TreeNode_ae3240* node;
            void* raw = ::operator new(sizeof(TreeNode_ae3240));
            if (raw) {
                node = static_cast<TreeNode_ae3240*>(raw)->Fn009d2b42();
            } else {
                node = 0;
            }
            node->mnInsertAfter = info->mnInsertAfter;
            node->mnHandle = mnNextHandle++;
            cIGZString* name = &node->mName;
            name->Copy(*info->mNode.mpText);
            node->mnUserData = info->mNode.mnUserData;
            node->mbExpanded = info->mNode.mb2C;
            node->mb45 = false;
            node->mbSelected = false;
            node->mbRemove = false;
            node->mn34 = info->mNode.mnImage[0];
            node->mn38 = info->mNode.mnImage[1];
            node->mn3C = info->mNode.mnImage[2];
            node->mn40 = info->mNode.mnImage[3];
            Font_ae3240* font = info->mNode.mpFont;
            if (!font) {
                font = static_cast<Font_ae3240*>(mpDefaultFont);
            }
            node->mpFont = font;
            if (mnRowHeight < font->GetTextHeight(0, 0)) {
                mnRowHeight = node->mpFont->GetTextHeight(0, 0);
            }
            node->mn24 = info->mNode.mnColor0;
            node->mn28 = info->mNode.mnColor2;
            node->mn2C = info->mNode.mnColor1;
            node->mn30 = info->mNode.mnColor3;
            node->mpParent = parent;
            ChildList_ae3240* children = reinterpret_cast<ChildList_ae3240*>(&parent->mChildren);
            int32_t after = info->mnInsertAfter;
            if (after == -2) {
                children->Fn009d74d9(node);
            } else if (after == -3) {
                children->Fn008f6e80(node);
            } else {
                ListLink_ae3240* head = children->mpHead;
                ListLink_ae3240* link;
                if (after == -4) {
                    link = head->mpNext;
                    while (link != head && !Fn009d1708(&node->mName, &link->mpNode->mName)) {
                        link = link->mpNext;
                    }
                } else {
                    TreeNode_ae3240* sibling = static_cast<TreeNode_ae3240*>(GetNodeByHandle(after));
                    if (!sibling) {
                        return 0xffffffff;
                    }
                    link = head->mpNext;
                    while (link != head && sibling->mnHandle != link->mpNode->mnHandle) {
                        link = link->mpNext;
                    }
                }
                if (link == head->mpNext) {
                    children->Fn009d74d9(node);
                } else if (link == head) {
                    children->Fn008f6e80(node);
                } else {
                    NodeIter_ae3240 at;
                    at.mpNode = link;
                    NodeIter_ae3240 result;
                    children->Fn00897c8d(&result, at, node);
                }
            }
            parent->mnChildCount++;
            mbDirty = true;
            InvalidateSelfAndParents();
            int32_t handle = node->mnHandle;
            *reinterpret_cast<NodeMapIndex_ae3240*>(mNodeMap)->Fn009389aa(handle) = node;
            return node->mnHandle;
        }
    }
    return 0xffffffff;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009d0cb1 score 329 (drawing code written from the Mac logic; icon/text rectangle arithmetic and register use differ)
void cGZWinTreeView::DrawItem(void* surfaceArg, void* nodeArg, int32_t x, int32_t y)
{
    Frame_ae3240* surface = static_cast<Frame_ae3240*>(surfaceArg);
    TreeNode_ae3240* node = static_cast<TreeNode_ae3240*>(nodeArg);
    if (Slot04_ae2ef0(4)) {
        int32_t icon = -1;
        if (!node->mbExpanded || node->mnChildCount == 0) {
            if (node->mn34 != 0xffffffff) {
                icon = node->mn34;
            }
            if (node->mbSelected) {
                int32_t selectedIcon = node->mn38;
                if (selectedIcon != -1) {
                    icon = selectedIcon;
                }
            }
        } else {
            if (node->mn3C != 0xffffffff) {
                icon = node->mn3C;
            }
            if (node->mbSelected) {
                int32_t selectedIcon = node->mn40;
                if (selectedIcon != -1) {
                    icon = selectedIcon;
                }
            }
        }
        if (icon != -1) {
            IconVec_ae3240* icons = reinterpret_cast<IconVec_ae3240*>(mIconImages);
            void* image = icons->mpStart[icon].mpImage;
            Rect_ae3240 source = icons->mpStart[icon].mRect;
            if (surface->Lock(0x8010)) {
                Rect_ae3240 target;
                target.mnTop = ((mnRowHeight - source.mnBottom + source.mnTop) >> 1) + y;
                target.mnBottom = source.mnBottom - source.mnTop + target.mnTop;
                target.mnLeft = ((mnImageWidth - source.mnRight + source.mnLeft) >> 1) + x;
                target.mnRight = source.mnRight - source.mnLeft + target.mnLeft;
                surface->Blit(image, &source, &target, 0);
                surface->Unlock(0x8010);
                *reinterpret_cast<Rect_ae3240*>(&node->mn6C) = target;
                node->mb4A = true;
            }
        }
    }
    Rect_ae3240 text;
    text.mnLeft = mnIconGutter + mnImageWidth + x;
    text.mnTop = y;
    const std::string& name = node->mName;
    text.mnRight = node->mpFont->GetTextWidth(name.data(), name.size()) + 3 + text.mnLeft;
    text.mnBottom = mnRowHeight + y;
    uint32_t colorA;
    uint32_t colorB;
    if (!node->mbSelected) {
        colorA = node->mn24;
        colorB = node->mn2C;
    } else {
        if (surface->Lock(0x8001)) {
            Rect_ae3240 band = text;
            if (!mbBlendSelection) {
                surface->Fill(mnColors[3], &text);
            } else {
                uint8_t r1;
                uint8_t g1;
                uint8_t b1;
                uint8_t r2;
                uint8_t g2;
                uint8_t b2;
                surface->GetColor(mnColors[1], &r1, &g1, &b1);
                surface->GetColor(mnColors[3], &r2, &g2, &b2);
                uint32_t blended = surface->MakeColor((r2 + r1) >> 1, (g2 + g1) >> 1, (b2 + b1) >> 1);
                surface->Fill(blended, &text);
                band.mnBottom = (band.mnTop * 3 + 2 + band.mnBottom) >> 2;
                band.mnLeft = surface->GetRect()->mnLeft;
                band.mnRight = surface->GetRect()->mnRight;
                surface->Fill(mnColors[3], &band);
            }
            surface->Unlock(0x8001);
        }
        colorA = node->mn28;
        colorB = node->mn30;
    }
    node->mpFont->DrawText(surface, text.mnLeft + 3, text.mnTop + 1, name.data(), name.size(), colorA, colorB, 0, 0);
    if (surface == mpObject14c) {
        *reinterpret_cast<Rect_ae3240*>(&node->mn5C) = text;
        node->mb49 = true;
    }
}
#endif

// The allocator part of the icon vector (at +8 of the vector), and the library's range helpers.
struct IconStorage_ae3240 {
    // STUB: 0x009cff48
    IconImage_ae3240* Fn009cff48(uint32_t count, uint32_t hint);
};

// STUB: 0x009cff9a
IconImage_ae3240* Fn009cff9a(IconImage_ae3240* first, IconImage_ae3240* last, IconImage_ae3240* result, const Tag_ae3240& tag);   // uninitialized copy

// STUB: 0x009cffc0
IconImage_ae3240* Fn009cffc0(IconImage_ae3240* result, uint32_t count, const IconImage_ae3240& value, const Tag_ae3240& tag);   // uninitialized fill

#ifdef OB_DRAFTS
// CLOSE: 0x009d2992 score 37 (std::vector<IconImage>::_M_insert_overflow: a draft of the library code; the temporaries of the empty tag type sit elsewhere)
void IconVec_ae3240::Fn009d2992(IconImage_ae3240* position, const IconImage_ae3240& value, const Tag_ae3240& tag, uint32_t count, bool atEnd)
{
    uint32_t oldSize = size();
    const uint32_t* larger = oldSize < count ? &count : &oldSize;
    uint32_t length = *larger + oldSize;
    IconImage_ae3240* newStart = reinterpret_cast<IconStorage_ae3240*>(&mpEnd)->Fn009cff48(length, 0);
    IconImage_ae3240* newFinish = Fn009cff9a(mpStart, position, newStart, Tag_ae3240());
    if (count == 1) {
        Fn009cff64(newFinish, value);
        newFinish++;
    } else {
        newFinish = Fn009cffc0(newFinish, count, value, Tag_ae3240());
    }
    if (!atEnd) {
        newFinish = Fn009cff9a(position, mpFinish, newFinish, Tag_ae3240());
    }
    if (mpStart) {
        Fn0090cf63(mpStart);
    }
    mpFinish = newFinish;
    mpStart = newStart;
    mpEnd = newStart + length;
}
#endif

// NOT ATTEMPTED: 0x009d1031 GZOnMouseDownL. Its double-click detection keeps function-local statics (a click time, the
// last node and rectangle at 0x00bac0a0..0x00bac0b4, with init guards at 0x00bac0d0 and an atexit registration);
// they cannot be written as the original's variables with GLOBAL externs without the guard code.

// NOT ATTEMPTED: 0x009d2577 GZOnMouseMove. The drag start: builds the dragged-selection surface (union of the
// selected nodes' rectangles, a vector of nodes, a surface from the graphics service) and the drag window
// (constructor 0x009cfd89, vtable 0x00ae2c90); 933 bytes with many unidentified callees.
