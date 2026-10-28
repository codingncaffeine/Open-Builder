#!/usr/bin/env bash
# Builds the hook DLL: build/<toolchain>/version.dll and version.map.
#   tools/build.sh            the 2003 compiler toolkit under Wine (tools/vc71.sh), the matching build: build/vc71
#   tools/build.sh --clang    clang-cl + lld-link, a modern compiler kept building the same sources: build/clang
# Every .cpp under src/ is compiled in, plus hook/. No C runtime: the DLL imports only kernel32 (sdk/).
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
if [[ "${1:-}" == --clang ]]; then
  out=build/clang sep=/
  # /GS- and freestanding: the 2003 compiler has neither stack cookies nor implied memset calls, and there is no CRT
  cl() { clang-cl --target=i686-pc-windows-msvc -fms-compatibility-version=13.10 /GS- /clang:-ffreestanding "$@"; }
  link() { lld-link "$@"; }
else
  out=build/vc71 sep='\'  # the toolkit runs under Wine, where an output folder needs a backslash
  cl() { "$root/tools/vc71.sh" cl "$@"; }
  link() { "$root/tools/vc71.sh" link "$@"; }
fi
rm -rf "$out"
mkdir -p "$out/sdk" "$out/obj"

quiet() {  # both compilers echo each source name, the toolkit in CRLF; show only real messages
  tr -d '\r' | grep -vE '^[A-Za-z0-9_./\\-]+\.cpp$|^   Creating library |^Generating Code\.\.\.$' || true
}

# kernel32.lib: link a throwaway kernel32.dll from the stubs so the import names come out undecorated.
cl /nologo /c /O2 /Isdk "/Fo$out/sdk$sep" sdk/kernel32_stub.cpp 2>&1 | quiet
link /nologo /dll /noentry /nodefaultlib /def:sdk/kernel32.def "/out:$out/sdk/kernel32.dll" \
  "/implib:$out/sdk/kernel32.lib" "$out/sdk/kernel32_stub.obj" 2>&1 | quiet

mapfile -t sources < <(find src hook -name '*.cpp' | sort)
cl /nologo /c /O2 /GX- /W3 /Isdk /Isrc /Ihook "/Fo$out/obj$sep" "${sources[@]}" 2>&1 | quiet
objs=()
for s in "${sources[@]}"; do objs+=("$out/obj/$(basename "${s%.cpp}").obj"); done
link /nologo /dll /nodefaultlib /entry:DllMain /def:hook/version.def "/map:$out/version.map" \
  "/out:$out/version.dll" "${objs[@]}" "$out/sdk/kernel32.lib" 2>&1 | quiet

[[ -f "$out/version.dll" ]] || { echo "build failed" >&2; exit 1; }
echo "built $out/version.dll ($(stat -c %s "$out/version.dll") bytes, ${#sources[@]} sources)"
