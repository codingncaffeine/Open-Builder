// The table of decompiled functions the hook DLL swaps into the original program. One entry per function:
// its address in the original and ours. tools/gen-hooks.sh writes it from the FUNCTION annotations in src/; it
// sits in its own section (.obhook) so tools can read the pairs straight from the built DLL.
#ifndef OB_HOOK_HOOKS_H
#define OB_HOOK_HOOKS_H

struct HookEntry {
    unsigned long original;  // address of the function in the original program
    void* replacement;       // our compiled version
    const char* name;
    int hook;                // 0: matched but never patched in (too small for the jump)
};

extern const HookEntry g_hooks[];
extern const unsigned g_hookCount;

#endif
