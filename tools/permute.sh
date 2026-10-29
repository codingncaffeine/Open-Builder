#!/usr/bin/env bash
# Searches spellings of one decompiled function until the 2003 compiler matches the original (tools/obcmp/obperm).
#   tools/permute.sh <address> <file.cpp> [obperm options: --jobs N --seconds N --tries N --seed N --flags "..."]
# The function is the definition after "// FUNCTION: 0x<address>" in file.cpp. The best spelling goes to
# scratch/perm/<address>/best.cpp (the whole file); copy its body back by hand, keeping your comments. Exit 0 = match.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
addr="${1:?address}" file="${2:?file.cpp}"
shift 2
addr="$(printf '%08x' "$((16#${addr#0x}))")"
# sizes: the function list corrected where it ends a function early (tools/obcmp/obshape --sizes, by gen-classes.sh)
sizes=re/map/functions.tsv
[[ -f scratch/classes/sizes.tsv ]] && sizes=scratch/classes/sizes.tsv
exec scratch/build/obcmp/obperm "scratch/testbed/game/Apps/SimCity 4.exe" "$sizes" "$file" "$addr" \
  --work "scratch/perm/$addr" "$@"
