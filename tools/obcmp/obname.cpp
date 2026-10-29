// obname — names the original program's functions and classes from a build of the same source that kept its
// symbols (the Mac reference build), by pairing what both builds share:
//   1. functions, by the strings and 32-bit IDs they use, when a pair is each other's best and well ahead of the next;
//   2. the callees and callers of a pair, when each side has exactly one left unpaired;
//   3. vtables, by the votes of the slots already paired (a class's own slots vote, inherited ones barely);
//   4. every slot of a paired vtable, by aligning the two slot lists: the reference build's compiler gives a virtual
//      destructor two slots (complete, deleting) where ours has one, puts overrides of a secondary base's functions
//      into the primary table, and declares overloads in source order where ours groups them in reverse. The `ret N`
//      of each of our slots must agree with the argument list of the name it gets.
// Stages 3 and 4 add pairs, so 2-4 run again until nothing changes.
//
//   obname --win-feat F --win-slots F --win-shapes F --win-classes F
//          --mac-feat F --mac-funcs F --mac-vtables F --out DIR
//          [--truth-lib libraries.tsv] [--truth-known known.tsv]
//
// Inputs: obfeat's feat.tsv for our program; scratch/classes/{slots,shapes,classes}.tsv (obclass, obshape);
// tools/names/mac-features.sh and mac-tables.sh output for the reference build. Writes to DIR:
//   functions.tsv  addr  name  how  mac-addr      how: F features, G call graph, S vtable slot (s: by position only);
//                  mac-addr = the reference function the name comes from
//   slots.tsv      vtable  index  name  how
//   classes.tsv    primary-vtable  class  votes  runner-up-votes  slots  named-slots
//   vtables.tsv    vtable  mac-class  part  votes                 (every paired vtable, secondary ones too)
// --truth-*: functions/classes whose names are known some other way; the precision of each stage against them is
// printed (a pairing nothing checks is a guess).
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

uint32_t hexv(const std::string& s) { return uint32_t(std::strtoul(s.c_str(), nullptr, 16)); }

std::vector<std::string> split(const std::string& line, char sep = '\t') {
    std::vector<std::string> out;
    size_t a = 0;
    for (;;) {
        size_t b = line.find(sep, a);
        out.push_back(line.substr(a, b == std::string::npos ? std::string::npos : b - a));
        if (b == std::string::npos) break;
        a = b + 1;
    }
    return out;
}

struct Side {
    std::vector<uint32_t> addr;
    std::unordered_map<uint32_t, int> at;
    std::vector<std::vector<int>> feats;    // interned s/k/r features
    std::vector<std::vector<int>> callees;  // indices
    std::vector<std::vector<int>> callers;
    std::vector<int> ninst;
    std::vector<std::string> name;          // reference build only
    std::vector<int> partner;
    std::vector<char> how;
    int get(uint32_t a) {
        auto it = at.find(a);
        if (it != at.end()) return it->second;
        int i = int(addr.size());
        addr.push_back(a);
        at[a] = i;
        feats.emplace_back();
        callees.emplace_back();
        callers.emplace_back();
        ninst.push_back(0);
        name.emplace_back();
        partner.push_back(-1);
        how.push_back(0);
        return i;
    }
    int find(uint32_t a) const {
        auto it = at.find(a);
        return it == at.end() ? -1 : it->second;
    }
};

std::unordered_map<std::string, int> featId;
std::vector<std::string> featKey;

int intern(const std::string& k) {
    auto it = featId.find(k);
    if (it != featId.end()) return it->second;
    int id = int(featKey.size());
    featKey.push_back(k);
    featId[k] = id;
    return id;
}

void readFeat(const std::string& path, Side& s) {
    std::ifstream f(path);
    if (!f) { std::fprintf(stderr, "cannot read %s\n", path.c_str()); std::exit(2); }
    std::string line;
    std::vector<std::pair<int, uint32_t>> calls;
    while (std::getline(f, line)) {
        auto p = split(line);
        if (p.size() < 3) continue;
        int i = s.get(hexv(p[0]));
        const std::string& k = p[1];
        if (k == "s" || k == "k" || k == "r") s.feats[i].push_back(intern(k + "\x1f" + p[2]));
        else if (k == "c") calls.push_back({i, hexv(p[2])});
        else if (k == "n") s.ninst[i] = std::atoi(p[2].c_str());
    }
    for (auto [i, t] : calls) {
        int j = s.find(t);
        if (j < 0 || j == i) continue;
        s.callees[i].push_back(j);
        s.callers[j].push_back(i);
    }
    for (auto& v : s.feats) { std::sort(v.begin(), v.end()); v.erase(std::unique(v.begin(), v.end()), v.end()); }
    for (auto* vv : {&s.callees, &s.callers})
        for (auto& v : *vv) { std::sort(v.begin(), v.end()); v.erase(std::unique(v.begin(), v.end()), v.end()); }
}

Side W, M;
double sizeRatio = 1.0;  // median instructions of a reference-build function per one of ours (set after stage 1)
std::vector<int> wPops;  // bytes each of our functions pops (ret N), -1 unknown

// How alike two function bodies are, past their slot: size (calibrated for the two compilers) and paired callees.
double bodyScore(int w, int m) {
    if (w < 0 || m < 0) return 0;
    double s = 0;
    int a = W.ninst[size_t(w)], b = M.ninst[size_t(m)];
    if (a >= 4 && b >= 4) {
        double d = std::fabs(std::log(double(b) / (double(a) * sizeRatio)));
        s += d < 0.3 ? 1.5 : d < 0.6 ? 0.5 : d > 1.0 ? -1.0 : 0;
    }
    for (int c : W.callees[size_t(w)]) {
        int p = W.partner[size_t(c)];
        if (p >= 0) s += std::binary_search(M.callees[size_t(m)].begin(), M.callees[size_t(m)].end(), p) ? 2 : -0.5;
    }
    return s;
}

