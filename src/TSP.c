#include "TSP.h"

#include "UF.h"
#include "adj_matrix.h"
#include "aresta.h"

struct tsp_st
{
    char *name;
    int vertices;
    Vetor *vetorpos;
    VetorAresta *vetorArestas;
    Adj_matrix *adj_mat;
    UF *qw_union;
};

TSP *TSP_init(char *name, int vertices)
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
    vetoraresta_libera(t->vetorArestas);
    vetor_libera(t->vetorpos);
    adj_mat_free(t->adj_mat);
    UF_free(t->qw_union);
    free(t->name);
    free(t);
}

char *TSP_get_name(TSP *t)
{
    return t->name;
}

int TSP_get_vertices(TSP *t)
{
    return t->vertices;
}

Vetor *TSP_get_vetor_pos(TSP *t)
{
    return t->vetorpos;
}

void TSP_preenche_vetor_pos(TSP *t, FILE *f)
{
    Vertex *pos = NULL;

    long i;
    for (i = 0; i < t->vertices; i++)
    {
        pos = file_read_vert(f);
        vetor_set_index(t->vetorpos, pos, i);
    }
}

void TSP_preenche_vetarestas(TSP *t)
{
    // vetorPos já preenchido
    t->vetorArestas = vetoraresta_init(t->vetorpos);
}

void TSP_kruskal(TSP *t)
{
    // TODO: é preciso extrair o id das arestas pra fazer isso
    // Para cada aresta de menor pra maior
    //
    // se MST_find(vertice A) != MST_find(vertice B)
    //      Marcar adjacencia na matriz
    //      MST_union(v1, v2)

    // vetoraresta_sort(t->vetorArestas);

    // long i;
    // for (i = 0; i < vetoraresta_get_Qtd(t->vetorArestas); i++)
    // {
    //     vetoraresta_get_Index(t->vetorArestas, i);
    // }
}