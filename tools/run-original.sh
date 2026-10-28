#!/usr/bin/env bash
# Runs the original game from the local test bed, headless: its own Wine prefix, its own X server (Xvfb),
# an isolated session bus, nothing on the user's desktop. Captures the screen after --shot-after seconds.
#
#   tools/run-original.sh [--driver OpenGL|DirectX|Software] [--seconds N] [--shot-after N] [--out PNG] [--size WxH] [-- extra game args]
#
# The test bed lives in scratch/testbed/ (gitignored): game/ is a copy of the install, prefix/ the Wine prefix.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
bed="$root/scratch/testbed"
seconds=60 shot_after=0 out="" size=1280x720 driver=OpenGL
while [[ $# -gt 0 ]]; do
  case "$1" in
    --seconds) seconds="$2"; shift 2 ;;
    --shot-after) shot_after="$2"; shift 2 ;;
    --out) out="$2"; shift 2 ;;
    --size) size="$2"; shift 2 ;;
    --driver) driver="$2"; shift 2 ;;
    --) shift; break ;;
    *) echo "unknown option: $1" >&2; exit 2 ;;
  esac
done
[[ -x "$bed/game/Apps/SimCity 4.exe" || -f "$bed/game/Apps/SimCity 4.exe" ]] || { echo "no test bed at $bed/game" >&2; exit 1; }

export WINEPREFIX="$bed/prefix" WINEARCH=win64 WINEDEBUG="${WINEDEBUG:--all}"
# No desktop menu entries, file associations, Mono or Gecko prompts from this prefix.
export WINEDLLOVERRIDES="winemenubuilder.exe=d;mscoree=d;mshtml=d${WINEDLLOVERRIDES:+;$WINEDLLOVERRIDES}"
# A private HOME: Wine links the prefix's Documents/Desktop/... to $HOME's folders, and the game writes its
# user folder into Documents. With the real HOME that lands in the user's own Documents (it did, 2026-10-28).
export HOME="$bed/home"
export XDG_CONFIG_HOME="$bed/xdg/config" XDG_DATA_HOME="$bed/xdg/data" XDG_CACHE_HOME="$bed/xdg/cache"
mkdir -p "$HOME" "$XDG_CONFIG_HOME" "$XDG_DATA_HOME" "$XDG_CACHE_HOME" "$bed/logs"
unset WAYLAND_DISPLAY

# Refuses to run while any user folder of the prefix points outside the test bed.
check_prefix_contained() {
  local link target
  [[ -d "$WINEPREFIX/drive_c/users" ]] || return 0
  while IFS= read -r -d '' link; do
    target="$(readlink -f "$link")"
    [[ "$target" == "$bed"/* ]] || { echo "prefix link escapes the test bed: $link -> $target" >&2; return 1; }
  done < <(find "$WINEPREFIX/drive_c/users" -mindepth 2 -maxdepth 2 -type l -print0)
}
export -f check_prefix_contained

w="${size%x*}" h="${size#*x}"
args=(-w "-d:$driver" -Intro:off -CPUCount:1 -CustomResolution:enabled "-r${w}x${h}x32" "$@")

session() {
  set -euo pipefail
  [[ -d "$WINEPREFIX/drive_c" ]] || wineboot -i >/dev/null 2>&1
  check_prefix_contained
  cd "$bed/game/Apps"
  wine "SimCity 4.exe" "${args[@]}" >"$bed/logs/game.out" 2>&1 &
  pid=$!
  # OB_PROBE_DIR: every 15 s, the X window tree and a screenshot, until the run ends.
  if [[ -n "${OB_PROBE_DIR:-}" ]]; then
    mkdir -p "$OB_PROBE_DIR"
    ( t=0; while kill -0 "$pid" 2>/dev/null && (( t < seconds )); do
        sleep 15; t=$(( t + 15 ))
        xwininfo -root -tree >"$OB_PROBE_DIR/tree-$t.txt" 2>&1
        import -window root "$OB_PROBE_DIR/shot-$t.png" 2>/dev/null
      done ) &
  fi
  if [[ -n "$out" && "$shot_after" -gt 0 ]]; then
    sleep "$shot_after"
    import -window root "$out" 2>/dev/null || echo "screen capture failed" >&2
  fi
  local left=$(( seconds - shot_after ))
  (( left > 0 )) && timeout "$left" tail --pid="$pid" -f /dev/null || true
  wineserver -k 2>/dev/null || true
  wait "$pid" 2>/dev/null || true
}
export -f session
export bed out shot_after seconds
export args_str="$(printf '%q ' "${args[@]}")"
xvfb-run -a -s "-screen 0 ${w}x${h}x24" \
  dbus-run-session --config-file="$root/tools/isolated-bus.conf" \
  bash -c 'eval "args=($args_str)"; session'
echo "log: $bed/logs/game.out"
