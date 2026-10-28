#!/usr/bin/perl
# Writes the Authenticode PKCS#7 blob of a PE file (its certificate table) to stdout, DER-encoded.
#   tools/pe-signature.pl file.exe | openssl pkcs7 -inform DER -print_certs -noout
# With --hash md5|sha1|sha256, prints the file's Authenticode digest instead: the whole file except the checksum
# field, the certificate-table directory entry and the certificate table itself.
use strict;
use warnings;
use Digest::MD5;
use Digest::SHA;

my $algo;
if ($ARGV[0] eq '--hash') { shift; $algo = shift; }
open my $f, '<:raw', $ARGV[0] or die "cannot open $ARGV[0]: $!\n";
local $/;
my $b = <$f>;
my $pe = unpack 'V', substr($b, 0x3c, 4);
die "not a PE file\n" unless substr($b, $pe, 4) eq "PE\0\0";
my $opt = $pe + 24;
my $magic = unpack 'v', substr($b, $opt, 2);
my $dirs = $opt + ($magic == 0x20b ? 112 : 96);
my ($off, $size) = unpack 'VV', substr($b, $dirs + 4 * 8, 8);    # data directory 4 = certificate table
die "no certificate table\n" unless $off && $size;
if ($algo) {
    my $sum = $opt + 64;           # CheckSum field
    my $entry = $dirs + 4 * 8;     # certificate-table directory entry
    my $d = $algo eq 'md5' ? Digest::MD5->new : Digest::SHA->new($algo =~ s/^sha//r);
    $d->add(substr($b, 0, $sum));
    $d->add(substr($b, $sum + 4, $entry - $sum - 4));
    $d->add(substr($b, $entry + 8, $off - $entry - 8));
    $d->add(substr($b, $off + $size)) if $off + $size < length $b;
    print $d->hexdigest, "\n";
    exit 0;
}
my ($len, $rev, $type) = unpack 'Vvv', substr($b, $off, 8);
die "certificate is not PKCS#7 (type $type)\n" unless $type == 2;
print substr($b, $off + 8, $len - 8);
