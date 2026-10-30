#include "classes/cRZDiskRadioStation.h"
#include <stdlib.h>

// The radio this station plays through (slots by their vtable offsets; only the ones used here are named).
struct Radio_acc290 {
    virtual void Pad00_acc290();
    virtual void Pad01_acc290();
    virtual void Pad02_acc290();
    virtual void Pad03_acc290();
    virtual void Pad04_acc290();
    virtual void Pad05_acc290();
    virtual uint32_t Fn06();                    // 0x18
    virtual void PlayFile(cRZString* path);     // 0x1c
    virtual void Pad08_acc290();
    virtual void Pad09_acc290();
    virtual void Pad10_acc290();
    virtual void Pad11_acc290();
    virtual void Pad12_acc290();
    virtual void Pad13_acc290();
    virtual void Pad14_acc290();
    virtual uint32_t Fn15();                    // 0x3c
    virtual void Pad16_acc290();
    virtual void Pad17_acc290();
    virtual void Pad18_acc290();
    virtual void Pad19_acc290();
    virtual void Pad20_acc290();
    virtual void Pad21_acc290();
    virtual void Pad22_acc290();
    virtual void Pad23_acc290();
    virtual void Pad24_acc290();
    virtual void Pad25_acc290();
    virtual bool Fn26(uint32_t index);          // 0x68
    virtual void Pad27_acc290();
    virtual void Pad28_acc290();
    virtual void Pad29_acc290();
    virtual void Pad30_acc290();
    virtual void Pad31_acc290();
    virtual void Pad32_acc290();
    virtual void Pad33_acc290();
    virtual bool Fn34();                        // 0x88
};

// The station's timer (4000 ticks between two picks).
struct Timer_acc290 {
    // STUB: 0x00890198
    uint32_t GetElapsed();
    // STUB: 0x0088ff0a
    void Reset();
    // STUB: 0x008905c4
    void Start();
};

// A node of a string list (the original's list class): the links, then the string.
struct Node_acc290 {
    Node_acc290* mpNext;
    Node_acc290* mpPrev;
    cRZString mValue;
};

// One of the four play lists: the directory it was read from, the list, the position in it.
struct Iter_acc290 {
    Node_acc290* mpNode;
    Iter_acc290(Node_acc290* node) : mpNode(node) {}
    Iter_acc290(const Iter_acc290& other) : mpNode(other.mpNode) {}
};

struct List_acc290 {
    Node_acc290* mpHead;
    // STUB: 0x0043aba0
    void Clear();
    // STUB: 0x004580e0
    void PushBack(const cRZString& value);
    // STUB: 0x007b6f80
    Iter_acc290 Erase(Iter_acc290 first, Iter_acc290 last);
    // STUB: 0x00456ab0
    Iter_acc290 Erase(Iter_acc290 position);
};

inline List_acc290* ListOf_acc290(void** field)
{
    return reinterpret_cast<List_acc290*>(field);
}

inline Iter_acc290 BeginOf_acc290(List_acc290* list)
{
    return Iter_acc290(list->mpHead->mpNext);
}

inline Iter_acc290 EndOf_acc290(List_acc290* list)
{
    return Iter_acc290(list->mpHead);
}

struct Group_acc290 {
    cRZString mPath;
    List_acc290 mList;
    Node_acc290* mpIter;
};

inline Radio_acc290* RadioOf_acc290(const cRZDiskRadioStation* station)
{
    return static_cast<Radio_acc290*>(station->mpRadio);
}

inline Timer_acc290* TimerOf_acc290(cRZDiskRadioStation* station)
{
    return reinterpret_cast<Timer_acc290*>(station->mTimer);
}

inline const std::string* StdOf_acc290(const cRZString* text)
{
    return text != 0 ? static_cast<const std::string*>(text) : 0;
}

inline Node_acc290*& NodeRef_acc290(void*& field)
{
    return reinterpret_cast<Node_acc290*&>(field);
}

inline Group_acc290* GroupsOf_acc290(cRZDiskRadioStation* station)
{
    return reinterpret_cast<Group_acc290*>(&station->mPath0);
}

// A std::vector<int> view over the station's cycle (begin, end, capacity).
struct Vec_acc290 {
    int32_t* mpBegin;
    int32_t* mpEnd;
    int32_t* mpCap;
    uint32_t size() const
    {
        return mpEnd - mpBegin;
    }
    int32_t& operator[](uint32_t n)
    {
        return mpBegin[n];
    }
};