bool sizesAgree(int w, int m) {
    int a = W.ninst[w], b = M.ninst[m];
    if (a == 0 || b == 0) return true;
    int lo = std::min(a, b), hi = std::max(a, b);
    return lo <= 8 || hi <= 5 * lo;
}

void pair(int w, int m, char how) {
    W.partner[w] = m;
    M.partner[m] = w;
    W.how[w] = how;
}

// ---- stage 1: features -------------------------------------------------------------------------------------------
int stageFeatures() {
    const int maxDf = 6;
    std::vector<int> dfW(featKey.size()), dfM(featKey.size());
    std::vector<std::vector<int>> postM(featKey.size()), postW(featKey.size());
    for (size_t i = 0; i < W.feats.size(); ++i) for (int f : W.feats[i]) { ++dfW[f]; postW[f].push_back(int(i)); }
    for (size_t i = 0; i < M.feats.size(); ++i) for (int f : M.feats[i]) { ++dfM[f]; postM[f].push_back(int(i)); }
    auto weight = [&](int f) { return 1.0 / (double(dfW[f]) * double(dfM[f])); };
    auto best = [&](const Side& a, const std::vector<std::vector<int>>& post, const std::vector<int>& dfA,
                    const std::vector<int>& dfB, std::vector<int>& bi, std::vector<double>& bs, std::vector<double>& ss) {
        bi.assign(a.feats.size(), -1);
        bs.assign(a.feats.size(), 0);
        ss.assign(a.feats.size(), 0);
        std::unordered_map<int, double> cand;
        for (size_t i = 0; i < a.feats.size(); ++i) {
            cand.clear();
            for (int f : a.feats[i])
                if (dfA[f] <= maxDf && dfB[f] >= 1 && dfB[f] <= maxDf)
                    for (int j : post[f]) cand[j] += weight(f);
            for (auto [j, sc] : cand) {
                if (sc > bs[i]) { ss[i] = bs[i]; bs[i] = sc; bi[i] = j; }
                else if (sc > ss[i]) ss[i] = sc;
            }
        }
    };
    std::vector<int> bw, bm;
    std::vector<double> sw, s2w, sm, s2m;
    best(W, postM, dfW, dfM, bw, sw, s2w);
    best(M, postW, dfM, dfW, bm, sm, s2m);
    int n = 0;
    for (size_t w = 0; w < bw.size(); ++w) {
        int m = bw[w];
        if (m < 0 || bm[m] != int(w)) continue;
        if (sw[w] < 0.99 || sw[w] < 2 * s2w[w] || sm[m] < 2 * s2m[m]) continue;
        if (!sizesAgree(int(w), m)) continue;
        pair(int(w), m, 'F');
        ++n;
    }
    return n;
}

// ---- stage 2: call graph -----------------------------------------------------------------------------------------
// Whether pairing w with m agrees with the pairs around them: their paired callers and callees should be partners
// of each other's (a helper one compiler inlined makes the 1-1 rule below pair the wrong function).
bool neighboursAgree(int w, int m) {
    int agree = 0, disagree = 0;
    for (int dir = 0; dir < 2; ++dir) {
        const auto& lw = dir ? W.callers[size_t(w)] : W.callees[size_t(w)];
        const auto& lm = dir ? M.callers[size_t(m)] : M.callees[size_t(m)];
        for (int x : lw) {
            int p = W.partner[size_t(x)];
            if (p < 0) continue;
            (std::binary_search(lm.begin(), lm.end(), p) ? agree : disagree)++;
        }
    }
    return disagree <= agree;
}

int argBytes(const std::string& sig);

// Whether our function's ret N fits the reference function's arguments: a member pops its arguments, a free
// function none (cdecl) or all (stdcall).
bool popsAgree(int w, int m) {
    int p = size_t(w) < wPops.size() ? wPops[size_t(w)] : -1;
    int b = argBytes(M.name[size_t(m)]);
    if (p < 0 || b < 0) return true;
    std::string head = M.name[size_t(m)].substr(0, M.name[size_t(m)].find('('));
    if (head.find("::") == std::string::npos) return p == 0 || p == b;
    return p == b;
}

bool sizesClose(int w, int m) {
    int a = W.ninst[size_t(w)], b = M.ninst[size_t(m)];
    if (a < 8 && b < 8) return true;
    a = std::max(a, 1); b = std::max(b, 1);
    return std::fabs(std::log(double(b) / (double(a) * sizeRatio))) < 0.7;
}

int stageGraph() {
    int total = 0;
    for (;;) {
        int n = 0;
        for (size_t w = 0; w < W.partner.size(); ++w) {
            int m = W.partner[w];
            if (m < 0) continue;
            for (int dir = 0; dir < 2; ++dir) {
                const auto& lw = dir ? W.callers[w] : W.callees[w];
                const auto& lm = dir ? M.callers[m] : M.callees[m];
                int uw = -1, um = -1, cw = 0, cm = 0;
                for (int x : lw) if (W.partner[x] < 0) { uw = x; ++cw; }
                for (int x : lm) if (M.partner[x] < 0) { um = x; ++cm; }
                if (cw == 1 && cm == 1 && sizesClose(uw, um) && popsAgree(uw, um) && neighboursAgree(uw, um)) { pair(uw, um, 'G'); ++n; }
            }
        }
        total += n;
        if (!n) break;
    }
    return total;
}

// ---- vtables ------------------------------------------------------------------------------------------------------
struct WSlot { uint32_t target; std::string kind; uint32_t method; int pops; };  // pops -1 unknown
struct MSlot { uint32_t target; std::string name; };

