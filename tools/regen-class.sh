#!/usr/bin/env bash
# Rewrites one generated class's header (src/classes/<class>.h) after its src/classes/ext/<class>.tsv changed, from
# the class map tools/gen-classes.sh last built (scratch/classes). Nothing else is written, so it is safe while other
# classes are being worked on; tools/gen-classes.sh regenerates everything when the work is brought together.
#   tools/regen-class.sh cUnk00a858d0
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
cls="${1:?class name, e.g. cUnk00a858d0}"
w=scratch/classes
[[ -f "$w/classes.tsv" && -f "$w/shapes.tsv" ]] || { echo "run tools/gen-classes.sh first" >&2; exit 2; }
scratch/build/obcmp/obdecl "$w/classes.tsv" "$w/slots.tsv" "$w/deleting.tsv" "$w/known.tsv" --purecall 0x5d4a10 \
  --exclude "$w/exclude.txt" --shapes "$w/shapes.tsv" --only "$cls" >/dev/null
echo "wrote src/classes/$cls.h"
