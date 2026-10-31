#include <stddef.h>
#include "classes/cGZPersistBinaryReader.h"
#include "classes/cGZPersistBinaryWriter.h"
#include "classes/cGZPersistASCIIWriter.h"
#include <cstdio>
#include "gzcom/cRZString.h"

// The stream a binary reader pulls its values from: only the slots used here are named.
struct InStream_ada340 {
    virtual void Pad0_ada340();
    virtual void Pad1_ada340();
    virtual void Pad2_ada340();
    virtual void SkipBytes_ada340(uint32_t count);
    virtual void ReadSint8_ada340(void* pValue);
    virtual void ReadUint8_ada340(void* pValue);
    virtual void ReadSint16_ada340(void* pValue);
    virtual void ReadUint16_ada340(void* pValue);
    virtual void ReadSint32_ada340(void* pValue);
    virtual void ReadUint32_ada340(void* pValue);
    virtual void Pad10_ada340();
    virtual void Pad11_ada340();
    virtual void ReadFloat32_ada340(void* pValue);
    virtual void ReadFloat64_ada340(void* pValue);
    virtual void Pad14_ada340();
    virtual void ReadString_ada340(void* pString);
    virtual void Pad16_ada340();
    virtual void ReadBytes_ada340(void* pData, uint32_t count);
};

// The stream a binary writer pushes its values into.
struct OutStream_ada210 {
    virtual void Pad0_ada210();
    virtual void Pad1_ada210();
    virtual void Pad2_ada210();
    virtual void Flush_ada210();
    virtual void WriteSint8_ada210(int8_t value);
    virtual void WriteUint8_ada210(uint8_t value);
    virtual void WriteSint16_ada210(int16_t value);
    virtual void WriteUint16_ada210(uint16_t value);
    virtual void WriteSint32_ada210(uint32_t value);
    virtual void WriteUint32_ada210(uint32_t value);
    virtual void Pad10_ada210();
    virtual void Pad11_ada210();
    virtual void Pad12_ada210();
    virtual void Pad13_ada210();
    virtual void WriteChars_ada210(const char* text);
    virtual void WriteString_ada210(void* pString);
    virtual void Pad16_ada210();
    virtual void WriteBytes_ada210(const void* pData, uint32_t count);
};

// STUB: 0x0040cef0
OutStream_ada210* Fn0040cef0(void* pStream, float value);
// STUB: 0x004a7560
OutStream_ada210* Fn004a7560(void* pStream, double value);

// The resource records the reader stacks up (a stack of 0x1c-byte records); only the stream is named.
struct ResourceInfo_ada340 {
    char* mpResources;
    char mPad[0x8];
    char* mpReferents;
    char mPad2[0x8];
    void* mpStream;
};

struct ReaderStack_ada340 {
    // STUB: 0x00983d46
    void Construct_ada340();
    // STUB: 0x00983a13
    void Destroy_ada340();
    // STUB: 0x00982bb6
    ResourceInfo_ada340* back();
};

struct Serializable_ada288;
struct Res_ada288;
struct Releasable_ada288;

// The surveyor writers a writer stacks; slot 28 hands out the stream.
struct SurveyorWriter_ada288 {
    virtual void Pad0_ada288();
    virtual void Pad1_ada288();
    virtual void Pad2_ada288();
    virtual void SetRoot_ada288(void* pRoot, uint32_t b);
    virtual void Pad4_ada288();
    virtual void Pad5_ada288();
    virtual void Pad6_ada288();
    virtual void Pad7_ada288();
    virtual void Pad8_ada288();
    virtual void Pad9_ada288();
    virtual void Pad10_ada288();
    virtual void Pad11_ada288();
    virtual void Pad12_ada288();
    virtual void Pad13_ada288();
    virtual void Pad14_ada288();
    virtual void Pad15_ada288();
    virtual void Pad16_ada288();
    virtual void Pad17_ada288();
    virtual void Pad18_ada288();
    virtual void Pad19_ada288();
    virtual void Pad20_ada288();
    virtual void Pad21_ada288();
    virtual void Pad22_ada288();
    virtual void Pad23_ada288();
    virtual void Pad24_ada288();
    virtual void Pad25_ada288();
    virtual void Pad26_ada288();
    virtual void Pad27_ada288();
    virtual void* Stream_ada288();
    virtual void Pad29_ada288();
    virtual void* Resource_ada288();
    virtual uint32_t ReferentCount_ada288();
    virtual Serializable_ada288* GetReferent_ada288(uint32_t index);
    virtual uint32_t IdOfObject_ada288(void* pObject);
    virtual uint32_t ResourceCount_ada288();
    virtual Res_ada288* GetResource_ada288(uint32_t index);
    virtual uint32_t IdOfResource_ada288(void* pResource);
};

// A resource of the surveyor and the key parts it hands out.
struct KeyPart_ada288 {
    virtual void Pad0_ada288();
    virtual void Pad1_ada288();
    virtual void Pad2_ada288();
    virtual const uint32_t* GetKey_ada288(uint32_t* pOut);
};

struct Res_ada288 {
    virtual void Pad0_ada288();
    virtual void Pad1_ada288();
    virtual void Pad2_ada288();
    virtual void Pad3_ada288();
    virtual void* const* GetName_ada288(Releasable_ada288** ppRef);
    virtual void Pad5_ada288();
    virtual void Pad6_ada288();
    virtual KeyPart_ada288* GetPart_ada288();
    virtual KeyPart_ada288* GetOwnerPart_ada288();
    virtual void Pad9_ada288();
    virtual void Finish_ada288();
    virtual uint32_t IdOfObject_ada288(void* pObject);
};

struct SurveyorStack_ada288 {
    // STUB: 0x009832ad
    void PushBack_ada288(void* pItem);
    // STUB: 0x00982bd7
    void PopBack_ada288();
    // STUB: 0x0089223d
    void Construct_ada288();
    // STUB: 0x00983105
    void Destroy_ada288();
    // STUB: 0x00892041
    SurveyorWriter_ada288** back();
};

// What a writer is handed to serialize: slot 4 hands out the type record, slot 5 writes the object.
struct Releasable_ada288 {
    virtual void Pad0_ada288();
    virtual void Pad1_ada288();
    virtual void Release_ada288();
};

struct Serializable_ada288 {
    virtual void Pad0_ada288();
    virtual void Pad1_ada288();
    virtual void Pad2_ada288();
    virtual void Pad3_ada288();
    virtual const uint32_t* GetTypeInfo_ada288(Releasable_ada288** ppRef);
    virtual void Write_ada288(void* pWriter);
    virtual void* Resource_ada288();
};

// FUNCTION: 0x009819f1
uint32_t cGZPersistBinaryReader::Release()
{
    if (--mnRefCount == 0) {
        delete this;
        return 0;
    }
    return mnRefCount;
}

// FUNCTION: 0x00981a40
uint32_t cGZPersistASCIIWriter::Release()
{
    if (--mnRefCount == 0) {
        delete this;
        return 0;
    }
    return mnRefCount;
}

// FUNCTION: 0x00981a1a
void cGZPersistBinaryReader::ReadString(const char* /*name*/, void* pString)
{
    static_cast<InStream_ada340*>(InputStream())->ReadString_ada340(pString);
}

// FUNCTION: 0x00981a2d
void cGZPersistBinaryReader::SkipBytes(const char* /*name*/, uint32_t count)
{
    static_cast<InStream_ada340*>(InputStream())->SkipBytes_ada340(count);
}

// FUNCTION: 0x00981a69
void cGZPersistBinaryWriter::WriteString_3(const char* /*name*/, void* pString)
{
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteString_ada210(pString);
}

// FUNCTION: 0x00981a7c
void cGZPersistBinaryWriter::WriteString(const char* /*name*/, const char* text)
{
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteChars_ada210(text);
}

// FUNCTION: 0x00981d99
void cGZPersistBinaryWriter::WriteSint8(const char* /*name*/, uint32_t value)
{
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteSint8_ada210(value);
}

// FUNCTION: 0x00981dac
void cGZPersistBinaryWriter::WriteUint8(const char* /*name*/, uint32_t value)
{
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint8_ada210(value);
}

// FUNCTION: 0x00981dbf
void cGZPersistBinaryWriter::WriteSint16(const char* /*name*/, uint32_t value)
{
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteSint16_ada210(value);
}

// FUNCTION: 0x00981dd2
void cGZPersistBinaryWriter::WriteUint16(const char* /*name*/, uint32_t value)
{
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint16_ada210(value);
}

// FUNCTION: 0x00981de5
void cGZPersistBinaryWriter::WriteSint32(const char* /*name*/, uint32_t value)
{
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteSint32_ada210(value);
}

// FUNCTION: 0x00981df8
void cGZPersistBinaryWriter::WriteUint32(const char* /*name*/, uint32_t value)
{
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint32_ada210(value);
}

