#include "classes/cSC4App.h"
#include "classes/cSC4NeighborDeal.h"
#include "game/Globals.h"

#include <cstring>
#include <new>

// Views of objects reached through pointers: only the slots used here are named (PadNN keeps the numbering).
struct Sink_a86878 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Put(const void* data);
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
};

struct Sub_a86878 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Run();
};

struct Prefs_a86878 {
    char pad0[0x69];
    uint8_t mbAudioEnabled;
    char pad1[0x43a];
    uint8_t mbPauseOnFocusLoss;
};

struct Service_a86878 {
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
    virtual void Notify(uint32_t a, uint32_t b);
};

struct MainWin_a86878 {
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
    virtual void ChildAdd(void* child);
    virtual void Pad15();
    virtual void ChildRemove(void* child);
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
    virtual void Pad51();
    virtual void Pad52();
    virtual void Pad53();
    virtual void Pad54();
    virtual void Pad55();
    virtual void Pad56();
    virtual void Pad57();
    virtual void Pad58();
    virtual void Pad59();
    virtual void Pad60();
    virtual void Pad61();
    virtual void Pad62();
    virtual void Pad63();
    virtual void Pad64();
    virtual void Pad65();
    virtual void Pad66();
    virtual void Pad67();
    virtual void Pad68();
    virtual void ShowWindow();
};

struct Director_a86878 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void OnStart(void* com);
};

struct Process_a86878 {
    // STUB: 0x0090e0d4
    void AddDirector(Director_a86878* director);
};

struct WinSC4AppCtor_a86878 {
    // STUB: 0x004e0ee0
    void* Construct(void* app);
};

// STUB: 0x0087b212
Process_a86878* Fn0087b212();

// STUB: 0x0090ddf1
void* Fn0090ddf1();

// STUB: 0x00460f80
Director_a86878* Fn00460f80();

// STUB: 0x004ecd60
Director_a86878* Fn004ecd60();

// STUB: 0x008f677c
Director_a86878* Fn008f677c();

// STUB: 0x005f91c0
void SC4GamePause(uint32_t pause, bool a, bool b, bool c, bool d);

struct Service2_a86878 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Find(uint32_t classId, uint32_t interfaceId, void** out);
};

// STUB: 0x00913d22
Service_a86878* Fn00913d22();

// FUNCTION: 0x004499d0
void Fn004499d0(uint32_t a, uint32_t b)
{
    Service_a86878* service = Fn00913d22();
    if (service) {
        service->Notify(b, a);
    }
}

// FUNCTION: 0x004497c0
void OB_STDCALL Fn004497c0(const uint8_t* first, const uint8_t* last, uint8_t* dest)
{
    while (first != last) {
        *dest = *first;
        ++first;
        ++dest;
    }
}

// FUNCTION: 0x0044b490
void* cUnk00ac31e4::Slot03_ac3154()
{
    return this;
}

// FUNCTION: 0x0044b4a0
void cSC4App::Slot35_a86878()
{
    static_cast<Sub_a86878*>(mpField54)->Run();
}

// FUNCTION: 0x00449dc0
void cSC4NeighborDeal::Slot24_ab1cb0(void* sink)
{
    static_cast<Sink_a86878*>(sink)->Put(*reinterpret_cast<void* const*>(mStartDate + 4));
}

// FUNCTION: 0x00449de0
void cSC4App::Slot51_a86878(void* sink)
{
    static_cast<Sink_a86878*>(sink)->Put(mString78.c_str());
}

// FUNCTION: 0x00449e00
void cSC4App::Slot52_a86878(void* sink)
{
    static_cast<Sink_a86878*>(sink)->Put(mString8c.c_str());
}

// FUNCTION: 0x00449e20
void cSC4App::Slot55_a86878(void* sink)
{
    static_cast<Sink_a86878*>(sink)->Put(mStringC8.c_str());
}

