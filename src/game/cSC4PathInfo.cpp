#include <vector>
#include <cstddef>
#include <cmath>
#include "classes/cSC4PathInfo.h"

// Views of the hash table of paths (at +0x1c) and the object, in the original's layout.
struct Vec3_a99e70 {
    float x;
    float y;
    float z;
};

struct Node_a99e70 {
    Node_a99e70* mpNext;     // 0x0
    uint32_t mnKey;          // 0x4
    Vec3_a99e70* mpPtsBegin; // 0x8: the path's points
    Vec3_a99e70* mpPtsEnd;   // 0xc
    Vec3_a99e70* mpPtsCap;   // 0x10
    float mfLength;          // 0x14
    uint8_t mbFlag;          // 0x18
    uint8_t mPad[3];
};

struct Table_a99e70 {
    uint32_t mFunctor;       // 0x0
    Node_a99e70** mpBegin;   // 0x4
    Node_a99e70** mpEnd;     // 0x8
    Node_a99e70** mpCap;     // 0xc
    uint32_t mnCount;        // 0x10
    // STUB: 0x00540160
    void Fn00540160(const Table_a99e70* other);
    // STUB: 0x005402d0
    Node_a99e70* Fn005402d0(const uint32_t* key);
    Node_a99e70* Find(uint32_t key) const
    {
        uint32_t n = static_cast<uint32_t>(mpEnd - mpBegin);
        Node_a99e70* p = mpBegin[key % n];
        while (p) {
            if (p->mnKey == key) {
                return p;
            }
            p = p->mpNext;
        }
        return 0;
    }
};

struct View_a99e70 {
    void* mpVtables[2];      // 0x0
    uint8_t mPad8[0x14];     // 0x8
    Table_a99e70 mTable;     // 0x1c
    uint8_t mFlags;          // 0x30
    uint8_t mBytes[8];       // 0x31
};

