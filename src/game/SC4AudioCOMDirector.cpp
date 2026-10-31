#include <stddef.h>

#include "classes/cUnk00a93ff4.h"
#include "classes/cUnk00a93fdc.h"
#include "classes/cUnk00a93fc4.h"
#include "classes/cSC4AudioCOMDirector.h"
#include "classes/cUnk00a937d0.h"
#include "classes/cUnk00a937e8.h"
#include "classes/cUnk00a93800.h"
#include "classes/cUnk00a93818.h"
#include "classes/cUnk00a93830.h"
#include "classes/cUnk00a93848.h"
#include "classes/cUnk00a93860.h"
#include "classes/cUnk00a93878.h"
#include "classes/cUnk00a93890.h"
#include "classes/cUnk00a938a8.h"
#include "classes/cUnk00a938c0.h"
#include "classes/cUnk00a938d8.h"
#include "classes/cUnk00a938f0.h"
#include "classes/cUnk00a93908.h"
#include "classes/cUnk00a93920.h"
#include "classes/cUnk00a93938.h"
#include "classes/cUnk00a93950.h"
#include "classes/cUnk00a93968.h"
#include "classes/cUnk00a93980.h"
#include "classes/cUnk00a93998.h"
#include "classes/cUnk00a939b0.h"
#include "classes/cUnk00a939c8.h"
#include "classes/cUnk00a939e0.h"
#include "classes/cUnk00a939f8.h"
#include "classes/cUnk00a93a10.h"
#include "classes/cUnk00a93a28.h"
#include "classes/cUnk00a93a40.h"
#include "classes/cUnk00a93a58.h"
#include "classes/cUnk00a93a70.h"
#include "classes/cUnk00a93a88.h"
#include "classes/cUnk00a93aa0.h"
#include "classes/cUnk00a93ab8.h"
#include "classes/cUnk00a93ad0.h"
#include "classes/cUnk00a93ae8.h"
#include "classes/cUnk00a93b00.h"
#include "classes/cUnk00a93b18.h"
#include "classes/cUnk00a93b30.h"
#include "classes/cUnk00a93b48.h"
#include "classes/cUnk00a93b60.h"
#include "classes/cUnk00a93b78.h"
#include "classes/cUnk00a93b90.h"
#include "classes/cUnk00a93ba8.h"
#include "classes/cUnk00a93bc0.h"
#include "classes/cUnk00a93bd8.h"
#include "classes/cUnk00a93bf0.h"
#include "classes/cUnk00a93c08.h"
#include "classes/cUnk00a93c20.h"
#include "classes/cUnk00a93c38.h"
#include "classes/cUnk00a93c50.h"
#include "classes/cUnk00a93c68.h"
#include "classes/cUnk00a93c80.h"
#include "classes/cUnk00a93c98.h"
#include "classes/cUnk00a93cb0.h"
#include "classes/cUnk00a93cc8.h"
#include "classes/cUnk00a93ce0.h"
#include "classes/cUnk00a93cf8.h"
#include "classes/cUnk00a93d10.h"
#include "classes/cUnk00a93d28.h"
#include "classes/cUnk00a93d40.h"
#include "classes/cUnk00a93d58.h"
#include "classes/cUnk00a93d70.h"
#include "classes/cUnk00a93d88.h"
#include "classes/cUnk00a93da0.h"
#include "classes/cUnk00a93db8.h"
#include "classes/cUnk00a93dd0.h"
#include "classes/cUnk00a93e5c.h"
#include "classes/cUnk00a93e74.h"
#include "classes/cUnk00a93e8c.h"
#include "classes/cUnk00a93ea4.h"
#include "classes/cUnk00a93ebc.h"
#include "classes/cUnk00a93ed4.h"
#include "classes/cUnk00a93eec.h"
#include "classes/cUnk00a93f04.h"
#include "classes/cUnk00a93f1c.h"
#include "classes/cUnk00a93f34.h"
#include "classes/cUnk00a93f4c.h"
#include "classes/cUnk00a93f64.h"
#include "classes/cUnk00a93f7c.h"
#include "classes/cUnk00a93f94.h"
#include "classes/cUnk00a93fac.h"

