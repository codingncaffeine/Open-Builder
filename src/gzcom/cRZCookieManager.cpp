#include "classes/cRZCookieManager.h"
#include "gzcom/cRZString.h"
#include <string>
#include <time.h>
#include <vector>

#ifdef _MSC_VER
#define OB_STRICMP_accf68 _stricmp
#else
#include <strings.h>
#define OB_STRICMP_accf68 strcasecmp
#endif
#include <stdlib.h>
#include <string.h>

// The lock embedded at offset 0x14 (a vtable and one word); only the slots used here are named.
struct Lock_accf68 {
    virtual void Pad0_accf68();
    virtual void Enter_accf68();
    virtual void Leave_accf68();
};

// A scope guard over the embedded lock: the constructor takes the lock, the destructor lets it go.
struct Guard_accf68 {
    uint32_t mPad;
    Lock_accf68* mpLock;

    // STUB: 0x0048c9f0
    Guard_accf68(Lock_accf68* lock);
    ~Guard_accf68() { mpLock->Leave_accf68(); }
};

// One name and value of a cookie (the original's std::pair of two strings, whose destructor it keeps out of line).
struct Pair_accf68 {
    std::string mName;
    std::string mValue;
    // STUB: 0x008181e0
    ~Pair_accf68();
};

// The pairs of a cookie: a vector (begin, end, capacity).
struct PairVec_accf68 {
    Pair_accf68* mpBegin;
    Pair_accf68* mpEnd;
    Pair_accf68* mpCap;

    uint32_t size() const
    {
        return mpEnd - mpBegin;
    }
    bool empty() const
    {
        return mpBegin == mpEnd;
    }
    Pair_accf68& operator[](uint32_t n)
    {
        return mpBegin[n];
    }
    // STUB: 0x008f8a94
    void Erase(Pair_accf68* first, Pair_accf68* last);
    // STUB: 0x0081abe0
    void PushBack(const Pair_accf68& pair);
};

// One cookie: its text, its name/value pairs, the attributes read from them. 0x94 bytes.
struct CookieData_accf68 {
    std::string mText;                   // 0x00
    PairVec_accf68 mPairs;               // 0x0c
    std::string mComment;                // 0x18
    std::string mCommentURL;             // 0x24
    std::string mDomain;                 // 0x30
    std::string mPath;                   // 0x3c
    uint32_t mnVersion;                  // 0x48
    uint32_t mnExpires;                  // 0x4c
    uint32_t mnPorts[16];                // 0x50
    uint32_t mbSecure;                   // 0x90

    // STUB: 0x008f883e
    CookieData_accf68();
    // STUB: 0x008f8875
    ~CookieData_accf68();
    // STUB: 0x008f88c7
    CookieData_accf68& operator=(const CookieData_accf68& other);
};

// The cookie list: a vector of cookies (begin, end, capacity).
struct Cookies_accf68 {
    CookieData_accf68* mpBegin;
    CookieData_accf68* mpEnd;
    CookieData_accf68* mpCap;

    CookieData_accf68* begin() const
    {
        return mpBegin;
    }
    CookieData_accf68* end() const
    {
        return mpEnd;
    }
    uint32_t size() const
    {
        return end() - begin();
    }
    // STUB: 0x008f9b5c
    void Erase(CookieData_accf68* first, CookieData_accf68* last);
    void Clear()
    {
        Erase(mpBegin, mpEnd);
    }
    // STUB: 0x008f99ca
    void EraseOne(CookieData_accf68* where);
    // STUB: 0x008f9ff2
    void PushBack(const CookieData_accf68* cookie);
};

inline Cookies_accf68* CookiesOf_accf68(cRZCookieManager* self)
{
    return reinterpret_cast<Cookies_accf68*>(&self->mCookies[0]);
}

inline Lock_accf68* LockOf_accf68(cRZCookieManager* self)
{
    return reinterpret_cast<Lock_accf68*>(&self->mLock[0]);
}

