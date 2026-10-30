#include <cstddef>

#include "classes/cUnk00ae4910.h"

// A window object seen through the slots this class calls (slot numbers are vtable offset / 4).
struct Win_ae4910 {
    virtual bool S0(void* a, void* b);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual bool Msg(void* m);
    virtual void P4();
    virtual void S5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual bool S9(uint32_t a, uint32_t b, uint32_t c);
    virtual void P10();
    virtual Win_ae4910* GetParent();
    virtual void P12();
    virtual void P13();
    virtual void P14();
    virtual void S15(Win_ae4910* w);
    virtual void S16();
    virtual bool S17(Win_ae4910* w);
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual bool S21(Win_ae4910* w);
    virtual bool S22(Win_ae4910* w);
    virtual void S23();
    virtual void P24();
    virtual void P25();
    virtual void P26();
    virtual void P27();
    virtual void P28();
    virtual void P29();
    virtual void P30();
    virtual void P31();
    virtual void P32();
    virtual void P33();
    virtual void P34();
    virtual void P35();
    virtual void P36();
    virtual void P37();
    virtual void P38();
    virtual uint32_t S39(uint32_t a, uint32_t b);
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual void P48();
    virtual void P49();
    virtual void P50();
    virtual void P51();
    virtual void P52();
    virtual void P53();
    virtual void P54();
    virtual void P55();
    virtual void P56();
    virtual void P57();
    virtual void P58();
    virtual void S59(uint32_t a, uint32_t b);
    virtual void P60();
    virtual void P61();
    virtual bool S62(uint32_t a, uint32_t b);
    virtual uint32_t S63();
    virtual void P64();
    virtual uint32_t S65();
    virtual void S66(uint32_t a);
    virtual bool S67(uint32_t a);
    virtual void S68(uint32_t a, uint32_t b);
    virtual void S69();
    virtual void P70();
    virtual bool S71();
    virtual bool S72();
    virtual void P73();
    virtual void P74();
    virtual void P75();
    virtual void P76();
    virtual void P77();
    virtual void P78();
    virtual void P79();
    virtual void P80();
    virtual void P81();
    virtual void P82();
    virtual bool S83(Win_ae4910* w);
    virtual void P84();
    virtual void P85();
    virtual void P86();
    virtual uint32_t S87();
    virtual void P88();
    virtual void S89();
    virtual void P90();
    virtual void S91();
};

// An intrusive reference to a window: the copy and assignment constructors are the original's functions.
struct Ref_ae4910 {
    Win_ae4910* mp;
    // STUB: 0x004e4bb0
    Ref_ae4910(const Ref_ae4910* src);
    // STUB: 0x004f20c0
    Ref_ae4910(Win_ae4910* w);
    // STUB: 0x005447b0
    void Set(Win_ae4910* w);
    ~Ref_ae4910()
    {
        if (mp) {
            mp->Release();
        }
    }
};

// The service object the class asks for (slots 1, 2, 3, 5).
struct Svc_ae4910 {
    virtual void P0();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual Win_ae4910* Get();
    virtual void P4();
    virtual bool Init(uint32_t a, uint32_t b, uint32_t c);
};

// The service manager the global getter returns.
struct Mgr_ae4910 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual bool Find(uint32_t id1, uint32_t id2, void* out);
};

// STUB: 0x0090ddf1
Mgr_ae4910* Fn0090ddf1();

// A lock-like object embedded in the class (slots 1 and 2).
struct Lock_ae4910 {
    virtual void P0();
    virtual void Lock();
    virtual void Unlock();
};

// A list of references, a hash set of windows and the list helpers.
struct Node_ae4910 {
    Node_ae4910* next;
    Node_ae4910* prev;
    Win_ae4910* mpWin;
};
struct List_ae4910 {
    Node_ae4910* head;
};
struct SetNode_ae4910 {
    SetNode_ae4910* next;
    uint32_t key;
};
struct Set_ae4910 {
    uint32_t unused0;
    SetNode_ae4910** begin;
    SetNode_ae4910** end;
    uint32_t unusedc;
    uint32_t count;
    // STUB: 0x009db9b1
    SetNode_ae4910* Find(uint32_t* key);
    // STUB: 0x009dbcdb
    uint32_t Erase(uint32_t* key);
};

