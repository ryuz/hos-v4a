#!/usr/bin/perl

open(OUT_IMG, ">$ARGV[0]") || die("$! : $ARGV[0]");
binmode OUT_IMG;

open(IPL, $ARGV[1]) || die("$! : $ARGV[1]");
binmode IPL;

open(MODULE, $ARGV[2]) || die("$! : $ARGV[2]");
binmode MODULE;

$size = -s $ARGV[1];
if ( $size > 512 ) { $size = 512; }
read(IPL, $buf, $size);
print OUT_IMG $buf;
for ($i = $size; $i < 512; $i++)
{
	print OUT_IMG "\0";
}

$size = -s $ARGV[2];
read(MODULE, $buf, $size);
print OUT_IMG $buf;
for ($i = $i + $size; $i < 1474560; $i++)
{
	print OUT_IMG "\0";
}



close(OUT_IMG);
close(IPL);
close(SWITCH32);