std::map<uint32_t, std::vector<WSlot>> wVt;                    // vtable → slots
std::map<uint32_t, uint32_t> wBase0;                           // primary vtable → primary vtable of its base at 0
std::set<uint32_t> wPrimary;
struct MVt { std::string cls; std::vector<std::vector<MSlot>> parts; };
std::map<uint32_t, MVt> mVt;
std::unordered_map<int, std::vector<std::pair<uint32_t, int>>> mSlotsOf;  // M fn index → (mac vtable, part)

// Bytes of arguments a reference-build signature takes under our compiler's convention, or -1 when an argument's
// size is unknown (a class or enum by value).
int argBytes(const std::string& sig) {
    size_t open = sig.find('(');
    if (open == std::string::npos) return -1;
    int depth = 0;
    size_t close = std::string::npos;
    for (size_t i = open; i < sig.size(); ++i) {
        if (sig[i] == '(' || sig[i] == '<') ++depth;
        else if (sig[i] == ')' || sig[i] == '>') { if (--depth == 0 && sig[i] == ')') { close = i; break; } }
    }
    if (close == std::string::npos) return -1;
    std::string args = sig.substr(open + 1, close - open - 1);
    if (args.empty() || args == "void") return 0;
    std::vector<std::string> list;
    depth = 0;
    std::string cur;
    for (char c : args) {
        if (c == '<' || c == '(') ++depth;
        if (c == '>' || c == ')') --depth;
        if (c == ',' && depth == 0) { list.push_back(cur); cur.clear(); } else cur += c;
    }
    list.push_back(cur);
    int bytes = 0;
    for (std::string a : list) {
        while (!a.empty() && a.front() == ' ') a.erase(a.begin());
        if (a.find('*') != std::string::npos || a.find('&') != std::string::npos) { bytes += 4; continue; }
        if (a == "double" || a == "long long" || a == "unsigned long long") { bytes += 8; continue; }
        static const std::set<std::string> four = {"int", "unsigned int", "long", "unsigned long", "float", "bool",
            "char", "signed char", "unsigned char", "short", "unsigned short", "wchar_t", "unsigned"};
        if (four.count(a)) { bytes += 4; continue; }
        return -1;
    }
    return bytes;
}

std::string methodOf(const std::string& sig) {  // "cA::cB<x>::Name(args) const" → "Name"
    size_t open = sig.find('(');
    std::string head = sig.substr(0, open);
    int depth = 0;
    size_t cut = std::string::npos;
    for (size_t i = 0; i + 1 < head.size(); ++i) {
        if (head[i] == '<') ++depth;
        else if (head[i] == '>') --depth;
        else if (depth == 0 && head[i] == ':' && head[i + 1] == ':') cut = i + 2;
    }
    return cut == std::string::npos ? head : head.substr(cut);
}

bool isDtor(const std::string& sig) { return methodOf(sig).rfind("~", 0) == 0; }

std::string thunkTarget(const std::string& name) {  // "non-virtual thunk to X::f(...)" → "X::f(...)"
    for (const char* p : {"non-virtual thunk to ", "virtual thunk to "})
        if (name.rfind(p, 0) == 0) return name.substr(std::string(p).size());
    return name;
}

// The reference build's slot list of one part, rearranged the way our compiler lays the same declarations out.
std::vector<MSlot> msvcOrder(const MVt& vt, int part, bool group) {
    std::vector<MSlot> in = vt.parts[part], out;
    std::set<std::string> secondary;  // overrides of secondary bases' functions: thunks in the other parts
    if (part == 0)
        for (size_t p = 1; p < vt.parts.size(); ++p)
            for (const MSlot& s : vt.parts[p]) secondary.insert(thunkTarget(s.name));
    for (size_t i = 0; i < in.size(); ++i) {
        MSlot s = in[i];
        if (part > 0) s.name = thunkTarget(s.name);
        if (isDtor(s.name) && i + 1 < in.size() && isDtor(in[i + 1].name)) { out.push_back(s); ++i; continue; }
        if (part == 0 && i > 0 && secondary.count(s.name) && !isDtor(s.name)) continue;
        out.push_back(s);
    }
    if (!group) return out;
    // overloads together at the first one's place, in reverse order
    std::vector<MSlot> g;
    std::vector<bool> used(out.size());
    for (size_t i = 0; i < out.size(); ++i) {
        if (used[i]) continue;
        std::string m = methodOf(out[i].name);
        std::vector<size_t> run = {i};
        if (!isDtor(out[i].name) && out[i].name != "?")
            for (size_t j = i + 1; j < out.size(); ++j)
                if (!used[j] && methodOf(out[j].name) == m) run.push_back(j);
        for (auto it = run.rbegin(); it != run.rend(); ++it) { g.push_back(out[*it]); used[*it] = true; }
    }
    return g;
}

struct Align { double score = -1e9; std::vector<int> map; };  // map[w slot] = index into the M list, or -1

