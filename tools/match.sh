#!/usr/bin/env bash
# Builds the hook DLL with the 2003 compiler and scores every decompiled function against the original (obcmp).
#   tools/match.sh [--verbose]
# The pairs come from the built DLL itself: the hook table (g_hooks, located through the map) holds each original
# address and our function's. Original sizes come from re/map/functions.tsv, ours from the map (up to the next
# symbol or the end of .text; obcmp trims the padding). Exits non-zero unless every function is identical.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
exe="scratch/testbed/game/Apps/SimCity 4.exe"
obcmp="scratch/build/obcmp/obcmp"
[[ -f re/map/functions.tsv && -f "$exe" && -x "$obcmp" ]] || { echo "needs re/map/functions.tsv, the test bed and obcmp" >&2; exit 2; }
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
od -An -v -tx4 -j "$offset" -w16 "$dll" | awk '$1 == "00000000" && $2 == "00000000" {exit} {print $1, $2}' >"$out/hook-pairs.txt"

textend=$(objdump -h "$dll" | awk '$2 == ".text" {print strtonum("0x" $4) + strtonum("0x" $3)}')
awk -v textend="$textend" '
  FILENAME ~ /functions.tsv$/ { size[sprintf("%x", strtonum("0x" $1))] = $2; next }
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
  }' re/map/functions.tsv "$map" "$out/hook-pairs.txt" >"$out/pairs.tsv"
# The stubs that lead to functions not decompiled yet name their original, so calls to them compare by target.
awk '$1 ~ /^0001:/ && $2 ~ /^_ob_stub_[0-9a-f]{8}$/ { print substr($2, 10), $3, "stub_" substr($2, 10) }' "$map" >"$out/names.tsv"
# Vtables: "// VTABLE: 0x<address> [base]" above a class pairs the original's with ours, ??_7Class@@6B@ (or the one
# for that base, ??_7Class@@6BBase@@@); our slot count runs to the next symbol in the map.
grep -rh -A10 -E '// VTABLE: 0x[0-9a-fA-F]+' src | awk '
  /\/\/ VTABLE: 0x/ { match($0, /0x[0-9a-fA-F]+/); va = substr($0, RSTART + 2, RLENGTH - 2); base = $0
                      sub(/.*VTABLE: 0x[0-9a-fA-F]+[ \t]*/, "", base); pending = 1; next }
  pending && match($0, /(class|struct)[ \t]+(OB_NOVTABLE[ \t]+)?[A-Za-z_][A-Za-z0-9_]*/) {
    s = substr($0, RSTART, RLENGTH); n = split(s, w, /[ \t]+/)
    print va, "??_7" w[n] "@@6B" (base == "" ? "@" : base "@@@"); pending = 0 }' >"$out/vtable-annotations.txt"
awk 'FILENAME ~ /vtables.tsv$/ { slots[sprintf("%x", strtonum("0x" $1))] = $2; next }
     FILENAME ~ /version.map$/ {
       if ($1 ~ /^000[0-9]:/ && $3 ~ /^[0-9a-f]{8}$/) { n++; va[n] = strtonum("0x" $3); at[$2] = n }
       next }
     {
       o = sprintf("%x", strtonum("0x" $1))
       if (!($2 in at)) { print "match: no " $2 " in the map (vtable 0x" o ")" > "/dev/stderr"; bad = 1; next }
       i = at[$2]; next_va = 0
       for (j = 1; j <= n; j++) if (va[j] > va[i] && (next_va == 0 || va[j] < next_va)) next_va = va[j]
       printf "%s %x %d %d vtable_%s\n", o, va[i], slots[o], (next_va - va[i]) / 4, o
     }
     END { exit bad }' re/map/vtables.tsv "$map" "$out/vtable-annotations.txt" >"$out/vtables.tsv"
"$obcmp" "$exe" "$dll" "$out/pairs.tsv" --names "$out/names.tsv" --vtables "$out/vtables.tsv" "$@"
