#include <cstddef>
#include <new>

#include "classes/cSTEOverlayManager.h"
#include <cmath>

#include "game/Globals.h"
#include "gzcom/cIGZString.h"

// Views of the manager's records (0xb4 / 0x30 / 0x24 bytes each) and of the objects it talks to.
struct Rect_ab3930 {
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
};

struct Decal_ab3930 {
    uint32_t freeLink;
    uint32_t x;
    uint32_t z;
    uint32_t width;
    uint32_t turns;
    uint32_t aspectAdjust;
    uint32_t uRepeat;
    uint32_t vRepeat;
    uint32_t uvOffset;
    uint32_t userValue;
    uint32_t aspect;
    uint32_t overlay;
};

struct Ring_ab3930 {
    uint32_t freeLink;
    uint32_t overlay[8];
};

struct Released_ab3930 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
};

struct TexBinding_ab3930 {
    // STUB: 0x004664a0
    uint32_t AddRef();
    // STUB: 0x008090e0
    void Release();
};

struct Overlay_ab3930 {
    uint32_t freeLink;
    uint32_t flags;
    uint8_t drawMode;
    uint8_t pad09[3];
    Rect_ab3930 rect;
    float matrix[16];
    uint8_t pad5c[0x40];
    float alpha;
    uint32_t color[3];
    TexBinding_ab3930* mpTexture;
    Released_ab3930* mpObject;
    // STUB: 0x00735f40
    Overlay_ab3930();
    ~Overlay_ab3930()
    {
        if (mpObject) {
            mpObject->Release();
        }
        if (mpTexture) {
            mpTexture->Release();
        }
    }
    // STUB: 0x00735820
    Overlay_ab3930* Fn00735820(const Overlay_ab3930* src);
    Overlay_ab3930* Fn00735820Draft_ab3930(const Overlay_ab3930* src);
    // STUB: 0x007359f0
    Overlay_ab3930* Fn007359f0(const Overlay_ab3930* src);
};

struct Factory_ab3930 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void GetTexture(uint32_t instance, TexBinding_ab3930** out);
    virtual void GetTextureByKey(const void* key, TexBinding_ab3930** out);
    virtual void Pad07();
    virtual void GetTextureInfo(TexBinding_ab3930* tex, void* info);
    virtual void Pad09();
    virtual void Pad10();
    virtual uint32_t ShadowGroup();
};

struct Terrain_ab3930 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void Pad03();
    virtual void Pad04();
    virtual void Pad05();
    virtual float GetCellSize();
    virtual int32_t GetCellsX();
    virtual int32_t GetCellsZ();
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
    virtual void Redisplay(uint32_t a, uint32_t b, void* rect, uint32_t c);
};

struct ResKey_ab3930 {
    uint32_t type;
    uint32_t group;
    uint32_t instance;
};

struct View_ab3930 {
    // STUB: 0x00754f10
    void Fn00754f10(void* rect, uint32_t ctx);
    // STUB: 0x00754c60
    void Fn00754c60(void* rect, uint32_t ctx);
};

// The decal pool: a vector of 0x30-byte records threaded by a free list.
struct DecalPool_ab3930 {
    Decal_ab3930* mpBegin;
    Decal_ab3930* mpEnd;
    Decal_ab3930* mpCap;
    uint32_t mnHead;
    uint32_t mnTail;
    // STUB: 0x00736210
    void Fn00736210(uint32_t id);
    void Fn00736210Draft_ab3930(uint32_t id);
    // STUB: 0x00739ec0
    uint32_t Fn00739ec0(const Decal_ab3930* value);
    uint32_t Fn00739ec0Draft_ab3930(const Decal_ab3930* value);
    // STUB: 0x007385c0
    void Fn007385c0(Decal_ab3930* pos, const Decal_ab3930* value, void* tmp, uint32_t a, uint32_t b);
};

// The ring-decal pool: a vector of 0x24-byte records threaded by a free list.
struct RingPool_ab3930 {
    Ring_ab3930* mpBegin;
    Ring_ab3930* mpEnd;
    Ring_ab3930* mpCap;
    uint32_t mnHead;
    uint32_t mnTail;
    // STUB: 0x007386a0
    void Fn007386a0(Ring_ab3930* pos, const Ring_ab3930* value, void* tmp, uint32_t a, uint32_t b);
    // STUB: 0x00739fc0
    uint32_t Fn00739fc0(const Ring_ab3930* value);
    uint32_t Fn00739fc0Draft_ab3930(const Ring_ab3930* value);
};

// The overlay pool: a vector of 0xb4-byte records threaded by a free list.
struct OverlayPool_ab3930 {
    Overlay_ab3930* mpBegin;
    Overlay_ab3930* mpEnd;
    Overlay_ab3930* mpCap;
    uint32_t mnHead;
    uint32_t mnTail;
    // STUB: 0x0073a070
    void Fn0073a070(Overlay_ab3930* pos, const Overlay_ab3930* value, void* tmp, uint32_t a, uint32_t b);
    uint32_t Fn0073aec0Draft_ab3930(const Overlay_ab3930* value);
    // STUB: 0x0073aec0
    uint32_t Fn0073aec0(const Overlay_ab3930* value);
};

struct SNode_ab3930 {
    SNode_ab3930* mpNext;
    uint32_t mnValue;
};

// A singly linked list head (the next pointer is the node's first word).
struct SList_ab3930 {
    SNode_ab3930* mpHead;
    void Fn00738590();
    // STUB: 0x00737db0
    SList_ab3930* Fn00737db0(const SList_ab3930* src);
    SList_ab3930* Fn00737db0Draft_ab3930(const SList_ab3930* src);
};

// The grid of slist buckets (a vector of 4-byte list heads).
struct SListVec_ab3930 {
    SList_ab3930* mpBegin;
    SList_ab3930* mpEnd;
    SList_ab3930* mpCap;
    // STUB: 0x0073cab0
    void Fn0073cab0(uint32_t n, SList_ab3930* value);
};

