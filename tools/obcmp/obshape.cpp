// obshape — reads every function of a program built with the 2003 compiler for what its declaration can be told from:
// how many bytes of arguments it pops (the `ret N` of a __thiscall or __stdcall function), and, for the one-line
// members the compiler writes the same way every time, what they do.
//
//   obshape <program> <functions.tsv> [--out shapes.tsv]
//
// functions.tsv: "entry size ..." (hex, tools/ghidra/ExportFunctions.java). shapes.tsv, one line per function:
//   address  room  pops  shape  [detail...]
// room: its own bytes and the padding (int3, nop) after them, up to the next function (decimal): where a hook can
// write its 5-byte jump.
// pops: the bytes every ret in it pops (decimal), "?" when it has no ret (it ends in a jump), "x" when its rets
// disagree. shape and detail (offsets hex, from this; types: d dword, b byte, w word, bz/bs a byte widened with zero
// or sign extension, wz/ws the same for a word, f float, q double, a the address of a member):
//   -                         none of these
//   empty                     ret
//   this                      mov eax,ecx; ret
//   const T VALUE OPT         return VALUE (T d, b or f; VALUE hex, a float's bits); OPT is O1 or O2 when only that
//                             flag set writes the constant this way (xor eax,eax; inc eax / push N; pop eax are /O1's,
//                             mov eax,N for a small N /O2's), "-" otherwise
//   get T OFF                 return the member at OFF (a: its address)
//   set T OFF ARG             the member at OFF = argument ARG (0 = the first)
//   setconst T OFF ARG CT CV  the same, then return the constant CV of type CT
// The shapes are what the compiler emits for the spellings in tools/obcmp/test/shapes.cpp (checked by shapes.sh).

#include "pe.h"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace {

using namespace ob;

struct Ins {
    ZydisDecodedInstruction i;
    ZydisDecodedOperand o[ZYDIS_MAX_OPERAND_COUNT];
};

bool isReg(const ZydisDecodedOperand& o, ZydisRegister r) { return o.type == ZYDIS_OPERAND_TYPE_REGISTER && o.reg.value == r; }
bool isImm(const ZydisDecodedOperand& o) { return o.type == ZYDIS_OPERAND_TYPE_IMMEDIATE; }
// [base+disp] with no index
bool isMem(const ZydisDecodedOperand& o, ZydisRegister base) {
    return o.type == ZYDIS_OPERAND_TYPE_MEMORY && o.mem.base == base && o.mem.index == ZYDIS_REGISTER_NONE &&
           o.mem.segment != ZYDIS_REGISTER_FS;
}
uint32_t disp(const ZydisDecodedOperand& o) { return uint32_t(o.mem.disp.value); }
bool isRet(const Ins& x) { return x.i.mnemonic == ZYDIS_MNEMONIC_RET; }
uint32_t retPops(const Ins& x) { return x.i.operand_count_visible ? uint32_t(x.o[0].imm.value.u) : 0; }

std::string hexs(uint64_t v) {
    char b[24];
    std::snprintf(b, sizeof b, "%llx", static_cast<unsigned long long>(v));
    return b;
}

// The type a load into eax/al/ax from memory gives, or "" when it is not one.
std::string loadType(const Ins& x, ZydisRegister base, uint32_t& off) {
    if (x.i.operand_count_visible != 2) return "";
    const auto &d = x.o[0], &s = x.o[1];
    if (x.i.mnemonic == ZYDIS_MNEMONIC_LEA && isReg(d, ZYDIS_REGISTER_EAX) && isMem(s, base)) { off = disp(s); return "a"; }
    if (!isMem(s, base)) return "";
    off = disp(s);
    unsigned size = s.size;
    if (x.i.mnemonic == ZYDIS_MNEMONIC_MOV) {
        if (isReg(d, ZYDIS_REGISTER_EAX)) return "d";
        if (isReg(d, ZYDIS_REGISTER_AL)) return "b";
        if (isReg(d, ZYDIS_REGISTER_AX)) return "w";
    }
    if (x.i.mnemonic == ZYDIS_MNEMONIC_MOVZX && isReg(d, ZYDIS_REGISTER_EAX)) return size == 8 ? "bz" : "wz";
    if (x.i.mnemonic == ZYDIS_MNEMONIC_MOVSX && isReg(d, ZYDIS_REGISTER_EAX)) return size == 8 ? "bs" : "ws";
    return "";
}

