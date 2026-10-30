#!/usr/bin/env python3
# Writes src/<folder>/GeneratedStatics_<folder>.cpp: the global objects of the original whose construction and
# destruction the compiler wrote as a pair of functions (the dynamic initializer, which constructs the object and
# registers the other with atexit, and the teardown it registers), found in the original by their exact instructions.
#   tools/gen-statics.py
# The families, each a definition and the instructions the folder's flags make of it:
# - cRZString g("...") with the game's flags (/O2): the string's range constructor inline, the vtable stored, the
#   reference count zeroed:
#     push ecx; lea eax,[esp+3]; push eax; push END; push BEGIN; mov ecx,G+4; call _M_range_initialize<const char*>
#     push TEARDOWN; mov [G],cRZString vtable; mov [G+0x10],0; call atexit; add esp,8; ret
#   and the teardown, ~cRZString inline:
#     mov eax,[G+4]; test eax,eax; mov [G],cRZString vtable; je +7; push eax; call __stl_delete; pop ecx; ret
# - std::string g("...") with the game's flags: the same without the vtable and the count,
#     ...; mov ecx,G; call _M_range_initialize<const char*>; push TEARDOWN; call atexit; add esp,8; ret
#     mov eax,[G]; test eax,eax; je +7; push eax; call __stl_delete; pop ecx; ret
# - cRZString g("...") with the framework's flags (/O1): the constructor called,
#     push LITERAL; mov ecx,G; call cRZString::cRZString(const char*); push TEARDOWN; call atexit; pop ecx; ret
#   and the same teardown as the game's.
# - float g[3] = { a[0] * k, a[1] * k, a[2] * k } (a another global, k a constant), or one float alike: no teardown,
#     fld [A]; fmul [K]; fstp [G] (per float); ret
# Each definition is annotated "// STATIC-INIT: 0x<initializer> 0x<teardown>|- <global> <size>": tools/match.sh pairs
# them with the compiler's _$E<n> functions of the object file, in order. The objects live in namespace ob_statics,
# so that the hook build's references to the original's variables (GLOBAL annotations) still reach the original's.
import os
import re
import struct
import sys

root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(root)
EXE = "scratch/testbed/game/Apps/SimCity 4.exe"
OUTS = {g: "src/%s/GeneratedStatics_%s.cpp" % (g, g) for g in ("game", "gzcom")}

RANGE_INIT = 0x407FA0   # basic_string<char>::_M_range_initialize<const char*>
RZSTRING_VTABLE = 0xA80810
ATEXIT = 0x9EF059
STL_DELETE = 0x90CF63
RZSTRING_CTOR = 0x408480  # cRZString::cRZString(const char*), out of line


def sections(data):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    count = struct.unpack_from("<H", data, pe + 6)[0]
    opt = struct.unpack_from("<H", data, pe + 20)[0]
    base = struct.unpack_from("<I", data, pe + 24 + 28)[0]
    out = []
    at = pe + 24 + opt
    for _ in range(count):
        name = data[at:at + 8].rstrip(b"\0").decode()
        vsize, va, rawsize, raw = struct.unpack_from("<IIII", data, at + 8)
        out.append((name, base + va, max(vsize, rawsize), raw))
        at += 40
    return out


data = open(EXE, "rb").read()
secs = sections(data)


def offset(va):
    for _, start, size, raw in secs:
        if start <= va < start + size:
            return raw + va - start
    return None


def dword(va):
    o = offset(va)
    return None if o is None else struct.unpack_from("<I", data, o)[0]


def rel(va):  # the target of the call whose rel32 operand is at va
    return (va + 4 + struct.unpack_from("<i", data, offset(va))[0]) & 0xFFFFFFFF


