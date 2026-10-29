#!/usr/bin/env bash
# Brings a finished agent wave into the tree, in the order that works, stopping at the first step that fails:
#   1. drafts out of the build (tools/wrap-drafts.sh on every file with a "// CLOSE:" line)
#   2. every class header again from the ext files (tools/gen-classes.sh; it reads hand-written classes from the
#      last successful build, so run it after the agents, never with a half-built tree in between)
#   3. every decompiled file scored (tools/score.sh): a function annotated FUNCTION that does not score 0 is listed
#   4. the hook build and the match against the original (tools/match.sh)
#   5. the native compilers (tools/check-portable.sh) and the content rules (tools/check-content.sh)
# Then the game runs with the hooks (tools/run-original.sh --hook --plain --seconds 60) — by hand, it is the slow one.
#   tools/integrate.sh               logs in scratch/integrate/
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
log=scratch/integrate
rm -rf "$log"
mkdir -p "$log"
step() {  # name, command...: runs it into its log, stops the run when it fails
  local name="$1"
  shift
  printf '%-10s ' "$name"
  if "$@" >"$log/$name.log" 2>&1; then
    echo "ok"
  else
    echo "FAILED (see $log/$name.log)"
    tail -15 "$log/$name.log"
    exit 1
  fi
}
wrapall() {
  local files
  mapfile -t files < <(grep -rl '^// CLOSE: 0x' src || true)
  ((${#files[@]} == 0)) || tools/wrap-drafts.sh "${files[@]}"
  tools/wrap-drafts.sh --check
}
step drafts wrapall
step classes tools/gen-classes.sh
scoreall() {
  local bad=0
  for f in $(grep -rl '^// FUNCTION: 0x' src --include=*.cpp | grep -v '/Generated'); do
    # a FUNCTION that is not 0 (score.sh exits 1 for any draft; a draft's score is its own business)
    { tools/score.sh "$f" || true; } | awk -v f="$f" '/  FUNCTION  score [1-9]/ || /cannot be scored|does not compile/ { print f ": " $0; bad = 1 }
      /^ {13}address/ { print f ": " $0 } END { exit bad }' || bad=1
  done
  return $bad
}
step score scoreall
step match tools/match.sh
step portable tools/check-portable.sh
step content tools/check-content.sh
grep -E '^total' "$log/match.log"
echo "next: tools/run-original.sh --hook --plain --seconds 60 (alive 60 s), then commit"