std::string fldType(const Ins& x, ZydisRegister base, uint32_t& off) {
    if (x.i.mnemonic != ZYDIS_MNEMONIC_FLD || !isMem(x.o[0], base)) return "";
    off = disp(x.o[0]);
    return x.o[0].size == 32 ? "f" : x.o[0].size == 64 ? "q" : "";
}

// A constant into eax/al from one or two instructions: type, value, and the flag set that writes it so.
bool constant(const std::vector<Ins>& v, size_t at, size_t& used, std::string& type, uint64_t& value, std::string& opt,
              const Image& img) {
    const Ins& a = v[at];
    const auto &d = a.o[0], &s = a.o[1];
    opt = "-";
    used = 1;
    if (a.i.mnemonic == ZYDIS_MNEMONIC_MOV && isImm(s) && isReg(d, ZYDIS_REGISTER_EAX)) {
        type = "d", value = uint32_t(s.imm.value.u);
        // a small constant is push N; pop eax under /O1 (1 is xor eax,eax; inc eax)
        if (int32_t(value) >= -128 && int32_t(value) <= 127) opt = "O2";
        return true;
    }
    if (a.i.mnemonic == ZYDIS_MNEMONIC_MOV && isImm(s) && isReg(d, ZYDIS_REGISTER_AL)) { type = "b", value = uint8_t(s.imm.value.u); return true; }
    if (a.i.mnemonic == ZYDIS_MNEMONIC_XOR && isReg(d, ZYDIS_REGISTER_AL) && isReg(s, ZYDIS_REGISTER_AL)) { type = "b", value = 0; return true; }
    if (a.i.mnemonic == ZYDIS_MNEMONIC_XOR && isReg(d, ZYDIS_REGISTER_EAX) && isReg(s, ZYDIS_REGISTER_EAX)) {
        if (at + 1 < v.size() && v[at + 1].i.mnemonic == ZYDIS_MNEMONIC_INC && isReg(v[at + 1].o[0], ZYDIS_REGISTER_EAX)) {
            used = 2, type = "d", value = 1, opt = "O1";
            return true;
        }
        type = "d", value = 0;
        return true;
    }
    if (a.i.mnemonic == ZYDIS_MNEMONIC_OR && isReg(d, ZYDIS_REGISTER_EAX) && isImm(s) && uint32_t(s.imm.value.u) == 0xffffffffu) {
        type = "d", value = 0xffffffffu;
        return true;
    }
    if (a.i.mnemonic == ZYDIS_MNEMONIC_PUSH && isImm(d) && at + 1 < v.size() && v[at + 1].i.mnemonic == ZYDIS_MNEMONIC_POP &&
        isReg(v[at + 1].o[0], ZYDIS_REGISTER_EAX)) {
        used = 2, type = "d", value = uint32_t(d.imm.value.u), opt = "O1";
        return true;
    }
    // fld dword [constant]: the float's bits, read from the program
    if (a.i.mnemonic == ZYDIS_MNEMONIC_FLD && d.type == ZYDIS_OPERAND_TYPE_MEMORY && d.mem.base == ZYDIS_REGISTER_NONE &&
        d.mem.index == ZYDIS_REGISTER_NONE && d.size == 32) {
        uint32_t bits;
        if (!img.readConst(uint32_t(d.mem.disp.value), bits)) return false;
        type = "f", value = bits;
        return true;
    }
    return false;
}

std::string shapeOf(const std::vector<Ins>& v, const Image& img) {
    if (v.empty() || !isRet(v.back())) return "-";
    size_t n = v.size();
    if (n == 1) return "empty";
    if (n == 2 && v[0].i.mnemonic == ZYDIS_MNEMONIC_MOV && isReg(v[0].o[0], ZYDIS_REGISTER_EAX) && isReg(v[0].o[1], ZYDIS_REGISTER_ECX))
        return "this";
    uint32_t off = 0;
    std::string t;
    if (n == 2 && (!(t = loadType(v[0], ZYDIS_REGISTER_ECX, off)).empty() || !(t = fldType(v[0], ZYDIS_REGISTER_ECX, off)).empty()))
        return "get " + t + " " + hexs(off);
    size_t used;
    uint64_t value;
    std::string opt;
    if (constant(v, 0, used, t, value, opt, img) && used + 1 == n) return "const " + t + " " + hexs(value) + " " + opt;
    // mov R,[esp+4+4k]; mov [ecx+N],R (; constant) ; ret
    if (n >= 3 && v[0].i.mnemonic == ZYDIS_MNEMONIC_MOV && v[1].i.mnemonic == ZYDIS_MNEMONIC_MOV &&
        isMem(v[0].o[1], ZYDIS_REGISTER_ESP) && v[0].o[0].type == ZYDIS_OPERAND_TYPE_REGISTER &&
        isMem(v[1].o[0], ZYDIS_REGISTER_ECX) && isReg(v[1].o[1], v[0].o[0].reg.value)) {
        uint32_t sp = disp(v[0].o[1]);
        if (sp < 4 || sp % 4) return "-";
        ZydisRegister r = v[0].o[0].reg.value;
        std::string st = r == ZYDIS_REGISTER_EAX ? "d" : r == ZYDIS_REGISTER_AL ? "b" : r == ZYDIS_REGISTER_AX ? "w" : "";
        if (st.empty() || v[0].o[1].size != v[1].o[0].size) return "-";
        std::string set = st + " " + hexs(disp(v[1].o[0])) + " " + std::to_string((sp - 4) / 4);
        if (n == 3) return "set " + set;
        if (constant(v, 2, used, t, value, opt, img) && used + 3 == n && t != "f")
            return "setconst " + set + " " + t + " " + hexs(value);
    }
    return "-";
}

}  // namespace

