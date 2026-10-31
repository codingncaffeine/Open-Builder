// obsig — finds the functions of a library, built with the original's compiler, inside the original program.
//
//   obsig <original.exe> <original-functions.tsv> <library.dll> <library-functions.tsv> <library.map>
//         [--out matches.tsv] [--min N] [--list] [--diff NAME] [--twins] [--no-position]
//
// The function lists are tools/ghidra/ExportFunctions.java output ("entry size name source", hex). The map names the
// library's public functions; the others (statics) are named after the public function before them.
//
// Every function on both sides is tokenised (pe.h). A token string found exactly once among the unmatched functions
// of each side is a match. Matched pairs then share a name, so calls to them tokenise the same on both sides and
// tell apart more of the rest; this repeats until a round finds nothing new. With --twins, library functions identical
// to each other (one template over types of one shape: map<int, void*> and map<int, int>) count as one: the first by
// name stands for them all. --no-position leaves out the pairs by position (a catalogue has no layout to follow). Functions under --min instructions
// (default 3) are never matched on their own: too many of them look alike by chance.
//
// Pairs are rescored at the end with every name known: identical, or "near" with a score (a position pair
// can differ). A function no pair refers to is "absent" (most likely never linked into the original) rather
// than missing. --list names every near, missing and absent function; --diff prints one side by side.
//
// matches.tsv is in obcmp's pairs format ("orig_va orig_size lib_va lib_size name"), so obcmp can rescore it.

#include "pe.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

using namespace ob;

struct Function {
    uint32_t va;
    uint32_t size;
    std::string name;
    std::string object;  // library side: the .obj it came from (from the map)
    int match = -1;      // index on the other side
    bool byPosition = false;
    bool twin = false;   // library side, --twins: identical to a matched function that stands for it
    bool hasTwins = false;  // library side: stands for twins (its name says what the code is, not which copy)
};

bool readFunctions(const std::string& path, std::vector<Function>& out) {
    std::ifstream f(path);
    if (!f) return false;
    std::string line;
    while (std::getline(f, line)) {
        std::istringstream ss(line);
        std::string va, size, name;
        if (!(ss >> va >> size >> name)) continue;
        out.push_back({uint32_t(std::stoul(va, nullptr, 16)), uint32_t(std::stoul(size, nullptr, 16)), name, ""});
    }
    std::sort(out.begin(), out.end(), [](const Function& a, const Function& b) { return a.va < b.va; });
    return true;
}

// Names and objects from an MSVC /MAP: " 0001:00000090  _luaA_pushobject  10001090 f  lapi.obj".
void applyMap(const std::string& path, std::vector<Function>& fns) {
    std::map<uint32_t, std::pair<std::string, std::string>> publics;
    std::ifstream f(path);
    std::string line;
    while (std::getline(f, line)) {
        std::istringstream ss(line);
        std::string addr, name, va, kind, object;
        if (!(ss >> addr >> name >> va >> kind)) continue;
        if (kind != "f" || addr.rfind("0001:", 0) != 0) continue;
        ss >> object;
        if (object == "i") ss >> object;  // "f i" marks an inline function's out-of-line copy
        publics[uint32_t(std::stoul(va, nullptr, 16))] = {name, object};
    }
    for (Function& fn : fns) {
        auto it = publics.upper_bound(fn.va);
        if (it == publics.begin()) continue;
        --it;
        fn.object = it->second.second;
        fn.name = it->first == fn.va ? it->second.first : it->second.first + "+static_" + hex(fn.va - it->first);
    }
}

// A function's tokens, padding trimmed, as one string.
std::string signature(const Image& img, const std::map<uint32_t, std::string>& names, const Function& fn,
                      size_t& count) {
    auto tokens = tokenize({&img, &names}, fn.va, fn.size);
    trimPadding(tokens);
    count = tokens.size();
    std::string s;
    for (const auto& t : tokens) s += t, s += '\n';
    return s;
}

