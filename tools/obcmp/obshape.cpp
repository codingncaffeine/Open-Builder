// obshape — reads every function of a program built with the 2003 compiler for what its declaration can be told from:
// how many bytes of arguments it pops (the `ret N` of a __thiscall or __stdcall function), and, for the one-line
// members the compiler writes the same way every time, what they do.
//
//   obshape <program> <functions.tsv> [--out shapes.tsv]
//
// functions.tsv: "entry size ..." (hex, tools/ghidra/ExportFunctions.java). shapes.tsv, one line per function:
//   address  room  pops  returns  shape  [detail...]
// room: its own bytes and the padding (int3, nop) after them, up to the next function (decimal): where a hook can
// write its 5-byte jump.
// pops: the bytes every ret in it pops (decimal), "?" when it has no ret (it ends in a jump), "x" when its rets
// disagree. returns: D, B, F (a dword, a byte, a float), V (nothing), ? (unknown), from the instruction before each
// ret. shape and detail (offsets hex, from this; types: d dword, b byte, w word, bz/bs a byte widened with zero
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
// --extents: "address extent" (hex), how far past this the function reaches (see thisExtent), for those that do.
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

// What the function returns, from the last instruction before each ret (stack cleanup skipped): D a dword in eax, B a
// byte in al, F a float on the FPU stack, V nothing written there, ? a call (its result may be passed on) or rets
// that disagree. A void function leaves eax as scratch, but never writes it last.
std::string returns(const std::vector<Ins>& v) {
    std::set<char> seen;
    for (size_t i = 0; i < v.size(); ++i) {
        if (!isRet(v[i])) continue;
        size_t j = i;
        while (j > 0) {
            const Ins& p = v[j - 1];
            auto m = p.i.mnemonic;
            bool cleanup = m == ZYDIS_MNEMONIC_LEAVE ||
                           (m == ZYDIS_MNEMONIC_POP && !isReg(p.o[0], ZYDIS_REGISTER_EAX)) ||
                           ((m == ZYDIS_MNEMONIC_ADD || m == ZYDIS_MNEMONIC_SUB) && isReg(p.o[0], ZYDIS_REGISTER_ESP)) ||
                           (m == ZYDIS_MNEMONIC_MOV && isReg(p.o[0], ZYDIS_REGISTER_ESP));
            if (!cleanup) break;
            --j;
        }
        if (j == 0) { seen.insert('V'); continue; }
        const Ins& p = v[j - 1];
        auto m = p.i.mnemonic;
        const auto& d = p.o[0];
        if (m == ZYDIS_MNEMONIC_CALL) { seen.insert('?'); continue; }
        if (m == ZYDIS_MNEMONIC_FLD || m == ZYDIS_MNEMONIC_FILD || m == ZYDIS_MNEMONIC_FLDZ || m == ZYDIS_MNEMONIC_FLD1 ||
            m == ZYDIS_MNEMONIC_FMUL || m == ZYDIS_MNEMONIC_FADD || m == ZYDIS_MNEMONIC_FSUB || m == ZYDIS_MNEMONIC_FDIV ||
            m == ZYDIS_MNEMONIC_FSUBR || m == ZYDIS_MNEMONIC_FDIVR || m == ZYDIS_MNEMONIC_FCHS || m == ZYDIS_MNEMONIC_FABS) {
            seen.insert('F');
            continue;
        }
        bool writes = d.type == ZYDIS_OPERAND_TYPE_REGISTER && (d.actions & ZYDIS_OPERAND_ACTION_MASK_WRITE) &&
                      m != ZYDIS_MNEMONIC_CMP && m != ZYDIS_MNEMONIC_TEST && m != ZYDIS_MNEMONIC_PUSH;
        if (writes && d.reg.value == ZYDIS_REGISTER_AL) seen.insert('B');
        else if (writes && (d.reg.value == ZYDIS_REGISTER_EAX || d.reg.value == ZYDIS_REGISTER_AX)) seen.insert('D');
        else seen.insert('V');
    }
    if (seen.size() != 1) return "?";
    return std::string(1, *seen.begin());
}

