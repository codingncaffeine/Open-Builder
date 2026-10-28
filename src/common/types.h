// Fixed-size integer types. The 2003 compiler has no <stdint.h>, so they are spelled out here for it and for every
// later compiler alike.
#ifndef OB_COMMON_TYPES_H
#define OB_COMMON_TYPES_H

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;

#endif
