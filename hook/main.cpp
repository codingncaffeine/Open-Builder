// The hook DLL. The original program imports VERSION.dll; this DLL takes its place (loaded from the program's
// folder ahead of the system one), passes every VERSION.dll function on to the real one (other DLLs in the
// process load version.dll by name and get this one too), and on load replaces every function in the hook table:
// a jump at the original address leads, through a counter, to our version. Every few seconds the counts go to
// ob-hooks.txt in the current folder, so a run shows which of our functions the game actually called.
#include "win32.h"
#include "hooks.h"

// Code that uses floating point refers to the C runtime's _fltused. This DLL has no runtime of its own (decompiled
// code calls the original's), so it defines the marker itself.
extern "C" int _fltused = 0x9875;

namespace {

const unsigned kThunkSize = 11;  // inc dword [count] (6 bytes) + jmp rel32 (5 bytes)

volatile long* g_counts;

void WriteJump(unsigned char* at, const void* to)
{
    at[0] = 0xE9;
    *reinterpret_cast<long*>(at + 1) = static_cast<long>(reinterpret_cast<const unsigned char*>(to) - (at + 5));
}

void InstallHooks()
{
    unsigned char* thunks = static_cast<unsigned char*>(
        VirtualAlloc(0, g_hookCount * kThunkSize + g_hookCount * sizeof(long), MEM_COMMIT | MEM_RESERVE,
                     PAGE_EXECUTE_READWRITE));
    if (!thunks) return;
    g_counts = reinterpret_cast<volatile long*>(thunks + g_hookCount * kThunkSize);

    for (unsigned i = 0; i < g_hookCount; ++i) {
        unsigned char* thunk = thunks + i * kThunkSize;
        thunk[0] = 0xFF;  // inc dword ptr [abs32]
        thunk[1] = 0x05;
        *reinterpret_cast<volatile long**>(thunk + 2) = &g_counts[i];
        WriteJump(thunk + 6, g_hooks[i].replacement);
        if (!g_hooks[i].hook) continue;

        unsigned char* original = reinterpret_cast<unsigned char*>(g_hooks[i].original);
        DWORD old;
        if (VirtualProtect(original, 5, PAGE_EXECUTE_READWRITE, &old)) {
            WriteJump(original, thunk);
            VirtualProtect(original, 5, old, &old);
        }
    }
    FlushInstructionCache(GetCurrentProcess(), 0, 0);
}

char* Append(char* out, const char* text)
{
    while (*text) *out++ = *text++;
    return out;
}

char* AppendNumber(char* out, unsigned long value, unsigned base, int width)
{
    char digits[16];
    int n = 0;
    do { digits[n++] = "0123456789abcdef"[value % base]; value /= base; } while (value);
    while (n < width) digits[n++] = '0';
    while (n) *out++ = digits[--n];
    return out;
}

// Rewrites ob-hooks.txt every two seconds: "<original address> <calls> <name>" per hooked function.
DWORD __stdcall Report(LPVOID)
{
    static char text[64 * 1024];
    for (;;) {
        Sleep(2000);
        char* out = text;
        for (unsigned i = 0; i < g_hookCount && out < text + sizeof text - 256; ++i) {
            out = Append(out, "0x");
            out = AppendNumber(out, g_hooks[i].original, 16, 8);
            out = Append(out, " ");
            out = AppendNumber(out, static_cast<unsigned long>(g_counts[i]), 10, 1);
            out = Append(out, " ");
            out = Append(out, g_hooks[i].name);
            out = Append(out, "\r\n");
        }
        HANDLE file = CreateFileA("ob-hooks.txt", GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS,
                                  FILE_ATTRIBUTE_NORMAL, 0);
        if (file != INVALID_HANDLE_VALUE) {
            DWORD written;
            WriteFile(file, text, static_cast<DWORD>(out - text), &written, 0);
            CloseHandle(file);
        }
    }
}

// Every export of the real VERSION.dll (Windows 10's list; Wine lacks GetFileVersionInfoByHandle, which then stays
// null, as nothing there imports it).
#define OB_VERSION_EXPORTS(X)                                                                                     \
    X(0, GetFileVersionInfoA) X(1, GetFileVersionInfoByHandle) X(2, GetFileVersionInfoExA)                      \
    X(3, GetFileVersionInfoExW) X(4, GetFileVersionInfoSizeA) X(5, GetFileVersionInfoSizeExA)                   \
    X(6, GetFileVersionInfoSizeExW) X(7, GetFileVersionInfoSizeW) X(8, GetFileVersionInfoW) X(9, VerFindFileA)  \
    X(10, VerFindFileW) X(11, VerInstallFileA) X(12, VerInstallFileW) X(13, VerLanguageNameA)                   \
    X(14, VerLanguageNameW) X(15, VerQueryValueA) X(16, VerQueryValueW)

#define OB_NAME(index, name) #name,
const char* const kVersionExports[] = { OB_VERSION_EXPORTS(OB_NAME) };
#undef OB_NAME
const unsigned kVersionExportCount = sizeof kVersionExports / sizeof kVersionExports[0];
LPVOID g_realVersion[kVersionExportCount];  // filled by LoadRealVersion, read by the Forward_ jumps

// Loads the real VERSION.dll by full path (so this DLL is not found again) and fills g_realVersion.
void LoadRealVersion()
{
    char path[260];
    UINT n = GetSystemDirectoryA(path, 260 - 16);
    *Append(path + n, "\\version.dll") = 0;
    HMODULE real = LoadLibraryA(path);
    if (!real) return;
    for (unsigned i = 0; i < kVersionExportCount; ++i) g_realVersion[i] = GetProcAddress(real, kVersionExports[i]);
}

}  // namespace

extern "C" {

// Each export is a bare jump to the real function, so arguments and calling convention pass through untouched.
#define OB_FORWARD(index, name) \
    __declspec(naked) void Forward_##name() { __asm { jmp dword ptr [g_realVersion + index * 4] } }
OB_VERSION_EXPORTS(OB_FORWARD)
#undef OB_FORWARD

BOOL __stdcall DllMain(HMODULE, DWORD reason, LPVOID)
{
    if (reason == DLL_PROCESS_ATTACH) {
        LoadRealVersion();
        InstallHooks();
        DWORD id;
        CreateThread(0, 0, Report, 0, 0, &id);
    }
    return 1;
}

}  // extern "C"
