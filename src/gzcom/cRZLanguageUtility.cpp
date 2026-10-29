#include "classes/cRZLanguageUtility.h"
#include "common/winapi.h"
#include "gzcom/cRZString.h"

// A sink the object writes itself into (a stream-like interface); only the slots used here are named.
struct Sink_ad1250 {
    virtual void Pad0_ad1250() = 0;
    virtual void Pad1_ad1250() = 0;
    virtual void Pad2_ad1250() = 0;
    virtual void Write_ad1250(const void* data, uint32_t size) = 0;
    virtual void Put_ad1250(const void* record) = 0;
    virtual void Pad5_ad1250() = 0;
    virtual void Pad6_ad1250() = 0;
    virtual uint32_t Query_ad1250() = 0;
};

// The two objects Slot19 shuttles a value between; only the slots it uses are named.
struct Source_ad1250 {
    virtual void Pad0_ad1250() = 0;
    virtual void Pad1_ad1250() = 0;
    virtual void Pad2_ad1250() = 0;
    virtual void Pad3_ad1250() = 0;
    virtual void Pad4_ad1250() = 0;
    virtual uint32_t Get_ad1250(double value) = 0;
};

#ifdef _MSC_VER
#define OB_CDECL_ad1250 __cdecl
#else
#define OB_CDECL_ad1250
#endif

#define OB_PAD_ad1250(n) virtual void Pad##n##_ad1250() = 0;
struct Target_ad1250 {
    OB_PAD_ad1250(0) OB_PAD_ad1250(1) OB_PAD_ad1250(2) OB_PAD_ad1250(3) OB_PAD_ad1250(4) OB_PAD_ad1250(5)
    OB_PAD_ad1250(6) OB_PAD_ad1250(7) OB_PAD_ad1250(8) OB_PAD_ad1250(9) OB_PAD_ad1250(10) OB_PAD_ad1250(11)
    OB_PAD_ad1250(12) OB_PAD_ad1250(13) OB_PAD_ad1250(14) OB_PAD_ad1250(15) OB_PAD_ad1250(16) OB_PAD_ad1250(17)
    OB_PAD_ad1250(18) OB_PAD_ad1250(19) OB_PAD_ad1250(20) OB_PAD_ad1250(21) OB_PAD_ad1250(22) OB_PAD_ad1250(23)
    OB_PAD_ad1250(24) OB_PAD_ad1250(25) OB_PAD_ad1250(26)
    virtual void OB_CDECL_ad1250 Set_ad1250(uint32_t value) = 0;
};
#undef OB_PAD_ad1250

// Text conversions (the framework's encoding helpers): the source string into dest, and dest back into a string.
// STUB: 0x0091152f
uint32_t Fn0091152f(cIGZString* source, cRZString* dest, int32_t encoding);
// STUB: 0x00911466
uint32_t Fn00911466(cRZString* source, int32_t encoding, cIGZString* dest);

// STUB: 0x00940da8
uint32_t Fn00940da8();

// STUB: 0x00923d58
void Fn00923d58();

// GLOBAL: 0x00a99f14
extern uint32_t g00a99f14;
// GLOBAL: 0x00aa1b74
extern uint32_t g00aa1b74;

// FUNCTION: 0x00968b60
uint32_t cRZLanguageUtility::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x00925991
bool cRZLanguageUtility::GetMeasurementSystem()
{
    return mnSubType != 0x36;
}

// FUNCTION: 0x00927c17
bool cRZLanguageUtility::GetLanguageRoadDrivingSide()
{
    if (mnType == 2 || mnType == 0xf) {
        return false;
    }
    return true;
}

// FUNCTION: 0x00927c2a
bool cRZLanguageUtility::QueryInterface(uint32_t riid, void* ppvObj)
{
    bool found;
    if ((riid != 0x1054b7d5 && riid != 1) == 0) {
        *static_cast<cRZLanguageUtility**>(ppvObj) = this;
        AddRef();
        found = true;
    } else {
        found = false;
    }
    return found;
}

// FUNCTION: 0x00927c4f
uint32_t cRZLanguageUtility::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x0092599b
bool cRZLanguageUtility::AreFirstAndLastNamesReversed()
{
    switch (mnType) {
    case 0xf:
    case 0x11:
    case 0x12:
    case 0x14:
        return true;
    }
    return false;
}

