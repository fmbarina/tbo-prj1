#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "posicao.h"

struct vetor{
    Posicao** itens;
    int qtd;
};

Vetor* inicializaVetor(int qtd){

    Vetor* vet = (Vetor*)malloc(sizeof(Vetor));
    vet->qtd = qtd;
    vet->itens =  (Posicao**)malloc(qtd*sizeof(Posicao*));

    int i;
    for(i = 0; i < qtd; i++){
        vet->itens[i] = NULL;
    }

    return vet;
}

Posicao* GetIndexVetor(Vetor* vetor, int index){
    return vetor->itens[index];
}

void setIndexVetor(Vetor* vetor, Posicao* item, int index){
    vetor->itens[index] = NULL;
    vetor->itens[index] = item;
}

int qtdElementosVetor(Vetor* vetor){
    return vetor->qtd;
}

void imprimeVetor(Vetor* vetor){
    for(int i = 0; i < vetor->qtd; i++){
        if(vetor->itens[i]){
            imprimePosicao(vetor->itens[i]);
            printf(" ");  
        }
    }
    printf("\n");
}
void liberaVetor(Vetor* vetor){
    free(vetor->itens);
    free(vetor);
}