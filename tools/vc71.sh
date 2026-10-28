#!/usr/bin/env bash
# Runs a tool of the 2003 compiler toolkit (cl, link) under Wine, in the project's own toolchain prefix with a
# private HOME, no display and no desktop integration. Paths in arguments are passed through unchanged, so run it
# from the directory holding the sources and use relative paths.
#
#   tools/vc71.sh cl /nologo /c /O2 foo.cpp
#   tools/vc71.sh link /nologo /dll foo.obj
#
# The toolkit is unpacked (not installed) into scratch/toolchain/vc71: tools/isx-unpack.pl takes the MSI out of
# the setup stream, Wine's msidb exports its tables, cabextract + tools/msi-layout.pl lay out the files.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
tc="$root/scratch/toolchain"
vc="$tc/vc71/Microsoft Visual C++ Toolkit 2003"
[[ -f "$vc/bin/cl.exe" ]] || { echo "no toolkit at $vc" >&2; exit 1; }
tool="$1"; shift

export HOME="$tc/home" XDG_CONFIG_HOME="$tc/xdg/config" XDG_DATA_HOME="$tc/xdg/data" XDG_CACHE_HOME="$tc/xdg/cache"
export WINEPREFIX="$tc/prefix" WINEDEBUG="${WINEDEBUG:--all}"
# No display drivers: a compiler needs no window, and without them Wine never probes the GPU (Mesa warnings).
export WINEDLLOVERRIDES="winemenubuilder.exe=d;mscoree=d;mshtml=d;winex11.drv=d;winewayland.drv=d"
unset DISPLAY WAYLAND_DISPLAY

winpath() { printf 'Z:%s' "${1//\//\\}"; }
export INCLUDE="$(winpath "$vc/include")${OB_INCLUDE:+;$OB_INCLUDE}"
export LIB="$(winpath "$vc/lib")${OB_LIB:+;$OB_LIB}"
export WINEPATH="$(winpath "$vc/bin")"
exec wine "$vc/bin/$tool.exe" "$@"
