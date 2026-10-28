// obcmp — compares functions of a rebuilt binary against the original program, instruction by instruction.
//
//   obcmp <original.exe> <rebuilt.exe|dll> <pairs.tsv> [--verbose]
//
// pairs.tsv: one function per line, "orig_va  orig_size  rebuilt_va  rebuilt_size  name" (hex VAs and sizes,
// tab- or space-separated, '#' starts a comment). For every pair it prints the match score (0-100) and a total.
//
// Each instruction becomes a token: mnemonic plus normalised operands. Absolute addresses inside the image are
// replaced by what they refer to where that is known (a paired function), otherwise by "addr", so two builds placed
// at different addresses still compare equal. Branch targets inside the function become offsets from its start in
// instructions. The score is the longest common subsequence of the two token lists over the longer list.

#include <Zydis/Zydis.h>

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace {

struct Section {
    uint32_t va;  // relative to the image base
    uint32_t vsize;
    uint32_t raw;
    uint32_t rawSize;
};

struct Image {
    std::string path;
    std::vector<uint8_t> file;
    uint32_t base = 0;
    uint32_t size = 0;
    std::vector<Section> sections;

    // Bytes at a virtual address, or nullptr when it is not backed by file data.
    const uint8_t* at(uint32_t va, uint32_t len) const {
        if (va < base) return nullptr;
        uint32_t rva = va - base;
        for (const Section& s : sections) {
            if (rva >= s.va && rva + len <= s.va + std::min(s.vsize ? s.vsize : s.rawSize, s.rawSize))
                return file.data() + s.raw + (rva - s.va);
        }
        return nullptr;
    }
    bool contains(uint64_t va) const { return va >= base && va < uint64_t(base) + size; }
};

uint32_t rd32(const std::vector<uint8_t>& b, size_t o) {
    uint32_t v;
    std::memcpy(&v, b.data() + o, 4);
    return v;
}
uint16_t rd16(const std::vector<uint8_t>& b, size_t o) {
    uint16_t v;
    std::memcpy(&v, b.data() + o, 2);
    return v;
}

bool loadImage(const std::string& path, Image& img) {
    std::ifstream f(path, std::ios::binary);
    if (!f) return false;
    img.path = path;
    img.file.assign(std::istreambuf_iterator<char>(f), {});
    const auto& b = img.file;
    if (b.size() < 0x40 || b[0] != 'M' || b[1] != 'Z') return false;
    uint32_t pe = rd32(b, 0x3c);
    if (pe + 0xf8 > b.size() || std::memcmp(b.data() + pe, "PE\0\0", 4) != 0) return false;
    uint16_t machine = rd16(b, pe + 4);
    if (machine != 0x14c) return false;  // i386 only
    uint16_t nsect = rd16(b, pe + 6);
    uint16_t optSize = rd16(b, pe + 20);
    size_t opt = pe + 24;
    img.base = rd32(b, opt + 28);
    img.size = rd32(b, opt + 56);
    size_t sh = opt + optSize;
    for (uint16_t i = 0; i < nsect; ++i, sh += 40) {
        if (sh + 40 > b.size()) return false;
        img.sections.push_back({rd32(b, sh + 12), rd32(b, sh + 8), rd32(b, sh + 20), rd32(b, sh + 16)});
    }
    return true;
}

struct Pair {
    uint32_t origVa, origSize, newVa, newSize;
    std::string name;
};

struct Side {
    const Image* img;
    // Function start address → canonical name, for this side's addresses.
    const std::map<uint32_t, std::string>* names;
};

std::string hex(uint64_t v) {
    char buf[24];
    std::snprintf(buf, sizeof buf, "0x%llx", static_cast<unsigned long long>(v));
    return buf;
}

// Turns one function into normalised instruction tokens.
std::vector<std::string> tokenize(const Side& side, uint32_t va, uint32_t size) {
    std::vector<std::string> out;
    const uint8_t* code = side.img->at(va, size);
    if (!code) return out;

    ZydisDecoder dec;
    ZydisDecoderInit(&dec, ZYDIS_MACHINE_MODE_LEGACY_32, ZYDIS_STACK_WIDTH_32);

    // First pass: instruction start offsets, so in-function branch targets become instruction indexes.
    std::vector<uint32_t> starts;
    std::map<uint32_t, size_t> index;
    for (uint32_t off = 0; off < size;) {
        ZydisDecodedInstruction ins;
        if (ZYAN_FAILED(ZydisDecoderDecodeInstruction(&dec, nullptr, code + off, size - off, &ins))) break;
        index[off] = starts.size();
        starts.push_back(off);
        off += ins.length;
    }

    auto refer = [&](uint64_t target) -> std::string {
        if (target >= va && target < uint64_t(va) + size) {
            auto it = index.find(uint32_t(target - va));
            return it != index.end() ? "L" + std::to_string(it->second) : "Lmid";
        }
        auto it = side.names->find(uint32_t(target));
        if (it != side.names->end()) return "@" + it->second;
        return side.img->contains(target) ? "addr" : hex(target);
    };

    for (uint32_t off : starts) {
        ZydisDecodedInstruction ins;
        ZydisDecodedOperand ops[ZYDIS_MAX_OPERAND_COUNT];
        if (ZYAN_FAILED(ZydisDecoderDecodeFull(&dec, code + off, size - off, &ins, ops))) break;
        std::string tok = ZydisMnemonicGetString(ins.mnemonic);
        for (uint8_t i = 0; i < ins.operand_count_visible; ++i) {
            const ZydisDecodedOperand& op = ops[i];
            tok += i ? "," : " ";
            switch (op.type) {
            case ZYDIS_OPERAND_TYPE_REGISTER:
                tok += ZydisRegisterGetString(op.reg.value);
                break;
            case ZYDIS_OPERAND_TYPE_IMMEDIATE: {
                if (op.imm.is_relative) {
                    uint64_t target = uint64_t(va) + off + ins.length + uint64_t(int64_t(op.imm.value.s));
                    tok += refer(target & 0xffffffffu);
                } else {
                    uint64_t v = op.imm.value.u & 0xffffffffu;
                    tok += side.img->contains(v) ? refer(v) : hex(v);
                }
                break;
            }
            case ZYDIS_OPERAND_TYPE_MEMORY: {
                tok += "[";
                if (op.mem.base != ZYDIS_REGISTER_NONE) tok += ZydisRegisterGetString(op.mem.base);
                if (op.mem.index != ZYDIS_REGISTER_NONE) {
                    tok += "+";
                    tok += ZydisRegisterGetString(op.mem.index);
                    tok += "*" + std::to_string(op.mem.scale);
                }
                if (op.mem.disp.has_displacement) {
                    uint64_t d = uint64_t(op.mem.disp.value) & 0xffffffffu;
                    tok += "+";
                    tok += (op.mem.base == ZYDIS_REGISTER_NONE && side.img->contains(d)) ? refer(d) : hex(d);
                }
                tok += "]";
                break;
            }
            case ZYDIS_OPERAND_TYPE_POINTER:
                tok += "far";
                break;
            default:
                break;
            }
        }
        out.push_back(std::move(tok));
    }
    return out;
}

size_t lcs(const std::vector<std::string>& a, const std::vector<std::string>& b) {
    std::vector<size_t> prev(b.size() + 1, 0), cur(b.size() + 1, 0);
    for (size_t i = 1; i <= a.size(); ++i) {
        for (size_t j = 1; j <= b.size(); ++j)
            cur[j] = a[i - 1] == b[j - 1] ? prev[j - 1] + 1 : std::max(prev[j], cur[j - 1]);
        std::swap(prev, cur);
    }
    return prev[b.size()];
}

bool parsePairs(const std::string& path, std::vector<Pair>& pairs) {
    std::ifstream f(path);
    if (!f) return false;
    std::string line;
    while (std::getline(f, line)) {
        if (auto c = line.find('#'); c != std::string::npos) line.resize(c);
        std::istringstream ss(line);
        std::string a, b, c, d, name;
        if (!(ss >> a >> b >> c >> d)) continue;
        std::getline(ss >> std::ws, name);
        pairs.push_back({uint32_t(std::stoul(a, nullptr, 16)), uint32_t(std::stoul(b, nullptr, 16)),
                         uint32_t(std::stoul(c, nullptr, 16)), uint32_t(std::stoul(d, nullptr, 16)),
                         name.empty() ? a : name});
    }
    return true;
}

}  // namespace

