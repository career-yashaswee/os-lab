#! /bin/bash
a=0
b=1
n=10

echo="$a"
echo="$b"

for((i=2;i<n;i++))
do
c=$((a+b))
echo "$c"
a=$b
b=$c  
done