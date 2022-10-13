#ifndef VERTICE_H_
#define VERTICE_H_

typedef struct vertice_st Vertice;

/**
 * @brief Aloca espaço para uma posição da TSP.
 *
 * @param x - float
 * @param y - float
 * @return Vertice* - Struct alocada com x e y
 */
Vertice *vertice_init(unsigned long id, float x, float y);

/**
 * @brief Retorna o id da vertice no grafo
 * 
 * @param vertice 
 * @return unsigned long 
 */
unsigned long vertice_getid(Vertice *vertice);

/**
 * @brief Retorna o x da posição
 *
 * @param vertice - Ponteiro para a vértice
 * @return float - Valor de x
 */
float vertice_getx(Vertice *vertice);

/**
 * @brief Retorna o y da posição
 *
 * @param vertice - Ponteiro para a vértice
 * @return float - Valor de y
 */
float vertice_gety(Vertice *vertice);

/**
 * @brief Calcula e retorna a distância euclidiana 
 *        entre dois vértices.
 *        
 * @param a - Vértice a
 * @param b - Vértice b
 * @return float - distancia euclidiana
 */
float vertice_dist(Vertice *a, Vertice *b);

/**
 * @brief Imprime a posição atual na saida padrão
 *
 * @param vertice - Vértice a ser impressa
 */
void vertice_imprime(Vertice *vertice);

/**
 * @brief Libera a memoria dinamicamente alocada para
 *        a posição atual
 *
 * @param vertice - Vértice a ser desalocada
 */
void vertice_free(Vertice *vertice);

/**
 * @brief Aloca um vetor de vértices
 *
 * @param qtd - Quantidade de vértices
 * @return Vertice* - Vetor de vértices
 */
Vertice *vertice_aloca_n(int qtd);

#endif /* VERTICE_H_ */