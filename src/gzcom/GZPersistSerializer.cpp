#include <stddef.h>
#include "classes/cGZPersistBinaryReader.h"
#include "classes/cGZPersistBinaryWriter.h"
#include "classes/cGZPersistASCIIWriter.h"
#include <cstdio>

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
