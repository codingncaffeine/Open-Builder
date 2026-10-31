// Shape families of packet shapec07_game.
#include "common/types.h"

struct Elem_shapec07_game {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
};

struct View_008fed20_shapec07_game : Elem_shapec07_game {
    View_008fed20_shapec07_game* Fn008fed20();
};

// FUNCTION: 0x008fed20
View_008fed20_shapec07_game* View_008fed20_shapec07_game::Fn008fed20()
{
    Base(0xa);
    mnVtable = 0xacd698;
    return this;
}

struct View_008fed70_shapec07_game : Elem_shapec07_game {
    View_008fed70_shapec07_game* Fn008fed70();
};

// FUNCTION: 0x008fed70
View_008fed70_shapec07_game* View_008fed70_shapec07_game::Fn008fed70()
{
    Base(0x2);
    mnVtable = 0xacd748;
    return this;
}

struct View_008fee00_shapec07_game : Elem_shapec07_game {
    View_008fee00_shapec07_game* Fn008fee00();
};

// FUNCTION: 0x008fee00
View_008fee00_shapec07_game* View_008fee00_shapec07_game::Fn008fee00()
{
    Base(0x23);
    mnVtable = 0xacd87c;
    return this;
}

struct View_009ec180_shapec07_game {
    virtual uint16_t Fn009ec180();
};

// FUNCTION: 0x009ec180
uint16_t View_009ec180_shapec07_game::Fn009ec180()
{
    return 0x2e;
}

struct View_009ec190_shapec07_game {
    virtual uint16_t Fn009ec190();
};

// FUNCTION: 0x009ec190
uint16_t View_009ec190_shapec07_game::Fn009ec190()
{
    return 0x2c;
}

struct View_009edd00_shapec07_game {
    virtual uint16_t Fn009edd00();
};

// FUNCTION: 0x009edd00
uint16_t View_009edd00_shapec07_game::Fn009edd00()
{
    return 0x20;
}

struct Str_shapec07_game {
    uint32_t pad[5];
    // STUB: 0x00408a20
    Str_shapec07_game(const Str_shapec07_game& rOther);
};

// GLOBAL: 0x00bacfc8
extern Str_shapec07_game g00bacfc8;
// GLOBAL: 0x00bacfb0
extern Str_shapec07_game g00bacfb0;
// GLOBAL: 0x00bacff8
extern Str_shapec07_game g00bacff8;

struct View_009ec200_shapec07_game {
    virtual Str_shapec07_game Fn009ec200();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009ec200 score 5
Str_shapec07_game View_009ec200_shapec07_game::Fn009ec200()
{
    return g00bacfc8;
}
#endif

struct View_009ec230_shapec07_game {
    virtual Str_shapec07_game Fn009ec230();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009ec230 score 5
Str_shapec07_game View_009ec230_shapec07_game::Fn009ec230()
{
    return g00bacfb0;
}
#endif

struct View_009edea0_shapec07_game {
    virtual Str_shapec07_game Fn009edea0();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009edea0 score 5
Str_shapec07_game View_009edea0_shapec07_game::Fn009edea0()
{
    return g00bacff8;
}
#endif

struct Vec3_shapec07_game {
    uint32_t mpBegin;
    uint32_t mpEnd;
    uint32_t mpCap;
    // STUB: 0x009ec1a0
    void Assign(uint32_t a, uint32_t b);
};

// GLOBAL: 0x00bacfbc
extern uint32_t g00bacfbc;
// GLOBAL: 0x00bacfc0
extern uint32_t g00bacfc0;
// GLOBAL: 0x00bacfe0
extern uint32_t g00bacfe0;
// GLOBAL: 0x00bacfe4
extern uint32_t g00bacfe4;
// GLOBAL: 0x00bacfec
extern uint32_t g00bacfec;
// GLOBAL: 0x00bacff0
extern uint32_t g00bacff0;

struct View_009ec260_shapec07_game {
    virtual Vec3_shapec07_game Fn009ec260();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009ec260 score 31
Vec3_shapec07_game View_009ec260_shapec07_game::Fn009ec260()
{
    Vec3_shapec07_game r;
    r.mpBegin = 0;
    r.mpEnd = 0;
    r.mpCap = 0;
    r.Assign(g00bacfbc, g00bacfc0);
    return r;
}
#endif
