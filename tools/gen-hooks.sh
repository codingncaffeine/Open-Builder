#!/usr/bin/env bash
# Writes the hook table from the "// FUNCTION: 0x<address>" annotations in src/ (sources and headers), after the
# sources are compiled: each annotation names the original address of the function defined right after it, and that
# function is found among the compiled objects' symbols by qualified name and parameter types (llvm-undname), so
# virtual, overloaded, variadic and inline functions all resolve to the function itself (a name only one function
# has resolves by the name alone, so a parameter type may be a typedef). The table refers to each one
# through /alternatename.
#   tools/gen-hooks.sh <out.cpp> <object dir> [stubs.txt]
# "// SYNTHETIC: 0x<address>" with the next line "// <the compiler's name for it>" (llvm-undname's spelling, e.g.
# "cFoo::`scalar deleting dtor'" or "cFoo::Release`adjustor{4}'") matches a function the compiler generated, never hooked.
# "// FUNCTION: 0x<address> nohook" matches the function without hooking it (one too small for a 5-byte jump, or a
# body the linker folded into one shared by another entry).
# "// STUB: 0x<address>" before a declaration of a function not decompiled yet: when the objects call it (an undefined
# symbol), "0x<address> <decorated>" goes to stubs.txt for tools/gen-stubs.sh, so the call lands in the original.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
out="$1" objdir="$2" stubsOut="${3:-/dev/null}"
cd "$root"

# Signature keys "Class::Name(type;type)const" with types reduced to sorted tokens, typedefs resolved.
canon='
function trim(s) { sub(/^[ \t]+/, "", s); sub(/[ \t]+$/, "", s); return s }
function canontype(t,   n, w, i, j, k, out, keep, tmp) {
  gsub(/\*/, " * ", t); gsub(/&/, " & ", t); gsub(/[ \t]+/, " ", t); t = trim(t)
  n = split(t, w, " ")
  # a trailing identifier after a type is the parameter name
  if (n > 1 && w[n] ~ /^[A-Za-z_][A-Za-z0-9_]*$/ && !(w[n] in builtin)) n--
  k = 0
  for (i = 1; i <= n; i++) {
    if (w[i] == "class" || w[i] == "struct" || w[i] == "enum") continue
    if (w[i] in typedefs) { split(typedefs[w[i]], tmp, " "); for (j in tmp) keep[++k] = tmp[j]; continue }
    keep[++k] = w[i]
  }
  for (i = 1; i <= k; i++) for (j = i + 1; j <= k; j++) if (keep[j] < keep[i]) { tmp[0] = keep[i]; keep[i] = keep[j]; keep[j] = tmp[0] }
  out = ""
  for (i = 1; i <= k; i++) out = out (i > 1 ? " " : "") keep[i]
  return out
}
function key(qualified, params, isconst,   n, p, i, out) {
  params = trim(params)
  if (params == "void") params = ""
  # the demangler spells standard library types out, in the STLport namespace (before the split at commas)
  gsub(/class _STL::basic_string<char, class _STL::char_traits<char>, class _STL::allocator<char>>/, "std::string", params)
  gsub(/_STL::/, "std::", params)
  gsub(/=[^,]*/, "", params)
  n = params == "" ? 0 : split(params, p, ",")
  out = qualified "("
  for (i = 1; i <= n; i++) out = out (i > 1 ? ";" : "") canontype(p[i])
  return out ")" (isconst ? "const" : "")
}
BEGIN {
  split("int char short long unsigned signed bool float double void __int64 wchar_t", b, " ")
  for (i in b) builtin[b[i]] = 1
  typedefs["uint32_t"] = "unsigned int"; typedefs["int32_t"] = "int"; typedefs["size_t"] = "unsigned int"
  typedefs["uint16_t"] = "unsigned short"; typedefs["int16_t"] = "short"; typedefs["uint8_t"] = "unsigned char"
  typedefs["int8_t"] = "signed char"; typedefs["int64_t"] = "__int64"; typedefs["uint64_t"] = "unsigned __int64"
}
'

