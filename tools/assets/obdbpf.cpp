// obdbpf — reads the game's data archives (DBPF 1.0, index 7.0): lists their entries, and exports the textures (FSH
// images) as PNG, as reference material that stays out of the repository (scratch/assets/).
//
//   obdbpf list <file.dat>                       type  group  instance  stored-size  size  (hex; size after QFS)
//   obdbpf count <file.dat>                      entries per type
//   obdbpf raw <file.dat> <type> <outdir>        every entry of that type, decompressed, as <group>_<instance>.bin
//   obdbpf fsh <file.dat> <outdir> [--limit N]   every FSH texture as <group>_<instance>[_<n>].png (first mip level)
//   obdbpf exemplars <file.dat>                 group  instance  exemplar-type  model T:G:I (RKT0-5)  name
//   obdbpf s3d <file.dat> <instance> <textures> <outdir>   one model (S3D) as OBJ + MTL, its textures copied from
//                                                <textures> (the fsh export, one folder per archive)
//
// Formats (public documentation of the community tools, written from the descriptions):
// - DBPF: "DBPF", index entry count at 0x24, index offset at 0x28, index size at 0x2c; index 7.0 entries are type,
//   group, instance, offset, size (5 x u32). The directory entry (type 0xe86b1eef) lists the entries stored
//   compressed: type, group, instance, uncompressed size.
// - QFS (RefPack): a compressed entry starts with its u32 stored size, then 0x10 0xfb and the u24 big-endian
//   uncompressed size, then the control codes.
// - FSH: "SHPI", u32 size, u32 count, 4-byte directory id, then count x (4-byte name, u32 offset). Each image: u8
//   format (0x80 = QFS-compressed, ignored here), u24 offset to the next block, u16 width, u16 height, 4 x u16 (the
//   last one's top 4 bits = mip count), then the pixels. Formats: 0x60 DXT1, 0x61 DXT3, 0x62 DXT5, 0x7d 32-bit
//   BGRA, 0x7f 24-bit BGR, 0x7e 16-bit 1555, 0x78 16-bit 565, 0x6d 16-bit 4444.

