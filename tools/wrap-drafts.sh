#!/usr/bin/env bash
# Puts every unmatched draft ("// CLOSE: 0x<address> score N" and the definition below it, to its closing brace in
# column 0) inside #ifdef OB_DRAFTS ... #endif. The build then leaves the method to the original (its stub), so a
# vtable slot or a thunk that leads to it stays the original's; tools/score.sh defines OB_DRAFTS and scores them.
#   tools/wrap-drafts.sh <file.cpp> ...    (already wrapped drafts are left as they are)
#   tools/wrap-drafts.sh --check           exit 1 and name each draft under src/ the build would compile
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
if [[ "${1:-}" == "--check" ]]; then
  bad=0
  while IFS= read -r f; do
    awk -v f="$f" '/^#ifdef OB_DRAFTS/ { d = 1 } /^#endif/ { d = 0 }
      /^\/\/ CLOSE: 0x/ && !d { print f ": " $0 " is compiled (tools/wrap-drafts.sh " f ")"; bad = 1 }
      END { exit bad }' "$f" || bad=1
  done < <(grep -rl '^// CLOSE: 0x' src || true)
  exit $bad
fi
for f in "$@"; do
  # a draft ends at the first "}" in column 0; another annotation before it = a CLOSE line with no body (a note)
  tmp="$f.wrap-tmp"
  perl -0ne '
    my (@out, $start);
    my ($wrapped, $open) = (0, 0);
    for my $line (split /(?<=\n)/) {
      if ($line =~ /^#ifdef OB_DRAFTS/) { $wrapped = 1 }
      elsif ($line =~ /^#endif/ && $wrapped) { $wrapped = 0 }
      if ($open && $line =~ m{^// (FUNCTION|CLOSE|STUB|GLOBAL|SYNTHETIC|VTABLE):}) {
        # take its #ifdef back
        for (my $i = $#out; $i >= 0; --$i) { if ($out[$i] eq "#ifdef OB_DRAFTS\n") { splice @out, $i, 1; last } }
        $open = 0;
      }
      if (!$wrapped && !$open && $line =~ m{^// CLOSE: 0x}) {
        push @out, "#ifdef OB_DRAFTS\n";
        ($open, $start) = (1, $line);
        chomp $start;
        push @out, $line;
        next;
      }
      push @out, $line;
      if ($open && $line =~ /^\}/) { push @out, "#endif\n"; $open = 0 }
    }
    die "$ARGV: the draft at \"$start\" does not end\n" if $open;
    print join "", @out;' "$f" >"$tmp" || { rm -f "$tmp"; exit 1; }
  [[ -s "$tmp" ]] && mv "$tmp" "$f"
done
