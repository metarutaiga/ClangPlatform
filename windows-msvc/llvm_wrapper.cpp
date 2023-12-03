#include <new>
#include <memory>
#include <string>
#include <vector>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//------------------------------------------------------------------------------
extern "C" const int _fltused = 1;
//------------------------------------------------------------------------------
#pragma data_seg(".tls")
#pragma data_seg(".tls$ZZZ")
#pragma data_seg()
#pragma section(".CRT$XLA", long, read)
#pragma section(".CRT$XLZ", long, read)
#pragma section(".rdata$T", long, read)
#pragma comment(linker, "/merge:.CRT=.rdata")
extern "C" ULONG _tls_index = 0;
extern "C" __declspec(allocate(".tls"))     char _tls_start = 0;
extern "C" __declspec(allocate(".tls$ZZZ")) char _tls_end = 0;
extern "C" __declspec(allocate(".CRT$XLA")) const PIMAGE_TLS_CALLBACK __xl_a = 0;
extern "C" __declspec(allocate(".CRT$XLZ")) const PIMAGE_TLS_CALLBACK __xl_z = 0;
extern "C" __declspec(allocate(".rdata$T")) const IMAGE_TLS_DIRECTORY _tls_used =
{
#if defined(_WIN64)
    (ULONGLONG) &_tls_start,
    (ULONGLONG) &_tls_end,
    (ULONGLONG) &_tls_index,
    (ULONGLONG)(&__xl_a + 1),
#else
    (ULONG_PTR) &_tls_start,
    (ULONG_PTR) &_tls_end,
    (ULONG_PTR) &_tls_index,
    (ULONG_PTR)(&__xl_a + 1),
#endif
    (ULONG)0,
    (ULONG)0,
};
//------------------------------------------------------------------------------
typedef void (*_PVFV)();
extern "C" __declspec(allocate(".CRT$XDA")) const _PVFV __xd_a = 0;
extern "C" __declspec(allocate(".CRT$XDZ")) const _PVFV __xd_z = 0;
//------------------------------------------------------------------------------
extern "C" void WINAPI __dyn_tls_init(PVOID, DWORD dwReason, LPVOID)
{
    if (dwReason != DLL_THREAD_ATTACH)
        return;

    for (const _PVFV* pfunc = &__xd_a + 1; pfunc != &__xd_z; ++pfunc)
    {
        if (*pfunc)
            (*pfunc)();
    }
}
//------------------------------------------------------------------------------
#if defined(_M_IX86)
#pragma comment(linker, "/alternatename:__CxxThrowException@8=__CxxThrowException")
#pragma comment(linker, "/alternatename:_atexit=__crt_atexit")
#pragma comment(linker, "/alternatename:_setjmp=__setjmp3")
#pragma comment(linker, "/alternatename:___uncaught_exceptions=___uncaught_exception")
#elif defined(_M_ARM)
#pragma comment(linker, "/alternatename:atexit=_crt_atexit")
#pragma comment(linker, "/alternatename:setjmp=__intrinsic_setjmp")
#pragma comment(linker, "/alternatename:__uncaught_exceptions=__uncaught_exception")
#elif defined(_M_AMD64) || defined(_M_ARM64)
#pragma comment(linker, "/alternatename:atexit=_crt_atexit")
#pragma comment(linker, "/alternatename:setjmp=__intrinsic_setjmpex")
#pragma comment(linker, "/alternatename:__uncaught_exceptions=__uncaught_exception")
#endif
//------------------------------------------------------------------------------
#ifndef _NO_DLLMAIN_
#pragma section(".CRT$XCA", long, read)
#pragma section(".CRT$XCZ", long, read)
#pragma section(".CRT$XIA", long, read)
#pragma section(".CRT$XIZ", long, read)
#pragma section(".CRT$XPA", long, read)
#pragma section(".CRT$XPZ", long, read)
#pragma section(".CRT$XTA", long, read)
#pragma section(".CRT$XTZ", long, read)
#pragma comment(linker, "/merge:.CRT=.rdata")
extern "C" __declspec(allocate(".CRT$XCA")) const _PVFV __xc_a[] = {};
extern "C" __declspec(allocate(".CRT$XCZ")) const _PVFV __xc_z[] = {};
extern "C" __declspec(allocate(".CRT$XIA")) const _PVFV __xi_a[] = {};
extern "C" __declspec(allocate(".CRT$XIZ")) const _PVFV __xi_z[] = {};
extern "C" __declspec(allocate(".CRT$XPA")) const _PVFV __xp_a[] = {};
extern "C" __declspec(allocate(".CRT$XPZ")) const _PVFV __xp_z[] = {};
extern "C" __declspec(allocate(".CRT$XTA")) const _PVFV __xt_a[] = {};
extern "C" __declspec(allocate(".CRT$XTZ")) const _PVFV __xt_z[] = {};
//------------------------------------------------------------------------------
static void _initterm(_PVFV const* const first, _PVFV const* const last)
{
    for (_PVFV const* it = first; it != last; ++it)
    {
        if (*it == nullptr)
            continue;

        (**it)();
    }
}
//------------------------------------------------------------------------------
extern "C" BOOL WINAPI _DllMainCRTStartup(HANDLE handle, DWORD reason, LPVOID preserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        _initterm(__xi_a, __xi_z);
        _initterm(__xc_a, __xc_z);
        break;

    case DLL_PROCESS_DETACH:
        _initterm(__xp_a, __xp_z);
        _initterm(__xt_a, __xt_z);
        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}
