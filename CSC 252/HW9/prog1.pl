#!/usr/bin/perl 

my $Total = 0;
my $Count = 0;

while (<STDIN>) {
  my @Columns = split;

  my $Final = $Columns[5];

  $Total += $Final;

  $Count++;
}

$Count = $Count-2;

my $Average = $Total / $Count;

printf "Final Average: %.2f\n", $Average;