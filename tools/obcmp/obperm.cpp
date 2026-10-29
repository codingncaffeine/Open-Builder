// obperm — searches spellings of one decompiled function until the 2003 compiler turns it into the original's
// instructions (a permuter): the statements of its body are rewritten at random in ways that keep C++ valid (swaps of
// neighbouring statements, inverted ifs, else after a return or not, loop forms, compare operand order, null tests,
// increment forms, split or joined declarations, return c ? a : b), each candidate compiled with the folder's flags and
// scored against the original, the best kept.
//
//   obperm <original.exe> <functions.tsv> <file.cpp> <address> [--tries N] [--jobs N] [--seed N] [--seconds N]
//          [--flags "..."] [--work DIR] [--out FILE] [--quiet] [--obj FILE]
// --obj scores an object already compiled from file.cpp (tools/score.sh) and searches nothing.
//
// The function is the definition right after "// FUNCTION: 0x<address>" in file.cpp; the rest of the file is compiled
// as it is, from the project root (run it there), with build.sh's options and the flags of the nearest FLAGS file
// above the file (or --flags). Score = tokens in a diff of the two listings (0 = identical), both read by the
// tokenizer obcmp uses (pe.h): mnemonics and operands, jump targets inside the function as "L<instruction index>",
// switch tables as "table T<place>" and their entries, addresses outside the function as "addr". Calls are compared by
// being calls; when the instructions are identical, each address outside the function (a callee, a global) must be
// the original's where we know what ours stands for (the stub lists, the file's STUB and GLOBAL lines, Fn<address>
// names), else it scores and work/j0/targets.txt says which.
// The best spelling is written to --out (default <work>/best.cpp, the whole file with the body replaced); comments
// inside the body are not kept. Exit 0 when a candidate scores 0, 1 otherwise, 2 on bad input.

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "pe.h"

namespace fs = std::filesystem;

