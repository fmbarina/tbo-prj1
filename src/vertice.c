#include "vertice.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct vertice_st
{
    unsigned long id;
    float x;
    float y;
};

Vertice *vertice_init(unsigned long id, float x, float y)
{
    Vertice *p = (Vertice *)malloc(sizeof(Vertice));
    p->id = id;
    p->x = x;
    p->y = y;
    return p;
}

unsigned long vertice_getid(Vertice *vertice)
{
    return vertice->id;
}

float vertice_getx(Vertice *vertice)
{
    return vertice->x;
}

float vertice_gety(Vertice *vertice)
{
    return vertice->y;
}

float vertice_dist(Vertice *a, Vertice *b)
{
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

void vertice_imprime(Vertice *vertice)
{
    printf("(%.2f, %.2f)", vertice->x, vertice->y);
}

void vertice_free(Vertice *vertice)
{
    free(vertice);
}

Vertice *vertice_aloca_n(int qtd)
{
    return malloc(qtd * sizeof(Vertice));
}