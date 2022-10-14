#include "TSP.h"
#include "aresta.h"


struct tsp_st
{
    char *nome;
    int nVertices;
    Vetor *vetorpos;
    VetorAresta* vetorArestas;
    MST* minimalSpanningTree;
};

TSP *TSP_init(char *nome, int numVertices)
{
    TSP *tsp = (TSP *)malloc(sizeof(TSP));

    tsp->nome = strdup(nome);
    tsp->nVertices = numVertices;
    tsp->vetorpos = vetor_init(numVertices);
    tsp->vetorArestas = NULL;
    tsp->minimalSpanningTree = MST_init(numVertices);

    return tsp;
}

void TSP_libera(TSP*t){
    vetoraresta_libera(t->vetorArestas);
    vetor_libera(t->vetorpos);
    free(t->nome);
    MST_libera(t->minimalSpanningTree);
    free(t);
}

char* TSP_get_name(TSP*t){
    return t->nome;
}

int TSP_get_nvertices(TSP *t)
{
    return t->nVertices;
}

Vetor *TSP_get_vetor_pos(TSP *t)
{
    return t->vetorpos;
}

void TSP_preenche_vetor_pos(TSP *t, FILE* f)
{
    Vertice *pos = NULL;
    
    int i;
    for (i = 0; i < t->nVertices; i++)
    {
        pos = arq_le_pos(f);
        vetor_set_index(t->vetorpos, pos, i);
    }
}

void TSP_preenche_vetarestas(TSP*t){
    //vetorPos já preenchido
    t->vetorArestas = vetoraresta_init(t->vetorpos);
}

void TSP_kruskal(TSP *t)
{
    // Para cada aresta de menor pra maior
        // se MST_find(vertice 1) != MST_find(vertice 1)
            // Marcar adjacencia na matriz
            // MST_union(v1, v2)
    unsigned long int i;
    for (i = 0; i < vetoraresta_get_Qtd(t->vetorArestas); i++)
    {
        //vetoraresta_get_Index(t->vetorArestas, i); //TODO: ja volto
    }
}