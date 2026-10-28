#!/usr/bin/env bash
# Fails if the tree that would be committed holds anything of the original program: executables or DLLs (by
# their MZ header, whatever the name), game archives (DBPF), Ghidra projects, or any file over 1 MB.
#   tools/check-content.sh
set -euo pipefail
cd "$(dirname "$0")/.."
bad=0
while IFS= read -r -d '' f; do
  [[ -f "$f" ]] || continue
  magic="$(head -c 4 "$f" | tr -d '\0')"
  reason=""
  [[ "$magic" == MZ* ]] && reason="executable (MZ header)"
  [[ "$magic" == DBPF ]] && reason="game archive (DBPF)"
  [[ "$f" =~ \.(gpr|rep|gzf)$ ]] && reason="Ghidra project"
  (( $(stat -c %s "$f") > 1048576 )) && reason="${reason:-over 1 MB}"
  if [[ -n "$reason" ]]; then echo "not allowed: $f — $reason"; bad=1; fi
done < <(git ls-files -z --cached --others --exclude-standard)
(( bad == 0 )) && echo "content check: clean"
exit $bad
