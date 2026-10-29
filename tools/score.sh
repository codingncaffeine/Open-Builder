#!/usr/bin/env bash
# Scores every function of one source file against the original in one compile: each "// FUNCTION: 0x..." and each
# "// CLOSE: 0x... score N" draft, one line each, then the totals. Also compiles the file with the other folder's
# flags (/O1 vs /O2) and says when those match better (a class in the wrong folder).
#   tools/score.sh <file.cpp> [--flags "..."]      exit 0 = every function scores 0
# Listings per function as with permute.sh: scratch/perm/<address>/want.txt (original) vs j0/got.txt (ours).
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
file="${1:?file.cpp}"
shift
flags=""
[[ "${1:-}" == "--flags" ]] && flags="${2:?flags}"
if [[ -z "$flags" ]]; then  # the nearest FLAGS file above the source, as build.sh and obperm pick them
  d="$(dirname "$file")"
  while [[ "$d" == src* ]]; do
    [[ -f "$d/FLAGS" ]] && { flags="$(grep -v '^#' "$d/FLAGS" | tr '\n' ' ')"; break; }
    d="$(dirname "$d")"
  done
  flags="${flags:-/O2 /GX- /W3}"
fi
other="$(sed 's|/O1|/OX|; s|/O2|/O1|; s|/OX|/O2|' <<<"$flags")"
exe="scratch/testbed/game/Apps/SimCity 4.exe"
sizes=re/map/functions.tsv
[[ -f scratch/classes/sizes.tsv ]] && sizes=scratch/classes/sizes.tsv
work="scratch/score/$(basename "$file" .cpp)"
rm -rf "$work"
mkdir -p "$work"
# A copy where the drafts are annotated too (obperm finds a function by its annotation); its includes resolve from
# the source's own folder (/I below).
copy="$work/$(basename "$file")"
sed -E 's|^// CLOSE: (0x[0-9a-fA-F]+).*|// FUNCTION: \1|' "$file" >"$copy"
# The options obperm compiles with (tools/obcmp/obperm.cpp, "common").
common=(/nologo /c /Isdk /Isrc /Ihook /Ithird_party/stlport-4.6/stlport /D_STLP_DONT_FORCE_MSVC_LIB_NAME
  /D_STLP_USE_NEWALLOC /D_STLP_OUT_OF_LINE_STL_NEW /D_STLP_RESIZE_BY_REFERENCE "/I$(dirname "$file")")
compile() {  # flags, object
  # shellcheck disable=SC2086
  timeout -k 5 120 tools/vc71.sh cl "${common[@]}" $1 "/Fo$2" "$copy" >"$2.log" 2>&1 || true
  [[ -f "$2" ]]
}
compile "$flags" "$work/t.obj" || { grep -E 'error|fatal' "$work/t.obj.log" | head -20; echo "does not compile"; exit 2; }
compile "$other" "$work/other.obj" || true
addrs=$(grep -oE '^// (FUNCTION|CLOSE): 0x[0-9a-fA-F]+' "$file" | awk '{print $2 " " $3}')
total=0 zero=0 n=0 better=0
while read -r kind addr; do
  [[ -n "$addr" ]] || continue
  a="$(printf '%08x' "$((16#${addr#0x}))")"
  s=$(scratch/build/obcmp/obperm "$exe" "$sizes" "$copy" "$a" --obj "$work/t.obj" --work "scratch/perm/$a" 2>&1 |
    awk '/^start:/ {print $2 " " $4; exit}' || true)
  [[ -n "$s" ]] || { printf '0x%s  %-9s cannot be scored (no symbol, or not in the function list)\n' "$a" "$kind"; continue; }
  read -r score orig <<<"$s"
  o=""
  if [[ -f "$work/other.obj" ]]; then
    so=$(scratch/build/obcmp/obperm "$exe" "$sizes" "$copy" "$a" --obj "$work/other.obj" --work "$work/other-$a" 2>&1 |
      awk '/^start:/ {print $2; exit}' || true)
    [[ -n "$so" && "$so" -lt "$score" ]] && { o="  (other flags: $so)"; better=$((better + 1)); }
  fi
  printf '0x%s  %-9s score %-4s (original %s)%s\n' "$a" "$kind" "$score" "$orig" "$o"
  n=$((n + 1)) total=$((total + score))
  [[ "$score" -eq 0 ]] && zero=$((zero + 1))
done <<<"${addrs//:/}"
echo "$zero of $n at score 0 (total $total) with $flags"
[[ $better -gt 0 ]] && echo "$better score better with $other: is the class in the wrong folder? (try --flags \"$other\")"
[[ $zero -eq $n ]]
