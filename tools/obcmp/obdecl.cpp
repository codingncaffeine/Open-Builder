// obdecl — writes C++ declarations of the classes obclass recovered, so the 2003 compiler generates what it generated
// for them in the original: their vtables, adjustor thunks and deleting destructors.
//
//   obdecl <classes.tsv> <slots.tsv> <deleting.tsv> <known.tsv> [--purecall ADDR] [--src DIR] [--out DIR]
//          [--report FILE] [--exclude FILE]
//
// classes.tsv, slots.tsv, deleting.tsv: obclass output. known.tsv: the slots of the classes declared by hand
// (tools/known-slots.sh), which generated classes derive from by name; hand classes are found by their
// "// VTABLE:" annotations under --src (default src) and never written. Output under --out (default src/classes):
//   <class>.h            one header per class, marked GENERATED (a header without the mark is never overwritten)
//   stubs.txt            "0x<address> <decorated>" for every declared method not decompiled (tools/gen-stubs.sh)
// and --src/game/GeneratedClasses_game.cpp, --src/gzcom/GeneratedClasses_gzcom.cpp: one `new` of every concrete class, in the
// folder whose flags its deleting destructor was built with, so the compiler emits its vtables, thunks and deleting
// destructor there.
//
// How a class is declared:
// - Its bases are the classes obclass found; every vtable no base covers is a synthesized subobject
//   (<class>_<offset>, no vtable of its own, pure virtual slots, padding up to the next subobject: the compiler puts
//   polymorphic bases first, so a gap between two vtables is the earlier subobject's data). When a class has more
//   than one vtable and no base at 0, offset 0 is a synthesized subobject too.
// - A slot holding "sub/add ecx,N; jmp F" with N other than its vtable's offset is the class's own method (a
//   one-line forward to a base's), not a thunk.
// - Slots are "void SlotNN()" by index, overrides take the overridden slot's name and signature (a hand class's from
//   known.tsv), a slot reached through a thunk takes the name of the primary slot holding the same function (one
//   function, one name) or "FnXXXXXXXX" after the function.
// - The destructor is declared out of line (stubbed to the original's) when the deleting destructor calls it, inline
//   otherwise.
// Annotations: VTABLE for every vtable of a concrete class, SYNTHETIC for its own adjustor thunks and for a deleting
// destructor whose code follows from the declaration (deleting.tsv "call", or "stores" with every base's
// destructor inline). A class that cannot be declared this way is reported with the reason, not written.

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <functional>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

namespace {

std::string hex8(uint32_t v) {
    char b[16];
    std::snprintf(b, sizeof b, "%08x", v);
    return b;
}
std::string hexn(uint32_t v) {
    char b[16];
    std::snprintf(b, sizeof b, "%x", v);
    return b;
}
uint32_t parseHex(const std::string& s) { return uint32_t(std::stoul(s, nullptr, 16)); }

std::vector<std::string> split(const std::string& s, char c) {
    std::vector<std::string> out;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, c)) out.push_back(item);
    return out;
}

std::vector<std::vector<std::string>> readTsv(const std::string& path) {
    std::vector<std::vector<std::string>> rows;
    std::ifstream f(path);
    if (!f) {
        std::fprintf(stderr, "cannot read %s\n", path.c_str());
        std::exit(2);
    }
    std::string line;
    while (std::getline(f, line))
        if (!line.empty() && line[0] != '#') rows.push_back(split(line, '\t'));
    return rows;
}

struct Slot {
    uint32_t target = 0;
    std::string kind;  // own, inherited, thunk, thunk-vtordisp, deleting-dtor
    uint32_t method = 0;
    int32_t adj = 0;
    bool addForm = false;  // add ecx,-N: not a thunk the compiler writes, so never annotated
};

struct Record {  // a class as obclass found it
    uint32_t primary = 0;
    uint32_t size = 0;  // the smallest seen, 0 = unknown
    std::map<int32_t, uint32_t> layout;
    std::vector<std::pair<int32_t, uint32_t>> bases;
    bool virtualBases = false, conflict = false;
};

struct Deleting {
    std::string shape;
    uint32_t dtor = 0;
    bool o1 = false;
};

// A virtual function as the class that introduced it declares it. Slots filled by one function of a class through
// a thunk belong to one function in the source, so their identities are merged (union-find) and named once.
struct Ident {
    int parent = 0;
    std::string name, decl, tail;  // "Slot03_a80710", "void Slot03_a80710()", decorated after "@Class@@"
    bool fixed = false;            // a hand class's: name and signature given
    bool dtor = false;
};

// A function a class declares (overrides or introduces), standing for one of the original's.
struct Decl {
    std::string owner;  // the class, or one of its synthesized subobjects or intermediates
    int ident;
    uint32_t function;
};

struct Sub {
    int32_t off;
    uint32_t base;  // a class's primary vtable, or 0 for a synthesized subobject
    uint32_t size;
    // An intermediate class between the base and this one, never seen on its own (its constructor was always
    // inlined): it overrides some of the base's slots with functions whose this is the base subobject.
    bool intermediate;
};