namespace {

// ---- tokens ------------------------------------------------------------------------------------------------------

std::vector<std::string> tokenize(const std::string& s, bool& preprocessor) {
    static const char* multi[] = {">>=", "<<=", "->*", "...", "::", "->", "++", "--", "<<", ">>", "<=", ">=", "==",
                                  "!=", "&&", "||", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", ".*"};
    std::vector<std::string> out;
    preprocessor = false;
    size_t i = 0, n = s.size();
    bool lineStart = true;
    while (i < n) {
        char c = s[i];
        if (c == '\n') { lineStart = true; ++i; continue; }
        if (std::isspace(static_cast<unsigned char>(c))) { ++i; continue; }
        if (c == '#' && lineStart) preprocessor = true;
        lineStart = false;
        if (c == '/' && i + 1 < n && s[i + 1] == '/') { while (i < n && s[i] != '\n') ++i; continue; }
        if (c == '/' && i + 1 < n && s[i + 1] == '*') {
            size_t e = s.find("*/", i + 2);
            i = e == std::string::npos ? n : e + 2;
            continue;
        }
        if (c == '"' || c == '\'') {
            size_t j = i + 1;
            while (j < n && s[j] != c) j += s[j] == '\\' ? 2 : 1;
            out.push_back(s.substr(i, j + 1 - i));
            i = j + 1;
            continue;
        }
        if (std::isalnum(static_cast<unsigned char>(c)) || c == '_') {
            size_t j = i;
            bool num = std::isdigit(static_cast<unsigned char>(c));
            while (j < n && (std::isalnum(static_cast<unsigned char>(s[j])) || s[j] == '_' ||
                             (num && (s[j] == '.' || ((s[j] == '+' || s[j] == '-') && (s[j - 1] == 'e' || s[j - 1] == 'E'))))))
                ++j;
            out.push_back(s.substr(i, j - i));
            i = j;
            continue;
        }
        std::string op(1, c);
        for (const char* m : multi)
            if (s.compare(i, std::strlen(m), m) == 0) { op = m; break; }
        out.push_back(op);
        i += op.size();
    }
    return out;
}

using Toks = std::vector<std::string>;

bool operand(const std::string& p) {  // ends an operand: a name, a number, a literal, a closing bracket
    return std::isalnum(static_cast<unsigned char>(p[0])) || p[0] == '_' || p[0] == '"' || p[0] == '\'' || p == ")" ||
           p == "]";
}

bool typeName(const std::string& p) {  // a built-in or fixed-size type, or a class named the house way (cFoo, cIGZFoo)
    static const std::set<std::string> builtin = {"char", "int", "void", "bool", "unsigned", "signed", "short", "long",
                                                  "float", "double", "size_t", "wchar_t", "const"};
    return builtin.count(p) || (p.size() > 2 && p.back() == 't' && p[p.size() - 2] == '_') ||
           (p.size() > 1 && p[0] == 'c' && std::isupper(static_cast<unsigned char>(p[1])));
}

std::string join(const Toks& t) {
    static const std::set<std::string> unary = {"*", "&", "-", "+", "!", "~", "++", "--"};
    static const std::set<std::string> keywords = {"return", "case", "throw", "delete", "new", "sizeof"};
    std::string out;
    for (size_t i = 0; i < t.size(); ++i) {
        const std::string& a = t[i];
        if (i) {
            const std::string& p = t[i - 1];
            // p is a prefix operator when nothing that ends an operand comes before it
            bool prefix = unary.count(p) && (i < 2 || !operand(t[i - 2]) || keywords.count(t[i - 2])) &&
                          !((p == "*" || p == "&") && i >= 2 && typeName(t[i - 2]));
            bool pointer = (a == "*" || a == "&") && typeName(p);  // "char* p"
            bool tight = a == "," || a == ";" || a == ")" || a == "]" || a == "." || a == "->" || a == "::" ||
                         p == "(" || p == "[" || p == "." || p == "->" || p == "::" || prefix || pointer ||
                         (a == "(" && (operand(p) && !keywords.count(p) && p != "if" && p != "while" && p != "for" &&
                                       p != "switch")) ||
                         (a == "[" && operand(p)) || ((a == "++" || a == "--") && operand(p) && !keywords.count(p));
            if (!tight) out += ' ';
        }
        out += a;
    }
    return out;
}

// ---- statements --------------------------------------------------------------------------------------------------

struct Node {
    enum Kind { Block, Simple, If, For, While, Do, Switch, Label } kind = Simple;
    Toks a, b, c;            // Simple, Label: its tokens; If/While/Do/Switch: condition; For: init, cond, increment
    std::vector<Node> kids;  // Block: statements; If: then [, else]; For/While/Do/Switch: body
};

struct Parser {
    const Toks& t;
    size_t p = 0;
    bool ok = true;
    explicit Parser(const Toks& toks) : t(toks) {}
    const std::string& peek(size_t k = 0) const {
        static const std::string none;
        return p + k < t.size() ? t[p + k] : none;
    }
    bool eat(const std::string& s) {
        if (peek() != s) { ok = false; return false; }
        ++p;
        return true;
    }
    Toks paren() {  // "( ... )" -> inside
        Toks in;
        if (!eat("(")) return in;
        int d = 1;
        while (p < t.size()) {
            if (t[p] == "(") ++d;
            if (t[p] == ")" && --d == 0) { ++p; return in; }
            in.push_back(t[p++]);
        }
        ok = false;
        return in;
    }
    Node block() {
        Node b;
        b.kind = Node::Block;
        eat("{");
        while (ok && p < t.size() && peek() != "}") b.kids.push_back(stmt());
        eat("}");
        return b;
    }
    Node stmt() {
        Node n;
        const std::string& w = peek();
        if (w == "{") return block();
        if (w == "if") {
            ++p;
            n.kind = Node::If;
            n.a = paren();
            n.kids.push_back(stmt());
            if (peek() == "else") { ++p; n.kids.push_back(stmt()); }
            return n;
        }
        if (w == "for") {
            ++p;
            n.kind = Node::For;
            Toks in = paren();
            int part = 0, d = 0;
            for (auto& x : in) {
                if (x == "(" || x == "[" || x == "{") ++d;
                if (x == ")" || x == "]" || x == "}") --d;
                if (x == ";" && d == 0) { ++part; continue; }
                (part == 0 ? n.a : part == 1 ? n.b : n.c).push_back(x);
            }
            if (part != 2) ok = false;
            n.kids.push_back(stmt());
            return n;
        }
        if (w == "while" || w == "switch") {
            ++p;
            n.kind = w == "while" ? Node::While : Node::Switch;
            n.a = paren();
            n.kids.push_back(stmt());
            return n;
        }
        if (w == "do") {
            ++p;
            n.kind = Node::Do;
            n.kids.push_back(stmt());
            eat("while");
            n.a = paren();
            eat(";");
            return n;
        }
        if (w == "case" || (w == "default" && peek(1) == ":") ||
            (peek(1) == ":" && (std::isalpha(static_cast<unsigned char>(w[0])) || w[0] == '_'))) {
            n.kind = Node::Label;
            while (p < t.size() && t[p] != ":") n.a.push_back(t[p++]);
            n.a.push_back(":");
            eat(":");
            return n;
        }
        n.kind = Node::Simple;
        int d = 0;
        while (p < t.size()) {
            const std::string& x = t[p++];
            n.a.push_back(x);
            if (x == "(" || x == "[" || x == "{") ++d;
            if (x == ")" || x == "]" || x == "}") --d;
            if (x == ";" && d == 0) return n;
        }
        ok = false;
        return n;
    }
};

// House style: a control statement's block opens on its line ("if (c) {", "} else {"), every body in braces.
void print(const Node& n, int ind, std::string& out) {
    std::string pad(size_t(ind) * 4, ' ');
    auto body = [&](const Node& k) {  // " {\n...pad}" without the newline after it
        out += " {\n";
        if (k.kind == Node::Block) for (auto& c : k.kids) print(c, ind + 1, out);
        else print(k, ind + 1, out);
        out += pad + "}";
    };
    switch (n.kind) {
    case Node::Block:
        out += pad + "{\n";
        for (auto& c : n.kids) print(c, ind + 1, out);
        out += pad + "}\n";
        return;
    case Node::Simple: out += pad + join(n.a) + "\n"; return;
    case Node::Label: out += std::string(size_t(std::max(0, ind - 1)) * 4, ' ') + join(n.a) + "\n"; return;
    case Node::If: {
        out += pad + "if (" + join(n.a) + ")";
        body(n.kids[0]);
        const Node* e = n.kids.size() > 1 ? &n.kids[1] : nullptr;
        while (e && e->kind == Node::If) {  // else if chains stay flat
            out += " else if (" + join(e->a) + ")";
            body(e->kids[0]);
            e = e->kids.size() > 1 ? &e->kids[1] : nullptr;
        }
        if (e) { out += " else"; body(*e); }
        out += "\n";
        return;
    }
    case Node::For:
        out += pad + "for (" + join(n.a) + ";" + (n.b.empty() ? "" : " " + join(n.b)) + ";" + (n.c.empty() ? "" : " " + join(n.c)) + ")";
        body(n.kids[0]);
        out += "\n";
        return;
    case Node::While:
    case Node::Switch:
        out += pad + (n.kind == Node::While ? "while (" : "switch (") + join(n.a) + ")";
        body(n.kids[0]);
        out += "\n";
        return;
    case Node::Do:
        out += pad + "do";
        body(n.kids[0]);
        out += " while (" + join(n.a) + ");\n";
        return;
    }
}

// ---- expression helpers ------------------------------------------------------------------------------------------

// The index of the single top-level binary operator among ops (outside parentheses and ?:), or -1.
int topLevel(const Toks& e, const std::set<std::string>& ops, bool requireSingle = true) {
    int d = 0, found = -1, count = 0;
    for (size_t i = 0; i < e.size(); ++i) {
        const std::string& x = e[i];
        if (x == "(" || x == "[") ++d;
        else if (x == ")" || x == "]") --d;
        else if (d == 0 && (x == "?" || x == "=" || x == "&&" || x == "||" || x == ",")) {
            if (!ops.count(x)) return -1;
        }
        if (d == 0 && ops.count(x) && i > 0) { found = int(i); ++count; }
    }
    if (requireSingle && count != 1) return -1;
    return found;
}

bool simpleOperand(const Toks& e) {  // no operator weaker than a unary/postfix one at top level
    int d = 0;
    static const std::set<std::string> weak = {"==", "!=", "<", ">", "<=", ">=", "&&", "||", "?", ":", "=", "+", "-",
                                               "*", "/", "%", "&", "|", "^", "<<", ">>", ",", "+=", "-="};
    for (size_t i = 0; i < e.size(); ++i) {
        if (e[i] == "(" || e[i] == "[") ++d;
        else if (e[i] == ")" || e[i] == "]") --d;
        else if (d == 0 && i > 0 && weak.count(e[i])) return false;
    }
    return !e.empty();
}

Toks paren(const Toks& e) {
    if (simpleOperand(e)) return e;
    Toks r{"("};
    r.insert(r.end(), e.begin(), e.end());
    r.push_back(")");
    return r;
}

Toks negate(const Toks& c) {
    static const std::map<std::string, std::string> inv = {{"==", "!="}, {"!=", "=="}, {"<", ">="}, {">=", "<"},
                                                           {">", "<="}, {"<=", ">"}};
    std::set<std::string> rel;
    for (auto& [k, v] : inv) rel.insert(k);
    int i = topLevel(c, rel);
    if (i > 0) {
        Toks r = c;
        r[size_t(i)] = inv.at(c[size_t(i)]);
        return r;
    }
    if (!c.empty() && c[0] == "!" && simpleOperand(Toks(c.begin() + 1, c.end()))) {
        Toks r(c.begin() + 1, c.end());
        if (r.size() > 2 && r.front() == "(" && r.back() == ")") return Toks(r.begin() + 1, r.end() - 1);
        return r;
    }
    Toks r{"!"};
    Toks p = paren(c);
    r.insert(r.end(), p.begin(), p.end());
    return r;
}

bool endsInJump(const Node& n) {
    const Node* last = &n;
    while (last->kind == Node::Block && !last->kids.empty()) last = &last->kids.back();
    return last->kind == Node::Simple && !last->a.empty() &&
           (last->a[0] == "return" || last->a[0] == "break" || last->a[0] == "continue" || last->a[0] == "goto");
}

bool isTypeStart(const std::string& w) {
    static const std::set<std::string> kw = {"return", "break", "continue", "goto", "delete", "throw", "new", "this",
                                             "sizeof", "operator", "else", "case", "default"};
    return (std::isalpha(static_cast<unsigned char>(w[0])) || w[0] == '_') && !kw.count(w);
}

// "T x = e;" -> type tokens, name, initializer (without ';'); false when not a declaration with an initializer.
bool declaration(const Toks& a, Toks& type, std::string& name, Toks& init) {
    int eq = -1, d = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == "(" || a[i] == "[") ++d;
        if (a[i] == ")" || a[i] == "]") --d;
        if (d == 0 && a[i] == "=") { eq = int(i); break; }
        if (d == 0 && (a[i] == "(" || a[i] == ",")) return false;
    }
    if (eq < 2 || !isTypeStart(a[0])) return false;
    name = a[size_t(eq) - 1];
    if (!(std::isalpha(static_cast<unsigned char>(name[0])) || name[0] == '_')) return false;
    type.assign(a.begin(), a.begin() + eq - 1);
    for (auto& x : type)
        if (x == "." || x == "->" || x == "=" || x == "(") return false;
    init.assign(a.begin() + eq + 1, a.end() - 1);
    return !init.empty();
}

