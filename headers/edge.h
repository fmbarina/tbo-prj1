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

/**
 * @brief Recupera o vertice A de uma aresta.
 * 
 * @param edge Aresta.
 * @return Vertex* Vertice A recuperado.
 */
Vertex *edge_geta(Edge *edge);

/**
 * @brief Recupera o vertice B de uma aresta.
 * 
 * @param edge Aresta.
 * @return Vertex* Vertice B recuperado.
 */
Vertex *edge_getb(Edge *edge);

/**
 * @brief Recupera a distancia entre os vertices de uma aresta.
 * 
 * @param edge Aresta.
 * @return float Distancia entre seus vertices.
 */
float edge_getdist(Edge *edge);

/* ------------------------------------------------------------------------ */

typedef struct edge_v_st Edge_v;

/**
 * @brief Aloca espaço para um vetor de arestas, já calculando as
 * distancias entre vertices e o preenchendo.
 *
 * @param vertices Vetor de vertices.
 * @return Edge_v* Vetor de arestas com distancias.
 */
Edge_v *edge_v_init(Vertex_v *vertices);

/**
 * @brief Libera toda a memória de um vetor de arestas, incluindo
 * cada uma de suas arestas.
 *
 * @param v Vetor a ser liberado.
 */
void edge_v_free(Edge_v *v);

/**
 * @brief Ordena um vetor de arestas de forma crescente, usando
 * as distancias entre vertices das arestas.
 *
 * @param v Vetor a ser ordenado.
 */
void edge_v_sort(Edge_v *v);

/**
 * @brief Recupera uma aresta de um vetor de arestas.
 * 
 * @param v Vetor de arestas.
 * @param index Indice da aresta a se recuperar.
 * @return Edge* Aresta recuperada.
 */
Edge *edge_v_get_index(Edge_v *v, long index);

/**
 * @brief Retorna o tamanho de um vetor de arestas. 
 * 
 * @param v Vetor de arestas.
 * @return long Quantidade de arestas no vetor.
 */
long edge_v_len(Edge_v *v);

#endif /* EDGE_H_ */