// FUNCTION: 0x009259b8
uint32_t cRZLanguageUtility::DoesLanguageUseInputMethodEditing()
{
    if (mnType == 0xf || mnType == 0x11 || mnType == 0x12 || mnType == 0x14) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00927ae3
bool cRZLanguageUtility::DoesCurrencySymbolPrecedeAmount()
{
    switch (mnType) {
    case 1:
    case 2:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    case 15:
    case 17:
    case 18:
    case 19:
    case 20:
    case 34:
    case 35:
        return true;
    case 3:
    case 4:
    case 6:
    case 9:
    case 11:
    case 13:
    case 14:
    case 16:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 33:
        return false;
    default:
        return false;
    }
}

// FUNCTION: 0x00927b2f
bool cRZLanguageUtility::IsSpaceBetweenCurrencySymbolAndAmount()
{
    switch (mnType) {
    case 1:
    case 2:
    case 10:
    case 12:
    case 15:
    case 17:
    case 18:
    case 19:
    case 20:
        return false;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 13:
    case 14:
    case 16:
    case 35:
        return true;
    default:
        return true;
    }
}

// FUNCTION: 0x00927b7b
bool cRZLanguageUtility::GetDecimalSeparator(void* pSink)
{
    Sink_ad1250* sink = static_cast<Sink_ad1250*>(pSink);
    bool ok;
    switch (mnType) {
    case 1:
    case 2:
    case 12:
    case 15:
    case 17:
    case 18:
    case 19:
    case 20:
        ok = true;
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 14:
    case 16:
    case 35:
        sink->Put_ad1250(&g00a99f14);
        return true;
    default:
        ok = false;
        break;
    }
    sink->Put_ad1250(&g00aa1b74);
    return ok;
}

// FUNCTION: 0x00927c66
bool cRZLanguageUtility::GetThousandSeparator(void* pSink)
{
    Sink_ad1250* sink = static_cast<Sink_ad1250*>(pSink);
    bool ok;
    switch (mnType) {
    case 1:
    case 2:
    case 12:
    case 15:
    case 17:
    case 18:
    case 19:
    case 20:
        ok = true;
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 13:
    case 14:
    case 35:
        sink->Put_ad1250(&g00aa1b74);
        return true;
    case 10:
    case 11:
    case 16:
        {
            const cRZString& name = mName;
            sink->Write_ad1250(name.data(), static_cast<uint32_t>(name.size()));
        }
        return true;
    default:
        ok = false;
        break;
    }
    sink->Put_ad1250(&g00a99f14);
    return ok;
}

// FUNCTION: 0x009256f5
uint32_t cRZLanguageUtility::GetCharacterSetFromLanguage()
{
    if (DoesLanguageUseCharacterSet(0x4e4)) {
        return 0x4e4;
    }
    if (DoesLanguageUseCharacterSet(0x4e2)) {
        return 0x4e2;
    }
    if (DoesLanguageUseCharacterSet(0x36a)) {
        return 0x36a;
    }
    if (DoesLanguageUseCharacterSet(0x3a4)) {
        return 0x3a4;
    }
    if (DoesLanguageUseCharacterSet(0x3a8)) {
        return 0x3a8;
    }
    if (DoesLanguageUseCharacterSet(0x3b6)) {
        return 0x3b6;
    }
    if (DoesLanguageUseCharacterSet(0x3b5)) {
        return 0x3b5;
    }
    if (DoesLanguageUseCharacterSet(0x4e3)) {
        return 0x4e3;
    }
    if (DoesLanguageUseCharacterSet(0x4e3)) {
        return 0x4e3;
    }
    if (DoesLanguageUseCharacterSet(0x4e5)) {
        return 0x4e5;
    }
    if (DoesLanguageUseCharacterSet(0x4e6)) {
        return 0x4e6;
    }
    if (DoesLanguageUseCharacterSet(0x4e7)) {
        return 0x4e7;
    }
    if (DoesLanguageUseCharacterSet(0x4e8)) {
        return 0x4e8;
    }
    if (DoesLanguageUseCharacterSet(0x4e9)) {
        return 0x4e9;
    }
    if (DoesLanguageUseCharacterSet(0x4e9)) {
        return 0x4e9;
    }
    return 0x4e4;
}


// FUNCTION: 0x009259d6
bool cRZLanguageUtility::DoesLanguageUseMultiByteCharacters()
{
    switch (Fn00940da8()) {
    case 0:
        return false;
    case 8:
        return mnType != 1 && mnType != 2;
    case 0x10:
        return false;
    }
    uint32_t t = mnType;
    return t == 0xf || t == 0x11 || t == 0x12 || t == 0x14 || t == 0x13;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0092580a score 119 (the original shares one "sete al" tail between the compare cases)
bool cRZLanguageUtility::DoesLanguageUseCharacterSet(uint32_t id)
{
    if (id == 0x4e4) {
        uint32_t t = mnType;
        return t == 1 || t == 2 || t == 3 || t == 4 || t == 5 || t == 8 || t == 9 || t == 7 || t == 10 || t == 14 ||
               t == 0x23 || t == 11 || t == 6 || t == 0x1c || t == 0x1d || t == 0x1e || t == 0x1f || t == 0x2a ||
               t == 0x24 || t == 0x25 || t == 0x26 || t == 0x27 || t == 0x28 || t == 0x29;
    }
    if (id == 0x4e2) {
        uint32_t t = mnType;
        return t == 0x10 || t == 0xd || t == 0x21 || t == 0x1a || t == 0x1c || t == 0x1e || t == 0x20;
    }
    if (id == 0x3a4) {
        return mnType == 0xf;
    }
    if (id == 0x3b5) {
        return mnType == 0x14;
    }
    if (id == 0x3a8) {
        return mnType == 0x11;
    }
    if (id == 0x3b6) {
        return mnType == 0x12;
    }
    if (id == 0x36a) {
        return mnType == 0x13;
    }
    if (id == 0x4e3) {
        uint32_t t = mnType;
        return t == 0xd || t == 0x18 || t == 0x17;
    }
    if (id == 0x4e5) {
        return mnType == 0x1b;
    }
    if (id == 0x4e6) {
        return mnType == 0x22;
    }
    if (id == 0x4e7) {
        return mnType == 0xc;
    }
    if (id == 0x4e8) {
        return mnType == 0x16;
    }
    return false;
}
#endif

// FUNCTION: 0x009279b0
bool cRZLanguageUtility::GetCurrencySymbol(void* pSink)
{
    Sink_ad1250* sink = static_cast<Sink_ad1250*>(pSink);
    bool ok = true;
    if (mbHasSymbol) {
        switch (mnType) {
        case 1:
        case 0x11:
        case 0x12:
            sink->Put_ad1250("$");
            break;
        case 2:
            sink->Put_ad1250("\xC2\xA3");
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 14:
        case 0x1b:
        case 0x26:
            sink->Put_ad1250("\xE2,\x82,\xAC");
            break;
        case 9:
        case 0x1d:
            sink->Put_ad1250("kr");
            break;
        case 12:
            sink->Put_ad1250("\xE2\x82\xAA");
            break;
        case 13:
            sink->Put_ad1250("\xD0\xB1");
            break;
        case 15:
            sink->Put_ad1250("\xC2\xA5");
            break;
        case 0x10:
            sink->Put_ad1250("\xC5\x82");
            break;
        case 0x13:
            sink->Put_ad1250("\xE0\xB8\xBF");
            break;
        case 0x14:
            sink->Put_ad1250("\\");
            break;
        case 0x1a:
            sink->Put_ad1250("K\xC4\x8D\x7B");
            break;
        case 0x1c:
            sink->Put_ad1250("FT");
            break;
        case 0x1e:
            sink->Put_ad1250("Lei");
            break;
        case 0x21:
            sink->Put_ad1250("Lek");
            break;
        case 0x22:
            sink->Put_ad1250("TL");
            break;
        case 0x23:
            sink->Put_ad1250("Esc.");
            break;
        default:
            break;
        }
    } else {
        sink->Put_ad1250("$");
    }
    if (sink->Query_ad1250() == 0) {
        sink->Put_ad1250("Untranslated");
        ok = false;
    }
    Fn00923d58();
    return ok;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00927bee score 7 (the original leaves the argument cleanup of the first call to the caller and loads the target vtable first)
bool cRZLanguageUtility::MakeFormattedNumberString(double value, void* pTarget, void* pSource)
{
    Target_ad1250* target = static_cast<Target_ad1250*>(pTarget);
    Source_ad1250* source = static_cast<Source_ad1250*>(pSource);
    target->Set_ad1250(source->Get_ad1250(value));
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00928fdd score 7 (the original keeps this in esi and bumps it with add where this spelling uses lea)
bool cRZLanguageUtility::Init()
{
    {
        cRZString text("\xC2\xA0");
        mName = text;
    }
    Fn00923d58();
    return true;
}
#endif

// FUNCTION: 0x00927e7e
void cRZLanguageUtility::ConvertToLowerCase(void* pSource, void* pText)
{
    cRZString converted;
    Fn0091152f(static_cast<cIGZString*>(pSource), &converted, -1);
    cIGZString* text = static_cast<cIGZString*>(pText);
    CharLowerBuffA(const_cast<char*>(converted.data()), text->Strlen());
    Fn00911466(&converted, -1, text);
}

// FUNCTION: 0x00927edf
void cRZLanguageUtility::ConvertToUpperCase(void* pSource, void* pText)
{
    cRZString converted;
    Fn0091152f(static_cast<cIGZString*>(pSource), &converted, -1);
    cIGZString* text = static_cast<cIGZString*>(pText);
    CharUpperBuffA(const_cast<char*>(converted.data()), text->Strlen());
    Fn00911466(&converted, -1, text);
}

// FUNCTION: 0x00927f40
int32_t cRZLanguageUtility::CompareStrings(void* pFirst, void* pSecond, bool caseSensitive)
{
    cRZString first;
    cRZString second;
    Fn0091152f(static_cast<cIGZString*>(pFirst), &first, -1);
    Fn0091152f(static_cast<cIGZString*>(pSecond), &second, -1);
    int32_t result = CompareStringA(0x400, caseSensitive == false, first.data(),
                                             static_cast<int32_t>(first.size()), second.data(),
                                             static_cast<int32_t>(second.size()));
    if (result != 0) {
        result -= 2;
    }
    return result;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009284ba score unknown (the tool cannot score jump-table functions; this spelling makes the table but starts it at 1 where the original compares 1 and 0x2a first and tables 2..0x2c)
bool cRZLanguageUtility::MakeTimeString(int32_t hour, int32_t minute, int32_t second, void* pSink)
{
    cRZString text;
    if (hour >= 24) {
        hour %= 24;
    }
    if (minute >= 60) {
        minute %= 60;
    }
    if (second >= 60) {
        second %= 60;
    }
    switch (mnType) {
    case 1:
    case 0x2a: {
        const char* suffix = "am";
        if (hour >= 12) {
            suffix = "pm";
        }
        if (hour == 0) {
            hour = 12;
        } else if (hour > 12) {
            hour -= 12;
        }
        if (second >= 0) {
            text.Sprintf("%u:%.2u:%.2u %s", hour, minute, second, suffix);
        } else if (minute < 0) {
            text.Sprintf("%u %s", hour, suffix);
        } else {
            text.Sprintf("%u:%.2u %s", hour, minute, suffix);
        }
        break;
    }
    
        case 2:
        case 3:
        case 4:
        case 10:
        case 0x10:
        case 0x1d:
            if (second >= 0) {
                text.Sprintf("%.2u:%.2u:%.2u", hour, minute, second);
            } else if (minute < 0) {
                text.Sprintf("%.2u:00", hour);
            } else {
                text.Sprintf("%.2u:%.2u", hour, minute);
            }
            break;
        case 5:
        case 0x1c:
            if (second >= 0) {
                text.Sprintf("%u.%.2u.%.2u", hour, minute, second);
            } else if (minute < 0) {
                text.Sprintf("%u:00", hour);
            } else {
                text.Sprintf("%u.%.2u", hour, minute);
            }
            break;
        case 8:
        case 9:
        case 0x24:
        case 0x27:
        case 0x28:
            if (second >= 0) {
                text.Sprintf("%.2u.%.2u.%.2u", hour, minute, second);
            } else if (minute < 0) {
                text.Sprintf("%.2u:00", hour);
            } else {
                text.Sprintf("%.2u.%.2u", hour, minute);
            }
            break;
        case 0x2c:
        case 6:
        case 7:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 37:
        case 38:
        case 41:
        case 43:
        default:
            if (second >= 0) {
                text.Sprintf("%u:%.2u:%.2u", hour, minute, second);
            } else if (minute < 0) {
                text.Sprintf("%u:00", hour);
            } else {
                text.Sprintf("%u:%.2u", hour, minute);
            }
            break;
    }
    static_cast<Sink_ad1250*>(pSink)->Put_ad1250(text.ToChar());
    return true;
}
#endif
