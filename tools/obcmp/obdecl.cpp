// obdecl — writes C++ declarations of the classes obclass recovered, so the 2003 compiler generates what it generated
// for them in the original: their vtables, adjustor thunks and deleting destructors.
//
//   obdecl <classes.tsv> <slots.tsv> <deleting.tsv> <known.tsv> [--purecall ADDR] [--src DIR] [--out DIR]
//          [--report FILE] [--exclude FILE] [--shapes shapes.tsv] [--extents extents.tsv]
//          [--names FILE] [--methods FILE] [--names-before FILE] [--rename-map FILE] [--slot-names FILE] [--slot-names-before FILE]
//
// --slot-names writes "vtable slot name" for every slot of every written class; given back as --slot-names-before
// on the next run, every generated name that moved (its identity's root changed) goes into --rename-map too.
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
//
// With --shapes (tools/obcmp/obshape's reading of the original), the functions of one slot identity tell its
// signature: the bytes every one of them pops are its arguments (dwords, or what a setter stores one as), and the
// one-line ones what it returns. A one-line method (a constant, a getter, a setter, an empty body, return this) is
// then written out, in --src/<folder>/GeneratedMethods_<folder>.cpp with its FUNCTION annotation ("nohook" when the
// original has no room for the hook's 5-byte jump, or for every copy but the first of a body the original's linker
// folded for several methods), and the members it reads or writes are declared as fields
// ("fieldNN" at offset NN) in the class whose own data holds them. Evidence that disagrees (two return types, two
// argument sizes, two kinds of member at one offset, overlapping members) leaves the identity or field as it was.

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
    std::map<uint32_t, int> at;    // vtable -> the slot this identity holds there: one method has ONE slot per vtable
};

// A function a class declares (overrides or introduces), standing for one of the original's.
struct Decl {
    std::string owner;  // the class, or one of its synthesized subobjects or intermediates
    int ident;
    uint32_t function;
    int32_t thisOff = 0;  // where the function's this points in the owner (a slot of a non-primary base)
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
    bool reachedSize = false;  // no SIZE annotation: the size is as far as its functions reach, a lower bound
    uint32_t ownDeleting = 0;
    std::vector<std::string> includes;
};

// obshape's reading of one function.
struct Shape {
    uint32_t room = 0xffffffffu;      // bytes up to the next function
    std::string pops, kind;           // pops: decimal, "?" or "x"
    char returns = '?';               // D, B, F, V or ? (obshape)
    std::vector<std::string> detail;  // after the kind
};

