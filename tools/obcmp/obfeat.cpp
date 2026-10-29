// obfeat — the features of every function of the original program that a build of the same source by another
// compiler keeps: the strings it references, the 32-bit IDs it uses, the functions it calls, the constant a tiny
// function returns. tools/obcmp/obname pairs functions of the two builds by them.
//
//   obfeat <program> <sizes.tsv> [--vtables vtables.tsv] > feat.tsv
//
// sizes.tsv: "entry size" (hex, obshape --sizes). feat.tsv, one feature per line, "addr kind value":
//   s STRING   a string it references (\n \r \t written as two characters, as Ghidra writes them)
//   k HEX      a 32-bit constant >= 0x01e00000 and < 0xffff0000 (an ID, not an address of this program or a small
//              number), or the value a chain of sub/dec on one register reaches (a switch over IDs compiles so)
//   c HEX      a function it calls directly
//   v HEX      a vtable whose address it uses (a constructor or destructor stores it)
//   r HEX      the constant a function of at most three instructions returns in eax
//   n DEC      its instruction count
// The same kinds come from the reference build's Ghidra export (tools/names/mac-features.sh).
#include "pe.h"

#include <Zydis/Zydis.h>

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace ob;

namespace {

bool idLike(uint64_t v, const Image& img) {
    return v >= 0x01e00000u && v < 0xffff0000u && !img.contains(v);
}

// A NUL-terminated string of at least 3 printable characters at va, escaped as Ghidra writes it.
bool stringAt(const Image& img, uint32_t va, std::string& out) {
    out.clear();
    if (img.isCode(va)) return false;
    for (uint32_t i = 0; i < 4096; ++i) {
        const uint8_t* b = img.at(va + i, 1);
        if (!b) return false;
        uint8_t c = *b;
        if (c == 0) return out.size() >= 3;
        if (c == '\n') out += "\\n";
        else if (c == '\r') out += "\\r";
        else if (c == '\t') out += "\\t";
        else if (c >= 0x20 && c < 0x7f) out += char(c);
        else if (c >= 0xa0) out += char(c);
        else return false;
    }
    return false;
}

}  // namespace

