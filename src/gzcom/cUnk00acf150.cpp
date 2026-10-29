#include "classes/cUnk00acf150.h"
#include "gzcom/cRZString.h"
#include <new>
#include <stdio.h>
#include <string.h>
#include <time.h>

// STUB: 0x0090fef4
void Fn0090fef4(const void* source, uint32_t count, char* text);

// STUB: 0x0090ff33
bool Fn0090ff33(const char* text, uint32_t length, void* dest);

// STUB: 0x009205a0
void Fn009205a0(uint32_t microseconds);

// STUB: 0x0090f31b
void Fn0090f31b(const cRZString* source, std::string* dest);

// The byte stream the file object reads and writes through (the original builds a 0x80-byte one of its own when
// none is set). Slots by their vtable offsets.
struct Stream_acf150 {
    virtual void Pad00_acf150();
    virtual uint32_t AddRef();                                  // 0x04
    virtual uint32_t Release();                                 // 0x08
    virtual bool Open(uint32_t mode, uint32_t share, uint32_t flag);  // 0x0c
    virtual bool IsOpen();                                      // 0x10
    virtual void Close();                                       // 0x14
    virtual uint32_t GetPosition();                             // 0x18
    virtual uint32_t GetSize();                                 // 0x1c
    virtual void SetSize(uint32_t size);                        // 0x20
    virtual void Pad09_acf150();                                // 0x24
    virtual void Pad10_acf150();                                // 0x28
    virtual void Skip(int32_t count);                           // 0x2c
    virtual uint32_t Seek(uint32_t position);                   // 0x30
    virtual void Pad13_acf150();                                // 0x34
    virtual bool Read(void* buffer, uint32_t count);            // 0x38
    virtual void Pad15_acf150();                                // 0x3c
    virtual void Write(const void* buffer, uint32_t count);     // 0x40
    virtual void Pad17_acf150();                                // 0x44
    virtual void Pad18_acf150();                                // 0x48
    virtual void Pad19_acf150();                                // 0x4c
    virtual void Pad20_acf150();                                // 0x50
    virtual bool Fn21();                                        // 0x54
    virtual void Pad22_acf150();                                // 0x58
    virtual void Pad23_acf150();                                // 0x5c
    virtual void Pad24_acf150();                                // 0x60
    virtual void Pad25_acf150();                                // 0x64
    virtual void Pad26_acf150();                                // 0x68
    virtual void Pad27_acf150();                                // 0x6c
    virtual void SetName(void* name);                           // 0x70
    virtual bool GetMode(uint32_t* mode, uint32_t* a, uint32_t* b);   // 0x74
    char mPad_acf150[0x7c];
    // STUB: 0x00918b96
    Stream_acf150();
};

// A node of either map: the tree links, the key (a lower-case name), then the value (a position in the first map,
// the name as written in the second).
struct Node_acf150 {
    uint32_t mnColor;
    Node_acf150* mpParent;
    Node_acf150* mpLeft;
    Node_acf150* mpRight;
    cRZString mKey;
    uint32_t mnValue;
    uint8_t mPad_acf150[0x10];
};

// STUB: 0x0040d4c0
Node_acf150* Fn0040d4c0(Node_acf150* node);

struct EntryA_acf150;
struct PairMap_acf150;

// The two maps (STLport red-black trees: header pointer, count, compare) at +0x1c and +0x28.
struct Map_acf150 {
    Node_acf150* mpHeader;
    uint32_t mnCount;
    uint32_t mnCompare;
    // STUB: 0x00662840
    Node_acf150* Find(const cRZString* key);
    // STUB: 0x00662af0
    void Clear();
    // STUB: 0x00662ef0
    void InsertA(void* result, const EntryA_acf150& item);
    // STUB: 0x0081d300
    void InsertB(void* result, const PairMap_acf150& item);
};

// A name whose destructor the original calls out of line.
struct Name_acf150 : public cRZString {
    using cRZString::operator=;
    // STUB: 0x00414250
    ~Name_acf150();
};

// The entry of the second map (the lower-case name, the name as written).
struct PairMap_acf150 {
    cRZString first;
    Name_acf150 second;
    // STUB: 0x006004b0
    PairMap_acf150(const cRZString& a, const cRZString& b);
};

