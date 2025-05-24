#!/bin/bash
read -p "Enter the number :" n

num=$n

for((i=1;i<=10;i++));do
  n=$((num*i))
  echo $n
done

