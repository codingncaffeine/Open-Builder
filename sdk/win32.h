// The few Win32 declarations the hook DLL uses, written out so it builds with the 2003 compiler alone (the
// toolkit ships no Windows SDK). Import library: sdk/kernel32.def + sdk/kernel32_stub.cpp, see tools/build.sh.
#ifndef OB_SDK_WIN32_H
#define OB_SDK_WIN32_H

typedef unsigned long DWORD;
typedef int BOOL;
typedef void* HANDLE;
typedef void* HMODULE;
typedef void* LPVOID;
typedef const void* LPCVOID;
typedef const char* LPCSTR;
typedef unsigned int UINT;
typedef DWORD (__stdcall* LPTHREAD_START_ROUTINE)(LPVOID);

#define DLL_PROCESS_ATTACH 1
#define PAGE_EXECUTE_READWRITE 0x40
#define MEM_COMMIT 0x1000
#define MEM_RESERVE 0x2000
#define GENERIC_WRITE 0x40000000
#define FILE_SHARE_READ 0x1
#define CREATE_ALWAYS 2
#define FILE_ATTRIBUTE_NORMAL 0x80
#define INVALID_HANDLE_VALUE ((HANDLE)(long)-1)

#ifdef OB_KERNEL32_STUB
#define OB_IMPORT
#else
#define OB_IMPORT __declspec(dllimport)
#endif

extern "C" {
OB_IMPORT BOOL __stdcall VirtualProtect(LPVOID address, DWORD size, DWORD protect, DWORD* old);
OB_IMPORT LPVOID __stdcall VirtualAlloc(LPVOID address, DWORD size, DWORD type, DWORD protect);
OB_IMPORT HANDLE __stdcall GetCurrentProcess();
OB_IMPORT BOOL __stdcall FlushInstructionCache(HANDLE process, LPCVOID address, DWORD size);
OB_IMPORT HMODULE __stdcall LoadLibraryA(LPCSTR name);
OB_IMPORT LPVOID __stdcall GetProcAddress(HMODULE module, LPCSTR name);
OB_IMPORT UINT __stdcall GetSystemDirectoryA(char* buffer, UINT size);
OB_IMPORT HANDLE __stdcall CreateFileA(LPCSTR name, DWORD access, DWORD share, LPVOID security,
                                      DWORD disposition, DWORD flags, HANDLE templ);
OB_IMPORT BOOL __stdcall WriteFile(HANDLE file, LPCVOID data, DWORD size, DWORD* written, LPVOID overlapped);
OB_IMPORT BOOL __stdcall CloseHandle(HANDLE handle);
OB_IMPORT HANDLE __stdcall CreateThread(LPVOID security, DWORD stack, LPTHREAD_START_ROUTINE start,
                                       LPVOID param, DWORD flags, DWORD* id);
OB_IMPORT void __stdcall Sleep(DWORD ms);
}

#endif