entries="$(mktemp)" symbols="$(mktemp)"
trap 'rm -f "$entries" "$symbols" "$symbols.raw" "$symbols.kind"' EXIT
# C++ functions of every object: "<key> <decorated>", defined ones, and "U:<key> <decorated>" for the undefined ones
# (called, for STUB annotations). One table for all of them, because a function defined in a header (an inline one)
# is compiled into whichever objects use it, and the linker keeps one of those copies.
for obj in "$objdir"/*.obj; do
  objdump -t "$obj" | awk '/\(ty +20\)\(scl +2\)/ && $NF ~ /^\?/ {print ($0 ~ /\(sec +0\)/ ? "U" : "D") "\t" $NF}'
done | sort -u >"$symbols.kind"
cut -f2 "$symbols.kind" >"$symbols.raw"
# llvm-undname echoes each name, then prints the result and a blank line: keep the results
paste "$symbols.kind" <(llvm-undname <"$symbols.raw" | awk 'NR % 3 == 2') | awk -F'\t' "$canon"'
  {
    undefined = $1 == "U"; $1 = $2; $2 = $3
    if (undefined) {
      d = $2; isconst = (d ~ /\) const$/); sub(/\) const$/, ")", d)
      open = index(d, "("); if (!open) next
      head = substr(d, 1, open - 1); params = substr(d, open + 1); sub(/\)$/, "", params)
      n = split(head, w, " "); print "U:" key(w[n], params, isconst) "\t" $1
      next
    }
    d = $2
    # What the compiler generates (deleting destructors, thunks) by the name it gives it, without the parameters,
    # as the SYNTHETIC annotations spell it (see the top of this script)
    if (d ~ /`/ && (t = index(d, "__thiscall ")) > 0) {
      rest = substr(d, t + 11); last = 0
      for (i = length(rest); i > 0; i--) if (substr(rest, i, 1) == "(") { last = i; break }
      print "SYNTHETIC:" substr(rest, 1, last - 1) "\t" $1
      next
    }
    isconst = (d ~ /\) const$/); sub(/\) const$/, ")", d)
    open = index(d, "("); head = substr(d, 1, open - 1); params = substr(d, open + 1); sub(/\)$/, "", params)
    n = split(head, w, " "); qualified = w[n]
    print key(qualified, params, isconst) "\t" $1
  }' >"$symbols"
: >"$stubsOut"
for src in $(find src -name '*.cpp' -o -name '*.h' | sort); do
  # Annotated definitions in this source, joined to their symbols.
  awk -v src="$src" -v stubsOut="$stubsOut" "$canon"'
    FILENAME != src && $1 ~ /^U:/ {
      k = substr($1, 3); usym[k] = $2
      name = substr(k, 1, index(k, "(") - 1)
      if (!(name SUBSEP $2 in useen)) { useen[name, $2] = 1; unamed[name]++; ubyname[name] = $2 }
      next
    }
    FILENAME != src {
      if (($1 in sym) && sym[$1] != $2) { ambiguous[$1] = sym[$1] " and " $2 }
      sym[$1] = $2
      # by name alone too, for parameter types written through a typedef this script cannot see through
      name = substr($1, 1, index($1, "(") - 1)
      if (!(name SUBSEP $2 in seen)) { seen[name, $2] = 1; named[name]++; byname[name] = $2 }
      next
    }
    synthetic {
      synthetic = 0; name = $0; sub(/^[ \t]*\/\/[ \t]*/, "", name); name = trim(name)
      if (!(("SYNTHETIC:" name) in sym)) { printf "gen-hooks: %s: no compiled %s (%s)\n", src, name, address > "/dev/stderr"; bad = 1; next }
      print address "\t" sym["SYNTHETIC:" name] "\t" name "\t0"
      next
    }
    /\/\/ SYNTHETIC: 0x[0-9a-fA-F]+/ {
      match($0, /0x[0-9a-fA-F]+/); address = substr($0, RSTART, RLENGTH); synthetic = 1; next
    }
    /\/\/ FUNCTION: 0x[0-9a-fA-F]+/ {
      match($0, /0x[0-9a-fA-F]+/); address = substr($0, RSTART, RLENGTH); hook = ($0 !~ /nohook/); text = ""; pending = 1; next
    }
    /\/\/ STUB: 0x[0-9a-fA-F]+/ {
      match($0, /0x[0-9a-fA-F]+/); address = substr($0, RSTART, RLENGTH); text = ""; stub = 1; next
    }
    # the class a member declaration (an indented one) belongs to
    /^(class|struct)[ \t]/ { c = $0; sub(/^(class|struct)[ \t]+(OB_NOVTABLE[ \t]+)?/, "", c); sub(/[ \t:{;].*/, "", c); cls = c }
    stub {
      text = text " " $0
      if (text !~ /\)/) next
      stub = 0
      open = index(text, "("); rparen = 0
      for (i = length(text); i > open; i--) if (substr(text, i, 1) == ")") { rparen = i; break }
      head = substr(text, 1, open - 1); params = substr(text, open + 1, rparen - open - 1)
      isconst = (substr(text, rparen + 1) ~ /^[ \t]*const/)
      n = split(trim(head), w, " "); qualified = w[n]; sub(/^[*&]+/, "", qualified)
      if (qualified !~ /::/ && text ~ /^ [ \t]/ && cls != "") qualified = cls "::" qualified
      k = key(qualified, params, isconst)
      if (!(k in usym) && unamed[qualified] == 1) usym[k] = ubyname[qualified]
      if (k in usym) print address "\t" usym[k] >> stubsOut  # not called anywhere: no stub needed
      next
    }
    pending {
      text = text " " $0
      if (text !~ /\)/) next
      pending = 0
      open = index(text, "("); rparen = 0
      for (i = length(text); i > open; i--) if (substr(text, i, 1) == ")") { rparen = i; break }
      head = substr(text, 1, open - 1); params = substr(text, open + 1, rparen - open - 1)
      isconst = (substr(text, rparen + 1) ~ /^[ \t]*const/)
      n = split(trim(head), w, " "); qualified = w[n]; sub(/^[*&]+/, "", qualified)
      k = key(qualified, params, isconst)
      if (!(k in sym) && named[qualified] == 1) sym[k] = byname[qualified]
      if (!(k in sym)) { printf "gen-hooks: %s: no compiled function for %s (%s)\n", src, k, address > "/dev/stderr"; bad = 1; pending = 0; next }
      if (k in ambiguous) { printf "gen-hooks: %s: %s (%s) is %s\n", src, k, address, ambiguous[k] > "/dev/stderr"; bad = 1; pending = 0; next }
      print address "\t" sym[k] "\t" qualified "\t" hook
    }
    END { exit bad }' FS='\t' "$symbols" FS=' ' "$src" >>"$entries" || failed=1
done
# Every unresolved annotation is reported above before the build stops.
[[ -z "${failed:-}" ]] || exit 1

{
  echo '// Generated by tools/gen-hooks.sh from the FUNCTION annotations in src/. Do not edit.'
  echo '#include "hooks.h"'
  echo
  awk -F'\t' '{ printf "extern \"C\" void obhook_%d();\n#pragma comment(linker, \"/alternatename:_obhook_%d=%s\")\n", NR, NR, $2 }' "$entries"
  echo
  echo '#pragma data_seg(".obhook")'
  echo '#pragma const_seg(".obhook")'
  echo
  echo 'const HookEntry g_hooks[] = {'
  awk -F'\t' '{ printf "    { %s, (void*)&obhook_%d, \"%s\", %d },\n", $1, NR, $3, $4 }' "$entries"
  echo '    { 0, 0, 0, 0 },  // keeps the array non-empty; never installed'
  echo '};'
  echo
  echo '#pragma const_seg()'
  echo '#pragma data_seg()'
  echo
  echo 'const unsigned g_hookCount = sizeof g_hooks / sizeof g_hooks[0] - 1;'
} >"$out"
