#include <algorithm>

#include "classes/cGZClipboardManagerClipboard.h"
#include "gzcom/cIGZUnknown.h"
#include "gzcom/cIGZString.h"
#include "gzcom/cRZString.h"

static const uint32_t kTypeText_acfe40 = 0x67ec001d;
static const uint32_t kAnyType_acfe40 = 0xffffffff;

// The lock embedded at offset 0x28 (a vtable and one word); only the slots used here are named.
struct Lock_acfe40 {
    virtual void Pad0_acfe40();
    virtual void Enter_acfe40();
    virtual void Leave_acfe40();
};

// A scope guard over the embedded lock: the constructor takes the lock, the destructor lets it go.
struct Guard_acfe40 {
    uint32_t mPad;
    Lock_acfe40* mpLock;

    // STUB: 0x0048c9f0
    Guard_acfe40(Lock_acfe40* lock);
    ~Guard_acfe40() { mpLock->Leave_acfe40(); }
};

// One piece of clipboard data: the component interface, then its type and its payload.
struct Data_acfe40 {
    virtual bool QueryInterface(uint32_t riid, void** ppvObj);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual uint32_t GetDataType();
    virtual void Pad4_acfe40();
    virtual cIGZUnknown* GetPayload();
};

// The record the data types are kept in (a red-black tree node: link words, then the key and its data).
struct Node_acfe40 {
    uint32_t mColor;
    Node_acfe40* mpParent;
    Node_acfe40* mpLeft;
    Node_acfe40* mpRight;
    uint32_t mKey;
    Data_acfe40* mpData;
};

struct Entry_acfe40 {
    uint32_t mKey;
    Data_acfe40* mpData;
    Entry_acfe40(uint32_t key, Data_acfe40* data) : mKey(key), mpData(data) {}
};

// An iterator is a class passed by value, a pair a class returned through a hidden pointer.
struct Iter_acfe40 {
    Node_acfe40* mpNode;
    Iter_acfe40() : mpNode(0) {}
    Iter_acfe40(const Iter_acfe40& other) : mpNode(other.mpNode) {}
};

struct Result_acfe40 {
    Iter_acfe40 mIter;
    bool mbInserted;
    Result_acfe40() : mbInserted(false) {}
};

struct Tree_acfe40 {
    // STUB: 0x0098129c
    Node_acfe40* Find(const uint32_t* key);
    // STUB: 0x0092286b
    void Clear();
    // STUB: 0x00927cf8
    void Erase(Iter_acfe40 it);
    // STUB: 0x0094950a
    Result_acfe40 Insert(const Entry_acfe40& entry);
};

inline Tree_acfe40* TreeOf_acfe40(void** head)
{
    return reinterpret_cast<Tree_acfe40*>(head);
}

// STUB: 0x0040d4c0
Node_acfe40* Next_acfe40(Node_acfe40* node);

// The object behind offset 0x18, which takes the text.
struct System_acfe40 {
    // STUB: 0x00923760
    void SetText_acfe40(cIGZString* text);
};

// The data object the text is wrapped in (vtable, count, type, payload).
struct NewData_acfe40 {
    uint32_t mWords[4];
    // STUB: 0x009227ad
    NewData_acfe40(uint32_t type, cIGZUnknown* payload);
};

// FUNCTION: 0x009223f2
bool cGZClipboardManagerClipboard::QueryInterface(uint32_t a, void* b)
{
    bool found = false;
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    if (a == 1 || a == 0x87ec000b) {
        *static_cast<cGZClipboardManagerClipboard**>(b) = this;
        AddRef();
        found = true;
    }
    return found;
}

// FUNCTION: 0x00922436
uint32_t cGZClipboardManagerClipboard::AddRef()
{
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    return ++mnRefCount;
}

// FUNCTION: 0x0092245d
void cGZClipboardManagerClipboard::SetChangeNotificationEnabled(bool a)
{
    field5 = a != 0;
}

