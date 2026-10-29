#!/usr/bin/env bash
# Prints a class's layout as the original's compiler lays it out (clang's MSVC record and vtable layouts): every field
# and base subobject at its offset from `this`, then for each vtable pointer the slot at each offset, so
# `[ecx+0x8]` and `call DWORD PTR [eax+0x60]` read off directly. Written into each packet by tools/packet.sh.
#   tools/layout.sh <class>
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
cls="${1:?class}"
[[ -f "src/classes/$cls.h" ]] || { echo "no src/classes/$cls.h" >&2; exit 2; }
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
# A constructor of a class derived from it makes clang lay out every vtable (MSVC fills them in the constructor);
# deriving works for an abstract class too (nothing is made).
printf '#include "classes/%s.h"\nstruct ob_layout : %s { ob_layout(); };\nob_layout::ob_layout() {}\n' "$cls" "$cls" >"$work/t.cpp"
args=(-triple i386-pc-windows-msvc -fms-extensions -fms-compatibility -emit-llvm-only -fdump-record-layouts
  -fdump-vtable-layouts -internal-isystem "$(clang -print-resource-dir)/include" -Isrc -Isdk)
clang -cc1 "${args[@]}" "$work/t.cpp" >"$work/out" 2>/dev/null || {
  echo "clang cannot read src/classes/$cls.h" >&2
  exit 2
}
awk -v cls="$cls" '
  # the class record: from its own "0 | class <cls>" line to the size line
  /^\*\*\* Dumping AST Record Layout/ { rec = 0; next }
  $0 ~ "^ +0 \\| (class|struct) " cls "$" { rec = 1; print "# " cls ": offset from this (hex), field or base subobject"; }
  rec && /\[sizeof=/ { s = $0; sub(/^[^[]*/, "", s); print "# " s; rec = 0; next }
  rec && /\|/ { split($0, p, "|"); o = p[1]; gsub(/ /, "", o); if (o == "") next
               printf "0x%02x %s\n", o, p[2]; next }
  # every vtable as this class fills it, seen from the class derived from it: "VFTable for <base> in ob_layout"
  /^VFTable for / { vt = ($0 ~ / in .ob_layout. \(/); rtti = 0; h = $0; sub(/ in .ob_layout. /, " ", h); sub(/ \([0-9]+ entries\)\./, "", h)
                    if (vt) { print ""; print "# " h " — call [vptr+offset]:" } next }
  vt && /^ +[0-9]+ \| / { split($0, p, "|"); i = p[1] + 0; s = p[2]
                          if (s ~ /RTTI/) { rtti = 1; next }
                          printf "  +0x%02x %s\n", (i - rtti) * 4, s; next }
  vt && !/^ +[0-9]+ \| / && !/^ +\| / { vt = 0 }
' "$work/out"