int main(int argc, char** argv) {
    std::vector<std::string> pos;
    std::string out;
    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if (a == "--out" && i + 1 < argc) out = argv[++i];
        else pos.push_back(a);
    }
    if (pos.size() != 2) {
        std::fprintf(stderr, "usage: obshape <program> <functions.tsv> [--out shapes.tsv]\n");
        return 2;
    }
    Image img;
    if (!loadImage(pos[0], img)) { std::fprintf(stderr, "cannot read %s\n", pos[0].c_str()); return 2; }
    std::ifstream f(pos[1]);
    if (!f) { std::fprintf(stderr, "cannot read %s\n", pos[1].c_str()); return 2; }
    std::ofstream file;
    if (!out.empty()) file.open(out);
    std::ostream& os = out.empty() ? std::cout : file;
    ZydisDecoder dec;
    ZydisDecoderInit(&dec, ZYDIS_MACHINE_MODE_LEGACY_32, ZYDIS_STACK_WIDTH_32);
    std::string line;
    size_t count = 0, shaped = 0;
    std::vector<std::pair<uint32_t, uint32_t>> fns;  // entry, size
    while (std::getline(f, line)) {
        std::istringstream ss(line);
        std::string a, s;
        if (!(ss >> a >> s) || a[0] == '#') continue;
        fns.push_back({uint32_t(std::stoul(a, nullptr, 16)), uint32_t(std::stoul(s, nullptr, 16))});
    }
    std::sort(fns.begin(), fns.end());
    for (size_t k = 0; k < fns.size(); ++k) {
        auto [va, size] = fns[k];
        const uint8_t* code = img.at(va, size);
        if (!code) continue;
        std::vector<Ins> v;
        std::set<uint32_t> pops;
        uint32_t own = 0;  // bytes of its own instructions
        for (uint32_t o = 0; o < size;) {
            Ins x;
            if (ZYAN_FAILED(ZydisDecoderDecodeFull(&dec, code + o, size - o, &x.i, x.o))) break;
            o += x.i.length;
            own = o;
            if (isRet(x)) pops.insert(retPops(x));
            v.push_back(x);
            if (isRet(x) && pops.size() == 1 && o < size && v.size() <= 4) {
                // padding after a short function's ret is not its code
                bool pad = true;
                for (uint32_t q = o; q < size; ++q) pad &= code[q] == 0xcc || code[q] == 0x90;
                if (pad) break;
            }
        }
        std::string p = pops.empty() ? "?" : pops.size() > 1 ? "x" : std::to_string(*pops.begin());
        std::string sh = shapeOf(v, img);
        shaped += sh != "-";
        // room: its own bytes and the padding after them, where a hook can write its 5-byte jump. Never past the
        // next function, nor the first byte that is not padding: the function list misses functions only vtables
        // reach (packed, with no padding between them).
        uint32_t limit = k + 1 < fns.size() ? fns[k + 1].first - va : own + 16;
        uint32_t r = own;
        for (const uint8_t* b; r < limit && (b = img.at(va + r, 1)) && (*b == 0xcc || *b == 0x90);) ++r;
        std::string room = std::to_string(std::min(r, limit));
        os << std::hex << va << std::dec << "\t" << room << "\t" << p << "\t" << sh << "\n";
        ++count;
    }
    std::fprintf(stderr, "%zu functions, %zu one-line shapes\n", count, shaped);
    return 0;
}
