#!/usr/bin/env python3
# Sorts the CLOSE drafts by what keeps them from the original's instructions, from the listings tools/score.sh leaves
# (scratch/perm/<address>/want.txt = the original's, j0/got.txt = ours), so each kind gets the tool that fixes it:
#   offset     the same instructions, only memory displacements differ (a field or subobject typed wrong)
#   register   the same instructions with other registers (allocation: permuter work)
#   order      the same instructions in another order (scheduling, block order: permuter work)
#   immediate  only constants differ (a literal or a size)
#   mixed      the same length, several of the above
#   structure  a different number of instructions (other code: a draft to rework)
#   tools/near-misses.py [--max-score N] [--list KIND]     (from the project folder)
import os
import re
import sys

REG = r"\b(e?[abcd]x|[abcd][lh]|e?[sd]i|e?[sb]p|xmm\d|st\(\d\)|st)\b"


def drafts():
    out = {}
    for base, _, files in os.walk("src"):
        for name in files:
            if name.endswith(".cpp"):
                path = os.path.join(base, name)
                for line in open(path, encoding="utf-8", errors="replace"):
                    m = re.match(r"// CLOSE: 0x([0-9a-fA-F]+) score (\d+)", line)
                    if m:
                        out["%08x" % int(m.group(1), 16)] = (int(m.group(2)), path)
    return out


def kind_of_pair(a, b):
    """What differs between two instructions: offset, register, immediate or other."""
    if re.sub(r"[+-]0x[0-9a-f]+\]", "]", a) == re.sub(r"[+-]0x[0-9a-f]+\]", "]", b):
        return "offset"
    if re.sub(REG, "R", a) == re.sub(REG, "R", b):
        return "register"
    if re.sub(r"\b0x[0-9a-f]+\b|\b\d+\b", "K", a) == re.sub(r"\b0x[0-9a-f]+\b|\b\d+\b", "K", b):
        return "immediate"
    return "other"


def classify(want, got):
    if len(want) != len(got):
        return "structure"
    if sorted(want) == sorted(got):
        return "order"
    kinds = {kind_of_pair(a, b) for a, b in zip(want, got) if a != b}
    if len(kinds) == 1 and "other" not in kinds:
        return kinds.pop()
    if sorted(re.sub(REG, "R", x) for x in want) == sorted(re.sub(REG, "R", x) for x in got):
        return "order"  # reordered and renamed: still scheduling
    return "mixed" if "other" not in kinds else "structure"


def main():
    max_score = 10 ** 9
    listing = None
    args = sys.argv[1:]
    if "--max-score" in args:
        max_score = int(args[args.index("--max-score") + 1])
    if "--list" in args:
        listing = args[args.index("--list") + 1]
    table = {}
    for addr, (score, path) in sorted(drafts().items()):
        if score > max_score:
            continue
        w, g = "scratch/perm/%s/want.txt" % addr, "scratch/perm/%s/j0/got.txt" % addr
        if not (os.path.exists(w) and os.path.exists(g)):
            kind = "no listing"
        else:
            kind = classify([l.rstrip("\n") for l in open(w) if l.strip()], [l.rstrip("\n") for l in open(g) if l.strip()])
        band = "1-2" if score <= 2 else "3-5" if score <= 5 else "6-10" if score <= 10 else "11-20" if score <= 20 else \
            "21-40" if score <= 40 else ">40"
        table.setdefault(kind, {}).setdefault(band, 0)
        table[kind][band] += 1
        if listing == kind:
            print("0x%s\t%d\t%s" % (addr, score, path))
    if listing:
        return
    bands = ["1-2", "3-5", "6-10", "11-20", "21-40", ">40"]
    print("%-11s" % "kind" + "".join("%7s" % b for b in bands) + "%8s" % "all")
    for kind in sorted(table, key=lambda k: -sum(table[k].values())):
        row = table[kind]
        print("%-11s" % kind + "".join("%7d" % row.get(b, 0) for b in bands) + "%8d" % sum(row.values()))


if __name__ == "__main__":
    main()
