#!/usr/bin/env bash
# Prints a C++ declaration of an interface the code reaches only through a pointer (a global, a member of another
# class): every slot by its real name, in vtable order, for Globals.h or a decompiled file.
#   tools/names/iface.sh cISC4City cSC4City a87620 [cISC4City_ab0dc8]
# INTERFACE: its vftable_<name> slots in the symbol archive's dump (scratch/names/gdt/fields.tsv).
# CLASS: the class implementing it in the reference build, whose symbols give each slot's argument types
# (re/names/mac/funcs.tsv). VTABLE: that class's vtable for the interface in the original (hex), whose functions give
# each return type (what they leave in al/eax/st0, scratch/classes/shapes.tsv); "-" when the original's is not known.
# Where the original's function does not tell (it ends in a jump), the reference build's pseudocode does. Types that
# are not plain values become void* (a pointer or a reference to a class: the same argument for the compiler).
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$root"
iface="${1:?interface, e.g. cISC4City}" cls="${2:?implementing class, e.g. cSC4City}" vt="${3:--}" as="${4:-$1}"
gdt=scratch/names/gdt/fields.tsv
mac=re/names/mac/funcs.tsv
code=scratch/downloads/sc4-research-mac/artifacts/code/Mac-RevA-x86-named/functions
for f in "$gdt" "$mac" scratch/classes/slots.tsv scratch/classes/shapes.tsv; do
  [[ -s "$f" ]] || { echo "iface: $f missing (tools/names/run.sh, tools/gen-classes.sh)" >&2; exit 2; }
done
# The reference build's return type of each method of CLASS, from the first line of its pseudocode (when present).
macret=$(mktemp -p scratch)
trap 'rm -f "$macret"' EXIT
awk -F'\t' -v c="$cls::" 'index($3, c) == 1 { n = substr($3, length(c) + 1); sub(/\(.*/, "", n); print $1 "\t" n }' "$mac" |
  while IFS=$'\t' read -r a n; do
    f="$code/$a.c"
    [[ -f "$f" ]] || continue
    t=$(awk 'NR <= 6 && / __thiscall / { sub(/ __thiscall .*/, ""); print; exit }' "$f")
    if [[ -n "$t" ]]; then printf "%s\t%s\n" "$n" "$t"; fi
  done >"$macret"
awk -F'\t' -v iface="$iface" -v cls="$cls" -v vt="$vt" -v as="$as" '
  function argType(t) {
    gsub(/^ +| +$/, "", t); sub(/ const$/, "", t); sub(/^const /, "", t)
    if (t == "unsigned long" || t == "unsigned int") return "uint32_t"
    if (t == "long" || t == "int") return "int32_t"
    if (t == "bool" || t == "__bool8") return "bool"
    if (t == "unsigned short") return "uint16_t"
    if (t == "short") return "int16_t"
    if (t == "unsigned char") return "uint8_t"
    if (t == "signed char") return "int8_t"
    if (t == "char") return "char"
    if (t == "float" || t == "double") return t
    if (t == "char*" || t == "char const*") return "const char*"
    if (t ~ /[*&]$/) return "void*"
    return ""  # a class passed by value: not declared
  }
  function retFromShape(r) { return r == "B" ? "bool" : r == "F" ? "float" : r == "V" ? "void" : r == "D" ? "uint32_t" : "" }
  function retFromMac(t) {
    if (t == "void") return "void"
    if (t == "bool" || t == "char" || t == "byte" || t == "undefined" || t == "undefined1") return "bool"
    if (t == "float10" || t == "float") return "float"
    if (t ~ /\*$/) return "void*"
    if (t == "undefined4" || t == "int" || t == "uint" || t == "ulong" || t == "long") return "uint32_t"
    return ""
  }
  FILENAME == ARGV[1] { if ($2 == "vftable_" iface) slot[strtonum("0x" $3) / 4] = $6; next }
  FILENAME == ARGV[2] {
    p = index($3, cls "::"); if (p != 1) next
    n = substr($3, length(cls) + 3); name = n; sub(/\(.*/, "", name)
    a = n; sub(/^[^(]*\(/, "", a); sub(/\)[^)]*$/, "", a)
    if (name in args && args[name] !~ /__bool8/) next  # an overload kept twice (bool, __bool8): the first
    args[name] = a; next
  }
  FILENAME == ARGV[3] { if ($1 == vt) fn[$2] = $3; next }
  FILENAME == ARGV[4] { ret[$1] = $4; next }
  FILENAME == ARGV[5] { macRet[$1] = $2; next }
  END {
    print "struct " as " {"
    for (i = 0; i in slot; ++i) {
      n = slot[i]
      how = ""
      r = (i in fn) ? retFromShape(ret[fn[i]]) : ""
      if (r == "" && (n in macRet)) { r = retFromMac(macRet[n]); how = "return type from the reference build" }
      if (r == "") { r = "uint32_t"; how = "return type unknown" }
      params = ""; ok = 1
      if ((n in args) && args[n] != "" && args[n] != "void") {
        k = split(args[n], A, ",")
        for (j = 1; j <= k; ++j) { t = argType(A[j]); if (t == "") ok = 0; params = params (j > 1 ? ", " : "") t }
      } else if (!(n in args)) ok = 0
      if (!ok) how = how (how == "" ? "" : "; ") "arguments unknown"
      note = how == "" ? "" : "  // " how
      if (n == "") n = sprintf("Slot%02d", i)
      # every interface starts with the three of cIGZUnknown
      if (i == 0) { r = "bool"; params = "uint32_t, void**"; ok = 1; note = "" }
      if (i == 1 || i == 2) { r = "uint32_t"; params = ""; ok = 1; note = "" }
      printf "    virtual %s %s(%s);%s\n", r, n, ok ? params : "", note
    }
    print "};"
  }' "$gdt" "$mac" scratch/classes/slots.tsv scratch/classes/shapes.tsv "$macret"
