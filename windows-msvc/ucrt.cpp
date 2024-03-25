//------------------------------------------------------------------------------
extern "C" const int _fltused = 1;
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
