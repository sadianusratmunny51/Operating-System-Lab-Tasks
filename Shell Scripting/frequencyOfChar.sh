#!/bin/bash
read -p "Enter a string: " str

for ((i=0; i<${#str}; i++)); do
  ch=${str:$i:1}
  count=0
  for ((j=0; j<${#str}; j++)); do
    if [[ ${str:$j:1} == "$ch" ]]; then
      ((count++))
    fi
  done
  echo "$ch → $count"
done
