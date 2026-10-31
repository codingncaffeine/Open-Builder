#include "classes/cSC43DRender.h"

#include <cstddef>
#include <new>
#include <cmath>
#include <cstdlib>

// The color backing store and the backing-store switch (class statics of the original).
// GLOBAL: 0x00b0dc19
extern bool gb0dc19;
// GLOBAL: 0x00b4e1e4
extern uint32_t gb4e1e4;
// The graphics driver the original keeps in a global (also reference counted).
struct cRef_abab60 {
    virtual uint32_t QueryInterface(uint32_t iid, void** out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad03_abab60();
    virtual void Pad04_abab60();
    virtual void Pad05_abab60();
    virtual void Pad06_abab60();
    virtual void Pad07_abab60();
    virtual void Pad08_abab60();
    virtual void Pad09_abab60();
    virtual void Pad10_abab60();
    virtual void Slot11(uint32_t mask);
    virtual void Slot12(float r, float g, float b, float a);
    virtual void Slot13(double depth);
    virtual void Pad14_abab60();
    virtual void Pad15_abab60();
    virtual void Pad16_abab60();
    virtual void Pad17_abab60();
    virtual void Pad18_abab60();
    virtual void Pad19_abab60();
    virtual void Pad20_abab60();
    virtual void Pad21_abab60();
    virtual void Pad22_abab60();
    virtual void Pad23_abab60();
    virtual void Pad24_abab60();
    virtual void Pad25_abab60();
    virtual void Pad26_abab60();
    virtual void Pad27_abab60();
    virtual void Pad28_abab60();
    virtual void Pad29_abab60();
    virtual void Pad30_abab60();
    virtual void Pad31_abab60();
    virtual void Pad32_abab60();
    virtual void Pad33_abab60();
    virtual void Pad34_abab60();
    virtual void Pad35_abab60();
    virtual void Pad36_abab60();
    virtual void Pad37_abab60();
    virtual void Pad38_abab60();
    virtual void Pad39_abab60();
    virtual void Slot40(bool on);
    virtual void Slot41(void* data);
    virtual void Slot42();
    virtual void Pad43_abab60();
    virtual void Pad44_abab60();
    virtual void Pad45_abab60();
    virtual void Pad46_abab60();
    virtual void Pad47_abab60();
    virtual void Pad48_abab60();
    virtual void Pad49_abab60();
    virtual void Pad50_abab60();
    virtual void Pad51_abab60();
    virtual void Pad52_abab60();
    virtual void Pad53_abab60();
    virtual void Pad54_abab60();
    virtual void Pad55_abab60();
    virtual void Pad56_abab60();
    virtual void Pad57_abab60();
    virtual void Pad58_abab60();
    virtual void Pad59_abab60();
    virtual void Pad60_abab60();
    virtual void Pad61_abab60();
    virtual void Pad62_abab60();
    virtual void Pad63_abab60();
    virtual void Slot64(void* buffer);
    virtual void Pad65_abab60();
    virtual void Pad66_abab60();
    virtual void Pad67_abab60();
    virtual void Pad68_abab60();
    virtual void Pad69_abab60();
    virtual void Pad70_abab60();
    virtual void Pad71_abab60();
    virtual void Pad72_abab60();
    virtual void Pad73_abab60();
    virtual void Slot74(uint32_t x, uint32_t y, uint32_t w, uint32_t h);
    virtual void Slot75();
};

// The object at 0x00b4e1f0: slot 5 frees a handle.
struct cHandles_abab60 {
    virtual void Pad00_abab60();
    virtual void Pad01_abab60();
    virtual uint32_t Release();
    virtual void Pad03_abab60();
    virtual void Pad04_abab60();
    virtual void Free(uint32_t handle);
    virtual void Pad06_abab60();
    virtual void Slot07(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
    virtual void Pad08_abab60();
    virtual bool Slot09();
};

struct cSnapshotExt_abab60;
// GLOBAL: 0x00b4e1f4
extern cSnapshotExt_abab60* gpB4e1f4;
// GLOBAL: 0x00b4e1ec
extern cRef_abab60* gpB4e1ec;
// GLOBAL: 0x00b4e1f0
extern cHandles_abab60* gpB4e1f0;
// GLOBAL: 0x00b4e1e8
extern uint32_t gb4e1e8;
// GLOBAL: 0x00b4e1e0
extern bool gb4e1e0;

// The camera control, seen from outside.
struct cCameraControl_abab60 {
    virtual void Pad00_abab60();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    // STUB: 0x007cdc50
    void SetZoom(float zoom);
};

// The snapshot extension of the driver: slot 3 takes a snapshot.
struct cSnapshotExt_abab60 {
    virtual void Pad00_abab60();
    virtual void Pad01_abab60();
    virtual uint32_t Release();
    virtual void* Snapshot(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t) = 0;
};

// The draw context, seen from outside.
struct cDrawContext_abab60 {
    // STUB: 0x007d3d80
    void SetCamera(void* camera);
};

// The 3D camera.
struct cCamera_abab60 {
    // STUB: 0x007ff080
    void SetSubview(float, float, float, float);
    virtual void Pad00_abab60();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    // STUB: 0x007ff070
    void SetDepthSize(float);
    // STUB: 0x007ff120
    uint32_t GetProjectionState();
    // STUB: 0x00800340
    bool GetEyeRay(const float* point, void* origin, void* direction);
    // STUB: 0x007ff3c0
    uint32_t GetViewState();
};

// A node of the view object list (a circular doubly-linked list with a head node).
struct Node_abab60 {
    Node_abab60* next;
    Node_abab60* prev;
    uint32_t value;
};
struct List_abab60 {
    Node_abab60* head;
};

// FUNCTION: 0x007c2750
bool cSC43DRender::GetBackingStoreEnabled()
{
    return gb0dc19;
}

// FUNCTION: 0x007c2cd0
bool cSC43DRender::BorrowRenderSystem()
{
    mbBorrowed = true;
    return true;
}

// FUNCTION: 0x007c2790
bool Fn007c2790()
{
    return gb4e1e4 != 0;
}

// FUNCTION: 0x007c25f0
void* cSC43DRender::GetBackgroundPicture(void* pFlag)
{
    bool* p = static_cast<bool*>(pFlag);
    if (p) {
        *p = mbBackgroundFlag;
    }
    return mpBackgroundPicture;
}

// FUNCTION: 0x007c1920
void cSC43DRender::GetViewportSize(void* w, void* h)
{
    *static_cast<uint32_t*>(w) = mnViewportW;
    *static_cast<uint32_t*>(h) = mnViewportH;
}

// FUNCTION: 0x007c22b0
void cSC43DRender::SetZoom(int32_t zoom)
{
    static_cast<cCameraControl_abab60*>(mpCameraControl)->SetZoom(static_cast<float>(zoom));
}

// FUNCTION: 0x007c1940
void cSC43DRender::SetViewportSize(uint32_t w, uint32_t h)
{
    mnViewportW = w;
    mnViewportH = h;
    mnViewportW2 = w;
    mnViewportH2 = h;
}

// FUNCTION: 0x007c1960
void cSC43DRender::SetSubpixelImageBias(float x, float y)
{
    mfBiasX = x;
    mfBiasY = y;
}

// FUNCTION: 0x007c2330
void cSC43DRender::GetShakeOffsets(void* x, void* y)
{
    *static_cast<float*>(x) = static_cast<float>(mnShakeX);
    *static_cast<float*>(y) = static_cast<float>(mnShakeY);
}

// FUNCTION: 0x007c2c10
bool cSC43DRender::SetViewFogEnabled(bool on)
{
    if (mbFog != on) {
        mbFog = on;
        ForceFullRedraw();
    }
    return true;
}

// FUNCTION: 0x007c2760
void cSC43DRender::SetBackingStoreEnabled(bool on)
{
    if (gb4e1e4 == 0) {
        on = false;
    }
    if (gb0dc19 != on) {
        gb0dc19 = on;
    }
}

// FUNCTION: 0x007c3b30
bool Fn007c3b30(List_abab60* list, uint32_t key)
{
    Node_abab60* head = list->head;
    Node_abab60* n = head->next;
    if (n != head) {
        do {
            if (n->value == key) {
                return true;
            }
            n = n->next;
        } while (n != head);
    }
    return false;
}

// FUNCTION: 0x007c2c40
bool cSC43DRender::SetLightingEnabled(bool on)
{
    if (mbLighting != on) {
        ForceFullRedraw();
        mbLighting = on;
    }
    return true;
}

// FUNCTION: 0x007c3060
uint32_t cSC43DRender::Slot02_abab60()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Shutdown();
    delete this;
    return 0;
}

// FUNCTION: 0x007c1a90
void cSC43DRender::Set2DCameraView()
{
    if (mnCameraMode != 1) {
        static_cast<cDrawContext_abab60*>(mpDrawContext)->SetCamera(mpCamera2D);
        mnCameraMode = 1;
    }
}

// FUNCTION: 0x007c2350
void cSC43DRender::SetViewportClearColor(const void* color)
{
    const float* c = static_cast<const float*>(color);
    mbClearSolid = false;
    mfClearR = c[0];
    mfClearG = c[1];
    mfClearB = c[2];
    mfClearA = c[3];
}

// FUNCTION: 0x007c2530
bool cSC43DRender::TakeSnapshot_2(void* out, bool)
{
    if (gpB4e1f4) {
        void* snap = gpB4e1f4->Snapshot(0, 0, mnViewportW, mnViewportH, 0);
        *static_cast<void**>(out) = snap;
        return snap != 0;
    }
    return false;
}

// FUNCTION: 0x007c1a50
void cSC43DRender::Set3DCameraView()
{
    if (mnCameraMode != 2) {
        static_cast<cDrawContext_abab60*>(mpDrawContext)->SetCamera(mpCamera);
        mnCameraMode = 2;
        mnViewState = static_cast<cCamera_abab60*>(mpCamera)->GetViewState();
    }
}

// The pointer lists the original keeps as circular lists with a head node: a node holds a view object.
struct ViewObject_abab60 {
    virtual void Pad00_abab60();
    virtual void Pad01_abab60();
    virtual uint32_t Release();
    virtual void Draw(void* context);
};
struct NodeP_abab60 {
    NodeP_abab60* next;
    NodeP_abab60* prev;
    ViewObject_abab60* object;
};
struct DrawContext_abab60 {
    char pad0[0x4];
    uint32_t mnIndex;
    char pad1[0x18];
    uint32_t mnReason;
    char pad2[0x2c];
    uint32_t mnPass;
};

// FUNCTION: 0x007c3e10
void cSC43DRender::DrawViewListA()
{
    static_cast<DrawContext_abab60*>(mpDrawContext)->mnPass = 3;
    NodeP_abab60* n = static_cast<NodeP_abab60*>(mpViewListA)->next;
    if (n != static_cast<NodeP_abab60*>(mpViewListA)) {
        do {
            ViewObject_abab60* o = n->object;
            n = n->next;
            o->Draw(mpDrawContext);
        } while (n != static_cast<NodeP_abab60*>(mpViewListA));
    }
}

// FUNCTION: 0x007c3e50
void cSC43DRender::DrawViewListB()
{
    static_cast<DrawContext_abab60*>(mpDrawContext)->mnPass = 5;
    NodeP_abab60* n = static_cast<NodeP_abab60*>(mpViewListB)->next;
    if (n != static_cast<NodeP_abab60*>(mpViewListB)) {
        do {
            ViewObject_abab60* o = n->object;
            n = n->next;
            o->Draw(mpDrawContext);
        } while (n != static_cast<NodeP_abab60*>(mpViewListB));
    }
}

// FUNCTION: 0x007c3e90
void cSC43DRender::DrawViewListC()
{
    static_cast<DrawContext_abab60*>(mpDrawContext)->mnPass = 0;
    NodeP_abab60* n = static_cast<NodeP_abab60*>(mpViewListC)->next;
    if (n != static_cast<NodeP_abab60*>(mpViewListC)) {
        do {
            ViewObject_abab60* o = n->object;
            n = n->next;
            o->Draw(mpDrawContext);
        } while (n != static_cast<NodeP_abab60*>(mpViewListC));
    }
}

// FUNCTION: 0x007c3ed0
void cSC43DRender::DrawViewListD()
{
    static_cast<DrawContext_abab60*>(mpDrawContext)->mnPass = 2;
    NodeP_abab60* n = static_cast<NodeP_abab60*>(mpViewListD)->next;
    if (n != static_cast<NodeP_abab60*>(mpViewListD)) {
        do {
            ViewObject_abab60* o = n->object;
            n = n->next;
            o->Draw(mpDrawContext);
        } while (n != static_cast<NodeP_abab60*>(mpViewListD));
    }
}

// The view utilities, seen from outside.
struct cViewUtil_abab60 {
    // STUB: 0x007f83f0
    void UpdateCameraPosition(void* control);
    // STUB: 0x007f7a40
    void Fn007f7a40(uint32_t, uint32_t, uint32_t*, uint32_t*);
    // STUB: 0x007f9f50
    void Fn007f9f50(void*, void*);
};

// FUNCTION: 0x007c1a00
void cSC43DRender::SetCameraControl(void* control)
{
    cCameraControl_abab60* c = static_cast<cCameraControl_abab60*>(control);
    if (mpCameraControl != c) {
        if (c) {
            c->AddRef();
        }
        if (mpCameraControl) {
            static_cast<cCameraControl_abab60*>(mpCameraControl)->Release();
        }
        mpCameraControl = c;
        if (c) {
            static_cast<cViewUtil_abab60*>(mpViewUtilities)->UpdateCameraPosition(c);
        }
    }
}

// STUB: 0x0090cf63
void StlDelete_abab60(void* p);

// FUNCTION: 0x007c3b60
void Fn007c3b60(List_abab60* l)
{
    NodeP_abab60* n = reinterpret_cast<NodeP_abab60*>(l->head)->next;
    if (n != reinterpret_cast<NodeP_abab60*>(l->head)) {
        do {
            n->object->Release();
            n = n->next;
        } while (n != reinterpret_cast<NodeP_abab60*>(l->head));
    }
    n = reinterpret_cast<NodeP_abab60*>(l->head)->next;
    while (n != reinterpret_cast<NodeP_abab60*>(l->head)) {
        NodeP_abab60* cur = n;
        n = n->next;
        StlDelete_abab60(cur);
    }
    l->head->next = l->head;
    l->head->prev = l->head;
}

// FUNCTION: 0x007c2910
bool Fn007c2910()
{
    if (gpB4e1f0) {
        if (gb4e1e4) {
            gpB4e1f0->Free(gb4e1e4);
            gb4e1e4 = 0;
        }
        if (gb4e1e8) {
            gpB4e1f0->Free(gb4e1e8);
            gb4e1e8 = 0;
        }
        return true;
    }
    return false;
}

// FUNCTION: 0x007c3090
bool Fn007c3090()
{
    if (gb4e1e0) {
        gb4e1e0 = false;
        if (gpB4e1ec) {
            Fn007c2910();
            gpB4e1ec->Release();
            gpB4e1ec = 0;
        }
        if (gpB4e1f0) {
            gpB4e1f0->Release();
            gpB4e1f0 = 0;
        }
        if (gpB4e1f4) {
            gpB4e1f4->Release();
            gpB4e1f4 = 0;
        }
    }
    return true;
}

// The object at 0x00b43c94: slot 69 installs a callback.
struct cSC4_abab60 {
    virtual void Pad00_abab60();
    virtual void Pad01_abab60();
    virtual void Pad02_abab60();
    virtual void Pad03_abab60();
    virtual void Pad04_abab60();
    virtual void Pad05_abab60();
    virtual void Pad06_abab60();
    virtual void Pad07_abab60();
    virtual void Pad08_abab60();
    virtual void Pad09_abab60();
    virtual void Pad10_abab60();
    virtual void Pad11_abab60();
    virtual void Pad12_abab60();
    virtual void Pad13_abab60();
    virtual void Pad14_abab60();
    virtual void Pad15_abab60();
    virtual void Pad16_abab60();
    virtual void Pad17_abab60();
    virtual void Pad18_abab60();
    virtual void Pad19_abab60();
    virtual void Pad20_abab60();
    virtual void Pad21_abab60();
    virtual void Pad22_abab60();
    virtual void Pad23_abab60();
    virtual void Pad24_abab60();
    virtual void Pad25_abab60();
    virtual void Pad26_abab60();
    virtual void Pad27_abab60();
    virtual void Pad28_abab60();
    virtual void Pad29_abab60();
    virtual void Pad30_abab60();
    virtual void Pad31_abab60();
    virtual void Pad32_abab60();
    virtual void Pad33_abab60();
    virtual void Pad34_abab60();
    virtual void Pad35_abab60();
    virtual void Pad36_abab60();
    virtual void Pad37_abab60();
    virtual void Pad38_abab60();
    virtual void Pad39_abab60();
    virtual void Pad40_abab60();
    virtual void Pad41_abab60();
    virtual void Pad42_abab60();
    virtual void Pad43_abab60();
    virtual void Pad44_abab60();
    virtual void Pad45_abab60();
    virtual void Pad46_abab60();
    virtual void Pad47_abab60();
    virtual void Pad48_abab60();
    virtual void Pad49_abab60();
    virtual void Pad50_abab60();
    virtual void Pad51_abab60();
    virtual void Pad52_abab60();
    virtual void Pad53_abab60();
    virtual void Pad54_abab60();
    virtual void Pad55_abab60();
    virtual void Pad56_abab60();
    virtual void Pad57_abab60();
    virtual void Pad58_abab60();
    virtual void Pad59_abab60();
    virtual void Pad60_abab60();
    virtual void Pad61_abab60();
    virtual void Pad62_abab60();
    virtual void Pad63_abab60();
    virtual void Pad64_abab60();
    virtual void Pad65_abab60();
    virtual void Pad66_abab60();
    virtual void Pad67_abab60();
    virtual void Pad68_abab60();
    virtual void Fn69(bool (*callback)(), uint32_t flags);
};
// GLOBAL: 0x00b43c94
extern cSC4_abab60* gpB43c94_abab60;

// FUNCTION: 0x007c3bb0
bool Fn007c3bb0()
{
    if (!gb4e1e0) {
        gb4e1e0 = true;
        gpB43c94_abab60->Fn69(Fn007c3090, 0);
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007c95b0 score 2
void cSC43DRender::Fn007c95b0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t v[4];
    static_cast<cViewUtil_abab60*>(mpViewUtilities)->Fn007f7a40(b, c, &v[0], &v[2]);
    Fn007c9540(v[2], &v[0], d, e);
}
#endif

struct Elem_abab60 {
    int32_t value;
    uint32_t key;
};

// STUB: 0x007c3950
int32_t Fn007c3950(Elem_abab60* p, int32_t lo, int32_t hi);
// STUB: 0x007c3a10
int32_t Fn007c3a10(Elem_abab60* p, int32_t lo, int32_t hi);

// FUNCTION: 0x007c56d0
void Fn007c56d0(Elem_abab60* p, int32_t n)
{
    while (n - 1 > 0) {
        int32_t k = Fn007c3950(p, 0, n - 1);
        Fn007c56d0(p, k);
        n += -1 - k;
        p += k + 1;
    }
}

// FUNCTION: 0x007c5710
void Fn007c5710(Elem_abab60* p, int32_t n)
{
    while (n - 1 > 0) {
        int32_t k = Fn007c3a10(p, 0, n - 1);
        Fn007c5710(p, k);
        n += -1 - k;
        p += k + 1;
    }
}

struct Rect4_abab60 {
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
};

// FUNCTION: 0x007c2c70
bool cSC43DRender::ClipRectToViewport(void* rect)
{
    Rect4_abab60* r = static_cast<Rect4_abab60*>(rect);
    int32_t right = r->right;
    if (right > 0) {
        int32_t left = r->left;
        if (left < static_cast<int32_t>(mnViewportW)) {
            int32_t bottom = r->bottom;
            if (bottom > 0) {
                int32_t top = r->top;
                if (top < static_cast<int32_t>(mnViewportH)) {
                    if (left < 0) {
                        r->left = 0;
                    }
                    if (right > static_cast<int32_t>(mnViewportW)) {
                        r->right = mnViewportW;
                    }
                    if (top < 0) {
                        r->top = 0;
                    }
                    if (bottom > static_cast<int32_t>(mnViewportH)) {
                        r->bottom = mnViewportH;
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

// The string object statistics are printed into: slot 27 is a printf.
struct cString_abab60 {
    virtual void Pad00_abab60();
    virtual void Pad01_abab60();
    virtual void Pad02_abab60();
    virtual void Pad03_abab60();
    virtual void Pad04_abab60();
    virtual void Pad05_abab60();
    virtual void Pad06_abab60();
    virtual void Pad07_abab60();
    virtual void Pad08_abab60();
    virtual void Pad09_abab60();
    virtual void Pad10_abab60();
    virtual void Pad11_abab60();
    virtual void Pad12_abab60();
    virtual void Pad13_abab60();
    virtual void Pad14_abab60();
    virtual void Pad15_abab60();
    virtual void Pad16_abab60();
    virtual void Pad17_abab60();
    virtual void Pad18_abab60();
    virtual void Pad19_abab60();
    virtual void Pad20_abab60();
    virtual void Pad21_abab60();
    virtual void Pad22_abab60();
    virtual void Pad23_abab60();
    virtual void Pad24_abab60();
    virtual void Pad25_abab60();
    virtual void Pad26_abab60();
    virtual void Sprintf(const char* format, ...);
};

// FUNCTION: 0x007c2db0
void cSC43DRender::GetStatsString2(uint32_t str)
{
    cString_abab60* s = OB_PTR(cString_abab60, str);
    s->Sprintf("QGT:%u MST:%u MTC:%u, MC1:%u MDC:%u AIT:%u AMT:%u ART:%u TPT%u MPT:%u", mnStat2a4, mnStat2a8, mnStat2b0,
               mnStat2b4, mnStat2b8, mnStat2c0, mnStat2c4, mnStat2c8, mnStat2cc, mnStat2d0);
}

// GLOBAL: 0x00b4e218
extern float gfB4e218;

// FUNCTION: 0x007c2d50
void cSC43DRender::GetStatsString1(uint32_t str)
{
    cString_abab60* s = OB_PTR(cString_abab60, str);
    s->Sprintf("SPS:%.1f BST:%u BRT:%u VCT:%u PrVDT:%u TeDT:%u PoVDT:%u ToDT:%u", static_cast<double>(gfB4e218),
               mnStat288, mnStat28c, mnStat290, mnStat294, mnStat2ac, mnStat298, mnStat2bc);
}

// STUB: 0x00604690
void Fn00604690(cRef_abab60* driver, uint32_t texture);

// FUNCTION: 0x007c26d0
bool cSC43DRender::SetBackgroundPicture(uint32_t texture, uint32_t w, uint32_t h, bool flag)
{
    mbBackgroundFlag = flag;
    if (texture != mnBackgroundTexture) {
        if (mpBackgroundPicture) {
            static_cast<cRef_abab60*>(mpBackgroundPicture)->Release();
            mpBackgroundPicture = 0;
        }
        if (mnBackgroundTexture) {
            if (gpB4e1ec) {
                Fn00604690(gpB4e1ec, mnBackgroundTexture);
            }
            mnBackgroundTexture = 0;
        }
        mnBackgroundTexture = texture;
        mnBackgroundW = w;
        mnBackgroundH = h;
    }
    return true;
}

// FUNCTION: 0x007c9540
void cSC43DRender::Fn007c9540(uint32_t a, void* rect, uint32_t d, uint32_t e)
{
    if (!mbFullUpdateDone) {
        Rect4_abab60 r = *static_cast<Rect4_abab60*>(rect);
        if (ClipRectToViewport(&r)) {
            Fn007c8f30(a, &r, d, e);
        }
    }
}

struct QuadGrid_abab60 {
    // STUB: 0x005f41f0
    QuadGrid_abab60(float, float);
    // STUB: 0x005f40b0
    void SetSize(float, float);
    char data[0x20];
};

// FUNCTION: 0x007c2390
void* cSC43DRender::CreateQuadGrid()
{
    mfQuadGridSize = static_cast<float>(mnGridScale) * 8192.0f;
    QuadGrid_abab60* g = new QuadGrid_abab60(1.0f, 1.0f);
    g->SetSize(static_cast<float>(mnGridScale) * 8192.0f, static_cast<float>(mnGridScale) * 32.0f);
    return g;
}

// FUNCTION: 0x007c7dd0
void cSC43DRender::ForceFullRedraw()
{
    static_cast<DrawContext_abab60*>(mpDrawContext)->mnReason = 10;
    if (!mbFullUpdateDone) {
        mbFullUpdateDone = true;
        mbBackingValid = false;
        static_cast<cViewUtil_abab60*>(mpViewUtilities)->Fn007f9f50(mnViewOrigin, &mnViewportW2);
        mbDirtyA = false;
        mbDirtyB = false;
        ClearDirtyRectangleQueue();
    }
}

// FUNCTION: 0x007c7310
void cSC43DRender::DoFullViewUpdate(uint32_t reason)
{
    static_cast<DrawContext_abab60*>(mpDrawContext)->mnReason = reason;
    if (!mbFullUpdateDone) {
        mbFullUpdateDone = true;
        mbBackingValid = false;
        static_cast<cViewUtil_abab60*>(mpViewUtilities)->Fn007f9f50(mnViewOrigin, &mnViewportW2);
        mbDirtyA = false;
        mbDirtyB = false;
        ClearDirtyRectangleQueue();
    }
}

struct Quad_abab60 {
    uint32_t v[4];
    Quad_abab60& operator=(const Quad_abab60& o)
    {
        v[0] = o.v[0];
        v[1] = o.v[1];
        v[2] = o.v[2];
        v[3] = o.v[3];
        return *this;
    }
};

struct ModelChangeQueueItem_abab60 {
    uint32_t a;
    uint8_t b;
    uint8_t c;
    Quad_abab60 q;
    uint32_t s[6];
    // STUB: 0x007c3ad0
    ModelChangeQueueItem_abab60(const ModelChangeQueueItem_abab60& o);
    // STUB: 0x007c2e50
    ModelChangeQueueItem_abab60(uint32_t a_, uint8_t b_, uint8_t c_, const Quad_abab60& q_, const uint32_t* s_);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c3ad0 score 22
ModelChangeQueueItem_abab60::ModelChangeQueueItem_abab60(const ModelChangeQueueItem_abab60& o)
{
    a = o.a;
    b = o.b;
    c = o.c;
    q = o.q;
    s[0] = o.s[0];
    s[1] = o.s[1];
    s[2] = o.s[2];
    s[3] = o.s[3];
    s[4] = o.s[4];
    s[5] = o.s[5];
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007c2e50 score 21
ModelChangeQueueItem_abab60::ModelChangeQueueItem_abab60(uint32_t a_, uint8_t b_, uint8_t c_, const Quad_abab60& q_,
                                                           const uint32_t* s_)
{
    a = a_;
    b = b_;
    c = c_;
    q = q_;
    s[0] = s_[0];
    s[1] = s_[1];
    s[2] = s_[2];
    s[3] = s_[3];
    s[4] = s_[4];
    s[5] = s_[5];
}
#endif

struct ViewObjectInfoNode_abab60 {
    ViewObjectInfoNode_abab60* next;
    ViewObjectInfoNode_abab60* prev;
    char pad[0x1c];
    void* p24;
    char pad2[0x8];
    void* p30;
};
struct ViewObjectInfoList_abab60 {
    ViewObjectInfoNode_abab60* head;
    void Clear();
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c7020 score 4
void ViewObjectInfoList_abab60::Clear()
{
    ViewObjectInfoNode_abab60* n = head->next;
    if (n != head) {
        do {
            ViewObjectInfoNode_abab60* cur = n;
            void* a = cur->p30;
            n = n->next;
            if (a) {
                StlDelete_abab60(a);
            }
            a = cur->p24;
            if (a) {
                StlDelete_abab60(a);
            }
            StlDelete_abab60(cur);
        } while (n != head);
    }
    head->next = head;
    head->prev = head;
}
#endif

struct cDrawContextCalls_abab60 {
    // STUB: 0x007d2750
    void SetModelViewTransformChanged();
    // STUB: 0x007d5230
    void SetDefaultRenderStateUnilaterally();
    // STUB: 0x007d2760
    void EnableColorMaskFlag(bool);
    // STUB: 0x007d2800
    void EnableDepthMaskFlag(bool);
};

// FUNCTION: 0x007c1ac0
void cSC43DRender::SetUICameraView()
{
    if (mnCameraMode != 3) {
        gpB4e1ec->Slot40(true);
        gpB4e1ec->Slot41(&mnUICameraData);
        gpB4e1ec->Slot40(false);
        gpB4e1ec->Slot42();
        static_cast<cDrawContextCalls_abab60*>(mpDrawContext)->SetModelViewTransformChanged();
        mnCameraMode = 3;
    }
}

struct cModel_abab60 {
    virtual void Pad00_abab60();
    virtual void Pad01_abab60();
    virtual void Pad02_abab60();
    virtual void Pad03_abab60();
    virtual void Pad04_abab60();
    virtual void Pad05_abab60();
    virtual void Slot06(uint32_t);
    virtual void Pad07_abab60();
    virtual void GetBoundingBox(float* box);
    virtual void Pad09_abab60();
    virtual void Pad10_abab60();
    virtual void Pad11_abab60();
    virtual void Pad12_abab60();
    virtual uint32_t Slot13();
    virtual void Pad14_abab60();
    virtual uint8_t* Slot15(void* buffer);
};

// FUNCTION: 0x007c3f10
void cSC43DRender::GetModelContainerRect(void* model, void* rect, int32_t flag)
{
    float box[6];
    box[0] = 1.0f;
    box[1] = 1.0f;
    box[2] = 1.0f;
    box[3] = 0.0f;
    box[4] = 0.0f;
    box[5] = 0.0f;
    static_cast<cModel_abab60*>(model)->GetBoundingBox(box);
    WorldToContainerRect(&box[0], &box[3], rect, flag);
}

struct cGimexFactory_abab60 {
    // STUB: 0x0090bc54
    cGimexFactory_abab60();
    virtual void Pad00_abab60();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad03_abab60();
    virtual void Pad04_abab60();
    virtual void Pad05_abab60();
    virtual void Pad06_abab60();
    virtual void Pad07_abab60();
    virtual bool Save(void* str, void* image, uint32_t quality);
    char data[0x34];
};

// FUNCTION: 0x007c2570
bool cSC43DRender::TakeSnapshot(void* str, bool flag)
{
    cRef_abab60* image = 0;
    bool result = false;
    if (TakeSnapshot_2(&image, flag)) {
        cGimexFactory_abab60* f = new cGimexFactory_abab60();
        f->AddRef();
        result = f->Save(str, image, 100);
        f->Release();
        image->Release();
    }
    return result;
}

struct CameraControlView_abab60 {
    char pad0[0x98];
    float f98;
    float f9c;
    char pad1[0x8];
    float fa8;
    float fac;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c3230 score 9
void cSC43DRender::Fn007c3230()
{
    union Bits {
        float f;
        int32_t i;
    } a, b;
    CameraControlView_abab60* cc = static_cast<CameraControlView_abab60*>(mpCameraControl);
    float dx = cc->f98 - cc->fa8;
    float dy = cc->f9c - cc->fac;
    a.f = dx + 12582912.0f;
    b.f = dy + 12582912.0f;
    mnOffsetE0 += a.i - 0x4B400000;
    mnOffsetE4 += b.i - 0x4B400000;
    ++mnCounter15c;
}
#endif

// The camera control's position update.
struct cCameraUpdate_abab60 {
    // STUB: 0x007ccf80
    void UpdateCameraPosition(uint32_t reason);
};

// FUNCTION: 0x007c2ce0
bool cSC43DRender::ReturnRenderSystem()
{
    mbBorrowed = false;
    static_cast<cCameraUpdate_abab60*>(mpCameraControl)->UpdateCameraPosition(5);
    uint32_t mode = mnCameraMode;
    mnCameraMode = 0;
    switch (mode) {
    case 1:
        Set2DCameraView();
        break;
    case 2:
        Set3DCameraView();
        break;
    case 3:
        SetUICameraView();
        break;
    }
    static_cast<cDrawContextCalls_abab60*>(mpDrawContext)->SetDefaultRenderStateUnilaterally();
    return true;
}

// FUNCTION: 0x007c1980
void cSC43DRender::SetCamera(void* camera)
{
    cCamera_abab60* c = static_cast<cCamera_abab60*>(camera);
    if (mpCamera != c) {
        if (c) {
            c->AddRef();
        }
        if (mpCamera) {
            static_cast<cCamera_abab60*>(mpCamera)->Release();
        }
        mpCamera = c;
        if (c) {
            char buffer[0x34];
            gpB4e1ec->Slot64(buffer);
            static_cast<cCamera_abab60*>(mpCamera)->SetDepthSize(65536.0f);
            mnProjectionState = static_cast<cCamera_abab60*>(mpCamera)->GetProjectionState() - 1;
        }
    }
}

// FUNCTION: 0x007c2ac0
bool OB_STDCALL Fn007c2ac0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    bool result = false;
    if (gpB4e1f0 && gb4e1e4 && gb4e1e8) {
        gpB4e1f0->Slot07(gb4e1e4, a, b, c, d, e, f);
        gpB4e1f0->Slot07(gb4e1e8, a, b, c, d, e, f);
        result = true;
    }
    return result;
}

struct GridElement_abab60 {
    char pad0[6];
    uint16_t flags;
    char pad1[0x14];
    float box[6];
};

struct ViewUtilFields_abab60 {
    char pad[0x10];
    int32_t mnValue;
};

struct cQuadGrid_abab60 {
    // STUB: 0x005f3390
    bool MoveElement(void* element, const void* rect, uint32_t flag);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c3790 score 2
bool cSC43DRender::MoveGridElement(void* element, void* model)
{
    GridElement_abab60* e = static_cast<GridElement_abab60*>(element);
    cModel_abab60* m = static_cast<cModel_abab60*>(model);
    float rect[4];
    m->GetBoundingBox(e->box);
    WorldToContainerRect(&e->box[0], &e->box[3], rect, static_cast<ViewUtilFields_abab60*>(mpViewUtilities)->mnValue);
    uint16_t bits = e->flags;
    uint32_t flag = 0;
    if ((bits & 8) == 0 || static_cast<int8_t>(bits) < 0) {
        flag = 1;
    }
    bool ok = static_cast<cQuadGrid_abab60*>(mpQuadGrid)->MoveElement(e, rect, flag);
    if (!ok) {
        m->Slot06(0);
    }
    return ok;
}
#endif

struct RenderProps_abab60 {
    char pad[0xc];
    char* items;
};
// GLOBAL: 0x00b43cc4
extern RenderProps_abab60* gpB43cc4_abab60;

// FUNCTION: 0x007c94c0
void cSC43DRender::UpdateViewportRect(void* rectArg)
{
    int32_t* r = static_cast<int32_t*>(rectArg);
    if (r[2] > r[0] && r[3] > r[1]) {
        static_cast<cViewUtil_abab60*>(mpViewUtilities)->Fn007f9f50(r, r + 2);
        mbDirtyA = false;
        mbDirtyB = false;
        SetClipRect(r);
        ClearViewport(0);
        Set3DCameraView();
        if (gpB43cc4_abab60->items[0x5c]) {
            DrawViewListC();
            Fn007c7370();
            DrawViewListD();
        }
    }
}

void Fn007c3810(void* driver);

// FUNCTION: 0x007c3be0
void cSC43DRender::SetGDriver(void* driver)
{
    char buffer[0x34];
    Fn007c3810(driver);
    if (gpB4e1f0) {
        mbBufferRegions = gpB4e1f0->Slot09();
        mbBufferRegionsUsable = mbBufferRegions && !gpB43cc4_abab60->items[0x3dc];
    }
    if (mpCamera) {
        gpB4e1ec->Slot64(buffer);
        static_cast<cCamera_abab60*>(mpCamera)->SetDepthSize(65536.0f);
    }
}

// GLOBAL: 0x00b4e1f8
extern uint32_t gdB4e1f8;

struct Vec3_abab60 {
    uint32_t x;
    uint32_t y;
    uint32_t z;
    Vec3_abab60()
    {
        x = gdB4e1f8;
        y = gdB4e1f8;
        z = gdB4e1f8;
    }
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c2220 score 12
bool cSC43DRender::Pick_2(int32_t x, int32_t y, void* filter, void* out)
{
    Vec3_abab60 origin;
    Vec3_abab60 direction;
    float point[2];
    if (mpCamera) {
        point[0] = static_cast<float>(x);
        point[1] = static_cast<float>(y);
        static_cast<cCamera_abab60*>(mpCamera)->GetEyeRay(point, &origin, &direction);
        return Pick(x, y, &origin, &direction, filter, out);
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007c2b40 score 2
void cSC43DRender::UpdateGridElementObjectFlags(void* model, void* element)
{
    cModel_abab60* m = static_cast<cModel_abab60*>(model);
    GridElement_abab60* e = static_cast<GridElement_abab60*>(element);
    uint8_t buffer[0x14];
    uint32_t bits = m->Slot13();
    e->flags &= 0xc01f;
    if (bits & 1) {
        e->flags = e->flags | 0x20;
    }
    if (*m->Slot15(buffer) & 4) {
        e->flags |= 0x101;
    } else {
        if (*m->Slot15(buffer) & 2) {
            e->flags |= 0x100;
        } else {
            if (bits & 2) {
                e->flags |= 0x40;
            }
            if (bits & 4) {
                e->flags |= 0x100;
            }
        }
    }
    if (bits & 8) {
        e->flags |= 0x200;
    }
    if (bits & 0xf0) {
        if (bits & 0x10) {
            e->flags |= 0x400;
        }
        if (bits & 0x20) {
            e->flags |= 0x800;
        }
        if (bits & 0x40) {
            e->flags |= 0x1000;
        }
        if (static_cast<int8_t>(bits) < 0) {
            e->flags |= 0x2000;
        }
    } else {
        e->flags |= 0x800;
    }
}
#endif

struct cPicture_abab60 {
    virtual void Pad00_abab60();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad03_abab60();
    virtual void Pad04_abab60();
    virtual void Pad05_abab60();
    virtual void Pad06_abab60();
    virtual void Pad07_abab60();
    virtual void Pad08_abab60();
    virtual uint32_t GetWidth();
    virtual uint32_t GetHeight();
};

// STUB: 0x006046d0
bool Fn006046d0(cPicture_abab60* picture, cRef_abab60* driver, uint32_t* texture, uint32_t a, uint32_t b, uint32_t c,
                uint32_t d);

#ifdef OB_DRAFTS
// CLOSE: 0x007c2610 score 33
bool cSC43DRender::SetBackgroundPicture_2(void* picture, bool flag)
{
    cPicture_abab60* pic = static_cast<cPicture_abab60*>(picture);
    bool result = true;
    mbBackgroundFlag = flag;
    if (pic != mpBackgroundPicture) {
        if (mpBackgroundPicture) {
            static_cast<cPicture_abab60*>(mpBackgroundPicture)->Release();
            mpBackgroundPicture = 0;
        }
        if (pic) {
            pic->AddRef();
        }
        if (mnBackgroundTexture) {
            if (gpB4e1ec) {
                Fn00604690(gpB4e1ec, mnBackgroundTexture);
            }
            mnBackgroundTexture = 0;
        }
        if (pic) {
            if (!gpB4e1ec || !Fn006046d0(pic, gpB4e1ec, &mnBackgroundTexture, 0, 0, 0, 0)) {
                return false;
            }
            mpBackgroundPicture = pic;
            mnBackgroundW = pic->GetWidth();
            mnBackgroundH = pic->GetHeight();
        }
    }
    return result;
}
#endif

// STUB: 0x007c27a0
bool Fn007c27a0();

// FUNCTION: 0x007c3810
void Fn007c3810(void* driverArg)
{
    cRef_abab60* driver = static_cast<cRef_abab60*>(driverArg);
    if (driver != gpB4e1ec) {
        if (gpB4e1ec) {
            Fn007c2910();
        }
        if (driver) {
            driver->AddRef();
        }
        if (gpB4e1ec) {
            gpB4e1ec->Release();
        }
        gpB4e1ec = driver;
        if (gpB4e1f0) {
            gpB4e1f0->Release();
            gpB4e1f0 = 0;
        }
        if (gpB4e1f4) {
            gpB4e1f4->Release();
            gpB4e1f4 = 0;
        }
        if (gpB4e1ec) {
            gpB4e1ec->QueryInterface(0x669565fe, reinterpret_cast<void**>(&gpB4e1f0));
            gpB4e1ec->QueryInterface(0xe69bfe2a, reinterpret_cast<void**>(&gpB4e1f4));
            if (gpB4e1ec) {
                Fn007c27a0();
            }
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x007c3950 score 101
int32_t Fn007c3950(Elem_abab60* p, int32_t lo, int32_t hi)
{
    int32_t mid = (lo + hi) / 2;
    Elem_abab60 t = p[lo];
    p[lo] = p[mid];
    p[mid] = t;
    Elem_abab60 pivot = p[lo];
    int32_t i = lo;
    for (int32_t j = lo + 1; j <= hi; ++j) {
        if (p[j].key > pivot.key) {
            ++i;
            Elem_abab60 t2 = p[i];
            p[i] = p[j];
            p[j] = t2;
        }
    }
    Elem_abab60 t3 = p[lo];
    p[lo] = p[i];
    p[i] = t3;
    return i;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007c3a10 score 101
int32_t Fn007c3a10(Elem_abab60* p, int32_t lo, int32_t hi)
{
    int32_t mid = (lo + hi) / 2;
    Elem_abab60 t = p[lo];
    p[lo] = p[mid];
    p[mid] = t;
    Elem_abab60 pivot = p[lo];
    int32_t i = lo;
    for (int32_t j = lo + 1; j <= hi; ++j) {
        if (p[j].key < pivot.key) {
            ++i;
            Elem_abab60 t2 = p[i];
            p[i] = p[j];
            p[j] = t2;
        }
    }
    Elem_abab60 t3 = p[lo];
    p[lo] = p[i];
    p[i] = t3;
    return i;
}
#endif

// FUNCTION: 0x007c3350
void cSC43DRender::ClearViewportWithSolidColor(const void* color, bool depth, bool)
{
    const float* c = static_cast<const float*>(color);
    gpB4e1ec->Slot12(c[0], c[1], c[2], c[3]);
    static_cast<cDrawContextCalls_abab60*>(mpDrawContext)->EnableColorMaskFlag(true);
    if (depth) {
        static_cast<cDrawContextCalls_abab60*>(mpDrawContext)->EnableDepthMaskFlag(true);
        gpB4e1ec->Slot13(mfClearDepth);
        gpB4e1ec->Slot11(0x5000);
    } else {
        gpB4e1ec->Slot11(0x4000);
    }
    gpB4e1ec->Slot12(mfClearR, mfClearG, mfClearB, mfClearA);
}

struct RenderProps2_abab60 {
    char pad[0xc];
    char* items;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c3c60 score 44
void cSC43DRender::SetClipRect(const void* rectArg)
{
    if (static_cast<RenderProps2_abab60*>(mpRenderProps)->items[0x31c]) {
        const int32_t* r = static_cast<const int32_t*>(rectArg);
        uint32_t left = r[0];
        uint32_t y = mnViewportH - r[3];
        int32_t right = r[2];
        uint32_t h = r[3] - r[1];
        gpB4e1ec->Slot74(left, y, right - left, h);
        float fh = static_cast<float>(h);
        float fw = static_cast<float>(right - left);
        float fy = static_cast<float>(y);
        float fx = static_cast<float>(left);
        static_cast<cCamera_abab60*>(mpCamera)->SetSubview(fx, fy, fw, fh);
        static_cast<cCamera_abab60*>(mpCamera2D)->SetSubview(fx, fy, fw, fh);
        mnCameraMode = 0;
    }
}
#endif

struct cFrustum_abab60 {
    // STUB: 0x007f6770
    bool IsBoundingBoxInViewFrustum(const float* min, const float* max);
    // STUB: 0x007f6910
    bool Fn007f6910(const float* min, const float* max);
};

// FUNCTION: 0x007c51d0
bool cSC43DRender::Slot68_abab60(void* model, int32_t mode)
{
    float box[6];
    box[0] = 1.0f;
    box[1] = 1.0f;
    box[2] = 1.0f;
    box[3] = 0.0f;
    box[4] = 0.0f;
    box[5] = 0.0f;
    static_cast<cModel_abab60*>(model)->GetBoundingBox(box);
    if (mode == 2) {
        return static_cast<cFrustum_abab60*>(mpViewUtilities)->IsBoundingBoxInViewFrustum(&box[0], &box[3]);
    }
    return static_cast<cFrustum_abab60*>(mpViewUtilities)->Fn007f6910(&box[0], &box[3]);
}

struct ObjectWithModel_abab60 {
    char pad[0x18];
    cModel_abab60* model;
};

// FUNCTION: 0x007c5260
bool cSC43DRender::Slot67_abab60(void* object, int32_t mode)
{
    float box[6];
    cModel_abab60* model = static_cast<ObjectWithModel_abab60*>(object)->model;
    box[0] = 1.0f;
    box[1] = 1.0f;
    box[2] = 1.0f;
    box[3] = 0.0f;
    box[4] = 0.0f;
    box[5] = 0.0f;
    model->GetBoundingBox(box);
    if (mode == 2) {
        return static_cast<cFrustum_abab60*>(mpViewUtilities)->IsBoundingBoxInViewFrustum(&box[0], &box[3]);
    }
    return static_cast<cFrustum_abab60*>(mpViewUtilities)->Fn007f6910(&box[0], &box[3]);
}

#ifdef OB_DRAFTS
// CLOSE: 0x007c52f0 score 68
bool cSC43DRender::FindViewObject(uint32_t object)
{
    if (object == mnFocusedViewObject) {
        return true;
    }
    Node_abab60* head = static_cast<Node_abab60*>(mpViewListB);
    Node_abab60* n = head->next;
    if (n != head) {
        do {
            if (n->value == object) {
                return true;
            }
            n = n->next;
        } while (n != head);
    }
    head = static_cast<Node_abab60*>(mpViewListA);
    n = head->next;
    if (n != head) {
        do {
            if (n->value == object) {
                return true;
            }
            n = n->next;
        } while (n != head);
    }
    return Fn007c3b30(reinterpret_cast<List_abab60*>(&mpViewListD), object) ||
           Fn007c3b30(reinterpret_cast<List_abab60*>(&mpViewListC), object);
}
#endif

struct DrawContextLevel_abab60 {
    char pad[0x14];
    int32_t mnLevel;
};
struct Thresholds_abab60 {
    char pad0[0x184];
    int32_t t184;
    char pad1[0x24];
    int32_t t1ac;
    char pad2[0x24];
    int32_t t1d4;
};
struct RenderOwner_abab60 {
    char pad[0x18];
    Thresholds_abab60* thresholds;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c5540 score 22
bool cSC43DRender::Fn007c5540(void* element)
{
    uint16_t f = static_cast<GridElement_abab60*>(element)->flags;
    if (f & 0x100) {
        return false;
    }
    if (!(f & 0x20) && (f & 0x40)) {
        if (f & 0x400) {
            if (static_cast<DrawContextLevel_abab60*>(mpDrawContext)->mnLevel <
                static_cast<RenderOwner_abab60*>(mpRenderProps)->thresholds->t1ac) {
                return true;
            }
        }
        if (f & 0x1800) {
            if (static_cast<DrawContextLevel_abab60*>(mpDrawContext)->mnLevel <
                static_cast<RenderOwner_abab60*>(mpRenderProps)->thresholds->t184) {
                return true;
            }
        }
        if (f & 0x2000) {
            return static_cast<DrawContextLevel_abab60*>(mpDrawContext)->mnLevel <
                   static_cast<RenderOwner_abab60*>(mpRenderProps)->thresholds->t1d4;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007c38d0 score 54
bool cSC43DRender::Fn007c38d0()
{
    int32_t sy = mnShakeY;
    if (sy == 0 && mnShakeX == 0) {
        return Fn007c2ac0(0, 0, mnViewportW, mnViewportH, sy, sy);
    }
    int32_t dx;
    int32_t fromX;
    int32_t toX;
    if (mnShakeX < 0) {
        dx = -mnShakeX;
        toX = 0;
        fromX = dx;
    } else {
        dx = mnShakeX;
        toX = dx;
        fromX = 0;
    }
    int32_t dy;
    int32_t fromY;
    int32_t toY;
    if (sy < 0) {
        dy = -mnShakeY;
        fromY = dy;
        toY = 0;
    } else {
        dy = mnShakeY;
        toY = dy;
        fromY = 0;
    }
    return Fn007c2ac0(fromX, fromY, mnViewportW - dx, mnViewportH - dy, toX, toY);
}
#endif

// ---- agent 2, batch 1 ----
// STUB: 0x0090cf54
void* StlNew_abab60(uint32_t size);

struct IUnk_abab60 {
    virtual uint32_t QueryInterface(uint32_t iid, void* out);
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

// The graphics driver: slot 29 fetches the driver's name and description strings.
struct GfxDriver_abab60 : IUnk_abab60 {
    virtual void P03_abab60();
    virtual void P04_abab60();
    virtual void P05_abab60();
    virtual void P06_abab60();
    virtual void P07_abab60();
    virtual void P08_abab60();
    virtual void P09_abab60();
    virtual void P10_abab60();
    virtual void P11_abab60();
    virtual void P12_abab60();
    virtual void P13_abab60();
    virtual void P14_abab60();
    virtual void P15_abab60();
    virtual void P16_abab60();
    virtual void P17_abab60();
    virtual void P18_abab60();
    virtual void P19_abab60();
    virtual void P20_abab60();
    virtual void P21_abab60();
    virtual void P22_abab60();
    virtual void P23_abab60();
    virtual void P24_abab60();
    virtual void P25_abab60();
    virtual void P26_abab60();
    virtual void P27_abab60();
    virtual void P28_abab60();
    virtual void Slot29(void* name, void* description);
};

struct Str_abab60 {
    uint32_t pad;
    char* start;
    char* finish;
};

// FUNCTION: 0x007c5d00
void cSC43DRender::SetGraphicSystem(uint32_t system)
{
    IUnk_abab60* sys = OB_PTR(IUnk_abab60, system);
    if (sys) {
        sys->AddRef();
    }
    if (mpGraphicDriver) {
        static_cast<IUnk_abab60*>(mpGraphicDriver)->Release();
    }
    if (mpGraphicSystem) {
        static_cast<IUnk_abab60*>(mpGraphicSystem)->Release();
    }
    mpGraphicSystem = sys;
    if (sys) {
        sys->QueryInterface(0x73283c, &mpGraphicDriver);
    }
    if (mpGraphicDriver) {
        static_cast<GfxDriver_abab60*>(mpGraphicDriver)->Slot29(mDriverName, mDriverDesc);
    } else {
        Str_abab60* a = reinterpret_cast<Str_abab60*>(mDriverName);
        if (a->start != a->finish) {
            *a->start = 0;
            a->finish = a->start;
        }
        Str_abab60* b = reinterpret_cast<Str_abab60*>(mDriverDesc);
        if (b->start != b->finish) {
            *b->start = 0;
            b->finish = b->start;
        }
    }
}

// The 0x30-byte record of the model change queue, with its inlined copy.
struct ViewNode_abab60 {
    ViewNode_abab60* next;
    ViewNode_abab60* prev;
    ViewObject_abab60* object;
    uint32_t key;
};
struct ViewObjectRef_abab60 {
    virtual void Pad00_abab60();
    virtual uint32_t AddRef();
};

// STUB: 0x007c5c80
void Fn007c5c80(List_abab60* list, ViewObject_abab60* object, uint32_t key);

// FUNCTION: 0x007c5d90
bool cSC43DRender::AddViewObject(uint32_t object, uint32_t mode, uint32_t key)
{
    if (mode == 3) {
        Fn007c5c80(reinterpret_cast<List_abab60*>(&mpViewListA), OB_PTR(ViewObject_abab60, object), key);
        return true;
    }
    if (mode == 5) {
        Fn007c5c80(reinterpret_cast<List_abab60*>(&mpViewListB), OB_PTR(ViewObject_abab60, object), key);
        return true;
    }
    List_abab60* list;
    if (mode == 0) {
        list = reinterpret_cast<List_abab60*>(&mpViewListC);
    } else if (mode == 2) {
        list = reinterpret_cast<List_abab60*>(&mpViewListD);
    } else {
        return false;
    }
    Fn007c5c80(list, OB_PTR(ViewObject_abab60, object), key);
    mbBackingValid = false;
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x007c5c80 score 20
void Fn007c5c80(List_abab60* list, ViewObject_abab60* object, uint32_t key)
{
    reinterpret_cast<ViewObjectRef_abab60*>(object)->AddRef();
    ViewNode_abab60* head = reinterpret_cast<ViewNode_abab60*>(list->head);
    ViewNode_abab60* pos = head->next;
    while (pos != head) {
        if (pos->key > key) {
            ViewNode_abab60* node = static_cast<ViewNode_abab60*>(StlNew_abab60(0x10));
            if (&node->object) {
                node->object = object;
                node->key = key;
            }
            node->next = pos;
            node->prev = pos->prev;
            pos->prev->next = node;
            pos->prev = node;
            return;
        }
        pos = pos->next;
    }
    ViewNode_abab60* node = static_cast<ViewNode_abab60*>(StlNew_abab60(0x10));
    if (&node->object) {
        node->object = object;
        node->key = key;
    }
    node->next = head;
    node->prev = head->prev;
    head->prev->next = node;
    head->prev = node;
}
#endif

struct ModelInstProps_abab60 {
    uint8_t pad[6];
    uint8_t flags6;
};
struct ModelInst_abab60 {
    virtual void Pad00_abab60();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
    virtual void Pad03_abab60();
    virtual void Pad04_abab60();
    virtual ModelInstProps_abab60* GetProps();
    virtual void Slot06(uint32_t);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007ca180 score 20
bool cSC43DRender::IsModelInserted(uint32_t model)
{
    ModelInst_abab60* m = OB_PTR(ModelInst_abab60, model);
    ModelInstProps_abab60* props = m->GetProps();
    if (props) {
        if (props->flags6 & 0x10) {
            ModelChangeQueueItem_abab60* it = static_cast<ModelChangeQueueItem_abab60*>(mpQueueBegin);
            ModelChangeQueueItem_abab60* end = static_cast<ModelChangeQueueItem_abab60*>(mpQueueEnd);
            for (; it != end; ++it) {
                if (it->a == model && it->b == 1) {
                    return false;
                }
            }
            if (static_cast<uint32_t>(static_cast<ModelChangeQueueItem_abab60*>(mpQueueEnd) -
                                      static_cast<ModelChangeQueueItem_abab60*>(mpQueueBegin)) > 8) {
                ProcessModelChangeQueue();
            }
        }
        return true;
    }
    return false;
}
#endif

// STUB: 0x007c5870
ModelChangeQueueItem_abab60* Fn007c5870(ModelChangeQueueItem_abab60* first, ModelChangeQueueItem_abab60* last,
                                         ModelChangeQueueItem_abab60* dest, const char* tag, uint32_t n);

#ifdef OB_DRAFTS
// CLOSE: 0x007c6e30 score 16
void cSC43DRender::ClearModelChangeQueue()
{
    if (!mbQueueBusy) {
        mbQueueBusy = true;
        ModelChangeQueueItem_abab60* it = static_cast<ModelChangeQueueItem_abab60*>(mpQueueBegin);
        for (; it != static_cast<ModelChangeQueueItem_abab60*>(mpQueueEnd); ++it) {
            if (it->a) {
                ModelInstProps_abab60* props = OB_PTR(ModelInst_abab60, it->a)->GetProps();
                if (props) {
                    props->flags6 &= 0xe7;
                    uint32_t saved = it->a;
                    it->a = 0;
                    RemoveModel(saved);
                    it->a = saved;
                }
                OB_PTR(ModelInst_abab60, it->a)->Release();
            }
        }
        char tag;
        ModelChangeQueueItem_abab60* end = static_cast<ModelChangeQueueItem_abab60*>(mpQueueEnd);
        mpQueueEnd = Fn007c5870(end, end, static_cast<ModelChangeQueueItem_abab60*>(mpQueueBegin), &tag, 0);
        mbQueueBusy = false;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007c57e0 score 63
ModelChangeQueueItem_abab60* Fn007c57e0(ModelChangeQueueItem_abab60* dest, uint32_t n,
                                         const ModelChangeQueueItem_abab60* x)
{
    if (n > 0) {
        do {
        if (dest) {
            dest->a = x->a;
            dest->b = x->b;
            dest->c = x->c;
            dest->q = x->q;
            dest->s[0] = x->s[0];
            dest->s[1] = x->s[1];
            dest->s[2] = x->s[2];
            dest->s[3] = x->s[3];
            dest->s[4] = x->s[4];
            dest->s[5] = x->s[5];
        }
        ++dest;
        } while (--n != 0);
    }
    return dest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007c5750 score 70
ModelChangeQueueItem_abab60* Fn007c5750(ModelChangeQueueItem_abab60* first, ModelChangeQueueItem_abab60* last,
                                         ModelChangeQueueItem_abab60* dest)
{
    if (first != last) {
        do {
        if (dest) {
            dest->a = first->a;
            dest->b = first->b;
            dest->c = first->c;
            dest->q = first->q;
            dest->s[0] = first->s[0];
            dest->s[1] = first->s[1];
            dest->s[2] = first->s[2];
            dest->s[3] = first->s[3];
            dest->s[4] = first->s[4];
            dest->s[5] = first->s[5];
        }
        ++first;
        ++dest;
        } while (first != last);
    }
    return dest;
}
#endif

// The model change queue is a vector of 0x30-byte items; its push_back.
struct FalseType_abab60 {};  // the type tag the vector's overflow insert takes (items are not plain data)
struct ModelQueue_abab60 {
    ModelChangeQueueItem_abab60* begin;
    ModelChangeQueueItem_abab60* finish;
    ModelChangeQueueItem_abab60* cap;
    // STUB: 0x007c62b0
    void InsertOverflow(ModelChangeQueueItem_abab60* pos, const ModelChangeQueueItem_abab60& x, const FalseType_abab60& tag,
                        uint32_t n, bool atEnd);
    void PushBack(const ModelChangeQueueItem_abab60& x);
};

// FUNCTION: 0x007c6fe0
void ModelQueue_abab60::PushBack(const ModelChangeQueueItem_abab60& x)
{
    if (finish != cap) {
        if (finish) {
            new (finish) ModelChangeQueueItem_abab60(x);
        }
        ++finish;
    } else {
        FalseType_abab60 tag;
        InsertOverflow(finish, x, tag, 1, true);
    }
}

// The record of 0x40 bytes with two embedded vectors.
struct Vec12_abab60 {
    uint32_t v[3];
    // STUB: 0x00464760
    Vec12_abab60& operator=(const Vec12_abab60& o);
};
struct Rec40_abab60 {
    uint32_t a;
    uint32_t b;
    uint8_t c;
    uint32_t d;
    uint32_t e;
    uint32_t f;
    uint32_t g;
    Vec12_abab60 v1;
    Vec12_abab60 v2;
    uint32_t h;
    uint32_t i;
    uint32_t j;
    Rec40_abab60& Assign(const Rec40_abab60& o);
};

// FUNCTION: 0x007c63a0
Rec40_abab60& Rec40_abab60::Assign(const Rec40_abab60& o)
{
    a = o.a;
    b = o.b;
    c = o.c;
    d = o.d;
    e = o.e;
    f = o.f;
    g = o.g;
    v1 = o.v1;
    v2 = o.v2;
    h = o.h;
    i = o.i;
    j = o.j;
    return *this;
}

struct DrawCtxFlag_abab60 {
    char pad[0x20];
    uint32_t reason;
};
struct cCameraUnset_abab60 {
    // STUB: 0x007ff0b0
    void Unset();
};

// FUNCTION: 0x007ca9c0
void cSC43DRender::DoPartialViewUpdate(void* rect, uint32_t reason)
{
    if (gb0dc19) {
        const int32_t* r = static_cast<const int32_t*>(rect);
        if (r[2] > r[0] && r[3] > r[1]) {
            static_cast<DrawCtxFlag_abab60*>(mpDrawContext)->reason = reason;
            UpdateViewportRect(rect);
            gpB4e1ec->Slot75();
            static_cast<cCameraUnset_abab60*>(mpCamera)->Unset();
            static_cast<cCameraUnset_abab60*>(mpCamera2D)->Unset();
            mnCameraMode = 0;
            if (mbBackingValid) {
                mbBackingValid = SaveBackingStore(r[0], r[1], r[2] - r[0], r[3] - r[1]);
            }
            static_cast<DrawCtxFlag_abab60*>(mpDrawContext)->reason = 0;
        }
    }
}

struct ShakeNode_abab60 {
    ShakeNode_abab60* next;
    ShakeNode_abab60* prev;
    float f08;
    char pad0c[0x10];
    float f1c;
    float f20;
    void* p24;
    char pad28[0x8];
    void* p30;
    char pad34[0x10];
    uint32_t id;
};
struct Timer_abab60 {
    // STUB: 0x00890377
    void GetElapsedTime(float& out) const;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c8630 score 42
void cSC43DRender::StopScreenShake(uint32_t id)
{
    ShakeNode_abab60* head = static_cast<ShakeNode_abab60*>(mpShakeList);
    ShakeNode_abab60* n = head->next;
    if (n == head) {
        return;
    }
    while (n->id != id) {
        n = n->next;
        if (n == head) {
            return;
        }
    }
    if (n->f20 == 0.0f) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        if (n->p30) {
            StlDelete_abab60(n->p30);
        }
        if (n->p24) {
            StlDelete_abab60(n->p24);
        }
        StlDelete_abab60(n);
        return;
    }
    float t;
    reinterpret_cast<const Timer_abab60*>(&mTimerBase)->GetElapsedTime(t);
    t = (n->f20 - n->f1c) + t;
    if (t < n->f08) {
        n->f08 = t;
    }
}
#endif

// ---- agent 2, batch 2 ----
struct DrawCtxScale_abab60 {
    char pad[0x10];
    float scale;
    int32_t w;
    int32_t h;
};
struct RenderPropsInner_abab60 {
    char pad[0x15c];
    int32_t value;
};
struct RenderPropsOuter_abab60 {
    char pad[0x18];
    RenderPropsInner_abab60* inner;
};

// FUNCTION: 0x007cab30
void cSC43DRender::Fn007cab30(int32_t a, int32_t b, int32_t c, int32_t d)
{
    if (b != d) {
        if (mpQueueBegin != mpQueueEnd) {
            ProcessModelChangeQueue();
        }
        mbFullUpdateDone = true;
        mbBackingValid = false;
        static_cast<DrawCtxScale_abab60*>(mpDrawContext)->scale = static_cast<float>(c);
        static_cast<DrawCtxScale_abab60*>(mpDrawContext)->w = c;
        static_cast<DrawCtxScale_abab60*>(mpDrawContext)->h = d;
        RebuildQuadGrid(a, b, c, d);
        static_cast<cViewUtil_abab60*>(mpViewUtilities)->Fn007f9f50(mnViewOrigin, &mnViewportW2);
        mbDirtyA = false;
        mbDirtyB = false;
        ++mnCounter15c;
        ClearDirtyRectangleQueue();
    }
}

// FUNCTION: 0x007caa60
void cSC43DRender::Fn007caa60(int32_t a, int32_t b, int32_t c, int32_t d)
{
    if (a != c) {
        if (mpQueueBegin != mpQueueEnd) {
            ProcessModelChangeQueue();
        }
        SetBackingStoreEnabled(c < static_cast<RenderPropsOuter_abab60*>(mpRenderProps)->inner->value);
        mbFullUpdateDone = true;
        mbBackingValid = false;
        static_cast<DrawCtxScale_abab60*>(mpDrawContext)->scale = static_cast<float>(c);
        static_cast<DrawCtxScale_abab60*>(mpDrawContext)->w = c;
        static_cast<DrawCtxScale_abab60*>(mpDrawContext)->h = d;
        RebuildQuadGrid(a, b, c, d);
        static_cast<cViewUtil_abab60*>(mpViewUtilities)->Fn007f9f50(mnViewOrigin, &mnViewportW2);
        Fn007c55c0();
        mbDirtyA = false;
        mbDirtyB = false;
        ++mnCounter15c;
        ClearDirtyRectangleQueue();
    }
}

struct CleanupTimer_abab60 {
    // STUB: 0x0088fefb
    bool IsTimerRunning() const;
    // STUB: 0x00890198
    uint32_t GetElapsedTime() const;
    // STUB: 0x0088ff0a
    void Reset();
    // STUB: 0x0089058f
    void Restart();
};

#ifdef OB_DRAFTS
// CLOSE: 0x007cafb0 score 54
void cSC43DRender::DoViewCleanup()
{
    if (mbCleanupB && mbCleanupA) {
        CleanupTimer_abab60* timer = reinterpret_cast<CleanupTimer_abab60*>(mCleanupTimer);
        if (timer->IsTimerRunning()) {
            if (timer->GetElapsedTime() > mnCleanupDelay) {
                int32_t rect[4];
                rect[0] = mCleanupRect[0];
                rect[1] = mCleanupRect[1];
                rect[2] = mCleanupRect[2];
                rect[3] = mCleanupRect[3];
                rect[2] = mnCleanupStep + rect[0];
                if (rect[2] > mCleanupRect[2]) {
                    rect[2] = mCleanupRect[2];
                }
                DoPartialViewUpdate(rect, 9);
                mCleanupRect[0] = rect[2];
                if (rect[2] >= mCleanupRect[2]) {
                    mbCleanupB = false;
                    timer->Reset();
                }
            }
        } else {
            timer->Restart();
        }
    }
}
#endif

struct DirtyNode_abab60 {
    DirtyNode_abab60* next;
    DirtyNode_abab60* prev;
    char pad[0x18];
    ViewObject_abab60* object;
};

// STUB: 0x007257c0
void* Fn007257c0(void* first, void* last, void* dest, const char* tag, uint32_t n);

#ifdef OB_DRAFTS
// CLOSE: 0x007c6d80 score 28
void cSC43DRender::ClearDirtyRectangleQueue()
{
    DirtyNode_abab60* head = static_cast<DirtyNode_abab60*>(mpDirtyList);
    if (head->next != head) {
        DirtyNode_abab60* tail = head;
        DirtyNode_abab60* n = tail->next;
        if (n != tail) {
            do {
                if (n->object) {
                    n->object->Release();
                }
                n = n->next;
            } while (n != tail);
        }
        n = static_cast<DirtyNode_abab60*>(mpDirtyList)->next;
        while (n != static_cast<DirtyNode_abab60*>(mpDirtyList)) {
            DirtyNode_abab60* cur = n;
            n = n->next;
            StlDelete_abab60(cur);
        }
        static_cast<DirtyNode_abab60*>(mpDirtyList)->next = static_cast<DirtyNode_abab60*>(mpDirtyList);
        static_cast<DirtyNode_abab60*>(mpDirtyList)->prev = static_cast<DirtyNode_abab60*>(mpDirtyList);
        char tag;
        void* end = mpDirtyVecEnd;
        mpDirtyVecEnd = Fn007257c0(end, end, mpDirtyVecBegin, &tag, 0);
        mnDirty1d8 = 0;
        mnDirty1e0 = 0;
    }
}
#endif

struct Vec4_abab60 {
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t w;
    Vec4_abab60()
    {
        x = gdB4e1f8;
        y = gdB4e1f8;
        z = gdB4e1f8;
        w = gdB4e1f8;
    }
};
struct Vec4Vector_abab60 {
    Vec4_abab60* begin;
    Vec4_abab60* finish;
    Vec4_abab60* cap;
    explicit Vec4Vector_abab60(uint32_t n);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c5be0 score 56
Vec4Vector_abab60::Vec4Vector_abab60(uint32_t n)
{
    begin = 0;
    finish = 0;
    cap = 0;
    Vec4_abab60* p = 0;
    if (n) {
        p = static_cast<Vec4_abab60*>(StlNew_abab60(n * sizeof(Vec4_abab60)));
    }
    cap = p + n;
    begin = p;
    finish = p;
    Vec4_abab60 x;
    for (; n > 0; --n) {
        if (p) {
            *p = x;
        }
        ++p;
    }
    finish = p;
}
#endif

struct GridCell_abab60 {
    char pad[0xc];
    uint16_t flags;
};
struct GridRow_abab60 {
    GridCell_abab60* begin;
    GridCell_abab60* end;
    uint32_t pad;
};
struct GridState_abab60 {
    int32_t count;
    char pad[0x10];
    GridRow_abab60* rowsBegin;
    GridRow_abab60* rowsEnd;
    // STUB: 0x005f34b0
    void GetAllElements(GridElement_abab60** out, int32_t* count);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c55c0 score 48
void cSC43DRender::Fn007c55c0()
{
    GridState_abab60* grid = static_cast<GridState_abab60*>(mpQuadGrid);
    if (grid) {
        int32_t count = grid->count;
        GridElement_abab60** all = static_cast<GridElement_abab60**>(operator new(count * 4));
        static_cast<GridState_abab60*>(mpQuadGrid)->GetAllElements(all, &count);
        for (int32_t i = 0; i < count; ++i) {
            GridElement_abab60* e = all[i];
            e->flags |= 8;
            uint16_t bits = e->flags;
            if (!Fn007c5540(e)) {
                e->flags = bits & 0xfff7;
            }
        }
        operator delete(all);
        GridRow_abab60* row = static_cast<GridState_abab60*>(mpQuadGrid)->rowsBegin;
        GridRow_abab60* rowEnd = static_cast<GridState_abab60*>(mpQuadGrid)->rowsEnd;
        for (; row != rowEnd; ++row) {
            GridCell_abab60* c = row->begin;
            for (; c != row->end; ++c) {
                c->flags |= 1;
            }
        }
    }
}
#endif

struct cViewUtilF_abab60 {
    char pad0[0x10];
    int32_t index;
    char pad1[0x14];
    int32_t w;
    int32_t h;
    char pad2[0x1fc];
    int32_t v22c;
    int32_t v230;
    int32_t v234;
    int32_t v238;
    // STUB: 0x007f8390
    void Fn007f8390(float* v);
};

// FUNCTION: 0x007c1e10
void cSC43DRender::Fn007c1e10(float* out)
{
    float a[3];
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    cViewUtilF_abab60* vu = static_cast<cViewUtilF_abab60*>(mpViewUtilities);
    float b[3];
    b[0] = static_cast<float>(vu->w);
    b[1] = static_cast<float>(vu->h);
    b[2] = 0;
    vu->Fn007f8390(a);
    a[0] = a[0] + mfOffsetsX[static_cast<cViewUtilF_abab60*>(mpViewUtilities)->index];
    a[1] = -a[1];
    a[1] = a[1] + mfOffsetsY[static_cast<cViewUtilF_abab60*>(mpViewUtilities)->index];
    static_cast<cViewUtilF_abab60*>(mpViewUtilities)->Fn007f8390(b);
    b[0] = b[0] + mfOffsetsX[static_cast<cViewUtilF_abab60*>(mpViewUtilities)->index];
    b[1] = -b[1];
    b[1] = b[1] + mfOffsetsY[static_cast<cViewUtilF_abab60*>(mpViewUtilities)->index];
    out[0] = a[0];
    out[1] = a[1];
    out[2] = b[0];
    out[3] = b[1];
}

// FUNCTION: 0x007c1ef0
void cSC43DRender::Fn007c1ef0(float* out)
{
    cViewUtilF_abab60* vu = static_cast<cViewUtilF_abab60*>(mpViewUtilities);
    float a[3];
    a[0] = static_cast<float>(vu->v22c);
    a[1] = static_cast<float>(vu->v230);
    a[2] = 0;
    float b[3];
    b[0] = static_cast<float>(vu->v234);
    b[1] = static_cast<float>(vu->v238);
    b[2] = 0;
    vu->Fn007f8390(a);
    a[0] = a[0] + mfOffsetsX[static_cast<cViewUtilF_abab60*>(mpViewUtilities)->index];
    a[1] = -a[1];
    a[1] = a[1] + mfOffsetsY[static_cast<cViewUtilF_abab60*>(mpViewUtilities)->index];
    static_cast<cViewUtilF_abab60*>(mpViewUtilities)->Fn007f8390(b);
    b[0] = b[0] + mfOffsetsX[static_cast<cViewUtilF_abab60*>(mpViewUtilities)->index];
    b[1] = -b[1];
    b[1] = b[1] + mfOffsetsY[static_cast<cViewUtilF_abab60*>(mpViewUtilities)->index];
    out[0] = a[0];
    out[1] = a[1];
    out[2] = b[0];
    out[3] = b[1];
}

#ifdef OB_DRAFTS
// CLOSE: 0x007c1fd0 score 108
void cSC43DRender::Fn007c1fd0(float* out, int32_t mode)
{
    float* r;
    if (mode == 0 || mode == 1) {
        if (!mbDirtyB) {
            r = mfRectB;
            Fn007c1ef0(r);
            mbDirtyB = true;
            goto clamp;
        }
        r = mfRectB;
    } else {
        if (!mbDirtyA) {
            r = mfRectA;
            Fn007c1e10(r);
            mbDirtyA = true;
        clamp:
            if (r[0] < 0.0f) {
                r[0] = 0.0f;
            }
            if (r[1] < 0.0f) {
                r[1] = 0.0f;
            }
            if (mfQuadGridSize - 1.0f < r[2]) {
                r[2] = mfQuadGridSize - 1.0f;
            }
            if (mfQuadGridSize - 1.0f < r[3]) {
                r[3] = mfQuadGridSize - 1.0f;
            }
            out[0] = r[0];
            out[1] = r[1];
            out[2] = r[2];
            out[3] = r[3];
            return;
        }
        r = mfRectA;
    }
    out[0] = r[0];
    out[1] = r[1];
    out[2] = r[2];
    out[3] = r[3];
}
#endif

// ---- agent 2, batch 3 ----
// GLOBAL: 0x00b0dc20
extern float gfB0dc20;

struct VecF3_abab60 {
    float x;
    float y;
    float z;
    VecF3_abab60()
    {
        *reinterpret_cast<uint32_t*>(&x) = gdB4e1f8;
        *reinterpret_cast<uint32_t*>(&y) = gdB4e1f8;
        *reinterpret_cast<uint32_t*>(&z) = gdB4e1f8;
    }
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c5000 score 23
bool cSC43DRender::PickTerrain(int32_t x, int32_t y, void* out, bool a, bool b)
{
    bool result = false;
    if (mpCamera && mnFocusedViewObject) {
        VecF3_abab60 origin;
        VecF3_abab60 dir;
        float point[2];
        point[0] = static_cast<float>(x);
        point[1] = static_cast<float>(y);
        if (static_cast<cCamera_abab60*>(mpCamera)->GetEyeRay(point, &origin, &dir)) {
            float scale = gfB0dc20 / sqrtf(dir.z * dir.z + dir.y * dir.y + dir.x * dir.x);
            dir.x = dir.x * scale;
            dir.y = dir.y * scale;
            dir.z = dir.z * scale;
            result = PickTerrain_2(&origin, &dir, out, a, b);
        }
    }
    return result;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007c50f0 score 23
bool cSC43DRender::PickTerrainAlways(int32_t x, int32_t y, void* out, bool a)
{
    bool result = false;
    if (mpCamera && mnFocusedViewObject) {
        VecF3_abab60 origin;
        VecF3_abab60 dir;
        float point[2];
        point[0] = static_cast<float>(x);
        point[1] = static_cast<float>(y);
        if (static_cast<cCamera_abab60*>(mpCamera)->GetEyeRay(point, &origin, &dir)) {
            float scale = gfB0dc20 / sqrtf(dir.z * dir.z + dir.y * dir.y + dir.x * dir.x);
            dir.x = dir.x * scale;
            dir.y = dir.y * scale;
            dir.z = dir.z * scale;
            result = PickTerrainAlways_2(&origin, &dir, out, a);
        }
    }
    return result;
}
#endif

// ---- agent 2, batch 4 ----
struct GridProps_abab60 {
    char pad[6];
    uint8_t flags6;
    char pad2[0x15];
    uint32_t box[6];
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c9220 score 39
bool cSC43DRender::MoveModel(uint32_t model)
{
    ModelInst_abab60* m = OB_PTR(ModelInst_abab60, model);
    m->AddRef();
    GridProps_abab60* props = reinterpret_cast<GridProps_abab60*>(m->GetProps());
    if (props) {
        if (props->flags6 & 8) {
            Quad_abab60 quad;
            quad.v[0] = 0;
            quad.v[1] = 0;
            quad.v[2] = 0;
            quad.v[3] = 0;
            ModelChangeQueueItem_abab60 item(model, 2, 0, quad, props->box);
            m->AddRef();
            props->flags6 |= 0x10;
            ModelQueue_abab60* q = reinterpret_cast<ModelQueue_abab60*>(&mpQueueBegin);
            q->PushBack(item);
            if (static_cast<int32_t>(q->finish - q->begin) == 200) {
                DoFullViewUpdate(4);
            }
        } else {
            MoveGridElement(props, m);
        }
    } else {
        InsertModel(model);
    }
    m->Release();
    return true;
}
#endif

struct cViewUtilW_abab60 {
    // STUB: 0x007f78a0
    float Fn007f78a0(float* v);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007c2f80 score 50
void Fn007c2f80(float* out, cViewUtilW_abab60* vu)
{
    float v[3];
    float r[3];
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    r[0] = vu->Fn007f78a0(v);
    v[0] = 1.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    r[1] = vu->Fn007f78a0(v);
    v[0] = 0.0f;
    v[1] = 1.0f;
    v[2] = 0.0f;
    r[2] = vu->Fn007f78a0(v);
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 1.0f;
    float r3 = vu->Fn007f78a0(v);
    out[0] = r[1] - r[0];
    out[1] = r[2] - r[0];
    out[2] = r3 - r[0];
    out[3] = r[0] + 1.0f;
}
#endif

// ---- agent 2, batch 5 ----
struct DirtyRectNode_abab60 {
    DirtyRectNode_abab60* next;
    DirtyRectNode_abab60* prev;
    int32_t pad[2];
    int32_t x0;
    int32_t y0;
    int32_t x1;
    int32_t y1;
};

#ifdef OB_DRAFTS
// CLOSE: 0x007cabe0 score 62
bool cSC43DRender::AttemptTranslatedViewUpdate(int32_t dx, int32_t dy)
{
    int32_t ax = abs(dx);
    if (ax < static_cast<int32_t>(mnViewportW) * 14 / 16) {
        int32_t ay = abs(dy);
        if (ay < static_cast<int32_t>(mnViewportH) * 14 / 16 && mbBufferRegionsUsable && gb0dc19 && mbBackingValid &&
            gb4e1e4) {
            DirtyRectNode_abab60* n = static_cast<DirtyRectNode_abab60*>(mpDirtyList)->next;
            while (n != static_cast<DirtyRectNode_abab60*>(mpDirtyList)) {
                n->x0 += -dx;
                n->x1 += -dx;
                n->y0 += dy;
                n->y1 += dy;
                n = n->next;
            }
            DoTranslatedViewUpdate(dx, dy);
            return true;
        }
    }
    static_cast<DrawCtxFlag_abab60*>(mpDrawContext)->reason = 3;
    mbFullUpdateDone = true;
    mbBackingValid = false;
    static_cast<cViewUtil_abab60*>(mpViewUtilities)->Fn007f9f50(mnViewOrigin, &mnViewportW2);
    mbDirtyA = false;
    mbDirtyB = false;
    ClearDirtyRectangleQueue();
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007c5ac0 score 49
bool cSC43DRender::RemoveViewObject(uint32_t object)
{
    ViewObject_abab60* o = OB_PTR(ViewObject_abab60, object);
    bool result = false;
    if (object == mnFocusedViewObject) {
        if (mnFocusedViewObject) {
            OB_PTR(ViewObject_abab60, mnFocusedViewObject)->Release();
            mnFocusedViewObject = 0;
        }
        result = true;
    }
    ViewNode_abab60* head = static_cast<ViewNode_abab60*>(mpViewListB);
    ViewNode_abab60* n = head->next;
    while (n != head) {
        if (n->object == o) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            StlDelete_abab60(n);
            o->Release();
            result = true;
            break;
        }
        n = n->next;
    }
    head = static_cast<ViewNode_abab60*>(mpViewListA);
    n = head->next;
    while (n != head) {
        if (n->object == o) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            StlDelete_abab60(n);
            o->Release();
            result = true;
            break;
        }
        n = n->next;
    }
    head = static_cast<ViewNode_abab60*>(mpViewListD);
    n = head->next;
    while (n != head) {
        if (n->object == o) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            StlDelete_abab60(n);
            o->Release();
            mbBackingValid = false;
            result = true;
            break;
        }
        n = n->next;
    }
    head = static_cast<ViewNode_abab60*>(mpViewListC);
    n = head->next;
    while (n != head) {
        if (n->object == o) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            StlDelete_abab60(n);
            o->Release();
            mbBackingValid = false;
            result = true;
            break;
        }
        n = n->next;
    }
    return result;
}
#endif

struct GridPropsW_abab60 {
    char pad[6];
    uint16_t flags;
};
struct cQuadGridR_abab60 {
    // STUB: 0x005f2b30
    bool RemoveElement(void* element);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007ca3d0 score 53
bool cSC43DRender::RemoveModel(uint32_t model)
{
    ModelInst_abab60* m = OB_PTR(ModelInst_abab60, model);
    bool result = false;
    m->AddRef();
    GridProps_abab60* props = reinterpret_cast<GridProps_abab60*>(m->GetProps());
    if (props) {
        uint16_t bits = reinterpret_cast<GridPropsW_abab60*>(props)->flags;
        if (bits & 8) {
            if (bits & 0x10) {
                ProcessModelChangeQueue();
                props = reinterpret_cast<GridProps_abab60*>(m->GetProps());
            }
            if (props) {
                Quad_abab60 quad;
                quad.v[0] = 0;
                quad.v[1] = 0;
                quad.v[2] = 0;
                quad.v[3] = 0;
                ModelChangeQueueItem_abab60 item(model, 1, 0, quad, props->box);
                m->AddRef();
                props->flags6 |= 0x10;
                ModelQueue_abab60* q = reinterpret_cast<ModelQueue_abab60*>(&mpQueueBegin);
                q->PushBack(item);
                if (static_cast<int32_t>(q->finish - q->begin) == 200) {
                    DoFullViewUpdate(4);
                }
                result = true;
            }
        } else {
            if (bits & 0x10) {
                ProcessModelChangeQueue();
            }
            result = static_cast<cQuadGridR_abab60*>(mpQuadGrid)->RemoveElement(props);
            if (result) {
                m->Release();
            }
            m->Slot06(0);
        }
    }
    m->Release();
    return result;
}
#endif
