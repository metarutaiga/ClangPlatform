#include <new>

//==============================================================================
//  new / delete
//==============================================================================
void* operator new(size_t size)
{
    return malloc(size);
}
void* operator new[](size_t size)
{
    return malloc(size);
}
#ifdef __cpp_aligned_new
void* operator new(size_t size, std::align_val_t)
{
    return malloc(size);
}
void* operator new[](size_t size, std::align_val_t)
{
    return malloc(size);
}
#endif
//------------------------------------------------------------------------------
void operator delete(void* ptr) noexcept
{
    free(ptr);
}
void operator delete(void* ptr, size_t size) noexcept
{
    free(ptr);
}
void operator delete[](void* ptr) noexcept
{
    free(ptr);
}
void operator delete[](void* ptr, size_t size) noexcept
{
    free(ptr);
}
#ifdef __cpp_aligned_new
void operator delete(void* ptr, std::align_val_t) noexcept
{
    free(ptr);
}
void operator delete(void* ptr, size_t size, std::align_val_t) noexcept
{
    free(ptr);
}
void operator delete[](void* ptr, std::align_val_t) noexcept
{
    free(ptr);
}
void operator delete[](void* ptr, size_t size, std::align_val_t) noexcept
{
    free(ptr);
}
#endif
//------------------------------------------------------------------------------
