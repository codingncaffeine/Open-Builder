#!/usr/bin/env bash
# Compiles every source under src/ with today's compilers and their own standard libraries (64-bit, native), warnings
# as errors: the decompiled code has to stay ordinary, portable C++ while it is written, not only when the native
# port (phase 8) comes. The matching build (tools/build.sh) compiles the same sources with the 2003 compiler and STLport.
#   tools/check-portable.sh [compiler ...]     default: g++ and clang++, whichever are installed
set -euo pipefail
cd "$(dirname "$0")/.."
compilers=("$@")
if ((${#compilers[@]} == 0)); then
  for c in g++ clang++; do command -v "$c" >/dev/null && compilers+=("$c"); done
fi
((${#compilers[@]})) || { echo "no compiler found" >&2; exit 2; }
mapfile -t sources < <(find src -name '*.cpp' | sort)
failed=0
for c in "${compilers[@]}"; do
  for s in "${sources[@]}"; do
    "$c" -std=c++17 -Wall -Wextra -Werror -Isrc -c -o /dev/null "$s" || { echo "FAILED: $c $s" >&2; failed=1; }
  done
  echo "$c: ${#sources[@]} sources"
done
exit $failed
