// obcmp — compares functions of a rebuilt binary against the original program, instruction by instruction.
//
//   obcmp <original.exe> <rebuilt.exe|dll> <pairs.tsv> [--verbose] [--names names.tsv] [--vtables vtables.tsv]
//
// pairs.tsv: one function per line, "orig_va  orig_size  rebuilt_va  rebuilt_size  name" (hex VAs and sizes,
// tab- or space-separated, '#' starts a comment). For every pair it prints the match score (0-100) and a total.
// Several pairs may share an original function: the original's linker folded identical bodies (/OPT:ICF) that are
// separate functions in the rebuild. All of them take the first pair's name, so each compares equal to it.
//
// Each instruction becomes a token: mnemonic plus normalised operands. Absolute addresses inside the image are
// replaced by what they refer to where that is known (a paired function), otherwise by "addr", so two builds placed
// at different addresses still compare equal. Branch targets inside the function become offsets from its start in
// instructions. The score is the longest common subsequence of the two token lists over the longer list.
//
// vtables.tsv: "orig_va rebuilt_va orig_slots rebuilt_slots name [strict|report]": vtables compared slot by slot (a
// "report" one does not fail the run), each slot's function
// by name (paired or named functions), and their addresses named for the code that stores them.
// names.tsv: more address pairs that only name ("orig_va rebuilt_va name"), not scored: the stubs that stand in for
// functions not decompiled yet, so a call to the wrong one of them is a difference instead of "addr" on both sides.
#include "pe.h"

#include <algorithm>
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

