#!/usr/bin/env bash
# Runs the permuter unattended over CLOSE drafts, lowest score first: for every "// CLOSE: 0x<address> score N" in the
# files given (default: every file under src/ with one), the file is copied with only that draft annotated FUNCTION,
# tools/obcmp/obperm searches spellings for --seconds with --jobs compiles at a time, and a match (exit 0) is taken
# back into the source: the permuter's best.cpp replaces the file, the function is taken out of its #ifdef OB_DRAFTS,
# and tools/score.sh must then show one more function at score 0 and none fewer, else the backup copy is restored.
# Drafts scoring above --max-score are skipped. Per draft: scratch/perm-batch/<address>/ (orig.cpp = the backup,
# obperm.log, perm/); the tally in scratch/perm-batch/summary.tsv.
#   tools/perm-batch.sh [--seconds N] [--jobs N] [--max-score N] [file.cpp ...]
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
seconds=120 jobs=8 maxscore=999999 minscore=1 files=()  # a CLOSE draft at score 0 is parked on purpose: left alone
while (($#)); do
  case "$1" in
    --seconds) seconds="$2"; shift 2 ;;
    --jobs) jobs="$2"; shift 2 ;;
    --max-score) maxscore="$2"; shift 2 ;;
    --min-score) minscore="$2"; shift 2 ;;
    *) files+=("$1"); shift ;;
  esac
done
((${#files[@]})) || mapfile -t files < <(grep -rlE '^// CLOSE: 0x' src | sort)
exe="scratch/testbed/game/Apps/SimCity 4.exe"
sizes=re/map/functions.tsv
[[ -f scratch/classes/sizes.tsv ]] && sizes=scratch/classes/sizes.tsv
log=scratch/perm-batch
mkdir -p "$log"
summary="$log/summary.tsv"
[[ -f "$summary" ]] || printf '# address\tfile\tscore before\tresult\tbest\tseconds\n' >"$summary"

# Every draft: "<file> <address> <score>", lowest score first.
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
for f in "${files[@]}"; do
  awk -v f="$f" '/^\/\/ CLOSE: 0x[0-9a-fA-F]+ score [0-9]+/ { x = $3; sub(/^0x/, "", x); print f "\t" sprintf("%08x", strtonum("0x" x)) "\t" $5 }' "$f"
done | awk -F'\t' -v max="$maxscore" -v min="$minscore" '$3 + 0 <= max + 0 && $3 + 0 >= min + 0' | sort -t$'\t' -k3,3n >"$work/drafts"
echo "$(wc -l <"$work/drafts") drafts ($minscore <= score <= $maxscore) in ${#files[@]} files; $seconds s and $jobs jobs each"

# "zero n" of a file as tools/score.sh counts them ("zero of n at score 0"); "- -" when it does not compile
scoreof() {
  local out
  out=$(tools/score.sh "$1" 2>&1 || true)
  awk '/ at score 0 / { print $1, $3; found = 1 } END { if (!found) print "- -" }' <<<"$out"
}
declare -A baseline
tried=0 matched=0
while IFS=$'\t' read -r f a score; do
  [[ -n "$a" ]] || continue
  if [[ -z "${baseline[$f]:-}" ]]; then
    baseline[$f]="$(scoreof "$f")"
    echo "$f: baseline ${baseline[$f]}"
  fi
  w="$log/$a"
  rm -rf "$w"
  mkdir -p "$w"
  cp "$f" "$w/orig.cpp"
  # the folder's flags, plus the file's own folder for its local includes (obperm compiles the copy from the root)
  d="$(dirname "$f")" flags="" dd="$(dirname "$f")"
  while [[ "$dd" == src* ]]; do
    [[ -f "$dd/FLAGS" ]] && { flags="$(grep -v '^#' "$dd/FLAGS" | tr '\n' ' ')"; break; }
    dd="$(dirname "$dd")"
  done
  flags="${flags:-/O2 /GX- /W3} /I$d"
  copy="$w/$(basename "$f")"
  awk -v a="$a" '/^\/\/ CLOSE: 0x[0-9a-fA-F]+ score/ { x = $3; sub(/^0x/, "", x); if (sprintf("%08x", strtonum("0x" x)) == a) { print "// FUNCTION: 0x" a; next } } { print }' "$f" >"$copy"
  tried=$((tried + 1))
  t0=$(date +%s)
  printf '%s %s score %s: ' "$f" "$a" "$score"
  if timeout -k 10 "$((seconds + 180))" scratch/build/obcmp/obperm "$exe" "$sizes" "$copy" "$a" --work "$w/perm" \
       --seconds "$seconds" --jobs "$jobs" --flags "$flags" >"$w/obperm.log" 2>&1; then
    result=match
  else
    result=none
  fi
  best=$(grep -oE '^best: score [0-9]+' "$w/obperm.log" | tail -1 | awk '{print $3}')
  dt=$(( $(date +%s) - t0 ))
  if [[ "$result" == match ]]; then
    # best.cpp: the copy with the matching body; the function leaves its #ifdef OB_DRAFTS (the #ifdef right above
    # its annotation and the #endif after its closing brace in column 0)
    awk -v a="$a" '
      held != "" { if ($0 == "// FUNCTION: 0x" a) { inside = 1 } else print held; held = "" }
      /^#ifdef OB_DRAFTS$/ { held = $0; next }
      inside && /^}/ { print; drop = 1; inside = 0; next }
      drop { drop = 0; if ($0 == "#endif") next }
      { print }
      END { if (held != "") print held }' "$w/perm/best.cpp" >"$f"
    now="$(scoreof "$f")"
    read -r bz bn <<<"${baseline[$f]}"
    read -r nz nn <<<"$now"
    if [[ "$nz" != "-" && "$bz" != "-" && "$nn" == "$bn" && "$nz" -gt "$bz" ]]; then
      baseline[$f]="$now"
      matched=$((matched + 1))
      echo "MATCHED (file now $now)"
    else
      cp "$w/orig.cpp" "$f"
      result="match-but-regressed ($now vs ${baseline[$f]})"
      echo "$result: restored"
    fi
  else
    echo "no match (best ${best:-?})"
  fi
  printf '%s\t%s\t%s\t%s\t%s\t%s\n' "$a" "$f" "$score" "$result" "${best:-?}" "$dt" >>"$summary"
done <"$work/drafts"
echo "tried $tried, matched $matched (summary: $summary)"
