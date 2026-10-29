#!/usr/bin/env bash
# Tables of the Mac reference build (a debug-symbol build of the same game, used only to NAME things here): every
# function with its demangled name, and every vtable's slots in order.
#   tools/names/mac-tables.sh [<research dir>]
# Input (local, never committed): the sc4-research Mac package unpacked under scratch/downloads/sc4-research-mac.
# Output in re/names/mac/:
#   funcs.tsv    addr  bytes  demangled-name            (one line per function; Ghidra's name when no symbol)
#   vtables.tsv  vtable-symbol-addr  class  part  index  slot-addr  target  target-name
#                part 0 = primary, 1.. = secondary tables in order; index from 0 within the part. A slot Ghidra left
#                without a reference is listed as target 00000000, name "?", so the indices stay exact.
# A table's parts start where the constructors point an object's vtable pointers (absolute or position-independent
# addresses inside the table); a table no code points into is split at two or more dwords without a code reference
# (offset to top, typeinfo).
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$root"
R="${1:-scratch/downloads/sc4-research-mac/artifacts}"
C="$R/code/Mac-RevA-x86-named"
S="$R/symbols/mac/x86"
O=re/names/mac
mkdir -p "$O"

# Functions: Ghidra's list, renamed with the symbol table's demangled form where one exists at the address.
awk -F'\t' '
  FNR==1 { next }
  FILENAME ~ /symbols\/mac\/x86\/functions.tsv$/ {
      if ($3 ~ /\(/ && !($1 in dem)) dem[$1]=$3; next }
  { n=$2; if ($1 in dem) n=dem[$1]; print $1 "\t" $3 "\t" n }
' "$S/functions.tsv" "$C/functions.tsv" | sort -u -k1,1 >"$O/funcs.tsv"

# Every symbol with an address (for extents): address, mangled, demangled.
awk -F'\t' 'NR>1 && $5!="00000000" && $3!="0" { print $5 "\t" $6 "\t" $7 }' "$S/symbols.tsv" | sort -u >"$O/.syms"

# Vtable pointer values the code uses: absolute immediates, and [reg + disp] after a pc thunk (position-independent).
awk -F'\t' -v SYMS="$O/.syms" '
  BEGIN {
      while ((getline l < SYMS) > 0) { split(l, p, "\t"); n++; a[n] = strtonum("0x" p[1]); nm[n] = p[2] }
      for (i = 1; i <= n; i++) if (nm[i] ~ /^__ZTV/) {
          e = a[i] + 0x4000; for (j = i + 1; j <= n; j++) if (a[j] > a[i]) { e = a[j]; break }
          nv++; vs[nv] = a[i]; ve[nv] = e
      }
      thunk[strtonum("0x005edba0")] = "EBX"; thunk[strtonum("0x0082f11e")] = "ECX"; thunk[strtonum("0x008304a0")] = "EDX"
  }
  function inside(t,   lo, hi, mid) {
      lo = 1; hi = nv
      while (lo <= hi) { mid = int((lo + hi) / 2); if (vs[mid] <= t) lo = mid + 1; else hi = mid - 1 }
      return hi >= 1 && t >= vs[hi] + 8 && t < ve[hi]
  }
  /^;/ { next }
  {
      t = $3; sp = index(t, " "); op = (sp ? substr(t, 1, sp - 1) : t); args = (sp ? substr(t, sp + 1) : "")
      if (op == "PUSH" && args == "EBP") delete pic
      if (op == "CALL") { tv = strtonum(args); if (tv in thunk) { pic[thunk[tv]] = strtonum("0x" $1) + length($2) / 2; next } }
      rest = args
      while (match(rest, /0x[0-9a-f]+/)) {
          v = strtonum(substr(rest, RSTART, RLENGTH)); pre = substr(rest, 1, RSTART - 1); rest = substr(rest, RSTART + RLENGTH)
          if (pre ~ /\[E[A-DS][XIP] \+ -?$/) {
              split(pre, q, "["); r = substr(q[length(q)], 1, 3)
              if (!(r in pic)) continue
              v = (pre ~ /-$/) ? pic[r] - v : pic[r] + v
          } else if (pre ~ /\[[^]]*$/) continue
          if (inside(v)) printf "%08x\n", v
      }
  }
' "$C/instructions.asm" | sort -u >"$O/.vptrs"

awk -F'\t' -v FUNCS="$O/funcs.tsv" -v VPTRS="$O/.vptrs" '
  BEGIN {
      while ((getline l < FUNCS) > 0) { split(l, f, "\t"); fname[f[1]] = f[3] }
      while ((getline l < VPTRS) > 0) vptr[strtonum("0x" l)] = 1
  }
  FILENAME ~ /\.syms$/ { a = strtonum("0x" $1); nsym++; saddr[nsym] = a; sname[nsym] = $2; sdem[nsym] = $3; next }
  FNR==1 { next }
  { ref[strtonum("0x" $1)] = $2 }
  END {
      for (i = 1; i <= nsym; i++) {
          if (sname[i] !~ /^__ZTV/) continue
          start = saddr[i]; end = start + 0x4000
          for (j = i + 1; j <= nsym; j++) if (saddr[j] > start) { end = saddr[j]; break }
          cls = sdem[i]; sub(/^vtable for /, "", cls)
          # part starts: +8, then every vtable pointer the code uses; without any beyond +8, the gap rule
          np = 0; for (a = start + 8; a < end; a += 4) if (a == start + 8 || (a in vptr)) ps[++np] = a
          if (np == 1) {
              gap = 0; seen = 0
              for (a = start + 8; a < end; a += 4) {
                  t = (a in ref) ? ref[a] : ""
                  if (t != "" && (t in fname)) { if (gap >= 2 && seen) ps[++np] = a; gap = 0; seen = 1 } else gap++
              }
          }
          for (p = 1; p <= np; p++) {
              pe = (p < np) ? ps[p + 1] - 8 : end
              last = -1
              for (a = ps[p]; a < pe; a += 4) { t = (a in ref) ? ref[a] : ""; if (t != "" && (t in fname)) last = a }
              if (p < np) last = pe - 4  # a part followed by another: its length is known
              for (a = ps[p]; a <= last; a += 4) {
                  t = (a in ref) ? ref[a] : ""
                  if (t != "" && (t in fname)) printf "%08x\t%s\t%d\t%d\t%08x\t%s\t%s\n", start, cls, p - 1, (a - ps[p]) / 4, a, t, fname[t]
                  else printf "%08x\t%s\t%d\t%d\t%08x\t00000000\t?\n", start, cls, p - 1, (a - ps[p]) / 4, a
              }
          }
          delete ps
      }
  }
' "$O/.syms" "$C/data-references.tsv" >"$O/vtables.tsv"
rm -f "$O/.syms" "$O/.vptrs"
echo "mac: $(wc -l <"$O/funcs.tsv") functions, $(cut -f1 "$O/vtables.tsv" | sort -u | wc -l) vtables, $(wc -l <"$O/vtables.tsv") slots ($(awk -F'\t' '$7=="?"' "$O/vtables.tsv" | wc -l) unknown)"