Align align(const std::vector<WSlot>& ws, const std::vector<MSlot>& ms) {
    size_t n = ws.size(), l = ms.size();
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(l + 1, -1e9));
    std::vector<std::vector<char>> mv(n + 1, std::vector<char>(l + 1, 0));
    dp[0][0] = 0;
    auto score = [&](size_t i, size_t j) {
        const WSlot& w = ws[i];
        const MSlot& m = ms[j];
        double s = 0;
        if (m.name == "?") return 0.5;  // a slot the reference data lost: keeps its place, says nothing
        int wi = W.find(w.kind == "thunk" ? w.method : w.target);
        int mi = M.find(m.target);
        if (wi >= 0 && mi >= 0 && W.partner[wi] == mi) s += 6;
        else if (wi >= 0 && W.partner[wi] >= 0) s -= 4;
        else s += bodyScore(wi, mi);
        bool wd = w.kind == "deleting-dtor", md = isDtor(m.name);
        if (wd && md) s += 3;
        else if (wd != md) s -= 6;
        if (!wd && w.pops >= 0) {
            int b = argBytes(m.name);
            if (b >= 0) s += (b == w.pops) ? 1 : -3;
        }
        return s;
    };
    for (size_t i = 0; i <= n; ++i)
        for (size_t j = 0; j <= l; ++j) {
            if (dp[i][j] <= -1e8) continue;
            if (i < n && j < l) { double v = dp[i][j] + score(i, j); if (v > dp[i + 1][j + 1]) { dp[i + 1][j + 1] = v; mv[i + 1][j + 1] = 'm'; } }
            if (j < l) { double v = dp[i][j] - 0.5; if (v > dp[i][j + 1]) { dp[i][j + 1] = v; mv[i][j + 1] = 'l'; } }
            if (i < n) { double v = dp[i][j] - 4; if (v > dp[i + 1][j]) { dp[i + 1][j] = v; mv[i + 1][j] = 'w'; } }
        }
    Align a;
    size_t bj = 0;
    for (size_t j = 0; j <= l; ++j) if (dp[n][j] > a.score) { a.score = dp[n][j]; bj = j; }
    a.map.assign(n, -1);
    size_t i = n, j = bj;
    while (i > 0 || j > 0) {
        char c = mv[i][j];
        if (c == 'm') { a.map[i - 1] = int(j - 1); --i; --j; }
        else if (c == 'l') --j;
        else if (c == 'w') --i;
        else break;
    }
    return a;
}

struct VtPair { uint32_t mac = 0; int part = -1; double votes = 0, second = 0; char how = 'v'; };
std::map<uint32_t, VtPair> vtPairs;
std::set<std::pair<uint32_t, int>> macUsed;  // reference-build tables already given to one of ours
std::map<std::pair<uint32_t, int>, std::pair<std::string, char>> slotNames;  // (vtable, index) → (name, how)
std::map<std::pair<uint32_t, int>, uint32_t> slotMac;  // (vtable, index) → the reference function named after
std::unordered_map<uint32_t, int> ownSlots;  // our function → how many own slots hold it (more than one: folded twins)
uint32_t purecall = 0x5d4a10;  // the pure-virtual stub (hook/stubs.txt)
std::map<uint32_t, std::vector<uint32_t>> wLayout;  // our primary vtable → its secondary vtables, in offset order
std::map<uint32_t, std::set<uint32_t>> mBase;       // reference vtable → its direct base's (longest proper prefix)
std::map<uint32_t, std::vector<uint32_t>> mChildren;

void addPair(uint32_t vt, uint32_t mac, int part, double votes, double second, char how) {
    VtPair p;
    p.mac = mac; p.part = part; p.votes = votes; p.second = second; p.how = how;
    vtPairs[vt] = p;
    macUsed.insert({mac, part});
}

// How well one of our tables fits a reference table: the better of the two overload orders.
double fit(uint32_t vt, uint32_t mac, int part) {
    const MVt& mv = mVt[mac];
    if (part >= int(mv.parts.size())) return -1e9;
    double best = -1e9;
    const auto& ws = wVt[vt];
    std::string own = mv.cls + "::";
    for (bool g : {false, true}) {
        auto ms = msvcOrder(mv, part, g);
        Align a = align(ws, ms);
        // ownership: a slot our class declares itself should hold a function of that class there too, and an
        // inherited one a base's (a derived class that overrides nothing has the same slots as its base)
        double o = 0;
        for (size_t i = 0; i < ws.size(); ++i) {
            if (a.map[i] < 0 || ws[i].target == purecall) continue;
            bool mine = ms[size_t(a.map[i])].name.rfind(own, 0) == 0;
            bool wOwn = ws[i].kind != "inherited";
            o += (mine == wOwn) ? 0.5 : -0.5;
        }
        best = std::max(best, a.score + o);
    }
    return best;
}

// How many of our class's own slots, both bodies at least 10 instructions, differ in size by more than e (calibrated):
// a pairing by structure alone (interface IDs, hierarchy) whose bodies mostly disagree is a look-alike.
std::pair<int, int> sizeDisagreement(uint32_t vt, uint32_t mac, int part) {
    const auto& ws = wVt[vt];
    std::pair<int, int> best{0, 0};
    double bs = -1e9;
    for (bool g : {false, true}) {
        auto ms = msvcOrder(mVt[mac], part, g);
        Align a = align(ws, ms);
        if (a.score <= bs) continue;
        bs = a.score;
        int tot = 0, bad = 0;
        for (size_t i = 0; i < ws.size(); ++i) {
            if (a.map[i] < 0 || ws[i].kind == "inherited") continue;
            int w = W.find(ws[i].method), m = M.find(ms[size_t(a.map[i])].target);
            if (w < 0 || m < 0 || W.ninst[size_t(w)] < 10 || M.ninst[size_t(m)] < 10) continue;
            ++tot;
            bad += std::fabs(std::log(double(M.ninst[size_t(m)]) / (W.ninst[size_t(w)] * sizeRatio))) > 1.0;
        }
        best = {tot, bad};
    }
    return best;
}

