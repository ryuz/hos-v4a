#!/usr/bin/perl

$text .= $_  while (<>);
$text =~ s/%jp{([^}]*)}/$1/gs;
$text =~ s/%..{([^}]*)}//gs;
print $text;
