// Fixed-size integer types: <stdint.h> where the compiler has one, spelled out for the 2003 compiler, which has none.
#ifndef OB_COMMON_TYPES_H
#define OB_COMMON_TYPES_H

#if defined(_MSC_VER) && _MSC_VER < 1600
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

#endif
