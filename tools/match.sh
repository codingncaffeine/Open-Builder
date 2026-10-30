#!/usr/bin/env bash
# Builds the hook DLL with the 2003 compiler and scores every decompiled function against the original (obcmp).
#   tools/match.sh [--verbose]
# The pairs come from the built DLL itself: the hook table (g_hooks, located through the map) holds each original
# address and our function's. Original sizes come from scratch/classes/sizes.tsv (tools/obcmp/obshape --sizes, by
# tools/gen-classes.sh: the function list corrected where it ends a function early), else re/map/functions.tsv; ours
# from the map (up to the next symbol or the end of .text; obcmp trims the padding).
# Exits non-zero unless every function is identical.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
exe="scratch/testbed/game/Apps/SimCity 4.exe"
obcmp="scratch/build/obcmp/obcmp"
[[ -f re/map/functions.tsv && -f "$exe" && -x "$obcmp" ]] || { echo "needs re/map/functions.tsv, the test bed and obcmp" >&2; exit 2; }
sizes=re/map/functions.tsv
[[ -f scratch/classes/sizes.tsv ]] && sizes=scratch/classes/sizes.tsv
log=$(tools/build.sh 2>&1) || { printf '%s\n' "$log" >&2; exit 2; }
out=build/vc71
dll=$out/version.dll map=$out/version.map