// FUNCTION: 0x00981a03
void cGZPersistBinaryReader::ReadUint8Array(const char* /*name*/, void* pData, uint32_t count)
{
    static_cast<InStream_ada340*>(InputStream())->ReadBytes_ada340(pData, count);
}

// FUNCTION: 0x00981a52
void cGZPersistBinaryWriter::WriteUint8Array(const char* /*name*/, const void* pData, uint32_t count)
{
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteBytes_ada210(pData, count);
}

// FUNCTION: 0x00981e0b
void cGZPersistBinaryWriter::WriteFloat32(const char* /*name*/, float value)
{
    Fn0040cef0(Slot28_ada210(), value);
}

// FUNCTION: 0x00981e23
void cGZPersistBinaryWriter::WriteFloat64(const char* /*name*/, double value)
{
    Fn004a7560(Slot28_ada210(), value);
}

// FUNCTION: 0x00981afa
int8_t cGZPersistBinaryReader::ReadSint8(const char* /*name*/)
{
    int8_t value;
    static_cast<InStream_ada340*>(InputStream())->ReadSint8_ada340(&value);
    return value;
}

// FUNCTION: 0x00981b15
uint8_t cGZPersistBinaryReader::ReadUint8(const char* /*name*/)
{
    uint8_t value;
    static_cast<InStream_ada340*>(InputStream())->ReadUint8_ada340(&value);
    return value;
}

// FUNCTION: 0x00981b30
int16_t cGZPersistBinaryReader::ReadSint16(const char* /*name*/)
{
    int16_t value;
    static_cast<InStream_ada340*>(InputStream())->ReadSint16_ada340(&value);
    return value;
}

// FUNCTION: 0x00981b4c
uint16_t cGZPersistBinaryReader::ReadUint16(const char* /*name*/)
{
    uint16_t value;
    static_cast<InStream_ada340*>(InputStream())->ReadUint16_ada340(&value);
    return value;
}

// FUNCTION: 0x00981b68
int32_t cGZPersistBinaryReader::ReadSint32(const char* /*name*/)
{
    int32_t value;
    static_cast<InStream_ada340*>(InputStream())->ReadSint32_ada340(&value);
    return value;
}

// FUNCTION: 0x00981b83
uint32_t cGZPersistBinaryReader::ReadUint32(const char* /*name*/)
{
    uint32_t value;
    static_cast<InStream_ada340*>(InputStream())->ReadUint32_ada340(&value);
    return value;
}

// FUNCTION: 0x00981b9e
float cGZPersistBinaryReader::ReadFloat32(const char* /*name*/)
{
    float value;
    static_cast<InStream_ada340*>(InputStream())->ReadFloat32_ada340(&value);
    return value;
}

// FUNCTION: 0x00981bb9
double cGZPersistBinaryReader::ReadFloat64(const char* /*name*/)
{
    double value;
    static_cast<InStream_ada340*>(InputStream())->ReadFloat64_ada340(&value);
    return value;
}

// FUNCTION: 0x00981ada
bool cGZPersistBinaryReader::ReadBool(const char* /*name*/)
{
    uint8_t value;
    static_cast<InStream_ada340*>(InputStream())->ReadUint8_ada340(&value);
    return value != 0;
}

// FUNCTION: 0x00981c0d
void cGZPersistBinaryReader::ReadSint16Array(const char* /*name*/, char* pData, uint32_t count)
{
    while (count > 0) {
        static_cast<InStream_ada340*>(InputStream())->ReadSint16_ada340(pData);
        pData += 2;
        --count;
    }
}

// FUNCTION: 0x00981c38
void cGZPersistBinaryReader::ReadUint16Array(const char* /*name*/, char* pData, uint32_t count)
{
    while (count > 0) {
        static_cast<InStream_ada340*>(InputStream())->ReadUint16_ada340(pData);
        pData += 2;
        --count;
    }
}

// FUNCTION: 0x00981c63
void cGZPersistBinaryReader::ReadSint32Array(const char* /*name*/, char* pData, uint32_t count)
{
    while (count > 0) {
        static_cast<InStream_ada340*>(InputStream())->ReadSint32_ada340(pData);
        pData += 4;
        --count;
    }
}

// FUNCTION: 0x00981c8e
void cGZPersistBinaryReader::ReadUint32Array(const char* /*name*/, char* pData, uint32_t count)
{
    while (count > 0) {
        static_cast<InStream_ada340*>(InputStream())->ReadUint32_ada340(pData);
        pData += 4;
        --count;
    }
}

// FUNCTION: 0x00981cb9
void cGZPersistBinaryReader::ReadFloat32Array(const char* /*name*/, char* pData, uint32_t count)
{
    while (count > 0) {
        static_cast<InStream_ada340*>(InputStream())->ReadFloat32_ada340(pData);
        pData += 4;
        --count;
    }
}

// FUNCTION: 0x00981ce4
void cGZPersistBinaryReader::ReadFloat64Array(const char* /*name*/, char* pData, uint32_t count)
{
    while (count > 0) {
        static_cast<InStream_ada340*>(InputStream())->ReadFloat64_ada340(pData);
        pData += 8;
        --count;
    }
}

// FUNCTION: 0x00981bd5
void cGZPersistBinaryReader::ReadBoolArray(const char* /*name*/, char* pData, uint32_t count)
{
    while (count > 0) {
        uint8_t value;
        static_cast<InStream_ada340*>(InputStream())->ReadUint8_ada340(&value);
        *pData = value != 0;
        ++pData;
        --count;
    }
}

// FUNCTION: 0x00981e3d
void cGZPersistBinaryWriter::WriteBoolArray(const char* /*name*/, const char* pData, uint32_t count)
{
    while (count > 0) {
        uint8_t value = static_cast<uint8_t>(*pData);
        static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint8_ada210(value);
        ++pData;
        --count;
    }
}

// FUNCTION: 0x00981e70
void cGZPersistBinaryWriter::WriteSint16Array(const char* /*name*/, const char* pData, uint32_t count)
{
    while (count > 0) {
        int16_t value = *reinterpret_cast<const int16_t*>(pData);
        static_cast<OutStream_ada210*>(Slot28_ada210())->WriteSint16_ada210(value);
        pData += 2;
        --count;
    }
}

// FUNCTION: 0x00981ea5
void cGZPersistBinaryWriter::WriteUint16Array(const char* /*name*/, const char* pData, uint32_t count)
{
    while (count > 0) {
        uint16_t value = *reinterpret_cast<const uint16_t*>(pData);
        static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint16_ada210(value);
        pData += 2;
        --count;
    }
}

// FUNCTION: 0x00981eda
void cGZPersistBinaryWriter::WriteSint32Array(const char* /*name*/, const char* pData, uint32_t count)
{
    while (count > 0) {
        int32_t value = *reinterpret_cast<const int32_t*>(pData);
        static_cast<OutStream_ada210*>(Slot28_ada210())->WriteSint32_ada210(value);
        pData += 4;
        --count;
    }
}

// FUNCTION: 0x00981f0f
void cGZPersistBinaryWriter::WriteUint32Array(const char* /*name*/, const char* pData, uint32_t count)
{
    while (count > 0) {
        uint32_t value = *reinterpret_cast<const uint32_t*>(pData);
        static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint32_ada210(value);
        pData += 4;
        --count;
    }
}

// FUNCTION: 0x00981f44
void cGZPersistBinaryWriter::WriteFloat32Array(const char* /*name*/, const char* pData, uint32_t count)
{
    while (count > 0) {
        Fn0040cef0(Slot28_ada210(), *reinterpret_cast<const float*>(pData));
        pData += 4;
        --count;
    }
}

// FUNCTION: 0x00981f76
void cGZPersistBinaryWriter::WriteFloat64Array(const char* /*name*/, const char* pData, uint32_t count)
{
    while (count > 0) {
        Fn004a7560(Slot28_ada210(), *reinterpret_cast<const double*>(pData));
        pData += 8;
        --count;
    }
}

// FUNCTION: 0x0098209e
void cGZPersistASCIIWriter::WriteSint8(const char* name, uint32_t value)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Sint8 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    s->WriteSint8_ada210(value);
    s->WriteChars_ada210("\n");
}

// FUNCTION: 0x009820e4
void cGZPersistASCIIWriter::WriteUint8(const char* name, uint32_t value)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Uint8 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    s->WriteUint8_ada210(value);
    s->WriteChars_ada210("\n");
}

// FUNCTION: 0x0098212a
void cGZPersistASCIIWriter::WriteSint16(const char* name, uint32_t value)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Sint16 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    s->WriteSint16_ada210(value);
    s->WriteChars_ada210("\n");
}

// FUNCTION: 0x00982170
void cGZPersistASCIIWriter::WriteUint16(const char* name, uint32_t value)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Uint16 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    s->WriteUint16_ada210(value);
    s->WriteChars_ada210("\n");
}

