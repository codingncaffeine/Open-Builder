// obdbpf — reads the game's data archives (DBPF 1.0, index 7.0): lists their entries, and exports the textures (FSH
// images) as PNG, as reference material that stays out of the repository (scratch/assets/).
//
//   obdbpf list <file.dat>                       type  group  instance  stored-size  size  (hex; size after QFS)
//   obdbpf count <file.dat>                      entries per type
//   obdbpf raw <file.dat> <type> <outdir>        every entry of that type, decompressed, as <group>_<instance>.bin
//   obdbpf fsh <file.dat> <outdir> [--limit N]   every FSH texture as <group>_<instance>[_<n>].png (first mip level)
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

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
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
