// The Windows functions decompiled code calls, imported as the original imported them (__stdcall, through the
// import table), declared here rather than taken from the platform's headers; other compilers get plain declarations.
#ifndef OB_COMMON_WINAPI_H
#define OB_COMMON_WINAPI_H

#include "common/compiler.h"
#include "common/types.h"

#ifdef _MSC_VER
#define OB_WINAPI extern "C" __declspec(dllimport)
#else
#define OB_WINAPI extern "C"
#endif

// user32
OB_WINAPI uint32_t OB_STDCALL CharLowerBuffA(char* text, uint32_t length);
OB_WINAPI uint32_t OB_STDCALL CharUpperBuffA(char* text, uint32_t length);
// kernel32
OB_WINAPI int32_t OB_STDCALL CompareStringA(uint32_t locale, uint32_t flags, const char* first, int32_t firstLength,
                                            const char* second, int32_t secondLength);

#endif
