#include <stdlib.h>
#include <stdio.h>

typedef struct vetorDistancia VetorDistancia;

/**
 * @brief Inicia vetor de distancias
 * 
 * @param tsp 
 * @return VetorDistancia* 
 */
VetorDistancia* vetordist_init(TSP* tsp);