struct Model {
    bool done = false, ok = false, hand = false, abstract = false;
    std::string why, name, header;
    uint32_t primary = 0, size = 0, end = 0;
    std::map<int32_t, uint32_t> layout;
    std::map<int32_t, std::vector<int>> ids;            // slot identities by offset in this class
    std::map<int32_t, std::vector<std::string>> owner;  // the final overrider's class per slot, "" = pure
    std::map<int32_t, std::string> root;                // the class a vtable at that offset is named after
    std::map<int32_t, size_t> inherited;                // slots a vtable has from the base there
    std::map<int32_t, std::string> synthName;           // synthesized subobjects by offset
    std::vector<Sub> subs;
    std::vector<Decl> decls;
    std::vector<int> pureAgain;  // defined slots this class declares pure again
    std::vector<std::pair<uint32_t, std::pair<int32_t, size_t>>> thunks;  // thunk address, its slot
    bool hasDtor = false, inlineDtor = true, o1 = false;
    bool assumedSize = false;  // no SIZE annotation: the size is a guess the derived classes check
    uint32_t ownDeleting = 0;
    std::vector<std::string> includes;
};

struct Hand {
    std::string name, header;
    std::string base;  // first base, for the root of its vtable names
    uint32_t size = 0;
    bool inlineDtor = false;
    std::vector<std::pair<uint32_t, std::string>> vtables;  // original vtable, base suffix
};

// "public: virtual bool __thiscall cRZString::QueryInterface(unsigned int, void **)" -> name and declaration.
bool parseDemangled(const std::string& d, std::string& name, std::string& decl, bool& dtor) {
    dtor = d.find("deleting dtor'") != std::string::npos;
    std::string s = d;
    for (const char* p : {"public: ", "protected: ", "private: ", "virtual "})
        if (s.rfind(p, 0) == 0) s = s.substr(std::string(p).size());
    size_t cc = s.find(" __thiscall ");
    size_t clen = 12;
    if (cc == std::string::npos) { cc = s.find(" __cdecl "); clen = 9; }
    if (cc == std::string::npos) return false;
    std::string ret = s.substr(0, cc), rest = s.substr(cc + clen);
    size_t colons = rest.find("::");
    size_t paren = rest.find('(');
    if (colons == std::string::npos || paren == std::string::npos) return false;
    name = rest.substr(colons + 2, paren - colons - 2);
    std::string params = rest.substr(paren);
    auto strip = [](std::string t) {
        for (const char* k : {"class ", "struct ", "enum "}) {
            size_t at;
            while ((at = t.find(k)) != std::string::npos) t.erase(at, std::string(k).size());
        }
        return t;
    };
    if (params == "(void)") params = "()";
    decl = strip(ret) + " " + name + strip(params);
    return true;
}

}  // namespace

