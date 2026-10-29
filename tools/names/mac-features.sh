#!/usr/bin/env bash
# Features of every function of the Mac reference build, for pairing its functions with the original's:
#   tools/names/mac-features.sh [<research dir>]
# Output re/names/mac/feat.tsv: addr  kind  value
#   s STRING   a string it references
#   k HEX      a 32-bit constant it uses (>= 0x01e00000 and < 0xffff0000: an ID, not an address or a small number), or
#              the value a chain of sub/dec on one register compares against (how a switch over IDs compiles)
#   c HEX      a function it calls
#   r HEX      the constant a tiny function returns (mov eax,imm; ret)
#   v VT:PART  a vtable whose address it uses (a constructor or destructor stores it)
#   n DEC      its instruction count
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$root"
R="${1:-scratch/downloads/sc4-research-mac/artifacts}"
C="$R/code/Mac-RevA-x86-named"
O=re/names/mac
mkdir -p "$O"
# intervals: start end function, from Ghidra's body ranges
awk -F'\t' 'NR>1 { n=split($5, r, ";"); for (i=1;i<=n;i++) if (r[i] ~ /-/) { split(r[i], p, "-"); print p[1] "\t" p[2] "\t" $1 } }' \
    "$C/function-details.tsv" | sort -k1,1 >"$O/.iv"
awk -F'\t' -v IV="$O/.iv" -v STR="$C/defined-strings.tsv" -v VT="$O/vtables.tsv" '
  function owner(a,   lo, hi, mid) {
      lo = 1; hi = niv
      while (lo <= hi) { mid = int((lo + hi) / 2); if (ivs[mid] <= a) lo = mid + 1; else hi = mid - 1 }
      if (hi >= 1 && a <= ive[hi]) return ivf[hi]
      return ""
  }
  function idlike(v) { return v >= 0x01e00000 && v < 0xffff0000 }
  BEGIN {
      while ((getline l < IV) > 0) { split(l, p, "\t"); niv++; ivs[niv] = strtonum("0x" p[1]); ive[niv] = strtonum("0x" p[2]); ivf[niv] = p[3] }
      # strings by address (for position-independent loads), and the first slot of every vtable part
      while ((getline l < STR) > 0) { split(l, p, "\t"); if (p[1] ~ /^[0-9a-f]+$/ && length(p[4]) >= 3) str[strtonum("0x" p[1])] = p[4] }
      while ((getline l < VT) > 0) { split(l, p, "\t"); if (p[4] == "0") vts[strtonum("0x" p[5])] = p[1] ":" p[3] }
      thunk[strtonum("0x005edba0")] = "EBX"; thunk[strtonum("0x0082f11e")] = "ECX"; thunk[strtonum("0x008304a0")] = "EDX"
  }
  # string references: function from string-address value
  FILENAME ~ /string-references.tsv$/ { if (FNR > 1 && length($4) >= 3) { f = owner(strtonum("0x" $2)); if (f != "") print f "\ts\t" $4 } next }
  FILENAME ~ /calls.tsv$/ { if (FNR > 1 && $3 ~ /^[0-9a-f]+$/) { f = owner(strtonum("0x" $2)); if (f != "") print f "\tc\t" $3 } next }
  # instructions: addr bytes text
  /^;/ { next }
  {
      a = strtonum("0x" $1); f = owner(a)
      if (f == "") next
      if (f != cur) {
          if (cur != "") { print cur "\tn\t" cnt; if (cnt <= 6 && retv != "") print cur "\tr\t" retv }
          cur = f; cnt = 0; retv = ""; delete off; delete pic
      }
      cnt++
      t = $3; sp = index(t, " "); op = (sp ? substr(t, 1, sp - 1) : t); args = (sp ? substr(t, sp + 1) : "")
      dst = args; sub(/,.*/, "", dst)
      # position-independent addressing: a call to a pc thunk leaves the next address in a register
      if (op == "CALL") {
          tv = strtonum(args)
          if (tv in thunk) { pic[thunk[tv]] = a + length($2) / 2; next }
          delete pic["ECX"]; delete pic["EDX"]; delete pic["EAX"]
      }
      rest = args
      while (match(rest, /\[E[A-DS][XIP] \+ -?0x[0-9a-f]+\]/)) {
          m = substr(rest, RSTART + 1, RLENGTH - 2); rest = substr(rest, RSTART + RLENGTH)
          split(m, mp, " "); r = mp[1]; d = mp[3]
          if (!(r in pic)) continue
          neg = (substr(d, 1, 1) == "-"); if (neg) d = substr(d, 2)
          t = pic[r] + (neg ? -strtonum(d) : strtonum(d))
          if (t in str) print f "\ts\t" str[t]
          else if (t in vts) print f "\tv\t" vts[t]
      }
      if (dst in pic && dst != "EBX" && op != "CMP" && op != "TEST" && op != "PUSH") delete pic[dst]
      plain = args; gsub(/\[[^]]*\]/, "", plain)
      imm = ""
      if (match(plain, /-?0x[0-9a-f]+$/)) {
          s = substr(plain, RSTART, RLENGTH); neg = (substr(s, 1, 1) == "-"); if (neg) s = substr(s, 2)
          v = strtonum(s); if (neg) v = 4294967296 - v
          imm = v
          if (v in str) print f "\ts\t" str[v]
          else if (v in vts) print f "\tv\t" vts[v]
          if (idlike(v) && !((op == "SUB" || op == "ADD") && dst ~ /^E[A-DS][XIP]$/ && args !~ /\[/)) printf "%s\tk\t%08x\n", f, v
      }
      if (op == "MOV" && dst == "EAX" && imm != "") retv = sprintf("%08x", imm)
      else if (op != "RET" && op != "LEAVE" && op != "POP" && op != "PUSH" && !(op == "MOV" && dst == "EBP")) retv = ""
      # sub/dec chains on one register (a switch over IDs)
      if (dst ~ /^E[A-DS][XIP]$/ && args !~ /\[/) {
          if (op == "SUB" && imm != "") { off[dst] = (off[dst] + imm) % 4294967296; if (idlike(off[dst])) printf "%s\tk\t%08x\n", f, off[dst] }
          else if (op == "ADD" && imm != "") { off[dst] = (off[dst] - imm + 4294967296) % 4294967296; if (idlike(off[dst])) printf "%s\tk\t%08x\n", f, off[dst] }
          else if (op == "DEC") { off[dst] = (off[dst] + 1) % 4294967296; if (idlike(off[dst])) printf "%s\tk\t%08x\n", f, off[dst] }
          else if (op == "INC") { off[dst] = (off[dst] - 1 + 4294967296) % 4294967296 }
          else if (op != "CMP" && op != "TEST" && op != "PUSH") off[dst] = 0
      }
  }
  END { if (cur != "") { print cur "\tn\t" cnt; if (cnt <= 6 && retv != "") print cur "\tr\t" retv } }
' "$C/string-references.tsv" "$C/calls.tsv" "$C/instructions.asm" | sort -u >"$O/feat.tsv"
rm -f "$O/.iv"
cut -f2 "$O/feat.tsv" | sort | uniq -c | awk '{printf "%s=%s ", $2, $1} END {print ""}'
