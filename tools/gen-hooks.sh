#!/usr/bin/env bash
# Writes the hook table from the "// FUNCTION: 0x<address>" annotations in src/ (sources and headers), after the
# sources are compiled: each annotation names the original address of the function defined right after it, and that
# function is found among the compiled objects' symbols by qualified name and parameter types (llvm-undname), so
# virtual, overloaded, variadic and inline functions all resolve to the function itself (a name only one function
# has resolves by the name alone, so a parameter type may be a typedef). The table refers to each one
# through /alternatename.
#   tools/gen-hooks.sh <out.cpp> <object dir> [stubs.txt] [globals.txt]
# "// SYNTHETIC: 0x<address>" with the next line "// <the compiler's name for it>" (llvm-undname's spelling, e.g.
# "cFoo::`scalar deleting dtor'" or "cFoo::Release`adjustor{4}'") matches a function the compiler generated, never hooked.
# "// FUNCTION: 0x<address> nohook" matches the function without hooking it (one too small for a 5-byte jump, or a
# body the linker folded into one shared by another entry).
# "// STUB: 0x<address>" before a declaration of a function not decompiled yet: when the objects call it (an undefined
# symbol), "0x<address> <decorated>" goes to stubs.txt for tools/gen-stubs.sh, so the call lands in the original.
# "// GLOBAL: 0x<address>" before an extern declaration of one of the original's global variables (or of a static
# member): when the objects refer to it, "0x<address> <decorated>" goes to globals.txt for tools/gen-globals.sh, so the
# reference lands on the original's variable. Our sources must not define it: the game's own code uses the original's.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
out="$1" objdir="$2" stubsOut="${3:-/dev/null}" globalsOut="${4:-/dev/null}"
cd "$root"
# the original's function sizes (as tools/match.sh takes them)
sizes=re/map/functions.tsv
[[ -f scratch/classes/sizes.tsv ]] && sizes=scratch/classes/sizes.tsv

# Signature keys "Class::Name(type;type)const" with types reduced to sorted tokens, typedefs resolved.
canon='
function trim(s) { sub(/^[ \t]+/, "", s); sub(/[ \t]+$/, "", s); return s }
function canontype(t,   n, w, i, j, k, out, keep, tmp) {
  gsub(/\*/, " * ", t); gsub(/&/, " & ", t); gsub(/[ \t]+/, " ", t); t = trim(t)
  n = split(t, w, " ")
  # a trailing identifier after a type is the parameter name
  # (not the name after class/struct/enum, which the demangler writes before a type)
  if (n > 1 && w[n] ~ /^[A-Za-z_][A-Za-z0-9_]*$/ && !(w[n] in builtin) && w[n - 1] !~ /^(class|struct|enum|union)$/) n--
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
# a key'"'"'s name with its parameter count ("cX::F/2"): the name alone stands for a function only among overloads
# of the same count (a default constructor never takes the copy constructor'"'"'s symbol)
function byarity(k,   inner, i, c, depth, n) {
  inner = substr(k, index(k, "(") + 1); sub(/\)[^)]*$/, "", inner)
  n = inner == "" ? 0 : 1
  for (i = 1; i <= length(inner); i++) {  # separators inside template arguments or a function type do not count
    c = substr(inner, i, 1)
    if (c == "<" || c == "(") depth++; else if (c == ">" || c == ")") depth--; else if (c == ";" && depth == 0) n++
  }
  return substr(k, 1, index(k, "(") - 1) "/" n
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
  # the demangler'"'"'s spelling of an anonymous namespace; sources name what is in one without it
  anon = "`anonymous namespace" sprintf("%c", 39) "::"
}
'

