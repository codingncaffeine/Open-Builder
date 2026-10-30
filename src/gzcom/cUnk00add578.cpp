#include <cstddef>
#include <cstring>
#include <math.h>
#include "gzcom/cIGZUnknown.h"
#include "gzcom/cRZString.h"
#include "classes/cUnk00add578.h"

struct CellData_add578;

// The free-list push of the cell record pool (defined below).
void Fn009a5c20(void** p);
void Fn009a5c9f(void** p);

// A node of the red-black tree the two maps at +0x2a8 and +0x2b4 keep.
struct TreeNode_add578 {
    uint32_t mnColor;
    TreeNode_add578* mpParent;
    TreeNode_add578* mpLeft;
    TreeNode_add578* mpRight;
};

// The tag object the standard-library helpers take.
struct Tag_add578 {
};

// STUB: 0x00893dec
uint32_t Fn00893dec(TreeNode_add578** first, TreeNode_add578** second, Tag_add578& tag);

// An iterator passed by value (a node pointer).
struct NodeIter_add578 {
    TreeNode_add578* mpNode;
    NodeIter_add578(TreeNode_add578* node) : mpNode(node) {}
    NodeIter_add578(const NodeIter_add578& other) : mpNode(other.mpNode) {}
};

// The two ends of a range, returned through a hidden pointer.
struct Range_add578 {
    TreeNode_add578* mpFirst;
    TreeNode_add578* mpSecond;
    Range_add578(TreeNode_add578* first, TreeNode_add578* second) : mpFirst(first), mpSecond(second) {}
};

// The map object: the header node and the node count.
struct Tree_add578 {
    TreeNode_add578* mpHeader;
    uint32_t mnCount;
    // STUB: 0x0066f6f0
    void Erase(TreeNode_add578* node);
    void EraseAll();
    // STUB: 0x0066e2f0
    TreeNode_add578* Fn0066e2f0(uint32_t key);
    // STUB: 0x009a83fa
    TreeNode_add578* Fn009a83fa(uint32_t key);
    // STUB: 0x009ab25c
    void EraseNode(NodeIter_add578 node);
    // STUB: 0x009a90f8
    Range_add578 Fn009a90f8(uint32_t key);
    uint32_t Fn009ab66b(uint32_t key);
    // STUB: 0x009ab57d
    void Fn009ab57d(NodeIter_add578 first, NodeIter_add578 last);
};

// A rectangle of four coordinates.
struct Rect_add578 {
    int32_t mnLeft;
    int32_t mnTop;
    int32_t mnRight;
    int32_t mnBottom;
    void Fn009a5fc4();
};

// The record pools.
// The pool the cell records are taken from.
struct Pool_add578 {
    uint32_t mData[4];
    // STUB: 0x005a6290
    void* Alloc();
};

// GLOBAL: 0x00b17c0c
extern Pool_add578 gB17c0c;

// GLOBAL: 0x00b17bec
extern Pool_add578 gB17bec;

// The cell format record: font, six colours, four flags and the border colour.
struct CellFormat_add578 {
    cIGZUnknown* mpFont;
    uint32_t mnColors[6];
    uint8_t mnWrapping;
    uint8_t mnColumnAlignment;
    uint8_t mnRowAlignment;
    uint8_t mnBorderWidth;
    uint32_t mnBorderColor;
    static void* operator new(size_t)
    {
        return gB17bec.Alloc();
    }
    static void operator delete(void* p)
    {
        Fn009a5c20(static_cast<void**>(p));
    }
    // STUB: 0x009a5bf2
    CellFormat_add578();
};

// The format record of a row or column: the cell format and the size (and its cache).
struct CellFormatExtra_add578 : public CellFormat_add578 {
    int16_t mnSize;
    int16_t mnCachedSize;
    // STUB: 0x009a5c36
    CellFormatExtra_add578();
    // STUB: 0x009a5c4a
    CellFormatExtra_add578(const CellFormat_add578& format);
};

// An empty allocator object the tree constructors take by reference.
struct Alloc_add578 {
};

// The standard-library helpers on tree nodes.
// STUB: 0x0040d4c0
TreeNode_add578* Fn0040d4c0(TreeNode_add578* node);
// STUB: 0x0040d500
TreeNode_add578* Fn0040d500(TreeNode_add578* header);
// STUB: 0x0040daf0
TreeNode_add578* Fn0040daf0(TreeNode_add578* node, TreeNode_add578** root, TreeNode_add578** leftmost, TreeNode_add578** rightmost);
// STUB: 0x0090cf63
void Fn0090cf63(void* p);

struct InsertResult_add578;
struct NodeRef_add578;
struct KeyValue_add578;

// The tree that keeps the cells of one row of the sparse matrix, by column.
struct CellsTree_add578 {
    TreeNode_add578* mpHeader;
    uint32_t mnCount;
    uint32_t mnPad;
    // STUB: 0x009492cb
    TreeNode_add578* Fn009492cb(uint32_t key);
    // STUB: 0x009a83fa
    TreeNode_add578* Fn009a83fa(uint32_t key);
    // STUB: 0x00927cf8
    void EraseNode(NodeIter_add578 node);
    // STUB: 0x009a8908
    void Clear();
    // STUB: 0x009a90ce
    Range_add578 Fn009a90ce(uint32_t key);
    uint32_t Fn009a99c0(uint32_t key);
    // STUB: 0x009a908a
    void Fn009a908a(NodeIter_add578 first, NodeIter_add578 last);
    // STUB: 0x009a8b1c
    NodeRef_add578 Insert(TreeNode_add578* x, TreeNode_add578* y, const KeyValue_add578& v, TreeNode_add578* w);
    // STUB: 0x009a954e
    InsertResult_add578 Fn009a954e(const KeyValue_add578& v);
    // STUB: 0x0094c8f5
    TreeNode_add578* Find(const int32_t& key);
    // STUB: 0x009a8970
    void Fn009a8970();
    // STUB: 0x0087b7a5
    void Init(Alloc_add578& a, Alloc_add578& b);
    // STUB: 0x009aacb8
    CellsTree_add578(const CellsTree_add578& other);
    // STUB: 0x009a9c2f
    CellsTree_add578();
    ~CellsTree_add578();
};

// A row of the matrix: its index and its cells.
struct MatrixRow_add578 {
    int32_t mnIndex;
    CellsTree_add578 mCells;
    MatrixRow_add578(int32_t row) : mnIndex(row) {}
    MatrixRow_add578(const MatrixRow_add578& other);
};

// A row with its key, as the row tree stores it.
struct RowPair_add578 {
    int32_t mnKey;
    MatrixRow_add578 mRow;
    RowPair_add578(int32_t key, const MatrixRow_add578& row) : mnKey(key), mRow(row) {}
    // STUB: 0x009aad36
    void DtorFlag(uint32_t flag);
};

// The row of a format matrix.
struct FmtRow_add578;


// An entry the cell range query fills in.
struct UserCell_add578 {
    int32_t mnColumn;
    int32_t mnRow;
    CellData_add578* mpCell;
};

// A node of the row tree.
struct RowNode_add578 : public TreeNode_add578 {
    int32_t mnKey;
    MatrixRow_add578 mRow;
};

// A node of a row's cell tree.
struct CellNode_add578 : public TreeNode_add578 {
    int32_t mnKey;
    int32_t mnColumn;
    void* mpValue;
};

// The tree that keeps the rows of the sparse matrix, by row.
struct RowsTree_add578 {
    TreeNode_add578* mpHeader;
    uint32_t mnCount;
    uint32_t mnPad;
    // STUB: 0x009aba67
    NodeRef_add578 Insert(TreeNode_add578* x, TreeNode_add578* y, const KeyValue_add578& v, TreeNode_add578* w);
    // STUB: 0x009abc11
    InsertResult_add578 Fn009abc11(const KeyValue_add578& v);
    // STUB: 0x0094c8f5
    TreeNode_add578* Find(const int32_t& key);
    // STUB: 0x009a8947
    void Fn009a8947();
    // STUB: 0x009a9455
    void Init(Alloc_add578& a, Alloc_add578& b);
    void Fn009ab2d3(NodeIter_add578 it);
    // STUB: 0x009aac3a
    RowsTree_add578(const RowsTree_add578& other);
    // STUB: 0x009a9c16
    RowsTree_add578();
    ~RowsTree_add578();
};

// The result of a unique insert: the node and whether it was new.
struct InsertResult_add578 {
    TreeNode_add578* mpNode;
    uint8_t mbInserted;
    InsertResult_add578(TreeNode_add578* node, bool inserted) : mpNode(node), mbInserted(inserted) {}
};

// An iterator the node-inserting worker returns through a hidden pointer.
struct NodeRef_add578 {
    TreeNode_add578* mpNode;
    NodeRef_add578(TreeNode_add578* node) : mpNode(node) {}
};

// A value whose first word is its key.
struct KeyValue_add578 {
    int32_t mnKey;
    KeyValue_add578() {}
    KeyValue_add578(int32_t key) : mnKey(key) {}
};

// A node whose key follows the tree links.
struct KeyNode_add578 : public TreeNode_add578 {
    int32_t mnKey;
};

// Trees of two more shapes that only the unique insert is used on.
struct IntTreeA_add578 {
    TreeNode_add578* mpHeader;
    // STUB: 0x009a8a94
    NodeRef_add578 Insert(TreeNode_add578* x, TreeNode_add578* y, const KeyValue_add578& v, TreeNode_add578* w);
    // STUB: 0x009a94ca
    InsertResult_add578 Fn009a94ca(const KeyValue_add578& v);
};

struct IntTreeB_add578 {
    TreeNode_add578* mpHeader;
    // STUB: 0x009ab9df
    NodeRef_add578 Insert(TreeNode_add578* x, TreeNode_add578* y, const KeyValue_add578& v, TreeNode_add578* w);
    // STUB: 0x009abb8d
    InsertResult_add578 Fn009abb8d(const KeyValue_add578& v);
};

// A row of a format matrix: its index and its cells.
struct FmtRow_add578 {
    int32_t mnIndex;
    RowsTree_add578 mCells;
    FmtRow_add578(int32_t row) : mnIndex(row) {}
    FmtRow_add578(const FmtRow_add578& other);
};

struct FmtPair_add578 {
    int32_t mnKey;
    FmtRow_add578 mRow;
    FmtPair_add578(int32_t key, const FmtRow_add578& row) : mnKey(key), mRow(row) {}
};

// What a format cell holds: its column and the format record.
struct FmtValue_add578 {
    int32_t mnColumn;
    CellFormatExtra_add578 mFormat;
    FmtValue_add578(int32_t column, const CellFormatExtra_add578& format) : mnColumn(column), mFormat(format) {}
};

struct FmtEntry_add578 {
    int32_t mnKey;
    FmtValue_add578 mValue;
    FmtEntry_add578(int32_t key, const FmtValue_add578& value) : mnKey(key), mValue(value) {}
};

// A node of a format matrix cell tree.
struct FmtCellNode_add578 : public TreeNode_add578 {
    int32_t mnKey;
    int32_t mnColumn;
    CellFormatExtra_add578 mFormat;
};

// A position in the matrix: the matrix, a row node and a cell node.
struct MatIter_add578 {
    void* mpMatrix;
    void* mpRow;
    void* mpCell;
    MatIter_add578(void* matrix, void* row, void* cell) : mpMatrix(matrix), mpRow(row), mpCell(cell) {}
    // STUB: 0x009a903e
    MatIter_add578& Fn009a903e();
    // STUB: 0x009a8fec
    MatIter_add578& Fn009a8fec();
    uint32_t Fn0095bc74(const MatIter_add578* other);
};

// The sparse matrix the grid keeps for its column formats, its row formats and its cells (0x24 bytes each).
struct Matrix_add578 {
    RowsTree_add578 mRows;
    uint32_t mnCellCount;
    int32_t mnMinRow;
    int32_t mnMaxRow;
    int32_t mnMinColumn;
    int32_t mnMaxColumn;
    uint32_t mnPad;
    // STUB: 0x009a9bd7
    bool GetCellPtr(int32_t column, int32_t row, void* out);
    // STUB: 0x009ac157
    bool InsertCell(int32_t column, int32_t row, void* value, void* old);
    bool RemoveCell(int32_t column, int32_t row, void* old);
    bool GetMatrixRow(int32_t row, MatrixRow_add578*& out);
    // STUB: 0x009a9280
    int32_t GetCellCountForRange(int32_t column0, int32_t column1, int32_t row0, int32_t row1);
    // STUB: 0x009a92db
    int32_t GetCellRange(int32_t column0, int32_t column1, int32_t row0, int32_t row1, struct UserCell_add578* out);
    // STUB: 0x009ab5ea
    void Fn009ab5ea();
    int32_t GetRowCountForCol(int32_t column);
    int32_t GetColCountForRow(int32_t row);
    bool GetMinMaxUsedColForRow(int32_t row, int32_t& minColumn, int32_t& maxColumn);
    // STUB: 0x009a9ada
    bool GetMinMaxUsedRowForCol(int32_t column, int32_t& minRow, int32_t& maxRow);
    // STUB: 0x009ac02f
    // STUB: 0x009ac02f
    bool Fn009ac02f(int32_t column, int32_t row, const CellFormatExtra_add578& format, void* old);
    // STUB: 0x009a91d4
    int32_t Fn009a91d4(int32_t* other);
    int32_t Fn009a917d(int32_t* other);
    // STUB: 0x009a9225
    int32_t Fn009a9225(int32_t* other);
    int32_t Fn009a91a6(int32_t* other);
    // STUB: 0x009a9122
    MatIter_add578 Fn009a9122(int32_t column);
    // STUB: 0x009a9a09
    MatIter_add578 Fn009a9a09(int32_t row);
    // STUB: 0x009a9a4c
    MatIter_add578 Fn009a9a4c(int32_t row);
    // STUB: 0x009ab716
    bool Fn009ab716(int32_t start, int32_t count);
    bool Fn009ab75e(int32_t start, int32_t count);
    // STUB: 0x009a935d
    MatIter_add578 Fn009a935d();
};

inline void* Ptr_add578(uint32_t word)
{
    return reinterpret_cast<void*>(static_cast<uintptr_t>(word));
}

// A cell position.
struct Coord_add578 {
    int32_t mnColumn;
    int32_t mnRow;
};

// A node of the std::list the selection is kept in (the member is the sentinel node's pointer).
struct ListNode_add578 {
    ListNode_add578* mpNext;
    ListNode_add578* mpPrev;
    int32_t mnColumn;
    int32_t mnRow;
};

struct List_add578 {
    ListNode_add578* mpHead;
    bool IsEmpty() const
    {
        return mpHead->mpNext == mpHead;
    }
    uint32_t Size() const
    {
        uint32_t n = 0;
        for (ListNode_add578* p = mpHead->mpNext; p != mpHead; p = p->mpNext) {
            ++n;
        }
        return n;
    }
    // STUB: 0x009a841f
    void Clear();
    // STUB: 0x0089408d
    void PushBack(const struct Coord_add578& coord);
    // STUB: 0x00949259
    void Erase(struct Tag_add578& tag, struct NodeIter_add578 node);
    // STUB: 0x0093a22b
    void EraseRange(struct Tag_add578& tag, struct NodeIter_add578 first, struct NodeIter_add578 last);
    // STUB: 0x009aabc6
    List_add578& Fn009aabc6(const List_add578& other);
};

// A node of a map from an index to a word.
struct IdNode_add578 : public TreeNode_add578 {
    uint32_t mnKey;
    uint32_t mnValue;
};

// A map from an index to a word (the per-column and per-row extra data).
struct IdMap_add578 {
    TreeNode_add578* mpHeader;
    uint32_t mnCount;
    uint32_t mnPad;
    // STUB: 0x0096a7b0
    uint32_t& Index(const uint32_t& key);
    // STUB: 0x0098129c
    TreeNode_add578* Find(const uint32_t& key);
};

// A 16-byte record copied as a whole.
struct Quad_add578 {
    int32_t v[4];
    // STUB: 0x0043fde0
    bool Contains(int32_t x, int32_t y);
    // STUB: 0x0048ed90
    void Fn0048ed90(const Quad_add578* other);
};

inline void OffsetQuad_add578(Quad_add578* r, int32_t x, int32_t y)
{
    r->v[0] += x;
    r->v[2] += x;
    r->v[1] += y;
    r->v[3] += y;
}

// A grid cell record.
struct CellData_add578 {
    uint32_t mnType;
    int32_t mnColumn;
    int32_t mnRow;
    void* mpData;
    void* mpFormat;
    uint32_t mnExtraData;
    uint32_t mnWindowFlags;
    static void* operator new(size_t)
    {
        return gB17c0c.Alloc();
    }
    static void operator delete(void* p)
    {
        Fn009a5c9f(static_cast<void**>(p));
    }
    CellData_add578()
        : mnType(0), mnColumn(0), mnRow(0), mpData(0), mpFormat(0), mnExtraData(0), mnWindowFlags(0)
    {
    }
    CellData_add578(uint32_t type, int32_t column, int32_t row, void* data, void* format, uint32_t extra);
};

// An iterator passed by value.
struct Iter_add578 {
    void* mpNode;
    Iter_add578(void* node) : mpNode(node) {}
    Iter_add578(const Iter_add578& other) : mpNode(other.mpNode) {}
};

// A container member that forwards to its four-argument worker.
struct Worker_add578 {
    // STUB: 0x009a960e
    uint32_t Fn009a960e(Iter_add578 a, void* b, void* c, Tag_add578& tag);
    uint32_t Fn008940cd(Iter_add578 a, void* b, void* c);
};

// STUB: 0x004696c0
uint32_t Fn004696c0(uint32_t a, uint32_t b, uint32_t c, Tag_add578& tag);

// A map from an index to a string (the per-column and per-row headings).
struct HeadingMap_add578 {
    uint32_t mData[3];
    // STUB: 0x00671f80
    cRZString& Index(const uint32_t& key);
};

// Two iterator-like records that compare equal when both are at their end.
struct IterA_add578 {
    uint32_t mn0;
    uint32_t mn4;
    uint32_t mn8;
    bool Fn009a7577(const IterA_add578& other);
};

struct IterB_add578 {
    uint32_t mn0;
    uint32_t mn4;
    uint32_t mn8;
    bool Fn009a75a3(const IterB_add578& other);
};

// The message the grid sends its owner when the escape key goes up.
struct Msg_add578 {
    int32_t mnType;
    int32_t mnKey;
    uint32_t mnFlags;
    int32_t mnZero;
};

// The grid seen through its own primary vtable with the argument and return types the calls show (the base declares
// some of them differently).
struct cSelf_add578 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void Slot08(void* rect);
    virtual void Slot09(void* rect);
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
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
    virtual bool Slot42(int32_t* column, int32_t* row);
    virtual void D43();
    virtual void D44();
    virtual bool Slot45(uint32_t column, uint32_t row);
    virtual void D46();
    virtual void D47();
    virtual void D48();
    virtual void D49();
    virtual bool Slot50(void* range);
    virtual bool Slot51(void* rect);
    virtual bool Slot52(uint32_t column);
    virtual bool Slot53(uint32_t row);
    virtual bool Slot54(uint32_t column, uint32_t row);
    virtual void D55();
    virtual void D56();
    virtual void D57();
    virtual void D58();
    virtual void D59();
    virtual void D60();
    virtual void D61();
    virtual void D62();
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
    virtual void D74();
    virtual void D75();
    virtual void D76();
    virtual void D77();
    virtual void D78();
    virtual void D79();
    virtual void D80();
    virtual void D81();
    virtual void D82();
    virtual void D83();
    virtual bool Slot84(int32_t column, int32_t row, void* format);
    virtual void D85();
    virtual void D86();
    virtual bool Slot87(uint32_t column, void* out);
    virtual bool Slot88(uint32_t row, void* out);
    virtual void D89();
    virtual void D90();
    virtual void D91();
    virtual void D92();
    virtual void D93();
    virtual void D94();
    virtual void D95();
    virtual void D96();
    virtual void D97();
    virtual void D98();
    virtual void D99();
    virtual void D100();
    virtual void D101();
    virtual void D102();
    virtual void D103();
    virtual bool Slot104(uint32_t column, uint32_t row);
    virtual void D105();
    virtual bool Slot106(uint32_t column, uint32_t row, void* rect);
    virtual void D107();
    virtual void D108();
    virtual void D109();
    virtual bool Slot110(int32_t x, int32_t y, void* result, void* data);
    virtual void D111();
    virtual void D112();
    virtual void D113();
    virtual void D114();
    virtual bool Slot115(uint32_t column, uint32_t row, void* out);
    virtual bool Slot116(int32_t column, int32_t row, void* window, uint32_t a, uint32_t b, uint32_t c);
    virtual bool Slot117(void* window, int32_t a, int32_t b, int32_t c);
    virtual void D118();
    virtual void D119();
    virtual void D120();
    virtual void D121();
    virtual void D122();
    virtual void D123();
    virtual void D124();
    virtual void D125();
    virtual void D126();
    virtual void D127();
    virtual void D128();
    virtual void D129();
    virtual void D130();
    virtual void D131();
    virtual void D132();
    virtual void D133();
    virtual void D134();
    virtual void D135();
    virtual void D136();
    virtual void D137();
    virtual void D138();
    virtual void D139();
};

// The window base seen through its vtable with pointer arguments.
struct cWinView_add578 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void Slot14(void* child);
    virtual void D15();
    virtual void Slot16(void* child);
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
    virtual bool Slot45(uint32_t column, uint32_t row);
    virtual void D46();
    virtual void D47();
    virtual void D48();
    virtual void D49();
    virtual void D50();
    virtual void D51();
    virtual void D52();
    virtual void D53();
    virtual void D54();
    virtual void D55();
    virtual void D56();
    virtual void D57();
    virtual void D58();
    virtual void D59();
    virtual void D60();
    virtual bool Slot61(void* window, int32_t* x, int32_t* y);
    virtual void D62();
    virtual void D63();
    virtual void D64();
    virtual void D65();
    virtual void D66();
    virtual bool Slot67(uint32_t flag);
    virtual void D68();
    virtual void D69();
    virtual void D70();
    virtual void D71();
    virtual void D72();
    virtual void D73();
    virtual void D74();
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
    virtual void D90();
    virtual void D91();
    virtual void D92();
    virtual void D93();
    virtual void D94();
    virtual void D95();
    virtual void D96();
    virtual void D97();
    virtual void D98();
    virtual void D99();
    virtual void D100();
    virtual void D101();
    virtual void D102();
    virtual void D103();
    virtual void D104();
    virtual void D105();
    virtual bool Slot106(uint32_t column, uint32_t row, void* rect);
    virtual void D107();
    virtual void D108();
    virtual void D109();
    virtual void D110();
    virtual void D111();
    virtual void D112();
    virtual void D113();
    virtual void D114();
    virtual bool Slot115(uint32_t column, uint32_t row, void* out);
    virtual void D116();
    virtual void D117();
    virtual void D118();
    virtual void D119();
    virtual void D120();
    virtual bool Slot121(int32_t x, int32_t y);
    virtual void D122();
    virtual void D123();
    virtual void D124();
    virtual void D125();
    virtual void D126();
    virtual void D127();
    virtual void D128();
    virtual void D129();
    virtual void D130();
    virtual void D131();
    virtual void D132();
    virtual void D133();
    virtual void D134();
    virtual void D135();
    virtual void D136();
    virtual void D137();
    virtual void D138();
    virtual void D139();
    virtual void D140();
    virtual void D141();
    virtual void D142();
    virtual void D143();
    virtual void D144();
    virtual bool SendMsg_2(uint32_t target, void* message);
    virtual void D146();
    virtual void D147();
    virtual void D148();
    virtual void D149();
    virtual void D150();
};

// A scroll bar object: its window.
struct WinObj_add578;
struct ScrollBar_add578 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual WinObj_add578* Slot03();
    virtual void D4();
    virtual void Slot05(int32_t position);
    virtual int32_t Slot06();
    virtual void Slot07(int32_t minimum, int32_t maximum);
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void Slot15(int32_t page, int32_t total);
    virtual void D16();
    virtual void Slot17(void* source, void* image, uint32_t flag);
};

// The image object of a scroll bar: slot 12 gives its source.
struct Image_add578 {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual int32_t Slot10();
    virtual void Slot11(void* rect);
    virtual void* Slot12();
};

// The record the scroll images are looked up in.
struct Embedded_add578 {
    uint32_t mData[4];
    // STUB: 0x007c1870
    bool Fn007c1870();
};

// The message the window gets.
struct Message_add578 {
    uint32_t mnType;
    uint32_t mnId;
    uint32_t mnSub;
};