inline Vec_acc290* CycleOf_acc290(cRZDiskRadioStation* station)
{
    return reinterpret_cast<Vec_acc290*>(&station->mpCycleBegin);
}

// The directory reader (a class of the framework; 0x34 bytes).
struct Directory_acc290 {
    uint8_t mPad_acc290[0x34];
    // STUB: 0x0091bd31
    Directory_acc290(const cIGZString& path, bool a, bool b, bool c);
    // STUB: 0x0091b2f7
    ~Directory_acc290();
    // STUB: 0x0091bcad
    void ChangeDirectory(const cRZString* path, bool flag);
    // STUB: 0x0091bcd7
    void SetFilter(const cRZString& filter, bool flag);
    // STUB: 0x0091b9c7
    void ReadFiles(List_acc290* out);
    // STUB: 0x009d7e63
    uint32_t GetEntryCount();
    // STUB: 0x0091ad83
    uint8_t* GetNthEntry(uint32_t n);
};

// STUB: 0x0091a93d
void Fn0091a93d(const void* entry, void* dest, bool flag);

// STUB: 0x00408ae0
std::string Fn00408ae0(const std::string* a, const std::string* b);

// STUB: 0x0043ab70
bool Fn0043ab70(const std::string* a, const std::string* b);

// STUB: 0x004974f0
Iter_acc290 Fn004974f0(Iter_acc290 first, Iter_acc290 last, const cRZString& value);

// GLOBAL: 0x00b16058
extern const char* gp00b16058;

// GLOBAL: 0x00b1605c
extern const char* gp00b1605c;

// A vector of strings (begin, end, capacity) the way the framework lays it out.
struct StrVec_acc290 {
    cRZString* mpBegin;
    cRZString* mpEnd;
    cRZString* mpCap;
    StrVec_acc290() : mpBegin(0), mpEnd(0), mpCap(0) {}
    // STUB: 0x004522f0
    void PushBack(const cRZString& value);
    // STUB: 0x00419140
    ~StrVec_acc290();
};

// The sort's comparison object: a copy of a path string (the copy constructor is the framework's own).
struct PathArg_acc290 {
    uint8_t mPad_acc290[0x14];
    // STUB: 0x008d3be2
    PathArg_acc290(const cRZString& source);
};

// STUB: 0x008d5e50
void Fn008d5e50(cRZString* first, cRZString* last, PathArg_acc290 path);

// STUB: 0x008d546f
void Fn008d546f(cRZString* first, cRZString* last);

// GLOBAL: 0x00b16064
extern const char* gp00b16064;

// One entry of a play list: 0x2c bytes, the name string at +0x14.
struct PlayListEntry_acc290 {
    uint8_t mPad_acc290[0x14];
    cRZString mName;
    uint8_t mTail_acc290[0x4];
};

// The play list file reader (0x48 bytes): its entries are a vector at the start.
struct PlayList_acc290 {
    uint8_t mPad_acc290[0x48];
    // STUB: 0x008d569f
    PlayList_acc290();
    // STUB: 0x008d56c8
    ~PlayList_acc290();
    // STUB: 0x008d6b22
    bool Open(const cIGZString& path);
};

// A copy of the entries (begin, end, capacity).
struct EntryVec_acc290 {
    PlayListEntry_acc290* mpBegin;
    PlayListEntry_acc290* mpEnd;
    PlayListEntry_acc290* mpCap;
    EntryVec_acc290() : mpBegin(0), mpEnd(0), mpCap(0) {}
    // STUB: 0x008d56eb
    void Assign(const PlayList_acc290& source);
    // STUB: 0x008d51fc
    ~EntryVec_acc290();
};

// The file object (0x80 bytes); only built and torn down here.
struct File_acc290 {
    uint8_t mPad_acc290[0x80];
    // STUB: 0x00918c00
    File_acc290(const cIGZString& path);
    // STUB: 0x00918c70
    ~File_acc290();
};

// GLOBAL: 0x00b16060
extern const char* gp00b16060;

// STUB: 0x008d3442
void Fn008d3442(int32_t* first, int32_t* last);