entries="$(mktemp)" symbols="$(mktemp)"
trap 'rm -f "$entries" "$symbols" "$symbols.raw" "$symbols.kind"' EXIT
# C++ functions of every object: "<key> <decorated>", defined ones, and "U:<key> <decorated>" for the undefined ones
# (called, for STUB annotations); variables: "DATA:<name> <decorated>" and "UDATA:<name> <decorated>" (for GLOBAL
# annotations). One table for all of them, because a function defined in a header (an inline one) is compiled into
# whichever objects use it, and the linker keeps one of those copies.
for obj in "$objdir"/*.obj; do
  # variables are type 0; the compiler's own data (vtables, string literals) is named "??_"
  objdump -t "$obj" | awk '$NF ~ /^\?/ && /\(scl +2\)/ {
    kind = /\(sec +0\)/ ? "U" : "D"
    if (/\(ty +20\)/) print kind "\t" $NF
    else if (/\(ty +0\)/ && $NF !~ /^\?\?_/) print kind "D\t" $NF
  }'
done | sort -u >"$symbols.kind"
cut -f2 "$symbols.kind" >"$symbols.raw"
# llvm-undname echoes each name, then prints the result (nothing for a name it cannot read) and a blank line: one
# block per name, its result or the name itself
paste "$symbols.kind" <(llvm-undname <"$symbols.raw" 2>/dev/null | awk 'BEGIN { RS = ""; FS = "\n" } { print ($2 != "" ? $2 : $1) }') | awk -F'\t' "$canon"'
  {
    kind = $1; undefined = kind == "U"; $1 = $2; $2 = $3
    gsub(anon, "", $2)
    if (kind == "UD" || kind == "DD") {
      # a variable: its name is the last word, or the one in "(*name)" of a function pointer, or a template'"'"'s static
      # member spelled without class keys and spaces ("cX<cY*>::spZ")
      d = $2; t = d; gsub(/(class|struct|union|enum) /, "", t)
      if (match(t, /[A-Za-z_][A-Za-z0-9_:]*<.*>::[A-Za-z_][A-Za-z0-9_]*$/)) { name = substr(t, RSTART, RLENGTH); gsub(/ /, "", name) }
      else if (match(d, /\*[A-Za-z_][A-Za-z0-9_:]*\)/)) name = substr(d, RSTART + 1, RLENGTH - 2)
      else { n = split(d, w, /[ *&]+/); name = w[n] }
      print (kind == "UD" ? "UDATA:" : "DATA:") name "\t" $1
      next
    }
    if (undefined) {
      d = $2; isconst = (d ~ /\) const$/); sub(/\) const$/, ")", d)
      open = index(d, "("); if (!open) next
      head = substr(d, 1, open - 1); params = substr(d, open + 1); sub(/\)$/, "", params)
      # "operator delete" is one name (the space would split it), on both sides: symbols and annotations
      gsub(/operator +/, "operator", head); n = split(head, w, " "); print "U:" key(w[n], params, isconst) "\t" $1
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
    gsub(/operator +/, "operator", head); n = split(head, w, " "); qualified = w[n]
    print key(qualified, params, isconst) "\t" $1
  }' >"$symbols"
: >"$stubsOut"
: >"$globalsOut"
for src in $(find src -name '*.cpp' -o -name '*.h' | sort); do
  # Annotated definitions in this source, joined to their symbols.
  awk -v src="$src" -v stubsOut="$stubsOut" -v globalsOut="$globalsOut" "$canon"'
    FILENAME != src && $1 ~ /^UDATA:/ { udata[substr($1, 7)] = udata[substr($1, 7)] " " $2; next }
    FILENAME != src && $1 ~ /^DATA:/ { ddata[substr($1, 6)] = $2; next }
    FILENAME != src && $1 ~ /^U:/ {
      # one key (name and parameters) can stand for several symbols: declarations of one original function that
      # differ only in the return type (two views of what it returns); each gets the stub
      k = substr($1, 3); if (!((k, $2) in ukseen)) { ukseen[k, $2] = 1; usym[k] = (k in usym ? usym[k] " " : "") $2 }
      name = byarity(k)
      if (!(name SUBSEP $2 in useen)) { useen[name, $2] = 1; unamed[name]++; ubyname[name] = $2 }
      next
    }
    FILENAME != src {
      if (($1 in sym) && sym[$1] != $2) { ambiguous[$1] = sym[$1] " and " $2 }
      sym[$1] = $2
      # by name alone too, for parameter types written through a typedef this script cannot see through
      name = byarity($1)
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
    /\/\/ GLOBAL: 0x[0-9a-fA-F]+/ {
      match($0, /0x[0-9a-fA-F]+/); address = substr($0, RSTART, RLENGTH); global = 1; next
    }
    # a named namespace opened at column 0 qualifies what is declared inside it, until its brace closes (braces
    # counted per line; the closing line itself declares nothing)
    { if (nsname != "" && depth <= nsdepth) nsname = ""; depth += gsub(/\{/, "{") - gsub(/\}/, "}") }
    /^namespace[ \t]+[A-Za-z_][A-Za-z0-9_]*[ \t]*\{/ { ns = $0; sub(/^namespace[ \t]+/, "", ns); sub(/[ \t{].*/, "", ns); nsname = ns; nsdepth = depth - 1 }
    # the class a member declaration (an indented one) belongs to, up to its closing "};" (not a forward declaration)
    /^(class|struct)[ \t]/ && !/;[ \t]*$/ { c = $0; sub(/^(class|struct)[ \t]+(OB_NOVTABLE[ \t]+)?/, "", c); sub(/[ \t:{;].*/, "", c); cls = (nsname != "" ? nsname "::" : "") c }
    # an explicit specialization of a class template ("template <> struct cX<cY*> {"): its name spelled as the
    # variables'"'"' names are (no spaces), so a static member'"'"'s GLOBAL finds it
    /^template[ \t]*<>[ \t]*(class|struct)[ \t]/ && !/;[ \t]*$/ {
      c = $0; sub(/^template[ \t]*<>[ \t]*(class|struct)[ \t]+/, "", c); sub(/[ \t]*(:[^:].*|\{.*)$/, "", c); gsub(/[ \t]/, "", c)
      cls = (nsname != "" ? nsname "::" : "") c
    }
    /^};/ { cls = "" }
    global {
      global = 0; line = $0; sub(/\/\/.*/, "", line)
      if (line !~ /^[ \t]*extern[ \t]/ && !(line ~ /^[ \t]+static[ \t]/ && cls != "")) {
        printf "gen-hooks: %s: GLOBAL %s must annotate the extern declaration (or static member) right below it\n", src, address > "/dev/stderr"
        bad = 1; next
      }
      sub(/;.*/, "", line); sub(/\[.*/, "", line); sub(/[ \t]*=.*/, "", line)
      if (match(line, /\*[ \t]*[A-Za-z_][A-Za-z0-9_]*[ \t]*\)/)) { name = substr(line, RSTART + 1, RLENGTH - 2); gsub(/[ \t]/, "", name) }
      else { n = split(trim(line), w, /[ \t*&]+/); name = w[n] }
      if (line ~ /^[ \t]+static[ \t]/) name = cls "::" name
      if (name in ddata) {
        printf "gen-hooks: %s: %s (GLOBAL %s) is defined in our sources; the hook build must use the original%cs\n", src, name, address, 39 > "/dev/stderr"
        bad = 1; next
      }
      # not referred to anywhere: nothing to resolve
      n = split(udata[name], w, " "); for (i = 1; i <= n; i++) print address "\t" w[i] >> globalsOut
      next
    }
    stub {
      l = $0; sub(/\/\/.*/, "", l); text = text " " l  # a comment after the declaration is not part of it
      if (text !~ /\)/) next
      stub = 0
      open = index(text, "("); rparen = 0
      for (i = length(text); i > open; i--) if (substr(text, i, 1) == ")") { rparen = i; break }
      head = substr(text, 1, open - 1); params = substr(text, open + 1, rparen - open - 1)
      isconst = (substr(text, rparen + 1) ~ /^[ \t]*const/)
      gsub(/operator +/, "operator", head); n = split(trim(head), w, " "); qualified = w[n]; sub(/^[*&]+/, "", qualified)
      if (qualified !~ /::/ && text ~ /^ [ \t]/ && cls != "") qualified = cls "::" qualified
      else if (qualified !~ /::/ && nsname != "") qualified = nsname "::" qualified
      k = key(qualified, params, isconst)
      if (k in usym) { n = split(usym[k], w, " "); for (i = 1; i <= n; i++) { print address "\t" w[i] >> stubsOut; exact[w[i]] = 1 } }
      # by name and count alone (a typedef this script cannot see through), decided at the end: never a symbol
      # another declaration of the file names exactly (an uncalled overload must not take the called one'"'"'s)
      else if (unamed[byarity(k)] == 1) fallback[address] = ubyname[byarity(k)]
      next  # not called: no stub
    }
    pending {
      l = $0; sub(/\/\/.*/, "", l); text = text " " l
      if (text !~ /\)/) next
      pending = 0
      open = index(text, "("); rparen = 0
      for (i = length(text); i > open; i--) if (substr(text, i, 1) == ")") { rparen = i; break }
      head = substr(text, 1, open - 1); params = substr(text, open + 1, rparen - open - 1)
      isconst = (substr(text, rparen + 1) ~ /^[ \t]*const/)
      gsub(/operator +/, "operator", head); n = split(trim(head), w, " "); qualified = w[n]; sub(/^[*&]+/, "", qualified)
      if (qualified !~ /::/ && text ~ /^ [ \t]/ && cls != "") qualified = cls "::" qualified
      else if (qualified !~ /::/ && nsname != "") qualified = nsname "::" qualified
      k = key(qualified, params, isconst)
      if (!(k in sym) && named[byarity(k)] == 1) sym[k] = byname[byarity(k)]
      if (!(k in sym)) { printf "gen-hooks: %s: no compiled function for %s (%s)\n", src, k, address > "/dev/stderr"; bad = 1; pending = 0; next }
      if (k in ambiguous) { printf "gen-hooks: %s: %s (%s) is %s\n", src, k, address, ambiguous[k] > "/dev/stderr"; bad = 1; pending = 0; next }
      print address "\t" sym[k] "\t" qualified "\t" hook
    }
    END {
      for (a in fallback) if (!(fallback[a] in exact)) print a "\t" fallback[a] >> stubsOut
      exit bad
    }' FS='\t' "$symbols" FS=' ' "$src" >>"$entries" || failed=1
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
  # a function shorter than the 5-byte jump is matched but never patched in: the jump would overwrite the start of
  # the function after it (a 4-byte getter's hook broke the setter behind it, s17)
  awk -F'\t' 'FILENAME != ARGV[ARGC - 1] { size[sprintf("%x", strtonum("0x" $1))] = strtonum("0x" $2); next }
    { a = sprintf("%x", strtonum($1)); hook = $4; if ((a in size) && size[a] < 5) hook = 0
      printf "    { %s, (void*)&obhook_%d, \"%s\", %d },\n", $1, FNR, $3, hook }' "$sizes" "$entries"
  echo '    { 0, 0, 0, 0 },  // keeps the array non-empty; never installed'
  echo '};'
  echo
  echo '#pragma const_seg()'
  echo '#pragma data_seg()'
  echo
  echo 'const unsigned g_hookCount = sizeof g_hooks / sizeof g_hooks[0] - 1;'
} >"$out"
