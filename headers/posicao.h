#ifndef POSICAO_H
#define POSICAO_H

typedef struct posicao Posicao;

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @return Posicao* 
 */
Posicao* posicao_init(float x, float y);

/**
 * @brief 
 * 
 * @param posicao 
 * @return float 
 */
float posicao_getx(Posicao* posicao);

/**
 * @brief 
 * 
 * @param posicao 
 * @return float 
 */
float posicao_gety(Posicao* posicao);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return float 
 */
float posicao_distancia(Posicao* a, Posicao* b);

/**
 * @brief 
 * 
 * @param posicao 
 */
void posicao_imprime(Posicao* posicao);

/**
 * @brief 
 * 
 * @param posicao 
 */
void posicao_libera(Posicao* posicao);

/**
 * @brief 
 * 
 * @param qtd 
 * @return Posicao* 
 */
Posicao*  posicao_aloca_n(int qtd);
#endif