#!/bin/bash

read -p "Enter the number of elements: " n
echo "Enter $n numbers separated by space:"
read -a arr

for ((i = 0; i < n; i++)); do
  for ((j = 0; j < n - i - 1; j++)); do
    if (( arr[j] > arr[j+1] )); then
      temp=${arr[j]}
      arr[j]=${arr[j+1]}
      arr[j+1]=$temp
    fi
  done
done

echo "Sorted array in ascending order:"
echo "${arr[@]}"
