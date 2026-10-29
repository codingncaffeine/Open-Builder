#!/usr/bin/env bash
# Freezes the names tools/obcmp/obname found into src/classes/names.tsv (committed; tools/obcmp/obdecl reads it):
#   class <primary vtable> <name>        every class paired with the reference build's
#   slot <vtable> <index> <method>       every slot named with evidence (how S: a paired function, or ret N agreeing
#                                        with the reference argument list); position-only names (s) stay out
# Names become identifiers: template arguments and nested names joined with "_" (cSC4SimGrid<float> →
# cSC4SimGrid_float), anonymous namespaces dropped.
#   tools/names/freeze.sh
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$root"
out=src/classes/names.tsv
tmp="$out.new"
{
  echo "# Names of the recovered classes and of the virtual methods they introduce, from a build of the same source"
  echo "# that kept its symbols (tools/names/run.sh, then tools/names/freeze.sh). Read by tools/obcmp/obdecl."
  awk -F'\t' '
    function ident(s) {
        gsub(/\(anonymous namespace\)::/, "", s)
        gsub(/[^A-Za-z0-9_]+/, "_", s); gsub(/_+/, "_", s); sub(/^_/, "", s); sub(/_$/, "", s)
        return s
    }
    FILENAME ~ /classes.tsv$/ { print "class\t" $1 "\t" ident($2); next }
    $4 == "S" {
        n = $3; sub(/\(.*/, "", n)
        # the last name at template depth 0
        d = 0; cut = 0
        for (i = 1; i < length(n); i++) {
            c = substr(n, i, 1)
            if (c == "<") d++; else if (c == ">") d--
            else if (d == 0 && substr(n, i, 2) == "::") cut = i + 2
        }
        m = cut ? substr(n, cut) : n
        if (m ~ /^[A-Za-z_][A-Za-z0-9_]*$/) print "slot\t" $1 "\t" $2 "\t" m
    }
  ' re/names/classes.tsv re/names/slots.tsv | sort -t$'\t' -k1,1 -k2,2 -k3,3n
} >"$tmp"
mv "$tmp" "$out"
echo "names.tsv: $(command grep -c '^class' "$out") classes, $(command grep -c '^slot' "$out") slots"
