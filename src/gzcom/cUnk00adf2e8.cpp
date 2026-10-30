#include "classes/cUnk00adf2e8.h"
#include <cfloat>
#include <algorithm>
#include <vector>
#include "gzcom/cIGZUnknown.h"
#include "gzcom/cRZString.h"

// One data series' look: 0x28 bytes, kept in a vector at +0x14 of the data-series base.
struct Dataset_adf2e8 {
    uint8_t mbShowMarker;
    uint8_t mnMark;
    uint8_t mPad2[2];
    uint32_t mnSize;
    uint8_t mbShowLine;
    uint8_t mPad9[3];
    uint32_t mnColor;
    uint32_t mnFlags;
    cRZString mName;
    // STUB: 0x0076bd20
    Dataset_adf2e8();
    // STUB: 0x009baa81
    Dataset_adf2e8& Fn009baa81(const Dataset_adf2e8* source);
};

typedef std::vector<float> Values_adf2e8;
typedef std::vector<Values_adf2e8> ValueRows_adf2e8;
typedef std::vector<Dataset_adf2e8> Datasets_adf2e8;
typedef std::vector<cRZString> Labels_adf2e8;

#define DS_adf2e8() (*reinterpret_cast<Datasets_adf2e8*>(&mpSeriesBegin))
#define VR_adf2e8() (*reinterpret_cast<ValueRows_adf2e8*>(&mpValuesBegin))
#define LB_adf2e8() (*reinterpret_cast<Labels_adf2e8*>(&mpLabelsBegin))

// The default look of a series.
#ifdef OB_DRAFTS
// CLOSE: 0x0076bd20 score 27
Dataset_adf2e8::Dataset_adf2e8()
{
    mbShowMarker = 1;
    mnMark = 0x41;
    mnSize = 12;
    mbShowLine = 1;
    mnColor = 0;
    mnFlags = 1;
}
#endif

