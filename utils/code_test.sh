#!/bin/bash

# Remove main
mv ./src/main.c ./src/.main.c.

for input in "./tests/code"/* ; do
    echo "---------- #  $input  # ----------"

    cp "$input" ./src/

    make all || break 
    valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./trab1 "$input"

    rm -f "./src/$(basename "$input")"
done

# Add back main
mv ./src/.main.c. ./src/main.c

# Cleanup
rm -f "./src/$(basename "$input")"
rm -f ./*.mst ./tests/out || err=1
rm -f ./*.tour ./tests/out || err=1