// FUNCTION: 0x0092246b
bool cGZClipboardManagerClipboard::GetClipboardText_2(void* a)
{
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    Data_acfe40* data = static_cast<Data_acfe40*>(GetClipboardData_2(kTypeText_acfe40));
    if (data) {
        cIGZUnknown* payload = data->GetPayload();
        if (payload) {
            cIGZString* text;
            if (payload->QueryInterface(GZIID_cIGZString, reinterpret_cast<void**>(&text))) {
                static_cast<cIGZString*>(a)->Copy(*text);
                text->Release();
                return true;
            }
        }
    }
    return false;
}

// FUNCTION: 0x009224dc
bool cGZClipboardManagerClipboard::GetClipboardText(void* /*a*/, void* /*b*/, uint32_t /*c*/)
{
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    return false;
}

// FUNCTION: 0x009224fb
bool cGZClipboardManagerClipboard::SetClipboardText(void* /*a*/, uint32_t /*b*/, uint32_t /*c*/, bool /*d*/)
{
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092264b score 2  (the lock call loads its vtable before the count store in the original, after it here)
uint32_t cGZClipboardManagerClipboard::Release()
{
    Lock_acfe40* lock = reinterpret_cast<Lock_acfe40*>(&mLock[0]);
    lock->Enter_acfe40();
    if (mnRefCount > 1) {
        uint32_t n = mnRefCount - 1;
        mnRefCount = n;
        lock->Leave_acfe40();
        return n;
    }
    lock->Leave_acfe40();
    Shutdown();
    delete this;
    return 0;
}
#endif

// FUNCTION: 0x009228bd
bool cGZClipboardManagerClipboard::Shutdown()
{
    Lock_acfe40* lock = reinterpret_cast<Lock_acfe40*>(&mLock[0]);
    lock->Enter_acfe40();
    if (mbRunning) {
        lock->Leave_acfe40();
        SendChangeNotification(false);
        lock->Enter_acfe40();
        Clear(kAnyType_acfe40);
        Fn009227d7();
        mbRunning = false;
    }
    lock->Leave_acfe40();
    return true;
}

// FUNCTION: 0x00922908
uint32_t cGZClipboardManagerClipboard::GetAvailableClipboardDataTypes(void* a, void* b)
{
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    uint32_t have = mnTreeCount;
    uint32_t* out = static_cast<uint32_t*>(a);
    uint32_t* count = static_cast<uint32_t*>(b);
    if (out) {
        Node_acfe40* node = static_cast<Node_acfe40*>(mpTreeHead)->mpLeft;
        *count = std::min(have, *count);
        for (uint32_t i = 0; i < *count;) {
            out[i++] = node->mKey;
            node = Next_acfe40(node);
        }
    } else {
        *count = have;
    }
    return *count;
}

// FUNCTION: 0x00922ee8
bool cGZClipboardManagerClipboard::IsClipboardDataTypeAvailable(uint32_t a)
{
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    return TreeOf_acfe40(&mpTreeHead)->Find(&a) != static_cast<Node_acfe40*>(mpTreeHead);
}

// FUNCTION: 0x00922f20
void* cGZClipboardManagerClipboard::GetClipboardData_2(uint32_t a)
{
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    Node_acfe40* node = TreeOf_acfe40(&mpTreeHead)->Find(&a);
    Data_acfe40* data;
    if (node != static_cast<Node_acfe40*>(mpTreeHead)) {
        data = node->mpData;
    } else {
        data = 0;
    }
    return data;
}

// FUNCTION: 0x00922f5c
bool cGZClipboardManagerClipboard::GetClipboardData(uint32_t a, uint32_t b, void* c)
{
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    Node_acfe40* node = TreeOf_acfe40(&mpTreeHead)->Find(&a);
    bool ok;
    if (node != static_cast<Node_acfe40*>(mpTreeHead)) {
        ok = node->mpData->QueryInterface(b, static_cast<void**>(c));
    } else {
        ok = false;
    }
    return ok;
}

// FUNCTION: 0x00922fa6
void cGZClipboardManagerClipboard::Clear(uint32_t a)
{
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    if (mnTreeCount != 0) {
        if (a == kAnyType_acfe40) {
            Node_acfe40* head = static_cast<Node_acfe40*>(mpTreeHead);
            for (Node_acfe40* node = head->mpLeft; node != head; node = Next_acfe40(node)) {
                node->mpData->Release();
            }
            TreeOf_acfe40(&mpTreeHead)->Clear();
            field14++;
            PostDataChangeNotification(kAnyType_acfe40);
        } else {
            Node_acfe40* node = TreeOf_acfe40(&mpTreeHead)->Find(&a);
            if (node != static_cast<Node_acfe40*>(mpTreeHead)) {
                node->mpData->Release();
                Iter_acfe40 it;
                it.mpNode = node;
                TreeOf_acfe40(&mpTreeHead)->Erase(it);
                field14++;
                PostDataChangeNotification(a);
            }
        }
    }
}

// FUNCTION: 0x009232dc
bool cGZClipboardManagerClipboard::SetClipboardText_2(void* a, bool b)
{
    Guard_acfe40 guard(reinterpret_cast<Lock_acfe40*>(&mLock[0]));
    cRZString* text = new cRZString(*static_cast<cIGZString*>(a));
    text->AddRef();
    NewData_acfe40* data = new NewData_acfe40(kTypeText_acfe40, text);
    Data_acfe40* item = reinterpret_cast<Data_acfe40*>(data);
    item->AddRef();
    bool ok = SetClipboardData(item, b);
    item->Release();
    text->Release();
    return ok;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00923ae5 score 10  (the pair temp sits 8 bytes lower, stored after the AddRef; vtable load order at the end)
bool cGZClipboardManagerClipboard::SetClipboardData(void* a, bool b)
{
    Lock_acfe40* lock = reinterpret_cast<Lock_acfe40*>(&mLock[0]);
    uint32_t type = 0;
    bool changed = false;
    lock->Enter_acfe40();
    if (b && mnTreeCount != 0) {
        mnSuppress++;
        Clear(kAnyType_acfe40);
        mnSuppress--;
        type = kAnyType_acfe40;
        changed = true;
    }
    Data_acfe40* data = static_cast<Data_acfe40*>(a);
    if (data) {
        uint32_t dataType = data->GetDataType();
        if (mnTreeCount != 0) {
            mnSuppress++;
            Clear(dataType);
            mnSuppress--;
        }
        Entry_acfe40 entry(dataType, data);
        data->AddRef();
        TreeOf_acfe40(&mpTreeHead)->Insert(entry);
        changed = true;
        type = dataType;
        if (fieldc == 0 && dataType == kTypeText_acfe40 && mpSystem) {
            cIGZUnknown* payload = data->GetPayload();
            if (payload) {
                cIGZString* text;
                if (payload->QueryInterface(GZIID_cIGZString, reinterpret_cast<void**>(&text))) {
                    System_acfe40* system = static_cast<System_acfe40*>(mpSystem);
                    lock->Leave_acfe40();
                    system->SetText_acfe40(text);
                    lock->Enter_acfe40();
                    text->Release();
                }
            }
        }
    }
    if (changed) {
        field14++;
        lock->Leave_acfe40();
        PostDataChangeNotification(type);
        lock->Enter_acfe40();
    }
    lock->Leave_acfe40();
    return true;
}
#endif

// FUNCTION: 0x00923cf6
void cGZClipboardManagerClipboard::SetID(uint32_t a)
{
    fieldc = a;
    if (mbRunning) {
        if (a == 0) {
            Fn00923cc8();
        } else {
            Fn009227d7();
        }
    }
}

// FUNCTION: 0x00923d16
bool cGZClipboardManagerClipboard::Init()
{
    Lock_acfe40* lock = reinterpret_cast<Lock_acfe40*>(&mLock[0]);
    lock->Enter_acfe40();
    if (!mbRunning) {
        mbRunning = true;
        Fn00923cc8();
        lock->Leave_acfe40();
        SendChangeNotification(true);
        lock->Enter_acfe40();
    }
    lock->Leave_acfe40();
    return true;
}
