#!/bin/sh
cat /etc/passwd | sed '/^#/d' | sed -n '1d;p;n' | cut -d : -f 1 | rev | sort -r | sed "$FT_LINE1"','"$FT_LINE2"'!d' | sed -ne 'H;${x;s/\n/, /g;p;}' | sed -e 's/^,//;s/^ //;s/$/./'
