#include "classes/cUnk00a808b8.h"
#include "game/Globals.h"
#include <cstring>
#include <list>

// A node of the std::list the object keeps at +0xbc (the member is the sentinel node's pointer).
struct ListNode {
    ListNode* mpNext;
    ListNode* mpPrev;
    uint32_t mnValue;
};

// Slot15 is declared uint32_t but the original callers test al as a bool (and it is a slot of another class, so not corrected here). This view of the same vtable calls it as one.
struct Slot15View {
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
    virtual bool Test(uint32_t);
};

// The object behind the global at 0xb43dc4: only the two virtual calls used here are named.
struct cUnk00b43dc4 {
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
    virtual void Pad43();
    virtual void Pad44();
    virtual void Pad45();
    virtual void Pad46();
    virtual void Fn47(uint32_t);
    virtual void Fn48(uint32_t);
};
// The stream the object is read from: only the slots used here are named.
struct StreamView {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Read16(void*);
    virtual void Read32(void*);
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual bool Fn18();
};

// STUB: 0x005d9730
void Fn005d9730(StreamView* stream, uint32_t id, cUnk00a80710** ppOut, uint32_t flag);

// The stream the object is written to.
struct StreamWriteView {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Write16(uint32_t);
    virtual void Write32(uint32_t);
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Pad12();
    virtual void Pad13();
    virtual void Pad14();
    virtual void Pad15();
    virtual void Pad16();
    virtual void Pad17();
    virtual bool Fn18();
};

// STUB: 0x005d99a0
void Fn005d99a0(StreamWriteView* stream, cUnk00a80710* pObject);

// GLOBAL: 0x00b43dc4
extern cUnk00b43dc4* gpB43dc4;

// Callee types used by the CLOSE functions below (names are guesses; only the slots called are declared).
struct cUnk00a80710Str {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual const char* Fn05();
};

struct cUnk00602f70 {
    // STUB: 0x00602f70
    void Fn00602f70(uint32_t* pOut);
};

// FUNCTION: 0x00407b90
void cUnk00a808b8::Slot29_a808b8()
{
    Slot15_a80710(2);
}

// FUNCTION: 0x00407c30
void cUnk00a808b8::Slot28_a80710()
{
    Slot30_a808b8();
}

// FUNCTION: 0x00407bc0
bool cUnk00a808b8::QueryInterface(unsigned int iid, void** ppv)
{
    if (iid != 0x8a09f5f5) {
        if (iid != 0xe4fda3d4) {
            return cUnk0090da1e::QueryInterface(iid, ppv);
        }
        *ppv = static_cast<cUnk00a80784*>(this);
        AddRef();
        return true;
    }
    *ppv = this;
    AddRef();
    return true;
}

// FUNCTION: 0x00407f40
void cUnk00a808b8::Slot23_a80710()
{
    ListNode* head = static_cast<ListNode*>(mpListNode);
    if (head->mpNext != head) {
        cUnk00b43dc4* p = gpB43dc4;
        if (p) {
            bool b = reinterpret_cast<Slot15View*>(this)->Test(2);
            for (ListNode* n = static_cast<ListNode*>(mpListNode)->mpNext; n != static_cast<ListNode*>(mpListNode); n = n->mpNext) {
                if (b) {
                    p->Fn47(n->mnValue);
                } else {
                    p->Fn48(n->mnValue);
                }
            }
        }
    }
}

// The data of the object seen from its third base (this + 0xc), the way the original's code addresses it.
struct ThirdBaseView {
    char pad00[0x64];
    uint32_t mnFlags;
    uint32_t mn68;
    uint32_t mn6c;
    uint32_t mn70;
    uint32_t mn74;
    uint32_t mn78;
    uint32_t mn7c;
    uint32_t mn80;
    char pad84[0x14];
    bool mbA4;
    char pad99[0x7];
    cUnk00a80710* mpAC;
    char padA4[0xc];
    void* mpListNode;
};

