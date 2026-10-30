#!/usr/bin/env bash
# Applies the `ask` lines of agent reports to the ext files of the classes they name: "ask <class> slot NAME RET ARGS..."
# and "ask <class> field OFF TYPE NAME" become `slot`/`field` lines in src/classes/ext/<class>.tsv (a line already
# there is kept; a slot or field already set differently is printed and left alone), then tools/regen-class.sh runs
# for each class touched. "ask types ..." lines are only printed (src/classes/ext/types.tsv is edited by hand).
#   tools/apply-asks.sh scratch/packets/<class>/report.md ...      (--dry-run: print, change nothing)
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
dry=0
[[ "${1:-}" == "--dry-run" ]] && { dry=1; shift; }
declare -A touched
for r in "$@"; do
  grep -E '^ask ' "$r" | sed -E 's/[[:space:]]*#.*$//' | while IFS= read -r line; do
    read -r _ cls kind rest <<<"$line"
    [[ -n "$cls" && -n "$kind" ]] || continue
    if [[ "$cls" == types ]]; then echo "types (by hand): $line  [$r]"; continue; fi
    [[ -f "src/classes/$cls.h" ]] || { echo "no class header: $line  [$r]"; continue; }
    ext="src/classes/ext/$cls.tsv"
    key="$(awk '{print $1}' <<<"$rest")"
    new="$kind $rest"
    case "$kind" in
      slot)
        have="$(grep -E "^slot[[:space:]]+$key([[:space:]]|$)" "$ext" 2>/dev/null || true)" ;;
      field)
        have="$(grep -E "^field[[:space:]]+$key([[:space:]]|$)" "$ext" 2>/dev/null || true)" ;;
      method)  # "method 0xADDR DECL": keyed by the address
        have="$(grep -iE "^method[[:space:]]+$key([[:space:]]|$)" "$ext" 2>/dev/null || true)" ;;
      *) echo "unknown kind: $line  [$r]"; continue ;;
    esac
    if [[ -n "$have" ]]; then
      [[ "$(tr -s ' \t' ' ' <<<"$have")" == "$(tr -s ' \t' ' ' <<<"$new")" ]] || echo "already set, left: $ext: '$have' vs ask '$new'  [$r]"
      continue
    fi
    echo "+ $ext: $new"
    ((dry)) || { printf '%s\n' "$new" >>"$ext"; echo "$cls" >>"${TMPDIR:-/tmp}/apply-asks.$$"; }
  done
done
if [[ -f "${TMPDIR:-/tmp}/apply-asks.$$" ]]; then
  for cls in $(sort -u "${TMPDIR:-/tmp}/apply-asks.$$"); do
    tools/regen-class.sh "$cls" || echo "regen-class failed for $cls: check $ext"
  done
  rm -f "${TMPDIR:-/tmp}/apply-asks.$$"
fi
