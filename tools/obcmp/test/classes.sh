#!/usr/bin/env bash
# Checks obclass against ground truth: builds classes.cpp with the 2003 compiler at the framework's flags and the
# game's, gives obclass the function and vtable lists read from the linker map, puts the map's names back on its
# output and compares it with classes.expected (written from the source).
#   tools/obcmp/test/classes.sh [obclass]     exit 0 = both builds recovered exactly
# Needs the toolkit (tools/vc71.sh). Works in scratch/obclass-test/.
set -euo pipefail
root="$(cd "$(dirname "$0")/../../.." && pwd)"
here="$root/tools/obcmp/test"
obclass="${1:-$root/scratch/build/obcmp/obclass}"
work="$root/scratch/obclass-test"
rm -rf "$work"
mkdir -p "$work"
status=0
winpath() { printf "Z:%s" "${1//\//\\}"; }

for flags in "/O1 /GX- /W3" "/O2 /GX- /W3"; do
  out="$work/$(echo "$flags" | tr -dc 'A-Za-z0-9')"
  mkdir -p "$out"
  # Linked as the original was: unreferenced functions dropped, identical ones folded. Alloc/Free stay unresolved
  # (/force): only their call sites matter.
  ( cd "$here" && "$root/tools/vc71.sh" cl /nologo /c $flags "/Fo$(winpath "$out/classes.obj")" classes.cpp ) >/dev/null
  ( cd "$out" && "$root/tools/vc71.sh" link /nologo /dll /noentry /nodefaultlib /opt:ref /opt:icf /force /map:lib.map \
      /out:lib.dll classes.obj ) >/dev/null 2>&1 || true
  [[ -f "$out/lib.dll" ]] || { echo "$flags: link failed" >&2; exit 2; }
  map="$out/lib.map"
  # " 0001:00000020  ??0cCounter@@QAE@XZ  10001020 f  classes.obj": functions (f) and vtables (??_7), by address.
  awk '$1 ~ /^000[0-9]:/ && $3 ~ /^[0-9a-f]{8}$/ { print $3, $2, ($4 == "f" ? "f" : "d") }' "$map" | sort >"$out/symbols"
  # Functions: one per address, sized to the next symbol. Names: the alphabetically first at an address (folded
  # deleting destructors ??_E/??_G share one).
  awk '$3 == "f" { if (!($1 in n) || $2 < n[$1]) n[$1] = $2; a[$1] = 1 }
       END { for (k in a) print k, n[k] }' "$out/symbols" | sort >"$out/fnames"
  # The last one ends with .text.
  end="$(objdump -h "$out/lib.dll" | awk '$2 == ".text" { printf "%08x", strtonum("0x" $4) + strtonum("0x" $3) }')"
  { cat "$out/fnames"; echo "$end end"; } | awk 'NR > 1 { printf "%s %x\n", prev, strtonum("0x" $1) - strtonum("0x" prev) } { prev = $1 }' >"$out/functions.tsv"
  # Vtables: the run of function addresses from each ??_7 symbol up to the next symbol.
  objdump -s -j .rdata "$out/lib.dll" | awk '/^ [0-9a-f]+ / {
      a = strtonum("0x" $1)
      for (i = 2; i <= 5; i++) if (length($i) == 8) { w = substr($i,7,2) substr($i,5,2) substr($i,3,2) substr($i,1,2); printf "%08x %s\n", a + 4 * (i - 2), w }
    }' >"$out/rdata"
  awk 'FILENAME ~ /fnames$/ { f[$1] = 1; next }
       FILENAME ~ /symbols$/ { if ($2 ~ /^\?\?_7/) vt[$1] = $2; else other[$1] = 1; next }
       { word[$1] = $2; order[++n] = $1 }
       END {
         for (i = 1; i <= n; i++) {
           a = order[i]; if (!(a in vt)) continue
           c = 0
           for (j = i; j <= n; j++) { if (j > i && (order[j] in vt || order[j] in other)) break; if (!(word[order[j]] in f)) break; c++ }
           print a, c
         }
       }' "$out/fnames" "$out/symbols" "$out/rdata" >"$out/vtables.tsv"
  new="$(awk '$2 == "??2@YAPAXI@Z" { print $1 }' "$out/symbols")"
  del="$(awk '$2 == "??3@YAXPAX@Z" { print $1 }' "$out/symbols")"
  "$obclass" "$out/lib.dll" "$out/functions.tsv" "$out/vtables.tsv" --new "$new" --delete "$del" \
    --classes "$out/classes.tsv" --slots "$out/slots.tsv" >"$out/summary.txt"

  # Names back: vtables as class/base, functions as the map has them.
  awk 'FILENAME ~ /symbols$/ {
         if ($2 ~ /^\?\?_7/) { s = $2; sub(/^\?\?_7/, "", s); split(s, p, "@@6B"); b = p[2]; sub(/@@@$/, "", b); sub(/@$/, "", b); if (b ~ /^0@?$/) b = ""
                               nm[$1] = p[1] (b == "" ? "" : "/" b) }
         next }
       FILENAME ~ /fnames$/ { if (!($1 in nm)) nm[$1] = $2; next }
       function name(x,   parts, k, out, q, pre) {
         if (x == "-") return x
         k = split(x, parts, ","); out = ""
         for (q = 1; q <= k; q++) {
           pre = ""; v = parts[q]
           if (v ~ /:/) { pre = substr(v, 1, index(v, ":")); v = substr(v, index(v, ":") + 1) }
           v = sprintf("%08x", strtonum("0x" v))
           out = out (q > 1 ? "," : "") pre (v in nm ? nm[v] : v)
         }
         return out
       }
       { printf "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", name($1), $2, name($3), name($4), name($5), name($6), name($7), name($8), name($11) }
      ' "$out/symbols" "$out/fnames" "$out/classes.tsv" | sort >"$out/got.tsv"
  grep -v "^#" "$here/classes.$(echo "$flags" | cut -d" " -f1 | tr -d /).expected" | sort >"$out/want.tsv"
  if diff -u "$out/want.tsv" "$out/got.tsv" >"$out/diff.txt"; then
    echo "$flags: identical ($(head -2 "$out/summary.txt" | tail -1))"
  else
    echo "$flags: DIFFERS"
    cat "$out/diff.txt"
    status=1
  fi
done
exit $status
