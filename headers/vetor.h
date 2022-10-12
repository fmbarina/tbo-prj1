#ifndef VETOR_H_
#define VETOR_H_

#include "posicao.h"

typedef struct vetor_st Vetor;

/**
 * @brief Aloca o vetor de Posições
 *
 * @param qtd - Quantidade de posições
 * @return Vetor* - Vetor de posições alocado
 */
Vetor *vetor_init(int qtd);

/**
 * @brief Retorna a posição do vetor de 
 *        acordo com o index
 *
 * @param vetor - Vetor de posições 
 * @param index - index da posição desejada
 * @return Posicao* - Posição presente em vetor->itens[index]
 */
Posicao *vetor_get_index(Vetor *vetor, int index);

/**
 * @brief Muda a posição do index no vetor para a posição passada como
 *        parametro.
 *
 * @param vetor - Vetor de posições a ser mudado
 * @param item - Item a ser colocado
 * @param index - Index do local no vetor
 */
void vetor_set_index(Vetor *vetor, Posicao *item, int index);

/**
 * @brief Retorna a quantidade de Elementos presente no vetor
 *        de poisções.
 *
 * @param vetor - Vetor de posições
 * @return int - Quantidade de elementos alocados
 */
int vetor_qtd_elementos(Vetor *vetor);

/**
 * @brief Imprime todas as posições no Vetor de posições
 *
 * @param vetor - Vetor a ser impresso
 */
void vetor_imprime(Vetor *vetor);

/**
 * @brief Libera a memória alocada pelo vetor de posições.
 *        Libera as posições alocadas dentro dele também.
 *
 * @param vetor - Vetor a ser liberado
 */
void vetor_libera(Vetor *vetor);

#endif /* VETOR_H_ */