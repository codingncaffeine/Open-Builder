// Compiler-specific keywords the original's code relies on, as macros that are empty where they do not exist.
#ifndef OB_COMMON_COMPILER_H
#define OB_COMMON_COMPILER_H

// An interface class whose constructor never stores a vtable of its own (only the most-derived class's is used).
#ifdef _MSC_VER
#define OB_NOVTABLE __declspec(novtable)
#else
#define OB_NOVTABLE
#endif

// The Windows API's calling convention (callee pops), for the functions the original hands to Windows.
#ifdef _MSC_VER
#define OB_STDCALL __stdcall
#else
#define OB_STDCALL
#endif

// A pointer that arrives as a 32-bit integer (a slot or field not typed yet), and the way back. Macros on purpose:
// the 2003 compiler evaluates an inlined function call before the other arguments of the call it sits in, which
// swaps the registers the original's code uses; a cast expression is evaluated in place.
#define OB_PTR(Type, value) reinterpret_cast<Type*>(static_cast<uintptr_t>(value))
#define OB_ADDR(p) static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p))

#endif