// What identical pairs refer to, side by side: in two identical functions the k-th outside address each refers to
// is the same thing on both sides. Where that is data (a registration table, a vtable), the two tables are walked in
// step and the pointers at equal offsets pair up too, until their layouts part or two zero words end the table.
std::vector<std::pair<uint32_t, uint32_t>> pairedReferences(const Image& orig, const Image& lib,
                                                            const std::vector<Function>& a,
                                                            const std::vector<Function>& b,
                                                            const std::map<uint32_t, std::string>& namesA,
                                                            const std::map<uint32_t, std::string>& namesB,
                                                            const std::set<uint32_t>& codeB) {
    std::vector<std::pair<uint32_t, uint32_t>> out;
    std::set<std::pair<uint32_t, uint32_t>> tables;
    for (const Function& y : b) {
        if (y.match < 0) continue;
        const Function& x = a[y.match];
        std::vector<uint32_t> refsA, refsB;
        auto tx = tokenize({&orig, &namesA}, x.va, x.size, &refsA);
        auto ty = tokenize({&lib, &namesB}, y.va, y.size, &refsB);
        if (tx != ty || refsA.size() != refsB.size()) continue;
        for (size_t k = 0; k < refsA.size(); ++k) {
            out.push_back({refsA[k], refsB[k]});
            if (!codeB.count(refsB[k])) tables.insert({refsA[k], refsB[k]});
        }
    }
    for (const auto& [ta, tb] : tables) {
        bool zero = false;
        for (uint32_t off = 0; off < 1024; off += 4) {
            const uint8_t* pa = orig.at(ta + off, 4);
            const uint8_t* pb = lib.at(tb + off, 4);
            if (!pa || !pb) break;
            uint32_t va, vb;
            std::memcpy(&va, pa, 4);
            std::memcpy(&vb, pb, 4);
            if (orig.contains(va) != lib.contains(vb)) break;  // the layouts part
            if (vb == 0 && zero) break;
            zero = vb == 0;
            if (lib.contains(vb)) out.push_back({va, vb});
        }
    }
    return out;
}

// Pairs every unmatched function start the two sides refer to in the same place (pairedReferences). A function
// claimed by two different partners is left alone.
int pairByReference(const Image& orig, const Image& lib, std::vector<Function>& a, std::vector<Function>& b,
                    std::map<uint32_t, std::string>& namesA, std::map<uint32_t, std::string>& namesB) {
    std::map<uint32_t, int> startA, startB;
    std::set<uint32_t> codeB;
    for (int i = 0; i < int(a.size()); ++i) startA[a[i].va] = i;
    for (int j = 0; j < int(b.size()); ++j) startB[b[j].va] = j, codeB.insert(b[j].va);
    std::map<int, std::set<int>> claims;  // library index -> original indexes
    std::map<int, std::set<int>> claimedBy;
    for (const auto& [ra, rb] : pairedReferences(orig, lib, a, b, namesA, namesB, codeB)) {
        auto ia = startA.find(ra);
        auto jb = startB.find(rb);
        if (ia == startA.end() || jb == startB.end()) continue;
        if (a[ia->second].match >= 0 || b[jb->second].match >= 0) continue;
        claims[jb->second].insert(ia->second);
        claimedBy[ia->second].insert(jb->second);
    }
    int found = 0;
    for (const auto& [j, is] : claims) {
        int i = *is.begin();
        if (is.size() != 1 || claimedBy[i].size() != 1) continue;
        a[i].match = j;
        b[j].match = i;
        namesA[a[i].va] = namesB[b[j].va] = b[j].name;
        ++found;
    }
    return found;
}

