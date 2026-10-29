#include "classes/cGZDBSerialRecordAsIGZFile.h"

// The wrapped object at field 0x8. Only the slots this class calls are named by their number;
// the rest are padding so that the slot numbers line up with the original's vtable.
struct cInner_ad8468 {
    virtual void Pad00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void* Fn03();
    virtual bool Fn04();
    virtual void Fn05();
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
    virtual bool Fn27(uint32_t, uint32_t);
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
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Pad47();
    virtual void Pad48();
    virtual void Pad49();
    virtual void Pad50();
    virtual bool Fn51(uint32_t, uint32_t);
    virtual uint32_t Fn52();
    virtual bool Fn53(uint32_t);
    virtual uint32_t Fn54();
    virtual bool Fn55(uint32_t);
    virtual bool Fn56(uint32_t);
};

static inline cInner_ad8468* Inner_ad8468(void* p)
{
    return static_cast<cInner_ad8468*>(p);
}

// FUNCTION: 0x0096e957
bool cGZDBSerialRecordAsIGZFile::Slot04_abfe50()
{
    return mpTarget != 0;
}


// FUNCTION: 0x0096dce4
uint32_t cGZDBSerialRecordAsIGZFile::Slot06_abfe50()
{
    if (mpTarget) {
        return static_cast<cInner_ad8468*>(mpTarget)->Fn54();
    }
    return 0xffffffff;
}

// FUNCTION: 0x0096dd0c
bool cGZDBSerialRecordAsIGZFile::Slot08_abfe50(uint32_t a)
{
    if (mpTarget) {
        return static_cast<cInner_ad8468*>(mpTarget)->Fn53(a);
    }
    return false;
}

// FUNCTION: 0x0096de7e
bool cGZDBSerialRecordAsIGZFile::Slot16_abfe50(uint32_t a, uint32_t b)
{
    if (mpTarget) {
        return static_cast<cInner_ad8468*>(mpTarget)->Fn51(a, b);
    }
    return false;
}

// FUNCTION: 0x0096de22
bool cGZDBSerialRecordAsIGZFile::Slot14_abfe50(uint32_t a, uint32_t b)
{
    if (mpTarget) {
        return static_cast<cInner_ad8468*>(mpTarget)->Fn27(a, b);
    }
    return false;
}

// FUNCTION: 0x0096dd22
uint32_t cGZDBSerialRecordAsIGZFile::Slot09_abfe50()
{
    if (mpTarget && static_cast<cInner_ad8468*>(mpTarget)->Fn55(0)) {
        return 0;
    }
    return 0xffffffff;
}

// FUNCTION: 0x0096dda5
uint32_t cGZDBSerialRecordAsIGZFile::Slot12_abfe50(uint32_t a)
{
    if (mpTarget && static_cast<cInner_ad8468*>(mpTarget)->Fn55(a)) {
        return a;
    }
    return 0xffffffff;
}

// FUNCTION: 0x0096dd75
uint32_t cGZDBSerialRecordAsIGZFile::Slot11_abfe50(uint32_t a)
{
    if (mpTarget && static_cast<cInner_ad8468*>(mpTarget)->Fn56(a)) {
        return static_cast<cInner_ad8468*>(mpTarget)->Fn54();
    }
    return 0xffffffff;
}

// FUNCTION: 0x0096dd40
uint32_t cGZDBSerialRecordAsIGZFile::Slot10_abfe50()
{
    if (mpTarget) {
        uint32_t n = static_cast<cInner_ad8468*>(mpTarget)->Fn52();
        if (n && static_cast<cInner_ad8468*>(mpTarget)->Fn55(n)) {
            return n;
        }
    }
    return 0xffffffff;
}


// FUNCTION: 0x0096dc93
bool cGZDBSerialRecordAsIGZFile::SetDBSerialRecord(void* p)
{
    if (p) {
        Inner_ad8468(p)->AddRef();
    }
    if (mpTarget) {
        static_cast<cInner_ad8468*>(mpTarget)->Release();
    }
    mpTarget = p;
    return true;
}


// FUNCTION: 0x0096ddca
uint32_t cGZDBSerialRecordAsIGZFile::Slot13_abfe50(uint32_t a, uint32_t b)
{
    if (mpTarget) {
        switch (b) {
        case 0:
            return Slot12_abfe50(a);
        case 1:
            return Slot11_abfe50(a);
        case 2: {
            uint32_t n = static_cast<cInner_ad8468*>(mpTarget)->Fn52();
            if (n) {
                return Slot12_abfe50(n + a);
            }
        }
        }
    }
    return 0xffffffff;
}

// FUNCTION: 0x0096e96b
uint32_t cGZDBSerialRecordAsIGZFile::Slot02_ad8468()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Fn0096dc6e();
    return 0;
}

// FUNCTION: 0x0096dcbc
bool cGZDBSerialRecordAsIGZFile::Slot05_abfe50()
{
    bool result = false;
    if (mpTarget) {
        Inner_ad8468(Inner_ad8468(mpTarget)->Fn03())->Fn05();
        static_cast<cInner_ad8468*>(mpTarget)->Release();
        mpTarget = 0;
        result = true;
    }
    return result;
}


#ifdef OB_DRAFTS
// CLOSE: 0x0096dcf9 score 5
void cGZDBSerialRecordAsIGZFile::Slot07_abfe50()
{
    if (mpTarget != 0) {
        static_cast<cInner_ad8468*>(mpTarget)->Fn52();
    }
}
#endif

// FUNCTION: 0x0096dc2d
bool cGZDBSerialRecordAsIGZFile::QueryInterface(uint32_t riid, void* ppv)
{
    if (riid == 0xe0203645) {
        *static_cast<void**>(ppv) = static_cast<cUnk00abfe50*>(this);
    } else {
        if ((riid != 0x8a32c0ac && riid != 1) == 0) {
            *static_cast<void**>(ppv) = this;
        } else {
            return false;
        }
    }
    Slot01_ad8468();
    return true;
}