int main(int argc, char** argv) {
    std::vector<std::string> pos;
    std::string srcDir = "src", outDir = "src/classes", reportPath, excludePath;
    uint32_t purecall = 0;
    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        auto value = [&]() -> std::string {
            if (i + 1 >= argc) { std::fprintf(stderr, "%s needs a value\n", a.c_str()); std::exit(2); }
            return argv[++i];
        };
        if (a == "--purecall") purecall = parseHex(value());
        else if (a == "--src") srcDir = value();
        else if (a == "--out") outDir = value();
        else if (a == "--report") reportPath = value();
        else if (a == "--exclude") excludePath = value();
        else pos.push_back(a);
    }
    if (pos.size() != 4) {
        std::fprintf(stderr, "usage: obdecl <classes.tsv> <slots.tsv> <deleting.tsv> <known.tsv> [--purecall ADDR] "
                             "[--src DIR] [--out DIR] [--report FILE]\n");
        return 2;
    }

    // Inputs.
    std::set<uint32_t> excluded;  // classes not to write (a regenerating tool found their size check failing)
    if (!excludePath.empty()) {
        std::ifstream ex(excludePath);
        std::string a;
        while (ex >> a) excluded.insert(parseHex(a));
    }
    std::map<uint32_t, Record> recs;
    std::map<uint32_t, uint32_t> vtableClass;  // vtable -> primary of its class
    for (auto& r : readTsv(pos[0])) {
        if (r.size() < 11) continue;
        Record rec;
        rec.primary = parseHex(r[0]);
        if (r[1] != "-") {
            rec.size = 0xffffffffu;
            for (auto& s : split(r[1], ',')) rec.size = std::min(rec.size, parseHex(s));
        }
        for (auto& e : split(r[2], ',')) {
            auto kv = split(e, ':');
            if (kv.size() == 2) rec.layout[int32_t(parseHex(kv[0]))] = parseHex(kv[1]);
        }
        if (r[3] != "-")
            for (auto& e : split(r[3], ',')) {
                auto kv = split(e, ':');
                if (kv.size() == 2) rec.bases.push_back({int32_t(parseHex(kv[0])), parseHex(kv[1])});
            }
        std::sort(rec.bases.begin(), rec.bases.end());
        rec.virtualBases = r[10] != "-";
        rec.conflict = r[9].find("layout-conflict") != std::string::npos;
        for (auto& [o, v] : rec.layout) vtableClass[v] = rec.primary;
        recs[rec.primary] = rec;
    }
    std::map<uint32_t, std::vector<Slot>> slots;
    for (auto& r : readTsv(pos[1])) {
        if (r.size() < 5) continue;
        Slot s;
        s.target = parseHex(r[2]);
        s.kind = r[3];
        if (s.kind == "thunk-add") { s.kind = "thunk"; s.addForm = true; }  // not the compiler's encoding
        if (s.kind == "thunk" || s.kind == "thunk-vtordisp") {
            auto d = split(r[4], ',');
            s.method = parseHex(d[0]);
            s.adj = int32_t(parseHex(d[1]));
        }
        auto& v = slots[parseHex(r[0])];
        size_t i = std::stoul(r[1]);
        if (v.size() <= i) v.resize(i + 1);
        v[i] = s;
    }
    // Functions in vtables at two or more different slot indices: bodies the linker folded (/OPT:ICF) for several
    // methods, so the same function in two slots says nothing about their being one method.
    std::set<uint32_t> folded_;
    {
        std::map<uint32_t, std::set<size_t>> indices;
        for (auto& [v, vs] : slots)
            for (size_t i = 0; i < vs.size(); ++i)
                if (vs[i].kind != "thunk" && vs[i].kind != "thunk-vtordisp") indices[vs[i].target].insert(i);
        for (auto& [fn, is] : indices)
            if (is.size() > 1) folded_.insert(fn);
    }
    std::map<uint32_t, Deleting> deleting;
    for (auto& r : readTsv(pos[2]))
        if (r.size() >= 4) deleting[parseHex(r[0])] = {r[1], r[2] == "-" ? 0u : parseHex(r[2]), r[3] == "O1"};
    std::map<uint32_t, std::map<int, std::pair<std::string, std::string>>> known;  // vtable -> slot -> decorated, demangled
    for (auto& r : readTsv(pos[3]))
        if (r.size() >= 4) known[parseHex(r[0])][std::stoi(r[1])] = {r[2], r[3]};

    // Hand-declared classes: their VTABLE annotations, header, first base, size and destructor.
    std::map<uint32_t, Hand> hands;  // by primary
    std::map<std::string, std::string> firstBase;  // class -> first base, over every header
    for (auto& entry : fs::recursive_directory_iterator(srcDir)) {
        if (!entry.is_regular_file()) continue;
        std::string ext = entry.path().extension().string();
        if (ext != ".h" && ext != ".cpp") continue;
        std::string rel = fs::relative(entry.path(), srcDir).generic_string();
        if (rel.rfind(fs::relative(outDir, srcDir).generic_string() + "/", 0) == 0) continue;  // our own output
        std::ifstream f(entry.path());
        std::string line;
        std::vector<std::pair<uint32_t, std::string>> pending;
        uint32_t size = 0;
        Hand* current = nullptr;
        while (std::getline(f, line)) {
            size_t at;
            if ((at = line.find("// VTABLE: 0x")) != std::string::npos) {
                std::istringstream ss(line.substr(at + 11));
                std::string addr, base;
                ss >> addr >> base;
                pending.push_back({parseHex(addr), base});
                continue;
            }
            if ((at = line.find("// SIZE 0x")) != std::string::npos) { size = parseHex(line.substr(at + 8)); continue; }
            std::istringstream ss(line);
            std::string kw, name, colon, access, base;
            ss >> kw;
            if (kw == "class" || kw == "struct") {
                ss >> name;
                if (name == "OB_NOVTABLE") ss >> name;
                if (!name.empty() && name.back() == ';') continue;  // a forward declaration
                if (ss >> colon && colon == ":" && ss >> access >> base) {
                    if (!base.empty() && base.back() == ',') base.pop_back();
                    if (base == "{") base.clear();
                    firstBase[name] = base;
                }
                if (!pending.empty()) {
                    uint32_t primary = pending.front().first;
                    for (auto& [v, b] : pending)
                        if (recs.count(v)) primary = v;
                    Hand h;
                    h.name = name;
                    h.header = rel;
                    h.size = size;
                    h.vtables = pending;
                    hands[primary] = h;
                    current = &hands[primary];
                    pending.clear();
                    size = 0;
                }
                continue;
            }
            if (current && line.find("virtual ~" + current->name + "() {}") != std::string::npos) current->inlineDtor = true;
        }
    }
    for (auto& [p, h] : hands) {
        std::string b = firstBase.count(h.name) ? firstBase[h.name] : "";
        h.base = b;
    }

    // Sizes implied by derived classes: a base followed by another subobject ends where that one starts.
    std::map<uint32_t, std::set<uint32_t>> implied;
    auto covered = [&](const Record& r, int32_t k) {
        for (auto& [bo, b] : r.bases) {
            auto it = recs.find(b);
            if (it != recs.end() && it->second.layout.count(k - bo)) return true;
        }
        return false;
    };
    for (auto& [p, r] : recs) {
        if (r.virtualBases) continue;  // its virtual bases sit at the end, after its own data
        std::vector<std::pair<int32_t, uint32_t>> subs(r.bases.begin(), r.bases.end());
        for (auto& [k, v] : r.layout)
            if (!covered(r, k)) subs.push_back({k, 0});
        std::sort(subs.begin(), subs.end());
        for (size_t i = 0; i + 1 < subs.size(); ++i)
            if (subs[i].second) implied[subs[i].second].insert(uint32_t(subs[i + 1].first - subs[i].first));
    }

    // Identities, merged by union-find.
    std::vector<Ident> idents;
    std::function<int(int)> find = [&](int i) { return idents[i].parent == i ? i : idents[i].parent = find(idents[i].parent); };
    auto newIdent = [&](const std::string& name, bool dtor) {
        Ident id;
        id.parent = int(idents.size());
        id.name = name;
        id.decl = "void " + name + "()";
        id.tail = "UAEXXZ";
        id.dtor = dtor;
        idents.push_back(id);
        return id.parent;
    };
    std::set<int> conflicted;  // roots two different fixed names were merged into
    auto unite = [&](int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (idents[a].dtor != idents[b].dtor) { conflicted.insert(a); conflicted.insert(b); }
        if (idents[a].fixed && idents[b].fixed && idents[a].decl != idents[b].decl) conflicted.insert(a);
        if (idents[b].fixed && !idents[a].fixed) std::swap(a, b);  // the fixed one is the root
        idents[b].parent = a;
        if (conflicted.count(b)) conflicted.insert(a);
    };

    std::map<uint32_t, Model> models;
    std::function<Model&(uint32_t)> model = [&](uint32_t primary) -> Model& {
        Model& m = models[primary];
        if (m.done) return m;
        m.done = true;
        m.primary = primary;
        auto fail = [&](const std::string& why) -> Model& {
            m.ok = false;
            m.why = why;
            return m;
        };
        auto rit = recs.find(primary);
        if (rit == recs.end()) return fail("no record");
        const Record& r = rit->second;
        m.layout = r.layout;

        // A hand class: names and signatures from its compiled vtables.
        if (hands.count(primary)) {
            const Hand& h = hands[primary];
            m.hand = true;
            m.name = h.name;
            m.header = h.header;
            m.size = h.size;
            m.inlineDtor = h.inlineDtor;
            for (auto& [o, v] : r.layout) {
                auto kit = known.find(v);
                if (kit == known.end()) return fail("hand class vtable " + hex8(v) + " not in known.tsv");
                for (auto& [i, dd] : kit->second) {
                    std::string name, decl;
                    bool dtor;
                    if (!parseDemangled(dd.second, name, decl, dtor)) return fail("cannot read " + dd.second);
                    int id = newIdent(name, dtor);
                    idents[id].decl = decl;
                    idents[id].fixed = true;
                    // the qualifier is the first "Class@@" ("?Name@Class@@...", "??4Class@@...")
                    std::string dec = dd.first, marker = h.name + "@@";
                    size_t at = dec.find(marker);
                    idents[id].tail = at == std::string::npos ? "" : dec.substr(at + marker.size());
                    auto& ids = m.ids[o];
                    auto& own = m.owner[o];
                    if (int(ids.size()) <= i) { ids.resize(i + 1, -1); own.resize(i + 1); }
                    ids[i] = id;
                    own[i] = h.name;
                    if (dtor) m.hasDtor = true;
                }
                // how a derived class names this vtable: the class itself when it has one, else its own name for it
                std::string suffix;
                for (auto& [hv, hb] : h.vtables)
                    if (hv == v) suffix = hb;
                m.root[o] = r.layout.size() == 1 || suffix.empty() ? h.name : suffix;
            }
            m.ok = true;
            return m;
        }

        m.name = "cUnk" + hex8(primary);
        m.header = fs::relative(outDir, srcDir).generic_string() + "/" + m.name + ".h";
        std::string tag = hexn(primary);
        if (r.virtualBases) return fail("virtual bases");
        if (excluded.count(primary)) return fail("excluded");
        if (r.conflict) return fail("layout conflict");
        for (auto& [o, v] : r.layout)
            if (!slots.count(v)) return fail("vtable " + hex8(v) + " has no slots");
        m.size = r.size;
        if (!m.size && implied.count(primary) && implied[primary].size() == 1) m.size = *implied[primary].begin();
        if (!m.size && implied.count(primary) && implied[primary].size() > 1) return fail("derived classes need different sizes");
        // A lone vtable with no base and no size from anywhere: assumed to be an interface, just its vtable pointer.
        // Every derived class of known size checks it at compile time (the size typedef), and tools that regenerate
        // exclude a class whose check fails (--exclude).
        if (!m.size && r.layout.size() == 1 && r.bases.empty()) { m.size = 4; m.assumedSize = true; }
        if (r.size && implied.count(primary))
            for (uint32_t s : implied[primary])
                if (s != r.size) return fail("size " + hexn(r.size) + " but a derived class needs " + hexn(s));

        // Subobjects in offset order.
        for (auto& [bo, b] : r.bases) {
            Model& bm = model(b);
            if (!bm.ok) return fail("base " + hex8(b) + ": " + bm.why);
            m.subs.push_back({bo, b, bm.size, false});
            m.includes.push_back(bm.header);
        }
        for (auto& [k, v] : r.layout)
            if (!covered(r, k) && (k != 0 || r.layout.size() > 1 || !r.bases.empty())) m.subs.push_back({k, 0, 0, false});
        std::sort(m.subs.begin(), m.subs.end(), [](const Sub& a, const Sub& b) { return a.off < b.off; });
        if (!m.subs.empty() && m.subs.front().off != 0) return fail("no subobject at 0");
        for (size_t i = 0; i < m.subs.size(); ++i) {
            Sub& s = m.subs[i];
            if (i + 1 < m.subs.size()) {
                uint32_t gap = uint32_t(m.subs[i + 1].off - s.off);
                if (s.base && !s.size) return fail("base " + hex8(s.base) + " of unknown size before another subobject");
                if (s.base && s.size != gap)
                    return fail("base " + hex8(s.base) + " is " + hexn(s.size) + " bytes, the next subobject is " + hexn(gap) + " on");
                if (!s.base && gap < 4) return fail("subobjects overlap");
                s.size = gap;
            } else if (!s.base) {
                s.size = 4;
            }
        }
        m.end = m.subs.empty() ? 4 : m.subs.back().off + m.subs.back().size;  // a lone vtable pointer ends at 4
        if (!m.subs.empty() && m.subs.back().base && !m.subs.back().size) {
            if (m.size) return fail("last base " + hex8(m.subs.back().base) + " of unknown size");
            m.end = 0;  // unknown
        }
        if (m.size && m.end && m.size < m.end) return fail("size " + hexn(m.size) + " smaller than its subobjects");

        // Identities and final overriders as the bases have them.
        for (auto& s : m.subs) {
            if (!s.base) continue;
            Model& bm = models[s.base];
            for (auto& [o, ids] : bm.ids) m.ids[s.off + o] = ids;
            for (auto& [o, own] : bm.owner) m.owner[s.off + o] = own;
            // a vtable is named after the direct base holding it, or that base's own name for it when it has several
            for (auto& [o, rn] : bm.root)
                m.root[s.off + o] = bm.layout.size() == 1 ? (s.intermediate ? m.name + "_" + hexn(uint32_t(s.off)) : bm.name) : rn;
            if (bm.hasDtor && !bm.inlineDtor) m.inlineDtor = false;  // reconsidered below for this class's own
        }
        for (auto& s : m.subs)
            if (!s.base) {
                m.synthName[s.off] = m.name + "_" + hexn(uint32_t(s.off));
                m.root[s.off] = m.synthName[s.off];
            }
        bool introduces = m.subs.empty();  // a lone vtable and no base: the class declares its slots itself
        if (introduces) m.root[0] = m.name;
        bool basesInline = true;
        for (auto& s : m.subs)
            if (s.base && models[s.base].hasDtor && !models[s.base].inlineDtor) basesInline = false;
        m.inlineDtor = true;

        // A function this class declares, and whether through a thunk: one function in a primary slot and behind a
        // thunk (or behind two thunks) is one method, so their identities merge; two primary slots with one body are
        // two methods the linker folded, and so is any body found at several slot indices.
        std::map<uint32_t, std::pair<int, bool>> declaredFn;
        auto declare = [&](const std::string& owner, int id, uint32_t fn, bool viaThunk) {
            m.decls.push_back({owner, id, fn});
            auto it = declaredFn.find(fn);
            if (it == declaredFn.end()) { declaredFn[fn] = {id, viaThunk}; return; }
            if (viaThunk || (it->second.second && !folded_.count(fn))) unite(it->second.first, id);
            it->second.second = it->second.second || viaThunk;
        };
        // Offset 0 first, so a thunk to a function of the primary vtable merges with that slot.
        const std::vector<Slot>& primarySlots = slots[r.layout.at(0)];
        for (auto& [k, v] : r.layout) {
            const std::vector<Slot>& vs = slots[v];
            auto& ids = m.ids[k];
            auto& own = m.owner[k];
            bool synth = m.synthName.count(k) > 0;
            if (synth || introduces) { ids.clear(); own.clear(); }
            size_t inherited = ids.size();
            m.inherited[k] = inherited;
            if (inherited > vs.size()) return fail("vtable " + hex8(v) + " shorter than its base's");
            if (!synth && !introduces && k != 0 && vs.size() > inherited) return fail("new slots in a secondary vtable");
            ids.resize(vs.size(), -1);
            own.resize(vs.size());
            for (size_t j = 0; j < vs.size(); ++j) {
                Slot s = vs[j];
                // "sub/add ecx,N; jmp F" with N not this vtable's offset is no thunk the compiler made but a method
                // that forwards to a base's (return Base::F(), compiled to the same two instructions).
                if (s.kind == "thunk" && s.adj != k) s.kind = "own";
                bool isDeleting = s.kind == "deleting-dtor" || (s.kind == "thunk" && deleting.count(s.method));
                bool isPure = purecall && s.target == purecall;
                if (j >= inherited) {
                    char b[48];
                    if (synth && k != 0) std::snprintf(b, sizeof b, "Slot%02zu_%s_%x", j, tag.c_str(), unsigned(k));
                    else std::snprintf(b, sizeof b, "Slot%02zu_%s", j, tag.c_str());
                    ids[j] = newIdent(isDeleting ? "~" : b, isDeleting);
                    own[j].clear();
                }
                if (s.kind == "inherited") {
                    if (j >= inherited) return fail("slot " + std::to_string(j) + " of " + hex8(v) + " inherited from nothing");
                    continue;
                }
                if (isPure) {
                    // a derived class may declare a defined function pure again (C++ allows it): it is abstract then
                    if (j < inherited && !own[j].empty()) m.pureAgain.push_back(ids[j]);
                    own[j].clear();
                    continue;
                }
                // A destructor's slot holds this class's deleting destructor, whatever its code looks like.
                if (!isDeleting && idents[find(ids[j])].dtor && (s.kind == "own" || s.kind == "thunk")) isDeleting = true;
                if (isDeleting) {
                    if (!idents[find(ids[j])].dtor) return fail("deleting destructor in a slot that is no destructor");
                    m.hasDtor = true;
                    own[j] = m.name;
                    if (s.kind == "thunk") m.thunks.push_back({s.target, {k, j}});
                    else if (k == 0) m.ownDeleting = s.target;
                    continue;
                }
                if (s.kind == "thunk-vtordisp") return fail("vtordisp thunk");
                if (s.kind == "thunk") {
                    // This class's function, also in the primary vtable when it overrides a slot there too (unless
                    // the linker folded it with others: then the same body is no evidence of the same method).
                    declare(m.name, ids[j], s.method, true);
                    own[j] = m.name;
                    for (size_t i = 0; i < primarySlots.size() && k != 0; ++i)
                        if (primarySlots[i].target == s.method && m.ids[0][i] >= 0) {
                            unite(m.ids[0][i], ids[j]);
                            if (m.owner[0][i] != m.name) { m.owner[0][i] = m.name; declare(m.name, m.ids[0][i], s.method, true); }
                        }
                    if (!s.addForm) m.thunks.push_back({s.target, {k, j}});
                    continue;
                }
                // own: the function sits in the slot unadjusted, so its this is the subobject at k
                if (k == 0) {
                    declare(m.name, ids[j], s.target, false);
                    own[j] = m.name;
                } else if (synth) {
                    declare(m.synthName[k], ids[j], s.target, false);
                    own[j] = m.synthName[k];
                } else {
                    Sub* at = nullptr;
                    for (auto& sub : m.subs)
                        if (sub.base && sub.off == k) at = &sub;
                    if (!at || j >= inherited) return fail("own function in a secondary vtable without a thunk");
                    at->intermediate = true;
                    std::string in = m.name + "_" + hexn(uint32_t(k));
                    declare(in, ids[j], s.target, false);
                    own[j] = in;
                }
            }
        }

        // The destructor: out of line (stubbed) when the deleting destructor calls it.
        if (m.hasDtor) {
            auto dit = deleting.find(m.ownDeleting);
            if (dit != deleting.end()) {
                m.o1 = dit->second.o1;
                if (dit->second.shape == "call") m.inlineDtor = false;
            }
        }
        (void)basesInline;
        for (auto& [k, own] : m.owner)
            for (size_t j = 0; j < own.size(); ++j)
                if (own[j].empty() && m.ids[k][j] >= 0 && !idents[m.ids[k][j]].dtor) m.abstract = true;
        // Vtable names: an intermediate class (known only now) names those it holds when its base has one vtable;
        // a class with one vtable is named by itself in a derived class.
        for (auto& s : m.subs)
            if (s.base && s.intermediate && models[s.base].layout.size() == 1) m.root[s.off] = m.name + "_" + hexn(uint32_t(s.off));
        if (m.layout.size() == 1) m.root[0] = m.name;
        m.ok = true;
        return m;
    };

    for (auto& [p, r] : recs) model(p);

    // Names: every identity takes its root's; a root merged from two different fixed names cannot be declared.
    auto nameOf = [&](int id) -> const Ident& { return idents[find(id)]; };

    // Output.
    fs::create_directories(outDir);
    size_t written = 0, kept = 0, failed = 0, synthCount = 0, vtCount = 0;
    std::map<std::string, size_t> reasons;
    std::ofstream report(reportPath.empty() ? "/dev/null" : reportPath);
    std::vector<std::string> instO1, instO2;
    std::ofstream stubs(outDir + "/stubs.txt");
    stubs << "# Generated by tools/obcmp/obdecl: the methods the generated classes declare, each leading to the original's\n"
             "# function until it is decompiled (tools/gen-stubs.sh). \"0x<address> <decorated>\".\n";
    std::set<uint32_t> thunkTaken, deletingTaken;
    // Game classes (/O2) a framework class (/O1) derives from: the framework's instantiations link first, so their copy
    // of the base's deleting destructor (built with /O1) is the one kept, and it cannot match.
    std::set<uint32_t> displaced;
    std::function<void(uint32_t)> markBases = [&](uint32_t p) {
        for (auto& s : models[p].subs)
            if (s.base && !models[s.base].hand) {
                if (!models[s.base].o1) displaced.insert(s.base);
                markBases(s.base);
            }
    };
    for (auto& [p, m] : models)
        if (m.ok && !m.hand && m.o1 && !m.abstract) markBases(p);
    // A class fails when its base failed (here, after the names) too.
    std::function<bool(uint32_t)> usable = [&](uint32_t p) -> bool {
        Model& m = models[p];
        if (!m.ok) return false;
        if (m.hand) return true;
        for (auto& s : m.subs)
            if (s.base && !usable(s.base)) {
                m.ok = false;
                m.why = "base " + hex8(s.base) + ": " + models[s.base].why;
                return false;
            }
        // every declaration under one name per owner, one function per name
        std::map<std::pair<std::string, std::string>, uint32_t> byName;
        for (auto& d : m.decls) {
            int root = find(d.ident);
            if (conflicted.count(root)) { m.ok = false; m.why = "merged slots of different names: " + idents[root].name; return false; }
            auto key = std::make_pair(d.owner, idents[root].name);
            auto it = byName.find(key);
            if (it != byName.end() && it->second != d.function) {
                m.ok = false;
                m.why = "one name, two functions: " + idents[root].name;
                return false;
            }
            byName[key] = d.function;
        }
        return true;
    };
    for (auto& [p, m] : models) {
        if (m.hand) continue;
        if (!usable(p)) {
            ++failed;
            std::string why = m.why;
            while (why.rfind("base ", 0) == 0 && why.find(": ") != std::string::npos) why = why.substr(why.find(": ") + 2);
            ++reasons[why.substr(0, why.find_first_of("0123456789"))];
            report << hex8(p) << "\t" << m.why << "\n";
            continue;
        }
        std::string path = srcDir + "/" + m.header;
        if (fs::exists(path)) {
            std::ifstream in(path);
            std::string first;
            std::getline(in, first);
            if (first.find("GENERATED") == std::string::npos) { ++kept; continue; }
        }
        // Declarations by owner, one per name.
        std::map<std::string, std::vector<std::string>> body;
        std::map<std::string, std::set<std::string>> seenName;
        std::vector<std::pair<uint32_t, std::string>> stubList;
        auto emit = [&](const std::string& owner, int id, uint32_t fn, bool pure) {
            const Ident& n = nameOf(id);
            if (!seenName[owner].insert(n.name).second) return;
            body[owner].push_back("virtual " + n.decl + (pure ? " = 0;" : ";"));
            // operator= is ??4Class@@..., every other method ?Name@Class@@...
            std::string head = n.name == "operator=" ? "??4" : "?" + n.name + "@";
            if (!pure) stubList.push_back({fn, head + owner + "@@" + (n.tail.empty() ? "UAEXXZ" : n.tail)});
        };
        std::map<std::pair<std::string, int>, uint32_t> fnOf;  // owner, root -> function
        for (auto& d : m.decls) fnOf[{d.owner, find(d.ident)}] = d.function;
        // synthesized subobjects: every slot, in order
        std::vector<std::string> synthesized;
        for (auto& s : m.subs) {
            std::ostringstream d;
            if (s.base && s.intermediate) {
                std::string in = m.name + "_" + hexn(uint32_t(s.off));
                for (auto& [key, fn] : fnOf)
                    if (key.first == in) emit(in, key.second, fn, false);
                d << "// Between " << models[s.base].name << " and " << m.name << " at +0x" << hexn(uint32_t(s.off))
                  << ": a class the map never saw on its own, overriding these.\n";
                d << "struct OB_NOVTABLE " << in << " : public " << models[s.base].name << " {\n";
                for (auto& line : body[in]) d << "    " << line << "\n";
                d << "};\n";
                synthesized.push_back(d.str());
                continue;
            }
            if (s.base) continue;
            std::string sn = m.synthName[s.off];
            d << "// The subobject at +0x" << hexn(uint32_t(s.off)) << " (vtable 0x" << hex8(m.layout.at(s.off))
              << "): an interface or base the class map has no class for.\n";
            d << "struct OB_NOVTABLE " << sn << " {\n";
            for (size_t j = 0; j < m.ids[s.off].size(); ++j) {
                int id = m.ids[s.off][j];
                if (nameOf(id).dtor) { d << "    virtual ~" << sn << "() {}\n"; continue; }
                auto it = fnOf.find({sn, find(id)});
                if (it != fnOf.end()) {
                    emit(sn, id, it->second, false);
                    d << "    virtual " << nameOf(id).decl << ";\n";
                } else if (seenName[sn].insert(nameOf(id).name).second) {
                    d << "    virtual " << nameOf(id).decl << " = 0;\n";
                }
            }
            if (s.size > 4) d << "    char unknown04[0x" << hexn(s.size - 4) << "];\n";
            d << "};\n";
            synthesized.push_back(d.str());
        }
        // the class: slots it adds to its primary vtable in slot order, the destructor in its place among them, then
        // its overrides
        std::vector<std::string> lines;
        std::string dtorDecl = m.inlineDtor ? "virtual ~" + m.name + "() {}" : "virtual ~" + m.name + "();";
        bool dtorWritten = false;
        if (!m.synthName.count(0)) {
            auto& ids = m.ids[0];
            for (size_t j = m.inherited[0]; j < ids.size(); ++j) {
                const Ident& n = nameOf(ids[j]);
                if (n.dtor) {
                    if (m.hasDtor) { lines.push_back(dtorDecl); dtorWritten = true; }
                    continue;
                }
                auto it = fnOf.find({m.name, find(ids[j])});
                if (it != fnOf.end()) emit(m.name, ids[j], it->second, false);
                else if (seenName[m.name].insert(n.name).second) body[m.name].push_back("virtual " + n.decl + " = 0;");
                if (!body[m.name].empty()) { lines.push_back(body[m.name].back()); body[m.name].pop_back(); }
            }
        }
        if (m.hasDtor && !dtorWritten) lines.insert(lines.begin(), dtorDecl);
        for (auto& [key, fn] : fnOf)
            if (key.first == m.name) emit(m.name, key.second, fn, false);
        for (int id : m.pureAgain)
            if (seenName[m.name].insert(nameOf(id).name).second) body[m.name].push_back("virtual " + nameOf(id).decl + " = 0;");
        for (auto& line : body[m.name]) lines.push_back(line);
        // a base's virtual operator= stays visible beside the implicit copy assignment (no code changes)
        for (auto& s : m.subs) {
            if (!s.base) continue;
            bool has = false;
            for (auto& [o, ids] : models[s.base].ids)
                for (int id : ids) has |= id >= 0 && nameOf(id).name == "operator=";
            if (has) lines.push_back("using " + (s.intermediate ? m.name + "_" + hexn(uint32_t(s.off)) : models[s.base].name) + "::operator=;");
        }
        if (m.size > m.end && m.end) lines.push_back("char unknown" + hexn(m.end) + "[0x" + hexn(m.size - m.end) + "];");
        if (m.hasDtor && !m.inlineDtor) {
            auto dit = deleting.find(m.ownDeleting);
            if (dit != deleting.end()) stubList.push_back({dit->second.dtor, "??1" + m.name + "@@UAE@XZ"});
        }

        // Annotations of what the compiler makes for a concrete class.
        std::vector<std::pair<uint32_t, std::string>> vtables, synthetic;
        if (!m.abstract) {
            bool several = m.layout.size() > 1;
            for (auto& [k, v] : m.layout) vtables.push_back({v, several ? m.root[k] : ""});
            auto dit = deleting.find(m.ownDeleting);
            bool basesInline = true;
            for (auto& s : m.subs)
                if (s.base && models[s.base].hasDtor && !models[s.base].inlineDtor) basesInline = false;
            if (m.ownDeleting && dit != deleting.end() && !deletingTaken.count(m.ownDeleting) && !displaced.count(p) &&
                (dit->second.shape == "call" || (dit->second.shape == "stores" && basesInline))) {
                deletingTaken.insert(m.ownDeleting);
                synthetic.push_back({m.ownDeleting, m.name + "::`scalar deleting dtor'"});
            }
            for (auto& [addr, slot] : m.thunks) {
                if (thunkTaken.count(addr)) continue;
                // The compiler makes a thunk for a function whose this is the class itself: one in its primary vtable
                // (merged with a primary slot) or a destructor. Otherwise this is the base subobject and the slot holds
                // the function itself, so the original's thunk cannot come out of this declaration.
                int root = find(m.ids[slot.first][slot.second]);
                bool inPrimary = idents[root].dtor;
                for (int id : m.ids[0]) inPrimary |= id >= 0 && find(id) == root;
                if (!inPrimary) continue;
                thunkTaken.insert(addr);
                const Ident& n = nameOf(m.ids[slot.first][slot.second]);
                std::string adj = "`adjustor{" + std::to_string(slot.first) + "}'";
                synthetic.push_back({addr, n.dtor ? m.name + "::`vector deleting dtor'" + adj
                                                  : m.owner[slot.first][slot.second] + "::" + n.name + adj});
            }
        }

        std::ofstream h(path);
        std::string guard = "OB_CLASSES_" + m.name + "_H";
        for (auto& c : guard) c = char(std::toupper(static_cast<unsigned char>(c)));
        h << "// GENERATED by tools/obcmp/obdecl from the class map; remove this line to keep edits.\n";
        h << "#ifndef " << guard << "\n#define " << guard << "\n\n#include \"common/compiler.h\"\n";
        std::set<std::string> inc(m.includes.begin(), m.includes.end());
        for (auto& i : inc) h << "#include \"" << i << "\"\n";
        h << "\n";
        for (auto& s : synthesized) h << s << "\n";
        for (auto& [v, b] : vtables) h << "// VTABLE: 0x" << hex8(v) << (b.empty() ? "" : " " + b) << "\n";
        if (m.size && !m.assumedSize) h << "// SIZE 0x" << hexn(m.size) << "\n";
        h << "class " << m.name;
        bool first = true;
        for (auto& s : m.subs) {
            h << (first ? " : public " : ", public ")
              << (s.base && !s.intermediate ? models[s.base].name : m.name + "_" + hexn(uint32_t(s.off)));
            first = false;
        }
        h << " {\npublic:\n";
        for (auto& l : lines) h << "    " << l << "\n";
        h << "};\n";
        // The 2003 compiler (32-bit) checks the size; other compilers lay it out for their own pointer size.
        if (m.size && !m.assumedSize)
            h << "#ifdef _MSC_VER\ntypedef char ob_size_" << m.name << "[sizeof(" << m.name << ") == 0x" << hexn(m.size)
              << " ? 1 : -1];\n#endif\n";
        for (auto& [a, n] : synthetic) h << "\n// SYNTHETIC: 0x" << hex8(a) << "\n// " << n << "\n";
        h << "\n#endif\n";
        for (auto& [a, n] : stubList) stubs << "0x" << hex8(a) << " " << n << "\n";
        if (!m.abstract) (m.o1 ? instO1 : instO2).push_back(m.name + "|" + m.header);
        synthCount += synthetic.size();
        vtCount += vtables.size();
        ++written;
    }
    for (auto [group, list] : {std::pair<const char*, std::vector<std::string>*>{"game", &instO2}, {"gzcom", &instO1}}) {
        // one object name per file: the build puts every object in one folder
        std::ofstream f(srcDir + "/" + group + "/GeneratedClasses_" + group + ".cpp");
        f << "// GENERATED by tools/obcmp/obdecl: one construction of every generated class built with this folder's\n"
             "// flags, so the compiler emits their vtables, thunks and deleting destructors here, as the original's\n"
             "// sources did. Not decompiled code; never called.\n";
        for (auto& e : *list) f << "#include \"" << e.substr(e.find('|') + 1) << "\"\n";
        // nothing calls it, so the linker is told to keep it (and with it the vtables, thunks and destructors)
        f << "\n#ifdef _MSC_VER\n#pragma comment(linker, \"/include:?GeneratedClasses_" << group << "@@YAXXZ\")\n#endif\n";
        f << "void GeneratedClasses_" << group << "()\n{\n";
        for (auto& e : *list) f << "    (void)new " << e.substr(0, e.find('|')) << ";\n";
        f << "}\n";
    }
    std::printf("classes written %zu (kept %zu edited), not written %zu; %zu SYNTHETIC, %zu VTABLE annotations\n",
                written, kept, failed, synthCount, vtCount);
    std::vector<std::pair<size_t, std::string>> top;
    for (auto& [k, n] : reasons) top.push_back({n, k});
    std::sort(top.rbegin(), top.rend());
    for (size_t i = 0; i < top.size() && i < 12; ++i) std::printf("  %5zu  %s\n", top[i].first, top[i].second.c_str());
    return 0;
}
