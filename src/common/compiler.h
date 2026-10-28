// Compiler-specific keywords the original's code relies on, as macros that are empty where they do not exist.
#ifndef OB_COMMON_COMPILER_H
#define OB_COMMON_COMPILER_H

// An interface class whose constructor never stores a vtable of its own (only the most-derived class's is used).
#ifdef _MSC_VER
#define OB_NOVTABLE __declspec(novtable)
#else
#define OB_NOVTABLE
#endif

#endif