int pairByPosition(std::vector<Function>& a, std::vector<Function>& b, std::map<uint32_t, std::string>& namesA,
                   std::map<uint32_t, std::string>& namesB) {
    int found = 0;
    for (size_t j = 0; j < b.size();) {
        if (b[j].match >= 0) { ++j; continue; }
        size_t end = j;  // the run b[j, end) of unmatched functions in one object
        while (end < b.size() && b[end].match < 0 && b[end].object == b[j].object) ++end;
        bool anchored = j > 0 && end < b.size() && b[j - 1].object == b[j].object && b[end].object == b[j].object;
        if (anchored) {
            uint32_t lo = a[b[j - 1].match].va, hi = a[b[end].match].va;
            std::vector<int> run;
            bool clean = lo < hi;
            for (int i = 0; clean && i < int(a.size()); ++i) {
                if (a[i].va <= lo || a[i].va >= hi) continue;
                if (a[i].match >= 0) clean = false;  // something else sits in between: not the same layout
                else run.push_back(i);
            }
            if (clean && run.size() == end - j) {
                for (size_t k = 0; k < run.size(); ++k) {
                    Function &x = a[run[k]], &y = b[j + k];
                    x.match = int(j + k);
                    y.match = run[k];
                    y.byPosition = true;
                    namesA[x.va] = namesB[y.va] = y.name;
                    ++found;
                }
            }
        }
        j = end;
    }
    return found;
}

}  // namespace

