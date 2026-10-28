#!/usr/bin/env bash
# Builds a third-party library's sources with the 2003 compiler into one DLL with a /MAP, every function kept, so
# tools/obsig can find each of them in the original program.
#   tools/build-lib.sh <out dir> "<cl flags>" <source.c|.cpp> [...]
# Writes <out dir>/lib.dll and <out dir>/lib.map. Source paths may be absolute; they are compiled from their own
# folders' parent, with -I for every source folder.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
out="$1" flags="$2"; shift 2
mkdir -p "$out"
out="$(cd "$out" && pwd)"
rm -rf "$out/obj" "$out/lib.dll" "$out/lib.map"
mkdir -p "$out/obj"
winpath() { printf 'Z:%s' "${1//\//\\}"; }
includes=()
for d in $(for s in "$@"; do dirname "$(realpath "$s")"; done | sort -u); do includes+=("/I$(winpath "$d")"); done
srcs=()
for s in "$@"; do srcs+=("$(winpath "$(realpath "$s")")"); done
quiet() { tr -d '\r' | grep -vE '^[A-Za-z0-9_.-]+\.c(pp)?$|^   Creating library |^Generating Code\.\.\.$' || true; }
# shellcheck disable=SC2086  # flags are a list
"$root/tools/vc71.sh" cl /nologo /c $flags "${includes[@]}" "/Fo$(winpath "$out/obj")\\" "${srcs[@]}" 2>&1 | quiet
objs=()
for o in "$out"/obj/*.obj; do objs+=("$(winpath "$o")"); done
"$root/tools/vc71.sh" link /nologo /dll /noentry /opt:noref /force:unresolved "/map:$(winpath "$out/lib.map")" \
  "/out:$(winpath "$out/lib.dll")" "${objs[@]}" libcmt.lib 2>&1 | quiet | { grep -v 'LNK4088\|unresolved external' || true; } | head -20
[[ -f "$out/lib.dll" ]] || { echo "link failed" >&2; exit 1; }
echo "built $out/lib.dll: ${#objs[@]} objects, $(grep -c ' f ' "$out/lib.map") functions in the map"
