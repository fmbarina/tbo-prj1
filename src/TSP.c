#include "TSP.h"
#include "tour.h"
#include "UF.h"
#include "adj_matrix.h"
#include "aresta.h"
#include <stdbool.h>

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
            adj_mat_connect(t->adj_mat, aid, bid, aresta_getDist(e));
            UF_union(t->qw_union, aid, bid);
        }
    }
}

void TSP_init_tour(TSP* t){
    // visited_ord[0] = Contador de posicoes visitadas
    // visited_ord[id] = Quando o vertice de ID foi encontrado
    //int visited_ord[TSP_get_vertices(t) + 1];
    // visited_ord[0] = Contador de posicoes a visitar???
    // visited_vet[id] = Se o vertice de ID foi visitado
    //bool visited_vet[TSP_get_vertices(t) + 1];
    // visited_dir[id] = 
    //bool visited_dir[TSP_get_vertices(t) + 1];

    Tour* vertices = tour_init(TSP_get_vertices(t));

    /*  struct com visitado, finalizado, pai
    */
    int i, j;

    // TOUR SERA UMA DFS, Algoritmo veio do professor Berilhes
    // da matéria de Teoria dos Grafos
    int componente = 0;
    int counter = 0;
    for (j = 0; j < TSP_get_vertices(t); j++)
    {
        if(tour_get_visited(vertices,j) != 0){
            componente++;
            counter = DFS(tour_get_vertice(vertices,j),counter, componente);
        }
    }
    
}