int main(int argc, char** argv) {
    if (argc < 6) {
        std::fprintf(stderr,
                     "usage: obsig <original.exe> <original-functions.tsv> <library.dll> <library-functions.tsv> "
                     "<library.map> [--out matches.tsv] [--min N] [--list] [--diff NAME] [--twins] [--no-position]\n");
        return 2;
    }
    std::string outPath, diffName;
    size_t minCount = 3;
    bool listNear = false, twins = false, position = true;
    for (int i = 6; i < argc; ++i) {
        if (std::strcmp(argv[i], "--list") == 0) listNear = true;
        else if (std::strcmp(argv[i], "--twins") == 0) twins = true;
        else if (std::strcmp(argv[i], "--no-position") == 0) position = false;
        else if (i + 1 >= argc) break;
        else if (std::strcmp(argv[i], "--out") == 0) outPath = argv[++i];
        else if (std::strcmp(argv[i], "--min") == 0) minCount = std::stoul(argv[++i]);
        else if (std::strcmp(argv[i], "--diff") == 0) diffName = argv[++i];
    }
    Image orig, lib;
    if (!loadImage(argv[1], orig)) { std::fprintf(stderr, "cannot read PE32 image %s\n", argv[1]); return 2; }
    if (!loadImage(argv[3], lib)) { std::fprintf(stderr, "cannot read PE32 image %s\n", argv[3]); return 2; }
    std::vector<Function> a, b;
    if (!readFunctions(argv[2], a) || !readFunctions(argv[4], b)) {
        std::fprintf(stderr, "cannot read a function list\n");
        return 2;
    }
    applyMap(argv[5], b);

    std::map<uint32_t, std::string> namesA, namesB;
    for (int round = 1;; ++round) {
        // token string -> indexes of the unmatched functions with it, per side
        std::unordered_map<std::string, std::pair<std::vector<int>, std::vector<int>>> groups;
        for (int i = 0; i < int(a.size()); ++i) {
            if (a[i].match >= 0) continue;
            size_t n;
            std::string s = signature(orig, namesA, a[i], n);
            if (n >= minCount) groups[s].first.push_back(i);
        }
        for (int j = 0; j < int(b.size()); ++j) {
            if (b[j].match >= 0) continue;
            size_t n;
            std::string s = signature(lib, namesB, b[j], n);
            if (n >= minCount) groups[s].second.push_back(j);
        }
        int found = 0;
        for (auto& [s, g] : groups) {
            if (g.first.size() != 1 || g.second.empty() || (g.second.size() != 1 && !twins)) continue;
            int i = g.first[0], j = g.second[0];
            for (int k : g.second) if (b[k].name < b[j].name) j = k;
            a[i].match = j;
            b[j].match = i;
            namesA[a[i].va] = namesB[b[j].va] = b[j].name;
            for (int k : g.second)
                if (k != j) b[k].match = i, b[k].twin = true, namesB[b[k].va] = b[j].name, b[j].hasTwins = true;
            ++found;
        }
        // When the token rounds stall, pair through the references of identical pairs, then by position: a run of
        // unmatched functions of one object between two matched neighbours faces the same number of unmatched functions between the neighbours' matches.
        if (!found) found = pairByReference(orig, lib, a, b, namesA, namesB);
        if (!found && position) found = pairByPosition(a, b, namesA, namesB);
        std::fprintf(stderr, "round %d: %d new matches\n", round, found);
        if (!found) break;
    }

    // A missing library function matters when a matched function, or a table one refers to, refers to it: the
    // original has something in that place we failed to pair. The rest were most likely never linked into the
    // original (its linker drops what nothing uses, and an inlined static leaves an unused copy in our build).
    std::set<uint32_t> codeB, referenced;
    for (const Function& fn : b) codeB.insert(fn.va);
    for (const auto& r : pairedReferences(orig, lib, a, b, namesA, namesB, codeB)) referenced.insert(r.second);

    // Every pair rescored with all names known: identical, or how close (a position pair can differ).
    struct Tally { int fns = 0, same = 0, near = 0, absent = 0; uint64_t bytes = 0, sameBytes = 0; };
    std::map<std::string, Tally> perObject;
    Tally all;
    std::vector<std::string> nearLines;
    for (const Function& fn : b) {
        double score = 0;
        bool same = false;
        if (fn.match >= 0) {
            auto x = tokenize({&orig, &namesA}, a[fn.match].va, a[fn.match].size);
            auto y = tokenize({&lib, &namesB}, fn.va, fn.size);
            trimPadding(x);
            trimPadding(y);
            same = x == y;
            size_t longest = std::max(x.size(), y.size());
            score = longest ? 100.0 * double(lcs(x, y)) / double(longest) : 0;
            if (fn.name == diffName) {
                for (size_t i = 0; i < longest; ++i) {
                    const std::string& p = i < x.size() ? x[i] : std::string();
                    const std::string& q = i < y.size() ? y[i] : std::string();
                    std::printf("    %c %-48s | %s\n", p == q ? ' ' : '!', p.c_str(), q.c_str());
                }
            }
            if (!same) {
                char line[512];
                std::snprintf(line, sizeof line, "  near %5.1f%%  %s  %s (%s)", score, hex(a[fn.match].va).c_str(),
                              fn.name.c_str(), fn.object.c_str());
                nearLines.push_back(line);
            }
        }
        Tally& t = perObject[fn.object.empty() ? "?" : fn.object];
        for (Tally* x : {&t, &all}) {
            ++x->fns;
            x->bytes += fn.size;
            if (same) ++x->same, x->sameBytes += fn.size;
            else if (fn.match >= 0) ++x->near;
            else if (!referenced.count(fn.va)) ++x->absent, x->bytes -= fn.size;
        }
    }
    for (const auto& [object, t] : perObject)
        std::printf("%-24s %4d identical %4d near %4d missing %4d absent  of %4d  (%5.1f%% of needed bytes "
                    "identical)\n",
                    object.c_str(), t.same, t.near, t.fns - t.same - t.near - t.absent, t.absent, t.fns,
                    t.bytes ? 100.0 * double(t.sameBytes) / double(t.bytes) : 0.0);
    if (listNear)
        for (const auto& l : nearLines) std::printf("%s\n", l.c_str());
    for (const Function& fn : b)
        if (listNear && fn.match < 0)
            std::printf("  %-14s %s (%s)\n", referenced.count(fn.va) ? "missing" : "absent", fn.name.c_str(),
                        fn.object.c_str());
    std::printf("total: %d identical, %d near, %d missing, %d absent of %d library functions (%.1f%% of needed bytes "
                "identical)\n",
                all.same, all.near, all.fns - all.same - all.near - all.absent, all.absent, all.fns,
                all.bytes ? 100.0 * double(all.sameBytes) / double(all.bytes) : 0.0);

    if (!outPath.empty()) {
        std::ofstream out(outPath);
        for (const Function& fn : b) {
            if (fn.match < 0 || fn.twin) continue;
            const Function& o = a[fn.match];
            out << std::hex << o.va << '\t' << o.size << '\t' << fn.va << '\t' << fn.size << '\t' << fn.name
                << (fn.byPosition ? "\t# by position" : fn.hasTwins ? "\t# twins" : "") << '\n';
        }
    }
    return 0;
}
