#ifndef VERTEX_H_
#define VERTEX_H_

typedef struct vertex_st Vertex;

/**
 * @brief Aloca espaço para uma posição da TSP.
 *
 * @param x - float
 * @param y - float
 * @return Vertex* - Struct alocada com x e y
 */
Vertex *vertex_init(long id, float x, float y);

/**
 * @brief Libera a memoria dinamicamente alocada para
 *        a posição atual
 *
 * @param vertice - Vértice a ser desalocada
 */
void vertex_free(Vertex *vertex);

/**
 * @brief Retorna o id da vertice no grafo
 *
 * @param vertice
 * @return long
 */
long vertex_getid(Vertex *vertex);

/**
 * @brief Retorna o x da posição
 *
 * @param vertice - Ponteiro para a vértice
 * @return float - Valor de x
 */
float vertex_getx(Vertex *vertex);

/**
 * @brief Retorna o y da posição
 *
 * @param vertice - Ponteiro para a vértice
 * @return float - Valor de y
 */
float vertex_gety(Vertex *vertex);

/**
 * @brief Calcula e retorna a distância euclidiana
 *        entre dois vértices.
 *
 * @param a - Vértice a
 * @param b - Vértice b
 * @return float - distancia euclidiana
 */
float vertex_dist(Vertex *a, Vertex *b);

/**
 * @brief Imprime a posição atual na saida padrão
 *
 * @param vertice - Vértice a ser impressa
 */
void vertex_print(Vertex *vertex);

/**
 * @brief Aloca um vetor de vértices
 *
 * @param qtd - Quantidade de vértices
 * @return Vertex* - Vetor de vértices
 */
Vertex *vertex_aloca_n(int qtd);

#endif /* VERTEX_H_ */