#include <png.h>

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace {

namespace fs = std::filesystem;
using Bytes = std::vector<uint8_t>;

uint32_t u32(const uint8_t* p) { return uint32_t(p[0]) | uint32_t(p[1]) << 8 | uint32_t(p[2]) << 16 | uint32_t(p[3]) << 24; }
uint16_t u16(const uint8_t* p) { return uint16_t(p[0] | p[1] << 8); }

struct Entry {
    uint32_t type, group, instance, offset, size;
    uint32_t full = 0;  // uncompressed size, 0 = stored as is
};

struct Archive {
    Bytes data;
    std::vector<Entry> entries;
};

bool load(const std::string& path, Archive& a) {
    std::ifstream f(path, std::ios::binary);
    if (!f) return false;
    a.data.assign(std::istreambuf_iterator<char>(f), {});
    const Bytes& d = a.data;
    if (d.size() < 0x60 || std::memcmp(d.data(), "DBPF", 4) != 0) return false;
    if (u32(&d[0x20]) != 7) { std::fprintf(stderr, "obdbpf: index version %u not supported\n", u32(&d[0x20])); return false; }
    uint32_t count = u32(&d[0x24]), off = u32(&d[0x28]);
    if (uint64_t(off) + uint64_t(count) * 20 > d.size()) return false;
    for (uint32_t i = 0; i < count; ++i) {
        const uint8_t* p = &d[off + i * 20];
        a.entries.push_back({u32(p), u32(p + 4), u32(p + 8), u32(p + 12), u32(p + 16)});
    }
    // the directory: which entries are compressed
    std::map<std::tuple<uint32_t, uint32_t, uint32_t>, uint32_t> full;
    for (auto& e : a.entries)
        if (e.type == 0xe86b1eef && uint64_t(e.offset) + e.size <= d.size())
            for (uint32_t k = 0; k + 16 <= e.size; k += 16) {
                const uint8_t* p = &d[e.offset + k];
                full[{u32(p), u32(p + 4), u32(p + 8)}] = u32(p + 12);
            }
    for (auto& e : a.entries) {
        auto it = full.find({e.type, e.group, e.instance});
        if (it != full.end()) e.full = it->second;
    }
    return true;
}

// RefPack: the control codes after the 5-byte header (0x10 0xfb, u24 big-endian size).
bool qfs(const uint8_t* in, size_t n, Bytes& out) {
    if (n < 5 || in[1] != 0xfb) return false;
    size_t want = size_t(in[2]) << 16 | size_t(in[3]) << 8 | in[4];
    size_t p = 5;
    if (in[0] & 0x01) p += 3;  // a stored compressed size follows
    out.clear();
    out.reserve(want);
    while (p < n) {
        uint8_t b0 = in[p];
        size_t plain, copy = 0, offset = 0;
        bool last = false;
        if (b0 < 0x80) {
            if (p + 2 > n) return false;
            uint8_t b1 = in[p + 1];
            plain = b0 & 3, copy = ((b0 & 0x1c) >> 2) + 3, offset = ((b0 & 0x60) << 3) + b1 + 1;
            p += 2;
        } else if (b0 < 0xc0) {
            if (p + 3 > n) return false;
            uint8_t b1 = in[p + 1], b2 = in[p + 2];
            plain = (b1 >> 6) & 3, copy = (b0 & 0x3f) + 4, offset = ((b1 & 0x3f) << 8) + b2 + 1;
            p += 3;
        } else if (b0 < 0xe0) {
            if (p + 4 > n) return false;
            uint8_t b1 = in[p + 1], b2 = in[p + 2], b3 = in[p + 3];
            plain = b0 & 3, copy = ((b0 & 0x0c) << 6) + b3 + 5, offset = ((b0 & 0x10) << 12) + (b1 << 8) + b2 + 1;
            p += 4;
        } else if (b0 < 0xfc) {
            plain = ((b0 & 0x1f) << 2) + 4;
            p += 1;
        } else {
            plain = b0 & 3, last = true;
            p += 1;
        }
        if (p + plain > n) return false;
        out.insert(out.end(), in + p, in + p + plain);
        p += plain;
        if (copy) {
            if (offset > out.size()) return false;
            size_t from = out.size() - offset;
            for (size_t i = 0; i < copy; ++i) out.push_back(out[from + i]);
        }
        if (last) break;
    }
    return out.size() == want;
}

bool contents(const Archive& a, const Entry& e, Bytes& out) {
    if (uint64_t(e.offset) + e.size > a.data.size()) return false;
    const uint8_t* p = &a.data[e.offset];
    if (e.full && e.size >= 9 && p[5] == 0xfb) return qfs(p + 4, e.size - 4, out);
    out.assign(p, p + e.size);
    return true;
}

// ---- images ---------------------------------------------------------------------------------------------------------

struct Image {
    uint32_t w = 0, h = 0;
    std::vector<uint8_t> rgba;
};

void rgb565(uint16_t c, uint8_t* o) {
    o[0] = uint8_t((c >> 11 & 31) * 255 / 31), o[1] = uint8_t((c >> 5 & 63) * 255 / 63), o[2] = uint8_t((c & 31) * 255 / 31);
}

// One 4x4 colour block of DXT1 (alpha by the colour order when dxt1) into the image at (bx, by).
void colourBlock(const uint8_t* b, bool dxt1, Image& im, uint32_t bx, uint32_t by) {
    uint16_t c0 = u16(b), c1 = u16(b + 2);
    uint8_t pal[4][4];
    rgb565(c0, pal[0]), rgb565(c1, pal[1]);
    pal[0][3] = pal[1][3] = 255;
    for (int k = 0; k < 3; ++k) {
        if (!dxt1 || c0 > c1) {
            pal[2][k] = uint8_t((2 * pal[0][k] + pal[1][k]) / 3), pal[3][k] = uint8_t((pal[0][k] + 2 * pal[1][k]) / 3);
        } else {
            pal[2][k] = uint8_t((pal[0][k] + pal[1][k]) / 2), pal[3][k] = 0;
        }
    }
    pal[2][3] = 255, pal[3][3] = (!dxt1 || c0 > c1) ? 255 : 0;
    uint32_t bits = u32(b + 4);
    for (uint32_t y = 0; y < 4; ++y)
        for (uint32_t x = 0; x < 4; ++x) {
            uint32_t px = bx + x, py = by + y;
            int idx = bits >> (2 * (y * 4 + x)) & 3;
            if (px >= im.w || py >= im.h) continue;
            std::memcpy(&im.rgba[(py * im.w + px) * 4], pal[idx], 4);
        }
}

bool decode(uint8_t fmt, const uint8_t* p, size_t n, uint32_t w, uint32_t h, Image& im) {
    im.w = w, im.h = h;
    im.rgba.assign(size_t(w) * h * 4, 255);
    uint32_t bw = (w + 3) / 4, bh = (h + 3) / 4;
    auto need = [&](size_t k) { return k <= n; };
    switch (fmt) {
    case 0x60:  // DXT1
        if (!need(size_t(bw) * bh * 8)) return false;
        for (uint32_t y = 0; y < bh; ++y)
            for (uint32_t x = 0; x < bw; ++x) colourBlock(p + (y * bw + x) * 8, true, im, x * 4, y * 4);
        return true;
    case 0x61:  // DXT3: 64 bits of 4-bit alpha, then a colour block
    case 0x62:  // DXT5: two alpha endpoints and 3-bit indices, then a colour block
        if (!need(size_t(bw) * bh * 16)) return false;
        for (uint32_t y = 0; y < bh; ++y)
            for (uint32_t x = 0; x < bw; ++x) {
                const uint8_t* b = p + (y * bw + x) * 16;
                colourBlock(b + 8, false, im, x * 4, y * 4);
                uint8_t a[16];
                if (fmt == 0x61) {
                    for (int i = 0; i < 16; ++i) a[i] = uint8_t(((b[i / 2] >> (4 * (i & 1))) & 15) * 17);
                } else {
                    uint8_t a0 = b[0], a1 = b[1], pal[8] = {a0, a1};
                    for (int i = 2; i < 8; ++i)
                        pal[i] = a0 > a1 ? uint8_t(((8 - i) * a0 + (i - 1) * a1) / 7)
                                         : i < 6 ? uint8_t(((6 - i) * a0 + (i - 1) * a1) / 5) : (i == 6 ? 0 : 255);
                    uint64_t bits = 0;
                    for (int i = 0; i < 6; ++i) bits |= uint64_t(b[2 + i]) << (8 * i);
                    for (int i = 0; i < 16; ++i) a[i] = pal[bits >> (3 * i) & 7];
                }
                for (uint32_t i = 0; i < 16; ++i) {
                    uint32_t px = x * 4 + i % 4, py = y * 4 + i / 4;
                    if (px < w && py < h) im.rgba[(py * w + px) * 4 + 3] = a[i];
                }
            }
        return true;
    case 0x7d:  // 32-bit B G R A
    case 0x7f:  // 24-bit B G R
    {
        size_t bpp = fmt == 0x7d ? 4 : 3;
        if (!need(size_t(w) * h * bpp)) return false;
        for (size_t i = 0; i < size_t(w) * h; ++i) {
            const uint8_t* s = p + i * bpp;
            uint8_t* o = &im.rgba[i * 4];
            o[0] = s[2], o[1] = s[1], o[2] = s[0], o[3] = bpp == 4 ? s[3] : 255;
        }
        return true;
    }
    case 0x7e: case 0x78: case 0x6d:  // 16-bit 1555, 565, 4444
        if (!need(size_t(w) * h * 2)) return false;
        for (size_t i = 0; i < size_t(w) * h; ++i) {
            uint16_t c = u16(p + i * 2);
            uint8_t* o = &im.rgba[i * 4];
            if (fmt == 0x78) { rgb565(c, o); o[3] = 255; }
            else if (fmt == 0x7e) {
                o[0] = uint8_t((c >> 10 & 31) * 255 / 31), o[1] = uint8_t((c >> 5 & 31) * 255 / 31);
                o[2] = uint8_t((c & 31) * 255 / 31), o[3] = (c & 0x8000) ? 255 : 0;
            } else {
                o[0] = uint8_t((c >> 8 & 15) * 17), o[1] = uint8_t((c >> 4 & 15) * 17), o[2] = uint8_t((c & 15) * 17);
                o[3] = uint8_t((c >> 12 & 15) * 17);
            }
        }
        return true;
    default:
        return false;
    }
}

bool writePng(const std::string& path, const Image& im) {
    FILE* f = std::fopen(path.c_str(), "wb");
    if (!f) return false;
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    png_infop info = png ? png_create_info_struct(png) : nullptr;
    if (!png || !info || setjmp(png_jmpbuf(png))) {
        png_destroy_write_struct(&png, &info);
        std::fclose(f);
        return false;
    }
    png_init_io(png, f);
    png_set_IHDR(png, info, im.w, im.h, 8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
                 PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png, info);
    for (uint32_t y = 0; y < im.h; ++y) png_write_row(png, const_cast<uint8_t*>(&im.rgba[size_t(y) * im.w * 4]));
    png_write_end(png, nullptr);
    png_destroy_write_struct(&png, &info);
    std::fclose(f);
    return true;
}

// Every image of one FSH file; written as <stem>.png, or <stem>_<n>.png when it holds several.
int exportFsh(const Bytes& d, const std::string& stem, std::map<int, int>& formats) {
    if (d.size() < 16 || std::memcmp(d.data(), "SHPI", 4) != 0) return -1;
    uint32_t count = u32(&d[8]);
    if (16 + uint64_t(count) * 8 > d.size()) return -1;
    int written = 0;
    for (uint32_t i = 0; i < count; ++i) {
        uint32_t off = u32(&d[16 + i * 8 + 4]);
        if (uint64_t(off) + 16 > d.size()) continue;
        const uint8_t* h = &d[off];
        uint8_t fmt = h[0] & 0x7f;
        uint32_t w = u16(h + 4), ht = u16(h + 6);
        ++formats[fmt];
        if (h[0] & 0x80 || !w || !ht || w > 8192 || ht > 8192) continue;
        Image im;
        if (!decode(fmt, h + 16, d.size() - off - 16, w, ht, im)) continue;
        std::string path = stem + (count > 1 ? "_" + std::to_string(i) : "") + ".png";
        written += writePng(path, im);
    }
    return written;
}

char* hex8(uint32_t v);

// ---- models ---------------------------------------------------------------------------------------------------------
// S3D ("3DMD"): sections of a 4-byte tag and a u32 size (the tag and size included). VERT: groups of u16 flags,
// u16 count, u32 format (0x80004001 = position and one UV, 20 bytes; 0x80004002 adds a colour), then the vertices.
// INDX: groups of u16 flags, u16 stride, u16 count, u16 indices. PRIM: groups of a u16 count of (u32 type, u32
// first, u32 count). MATS: u32 flags, 4 bytes of alpha/depth/blend, u16 alpha threshold, u32 class, a byte, a u8
// texture count, then per texture u32 id, 2 wrap bytes (+2 filter bytes from version 1.5), u16 rate, u16 mode,
// u8-length name. ANIM: u16 frames, u16 rate, u16 mode, u32 flags, f32, u16 group count; per group a u8-length
// name, a byte, then per frame the vert, index, prim and material block of that group.
struct Model {
    struct Vert { float x, y, z, u, v; };
    std::vector<std::vector<Vert>> verts;
    std::vector<std::vector<uint16_t>> indices;
    std::vector<std::vector<std::array<uint32_t, 3>>> prims;
    std::vector<uint32_t> texture;  // per material block: its first texture's id, 0 = none
    struct Group { std::string name; uint16_t v, i, p, m; };
    std::vector<Group> groups;  // frame 0
};

bool readS3d(const Bytes& d, Model& m) {
    if (d.size() < 16 || std::memcmp(d.data(), "3DMD", 4) != 0) return false;
    uint16_t minor = 0;
    const uint8_t* animEnd = nullptr;
    for (size_t p = 8; p + 8 <= d.size();) {
        std::string tag(reinterpret_cast<const char*>(&d[p]), 4);
        uint32_t size = u32(&d[p + 4]);
        if (size < 8 || p + size > d.size()) return false;
        const uint8_t* s = &d[p + 8];
        const uint8_t* end = &d[p] + size;
        auto have = [&](const uint8_t* q, size_t n) { return q + n <= end; };
        if (tag == "HEAD" && have(s, 4)) minor = u16(s + 2);
        if (tag == "VERT" && have(s, 4)) {
            uint32_t groups = u32(s);
            const uint8_t* q = s + 4;
            for (uint32_t g = 0; g < groups && have(q, 8); ++g) {
                uint16_t count = u16(q + 2);
                uint32_t fmt = u32(q + 4);
                q += 8;
                size_t stride = 12 + 4 * ((fmt >> 8) & 0xf) /* colours */ + 8 * (fmt & 0xf) /* UV sets */;
                std::vector<Model::Vert> vs;
                for (uint16_t k = 0; k < count && have(q, stride); ++k, q += stride) {
                    Model::Vert v{};
                    std::memcpy(&v.x, q, 12);
                    if (fmt & 0xf) std::memcpy(&v.u, q + stride - 8 * (fmt & 0xf), 8);
                    vs.push_back(v);
                }
                m.verts.push_back(vs);
            }
        }
        if (tag == "INDX" && have(s, 4)) {
            uint32_t groups = u32(s);
            const uint8_t* q = s + 4;
            for (uint32_t g = 0; g < groups && have(q, 6); ++g) {
                uint16_t count = u16(q + 4);
                q += 6;
                std::vector<uint16_t> is;
                for (uint16_t k = 0; k < count && have(q, 2); ++k, q += 2) is.push_back(u16(q));
                m.indices.push_back(is);
            }
        }
        if (tag == "PRIM" && have(s, 4)) {
            uint32_t groups = u32(s);
            const uint8_t* q = s + 4;
            for (uint32_t g = 0; g < groups && have(q, 2); ++g) {
                uint16_t count = u16(q);
                q += 2;
                std::vector<std::array<uint32_t, 3>> ps;
                for (uint16_t k = 0; k < count && have(q, 12); ++k, q += 12) ps.push_back({u32(q), u32(q + 4), u32(q + 8)});
                m.prims.push_back(ps);
            }
        }
        if (tag == "MATS" && have(s, 4)) {
            uint32_t groups = u32(s);
            const uint8_t* q = s + 4;
            for (uint32_t g = 0; g < groups && have(q, 16); ++g) {
                uint8_t textures = q[15];
                q += 16;
                uint32_t first = 0;
                for (uint8_t t = 0; t < textures && have(q, 4); ++t) {
                    if (!t) first = u32(q);
                    q += 4 + 2 + (minor >= 5 ? 2 : 0) + 4;
                    if (!have(q, 1)) break;
                    q += 1 + q[0];
                }
                m.texture.push_back(first);
            }
        }
        if (tag == "ANIM" && have(s, 16)) {
            // its size leaves out the per-frame block references after each name: parsed to its real end
            const uint8_t* fileEnd = d.data() + d.size();
            uint16_t groups = u16(s + 14);
            const uint8_t* q = s + 16;
            for (uint16_t g = 0; g < groups && q + 2 <= fileEnd; ++g) {
                uint8_t len = q[0];
                if (q + 2 + len + 8 * size_t(u16(s)) > fileEnd) break;
                std::string name(reinterpret_cast<const char*>(q + 2), len);
                while (!name.empty() && name.back() == 0) name.pop_back();
                q += 2 + len;
                m.groups.push_back({name, u16(q), u16(q + 2), u16(q + 4), u16(q + 6)});
                q += 8 * u16(s);  // every frame; frame 0 is kept
            }
            animEnd = q;
        }
        p = tag == "ANIM" ? size_t(animEnd - d.data()) : p + size;
    }
    return !m.groups.empty();
}

// The model as OBJ + MTL, each material's texture found as <textures>/*/1abe787d_<id>.png and copied beside it.
bool writeObj(const Model& m, const std::string& dir, const std::string& stem, const std::string& textures) {
    std::ofstream obj(dir + "/" + stem + ".obj"), mtl(dir + "/" + stem + ".mtl");
    obj << "mtllib " << stem << ".mtl\n";
    size_t base = 1;
    std::set<uint32_t> written;
    for (auto& g : m.groups) {
        if (g.v >= m.verts.size() || g.i >= m.indices.size() || g.p >= m.prims.size()) continue;
        const auto& vs = m.verts[g.v];
        const auto& is = m.indices[g.i];
        uint32_t tex = g.m < m.texture.size() ? m.texture[g.m] : 0;
        for (auto& v : vs) obj << "v " << v.x << " " << v.y << " " << v.z << "\n";
        for (auto& v : vs) obj << "vt " << v.u << " " << 1.0f - v.v << "\n";
        obj << "o " << g.name << "\nusemtl t" << hex8(tex) << "\n";
        for (auto& pr : m.prims[g.p]) {
            if (pr[0] != 0) continue;  // triangle lists only
            for (uint32_t k = pr[1]; k + 2 < pr[1] + pr[2] && k + 2 < is.size(); k += 3) {
                size_t a = base + is[k], b = base + is[k + 1], c = base + is[k + 2];
                obj << "f " << a << "/" << a << " " << b << "/" << b << " " << c << "/" << c << "\n";
            }
        }
        base += vs.size();
        if (written.insert(tex).second) {
            std::string name = std::string("1abe787d_") + hex8(tex) + ".png";
            mtl << "newmtl t" << hex8(tex) << "\nKd 1 1 1\n";
            std::error_code ec;
            for (auto& sub : fs::directory_iterator(textures, ec))
                if (fs::exists(sub.path() / name)) {
                    fs::copy_file(sub.path() / name, dir + "/" + name, fs::copy_options::overwrite_existing, ec);
                    mtl << "map_Kd " << name << "\nmap_d " << name << "\n";
                    break;
                }
        }
    }
    return true;
}

char* hex8(uint32_t v) {
    static char b[4][12];
    static int k = 0;
    k = (k + 1) & 3;
    std::snprintf(b[k], sizeof b[k], "%08x", v);
    return b[k];
}

}  // namespace

