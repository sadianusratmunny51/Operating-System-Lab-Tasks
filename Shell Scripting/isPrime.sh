#!/bin/bash
read -p "Enter the number: " n

isPrime=1
for ((i = 2; i < n; i++)); do
  if (( n % i == 0 )); then
    isPrime=0
    break
  fi
done

if (( n < 2 )); then
  isPrime=0
fi

if (( isPrime == 0 )); then
  echo "The number $n is not prime"
else
  echo "The number $n is prime"
fi

