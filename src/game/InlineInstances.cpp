// Stands in for the game's sources until they are decompiled. The original has each inline function of the
// framework's headers out of line once, compiled with the game's flags by the first game source that used it, and
// the framework's own code calls those copies. Using the functions here makes this build compile them the same way;
// an entry leaves when the game source that first used it is decompiled.
#include "gzcom/cRZString.h"

void UseInlineInstances(const char* text, uint32_t length, const cIGZString& string, const cRZString& rzString,
                        const std::string& stdString)
{
    cRZString empty;
    cRZString fromText(text);
    cRZString fromRange(text, length);
    cRZString fromString(string);
    cRZString fromStdString(stdString);
    cRZString copy(rzString);
    copy = rzString;
}

// The game deletes arrays of strings, so the string's vtable holds a vector deleting destructor (0x0044bf10).
void UseStringArrays(uint32_t count)
{
    cRZString* strings = new cRZString[count];
    delete[] strings;
}
