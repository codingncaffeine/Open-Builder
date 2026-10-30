#include "classes/cSC4LineItem.h"
#include "game/Globals.h"

// The department budget the item belongs to (field at +0x60): only the slot and the method used here.
struct cDepartmentBudget_ab0f58 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void* GetFundingPercentage();
    // STUB: 0x006a9980
    void SendBudgetChangeMessage();
};

inline cDepartmentBudget_ab0f58* BudgetOf_ab0f58(cIGZUnknown* p)
{
    return reinterpret_cast<cDepartmentBudget_ab0f58*>(p);
}

// FUNCTION: 0x006a97d0
bool cSC4LineItem::QueryInterface(unsigned int iid, void** ppv)
{
    if (iid != 1 && iid != 0xaa313c9f) {
        if (iid != 0xe4fda3d4) {
            return false;
        }
        *ppv = static_cast<cUnk00a80784*>(this);
        AddRef();
        return true;
    }
    *ppv = this;
    AddRef();
    return true;
}

// FUNCTION: 0x006a9830
uint32_t cSC4LineItem::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x006a9840
unsigned int cSC4LineItem::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x006aaed0
void cSC4LineItem::SetSecondaryInfoField(int64_t value)
{
    mnSecondaryInfo = value;
}

// FUNCTION: 0x006aaf10
void cSC4LineItem::SetDisplayFlag(uint32_t flag, bool set)
{
    uint32_t v;
    if (set) {
        v = flag | mnDisplayFlags;
    } else {
        v = ~flag & mnDisplayFlags;
    }
    mnDisplayFlags = v;
}

// The building development simulator (global 0xb43d68): only the slot used here is named.
struct cBuildingDevelopmentSim_ab0f58 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void Pad21();
    virtual void Pad22();
    virtual void Pad23();
    virtual void Pad24();
    virtual void Pad25();
    virtual void Pad26();
    virtual void Pad27();
    virtual void Pad28();
    virtual void Pad29();
    virtual void Pad30();
    virtual void Pad31();
    virtual void Pad32();
    virtual void Pad33();
    virtual void Pad34();
    virtual void Pad35();
    virtual void Pad36();
    virtual void Pad37();
    virtual void* GetBuildingName(uint32_t id);
};

// GLOBAL: 0x00b43d68
extern cBuildingDevelopmentSim_ab0f58* gpB43d68;

// A string built from a (group, id) pair of the text resources; the item copies its text. Only the constructor is
// used here, so the type has no other members.
struct cSLString_ab0f58 : public cRZString {
    using cRZString::operator=;
    uint32_t mUnused[3];
    // STUB: 0x00603580
    cSLString_ab0f58(uint32_t a, uint32_t b, bool c);
};

// The stream the item is written to: only the slots used here are named.
struct StreamWrite_ab0f58 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Write16(uint16_t value);
    virtual void Pad08();
    virtual void Write32(uint32_t value);
    virtual void Write64(int64_t value);
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void WriteString(const void* text);
    virtual void Pad16();
    virtual void Pad17();
    virtual bool HasError();
};

// The stream the item is read from.
struct StreamRead_ab0f58 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Read16(uint16_t* value);
    virtual void Pad08();
    virtual void Read32(uint32_t* value);
    virtual void Read64(int64_t* value);
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void ReadString(void* text);
    virtual void Pad16();
    virtual void Pad17();
    virtual bool HasError();
};

// STUB: 0x005d9fd0
void Fn005d9fd0(StreamWrite_ab0f58* stream, bool value);

// STUB: 0x005d99a0
void Fn005d99a0(StreamWrite_ab0f58* stream, cIGZUnknown* object);

// STUB: 0x005d9fa0
void Fn005d9fa0(StreamRead_ab0f58* stream, bool* value);

// STUB: 0x005d9730
void Fn005d9730(StreamRead_ab0f58* stream, uint32_t iid, cIGZUnknown** object, uint32_t flag);

