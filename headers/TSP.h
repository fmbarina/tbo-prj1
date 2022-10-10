#ifndef TSP_H_
#define TSP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"
#include "vetorDistancia.h"
#include "arquivo.h"
#include "MST.h"

typedef struct tsp_st TSP;

/**
 * @brief Inicia a estrutura para guardar dados da TSP
 *
 * @param nome - char*
 * @param numVertices - int
 * @return TSP*
 */
TSP *TSP_init(char *nome, int numVertices);

/**
 * @brief
 *
 * @param t
 * @return int
 */
int TSP_get_nvertices(TSP *t);

/**
 * @brief
 *
 * @param t
 * @return Vetor*
 */
Vetor *TSP_get_vetor(TSP *t);

/**
 * @brief
 *
 * @param tsp
 */
void TSP_preenche_vetor_pos(TSP *t, FILE* f);

/**
 * @brief 
 * 
 * @param t - TSP*
 */
void TSP_libera(TSP*t);

/**
 * @brief 
 * 
 * @param t 
 * @return char* 
 */
char* TSP_get_name(TSP*t);

/**
 * @brief 
 * 
 * @param t 
 */
void TSP_preenche_vetarestas(TSP*t);

#endif /* TSP_H_ */