#endif
//------------------------------------------------------------------------------
#ifdef _HAVE_WINMAIN_
extern "C" IMAGE_DOS_HEADER __ImageBase;
extern "C" void WinMainCRTStartup()
{
    _DllMainCRTStartup(NULL, DLL_PROCESS_ATTACH, NULL);
    STARTUPINFOA startupInfo;
    GetStartupInfoA(&startupInfo);
    int showWindowMode = startupInfo.dwFlags & STARTF_USESHOWWINDOW ? startupInfo.wShowWindow : SW_SHOWDEFAULT;
    int result = WinMain((HINSTANCE)&__ImageBase, NULL, GetCommandLineA(), showWindowMode);
    exit(result);
}
#endif
//------------------------------------------------------------------------------
extern "C" void __std_terminate()
{
    exit(0);
}
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
#if defined(_LIBCPP_VERSION) && !defined(_LIBCPP_BUILDING_LIBRARY)
_LIBCPP_BEGIN_NAMESPACE_STD
    template class _LIBCPP_CLASS_TEMPLATE_INSTANTIATION_VIS basic_string<char>;
    template class _LIBCPP_CLASS_TEMPLATE_INSTANTIATION_VIS basic_string<wchar_t>;
    __shared_count::~__shared_count() {}
    __shared_weak_count::~__shared_weak_count() {}
    void __shared_weak_count::__release_weak() _NOEXCEPT
    {
        if (__atomic_load_n(&__shared_weak_owners_, __ATOMIC_ACQUIRE) == 0)
            __on_zero_shared_weak();
        else if (__atomic_add_fetch(&__shared_weak_owners_, -1, __ATOMIC_ACQ_REL) == -1)
            __on_zero_shared_weak();
    }
    __shared_weak_count* __shared_weak_count::lock() _NOEXCEPT
    {
        long object_owners = __atomic_load_n(&__shared_owners_, __ATOMIC_SEQ_CST);
        while (object_owners != -1)
        {
            if (__atomic_compare_exchange_n(&__shared_owners_,
                                            &object_owners,
                                            object_owners + 1,
                                            true,
                                            __ATOMIC_SEQ_CST,
                                            __ATOMIC_SEQ_CST))
                return this;
        }
        return nullptr;
    }
    const void* __shared_weak_count::__get_deleter(const type_info&) const _NOEXCEPT
    {
        return nullptr;
    }
_LIBCPP_END_NAMESPACE_STD
#endif
//------------------------------------------------------------------------------
#if defined(_DEBUG)
extern "C" int _chvalidator(int const c, int const mask)
{
    return __acrt_locale_get_ctype_array_value(__PCTYPE_FUNC, c, mask);
}
extern "C" int _chvalidator_l(_locale_t const locale, int const c, int const mask)
{
    if (locale)
    {
        return __acrt_locale_get_ctype_array_value(__acrt_get_locale_data_prefix(locale)->_locale_pctype, c, mask);
    }
    return __acrt_locale_get_ctype_array_value(__PCTYPE_FUNC, c, mask);
}
#endif
//------------------------------------------------------------------------------
extern "C" int __tlregdtor(void*)
{
    return 0;
}
//------------------------------------------------------------------------------
extern "C" void* _CrtSetReportFile(int _ReportType, void* _ReportFile)
{
    return nullptr;
}
extern "C"  int _CrtSetReportMode(int _ReportType, int _ReportMode)
{
    return 0;
}
//------------------------------------------------------------------------------
