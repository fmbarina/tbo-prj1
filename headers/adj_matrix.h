#ifndef ADJ_MATRIX_H_
#define ADJ_MATRIX_H_

#include <stdio.h>

#include "common.h"

typedef struct adj_matrix_st Adj_matrix;

/**
 * @brief Aloca a memória de uma matriz de adjacencia.
 *
 * @param dim Dimensao da matriz, considerando uma matriz quadrada.
 * @return Adj_matrix* Ponteiro pra matriz de adjacencia criada
 */
Adj_matrix *adj_mat_init(IDT dim);

/**
 * @brief Libera a memória de uma matriz de adjacencia.
 *
 * @param m Matriz de adjacencia a ser liberada.
 */
void adj_mat_free(Adj_matrix *m);

/**
 * @brief Recupera o valor de uma posicao em uma matriz. Para valores i, j
 * iguais, o valor retornado e sempre zero.
 *
 * @param m Matriz onde recuperar o valor.
 * @param i Linha da matriz a recuperar, [0, n).
 * @param j Coluna da matriz a recuperar, [0, n).
 * @return double
 */
int adj_mat_get(Adj_matrix *m, IDT i, IDT j);

/**
 * @brief Define um valor de uma posicao em uma matriz. Para valores i, j
 * iguais, o valor e sempre zero e nao alteravel.
 *
 * @param m Matriz onde definir o valor.
 * @param i Linha da matriz a definir, [0, n).
 * @param j Coluna da matriz a definir, [0, n).
 * @param w Valor a definir.
 */
void adj_mat_set(Adj_matrix *m, IDT i, IDT j, int w);

/**
 * @brief Imprime em um arquivo as adjacencias de uma matriz.
 *
 * @param m Matriz a imprimir.
 * @param f Arquivo de saida para onde imprimir.
 */
void adj_mat_fprint(Adj_matrix *m, FILE *f);

#endif /* ADJ_MATRIX_H_ */