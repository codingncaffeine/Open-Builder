// obclass — recovers the classes of a program built with the 2003 compiler from its vtables and the code that writes
// them, so they can be declared again and the compiler made to emit what it generated for them (adjustor thunks,
// deleting destructors).
//
//   obclass <program> <functions.tsv> <vtables.tsv> --new ADDR[,ADDR...] --delete ADDR[,ADDR...]
//           [--classes out.tsv] [--slots out.tsv] [--deleting out.tsv]
//
// functions.tsv: "entry size ..." (hex, tools/ghidra/ExportFunctions.java). vtables.tsv: "vtable slots ..." (hex
// address, decimal slot count; tools/ghidra/Vtables.java). --new and --delete name the allocator's operator new and
// operator delete, so objects can be followed from their allocation and deleting destructors recognised.
//
// Every function is read straight through, following two kinds of object pointer: `this` (ecx on entry) and each
// operator new result, through register copies, lea and add/sub; code after a ret or jmp starts from the state at
// the jump to it. Constants stored into an object are remembered, and dwords of read-only data can be loaded, so a
// virtual base found through the vbtable the constructor stored sits at a known offset. Each store of a vtable
// address into an object, and each call made with ecx pointing into one, is an event on that object. A constructor
// stores the vtables of its bases first and its own last; a destructor its own first; but the optimiser drops a
// store a later one overwrites, so a constructor usually shows only its own vtables and a destructor its deepest
// base's. A function is a destructor when it tests the delete flag and calls operator delete (a deleting
// destructor), when a deleting destructor calls it, or when it does not return `this` (constructors return it).
// Deleting destructors belong to the class whose vtable holds them; a destructor's stores of another class's
// vtables name an ancestor, and the direct base is the class under it whose vtable shares the most slots. Calls
// made with ecx at this+N before the class's own vtables are stored are base constructors; known constructors
// called after are member objects.
//
// A class is named after the vtable at offset 0 of its objects ("primary"), or at its first virtual base when a
// vbtable pointer is at 0. classes.tsv, one line per class:
//   primary  size  layout(offset:vtable,...)  bases(offset:primary,...)  members(offset:primary,...)
//   constructors  destructors  deleting-destructors  sites(functions building it inline)  flags
//   virtual-bases(offset:primary,...)
// deleting.tsv, one line per deleting destructor: address, shape (call: it calls the destructor out of line; stores:
// the destructor inlined is only vtable stores; other), the destructor it calls, O1 or O2 (how it pops operator
// delete's argument: pop ecx, or add esp).
// slots.tsv, one line per vtable slot of every placed vtable:
//   vtable  index  target  kind  detail
// kind: own (declared or overridden by the class), inherited (same as the base's at that position, detail = base
// vtable), thunk (adjustor: detail = method,adjustment), thunk-vtordisp (detail = method,adjustment,displacement
// offset), deleting-dtor. Sizes, lists and addresses are hex, "-" when
// empty. A summary goes to stdout.

#include "pe.h"

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace {

using namespace ob;

struct Value {
    enum Kind { None, Obj, Const, Flag } kind = None;  // Flag: a byte argument loaded from the stack
    int root = 0;     // Obj: which object
    int32_t off = 0;  // Obj: offset into it
    uint32_t c = 0;   // Const
    bool viaTable = false;  // read from a table in read-only data (a vbtable entry), or an address using one
};

struct Event {
    enum Type { Write, Call, VbTable } type;  // VbTable: a vbtable pointer stored (a = the vbtable)
    int32_t off;
    uint32_t a;  // Write: vtable; Call: callee (0 = indirect)
    bool virt = false;  // Write: at an offset found through a vbtable (a virtual base)
};

struct Root {
    bool fromNew = false;
    uint32_t size = 0;  // operator new's argument, 0 = unknown
    std::vector<Event> ev;
    // Constants stored into the object (vbtable pointers), so a later load of them is known: a constructor finds
    // a virtual base through the vbtable it stored.
    std::map<int32_t, Value> fields;
};

struct FunctionInfo {
    uint32_t va = 0, size = 0;
    std::vector<Root> roots;  // [0] = this
    bool returnsThis = false;
    bool testsDeleteFlag = false;
    bool deletesThis = false;
    int32_t deleteOff = 0;  // what it deletes, from this: 0, -4 (an array's count), -N (this is a virtual base)
    int instructions = 0;
    bool popEcx = false;  // pops operator delete's argument with pop ecx (/O1) rather than add esp (/O2)
    bool afterDelete = false;
};

enum class Role { Ctor, Dtor };

struct Class {
    uint32_t primary = 0;
    std::map<int32_t, uint32_t> layout;
    std::map<int32_t, std::vector<uint32_t>> chain;  // construction order, own vtable last
    std::set<uint32_t> sizes;
    std::set<std::pair<int32_t, uint32_t>> bases, members, virtualBases;  // offset, primary
    std::set<uint32_t> ctors, dtors, deleting, sites;
    std::set<std::string> flags;
};

std::vector<uint32_t> parseList(const std::string& s) {
    std::vector<uint32_t> out;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, ',')) out.push_back(uint32_t(std::stoul(item, nullptr, 16)));
    return out;
}

std::string list(const std::set<uint32_t>& s) {
    if (s.empty()) return "-";
    std::string out;
    for (uint32_t v : s) out += (out.empty() ? "" : ",") + hex(v).substr(2);
    return out;
}

std::string offsets(const std::set<std::pair<int32_t, uint32_t>>& s) {
    if (s.empty()) return "-";
    std::string out;
    for (auto& [o, v] : s) out += (out.empty() ? "" : ",") + hex(uint32_t(o)).substr(2) + ":" + hex(v).substr(2);
    return out;
}