// An address and its parts (the framework's URL class; 0xc0 bytes). The constructors are stubs of their own, so each
// has its own type over the same bytes.
struct Url_accf68 {
    uint8_t mPad_accf68[0xc0];
    // STUB: 0x00821fc0
    void SetFullURL(const cRZString* text, bool flag);
    // STUB: 0x008238d0
    const cRZString* GetAbsolutePath();
    // STUB: 0x00823860
    const cRZString* GetServer();
    // STUB: 0x008216d0
    uint32_t GetPort();
};

struct UrlEmpty_accf68 : Url_accf68 {
    // STUB: 0x008216e0
    UrlEmpty_accf68();
    // STUB: 0x008128a0
    ~UrlEmpty_accf68();
};

struct UrlText_accf68 : Url_accf68 {
    // STUB: 0x00821c60
    UrlText_accf68(const cRZString& text);
    // STUB: 0x008128a0
    ~UrlText_accf68();
};

// The framework's ini file reader and writer (0x3c bytes).
struct Ini_accf68 {
    uint8_t mPad_accf68[0x3c];
    // STUB: 0x0091cee3
    Ini_accf68(const cRZString* path);
    // STUB: 0x0091cde3
    ~Ini_accf68();
    // STUB: 0x0091cbb3
    bool ReadEntry(const cRZString& section, const cRZString& key, cRZString* value);
    // STUB: 0x0091c84f
    uint32_t ReadBinaryEntry(const cRZString* section, const cRZString* key, void* buffer, uint32_t size);
    // STUB: 0x0091d168
    bool WriteEntry(const cRZString& section, const cRZString& key, const cRZString& value);
    // STUB: 0x0091c722
    bool WriteBinaryEntry(const cRZString* section, const cRZString* key, const void* data, uint32_t size);
};

// Splits text at a separator into at most max strings; returns how many.
// STUB: 0x00819290
uint32_t Fn00819290(const std::string* text, std::string* out, uint32_t max, bool trim, char separator, bool skipEmpty);

// The seconds since 1970 of a time text (0 when it cannot be read).
// STUB: 0x00818bd0
uint32_t Fn00818bd0(const cRZString* text);

// STUB: 0x0090f31b
void Fn0090f31b(const cRZString* source, std::string* dest);

// GLOBAL: 0x00b16138
extern const char* gp00b16138;

// The framework's file calls on a path.
// STUB: 0x00919e96
bool Fn00919e96(const cIGZString* path);

// STUB: 0x0091a1a6
bool Fn0091a1a6(const cIGZString* path);

// STUB: 0x00454bb0
bool Fn00454bb0(const cIGZString* a, const cIGZString* b);

// FUNCTION: 0x008f67a7
uint32_t cRZCookieManager::AddRef()
{
    Guard_accf68 guard(LockOf_accf68(this));
    return ++mnRefCount;
}

// FUNCTION: 0x008f67ce
uint32_t cRZCookieManager::Release()
{
    Lock_accf68* lock = LockOf_accf68(this);
    lock->Enter_accf68();
    uint32_t n;
    if (mnRefCount > 1) {
        n = --mnRefCount;
        lock->Leave_accf68();
    } else {
        lock->Leave_accf68();
        n = 0;
        delete this;
    }
    return n;
}

// FUNCTION: 0x008f683f
bool cRZCookieManager::ClearCookieDataFile()
{
    Guard_accf68 guard(LockOf_accf68(this));
    bool ok;
    if (Fn00919e96(&mCookieDataFilePath)) {
        ok = Fn0091a1a6(&mCookieDataFilePath);
    } else {
        ok = true;
    }
    return ok;
}

// FUNCTION: 0x008f6a7c
bool cRZCookieManager::Init()
{
    if (!mbInitialized) {
        if (CookiesOf_accf68(this)->mpBegin == CookiesOf_accf68(this)->mpEnd) {
            ReadCookieDataFile();
        }
        mbInitialized = true;
    }
    return true;
}

