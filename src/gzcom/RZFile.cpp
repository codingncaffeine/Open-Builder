#include "classes/cRZFile.h"
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "gzcom/cRZString.h"

// The Windows functions this file calls, imported as the original imported them (declared here, as the shared
// header lacks them yet).
#ifdef _MSC_VER
#define RZ_API extern "C" __declspec(dllimport)
#else
#define RZ_API extern "C"
#endif
RZ_API uint32_t OB_STDCALL GetLastError(void);
RZ_API int32_t OB_STDCALL CloseHandle(void* handle);
RZ_API int32_t OB_STDCALL FlushFileBuffers(void* handle);
RZ_API int32_t OB_STDCALL SetEndOfFile(void* handle);
RZ_API int32_t OB_STDCALL WriteFile(void* handle, const void* buffer, uint32_t count, uint32_t* written, void* overlapped);
RZ_API int32_t OB_STDCALL ReadFile(void* handle, void* buffer, uint32_t count, uint32_t* read, void* overlapped);
RZ_API uint32_t OB_STDCALL SetFilePointer(void* handle, int32_t distance, int32_t* high, uint32_t method);
RZ_API uint32_t OB_STDCALL GetFileSize(void* handle, uint32_t* high);
RZ_API void* OB_STDCALL CreateFileA(const char* name, uint32_t access, uint32_t share, void* security, uint32_t creation, uint32_t flags, void* templateFile);
RZ_API uint32_t OB_STDCALL GetFileAttributesA(const char* name);
RZ_API int32_t OB_STDCALL SetFileAttributesA(const char* name, uint32_t attributes);
RZ_API int32_t OB_STDCALL DeleteFileA(const char* name);
RZ_API int32_t OB_STDCALL MoveFileA(const char* from, const char* to);
RZ_API uint32_t OB_STDCALL GetTempPathA(uint32_t size, char* buffer);
RZ_API int32_t OB_STDCALL GetVolumeInformationA(const char* root, char* name, uint32_t nameSize, uint32_t* serial, uint32_t* maxLength, uint32_t* flags, char* system, uint32_t systemSize);
RZ_API void* OB_STDCALL FindFirstFileA(const char* name, void* data);
RZ_API int32_t OB_STDCALL FindClose(void* handle);
RZ_API int32_t OB_STDCALL CopyFileA(const char* from, const char* to, int32_t failIfExists);

// The byte vector at 0x54 and at 0x6c (begin, end, end of storage); only the resize helper is used here.
struct Bytes_abfed0 {
    uint8_t* mpBegin;
    uint8_t* mpEnd;
    uint8_t* mpCap;
    // STUB: 0x00478aa0
    void Fn00478aa0(uint32_t count);
};

// The path tests and the string helpers of this file.
bool Fn00918080(const char* path);

// The STL allocator's release function (the standard library of the original).
namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

// STUB: 0x00919e96
bool Fn00919e96(const cRZString* path);

// STUB: 0x0091a225
bool Fn0091a225(const cIGZString* from, const void* to);

// STUB: 0x0091a2f9
bool Fn0091a2f9(const cIGZString& from, const cIGZString& to, bool overwrite);

#ifdef OB_DRAFTS
// CLOSE: 0x009182ff score 8
bool cRZFile::QueryInterface(uint32_t riid, uint32_t ppv)
{
    bool ok;
    if (riid == 0xe0203645 || riid == 1) {
        *OB_PTR(cRZFile*, ppv) = this;
        AddRef();
        ok = true;
    } else {
        ok = false;
    }
    return ok;
}
#endif

// FUNCTION: 0x00918324
uint32_t cRZFile::AddRef()
{
    return ++mnRefCount;
}

// FUNCTION: 0x0091832b
uint32_t cRZFile::Release()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    delete this;
    return 0;
}

// FUNCTION: 0x00918345
uint32_t cRZFile::Position()
{
    uint32_t position = 0xffffffff;
    if (mbOpen) {
        position = mnPosition;
    }
    return position;
}

// FUNCTION: 0x00918352
void cRZFile::SeekToBegin()
{
    Seek(0, 0);
}

// FUNCTION: 0x0091835c
void cRZFile::SeekToEnd()
{
    Seek(0, 2);
}

// FUNCTION: 0x00918366
void cRZFile::SeekToRelativePosition(uint32_t offset)
{
    Seek(offset, 1);
}

// FUNCTION: 0x00918374
uint32_t cRZFile::SeekToPosition(uint32_t position)
{
    return Seek(position, 0);
}

// FUNCTION: 0x00918382
bool cRZFile::Read(void* buffer, uint32_t count)
{
    uint32_t done = count;
    if (ReadWithCount(buffer, &done)) {
        return count == done;
    }
    return false;
}

// FUNCTION: 0x009183ad
bool cRZFile::Write(const void* buffer, uint32_t count)
{
    uint32_t done = count;
    if (WriteWithCount(buffer, &done)) {
        return count == done;
    }
    return false;
}

// FUNCTION: 0x009183d8
bool cRZFile::GetOpenModes(void* access, void* creation, void* share)
{
    if (mbOpen) {
        *static_cast<uint32_t*>(access) = mnAccess;
        *static_cast<uint32_t*>(creation) = mnCreation;
        *static_cast<uint32_t*>(share) = mnShare;
        return true;
    }
    return false;
}

// FUNCTION: 0x00918402
void cRZFile::GetBuffering(void* readSize, void* writeSize)
{
    *static_cast<uint32_t*>(readSize) = mnReadBufferSize;
    *static_cast<uint32_t*>(writeSize) = mnWriteBufferSize;
}

// FUNCTION: 0x00918577
void cRZFile::SetErrorFromOS()
{
    uint32_t error = GetLastError();
    switch (error) {
    case 5:
        mnLastError = 0x20000002;
        break;
    case 0xb7:
        mnLastError = 0x20000001;
        break;
    default:
        mnLastError = error;
        break;
    }
}

// FUNCTION: 0x009185a3
void* Fn009185a3(void* destination, const void* source, uint32_t count)
{
    if (count == 0) {
        return destination;
    }
    return memcpy(destination, source, count * 2);
}

// FUNCTION: 0x009186e7
bool Fn009186e7(const cRZString* path)
{
    return Fn00918080(path->c_str());
}

