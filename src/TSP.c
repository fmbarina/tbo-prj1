#include "../headers/TSP.h"


struct tsp_st
{
    char *nome;
    Vetor *vetorpos;
    VetorAresta* vetorArestas;
    int nVertices;
    MST* minimalSpanningTree;
};

TSP *TSP_init(char *nome, int numVertices)
{
    TSP *tsp = (TSP *)malloc(sizeof(TSP));

    tsp->nome = strdup(nome);
    tsp->vetorpos = vetor_init(numVertices);
    tsp->vetorArestas = NULL;
    tsp->nVertices = numVertices;
    tsp->minimalSpanningTree = mst_init();

    return tsp;
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
    Posicao *pos = NULL;
    
    int i;
    for (i = 0; i < t->nVertices; i++)
    {
        pos = arq_le_pos(f);
        vetor_set_index(t->vetorpos, pos, i);
    }
}

void TSP_libera(TSP*t){
    vetor_libera(t->vetorpos);
    vetoraresta_libera(t->vetorArestas);
    free(t->nome);
    free(t);
}

char* TSP_get_name(TSP*t){
    return t->nome;
}

void TSP_preenche_vetarestas(TSP*t){
    //vetorPos já preenchido
    t->vetorArestas = vetoraresta_init(t->vetorpos);
}