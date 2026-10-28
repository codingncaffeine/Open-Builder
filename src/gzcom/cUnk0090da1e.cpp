#include "gzcom/cUnk0090da1e.h"

// FUNCTION: 0x0090d981
uint32_t cUnk0090da1e::RemoveRef() {
    if (refCount > 0) --refCount;
    return refCount;
}

// FUNCTION: 0x0090d997
uint32_t cUnk0090da1e::Release() {
    if (refCount > 1) return --refCount;
    delete this;
    return 0;
}

// FUNCTION: 0x0090da1e
cUnk0090da1e::cUnk0090da1e() : refCount(0) {}
