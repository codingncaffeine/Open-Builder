// Classes known only from the code that uses them; named after the address of their first decompiled method
// until the binary gives up their real names.
#ifndef OB_UNIDENTIFIED_CUNK0098E9A0_H
#define OB_UNIDENTIFIED_CUNK0098E9A0_H

// The base at +0x4C of cUnk0098e9a0Inner; slot 15 (vtable +0x3C) returns a bool.
class cUnk0098e9a0Iface {
public:
    virtual void Slot00(); virtual void Slot01(); virtual void Slot02(); virtual void Slot03();
    virtual void Slot04(); virtual void Slot05(); virtual void Slot06(); virtual void Slot07();
    virtual void Slot08(); virtual void Slot09(); virtual void Slot10(); virtual void Slot11();
    virtual void Slot12(); virtual void Slot13(); virtual void Slot14(); virtual bool Slot15();
};

// The first base of cUnk0098e9a0Inner: its own vtable and 0x48 bytes, putting the second base at +0x4C.
class cUnk0098e9a0InnerBase {
public:
    virtual void Slot00();
    char unknown04[0x48];
};

// Multiple inheritance, as the engine's interface classes use it: calling a second-base method adjusts `this` by
// the base's offset with no null check, which is the original's `add ecx, 4C`. (A member object instead compiles
// the same under this compiler, but a modern one calls Slot15 directly, as a member's type is exact.)
class cUnk0098e9a0Inner : public cUnk0098e9a0InnerBase, public cUnk0098e9a0Iface {
};

class cUnk0098e9a0 {
public:
    bool ForwardSlot15();

    char unknown00[0xE4];
    cUnk0098e9a0Inner* inner;  // +0xE4; not checked for null (the OpenGL crash at 0x0098e9a6 is this read)
};

#endif
