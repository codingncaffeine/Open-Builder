#include <stddef.h>
#include <new>

#include "classes/cGZBarGraph.h"

// The data of one series: a vector of floats (three words).
struct FloatVec_ade648 {
    float* mpBegin;
    float* mpEnd;
    float* mpCap;
    // STUB: 0x00496c50
    void push_back(const float& value);
    // STUB: 0x00802c00
    float* insert(float* position, const float& value);
    // STUB: 0x008d3333
    float* erase(float* position);
    // STUB: 0x00464430
    FloatVec_ade648& assign(const FloatVec_ade648& other);
    // STUB: 0x005c87a0
    void resize_names(uint32_t count);
};

// The information record of one series (0x28 bytes).
struct Series_ade648 {
    bool mbOutline;
    uint32_t mnOutlineColor;
    bool mbFill;
    uint32_t mnFillColor;
    void* mpPattern;
    uint8_t mName[0x14];
    // STUB: 0x009b9f6b
    void Assign(const Series_ade648& other);
};

// A pattern buffer (reference counted).
struct Pattern_ade648 {
    virtual void P00();
    virtual uint32_t AddRef();
    virtual uint32_t Release();
};

// The secondary base seen through the slots the class calls itself.
struct cSelf_ade648 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual uint32_t P20();
    virtual uint32_t P21();
    virtual uint32_t P22();
    virtual uint32_t P23();
    virtual int32_t GetLeftOfBar(uint32_t series, uint32_t bar);
};

#define OB_SERIES_ADE648 reinterpret_cast<Series_ade648*>(mpSeriesBegin)
#define OB_SERIES_COUNT_ADE648 static_cast<uint32_t>(reinterpret_cast<Series_ade648*>(mpSeriesEnd) - reinterpret_cast<Series_ade648*>(mpSeriesBegin))
#define OB_DATA_ADE648 reinterpret_cast<FloatVec_ade648*>(mpDataBegin)
#define OB_DATA_COUNT_ADE648 static_cast<uint32_t>(reinterpret_cast<FloatVec_ade648*>(mpDataEnd) - reinterpret_cast<FloatVec_ade648*>(mpDataBegin))

