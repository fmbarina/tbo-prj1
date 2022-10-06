#include "../headers/TSP.h"

#include <string.h>

#include "../headers/vetor.h"

struct tsp_st
{
    char *nome;
    Vetor *vetor;
    int nVertices;
};

TSP *TSP_init(char *nome, int numVertices)
{
    TSP *tsp = (TSP *)malloc(sizeof(TSP));

    tsp->nome = strdup(nome);
    tsp->vetor = vetor_init(numVertices);
    tsp->nVertices = numVertices;

    return tsp;
}

int TSP_get_nvertices(TSP *t)
{
    return t->nVertices;
}

Vetor *TSP_get_vetor(TSP *t)
{
    return t->vetor;
}

void TSP_preenche_vetor(TSP *t)
{
    Posicao *pos = NULL;
    
    int i;
    for (i = 0; i < t->nVertices; i++)
    {
        /* funcao pra ler e criar posição*/
        vetor_set_index(t->vetor, pos, i);
    }
}