int main(int argc, char** argv) {
    std::vector<std::string> pos;
    std::string vtPath;
    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if (a == "--vtables" && i + 1 < argc) vtPath = argv[++i];
        else pos.push_back(a);
    }
    if (pos.size() != 2) {
        std::fprintf(stderr, "usage: obfeat <program> <sizes.tsv> [--vtables vtables.tsv]\n");
        return 2;
    }
    Image img;
    if (!loadImage(pos[0], img)) { std::fprintf(stderr, "cannot read %s\n", pos[0].c_str()); return 2; }
    std::vector<std::pair<uint32_t, uint32_t>> fns;
    {
        std::ifstream f(pos[1]);
        std::string a, s, line;
        while (std::getline(f, line)) {
            std::istringstream ss(line);
            if (ss >> a >> s && a[0] != '#') fns.push_back({uint32_t(std::stoul(a, nullptr, 16)), uint32_t(std::stoul(s, nullptr, 16))});
        }
    }
    std::set<uint32_t> vtables, entries;
    for (auto& f : fns) entries.insert(f.first);
    if (!vtPath.empty()) {
        std::ifstream f(vtPath);
        std::string a, line;
        while (std::getline(f, line)) {
            std::istringstream ss(line);
            if (ss >> a) vtables.insert(uint32_t(std::stoul(a, nullptr, 16)));
        }
    }
    ZydisDecoder dec;
    ZydisDecoderInit(&dec, ZYDIS_MACHINE_MODE_LEGACY_32, ZYDIS_STACK_WIDTH_32);
    std::string str;
    for (auto [va, size] : fns) {
        const uint8_t* code = img.at(va, size);
        if (!code) continue;
        std::set<std::string> out;
        std::map<ZydisRegister, uint32_t> off;  // running sub/dec total per register since its last write
        size_t n = 0;
        int64_t ret = -1;  // the constant in eax, while the function is still tiny
        auto hexs = [](uint32_t v) { char b[16]; std::snprintf(b, sizeof b, "%08x", v); return std::string(b); };
        for (uint32_t o = 0; o < size;) {
            ZydisDecodedInstruction i;
            ZydisDecodedOperand op[ZYDIS_MAX_OPERAND_COUNT];
            if (ZYAN_FAILED(ZydisDecoderDecodeFull(&dec, code + o, size - o, &i, op))) break;
            uint32_t at = va + o;
            o += i.length;
            ++n;
            for (unsigned k = 0; k < i.operand_count_visible; ++k) {
                uint64_t v = 0;
                bool have = false;
                if (op[k].type == ZYDIS_OPERAND_TYPE_IMMEDIATE) {
                    if (op[k].imm.is_relative) {
                        uint32_t t = uint32_t(at + i.length + op[k].imm.value.s);
                        if (i.mnemonic == ZYDIS_MNEMONIC_CALL) out.insert("c\t" + hexs(t));
                        continue;
                    }
                    v = uint32_t(op[k].imm.value.u);
                    have = true;
                    // sub/add on a register: the difference is no ID (the running total below is)
                    bool chain = (i.mnemonic == ZYDIS_MNEMONIC_SUB || i.mnemonic == ZYDIS_MNEMONIC_ADD) &&
                                 op[0].type == ZYDIS_OPERAND_TYPE_REGISTER;
                    if (!chain && idLike(v, img)) out.insert("k\t" + hexs(uint32_t(v)));
                } else if (op[k].type == ZYDIS_OPERAND_TYPE_MEMORY && op[k].mem.base == ZYDIS_REGISTER_NONE &&
                           op[k].mem.index == ZYDIS_REGISTER_NONE && op[k].mem.disp.has_displacement) {
                    v = uint32_t(op[k].mem.disp.value);
                    have = true;
                } else if (op[k].type == ZYDIS_OPERAND_TYPE_MEMORY && op[k].mem.disp.has_displacement &&
                           img.contains(uint32_t(op[k].mem.disp.value))) {
                    v = uint32_t(op[k].mem.disp.value);  // a table indexed by a register
                    have = true;
                }
                if (have && img.contains(v)) {
                    if (vtables.count(uint32_t(v))) out.insert("v\t" + hexs(uint32_t(v)));
                    else if (stringAt(img, uint32_t(v), str)) out.insert("s\t" + str);
                }
            }
            // switch over IDs: sub/dec chains on one register
            if (i.operand_count_visible >= 1 && op[0].type == ZYDIS_OPERAND_TYPE_REGISTER) {
                ZydisRegister r = op[0].reg.value;
                bool imm = i.operand_count_visible >= 2 && op[1].type == ZYDIS_OPERAND_TYPE_IMMEDIATE;
                uint32_t iv = imm ? uint32_t(op[1].imm.value.u) : 0;
                switch (i.mnemonic) {
                case ZYDIS_MNEMONIC_SUB:
                    if (imm) { off[r] += iv; if (idLike(off[r], img)) out.insert("k\t" + hexs(off[r])); } else off[r] = 0;
                    break;
                case ZYDIS_MNEMONIC_ADD:
                    if (imm) { off[r] -= iv; if (idLike(off[r], img)) out.insert("k\t" + hexs(off[r])); } else off[r] = 0;
                    break;
                case ZYDIS_MNEMONIC_DEC:
                    off[r] += 1; if (idLike(off[r], img)) out.insert("k\t" + hexs(off[r]));
                    break;
                case ZYDIS_MNEMONIC_INC: off[r] -= 1; break;
                case ZYDIS_MNEMONIC_CMP: case ZYDIS_MNEMONIC_TEST: case ZYDIS_MNEMONIC_PUSH: break;
                default: off[r] = 0;
                }
                if (i.mnemonic == ZYDIS_MNEMONIC_MOV && r == ZYDIS_REGISTER_EAX && imm) ret = iv;
                else if (i.mnemonic == ZYDIS_MNEMONIC_PUSH && imm) ret = iv;  // push N; pop eax
            }
            if (i.mnemonic == ZYDIS_MNEMONIC_RET) {
                if (n <= 3 && ret >= 0) out.insert("r\t" + hexs(uint32_t(ret)));
                break;
            }
        }
        out.insert("n\t" + std::to_string(n));
        char b[16];
        std::snprintf(b, sizeof b, "%08x", va);
        for (const std::string& s : out) std::cout << b << '\t' << s << '\n';
    }
    return 0;
}
