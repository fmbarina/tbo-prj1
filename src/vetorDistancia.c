#include "vetorDistancia.h"
#include "TSP.h"
#include "posicao.h"
#include "vetor.h"

struct vetorDistancia_st
{
    double *distancias;
    int qtd;
};

VetorDistancia *vetordist_init(TSP *tsp)
{
    int qtd = TSP_get_nvertices(tsp);

    VetorDistancia *vetor = (VetorDistancia *)calloc(1, sizeof(VetorDistancia));

    vetor->distancias = calloc(qtd, sizeof(double));
    vetor->qtd = qtd;
    return vetor;
}

void vetordist_preenche(VetorDistancia *vetDist, Vetor *vetPos)
{
    // TODO: pensar em como fazer isso:
}

void vetordist_libera(VetorDistancia *v)
{
    free(v->distancias);
    free(v);
}