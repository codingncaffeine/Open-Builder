#include "classes/cSC43DRender.h"

#include <cstddef>
#include <new>

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
    void GetEyeRay(const float* point, void* origin, void* direction);
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
    ModelChangeQueueItem_abab60(const ModelChangeQueueItem_abab60& o);
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
