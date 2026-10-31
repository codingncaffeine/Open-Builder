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
int __stdcall CompareStringA(DWORD, DWORD, LPCSTR, int, LPCSTR, int) { return 0; }
LPVOID __stdcall GetProcAddress(HMODULE, LPCSTR) { return 0; }
UINT __stdcall GetSystemDirectoryA(char*, UINT) { return 0; }
HANDLE __stdcall CreateFileA(LPCSTR, DWORD, DWORD, LPVOID, DWORD, DWORD, HANDLE) { return 0; }
BOOL __stdcall WriteFile(HANDLE, LPCVOID, DWORD, DWORD*, LPVOID) { return 0; }
BOOL __stdcall CloseHandle(HANDLE) { return 0; }
HANDLE __stdcall CreateThread(LPVOID, DWORD, LPTHREAD_START_ROUTINE, LPVOID, DWORD, DWORD*) { return 0; }
void __stdcall Sleep(DWORD) {}
int __stdcall FreeLibrary(HMODULE) { return 0; }
HMODULE __stdcall GetModuleHandleA(LPCSTR) { return 0; }
DWORD __stdcall GetUserDefaultLCID() { return 0; }
BOOL __stdcall SetEnvironmentVariableA(LPCSTR, LPCSTR) { return 0; }
DWORD __stdcall GetLastError() { return 0; }
DWORD __stdcall GetFileSize(HANDLE, DWORD*) { return 0; }
DWORD __stdcall SetFilePointer(HANDLE, long, long*, DWORD) { return 0; }
BOOL __stdcall ReleaseMutex(HANDLE) { return 0; }
BOOL __stdcall PulseEvent(HANDLE) { return 0; }
BOOL __stdcall ResetEvent(HANDLE) { return 0; }
long __stdcall InterlockedIncrement(long*) { return 0; }
long __stdcall InterlockedDecrement(long*) { return 0; }
HANDLE __stdcall GetProcessHeap() { return 0; }
LPVOID __stdcall HeapAlloc(HANDLE, DWORD, DWORD) { return 0; }
BOOL __stdcall HeapFree(HANDLE, DWORD, LPVOID) { return 0; }
DWORD __stdcall SuspendThread(HANDLE) { return 0; }
DWORD __stdcall ResumeThread(HANDLE) { return 0; }
}