ZydisRegister reg32(ZydisRegister r) {
    return ZydisRegisterGetLargestEnclosing(ZYDIS_MACHINE_MODE_LEGACY_32, r);
}

int regIndex(ZydisRegister r) {
    switch (reg32(r)) {
    case ZYDIS_REGISTER_EAX: return 0;
    case ZYDIS_REGISTER_ECX: return 1;
    case ZYDIS_REGISTER_EDX: return 2;
    case ZYDIS_REGISTER_EBX: return 3;
    case ZYDIS_REGISTER_ESP: return 4;
    case ZYDIS_REGISTER_EBP: return 5;
    case ZYDIS_REGISTER_ESI: return 6;
    case ZYDIS_REGISTER_EDI: return 7;
    default: return -1;
    }
}

struct Program {
    Image img;
    std::vector<std::pair<uint32_t, uint32_t>> functions;  // va, size
    std::map<uint32_t, std::vector<uint32_t>> vtables;      // va -> slot targets
    std::set<uint32_t> newFns, deleteFns;
};

FunctionInfo analyse(const Program& p, uint32_t va, uint32_t size) {
    FunctionInfo fi;
    fi.va = va;
    fi.size = size;
    fi.roots.emplace_back();
    const uint8_t* code = p.img.at(va, size);
    if (!code) return fi;

    ZydisDecoder dec;
    ZydisDecoderInit(&dec, ZYDIS_MACHINE_MODE_LEGACY_32, ZYDIS_STACK_WIDTH_32);
    Value regs[8];
    regs[1] = {Value::Obj, 0, 0, 0};
    std::vector<Value> pushes;  // since the last call
    // Register state at each jump target inside the function, taken at the first jump there. Code after a ret
    // or jmp is reached only by a jump, so it starts from that state (or from the state at the last jump through
    // a table) instead of from what the instruction before it left.
    std::map<uint32_t, std::array<Value, 8>> atTarget;
    std::array<Value, 8> atTable{};
    bool tableSeen = false, terminal = false;

    auto vtableValue = [&](const Value& v) { return v.kind == Value::Const && p.vtables.count(v.c); };
    // A vbtable: read-only data whose first entry is the vbptr's offset back to its subobject (0 or a small negative)
    // and whose next is a plausible offset to a virtual base; never a vtable.
    auto isVbtable = [&](uint32_t a) {
        uint32_t first, second;
        if (p.vtables.count(a) || !p.img.readConst(a, first) || !p.img.readConst(a + 4, second)) return false;
        return int32_t(first) <= 0 && int32_t(first) > -0x1000 && int32_t(second) > 0 && second < 0x10000 && second % 4 == 0;
    };
    // A memory operand's address: base + index*scale + disp, an object offset or a constant when what it adds up
    // is (an object plus constants, or constants only).
    auto address = [&](const ZydisDecodedOperand& o) {
        Value a{Value::Const, 0, 0, uint32_t(o.mem.disp.value)};
        auto add = [&](ZydisRegister r, uint8_t scale) {
            if (r == ZYDIS_REGISTER_NONE || a.kind == Value::None) return;
            int i = regIndex(r);
            Value v = i >= 0 ? regs[i] : Value{};
            bool table = a.viaTable || v.viaTable;
            if (v.kind == Value::Obj && scale <= 1 && a.kind == Value::Const) a = {Value::Obj, v.root, v.off + int32_t(a.c), 0};
            else if (v.kind == Value::Const && a.kind == Value::Const) a.c += v.c * (scale ? scale : 1);
            else if (v.kind == Value::Const && a.kind == Value::Obj) a.off += int32_t(v.c * (scale ? scale : 1));
            else a = Value{};
            if (a.kind != Value::None) a.viaTable = table;
        };
        add(o.mem.base, 1);
        add(o.mem.index, o.mem.scale);
        return a;
    };
    auto record = [&](const Value& obj, int32_t disp, Event::Type t, uint32_t a) {
        fi.roots[obj.root].ev.push_back({t, obj.off + disp, a, obj.viaTable});
    };
    auto call = [&](uint32_t target) {
        if (regs[1].kind == Value::Obj) record(regs[1], 0, Event::Call, target);
        if (p.deleteFns.count(target) && !pushes.empty() && pushes.back().kind == Value::Obj &&
            pushes.back().root == 0 && pushes.back().off <= 0) {
            fi.deletesThis = true;
            fi.deleteOff = pushes.back().off;
            fi.afterDelete = true;
        }
        Value result;
        if (p.newFns.count(target)) {
            Root r;
            r.fromNew = true;
            if (!pushes.empty() && pushes.back().kind == Value::Const) r.size = pushes.back().c;
            fi.roots.push_back(r);
            result = {Value::Obj, int(fi.roots.size() - 1), 0, 0};
        }
        regs[0] = result;
        regs[1] = regs[2] = Value{};
        pushes.clear();
    };

    for (uint32_t off = 0; off < size;) {
        ZydisDecodedInstruction ins;
        ZydisDecodedOperand ops[ZYDIS_MAX_OPERAND_COUNT];
        if (terminal) {
            auto it = atTarget.find(va + off);
            if (it != atTarget.end()) std::copy(it->second.begin(), it->second.end(), regs);
            else if (tableSeen) std::copy(atTable.begin(), atTable.end(), regs);
            pushes.clear();
        }
        terminal = false;
        if (ZYAN_FAILED(ZydisDecoderDecodeFull(&dec, code + off, size - off, &ins, ops))) break;
        ++fi.instructions;
        uint32_t next = va + off + ins.length;
        off += ins.length;
        const ZydisDecodedOperand& o0 = ops[0];
        const ZydisDecodedOperand& o1 = ops[1];
        int d = o0.type == ZYDIS_OPERAND_TYPE_REGISTER ? regIndex(o0.reg.value) : -1;
        bool full = d >= 0 && reg32(o0.reg.value) == o0.reg.value;  // the whole 32-bit register
        if (fi.afterDelete) {
            fi.popEcx = ins.mnemonic == ZYDIS_MNEMONIC_POP && o0.type == ZYDIS_OPERAND_TYPE_REGISTER &&
                        o0.reg.value == ZYDIS_REGISTER_ECX;
            fi.afterDelete = false;
        }

        auto relTarget = [&](const ZydisDecodedOperand& o) {
            return uint32_t(uint64_t(next) + uint64_t(int64_t(o.imm.value.s)));
        };
        auto save = [&](uint32_t t) {
            if (t >= va && t < va + size && !atTarget.count(t)) std::copy(regs, regs + 8, atTarget[t].begin());
        };
        if (ins.meta.category == ZYDIS_CATEGORY_COND_BR && o0.type == ZYDIS_OPERAND_TYPE_IMMEDIATE && o0.imm.is_relative)
            save(relTarget(o0));
        bool handled = false;
        switch (ins.mnemonic) {
        case ZYDIS_MNEMONIC_MOV:
            if (full && o1.type == ZYDIS_OPERAND_TYPE_REGISTER && regIndex(o1.reg.value) >= 0) {
                regs[d] = regs[regIndex(o1.reg.value)];
                handled = true;
            } else if (full && o1.type == ZYDIS_OPERAND_TYPE_IMMEDIATE) {
                regs[d] = {Value::Const, 0, 0, uint32_t(o1.imm.value.u)};
                handled = true;
            } else if (d >= 0 && o0.size == 8 && o1.type == ZYDIS_OPERAND_TYPE_MEMORY &&
                       reg32(o1.mem.base) == ZYDIS_REGISTER_ESP) {
                regs[d] = {Value::Flag, 0, 0, 0};  // mov bl,[esp+N]: a vector deleting destructor's flags
                handled = true;
            } else if (o0.type == ZYDIS_OPERAND_TYPE_MEMORY && o0.size == 32) {
                Value base = address(o0);
                Value v;
                if (o1.type == ZYDIS_OPERAND_TYPE_IMMEDIATE) v = {Value::Const, 0, 0, uint32_t(o1.imm.value.u)};
                else if (o1.type == ZYDIS_OPERAND_TYPE_REGISTER && regIndex(o1.reg.value) >= 0)
                    v = regs[regIndex(o1.reg.value)];
                if (base.kind == Value::Obj) {
                    if (vtableValue(v)) record(base, 0, Event::Write, v.c);
                    else if (v.kind == Value::Const && isVbtable(v.c)) record(base, 0, Event::VbTable, v.c);
                    if (v.kind == Value::Const) fi.roots[base.root].fields[base.off] = v;
                    else fi.roots[base.root].fields.erase(base.off);
                }
                handled = true;  // a store writes no register
            } else if (full && o1.type == ZYDIS_OPERAND_TYPE_MEMORY && o1.size == 32) {
                // A load: a constant this object was given, or a dword of read-only data.
                Value a = address(o1), v;
                if (a.kind == Value::Obj) {
                    auto& fields = fi.roots[a.root].fields;
                    auto it = fields.find(a.off);
                    if (it != fields.end()) v = it->second;
                } else if (a.kind == Value::Const) {
                    uint32_t c;
                    if (p.img.readConst(a.c, c)) v = {Value::Const, 0, 0, c, true};
                }
                regs[d] = v;
                handled = true;
            }
            break;
        case ZYDIS_MNEMONIC_LEA:
            if (full && o1.mem.index == ZYDIS_REGISTER_NONE && regIndex(o1.mem.base) >= 0) {
                Value v = regs[regIndex(o1.mem.base)];
                if (v.kind == Value::Obj) v.off += int32_t(o1.mem.disp.value);
                else v = Value{};
                regs[d] = v;
                handled = true;
            }
            break;
        case ZYDIS_MNEMONIC_ADD:
        case ZYDIS_MNEMONIC_SUB:
            if (full && o1.type == ZYDIS_OPERAND_TYPE_IMMEDIATE && regs[d].kind == Value::Obj) {
                int32_t n = int32_t(o1.imm.value.s);
                regs[d].off += ins.mnemonic == ZYDIS_MNEMONIC_ADD ? n : -n;
                handled = true;
            }
            break;
        case ZYDIS_MNEMONIC_PUSH:
            if (o0.type == ZYDIS_OPERAND_TYPE_IMMEDIATE) pushes.push_back({Value::Const, 0, 0, uint32_t(o0.imm.value.u)});
            else if (d >= 0) pushes.push_back(regs[d]);
            else pushes.push_back(Value{});
            handled = true;
            break;
        case ZYDIS_MNEMONIC_TEST:
            // test byte [esp+N],1 (or 2, the array bit), or the same of the flags loaded into a register: a deleting
            // destructor's flags
            if (o1.type == ZYDIS_OPERAND_TYPE_IMMEDIATE && (o1.imm.value.u == 1 || o1.imm.value.u == 2) &&
                ((o0.type == ZYDIS_OPERAND_TYPE_MEMORY && o0.size == 8 && reg32(o0.mem.base) == ZYDIS_REGISTER_ESP) ||
                 (d >= 0 && o0.size == 8 && regs[d].kind == Value::Flag)))
                fi.testsDeleteFlag = true;
            handled = true;
            break;
        case ZYDIS_MNEMONIC_CALL:
            call(o0.type == ZYDIS_OPERAND_TYPE_IMMEDIATE && o0.imm.is_relative ? relTarget(o0) : 0);
            handled = true;
            break;
        case ZYDIS_MNEMONIC_JMP:
            // A jump out of the function is a tail call; one through memory, a jump table.
            if (o0.type == ZYDIS_OPERAND_TYPE_IMMEDIATE && o0.imm.is_relative) {
                uint32_t t = relTarget(o0);
                if (t < va || t >= va + size) call(t);
                else save(t);
            } else {
                std::copy(regs, regs + 8, atTable.begin());
                tableSeen = true;
            }
            terminal = true;
            handled = true;
            break;
        case ZYDIS_MNEMONIC_RET:
            if (regs[0].kind == Value::Obj && regs[0].root == 0 && regs[0].off == 0) fi.returnsThis = true;
            terminal = true;
            handled = true;
            break;
        default:
            break;
        }
        if (handled) continue;
        // Anything else: every register it writes is no longer known.
        for (uint8_t i = 0; i < ins.operand_count; ++i) {
            if (ops[i].type == ZYDIS_OPERAND_TYPE_REGISTER && (ops[i].actions & ZYDIS_OPERAND_ACTION_MASK_WRITE)) {
                int r = regIndex(ops[i].reg.value);
                if (r >= 0) regs[r] = Value{};
            }
        }
    }
    return fi;
}

