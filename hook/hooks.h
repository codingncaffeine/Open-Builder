// The table of decompiled functions the hook DLL swaps into the original program. One entry per function:
// its address in the original and ours. The table sits in its own section (.obhook) so tools can read the pairs
// straight from the built DLL.
#ifndef OB_HOOK_HOOKS_H
#define OB_HOOK_HOOKS_H

struct HookEntry {
    unsigned long original;  // address of the function in the original program
    void* replacement;       // our compiled version
    const char* name;
};

// Address of any function, member functions included (a non-virtual member function pointer of a class with
// single inheritance is a plain code address in this compiler).
template <class T> void* FunctionAddress(T function)
{
    union { T function; void* address; } u;
    u.function = function;
    return u.address;
}

extern const HookEntry g_hooks[];
extern const unsigned g_hookCount;

#endif
