#include "classes/cGZScatterGraph.h"
#include <algorithm>
#include <cfloat>
#include <vector>
#include "gzcom/cIGZUnknown.h"
#include "gzcom/cRZString.h"

// One point: x then y.
struct Point_adea90 {
    float x;
    float y;
};

// One series' look: 0x24 bytes, kept in a vector at +0x14 of the series base.
struct Look_adea90 {
    uint8_t mnMark;
    uint8_t mPad1[3];
    uint32_t mnSize;
    uint32_t mnColor;
    cRZString mName;
    uint8_t mbConnect;
    uint8_t mPad21[3];
    // STUB: 0x009b74f0
    Look_adea90();
    // STUB: 0x009ba152
    Look_adea90& Fn009ba152(const Look_adea90* source);
};

struct Rect_adea90 {
    int32_t v[4];
};

typedef std::vector<Point_adea90> Points_adea90;
typedef std::vector<Points_adea90> Rows_adea90;
typedef std::vector<Look_adea90> Looks_adea90;

#define LK_adea90() (*reinterpret_cast<Looks_adea90*>(&mpLooksBegin))
#define RW_adea90() (*reinterpret_cast<Rows_adea90*>(&mpRowsBegin))

// The default look of a series.
#ifdef OB_DRAFTS
// CLOSE: 0x009b74f0 score 4
Look_adea90::Look_adea90()
{
    mnMark = 0x41;
    mnSize = 12;
    mnColor = 0;
}
#endif

