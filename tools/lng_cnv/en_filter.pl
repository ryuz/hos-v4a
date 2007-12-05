#!/usr/bin/perl

$text .= $_  while (<>);
$text =~ s/%en{([^}]*)}/$1/gs;
$text =~ s/%..{([^}]*)}//gs;
$text =~ s/[\x80-\xff]//gs;
print $text;
