// Never run: linked into a throwaway wininet.dll only so the linker writes wininet.lib with the right import names
// (as sdk/kernel32_stub.cpp does for kernel32).
#include "win32.h"

extern "C" {
BOOL __stdcall InternetSetOptionA(void*, DWORD, void*, DWORD) { return 0; }
}