// Iteration over the window set (a list of windows hanging from the set).
struct SetIter_ae4910 {
    Node_ae4910* cur;
    // STUB: 0x0097c081
    void Begin(Set_ae4910* s);
    // STUB: 0x009dbc2d
    SetIter_ae4910* Next();
};

// An observer entry: the pair the message-filter list holds.
struct Msg_ae4910 {
    uint32_t type;
    Win_ae4910* win;
    uint32_t a;
    uint32_t b;
};

// STUB: 0x009dafa4
bool Fn009dafa4(Win_ae4910* w, Msg_ae4910* m);

// FUNCTION: 0x009daf46
bool cUnk00ae4910::Slot09_ad1a98(uint32_t /*a*/)
{
    Slot16_ae47e8();
    return true;
}

// FUNCTION: 0x009daf53
void cUnk00ae4910::Slot10_ae47e8(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Slot09_ae47e8(a, d, (c << 16) | (b & 0xffff));
}

// FUNCTION: 0x009daf7e
bool cUnk00ae4910::Slot13_ae47e8(uint32_t a, uint32_t b)
{
    Win_ae4910* w = OB_PTR(Win_ae4910, a);
    if (w != 0 && Slot24_ae47e8(a)) {
        return w->Msg(OB_PTR(void, b));
    }
    return false;
}

// FUNCTION: 0x009dafe0
void cUnk00ae4910::Slot34_ae47e8(uint32_t a, uint32_t b, uint32_t c)
{
    Slot33_ae47e8(b, c);
    OB_PTR(Win_ae4910, a)->S59(b, c);
}

// FUNCTION: 0x009db006
void cUnk00ae4910::Slot33_ae47e8(uint32_t a, uint32_t b)
{
    *OB_PTR(int32_t, a) = mnX168;
    *OB_PTR(int32_t, b) = mnY16c;
}

// FUNCTION: 0x009db025
bool cUnk00ae4910::Slot42_ae47e8()
{
    return mnLock17c != 0;
}

