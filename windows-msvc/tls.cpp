#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

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
