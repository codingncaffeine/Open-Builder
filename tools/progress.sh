#!/usr/bin/env bash
# Prints where the decompilation stands: every function of the original accounted for as a matched library
# function, part of the block another compiler built, decompiled in src/ (a "// FUNCTION: 0x..." annotation), or
# still to do.
#   tools/progress.sh
# Reads re/map/functions.tsv (tools/ghidra/ExportFunctions.java) and re/map/libraries.tsv (merged obsig matches,
# "<hex va>\t<library>\t<name>"); both are local, derived from the original program, and never committed.
set -euo pipefail
cd "$(dirname "$0")/.."
# The image library's code, built with the Intel C++ compiler 6.0 (its build strings name jpeg, png, zlib and its
# own common code): the 2003 compiler cannot match it, so it is counted apart.
intel_lo=0xa053a0 intel_hi=0xa640c0
# (and the initializer and teardown of a global object, "// STATIC-INIT: 0x<init> 0x<teardown> ...": tools/gen-statics.py)
{ grep -rhoE '// (FUNCTION|SYNTHETIC): 0x[0-9a-fA-F]+' src | awk '{print tolower(substr($3, 3))}'
  grep -rhoE '// STATIC-INIT: 0x[0-9a-fA-F]+ (0x[0-9a-fA-F]+|-)' src | awk '{print tolower(substr($3, 3)); if ($4 != "-") print tolower(substr($4, 3))}'
} | sort -u >"${TMPDIR:-/tmp}/ob-done.$$"
trap 'rm -f "${TMPDIR:-/tmp}/ob-done.$$"' EXIT
# the compiler's own functions (adjustor thunks, import jumps), when the class generator has run (tools/gen-classes.sh)
shapes=(); [[ -f scratch/classes/shapes.tsv ]] && shapes=(scratch/classes/shapes.tsv)
awk -v lo=$((intel_lo)) -v hi=$((intel_hi)) '
  FILENAME ~ /ob-done/ { done[sprintf("%x", strtonum("0x" $1))] = 1; next }
  FILENAME ~ /libraries/ { lib[sprintf("%x", strtonum("0x" $1))] = $2; next }
  FILENAME ~ /shapes/ { if ($5 == "thunk" || $5 == "import") comp[sprintf("%x", strtonum("0x" $1))] = 1; next }
  {
    va = strtonum("0x" $1); size = strtonum("0x" $2); key = sprintf("%x", va)
    if (key in done) kind = "decompiled"
    else if (key in lib) kind = "library " lib[key]
    else if (va >= lo && va < hi) kind = "other compiler"
    else if (key in comp) kind = "compiler-made"
    else kind = "to do"
    n[kind]++; b[kind] += size; total++; bytes += size
  }
  END {
    for (k in n) printf "  %-16s %6d functions %8.1f KB  %5.1f%% of code\n", k, n[k], b[k] / 1024, 100 * b[k] / bytes
    printf "  %-16s %6d functions %8.1f KB\n", "total", total, bytes / 1024
  }' "${TMPDIR:-/tmp}/ob-done.$$" re/map/libraries.tsv "${shapes[@]}" re/map/functions.tsv | sort -k1,1 -s
