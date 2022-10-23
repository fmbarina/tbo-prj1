#ifndef VERTEX_H_
#define VERTEX_H_

#include "common.h"

typedef struct vertex_st Vertex;

/**
 * @brief Aloca a memoria para um vertice de um grafo, representando 
 * uma posicao em um plano euclidiano.
 *
 * @param ID ID do vertice no grafo.
 * @param x Valor da posicao X do vertice.
 * @param y Valor da posicao Y do vertice.
 * @return Vertex* Estrutura do vertice criado.
 */
Vertex *vertex_init(IDT id, float x, float y);

/**
 * @brief Libera a memoria alocada para um vertice.
 *
 * @param vertex Vértice a ser liberada.
 */
void vertex_free(Vertex *vertex);

/**
 * @brief Recupera o ID de um vertice.
 *
 * @param vertex Vertice.
 * @return IDT
 */
IDT vertex_getid(Vertex *vertex);

/**
 * @brief Retorna o valor X da posicao de um vertice.
 *
 * @param vertex Vertice.
 * @return float Valor X da posicao do vertice.
 */
float vertex_getx(Vertex *vertex);

/**
 * @brief Retorna o valor Y da posicao de um vertice.
 *
 * @param vertex Vertice.
 * @return float Valor Y da posicao do vertice.
 */
float vertex_gety(Vertex *vertex);

/**
 * @brief Calcula e retorna a distância euclidiana entre dois vertices.
 *
 * @param a Vértice A.
 * @param b Vértice B.
 * @return float Distancia entre os vertices A e B.
 */
float vertex_dist(Vertex *a, Vertex *b);

/* ------------------------------------------------------------------------ */

typedef struct vertex_v_st Vertex_v;

/**
 * @brief Aloca a memoria de um vetor de vertices.
 *
 * @param len Quantidade de vértices.
 * @return Vertex_v* Vetor de vértices alocado.
 */
Vertex_v *vertex_v_init(IDT len);

/**
 * @brief Libera a memória alocada para um vetor de vértices, liberando
 * também a memoria de cada um de seus vertices.
 *
 * @param v Vetor a ser liberado.
 */
void vertex_v_free(Vertex_v *v);

/**
 * @brief Recupera o vertice no dado index em um vetor de vertices.
 *
 * @param v Vetor de vertices.
 * @param index Indice do vertice no vetor.
 * @return Vertex* Vertice presente no vetor na posicao index.
 */
Vertex *vertex_v_get_index(Vertex_v *v, IDT index);

/**
 * @brief Define o vertice no dado index em um vetor de vertices.
 *
 * @param v Vetor de vertices.
 * @param item Vertice a definir no indice.
 * @param index Indice da posicao no vetor a definir.
 */
void vertex_v_set_index(Vertex_v *v, Vertex *item, IDT index);

/**
 * @brief Retorna o tamanho de um vetor de vertices. 
 *
 * @param v Vetor de vertices.
 * @return IDT Quantidade de elementos no vetor.
 */
IDT vertex_v_len(Vertex_v *v);

#endif /* VERTEX_H_ */