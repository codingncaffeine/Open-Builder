#!/usr/bin/env bash
# Analyses a binary in a throwaway Ghidra project and writes its function list (tools/ghidra/ExportFunctions.java).
#   tools/ghidra/functions.sh <binary> <out.tsv> [seeds.txt]
# seeds.txt: hex addresses to make functions of before analysis (tools/ghidra/SeedFunctions.java), e.g. a /MAP's.
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
bin="$(realpath "$1")" out="$(realpath -m "$2")"
seed=()
[[ -n "${3:-}" ]] && seed=(-preScript SeedFunctions.java "$(realpath "$3")")
proj="$root/scratch/ghidra-tmp/$(basename "$out" .tsv)"
rm -rf "$proj"; mkdir -p "$proj"
/opt/ghidra/support/analyzeHeadless "$proj" tmp -import "$bin" -scriptPath "$root/tools/ghidra" "${seed[@]}" \
  -postScript ExportFunctions.java "$out" -deleteProject -log "$proj/ghidra.log" >/dev/null 2>&1 \
  || { echo "ghidra failed, see $proj/ghidra.log" >&2; exit 1; }
grep -oE 'seeded [0-9]+ functions|exported [0-9]+ functions' "$proj/ghidra.log"
rm -rf "$proj"