// A thunk: an adjustor (sub/add ecx,N; jmp F) or a vtordisp thunk (sub ecx,[ecx-M]; then maybe sub/add ecx,N;
// jmp F), which also subtracts the displacement stored before a virtual base. Returns F, or 0 when va is no thunk,
// and sets adj (N, the constant subtracted from this) and vtordisp (M, 0 for an adjustor).
uint32_t thunkTarget(const Program& p, uint32_t va, int32_t& adj, int32_t* vtordisp = nullptr) {
    ZydisDecoder dec;
    ZydisDecoderInit(&dec, ZYDIS_MACHINE_MODE_LEGACY_32, ZYDIS_STACK_WIDTH_32);
    adj = 0;
    int32_t disp = 0;
    uint32_t at = va;
    for (int step = 0; step < 3; ++step) {
        const uint8_t* b = p.img.at(at, 6);
        if (!b) return 0;
        ZydisDecodedInstruction ins;
        ZydisDecodedOperand o[ZYDIS_MAX_OPERAND_COUNT];
        if (ZYAN_FAILED(ZydisDecoderDecodeFull(&dec, b, 6, &ins, o))) return 0;
        at += ins.length;
        if (ins.mnemonic == ZYDIS_MNEMONIC_JMP) {
            if (step == 0 || o[0].type != ZYDIS_OPERAND_TYPE_IMMEDIATE || !o[0].imm.is_relative) return 0;
            if (vtordisp) *vtordisp = disp;
            else if (disp) return 0;
            return uint32_t(uint64_t(at) + uint64_t(int64_t(o[0].imm.value.s)));
        }
        bool ecx = o[0].type == ZYDIS_OPERAND_TYPE_REGISTER && o[0].reg.value == ZYDIS_REGISTER_ECX;
        if (!ecx || (ins.mnemonic != ZYDIS_MNEMONIC_SUB && ins.mnemonic != ZYDIS_MNEMONIC_ADD)) return 0;
        if (o[1].type == ZYDIS_OPERAND_TYPE_IMMEDIATE && !adj) {
            int32_t n = int32_t(o[1].imm.value.s);
            adj = ins.mnemonic == ZYDIS_MNEMONIC_SUB ? n : -n;
        } else if (step == 0 && ins.mnemonic == ZYDIS_MNEMONIC_SUB && o[1].type == ZYDIS_OPERAND_TYPE_MEMORY &&
                   o[1].mem.base == ZYDIS_REGISTER_ECX && o[1].mem.index == ZYDIS_REGISTER_NONE) {
            disp = -int32_t(o[1].mem.disp.value);
        } else {
            return 0;
        }
    }
    return 0;
}

