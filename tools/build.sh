#!/usr/bin/env bash
# Builds the hook DLL with the 2003 compiler toolkit under Wine (tools/vc71.sh): build/vc71/version.dll and .map.
#   tools/build.sh
# Every .cpp under src/ is compiled in, plus hook/, the hook table (tools/gen-hooks.sh) and the stubs that lead to
# the original's code (tools/gen-stubs.sh). A source under src/ is compiled with the flags in the nearest FLAGS file
# above it (the original built its parts with different flags); hook/ and the generated files with hook_flags. No C
# runtime: the DLL imports kernel32 (sdk/) and, for the decompiled OpenGL driver, the SDK's opengl32, gdi32,
# user32; the runtime functions decompiled code calls are stubs.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
out=build/vc71 sep='\'  # the toolkit runs under Wine, where an output folder needs a backslash
cl() { "$root/tools/vc71.sh" cl "$@"; }
link() { "$root/tools/vc71.sh" link "$@"; }
hook_flags="/O2 /GX- /W3"
# STLport configured as the original had it: plain new-allocator, __stl_new/__stl_delete out of line (stubs).
common=(/nologo /c /Isdk /Isrc /Ihook /Ithird_party/stlport-4.6/stlport /D_STLP_DONT_FORCE_MSVC_LIB_NAME
  /D_STLP_USE_NEWALLOC /D_STLP_OUT_OF_LINE_STL_NEW /D_STLP_RESIZE_BY_REFERENCE /D_STLP_TREE_ITERATOR_WALKS
  /D_STLP_INSERT_UNIQUE_BY_X)
rm -rf "$out"
mkdir -p "$out/sdk" "$out/obj"

quiet() {  # the toolkit echoes each source name and its progress, in CRLF; show only real messages
  tr -d '\r' | grep -vE '^[A-Za-z0-9_./\\-]+\.cpp$|^   Creating library |^Generating Code\.\.\.$' || true
}

# kernel32.lib: link a throwaway kernel32.dll from the stubs so the import names come out undecorated.
cl /nologo /c /O2 /Isdk "/Fo$out/sdk$sep" sdk/kernel32_stub.cpp 2>&1 | quiet
link /nologo /dll /noentry /nodefaultlib /def:sdk/kernel32.def "/out:$out/sdk/kernel32.dll" \
  "/implib:$out/sdk/kernel32.lib" "$out/sdk/kernel32_stub.obj" 2>&1 | quiet
# wininet.lib alike: decompiled functions call the original's wininet imports
cl /nologo /c /O2 /Isdk "/Fo$out/sdk$sep" sdk/wininet_stub.cpp 2>&1 | quiet
link /nologo /dll /noentry /nodefaultlib /def:sdk/wininet.def "/out:$out/sdk/wininet.dll" \
  "/implib:$out/sdk/wininet.lib" "$out/sdk/wininet_stub.obj" 2>&1 | quiet


flags_for() {  # the FLAGS file nearest above a source under src/, else the hook's flags
  local d
  d="$(dirname "$1")"
  while [[ "$d" == src* ]]; do
    [[ -f "$d/FLAGS" ]] && { grep -v '^#' "$d/FLAGS" | tr '\n' ' '; return; }
    d="$(dirname "$d")"
  done
  echo "$hook_flags"
}

# One compiler run per distinct flag set.
declare -A groups=()
# Link order decides which copy of an inline function (or compiler-generated one) the linker keeps: the first.
# The game's sources link first, as in the original, which kept the game's copies of the framework's inline
# functions (src/game/InlineInstances.cpp); then the instantiations of the framework's generated classes
# (tools/obcmp/obdecl), so their deleting destructors come out with the framework's flags; the instantiations of
# the game's generated classes last, so they never displace another folder's copy.
mapfile -t sources < <(
  find src/game -name '*.cpp' -not -name 'GeneratedClasses_*' | sort
  find src -name 'GeneratedClasses_*.cpp' -not -path 'src/game/*' | sort
  find src hook -name '*.cpp' -not -path 'src/game/*' -not -name 'GeneratedClasses_*' | sort
  find src/game -name 'GeneratedClasses_*.cpp' | sort)
for s in "${sources[@]}"; do
  f="$(flags_for "$s")"
  groups["$f"]+="$s"$'\n'
done
for f in "${!groups[@]}"; do
  mapfile -t files < <(printf '%s' "${groups[$f]}")
  # shellcheck disable=SC2086  # a flag set is a list
  cl "${common[@]}" $f "/Fo$out/obj$sep" "${files[@]}" 2>&1 | quiet
done

# The hook table needs the compiled functions' symbols (tools/gen-hooks.sh).
# and the stubs: the lists, and the STUB annotations of what the objects call (tools/gen-stubs.sh)
"$root/tools/gen-hooks.sh" "$out/hooks.gen.cpp" "$out/obj" "$out/stubs.annotated.txt" "$out/globals.txt"
"$root/tools/gen-stubs.sh" "$out/stubs.gen.cpp" "$out/stubs.annotated.txt"
# and the original's global variables the objects refer to (GLOBAL annotations, tools/gen-globals.sh)
"$root/tools/gen-globals.sh" "$out/obj/globals.gen.obj" "$out/globals.txt"
# shellcheck disable=SC2086
cl "${common[@]}" $hook_flags "/Fo$out/obj$sep" "$out/hooks.gen.cpp" "$out/stubs.gen.cpp" 2>&1 | quiet
sources+=("$out/hooks.gen.cpp" "$out/stubs.gen.cpp")

objs=()
for s in "${sources[@]}"; do objs+=("$out/obj/$(basename "${s%.cpp}").obj"); done
objs+=("$out/obj/globals.gen.obj")
# Based where no constant of the game falls (not the default 0x10000000: flag words like 0x10000001 read as addresses
# inside our DLL to obcmp), and above the game image; as a float, 0x5d000000 is ~5.8e17.
link /nologo /dll /nodefaultlib /entry:DllMain /base:0x5d000000 /def:hook/version.def "/map:$out/version.map" \
  "/out:$out/version.dll" "${objs[@]}" "$out/sdk/kernel32.lib" "$out/sdk/wininet.lib" OpenGL32.Lib Gdi32.Lib User32.Lib 2>&1 | quiet

[[ -f "$out/version.dll" ]] || { echo "build failed" >&2; exit 1; }
# The objects of this successful build, kept beside the output (which the next build wipes first): tools/known-slots.sh
# reads hand-written classes from them, so a later build that fails cannot hand the class generator half a tree.
rm -rf "$out-good-obj.tmp"
cp -a "$out/obj" "$out-good-obj.tmp"
rm -rf "$out-good-obj"
mv "$out-good-obj.tmp" "$out-good-obj"
echo "built $out/version.dll ($(stat -c %s "$out/version.dll") bytes, ${#sources[@]} sources)"
