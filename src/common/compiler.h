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

// The argument of the constructor a generated class gets only so its vtable is emitted (tools/obcmp/obdecl): a class
// whose real constructor is still the original's (a STUB) is constructed through it by GeneratedClasses, never at run time.
struct ob_emit {
};

// A pointer that arrives as a 32-bit integer (a slot or field not typed yet), and the way back. Macros on purpose:
// the 2003 compiler evaluates an inlined function call before the other arguments of the call it sits in, which
// swaps the registers the original's code uses; a cast expression is evaluated in place.
#define OB_PTR(Type, value) reinterpret_cast<Type*>(static_cast<uintptr_t>(value))
#define OB_ADDR(p) static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p))

// The scanf conversion of a 64-bit integer (a long long): the 2003 runtime spells it its own way.
#ifdef _MSC_VER
#define OB_SCN_INT64 "%I64d"
#else
#define OB_SCN_INT64 "%lld"
#endif

#endif