// The audio COM director's small ref-counted helper objects: one factory per kind, each building the class of its
// vtable (src/classes; the constructor zeroes the count and the fields the factory sets).
// FUNCTION: 0x004ec3d0
cUnk00a93e5c* Fn004ec3d0()
{
    return new cUnk00a93e5c;
}

// FUNCTION: 0x004ec3f0
cUnk00a93e74* Fn004ec3f0()
{
    return new cUnk00a93e74;
}

// FUNCTION: 0x004ec410
cUnk00a93e8c* Fn004ec410()
{
    return new cUnk00a93e8c;
}

// FUNCTION: 0x004ec430
cUnk00a93ea4* Fn004ec430()
{
    return new cUnk00a93ea4;
}

// FUNCTION: 0x004ec450
cUnk00a93ebc* Fn004ec450()
{
    return new cUnk00a93ebc;
}

// FUNCTION: 0x004ec470
cUnk00a93ed4* Fn004ec470()
{
    return new cUnk00a93ed4;
}

// FUNCTION: 0x004ec490
cUnk00a93eec* Fn004ec490()
{
    return new cUnk00a93eec;
}

// FUNCTION: 0x004ec4b0
cUnk00a93f04* Fn004ec4b0()
{
    return new cUnk00a93f04;
}

// FUNCTION: 0x004ec4d0
cUnk00a93f1c* Fn004ec4d0()
{
    return new cUnk00a93f1c;
}

// FUNCTION: 0x004ec4f0
cUnk00a93f34* Fn004ec4f0()
{
    return new cUnk00a93f34;
}

// FUNCTION: 0x004ec510
cUnk00a93f4c* Fn004ec510()
{
    return new cUnk00a93f4c;
}

// FUNCTION: 0x004ec530
cUnk00a93f64* Fn004ec530()
{
    return new cUnk00a93f64;
}

// FUNCTION: 0x004ec550
cUnk00a93f7c* Fn004ec550()
{
    return new cUnk00a93f7c;
}

// FUNCTION: 0x004ec570
cUnk00a93f94* Fn004ec570()
{
    return new cUnk00a93f94;
}

// FUNCTION: 0x004ec590
cUnk00a93fac* Fn004ec590()
{
    return new cUnk00a93fac;
}

// FUNCTION: 0x004ec6f0
cUnk00a93ff4* Fn004ec6f0()
{
    return new cUnk00a93ff4;
}

// FUNCTION: 0x004eb260
cUnk00a937d0* Fn004eb260()
{
    return new cUnk00a937d0;
}

// FUNCTION: 0x004eb290
cUnk00a937e8* Fn004eb290()
{
    return new cUnk00a937e8;
}

// FUNCTION: 0x004eb2c0
cUnk00a93800* Fn004eb2c0()
{
    return new cUnk00a93800;
}

// FUNCTION: 0x004eb2f0
cUnk00a93818* Fn004eb2f0()
{
    return new cUnk00a93818;
}

// FUNCTION: 0x004eb320
cUnk00a93830* Fn004eb320()
{
    return new cUnk00a93830;
}

// FUNCTION: 0x004eb350
cUnk00a93848* Fn004eb350()
{
    return new cUnk00a93848;
}

// FUNCTION: 0x004eb380
cUnk00a93860* Fn004eb380()
{
    return new cUnk00a93860;
}

// FUNCTION: 0x004eb3b0
cUnk00a93878* Fn004eb3b0()
{
    return new cUnk00a93878;
}

// FUNCTION: 0x004eb3e0
cUnk00a93890* Fn004eb3e0()
{
    return new cUnk00a93890;
}

// FUNCTION: 0x004eb410
cUnk00a938a8* Fn004eb410()
{
    return new cUnk00a938a8;
}

// FUNCTION: 0x004eb440
cUnk00a938c0* Fn004eb440()
{
    return new cUnk00a938c0;
}

// FUNCTION: 0x004eb470
cUnk00a938d8* Fn004eb470()
{
    return new cUnk00a938d8;
}

// FUNCTION: 0x004eb4a0
cUnk00a938f0* Fn004eb4a0()
{
    return new cUnk00a938f0;
}

// FUNCTION: 0x004eb4d0
cUnk00a93908* Fn004eb4d0()
{
    return new cUnk00a93908;
}

// FUNCTION: 0x004eb500
cUnk00a93920* Fn004eb500()
{
    return new cUnk00a93920;
}

