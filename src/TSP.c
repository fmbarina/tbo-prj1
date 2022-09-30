#include "../headers/TSP.h"
#include "../headers/vetor.h"
#include <string.h>

struct tsp
{
    char* nome;
    /*nome só para deixar ai (matriz de localizacoes) */
    Vetor* vetor;
    int nVertices;
};

TSP* TSP_init(char* nome, int numVertices){
    TSP* tsp = (TSP*)malloc(sizeof(TSP));

    tsp->vetor = vetor_init(numVertices);

    tsp->nome = strdup(nome);
    tsp->nVertices = numVertices;
    return tsp;
}

int TSP_get_nvertices(TSP* t){
    return t->nVertices;
}

Vetor* TSP_get_vetor(TSP* t){
    return t->vetor;
}

void TSP_preenche_vetor(TSP* tsp){
    Posicao* pos = NULL;
    for (int i = 0; i < TSP_get_nvertices(tsp) ; i++)
    {
        /* funcao pra ler e criar posição*/
        vetor_set_index(TSP_get_vetor(tsp),pos,i);
    }

}

