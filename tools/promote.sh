#!/usr/bin/env bash
# Promotes the CLOSE drafts of a file that now score 0 (after an edit that fixed a whole family): tools/score.sh
# scores the file, every "// CLOSE: 0x<address> score N" at score 0 becomes "// FUNCTION: 0x<address>" and leaves its
# #ifdef OB_DRAFTS, the others get their new score written in; then the file is scored once more and the counts
# before and after are printed. A backup copy sits beside the log in scratch/promote/.
#   tools/promote.sh <file.cpp> [--flags "..."]
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
file="${1:?file.cpp}"
shift
mkdir -p scratch/promote
cp "$file" "scratch/promote/$(basename "$file").before"
out=$(tools/score.sh "$file" "$@" 2>&1 || true)
grep -q ' at score 0 ' <<<"$out" || { echo "$out" | tail -5; echo "promote: the file does not score"; exit 2; }
echo "before: $(grep ' at score 0 ' <<<"$out")"
# "<address> <score>" of every CLOSE draft
awk '$2 == "CLOSE" { a = $1; sub(/^0x/, "", a); print a, $4 }' <<<"$out" >scratch/promote/scores.txt
awk -v scores=scratch/promote/scores.txt '
  BEGIN { while ((getline l < scores) > 0) { split(l, p, " "); s[p[1]] = p[2] } }
  /^#ifdef OB_DRAFTS$/ { held = $0; next }  # kept back until the next line says whether its draft is promoted
  /^\/\/ CLOSE: 0x[0-9a-fA-F]+ score [0-9]+/ {
    x = $3; sub(/^0x/, "", x); cur = sprintf("%08x", strtonum("0x" x))
    if ((cur in s) && s[cur] == 0) { print "// FUNCTION: 0x" cur; inside = (held != ""); held = ""; next }
    if (held != "") { print held; held = "" }
    if (cur in s) $5 = s[cur]
    print; next
  }
  held != "" { print held; held = "" }
  inside && /^}/ { print; drop = 1; inside = 0; next }
  drop { drop = 0; if ($0 == "#endif") next }
  { print }
  END { if (held != "") print held }' "$file" >"$file.promote-tmp"
[[ -s "$file.promote-tmp" ]] || { rm -f "$file.promote-tmp"; echo "promote: empty result, nothing changed"; exit 2; }
mv "$file.promote-tmp" "$file"
echo "after:  $(tools/score.sh "$file" "$@" 2>&1 | grep -E ' at score 0 |does not compile' || true)"
