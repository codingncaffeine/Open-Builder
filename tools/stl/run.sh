#!/usr/bin/env bash
# Finds the original's STLport instances for element types the game uses (tools/stl/catalogue.py), with each flag set
# the original built its parts with, and lists the ones that are not known library functions yet.
#   tools/stl/run.sh <out dir> [--apply]
# OB_STL_INCLUDE=<dir> builds against other STLport headers (an experiment on EA's changes), default the vendored ones.
# Writes <out dir>/<variant>/{lib.dll,lib.map,functions.tsv,matches.tsv} and <out dir>/new.tsv: "address size name
# variant" for every identical instance whose address re/map/libraries.tsv does not list and no FUNCTION annotation in
# src/ claims (agents wrote some of these out by hand as helpers). --apply adds them to re/map/libraries.tsv.
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$root"
out="$(realpath -m "$1")" apply="${2:-}"
exe="scratch/testbed/game/Apps/SimCity 4.exe"
obsig=scratch/build/obcmp/obsig
mkdir -p "$out/src"
# One object can hold only so many sections: 40 instantiations per source.
stl=(/I"${OB_STL_INCLUDE:-third_party/stlport-4.6/stlport}" /Isrc /D_STLP_DONT_FORCE_MSVC_LIB_NAME /D_STLP_USE_NEWALLOC
  /D_STLP_OUT_OF_LINE_STL_NEW /D_STLP_RESIZE_BY_REFERENCE /D_STLP_TREE_ITERATOR_WALKS /D_STLP_INSERT_UNIQUE_BY_X /W0)
# A variant is built again only when the catalogue, the options or the headers changed (or its last run did not finish).
python3 tools/stl/catalogue.py >"$out/catalogue.cpp"
{ md5sum "$out/catalogue.cpp" tools/obcmp/obsig.cpp; echo "${stl[*]}"; find "${OB_STL_INCLUDE:-third_party/stlport-4.6/stlport}" -type f -print0 | sort -z | xargs -0 cat; } |
  md5sum >"$out/stamp.new"
cmp -s "$out/stamp.new" "$out/stamp" || rm -f "$out"/*/matches.tsv
mv "$out/stamp.new" "$out/stamp"
rm -f "$out"/src/*.cpp
awk -v dir="$out/src" '/^template class/ { n++; if (n % 40 == 1) { k++; f = sprintf("%s/c%02d.cpp", dir, k); printf "%s", head > f }
                                           print > f; next }
                       { head = head $0 "\n" }' "$out/catalogue.cpp"
# what the allocator header leaves to the framework (STUB lines in the game's sources), so the library links
printf '%s\n' '#include "gzcom/cGZAllocatorServiceSTLAllocator.h"' 'cIGZFrameWork_Services* RZGetFramework() { return 0; }' \
  'void cGZAllocatorServiceRef::Release() { mpService = 0; }' >"$out/src/zz_framework.cpp"
variant() {  # name, flags
  local d="$out/$1"
  [[ -s "$d/matches.tsv" ]] && return
  tools/build-lib.sh "$d" "$2 ${stl[*]}" "$out"/src/*.cpp
  awk '$4 == "f" && $1 ~ /^0001:/ { print $3 }' "$d/lib.map" >"$d/seeds.txt"
  tools/ghidra/functions.sh "$d/lib.dll" "$d/functions.tsv" "$d/seeds.txt"
  "$obsig" "$exe" re/map/functions.tsv "$d/lib.dll" "$d/functions.tsv" "$d/lib.map" --twins --no-position \
    --out "$d/matches.tsv" | tail -1
}
variant O2 "/O2 /GX-" &
variant O1 "/O1 /GX-" &
variant O2GX "/O2 /GX" &
# where the original kept an inline function out of line (a tree iterator's operator--), the instance was built inlining
# only what is marked inline
variant O2Ob1 "/O2 /Ob1 /GX-" &
variant O1Ob1 "/O1 /Ob1 /GX-" &
variant O2Ob1GX "/O2 /Ob1 /GX" &
wait
# Identical pairs only (obcmp's rescoring would say; obsig's own pairs by tokens are identical by construction, and
# position pairs are off), first variant first, one name per address.
grep -rhoE '// FUNCTION: 0x[0-9a-fA-F]+' src | awk '{ printf "%x\n", strtonum($3) }' | sort -u >"$out/done.txt"
awk -F'\t' -v OFS='\t' 'FILENAME ~ /done.txt$/ { known[$1] = 1; next }
     FILENAME ~ /libraries.tsv$/ { known[sprintf("%x", strtonum("0x" $1))] = 1; next }
     { a = sprintf("%x", strtonum("0x" $1)); v = FILENAME; sub(/\/matches.tsv$/, "", v); sub(/.*\//, "", v)
       if (!(a in known) && !(a in seen)) { seen[a] = 1; print a, $2, $5 ($6 == "# twins" ? "#twin" : ""), v } }' \
  "$out/done.txt" re/map/libraries.tsv "$out"/{O2,O1,O2GX,O2Ob1,O1Ob1,O2Ob1GX}/matches.tsv | sort >"$out/new.tsv"
echo "new: $(wc -l <"$out/new.tsv") instances not in re/map/libraries.tsv"
[[ "$apply" == --apply ]] || exit 0
# The rows count these addresses as library code; they name none of our functions (name#cat: match.sh never finds
# it in our map). A decorated name does not tell which copy of an instance it is: the original can hold several of
# one instance (objects built without function-level linking are never folded: cRZString's own copy of
# _M_range_initialize<char*> at 0x408420 beside 0x407fa0), and obsig's pick among identical instances of several types
# is one of them by chance.
awk -F'\t' -v OFS='\t' '{ n = $3; sub(/#twin$/, "", n); print sprintf("%x", strtonum("0x" $1)), "stlport", n "#cat" }' \
  "$out/new.tsv" >"$out/apply.tsv"
cat "$out/apply.tsv" >>re/map/libraries.tsv
echo "applied: $(wc -l <"$out/apply.tsv") rows added to re/map/libraries.tsv"