// FUNCTION: 0x009186f5
uint32_t cRZFile::Length()
{
    uint32_t length = 0xffffffff;
    if (mbOpen) {
        length = GetFileSize(mhFile, 0);
        if (length == 0xffffffff) {
            SetErrorFromOS();
        } else if (mnWriteFill != 0) {
            uint32_t position = mnPosition;
            if (length < position) {
                length = position;
            }
        }
    }
    return length;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009187b1 score 11
bool cRZFile::FlushWriteBuffer()
{
    bool ok = true;
    uint32_t written = mnWriteFill;
    if (written != 0) {
        uint32_t position;
        if (WriteFile(mhFile, mpWriteBegin, written, &written, 0)) {
            mnFilePosition += written;
            position = mnFilePosition;
        } else {
            position = SetFilePointer(mhFile, 0, 0, 1);
            mnFilePosition = position;
            ok = false;
        }
        mnWriteFileOffset = position;
        mnWriteFill = 0;
    }
    return ok;
}
#endif

// FUNCTION: 0x009188a5
bool cRZFile::Close()
{
    if (mbOpen) {
        FlushWriteBuffer();
        mnReadWindowOffset = 0;
        mnReadWindowCount = 0;
        mnWriteFileOffset = 0;
        mnWriteFill = 0;
        if (!CloseHandle(mhFile)) {
            SetErrorFromOS();
        }
        mhFile = reinterpret_cast<void*>(-1);
        mnAccess = 0;
        mnCreation = 0;
        mnShare = 0;
        mnFilePosition = 0;
        mbOpen = false;
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009188f1 score 12
bool cRZFile::SetLength(uint32_t length)
{
    bool ok = false;
    if (mbOpen) {
        mnReadWindowOffset = 0;
        mnReadWindowCount = 0;
        FlushWriteBuffer();
        if (SetFilePointer(mhFile, length, 0, 0) != 0xffffffff && SetEndOfFile(mhFile)) {
            ok = true;
        } else {
            SetErrorFromOS();
            ok = false;
        }
        mnPosition = mnFilePosition = SetFilePointer(mhFile, 0, 0, 1);
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009189e2 score 2
bool cRZFile::Flush()
{
    if (mbOpen) {
        bool pending = mnWriteFill > 0;
        FlushWriteBuffer();
        uint32_t result = 1;
        if (pending) {
            result = FlushFileBuffers(mhFile);
            if (result == 0) {
                SetErrorFromOS();
            }
        }
        return result != 0;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0091895a score 48
uint32_t cRZFile::Seek(uint32_t offset, uint32_t origin)
{
    if (mbOpen) {
        uint32_t method;
        switch (origin) {
        case 0:
            method = 0;
            break;
        case 1: {
            uint32_t position = mnPosition;
            method = 1;
            if (mnFilePosition != position) {
                method = 0;
                offset += position;
            }
            break;
        }
        case 2:
            method = 2;
            break;
        default:
            return Position();
        }
        FlushWriteBuffer();
        uint32_t result = SetFilePointer(mhFile, offset, 0, method);
        if (result == 0xffffffff) {
            result = SetFilePointer(mhFile, 0, 0, 1);
            mnFilePosition = result;
            mnPosition = result;
            SetErrorFromOS();
            return 0xffffffff;
        }
        mnFilePosition = result;
        mnPosition = result;
        return result;
    }
    return 0xffffffff;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00918b96 score 6
cRZFile::cRZFile()
    : mPath(), mbOpen(false), mhFile(reinterpret_cast<void*>(-1)), mnAccess(0), mnCreation(0), mnShare(0),
      mnRefCount(0), mnLastError(0x20000000), mAltPath(), mnPosition(0), mnFilePosition(0), mnReadBufferSize(0x200),
      mpReadBegin(0), mpReadEnd(0), mpReadCap(0), mnReadWindowOffset(0), mnReadWindowCount(0),
      mnWriteBufferSize(0x200), mpWriteBegin(0), mpWriteEnd(0), mpWriteCap(0), mnWriteFileOffset(0), mnWriteFill(0)
{
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00918c00 score 6
cRZFile::cRZFile(const void* path)
    : mPath(*static_cast<const cIGZString*>(path)), mbOpen(false), mhFile(reinterpret_cast<void*>(-1)), mnAccess(0),
      mnCreation(0), mnShare(0), mnRefCount(0), mnLastError(0x20000000), mAltPath(), mnPosition(0),
      mnFilePosition(0), mnReadBufferSize(0x200), mpReadBegin(0), mpReadEnd(0), mpReadCap(0), mnReadWindowOffset(0),
      mnReadWindowCount(0), mnWriteBufferSize(0x200), mpWriteBegin(0), mpWriteEnd(0), mpWriteCap(0),
      mnWriteFileOffset(0), mnWriteFill(0)
{
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00919a60 score 4
cRZFile::cRZFile(const char* path)
    : mPath(), mbOpen(false), mhFile(reinterpret_cast<void*>(-1)), mnAccess(0), mnCreation(0), mnShare(0),
      mnRefCount(0), mnLastError(0x20000000), mAltPath(), mnPosition(0), mnFilePosition(0), mnReadBufferSize(0x200),
      mpReadBegin(0), mpReadEnd(0), mpReadCap(0), mnReadWindowOffset(0), mnReadWindowCount(0),
      mnWriteBufferSize(0x200), mpWriteBegin(0), mpWriteEnd(0), mpWriteCap(0), mnWriteFileOffset(0), mnWriteFill(0)
{
    if (path) {
        mPath = cRZString(path);
    }
}
#endif

// FUNCTION: 0x00918c70
cRZFile::~cRZFile()
{
    if (mbOpen) {
        Close();
    }
    if (mpWriteBegin) {
        _STL::__stl_delete(mpWriteBegin);
    }
    if (mpReadBegin) {
        _STL::__stl_delete(mpReadBegin);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00918f67 score 2
bool cRZFile::FillReadBuffer()
{
    bool ok = false;
    Bytes_abfed0* buffer = reinterpret_cast<Bytes_abfed0*>(&mpReadBegin);
    if (buffer->mpBegin == buffer->mpEnd) {
        buffer->Fn00478aa0(mnReadBufferSize);
    }
    uint32_t count = mnReadBufferSize;
    uint8_t* data = buffer->mpBegin;
    uint32_t position;
    if (ReadFile(mhFile, data, count, &count, 0)) {
        position = mnFilePosition;
        mnReadWindowOffset = position;
        mnReadWindowCount = count;
        position += count;
        ok = true;
    } else {
        position = SetFilePointer(mhFile, 0, 0, 1);
        mnReadWindowOffset = 0;
        mnReadWindowCount = 0;
    }
    mnFilePosition = position;
    return ok;
}
#endif

// FUNCTION: 0x00918fd8
bool cRZFile::FillWriteBuffer(const void* data, int32_t count)
{
    bool ok = true;
    if (count > 0) {
        Bytes_abfed0* buffer = reinterpret_cast<Bytes_abfed0*>(&mpWriteBegin);
        if (buffer->mpBegin == buffer->mpEnd) {
            buffer->Fn00478aa0(mnWriteBufferSize);
        }
        uint32_t fill = mnWriteFill;
        if (fill == 0) {
            mnWriteFileOffset = mnFilePosition;
        }
        if (static_cast<int32_t>(fill) + count <= static_cast<int32_t>(mnWriteBufferSize)) {
            memcpy(buffer->mpBegin + fill, data, count);
            mnWriteFill += count;
        } else {
            do {
                if (!ok) {
                    break;
                }
                int32_t room = mnWriteBufferSize - mnWriteFill;
                if (room >= count) {
                    room = count;
                }
                if (room != 0) {
                    memcpy(mpWriteBegin + mnWriteFill, data, room);
                    mnWriteFill += room;
                    data = static_cast<const uint8_t*>(data) + room;
                    count -= room;
                }
                if (mnWriteFill == mnWriteBufferSize) {
                    ok = FlushWriteBuffer();
                }
            } while (count != 0);
        }
    }
    return ok;
}

// FUNCTION: 0x00919081
bool cRZFile::SetBuffering(uint32_t readSize, uint32_t writeSize)
{
    if (readSize == 0xffffffff) {
        readSize = 0x200;
    }
    readSize &= 0xfffffffe;
    if (readSize > 0 && readSize < 4) {
        readSize = 4;
    }
    if (readSize > 0x1f4000) {
        readSize = 0x1f4000;
    }
    if (readSize < mnReadBufferSize) {
        mnReadWindowOffset = 0;
        mnReadWindowCount = 0;
    }
    Bytes_abfed0* readBuffer = reinterpret_cast<Bytes_abfed0*>(&mpReadBegin);
    mnReadBufferSize = readSize;
    if (readBuffer->mpBegin != readBuffer->mpEnd) {
        readBuffer->Fn00478aa0(readSize);
    }
    if (writeSize == 0xffffffff) {
        writeSize = 0x200;
    }
    writeSize &= 0xfffffffe;
    if (writeSize > 0 && writeSize < 4) {
        writeSize = 4;
    }
    if (writeSize > 0x1f4000) {
        writeSize = 0x1f4000;
    }
    if (writeSize < mnWriteBufferSize) {
        FlushWriteBuffer();
    }
    Bytes_abfed0* writeBuffer = reinterpret_cast<Bytes_abfed0*>(&mpWriteBegin);
    mnWriteBufferSize = writeSize;
    if (writeBuffer->mpBegin != writeBuffer->mpEnd) {
        writeBuffer->Fn00478aa0(writeSize);
    }
    return true;
}

// FUNCTION: 0x009193e3
bool cRZFile::WriteWithCount(const void* buffer, void* count)
{
    if (mbOpen) {
        uint32_t* pCount = static_cast<uint32_t*>(count);
        if (mnReadWindowCount != 0) {
            uint32_t position = mnPosition;
            mnReadWindowOffset = 0;
            mnReadWindowCount = 0;
            if (position != mnFilePosition) {
                SeekToPosition(position);
            }
        }
        if (mnWriteBufferSize != 0) {
            bool ok = FillWriteBuffer(buffer, *pCount);
            mnPosition += *pCount;
            return ok;
        }
        int32_t result = WriteFile(mhFile, buffer, *pCount, pCount, 0);
        if (result != 0) {
            mnFilePosition += *pCount;
        } else {
            mnFilePosition = SetFilePointer(mhFile, 0, 0, 1);
            SetErrorFromOS();
        }
        mnPosition = mnFilePosition;
        return result != 0;
    }
    return false;
}

// FUNCTION: 0x00919474
void cRZFile::SetPath_2(void* path)
{
    cIGZString* source = static_cast<cIGZString*>(path);
    uint32_t length = source->Strlen();
    const char* data = source->Data();
    mPath.assign(data, data + length);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00919d88 score 2
void cRZFile::SetPath(const char* path)
{
    if (path) {
        mPath = cRZString(path);
    }
}
#endif

// FUNCTION: 0x0091ab92
bool cRZFile::Exists()
{
    bool exists = Fn00919e96(&mPath);
    if (!exists) {
        SetErrorFromOS();
    }
    return exists;
}

// FUNCTION: 0x0091ab4e
bool cRZFile::Rename(void* newPath)
{
    if (IsOpen()) {
        Close();
    }
    cIGZString* path = &mPath;
    bool renamed = Fn0091a225(path, newPath);
    if (!renamed) {
        SetErrorFromOS();
    }
    path->operator=(*static_cast<cIGZString*>(newPath));
    return renamed;
}

// FUNCTION: 0x0091abb2
bool cRZFile::Copy_2(void* source, bool overwrite)
{
    bool copied = Fn0091a2f9(*static_cast<cIGZString*>(source), mPath, overwrite);
    if (!copied) {
        SetErrorFromOS();
    }
    return copied;
}

// FUNCTION: 0x0091abde
bool cRZFile::Copy(void* source, bool overwrite)
{
    cRZFile* file = static_cast<cRZFile*>(source);
    bool copied = Fn0091a2f9(cRZString(*static_cast<cIGZString*>(file->GetPath())), mPath, overwrite);
    if (!copied) {
        SetErrorFromOS();
    }
    return copied;
}

// ---- translation unit helpers (path functions) ----

// STUB: 0x00911466
uint32_t Fn00911466(const cIGZString* source, int32_t encoding, cIGZString* dest);

// STUB: 0x0091152f
uint32_t Fn0091152f(const cIGZString* source, cIGZString* dest, int32_t encoding);

// STUB: 0x005f8fe0
bool Fn005f8fe0(char c);

// STUB: 0x00919672
bool Fn00919672(cRZString* out, const cRZString* path);

// STUB: 0x00917e7c
char* Fn00917e7c(char* out, const char* path, uint32_t size, const char* base);

// The drive, directory, name and extension of a path (the file's Splitpath).
// STUB: 0x00917bcb
void Fn00917bcb(const char* path, char* drive, char* dir, char* name, char* ext);

#ifdef OB_DRAFTS
// CLOSE: 0x00917bcb score 182
void Fn00917bcb(const char* path, char* drive, char* dir, char* name, char* ext)
{
    const char* lastDot = 0;
    const char* start;
    if (strlen(path) == 0 || path[1] != ':') {
        start = path;
        if (drive) {
            *drive = 0;
        }
    } else {
        if (drive) {
            strncpy(drive, path, 2);
            drive[2] = 0;
        }
        start = path + 2;
    }
    const char* nameStart = 0;
    const char* p = start;
    char c = *start;
    if (c != 0) {
        do {
            if (Fn005f8fe0(c)) {
                nameStart = p + 1;
            } else if (c == '.') {
                lastDot = p;
            }
            ++p;
            c = *p;
        } while (c != 0);
    }
    if (nameStart != 0) {
        if (dir) {
            uint32_t n = nameStart - start;
            if (n > 0xfe) {
                n = 0xff;
            }
            strncpy(dir, start, n);
            dir[n] = 0;
        }
    } else {
        nameStart = start;
        if (dir) {
            *dir = 0;
        }
    }
    if (lastDot == 0 || lastDot < nameStart) {
        if (name) {
            uint32_t n = 0xff;
            if (static_cast<uint32_t>(p - nameStart) < 0xff) {
                n = p - nameStart;
            }
            strncpy(name, nameStart, n);
            name[n] = 0;
        }
        if (ext) {
            *ext = 0;
        }
    } else {
        if (name) {
            uint32_t n = lastDot - nameStart;
            if (n > 0xfe) {
                n = 0xff;
            }
            strncpy(name, nameStart, n);
            name[n] = 0;
        }
        if (ext) {
            uint32_t n = 0xff;
            if (static_cast<uint32_t>(p - lastDot) < 0xff) {
                n = p - lastDot;
            }
            strncpy(ext, lastDot, n);
            ext[n] = 0;
        }
    }
}
#endif

// An absolute path without a "\." or "/." part.
// FUNCTION: 0x00918080
bool Fn00918080(const char* path)
{
    if ((isalpha(*path) && path[1] == ':' && path[2] == '\\') || (path[0] == '\\' && path[1] == '\\')) {
        if (!strstr(path, "\\.") && !strstr(path, "/.")) {
            return true;
        }
    }
    return false;
}

// A character a file name may hold.
// FUNCTION: 0x009180d4
uint32_t Fn009180d4(char c)
{
    if (c == '<' || c == '>' || c == ':' || c == '\\' || c == '/' || c == '"' || c == '|' || c == '*' || c == '?') {
        return 0;
    }
    return 1;
}

// The extension of a path, into a string.
#ifdef OB_DRAFTS
// CLOSE: 0x00918417 score 4
bool Fn00918417(cIGZString* path, cIGZString* out)
{
    char drive[4] = "";
    char dir[256] = "";
    char name[256] = "";
    char ext[256] = "";
    Fn00917bcb(path->ToChar(), drive, dir, name, ext);
    uint32_t length = strlen(ext);
    out->FromChar(ext, length);
    return length != 0;
}
#endif

// The drive of a path, with a closing separator, into a string.
// FUNCTION: 0x009184c2
bool Fn009184c2(cIGZString* path, cIGZString* out)
{
    char drive[4] = "";
    char dir[256] = "";
    char name[256] = "";
    char ext[256] = "";
    Fn00917bcb(path->ToChar(), drive, dir, name, ext);
    uint32_t length = strlen(drive);
    if (length != 0) {
        drive[2] = '\\';
        drive[3] = 0;
        out->FromChar(drive, 3);
    }
    return length != 0;
}

#ifdef _MSC_VER
#define RZ_STAT_TYPE struct _stat
#define RZ_STAT _stat
#else
#define RZ_STAT_TYPE struct stat
#define RZ_STAT stat
#endif

// A file's time (1 created, 2 modified, 3 accessed); 0 where the file cannot be read.
// FUNCTION: 0x00918cb1
uint32_t Fn00918cb1(const cIGZString* path, uint32_t type)
{
    cRZString converted;
    Fn0091152f(path, &converted, -1);
    RZ_STAT_TYPE info;
    if (RZ_STAT(converted.c_str(), &info) == 0) {
        uint32_t time;
        if (type == 1) {
            time = info.st_ctime;
        } else if (type == 2) {
            time = info.st_mtime;
        } else if (type == 3) {
            time = info.st_atime;
        } else {
            return 0;
        }
        return time;
    }
    return 0;
}

// The wide string at the front of this file's helpers (begin, end, end of storage).
struct Wide_abfed0 {
    uint16_t* mpBegin;
    uint16_t* mpEnd;
    uint16_t* mpCap;
    // STUB: 0x0079c7c0
    void Fn0079c7c0(uint32_t count);
    void Fn00918a86(const uint16_t* first, const uint16_t* last, char* tag);
    Wide_abfed0* Fn00918eba(const Wide_abfed0* other);
    uint32_t Fn00918a25Draft(uint16_t value, uint32_t position);
    Wide_abfed0* Fn00919114Draft(const uint16_t* first, const uint16_t* last);
    // STUB: 0x0090e3bf
    void Fn0090e3bf(uint16_t* first, uint16_t* last);
    // STUB: 0x00918ab7
    Wide_abfed0* Fn00918ab7(const uint16_t* first, const uint16_t* last, char* tag);
};

// STUB: 0x0090e63c
uint16_t* Fn0090e63c(const uint16_t* first, const uint16_t* last, uint16_t* destination);

// FUNCTION: 0x00918a86
void Wide_abfed0::Fn00918a86(const uint16_t* first, const uint16_t* last, char* /*tag*/)
{
    Fn0079c7c0((last - first) + 1);
    mpEnd = Fn0090e63c(first, last, mpBegin);
    *mpEnd = 0;
}

// FUNCTION: 0x00918eba
Wide_abfed0* Wide_abfed0::Fn00918eba(const Wide_abfed0* other)
{
    mpBegin = 0;
    mpEnd = 0;
    mpCap = 0;
    char tag;
    Fn00918a86(other->mpBegin, other->mpEnd, &tag);
    return this;
}

// The drive, directory, name and extension of a path, each into a string where one is given.
#ifdef OB_DRAFTS
// CLOSE: 0x009194a0 score 45
void Fn009194a0(const cRZString* path, cRZString* drive, cRZString* dir, cRZString* name, cRZString* ext)
{
    char driveBuffer[4];
    char dirBuffer[256];
    char nameBuffer[256];
    char extBuffer[256];
    Fn00917bcb(path->c_str(), driveBuffer, dirBuffer, nameBuffer, extBuffer);
    if (drive) {
        *drive = cRZString(driveBuffer);
    }
    if (dir) {
        *dir = cRZString(dirBuffer);
    }
    if (name) {
        *name = cRZString(nameBuffer);
    }
    if (ext) {
        *ext = cRZString(extBuffer);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009196cc score 8
bool Fn009196cc(cRZString* out, const cRZString* path, const cRZString* base)
{
    char full[0x208];
    if (Fn00917e7c(full, path->c_str(), 0x208, base ? base->c_str() : "")) {
        *out = cRZString(full);
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00919738 score 10
bool Fn00919738(cRZString* out, const cRZString* path, const cRZString* base)
{
    if (Fn009186e7(path)) {
        *out = *path;
        return true;
    }
    if (base == 0) {
        return Fn00919672(out, path);
    }
    return Fn009196cc(out, path, base);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009192a9 score 110
bool cRZFile::ReadWithCount(void* buffer, void* count)
{
    if (mbOpen) {
        uint32_t* pCount = static_cast<uint32_t*>(count);
        if (*pCount != 0) {
            if (mnWriteFill != 0) {
                FlushWriteBuffer();
            }
            if (mnReadBufferSize != 0) {
                uint32_t remaining = *pCount;
                uint8_t* destination = static_cast<uint8_t*>(buffer);
                bool ok = true;
                while (remaining != 0) {
                    uint32_t windowStart = mnReadWindowOffset;
                    int32_t position = mnPosition;
                    uint32_t chunk;
                    if (position >= static_cast<int32_t>(windowStart) &&
                        position < static_cast<int32_t>(mnReadWindowCount + windowStart)) {
                        chunk = mnReadWindowCount - (position - windowStart);
                        if (static_cast<int32_t>(chunk) >= static_cast<int32_t>(remaining)) {
                            chunk = remaining;
                        }
                        memcpy(destination, mpReadBegin + (position - windowStart), chunk);
                        destination += chunk;
                    } else {
                        mnReadWindowOffset = 0;
                        mnReadWindowCount = 0;
                        if (mnFilePosition != static_cast<uint32_t>(position)) {
                            ok = SeekToPosition(position) == mnPosition;
                        }
                        if (!ok) {
                            break;
                        }
                        ok = FillReadBuffer();
                        if (!ok) {
                            break;
                        }
                        chunk = mnReadWindowCount;
                        if (chunk == 0) {
                            break;
                        }
                        if (static_cast<int32_t>(chunk) >= static_cast<int32_t>(remaining)) {
                            chunk = remaining;
                        }
                        memcpy(destination, mpReadBegin, chunk);
                        destination += chunk;
                    }
                    remaining -= chunk;
                    mnPosition += chunk;
                }
                *pCount -= remaining;
                return ok;
            }
            int32_t result = ReadFile(mhFile, buffer, *pCount, pCount, 0);
            if (result != 0) {
                mnFilePosition += *pCount;
            } else {
                mnFilePosition = SetFilePointer(mhFile, 0, 0, 1);
                SetErrorFromOS();
            }
            mnPosition = mnFilePosition;
            return result != 0;
        }
        return true;
    }
    return false;
}
#endif

// ---- the wide-or-narrow file system calls ----

// A wide string's three pointers (a local of the original's functions).
struct WideBuffer_abfed0 {
    uint16_t* mpBegin;
    uint16_t* mpEnd;
    uint16_t* mpCap;
};

// The wide file system calls the program looks up at start (null where the system has only the narrow ones).
// GLOBAL: 0x00b628e0
extern void* (OB_STDCALL* gpB628e0)(const uint16_t*, uint32_t, uint32_t, void*, uint32_t, uint32_t, void*);
// GLOBAL: 0x00b628e4
extern int32_t (OB_STDCALL* gpB628e4)(const uint16_t*, const uint16_t*, int32_t);
// GLOBAL: 0x00b628e8
extern int32_t (OB_STDCALL* gpB628e8)(const uint16_t*, const uint16_t*, uint32_t);
// GLOBAL: 0x00b628f0
extern int32_t (OB_STDCALL* gpB628f0)(const uint16_t*);
// GLOBAL: 0x00b628f4
extern uint32_t (OB_STDCALL* gpB628f4)(const uint16_t*);
// GLOBAL: 0x00b628f8
extern int32_t (OB_STDCALL* gpB628f8)(const uint16_t*, uint32_t);

// Resolves a shortcut file (the size of the target path, 0 where the file is no shortcut, -1 on failure).
// STUB: 0x0091814e
int32_t Fn0091814e(const char* path, char* out, int32_t size);

// The wide form of a string; the original passes the source in edi and the buffer on the stack, which no C++
// signature expresses, so only drafts call this.
// STUB: 0x0091af61
uint16_t** Fn0091af61(const cIGZString* source, WideBuffer_abfed0* out);

// Whether a file or directory exists.
#ifdef OB_DRAFTS
// CLOSE: 0x00919e96 score 13
bool Fn00919e96Draft_abfed0(const cRZString* path)
{
    bool exists;
    if (gpB628f4) {
        WideBuffer_abfed0 wide;
        exists = gpB628f4(*Fn0091af61(path, &wide)) != 0xffffffff;
        if (wide.mpBegin) {
            _STL::__stl_delete(wide.mpBegin);
        }
    } else {
        cRZString converted;
        Fn0091152f(path, &converted, -1);
        exists = GetFileAttributesA(converted.cRZString::ToChar()) != 0xffffffff;
    }
    return exists;
}
#endif

// Deletes a file.
#ifdef OB_DRAFTS
// CLOSE: 0x0091a1a6 score 27
bool Fn0091a1a6Draft_abfed0(const cRZString* path)
{
    int32_t result;
    if (gpB628f0) {
        WideBuffer_abfed0 wide;
        result = gpB628f0(*Fn0091af61(path, &wide));
        if (wide.mpBegin) {
            _STL::__stl_delete(wide.mpBegin);
        }
    } else {
        cRZString converted;
        Fn0091152f(path, &converted, -1);
        result = DeleteFileA(converted.cRZString::ToChar());
    }
    return result != 0;
}
#endif

// Renames a file.
#ifdef OB_DRAFTS
// CLOSE: 0x0091a225 score 44
bool Fn0091a225Draft_abfed0(const cIGZString* from, const cIGZString* to)
{
    int32_t result;
    if (gpB628e8) {
        WideBuffer_abfed0 wideFrom;
        WideBuffer_abfed0 wideTo;
        const uint16_t* target = *Fn0091af61(to, &wideTo);
        result = gpB628e8(*Fn0091af61(from, &wideFrom), target, 2);
        if (wideFrom.mpBegin) {
            _STL::__stl_delete(wideFrom.mpBegin);
        }
        if (wideTo.mpBegin) {
            _STL::__stl_delete(wideTo.mpBegin);
        }
    } else {
        cRZString convertedFrom;
        cRZString convertedTo;
        Fn0091152f(from, &convertedFrom, -1);
        Fn0091152f(to, &convertedTo, -1);
        result = MoveFileA(convertedFrom.cRZString::ToChar(), convertedTo.cRZString::ToChar());
    }
    return result != 0;
}
#endif

// Copies a file.
#ifdef OB_DRAFTS
// CLOSE: 0x0091a2f9 score 24
bool Fn0091a2f9Draft_abfed0(const cIGZString& from, const cIGZString& to, bool overwrite)
{
    bool copied;
    if (gpB628e4) {
        WideBuffer_abfed0 wideFrom;
        WideBuffer_abfed0 wideTo;
        const uint16_t* target = *Fn0091af61(&to, &wideTo);
        copied = gpB628e4(*Fn0091af61(&from, &wideFrom), target, !overwrite) != 0;
        if (wideFrom.mpBegin) {
            _STL::__stl_delete(wideFrom.mpBegin);
        }
        if (wideTo.mpBegin) {
            _STL::__stl_delete(wideTo.mpBegin);
        }
    } else {
        cRZString convertedFrom;
        cRZString convertedTo;
        Fn0091152f(&from, &convertedFrom, -1);
        Fn0091152f(&to, &convertedTo, -1);
        copied = CopyFileA(convertedFrom.cRZString::ToChar(), convertedTo.cRZString::ToChar(), !overwrite) != 0;
    }
    return copied;
}
#endif

// Whether the file has every attribute the mask asks for (read-only 2, directory 8, archive 0x20, hidden 0x40,
// system 0x80 and 0x1000), and, with the mask's 0x10, whether it can be resolved.
#ifdef OB_DRAFTS
// CLOSE: 0x00919f17 score 79
bool Fn00919f17Draft_abfed0(const cIGZString* path, uint32_t mask)
{
    uint32_t attributes;
    if (gpB628f4) {
        WideBuffer_abfed0 wide;
        attributes = gpB628f4(*Fn0091af61(path, &wide));
        if (wide.mpBegin) {
            _STL::__stl_delete(wide.mpBegin);
        }
    } else {
        cRZString converted;
        Fn0091152f(path, &converted, -1);
        attributes = GetFileAttributesA(converted.cRZString::ToChar());
    }
    if (((mask & 2) == 0 || (attributes & 1) == 0) && ((mask & 8) == 0 || (attributes & 0x10) != 0)) {
        if ((mask & 0x10) != 0 && (mask & 0x400) == 0) {
            cRZString converted;
            char full[0x104];
            Fn0091152f(path, &converted, -1);
            if (Fn0091814e(converted.cRZString::ToChar(), full, 0x104) == 0) {
                return false;
            }
        }
        if (((mask & 0x20) == 0 || (attributes & 0x20) != 0) && ((mask & 0x40) == 0 || (attributes & 2) != 0) &&
            ((mask & 0x80) == 0 || (attributes & 4) != 0) && ((mask & 0x1000) == 0 || (attributes & 1) != 0)) {
            return true;
        }
    }
    return false;
}
#endif

// Sets or clears (set) the attributes the mask names.
#ifdef OB_DRAFTS
// CLOSE: 0x0091a035 score 154
bool Fn0091a035Draft_abfed0(const cIGZString* path, uint32_t mask, char set)
{
    cRZString converted;
    uint32_t attributes;
    if (gpB628f4 == 0 || gpB628f8 == 0) {
        Fn0091152f(path, &converted, -1);
        attributes = GetFileAttributesA(converted.cRZString::ToChar());
    } else {
        WideBuffer_abfed0 wide;
        attributes = gpB628f4(*Fn0091af61(path, &wide));
        if (wide.mpBegin) {
            _STL::__stl_delete(wide.mpBegin);
        }
    }
    uint32_t wanted = attributes;
    if ((mask & 2) != 0) {
        if (set == 0) {
            wanted = attributes | 1;
        } else {
            wanted = attributes & 0xfffffffe;
        }
    }
    if ((mask & 8) == 0 && (mask & 0x10) == 0) {
        if ((mask & 0x20) != 0) {
            if (set == 0) {
                wanted &= 0xffffffdf;
            } else {
                wanted |= 0x20;
            }
        }
        if ((mask & 0x40) != 0) {
            if (set == 0) {
                wanted &= 0xfffffffd;
            } else {
                wanted |= 2;
            }
        }
        if ((mask & 0x80) != 0) {
            if (set == 0) {
                wanted &= 0xfffffffb;
            } else {
                wanted |= 4;
            }
        }
        if ((mask & 0x1000) != 0) {
            if (set == 0) {
                wanted &= 0xfffffffe;
            } else {
                wanted |= 1;
            }
        }
        if (wanted == attributes) {
            return true;
        }
        if (gpB628f8 == 0) {
            return SetFileAttributesA(converted.cRZString::ToChar(), wanted) != 0;
        }
        WideBuffer_abfed0 wide;
        bool changed = gpB628f8(*Fn0091af61(path, &wide), wanted) != 0;
        if (wide.mpBegin) {
            _STL::__stl_delete(wide.mpBegin);
        }
        return changed;
    }
    return false;
}
#endif

// Whether a file can be opened for reading; with truncate, it is also cut to its start.
#ifdef OB_DRAFTS
// CLOSE: 0x00919dc2 score 22
bool Fn00919dc2Draft_abfed0(const cIGZString* path, char truncate)
{
    uint32_t security[3];
    security[0] = 0xc;
    security[1] = 0;
    security[2] = 0;
    void* handle;
    if (gpB628e0) {
        WideBuffer_abfed0 wide;
        handle = gpB628e0(*Fn0091af61(path, &wide), 0x80000000, 3, security, 4, 0x80, 0);
        if (wide.mpBegin) {
            _STL::__stl_delete(wide.mpBegin);
        }
    } else {
        cRZString converted;
        Fn0091152f(path, &converted, -1);
        handle = CreateFileA(converted.cRZString::ToChar(), 0x80000000, 3, security, 4, 0x80, 0);
    }
    if (handle == reinterpret_cast<void*>(-1)) {
        return false;
    }
    if (truncate != 0) {
        SetFilePointer(handle, 0, 0, 0);
        SetEndOfFile(handle);
    }
    CloseHandle(handle);
    return true;
}
#endif

// The wide-string buffer helpers the open path uses (thiscall on the buffer).
struct WideTemp_abfed0 {
    uint16_t* mpBegin;
    uint16_t* mpEnd;
    uint16_t* mpCap;
    // STUB: 0x00621810
    WideTemp_abfed0();
    // STUB: 0x0096edf7
    void Swap(WideBuffer_abfed0* other);
};

// STUB: 0x009198f3
bool Fn009198f3(WideBuffer_abfed0* path, WideTemp_abfed0* resolved);

#ifdef OB_DRAFTS
// CLOSE: 0x00919b00 score 172
bool cRZFile::Open(uint32_t access, uint32_t creation, uint32_t share)
{
    if (IsOpen()) {
        return true;
    }
    uint32_t desired = 0;
    if ((access & 1) != 0) {
        desired = 0x80000000;
    }
    if ((access & 2) != 0) {
        desired |= 0x40000000;
    }
    uint32_t sharing = (share & 1) != 0;
    if ((share & 2) != 0) {
        sharing = 3;
    }
    uint32_t disposition;
    switch (creation) {
    case 0:
        disposition = 1;
        break;
    case 1:
        disposition = 2;
        break;
    case 2:
        disposition = 3;
        break;
    case 3:
        disposition = 4;
        break;
    case 4:
        disposition = 5;
        break;
    default:
        return false;
    }
    if (gpB628e0) {
        WideBuffer_abfed0 wide;
        Fn0091af61(&mPath, &wide);
        WideTemp_abfed0 resolved;
        if (Fn009198f3(&wide, &resolved)) {
            resolved.Swap(&wide);
        }
        mhFile = gpB628e0(wide.mpBegin, desired, sharing, 0, disposition, 0, 0);
        if (resolved.mpBegin) {
            _STL::__stl_delete(resolved.mpBegin);
        }
        if (wide.mpBegin) {
            _STL::__stl_delete(wide.mpBegin);
        }
    } else {
        cRZString converted;
        Fn0091152f(&mPath, &converted, -1);
        char resolvedPath[0x104];
        int32_t length = Fn0091814e(converted.c_str(), resolvedPath, 0x104);
        const char* name = converted.c_str();
        if (length != 0 && length != -1) {
            name = resolvedPath;
        }
        mhFile = CreateFileA(name, desired, sharing, 0, disposition, 0, 0);
    }
    if (mhFile == reinterpret_cast<void*>(-1)) {
        SetErrorFromOS();
        return false;
    }
    mbOpen = true;
    if (disposition == 2 || disposition == 4) {
        SetErrorFromOS();
    }
    mnAccess = access;
    mnCreation = creation;
    mnShare = share;
    mnFilePosition = SetFilePointer(mhFile, 0, 0, 1);
    mnPosition = mnFilePosition;
    mnReadWindowOffset = 0;
    mnReadWindowCount = 0;
    mnWriteFileOffset = 0;
    mnWriteFill = 0;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00919cd8 score 32
bool cRZFile::Remove()
{
    if (IsOpen()) {
        Close();
    }
    int32_t result;
    if (gpB628f0) {
        WideBuffer_abfed0 wide;
        result = gpB628f0(*Fn0091af61(&mPath, &wide));
        if (wide.mpBegin) {
            _STL::__stl_delete(wide.mpBegin);
        }
        if (!result) {
            SetErrorFromOS();
        }
        return result != 0;
    }
    cRZString converted;
    Fn0091152f(&mPath, &converted, -1);
    result = DeleteFileA(converted.cRZString::ToChar());
    if (!result) {
        SetErrorFromOS();
    }
    return result != 0;
}
#endif

// The wide forms of GetTempPath and GetLongPathName and the narrow long-path call (null where unavailable).
// GLOBAL: 0x00b62904
extern uint32_t (OB_STDCALL* gpB62904)(uint32_t, uint16_t*);
// GLOBAL: 0x00b62900
extern uint32_t (OB_STDCALL* gpB62900)(const uint16_t*, uint16_t*, uint32_t);
// GLOBAL: 0x00b628fc
extern uint32_t (OB_STDCALL* gpB628fc)(const char*, char*, uint32_t);

// STUB: 0x00911358
uint32_t RZEncodingToString(const void* text, uint32_t length, int32_t encoding, cIGZString& out);

// The temporary directory's name, into a string.
#ifdef OB_DRAFTS
// CLOSE: 0x00918d35 score 28
bool Fn00918d35Draft_abfed0(cIGZString* out)
{
    if (gpB62904 && gpB62900) {
        uint16_t buffer[0x104];
        uint32_t length = gpB62904(0x104, buffer);
        if (length == 0) {
            return false;
        }
        if (gpB62900) {
            length = gpB62900(buffer, buffer, 0x104);
        }
        RZEncodingToString(buffer, length, 0x10, *out);
        return true;
    }
    char buffer[0x104];
    uint32_t length = GetTempPathA(0x104, buffer);
    if (length == 0) {
        return false;
    }
    if (gpB628fc) {
        length = gpB628fc(buffer, buffer, 0x104);
    }
    {
        cRZString text(buffer, length);
        Fn00911466(&text, -1, out);
    }
    return true;
}
#endif

// The volume's name of a path, into a string.
#ifdef OB_DRAFTS
// CLOSE: 0x00918e00 score 8
bool Fn00918e00Draft_abfed0(cIGZString* path, cIGZString* out)
{
    cRZString root;
    if (Fn009184c2(path, &root)) {
        char volume[0x104];
        char system[0x104];
        uint32_t serial;
        uint32_t maxLength;
        uint32_t flags;
        if (GetVolumeInformationA(root.c_str(), volume, 0x104, &serial, &maxLength, &flags, system, 0x104)) {
            cRZString text(volume);
            Fn00911466(&text, -1, out);
            return true;
        }
    }
    return false;
}
#endif

// The first words of a find-data record (the size sits at 0x20).
struct FindData_abfed0 {
    uint32_t mnAttributes;
    uint32_t mnTimes[6];
    uint32_t mnSizeHigh;
    uint32_t mnSizeLow;
    uint8_t mPad[0x250];
};

// GLOBAL: 0x00b628ec
extern void* (OB_STDCALL* gpB628ec)(const uint16_t*, void*);

// The size of a file, or -1.
#ifdef OB_DRAFTS
// CLOSE: 0x0091a3e2 score 72
uint32_t Fn0091a3e2Draft_abfed0(const cIGZString* path)
{
    uint32_t size = 0xffffffff;
    FindData_abfed0 data;
    if (gpB628ec == 0) {
        cRZString converted;
        Fn0091152f(path, &converted, -1);
        void* handle = FindFirstFileA(converted.cRZString::ToChar(), &data);
        if (handle != reinterpret_cast<void*>(-1)) {
            FindClose(handle);
            size = data.mnSizeLow;
        }
    } else {
        WideBuffer_abfed0 wide;
        void* handle = gpB628ec(*Fn0091af61(path, &wide), &data);
        if (wide.mpBegin) {
            _STL::__stl_delete(wide.mpBegin);
        }
        if (handle != reinterpret_cast<void*>(-1)) {
            FindClose(handle);
            size = data.mnSizeLow;
        }
    }
    return size;
}
#endif

// The drive and directory of a path, into a string.
#ifdef OB_DRAFTS
// CLOSE: 0x0091a847 score 17
bool Fn0091a847Draft_abfed0(cIGZString* path, cIGZString* out)
{
    char drive[4] = "";
    char dir[256] = "";
    char name[256] = "";
    char ext[256] = "";
    cRZString text;
    Fn00917bcb(path->ToChar(), drive, dir, name, ext);
    text = cRZString(drive);
    text.append(dir);
    out->FromChar(text.c_str(), text.size());
    return text.size() != 0;
}
#endif

// The file name of a path, with its extension where asked, into a string.
#ifdef OB_DRAFTS
// CLOSE: 0x0091a93d score 19
bool Fn0091a93dDraft_abfed0(cIGZString* path, cIGZString* out, bool withExtension)
{
    char drive[4] = "";
    char dir[256] = "";
    char name[256] = "";
    char ext[256] = "";
    cRZString text;
    Fn00917bcb(path->ToChar(), drive, dir, name, ext);
    text = cRZString(name);
    if (withExtension) {
        text.append(ext);
    }
    out->FromChar(text.c_str(), text.size());
    return text.size() != 0;
}
#endif

// The directory names of a path, last first, each into a 0x104-byte entry; the count says how many fit and, on
// return, how many there are.
#ifdef OB_DRAFTS
// CLOSE: 0x00917d1a score 161
bool Fn00917d1aDraft_abfed0(const char* path, char* out, int32_t* count)
{
    int32_t length = strlen(path);
    if (length < 1) {
        *count = 0;
        return false;
    }
    int32_t found = 0;
    int32_t end = length - 1;
    int32_t index = end;
    if (Fn005f8fe0(path[end])) {
        index = length - 2;
    }
    int32_t pieceEnd = end;
    if (index >= 0) {
        int32_t offset = 0;
        int32_t number = 1;
        do {
            if (*count <= number) {
                break;
            }
            bool store = false;
            if (Fn005f8fe0(path[index])) {
                end = end - index;
                strncpy(out + offset, path + index + 1, end);
                pieceEnd = index;
                store = true;
            } else if (index == 0) {
                strncpy(out + offset, path, pieceEnd);
                pieceEnd = 0;
                store = true;
            }
            if (store) {
                if (end < 1 || end > 0xfe) {
                    *count = 0;
                    return false;
                }
                char* tail = out + offset + end;
                if (!Fn005f8fe0(tail[-1])) {
                    tail[0] = '\\';
                    tail[1] = 0;
                } else {
                    tail[0] = 0;
                }
                ++found;
                ++number;
                offset += 0x104;
                end = pieceEnd;
            }
            --index;
        } while (index >= 0);
    }
    if (end > 0 && found < *count) {
        if (end > 0xfe) {
            *count = 0;
            return false;
        }
        strncpy(out + found * 0x104, path, pieceEnd);
        char* tail = out + found * 0x104 + pieceEnd;
        if (!Fn005f8fe0(tail[-1])) {
            tail[0] = '\\';
            tail[1] = 0;
        } else {
            tail[0] = 0;
        }
        ++found;
    }
    *count = found;
    return true;
}
#endif

// STUB: 0x00917d1a
bool Fn00917d1a(const char* path, char* out, int32_t* count);

// STUB: 0x00680c40
void Fn00680c40(uint32_t value, char* entry);

// The directory names of a path into strings.
#ifdef OB_DRAFTS
// CLOSE: 0x0091958b score 71
bool Fn0091958bDraft_abfed0(const cRZString* path, cRZString* out, int32_t* count)
{
    char* buffer = new char[0x2080];
    int32_t total = 0x20;
    char* entry = buffer;
    bool ok = false;
    if (Fn00917d1a(path->c_str(), entry, &total)) {
        if (total < *count) {
            *count = total;
        }
        int32_t index = 0;
        if (*count > 0) {
            cRZString* target = out;
            do {
                *target = cRZString(entry);
                ++index;
                ++target;
                entry += 0x104;
            } while (index < *count);
        }
        if (index < total) {
            char* rest = buffer + index * 0x104;
            int32_t remaining = total - index;
            do {
                Fn00680c40(0, rest);
                rest += 0x104;
                --remaining;
            } while (remaining != 0);
        }
        ok = true;
    } else {
        *count = 0;
    }
    delete[] buffer;
    return ok;
}
#endif

// The last place in [first, last) holding the value, as the position after it; first where there is none.
#ifdef OB_DRAFTS
// CLOSE: 0x00918731 score 60
void Fn00918731Draft(const uint16_t** out, const uint16_t* last, const uint16_t* first, uint16_t value)
{
    const uint16_t* p = last;
    while (p > first) {
        if (p[-1] == value) {
            *out = p;
            return;
        }
        --p;
    }
    *out = first;
}
#endif

// The index of the last occurrence of the value at or before the position, or -1.
#ifdef OB_DRAFTS
// CLOSE: 0x00918a25 score 45
uint32_t Wide_abfed0::Fn00918a25Draft(uint16_t value, uint32_t position)
{
    uint32_t length = mpEnd - mpBegin;
    if (length < 1) {
        return 0xffffffff;
    }
    uint32_t limit = length - 1;
    if (position < limit) {
        limit = position;
    }
    const uint16_t* found;
    Fn00918731Draft(&found, mpBegin + limit + 1, mpBegin, value);
    if (found == mpBegin) {
        return 0xffffffff;
    }
    return (found - mpBegin) - 1;
}
#endif

// Assigns the range.
#ifdef OB_DRAFTS
// CLOSE: 0x00919114 score 52
Wide_abfed0* Wide_abfed0::Fn00919114Draft(const uint16_t* first, const uint16_t* last)
{
    uint32_t count = last - first;
    uint32_t size = mpEnd - mpBegin;
    char tag;
    if (count <= size) {
        Fn009185a3(mpBegin, first, count);
        Fn0090e3bf(mpBegin + count, mpEnd);
    } else {
        Fn009185a3(mpBegin, first, size);
        Fn00918ab7(first + size, last, &tag);
    }
    return this;
}
#endif
