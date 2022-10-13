#ifndef MST_H_
#define MST_H_

#include "aresta.h"

typedef struct mst_st MST;

/**
 * @brief Aloca espaço para a arvore minima dentro também é alocado
 *        uma Quick Union Find e uma Matriz de adjacencias.
 * 
 * @param len - unsigned long int
 * @return MST* - minimal spanning tree
 */
MST* MST_init(unsigned long int len);

/**
 * @brief Libera o espaço alocado pela MST.
 * 
 * @param m - MST a ser desalocada
 */
void MST_libera(MST* m);

#endif /* MST_H_ */