// GetThisAsAddff8(): the primary object, seen from the graph interface.
// FUNCTION: 0x0076b630
void* cUnk00adf2e8::Slot54_addff8()
{
    return this;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0076b640 score 2
uint32_t cUnk00adf2e8::Slot34_ade0f0()
{
    cUnk00adf2e8* self = this;
    if (self) {
        return OB_ADDR(static_cast<cUnk00addff8*>(self));
    }
    return 0;
}
#endif

// FUNCTION: 0x009b293a
bool cUnk00adf2e8::Slot43_addff8(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    return cGZGraph::Slot43_addff8(a, b, c, d, e, f, g);
}

// Removes every series, last first.
// FUNCTION: 0x009b41f1
void cUnk00adf2e8::Slot08_ade0f0()
{
    uint32_t count = VR_adf2e8().size();
    if (count > 0) {
        uint32_t i = count;
        do {
            Slot07_ade0f0(0xffffffff);
        } while (--i);
    }
}

// SetSeriesLook: which of two flags a series (or all, -1) has.
#ifdef OB_DRAFTS
// CLOSE: 0x009b4216 score 65
void cUnk00adf2e8::Slot09_ade0f0(uint32_t line, uint32_t point, uint32_t index)
{
    if (index == 0xffffffff) {
        for (uint32_t i = 0; i < DS_adf2e8().size(); ++i) {
            DS_adf2e8()[i].mbShowMarker = line ? 1 : 0;
            DS_adf2e8()[i].mbShowLine = point ? 1 : 0;
        }
    } else if (index < DS_adf2e8().size()) {
        Dataset_adf2e8* d = &DS_adf2e8()[index];
        if (line) {
            d->mbShowMarker = 1;
        } else {
            d->mbShowMarker = 0;
        }
        if (point) {
            d->mbShowLine = 1;
        } else {
            d->mbShowLine = 0;
        }
    }
}
#endif

// FUNCTION: 0x009b42b2
void cUnk00adf2e8::Slot10_ade0f0(uint32_t mark, uint32_t index)
{
    if (index == 0xffffffff) {
        for (uint32_t i = 0; i < DS_adf2e8().size(); ++i) {
            DS_adf2e8()[i].mnMark = static_cast<uint8_t>(mark);
        }
    } else if (index < DS_adf2e8().size()) {
        DS_adf2e8()[index].mnMark = static_cast<uint8_t>(mark);
    }
}

// FUNCTION: 0x009b430e
void cUnk00adf2e8::Slot11_ade0f0(uint32_t size, uint32_t index)
{
    if (index == 0xffffffff) {
        for (uint32_t i = 0; i < DS_adf2e8().size(); ++i) {
            DS_adf2e8()[i].mnSize = size;
        }
    } else if (index < DS_adf2e8().size()) {
        DS_adf2e8()[index].mnSize = size;
    }
}

// FUNCTION: 0x009b436a
void cUnk00adf2e8::Slot12_ade0f0(uint32_t color, uint32_t index)
{
    if (index == 0xffffffff) {
        for (uint32_t i = 0; i < DS_adf2e8().size(); ++i) {
            DS_adf2e8()[i].mnColor = color;
        }
    } else if (index < DS_adf2e8().size()) {
        DS_adf2e8()[index].mnColor = color;
    }
}

// SetSeriesName(const cRZString&, index)
// FUNCTION: 0x009baabc
void cUnk00adf2e8::Slot13_ade0f0(uint32_t name, uint32_t index)
{
    if (index == 0xffffffff) {
        for (uint32_t i = 0; i < DS_adf2e8().size(); ++i) {
            DS_adf2e8()[i].mName = *OB_PTR(const cRZString, name);
        }
    } else if (index < DS_adf2e8().size()) {
        DS_adf2e8()[index].mName = *OB_PTR(const cRZString, name);
    }
}

// SetSeriesLookFrom(const Look&, index)
// FUNCTION: 0x009bab24
void cUnk00adf2e8::Slot14_ade0f0(uint32_t look, uint32_t index)
{
    if (index < DS_adf2e8().size()) {
        DS_adf2e8()[index].Fn009baa81(OB_PTR(const Dataset_adf2e8, look));
    }
}

// FUNCTION: 0x009b5e8b
bool cUnk00adf2e8::Slot04_ae1d24()
{
    if (mpFont) {
        mpFont->Release();
        mpFont = 0;
    }
    return cGZGraph::Slot04_ae1d24();
}

// The highest value over all series.
#ifdef OB_DRAFTS
// CLOSE: 0x009b5eac score 29
float cUnk00adf2e8::Slot164_ade188(uint32_t)
{
    float high = -FLT_MAX;
    uint32_t rows = VR_adf2e8().size();
    for (uint32_t r = 0; r < rows; ++r) {
        for (uint32_t c = 0; c < VR_adf2e8()[r].size(); ++c) {
            float v = VR_adf2e8()[r][c];
            if (v > high) {
                high = v;
            }
        }
    }
    return high;
}
#endif

// The lowest value over all series.
#ifdef OB_DRAFTS
// CLOSE: 0x009b5f09 score 29
float cUnk00adf2e8::Slot165_ade188(uint32_t)
{
    float low = FLT_MAX;
    uint32_t rows = VR_adf2e8().size();
    for (uint32_t r = 0; r < rows; ++r) {
        for (uint32_t c = 0; c < VR_adf2e8()[r].size(); ++c) {
            float v = VR_adf2e8()[r][c];
            if (v < low) {
                low = v;
            }
        }
    }
    return low;
}
#endif

// The pixel position of the n-th label along the axis.
#ifdef OB_DRAFTS
// CLOSE: 0x009b43c6 score 77
uint32_t cUnk00adf2e8::Slot30_ade0f0(uint32_t n)
{
    uint32_t count = 2;
    if (!VR_adf2e8().empty()) {
        uint32_t size = VR_adf2e8()[0].size();
        if (size > 1) {
            count = size;
        }
    }
    if (field230 == 0) {
        int32_t width = mnGraphArea[2] - mnGraphArea[0];
        return mnGraphArea[0] + static_cast<int32_t>(static_cast<float>(width) * static_cast<float>(n) / static_cast<float>(count - 1));
    }
    int32_t height = mnGraphArea[3] - mnGraphArea[1];
    return mnGraphArea[3] - static_cast<int32_t>(static_cast<float>(height) * static_cast<float>(n) / static_cast<float>(count - 1));
}
#endif

// ---- batch B ----

// A float vector seen through its out-of-line members.
struct FloatVec_adf2e8 {
    float* mpBegin;
    float* mpEnd;
    float* mpCap;
    // STUB: 0x008d3333
    float* Fn008d3333(float* position);
};

// The font a series marker is drawn with, seen through the slots this class calls.
struct Font_adf2e8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void P05();
    virtual void P06();
    virtual void P07();
    virtual void P08();
    virtual void P09();
    virtual void P10();
    virtual void P11();
    virtual uint32_t GetColor();
    virtual void P13();
    virtual void SetColor(uint32_t color, uint32_t flags);
    virtual void P15();
    virtual void P16();
    virtual void P17();
    virtual void P18();
    virtual void P19();
    virtual void P20();
    virtual void P21();
    virtual void P22();
    virtual void P23();
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
    virtual uint32_t GetCharWidth(const char* text, uint32_t length);
    virtual uint32_t GetLineHeight(uint32_t a, uint32_t b);
    virtual void P38();
    virtual void P39();
    virtual void P40();
    virtual void P41();
    virtual void P42();
    virtual void P43();
    virtual void P44();
    virtual void P45();
    virtual void P46();
    virtual void P47();
    virtual uint32_t GetStringWidth(const char* text, uint32_t length);
    virtual void P49();
    virtual void P50();
    virtual void DrawTextAt(uint32_t buffer, int32_t x, int32_t y, const char* text, uint32_t length, uint32_t a, uint32_t b, uint32_t c, uint32_t d);
    virtual void DrawTextLine(uint32_t buffer, const int32_t* area, const char* text, uint32_t length, uint32_t align, uint32_t color, uint32_t background, uint32_t a, uint32_t b);
    virtual void P53();
    virtual void P54();
    virtual bool BeginDraw(uint32_t buffer);
    virtual void EndDraw(uint32_t buffer);
};

