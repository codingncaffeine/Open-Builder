#!/usr/bin/perl
# Lays out the files of an extracted MSI cabinet under their installed names and folders.
#   tools/msi-layout.pl <tables dir> <cab dir> <out dir>
# <tables dir> holds File.idt, Component.idt and Directory.idt (`wine msidb -d x.msi -f DIR -e File Component
# Directory`); <cab dir> holds the cabinet's files named by their File key (cabextract of the MSI's .cab).
use strict;
use warnings;
use File::Copy;
use File::Path qw(make_path);

my ($tables, $cab, $out) = @ARGV;
die "usage: msi-layout.pl <tables dir> <cab dir> <out dir>\n" unless $out;

sub rows {
    my ($file) = @_;
    open my $f, '<', "$tables/$file" or die "cannot open $tables/$file: $!\n";
    my @rows;
    my $n = 0;
    while (my $line = <$f>) {
        $line =~ s/\r?\n$//;
        next if $n++ < 3;    # column names, column types, table name + keys
        push @rows, [split /\t/, $line, -1];
    }
    return @rows;
}

sub long_name { my ($n) = @_; $n =~ s/^.*\|//; return $n; }

my %dir;    # Directory => [parent, target name]
for my $r (rows('Directory.idt')) {
    my ($id, $parent, $default) = @$r;
    my $target = (split /:/, $default)[0];
    $dir{$id} = [$parent, long_name($target)];
}
my %path;
sub dir_path {
    my ($id) = @_;
    return $path{$id} if exists $path{$id};
    my ($parent, $name) = @{ $dir{$id} // die "unknown directory $id\n" };
    my $p = (!$parent || $parent eq $id) ? '' : dir_path($parent);
    $p = $name eq '.' || $id eq 'TARGETDIR' ? $p : ($p eq '' ? $name : "$p/$name");
    die "unsafe path $p\n" if $p =~ m{(^|/)\.\.(/|$)};
    return $path{$id} = $p;
}

my %component = map { $_->[0] => $_->[2] } rows('Component.idt');
my $count = 0;
for my $r (rows('File.idt')) {
    my ($key, $comp, $name) = @$r;
    my $d = dir_path($component{$comp} // die "unknown component $comp\n");
    my $to = "$out/" . ($d eq '' ? '' : "$d/");
    make_path($to);
    copy("$cab/$key", $to . long_name($name)) or die "copy $key: $!\n";
    $count++;
}
print "$count files laid out under $out\n";
