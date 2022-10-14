#ifndef ARESTA_H_
#define ARESTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vertex.h"
#include "vetor.h"
#include "assertr.h"

typedef struct aresta_st Aresta;

struct aresta_st
{
    Vertex *a;
    Vertex *b;
    float dist;
};

Vertex *aresta_getA(Aresta aresta);

Vertex *aresta_getB(Aresta aresta);

float aresta_getDist(Aresta aresta);

/* ------------------------------------------------------------------------ */

typedef struct vetorAresta_st VetorAresta;

/**
 * @brief Aloca espaço para o Vetor de Arestas
 *        e já calcula as distancias entre as vértices 
 *        guardadas no Vetor de vértices.
 * 
 * @param posicoes - Vetor de vértices
 * @return VetorAresta* - Vetor de arestas com distâncias
 */
VetorAresta* vetoraresta_init(Vetor* posicoes);

/**
 * @brief Libera a memória alocada pelo vetor de Arestas.
 *        Libera aresta por aresta.
 * 
 * @param vetor - Vetor a ser liberado 
 */
void vetoraresta_free(VetorAresta* vetor);

/**
 * @brief Realiza o sort do Vetor de Arestas baseado nas
 *        distância entre as vértices
 * 
 * @param vetor - Vetor a ser organizado
 */
void vetoraresta_sort(VetorAresta* vetor);

Aresta vetoraresta_get_index(VetorAresta *vetor, int index);

/**
 * @brief Retorna a quantidade de Arestas presente no vetor
 * 
 * @param vetor - Vetor de arestas 
 * @return int - Quantidade de arestas
 */
long int vetoraresta_get_qtd(VetorAresta* vetor);

#endif /* ARESTA_H_ */