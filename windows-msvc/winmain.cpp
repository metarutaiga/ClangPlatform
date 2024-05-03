#include "dllmain.cpp"

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
