 #!/bin/bash

read -p "Enter the size of array: " n
read -p "Enter numbers separated by space: " -a arr
read -p "Enter the key : " k
idx=-1
for((i=0;i<n;i++));do
 if((arr[i]==k));then
   idx=$((i+1))
    break
  fi

 done
 if((idx!=-1));then
    echo "The index number :  $idx "
 else
    echo "Element not found"

 fi