// FUNCTION: 0x004eb530
cUnk00a93938* Fn004eb530()
{
    return new cUnk00a93938;
}

// FUNCTION: 0x004eb560
cUnk00a93950* Fn004eb560()
{
    return new cUnk00a93950;
}

// FUNCTION: 0x004eb590
cUnk00a93968* Fn004eb590()
{
    return new cUnk00a93968;
}

// FUNCTION: 0x004eb5c0
cUnk00a93980* Fn004eb5c0()
{
    return new cUnk00a93980;
}

// FUNCTION: 0x004eb5f0
cUnk00a93998* Fn004eb5f0()
{
    return new cUnk00a93998;
}

// FUNCTION: 0x004eb620
cUnk00a939b0* Fn004eb620()
{
    return new cUnk00a939b0;
}

// FUNCTION: 0x004eb650
cUnk00a939c8* Fn004eb650()
{
    return new cUnk00a939c8;
}

// FUNCTION: 0x004eb680
cUnk00a939e0* Fn004eb680()
{
    return new cUnk00a939e0;
}

// FUNCTION: 0x004eb6b0
cUnk00a939f8* Fn004eb6b0()
{
    return new cUnk00a939f8;
}

// FUNCTION: 0x004eb6e0
cUnk00a93a10* Fn004eb6e0()
{
    return new cUnk00a93a10;
}

// FUNCTION: 0x004eb710
cUnk00a93a28* Fn004eb710()
{
    return new cUnk00a93a28;
}

// FUNCTION: 0x004eb740
cUnk00a93a40* Fn004eb740()
{
    return new cUnk00a93a40;
}

// FUNCTION: 0x004eb770
cUnk00a93a58* Fn004eb770()
{
    return new cUnk00a93a58;
}

// FUNCTION: 0x004eb7a0
cUnk00a93a70* Fn004eb7a0()
{
    return new cUnk00a93a70;
}

// FUNCTION: 0x004eb7d0
cUnk00a93a88* Fn004eb7d0()
{
    return new cUnk00a93a88;
}

// FUNCTION: 0x004ec600
cUnk00a93fc4* Fn004ec600()
{
    return new cUnk00a93fc4;
}

// FUNCTION: 0x004eb800
cUnk00a93aa0* Fn004eb800()
{
    return new cUnk00a93aa0;
}

// FUNCTION: 0x004eb830
cUnk00a93ab8* Fn004eb830()
{
    return new cUnk00a93ab8;
}

// FUNCTION: 0x004eb860
cUnk00a93ad0* Fn004eb860()
{
    return new cUnk00a93ad0;
}

// FUNCTION: 0x004eb890
cUnk00a93ae8* Fn004eb890()
{
    return new cUnk00a93ae8;
}

// FUNCTION: 0x004eb8c0
cUnk00a93b00* Fn004eb8c0()
{
    return new cUnk00a93b00;
}

// FUNCTION: 0x004eb8f0
cUnk00a93b18* Fn004eb8f0()
{
    return new cUnk00a93b18;
}

// FUNCTION: 0x004eb920
cUnk00a93b30* Fn004eb920()
{
    return new cUnk00a93b30;
}

// FUNCTION: 0x004eb950
cUnk00a93b48* Fn004eb950()
{
    return new cUnk00a93b48;
}

// FUNCTION: 0x004eb980
cUnk00a93b60* Fn004eb980()
{
    return new cUnk00a93b60;
}

// FUNCTION: 0x004eb9b0
cUnk00a93b78* Fn004eb9b0()
{
    return new cUnk00a93b78;
}

// FUNCTION: 0x004eb9e0
cUnk00a93b90* Fn004eb9e0()
{
    return new cUnk00a93b90;
}

// FUNCTION: 0x004eba10
cUnk00a93ba8* Fn004eba10()
{
    return new cUnk00a93ba8;
}

// FUNCTION: 0x004eba40
cUnk00a93bc0* Fn004eba40()
{
    return new cUnk00a93bc0;
}

// FUNCTION: 0x004ebaa0
cUnk00a93bd8* Fn004ebaa0()
{
    return new cUnk00a93bd8;
}

// FUNCTION: 0x004ebad0
cUnk00a93bf0* Fn004ebad0()
{
    return new cUnk00a93bf0;
}

