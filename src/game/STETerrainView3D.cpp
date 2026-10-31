#include <new>

#include "classes/cSTETerrainView3D.h"

// Terrain-size globals shared by this file's functions (the Mac build's statics sVertexCountX, ...).
// GLOBAL: 0x00b4c744
extern uint32_t gnB4c744;
// GLOBAL: 0x00b4c748
extern uint32_t gnB4c748;
// GLOBAL: 0x00b4c6d8
extern uint32_t gnB4c6d8;
// GLOBAL: 0x00b4c6d4
extern uint32_t gnB4c6d4;
// GLOBAL: 0x00b4c74c
extern uint32_t gnB4c74c;
// GLOBAL: 0x00b4c754
extern uint32_t gnB4c754;
// GLOBAL: 0x00b4c758
extern uint8_t* gpB4c758;
// GLOBAL: 0x00b4c75c
extern uint8_t* gpB4c75c;
// GLOBAL: 0x00b0d6fc
extern uint32_t gnB0d6fc;
// GLOBAL: 0x00b4c70c
extern uint32_t gnB4c70c;

// The target the base-class slots forward to (a member at 0x6c); its methods are still the original's.
struct Delegate_ab4380 {
    // STUB: 0x007516d0
    bool Fn007516d0(uint32_t, uint32_t, uint32_t);
    // STUB: 0x00751780
    bool Fn00751780(uint32_t, uint32_t, uint32_t);
    // STUB: 0x00751910
    bool Fn00751910(uint32_t, uint32_t, uint32_t);
    // STUB: 0x007519a0
    bool Fn007519a0(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
    // STUB: 0x00751a70
    bool Fn00751a70(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
};

// An object with a vtable whose slots 9 and 14 return packed 16:16 sizes.
struct OB_NOVTABLE Sized_ab4380 {
    virtual void QueryInterface();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab4380();
    virtual void Slot04_ab4380();
    virtual void Slot05_ab4380();
    virtual void Slot06_ab4380();
    virtual void Slot07_ab4380();
    virtual void Slot08_ab4380();
    virtual uint32_t Slot09_ab4380();
    virtual void Slot10_ab4380();
    virtual void Slot11_ab4380();
    virtual void Slot12_ab4380();
    virtual void Slot13_ab4380();
    virtual uint32_t Slot14_ab4380();
};

// A terrain vertex (0x20 bytes).
struct Vertex_ab4380 {
    float x;
    float y;
    float z;
    uint8_t b;
    uint8_t g;
    uint8_t r;
    uint8_t a;
    float u;
    float v;
    float u2;
    float v2;
};

// A 0x80-byte record that std::vector copies around.
struct Record_ab4380 {
    uint32_t m[32];
    // STUB: 0x007565f0
    Record_ab4380(const Record_ab4380&);
    Record_ab4380& operator=(const Record_ab4380&);
    void Fn00755dd0();
};

// A 4-byte element the same vector code walks.
struct Element_ab4380 {
    uint32_t mValue;
    // STUB: 0x0075ae00
    void Fn0075ae00(const Element_ab4380*);
};

// STUB: 0x00756ca0
void Fn00756ca0();
// STUB: 0x007571d0
void Fn007571d0(uint32_t);

// A service object whose slot 12 takes an id, a count, an out value and a size.
struct OB_NOVTABLE Service_ab4380 {
    virtual void QueryInterface();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab4380();
    virtual void Slot04_ab4380();
    virtual void Slot05_ab4380();
    virtual void Slot06_ab4380();
    virtual void Slot07_ab4380();
    virtual void Slot08_ab4380();
    virtual void Slot09_ab4380();
    virtual void Slot10_ab4380();
    virtual void Slot11_ab4380();
    virtual void Slot12_ab4380(uint32_t*, uint32_t, uint32_t*, uint32_t);
};

// GLOBAL: 0x00b4c738
extern Service_ab4380* gpB4c738;
// GLOBAL: 0x00b4c7b8
extern uint32_t* gpB4c7b8;

// FUNCTION: 0x007558a0
uint32_t cSTETerrainView3D::Slot18_ab4380(uint32_t index)
{
    return mnTexSlot[index];
}

// FUNCTION: 0x00752660
bool cSTETerrainView3D::Slot08_ab4380(uint32_t a, uint32_t b, uint32_t c)
{
    if (mpDelegate) {
        return static_cast<Delegate_ab4380*>(mpDelegate)->Fn007516d0(a, b, c);
    }
    return false;
}

// FUNCTION: 0x00752680
bool cSTETerrainView3D::Slot07_ab4380(uint32_t a, uint32_t b, uint32_t c)
{
    if (mpDelegate) {
        return static_cast<Delegate_ab4380*>(mpDelegate)->Fn00751780(a, b, c);
    }
    return false;
}

// FUNCTION: 0x007526a0
bool cSTETerrainView3D::Slot06_ab4380(uint32_t a, uint32_t b, uint32_t c)
{
    if (mpDelegate) {
        return static_cast<Delegate_ab4380*>(mpDelegate)->Fn00751910(a, b, c);
    }
    return false;
}

// FUNCTION: 0x007526c0
bool cSTETerrainView3D::Slot05_ab4380(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    if (mpDelegate) {
        return static_cast<Delegate_ab4380*>(mpDelegate)->Fn007519a0(a, b, c, d, e, f, g);
    }
    return false;
}

// FUNCTION: 0x007526e0
bool cSTETerrainView3D::Slot04_ab4380(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    if (mpDelegate) {
        return static_cast<Delegate_ab4380*>(mpDelegate)->Fn00751a70(a, b, c, d, e, f, g);
    }
    return false;
}

// FUNCTION: 0x00752700
bool cSTETerrainView3D::Slot04_a881c0(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    return Slot03_ab4380(a, b, c, d, 0);
}

// FUNCTION: 0x00752820
void cSTETerrainView3D::GetCullingInfo(void* pFirst, void* pSecond, void* pThird, void* pFourth)
{
    *static_cast<uint32_t*>(pFirst) = mnCullFirst;
    *static_cast<uint32_t*>(pSecond) = mnCullSecond;
    *static_cast<uint32_t*>(pThird) = gnB4c6d8;
    *static_cast<uint32_t*>(pFourth) = gnB4c6d4;
}

// FUNCTION: 0x007523f0
void Fn007523f0(Sized_ab4380* pObject, uint32_t* pOut)
{
    uint32_t width = pObject->Slot09_ab4380();
    pOut[0] = width >> 16;
    pOut[2] = width & 0xffff;
    uint32_t height = pObject->Slot14_ab4380();
    pOut[1] = height >> 16;
    pOut[3] = height & 0xffff;
}

// FUNCTION: 0x00755fb0
void cSTETerrainView3D::Fn00755fb0()
{
    for (uint32_t row = 0; row < gnB4c748; ++row) {
        for (uint32_t col = 0; col < gnB4c744; ++col) {
            SetTriangleIndicesForCell(row, col);
        }
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x007565f0 score 999
Record_ab4380::Record_ab4380(const Record_ab4380& other)
{
    for (int i = 0; i < 32; ++i) {
        m[i] = other.m[i];
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00756690 score 37
Record_ab4380* Fn00756690(Record_ab4380* pDest, uint32_t count, const Record_ab4380* pSource)
{
    for (; count != 0; --count) {
        if (pDest) {
            new (pDest) Record_ab4380(*pSource);
        }
        ++pDest;
    }
    return pDest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00756650 score 35
Record_ab4380* Fn00756650(const Record_ab4380* pFirst, const Record_ab4380* pLast, Record_ab4380* pDest)
{
    for (; pFirst != pLast; ++pFirst) {
        if (pDest) {
            new (pDest) Record_ab4380(*pFirst);
        }
        ++pDest;
    }
    return pDest;
}
#endif

// FUNCTION: 0x0075af00
void Fn0075af00(Element_ab4380* pFirst, Element_ab4380* pLast, const Element_ab4380* value)
{
    for (; pFirst != pLast; ++pFirst) {
        pFirst->Fn0075ae00(value);
    }
}

// FUNCTION: 0x00757470
void* Fn00757470()
{
    void* pMemory = operator new(0xe8);
    if (pMemory) {
        void* pObject = static_cast<cSTETerrainView3D*>(pMemory)->Fn007567c0();
        if (pObject) {
            return static_cast<uint8_t*>(pObject) + 0xc;
        }
    }
    return 0;
}

// FUNCTION: 0x007574a0
void Fn007574a0(uint32_t value)
{
    if (gnB0d6fc != value) {
        Fn00756ca0();
        gnB0d6fc = value;
        Fn007571d0(gnB4c70c);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x00752430 score 999
void Fn00752430()
{
    for (uint32_t i = 0; i < gnB4c754; ++i) {
        Vertex_ab4380* pVertex = reinterpret_cast<Vertex_ab4380*>(gpB4c758 + i * 0x20);
        float column = static_cast<float>(static_cast<int32_t>(i % gnB4c74c));
        float row = static_cast<float>(static_cast<int32_t>(i / gnB4c74c));
        pVertex->x = column * 16.0f;
        pVertex->z = static_cast<float>(static_cast<int32_t>(row)) * 16.0f;
        pVertex->a = 0xff;
        pVertex->u2 = 0.0f;
        pVertex->v2 = 0.0f;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00752520 score 999
void Fn00752520()
{
    for (uint32_t i = 0; i < gnB4c754; ++i) {
        Vertex_ab4380* pVertex = reinterpret_cast<Vertex_ab4380*>(gpB4c75c + i * 0x20);
        float column = static_cast<float>(static_cast<int32_t>(i % gnB4c74c));
        float row = static_cast<float>(static_cast<int32_t>(i / gnB4c74c));
        pVertex->x = column * 16.0f;
        pVertex->z = row * 16.0f;
        pVertex->a = 0;
        pVertex->g = 0;
        pVertex->b = 0xff;
        pVertex->r = 0;
        pVertex->u = pVertex->x * 0.0125f;
        pVertex->v = pVertex->z * 0.0125f;
        pVertex->u2 = 0.0f;
        pVertex->v2 = 0.0f;
    }
    uint32_t out = 0;
    uint32_t iid[3] = { 0x7ab50e44, 0x891b0e1a, 0x69efb7da };
    if (gpB4c738 == 0) {
        gpB4c7b8 = 0;
        return;
    }
    gpB4c738->Slot12_ab4380(iid, 1, &out, 8);
    gpB4c7b8 = &out;
}
#endif

// ---- batch 2 ----

// GLOBAL: 0x00b4bc5c
extern bool gbB4bc5c;
// GLOBAL: 0x00b0d718
extern bool gbB0d718;
// GLOBAL: 0x00b4c7c0
extern float gfB4c7c0;
// GLOBAL: 0x00b4c7ec
extern uint32_t* gpB4c7ec;
// GLOBAL: 0x00b4c7f0
extern int32_t gnB4c7f0;
// GLOBAL: 0x00b4c6d0
extern uint8_t* gpB4c6d0;
// GLOBAL: 0x00b4c700
extern uint32_t gnB4c700;
// GLOBAL: 0x00b4c6f4
extern uint16_t* gpB4c6f4;
// GLOBAL: 0x00b4c6d8
extern int32_t* gpB4c6d8List;
// GLOBAL: 0x00b4c6d4
extern int32_t* gpB4c6d4List;

// The terrain object at +0x20 (slot 83 answers a flag).
struct OB_NOVTABLE Terrain_ab4380 {
    virtual void QueryInterface();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab4380();
    virtual void Slot04_ab4380();
    virtual void Slot05_ab4380();
    virtual void Slot06_ab4380();
    virtual void Slot07_ab4380();
    virtual void Slot08_ab4380();
    virtual void Slot09_ab4380();
    virtual void Slot10_ab4380();
    virtual void Slot11_ab4380();
    virtual void Slot12_ab4380();
    virtual void Slot13_ab4380();
    virtual void Slot14_ab4380();
    virtual void Slot15_ab4380();
    virtual void Slot16_ab4380();
    virtual void Slot17_ab4380();
    virtual void Slot18_ab4380();
    virtual void Slot19_ab4380();
    virtual void Slot20_ab4380();
    virtual void Slot21_ab4380();
    virtual void Slot22_ab4380();
    virtual void Slot23_ab4380();
    virtual void Slot24_ab4380();
    virtual void Slot25_ab4380();
    virtual void Slot26_ab4380();
    virtual void Slot27_ab4380();
    virtual void Slot28_ab4380();
    virtual void Slot29_ab4380();
    virtual void Slot30_ab4380();
    virtual void Slot31_ab4380();
    virtual void Slot32_ab4380();
    virtual void Slot33_ab4380();
    virtual void Slot34_ab4380();
    virtual void Slot35_ab4380();
    virtual void Slot36_ab4380();
    virtual void Slot37_ab4380();
    virtual void Slot38_ab4380();
    virtual void Slot39_ab4380();
    virtual void Slot40_ab4380();
    virtual void Slot41_ab4380();
    virtual void Slot42_ab4380();
    virtual void Slot43_ab4380();
    virtual void Slot44_ab4380();
    virtual void Slot45_ab4380();
    virtual void Slot46_ab4380();
    virtual void Slot47_ab4380();
    virtual void Slot48_ab4380();
    virtual void Slot49_ab4380();
    virtual void Slot50_ab4380();
    virtual void Slot51_ab4380();
    virtual void Slot52_ab4380();
    virtual void Slot53_ab4380();
    virtual void Slot54_ab4380();
    virtual void Slot55_ab4380();
    virtual void Slot56_ab4380();
    virtual void Slot57_ab4380();
    virtual void Slot58_ab4380();
    virtual void Slot59_ab4380();
    virtual void Slot60_ab4380();
    virtual void Slot61_ab4380();
    virtual void Slot62_ab4380();
    virtual void Slot63_ab4380();
    virtual void Slot64_ab4380();
    virtual void Slot65_ab4380();
    virtual void Slot66_ab4380();
    virtual void Slot67_ab4380();
    virtual void Slot68_ab4380();
    virtual void Slot69_ab4380();
    virtual void Slot70_ab4380();
    virtual void Slot71_ab4380();
    virtual void Slot72_ab4380();
    virtual void Slot73_ab4380();
    virtual void Slot74_ab4380();
    virtual void Slot75_ab4380();
    virtual void Slot76_ab4380();
    virtual void Slot77_ab4380();
    virtual void Slot78_ab4380();
    virtual void Slot79_ab4380();
    virtual void Slot80_ab4380();
    virtual void Slot81_ab4380();
    virtual void Slot82_ab4380();
    virtual bool Slot83_ab4380();
};

// The view utilities object a draw context points to.
struct SC4ViewUtilities_ab4380 {
    // STUB: 0x007f7750
    void GetVisibleEdges(int32_t*, int32_t*);
};

// The draw context's methods this file calls (still the original's).
struct DrawContext_ab4380 {
    // STUB: 0x007d2970
    void SetVertexBuffer(uint32_t, uint32_t, void*);
    // STUB: 0x007d2980
    void SetIndexBuffer(uint32_t, const uint16_t*);
    // STUB: 0x007d29c0
    void DrawPrimsIndexed(uint32_t, int32_t, int32_t);
    // STUB: 0x007d4010
    void EnableBlendStateFlag(bool);
    // STUB: 0x007d28f0
    void SetBlendFunc(int32_t, int32_t);
    // STUB: 0x007d40b0
    void SetTexEnvMode(int32_t, int32_t);
    // STUB: 0x007d4070
    void SetTexture(uint32_t, uint32_t);
    // STUB: 0x007d28a0
    void SetDepthFunc(int32_t);
};

// A list node as the STL's circular list lays it out.
struct ListNode_ab4380 {
    ListNode_ab4380* next;
    ListNode_ab4380* prev;
};

// A list handle: a value and the list's head node.
struct ListHandle_ab4380 {
    uint32_t value;
    ListNode_ab4380* head;
};

// STUB: 0x0090cf63
void Fn0090cf63(void* pBlock);

#ifdef OB_DRAFTS
// CLOSE: 0x00755dd0 score 86
void Record_ab4380::Fn00755dd0()
{
    float* f = reinterpret_cast<float*>(m);
    f[0] = gfB4c7c0;
    f[1] = gfB4c7c0;
    f[2] = gfB4c7c0;
    f[4] = 0.0f;
    f[5] = 0.0f;
    f[6] = 0.0f;
    f[7] = 0.0f;
    f[8] = gfB4c7c0;
    f[9] = gfB4c7c0;
    f[10] = gfB4c7c0;
    f[12] = 0.0f;
    f[13] = 0.0f;
    f[14] = 0.0f;
    f[15] = 0.0f;
    f[16] = gfB4c7c0;
    f[17] = gfB4c7c0;
    f[18] = gfB4c7c0;
    f[20] = 0.0f;
    f[21] = 0.0f;
    f[22] = 0.0f;
    f[23] = 0.0f;
    f[24] = gfB4c7c0;
    f[25] = gfB4c7c0;
    f[26] = gfB4c7c0;
    f[28] = 0.0f;
    f[29] = 0.0f;
    f[30] = 0.0f;
    f[31] = 0.0f;
}
#endif

// FUNCTION: 0x00752100
bool cSTETerrainView3D::DrawTextureLessTerrainSurface(void* pContext)
{
    DrawContext_ab4380* pDraw = static_cast<DrawContext_ab4380*>(pContext);
    for (int32_t row = mnFirstRow; row < mnEndRow; ++row) {
        if (gpB4c6d0[row] != 0 || gpB4c6d0[row + 1] != 0) {
            pDraw->SetVertexBuffer(0xb, gnB4c74c * 2, gpB4c758 + gnB4c74c * row * 0x20);
            pDraw->SetIndexBuffer(gnB4c700, gpB4c6f4 + gnB4c700 * row);
            int32_t first = gpB4c6d8List[row];
            int32_t count = gpB4c6d4List[row] - first - 1;
            pDraw->DrawPrimsIndexed(0, first * 6, count * 6);
        }
    }
    return true;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00755ed0 score 38
void Fn00755ed0(int32_t first, int32_t last)
{
    for (int32_t i = first; i <= last; ++i) {
        int32_t index = gnB4c7f0 + i;
        uint32_t* pWord = gpB4c7ec + index / 32;
        int32_t bit = index % 32;
        if (bit < 0) {
            bit += 32;
            --pWord;
        }
        *pWord |= 1u << bit;
    }
}
#endif

// FUNCTION: 0x007599b0
void Fn007599b0(ListHandle_ab4380* pFirst, ListHandle_ab4380* pLast)
{
    for (; pFirst != pLast; ++pFirst) {
        ListNode_ab4380* pNode = pFirst->head->next;
        while (pNode != pFirst->head) {
            ListNode_ab4380* pCurrent = pNode;
            pNode = pNode->next;
            Fn0090cf63(pCurrent);
        }
        pFirst->head->next = pFirst->head;
        pFirst->head->prev = pFirst->head;
        if (pFirst->head) {
            Fn0090cf63(pFirst->head);
        }
    }
}

// FUNCTION: 0x00752e30
Record_ab4380* Fn00752e30(const Record_ab4380* pFirst, const Record_ab4380* pLast, Record_ab4380* pDest)
{
    for (int32_t count = pLast - pFirst; count > 0; --count) {
        *pDest = *pFirst;
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

// FUNCTION: 0x00752de0
Record_ab4380* Fn00752de0(const Record_ab4380* pFirst, const Record_ab4380* pLast, Record_ab4380* pDest)
{
    for (int32_t count = pLast - pFirst; count > 0; --count) {
        --pLast;
        --pDest;
        *pDest = *pLast;
    }
    return pDest;
}

// FUNCTION: 0x00752d10
Record_ab4380& Record_ab4380::operator=(const Record_ab4380& other)
{
    m[0] = other.m[0];
    m[1] = other.m[1];
    m[2] = other.m[2];
    m[3] = other.m[3];
    m[4] = other.m[4];
    m[5] = other.m[5];
    m[6] = other.m[6];
    m[7] = other.m[7];
    m[8] = other.m[8];
    m[9] = other.m[9];
    m[10] = other.m[10];
    m[11] = other.m[11];
    m[12] = other.m[12];
    m[13] = other.m[13];
    m[14] = other.m[14];
    m[15] = other.m[15];
    m[16] = other.m[16];
    m[17] = other.m[17];
    m[18] = other.m[18];
    m[19] = other.m[19];
    m[20] = other.m[20];
    m[21] = other.m[21];
    m[22] = other.m[22];
    m[23] = other.m[23];
    m[24] = other.m[24];
    m[25] = other.m[25];
    m[26] = other.m[26];
    m[27] = other.m[27];
    m[28] = other.m[28];
    m[29] = other.m[29];
    m[30] = other.m[30];
    m[31] = other.m[31];
    return *this;
}

// FUNCTION: 0x007572a0
void cSTETerrainView3D::DrawWaterLayers(void* pContext, void* pExtension)
{
    if (!gbB4bc5c) {
        if (static_cast<Terrain_ab4380*>(mpTerrain)->Slot83_ab4380() && gbB0d718) {
            if (!mbWaterColorReady) {
                SetColorOfWaterSurface();
            }
            DrawWaterBox(pContext);
            DrawWaterSurface(pContext, pExtension);
        }
    }
}

// FUNCTION: 0x00756750
void cSTETerrainView3D::ComputeDrawFrustumOptimizationInfo(void* pContext)
{
    SC4ViewUtilities_ab4380* pUtilities = *reinterpret_cast<SC4ViewUtilities_ab4380**>(static_cast<uint8_t*>(pContext) + 0x24);
    ComputeDrawRectsForDrawFrustum(pContext);
    int32_t* pEdgeB = &mnEdgeB;
    int32_t* pEdgeA = &mnEdgeA;
    pUtilities->GetVisibleEdges(pEdgeA, pEdgeB);
    *pEdgeA = (6 - *pEdgeA) % 4;
    *pEdgeB = (6 - *pEdgeB) % 4;
    ComputeHeightBasedCullingInfoForDrawFrustum(pContext);
}

// ---- batch 3 ----

// The buffered vertex-extension object a draw call goes through.
struct VertBufExtn_ab4380 {
    // STUB: 0x0075c9f0
    void CreateBuffer();
    // STUB: 0x0075cb50
    void DrawPrimsIndexedUsingVertBuf(int32_t, int32_t, int32_t);
    // STUB: 0x0075cad0
    void FlushBuffer();
    // STUB: 0x0075cab0
    void SetIndexBuffer(const uint16_t*, bool);
};

// FUNCTION: 0x007521c0
bool cSTETerrainView3D::Fn007521c0(void* pExtension)
{
    VertBufExtn_ab4380* pExtn = static_cast<VertBufExtn_ab4380*>(pExtension);
    pExtn->CreateBuffer();
    for (int32_t row = mnFirstRow; row < mnEndRow; ++row) {
        if (gpB4c6d0[row] != 0 || gpB4c6d0[row + 1] != 0) {
            int32_t last = gpB4c6d4List[row] - 1;
            int32_t first = gpB4c6d8List[row];
            if (last > first) {
                pExtn->DrawPrimsIndexedUsingVertBuf(row, first, last);
            }
        }
    }
    pExtn->FlushBuffer();
    return true;
}

// A list of lists, as the STL lays it out: the handle's first word is the head node.
struct OuterNode_ab4380 {
    OuterNode_ab4380* next;
    OuterNode_ab4380* prev;
    uint32_t value;
    ListNode_ab4380* inner;
};
struct OuterList_ab4380 {
    OuterNode_ab4380* head;
    // STUB: 0x007598a0
    void Clear();
};

#ifdef OB_DRAFTS
// CLOSE: 0x007598a0 score 50
void OuterList_ab4380::Clear()
{
    OuterNode_ab4380* pNode = head->next;
    while (pNode != head) {
        OuterNode_ab4380* pCurrent = pNode;
        ListNode_ab4380* pInner = pCurrent->inner->next;
        pNode = pNode->next;
        while (pInner != pCurrent->inner) {
            ListNode_ab4380* pDead = pInner;
            pInner = pInner->next;
            Fn0090cf63(pDead);
        }
        pCurrent->inner->next = pCurrent->inner;
        pCurrent->inner->prev = pCurrent->inner;
        if (pCurrent->inner) {
            Fn0090cf63(pCurrent->inner);
        }
        Fn0090cf63(pCurrent);
    }
    head->next = head;
    head->prev = head;
}
#endif

// ---- batch 4 (STL list plumbing, drafts) ----

// STUB: 0x0090cf54
void* Fn0090cf54(uint32_t size);
// STUB: 0x004665c0
void Fn004665c0(int32_t* pDest, const int32_t* pSource);

// A std::list<double> handle: its head node.
struct DoubleList_ab4380 {
    ListNode_ab4380* head;
    // STUB: 0x0075ae00
    void Assign(const DoubleList_ab4380*);
    // STUB: 0x0075a9d0
    void InsertDispatch(ListNode_ab4380*, ListNode_ab4380*, ListNode_ab4380*, void*);
};

// A std::list<std::pair<int,int>> handle with its leading value (an 8-byte element).
struct PairList_ab4380 {
    int32_t value;
    ListNode_ab4380* head;
    // STUB: 0x00758e20
    void Assign(const PairList_ab4380*);
    // STUB: 0x00758700
    void InsertDispatch(ListNode_ab4380*, ListNode_ab4380*, ListNode_ab4380*, void*);
};

// FUNCTION: 0x0075af30
DoubleList_ab4380* Fn0075af30(const DoubleList_ab4380* pFirst, const DoubleList_ab4380* pLast, DoubleList_ab4380* pDest)
{
    for (int32_t count = pLast - pFirst; count > 0; --count) {
        pDest->Assign(pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}

// FUNCTION: 0x0075afd0
DoubleList_ab4380* Fn0075afd0(const DoubleList_ab4380* pFirst, const DoubleList_ab4380* pLast, DoubleList_ab4380* pDest)
{
    for (int32_t count = pLast - pFirst; count > 0; --count) {
        --pLast;
        --pDest;
        pDest->Assign(pLast);
    }
    return pDest;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0075af70 score 33
DoubleList_ab4380* Fn0075af70(DoubleList_ab4380* pDest, uint32_t count, const DoubleList_ab4380* pSource)
{
    for (; count != 0; --count) {
        if (pDest) {
            pDest->head = 0;
            ListNode_ab4380* pNode = static_cast<ListNode_ab4380*>(Fn0090cf54(0x10));
            pNode->next = pNode;
            pNode->prev = pNode;
            pDest->head = pNode;
            uint32_t tag = 0;
            pDest->InsertDispatch(pNode->next, pSource->head->next, pSource->head, &tag);
        }
        ++pDest;
    }
    return pDest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0075b170 score 39
DoubleList_ab4380* Fn0075b170(const DoubleList_ab4380* pFirst, const DoubleList_ab4380* pLast, DoubleList_ab4380* pDest)
{
    for (; pFirst != pLast; ++pFirst) {
        if (pDest) {
            pDest->head = 0;
            ListNode_ab4380* pNode = static_cast<ListNode_ab4380*>(Fn0090cf54(0x10));
            pNode->next = pNode;
            pNode->prev = pNode;
            pDest->head = pNode;
            uint32_t tag = 0;
            pDest->InsertDispatch(pNode->next, pFirst->head->next, pFirst->head, &tag);
        }
        ++pDest;
    }
    return pDest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0075a8f0 score 58
PairList_ab4380* Fn0075a8f0(const PairList_ab4380* pFirst, const PairList_ab4380* pLast, PairList_ab4380* pDest)
{
    for (; pFirst != pLast; ++pFirst) {
        if (pDest) {
            pDest->value = pFirst->value;
            pDest->head = 0;
            ListNode_ab4380* pNode = static_cast<ListNode_ab4380*>(Fn0090cf54(0x10));
            pNode->next = pNode;
            pNode->prev = pNode;
            pDest->head = pNode;
            uint32_t tag = 0;
            pDest->InsertDispatch(pNode->next, pFirst->head->next, pFirst->head, &tag);
        }
        ++pDest;
    }
    return pDest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0075a960 score 54
PairList_ab4380* Fn0075a960(PairList_ab4380* pDest, uint32_t count, const PairList_ab4380* pSource)
{
    for (; count != 0; --count) {
        if (pDest) {
            pDest->value = pSource->value;
            pDest->head = 0;
            ListNode_ab4380* pNode = static_cast<ListNode_ab4380*>(Fn0090cf54(0x10));
            pNode->next = pNode;
            pNode->prev = pNode;
            pDest->head = pNode;
            uint32_t tag = 0;
            pDest->InsertDispatch(pNode->next, pSource->head->next, pSource->head, &tag);
        }
        ++pDest;
    }
    return pDest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00759960 score 7
PairList_ab4380* Fn00759960(const PairList_ab4380* pFirst, const PairList_ab4380* pLast, PairList_ab4380* pDest)
{
    for (int32_t count = pLast - pFirst; count > 0; --count) {
        pDest->value = pFirst->value;
        pDest->Assign(pFirst);
        ++pFirst;
        ++pDest;
    }
    return pDest;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00759910 score 36
PairList_ab4380* Fn00759910(PairList_ab4380* pThis, const PairList_ab4380* pSource)
{
    pThis->value = pSource->value;
    pThis->head = 0;
    ListNode_ab4380* pNode = static_cast<ListNode_ab4380*>(Fn0090cf54(0x10));
    pNode->next = pNode;
    pNode->prev = pNode;
    pThis->head = pNode;
    uint32_t tag = 0;
    pThis->InsertDispatch(pNode->next, pSource->head->next, pSource->head, &tag);
    return pThis;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00759a10 score 65
void Fn00759a10(PairList_ab4380* pFirst, PairList_ab4380* pLast, PairList_ab4380** pOut)
{
    while (pFirst != pLast) {
        PairList_ab4380* pCurrent = pFirst;
        ListNode_ab4380* pLink = reinterpret_cast<ListNode_ab4380*>(pCurrent);
        pFirst = reinterpret_cast<PairList_ab4380*>(pLink->next);
        pLink->prev->next = pLink->next;
        pLink->next->prev = pLink->prev;
        ListNode_ab4380* pInner = reinterpret_cast<ListNode_ab4380**>(pCurrent)[3];
        ListNode_ab4380* pWalk = pInner->next;
        while (pWalk != pInner) {
            ListNode_ab4380* pDead = pWalk;
            pWalk = pWalk->next;
            Fn0090cf63(pDead);
        }
        pInner->next = pInner;
        pInner->prev = pInner;
        if (pInner) {
            Fn0090cf63(pInner);
        }
        Fn0090cf63(pCurrent);
    }
    *pOut = pLast;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00756000 score 42
void cSTETerrainView3D::SetWaterColorUpdateRect(void* pRect)
{
    int32_t rect[4];
    const int32_t* pSource = static_cast<const int32_t*>(pRect);
    if (pSource) {
        rect[0] = pSource[0];
        rect[1] = pSource[1];
        rect[2] = pSource[2];
        rect[3] = pSource[3];
    } else {
        rect[0] = 0;
        rect[1] = 0;
        rect[2] = gnB4c744;
        rect[3] = gnB4c748;
    }
    int32_t* pStored = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(this) + 0x4c);
    if (mbWaterColorReady) {
        mbWaterColorReady = false;
        pStored[0] = rect[0];
        pStored[1] = rect[1];
        pStored[2] = rect[2];
        pStored[3] = rect[3];
    } else {
        Fn004665c0(pStored, rect);
    }
}
#endif

// ---- batch 5 ----

// GLOBAL: 0x00b4c708
extern uint32_t gnB4c708;
// GLOBAL: 0x00b4c668
extern bool gbB4c668[5];
// GLOBAL: 0x00b4c670
extern void** gpB4c670[5];
// GLOBAL: 0x00b4bcd8
extern ListNode_ab4380* gpB4bcd8[];

// A texture binding (reference-counted by the renderer).
struct TextureBinding_ab4380 {
    // STUB: 0x008090e0
    void Release();
};

// A node of the used-texture list: the slot index sits at +8.
struct TextureNode_ab4380 {
    TextureNode_ab4380* next;
    TextureNode_ab4380* prev;
    uint32_t slot;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00756ca0 score 2
void Fn00756ca0Draft_ab4380()
{
    for (int32_t i = 0; i < 5; ++i) {
        if (gbB4c668[i]) {
            TextureNode_ab4380* pHead = reinterpret_cast<TextureNode_ab4380*>(gpB4bcd8[gnB0d6fc]);
            for (TextureNode_ab4380* pNode = pHead->next; pNode != pHead; pNode = pNode->next) {
                uint32_t slot = pNode->slot;
                TextureBinding_ab4380* pBinding = static_cast<TextureBinding_ab4380*>(gpB4c670[i][slot]);
                if (pBinding) {
                    pBinding->Release();
                    gpB4c670[i][slot] = 0;
                }
            }
        }
        gbB4c668[i] = false;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0075ae00 score 78
DoubleList_ab4380* Fn0075ae00Draft_ab4380(DoubleList_ab4380* pThis, const DoubleList_ab4380* pOther)
{
    if (pThis != pOther) {
        ListNode_ab4380* pEnd = pThis->head;
        ListNode_ab4380* pDest = pEnd->next;
        ListNode_ab4380* pSourceEnd = pOther->head;
        ListNode_ab4380* pSource = pSourceEnd->next;
        while (pDest != pEnd && pSource != pSourceEnd) {
            uint32_t* pDestWords = reinterpret_cast<uint32_t*>(pDest);
            const uint32_t* pSourceWords = reinterpret_cast<const uint32_t*>(pSource);
            pDestWords[2] = pSourceWords[2];
            reinterpret_cast<PairList_ab4380*>(pDestWords + 3)->Assign(reinterpret_cast<const PairList_ab4380*>(pSourceWords + 3));
            pDest = pDest->next;
            pSource = pSource->next;
        }
        if (pSource == pSourceEnd) {
            PairList_ab4380* pResult;
            Fn00759a10(reinterpret_cast<PairList_ab4380*>(pDest), reinterpret_cast<PairList_ab4380*>(pEnd), &pResult);
        } else {
            uint32_t tag = 0;
            reinterpret_cast<DoubleList_ab4380*>(pThis)->InsertDispatch(pEnd, pSource, pSourceEnd, &tag);
        }
    }
    return pThis;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x007566c0 score 47
void cSTETerrainView3D::Fn007566c0(void* pContext)
{
    gnB4c708 = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pContext) + 0x18);
    Slot13_ab4380(0);
    int32_t rect[4] = { 0, 0, static_cast<int32_t>(gnB4c744), static_cast<int32_t>(gnB4c748) };
    if (mbWaterColorReady) {
        int32_t* pStored = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(this) + 0x4c);
        pStored[0] = rect[0];
        pStored[1] = rect[1];
        pStored[2] = rect[2];
        pStored[3] = rect[3];
        mbWaterColorReady = false;
    } else {
        Fn004665c0(reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(this) + 0x4c), rect);
    }
    Fn00751c80(pContext);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00752730 score 24
bool cSTETerrainView3D::QueryInterface(unsigned int iid, void** ppOut)
{
    switch (iid) {
    case 0xc989f960:
    case 0xc9b84e10:
        *ppOut = this;
        break;
    case 0x6771477d:
        *ppOut = static_cast<cUnk00ab4380*>(this);
        break;
    case 0x452294aa:
        *ppOut = static_cast<cSTETerrainView3D_10*>(this);
        break;
    case 0xe4fda3d4:
        *ppOut = static_cast<cSTETerrainView3D_14*>(this);
        break;
    default:
        return cUnk0090da1e::QueryInterface(iid, ppOut);
    }
    AddRef();
    return true;
}
#endif

// ---- batch 6 ----

// GLOBAL: 0x00b4c698
extern uint32_t** gpB4c698[];
// GLOBAL: 0x00b4c8b4
extern uint8_t* gpB4c8b4;
// GLOBAL: 0x00b4c6cc
extern uint8_t* gpB4c6cc;

// FUNCTION: 0x00752240
bool cSTETerrainView3D::DrawWaterSurface(void* pContext, void* pExtension)
{
    DrawContext_ab4380* pDraw = static_cast<DrawContext_ab4380*>(pContext);
    VertBufExtn_ab4380* pExtn = static_cast<VertBufExtn_ab4380*>(pExtension);
    pDraw->EnableBlendStateFlag(true);
    pDraw->SetBlendFunc(4, 5);
    pDraw->SetTexEnvMode(1, 0);
    pDraw->SetTexture(**gpB4c698[gnB4c70c], 0);
    pDraw->SetDepthFunc(1);
    if (pExtn) {
        pExtn->CreateBuffer();
        gpB4c8b4 = gpB4c75c;
        pExtn->SetIndexBuffer(gpB4c6f4, true);
        for (int32_t row = mnWaterFirstRow; row < mnWaterEndRow; ++row) {
            if (gpB4c6cc[row] != 0 || gpB4c6cc[row + 1] != 0) {
                int32_t last = gpB4c6d4List[row] - 1;
                int32_t first = gpB4c6d8List[row];
                if (last > first) {
                    pExtn->DrawPrimsIndexedUsingVertBuf(row, first, last);
                }
            }
        }
        pExtn->FlushBuffer();
    } else {
        for (int32_t row = mnWaterFirstRow; row < mnWaterEndRow; ++row) {
            if (gpB4c6cc[row] != 0 || gpB4c6cc[row + 1] != 0) {
                int32_t count = (gpB4c6d4List[row] - gpB4c6d8List[row]) * 2 - 2;
                if (count > 0) {
                    pDraw->SetIndexBuffer(gnB4c700, gpB4c6f4 + gnB4c700 * row);
                    pDraw->SetVertexBuffer(0xb, gnB4c74c, gpB4c75c + gnB4c74c * row * 0x20);
                    pDraw->DrawPrimsIndexed(0, gpB4c6d8List[row] * 6, count * 3);
                }
            }
        }
    }
    pDraw->SetDepthFunc(3);
    pDraw->EnableBlendStateFlag(false);
    return true;
}

// ---- batch 7 ----

// GLOBAL: 0x00b4c6c8
extern int32_t* gpB4c6c8;
// GLOBAL: 0x00b4c6c4
extern int32_t* gpB4c6c4;

// The camera data a draw context points to (draw-frustum copy at 0x334, view copy at 0x180).
struct DrawCamera_ab4380 {
    uint8_t unknown0[0x180];
    float mViewA;
    float mViewB;
    float mViewC;
    float mViewD;
    uint8_t unknown190[0x334 - 0x190];
    float mDrawA;
    float mDrawB;
    float mDrawC;
    float mDrawD;
};

struct DrawContextCamera_ab4380 {
    uint8_t unknown0[0x24];
    DrawCamera_ab4380* mpCamera;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00751ee0 score 28
void cSTETerrainView3D::ComputeMinimumVisibleHtAtDrawRows(void* pContext, void* pResult)
{
    DrawCamera_ab4380* pCamera = static_cast<DrawContextCamera_ab4380*>(pContext)->mpCamera;
    float* pHeights = static_cast<float*>(pResult);
    float scale = -1.0f / pCamera->mDrawB;
    float a = pCamera->mDrawA;
    float c = pCamera->mDrawC;
    float d = pCamera->mDrawD;
    for (int32_t row = mnCullFirst; row < mnCullSecond; ++row) {
        pHeights[row] = 3.4028235e+38f;
        int32_t start = gpB4c6d8List[row];
        if (start < gpB4c6d4List[row]) {
            float rowTerm = static_cast<float>(row) * 16.0f * c;
            float low = (static_cast<float>(start) * 16.0f * a + rowTerm + d) * scale;
            pHeights[row] = low;
            int32_t end = gpB4c6d4List[row];
            if (0 < end) {
                float high = (static_cast<float>(end - 1) * 16.0f * a + rowTerm + d) * scale;
                if (high < low) {
                    pHeights[row] = high;
                }
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00751ff0 score 28
void cSTETerrainView3D::ComputeMinimumVisibleHtAtViewRows(void* pContext, void* pResult)
{
    DrawCamera_ab4380* pCamera = static_cast<DrawContextCamera_ab4380*>(pContext)->mpCamera;
    float* pHeights = static_cast<float*>(pResult);
    float scale = -1.0f / pCamera->mViewB;
    float a = pCamera->mViewA;
    float c = pCamera->mViewC;
    float d = pCamera->mViewD;
    for (int32_t row = mnViewFirstRow; row < mnViewEndRow; ++row) {
        pHeights[row] = 3.4028235e+38f;
        int32_t start = gpB4c6c8[row];
        if (start < gpB4c6c4[row]) {
            float rowTerm = static_cast<float>(row) * 16.0f * c;
            float low = (static_cast<float>(start) * 16.0f * a + rowTerm + d) * scale;
            pHeights[row] = low;
            int32_t end = gpB4c6c4[row];
            if (0 < end) {
                float high = (static_cast<float>(end - 1) * 16.0f * a + rowTerm + d) * scale;
                if (high < low) {
                    pHeights[row] = high;
                }
            }
        }
    }
}
#endif

// ---- batch 8 ----

// The terrain object at +0x20: its cell records (0x24 bytes each) are at +0x6c.
struct TerrainCells_ab4380 {
    uint8_t unknown0[0x6c];
    uint8_t* mpCells;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00752af0 score 226
void cSTETerrainView3D::SetTriangleIndicesForCell(int32_t row, int32_t col)
{
    uint16_t flags = *reinterpret_cast<uint16_t*>(static_cast<TerrainCells_ab4380*>(mpTerrain)->mpCells + 0x22 + (gnB4c74c * row + col) * 0x24);
    uint8_t bit6 = static_cast<uint8_t>(flags) >> 6 & 1;
    uint8_t bit9 = static_cast<uint8_t>(flags >> 9) & 1;
    uint8_t bit5 = static_cast<uint8_t>(flags) >> 5 & 1;
    int16_t* pIndices = reinterpret_cast<int16_t*>(gpB4c6f4 + (gnB4c700 * row + col * 6));
    int16_t c = static_cast<int16_t>(col);
    int16_t w = static_cast<int16_t>(gnB4c74c);
    if ((flags & 0x3000) == 0) {
        if (bit5 == 0) {
            if (bit9 == 0) {
                pIndices[0] = c;
                pIndices[1] = w + c;
                pIndices[2] = w + 1 + c;
            } else {
                pIndices[0] = w + 1 + c;
                pIndices[1] = w + c;
                pIndices[2] = c;
            }
        } else {
            pIndices[0] = c;
            pIndices[1] = c;
            pIndices[2] = c;
        }
        if (bit6 == 0) {
            if (bit9 != 0) {
                pIndices[3] = c + 1;
                pIndices[4] = w + 1 + c;
                pIndices[5] = c;
                return;
            }
            pIndices[3] = c;
            pIndices[4] = w + 1 + c;
            pIndices[5] = c + 1;
            return;
        }
    } else {
        if (bit5 == 0) {
            if (bit9 == 0) {
                pIndices[0] = c;
                pIndices[1] = w + c;
                pIndices[2] = c + 1;
            } else {
                pIndices[0] = c + 1;
                pIndices[1] = w + c;
                pIndices[2] = c;
            }
        } else {
            pIndices[0] = c;
            pIndices[1] = c;
            pIndices[2] = c;
        }
        if (bit6 == 0) {
            if (bit9 != 0) {
                pIndices[3] = w + 1 + c;
                pIndices[4] = w + c;
                pIndices[5] = c + 1;
                return;
            }
            pIndices[3] = c + 1;
            pIndices[4] = w + c;
            pIndices[5] = w + 1 + c;
            return;
        }
    }
    pIndices[3] = c;
    pIndices[4] = c;
    pIndices[5] = c;
}
#endif

// ---- batch 9 ----

// GLOBAL: 0x00b4c704
extern struct Loader_ab4380* gpB4c704;

// A loader object whose slot 6 fills a texture binding for an id (still the original's code).
struct OB_NOVTABLE Loader_ab4380 {
    virtual void QueryInterface();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab4380();
    virtual void Slot04_ab4380();
    virtual void Slot05_ab4380();
    virtual bool Slot06_ab4380(uint32_t*, void*);
};

#ifdef OB_DRAFTS
// CLOSE: 0x007571d0 score 44
void Fn007571d0Draft_ab4380(int32_t index)
{
    if ((-1 < index || index < 5) && !gbB4c668[index]) {
        ListNode_ab4380* pHead = gpB4bcd8[gnB0d6fc];
        uint32_t key[3] = { 0x7ab50e44, 0x891b0e1a, 0 };
        for (ListNode_ab4380* pNode = pHead->next; pNode != pHead; pNode = pNode->next) {
            int32_t slot = reinterpret_cast<int32_t*>(pNode)[2];
            key[2] = slot + index * 0x100;
            if (!gpB4c704->Slot06_ab4380(key, reinterpret_cast<uint8_t*>(gpB4c670[index]) + slot * 4)) {
                key[2] = slot;
                gpB4c704->Slot06_ab4380(key, reinterpret_cast<uint8_t*>(gpB4c670[index]) + slot * 4);
            }
        }
        gbB4c668[index] = true;
    }
}
#endif

// A node of a std::list of integer ranges.
struct RangeNode_ab4380 {
    RangeNode_ab4380* next;
    RangeNode_ab4380* prev;
    int32_t low;
    int32_t high;
};
struct RangeList_ab4380 {
    uint32_t unknown0;
    RangeNode_ab4380* head;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00758b10 score 85
void Fn00758b10Draft_ab4380(RangeList_ab4380* pList, const int32_t* pRange)
{
    int32_t low = pRange[0];
    int32_t high = pRange[1];
    RangeNode_ab4380* pHead = pList->head;
    RangeNode_ab4380* pNode = pHead->next;
    RangeNode_ab4380* pAt = pNode;
    if (pNode != pHead) {
        do {
            pAt = pNode;
            if (high < pNode->low) {
                break;
            }
            pAt = reinterpret_cast<RangeNode_ab4380*>(&pNode->high);
            if (pNode->high < low) {
                pAt = pNode->next;
            } else {
                if (pNode->low < low) {
                    low = pNode->low;
                }
                if (high < pNode->high) {
                    high = pNode->high;
                }
                RangeNode_ab4380* pNext = pNode->next;
                pNode->prev->next = pNext;
                pNext->prev = pNode->prev;
                pAt = pNext;
                Fn0090cf63(pNode);
            }
            pNode = pAt;
        } while (pAt != pList->head);
    }
    RangeNode_ab4380* pNew = static_cast<RangeNode_ab4380*>(Fn0090cf54(0x10));
    pNew->low = low;
    pNew->high = high;
    pNew->next = pAt;
    pNew->prev = pAt->prev;
    pAt->prev->next = pNew;
    pAt->prev = pNew;
}
#endif

// ---- batch 10 ----

// GLOBAL: 0x00b4c741
extern bool gbB4c741;

// A message: slot 4 answers its type, slot 14 its payload word.
struct OB_NOVTABLE Message_ab4380 {
    virtual void QueryInterface();
    virtual void AddRef();
    virtual void Release();
    virtual void Slot03_ab4380();
    virtual uint32_t Slot04_ab4380();
    virtual void Slot05_ab4380();
    virtual void Slot06_ab4380();
    virtual void Slot07_ab4380();
    virtual void Slot08_ab4380();
    virtual void Slot09_ab4380();
    virtual void Slot10_ab4380();
    virtual void Slot11_ab4380();
    virtual void Slot12_ab4380();
    virtual void Slot13_ab4380();
    virtual uint32_t Slot14_ab4380();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00757560 score 53
void cSTETerrainView3D_10::Slot03_ab4480_10(uint32_t message)
{
    cSTETerrainView3D* pView = static_cast<cSTETerrainView3D*>(this);
    Message_ab4380* pMessage = OB_PTR(Message_ab4380, message);
    uint32_t type = pMessage->Slot04_ab4380();
    uint32_t rect[4];
    switch (type) {
    case 0x678e6e3a:
        Fn007523f0(reinterpret_cast<Sized_ab4380*>(pMessage), rect);
        pView->ObtainWaterSurfaceInfo(rect);
        pView->mbRectDirty = true;
        return;
    case 0x278e6003:
        Fn007523f0(reinterpret_cast<Sized_ab4380*>(pMessage), rect);
        pView->Fn007569f0(rect);
        pView->mbRectDirty = true;
        return;
    case 0xa6b79601:
    case 0xa6b79611:
        pView->mbRectDirty = true;
        return;
    case 0x277a9364:
        pView->Slot21_ab4380(!gbB4c741);
        return;
    case 0xc9da96ea:
        pView->Slot13_ab4380(0);
        pView->SetWaterColorUpdateRect(0);
        pView->mnMessageValue = pMessage->Slot14_ab4380();
        return;
    default:
        return;
    }
}
#endif
