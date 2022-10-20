#include "tour.h"
#include "adj_matrix.h"
#include "assertx.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tour_st
{
    int size;
    int visited;
    int *discovered;
    int *order;
};

Tour *tour_init(int size)
{
    Tour *t = malloc(size * sizeof(Tour));
    t->size = size;
    t->visited = 0;
    t->discovered = calloc(size, sizeof(int));
    t->order = calloc(size, sizeof(int));
    return t;
}

void tour_free(Tour *t)
{
    free(t->discovered);
    free(t->order);
    free(t);
}

void tour_DFS(Tour *t, Adj_matrix *adj, int vertex_id)
{
    /* procedure DFS(G, v) is
     * label v as discovered
     * for all directed edges from v to w that are in G.adjacentEdges(v) do
     *     if vertex w is not labeled as discovered then
     *         recursively call DFS(G, w)
     *
     * Fonte: https://en.wikipedia.org/wiki/Depth-first_search
     */

    t->order[t->visited++] = vertex_id;
    t->discovered[vertex_id - 1] = 1;

    int i;
    for (i = 0; i < t->size; i++)
    {
        if (i + 1 == vertex_id) continue;
        if (t->discovered[i]) continue;

        double E = adj_mat_get(adj, i, vertex_id - 1);

        if (!E) continue; // Caso não esteja conectado, pular vertice

        // i + 1: ID de vértice conectado a vertex_id por arco de valor E
        if (!t->discovered[i]) tour_DFS(t, adj, i + 1);
    }
}

void tour_fprint(Tour *t, FILE *f)
{
    int i;
    for (i = 0; i < t->size; i++)
        fprintf(f, "%d\n", t->order[i]);
}
