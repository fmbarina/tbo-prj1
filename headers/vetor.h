#ifndef VETOR_H_
#define VETOR_H_

#include "vertice.h"

typedef struct vetor_st Vetor;

/**
 * @brief Aloca o vetor de Posições
 *
 * @param qtd - Quantidade de vértices
 * @return Vetor* - Vetor de vértices alocado
 */
Vetor *vetor_init(int qtd);

/**
 * @brief Retorna a posição do vetor de 
 *        acordo com o index
 *
 * @param vetor - Vetor de vértices 
 * @param index - index da posição desejada
 * @return Vertice* - Posição presente em vetor->itens[index]
 */
Vertice *vetor_get_index(Vetor *vetor, int index);

/**
 * @brief Muda a posição do index no vetor para a posição passada como
 *        parametro.
 *
 * @param vetor - Vetor de vértices a ser mudado
 * @param item - Item a ser colocado
 * @param index - Index do local no vetor
 */
void vetor_set_index(Vetor *vetor, Vertice *item, int index);

/**
 * @brief Retorna a quantidade de Elementos presente no vetor
 *        de poisções.
 *
 * @param vetor - Vetor de vértices
 * @return int - Quantidade de elementos alocados
 */
int vetor_qtd_elementos(Vetor *vetor);

/**
 * @brief Imprime todas as vértices no Vetor de vértices
 *
 * @param vetor - Vetor a ser impresso
 */
void vetor_imprime(Vetor *vetor);

/**
 * @brief Libera a memória alocada pelo vetor de vértices.
 *        Libera as vértices alocadas dentro dele também.
 *
 * @param vetor - Vetor a ser liberado
 */
void vetor_libera(Vetor *vetor);

#endif /* VETOR_H_ */