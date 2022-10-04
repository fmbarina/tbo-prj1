#ifndef VETORDISTANCIA_H_
#define VETORDISTANCIA_H_

#include <stdlib.h>
#include <stdio.h>
#include "TSP.h"

typedef struct vetorDistancia_st VetorDistancia;

/**
 * @brief Inicia vetor de distancias
 *
 * @param tsp
 * @return VetorDistancia*
 */
VetorDistancia *vetordist_init(TSP *tsp);

#endif /* VETORDISTANCIA_H_ */