// FUNCTION: 0x004082f0
bool cUnk00a808b8::Slot04_a80784(void* pStream)
{
    ThirdBaseView* v = reinterpret_cast<ThirdBaseView*>(reinterpret_cast<char*>(this) + 0xc);
    StreamView* stream = static_cast<StreamView*>(pStream);
    uint16_t version;
    uint32_t count;
    uint32_t value;
    stream->Read16(&version);
    stream->Read32(&v->mn7c);
    stream->Read32(&v->mn80);
    stream->Read32(&v->mnFlags);
    stream->Read32(&v->mn68);
    stream->Read32(&v->mn6c);
    stream->Read32(&v->mn70);
    stream->Read32(&v->mn74);
    stream->Read32(&v->mn78);
    if (version > 3) {
        stream->Read32(&count);
        while (count) {
            --count;
            stream->Read32(&value);
            uint32_t x = value;
            reinterpret_cast<std::list<uint32_t>*>(&v->mpListNode)->push_back(x);
        }
    }
    cUnk00a80710** pp = &v->mpAC;
    if (*pp) {
        cUnk00a80710* old = *pp;
        *pp = 0;
        old->Release();
    }
    Fn005d9730(stream, 0x6a26d050, pp, 0);
    Slot14_a80710(0x10, 1);
    v->mbA4 = !stream->Fn18();
    return v->mbA4;
}

// FUNCTION: 0x00408090
bool cUnk00a808b8::Slot03_a80784(void* pStream)
{
    ThirdBaseView* v = reinterpret_cast<ThirdBaseView*>(reinterpret_cast<char*>(this) + 0xc);
    StreamWriteView* stream = static_cast<StreamWriteView*>(pStream);
    std::list<uint32_t>& list = *reinterpret_cast<std::list<uint32_t>*>(&v->mpListNode);
    stream->Write16(4);
    stream->Write32(v->mn7c);
    stream->Write32(v->mn80);
    stream->Write32(v->mnFlags);
    stream->Write32(v->mn68);
    stream->Write32(v->mn6c);
    stream->Write32(v->mn70);
    stream->Write32(v->mn74);
    stream->Write32(v->mn78);
    stream->Write32(list.size());
    ListNode* node = static_cast<ListNode*>(v->mpListNode)->mpNext;
    if (node != static_cast<ListNode*>(v->mpListNode)) {
        do {
            ListNode* cur = node;
            node = node->mpNext;
            stream->Write32(cur->mnValue);
        } while (node != static_cast<ListNode*>(v->mpListNode));
    }
    Fn005d99a0(stream, v->mpAC);
    return !stream->Fn18();
}

// FUNCTION: 0x00407ae0
bool cUnk00a808b8::Slot14_a80710(uint32_t mask, uint32_t set)
{
    uint32_t old = mnFlags;
    bool wasVisible = ((old >> 1) & 1) != 0;
    if (static_cast<uint8_t>(set)) {
        mnFlags = old | mask;
        if (mask & 2) {
            if (reinterpret_cast<Slot15View*>(this)->Test(0x10)) {
                Slot30_a808b8();
            }
            if (!wasVisible) {
                Slot23_a80710();
            }
        }
    } else {
        mnFlags = old & ~mask;
        if (mask & 2) {
            Slot14_a80710(0x10, 1);
            if (wasVisible) {
                Slot23_a80710();
            }
        }
    }
    if (mask & 0x200) {
        Slot14_a80710(0x10, 1);
    }
    return true;
}

// FUNCTION: 0x00407d70
uint32_t cUnk00a808b8::Slot19_a80710()
{
    uint32_t v[3] = {0, 0, 0};
    reinterpret_cast<cUnk00602f70*>(&field30)->Fn00602f70(v);
    return v[2];
}

// FUNCTION: 0x00407da0
uint32_t cUnk00a808b8::Slot21_a80710()
{
    uint32_t v[3] = {0, 0, 0};
    reinterpret_cast<cUnk00602f70*>(&field50)->Fn00602f70(v);
    return v[2];
}

// FUNCTION: 0x00407dd0
bool cUnk00a808b8::Slot24_a80710(uint32_t p)
{
    Slot14_a80710(0x10, 1);
    cUnk00a80710* pNew = reinterpret_cast<cUnk00a80710*>(p);
    cUnk00a80710* old = mpAC;
    if (pNew != old) {
        if (pNew) {
            pNew->AddRef();
        }
        mpAC = pNew;
        if (old) {
            old->Release();
        }
    }
    return true;
}