// STUB: 0x00919e96
bool Fn00919e96(const cIGZString* path);

// GLOBAL: 0x00b16040
extern const char* gp00b16040;

// FUNCTION: 0x008d2994
bool cRZDiskRadioStation::QueryInterface(uint32_t riid, void* ppv)
{
    bool known = riid == 1 || riid == 0x4056574b;
    if (known) {
        *static_cast<void**>(ppv) = this;
        AddRef();
        return true;
    }
    return false;
}

// FUNCTION: 0x008d29b9
uint32_t cRZDiskRadioStation::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x008d29d0
void cRZDiskRadioStation::SetStation()
{
    ReadCallSignFromDisk();
    LoadAllPlaylists();
    Slot17_acc290(mnSelected);
    if (!mbWelcomed) {
        PlayWelcome();
    }
}

// FUNCTION: 0x008d2e5f
void cRZDiskRadioStation::GetStationCallSign(char* dest)
{
    dest[0] = mCallSign[0];
    dest[1] = mCallSign[1];
    dest[2] = mCallSign[2];
    dest[3] = mCallSign[3];
}

// FUNCTION: 0x008d2e88
void cRZDiskRadioStation::GetStationDescription(void* dest)
{
    cIGZString* target = static_cast<cIGZString*>(dest);
    if (mDescription.empty()) {
        target->FromChar(static_cast<const cIGZString&>(mCallSign).ToChar());
    } else {
        target->FromChar(static_cast<const cIGZString&>(mDescription).ToChar());
    }
}

// FUNCTION: 0x008d3593
bool cRZDiskRadioStation::SetRadio(void* radio)
{
    mpRadio = radio;
    mnRadioValue = RadioOf_acc290(this)->Fn06();
    return true;
}

// FUNCTION: 0x008d2eb0
bool cRZDiskRadioStation::Slot20_acc290(uint32_t index)
{
    Group_acc290* groups = GroupsOf_acc290(this);
    Node_acc290* head;
    if (index == 0) {
        head = groups[0].mList.mpHead;
    } else if (index == 1) {
        if (!RadioOf_acc290(this)->Fn26(0)) {
            return false;
        }
        head = groups[1].mList.mpHead;
    } else if (index == 2) {
        if (!RadioOf_acc290(this)->Fn26(1)) {
            return false;
        }
        head = groups[2].mList.mpHead;
    } else if (index == 3) {
        if (!RadioOf_acc290(this)->Fn26(2)) {
            return false;
        }
        head = groups[3].mList.mpHead;
    } else {
        return false;
    }
    return head->mpNext != head;
}

