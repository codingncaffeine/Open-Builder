#!/usr/bin/env bash
# Runs a session script inside a private, virtual KWin with Xwayland: GPU-accelerated, but nothing it starts
# appears on the desktop, reaches the desktop's D-Bus, or can make a sound.
#
#   tools/nested.sh WORK_DIR SECONDS SESSION_SCRIPT
#
# Isolation: a private session bus that activates no services (isolated-bus.conf); every XDG directory, the
# runtime one included, inside WORK_DIR or a private /tmp folder; the compositor refuses to start otherwise.
# After the run, a leak check lists files changed in the real home that a test run must never touch.
# KWin splits --exit-with-session on spaces, so the session script is reached through a space-free link.
set -u
[ $# -eq 3 ] || { sed -n '2,11p' "$0"; exit 2; }
HERE="$(cd "$(dirname "$0")" && pwd)"
WORK="$(mkdir -p "$1" && cd "$1" && pwd)"; SECS="$2"; SESSION_SRC="$(cd "$(dirname "$3")" && pwd)/$(basename "$3")"
[ -x "$SESSION_SRC" ] || { echo "nested: $SESSION_SRC is not an executable script"; exit 2; }
command -v kwin_wayland >/dev/null 2>&1 || { echo "nested: kwin_wayland not found"; exit 2; }

LINK="/tmp/openbuilder-$(id -u)-session-$$"
ln -sfn "$SESSION_SRC" "$LINK"
K="$WORK/kwin"
rm -rf "$K"; mkdir -p "$K/config" "$K/state" "$K/data" "$K/cache"
RT="/tmp/openbuilder-$(id -u)-kwrt-$$"; mkdir -p "$RT"; chmod 700 "$RT"
printf '[Wayland]\nEnablePrimarySelection=false\n' > "$K/config/kwinrc"

export OB_NESTED_WORK="$WORK"
export XDG_CONFIG_HOME="$K/config" XDG_STATE_HOME="$K/state" XDG_DATA_HOME="$K/data" XDG_CACHE_HOME="$K/cache" XDG_RUNTIME_DIR="$RT"
unset DISPLAY WAYLAND_DISPLAY JOURNAL_STREAM
for v in XDG_CONFIG_HOME XDG_STATE_HOME XDG_DATA_HOME XDG_CACHE_HOME; do
  case "${!v}" in "$K"/*) ;; *) echo "isolation guard: $v=${!v} is outside $K, refusing"; exit 99;; esac
done
case "$XDG_RUNTIME_DIR" in /tmp/openbuilder-*-kwrt-*) ;; *) echo "isolation guard: runtime dir not private, refusing"; exit 99;; esac

# No sound, by construction: the whole session runs in a mount namespace where /dev/snd is an empty tmpfs and the
# user's audio-server sockets are covered, so nothing started inside can open a sound device or reach PipeWire or
# PulseAudio, whatever its own settings say (a Wine run once opened the HDMI device directly through ALSA).
command -v bwrap >/dev/null 2>&1 || { echo "nested: bwrap not found; refusing to run without the audio wall"; exit 2; }
UR="/run/user/$(id -u)"
silence=(bwrap --dev-bind / / --tmpfs /dev/snd)
[ -d "$UR/pulse" ] && silence+=(--tmpfs "$UR/pulse")
for s in "$UR"/pipewire-0 "$UR"/pipewire-0-manager; do [ -e "$s" ] && silence+=(--ro-bind /dev/null "$s"); done
silence+=(--)

START=$(date '+%Y-%m-%d %H:%M:%S')
timeout -k 5 -s TERM "$SECS" "${silence[@]}" dbus-run-session --config-file="$HERE/isolated-bus.conf" -- kwin_wayland --virtual --xwayland --no-lockscreen --no-global-shortcuts --socket "wayland-openbuilder-$$" --width "${OB_WIDTH:-1280}" --height "${OB_HEIGHT:-720}" --exit-with-session "$LINK" > "$K/kwin.txt" 2>&1
STATUS=$?
rm -f "$LINK"
if [ -d "$RT/doc" ]; then fusermount3 -u "$RT/doc" 2>/dev/null; fi
rm -rf "$RT"
echo "nested: compositor exit $STATUS"
echo "--- real-home leak check (anything listed is a leak) ---"
find ~/.config ~/.local/state -maxdepth 2 -newermt "$START" \( -name 'kwin*' -o -name 'kglobal*' -o -name 'kdeglobals' \) 2>/dev/null
find ~/Documents ~/Desktop ~/.wine -maxdepth 1 -newermt "$START" 2>/dev/null
echo "--- end leak check ---"
exit $STATUS