// ---- mutations ---------------------------------------------------------------------------------------------------

void collect(Node& n, std::vector<Node*>& all) {
    all.push_back(&n);
    for (auto& k : n.kids) collect(k, all);
}

using Rng = std::mt19937;

bool mutate(Node& root, Rng& rng) {
    std::vector<Node*> all;
    collect(root, all);
    std::vector<Node*> blocks, conds, ifs;
    for (Node* n : all) {
        if (n->kind == Node::Block && n->kids.size() >= 1) blocks.push_back(n);
        if ((n->kind == Node::If || n->kind == Node::While || n->kind == Node::Do || n->kind == Node::For) &&
            !(n->kind == Node::For ? n->b : n->a).empty())
            conds.push_back(n);
        if (n->kind == Node::If) ifs.push_back(n);
    }
    auto pick = [&](auto& v) { return v[std::uniform_int_distribution<size_t>(0, v.size() - 1)(rng)]; };
    auto condOf = [](Node* n) -> Toks& { return n->kind == Node::For ? n->b : n->a; };
    int kind = std::uniform_int_distribution<int>(0, 11)(rng);
    switch (kind) {
    case 0:
    case 1: {  // swap two neighbouring statements
        if (blocks.empty()) return false;
        Node* b = pick(blocks);
        if (b->kids.size() < 2) return false;
        size_t i = std::uniform_int_distribution<size_t>(0, b->kids.size() - 2)(rng);
        if (b->kids[i].kind == Node::Label || b->kids[i + 1].kind == Node::Label) return false;
        std::swap(b->kids[i], b->kids[i + 1]);
        return true;
    }
    case 2: {  // if (c) A else B -> if (!c) B else A
        std::vector<Node*> v;
        for (Node* n : ifs)
            if (n->kids.size() == 2) v.push_back(n);
        if (v.empty()) return false;
        Node* n = pick(v);
        n->a = negate(n->a);
        std::swap(n->kids[0], n->kids[1]);
        if (n->kids[0].kind == Node::If) {  // keep "else if" readable: the moved if gets braces
            Node b;
            b.kind = Node::Block;
            b.kids.push_back(n->kids[0]);
            n->kids[0] = b;
        }
        return true;
    }
    case 3: {  // else after a branch that jumps: drop it, or wrap what follows in one
        if (blocks.empty()) return false;
        Node* b = pick(blocks);
        for (size_t i = 0; i < b->kids.size(); ++i) {
            Node& n = b->kids[i];
            if (n.kind != Node::If || !endsInJump(n.kids[0])) continue;
            if (n.kids.size() == 2) {
                Node e = n.kids[1];
                n.kids.pop_back();
                std::vector<Node> rest = e.kind == Node::Block ? e.kids : std::vector<Node>{e};
                b->kids.insert(b->kids.begin() + long(i) + 1, rest.begin(), rest.end());
                return true;
            }
            if (i + 1 < b->kids.size()) {
                Node e;
                e.kind = Node::Block;
                e.kids.assign(b->kids.begin() + long(i) + 1, b->kids.end());
                b->kids.erase(b->kids.begin() + long(i) + 1, b->kids.end());
                b->kids[i].kids.push_back(e);
                return true;
            }
        }
        return false;
    }
    case 4: {  // a < b -> b > a
        if (conds.empty()) return false;
        static const std::map<std::string, std::string> mirror = {{"==", "=="}, {"!=", "!="}, {"<", ">"}, {">", "<"},
                                                                  {"<=", ">="}, {">=", "<="}};
        std::set<std::string> rel;
        for (auto& [k, v] : mirror) rel.insert(k);
        Toks& c = condOf(pick(conds));
        int i = topLevel(c, rel);
        if (i <= 0) return false;
        Toks l(c.begin(), c.begin() + i), r(c.begin() + i + 1, c.end());
        Toks out = r;
        out.push_back(mirror.at(c[size_t(i)]));
        out.insert(out.end(), l.begin(), l.end());
        c = out;
        return true;
    }
    case 5: {  // x <-> x != 0, !x <-> x == 0
        if (conds.empty()) return false;
        Toks& c = condOf(pick(conds));
        size_t n = c.size();
        if (n >= 3 && c[n - 1] == "0" && (c[n - 2] == "!=" || c[n - 2] == "==") && topLevel(c, {"!=", "=="}) == int(n - 2)) {
            Toks l(c.begin(), c.end() - 2);
            if (c[n - 2] == "!=") c = l;
            else { c = {"!"}; Toks p = paren(l); c.insert(c.end(), p.begin(), p.end()); }
            return true;
        }
        if (simpleOperand(c)) {
            if (c[0] == "!") { Toks l(c.begin() + 1, c.end()); c = l; c.push_back("=="); c.push_back("0"); }
            else { c.push_back("!="); c.push_back("0"); }
            return true;
        }
        return false;
    }
    case 6: {  // x++; <-> ++x; <-> x += 1;
        std::vector<Node*> v;
        for (Node* n : all)
            if (n->kind == Node::Simple && (std::find(n->a.begin(), n->a.end(), "++") != n->a.end() ||
                                            std::find(n->a.begin(), n->a.end(), "--") != n->a.end() ||
                                            (n->a.size() >= 4 && (n->a[n->a.size() - 3] == "+=" || n->a[n->a.size() - 3] == "-=") &&
                                             n->a[n->a.size() - 2] == "1")))
                v.push_back(n);
        for (Node* n : all)
            if (n->kind == Node::For && !n->c.empty()) v.push_back(n);
        if (v.empty()) return false;
        Node* n = pick(v);
        Toks& s = n->kind == Node::For ? n->c : n->a;
        bool semi = n->kind != Node::For;
        Toks body(s.begin(), s.end() - (semi ? 1 : 0));
        std::string op;
        Toks x;
        if (body.size() >= 2 && (body.back() == "++" || body.back() == "--")) { op = body.back(); x.assign(body.begin(), body.end() - 1); }
        else if (body.size() >= 2 && (body.front() == "++" || body.front() == "--")) { op = body.front(); x.assign(body.begin() + 1, body.end()); }
        else if (body.size() >= 3 && (body[body.size() - 2] == "+=" || body[body.size() - 2] == "-=") && body.back() == "1") {
            op = body[body.size() - 2] == "+=" ? "++" : "--";
            x.assign(body.begin(), body.end() - 2);
        } else return false;
        if (!simpleOperand(x)) return false;
        int form = std::uniform_int_distribution<int>(0, 2)(rng);
        Toks out;
        if (form == 0) { out = x; out.push_back(op); }
        else if (form == 1) { out = {op}; out.insert(out.end(), x.begin(), x.end()); }
        else { out = x; out.push_back(op == "++" ? "+=" : "-="); out.push_back("1"); }
        if (semi) out.push_back(";");
        if (out == s) return false;
        s = out;
        return true;
    }
    case 7: {  // T x = e; <-> T x; x = e;
        if (blocks.empty()) return false;
        Node* b = pick(blocks);
        for (size_t i = 0; i < b->kids.size(); ++i) {
            Node& n = b->kids[i];
            if (n.kind != Node::Simple) continue;
            Toks type, init;
            std::string name;
            if (declaration(n.a, type, name, init) && std::uniform_int_distribution<int>(0, 1)(rng)) {
                Node d = n, s = n;
                d.a = type;
                d.a.push_back(name);
                d.a.push_back(";");
                s.a = {name, "="};
                s.a.insert(s.a.end(), init.begin(), init.end());
                s.a.push_back(";");
                b->kids[i] = d;
                b->kids.insert(b->kids.begin() + long(i) + 1, s);
                return true;
            }
            // T x; then x = e;  (the assignment anywhere later in the block)
            if (n.a.size() >= 3 && n.a.back() == ";" && isTypeStart(n.a[0]) &&
                std::find(n.a.begin(), n.a.end(), "=") == n.a.end() && std::find(n.a.begin(), n.a.end(), "(") == n.a.end()) {
                const std::string& nm = n.a[n.a.size() - 2];
                for (size_t j = i + 1; j < b->kids.size(); ++j) {
                    Node& s = b->kids[j];
                    if (s.kind == Node::Simple && s.a.size() >= 4 && s.a[0] == nm && s.a[1] == "=") {
                        Node d = n;
                        d.a.pop_back();
                        d.a.insert(d.a.end(), s.a.begin() + 1, s.a.end());
                        b->kids.erase(b->kids.begin() + long(j));
                        b->kids[i] = d;
                        if (j > i + 1) std::rotate(b->kids.begin() + long(i), b->kids.begin() + long(i) + 1, b->kids.begin() + long(j));
                        return true;
                    }
                }
            }
        }
        return false;
    }
    case 8: {  // a && b -> b && a
        if (conds.empty()) return false;
        Toks& c = condOf(pick(conds));
        int i = topLevel(c, {"&&"}, false);
        if (i <= 0) i = topLevel(c, {"||"}, false);
        if (i <= 0 || (topLevel(c, {"&&"}) < 0 && topLevel(c, {"||"}) < 0)) return false;
        Toks l(c.begin(), c.begin() + i), r(c.begin() + i + 1, c.end());
        Toks out = r;
        out.push_back(c[size_t(i)]);
        out.insert(out.end(), l.begin(), l.end());
        c = out;
        return true;
    }
    case 9: {  // if (c) return a; return b;  <->  return c ? a : b;
        if (blocks.empty()) return false;
        Node* b = pick(blocks);
        auto ret = [](const Node& n, Toks& v) {
            const Node* s = &n;
            if (s->kind == Node::Block && s->kids.size() == 1) s = &s->kids[0];
            if (s->kind != Node::Simple || s->a.size() < 3 || s->a[0] != "return") return false;
            v.assign(s->a.begin() + 1, s->a.end() - 1);
            return true;
        };
        for (size_t i = 0; i < b->kids.size(); ++i) {
            Node& n = b->kids[i];
            Toks x, y;
            if (n.kind == Node::If && ret(n.kids[0], x) &&
                ((n.kids.size() == 2 && ret(n.kids[1], y)) || (n.kids.size() == 1 && i + 1 < b->kids.size() && ret(b->kids[i + 1], y)))) {
                Node r;
                r.kind = Node::Simple;
                Toks c = paren(n.a), px = paren(x), py = paren(y);
                r.a = {"return"};
                r.a.insert(r.a.end(), c.begin(), c.end());
                r.a.push_back("?");
                r.a.insert(r.a.end(), px.begin(), px.end());
                r.a.push_back(":");
                r.a.insert(r.a.end(), py.begin(), py.end());
                r.a.push_back(";");
                bool two = n.kids.size() == 1;
                b->kids[i] = r;
                if (two) b->kids.erase(b->kids.begin() + long(i) + 1);
                return true;
            }
            if (n.kind == Node::Simple && n.a.size() > 4 && n.a[0] == "return") {
                int q = topLevel(Toks(n.a.begin() + 1, n.a.end() - 1), {"?"}, true);
                if (q < 0) continue;
                Toks e(n.a.begin() + 1, n.a.end() - 1);
                int d = 0, colon = -1, depthQ = 0;
                for (size_t k = size_t(q) + 1; k < e.size(); ++k) {
                    if (e[k] == "(" || e[k] == "[") ++d;
                    if (e[k] == ")" || e[k] == "]") --d;
                    if (d == 0 && e[k] == "?") ++depthQ;
                    if (d == 0 && e[k] == ":") { if (depthQ == 0) { colon = int(k); break; } --depthQ; }
                }
                if (colon < 0) continue;
                Node f;
                f.kind = Node::If;
                f.a.assign(e.begin(), e.begin() + q);
                Node r1, r2;
                r1.kind = r2.kind = Node::Simple;
                r1.a = {"return"};
                r1.a.insert(r1.a.end(), e.begin() + q + 1, e.begin() + colon);
                r1.a.push_back(";");
                r2.a = {"return"};
                r2.a.insert(r2.a.end(), e.begin() + colon + 1, e.end());
                r2.a.push_back(";");
                f.kids.push_back(r1);
                b->kids[i] = f;
                b->kids.insert(b->kids.begin() + long(i) + 1, r2);
                return true;
            }
        }
        return false;
    }
    case 10: {  // for (;;) <-> while (1) <-> while (true); for (i; c; s) B <-> i; while (c) { B s; }
        std::vector<Node*> v;
        for (Node* n : all)
            if (n->kind == Node::For || n->kind == Node::While) v.push_back(n);
        if (v.empty()) return false;
        Node* n = pick(v);
        if (n->kind == Node::For && n->a.empty() && n->b.empty() && n->c.empty()) {
            n->kind = Node::While;
            n->a = {std::uniform_int_distribution<int>(0, 1)(rng) ? "true" : "1"};
            return true;
        }
        if (n->kind == Node::While && n->a.size() == 1 && (n->a[0] == "1" || n->a[0] == "true")) {
            n->kind = Node::For;
            n->a.clear();
            return true;
        }
        if (n->kind == Node::For && !n->b.empty()) {
            Node w;
            w.kind = Node::While;
            w.a = n->b;
            Node body = n->kids[0];
            if (body.kind != Node::Block) { Node bb; bb.kind = Node::Block; bb.kids.push_back(body); body = bb; }
            if (!n->c.empty()) { Node s; s.kind = Node::Simple; s.a = n->c; s.a.push_back(";"); body.kids.push_back(s); }
            w.kids.push_back(body);
            Node out;
            out.kind = Node::Block;
            if (!n->a.empty()) { Node s; s.kind = Node::Simple; s.a = n->a; s.a.push_back(";"); out.kids.push_back(s); }
            out.kids.push_back(w);
            *n = out;
            return true;
        }
        return false;
    }
    case 11: {  // swap the operands of ==, !=, +, *, &, | in a condition
        if (conds.empty()) return false;
        Toks& c = condOf(pick(conds));
        for (const char* op : {"==", "!=", "&", "|", "+", "*"}) {
            int i = topLevel(c, {op});
            if (i <= 0) continue;
            Toks l(c.begin(), c.begin() + i), r(c.begin() + i + 1, c.end());
            if (!simpleOperand(l) || !simpleOperand(r)) continue;
            Toks out = r;
            out.push_back(op);
            out.insert(out.end(), l.begin(), l.end());
            c = out;
            return true;
        }
        return false;
    }
    }
    return false;
}

