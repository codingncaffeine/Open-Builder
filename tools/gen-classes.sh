#!/usr/bin/env bash
# Regenerates the declarations of the recovered classes (src/classes, src/*/GeneratedClasses_*.cpp) and builds them:
# the class map from the original (tools/obcmp/obclass), the slots of the hand-declared classes from a build
# (tools/known-slots.sh), what each function pops and does (tools/obcmp/obshape), the declarations and one-line methods
# (tools/obcmp/obdecl). A generated class whose size check fails to compile,
# or whose annotations do not resolve, is excluded and the declarations written again, until the build is clean;
# tools/match.sh then scores what is left.
#   tools/gen-classes.sh
# Reads re/map/functions.tsv, re/map/vtables.tsv and the test bed's program (local, never committed); keeps the class
# map and the exclusions in scratch/classes/.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
exe="scratch/testbed/game/Apps/SimCity 4.exe"
bin=scratch/build/obcmp
work=scratch/classes
mkdir -p "$work"
[[ -x "$bin/obclass" && -x "$bin/obdecl" && -x "$bin/obshape" ]] || { echo "build tools/obcmp first (cmake)" >&2; exit 2; }

# The program's allocator and pure-virtual stub (see hook/stubs.txt).
"$bin/obclass" "$exe" re/map/functions.tsv re/map/vtables.tsv --new 0x5e55e0 --delete 0x5e5620 \
  --classes "$work/classes.tsv" --slots "$work/slots.tsv" --deleting "$work/deleting.tsv"
[[ -d build/vc71/obj ]] || tools/build.sh >/dev/null 2>&1 || true
tools/known-slots.sh "$work/known.tsv"
# What each function pops and, for the one-line ones, does: signatures, fields and bodies.
"$bin/obshape" "$exe" re/map/functions.tsv --out "$work/shapes.tsv" 2>/dev/null
: >"$work/exclude.txt"
for round in 1 2 3 4 5 6; do
  rm -rf src/classes
  "$bin/obdecl" "$work/classes.tsv" "$work/slots.tsv" "$work/deleting.tsv" "$work/known.tsv" --purecall 0x5d4a10 \
    --report "$work/report.tsv" --exclude "$work/exclude.txt" --shapes "$work/shapes.tsv" | head -1
  if tools/build.sh >"$work/build.log" 2>&1; then
    echo "round $round: clean"
    exit 0
  fi
  # src\classes\cUnk00a810e0.h(41) : error C2118: negative subscript  /  gen-hooks: src/classes/cUnk00a810e0.h: ...
  found=$(grep -E 'error C2118|gen-hooks: src/classes/' "$work/build.log" | grep -oE 'cUnk[0-9a-f]{8}' | sort -u || true)
  if [[ -z "$found" ]]; then
    echo "round $round: the build fails for another reason, see $work/build.log" >&2
    exit 1
  fi
  echo "round $round: excluding $(wc -w <<<"$found") classes"
  printf '%s\n' $found | sed 's/^cUnk//' >>"$work/exclude.txt"
done
echo "still failing after 6 rounds, see $work/build.log" >&2
exit 1
