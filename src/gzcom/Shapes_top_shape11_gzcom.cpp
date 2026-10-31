#include "common/types.h"

// The STL allocator's release function (the standard library of the original).
namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct View_94a457_top_shape11_gzcom {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x0094a457
bool View_94a457_top_shape11_gzcom::QueryInterface(uint32_t riid, void** ppvObj)
{
    if (riid == 1 || riid == 0xfceff549u) {
        *ppvObj = this;
        AddRef();
        return true;
    }
    return false;
}

struct View_92b318_top_shape11_gzcom {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x0092b318
bool View_92b318_top_shape11_gzcom::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0x51b11bd:
        *ppvObj = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct View_93348f_top_shape11_gzcom {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef() { return 0; }
};

// FUNCTION: 0x0093348f
bool View_93348f_top_shape11_gzcom::QueryInterface(uint32_t riid, void** ppvObj)
{
    switch (riid) {
    case 1:
    case 0x276c77c8:
        *ppvObj = this;
        AddRef();
        return true;
    default:
        return false;
    }
}

struct Sub_9490c9_top_shape11_gzcom {
    uint32_t mWord;
    // STUB: 0x004e4bb0
    void Copy(const Sub_9490c9_top_shape11_gzcom& other);
};

struct View_9490c9_top_shape11_gzcom {
    uint32_t mFirst;
    Sub_9490c9_top_shape11_gzcom mSecond;
    View_9490c9_top_shape11_gzcom* Fn9490c9(const View_9490c9_top_shape11_gzcom& other);
};

// FUNCTION: 0x009490c9
View_9490c9_top_shape11_gzcom* View_9490c9_top_shape11_gzcom::Fn9490c9(const View_9490c9_top_shape11_gzcom& other)
{
    mFirst = other.mFirst;
    mSecond.Copy(other.mSecond);
    return this;
}

struct Node_9493c7_top_shape11_gzcom;

struct Value_9493c7_top_shape11_gzcom {
    // STUB: 0x009491ff
    void Destroy(uint32_t flag);
};

struct Node_9493c7_top_shape11_gzcom {
    uint32_t mColor;
    Node_9493c7_top_shape11_gzcom* mpParent;
    Node_9493c7_top_shape11_gzcom* mpLeft;
    Node_9493c7_top_shape11_gzcom* mpRight;
    Value_9493c7_top_shape11_gzcom mValue;
};

struct View_9493c7_top_shape11_gzcom {
    void Fn9493c7(Node_9493c7_top_shape11_gzcom* node);
};

// FUNCTION: 0x009493c7
void View_9493c7_top_shape11_gzcom::Fn9493c7(Node_9493c7_top_shape11_gzcom* node)
{
    while (node) {
        Fn9493c7(node->mpRight);
        Node_9493c7_top_shape11_gzcom* left = node->mpLeft;
        node->mValue.Destroy(0);
        _STL::__stl_delete(node);
        node = left;
    }
}

struct Node_91b349_top_shape11_gzcom {
    Node_91b349_top_shape11_gzcom* mpNext;
    Node_91b349_top_shape11_gzcom* mpPrev;
};

struct Iter_91b349_top_shape11_gzcom {
    Node_91b349_top_shape11_gzcom* mpNode;
};

struct View_91b349_top_shape11_gzcom {
    // STUB: 0x0091b2d6
    Node_91b349_top_shape11_gzcom* CreateNode(const uint32_t& x);
    Iter_91b349_top_shape11_gzcom Fn91b349(Iter_91b349_top_shape11_gzcom pos, const uint32_t& x);
};

// FUNCTION: 0x0091b349
Iter_91b349_top_shape11_gzcom View_91b349_top_shape11_gzcom::Fn91b349(Iter_91b349_top_shape11_gzcom pos, const uint32_t& x)
{
    Node_91b349_top_shape11_gzcom* node = CreateNode(x);
    Node_91b349_top_shape11_gzcom* next = pos.mpNode;
    Node_91b349_top_shape11_gzcom* prev = next->mpPrev;
    node->mpNext = next;
    node->mpPrev = prev;
    prev->mpNext = node;
    next->mpPrev = node;
    Iter_91b349_top_shape11_gzcom result;
    result.mpNode = node;
    return result;
}

struct Elem_91e7ab_top_shape11_gzcom {
    uint8_t mBytes[48];
    // STUB: 0x0091e618
    void Copy(const Elem_91e7ab_top_shape11_gzcom& other);
};

// FUNCTION: 0x0091e7ab
Elem_91e7ab_top_shape11_gzcom* Fn0091e7ab(Elem_91e7ab_top_shape11_gzcom* first, uint32_t n, const Elem_91e7ab_top_shape11_gzcom& x)
{
    Elem_91e7ab_top_shape11_gzcom* cur = first;
    uint32_t count = n;
    for (; count > 0; --count, ++cur) {
        if (cur) {
            cur->Copy(x);
        }
    }
    return cur;
}

struct Elem_875161_top_shape11_gzcom;

// STUB: 0x00875148
void Fn00875148_875161(Elem_875161_top_shape11_gzcom* first, Elem_875161_top_shape11_gzcom* last);

struct View_875161_top_shape11_gzcom {
    Elem_875161_top_shape11_gzcom* mpBegin;
    Elem_875161_top_shape11_gzcom* mpEnd;
    void Fn875161();
};

// FUNCTION: 0x00875161
void View_875161_top_shape11_gzcom::Fn875161()
{
    Fn00875148_875161(mpBegin, mpEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct Elem_91f8ef_top_shape11_gzcom;

// STUB: 0x0091f86e
void Fn0091f86e_91f8ef(Elem_91f8ef_top_shape11_gzcom* first, Elem_91f8ef_top_shape11_gzcom* last);

struct View_91f8ef_top_shape11_gzcom {
    Elem_91f8ef_top_shape11_gzcom* mpBegin;
    Elem_91f8ef_top_shape11_gzcom* mpEnd;
    void Fn91f8ef();
};

// FUNCTION: 0x0091f8ef
void View_91f8ef_top_shape11_gzcom::Fn91f8ef()
{
    Fn0091f86e_91f8ef(mpBegin, mpEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct Elem_93de49_top_shape11_gzcom;

// STUB: 0x00981543
void Fn00981543_93de49(Elem_93de49_top_shape11_gzcom* first, Elem_93de49_top_shape11_gzcom* last);

struct View_93de49_top_shape11_gzcom {
    Elem_93de49_top_shape11_gzcom* mpBegin;
    Elem_93de49_top_shape11_gzcom* mpEnd;
    void Fn93de49();
};

// FUNCTION: 0x0093de49
void View_93de49_top_shape11_gzcom::Fn93de49()
{
    Fn00981543_93de49(mpBegin, mpEnd);
    if (mpBegin) {
        _STL::__stl_delete(mpBegin);
    }
}

struct Node_90dbcd_top_shape11_gzcom;

struct Iter_90dbcd_top_shape11_gzcom {
    Node_90dbcd_top_shape11_gzcom* mpNode;
    Iter_90dbcd_top_shape11_gzcom() {}
    Iter_90dbcd_top_shape11_gzcom(const Iter_90dbcd_top_shape11_gzcom& other) : mpNode(other.mpNode) {}
};

struct View_90dbcd_top_shape11_gzcom {
    Node_90dbcd_top_shape11_gzcom* mpNode;
    // STUB: 0x0099d2c2
    Iter_90dbcd_top_shape11_gzcom Insert(Iter_90dbcd_top_shape11_gzcom pos, const uint32_t& x);
    Iter_90dbcd_top_shape11_gzcom End()
    {
        Iter_90dbcd_top_shape11_gzcom it;
        it.mpNode = mpNode;
        return it;
    }
    void Fn90dbcd(const uint32_t& x);
};

// FUNCTION: 0x0090dbcd
void View_90dbcd_top_shape11_gzcom::Fn90dbcd(const uint32_t& x)
{
    Insert(End(), x);
}

struct Node_91ba08_top_shape11_gzcom;

struct Iter_91ba08_top_shape11_gzcom {
    Node_91ba08_top_shape11_gzcom* mpNode;
    Iter_91ba08_top_shape11_gzcom() {}
    Iter_91ba08_top_shape11_gzcom(const Iter_91ba08_top_shape11_gzcom& other) : mpNode(other.mpNode) {}
};

struct View_91ba08_top_shape11_gzcom {
    Node_91ba08_top_shape11_gzcom* mpNode;
    // STUB: 0x0091b349
    Iter_91ba08_top_shape11_gzcom Insert(Iter_91ba08_top_shape11_gzcom pos, const uint32_t& x);
    Iter_91ba08_top_shape11_gzcom End()
    {
        Iter_91ba08_top_shape11_gzcom it;
        it.mpNode = mpNode;
        return it;
    }
    void Fn91ba08(const uint32_t& x);
};

// FUNCTION: 0x0091ba08
void View_91ba08_top_shape11_gzcom::Fn91ba08(const uint32_t& x)
{
    Insert(End(), x);
}

struct Node_9dc0ab_top_shape11_gzcom;

struct Iter_9dc0ab_top_shape11_gzcom {
    Node_9dc0ab_top_shape11_gzcom* mpNode;
    Iter_9dc0ab_top_shape11_gzcom() {}
    Iter_9dc0ab_top_shape11_gzcom(const Iter_9dc0ab_top_shape11_gzcom& other) : mpNode(other.mpNode) {}
};

struct View_9dc0ab_top_shape11_gzcom {
    Node_9dc0ab_top_shape11_gzcom* mpNode;
    // STUB: 0x009dbc43
    Iter_9dc0ab_top_shape11_gzcom Insert(Iter_9dc0ab_top_shape11_gzcom pos, const uint32_t& x);
    Iter_9dc0ab_top_shape11_gzcom End()
    {
        Iter_9dc0ab_top_shape11_gzcom it;
        it.mpNode = mpNode;
        return it;
    }
    void Fn9dc0ab(const uint32_t& x);
};

// FUNCTION: 0x009dc0ab
void View_9dc0ab_top_shape11_gzcom::Fn9dc0ab(const uint32_t& x)
{
    Insert(End(), x);
}

struct Elem_87540b_top_shape11_gzcom {
    uint8_t mBytes[44];
    // STUB: 0x008750ae
    void Copy(const Elem_87540b_top_shape11_gzcom& other);
};

struct Tag_87540b_top_shape11_gzcom {
    Tag_87540b_top_shape11_gzcom() {}
};

struct View_87540b_top_shape11_gzcom {
    uint32_t mpBegin;
    Elem_87540b_top_shape11_gzcom* mpFinish;
    Elem_87540b_top_shape11_gzcom* mpEndOfStorage;
    // STUB: 0x00875337
    void InsertOverflow(Elem_87540b_top_shape11_gzcom* pos, const Elem_87540b_top_shape11_gzcom& x, const Tag_87540b_top_shape11_gzcom& tag, uint32_t n, bool atEnd);
    void Fn87540b(const Elem_87540b_top_shape11_gzcom& x);
};

// FUNCTION: 0x0087540b
void View_87540b_top_shape11_gzcom::Fn87540b(const Elem_87540b_top_shape11_gzcom& x)
{
    if (mpFinish != mpEndOfStorage) {
        if (mpFinish) {
            mpFinish->Copy(x);
        }
        ++mpFinish;
    } else {
        InsertOverflow(mpFinish, x, Tag_87540b_top_shape11_gzcom(), 1, true);
    }
}

struct Elem_91fa1a_top_shape11_gzcom {
    uint8_t mBytes[48];
    // STUB: 0x0091e618
    void Copy(const Elem_91fa1a_top_shape11_gzcom& other);
};

struct Tag_91fa1a_top_shape11_gzcom {
    Tag_91fa1a_top_shape11_gzcom() {}
};

struct View_91fa1a_top_shape11_gzcom {
    uint32_t mpBegin;
    Elem_91fa1a_top_shape11_gzcom* mpFinish;
    Elem_91fa1a_top_shape11_gzcom* mpEndOfStorage;
    // STUB: 0x0091f92a
    void InsertOverflow(Elem_91fa1a_top_shape11_gzcom* pos, const Elem_91fa1a_top_shape11_gzcom& x, const Tag_91fa1a_top_shape11_gzcom& tag, uint32_t n, bool atEnd);
    void Fn91fa1a(const Elem_91fa1a_top_shape11_gzcom& x);
};

// FUNCTION: 0x0091fa1a
void View_91fa1a_top_shape11_gzcom::Fn91fa1a(const Elem_91fa1a_top_shape11_gzcom& x)
{
    if (mpFinish != mpEndOfStorage) {
        if (mpFinish) {
            mpFinish->Copy(x);
        }
        ++mpFinish;
    } else {
        InsertOverflow(mpFinish, x, Tag_91fa1a_top_shape11_gzcom(), 1, true);
    }
}

struct Elem_9baba3_top_shape11_gzcom {
    uint8_t mBytes[40];
    // STUB: 0x009b978d
    void Copy(const Elem_9baba3_top_shape11_gzcom& other);
};

struct Tag_9baba3_top_shape11_gzcom {
    Tag_9baba3_top_shape11_gzcom() {}
};

struct View_9baba3_top_shape11_gzcom {
    uint32_t mpBegin;
    Elem_9baba3_top_shape11_gzcom* mpFinish;
    Elem_9baba3_top_shape11_gzcom* mpEndOfStorage;
    // STUB: 0x009ba538
    void InsertOverflow(Elem_9baba3_top_shape11_gzcom* pos, const Elem_9baba3_top_shape11_gzcom& x, const Tag_9baba3_top_shape11_gzcom& tag, uint32_t n, bool atEnd);
    void Fn9baba3(const Elem_9baba3_top_shape11_gzcom& x);
};

// FUNCTION: 0x009baba3
void View_9baba3_top_shape11_gzcom::Fn9baba3(const Elem_9baba3_top_shape11_gzcom& x)
{
    if (mpFinish != mpEndOfStorage) {
        if (mpFinish) {
            mpFinish->Copy(x);
        }
        ++mpFinish;
    } else {
        InsertOverflow(mpFinish, x, Tag_9baba3_top_shape11_gzcom(), 1, true);
    }
}

struct Elem_9bac34_top_shape11_gzcom {
    uint8_t mBytes[28];
    // STUB: 0x009b97fb
    void Copy(const Elem_9bac34_top_shape11_gzcom& other);
};

struct Tag_9bac34_top_shape11_gzcom {
    Tag_9bac34_top_shape11_gzcom() {}
};

struct View_9bac34_top_shape11_gzcom {
    uint32_t mpBegin;
    Elem_9bac34_top_shape11_gzcom* mpFinish;
    Elem_9bac34_top_shape11_gzcom* mpEndOfStorage;
    // STUB: 0x009ba6f7
    void InsertOverflow(Elem_9bac34_top_shape11_gzcom* pos, const Elem_9bac34_top_shape11_gzcom& x, const Tag_9bac34_top_shape11_gzcom& tag, uint32_t n, bool atEnd);
    void Fn9bac34(const Elem_9bac34_top_shape11_gzcom& x);
};

// FUNCTION: 0x009bac34
void View_9bac34_top_shape11_gzcom::Fn9bac34(const Elem_9bac34_top_shape11_gzcom& x)
{
    if (mpFinish != mpEndOfStorage) {
        if (mpFinish) {
            mpFinish->Copy(x);
        }
        ++mpFinish;
    } else {
        InsertOverflow(mpFinish, x, Tag_9bac34_top_shape11_gzcom(), 1, true);
    }
}

struct Elem_9d5c7e_top_shape11_gzcom {
    uint8_t mBytes[48];
    // STUB: 0x009d582b
    void Copy(const Elem_9d5c7e_top_shape11_gzcom& other);
};

struct Tag_9d5c7e_top_shape11_gzcom {
    Tag_9d5c7e_top_shape11_gzcom() {}
};

struct View_9d5c7e_top_shape11_gzcom {
    uint32_t mpBegin;
    Elem_9d5c7e_top_shape11_gzcom* mpFinish;
    Elem_9d5c7e_top_shape11_gzcom* mpEndOfStorage;
    // STUB: 0x009d5b89
    void InsertOverflow(Elem_9d5c7e_top_shape11_gzcom* pos, const Elem_9d5c7e_top_shape11_gzcom& x, const Tag_9d5c7e_top_shape11_gzcom& tag, uint32_t n, bool atEnd);
    void Fn9d5c7e(const Elem_9d5c7e_top_shape11_gzcom& x);
};

// FUNCTION: 0x009d5c7e
void View_9d5c7e_top_shape11_gzcom::Fn9d5c7e(const Elem_9d5c7e_top_shape11_gzcom& x)
{
    if (mpFinish != mpEndOfStorage) {
        if (mpFinish) {
            mpFinish->Copy(x);
        }
        ++mpFinish;
    } else {
        InsertOverflow(mpFinish, x, Tag_9d5c7e_top_shape11_gzcom(), 1, true);
    }
}

