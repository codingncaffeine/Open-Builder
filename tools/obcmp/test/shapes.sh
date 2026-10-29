#!/usr/bin/env bash
# Checks obshape against ground truth: builds shapes.cpp with the 2003 compiler at the framework's flags and the
# game's, runs obshape over the functions the linker map lists and compares, by name, with shapes.<flag>.expected.
#   tools/obcmp/test/shapes.sh [obshape]     exit 0 = both builds read exactly
# Needs the toolkit (tools/vc71.sh). Works in scratch/obshape-test/.
set -euo pipefail
root="$(cd "$(dirname "$0")/../../.." && pwd)"
here="$root/tools/obcmp/test"
obshape="${1:-$root/scratch/build/obcmp/obshape}"
work="$root/scratch/obshape-test"
rm -rf "$work"
mkdir -p "$work"
status=0
winpath() { printf "Z:%s" "${1//\//\\}"; }

for flags in "/O1 /GX- /W3" "/O2 /GX- /W3"; do
  opt="$(echo "$flags" | cut -d" " -f1 | tr -d /)"
  out="$work/$opt"
  mkdir -p "$out"
  ( cd "$here" && "$root/tools/vc71.sh" cl /nologo /c $flags "/Fo$(winpath "$out/shapes.obj")" shapes.cpp ) >/dev/null
  # No /opt:icf: members with one body keep their own addresses, so each is read under its own name.
  ( cd "$out" && "$root/tools/vc71.sh" link /nologo /dll /noentry /nodefaultlib /opt:noref /force /map:lib.map \
      /out:lib.dll shapes.obj ) >/dev/null 2>&1 || true
  [[ -f "$out/lib.dll" ]] || { echo "$flags: link failed" >&2; exit 2; }
  awk '$1 ~ /^0001:/ && $3 ~ /^[0-9a-f]{8}$/ && $4 == "f" { print $3, $2 }' "$out/lib.map" | sort >"$out/fnames"
  end="$(objdump -h "$out/lib.dll" | awk '$2 == ".text" { printf "%08x", strtonum("0x" $4) + strtonum("0x" $3) }')"
  { cat "$out/fnames"; echo "$end end"; } | awk 'NR > 1 { printf "%s %x\n", prev, strtonum("0x" $1) - strtonum("0x" prev) } { prev = $1 }' >"$out/functions.tsv"
  "$obshape" "$out/lib.dll" "$out/functions.tsv" --out "$out/shapes.tsv" 2>/dev/null
  # "?Name@C@@..." -> "Name"; pops, returns and shape (room depends on where the linker put each function)
  awk 'FILENAME ~ /fnames$/ { n = $2; sub(/^\?/, "", n); sub(/@.*/, "", n); name[sprintf("%x", strtonum("0x" $1))] = n; next }
       { print name[$1] "\t" $3 " " $4 " " $5 }' "$out/fnames" FS='\t' "$out/shapes.tsv" | sort >"$out/got.tsv"
  grep -v "^#" "$here/shapes.$opt.expected" | sort >"$out/want.tsv"
  if diff -u "$out/want.tsv" "$out/got.tsv" >"$out/diff.txt"; then
    echo "$flags: identical ($(wc -l <"$out/got.tsv") functions)"
  else
    echo "$flags: DIFFERS"
    cat "$out/diff.txt"
    status=1
  fi
done
exit $status