// An overlay id: a decal id (top bit set) names the decal's overlay, which may be a ring's first overlay.
#define OBS_RESOLVE(idv) \
    if ((idv & 0x80000000)) { \
        idv = reinterpret_cast<Decal_ab3930*>(mpDecals)[idv & 0x7fffffff].overlay; \
        if ((idv & 0x80000000)) { \
            idv = reinterpret_cast<Ring_ab3930*>(mpRings)[idv & 0x7fffffff].overlay[0]; \
        } \
    }

// STUB: 0x00736280
void Fn00736280(Decal_ab3930* dst, const Decal_ab3930* src);
// STUB: 0x0090cf63
void Fn0090cf63(void* p);
// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);

// FUNCTION: 0x007352a0
void cSTEOverlayManager::Slot27_ab3930(uint32_t a)
{
    cIGZString* out = OB_PTR(cIGZString, a);
    out->Sprintf("%d decals, %d shadows", mnDecalsDrawn, mnShadowsDrawn);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00736580 score 22
void cSTEOverlayManager::Slot22_ab3930(uint32_t id)
{
    if (id == 0xffffffff) {
        return;
    }
    OBS_RESOLVE(id)
    reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].flags & 1;
}
#endif

// FUNCTION: 0x007365e0
float cSTEOverlayManager::Slot23_ab3930(uint32_t id)
{
    if (id == 0xffffffff) {
        return 0.0f;
    }
    OBS_RESOLVE(id)
    return reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].alpha;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00736640 score 18
void cSTEOverlayManager::Slot24_ab3930(uint32_t out, uint32_t id)
{
    uint32_t* dst = OB_PTR(uint32_t, out);
    if (id == 0xffffffff) {
        dst[0] = 0;
        dst[1] = 0;
        dst[2] = 0;
        return;
    }
    OBS_RESOLVE(id)
    Overlay_ab3930* o = &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id];
    dst[0] = o->color[0];
    dst[1] = o->color[1];
    dst[2] = o->color[2];
}
#endif

// FUNCTION: 0x007366c0
uint32_t cSTEOverlayManager::Slot25_ab3930(uint32_t id)
{
    if (id == 0xffffffff) {
        return 0;
    }
    OBS_RESOLVE(id)
    return reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].drawMode;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00736720 score 31
uint32_t cSTEOverlayManager::Slot26_ab3930(uint32_t id)
{
    if (id == 0xffffffff) {
        return 0;
    }
    OBS_RESOLVE(id)
    return (reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].flags >> 6) & 1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00736490 score 24
void cSTEOverlayManager::Slot14_ab3930(uint32_t id, uint32_t out)
{
    if (id != 0xffffffff && (id & 0x80000000)) {
        Decal_ab3930* d = &reinterpret_cast<Decal_ab3930*>(mpDecals)[id & 0x7fffffff];
        Decal_ab3930* o = OB_PTR(Decal_ab3930, out);
        o->freeLink = d->x;
        o->x = d->z;
        o->z = d->width;
        o->width = d->turns;
        o->turns = d->aspectAdjust;
        o->aspectAdjust = d->uRepeat;
        o->uRepeat = d->vRepeat;
        o->vRepeat = d->uvOffset;
        o->uvOffset = d->userValue;
    }
}
#endif

// FUNCTION: 0x007364f0
void cSTEOverlayManager::Slot20_ab3930(uint32_t id, uint32_t flags)
{
    if (id == 0xffffffff) {
        return;
    }
    if ((id & 0x80000000)) {
        id = reinterpret_cast<Decal_ab3930*>(mpDecals)[id & 0x7fffffff].overlay;
        if ((id & 0x80000000)) {
            Ring_ab3930* r = &reinterpret_cast<Ring_ab3930*>(mpRings)[id & 0x7fffffff];
            for (int i = 0; i < 8; i++) {
                Slot20_ab3930(r->overlay[i], flags);
            }
            return;
        }
    }
    if (flags & 1) {
        reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].flags |= 0x40;
    }
}

// FUNCTION: 0x00736150
uint32_t cSTEOverlayManager::Slot05_ab3930(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    TexBinding_ab3930* tex = 0;
    reinterpret_cast<Factory_ab3930*>(mpTextureFactory)->GetTextureByKey(OB_PTR(const void, a), &tex);
    uint32_t r = Slot04_ab3930(OB_ADDR(tex), b, c, d);
    if (tex) {
        tex->Release();
    }
    return r;
}

// FUNCTION: 0x007361b0
uint32_t cSTEOverlayManager::Slot06_ab3930(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    TexBinding_ab3930* tex = 0;
    reinterpret_cast<Factory_ab3930*>(mpTextureFactory)->GetTexture(a, &tex);
    uint32_t r = Slot04_ab3930(OB_ADDR(tex), b, c, d);
    if (tex) {
        tex->Release();
    }
    return r;
}

// FUNCTION: 0x0073c0b0
void cSTEOverlayManager::Slot03_ab3930(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Fn0073af80(a, 0, b, c, d);
}