// GLOBAL: 0x00bac068
extern Dataset_adf2e8* gpBac068_adf2e8;

// SetSeriesColor... the graph's marker: a character in the series' color, centred on a point.
// DrawMarker(cIGZBuffer*, const cRZPoint&, index)
#ifdef OB_DRAFTS
// CLOSE: 0x009b447c score 55
void cUnk00adf2e8::Slot31_ade0f0(uint32_t buffer, uint32_t point, uint32_t index)
{
    if (index < DS_adf2e8().size() && mpFont) {
        Dataset_adf2e8* d = &DS_adf2e8()[index];
        char mark = static_cast<char>(d->mnMark);
        uint32_t color = d->mnColor;
        Font_adf2e8* font = reinterpret_cast<Font_adf2e8*>(mpFont);
        uint32_t width = font->GetCharWidth(&mark, 1);
        uint32_t height = font->GetLineHeight(0, 0);
        const int32_t* at = OB_PTR(const int32_t, point);
        if (color == 0x80000000) {
            font->DrawTextAt(buffer, at[0] - (width >> 1), at[1] - (height >> 1), &mark, 1, 0x8000000, 0x8000000, 0, 0);
        } else {
            uint32_t old = font->GetColor();
            font->SetColor(color, 0x8000000);
            font->DrawTextAt(buffer, at[0] - (width >> 1), at[1] - (height >> 1), &mark, 1, 0x8000000, 0x8000000, 0, 0);
            font->SetColor(old, 0x8000000);
        }
    }
}
#endif

// DrawSeriesLine(cIGZBuffer*, const cRZRect&, index): a line in the series' color.
// FUNCTION: 0x009b4585
void cUnk00adf2e8::Slot32_ade0f0(uint32_t buffer, uint32_t rect, uint32_t index)
{
    if (index < DS_adf2e8().size()) {
        Dataset_adf2e8* d = &DS_adf2e8()[index];
        const int32_t* r = OB_PTR(const int32_t, rect);
        Slot43_addff8(buffer, r[0], r[1], r[2], r[3], d->mnColor, d->mnFlags);
    }
}

// RemoveValue(position, series)
// FUNCTION: 0x009b5f66
void cUnk00adf2e8::Slot21_ade0f0(uint32_t position, uint32_t series)
{
    if (series == 0xffffffff && VR_adf2e8().size() == 1) {
        series = 0;
    }
    if (series < VR_adf2e8().size()) {
        FloatVec_adf2e8* row = reinterpret_cast<FloatVec_adf2e8*>(&VR_adf2e8()[series]);
        row->Fn008d3333(row->mpBegin + position);
    }
}