# Functions already written or spoken for by hand: never generated again.
taken = set()
pat = re.compile(r"// (?:FUNCTION|SYNTHETIC|STUB|CLOSE): 0x([0-9a-fA-F]+)")
for d, _, files in os.walk("src"):
    for f in files:
        if f.endswith((".cpp", ".h")) and os.path.join(d, f) not in OUTS.values():
            for m in pat.finditer(open(os.path.join(d, f), errors="replace").read()):
                taken.add(int(m.group(1), 16))

text = next(s for s in secs if s[0] == ".text")
tbase = text[1] - text[3]  # va = file offset + tbase within .text
def literal(b):  # a C++ literal the compiler stores as these bytes (octal escapes: no hex run-on, no trigraphs)
    s = ""
    for c in b:
        ch = chr(c)
        s += ch if 0x20 <= c < 0x7F and ch not in "\"\\?" else "\\%03o" % c
    return '"' + s + '"'


u32 = lambda va: struct.unpack_from("<I", data, offset(va))[0]


def rztear(td, g):  # ~cRZString inline on G
    o = offset(td)
    want = b"\xa1" + struct.pack("<I", g + 4) + b"\x85\xc0\xc7\x05" + struct.pack("<II", g, RZSTRING_VTABLE) + b"\x74\x07\x50\xe8"
    return o is not None and data[o:o + len(want)] == want and data[o + 25:o + 27] == b"\x59\xc3" and rel(td + 21) == STL_DELETE


def strtear(td, g):  # ~basic_string inline on G
    o = offset(td)
    want = b"\xa1" + struct.pack("<I", g) + b"\x85\xc0\x74\x07\x50\xe8"
    return o is not None and data[o:o + len(want)] == want and data[o + 15:o + 17] == b"\x59\xc3" and rel(td + 11) == STL_DELETE


RANGE = rb"\x51\x8d\x44\x24\x03\x50\x68(.{4})\x68(.{4})\xb9(.{4})\xe8.{4}\x68(.{4})"
families = [  # folder, type, size, initializer pattern, check -> (teardown, global, literal start, literal end) or None
    ("game", "cRZString", 0x14,
     re.compile(RANGE + rb"\xc7\x05(.{4})(.{4})\xc7\x05(.{4})\x00\x00\x00\x00\xe8.{4}\x83\xc4\x08\xc3", re.S),
     lambda fn, end, begin, g4, td, g, vt, g10: (td, g, begin, end)
     if g4 == g + 4 and g10 == g + 0x10 and vt == RZSTRING_VTABLE and rel(fn + 0x16) == RANGE_INIT
     and rel(fn + 0x34) == ATEXIT and rztear(td, g) else None),
    ("game", "std::string", 0xc,
     re.compile(RANGE + rb"\xe8.{4}\x83\xc4\x08\xc3", re.S),
     lambda fn, end, begin, g, td: (td, g, begin, end)
     if rel(fn + 0x16) == RANGE_INIT and rel(fn + 0x20) == ATEXIT and strtear(td, g) else None),
    ("gzcom", "cRZString", 0x14,
     re.compile(rb"\x68(.{4})\xb9(.{4})\xe8.{4}\x68(.{4})\xe8.{4}\x59\xc3", re.S),
     lambda fn, lit, g, td: (td, g, lit, lit + data[offset(lit):].index(b"\0") if offset(lit) is not None else lit)
     if rel(fn + 11) == RZSTRING_CTOR and rel(fn + 21) == ATEXIT and rztear(td, g) else None),
]

defs = {g: [] for g in OUTS}
skipped = 0
held = 0
for folder, typ, size, pattern, check in families:
    for m in pattern.finditer(data, text[3], text[3] + text[2]):
        fn = m.start() + tbase
        got = check(fn, *(struct.unpack("<I", x)[0] for x in m.groups()))
        if got is None:
            skipped += 1
            continue
        td, g, begin, end = got
        lo, hi = offset(begin), offset(end)
        if lo is None or hi is None or hi < lo or data[hi] != 0 or 0 in data[lo:hi]:
            skipped += 1
            continue
        if fn in taken or td in taken:
            continue
        # literals that name other products (registry paths, font faces) wait for a decision on what may be published
        if b"HKEY_" in data[lo:hi] or b"FACE=" in data[lo:hi]:
            held += 1
            continue
        defs[folder].append((fn, td, g, size, "%s g%s(%s);" % (typ, ("%x" % g).capitalize(), literal(data[lo:hi]))))


