#!/usr/bin/env bash
# Applies the `ask` lines of agent reports to the ext files of the classes they name:
#   ask <class> slot NAME RET [ARGS...]      → "slot NAME RET ARGS..."     in src/classes/ext/<class>.tsv
#   ask <class> field OFF TYPE NAME          → "field OFF TYPE NAME"       (OFF hex, NAME an identifier or array)
#   ask <class> method 0xADDR DECL           → "method 0xADDR DECL"
# A line already there is kept; a slot, field or method already set differently is printed and left alone; a line
# that is not of one of these shapes (prose) is printed and skipped. Then tools/regen-class.sh runs for every class
# touched. "ask types ..." lines are only printed (src/classes/ext/types.tsv is edited by hand).
#   tools/apply-asks.sh [--dry-run] scratch/packets/<class>/report.md ...
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
dry=0
[[ "${1:-}" == "--dry-run" ]] && { dry=1; shift; }
touched="$(mktemp)"
trap 'rm -f "$touched"' EXIT
ident='[A-Za-z_][A-Za-z0-9_]*'
type='(const )?[A-Za-z_][A-Za-z0-9_]*\*?'
for r in "$@"; do
  { grep -E '^[[:space:]]*ask ' "$r" || true; } | sed -E 's/^[[:space:]]+//; s/[[:space:]]*#.*$//; s/[[:space:]]+$//' | while IFS= read -r line; do
    read -r _ cls kind rest <<<"$line"
    [[ -n "$cls" && -n "$kind" ]] || continue
    if [[ "$cls" == types ]]; then echo "types (by hand): $line  [$r]"; continue; fi
    [[ -f "src/classes/$cls.h" ]] || { echo "no class header, skipped: $line  [$r]"; continue; }
    ext="src/classes/ext/$cls.tsv"
    key="$(awk '{print $1}' <<<"$rest")"
    new="$kind $rest"
    case "$kind" in
      slot)
        grep -qE "^slot $ident( $type)+$" <<<"$new" || { echo "not a slot line, skipped: $line  [$r]"; continue; }
        have="$(grep -E "^slot[[:space:]]+$key([[:space:]]|$)" "$ext" 2>/dev/null || true)" ;;
      field)
        grep -qE "^field [0-9a-fA-F]+ $type $ident(\[[0-9a-fx]+\])?$" <<<"$new" || { echo "not a field line, skipped: $line  [$r]"; continue; }
        have="$(grep -E "^field[[:space:]]+$key([[:space:]]|$)" "$ext" 2>/dev/null || true)" ;;
      method)
        grep -qE "^method 0x[0-9a-fA-F]+ .+\(.*\)$" <<<"$new" || { echo "not a method line, skipped: $line  [$r]"; continue; }
        have="$(grep -iE "^method[[:space:]]+$key([[:space:]]|$)" "$ext" 2>/dev/null || true)" ;;
      *) echo "unknown kind, skipped: $line  [$r]"; continue ;;
    esac
    if [[ -n "$have" ]]; then
      [[ "$(tr -s ' \t' ' ' <<<"$have")" == "$(tr -s ' \t' ' ' <<<"$new")" ]] || echo "already set, left: $ext: '$have' vs ask '$new'  [$r]"
      continue
    fi
    echo "+ $ext: $new"
    ((dry)) || { printf '%s\n' "$new" >>"$ext"; echo "$cls" >>"$touched"; }
  done
done
for cls in $(sort -u "$touched"); do
  if out="$(tools/regen-class.sh "$cls" 2>&1)"; then echo "regen $cls: ok"; else echo "regen $cls FAILED:"; echo "$out" | tail -5; fi
done
