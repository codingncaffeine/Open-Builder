// Classes known only from the code that uses them; named after the address of their first decompiled method
// until the binary gives up their real names.
#ifndef OB_UNIDENTIFIED_CUNK0098E9A0_H
#define OB_UNIDENTIFIED_CUNK0098E9A0_H

// An interface embedded at +0x4C of cUnk0098e9a0Inner; slot 15 (vtable +0x3C) returns a bool.
class cUnk0098e9a0Iface {
public:
    virtual void Slot00(); virtual void Slot01(); virtual void Slot02(); virtual void Slot03();
    virtual void Slot04(); virtual void Slot05(); virtual void Slot06(); virtual void Slot07();
    virtual void Slot08(); virtual void Slot09(); virtual void Slot10(); virtual void Slot11();
    virtual void Slot12(); virtual void Slot13(); virtual void Slot14(); virtual bool Slot15();
};

class cUnk0098e9a0Inner {
public:
    char unknown00[0x4C];
    cUnk0098e9a0Iface iface;  // +0x4C
};

class cUnk0098e9a0 {
public:
    bool ForwardSlot15();

    char unknown00[0xE4];
    cUnk0098e9a0Inner* inner;  // +0xE4; not checked for null (the OpenGL crash at 0x0098e9a6 is this read)
};

#endif
