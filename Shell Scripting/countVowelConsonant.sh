#!/bin/bash
read -p "Enter a string: " str
vowels=0
consonants=0

for ((i=0; i<${#str}; i++)); do
  ch=${str:$i:1}
  if [[ $ch =~ [aeiouAEIOU] ]]; then
    ((vowels++))
  elif [[ $ch =~ [a-zA-Z] ]]; then
    ((consonants++))
  fi
done

echo "Vowels: $vowels"
echo "Consonants: $consonants"
