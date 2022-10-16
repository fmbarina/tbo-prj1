#!/bin/bash

make all || exit 1

rm -rf ./tests/out
mkdir -p ./tests/out

err=

echo '*** Rodando todos os testes ***'

for input in "./tests/in"/* ; do
    echo "---------- #  $input  # ----------"

    # ./trab1 "$input"
    valgrind --leak-check=full --track-origins=yes ./trab1 "$input"

    mv ./*.mst ./tests/out || err=1
    mv ./*.tour ./tests/out || err=1
done

[ -z "$err" ] && echo 'Parece certo' || echo '*** Há erro(s) ***'