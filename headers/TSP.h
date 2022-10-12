#ifndef TSP_H_
#define TSP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"
// #include "vetorDistancia.h"
#include "arquivo.h"
#include "MST.h"

typedef struct tsp_st TSP;

/**
 * @brief Inicia a estrutura para guardar dados da TSP
 *
 * @param nome - char* nome da TSP
 * @param numVertices - int numero de vértices/posições da TSP
 * @return TSP* - a TSP em si
 */
TSP *TSP_init(char *nome, int numVertices);

/**
 * @brief Retorna o numero de vértices/posições da TSP
 *
 * @param t - TSP*
 * @return int - numero de vértices
 */
int TSP_get_nvertices(TSP *t);

/**
 * @brief Retorna o vetor de posições da TSP
 *
 * @param t - TSP*
 * @return Vetor* - Vetor de posições
 */
Vetor *TSP_get_vetor(TSP *t);

/**
 * @brief Preenvhe o vetor de posições da TSP com 
 *        a leitura do arquivo f.
 *
 * @param tsp - TSP* com o vetor a ser preenchido
 * @param f - Arquivo de entrada da TSP
 */
void TSP_preenche_vetor_pos(TSP *t, FILE* f);

/**
 * @brief Libera a memória alocada pela TSP
 * 
 * @param t - TSP*
 */
void TSP_libera(TSP*t);

/**
 * @brief Retorna o nome da TSP.
 * 
 * @param t - TSP*
 * @return char* - Seu nome 
 */
char* TSP_get_name(TSP*t);

/**
 * @brief Preenche o vetor de arestas da TSP
 *        utilizando o vetor de posições dela
 * 
 * @param t - TSP*
 */
void TSP_preenche_vetarestas(TSP*t);

#endif /* TSP_H_ */