// How far a function's code really runs: decoded from its entry, following the branches it takes inside itself (jump
// tables included), up to the ret or jump that no branch reaches past; never past the next listed function, unless
// that one is a false start inside this one: this one runs into it, or branches into its listed extent past its entry
// (a tail call goes to an entry, or past the extent to a function the list misses). Then the limit moves to the entry
// after it. fns: every listed function (entry, size), sorted. The list sometimes ends a function early, which would
// score a truncated original.
uint32_t extent(const ZydisDecoder& dec, const Image& img, const std::vector<std::pair<uint32_t, uint32_t>>& fns,
                size_t k) {
    uint32_t va = fns[k].first;
    size_t following = k + 1;  // the next listed function, where the limit is
    auto limitOf = [&](size_t f) { return f < fns.size() ? fns[f].first - va : fns.back().first + fns.back().second - va; };
    uint32_t limit = limitOf(following);
    const uint8_t* code = img.at(va, limit);
    if (!code) return 0;
    auto skip = [&]() {  // the following function is a false start: the limit moves to the one after it
        if (following >= fns.size() || limitOf(following + 1) >= 0x10000) return;
        if (const uint8_t* longer = img.at(va, limitOf(following + 1))) { code = longer; limit = limitOf(++following); }
    };
    uint32_t reach = 0;  // the furthest branch target seen, from va
    for (uint32_t o = 0; o < limit;) {
        Ins x;
        if (ZYAN_FAILED(ZydisDecoderDecodeFull(&dec, code + o, limit - o, &x.i, x.o))) return o;
        o += x.i.length;
        const auto& t = x.o[0];
        bool branch = x.i.meta.category == ZYDIS_CATEGORY_COND_BR || x.i.meta.category == ZYDIS_CATEGORY_UNCOND_BR;
        if (branch && t.type == ZYDIS_OPERAND_TYPE_IMMEDIATE && t.imm.is_relative) {
            uint64_t target = (uint64_t(va) + o + uint64_t(t.imm.value.s)) & 0xffffffffu;
            // into the following function's extent, past its entry (checked again after each move)
            while (following < fns.size() && target > fns[following].first &&
                   target < uint64_t(fns[following].first) + fns[following].second) {
                size_t was = following;
                skip();
                if (following == was) break;
            }
            if (target > va && target < uint64_t(va) + limit) reach = std::max(reach, uint32_t(target - va));
        }
        // jmp [reg*4+table]: every entry is a target inside this function (a listed function at or around one is a
        // case Ghidra cut out), up to the first word that is no address shortly after the entry
        if (x.i.mnemonic == ZYDIS_MNEMONIC_JMP && t.type == ZYDIS_OPERAND_TYPE_MEMORY && t.mem.scale == 4 &&
            t.mem.base == ZYDIS_REGISTER_NONE) {
            for (uint32_t e = uint32_t(t.mem.disp.value), w;; e += 4) {
                const uint8_t* p = img.at(e, 4);
                if (!p) break;
                std::memcpy(&w, p, 4);
                if (w <= va || w >= va + 0x10000) break;
                while (following < fns.size() && w >= fns[following].first) {
                    size_t was = following;
                    skip();
                    if (following == was) break;
                }
                if (w >= va + limit) break;
                reach = std::max(reach, w - va);
            }
        }
        bool ends = isRet(x) || (x.i.mnemonic == ZYDIS_MNEMONIC_JMP);
        if (ends && o > reach) return o;
        // Running into the following function: compiled code never runs into another function (one that does not
        // return ends in its call; alignment is int3/nop), so that one is a false start inside this one.
        bool stops = ends || x.i.mnemonic == ZYDIS_MNEMONIC_CALL || x.i.mnemonic == ZYDIS_MNEMONIC_INT3 ||
                     x.i.mnemonic == ZYDIS_MNEMONIC_NOP;
        if (o == limit && !stops) skip();
    }
    return limit;
}