// FUNCTION: 0x00449e40
void cSC4App::Slot56_a86878(void* sink)
{
    static_cast<Sink_a86878*>(sink)->Put(mStringDC.c_str());
}

// FUNCTION: 0x00449e60
void cSC4App::Slot57_a86878(void* sink)
{
    static_cast<Sink_a86878*>(sink)->Put(mString104.c_str());
}

// FUNCTION: 0x00449e80
void cSC4App::Slot58_a86878(void* sink)
{
    static_cast<Sink_a86878*>(sink)->Put(mString118.c_str());
}

// FUNCTION: 0x00449320
void cSC4App::Slot18_a86878(uint32_t value)
{
    static_cast<Prefs_a86878*>(mpPreferences)->mbPauseOnFocusLoss = static_cast<uint8_t>(value);
    mbPauseOnFocusLoss = static_cast<uint8_t>(value);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00449340 score 17
void cSC4App::GainLoseFocus(uint32_t gained)
{
    if (mbPauseOnFocusLoss) {
        gained = (static_cast<uint8_t>(gained) == 0);
        if (mbGamePaused != static_cast<uint8_t>(gained)) {
            FullGamePause(gained);
        }
    }
}
#endif

// FUNCTION: 0x00449380
void cSC4App::FullGamePause(uint32_t pause)
{
    if (mbGamePaused != static_cast<uint8_t>(pause)) {
        mbGamePaused = static_cast<uint8_t>(pause);
        SC4GamePause(pause, true, true, true, true);
    }
}

// FUNCTION: 0x00449470
bool cSC4App::WindowShutdown()
{
    if (mpWinSC4App) {
        static_cast<MainWin_a86878*>(mpMainWindow)->ChildRemove(mpWinSC4App);
        mpWinSC4App = 0;
    }
    mpMainWindow = 0;
    return true;
}

// FUNCTION: 0x00449420
bool cSC4App::WindowSetup()
{
    if (!mpWinSC4App) {
        WinSC4AppCtor_a86878* memory = static_cast<WinSC4AppCtor_a86878*>(::operator new(0x158));
        void* window;
        if (memory) {
            window = memory->Construct(this);
        } else {
            window = 0;
        }
        mpWinSC4App = window;
        static_cast<MainWin_a86878*>(mpMainWindow)->ChildAdd(window);
    }
    static_cast<MainWin_a86878*>(mpMainWindow)->ShowWindow();
    return true;
}

// FUNCTION: 0x004493b0
void cSC4App::AddCOMDirectors()
{
    Process_a86878* process = Fn0087b212();
    void* com = Fn0090ddf1();
    Director_a86878* director = Fn00460f80();
    process->AddDirector(director);
    director->OnStart(com);
    if (static_cast<Prefs_a86878*>(mpPreferences)->mbAudioEnabled) {
        director = Fn004ecd60();
        process->AddDirector(director);
        director->OnStart(com);
    }
    director = Fn008f677c();
    process->AddDirector(director);
    director->OnStart(com);
}

// FUNCTION: 0x00449ea0
void cSC4App::Slot59_a86878(void* sink)
{
    if (mString12c.empty()) {
        cIGZString* path = &mString12c;
        Slot58_a86878(path);
        path->Append("Plugins", 7);
        path->Append("\\", 1);
    }
    static_cast<Sink_a86878*>(sink)->Put(mString12c.c_str());
}

// FUNCTION: 0x00449f00
void cSC4App::Slot60_a86878(void* sink)
{
    if (mString140.empty()) {
        cIGZString* path = &mString140;
        Slot58_a86878(path);
        path->Append("Regions", 7);
        path->Append("\\", 1);
    }
    static_cast<Sink_a86878*>(sink)->Put(mString140.c_str());
}

// FUNCTION: 0x00449f60
void cSC4App::Slot61_a86878(void* sink)
{
    if (mString154.empty()) {
        cIGZString* path = &mString154;
        Slot58_a86878(path);
        path->Append("MySim", 5);
        path->Append("\\", 1);
    }
    static_cast<Sink_a86878*>(sink)->Put(mString154.c_str());
}

// FUNCTION: 0x00449fc0
void cSC4App::Slot62_a86878(void* sink)
{
    if (mAlbumDirectory.empty()) {
        cIGZString* path = &mAlbumDirectory;
        Slot58_a86878(path);
        path->Append("Albums", 6);
        path->Append("\\", 1);
    }
    static_cast<Sink_a86878*>(sink)->Put(mAlbumDirectory.c_str());
}

// FUNCTION: 0x0044a020
void cSC4App::Slot63_a86878(void* sink)
{
    if (mHTTPCacheDirectory.empty()) {
        cIGZString* path = &mHTTPCacheDirectory;
        Slot58_a86878(path);
        path->Append("HTTPCache", 9);
        path->Append("\\", 1);
    }
    static_cast<Sink_a86878*>(sink)->Put(mHTTPCacheDirectory.c_str());
}

// FUNCTION: 0x0044a080
void cSC4App::Slot64_a86878(void* sink)
{
    if (mTempDirectory.empty()) {
        cIGZString* path = &mTempDirectory;
        Slot58_a86878(path);
        path->Append("Temp", 4);
        path->Append("\\", 1);
    }
    static_cast<Sink_a86878*>(sink)->Put(mTempDirectory.c_str());
}

// FUNCTION: 0x0044a0e0
void cSC4App::Slot65_a86878(void* sink)
{
    if (mExceptionReportsDirectory.empty()) {
        cIGZString* path = &mExceptionReportsDirectory;
        Slot58_a86878(path);
        path->Append("Exception Reports", 17);
        path->Append("\\", 1);
    }
    static_cast<Sink_a86878*>(sink)->Put(mExceptionReportsDirectory.c_str());
}

// FUNCTION: 0x0044a140
void cSC4App::Slot66_a86878(void* sink)
{
    if (mString1b8.empty()) {
        cIGZString* path = &mString1b8;
        Slot53_a86878(path, -1);
        path->Append("Scripts", 7);
        path->Append("\\", 1);
        path->Append("TestScripts", 11);
        path->Append("\\", 1);
    }
    static_cast<Sink_a86878*>(sink)->Put(mString1b8.c_str());
}

// FUNCTION: 0x0044a900
void cSC4App::Slot28_a86878(void* sink)
{
    if (mString64.size() != 0) {
        Sink_a86878* out = static_cast<Sink_a86878*>(sink);
        out->Put(mString64.c_str());
        static_cast<cIGZString*>(sink)->Append(".ini", 4);
    } else {
        static_cast<Sink_a86878*>(sink)->Put("SimCity 4.ini");
    }
}

// FUNCTION: 0x0044a940
void cSC4App::Slot30_a86878(void* sink)
{
    if (mString64.size() != 0) {
        Sink_a86878* out = static_cast<Sink_a86878*>(sink);
        out->Put(mString64.c_str());
        static_cast<cIGZString*>(sink)->Append(".cfg", 4);
    } else {
        static_cast<Sink_a86878*>(sink)->Put("SimCity 4.cfg");
    }
}

// A node of the list at +0x5c0: links, then a pair of values.
struct Node_a86878 {
    Node_a86878* mpNext;
    Node_a86878* mpPrev;
    uint32_t mnFirst;
    uint32_t mnSecond;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* block);

// STUB: 0x00449780
void Fn00449780(Node_a86878** out, Node_a86878* first, Node_a86878* last, const uint32_t* key, const uint32_t* unused);

// STUB: 0x008793ec
Service2_a86878* Fn008793ec();

struct ServiceRef_a86878 {
    void* mpService;
    // STUB: 0x004495c0
    void Release_4495c0();
    ServiceRef_a86878* Fn00449560();
    ServiceRef_a86878* Fn00449590();
    ServiceRef_a86878* Fn00449690();
    ServiceRef_a86878* Fn004496c0();
    ServiceRef_a86878* Fn004496f0();
    ServiceRef_a86878* Fn00449750();
};

// FUNCTION: 0x00449560
ServiceRef_a86878* ServiceRef_a86878::Fn00449560()
{
    mpService = 0;
    Service2_a86878* service = Fn008793ec();
    if (service) {
        service->Find(0xc416025c, 0x73283c, &mpService);
    }
    return this;
}

// FUNCTION: 0x00449590
ServiceRef_a86878* ServiceRef_a86878::Fn00449590()
{
    mpService = 0;
    Service2_a86878* service = Fn008793ec();
    if (service) {
        service->Find(0xc416025c, 0xc47b747c, &mpService);
    }
    return this;
}

// FUNCTION: 0x00449690
ServiceRef_a86878* ServiceRef_a86878::Fn00449690()
{
    mpService = 0;
    Service2_a86878* service = Fn008793ec();
    if (service) {
        service->Find(0x04fa845b, 0x652294c7, &mpService);
    }
    return this;
}

// FUNCTION: 0x004496c0
ServiceRef_a86878* ServiceRef_a86878::Fn004496c0()
{
    mpService = 0;
    Service2_a86878* service = Fn008793ec();
    if (service) {
        service->Find(0x056b906e, 0x656b8efc, &mpService);
    }
    return this;
}

// FUNCTION: 0x004496f0
ServiceRef_a86878* ServiceRef_a86878::Fn004496f0()
{
    mpService = 0;
    Service2_a86878* service = Fn008793ec();
    if (service) {
        service->Find(0x4bd10133, 0x4bd10129, &mpService);
    }
    return this;
}

// FUNCTION: 0x00449750
ServiceRef_a86878* ServiceRef_a86878::Fn00449750()
{
    mpService = 0;
    Service2_a86878* service = Fn008793ec();
    if (service) {
        service->Find(0x5a356e15, 0xfa3562fa, &mpService);
    }
    return this;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00449780 score 26
void Fn00449780Draft_a86878(Node_a86878** out, Node_a86878* first, Node_a86878* last, const uint32_t* key, const uint32_t* unused)
{
    if (first != last) {
        uint32_t value = key[0];
        do {
            if (value == first->mnFirst && key[1] == first->mnSecond) {
                break;
            }
            first = first->mpNext;
        } while (first != last);
    }
    *out = first;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0044a980 score 42
bool cSC4App::Slot70_a86878(uint32_t first, uint32_t second)
{
    uint32_t key[2];
    key[0] = first;
    key[1] = second;
    Node_a86878* found;
    Node_a86878* head = static_cast<Node_a86878*>(mpList5cc);
    Fn00449780(&found, head->mpNext, head, key, key);
    if (found != mpList5cc) {
        Node_a86878* next = found->mpNext;
        Node_a86878* prev = found->mpPrev;
        prev->mpNext = next;
        next->mpPrev = prev;
        Fn0090cf63(found);
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x0044d7f0
void Fn0044d7f0(void* name, void* style, cSC4App* app)
{
    app->SetFontStyle(name, style);
}

struct Settings_a86878 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Set(uint32_t index, uint32_t value);
    virtual uint32_t Get(uint32_t index);
};

struct Message_a86878 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual uint32_t GetType();
};

struct Msg2_a86878 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void SetType(uint32_t type);
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void SetData1(uint32_t value);
    virtual void SetVoid1(void* value);
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void SetData2(uint32_t value);
    virtual void Pad17();
    virtual void Pad18();
    virtual void Pad19();
    virtual void Pad20();
    virtual void SetData3(uint32_t value);
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
    virtual void SetIGZUnknown(void* value);
};

struct Manager_a86878 {
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
    virtual void Pad38();
    virtual void Pad39();
    virtual void Pad40();
    virtual void Pad41();
    virtual void Pad42();
    virtual void Refresh();
};

struct Timer_a86878 {
    // STUB: 0x00890198
    uint32_t GetElapsedTime() const;
    // STUB: 0x0089058f
    void Restart();
    // STUB: 0x0089045a
    void Fn0089045a(uint32_t value, uint32_t flag);
};

struct Msg2Ctor_a86878 {
    // STUB: 0x009134d6
    Msg2_a86878* Construct();
};

struct Out_a86878 {
    uint8_t mb0;
    uint8_t mb1;
    uint8_t mb2;
    uint8_t mb3;
    uint8_t mb4;
    uint8_t mb5;
    uint8_t mb6;
    uint8_t mb7;
    uint8_t mb8;
    uint8_t mb9;
    uint8_t mba;
    uint8_t mbb;
    uint8_t mbc;
    uint8_t pad[3];
    uint32_t mnWidth;
    uint32_t mnHeight;
    uint32_t mnDepth;
    uint8_t mb1c;
};

// STUB: 0x009133da
void* Fn009133da(uint32_t size);

// STUB: 0x009205a0
void Fn009205a0(uint32_t value);

// GLOBAL: 0x00b43ca8
extern Manager_a86878* gpB43ca8;

struct PixFmt_a86878 {
    uint32_t mnFormat;
    uint32_t mnConverted;
    PixFmt_a86878* Fn0044a490(uint32_t format);
};

// STUB: 0x00449500
uint32_t OB_STDCALL Fn00449500(uint32_t format);

// FUNCTION: 0x0044a490
PixFmt_a86878* PixFmt_a86878::Fn0044a490(uint32_t format)
{
    mnFormat = format;
    mnConverted = Fn00449500(format);
    return this;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00449af0 score 15
void OB_STDCALL PostCityMessage(void* city, uint32_t type, uint32_t data2, uint32_t data3, bool post)
{
    cIGZMessageServer2* server = gpB43ccc;
    if (server) {
        void* memory = Fn009133da(0x2c);
        Msg2_a86878* message;
        if (memory) {
            message = static_cast<Msg2Ctor_a86878*>(memory)->Construct();
        } else {
            message = 0;
        }
        if (message) {
            message->AddRef();
        }
        message->SetType(type);
        message->SetVoid1(city);
        message->SetIGZUnknown(city);
        message->SetData2(data2);
        message->SetData3(data3);
        if (post) {
            server->MessagePost(message, false);
            message->Release();
            return;
        }
        server->MessageSend(message);
        message->Release();
    }
}
#endif

// FUNCTION: 0x00449250
bool cSC4App::QueryInterface(unsigned int iid, void** ppv)
{
    if (iid == 0xe98b2f57) {
        *ppv = this;
        AddRef();
        return true;
    }
    if (iid == 0x452294aa) {
        *ppv = static_cast<cSC4App_4*>(this);
        AddRef();
        return true;
    }
    if (iid == 0xc6ae7085) {
        *ppv = static_cast<cSC4App_8*>(this);
        AddRef();
        return true;
    }
    if (iid == 0x26ce01c0) {
        *ppv = static_cast<cUnk00a86878*>(this);
        AddRef();
        return true;
    }
    if (iid == 0xca263481) {
        *ppv = this;
        AddRef();
        return true;
    }
    return cUnk00ac31e4::QueryInterface(iid, ppv);
}

// The subobject at +4 seen as bytes: its state and a timer; the whole application is 4 bytes before it.
struct View4_a86878 {
    char pad0[0x40];
    uint32_t mnMode;
    char pad1[0x330];
    uint8_t mTimer374[0x18];
};

#define APP_OF_a86878(p) reinterpret_cast<cSC4App*>(reinterpret_cast<char*>(p) - 4)

// FUNCTION: 0x00451ed0
bool cSC4App_4::Slot03_a86c2c_4(void* message)
{
    View4_a86878* self = reinterpret_cast<View4_a86878*>(this);
    switch (static_cast<Message_a86878*>(message)->GetType()) {
    case 0x26d31ec2:
    case 0x8bb5bb46:
        self->mnMode = 0;
        break;
    case 0x231bbf91:
        APP_OF_a86878(self)->DoPreferencesChanged(false);
        break;
    case 0x29a89b05:
        APP_OF_a86878(self)->Quit();
        break;
    case 0x0b627ad3:
    case 0x49a780b2:
        APP_OF_a86878(self)->Fn0044e980();
        break;
    case 0xcbb5bb45:
        self->mnMode = 1;
        break;
    case 0xba44eb51:
        if (gpB43ca8) {
            gpB43ca8->Refresh();
        }
        break;
    case 0xea65224e:
        APP_OF_a86878(self)->DoCityObliteration();
        break;
    case 0xea8ae29a:
        self->mnMode = 2;
        break;
    case 0x7a104750:
    case 0xfa0c6390:
        reinterpret_cast<Timer_a86878*>(self->mTimer374)->Restart();
        break;
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00449c70 score 27
bool cSC4App::Slot03_a86878(uint32_t)
{
    Timer_a86878* heartbeat = reinterpret_cast<Timer_a86878*>(mTimer360);
    if (heartbeat->GetElapsedTime() > 1000) {
        heartbeat->Restart();
        Timer_a86878* window = reinterpret_cast<Timer_a86878*>(mTimer390);
        uint32_t elapsed;
        bool send;
        if (window->GetElapsedTime() >= 300) {
            reinterpret_cast<Timer_a86878*>(mTimer378)->Restart();
            elapsed = 60;
            send = true;
        } else {
            Timer_a86878* steady = reinterpret_cast<Timer_a86878*>(mTimer378);
            elapsed = steady->GetElapsedTime();
            if (elapsed > mnLimit3a8) {
                steady->Fn0089045a(mnLimit3a8 - mnLimit3ac, 0);
                send = true;
            } else {
                send = false;
            }
        }
        if (send) {
            window->Restart();
            cIGZMessageServer2* server = gpB43ccc;
            if (server) {
                void* memory = Fn009133da(0x2c);
                Msg2_a86878* message;
                if (memory) {
                    message = static_cast<Msg2Ctor_a86878*>(memory)->Construct();
                } else {
                    message = 0;
                }
                if (message) {
                    message->AddRef();
                }
                message->SetType(0xba44eb51);
                message->SetData1(elapsed);
                server->MessagePost(message, false);
                message->Release();
            }
        }
        Timer_a86878* autosave = reinterpret_cast<Timer_a86878*>(mTimer320);
        if (autosave->GetElapsedTime() > mnLimit338) {
            autosave->Restart();
            Slot17_a86878();
        }
        Timer_a86878* refresh = reinterpret_cast<Timer_a86878*>(mTimer340);
        if (refresh->GetElapsedTime() > mnLimit358) {
            refresh->Restart();
            if (gpB43ca8) {
                gpB43ca8->Refresh();
            }
        }
    }
    if (mbGamePaused) {
        Fn009205a0(0x3d090);
    }
    return false;
}
#endif

// FUNCTION: 0x0044a330
void cSC4App::Slot20_a86878(void* destination)
{
    Out_a86878* out = static_cast<Out_a86878*>(destination);
    out->mb1 = static_cast<Settings_a86878*>(mpPreferences634)->Get(0);
    out->mb2 = static_cast<Settings_a86878*>(mpPreferences634)->Get(1);
    out->mb3 = static_cast<Settings_a86878*>(mpPreferences634)->Get(2);
    out->mb4 = static_cast<Settings_a86878*>(mpPreferences634)->Get(3);
    out->mb7 = static_cast<Settings_a86878*>(mpPreferences634)->Get(6);
    out->mb5 = static_cast<Settings_a86878*>(mpPreferences634)->Get(4);
    out->mb6 = static_cast<Settings_a86878*>(mpPreferences634)->Get(5);
    out->mb9 = static_cast<Settings_a86878*>(mpPreferences634)->Get(8);
    out->mb8 = static_cast<Settings_a86878*>(mpPreferences634)->Get(7);
    out->mba = static_cast<Settings_a86878*>(mpPreferences634)->Get(9);
    out->mbc = static_cast<Settings_a86878*>(mpPreferences634)->Get(10);
    out->mbb = 1;
    out->mb1c = static_cast<Settings_a86878*>(mpPreferences634)->Get(15);
    switch (static_cast<Settings_a86878*>(mpPreferences634)->Get(11)) {
    case 0:
        out->mnWidth = 800;
        out->mnHeight = 600;
        break;
    case 1:
        out->mnWidth = 1024;
        out->mnHeight = 768;
        break;
    case 2:
        out->mnWidth = 1280;
        out->mnHeight = 1024;
        break;
    case 3:
        out->mnWidth = 1600;
        out->mnHeight = 1200;
        break;
    }
    switch (static_cast<Settings_a86878*>(mpPreferences634)->Get(12)) {
    case 0:
        out->mnDepth = 16;
        break;
    case 1:
        out->mnDepth = 32;
        break;
    }
}

// FUNCTION: 0x0044a1c0
void cSC4App::Slot19_a86878(void* source)
{
    const Out_a86878* in = static_cast<const Out_a86878*>(source);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(0, in->mb1);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(1, in->mb2);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(2, in->mb3);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(3, in->mb4);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(6, in->mb7);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(4, in->mb5);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(5, in->mb6);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(8, in->mb9);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(7, in->mb8);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(9, in->mba);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(10, in->mbc);
    static_cast<Settings_a86878*>(mpPreferences634)->Set(15, in->mb1c);
    ServiceRef_a86878 server;
    server.Fn00449690();
    if (server.mpService) {
        void* memory = Fn009133da(0x2c);
        Msg2_a86878* message;
        if (memory) {
            message = static_cast<Msg2Ctor_a86878*>(memory)->Construct();
        } else {
            message = 0;
        }
        if (message) {
            message->AddRef();
        }
        message->SetType(0xc9f775bb);
        static_cast<cIGZMessageServer2*>(server.mpService)->MessagePost(message, false);
        message->Release();
    }
    server.Release_4495c0();
}

struct CommandLine_a86878 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual bool GetValue(cRZString* name, cRZString* value, bool flag);
};

struct Framework_a86878 {
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
    virtual CommandLine_a86878* GetCommandLine();
};

// STUB: 0x008793ec
Framework_a86878* Fn008793ecFramework();

// FUNCTION: 0x0044ba80
bool OB_STDCALL IsStartupResolutionOK(uint32_t width, uint32_t height)
{
    cRZString value;
    cRZString name("CustomResolution");
    if (Fn008793ecFramework()->GetCommandLine()->GetValue(&name, &value, true)) {
        value.MakeLower();
        if (value == "on" || value == "enabled") {
            return true;
        }
    }
    if (height < 600) {
        return false;
    }
    if (width >= 800 && height == 600) {
        return true;
    }
    if (width >= 1024 && height == 768) {
        return true;
    }
    if (width >= 1152 && height == 864) {
        return true;
    }
    if (width >= 1280 && height == 1024) {
        return true;
    }
    if (width >= 1600 && height == 1200) {
        return true;
    }
    if (width >= 1800 && height == 1440) {
        return true;
    }
    if (width >= 2048 && height == 1536) {
        return true;
    }
    return false;
}

// FUNCTION: 0x00449ba0
void cSC4App::PostSC4AppMessage(uint32_t type, bool post)
{
    ServiceRef_a86878 server;
    server.Fn00449690();
    if (server.mpService) {
        void* memory = Fn009133da(0x2c);
        Msg2_a86878* message;
        if (memory) {
            message = static_cast<Msg2Ctor_a86878*>(memory)->Construct();
        } else {
            message = 0;
        }
        if (message) {
            message->AddRef();
        }
        message->SetType(type);
        message->SetVoid1(static_cast<cUnk00a86878*>(this));
        message->SetIGZUnknown(static_cast<cUnk00a86878*>(this));
        if (post) {
            static_cast<cIGZMessageServer2*>(server.mpService)->MessagePost(message, false);
        } else {
            static_cast<cIGZMessageServer2*>(server.mpService)->MessageSend(message);
        }
        message->Release();
    }
    server.Release_4495c0();
}

// FUNCTION: 0x0044d6a0
void Fn0044d6a0(cRZString* where, const cRZString* source)
{
    if (where) {
        new (where) cRZString(*source);
    }
}

// A vector of strings (pointers to the first, one past the last, and the end of the storage).
struct StringVec_a86878 {
    cRZString* mpStart;
    cRZString* mpFinish;
    cRZString* mpEnd;

    // STUB: 0x0044eda0
    void InsertOverflow_44eda0(cRZString* position, const cRZString* value, const void* tag, uint32_t count, bool atEnd);
    void PushBack_4522f0(const cRZString* value);
};

#ifdef OB_DRAFTS
// CLOSE: 0x004522f0 score 37
void StringVec_a86878::PushBack_4522f0(const cRZString* value)
{
    if (mpFinish != mpEnd) {
        if (mpFinish) {
            new (mpFinish) cRZString(*value);
        }
        ++mpFinish;
    } else {
        InsertOverflow_44eda0(mpFinish, value, &value, 1, true);
    }
}
#endif

struct File_a86878 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual bool Init();
    virtual void Shutdown();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void SetPath(cRZString* path);
};

struct Segment_a86878 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual bool Open(bool a, bool b);
    virtual void Pad07();
    virtual void Close();
};

struct Record_a86878 {
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
    virtual bool GetFieldVoid(void* data, uint32_t size);
};

struct FileCtor_a86878 {
    // STUB: 0x0097212d
    File_a86878* Construct();
};

struct Preferences_a86878 {
    uint8_t mData[0x1734];
    // STUB: 0x00449070
    Preferences_a86878();
};

struct AutoLoad_a86878 {
    uint32_t mnPad0;
    uint32_t mnPad1;
    Record_a86878* mpRecord;
    uint16_t mnVersion;
    uint16_t mnPad2;

    // STUB: 0x005d9a20
    AutoLoad_a86878(void* segment, uint32_t type, uint32_t group, bool flag);
    // STUB: 0x005d9430
    void Close();
    // STUB: 0x005d9490
    void Release_5d9490();
};

// FUNCTION: 0x0044bc50
void cSC4App::ReadPreferences()
{
    void* memory = ::operator new(0x1c8);
    File_a86878* file;
    if (memory) {
        file = static_cast<FileCtor_a86878*>(memory)->Construct();
    } else {
        file = 0;
    }
    file->AddRef();
    if (file->Init()) {
        cRZString path;
        Slot31_a86878(&path);
        file->SetPath(&path);
        Segment_a86878* segment = reinterpret_cast<Segment_a86878*>(reinterpret_cast<char*>(file) + 4);
        if (segment->Open(true, false)) {
            AutoLoad_a86878 record(segment, 0xa9dd6e06, 0x49dd6e08, true);
            if (record.mpRecord) {
                if (record.mnVersion == 0x15) {
                    Preferences_a86878 loaded;
                    if (record.mpRecord->GetFieldVoid(&loaded, 0x1734)) {
                        std::memcpy(mpPreferences, &loaded, 0x1734);
                        mbFirstRunAfterInstall = 0;
                    }
                }
                record.Close();
            }
            record.Release_5d9490();
            segment->Close();
        }
        file->Shutdown();
    }
    file->Release();
}

#ifdef OB_DRAFTS
// CLOSE: 0x0044b620 score 25
uint32_t cSC4App::Slot36_a86878()
{
    uint32_t* holder = static_cast<uint32_t*>(mpField58);
    if (holder) {
        return *holder;
    }
    return 0;
}
#endif
