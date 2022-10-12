#ifndef POSICAO_H_
#define POSICAO_H_

typedef struct posicao_st Posicao;

/**
 * @brief Aloca espaço para uma posição da TSP.
 *
 * @param x - float
 * @param y - float
 * @return Posicao* - Struct alocada com x e y
 */
Posicao *posicao_init(float x, float y);

/**
 * @brief Retorna o x da posição
 *
 * @param posicao - Ponteiro para a posição
 * @return float - Valor de x
 */
float posicao_getx(Posicao *posicao);

/**
 * @brief Retorna o y da posição
 *
 * @param posicao - Ponteiro para a posição
 * @return float - Valor de y
 */
float posicao_gety(Posicao *posicao);

/**
 * @brief Calcula e retorna a distância euclidiana 
 *        entre duas posições.
 *        
 * @param a - Posição a
 * @param b - Posição b
 * @return float - distancia euclidiana
 */
float posicao_distancia(Posicao *a, Posicao *b);

/**
 * @brief Imprime a posição atual na saida padrão
 *
 * @param posicao - Posição a ser impressa
 */
void posicao_imprime(Posicao *posicao);

/**
 * @brief Libera a memoria dinamicamente alocada para
 *        a posição atual
 *
 * @param posicao - Posição aa ser desalocada
 */
void posicao_libera(Posicao *posicao);

/**
 * @brief Aloca um vetor de posições
 *
 * @param qtd - Quantidade de posições
 * @return Posicao* - Vetor de posições
 */
Posicao *posicao_aloca_n(int qtd);

#endif /* POSICAO_H_ */