// SetSeriesValues(const vector<float>&, series)
// FUNCTION: 0x009b6a77
void cUnk00adf2e8::Slot22_ade0f0(uint32_t values, uint32_t series)
{
    uint32_t n = VR_adf2e8().size();
    if (series == 0xffffffff && n == 1) {
        series = 0;
    }
    if (series < n) {
        VR_adf2e8()[series] = *OB_PTR(const Values_adf2e8, values);
    }
}

// SetValue(value, position, series): the value at the position, or appended when the position is -1.
// FUNCTION: 0x009b82ce
void cUnk00adf2e8::Slot23_ade0f0(uint32_t value, uint32_t position, uint32_t series)
{
    if (series < VR_adf2e8().size()) {
        Values_adf2e8& row = VR_adf2e8()[series];
        if (position == 0xffffffff) {
            row.push_back(*reinterpret_cast<float*>(&value));
        } else {
            row[position] = *reinterpret_cast<float*>(&value);
        }
    }
}

// InsertValue(value, series, position)
// FUNCTION: 0x009b830e
void cUnk00adf2e8::Slot20_ade0f0(uint32_t value, uint32_t series, uint32_t position)
{
    if (series == 0xffffffff && VR_adf2e8().size() == 1) {
        series = 0;
    }
    if (series < VR_adf2e8().size()) {
        Values_adf2e8& row = VR_adf2e8()[series];
        if (position == 0xffffffff) {
            row.push_back(*reinterpret_cast<float*>(&value));
        } else {
            row.insert(row.begin() + position, *reinterpret_cast<float*>(&value));
        }
    }
}

// AppendValues(const vector<float>&, series)
#ifdef OB_DRAFTS
// CLOSE: 0x009b836f score 38
void cUnk00adf2e8::Slot24_ade0f0(uint32_t values, uint32_t series)
{
    if (series == 0xffffffff && VR_adf2e8().size() == 1) {
        series = 0;
    }
    if (series < VR_adf2e8().size()) {
        Values_adf2e8& row = VR_adf2e8()[series];
        const Values_adf2e8* source = OB_PTR(const Values_adf2e8, values);
        for (uint32_t i = 0; i < source->size(); ++i) {
            row.push_back((*source)[i]);
        }
    }
}
#endif

// ClearLabel(index): the last label when -1.
// FUNCTION: 0x009b66cb
void cUnk00adf2e8::Slot18_ade0f0(uint32_t index)
{
    if (index == 0xffffffff) {
        index = LB_adf2e8().size() - 1;
    }
    if (index < LB_adf2e8().size()) {
        reinterpret_cast<std::string*>(reinterpret_cast<uint8_t*>(&LB_adf2e8()[index]) + 4)->erase(0, std::string::npos);
    }
}

// FUNCTION: 0x009bbcb7
void cUnk00adf2e8::Slot19_ade0f0()
{
    LB_adf2e8().clear();
}

// SetLabel(const cRZString&, index): grows the label list to fit.
// FUNCTION: 0x009bbe63
void cUnk00adf2e8::Slot17_ade0f0(uint32_t label, uint32_t index)
{
    if (index == 0xffffffff) {
        index = LB_adf2e8().size();
    }
    if (index >= LB_adf2e8().size()) {
        LB_adf2e8().resize(index + 1);
    }
    LB_adf2e8()[index] = *OB_PTR(const cRZString, label);
}

// RemoveSeriesLook(index)
// FUNCTION: 0x009bbc77
void cUnk00adf2e8::Slot16_ade0f0(uint32_t index)
{
    if (index == 0xffffffff) {
        DS_adf2e8().pop_back();
    } else if (index < DS_adf2e8().size()) {
        DS_adf2e8().erase(DS_adf2e8().begin() + index);
    }
}

// InsertSeriesLook(const Look&, index)
// FUNCTION: 0x009bbc35
void cUnk00adf2e8::Slot15_ade0f0(uint32_t look, uint32_t index)
{
    if (index == 0xffffffff) {
        DS_adf2e8().push_back(*OB_PTR(const Dataset_adf2e8, look));
    }
    if (index < DS_adf2e8().size()) {
        DS_adf2e8().insert(DS_adf2e8().begin() + index, *OB_PTR(const Dataset_adf2e8, look));
    }
}

