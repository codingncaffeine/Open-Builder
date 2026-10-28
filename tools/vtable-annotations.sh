#!/usr/bin/env bash
# Prints the vtables our sources pair with the original's: for each "// VTABLE: 0x<address> [base]" annotation, the
# address and our vtable symbol, ??_7Class@@6B@ (or ??_7Class@@6BBase@@@ for the one shared with that base), Class
# being the next class or struct declared after the annotations (a class with several vtables has one line each).
#   tools/vtable-annotations.sh        "<address> <symbol>" per line
set -euo pipefail
cd "$(dirname "$0")/.."
grep -rh -A40 -E '// VTABLE: 0x[0-9a-fA-F]+' src | awk '
  /\/\/ VTABLE: 0x/ { match($0, /0x[0-9a-fA-F]+/); va[++n] = substr($0, RSTART + 2, RLENGTH - 2); b = $0
                      sub(/.*VTABLE: 0x[0-9a-fA-F]+[ \t]*/, "", b); base[n] = b; next }
  n && match($0, /(class|struct)[ \t]+(OB_NOVTABLE[ \t]+)?[A-Za-z_][A-Za-z0-9_]*/) {
    s = substr($0, RSTART, RLENGTH); k = split(s, w, /[ \t]+/)
    for (i = 1; i <= n; i++) print va[i], "??_7" w[k] "@@6B" (base[i] == "" ? "@" : base[i] "@@@")
    n = 0 }' | sort -u
