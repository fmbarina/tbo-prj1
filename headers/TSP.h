#ifndef TSP_H_
#define TSP_H_

#include <stdlib.h>
#include <string.h>

#include "adj_matrix.h"
#include "file_op.h"
#include "tour.h"

typedef struct tsp_st TSP;

/**
 * @brief Inicia a estrutura para guardar dados de um TSP
 *
 * @param name Nome do TSP.
 * @param vertices Numero de vertices do TSP.
 * @return TSP* Estrutura do TSP criado.
 */
TSP *TSP_init(char *name, long vertices);

/**
 * @brief Libera a estrutura que guarda os dados de um TSP.
 *
 * @param t Estrutura TSP a liberar.
 */
void TSP_free(TSP *t);

/**
 * @brief Recupera o nome de um TSP.
 *
 * @param t TSP.
 * @return char* Nome recuperado.
 */
char *TSP_get_name(TSP *t);

/**
 * @brief Retorna o numero de vertices de um TSP.
 *
 * @param t TSP.
 * @return int Numero de vertices.
 */
long TSP_get_vertices(TSP *t);

/**
 * @brief Recupera a matriz de adjacencias de um TSP.
 * 
 * @param t TSP.
 * @return Adj_matrix* Matriz de adjacencias.
 */
Adj_matrix *TSP_get_adj_mat(TSP *t);

Tour *TSP_get_tour(TSP *t);

/**
 * @brief Preenvhe o vetor de vertices de um TSP com os vertices
 * lidos de um arquivo.
 *
 * @param tsp TSP.
 * @param f Arquivo de entrada com os vertices do TSP.
 */
void TSP_fill_vertices(TSP *t, FILE *f);

/**
 * @brief Preenche o vetor de arestas de um TSP utilizando seu vetor de 
 * vertices já preenchido.
 *
 * @param t TSP.
 */
void TSP_fill_edges(TSP *t);

/**
 * @brief Gera a MST (Minimum Spanning Tree) de um TSP usando o algoritmo
 * de kruskal.
 * 
 * @param t TSP.
 */
void TSP_kruskal(TSP *t);

/**
 * @brief Gera o Tour de um TSP por meio de uma DFS (Depth First Search).
 * 
 * @param t TSP.
 */
void TSP_tour(TSP *t);

#endif /* TSP_H_ */