int main(int argc, char** argv) {
    if (argc < 4) {
        std::fprintf(stderr, "usage: obcmp <original.exe> <rebuilt.exe|dll> <pairs.tsv> [--verbose]\n");
        return 2;
    }
    bool verbose = argc > 4 && std::strcmp(argv[4], "--verbose") == 0;
    Image orig, rebuilt;
    if (!loadImage(argv[1], orig)) { std::fprintf(stderr, "cannot read PE32 image %s\n", argv[1]); return 2; }
    if (!loadImage(argv[2], rebuilt)) { std::fprintf(stderr, "cannot read PE32 image %s\n", argv[2]); return 2; }
    std::vector<Pair> pairs;
    if (!parsePairs(argv[3], pairs) || pairs.empty()) { std::fprintf(stderr, "no pairs in %s\n", argv[3]); return 2; }

    // Both sides refer to a paired function by the same name, so a call to it compares equal.
    std::map<uint32_t, std::string> origNames, newNames;
    for (const Pair& p : pairs) {
        origNames[p.origVa] = p.name;
        newNames[p.newVa] = p.name;
    }

    double weighted = 0;
    size_t total = 0, exact = 0;
    for (const Pair& p : pairs) {
        auto a = tokenize({&orig, &origNames}, p.origVa, p.origSize);
        auto b = tokenize({&rebuilt, &newNames}, p.newVa, p.newSize);
        size_t longest = std::max(a.size(), b.size());
        double score = longest ? 100.0 * double(lcs(a, b)) / double(longest) : 0.0;
        bool same = !a.empty() && a == b;
        exact += same;
        weighted += score * double(longest);
        total += longest;
        std::printf("%6.2f%%  %s  %s (%zu vs %zu instructions)\n", same ? 100.0 : score,
                    hex(p.origVa).c_str(), p.name.c_str(), a.size(), b.size());
        if (verbose && !same) {
            for (size_t i = 0; i < longest; ++i) {
                const std::string& x = i < a.size() ? a[i] : std::string();
                const std::string& y = i < b.size() ? b[i] : std::string();
                std::printf("    %c %-48s | %s\n", x == y ? ' ' : '!', x.c_str(), y.c_str());
            }
        }
    }
    std::printf("total: %zu/%zu functions identical, %.2f%% of instructions matched\n", exact, pairs.size(),
                total ? weighted / double(total) : 0.0);
    return exact == pairs.size() ? 0 : 1;
}
