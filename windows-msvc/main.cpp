#include <stdlib.h>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//------------------------------------------------------------------------------
typedef void (*_PVFV)();
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
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