// ---- listings and score ------------------------------------------------------------------------------------------

std::string run(const std::string& cmd) {
    std::string out;
    FILE* p = popen(cmd.c_str(), "r");
    if (!p) return out;
    char buf[4096];
    size_t n;
    while ((n = fread(buf, 1, sizeof buf, p)) > 0) out.append(buf, n);
    pclose(p);
    return out;
}

std::string quote(const std::string& s) {
    std::string q = "'";
    for (char c : s) q += c == '\'' ? std::string("'\\''") : std::string(1, c);
    return q + "'";
}

// The fill after a function: int3, nops, and lea r,[r+0] (a long nop).
void trimFill(std::vector<std::string>& t) {
    static const std::regex longNop("lea (\\w+),\\[\\1\\+0x0\\]");
    while (!t.empty() && (t.back() == "int3" || t.back().rfind("nop", 0) == 0 || std::regex_match(t.back(), longNop))) t.pop_back();
}

// What a symbol of ours stands for in the original: the stub lists ("0x<address> <decorated>": hook/stubs.txt, the
// generated classes' src/classes/stubs.txt, and the last build's STUB annotations and GLOBALs), else the address in
// its name (Fn0045e000, gpB43dc4: the names the agents give unknowns). 0 = not known.
uint32_t originalOf(const std::string& sym, const std::map<std::string, uint32_t>& stubs) {
    // first the scored file's own STUB and GLOBAL lines, by symbol prefix (sourceStubs): newer than any build's list
    for (auto& [prefix, address] : stubs)
        if (prefix.size() > 2 && prefix.compare(prefix.size() - 2, 2, "@@") == 0 && sym.rfind(prefix, 0) == 0) return address;
    auto it = stubs.find(sym);
    if (it != stubs.end()) return it->second;
    std::string name = sym.substr(sym[0] == '?' ? 1 : 0);
    name = name.substr(0, name.find('@'));
    static const std::regex fn("^Fn([0-9a-fA-F]{8})$"), global("^g[a-z]?([0-9A-Fa-f]{6,8})$");
    std::smatch m;
    if (std::regex_match(name, m, fn) || std::regex_match(name, m, global)) return uint32_t(std::stoul(m[1], nullptr, 16));
    return 0;
}

