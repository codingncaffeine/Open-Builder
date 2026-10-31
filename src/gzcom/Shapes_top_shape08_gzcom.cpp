#include "common/types.h"

// The STL allocator's release function (the standard library of the original).
namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

// The header node of an STL tree container.
struct Node_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpLeft;
    Node_top_shape08_gzcom* mpRoot;
    Node_top_shape08_gzcom* mpRight;
    Node_top_shape08_gzcom* mpLast;
};

struct View_0087703d_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    // STUB: 0x00876f57
    void Clear();
    void Fn0087703d();
};

// FUNCTION: 0x0087703d
void View_0087703d_top_shape08_gzcom::Fn0087703d()
{
    Clear();
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_0091af4a_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    // STUB: 0x0091aeba
    void Clear();
    void Fn0091af4a();
};

// FUNCTION: 0x0091af4a
void View_0091af4a_top_shape08_gzcom::Fn0091af4a()
{
    Clear();
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_00949387_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    // STUB: 0x009492a2
    void Clear();
    void Fn00949387();
};

// FUNCTION: 0x00949387
void View_00949387_top_shape08_gzcom::Fn00949387()
{
    Clear();
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_0094958e_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    // STUB: 0x0094939e
    void Clear();
    void Fn0094958e();
};

// FUNCTION: 0x0094958e
void View_0094958e_top_shape08_gzcom::Fn0094958e()
{
    Clear();
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_009dadee_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    // STUB: 0x009dadc5
    void Clear();
    void Fn009dadee();
};

// FUNCTION: 0x009dadee
void View_009dadee_top_shape08_gzcom::Fn009dadee()
{
    Clear();
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_00876f57_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    uint32_t mnSize;
    // STUB: 0x00876f2a
    void Erase(Node_top_shape08_gzcom* node);
    void Fn00876f57();
};

// FUNCTION: 0x00876f57
void View_00876f57_top_shape08_gzcom::Fn00876f57()
{
    if (mnSize != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpRight = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpLast = mpHead;
        mnSize = 0;
    }
}

struct View_00891ee6_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    uint32_t mnSize;
    // STUB: 0x00891eb9
    void Erase(Node_top_shape08_gzcom* node);
    void Fn00891ee6();
};

// FUNCTION: 0x00891ee6
void View_00891ee6_top_shape08_gzcom::Fn00891ee6()
{
    if (mnSize != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpRight = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpLast = mpHead;
        mnSize = 0;
    }
}

struct View_0090d164_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    uint32_t mnSize;
    // STUB: 0x0090d104
    void Erase(Node_top_shape08_gzcom* node);
    void Fn0090d164();
};

// FUNCTION: 0x0090d164
void View_0090d164_top_shape08_gzcom::Fn0090d164()
{
    if (mnSize != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpRight = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpLast = mpHead;
        mnSize = 0;
    }
}

struct View_0090d1b9_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    uint32_t mnSize;
    // STUB: 0x0090d134
    void Erase(Node_top_shape08_gzcom* node);
    void Fn0090d1b9();
};

// FUNCTION: 0x0090d1b9
void View_0090d1b9_top_shape08_gzcom::Fn0090d1b9()
{
    if (mnSize != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpRight = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpLast = mpHead;
        mnSize = 0;
    }
}

struct View_00939017_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    uint32_t mnSize;
    // STUB: 0x00938c50
    void Erase(Node_top_shape08_gzcom* node);
    void Fn00939017();
};

// FUNCTION: 0x00939017
void View_00939017_top_shape08_gzcom::Fn00939017()
{
    if (mnSize != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpRight = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpLast = mpHead;
        mnSize = 0;
    }
}

struct View_00949279_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    uint32_t mnSize;
    // STUB: 0x009491a5
    void Erase(Node_top_shape08_gzcom* node);
    void Fn00949279();
};

// FUNCTION: 0x00949279
void View_00949279_top_shape08_gzcom::Fn00949279()
{
    if (mnSize != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpRight = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpLast = mpHead;
        mnSize = 0;
    }
}

struct View_009492a2_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    uint32_t mnSize;
    // STUB: 0x009491d2
    void Erase(Node_top_shape08_gzcom* node);
    void Fn009492a2();
};

// FUNCTION: 0x009492a2
void View_009492a2_top_shape08_gzcom::Fn009492a2()
{
    if (mnSize != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpRight = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpLast = mpHead;
        mnSize = 0;
    }
}

struct View_0094939e_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    uint32_t mnSize;
    // STUB: 0x009492f0
    void Erase(Node_top_shape08_gzcom* node);
    void Fn0094939e();
};

// FUNCTION: 0x0094939e
void View_0094939e_top_shape08_gzcom::Fn0094939e()
{
    if (mnSize != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpRight = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpLast = mpHead;
        mnSize = 0;
    }
}

struct View_009495a5_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    uint32_t mnSize;
    // STUB: 0x009493c7
    void Erase(Node_top_shape08_gzcom* node);
    void Fn009495a5();
};

// FUNCTION: 0x009495a5
void View_009495a5_top_shape08_gzcom::Fn009495a5()
{
    if (mnSize != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpRight = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpLast = mpHead;
        mnSize = 0;
    }
}

struct View_009dadc5_top_shape08_gzcom {
    Node_top_shape08_gzcom* mpHead;
    uint32_t mnSize;
    // STUB: 0x009dad98
    void Erase(Node_top_shape08_gzcom* node);
    void Fn009dadc5();
};

// FUNCTION: 0x009dadc5
void View_009dadc5_top_shape08_gzcom::Fn009dadc5()
{
    if (mnSize != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpRight = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpLast = mpHead;
        mnSize = 0;
    }
}