// The entry of the first map (the lower-case name, where the section starts).
struct EntryA_acf150 {
    cRZString first;
    uint32_t second;
    EntryA_acf150(const cRZString& name)
        : first(name, 0, std::string::npos)
    {
    }
};

// A line of a section: the key and its value.
struct PairLine_acf150 {
    cRZString first;
    Name_acf150 second;
    // STUB: 0x0091c9c6
    PairLine_acf150(const cRZString& a, const cRZString& b);
};

struct Lines_acf150 {
    PairLine_acf150* mpBegin;
    PairLine_acf150* mpEnd;
    PairLine_acf150* mpCap;
    Lines_acf150()
        : mpBegin(0), mpEnd(0), mpCap(0)
    {
    }
    // STUB: 0x0091ce50
    ~Lines_acf150();
    // STUB: 0x0091d130
    void PushBack(const PairLine_acf150& item);
};

// A list of names.
struct ListNode_acf150 {
    ListNode_acf150* mpNext;
    ListNode_acf150* mpPrev;
    cRZString mData;
};

struct List_acf150 {
    ListNode_acf150* mpHead;
    // STUB: 0x0043aef0
    List_acf150(const void* allocator);
    // STUB: 0x0043af20
    ~List_acf150();
    // STUB: 0x004580e0
    void PushBack(const cRZString* item);
};


static inline Stream_acf150* StreamOf_acf150(cUnk00acf150* self)
{
    return static_cast<Stream_acf150*>(self->mpStream);
}

inline void AssignRange_acf150(cRZString& dest, const char* text, int length)
{
    static_cast<std::string&>(dest).assign(text, text + length);
}

static inline Map_acf150* MapAOf_acf150(cUnk00acf150* self)
{
    return reinterpret_cast<Map_acf150*>(self->mMapA);
}

// FUNCTION: 0x0091c574
bool cUnk00acf150::Slot04_acf150(void* stream)
{
    Stream_acf150* s = static_cast<Stream_acf150*>(stream);
    if (s != StreamOf_acf150(this)) {
        Slot05_acf150();
        if (s) {
            s->AddRef();
        }
        if (mpStream) {
            StreamOf_acf150(this)->Release();
        }
        mpStream = s;
        if (!s) {
            Stream_acf150* made = new Stream_acf150;
            mpStream = made;
            made->AddRef();
            StreamOf_acf150(this)->SetName(&mName);
        }
    }
    return true;
}

// FUNCTION: 0x0091c699
bool cUnk00acf150::Slot16_acf150(bool keepOpen)
{
    if (mbKeepOpen != keepOpen) {
        mbKeepOpen = keepOpen;
        if (!keepOpen) {
            Slot05_acf150();
        }
    }
    return true;
}

// FUNCTION: 0x0091cb95
void cUnk00acf150::Slot02_acf150(void* name)
{
    if (mbParsed) {
        Slot05_acf150();
    }
    mName = *static_cast<cRZString*>(name);
}

// FUNCTION: 0x0091ce29
bool cUnk00acf150::Slot05_acf150()
{
    if (StreamOf_acf150(this)->IsOpen()) {
        StreamOf_acf150(this)->Close();
    }
    MapAOf_acf150(this)->Clear();
    mbParsed = false;
    return true;
}