// The STUB and GLOBAL lines of a source, as the symbol prefix each declaration compiles to ("?Name@@" for a free
// function or variable, "?Name@Struct@@" for a member, "??0Struct@@" for a constructor) and its original address.
void sourceStubs(const std::string& src, std::map<std::string, uint32_t>& out) {
    std::istringstream ss(src);
    std::string cls, line;
    uint32_t pending = 0;
    static const std::regex annotation("^\\s*// (STUB|GLOBAL): 0x([0-9a-fA-F]+)"), open("^(struct|class)\\s+(\\w+)[^;]*$");
    std::smatch m;
    while (std::getline(ss, line)) {
        if (std::regex_search(line, m, annotation)) { pending = uint32_t(std::stoul(m[2], nullptr, 16)); continue; }
        if (std::regex_search(line, m, open)) cls = m[2];
        if (line.rfind("};", 0) == 0) cls.clear();
        if (!pending || line.find_first_not_of(" \t") == std::string::npos) continue;
        std::string decl = line.substr(0, line.find('('));
        decl = decl.substr(0, decl.find('['));
        decl = decl.substr(0, decl.find(';'));
        static const std::regex last("([~\\w]+(::[~\\w]+)*)\\s*$");
        if (std::regex_search(decl, m, last)) {
            std::string name = m[1], scope = line[0] == ' ' || line[0] == '\t' ? cls : "";
            if (auto c = name.rfind("::"); c != std::string::npos) { scope = name.substr(0, c); name = name.substr(c + 2); }
            if (name == scope && !scope.empty()) out.emplace("??0" + scope + "@@", pending);
            else out.emplace("?" + name + "@" + (scope.empty() ? "" : scope + "@") + "@", pending);
        }
        pending = 0;
    }
}

std::map<std::string, uint32_t> loadStubs() {
    std::map<std::string, uint32_t> out;
    for (const char* path : {"hook/stubs.txt", "src/classes/stubs.txt", "build/vc71/stubs.annotated.txt", "build/vc71/globals.txt"}) {
        std::ifstream f(path);
        std::string a, s;
        for (std::string line; std::getline(f, line);) {
            std::istringstream ss(line);
            if (line.rfind("0x", 0) == 0 && ss >> a >> s) out.emplace(s, uint32_t(std::stoul(a, nullptr, 16)));
        }
    }
    return out;
}

// One function of a rebuilt object: its tokens, and every address outside it that it refers to, in order, as the
// original address it stands for (0 = not known: a constant of ours, a string, a function of this file).
struct Listing {
    std::vector<std::string> tokens;
    std::vector<std::pair<uint32_t, std::string>> refs;
};