// Choose among candidate reference tables by fit: the best must clear `floor` and lead the next by 3.
bool choose(uint32_t vt, const std::vector<std::pair<uint32_t, int>>& cands, double floor, char how) {
    static const char* dbg = std::getenv("OBNAME_DEBUG");
    bool show = dbg && hexv(dbg) == vt;
    double b = -1e9, s = -1e9;
    std::pair<uint32_t, int> bc{0, -1};
    for (auto& c : cands) {
        if (macUsed.count(c)) continue;
        double f = fit(vt, c.first, c.second);
        if (show) std::fprintf(stderr, "  %x %c candidate %s part %d fit %.1f\n", vt, how, mVt[c.first].cls.c_str(), c.second, f);
        if (f > b) { s = b; b = f; bc = c; } else if (f > s) s = f;
    }
    if (bc.second < 0 || b < floor || b < s + 3) return false;
    if (how == 'h' || how == 'q') {
        auto [tot, bad] = sizeDisagreement(vt, bc.first, bc.second);
        if (bad >= 2 && 2 * bad >= tot) return false;
    }
    addPair(vt, bc.first, bc.second, b, s, how);
    return true;
}

std::vector<int> kset(const Side& s, int i) {
    std::vector<int> k;
    if (i < 0) return k;
    for (int f : s.feats[size_t(i)]) if (featKey[size_t(f)][0] == 'k') k.push_back(f);
    return k;
}

double jaccard(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.empty() || b.empty()) return 0;
    size_t i = 0, j = 0, both = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) { ++both; ++i; ++j; } else if (a[i] < b[j]) ++i; else ++j;
    }
    return double(both) / double(a.size() + b.size() - both);
}

// The IDs that name a class: what its own QueryInterface (slot 0) compares, and the IDs its slots return.
std::set<std::string> idsOf(const Side& s, int fn, bool k, bool r) {
    std::set<std::string> out;
    if (fn < 0) return out;
    for (int f : s.feats[size_t(fn)]) {
        const std::string& key = featKey[size_t(f)];
        if ((k && key[0] == 'k') || (r && key[0] == 'r')) {
            std::string v = key.substr(2);
            uint32_t x = hexv(v);
            if (x >= 0x01e00000u && x < 0xffff0000u) out.insert(v);
        }
    }
    return out;
}
std::set<std::string> classKey(uint32_t vt) {
    std::set<std::string> out;
    const auto& ws = wVt[vt];
    if (!ws.empty() && ws[0].kind != "inherited") {  // folded twins too: a QueryInterface is often shared
        out = idsOf(W, W.find(ws[0].method), true, false);
        if (!out.empty()) return out;
    }
    for (size_t i = 0; i < ws.size(); ++i) {
        if (ws[i].kind == "inherited" || ws[i].target == purecall || ownSlots[ws[i].method] > 1) continue;
        auto s = idsOf(W, W.find(ws[i].method), i == 0, true);
        out.insert(s.begin(), s.end());
    }
    return out;
}
const std::set<std::string>& macKey(uint32_t mac) {
    static std::map<uint32_t, std::set<std::string>> memo;
    auto it = memo.find(mac);
    if (it != memo.end()) return it->second;
    std::set<std::string>& out = memo[mac];
    const auto& p = mVt[mac].parts[0];
    std::string own = mVt[mac].cls + "::";
    if (!p.empty() && p[0].name.rfind(own, 0) == 0) {
        out = idsOf(M, M.find(p[0].target), true, false);
        if (!out.empty()) return out;
    }
    for (size_t i = 0; i < p.size(); ++i) {
        if (p[i].name.rfind(own, 0) != 0) continue;  // inherited: the base's IDs
        auto s = idsOf(M, M.find(p[i].target), i == 0, true);
        out.insert(s.begin(), s.end());
    }
    return out;
}

