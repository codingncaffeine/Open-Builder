#!/usr/bin/perl
# Unpacks an InstallShield setup stream (the payload that starts with "InstallShield\0", e.g. the overlay of the
# 2003 compiler toolkit's setup.exe after `7z x setup.exe '[0]'`).
#   tools/isx-unpack.pl <stream> <out dir> [name ...]     (no names = every file)
# Layout: a 46-byte header (signature, u16 file count), then per file a 312-byte record (name[260], u32 flags,
# u32, u32 length, ...) followed by the data. Data with flag 0x2 is encoded per byte as
# ~(swap_nibbles(b) ^ key[i % len(key)]), key = name bytes ^ 13 35 86 07 (measured on the toolkit's Setup.ini:
# every byte decodes to text). Flag 0x4 streams use a different key schedule and are refused.
use strict;
use warnings;

my ($stream, $out, @want) = @ARGV;
die "usage: isx-unpack.pl <stream> <out dir> [name ...]\n" unless $stream && $out;
open my $f, '<:raw', $stream or die "cannot open $stream: $!\n";
local $/;
my $b = <$f>;
die "not an InstallShield stream\n" unless substr($b, 0, 14) eq "InstallShield\0";
mkdir $out;

my @magic = (0x13, 0x35, 0x86, 0x07);
my $n = unpack 'v', substr($b, 14, 2);
my $o = 46;
for (1 .. $n) {
    my $name = unpack 'Z*', substr($b, $o, 260);
    my ($flags, undef, $len) = unpack 'VVV', substr($b, $o + 260, 12);
    my $data = substr($b, $o + 312, $len);
    $o += 312 + $len;
    next if @want && !grep { $_ eq $name } @want;
    die "$name: encoding flag 0x4 is not supported\n" if $flags & 0x4;
    if ($flags & 0x2) {
        my @seed = unpack 'C*', $name;
        my @key = map { $seed[$_] ^ $magic[$_ % 4] } 0 .. $#seed;
        my @d = unpack 'C*', $data;
        for my $i (0 .. $#d) {
            my $c = $d[$i];
            $d[$i] = ~((((($c << 4) | ($c >> 4)) & 0xff) ^ $key[$i % @key])) & 0xff;
        }
        $data = pack 'C*', @d;
    }
    die "unsafe name $name\n" if $name =~ m{[/\\]} || $name =~ /^\.\.?$/;
    open my $w, '>:raw', "$out/$name" or die "cannot write $out/$name: $!\n";
    print $w $data;
    close $w;
    printf "%-40s %10d bytes\n", $name, $len;
}
