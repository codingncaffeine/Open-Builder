// The class shapes obclass has to recover, built with the 2003 compiler as the ground truth its output is checked
// against (tools/obcmp/test/classes.sh). Written for the test: component-framework idioms (interfaces without
// vtables, a reference-counted base, several interfaces per class), a base whose constructor is always inlined,
// members that have vtables, objects built inline after operator new, out of line, and on the stack, and virtual
// destructors called through deleting destructors.

#define NOVTABLE __declspec(novtable)

typedef unsigned int uint32;

struct NOVTABLE IUnknownLike {
    virtual bool QueryInterface(uint32 id, void** out) = 0;
    virtual uint32 AddRef() = 0;
    virtual uint32 Release() = 0;
};

struct NOVTABLE IShape : public IUnknownLike {
    virtual int Area() = 0;
    virtual int Sides() = 0;
};

struct NOVTABLE INamed : public IUnknownLike {
    virtual const char* Name() = 0;
};

struct NOVTABLE ISerial : public IUnknownLike {
    virtual bool Write(void* stream) = 0;
    virtual bool Read(void* stream) = 0;
    virtual uint32 Type() = 0;
};

extern "C" void* Alloc(unsigned int);
extern "C" void Free(void*);
// The pure-virtual slot, as the C runtime provides it.
extern "C" int __cdecl _purecall() { return 0; }
// Out of line, as the original's allocator is.
__declspec(noinline) void* operator new(unsigned int n) { return Alloc(n); }
__declspec(noinline) void operator delete(void* p) { Free(p); }

// A member with its own vtable.
class cCounter {
public:
    cCounter() : count(0) {}
    virtual ~cCounter() {}
    virtual void Bump() { ++count; }
    int count;
};

// A plain polymorphic class, no interfaces.
class cNode {
public:
    cNode() : next(0) {}
    virtual ~cNode() { delete next; }
    virtual int Depth() { return next ? next->Depth() + 1 : 0; }
    cNode* next;
};

// Derived from cNode, with a member that has a vtable.
class cLeaf : public cNode {
public:
    cLeaf();
    virtual ~cLeaf();
    virtual int Depth() { return 100; }
    virtual void Touch() { hits.Bump(); }
    cCounter hits;
};

// A shape with three interfaces (primary IShape, then INamed and ISerial).
class cSquare : public IShape, public INamed, public ISerial {
public:
    cSquare(int s);
    virtual ~cSquare();
    bool QueryInterface(uint32 id, void** out);
    uint32 AddRef() { return ++refs; }
    uint32 Release();
    int Area() { return side * side; }
    int Sides() { return 4; }
    const char* Name() { return "square"; }
    bool Write(void*) { return true; }
    bool Read(void*) { return true; }
    uint32 Type() { return 0x5c; }
    int side;
    uint32 refs;
};

// An abstract base (not an interface: it has a vtable, its constructor is inline and always inlined).
class cShapeBase : public IShape, public INamed {
public:
    cShapeBase() : refs(0) {}
    virtual ~cShapeBase() {}
    bool QueryInterface(uint32 id, void** out) {
        if (id == 1) { *out = static_cast<IShape*>(this); AddRef(); return true; }
        if (id == 2) { *out = static_cast<INamed*>(this); AddRef(); return true; }
        return false;
    }
    uint32 AddRef() { return ++refs; }
    uint32 Release() { if (--refs) return refs; delete this; return 0; }
    uint32 refs;
};

class cTriangle : public cShapeBase {
public:
    cTriangle(int b, int h) : base(b), height(h) {}
    int Area() { return base * height / 2; }
    int Sides() { return 3; }
    const char* Name() { return "triangle"; }
    int base, height;
};

// Two levels under the abstract base, with a member that has a vtable.
class cRightTriangle : public cTriangle {
public:
    cRightTriangle(int b, int h);
    ~cRightTriangle();
    const char* Name() { return "right triangle"; }
    cCounter uses;
};

__declspec(noinline) cLeaf::cLeaf() {}
cLeaf::~cLeaf() { hits.count = 0; }

cSquare::cSquare(int s) : side(s), refs(0) {}
cSquare::~cSquare() { side = 0; }
bool cSquare::QueryInterface(uint32 id, void** out) {
    switch (id) {
    case 1: *out = static_cast<IShape*>(this); break;
    case 2: *out = static_cast<INamed*>(this); break;
    case 3: *out = static_cast<ISerial*>(this); break;
    default: return false;
    }
    AddRef();
    return true;
}
uint32 cSquare::Release() {
    if (--refs) return refs;
    delete this;
    return 0;
}

__declspec(noinline) cRightTriangle::cRightTriangle(int b, int h) : cTriangle(b, h) {}
cRightTriangle::~cRightTriangle() { uses.count = -1; }

// Construction sites, exported so the linker keeps them (it drops what nothing refers to, as the original's did):
// inline after new (cSquare, cTriangle, cNode, cCounter) and out of line (cLeaf, cRightTriangle).
#define EXPORT __declspec(dllexport)
EXPORT IShape* MakeShape(int kind, int a, int b) {
    switch (kind) {
    case 0: return new cSquare(a);
    case 1: return new cTriangle(a, b);
    default: return new cRightTriangle(a, b);
    }
}
EXPORT cNode* MakeList(int n) {
    cNode* head = new cLeaf;
    while (n-- > 0) {
        cNode* node = new cNode;
        node->next = head;
        head = node;
    }
    return head;
}
EXPORT cCounter* MakeCounter() { return new cCounter; }
EXPORT int CountOnStack(int n) {
    cCounter c;
    while (n-- > 0) c.Bump();
    return c.count;
}

// Virtual inheritance: the virtual base is found through the vbtable the constructor stores, and overriding its
// function in a class with a constructor of its own needs a vtordisp thunk. cVMid adds no virtual function, so it
// has no vtable of its own at offset 0 (a vbtable pointer is there); cVLeaf adds one, so it does.
class cVBase {
public:
    cVBase() : tag(0) {}
    virtual ~cVBase() {}
    virtual int Tag() { return tag; }
    int tag;
};
class cVMid : public virtual cVBase {
public:
    cVMid();
    virtual int Tag() { return mid; }
    int mid;
};
class cVLeaf : public cVMid {
public:
    cVLeaf();
    virtual int Tag() { return leaf; }
    virtual void Grow() { ++leaf; }
    int leaf;
};
__declspec(noinline) cVMid::cVMid() : mid(1) {}
__declspec(noinline) cVLeaf::cVLeaf() : leaf(2) {}
EXPORT cVBase* MakeVirtual(int k) { if (k) return new cVLeaf; return new cVMid; }
