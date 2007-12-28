#!/usr/bin/perl

open(IN, $ARGV[0]) || die("$! : $ARGV[0]");
binmode IN;
open(OUT, ">$ARGV[1]") || die("$! : $ARGV[1]");
binmode OUT;

$size = -s $ARGV[0];
read(IN, $buf, $size);
print OUT $buf;
for ($i = $size; $i < 1474560; $i++)
{
	print OUT "\0";
}
close(IN);
close(OUT);

