#include "TSP.h"
#include "UF.h"
#include "adj_matrix.h"
#include "edge.h"
#include "tour.h"
#include "vertex.h"
#include <stdbool.h>

struct tsp_st
{
    char *name;
    long vertices;
    Edge_v *edge_v;
    Vertex_v *vertex_v;
    Adj_matrix *adj_mat;
    UF *qw_union;
    Tour *tour;
};

TSP *TSP_init(char *name, long vertices)
{
    TSP *tsp = (TSP *)malloc(sizeof(TSP));
    tsp->name = strdup(name);
    tsp->vertices = vertices;
    tsp->edge_v = NULL;
    tsp->vertex_v = vertex_v_init(vertices);
    tsp->adj_mat = adj_mat_init(vertices);
    tsp->qw_union = UF_init(vertices);
    tsp->tour = tour_init(vertices);
    return tsp;
}

void TSP_free(TSP *t)
{
    free(t->name);
    edge_v_free(t->edge_v);
    vertex_v_free(t->vertex_v);
    UF_free(t->qw_union);
    adj_mat_free(t->adj_mat);
    tour_free(t->tour);
    free(t);
}

char *TSP_get_name(TSP *t)
{
    return t->name;
}

long TSP_get_vertices(TSP *t)
{
    return t->vertices;
}

Adj_matrix *TSP_get_adj_mat(TSP *t)
{
    return t->adj_mat;
}

Tour *TSP_get_tour(TSP *t)
{
    return t->tour;
}

void TSP_fill_vertices(TSP *t, FILE *f)
{
    Vertex *pos = NULL;

    long i;
    for (i = 0; i < t->vertices; i++)
    {
        pos = file_read_vertex(f);
        vertex_v_set_index(t->vertex_v, pos, i);
    }
}

void TSP_fill_edges(TSP *t)
{
    t->edge_v = edge_v_init(t->vertex_v);
}

void TSP_kruskal(TSP *t)
{
    edge_v_sort(t->edge_v);

    long i;
    for (i = 0; i < edge_v_len(t->edge_v); i++)
    {
        Edge *e = edge_v_get_index(t->edge_v, i);

        long aid = vertex_getid(edge_geta(e));
        long bid = vertex_getid(edge_getb(e));

        if (!UF_connected(t->qw_union, aid, bid))
        {
            adj_mat_set(t->adj_mat, aid, bid, edge_getdist(e));
            UF_union(t->qw_union, aid, bid);
        }
    }
}

void TSP_tour(TSP *t)
{
    tour_DFS(t->tour, t->adj_mat, 1);
}
