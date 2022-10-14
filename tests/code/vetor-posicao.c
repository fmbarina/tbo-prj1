#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "vertex.h"

int main(void){
    Vertex* um = vertex_init(1, 1, 1);
    Vertex* dois = vertex_init(1, 2, 1);
    Vertex* tres = vertex_init(1, 3, 1);
    Vertex* quatro = vertex_init(1, 4, 1);
    Vertex* cinco = vertex_init(1, 5, 1);

    Vetor* vet = vetor_init(5);
    //printf("()\n");
    vetor_set_index(vet, um, 0);
    vetor_set_index(vet, dois, 1);
    vetor_set_index(vet, tres, 1);
    vetor_set_index(vet, quatro, 1);
    vetor_set_index(vet, cinco, 1);
    
    vetor_imprime(vet);

    vetor_libera(vet);
    vertex_free(um);
    vertex_free(dois);
    vertex_free(tres);
    vertex_free(quatro);
    vertex_free(cinco);

    return 0;
}