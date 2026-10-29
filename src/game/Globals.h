// The original's global objects that more than one decompiled file uses, each declared once here: what is known of
// its interface so far (slots named as they are learned, PadNN keeping the slot numbers of the rest). Their GLOBAL
// annotations keep each variable the original's in the hook build (tools/gen-hooks.sh, tools/gen-globals.sh).
#ifndef OB_GAME_GLOBALS_H
#define OB_GAME_GLOBALS_H

#include "common/types.h"

class cUnk00a81120;

// What the object at 0x00b207c0 hands out from its slot 10.
struct cB207c0Item {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
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
    virtual void Pad49();
    virtual void Pad50();
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual void Fn55(const char*, uint32_t, const char*);
    virtual void Pad56();
    virtual void Pad57();
    virtual void Pad58();
    virtual void Pad59();
    virtual void Pad60();
    virtual void Pad61();
    virtual void Fn62(int32_t);
};

// The object at 0x00b207c0.
struct cB207c0 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual cB207c0Item* Fn10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Fn17(uint32_t id, cUnk00a81120* owner);
    virtual void Fn18(void*);
    virtual void Fn19();
};
// GLOBAL: 0x00b207c0
extern cB207c0* gpB207c0;

// The object at 0x00b43ccc: slots 4 and 6 register or unregister an object under an id.
struct cB43ccc {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Fn04(void* object, uint32_t id);
    virtual void Pad05();
    virtual void Fn06(void* object, uint32_t id);
};
// GLOBAL: 0x00b43ccc
extern cB43ccc* gpB43ccc;

#endif
