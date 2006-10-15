#!/usr/bin/perl

$text .= $_  while (<>);
$text =~ s/%en{([^}]*)}/$1/gs;
$text =~ s/%..{([^}]*)}//gs;
print $text;
