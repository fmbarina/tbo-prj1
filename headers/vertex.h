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
 * entre dois vértices.
 *
 * @param a - Vértice a
 * @param b - Vértice b
 * @return float - distancia euclidiana
 */
float vertex_dist(Vertex *a, Vertex *b);

/* ------------------------------------------------------------------------ */

typedef struct vertex_v_st Vertex_v;

/**
 * @brief Aloca o vetor de Posições
 *
 * @param len - Quantidade de vértices
 * @return Vertex_v* - Vetor de vértices alocado
 */
Vertex_v *vertex_v_init(int len);

/**
 * @brief Retorna a posição do vetor de
 *        acordo com o index
 *
 * @param vetor - Vetor de vértices
 * @param index - index da posição desejada
 * @return Vertex* - Posição presente em vetor->itens[index]
 */
Vertex *vertex_v_get_index(Vertex_v *v, int index);

/**
 * @brief Muda a posição do index no vetor para a posição passada como
 *        parametro.
 *
 * @param vetor - Vetor de vértices a ser mudado
 * @param item - Item a ser colocado
 * @param index - Index do local no vetor
 */
void vertex_v_set_index(Vertex_v *v, Vertex *item, int index);

/**
 * @brief Retorna a quantidade de Elementos presente no vetor
 * de posições.
 *
 * @param vetor - Vetor de vértices
 * @return int - Quantidade de elementos alocados
 */
int vertex_v_len(Vertex_v *v);

/**
 * @brief Libera a memória alocada pelo vetor de vértices.
 *        Libera as vértices alocadas dentro dele também.
 *
 * @param vetor - Vetor a ser liberado
 */
void vertex_v_free(Vertex_v *v);

#endif /* VERTEX_H_ */