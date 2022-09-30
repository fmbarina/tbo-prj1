#ifndef VETOR_H
#define VETOR_H
#include "posicao.h"

typedef struct vetor Vetor;

Vetor* inicializaVetor(int qtd);

Posicao* GetIndexVetor(Vetor* vetor, int index);

void setIndexVetor(Vetor* vetor, Posicao* item, int index);

int qtdElementosVetor(Vetor* vetor);

void imprimeVetor(Vetor* vetor);

void liberaVetor(Vetor* vetor);

#endif