// FUNCTION: 0x008d338f
void cRZDiskRadioStation::Slot21_acc290(uint32_t index)
{
    Group_acc290* groups = GroupsOf_acc290(this);
    Node_acc290** iter;
    Node_acc290* head;
    if (index == 0) {
        iter = &groups[0].mpIter;
        *iter = (*iter)->mpNext;
        head = groups[0].mList.mpHead;
    } else if (index == 1) {
        iter = &groups[1].mpIter;
        *iter = (*iter)->mpNext;
        head = groups[1].mList.mpHead;
    } else if (index == 2) {
        iter = &groups[2].mpIter;
        *iter = (*iter)->mpNext;
        head = groups[2].mList.mpHead;
    } else if (index == 3) {
        iter = &groups[3].mpIter;
        *iter = (*iter)->mpNext;
        head = groups[3].mList.mpHead;
    } else {
        return;
    }
    if (*iter == head) {
        *iter = head->mpNext;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x008d3485 score 29
void cRZDiskRadioStation::ShuffleCycle()
{
    Vec_acc290* cycle = CycleOf_acc290(this);
    int32_t last = (*cycle)[cycle->size() - 1];
    Fn008d3442(cycle->mpBegin, cycle->mpEnd);
    if (last != 0) {
        int32_t* first = &(*cycle)[0];
        if (*first == last) {
            int32_t held = *first;
            *first = (*cycle)[cycle->size() - 1];
            (*cycle)[cycle->size() - 1] = held;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008d2cfd score 34
bool cRZDiskRadioStation::OnIdle()
{
    if (!IsOnTheAir()) {
        return true;
    }
    if (RadioOf_acc290(this)->Fn15() == 0) {
        return true;
    }
    if (RadioOf_acc290(this)->Fn34()) {
        return true;
    }
    {
        {
            {
                if (0 != mbTimerRunning) {
                    if (TimerOf_acc290(this)->GetElapsed() >= 4000) {
                        if ((mpCycleBegin[mnCycleIndex] == 0 && Slot20_acc290(0) && static_cast < uint32_t > (rand() % 100) < 75) == 0) {
                            mnCycleIndex++;
                            int32_t kind;
                            if (mnCycleIndex == static_cast < uint32_t > (mpCycleEnd - mpCycleBegin)) {
                                ShuffleCycle();
                                mnCycleIndex = 0;
                            }
                            kind = mpCycleBegin[mnCycleIndex];
                            if (!kind) {
                                if (Slot20_acc290(0)) {
                                    mbTimerRunning = false;
                                    Slot23_acc290(0);
                                } else {
                                    return true;
                                }
                            } else {
                                if (1 == kind) {
                                    if (static_cast < uint32_t > (rand() % 100) >= 50) {
                                        return true;
                                    } else {
                                        if (0 != Slot20_acc290(1)) {
                                            mbTimerRunning = false;
                                            Slot23_acc290(1);
                                        } else {
                                            return true;
                                        }
                                    }
                                } else if (2 == kind) {
                                    if (0 != (static_cast < uint32_t > (rand() % 100) >= 10)) {
                                        return true;
                                    }
                                    if (!Slot20_acc290(2)) {
                                        return true;
                                    }
                                    mbTimerRunning = false;
                                    Slot23_acc290(2);
                                } else if (kind == 3) {
                                    if (0 != (static_cast < uint32_t > (rand() % 100) >= 10)) {
                                        return true;
                                    }
                                    if (0 == Slot20_acc290(3)) {
                                        return true;
                                    } else {
                                        mbTimerRunning = false;
                                        Slot23_acc290(3);
                                    }
                                }
                            }
                        } else {
                            mbTimerRunning = false;
                            mnCountA += 1;
                            Slot23_acc290(0);
                            return true;
                        }
                    }
                } else {
                    if (!RadioOf_acc290(this)->Fn34()) {
                        mbTimerRunning = true;
                        TimerOf_acc290(this)->Reset();
                        TimerOf_acc290(this)->Start();
                    }
                }
            }
        }
    }
    return true;
}
#endif

// FUNCTION: 0x008d3e7e
void cRZDiskRadioStation::PlayWelcome()
{
    cRZString path(mBasePath, 0, cRZString::npos);
    path.append(gp00b16040);
    if (Fn00919e96(&path)) {
        RadioOf_acc290(this)->PlayFile(&path);
        mbTimerRunning = false;
        mbWelcomed = true;
    }
}

// FUNCTION: 0x008d4579
bool cRZDiskRadioStation::ReadCallSignFromDisk()
{
    Directory_acc290 dir(cRZString(), false, false, false);
    cRZString filter(gp00b16058);
    dir.ChangeDirectory(&mBasePath, true);
    dir.SetFilter(filter, true);
    if (dir.GetEntryCount() != 0) {
        uint8_t* entry = dir.GetNthEntry(0);
        Fn0091a93d(entry + 4, &mCallSign, false);
    }
    filter = gp00b1605c;
    dir.SetFilter(filter, true);
    if (dir.GetEntryCount() != 0) {
        uint8_t* entry = dir.GetNthEntry(0);
        Fn0091a93d(entry + 4, &mDescription, false);
    }
    return mCallSign.begin() != mCallSign.end();
}

#ifdef OB_DRAFTS
// CLOSE: 0x008d5409 score 7
void cRZDiskRadioStation::SetModifierList(void* source)
{
    List_acc290* mine = reinterpret_cast<List_acc290*>(&mpModifierList);
    mine->Clear();
    List_acc290* list = static_cast<List_acc290*>(source);
    if (list != 0 && list->mpHead->mpNext != list->mpHead) {
        cRZString value;
        for (Node_acc290* node = list->mpHead->mpNext; node != list->mpHead; node = node->mpNext) {
            value = node->mValue;
            mine->PushBack(value);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008d3f8e score 22
bool cRZDiskRadioStation::PlayNextSelectionNotOnExclusionList()
{
    List_acc290* mods = reinterpret_cast<List_acc290*>(&mpModifierList);
    if (NodeRef_acc290(mpHead0)->mpNext != NodeRef_acc290(mpHead0)) {
        Node_acc290* start = NodeRef_acc290(mpIter0);
        bool wrapped = false;
        NodeRef_acc290(mpIter0) = start->mpNext;
        while (NodeRef_acc290(mpIter0) != start) {
            if (NodeRef_acc290(mpIter0) == NodeRef_acc290(mpHead0)) {
                if (wrapped) {
                    break;
                }
                NodeRef_acc290(mpIter0) = NodeRef_acc290(mpHead0)->mpNext;
                wrapped = true;
            }
            cRZString* value = &NodeRef_acc290(mpIter0)->mValue;
            Node_acc290* modEnd = mods->mpHead;
            if (mnModifierMode == 1) {
                if (modEnd != Fn004974f0(Iter_acc290(mods->mpHead->mpNext), Iter_acc290(modEnd), *value).mpNode) {
                    goto skipEntry;
                }
                goto tryEntry;
            } else {
                if (modEnd != Fn004974f0(Iter_acc290(mods->mpHead->mpNext), Iter_acc290(modEnd), *value).mpNode) {
                tryEntry:
                    if (Fn008d3ee0(value)) {
                        cRZString name;
                        name = NodeRef_acc290(mpIter0)->mValue;
                        if (!Fn00919e96(&name)) {
                            name = Fn00408ae0(static_cast<const std::string*>(&mPath0), static_cast<const std::string*>(&name));
                        }
                        RadioOf_acc290(this)->PlayFile(&name);
                        return true;
                    }
                }
            }
        skipEntry:
            NodeRef_acc290(mpIter0) = NodeRef_acc290(mpIter0)->mpNext;
        }
        if (NodeRef_acc290(mpIter0) == start) {
            Slot17_acc290(mnSelected);
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008d4127 score 24
bool cRZDiskRadioStation::Slot23_acc290(uint32_t index)
{
    cRZString name;
    if (index == 0) {
        List_acc290* mods = reinterpret_cast<List_acc290*>(&mpModifierList);
        if (mnModifierMode != 0 && (mnModifierMode != 1 || mods->mpHead->mpNext != mods->mpHead)) {
            return PlayNextSelectionNotOnExclusionList();
        }
        Node_acc290** iter = &NodeRef_acc290(mpIter0);
        *iter = (*iter)->mpNext;
        if (*iter == NodeRef_acc290(mpHead0)) {
            *iter = NodeRef_acc290(mpHead0)->mpNext;
        }
        name = (*iter)->mValue;
        if (!Fn00919e96(&name)) {
            name = Fn00408ae0(static_cast<const std::string*>(&mPath0), static_cast<const std::string*>(&name));
        }
    } else if (index == 1) {
        Node_acc290** iter = &NodeRef_acc290(mpIter1);
        *iter = (*iter)->mpNext;
        if (*iter == NodeRef_acc290(mpHead1)) {
            *iter = NodeRef_acc290(mpHead1)->mpNext;
        }
        cRZString* entry = &(*iter)->mValue;
        name = Fn00408ae0(static_cast<const std::string*>(&mPath1), static_cast<const std::string*>(entry));
    } else if (index == 2) {
        Node_acc290** iter = &NodeRef_acc290(mpIter2);
        *iter = (*iter)->mpNext;
        if (*iter == NodeRef_acc290(mpHead2)) {
            *iter = NodeRef_acc290(mpHead2)->mpNext;
        }
        cRZString* entry = &(*iter)->mValue;
        name = Fn00408ae0(static_cast<const std::string*>(&mPath2), static_cast<const std::string*>(entry));
    } else if (index == 3) {
        Node_acc290** iter = &NodeRef_acc290(mpIter3);
        *iter = (*iter)->mpNext;
        if (*iter == NodeRef_acc290(mpHead3)) {
            *iter = NodeRef_acc290(mpHead3)->mpNext;
        }
        cRZString* entry = &(*iter)->mValue;
        name = Fn00408ae0(static_cast<const std::string*>(&mPath3), static_cast<const std::string*>(entry));
    } else {
        return false;
    }
    RadioOf_acc290(this)->PlayFile(&name);
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008d5ec3 score 11
void cRZDiskRadioStation::Slot18_acc290(void* path, void* source, uint32_t flag)
{
    List_acc290* list = static_cast<List_acc290*>(source);
    Node_acc290* node = list->mpHead->mpNext;
    if (node != list->mpHead) {
        StrVec_acc290 items;
        do {
            items.PushBack(node->mValue);
            node = node->mpNext;
        } while (node != list->mpHead);
        cRZString* first;
        if (flag == 1) {
            Fn008d5e50(first = items.mpBegin, items.mpEnd, *static_cast<cRZString*>(path));
        } else {
            Fn008d546f(first = items.mpBegin, items.mpEnd);
        }
        list->Clear();
        for (int32_t count = items.mpEnd - first; count > 0; --count) {
            list->PushBack(*first);
            ++first;
        }
    }
}
#endif

// FUNCTION: 0x008d3960
void cRZDiskRadioStation::LoadAllPlaylists()
{
    Directory_acc290 dir(cRZString(), false, false, false);
    cRZString filters(gp00b16064);
    ListOf_acc290(&mpHead0)->Erase(BeginOf_acc290(ListOf_acc290(&mpHead0)), EndOf_acc290(ListOf_acc290(&mpHead0)));
    ListOf_acc290(&mpHead1)->Erase(BeginOf_acc290(ListOf_acc290(&mpHead1)), EndOf_acc290(ListOf_acc290(&mpHead1)));
    ListOf_acc290(&mpHead2)->Erase(BeginOf_acc290(ListOf_acc290(&mpHead2)), EndOf_acc290(ListOf_acc290(&mpHead2)));
    ListOf_acc290(&mpHead3)->Erase(BeginOf_acc290(ListOf_acc290(&mpHead3)), EndOf_acc290(ListOf_acc290(&mpHead3)));
    cRZString token;
    bool more;
    do {
        more = filters.SplitToken(',', token);
        dir.ChangeDirectory(&mPath0, false);
        dir.SetFilter(token, false);
        dir.ReadFiles(ListOf_acc290(&mpHead0));
        dir.ChangeDirectory(&mPath1, false);
        dir.SetFilter(cRZString(token, 0, cRZString::npos), false);
        dir.ReadFiles(ListOf_acc290(&mpHead1));
        dir.ChangeDirectory(&mPath2, false);
        dir.SetFilter(cRZString(token, 0, cRZString::npos), false);
        dir.ReadFiles(ListOf_acc290(&mpHead2));
        dir.ChangeDirectory(&mPath3, false);
        dir.SetFilter(cRZString(token, 0, cRZString::npos), false);
        dir.ReadFiles(ListOf_acc290(&mpHead3));
    } while (more);
    ExpandPlayLists(&mPath0, ListOf_acc290(&mpHead0));
    ExpandPlayLists(&mPath1, ListOf_acc290(&mpHead1));
    ExpandPlayLists(&mPath2, ListOf_acc290(&mpHead2));
    ExpandPlayLists(&mPath3, ListOf_acc290(&mpHead3));
}

#ifdef OB_DRAFTS
// CLOSE: 0x008d4317 score 37
void cRZDiskRadioStation::Slot17_acc290(uint32_t arg)
{
    cRZString spare;
    cRZString held;
    if (ListOf_acc290(&mpHead0)->mpHead->mpNext != ListOf_acc290(&mpHead0)->mpHead) {
        held = ListOf_acc290(&mpHead0)->mpHead->mpPrev->mValue;
        Slot18_acc290(&mPath0, ListOf_acc290(&mpHead0), arg);
        if (Fn0043ab70(&held, static_cast<const std::string*>(&ListOf_acc290(&mpHead0)->mpHead->mpNext->mValue))) {
            spare = ListOf_acc290(&mpHead0)->mpHead->mpPrev->mValue;
            ListOf_acc290(&mpHead0)->mpHead->mpPrev->mValue = ListOf_acc290(&mpHead0)->mpHead->mpNext->mValue;
            ListOf_acc290(&mpHead0)->mpHead->mpNext->mValue = spare;
        }
        NodeRef_acc290(mpIter0) = ListOf_acc290(&mpHead0)->mpHead->mpNext;
    }
    if (ListOf_acc290(&mpHead1)->mpHead->mpNext != ListOf_acc290(&mpHead1)->mpHead) {
        held = ListOf_acc290(&mpHead1)->mpHead->mpPrev->mValue;
        Slot18_acc290(&mPath1, ListOf_acc290(&mpHead1), arg);
        if (Fn0043ab70(&held, static_cast<const std::string*>(&ListOf_acc290(&mpHead1)->mpHead->mpNext->mValue))) {
            spare = ListOf_acc290(&mpHead1)->mpHead->mpPrev->mValue;
            ListOf_acc290(&mpHead1)->mpHead->mpPrev->mValue = ListOf_acc290(&mpHead1)->mpHead->mpNext->mValue;
            ListOf_acc290(&mpHead1)->mpHead->mpNext->mValue = spare;
        }
        NodeRef_acc290(mpIter1) = ListOf_acc290(&mpHead1)->mpHead->mpNext;
    }
    if (ListOf_acc290(&mpHead2)->mpHead->mpNext != ListOf_acc290(&mpHead2)->mpHead) {
        held = ListOf_acc290(&mpHead2)->mpHead->mpPrev->mValue;
        Slot18_acc290(&mPath2, ListOf_acc290(&mpHead2), arg);
        if (Fn0043ab70(&held, static_cast<const std::string*>(&ListOf_acc290(&mpHead2)->mpHead->mpNext->mValue))) {
            spare = ListOf_acc290(&mpHead2)->mpHead->mpPrev->mValue;
            ListOf_acc290(&mpHead2)->mpHead->mpPrev->mValue = ListOf_acc290(&mpHead2)->mpHead->mpNext->mValue;
            ListOf_acc290(&mpHead2)->mpHead->mpNext->mValue = spare;
        }
        NodeRef_acc290(mpIter2) = ListOf_acc290(&mpHead2)->mpHead->mpNext;
    }
    if (ListOf_acc290(&mpHead3)->mpHead->mpNext != ListOf_acc290(&mpHead3)->mpHead) {
        held = ListOf_acc290(&mpHead3)->mpHead->mpPrev->mValue;
        Slot18_acc290(&mPath3, ListOf_acc290(&mpHead3), arg);
        if (Fn0043ab70(&held, static_cast<const std::string*>(&ListOf_acc290(&mpHead3)->mpHead->mpNext->mValue))) {
            spare = ListOf_acc290(&mpHead3)->mpHead->mpPrev->mValue;
            ListOf_acc290(&mpHead3)->mpHead->mpPrev->mValue = ListOf_acc290(&mpHead3)->mpHead->mpNext->mValue;
            ListOf_acc290(&mpHead3)->mpHead->mpNext->mValue = spare;
        }
        NodeRef_acc290(mpIter3) = ListOf_acc290(&mpHead3)->mpHead->mpNext;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x008d5827 score 47
void cRZDiskRadioStation::ExpandPlayLists(void* pathArg, void* listArg)
{
    cRZString* directory = static_cast<cRZString*>(pathArg);
    List_acc290* list = static_cast<List_acc290*>(listArg);
    Node_acc290* node = list->mpHead->mpNext;
    while (node != list->mpHead) {
        cRZString* value = &node->mValue;
        cRZString suffix;
        cRZString tail;
        cRZString filters(gp00b16060);
        bool more;
        do {
            more = filters.SplitToken(',', suffix);
            suffix.Erase(0, 1);
            tail = value->Right(suffix.Strlen());
            if (tail.IsEqual(suffix, false)) {
                PlayList_acc290 playlist;
                cRZString path;
                File_acc290 file(*value);
                if (Fn00919e96(value)) {
                    path = *value;
                } else {
                    path = Fn00408ae0(static_cast<const std::string*>(directory), static_cast<const std::string*>(value));
                }
                if (playlist.Open(path)) {
                    EntryVec_acc290 entries;
                    entries.Assign(playlist);
                    uint32_t count = entries.mpEnd - entries.mpBegin;
                    if (count > 0) {
                        PlayListEntry_acc290* entry = entries.mpBegin;
                        do {
                            cRZString text;
                            static_cast<cIGZString&>(text) = entry->mName;
                            list->PushBack(text);
                            ++entry;
                            --count;
                        } while (count != 0);
                    }
                }
                node = list->Erase(Iter_acc290(node)).mpNode->mpPrev;
            }
        } while (more);
        node = node->mpNext;
    }
}
#endif
