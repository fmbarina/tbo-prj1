#ifndef TSP_H_
#define TSP_H_

#include <stdlib.h>
#include <string.h>

#include "adj_matrix.h"
#include "file_op.h"
#include "tour.h"

typedef struct tsp_st TSP;

/**
 * @brief Inicia a estrutura para guardar dados da TSP
 *
 * @param name - char* nome da TSP
 * @param vertices - long numero de vértices da TSP
 * @return TSP* - a TSP em si
 */
TSP *TSP_init(char *name, long vertices);

/**
 * @brief Libera a memória alocada pela TSP
 *
 * @param t - TSP*
 */
void TSP_free(TSP *t);

/**
 * @brief Retorna o nome da TSP.
 *
 * @param t - TSP*
 * @return char* - Seu nome
 */
char *TSP_get_name(TSP *t);

/**
 * @brief Retorna o numero de vértices da TSP
 *
 * @param t - TSP*
 * @return int - numero de vértices
 */
long TSP_get_vertices(TSP *t);

Adj_matrix *TSP_get_adj_mat(TSP *t);

Tour *TSP_get_tour(TSP *t);

/**
 * @brief Preenvhe o vetor de vértices da TSP com
 *        a leitura do arquivo f.
 *
 * @param tsp - TSP* com o vetor a ser preenchido
 * @param f - Arquivo de entrada da TSP
 */
void TSP_fill_vertices(TSP *t, FILE *f);

/**
 * @brief Preenche o vetor de arestas da TSP
 * utilizando o vetor de vértices dela.
 *
 * @param t - TSP*
 */
void TSP_fill_edges(TSP *t);

void TSP_kruskal(TSP *t);

void TSP_tour(TSP *t);

#endif /* TSP_H_ */