// FUNCTION: 0x009821b6
void cGZPersistASCIIWriter::WriteSint32(const char* name, uint32_t value)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Sint32 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    s->WriteSint32_ada210(value);
    s->WriteChars_ada210("\n");
}

// FUNCTION: 0x009821fc
void cGZPersistASCIIWriter::WriteUint32(const char* name, uint32_t value)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Uint32 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    s->WriteUint32_ada210(value);
    s->WriteChars_ada210("\n");
}

// FUNCTION: 0x00982048
void cGZPersistASCIIWriter::WriteBool(const char* name, bool value)
{
    const char* text = "true";
    if (!value) {
        text = "false";
    }
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      bool ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    s->WriteChars_ada210(text);
    s->WriteChars_ada210("\n");
}

// FUNCTION: 0x00982242
void cGZPersistASCIIWriter::WriteFloat32(const char* name, float value)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Float32 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    Fn0040cef0(s, value)->WriteChars_ada210("\n");
}

// FUNCTION: 0x0098228d
void cGZPersistASCIIWriter::WriteFloat64(const char* name, double value)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Float64 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    Fn004a7560(s, value)->WriteChars_ada210("\n");
}

// FUNCTION: 0x00982819
void cGZPersistASCIIWriter::WriteString_4(const char* name, void* pString)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      RZString ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    s->WriteString_ada210(pString);
    s->WriteChars_ada210("\n");
}

// FUNCTION: 0x0098285f
void cGZPersistASCIIWriter::WriteString(const char* name, const char* text)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      RZChar* ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    s->WriteChars_ada210(text);
    s->WriteChars_ada210("\n");
}

// FUNCTION: 0x009828a5
void cGZPersistASCIIWriter::WriteUint32InHex(uint32_t value)
{
    char text[11] = "0x00000000";
    std::sprintf(text, "0x%08x", value);
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210(text);
}

// FUNCTION: 0x009828ea
void cGZPersistASCIIWriter::WriteKey(const void* pKey)
{
    const uint32_t* key = static_cast<const uint32_t*>(pKey);
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("G:");
    WriteUint32InHex(key[1]);
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210(" I:");
    WriteUint32InHex(key[2]);
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210(" T:");
    WriteUint32InHex(key[0]);
}

// FUNCTION: 0x0098237b
void cGZPersistASCIIWriter::WriteSint8Array(const char* name, const char* pData, uint32_t count)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Sint8 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210("[");
    s->WriteUint32_ada210(count);
    s->WriteChars_ada210("] = ");
    for (uint32_t i = 0; i < count; ++i) {
        int8_t value = *reinterpret_cast<const int8_t*>(pData);
        s = static_cast<OutStream_ada210*>(Slot28_ada288());
        s->WriteSint8_ada210(value);
        s->WriteChars_ada210(", ");
        pData += 1;
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}

// FUNCTION: 0x00982411
void cGZPersistASCIIWriter::WriteUint8Array(const char* name, const char* pData, uint32_t count)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Uint8 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210("[");
    s->WriteUint32_ada210(count);
    s->WriteChars_ada210("] = ");
    for (uint32_t i = 0; i < count; ++i) {
        uint8_t value = *reinterpret_cast<const uint8_t*>(pData);
        s = static_cast<OutStream_ada210*>(Slot28_ada288());
        s->WriteUint8_ada210(value);
        s->WriteChars_ada210(", ");
        pData += 1;
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}

// FUNCTION: 0x009824a7
void cGZPersistASCIIWriter::WriteSint16Array(const char* name, const char* pData, uint32_t count)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Sint16 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210("[");
    s->WriteUint32_ada210(count);
    s->WriteChars_ada210("] = ");
    for (uint32_t i = 0; i < count; ++i) {
        int16_t value = *reinterpret_cast<const int16_t*>(pData);
        s = static_cast<OutStream_ada210*>(Slot28_ada288());
        s->WriteSint16_ada210(value);
        s->WriteChars_ada210(", ");
        pData += 2;
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}

// FUNCTION: 0x0098253c
void cGZPersistASCIIWriter::WriteUint16Array(const char* name, const char* pData, uint32_t count)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Uint16 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210("[");
    s->WriteUint32_ada210(count);
    s->WriteChars_ada210("] = ");
    for (uint32_t i = 0; i < count; ++i) {
        uint16_t value = *reinterpret_cast<const uint16_t*>(pData);
        s = static_cast<OutStream_ada210*>(Slot28_ada288());
        s->WriteUint16_ada210(value);
        s->WriteChars_ada210(", ");
        pData += 2;
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}

// FUNCTION: 0x009825d1
void cGZPersistASCIIWriter::WriteSint32Array(const char* name, const char* pData, uint32_t count)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Sint32 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210("[");
    s->WriteUint32_ada210(count);
    s->WriteChars_ada210("] = ");
    for (uint32_t i = 0; i < count; ++i) {
        int32_t value = *reinterpret_cast<const int32_t*>(pData);
        s = static_cast<OutStream_ada210*>(Slot28_ada288());
        s->WriteSint32_ada210(value);
        s->WriteChars_ada210(", ");
        pData += 4;
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}

// FUNCTION: 0x00982665
void cGZPersistASCIIWriter::WriteUint32Array(const char* name, const char* pData, uint32_t count)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Uint32 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210("[");
    s->WriteUint32_ada210(count);
    s->WriteChars_ada210("] = ");
    for (uint32_t i = 0; i < count; ++i) {
        uint32_t value = *reinterpret_cast<const uint32_t*>(pData);
        s = static_cast<OutStream_ada210*>(Slot28_ada288());
        s->WriteUint32_ada210(value);
        s->WriteChars_ada210(", ");
        pData += 4;
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}

// FUNCTION: 0x009822da
void cGZPersistASCIIWriter::WriteBoolArray(const char* name, const char* pData, uint32_t count)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      bool ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210("[");
    s->WriteUint32_ada210(count);
    s->WriteChars_ada210("] = ");
    for (uint32_t i = 0; i < count; ++i) {
        const char* text = "true";
        if (*pData++ == 0) {
            text = "false";
        }
        s = static_cast<OutStream_ada210*>(Slot28_ada288());
        s->WriteChars_ada210(text);
        s->WriteChars_ada210(", ");
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}

// FUNCTION: 0x009826f9
void cGZPersistASCIIWriter::WriteFloat32Array(const char* name, const char* pData, uint32_t count)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Float32 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210("[");
    s->WriteUint32_ada210(count);
    s->WriteChars_ada210("] = ");
    for (uint32_t i = 0; i < count; ++i) {
        Fn0040cef0(Slot28_ada288(), *reinterpret_cast<const float*>(pData))->WriteChars_ada210(", ");
        pData += 4;
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}

