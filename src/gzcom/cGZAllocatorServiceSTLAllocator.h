// The standard-library allocator the game's containers use: every block comes from the framework's allocator
// service. The service is looked up the first time an allocator of a type needs it and kept in a static of that
// type, so a std::list<cISC4Occupant*, cGZAllocatorServiceSTLAllocator<cISC4Occupant*> > allocates from the cache of
// cISC4Occupant*: rebinding to the container's node keeps the element type as the key.
#ifndef OB_GZCOM_CGZALLOCATORSERVICESTLALLOCATOR_H
#define OB_GZCOM_CGZALLOCATORSERVICESTLALLOCATOR_H

#include <cstddef>
#include <new>
#include "common/compiler.h"
#include "common/types.h"
#include "gzcom/cIGZUnknown.h"

// The framework's memory: the game's own pool.
class OB_NOVTABLE cIGZAllocatorService : public cIGZUnknown {
public:
    virtual void* Allocate(uint32_t size) = 0;
    virtual bool Deallocate(void* block) = 0;
    virtual void* Reallocate(void* block, uint32_t size) = 0;
};

static const uint32_t GZCLSID_cGZAllocatorService = 0x3ae4bea3;
static const uint32_t GZIID_cIGZAllocatorService = 0x3ae4beab;

// The framework, as far as finding a system service goes.
class OB_NOVTABLE cIGZFrameWork_Services : public cIGZUnknown {
public:
    virtual bool AddSystemService(void* service) = 0;
    virtual bool RemoveSystemService(void* service) = 0;
    virtual bool GetSystemService(uint32_t clsid, uint32_t iid, void** service) = 0;
};

// STUB: 0x008793ec
cIGZFrameWork_Services* RZGetFramework();

// The counted reference the lookup goes through (it lets go of its count on the way out).
struct cGZAllocatorServiceRef {
    cIGZAllocatorService* mpService;
    // STUB: 0x00411870
    void Release();
};

// The cache of one element type's allocators.
template <class Key>
struct cGZAllocatorServiceCache {
    static cIGZAllocatorService* spService;
};

// The caches the original has, one per element type its containers hold. A key with no specialization here leaves
// an unresolved symbol: give it one, with the original's address, when a function shows which global caches it.
class cISC4Occupant;
template <>
struct cGZAllocatorServiceCache<cISC4Occupant*> {
    // GLOBAL: 0x00b207e4
    static cIGZAllocatorService* spService;
};

template <class T, class Key = T>
class cGZAllocatorServiceSTLAllocator {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    template <class U>
    struct rebind {
        typedef cGZAllocatorServiceSTLAllocator<U, Key> other;
    };

    cGZAllocatorServiceSTLAllocator() {}
    template <class U>
    cGZAllocatorServiceSTLAllocator(const cGZAllocatorServiceSTLAllocator<U, Key>&) {}

    static cIGZAllocatorService* Service()
    {
        if (!cGZAllocatorServiceCache<Key>::spService) {
            cGZAllocatorServiceRef ref;
            ref.mpService = 0;
            cIGZFrameWork_Services* framework = RZGetFramework();
            if (framework) {
                framework->GetSystemService(GZCLSID_cGZAllocatorService, GZIID_cIGZAllocatorService,
                                            reinterpret_cast<void**>(&ref.mpService));
            }
            cGZAllocatorServiceCache<Key>::spService = ref.mpService;
            ref.Release();
        }
        return cGZAllocatorServiceCache<Key>::spService;
    }

    pointer allocate(size_type n, const void* = 0)
    {
        return static_cast<pointer>(Service()->Allocate(static_cast<uint32_t>(n * sizeof(T))));
    }
    void deallocate(pointer p, size_type) { Service()->Deallocate(p); }
    void construct(pointer p, const T& value) { new (p) T(value); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { return size_type(-1) / sizeof(T); }
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
};

template <class T, class U, class Key>
inline bool operator==(const cGZAllocatorServiceSTLAllocator<T, Key>&, const cGZAllocatorServiceSTLAllocator<U, Key>&)
{
    return true;
}
template <class T, class U, class Key>
inline bool operator!=(const cGZAllocatorServiceSTLAllocator<T, Key>&, const cGZAllocatorServiceSTLAllocator<U, Key>&)
{
    return false;
}

#endif