int pairVtables() {
    size_t before = vtPairs.size();
    // (a) votes of paired slots: primary tables with primary tables (a secondary table's thunks lead to the
    // primary's methods too; secondary tables are paired after their class, below)
    for (auto& [vt, slots] : wVt) {
        if (vtPairs.count(vt) || !wPrimary.count(vt)) continue;
        std::map<std::pair<uint32_t, int>, double> votes;
        for (const WSlot& s : slots) {
            int wi = W.find(s.kind == "thunk" ? s.method : s.target);
            if (wi < 0 || W.partner[wi] < 0 || ownSlots[W.addr[wi]] > 1) continue;
            double v = (s.kind == "own" || s.kind == "deleting-dtor" || s.kind == "thunk") ? 1.0 : 0.25;
            if (W.how[size_t(wi)] == 'G') v *= 0.5;  // call-graph pairs are the least sure
            auto it = mSlotsOf.find(W.partner[wi]);
            if (it == mSlotsOf.end()) continue;
            std::set<std::pair<uint32_t, int>> seen;
            for (auto& mp : it->second) if (seen.insert(mp).second) votes[mp] += v;
        }
        double b = 0, s2 = 0;
        std::pair<uint32_t, int> bc{0, -1};
        for (auto& [k, v] : votes) {
            if (macUsed.count(k)) continue;
            if (k.second != 0) continue;
            if (msvcOrder(mVt[k.first], k.second, false).size() + 2 < slots.size()) continue;
            if (v > b) { s2 = b; b = v; bc = k; } else if (v > s2) s2 = v;
        }
        // one vote: the slot lists must agree too
        if (b >= 1 && b >= 1.5 * s2 && (b >= 2 || fit(vt, bc.first, bc.second) >= 0.5 * double(slots.size())))
            addPair(vt, bc.first, bc.second, b, s2, 'v');
    }
    // (b) the interface IDs their QueryInterface compares and the class IDs their slots return: ours may delegate
    //     to a base's QueryInterface what the reference build inlined, so one set containing the other counts
    //     (siblings that share them: by fit)
    for (uint32_t vt : wPrimary) {
        if (vtPairs.count(vt) || wVt[vt].empty()) continue;
        auto kw = classKey(vt);
        if (kw.empty()) continue;
        std::vector<std::pair<uint32_t, int>> cands;
        double bestO = 0;
        for (auto& [mac, mv] : mVt) {
            if (mv.parts.empty() || mv.parts[0].empty() || macUsed.count({mac, 0})) continue;
            const auto& km = macKey(mac);
            size_t o = 0;
            for (auto& x : kw) o += km.count(x);
            if (!o || (o < kw.size() && o < km.size() && 2 * o < kw.size() + km.size() - o)) continue;
            double j = double(o) / double(kw.size() + km.size() - o);
            if (j > bestO + 1e-9) { bestO = j; cands.clear(); }
            if (j >= bestO - 1e-9) cands.push_back({mac, 0});
        }
        choose(vt, cands, 0.3 * double(wVt[vt].size()), 'q');
    }
    // (c) down the hierarchy: our class's base is paired, so it is one of that table's children
    for (uint32_t vt : wPrimary) {
        if (vtPairs.count(vt) || !wBase0.count(vt)) continue;
        auto bp = vtPairs.find(wBase0[vt]);
        if (bp == vtPairs.end() || bp->second.part != 0) continue;
        std::vector<std::pair<uint32_t, int>> cands;
        // descendants to three levels: the reference build may have a class between, or a sibling that adds
        // methods of the same names may look like a parent
        std::vector<uint32_t> level = {bp->second.mac};
        std::set<uint32_t> seen;
        for (int depth = 0; depth < 3 && !level.empty(); ++depth) {
            std::vector<uint32_t> next;
            for (uint32_t m : level)
                for (uint32_t c : mChildren[m])
                    if (seen.insert(c).second) { cands.push_back({c, 0}); next.push_back(c); }
            level = next;
        }
        if (const char* d = std::getenv("OBNAME_DEBUG"); d && hexv(d) == vt)
            std::fprintf(stderr, "  %x h: base %x is %s, %zu children\n", vt, wBase0[vt], mVt[bp->second.mac].cls.c_str(), cands.size());
        choose(vt, cands, 0.3 * double(wVt[vt].size()), 'h');
    }
    // (d) up the hierarchy: a paired class whose reference table has one direct base
    for (uint32_t vt : wPrimary) {
        auto p = vtPairs.find(vt);
        if (p == vtPairs.end() || p->second.part != 0 || !wBase0.count(vt)) continue;
        uint32_t b = wBase0[vt];
        if (vtPairs.count(b) || mBase[p->second.mac].size() != 1) continue;
        choose(b, {{*mBase[p->second.mac].begin(), 0}}, 0.3 * double(wVt[b].size()), 'u');
    }
    // (e) a paired class's secondary tables, among the reference table's other parts
    for (auto& [prim, secs] : wLayout) {
        auto p = vtPairs.find(prim);
        if (p == vtPairs.end() || p->second.part != 0) continue;
        for (uint32_t s : secs) {
            if (vtPairs.count(s)) continue;
            std::vector<std::pair<uint32_t, int>> cands;
            for (int part = 1; part < int(mVt[p->second.mac].parts.size()); ++part) 
                if (msvcOrder(mVt[p->second.mac], part, false).size() == wVt[s].size()) cands.push_back({p->second.mac, part});
            choose(s, cands, 0, '2');
        }
    }
    return int(vtPairs.size() - before);
}

int nameSlots() {
    int added = 0;
    for (auto& [vt, p] : vtPairs) {
        const auto& ws = wVt[vt];
        const MVt& mv = mVt[p.mac];
        std::vector<MSlot> best;
        Align ba;
        for (bool g : {false, true}) {
            auto ms = msvcOrder(mv, p.part, g);
            Align a = align(ws, ms);
            if (a.score > ba.score) { ba = a; best = ms; }
        }
        for (size_t i = 0; i < ws.size(); ++i) {
            int j = ba.map[i];
            if (j < 0 || best[size_t(j)].name == "?") continue;
            const WSlot& w = ws[i];
            if (w.target == purecall) continue;
            uint32_t fn = w.kind == "thunk" ? w.method : w.target;
            int wi = W.find(fn), mi = M.find(best[size_t(j)].target);
            bool anchored = wi >= 0 && mi >= 0 && W.partner[wi] == mi;
            int b = argBytes(best[j].name);
            bool popsOk = w.kind == "deleting-dtor" || (w.pops >= 0 && b >= 0 && b == w.pops);
            char how = (anchored || popsOk) ? 'S' : 's';
            std::string name = best[j].name;
            if (w.kind == "deleting-dtor") name = name.substr(0, name.find('(')) + "`deleting'";
            slotNames[{vt, int(i)}] = {name, how};
            slotMac[{vt, int(i)}] = best[size_t(j)].target;
            if (w.kind == "inherited") continue;
            if (how == 'S' && ownSlots[fn] == 1 && wi >= 0 && mi >= 0 && W.partner[wi] < 0 && M.partner[mi] < 0 &&
                w.kind != "deleting-dtor") {
                pair(wi, mi, 'S');
                ++added;
            }
        }
    }
    return added;
}

void buildHierarchy() {
    std::map<uint32_t, std::vector<std::string>> lists;
    for (auto& [mac, mv] : mVt) {
        if (mv.parts.empty()) continue;
        for (const MSlot& s : mv.parts[0]) lists[mac].push_back(s.name == "?" ? "?" : isDtor(s.name) ? "~" : methodOf(s.name));
    }
    for (auto& [x, lx] : lists) {
        size_t bestLen = 0;
        std::set<uint32_t> best;
        for (auto& [y, ly] : lists) {
            if (y == x || ly.size() >= lx.size() || ly.size() < 3 || ly.size() < bestLen) continue;
            if (!std::equal(ly.begin(), ly.end(), lx.begin(),
                            [](const std::string& a, const std::string& b) { return a == b || a == "?" || b == "?"; }))
                continue;
            if (ly.size() > bestLen) { bestLen = ly.size(); best.clear(); }
            best.insert(y);
        }
        mBase[x] = best;
        for (uint32_t b : best) mChildren[b].push_back(x);
    }
}

}  // namespace