// A rebuilt object's functions, read with the tokenizer the original goes through (pe.h). Each function's section is
// placed in a stand-in image with the original's base and size, its relocations applied: a target in the same section
// lands where it sits, any other symbol in a 4 KB window of its own in the upper half of the image (so it reads as an
// address, "addr", like the original's globals and callees, and an offset added to it survives as the remainder).
// Labels ($L...) and switch tables stay inside the function.
std::map<std::string, Listing> objectListing(const std::string& obj, const ob::Image& orig,
                                             const std::map<std::string, uint32_t>& stubs) {
    std::map<std::string, Listing> fns;
    std::ifstream f(obj, std::ios::binary);
    std::vector<uint8_t> b((std::istreambuf_iterator<char>(f)), {});
    if (b.size() < 20 || ob::rd16(b, 0) != 0x14c) return fns;
    uint16_t nsect = ob::rd16(b, 2), optSize = ob::rd16(b, 16);
    uint32_t symtab = ob::rd32(b, 8), nsyms = ob::rd32(b, 12);
    if (symtab + uint64_t(nsyms) * 18 > b.size()) return fns;
    size_t strtab = symtab + size_t(nsyms) * 18;
    auto symName = [&](uint32_t i) {
        size_t s = symtab + size_t(i) * 18;
        if (ob::rd32(b, s) == 0) {
            size_t o = strtab + ob::rd32(b, s + 4);
            return o < b.size() ? std::string(reinterpret_cast<const char*>(b.data() + o)) : std::string();
        }
        return std::string(reinterpret_cast<const char*>(b.data() + s), strnlen(reinterpret_cast<const char*>(b.data() + s), 8));
    };
    struct Sym { std::string name; uint32_t value; int16_t section; bool function; };
    std::vector<Sym> syms(nsyms);
    for (uint32_t i = 0; i < nsyms; ++i) {
        size_t s = symtab + size_t(i) * 18;
        int16_t sec;
        std::memcpy(&sec, b.data() + s + 12, 2);
        syms[i] = {symName(i), ob::rd32(b, s + 8), sec, ob::rd16(b, s + 14) == 0x20};
        i += b[s + 17];  // auxiliary records
    }
    const uint32_t place = orig.base + 0x1000, others = orig.base + orig.size / 2;
    for (uint32_t i = 0; i < nsyms; ++i) {
        const Sym& fn = syms[i];
        if (!fn.function || fn.section <= 0 || fn.section > nsect || fn.name.empty()) continue;
        size_t sh = 20 + optSize + size_t(fn.section - 1) * 40;
        uint32_t rawSize = ob::rd32(b, sh + 16), raw = ob::rd32(b, sh + 20), relocs = ob::rd32(b, sh + 24);
        uint16_t nrel = ob::rd16(b, sh + 32);
        if (uint64_t(raw) + rawSize > b.size() || uint64_t(relocs) + nrel * 10ull > b.size()) continue;
        // the function runs to the next function in its section, or the section's end
        uint32_t end = rawSize;
        for (uint32_t j = 0; j < nsyms; ++j)
            if (syms[j].function && syms[j].section == fn.section && syms[j].value > fn.value) end = std::min(end, syms[j].value);
        ob::Image img;
        img.base = orig.base;
        img.size = orig.size;
        img.file.assign(b.begin() + raw, b.begin() + raw + rawSize);
        img.sections.push_back({place - orig.base, rawSize, 0, rawSize, 0x60000020u});
        std::map<uint32_t, uint32_t> window;  // symbol → its window
        std::vector<uint32_t> windowSym;
        auto at = [&](uint32_t s) {
            if (syms[s].section == fn.section) return place + syms[s].value;
            auto w = window.emplace(s, uint32_t(windowSym.size()));
            if (w.second) windowSym.push_back(s);
            return others + 0x1000 * w.first->second;
        };
        for (uint16_t r = 0; r < nrel; ++r) {
            size_t e = relocs + size_t(r) * 10;
            uint32_t off = ob::rd32(b, e), s = ob::rd32(b, e + 4);
            uint16_t type = ob::rd16(b, e + 8);
            if (s >= nsyms || off + 4 > rawSize) continue;
            uint32_t v = ob::rd32(img.file, off);
            if (type == 6) v += at(s);                          // DIR32
            else if (type == 0x14) v += at(s) - (place + off + 4);  // REL32
            else continue;
            std::memcpy(img.file.data() + off, &v, 4);
        }
        // the read-only data it reads (the compiler's float constants) in its window, so its value compares
        for (uint32_t k = 0; k < windowSym.size(); ++k) {
            const Sym& d = syms[windowSym[k]];
            if (d.section <= 0 || d.section > nsect) continue;
            size_t dh = 20 + optSize + size_t(d.section - 1) * 40;
            uint32_t dSize = ob::rd32(b, dh + 16), dRaw = ob::rd32(b, dh + 20), dFlags = ob::rd32(b, dh + 36);
            if ((dFlags & 0xe0000000u) != 0x40000000u || !dRaw || d.value >= dSize || uint64_t(dRaw) + dSize > b.size()) continue;
            uint32_t len = std::min<uint32_t>(dSize - d.value, 0x1000);
            img.sections.push_back({others + 0x1000 * k - orig.base, len, uint32_t(img.file.size()), len, 0x40000040u});
            img.file.insert(img.file.end(), b.begin() + dRaw + d.value, b.begin() + dRaw + d.value + len);
        }
        // an imported function by its name, "imp:<function>" (__imp__glEnable@4 → imp:glEnable), as the original's
        std::map<uint32_t, std::string> imports;
        for (uint32_t k = 0; k < windowSym.size(); ++k) {
            const std::string& n = syms[windowSym[k]].name;
            if (n.rfind("__imp_", 0) != 0) continue;
            std::string f = n.substr(n.size() > 6 && n[6] == '_' ? 7 : 6);
            imports[others + 0x1000 * k] = "imp:" + f.substr(0, f.find('@'));
        }
        std::vector<uint32_t> refs;
        Listing& l = fns[fn.name];
        l.tokens = ob::tokenize({&img, &imports}, place + fn.value, end - fn.value, &refs);
        trimFill(l.tokens);
        for (uint32_t r : refs) {
            if (r < others || (r - others) / 0x1000 >= windowSym.size()) { l.refs.push_back({r, ""}); continue; }  // a number
            const std::string& name = syms[windowSym[(r - others) / 0x1000]].name;
            uint32_t o = originalOf(name, stubs);
            l.refs.push_back({o ? o + (r - others) % 0x1000 : 0, name});
        }
    }
    return fns;
}

size_t diffScore(const std::vector<std::string>& a, const std::vector<std::string>& b) {
    std::vector<size_t> prev(b.size() + 1), cur(b.size() + 1);
    for (size_t i = 1; i <= a.size(); ++i) {
        for (size_t j = 1; j <= b.size(); ++j)
            cur[j] = a[i - 1] == b[j - 1] ? prev[j - 1] + 1 : std::max(prev[j], cur[j - 1]);
        std::swap(prev, cur);
    }
    return a.size() + b.size() - 2 * prev[b.size()];
}

}  // namespace

