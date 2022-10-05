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

    vetor->distancias = calloc((qtd/2)+1, sizeof(double));
    vetor->qtd = qtd;
    return vetor;
}

void vetordist_preenche(VetorDistancia *vetDist, Vetor *vetPos)
{
    for (int i = 0; i < vetor_qtd_elementos(vetPos); i++)
    {
        for(int j = i+1; j< vetor_qtd_elementos(vetPos); j++){
            if(vetDist->distancias[i+j] == 0)
                vetDist->distancias[i+j] = posicao_distancia(vetor_get_index(vetPos,i),
                                                             vetor_get_index(vetPos,j));
        }
    }
    
}

void vetordist_imprime(VetorDistancia* v){
    for (int i = 0; i < v->qtd; i++)
    {
        printf("%d/n", v->distancias[i]);
    }
    
}

void vetordist_libera(VetorDistancia *v)
{
    free(v->distancias);
    free(v);
}