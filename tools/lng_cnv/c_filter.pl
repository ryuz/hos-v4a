#!/usr/bin/perl

$text .= $_  while (<>);
$text =~ s/\/\*\s*?\*\///gs;
$text =~ s/\/\*\*\s*?\*\///gs;
$text =~ s/\/\*\*<\s*?\*\///gs;
print $text;
