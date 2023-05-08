#!/usr/bin/perl

my $LC = 0;

while (<STDIN>) {
  my @Column = split;
  my $Final = $Column[0];
  
  if($LC == 0){
    printf ("%-2s   %-2s Average", $Column[0] , $Column[1]);
  }
  elsif($LC == 1){
    print "\n---------------------------------\n"
  }
  else{
    my $average = ($Column[2] + $Column[3] + $Column[4] + $Column[5]) / 85;
    printf ("%-10s %-9s %.1f %%\n", $Column[0] , $Column[1], $average*100);
  }
  $LC++;
}