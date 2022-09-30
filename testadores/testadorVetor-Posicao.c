#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "posicao.h"

int main(void){
    Posicao* um = inicializaPosicao(1,1);
    Posicao* dois = inicializaPosicao(2,1);
    Posicao* tres = inicializaPosicao(3,1);
    Posicao* quatro = inicializaPosicao(4,1);
    Posicao* cinco = inicializaPosicao(5,1);

    Vetor* vet = inicializaVetor(5);
    //printf("()\n");
    setIndexVetor(vet, um, 0);
    setIndexVetor(vet, dois, 1);
    setIndexVetor(vet, tres, 1);
    setIndexVetor(vet, quatro, 1);
    setIndexVetor(vet, cinco, 1);
    
    imprimeVetor(vet);

    liberaVetor(vet);
    liberaPosicao(um);
    liberaPosicao(dois);
    liberaPosicao(tres);
    liberaPosicao(quatro);
    liberaPosicao(cinco);
}