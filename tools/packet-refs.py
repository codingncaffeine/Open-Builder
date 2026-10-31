#!/usr/bin/env python3
# Adds to work packets a third reference beside the asm and the Ghidra drafts: the function as an independent
# decompilation of the Mac build writes it (DeSCAi4, C++20 from the Mac x86_64 binary, GPLv3), found by the Mac name
# the packet's pairs.tsv gives the function. Its names, types and logic are what the agent reads; its text is never
# copied into src/ (another compiler and pointer size: our code is written against the original's own bytes).
#   tools/packet-refs.py <DeSCAi4 checkout> <packet dir> [...]
# Writes <packet>/<address>.ref.cpp per function found (every overload of the name, the one whose parameters match
# first) and prints how many functions of each packet have one.
import os
import re
import sys

HEADER = ("// REFERENCE ONLY, never copied into src/: {name} as DeSCAi4 (an independent C++ decompilation of the Mac\n"
          "// x86_64 build, GPLv3) writes it, {where}. Read it for names, types and logic; write our own code against\n"
          "// the original's bytes.\n\n")


def definitions(root):
    """qualified name -> [(file, line, parameters, text)] for every function defined in the checkout's .cpp files."""
    found = {}
    head = re.compile(r"^(?!\s)(?!return\b)[^;#/{}]*?\b((?:[A-Za-z_][A-Za-z0-9_]*::)+~?[A-Za-z_][A-Za-z0-9_]*)\s*\(")
    for base, _, files in os.walk(os.path.join(root, "src")):
        for name in files:
            if not name.endswith(".cpp"):
                continue
            path = os.path.join(base, name)
            with open(path, encoding="utf-8", errors="replace") as f:
                lines = f.read().split("\n")
            i = 0
            while i < len(lines):
                m = head.match(lines[i])
                if not m:
                    i += 1
                    continue
                # the declaration runs to its body's brace; a declaration ending in ';' first is no definition
                j, text = i, lines[i]
                while "{" not in text and ";" not in text and j + 1 < len(lines) and j - i < 8:
                    j += 1
                    text += "\n" + lines[j]
                if "{" not in text or text.index("{") > text.find(";") >= 0:
                    i += 1
                    continue
                depth, k, body = 0, i, []
                while k < len(lines):
                    body.append(lines[k])
                    depth += lines[k].count("{") - lines[k].count("}")
                    if depth <= 0 and "{" in "\n".join(body):
                        break
                    k += 1
                params = text[text.index("(", m.end(1)) + 1:]
                params = params[:params.find(")")] if ")" in params else params
                rel = os.path.relpath(path, root)
                found.setdefault(m.group(1), []).append((rel, i + 1, params, "\n".join(body)))
                i = k + 1
    return found


def norm(params):
    """Parameter types as comparable tokens: names, const, std:: and spacing dropped."""
    out = []
    for p in params.split(","):
        p = re.sub(r"\bconst\b|\bstd::|\b(struct|class)\b", "", p).strip()
        p = re.sub(r"\s*=.*$", "", p)
        p = re.sub(r"\b[A-Za-z_][A-Za-z0-9_]*\s*$", "", p) if re.search(r"[\w*&>]\s+[A-Za-z_]\w*\s*$", p) else p
        out.append(re.sub(r"\s+", "", p))
    return [x for x in out if x not in ("", "void")]


def main():
    root, packets = sys.argv[1], sys.argv[2:]
    defs = definitions(root)
    for packet in packets:
        pairs = os.path.join(packet, "pairs.tsv")
        if not os.path.exists(pairs):
            continue
        rows = have = 0
        for line in open(pairs):
            f = line.rstrip("\n").split("\t")
            if len(f) < 3 or "::" not in f[2]:
                continue
            rows += 1
            name = f[2]
            qualified = name[:name.index("(")] if "(" in name else name
            want = norm(name[name.index("(") + 1:name.rindex(")")]) if "(" in name and ")" in name else None
            cands = defs.get(qualified)
            if not cands:
                continue
            cands = sorted(cands, key=lambda c: norm(c[2]) != want)
            have += 1
            out = os.path.join(packet, "%08x.ref.cpp" % int(f[0], 16))
            with open(out, "w") as o:
                for rel, ln, _, body in cands[:4]:
                    o.write(HEADER.format(name=name, where="%s:%d" % (rel, ln)))
                    o.write(body + "\n\n")
        print("%s: %d of %d named functions have a reference" % (os.path.basename(packet.rstrip("/")), have, rows))


if __name__ == "__main__":
    main()
