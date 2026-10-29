// The PE32 reader and instruction tokenizer shared by obcmp and obsig.
//
// Each instruction becomes a token: mnemonic plus normalised operands. Absolute addresses inside the image are
// replaced by what they refer to where that is known (a named function), otherwise by "addr", so two builds placed
// at different addresses still compare equal; a named address outside the image is named too (the rebuilt DLL refers
// to the original's global variables at their own addresses). Branch targets inside the function become offsets
// from its start in instructions. lcs() scores two token lists: the longest common subsequence.
#pragma once


#include <Zydis/Zydis.h>

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
namespace ob {

struct Section {
    uint32_t va;  // relative to the image base
    uint32_t vsize;
    uint32_t raw;
    uint32_t rawSize;
    uint32_t flags;  // IMAGE_SCN_* characteristics
};

struct Image {
    std::string path;
    std::vector<uint8_t> file;
    uint32_t base = 0;
    uint32_t size = 0;
    std::vector<Section> sections;
    uint32_t importDir = 0;  // RVA of the import descriptors

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
    // Inside an executable section.
    bool isCode(uint32_t va) const {
        for (const Section& s : sections)
            if ((s.flags & 0x20000000u) && va >= base + s.va && va < base + s.va + s.vsize) return true;
        return false;
    }
    // n bytes of initialised data no code can change (a read-only, non-executable section), or nullptr.
    const uint8_t* constBytes(uint32_t va, uint32_t n) const {
        if (va < base) return nullptr;
        for (const Section& s : sections) {
            if ((s.flags & 0xe0000000u) != 0x40000000u) continue;
            if (va - base >= s.va && va - base + n <= s.va + std::min(s.vsize ? s.vsize : s.rawSize, s.rawSize))
                return file.data() + s.raw + (va - base - s.va);
        }
        return nullptr;
    }
    // A dword of initialised data no code can change (a read-only, non-executable section).
    bool readConst(uint32_t va, uint32_t& out) const {
        if (va < base) return false;
        for (const Section& s : sections) {
            if ((s.flags & 0xe0000000u) != 0x40000000u) continue;  // readable, not writable, not executable
            if (va - base >= s.va && va - base + 4 <= s.va + std::min(s.vsize ? s.vsize : s.rawSize, s.rawSize)) {
                std::memcpy(&out, file.data() + s.raw + (va - base - s.va), 4);
                return true;
            }
        }
        return false;
    }
};

inline uint32_t rd32(const std::vector<uint8_t>& b, size_t o) {
    uint32_t v;
    std::memcpy(&v, b.data() + o, 4);
    return v;
}
inline uint16_t rd16(const std::vector<uint8_t>& b, size_t o) {
    uint16_t v;
    std::memcpy(&v, b.data() + o, 2);
    return v;
}

inline bool loadImage(const std::string& path, Image& img) {
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
    if (optSize >= 112) img.importDir = rd32(b, opt + 104);
    size_t sh = opt + optSize;
    for (uint16_t i = 0; i < nsect; ++i, sh += 40) {
        if (sh + 40 > b.size()) return false;
        img.sections.push_back({rd32(b, sh + 12), rd32(b, sh + 8), rd32(b, sh + 20), rd32(b, sh + 16), rd32(b, sh + 36)});
    }
    return true;
}

struct Side {
    const Image* img;
    // Function start address → canonical name, for this side's addresses.
    const std::map<uint32_t, std::string>* names;
};

// The import address table: each slot's address and "imp:<dll>!<function>" (dll in lower case; "#N" for an
// ordinal), so a call through it compares by what it calls, not where the table sits.
inline std::map<uint32_t, std::string> importNames(const Image& img) {
    std::map<uint32_t, std::string> out;
    if (!img.importDir) return out;
    for (uint32_t d = img.base + img.importDir;; d += 20) {
        const uint8_t* desc = img.at(d, 20);
        if (!desc) break;
        uint32_t lookup, nameRva, iat;
        std::memcpy(&lookup, desc, 4);
        std::memcpy(&nameRva, desc + 12, 4);
        std::memcpy(&iat, desc + 16, 4);
        if (!nameRva && !iat) break;
        std::string dll;
        for (const uint8_t* c; (c = img.at(img.base + nameRva + uint32_t(dll.size()), 1)) && *c;) dll += char(std::tolower(*c));
        uint32_t table = lookup ? lookup : iat;
        for (uint32_t i = 0;; ++i) {
            const uint8_t* t = img.at(img.base + table + 4 * i, 4);
            if (!t) break;
            uint32_t entry;
            std::memcpy(&entry, t, 4);
            if (!entry) break;
            std::string fn;
            if (entry & 0x80000000u) fn = "#" + std::to_string(entry & 0xffff);
            else
                for (const uint8_t* c; (c = img.at(img.base + entry + 2 + uint32_t(fn.size()), 1)) && *c;) fn += char(*c);
            out[img.base + iat + 4 * i] = "imp:" + dll + "!" + fn;
        }
    }
    return out;
}

inline std::string hex(uint64_t v) {
    char buf[24];
    std::snprintf(buf, sizeof buf, "0x%llx", static_cast<unsigned long long>(v));
    return buf;
}

// Turns one function into normalised instruction tokens.
// refs, when given, receives every address in the image outside the function that an instruction refers to, in order.
inline std::vector<std::string> tokenize(const Side& side, uint32_t va, uint32_t size,
                                         std::vector<uint32_t>* refs = nullptr) {
    std::vector<std::string> out;
    const uint8_t* code = side.img->at(va, size);
    if (!code) return out;

    ZydisDecoder dec;
    ZydisDecoderInit(&dec, ZYDIS_MACHINE_MODE_LEGACY_32, ZYDIS_STACK_WIDTH_32);

    // First pass: instruction start offsets, so in-function branch targets become instruction indexes. The code ends
    // where a table it indexes inside its own extent begins (a switch's jump table and byte index table follow the
    // code in a packed function), so the tables are not read as instructions.
    std::vector<uint32_t> starts;
    std::map<uint32_t, size_t> index;
    uint32_t codeEnd = size;
    uint64_t firstTable = ~uint64_t(0);  // the lowest table address past the code, inside the extent or just after it
    // The tables' contents compare too (which case goes where). Entries: the bound of the `cmp r,N; ja default` before
    // the indexing instruction (N + 1); a jump table indexed through a byte table has (largest byte + 1) entries.
    struct Table { uint64_t at; bool bytes; long count; };  // count -1: from the byte table before it; 0: unknown
    std::vector<Table> tables;
    long lastCmp = -1;
    bool afterBytes = false;
    for (uint32_t off = 0; off < codeEnd;) {
        ZydisDecodedInstruction ins;
        ZydisDecodedOperand tops[ZYDIS_MAX_OPERAND_COUNT];
        if (ZYAN_FAILED(ZydisDecoderDecodeFull(&dec, code + off, codeEnd - off, &ins, tops))) break;
        index[off] = starts.size();
        starts.push_back(off);
        off += ins.length;
        bool tableHere = false;
        for (uint8_t i = 0; i < ins.operand_count_visible; ++i) {
            const ZydisDecodedOperand& op = tops[i];
            if (op.type != ZYDIS_OPERAND_TYPE_MEMORY || !op.mem.disp.has_displacement) continue;
            bool scaled = op.mem.base == ZYDIS_REGISTER_NONE && op.mem.index != ZYDIS_REGISTER_NONE;
            if (!scaled && ins.mnemonic != ZYDIS_MNEMONIC_MOVZX) continue;  // jmp [r*4+table], movzx r,[r+bytes]
            uint64_t at = uint64_t(op.mem.disp.value) & 0xffffffffu;
            if (at >= uint64_t(va) + off && at < uint64_t(va) + size + 0x400) {
                firstTable = std::min(firstTable, at);
                bool bytes = ins.mnemonic == ZYDIS_MNEMONIC_MOVZX;
                long count = bytes || !afterBytes ? (lastCmp >= 0 ? lastCmp + 1 : 0) : -1;
                if (std::none_of(tables.begin(), tables.end(), [&](const Table& t) { return t.at == at; }))
                    tables.push_back({at, bytes, count});
                tableHere = true;
                afterBytes = bytes;
            }
            if (at >= uint64_t(va) + off && at < uint64_t(va) + codeEnd) codeEnd = uint32_t(at - va);
        }
        if (!tableHere) afterBytes = false;
        if (ins.mnemonic == ZYDIS_MNEMONIC_CMP && ins.operand_count_visible == 2 &&
            tops[1].type == ZYDIS_OPERAND_TYPE_IMMEDIATE)
            lastCmp = long(tops[1].imm.value.u & 0xffffffffu);
    }

    auto refer = [&](uint64_t target) -> std::string {
        // a switch table: by its place among the function's tables (one build packs them inside the extent, the
        // function list ends the original's before them)
        if (target >= firstTable && target < firstTable + 0x400) return "T" + std::to_string(target - firstTable);
        if (target >= va && target < uint64_t(va) + size) {
            auto it = index.find(uint32_t(target - va));
            return it != index.end() ? "L" + std::to_string(it->second) : "Lmid";
        }
        if (refs && side.img->contains(target)) refs->push_back(uint32_t(target));
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
                    tok += side.img->contains(v) || side.names->count(uint32_t(v)) ? refer(v) : hex(v);
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
                    // An address inside the image is one even with a register added (a table indexed by it).
                    std::string r = side.img->contains(d) || side.names->count(uint32_t(d)) ? refer(d) : hex(d);
                    tok += r;
                    // An unnamed constant read straight from read-only data (a float the compiler placed): its value,
                    // so a wrong constant differs although both read "some address".
                    uint32_t n = op.size / 8;
                    const uint8_t* c = r == "addr" && op.mem.base == ZYDIS_REGISTER_NONE &&
                                       op.mem.index == ZYDIS_REGISTER_NONE && n >= 1 && n <= 10
                                       ? side.img->constBytes(uint32_t(d), n) : nullptr;
                    if (c) {
                        tok += "=";
                        for (uint32_t k = n; k-- > 0;) {
                            char h[3];
                            std::snprintf(h, sizeof h, "%02x", c[k]);
                            tok += h;
                        }
                    }
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

    // The tables after the code: "table T<place>", then one token per entry ("L<n>" for a jump, "b<n>" for an index).
    if (!tables.empty()) {
        while (!out.empty() && (out.back() == "int3" || out.back().rfind("nop", 0) == 0)) out.pop_back();  // alignment
        std::sort(tables.begin(), tables.end(), [](const Table& a, const Table& b) { return a.at < b.at; });
        long largestByte = -1;
        for (const Table& t : tables) {
            out.push_back("table T" + std::to_string(t.at - firstTable));
            long count = t.count < 0 ? largestByte + 1 : t.count;
            const uint8_t* p = count > 0 && count <= 1024 ? side.img->at(uint32_t(t.at), uint32_t(count) * (t.bytes ? 1 : 4)) : nullptr;
            if (!p) { out.push_back("entries ?"); continue; }
            for (long i = 0; i < count; ++i) {
                if (t.bytes) {
                    largestByte = std::max<long>(largestByte, p[i]);
                    out.push_back("b" + std::to_string(p[i]));
                } else {
                    uint32_t e;
                    std::memcpy(&e, p + 4 * i, 4);
                    out.push_back(refer(e));
                }
            }
        }
    }
    return out;
}

// Drops the int3 / nop padding a function's extent may end with (up to the next symbol, the alignment fill).
inline void trimPadding(std::vector<std::string>& tokens) {
    while (!tokens.empty() && (tokens.back() == "int3" || tokens.back().rfind("nop", 0) == 0)) tokens.pop_back();
}

inline size_t lcs(const std::vector<std::string>& a, const std::vector<std::string>& b) {
    std::vector<size_t> prev(b.size() + 1, 0), cur(b.size() + 1, 0);
    for (size_t i = 1; i <= a.size(); ++i) {
        for (size_t j = 1; j <= b.size(); ++j)
            cur[j] = a[i - 1] == b[j - 1] ? prev[j - 1] + 1 : std::max(prev[j], cur[j - 1]);
        std::swap(prev, cur);
    }
    return prev[b.size()];
}

}  // namespace ob
