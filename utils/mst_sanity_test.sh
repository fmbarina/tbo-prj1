#!/bin/bash

echo mst padrao:
python3 ./utils/tsp_plot.py ./exemplos/in/pr1002.tsp ./pr1002.mst

echo ""
echo nossa mst:
python3 ./utils/tsp_plot.py ./exemplos/in/pr1002.tsp ./exemplos/mst/pr1002.mst