int main(int argc, char** argv) {
    std::map<std::string, std::string> opt;
    for (int i = 1; i + 1 < argc; i += 2) opt[argv[i]] = argv[i + 1];
    for (const char* k : {"--win-feat", "--win-slots", "--win-shapes", "--win-classes", "--mac-feat", "--mac-funcs",
                          "--mac-vtables", "--out"})
        if (!opt.count(k)) { std::fprintf(stderr, "missing %s (see the header of tools/obcmp/obname.cpp)\n", k); return 2; }
    readFeat(opt["--win-feat"], W);
    readFeat(opt["--mac-feat"], M);
    std::string line;
    {
        std::ifstream f(opt["--mac-funcs"]);
        while (std::getline(f, line)) { auto p = split(line); if (p.size() >= 3) M.name[M.get(hexv(p[0]))] = p[2]; }
    }
    std::map<uint32_t, int> pops;
    {
        std::ifstream f(opt["--win-shapes"]);
        while (std::getline(f, line)) {
            auto p = split(line);
            if (p.size() >= 3) pops[hexv(p[0])] = (p[2] == "?" || p[2] == "x") ? -1 : std::atoi(p[2].c_str());
        }
    }
    {
        std::ifstream f(opt["--win-slots"]);
        while (std::getline(f, line)) {
            auto p = split(line);
            if (p.size() < 4) continue;
            WSlot s;
            s.target = hexv(p[2]);
            s.kind = p[3];
            s.method = s.target;
            if (s.kind == "thunk" && p.size() >= 5) s.method = hexv(split(p[4], ',')[0]);
            auto it = pops.find(s.method);
            s.pops = it == pops.end() ? -1 : it->second;
            wVt[hexv(p[0])].push_back(s);
            W.get(s.method);
            if (s.kind != "inherited" && s.target != purecall) ++ownSlots[s.method];
        }
    }
    {
        std::ifstream f(opt["--win-classes"]);
        while (std::getline(f, line)) {
            auto p = split(line);
            if (p.size() < 4) continue;
            uint32_t prim = hexv(p[0]);
            wPrimary.insert(prim);
            for (auto& l : split(p[2], ',')) {
                auto q = split(l, ':');
                if (q.size() == 2 && q[0] != "0") wLayout[prim].push_back(hexv(q[1]));
            }
            for (auto& b : split(p[3], ',')) {
                auto q = split(b, ':');
                if (q.size() == 2 && q[0] == "0") wBase0[prim] = hexv(q[1]);
            }
        }
    }
    {
        std::ifstream f(opt["--mac-vtables"]);
        while (std::getline(f, line)) {
            auto p = split(line);
            if (p.size() < 7) continue;
            uint32_t vt = hexv(p[0]);
            MVt& v = mVt[vt];
            v.cls = p[1];
            size_t part = std::atoi(p[2].c_str());
            if (v.parts.size() <= part) v.parts.resize(part + 1);
            MSlot s{hexv(p[5]), p[6]};
            if (s.name == "?") { v.parts[part].push_back(s); continue; }  // a slot the reference data lost
            v.parts[part].push_back(s);
            int mi = M.get(s.target);
            if (M.name[mi].empty()) M.name[mi] = s.name;
            mSlotsOf[mi].push_back({vt, int(part)});
        }
    }
    buildHierarchy();
    wPops.assign(W.addr.size(), -1);
    for (size_t w = 0; w < W.addr.size(); ++w) { auto it = pops.find(W.addr[w]); if (it != pops.end()) wPops[w] = it->second; }
    int f = stageFeatures();
    {
        std::vector<double> r;
        for (size_t w = 0; w < W.partner.size(); ++w) {
            int m = W.partner[w];
            if (m >= 0 && W.ninst[w] >= 10 && M.ninst[size_t(m)] >= 10) r.push_back(double(M.ninst[size_t(m)]) / W.ninst[w]);
        }
        if (!r.empty()) { std::nth_element(r.begin(), r.begin() + long(r.size() / 2), r.end()); sizeRatio = r[r.size() / 2]; }
        std::fprintf(stderr, "size ratio (reference / ours, median of %zu pairs): %.2f\n", r.size(), sizeRatio);
    }
    std::fprintf(stderr, "stage 1 features: %d pairs\n", f);
    for (int round = 1; round <= 12; ++round) {
        int g = stageGraph();
        int v = pairVtables();
        int s = nameSlots();
        std::fprintf(stderr, "round %d: %d by call graph, %d vtables paired (+%d), %d pairs from slots\n", round, g,
                     int(vtPairs.size()), v, s);
        if (!g && !s && !v) break;
    }

    // ---- output ---------------------------------------------------------------------------------------------------
    std::string out = opt["--out"];
    // A function's name: its pair's, else the name its own slots agree on. Folded twins (one body in the slots of
    // several methods) get no single name; their slots keep theirs.
    std::map<uint32_t, std::pair<std::string, char>> names;
    std::map<uint32_t, uint32_t> namedAfter;  // our function → the reference function its name comes from
    std::map<uint32_t, std::set<std::string>> slotSays;
    for (auto& [k, n] : slotNames) {
        const WSlot& s = wVt[k.first][size_t(k.second)];
        if (s.kind == "inherited") continue;
        slotSays[s.kind == "thunk" ? s.method : s.target].insert(n.first);
    }
    int folded = 0;
    for (auto& [k, n] : slotNames) {
        const WSlot& s = wVt[k.first][size_t(k.second)];
        if (s.kind == "inherited") continue;
        uint32_t fn = s.kind == "thunk" ? s.method : s.target;
        if (slotSays[fn].size() != 1 || ownSlots[fn] != 1) continue;
        auto it = names.find(fn);
        if (it == names.end() || (it->second.second == 's' && n.second == 'S')) { names[fn] = n; namedAfter[fn] = slotMac[k]; }
    }
    for (auto& [fn, says] : slotSays) folded += says.size() > 1 || ownSlots[fn] > 1;
    for (size_t w = 0; w < W.partner.size(); ++w) {
        int m = W.partner[w];
        if (m < 0 || M.name[m].empty() || ownSlots[W.addr[w]] > 1) continue;
        auto it = names.find(W.addr[w]);
        if (it == names.end() || it->second.second == 's') { names[W.addr[w]] = {M.name[m], W.how[w]}; namedAfter[W.addr[w]] = M.addr[size_t(m)]; }
    }
    {
        std::ofstream o(out + "/functions.tsv");
        for (auto& [a, n] : names) {
            char b[16];
            std::snprintf(b, sizeof b, "%08x", namedAfter.count(a) ? namedAfter[a] : 0);
            o << std::hex << a << std::dec << '\t' << n.first << '\t' << n.second << '\t' << b << '\n';
        }
    }
    {
        std::ofstream o(out + "/slots.tsv");
        for (auto& [k, n] : slotNames)
            o << std::hex << k.first << std::dec << '\t' << k.second << '\t' << n.first << '\t' << n.second << '\n';
    }
    {
        std::ofstream o(out + "/vtables.tsv");
        std::ofstream c(out + "/classes.tsv");
        for (auto& [vt, p] : vtPairs) {
            o << std::hex << vt << std::dec << '\t' << mVt[p.mac].cls << '\t' << p.part << '\t' << p.votes << '\t' << p.how << '\n';
            if (p.part == 0 && wPrimary.count(vt)) {
                int named = 0;
                for (size_t i = 0; i < wVt[vt].size(); ++i) named += slotNames.count({vt, int(i)});
                c << std::hex << vt << std::dec << '\t' << mVt[p.mac].cls << '\t' << p.votes << '\t' << p.second << '\t'
                  << wVt[vt].size() << '\t' << named << '\n';
            }
        }
    }
    std::map<char, int> byHow;
    for (auto& [a, n] : names) ++byHow[n.second];
    std::fprintf(stderr, "named %zu functions:", names.size());
    for (auto [h, n] : byHow) std::fprintf(stderr, " %c=%d", h, n);
    std::fprintf(stderr, "; %zu slots named; %d folded twins left unnamed; %zu vtables paired\n", slotNames.size(),
                 folded, vtPairs.size());

    // ---- truth -----------------------------------------------------------------------------------------------------
    auto bare = [](std::string s) {
        s = s.substr(0, s.find('('));
        while (!s.empty() && s[0] == '_') s.erase(s.begin());
        return s;
    };
    if (opt.count("--truth-lib")) {
        std::ifstream f(opt["--truth-lib"]);
        std::map<char, std::pair<int, int>> r;  // how → (right, wrong)
        int total = 0;
        std::vector<std::string> wrong;
        while (std::getline(f, line)) {
            auto p = split(line);
            if (p.size() < 3 || p[1] != "lua") continue;
            ++total;
            auto it = names.find(hexv(p[0]));
            if (it == names.end()) continue;
            bool ok = bare(it->second.first) == bare(p[2]);
            (ok ? r[it->second.second].first : r[it->second.second].second)++;
            if (!ok && wrong.size() < 8) wrong.push_back(p[0] + " " + p[2] + " named " + it->second.first);
        }
        std::fprintf(stderr, "truth (Lua, %d functions):", total);
        for (auto [h, rw] : r) std::fprintf(stderr, " %c %d right %d wrong;", h, rw.first, rw.second);
        std::fprintf(stderr, "\n");
        for (auto& s : wrong) std::fprintf(stderr, "  wrong: %s\n", s.c_str());
    }
    if (opt.count("--truth-known")) {
        std::ifstream f(opt["--truth-known"]);
        int right = 0, wrongN = 0, unnamed = 0;
        std::vector<std::string> wrong;
        while (std::getline(f, line)) {
            auto p = split(line);
            if (p.size() < 4) continue;
            uint32_t vt = hexv(p[0]);
            size_t idx = std::atoi(p[1].c_str());
            auto& ws = wVt[vt];
            if (idx >= ws.size()) continue;
            if (ws[idx].target == purecall) continue;
            auto it = slotNames.find({vt, int(idx)});
            // "public: virtual bool __thiscall cRZString::QueryInterface(unsigned int, void **)"
            std::string d = p[3];
            size_t cc = d.find("__thiscall ");
            std::string q = cc == std::string::npos ? d : d.substr(cc + 11);
            std::string want = methodOf(q);
            if (it == slotNames.end()) { ++unnamed; continue; }
            std::string got = methodOf(it->second.first);
            if (want.find("deleting") != std::string::npos || got.find("deleting") != std::string::npos) {
                bool ok = got.find("deleting") != std::string::npos && want.find("deleting") != std::string::npos;
                (ok ? right : wrongN)++;
                continue;
            }
            if (got == want) ++right;
            else { ++wrongN; if (wrong.size() < 10) wrong.push_back(p[0] + "[" + p[1] + "] " + want + " named " + it->second.first); }
        }
        std::fprintf(stderr, "truth (hand-declared slots): %d right, %d wrong, %d unnamed\n", right, wrongN, unnamed);
        for (auto& s : wrong) std::fprintf(stderr, "  wrong: %s\n", s.c_str());
    }
    return 0;
}
