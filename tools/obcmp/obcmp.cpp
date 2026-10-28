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
#include "pe.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <map>
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