// InsertSeries(index): an empty row of values and a default look.
#ifdef OB_DRAFTS
// CLOSE: 0x009bbb36 score 17
void cUnk00adf2e8::Slot06_ade0f0(uint32_t index)
{
    if (index == 0xffffffff) {
        Values_adf2e8 empty;
        VR_adf2e8().push_back(empty);
        Dataset_adf2e8 look;
        DS_adf2e8().push_back(look);
    } else if (index < VR_adf2e8().size()) {
        Values_adf2e8 empty;
        VR_adf2e8().insert(VR_adf2e8().begin() + index, empty);
        Dataset_adf2e8 look;
        DS_adf2e8().insert(DS_adf2e8().begin() + index, look);
    }
}
#endif

// RemoveSeries(index)
// FUNCTION: 0x009bbbd2
void cUnk00adf2e8::Slot07_ade0f0(uint32_t index)
{
    if (index == 0xffffffff) {
        VR_adf2e8().pop_back();
        DS_adf2e8().pop_back();
    } else if (index < VR_adf2e8().size()) {
        VR_adf2e8().erase(VR_adf2e8().begin() + index);
        DS_adf2e8().erase(DS_adf2e8().begin() + index);
    }
}

// SetSeriesCount(n): n rows of values, n looks taken from a table of eight in turn.
// FUNCTION: 0x009bc01a
void cUnk00adf2e8::Slot05_ade0f0(uint32_t count)
{
    VR_adf2e8().resize(count);
    DS_adf2e8().resize(count);
    for (uint32_t i = 0; i < count; ++i) {
        DS_adf2e8()[i].Fn009baa81(&gpBac068_adf2e8[i & 7]);
    }
}

// SetFont(font, color): holds a reference to the font.
// FUNCTION: 0x009b28fb
void cUnk00adf2e8::Slot04_ade0f0(uint32_t font, uint32_t color)
{
    cIGZUnknown* p = OB_PTR(cIGZUnknown, font);
    if (p != mpFont) {
        if (p) {
            p->AddRef();
        }
        if (mpFont) {
            mpFont->Release();
        }
        mpFont = p;
    }
    if (color != 0x80000000) {
        mnFontColor = color;
    }
}

// ---- batch C ----

// The drawing buffer, seen through the slots this class calls.
struct Buffer_adf2e8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void P05();
    virtual bool Lock(uint32_t flags);
    virtual bool Unlock(uint32_t flags);
};

// The font system RZ::FO(): makes fonts by name.
struct FontSystem_adf2e8 {
    virtual void P00();
    virtual void P01();
    virtual void P02();
    virtual void P03();
    virtual void P04();
    virtual void P05();
    virtual void P06();
    virtual void P07();
    virtual void P08();
    virtual void P09();
    virtual void P10();
    virtual cIGZUnknown* CreateFont(const cRZString& name, uint32_t style, uint32_t size, uint32_t a, uint32_t b);
};

// STUB: 0x00913d22
FontSystem_adf2e8* Fn00913d22_adf2e8();

// LoadDefaultFonts(): the marker font, windings (else dingbats), when the graph has none.
// FUNCTION: 0x009b8210
void cUnk00adf2e8::LoadDefaultFonts()
{
    if (!mpFont) {
        FontSystem_adf2e8* fonts = Fn00913d22_adf2e8();
        if (fonts) {
            cIGZUnknown* font = fonts->CreateFont(cRZString("windings"), 0, 12, 0, 1);
            if (!font) {
                font = fonts->CreateFont(cRZString("dingbats"), 0, 12, 0, 1);
            }
            if (font) {
                Slot04_ade0f0(OB_ADDR(font), 0x80000000);
                font->Release();
            }
        }
    }
    cGZGraph::LoadDefaultFonts();
}

