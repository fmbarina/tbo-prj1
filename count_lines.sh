#!/bin/bash

declare -i total_lines

for file in "./src"/* ; do 
    [ -n "$1" ] && wc -l $file # If any argument present, print lines per file 
    file_lines=$(wc -l $file | awk '{print $1}')
    total_lines+=$(($file_lines))
done

echo $total_lines