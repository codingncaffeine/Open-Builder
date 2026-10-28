#!/usr/bin/env bash
# Sorts every function still to do (not decompiled, not a found library, not the other compiler's block) by kind, so
# work can go to the right tool: compiler-generated code that appears by itself once its class is declared,
# one-line members a generator can write, and real code.
#   tools/triage.sh            summary per kind
#   tools/triage.sh --list     "<address>\t<size>\t<kind>" for every function (re/map/triage.tsv is written either way)
# Reads re/map/functions.tsv, re/map/libraries.tsv, the FUNCTION annotations in src/, and the original's disassembly
# (scratch/exe.dis, regenerated with objdump when missing). Kinds come from the instruction shape alone (every number
# replaced by N); an unrecognised shape is "code".
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
exe="scratch/testbed/game/Apps/SimCity 4.exe"
dis="scratch/exe.dis"
[[ -f re/map/functions.tsv && -f re/map/libraries.tsv ]] || { echo "needs re/map/functions.tsv and libraries.tsv" >&2; exit 2; }
if [[ ! -f "$dis" ]]; then
  objdump -d -M intel --no-show-raw-insn "$exe" >"$dis"
fi
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT

grep -rhoE '// FUNCTION: 0x[0-9a-fA-F]+' src | awk '{print tolower(substr($3, 3))}' | sort -u >"$work/done"
# The functions to do, in address order: "<va hex> <size dec>". The image library (other compiler) is left out.
awk 'FILENAME ~ /done$/ { done[sprintf("%08x", strtonum("0x" $1))] = 1; next }
     FILENAME ~ /libraries/ { lib[sprintf("%08x", strtonum("0x" $1))] = 1; next }
     {
       a = sprintf("%08x", strtonum("0x" $1)); va = strtonum("0x" $1)
       if (a in done || a in lib || (va >= 0xa053a0 && va < 0xa640c0)) next
       print a, strtonum("0x" $2)
     }' "$work/done" re/map/libraries.tsv re/map/functions.tsv | sort >"$work/todo"

# Shape of each: its instructions in order, numbers as N.
awk 'NR == FNR { s[++n] = strtonum("0x" $1); l[n] = $2; next }
  FNR == 1 { i = 1 }
  {
    a = $1; sub(/^ +/, "", a); sub(/:$/, "", a)
    if (a !~ /^[0-9a-f]+$/ || $2 == "") next
    va = strtonum("0x" a)
    while (i <= n && va >= s[i] + l[i]) { out(i); i++ }
    if (i > n) exit
    if (va >= s[i]) { ins = $2; gsub(/0x[0-9a-f]+/, "N", ins); gsub(/ +/, " ", ins); sh[i] = sh[i] ins "; " }
  }
  END { while (i <= n) { out(i); i++ } }
  function out(k) { printf "%08x\t%d\t%s\n", s[k], l[k], sh[k] }
' "$work/todo" FS='\t' "$dis" >"$work/shapes"

awk -F'\t' '
  function kind(sh) {
    if (sh ~ /^(ret|ret N); $/) return "empty"
    if (sh ~ /^(sub|add) ecx,N; jmp N; $/) return "thunk-adjustor"
    if (sh ~ /^sub ecx,DWORD PTR \[ecx-N\]; ((sub|add) ecx,N; )?jmp N; $/) return "thunk-vtordisp"
    # mov eax,FuncInfo; jmp __CxxFrameHandler: the exception-handling stub of a function built with /GX
    if (sh ~ /^mov eax,N; jmp N; $/) return "eh-handler"
    if (sh ~ /^jmp [^;]*; $/ || sh ~ /^mov ecx,DWORD PTR [^;]*; jmp [^;]*; $/) return "forwarder"
    if (sh ~ /test BYTE PTR \[esp\+N\],N; je N; push (esi|edi); call N;/ && sh ~ /mov eax,(esi|edi);/) return "deleting-dtor"
    if (sh ~ /^(mov eax,N|xor eax,eax|mov al,N|xor al,al|or eax,N|mov ax,N|xor ax,ax|fld[^;]*|fldz|fld1); ret( N)?; $/) return "return-constant"
    if (sh ~ /^(mov|movzx|movsx|lea|fld) [^;]*\[ecx(\+N)?\]; ret( N)?; $/) return "getter"
    if (sh ~ /^mov (e?ax|al|cl|ecx|edx|dl),[^;]*\[esp\+N\]; mov [^;]*\[ecx(\+N)?\],[^;]*; ret N; $/) return "setter"
    if (sh ~ /^mov eax,ecx; ret( N)?; $/) return "return-this"
    if (sh ~ /push N; call N; pop ecx; ret; $/ && sh ~ /^(mov ecx,N; call N; )?push N; call N; pop ecx; ret; $/) return "global-init"
    if (sh ~ /^mov eax,ds:N; test eax,eax; (mov DWORD PTR ds:N,N; )?je N; push eax; call N; pop ecx; ret; $/) return "global-dtor"
    # the destructor of a global object, registered with atexit by its initialiser
    if (sh ~ /^mov ecx,N; jmp N; $/) return "global-dtor"
    if (sh ~ /atexit|^push ecx; lea eax,\[esp\+N\]; push eax; push N; push N; mov ecx,N; call N;/) return "global-init"
    return "code"
  }
  { k = kind($3); print $1 "\t" $2 "\t" k }
' "$work/shapes" >re/map/triage.tsv

if [[ "${1:-}" == "--list" ]]; then
  cat re/map/triage.tsv
  exit 0
fi
awk -F'\t' '{ n[$3]++; b[$3] += $2; tn++; tb += $2 }
  END {
    for (k in n) printf "%-16s %6d functions %9.1f KB  %5.1f%% of bytes\n", k, n[k], b[k] / 1024, 100 * b[k] / tb | "sort -k2 -nr"
    close("sort -k2 -nr")
    printf "%-16s %6d functions %9.1f KB\n", "total", tn, tb / 1024
  }' re/map/triage.tsv
