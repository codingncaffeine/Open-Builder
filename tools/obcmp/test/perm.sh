#!/usr/bin/env bash
# Checks obperm end to end: in a copy of src/gzcom/cRZString.cpp, three matched functions are written in other valid
# spellings (BeginsWith with an early return, CompareTo's first two declarations swapped, Mid's compare flipped).
# Each must score above 0 as planted and come back to 0 within the time given.
#   tools/obcmp/test/perm.sh       exit 0 = every plant scored > 0 and was recovered
# Needs the toolkit and the test bed. Works in scratch/obperm-test/.
set -euo pipefail
root="$(cd "$(dirname "$0")/../../.." && pwd)"
cd "$root"
work=scratch/obperm-test
rm -rf "$work"
mkdir -p "$work"
f="$work/planted.cpp"
cp src/gzcom/cRZString.cpp "$f"
perl -0pi -e '
  $n += s/    if \(length <= size\(\)\) \{\n        for \(uint32_t i = 0; i < length; i\+\+\) \{\n            if \(\(\*this\)\[i\] != prefix\[i\]\) \{\n                return false;\n            \}\n        \}\n        return true;\n    \}\n    return false;\n/    if (length > size()) {\n        return false;\n    }\n    for (uint32_t i = 0; i < length; i++) {\n        if ((*this)[i] != prefix[i]) {\n            return false;\n        }\n    }\n    return true;\n/;
  $n += s/    uint32_t otherLength = other.Strlen\(\);\n    uint32_t length = size\(\);\n/    uint32_t length = size();\n    uint32_t otherLength = other.Strlen();\n/;
  $n += s/if \(start >= size\(\)\) \{\n        return cRZString\(\);/if (size() <= start) {\n        return cRZString();/;
  END { exit($n == 3 ? 0 : 1) }' "$f" || { echo "the plants no longer apply to cRZString.cpp" >&2; exit 2; }
status=0
for a in 0090e443 0090ee61 0090ea57; do
  log="$work/$a.log"
  scratch/build/obcmp/obperm "scratch/testbed/game/Apps/SimCity 4.exe" re/map/functions.tsv "$f" "$a" \
    --flags "/O1 /GX- /W3" --jobs 8 --seconds 300 --seed 1 --work "$work/$a" >"$log" 2>&1 || true
  start="$(awk '/^start:/ {print $2}' "$log")"
  if [[ "${start:-0}" -gt 0 ]] && grep -q '^MATCH' "$log"; then
    echo "$a: planted $start, $(tail -1 "$log" | cut -d' ' -f2-6)"
  else
    echo "$a: FAILED (start ${start:-?}): $(tail -1 "$log")"
    status=1
  fi
done
exit $status
