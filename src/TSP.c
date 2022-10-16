#include "TSP.h"

#include "UF.h"
#include "adj_matrix.h"
#include "aresta.h"

struct tsp_st
{
    char *name;
    long vertices;
    Vetor *vetorpos;
    VetorAresta *vetorArestas;
    Adj_matrix *adj_mat;
    UF *qw_union;
};

TSP *TSP_init(char *name, long vertices)
{
    TSP *tsp = (TSP *)malloc(sizeof(TSP));

    tsp->name = strdup(name);
    tsp->vertices = vertices;
    tsp->vetorpos = vetor_init(vertices);
    tsp->vetorArestas = NULL;
    tsp->qw_union = UF_init(vertices);
    tsp->adj_mat = adj_mat_init(vertices);

    return tsp;
}

void TSP_free(TSP *t)
{
    adj_mat_free(t->adj_mat);
    UF_free(t->qw_union);
    vetoraresta_free(t->vetorArestas);
    free(t->name);
    vetor_free(t->vetorpos);
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

Vetor *TSP_get_vetor_pos(TSP *t)
{
    return t->vetorpos;
}

Adj_matrix *TSP_get_adj_mat(TSP *t)
{
    return t->adj_mat;
}

void TSP_preenche_vetor_pos(TSP *t, FILE *f)
{
    Vertex *pos = NULL;

    long i;
    for (i = 0; i < t->vertices; i++)
    {
        pos = file_read_vertex(f);
        vetor_set_index(t->vetorpos, pos, i);
    }
}

void TSP_preenche_vetarestas(TSP *t)
{
    t->vetorArestas = vetoraresta_init(t->vetorpos);
}

void TSP_kruskal(TSP *t)
{
    vetoraresta_sort(t->vetorArestas);

    long i;
    for (i = 0; i < vetoraresta_get_qtd(t->vetorArestas); i++)
    {
        Aresta *e = vetoraresta_get_index(t->vetorArestas, i);

        long aid = vertex_getid(aresta_getA(e));
        long bid = vertex_getid(aresta_getB(e));

        if (!UF_connected(t->qw_union, aid, bid))
        {
            adj_mat_connect(t->adj_mat, aid, bid);
            UF_union(t->qw_union, aid, bid);
        }
    }
}