int main(int argc, char** argv) {
    if (argc < 3) {
        std::fprintf(stderr, "usage: obdbpf list|count|raw|fsh <file.dat> ... (see the header of tools/assets/obdbpf.cpp)\n");
        return 2;
    }
    std::string cmd = argv[1];
    Archive a;
    if (!load(argv[2], a)) { std::fprintf(stderr, "obdbpf: cannot read %s as DBPF\n", argv[2]); return 2; }
    if (cmd == "list") {
        for (auto& e : a.entries)
            std::printf("%s\t%s\t%s\t%x\t%x\n", hex8(e.type), hex8(e.group), hex8(e.instance), e.size, e.full ? e.full : e.size);
        return 0;
    }
    if (cmd == "s3d" && argc >= 6) {
        uint32_t inst = uint32_t(std::stoul(argv[3], nullptr, 16));
        fs::create_directories(argv[5]);
        Bytes buf;
        for (auto& e : a.entries) {
            if (e.type != 0x5ad0e817 || e.instance != inst) continue;
            Model m;
            if (!contents(a, e, buf) || !readS3d(buf, m)) { std::fprintf(stderr, "obdbpf: model %08x unreadable\n", inst); return 1; }
            writeObj(m, argv[5], hex8(inst), argv[4]);
            size_t tris = 0;
            for (auto& g : m.groups) if (g.p < m.prims.size()) for (auto& pr : m.prims[g.p]) tris += pr[0] == 0 ? pr[2] / 3 : 0;
            std::fprintf(stderr, "obdbpf: %08x: %zu groups, %zu triangles\n", inst, m.groups.size(), tris);
            return 0;
        }
        std::fprintf(stderr, "obdbpf: no model %08x\n", inst);
        return 1;
    }
    if (cmd == "exemplars") {
        // binary exemplars and cohorts ("EQZB1###"/"CQZB1###"): parent cohort TGI, then properties of id u32, type u16,
        // key type u16 (0x80 = an array: u32 count follows), one unused byte, then the values
        Bytes buf;
        for (auto& e : a.entries) {
            if (e.type != 0x6534284a && e.type != 0x05342861) continue;
            if (!contents(a, e, buf) || buf.size() < 24 || std::memcmp(buf.data() + 1, "QZB1", 4) != 0) continue;
            uint32_t n = u32(&buf[20]);
            size_t p = 24;
            std::string name;
            uint32_t kind = 0;
            std::string model = "-";
            for (uint32_t k = 0; k < n && p + 9 <= buf.size(); ++k) {
                uint32_t id = u32(&buf[p]);
                uint16_t type = u16(&buf[p + 4]), key = u16(&buf[p + 6]);
                p += 9;
                size_t width = type == 0x0100 || type == 0x0b00 || type == 0x0c00 ? 1 : type == 0x0200 ? 2 : type == 0x0800 ? 8 : 4;
                size_t count = 1;
                if (key & 0x80) {
                    if (p + 4 > buf.size()) break;
                    count = u32(&buf[p]);
                    p += 4;
                }
                if (p + width * count > buf.size()) break;
                const uint8_t* v = &buf[p];
                if (id == 0x20 && type == 0x0c00) name.assign(reinterpret_cast<const char*>(v), count);
                if (id == 0x10 && width == 4) kind = u32(v);
                if (id >= 0x27812820 && id <= 0x27812825 && width == 4 && count >= 3 && model == "-") {
                    // RKT0-5: the model; RKT4 lists records of 8 words whose last three are a type, group, instance
                    size_t at = id == 0x27812824 && count >= 8 ? 5 : 0;
                    model = std::string(hex8(u32(v + at * 4))) + ":" + hex8(u32(v + at * 4 + 4)) + ":" + hex8(u32(v + at * 4 + 8));
                }
                p += width * count;
            }
            std::printf("%s\t%s\t%x\t%s\t%s\n", hex8(e.group), hex8(e.instance), kind, model.c_str(), name.c_str());
        }
        return 0;
    }
    if (cmd == "count") {
        std::map<uint32_t, std::pair<size_t, uint64_t>> by;
        for (auto& e : a.entries) by[e.type].first++, by[e.type].second += e.full ? e.full : e.size;
        for (auto& [t, c] : by) std::printf("%s\t%zu\t%llu\n", hex8(t), c.first, static_cast<unsigned long long>(c.second));
        return 0;
    }
    if ((cmd == "raw" && argc >= 5) || (cmd == "fsh" && argc >= 4)) {
        uint32_t want = cmd == "raw" ? uint32_t(std::stoul(argv[3], nullptr, 16)) : 0x7ab50e44;
        std::string out = argv[cmd == "raw" ? 4 : 3];
        size_t limit = SIZE_MAX;
        for (int i = 4; i + 1 < argc; ++i)
            if (std::string(argv[i]) == "--limit") limit = std::stoul(argv[i + 1]);
        fs::create_directories(out);
        size_t done = 0, failed = 0, images = 0;
        std::map<int, int> formats;
        Bytes buf;
        for (auto& e : a.entries) {
            if (e.type != want || done >= limit) continue;
            if (!contents(a, e, buf)) { ++failed; continue; }
            std::string stem = out + "/" + hex8(e.group) + "_" + hex8(e.instance);
            if (cmd == "raw") {
                std::ofstream(stem + ".bin", std::ios::binary).write(reinterpret_cast<const char*>(buf.data()), long(buf.size()));
            } else {
                int n = exportFsh(buf, stem, formats);
                if (n < 0) { ++failed; continue; }
                images += size_t(n);
            }
            ++done;
        }
        std::fprintf(stderr, "obdbpf: %zu entries, %zu images, %zu unreadable", done, images, failed);
        for (auto [f, c] : formats) std::fprintf(stderr, "; format %02x: %d", f, c);
        std::fprintf(stderr, "\n");
        return 0;
    }
    std::fprintf(stderr, "obdbpf: unknown command %s\n", cmd.c_str());
    return 2;
}