// FUNCTION: 0x009db038
void cUnk00ae4910::Slot54_ae4910(uint32_t a, uint32_t b)
{
    Slot09_ae47e8(0xf, a, b);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009db04a score 23
uint32_t cUnk00ae4910::Slot44_ae47e8(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Svc_ae4910* svc = 0;
    uint32_t result = 0xffffffff;
    if (!Fn0090ddf1()->Find(0x593, 0x57c, &svc)) {
        char* obj = new char[0x118];
        svc = reinterpret_cast<Svc_ae4910*>(obj + 0xdc);
        svc->AddRef();
    }
    if (svc->Init(a, b, c)) {
        Win_ae4910* w = svc->Get();
        if (w) {
            w->AddRef();
            result = Slot41_ae47e8(OB_ADDR(w));
            w->S5();
            w->Release();
        }
    }
    svc->Release();
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009db0fd score 2
bool cUnk00ae4910::Slot56_ae4910(uint32_t a)
{
    Win_ae4910* w = OB_PTR(Win_ae4910, a);
    bool has = Slot24_ae47e8(a);
    Slot22_ae47e8(a);
    Win_ae4910* parent = 0;
    if (has) {
        parent = w->GetParent();
    }
    if (Slot24_ae47e8(OB_ADDR(parent))) {
        return parent->S17(w);
    }
    if (has) {
        w->AddRef();
        w->S5();
        w->Release();
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x009db163
uint32_t cUnk00ae4910::Slot59_ae4910()
{
    return ++mnRef18c;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009db16e score 13
uint32_t cUnk00ae4910::Slot60_ae4910()
{
    if (mnRef18c > 0) {
        --mnRef18c;
        if (mnRef18c == 0) {
            Slot57_ae4910();
        }
        return mnRef18c;
    }
    mnRef18c = 0;
    return 0;
}
#endif

// FUNCTION: 0x009db37e
bool cUnk00ae4910::Slot05_ae47e8(uint32_t a, uint32_t b)
{
    Win_ae4910* w = reinterpret_cast<Win_ae4910*>(mpWin40);
    if (w) {
        return w->S0(OB_PTR(void, a), OB_PTR(void, b));
    }
    return false;
}

// FUNCTION: 0x009db38e
bool cUnk00ae4910::Slot12_ae47e8(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    if (Slot24_ae47e8(a)) {
        uint32_t rect[4];
        rect[0] = b;
        rect[1] = c;
        rect[2] = d;
        rect[3] = e;
        return OB_PTR(Win_ae4910, a)->Msg(rect);
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009db72d score 16
uint32_t cUnk00ae4910::Slot31_ae47e8(uint32_t a)
{
    return Slot30_ae47e8(a);
}
#endif

// FUNCTION: 0x009db957
uint32_t cUnk00ae4910::Slot25_ae47e8(uint32_t a, uint32_t b)
{
    Win_ae4910* w = reinterpret_cast<Win_ae4910*>(mpWin40);
    if (w) {
        return w->S39(a, b);
    }
    return 0;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009db9e3 score 14
void cUnk00ae4910::Slot06_ae47e8()
{
    if (mbRun180) {
        mbBusy188 = true;
        if (Slot07_ae47e8(OB_ADDR(mpWin40))) {
            Slot08_ae47e8();
        }
        mbBusy188 = false;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dba20 score 9
bool cUnk00ae4910::Slot61_ae4910(uint32_t a)
{
    List_ae4910* list = reinterpret_cast<List_ae4910*>(&mList1a4);
    Node_ae4910* end = list->head;
    Node_ae4910* n = end->next;
    while (n != end) {
        if (n->mpWin->Msg(OB_PTR(void, a))) {
            return true;
        }
        n = n->next;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dbaa4 score 22
bool cUnk00ae4910::Slot58_ae4910(uint32_t a)
{
    List_ae4910* list = reinterpret_cast<List_ae4910*>(&mList190);
    Node_ae4910* end = list->head;
    Node_ae4910* n = end->next;
    while (n != end) {
        Win_ae4910* w = OB_PTR(Win_ae4910, a);
        if (w == 0 || w == n->mpWin || w->GetParent() != 0) {
            return true;
        }
        n = n->next;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dbd68 score 32
bool cUnk00ae4910::Slot08_ae47e8()
{
    if (mbBusy188) {
        List_ae4910* list = reinterpret_cast<List_ae4910*>(&mPend184);
        while (list->head->next != list->head) {
            Win_ae4910* w = list->head->next->mpWin;
            w->S89();
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dc087 score 11
bool cUnk00ae4910::Slot24_ae47e8(uint32_t a)
{
    if (a != 0) {
        Set_ae4910* set = reinterpret_cast<Set_ae4910*>(mSet44);
        return set->Find(&a) != 0;
    }
    return false;
}
#endif

// FUNCTION: 0x009dc451
bool cUnk00ae4910::Slot21_ae47e8(uint32_t a)
{
    Set_ae4910* set = reinterpret_cast<Set_ae4910*>(mSet44);
    if (set->Find(&a) != 0) {
        set->Erase(&a);
        return true;
    }
    return false;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009dc4ac score 23
void cUnk00ae4910::Slot23_ae47e8(uint32_t a)
{
    if (mnRef18c > 0) {
        if (!Slot58_ae4910(a)) {
            reinterpret_cast<List_ae4910*>(&mList190);
        }
    } else {
        Slot56_ae4910(a);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dc586 score 45
bool cUnk00ae4910::Slot20_ae47e8(uint32_t a)
{
    Set_ae4910* set = reinterpret_cast<Set_ae4910*>(mSet44);
    if (set->Find(&a) == 0) {
        Win_ae4910* w = OB_PTR(Win_ae4910, a);
        if (w->S65() == 0) {
            w->S66(mnCounter194++);
        }
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dc3e1 score 39
void cUnk00ae4910::Slot39_ae47e8(uint32_t a)
{
    Ref_ae4910 r(OB_PTR(Win_ae4910, a));
    (void)r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dbbb9 score 33
void cUnk00ae4910::Slot40_ae47e8(uint32_t a)
{
    Ref_ae4910 r(OB_PTR(Win_ae4910, a));
    (void)r;
}
#endif

// A map and a record list the class keeps (field198 and field20), reached through their helpers.
struct Map_ae4910 {
    // STUB: 0x0096a7b0
    uint32_t* Index(uint32_t* key);
};
struct Rec_ae4910 {
    uint32_t v[5];
    // STUB: 0x009db1a1
    Rec_ae4910(uint32_t a, uint32_t b);
};
struct RecList_ae4910 {
    // STUB: 0x009dc0ab
    void Push(Rec_ae4910* r);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009db667 score 47
bool cUnk00ae4910::Slot29_ae47e8(uint32_t a)
{
    if (a != OB_ADDR(mpWin30)) {
        if (mb1a8 || mpWin30 == 0) {
            Ref_ae4910 keep(OB_PTR(Win_ae4910, a));
            Ref_ae4910 cur(reinterpret_cast<const Ref_ae4910*>(&mpWin30));
            Ref_ae4910* slot = reinterpret_cast<Ref_ae4910*>(&mpWin30);
            slot->Set(OB_PTR(Win_ae4910, a));
            if (cur.mp) {
                Slot12_ae47e8(OB_ADDR(cur.mp), 0x12, OB_ADDR(cur.mp), a, 0);
            }
            if (mpWin30) {
                Slot12_ae47e8(OB_ADDR(mpWin30), 0x12, OB_ADDR(cur.mp), a, 0);
            }
        }
    }
    return true;
}
#endif

// FUNCTION: 0x009db6f3
bool cUnk00ae4910::Slot30_ae47e8(uint32_t a)
{
    if (a != OB_ADDR(mpWin30)) {
        return false;
    }
    Slot29_ae47e8(0);
    Slot10_ae47e8(0xd, mnX168, mnY16c, mnW178);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009db756 score 54
bool cUnk00ae4910::Slot26_ae47e8(uint32_t a)
{
    if (a != OB_ADDR(mpWin3c)) {
        Ref_ae4910 keep(OB_PTR(Win_ae4910, a));
        Msg_ae4910 m;
        m.type = 0;
        m.win = 0;
        m.a = 0;
        m.b = 0;
        Ref_ae4910* slot = reinterpret_cast<Ref_ae4910*>(&mpWin3c);
        if (!Slot24_ae47e8(OB_ADDR(mpWin3c))) {
            slot->Set(0);
        }
        Win_ae4910* w = OB_PTR(Win_ae4910, a);
        if (!Slot24_ae47e8(a)) {
            w = 0;
        }
        if (slot->mp) {
            m.type = 0x14;
            m.win = w;
            slot->mp->Msg(&m);
        }
        if (w) {
            m.win = slot->mp;
            m.type = 0x13;
            w->Msg(&m);
        }
        slot->Set(w);
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009db804 score 1
uint32_t cUnk00ae4910::Slot37_ae47e8(uint32_t a)
{
    Ref_ae4910* slot = reinterpret_cast<Ref_ae4910*>(&mpWin34);
    Win_ae4910* w = OB_PTR(Win_ae4910, a);
    if (a != OB_ADDR(mpWin34)) {
        if (Slot24_ae47e8(a)) {
            Ref_ae4910 keep(w);
            if (w == 0 || w->S67(0x8000)) {
                Ref_ae4910 old(slot);
                if (old.mp) {
                    Slot12_ae47e8(OB_ADDR(old.mp), 0x10, a, 0, 0);
                }
                slot->Set(w);
                if (slot->mp) {
                    Slot12_ae47e8(OB_ADDR(slot->mp), 0x11, OB_ADDR(old.mp), 0, 0);
                }
            }
        }
    }
    return OB_ADDR(mpWin34);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009db8a4 score 43
void cUnk00ae4910::Slot22_ae47e8(uint32_t a)
{
    Win_ae4910* w = OB_PTR(Win_ae4910, a);
    if (Slot24_ae47e8(OB_ADDR(mpWin30))) {
        Win_ae4910* c = reinterpret_cast<Win_ae4910*>(mpWin30);
        if (w == c || c->S21(w)) {
            Slot30_ae47e8(OB_ADDR(mpWin30));
        }
    }
    if (Slot24_ae47e8(OB_ADDR(mpWin34))) {
        Win_ae4910* c = reinterpret_cast<Win_ae4910*>(mpWin34);
        if (w == c || c->S21(w)) {
            if (w->S87() != 0) {
                Slot37_ae47e8(w->S87());
            } else {
                Slot37_ae47e8(OB_ADDR(mpWin40));
            }
        }
    } else {
        Slot37_ae47e8(OB_ADDR(mpWin40));
    }
    Ref_ae4910* slot = reinterpret_cast<Ref_ae4910*>(&mpWin3c);
    if (Slot24_ae47e8(OB_ADDR(mpWin3c))) {
        if (w == slot->mp || slot->mp->S21(w)) {
            slot->Set(0);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dc225 score 10
bool cUnk00ae4910::Slot07_ae47e8(uint32_t a)
{
    if (a != 0 && mbBusy188) {
        // 0x99d291: push_back of the key onto the pending list
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dc24e score 1
void cUnk00ae4910::Slot15_ae47e8(uint32_t a, uint32_t b)
{
    Lock_ae4910* lock = reinterpret_cast<Lock_ae4910*>(&mLock24);
    lock->Lock();
    Rec_ae4910 r(a, b);
    reinterpret_cast<RecList_ae4910*>(&mList20)->Push(&r);
    lock->Unlock();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dc286 score 4
void cUnk00ae4910::Slot14_ae47e8(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Lock_ae4910* lock = reinterpret_cast<Lock_ae4910*>(&mLock24);
    lock->Lock();
    Rec_ae4910 r(0, 0);
    r.v[0] = a;
    r.v[1] = b;
    r.v[2] = c;
    r.v[3] = d;
    r.v[4] = e;
    reinterpret_cast<RecList_ae4910*>(&mList20)->Push(&r);
    lock->Unlock();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dc47b score 17
void cUnk00ae4910::Slot55_ae4910()
{
    SetIter_ae4910 it;
    it.Begin(reinterpret_cast<Set_ae4910*>(mSet44));
    while (it.cur != 0) {
        it.cur->mpWin->S91();
        it.Next();
    }
}
#endif

// FUNCTION: 0x009dc56d
void cUnk00ae4910::Slot62_ae4910(uint32_t a, uint32_t b)
{
    *reinterpret_cast<Map_ae4910*>(&mMap198)->Index(&a) = b;
}

#ifdef OB_DRAFTS
// CLOSE: 0x009dc2d1 score 95
void cUnk00ae4910::Slot16_ae47e8()
{
    // Drains the queued records one by one under the lock, handing each to its window or to the queued windows.
    Lock_ae4910* lock = reinterpret_cast<Lock_ae4910*>(&mLock24);
    lock->Lock();
    lock->Unlock();
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009db553 score 52
bool cUnk00ae4910::Slot18_ae47e8(uint32_t a)
{
    uint32_t* m = OB_PTR(uint32_t, a);
    Win_ae4910* t = 0;
    if (mpWin34 != 0 && reinterpret_cast<Win_ae4910*>(mpWin34)->S72()) {
        t = reinterpret_cast<Win_ae4910*>(mpWin34);
    } else if (mpWin40 != 0 && reinterpret_cast<Win_ae4910*>(mpWin40)->S72()) {
        t = reinterpret_cast<Win_ae4910*>(mpWin40);
    }
    if (t != 0) {
        Msg_ae4910 q;
        q.type = 0x1a;
        q.win = t;
        q.a = m[0];
        q.b = a;
        Win_ae4910* cur = t;
        if (!Slot61_ae4910(OB_ADDR(&q))) {
            while (cur != 0 && !Fn009dafa4(cur, &q) && !cur->Msg(m)) {
                q.type = 0x1b;
                if (cur->Msg(&q) || cur == reinterpret_cast<Win_ae4910*>(mpWin38)) {
                    break;
                }
                cur = cur->GetParent();
            }
            if (!Slot61_ae4910(OB_ADDR(&q))) {
                return false;
            }
        }
        return true;
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009db3ce score 178
bool cUnk00ae4910::Slot17_ae47e8(uint32_t a)
{
    uint32_t* m = OB_PTR(uint32_t, a);
    uint32_t type = m[0];
    bool r = false;
    mnX168 = m[1];
    mnY16c = m[2];
    mnW178 = *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(m) + 0xe);
    if (mpWin30 != 0) {
        Ref_ae4910 f(reinterpret_cast<const Ref_ae4910*>(&mpWin30));
        Win_ae4910* w = f.mp;
        if (type == 0xd) {
            w->S59(m[1], m[2]);
            Slot26_ae47e8(OB_ADDR(w));
            r = w->Msg(m);
        } else if (w->S72()) {
            w->S59(m[1], m[2]);
            if (type == 7 || type == 8) {
                w->S23();
                Slot37_ae47e8(OB_ADDR(w));
            }
            Slot26_ae47e8(OB_ADDR(w));
            r = w->Msg(m);
        } else if (mpWin40 != 0) {
            Slot26_ae47e8(reinterpret_cast<Win_ae4910*>(mpWin40)->S39(m[1], m[2]));
        }
    } else {
        Win_ae4910* w38 = reinterpret_cast<Win_ae4910*>(mpWin38);
        Win_ae4910* w40 = reinterpret_cast<Win_ae4910*>(mpWin40);
        if (w38 != 0 && w38->S62(m[1], m[2]) && w38->S71() && w38->S72()) {
            w40 = w38;
        } else if (mb1a9 && w40 != 0) {
            Slot26_ae47e8(w40->S39(m[1], m[2]));
        }
        if (w40 != 0) {
            r = w40->S83(reinterpret_cast<Win_ae4910*>(m));
        }
    }
    return r;
}
#endif

// The window manager's stand-ins used by the setup code.
struct GzWin_ae4910 {
    char pad[0xd8];
    // STUB: 0x0099da5a
    GzWin_ae4910(void* mgr, void* kb);
};
struct Helper_ae4910 {
    char pad[0x44];
    // STUB: 0x00892792
    Helper_ae4910();
};
struct Kb_ae4910 {
    virtual void P0();
    virtual void P1();
    virtual void P2();
    virtual void P3();
    virtual void P4();
    virtual void P5();
    virtual void P6();
    virtual void P7();
    virtual void P8();
    virtual void Attach(void* owner);
    virtual void Detach(void* owner);
};
// STUB: 0x008793ec
Kb_ae4910* Fn008793ec();

#ifdef OB_DRAFTS
// CLOSE: 0x009db1bc score 99
bool cUnk00ae4910::Slot03_ae1d24()
{
    if (!mbInit2c) {
        mbInit2c = true;
        Ref_ae4910* win = reinterpret_cast<Ref_ae4910*>(&mpWin40);
        if (mpWin40 == 0) {
            GzWin_ae4910* w = new GzWin_ae4910(this, mpMgr58);
            win->Set(reinterpret_cast<Win_ae4910*>(w));
            win->mp->S5();
        }
        if (mpMgr58 == 0) {
            mpMgr58 = Fn008793ec();
        }
        reinterpret_cast<Kb_ae4910*>(mpMgr58)->Attach(static_cast<cRZSystemService*>(this));
        if (mpHelper164 == 0) {
            Svc_ae4910* svc = reinterpret_cast<Svc_ae4910*>(this);
            if (!Fn0090ddf1()->Find(0x4352fef3, 0xa34c498a, &mpHelper164)) {
                Helper_ae4910* h = new Helper_ae4910;
                mpHelper164 = h;
                reinterpret_cast<Svc_ae4910*>(h)->AddRef();
            }
            reinterpret_cast<Svc_ae4910*>(mpHelper164)->Get();
            (void)svc;
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009db279 score 99
bool cUnk00ae4910::Slot04_ae1d24()
{
    if (mbInit2c) {
        mbInit2c = false;
        Ref_ae4910 r30(reinterpret_cast<const Ref_ae4910*>(&mpWin30));
        Ref_ae4910 r34(reinterpret_cast<const Ref_ae4910*>(&mpWin34));
        Ref_ae4910 r38(reinterpret_cast<const Ref_ae4910*>(&mpWin38));
        Ref_ae4910 r3c(reinterpret_cast<const Ref_ae4910*>(&mpWin3c));
        Ref_ae4910 r40(reinterpret_cast<const Ref_ae4910*>(&mpWin40));
        reinterpret_cast<Ref_ae4910*>(&mpWin30)->Set(0);
        reinterpret_cast<Ref_ae4910*>(&mpWin38)->Set(0);
        reinterpret_cast<Ref_ae4910*>(&mpWin3c)->Set(0);
        if (mpWin40 != 0) {
            reinterpret_cast<Win_ae4910*>(mpWin40)->S5();
            reinterpret_cast<Ref_ae4910*>(&mpWin40)->Set(0);
        }
        if (mpHelper164 != 0) {
            Svc_ae4910* h = reinterpret_cast<Svc_ae4910*>(mpHelper164);
            h->Get();
            h->Release();
            mpHelper164 = 0;
        }
        reinterpret_cast<Ref_ae4910*>(&mpWin34)->Set(0);
        reinterpret_cast<Kb_ae4910*>(mpMgr58)->Detach(static_cast<cRZSystemService*>(this));
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009dbda3 score 99
uint32_t cUnk00ae4910::Slot41_ae47e8(uint32_t a)
{
    uint32_t result = 0x80000000;
    Win_ae4910* w = OB_PTR(Win_ae4910, a);
    if (Slot24_ae47e8(a)) {
        uint32_t parent = Slot03_ae47e8();
        Win_ae4910* p = w->GetParent();
        if (p != 0 && !Slot24_ae47e8(OB_ADDR(p)) && parent == 0) {
            return result;
        }
        if (parent == 0 || Slot24_ae47e8(parent)) {
            Ref_ae4910 prev(OB_PTR(Win_ae4910, Slot36_ae47e8()));
            Ref_ae4910 cur(reinterpret_cast<const Ref_ae4910*>(&mpWin38));
            Msg_ae4910 q;
            q.type = 0x62ba7b42;
            q.win = w;
            q.a = w->S63();
            q.b = mnLock17c;
            if (p == 0) {
                Slot13_ae47e8(parent, a);
            }
            Slot37_ae47e8(a);
            if (mb1aa && w != OB_PTR(Win_ae4910, Slot28_ae47e8())) {
                Slot29_ae47e8(0);
            }
            if (mb1ab) {
                w->S69();
            }
            if (mb1ac) {
                w->S23();
            }
            reinterpret_cast<Ref_ae4910*>(&mpWin38)->Set(w);
            ++mnLock17c;
            result = Slot63_ae4910(a, 0x80000001, 0x80000000, OB_ADDR(mpMgr58));
            --mnLock17c;
            {
                q.type = 0x62ba7b43;
                q.a = w->S63();
                q.b = mnLock17c;
            }
        }
    }
    return result;
}
#endif