// DrawTicks(cIGZBuffer*, flags): the base draws the value axis; this draws the tick marks of the label axis, major
// ones between the labels, minor ones at them.
#ifdef OB_DRAFTS
// CLOSE: 0x009b45ce score 162
void cUnk00adf2e8::Slot155_ade188(uint32_t buffer, uint32_t flags)
{
    int32_t minorStart0;
    int32_t minorEnd0;
    int32_t majorStart0;
    int32_t majorEnd0;
    int32_t minorStart1;
    int32_t minorEnd1;
    int32_t majorStart1;
    int32_t majorEnd1;
    int32_t first = 0;
    if (field230 == 0 && (flags & 2)) {
        cGZGraph::Slot155_ade188(buffer, 2);
    }
    if (field230 == 1 && (flags & 1)) {
        cGZGraph::Slot155_ade188(buffer, 1);
    }
    if ((mbMajorTickUsage[0] || mbMinorTickUsage[0] || mbMajorTickUsage[1] || mbMinorTickUsage[1]) &&
        VR_adf2e8().size() != 0) {
        Buffer_adf2e8* target = OB_PTR(Buffer_adf2e8, buffer);
        if (target->Lock(0x8004)) {
            if (field230 == 0 && (flags & 1) && (mbMajorTickUsage[0] || mbMinorTickUsage[0])) {
                if (mbMajorTickUsage[0]) {
                    int32_t bottom = mnGraphArea[3];
                    majorEnd0 = bottom + mnMajorTickLength[0];
                    if (mbMajorTickGrid[0]) {
                        majorStart0 = mnGraphArea[1];
                    } else {
                        majorStart0 = bottom;
                    }
                }
                if (mbMinorTickUsage[0]) {
                    int32_t bottom = mnGraphArea[3];
                    minorEnd0 = bottom + mnMinorTickLength[0];
                    if (mbMinorTickGrid[0]) {
                        minorStart0 = mnGraphArea[1];
                    } else {
                        minorStart0 = bottom;
                    }
                }
                int32_t count = VR_adf2e8()[0].size();
                int32_t pos = 0;
                for (int32_t i = 0; i < count; ++i) {
                    pos = Slot30_ade0f0(i);
                    if (mbMinorTickUsage[0]) {
                        int32_t x = pos;
                        if (i == 0) {
                            x = mnGraphArea[0];
                        } else if (i == count - 1) {
                            x = mnGraphArea[2];
                        }
                        Slot43_addff8(buffer, x, minorStart0, x, minorEnd0, mnTickColor, 1);
                    }
                    if (mbMajorTickUsage[0] && static_cast<uint32_t>(i + 1) < static_cast<uint32_t>(count)) {
                        int32_t mid = (Slot30_ade0f0(i + 1) + pos) / 2;
                        Slot43_addff8(buffer, mid, majorStart0, mid, majorEnd0, mnTickColor, 1);
                    }
                }
                first = pos;
            }
            if (field230 == 1 && (flags & 2) && (mbMajorTickUsage[1] || mbMinorTickUsage[1])) {
                if (mbMajorTickUsage[1]) {
                    int32_t left = mnGraphArea[0];
                    majorStart1 = left - mnMajorTickLength[1];
                    if (mbMajorTickGrid[1]) {
                        majorEnd1 = mnGraphArea[2];
                    } else {
                        majorEnd1 = left;
                    }
                }
                if (mbMinorTickUsage[1]) {
                    int32_t left = mnGraphArea[0];
                    minorStart1 = left - mnMinorTickLength[1];
                    if (mbMinorTickGrid[1]) {
                        minorEnd1 = mnGraphArea[2];
                    } else {
                        minorEnd1 = left;
                    }
                }
                int32_t count = VR_adf2e8()[0].size();
                for (int32_t i = 0; i < count; ++i) {
                    int32_t pos = Slot30_ade0f0(i);
                    if (mbMinorTickUsage[1]) {
                        int32_t y = pos;
                        if (i == 0) {
                            y = mnGraphArea[1];
                        } else if (i == count - 1) {
                            y = mnGraphArea[3];
                        }
                        Slot43_addff8(buffer, minorStart1, y, minorEnd1, y, mnTickColor, 1);
                    }
                    if (mbMajorTickUsage[1] && static_cast<uint32_t>(i + 1) < static_cast<uint32_t>(count)) {
                        int32_t mid = (Slot30_ade0f0(i + 1) + first) / 2;
                        Slot43_addff8(buffer, majorStart1, mid, majorEnd1, mid, mnTickColor, 1);
                    }
                }
            }
            target->Unlock(0x8004);
        }
    }
}
#endif