def floatlit(bits):  # the shortest literal that reads back to these bits
    import math
    v = struct.unpack("<f", struct.pack("<I", bits))[0]
    if not math.isfinite(v):
        return None
    for prec in range(1, 10):
        t = "%.*g" % (prec, v)
        if struct.pack("<f", float(t)) == struct.pack("<I", bits):
            break
    return (t if any(c in t for c in ".e") else t + ".0") + "f"


externs = set()
scale = re.compile(rb"((?:\xd9\x05.{4}\xd8\x0d.{4}\xd9\x1d.{4})+)\xc3", re.S)
starts = sorted(int(l.split()[0], 16) for l in open("re/map/functions.tsv") if l[:1] not in "#\n")
for fn in starts:
    if fn in taken or offset(fn) is None or data[offset(fn):offset(fn) + 2] != b"\xd9\x05":
        continue
    t = scale.match(data, offset(fn))
    if not t:
        continue
    n = len(t.group(1)) // 18
    if n not in (1, 3):
        continue
    A, K, G = ([struct.unpack_from("<I", t.group(1), 18 * i + j)[0] for i in range(n)] for j in (2, 8, 14))
    if any(A[i] != A[0] + 4 * i or G[i] != G[0] + 4 * i or K[i] != K[0] for i in range(n)):
        continue
    o = offset(K[0])
    k = u32(K[0]) if o is not None and o + 4 <= len(data) and next(x for x in secs if x[1] <= K[0] < x[1] + x[2])[0] == ".rdata" else None
    lit = None if k is None else floatlit(k)
    if lit is None:
        skipped += 1
        continue
    a, g = ("%x" % A[0]).capitalize(), ("%x" % G[0]).capitalize()
    if n == 1:
        externs.add((A[0], "float g%s;" % a))
        decl = "float g%s = g%s * %s;" % (g, a, lit)
    else:
        externs.add((A[0], "float g%s[3];" % a))
        decl = "float g%s[3] = { g%s[0] * %s, g%s[1] * %s, g%s[2] * %s };" % (g, a, lit, a, lit, a, lit)
    defs["game"].append((fn, None, G[0], 4 * n, decl))

total = 0
for folder, out in OUTS.items():
    with open(out + ".new", "w") as f:
        f.write("// GENERATED by tools/gen-statics.py: the original's global objects whose construction and destruction the\n"
                "// compiler wrote as functions (the dynamic initializer and the teardown it registers with atexit), found by\n"
                "// their instructions. tools/match.sh pairs each STATIC-INIT with this object's _$E<n> functions, in order.\n"
                "#include \"gzcom/cRZString.h\"\n")
        if folder == "game":  # the original's variables the initializers read
            for a, decl in sorted(externs):
                f.write("\n// GLOBAL: 0x%08x\nextern %s\n" % (a, decl))
        f.write("\nnamespace ob_statics {\n")
        for fn, td, g, size, decl in sorted(defs[folder], key=lambda d: d[0]):
            f.write("\n// STATIC-INIT: 0x%08x %s 0x%08x 0x%x\n%s\n" % (fn, "0x%08x" % td if td else "-", g, size, decl))
        f.write("\n}  // namespace ob_statics\n")
    os.replace(out + ".new", out)
    total += len(defs[folder])
print("gen-statics: %d global objects (%s), %d near misses skipped, %d held back" % (
    total, ", ".join("%s %d" % (k, len(v)) for k, v in defs.items()), skipped, held))
