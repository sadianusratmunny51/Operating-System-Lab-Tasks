#!/bin/bash
read -p "Enter number n: "  n
fact=1
for((i=2;i<=n;i++)); do
((fact*=i))
done
echo "Factorial of $n is $fact"