// FUNCTION: 0x008f9dda
bool cRZCookieManager::Shutdown()
{
    if (mbInitialized) {
        WriteCookieDataFile();
        Cookies_accf68* cookies = CookiesOf_accf68(this);
        cookies->Erase(cookies->mpBegin, cookies->mpEnd);
        mbInitialized = false;
    }
    return true;
}

// FUNCTION: 0x008f9dfd
bool cRZCookieManager::RemoveAllCookies()
{
    Guard_accf68 guard(LockOf_accf68(this));
    Cookies_accf68* cookies = CookiesOf_accf68(this);
    cookies->Erase(cookies->mpBegin, cookies->mpEnd);
    return true;
}

// FUNCTION: 0x008f807b
bool cRZCookieManager::GetCookieDataFilePath(void* path)
{
    Guard_accf68 guard(LockOf_accf68(this));
    *static_cast<cRZString*>(path) = mCookieDataFilePath;
    return true;
}

// FUNCTION: 0x008f80aa
bool cRZCookieManager::SetCookieDataFilePath(void* path)
{
    Guard_accf68 guard(LockOf_accf68(this));
    const cRZString* newPath = static_cast<const cRZString*>(path);
    if (Fn00454bb0(newPath, &mCookieDataFilePath)) {
        mCookieDataFilePath = *newPath;
        ReadCookieDataFile();
    }
    return true;
}

// FUNCTION: 0x008f71ff
bool cRZCookieManager::GetCookieTextForURL_2(void* address, void* text)
{
    UrlText_accf68 url(*static_cast<const cRZString*>(address));
    return GetCookieTextForURL(static_cast<void*>(&url), text);
}

// FUNCTION: 0x008f7240
bool cRZCookieManager::GetCookieDataForURL_2(void* address, void* cookie, uint32_t index)
{
    UrlText_accf68 url(*static_cast<const cRZString*>(address));
    return GetCookieDataForURL(static_cast<void*>(&url), cookie, index);
}

#ifdef OB_DRAFTS
// CLOSE: 0x008f8947 score 15
// The original gives the found pointer the storage of the index argument itself (the helper is passed the address of
// the argument): with that spelling this is score 0, but it is not honest C++, so the plain local stays.
bool cRZCookieManager::GetCookieDataForURL(void* address, void* cookie, uint32_t index)
{
    CookieData_accf68* found;
    Guard_accf68 guard(LockOf_accf68(this));
    bool ok;
    if (Fn008f6e9a(address, &found, index)) {
        *static_cast<CookieData_accf68*>(cookie) = *found;
        ok = true;
    } else {
        ok = false;
    }
    return ok;
}
#endif

// FUNCTION: 0x008f8bc7
uint32_t cRZCookieManager::EnumCookies(void* out, void* count)
{
    Guard_accf68 guard(LockOf_accf68(this));
    Cookies_accf68* cookies = CookiesOf_accf68(this);
    uint32_t* pCount = static_cast<uint32_t*>(count);
    CookieData_accf68* dst = static_cast<CookieData_accf68*>(out);
    if (*pCount > cookies->size()) {
        *pCount = CookiesOf_accf68(this)->size();
    }
    for (uint32_t i = 0; i < *pCount; ++i) {
        dst[i] = cookies->mpBegin[i];
    }
    return 1;
}

// FUNCTION: 0x008f8b5a
bool cRZCookieManager::AddCookie_2(void* text, void* url)
{
    const std::string* source = static_cast<const std::string*>(text);
    if (source->size() != 0) {
        CookieData_accf68 cookie;
        cookie.mText = *source;
        if (ParseCookieText(&cookie, url)) {
            bool added = AddCookie(&cookie, url);
            return added;
        }
    }
    return false;
}

