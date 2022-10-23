#include "vertex.h"

#include <math.h>
#include <stdlib.h>

#include "common.h"

struct vertex_st
{
    IDT id;
    float x;
    float y;
};

Vertex *vertex_init(IDT id, float x, float y)
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

IDT vertex_getid(Vertex *vertex)
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
    IDT len;
};

Vertex_v *vertex_v_init(IDT len)
{
    Vertex_v *v = (Vertex_v *)malloc(sizeof(Vertex_v));
    v->vertices = (Vertex **)malloc(len * sizeof(Vertex *));
    v->len = len;

    IDT i;
    for (i = 0; i < len; i++)
        v->vertices[i] = NULL;

    return v;
}

void vertex_v_free(Vertex_v *v)
{
    IDT i;
    for (i = 0; i < v->len; i++)
        vertex_free(v->vertices[i]);
    free(v->vertices);
    free(v);
}

Vertex *vertex_v_get_index(Vertex_v *v, IDT index)
{
    return v->vertices[index];
}

void vertex_v_set_index(Vertex_v *v, Vertex *item, IDT index)
{
    v->vertices[index] = item;
}

IDT vertex_v_len(Vertex_v *v)
{
    return v->len;
}
