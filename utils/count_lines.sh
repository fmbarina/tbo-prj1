#!/bin/bash

declare -i total_lines

# FIXME: use find -exec instead of a for loop(?)
for file in $(find ./src -name '*.c'); do 
    [ -n "$1" ] && wc -l "$file" # If any argument present, print lines per file 
    file_lines=$(wc -l "$file" | awk '{print $1}')
    total_lines+=$file_lines
done

echo "$total_lines"