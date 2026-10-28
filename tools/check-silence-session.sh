#!/usr/bin/env bash
# Session for tools/check-silence.sh: reports, from inside the nested session, every way to sound that is still
# open. Writes $OB_NESTED_WORK/silence.txt; a line starting with OPEN is a hole in the wall.
out="$OB_NESTED_WORK/silence.txt"
: >"$out"
ur="/run/user/$(id -u)"
devs=$(find /dev/snd -mindepth 1 2>/dev/null | wc -l)
(( devs == 0 )) && echo "closed: /dev/snd is empty" >>"$out" || echo "OPEN: /dev/snd has $devs entries" >>"$out"
for s in "$ur/pipewire-0" "$ur/pipewire-0-manager" "$ur/pulse/native"; do
  if [ -S "$s" ]; then echo "OPEN: audio socket $s" >>"$out"; else echo "closed: $s is not a socket" >>"$out"; fi
done
if command -v aplay >/dev/null; then
  # Lists playback devices only; plays nothing.
  n=$(aplay -l 2>/dev/null | grep -c '^card')
  (( n == 0 )) && echo "closed: ALSA lists no playback cards" >>"$out" || echo "OPEN: ALSA lists $n playback cards" >>"$out"
fi
if command -v pactl >/dev/null; then
  pactl info >/dev/null 2>&1 && echo "OPEN: pactl reached an audio server" >>"$out" || echo "closed: pactl reaches no audio server" >>"$out"
fi
