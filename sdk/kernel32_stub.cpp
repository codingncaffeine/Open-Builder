// Never run: linked into a throwaway kernel32.dll only so the linker writes kernel32.lib with the right import
// names. Matching the undecorated names in kernel32.def to these __stdcall definitions makes each import
// "VirtualProtect" (as kernel32 exports it) while code links against __imp__VirtualProtect@16.
#define OB_KERNEL32_STUB
#include "win32.h"

extern "C" {
BOOL __stdcall VirtualProtect(LPVOID, DWORD, DWORD, DWORD*) { return 0; }
LPVOID __stdcall VirtualAlloc(LPVOID, DWORD, DWORD, DWORD) { return 0; }
HANDLE __stdcall GetCurrentProcess() { return 0; }
BOOL __stdcall FlushInstructionCache(HANDLE, LPCVOID, DWORD) { return 0; }
HMODULE __stdcall LoadLibraryA(LPCSTR) { return 0; }
LPVOID __stdcall GetProcAddress(HMODULE, LPCSTR) { return 0; }
UINT __stdcall GetSystemDirectoryA(char*, UINT) { return 0; }
HANDLE __stdcall CreateFileA(LPCSTR, DWORD, DWORD, LPVOID, DWORD, DWORD, HANDLE) { return 0; }
BOOL __stdcall WriteFile(HANDLE, LPCVOID, DWORD, DWORD*, LPVOID) { return 0; }
BOOL __stdcall CloseHandle(HANDLE) { return 0; }
HANDLE __stdcall CreateThread(LPVOID, DWORD, LPTHREAD_START_ROUTINE, LPVOID, DWORD, DWORD*) { return 0; }
void __stdcall Sleep(DWORD) {}
}
