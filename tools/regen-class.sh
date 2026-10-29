#!/usr/bin/env bash
# Rewrites one generated class's header (src/classes/<class>.h) after its src/classes/ext/<class>.tsv changed, from
# the class map tools/gen-classes.sh last built (scratch/classes). Nothing else is written, so it is safe while other
# classes are being worked on; tools/gen-classes.sh regenerates everything when the work is brought together.
#   tools/regen-class.sh cSC4CrimeSimulator
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
cls="${1:?class name, e.g. cSC4CrimeSimulator}"
w=scratch/classes
[[ -f "$w/classes.tsv" && -f "$w/shapes.tsv" ]] || { echo "run tools/gen-classes.sh first" >&2; exit 2; }
# the same inputs gen-classes.sh gives it: without the names a named class is not found and nothing is written
opts=()
[[ -s src/classes/names.tsv ]] && opts+=(--names src/classes/names.tsv)
[[ -s "$w/extents.tsv" ]] && opts+=(--extents "$w/extents.tsv")
out=$(scratch/build/obcmp/obdecl "$w/classes.tsv" "$w/slots.tsv" "$w/deleting.tsv" "$w/known.tsv" --purecall 0x5d4a10 \
  --exclude "$w/exclude.txt" --shapes "$w/shapes.tsv" "${opts[@]}" --only "$cls")
if ! grep -q '^classes written 1 ' <<<"$out"; then
  echo "regen-class: nothing written for $cls:" >&2
  echo "$out" >&2
  exit 1
fi
echo "wrote src/classes/$cls.h"
