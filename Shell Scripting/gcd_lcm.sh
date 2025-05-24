#!/bin/bash

read -p "Enter number a :" a
read -p "Enter number b :" b
temp1=$b
temp2=$a
while((b!=0));do
 
  temp=$b 
  b=$((a % b)) 
  a=$temp 
done 
gcd=$a

echo "the gcd is $gcd"
 

lcm=$((temp1*temp2/gcd))
#lcm=$((lcm/gcd))
echo "The lcm is $lcm"
