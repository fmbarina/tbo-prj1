#include "vertex.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct vertex_st
{
    long id;
    float x;
    float y;
};

Vertex *vertex_init(long id, float x, float y)
{
    Vertex *p = (Vertex *)malloc(sizeof(Vertex));
    p->id = id;
    p->x = x;
    p->y = y;
    return p;
}

void vertex_free(Vertex *vertex)
{
    free(vertex);
}

long vertex_getid(Vertex *vertex)
{
    return vertex->id;
}

float vertex_getx(Vertex *vertex)
{
    return vertex->x;
}

float vertex_gety(Vertex *vertex)
{
    return vertex->y;
}

float vertex_dist(Vertex *a, Vertex *b)
{
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

void vertex_print(Vertex *vertex)
{
    printf("(%.2f, %.2f)", vertex->x, vertex->y);
}

Vertex *vertex_aloca_n(int qtd)
{
    return malloc(qtd * sizeof(Vertex));
}