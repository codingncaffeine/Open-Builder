#!/usr/bin/env bash
# Pairs the original's functions with the reference build's by what their code does (Ghidra's BSim): the reference
# build's program (its symbols name every function) goes into a local BSim database, then every function of the
# original asks it for its nearest ones. Same source, other compiler: BSim's design case. For the functions no
# vtable, string or call-graph position names (tools/names/run.sh).
# Defaults chosen 2026-10-29 by a hold-out and the Lua truth set: 0.3 and 3 (0.5: 100% but 839 fewer names; 0.3 and 5:
# one hold-out error more for 10 names).
#   tools/names/bsim.sh [similarity floor, default 0.3] [candidates per function, default 3] [out, default re/names/bsim.tsv]
# Needs the reference build analysed in its own project (re/ghidra-mac/MacRevA, imported from the public Rev A patch:
# scratch/downloads/mac-reva/SC4RH-i386). Writes re/bsim/ (the database) and re/names/bsim.tsv (BSimPairs.java's
# lines); local, never committed.
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$root"
floor="${1:-0.3}" per="${2:-3}" out="${3:-re/names/bsim.tsv}"
bsim=/opt/ghidra/support/bsim
db="file:$root/re/bsim/sc4"
[[ -d re/ghidra-mac/MacRevA.rep ]] || { echo "bsim: import the reference build first (re/ghidra-mac/MacRevA)" >&2; exit 2; }
mkdir -p re/bsim re/names
# a Ghidra URL takes the path URL-encoded (the folder name has a space)
project="ghidra:${root// /%20}/re/ghidra-mac/MacRevA"
[[ -f re/bsim/sc4.mv.db ]] || "$bsim" createdatabase "$db" medium_32 --name sc4 >re/bsim/create.log 2>&1
if [[ ! -f re/bsim/sigs.done ]]; then
  "$bsim" generatesigs "$project" --bsim "$db" >re/bsim/sigs.log 2>&1 || { echo "bsim: signatures failed, see re/bsim/sigs.log" >&2; exit 1; }
  touch re/bsim/sigs.done
fi
"$bsim" getexecount "$db" 2>/dev/null | tail -1
ghidra-analyzeHeadless re/ghidra OpenBuilder -process "SimCity 4.exe" -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript BSimPairs.java "$db" "$(realpath -m "$out")" "$floor" "$per" >re/bsim/query.log 2>&1 \
  || { echo "bsim: query failed, see re/bsim/query.log" >&2; exit 1; }
grep -oE 'BSimPairs: [0-9]+ functions answered.*' re/bsim/query.log
