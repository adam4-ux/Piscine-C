#!/bin/sh
echo "$FT_NBR1 + $FT_NBR2" | sed "s/'/0/g" | tr '\\"?!' '1234' | tr "mrdoc" "01234" | tr "'" "0" | xargs echo "obase=13; ibase=5;" | BC_LINE_LENGTH=0 bc | tr "0123456789ABC" "gtaio luSnemf"