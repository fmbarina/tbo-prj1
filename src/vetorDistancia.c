#include "../headers/vetorDistancia.h"

#include "../headers/TSP.h"
#include "../headers/posicao.h"
#include "../headers/vetor.h"

struct vetordist_st
{
    double *distancias;
    int qtd;
};

VetorDistancia *vetordist_init(Vetor *vp)
{
    VetorDistancia *vetor = (VetorDistancia *)malloc(sizeof(VetorDistancia));

    vetor->qtd = vetor_qtd_elementos(vp);
    vetor->distancias = calloc((vetor->qtd * vetor->qtd/2)+1, sizeof(double));

    return vetor;
}

// FIXME: essa funcao 
void vetordist_preenche(VetorDistancia *vd, Vetor *vp)
{
    int i, j;
    for (i = 0; i < vetor_qtd_elementos(vp); i++)
    {
        for(j = i /*+?*/; j < vetor_qtd_elementos(vp); j++){
            if(vd->distancias[i+j] == 0)
                vd->distancias[i+j] = posicao_distancia(vetor_get_index(vp, i),
                                                        vetor_get_index(vp, j));
        }
    }
}

void vetordist_imprime(VetorDistancia* vd){
    int i;
    for (i = 0; i < vd->qtd; i++)
        printf("%d/n", vd->distancias[i]);
}

void vetordist_libera(VetorDistancia *vd)
{
    free(vd->distancias);
    free(vd);
}