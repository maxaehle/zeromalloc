#include <new>
using std::size_t;

extern "C" {
void *malloc(size_t);
void free(void*);
}

void* operator new(size_t size) noexcept(false) {return malloc(size);}
void operator delete(void* p) noexcept {free(p);}
void operator delete(void* p, size_t size) noexcept {free(p);}
void* operator new[](size_t size) noexcept(false) { return malloc(size); }
void operator delete[](void* p) noexcept { free(p); }
void operator delete[](void* p, size_t size) noexcept { free(p); }
void* operator new(size_t size, const std::nothrow_t& nt) noexcept {return malloc(size);}
void* operator new[](size_t size, const std::nothrow_t& nt) noexcept {return malloc(size);}
void operator delete(void* p, const std::nothrow_t& nt) noexcept {free(p);}
void operator delete[](void* p, const std::nothrow_t& nt) noexcept {free(p);}

/*
void* operator new(size_t size, std::align_val_t alignment) noexcept(false)
    TCMALLOC_ALIAS(TCMallocInternalNewAligned);
void* operator new(size_t size, std::align_val_t alignment,
                   const std::nothrow_t&) noexcept
    TCMALLOC_ALIAS(TCMallocInternalNewAligned_nothrow);
void operator delete(void* p, std::align_val_t alignment) noexcept
    TCMALLOC_ALIAS(TCMallocInternalDeleteAligned);
void operator delete(void* p, std::align_val_t alignment,
                     const std::nothrow_t&) noexcept
    TCMALLOC_ALIAS(TCMallocInternalDeleteAligned_nothrow);
void operator delete(void* p, size_t size, std::align_val_t alignment) noexcept
    TCMALLOC_ALIAS(TCMallocInternalDeleteSizedAligned);
void* operator new[](size_t size, std::align_val_t alignment) noexcept(false)
    TCMALLOC_ALIAS(TCMallocInternalNewArrayAligned);
void* operator new[](size_t size, std::align_val_t alignment,
                     const std::nothrow_t&) noexcept
    TCMALLOC_ALIAS(TCMallocInternalNewArrayAligned_nothrow);
void operator delete[](void* p, std::align_val_t alignment) noexcept
    TCMALLOC_ALIAS(TCMallocInternalDeleteArrayAligned);
void operator delete[](void* p, std::align_val_t alignment,
                       const std::nothrow_t&) noexcept
    TCMALLOC_ALIAS(TCMallocInternalDeleteArrayAligned_nothrow);
void operator delete[](void* p, size_t size,
                       std::align_val_t alignemnt) noexcept
    TCMALLOC_ALIAS(TCMallocInternalDeleteArraySizedAligned);
*/