// The font a series marker is drawn with, seen through the slots this class calls.
struct Font_adea90 {
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

// The drawing buffer, seen through the slots this class calls.
struct Buffer_adea90 {
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
struct FontSystem_adea90 {
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
FontSystem_adea90* Fn00913d22_adea90();

// GLOBAL: 0x00bac080
extern Look_adea90* gpBac080_adea90;

// QueryInterface: the series interface answers with its own subobject, anything else goes to the base.
#ifdef OB_DRAFTS
// CLOSE: 0x009b2a38 score 4
bool cGZScatterGraph::QueryInterface(uint32_t iid, void** ppv)
{
    if (iid == 0x32cf2351) {
        *ppv = static_cast<cUnk00addef0*>(this);
        AddRef();
        return true;
    }
    return cGZGraph::QueryInterface(iid, ppv);
}
#endif

// SetFont(font, color): holds a reference to the font.
// FUNCTION: 0x009b2a65
void cGZScatterGraph::Slot03_addef0(uint32_t font, uint32_t color)
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

// GetAutomaticAxisMinValue(Axis, float&): the lowest value, stretched by a ninth, never above zero.
#ifdef OB_DRAFTS
// CLOSE: 0x009b2a9f score 28
void cGZScatterGraph::Slot174_ade188(uint32_t axis, uint32_t out)
{
    float* result = OB_PTR(float, out);
    if (mbSwapAxes) {
        float a = Slot165_ade188(0);
        float b = Slot165_ade188(1);
        if (!(a < 0.0f)) {
            a = 0.0f;
        }
        if (!(b < 0.0f)) {
            b = 0.0f;
        }
        if (a >= b) {
            *result = b;
        } else {
            *result = a;
        }
        *result = *result * 1.1111112f;
    } else {
        float v = Slot165_ade188(axis);
        *result = v;
        if (v < 0.0f) {
            *result = v * 1.1111112f;
        } else {
            *result = 0.0f;
        }
    }
}
#endif

// GetAutomaticAxisMaxValue(Axis, float&): the highest value, stretched by a ninth, never below zero.
#ifdef OB_DRAFTS
// CLOSE: 0x009b2b47 score 20
void cGZScatterGraph::Slot175_ade188(uint32_t axis, uint32_t out)
{
    float* result = OB_PTR(float, out);
    if (mbSwapAxes) {
        float a = Slot164_ade188(0);
        float b = Slot164_ade188(1);
        if (!(a > 0.0f)) {
            a = 0.0f;
        }
        if (!(b > 0.0f)) {
            b = 0.0f;
        }
        if (a <= b) {
            *result = b;
        } else {
            *result = a;
        }
        *result = *result * 1.1111112f;
    } else {
        float v = Slot164_ade188(axis);
        *result = v;
        if (v > 0.0f) {
            *result = v * 1.1111112f;
        } else {
            *result = 0.0f;
        }
    }
}
#endif

// The setters of one field of a look, for one series or (-1) all of them.
// FUNCTION: 0x009b55a7
void cGZScatterGraph::Slot07_addef0(uint32_t mark, uint32_t index)
{
    if (index == 0xffffffff) {
        for (uint32_t i = 0; i < LK_adea90().size(); ++i) {
            LK_adea90()[i].mnMark = static_cast<uint8_t>(mark);
        }
    } else if (index < LK_adea90().size()) {
        LK_adea90()[index].mnMark = static_cast<uint8_t>(mark);
    }
}

// FUNCTION: 0x009b5601
void cGZScatterGraph::Slot08_addef0(uint32_t size, uint32_t index)
{
    if (index == 0xffffffff) {
        for (uint32_t i = 0; i < LK_adea90().size(); ++i) {
            LK_adea90()[i].mnSize = size;
        }
    } else if (index < LK_adea90().size()) {
        LK_adea90()[index].mnSize = size;
    }
}

// FUNCTION: 0x009b565d
void cGZScatterGraph::Slot09_addef0(uint32_t color, uint32_t index)
{
    if (index == 0xffffffff) {
        for (uint32_t i = 0; i < LK_adea90().size(); ++i) {
            LK_adea90()[i].mnColor = color;
        }
    } else if (index < LK_adea90().size()) {
        LK_adea90()[index].mnColor = color;
    }
}

// FUNCTION: 0x009b56b9
void cGZScatterGraph::Slot11_addef0(uint32_t connect, uint32_t index)
{
    if (index == 0xffffffff) {
        for (uint32_t i = 0; i < LK_adea90().size(); ++i) {
            LK_adea90()[i].mbConnect = static_cast<uint8_t>(connect);
        }
    } else if (index < LK_adea90().size()) {
        LK_adea90()[index].mbConnect = static_cast<uint8_t>(connect);
    }
}

// DrawMarker(cIGZBuffer*, const cRZPoint&, index): a character in the series' color, centred on a point.
#ifdef OB_DRAFTS
// CLOSE: 0x009b5715 score 55
void cGZScatterGraph::Slot30_addef0(uint32_t buffer, uint32_t point, uint32_t index)
{
    if (index < LK_adea90().size() && mpFont) {
        Look_adea90* d = &LK_adea90()[index];
        char mark = static_cast<char>(d->mnMark);
        uint32_t color = d->mnColor;
        Font_adea90* font = reinterpret_cast<Font_adea90*>(mpFont);
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

// FUNCTION: 0x009b625f
bool cGZScatterGraph::Slot04_ae1d24()
{
    if (mpFont) {
        mpFont->Release();
        mpFont = 0;
    }
    return cGZGraph::Slot04_ae1d24();
}

// The highest value of an axis over all points of all series.
#ifdef OB_DRAFTS
// CLOSE: 0x009b6280 score 106
float cGZScatterGraph::Slot164_ade188(uint32_t axis)
{
    float high = -FLT_MAX;
    if (axis == 0) {
        for (uint32_t r = 0; r < RW_adea90().size(); ++r) {
            for (uint32_t c = 0; c < RW_adea90()[r].size(); ++c) {
                float v = RW_adea90()[r][c].x;
                if (v > high) {
                    high = v;
                }
            }
        }
    } else if (axis == 1) {
        for (uint32_t r = 0; r < RW_adea90().size(); ++r) {
            for (uint32_t c = 0; c < RW_adea90()[r].size(); ++c) {
                float v = RW_adea90()[r][c].y;
                if (v > high) {
                    high = v;
                }
            }
        }
    }
    return high;
}
#endif

// The lowest value of an axis over all points of all series.
#ifdef OB_DRAFTS
// CLOSE: 0x009b633c score 106
float cGZScatterGraph::Slot165_ade188(uint32_t axis)
{
    float low = FLT_MAX;
    if (axis == 0) {
        for (uint32_t r = 0; r < RW_adea90().size(); ++r) {
            for (uint32_t c = 0; c < RW_adea90()[r].size(); ++c) {
                float v = RW_adea90()[r][c].x;
                if (v < low) {
                    low = v;
                }
            }
        }
    } else if (axis == 1) {
        for (uint32_t r = 0; r < RW_adea90().size(); ++r) {
            for (uint32_t c = 0; c < RW_adea90()[r].size(); ++c) {
                float v = RW_adea90()[r][c].y;
                if (v < low) {
                    low = v;
                }
            }
        }
    }
    return low;
}
#endif

// DrawGraphData(cIGZBuffer*): every point as a marker, joined to the one before it when the series says so.
#ifdef OB_DRAFTS
// CLOSE: 0x009b63f8 score 80
void cGZScatterGraph::DrawGraphData(uint32_t buffer)
{
    int32_t previous[2];
    int32_t current[2];
    uint32_t rows = RW_adea90().size();
    if (rows) {
        uint32_t columns = RW_adea90()[0].size();
        if (columns) {
            Font_adea90* font = reinterpret_cast<Font_adea90*>(mpFont);
            if (font->BeginDraw(buffer)) {
                for (uint32_t s = 0; s < rows; ++s) {
                    bool connect = LK_adea90()[s].mbConnect != 0;
                    for (uint32_t i = 0; i < columns; ++i) {
                        float px = RW_adea90()[s][i].x;
                        float py = RW_adea90()[s][i].y;
                        current[0] = Slot160_ade188(0, px, true);
                        current[1] = Slot160_ade188(1, py, true);
                        if (connect && i > 0) {
                            Slot43_addff8(buffer, previous[0], previous[1], current[0], current[1],
                                          LK_adea90()[s].mnColor, 1);
                        }
                        previous[0] = current[0];
                        previous[1] = current[1];
                        Slot30_addef0(buffer, OB_ADDR(current), s);
                    }
                }
                reinterpret_cast<Font_adea90*>(mpFont)->EndDraw(buffer);
            }
        }
    }
}
#endif

// RemoveValue... erase point `position` of a series.
// FUNCTION: 0x009b674f
void cGZScatterGraph::Slot17_addef0(uint32_t position, uint32_t series)
{
    if (series == 0xffffffff && RW_adea90().size() == 1) {
        series = 0;
    }
    if (series < RW_adea90().size()) {
        Points_adea90& row = RW_adea90()[series];
        row.erase(row.begin() + position);
    }
}

// SetSeriesPoints(const vector<point>&, series)
// FUNCTION: 0x009b696f
void cGZScatterGraph::Slot18_addef0(uint32_t points, uint32_t series)
{
    uint32_t n = RW_adea90().size();
    if (series == 0xffffffff && n == 1) {
        series = 0;
    }
    if (series < n) {
        RW_adea90()[series] = *OB_PTR(const Points_adea90, points);
    }
}

// LoadDefaultFonts(): the marker font, windings (else dingbats), when the graph has none.
// FUNCTION: 0x009b9226
void cGZScatterGraph::LoadDefaultFonts()
{
    if (!mpFont) {
        FontSystem_adea90* fonts = Fn00913d22_adea90();
        if (fonts) {
            cIGZUnknown* font = fonts->CreateFont(cRZString("windings"), 0, 12, 0, 1);
            if (!font) {
                font = fonts->CreateFont(cRZString("dingbats"), 0, 12, 0, 1);
            }
            if (font) {
                Slot03_addef0(OB_ADDR(font), 0x80000000);
                font->Release();
            }
        }
    }
    cGZGraph::LoadDefaultFonts();
}

// GetAutomaticGraphAreaRect(cRZRect&): the base's area made square (the shorter side wins).
#ifdef OB_DRAFTS
// CLOSE: 0x009b92e4 score 23
void cGZScatterGraph::GetAutomaticGraphAreaRect(uint32_t rect)
{
    int32_t area[4];
    cGZGraph::GetAutomaticGraphAreaRect(OB_ADDR(area));
    int32_t height = area[3] - area[1];
    int32_t width = area[2] - area[0];
    if (height < width) {
        area[2] = height + area[0];
    } else if (height > width) {
        area[3] = area[1] + width;
    }
    *OB_PTR(Rect_adea90, rect) = *reinterpret_cast<Rect_adea90*>(area);
}
#endif

// InsertPoint(const point&, series, position)
// FUNCTION: 0x009b932a
void cGZScatterGraph::Slot16_addef0(uint32_t point, uint32_t series, uint32_t position)
{
    if (series == 0xffffffff && RW_adea90().size() == 1) {
        series = 0;
    }
    if (series < RW_adea90().size()) {
        Points_adea90& row = RW_adea90()[series];
        if (position == 0xffffffff) {
            row.push_back(*OB_PTR(const Point_adea90, point));
        } else {
            row.insert(row.begin() + position, *OB_PTR(const Point_adea90, point));
        }
    }
}

// InsertPoint(x, y, series, position)
// FUNCTION: 0x009b9385
void cGZScatterGraph::Slot15_addef0(uint32_t x, uint32_t y, uint32_t series, uint32_t position)
{
    Point_adea90 p;
    p.x = *reinterpret_cast<float*>(&x);
    p.y = *reinterpret_cast<float*>(&y);
    cGZScatterGraph::Slot16_addef0(OB_ADDR(&p), series, position);
}

// SetPoint(const point&, position, series): at the position, or appended when the position is -1.
// FUNCTION: 0x009b93a9
void cGZScatterGraph::Slot20_addef0(uint32_t point, uint32_t position, uint32_t series)
{
    if (series < RW_adea90().size()) {
        Points_adea90& row = RW_adea90()[series];
        if (position == 0xffffffff) {
            row.push_back(*OB_PTR(const Point_adea90, point));
        } else {
            row[position] = *OB_PTR(const Point_adea90, point);
        }
    }
}

// SetPoint(x, y, position, series)
// FUNCTION: 0x009b93f1
void cGZScatterGraph::Slot19_addef0(uint32_t x, uint32_t y, uint32_t position, uint32_t series)
{
    Point_adea90 p;
    p.x = *reinterpret_cast<float*>(&x);
    p.y = *reinterpret_cast<float*>(&y);
    cGZScatterGraph::Slot20_addef0(OB_ADDR(&p), position, series);
}

// AppendPoints(const vector<point>&, series)
#ifdef OB_DRAFTS
// CLOSE: 0x009b9415 score 66
void cGZScatterGraph::Slot21_addef0(uint32_t points, uint32_t series)
{
    if (series == 0xffffffff && RW_adea90().size() == 1) {
        series = 0;
    }
    if (series < RW_adea90().size()) {
        Points_adea90& row = RW_adea90()[series];
        const Points_adea90* source = OB_PTR(const Points_adea90, points);
        for (uint32_t i = 0; i < source->size(); ++i) {
            row.push_back((*source)[i]);
        }
    }
}
#endif

// SetSeriesName(const cRZString&, index)
// FUNCTION: 0x009ba183
void cGZScatterGraph::Slot10_addef0(uint32_t name, uint32_t index)
{
    if (index == 0xffffffff) {
        for (uint32_t i = 0; i < LK_adea90().size(); ++i) {
            LK_adea90()[i].mName = *OB_PTR(const cRZString, name);
        }
    } else if (index < LK_adea90().size()) {
        LK_adea90()[index].mName = *OB_PTR(const cRZString, name);
    }
}

// SetSeriesLookFrom(const Look&, index)
// FUNCTION: 0x009ba1eb
void cGZScatterGraph::Slot12_addef0(uint32_t look, uint32_t index)
{
    if (index < LK_adea90().size()) {
        LK_adea90()[index].Fn009ba152(OB_PTR(const Look_adea90, look));
    }
}

// FUNCTION: 0x009ba2f4
uint32_t cGZScatterGraph::Slot32_addef0()
{
    return OB_ADDR(static_cast<cUnk00addff8*>(this));
}

// InsertSeries(index): an empty row of points and a default look.
#ifdef OB_DRAFTS
// CLOSE: 0x009bb660 score 17
void cGZScatterGraph::Slot05_addef0(uint32_t index)
{
    if (index == 0xffffffff) {
        Points_adea90 empty;
        RW_adea90().push_back(empty);
        Look_adea90 look;
        LK_adea90().push_back(look);
    } else if (index < RW_adea90().size()) {
        Points_adea90 empty;
        RW_adea90().insert(RW_adea90().begin() + index, empty);
        Look_adea90 look;
        LK_adea90().insert(LK_adea90().begin() + index, look);
    }
}
#endif

// RemoveSeries(index)
// FUNCTION: 0x009bb6fc
void cGZScatterGraph::Slot06_addef0(uint32_t index)
{
    if (index == 0xffffffff) {
        RW_adea90().pop_back();
        LK_adea90().pop_back();
    } else if (index < RW_adea90().size()) {
        RW_adea90().erase(RW_adea90().begin() + index);
        LK_adea90().erase(LK_adea90().begin() + index);
    }
}

// InsertSeriesLook(const Look&, index)
// FUNCTION: 0x009bb75f
void cGZScatterGraph::Slot13_addef0(uint32_t look, uint32_t index)
{
    if (index == 0xffffffff) {
        LK_adea90().push_back(*OB_PTR(const Look_adea90, look));
    }
    if (index < LK_adea90().size()) {
        LK_adea90().insert(LK_adea90().begin() + index, *OB_PTR(const Look_adea90, look));
    }
}

// RemoveSeriesLook(index)
// FUNCTION: 0x009bb7a1
void cGZScatterGraph::Slot14_addef0(uint32_t index)
{
    if (index == 0xffffffff) {
        LK_adea90().pop_back();
    } else if (index < LK_adea90().size()) {
        LK_adea90().erase(LK_adea90().begin() + index);
    }
}

// SetSeriesCount(n): n rows of points, n looks taken from a table of eight in turn.
// FUNCTION: 0x009bbf4b
void cGZScatterGraph::Slot04_addef0(uint32_t count)
{
    RW_adea90().resize(count);
    LK_adea90().resize(count);
    for (uint32_t i = 0; i < count; ++i) {
        LK_adea90()[i].Fn009ba152(&gpBac080_adea90[i & 7]);
    }
}

// ---- the vector members the original instantiated ----

struct PointsVec_adea90 : public Points_adea90 {
    void PushBack(const Point_adea90& point);
    Point_adea90* Erase(Point_adea90* position);
    void Insert(Point_adea90* position, const Point_adea90& point);
};

struct RowsVec_adea90 : public Rows_adea90 {
    void PushBack(const Points_adea90& row);
    Points_adea90* Insert(Points_adea90* position, const Points_adea90& row);
    Points_adea90* Erase(Points_adea90* position);
    void Resize(uint32_t count);
    void ResizeFill(uint32_t count, const Points_adea90& fill);
};

struct LooksVec_adea90 : public Looks_adea90 {
    void PushBack(const Look_adea90& look);
    Look_adea90* Insert(Look_adea90* position, const Look_adea90& look);
    Look_adea90* Erase(Look_adea90* position);
    void ResizeFill(uint32_t count, const Look_adea90& fill);
    void Resize(uint32_t count);
};

#ifdef OB_DRAFTS
// CLOSE: 0x008fe4de score 26
void PointsVec_adea90::PushBack(const Point_adea90& point)
{
    push_back(point);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b65d6 score 24
Point_adea90* PointsVec_adea90::Erase(Point_adea90* position)
{
    return &*erase(iterator(position));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b741e score 65
void PointsVec_adea90::Insert(Point_adea90* position, const Point_adea90& point)
{
    insert(iterator(position), point);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b9c4b score 25
void RowsVec_adea90::PushBack(const Points_adea90& row)
{
    push_back(row);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b9c83 score 72
Points_adea90* RowsVec_adea90::Insert(Points_adea90* position, const Points_adea90& row)
{
    return &*insert(iterator(position), row);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009b73e5 score 27
Points_adea90* RowsVec_adea90::Erase(Points_adea90* position)
{
    return &*erase(iterator(position));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009babdb score 14
void RowsVec_adea90::Resize(uint32_t count)
{
    resize(count);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009ba5f3 score 37
void RowsVec_adea90::ResizeFill(uint32_t count, const Points_adea90& fill)
{
    resize(count, fill);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009babfc score 25
void LooksVec_adea90::PushBack(const Look_adea90& look)
{
    push_back(look);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009baf86 score 69
Look_adea90* LooksVec_adea90::Insert(Look_adea90* position, const Look_adea90& look)
{
    return &*insert(iterator(position), look);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bb029 score 27
Look_adea90* LooksVec_adea90::Erase(Look_adea90* position)
{
    return &*erase(iterator(position));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bbd0e score 37
void LooksVec_adea90::ResizeFill(uint32_t count, const Look_adea90& fill)
{
    resize(count, fill);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009bbdc8 score 17
void LooksVec_adea90::Resize(uint32_t count)
{
    resize(count);
}
#endif