table=$(awk '$2 == "?g_hooks@@3QBUHookEntry@@B" {print $3}' "$map")
[[ -n "$table" ]] || { echo "no g_hooks in $map" >&2; exit 2; }
# File offset of the table: from the section that holds its address.
offset=$(objdump -h "$dll" | awk -v va=$((16#$table)) '$1 ~ /^[0-9]+$/ {
  vma = strtonum("0x" $4); size = strtonum("0x" $3); file = strtonum("0x" $6)
  if (va >= vma && va < vma + size) print va - vma + file }')
# Entries of 16 bytes ({original, replacement, name, hook}) up to the all-zero sentinel.
# (through a file: awk stops at the sentinel, which would end od with SIGPIPE under pipefail)
od -An -v -tx4 -j "$offset" -w16 "$dll" >"$out/hook-table.txt"
awk '$1 == "00000000" && $2 == "00000000" {exit} {print $1, $2}' "$out/hook-table.txt" >"$out/hook-pairs.txt"

textend=$(objdump -h "$dll" | awk '$2 == ".text" {print strtonum("0x" $4) + strtonum("0x" $3)}')
awk -v textend="$textend" -v sizes="$sizes" '
  FILENAME == sizes { size[sprintf("%x", strtonum("0x" $1))] = $2; next }
  FILENAME ~ /version.map$/ {
    if ($1 ~ /^0001:/ && $3 ~ /^[0-9a-f]{8}$/) { n++; symva[n] = strtonum("0x" $3); symname[n] = $2 }
    next
  }
  {
    o = sprintf("%x", strtonum("0x" $1)); r = strtonum("0x" $2)
    rs = 0; nm = ""
    for (i = 1; i <= n; i++) if (symva[i] == r && (nm == "" || nm ~ /^_obhook_/)) { nm = symname[i]; for (j = 1; j <= n; j++) if (symva[j] > r && (rs == 0 || symva[j] - r < rs)) rs = symva[j] - r }
    if (rs == 0) rs = textend - r  # the last function runs to the end of .text
    if (!(o in size)) { print "# no size for " o > "/dev/stderr"; next }
    printf "%s %s %x %x %s\n", o, size[o], r, rs, nm
  }' "$sizes" "$map" "$out/hook-pairs.txt" >"$out/pairs.tsv"
# The global objects of tools/gen-statics.py: each STATIC-INIT of an object file pairs the original's initializer and
# teardown with that object's next _$E<n>: the compiler numbers an initializer, its teardown and the pointer to the
# initializer in a row (an object with no teardown, "-", takes two numbers); ours run to the next symbol.
for src in $(grep -rl '^// STATIC-INIT: 0x' src --include=*.cpp | sort); do
  obj=$(basename "$src" .cpp).obj
  awk -v obj="$obj" -v textend="$textend" -v sizes="$sizes" '
    FILENAME == sizes { size[sprintf("%x", strtonum("0x" $1))] = $2; next }
    FILENAME ~ /version.map$/ {
      if ($1 ~ /^0001:/ && $3 ~ /^[0-9a-f]{8}$/) { n++; va[n] = strtonum("0x" $3); f = $NF; sub(/\r$/, "", f); if ($2 ~ /^_\$E[0-9]+$/ && f == obj) e[substr($2, 4)] = va[n] }
      next
    }
    /^\/\/ STATIC-INIT: 0x/ {
      for (w = 0; w < 2; w++) {
        if (w && $4 == "-") continue
        o = sprintf("%x", strtonum($(3 + w))); r = e[next_ + 1 + w]
        if (!r) { print "match: no _$E" next_ + 1 + w " in " obj > "/dev/stderr"; continue }
        rs = textend - r
        for (i = 1; i <= n; i++) if (va[i] > r && va[i] - r < rs) rs = va[i] - r
        if (!(o in size)) { print "# no size for " o > "/dev/stderr"; continue }
        printf "%s %s %x %x %s\n", o, size[o], r, rs, (w ? "teardown_" : "init_") $5
      }
      next_ += $4 == "-" ? 2 : 3
    }' "$sizes" "$map" "$src" >>"$out/pairs.tsv"
done
# The stubs that lead to functions not decompiled yet name their original, so calls to them compare by target.
awk '$1 ~ /^0001:/ && $2 ~ /^_ob_stub_[0-9a-f]{8}$/ { print substr($2, 10), $3, "stub_" substr($2, 10) }' "$map" >"$out/names.tsv"
# A library function (STLport, the C runtime) our build compiles from the library's own source has the original's
# decorated name: it stands for the original's copy, under the name a stub of that copy has. Where our linker folded
# two of them into one body (identical template instances) that body stands for neither: left unnamed. A name our map
# has at several addresses stands for none of them, nor does a static's teardown (_$E<n>: local to its object, named alike
# in every one).
awk -F'\t' 'FILENAME == ARGV[1] { lib[$3] = sprintf("%08x", strtonum("0x" $1)); next }
            { split($0, f, " +") }
            f[2] ~ /^0001:/ && (f[3] in lib) && f[3] !~ /^_\$E[0-9]+$/ { at[f[4]] = lib[f[3]]; n[f[4]]++; sym[f[4]] = f[3]; if (!((f[3], f[4]) in seen)) { seen[f[3], f[4]] = 1; places[f[3]]++ } }
            END { for (a in at) if (n[a] == 1 && places[sym[a]] == 1) print at[a], a, "stub_" at[a] }' re/map/libraries.tsv "$map" >>"$out/names.tsv"
# The original's global variables (GLOBAL annotations) are at the same address on both sides: named alike.
awk '{ a = tolower($1); sub(/^0x/, "", a); print a, a, "data_" a }' "$out/globals.txt" | sort -u >>"$out/names.tsv"
# A global object tools/gen-statics.py defines (ob_statics::g<address>, STATIC-INIT size) stands for the original's at
# that address: every dword of it named alike on both sides.
awk 'FILENAME ~ /version.map$/ {
       if ($2 ~ /^\?g[0-9A-Fa-f]+@ob_statics@@/ && $3 ~ /^[0-9a-f]{8}$/) { nm = $2; sub(/^\?g/, "", nm); sub(/@.*/, "", nm); ours[tolower(nm)] = strtonum("0x" $3) }
       next
     }
     /^\/\/ STATIC-INIT: 0x/ {
       g = strtonum($5); key = sprintf("%x", g)
       # and the original address too, where a decompiled function reaches the variable itself (GLOBAL)
       if (key in ours) for (k = 0; k < strtonum($6); k += 4) printf "%x %x g_0x%x\n%x %x g_0x%x\n", g + k, ours[key] + k, g + k, g + k, g + k, g + k
     }' "$map" $(grep -rl '^// STATIC-INIT: 0x' src --include=*.cpp | sort) >>"$out/names.tsv"
# Vtables: "// VTABLE: 0x<address> [base]" above a class pairs the original's with ours (tools/vtable-annotations.sh);
# our slot count runs to the next symbol in the map at most.
tools/vtable-annotations.sh >"$out/vtable-annotations.txt"
# The generated classes' vtables (src/classes, tools/obcmp/obdecl) are reported, not required: their slots often hold
# functions nothing declares yet. Hand-written ones must be identical.
find src/classes -name '*.h' -printf '%f\n' 2>/dev/null | sed 's/\.h$//' >"$out/generated-classes.txt"
awk 'FILENAME ~ /generated-classes.txt$/ { generated[$1] = 1; next }
     FILENAME ~ /vtables.tsv$/ { slots[sprintf("%x", strtonum("0x" $1))] = $2; next }
     FILENAME ~ /version.map$/ {
       if ($1 ~ /^000[0-9]:/ && $3 ~ /^[0-9a-f]{8}$/) { n++; va[n] = strtonum("0x" $3); at[$2] = n }
       next }
     { want[++w] = $2; orig[w] = sprintf("%x", strtonum("0x" $1)); if ($2 in at) claimed[$2] = 1 }
     END {
       for (k = 1; k <= w; k++) {
         sym = want[k]; o = orig[k]; cls = sym; sub(/^\?\?_7/, "", cls); sub(/@@.*/, "", cls)
         if (!(sym in at) && (cls in generated)) {
           # A generated class whose vtable the compiler named otherwise: its one unclaimed vtable, if just one (the
           # slot by slot comparison then says whether it is the one).
           found = ""; count = 0
           for (s in at) if (index(s, "??_7" cls "@@6B") == 1 && !(s in claimed)) { found = s; count++ }
           if (count == 1) { sym = found; claimed[found] = 1 }
         }
         if (!(sym in at)) {
           print "match: no " sym " in the map (vtable 0x" o ")" > "/dev/stderr"
           if (!(cls in generated)) bad = 1
           continue
         }
         i = at[sym]; next_va = 0
         for (j = 1; j <= n; j++) if (va[j] > va[i] && (next_va == 0 || va[j] < next_va)) next_va = va[j]
         printf "%s %x %d %d vtable_%s %s\n", o, va[i], slots[o], (next_va - va[i]) / 4, o, (cls in generated) ? "report" : "strict"
       }
       exit bad
     }' "$out/generated-classes.txt" re/map/vtables.tsv "$map" "$out/vtable-annotations.txt" >"$out/vtables.tsv"
"$obcmp" "$exe" "$dll" "$out/pairs.tsv" --names "$out/names.tsv" --vtables "$out/vtables.tsv" "$@"