// FUNCTION: 0x00407e90
bool cUnk00a808b8::Slot04_a80710()
{
    if (mnB8 != -2 && gpB207c0) {
        cB207c0Item* o = gpB207c0->Fn10();
        if (o) {
            o->Fn62(mnB8);
        }
        mnB8 = -2;
    }
    return true;
}

// FUNCTION: 0x00407ed0
bool cUnk00a808b8::Slot22_a80710(uint32_t p)
{
    if (!reinterpret_cast<Slot15View*>(this)->Test(8) && reinterpret_cast<Slot15View*>(this)->Test(2)) {
        cB207c0* g = gpB207c0;
        g->Fn18(this);
        cB207c0Item* o = g->Fn10();
        const char* s = reinterpret_cast<cUnk00a80710Str*>(p)->Fn05();
        o->Fn55(s, static_cast<uint32_t>(std::strlen(s)), s);
        g->Fn19();
    }
    return true;
}

// FUNCTION: 0x00408970
bool cUnk00a808b8::Slot08_a80710()
{
    if (reinterpret_cast<Slot15View*>(this)->Test(0x400)) {
        return true;
    }
    bool r = Fn00408800();
    if (r) {
        r = !reinterpret_cast<Slot15View*>(this)->Test(0x80);
    }
    return r;
}

// FUNCTION: 0x00407b70
uint32_t cUnk00a808b8::Slot15_a80710(uint32_t flags)
{
    return (mnFlags & flags) == flags;
}

// ---- 0x00407c50 ----
// Views of the interfaces it talks to (only the slots called are named) and the two smart-pointer shapes it uses.
struct RefTarget {
    virtual void Pad00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual bool Fn03(uint32_t);
    virtual void Pad04();
    virtual void Pad05();
    virtual void Pad06();
    virtual void Pad07();
    virtual void Pad08();
    virtual void Pad09();
    virtual void Pad10();
    virtual void Pad11();
    virtual void Fn12(uint32_t);
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
    virtual void Fn24(RefTarget*);
};
struct Service {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Fn03(uint32_t);
};
struct Owner {
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
    virtual bool Fn13(RefTarget**);
};
struct ThirdBase {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual uint32_t Fn05(uint32_t, RefTarget**);
};

// STUB: 0x0090ddf1
Service* Fn0090ddf1();

// A reference that releases on destruction, and gives out the address of its pointer after releasing the old one.
struct InlineRef {
    RefTarget* mp;
    InlineRef() : mp(0) {}
    ~InlineRef()
    {
        if (mp) {
            mp->Release();
        }
    }
    RefTarget** operator&()
    {
        if (mp) {
            RefTarget* old = mp;
            mp = 0;
            old->Release();
        }
        return &mp;
    }
};
// The same shape, but the address-of is the original's out-of-line function.
struct OutOfLineRef {
    RefTarget* mp;
    OutOfLineRef() : mp(0) {}
    // STUB: 0x004f20a0
    RefTarget** operator&();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00407c50 score 8 (only the eax/edx choice for the vtable of the call through the third base differs)
bool cUnk00a808b8::Slot05_a80710(uint32_t pOut)
{
    if (mn88 != 0 && pOut != 0) {
        RefTarget** out = reinterpret_cast<RefTarget**>(pOut);
        *out = 0;
        RefTarget* local = 0;
        Service* svc = Fn0090ddf1();
        if (local) {
            RefTarget* old = local;
            local = 0;
            old->Release();
        }
        svc->Fn03(reinterpret_cast<ThirdBase*>(static_cast<cUnk00a80784*>(this))->Fn05(0x8a09f5f5, &local));
        if (local) {
            if (local->Fn03(mn88)) {
                RefTarget* p = local;
                p->Fn12(Slot11_a80710());
                Owner* owner = reinterpret_cast<Owner*>(Slot25_a80710());
                OutOfLineRef temp;
                if (!owner || owner->Fn13(&temp)) {
                    local->Fn24(temp.mp);
                    *out = local;
                    local->AddRef();
                    if (temp.mp) {
                        temp.mp->Release();
                    }
                    if (local) {
                        local->Release();
                    }
                    return true;
                }
                if (temp.mp) {
                    temp.mp->Release();
                }
            }
            if (local) {
                local->Release();
            }
        }
    }
    return false;
}
#endif
