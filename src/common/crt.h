// C runtime functions the original's runtime has under other names or with other contracts, given one spelling.
#ifndef OB_COMMON_CRT_H
#define OB_COMMON_CRT_H

#include <stdio.h>

// _snprintf: -1 when the text does not fit in count bytes. C99's snprintf returns the length it needed instead, so
// elsewhere a wrapper keeps the old contract (and always terminates the text).
#if defined(_MSC_VER) && _MSC_VER < 1900
#define OB_SNPRINTF _snprintf
#else
#include <stdarg.h>

inline int ob_snprintf(char* buffer, size_t count, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    int length = vsnprintf(buffer, count, format, args);
    va_end(args);
    return length < 0 || static_cast<size_t>(length) >= count ? -1 : length;
}
#define OB_SNPRINTF ob_snprintf
#endif


// _strnicmp: case-blind compare of at most count bytes; POSIX calls it strncasecmp.
#ifdef _MSC_VER
#include <string.h>
#define OB_STRNICMP _strnicmp
#else
#include <strings.h>
#define OB_STRNICMP strncasecmp
#endif

#endif
