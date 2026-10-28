#!/usr/bin/env bash
# Proves the audio wall of tools/nested.sh before a run: the same checks run once outside (the control: they must
# see the user's sound devices, or the check proves nothing) and once inside the nested session (all must be
# closed). Plays nothing. Exit 0 only when the control sees the devices and the session sees none.
set -u
root="$(cd "$(dirname "$0")/.." && pwd)"
work="$root/scratch/nested-silence"
mkdir -p "$work"

echo "== control, outside the sandbox (must show OPEN lines)"
OB_NESTED_WORK="$work" bash "$root/tools/check-silence-session.sh"
cat "$work/silence.txt"
control_open=$(grep -c '^OPEN' "$work/silence.txt")

echo "== inside the nested session (must be all closed)"
rm -f "$work/silence.txt"
"$root/tools/nested.sh" "$work" 60 "$root/tools/check-silence-session.sh" >/dev/null
cat "$work/silence.txt" 2>/dev/null || { echo "the session wrote nothing"; exit 1; }
inside_open=$(grep -c '^OPEN' "$work/silence.txt")

if (( control_open == 0 )); then echo "FAIL: the control saw no sound device, so the check cannot see the fault"; exit 1; fi
if (( inside_open > 0 )); then echo "FAIL: the wall has holes"; exit 1; fi
echo "PASS: $control_open ways to sound outside, none inside"