#ifdef OB_DRAFTS
// CLOSE: 0x009b2943 score 4
bool cGZBarGraph::QueryInterface(uint32_t iid, void** out)
{
    if (iid == 0x22cf2351) {
        *out = static_cast<cUnk00adde50*>(this);
        AddRef();
        return true;
    }
    return cGZGraph::QueryInterface(iid, out);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b297a score 12
void cGZBarGraph::Slot18_adde50(uint32_t value)
{
    float f = *reinterpret_cast<float*>(&value);
    if (f < 0.1f) {
        f = 0.1f;
    } else if (f > 1.0f) {
        f = 1.0f;
    }
    mfBarWidthPct = f;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b29ac score 22
void cGZBarGraph::Slot25_adde50(uint32_t series, uint32_t bar)
{
    int32_t left = reinterpret_cast<cSelf_ade648*>(static_cast<cUnk00adde50*>(this))->GetLeftOfBar(series, bar);
    static_cast<int32_t>(left + mfBarSpacing);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b29d0 score 24
void cGZBarGraph::Slot26_adde50(uint32_t series, uint32_t bar)
{
    int32_t left = reinterpret_cast<cSelf_ade648*>(static_cast<cUnk00adde50*>(this))->GetLeftOfBar(series, bar);
    static_cast<int32_t>(left + mfBarSpacing * 0.5f);
}
#endif

// FUNCTION: 0x009b29fc
void cGZBarGraph::DrawGraphData(uint32_t buffer)
{
    Slot32_adde50(buffer);
}

// FUNCTION: 0x009b2a0a
void cGZBarGraph::Slot14_addff8(uint32_t window)
{
    if (!window) {
        window = field68;
        if (!window) {
            return;
        }
    }
    Slot36_adde50();
    cGZGraph::Slot14_addff8(window);
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b4919 score 55
void cGZBarGraph::Slot15_adde50(uint32_t series, uint32_t color)
{
    if (series == 0xffffffff) {
        for (uint32_t i = 0; i < OB_SERIES_COUNT_ADE648; i++) {
            OB_SERIES_ADE648[i].mnFillColor = color;
        }
    } else if (series < OB_SERIES_COUNT_ADE648) {
        OB_SERIES_ADE648[series].mnFillColor = color;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b4975 score 65
void cGZBarGraph::Slot14_adde50(uint32_t outline, uint32_t fill, uint32_t series)
{
    if (series == 0xffffffff) {
        for (uint32_t i = 0; i < OB_SERIES_COUNT_ADE648; i++) {
            OB_SERIES_ADE648[i].mbOutline = outline;
            OB_SERIES_ADE648[i].mbFill = fill;
        }
    } else if (series < OB_SERIES_COUNT_ADE648) {
        OB_SERIES_ADE648[series].mbOutline = outline;
        OB_SERIES_ADE648[series].mbFill = fill;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b4a11 score 55
void cGZBarGraph::Slot16_adde50(uint32_t series, uint32_t color)
{
    if (series == 0xffffffff) {
        for (uint32_t i = 0; i < OB_SERIES_COUNT_ADE648; i++) {
            OB_SERIES_ADE648[i].mnOutlineColor = color;
        }
    } else if (series < OB_SERIES_COUNT_ADE648) {
        OB_SERIES_ADE648[series].mnOutlineColor = color;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b4a6d score 4
void cGZBarGraph::Slot17_adde50(uint32_t pattern, uint32_t series)
{
    if (series < OB_SERIES_COUNT_ADE648) {
        Pattern_ade648* p = OB_PTR(Pattern_ade648, pattern);
        if (p) {
            p->AddRef();
        }
        Pattern_ade648* old = static_cast<Pattern_ade648*>(OB_SERIES_ADE648[series].mpPattern);
        if (old) {
            old->Release();
        }
        OB_SERIES_ADE648[series].mpPattern = p;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b6222 score 26
void cGZBarGraph::Slot20_adde50(uint32_t pos, uint32_t series)
{
    uint32_t n = OB_DATA_COUNT_ADE648;
    if (series == 0xffffffff && n == 1) {
        series = 0;
    }
    if (series < n) {
        FloatVec_ade648* v = &OB_DATA_ADE648[series];
        v->erase(v->mpBegin + pos);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b6aae score 26
void cGZBarGraph::Slot21_adde50(uint32_t vec, uint32_t series)
{
    uint32_t n = OB_DATA_COUNT_ADE648;
    if (series == 0xffffffff && n == 1) {
        series = 0;
    }
    if (series < n) {
        OB_DATA_ADE648[series].assign(*OB_PTR(FloatVec_ade648, vec));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b8775 score 34
void cGZBarGraph::Slot19_adde50(uint32_t value, uint32_t series, uint32_t pos)
{
    uint32_t n = OB_DATA_COUNT_ADE648;
    if (series == 0xffffffff && n == 1) {
        series = 0;
    }
    if (series < n) {
        FloatVec_ade648* v = &OB_DATA_ADE648[series];
        if (pos == 0xffffffff) {
            v->push_back(*reinterpret_cast<float*>(&value));
        } else {
            v->insert(v->mpBegin + pos, *reinterpret_cast<float*>(&value));
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b87c8 score 34
void cGZBarGraph::Slot22_adde50(uint32_t value, uint32_t pos, uint32_t series)
{
    uint32_t n = OB_DATA_COUNT_ADE648;
    if (series == 0xffffffff && n == 1) {
        series = 0;
    }
    if (series < n) {
        FloatVec_ade648* v = &OB_DATA_ADE648[series];
        if (pos == 0xffffffff) {
            v->push_back(*reinterpret_cast<float*>(&value));
        } else {
            v->mpBegin[pos] = *reinterpret_cast<float*>(&value);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b8814 score 26
void cGZBarGraph::Slot23_adde50(uint32_t vec, uint32_t series)
{
    uint32_t n = OB_DATA_COUNT_ADE648;
    if (series == 0xffffffff && n == 1) {
        series = 0;
    }
    if (series < n) {
        FloatVec_ade648* src = OB_PTR(FloatVec_ade648, vec);
        FloatVec_ade648* v = &OB_DATA_ADE648[series];
        for (uint32_t i = 0; i < static_cast<uint32_t>(src->mpEnd - src->mpBegin); i++) {
            v->push_back(src->mpBegin[i]);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ba008 score 22
void cGZBarGraph::Slot09_adde50(uint32_t info, uint32_t series)
{
    if (series < OB_SERIES_COUNT_ADE648) {
        OB_SERIES_ADE648[series].Assign(*OB_PTR(Series_ade648, info));
    }
}
#endif

// FUNCTION: 0x009ba2f4
uint32_t cGZBarGraph::Slot39_adde50()
{
    return OB_ADDR(static_cast<cUnk00addff8*>(this));
}

// A text font (slots 37, 48 and 52 are measured and drawn through).
struct FontA_ade648 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual uint32_t P20();
    virtual uint32_t P21();
    virtual uint32_t P22();
    virtual uint32_t P23();
    virtual uint32_t P24();
    virtual uint32_t P25();
    virtual uint32_t P26();
    virtual uint32_t P27();
    virtual uint32_t P28();
    virtual uint32_t P29();
    virtual uint32_t P30();
    virtual uint32_t P31();
    virtual uint32_t P32();
    virtual uint32_t P33();
    virtual uint32_t P34();
    virtual uint32_t P35();
    virtual uint32_t P36();
    virtual int32_t Measure(uint32_t a, uint32_t b);
    virtual uint32_t P38();
    virtual uint32_t P39();
    virtual uint32_t P40();
    virtual uint32_t P41();
    virtual uint32_t P42();
    virtual uint32_t P43();
    virtual uint32_t P44();
    virtual uint32_t P45();
    virtual uint32_t P46();
    virtual uint32_t P47();
    virtual int32_t MeasureText(uint32_t begin, uint32_t length);
    virtual uint32_t P49();
    virtual uint32_t P50();
    virtual uint32_t P51();
    virtual void DrawText(uint32_t buffer, void* rect, uint32_t text, uint32_t length, uint32_t a, uint32_t b, uint32_t c);
};

// The same font reached through its longer draw call.
struct FontB_ade648 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual uint32_t P20();
    virtual uint32_t P21();
    virtual uint32_t P22();
    virtual uint32_t P23();
    virtual uint32_t P24();
    virtual uint32_t P25();
    virtual uint32_t P26();
    virtual uint32_t P27();
    virtual uint32_t P28();
    virtual uint32_t P29();
    virtual uint32_t P30();
    virtual uint32_t P31();
    virtual uint32_t P32();
    virtual uint32_t P33();
    virtual uint32_t P34();
    virtual uint32_t P35();
    virtual uint32_t P36();
    virtual uint32_t P37();
    virtual uint32_t P38();
    virtual uint32_t P39();
    virtual uint32_t P40();
    virtual uint32_t P41();
    virtual uint32_t P42();
    virtual uint32_t P43();
    virtual uint32_t P44();
    virtual uint32_t P45();
    virtual uint32_t P46();
    virtual uint32_t P47();
    virtual uint32_t P48();
    virtual uint32_t P49();
    virtual uint32_t P50();
    virtual uint32_t P51();
    virtual void DrawTextColored(uint32_t buffer, void* rect, uint32_t text, uint32_t length, uint32_t a, uint32_t color, uint32_t b, uint32_t c, uint32_t d);
};

// A category name: the string object's start and finish pointers.
struct Name_ade648 {
    void* mpVtable;
    char* mpStart;
    char* mpFinish;
    uint8_t mRest[0x8];
};

// The drawing buffer (lock, fill, unlock).
struct Buffer_ade648 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual bool Lock(uint32_t flags);
    virtual void Unlock(uint32_t flags);
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual void Fill(uint32_t color, const void* rect, uint32_t flags);
};

// The pattern image (width and height).
struct Image_ade648 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual uint32_t GetWidth();
    virtual uint32_t GetHeight();
};

// The drawing slots of the addff8 subobject.
struct DrawV_ade648 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual uint32_t P20();
    virtual uint32_t P21();
    virtual uint32_t P22();
    virtual uint32_t P23();
    virtual uint32_t P24();
    virtual uint32_t P25();
    virtual uint32_t P26();
    virtual uint32_t P27();
    virtual uint32_t P28();
    virtual uint32_t P29();
    virtual uint32_t P30();
    virtual uint32_t P31();
    virtual uint32_t P32();
    virtual uint32_t P33();
    virtual uint32_t P34();
    virtual uint32_t P35();
    virtual uint32_t P36();
    virtual uint32_t P37();
    virtual uint32_t P38();
    virtual uint32_t P39();
    virtual uint32_t P40();
    virtual uint32_t P41();
    virtual uint32_t P42();
    virtual void DrawLine(uint32_t buffer, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color, uint32_t width);
    virtual void DrawOutline(uint32_t buffer, void* rect, uint32_t color, uint32_t width);
};

// The primary slots the bar graph reads sizes through.
struct PrimV_ade648 {
    virtual uint32_t P00();
    virtual uint32_t P01();
    virtual uint32_t P02();
    virtual uint32_t P03();
    virtual uint32_t P04();
    virtual uint32_t P05();
    virtual uint32_t P06();
    virtual uint32_t P07();
    virtual uint32_t P08();
    virtual uint32_t P09();
    virtual uint32_t P10();
    virtual uint32_t P11();
    virtual uint32_t P12();
    virtual uint32_t P13();
    virtual uint32_t P14();
    virtual uint32_t P15();
    virtual uint32_t P16();
    virtual uint32_t P17();
    virtual uint32_t P18();
    virtual uint32_t P19();
    virtual uint32_t P20();
    virtual uint32_t P21();
    virtual uint32_t P22();
    virtual uint32_t P23();
    virtual uint32_t P24();
    virtual uint32_t P25();
    virtual uint32_t P26();
    virtual uint32_t P27();
    virtual uint32_t P28();
    virtual uint32_t P29();
    virtual uint32_t P30();
    virtual uint32_t P31();
    virtual uint32_t P32();
    virtual uint32_t P33();
    virtual uint32_t P34();
    virtual uint32_t P35();
    virtual uint32_t P36();
    virtual uint32_t P37();
    virtual uint32_t P38();
    virtual uint32_t P39();
    virtual uint32_t P40();
    virtual uint32_t P41();
    virtual uint32_t P42();
    virtual uint32_t P43();
    virtual uint32_t P44();
    virtual uint32_t P45();
    virtual uint32_t P46();
    virtual uint32_t P47();
    virtual uint32_t P48();
    virtual uint32_t P49();
    virtual uint32_t P50();
    virtual uint32_t P51();
    virtual uint32_t P52();
    virtual uint32_t P53();
    virtual uint32_t P54();
    virtual uint32_t P55();
    virtual uint32_t P56();
    virtual uint32_t P57();
    virtual uint32_t P58();
    virtual uint32_t P59();
    virtual uint32_t P60();
    virtual uint32_t P61();
    virtual uint32_t P62();
    virtual uint32_t P63();
    virtual uint32_t P64();
    virtual uint32_t P65();
    virtual uint32_t P66();
    virtual uint32_t P67();
    virtual uint32_t P68();
    virtual uint32_t P69();
    virtual uint32_t P70();
    virtual uint32_t P71();
    virtual uint32_t P72();
    virtual uint32_t P73();
    virtual uint32_t P74();
    virtual uint32_t P75();
    virtual uint32_t P76();
    virtual uint32_t P77();
    virtual uint32_t P78();
    virtual uint32_t P79();
    virtual uint32_t P80();
    virtual uint32_t P81();
    virtual uint32_t P82();
    virtual uint32_t P83();
    virtual uint32_t P84();
    virtual uint32_t P85();
    virtual uint32_t P86();
    virtual uint32_t P87();
    virtual uint32_t P88();
    virtual uint32_t P89();
    virtual uint32_t P90();
    virtual uint32_t P91();
    virtual uint32_t P92();
    virtual uint32_t P93();
    virtual uint32_t P94();
    virtual uint32_t P95();
    virtual uint32_t P96();
    virtual uint32_t P97();
    virtual uint32_t P98();
    virtual uint32_t P99();
    virtual uint32_t P100();
    virtual uint32_t P101();
    virtual uint32_t P102();
    virtual uint32_t P103();
    virtual uint32_t P104();
    virtual uint32_t P105();
    virtual uint32_t P106();
    virtual uint32_t P107();
    virtual uint32_t P108();
    virtual uint32_t P109();
    virtual uint32_t P110();
    virtual uint32_t P111();
    virtual uint32_t P112();
    virtual uint32_t P113();
    virtual uint32_t P114();
    virtual uint32_t P115();
    virtual uint32_t P116();
    virtual uint32_t P117();
    virtual uint32_t P118();
    virtual uint32_t P119();
    virtual uint32_t P120();
    virtual uint32_t P121();
    virtual uint32_t P122();
    virtual uint32_t P123();
    virtual uint32_t P124();
    virtual uint32_t P125();
    virtual uint32_t P126();
    virtual uint32_t P127();
    virtual uint32_t P128();
    virtual uint32_t P129();
    virtual uint32_t P130();
    virtual uint32_t P131();
    virtual uint32_t P132();
    virtual uint32_t P133();
    virtual uint32_t P134();
    virtual uint32_t P135();
    virtual uint32_t P136();
    virtual uint32_t P137();
    virtual uint32_t P138();
    virtual uint32_t P139();
    virtual uint32_t P140();
    virtual uint32_t P141();
    virtual uint32_t P142();
    virtual uint32_t P143();
    virtual uint32_t P144();
    virtual uint32_t P145();
    virtual uint32_t P146();
    virtual uint32_t P147();
    virtual uint32_t P148();
    virtual uint32_t P149();
    virtual uint32_t P150();
    virtual uint32_t P151();
    virtual uint32_t P152();
    virtual uint32_t P153();
    virtual uint32_t P154();
    virtual uint32_t P155();
    virtual uint32_t P156();
    virtual uint32_t P157();
    virtual uint32_t P158();
    virtual uint32_t P159();
    virtual int32_t PositionOf(uint32_t vertical, float value, bool flag);
    virtual uint32_t P161();
    virtual int32_t ScaleOf(uint32_t vertical, float value);
};

// A growing array of words (the original's local vector of lengths).
struct UIntVec_ade648 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x007ebd30
    void push_back(const uint32_t& value);
};

// STUB: 0x0090cf63
void StlDelete_ade648(void* p);

// STUB: 0x008d8bc0
void DrawTiled_ade648(uint32_t buffer, void* pattern, const void* source, const void* dest, uint32_t a, uint32_t b, uint32_t c);

#ifdef OB_DRAFTS
// CLOSE: 0x009b8f82 score 130
float cGZBarGraph::Slot164_ade188(uint32_t axis)
{
    float best = -3.4028235e+38f;
    uint32_t n;
    if (mnLayoutMode == 0) {
        if (mpDataBegin == mpDataEnd) {
            return 0.0f;
        }
        n = OB_DATA_COUNT_ADE648;
        UIntVec_ade648 lengths;
        lengths.mpBegin = 0;
        lengths.mpEnd = 0;
        lengths.mpCap = 0;
        uint32_t maxLen = 0;
        for (uint32_t i = 0; i < n; i++) {
            uint32_t len = static_cast<uint32_t>(OB_DATA_ADE648[i].mpEnd - OB_DATA_ADE648[i].mpBegin);
            lengths.push_back(len);
            if (len > maxLen) {
                maxLen = len;
            }
        }
        for (uint32_t bar = 0; bar < maxLen; bar++) {
            float sum = 0.0f;
            for (uint32_t s = 0; s < n; s++) {
                if (bar < lengths.mpBegin[s]) {
                    float v = OB_DATA_ADE648[s].mpBegin[bar];
                    if (v > 0.0f) {
                        sum += v;
                    }
                }
            }
            if (sum > best) {
                best = sum;
            }
        }
        if (lengths.mpBegin) {
            StlDelete_ade648(lengths.mpBegin);
        }
    } else {
        n = OB_DATA_COUNT_ADE648;
        for (uint32_t s = 0; s < n; s++) {
            for (float* p = OB_DATA_ADE648[s].mpBegin; p != OB_DATA_ADE648[s].mpEnd; p++) {
                if (*p > best) {
                    best = *p;
                }
            }
        }
    }
    return best;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b90d4 score 130
float cGZBarGraph::Slot165_ade188(uint32_t axis)
{
    float best = 3.4028235e+38f;
    uint32_t n;
    if (mnLayoutMode == 0) {
        if (mpDataBegin == mpDataEnd) {
            return 0.0f;
        }
        n = OB_DATA_COUNT_ADE648;
        UIntVec_ade648 lengths;
        lengths.mpBegin = 0;
        lengths.mpEnd = 0;
        lengths.mpCap = 0;
        uint32_t maxLen = 0;
        for (uint32_t i = 0; i < n; i++) {
            uint32_t len = static_cast<uint32_t>(OB_DATA_ADE648[i].mpEnd - OB_DATA_ADE648[i].mpBegin);
            lengths.push_back(len);
            if (len > maxLen) {
                maxLen = len;
            }
        }
        for (uint32_t bar = 0; bar < maxLen; bar++) {
            float sum = 0.0f;
            for (uint32_t s = 0; s < n; s++) {
                if (bar < lengths.mpBegin[s]) {
                    float v = OB_DATA_ADE648[s].mpBegin[bar];
                    if (v < 0.0f) {
                        sum += v;
                    }
                }
            }
            if (sum < best) {
                best = sum;
            }
        }
        if (lengths.mpBegin) {
            StlDelete_ade648(lengths.mpBegin);
        }
    } else {
        n = OB_DATA_COUNT_ADE648;
        for (uint32_t s = 0; s < n; s++) {
            for (float* p = OB_DATA_ADE648[s].mpBegin; p != OB_DATA_ADE648[s].mpEnd; p++) {
                if (*p < best) {
                    best = *p;
                }
            }
        }
    }
    return best;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b54c5 score 108
void cGZBarGraph::Slot33_adde50(uint32_t buffer, uint32_t rect, uint32_t series, uint32_t flag)
{
    Series_ade648* s = &OB_SERIES_ADE648[series];
    Buffer_ade648* buf = OB_PTR(Buffer_ade648, buffer);
    if (s->mpPattern) {
        if (buf->Lock(0x8010)) {
            Image_ade648* image = static_cast<Image_ade648*>(s->mpPattern);
            int32_t source[4];
            source[0] = 0;
            source[1] = 0;
            source[3] = image->GetWidth();
            source[2] = image->GetHeight();
            DrawTiled_ade648(buffer, s->mpPattern, source, OB_PTR(void, rect), 0, 0, 0);
            buf->Unlock(0x8010);
        }
    } else if (s->mbFill) {
        if (buf->Lock(0x8001)) {
            buf->Fill(s->mnFillColor, OB_PTR(void, rect), 0);
            buf->Unlock(0x8001);
        }
    }
    if (s->mbOutline) {
        if (buf->Lock(0x8008)) {
            reinterpret_cast<DrawV_ade648*>(static_cast<cUnk00addff8*>(this))->DrawOutline(buffer, OB_PTR(void, rect), s->mnOutlineColor, 1);
            buf->Unlock(0x8008);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b528e score 51
void cGZBarGraph::Slot37_adde50()
{
    float width;
    if (mnLayoutMode == 0) {
        width = static_cast<float>(static_cast<uint32_t>(mnGraphArea[2] - mnGraphArea[0]));
    } else if (mnLayoutMode == 1) {
        uint32_t extent = mnGraphArea[2] - mnGraphArea[0];
        uint32_t n = OB_DATA_COUNT_ADE648;
        if (n) {
            width = static_cast<float>(extent) * mfBarWidthPct / static_cast<float>(n);
        } else {
            width = static_cast<float>(extent);
        }
    } else {
        width = static_cast<float>(static_cast<uint32_t>(mnGraphArea[2] - mnGraphArea[0]));
    }
    static_cast<int32_t>(width);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b5319 score 201
void cGZBarGraph::Slot36_adde50()
{
    uint32_t extent;
    uint32_t count;
    float spacing;
    if (mnHorizontal == 0) {
        extent = mnGraphArea[2] - mnGraphArea[0];
    } else {
        extent = mnGraphArea[3] - mnGraphArea[1];
    }
    FloatVec_ade648* d = OB_DATA_ADE648;
    if (mnLayoutMode == 0) {
        if (d == reinterpret_cast<FloatVec_ade648*>(mpDataEnd) || d->mpBegin == d->mpEnd) {
            count = 1;
            spacing = 0.0f;
        } else {
            count = static_cast<uint32_t>(d->mpEnd - d->mpBegin);
            spacing = static_cast<float>(extent) * mfBarWidthPct / static_cast<float>(count);
        }
        mfBarSpacing = spacing;
        mfBarWidth = (static_cast<float>(extent) - static_cast<float>(count) * mfBarSpacing) / static_cast<float>(count + 1);
    } else if (mnLayoutMode == 1) {
        if (d == reinterpret_cast<FloatVec_ade648*>(mpDataEnd) || d->mpBegin == d->mpEnd) {
            count = 1;
            spacing = 0.0f;
        } else {
            count = static_cast<uint32_t>(d->mpEnd - d->mpBegin);
            uint32_t series = OB_DATA_COUNT_ADE648;
            spacing = static_cast<float>(extent) * mfBarWidthPct / static_cast<float>(series * count);
        }
        mfBarSpacing = spacing;
        uint32_t series2 = OB_DATA_COUNT_ADE648;
        mfBarWidth = (static_cast<float>(extent) - static_cast<float>(count) * static_cast<float>(series2) * mfBarSpacing) / static_cast<float>(count + 1);
    }
}
#endif

// A rectangle with the one operation the bar graph needs.
struct Rect_ade648 {
    int32_t v[4];
    // STUB: 0x005dc980
    void Union(const Rect_ade648* other);
    // STUB: 0x0094bd38
    bool Contains(const void* point);
};

// A series name (reference to the original string object).
struct StdString_ade648 {
    // STUB: 0x004425c0
    void erase(uint32_t position, uint32_t count);
};

// The stored bar the pointer is over.
struct Hit_ade648 {
    uint32_t mnKind;
    uint32_t mnSeries;
    uint32_t mnBar;
};

#ifdef OB_DRAFTS
// CLOSE: 0x009b4ab8 score 111
void cGZBarGraph::Slot24_adde50(uint32_t series, uint32_t bar)
{
    float f;
    if (mpDataBegin != mpDataEnd) {
        if (mnLayoutMode == 0) {
            f = static_cast<float>(bar + 1) * mfBarWidth;
            f = f + static_cast<float>(series) * mfBarSpacing;
        } else if (mnLayoutMode == 1) {
            uint32_t count = OB_DATA_COUNT_ADE648;
            f = static_cast<float>(bar + 1) * mfBarWidth * static_cast<float>(count);
            f = f + static_cast<float>(series) * mfBarSpacing;
        } else {
            f = mfBarWidth;
            static_cast<int32_t>(f);
            return;
        }
        f = f + static_cast<float>(mnHorizontal ? mnGraphArea[1] : mnGraphArea[0]);
        static_cast<int32_t>(f);
        return;
    }
    static_cast<int32_t>(mfBarWidth);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b4d9e score 25
bool cGZBarGraph::Slot28_adde50(uint32_t category, uint32_t rectArg)
{
    FloatVec_ade648* first = OB_DATA_ADE648;
    if (mpDataBegin != mpDataEnd && category < static_cast<uint32_t>(first->mpEnd - first->mpBegin)) {
        uint32_t n = OB_DATA_COUNT_ADE648;
        for (uint32_t i = 0; i < n; i++) {
            if (i == 0) {
                Slot27_adde50(category, i, rectArg);
            } else {
                Rect_ade648 tmp;
                Slot27_adde50(category, i, OB_ADDR(&tmp));
                OB_PTR(Rect_ade648, rectArg)->Union(&tmp);
            }
        }
        return true;
    }
    Rect_ade648* r = OB_PTR(Rect_ade648, rectArg);
    r->v[0] = 0;
    r->v[1] = 0;
    r->v[2] = 0;
    r->v[3] = 0;
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b4bfe score 169
bool cGZBarGraph::Slot27_adde50(uint32_t series, uint32_t bar, uint32_t rectArg)
{
    uint32_t n = OB_DATA_COUNT_ADE648;
    Rect_ade648* r = OB_PTR(Rect_ade648, rectArg);
    if (bar < n) {
        FloatVec_ade648* vec = &OB_DATA_ADE648[bar];
        if (series < static_cast<uint32_t>(vec->mpEnd - vec->mpBegin)) {
            bool vertical = mnHorizontal == 0;
            int32_t left = reinterpret_cast<cSelf_ade648*>(static_cast<cUnk00adde50*>(this))->GetLeftOfBar(series, bar);
            int32_t right = static_cast<int32_t>(left + mfBarWidth);
            int32_t top;
            int32_t bottom;
            PrimV_ade648* prim = reinterpret_cast<PrimV_ade648*>(static_cast<cGZGraph*>(this));
            if (mnLayoutMode == 0) {
                top = mnGraphArea[vertical ? 3 : 2];
                bottom = top;
                for (uint32_t i = 0; i <= bar; i++) {
                    float v = OB_DATA_ADE648[i].mpBegin[series];
                    if (v > 0.0f) {
                        top -= prim->ScaleOf(vertical, v);
                    } else if (v < 0.0f) {
                        bottom -= prim->ScaleOf(vertical, v);
                    }
                }
            } else {
                float v = vec->mpBegin[series];
                top = mnGraphArea[vertical ? 3 : 2];
                bottom = top;
                if (v > 0.0f) {
                    top -= prim->PositionOf(vertical, v, true);
                } else {
                    bottom -= prim->PositionOf(vertical, v, true);
                }
            }
            if (mnHorizontal == 0) {
                r->v[0] = left;
                r->v[1] = top;
                r->v[2] = right;
                r->v[3] = bottom;
            } else {
                r->v[0] = top;
                r->v[1] = left;
                r->v[2] = bottom;
                r->v[3] = right;
            }
            return true;
        }
    }
    r->v[0] = 0;
    r->v[1] = 0;
    r->v[2] = 0;
    r->v[3] = 0;
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b4e24 score 16
bool cGZBarGraph::Slot40_addff8(uint32_t point, uint32_t outKind)
{
    uint32_t n = OB_DATA_COUNT_ADE648;
    for (uint32_t i = 0; i < n; i++) {
        uint32_t count = static_cast<uint32_t>(OB_DATA_ADE648[i].mpEnd - OB_DATA_ADE648[i].mpBegin);
        for (uint32_t j = 0; j < count; j++) {
            Rect_ade648 r;
            Slot27_adde50(j, i, OB_ADDR(&r));
            if (r.Contains(OB_PTR(void, point))) {
                Slot41_addff8(0xc);
                Hit_ade648* hit = static_cast<Hit_ade648*>(mpHitTestData);
                hit->mnSeries = i;
                hit->mnBar = j;
                *OB_PTR(uint32_t, outKind) = 0x3e9;
                return true;
            }
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b670d score 18
void cGZBarGraph::Slot13_adde50(uint32_t idx)
{
    if (idx == 0xffffffff) {
        idx = static_cast<uint32_t>(reinterpret_cast<Name_ade648*>(mpNamesEnd) - reinterpret_cast<Name_ade648*>(mpNamesBegin)) - 1;
    }
    if (idx < static_cast<uint32_t>(reinterpret_cast<Name_ade648*>(mpNamesEnd) - reinterpret_cast<Name_ade648*>(mpNamesBegin))) {
        reinterpret_cast<StdString_ade648*>(&reinterpret_cast<Name_ade648*>(mpNamesBegin)[idx].mpStart)->erase(0, 0xffffffff);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b9fa0 score 55
void cGZBarGraph::Slot08_adde50(uint32_t name, uint32_t series)
{
    if (series == 0xffffffff) {
        for (uint32_t i = 0; i < OB_SERIES_COUNT_ADE648; i++) {
            *reinterpret_cast<cRZString*>(OB_SERIES_ADE648[i].mName) = *OB_PTR(cRZString, name);
        }
    } else if (series < OB_SERIES_COUNT_ADE648) {
        *reinterpret_cast<cRZString*>(OB_SERIES_ADE648[series].mName) = *OB_PTR(cRZString, name);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bbeff score 2
void cGZBarGraph::Slot12_adde50(uint32_t name, uint32_t idx)
{
    if (idx == 0xffffffff) {
        idx = static_cast<uint32_t>(reinterpret_cast<cRZString*>(mpNamesEnd) - reinterpret_cast<cRZString*>(mpNamesBegin));
    }
    if (idx >= static_cast<uint32_t>(reinterpret_cast<cRZString*>(mpNamesEnd) - reinterpret_cast<cRZString*>(mpNamesBegin))) {
        FloatVec_ade648* names = reinterpret_cast<FloatVec_ade648*>(&mpNamesBegin);
        names->resize_names(idx + 1);
    }
    reinterpret_cast<cRZString*>(mpNamesBegin)[idx] = *OB_PTR(cRZString, name);
}
#endif

// The vector of data vectors and the vector of series records, as the original's container code sees them.
struct DataVecVec_ade648 {
    FloatVec_ade648* mpBegin;
    FloatVec_ade648* mpEnd;
    FloatVec_ade648* mpCap;
    // STUB: 0x009b95b2
    FloatVec_ade648* erase(FloatVec_ade648* position);
    // STUB: 0x009b9b4b
    void push_back(const FloatVec_ade648& value);
    // STUB: 0x009b9b83
    FloatVec_ade648* insert(FloatVec_ade648* position, const FloatVec_ade648& value);
    // STUB: 0x00464300
    void resize(uint32_t count);
};

struct SeriesVec_ade648 {
    Series_ade648* mpBegin;
    Series_ade648* mpEnd;
    Series_ade648* mpCap;
    // STUB: 0x009baf4d
    Series_ade648* erase(Series_ade648* position);
    // STUB: 0x009baba3
    void push_back(const Series_ade648& value);
    // STUB: 0x009baeaa
    Series_ade648* insert(Series_ade648* position, const Series_ade648& value);
    // STUB: 0x009bbd9f
    void resize(uint32_t count);
};

// A default-constructed series record.
struct SeriesInit_ade648 : public Series_ade648 {
    // STUB: 0x009b74ce
    SeriesInit_ade648* Init();
};

// STUB: 0x0045dd50
void DestroyData_ade648(FloatVec_ade648* v, uint32_t flag);

// STUB: 0x009be9af
void DestroySeries_ade648(Series_ade648* s, uint32_t flag);

// GLOBAL: 0x00bac074
extern Series_ade648* gpBac074;

#ifdef OB_DRAFTS
// CLOSE: 0x009bb57b score 42
void cGZBarGraph::Slot07_adde50(uint32_t idx)
{
    DataVecVec_ade648* data = reinterpret_cast<DataVecVec_ade648*>(&mpDataBegin);
    SeriesVec_ade648* series = reinterpret_cast<SeriesVec_ade648*>(&mpSeriesBegin);
    if (idx == 0xffffffff) {
        data->mpEnd = data->mpEnd - 1;
        DestroyData_ade648(data->mpEnd, 0);
        series->mpEnd = series->mpEnd - 1;
        DestroySeries_ade648(series->mpEnd, 0);
    } else if (idx < static_cast<uint32_t>(data->mpEnd - data->mpBegin)) {
        data->erase(&data->mpBegin[idx]);
        series->erase(&series->mpBegin[idx]);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bb4df score 31
void cGZBarGraph::Slot06_adde50(uint32_t idx)
{
    DataVecVec_ade648* data = reinterpret_cast<DataVecVec_ade648*>(&mpDataBegin);
    SeriesVec_ade648* series = reinterpret_cast<SeriesVec_ade648*>(&mpSeriesBegin);
    FloatVec_ade648 empty;
    if (idx == 0xffffffff) {
        empty.mpBegin = 0;
        empty.mpEnd = 0;
        empty.mpCap = 0;
        data->push_back(empty);
        SeriesInit_ade648 def;
        def.Init();
        series->push_back(def);
    } else if (idx < static_cast<uint32_t>(data->mpEnd - data->mpBegin)) {
        empty.mpBegin = 0;
        empty.mpEnd = 0;
        empty.mpCap = 0;
        data->insert(&data->mpBegin[idx], empty);
        SeriesInit_ade648 def;
        def.Init();
        series->insert(&series->mpBegin[idx], def);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bb5de score 25
void cGZBarGraph::Slot10_adde50(uint32_t info, uint32_t idx)
{
    SeriesVec_ade648* series = reinterpret_cast<SeriesVec_ade648*>(&mpSeriesBegin);
    if (idx == 0xffffffff) {
        series->push_back(*OB_PTR(Series_ade648, info));
    } else if (idx < static_cast<uint32_t>(series->mpEnd - series->mpBegin)) {
        series->insert(&series->mpBegin[idx], *OB_PTR(Series_ade648, info));
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bb620 score 31
void cGZBarGraph::Slot11_adde50(uint32_t idx)
{
    SeriesVec_ade648* series = reinterpret_cast<SeriesVec_ade648*>(&mpSeriesBegin);
    if (idx == 0xffffffff) {
        series->mpEnd = series->mpEnd - 1;
        DestroySeries_ade648(series->mpEnd, 0);
    } else if (idx < static_cast<uint32_t>(series->mpEnd - series->mpBegin)) {
        series->erase(&series->mpBegin[idx]);
    }
}
#endif

// FUNCTION: 0x009bbeaf
void cGZBarGraph::Slot05_adde50(uint32_t count)
{
    reinterpret_cast<DataVecVec_ade648*>(&mpDataBegin)->resize(count);
    SeriesVec_ade648* series = reinterpret_cast<SeriesVec_ade648*>(&mpSeriesBegin);
    series->resize(count);
    for (uint32_t i = 0; i < count; i++) {
        series->mpBegin[i].Assign(gpBac074[i & 7]);
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009b4ecc score 252
void cGZBarGraph::Slot155_ade188(uint32_t buffer, uint32_t flags)
{
    int32_t a[2];
    int32_t b[2];
    DrawV_ade648* draw = reinterpret_cast<DrawV_ade648*>(static_cast<cUnk00addff8*>(this));
    if (mnHorizontal == 0 && (flags & 2)) {
        cGZGraph::Slot155_ade188(buffer, 2);
    }
    if (mnHorizontal == 1 && (flags & 1)) {
        cGZGraph::Slot155_ade188(buffer, 1);
    }
    if (!mbMajorTickUsage[0] && !mbMinorTickUsage[0] && !mbMajorTickUsage[1] && !mbMinorTickUsage[1]) {
        return;
    }
    if (OB_DATA_COUNT_ADE648 == 0) {
        return;
    }
    Buffer_ade648* buf = OB_PTR(Buffer_ade648, buffer);
    if (!buf->Lock(0x8004)) {
        return;
    }
    if (mnHorizontal == 0 && (flags & 1)) {
        int32_t y0 = mnGraphArea[3];
        int32_t y1 = y0 + mnMajorTickLength[0];
        if (mbMajorTickGrid[0]) {
            y0 = mnGraphArea[1];
        }
        int32_t z0 = mnGraphArea[3];
        int32_t z1 = z0 + mnMinorTickLength[0];
        if (mbMinorTickGrid[0]) {
            z0 = mnGraphArea[1];
        }
        uint32_t n = static_cast<uint32_t>(OB_DATA_ADE648[0].mpEnd - OB_DATA_ADE648[0].mpBegin);
        for (uint32_t i = 0; i < n; i++) {
            int32_t x = reinterpret_cast<cSelf_ade648*>(static_cast<cUnk00adde50*>(this))->GetLeftOfBar(i, 0);
            if (mbMajorTickUsage[0]) {
                draw->DrawLine(buffer, x, y0, x, y1, mnTickColor, 1);
            }
            if (mbMinorTickUsage[0]) {
                draw->DrawLine(buffer, x, z0, x, z1, mnTickColor, 1);
            }
        }
    }
    if (mnHorizontal == 1 && (flags & 2)) {
        int32_t x0 = mnGraphArea[0];
        int32_t x1 = x0 - mnMajorTickLength[1];
        if (mbMajorTickGrid[1]) {
            x0 = mnGraphArea[2];
        }
        int32_t w0 = mnGraphArea[0];
        int32_t w1 = w0 - mnMinorTickLength[1];
        if (mbMinorTickGrid[1]) {
            w0 = mnGraphArea[2];
        }
        uint32_t n = static_cast<uint32_t>(OB_DATA_ADE648[0].mpEnd - OB_DATA_ADE648[0].mpBegin);
        for (uint32_t i = 0; i < n; i++) {
            int32_t y = reinterpret_cast<cSelf_ade648*>(static_cast<cUnk00adde50*>(this))->GetLeftOfBar(i, 0);
            if (mbMajorTickUsage[1]) {
                draw->DrawLine(buffer, x1, y, x0, y, mnTickColor, 1);
            }
            if (mbMinorTickUsage[1]) {
                draw->DrawLine(buffer, w1, y, w0, y, mnTickColor, 1);
            }
        }
    }
    buf->Unlock(0x8004);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b8c07 score 199
void cGZBarGraph::Slot156_ade188(uint32_t buffer, uint32_t flags)
{
    if (mnHorizontal == 0) {
        if ((flags & 2) && mbTickText[1]) {
            cGZGraph::Slot156_ade188(buffer, 2);
        }
        if ((flags & 1) && mbTickText[0] && OB_DATA_COUNT_ADE648 != 0 && mpAxisTickFont[0]) {
            FontA_ade648* font = static_cast<FontA_ade648*>(mpAxisTickFont[0]);
            uint32_t color = mnAxisTickFontColor[0];
            int32_t lineHeight = font->Measure(0, 0);
            int32_t offset = Slot169_ade188(0);
            uint32_t names = static_cast<uint32_t>(reinterpret_cast<Name_ade648*>(mpNamesEnd) - reinterpret_cast<Name_ade648*>(mpNamesBegin));
            uint32_t bars = static_cast<uint32_t>(OB_DATA_ADE648[0].mpEnd - OB_DATA_ADE648[0].mpBegin);
            uint32_t count = names <= bars ? names : bars;
            for (uint32_t i = 0; i < count; i++) {
                Name_ade648* name = &reinterpret_cast<Name_ade648*>(mpNamesBegin)[i];
                if (name->mpFinish != name->mpStart) {
                    int32_t rect[4];
                    Slot28_adde50(i, OB_ADDR(rect));
                    int32_t textWidth = font->MeasureText(OB_ADDR(name->mpStart), static_cast<uint32_t>(name->mpFinish - name->mpStart));
                    rect[1] = mnGraphArea[3] + offset;
                    rect[3] = rect[1] + lineHeight;
                    rect[0] = rect[0] - 1 + ((rect[2] - rect[0]) / 2 - textWidth / 2);
                    rect[2] = textWidth + 2 + rect[0];
                    if (color == 0x80000000) {
                        font->DrawText(buffer, rect, OB_ADDR(name->mpStart), static_cast<uint32_t>(name->mpFinish - name->mpStart), 1, 0x8000000, 0x8000000);
                    } else {
                        reinterpret_cast<FontB_ade648*>(font)->DrawTextColored(buffer, rect, OB_ADDR(name->mpStart), static_cast<uint32_t>(name->mpFinish - name->mpStart), 1, color, 0x8000000, 0, 0);
                    }
                }
            }
        }
    } else if (mnHorizontal == 1) {
        if ((flags & 1) && mbTickText[0]) {
            cGZGraph::Slot156_ade188(buffer, 1);
        }
        if ((flags & 2) && mbTickText[1] && OB_DATA_COUNT_ADE648 != 0 && mpAxisTickFont[1]) {
            FontA_ade648* font = static_cast<FontA_ade648*>(mpAxisTickFont[1]);
            uint32_t color = mnAxisTickFontColor[1];
            int32_t lineHeight = font->Measure(0, 0);
            int32_t offset = Slot169_ade188(1);
            uint32_t bars = static_cast<uint32_t>(OB_DATA_ADE648[0].mpEnd - OB_DATA_ADE648[0].mpBegin);
            uint32_t names = static_cast<uint32_t>(reinterpret_cast<Name_ade648*>(mpNamesEnd) - reinterpret_cast<Name_ade648*>(mpNamesBegin));
            uint32_t count = bars <= names ? bars : names;
            for (uint32_t i = 0; i < count; i++) {
                Name_ade648* name = &reinterpret_cast<Name_ade648*>(mpNamesBegin)[i];
                if (name->mpStart != name->mpFinish) {
                    int32_t rect[4];
                    Slot28_adde50(i, OB_ADDR(rect));
                    rect[0] = font->MeasureText(OB_ADDR(name->mpStart), static_cast<uint32_t>(name->mpFinish - name->mpStart));
                    rect[2] = mnGraphArea[0] - offset;
                    rect[0] = rect[2] - rect[0];
                    rect[1] = rect[1] + ((rect[3] - rect[1]) / 2 - lineHeight / 2);
                    rect[3] = rect[1] + 1 + lineHeight;
                    if (color == 0x80000000) {
                        font->DrawText(buffer, rect, OB_ADDR(name->mpStart), static_cast<uint32_t>(name->mpFinish - name->mpStart), 1, 0x8000000, 0x8000000);
                    } else {
                        reinterpret_cast<FontB_ade648*>(font)->DrawTextColored(buffer, rect, OB_ADDR(name->mpStart), static_cast<uint32_t>(name->mpFinish - name->mpStart), 1, color, 0x8000000, 0, 0);
                    }
                }
            }
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b8872 score 375
void cGZBarGraph::Slot32_adde50(uint32_t buffer)
{
    uint32_t vertical = mnHorizontal == 0;
    if (mpDataBegin == mpDataEnd) {
        return;
    }
    PrimV_ade648* prim = reinterpret_cast<PrimV_ade648*>(static_cast<cGZGraph*>(this));
    uint32_t n = OB_DATA_COUNT_ADE648;
    int32_t rect[4];
    if (mnLayoutMode == 0) {
        UIntVec_ade648 lengths;
        lengths.mpBegin = 0;
        lengths.mpEnd = 0;
        lengths.mpCap = 0;
        uint32_t maxLen = 0;
        for (uint32_t i = 0; i < n; i++) {
            uint32_t len = static_cast<uint32_t>(OB_DATA_ADE648[i].mpEnd - OB_DATA_ADE648[i].mpBegin);
            lengths.push_back(len);
            if (maxLen < len) {
                maxLen = len;
            }
        }
        float x0 = static_cast<float>(mnGraphArea[0]) + mfBarWidth;
        float x1 = x0 + mfBarSpacing;
        for (uint32_t bar = 0; bar < maxLen; bar++) {
            int32_t up = mnGraphArea[vertical ? 3 : 2];
            int32_t down = up;
            for (uint32_t s = 0; s < n; s++) {
                if (bar < lengths.mpBegin[s]) {
                    float v = OB_DATA_ADE648[s].mpBegin[bar];
                    if (v != 0.0f) {
                        uint32_t positive;
                        float y0;
                        float y1;
                        if (v > 0.0f) {
                            positive = 0;
                            int32_t d = up - prim->ScaleOf(vertical, v);
                            y0 = static_cast<float>(d);
                            y1 = static_cast<float>(up);
                            up = d;
                        } else {
                            positive = 1;
                            int32_t d = down - prim->ScaleOf(vertical, v);
                            y1 = static_cast<float>(d);
                            y0 = static_cast<float>(down);
                            down = d;
                        }
                        rect[0] = static_cast<int32_t>(x0);
                        rect[1] = static_cast<int32_t>(y0);
                        rect[2] = static_cast<int32_t>(x1);
                        rect[3] = static_cast<int32_t>(y1);
                        Slot33_adde50(buffer, OB_ADDR(rect), s, positive);
                    }
                }
            }
            x0 = mfBarWidth + mfBarSpacing + x0;
            x1 = x0 + mfBarSpacing;
        }
        if (lengths.mpBegin) {
            StlDelete_ade648(lengths.mpBegin);
        }
    } else if (mnLayoutMode == 1) {
        float x0 = static_cast<float>(mnGraphArea[0]) + mfBarWidth;
        float x1 = x0 + mfBarSpacing;
        uint32_t bars = static_cast<uint32_t>(OB_DATA_ADE648[0].mpEnd - OB_DATA_ADE648[0].mpBegin);
        for (uint32_t bar = 0; bar < bars; bar++) {
            for (uint32_t s = 0; s < n; s++) {
                float v = OB_DATA_ADE648[s].mpBegin[bar];
                if (v != 0.0f) {
                    uint32_t positive;
                    float y0;
                    float y1;
                    if (v > 0.0f) {
                        positive = 0;
                        y0 = static_cast<float>(prim->PositionOf(vertical, v, true));
                        y1 = static_cast<float>(mnGraphArea[vertical ? 3 : 2]);
                    } else {
                        positive = 1;
                        y0 = static_cast<float>(mnGraphArea[vertical ? 3 : 2]);
                        y1 = static_cast<float>(prim->PositionOf(vertical, v, true));
                    }
                    rect[0] = static_cast<int32_t>(x0);
                    rect[1] = static_cast<int32_t>(y0);
                    rect[2] = static_cast<int32_t>(x1);
                    rect[3] = static_cast<int32_t>(y1);
                    Slot33_adde50(buffer, OB_ADDR(rect), s, positive);
                }
                x0 = x0 + mfBarSpacing;
                x1 = x1 + mfBarSpacing;
            }
            x0 = x0 + mfBarWidth;
            x1 = x1 + mfBarWidth;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0094bd38 score 15
bool Rect_ade648::Contains(const void* point)
{
    const int32_t* p = static_cast<const int32_t*>(point);
    int32_t x = p[0];
    if (x >= v[0]) {
        int32_t y = p[1];
        if (y >= v[1] && x <= v[2] && y <= v[3]) {
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b74ce score 2
SeriesInit_ade648* SeriesInit_ade648::Init()
{
    mnOutlineColor = 0;
    mnFillColor = 0xffffffff;
    mpPattern = 0;
    mbOutline = true;
    mbFill = true;
    new (mName) cRZString();
    return this;
}
#endif
