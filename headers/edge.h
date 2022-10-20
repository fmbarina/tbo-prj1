#ifndef EDGE_H_
#define EDGE_H_

#include <stdlib.h>
#include <string.h>

#include "assertx.h"
#include "vertex.h"

typedef struct edge_st Edge;

struct edge_st
{
    Vertex *a;
    Vertex *b;
    float dist;
};

Vertex *edge_geta(Edge *aresta);

Vertex *edge_getb(Edge *aresta);

float edge_getdist(Edge *aresta);

/* ------------------------------------------------------------------------ */

typedef struct edge_v_st Edge_v;

/**
 * @brief Aloca espaço para o Vetor de Arestas
 *        e já calcula as distancias entre as vértices
 *        guardadas no Vetor de vértices.
 *
 * @param posicoes - Vetor de vértices
 * @return Edge_v* - Vetor de arestas com distâncias
 */
Edge_v *edge_v_init(Vertex_v *posicoes);

/**
 * @brief Libera a memória alocada pelo vetor de Arestas.
 *        Libera aresta por aresta.
 *
 * @param vetor - Vetor a ser liberado
 */
void edge_v_free(Edge_v *v);

/**
 * @brief Realiza o sort do Vetor de Arestas baseado nas
 *        distância entre as vértices
 *
 * @param vetor - Vetor a ser organizado
 */
void edge_v_sort(Edge_v *v);

Edge *edge_v_get_index(Edge_v *v, long index);

long edge_v_len(Edge_v *v);

#endif /* EDGE_H_ */