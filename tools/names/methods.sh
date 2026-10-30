#!/usr/bin/env bash
# Writes the non-virtual member names to src/classes/methods.tsv (committed; tools/obcmp/obdecl --methods reads it),
# for the classes src/classes/names.tsv names (tools/names/freeze.sh):
#   method <function> <class> <name> [const]   every function the reference build names as a member of a class
#                                              names.tsv names (re/names/functions.tsv, any evidence but position-only)
#   tools/names/methods.sh
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$root"
names=src/classes/names.tsv
out=src/classes/methods.tsv
tmp="$out.new"
{
  echo "# Names of the non-virtual member functions of the named classes, from a build of the same source that kept its"
  echo "# symbols (tools/names/run.sh, then tools/names/methods.sh). Read by tools/obcmp/obdecl --methods."
  awk -F'\t' '
    function ident(s) {
        gsub(/\(anonymous namespace\)::/, "", s)
        gsub(/[^A-Za-z0-9_]+/, "_", s); gsub(/_+/, "_", s); sub(/^_/, "", s); sub(/_$/, "", s)
        return s
    }
    FILENAME ~ /names.tsv$/ { if ($1 == "class") known[$3] = 1; next }
    $3 != "s" {
        n = $2; sub(/\(.*/, "", n)
        # the last name at template depth 0
        d = 0; cut = 0
        for (i = 1; i < length(n); i++) {
            c = substr(n, i, 1)
            if (c == "<") d++; else if (c == ">") d--
            else if (d == 0 && substr(n, i, 2) == "::") cut = i + 2
        }
        if (!cut) next
        m = substr(n, cut); cls = ident(substr(n, 1, cut - 3))
        if (cls in known && m ~ /^[A-Za-z_][A-Za-z0-9_]*$/)
            print "method\t" $1 "\t" cls "\t" m ($2 ~ /\) const$/ ? "\tconst" : "")
    }
  ' "$names" re/names/functions.tsv | sort -t$'\t' -k2,2
} >"$tmp"
[[ -s "$tmp" ]] && mv "$tmp" "$out"
echo "methods.tsv: $(command grep -c '^method' "$out") methods"
