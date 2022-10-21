#!/bin/bash

declare -i total_lines

[ -z "$1" ] && wc -l ./src/*.c | awk 'END{print}'
[ -n "$1" ] && [ "$1" == "s" ] && wc -l ./src/*.c 
[ -n "$1" ] && [ "$1" == "a" ] && wc -l ./headers/*.h ./src/*.c 
