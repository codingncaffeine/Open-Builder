#!/usr/bin/env bash
# Builds work packets for decompiling generated classes: for each class, every method it declares that is still
# the original's code (a stub in src/classes/stubs.txt, real code by tools/triage.sh), with
#   functions.tsv   address, size, folder (game or gzcom: the flags its class was built with), declaration
#   <address>.asm   the original's instructions, calls and addresses named where we know them
#   <address>.c     Ghidra's decompilation (a draft: types and names are guesses)
# in scratch/packets/<class>/. One Ghidra run serves every class given.
#   tools/packet.sh cUnk00a87dd0 [cUnk... ...]
#   tools/packet.sh --pick N [MAXSIZE] [MIN-MAX]   N classes with MIN to MAX (default 6-20) such methods of at most
#                                                MAXSIZE bytes each, the most first
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
exe="scratch/testbed/game/Apps/SimCity 4.exe"
out=scratch/packets
mkdir -p "$out"
tools/triage.sh --list >/dev/null  # re/map/triage.tsv
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT

# Names: what the stubs and the annotations call each address, demangled ("0x<address>\t<name>").
grep -rhoE '^0x[0-9a-fA-F]+[[:space:]]+\S+' hook/stubs.txt src/classes/stubs.txt | awk '{print tolower($1) "\t" $2}' >"$work/stubs"
paste <(cut -f1 "$work/stubs") <(cut -f2 "$work/stubs" | llvm-undname 2>/dev/null | awk 'BEGIN { RS = ""; FS = "\n" } { print ($2 != "" ? $2 : $1) }') >"$work/names"
for f in $(grep -rlE '// (FUNCTION|SYNTHETIC): 0x' src); do
  awk '/\/\/ (FUNCTION|SYNTHETIC): 0x/ { match($0, /0x[0-9a-fA-F]+/); a = tolower(substr($0, RSTART, RLENGTH)); p = 1; next }
       p { s = $0; sub(/^[ \t\/]*/, "", s); sub(/[ \t]*\{?[ \t]*$/, "", s); printf "0x%08x\t%s\n", strtonum(a), s; p = 0 }' "$f"
done >>"$work/names"
awk '{printf "0x%08x\t%s\n", strtonum("0x" $1), $3 " (library)"}' re/map/libraries.tsv >>"$work/names" 2>/dev/null || true
awk -F'\t' '{ a = sprintf("0x%08x", strtonum($1)); if (!(a in n)) { n[a] = $2; print a "\t" $2 } }' "$work/names" >"$out/names.tsv"

# Candidates: stubbed methods of generated classes whose code is still to do and is real code.
# sizes: the function list corrected where it ends a function early (scratch/classes/sizes.tsv, by gen-classes.sh)
sizes=re/map/functions.tsv
[[ -f scratch/classes/sizes.tsv ]] && sizes=scratch/classes/sizes.tsv
awk -F'\t' 'FILENAME ~ /sizes.tsv$|functions.tsv$/ { real[sprintf("%08x", strtonum("0x" $1))] = strtonum("0x" $2); next }
            FILENAME ~ /triage/ { a = sprintf("%08x", strtonum("0x" $1)); if ($3 == "code") code[a] = (a in real) ? real[a] : $2; next }
            { a = tolower($1); sub(/^0x/, "", a); a = sprintf("%08x", strtonum("0x" a))
              if (!(a in code)) next
              cls = $2; sub(/^\?[^@]*@/, "", cls); sub(/@@.*/, "", cls); sub(/_[0-9a-f]+$/, "", cls)
              if (cls !~ /^cUnk[0-9a-f]{8}$/) next
              print cls "\t" a "\t" code[a] "\t" $2 }' "$sizes" re/map/triage.tsv "$work/stubs" | sort -u >"$work/candidates"

classes=()
if [[ "${1:-}" == "--pick" ]]; then
  n="${2:?how many}" max="${3:-400}" range="${4:-6-20}"
  done_list="$(ls "$out" 2>/dev/null | grep '^cUnk' || true)"
  mapfile -t classes < <(awk -F'\t' -v max="$max" -v lo="${range%-*}" -v hi="${range#*-}" '$3 <= max { c[$1]++ } END { for (k in c) if (c[k] >= lo && c[k] <= hi) print c[k] "\t" k }' "$work/candidates" |
    sort -k1,1nr -k2 | cut -f2 | grep -vxF -f <(printf '%s\n' $done_list "") | head -n "$n")
else
  classes=("$@")
fi
((${#classes[@]})) || { echo "no classes" >&2; exit 2; }

: >"$work/all-addresses"
for cls in "${classes[@]}"; do
  dir="$out/$cls"
  mkdir -p "$dir"
  rm -f "$dir"/*.asm "$dir"/*.c  # listings of an earlier packet (its report.md stays)
  # one line per function (a function several decorated names share is one function)
  awk -F'\t' -v c="$cls" '$1 == c && !seen[$2]++' "$work/candidates" >"$work/$cls"
  # The folder (its flags) from where the original put the functions: the game was built with function-level linking
  # (every function 16-aligned), the framework packed; most of a class's methods off a 16-byte boundary = framework.
  folder=$(awk -F'\t' '{ n++; if (strtonum("0x" $2) % 16) u++ } END { print (u * 2 > n ? "gzcom" : "game") }' "$work/$cls")
  paste <(cut -f2 "$work/$cls") <(cut -f3 "$work/$cls") <(cut -f4 "$work/$cls" | llvm-undname 2>/dev/null | awk 'BEGIN { RS = ""; FS = "\n" } { print ($2 != "" ? $2 : $1) }') |
    awk -F'\t' -v f="$folder" '{ print "0x" $1 "\t" $2 "\t" f "\t" $3 }' >"$dir/functions.tsv"
  cut -f2 "$work/$cls" >>"$work/all-addresses"
  # the original's instructions, with names
  while IFS=$'\t' read -r a size _ _; do
    objdump -d -M intel --no-show-raw-insn --start-address="$a" --stop-address="$((a + size))" "$exe" |
      awk -F'\t' 'FILENAME ~ /names.tsv$/ { n[$1] = $2; next }
        /^ *[0-9a-f]+:\t/ {
          line = $2
          if (match(line, /0x[0-9a-f]+/) || match(line, /^(call|jmp) +[0-9a-f]+/)) {
            s = line; out = ""
            while (match(s, /(0x)?[0-9a-f]{6,8}/)) {
              h = substr(s, RSTART, RLENGTH); v = sprintf("0x%08x", strtonum(h ~ /^0x/ ? h : "0x" h))
              out = out substr(s, 1, RSTART + RLENGTH - 1) ((v in n) ? " <" n[v] ">" : "")
              s = substr(s, RSTART + RLENGTH)
            }
            line = out s
          }
          sub(/^ +/, "", $1); print $1 "\t" line
        }' "$out/names.tsv" - >"$dir/${a#0x}.asm"
  done <"$dir/functions.tsv"
done

# Ghidra's drafts, one run for all.
mapfile -t addrs <"$work/all-addresses"
ghidra-analyzeHeadless re/ghidra OpenBuilder -process "SimCity 4.exe" -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript Decompile.java "${addrs[@]}" >"$work/ghidra.log" 2>&1 || true
for cls in "${classes[@]}"; do
  while IFS=$'\t' read -r a _ _ _; do
    awk -v want="${a#0x}" '
      /=== / { s = $0; sub(/.*=== /, "", s); split(s, w, /[ :]/); cur = w[1]; sub(/^0x/, "", cur); keep = (sprintf("%08x", strtonum("0x" cur)) == want); next }
      keep && /Decompile.java>|INFO|^ *$/ && !/Decompile.java> / { next }
      keep { s = $0; sub(/^.*Decompile\.java> /, "", s); print s }' "$work/ghidra.log" >"$out/$cls/${a#0x}.c"
  done <"$out/$cls/functions.tsv"
  echo "$out/$cls: $(wc -l <"$out/$cls/functions.tsv") functions"
done
