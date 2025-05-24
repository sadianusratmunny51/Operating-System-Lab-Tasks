#!/bin/bash

read -p "Enter the number of elements: " n
echo "Enter $n numbers separated by space:"
read -a arr

sum=0
for (( i=0; i<n; i++ )); do
  sum=$((sum + arr[i]))
done

echo "Sum of array elements: $sum"


