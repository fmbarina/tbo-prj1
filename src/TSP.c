#include "TSP.h"
#include "UF.h"
#include "adj_matrix.h"
#include "edge.h"
#include "tour.h"
#include "vertex.h"
#include <stdbool.h>
#include <string.h>
#include "common.h"
#include "timer.h"

struct tsp_st
{
    char *name;
    IDT vertices;
    Edge_v *edge_v;
    Vertex_v *vertex_v;
    Adj_matrix *adj_mat;
    UF *qw_union;
    Tour *tour;
};

TSP *TSP_init(char *name, IDT vertices)
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

IDT TSP_get_vertices(TSP *t)
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

    IDT i;

    double start = timer_clock();

    for (i = 0; i < t->vertices; i++)
    {
        pos = file_read_vertex(f);
        vertex_v_set_index(t->vertex_v, pos, i);
    }
    double end = timer_clock();
    timer_print(start, end, "Leitura dos dados");
}

void TSP_fill_edges(TSP *t)
{
    t->edge_v = edge_v_init(t->vertex_v);
}

void TSP_kruskal(TSP *t)
{

    double start = timer_clock();
    edge_v_sort(t->edge_v);
    double end = timer_clock();
    timer_print(start, end, "Ordenar aresta");


    long i;

    start = timer_clock();
    for (i = 0; i < edge_v_len(t->edge_v); i++)
    {
        Edge *e = edge_v_get_index(t->edge_v, i);
        IDT aid = vertex_getid(edge_geta(e));
        IDT bid = vertex_getid(edge_getb(e));

        if (!UF_connected(t->qw_union, aid, bid))
        {
            adj_mat_set(t->adj_mat, aid, bid, 1);
            UF_union(t->qw_union, aid, bid);
        }
    }
    end = timer_clock();
    timer_print(start,end, "Obter mst");
}

void TSP_tour(TSP *t)
{
    double start = timer_clock();
    tour_DFS(t->tour, t->adj_mat, 1);
    double end = timer_clock();
    timer_print(start, end, "Obter tour");
}
