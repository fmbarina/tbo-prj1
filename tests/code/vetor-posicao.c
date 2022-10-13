#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "vertice.h"

int main(void){
    Vertice* um = vertice_init(1, 1, 1);
    Vertice* dois = vertice_init(1, 2, 1);
    Vertice* tres = vertice_init(1, 3, 1);
    Vertice* quatro = vertice_init(1, 4, 1);
    Vertice* cinco = vertice_init(1, 5, 1);

    Vetor* vet = vetor_init(5);
    //printf("()\n");
    vetor_set_index(vet, um, 0);
    vetor_set_index(vet, dois, 1);
    vetor_set_index(vet, tres, 1);
    vetor_set_index(vet, quatro, 1);
    vetor_set_index(vet, cinco, 1);
    
    vetor_imprime(vet);

    vetor_libera(vet);
    vertice_free(um);
    vertice_free(dois);
    vertice_free(tres);
    vertice_free(quatro);
    vertice_free(cinco);

    return 0;
}