// A window object as the grid calls it: its id and its flag setter.
struct WinObj_add578 {
    virtual void D0();
    virtual uint32_t Slot01();
    virtual void D2();
    virtual bool Slot03(void* message);
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void Slot24();
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
    virtual uint32_t Slot41();
    virtual uint32_t Slot42();
    virtual void D43();
    virtual void D44();
    virtual bool Slot45(uint32_t column, uint32_t row);
    virtual void D46();
    virtual void D47();
    virtual void D48();
    virtual void D49();
    virtual void D50();
    virtual void Slot51(int32_t width);
    virtual void Slot52(int32_t height);
    virtual void D53();
    virtual void D54();
    virtual void Slot55(int32_t l, int32_t t, int32_t r, int32_t bt);
    virtual void Slot56(int32_t x, int32_t y);
    virtual void D57();
    virtual void D58();
    virtual void D59();
    virtual void D60();
    virtual void D61();
    virtual void D62();
    virtual uint32_t Slot63();
    virtual void D64();
    virtual void D65();
    virtual void D66();
    virtual void D67();
    virtual uint32_t Slot68(uint32_t flag, uint32_t value);
    virtual void Slot69();
    virtual void Slot70();
};

// The window base: the one non-virtual method the grid calls.
struct Win_add578 {
    // STUB: 0x0099bc31
    bool Fn0099bc31();
    // STUB: 0x0099be0a
    bool Fn0099be0a();
    // STUB: 0x0099bdfe
    bool Fn0099bdfe();
    // STUB: 0x0099be1e
    void Fn0099be1e();
};

// A service object whose slot 7 gives a number.
struct Service_add578 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual uint32_t Slot07();
};

inline Win_add578* WinOf_add578(cUnk00add578* p)
{
    return reinterpret_cast<Win_add578*>(reinterpret_cast<char*>(p) + 4);
}

// STUB: 0x00913d7a
Service_add578* Fn00913d7a();

// A node of the cell-window map.
struct WinNode_add578 : public TreeNode_add578 {
    uint32_t mnType;
    int32_t mnColumn;
    int32_t mnRow;
    WinObj_add578* mpWindow;
};

struct WinMap_add578 {
    TreeNode_add578* mpHeader;
    uint32_t mnCount;
    // STUB: 0x009a93a1
    InsertResult_add578 Fn009a93a1(const CellData_add578& value);
    // STUB: 0x009a999d
    InsertResult_add578 Fn009a999d(const CellData_add578& value);
};


// The heads of the free lists of the two record pools.
// GLOBAL: 0x00b17bf8
extern void* gpB17bf8;
// GLOBAL: 0x00b17c18
extern void* gpB17c18;

inline uint32_t& RefOf_add578(cUnk00add578* p)
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(p) + 0x10);
}

// FUNCTION: 0x009a5c20
void Fn009a5c20(void** p)
{
    if (p) {
        *p = gpB17bf8;
        gpB17bf8 = p;
    }
}

// FUNCTION: 0x009a5c9f
void Fn009a5c9f(void** p)
{
    if (p) {
        *p = gpB17c18;
        gpB17c18 = p;
    }
}

