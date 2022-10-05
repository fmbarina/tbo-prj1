#ifndef POSICAO_H_
#define POSICAO_H_

typedef struct posicao_st Posicao;

/**
 * @brief
 *
 * @param x
 * @param y
 * @return Posicao*
 */
Posicao *posicao_init(float x, float y);

/**
 * @brief
 *
 * @param posicao
 * @return float
 */
float posicao_getx(Posicao *posicao);

/**
 * @brief
 *
 * @param posicao
 * @return float
 */
float posicao_gety(Posicao *posicao);

/**
 * @brief
 *
 * @param a
 * @param b
 * @return float
 */
float posicao_distancia(Posicao *a, Posicao *b);

/**
 * @brief
 *
 * @param posicao
 */
void posicao_imprime(Posicao *posicao);

/**
 * @brief
 *
 * @param posicao
 */
void posicao_libera(Posicao *posicao);

/**
 * @brief
 *
 * @param qtd
 * @return Posicao*
 */
Posicao *posicao_aloca_n(int qtd);

#endif /* POSICAO_H_ */