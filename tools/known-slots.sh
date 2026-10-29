#!/usr/bin/env bash
# Lists the slots of the vtables our sources declare by hand (the "// VTABLE:" annotations outside src/classes), read
# from the compiled objects: each vtable's relocations name the function in every slot. tools/obcmp/obdecl reads it
# to derive generated classes from hand-written ones (their slot names and signatures).
#   tools/known-slots.sh <out.tsv>      after a build (build/vc71/obj)
# Writes "<original vtable>\t<slot>\t<decorated>\t<demangled>" per slot.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
out="$1" build=build/vc71
[[ -d "$build/obj" ]] || { echo "build first (tools/build.sh)" >&2; exit 2; }
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
# Hand annotations only: the generated classes (src/classes) are what obdecl writes from this.
find src/classes -name '*.h' -printf '%f\n' 2>/dev/null | sed 's/\.h$//' >"$work/generated"
tools/vtable-annotations.sh | awk 'NR == FNR { g[$1] = 1; next }
  { c = $2; sub(/^\?\?_7/, "", c); sub(/@@.*/, "", c); if (!(c in g)) print }' "$work/generated" - >"$work/annotations"
for obj in "$build"/obj/*.obj; do
  [[ "$(basename "$obj")" == GeneratedClasses_* ]] && continue
  # "(sec N)...??_7Name@@6B@": the section each vtable is in; then every section's relocations, read once.
  llvm-objdump -t "$obj" | awk '/\?\?_7/ && /\(sec +[0-9]+\)/ { match($0, /\(sec +[0-9]+\)/); s = substr($0, RSTART + 5, RLENGTH - 6); gsub(/ /, "", s); print s, $NF }' >"$work/vtables"
  [[ -s "$work/vtables" ]] || continue
  llvm-readobj --relocations "$obj" >"$work/relocs"
  awk 'NR == FNR { sym[$1] = $2; next }
    $1 == "Section" { s = $2; gsub(/[()]/, "", s); on = (s in sym); next }
    on && $1 == "}" { on = 0; next }
    on { print sym[s] "\t" strtonum($1) / 4 "\t" $3 }' "$work/vtables" "$work/relocs"
done | sort -u >"$work/raw"
# The original's address for each of our vtable symbols, then the demangled slot functions.
awk 'NR == FNR { orig[$2] = $1; next } ($1 in orig) { print orig[$1] "\t" $2 "\t" $3 }' "$work/annotations" "$work/raw" |
  sort -k1,1 -k2,2n >"$work/joined"
paste "$work/joined" <(cut -f3 "$work/joined" | llvm-undname 2>/dev/null | awk 'BEGIN { RS = ""; FS = "\n" } { print ($2 != "" ? $2 : $1) }') >"$out"
echo "$(wc -l <"$out") slots of $(cut -f1 "$out" | sort -u | wc -l) vtables"
