#include "../headers/posicao.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct posicao_st
{
    float x;
    float y;
};

Posicao *posicao_init(float x, float y)
{
    Posicao *p = (Posicao *)malloc(sizeof(Posicao));
    p->x = x;
    p->y = y;

    return p;
}

float posicao_getx(Posicao *posicao)
{
    return posicao->x;
}

float posicao_gety(Posicao *posicao)
{
    return posicao->y;
}

float posicao_distancia(Posicao *a, Posicao *b)
{
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

void posicao_imprime(Posicao *posicao)
{
    printf("(%.2f, %.2f)", posicao->x, posicao->y);
}

void posicao_libera(Posicao *posicao)
{
    free(posicao);
}

Posicao *posicao_aloca_n(int qtd)
{
    return malloc(qtd * sizeof(Posicao));
}