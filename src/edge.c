#include "edge.h"

#include "vertex.h"

static void edge_init(Vertex *a, Vertex *b, Edge *edge)
{
    edge->a = a;
    edge->b = b;
    edge->dist = vertex_dist(a, b);
}

Vertex *edge_geta(Edge *edge)
{
    return edge->a;
}

Vertex *edge_getb(Edge *edge)
{
    return edge->b;
}

float edge_getdist(Edge *edge)
{
    return edge->dist;
}

/* ------------------------------------------------------------------------ */

struct edge_v_st
{
    Edge *vet;
    long len;
};

Edge_v *edge_v_init(Vertex_v *vertices)
{
    Edge_v *edges = (Edge_v *)malloc(sizeof(Edge_v));

    // TODO: isso é uma pergunta?
    // quantidade de arestas eh uma PA: N(N-1)/2?
    int vert_len = vertex_v_len(vertices);
    edges->len = ((vert_len * (vert_len - 1)) / 2);
    edges->vet = (Edge *)malloc(sizeof(Edge) * edges->len);

    long i = 0, j = 0, k = 0;
    // inicializa as arestas da "Diagonal Principal pra cima"
    for (i = 0; i < vert_len; i++)
    {

        assertx(k < edges->len || i == vert_len - 1,
                "Index do vetor de aresta ultrapassou limite de linhas");

        for (j = i + 1; j < vert_len; j++)
        {
            assertx(k < edges->len,
                    "Index do vetor de aresta ultrapassou limite de colunas");
            /**
             * Nao eh possivel obter index do vetor de aresta de forma linear
             * ao vetor posicoes O k vai ser o index de cada vetor
             */

            edge_init(vertex_v_get_index(vertices, i),
                      vertex_v_get_index(vertices, j), ((edges->vet) + k));
            k++;
        }
    }

    return edges;
}

void edge_v_free(Edge_v *v)
{
    free(v->vet);
    free(v);
}

static int compare(const void *a, const void *b)
{
    /* Passa o que esta apontado por aresta
     * (passar como argumento o endereco da aresta)
     */
    if (((Edge *)a)->dist > ((Edge *)b)->dist) return 1;
    else if (((Edge *)a)->dist < ((Edge *)b)->dist) return -1;
    else return 0;
}

void edge_v_sort(Edge_v *v)
{
    qsort(v->vet, v->len, sizeof(Edge), compare);
}

Edge *edge_v_get_index(Edge_v *v, long index)
{
    return ((v->vet) + index);
}

long edge_v_len(Edge_v *v)
{
    return v->len;
}