// The map code was compiled for speed (the game folder), unlike the rest of this file.
#ifdef _MSC_VER
#pragma optimize("s", off)
#pragma optimize("t", on)
#endif
// FUNCTION: 0x0066f8a0
void Tree_add578::EraseAll()
{
    if (mnCount != 0) {
        Erase(mpHeader->mpParent);
        mpHeader->mpLeft = mpHeader;
        mpHeader->mpParent = 0;
        mpHeader->mpRight = mpHeader;
        mnCount = 0;
    }
}
#ifdef _MSC_VER
#pragma optimize("", on)
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a5c36 score 10
CellFormatExtra_add578::CellFormatExtra_add578()
{
    mnSize = -1;
    mnCachedSize = -1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a5c4a score 14
CellFormatExtra_add578::CellFormatExtra_add578(const CellFormat_add578& format)
{
    mnSize = -1;
    mnCachedSize = -1;
    *static_cast<CellFormat_add578*>(this) = format;
}
#endif

// FUNCTION: 0x009a5fc4
void Rect_add578::Fn009a5fc4()
{
    if (mnLeft > mnRight) {
        int32_t t = mnLeft;
        mnLeft = mnRight;
        mnRight = t;
    }
    if (mnTop > mnBottom) {
        int32_t t = mnTop;
        mnTop = mnBottom;
        mnBottom = t;
    }
}

// FUNCTION: 0x009a5faa
void cUnk00add578::Fn009a5faa()
{
    if (!mbInvalidated) {
        mbInvalidated = 1;
        InvalidateSelfAndParents();
    }
}

// FUNCTION: 0x009a5f23
bool cUnk00add578::Fn009a5f23(bool negate)
{
    return Slot31_add348(static_cast<int32_t>(negate ? -mfVisibleRows : mfVisibleRows));
}

// FUNCTION: 0x009a5f48
bool cUnk00add578::Fn009a5f48(bool negate)
{
    return Slot32_add348(static_cast<int32_t>(negate ? -mfVisibleColumns : mfVisibleColumns));
}

// FUNCTION: 0x009a5f70
bool cUnk00add578::Slot139_add348()
{
    Slot10_add348(0x40000);
    return true;
}

// FUNCTION: 0x009a5f7d
bool cUnk00add578::GZOnMouseWheel(uint32_t /*a*/, uint32_t /*b*/, uint32_t /*c*/, uint32_t d)
{
    Slot31_add348(static_cast<int32_t>(d) / -100);
    return true;
}

// FUNCTION: 0x009a5f99
bool cUnk00add578::Slot140_add578(void* out)
{
    *reinterpret_cast<void**>(out) = mCells;
    return true;
}

// FUNCTION: 0x009a62bc
uint32_t cUnk00add578::Slot13_add348(uint32_t mask)
{
    return (mnFlags & mask) != 0;
}

// FUNCTION: 0x009a63b4
void cUnk00add578::Slot22_add348()
{
    Slot13_add348(0x800);
}

// FUNCTION: 0x009a64b3
uint32_t cUnk00add578::Slot29_add348(uint32_t up)
{
    if (static_cast<uint8_t>(up)) {
        ++mnPauseCount;
    } else {
        --mnPauseCount;
    }
    return mnPauseCount;
}

// FUNCTION: 0x009a64cb
void cUnk00add578::Slot33_add348(uint32_t pages)
{
    Slot31_add348(pages << 2);
}

// FUNCTION: 0x009a64db
void cUnk00add578::Slot34_add348(uint32_t pages)
{
    Slot32_add348(pages << 2);
}

// FUNCTION: 0x009a679d
bool cUnk00add578::Slot56_add348(uint32_t color)
{
    Slot08_ae1a28(color);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a6d2d score 8
void cUnk00add578::Slot125_add348(uint32_t object)
{
    mn188 = 1;
    mpExtra = static_cast<cIGZUnknown*>(Ptr_add578(object));
}
#endif

// FUNCTION: 0x009a6e0f
bool cUnk00add578::Slot129_add348(uint32_t iid, uint32_t ppv)
{
    cIGZUnknown* extra = mpExtra;
    if (extra) {
        return extra->QueryInterface(iid, static_cast<void**>(Ptr_add578(ppv)));
    }
    return false;
}

// FUNCTION: 0x009a7650
unsigned int cUnk00add578::Release()
{
    uint32_t n = RefOf_add578(this);
    if (n > 1) {
        n = n - 1;
        RefOf_add578(this) = n;
        return n;
    }
    Fn009a5cd7();
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a96fd score 8
void cUnk00add578::Slot40_add348()
{
}
#endif

// FUNCTION: 0x009ab87b
bool cUnk00add578::Slot82_add348()
{
    reinterpret_cast<Tree_add578*>(mRowHeadings)->EraseAll();
    return true;
}

// FUNCTION: 0x009ab889
bool cUnk00add578::Slot83_add348()
{
    reinterpret_cast<Tree_add578*>(mColumnHeadings)->EraseAll();
    return true;
}

// FUNCTION: 0x009afccb
bool cUnk00add578::Slot06_add348()
{
    RecalculateAll();
    mbE4 = 1;
    return true;
}

// FUNCTION: 0x009a9427
RowsTree_add578::~RowsTree_add578()
{
    Fn009a8947();
    if (mpHeader) {
        Fn0090cf63(mpHeader);
    }
}

// FUNCTION: 0x009a943e
CellsTree_add578::~CellsTree_add578()
{
    Fn009a8970();
    if (mpHeader) {
        Fn0090cf63(mpHeader);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a9c16 score 1
RowsTree_add578::RowsTree_add578()
{
    Alloc_add578 a;
    Init(a, a);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a9c2f score 1
CellsTree_add578::CellsTree_add578()
{
    Alloc_add578 a;
    Init(a, a);
}
#endif

// FUNCTION: 0x009aa7e3
void cUnk00add578::Slot87_add348(uint32_t column, uint32_t out)
{
    reinterpret_cast<Matrix_add578*>(mColumnFormats)->GetCellPtr(column, 0, Ptr_add578(out));
}

// FUNCTION: 0x009aa7fb
void cUnk00add578::Slot88_add348(uint32_t row, uint32_t out)
{
    reinterpret_cast<Matrix_add578*>(mRowFormats)->GetCellPtr(0, row, Ptr_add578(out));
}

// FUNCTION: 0x009a667e
bool cUnk00add578::Slot48_add348(uint32_t columns, uint32_t rows)
{
    mnMaxColumns = columns;
    mnMaxRows = rows;
    return true;
}

// FUNCTION: 0x009a6284
void cUnk00add578::Slot10_add348(uint32_t flag)
{
    uint32_t flags = mnFlags;
    if (!(flag & flags)) {
        Slot11_add348(flags | flag);
    }
}

// FUNCTION: 0x009a629f
void cUnk00add578::Slot12_add348(uint32_t flag)
{
    uint32_t flags = mnFlags;
    if (flag & flags) {
        Slot11_add348(~flag & flags);
    }
}

// FUNCTION: 0x009a633a
bool cUnk00add578::Slot17_add348(uint32_t color, uint32_t index)
{
    if (index < 6) {
        mnDefaultColors[index] = color;
        return true;
    }
    return false;
}

// FUNCTION: 0x009a65fb
bool cUnk00add578::Slot38_add348(uint32_t a, uint32_t b)
{
    *static_cast<int32_t*>(Ptr_add578(a)) = mnSelectionRuleA;
    *static_cast<int32_t*>(Ptr_add578(b)) = mnSelectionRuleB;
    return true;
}

// FUNCTION: 0x009a6697
bool cUnk00add578::Slot49_add348(uint32_t columns, uint32_t rows)
{
    *static_cast<int32_t*>(Ptr_add578(columns)) = mnMaxColumns;
    *static_cast<int32_t*>(Ptr_add578(rows)) = mnMaxRows;
    return true;
}

// FUNCTION: 0x009a69b7
bool cUnk00add578::Slot75_add348(uint32_t a, uint32_t b)
{
    *static_cast<int32_t*>(Ptr_add578(a)) = mnHeaderSizeA;
    *static_cast<int32_t*>(Ptr_add578(b)) = mnHeaderSizeB;
    return true;
}

// FUNCTION: 0x009a6ba5
bool cUnk00add578::Slot107_add348(uint32_t column, uint32_t row)
{
    *static_cast<int32_t*>(Ptr_add578(column)) = mnFirstColumn;
    *static_cast<int32_t*>(Ptr_add578(row)) = mnFirstRow;
    return true;
}

// FUNCTION: 0x009a6bf7
bool cUnk00add578::Slot109_add348(uint32_t columns, uint32_t rows)
{
    *static_cast<float*>(Ptr_add578(columns)) = mfVisibleColumns;
    *static_cast<float*>(Ptr_add578(rows)) = mfVisibleRows;
    return true;
}

// FUNCTION: 0x009a6ebd
bool cUnk00add578::Slot135_add348(uint32_t buffer, uint32_t area)
{
    const char* base = reinterpret_cast<const char*>(this);
    *static_cast<uint32_t*>(Ptr_add578(buffer)) = *reinterpret_cast<const uint32_t*>(base + 0x6c);
    *static_cast<Quad_add578*>(Ptr_add578(area)) = *reinterpret_cast<const Quad_add578*>(base + 0x28);
    return true;
}

// FUNCTION: 0x009a6eda
bool cUnk00add578::Slot138_add348(uint32_t index, uint32_t id)
{
    int32_t i = static_cast<int32_t>(index);
    if (i < 3) {
        mnSoundIds[i] = id;
        return true;
    }
    return false;
}

// FUNCTION: 0x0095bc74
uint32_t MatIter_add578::Fn0095bc74(const MatIter_add578* other)
{
    if (mpRow == other->mpRow) {
        if (mpCell == other->mpCell) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x009ab1dc
uint32_t cUnk00add578::Slot122_add348(uint32_t column)
{
    uint32_t key = column;
    return reinterpret_cast<IdMap_add578*>(mColumnExtra)->Index(key);
}

// FUNCTION: 0x009ab23e
uint32_t cUnk00add578::Slot124_add348(uint32_t row)
{
    uint32_t key = row;
    return reinterpret_cast<IdMap_add578*>(mRowExtra)->Index(key);
}

// FUNCTION: 0x009a6357
bool cUnk00add578::Slot18_add348(uint32_t out, uint32_t index)
{
    if (index < 6) {
        *static_cast<uint32_t*>(Ptr_add578(out)) = mnDefaultColors[index];
        return true;
    }
    return false;
}

// FUNCTION: 0x009a8869
bool cUnk00add578::Slot46_add348()
{
    List_add578* list = reinterpret_cast<List_add578*>(&mpSelection);
    if (!list->IsEmpty()) {
        list->Clear();
        Fn009a5faa();
    }
    return true;
}

// FUNCTION: 0x009a62cf
void cUnk00add578::Slot08_ae1a28(uint32_t a)
{
    cGZWin::Slot08_ae1a28(a);
    if (mnFlags & 0x100) {
        Fn009a5faa();
    }
}

// FUNCTION: 0x009a6618
bool cUnk00add578::Slot39_add348(uint32_t a, uint32_t b)
{
    mnSelectionRuleA = a;
    mnSelectionRuleB = b;
    Slot46_add348();
    return true;
}

// FUNCTION: 0x009a65d8
bool cUnk00add578::Slot37_add348(uint32_t column, uint32_t row)
{
    Slot35_add348(column);
    Slot36_add348(row);
    return true;
}

// FUNCTION: 0x009a7e0c
bool cUnk00add578::GZOnSetFocus(uint32_t a)
{
    if (mnFlags & 1) {
        Fn009a5faa();
    }
    return cGZWin::GZOnSetFocus(a);
}

// FUNCTION: 0x009a7e2f
bool cUnk00add578::GZOnKillFocus(uint32_t a)
{
    if (mnFlags & 1) {
        Fn009a5faa();
    }
    return cGZWin::GZOnKillFocus(a);
}

// FUNCTION: 0x009a648f
void cUnk00add578::Slot27_add348(uint32_t enable, uint32_t color)
{
    if (static_cast<uint8_t>(enable)) {
        mnFlags |= 0x200;
    } else {
        mnFlags &= ~0x200;
    }
    mnOutlineColor = color;
}

// The standard-library code was compiled for speed (the game folder), unlike the rest of this file.
#ifdef _MSC_VER
#pragma optimize("s", off)
#pragma optimize("t", on)
#endif
// FUNCTION: 0x008bc520
uint32_t Fn008bc520(uint32_t a, uint32_t b, uint32_t c)
{
    Tag_add578 tag;
    return Fn004696c0(a, b, c, tag);
}
#ifdef _MSC_VER
#pragma optimize("", on)
#endif

// FUNCTION: 0x008940cd
uint32_t Worker_add578::Fn008940cd(Iter_add578 a, void* b, void* c)
{
    Tag_add578 tag;
    return Fn009a960e(a, b, c, tag);
}

// FUNCTION: 0x009a6778
bool cUnk00add578::Slot55_add348(uint32_t column, uint32_t row)
{
    *static_cast<int32_t*>(Ptr_add578(column)) = mnLastColumn;
    *static_cast<int32_t*>(Ptr_add578(row)) = mnLastRow;
    return *static_cast<int32_t*>(Ptr_add578(column)) != -1;
}

// FUNCTION: 0x009a69d4
bool cUnk00add578::Slot76_add348(uint32_t a, uint32_t b)
{
    mnHeaderSizeA = a;
    mnHeaderSizeB = b;
    mbE4 = 1;
    Fn009a5faa();
    return true;
}

// FUNCTION: 0x009a66fc
uint32_t cUnk00add578::Slot52_add348(uint32_t column)
{
    int32_t max = mnMaxColumns;
    if (max != 0 && max != -1) {
        if (static_cast<int32_t>(column) < 0 || static_cast<int32_t>(column) >= max) {
            return 0;
        }
    }
    return 1;
}

// FUNCTION: 0x009a6722
uint32_t cUnk00add578::Slot53_add348(uint32_t row)
{
    int32_t max = mnMaxRows;
    if (max != 0 && max != -1) {
        if (static_cast<int32_t>(row) < 0 || static_cast<int32_t>(row) >= max) {
            return 0;
        }
    }
    return 1;
}

// FUNCTION: 0x009ad95e
bool cUnk00add578::Slot81_add348(uint32_t row, uint32_t text)
{
    uint32_t key = row;
    cIGZString& heading = reinterpret_cast<HeadingMap_add578*>(mRowHeadings)->Index(key);
    heading = *static_cast<const cIGZString*>(Ptr_add578(text));
    return true;
}

// FUNCTION: 0x009ad9b3
bool cUnk00add578::Slot79_add348(uint32_t column, uint32_t text)
{
    uint32_t key = column;
    cIGZString& heading = reinterpret_cast<HeadingMap_add578*>(mColumnHeadings)->Index(key);
    heading = *static_cast<const cIGZString*>(Ptr_add578(text));
    return true;
}

// FUNCTION: 0x009ad931
bool cUnk00add578::Slot80_add348(uint32_t row, uint32_t out)
{
    cIGZString* dest = static_cast<cIGZString*>(Ptr_add578(out));
    uint32_t key = row;
    *dest = reinterpret_cast<HeadingMap_add578*>(mRowHeadings)->Index(key);
    return true;
}

// FUNCTION: 0x009ad986
bool cUnk00add578::Slot78_add348(uint32_t column, uint32_t out)
{
    cIGZString* dest = static_cast<cIGZString*>(Ptr_add578(out));
    uint32_t key = column;
    *dest = reinterpret_cast<HeadingMap_add578*>(mColumnHeadings)->Index(key);
    return true;
}

// FUNCTION: 0x009ae35c
uint32_t cUnk00add578::Slot70_add348(uint32_t column, uint32_t count)
{
    int32_t total = 0;
    for (; static_cast<int32_t>(count) > 0; count--) {
        total += GetColumnWidthInternal(column);
        column++;
    }
    return total;
}

// FUNCTION: 0x009af0f6
uint32_t cUnk00add578::Slot71_add348(uint32_t row, uint32_t count)
{
    int32_t total = 0;
    for (; static_cast<int32_t>(count) > 0; count--) {
        total += GetRowHeightInternal(row);
        row++;
    }
    return total;
}

// FUNCTION: 0x009a7577
bool IterA_add578::Fn009a7577(const IterA_add578& other)
{
    if (mn8 == 0 && other.mn8 == 0) {
        return true;
    }
    return mn4 == other.mn4 && mn8 == other.mn8;
}

// FUNCTION: 0x009a75a3
bool IterB_add578::Fn009a75a3(const IterB_add578& other)
{
    if (mn4 == 0 && other.mn4 == 0) {
        return true;
    }
    return mn4 == other.mn4 && mn8 == other.mn8;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a90ce score 2
Range_add578 CellsTree_add578::Fn009a90ce(uint32_t key)
{
    return Range_add578(Fn009492cb(key), Fn009a83fa(key));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a90f8 score 2
Range_add578 Tree_add578::Fn009a90f8(uint32_t key)
{
    return Range_add578(Fn0066e2f0(key), Fn009a83fa(key));
}
#endif

// FUNCTION: 0x009a6462
bool cUnk00add578::Slot26_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    mnCellGutters[0] = a;
    mnCellGutters[1] = b;
    mnCellGutters[2] = c;
    mnCellGutters[3] = d;
    return true;
}

// FUNCTION: 0x009a67b1
bool cUnk00add578::Slot57_add348(uint32_t bitmap)
{
    cIGZUnknown* object = static_cast<cIGZUnknown*>(Ptr_add578(bitmap));
    if (object) {
        object->AddRef();
    }
    if (mpBackgroundBitmap) {
        mpBackgroundBitmap->Release();
    }
    mpBackgroundBitmap = object;
    return true;
}

// FUNCTION: 0x009a6e90
bool cUnk00add578::Slot134_add348(uint32_t notify)
{
    cIGZUnknown* object = static_cast<cIGZUnknown*>(Ptr_add578(notify));
    if (object) {
        object->AddRef();
    }
    if (mpOwnerDrawNotify) {
        mpOwnerDrawNotify->Release();
    }
    mpOwnerDrawNotify = object;
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a87dc score 14
bool cUnk00add578::Slot42_add348(uint32_t column, uint32_t row)
{
    List_add578* list = reinterpret_cast<List_add578*>(&mpSelection);
    if (!list->IsEmpty()) {
        *static_cast<int32_t*>(Ptr_add578(column)) = list->mpHead->mpNext->mnColumn;
        *static_cast<int32_t*>(Ptr_add578(row)) = list->mpHead->mpNext->mnRow;
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x009a5c6f
CellData_add578::CellData_add578(uint32_t type, int32_t column, int32_t row, void* data, void* format, uint32_t extra)
{
    mnWindowFlags = 0;
    mnType = type;
    mnColumn = column;
    mnRow = row;
    mpData = data;
    mpFormat = format;
    mnExtraData = extra;
}

// FUNCTION: 0x009a6748
uint32_t cUnk00add578::Slot54_add348(uint32_t column, uint32_t row)
{
    cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
    if (self->Slot52(column)) {
        if (self->Slot53(row)) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x009aaad1
uint32_t cUnk00add578::Slot120_add348(uint32_t column, uint32_t row)
{
    CellData_add578** cell;
    if (reinterpret_cast<Matrix_add578*>(mCells)->GetCellPtr(column, row, &cell) && *cell) {
        return (*cell)->mnExtraData;
    }
    return 0;
}

// FUNCTION: 0x009a6986
bool cUnk00add578::Slot74_add348(uint32_t headers, uint32_t scrollBars)
{
    if (static_cast<uint8_t>(headers)) {
        Slot10_add348(8);
    } else {
        Slot12_add348(8);
    }
    if (static_cast<uint8_t>(scrollBars)) {
        Slot10_add348(0x10);
    } else {
        Slot12_add348(0x10);
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a6c14 score 4
void cUnk00add578::Slot89_add348(uint32_t column, uint32_t row, uint32_t out)
{
    cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
    if (self->Slot87(column, Ptr_add578(out))) {
        return;
    }
    self->Slot88(row, Ptr_add578(out));
}
#endif

// FUNCTION: 0x009aa59c
bool cUnk00add578::Slot95_add348(uint32_t column, uint32_t row, uint32_t out)
{
    CellData_add578** cell;
    if (reinterpret_cast<Matrix_add578*>(mCells)->GetCellPtr(column, row, &cell)) {
        *static_cast<uint32_t*>(Ptr_add578(out)) = (*cell)->mnType;
        return true;
    }
    return false;
}

// FUNCTION: 0x009a63bf
bool cUnk00add578::Slot23_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *static_cast<int32_t*>(Ptr_add578(a)) = mnGutters[0];
    *static_cast<int32_t*>(Ptr_add578(b)) = mnGutters[1];
    *static_cast<int32_t*>(Ptr_add578(c)) = mnGutters[2];
    *static_cast<int32_t*>(Ptr_add578(d)) = mnGutters[3];
    return true;
}

// FUNCTION: 0x009a642d
bool cUnk00add578::Slot25_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    *static_cast<int32_t*>(Ptr_add578(a)) = mnCellGutters[0];
    *static_cast<int32_t*>(Ptr_add578(b)) = mnCellGutters[1];
    *static_cast<int32_t*>(Ptr_add578(c)) = mnCellGutters[2];
    *static_cast<int32_t*>(Ptr_add578(d)) = mnCellGutters[3];
    return true;
}

// FUNCTION: 0x009a63f4
bool cUnk00add578::Slot24_add348(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    mnGutters[0] = a;
    mnGutters[1] = b;
    mnGutters[2] = c;
    mnGutters[3] = d;
    mbE4 = 1;
    Fn009a5faa();
    return true;
}

// FUNCTION: 0x009a6bc2
bool cUnk00add578::Slot108_add348(uint32_t column, uint32_t row)
{
    if (mnFirstColumn != static_cast<int32_t>(column) || mnFirstRow != static_cast<int32_t>(row)) {
        mnFirstColumn = column;
        mnFirstRow = row;
        mbE4 = 1;
        Fn009a5faa();
    }
    return true;
}

// FUNCTION: 0x009a67de
bool cUnk00add578::Slot58_add348(uint32_t a, uint32_t b)
{
    mnGridColorA = ConvertNativeToPackedRGB(a);
    mnGridColorB = ConvertNativeToPackedRGB(b);
    return true;
}

// FUNCTION: 0x009a6e22
bool cUnk00add578::Slot130_add348(uint32_t object)
{
    cIGZUnknown* p = static_cast<cIGZUnknown*>(Ptr_add578(object));
    mn188 = 2;
    if (p) {
        p->AddRef();
    }
    if (mpExtra) {
        mpExtra->Release();
    }
    mpExtra = p;
    return true;
}

// FUNCTION: 0x009aa8aa
bool cUnk00add578::Slot113_add348(uint32_t column, uint32_t row, uint32_t out)
{
    CellData_add578** cell;
    if (reinterpret_cast<Matrix_add578*>(mCells)->GetCellPtr(column, row, &cell) && (*cell)->mnType == 4) {
        *static_cast<void**>(Ptr_add578(out)) = (*cell)->mpData;
        return true;
    }
    return false;
}

// FUNCTION: 0x009aa8e2
bool cUnk00add578::Slot115_add348(uint32_t column, uint32_t row, uint32_t out)
{
    CellData_add578** cell;
    if (reinterpret_cast<Matrix_add578*>(mCells)->GetCellPtr(column, row, &cell) && (*cell)->mnType == 1) {
        *static_cast<void**>(Ptr_add578(out)) = (*cell)->mpData;
        return true;
    }
    return false;
}

// FUNCTION: 0x009a77ed
bool cUnk00add578::GZOnKeyUp(uint32_t key, uint32_t flags)
{
    if (key == 0x1b) {
        Msg_add578 message;
        message.mnZero = 0;
        message.mnKey = 0x1b;
        message.mnFlags = flags;
        message.mnType = 6;
        return reinterpret_cast<cWinView_add578*>(reinterpret_cast<char*>(this) + 4)->SendMsg_2(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) + 0x50), &message);
    }
    return true;
}

// FUNCTION: 0x009a6d4a
bool cUnk00add578::Slot127_add348(uint32_t column, uint32_t row, uint32_t iid, uint32_t ppv)
{
    mn188 = 1;
    cIGZUnknown* object = static_cast<cIGZUnknown*>(Ptr_add578(Slot120_add348(column, row)));
    mn188 = 2;
    if (object) {
        return object->QueryInterface(iid, static_cast<void**>(Ptr_add578(ppv)));
    }
    return false;
}

// FUNCTION: 0x009a6376
bool cUnk00add578::Slot21_add348(uint32_t wrap)
{
    if (static_cast<uint8_t>(wrap) != static_cast<uint8_t>(Slot13_add348(0x800))) {
        if (static_cast<uint8_t>(wrap)) {
            Slot10_add348(0x800);
        } else {
            Slot12_add348(0x800);
        }
        mbE4 = 1;
        Fn009a5faa();
    }
    return true;
}

// FUNCTION: 0x005f8ac0
void cUnk00add578::Slot59_add348(uint32_t a, uint32_t b)
{
    *static_cast<uint32_t*>(Ptr_add578(a)) = mnGridColorA;
    *static_cast<uint32_t*>(Ptr_add578(b)) = mnGridColorB;
}

// FUNCTION: 0x009a69f9
bool cUnk00add578::Slot77_add348(uint32_t format)
{
    CellFormat_add578* source = static_cast<CellFormat_add578*>(Ptr_add578(format));
    if (source->mpFont) {
        source->mpFont->AddRef();
    }
    CellFormat_add578* heading = reinterpret_cast<CellFormat_add578*>(&mpHeadingFont);
    if (heading->mpFont) {
        heading->mpFont->Release();
    }
    *heading = *source;
    mbE4 = 1;
    Fn009a5faa();
    return true;
}

// FUNCTION: 0x009a62f0
void cUnk00add578::Slot15_add348(uint32_t font)
{
    cIGZUnknown* object = static_cast<cIGZUnknown*>(Ptr_add578(font));
    if (object != mpDefaultFont) {
        if (object) {
            object->AddRef();
        }
        if (mpDefaultFont) {
            mpDefaultFont->Release();
        }
        mpDefaultFont = object;
        mbE4 = 1;
        Fn009a5faa();
    }
}

// FUNCTION: 0x009ab198
bool cUnk00add578::Slot121_add348(uint32_t column, uint32_t data)
{
    mn188 = 1;
    if (reinterpret_cast<cSelf_add578*>(this)->Slot52(column)) {
        uint32_t key = column;
        reinterpret_cast<IdMap_add578*>(mColumnExtra)->Index(key) = data;
        return true;
    }
    return false;
}

// FUNCTION: 0x009ab1fa
bool cUnk00add578::Slot123_add348(uint32_t row, uint32_t data)
{
    mn188 = 1;
    if (reinterpret_cast<cSelf_add578*>(this)->Slot53(row)) {
        uint32_t key = row;
        reinterpret_cast<IdMap_add578*>(mRowExtra)->Index(key) = data;
        return true;
    }
    return false;
}

// FUNCTION: 0x009a6639
bool cUnk00add578::Slot47_add348(uint32_t fixedColumns, uint32_t fixedRows)
{
    if (static_cast<uint8_t>(fixedColumns)) {
        Slot10_add348(0x2000);
    } else {
        Slot12_add348(0x2000);
        mnMaxColumns = -1;
    }
    if (static_cast<uint8_t>(fixedRows)) {
        Slot10_add348(0x4000);
    } else {
        Slot12_add348(0x4000);
        mnMaxRows = -1;
    }
    return true;
}

// FUNCTION: 0x009af121
bool cUnk00add578::Slot03_ae1d24()
{
    Win_add578* win = reinterpret_cast<Win_add578*>(reinterpret_cast<char*>(this) + 4);
    if (!win->Fn0099bc31()) {
        cGZWin::Slot03_ae1d24();
        Service_add578* service = Fn00913d7a();
        mnE0 = service ? service->Slot07() : 1;
        SetDefaultFormatting();
        RecalculateAll();
    }
    return true;
}

// FUNCTION: 0x009a66b4
bool cUnk00add578::Slot51_add348(uint32_t out)
{
    int32_t* r = static_cast<int32_t*>(Ptr_add578(out));
    r[0] = mnFirstColumn;
    r[1] = mnFirstRow;
    r[2] = static_cast<int32_t>(mfVisibleColumns) + mnFirstColumn;
    r[3] = static_cast<int32_t>(mfVisibleRows) + mnFirstRow;
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a9711 score 18
bool cUnk00add578::Slot41_add348(uint32_t cells, uint32_t countPtr)
{
    List_add578* list = reinterpret_cast<List_add578*>(&mpSelection);
    int32_t n = list->Size();
    int32_t* count = static_cast<int32_t*>(Ptr_add578(countPtr));
    if (*count > n) {
        *count = n;
    }
    int32_t* out = static_cast<int32_t*>(Ptr_add578(cells));
    if (out) {
        ListNode_add578* node = list->mpHead->mpNext;
        for (uint32_t i = 0; i < static_cast<uint32_t>(*count); i++) {
            out[0] = node->mnColumn;
            out[1] = node->mnRow;
            node = node->mpNext;
            out += 2;
        }
    }
    return true;
}
#endif

// FUNCTION: 0x009a6b50
uint32_t cUnk00add578::Slot104_add348(uint32_t column, uint32_t row)
{
    int32_t firstColumn = mnFirstColumn;
    if (static_cast<int32_t>(column) >= firstColumn && static_cast<float>(static_cast<int32_t>(column)) < firstColumn + mfVisibleColumns) {
        int32_t firstRow = mnFirstRow;
        if (static_cast<int32_t>(row) >= firstRow && static_cast<float>(static_cast<int32_t>(row)) < firstRow + mfVisibleRows) {
            return 1;
        }
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a76da score 3
void cUnk00add578::Slot08_add348(uint32_t out)
{
    uint32_t height = GetH();
    uint32_t width = GetW();
    Quad_add578* r = static_cast<Quad_add578*>(Ptr_add578(out));
    r->v[0] = 0;
    r->v[1] = 0;
    r->v[2] = width;
    r->v[3] = height;
    r->v[0] = mnGutters[0];
    r->v[1] = mnGutters[1];
    r->v[2] = width - mnGutters[2];
    r->v[3] = height - mnGutters[3];
}
#endif

// FUNCTION: 0x009a6af1
bool cUnk00add578::Slot98_add348()
{
    Quad_add578 range = { { 0, 0, 0, 0 } };
    if (reinterpret_cast<cSelf_add578*>(this)->Slot50(&range)) {
        Slot97_add348(range.v[0], range.v[1], range.v[2] - range.v[0] + 1, range.v[3] - range.v[1] + 1);
        Slot46_add348();
        Fn009a5faa();
    }
    return true;
}

// FUNCTION: 0x009a6224
uint32_t cUnk00add578::Slot68_adc8d8(uint32_t flag, uint32_t value)
{
    if (flag == 2) {
        if (mpScrollBarV) {
            static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot03()->Slot68(2, value);
        }
        if (mpScrollBarH) {
            static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot03()->Slot68(2, value);
        }
    }
    return cGZWin::Slot68_adc8d8(flag, value);
}

// FUNCTION: 0x009a8809
bool cUnk00add578::Slot45_add348(uint32_t column, uint32_t row)
{
    int32_t rule = mnSelectionRuleA;
    ListNode_add578* head = *reinterpret_cast<ListNode_add578**>(&mpSelection);
    if (rule == 0) {
        for (ListNode_add578* node = head->mpNext; node != head; node = node->mpNext) {
            if (column == static_cast<uint32_t>(node->mnColumn)) {
                return true;
            }
        }
    } else if (rule == 1) {
        for (ListNode_add578* node = head->mpNext; node != head; node = node->mpNext) {
            if (row == static_cast<uint32_t>(node->mnRow)) {
                return true;
            }
        }
    } else {
        for (ListNode_add578* node = head->mpNext; node != head; node = node->mpNext) {
            if (column == static_cast<uint32_t>(node->mnColumn) && row == static_cast<uint32_t>(node->mnRow)) {
                return true;
            }
        }
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a8f16 score 12
bool cUnk00add578::Slot117_add348(uint32_t window, uint32_t id, uint32_t column, uint32_t row)
{
    WinMap_add578* map = reinterpret_cast<WinMap_add578*>(mCellWindows);
    for (WinNode_add578* node = static_cast<WinNode_add578*>(map->mpHeader->mpLeft); node != map->mpHeader; node = static_cast<WinNode_add578*>(Fn0040d4c0(node))) {
        WinObj_add578* w = node->mpWindow;
        bool match;
        if (window) {
            match = Ptr_add578(window) == w;
        } else {
            match = w->Slot63() == id;
        }
        if (match) {
            int32_t* c = static_cast<int32_t*>(Ptr_add578(column));
            if (c) {
                *c = node->mnColumn;
            }
            int32_t* r = static_cast<int32_t*>(Ptr_add578(row));
            if (r) {
                *r = node->mnRow;
            }
            return true;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x009afc65
bool cUnk00add578::Slot105_add348(uint32_t column, uint32_t row)
{
    cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
    if (mbE4) {
        RecalculateAll();
    }
    if (!self->Slot104(column, row)) {
        Slot31_add348(row - mnFirstRow);
        if (!self->Slot104(column, row)) {
            Slot32_add348(column - mnFirstColumn);
        }
    }
    return true;
}

// FUNCTION: 0x009ab897
bool cUnk00add578::Slot96_add348(uint32_t column, uint32_t row)
{
    bool changed = false;
    if (Slot44_add348(column, row, 0)) {
        changed = true;
    }
    void* old;
    if (reinterpret_cast<Matrix_add578*>(mCells)->RemoveCell(column, row, &old)) {
        DisposeOfCellData(column, row, old, true);
        mbE4 = 1;
        changed = true;
    }
    if (changed) {
        Fn009a5faa();
    }
    return true;
}

// FUNCTION: 0x009a9765
bool cUnk00add578::Slot43_add348(uint32_t column, uint32_t row)
{
    if (mnSelectionRuleB > 0) {
        cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
        if (!self->Slot45(column, row) || reinterpret_cast<List_add578*>(&mpSelection)->Size() != 1) {
            Slot46_add348();
            Slot44_add348(column, row, 1);
            Fn009a5faa();
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x009a97ce
bool cUnk00add578::Slot50_add348(uint32_t out)
{
    Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
    int32_t other;
    int32_t first = cells->Fn009a91d4(&other);
    if (first != static_cast<int32_t>(0x80000000)) {
        int32_t* r = static_cast<int32_t*>(Ptr_add578(out));
        r[0] = first;
        r[1] = cells->Fn009a917d(&other);
        r[2] = cells->Fn009a9225(&other);
        r[3] = cells->Fn009a91a6(&other);
        return true;
    }
    int32_t* r = static_cast<int32_t*>(Ptr_add578(out));
    r[0] = 0;
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    return false;
}

// FUNCTION: 0x009ac369
bool cUnk00add578::Slot61_add348(uint32_t start, uint32_t count, uint32_t alignment)
{
    int32_t end = start + count;
    int32_t c = start;
    if (c < end) {
        Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mColumnFormats);
        uint8_t align = static_cast<uint8_t>(alignment);
        do {
            CellFormatExtra_add578* cell;
            if (formats->GetCellPtr(c, 0, &cell)) {
                cell->mnColumnAlignment = align;
            } else {
                CellFormatExtra_add578 fresh;
                fresh.mnColumnAlignment = align;
                formats->Fn009ac02f(c, 0, fresh, 0);
            }
            c++;
        } while (c < end);
    }
    return true;
}

// FUNCTION: 0x009ac3d2
bool cUnk00add578::Slot62_add348(uint32_t start, uint32_t count, uint32_t alignment)
{
    int32_t end = start + count;
    int32_t r = start;
    if (r < end) {
        Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mRowFormats);
        uint8_t align = static_cast<uint8_t>(alignment);
        do {
            CellFormatExtra_add578* cell;
            if (formats->GetCellPtr(0, r, &cell)) {
                cell->mnColumnAlignment = align;
            } else {
                CellFormatExtra_add578 fresh;
                fresh.mnColumnAlignment = align;
                formats->Fn009ac02f(0, r, fresh, 0);
            }
            r++;
        } while (r < end);
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ac43b score 2
bool cUnk00add578::Slot65_add348(uint32_t start, uint32_t count, uint32_t width)
{
    int32_t w = width;
    if (w < 0) {
        w = 0;
    }
    int32_t end = start + count;
    int32_t c = start;
    if (c < end) {
        Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mColumnFormats);
        do {
            CellFormatExtra_add578* cell;
            if (formats->GetCellPtr(c, 0, &cell)) {
                cell->mnSize = static_cast<uint16_t>(w);
            } else {
                CellFormatExtra_add578 fresh;
                fresh.mnSize = static_cast<uint16_t>(w);
                formats->Fn009ac02f(c, 0, fresh, 0);
            }
            c++;
        } while (c < end);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ac4aa score 2
bool cUnk00add578::Slot67_add348(uint32_t start, uint32_t count, uint32_t height)
{
    int32_t h = height;
    if (h < 0) {
        h = 0;
    }
    int32_t end = start + count;
    int32_t r = start;
    if (r < end) {
        Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mRowFormats);
        do {
            CellFormatExtra_add578* cell;
            if (formats->GetCellPtr(0, r, &cell)) {
                cell->mnSize = static_cast<uint16_t>(h);
            } else {
                CellFormatExtra_add578 fresh;
                fresh.mnSize = static_cast<uint16_t>(h);
                formats->Fn009ac02f(0, r, fresh, 0);
            }
            r++;
        } while (r < end);
    }
    return true;
}
#endif

// FUNCTION: 0x009ae282
bool cUnk00add578::MakeRoomForRow(int32_t row, int32_t count, int32_t mode)
{
    if (mode == 0) {
        mode = 3;
    }
    if (mode == 1 || mode == 3 || mode == 5) {
        Quad_add578 range;
        if (reinterpret_cast<cSelf_add578*>(this)->Slot50(&range)) {
            for (int32_t column = range.v[0]; column <= range.v[2]; column++) {
                if (reinterpret_cast<Matrix_add578*>(mCells)->GetRowCountForCol(column)) {
                    MakeRoom(column, row, count, mode);
                }
            }
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x009ae2ef
bool cUnk00add578::MakeRoomForColumn(int32_t column, int32_t count, int32_t mode)
{
    if (mode == 0) {
        mode = 2;
    }
    if (mode == 1 || mode == 2 || mode == 4) {
        Quad_add578 range;
        if (reinterpret_cast<cSelf_add578*>(this)->Slot50(&range)) {
            for (int32_t row = range.v[1]; row <= range.v[3]; row++) {
                if (reinterpret_cast<Matrix_add578*>(mCells)->GetColCountForRow(row)) {
                    MakeRoom(column, row, count, mode);
                }
            }
        }
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a6ef7 score 50
bool cUnk00add578::Slot136_add348(uint32_t bitmap, uint32_t unused)
{
    Image_add578* image = static_cast<Image_add578*>(Ptr_add578(bitmap));
    if (image) {
        image->AddRef();
    }
    if (mpScrollImageV) {
        mpScrollImageV->Release();
    }
    mpScrollImageV = reinterpret_cast<cIGZUnknown*>(image);
    if (image) {
        ScrollBar_add578* bar = static_cast<ScrollBar_add578*>(mpScrollBarV);
        if (bar) {
            Embedded_add578* rect = reinterpret_cast<Embedded_add578*>(mScrollRectV);
            if (rect->Fn007c1870()) {
                bar->Slot17(image->Slot12(), image, 0);
            } else {
                bar->Slot17(rect, image, 0);
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a6f67 score 50
bool cUnk00add578::Slot137_add348(uint32_t bitmap, uint32_t unused)
{
    Image_add578* image = static_cast<Image_add578*>(Ptr_add578(bitmap));
    if (image) {
        image->AddRef();
    }
    if (mpScrollImageH) {
        mpScrollImageH->Release();
    }
    mpScrollImageH = reinterpret_cast<cIGZUnknown*>(image);
    if (image) {
        ScrollBar_add578* bar = static_cast<ScrollBar_add578*>(mpScrollBarH);
        if (bar) {
            Embedded_add578* rect = reinterpret_cast<Embedded_add578*>(mScrollRectH);
            if (rect->Fn007c1870()) {
                bar->Slot17(image->Slot12(), image, 0);
            } else {
                bar->Slot17(rect, image, 0);
            }
        }
    }
    return true;
}
#endif

// FUNCTION: 0x009a64ee
bool cUnk00add578::Slot35_add348(uint32_t column)
{
    int32_t target = column;
    if (target != mnFirstColumn) {
        int32_t limit = mnMaxColumns;
        if ((limit <= 0 || limit == -1) && (mnFlags & 0x8000)) {
        } else {
            if (!(mnFlags & 0x8000)) {
                Quad_add578 range = { { 0, 0, 0, 0 } };
                reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
                limit = range.v[2] + 1;
            }
            if (target >= limit) {
                target = limit - 1;
            }
        }
        mnFirstColumn = target;
        Fn009a5faa();
    }
    return true;
}

// FUNCTION: 0x009a6563
bool cUnk00add578::Slot36_add348(uint32_t row)
{
    int32_t target = row;
    if (target != mnFirstRow) {
        int32_t limit = mnMaxRows;
        if ((limit <= 0 || limit == -1) && (mnFlags & 0x10000)) {
        } else {
            if (!(mnFlags & 0x10000)) {
                Quad_add578 range = { { 0, 0, 0, 0 } };
                reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
                limit = range.v[3] + 1;
            }
            if (target >= limit) {
                target = limit - 1;
            }
        }
        mnFirstRow = target;
        Fn009a5faa();
    }
    return true;
}

// FUNCTION: 0x009a7665
bool cUnk00add578::DoMessage(uint32_t message)
{
    Message_add578* m = static_cast<Message_add578*>(Ptr_add578(message));
    if (m->mnType == 3 && m->mnId == 0x887113a3) {
        if (m->mnSub == 0x1a7c4511) {
            ScrollBar_add578* bar = static_cast<ScrollBar_add578*>(mpScrollBarV);
            if (bar) {
                int32_t value = bar->Slot06();
                if (value != mnFirstRow) {
                    mnFirstRow = value;
                    mbE4 = 1;
                    Fn009a5faa();
                }
            }
        } else if (m->mnSub == 0x1a7c4510) {
            ScrollBar_add578* bar = static_cast<ScrollBar_add578*>(mpScrollBarH);
            if (bar) {
                int32_t value = bar->Slot06();
                if (value != mnFirstColumn) {
                    mnFirstColumn = value;
                    mbE4 = 1;
                    Fn009a5faa();
                }
            }
        }
    }
    return cGZWin::DoMessage(message);
}

// A service object that plays sounds: slot 8 plays one, slot 13 looks one up.
struct SoundSys_add578 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual bool Slot08(void* sound);
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual bool Slot13(uint32_t kind, uint32_t iid, void* out, uint32_t id, uint32_t a, uint32_t b, uint32_t c);
};

// STUB: 0x00913c9e
SoundSys_add578* Fn00913c9e();

#ifdef OB_DRAFTS
// CLOSE: 0x009ad684 score 32
int32_t cUnk00add578::GetColumnWidthInternal(int32_t column)
{
    int32_t result;
    CellFormatExtra_add578* format;
    if (reinterpret_cast<Matrix_add578*>(mColumnFormats)->GetCellPtr(column, 0, &format)) {
        int16_t width = format->mnSize;
        if (width != -1) {
            result = width;
        } else {
            width = format->mnCachedSize;
            if (width != -1) {
                result = width;
            } else {
                result = mnDefaultColumnWidth;
                SetSizeCachedActualForColumn(column, 1, result);
            }
        }
    } else if (reinterpret_cast<Matrix_add578*>(mCells)->GetRowCountForCol(column) == 0) {
        result = mnDefaultColumnWidth;
    } else {
        result = mnDefaultColumnWidth;
        SetSizeCachedActualForColumn(column, 1, result);
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a824e score 53
bool cUnk00add578::Slot141_add578(uint32_t index)
{
    SoundSys_add578* system;
    uint32_t* id = &mnSoundIds[index];
    if (*id) {
        system = Fn00913c9e();
        if (system) {
            cIGZUnknown* sound = 0;
            if (system->Slot13(5, 0x5b523ba4, &sound, *id, 0, 0, 0)) {
                if (sound) {
                    bool played = system->Slot08(sound);
                    sound->Release();
                    return played;
                }
            } else if (sound) {
                sound->Release();
            }
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ac269 score 4
bool cUnk00add578::Slot19_add348(uint32_t color, uint32_t index, uint32_t start, uint32_t count)
{
    if (index < 6) {
        int32_t end = start + count;
        int32_t c = start;
        if (c < end) {
            Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mColumnFormats);
            do {
                CellFormatExtra_add578* cell;
                if (!formats->GetCellPtr(c, 0, &cell)) {
                    CellFormatExtra_add578 fresh;
                    formats->Fn009ac02f(c, 0, fresh, 0);
                    if (!formats->GetCellPtr(c, 0, &cell)) {
                        c++;
                        continue;
                    }
                }
                cell->mnColors[index] = color;
                c++;
            } while (c < end);
        }
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ac2e9 score 4
bool cUnk00add578::Slot20_add348(uint32_t color, uint32_t index, uint32_t start, uint32_t count)
{
    if (index < 6) {
        int32_t end = start + count;
        int32_t r = start;
        if (r < end) {
            Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mRowFormats);
            do {
                CellFormatExtra_add578* cell;
                if (!formats->GetCellPtr(0, r, &cell)) {
                    CellFormatExtra_add578 fresh;
                    formats->Fn009ac02f(0, r, fresh, 0);
                    if (!formats->GetCellPtr(0, r, &cell)) {
                        r++;
                        continue;
                    }
                }
                cell->mnColors[index] = color;
                r++;
            } while (r < end);
        }
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x009a619f
void cUnk00add578::Slot07_add348(uint32_t left, uint32_t top, uint32_t right, uint32_t bottom)
{
    cGZWin::Slot07_add348(left, top, right, bottom);
    Win_add578* win = reinterpret_cast<Win_add578*>(reinterpret_cast<char*>(this) + 4);
    if (win->Fn0099bc31()) {
        Quad_add578 grid;
        Quad_add578 cells;
        cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
        self->Slot08(&grid);
        self->Slot09(&cells);
        mnGridWidth = grid.v[2] - grid.v[0];
        mbE4 = 1;
        mnGridHeight = grid.v[3] - grid.v[1];
        mnCellAreaWidth = cells.v[2] - cells.v[0];
        mnCellAreaHeight = cells.v[3] - cells.v[1];
        Fn009a5faa();
    }
}

// FUNCTION: 0x009a6d87
bool cUnk00add578::Slot128_add348(uint32_t column, uint32_t row, uint32_t object)
{
    mn188 = 2;
    if (reinterpret_cast<cSelf_add578*>(this)->Slot54(column, row)) {
        cIGZUnknown* p = static_cast<cIGZUnknown*>(Ptr_add578(object));
        if (p) {
            p->AddRef();
        }
        mn188 = 1;
        cIGZUnknown* old = static_cast<cIGZUnknown*>(Ptr_add578(Slot120_add348(column, row)));
        mn188 = 2;
        if (old) {
            old->Release();
        }
        mn188 = 1;
        Slot119_add348(column, row, *reinterpret_cast<uint32_t*>(&mpExtra));
        mn188 = 2;
        return true;
    }
    return false;
}

// FUNCTION: 0x009a81be
void cUnk00add578::Slot11_add348(uint32_t flags)
{
    if (flags != mnFlags) {
        uint32_t changed = mnFlags ^ flags;
        mnFlags = flags;
        if (changed & 6) {
            RemoveScrollBar(!(flags & 4), !(flags & 2));
            mbE4 = 1;
            Fn009a5faa();
        }
        if (changed & 0x40000) {
            if (mnFlags & 0x40000) {
                if (!WinOf_add578(this)->Fn0099be0a()) {
                    WinOf_add578(this)->Fn0099bdfe();
                }
            } else if (WinOf_add578(this)->Fn0099be0a()) {
                WinOf_add578(this)->Fn0099be1e();
            }
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ab8fe score 61
bool cUnk00add578::Slot86_add348(uint32_t column, uint32_t row)
{
    bool changed = false;
    CellData_add578** cell = 0;
    Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
    if (cells->GetCellPtr(column, row, &cell)) {
        if (*cell && (*cell)->mpFormat) {
            CellFormat_add578* format = static_cast<CellFormat_add578*>((*cell)->mpFormat);
            if (format->mpFont) {
                format->mpFont->Release();
                changed = true;
            }
            Fn009a5c20(static_cast<void**>((*cell)->mpFormat));
            (*cell)->mpFormat = 0;
            if ((*cell)->mpData == 0) {
                cells->RemoveCell(column, row, 0);
                changed = true;
            }
            if (changed) {
                mbE4 = 1;
            }
        }
    }
    Fn009a5faa();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009aa3e1 score 8
bool cUnk00add578::Slot30_add348(uint32_t columns, uint32_t rules, uint32_t multi)
{
    mnMaxRows = -1;
    uint32_t newFlags = (mnFlags & 0xfffc2ba6) | 0x2ba6;
    mnMaxColumns = columns;
    mnFlags = newFlags;
    mnSelectionRuleA = 1;
    mnSelectionRuleB = rules;
    if (static_cast<uint8_t>(multi)) {
        mnFlags |= 0x1000;
    } else if (static_cast<int32_t>(rules) > 0) {
        Coord_add578 coord;
        if (!reinterpret_cast<cSelf_add578*>(this)->Slot42(&coord.mnColumn, &coord.mnRow)) {
            coord.mnColumn = 0;
            coord.mnRow = 0;
            reinterpret_cast<List_add578*>(&mpSelection)->PushBack(coord);
        }
    } else {
        Slot46_add348();
    }
    return true;
}
#endif

// The text a text cell holds.
struct Text_add578 {
    uint32_t mnPad;
    const char* mpBegin;
    const char* mpEnd;
};

// The text interface of a cell window: slot 45 copies its text out.
struct TextWin_add578 {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
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
    virtual void Slot45(void* out);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009aa813 score 25
bool cUnk00add578::Slot111_add348(uint32_t column, uint32_t row, uint32_t out)
{
    CellData_add578** cell;
    if (reinterpret_cast<Matrix_add578*>(mCells)->GetCellPtr(column, row, &cell) && (*cell)->mnType == 2) {
        Text_add578* text = static_cast<Text_add578*>((*cell)->mpData);
        uint32_t length = text->mpEnd - text->mpBegin;
        static_cast<cIGZString*>(Ptr_add578(out))->FromChar(text->mpBegin, length);
        return true;
    }
    cIGZUnknown* window = 0;
    if (reinterpret_cast<cSelf_add578*>(this)->Slot115(column, row, &window)) {
        TextWin_add578* textWin = 0;
        if (window->QueryInterface(0x231a1c57, reinterpret_cast<void**>(&textWin))) {
            textWin->Slot45(Ptr_add578(out));
            textWin->Release();
            return true;
        }
    }
    return false;
}
#endif

// FUNCTION: 0x009a683d
bool cUnk00add578::Slot72_add348(uint32_t column, uint32_t out)
{
    if (mnFlags & 8) {
        Quad_add578* r = static_cast<Quad_add578*>(Ptr_add578(out));
        if (static_cast<int32_t>(column) == -1) {
            uint32_t height = GetH();
            uint32_t width = GetW();
            r->v[0] = 0;
            r->v[1] = 0;
            r->v[2] = width;
            r->v[3] = height;
            r->v[0] = mnGutters[0];
            r->v[1] = mnGutters[1];
            r->v[2] = width - mnGutters[2];
            r->v[3] = mnHeaderSizeA + r->v[1];
            return true;
        }
        if (reinterpret_cast<cSelf_add578*>(this)->Slot106(column, 0, r)) {
            r->v[1] = mnGutters[1];
            r->v[3] = mnHeaderSizeA + r->v[1];
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x009a68e2
bool cUnk00add578::Slot73_add348(uint32_t row, uint32_t out)
{
    if (mnFlags & 0x10) {
        Quad_add578* r = static_cast<Quad_add578*>(Ptr_add578(out));
        if (static_cast<int32_t>(row) == -1) {
            uint32_t height = GetH();
            uint32_t width = GetW();
            r->v[0] = 0;
            r->v[1] = 0;
            r->v[2] = width;
            r->v[3] = height;
            r->v[0] = mnGutters[0];
            r->v[1] = mnGutters[1];
            r->v[2] = mnHeaderSizeA + r->v[0];
            r->v[3] = height - mnGutters[3];
            return true;
        }
        if (reinterpret_cast<cSelf_add578*>(this)->Slot106(0, row, r)) {
            r->v[0] = mnGutters[0];
            r->v[2] = mnHeaderSizeB + r->v[0];
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x009ace2f
bool cUnk00add578::Slot119_add348(uint32_t column, uint32_t row, uint32_t data)
{
    mn188 = 1;
    if (reinterpret_cast<cSelf_add578*>(this)->Slot54(column, row)) {
        CellData_add578** cell;
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        if (cells->GetCellPtr(column, row, &cell)) {
            if (*cell) {
                (*cell)->mnExtraData = data;
                return true;
            }
        } else {
            if (data != 0) {
                CellData_add578* fresh = new CellData_add578;
                fresh->mnExtraData = data;
                cells->InsertCell(column, row, &fresh, 0);
            }
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x009abed4
bool cUnk00add578::Slot04_ae1d24()
{
    DisposeOfAllCellData();
    if (mpBackgroundBitmap) {
        mpBackgroundBitmap->Release();
        mpBackgroundBitmap = 0;
    }
    if (mpOwnerDrawNotify) {
        mpOwnerDrawNotify->Release();
        mpOwnerDrawNotify = 0;
    }
    if (mpDefaultFont) {
        mpDefaultFont->Release();
        mpDefaultFont = 0;
    }
    if (mpHeadingFont) {
        mpHeadingFont->Release();
        mpHeadingFont = 0;
    }
    if (mpScrollBarV) {
        static_cast<cIGZUnknown*>(mpScrollBarV)->Release();
        mpScrollBarV = 0;
    }
    if (mpScrollBarH) {
        static_cast<cIGZUnknown*>(mpScrollBarH)->Release();
        mpScrollBarH = 0;
    }
    if (mpScrollImageV) {
        mpScrollImageV->Release();
        mpScrollImageV = 0;
    }
    if (mpScrollImageH) {
        mpScrollImageH->Release();
        mpScrollImageH = 0;
    }
    return cGZWin::Slot04_ae1d24();
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a6a39 score 66
bool cUnk00add578::Slot97_add348(uint32_t column, uint32_t row, uint32_t width, uint32_t height)
{
    int32_t w = width;
    if (w > 0) {
        int32_t h = height;
        if (h > 0) {
            Quad_add578 range;
            reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
            int32_t c0 = column;
            if (c0 < range.v[0]) {
                c0 = range.v[0];
            }
            if (c0 + w > range.v[2] + 1) {
                w = range.v[2] - c0 + 1;
            }
            int32_t r0 = row;
            if (r0 < range.v[1]) {
                r0 = range.v[1];
            }
            if (r0 + h > range.v[3] + 1) {
                h = range.v[3] - r0 + 1;
            } else {
                h = height;
            }
            if (w > 0 && h > 0) {
                int32_t endColumn = c0 + w;
                for (int32_t c = c0; c < endColumn; c++) {
                    for (int32_t r = r0; r < r0 + h; r++) {
                        Slot96_add348(c, r);
                    }
                }
                Fn009a5faa();
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ae813 score 2
bool cUnk00add578::Slot106_add348(uint32_t column, uint32_t row, uint32_t out)
{
    Quad_add578* r = static_cast<Quad_add578*>(Ptr_add578(out));
    r->v[0] = Slot70_add348(0, column);
    r->v[2] = GetColumnWidthInternal(column) + r->v[0];
    int32_t dx = 0;
    if (mnFirstColumn != 0) {
        dx = Slot70_add348(0, mnFirstColumn);
    }
    r->v[1] = Slot71_add348(0, row);
    r->v[3] = GetRowHeightInternal(row) + r->v[1];
    int32_t dy = mnFirstRow != 0 ? Slot71_add348(0, mnFirstRow) : 0;
    OffsetQuad_add578(r, -dx, -dy);
    Quad_add578 area;
    reinterpret_cast<cSelf_add578*>(this)->Slot09(&area);
    OffsetQuad_add578(r, area.v[0], area.v[1]);
    return true;
}
#endif

// FUNCTION: 0x009a7734
bool cUnk00add578::Slot09_add348(uint32_t out)
{
    uint32_t height = GetH();
    uint32_t width = GetW();
    Quad_add578* r = static_cast<Quad_add578*>(Ptr_add578(out));
    r->v[0] = 0;
    r->v[1] = 0;
    r->v[2] = width;
    r->v[3] = height;
    r->v[0] = mnGutters[0];
    r->v[1] = mnGutters[1];
    r->v[2] = width - mnGutters[2];
    r->v[3] = height - mnGutters[3];
    if (mnFlags & 8) {
        r->v[1] += mnHeaderSizeA;
    }
    if (mnFlags & 0x10) {
        r->v[0] += mnHeaderSizeB;
    }
    if (mpScrollBarV) {
        r->v[2] -= static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot03()->Slot41();
    }
    if (mpScrollBarH) {
        r->v[3] -= static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot03()->Slot42();
    }
    return true;
}

// What the grid hands an owner-draw notification.
struct OwnerDraw_add578 {
    void* mpGrid;
    int32_t mnColumn;
    int32_t mnRow;
    Quad_add578* mpRect1;
    Quad_add578* mpRect2;
    Quad_add578* mpRect3;
    void* mpBuffer;
    void* mpDrawContext;
    CellFormat_add578* mpFormat;
    CellData_add578* mpCell;
    uint8_t mbSelected;
    uint8_t mbEnabled;
};

// The font as the grid calls it: slot 37 measures a text.
struct Font_add578 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
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
    virtual int32_t Slot37(const char* text, uint32_t length);
    virtual void D38();
    virtual void D39();
    virtual void D40();
    virtual int32_t Slot41(const char* text, uint32_t length, int32_t width, void* measured, uint32_t mode);
    virtual void D42();
    virtual int32_t Slot43(const char* text, uint32_t length, int32_t width);
    virtual void D44();
    virtual void D45();
    virtual void D46();
    virtual void D47();
    virtual void D48();
    virtual void D49();
    virtual void D50();
    virtual void D51();
    virtual void Slot52(void* buffer, void* area, const char* text, uint32_t length, uint32_t style, uint32_t color, uint32_t background, void* clip, uint32_t flag);
};

// FUNCTION: 0x009a5fe3
void cUnk00add578::CalcCellDrawingParams(void* textArg, void* infoArg, void* rectArg, void* styleArg, void* colorArg, void* backgroundArg)
{
    cIGZString* text = static_cast<cIGZString*>(textArg);
    OwnerDraw_add578* info = static_cast<OwnerDraw_add578*>(infoArg);
    Quad_add578* rect = static_cast<Quad_add578*>(rectArg);
    uint32_t* style = static_cast<uint32_t*>(styleArg);
    uint32_t* color = static_cast<uint32_t*>(colorArg);
    uint32_t* background = static_cast<uint32_t*>(backgroundArg);
    Font_add578* font = reinterpret_cast<Font_add578*>(info->mpFormat->mpFont);
    int32_t height = font->Slot37(text->Data(), text->Strlen());
    uint8_t alignment = info->mpFormat->mnColumnAlignment;
    if (alignment == 3) {
        *style = 1;
    } else if (alignment == 4) {
        *style = 2;
    } else {
        *style = 0;
    }
    if (info->mpFormat->mnRowAlignment == 6) {
        rect->v[1] = (rect->v[1] + rect->v[3]) / 2 - height / 2;
        rect->v[3] = rect->v[1] + height;
    } else if (info->mpFormat->mnColumnAlignment != 5) {
        rect->v[1] = rect->v[3] - height;
    }
    if (info->mbSelected) {
        *color = info->mpFormat->mnColors[4];
        *background = info->mpFormat->mnColors[5];
    } else if (info->mbEnabled) {
        *color = info->mpFormat->mnColors[0];
        *background = info->mpFormat->mnColors[1];
    } else {
        *color = info->mpFormat->mnColors[2];
        *background = info->mpFormat->mnColors[3];
    }
}

// Sets a colour that still has the unset marker.
inline void DefaultColor_add578(uint32_t& field, uint32_t color)
{
    if (field == 0x40000000) {
        field = color;
    }
}

inline void DefaultByte_add578(uint8_t& field, uint8_t from, uint8_t to)
{
    if (field == from) {
        field = to;
    }
}

// The window class manager: slot 5 gives the object for an id (the default font).
struct Wcm_add578 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual cIGZUnknown* Slot05(uint32_t id);
};

// STUB: 0x00913c72
Wcm_add578* Fn00913c72();

#ifdef OB_DRAFTS
// CLOSE: 0x009a5cee score 237
void cUnk00add578::SetDefaultFormatting()
{
    if (!mpDefaultFont) {
        mpDefaultFont = Fn00913c72()->Slot05(0x68963c4c);
        if (mpDefaultFont) {
            mpDefaultFont->AddRef();
        }
    }
    uint32_t black = MakeFillColor(0, 0, 0);
    uint32_t white = MakeFillColor(0xff, 0xff, 0xff);
    mnOutlineColor = black;
    mnGridColorA = 0xff000000;
    mnGridColorB = 0xff000000;
    DefaultColor_add578(mnDefaultColors[0], black);
    DefaultColor_add578(mnDefaultColors[1], white);
    DefaultColor_add578(mnDefaultColors[4], white);
    DefaultColor_add578(mnDefaultColors[5], black);
    if (mnDefaultColors[2] == 0x40000000) {
        mnDefaultColors[2] = MakeFillColor(0xc0, 0xc0, 0xc0);
    }
    DefaultColor_add578(mnDefaultColors[3], white);
    DefaultByte_add578(mnDefaultWrapping, 0xff, 1);
    DefaultByte_add578(mnDefaultColumnAlignment, 0, 2);
    DefaultByte_add578(mnDefaultRowAlignment, 0, 5);
    DefaultByte_add578(mnDefaultBorderWidth, 0, 0);
    DefaultColor_add578(mnDefaultBorderColor, black);
    if (!mpHeadingFont) {
        mpHeadingFont = Fn00913c72()->Slot05(0x68963c4c);
        if (mpHeadingFont) {
            mpHeadingFont->AddRef();
        }
    }
    DefaultColor_add578(mnHeadingColors[0], black);
    DefaultColor_add578(mnHeadingColors[1], white);
    DefaultColor_add578(mnHeadingColors[4], black);
    if (mnHeadingColors[5] == 0x40000000) {
        mnHeadingColors[5] = MakeFillColor(0xdc, 0xdc, 0xff);
    }
    if (mnHeadingColors[2] == 0x40000000) {
        mnHeadingColors[2] = MakeFillColor(0x80, 0x80, 0x80);
    }
    if (mnHeadingColors[3] == 0x40000000) {
        mnHeadingColors[3] = MakeFillColor(0xdc, 0xdc, 0xdc);
    }
    DefaultByte_add578(mnHeadingWrapping, 0xff, 1);
    DefaultByte_add578(mnHeadingColumnAlignment, 0, 2);
    DefaultByte_add578(mnHeadingRowAlignment, 0, 6);
    DefaultByte_add578(mnHeadingBorderWidth, 0, 0);
    DefaultColor_add578(mnHeadingBorderColor, black);
}
#endif

// FUNCTION: 0x009a94a6
bool Matrix_add578::GetMatrixRow(int32_t row, MatrixRow_add578*& out)
{
    TreeNode_add578* node = mRows.Find(row);
    if (node != mRows.mpHeader) {
        out = &static_cast<RowNode_add578*>(node)->mRow;
        return true;
    }
    return false;
}

// FUNCTION: 0x009a9b7d
int32_t Matrix_add578::GetColCountForRow(int32_t row)
{
    MatrixRow_add578* found;
    if (GetMatrixRow(row, found)) {
        return found->mCells.mnCount;
    }
    return 0;
}

// FUNCTION: 0x009a9b9e
int32_t Matrix_add578::GetRowCountForCol(int32_t column)
{
    int32_t count = 0;
    TreeNode_add578* header = mRows.mpHeader;
    for (TreeNode_add578* node = header->mpLeft; node != header; node = Fn0040d4c0(node)) {
        CellsTree_add578* cells = &static_cast<RowNode_add578*>(node)->mRow.mCells;
        if (cells->Find(column) != cells->mpHeader) {
            count++;
        }
    }
    return count;
}

// FUNCTION: 0x009a9a89
bool Matrix_add578::GetMinMaxUsedColForRow(int32_t row, int32_t& minColumn, int32_t& maxColumn)
{
    bool found = false;
    minColumn = 0x7fffffff;
    maxColumn = 0x80000000;
    TreeNode_add578* node = mRows.Find(row);
    if (node != mRows.mpHeader) {
        TreeNode_add578* header = static_cast<RowNode_add578*>(node)->mRow.mCells.mpHeader;
        CellNode_add578* last = static_cast<CellNode_add578*>(Fn0040d500(header));
        minColumn = static_cast<CellNode_add578*>(header->mpLeft)->mnColumn;
        maxColumn = last->mnColumn;
        found = true;
    }
    return found;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a91d4 score 24
int32_t Matrix_add578::Fn009a91d4(int32_t* other)
{
    *other = 0x80000000;
    int32_t best = 0x80000000;
    TreeNode_add578* header = mRows.mpHeader;
    TreeNode_add578* node = header->mpLeft;
    if (node != header) {
        do {
            RowNode_add578* row = static_cast<RowNode_add578*>(node);
            int32_t column = static_cast<CellNode_add578*>(row->mRow.mCells.mpHeader->mpLeft)->mnColumn;
            if (column < best || best == static_cast<int32_t>(0x80000000)) {
                best = column;
                *other = row->mRow.mnIndex;
            }
            node = Fn0040d4c0(node);
        } while (node != mRows.mpHeader);
    }
    return best;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a9225 score 26
int32_t Matrix_add578::Fn009a9225(int32_t* other)
{
    *other = 0x80000000;
    int32_t best = 0x80000000;
    TreeNode_add578* node = mRows.mpHeader->mpLeft;
    if (node != mRows.mpHeader) {
        do {
            RowNode_add578* row = static_cast<RowNode_add578*>(node);
            int32_t column = static_cast<CellNode_add578*>(Fn0040d500(row->mRow.mCells.mpHeader))->mnColumn;
            if (column > best || best == static_cast<int32_t>(0x80000000)) {
                best = column;
                *other = row->mRow.mnIndex;
            }
            node = Fn0040d4c0(node);
        } while (node != mRows.mpHeader);
    }
    return best;
}
#endif

// FUNCTION: 0x009a917d
int32_t Matrix_add578::Fn009a917d(int32_t* other)
{
    *other = 0x80000000;
    if (mRows.mnCount != 0) {
        RowNode_add578* row = static_cast<RowNode_add578*>(mRows.mpHeader->mpLeft);
        MatrixRow_add578* found = &row->mRow;
        *other = static_cast<CellNode_add578*>(found->mCells.mpHeader->mpLeft)->mnColumn;
        return found->mnIndex;
    }
    return 0x80000000;
}

// FUNCTION: 0x009a91a6
int32_t Matrix_add578::Fn009a91a6(int32_t* other)
{
    *other = 0x80000000;
    if (mRows.mnCount != 0) {
        MatrixRow_add578* found = &static_cast<RowNode_add578*>(Fn0040d500(mRows.mpHeader))->mRow;
        *other = static_cast<CellNode_add578*>(found->mCells.mpHeader->mpLeft)->mnColumn;
        return found->mnIndex;
    }
    return 0x80000000;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a9122 score 43
MatIter_add578 Matrix_add578::Fn009a9122(int32_t column)
{
    TreeNode_add578* header = mRows.mpHeader;
    for (TreeNode_add578* node = header->mpLeft; node != header; node = Fn0040d4c0(node)) {
        TreeNode_add578* cellsHeader = static_cast<RowNode_add578*>(node)->mRow.mCells.mpHeader;
        for (TreeNode_add578* cell = cellsHeader->mpLeft; cell != cellsHeader; cell = Fn0040d4c0(cell)) {
            CellNode_add578* c = static_cast<CellNode_add578*>(cell);
            if (c->mnColumn == column) {
                return MatIter_add578(this, node, &c->mnColumn);
            }
        }
    }
    return MatIter_add578(this, header, 0);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a9a09 score 7
MatIter_add578 Matrix_add578::Fn009a9a09(int32_t row)
{
    MatrixRow_add578* found = 0;
    if (GetMatrixRow(row, found)) {
        return MatIter_add578(this, found, found->mCells.mpHeader->mpLeft);
    }
    return MatIter_add578(this, 0, 0);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a9a4c score 7
MatIter_add578 Matrix_add578::Fn009a9a4c(int32_t row)
{
    MatrixRow_add578* found = 0;
    if (GetMatrixRow(row, found)) {
        return MatIter_add578(this, found, found->mCells.mpHeader);
    }
    return MatIter_add578(this, 0, 0);
}
#endif

// FUNCTION: 0x009a94ca
InsertResult_add578 IntTreeA_add578::Fn009a94ca(const KeyValue_add578& v)
{
    TreeNode_add578* y = mpHeader;
    TreeNode_add578* x = mpHeader->mpParent;
    bool less = true;
    while (x) {
        y = x;
        less = v.mnKey < static_cast<KeyNode_add578*>(x)->mnKey;
        x = less ? x->mpLeft : x->mpRight;
    }
    TreeNode_add578* j = y;
    if (less) {
        if (j == mpHeader->mpLeft) {
            return InsertResult_add578(Insert(x, y, v, 0).mpNode, true);
        }
        j = Fn0040d500(j);
    }
    if (static_cast<KeyNode_add578*>(j)->mnKey < v.mnKey) {
        return InsertResult_add578(Insert(x, y, v, 0).mpNode, true);
    }
    return InsertResult_add578(j, false);
}

// FUNCTION: 0x009a954e
InsertResult_add578 CellsTree_add578::Fn009a954e(const KeyValue_add578& v)
{
    TreeNode_add578* y = mpHeader;
    TreeNode_add578* x = mpHeader->mpParent;
    bool less = true;
    while (x) {
        y = x;
        less = v.mnKey < static_cast<KeyNode_add578*>(x)->mnKey;
        x = less ? x->mpLeft : x->mpRight;
    }
    TreeNode_add578* j = y;
    if (less) {
        if (j == mpHeader->mpLeft) {
            return InsertResult_add578(Insert(x, y, v, 0).mpNode, true);
        }
        j = Fn0040d500(j);
    }
    if (static_cast<KeyNode_add578*>(j)->mnKey < v.mnKey) {
        return InsertResult_add578(Insert(x, y, v, 0).mpNode, true);
    }
    return InsertResult_add578(j, false);
}

// FUNCTION: 0x009abb8d
InsertResult_add578 IntTreeB_add578::Fn009abb8d(const KeyValue_add578& v)
{
    TreeNode_add578* y = mpHeader;
    TreeNode_add578* x = mpHeader->mpParent;
    bool less = true;
    while (x) {
        y = x;
        less = v.mnKey < static_cast<KeyNode_add578*>(x)->mnKey;
        x = less ? x->mpLeft : x->mpRight;
    }
    TreeNode_add578* j = y;
    if (less) {
        if (j == mpHeader->mpLeft) {
            return InsertResult_add578(Insert(x, y, v, 0).mpNode, true);
        }
        j = Fn0040d500(j);
    }
    if (static_cast<KeyNode_add578*>(j)->mnKey < v.mnKey) {
        return InsertResult_add578(Insert(x, y, v, 0).mpNode, true);
    }
    return InsertResult_add578(j, false);
}

// FUNCTION: 0x009abc11
InsertResult_add578 RowsTree_add578::Fn009abc11(const KeyValue_add578& v)
{
    TreeNode_add578* y = mpHeader;
    TreeNode_add578* x = mpHeader->mpParent;
    bool less = true;
    while (x) {
        y = x;
        less = v.mnKey < static_cast<KeyNode_add578*>(x)->mnKey;
        x = less ? x->mpLeft : x->mpRight;
    }
    TreeNode_add578* j = y;
    if (less) {
        if (j == mpHeader->mpLeft) {
            return InsertResult_add578(Insert(x, y, v, 0).mpNode, true);
        }
        j = Fn0040d500(j);
    }
    if (static_cast<KeyNode_add578*>(j)->mnKey < v.mnKey) {
        return InsertResult_add578(Insert(x, y, v, 0).mpNode, true);
    }
    return InsertResult_add578(j, false);
}

// FUNCTION: 0x009ab66b
uint32_t Tree_add578::Fn009ab66b(uint32_t key)
{
    Range_add578 range = Fn009a90f8(key);
    Tag_add578 tag;
    uint32_t count = Fn00893dec(&range.mpFirst, &range.mpSecond, tag);
    Fn009ab57d(range.mpFirst, range.mpSecond);
    return count;
}

// FUNCTION: 0x009a99c0
uint32_t CellsTree_add578::Fn009a99c0(uint32_t key)
{
    Range_add578 range = Fn009a90ce(key);
    Tag_add578 tag;
    uint32_t count = Fn00893dec(&range.mpFirst, &range.mpSecond, tag);
    Fn009a908a(range.mpFirst, range.mpSecond);
    return count;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ab57d score 32
void Tree_add578::Fn009ab57d(NodeIter_add578 first, NodeIter_add578 last)
{
    if (first.mpNode == mpHeader->mpLeft && last.mpNode == mpHeader) {
        EraseAll();
    } else {
        while (first.mpNode != last.mpNode) {
            TreeNode_add578* node = first.mpNode;
            first.mpNode = Fn0040d4c0(first.mpNode);
            EraseNode(node);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a908a score 32
void CellsTree_add578::Fn009a908a(NodeIter_add578 first, NodeIter_add578 last)
{
    if (first.mpNode == mpHeader->mpLeft && last.mpNode == mpHeader) {
        Clear();
    } else {
        while (first.mpNode != last.mpNode) {
            TreeNode_add578* node = first.mpNode;
            first.mpNode = Fn0040d4c0(first.mpNode);
            EraseNode(node);
        }
    }
}
#endif

// FUNCTION: 0x009ab299
MatrixRow_add578::MatrixRow_add578(const MatrixRow_add578& other)
    : mnIndex(other.mnIndex), mCells(other.mCells)
{
}

// FUNCTION: 0x009ab2b6
FmtRow_add578::FmtRow_add578(const FmtRow_add578& other)
    : mnIndex(other.mnIndex), mCells(other.mCells)
{
}

// FUNCTION: 0x009ab2d3
void RowsTree_add578::Fn009ab2d3(NodeIter_add578 it)
{
    TreeNode_add578* node = Fn0040daf0(it.mpNode, &mpHeader->mpParent, &mpHeader->mpLeft, &mpHeader->mpRight);
    reinterpret_cast<RowPair_add578*>(&static_cast<RowNode_add578*>(node)->mnKey)->DtorFlag(0);
    if (node) {
        Fn0090cf63(node);
    }
    --mnCount;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ab716 score 7
bool Matrix_add578::Fn009ab716(int32_t start, int32_t count)
{
    int32_t end = start + count;
    for (; start < end; start++) {
        TreeNode_add578* node = mRows.Find(start);
        if (node != mRows.mpHeader) {
            mnCellCount -= static_cast<RowNode_add578*>(node)->mRow.mCells.mnCount;
            mRows.Fn009ab2d3(node);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a999d score 6
InsertResult_add578 WinMap_add578::Fn009a999d(const CellData_add578& value)
{
    InsertResult_add578 result = Fn009a93a1(value);
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a8f7a score 34
void cUnk00add578::Fn009a8f7a(void* record)
{
    CellData_add578* cell = static_cast<CellData_add578*>(record);
    if (cell->mnType == 1) {
        void* window = cell->mpData;
        TreeNode_add578* header = reinterpret_cast<WinMap_add578*>(mCellWindows)->mpHeader;
        for (TreeNode_add578* node = header->mpLeft; node != reinterpret_cast<WinMap_add578*>(mCellWindows)->mpHeader; node = Fn0040d4c0(node)) {
            WinNode_add578* entry = static_cast<WinNode_add578*>(node);
            if (entry->mnType == 1 && entry->mpWindow == window) {
                entry->mnColumn = cell->mnColumn;
                entry->mnRow = cell->mnRow;
                break;
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a935d score 4
MatIter_add578 Matrix_add578::Fn009a935d()
{
    TreeNode_add578* header = mRows.mpHeader;
    for (TreeNode_add578* node = header->mpLeft; node != header; node = Fn0040d4c0(node)) {
        MatrixRow_add578* row = &static_cast<RowNode_add578*>(node)->mRow;
        if (row->mCells.mnCount != 0) {
            return MatIter_add578(this, node, row->mCells.mpHeader->mpLeft);
        }
    }
    return MatIter_add578(this, header, 0);
}
#endif

// FUNCTION: 0x009ab75e
bool Matrix_add578::Fn009ab75e(int32_t start, int32_t count)
{
    TreeNode_add578* node = mRows.mpHeader->mpLeft;
    if (node != mRows.mpHeader) {
        int32_t end = start + count;
        do {
            RowNode_add578* row = static_cast<RowNode_add578*>(node);
            for (int32_t key = start; key < end; key++) {
                CellsTree_add578* cells = &row->mRow.mCells;
                TreeNode_add578* found = cells->Find(key);
                if (found != cells->mpHeader) {
                    cells->EraseNode(found);
                    --mnCellCount;
                }
            }
            if (row->mRow.mCells.mnCount == 0) {
                TreeNode_add578* current = node;
                node = Fn0040d4c0(node);
                mRows.Fn009ab2d3(current);
            } else {
                node = Fn0040d4c0(node);
            }
        } while (node != mRows.mpHeader);
    }
    return true;
}

// Three words copied as a whole (the comparison object of a sort).
struct Triple_add578 {
    uint32_t v[3];
};

// The scratch buffer the stable sort asks for.
struct TempBuffer_add578 {
    uint32_t mnFirst;
    uint32_t mnSize;
    void* mpBuffer;
    // STUB: 0x009a8a38
    TempBuffer_add578(uint32_t first, uint32_t last);
};

// STUB: 0x009ab08b
uint32_t Fn009ab08b(uint32_t a, uint32_t b, Triple_add578 compare);
// STUB: 0x009ab37e
uint32_t Fn009ab37e(uint32_t a, uint32_t b, void* buffer, uint32_t size, Triple_add578 compare);
// STUB: 0x009f015b
void Fn009f015b(void* p);

// FUNCTION: 0x009ab613
void Fn009ab613(uint32_t first, uint32_t last, uint32_t /*unused1*/, uint32_t /*unused2*/, Triple_add578 compare)
{
    TempBuffer_add578 buffer(first, last);
    if (buffer.mpBuffer == 0) {
        Fn009ab08b(first, last, compare);
    } else {
        Fn009ab37e(first, last, buffer.mpBuffer, buffer.mnSize, compare);
    }
    Fn009f015b(buffer.mpBuffer);
}

// FUNCTION: 0x009ab7e6
void Fn009ab7e6(uint32_t first, uint32_t last, Triple_add578 compare)
{
    Fn009ab613(first, last, 0, 0, compare);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a9280 score 21
int32_t Matrix_add578::GetCellCountForRange(int32_t column0, int32_t column1, int32_t row0, int32_t row1)
{
    int32_t count = 0;
    TreeNode_add578* header = mRows.mpHeader;
    TreeNode_add578* node = header->mpLeft;
    if (node != header) {
        do {
        RowNode_add578* row = static_cast<RowNode_add578*>(node);
        int32_t rowIndex = row->mRow.mnIndex;
        if (rowIndex >= row0) {
            if (rowIndex > row1) {
                return count;
            }
            TreeNode_add578* cellsHeader = row->mRow.mCells.mpHeader;
            for (TreeNode_add578* cell = cellsHeader->mpLeft; cell != cellsHeader; cell = Fn0040d4c0(cell)) {
                int32_t column = static_cast<CellNode_add578*>(cell)->mnColumn;
                if (column >= column0) {
                    if (column > column1) {
                        break;
                    }
                    count++;
                }
            }
        }
            node = Fn0040d4c0(node);
        } while (node != header);
    }
    return count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a92db score 57
int32_t Matrix_add578::GetCellRange(int32_t column0, int32_t column1, int32_t row0, int32_t row1, UserCell_add578* out)
{
    int32_t count = 0;
    TreeNode_add578* header = mRows.mpHeader;
    TreeNode_add578* node = header->mpLeft;
    if (node != header) {
        do {
        RowNode_add578* row = static_cast<RowNode_add578*>(node);
        int32_t rowIndex = row->mRow.mnIndex;
        if (rowIndex >= row0) {
            if (rowIndex > row1) {
                return count;
            }
            TreeNode_add578* cellsHeader = row->mRow.mCells.mpHeader;
            for (TreeNode_add578* cell = cellsHeader->mpLeft; cell != cellsHeader; cell = Fn0040d4c0(cell)) {
                CellNode_add578* c = static_cast<CellNode_add578*>(cell);
                if (c->mnColumn >= column0) {
                    if (c->mnColumn > column1) {
                        break;
                    }
                    if (out) {
                        out[count].mnColumn = c->mnColumn;
                        out[count].mnRow = rowIndex;
                        out[count].mpCell = static_cast<CellData_add578*>(c->mpValue);
                    }
                    count++;
                }
            }
        }
            node = Fn0040d4c0(node);
        } while (node != mRows.mpHeader);
    }
    return count;
}
#endif

// FUNCTION: 0x009a7178
bool cUnk00add578::RemoveScrollBar(bool vertical, bool horizontal)
{
    bool changed = false;
    if (vertical && mpScrollBarV) {
        changed = true;
        cWinView_add578* win = reinterpret_cast<cWinView_add578*>(reinterpret_cast<char*>(this) + 4);
        win->Slot16(static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot03());
        static_cast<cIGZUnknown*>(mpScrollBarV)->Release();
        mpScrollBarV = 0;
    }
    if (horizontal && mpScrollBarH) {
        changed = true;
        cWinView_add578* win = reinterpret_cast<cWinView_add578*>(reinterpret_cast<char*>(this) + 4);
        win->Slot16(static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot03());
        static_cast<cIGZUnknown*>(mpScrollBarH)->Release();
        mpScrollBarH = 0;
    }
    if (changed) {
        mbE4 = 1;
    }
    return true;
}

// FUNCTION: 0x009abaef
bool cUnk00add578::DisposeOfAllCellData()
{
    uint32_t total = reinterpret_cast<Matrix_add578*>(mCells)->mnCellCount;
    UserCell_add578* list = static_cast<UserCell_add578*>(::operator new(total * sizeof(UserCell_add578)));
    Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
    int32_t count = cells->GetCellRange(0, 0x7fffffff, 0, 0x7fffffff, list);
    for (int32_t i = 0; i < count; i++) {
        DisposeOfCellData(list[i].mnColumn, list[i].mnRow, list[i].mpCell, true);
    }
    ::operator delete(list);
    cells->Fn009ab5ea();
    cells->mnCellCount = 0;
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a9ada score 47
bool Matrix_add578::GetMinMaxUsedRowForCol(int32_t column, int32_t& minRow, int32_t& maxRow)
{
    minRow = 0x7fffffff;
    maxRow = 0x80000000;
    bool found = false;
    TreeNode_add578* header = mRows.mpHeader;
    for (TreeNode_add578* node = header->mpLeft; node != header; node = Fn0040d4c0(node)) {
        CellsTree_add578* cells = &static_cast<RowNode_add578*>(node)->mRow.mCells;
        if (cells->Find(column) != cells->mpHeader) {
            minRow = static_cast<RowNode_add578*>(node)->mRow.mnIndex;
            maxRow = static_cast<RowNode_add578*>(node)->mRow.mnIndex;
            TreeNode_add578* rbegin = mRows.mpHeader;
            TreeNode_add578* rend = rbegin->mpLeft;
            found = true;
            for (TreeNode_add578* it = rbegin; it != rend; it = Fn0040d500(it)) {
                MatrixRow_add578* row = &static_cast<RowNode_add578*>(Fn0040d500(it))->mRow;
                if (row->mCells.Find(column) != row->mCells.mpHeader) {
                    maxRow = row->mnIndex;
                    break;
                }
            }
            break;
        }
    }
    return found;
}
#endif

// FUNCTION: 0x009ab6b4
bool Matrix_add578::RemoveCell(int32_t column, int32_t row, void* old)
{
    TreeNode_add578* rowNode = mRows.Find(row);
    if (rowNode != mRows.mpHeader) {
        CellsTree_add578* cells = &static_cast<RowNode_add578*>(rowNode)->mRow.mCells;
        TreeNode_add578* cell = cells->Find(column);
        if (cell != cells->mpHeader) {
            if (old) {
                *static_cast<void**>(old) = static_cast<CellNode_add578*>(cell)->mpValue;
            }
            cells->EraseNode(cell);
            mnCellCount--;
            if (static_cast<RowNode_add578*>(rowNode)->mRow.mCells.mnCount == 0) {
                mRows.Fn009ab2d3(rowNode);
            }
            return true;
        }
    }
    return false;
}

// A cell as the cell tree stores it: key, column and value.
struct CellEntry_add578 : public KeyValue_add578 {
    int32_t mnColumn;
    void* mpValue;
    CellEntry_add578(int32_t column, void* value) : KeyValue_add578(column), mnColumn(column), mpValue(value) {}
};

// FUNCTION: 0x009ac157
bool Matrix_add578::InsertCell(int32_t column, int32_t row, void* value, void* old)
{
    if (row < mnMinRow || column < mnMinColumn || row > mnMaxRow || column > mnMaxColumn) {
        return false;
    }
    int32_t r = row;
    int32_t c = column;
    TreeNode_add578* rowNode = mRows.Find(row);
    if (rowNode != mRows.mpHeader) {
        CellsTree_add578* cells = &static_cast<RowNode_add578*>(rowNode)->mRow.mCells;
        TreeNode_add578* cell = cells->Find(column);
        if (cell != cells->mpHeader) {
            if (old) {
                *static_cast<void**>(old) = static_cast<CellNode_add578*>(cell)->mpValue;
            }
            static_cast<CellNode_add578*>(cell)->mpValue = *static_cast<void**>(value);
        } else {
            cells->Fn009a954e(CellEntry_add578(c, *static_cast<void**>(value)));
            mnCellCount++;
        }
    } else {
        RowPair_add578 pair(r, MatrixRow_add578(r));
        InsertResult_add578 inserted = mRows.Fn009abc11(reinterpret_cast<const KeyValue_add578&>(pair));
        static_cast<RowNode_add578*>(inserted.mpNode)->mRow.mCells.Fn009a954e(CellEntry_add578(c, *static_cast<void**>(value)));
        mnCellCount++;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a903e score 21
MatIter_add578& MatIter_add578::Fn009a903e()
{
    mpCell = Fn0040d4c0(static_cast<TreeNode_add578*>(mpCell));
    if (mpCell == static_cast<RowNode_add578*>(mpRow)->mRow.mCells.mpHeader) {
        for (;;) {
            mpRow = Fn0040d4c0(static_cast<TreeNode_add578*>(mpRow));
            if (mpRow == static_cast<Matrix_add578*>(mpMatrix)->mRows.mpHeader) {
                break;
            }
            MatrixRow_add578* row = &static_cast<RowNode_add578*>(mpRow)->mRow;
            if (row->mCells.mnCount != 0) {
                mpCell = row->mCells.mpHeader->mpLeft;
                break;
            }
        }
    }
    return *this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a8fec score 18
MatIter_add578& MatIter_add578::Fn009a8fec()
{
    for (;;) {
        mpRow = Fn0040d4c0(static_cast<TreeNode_add578*>(mpRow));
        if (mpRow == static_cast<Matrix_add578*>(mpMatrix)->mRows.mpHeader) {
            mpCell = 0;
            return *this;
        }
        TreeNode_add578* cellsHeader = static_cast<RowNode_add578*>(mpRow)->mRow.mCells.mpHeader;
        TreeNode_add578* cell = cellsHeader->mpLeft;
        if (cell != cellsHeader) {
            int32_t column = *static_cast<int32_t*>(mpCell);
            do {
                int32_t* field = &static_cast<CellNode_add578*>(cell)->mnColumn;
                if (*field == column) {
                    mpCell = field;
                    return *this;
                }
                cell = Fn0040d4c0(cell);
            } while (cell != cellsHeader);
        }
    }
}
#endif

inline bool EqualA_add578(MatIter_add578& a, MatIter_add578& b)
{
    return reinterpret_cast<IterA_add578*>(&a)->Fn009a7577(*reinterpret_cast<IterA_add578*>(&b));
}

inline bool EqualB_add578(MatIter_add578& a, MatIter_add578& b)
{
    return reinterpret_cast<IterB_add578*>(&a)->Fn009a75a3(*reinterpret_cast<IterB_add578*>(&b));
}

#ifdef OB_DRAFTS
// CLOSE: 0x009acd43 score 24
void cUnk00add578::SetSizeCachedActualForColumn(int32_t column, int32_t count, int32_t size)
{
    int32_t limit = 0x7fffffff;
    if (mnMaxColumns != -1 && mnMaxColumns != 0) {
        limit = mnMaxColumns - 1;
    }
    if (count == 0x7fffffff) {
        count = 0x7fffffff - column;
        if (column + count > limit) {
            count = limit - column + 1;
        }
        if (size == -1) {
            Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mColumnFormats);
            MatIter_add578 cell = formats->Fn009a9a09(0);
            MatIter_add578 end = formats->Fn009a9a4c(0);
            while (!EqualB_add578(cell, end)) {
                *reinterpret_cast<int16_t*>(static_cast<char*>(cell.mpCell) + 0x3e) = -1;
                cell.Fn009a903e();
            }
            return;
        }
    }
    if (count != 0) {
        Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mColumnFormats);
        for (int32_t n = count; n != 0; n--) {
            CellFormatExtra_add578* format;
            if (!formats->GetCellPtr(column, 0, &format)) {
                if (size == -1) {
                    column++;
                    continue;
                }
                CellFormatExtra_add578 fresh;
                formats->Fn009ac02f(column, 0, fresh, 0);
                if (!formats->GetCellPtr(column, 0, &format)) {
                    column++;
                    continue;
                }
            }
            format->mnCachedSize = static_cast<int16_t>(size);
            column++;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009acc5a score 2
void cUnk00add578::SetSizeCachedActualForRow(int32_t row, int32_t count, int32_t size)
{
    int32_t limit = 0x7fffffff;
    if (mnMaxRows != -1 && mnMaxRows != 0) {
        limit = mnMaxRows - 1;
    }
    if (count == 0x7fffffff) {
        count = 0x7fffffff - row;
        if (row + count > limit) {
            count = limit - row + 1;
        }
        if (size == -1) {
            Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mRowFormats);
            MatIter_add578 cell = formats->Fn009a9122(0);
            MatIter_add578 end(formats, formats->mRows.mpHeader, 0);
            while (!EqualA_add578(cell, end)) {
                *reinterpret_cast<int16_t*>(static_cast<char*>(cell.mpCell) + 0x2a) = -1;
                cell.Fn009a8fec();
            }
            return;
        }
    }
    if (count != 0) {
        Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mRowFormats);
        for (int32_t n = count; n != 0; n--) {
            CellFormatExtra_add578* format;
            if (!formats->GetCellPtr(0, row, &format)) {
                if (size == -1) {
                    row++;
                    continue;
                }
                CellFormatExtra_add578 fresh;
                formats->Fn009ac02f(0, row, fresh, 0);
                if (!formats->GetCellPtr(0, row, &format)) {
                    row++;
                    continue;
                }
            }
            format->mnCachedSize = static_cast<int16_t>(size);
            row++;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a82c6 score 4
bool cUnk00add578::TestForPossibleScrollBarAdditionOrRemoval()
{
    uint32_t flags = mnFlags;
    if (flags & 4) {
        int32_t rows = mnMaxRows;
        bool add;
        if ((rows == -1 || rows == 0) && (flags & 0x10000)) {
            add = true;
        } else {
            int32_t extent = rows;
            if (!(flags & 0x10000)) {
                Quad_add578 range = { { 0, 0, 0, 0 } };
                reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
                extent = range.v[3] + 1;
            }
            add = static_cast<float>(extent) > mfVisibleRows;
            if (!add && mpScrollBarV) {
                RemoveScrollBar(true, false);
            }
        }
        if (add && !mpScrollBarV) {
            AddScrollBar(true, false);
        }
    }
    flags = mnFlags;
    if (flags & 2) {
        int32_t rows = mnMaxRows;
        bool add;
        if ((rows == -1 || rows == 0) && (flags & 0x10000)) {
            add = true;
        } else {
            int32_t extent = mnMaxColumns;
            if (!(flags & 0x10000)) {
                Quad_add578 range = { { 0, 0, 0, 0 } };
                reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
                extent = range.v[2] + 1;
            }
            add = static_cast<float>(extent) > mfVisibleColumns;
            if (!add && mpScrollBarH) {
                RemoveScrollBar(false, true);
            }
        }
        if (add && !mpScrollBarH) {
            AddScrollBar(false, true);
        }
    }
    if (mpScrollBarV || mpScrollBarH) {
        SetScrollBarValues();
        SetScrollBarPositions();
    }
    return true;
}
#endif

// A cell's text, deleted through its slot 28 with the delete flag.
struct DeletableText_add578 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
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
    virtual void Slot28(uint32_t flag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009aab01 score 34
bool cUnk00add578::DisposeOfCellData(int32_t column, int32_t row, void* cellArg, bool freeIt)
{
    CellData_add578* cell = static_cast<CellData_add578*>(cellArg);
    if (cell == 0) {
        CellData_add578** found;
        if (!reinterpret_cast<Matrix_add578*>(mCells)->GetCellPtr(column, row, &found)) {
            return false;
        }
        cell = *found;
        if (cell == 0) {
            return false;
        }
    }
    switch (cell->mnType) {
    case 1:
        DoWindowRemoval(column, row, cell->mpData);
        cell->mpData = 0;
        break;
    case 2:
        if (cell->mpData) {
            static_cast<DeletableText_add578*>(cell->mpData)->Slot28(1);
        }
        cell->mpData = 0;
        break;
    case 4:
        static_cast<cIGZUnknown*>(cell->mpData)->Release();
        cell->mpData = 0;
        break;
    }
    if (cell->mpFormat) {
        CellFormat_add578* format = static_cast<CellFormat_add578*>(cell->mpFormat);
        if (format->mpFont) {
            format->mpFont->Release();
        }
        Fn009a5c20(static_cast<void**>(cell->mpFormat));
        cell->mpFormat = 0;
    }
    if (cell->mnExtraData) {
        if (mn188 == 2) {
            static_cast<cIGZUnknown*>(Ptr_add578(cell->mnExtraData))->Release();
        }
        cell->mnExtraData = 0;
    }
    if (freeIt) {
        delete cell;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009aa991 score 60
void cUnk00add578::PlaceAllCellWindows()
{
    if (WinOf_add578(this)->Fn0099bc31()) {
        Quad_add578 visible;
        reinterpret_cast<cSelf_add578*>(this)->Slot51(&visible);
        TreeNode_add578* header = reinterpret_cast<WinMap_add578*>(mCellWindows)->mpHeader;
        TreeNode_add578* node = header->mpLeft;
        if (node != header) {
            do {
                WinNode_add578* entry = static_cast<WinNode_add578*>(node);
                if (entry->mnType == 1) {
                    CellData_add578** found;
                    if (reinterpret_cast<Matrix_add578*>(mCells)->GetCellPtr(entry->mnColumn, entry->mnRow, &found)) {
                        CellData_add578* cell = *found;
                        if (cell) {
                            WinObj_add578* window = static_cast<WinObj_add578*>(cell->mpData);
                            if (window) {
                                if (visible.Contains(cell->mnColumn, cell->mnRow)) {
                                    Quad_add578 area;
                                    reinterpret_cast<cSelf_add578*>(this)->Slot106(cell->mnColumn, cell->mnRow, &area);
                                    area.v[0] += mnCellGutters[0];
                                    area.v[1] += mnCellGutters[1];
                                    area.v[2] -= mnCellGutters[2];
                                    area.v[3] -= mnCellGutters[3];
                                    window->Slot69();
                                    window->Slot56(area.v[0], area.v[1]);
                                    if (cell->mnWindowFlags & 1) {
                                        window->Slot51(area.v[2] - area.v[0]);
                                    }
                                    if (cell->mnWindowFlags & 2) {
                                        window->Slot52(area.v[3] - area.v[1]);
                                    }
                                } else {
                                    window->Slot70();
                                }
                            }
                        }
                    }
                }
                node = Fn0040d4c0(node);
            } while (node != header);
        }
    }
}
#endif

// FUNCTION: 0x009a6c45
void cUnk00add578::Fn009a6c45(int32_t column, int32_t row, void* windowArg, bool stretchWidth, bool stretchHeight)
{
    if (WinOf_add578(this)->Fn0099bc31()) {
        Quad_add578 visible;
        reinterpret_cast<cSelf_add578*>(this)->Slot51(&visible);
        WinObj_add578* window = static_cast<WinObj_add578*>(windowArg);
        if (visible.Contains(column, row)) {
            Quad_add578 area;
            reinterpret_cast<cSelf_add578*>(this)->Slot106(column, row, &area);
            area.v[0] += mnCellGutters[0];
            area.v[1] += mnCellGutters[1];
            area.v[2] -= mnCellGutters[2];
            area.v[3] -= mnCellGutters[3];
            window->Slot69();
            window->Slot56(area.v[0], area.v[1]);
            if (stretchWidth) {
                window->Slot51(area.v[2] - area.v[0]);
            }
            if (stretchHeight) {
                window->Slot52(area.v[3] - area.v[1]);
            }
            window->Slot55(area.v[0], area.v[1], area.v[2], area.v[3]);
        } else {
            window->Slot70();
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ae48f score 115
bool cUnk00add578::Slot31_add348(uint32_t delta)
{
    int32_t oldFirst = mnFirstRow;
    int32_t limit = mnMaxRows;
    if ((limit == -1 || limit == 0) && (mnFlags & 0x10000)) {
        mnFirstRow = oldFirst + delta;
    } else {
        if (!(mnFlags & 0x10000)) {
            Quad_add578 range = { { 0, 0, 0, 0 } };
            reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
            limit = range.v[3] + 1;
        }
        mnFirstRow += delta;
        if (mnFirstRow >= limit) {
            mnFirstRow = limit - 1;
        }
        if (mnFirstRow < 0) {
            mnFirstRow = 0;
        }
        if (mnFirstRow > 0) {
            while (mnCellAreaHeight > 0) {
                int32_t row = mnFirstRow;
                int32_t sum = 0;
                for (; row < limit; row++) {
                    sum += GetRowHeightInternal(row);
                    if (sum >= mnCellAreaHeight) {
                        break;
                    }
                }
                if (sum < mnCellAreaHeight) {
                    mnFirstRow--;
                }
                if (mnFirstRow < 0) {
                    break;
                }
            }
        }
    }
    if (mnFirstRow < 0) {
        mnFirstRow = 0;
    }
    if (oldFirst != mnFirstRow) {
        Fn009a5faa();
        mbE4 = 1;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ad817 score 109
bool cUnk00add578::Slot32_add348(uint32_t delta)
{
    int32_t oldFirst = mnFirstColumn;
    int32_t limit = mnMaxColumns;
    if ((limit == -1 || limit == 0) && (mnFlags & 0x8000)) {
        mnFirstColumn = oldFirst + delta;
    } else {
        if (!(mnFlags & 0x10000)) {
            Quad_add578 range = { { 0, 0, 0, 0 } };
            reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
            limit = range.v[2] + 1;
        }
        mnFirstColumn += delta;
        if (mnFirstColumn >= limit) {
            mnFirstColumn = limit - 1;
        }
        if (mnFirstColumn < 0) {
            mnFirstColumn = 0;
        }
        if (mnFirstColumn > 0) {
            while (mnCellAreaWidth > 0) {
                int32_t column = mnFirstColumn;
                int32_t sum = 0;
                for (; column < limit; column++) {
                    sum += GetColumnWidthInternal(column);
                    if (sum >= mnCellAreaWidth) {
                        break;
                    }
                }
                if (sum < mnCellAreaWidth) {
                    mnFirstColumn--;
                }
                if (mnFirstColumn < 0) {
                    break;
                }
            }
        }
    }
    if (mnFirstColumn < 0) {
        mnFirstColumn = 0;
    }
    if (oldFirst != mnFirstColumn) {
        Fn009a5faa();
        mbE4 = 1;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ae387 score 40
int32_t cUnk00add578::GetRowHeightInternal(int32_t row)
{
    int32_t height = mnDefaultRowHeight;
    if (mnMaxRows != 0 && mnMaxRows != -1) {
        height = mnCellAreaHeight / mnMaxRows;
    }
    CellFormatExtra_add578* format;
    if (reinterpret_cast<Matrix_add578*>(mRowFormats)->GetCellPtr(0, row, &format)) {
        int16_t size = format->mnSize;
        if (size != -1) {
            height = size;
            return height;
        }
        size = format->mnCachedSize;
        if (size != -1) {
            height = size;
            return height;
        }
    } else if (reinterpret_cast<Matrix_add578*>(mCells)->GetColCountForRow(row) == 0) {
        height = mnDefaultRowHeight;
        return height;
    }
    Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
    int32_t n = cells->GetColCountForRow(row);
    if (n != 0) {
        UserCell_add578* list = static_cast<UserCell_add578*>(::operator new(n * sizeof(UserCell_add578)));
        int32_t count = cells->GetCellRange(0x80000000, 0x7fffffff, row, row, list);
        for (int32_t i = 0; i < count; i++) {
            int32_t cellHeight = CalculateCellHeight(list[i].mnColumn, list[i].mnRow, list[i].mpCell);
            if (height < cellHeight) {
                height = cellHeight;
            }
        }
        ::operator delete(list);
    }
    SetSizeCachedActualForRow(row, 1, height);
    return height;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ad6fa score 103
int32_t cUnk00add578::CalculateCellHeight(int32_t column, int32_t row, void* cellArg)
{
    CellData_add578* cell = static_cast<CellData_add578*>(cellArg);
    int32_t height = mnDefaultRowHeight;
    CellData_add578** found;
    if (cell != 0 || (reinterpret_cast<Matrix_add578*>(mCells)->GetCellPtr(column, row, &found) && (cell = *found) != 0)) {
        switch (cell->mnType) {
        case 1:
            if (cell->mpData) {
                height = static_cast<WinObj_add578*>(cell->mpData)->Slot42();
            }
            break;
        case 2: {
            Text_add578* text = static_cast<Text_add578*>(cell->mpData);
            if (text && text->mpEnd - text->mpBegin != 0) {
                CellFormat_add578 format;
                if (reinterpret_cast<cSelf_add578*>(this)->Slot84(column, row, &format) && format.mpFont) {
                    Font_add578* font = reinterpret_cast<Font_add578*>(format.mpFont);
                    uint32_t lineHeight = font->Slot37(0, 0);
                    if (lineHeight != 0) {
                        int32_t lines = 1;
                        if (!(mnFlags & 0x20800)) {
                            lines = font->Slot43(text->mpBegin, text->mpEnd - text->mpBegin, GetColumnWidthInternal(column));
                        }
                        height = lineHeight * lines;
                    }
                }
            }
            break;
        }
        case 4:
            if (cell->mpData) {
                height = reinterpret_cast<Image_add578*>(cell->mpData)->Slot10();
            }
            break;
        }
    }
    return height + mnCellGutters[1] + mnCellGutters[3];
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a71fd score 114
bool cUnk00add578::SetScrollBarValues()
{
    Quad_add578 range = { { -1, -1, -1, -1 } };
    if (mpScrollBarV && mfVisibleRows > 0.0f) {
        int32_t rows = mnMaxRows;
        if ((rows == -1 || rows == 0) && (mnFlags & 0x10000)) {
            static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot07(0, static_cast<int32_t>(mfVisibleRows));
            static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot15(0x7fffffff, 0x7fffffff);
        } else {
            int32_t extent = rows;
            if (!(mnFlags & 0x10000)) {
                reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
                extent = range.v[3] + 1;
            }
            int32_t position = extent - static_cast<int32_t>(mfVisibleRows);
            if (position < 0) {
                position = 0;
            }
            static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot07(0, position);
            static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot15(position, static_cast<int32_t>(extent / mfVisibleRows + 1.0f));
        }
        static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot05(mnFirstRow);
    }
    if (mpScrollBarH && mfVisibleColumns != 0.0f) {
        int32_t columns = mnMaxColumns;
        if ((columns == -1 || columns == 0) && (mnFlags & 0x8000)) {
            static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot07(0, static_cast<int32_t>(mfVisibleColumns));
            static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot15(0x7fffffff, 0x7fffffff);
        } else {
            int32_t extent = columns;
            if (!(mnFlags & 0x10000)) {
                if (range.v[0] == -1) {
                    reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
                }
                extent = range.v[2] + 1;
            }
            int32_t position = extent - static_cast<int32_t>(mfVisibleColumns);
            if (position < 0) {
                position = 0;
            }
            static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot07(0, position);
            static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot15(position, static_cast<int32_t>(extent / mfVisibleColumns + 1.0f));
        }
        static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot05(mnFirstColumn);
    }
    return true;
}
#endif

// The drawing buffer as the grid calls it: slot 6 begins a mode, 7 ends it, 20 fills a rectangle.
struct Buffer_add578 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual bool Slot06(uint32_t mode);
    virtual void Slot07(uint32_t mode);
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void Slot20(uint32_t color, void* rect, uint32_t flag);
    virtual void D21();
    virtual void D22();
    virtual void D23();
    virtual void D24();
    virtual void D25();
    virtual void D26();
    virtual void D27();
    virtual void D28();
    virtual void Slot29(void* bitmap, void* source, void* target, void* clip);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009a60bb score 107
void cUnk00add578::DrawCellBackground(void* infoArg)
{
    OwnerDraw_add578* info = static_cast<OwnerDraw_add578*>(infoArg);
    uint32_t flags = mnFlags;
    Quad_add578 area = *info->mpRect1;
    if ((flags & 0x20) && mnGridColorA != 0x40000000) {
        area.v[0] += mnBorderOffsetA;
    }
    if ((flags & 0x40) && mnGridColorB != 0x40000000) {
        area.v[1] += mnBorderOffsetB;
    }
    Quad_add578 clip = area;
    if (info->mpRect2) {
        clip.Fn0048ed90(info->mpRect2);
    }
    uint32_t color = info->mbSelected ? info->mpFormat->mnColors[5] : info->mpFormat->mnColors[1];
    if (color != 0x40000000 && !(flags & 0x80000)) {
        Buffer_add578* buffer = static_cast<Buffer_add578*>(info->mpBuffer);
        if (buffer->Slot06(0x8001)) {
            buffer->Slot20(color, &clip, 0);
            buffer->Slot07(0x8001);
        }
    }
}
#endif

// FUNCTION: 0x009aa91a
void cUnk00add578::Fn009aa91a(int32_t column, int32_t row, void* windowArg, bool stretchWidth, bool stretchHeight)
{
    WinObj_add578* window = static_cast<WinObj_add578*>(windowArg);
    CellData_add578 record(1, column, row, window, 0, 0);
    window->Slot01();
    window->Slot24();
    window->Slot68(0x800, 0);
    reinterpret_cast<cWinView_add578*>(reinterpret_cast<char*>(this) + 4)->Slot14(window);
    reinterpret_cast<WinMap_add578*>(mCellWindows)->Fn009a999d(record);
    Fn009a6c45(column, row, window, stretchWidth, stretchHeight);
}

// Makes the cell at (column, row) if it does not exist, with a format of its own.
inline CellFormat_add578* FormatOf_add578(CellData_add578** found)
{
    CellData_add578* cell = *found;
    if (cell->mpFormat == 0) {
        cell->mpFormat = new CellFormat_add578;
    }
    return static_cast<CellFormat_add578*>(cell->mpFormat);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ac866 score 56
bool cUnk00add578::Slot91_add348(uint32_t column, uint32_t row, uint32_t index, uint32_t color)
{
    if (reinterpret_cast<cSelf_add578*>(this)->Slot54(column, row)) {
        CellData_add578** found = 0;
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        if (cells->GetCellPtr(column, row, &found) && found) {
            FormatOf_add578(found)->mnColors[index] = color;
        } else {
            CellData_add578* cell = new CellData_add578;
            cell->mpFormat = new CellFormat_add578;
            static_cast<CellFormat_add578*>(cell->mpFormat)->mnColors[index] = color;
            cells->InsertCell(column, row, &cell, 0);
        }
        Fn009a5faa();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ac960 score 54
bool cUnk00add578::Slot92_add348(uint32_t column, uint32_t row, uint32_t wrapping)
{
    if (reinterpret_cast<cSelf_add578*>(this)->Slot54(column, row)) {
        CellData_add578** found = 0;
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        if (cells->GetCellPtr(column, row, &found) && found) {
            FormatOf_add578(found)->mnWrapping = static_cast<uint8_t>(wrapping);
        } else {
            CellData_add578* cell = new CellData_add578;
            cell->mpFormat = new CellFormat_add578;
            static_cast<CellFormat_add578*>(cell->mpFormat)->mnWrapping = static_cast<uint8_t>(wrapping);
            cells->InsertCell(column, row, &cell, 0);
        }
        Fn009a5faa();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009aca52 score 66
bool cUnk00add578::Slot93_add348(uint32_t column, uint32_t row, uint32_t columnAlignment, uint32_t rowAlignment)
{
    if (reinterpret_cast<cSelf_add578*>(this)->Slot54(column, row)) {
        CellData_add578** found = 0;
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        if (cells->GetCellPtr(column, row, &found) && found) {
            FormatOf_add578(found)->mnColumnAlignment = static_cast<uint8_t>(columnAlignment);
            static_cast<CellFormat_add578*>((*found)->mpFormat)->mnRowAlignment = static_cast<uint8_t>(rowAlignment);
        } else {
            CellData_add578* cell = new CellData_add578;
            cell->mpFormat = new CellFormat_add578;
            static_cast<CellFormat_add578*>(cell->mpFormat)->mnColumnAlignment = static_cast<uint8_t>(columnAlignment);
            static_cast<CellFormat_add578*>(cell->mpFormat)->mnRowAlignment = static_cast<uint8_t>(rowAlignment);
            cells->InsertCell(column, row, &cell, 0);
        }
        Fn009a5faa();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009acb56 score 66
bool cUnk00add578::Slot94_add348(uint32_t column, uint32_t row, uint32_t width, uint32_t color)
{
    if (reinterpret_cast<cSelf_add578*>(this)->Slot54(column, row)) {
        CellData_add578** found = 0;
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        if (cells->GetCellPtr(column, row, &found) && found) {
            FormatOf_add578(found)->mnBorderWidth = static_cast<uint8_t>(width);
            static_cast<CellFormat_add578*>((*found)->mpFormat)->mnBorderColor = color;
        } else {
            CellData_add578* cell = new CellData_add578;
            cell->mpFormat = new CellFormat_add578;
            static_cast<CellFormat_add578*>(cell->mpFormat)->mnBorderWidth = static_cast<uint8_t>(width);
            static_cast<CellFormat_add578*>(cell->mpFormat)->mnBorderColor = color;
            cells->InsertCell(column, row, &cell, 0);
        }
        Fn009a5faa();
        return true;
    }
    return false;
}
#endif

// The text of a cell as a standard string (start and finish pointers).
struct Str_add578 {
    const char* mpStart;
    const char* mpFinish;
    // STUB: 0x004427f0
    uint32_t Find(const char* text, uint32_t position, uint32_t length);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009a9892 score 46
bool cUnk00add578::Slot133_add348(uint32_t textArg, uint32_t length, uint32_t column0, uint32_t columns, uint32_t row0, uint32_t rows, uint32_t outColumn, uint32_t outRow, uint32_t exact)
{
    const char* text = static_cast<const char*>(Ptr_add578(textArg));
    if (text == 0) {
        return false;
    }
    if (length == 0xffffffff || length == 0) {
        length = strlen(text);
    }
    Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
    MatIter_add578 it = cells->Fn009a935d();
    MatIter_add578 end(cells, cells->mRows.mpHeader, 0);
    if (it.Fn0095bc74(&end)) {
        return false;
    }
    do {
        CellData_add578* cell = static_cast<CellData_add578*>(static_cast<CellNode_add578*>(it.mpCell)->mpValue);
        if (cell && cell->mnColumn >= static_cast<int32_t>(column0)
            && (columns == 0x7fffffff || cell->mnColumn < static_cast<int32_t>(column0 + columns))
            && cell->mnRow >= static_cast<int32_t>(row0)
            && (rows == 0x7fffffff || cell->mnRow < static_cast<int32_t>(row0 + rows))
            && cell->mnType == 2) {
            Text_add578* contents = static_cast<Text_add578*>(cell->mpData);
            if (contents) {
                if (!static_cast<uint8_t>(exact) || static_cast<uint32_t>(contents->mpEnd - contents->mpBegin) == length) {
                    Str_add578* string = reinterpret_cast<Str_add578*>(&contents->mpBegin);
                    if (string->Find(text, 0, length) < static_cast<uint32_t>(string->mpFinish - string->mpStart)) {
                        *static_cast<int32_t*>(Ptr_add578(outColumn)) = cell->mnColumn;
                        *static_cast<int32_t*>(Ptr_add578(outRow)) = cell->mnRow;
                        return true;
                    }
                }
            }
        }
        it.Fn009a903e();
    } while (!it.Fn0095bc74(&end));
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ab46a score 100
bool cUnk00add578::Fn009ab46a(uint32_t unused1, uint32_t unused2, void* sourceArg, int32_t column, int32_t row, void* cellArg)
{
    CellData_add578* source = static_cast<CellData_add578*>(sourceArg);
    CellData_add578* cell = static_cast<CellData_add578*>(cellArg);
    if (cell) {
        DisposeOfCellData(column, row, cell, false);
    }
    if (source->mnType == 1) {
        return false;
    }
    if (cell == 0) {
        cell = new CellData_add578;
    }
    cell->mnType = source->mnType;
    cell->mnColumn = column;
    cell->mnRow = row;
    cell->mpData = 0;
    cell->mpFormat = 0;
    cell->mnExtraData = 0;
    cell->mnWindowFlags = source->mnWindowFlags;
    switch (source->mnType) {
    case 2: {
        cRZString* text = static_cast<cRZString*>(source->mpData);
        if (text) {
            cell->mpData = new cRZString(*text);
        } else {
            cell->mpData = new cRZString;
        }
        break;
    }
    case 4: {
        cIGZUnknown* bitmap = static_cast<cIGZUnknown*>(source->mpData);
        if (bitmap) {
            bitmap->AddRef();
        }
        cell->mpData = bitmap;
        break;
    }
    }
    if (source->mpFormat) {
        CellFormat_add578* format = new CellFormat_add578;
        cell->mpFormat = format;
        *format = *static_cast<CellFormat_add578*>(source->mpFormat);
        if (format->mpFont) {
            format->mpFont->AddRef();
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ac02f score 53
bool Matrix_add578::Fn009ac02f(int32_t column, int32_t row, const CellFormatExtra_add578& format, void* old)
{
    if (row < mnMinRow || column < mnMinColumn || row > mnMaxRow || column > mnMaxColumn) {
        return false;
    }
    TreeNode_add578* rowNode = mRows.Find(row);
    if (rowNode != mRows.mpHeader) {
        CellsTree_add578* cells = &static_cast<RowNode_add578*>(rowNode)->mRow.mCells;
        TreeNode_add578* cell = cells->Find(column);
        if (cell != cells->mpHeader) {
            if (old) {
                *static_cast<CellFormatExtra_add578*>(old) = static_cast<FmtCellNode_add578*>(cell)->mFormat;
            }
            static_cast<FmtCellNode_add578*>(cell)->mFormat = format;
        } else {
            FmtEntry_add578 entry(column, FmtValue_add578(column, format));
            reinterpret_cast<IntTreeA_add578*>(cells)->Fn009a94ca(reinterpret_cast<const KeyValue_add578&>(entry));
            mnCellCount++;
        }
    } else {
        FmtPair_add578 pair(row, FmtRow_add578(row));
        InsertResult_add578 inserted = reinterpret_cast<IntTreeB_add578*>(&mRows)->Fn009abb8d(reinterpret_cast<const KeyValue_add578&>(pair));
        FmtEntry_add578 entry(column, FmtValue_add578(column, format));
        reinterpret_cast<IntTreeA_add578*>(&static_cast<RowNode_add578*>(inserted.mpNode)->mRow.mCells)->Fn009a94ca(reinterpret_cast<const KeyValue_add578&>(entry));
        mnCellCount++;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ac741 score 115
bool cUnk00add578::Slot90_add348(uint32_t column, uint32_t row, uint32_t fontArg)
{
    if (reinterpret_cast<cSelf_add578*>(this)->Slot54(column, row)) {
        cIGZUnknown* font = static_cast<cIGZUnknown*>(Ptr_add578(fontArg));
        if (font) {
            font->AddRef();
        }
        CellData_add578** found = 0;
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        if (cells->GetCellPtr(column, row, &found) && found) {
            CellFormat_add578* format = FormatOf_add578(found);
            if (format->mpFont) {
                format->mpFont->Release();
            }
            format->mpFont = font;
        } else {
            CellData_add578* cell = new CellData_add578;
            cell->mpFormat = new CellFormat_add578;
            static_cast<CellFormat_add578*>(cell->mpFormat)->mpFont = font;
            cells->InsertCell(column, row, &cell, 0);
        }
        Fn009a5faa();
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009aa477 score 117
bool cUnk00add578::Slot44_add348(uint32_t column, uint32_t row, uint32_t add)
{
    bool changed = false;
    if (static_cast<uint8_t>(reinterpret_cast<cSelf_add578*>(this)->Slot45(column, row)) != static_cast<uint8_t>(add)) {
        Coord_add578 coord;
        coord.mnColumn = column;
        coord.mnRow = row;
        List_add578* list = reinterpret_cast<List_add578*>(&mpSelection);
        int32_t count = list->Size();
        Tag_add578 tag;
        if (static_cast<uint8_t>(add)) {
            if (count < mnSelectionRuleB) {
                list->PushBack(coord);
                changed = true;
            }
        } else if (mnSelectionRuleA == 0) {
            ListNode_add578* node = list->mpHead->mpNext;
            while (node != list->mpHead) {
                if (static_cast<int32_t>(column) == node->mnColumn) {
                    ListNode_add578* current = node;
                    node = node->mpNext;
                    list->Erase(tag, NodeIter_add578(reinterpret_cast<TreeNode_add578*>(current)));
                    changed = true;
                } else {
                    node = node->mpNext;
                }
            }
        } else if (mnSelectionRuleA == 1) {
            ListNode_add578* node = list->mpHead->mpNext;
            while (node != list->mpHead) {
                if (static_cast<int32_t>(row) == node->mnRow) {
                    ListNode_add578* current = node;
                    node = node->mpNext;
                    list->Erase(tag, NodeIter_add578(reinterpret_cast<TreeNode_add578*>(current)));
                    changed = true;
                } else {
                    node = node->mpNext;
                }
            }
        } else {
            ListNode_add578* node = list->mpHead->mpNext;
            while (node != list->mpHead) {
                if (static_cast<int32_t>(column) == node->mnColumn && static_cast<int32_t>(row) == node->mnRow) {
                    ListNode_add578* current = node;
                    node = node->mpNext;
                    list->Erase(tag, NodeIter_add578(reinterpret_cast<TreeNode_add578*>(current)));
                    changed = true;
                } else {
                    node = node->mpNext;
                }
            }
        }
    }
    Fn009a5faa();
    return changed;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ae5ac score 52
bool cUnk00add578::Slot100_add348(uint32_t startArg, uint32_t countArg, uint32_t mode)
{
    if (mode == 0) {
        mode = 2;
    }
    if (mode != 2 && mode != 4 && mode != 1) {
        mode = 1;
    }
    int32_t start = startArg;
    int32_t count = countArg;
    if (count < 0) {
        return false;
    }
    if (count > 0) {
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        UserCell_add578* list = static_cast<UserCell_add578*>(::operator new(cells->GetCellCountForRange(start, start + count - 1, 0, 0x7fffffff) * sizeof(UserCell_add578)));
        int32_t found = cells->GetCellRange(start, start + count - 1, 0, 0x7fffffff, list);
        for (UserCell_add578* entry = list; found > 0; found--, entry++) {
            DisposeOfCellData(entry->mnColumn, entry->mnRow, entry->mpCell, true);
            entry->mpCell = 0;
        }
        ::operator delete(list);
        cells->Fn009ab75e(start, count);
        if (mode == 1) {
            SetSizeCachedActualForColumn(start, 1, -1);
        } else if (mode == 2) {
            SetSizeCachedActualForColumn(start, 0x7fffffff, -1);
        } else if (mode == 4) {
            SetSizeCachedActualForColumn(0, start + 1, -1);
        }
        if (mode == 2 || mode == 4) {
            MakeRoomForColumn(start, -count, mode);
        }
        mbE4 = 1;
        Fn009a5faa();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ae6df score 49
bool cUnk00add578::Slot101_add348(uint32_t startArg, uint32_t countArg, uint32_t mode)
{
    if (mode == 0) {
        mode = 3;
    }
    if (mode != 3 && mode != 5 && mode != 1) {
        mode = 1;
    }
    int32_t start = startArg;
    int32_t count = countArg;
    if (count < 0) {
        return false;
    }
    if (count > 0) {
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        UserCell_add578* list = static_cast<UserCell_add578*>(::operator new(cells->GetCellCountForRange(0, 0x7fffffff, start, start + count - 1) * sizeof(UserCell_add578)));
        int32_t found = cells->GetCellRange(0, 0x7fffffff, start, start + count - 1, list);
        for (UserCell_add578* entry = list; found > 0; found--, entry++) {
            DisposeOfCellData(entry->mnColumn, entry->mnRow, entry->mpCell, true);
            entry->mpCell = 0;
        }
        ::operator delete(list);
        cells->Fn009ab716(start, count);
        if (mode == 1) {
            SetSizeCachedActualForRow(start, 1, -1);
        } else if (mode == 3) {
            SetSizeCachedActualForRow(start, 0x7fffffff, -1);
        } else if (mode == 5) {
            SetSizeCachedActualForRow(0, start + 1, -1);
        }
        if (mode == 3 || mode == 5) {
            MakeRoomForRow(start, -count, mode);
        }
        mbE4 = 1;
        Fn009a5faa();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009add09 score 42
void cUnk00add578::Slot118_add348(uint32_t startColumn, uint32_t count)
{
    bool changed = false;
    int32_t n = count;
    if (n != 0) {
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        for (; n != 0; n--, startColumn++) {
            int32_t widest = -1;
            MatIter_add578 it = cells->Fn009a9122(startColumn);
            MatIter_add578 end(cells, cells->mRows.mpHeader, 0);
            while (!EqualA_add578(it, end)) {
                CellData_add578* cell = *reinterpret_cast<CellData_add578**>(static_cast<char*>(it.mpCell) + 4);
                if (cell && cell->mnType == 1 && cell->mpData) {
                    int32_t width = static_cast<WinObj_add578*>(cell->mpData)->Slot41();
                    if (widest == -1 || width > widest) {
                        widest = width;
                    }
                }
                it.Fn009a8fec();
            }
            if (widest != -1) {
                Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mColumnFormats);
                CellFormatExtra_add578* format;
                bool have = formats->GetCellPtr(startColumn, 0, &format);
                if (!have) {
                    CellFormatExtra_add578 fresh;
                    formats->Fn009ac02f(startColumn, 0, fresh, 0);
                    have = formats->GetCellPtr(startColumn, 0, &format);
                }
                if (have) {
                    int16_t cached = format->mnCachedSize;
                    if (cached == -1 || cached < widest) {
                        format->mnCachedSize = static_cast<int16_t>(widest);
                        changed = true;
                    }
                }
            }
        }
        if (changed) {
            SetSizeCachedActualForRow(0, 0x7fffffff, -1);
            mbE4 = 1;
            Fn009a5faa();
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009aeb66 score 125
bool cUnk00add578::Slot114_add348(uint32_t columnArg, uint32_t rowArg, uint32_t bitmapArg, uint32_t mode)
{
    if (mode == 0) {
        mode = 1;
    }
    int32_t column = columnArg;
    int32_t row = rowArg;
    int32_t other = columnArg;
    int32_t extra = rowArg;
    Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
    if (column == 0x7fffffff) {
        bool useLast = false;
        if (row == 0x7fffffff) {
            column = cells->Fn009a9225(&other);
            if (column == static_cast<int32_t>(0x80000000)) {
                column = 0;
            }
            useLast = column != 0x7fffffff;
        }
        if (!useLast) {
            if (!cells->GetMinMaxUsedColForRow(row, extra, other)) {
                column = 0;
            } else {
                column = other + 1;
            }
        }
    }
    if (row == 0x7fffffff) {
        if (!cells->GetMinMaxUsedRowForCol(column, extra, other)) {
            row = 0;
        } else {
            row = other + 1;
        }
    }
    if (reinterpret_cast<cSelf_add578*>(this)->Slot54(column, row)) {
        cIGZUnknown* bitmap = static_cast<cIGZUnknown*>(Ptr_add578(bitmapArg));
        if (bitmap) {
            bitmap->AddRef();
            MakeRoom(column, row, 1, mode);
            CellData_add578* cell = new CellData_add578;
            cell->mnType = 4;
            cell->mnColumn = column;
            cell->mnRow = row;
            cell->mpData = bitmap;
            cells->InsertCell(column, row, &cell, 0);
            mbE4 = 1;
            Fn009a5faa();
        } else {
            Slot96_add348(column, row);
        }
        mnLastColumn = column;
        mnLastRow = row;
        return true;
    }
    Slot96_add348(column, row);
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009aabc6 score 8
List_add578& List_add578::Fn009aabc6(const List_add578& other)
{
    if (this != &other) {
        ListNode_add578* sourceHead = other.mpHead;
        ListNode_add578* source = sourceHead->mpNext;
        ListNode_add578* head = mpHead;
        ListNode_add578* target = head->mpNext;
        while (target != head && source != sourceHead) {
            ListNode_add578* current = source;
            source = source->mpNext;
            ListNode_add578* destination = target;
            target = target->mpNext;
            destination->mnColumn = current->mnColumn;
            destination->mnRow = current->mnRow;
        }
        if (source == sourceHead) {
            Tag_add578 tag;
            EraseRange(tag, NodeIter_add578(reinterpret_cast<TreeNode_add578*>(target)), NodeIter_add578(reinterpret_cast<TreeNode_add578*>(head)));
        } else {
            reinterpret_cast<Worker_add578*>(this)->Fn008940cd(Iter_add578(head), source, sourceHead);
        }
    }
    return *this;
}
#endif

// The message the grid sends its owner when the selection moves.
struct SelectMsg_add578 {
    uint32_t mnId;
    void* mpGrid;
    void* mpData;
    uint32_t mnZero;
};

#ifdef OB_DRAFTS
// CLOSE: 0x009a85b6 score 215
void cUnk00add578::DoArrowKey(uint32_t key, uint32_t flags)
{
    bool extend = (flags & 1) != 0;
    int32_t row = 1;
    int32_t column = 0;
    Quad_add578 range = { { 0, 0, 0, 0 } };
    reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
    List_add578* list = reinterpret_cast<List_add578*>(&mpSelection);
    if (!list->IsEmpty()) {
        ListNode_add578* last = list->mpHead->mpPrev;
        column = last->mnColumn;
        row = last->mnRow;
    }
    if (key == 0x25) {
        if (column <= 0) {
            Slot141_add578(2);
            return;
        }
        column--;
    } else if (key == 0x26) {
        if (row <= 0) {
            Slot141_add578(2);
            return;
        }
        row--;
    } else if (key == 0x27) {
        int32_t edge = mnMaxColumns;
        if ((edge == -1 || edge == 0) && (mnFlags & 0x8000)) {
            column++;
        } else {
            uint32_t bound = mnFlags & 0x8000;
            if (bound == 0) {
                edge = range.v[2] + 1;
            }
            edge--;
            if (column < edge) {
                column++;
            } else if (bound) {
                Slot141_add578(2);
                return;
            }
        }
    } else if (key == 0x28) {
        int32_t edge = mnMaxRows;
        if ((edge == -1 || edge == 0) && (mnFlags & 0x10000)) {
            row++;
        } else {
            uint32_t bound = mnFlags & 0x10000;
            if (bound == 0) {
                edge = range.v[3] + 1;
            }
            edge--;
            if (row < edge) {
                row++;
            } else if (bound) {
                Slot141_add578(2);
                return;
            }
        }
    } else {
        return;
    }
    if (!list->IsEmpty() && !extend) {
        list->Clear();
    }
    SelectMsg_add578 message;
    message.mnZero = 0;
    message.mpData = &column;
    message.mnId = 0x9a1552d2;
    message.mpGrid = this;
    reinterpret_cast<cWinView_add578*>(reinterpret_cast<char*>(this) + 4)->SendMsg_2(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) + 0x50), &message);
    Slot44_add348(column, row, 1);
    if (key == 0x25) {
        if (column < mnFirstColumn) {
            Slot35_add348(column);
        }
    } else if (key == 0x26) {
        if (row < mnFirstRow) {
            Slot36_add348(row);
        }
    } else if (key == 0x27) {
        if (!(static_cast<float>(column) < static_cast<float>(mnFirstColumn) + mfVisibleColumns)) {
            Slot35_add348(static_cast<int32_t>(column - mfVisibleColumns + 1.0f));
        }
    } else if (key == 0x28) {
        if (!(static_cast<float>(row) < static_cast<float>(mnFirstRow) + mfVisibleRows)) {
            Slot36_add348(static_cast<int32_t>(row - mfVisibleRows + 1.0f));
        }
    }
    SetScrollBarValues();
    mbE4 = 1;
    Fn009a5faa();
}
#endif

// The target window the grid sends its messages to (a field of the window base).
inline uint32_t TargetOf_add578(cUnk00add578* p)
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(p) + 0x50);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009a8d6d score 52
bool cUnk00add578::GZOnKeyDown(uint32_t key, uint32_t flags)
{
    cWinView_add578* win = reinterpret_cast<cWinView_add578*>(reinterpret_cast<char*>(this) + 4);
    bool control = ((flags >> 2) & 1) != 0;
    if (win->Slot67(2)) {
        switch (key) {
        case 0x1b: {
            Msg_add578 message;
            message.mnZero = 0;
            message.mnKey = 0x1b;
            message.mnFlags = flags;
            message.mnType = 5;
            win->SendMsg_2(TargetOf_add578(this), &message);
            break;
        }
        case 0x21:
            if (!control) {
                Fn009a5f23(false);
            } else {
                Fn009a5f48(false);
            }
            break;
        case 0x22:
            if (!control) {
                Fn009a5f23(true);
            } else {
                Fn009a5f48(true);
            }
            break;
        case 0x23: {
            Quad_add578 range = { { 0, 0, 0, 0 } };
            if (!(mnFlags & 0x10000) || !(mnFlags & 0x8000)) {
                reinterpret_cast<cSelf_add578*>(this)->Slot50(&range);
            }
            if (!(mnFlags & 0x8000)) {
                Slot35_add348(range.v[2]);
            } else if (mnMaxColumns != -1 && mnMaxColumns != 0) {
                Slot35_add348(mnMaxColumns - 1);
            }
            if (!(mnFlags & 0x10000)) {
                Slot36_add348(range.v[3]);
            } else if (mnMaxRows != -1 && mnMaxRows != 0) {
                Slot36_add348(mnMaxRows - 1);
            }
            break;
        }
        case 0x24:
            Slot37_add348(0, 0);
            break;
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
            DoArrowKey(key, flags);
            break;
        case 0x2d:
            if (static_cast<int8_t>(mnFlags) < 0) {
                mnFlags &= 0xffffff7f;
            } else {
                mnFlags |= 0x80;
            }
            break;
        }
        SelectMsg_add578 notice;
        notice.mnZero = 0;
        notice.mpData = reinterpret_cast<void*>(static_cast<uintptr_t>(key));
        notice.mpGrid = this;
        notice.mnId = 0x9a1552d5;
        win->SendMsg_2(TargetOf_add578(this), &notice);
    }
    return true;
}
#endif

// The window manager as the grid calls it: slot 29 captures the mouse for a window.
struct Manager_add578 {
    virtual void D0();
    virtual void D1();
    virtual void D2();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
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
    virtual void Slot29(void* window);
};

// The message a mouse button sends a scroll bar.
struct MouseMsg_add578 {
    uint32_t mnType;
    int32_t mnX;
    int32_t mnY;
    uint32_t mnFlags;
};

#ifdef OB_DRAFTS
// CLOSE: 0x009a7826 score 24
bool cUnk00add578::GZOnMouseUpL(uint32_t x, uint32_t y, uint32_t flags)
{
    Win_add578* win = WinOf_add578(this);
    cWinView_add578* view = reinterpret_cast<cWinView_add578*>(win);
    if (win->Fn0099be0a() && Slot13_add348(0x40000) && view->Slot121(x, y)) {
        if (mpScrollBarV) {
            int32_t px = x;
            int32_t py = y;
            WinObj_add578* bar = static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot03();
            view->Slot61(bar, &px, &py);
            if (px >= 0 && py >= 0 && px < static_cast<int32_t>(bar->Slot41()) && py < static_cast<int32_t>(bar->Slot42())) {
                static_cast<Manager_add578*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8))->Slot29(bar);
                MouseMsg_add578 message;
                message.mnX = px;
                message.mnY = py;
                message.mnType = 10;
                message.mnFlags = flags;
                bool handled = bar->Slot03(&message);
                win->Fn0099bdfe();
                return handled;
            }
        }
        if (mpScrollBarH) {
            int32_t px = x;
            int32_t py = y;
            WinObj_add578* bar = static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot03();
            view->Slot61(bar, &px, &py);
            if (px >= 0 && py >= 0 && px < static_cast<int32_t>(bar->Slot41()) && py < static_cast<int32_t>(bar->Slot42())) {
                static_cast<Manager_add578*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8))->Slot29(bar);
                MouseMsg_add578 message;
                message.mnX = px;
                message.mnY = py;
                message.mnType = 10;
                message.mnFlags = flags;
                bool handled = bar->Slot03(&message);
                win->Fn0099bdfe();
                return handled;
            }
        }
        int32_t result;
        int32_t data[2];
        if (reinterpret_cast<cSelf_add578*>(this)->Slot110(x, y, &result, data)) {
            mnHitColumn = data[0];
            mnHitRow = data[1];
            mnHitResult = result;
            SelectMsg_add578 notice;
            notice.mnZero = 0;
            notice.mpGrid = this;
            notice.mpData = &mnHitResult;
            notice.mnId = 0x9a1552d3;
            view->SendMsg_2(TargetOf_add578(this), &notice);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a79e6 score 109
bool cUnk00add578::GZOnMouseMove(uint32_t x, uint32_t y, uint32_t flags)
{
    Win_add578* win = WinOf_add578(this);
    cWinView_add578* view = reinterpret_cast<cWinView_add578*>(win);
    if (!win->Fn0099be0a() || !Slot13_add348(0x40000)) {
        int32_t result;
        int32_t data[2];
        if (reinterpret_cast<cSelf_add578*>(this)->Slot110(x, y, &result, data)) {
            if ((static_cast<uint32_t>(result - 2) < 2 || result == 5)
                && (result != mnHoverResult || data[0] != mnHoverColumn || data[1] != mnHoverRow)) {
                int32_t info[3];
                info[0] = result;
                info[1] = data[0];
                info[2] = data[1];
                SelectMsg_add578 notice;
                notice.mnZero = 0;
                notice.mpGrid = this;
                notice.mpData = info;
                notice.mnId = 0x9a1552d6;
                view->SendMsg_2(TargetOf_add578(this), &notice);
            }
            mnHoverResult = result;
            mnHoverColumn = data[0];
            mnHoverRow = data[1];
        }
    } else {
        if (!view->Slot121(x, y)) {
            return true;
        }
        if (mpScrollBarV) {
            int32_t px = x;
            int32_t py = y;
            WinObj_add578* bar = static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot03();
            view->Slot61(bar, &px, &py);
            if (px >= 0 && py >= 0 && px < static_cast<int32_t>(bar->Slot41()) && py < static_cast<int32_t>(bar->Slot42())) {
                static_cast<Manager_add578*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8))->Slot29(bar);
                MouseMsg_add578 message;
                message.mnX = px;
                message.mnY = py;
                message.mnType = 0xd;
                message.mnFlags = flags;
                bool handled = bar->Slot03(&message);
                win->Fn0099bdfe();
                return handled;
            }
        }
        if (mpScrollBarH) {
            int32_t px = x;
            int32_t py = y;
            WinObj_add578* bar = static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot03();
            view->Slot61(bar, &px, &py);
            if (px >= 0 && py >= 0 && px < static_cast<int32_t>(bar->Slot41()) && py < static_cast<int32_t>(bar->Slot42())) {
                static_cast<Manager_add578*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8))->Slot29(bar);
                MouseMsg_add578 message;
                message.mnX = px;
                message.mnY = py;
                message.mnType = 0xd;
                message.mnFlags = flags;
                bool handled = bar->Slot03(&message);
                win->Fn0099bdfe();
                return handled;
            }
        }
        int32_t result;
        int32_t data[2];
        if (reinterpret_cast<cSelf_add578*>(this)->Slot110(x, y, &result, data) && result == 5) {
            if (mnHitResult != 5 || data[0] != mnHitColumn || data[1] != mnHitRow) {
                Slot46_add348();
                Slot44_add348(data[0], data[1], 1);
            }
            mnHitColumn = data[0];
            mnHitRow = data[1];
            mnHitResult = 5;
        }
    }
    return true;
}
#endif

// The double-click timer.
struct Timer_add578 {
    uint8_t mData[0x18];
    // STUB: 0x0088fefb
    bool IsTimerRunning() const;
    // STUB: 0x00890198
    uint32_t GetElapsedTime() const;
    // STUB: 0x0088ff0a
    void Reset();
    // STUB: 0x0089058f
    void Restart();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009a9f6a score 370
bool cUnk00add578::GZOnMouseDownL(uint32_t x, uint32_t y, uint32_t flags)
{
    Win_add578* win = WinOf_add578(this);
    cWinView_add578* view = reinterpret_cast<cWinView_add578*>(win);
    cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
    uint32_t alt = flags >> 2;
    if (!view->Slot67(2)) {
        return true;
    }
    if (win->Fn0099be0a() && Slot13_add348(0x40000)) {
        if (!view->Slot121(x, y)) {
            SelectMsg_add578 notice;
            notice.mnZero = 0;
            notice.mpData = 0;
            notice.mpGrid = this;
            notice.mnId = 0x9a1552d7;
            view->SendMsg_2(TargetOf_add578(this), &notice);
            return true;
        }
        if (mpScrollBarV) {
            int32_t px = x;
            int32_t py = y;
            WinObj_add578* bar = static_cast<ScrollBar_add578*>(mpScrollBarV)->Slot03();
            view->Slot61(bar, &px, &py);
            if (px >= 0 && py >= 0 && px < static_cast<int32_t>(bar->Slot41()) && py < static_cast<int32_t>(bar->Slot42())) {
                static_cast<Manager_add578*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8))->Slot29(bar);
                MouseMsg_add578 message;
                message.mnX = px;
                message.mnY = py;
                message.mnType = 7;
                message.mnFlags = flags;
                bool handled = bar->Slot03(&message);
                win->Fn0099bdfe();
                return handled;
            }
        }
        if (mpScrollBarH == 0) {
            return true;
        }
        int32_t px = x;
        int32_t py = y;
        WinObj_add578* bar = static_cast<ScrollBar_add578*>(mpScrollBarH)->Slot03();
        view->Slot61(bar, &px, &py);
        if (px < 0 || py < 0 || px >= static_cast<int32_t>(bar->Slot41()) || py >= static_cast<int32_t>(bar->Slot42())) {
            return true;
        }
        static_cast<Manager_add578*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8))->Slot29(bar);
        MouseMsg_add578 message;
        message.mnX = px;
        message.mnY = py;
        message.mnType = 7;
        message.mnFlags = flags;
        bool handled = bar->Slot03(&message);
        win->Fn0099bdfe();
        return handled;
    }
    Timer_add578* timer = reinterpret_cast<Timer_add578*>(mTimer);
    bool doubleClick;
    if (!timer->IsTimerRunning() || timer->GetElapsedTime() > 499) {
        timer->Restart();
        doubleClick = false;
    } else {
        timer->Reset();
        doubleClick = true;
    }
    int32_t type;
    int32_t cell[2];
    self->Slot110(x, y, &type, cell);
    List_add578* list = reinterpret_cast<List_add578*>(&mpSelection);
    if (type != 1) {
        if (type == 2) {
            list->Clear();
            Quad_add578 range = { { 0, 0, 0, 0 } };
            self->Slot50(&range);
            for (int32_t column = range.v[0]; column <= range.v[2]; column++) {
                Slot44_add348(column, cell[1], 1);
            }
        } else if (type == 3) {
            list->Clear();
            Quad_add578 range = { { 0, 0, 0, 0 } };
            self->Slot50(&range);
            for (int32_t row = range.v[1]; row <= range.v[3]; row++) {
                Slot44_add348(cell[0], row, 1);
            }
        } else if (type == 5) {
            bool shift = (flags & 1) != 0;
            bool control = ((flags >> 1) & 1) != 0;
            bool altKey = (alt & 1) != 0;
            if (!shift || altKey) {
                if (control) {
                    if (!shift && !altKey) {
                        bool selected = self->Slot45(cell[0], cell[1]);
                        Slot44_add348(cell[0], cell[1], selected ^ 1);
                    }
                } else if (!shift && !altKey) {
                    Slot46_add348();
                    Slot44_add348(cell[0], cell[1], 1);
                }
            } else if (!control) {
                if (list->IsEmpty()) {
                    Coord_add578 coord;
                    coord.mnColumn = cell[0];
                    coord.mnRow = cell[1];
                    list->PushBack(coord);
                } else {
                    ListNode_add578* last = list->mpHead->mpPrev;
                    Rect_add578 box;
                    box.mnLeft = last->mnColumn;
                    box.mnTop = last->mnRow;
                    box.mnRight = cell[0];
                    box.mnBottom = cell[1];
                    box.Fn009a5fc4();
                    for (int32_t column = box.mnLeft; column <= box.mnRight; column++) {
                        for (int32_t row = box.mnTop; row <= box.mnBottom; row++) {
                            Slot44_add348(column, row, 1);
                        }
                    }
                }
            } else if (!shift && !altKey) {
                bool selected = self->Slot45(cell[0], cell[1]);
                Slot44_add348(cell[0], cell[1], selected ^ 1);
            }
        }
    }
    bool changed;
    if (mnHitResult == type && mnHitColumn == cell[0] && mnHitRow == cell[1]) {
        changed = false;
    } else {
        doubleClick = false;
        changed = true;
    }
    mnHitResult = type;
    mnHitColumn = cell[0];
    mnHitRow = cell[1];
    if (doubleClick) {
        SelectMsg_add578 notice;
        notice.mnZero = 0;
        notice.mpGrid = this;
        notice.mpData = &mnHitResult;
        notice.mnId = 0x9a1552d4;
        view->SendMsg_2(TargetOf_add578(this), &notice);
    } else {
        SelectMsg_add578 notice;
        notice.mnZero = 0;
        notice.mpGrid = this;
        notice.mpData = &mnHitResult;
        notice.mnId = 0x9a1552d3;
        view->SendMsg_2(TargetOf_add578(this), &notice);
        if (changed) {
            SelectMsg_add578 changedNotice;
            changedNotice.mnZero = 0;
            changedNotice.mpGrid = this;
            changedNotice.mpData = cell;
            changedNotice.mnId = 0x9a1552d2;
            view->SendMsg_2(TargetOf_add578(this), &changedNotice);
            Fn009a5faa();
        }
    }
    return true;
}
#endif

// Applies the fields of a format that are set (not the "unset" marker) over the ones of another.
inline void MergeFormat_add578(CellFormat_add578* dst, const CellFormat_add578* src)
{
    if (src->mpFont != 0) {
        dst->mpFont = src->mpFont;
    }
    if (src->mnColors[0] != 0x40000000) {
        dst->mnColors[0] = src->mnColors[0];
    }
    if (src->mnColors[1] != 0x40000000) {
        dst->mnColors[1] = src->mnColors[1];
    }
    if (src->mnColors[4] != 0x40000000) {
        dst->mnColors[4] = src->mnColors[4];
    }
    if (src->mnColors[5] != 0x40000000) {
        dst->mnColors[5] = src->mnColors[5];
    }
    if (src->mnColors[2] != 0x40000000) {
        dst->mnColors[2] = src->mnColors[2];
    }
    if (src->mnColors[3] != 0x40000000) {
        dst->mnColors[3] = src->mnColors[3];
    }
    if (src->mnWrapping != 0xff) {
        dst->mnWrapping = src->mnWrapping;
    }
    if (src->mnColumnAlignment != 0) {
        dst->mnColumnAlignment = src->mnColumnAlignment;
    }
    if (src->mnRowAlignment != 0) {
        dst->mnRowAlignment = src->mnRowAlignment;
    }
    if (src->mnBorderWidth != 0) {
        dst->mnBorderWidth = src->mnBorderWidth;
    }
    if (src->mnBorderColor != 0x40000000) {
        dst->mnBorderColor = src->mnBorderColor;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009aa5ce score 210
bool cUnk00add578::Slot84_add348(uint32_t column, uint32_t row, uint32_t out)
{
    CellFormat_add578* result = static_cast<CellFormat_add578*>(Ptr_add578(out));
    CellData_add578** found = 0;
    CellFormat_add578* extra = 0;
    *result = *reinterpret_cast<CellFormat_add578*>(&mpDefaultFont);
    cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
    if (self->Slot88(row, &extra) && extra) {
        MergeFormat_add578(result, extra);
        extra = 0;
    }
    if (self->Slot87(column, &extra) && extra) {
        MergeFormat_add578(result, extra);
        extra = 0;
    }
    if (reinterpret_cast<Matrix_add578*>(mCells)->GetCellPtr(column, row, &found) && found && (*found)->mpFormat) {
        MergeFormat_add578(result, static_cast<CellFormat_add578*>((*found)->mpFormat));
    }
    return true;
}
#endif

// Replaces a format by another one (the font is counted).
inline void AssignFormat_add578(CellFormat_add578* dst, const CellFormat_add578* src)
{
    if (src->mpFont) {
        src->mpFont->AddRef();
    }
    if (dst->mpFont) {
        dst->mpFont->Release();
    }
    *dst = *src;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009ac519 score 229
bool cUnk00add578::Slot85_add348(uint32_t columnArg, uint32_t rowArg, uint32_t formatArg)
{
    int32_t column = columnArg;
    int32_t row = rowArg;
    CellFormat_add578* format = static_cast<CellFormat_add578*>(Ptr_add578(formatArg));
    if (column == -1) {
        if (row == -1) {
            AssignFormat_add578(reinterpret_cast<CellFormat_add578*>(&mpDefaultFont), format);
            return true;
        }
        Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mRowFormats);
        CellFormatExtra_add578* target = 0;
        if (!formats->GetCellPtr(0, row, &target)) {
            CellFormatExtra_add578 fresh;
            formats->Fn009ac02f(0, row, fresh, 0);
            if (!formats->GetCellPtr(0, row, &target)) {
                return false;
            }
        }
        AssignFormat_add578(target, format);
        Fn009a5faa();
        return true;
    }
    if (row == -1) {
        Matrix_add578* formats = reinterpret_cast<Matrix_add578*>(mColumnFormats);
        CellFormatExtra_add578* target = 0;
        if (!formats->GetCellPtr(column, 0, &target)) {
            CellFormatExtra_add578 fresh;
            formats->Fn009ac02f(column, 0, fresh, 0);
            if (!formats->GetCellPtr(column, 0, &target)) {
                return false;
            }
        }
        AssignFormat_add578(target, format);
        Fn009a5faa();
        return true;
    }
    CellData_add578** found = 0;
    Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
    if (cells->GetCellPtr(column, row, &found) && found) {
        CellData_add578* cell = *found;
        if (cell->mpFormat == 0) {
            cell->mpFormat = new CellFormat_add578;
        }
        AssignFormat_add578(static_cast<CellFormat_add578*>(cell->mpFormat), format);
    } else {
        CellData_add578* cell = new CellData_add578;
        cell->mpFormat = new CellFormat_add578;
        AssignFormat_add578(static_cast<CellFormat_add578*>(cell->mpFormat), format);
        cells->InsertCell(column, row, &cell, 0);
    }
    Fn009a5faa();
    return true;
}
#endif

// The "already inside" counter of the recalculation (a function-local static of the original).
// GLOBAL: 0x00bac064
extern int32_t g00bac064;

#ifdef OB_DRAFTS
// CLOSE: 0x009aee63 score 114
bool cUnk00add578::RecalculateAll()
{
    if (g00bac064 < 2) {
        g00bac064++;
        if (mnPauseCount <= 0 && WinOf_add578(this)->Fn0099bc31()) {
            cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
            Quad_add578 grid;
            Quad_add578 cellArea;
            self->Slot08(&grid);
            self->Slot09(&cellArea);
            mfVisibleColumns = 0.0f;
            mnGridWidth = grid.v[2] - grid.v[0];
            int32_t sum = 0;
            int32_t column = mnFirstColumn;
            mnGridHeight = grid.v[3] - grid.v[1];
            mnCellAreaWidth = cellArea.v[2] - cellArea.v[0];
            mnCellAreaHeight = cellArea.v[3] - cellArea.v[1];
            int32_t limit = mnMaxColumns;
            if (limit == -1 || limit == 0) {
                limit = 0x7fffffff;
            }
            if (!(mnFlags & 0x8000)) {
                Quad_add578 range = { { 0, 0, 0, 0 } };
                self->Slot50(&range);
                if (range.v[2] <= limit) {
                    limit = range.v[2] + 1;
                }
            }
            for (; column < limit; column++) {
                int32_t total = sum + GetColumnWidthInternal(column);
                if (total > mnCellAreaWidth) {
                    float fraction = (static_cast<float>(mnCellAreaWidth) - static_cast<float>(sum)) / (static_cast<float>(total) - static_cast<float>(sum));
                    if (fabs(fraction) > 0.05f) {
                        mfVisibleColumns += fraction;
                    }
                    break;
                }
                mfVisibleColumns += 1.0f;
                sum = total;
            }
            int32_t rowLimit = mnMaxRows;
            mfVisibleRows = 0.0f;
            sum = 0;
            int32_t row = mnFirstRow;
            if (rowLimit == -1 || rowLimit == 0) {
                rowLimit = 0x7fffffff;
            }
            if (!(mnFlags & 0x10000)) {
                Quad_add578 range = { { 0, 0, 0, 0 } };
                self->Slot50(&range);
                if (range.v[3] <= rowLimit) {
                    rowLimit = range.v[3] + 1;
                }
            }
            for (; row < rowLimit; row++) {
                int32_t total = sum + GetRowHeightInternal(row);
                if (total > mnCellAreaHeight) {
                    float fraction = (static_cast<float>(mnCellAreaHeight) - static_cast<float>(sum)) / (static_cast<float>(total) - static_cast<float>(sum));
                    if (fabs(fraction) > 0.05f) {
                        mfVisibleRows += fraction;
                    }
                    break;
                }
                mfVisibleRows += 1.0f;
                sum = total;
            }
            int32_t before = (mpScrollBarV ? 2 : 0) | (mpScrollBarH ? 1 : 0);
            TestForPossibleScrollBarAdditionOrRemoval();
            if (before != ((mpScrollBarV ? 2 : 0) | (mpScrollBarH ? 1 : 0))) {
                RecalculateAll();
            }
            if (g00bac064 == 1) {
                PlaceAllCellWindows();
            }
        }
        g00bac064--;
        mbE4 = 0;
    }
    return true;
}
#endif

// The text interface of a text edit window: slot 0 answers an interface id, slot 49 sets the text.
struct TextSub_add578 {
    virtual bool QueryInterface(uint32_t iid, void** ppv);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void D3();
    virtual void D4();
    virtual void D5();
    virtual void D6();
    virtual void D7();
    virtual void D8();
    virtual void D9();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
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
    virtual void Slot49(const char* text, uint32_t length, uint32_t flag);
};

// A text edit window: constructed with its id, its text interface sits at +0xd8.
struct TextEditWin_add578 {
    char mData[0x290];
    // STUB: 0x009c01af
    TextEditWin_add578(uint32_t id);
    static void* operator new(size_t size)
    {
        return ::operator new(size);
    }
};

#ifdef OB_DRAFTS
// CLOSE: 0x009ae8cb score 189
bool cUnk00add578::Slot112_add348(uint32_t columnArg, uint32_t rowArg, uint32_t textArg, uint32_t length, uint32_t modeArg, uint32_t asEdit)
{
    int32_t column = columnArg;
    int32_t row = rowArg;
    int32_t mode = modeArg;
    const char* text = static_cast<const char*>(Ptr_add578(textArg));
    cIGZUnknown* existing = 0;
    cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
    bool haveWindow = column != 0x7fffffff && row != 0x7fffffff && self->Slot115(column, row, &existing);
    if (mode == 0) {
        mode = 1;
    }
    Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
    if (static_cast<uint8_t>(asEdit)) {
        if (haveWindow) {
            TextSub_add578* textSub = 0;
            if (existing->QueryInterface(0x231a1c57, reinterpret_cast<void**>(&textSub))) {
                textSub->Slot49(text, length, 0);
                textSub->Release();
                return true;
            }
            Slot96_add348(column, row);
        }
        TextEditWin_add578* edit = new TextEditWin_add578(0x11ff);
        TextSub_add578* sub = edit ? reinterpret_cast<TextSub_add578*>(reinterpret_cast<char*>(edit) + 0xd8) : 0;
        sub->Slot49(text, length, 0);
        void* window = 0;
        if (!sub->QueryInterface(0x22ba0121, &window)) {
            return true;
        }
        self->Slot116(column, row, window, 1, 1, 1);
        static_cast<cIGZUnknown*>(window)->Release();
        return true;
    }
    if (haveWindow && existing != 0) {
        Slot96_add348(column, row);
    }
    if (column == 0x7fffffff) {
        if (row != 0x7fffffff) {
            int32_t minimum;
            int32_t maximum;
            column = cells->GetMinMaxUsedColForRow(row, minimum, maximum) ? maximum + 1 : 0;
        } else {
            int32_t other;
            column = cells->Fn009a9225(&other);
            if (column == static_cast<int32_t>(0x80000000)) {
                column = 0;
            }
        }
    }
    if (row == 0x7fffffff) {
        int32_t minimum;
        int32_t maximum;
        row = cells->GetMinMaxUsedRowForCol(column, minimum, maximum) ? maximum + 1 : 0;
    }
    if (!reinterpret_cast<cSelf_add578*>(this)->Slot54(column, row)) {
        Slot96_add348(column, row);
        return true;
    }
    if (text == 0) {
        Slot96_add348(column, row);
    } else {
        if (length == 0xffffffff || length == 0) {
            length = strlen(text);
        }
        cRZString* string = new cRZString(text, length);
        MakeRoom(column, row, 1, mode);
        CellData_add578* cell = new CellData_add578;
        cell->mnType = 2;
        cell->mnColumn = column;
        cell->mnRow = row;
        cell->mpData = string;
        cells->InsertCell(column, row, &cell, 0);
        mbE4 = 1;
        Fn009a5faa();
    }
    mnLastColumn = column;
    mnLastRow = row;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009aecb7 score 151
bool cUnk00add578::Slot116_add348(uint32_t columnArg, uint32_t rowArg, uint32_t windowArg, uint32_t stretchWidth, uint32_t stretchHeight, uint32_t mode)
{
    if (mode == 0) {
        mode = 1;
    }
    WinObj_add578* window = static_cast<WinObj_add578*>(Ptr_add578(windowArg));
    cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
    if (self->Slot117(window, 0, 0, 0)) {
        return false;
    }
    int32_t column = columnArg;
    int32_t row = rowArg;
    int32_t other = windowArg;
    int32_t extra = rowArg;
    Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
    if (column == 0x7fffffff) {
        bool useLast = false;
        if (row == 0x7fffffff) {
            column = cells->Fn009a9225(&other);
            if (column == static_cast<int32_t>(0x80000000)) {
                column = 0;
            }
            useLast = column != 0x7fffffff;
        }
        if (!useLast) {
            if (!cells->GetMinMaxUsedColForRow(row, extra, other)) {
                column = 0;
            } else {
                column = other + 1;
            }
        }
    }
    if (row == 0x7fffffff) {
        if (!cells->GetMinMaxUsedRowForCol(column, other, extra)) {
            row = 0;
        } else {
            row = extra + 1;
        }
    }
    if (self->Slot54(column, row)) {
        if (window) {
            window->Slot01();
            MakeRoom(column, row, 1, mode);
            CellData_add578* cell = new CellData_add578;
            cell->mnType = 1;
            cell->mnColumn = column;
            cell->mnRow = row;
            cell->mpData = window;
            if (static_cast<uint8_t>(stretchWidth)) {
                cell->mnWindowFlags |= 1;
            }
            if (static_cast<uint8_t>(stretchHeight)) {
                cell->mnWindowFlags |= 2;
            }
            cells->InsertCell(column, row, &cell, 0);
            Fn009aa91a(column, row, window, static_cast<uint8_t>(stretchWidth) != 0, static_cast<uint8_t>(stretchHeight) != 0);
            reinterpret_cast<cIGZUnknown*>(window)->Release();
            mbE4 = 1;
            Fn009a5faa();
        } else {
            Slot96_add348(column, row);
        }
        mnLastColumn = column;
        mnLastRow = row;
        return true;
    }
    Slot96_add348(column, row);
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ad512 score 108
bool cUnk00add578::Fn009ad512(int32_t sourceColumn, int32_t sourceRow, int32_t targetColumn, int32_t targetRow, bool copy)
{
    cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
    if (!self->Slot54(sourceColumn, sourceRow)) {
        return false;
    }
    if (sourceColumn != targetColumn || sourceRow != targetRow) {
        CellData_add578* source = 0;
        if (!self->Slot54(targetColumn, targetRow)) {
            if (!copy) {
                Slot96_add348(sourceColumn, sourceRow);
            }
            return true;
        }
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        CellData_add578** found;
        if (copy) {
            if (!cells->GetCellPtr(sourceColumn, sourceRow, &found)) {
                Slot96_add348(targetColumn, targetRow);
                return true;
            }
            source = *found;
        } else {
            cells->RemoveCell(sourceColumn, sourceRow, &source);
        }
        if (source == 0) {
            Slot96_add348(targetColumn, targetRow);
            return true;
        }
        CellData_add578* target;
        if (cells->GetCellPtr(targetColumn, targetRow, &found)) {
            target = *found;
        } else {
            target = new CellData_add578;
            cells->InsertCell(targetColumn, targetRow, &target, 0);
        }
        if (copy) {
            Fn009ab46a(sourceColumn, sourceRow, source, targetColumn, targetRow, target);
        } else {
            DisposeOfCellData(targetColumn, targetRow, target, false);
            *target = *source;
            target->mnColumn = targetColumn;
            target->mnRow = targetRow;
            if (target->mnType == 1) {
                Fn009a8f7a(target);
            }
            delete source;
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ad9db score 174
bool cUnk00add578::Slot102_add348(uint32_t sourceArg, uint32_t targetArg, uint32_t countArg, uint32_t moveArg)
{
    int32_t source = sourceArg;
    int32_t target = targetArg;
    int32_t count = countArg;
    bool move = static_cast<uint8_t>(moveArg) != 0;
    if (source != target) {
        int32_t step = 1;
        int32_t first = source;
        int32_t last = source + count - 1;
        if (last >= target && source <= target + count - 1 && target > source) {
            step = -1;
            first = source + count - 1;
            last = source;
        }
        int32_t delta = target - source;
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        for (int32_t column = first;; column += step) {
            int32_t minimum;
            int32_t maximum;
            if (cells->GetMinMaxUsedRowForCol(column, minimum, maximum)) {
                for (int32_t row = minimum; row <= maximum; row++) {
                    SetSizeCachedActualForRow(row, 1, -1);
                    Fn009ad512(column, row, column + delta, row, !move);
                }
            }
            IdMap_add578* extras = reinterpret_cast<IdMap_add578*>(mColumnExtra);
            uint32_t key = column;
            TreeNode_add578* node = extras->Find(key);
            if (node != extras->mpHeader) {
                key = column + delta;
                extras->Index(key) = static_cast<IdNode_add578*>(node)->mnValue;
                if (move) {
                    reinterpret_cast<CellsTree_add578*>(extras)->Fn009a99c0(column);
                }
            }
            HeadingMap_add578* headings = reinterpret_cast<HeadingMap_add578*>(mColumnHeadings);
            uint32_t from = column;
            uint32_t to = column + delta;
            headings->Index(to) = headings->Index(from);
            if (move) {
                reinterpret_cast<Tree_add578*>(headings)->Fn009ab66b(from);
            }
            if (column == last) {
                break;
            }
        }
        mbE4 = 1;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009adb72 score 183
bool cUnk00add578::Slot103_add348(uint32_t sourceArg, uint32_t targetArg, uint32_t countArg, uint32_t moveArg)
{
    int32_t source = sourceArg;
    int32_t target = targetArg;
    int32_t count = countArg;
    bool move = static_cast<uint8_t>(moveArg) != 0;
    if (source != target) {
        int32_t step = 1;
        int32_t first = source;
        int32_t last = source + count - 1;
        if (last >= target && source <= target + count - 1 && target > source) {
            step = -1;
            first = source + count - 1;
            last = source;
        }
        int32_t delta = target - source;
        Matrix_add578* cells = reinterpret_cast<Matrix_add578*>(mCells);
        for (int32_t row = first;; row += step) {
            int32_t minimum;
            int32_t maximum;
            if (cells->GetMinMaxUsedColForRow(row, minimum, maximum)) {
                for (int32_t column = minimum; column <= maximum; column++) {
                    SetSizeCachedActualForColumn(column, 1, -1);
                    Fn009ad512(column, row, column, row + delta, !move);
                }
            }
            IdMap_add578* extras = reinterpret_cast<IdMap_add578*>(mRowExtra);
            uint32_t key = row;
            TreeNode_add578* node = extras->Find(key);
            if (node != extras->mpHeader) {
                key = row + delta;
                extras->Index(key) = static_cast<IdNode_add578*>(node)->mnValue;
                if (move) {
                    reinterpret_cast<CellsTree_add578*>(extras)->Fn009a99c0(row);
                }
            }
            HeadingMap_add578* headings = reinterpret_cast<HeadingMap_add578*>(mRowHeadings);
            uint32_t from = row;
            uint32_t to = row + delta;
            headings->Index(to) = headings->Index(from);
            if (move) {
                reinterpret_cast<Tree_add578*>(headings)->Fn009ab66b(from);
            }
            if (row == last) {
                break;
            }
        }
        mbE4 = 1;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a7c69 score 38
bool cUnk00add578::Slot110_add348(uint32_t xArg, uint32_t yArg, uint32_t resultArg, uint32_t cellArg)
{
    int32_t x = xArg;
    int32_t y = yArg;
    int32_t* result = static_cast<int32_t*>(Ptr_add578(resultArg));
    int32_t* cell = static_cast<int32_t*>(Ptr_add578(cellArg));
    cSelf_add578* self = reinterpret_cast<cSelf_add578*>(this);
    *result = 0;
    cell[0] = 0;
    cell[1] = 0;
    Quad_add578 gridArea;
    self->Slot08(&gridArea);
    if (gridArea.Contains(x, y)) {
        Quad_add578 cellArea;
        self->Slot09(&cellArea);
        if (cellArea.Contains(x, y)) {
            *result = 5;
        } else {
            uint32_t flags = mnFlags;
            if ((flags & 8) && (flags & 0x10)) {
                bool inColumnHeader = y >= mnGutters[1] && y < mnHeaderSizeA;
                bool inRowHeader = x >= mnGutters[0] && x < mnHeaderSizeB;
                if (inColumnHeader) {
                    if (!inRowHeader) {
                        *result = 3;
                    } else {
                        *result = 4;
                    }
                } else if (inRowHeader) {
                    *result = 2;
                }
            }
        }
    } else {
        *result = 1;
    }
    if (*result == 5 || *result == 3 || *result == 2) {
        Quad_add578 area;
        int32_t column = mnFirstColumn;
        int32_t columnEnd = static_cast<int32_t>(ceil(mfVisibleColumns)) + mnFirstColumn;
        for (; column < columnEnd; column++) {
            self->Slot106(column, 0, &area);
            if (x < area.v[2]) {
                cell[0] = column;
                break;
            }
        }
        int32_t row = mnFirstRow;
        int32_t rowEnd = static_cast<int32_t>(ceil(mfVisibleRows)) + mnFirstRow;
        for (; row < rowEnd; row++) {
            self->Slot106(0, row, &area);
            if (y < area.v[3]) {
                cell[1] = row;
                break;
            }
        }
        if (*result == 3) {
            cell[1] = 0;
        } else if (*result == 2) {
            cell[0] = 0;
        }
    }
    return *result != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009a7e52 score 474
void cUnk00add578::DrawCell(void* infoArg)
{
    OwnerDraw_add578* info = static_cast<OwnerDraw_add578*>(infoArg);
    Quad_add578 area = *info->mpRect1;
    uint32_t flags = mnFlags;
    if ((flags & 0x20) && mnGridColorA != 0x40000000) {
        area.v[0] += mnBorderOffsetA;
    }
    if ((flags & 0x40) && mnGridColorB != 0x40000000) {
        area.v[1] += mnBorderOffsetB;
    }
    Quad_add578 clip = area;
    if (info->mpRect2) {
        clip.Fn0048ed90(info->mpRect2);
    }
    Buffer_add578* buffer = static_cast<Buffer_add578*>(info->mpBuffer);
    if (!(mnFlags & 0x20000)) {
        uint32_t color = info->mbSelected ? info->mpFormat->mnColors[5] : info->mpFormat->mnColors[1];
        if (color != 0x40000000 && buffer->Slot06(0x8001)) {
            buffer->Slot20(color, &clip, 0);
            buffer->Slot07(0x8001);
        }
    }
    area.v[0] += mnCellGutters[0];
    area.v[1] += mnCellGutters[1];
    area.v[2] -= mnCellGutters[2];
    area.v[3] -= mnCellGutters[3];
    CellData_add578* cell = info->mpCell;
    if (cell) {
        if (cell->mnType == 4) {
            Image_add578* bitmap = static_cast<Image_add578*>(cell->mpData);
            if (bitmap) {
                Quad_add578 source;
                bitmap->Slot11(&source);
                int32_t width = source.v[2] - source.v[0];
                int32_t height = source.v[3] - source.v[1];
                Quad_add578 target = area;
                target.v[2] = width + target.v[0];
                target.v[3] = height + target.v[1];
                if (info->mpFormat->mnColumnAlignment == 3) {
                    target.v[0] = area.v[0] + ((area.v[2] - area.v[0]) / 2 - width / 2);
                    target.v[2] = target.v[0] + width;
                } else if (info->mpFormat->mnColumnAlignment == 4) {
                    target.v[2] = area.v[2];
                    target.v[0] = area.v[2] - width;
                }
                if (info->mpFormat->mnRowAlignment == 6) {
                    target.v[1] = area.v[1] + ((area.v[3] - area.v[1]) / 2 - height / 2);
                    target.v[3] = target.v[1] + height;
                } else if (info->mpFormat->mnRowAlignment == 7) {
                    target.v[3] = area.v[3];
                    target.v[1] = area.v[3] - height;
                }
                if (mnFlags & 0x20000) {
                    clip.v[2] = info->mpRect3->v[2];
                }
                if (buffer->Slot06(0x8010)) {
                    buffer->Slot29(bitmap, &source, &target, &clip);
                    buffer->Slot07(0x8010);
                }
            }
        } else if (cell->mnType == 2) {
            Text_add578* text = static_cast<Text_add578*>(cell->mpData);
            if (text) {
                Font_add578* font = reinterpret_cast<Font_add578*>(info->mpFormat->mpFont);
                uint32_t style;
                uint32_t color;
                uint32_t background;
                CalcCellDrawingParams(text, info, &area, &style, &color, &background);
                if (mnFlags & 0x20000) {
                    area.v[2] = info->mpRect3->v[2];
                    clip.v[2] = info->mpRect3->v[2];
                }
                if (background != 0x40000000 && (mnFlags & 0x80000)) {
                    const char* start = text->mpBegin;
                    const char* finish = text->mpEnd;
                    for (; start < finish;) {
                        int32_t measured[2];
                        int32_t used = font->Slot41(start, finish - start, area.v[2] - area.v[0], measured, 2);
                        Quad_add578 band;
                        band.v[0] = area.v[0];
                        band.v[1] = area.v[1];
                        band.v[2] = area.v[0] + measured[0];
                        band.v[3] = area.v[3];
                        start += used;
                    }
                }
                font->Slot52(buffer, &area, text->mpBegin, text->mpEnd - text->mpBegin, style, color, background, &clip, 0);
            }
        }
    }
}
#endif