// FUNCTION: 0x008f7784
bool cRZCookieManager::WriteCookieDataFile()
{
    Guard_accf68 guard(LockOf_accf68(this));
    ClearCookieDataFile();
    Cookies_accf68* cookies = CookiesOf_accf68(this);
    if (cookies->mpBegin != cookies->mpEnd) {
        Ini_accf68 ini(&mCookieDataFilePath);
        cRZString section(gp00b16138);
        cRZString key;
        std::string encrypted;
        cRZString value;
        uint32_t now = static_cast<uint32_t>(time(0));
        if (mbEncryptFile) {
            ini.WriteEntry(cRZString("Admin"), cRZString("Binary"), cRZString("1"));
        }
        uint32_t count = cookies->size();
        uint32_t written = 0;
        for (uint32_t i = 0; i < count; ++i) {
            CookieData_accf68* cookie = &cookies->mpBegin[i];
            if (cookie->mnExpires > now) {
                key.Sprintf("CookieData%05u", written++);
                if (mbEncryptFile) {
                    Fn008f7752(&cookies->mpBegin[i].mText, &encrypted);
                    ini.WriteBinaryEntry(&section, &key, encrypted.data(), encrypted.size());
                } else {
                    RZStringFromStd(cookie->mText, value);
                    ini.WriteEntry(section, key, value);
                }
            }
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008f9e2b score 4
bool cRZCookieManager::ReadCookieDataFile()
{
    Guard_accf68 guard(LockOf_accf68(this));
    CookiesOf_accf68(this)->Erase(CookiesOf_accf68(this)->mpBegin, CookiesOf_accf68(this)->mpEnd);
    if (Fn00919e96(&mCookieDataFilePath)) {
        Ini_accf68 ini(&mCookieDataFilePath);
        cRZString section(gp00b16138);
        cRZString key;
        uint8_t* buffer = new uint8_t[0x4000];
        std::string text;
        cRZString value;
        bool binary = ini.ReadEntry(cRZString("Admin"), cRZString("Binary"), &value);
        for (uint32_t i = 0; i < 10000; ++i) {
            key.Sprintf("CookieData%05u", i);
            if (binary) {
                uint32_t length = ini.ReadBinaryEntry(&section, &key, buffer, 0x4000);
                if (length == 0) {
                    break;
                }
                text.assign(reinterpret_cast<const char*>(buffer), length);
                Fn008f7752(&text, &text);
            } else {
                if (!ini.ReadEntry(section, key, &value)) {
                    break;
                }
                Fn0090f31b(&value, &text);
            }
            AddCookie_2(&text, 0);
        }
        delete[] buffer;
    }
    return true;
}
#endif

// FUNCTION: 0x008f7507
bool cRZCookieManager::GetCookieTextForURL(void* address, void* text)
{
    Guard_accf68 guard(LockOf_accf68(this));
    std::string& out = *static_cast<std::string*>(text);
    bool sawVersion = false;
    out.erase();
    uint32_t index = 0;
    do {
        CookieData_accf68* cookie;
        if (!Fn008f6e9a(address, &cookie, index)) {
            break;
        }
        uint32_t count = cookie->mPairs.size();
        for (uint32_t k = 0; k < count; ++k) {
            Pair_accf68& pair = cookie->mPairs[k];
            const char* name = pair.mName.c_str();
            if (OB_STRICMP_accf68(name, "comment") == 0 || OB_STRICMP_accf68(name, "commenturl") == 0
                || OB_STRICMP_accf68(name, "discard") == 0 || OB_STRICMP_accf68(name, "expires") == 0
                || OB_STRICMP_accf68(name, "max-age") == 0 || OB_STRICMP_accf68(name, "secure") == 0
                || (OB_STRICMP_accf68(name, "version") == 0 && sawVersion)) {
                continue;
            }
            if (index > 0 || k > 0) {
                out.append("; ");
            }
            if (OB_STRICMP_accf68(name, "domain") == 0) {
                out.push_back('$');
            } else if (OB_STRICMP_accf68(name, "path") == 0) {
                out.push_back('$');
            } else if (OB_STRICMP_accf68(name, "port") == 0) {
                out.push_back('$');
            } else if (OB_STRICMP_accf68(name, "version") == 0) {
                if (out.size() != 0) {
                    std::string first;
                    first.push_back('$');
                    first.append(pair.mName);
                    first.push_back('=');
                    first.append(pair.mValue);
                    first.append("; ");
                    out.insert(0, first);
                    out.resize(out.size() - 2, 0);
                    continue;
                }
                out.push_back('$');
                sawVersion = true;
            }
            out.append(pair.mName);
            out.push_back('=');
            out.append(pair.mValue);
        }
        ++index;
    } while (index < 1000);
    return out.size() != 0;
}

// FUNCTION: 0x008f94f9
bool cRZCookieManager::ParseCookieText(void* cookieArg, void* address)
{
    Guard_accf68 guard(LockOf_accf68(this));
    CookieData_accf68* cookie = static_cast<CookieData_accf68*>(cookieArg);
    const cRZString* url = static_cast<const cRZString*>(address);
    std::string items[40];
    Pair_accf68 pair;
    UrlEmpty_accf68 parsedUrl;
    uint32_t now = static_cast<uint32_t>(time(0));
    if (url != 0) {
        parsedUrl.SetFullURL(url, true);
    }
    PairVec_accf68* pairs = &cookie->mPairs;
    pairs->Erase(pairs->mpBegin, pairs->mpEnd);
    cookie->mComment.erase();
    cookie->mCommentURL.erase();
    cookie->mDomain.erase();
    cookie->mPath.erase();
    cookie->mnVersion = 0;
    cookie->mnExpires = 2;
    cookie->mnPorts[0] = 0;
    cookie->mbSecure = 0;
    uint32_t count = Fn00819290(&cookie->mText, items, 40, true, ';', true);
    for (uint32_t i = 0; i < count; ++i) {
        uint32_t position = items[i].find("=", 0);
        if (position < items[i].size()) {
            pair.mName.assign(items[i].c_str(), position);
            pair.mValue.assign(items[i].c_str() + (position + 1), items[i].size() - position - 1);
        } else {
            pair.mName = items[i];
            pair.mValue.erase();
        }
        pairs->PushBack(pair);
    }
    uint32_t pairCount = pairs->size();
    for (uint32_t k = 0; k < pairCount; ++k) {
        std::string& value = (*pairs)[k].mValue;
        const char* name = (*pairs)[k].mName.c_str();
        if (OB_STRICMP_accf68(name, "Comment") == 0) {
            cookie->mComment = value;
        } else if (OB_STRICMP_accf68(name, "CommentURL") == 0) {
            cookie->mCommentURL = value;
        } else if (OB_STRICMP_accf68(name, "Domain") == 0) {
            cookie->mDomain = value;
            if (cookie->mDomain.size() != 0 && cookie->mDomain[0] != '.') {
                cookie->mDomain.insert(static_cast<std::string::size_type>(0), static_cast<std::string::size_type>(1), '.');
            }
        } else if (OB_STRICMP_accf68(name, "Path") == 0) {
            cookie->mPath = value;
        } else if (OB_STRICMP_accf68(name, "Secure") == 0) {
            cookie->mbSecure = 1;
        } else if (OB_STRICMP_accf68(name, "Version") == 0) {
            cookie->mnVersion = atoi(value.c_str());
        } else if (OB_STRICMP_accf68(name, "Discard") == 0) {
            cookie->mnExpires = 1;
        } else if (OB_STRICMP_accf68(name, "Expires") == 0) {
            cRZString text;
            RZStringFromStd(value, text);
            cookie->mnExpires = Fn00818bd0(&text);
            if (cookie->mnExpires == 0) {
                cookie->mnExpires = now + 86400;
            }
        } else if (OB_STRICMP_accf68(name, "Max-Age") == 0) {
            cookie->mnExpires = atoi(value.c_str()) + now;
        } else if (OB_STRICMP_accf68(name, "Port") == 0) {
            std::string parts[16];
            uint32_t partCount = Fn00819290(&value, parts, 16, false, ',', true);
            if (partCount != 0) {
                uint32_t j;
                j = 0;
                while (j < partCount - 1) {
                    cookie->mnPorts[j] = atoi(parts[j].c_str());
                    ++j;
                }
                cookie->mnPorts[j] = 0;
            } else {
                uint32_t port = 0x50;
                if (url != 0 && parsedUrl.GetPort() != 0) {
                    port = parsedUrl.GetPort();
                }
                cookie->mnPorts[1] = 0;
                cookie->mnPorts[0] = port;
            }
        }
    }
    if (cookie->mDomain.size() == 0) {
        if (url != 0) {
            const cRZString* serverName = parsedUrl.GetServer();
            Fn0090f31b(serverName, &cookie->mDomain);
            if (cookie->mDomain.size() != 0) {
                if (cookie->mDomain[0] != '.') {
                    while (cookie->mDomain.size() != 0 && cookie->mDomain[0] != '.') {
                        cookie->mDomain.erase(0, 1);
                    }
                }
            }
        }
        if (cookie->mDomain.size() != 0) {
            cookie->mText.append("; Domain=");
            cookie->mText.append(cookie->mDomain);
        }
    }
    if (cookie->mPath.size() == 0) {
        if (url != 0) {
            const cRZString* absolutePath = parsedUrl.GetAbsolutePath();
            Fn0090f31b(absolutePath, &cookie->mPath);
        } else {
            cookie->mPath.assign(1, '/');
        }
        if (cookie->mPath.size() != 0) {
            cookie->mText.append("; Path=");
            cookie->mText.append(cookie->mPath);
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x008fa054 score 197
bool cRZCookieManager::AddCookie(void* cookieArg, void* address)
{
    Guard_accf68 guard(LockOf_accf68(this));
    CookieData_accf68* cookie = static_cast<CookieData_accf68*>(cookieArg);
    const cRZString* url = static_cast<const cRZString*>(address);
    bool added;
    if (cookie->mPairs.empty()) {
        if (cookie->mText.size() != 0) {
            CookieData_accf68 parsed;
            parsed.mText = cookie->mText;
            ParseCookieText(&parsed, address);
            added = AddCookie(&parsed, address);
        } else {
            added = false;
        }
    } else {
        if (url != 0) {
            UrlText_accf68 parsedUrl(*url);
            const cRZString* absolutePath = parsedUrl.GetAbsolutePath();
            std::string path;
            Fn0090f31b(absolutePath, &path);
            if (cookie->mPath.size() == 0 || path.find(cookie->mPath.c_str(), 0, cookie->mPath.size()) != 0) {
                return false;
            }
            const cRZString* serverName = parsedUrl.GetServer();
            std::string server;
            Fn0090f31b(serverName, &server);
            if (cookie->mDomain.size() < 3
                || (cookie->mDomain.size() != 0 && cookie->mDomain[cookie->mDomain.size() - 1] == '.')) {
                return false;
            }
            if (cookie->mDomain.find('.', 0) >= cookie->mDomain.size()) {
                return false;
            }
            if (cookie->mDomain[0] == '.' && cookie->mDomain.find('.', 1) >= cookie->mDomain.size()) {
                return false;
            }
            if (cookie->mDomain.size() == 0) {
                return false;
            }
            uint32_t at = server.find(cookie->mDomain.c_str(), 0, cookie->mDomain.size());
            if (at >= server.size() || at != server.size() - cookie->mDomain.size() || server.find('.', 0) < at) {
                return false;
            }
            uint32_t port = parsedUrl.GetPort();
            if (port == 0) {
                port = 0x50;
            }
            if (!Fn008f6813(port, cookie)) {
                return false;
            }
        }
        Cookies_accf68* cookies = CookiesOf_accf68(this);
        uint32_t position = GetEquivalentCookieDataIndex(cookie);
        if (position < cookies->size()) {
            cookies->EraseOne(cookies->mpBegin + position);
        }
        uint32_t expires = cookie->mnExpires;
        if (expires > static_cast<uint32_t>(time(0)) || expires == 2) {
            if (cookies->size() >= mnMaxCookies) {
                RemoveOldestCookies(4, 0);
            }
            cookies->PushBack(cookie);
            added = true;
        } else {
            added = false;
        }
    }
    return added;
}
#endif
