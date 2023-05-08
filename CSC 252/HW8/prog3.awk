#!bin/awk/ -f
{if(NR > 2)
{if($7 == "Soph") Soph += 1}
{if($7 == "Frosh") Frosh += 1}
{if($7 == "Senior") Senior += 1}
{if($7 == "Junior") Junior += 1}

{if($7 == "Soph") Soph1 += $6}
{if($7 == "Frosh") Frosh2 += $6}
{if($7 == "Senior") Senior3 += $6}
{if($7 == "Junior") Junior4 += $6}
}

END {
a[0] = Soph
a[1] = Frosh
a[2] = Senior
a[3] = Junior
b[0] = "Soph"
b[1] = "Frosh"
b[2] = "Senior"
b[3] = "Junior"
c[0] = Soph1/Soph
c[1] = Frosh2/Frosh
c[2] = Senior3/Senior
c[3] = Junior4/Junior

Students = 0
class = ""
Averaged = 0
{for(i = 0; i < 4;i++)
    {
        print a[i]
        print b[i]
        print c[i]
        {if (a[i] < c[i]) print "Happy"}
        {if (a[i] < c[i]) print "SAD"}
    }
}
{for(i = 0; i < 4;i++)
    {if(a[i] > Students) Students=a[i]}
}

{for(i = 0; i < 4;i++)
    {if(a[i] == Students) class=b[i]}
}


printf "The " class " class had " "%.0f",Students
printf " students\n"

for(i = 0; i < 4;i++)
    {if(c[i] > Averaged)
        Averaged=c[i]
        class=b[i]
    }

printf "The " class " class had " "%.1f",Averaged
printf " points on the final\n"
}