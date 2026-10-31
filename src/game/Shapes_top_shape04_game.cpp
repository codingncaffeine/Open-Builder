// Shape families of packet top_shape04_game, written by scratch/s16/gen/top_shape04_game/gen.sh.
#include "common/types.h"

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

// The header node of an STL tree container.
struct Node_top_shape04_game {
    uint32_t mnColor;
    Node_top_shape04_game* mpRoot;
    Node_top_shape04_game* mpLeft;
    Node_top_shape04_game* mpRight;
};

struct View_467a50_top_shape04_game {
    Node_top_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x004676a0
    void Erase(Node_top_shape04_game* pNode);
    void Fn00467a50();
};

// FUNCTION: 0x00467a50
void View_467a50_top_shape04_game::Fn00467a50()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct Iface4_4695b0_top_shape04_game { virtual void Pad4(); };
struct Iface8_4695b0_top_shape04_game { virtual void Pad8(); };
struct Root_4695b0_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_4695b0_top_shape04_game : public Root_4695b0_top_shape04_game, public Iface4_4695b0_top_shape04_game, public Iface8_4695b0_top_shape04_game {
    bool Fn004695b0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x004695b0
bool View_4695b0_top_shape04_game::Fn004695b0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x694028ec:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_4695b0_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_4695b0_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_4a74e0_top_shape04_game { virtual void Pad4(); };
struct Iface8_4a74e0_top_shape04_game { virtual void Pad8(); };
struct Root_4a74e0_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_4a74e0_top_shape04_game : public Root_4a74e0_top_shape04_game, public Iface4_4a74e0_top_shape04_game, public Iface8_4a74e0_top_shape04_game {
    bool Fn004a74e0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x004a74e0
bool View_4a74e0_top_shape04_game::Fn004a74e0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x69d2be1d:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_4a74e0_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_4a74e0_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_4dc1b0_top_shape04_game { virtual void Pad4(); };
struct Iface8_4dc1b0_top_shape04_game { virtual void Pad8(); };
struct Root_4dc1b0_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_4dc1b0_top_shape04_game : public Root_4dc1b0_top_shape04_game, public Iface4_4dc1b0_top_shape04_game, public Iface8_4dc1b0_top_shape04_game {
    bool Fn004dc1b0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x004dc1b0
bool View_4dc1b0_top_shape04_game::Fn004dc1b0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x67652433:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_4dc1b0_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_4dc1b0_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct View_4de760_top_shape04_game {
    Node_top_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x004de6e0
    void Erase(Node_top_shape04_game* pNode);
    void Fn004de760();
};

// FUNCTION: 0x004de760
void View_4de760_top_shape04_game::Fn004de760()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct Stream_5d1860_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual bool Op(uint32_t a);
};
struct View_5d1860_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1860_top_shape04_game* mpStream;
    uint32_t Fn005d1860(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1860 score 2
uint32_t View_5d1860_top_shape04_game::Fn005d1860(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1930_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual bool Op(uint32_t a);
};
struct View_5d1930_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1930_top_shape04_game* mpStream;
    uint32_t Fn005d1930(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1930 score 2
uint32_t View_5d1930_top_shape04_game::Fn005d1930(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1960_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual bool Op(uint32_t a);
};
struct View_5d1960_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1960_top_shape04_game* mpStream;
    uint32_t Fn005d1960(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1960 score 2
uint32_t View_5d1960_top_shape04_game::Fn005d1960(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1990_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual bool Op(uint32_t a);
};
struct View_5d1990_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1990_top_shape04_game* mpStream;
    uint32_t Fn005d1990(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1990 score 2
uint32_t View_5d1990_top_shape04_game::Fn005d1990(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d19c0_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual bool Op(uint32_t a);
};
struct View_5d19c0_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d19c0_top_shape04_game* mpStream;
    uint32_t Fn005d19c0(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d19c0 score 2
uint32_t View_5d19c0_top_shape04_game::Fn005d19c0(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d19f0_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual bool Op(uint32_t a);
};
struct View_5d19f0_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d19f0_top_shape04_game* mpStream;
    uint32_t Fn005d19f0(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d19f0 score 2
uint32_t View_5d19f0_top_shape04_game::Fn005d19f0(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1a20_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual bool Op(uint32_t a);
};
struct View_5d1a20_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1a20_top_shape04_game* mpStream;
    uint32_t Fn005d1a20(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1a20 score 2
uint32_t View_5d1a20_top_shape04_game::Fn005d1a20(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1a50_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual bool Op(uint32_t a);
};
struct View_5d1a50_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1a50_top_shape04_game* mpStream;
    uint32_t Fn005d1a50(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1a50 score 2
uint32_t View_5d1a50_top_shape04_game::Fn005d1a50(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1a80_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual bool Op(uint32_t a);
};
struct View_5d1a80_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1a80_top_shape04_game* mpStream;
    uint32_t Fn005d1a80(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1a80 score 2
uint32_t View_5d1a80_top_shape04_game::Fn005d1a80(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1ab0_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual bool Op(uint32_t a);
};
struct View_5d1ab0_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1ab0_top_shape04_game* mpStream;
    uint32_t Fn005d1ab0(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1ab0 score 2
uint32_t View_5d1ab0_top_shape04_game::Fn005d1ab0(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1ae0_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual bool Op(uint32_t a);
};
struct View_5d1ae0_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1ae0_top_shape04_game* mpStream;
    uint32_t Fn005d1ae0(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1ae0 score 2
uint32_t View_5d1ae0_top_shape04_game::Fn005d1ae0(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1b10_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual bool Op(uint32_t a);
};
struct View_5d1b10_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1b10_top_shape04_game* mpStream;
    uint32_t Fn005d1b10(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1b10 score 2
uint32_t View_5d1b10_top_shape04_game::Fn005d1b10(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1ca0_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual bool Op(uint32_t a);
};
struct View_5d1ca0_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1ca0_top_shape04_game* mpStream;
    uint32_t Fn005d1ca0(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1ca0 score 2
uint32_t View_5d1ca0_top_shape04_game::Fn005d1ca0(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1d80_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual bool Op(uint32_t a);
};
struct View_5d1d80_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1d80_top_shape04_game* mpStream;
    uint32_t Fn005d1d80(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1d80 score 2
uint32_t View_5d1d80_top_shape04_game::Fn005d1d80(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1df0_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual bool Op(uint32_t a);
};
struct View_5d1df0_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1df0_top_shape04_game* mpStream;
    uint32_t Fn005d1df0(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1df0 score 2
uint32_t View_5d1df0_top_shape04_game::Fn005d1df0(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1e30_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual bool Op(uint32_t a);
};
struct View_5d1e30_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1e30_top_shape04_game* mpStream;
    uint32_t Fn005d1e30(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1e30 score 2
uint32_t View_5d1e30_top_shape04_game::Fn005d1e30(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1e70_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual bool Op(uint32_t a);
};
struct View_5d1e70_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1e70_top_shape04_game* mpStream;
    uint32_t Fn005d1e70(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1e70 score 2
uint32_t View_5d1e70_top_shape04_game::Fn005d1e70(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1eb0_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual bool Op(uint32_t a);
};
struct View_5d1eb0_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1eb0_top_shape04_game* mpStream;
    uint32_t Fn005d1eb0(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1eb0 score 2
uint32_t View_5d1eb0_top_shape04_game::Fn005d1eb0(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1f70_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual bool Op(uint32_t a);
};
struct View_5d1f70_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1f70_top_shape04_game* mpStream;
    uint32_t Fn005d1f70(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1f70 score 2
uint32_t View_5d1f70_top_shape04_game::Fn005d1f70(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Stream_5d1ff0_top_shape04_game {
    virtual void Pad0();
    virtual void Pad1();
    virtual void Pad2();
    virtual void Pad3();
    virtual void Pad4();
    virtual void Pad5();
    virtual void Pad6();
    virtual void Pad7();
    virtual void Pad8();
    virtual void Pad9();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual bool Op(uint32_t a);
};
struct View_5d1ff0_top_shape04_game {
    uint32_t mpVtbl;
    uint8_t mbOk;
    Stream_5d1ff0_top_shape04_game* mpStream;
    uint32_t Fn005d1ff0(uint32_t a);
};

#ifdef OB_DRAFTS
// CLOSE: 0x005d1ff0 score 2
uint32_t View_5d1ff0_top_shape04_game::Fn005d1ff0(uint32_t a)
{
    if (mbOk) {
        if (mpStream->Op(a)) {
            return mbOk = 1;
        }
    }
    return mbOk = 0;
}
#endif

struct Iface4_60c760_top_shape04_game { virtual void Pad4(); };
struct Iface8_60c760_top_shape04_game { virtual void Pad8(); };
struct Root_60c760_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_60c760_top_shape04_game : public Root_60c760_top_shape04_game, public Iface4_60c760_top_shape04_game, public Iface8_60c760_top_shape04_game {
    bool Fn0060c760(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0060c760
bool View_60c760_top_shape04_game::Fn0060c760(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x89a5ba3f:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_60c760_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_60c760_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct View_65e7c0_top_shape04_game {
    Node_top_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0065e740
    void Erase(Node_top_shape04_game* pNode);
    void Fn0065e7c0();
};

// FUNCTION: 0x0065e7c0
void View_65e7c0_top_shape04_game::Fn0065e7c0()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_662b30_top_shape04_game {
    Node_top_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x00662a60
    void Erase(Node_top_shape04_game* pNode);
    void Fn00662b30();
};

// FUNCTION: 0x00662b30
void View_662b30_top_shape04_game::Fn00662b30()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct View_6647a0_top_shape04_game {
    Node_top_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x006645b0
    void Erase(Node_top_shape04_game* pNode);
    void Fn006647a0();
};

// FUNCTION: 0x006647a0
void View_6647a0_top_shape04_game::Fn006647a0()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

struct Iface4_68b9c0_top_shape04_game { virtual void Pad4(); };
struct Iface8_68b9c0_top_shape04_game { virtual void Pad8(); };
struct Root_68b9c0_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_68b9c0_top_shape04_game : public Root_68b9c0_top_shape04_game, public Iface4_68b9c0_top_shape04_game, public Iface8_68b9c0_top_shape04_game {
    bool Fn0068b9c0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0068b9c0
bool View_68b9c0_top_shape04_game::Fn0068b9c0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0xc773e880:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_68b9c0_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_68b9c0_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_68fc80_top_shape04_game { virtual void Pad4(); };
struct Iface8_68fc80_top_shape04_game { virtual void Pad8(); };
struct Root_68fc80_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_68fc80_top_shape04_game : public Root_68fc80_top_shape04_game, public Iface4_68fc80_top_shape04_game, public Iface8_68fc80_top_shape04_game {
    bool Fn0068fc80(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0068fc80
bool View_68fc80_top_shape04_game::Fn0068fc80(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x6772bd23:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_68fc80_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_68fc80_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_69d6c0_top_shape04_game { virtual void Pad4(); };
struct Iface8_69d6c0_top_shape04_game { virtual void Pad8(); };
struct Root_69d6c0_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_69d6c0_top_shape04_game : public Root_69d6c0_top_shape04_game, public Iface4_69d6c0_top_shape04_game, public Iface8_69d6c0_top_shape04_game {
    bool Fn0069d6c0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0069d6c0
bool View_69d6c0_top_shape04_game::Fn0069d6c0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x8a41322f:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_69d6c0_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_69d6c0_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_6a2310_top_shape04_game { virtual void Pad4(); };
struct Iface8_6a2310_top_shape04_game { virtual void Pad8(); };
struct Root_6a2310_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_6a2310_top_shape04_game : public Root_6a2310_top_shape04_game, public Iface4_6a2310_top_shape04_game, public Iface8_6a2310_top_shape04_game {
    bool Fn006a2310(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006a2310
bool View_6a2310_top_shape04_game::Fn006a2310(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x47967e16:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_6a2310_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_6a2310_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_6ae390_top_shape04_game { virtual void Pad4(); };
struct Iface8_6ae390_top_shape04_game { virtual void Pad8(); };
struct Root_6ae390_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_6ae390_top_shape04_game : public Root_6ae390_top_shape04_game, public Iface4_6ae390_top_shape04_game, public Iface8_6ae390_top_shape04_game {
    bool Fn006ae390(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006ae390
bool View_6ae390_top_shape04_game::Fn006ae390(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x48f41617:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_6ae390_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_6ae390_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_6b8970_top_shape04_game { virtual void Pad4(); };
struct Iface8_6b8970_top_shape04_game { virtual void Pad8(); };
struct Root_6b8970_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_6b8970_top_shape04_game : public Root_6b8970_top_shape04_game, public Iface4_6b8970_top_shape04_game, public Iface8_6b8970_top_shape04_game {
    bool Fn006b8970(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006b8970
bool View_6b8970_top_shape04_game::Fn006b8970(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x477a9e7d:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_6b8970_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_6b8970_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_6b8b20_top_shape04_game { virtual void Pad4(); };
struct Iface8_6b8b20_top_shape04_game { virtual void Pad8(); };
struct Root_6b8b20_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_6b8b20_top_shape04_game : public Root_6b8b20_top_shape04_game, public Iface4_6b8b20_top_shape04_game, public Iface8_6b8b20_top_shape04_game {
    bool Fn006b8b20(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006b8b20
bool View_6b8b20_top_shape04_game::Fn006b8b20(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x8a09d502:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_6b8b20_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_6b8b20_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_6c3b80_top_shape04_game { virtual void Pad4(); };
struct Iface8_6c3b80_top_shape04_game { virtual void Pad8(); };
struct Root_6c3b80_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_6c3b80_top_shape04_game : public Root_6c3b80_top_shape04_game, public Iface4_6c3b80_top_shape04_game, public Iface8_6c3b80_top_shape04_game {
    bool Fn006c3b80(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006c3b80
bool View_6c3b80_top_shape04_game::Fn006c3b80(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x4818e5d2:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_6c3b80_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_6c3b80_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_6d5060_top_shape04_game { virtual void Pad4(); };
struct Iface8_6d5060_top_shape04_game { virtual void Pad8(); };
struct Root_6d5060_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_6d5060_top_shape04_game : public Root_6d5060_top_shape04_game, public Iface4_6d5060_top_shape04_game, public Iface8_6d5060_top_shape04_game {
    bool Fn006d5060(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006d5060
bool View_6d5060_top_shape04_game::Fn006d5060(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0xaa3fe6bc:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_6d5060_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_6d5060_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_6da3c0_top_shape04_game { virtual void Pad4(); };
struct Iface8_6da3c0_top_shape04_game { virtual void Pad8(); };
struct Root_6da3c0_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_6da3c0_top_shape04_game : public Root_6da3c0_top_shape04_game, public Iface4_6da3c0_top_shape04_game, public Iface8_6da3c0_top_shape04_game {
    bool Fn006da3c0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006da3c0
bool View_6da3c0_top_shape04_game::Fn006da3c0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x47782ccc:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_6da3c0_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_6da3c0_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_6e8fd0_top_shape04_game { virtual void Pad4(); };
struct Iface8_6e8fd0_top_shape04_game { virtual void Pad8(); };
struct Root_6e8fd0_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_6e8fd0_top_shape04_game : public Root_6e8fd0_top_shape04_game, public Iface4_6e8fd0_top_shape04_game, public Iface8_6e8fd0_top_shape04_game {
    bool Fn006e8fd0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x006e8fd0
bool View_6e8fd0_top_shape04_game::Fn006e8fd0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x4a2c4e69:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_6e8fd0_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_6e8fd0_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_7045b0_top_shape04_game { virtual void Pad4(); };
struct Iface8_7045b0_top_shape04_game { virtual void Pad8(); };
struct Root_7045b0_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_7045b0_top_shape04_game : public Root_7045b0_top_shape04_game, public Iface4_7045b0_top_shape04_game, public Iface8_7045b0_top_shape04_game {
    bool Fn007045b0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x007045b0
bool View_7045b0_top_shape04_game::Fn007045b0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0xa818ed1b:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_7045b0_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_7045b0_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct Iface4_70d7e0_top_shape04_game { virtual void Pad4(); };
struct Iface8_70d7e0_top_shape04_game { virtual void Pad8(); };
struct Root_70d7e0_top_shape04_game {
    virtual void Pad0();
    virtual void AddRef();
};
struct View_70d7e0_top_shape04_game : public Root_70d7e0_top_shape04_game, public Iface4_70d7e0_top_shape04_game, public Iface8_70d7e0_top_shape04_game {
    bool Fn0070d7e0(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0070d7e0
bool View_70d7e0_top_shape04_game::Fn0070d7e0(uint32_t iid, void** ppv)
{
    switch (iid) {
    case 0x68027f37:
    case 1:
        *ppv = this;
        AddRef();
        return true;
    case 0x452294aa:
        *ppv = static_cast<Iface4_70d7e0_top_shape04_game*>(this);
        AddRef();
        return true;
    case 0xe4fda3d4:
        *ppv = static_cast<Iface8_70d7e0_top_shape04_game*>(this);
        AddRef();
        return true;
    }
    return false;
}

struct View_81d1b0_top_shape04_game {
    Node_top_shape04_game* mpHead;
    uint32_t mnCount;
    // STUB: 0x0081d0f0
    void Erase(Node_top_shape04_game* pNode);
    void Fn0081d1b0();
};

// FUNCTION: 0x0081d1b0
void View_81d1b0_top_shape04_game::Fn0081d1b0()
{
    if (mnCount != 0) {
        Erase(mpHead->mpRoot);
        mpHead->mpLeft = mpHead;
        mpHead->mpRoot = 0;
        mpHead->mpRight = mpHead;
        mnCount = 0;
    }
    if (mpHead) {
        _STL::__stl_delete(mpHead);
    }
}

