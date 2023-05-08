#/bin/bash

sed -e 's/,.* //' -e 's/".*//' < thespians.txt
echo ------------------
sed 's/^.* "/"/' < thespians.txt
echo ------------------
sed 's/1.*.* //' < thespians.txt
echo ------------------
sed '/.*B/ s/1.*.* /**** /' < thespians.txt
echo ------------------
sed -e 's/,.* /,/' -e 's/1.*.* //' -e 's/"//' -e 's/"//' < thespians.txt