struct Pair {
    uint32_t origVa, origSize, newVa, newSize;
    std::string name;
};


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
        std::fprintf(stderr, "usage: obcmp <original.exe> <rebuilt.exe|dll> <pairs.tsv> [--verbose] [--names names.tsv] [--vtables vtables.tsv]\n");
        return 2;
    }
    bool verbose = false;
    std::string namesPath, vtablesPath;
    for (int i = 4; i < argc; ++i) {
        if (std::strcmp(argv[i], "--verbose") == 0) verbose = true;
        else if (std::strcmp(argv[i], "--names") == 0 && i + 1 < argc) namesPath = argv[++i];
        else if (std::strcmp(argv[i], "--vtables") == 0 && i + 1 < argc) vtablesPath = argv[++i];
        else { std::fprintf(stderr, "unknown argument %s\n", argv[i]); return 2; }
    }
    Image orig, rebuilt;
    if (!loadImage(argv[1], orig)) { std::fprintf(stderr, "cannot read PE32 image %s\n", argv[1]); return 2; }
    if (!loadImage(argv[2], rebuilt)) { std::fprintf(stderr, "cannot read PE32 image %s\n", argv[2]); return 2; }
    std::vector<Pair> pairs;
    if (!parsePairs(argv[3], pairs) || pairs.empty()) { std::fprintf(stderr, "no pairs in %s\n", argv[3]); return 2; }

    // Both sides refer to a paired function by the same name, so a call to it compares equal.
    std::map<uint32_t, std::string> origNames, newNames;
    // Every original function each of ours stands for: one of ours can be paired with several originals (the
    // original kept two copies of what our build makes once, e.g. a base's adjustor thunk used by two classes).
    std::map<uint32_t, std::set<uint32_t>> standsFor;
    for (const Pair& p : pairs) {
        origNames.emplace(p.origVa, p.name);  // a folded function: every copy takes the first pair's name
        newNames[p.newVa] = origNames[p.origVa];
        standsFor[p.newVa].insert(p.origVa);
    }
    if (!namesPath.empty()) {
        std::ifstream f(namesPath);
        if (!f) { std::fprintf(stderr, "cannot read %s\n", namesPath.c_str()); return 2; }
        std::string a, b, name;
        while (f >> a >> b >> name) {
            uint32_t o = uint32_t(std::stoul(a, nullptr, 16)), n = uint32_t(std::stoul(b, nullptr, 16));
            origNames.emplace(o, name);  // a paired function keeps its pair's name
            newNames.emplace(n, origNames[o]);
            standsFor[n].insert(o);
        }
    }
    struct Vtable {
        uint32_t origVa, newVa, slots, newSlots;
        std::string name;
        bool strict;  // must be identical (else only reported)
    };
    std::vector<Vtable> vtables;
    if (!vtablesPath.empty()) {
        std::ifstream f(vtablesPath);
        if (!f) { std::fprintf(stderr, "cannot read %s\n", vtablesPath.c_str()); return 2; }
        std::string line;
        while (std::getline(f, line)) {
            std::istringstream ss(line);
            std::string a, b, n, m, name, mode;
            if (!(ss >> a >> b >> n >> m >> name)) continue;
            ss >> mode;
            Vtable v{uint32_t(std::stoul(a, nullptr, 16)), uint32_t(std::stoul(b, nullptr, 16)),
                     uint32_t(std::stoul(n)), uint32_t(std::stoul(m)), name, mode != "report"};
            origNames[v.origVa] = newNames[v.newVa] = name;  // a store of the vtable compares by it
            vtables.push_back(v);
        }
    }

    double weighted = 0;
    size_t total = 0, exact = 0;
    for (const Pair& p : pairs) {
        auto a = tokenize({&orig, &origNames}, p.origVa, p.origSize);
        auto b = tokenize({&rebuilt, &newNames}, p.newVa, p.newSize);
        trimPadding(a);
        trimPadding(b);
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

    // Vtables: slot by slot, each slot's function by its name on both sides, or ours paired with the original's (a
    // function neither paired nor stubbed is its address, so it differs).
    size_t vexact = 0, vstrictBad = 0;
    for (Vtable& v : vtables) {
        auto slot = [](const Image& img, const std::map<uint32_t, std::string>& names, uint32_t va, uint32_t i,
                       uint32_t& t) {
            const uint8_t* b = img.at(va + 4 * i, 4);
            t = 0;
            if (!b) return std::string("?");
            std::memcpy(&t, b, 4);
            auto it = names.find(t);
            return it != names.end() ? it->second : hex(t);
        };
        size_t same = 0;
        std::vector<std::string> lines;
        for (uint32_t i = 0; i < v.slots; ++i) {
            uint32_t to, tn;
            std::string x = slot(orig, origNames, v.origVa, i, to), y = slot(rebuilt, newNames, v.newVa, i, tn);
            auto it = standsFor.find(tn);
            bool eq = x == y || (it != standsFor.end() && it->second.count(to));
            same += eq;
            lines.push_back((eq ? "      " : "    ! ") + std::to_string(i) + " " + x + " | " + y);
        }
        // Our vtable ends at the next symbol or at the first word that is no code address, whichever is first.
        uint32_t ours = 0;
        for (; ours < v.newSlots; ++ours) {
            const uint8_t* b = rebuilt.at(v.newVa + 4 * ours, 4);
            uint32_t t = 0;
            if (b) std::memcpy(&t, b, 4);
            if (!b || !rebuilt.isCode(t)) break;
        }
        v.newSlots = ours;
        bool identical = same == v.slots && ours == v.slots;
        vexact += identical;
        vstrictBad += !identical && v.strict;
        std::printf("%6.2f%%  %s  %s (vtable, %u slots)\n", identical ? 100.0 : 100.0 * double(same) / v.slots,
                    hex(v.origVa).c_str(), v.name.c_str(), v.slots);
        if (verbose && !identical) {
            for (auto& l : lines) std::printf("%s\n", l.c_str());
            if (v.newSlots != v.slots) std::printf("    ! ours has %u slots\n", v.newSlots);
        }
    }
    if (!vtables.empty())
        std::printf("total: %zu/%zu vtables identical (%zu required ones differ)\n", vexact, vtables.size(), vstrictBad);
    return exact == pairs.size() && vstrictBad == 0 ? 0 : 1;
}