int main(int argc, char** argv) {
    std::vector<std::string> pos;
    long tries = 2000, seconds = 600;
    int jobs = 8, seed = int(std::random_device{}());
    std::string flags, work = "scratch/perm", outPath;
    bool quiet = false;
    std::string fixedObj;  // --obj: score this already compiled object, no compile and no search
    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        auto value = [&]() -> std::string {
            if (i + 1 >= argc) { std::fprintf(stderr, "%s needs a value\n", a.c_str()); std::exit(2); }
            return argv[++i];
        };
        if (a == "--tries") tries = std::stol(value());
        else if (a == "--jobs") jobs = std::stoi(value());
        else if (a == "--seed") seed = std::stoi(value());
        else if (a == "--seconds") seconds = std::stol(value());
        else if (a == "--flags") flags = value();
        else if (a == "--work") work = value();
        else if (a == "--out") outPath = value();
        else if (a == "--quiet") quiet = true;
        else if (a == "--obj") fixedObj = value();
        else pos.push_back(a);
    }
    if (pos.size() != 4) {
        std::fprintf(stderr, "usage: obperm <original.exe> <functions.tsv> <file.cpp> <address> [--tries N] [--jobs N] "
                             "[--seed N] [--seconds N] [--flags \"...\"] [--work DIR] [--out FILE] [--quiet]\n");
        return 2;
    }
    const std::string exe = pos[0], file = pos[2];
    uint32_t addr = uint32_t(std::stoul(pos[3], nullptr, 16));

    // The original: its size from the function list, its listing from objdump.
    uint32_t size = 0;
    {
        std::ifstream f(pos[1]);
        std::string a, s;
        std::string line;
        while (std::getline(f, line)) {
            std::istringstream ss(line);
            if (ss >> a >> s && a[0] != '#' && std::stoul(a, nullptr, 16) == addr) { size = uint32_t(std::stoul(s, nullptr, 16)); break; }
        }
    }
    if (!size) { std::fprintf(stderr, "0x%x is not in %s\n", addr, pos[1].c_str()); return 2; }
    ob::Image orig;
    if (!ob::loadImage(exe, orig)) { std::fprintf(stderr, "cannot read %s\n", exe.c_str()); return 2; }
    // its imports by function name, as the object names them (objectListing)
    std::map<uint32_t, std::string> imports;
    for (auto& [slot, name] : ob::importNames(orig)) imports[slot] = "imp:" + name.substr(name.find('!') + 1);
    std::vector<uint32_t> wantRefs;
    std::vector<std::string> want = ob::tokenize({&orig, &imports}, addr, size, &wantRefs);
    std::map<std::string, uint32_t> stubs = loadStubs();
    trimFill(want);
    if (want.empty()) { std::fprintf(stderr, "no code at 0x%x\n", addr); return 2; }

    // The source: the body after the annotation.
    std::string src;
    {
        std::ifstream f(file);
        if (!f) { std::fprintf(stderr, "cannot read %s\n", file.c_str()); return 2; }
        std::stringstream ss;
        ss << f.rdbuf();
        src = ss.str();
    }
    sourceStubs(src, stubs);
    char ann[40];
    std::snprintf(ann, sizeof ann, "// FUNCTION: 0x%08x", addr);
    size_t at = src.find(ann);
    if (at == std::string::npos) { std::fprintf(stderr, "no \"%s\" in %s\n", ann, file.c_str()); return 2; }
    size_t open = src.find('{', at);
    std::string header = src.substr(src.find('\n', at) + 1, open - src.find('\n', at) - 1);
    size_t close = open;
    {
        int d = 0;
        for (size_t i = open; i < src.size(); ++i) {
            if (src[i] == '{') ++d;
            if (src[i] == '}' && --d == 0) { close = i; break; }
        }
    }
    bool pre;
    Toks bodyToks = tokenize(src.substr(open, close + 1 - open), pre);
    if (pre && fixedObj.empty()) { std::fprintf(stderr, "a preprocessor line inside the body: not permuted\n"); return 2; }
    Parser parser(bodyToks);
    Node root = parser.block();
    if ((!parser.ok || parser.p != bodyToks.size()) && fixedObj.empty()) {
        std::fprintf(stderr, "cannot read the body's statements\n");
        return 2;
    }

    // Its symbol: "?Name@Class@@...", "??0Class@@" (constructor) or "??1Class@@" (destructor), from the header.
    std::string prefix;
    {
        bool p2;
        Toks h = tokenize(header, p2);
        auto lp = std::find(h.begin(), h.end(), "(");
        if (lp == h.end() || lp == h.begin()) { std::fprintf(stderr, "cannot read the definition's name\n"); return 2; }
        // operator@: the name is the operator's code ("??4" for =), the scope as for any member
        static const std::map<std::string, std::string> opCode = {
            {"=", "4"}, {">>", "5"}, {"<<", "6"}, {"!", "7"}, {"==", "8"}, {"!=", "9"}, {"[]", "A"}, {"->", "C"},
            {"*", "D"}, {"++", "E"}, {"--", "F"}, {"-", "G"}, {"+", "H"}, {"&", "I"}, {"/", "K"}, {"%", "L"},
            {"<", "M"}, {"<=", "N"}, {">", "O"}, {">=", "P"}, {"()", "R"}, {"~", "S"}, {"^", "T"}, {"|", "U"},
            {"&&", "V"}, {"||", "W"}, {"*=", "X"}, {"+=", "Y"}, {"-=", "Z"}, {"/=", "_0"}, {"%=", "_1"},
            {">>=", "_2"}, {"<<=", "_3"}, {"&=", "_4"}, {"|=", "_5"}, {"^=", "_6"}, {"new", "2"}, {"delete", "3"}};
        std::string op;
        auto name0 = lp - 1;
        for (auto q = h.begin(); q != lp; ++q)
            if (*q == "operator") {
                for (auto r = q + 1; r != lp; ++r) op += *r;
                if (op == "(" && lp + 1 != h.end() && *(lp + 1) == ")") { op = "()"; lp = std::find(lp + 2, h.end(), "("); }
                name0 = q;
                break;
            }
        std::vector<std::string> parts{*name0};
        bool dtor = op.empty() && name0 - h.begin() >= 1 && *(name0 - 1) == "~";
        for (auto q = name0 - (dtor ? 1 : 0); q - h.begin() >= 2 && *(q - 1) == "::"; q -= 2) parts.insert(parts.begin(), *(q - 2));
        std::string scope;
        for (size_t i = parts.size() - 1; i-- > 0;) scope += parts[i] + "@";
        const std::string& name = parts.back();
        if (!op.empty()) {
            if (!opCode.count(op)) { std::fprintf(stderr, "unknown operator%s\n", op.c_str()); return 2; }
            prefix = "??" + opCode.at(op) + scope + "@";
        } else if (dtor) prefix = "??1" + scope + "@";
        else if (parts.size() >= 2 && name == parts[parts.size() - 2]) prefix = "??0" + scope + "@";
        else prefix = "?" + name + "@" + scope + "@";
    }

    // Flags: build.sh's common options and the nearest FLAGS file's.
    if (flags.empty()) {
        for (fs::path d = fs::path(file).parent_path(); !d.empty() && d.string().rfind("src", 0) == 0; d = d.parent_path()) {
            std::ifstream f(d / "FLAGS");
            if (!f) continue;
            std::string line;
            while (std::getline(f, line))
                if (!line.empty() && line[0] != '#') flags += line + " ";
            break;
        }
        if (flags.empty()) flags = "/O2 /GX- /W3";
    }
    std::string common = "/nologo /c /DOB_DRAFTS /Isdk /Isrc /Ihook /Ithird_party/stlport-4.6/stlport /D_STLP_DONT_FORCE_MSVC_LIB_NAME "
                         "/D_STLP_USE_NEWALLOC /D_STLP_OUT_OF_LINE_STL_NEW /D_STLP_RESIZE_BY_REFERENCE /I" +
                         quote(fs::path(file).parent_path().string());

    fs::create_directories(work);
    {
        std::ofstream o(work + "/want.txt");
        for (auto& l : want) o << l << "\n";
    }
    auto build =[&](const Node& body, int slot, std::string& text) -> long {
        std::string b;
        print(body, 0, b);
        text = src.substr(0, open) + b.substr(0, b.size() - 1) + src.substr(close + 1);
        std::string dir = work + "/j" + std::to_string(slot);
        fs::create_directories(dir);
        std::string cpp = dir + "/t.cpp", obj = fixedObj.empty() ? dir + "/t.obj" : fixedObj;
        if (fixedObj.empty()) {
            { std::ofstream o(cpp); o << text; }
            fs::remove(obj);
        // a candidate can send the compiler into a loop: no compile runs past a minute (a warm one takes about one
        // second); timeout signals its whole process group, the compiler under Wine included
            run("timeout -k 5 60 tools/vc71.sh cl " + common + " " + flags + " /Fo" + quote(obj) + " " + quote(cpp) + " >" +
                quote(dir + "/cl.txt") + " 2>&1");
        }
        if (!fs::exists(obj)) return -1;
        long best = -1;
        for (auto& [name, l] : objectListing(obj, orig, stubs))
            if (name.rfind(prefix, 0) == 0) {
                long s = long(diffScore(want, l.tokens));
                // Identical instructions: then each address it refers to must be the original's too, where we know
                // what ours stands for (a call to the wrong function, a global at the wrong address).
                std::string why;
                if (s == 0) {
                    if (l.refs.size() != wantRefs.size()) {
                        s += long(l.refs.size() > wantRefs.size() ? l.refs.size() - wantRefs.size() : wantRefs.size() - l.refs.size());
                        why += "the addresses it refers to: " + std::to_string(l.refs.size()) + ", the original's " +
                               std::to_string(wantRefs.size()) + "\n";
                    } else {
                        for (size_t i = 0; i < l.refs.size(); ++i) {
                            uint32_t ours = l.refs[i].first;
                            if (!ours || ours == wantRefs[i]) continue;
                            ++s;
                            char line[160];
                            std::snprintf(line, sizeof line, "address %zu: ours 0x%08x, the original's 0x%08x", i + 1, ours,
                                          wantRefs[i]);
                            why += line + (l.refs[i].second.empty() ? "" : " (ours is " + l.refs[i].second + ")") + "\n";
                        }
                    }
                }
                if (best < 0 || s < best) {
                    best = s;
                    std::ofstream o(dir + "/got.txt");  // the listing scored, beside work/want.txt, for a diff
                    for (auto& t : l.tokens) o << t << "\n";
                    std::ofstream w(dir + "/targets.txt");  // why identical instructions still score
                    w << why;
                }
            }
        return best;
    };

    std::string bestText;
    long best = build(root, 0, bestText);
    if (best < 0) {
        // the compiler's own words (it writes them to stdout): the error lines, so a typo needs no second run
        std::string errors = run("grep -E 'error|fatal' " + quote(work + "/j0/cl.txt") + " 2>/dev/null | head -20");
        std::fprintf(stderr, "%s%s", errors.c_str(), errors.empty() ? "" : "\n");
        std::fprintf(stderr, "the file does not compile, or no symbol %s... in it\n", prefix.c_str());
        return 2;
    }
    if (!fixedObj.empty()) {
        std::ifstream w(work + "/j0/targets.txt");
        for (std::string line; std::getline(w, line);) std::printf("target: %s\n", line.c_str());
        std::printf("start: %ld (original %zu instructions)\n", best, want.size());
        return best == 0 ? 0 : 1;
    }
    if (!quiet) std::printf("start: %ld (original %zu instructions)\n", best, want.size());
    Node bestNode = root, cur = root;
    long curScore = best;
    std::set<std::string> seen;
    { std::string b; print(root, 0, b); seen.insert(b); }
    Rng rng{uint32_t(seed)};
    auto t0 = std::chrono::steady_clock::now();
    long tried = 0;
    while (best > 0 && tried < tries &&
           std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - t0).count() < seconds) {
        // a round: one candidate per job, each from the current spelling with one to three changes
        std::vector<Node> cand;
        for (int k = 0, guard = 0; k < jobs && guard < jobs * 50; ++guard) {
            Node n = cur;
            int changes = std::uniform_int_distribution<int>(1, 3)(rng), applied = 0;
            for (int c = 0; c < changes * 4 && applied < changes; ++c) applied += mutate(n, rng);
            std::string b;
            print(n, 0, b);
            if (!applied || !seen.insert(b).second) continue;
            cand.push_back(n);
            ++k;
        }
        if (cand.empty()) break;
        std::vector<long> score(cand.size());
        std::vector<std::string> text(cand.size());
        std::vector<std::thread> th;
        for (size_t k = 0; k < cand.size(); ++k) th.emplace_back([&, k] { score[k] = build(cand[k], int(k), text[k]); });
        for (auto& t : th) t.join();
        tried += long(cand.size());
        size_t pickK = cand.size();
        for (size_t k = 0; k < cand.size(); ++k)
            if (score[k] >= 0 && (pickK == cand.size() || score[k] < score[pickK])) pickK = k;
        if (pickK == cand.size()) continue;
        if (score[pickK] < best) {
            best = score[pickK];
            bestNode = cand[pickK];
            bestText = text[pickK];
            if (!quiet) std::printf("%ld tries: %ld\n", tried, best);
            std::fflush(stdout);
        }
        // walk on: to anything no worse, and now and then to something a little worse (out of a local minimum)
        if (score[pickK] <= curScore || std::uniform_int_distribution<int>(0, 9)(rng) == 0) { cur = cand[pickK]; curScore = score[pickK]; }
        if (curScore > best + 4) { cur = bestNode; curScore = best; }
    }
    std::string out = outPath.empty() ? work + "/best.cpp" : outPath;
    { std::ofstream o(out); o << bestText; }
    std::printf("%s: score %ld after %ld tries, %lds -> %s\n", best == 0 ? "MATCH" : "best", best, tried,
                long(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - t0).count()),
                out.c_str());
    return best == 0 ? 0 : 1;
}
