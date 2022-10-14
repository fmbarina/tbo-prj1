#ifndef ARESTA_H_
#define ARESTA_H_

#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vertice.h"
#include "vetor.h"
#include "assertr.h"


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
 * @brief Realiza o sort do Vetor de Arestas baseado nas
 *        distância entre as vértices
 * 
 * @param vetor - Vetor a ser organizado
 */
void vetoraresta_sort(VetorAresta* vetor);

/**
 * @brief Retorna a quantidade de Arestas presente no vetor
 * 
 * @param vetor - Vetor de arestas 
 * @return int - Quantidade de arestas
 */
unsigned long int vetoraresta_get_Qtd(VetorAresta* vetor);

/**
 * @brief Libera a memória alocada pelo vetor de Arestas.
 *        Libera aresta por aresta.
 * 
 * @param vetor - Vetor a ser liberado 
 */
void vetoraresta_libera(VetorAresta* vetor);

#endif /* ARESTA_H_ */