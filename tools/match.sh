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
tools/build.sh >/dev/null
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
    for (i = 1; i <= n; i++) if (symva[i] == r) { nm = symname[i]; for (j = 1; j <= n; j++) if (symva[j] > r && (rs == 0 || symva[j] - r < rs)) rs = symva[j] - r }
    if (rs == 0) rs = textend - r  # the last function runs to the end of .text
    if (!(o in size)) { print "# no size for " o > "/dev/stderr"; next }
    printf "%s %s %x %x %s\n", o, size[o], r, rs, nm
  }' re/map/functions.tsv "$map" "$out/hook-pairs.txt" >"$out/pairs.tsv"
"$obcmp" "$exe" "$dll" "$out/pairs.tsv" "$@"
