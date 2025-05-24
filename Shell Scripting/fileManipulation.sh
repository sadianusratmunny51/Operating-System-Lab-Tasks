#!/bin/bash

filename="demo.txt"

#1.cheching
if [[ -f $filename ]]; then
    echo "File '$filename' already exists."
else
    echo "File '$filename' does not exist. "
    touch $filename
    echo "Creation done ."
fi

#2. writing to file
echo "This is the first line of text." > $filename
echo "Written to $filename."

#3.contents
echo "Reading contents of $filename:"
cat $filename

#4. Countint lines, words, characters
echo "File stats (lines words chars):"
wc $filename

#5. Copy
cp $filename backup.txt
echo "Copied $filename to backup.txt"

#6. Rename
mv $filename renamed_demo.txt
echo "Renamed $filename to renamed_demo.txt"

#7.Deleting the backup  file
if [[ -f backup.txt ]]; then
    rm backup.txt
    echo "Deleted backup.txt"
else
    echo "backup.txt not found, nothing to delete."
fi

#8.final look 
if [[ -f renamed_demo.txt ]]; then
    echo "Final content of renamed_demo.txt:"
    cat renamed_demo.txt
else
    echo "renamed_demo.txt not found."
fi



