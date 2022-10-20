#include "vertex.h"

#include <math.h>
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

/* ------------------------------------------------------------------------ */

struct vertex_v_st
{
    Vertex **vertices;
    int len;
};

Vertex_v *vertex_v_init(int len)
{
    Vertex_v *v = (Vertex_v *)malloc(sizeof(Vertex_v));
    v->vertices = (Vertex **)malloc(len * sizeof(Vertex *));
    v->len = len;

    long i;
    for (i = 0; i < len; i++)
        v->vertices[i] = NULL;

    return v;
}

Vertex *vertex_v_get_index(Vertex_v *v, int index)
{
    return v->vertices[index];
}

void vertex_v_set_index(Vertex_v *v, Vertex *item, int index)
{
    // TODO: porque NULL primeiro?
    v->vertices[index] = NULL;
    v->vertices[index] = item;
}

int vertex_v_len(Vertex_v *v)
{
    return v->len;
}

void vertex_v_free(Vertex_v *v)
{
    long i;
    for (i = 0; i < v->len; i++)
        vertex_free(v->vertices[i]);
    free(v->vertices);
    free(v);
}