#!/usr/bin/env bash
# Names the original's service pointers (the reference build's SL::spCity, SL::spMS2, ...): for every function pair
# tools/names/run.sh found (re/names/functions.tsv) where each side reads exactly one such pointer, a vote for that
# address; an address takes the name most of its votes give. Writes re/names/globals.tsv: address, name, votes for it /
# all its votes (local, never committed). Read by tools/packet.sh.
#   tools/names/sl-globals.sh
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$root"
exe="scratch/testbed/game/Apps/SimCity 4.exe"
code=scratch/downloads/sc4-research-mac/artifacts/code/Mac-RevA-x86-named/functions
work=scratch/names/sl
mkdir -p "$work"
# the reference build: SL pointers each function reads (its pseudocode names them PTR___ZN2SL<n><name>E_<address>)
command grep -roE "PTR___ZN2SL[0-9]+[A-Za-z0-9_]+E_[0-9a-f]{8}" "$code" |
  sed -E 's|.*/([0-9a-f]+)\.c:PTR___ZN2SL[0-9]+([A-Za-z0-9_]+)E_.*|\1\t\2|' | sort -u >"$work/mac-uses.tsv"
# the original: the 0xb4xxxx data each function reads (where the service pointers live)
llvm-objdump -d --no-show-raw-insn -M intel "$exe" 2>/dev/null |
  awk 'FNR == NR { start[++n] = strtonum("0x" $1); next }
       /\[0xb4[0-9a-f]{4}\]/ {
         s = $1; sub(/:$/, "", s); a = strtonum("0x" s)
         while (k < n && start[k + 1] <= a) k++
         if (match($0, /\[0xb4[0-9a-f]{4}\]/)) print sprintf("%x", start[k]) "\t" substr($0, RSTART + 3, 6)
       }' <(awk '{ printf "%08x\n", strtonum("0x" $1) }' scratch/classes/sizes.tsv | sort -u) - | sort -u >"$work/win-uses.tsv"
awk -F'\t' 'FILENAME == ARGV[1] { w[$1] = w[$1] " " $2; wn[$1]++; next }
            FILENAME == ARGV[2] { m[$1] = m[$1] " " $2; mn[$1]++; next }
            $4 != "-" && $4 != "" && wn[$1] == 1 && mn[$4] == 1 {
              g = substr(w[$1], 2); s = substr(m[$4], 2); v[g "\t" s]++; tot[g]++
            }
            END {
              for (k in v) { split(k, p, "\t"); if (v[k] > best[p[1]]) { best[p[1]] = v[k]; nm[p[1]] = p[2] } }
              for (g in best) if (best[g] * 2 > tot[g]) printf "%s\t%s\t%d/%d\n", g, nm[g], best[g], tot[g]
            }' "$work/win-uses.tsv" "$work/mac-uses.tsv" re/names/functions.tsv | sort >re/names/globals.tsv
echo "$(wc -l <re/names/globals.tsv) service pointers named"
