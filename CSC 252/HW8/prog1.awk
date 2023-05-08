#!bin/awk/ -f

NR > 2 {total += $6} END {if (NR > 0) print "Final Average: " total / (NR-2)}