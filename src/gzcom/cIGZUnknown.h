// The root interface of the engine's component model: every component answers QueryInterface for the interface IDs
// it implements and counts its references.
#ifndef OB_GZCOM_CIGZUNKNOWN_H
#define OB_GZCOM_CIGZUNKNOWN_H

#include "common/types.h"

static const uint32_t GZIID_cIGZUnknown = 0x00000001;

class __declspec(novtable) cIGZUnknown {
public:
    virtual bool QueryInterface(uint32_t riid, void** ppvObj) = 0;
    virtual uint32_t AddRef() = 0;
    virtual uint32_t Release() = 0;
};

#endif
