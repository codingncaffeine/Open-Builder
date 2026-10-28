// A reference-counted component: cIGZUnknown, a virtual destructor, a count at +0x04 and two more virtuals, one
// that drops a reference without deleting and one that returns the count. The base of many of the framework's and
// the game's classes. Vtable 0x00ace638; named after its constructor until the binary gives up its name.
#ifndef OB_GZCOM_CUNK0090DA1E_H
#define OB_GZCOM_CUNK0090DA1E_H

#include "gzcom/cIGZUnknown.h"

// VTABLE: 0x00ace638
// SIZE 0x8
class cUnk0090da1e : public cIGZUnknown {
public:
    cUnk0090da1e();
    // The destructor is inline: the deleting destructor (0x0090da2b) has its vtable store in it.
    virtual ~cUnk0090da1e() {}

    bool QueryInterface(uint32_t riid, void** ppvObj);
    uint32_t AddRef();
    uint32_t Release();
    virtual uint32_t RemoveRef();
    virtual uint32_t RefCount();

protected:
    uint32_t refCount;  // +0x04
};

// SYNTHETIC: 0x0090da2b
// cUnk0090da1e::`scalar deleting dtor'

#endif