// FUNCTION: 0x00739490
bool cSTEOverlayManager::Slot03_a881c0(uint32_t a)
{
    Fn00738a50(a);
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00735480 score 6
void cSTEOverlayManager::Slot10_ab3930(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    if (mnQuality == 0) {
        return;
    }
    ResKey_ab3930 key;
    key.group = reinterpret_cast<Factory_ab3930*>(mpTextureFactory)->ShadowGroup();
    key.instance = a;
    key.type = 0x7ab50e44;
    Slot09_ab3930(OB_ADDR(&key), b, c, d, e);
}
#endif

// FUNCTION: 0x00736210
void DecalPool_ab3930::Fn00736210Draft_ab3930(uint32_t id)
{
    Decal_ab3930* d = &mpBegin[id];
    if (d->freeLink == 0xffffffff) {
        d->freeLink = 0;
        if (mnTail != 0xffffffff) {
            mpBegin[mnTail].freeLink = id;
            mnTail = id;
        } else {
            mnHead = id;
            mnTail = id;
        }
    }
}

// FUNCTION: 0x00737e10
void Fn00737e10(Overlay_ab3930* first, Overlay_ab3930* last)
{
    for (; first != last; first++) {
        Released_ab3930* obj = first->mpObject;
        if (obj) {
            obj->Release();
        }
        TexBinding_ab3930* tex = first->mpTexture;
        if (tex) {
            tex->Release();
        }
    }
}

// FUNCTION: 0x00738590
void SList_ab3930::Fn00738590()
{
    SNode_ab3930* p = mpHead;
    while (p) {
        SNode_ab3930* node = p;
        p = p->mpNext;
        Fn0090cf63(node);
    }
    mpHead = 0;
}

// Inlined into its callers (its out-of-line copy at 0x007352d0 is not matched yet: score 20).
inline bool NearEqual_ab3930(const float* a, const float* b)
{
    if (std::fabs(a[0] - b[0]) >= 0.0001f) {
        return false;
    }
    if (std::fabs(a[1] - b[1]) >= 0.0001f) {
        return false;
    }
    return true;
}

bool Fn007352d0(const float* a, const float* b)
{
    return !NearEqual_ab3930(a, b);
}

// FUNCTION: 0x00736280
void Fn00736280Draft_ab3930(Decal_ab3930* dst, const Decal_ab3930* src)
{
    if (dst) {
        dst->freeLink = src->freeLink;
        dst->x = src->x;
        dst->z = src->z;
        dst->width = src->width;
        dst->turns = src->turns;
        dst->aspectAdjust = src->aspectAdjust;
        dst->uRepeat = src->uRepeat;
        dst->vRepeat = src->vRepeat;
        dst->uvOffset = src->uvOffset;
        dst->userValue = src->userValue;
        dst->aspect = src->aspect;
        dst->overlay = src->overlay;
    }
}

// FUNCTION: 0x00736320
Overlay_ab3930* Fn00736320(Overlay_ab3930* dst, uint32_t n, const Overlay_ab3930* src)
{
    Overlay_ab3930* cur = dst;
    for (; n > 0; n--) {
        if (cur) {
            cur->Fn007359f0(src);
        }
        cur++;
    }
    return cur;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007362e0 score 6
Overlay_ab3930* Fn007362e0(const Overlay_ab3930* first, const Overlay_ab3930* last, Overlay_ab3930* dst)
{
    while (first != last) {
        if (dst) {
            dst->Fn007359f0(first);
        }
        first++;
        dst++;
    }
    return dst;
}
#endif

// FUNCTION: 0x00736250
SNode_ab3930* OB_STDCALL Fn00736250(SNode_ab3930* before, SNode_ab3930* end)
{
    SNode_ab3930* p = before->mpNext;
    while (p != end) {
        SNode_ab3930* node = p;
        p = p->mpNext;
        Fn0090cf63(node);
    }
    before->mpNext = end;
    return end;
}

// STUB: 0x00736440
void OB_STDCALL Fn00736440(SNode_ab3930* before, SNode_ab3930* first, SNode_ab3930* last, void* alloc);

// FUNCTION: 0x00736440
void OB_STDCALL Fn00736440Draft_ab3930(SNode_ab3930* before, SNode_ab3930* first, SNode_ab3930* last, void* /*alloc*/)
{
    while (first != last) {
        SNode_ab3930* node = static_cast<SNode_ab3930*>(Fn0090cf54(8));
        uint32_t* vp = &node->mnValue;
        if (vp) {
            *vp = first->mnValue;
        }
        node->mpNext = 0;
        node->mpNext = before->mpNext;
        before->mpNext = node;
        first = first->mpNext;
        before = node;
    }
}

// FUNCTION: 0x00738800
SList_ab3930* Fn00738800(const SList_ab3930* first, const SList_ab3930* last, SList_ab3930* dst)
{
    int32_t n = last - first;
    for (; n > 0; n--) {
        dst->Fn00737db0(first);
        first++;
        dst++;
    }
    return dst;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00738840 score 20
SList_ab3930* Fn00738840(SList_ab3930* dst, uint32_t n, const SList_ab3930* value)
{
    uint32_t alloc;
    SList_ab3930* cur = dst;
    for (; n > 0; n--) {
        if (cur) {
            cur->mpHead = 0;
            Fn00736440(reinterpret_cast<SNode_ab3930*>(cur), value->mpHead, 0, &alloc);
        }
        cur++;
    }
    return cur;
}
#endif

// FUNCTION: 0x00738880
SList_ab3930* Fn00738880(const SList_ab3930* first, const SList_ab3930* last, SList_ab3930* dst)
{
    int32_t n = last - first;
    for (; n > 0; n--) {
        last--;
        dst--;
        dst->Fn00737db0(last);
    }
    return dst;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00739450 score 24
SList_ab3930* Fn00739450(const SList_ab3930* first, const SList_ab3930* last, SList_ab3930* dst)
{
    uint32_t alloc;
    for (; first != last; first++) {
        if (dst) {
            dst->mpHead = 0;
            Fn00736440(reinterpret_cast<SNode_ab3930*>(dst), first->mpHead, 0, &alloc);
        }
        dst++;
    }
    return dst;
}
#endif

// FUNCTION: 0x007387d0
void Fn007387d0(SList_ab3930* first, SList_ab3930* last, const SList_ab3930* value)
{
    for (; first != last; first++) {
        first->Fn00737db0(value);
    }
}

// FUNCTION: 0x0073a170
void Fn0073a170(SList_ab3930* first, SList_ab3930* last)
{
    for (; first != last; first++) {
        SNode_ab3930* p = first->mpHead;
        while (p) {
            SNode_ab3930* node = p;
            p = p->mpNext;
            Fn0090cf63(node);
        }
        first->mpHead = 0;
    }
}

// FUNCTION: 0x00735cb0
Overlay_ab3930* Fn00735cb0(const Overlay_ab3930* first, const Overlay_ab3930* last, Overlay_ab3930* dst)
{
    int32_t n = last - first;
    for (; n > 0; n--) {
        dst->Fn00735820(first);
        first++;
        dst++;
    }
    return dst;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007356d0 score 29
void cSTEOverlayManager::Fn007356d0(void* rectp, uint32_t ctx)
{
    const Rect_ab3930* p = static_cast<const Rect_ab3930*>(rectp);
    Rect_ab3930 r;
    r.left = p->left;
    r.top = p->top;
    r.right = p->right + 1;
    r.bottom = p->bottom + 1;
    View_ab3930* v = static_cast<View_ab3930*>(mpView);
    if (mbDynamic) {
        v->Fn00754f10(&r, ctx);
    } else {
        v->Fn00754c60(&r, ctx);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00737d40 score 43
void cSTEOverlayManager::RedisplayStaticOverlay(uint32_t slot)
{
    Rect_ab3930* rc = &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[slot].rect;
    int32_t left = rc->left;
    int32_t top = rc->top;
    int32_t right = rc->right;
    int32_t bottom = rc->bottom;
    if (right > left && bottom > top) {
        Rect_ab3930 r;
        r.left = left;
        r.top = top;
        r.right = right;
        r.bottom = bottom;
        static_cast<Terrain_ab3930*>(mpTerrain)->Redisplay(0, mbFlag16, &r, 0);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00737db0 score 19
SList_ab3930* SList_ab3930::Fn00737db0Draft_ab3930(const SList_ab3930* other)
{
    if (other != this) {
        SNode_ab3930* cur = mpHead;
        SNode_ab3930* src = other->mpHead;
        SNode_ab3930* prev = reinterpret_cast<SNode_ab3930*>(this);
        while (cur && src) {
            cur->mnValue = src->mnValue;
            src = src->mpNext;
            prev = cur;
            cur = cur->mpNext;
        }
        if (src) {
            uint32_t alloc;
            Fn00736440(prev, src, 0, &alloc);
        } else {
            Fn00736250(prev, 0);
        }
    }
    return this;
}
#endif

// FUNCTION: 0x0073ad80
void cSTEOverlayManager::Slot12_ab3930(uint32_t id, uint32_t pos)
{
    if (id != 0xffffffff && (id & 0x80000000)) {
        Decal_ab3930* d = &reinterpret_cast<Decal_ab3930*>(mpDecals)[id & 0x7fffffff];
        uint32_t* p = OB_PTR(uint32_t, pos);
        uint32_t* dstv = &d->x;
        if (Fn007352d0(OB_PTR(float, pos), reinterpret_cast<float*>(dstv))) {
            dstv[0] = p[0];
            dstv[1] = p[1];
            Fn0073a1b0(d, !mbDynamic);
        }
    }
}

// FUNCTION: 0x0073ade0
void cSTEOverlayManager::Slot13_ab3930(uint32_t id, uint32_t info)
{
    if (id != 0xffffffff && (id & 0x80000000)) {
        Decal_ab3930* d = &reinterpret_cast<Decal_ab3930*>(mpDecals)[id & 0x7fffffff];
        uint32_t* i = OB_PTR(uint32_t, info);
        d->x = i[0];
        d->z = i[1];
        d->width = i[2];
        d->turns = i[3];
        d->aspectAdjust = i[4];
        d->uRepeat = i[5];
        d->vRepeat = i[6];
        d->uvOffset = i[7];
        d->userValue = i[8];
        Fn0073a1b0(d, !mbDynamic);
    }
}

// FUNCTION: 0x007380c0
void cSTEOverlayManager::Slot19_ab3930(uint32_t id, uint32_t mode)
{
    if (id == 0xffffffff) {
        return;
    }
    if (id & 0x80000000) {
        id = reinterpret_cast<Decal_ab3930*>(mpDecals)[id & 0x7fffffff].overlay;
        if (id & 0x80000000) {
            Ring_ab3930* r = &reinterpret_cast<Ring_ab3930*>(mpRings)[id & 0x7fffffff];
            for (int i = 0; i < 8; i++) {
                Slot19_ab3930(r->overlay[i], mode);
            }
            return;
        }
    }
    reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].drawMode = static_cast<uint8_t>(mode);
    if (!mbDynamic) {
        RedisplayStaticOverlay(id);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00736350 score 77
void Fn00736350(const Decal_ab3930* first, const Decal_ab3930* last, Decal_ab3930* dst)
{
    for (; first != last; first++) {
        if (dst) {
            dst->freeLink = first->freeLink;
            dst->x = first->x;
            dst->z = first->z;
            dst->width = first->width;
            dst->turns = first->turns;
            dst->aspectAdjust = first->aspectAdjust;
            dst->uRepeat = first->uRepeat;
            dst->vRepeat = first->vRepeat;
            dst->uvOffset = first->uvOffset;
            dst->userValue = first->userValue;
            dst->aspect = first->aspect;
            dst->overlay = first->overlay;
        }
        dst++;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007363d0 score 68
void Fn007363d0(Decal_ab3930* dst, uint32_t n, const Decal_ab3930* value)
{
    for (; n > 0; n--) {
        if (dst) {
            dst->freeLink = value->freeLink;
            dst->x = value->x;
            dst->z = value->z;
            dst->width = value->width;
            dst->turns = value->turns;
            dst->aspectAdjust = value->aspectAdjust;
            dst->uRepeat = value->uRepeat;
            dst->vRepeat = value->vRepeat;
            dst->uvOffset = value->uvOffset;
            dst->userValue = value->userValue;
            dst->aspect = value->aspect;
            dst->overlay = value->overlay;
        }
        dst++;
    }
}
#endif

// FUNCTION: 0x00738a10
void cSTEOverlayManager::Fn00738a10(uint32_t id)
{
    if (id != 0xffffffff && !mbDynamic) {
        Fn00738230(id, &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].rect);
        RedisplayStaticOverlay(id);
    }
}

// FUNCTION: 0x0073cb10
void cSTEOverlayManager::Fn0073cb10()
{
    mnGridWidth = mnCellsX;
    mnGridHeight = mnCellsZ;
    mnGridOrigin = 0;
    SList_ab3930 empty;
    empty.mpHead = 0;
    static_cast<SListVec_ab3930*>(static_cast<void*>(&mpGrid))->Fn0073cab0(mnCellsZ * mnCellsX, &empty);
    mnGridFlags = 0;
}

// FUNCTION: 0x00737e50
void cSTEOverlayManager::Slot16_ab3930(uint32_t id, uint32_t enable)
{
    if (id == 0xffffffff) {
        return;
    }
    if (id & 0x80000000) {
        id = reinterpret_cast<Decal_ab3930*>(mpDecals)[id & 0x7fffffff].overlay;
        if (id & 0x80000000) {
            Ring_ab3930* r = &reinterpret_cast<Ring_ab3930*>(mpRings)[id & 0x7fffffff];
            for (int i = 0; i < 8; i++) {
                Slot16_ab3930(r->overlay[i], enable);
            }
            return;
        }
    }
    uint32_t* fp = &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].flags;
    if (static_cast<uint8_t>(enable)) {
        *fp |= 1;
    } else {
        *fp &= ~1u;
    }
    if (!mbDynamic) {
        RedisplayStaticOverlay(id);
    }
}

// FUNCTION: 0x00737f00
void cSTEOverlayManager::Slot17_ab3930(uint32_t id, uint32_t alphaBits)
{
    if (id == 0xffffffff) {
        return;
    }
    if (id & 0x80000000) {
        id = reinterpret_cast<Decal_ab3930*>(mpDecals)[id & 0x7fffffff].overlay;
        if (id & 0x80000000) {
            Ring_ab3930* r = &reinterpret_cast<Ring_ab3930*>(mpRings)[id & 0x7fffffff];
            for (int i = 0; i < 8; i++) {
                Slot17_ab3930(r->overlay[i], alphaBits);
            }
            return;
        }
    }
    float alpha = *reinterpret_cast<float*>(&alphaBits);
    if (!mbDynamic) {
        float* stored = &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].alpha;
        float old = *stored;
        if (old != alpha) {
            if (alpha == 0.0f || alpha == 1.0f || std::fabs(alpha - old) > 0.05) {
                *stored = alpha;
                RedisplayStaticOverlay(id);
            }
        }
    } else {
        reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].alpha = alpha;
    }
}

// FUNCTION: 0x00738010
void cSTEOverlayManager::Slot18_ab3930(uint32_t id, uint32_t rgb)
{
    if (id == 0xffffffff) {
        return;
    }
    if (id & 0x80000000) {
        id = reinterpret_cast<Decal_ab3930*>(mpDecals)[id & 0x7fffffff].overlay;
        if (id & 0x80000000) {
            Ring_ab3930* r = &reinterpret_cast<Ring_ab3930*>(mpRings)[id & 0x7fffffff];
            for (int i = 0; i < 8; i++) {
                Slot18_ab3930(r->overlay[i], rgb);
            }
            return;
        }
    }
    uint32_t* dst = reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].color;
    const uint32_t* src = OB_PTR(const uint32_t, rgb);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    if (!mbDynamic) {
        RedisplayStaticOverlay(id);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00738160 score 47
void cSTEOverlayManager::Slot21_ab3930(uint32_t id, uint32_t scaleBits, uint32_t offsetBits)
{
    if (id == 0xffffffff) {
        return;
    }
    if (id & 0x80000000) {
        id = reinterpret_cast<Decal_ab3930*>(mpDecals)[id & 0x7fffffff].overlay;
    }
    float scale = *reinterpret_cast<float*>(&scaleBits);
    float offset = *reinterpret_cast<float*>(&offsetBits);
    float inv = 1.0f / scale;
    float neg = -inv;
    float t = inv * offset + 1.0f;
    Overlay_ab3930* o = &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id];
    o->flags |= 0x20;
    float* m = reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].matrix;
    m[0] = inv;
    m[1] = 0.0f;
    m[2] = 0.0f;
    m[3] = 0.0f;
    m[4] = 0.0f;
    m[5] = neg;
    m[6] = 0.0f;
    m[7] = 0.0f;
    m[8] = inv;
    m[9] = 0.0f;
    m[10] = 1.0f;
    m[11] = 0.0f;
    m[12] = 0.0f;
    m[13] = t;
    m[14] = 0.0f;
    m[15] = 1.0f;
    if (!mbDynamic) {
        RedisplayStaticOverlay(id);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007388c0 score 52
void cSTEOverlayManager::Slot15_ab3930(uint32_t id)
{
    if (id == 0xffffffff) {
        return;
    }
    if (id & 0x80000000) {
        uint32_t decalId = id & 0x7fffffff;
        id = reinterpret_cast<Decal_ab3930*>(mpDecals)[decalId].overlay;
        reinterpret_cast<DecalPool_ab3930*>(&mpDecals)->Fn00736210(decalId);
        if (id & 0x80000000) {
            uint32_t ringId = id & 0x7fffffff;
            Ring_ab3930* r = &reinterpret_cast<Ring_ab3930*>(mpRings)[ringId];
            for (int i = 0; i < 8; i++) {
                Slot15_ab3930(r->overlay[i]);
            }
            Ring_ab3930* ring = &reinterpret_cast<Ring_ab3930*>(mpRings)[ringId];
            if (ring->freeLink == 0xffffffff) {
                ring->freeLink = 0;
                if (mnRingsTail != 0xffffffff) {
                    reinterpret_cast<Ring_ab3930*>(mpRings)[mnRingsTail].freeLink = ringId;
                    mnRingsTail = ringId;
                } else {
                    mnRingsHead = ringId;
                    mnRingsTail = ringId;
                }
            }
            return;
        }
    }
    if (!mbDynamic) {
        Fn007382e0(id, &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id].rect);
        RedisplayStaticOverlay(id);
    }
    Overlay_ab3930* o = &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[id];
    if (o->freeLink == 0xffffffff) {
        o->freeLink = 0;
        if (mnOverlaysTail != 0xffffffff) {
            reinterpret_cast<Overlay_ab3930*>(mpOverlays)[mnOverlaysTail].freeLink = id;
            mnOverlaysTail = id;
        } else {
            mnOverlaysHead = id;
            mnOverlaysTail = id;
        }
    }
}
#endif

// FUNCTION: 0x0073aec0
uint32_t OverlayPool_ab3930::Fn0073aec0Draft_ab3930(const Overlay_ab3930* value)
{
    uint32_t head = mnHead;
    if (head == 0xffffffff) {
        Overlay_ab3930* end = mpEnd;
        if (end != mpCap) {
            if (end) {
                end->Fn007359f0(value);
            }
            mpEnd += 1;
        } else {
            uint32_t tmp;
            Fn0073a070(end, value, &tmp, 1, 1);
        }
        mpEnd[-1].freeLink = 0xffffffff;
        return static_cast<uint32_t>(mpEnd - mpBegin) - 1;
    }
    if (head == mnTail) {
        mnHead = 0xffffffff;
        mnTail = 0xffffffff;
    } else {
        mnHead = mpBegin[head].freeLink;
    }
    mpBegin[head].Fn00735820(value);
    mpBegin[head].freeLink = 0xffffffff;
    return head;
}

struct SvcMgr_ab3930 {
    virtual void Pad00();
    virtual void Pad01();
    virtual void Pad02();
    virtual void Pad03();
    virtual void Pad04();
    virtual void GetService(uint32_t sid, uint32_t iid, void** out);
};

struct ServPtr_ab3930 {
    Released_ab3930* mp;
    ServPtr_ab3930() : mp(0) {}
    // STUB: 0x004495c0
    ~ServPtr_ab3930();
};

struct RenderProps_ab3930 {
    uint8_t pad00[0x18];
    uint8_t* mpItems;
};

// STUB: 0x008793ec
SvcMgr_ab3930* Fn008793ec();

// GLOBAL: 0x00b43cf4
extern Terrain_ab3930* gpB43cf4;
// GLOBAL: 0x00b43cc4
extern RenderProps_ab3930* gpB43cc4;

#ifdef OB_DRAFTS
// CLOSE: 0x0073cb60 score 133
void cSTEOverlayManager::Init(void* view, bool dynamic, bool flag)
{
    Released_ab3930* newView = static_cast<Released_ab3930*>(view);
    Released_ab3930* oldView = static_cast<Released_ab3930*>(mpView);
    if (newView != oldView) {
        if (newView) {
            newView->AddRef();
        }
        mpView = newView;
        if (oldView) {
            oldView->Release();
        }
    }
    mbDynamic = dynamic;
    mbFlag16 = flag;
    mbInitialized = true;
    {
        ServPtr_ab3930 svc;
        SvcMgr_ab3930* mgr = Fn008793ec();
        if (mgr) {
            mgr->GetService(0x1ac0e11a, 0xfac0e219, reinterpret_cast<void**>(&svc.mp));
        }
        Released_ab3930* newFactory = svc.mp;
        Released_ab3930* oldFactory = static_cast<Released_ab3930*>(mpTextureFactory);
        if (newFactory != oldFactory) {
            if (newFactory) {
                newFactory->AddRef();
            }
            mpTextureFactory = newFactory;
            if (oldFactory) {
                oldFactory->Release();
            }
        }
    }
    Terrain_ab3930* newTerrain = gpB43cf4;
    Terrain_ab3930* oldTerrain = static_cast<Terrain_ab3930*>(mpTerrain);
    if (newTerrain != oldTerrain) {
        if (newTerrain) {
            newTerrain->AddRef();
        }
        mpTerrain = newTerrain;
        if (oldTerrain) {
            oldTerrain->Release();
        }
    }
    mnCellsX = static_cast<Terrain_ab3930*>(mpTerrain)->GetCellsX();
    mnCellsZ = static_cast<Terrain_ab3930*>(mpTerrain)->GetCellsZ();
    mfCellSize = static_cast<Terrain_ab3930*>(mpTerrain)->GetCellSize();
    mfInvCellSize = 1.0f / mfCellSize;
    float x = static_cast<float>(mnCellsX);
    mfExtentX = x * mfCellSize;
    mfExtentX2 = x * mfCellSize;
    mfExtentZ = static_cast<float>(mnCellsZ) * mfCellSize;
    mnRectLeft = 0;
    mnRectTop = 0;
    mnRectRight = mnCellsX;
    mnRectBottom = mnCellsZ;
    Released_ab3930* factory = static_cast<Released_ab3930*>(mpTextureFactory);
    mnDecalsDrawn = 0;
    mnShadowsDrawn = 0;
    mnField94 = 0;
    TexBinding_ab3930* tex = static_cast<TexBinding_ab3930*>(mpTexBinding);
    if (tex) {
        mpTexBinding = 0;
        tex->Release();
    }
    static_cast<Factory_ab3930*>(static_cast<void*>(factory))->GetTexture(0xaa592b77, reinterpret_cast<TexBinding_ab3930**>(&mpTexBinding));
    InitDrawStates();
    if (!mbDynamic) {
        Fn0073cb10();
    }
    if (gpB43ccc) {
        gpB43ccc->AddNotification(static_cast<cUnk00aaaa9c*>(this), 0xc9f775bb);
    }
    mnQuality = *reinterpret_cast<uint32_t*>(gpB43cc4->mpItems + 0x1fc);
    mnProp1c = *reinterpret_cast<uint32_t*>(gpB43cc4->mpItems + 0xbc);
}
#endif

struct RenderState_ab3930 {
    uint32_t mWords[2];
    // STUB: 0x007d2b50
    void PackRenderState(bool a, bool b, bool c, bool d, bool e, int32_t f, bool g, int32_t h, int32_t i, int32_t j, int32_t k, float l, int32_t m, int32_t n);
};

struct RenderStateVec_ab3930 {
    RenderState_ab3930* mpBegin;
    RenderState_ab3930* mpEnd;
    RenderState_ab3930* mpCap;
    // STUB: 0x0073ae60
    void Resize(uint32_t n);
};

// FUNCTION: 0x0073ba10
void cSTEOverlayManager::InitDrawStates()
{
    reinterpret_cast<RenderStateVec_ab3930*>(&mpRenderStates)->Resize(5);
    static_cast<RenderState_ab3930*>(mpRenderStates)[0].PackRenderState(true, false, true, false, true, 1, false, 3, 4, 5, -1, -1.0f, 1, -1);
    static_cast<RenderState_ab3930*>(mpRenderStates)[1].PackRenderState(true, false, true, false, true, 1, false, 3, 4, 1, -1, -1.0f, 1, -1);
    static_cast<RenderState_ab3930*>(mpRenderStates)[2].PackRenderState(true, false, true, false, true, 1, false, 3, 0, 2, -1, -1.0f, 1, -1);
    static_cast<RenderState_ab3930*>(mpRenderStates)[3].PackRenderState(true, false, true, false, true, 1, false, 4, 4, 5, -1, -1.0f, 1, -1);
    static_cast<RenderState_ab3930*>(mpRenderStates)[4].PackRenderState(true, true, true, true, true, 1, false, 1, 4, 5, 4, 0.5f, -1, -1);
    mbComb38 = 0;
    mbComb3d = 0;
    mbComb44 = 0;
    mbComb49 = 0;
    mbComb50 = 0;
    mbComb51 = 0;
    mbComb54 = 0;
    mbComb55 = 0;
    mbComb39 = 2;
    mbComb3c = 1;
    mbComb3e = 2;
    mbComb45 = 1;
    mbComb48 = 1;
    mbComb4a = 1;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0073b8a0 score 2
uint32_t cSTEOverlayManager::Fn0073b8a0(void* texture, void* rect, void* matrix, uint32_t flags)
{
    TexBinding_ab3930* tex = static_cast<TexBinding_ab3930*>(texture);
    if (!tex) {
        return 0xffffffff;
    }
    Overlay_ab3930 o;
    TexBinding_ab3930* old = o.mpTexture;
    if (tex != old) {
        tex->AddRef();
        o.mpTexture = tex;
        if (old) {
            old->Release();
        }
    }
    const uint32_t* m = static_cast<const uint32_t*>(matrix);
    for (int i = 0; i < 16; i++) {
        reinterpret_cast<uint32_t*>(o.matrix)[i] = m[i];
    }
    const uint32_t* rc = static_cast<const uint32_t*>(rect);
    o.rect.left = rc[0];
    o.rect.top = rc[1];
    o.rect.right = rc[2];
    o.rect.bottom = rc[3];
    o.flags |= flags;
    uint32_t idx = reinterpret_cast<OverlayPool_ab3930*>(&mpOverlays)->Fn0073aec0(&o);
    if (idx != 0xffffffff && !mbDynamic) {
        Fn00738230(idx, &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[idx].rect);
        RedisplayStaticOverlay(idx);
    }
    return idx;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00735380 score 88
void Fn00735380(const float* in, int32_t* out)
{
    out[0] = static_cast<int32_t>(std::floor(in[0]));
    out[1] = static_cast<int32_t>(std::floor(in[1]));
    out[2] = static_cast<int32_t>(std::ceil(in[2]));
    out[3] = static_cast<int32_t>(std::ceil(in[3]));
}
#endif

struct TexInfo_ab3930 {
    uint32_t pad00[3];
    uint32_t width;
    uint32_t height;
    uint32_t pad14[2];
};

struct TextSize_ab3930 {
    uint32_t width;
    uint32_t height;
};

struct StringTexture_ab3930 {
    virtual void Pad00();
    virtual void AddRef();
    virtual void Release();
    virtual void GetSize(TextSize_ab3930* out);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0073af80 score 95
uint32_t cSTEOverlayManager::Fn0073af80(uint32_t text, uint32_t texture, uint32_t pos, uint32_t width, uint32_t turns)
{
    StringTexture_ab3930* str = OB_PTR(StringTexture_ab3930, text);
    TexBinding_ab3930* tex = OB_PTR(TexBinding_ab3930, texture);
    if (!tex && !str) {
        return 0xffffffff;
    }
    const uint32_t* p = OB_PTR(const uint32_t, pos);
    Decal_ab3930 d;
    d.x = p[0];
    d.z = p[1];
    d.width = width;
    d.turns = turns;
    reinterpret_cast<float&>(d.aspectAdjust) = 1.0f;
    reinterpret_cast<float&>(d.uRepeat) = 1.0f;
    reinterpret_cast<float&>(d.vRepeat) = 1.0f;
    reinterpret_cast<float&>(d.uvOffset) = 0.0f;
    reinterpret_cast<float&>(d.userValue) = 0.0f;
    float aspect;
    if (tex) {
        TexInfo_ab3930 info;
        reinterpret_cast<Factory_ab3930*>(mpTextureFactory)->GetTextureInfo(tex, &info);
        aspect = static_cast<float>(info.height) / static_cast<float>(info.width);
    } else {
        TextSize_ab3930 size;
        str->GetSize(&size);
        aspect = static_cast<float>(size.height) / static_cast<float>(size.width);
    }
    reinterpret_cast<float&>(d.aspect) = aspect;
    Overlay_ab3930 o;
    TexBinding_ab3930* oldTex = o.mpTexture;
    if (tex != oldTex) {
        if (tex) {
            tex->AddRef();
        }
        o.mpTexture = tex;
        if (oldTex) {
            oldTex->Release();
        }
    }
    Released_ab3930* oldObj = o.mpObject;
    if (str != reinterpret_cast<StringTexture_ab3930*>(oldObj)) {
        if (str) {
            str->AddRef();
        }
        o.mpObject = reinterpret_cast<Released_ab3930*>(str);
        if (oldObj) {
            oldObj->Release();
        }
    }
    o.flags |= 0x90;
    OverlayPool_ab3930* pool = reinterpret_cast<OverlayPool_ab3930*>(&mpOverlays);
    uint32_t idx = pool->Fn0073aec0(&o);
    d.overlay = idx;
    Fn0073a1b0(&d, false);
    if (idx != 0xffffffff && !mbDynamic) {
        Fn00738230(idx, &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[idx].rect);
        RedisplayStaticOverlay(idx);
    }
    uint32_t slot = reinterpret_cast<DecalPool_ab3930*>(&mpDecals)->Fn00739ec0(&d);
    return slot | 0x80000000;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00739ec0 score 4
uint32_t DecalPool_ab3930::Fn00739ec0Draft_ab3930(const Decal_ab3930* value)
{
    uint32_t head = mnHead;
    if (head == 0xffffffff) {
        Decal_ab3930* end = mpEnd;
        if (end != mpCap) {
            Fn00736280(end, value);
            mpEnd += 1;
        } else {
            uint32_t tmp;
            Fn007385c0(end, value, &tmp, 1, 1);
        }
        mpEnd[-1].freeLink = 0xffffffff;
        return static_cast<uint32_t>(mpEnd - mpBegin) - 1;
    }
    if (head == mnTail) {
        mnHead = 0xffffffff;
        mnTail = 0xffffffff;
    } else {
        mnHead = mpBegin[head].freeLink;
    }
    Decal_ab3930* d = &mpBegin[head];
    d->freeLink = value->freeLink;
    d->x = value->x;
    d->z = value->z;
    d->width = value->width;
    d->turns = value->turns;
    d->aspectAdjust = value->aspectAdjust;
    d->uRepeat = value->uRepeat;
    d->vRepeat = value->vRepeat;
    d->uvOffset = value->uvOffset;
    d->userValue = value->userValue;
    d->aspect = value->aspect;
    d->overlay = value->overlay;
    mpBegin[head].freeLink = 0xffffffff;
    return head;
}
#endif

// FUNCTION: 0x00739fc0
uint32_t RingPool_ab3930::Fn00739fc0Draft_ab3930(const Ring_ab3930* value)
{
    uint32_t head = mnHead;
    if (head == 0xffffffff) {
        Ring_ab3930* end = mpEnd;
        if (end != mpCap) {
            if (end) {
                *end = *value;
            }
            mpEnd += 1;
        } else {
            uint32_t tmp;
            Fn007386a0(end, value, &tmp, 1, 1);
        }
        mpEnd[-1].freeLink = 0xffffffff;
        return static_cast<uint32_t>(mpEnd - mpBegin) - 1;
    }
    if (head == mnTail) {
        mnHead = 0xffffffff;
        mnTail = 0xffffffff;
    } else {
        mnHead = mpBegin[head].freeLink;
    }
    mpBegin[head] = *value;
    mpBegin[head].freeLink = 0xffffffff;
    return head;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0073bf10 score 41
uint32_t cSTEOverlayManager::Slot04_ab3930(uint32_t texture, uint32_t pos, uint32_t width, uint32_t turns)
{
    TexBinding_ab3930* tex = OB_PTR(TexBinding_ab3930, texture);
    if (!tex) {
        return 0xffffffff;
    }
    const uint32_t* p = OB_PTR(const uint32_t, pos);
    Decal_ab3930 d;
    d.x = p[0];
    d.z = p[1];
    d.width = width;
    d.turns = turns;
    reinterpret_cast<float&>(d.aspectAdjust) = 1.0f;
    reinterpret_cast<float&>(d.uRepeat) = 1.0f;
    reinterpret_cast<float&>(d.vRepeat) = 1.0f;
    reinterpret_cast<float&>(d.uvOffset) = 0.0f;
    reinterpret_cast<float&>(d.userValue) = 0.0f;
    TexInfo_ab3930 info;
    reinterpret_cast<Factory_ab3930*>(mpTextureFactory)->GetTextureInfo(tex, &info);
    reinterpret_cast<float&>(d.aspect) = static_cast<float>(info.height) / static_cast<float>(info.width);
    Overlay_ab3930 o;
    TexBinding_ab3930* oldTex = o.mpTexture;
    if (tex != oldTex) {
        tex->AddRef();
        o.mpTexture = tex;
        if (oldTex) {
            oldTex->Release();
        }
    }
    Released_ab3930* oldObj = o.mpObject;
    if (oldObj) {
        o.mpObject = 0;
        oldObj->Release();
    }
    o.flags |= 0x90;
    OverlayPool_ab3930* pool = reinterpret_cast<OverlayPool_ab3930*>(&mpOverlays);
    uint32_t idx = pool->Fn0073aec0(&o);
    d.overlay = idx;
    Fn0073a1b0(&d, false);
    if (idx != 0xffffffff && !mbDynamic) {
        Fn00738230(idx, &reinterpret_cast<Overlay_ab3930*>(mpOverlays)[idx].rect);
        RedisplayStaticOverlay(idx);
    }
    uint32_t slot = reinterpret_cast<DecalPool_ab3930*>(&mpDecals)->Fn00739ec0(&d);
    return slot | 0x80000000;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00735820 score 138
Overlay_ab3930* Overlay_ab3930::Fn00735820Draft_ab3930(const Overlay_ab3930* src)
{
    freeLink = src->freeLink;
    flags = src->flags;
    drawMode = src->drawMode;
    *reinterpret_cast<uint16_t*>(&pad09[1]) = *reinterpret_cast<const uint16_t*>(&src->pad09[1]);
    rect = src->rect;
    for (int i = 0; i < 16; i++) {
        matrix[i] = src->matrix[i];
    }
    for (int i = 0; i < 16; i++) {
        reinterpret_cast<uint32_t*>(pad5c)[i] = reinterpret_cast<const uint32_t*>(src->pad5c)[i];
    }
    alpha = src->alpha;
    color[0] = src->color[0];
    color[1] = src->color[1];
    color[2] = src->color[2];
    if (&src->mpTexture != &mpTexture) {
        TexBinding_ab3930* newTex = src->mpTexture;
        TexBinding_ab3930* oldTex = mpTexture;
        if (newTex != oldTex) {
            if (newTex) {
                newTex->AddRef();
            }
            mpTexture = newTex;
            if (oldTex) {
                oldTex->Release();
            }
        }
    }
    if (&src->mpObject != &mpObject) {
        Released_ab3930* newObj = src->mpObject;
        Released_ab3930* oldObj = mpObject;
        if (newObj != oldObj) {
            if (newObj) {
                newObj->AddRef();
            }
            mpObject = newObj;
            if (oldObj) {
                oldObj->Release();
            }
        }
    }
    return this;
}
#endif
