#ifndef VETOR_H_
#define VETOR_H_

#include "posicao.h"

typedef struct vetor_st Vetor;

/**
 * @brief
 *
 * @param qtd
 * @return Vetor*
 */
Vetor *vetor_init(int qtd);

/**
 * @brief
 *
 * @param vetor
 * @param index
 * @return Posicao*
 */
Posicao *vetor_get_index(Vetor *vetor, int index);

/**
 * @brief
 *
 * @param vetor
 * @param item
 * @param index
 */
void vetor_set_index(Vetor *vetor, Posicao *item, int index);

/**
 * @brief
 *
 * @param vetor
 * @return int
 */
int vetor_qtd_elementos(Vetor *vetor);

/**
 * @brief
 *
 * @param vetor
 */
void vetor_imprime(Vetor *vetor);

/**
 * @brief
 *
 * @param vetor
 */
void vetor_libera(Vetor *vetor);

#endif /* VETOR_H_ */