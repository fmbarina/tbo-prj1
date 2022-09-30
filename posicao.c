#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "posicao.h"

struct posicao{
    float x;
    float y;
};

Posicao* inicializaPosicao(float x, float y){
    Posicao* p = (Posicao*)malloc(sizeof(Posicao));
    p->x = x;
    p->y = y;

    return p;
}

float GetXPosicao(Posicao* posicao){
    return posicao->x;
}
float GetYPosicao(Posicao* posicao){
    return posicao->y;
}

float distanciaPosicao(Posicao* a, Posicao* b){
    return sqrt(pow( b->x - a->x, 2) + pow( b->y - a->y, 2)  );
}

void imprimePosicao(Posicao* posicao){
    printf("(%.2f,%.2f)", posicao->x, posicao->y);
}
void liberaPosicao(Posicao* posicao){
    free(posicao);
}

Posicao*  alocaNPosicoes(int qtd){
    return malloc(qtd*sizeof(Posicao));
}