bool readTable(const std::string& path, std::vector<std::vector<std::string>>& rows) {
    std::ifstream f(path);
    if (!f) return false;
    std::string line;
    while (std::getline(f, line)) {
        std::istringstream ss(line);
        std::vector<std::string> cols;
        std::string c;
        while (ss >> c) cols.push_back(c);
        if (!cols.empty() && cols[0][0] != '#') rows.push_back(cols);
    }
    return true;
}

}  // namespace

int main(int argc, char** argv) {
    std::vector<std::string> pos;
    std::string classesOut, slotsOut, deletingOut, newArg, deleteArg;
    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        auto value = [&]() -> std::string {
            if (i + 1 >= argc) { std::fprintf(stderr, "%s needs a value\n", a.c_str()); std::exit(2); }
            return argv[++i];
        };
        if (a == "--classes") classesOut = value();
        else if (a == "--slots") slotsOut = value();
        else if (a == "--deleting") deletingOut = value();
        else if (a == "--new") newArg = value();
        else if (a == "--delete") deleteArg = value();
        else pos.push_back(a);
    }
    if (pos.size() != 3 || newArg.empty() || deleteArg.empty()) {
        std::fprintf(stderr, "usage: obclass <program> <functions.tsv> <vtables.tsv> --new ADDR[,..] --delete ADDR[,..] "
                             "[--classes out.tsv] [--slots out.tsv] [--deleting out.tsv]\n");
        return 2;
    }
    Program p;
    if (!loadImage(pos[0], p.img)) { std::fprintf(stderr, "cannot read %s\n", pos[0].c_str()); return 2; }
    std::vector<std::vector<std::string>> rows;
    if (!readTable(pos[1], rows)) { std::fprintf(stderr, "cannot read %s\n", pos[1].c_str()); return 2; }
    for (auto& r : rows)
        if (r.size() >= 2) p.functions.push_back({uint32_t(std::stoul(r[0], nullptr, 16)), uint32_t(std::stoul(r[1], nullptr, 16))});
    rows.clear();
    if (!readTable(pos[2], rows)) { std::fprintf(stderr, "cannot read %s\n", pos[2].c_str()); return 2; }
    for (auto& r : rows) {
        if (r.size() < 2) continue;
        uint32_t va = uint32_t(std::stoul(r[0], nullptr, 16));
        uint32_t n = uint32_t(std::stoul(r[1]));
        const uint8_t* b = p.img.at(va, n * 4);
        if (!b) continue;
        std::vector<uint32_t> slots(n);
        std::memcpy(slots.data(), b, n * 4);
        p.vtables[va] = slots;
    }
    for (uint32_t a : parseList(newArg)) p.newFns.insert(a);
    for (uint32_t a : parseList(deleteArg)) p.deleteFns.insert(a);

    // 1. Events of every function. Deleting destructors: they test the delete flag and call operator delete with
    //    this. One that stores no vtable calls the class's destructor; one that does has the destructor inlined, and
    //    what it calls on this is a base's destructor.
    std::map<uint32_t, FunctionInfo> fns;
    std::set<uint32_t> deletingFns;
    std::map<uint32_t, uint32_t> dtorOf;  // deleting destructor -> the class's destructor
    // The deleting destructors whose code follows from the class's declaration alone: "call" (the destructor called
    // out of line, then operator delete) or "stores" (an inline destructor that only stores vtables); "other" has
    // more in it.
    struct DeletingShape {
        std::string shape = "other";
        uint32_t dtor = 0;
        bool popEcx = false;
    };
    std::map<uint32_t, DeletingShape> deletingShape;
    auto writes = [](const Root& r) {
        for (auto& e : r.ev)
            if (e.type == Event::Write) return true;
        return false;
    };
    for (auto [va, size] : p.functions) {
        FunctionInfo fi = analyse(p, va, size);
        if (fi.testsDeleteFlag && fi.deletesThis) {
            deletingFns.insert(va);
            if (!writes(fi.roots[0]))
                for (auto& e : fi.roots[0].ev)
                    if (e.type == Event::Call && e.off == 0 && e.a && !p.deleteFns.count(e.a)) {
                        dtorOf[va] = e.a;
                        break;
                    }
            DeletingShape ds;
            ds.popEcx = fi.popEcx;
            int stores = 0, calls = 0;
            for (auto& e : fi.roots[0].ev) {
                if (e.type == Event::Write) ++stores;
                else if (!p.deleteFns.count(e.a)) ++calls;
            }
            // push esi; mov esi,ecx; [call dtor | stores]; test; je; push esi; call delete; pop/add; mov; pop; ret
            if (calls == 1 && stores == 0 && dtorOf.count(va) && fi.instructions == 11 && fi.deleteOff == 0) {
                ds.shape = "call";
                ds.dtor = dtorOf[va];
            } else if (calls == 0 && stores > 0 && fi.instructions == 10 + stores && fi.deleteOff == 0) {
                ds.shape = "stores";
            }
            deletingShape[va] = ds;
        }
        bool any = false;
        for (auto& r : fi.roots) any |= !r.ev.empty();
        if (any) fns[va] = std::move(fi);
    }
    std::set<uint32_t> calledByDeleting;
    for (auto& [d, x] : dtorOf) calledByDeleting.insert(x);
    auto roleOf = [&](const FunctionInfo& fi) {
        if (deletingFns.count(fi.va) || calledByDeleting.count(fi.va)) return Role::Dtor;
        return fi.returnsThis ? Role::Ctor : Role::Dtor;
    };

    // 2. Every object a function stores vtables into at offset 0 (and more), in construction order. The optimiser
    //    drops stores that a later one overwrites, so a constructor usually shows only its class's own vtables and a
    //    destructor only its deepest base's.
    struct Seen {
        uint32_t fn;
        int root;
        Role role;
        std::map<int32_t, std::vector<uint32_t>> chain;
        std::vector<Event> ev;
        uint32_t size;
        int32_t low = 0;                // the offset of the class's first vtable: 0, or its first virtual base's
        std::set<int32_t> virtOffsets;  // offsets of virtual bases (stored through a vbtable)
        uint32_t primary() const { return chain.at(low).back(); }
    };
    std::vector<Seen> seen;
    for (auto& [va, fi] : fns) {
        for (int r = 0; r < int(fi.roots.size()); ++r) {
            const Root& root = fi.roots[r];
            if (!writes(root)) continue;
            Seen s{va, r, r == 0 ? roleOf(fi) : Role::Ctor, {}, root.ev, root.size, 0, {}};
            if (s.role == Role::Dtor) std::reverse(s.ev.begin(), s.ev.end());
            for (auto& e : s.ev) {
                if (e.type != Event::Write) continue;
                s.chain[e.off].push_back(e.a);
                if (e.virt) s.virtOffsets.insert(e.off);
            }
            // A vbtable pointer at +k: the virtual bases sit at k plus its entries, wherever the constructor stored them.
            for (auto& e : s.ev) {
                if (e.type != Event::VbTable) continue;
                for (uint32_t i = 1; i < 16; ++i) {
                    uint32_t entry;
                    if (!p.img.readConst(e.a + 4 * i, entry) || int32_t(entry) <= 0 || entry >= 0x10000 || entry % 4) break;
                    if (s.chain.count(e.off + int32_t(entry))) s.virtOffsets.insert(e.off + int32_t(entry));
                }
            }
            // An object with nothing stored at 0 is a class only when it has virtual bases (a vbtable pointer is at
            // 0, its first vtable is a virtual base's); otherwise it is a member built in place.
            if (s.chain.empty() || (!s.chain.count(0) && s.virtOffsets.empty())) continue;
            s.low = s.chain.begin()->first;
            seen.push_back(std::move(s));
        }
    }

    // 3. Where each vtable sits: at offset 0 of its own class when it is ever stored at offset 0; otherwise at the
    //    offset it is stored at, in the class of the vtable stored at 0 beside it (constructors first). A vtable at
    //    a nonzero offset with no adjustor thunk for that offset is a member object's (its class never seen at 0).
    std::map<uint32_t, std::pair<uint32_t, int32_t>> placed;  // vtable -> class primary, offset in it
    std::map<uint32_t, std::set<std::string>> flagsOf;
    for (auto& s : seen) {
        const auto& ch = s.chain.at(s.low);
        for (size_t i = 0; i < ch.size(); ++i) placed[ch[i]] = {ch[i], i + 1 == ch.size() ? s.low : 0};
    }
    auto thunkFor = [&](uint32_t vt, int32_t k) {
        for (uint32_t t : p.vtables.at(vt)) {
            int32_t adj = 0;
            int32_t vd = 0;
            // A vtordisp thunk exists only in the vtable of a virtual base the class itself holds.
            if (thunkTarget(p, t, adj, &vd) && (adj == k || vd)) return true;
        }
        return false;
    };
    for (int pass = 0; pass < 2; ++pass) {
        for (auto& s : seen) {
            if ((s.role == Role::Ctor) != (pass == 0)) continue;
            for (auto& [o, ch] : s.chain) {
                if (o == s.low) continue;
                for (size_t i = 0; i < ch.size(); ++i) {
                    uint32_t v = ch[i];
                    if (placed.count(v)) continue;
                    if (i + 1 == ch.size() && thunkFor(v, o)) {
                        placed[v] = {s.primary(), o};
                    } else {
                        // An earlier store (a base's vtable there) or no thunk: a class of its own.
                        placed[v] = {v, 0};
                        flagsOf[v].insert(i + 1 == ch.size() ? "member-only" : "base-only");
                    }
                }
            }
        }
    }
    std::map<uint32_t, Class> classes;
    for (auto& [v, pl] : placed) {
        Class& c = classes[pl.first];
        c.primary = pl.first;
        if (c.layout.count(pl.second) && c.layout[pl.second] != v) c.flags.insert("layout-conflict");
        c.layout[pl.second] = v;
    }
    for (auto& [v, fl] : flagsOf) classes[v].flags.insert(fl.begin(), fl.end());
    auto classOf = [&](uint32_t vt) { return placed.at(vt).first; };

    // 4. Functions. Deleting destructors belong to the class whose vtable holds them (directly or through a thunk),
    //    and so does the destructor they call. Constructors and inline construction belong to the class they store
    //    at offset 0; other destructors too, failing anything better.
    std::map<uint32_t, std::set<uint32_t>> deletingClasses;
    for (auto& [v, pl] : placed) {
        auto it = p.vtables.find(v);
        if (it == p.vtables.end()) continue;
        for (uint32_t t : it->second) {
            int32_t adj = 0;
            int32_t vd = 0;
            uint32_t thunk = thunkTarget(p, t, adj, &vd);
            uint32_t d = deletingFns.count(t) ? t : thunk && deletingFns.count(thunk) ? thunk : 0;
            if (!d) continue;
            classes[pl.first].deleting.insert(d);
            deletingClasses[d].insert(pl.first);
        }
    }
    std::map<uint32_t, std::set<uint32_t>> dtorClasses;  // destructor -> classes
    for (auto& [d, cs] : deletingClasses) {
        auto it = dtorOf.find(d);
        if (it == dtorOf.end()) continue;
        for (uint32_t c : cs) {
            classes[c].dtors.insert(it->second);
            dtorClasses[it->second].insert(c);
        }
    }
    std::map<uint32_t, uint32_t> ctorClass;  // constructor -> class
    for (auto& s : seen) {
        Class& c = classes[classOf(s.primary())];
        if (s.root != 0) {
            c.sites.insert(s.fn);
            if (s.size) c.sizes.insert(s.size);
        } else if (s.role == Role::Ctor) {
            c.ctors.insert(s.fn);
            ctorClass[s.fn] = c.primary;
        } else if (!deletingFns.count(s.fn) && !dtorClasses.count(s.fn)) {
            c.dtors.insert(s.fn);
            dtorClasses[s.fn].insert(c.primary);
        }
    }
    // Sizes of classes built out of line: operator new, then a call of a known constructor at offset 0.
    for (auto& [va, fi] : fns) {
        for (size_t r = 1; r < fi.roots.size(); ++r) {
            const Root& root = fi.roots[r];
            if (!root.size || writes(root)) continue;
            for (auto& e : root.ev) {
                if (e.type == Event::Call && e.off == 0 && ctorClass.count(e.a)) {
                    classes[ctorClass[e.a]].sizes.insert(root.size);
                    break;
                }
            }
        }
    }

    // 5. Members and ancestors. A constructor's stores of another class's vtables are member objects; calls of a
    //    known constructor at this+N are bases before the class's own vtables are stored, members after. Earlier
    //    stores at an offset are bases. A destructor's stores of another class's vtables, and calls of another
    //    class's destructor at this+N, are ancestors (some levels between may have been optimised away).
    std::map<uint32_t, std::set<std::pair<int32_t, uint32_t>>> ancestors, directBases, virtualBases;
    for (auto& s : seen) {
        uint32_t own = classOf(s.primary());
        if (s.role == Role::Ctor) {
            for (auto& [o, ch] : s.chain) {
                auto [cv, cj] = placed[ch.back()];
                if (cv != own) classes[own].members.insert({o - cj, cv});
                for (size_t i = ch.size() - 1; i >= 1; --i) {
                    auto [dc, dj] = placed[ch[i]];
                    auto [bc, bj] = placed[ch[i - 1]];
                    if (dc != bc) (s.virtOffsets.count(o) ? virtualBases : ancestors)[dc].insert({dj - bj, bc});
                }
            }
            bool ownStored = false;
            for (auto& e : s.ev) {
                if (e.type == Event::Write && e.off == s.low && e.a == s.primary()) ownStored = true;
                if (e.type != Event::Call || !ctorClass.count(e.a) || ctorClass[e.a] == own) continue;
                if (ownStored) classes[own].members.insert({e.off, ctorClass[e.a]});
                else directBases[own].insert({e.off, ctorClass[e.a]});
            }
            continue;
        }
        if (s.root != 0) continue;
        // A deleting destructor called on a virtual base (it deletes this-N) stores that base's vtables, no ancestor's.
        if (fns.at(s.fn).deleteOff < -4) continue;
        // A destructor: whose is it?
        std::set<uint32_t> owners;
        if (deletingClasses.count(s.fn)) owners = deletingClasses[s.fn];
        else if (dtorClasses.count(s.fn)) owners = dtorClasses[s.fn];
        for (uint32_t c : owners) {
            for (auto& [o, ch] : s.chain) {
                auto [bc, bj] = placed[ch.front()];
                if (bc != c && o - bj == 0) ancestors[c].insert({0, bc});
            }
            for (auto& e : s.ev) {
                if (e.type != Event::Call || !dtorClasses.count(e.a)) continue;
                for (uint32_t b : dtorClasses[e.a])
                    if (b != c) ancestors[c].insert({e.off, b});
            }
        }
    }
    // Calls of a base's destructor from a deleting destructor with the class's destructor inlined.
    for (auto& [d, cs] : deletingClasses) {
        auto it = fns.find(d);
        if (it == fns.end() || dtorOf.count(d) || it->second.deleteOff < -4) continue;
        for (auto& e : it->second.roots[0].ev) {
            if (e.type != Event::Call || !dtorClasses.count(e.a)) continue;
            for (uint32_t c : cs)
                for (uint32_t b : dtorClasses[e.a])
                    if (b != c) ancestors[c].insert({e.off, b});
        }
    }
    for (auto& [c, vs] : virtualBases) classes[c].virtualBases.insert(vs.begin(), vs.end());
    for (auto& [c, ms] : directBases)
        for (auto& b : ms) classes[c].members.erase(b);

    // 6. Bases. A base constructor called out of line is the direct base. Otherwise the direct base at offset 0 is
    //    the ancestor, or a class below it, whose primary vtable shares the most slots with the class's (a derived
    //    class keeps every slot it does not override); classes are settled smallest first and a class is never
    //    given one of its own descendants or a larger class.
    auto slotsOf = [&](uint32_t primary) -> const std::vector<uint32_t>& {
        static const std::vector<uint32_t> none;
        auto it = p.vtables.find(primary);
        return it == p.vtables.end() ? none : it->second;
    };
    auto sizeOf = [&](uint32_t c) { return classes[c].sizes.empty() ? 0u : *classes[c].sizes.begin(); };
    std::map<uint32_t, uint32_t> base0;  // settled direct base at offset 0
    auto descendsFrom = [&](uint32_t x, uint32_t a) {
        for (int guard = 0; guard < 64 && x; ++guard) {
            if (x == a) return true;
            auto it = base0.find(x);
            if (it != base0.end()) { x = it->second; continue; }
            uint32_t next = 0;
            for (auto& [o, b] : ancestors[x])
                if (o == 0) next = b;
            x = next;
        }
        return false;
    };
    std::vector<uint32_t> order;
    for (auto& [primary, c] : classes) order.push_back(primary);
    std::stable_sort(order.begin(), order.end(), [&](uint32_t a, uint32_t b) {
        uint32_t sa = sizeOf(a) ? sizeOf(a) : 0xffffffffu, sb = sizeOf(b) ? sizeOf(b) : 0xffffffffu;
        if (sa != sb) return sa < sb;
        return slotsOf(a).size() < slotsOf(b).size();
    });
    for (uint32_t c : order) {
        Class& cls = classes[c];
        for (auto& b : directBases[c]) {
            cls.bases.insert(b);
            if (b.first == 0) base0[c] = b.second;
        }
        // One direct base per offset: at each offset with ancestors and no base constructor call, the ancestor or a
        // class below it whose primary vtable shares the most slots with the class's vtable there.
        std::map<int32_t, std::set<uint32_t>> ancAt;
        for (auto& [o, a] : ancestors[c]) ancAt[o].insert(a);
        for (auto& [o, anc] : ancAt) {
            bool direct = false;
            for (auto& b : directBases[c]) direct |= b.first == o;
            if (direct) continue;
            // An ancestor inside a base already chosen at a lower offset is that base's own ancestor.
            bool inside = false;
            for (auto& [bo, b] : cls.bases) {
                if (bo >= o) continue;
                auto bit = classes.find(b);
                if (bit == classes.end()) continue;
                inside |= bit->second.layout.count(o - bo) > 0 || (sizeOf(b) && uint32_t(o - bo) < sizeOf(b));
            }
            if (inside) continue;
            auto lit = cls.layout.find(o);
            const auto& cs = lit != cls.layout.end() ? slotsOf(lit->second) : slotsOf(c);
            uint32_t best = 0;
            size_t bestScore = 0;
            for (auto& [x, xc] : classes) {
                if (x == c || descendsFrom(x, c)) continue;
                bool under = false;
                for (uint32_t a : anc) under |= descendsFrom(x, a);
                if (!under) continue;
                const auto& xs = slotsOf(x);
                if (xs.size() > cs.size()) continue;
                // every vtable of the candidate must land on one of the class's
                bool fits = true;
                for (auto& [q, qv] : xc.layout) fits &= cls.layout.count(o + q) > 0;
                // ...and none where another base of the class starts (its constructor was called there): a base with
                // the same slots but more vtables would swallow that base (then its own base is the one)
                for (auto& [q, qv] : xc.layout)
                    for (auto& b : directBases[c]) fits &= q == 0 || b.first != o + q;
                if (!fits) continue;
                // a base of known size ends where the class's next subobject starts (polymorphic bases are adjacent)
                if (sizeOf(x)) {
                    int32_t last = o;
                    for (auto& [q, qv] : xc.layout) last = std::max(last, o + q);
                    auto nx = cls.layout.upper_bound(last);
                    if (nx != cls.layout.end() && int32_t(sizeOf(x)) != nx->first - o) continue;
                }
                if (o == 0 && sizeOf(x) && sizeOf(c) && sizeOf(x) > sizeOf(c)) continue;
                size_t score = 0;
                for (size_t i = 0; i < xs.size(); ++i) score += xs[i] == cs[i];
                bool better = !best || score > bestScore ||
                              (score == bestScore && (xs.size() > slotsOf(best).size() ||
                                                      (xs.size() == slotsOf(best).size() && sizeOf(x) > sizeOf(best))));
                if (better) { best = x; bestScore = score; }
            }
            if (!best) continue;
            cls.bases.insert({o, best});
            if (o == 0) base0[c] = best;
            if (!anc.count(best)) cls.flags.insert("base-by-slots");
        }
    }

    // 7. Slots.
    std::map<uint32_t, std::string> slotLines;
    size_t nThunks = 0, nDeleting = 0, nInherited = 0, nOwn = 0;
    std::set<uint32_t> thunkFns, deletingInSlots;
    for (auto& [primary, c] : classes) {
        for (auto& [o, vt] : c.layout) {
            auto it = p.vtables.find(vt);
            if (it == p.vtables.end()) continue;
            // The base's vtable at this position.
            const std::vector<uint32_t>* baseSlots = nullptr;
            uint32_t baseVt = 0;
            for (auto& [bo, bc] : c.bases) {
                auto bit = classes.find(bc);
                if (bit == classes.end()) continue;
                auto lit = bit->second.layout.find(o - bo);
                if (lit == bit->second.layout.end()) continue;
                auto vit = p.vtables.find(lit->second);
                if (vit == p.vtables.end()) continue;
                baseSlots = &vit->second;
                baseVt = lit->second;
                break;
            }
            for (size_t i = 0; i < it->second.size(); ++i) {
                uint32_t t = it->second[i];
                int32_t adj = 0;
                int32_t vd = 0;
                uint32_t thunk = thunkTarget(p, t, adj, &vd);
                std::string kind, detail = "-";
                if (baseSlots && i < baseSlots->size() && (*baseSlots)[i] == t) {
                    kind = "inherited";
                    detail = hex(baseVt).substr(2);
                    ++nInherited;
                } else if (thunk) {
                    kind = vd ? "thunk-vtordisp" : "thunk";
                    // add ecx,-N where the compiler writes sub ecx,N: the same adjustment, not the compiler's thunk
                    const uint8_t* tb = p.img.at(t, 1);
                    if (!vd && tb && (tb[0] == 0x83 || tb[0] == 0x81) && adj > 0) {
                        const uint8_t* mb = p.img.at(t + 1, 1);
                        if (mb && mb[0] == 0xc1) kind = "thunk-add";
                    }
                    detail = hex(thunk).substr(2) + "," + hex(uint32_t(adj)).substr(2);
                    if (vd) detail += "," + hex(uint32_t(vd)).substr(2);
                    ++nThunks;
                    thunkFns.insert(t);
                } else if (deletingFns.count(t)) {
                    kind = "deleting-dtor";
                    ++nDeleting;
                    deletingInSlots.insert(t);
                } else {
                    kind = "own";
                    ++nOwn;
                }
                slotLines[vt] += hex(vt).substr(2) + "\t" + std::to_string(i) + "\t" + hex(t).substr(2) + "\t" + kind +
                                 "\t" + detail + "\n";
            }
        }
    }

    if (!deletingOut.empty()) {
        std::ofstream f(deletingOut);
        for (auto& [va, ds] : deletingShape)
            f << hex(va).substr(2) << '\t' << ds.shape << '\t' << (ds.dtor ? hex(ds.dtor).substr(2) : "-") << '\t'
              << (ds.popEcx ? "O1" : "O2") << '\n';
    }
    if (!classesOut.empty()) {
        std::ofstream f(classesOut);
        for (auto& [primary, c] : classes) {
            std::set<std::pair<int32_t, uint32_t>> lay(c.layout.begin(), c.layout.end());
            std::string flags;
            for (auto& fl : c.flags) flags += (flags.empty() ? "" : ",") + fl;
            f << hex(primary).substr(2) << '\t' << list(c.sizes) << '\t' << offsets(lay) << '\t' << offsets(c.bases)
              << '\t' << offsets(c.members) << '\t' << list(c.ctors) << '\t' << list(c.dtors) << '\t'
              << list(c.deleting) << '\t' << list(c.sites) << '\t' << (flags.empty() ? "-" : flags) << '\t'
              << offsets(c.virtualBases) << '\n';
        }
    }
    if (!slotsOut.empty()) {
        std::ofstream f(slotsOut);
        for (auto& [vt, lines] : slotLines) f << lines;
    }

    size_t withSize = 0, withBase = 0;
    for (auto& [primary, c] : classes) {
        withSize += !c.sizes.empty();
        withBase += !c.bases.empty();
    }
    std::printf("vtables %zu, placed in a class %zu\n", p.vtables.size(), placed.size());
    std::printf("classes %zu: with a size %zu, with a base %zu\n", classes.size(), withSize, withBase);
    std::printf("slots: own %zu, inherited %zu, thunks %zu (%zu functions), deleting destructors %zu (%zu functions)\n",
                nOwn, nInherited, nThunks, thunkFns.size(), nDeleting, deletingInSlots.size());
    return 0;
}
