#!/usr/bin/perl -w
use strict;
binmode(STDOUT);	# prevent DOS style CRLFs for generated output
while(<STDIN>)
{
    while(s/\t+/' ' x (length($&) * 8 - length($`) % 8)/e) { }
    print $_;
}
exit(0);
