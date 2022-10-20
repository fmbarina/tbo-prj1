#ifndef TOUR_H_
#define TOUR_H_

#include <stdbool.h>

#include "adj_matrix.h"

typedef struct tour_st Tour;

/**
 * @brief Aloca a memoria de um Tour.
 * 
 * @param size Tamanho do tour a alocar (quantidade de vertices).
 * @return Tour* Tour alocado.
 */
Tour *tour_init(int size);

/**
 * @brief Libera a memoria de um tour.
 * 
 * @param t Tour a ser liberado.
 */
void tour_free(Tour *t);

/**
 * @brief Realiza o caminhamento de um grafo usando o algoritmo de 
 * Depth First Search recursivo, passando o grafo na forma de uma matriz
 * de adjacencias e o ID do vertice onde iniciar o caminhamento.
 * 
 * @param t Tour.
 * @param adj Matriz de adjacencias do grafo.
 * @param vertex_id ID do vertice de inicio.
 */
void tour_DFS(Tour *t, Adj_matrix *adj, int vertex_id);

/**
 * @brief Imprime em um arquivo o caminhamento do tour.
 * 
 * @param t Tour a imprimir.
 * @param f Arquivo de saida para onde imprimir.
 */
void tour_fprint(Tour *t, FILE *f);

#endif /* TOUR_H_ */