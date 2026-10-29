#!/usr/bin/env bash
# Writes the object that leads decompiled code to the original's global variables (the GLOBAL annotations,
# tools/gen-hooks.sh): one absolute symbol per original address, and a /alternatename per decorated name, so the
# linker takes the original's address only while nothing in our sources defines that variable. A reference to an
# absolute symbol gets no base relocation, so it stays on the original's variable wherever the DLL loads.
#   tools/gen-globals.sh <out.obj> <globals.txt>      ("0x<original address> <decorated>" per line)
# The 2003 toolkit has no assembler; llvm-mc writes the COFF object.
set -euo pipefail
out="$1" list="$2"
asm="${out%.obj}.s"
awk '
  NF >= 2 {
    address = tolower($1); sub(/^0x/, "", address); address = sprintf("%08s", address); gsub(/ /, "0", address)
    if (!(address in seen)) { seen[address] = 1; printf "\t.globl\t_ob_data_%s\n_ob_data_%s = 0x%s\n", address, address, address }
    if (!($2 in named)) { named[$2] = 1; alias[++n] = " /alternatename:" $2 "=_ob_data_" address }
  }
  END {
    print "\t.section\t.drectve,\"yn\""
    for (i = 1; i <= n; i++) printf "\t.ascii\t\"%s\"\n", alias[i]
  }' "$list" >"$asm"
llvm-mc -triple=i686-pc-win32 -filetype=obj "$asm" -o "$out"