// FUNCTION: 0x004ebb00
cUnk00a93c08* Fn004ebb00()
{
    return new cUnk00a93c08;
}

// FUNCTION: 0x004ebb30
cUnk00a93c20* Fn004ebb30()
{
    return new cUnk00a93c20;
}

// FUNCTION: 0x004ebb60
cUnk00a93c38* Fn004ebb60()
{
    return new cUnk00a93c38;
}

// FUNCTION: 0x004ebb90
cUnk00a93c50* Fn004ebb90()
{
    return new cUnk00a93c50;
}

// FUNCTION: 0x004ebbc0
cUnk00a93c68* Fn004ebbc0()
{
    return new cUnk00a93c68;
}

// FUNCTION: 0x004ebbf0
cUnk00a93c80* Fn004ebbf0()
{
    return new cUnk00a93c80;
}

// FUNCTION: 0x004ebc20
cUnk00a93c98* Fn004ebc20()
{
    return new cUnk00a93c98;
}

// FUNCTION: 0x004ebc50
cUnk00a93cb0* Fn004ebc50()
{
    return new cUnk00a93cb0;
}

// FUNCTION: 0x004ebc80
cUnk00a93cc8* Fn004ebc80()
{
    return new cUnk00a93cc8;
}

// FUNCTION: 0x004ebcb0
cUnk00a93ce0* Fn004ebcb0()
{
    return new cUnk00a93ce0;
}

// FUNCTION: 0x004ebce0
cUnk00a93cf8* Fn004ebce0()
{
    return new cUnk00a93cf8;
}

// FUNCTION: 0x004ebd10
cUnk00a93d10* Fn004ebd10()
{
    return new cUnk00a93d10;
}

// FUNCTION: 0x004ebd40
cUnk00a93d28* Fn004ebd40()
{
    return new cUnk00a93d28;
}

// FUNCTION: 0x004ebd70
cUnk00a93d40* Fn004ebd70()
{
    return new cUnk00a93d40;
}

// FUNCTION: 0x004ebda0
cUnk00a93d58* Fn004ebda0()
{
    return new cUnk00a93d58;
}

// FUNCTION: 0x004ebdd0
cUnk00a93d70* Fn004ebdd0()
{
    return new cUnk00a93d70;
}

// FUNCTION: 0x004ebe00
cUnk00a93d88* Fn004ebe00()
{
    return new cUnk00a93d88;
}

// FUNCTION: 0x004ebe30
cUnk00a93da0* Fn004ebe30()
{
    return new cUnk00a93da0;
}

// FUNCTION: 0x004ebe60
cUnk00a93db8* Fn004ebe60()
{
    return new cUnk00a93db8;
}

// FUNCTION: 0x004ebe90
cUnk00a93dd0* Fn004ebe90()
{
    return new cUnk00a93dd0;
}

// FUNCTION: 0x004ec650
cUnk00a93fdc* Fn004ec650()
{
    return new cUnk00a93fdc;
}

// FUNCTION: 0x004ec5b0
uint32_t cUnk00a93fc4::Slot02_a93fc4()
{
    int32_t n = static_cast<int32_t>(mnRefs);
    if (n > 1) {
        --n;
        mnRefs = n;
        return n;
    }
    operator delete(this);  // no destructor runs: the class has none
    return 0;
}

// FUNCTION: 0x004ec630
uint32_t cUnk00a93fdc::Slot02_a93fdc()
{
    int32_t n = static_cast<int32_t>(mnRefs);
    if (n > 1) {
        --n;
        mnRefs = n;
        return n;
    }
    operator delete(this);  // no destructor runs: the class has none
    return 0;
}