// DrawGraphData(cIGZBuffer*): a line between each pair of neighbouring values of every series that has one, then a
// marker at each value of every series that has one.
#ifdef OB_DRAFTS
// CLOSE: 0x009b5fb1 score 64
void cUnk00adf2e8::DrawGraphData(uint32_t buffer)
{
    uint32_t rows = VR_adf2e8().size();
    if (rows) {
        int32_t columns = VR_adf2e8()[0].size();
        if (columns) {
            uint32_t axis = (field230 == 0);
            Buffer_adf2e8* target = OB_PTR(Buffer_adf2e8, buffer);
            if (target->Lock(0x8004)) {
                for (int32_t s = 0; s < static_cast<int32_t>(rows); ++s) {
                    if (DS_adf2e8()[s].mbShowLine) {
                        Values_adf2e8& row = VR_adf2e8()[s];
                        columns = row.size();
                        for (int32_t i = 0; i < columns - 1; ++i) {
                            int32_t line[4];
                            float v0 = row[i];
                            float v1 = row[i + 1];
                            line[0] = Slot30_ade0f0(i);
                            line[1] = Slot160_ade188(axis, v0, true);
                            line[2] = Slot30_ade0f0(i + 1);
                            line[3] = Slot160_ade188(axis, v1, true);
                            if (field230 == 1) {
                                int32_t first = line[0];
                                line[0] = line[3];
                                line[3] = line[2];
                                line[2] = line[1];
                                line[1] = first;
                            }
                            Slot32_ade0f0(buffer, OB_ADDR(line), s);
                        }
                    }
                }
                target->Unlock(0x8004);
                if (mpFont) {
                    Font_adf2e8* font = reinterpret_cast<Font_adf2e8*>(mpFont);
                    if (font->BeginDraw(buffer)) {
                        for (int32_t s = 0; s < static_cast<int32_t>(rows); ++s) {
                            if (DS_adf2e8()[s].mbShowMarker) {
                                Values_adf2e8& row = VR_adf2e8()[s];
                                for (int32_t i = 0; i < columns; ++i) {
                                    int32_t point[2];
                                    float v = row[i];
                                    point[0] = Slot30_ade0f0(i);
                                    point[1] = Slot160_ade188(axis, v, true);
                                    if (field230 == 1) {
                                        int32_t swap = point[0];
                                        point[0] = point[1];
                                        point[1] = swap;
                                    }
                                    Slot31_ade0f0(buffer, OB_ADDR(point), s);
                                }
                            }
                        }
                        reinterpret_cast<Font_adf2e8*>(mpFont)->EndDraw(buffer);
                    }
                }
            }
        }
    }
}
#endif

