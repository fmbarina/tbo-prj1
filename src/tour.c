#include "tour.h"
#include "adj_matrix.h"
#include "assertx.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

struct tour_st
{
    IDT size;
    IDT visited;
    IDT *order;
    char *discovered;
};

Tour *tour_init(IDT size)
{
    Tour *t = malloc(size * sizeof(Tour));
    t->size = size;
    t->visited = 0;
    t->order = calloc(size, sizeof(IDT));
    t->discovered = calloc(size, sizeof(char));
    return t;
}

void tour_free(Tour *t)
{
    free(t->discovered);
    free(t->order);
    free(t);
}

void tour_DFS(Tour *t, Adj_matrix *adj, IDT vertex_id)
{
    /* procedure DFS(G, v) is
     * label v as discovered
     * for all directed edges from v to w that are in G.adjacentEdges(v) do
     *     if vertex w is not labeled as discovered then
     *         recursively call DFS(G, w)
     *
     * Fonte: https://en.wikipedia.org/wiki/Depth-first_search,
     * Aulas do professor Berilhes em Teoria dos Grafos
     */

    t->order[t->visited++] = vertex_id;
    t->discovered[vertex_id - 1] = 1;

    IDT i;
    for (i = 0; i < t->size; i++)
    {
        // Pular se...
        if (i + 1 == vertex_id) continue; // For o valor equiv. da diagonal
        if (t->discovered[i]) continue;   // O vertex dest. ja foi descoberto
        if (!adj_mat_get(adj, i, vertex_id - 1)) continue; // nao ha conexao

        // i + 1: ID de vértice conectado a vertex_id por arco de valor E
        if (!t->discovered[i]) tour_DFS(t, adj, i + 1);
    }
}

void tour_fprint(Tour *t, FILE *f)
{
    IDT i;
    for (i = 0; i < t->size; i++)
        fprintf(f, "%d\n", t->order[i]);
}