inline uint32_t PackKey_a99e70(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    return ((((a << 8) | static_cast<uint8_t>(d)) << 8 | static_cast<uint8_t>(b)) << 8) | static_cast<uint8_t>(c);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0053cfa0 score 23
bool cSC4PathInfo::QueryInterface(unsigned int iid, void** ppv)
{
    *ppv = 0;
    if (iid == 0x456b8f1d) {
        cGZPersistResource* p = this;
        *ppv = p;
    } else if (iid == 0xa9667793) {
        *ppv = this;
    } else {
        *ppv = 0;
        return false;
    }
    if (*ppv) {
        AddRef();
        return true;
    }
    return false;
}
#endif

// FUNCTION: 0x0053cff0
void cSC4PathInfo::Slot04_a99d78(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Slot03_a99d78(PackKey_a99e70(a, b, c, d), e);
}

// FUNCTION: 0x0053d030
void cSC4PathInfo::Slot11_a99d78(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    Slot10_a99d78(PackKey_a99e70(a, b, c, d));
}

// FUNCTION: 0x0053d060
void cSC4PathInfo::Slot36_a99d78(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    Slot35_a99d78(a, PackKey_a99e70(b | 0x10, c, d, e));
}

#ifdef OB_DRAFTS
// CLOSE: 0x0053d0a0
bool cSC4PathInfo::Slot13_a99d78(uint32_t index)
{
    View_a99e70* self = reinterpret_cast<View_a99e70*>(this);
    if (index) {
        return self->mBytes[index] != 0;
    }
    return ((self->mFlags >> 1) & 1) != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053d160 score ?
Vec3_a99e70 ComputeLineToRectIntersection(const float* rect, uint32_t flags, const Vec3_a99e70* p0, const Vec3_a99e70* p1, uint8_t* side)
{
    float t = 0.0f;
    if (flags & 1) {
        float s = (rect[0] - p0->x) / (p1->x - p0->x);
        if (!(s < t)) {
            *side = 0;
            t = s;
        }
    }
    if (flags & 2) {
        float s = (rect[1] - p0->z) / (p1->z - p0->z);
        if (!(s < t)) {
            *side = 1;
            t = s;
        }
    }
    if (flags & 4) {
        float s = (rect[2] - p0->x) / (p1->x - p0->x);
        if (!(s < t)) {
            *side = 2;
            t = s;
        }
    }
    if (flags & 8) {
        float s = (rect[3] - p0->z) / (p1->z - p0->z);
        if (!(s < t)) {
            *side = 3;
            t = s;
        }
    }
    Vec3_a99e70 r;
    float dx = (p1->x - p0->x) * t;
    float dy = (p1->y - p0->y) * t;
    float dz = (p1->z - p0->z) * t;
    r.x = dx + p0->x;
    r.y = dy + p0->y;
    r.z = dz + p0->z;
    return r;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053d280 score ?  (sums the lengths of a path's segments into its length field)
void Fn0053d280(Node_a99e70* path)
{
    float total = 0.0f;
    Vec3_a99e70* prev = path->mpPtsBegin;
    Vec3_a99e70* p = prev + 1;
    while (p != path->mpPtsEnd) {
        float dx = p->x - prev->x;
        float dy = p->y - prev->y;
        float dz = p->z - prev->z;
        prev = p;
        ++p;
        total += std::sqrt(dx * dx + dy * dy + dz * dz);
    }
    path->mfLength = total;
}
#endif

struct Vec3Vector_a99e70 {
    Vec3_a99e70* mpBegin;
    Vec3_a99e70* mpEnd;
    Vec3_a99e70* mpCap;
};

// STUB: 0x005d74d0
bool Fn005d74d0(const float* a, const float* b, const float* c, const float* d, float* out);
// STUB: 0x005d6fc0
float Fn005d6fc0(const float* a, const float* b);

#ifdef OB_DRAFTS
// CLOSE: 0x0053d2e0 score ?  (the original returns the index of the segment in eax; the base slot is declared void)
void cSC4PathInfo::Slot19_a99d78(uint32_t pointArg, uint32_t pathArg)
{
    Vec3_a99e70* pt = reinterpret_cast<Vec3_a99e70*>(pointArg);
    Vec3Vector_a99e70* pts = reinterpret_cast<Vec3Vector_a99e70*>(pathArg);
    if (!pts || pts->mpBegin == pts->mpEnd) {
        return;
    }
    Vec3_a99e70* prev = pts->mpBegin;
    int32_t index = 0;
    for (Vec3_a99e70* p = prev + 1; p != pts->mpEnd; ++p) {
        float dx = p->x - prev->x;
        float dy = p->y - prev->y;
        float dz = p->z - prev->z;
        float len2 = dz * dz + dy * dy + dx * dx;
        if (len2 > 0.0f) {
            float inv = 1.0f / std::sqrt(len2);
            dx = dx * inv;
            dz = dz * inv;
        }
        float a[2] = { pt->x - dz, pt->z + dx };
        float b[2] = { pt->x + dz, pt->z - dx };
        float s[2] = { prev->x, prev->z };
        float e[2] = { p->x, p->z };
        float hit[2];
        if (Fn005d74d0(b, a, s, e, hit)) {
            pt->x = hit[0];
            pt->z = hit[1];
            float d1 = Fn005d6fc0(s, hit);
            float d2 = Fn005d6fc0(s, e);
            float ratio = 0.0f;
            if (d2 > 0.0001f) {
                ratio = d1 / d2;
            }
            pt->y = (p->y - prev->y) * ratio + prev->y;
            return;
        }
        prev = p;
        ++index;
    }
    Vec3_a99e70* first = pts->mpBegin;
    Vec3_a99e70* last = pts->mpEnd - 1;
    float fx = pt->x - first->x;
    float fy = pt->y - first->y;
    float fz = pt->z - first->z;
    float lx = pt->x - last->x;
    float ly = pt->y - last->y;
    float lz = pt->z - last->z;
    if (std::sqrt(fx * fx + fy * fy + fz * fz) < std::sqrt(lx * lx + ly * ly + lz * lz)) {
        *pt = *first;
    } else {
        *pt = *last;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053d600 score ?  (copies a range of points backwards into a destination)
void Fn0053d600(Vec3_a99e70* last, Vec3_a99e70* first, Vec3_a99e70* dest)
{
    while (last != first) {
        --last;
        *dest = *last;
        ++dest;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053d6c0 score ?
bool cSC4PathInfo::Slot18_a99d78(uint32_t ptsArg, uint32_t pointArg, uint32_t outArg, uint32_t indexArg)
{
    Vec3Vector_a99e70* pts = reinterpret_cast<Vec3Vector_a99e70*>(ptsArg);
    Vec3_a99e70* point = reinterpret_cast<Vec3_a99e70*>(pointArg);
    Vec3_a99e70* out = reinterpret_cast<Vec3_a99e70*>(outArg);
    int32_t* pIndex = reinterpret_cast<int32_t*>(indexArg);
    bool found = false;
    float best = 3.4028235e+38f;
    uint32_t count = static_cast<uint32_t>(pts->mpEnd - pts->mpBegin);
    if (*pIndex < 0 || static_cast<uint32_t>(*pIndex) >= count) {
        *pIndex = 0;
    }
    Vec3_a99e70* p = pts->mpBegin;
    float dx = pts->mpEnd[-1].x - p->x;
    float dy = pts->mpEnd[-1].y - p->y;
    float dz = pts->mpEnd[-1].z - p->z;
    float inv = 1.0f / std::sqrt(dz * dz + dy * dy + dx * dx);
    float dirX = dx * inv;
    float dirY = dy * inv;
    float dirZ = dz * inv;
    int32_t i = 0;
    for (; p != pts->mpEnd; ++p, ++i) {
        if (i < *pIndex) {
            continue;
        }
        float vx = p->x - point->x;
        float vy = p->y - point->y;
        float vz = p->z - point->z;
        if (!Slot16_a99d78()) {
            vy = 0.0f;
        }
        float len = std::sqrt(vz * vz + vx * vx + vy * vy);
        if (len > 0.0f) {
            float k = 1.0f / len;
            float dot = dirY * (vy * k) + dirX * (vx * k) + dirZ * (vz * k);
            if (dot > 0.0f) {
                found = true;
                if (len < best) {
                    *out = *p;
                    best = len;
                    *pIndex = i;
                }
            }
        }
    }
    return found;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053dd30 score ?  (the original returns a pointer to the path; the base slot is declared void)
void cSC4PathInfo::Slot03_a99d78(uint32_t key, uint32_t outLength)
{
    View_a99e70* self = reinterpret_cast<View_a99e70*>(this);
    Node_a99e70* node = self->mTable.Find(key);
    float* pLength = reinterpret_cast<float*>(outLength);
    if (node && pLength) {
        *pLength = node->mfLength;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053dd90 score ?  (the original leaves the length in st0; the base slot is declared void)
void cSC4PathInfo::Slot10_a99d78(uint32_t key)
{
    View_a99e70* self = reinterpret_cast<View_a99e70*>(this);
    Node_a99e70* node = self->mTable.Find(key);
    float length = 0.0f;
    if (node) {
        length = node->mfLength;
    }
    (void)length;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053dde0 score ?  (the first key not in the table: raises the last byte while keys exist)
uint32_t Fn0053dde0_a99e70(View_a99e70* self, uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t key = PackKey_a99e70(a, b, c, d);
    if (self->mTable.Find(key)) {
        while (b < 0x1a) {
            ++b;
            key = PackKey_a99e70(a, b, c, d);
            if (!self->mTable.Find(key)) {
                break;
            }
        }
    }
    return key;
}
#endif

// FUNCTION: 0x005403a0
uint32_t cSC4PathInfo::Slot16_a99d78()
{
    return reinterpret_cast<View_a99e70*>(this)->mFlags & 1;
}

#ifdef OB_DRAFTS
// CLOSE: 0x005403b0 score ?
void cSC4PathInfo::Slot17_a99d78(uint32_t on)
{
    View_a99e70* self = reinterpret_cast<View_a99e70*>(this);
    uint8_t flags = self->mFlags;
    if (static_cast<uint8_t>(on)) {
        self->mFlags = flags | 1;
    } else {
        self->mFlags = flags & 0xfe;
    }
}
#endif

// Walking the hash table's nodes the way the original's iterator does.
inline Node_a99e70* NextNode_a99e70(const Table_a99e70* t, Node_a99e70* n)
{
    Node_a99e70* next = n->mpNext;
    if (next) {
        return next;
    }
    uint32_t count = static_cast<uint32_t>(t->mpEnd - t->mpBegin);
    for (uint32_t i = n->mnKey % count + 1; i < count; ++i) {
        if (t->mpBegin[i]) {
            return t->mpBegin[i];
        }
    }
    return 0;
}

inline Node_a99e70* FirstNode_a99e70(const Table_a99e70* t)
{
    uint32_t count = static_cast<uint32_t>(t->mpEnd - t->mpBegin);
    for (uint32_t i = 0; i < count; ++i) {
        if (t->mpBegin[i]) {
            return t->mpBegin[i];
        }
    }
    return 0;
}

inline Vec3Vector_a99e70* FindPoints_a99e70(cSC4PathInfo* self, uint32_t key, float* outLength)
{
    Node_a99e70* node = reinterpret_cast<View_a99e70*>(self)->mTable.Find(key);
    if (!node) {
        return 0;
    }
    *outLength = node->mfLength;
    return reinterpret_cast<Vec3Vector_a99e70*>(&node->mpPtsBegin);
}

struct Random_a99e70 {
    uint8_t mData[0x14];
    // STUB: 0x00913a5c
    void Init(uint32_t seed);
    // STUB: 0x00913761
    double RandomDoubleRange(double lo, double hi);
    // STUB: 0x00913696
    uint32_t RandomUint32();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0053d890 score ?  (the midpoint of a polyline)
bool cSC4PathInfo::Slot22_a99d78(uint32_t ptsArg, uint32_t outArg)
{
    Vec3Vector_a99e70* pts = reinterpret_cast<Vec3Vector_a99e70*>(ptsArg);
    Vec3_a99e70* out = reinterpret_cast<Vec3_a99e70*>(outArg);
    if (!pts) {
        return false;
    }
    uint32_t count = static_cast<uint32_t>(pts->mpEnd - pts->mpBegin);
    if (count == 0) {
        return false;
    }
    float total = 0.0f;
    Vec3_a99e70 prev = pts->mpBegin[0];
    for (uint32_t i = 1; i != count; ++i) {
        float dx = pts->mpBegin[i].x - prev.x;
        float dy = pts->mpBegin[i].y - prev.y;
        float dz = pts->mpBegin[i].z - prev.z;
        total = std::sqrt(dx * dx + dy * dy + dz * dz) + total;
        prev = pts->mpBegin[i];
    }
    prev = pts->mpBegin[0];
    bool found = false;
    float walked = 0.0f;
    for (uint32_t i = 1; i != count; ++i) {
        float dx = pts->mpBegin[i].x - prev.x;
        float dy = pts->mpBegin[i].y - prev.y;
        float dz = pts->mpBegin[i].z - prev.z;
        float walkedNext = std::sqrt(dx * dx + dy * dy + dz * dz) + walked;
        if (walkedNext < total * 0.5f) {
            prev = pts->mpBegin[i];
            walked = walkedNext;
        } else {
            float rest = total * 0.5f - walked;
            float inv = 1.0f / std::sqrt(dz * dz + dy * dy + dx * dx);
            out->x = rest * (dx * inv) + prev.x;
            out->y = rest * (dy * inv) + prev.y;
            out->z = rest * (dz * inv) + prev.z;
            found = true;
        }
    }
    return found;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053da80 score ?  (a random point along a path)
bool cSC4PathInfo::Slot23_a99d78(uint32_t key, uint32_t outArg)
{
    Vec3_a99e70* out = reinterpret_cast<Vec3_a99e70*>(outArg);
    float length = 0.0f;
    Vec3Vector_a99e70* pts = reinterpret_cast<Vec3Vector_a99e70*>(FindPoints_a99e70(this, key, &length));
    if (pts) {
        Random_a99e70 rnd;
        rnd.Init(0xffffffff);
        float dist = static_cast<float>(rnd.RandomDoubleRange(0.0, length));
        uint32_t count = static_cast<uint32_t>(pts->mpEnd - pts->mpBegin);
        for (uint32_t i = 0; i < count - 1; ++i) {
            float dx = pts->mpBegin[i + 1].x - pts->mpBegin[i].x;
            float dy = pts->mpBegin[i + 1].y - pts->mpBegin[i].y;
            float dz = pts->mpBegin[i + 1].z - pts->mpBegin[i].z;
            float seg = std::sqrt(dx * dx + dy * dy + dz * dz);
            if (dist < seg) {
                float inv = 1.0f / std::sqrt(dz * dz + dy * dy + dx * dx);
                out->x = dist * (dx * inv) + pts->mpBegin[i].x;
                out->y = dist * (dy * inv) + pts->mpBegin[i].y;
                out->z = dist * (dz * inv) + pts->mpBegin[i].z;
                return true;
            }
            dist = dist - seg;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053e550 score ?  (counts the paths whose key fits a pattern; 0xff = any)
uint32_t cSC4PathInfo::Slot34_a99d78(uint32_t type, uint32_t a, uint32_t b, uint32_t c)
{
    View_a99e70* self = reinterpret_cast<View_a99e70*>(this);
    uint32_t count = 0;
    uint32_t mask = 0;
    if (type == 0) {
        mask = 0x0f000000;
    }
    uint8_t ua = static_cast<uint8_t>(a);
    uint8_t ub = static_cast<uint8_t>(b);
    uint8_t uc = static_cast<uint8_t>(c);
    if (ua == 0xff) {
        mask |= 0xff00;
    }
    if (ub == 0xff) {
        mask |= 0xff;
    }
    if (uc == 0xff) {
        mask |= 0xff0000;
    }
    uint32_t want = ((((type | 0x10) << 8 | uc) << 8) | ua) << 8 | ub;
    for (Node_a99e70* n = FirstNode_a99e70(&self->mTable); n; n = NextNode_a99e70(&self->mTable, n)) {
        uint32_t k = n->mnKey;
        uint32_t wild = 0;
        if (static_cast<uint8_t>(k >> 8) == 0xff) {
            wild = 0xff00;
        }
        if (static_cast<uint8_t>(k) == 0xff) {
            wild |= 0xff;
        }
        if (((wild | k) | mask) == ((wild | want) | mask)) {
            ++count;
        }
    }
    return count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053e650 score ?
uint32_t cSC4PathInfo::Slot33_a99d78(uint32_t key)
{
    View_a99e70* self = reinterpret_cast<View_a99e70*>(this);
    uint32_t count = 0;
    uint32_t mask = 0;
    if (static_cast<uint8_t>(key >> 16) == 0xff) {
        mask = 0xff0000;
    }
    uint32_t want = (key & 0x0fffffff) | 0x10000000;
    for (Node_a99e70* n = FirstNode_a99e70(&self->mTable); n; n = NextNode_a99e70(&self->mTable, n)) {
        uint32_t k = n->mnKey;
        uint32_t wild = 0;
        if (static_cast<uint8_t>(k >> 8) == 0xff) {
            wild = 0xff00;
        }
        if (static_cast<uint8_t>(k) == 0xff) {
            wild |= 0xff;
        }
        if ((k | mask) == (want | mask) || (wild | k) == (wild | want)) {
            ++count;
        }
    }
    return count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053e740 score ?  (copies the first point of the path with this key, or of the first one that fits it)
bool cSC4PathInfo::Slot35_a99d78(uint32_t key, uint32_t outArg)
{
    View_a99e70* self = reinterpret_cast<View_a99e70*>(this);
    Vec3_a99e70* out = reinterpret_cast<Vec3_a99e70*>(outArg);
    Node_a99e70* exact = self->mTable.Find(key);
    if (exact) {
        *out = *exact->mpPtsBegin;
        return true;
    }
    uint32_t want = (key & 0x0fffffff) | 0x10000000;
    for (Node_a99e70* n = FirstNode_a99e70(&self->mTable); n; n = NextNode_a99e70(&self->mTable, n)) {
        uint32_t k = n->mnKey;
        uint32_t m = 0xffffffff;
        if (static_cast<uint8_t>(k >> 8) == 0xff) {
            m = 0xffff00ff;
        }
        if (static_cast<uint8_t>(k) == 0xff) {
            m &= 0xffffff00;
        }
        if (static_cast<uint8_t>(key >> 8) == 0xff) {
            m &= 0xffff00ff;
        }
        if (static_cast<uint8_t>(outArg) == 0xff) {
            m &= 0xffffff00;
        }
        if ((m & k) == (m & want)) {
            *out = *n->mpPtsBegin;
            return true;
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053eaa0 score ?
uint32_t cSC4PathInfo::Slot12_a99d78(uint32_t a, uint32_t b, uint32_t c)
{
    View_a99e70* self = reinterpret_cast<View_a99e70*>(this);
    uint32_t count = 0;
    uint32_t want = (((a << 16) | static_cast<uint8_t>(b)) << 8) | static_cast<uint8_t>(c);
    for (Node_a99e70* n = FirstNode_a99e70(&self->mTable); n; n = NextNode_a99e70(&self->mTable, n)) {
        if ((n->mnKey & 0xff00ffff) == want) {
            ++count;
        }
    }
    return count;
}
#endif

struct KeyVec_a99e70 {
    uint32_t* mpBegin;
    uint32_t* mpEnd;
    uint32_t* mpCap;
    // STUB: 0x0051ca60
    void Fn0051ca60(uint32_t* pos, const uint32_t* value, uint32_t n, uint32_t a, uint32_t b);
    void PushBack(uint32_t value)
    {
        if (mpEnd != mpCap) {
            if (mpEnd) {
                *mpEnd = value;
            }
            ++mpEnd;
        } else {
            Fn0051ca60(mpEnd, &value, 1, 1, 1);
        }
    }
};

// The wildcard mask of a (type, a, b) pattern where 0xff means any.
inline uint32_t PatternMask_a99e70(uint32_t a, uint32_t b)
{
    uint32_t mask = 0xff00ffff;
    if (static_cast<uint8_t>(a) == 0xff) {
        mask = 0xff0000ff;
    }
    if (static_cast<uint8_t>(b) == 0xff) {
        mask &= 0xffffff00;
    }
    return mask;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0053e150 score ?  (the original takes six arguments; the base slot is declared without any)
// Collects the keys of the paths that fit the pattern and whose first point is nearest to a position.
void Fn0053e150Draft_a99e70(cSC4PathInfo* self, uint32_t type, uint32_t a, uint32_t b, const Vec3_a99e70* pos, KeyVec_a99e70* out)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    float best = 3.4028235e+38f;
    uint32_t mask = PatternMask_a99e70(a, b);
    uint32_t want = ((type << 16 | static_cast<uint8_t>(a)) << 8 | static_cast<uint8_t>(b)) & mask;
    out->mpBegin = 0;
    out->mpEnd = 0;
    out->mpCap = 0;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        if ((n->mnKey & mask) != want) {
            continue;
        }
        float dx = n->mpPtsBegin->x - pos->x;
        float dy = n->mpPtsBegin->y - pos->y;
        float dz = n->mpPtsBegin->z - pos->z;
        float d = std::sqrt(dx * dx + dy * dy + dz * dz);
        if (d <= best) {
            if (d < best) {
                out->mpEnd = out->mpBegin;
            }
            out->PushBack(n->mnKey);
            best = d;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053e350 score ?
uint32_t cSC4PathInfo::Slot07_a99d78(uint32_t type, uint32_t a, uint32_t b, uint32_t posArg, uint32_t outArg, uint32_t maxDist)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(this);
    const Vec3_a99e70* pos = reinterpret_cast<const Vec3_a99e70*>(posArg);
    KeyVec_a99e70* out = reinterpret_cast<KeyVec_a99e70*>(outArg);
    float limit = *reinterpret_cast<float*>(&maxDist);
    uint32_t mask = PatternMask_a99e70(a, b);
    uint32_t want = ((type << 16 | static_cast<uint8_t>(a)) << 8 | static_cast<uint8_t>(b)) & mask;
    uint32_t found = 0;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        if ((n->mnKey & mask) != want) {
            continue;
        }
        float dx = n->mpPtsBegin->x - pos->x;
        float dy = n->mpPtsBegin->y - pos->y;
        float dz = n->mpPtsBegin->z - pos->z;
        if (std::sqrt(dx * dx + dy * dy + dz * dz) <= limit) {
            out->PushBack(n->mnKey);
            ++found;
        }
    }
    return found;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053e870 score ?  (the original takes three arguments; the base slot is declared without any)
// Collects the keys of the paths of one type and one direction into a vector.
uint32_t Fn0053e870Draft_a99e70(cSC4PathInfo* self, KeyVec_a99e70* out, uint32_t type, uint32_t a)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    uint32_t count = 0;
    out->mpEnd = out->mpBegin;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t k = n->mnKey;
        if ((k & 0xf0000000) == 0 && ((k >> 24) & 0xf) == type && static_cast<uint8_t>(k >> 8) == static_cast<uint8_t>(a)) {
            out->PushBack(k);
            ++count;
        }
    }
    return count;
}
#endif

struct Target_a99e70 {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Pad28() = 0;
    virtual void Pad29() = 0;
    virtual void Pad30() = 0;
    virtual void Pad31() = 0;
    virtual void Pad32() = 0;
    virtual void Pad33() = 0;
    virtual void Pad34() = 0;
    virtual void Pad35() = 0;
    virtual void Pad36() = 0;
    virtual void Pad37() = 0;
    virtual void Pad38() = 0;
    virtual void Pad39() = 0;
    virtual void Pad40() = 0;
    virtual void Pad41() = 0;
    virtual void Pad42() = 0;
    virtual void Pad43() = 0;
    virtual void Pad44() = 0;
    virtual void Pad45() = 0;
    virtual void Pad46() = 0;
    virtual void Pad47() = 0;
    virtual void Pad48() = 0;
    virtual void Pad49() = 0;
    virtual void Pad50() = 0;
    virtual void Pad51() = 0;
    virtual void Pad52() = 0;
    virtual void Pad53() = 0;
    virtual void Slot54(uint32_t a, uint32_t b, uint32_t c) = 0;
};

#ifdef OB_DRAFTS
// CLOSE: 0x0053ebb0 score ?
void cSC4PathInfo::Slot27_a99d78(uint32_t obj)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(this);
    Target_a99e70* target = reinterpret_cast<Target_a99e70*>(obj);
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t k = n->mnKey;
        if ((k & 0xf0000000) == 0) {
            target->Slot54((k >> 24) & 0xf, k >> 8, k);
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053ec40 score ?  (the original takes the offset (three floats) as arguments; the base slot is declared without any)
void Fn0053ec40Draft_a99e70(cSC4PathInfo* self, float dx, float dy, float dz)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        for (Vec3_a99e70* p = n->mpPtsBegin; p != n->mpPtsEnd; ++p) {
            p->x = dx + p->x;
            p->y = dy + p->y;
            p->z = dz + p->z;
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053e990 score ?  (three arguments in the original, the base slot has none)
uint32_t Fn0053e990Draft_a99e70(cSC4PathInfo* self, KeyVec_a99e70* out, uint32_t type, uint32_t a)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    uint32_t count = 0;
    out->mpEnd = out->mpBegin;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t k = n->mnKey;
        if ((k & 0xf0000000) == 0 && ((k >> 24) & 0xf) == type && static_cast<uint8_t>(k) == static_cast<uint8_t>(a)) {
            out->PushBack(k);
            ++count;
        }
    }
    return count;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053ece0 score ?  (the original takes (point, type, out key) and returns the segment index; the base slot has none)
// Snaps a point onto the nearest path of a type. The index Slot19 returns in eax is not reachable through its void declaration.
int32_t Fn0053ece0Draft_a99e70(cSC4PathInfo* self, Vec3_a99e70* point, uint32_t type, uint32_t* outKey)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    Vec3_a99e70 start = *point;
    float best = 3.4028235e+38f;
    int32_t bestIndex = -1;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t k = n->mnKey;
        if ((k & 0xf0000000) != 0) {
            continue;
        }
        if (type && ((k >> 24) & 0xf) != type) {
            continue;
        }
        Vec3_a99e70 snapped = start;
        self->Slot19_a99d78(OB_ADDR(&snapped), OB_ADDR(&n->mpPtsBegin));
        int32_t index = 0;
        if (index != -1) {
            float dx = start.x - snapped.x;
            float dy = start.y - snapped.y;
            float dz = start.z - snapped.z;
            float d = std::sqrt(dx * dx + dy * dy + dz * dz);
            if (d < best) {
                *point = snapped;
                best = d;
                bestIndex = index;
                if (outKey) {
                    *outKey = k;
                }
            }
        }
    }
    return bestIndex;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053ee90 score ?  (four arguments in the original: type, point, out point, out key)
// The midpoint (Slot22) of the nearest path of a type.
bool Fn0053ee90Draft_a99e70(cSC4PathInfo* self, uint32_t type, const Vec3_a99e70* point, Vec3_a99e70* out, uint32_t* outKey)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    bool found = false;
    float best = 3.4028235e+38f;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t k = n->mnKey;
        if (type && ((k >> 24) & 0xf) != type) {
            continue;
        }
        Vec3_a99e70 mid = *point;
        if (!self->Slot22_a99d78(OB_ADDR(&n->mpPtsBegin), OB_ADDR(&mid))) {
            continue;
        }
        float dx = point->x - mid.x;
        float dy = point->y - mid.y;
        float dz = point->z - mid.z;
        if (!self->Slot16_a99d78()) {
            dy = 0.0f;
        }
        float d = std::sqrt(dz * dz + dy * dy + dx * dx);
        if (d > best) {
            continue;
        }
        best = d;
        *out = mid;
        if (outKey) {
            *outKey = k;
        }
        found = true;
    }
    return found;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053f000 score ?
bool cSC4PathInfo::Slot38_a99d78(uint32_t outArg, uint32_t type, uint32_t a)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(this);
    KeyVec_a99e70* out = reinterpret_cast<KeyVec_a99e70*>(outArg);
    out->mpEnd = out->mpBegin;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t k = n->mnKey;
        if (static_cast<uint8_t>(k >> 8) == static_cast<uint8_t>(a) && ((k >> 24) & 0xf) == type && (n->mbFlag & 1)) {
            out->PushBack(k);
        }
    }
    return out->mpBegin != out->mpEnd;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053f100 score ?  (the original returns the key it searched for; the center of the bounds of the matching paths picks a path)
uint32_t cSC4PathInfo::Slot37_a99d78(uint32_t type, uint32_t a, uint32_t b)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(this);
    uint32_t key = ((type << 16 | static_cast<uint8_t>(a)) << 8) | static_cast<uint8_t>(b);
    uint32_t pattern = key & 0xff00ffff;
    bool any = false;
    float minX = 0.0f;
    float minZ = 0.0f;
    float maxX = 0.0f;
    float maxZ = 0.0f;
    std::vector<Node_a99e70*> hits;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        if ((n->mnKey & 0xff00ffff) != pattern || n->mpPtsBegin == n->mpPtsEnd) {
            continue;
        }
        hits.push_back(n);
        Vec3_a99e70* p = n->mpPtsBegin;
        if (!any) {
            minX = maxX = p->x;
            minZ = maxZ = p->z;
            any = true;
        } else {
            if (p->x < minX) {
                minX = p->x;
            }
            if (p->z < minZ) {
                minZ = p->z;
            }
            if (p->x > maxX) {
                maxX = p->x;
            }
            if (p->z > maxZ) {
                maxZ = p->z;
            }
        }
    }
    if (any) {
        float dx = maxX - minX;
        float dz = maxZ - minZ;
        bool alongX = !(std::fabs(dx) < std::fabs(dz));
        float center = dz * 0.5f + minZ;
        if (alongX) {
            center = dx * 0.5f + minX;
        }
        float bestDiff = 3.4028235e+38f;
        for (size_t i = 0; i < hits.size(); ++i) {
            float c = alongX ? hits[i]->mpPtsBegin->x : hits[i]->mpPtsBegin->z;
            float diff = std::fabs(c - center);
            if (diff < bestDiff) {
                bestDiff = diff;
            }
        }
    }
    return key;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053f6c0 score ?  (one argument in the original, a region object; the base slot has none)
// Flags the paths whose end points are off the edges of the region and returns false then.
bool Fn0053f6c0Draft_a99e70(cSC4PathInfo* self, Target_a99e70* region)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    bool ok = true;
    float rect[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    (void)region;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t k = n->mnKey;
        if ((k & 0xf0000000) != 0) {
            continue;
        }
        const Vec3_a99e70* first = n->mpPtsBegin;
        const Vec3_a99e70* last = n->mpPtsEnd - 1;
        uint32_t side = static_cast<uint8_t>(k >> 8);
        if (side <= 3) {
            float d = (side & 1) ? first->z - rect[side] : first->x - rect[side];
            if (std::fabs(d) >= 0.001f) {
                n->mbFlag |= 2;
                ok = false;
            }
        }
        side = static_cast<uint8_t>(k);
        if (side <= 3) {
            float d = (side & 1) ? last->z - rect[side] : last->x - rect[side];
            if (std::fabs(d) >= 0.001f) {
                n->mbFlag |= 2;
                ok = false;
            }
        }
    }
    return ok;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053fa40 score ?  (picks a random path among those that fit; the original returns a pointer, the base slot a uint32_t)
uint32_t cSC4PathInfo::Slot08_a99d78(uint32_t type, uint32_t a, uint32_t b, uint32_t unused, uint32_t outArg)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(this);
    uint32_t pattern = (((type << 16) | static_cast<uint8_t>(a)) << 8) | static_cast<uint8_t>(b);
    uint32_t* out = reinterpret_cast<uint32_t*>(outArg);
    std::vector<Node_a99e70*> hits;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        if ((n->mnKey & 0xff00ffff) == pattern) {
            hits.push_back(n);
        }
    }
    Node_a99e70* chosen = 0;
    if (!hits.empty()) {
        Random_a99e70 rnd;
        rnd.Init(0xffffffff);
        chosen = hits[rnd.RandomUint32() % hits.size()];
        if (out) {
            *out = chosen->mnKey;
        }
    }
    (void)unused;
    return chosen ? chosen->mnKey : 0;
}
#endif

struct Copy_a99e70 {
    // STUB: 0x005408b0
    void* Fn005408b0(const void* other);
};

// STUB: 0x0090cf9a
void* Fn0090cf9a_a99e70(void* pool);

#ifdef OB_DRAFTS
// CLOSE: 0x00540910 score 23  (allocates a copy from the class's pool and gives it a reference; the pointer return is a uint32_t in the base slot)
uint32_t cSC4PathInfo::Slot24_a99d78()
{
    Copy_a99e70* mem = static_cast<Copy_a99e70*>(Fn0090cf9a_a99e70(0));
    cSC4PathInfo* copy = static_cast<cSC4PathInfo*>(mem->Fn005408b0(this));
    copy->AddRef();
    return OB_ADDR(copy);
}
#endif

// STUB: 0x005d74d0
// (declared above: segment against segment in 2D)
// STUB: 0x005d6fc0
// (declared above: length of a 2D line)

#ifdef OB_DRAFTS
// CLOSE: 0x0053f360 score ?  (GetPathIntersection: the first crossing of a ray with the paths that run the same way)
bool cSC4PathInfo::Slot39_a99d78(uint32_t key, uint32_t startArg, uint32_t dirArg, uint32_t threshold, uint32_t outPointArg, uint32_t outKeyArg, uint32_t outIndexArg)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(this);
    const Vec3_a99e70* start = reinterpret_cast<const Vec3_a99e70*>(startArg);
    const Vec3_a99e70* dir = reinterpret_cast<const Vec3_a99e70*>(dirArg);
    float minDot = *reinterpret_cast<float*>(&threshold);
    Vec3_a99e70* outPoint = reinterpret_cast<Vec3_a99e70*>(outPointArg);
    uint32_t* outKey = reinterpret_cast<uint32_t*>(outKeyArg);
    int32_t* outIndex = reinterpret_cast<int32_t*>(outIndexArg);
    Vec3_a99e70 hitPoint;
    hitPoint.x = dir->x * 16.0f * 3.0f + start->x;
    hitPoint.y = dir->y * 16.0f * 3.0f + start->y;
    hitPoint.z = dir->z * 16.0f * 3.0f + start->z;
    float rayStart[2] = { start->x, start->z };
    float rayEnd[2] = { hitPoint.x, hitPoint.z };
    bool found = false;
    uint32_t foundKey = 0;
    Node_a99e70* mine = v->mTable.Find(key);
    if (mine) {
        Vec3_a99e70 myDir;
        myDir.x = mine->mpPtsEnd[-1].x - mine->mpPtsBegin->x;
        myDir.y = mine->mpPtsEnd[-1].y - mine->mpPtsBegin->y;
        myDir.z = mine->mpPtsEnd[-1].z - mine->mpPtsBegin->z;
        float inv = 1.0f / std::sqrt(myDir.x * myDir.x + myDir.y * myDir.y + myDir.z * myDir.z);
        myDir.x *= inv;
        myDir.y *= inv;
        myDir.z *= inv;
        float best = 3.4028235e+38f;
        for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
            uint32_t k = n->mnKey;
            if (k == key || (k >> 28) != (key >> 28) || (key & 0xf000000) != (k & 0xf000000)) {
                continue;
            }
            Vec3_a99e70 d;
            d.x = n->mpPtsEnd[-1].x - n->mpPtsBegin->x;
            d.y = n->mpPtsEnd[-1].y - n->mpPtsBegin->y;
            d.z = n->mpPtsEnd[-1].z - n->mpPtsBegin->z;
            float dinv = 1.0f / std::sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
            d.x *= dinv;
            d.y *= dinv;
            d.z *= dinv;
            if (minDot > d.x * myDir.x + d.y * myDir.y + d.z * myDir.z) {
                continue;
            }
            Vec3_a99e70* prev = n->mpPtsBegin;
            int32_t index = 0;
            for (Vec3_a99e70* p = prev + 1; p != n->mpPtsEnd; ++p, ++index) {
                float segA[2] = { prev->x, prev->z };
                float segB[2] = { p->x, p->z };
                float cross[2];
                if (Fn005d74d0(segA, segB, rayStart, rayEnd, cross)) {
                    float len = Fn005d6fc0(cross, rayStart);
                    if (len < best) {
                        hitPoint.x = cross[0];
                        hitPoint.y = start->y;
                        hitPoint.z = cross[1];
                        *outIndex = index;
                        found = true;
                        best = len;
                        foundKey = k;
                    }
                }
                prev = p;
            }
        }
        if (found) {
            *outKey = foundKey;
            *outPoint = hitPoint;
        }
    }
    return found;
}
#endif

// The region code of a point against a rectangle (left 1, top 2, right 4, bottom 8).
inline uint32_t RegionCode_a99e70(const float* rect, const Vec3_a99e70& p)
{
    uint32_t code = static_cast<uint32_t>(p.x < rect[0]);
    if (!(p.z >= rect[1])) {
        code += 2;
    }
    if (p.x > rect[2]) {
        code += 4;
    }
    if (p.z > rect[3]) {
        code += 8;
    }
    return code;
}

// STUB: 0x0053dde0
uint32_t Fn0053dde0_stub_a99e70(void* self, uint32_t a, uint32_t b, uint32_t c, uint32_t d);

#ifdef OB_DRAFTS
// CLOSE: 0x00541ae0 score ?  (OffsetAndScissor: a copy of the paths, moved and cut to a rectangle; four arguments, the offset and the rectangle)
// The rectangle is clipped per path: points inside are kept, a crossing adds the point on the edge.
uint32_t cSC4PathInfo::Slot29_a99d78(uint32_t dxArg, uint32_t dyArg, uint32_t dzArg, uint32_t rectArg)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(this);
    float dx = *reinterpret_cast<float*>(&dxArg);
    float dy = *reinterpret_cast<float*>(&dyArg);
    float dz = *reinterpret_cast<float*>(&dzArg);
    const float* rect = reinterpret_cast<const float*>(rectArg);
    Copy_a99e70* mem = static_cast<Copy_a99e70*>(Fn0090cf9a_a99e70(0));
    cSC4PathInfo* result = static_cast<cSC4PathInfo*>(mem->Fn005408b0(0));
    result->AddRef();
    result->Slot17_a99d78(Slot16_a99d78());
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        std::vector<Vec3_a99e70> kept;
        uint8_t entryEdge = 0;
        uint8_t exitEdge = 0;
        bool havePrev = false;
        uint32_t prevCode = 0;
        Vec3_a99e70 prev = { 0.0f, 0.0f, 0.0f };
        for (Vec3_a99e70* src = n->mpPtsBegin; src != n->mpPtsEnd; ++src) {
            Vec3_a99e70 cur;
            cur.x = dx + src->x;
            cur.y = dy + src->y;
            cur.z = dz + src->z;
            uint32_t code = RegionCode_a99e70(rect, cur);
            if (code == 0) {
                if (havePrev) {
                    if (prevCode != 0) {
                        Vec3_a99e70 edge = ComputeLineToRectIntersection(rect, prevCode, &prev, &cur, &entryEdge);
                        kept.push_back(edge);
                    }
                }
                if (kept.empty() || std::fabs(kept.back().x - cur.x) >= 0.001f || std::fabs(kept.back().y - cur.y) >= 0.001f || std::fabs(kept.back().z - cur.z) >= 0.001f) {
                    kept.push_back(cur);
                }
            } else if (havePrev) {
                if (prevCode == 0) {
                    Vec3_a99e70 edge = ComputeLineToRectIntersection(rect, code ^ prevCode, &cur, &prev, &exitEdge);
                    kept.push_back(edge);
                    uint32_t newKey = Fn0053dde0_stub_a99e70(result, (n->mnKey & 0xf000000) >> 24, entryEdge, exitEdge, n->mnKey >> 16);
                    Node_a99e70* path = reinterpret_cast<View_a99e70*>(result)->mTable.Fn005402d0(&newKey);
                    (void)path;
                    kept.clear();
                }
            }
            prev = cur;
            prevCode = code;
            havePrev = true;
        }
    }
    return OB_ADDR(result);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053fb80 score ?  (picks a random path among those that fit a pattern; the original returns a pointer)
uint32_t cSC4PathInfo::Slot09_a99d78(uint32_t flag, uint32_t a, uint32_t b, uint32_t c, uint32_t outKeyArg, uint32_t outLenArg)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(this);
    uint32_t mask = 0xff00ffff;
    if (!flag) {
        mask = 0xf000ffff;
    }
    if (static_cast<uint8_t>(a) == 0xff) {
        mask &= 0xffff00ff;
    }
    if (static_cast<uint8_t>(b) == 0xff) {
        mask &= 0xffffff00;
    }
    uint32_t pattern = ((((flag << 16) | static_cast<uint8_t>(a)) << 8) | static_cast<uint8_t>(b)) & mask;
    uint32_t* outKey = reinterpret_cast<uint32_t*>(outKeyArg);
    float* outLen = reinterpret_cast<float*>(outLenArg);
    std::vector<Node_a99e70*> hits;
    std::vector<uint32_t> keys;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        if ((n->mnKey & mask) == pattern) {
            hits.push_back(n);
            keys.push_back(n->mnKey);
        }
    }
    Node_a99e70* chosen = 0;
    if (!hits.empty()) {
        Random_a99e70 rnd;
        rnd.Init(0xffffffff);
        uint32_t pick = rnd.RandomUint32() % hits.size();
        chosen = hits[pick];
        if (outLen) {
            *outLen = chosen->mfLength;
        }
        if (outKey) {
            *outKey = keys[pick];
        }
    }
    (void)c;
    return chosen ? chosen->mnKey : 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053fd70 score ?  (two arguments, both network pieces, in the original; the base slot has none)
// Adds the straight path between two pieces to the table of the first, keyed by the side they face.
void Fn0053fd70Draft_a99e70(cSC4PathInfo* self, Target_a99e70* from, Target_a99e70* to)
{
    (void)self;
    (void)from;
    (void)to;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005425c0 score ?  (copies the paths that fit (type, edge, flip) into a new object; four arguments in the original)
uint32_t cSC4PathInfo::Slot31_a99d78(uint32_t type, uint32_t edge, uint32_t outArg, uint32_t flip)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(this);
    uint32_t copied = 0;
    cSC4PathInfo* target = reinterpret_cast<cSC4PathInfo*>(outArg);
    View_a99e70* t = reinterpret_cast<View_a99e70*>(target);
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t k = n->mnKey;
        uint8_t kind = static_cast<uint8_t>(k >> 16);
        uint8_t from = static_cast<uint8_t>(k >> 8);
        uint8_t to = static_cast<uint8_t>(k);
        if (type && ((k >> 24) & 0xf) != type) {
            continue;
        }
        if (static_cast<uint8_t>(edge) != 0xff && static_cast<uint8_t>(edge) != kind) {
            continue;
        }
        if (static_cast<uint8_t>(flip)) {
            uint8_t swap = from;
            from = to;
            to = swap;
        }
        uint32_t newKey = ((((k >> 28) << 4 | type) << 8 | kind) << 8 | from) << 8 | to;
        if (t->mTable.Find(newKey)) {
            continue;
        }
        Node_a99e70* dst = t->mTable.Fn005402d0(&newKey);
        if (!dst) {
            continue;
        }
        std::vector<Vec3_a99e70> pts;
        if (static_cast<uint8_t>(flip)) {
            for (Vec3_a99e70* p = n->mpPtsEnd; p != n->mpPtsBegin; --p) {
                pts.push_back(p[-1]);
            }
        } else {
            for (Vec3_a99e70* p = n->mpPtsBegin; p != n->mpPtsEnd; ++p) {
                pts.push_back(*p);
            }
        }
        (void)pts;
        dst->mfLength = n->mfLength;
        dst->mbFlag = n->mbFlag;
        ++copied;
    }
    return copied;
}
#endif

// Interface of the network piece the transforming copy reads (slots by their vtable offsets).
#ifdef OB_DRAFTS
// CLOSE: 0x00540ac0 score ?  (CreateTransformedCopy: a copy of the paths moved, rotated and mirrored to a placed network piece)
// Only the skeleton: the rotation (matrix from the piece's turn), the lane remapping of the keys and the point transform are left out.
uint32_t Fn00540ac0Draft_a99e70(cSC4PathInfo* self, Target_a99e70* piece)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    Copy_a99e70* mem = static_cast<Copy_a99e70*>(Fn0090cf9a_a99e70(0));
    cSC4PathInfo* result = static_cast<cSC4PathInfo*>(mem->Fn005408b0(0));
    result->AddRef();
    (void)piece;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t newKey = n->mnKey;
        Node_a99e70* dst = reinterpret_cast<View_a99e70*>(result)->mTable.Fn005402d0(&newKey);
        if (dst) {
            dst->mbFlag = n->mbFlag;
            dst->mfLength = 0.0f;
        }
    }
    return OB_ADDR(result);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00541670 score ?  (rebuild: drops the paths whose sides the placed piece does not connect; the original takes the piece)
// Only the skeleton: the connection tables at 0xa99ce0/0xa99f1c and the erase call are left out.
void Fn00541670Draft_a99e70(cSC4PathInfo* self, Target_a99e70* piece)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    (void)piece;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t k = n->mnKey;
        if (((k >> 24) & 0xf) == 1) {
            continue;
        }
    }
}
#endif

// ---- the table plumbing (hash table of paths, vector of points) ----

// STUB: 0x0050bcb0
void Fn0050bcb0_a99e70(void* dstVector, const void* srcVector);
// STUB: 0x004f0940
void Fn004f0940_a99e70(Table_a99e70* table, uint32_t count);
// STUB: 0x0090cf54
void* Fn0090cf54_a99e70(uint32_t size);

#ifdef OB_DRAFTS
// CLOSE: 0x0053f940 score ?  (vector<point>::insert(position, value) for a vector at this; returns the position's index as a pointer)
Vec3_a99e70* Fn0053f940Draft_a99e70(Vec3Vector_a99e70* self, Vec3_a99e70* pos, const Vec3_a99e70* value)
{
    uint32_t index = static_cast<uint32_t>(pos - self->mpBegin);
    if (self->mpEnd != self->mpCap) {
        if (pos == self->mpEnd) {
            if (pos) {
                *pos = *value;
            }
            ++self->mpEnd;
        } else {
            if (self->mpEnd) {
                *self->mpEnd = self->mpEnd[-1];
            }
            ++self->mpEnd;
            Vec3_a99e70 copy = *value;
            for (Vec3_a99e70* p = self->mpEnd - 2; p > pos; --p) {
                *p = p[-1];
            }
            *pos = copy;
        }
    }
    return self->mpBegin + index;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053ff10 score ?  (hashtable insert_unique: the result pair is (node, inserted))
void Fn0053ff10Draft_a99e70(Table_a99e70* self, const uint32_t* value, Node_a99e70** outNode, uint8_t* outInserted)
{
    uint32_t key = *value;
    uint32_t bucket = key % static_cast<uint32_t>(self->mpEnd - self->mpBegin);
    Node_a99e70* first = self->mpBegin[bucket];
    for (Node_a99e70* p = first; p; p = p->mpNext) {
        if (p->mnKey == key) {
            *outNode = p;
            *outInserted = 0;
            return;
        }
    }
    Node_a99e70* node = static_cast<Node_a99e70*>(Fn0090cf54_a99e70(0x1c));
    node->mpNext = 0;
    node->mnKey = key;
    Fn0050bcb0_a99e70(&node->mpPtsBegin, value + 1);
    node->mfLength = reinterpret_cast<const float*>(value)[4];
    node->mbFlag = reinterpret_cast<const uint8_t*>(value)[0x14];
    node->mpNext = first;
    self->mpBegin[bucket] = node;
    ++self->mnCount;
    *outNode = node;
    *outInserted = 1;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053ffd0 score ?  (hashtable insert_equal: a new node goes behind a node with the same key, else to the front)
Node_a99e70* Fn0053ffd0Draft_a99e70(Table_a99e70* self, const uint32_t* value)
{
    uint32_t key = *value;
    uint32_t bucket = key % static_cast<uint32_t>(self->mpEnd - self->mpBegin);
    Node_a99e70* first = self->mpBegin[bucket];
    Node_a99e70* node = static_cast<Node_a99e70*>(Fn0090cf54_a99e70(0x1c));
    node->mpNext = 0;
    node->mnKey = key;
    Fn0050bcb0_a99e70(&node->mpPtsBegin, value + 1);
    node->mfLength = reinterpret_cast<const float*>(value)[4];
    node->mbFlag = reinterpret_cast<const uint8_t*>(value)[0x14];
    for (Node_a99e70* p = first; p; p = p->mpNext) {
        if (p->mnKey == key) {
            node->mpNext = p->mpNext;
            p->mpNext = node;
            ++self->mnCount;
            return node;
        }
    }
    node->mpNext = first;
    self->mpBegin[bucket] = node;
    ++self->mnCount;
    return node;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005400d0 score ?  (hashtable insert_equal after a resize check)
Node_a99e70* Fn005400d0Draft_a99e70(Table_a99e70* self, const uint32_t* value)
{
    Fn004f0940_a99e70(self, self->mnCount + 1);
    uint32_t bucket = *value % static_cast<uint32_t>(self->mpEnd - self->mpBegin);
    Node_a99e70* first = self->mpBegin[bucket];
    Node_a99e70* node = static_cast<Node_a99e70*>(Fn0090cf54_a99e70(0x1c));
    node->mpNext = 0;
    node->mnKey = *value;
    Fn0050bcb0_a99e70(&node->mpPtsBegin, value + 1);
    node->mfLength = reinterpret_cast<const float*>(value)[4];
    node->mbFlag = reinterpret_cast<const uint8_t*>(value)[0x14];
    node->mpNext = first;
    self->mpBegin[bucket] = node;
    ++self->mnCount;
    return node;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00540160 score ?  (hashtable copy_from: the buckets get a copy of every node of the other table)
void Fn00540160Draft_a99e70(Table_a99e70* self, const Table_a99e70* other)
{
    uint32_t count = static_cast<uint32_t>(other->mpEnd - other->mpBegin);
    self->mpEnd = self->mpBegin;
    Fn004f0940_a99e70(self, count);
    for (uint32_t i = 0; i < count; ++i) {
        Node_a99e70* src = other->mpBegin[i];
        if (!src) {
            continue;
        }
        Node_a99e70* copy = static_cast<Node_a99e70*>(Fn0090cf54_a99e70(0x1c));
        copy->mpNext = 0;
        copy->mnKey = src->mnKey;
        Fn0050bcb0_a99e70(&copy->mpPtsBegin, &src->mpPtsBegin);
        copy->mfLength = src->mfLength;
        copy->mbFlag = src->mbFlag;
        self->mpBegin[i] = copy;
        for (Node_a99e70* s = src->mpNext; s; s = s->mpNext) {
            Node_a99e70* next = static_cast<Node_a99e70*>(Fn0090cf54_a99e70(0x1c));
            next->mpNext = 0;
            next->mnKey = s->mnKey;
            Fn0050bcb0_a99e70(&next->mpPtsBegin, &s->mpPtsBegin);
            next->mfLength = s->mfLength;
            next->mbFlag = s->mbFlag;
            copy->mpNext = next;
            copy = next;
        }
    }
    self->mnCount = other->mnCount;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005402d0 score ?  (hashtable operator[]: the path of a key, made empty when it is not there yet)
Node_a99e70* Fn005402d0Draft_a99e70(Table_a99e70* self, const uint32_t* key)
{
    Node_a99e70* node = self->Find(*key);
    if (node) {
        return node;
    }
    uint32_t entry[8];
    entry[0] = *key;
    entry[1] = entry[2] = entry[3] = 0;
    entry[4] = 0;
    reinterpret_cast<uint8_t*>(entry)[0x14] = 0;
    return Fn005400d0Draft_a99e70(self, entry);
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005403f0 score ?  (joins the paths of equal key bits whose ends meet: walks all paths against all)
void Fn005403f0Draft_a99e70(cSC4PathInfo* self)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    for (Node_a99e70* a = FirstNode_a99e70(&v->mTable); a; a = NextNode_a99e70(&v->mTable, a)) {
        for (Node_a99e70* b = FirstNode_a99e70(&v->mTable); b; b = NextNode_a99e70(&v->mTable, b)) {
            if (a->mnKey == b->mnKey || ((a->mnKey ^ b->mnKey) & 0xff00ffff) != 0) {
                continue;
            }
            float dx = a->mpPtsBegin->x - b->mpPtsBegin->x;
            float dy = a->mpPtsBegin->y - b->mpPtsBegin->y;
            float dz = a->mpPtsBegin->z - b->mpPtsBegin->z;
            if (std::sqrt(dx * dx + dy * dy + dz * dz) > 0.001f) {
                continue;
            }
            dx = a->mpPtsEnd[-1].x - b->mpPtsEnd[-1].x;
            dy = a->mpPtsEnd[-1].y - b->mpPtsEnd[-1].y;
            dz = a->mpPtsEnd[-1].z - b->mpPtsEnd[-1].z;
            if (std::sqrt(dx * dx + dy * dy + dz * dz) > 0.001f) {
                continue;
            }
            // the original erases one of the two here (0x5845d0)
        }
    }
}
#endif

// STUB: 0x00975633
void Fn00975633_a99e70(void* persistResource);
// STUB: 0x00829bc0
void Fn00829bc0_a99e70(void* pool, uint32_t size);

#ifdef OB_DRAFTS
// CLOSE: 0x005407d0 score ?  (the constructor: both vtables, an empty table, flags and the 8 lane bytes cleared)
void Fn005407d0Draft_a99e70(cSC4PathInfo* self)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    Fn00975633_a99e70(&v->mpVtables[1]);
    v->mTable.mpBegin = 0;
    v->mTable.mpEnd = 0;
    v->mTable.mpCap = 0;
    v->mTable.mnCount = 0;
    Fn00829bc0_a99e70(&v->mTable, 0x64);
    v->mFlags = 0;
    for (uint32_t i = 0; i < 8; ++i) {
        v->mBytes[i] = 0;
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x005408b0 score ?  (the copy constructor)
void Fn005408b0Draft_a99e70(cSC4PathInfo* self, const cSC4PathInfo* other)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    const View_a99e70* o = reinterpret_cast<const View_a99e70*>(other);
    Fn00975633_a99e70(&v->mpVtables[1]);
    v->mTable.mpBegin = 0;
    v->mTable.mpEnd = 0;
    v->mTable.mpCap = 0;
    v->mTable.mnCount = 0;
    Fn00540160Draft_a99e70(&v->mTable, &o->mTable);
    v->mFlags = o->mFlags;
    for (uint32_t i = 0; i < 8; ++i) {
        v->mBytes[i] = o->mBytes[i];
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00540a00 score ?  (adds an empty path under a key and flags its side: byte of the lane, bit 1)
bool Fn00540a00Draft_a99e70(cSC4PathInfo* self, uint32_t key)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    uint32_t entry[8];
    entry[0] = key;
    entry[1] = entry[2] = entry[3] = 0;
    entry[4] = 0;
    reinterpret_cast<uint8_t*>(entry)[0x14] = 0;
    Fn004f0940_a99e70(&v->mTable, v->mTable.mnCount + 1);
    Node_a99e70* node = 0;
    uint8_t inserted = 0;
    Fn0053ff10Draft_a99e70(&v->mTable, entry, &node, &inserted);
    if (inserted) {
        node->mfLength = 0.0f;
        node->mbFlag = 0;
        v->mBytes[(key >> 24) & 0xf] = 1;
        v->mFlags |= 2;
    }
    return inserted != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053df70 score ?  (GetBestPath: the path with a point nearest to a position; equal distances are decided by chance)
uint32_t cSC4PathInfo::Slot05_a99d78(uint32_t type, uint32_t a, uint32_t b, uint32_t posArg, uint32_t outKeyArg, uint32_t outLenArg)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(this);
    const Vec3_a99e70* pos = reinterpret_cast<const Vec3_a99e70*>(posArg);
    uint32_t* outKey = reinterpret_cast<uint32_t*>(outKeyArg);
    float* outLen = reinterpret_cast<float*>(outLenArg);
    uint32_t mask = 0xff00ffff;
    if (static_cast<uint8_t>(a) == 0xff) {
        mask = 0xff0000ff;
    }
    uint32_t mask2 = mask & 0xffffff00;
    if (static_cast<uint8_t>(b) != 0xff) {
        mask2 = mask;
    }
    uint32_t pattern = ((type << 24) | (static_cast<uint8_t>(a) << 8) | static_cast<uint8_t>(b)) & mask2;
    Node_a99e70* best = 0;
    float bestDist = 3.4028235e+38f;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t k = n->mnKey;
        if ((mask2 & k) != pattern) {
            continue;
        }
        for (Vec3_a99e70* p = n->mpPtsBegin; p != n->mpPtsEnd; ++p) {
            float dx = pos->x - p->x;
            float dy = pos->y - p->y;
            float dz = pos->z - p->z;
            if (!Slot16_a99d78()) {
                dy = 0.0f;
            }
            float d = std::sqrt(dx * dx + dy * dy + dz * dz);
            bool take = d < bestDist;
            if (!take && std::fabs(d - bestDist) < 0.01f) {
                Random_a99e70 rnd;
                rnd.Init(0xffffffff);
                take = rnd.RandomUint32() < 0x7fffffff;
            }
            if (take) {
                if (outKey) {
                    *outKey = k;
                }
                best = n;
                bestDist = d;
                if (outLen) {
                    *outLen = n->mfLength;
                }
            }
        }
    }
    return best ? best->mnKey : 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0053eb30 score ?  (GetMaxLane: the highest lane byte (bits 16..23) among the keys; three unused arguments)
uint32_t Fn0053eb30Draft_a99e70(cSC4PathInfo* self)
{
    View_a99e70* v = reinterpret_cast<View_a99e70*>(self);
    uint32_t best = 0;
    for (Node_a99e70* n = FirstNode_a99e70(&v->mTable); n; n = NextNode_a99e70(&v->mTable, n)) {
        uint32_t lane = static_cast<uint8_t>(n->mnKey >> 16);
        if (static_cast<int32_t>(best) < static_cast<int32_t>(lane)) {
            best = lane;
        }
    }
    return best;
}
#endif