// DrawTickText(cIGZBuffer*, flags): the base draws the value axis; this writes the label under (or beside) each
// tick of the label axis, kept inside the graph area.
#ifdef OB_DRAFTS
// CLOSE: 0x009b83cd score 146
void cUnk00adf2e8::Slot156_ade188(uint32_t buffer, uint32_t flags)
{
    int32_t rect[4];
    if (field230 == 0) {
        if ((flags & 2) && mbTickText[1]) {
            cGZGraph::Slot156_ade188(buffer, 2);
        }
        if ((flags & 1) && mbTickText[0] && VR_adf2e8().size() != 0) {
            Font_adf2e8* font = reinterpret_cast<Font_adf2e8*>(mpAxisTickFont[0]);
            if (font) {
                uint32_t color = mnAxisTickFontColor[0];
                int32_t lineHeight = font->GetLineHeight(0, 0);
                int32_t below = Slot169_ade188(0);
                uint32_t labels = LB_adf2e8().size();
                uint32_t columns = VR_adf2e8()[0].size();
                uint32_t count = std::min(labels, columns);
                for (uint32_t i = 0; i < count; ++i) {
                    cRZString& label = LB_adf2e8()[i];
                    if (!label.empty()) {
                        int32_t width = font->GetStringWidth(label.data(), label.size());
                        rect[1] = mnGraphArea[3] + below;
                        rect[3] = rect[1] + lineHeight;
                        int32_t left = Slot30_ade0f0(i) - width / 2 - 1;
                        rect[0] = left;
                        rect[2] = width + left + 2;
                        if (left < mnGraphArea[0]) {
                            int32_t shift = mnGraphArea[0] - left;
                            left += shift;
                            rect[2] += shift;
                            rect[0] = left;
                        }
                        if (rect[2] > mnGraphArea[2]) {
                            int32_t shift = mnGraphArea[2] - rect[2];
                            left += shift;
                            rect[2] += shift;
                            rect[0] = left;
                        }
                        if (color == 0x80000000) {
                            font->DrawTextLine(buffer, rect, label.data(), label.size(), 1, 0x8000000, 0x8000000, 0, 0);
                        } else {
                            font->DrawTextLine(buffer, rect, label.data(), label.size(), 1, color, 0x8000000, 0, 0);
                        }
                    }
                }
            }
        }
    } else if (field230 == 1) {
        if ((flags & 1) && mbTickText[0]) {
            cGZGraph::Slot156_ade188(buffer, 1);
        }
        if ((flags & 2) && mbTickText[1] && VR_adf2e8().size() != 0) {
            Font_adf2e8* font = reinterpret_cast<Font_adf2e8*>(mpAxisTickFont[1]);
            if (font) {
                uint32_t color = mnAxisTickFontColor[1];
                int32_t lineHeight = font->GetLineHeight(0, 0);
                int32_t beside = Slot169_ade188(1);
                uint32_t labels = LB_adf2e8().size();
                uint32_t columns = VR_adf2e8()[0].size();
                uint32_t count = std::min(labels, columns);
                for (uint32_t i = 0; i < count; ++i) {
                    cRZString& label = LB_adf2e8()[i];
                    if (!label.empty()) {
                        int32_t width = font->GetStringWidth(label.data(), label.size());
                        rect[2] = mnGraphArea[0] - beside;
                        rect[0] = rect[2] - width;
                        int32_t top = Slot30_ade0f0(i) - lineHeight / 2;
                        rect[1] = top;
                        rect[3] = top + lineHeight + 2;
                        if (top < mnGraphArea[1]) {
                            int32_t shift = mnGraphArea[1] - top;
                            top += shift;
                            rect[3] += shift;
                            rect[1] = top;
                        }
                        if (rect[3] > mnGraphArea[3]) {
                            int32_t shift = mnGraphArea[3] - rect[3];
                            top += shift;
                            rect[3] += shift;
                            rect[1] = top;
                        }
                        if (color == 0x80000000) {
                            font->DrawTextLine(buffer, rect, label.data(), label.size(), 1, 0x8000000, 0x8000000, 0, 0);
                        } else {
                            font->DrawTextLine(buffer, rect, label.data(), label.size(), 1, color, 0x8000000, 0, 0);
                        }
                    }
                }
            }
        }
    }
}
#endif

// ---- batch D: the vector members the original instantiated ----

// The vector of rows of values, with its members as the original's code has them.
struct RowsVec_adf2e8 : public ValueRows_adf2e8 {
    void PushBack(const Values_adf2e8& row);
    Values_adf2e8* Erase(Values_adf2e8* position);
    Values_adf2e8* Insert(Values_adf2e8* position, const Values_adf2e8& row);
};

// The vector of looks.
struct DatasetsVec_adf2e8 : public Datasets_adf2e8 {
    void PushBack(const Dataset_adf2e8& look);
    Dataset_adf2e8* Insert(Dataset_adf2e8* position, const Dataset_adf2e8& look);
    Dataset_adf2e8* Erase(Dataset_adf2e8* position);
    void Resize(uint32_t count, const Dataset_adf2e8& fill);
    void ResizeDefault(uint32_t count);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009b9b4b score 25
void RowsVec_adf2e8::PushBack(const Values_adf2e8& row)
{
    push_back(row);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b95b2 score 27
Values_adf2e8* RowsVec_adf2e8::Erase(Values_adf2e8* position)
{
    return &*erase(iterator(position));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b9b83 score 72
Values_adf2e8* RowsVec_adf2e8::Insert(Values_adf2e8* position, const Values_adf2e8& row)
{
    return &*insert(iterator(position), row);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bae72 score 25
void DatasetsVec_adf2e8::PushBack(const Dataset_adf2e8& look)
{
    push_back(look);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bb934 score 69
Dataset_adf2e8* DatasetsVec_adf2e8::Insert(Dataset_adf2e8* position, const Dataset_adf2e8& look)
{
    return &*insert(iterator(position), look);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bb9d7 score 27
Dataset_adf2e8* DatasetsVec_adf2e8::Erase(Dataset_adf2e8* position)
{
    return &*erase(iterator(position));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bbe1a score 37
void DatasetsVec_adf2e8::Resize(uint32_t count, const Dataset_adf2e8& fill)
{
    resize(count, fill);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bbff1 score 17
void DatasetsVec_adf2e8::ResizeDefault(uint32_t count)
{
    resize(count);
}
#endif
