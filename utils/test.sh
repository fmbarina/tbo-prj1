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

[ -n "$err" ] && echo '*** Há erro(s) ***'

echo '*** Comparando peso da MST ***'

for mst in "./tests/mst"/* ; do
    basename="(basename $mst)"
    noext=${basename%.*}

    python3 ./utils/tsp_plot.py ./tests/in/"$noext".tsp "$mst"
    python3 ./utils/tsp_plot.py ./tests/in/"$noext".tsp ./"$(basename "$mst")"
done

[ -z "$err" ] && echo 'Parece certo' || echo '*** Há erro(s) ***'