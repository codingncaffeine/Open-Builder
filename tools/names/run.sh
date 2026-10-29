#!/usr/bin/env bash
# Names the original's functions and classes from the Mac reference build: feature tables for both builds, then
# tools/obcmp/obname. Output in re/names/ (local, never committed).
#   tools/names/run.sh [--tables]     --tables also rebuilds the reference build's tables (slow part, ~15 s)
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$root"
bin=scratch/build/obcmp
exe="scratch/testbed/game/Apps/SimCity 4.exe"
if [[ "${1:-}" == --tables || ! -s re/names/mac/feat.tsv ]]; then
  tools/names/mac-tables.sh
  tools/names/mac-features.sh
fi
mkdir -p re/names/win
"$bin/obfeat" "$exe" scratch/classes/sizes.tsv --vtables re/map/vtables.tsv >re/names/win/feat.tsv
# BSim's nearest reference functions (tools/names/bsim.sh), the call-graph stage's tie-breaker, when made
bsim=()
[[ -s re/names/bsim.tsv ]] && bsim=(--bsim re/names/bsim.tsv)
"$bin/obname" --win-feat re/names/win/feat.tsv --win-slots scratch/classes/slots.tsv \
  --win-shapes scratch/classes/shapes.tsv --win-classes scratch/classes/classes.tsv \
  --mac-feat re/names/mac/feat.tsv --mac-funcs re/names/mac/funcs.tsv --mac-vtables re/names/mac/vtables.tsv \
  --out re/names --truth-lib re/map/libraries.tsv --truth-known scratch/classes/known.tsv "${bsim[@]}"
