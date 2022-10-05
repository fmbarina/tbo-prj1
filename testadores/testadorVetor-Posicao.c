#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "posicao.h"

int main(void){
    Posicao* um = posicao_init(1,1);
    Posicao* dois = posicao_init(2,1);
    Posicao* tres = posicao_init(3,1);
    Posicao* quatro = posicao_init(4,1);
    Posicao* cinco = posicao_init(5,1);

    Vetor* vet = vetor_init(5);
    //printf("()\n");
    vetor_set_index(vet, um, 0);
    vetor_set_index(vet, dois, 1);
    vetor_set_index(vet, tres, 1);
    vetor_set_index(vet, quatro, 1);
    vetor_set_index(vet, cinco, 1);
    
    vetor_imprime(vet);

    vetor_libera(vet);
    liberaPosicao(um);
    liberaPosicao(dois);
    liberaPosicao(tres);
    liberaPosicao(quatro);
    liberaPosicao(cinco);
}