// A member a one-line method reads or writes, declared in the class or subobject whose own data holds it.
struct Field {
    std::string type;  // "char" for a member whose address is taken: a char array up to the next field
    uint32_t size = 0;
    std::string name;  // from src/classes/ext (may end in "[N]"); empty = "field<offset>"
};
struct Region {
    uint32_t start = 0, end = 0;                  // the holder's own data
    std::map<uint32_t, std::set<char>> uses;      // offset -> kinds of access
    std::map<uint32_t, Field> fields;
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

// Names of classes and of the slots they introduce (src/classes/names.tsv, from tools/names/freeze.sh):
//   class <vtable> <name>
//   slot <vtable> <index> <name>
//   method <address> <class> <name> [const]   a non-virtual member function (src/classes/methods.tsv, --methods)
// A class or slot without a line keeps the generated name (cUnk<primary vtable>, SlotNN_<tag>).
struct Names {
    std::map<uint32_t, std::string> classes;
    std::map<std::pair<uint32_t, size_t>, std::string> slots;
    struct Method { std::string cls, name; bool isConst = false; };
    std::map<uint32_t, Method> methods;  // function -> its class and name
};

bool isIdentifier(const std::string& s) {
    static const std::set<std::string> keywords = {"and", "asm", "auto", "bool", "break", "case", "catch", "char",
        "class", "const", "continue", "default", "delete", "do", "double", "else", "enum", "explicit", "export",
        "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace",
        "new", "not", "operator", "or", "private", "protected", "public", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "template", "this", "throw", "true", "try", "typedef", "typeid",
        "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "while", "xor"};
    if (s.empty() || !(std::isalpha(static_cast<unsigned char>(s[0])) || s[0] == '_') || keywords.count(s)) return false;
    for (char c : s)
        if (!(std::isalnum(static_cast<unsigned char>(c)) || c == '_')) return false;
    return s.rfind("__", 0) != 0;
}

Names readNames(const std::string& path) {
    Names n;
    if (path.empty()) return n;
    std::ifstream f(path);
    if (!f) { std::fprintf(stderr, "obdecl: cannot read %s\n", path.c_str()); std::exit(2); }
    std::string line;
    for (int ln = 1; std::getline(f, line); ++ln) {
        std::istringstream ss(line);
        std::string kw, a, b, c;
        if (!(ss >> kw) || kw[0] == '#') continue;
        if (kw == "class" && ss >> a >> b && isIdentifier(b)) n.classes[parseHex(a)] = b;
        else if (kw == "slot" && ss >> a >> b >> c && isIdentifier(c)) n.slots[{parseHex(a), size_t(std::stoul(b))}] = c;
        else if (kw == "method" && ss >> a >> b >> c && isIdentifier(b) && isIdentifier(c)) {
            std::string q;
            n.methods[parseHex(a)] = {b, c, ss >> q && q == "const"};
        }
        else std::fprintf(stderr, "obdecl: %s:%d: not a name line, skipped\n", path.c_str(), ln);
    }
    return n;
}

std::string className(const Names& n, uint32_t primary) {
    auto it = n.classes.find(primary);
    return it == n.classes.end() ? "cUnk" + hex8(primary) : it->second;
}

std::string methodName(const Names& n, uint32_t vtable, size_t index, const std::string& generated) {
    auto it = n.slots.find({vtable, index});
    return it == n.slots.end() ? generated : it->second;
}

int main(int argc, char** argv) {
    std::vector<std::string> pos;
    std::string srcDir = "src", outDir = "src/classes", reportPath, excludePath, shapesPath, extentsPath, only, librariesPath;
    bool inferMajority = false;  // --infer-majority: slot signatures from the majority of their implementations
    std::string namesPath, methodsPath, namesBeforePath, renameMapPath, slotNamesPath, slotNamesBeforePath;
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
        else if (a == "--libraries") librariesPath = value();  // re/map/libraries.tsv: functions of the libraries (hex address first)
        else if (a == "--infer-majority") inferMajority = true;
        else if (a == "--report") reportPath = value();
        else if (a == "--exclude") excludePath = value();
        else if (a == "--shapes") shapesPath = value();
        else if (a == "--extents") extentsPath = value();
        else if (a == "--only") only = value();
        else if (a == "--names") namesPath = value();
        else if (a == "--methods") methodsPath = value();
        else if (a == "--names-before") namesBeforePath = value();
        else if (a == "--rename-map") renameMapPath = value();
        else if (a == "--slot-names") slotNamesPath = value();
        else if (a == "--slot-names-before") slotNamesBeforePath = value();
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
    Names names = readNames(namesPath), before = readNames(namesBeforePath);
    names.methods = readNames(methodsPath).methods;
    std::map<std::string, std::string> renames;  // a name under --names-before → under --names
    std::map<std::pair<uint32_t, int>, std::string> slotBefore;  // --slot-names-before: (vtable, slot) → its last name
    if (!slotNamesBeforePath.empty())
        for (auto& r : readTsv(slotNamesBeforePath))
            if (r.size() >= 3) slotBefore[{parseHex(r[0]), std::stoi(r[1])}] = r[2];
    std::map<uint32_t, Record> recs;
    std::map<uint32_t, uint32_t> vtableClass;  // vtable -> primary of its class
    std::map<uint32_t, uint32_t> ctorClass;    // a function that stores a class's vtables and is no destructor -> its class
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
        if (r[5] != "-")
            for (auto& c : split(r[5], ',')) ctorClass[parseHex(c)] = rec.primary;
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
    // A non-primary base whose vtable this class's copy outgrows is not the base: new virtual functions only go to the
    // end of a class's primary vtable, so the real base there is a class the map never saw on its own (one deriving from
    // a longer interface). Nor is one whose vtable is longer than this class's copy (a class never has fewer slots than
    // its base: the real base derives from a shorter interface). That base is dropped: its vtables become subobjects
    // this class declares slot by slot.
    size_t droppedBases = 0;
    for (auto& [p, rec] : recs) {
        std::vector<std::pair<int32_t, uint32_t>> keep;
        for (auto& [bo, b] : rec.bases) {
            bool outgrown = false;
            if (bo != 0)
                if (auto bit = recs.find(b); bit != recs.end())
                    for (auto& [xk, xv] : bit->second.layout)
                        if (auto own = rec.layout.find(bo + xk); own != rec.layout.end() && slots.count(own->second) &&
                            slots.count(xv) && slots[own->second].size() != slots[xv].size())
                            outgrown = true;
            if (outgrown) ++droppedBases;
            else keep.push_back({bo, b});
        }
        rec.bases.swap(keep);
    }
    std::fprintf(stderr, "obdecl: %zu bases dropped (a vtable outgrown or longer: the real base is a class never seen alone)\n", droppedBases);
    // How far past this each function reaches (obshape --extents): a class of no known size is at least as big as its
    // vtables' functions reach.
    std::map<uint32_t, uint32_t> reach;
    if (!extentsPath.empty())
        for (auto& r : readTsv(extentsPath))
            if (r.size() >= 2) reach[parseHex(r[0])] = parseHex(r[1]);
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
    std::map<uint32_t, Shape> shapes;
    if (!shapesPath.empty())
        for (auto& r : readTsv(shapesPath)) {
            if (r.size() < 5) continue;
            Shape s;
            if (r[1] != "-") s.room = uint32_t(std::stoul(r[1]));
            s.pops = r[2];
            s.returns = r[3][0];
            s.detail = split(r[4], ' ');
            s.kind = s.detail.front();
            s.detail.erase(s.detail.begin());
            shapes[parseHex(r[0])] = s;
        }

    // Hand-declared classes: their VTABLE annotations, header, first base, size and destructor.
    std::map<uint32_t, Hand> hands;  // by primary
    std::map<std::string, std::string> firstBase;  // class -> first base, over every header
    std::set<uint32_t> annotated;                  // functions written by hand (FUNCTION, SYNTHETIC)
    std::set<uint32_t> stubbed;                    // functions a hand source leads to the original (STUB) or drafts (CLOSE)
    std::set<uint32_t> libraries;                  // the libraries' functions (--libraries)
    if (!librariesPath.empty()) {
        std::ifstream lf(librariesPath);
        std::string l;
        while (std::getline(lf, l))
            if (!l.empty() && l[0] != '#') libraries.insert(parseHex(l.substr(0, l.find('\t'))));
    }
    for (auto& entry : fs::recursive_directory_iterator(srcDir)) {
        if (!entry.is_regular_file()) continue;
        std::string ext = entry.path().extension().string();
        if (ext != ".h" && ext != ".cpp") continue;
        std::string rel = fs::relative(entry.path(), srcDir).generic_string();
        if (rel.rfind(fs::relative(outDir, srcDir).generic_string() + "/", 0) == 0) continue;  // our own output
        if (entry.path().filename().string().rfind("GeneratedMethods_", 0) == 0) continue;
        if (entry.path().filename().string().rfind("GeneratedFunctions_", 0) == 0) continue;
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
            if ((at = line.find("// FUNCTION: 0x")) != std::string::npos || (at = line.find("// SYNTHETIC: 0x")) != std::string::npos) {
                annotated.insert(parseHex(line.substr(line.find("0x", at) + 2)));
                continue;
            }
            if ((at = line.find("// STUB: 0x")) != std::string::npos) {
                stubbed.insert(parseHex(line.substr(at + 11)));
                continue;
            }
            if ((at = line.find("// CLOSE: 0x")) != std::string::npos) {  // a draft under way: its function is spoken for
                stubbed.insert(parseHex(line.substr(at + 12)));
                continue;
            }
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
    std::map<uint32_t, std::map<uint32_t, int>> impliedVotes;  // base -> size -> how many derived classes say so
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
            if (subs[i].second) {
                implied[subs[i].second].insert(uint32_t(subs[i + 1].first - subs[i].first));
                impliedVotes[subs[i].second][uint32_t(subs[i + 1].first - subs[i].first)]++;
            }
    }
    // The room a class of known size leaves its LAST base: that base is no bigger. (A base's reach — how far its own
    // methods read past this — is a lower bound for the class owning that vtable, not for an interface that looks
    // like it; where a derived class leaves less room, the room wins.)
    std::map<uint32_t, uint32_t> roomCap;
    for (auto& [p, r] : recs) {
        if (r.virtualBases || r.bases.empty()) continue;
        uint32_t size = r.size;
        if (!size && implied.count(p) && implied[p].size() == 1) size = *implied[p].begin();
        if (!size) continue;
        auto last = std::prev(r.bases.end());
        if (last->first < 0 || uint32_t(last->first) >= size) continue;
        uint32_t room = size - uint32_t(last->first);
        auto it = roomCap.find(last->second);
        if (it == roomCap.end() || room < it->second) roomCap[last->second] = room;
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
    // false = refused: the two identities hold different slots of one vtable, so they are two methods that happen to
    // share one body (the linker folded them); the caller records the body as folded.
    auto unite = [&](int a, int b) -> bool {
        a = find(a);
        b = find(b);
        if (a == b) return true;
        for (auto& [v, s] : idents[b].at)
            if (auto it = idents[a].at.find(v); it != idents[a].at.end() && it->second != s) return false;
        if (idents[a].dtor != idents[b].dtor) { conflicted.insert(a); conflicted.insert(b); }
        if (idents[a].fixed && idents[b].fixed && idents[a].decl != idents[b].decl) conflicted.insert(a);
        if (idents[b].fixed && !idents[a].fixed) std::swap(a, b);  // the fixed one is the root
        idents[b].parent = a;
        for (auto& [v, s] : idents[b].at) idents[a].at[v] = s;
        if (conflicted.count(b)) conflicted.insert(a);
        return true;
    };

    std::set<std::string> usedClassNames;  // hand classes' names, then every generated class's
    for (auto& [p, h] : hands) usedClassNames.insert(h.name);
    std::map<int, std::string> wasNamed;  // a slot identity's name under --names-before
    std::map<uint32_t, Model> models;
    // Sizes written by hand (src/classes/ext/<class>.tsv "size <hex>") for a class the class map has none for: the bytes
    // its operator new asks for where the map did not see the call.
    std::map<std::string, uint32_t> extSizes;
    std::error_code extError;
    for (auto& entry : fs::directory_iterator(outDir + "/ext", extError)) {
        if (entry.path().extension() != ".tsv") continue;
        std::ifstream f(entry.path());
        for (std::string line; std::getline(f, line);) {
            std::istringstream ss(line);
            std::string kw, value;
            if (ss >> kw >> value && kw == "size") extSizes[entry.path().stem().string()] = parseHex(value);
        }
    }
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

        m.name = className(names, primary);
        if (usedClassNames.count(m.name)) m.name = "cUnk" + hex8(primary);  // a name taken by another class
        usedClassNames.insert(m.name);
        {
            std::string was = className(before, primary);
            if (was != m.name) renames[was] = m.name;
        }
        m.header = fs::relative(outDir, srcDir).generic_string() + "/" + m.name + ".h";
        std::string tag = hexn(primary);
        if (r.virtualBases) return fail("virtual bases");
        if (excluded.count(primary)) return fail("excluded");
        if (r.conflict) return fail("layout conflict");
        for (auto& [o, v] : r.layout)
            if (!slots.count(v)) return fail("vtable " + hex8(v) + " has no slots");
        m.size = r.size;
        if (!m.size) if (auto it = extSizes.find(m.name); it != extSizes.end()) m.size = it->second;
        if (!m.size && implied.count(primary) && implied[primary].size() == 1) m.size = *implied[primary].begin();
        if (!m.size && implied.count(primary) && implied[primary].size() > 1) {
            // The derived classes disagree: one of them picked this base wrongly. The size most of them leave wins and
            // the odd derived class fails on its own ("is N bytes, the next subobject is M on"); no majority = no size.
            uint32_t best = 0;
            int votes = 0, total = 0;
            for (auto& [sz, n] : impliedVotes[primary]) {
                total += n;
                if (n > votes) best = sz, votes = n;
            }
            if (votes * 2 > total) m.size = best;
            else return fail("derived classes need different sizes");
        }
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
        // No size from operator new or a derived class: at least as far as the functions in its vtables reach past the
        // subobject they are called on (thunks left out), so the members they use can be placed. Not checked as a size.
        if ((!m.size || m.assumedSize) && m.end) {
            uint32_t far = 0;
            for (auto& [o, v] : r.layout)
                for (auto& s : slots[v])
                    if (s.kind != "thunk" && s.kind != "thunk-vtordisp")
                        if (auto e = reach.find(s.target); e != reach.end()) far = std::max(far, uint32_t(o) + e->second);
            far = (far + 3) & ~3u;
            // never past the room a derived class leaves it (an interface this vtable's class implements is smaller)
            if (implied.count(primary)) far = std::min(far, *implied[primary].begin());
            if (auto c = roomCap.find(primary); c != roomCap.end()) far = std::min(far, c->second);
            if (far > std::max(m.size, m.end)) m.size = far, m.assumedSize = false, m.reachedSize = true;
        }

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
            if (viaThunk || (it->second.second && !folded_.count(fn)))
                if (!unite(it->second.first, id)) folded_.insert(fn);
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
                    std::string nm = isDeleting ? "~" : methodName(names, v, j, b);
                    ids[j] = newIdent(nm, isDeleting);
                    idents[ids[j]].at[v] = int(j);
                    if (!isDeleting) wasNamed[ids[j]] = methodName(before, v, j, b);
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
                    if (s.kind == "thunk") {
                        // a thunk to a SECOND deleting destructor body (the original kept a vector one beside the
                        // scalar one in the primary slot) is not one our build makes: left to do, not annotated
                        // (a class whose primary vtable has no destructor slot — an interface-like primary base —
                        // shows its deleting destructor only behind such thunks: the first thunk's target is it)
                        if (!m.ownDeleting && deleting.count(s.method)) m.ownDeleting = s.method;
                        if (m.ownDeleting && s.method == m.ownDeleting) m.thunks.push_back({s.target, {k, j}});
                    } else if (k == 0) m.ownDeleting = s.target;
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
                            if (!unite(m.ids[0][i], ids[j])) folded_.insert(s.method);
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
                    if (j >= inherited) return fail("own function in a secondary vtable without a thunk");
                    if (!at) {
                        // the vtable of a base's own base: the class overrides that slot itself, and the compiler
                        // passes the function that subobject as this (no thunk)
                        declare(m.name, ids[j], s.target, false);
                        m.decls.back().thisOff = k;
                        own[j] = m.name;
                        continue;
                    }
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

    // Real names can meet where generated ones never did: two identities of one class (with its bases) named alike
    // would overload, or override each other, and change the vtable. The later one gets a number.
    {
        std::set<std::string> taken;
        for (auto& id : idents) taken.insert(id.name);
        for (auto& [p, m] : models) {
            if (!m.ok) continue;
            std::map<std::string, int> first;
            for (auto& [o, ids] : m.ids)
                for (int id : ids) {
                    if (id < 0) continue;
                    int r = find(id);
                    if (idents[r].dtor) continue;
                    auto it = first.find(idents[r].name);
                    if (it == first.end()) { first[idents[r].name] = r; continue; }
                    if (it->second == r) continue;
                    int victim = idents[r].fixed ? it->second : r;
                    if (idents[victim].fixed) continue;
                    std::string base = idents[victim].name, nn;
                    for (int n = 2; taken.count(nn = base + "_" + std::to_string(n)); ++n) {}
                    taken.insert(nn);
                    idents[victim].name = nn;
                    idents[victim].decl = "void " + nn + "()";
                    if (victim == it->second) first[base] = r;
                    first[nn] = victim;
                }
        }
    }
    // Only a generated name is unique enough to replace wherever it is written (SlotNN_<tag>); a real method name
    // that changes (Init → Init_2) is common to many classes: reported, for a hand edit the build will point at.
    auto generated = [](const std::string& s) {
        return s.size() > 7 && s.rfind("Slot", 0) == 0 && std::isdigit(static_cast<unsigned char>(s[4])) &&
               s.find('_') != std::string::npos;
    };
    // The name every (vtable, slot) ends up with: a generated name is its identity's root, which moves whenever the
    // identities merge differently (a base newly declared, a merge refused), so --slot-names keeps this run's and
    // --slot-names-before (the last run's) turns each move into a rename for the hand sources.
    std::map<std::pair<uint32_t, int>, std::string> slotNow;
    for (auto& [p, m] : models) {
        if (!m.ok) continue;
        for (auto& [k, ids] : m.ids) {
            auto lit = m.layout.find(k);
            if (lit == m.layout.end()) continue;
            for (size_t j = 0; j < ids.size(); ++j)
                if (ids[j] >= 0) slotNow[{lit->second, int(j)}] = idents[find(ids[j])].name;
        }
    }
    if (!slotNamesPath.empty()) {
        std::ofstream sn(slotNamesPath);
        for (auto& [vj, name] : slotNow) sn << hex8(vj.first) << "\t" << vj.second << "\t" << name << "\n";
    }
    if (!renameMapPath.empty()) {
        size_t byHand = 0;
        for (auto& [vj, old] : slotBefore) {
            auto it = slotNow.find(vj);
            if (it == slotNow.end() || it->second == old || !generated(old) || renames.count(old)) continue;
            renames[old] = it->second;
        }
        for (auto& [id, was] : wasNamed) {
            const Ident& now = idents[find(id)];
            const std::string& old = find(id) == id ? was : wasNamed.count(find(id)) ? wasNamed[find(id)] : was;
            if (old == now.name) continue;
            if (generated(old)) renames[old] = now.name;
            else ++byHand;
        }
        if (byHand) std::fprintf(stderr, "obdecl: %zu method names changed from real names: not renamed in sources\n", byHand);
        for (auto& [p, m] : models) {
            std::string was = className(before, p);
            if (was == m.name) continue;
            for (auto& [o, sn] : m.synthName) renames[was + "_" + hexn(uint32_t(o))] = m.name + "_" + hexn(uint32_t(o));
            for (auto& [o, v] : m.layout)
                if (o) renames[was + "_" + hexn(uint32_t(o))] = m.name + "_" + hexn(uint32_t(o));
            for (auto& s : m.subs)
                if (s.off) renames[was + "_" + hexn(uint32_t(s.off))] = m.name + "_" + hexn(uint32_t(s.off));
        }
        std::ofstream rm(renameMapPath);
        for (auto& [a, b] : renames) rm << a << "\t" << b << "\n";
        std::fprintf(stderr, "obdecl: %zu renames in %s\n", renames.size(), renameMapPath.c_str());
    }

    // Intermediates the class can do without: a class overriding a method introduced in a non-primary base gets that
    // base subobject as this already (no thunk), so the overrides go into the class itself, unless one of their names
    // is also one the class overrides with another function (one class cannot hold both: then the intermediate stays),
    // or the method is in the primary vtable too (then the compiler takes the class's this and makes a thunk, which
    // the original does not have: the intermediate stays).
    std::map<std::string, std::string> foldedInto, foldedRoot;  // intermediate -> its class; -> its base (vtable name)
    for (auto& [p, m] : models) {
        if (!m.ok || m.hand) continue;
        std::map<std::string, std::map<std::string, uint32_t>> named;  // owner -> name -> function
        for (auto& d : m.decls) named[d.owner][idents[find(d.ident)].name] = d.function;
        std::set<std::string> primaryNames;
        for (int id : m.ids[0])
            if (id >= 0) primaryNames.insert(idents[find(id)].name);
        for (auto& s : m.subs) {
            if (!s.base || !s.intermediate) continue;
            std::string in = m.name + "_" + hexn(uint32_t(s.off));
            bool clash = false;
            for (auto& [n, fn] : named[in]) {
                auto it = named[m.name].find(n);
                clash |= (it != named[m.name].end() && it->second != fn) || primaryNames.count(n);
            }
            if (clash) continue;
            for (auto& d : m.decls)
                if (d.owner == in) { d.owner = m.name; d.thisOff = s.off; }
            for (auto& [n, fn] : named[in]) named[m.name][n] = fn;
            s.intermediate = false;
            foldedInto[in] = m.name;
            foldedRoot[in] = models[s.base].name;
            if (models[s.base].layout.size() == 1) m.root[s.off] = models[s.base].name;
        }
    }
    // the final overriders and vtable names derived classes copied from their bases
    for (auto& [p, m] : models) {
        for (auto& [o, own] : m.owner)
            for (auto& x : own)
                if (foldedInto.count(x)) x = foldedInto[x];
        for (auto& [o, rn] : m.root)
            if (foldedRoot.count(rn)) rn = foldedRoot[rn];
    }

    // Names: every identity takes its root's; a root merged from two different fixed names cannot be declared.
    auto nameOf = [&](int id) -> const Ident& { return idents[find(id)]; };

    // Output.
    fs::create_directories(outDir);
    size_t written = 0, kept = 0, failed = 0, synthCount = 0, vtCount = 0;
    std::map<std::string, size_t> reasons;
    std::ofstream report(reportPath.empty() ? "/dev/null" : reportPath);
    std::vector<std::string> instO1, instO2;
    // --only CLASS writes that one header and nothing else (the lists and generated sources stay as they are).
    std::ofstream stubs;
    if (only.empty()) {
        stubs.open(outDir + "/stubs.txt");
        stubs << "# Generated by tools/obcmp/obdecl: the methods the generated classes declare, each leading to the original's\n"
                 "# function until it is decompiled (tools/gen-stubs.sh). \"0x<address> <decorated>\".\n";
    }
    std::set<uint32_t> deletingTaken;
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
            auto key = std::make_pair(d.owner, idents[root].decl);  // overloads are different methods
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

    // The classes this run writes: usable, and not edited by hand (a header without the GENERATED mark is kept).
    auto keptHeader = [&](const Model& m) {
        std::ifstream in(srcDir + "/" + m.header);
        std::string first;
        return in && std::getline(in, first) && first.find("GENERATED") == std::string::npos;
    };
    std::set<uint32_t> writes;
    for (auto& [p, m] : models)
        if (!m.hand && usable(p) && !keptHeader(m)) writes.insert(p);

    // Signatures (--shapes). V void, D dword, B bool, W word, F float, Q double, P pointer; arguments d, b, w.
    struct Family {
        std::map<std::string, int> pops;  // bytes popped -> how many implementations say so
        std::set<char> ret;
        std::set<char> code;  // what real-code members return (obshape), when no one-line member says
        std::map<size_t, std::set<char>> args;  // what a setter stores the argument as
    };
    struct Sig {
        bool bodies = true;  // every piece of evidence agrees, so one-line bodies can be written
        char ret = 'V';
        std::vector<char> args;
    };
    auto retOf = [](const Shape& s) -> char {
        const std::string t = s.detail.empty() ? "" : s.detail[0];
        if (s.kind == "empty" || s.kind == "set") return 'V';
        if (s.kind == "this") return 'P';
        if (s.kind == "setconst") return s.detail.size() > 3 && s.detail[3] == "b" ? 'B' : 'D';
        if (s.kind == "const") return t == "b" ? 'B' : t == "f" ? 'F' : 'D';
        if (s.kind == "get") return t == "b" ? 'B' : t == "w" ? 'W' : t == "f" ? 'F' : t == "q" ? 'Q' : t == "a" ? 'P' : 'D';
        return 0;
    };
    std::map<int, Family> families;
    for (uint32_t p : writes)
        for (auto& d : models[p].decls) {
            int root = find(d.ident);
            if (idents[root].fixed || idents[root].dtor) continue;
            auto it = shapes.find(d.function);
            if (it == shapes.end()) continue;
            const Shape& s = it->second;
            Family& f = families[root];
            if (s.pops != "?" && s.pops != "x") ++f.pops[s.pops];  // a tail jump or a mis-bounded function says nothing
            if (char r = retOf(s)) f.ret.insert(r);
            else if (s.returns == 'D' || s.returns == 'B' || s.returns == 'F') f.code.insert(s.returns);
            if (s.kind == "set" || s.kind == "setconst") f.args[std::stoul(s.detail[2])].insert(s.detail[0][0]);
        }
    auto retType = [](char c) -> std::pair<std::string, std::string> {  // C++ and decorated
        switch (c) {
        case 'D': return {"uint32_t", "I"};
        case 'B': return {"bool", "_N"};
        case 'W': return {"uint16_t", "G"};
        case 'F': return {"float", "M"};
        case 'Q': return {"double", "N"};
        case 'P': return {"void*", "PAX"};
        }
        return {"void", "X"};
    };
    auto argType = [](char c) -> std::pair<std::string, std::string> {
        if (c == 'b') return {"bool", "_N"};
        if (c == 'w') return {"uint16_t", "G"};
        return {"uint32_t", "I"};
    };
    std::map<int, Sig> sigs;
    size_t popVotes = 0, retMerged = 0, retConflicts = 0;
    for (auto& [root, f] : families) {
        if (f.pops.empty() || (!inferMajority && f.pops.size() != 1)) continue;
        // The bytes popped: what most implementations agree on; a minority that disagrees keeps its one-line bodies
        // unwritten (they would be written for the wrong argument count). Before, any disagreement left the slot as
        // "void Name()", and every caller lost its arguments.
        std::string best;
        int votes = 0, total = 0;
        for (auto& [p, n] : f.pops) {
            total += n;
            if (n > votes || (n == votes && std::stoul(p) > std::stoul(best))) { best = p; votes = n; }
        }
        unsigned long n = std::stoul(best);
        if (n % 4) continue;
        Sig s;
        s.args.assign(n / 4, 'd');
        if (votes != total) { s.bodies = false; ++popVotes; }
        // The return: every piece of evidence, one-line bodies and real code alike. An implementation that returns
        // nothing loses to one that returns something (an empty default beside real overrides); a pointer or a bool
        // beside a dword is a dword (all three come back in eax; an ext file can still narrow a slot per class).
        // Before, two kinds of return left the slot void, and callers could not use its result at all.
        std::set<char> r = f.ret;
        if (inferMajority) {
            r.insert(f.code.begin(), f.code.end());
            if (r.size() > 1 && r.count('V')) { r.erase('V'); ++retMerged; }
            if (r.size() > 1 && r.count('D') && (r.count('P') || r.count('B'))) {
                if (r.count('B')) s.bodies = false;
                r.erase('P'); r.erase('B'); ++retMerged;
            }
        } else {
            if (r == std::set<char>{'D', 'P'}) r = {'D'};  // an integer or a null pointer: both are eax
            if (r.empty() && f.code.size() == 1) r = f.code;
        }
        if (r.size() == 1) s.ret = *r.begin();
        else if (r.size() > 1) { s.bodies = false; ++retConflicts; }
        for (auto& [i, ts] : f.args) {
            if (i >= s.args.size() || ts.size() != 1) { s.bodies = false; continue; }
            s.args[i] = *ts.begin();
        }
        // the declaration and its decoration: arguments of more than one character are back-referenced by index
        Ident& id = idents[root];
        std::string params, mangled;
        std::vector<std::string> seen;
        for (char a : s.args) {
            auto [text, code] = argType(a);
            params += (params.empty() ? "" : ", ") + text;
            if (code.size() > 1) {
                auto at = std::find(seen.begin(), seen.end(), code);
                if (at != seen.end()) { mangled += char('0' + (at - seen.begin())); continue; }
                if (seen.size() < 10) seen.push_back(code);
            }
            mangled += code;
        }
        id.decl = retType(s.ret).first + " " + id.name + "(" + params + ")";
        id.tail = "UAE" + retType(s.ret).second + (s.args.empty() ? "X" : mangled + "@") + "Z";
        sigs[root] = s;
    }
    std::fprintf(stderr, "obdecl: signatures: %zu by majority of pops, %zu with return evidence merged, %zu return conflicts left void\n", popVotes, retMerged, retConflicts);

    // Signatures corrected by hand (src/classes/ext/<class>.tsv): "slot <name> <return type> [<argument type> ...]",
    // for a slot whose evidence is missing or misleading (a function that ends in a jump pops nothing it can show).
    // The whole identity changes, in every class that declares it. Types from a fixed list, so the decoration is known.
    {
        static const std::map<std::string, std::string> code = {
            {"void", "X"}, {"bool", "_N"}, {"uint32_t", "I"}, {"int32_t", "H"}, {"uint16_t", "G"}, {"int16_t", "F"},
            {"uint8_t", "E"}, {"int8_t", "C"}, {"float", "M"}, {"double", "N"}, {"void*", "PAX"},
            {"const void*", "PBX"}, {"char*", "PAD"}, {"const char*", "PBD"}, {"int64_t", "_J"}, {"uint64_t", "_K"}};
        std::map<std::string, int> byName;
        for (size_t i = 0; i < idents.size(); ++i)
            if (find(int(i)) == int(i)) byName[idents[i].name] = int(i);
        std::error_code ec;
        // a slot line names a slot of its own file's class (real names repeat across classes: QueryInterface)
        std::map<std::string, const Model*> byStem;
        for (auto& [p, m] : models) {
            byStem[m.name] = &m;
            byStem.emplace(className(before, p), &m);
        }
        for (auto& e : fs::directory_iterator(outDir + "/ext", ec)) {
            std::ifstream f(e.path());
            std::map<std::string, int> own;
            if (auto st = byStem.find(e.path().stem().string()); st != byStem.end())
                for (auto& [o, ids] : st->second->ids)
                    for (int id : ids)
                        if (id >= 0) own[idents[find(id)].name] = find(id);
            std::string line;
            for (int ln = 1; std::getline(f, line); ++ln) {
                std::istringstream ss(line);
                std::string kw, name, t;
                if (!(ss >> kw) || kw != "slot") continue;
                ss >> name;
                std::vector<std::string> types;
                while (ss >> t) {
                    if (t == "const" && ss >> t) t = "const " + t;  // "const char*"
                    types.push_back(t);
                }
                auto bad = [&](const std::string& why) {
                    std::fprintf(stderr, "obdecl: %s:%d: %s\n", e.path().string().c_str(), ln, why.c_str());
                };
                int target = own.count(name) ? own[name] : byName.count(name) ? byName[name] : -1;
                if (target < 0) { bad("no slot named " + name); continue; }
                if (types.empty()) { bad("slot needs a return type"); continue; }
                bool known = true;
                for (auto& x : types) known &= code.count(x) > 0;
                if (!known) { bad("a type not in the list (void bool uint32_t int32_t uint16_t int16_t uint8_t int8_t int64_t uint64_t float double void* const void* char* const char*)"); continue; }
                Ident& id = idents[size_t(target)];
                std::string params, mangled;
                std::vector<std::string> seen;
                for (size_t i = 1; i < types.size(); ++i) {
                    params += (i > 1 ? ", " : "") + types[i];
                    const std::string& c = code.at(types[i]);
                    if (c.size() > 1) {
                        auto at = std::find(seen.begin(), seen.end(), c);
                        if (at != seen.end()) { mangled += char('0' + (at - seen.begin())); continue; }
                        if (seen.size() < 10) seen.push_back(c);
                    }
                    mangled += c;
                }
                id.decl = types[0] + " " + id.name + "(" + params + ")";
                id.tail = "UAE" + code.at(types[0]) + (types.size() == 1 ? "X" : mangled + "@") + "Z";
                sigs[target].bodies = false;  // its one-line bodies were written for the inferred signature
            }
        }
    }

    // One-line bodies and the fields they use. Where a member at an offset from an owner's this lives: the class or
    // synthesized subobject whose own data holds it (never a vtable pointer, a hand class or space of unknown size).
    std::map<std::string, Region> regions;
    std::function<bool(uint32_t, const std::string&, uint32_t, std::string&, uint32_t&)> place =
        [&](uint32_t p, const std::string& owner, uint32_t off, std::string& holder, uint32_t& rel) -> bool {
        if (!writes.count(p)) return false;
        Model& m = models[p];
        auto hold = [&](const std::string& h, uint32_t o, uint32_t start, uint32_t end) {
            if (o < start || o >= end) return false;
            holder = h, rel = o;
            regions[h].start = start, regions[h].end = end;
            return true;
        };
        if (owner != m.name) {
            for (auto& s : m.subs) {
                if (!s.base && m.synthName[s.off] == owner) return hold(owner, off, 4, s.size);
                if (s.base && s.intermediate && owner == m.name + "_" + hexn(uint32_t(s.off)))
                    return place(s.base, models[s.base].name, off, holder, rel);
            }
            return false;
        }
        for (auto& s : m.subs)
            if (off >= uint32_t(s.off) && off < uint32_t(s.off) + s.size)
                return s.base ? place(s.base, models[s.base].name, off - s.off, holder, rel)
                              : hold(m.synthName[s.off], off - s.off, 4, s.size);
        if (!m.size || !m.end || m.assumedSize) return false;
        return hold(m.name, off, m.end, m.size);
    };
    // How a shape uses a member: D dword, F float, B bool, U unsigned byte, S signed byte, W word, H signed word,
    // A its address; 0 = none, '!' = not written (a double: its alignment would move the class's layout).
    auto useOf = [](const Shape& s) -> char {
        if (s.kind == "get") {
            const std::string& t = s.detail[0];
            if (t == "d" || t == "wz" || t == "ws" || t == "bz" || t == "bs" || t == "b" || t == "w" || t == "f" || t == "a")
                return t == "d" ? 'D' : t == "f" ? 'F' : t == "b" ? 'B' : t == "bz" ? 'U' : t == "bs" ? 'S'
                     : t == "ws" ? 'H' : t == "a" ? 'A' : 'W';
            return '!';
        }
        if (s.kind == "set" || s.kind == "setconst") return s.detail[0] == "d" ? 'D' : s.detail[0] == "b" ? 'B' : 'W';
        return 0;
    };
    auto floatLiteral = [](uint32_t bits, std::string& out) {
        float f;
        std::memcpy(&f, &bits, 4);
        if (!std::isfinite(f)) return false;
        char b[48];
        for (int prec = 1; prec <= 9; ++prec) {  // the shortest that reads back to the same bits
            std::snprintf(b, sizeof b, "%.*g", prec, double(f));
            float back = std::strtof(b, nullptr);
            if (std::memcmp(&back, &f, 4) == 0) break;
        }
        out = b;
        if (out.find_first_of(".e") == std::string::npos) out += ".0";
        out += "f";
        return true;
    };
    // The statement a shape returns with, if the family's return type can hold it.
    auto returnOf = [&](const std::string& t, uint32_t v, char ret, std::string& out) {
        if (t == "b") {
            if (ret != 'B' || v > 1) return false;
            out = v ? "return true;" : "return false;";
            return true;
        }
        if (t == "f") {
            std::string lit;
            if (ret != 'F' || !floatLiteral(v, lit)) return false;
            out = "return " + lit + ";";
            return true;
        }
        if (ret != 'D' && !(ret == 'P' && v == 0)) return false;
        out = std::string("return ") + (v < 10 ? std::to_string(v) : "0x" + hexn(v)) + ";";
        return true;
    };
    struct Body {
        uint32_t fn = 0, cls = 0;
        std::string owner;
        int root = 0;
        const Shape* shape = nullptr;
        std::string holder;  // the field's, if it uses one
        uint32_t off = 0;
        std::string ret;     // the return statement, if any
        bool member = false; // a non-virtual member (names.tsv "method"): its own name and signature, not a slot's
        std::string name;
        Sig sig;
        bool isConst = false;
    };
    std::vector<Body> bodies;
    std::set<std::pair<std::string, int>> bodyTaken;
    std::map<uint32_t, std::string> refused;  // OB_DEBUG_METHODS: why a one-line slot got no body
    for (uint32_t p : writes)
        for (auto& d : models[p].decls) {
            int root = find(d.ident);
            auto sit = sigs.find(root);
            auto shit = shapes.find(d.function);
            if (shit != shapes.end()) refused[d.function] = sit == sigs.end() ? "no signature" : !sit->second.bodies ? "evidence disagrees" : "kind or type";
            if (sit == sigs.end() || !sit->second.bodies || shit == shapes.end()) continue;
            const Sig& sig = sit->second;
            const Shape& s = shit->second;
            Body b;
            b.fn = d.function, b.cls = p, b.owner = d.owner, b.root = root, b.shape = &s;
            if (s.kind == "empty") {
                if (sig.ret != 'V') continue;
            } else if (s.kind == "this") {
                if (sig.ret != 'P') continue;
                b.ret = "return this;";
            } else if (s.kind == "const") {
                if (!returnOf(s.detail[0], parseHex(s.detail[1]), sig.ret, b.ret)) continue;
            } else if (s.kind == "get") {
                char use = useOf(s);
                if (use == '!' || retOf(s) != sig.ret) continue;
            } else if (s.kind == "set") {
                if (sig.ret != 'V') continue;
            } else if (s.kind == "setconst") {
                if (!returnOf(s.detail[3], parseHex(s.detail[4]), sig.ret, b.ret)) continue;
            } else {
                continue;
            }
            refused[d.function] = "identity has a body";
            if (!bodyTaken.insert({d.owner, root}).second) continue;
            refused[d.function] = "field not placed";
            if (char use = useOf(s)) {
                if (!place(p, d.owner, uint32_t(d.thisOff) + parseHex(s.detail[1]), b.holder, b.off)) continue;
                regions[b.holder].uses[b.off].insert(use);
            }
            bodies.push_back(b);
        }
    // Members written by hand beside a generated class (decompiling its code): <out>/ext/<class>.tsv,
    //   field <offset> <type> <name>     a data member at that offset from the class's this (name may end in [N])
    //   size <hex>                       the class's size, where the class map has none
    //   method <address|-> <declaration> a non-virtual member; with an address, STUB-annotated (tools/gen-hooks.sh)
    //                                     (or one with its body inline: "cX() {}", the default constructor beside a declared one)
    // A field named there takes precedence over one the one-line methods imply.
    std::map<uint32_t, std::vector<std::pair<std::string, std::string>>> extMethods;  // class -> address, declaration
    std::map<std::string, std::map<uint32_t, Field>> named;                          // holder -> offset -> field
    // Class types a field may have (src/classes/ext/types.tsv): "type <name> <size> [<header>]", the size as the 2003
    // compiler lays it out; the header that declares it is included where a field of that type is written.
    std::map<std::string, std::pair<uint32_t, std::string>> classTypes;
    {
        std::ifstream f(outDir + "/ext/types.tsv");
        std::string line;
        for (int ln = 1; std::getline(f, line); ++ln) {
            std::istringstream ss(line);
            std::string kw, name, size, header;
            if (!(ss >> kw) || kw[0] == '#') continue;
            if (kw != "type" || !(ss >> name >> size)) {
                std::fprintf(stderr, "obdecl: %s/ext/types.tsv:%d: type <name> <size> [<header>]\n", outDir.c_str(), ln);
                continue;
            }
            ss >> header;
            classTypes[name] = {uint32_t(std::stoul(size, nullptr, 0)), header};
        }
    }
    auto typeSize = [&](std::string t) -> uint32_t {
        while (!t.empty() && t.back() == ' ') t.pop_back();
        if (!t.empty() && t.back() == '*') return 4;  // the 2003 compiler's layout; other compilers lay out their own
        if (auto c = classTypes.find(t); c != classTypes.end()) return c->second.first;
        static const std::map<std::string, uint32_t> sizes = {
            {"bool", 1}, {"char", 1}, {"int8_t", 1}, {"uint8_t", 1}, {"signed char", 1}, {"unsigned char", 1},
            {"int16_t", 2}, {"uint16_t", 2}, {"short", 2}, {"unsigned short", 2}, {"int", 4}, {"unsigned int", 4},
            {"int32_t", 4}, {"uint32_t", 4}, {"long", 4}, {"unsigned long", 4}, {"float", 4}, {"double", 8},
            {"int64_t", 8}, {"uint64_t", 8}};
        auto it = sizes.find(t);
        return it == sizes.end() ? 0 : it->second;
    };
    for (uint32_t p : writes) {
        std::string extPath = outDir + "/ext/" + models[p].name + ".tsv";
        if (!fs::exists(extPath)) extPath = outDir + "/ext/" + className(before, p) + ".tsv";  // not renamed yet
        std::ifstream f(extPath);
        std::string line;
        for (int ln = 1; std::getline(f, line); ++ln) {
            std::istringstream ss(line);
            std::string kw;
            if (!(ss >> kw) || kw[0] == '#') continue;
            auto bad = [&](const std::string& why) {
                std::fprintf(stderr, "obdecl: %s/ext/%s.tsv:%d: %s\n", outDir.c_str(), models[p].name.c_str(), ln, why.c_str());
            };
            if (kw == "method") {
                std::string a, decl;
                ss >> a;
                std::getline(ss, decl);
                decl = decl.substr(std::min(decl.size(), decl.find_first_not_of(" \t")));
                if (decl.empty()) { bad("method without a declaration"); continue; }
                if (decl.back() == ';') decl.pop_back();
                extMethods[p].push_back({a, decl});
                continue;
            }
            if (kw == "slot") continue;  // read with the signatures above
            if (kw == "size") continue;  // read with the class map
            if (kw != "field") { bad("unknown line"); continue; }
            std::string off, rest;
            ss >> off;
            std::getline(ss, rest);
            size_t sp = rest.find_last_of(" \t");
            if (sp == std::string::npos) { bad("field needs an offset, a type and a name"); continue; }
            Field fd;
            fd.name = rest.substr(sp + 1);
            fd.type = rest.substr(rest.find_first_not_of(" \t"), sp - rest.find_first_not_of(" \t"));
            uint32_t count = 1;
            if (size_t lb = fd.name.find('['); lb != std::string::npos) count = uint32_t(std::stoul(fd.name.substr(lb + 1), nullptr, 0));
            fd.size = typeSize(fd.type) * count;
            if (!fd.size) { bad("unknown type " + fd.type + " (a pointer, a fixed-size or built-in type, or one in ext/types.tsv)"); continue; }
            std::string holder;
            uint32_t rel = 0;
            if (!place(p, models[p].name, parseHex(off), holder, rel) || rel + fd.size > regions[holder].end) {
                bad("offset " + off + " is not in this class's own data, or its subobjects'");
                continue;
            }
            named[holder][rel] = fd;
        }
    }

    // Non-virtual members named by the reference build (names.tsv "method"): a one-line body that is no slot's, written
    // nowhere by hand and no library's is declared in its class, with the signature its own code shows (the bytes it
    // pops are dword arguments, a setter's the size it stores), unless the name is taken in the class or its bases.
    std::set<uint32_t> slotFns;
    for (auto& [p, m] : models)
        for (auto& d : m.decls) slotFns.insert(d.function);
    {
        std::map<std::string, uint32_t> byName;
        for (uint32_t p : writes) byName[models[p].name] = p;
        std::map<uint32_t, std::set<std::string>> taken;  // class -> names declared in it or its bases
        std::function<void(uint32_t, std::set<std::string>&)> namesIn = [&](uint32_t c, std::set<std::string>& out) {
            for (auto& [o, ids] : models[c].ids)
                for (int id : ids)
                    if (id >= 0) out.insert(nameOf(id).name);
            for (auto& s : models[c].subs)
                if (s.base && models.count(s.base)) namesIn(s.base, out);
        };
        std::map<std::pair<uint32_t, std::string>, int> uses;  // two functions of one name: overloads, written by neither
        for (auto& [fn, mt] : names.methods)
            if (byName.count(mt.cls)) ++uses[{byName[mt.cls], mt.name}];
        const bool trace = std::getenv("OB_DEBUG_METHODS") != nullptr;
        for (auto& [fn, mt] : names.methods) {
            auto pit = byName.find(mt.cls);
            auto shit = shapes.find(fn);
            if (trace && pit != byName.end() && shit != shapes.end() && shit->second.kind != "-")
                std::fprintf(stderr, "method %s %s::%s %s%s%s%s\n", hex8(fn).c_str(), mt.cls.c_str(), mt.name.c_str(), shit->second.kind.c_str(),
                             slotFns.count(fn) ? " slot" : "", annotated.count(fn) || stubbed.count(fn) ? " annotated" : "",
                             libraries.count(fn) ? " library" : "");
            if (pit == byName.end() || shit == shapes.end()) continue;
            if (slotFns.count(fn) || annotated.count(fn) || stubbed.count(fn) || libraries.count(fn)) continue;
            uint32_t p = pit->second;
            if (uses[{p, mt.name}] != 1) continue;
            if (!taken.count(p)) {
                namesIn(p, taken[p]);
                for (auto& [a, decl] : extMethods[p]) taken[p].insert(decl.substr(0, decl.find('(')).substr(decl.substr(0, decl.find('(')).find_last_of(" *&") + 1));
            }
            if (taken[p].count(mt.name) || mt.name == models[p].name) continue;
            const Shape& s = shit->second;
            if (s.pops.empty() || !std::all_of(s.pops.begin(), s.pops.end(), ::isdigit) || std::stoi(s.pops) % 4) continue;
            Body b;
            b.fn = fn, b.cls = p, b.owner = models[p].name, b.root = -1, b.shape = &s;
            b.member = true, b.name = mt.name, b.isConst = mt.isConst;
            b.sig.ret = retOf(s);
            b.sig.args.assign(size_t(std::stoi(s.pops) / 4), 'd');
            if (s.kind == "empty" || s.kind == "get") {
                if (s.kind == "get" && useOf(s) == '!') continue;
            } else if (s.kind == "this") {
                b.ret = "return this;";
            } else if (s.kind == "const") {
                if (!returnOf(s.detail[0], parseHex(s.detail[1]), b.sig.ret, b.ret)) continue;
            } else if (s.kind == "set" || s.kind == "setconst") {
                size_t at = std::stoul(s.detail[2]);
                if (at >= b.sig.args.size()) continue;
                b.sig.args[at] = s.detail[0][0];
                if (s.kind == "setconst" && !returnOf(s.detail[3], parseHex(s.detail[4]), b.sig.ret, b.ret)) continue;
            } else {
                continue;
            }
            if (char use = useOf(s)) {
                if (!place(p, b.owner, parseHex(s.detail[1]), b.holder, b.off)) continue;
                regions[b.holder].uses[b.off].insert(use);
            }
            bodies.push_back(b);
        }
    }
    // Fields: one kind of access per offset (a byte read as bool and as unsigned is bool), naturally aligned, inside the
    // holder's own data and overlapping nothing; an address-taken member runs up to the next field.
    for (auto& [h, r] : regions) {
        std::vector<std::pair<uint32_t, Field>> list;
        auto takenByName = [&](uint32_t off, uint32_t size) {
            for (auto& [o, f] : named[h])
                if (off < o + f.size && o < off + size) return true;
            return false;
        };
        for (auto& [off, f] : named[h]) list.push_back({off, f});
        for (auto& [off, ks] : r.uses) {
            if (named[h].count(off)) continue;
            bool bytes = ks.count('B') || ks.count('U') || ks.count('S'), words = ks.count('W') || ks.count('H');
            if (int(bytes) + int(words) + int(ks.count('D')) + int(ks.count('F')) + int(ks.count('A')) != 1) continue;
            Field f;
            if (bytes) {
                if (ks.count('S') && ks.size() > 1) continue;
                f = {ks.count('S') ? "int8_t" : ks.count('B') ? "bool" : "uint8_t", 1, ""};
            } else if (words) {
                f = {ks.count('H') ? "int16_t" : "uint16_t", 2, ""};
            } else if (ks.count('D')) {
                f = {"uint32_t", 4, ""};
            } else if (ks.count('F')) {
                f = {"float", 4, ""};
            } else {
                f = {"char", 1, ""};
            }
            if (off % f.size || off + f.size > r.end || takenByName(off, f.size)) continue;
            list.push_back({off, f});
        }
        std::sort(list.begin(), list.end(), [](const auto& a, const auto& b) { return a.first < b.first; });
        std::vector<bool> drop(list.size());
        for (size_t i = 0; i < list.size(); ++i) {
            uint32_t next = i + 1 < list.size() ? list[i + 1].first : r.end;
            if (list[i].second.type == "char" && list[i].second.name.empty()) list[i].second.size = next - list[i].first;
            else if (list[i].first + list[i].second.size > next) drop[i] = drop[i + 1] = true;
        }
        for (size_t i = 0; i < list.size(); ++i)
            if (!drop[i]) r.fields[list[i].first] = list[i].second;
    }
    std::set<std::pair<std::string, int>> bodied;  // owner, identity: defined, so no stub
    {
        std::vector<Body> keep;
        for (auto& b : bodies) {
            refused[b.fn] = "field conflict";
            if (!b.holder.empty() && !regions[b.holder].fields.count(b.off)) continue;
            refused[b.fn] = "field type";
            // a field named by hand as a pointer: the generated getter or setter of an integer would need a cast,
            // so the method stays the original's (a stub) until its signature says pointer
            if (!b.holder.empty()) {
                const Field& fd = regions[b.holder].fields[b.off];
                bool pointer = !fd.type.empty() && fd.type.back() == '*' && fd.name.find('[') == std::string::npos;
                bool address = b.shape->kind == "get" && b.shape->detail[0] == "a";
                if (pointer && !address && (b.shape->kind != "get" || (b.member ? b.sig : sigs[b.root]).ret != 'P')) continue;
                // a float field moved as a dword (its bits through eax): a body would convert int <-> float
                if (fd.type == "float" && fd.name.find('[') == std::string::npos && !address && b.shape->detail[0] != "f")
                    continue;
            }
            refused.erase(b.fn);
            keep.push_back(b);
            if (!b.member) bodied.insert({b.owner, b.root});
        }
        bodies.swap(keep);
        if (std::getenv("OB_DEBUG_METHODS"))
            for (auto& [fn, why] : refused) std::fprintf(stderr, "refused %s %s\n", hex8(fn).c_str(), why.c_str());
    }
    std::set<std::string> fieldIncludes;  // the headers the class-typed fields of the header being written need
    // The members of a holder's own data from start to end: its fields, and padding between them.
    auto regionLines = [&](const std::string& holder, uint32_t start, uint32_t end) {
        std::vector<std::string> out;
        uint32_t at = start;
        auto it = regions.find(holder);
        if (it != regions.end())
            for (auto& [off, f] : it->second.fields) {
                if (off > at) out.push_back("char unknown" + hexn(at) + "[0x" + hexn(off - at) + "];");
                if (auto c = classTypes.find(f.type); c != classTypes.end() && !c->second.second.empty())
                    fieldIncludes.insert(c->second.second);
                if (!f.name.empty()) out.push_back(f.type + " " + f.name + ";");
                else out.push_back(f.type == "char" ? "char field" + hexn(off) + "[0x" + hexn(f.size) + "];"
                                                    : f.type + " field" + hexn(off) + ";");
                at = off + f.size;
            }
        if (end > at) out.push_back("char unknown" + hexn(at) + "[0x" + hexn(end - at) + "];");
        return out;
    };

    // Factories (obshape "factory"): `return new C;` whose constructor the original kept out of line. C declares that
    // constructor (a STUB until it is decompiled) and, so its vtable is still emitted here, a constructor nothing calls
    // (`explicit C(ob_emit) {}`, what GeneratedClasses constructs); the factory itself is written below. Only for a
    // generated class whose size is the factory's (operator new's argument), through the global operator new, and
    // whose constructors nobody declared by hand.
    const uint32_t globalNew = 0x5e55e0;
    std::map<uint32_t, uint32_t> factoryCtor;                   // class -> its default constructor
    std::vector<std::pair<uint32_t, uint32_t>> factoryFns;      // factory -> class
    std::map<uint32_t, std::string> factoryOpt;                 // factory -> O1 / O2
    {
        std::map<uint32_t, std::set<uint32_t>> ctorsSeen;
        for (auto& [fn, s] : shapes) {
            if (s.kind != "factory" || s.detail.size() < 4 || parseHex(s.detail[3]) != globalNew) continue;
            if (annotated.count(fn) || stubbed.count(fn) || libraries.count(fn)) continue;
            uint32_t ctor = parseHex(s.detail[2]);
            auto c = ctorClass.find(ctor);
            if (c == ctorClass.end() || !models.count(c->second)) continue;
            const Model& m = models[c->second];
            if (!m.ok || m.hand || m.abstract || m.assumedSize || m.reachedSize || m.size != parseHex(s.detail[0])) continue;
            if (annotated.count(ctor)) continue;
            bool declared = false;  // a constructor written in the ext file: the class is the hand's
            for (auto& [a, decl] : extMethods[c->second]) declared |= decl.rfind(m.name + "(", 0) == 0;
            if (declared) continue;
            ctorsSeen[c->second].insert(ctor);
            factoryFns.push_back({fn, c->second});
            factoryOpt[fn] = s.detail[1];
        }
        for (auto& [cls, set] : ctorsSeen)
            if (set.size() == 1) factoryCtor[cls] = *set.begin();
        std::vector<std::pair<uint32_t, uint32_t>> keep;
        for (auto& f : factoryFns)
            if (factoryCtor.count(f.second)) keep.push_back(f);
        factoryFns.swap(keep);
    }

    for (auto& [p, m] : models) {
        if (m.hand || (!only.empty() && m.name != only)) continue;
        fieldIncludes.clear();
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
            if (!seenName[owner].insert(n.decl).second) return;
            body[owner].push_back("virtual " + n.decl + (pure ? " = 0;" : ";"));
            // operator= is ??4Class@@..., every other method ?Name@Class@@...
            std::string head = n.name == "operator=" ? "??4" : "?" + n.name + "@";
            if (!pure && !bodied.count({owner, find(id)}))
                stubList.push_back({fn, head + owner + "@@" + (n.tail.empty() ? "UAEXXZ" : n.tail)});
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
                } else if (seenName[sn].insert(nameOf(id).decl).second) {
                    d << "    virtual " << nameOf(id).decl << " = 0;\n";
                }
            }
            for (auto& line : regionLines(sn, 4, s.size)) d << "    " << line << "\n";
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
                else if (seenName[m.name].insert(n.decl).second) body[m.name].push_back("virtual " + n.decl + " = 0;");
                if (!body[m.name].empty()) { lines.push_back(body[m.name].back()); body[m.name].pop_back(); }
            }
        }
        if (m.hasDtor && !dtorWritten) lines.insert(lines.begin(), dtorDecl);
        for (auto& [key, fn] : fnOf)
            if (key.first == m.name) emit(m.name, key.second, fn, false);
        for (int id : m.pureAgain)
            if (seenName[m.name].insert(nameOf(id).decl).second) body[m.name].push_back("virtual " + nameOf(id).decl + " = 0;");
        for (auto& line : body[m.name]) lines.push_back(line);
        if (auto c = factoryCtor.find(p); c != factoryCtor.end()) {
            lines.push_back("// STUB: 0x" + hex8(c->second));
            lines.push_back(m.name + "();");
            lines.push_back("explicit " + m.name + "(ob_emit) {}  // never called: emits the vtable (GeneratedClasses)");
        }
        for (auto& [a, decl] : extMethods[p]) {
            if (a != "-") lines.push_back("// STUB: 0x" + hex8(parseHex(a)));
            lines.push_back(decl.back() == '}' ? decl : decl + ";");  // a body written inline (an empty constructor) takes no ';'
        }
        for (auto& b : bodies) {
            if (!b.member || b.cls != p) continue;
            std::string params;
            for (size_t i = 0; i < b.sig.args.size(); ++i) params += (i ? ", " : "") + argType(b.sig.args[i]).first;
            lines.push_back(retType(b.sig.ret).first + " " + b.name + "(" + params + ")" + (b.isConst ? " const" : "") + ";");
        }
        // a base's virtual operator= stays visible beside the implicit copy assignment (no code changes)
        for (auto& s : m.subs) {
            if (!s.base) continue;
            bool has = false;
            for (auto& [o, ids] : models[s.base].ids)
                for (int id : ids) has |= id >= 0 && nameOf(id).name == "operator=";
            if (has) lines.push_back("using " + (s.intermediate ? m.name + "_" + hexn(uint32_t(s.off)) : models[s.base].name) + "::operator=;");
        }
        if (m.size > m.end && m.end)
            for (auto& line : regionLines(m.name, m.end, m.size)) lines.push_back(line);
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
                // The compiler makes a thunk for a function whose this is the class itself: one in its primary vtable
                // (merged with a primary slot) or a destructor. Otherwise this is the base subobject and the slot holds
                // the function itself, so the original's thunk cannot come out of this declaration.
                int root = find(m.ids[slot.first][slot.second]);
                bool inPrimary = idents[root].dtor;
                for (int id : m.ids[0]) inPrimary |= id >= 0 && find(id) == root;
                if (!inPrimary) continue;
                // A thunk the original's linker folded with other classes' (/OPT:ICF) is annotated in each of them:
                // obcmp names every copy after the first pair of that address.
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
        h << "#ifndef " << guard << "\n#define " << guard << "\n\n#include \"common/compiler.h\"\n#include \"common/types.h\"\n";
        std::set<std::string> inc(m.includes.begin(), m.includes.end());
        inc.insert(fieldIncludes.begin(), fieldIncludes.end());
        fieldIncludes.clear();
        for (auto& i : inc) h << "#include \"" << i << "\"\n";
        h << "\n";
        for (auto& s : synthesized) h << s << "\n";
        for (auto& [v, b] : vtables) h << "// VTABLE: 0x" << hex8(v) << (b.empty() ? "" : " " + b) << "\n";
        if (m.size && !m.assumedSize && !m.reachedSize) h << "// SIZE 0x" << hexn(m.size) << "\n";
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
        if (m.size && !m.assumedSize && !m.reachedSize)
            h << "#ifdef _MSC_VER\ntypedef char ob_size_" << m.name << "[sizeof(" << m.name << ") == 0x" << hexn(m.size)
              << " ? 1 : -1];\n#endif\n";
        for (auto& [a, n] : synthetic) h << "\n// SYNTHETIC: 0x" << hex8(a) << "\n// " << n << "\n";
        h << "\n#endif\n";
        for (auto& [a, n] : stubList) stubs << "0x" << hex8(a) << " " << n << "\n";
        if (!m.abstract) (m.o1 ? instO1 : instO2).push_back(m.name + (factoryCtor.count(p) ? "(ob_emit())" : "") + "|" + m.header);
        synthCount += synthetic.size();
        vtCount += vtables.size();
        ++written;
    }
    for (auto [group, list] : {std::pair<const char*, std::vector<std::string>*>{"game", &instO2}, {"gzcom", &instO1}}) {
        if (!only.empty()) break;
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
    // The one-line methods, in the folder whose flags wrote them: a constant the flags spell differently says which,
    // otherwise the class's.
    size_t methodCount = 0, fieldCount = 0;
    for (auto& [h, r] : regions) fieldCount += r.fields.size();
    std::sort(bodies.begin(), bodies.end(), [](const Body& a, const Body& b) { return a.fn < b.fn; });
    std::set<uint32_t> fnTaken;
    for (const char* group : {"game", "gzcom"}) {
        if (!only.empty()) break;
        std::vector<const Body*> list;
        std::set<std::string> includes;
        for (auto& b : bodies) {
            const std::string opt = b.shape->kind == "const" && b.shape->detail.size() > 2 ? b.shape->detail[2] : "-";
            bool o1 = opt == "O1" || (opt == "-" && models[b.cls].o1);
            if (o1 != (std::string(group) == "gzcom")) continue;
            list.push_back(&b);
            includes.insert(models[b.cls].header);
        }
        std::ofstream f(srcDir + "/" + group + "/GeneratedMethods_" + group + ".cpp");
        f << "// GENERATED by tools/obcmp/obdecl: the one-line methods of the generated classes (constants, getters, setters,\n"
             "// empty bodies), written from what the original's code does (tools/obcmp/obshape) in the spelling the 2003\n"
             "// compiler turns back into the same instructions.\n";
        for (auto& i : includes) f << "#include \"" << i << "\"\n";
        for (const Body* b : list) {
            const Sig& sig = b->member ? b->sig : sigs[b->root];
            const std::string& name = b->member ? b->name : idents[b->root].name;
            const Shape& s = *b->shape;
            int value = s.kind == "set" || s.kind == "setconst" ? std::stoi(s.detail[2]) : -1;
            std::string params, field;
            if (!b->holder.empty()) {
                const Field& fd = regions[b->holder].fields[b->off];
                std::string base = fd.name.substr(0, fd.name.find('['));
                bool array = fd.name.find('[') != std::string::npos;
                bool address = s.kind == "get" && s.detail[0] == "a";
                if (fd.name.empty()) field = "field" + hexn(b->off);  // a char array when its address is taken
                else if (address) field = array ? base : "&" + base;
                else field = array ? base + "[0]" : base;
            }
            for (size_t i = 0; i < sig.args.size(); ++i)
                params += (i ? ", " : "") + argType(sig.args[i]).first + (int(i) == value ? " value" : "");
            f << "\n";
            // A body the original's linker folded for several methods is one function there and one per method here:
            // each is annotated (and scored), the first hooked, when the original has room for the jump.
            bool hook = !annotated.count(b->fn) && fnTaken.insert(b->fn).second && b->shape->room >= 5;
            f << "// FUNCTION: 0x" << hex8(b->fn) << (hook ? "" : " nohook") << "\n";
            f << retType(sig.ret).first << " " << b->owner << "::" << name << "(" << params << ")" << (b->isConst ? " const" : "") << "\n{\n";
            if (value >= 0) f << "    " << field << " = value;\n";
            if (s.kind == "get") f << "    return " << field << ";\n";
            if (!b->ret.empty()) f << "    " << b->ret << "\n";
            f << "}\n";
            ++methodCount;
        }
    }
    // Free constant functions: every function of the original whose whole body returns one constant (tools/obcmp/obshape
    // "const") and that is no class's slot, is written nowhere by hand (FUNCTION, SYNTHETIC or STUB) and is not a
    // library's or the other compiler's. A free function named by its address, in the folder whose flags spell the
    // constant; its real name and class, when they are learned, move it into its class.
    size_t freeCount = 0;
    if (only.empty()) {
        std::map<std::string, std::vector<std::string>> freeBodies;  // folder -> definitions
        for (auto& [fn, s] : shapes) {
            if (s.kind != "const" || s.detail.size() < 2) continue;
            if (slotFns.count(fn) || annotated.count(fn) || stubbed.count(fn) || fnTaken.count(fn)) continue;
            if (libraries.count(fn) || (fn >= 0xa053a0 && fn < 0xa640c0)) continue;  // the image library (another compiler)
            const std::string& t = s.detail[0];
            char ret = t == "b" ? 'B' : t == "f" ? 'F' : 'D';
            std::string stmt;
            if (!returnOf(t, parseHex(s.detail[1]), ret, stmt)) continue;
            // A body that pops its arguments (ret N) is a callee-pops function of N/4 dwords; its convention and arguments
            // are unknown beyond that, and stdcall spells the same instructions.
            if (s.pops.empty() || !std::all_of(s.pops.begin(), s.pops.end(), ::isdigit)) continue;
            int popped = std::stoi(s.pops);
            if (popped % 4) continue;
            std::string params;
            for (int i = 0; i < popped / 4; ++i) params += (i ? ", " : "") + std::string("uint32_t");
            const std::string opt = s.detail.size() > 2 ? s.detail[2] : "-";
            std::string def = "// FUNCTION: 0x" + hex8(fn) + (s.room >= 5 ? "" : " nohook") + "\n" + retType(ret).first +
                              (popped ? " OB_STDCALL" : "") + " Fn" + hex8(fn) + "(" + params + ")\n{\n    " + stmt + "\n}\n";
            freeBodies[opt == "O1" ? "gzcom" : "game"].push_back(def);
            ++freeCount;
        }
        // the factories, in the folder whose flags clean the stack as theirs do
        std::map<std::string, std::set<std::string>> freeIncludes;
        size_t factoryCount = 0;
        for (auto& [fn, cls] : factoryFns) {
            const Model& m = models[cls];
            if (!usable(cls)) continue;
            std::string group = factoryOpt[fn] == "O1" ? "gzcom" : "game";
            freeIncludes[group].insert(m.header);
            freeBodies[group].push_back("// FUNCTION: 0x" + hex8(fn) + (shapes[fn].room >= 5 ? "" : " nohook") + "\n" + m.name +
                                        "* Fn" + hex8(fn) + "()\n{\n    return new " + m.name + ";\n}\n");
            ++factoryCount;
        }
        std::printf("%zu factories (%zu classes declare their constructor)\n", factoryCount, factoryCtor.size());
        for (const char* group : {"game", "gzcom"}) {
            std::ofstream f(srcDir + "/" + group + "/GeneratedFunctions_" + group + ".cpp");
            f << "// GENERATED by tools/obcmp/obdecl: the functions of the original whose whole body returns one constant\n"
                 "// or a new object (a factory) and that belong to no declared class (tools/obcmp/obshape), named by address until\n"
                 "// their class or name is known.\n"
                 "#include \"common/compiler.h\"\n"
                 "#include \"common/types.h\"\n";
            for (auto& h : freeIncludes[group]) f << "#include \"" << h << "\"\n";
            for (auto& d : freeBodies[group]) f << "\n" << d;
        }
    }
    std::printf("classes written %zu (kept %zu edited), not written %zu; %zu SYNTHETIC, %zu VTABLE annotations; "
                "%zu signatures, %zu one-line methods, %zu fields, %zu free constant functions\n",
                written, kept, failed, synthCount, vtCount, sigs.size(), methodCount, fieldCount, freeCount);
    std::vector<std::pair<size_t, std::string>> top;
    for (auto& [k, n] : reasons) top.push_back({n, k});
    std::sort(top.rbegin(), top.rend());
    for (size_t i = 0; i < top.size() && i < 12; ++i) std::printf("  %5zu  %s\n", top[i].first, top[i].second.c_str());
    return 0;
}
