#include "hooks.h"

#include "unidentified/cUnk0098e9a0.h"

#pragma data_seg(".obhook")
#pragma const_seg(".obhook")

const HookEntry g_hooks[] = {
    { 0x0098e9a0, FunctionAddress(&cUnk0098e9a0::ForwardSlot15), "cUnk0098e9a0::ForwardSlot15" },
};

#pragma const_seg()
#pragma data_seg()

const unsigned g_hookCount = sizeof g_hooks / sizeof g_hooks[0];