// How far past `this` a member function reads or writes: the end of the furthest [reg+N] whose register still holds
// the ecx it was called with (copied by mov, kept across calls in esi/edi/ebx/ebp), in a straight pass over its
// instructions. A lower bound on the size of every class whose vtable holds the function (0 = no member seen).
uint32_t thisExtent(const ZydisDecoder& dec, const Image& img, uint32_t va, uint32_t size) {
    const uint8_t* code = img.at(va, size);
    if (!code) return 0;
    auto r32 = [](ZydisRegister r) { return ZydisRegisterGetLargestEnclosing(ZYDIS_MACHINE_MODE_LEGACY_32, r); };
    std::set<ZydisRegister> holds{ZYDIS_REGISTER_ECX};
    uint32_t end = 0;
    for (uint32_t o = 0; o < size;) {
        Ins x;
        if (ZYAN_FAILED(ZydisDecoderDecodeFull(&dec, code + o, size - o, &x.i, x.o))) break;
        o += x.i.length;
        for (unsigned k = 0; k < x.i.operand_count_visible; ++k) {
            const auto& m = x.o[k];
            if (m.type != ZYDIS_OPERAND_TYPE_MEMORY || m.mem.index != ZYDIS_REGISTER_NONE || m.mem.segment == ZYDIS_REGISTER_FS ||
                !holds.count(m.mem.base))
                continue;
            int64_t d = m.mem.disp.value;
            unsigned width = x.i.mnemonic == ZYDIS_MNEMONIC_LEA ? 0 : std::max(1u, unsigned(m.size) / 8);  // lea: an address, maybe one past the end
            if (d >= 0 && d < 0x10000) end = std::max(end, uint32_t(d) + width);
        }
        if (x.i.mnemonic == ZYDIS_MNEMONIC_CALL) {
            holds.erase(ZYDIS_REGISTER_EAX), holds.erase(ZYDIS_REGISTER_ECX), holds.erase(ZYDIS_REGISTER_EDX);
            continue;
        }
        const auto &d = x.o[0], &s = x.o[1];
        bool copy = x.i.mnemonic == ZYDIS_MNEMONIC_MOV && x.i.operand_count_visible == 2 &&
                    d.type == ZYDIS_OPERAND_TYPE_REGISTER && s.type == ZYDIS_OPERAND_TYPE_REGISTER &&
                    r32(d.reg.value) == d.reg.value && holds.count(s.reg.value);
        for (unsigned k = 0; k < x.i.operand_count; ++k)  // implicit operands too (cdq, mul, stos...)
            if (x.o[k].type == ZYDIS_OPERAND_TYPE_REGISTER && (x.o[k].actions & ZYDIS_OPERAND_ACTION_MASK_WRITE))
                holds.erase(r32(x.o[k].reg.value));
        if (copy) holds.insert(d.reg.value);
    }
    return end;
}

}  // namespace

int main(int argc, char** argv) {
    std::vector<std::string> pos;
    std::string out;
    std::ofstream sizesOut, extentsOut;
    size_t longer = 0;
    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if (a == "--out" && i + 1 < argc) out = argv[++i];
        else if (a == "--sizes" && i + 1 < argc) sizesOut.open(argv[++i]);
        else if (a == "--extents" && i + 1 < argc) extentsOut.open(argv[++i]);
        else pos.push_back(a);
    }
    if (pos.size() != 2) {
        std::fprintf(stderr, "usage: obshape <program> <functions.tsv> [--out shapes.tsv] [--sizes sizes.tsv] [--extents extents.tsv]\n");
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
        os << std::hex << va << std::dec << "\t" << room << "\t" << p << "\t" << returns(v) << "\t" << sh << "\n";
        ++count;
        uint32_t e = sizesOut.is_open() || extentsOut.is_open() ? std::max(extent(dec, img, fns, k), size) : size;
        if (sizesOut.is_open()) {
            if (e > size) ++longer;
            sizesOut << std::hex << va << "\t" << e << std::dec << "\n";
        }
        if (extentsOut.is_open())
            if (uint32_t t = thisExtent(dec, img, va, e)) extentsOut << std::hex << va << "\t" << t << std::dec << "\n";
    }
    if (sizesOut.is_open()) std::fprintf(stderr, "%zu functions longer than listed\n", longer);
    std::fprintf(stderr, "%zu functions, %zu one-line shapes\n", count, shaped);
    return 0;
}