// FUNCTION: 0x004ec6a0
uint32_t cUnk00a93ff4::Slot02_a93ff4()
{
    int32_t n = static_cast<int32_t>(mnRefs);
    if (n > 1) {
        --n;
        mnRefs = n;
        return n;
    }
    operator delete(this);  // no destructor runs: the class has none
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x004ec5d0 score 8
bool cUnk00a93fc4::Slot00_a93fc4(uint32_t a, uint32_t b)
{
    if (a != 0x4a40074c && a != 0xca400753) {
        return false;
    }
    *OB_PTR(cUnk00a93fc4*, b) = this;
        Slot01_a93fc4();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004eba70 score 8
bool cUnk00a93fdc::Slot00_a93fdc(uint32_t a, uint32_t b)
{
    if (a != 0x4a40074c && a != 0xca400757) {
        return false;
    }
    *OB_PTR(cUnk00a93fdc*, b) = this;
        Slot01_a93fdc();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x004ec6c0 score 8
bool cUnk00a93ff4::Slot00_a93ff4(uint32_t a, uint32_t b)
{
    if (a != 0x4a40074c && a != 0xea40074f) {
        return false;
    }
    *OB_PTR(cUnk00a93ff4*, b) = this;
        Slot01_a93ff4();
    return true;
}
#endif

// Views of what OnStart talks to (only the calls used here are named).
struct Director_a93e18;

struct Framework_a93e18 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Fn07(void* aPtr);
};

struct SubDirector_a93e18 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Fn04(uint32_t aCom);
};

struct Director_a93e18 {
    // STUB: 0x0090e0d4
    void AddDirector(SubDirector_a93e18* aDirector);
};

// STUB: 0x0087b212
Director_a93e18* Fn0087b212();
// STUB: 0x008793ec
Framework_a93e18* Fn008793ec();
// STUB: 0x009666c9
SubDirector_a93e18* Fn009666c9();
// STUB: 0x0087497e
SubDirector_a93e18* Fn0087497e();
// STUB: 0x0094ac43
SubDirector_a93e18* Fn0094ac43();
// STUB: 0x009361d5
SubDirector_a93e18* Fn009361d5();
// STUB: 0x00945785
SubDirector_a93e18* Fn00945785();

// FUNCTION: 0x004eb1b0
bool cSC4AudioCOMDirector::OnStart(uint32_t aCom)
{
    Director_a93e18* dir = Fn0087b212();
    cUnk00ace69c* base = this;
    Framework_a93e18* fw = Fn008793ec();
    fw->Fn07(base);
    SubDirector_a93e18* sub = Fn009666c9();
    dir->AddDirector(sub);
    sub->Fn04(aCom);
    sub = Fn0087497e();
    dir->AddDirector(sub);
    sub->Fn04(aCom);
    sub = Fn0094ac43();
    dir->AddDirector(sub);
    sub->Fn04(aCom);
    sub = Fn009361d5();
    dir->AddDirector(sub);
    sub->Fn04(aCom);
    sub = Fn00945785();
    dir->AddDirector(sub);
    sub->Fn04(aCom);
    return true;
}


// Views for the constructor: AddCls registers a class id with its factory.
struct ClsHost_a93e18 {
    // STUB: 0x0090e133
    void AddCls(uint32_t aId, void* aFactory);
};

// STUB: 0x004ed700
void* Fn004ed700();
// STUB: 0x004eb120
void* Fn004eb120();
// STUB: 0x004eb0a0
void* Fn004eb0a0();
// STUB: 0x004eb100
void* Fn004eb100();
// STUB: 0x004eb0c0
void* Fn004eb0c0();
// STUB: 0x004eb080
void* Fn004eb080();
// STUB: 0x004eb0e0
void* Fn004eb0e0();
// STUB: 0x004eb150
void* Fn004eb150();
// STUB: 0x004eb180
void* Fn004eb180();
#ifdef OB_DRAFTS
// CLOSE: 0x004ec710 score 999 (the original's constructor also builds the base and stores both vtables)
void* cSC4AudioCOMDirector::Fn004ec710()
{
    ClsHost_a93e18* host = reinterpret_cast<ClsHost_a93e18*>(this);
    mpUnk4c = 0;
    mpUnk50 = 0;
    mpUnk54 = 0;
    mpUnk58 = 0;
    mpUnk5c = 0;
    mpUnk60 = 0;
    mpUnk64 = 0;
    mpUnk68 = 0;
    host->AddCls(0xaa355871, reinterpret_cast<void*>(Fn004ed700));
    host->AddCls(0x29e2797f, reinterpret_cast<void*>(Fn004eb120));
    host->AddCls(0xbdb6171e, reinterpret_cast<void*>(Fn004eb0a0));
    host->AddCls(0x69e500bc, reinterpret_cast<void*>(Fn004eb100));
    host->AddCls(0x6a12f51c, reinterpret_cast<void*>(Fn004eb0c0));
    host->AddCls(0x4a47dc0d, reinterpret_cast<void*>(Fn004eb080));
    host->AddCls(0xca4a66b9, reinterpret_cast<void*>(Fn004eb0e0));
    host->AddCls(0x5cfbdbbf, reinterpret_cast<void*>(Fn004eb150));
    host->AddCls(0x5cfbdbd5, reinterpret_cast<void*>(Fn004eb180));
    host->AddCls(0xca426982, reinterpret_cast<void*>(Fn004ec6f0));
    host->AddCls(0x8a401e0f, reinterpret_cast<void*>(Fn004ec3d0));
    host->AddCls(0x2a426986, reinterpret_cast<void*>(Fn004ec3f0));
    host->AddCls(0x8a42698a, reinterpret_cast<void*>(Fn004ec410));
    host->AddCls(0x6a42698e, reinterpret_cast<void*>(Fn004ec430));
    host->AddCls(0xa426991, reinterpret_cast<void*>(Fn004ec450));
    host->AddCls(0x6a426995, reinterpret_cast<void*>(Fn004ec470));
    host->AddCls(0xa426998, reinterpret_cast<void*>(Fn004ec490));
    host->AddCls(0xaa54e710, reinterpret_cast<void*>(Fn004ec4b0));
    host->AddCls(0xaa54e715, reinterpret_cast<void*>(Fn004ec4d0));
    host->AddCls(0xa54e719, reinterpret_cast<void*>(Fn004ec4f0));
    host->AddCls(0xb817c41, reinterpret_cast<void*>(Fn004ec510));
    host->AddCls(0xab817c0b, reinterpret_cast<void*>(Fn004ec530));
    host->AddCls(0xcb817c1b, reinterpret_cast<void*>(Fn004ec550));
    host->AddCls(0x2b817c27, reinterpret_cast<void*>(Fn004ec570));
    host->AddCls(0x8b817c32, reinterpret_cast<void*>(Fn004ec590));
    host->AddCls(0xa401ba0, reinterpret_cast<void*>(Fn004ec600));
    host->AddCls(0x4a401ba7, reinterpret_cast<void*>(Fn004eb260));
    host->AddCls(0xca401bae, reinterpret_cast<void*>(Fn004eb290));
    host->AddCls(0x6a401bb3, reinterpret_cast<void*>(Fn004eb2c0));
    host->AddCls(0x6a401bba, reinterpret_cast<void*>(Fn004eb2f0));
    host->AddCls(0xa42b520, reinterpret_cast<void*>(Fn004eb320));
    host->AddCls(0x6a43c75d, reinterpret_cast<void*>(Fn004eb350));
    host->AddCls(0xca5a6a5f, reinterpret_cast<void*>(Fn004eb380));
    host->AddCls(0xa5a6a64, reinterpret_cast<void*>(Fn004eb3b0));
    host->AddCls(0x2a5a6a68, reinterpret_cast<void*>(Fn004eb3e0));
    host->AddCls(0x6a5a6a6b, reinterpret_cast<void*>(Fn004eb410));
    host->AddCls(0x4a5a6a6f, reinterpret_cast<void*>(Fn004eb440));
    host->AddCls(0xa5a6a72, reinterpret_cast<void*>(Fn004eb470));
    host->AddCls(0xa5a6a76, reinterpret_cast<void*>(Fn004eb4a0));
    host->AddCls(0xaa5a6a7a, reinterpret_cast<void*>(Fn004eb4d0));
    host->AddCls(0xaa5a6a7d, reinterpret_cast<void*>(Fn004eb500));
    host->AddCls(0xca5a6a81, reinterpret_cast<void*>(Fn004eb530));
    host->AddCls(0x2a5a6a84, reinterpret_cast<void*>(Fn004eb560));
    host->AddCls(0x4a5a6a88, reinterpret_cast<void*>(Fn004eb590));
    host->AddCls(0xea5a6a8b, reinterpret_cast<void*>(Fn004eb5c0));
    host->AddCls(0x6a5a6a8f, reinterpret_cast<void*>(Fn004eb5f0));
    host->AddCls(0x4a5d0eb0, reinterpret_cast<void*>(Fn004eb620));
    host->AddCls(0xaa5d0eb5, reinterpret_cast<void*>(Fn004eb650));
    host->AddCls(0xea5f4954, reinterpret_cast<void*>(Fn004eb680));
    host->AddCls(0x8a5f603e, reinterpret_cast<void*>(Fn004eb6b0));
    host->AddCls(0x8a60f033, reinterpret_cast<void*>(Fn004eb6e0));
    host->AddCls(0x2a872395, reinterpret_cast<void*>(Fn004eb710));
    host->AddCls(0xca9d68a1, reinterpret_cast<void*>(Fn004eb740));
    host->AddCls(0xca9d68a5, reinterpret_cast<void*>(Fn004eb770));
    host->AddCls(0xaa9d68a9, reinterpret_cast<void*>(Fn004eb7a0));
    host->AddCls(0x2aa17957, reinterpret_cast<void*>(Fn004eb7d0));
    host->AddCls(0x8a427f7c, reinterpret_cast<void*>(Fn004ec650));
    host->AddCls(0xea4298fc, reinterpret_cast<void*>(Fn004eb800));
    host->AddCls(0x2a429900, reinterpret_cast<void*>(Fn004eb830));
    host->AddCls(0x4a429903, reinterpret_cast<void*>(Fn004eb860));
    host->AddCls(0x2a429907, reinterpret_cast<void*>(Fn004eb890));
    host->AddCls(0xca42990a, reinterpret_cast<void*>(Fn004eb8c0));
    host->AddCls(0x8a53e23e, reinterpret_cast<void*>(Fn004eb8f0));
    host->AddCls(0xca53e243, reinterpret_cast<void*>(Fn004eb920));
    host->AddCls(0xa53e247, reinterpret_cast<void*>(Fn004eb950));
    host->AddCls(0x4a53e24b, reinterpret_cast<void*>(Fn004eb980));
    host->AddCls(0x2a53e24f, reinterpret_cast<void*>(Fn004eb9b0));
    host->AddCls(0xca53e252, reinterpret_cast<void*>(Fn004eb9e0));
    host->AddCls(0xa53e290, reinterpret_cast<void*>(Fn004eba10));
    host->AddCls(0x2a53f0c3, reinterpret_cast<void*>(Fn004eba40));
    host->AddCls(0x8a53f0e4, reinterpret_cast<void*>(Fn004ebaa0));
    host->AddCls(0x4a53f0e8, reinterpret_cast<void*>(Fn004ebad0));
    host->AddCls(0x8a53f584, reinterpret_cast<void*>(Fn004ebb00));
    host->AddCls(0xea5a6fce, reinterpret_cast<void*>(Fn004ebb30));
    host->AddCls(0x8a5a6fd1, reinterpret_cast<void*>(Fn004ebb60));
    host->AddCls(0xea5a6fd4, reinterpret_cast<void*>(Fn004ebb90));
    host->AddCls(0x6a5d0682, reinterpret_cast<void*>(Fn004ebbc0));
    host->AddCls(0xa5d068d, reinterpret_cast<void*>(Fn004ebbf0));
    host->AddCls(0x2a5d0691, reinterpret_cast<void*>(Fn004ebc20));
    host->AddCls(0xea5f495c, reinterpret_cast<void*>(Fn004ebc50));
    host->AddCls(0x4a60d870, reinterpret_cast<void*>(Fn004ebc80));
    host->AddCls(0x8a60d873, reinterpret_cast<void*>(Fn004ebcb0));
    host->AddCls(0x6a60f166, reinterpret_cast<void*>(Fn004ebce0));
    host->AddCls(0xea80835e, reinterpret_cast<void*>(Fn004ebd10));
    host->AddCls(0xa808367, reinterpret_cast<void*>(Fn004ebd40));
    host->AddCls(0xca80836c, reinterpret_cast<void*>(Fn004ebd70));
    host->AddCls(0x2a808371, reinterpret_cast<void*>(Fn004ebda0));
    host->AddCls(0x4a808375, reinterpret_cast<void*>(Fn004ebdd0));
    host->AddCls(0x4a8084f4, reinterpret_cast<void*>(Fn004ebe00));
    host->AddCls(0x2a9d6690, reinterpret_cast<void*>(Fn004ebe30));
    host->AddCls(0xaa9d6694, reinterpret_cast<void*>(Fn004ebe60));
    host->AddCls(0x2a9d6697, reinterpret_cast<void*>(Fn004ebe90));
    return this;
}
#endif