// FUNCTION: 0x0091c8d2
bool cUnk00acf150::Slot07_acf150(void* section, void* key, void* value)
{
    cRZString text;
    if (Slot06_acf150(section, key, &text)) {
        // 64-bit debt: the original's long is 32 bits; natively this must read into an int32_t.
        if (sscanf(text.c_str(), "%ld", static_cast<long*>(value)) == 1) {
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x0091c6b3
bool cUnk00acf150::Slot11_acf150(void* section, void* key, uint32_t value)
{
    cRZString* s = static_cast<cRZString*>(section);
    cRZString* k = static_cast<cRZString*>(key);
    if (s->size() && k->size()) {
        cRZString text;
        text.Sprintf("%ld", value);
        return Slot10_acf150(section, key, &text);
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0091c722 score 2
bool cUnk00acf150::Slot12_acf150(void* section, void* key, void* data, uint32_t count)
{
    cRZString* s = static_cast<cRZString*>(section);
    cRZString* k = static_cast<cRZString*>(key);
    bool result = false;
    if (s->size() && k->size()) {
        uint32_t length = count * 2;
        char* text = static_cast<char*>(operator new(length + 1));
        Fn0090fef4(data, count, text);
        *(length + text) = 0;
        bool ok;
        {
            cRZString value(text);
            ok = Slot10_acf150(section, key, &value);
        }
        if (ok) {
            result = true;
        }
        operator delete(text);
    }
    return result;
}
#endif

// FUNCTION: 0x0091c7b5
uint32_t cUnk00acf150::Slot09_acf150(void* section, void* key, void* out)
{
    cRZString text;
    if (Slot06_acf150(section, key, &text)) {
        void** dest = static_cast<void**>(out);
        *dest = operator new(text.size() / 2);
        if (!Fn0090ff33(text.c_str(), text.size(), *dest)) {
            operator delete(*dest);
            *dest = 0;
            return 0;
        }
    }
    return text.size() / 2;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0091c84f score 6
uint32_t cUnk00acf150::Slot08_acf150(void* section, void* key, void* data, uint32_t count)
{
    cRZString text;
    if (Slot06_acf150(section, key, &text)) {
        uint32_t length = count * 2;
        if (length > text.size()) {
            length = text.size();
        }
        if (Fn0090ff33(text.c_str(), length, data)) {
            return length / 2;
        }
    }
    return 0;
}
#endif

// FUNCTION: 0x0091c95a
bool cUnk00acf150::Slot15_acf150(void* name)
{
    if (mbParsed || Slot17_acf150(false)) {
        cRZString key(*static_cast<cIGZString*>(name));
        key.MakeLower();
        if (!mbKeepOpen) {
            Slot05_acf150();
        }
        Map_acf150* map = MapAOf_acf150(this);
        void* end = map->mpHeader;
        return map->Find(&key) != end;
    }
    return false;
}

// FUNCTION: 0x0091c5db
bool cUnk00acf150::Slot19_acf150(bool write)
{
    uint32_t mode = write ? 3 : 1;
    uint32_t share = write ? 3 : 2;
    uint32_t flag = write ? 0 : 1;
    if (StreamOf_acf150(this)->IsOpen()) {
        uint32_t current = 0;
        uint32_t t = 0;
        uint32_t u = 0;
        StreamOf_acf150(this)->GetMode(&current, &t, &u);
        if (mode == current) {
            return true;
        }
    }
    uint32_t t0 = static_cast<uint32_t>(time(0));
    do {
        if (StreamOf_acf150(this)->Open(mode, share, flag)) {
            mbWriteMode = write;
            return true;
        }
        if (!StreamOf_acf150(this)->Fn21()) {
            break;
        }
        int32_t now = static_cast<int32_t>(time(0));
        Fn009205a0(250000);
        if (now - static_cast<int32_t>(t0) >= 3) {
            break;
        }
    } while (true);
    return false;
}

inline Map_acf150* MapBOf_acf150(cUnk00acf150* self)
{
    return reinterpret_cast<Map_acf150*>(self->mMapB);
}

// FUNCTION: 0x0091ca15
bool cUnk00acf150::Slot18_acf150(void* out)
{
    std::string text;
    bool any = false;
    uint32_t position = StreamOf_acf150(this)->GetPosition();
    uint32_t remaining = StreamOf_acf150(this)->GetSize() - position;
    bool eol = false;
    cRZString& line = *static_cast<cRZString*>(out);
    line.resize(0, 0);
    char buffer[0x2a];
    memset(buffer, 0, 0x2a);
    if (remaining) {
        do {
            uint32_t chunk = 0x28;
            if (remaining <= 0x28) {
                chunk = remaining;
            }
            if (!StreamOf_acf150(this)->Read(buffer, chunk)) {
                break;
            }
            remaining -= chunk;
            any = true;
            uint32_t i = 0;
            if (i < chunk) {
                do {
                    char c = buffer[i];
                    if (c == 0xd || c == 0xa) {
                        buffer[i] = 0;
                        eol = true;
                        StreamOf_acf150(this)->Seek(position + i);
                        char next;
                        while (StreamOf_acf150(this)->Read(&next, 1)) {
                            if (next != 0xd && next != 0xa) {
                                StreamOf_acf150(this)->Skip(-1);
                                break;
                            }
                        }
                        break;
                    }
                    ++i;
                } while (i < chunk);
            }
            buffer[i] = 0;
            text += buffer;
            if (eol) {
                break;
            }
            position = StreamOf_acf150(this)->GetPosition();
        } while (remaining);
    }
    RZStringFromStd(text, line);
    return any;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0091cfa5 score 81
bool cUnk00acf150::Slot14_acf150(void* callback, uint32_t argument)
{
    if (!mbParsed && !Slot17_acf150(false)) {
        if (!mbKeepOpen) {
            Slot05_acf150();
        }
        return false;
    }
    typedef void (*Callback_acf150)(cRZString*, cRZString*, uint32_t);
    cRZString empty;
    List_acf150 names(reinterpret_cast<char*>(&argument) + 3);
    Node_acf150* node = MapAOf_acf150(this)->mpHeader->mpLeft;
    if (node != MapAOf_acf150(this)->mpHeader) {
        Map_acf150* map = MapBOf_acf150(this);
        do {
            Node_acf150* found = map->Find(&node->mKey);
            names.PushBack(found == map->mpHeader ? &node->mKey : reinterpret_cast<const cRZString*>(reinterpret_cast<char*>(found) + 0x24));
            node = Fn0040d4c0(node);
        } while (node != MapAOf_acf150(this)->mpHeader);
    }
    ListNode_acf150* head = names.mpHead;
    for (ListNode_acf150* item = head->mpNext; item != head; item = item->mpNext) {
        reinterpret_cast<Callback_acf150>(callback)(&item->mData, &empty, argument);
    }
    if (!mbKeepOpen) {
        Slot05_acf150();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0091cbb3 score 137
bool cUnk00acf150::Slot06_acf150(void* section, void* key, void* out)
{
    if (!mbParsed && !Slot17_acf150(false)) {
        if (!mbKeepOpen) {
            Slot05_acf150();
        }
        return false;
    }
    cRZString lowSection(*static_cast<cRZString*>(section));
    lowSection.MakeLower();
    cRZString lowKey(*static_cast<cRZString*>(key));
    lowKey.MakeLower();
    Map_acf150* map = MapAOf_acf150(this);
    Node_acf150* found = map->Find(&lowSection);
    Stream_acf150* stream;
    uint32_t position;
    if (found == map->mpHeader || (stream = StreamOf_acf150(this), position = stream->Seek(found->mnValue)) >= stream->GetSize()) {
        if (!mbKeepOpen) {
            Slot05_acf150();
        }
        return false;
    }
    cRZString line;
    cRZString text;
    if (Slot18_acf150(&text)) {
        while (Slot18_acf150(&text)) {
            text.TrimLeft();
            if (text.size() == 0) {
                continue;
            }
            char c = text[0];
            if (c == ';') {
                continue;
            }
            if (c == '[') {
                text.resize(0, 0);
                break;
            }
            line = text.SplitAt("=");
            line.TrimRight();
            line.MakeLower();
            if (static_cast<std::string&>(line) == static_cast<std::string&>(lowKey)) {
                text.Trim();
                *static_cast<cRZString*>(out) = text;
                if (!mbKeepOpen) {
                    Slot05_acf150();
                }
                return true;
            }
        }
    }
    if (!mbKeepOpen) {
        Slot05_acf150();
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0091db73 score 7
bool cUnk00acf150::Slot17_acf150(bool create)
{
    MapAOf_acf150(this)->Clear();
    if (!StreamOf_acf150(this)->IsOpen()) {
        StreamOf_acf150(this)->SetName(&mName);
        if (!Slot19_acf150(create)) {
            return false;
        }
    }
    cRZString line;
    cRZString name;
    cRZString lower;
    StreamOf_acf150(this)->Pad09_acf150();
    uint32_t position = StreamOf_acf150(this)->GetPosition();
    while (Slot18_acf150(&line)) {
        line.TrimLeft();
        int n = line.size();
        const char* s = line.c_str();
        if (n && s[0] == '[') {
            for (int i = 1; i < n; i++) {
                if (s[i] == ']') {
                    if (i >= 2) {
                        AssignRange_acf150(name, line.Mid(1, std::string::npos).ToChar(), i - 1);
                        lower = name;
                        lower.MakeLower();
                        char result[8];
                        {
                            EntryA_acf150 entry(lower);
                            entry.second = position;
                            MapAOf_acf150(this)->InsertA(result, entry);
                        }
                        MapBOf_acf150(this)->InsertB(result, PairMap_acf150(lower, name));
                    }
                    break;
                }
            }
        }
        position = StreamOf_acf150(this)->GetPosition();
    }
    mbParsed = true;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0091d91c score 141
bool cUnk00acf150::Slot13_acf150(void* section, void* callback, uint32_t argument)
{
    typedef void (*Callback_acf150)(cRZString*, cRZString*, uint32_t);
    if (!mbParsed && !Slot17_acf150(false)) {
        if (!mbKeepOpen) {
            Slot05_acf150();
        }
        return false;
    }
    cRZString lowSection(*static_cast<cRZString*>(section));
    lowSection.MakeLower();
    Map_acf150* map = MapAOf_acf150(this);
    Node_acf150* found = map->Find(&lowSection);
    Stream_acf150* stream;
    uint32_t position;
    if (found == map->mpHeader || (stream = StreamOf_acf150(this), position = stream->Seek(found->mnValue)) >= stream->GetSize()) {
        if (!mbKeepOpen) {
            Slot05_acf150();
        }
        return false;
    }
    cRZString line;
    cRZString text;
    if (Slot18_acf150(&text)) {
        Lines_acf150 lines;
        while (Slot18_acf150(&text)) {
            text.TrimLeft();
            if (text.size() == 0) {
                continue;
            }
            char c = text[0];
            if (c == ';') {
                continue;
            }
            if (c == '[') {
                break;
            }
            line = text.SplitAt("=");
            line.TrimRight();
            text.Trim();
            if (line.size() && text.size()) {
                lines.PushBack(PairLine_acf150(line, text));
            }
        }
        int count = lines.mpEnd - lines.mpBegin;
        PairLine_acf150* item = lines.mpBegin;
        for (int i = count; i > 0; --i) {
            reinterpret_cast<Callback_acf150>(callback)(&item->first, &item->second, argument);
            ++item;
        }
        if (!mbKeepOpen) {
            Slot05_acf150();
        }
        return true;
    }
    if (!mbKeepOpen) {
        Slot05_acf150();
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0091d168 score 549
bool cUnk00acf150::Slot10_acf150(void* section, void* key, void* value)
{
    cRZString* sec = static_cast<cRZString*>(section);
    cRZString* k = static_cast<cRZString*>(key);
    cRZString* val = static_cast<cRZString*>(value);
    if (sec->size() && k->size()) {
        cRZString head;
        cRZString entry;
        std::string headText;
        std::string entryText;
        if (mName.size()) {
            StreamOf_acf150(this)->SetName(&mName);
        }
        if (mName.size() && !StreamOf_acf150(this)->Fn21()) {
            mbParsed = false;
            if (StreamOf_acf150(this)->IsOpen()) {
                StreamOf_acf150(this)->Close();
            }
            if (Slot19_acf150(true)) {
                head.Sprintf("[%s]%s", sec->c_str(), "\r\n");
                Fn0090f31b(&head, &headText);
                StreamOf_acf150(this)->Write(headText.c_str(), headText.size());
                entry.Sprintf("%s = %s%s", k->c_str(), val->c_str(), "\r\n");
                Fn0090f31b(&entry, &entryText);
                StreamOf_acf150(this)->Write(entryText.c_str(), entryText.size());
                if (!mbKeepOpen) {
                    Slot05_acf150();
                }
                return true;
            }
            return false;
        }
        if (mbParsed || Slot17_acf150(true)) {
            if (!mbWriteMode) {
                if (StreamOf_acf150(this)->IsOpen()) {
                    StreamOf_acf150(this)->Close();
                }
            }
            if (StreamOf_acf150(this)->IsOpen() || Slot19_acf150(true)) {
                cRZString lowSection(*sec);
                lowSection.MakeLower();
                cRZString lowKey(*k);
                lowKey.MakeLower();
                Map_acf150* map = MapAOf_acf150(this);
                Node_acf150* found = map->Find(&lowSection);
                if (found == map->mpHeader) {
                    StreamOf_acf150(this)->Pad10_acf150();
                    bool single = false;
                    if (StreamOf_acf150(this)->GetPosition() > 0) {
                        char ch = 0;
                        StreamOf_acf150(this)->Skip(-1);
                        if (StreamOf_acf150(this)->Read(&ch, 1) && (ch == 0xd || ch == 0xa)) {
                            single = true;
                        }
                    }
                    if (single) {
                        head.Sprintf("%s", "\r\n");
                    } else {
                        head.Sprintf("%s%s", "\r\n", "\r\n");
                    }
                    Fn0090f31b(&head, &headText);
                    StreamOf_acf150(this)->Write(headText.c_str(), headText.size());
                    uint32_t position = StreamOf_acf150(this)->GetPosition();
                    head.Sprintf("[%s]%s", sec->c_str(), "\r\n");
                    Fn0090f31b(&head, &headText);
                    StreamOf_acf150(this)->Write(headText.c_str(), headText.size());
                    entry.Sprintf("%s = %s%s", k->c_str(), val->c_str(), "\r\n");
                    Fn0090f31b(&entry, &entryText);
                    StreamOf_acf150(this)->Write(entryText.c_str(), entryText.size());
                    {
                        EntryA_acf150 added(lowSection);
                        added.second = position;
                        char result[8];
                        map->InsertA(result, added);
                        MapBOf_acf150(this)->InsertB(result, PairMap_acf150(lowSection, *sec));
                    }
                    if (!mbKeepOpen) {
                        Slot05_acf150();
                    }
                    return true;
                }
                Stream_acf150* stream = StreamOf_acf150(this);
                uint32_t start = stream->Seek(found->mnValue);
                if (start < stream->GetSize()) {
                    cRZString lineKey;
                    cRZString lowKey2(*k);
                    cRZString text;
                    lowKey2.MakeLower();
                    if (Slot18_acf150(&text)) {
                        uint32_t lineStart = StreamOf_acf150(this)->GetPosition();
                        bool replace = false;
                        bool insert = false;
                        while (Slot18_acf150(&text)) {
                            text.TrimLeft();
                            if (text.size()) {
                                char c = text[0];
                                if (c != ';') {
                                    if (c == '[') {
                                        insert = true;
                                        break;
                                    }
                                    lineKey = text.SplitAt("=");
                                    lineKey.TrimRight();
                                    lineKey.MakeLower();
                                    if (static_cast<std::string&>(lineKey) == static_cast<std::string&>(lowKey2)) {
                                        replace = true;
                                        break;
                                    }
                                }
                            }
                            lineStart = StreamOf_acf150(this)->GetPosition();
                        }
                        if (insert || replace) {
                            uint32_t tailStart = lineStart;
                            if (replace) {
                                tailStart = StreamOf_acf150(this)->GetPosition();
                            }
                            uint32_t tailSize = StreamOf_acf150(this)->GetSize() - tailStart;
                            void* tail = operator new(tailSize);
                            bool ok;
                            if (insert) {
                                StreamOf_acf150(this)->Seek(lineStart);
                                ok = StreamOf_acf150(this)->Read(tail, tailSize);
                            } else {
                                ok = StreamOf_acf150(this)->Read(tail, tailSize);
                            }
                            if (ok) {
                                StreamOf_acf150(this)->Seek(lineStart);
                                entry.Sprintf("%s = %s%s", k->c_str(), val->c_str(), "\r\n");
                                Fn0090f31b(&entry, &entryText);
                                StreamOf_acf150(this)->Write(entryText.c_str(), entryText.size());
                                StreamOf_acf150(this)->Write(tail, tailSize);
                                Stream_acf150* s = StreamOf_acf150(this);
                                s->SetSize(s->GetPosition());
                            }
                            operator delete(tail);
                            mbParsed = false;
                        } else {
                            StreamOf_acf150(this)->Pad10_acf150();
                            entry.Sprintf("%s = %s%s", k->c_str(), val->c_str(), "\r\n");
                            Fn0090f31b(&entry, &entryText);
                            StreamOf_acf150(this)->Write(entryText.c_str(), entryText.size());
                        }
                        if (!mbKeepOpen) {
                            Slot05_acf150();
                        }
                        return true;
                    }
                }
                if (!mbKeepOpen) {
                    Slot05_acf150();
                }
            }
        }
    }
    return false;
}
#endif