// FUNCTION: 0x00982788
void cGZPersistASCIIWriter::WriteFloat64Array(const char* name, const char* pData, uint32_t count)
{
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      Float64 ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210("[");
    s->WriteUint32_ada210(count);
    s->WriteChars_ada210("] = ");
    for (uint32_t i = 0; i < count; ++i) {
        Fn004a7560(Slot28_ada288(), *reinterpret_cast<const double*>(pData))->WriteChars_ada210(", ");
        pData += 8;
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}

// FUNCTION: 0x00982e64
void* cGZPersistBinaryReader::InputStream()
{
    return reinterpret_cast<ReaderStack_ada340*>(reinterpret_cast<char*>(this) + 8)->back()->mpStream;
}

// FUNCTION: 0x00982f1c
void* cGZPersistASCIIWriter::Slot28_ada288()
{
    return (*reinterpret_cast<SurveyorStack_ada288*>(reinterpret_cast<char*>(this) + 8)->back())->Stream_ada288();
}

// FUNCTION: 0x00982a1f
void cGZPersistASCIIWriter::WriteTypeInfo(const void* pInfo)
{
    const uint32_t* info = static_cast<const uint32_t*>(pInfo);
    void* typeName = reinterpret_cast<void* const*>(info)[0];
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      TypeName: ");
    s->WriteString_ada210(typeName);
    s->WriteChars_ada210(" GZCLSID: ");
    WriteUint32InHex(info[1]);
    s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210(" Version: ");
    s->WriteUint32_ada210(info[2]);
    s->WriteChars_ada210("\n");
}

// FUNCTION: 0x0098298a
void cGZPersistASCIIWriter::WriteObject(const char* /*name*/, void* pObject)
{
    Serializable_ada288* object = static_cast<Serializable_ada288*>(pObject);
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("      Object GZCLSID: ");
    if (object != 0) {
        Releasable_ada288* refs[3];
        WriteUint32InHex(object->GetTypeInfo_ada288(&refs[0])[1]);
        if (refs[0] != 0) {
            refs[0]->Release_ada288();
        }
        static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n      {\n");
        object->Write_ada288(this);
        static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("      }\n");
    } else {
        WriteUint32InHex(0);
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}

// FUNCTION: 0x00982006
void cGZPersistBinaryWriter::WriteTypeInfo(const void* pInfo)
{
    const uint32_t* info = static_cast<const uint32_t*>(pInfo);
    void* typeName = reinterpret_cast<void* const*>(info)[0];
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteString_ada210(typeName);
    uint32_t group = info[1];
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint32_ada210(group);
    uint32_t version = info[2];
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint32_ada210(version);
}

// FUNCTION: 0x00981faa
void cGZPersistBinaryWriter::WriteObject(const char* /*name*/, void* pObject)
{
    Serializable_ada288* object = static_cast<Serializable_ada288*>(pObject);
    if (object != 0) {
        Releasable_ada288* refs[3];
        uint32_t clsid = object->GetTypeInfo_ada288(&refs[0])[1];
        static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint32_ada210(clsid);
        if (refs[0] != 0) {
            refs[0]->Release_ada288();
        }
        object->Write_ada288(this);
    } else {
        static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint32_ada210(0);
    }
}

// FUNCTION: 0x009832df
cGZPersistBinaryWriter::cGZPersistBinaryWriter()
{
    mnRefCount = 0;
    reinterpret_cast<SurveyorStack_ada288*>(reinterpret_cast<char*>(this) + 8)->Construct_ada288();
}

// FUNCTION: 0x00983314
cGZPersistASCIIWriter::cGZPersistASCIIWriter()
{
    mnRefCount = 0;
    reinterpret_cast<SurveyorStack_ada288*>(reinterpret_cast<char*>(this) + 8)->Construct_ada288();
}

// FUNCTION: 0x00983d5b
cGZPersistBinaryReader::cGZPersistBinaryReader()
{
    mnRefCount = 0;
    reinterpret_cast<ReaderStack_ada340*>(reinterpret_cast<char*>(this) + 8)->Construct_ada340();
}

// FUNCTION: 0x00983291
cGZPersistBinaryWriter::~cGZPersistBinaryWriter()
{
    reinterpret_cast<SurveyorStack_ada288*>(reinterpret_cast<char*>(this) + 8)->Destroy_ada288();
}

// FUNCTION: 0x0098329f
cGZPersistASCIIWriter::~cGZPersistASCIIWriter()
{
    reinterpret_cast<SurveyorStack_ada288*>(reinterpret_cast<char*>(this) + 8)->Destroy_ada288();
}

// FUNCTION: 0x00983a41
cGZPersistBinaryReader::~cGZPersistBinaryReader()
{
    reinterpret_cast<ReaderStack_ada340*>(reinterpret_cast<char*>(this) + 8)->Destroy_ada340();
}

// The objects a reader/writer hands around.
struct Unknown_ada340 {
    virtual bool QueryInterface_ada340(uint32_t iid, void* ppOut);
    virtual void Pad1_ada340();
    virtual void Release_ada340();
    virtual void Read_ada340(void* pReader);
};

struct Framework_ada340 {
    virtual void Pad0_ada340();
    virtual void Pad1_ada340();
    virtual void Pad2_ada340();
    virtual void Create_ada340(uint32_t clsid, uint32_t iid, void** ppOut);
};

// STUB: 0x0090ddf1
Framework_ada340* Fn0090ddf1();

struct Referent_ada210 {
    virtual void Pad0_ada210();
    virtual void Pad1_ada210();
    virtual void Pad2_ada210();
    virtual void Pad3_ada210();
    virtual void Pad4_ada210();
    virtual void Pad5_ada210();
    virtual void* Resource_ada210();
};

// FUNCTION: 0x00982e70
void cGZPersistBinaryWriter::WriteObjectRef_3(const char* /*name*/, void* pObject)
{
    Referent_ada210* object = static_cast<Referent_ada210*>(pObject);
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint8_ada210(object != 0);
    if (object != 0) {
        void* resource = object->Resource_ada210();
        SurveyorStack_ada288* stack = reinterpret_cast<SurveyorStack_ada288*>(reinterpret_cast<char*>(this) + 8);
        bool outside = (*stack->back())->Resource_ada288() != resource;
        static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint8_ada210(outside);
        uint32_t id;
        if ((*stack->back())->Resource_ada288() != resource) {
            id = (*stack->back())->IdOfResource_ada288(resource);
        } else {
            id = (*stack->back())->IdOfObject_ada288(object);
        }
        static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint32_ada210(id);
    }
}

// FUNCTION: 0x00981d0f
void cGZPersistBinaryReader::ReadObject(const char* /*name*/, uint32_t iid, void* ppOut)
{
    uint32_t id;
    static_cast<InStream_ada340*>(InputStream())->ReadUint32_ada340(&id);
    if (id != 0) {
        Unknown_ada340* object = 0;
        Fn0090ddf1()->Create_ada340(id, 0x5b0aaa74, reinterpret_cast<void**>(&object));
        object->Read_ada340(this);
        object->QueryInterface_ada340(iid, ppOut);
        if (object != 0) {
            object->Release_ada340();
        }
    } else {
        *static_cast<void**>(ppOut) = 0;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00982dbb score 39
void cGZPersistBinaryReader::ReadObjectRef(const char* name, uint32_t iid, void* ppOut)
{
    uint8_t present;
    static_cast<InStream_ada340*>(InputStream())->ReadUint8_ada340(&present);
    if (present != 0) {
        uint8_t inResource;
        uint32_t index;
        static_cast<InStream_ada340*>(InputStream())->ReadUint8_ada340(&inResource);
        static_cast<InStream_ada340*>(InputStream())->ReadUint32_ada340(&index);
        *static_cast<void**>(ppOut) = 0;
        ReaderStack_ada340* stack = reinterpret_cast<ReaderStack_ada340*>(reinterpret_cast<char*>(this) + 8);
        if (inResource != 0) {
            if (*reinterpret_cast<Unknown_ada340**>(stack->back()->mpResources + index * 4) != 0) {
                (*reinterpret_cast<Unknown_ada340**>(stack->back()->mpResources + index * 4))->QueryInterface_ada340(iid, ppOut);
            }
        } else {
            if (*reinterpret_cast<Unknown_ada340**>(stack->back()->mpReferents + index * 4) != 0) {
                (*reinterpret_cast<Unknown_ada340**>(stack->back()->mpReferents + index * 4))->QueryInterface_ada340(iid, ppOut);
            }
        }
    } else {
        *static_cast<void**>(ppOut) = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009819c8 score 10
bool cGZPersistBinaryReader::QueryInterface(uint32_t iid, uint32_t ppOut)
{
    void** pp = OB_PTR(void*, ppOut);
    if (pp == 0 || (iid != 1 && iid != 0xfb0c4344)) {
        return false;
    }
    *pp = this;
    AddRef();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00981a8f score 15
bool cGZPersistASCIIWriter::QueryInterface(uint32_t iid, uint32_t ppOut)
{
    void** pp = OB_PTR(void*, ppOut);
    if (pp == 0 || (iid != 1 && iid != 0x1b0aab0e)) {
        return false;
    }
    *pp = this;
    AddRef();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009833cc score 58
void cGZPersistBinaryWriter::WriteRoot(void* pRoot, uint32_t b)
{
    Unknown_ada340* surveyor = 0;
    Fn0090ddf1()->Create_ada340(0xbb194c78, 0x9b194c66, reinterpret_cast<void**>(&surveyor));
    SurveyorStack_ada288* stack = reinterpret_cast<SurveyorStack_ada288*>(reinterpret_cast<char*>(this) + 8);
    stack->PushBack_ada288(&surveyor);
    (*stack->back())->SetRoot_ada288(pRoot, b);
    uint32_t count = (*stack->back())->ResourceCount_ada288();
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint32_ada210(count);
    uint32_t i = 0;
    for (;;) {
        if (i >= (*stack->back())->ResourceCount_ada288()) {
            break;
        }
        Res_ada288* resource = (*stack->back())->GetResource_ada288(i);
        KeyPart_ada288* part0 = resource->GetPart_ada288();
        KeyPart_ada288* part1 = resource->GetPart_ada288();
        KeyPart_ada288* part2 = resource->GetPart_ada288();
        uint32_t tmp0[3];
        uint32_t tmp1[3];
        uint32_t tmp2[3];
        uint32_t x = part0->GetKey_ada288(tmp0)[0];
        uint32_t y = part1->GetKey_ada288(tmp1)[2];
        uint32_t z = part2->GetKey_ada288(tmp2)[1];
        OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada210());
        s->WriteUint32_ada210(z);
        s->WriteUint32_ada210(y);
        s->WriteUint32_ada210(x);
        ++i;
    }
    count = (*stack->back())->ReferentCount_ada288();
    static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint32_ada210(count);
    i = 0;
    for (;;) {
        if (i >= (*stack->back())->ReferentCount_ada288()) {
            break;
        }
        Releasable_ada288* refs[3];
        uint32_t id = (*stack->back())->GetReferent_ada288(i)->GetTypeInfo_ada288(&refs[0])[1];
        static_cast<OutStream_ada210*>(Slot28_ada210())->WriteUint32_ada210(id);
        if (refs[0] != 0) {
            refs[0]->Release_ada288();
        }
        ++i;
    }
    i = 0;
    for (;;) {
        if (i >= (*stack->back())->ReferentCount_ada288()) {
            break;
        }
        (*stack->back())->GetReferent_ada288(i)->Write_ada288(this);
        ++i;
    }
    static_cast<OutStream_ada210*>(Slot28_ada210())->Flush_ada210();
    i = 0;
    for (;;) {
        if (i >= (*stack->back())->ResourceCount_ada288()) {
            break;
        }
        (*stack->back())->GetResource_ada288(i)->Finish_ada288();
        ++i;
    }
    stack->PopBack_ada288();
    if (surveyor != 0) {
        surveyor->Release_ada340();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009835ed score 193
void cGZPersistASCIIWriter::WriteRoot(void* pRoot, uint32_t b)
{
    Unknown_ada340* surveyor = 0;
    Fn0090ddf1()->Create_ada340(0xbb194c78, 0x9b194c66, reinterpret_cast<void**>(&surveyor));
    SurveyorStack_ada288* stack = reinterpret_cast<SurveyorStack_ada288*>(reinterpret_cast<char*>(this) + 8);
    stack->PushBack_ada288(&surveyor);
    (*stack->back())->SetRoot_ada288(pRoot, b);
    Res_ada288* root = static_cast<Res_ada288*>(pRoot);
    Releasable_ada288* refs[3];
    void* name = root->GetName_ada288(&refs[0])[0];
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("Resource ");
    s->WriteString_ada210(name);
    s->WriteChars_ada210(" ");
    if (refs[0] != 0) {
        refs[0]->Release_ada288();
    }
    WriteKey(root->GetPart_ada288()->GetKey_ada288(reinterpret_cast<uint32_t*>(refs)));
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
    uint32_t i = 0;
    for (;;) {
        if (i >= (*stack->back())->ResourceCount_ada288()) {
            break;
        }
        Res_ada288* dep = (*stack->back())->GetResource_ada288(i);
        void* depName = dep->GetName_ada288(&refs[0])[0];
        s = static_cast<OutStream_ada210*>(Slot28_ada288());
        s->WriteChars_ada210("   Dep. Resource #");
        s->WriteUint32_ada210(i);
        s->WriteChars_ada210(" ");
        s->WriteString_ada210(depName);
        s->WriteChars_ada210(" ");
        if (refs[0] != 0) {
            refs[0]->Release_ada288();
        }
        uint32_t keyBuffer[3];
        WriteKey(dep->GetPart_ada288()->GetKey_ada288(keyBuffer));
        static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
        ++i;
    }
    i = 0;
    for (;;) {
        if (i >= (*stack->back())->ReferentCount_ada288()) {
            break;
        }
        Serializable_ada288* object = (*stack->back())->GetReferent_ada288(i);
        void* typeName = reinterpret_cast<void* const*>(object->GetTypeInfo_ada288(&refs[0]))[0];
        s = static_cast<OutStream_ada210*>(Slot28_ada288());
        s->WriteChars_ada210("   Object #");
        s->WriteUint32_ada210(i);
        s->WriteChars_ada210(" ");
        s->WriteString_ada210(typeName);
        s->WriteChars_ada210("\n");
        if (refs[0] != 0) {
            refs[0]->Release_ada288();
        }
        ++i;
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
    i = 0;
    for (;;) {
        if (i >= (*stack->back())->ReferentCount_ada288()) {
            break;
        }
        Serializable_ada288* object = (*stack->back())->GetReferent_ada288(i);
        void* typeName = reinterpret_cast<void* const*>(object->GetTypeInfo_ada288(&refs[0]))[0];
        s = static_cast<OutStream_ada210*>(Slot28_ada288());
        s->WriteChars_ada210("   Object #");
        s->WriteUint32_ada210(i);
        s->WriteChars_ada210(" ");
        s->WriteString_ada210(typeName);
        s->WriteChars_ada210("\n");
        if (refs[0] != 0) {
            refs[0]->Release_ada288();
        }
        static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("   {\n");
        object->Write_ada288(this);
        static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("   }\n\n");
        ++i;
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
    static_cast<OutStream_ada210*>(Slot28_ada288())->Flush_ada210();
    i = 0;
    for (;;) {
        if (i >= (*stack->back())->ResourceCount_ada288()) {
            break;
        }
        (*stack->back())->GetResource_ada288(i)->Finish_ada288();
        ++i;
    }
    stack->PopBack_ada288();
    if (surveyor != 0) {
        surveyor->Release_ada340();
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00982f2b score 149
void cGZPersistASCIIWriter::WriteObjectRef_4(const char* name, void* pObject)
{
    Serializable_ada288* object = static_cast<Serializable_ada288*>(pObject);
    OutStream_ada210* s = static_cast<OutStream_ada210*>(Slot28_ada288());
    s->WriteChars_ada210("      cIGZPersistSerializableReferent* ");
    s->WriteChars_ada210(name);
    s->WriteChars_ada210(" = ");
    if (object == 0) {
        static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("0");
    } else {
        Res_ada288* resource = static_cast<Res_ada288*>(object->Resource_ada288());
        SurveyorStack_ada288* stack = reinterpret_cast<SurveyorStack_ada288*>(reinterpret_cast<char*>(this) + 8);
        Releasable_ada288* refs[3];
        if ((*stack->back())->Resource_ada288() == resource) {
            SurveyorWriter_ada288* surveyor = *stack->back();
            void* typeName = reinterpret_cast<void* const*>(object->GetTypeInfo_ada288(&refs[0]))[0];
            s = static_cast<OutStream_ada210*>(Slot28_ada288());
            s->WriteChars_ada210("Object #");
            s->WriteUint32_ada210(surveyor->IdOfObject_ada288(object));
            s->WriteChars_ada210(" ");
            s->WriteString_ada210(typeName);
            if (refs[0] != 0) {
                refs[0]->Release_ada288();
            }
            static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210(" GZCLSID: ");
            WriteUint32InHex(object->GetTypeInfo_ada288(&refs[0])[1]);
            if (refs[0] != 0) {
                refs[0]->Release_ada288();
            }
        } else {
            SurveyorWriter_ada288* surveyor = *stack->back();
            void* typeName = reinterpret_cast<void* const*>(object->GetTypeInfo_ada288(&refs[0]))[0];
            s = static_cast<OutStream_ada210*>(Slot28_ada288());
            s->WriteChars_ada210("Object ID ");
            s->WriteUint32_ada210(resource->IdOfObject_ada288(object));
            s->WriteChars_ada210(" ");
            s->WriteString_ada210(typeName);
            s->WriteChars_ada210(" in dep. resource #");
            s->WriteUint32_ada210(surveyor->IdOfResource_ada288(resource));
            s->WriteChars_ada210(" ");
            if (refs[0] != 0) {
                refs[0]->Release_ada288();
            }
            WriteKey(resource->GetOwnerPart_ada288()->GetKey_ada288(reinterpret_cast<uint32_t*>(refs)));
        }
    }
    static_cast<OutStream_ada210*>(Slot28_ada288())->WriteChars_ada210("\n");
}
#endif

// ---- Agent 2: the deque / vector internals the reader and writer stack on (std containers of the original) ----

struct Iter_ada340 {
    void Fn0098294bDraft_ada340();
    void Fn00981ab6Draft_ada340();
    char* cur;
    char* first;
    char* last;
    char** node;
};

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);
// STUB: 0x0090cf63
void Fn0090cf63(void* p);
// STUB: 0x00407a50
void* Fn00407a50(const void* first, const void* last, void* dest);
// STUB: 0x00413d00
void* Fn00413d00(const void* first, const void* last, void* dest);

struct Releasable2_ada340 {
    virtual void Pad0_ada340();
    virtual void Pad1_ada340();
    virtual void Release_ada340();
};

struct Str_ada340 {
    // STUB: 0x0093de49
    void Destroy_ada340();
};

struct Ptr_ada340 {
    Ptr_ada340* Fn00981d78_ada340(const Ptr_ada340* pSource);
    Releasable2_ada340* mp;
    // STUB: 0x00966956
    void Copy_ada340(const void* pSource);
    // STUB: 0x0093ab29
    void* Delete_ada340(uint32_t flags);
};

struct Map_ada340 {
    // STUB: 0x009db998
    char** Allocate_ada340(uint32_t count);
};

struct Info_ada340 {
    void Info_Destroy_Draft_ada340();
    char mPad[0xc];
    Str_ada340 mA;
    Releasable2_ada340* mpObj;
    Str_ada340 mB;
};

struct Pair_ada340 {
    Pair_ada340* Fn009831c8Draft_ada340(const void* pSource);
    Pair_ada340* Fn0098319bDraft_ada340(Pair_ada340* pSource);
    // STUB: 0x004f20c0
    void Fn004f20c0(const void* p);
    // STUB: 0x004e4bb0
    void Fn004e4bb0(const void* p);
};

struct Vec_ada340 {
    Vec_ada340* Fn00982b59Draft_ada340(Vec_ada340* pSource);
    char** begin;
    char** end;
    char** cap;
    // STUB: 0x00982b59
    Vec_ada340* Fn00982b59(Vec_ada340* pSource);
};

struct RDeque_ada340;
// STUB: 0x00982c25
void Fn00982c25_ada340(RDeque_ada340* pDeque, uint32_t n, bool atFront);
// STUB: 0x00982a8e
void Fn00982a8e_ada340(RDeque_ada340* pDeque, uint32_t n);
// STUB: 0x0098296c
void Fn0098296c_ada340(RDeque_ada340* pDeque, char** first, char** last);

struct RDeque_ada340 {
    RDeque_ada340* Fn00983d46Draft_ada340();
    void Fn00982bd7Draft_ada340();
    char* Fn00982bb6Draft_ada340();
    char* Fn00892041Draft_ada340();
    void Fn00982d6fDraft_ada340(uint32_t n);
    void Fn00982d95Draft_ada340(uint32_t n);
    void Fn00983105Draft_ada340();
    void Fn00983a13Draft_ada340();
    RDeque_ada340* Fn00982bf4Draft_ada340(uint32_t n, const void* /*alloc*/);
    void Fn00983972Draft_ada340();
    void Fn009832adDraft_ada340(const void* pItem);
    void Fn00983940Draft_ada340(const void* pItem);
    void Fn00982b23Draft_ada340();
    void Fn00983349Draft_ada340(Pair_ada340* pItem);
    void Fn00983133Draft_ada340(Ptr_ada340 item);
    Iter_ada340 start;
    Iter_ada340 finish;
    char** map;
    uint32_t mapSize;

    // STUB: 0x009831f0
    void DestroyInfo_ada340();
    // STUB: 0x00982d6f
    void ReserveBack_ada340(uint32_t n);
    // STUB: 0x00983349
    void PushBackAux_ada340(void* pItem);
    // STUB: 0x00983972
    void PopBackAux_ada340();
    void PopBack_ada340();
};


// STUB: 0x00982bf4
RDeque_ada340* Fn00982bf4_ada340(RDeque_ada340* pThis, uint32_t n, const void* pAlloc);
// STUB: 0x00982b93
void Fn00982b93_ada340(Iter_ada340 first, Iter_ada340 last, const void* pAlloc);
// STUB: 0x009833ab
void Fn009833ab_ada340(Iter_ada340 first, Iter_ada340 last, const void* pAlloc);
// STUB: 0x00982d19
void Fn00982d19_ada340(Iter_ada340 first, Iter_ada340 last);
// STUB: 0x009839a3
void Fn009839a3_ada340(Iter_ada340 first, Iter_ada340 last);
// STUB: 0x00982d46
void Fn00982d46_ada340(Iter_ada340 first, Iter_ada340 last);
// STUB: 0x009839ea
void Fn009839ea_ada340(Iter_ada340 first, Iter_ada340 last);
// STUB: 0x00891f0f
void Fn00891f0f_ada340(RDeque_ada340* pThis);
// STUB: 0x00973c0e
void Fn00973c0e_ada340(RDeque_ada340* pThis, uint32_t n, bool atFront);
// STUB: 0x0098294b
void Fn0098294b_ada340(Iter_ada340* pIter);
// STUB: 0x009730a9
void Fn009730a9_ada340(Iter_ada340* pIter);
// STUB: 0x00981ab6
void Fn00981ab6_ada340(Iter_ada340* pIter);
// STUB: 0x00982b59
void Fn00982b59_ada340(Vec_ada340* pDest, Vec_ada340* pSource);

// FUNCTION: 0x009839d0
void RDeque_ada340::PopBack_ada340()
{
    if (this->finish.cur != this->finish.first) {
        this->finish.cur -= 0x1c;
        reinterpret_cast<RDeque_ada340*>(this->finish.cur)->DestroyInfo_ada340();
    } else {
        this->PopBackAux_ada340();
    }
}

// FUNCTION: 0x00981d78
Ptr_ada340* Ptr_ada340::Fn00981d78_ada340(const Ptr_ada340* pSource)
{
    this->Copy_ada340(pSource);
    reinterpret_cast<uint32_t*>(this)[1] = reinterpret_cast<const uint32_t*>(pSource)[1];
    reinterpret_cast<uint32_t*>(this)[2] = reinterpret_cast<const uint32_t*>(pSource)[2];
    return this;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00983d46 score ?
RDeque_ada340* RDeque_ada340::Fn00983d46Draft_ada340()
{
    char alloc[4];
    Fn00982bf4_ada340(this, 0, alloc);
    return this;
}


// CLOSE: 0x00982bd7 score ?
void RDeque_ada340::Fn00982bd7Draft_ada340()
{
    if (this->finish.cur != this->finish.first) {
        this->finish.cur -= 4;
        reinterpret_cast<Ptr_ada340*>(this->finish.cur)->Delete_ada340(0);
    } else {
        // 0x982b23: free the last node, step back one
        Fn0090cf63(this->finish.first);
        this->finish.node -= 1;
        this->finish.first = *this->finish.node;
        this->finish.last = this->finish.first + 0x80;
        this->finish.cur = this->finish.last - 4;
        reinterpret_cast<Ptr_ada340*>(this->finish.cur)->Delete_ada340(0);
    }
}

// CLOSE: 0x0098296c score ?
void Fn0098296cDraft_ada340(char** first, char** last)
{
    for (; first < last; ++first) {
        *first = static_cast<char*>(Fn0090cf54(0x70));
    }
}

// CLOSE: 0x009831f0 score ?
void Info_ada340::Info_Destroy_Draft_ada340()
{
    if (this->mpObj != 0) {
        this->mpObj->Release_ada340();
    }
    this->mA.Destroy_ada340();
    reinterpret_cast<Str_ada340*>(this)->Destroy_ada340();
}


// CLOSE: 0x0098294b score ?
void Iter_ada340::Fn0098294bDraft_ada340()
{
    if (this->cur == this->first) {
        --this->node;
        this->first = *this->node;
        this->last = this->first + 0x70;
        this->cur = this->last;
    }
    this->cur -= 0x1c;
}

// CLOSE: 0x00982bb6 score ?
char* RDeque_ada340::Fn00982bb6Draft_ada340()
{
    Iter_ada340 it = this->finish;
    Fn0098294b_ada340(&it);
    return it.cur;
}

// CLOSE: 0x00892041 score ?
char* RDeque_ada340::Fn00892041Draft_ada340()
{
    Iter_ada340 it = this->finish;
    Fn009730a9_ada340(&it);
    return it.cur;
}

// CLOSE: 0x009833ab score ?
void Fn009833abDraft_ada340(Iter_ada340 first, Iter_ada340 last, const void* /*alloc*/)
{
    while (first.cur != last.cur) {
        reinterpret_cast<RDeque_ada340*>(first.cur)->DestroyInfo_ada340();
        Fn00981ab6_ada340(&first);
    }
}

// CLOSE: 0x00982b93 score ?
void Fn00982b93Draft_ada340(Iter_ada340 first, Iter_ada340 last, const void* /*alloc*/)
{
    while (first.cur != last.cur) {
        reinterpret_cast<Ptr_ada340*>(first.cur)->Delete_ada340(0);
        // 0x97316e: advance by 4
        first.cur += 4;
    }
}

// CLOSE: 0x00981ab6 score ?
void Iter_ada340::Fn00981ab6Draft_ada340()
{
    this->cur += 0x1c;
    if (this->cur == this->last) {
        ++this->node;
        this->first = *this->node;
        this->last = this->first + 0x70;
        this->cur = this->first;
    }
}

// CLOSE: 0x00982d6f score ?
void RDeque_ada340::Fn00982d6fDraft_ada340(uint32_t n)
{
    if (n + 1 > this->mapSize - static_cast<uint32_t>(this->finish.node - this->map)) {
        Fn00982c25_ada340(this, n, false);
    }
}

// CLOSE: 0x00982d95 score ?
void RDeque_ada340::Fn00982d95Draft_ada340(uint32_t n)
{
    if (n + 1 > this->mapSize - static_cast<uint32_t>(this->finish.node - this->map)) {
        Fn00973c0e_ada340(this, n, false);
    }
}

// CLOSE: 0x009831c8 score ?
Pair_ada340* Pair_ada340::Fn009831c8Draft_ada340(const void* pSource)
{
    uint32_t* w = reinterpret_cast<uint32_t*>(this);
    w[0] = 0;
    w[1] = 0;
    w[2] = 0;
    w[3] = 0;
    w[4] = 0;
    w[5] = 0;
    reinterpret_cast<Pair_ada340*>(w + 6)->Fn004f20c0(pSource);
    return this;
}

// CLOSE: 0x00982d46 score ?
void Fn00982d46Draft_ada340(Iter_ada340 first, Iter_ada340 last)
{
    Fn00982d19_ada340(first, last);
}

// CLOSE: 0x009839ea score ?
void Fn009839eaDraft_ada340(Iter_ada340 first, Iter_ada340 last)
{
    Fn009839a3_ada340(first, last);
}

// CLOSE: 0x00982d19 score ?
void Fn00982d19Draft_ada340(Iter_ada340 first, Iter_ada340 last)
{
    char alloc[1];
    Fn00982b93_ada340(first, last, alloc);
}

// CLOSE: 0x009839a3 score ?
void Fn009839a3Draft_ada340(Iter_ada340 first, Iter_ada340 last)
{
    char alloc[1];
    Fn009833ab_ada340(first, last, alloc);
}

// CLOSE: 0x0098319b score ?
Pair_ada340* Pair_ada340::Fn0098319bDraft_ada340(Pair_ada340* pSource)
{
    char* self = reinterpret_cast<char*>(this);
    char* src = reinterpret_cast<char*>(pSource);
    Fn00982b59_ada340(reinterpret_cast<Vec_ada340*>(self), reinterpret_cast<Vec_ada340*>(src));
    Fn00982b59_ada340(reinterpret_cast<Vec_ada340*>(self + 0xc), reinterpret_cast<Vec_ada340*>(src + 0xc));
    reinterpret_cast<Pair_ada340*>(self + 0x18)->Fn004e4bb0(src + 0x18);
    return this;
}

// CLOSE: 0x00983105 score ?
void RDeque_ada340::Fn00983105Draft_ada340()
{
    Fn00982d46_ada340(this->finish, this->start);
    Fn00891f0f_ada340(this);
}

// CLOSE: 0x00983a13 score ?
void RDeque_ada340::Fn00983a13Draft_ada340()
{
    Fn009839ea_ada340(this->finish, this->start);
    Fn00891f0f_ada340(this);
}

// CLOSE: 0x00982bf4 score ?
RDeque_ada340* RDeque_ada340::Fn00982bf4Draft_ada340(uint32_t n, const void* /*alloc*/)
{
    uint32_t* w = reinterpret_cast<uint32_t*>(this);
    for (int i = 0; i < 10; ++i) {
        w[i] = 0;
    }
    Fn00982a8e_ada340(this, n);
    return this;
}

// CLOSE: 0x00983972 score ?
void RDeque_ada340::Fn00983972Draft_ada340()
{
    if (this->finish.first != 0) {
        Fn0090cf63(this->finish.first);
    }
    --this->finish.node;
    this->finish.first = *this->finish.node;
    this->finish.last = this->finish.first + 0x70;
    this->finish.cur = this->finish.last - 0x1c;
    reinterpret_cast<RDeque_ada340*>(this->finish.cur)->DestroyInfo_ada340();
}

// CLOSE: 0x009832ad score ?
void RDeque_ada340::Fn009832adDraft_ada340(const void* pItem)
{
    if (this->finish.cur != this->finish.last - 4) {
        if (this->finish.cur != 0) {
            reinterpret_cast<Ptr_ada340*>(this->finish.cur)->Copy_ada340(pItem);
        }
        this->finish.cur += 4;
    } else {
        reinterpret_cast<RDeque_ada340*>(this)->PushBackAux_ada340(const_cast<void*>(pItem));
    }
}

// CLOSE: 0x00983940 score ?
void RDeque_ada340::Fn00983940Draft_ada340(const void* pItem)
{
    if (this->finish.cur != this->finish.last - 0x1c) {
        if (this->finish.cur != 0) {
            reinterpret_cast<Pair_ada340*>(this->finish.cur)->Fn0098319bDraft_ada340(reinterpret_cast<Pair_ada340*>(const_cast<void*>(pItem)));
        }
        this->finish.cur += 0x1c;
    } else {
        this->PushBackAux_ada340(const_cast<void*>(pItem));
    }
}

// CLOSE: 0x00982b23 score ?
void RDeque_ada340::Fn00982b23Draft_ada340()
{
    if (this->finish.first != 0) {
        Fn0090cf63(this->finish.first);
    }
    --this->finish.node;
    this->finish.first = *this->finish.node;
    this->finish.last = this->finish.first + 0x80;
    this->finish.cur = this->finish.last - 4;
    reinterpret_cast<Ptr_ada340*>(this->finish.cur)->Delete_ada340(0);
}

// CLOSE: 0x00982b59 score ?
Vec_ada340* Vec_ada340::Fn00982b59Draft_ada340(Vec_ada340* pSource)
{
    this->end = reinterpret_cast<char**>(Fn00407a50(pSource->begin, pSource->end, this->begin));
    return this;
}

// CLOSE: 0x00983349 score ?
void RDeque_ada340::Fn00983349Draft_ada340(Pair_ada340* pItem)
{
    char copy[0x1c];
    reinterpret_cast<Pair_ada340*>(copy)->Fn0098319bDraft_ada340(pItem);
    this->ReserveBack_ada340(1);
    this->finish.node[1] = static_cast<char*>(Fn0090cf54(0x70));
    if (this->finish.cur != 0) {
        reinterpret_cast<Pair_ada340*>(this->finish.cur)->Fn0098319bDraft_ada340(reinterpret_cast<Pair_ada340*>(copy));
    }
    ++this->finish.node;
    this->finish.first = *this->finish.node;
    this->finish.last = this->finish.first + 0x70;
    this->finish.cur = this->finish.first;
    reinterpret_cast<RDeque_ada340*>(copy)->DestroyInfo_ada340();
}

// CLOSE: 0x00983133 score ?
void RDeque_ada340::Fn00983133Draft_ada340(Ptr_ada340 item)
{
    Ptr_ada340 key;
    key.Copy_ada340(&item);
    Fn00973c0e_ada340(this, 1, false);
    this->finish.node[1] = static_cast<char*>(Fn0090cf54(0x80));
    if (this->finish.cur != 0) {
        reinterpret_cast<Ptr_ada340*>(this->finish.cur)->Copy_ada340(&key);
    }
    ++this->finish.node;
    this->finish.first = *this->finish.node;
    this->finish.last = this->finish.first + 0x80;
    this->finish.cur = this->finish.first;
    if (key.mp != 0) {
        key.mp->Release_ada340();
    }
}
#endif

// ---- Agent 2: Slot26 and ReadRoot (drafts; they call the container internals above through STUBs) ----

// A counted pointer slot (cRZAutoRefCount) as the original passes it around.
struct Counted_ada340 {
    Unknown_ada340* mp;
    uint32_t mA;
    uint32_t mB;
    // STUB: 0x0094909a
    void Assign_ada340(void* p);
    // STUB: 0x00981d78
    Counted_ada340* Copy_ada340(Counted_ada340* pSource);
    // STUB: 0x0096e773
    void Construct_ada340(void* p);
};

struct Key_ada340 {
    uint32_t mType;
    uint32_t mGroup;
    uint32_t mInstance;
};

struct KeyHolder_ada340 {
    virtual void Pad0_ada340();
    virtual void Pad1_ada340();
    virtual void Pad2_ada340();
    virtual void Pad3_ada340();
    virtual void Pad4_ada340();
    virtual void Pad5_ada340();
    virtual void Pad6_ada340();
    virtual void Pad7_ada340();
    virtual void Pad8_ada340();
    virtual void Pad9_ada340();
    virtual void Pad10_ada340();
    virtual void Pad11_ada340();
    virtual void* GetKey_ada340(Key_ada340* pOut);
};

struct ResourceObject_ada340 {
    virtual void Pad0_ada340();
    virtual void Pad1_ada340();
    virtual void Pad2_ada340();
    virtual void Pad3_ada340();
    virtual void Pad4_ada340();
    virtual void Pad5_ada340();
    virtual void Pad6_ada340();
    virtual void Pad7_ada340();
    virtual KeyHolder_ada340* Owner_ada340();
};

struct ResourceManager_ada340 {
    virtual void Pad0_ada340();
    virtual void Pad1_ada340();
    virtual void Pad2_ada340();
    virtual bool GetResource_ada340(Key_ada340* pKey, uint32_t iid, void** ppOut, uint32_t a, uint32_t b);
    virtual void Pad4_ada340();
    virtual void Pad5_ada340();
    virtual void Pad6_ada340();
    virtual void Pad7_ada340();
    virtual void Register_ada340(void* pKey);
    virtual void Pad9_ada340();
    virtual bool Exists_ada340(void* pKey);
};

struct ManagerPtr_ada340 {
    ResourceManager_ada340* mp;
    // STUB: 0x004496c0
    void Construct_ada340();
    // STUB: 0x004495c0
    void Destroy_ada340();
};

struct InfoVec_ada340 {
    // STUB: 0x00981855
    void PushResource_ada340(Counted_ada340* pItem);
    // STUB: 0x0098181d
    void PushReferent_ada340(Counted_ada340* pItem);
};

struct ReaderStack2_ada340 {
    // STUB: 0x00983940
    void PushBack_ada340(void* pInfo);
    // STUB: 0x009839d0
    void PopBack_ada340();
    // STUB: 0x00982bb6
    char* back();
};

struct InfoCtor_ada340 {
    // STUB: 0x009831c8
    InfoCtor_ada340* Construct_ada340(void* pStream);
    // STUB: 0x009831f0
    void Destroy_ada340();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0098320f score ?
uint32_t cGZPersistBinaryReader::Slot26_ada340(uint32_t arg)
{
    Counted_ada340 local;
    local.mp = 0;
    cRZString* pText = new cRZString();
    local.Assign_ada340(pText);
    static_cast<InStream_ada340*>(InputStream())->ReadString_ada340(local.mp);
    uint32_t a;
    uint32_t b;
    static_cast<InStream_ada340*>(InputStream())->ReadUint32_ada340(&a);
    static_cast<InStream_ada340*>(InputStream())->ReadUint32_ada340(&b);
    Counted_ada340* result = OB_PTR(Counted_ada340, arg);
    result->Copy_ada340(&local);
    if (local.mp != 0) {
        local.mp->Release_ada340();
    }
    return OB_ADDR(result);
}

// CLOSE: 0x00983a4f score ?
void cGZPersistBinaryReader::ReadRoot(uint32_t resArg, uint32_t streamArg)
{
    ResourceObject_ada340* resource = OB_PTR(ResourceObject_ada340, resArg);
    InfoCtor_ada340 info;
    ReaderStack2_ada340* stack = reinterpret_cast<ReaderStack2_ada340*>(reinterpret_cast<char*>(this) + 8);
    stack->PushBack_ada340(info.Construct_ada340(OB_PTR(void, streamArg)));
    info.Destroy_ada340();
    ManagerPtr_ada340 manager;
    manager.Construct_ada340();
    Key_ada340 key;
    bool existed = manager.mp->Exists_ada340(resource->Owner_ada340()->GetKey_ada340(&key));
    if (!existed) {
        manager.mp->Register_ada340(resource->Owner_ada340()->GetKey_ada340(&key));
    }
    uint32_t count;
    static_cast<InStream_ada340*>(InputStream())->ReadUint32_ada340(&count);
    for (uint32_t i = 0; i < count; ++i) {
        Key_ada340 dep;
        dep.mType = 0;
        dep.mGroup = 0;
        dep.mInstance = 0;
        InStream_ada340* in = static_cast<InStream_ada340*>(InputStream());
        in->ReadUint32_ada340(&dep.mGroup);
        in->ReadUint32_ada340(&dep.mInstance);
        in->ReadUint32_ada340(&dep.mType);
        Counted_ada340 held;
        held.mp = 0;
        if (dep.mType != 0) {
            if (!manager.mp->GetResource_ada340(&dep, 0x9b11bf70, reinterpret_cast<void**>(&held.mp), 0, 0)) {
                cRZString text;
                text.Sprintf("Cannot load dependent resource with group ID = %xu, instance ID = %xu, type = %xu\n", dep.mGroup, dep.mInstance, dep.mType);
            }
        } else {
            cRZString text;
            text.Sprintf("Null dependent resource with group ID = %xu, instance ID = %xu, type = %xu\n", dep.mGroup, dep.mInstance, dep.mType);
        }
        reinterpret_cast<InfoVec_ada340*>(stack->back())->PushResource_ada340(&held);
        if (held.mp != 0) {
            held.mp->Release_ada340();
        }
    }
    uint32_t refCount;
    static_cast<InStream_ada340*>(InputStream())->ReadUint32_ada340(&refCount);
    Counted_ada340 first;
    first.Construct_ada340(resource);
    reinterpret_cast<InfoVec_ada340*>(stack->back() + 0xc)->PushReferent_ada340(&first);
    if (first.mp != 0) {
        first.mp->Release_ada340();
    }
    uint32_t id;
    static_cast<InStream_ada340*>(InputStream())->ReadUint32_ada340(&id);
    for (uint32_t j = 1; j < refCount; ++j) {
        Counted_ada340 ref;
        static_cast<InStream_ada340*>(InputStream())->ReadUint32_ada340(&id);
        ref.mp = 0;
        if (id != 0) {
            Fn0090ddf1()->Create_ada340(id, 0xbb11a53e, reinterpret_cast<void**>(&ref.mp));
            reinterpret_cast<InfoVec_ada340*>(stack->back() + 0xc)->PushReferent_ada340(&ref);
        } else {
            reinterpret_cast<InfoVec_ada340*>(stack->back() + 0xc)->PushReferent_ada340(&ref);
        }
        if (ref.mp != 0) {
            ref.mp->Release_ada340();
        }
    }
    for (uint32_t k = 0; k < refCount; ++k) {
        Unknown_ada340* item = reinterpret_cast<Unknown_ada340**>(*reinterpret_cast<char**>(stack->back() + 0xc))[k];
        if (item != 0) {
            item->Read_ada340(this);
        }
    }
    if (!existed) {
        manager.mp->Register_ada340(resource->Owner_ada340()->GetKey_ada340(&key));
    }
    stack->PopBack_ada340();
    manager.Destroy_ada340();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00982a8e score ?
void Fn00982a8eDraft_ada340(RDeque_ada340* pDeque, uint32_t n)
{
    uint32_t nodes = n / 4 + 1;
    uint32_t want = nodes + 2;
    uint32_t minimum = 8;
    pDeque->mapSize = want > minimum ? want : minimum;
    pDeque->map = reinterpret_cast<Map_ada340*>(&pDeque->map)->Allocate_ada340(pDeque->mapSize);
    char** nodeStart = pDeque->map + (pDeque->mapSize - nodes) / 2;
    char** nodeFinish = nodeStart + nodes;
    Fn0098296c_ada340(pDeque, nodeStart, nodeFinish);
    pDeque->start.node = nodeStart;
    pDeque->start.first = *nodeStart;
    pDeque->start.last = pDeque->start.first + 0x70;
    pDeque->finish.node = nodeFinish - 1;
    pDeque->finish.first = *pDeque->finish.node;
    pDeque->finish.last = pDeque->finish.first + 0x70;
    pDeque->finish.cur = pDeque->finish.first + (n % 4) * 0x1c;
    pDeque->start.cur = pDeque->start.first;
}

// CLOSE: 0x00982c25 score ?
void Fn00982c25Draft_ada340(RDeque_ada340* pDeque, uint32_t n, bool atFront)
{
    uint32_t oldNodes = static_cast<uint32_t>(pDeque->finish.node - pDeque->start.node) + 1;
    uint32_t newNodes = oldNodes + n;
    char** newStart;
    if (pDeque->mapSize > 2 * newNodes) {
        newStart = pDeque->map + (pDeque->mapSize - newNodes) / 2 + (atFront ? n : 0);
        if (newStart < pDeque->start.node) {
            Fn00407a50(pDeque->start.node, pDeque->finish.node + 1, newStart);
        } else {
            Fn00413d00(pDeque->start.node, pDeque->finish.node + 1, newStart + oldNodes);
        }
    } else {
        uint32_t newSize = pDeque->mapSize + (pDeque->mapSize > n ? pDeque->mapSize : n) + 2;
        char** newMap = reinterpret_cast<Map_ada340*>(&pDeque->map)->Allocate_ada340(newSize);
        newStart = newMap + (newSize - newNodes) / 2 + (atFront ? n : 0);
        Fn00407a50(pDeque->start.node, pDeque->finish.node + 1, newStart);
        if (pDeque->map != 0) {
            Fn0090cf63(pDeque->map);
        }
        pDeque->map = newMap;
        pDeque->mapSize = newSize;
    }
    pDeque->start.node = newStart;
    pDeque->start.first = *newStart;
    pDeque->start.last = pDeque->start.first + 0x70;
    pDeque->finish.node = newStart + oldNodes - 1;
    pDeque->finish.first = *pDeque->finish.node;
    pDeque->finish.last = pDeque->finish.first + 0x70;
}
#endif
