#!/usr/bin/perl

my $LC = 0;
my %Classes = ();
my %Averages = ();

while (<STDIN>) {
  my @Column = split;
  
  if($LC > 1){
    $Classes{$Column[6]}++;
    $Averages{$Column[6]} += $Column[5];
  }
  $LC++;
}

my $MAX = 0;
my $CMAX;

#Find biggest class size
while (($Class, $Classes) = each(%Classes)){
    if($Classes > $MAX){
        $MAX = $Classes;
        $CMAX = $Class;
    }
}

print "The $CMAX class had $MAX students\n";

$MAX = 0;
$CMAX = "";
my $avg;
while (($C, $Averages) = each(%Averages)){
    $avg = $Averages/$Classes{$C};
    if($avg > $MAX){
        $MAX = $avg;
        $CMAX = $C;
    }
}

print "The $CMAX class averaged ";
printf  "%.1f",  "$MAX"; 
print " points on the final\n";