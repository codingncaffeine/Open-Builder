// Text conversion between a cIGZString (UTF-8) and other encodings. Not decompiled yet: the calls reach the
// original (hook/stubs.txt). Names, return values and the encoding constants assumed from their callers.
#ifndef OB_GZCOM_RZTEXTENCODING_H
#define OB_GZCOM_RZTEXTENCODING_H

#include "common/types.h"

class cIGZString;

static const int32_t kRZEncodingUTF16 = 0x10;
// The encoding of a cIGZString's own text.
static const int32_t kRZEncodingString = -2;

// Converts the string into dest; length holds the capacity of dest in units on entry and the units written on return.
uint32_t RZStringToEncoding(const cIGZString& source, void* dest, uint32_t& length, int32_t encoding);
// Replaces dest with the length units of source.
uint32_t RZEncodingToString(const void* source, uint32_t length, int32_t encoding, cIGZString& dest);
// The bytes of the character text starts with, of the length bytes there; 0 when there is none.
int32_t RZCharacterSize(const char* text, int32_t length, int32_t encoding);
// The characters in the length bytes of text.
int32_t RZCharacterCount(const char* text, int32_t length, int32_t encoding);

#endif
