#!/usr/bin/env bash
# Lists the slots of the vtables our sources declare by hand (the "// VTABLE:" annotations outside src/classes), read
# from the compiled objects: each vtable's relocations name the function in every slot. tools/obcmp/obdecl reads it
# to derive generated classes from hand-written ones (their slot names and signatures).
#   tools/known-slots.sh <out.tsv>      after a build: the objects of the last SUCCESSFUL one (build/vc71-good-obj; a
#                                       failed build leaves out the objects of every source that failed)
# Writes "<original vtable>\t<slot>\t<decorated>\t<demangled>" per slot.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
out="$1"
objs=build/vc71-good-obj
[[ -d "$objs" ]] || { echo "no successful build yet: tools/build.sh on a tree that builds" >&2; exit 2; }
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
# Hand annotations only: the generated classes (src/classes) are what obdecl writes from this.
find src/classes -name '*.h' -printf '%f\n' 2>/dev/null | sed 's/\.h$//' >"$work/generated"
tools/vtable-annotations.sh | awk 'NR == FNR { g[$1] = 1; next }
  { c = $2; sub(/^\?\?_7/, "", c); sub(/@@.*/, "", c); if (!(c in g)) print }' "$work/generated" - >"$work/annotations"
for obj in "$objs"/*.obj; do
  # (the generated instantiations too: an abstract hand class, an interface with a vtable of its own, has its vtable
  # emitted only where a class derived from it is constructed)
  # "(sec N)...??_7Name@@6B@": the section each vtable is in; then every section's relocations, read once.
  llvm-objdump -t "$obj" | awk '/\?\?_7/ && /\(sec +[0-9]+\)/ { match($0, /\(sec +[0-9]+\)/); s = substr($0, RSTART + 5, RLENGTH - 6); gsub(/ /, "", s); print s, $NF }' >"$work/vtables"
  [[ -s "$work/vtables" ]] || continue
  llvm-readobj --relocations "$obj" >"$work/relocs"
  awk 'NR == FNR { sym[$1] = $2; next }
    $1 == "Section" { s = $2; gsub(/[()]/, "", s); on = (s in sym); next }
    on && $1 == "}" { on = 0; next }
    on { print sym[s] "\t" strtonum($1) / 4 "\t" $3 }' "$work/vtables" "$work/relocs"
done | sort -u >"$work/raw"
# A hand class no object holds a vtable of (an interface: its own vtable holds only _purecall, which names no slot):
# a probe class deriving from it redeclares every pure virtual of it and its bases, so the probe's vtable names each
# slot's function, compiled (not linked) here; the probe's name in them is put back to the class's.
# (a vtable holding _purecall names no slot: its rows are dropped, and it is probed like one no object holds)
awk -F'\t' '$3 == "__purecall" { print $1 }' "$work/raw" | sort -u >"$work/pure"
awk -F'\t' 'NR == FNR { pure[$1] = 1; next } !($1 in pure)' "$work/pure" "$work/raw" >"$work/raw.named"
mv "$work/raw.named" "$work/raw"
probes=scratch/known-probe
rm -rf "$probes"
awk 'NR == FNR { have[$1] = 1; next } !($2 in have) && $2 ~ /^\?\?_7[A-Za-z0-9_]+@@6B@$/ { print $2 }' "$work/raw" "$work/annotations" |
while read -r sym; do
  cls="${sym#\?\?_7}"; cls="${cls%%@@6B@}"
  probe="ObProbe_$cls"
  # the pure virtuals of the class and of its bases, base first, each declaration on one line
  decls() {
    local c="$1" h
    h="$(grep -rlE "^(class|struct)[ \t]+(OB_NOVTABLE[ \t]+)?$c\b[^;]*$" src --include='*.h' | grep -v '^src/classes/' | head -1)"
    [[ -n "$h" ]] || return 0
    for b in $(awk -v c="$c" '$0 ~ "^(class|struct)[ \t]+(OB_NOVTABLE[ \t]+)?" c "([ \t:{]|$)" {
                 s = $0; sub(/[{].*/, "", s); if (!sub(/^[^:]*:/, "", s)) exit
                 n = split(s, w, ","); for (i = 1; i <= n; i++) { t = w[i]; sub(/^[ \t]*(public|protected|private)?[ \t]*/, "", t); sub(/[ \t]+$/, "", t); print t }
                 exit }' "$h"); do decls "$b"; done
    awk -v c="$c" '$0 ~ "^(class|struct)[ \t]+(OB_NOVTABLE[ \t]+)?" c "([ \t:{]|$)" { in_ = 1; next }
                   in_ && /^};/ { exit }
                   in_ && /^[ \t]*virtual/ { d = $0; collecting = 1 }
                   in_ && collecting && !/^[ \t]*virtual/ { d = d " " $0 }
                   in_ && collecting && /;/ { collecting = 0; if (d ~ /=[ \t]*0[ \t]*;/) { sub(/=[ \t]*0[ \t]*;.*/, ";", d); gsub(/[ \t]+/, " ", d); print d } }' "$h"
  }
  hdr="$(grep -rlE "^(class|struct)[ \t]+(OB_NOVTABLE[ \t]+)?$cls\b[^;]*$" src --include='*.h' | grep -v '^src/classes/' | head -1)"
  [[ -n "$hdr" ]] || continue
  mkdir -p "$probes"  # in the project: the compiler runs under Wine and takes relative paths
  { echo "#include \"${hdr#src/}\""
    echo "class $probe : public $cls {"
    echo "public:"
    echo "    $probe();"
    decls "$cls" | sed 's/^/    /'
    echo "};"
    echo "$probe::$probe() {}"
  } >"$probes/$probe.cpp"
  ( cd "$root" && tools/vc71.sh cl /nologo /c /Od /GX- /Isdk /Isrc /Ihook /Ithird_party/stlport-4.6/stlport \
      /D_STLP_DONT_FORCE_MSVC_LIB_NAME /D_STLP_USE_NEWALLOC /D_STLP_OUT_OF_LINE_STL_NEW /D_STLP_RESIZE_BY_REFERENCE \
      "/Fo$probes/$probe.obj" "$probes/$probe.cpp" >"$probes/$probe.log" 2>&1 ) || true
  [[ -f "$probes/$probe.obj" ]] || { echo "known-slots: the probe for $cls does not compile ($probes/$probe.log)" >&2; cat "$probes/$probe.log" >&2; continue; }
  llvm-objdump -t "$probes/$probe.obj" | awk '/\?\?_7/ && /\(sec +[0-9]+\)/ { match($0, /\(sec +[0-9]+\)/); s = substr($0, RSTART + 5, RLENGTH - 6); gsub(/ /, "", s); print s, $NF }' >"$work/vtables"
  llvm-readobj --relocations "$probes/$probe.obj" >"$work/relocs"
  awk -v p="$probe" -v c="$cls" 'NR == FNR { sym[$1] = $2; next }
    $1 == "Section" { s = $2; gsub(/[()]/, "", s); on = (s in sym) && sym[s] == "??_7" p "@@6B@"; next }
    on && $1 == "}" { on = 0; next }
    on { f = $3; gsub("@" p "@@", "@" c "@@", f); print "??_7" c "@@6B@\t" strtonum($1) / 4 "\t" f }' "$work/vtables" "$work/relocs" >>"$work/raw"
done
# The original's address for each of our vtable symbols, then the demangled slot functions.
awk 'NR == FNR { orig[$2] = $1; next } ($1 in orig) { print orig[$1] "\t" $2 "\t" $3 }' "$work/annotations" "$work/raw" |
  sort -k1,1 -k2,2n >"$work/joined"
paste "$work/joined" <(cut -f3 "$work/joined" | llvm-undname 2>/dev/null | awk 'BEGIN { RS = ""; FS = "\n" } { print ($2 != "" ? $2 : $1) }') >"$out"
echo "$(wc -l <"$out") slots of $(cut -f1 "$out" | sort -u | wc -l) vtables"
