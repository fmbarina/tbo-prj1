#ifndef TSP_H_
#define TSP_H_

#include <stdlib.h>
#include <stdio.h>
#include "vetor.h"

typedef struct tsp_st TSP;

/**
 * @brief Inicia a estrutura para guardar dados da TSP
 * 
 * @param nome - char*
 * @param numVertices - int
 * @return TSP* 
 */
TSP* TSP_init(char* nome, int numVertices);

/**
 * @brief 
 * 
 * @param t 
 * @return int 
 */
int TSP_get_nvertices(TSP* t);

/**
 * @brief 
 * 
 * @param t 
 * @return Vetor* 
 */
Vetor* TSP_get_vetor(TSP* t);

/**
 * @brief 
 * 
 * @param tsp 
 */
void TSP_preenche_vetor(TSP* tsp);

#endif /* TSP_H_ */