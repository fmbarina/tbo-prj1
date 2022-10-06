#include "../headers/TSP.h"

#include <string.h>

#include "../headers/vetor.h"
#include "../headers/vetorDistancia.h"
#include "arquivo.h"

struct tsp_st
{
    char *nome;
    Vetor *vetorpos;
    VetorDistancia* vetordist;
    int nVertices;
};

TSP *TSP_init(char *nome, int numVertices)
{
    TSP *tsp = (TSP *)malloc(sizeof(TSP));

    tsp->nome = strdup(nome);
    tsp->vetorpos = vetor_init(numVertices);
    tsp->vetordist = vetordist_init(tsp->vetorpos);
    tsp->nVertices = numVertices;

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

void TSP_preenche_vet_dist(TSP* tsp){
    vetordist_preenche(tsp->vetordist,tsp->vetorpos);
}

void TSP_libera(TSP*t){
    vetor_libera(t->vetorpos);
    vetordist_libera(t->vetordist);
    free(t->nome);
    free(t);
}