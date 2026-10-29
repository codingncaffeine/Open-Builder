#!/usr/bin/env bash
# Applies a rename map (obdecl --rename-map: "old<TAB>new" per line, class, subobject and method names) to what was
# written by hand around the generated classes: src/ sources, src/classes/ext/*.tsv, hook/stubs.txt; files named
# after a renamed class are renamed too (git mv when tracked). Whole identifiers only; running it twice changes
# nothing.
#   tools/names/apply-rename.sh <map>
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$root"
map="$1"
[[ -s "$map" ]] || { echo "apply-rename: nothing to rename"; exit 0; }
mapfile -t files < <(find src hook -type f \( -name '*.cpp' -o -name '*.h' -o -name '*.tsv' -o -name 'stubs.txt' \) \
  ! -name names.tsv | sort)
perl -i -ne '
  BEGIN {
    open my $m, "<", shift @ARGV or die "map: $!";
    while (<$m>) { chomp; my ($a, $b) = split /\t/; $r{$a} = $b if defined $b && $a ne $b; }
    $re = join "|", map { quotemeta } sort { length($b) <=> length($a) } keys %r;
    $re = qr/(?<![A-Za-z0-9_])($re)(?![A-Za-z0-9_])/;
  }
  my $before = $_;
  s/$re/$r{$1}/g;
  $changed{$ARGV}++ if $_ ne $before;
  print;
  END { printf STDERR "apply-rename: %d files changed\n", scalar keys %changed; }
' "$map" "${files[@]}"
# files named after a class
moved=0
while IFS=$'\t' read -r old new; do
  [[ "$old" == cUnk* || -n "$old" ]] || continue
  for f in src/*/"$old".cpp src/*/"$old".h src/classes/ext/"$old".tsv; do
    [[ "$f" == src/classes/*.h ]] && continue  # generated headers: written under the new name
    [[ -e "$f" ]] || continue
    dest="$(dirname "$f")/$new.${f##*.}"
    [[ -e "$dest" ]] && { echo "apply-rename: $dest exists, $f kept" >&2; continue; }
    if git ls-files --error-unmatch "$f" >/dev/null 2>&1; then git mv "$f" "$dest"; else mv "$f" "$dest"; fi
    moved=$((moved + 1))
  done
done <"$map"
echo "apply-rename: $moved files renamed"