// FUNCTION: 0x006a9aa0
bool cSC4LineItem::Slot03_a80784(void* streamPtr)
{
    StreamWrite_ab0f58* stream = static_cast<StreamWrite_ab0f58*>(streamPtr);
    stream->Write16(4);
    stream->WriteString(&mName);
    stream->Write64(mnSecondaryInfo);
    stream->Write64(mnFullExpenses);
    stream->Write64(mnCurrentExpenses);
    stream->Write64(mnIncome);
    stream->Write32(mnField54);
    stream->Write32(mnDisplayFlags);
    Fn005d9fd0(stream, mbField5c);
    stream->Write16(mnField64);
    Fn005d99a0(stream, mpBudget);
    stream->Write32(mnNameB);
    stream->Write32(mnNameA);
    return !stream->HasError();
}

// FUNCTION: 0x006a9b60
bool cSC4LineItem::Slot04_a80784(void* streamPtr)
{
    StreamRead_ab0f58* stream = static_cast<StreamRead_ab0f58*>(streamPtr);
    uint16_t version;
    stream->Read16(&version);
    if (version != 4) {
        return false;
    }
    stream->ReadString(&mName);
    stream->Read64(&mnSecondaryInfo);
    stream->Read64(&mnFullExpenses);
    stream->Read64(&mnCurrentExpenses);
    stream->Read64(&mnIncome);
    stream->Read32(&mnField54);
    stream->Read32(&mnDisplayFlags);
    Fn005d9fa0(stream, &mbField5c);
    uint16_t extra;
    stream->Read16(&extra);
    mnField64 = extra;
    cIGZUnknown** slot = &mpBudget;
    if (*slot) {
        cIGZUnknown* old = *slot;
        *slot = 0;
        old->Release();
    }
    Fn005d9730(stream, 0xe990bffc, slot, 0);
    stream->Read32(&mnNameB);
    stream->Read32(&mnNameA);
    mbNameStale = true;
    return !stream->HasError();
}

// FUNCTION: 0x006ac460
void cSC4LineItem::SetName(uint32_t group, uint32_t id)
{
    mnNameA = group;
    mnNameB = id;
    if (group != 0) {
        mName.std::string::operator=(cSLString_ab0f58(group, id, true));
    } else {
        cIGZString* text = &mName;
        text->operator=(*static_cast<cIGZString*>(gpB43d68->GetBuildingName(id)));
    }
}

// FUNCTION: 0x006ac4f0
void cSC4LineItem::GetName(void* out)
{
    if (mbNameStale) {
        SetName(mnNameA, mnNameB);
        mbNameStale = false;
    }
    cRZString* source = &mName;
    static_cast<cRZString*>(out)->std::string::operator=(*source);
}

// FUNCTION: 0x006aaec0
int64_t cSC4LineItem::GetSecondaryInfoField()
{
    return mnSecondaryInfo;
}

// FUNCTION: 0x006b9850
int64_t cSC4LineItem::GetFullExpenses()
{
    return mnFullExpenses;
}

// FUNCTION: 0x006aaef0
int64_t cSC4LineItem::GetCurrentExpenses()
{
    return mnCurrentExpenses;
}

// FUNCTION: 0x006aaf00
int64_t cSC4LineItem::GetIncome()
{
    return mnIncome;
}

// FUNCTION: 0x006a9860
void cSC4LineItem::AddToFullExpenses(int64_t amount)
{
    SetFullExpenses(mnFullExpenses + amount);
}

// FUNCTION: 0x006a9a00
void cSC4LineItem::SetFullExpenses(int64_t amount)
{
    mnFullExpenses = amount;
    if (!mbField5c) {
        float* pct = static_cast<float*>(BudgetOf_ab0f58(mpBudget)->GetFundingPercentage());
        double d = *pct;
        mnCurrentExpenses = static_cast<int64_t>(d * mnFullExpenses);
    }
    BudgetOf_ab0f58(mpBudget)->SendBudgetChangeMessage();
}

#ifdef OB_DRAFTS
// CLOSE: 0x006a9a40 score 12 (scores 0 only under /O1; the class is built /O2)
void cSC4LineItem::SetIncome(int64_t amount)
{
    if (amount < 0) {
        amount = 0;
    }
    mnIncome = amount;
    BudgetOf_ab0f58(mpBudget)->SendBudgetChangeMessage();
}
#endif

// FUNCTION: 0x006a9a70
void cSC4LineItem::AddToIncome(int64_t amount)
{
    mnIncome += amount;
    BudgetOf_ab0f58(mpBudget)->SendBudgetChangeMessage();
}
