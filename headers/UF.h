#ifndef UF_H_
#define UF_H_

#define CEL int

/* Weighted Quick Union com comp. de caminho */

typedef struct uf_st UF;

/**
 * @brief Aloca espaço para a Weighted Quick Union com
 *        compressão de caminho.
 *
 * @param size - Quantidade de "vértices"
 * @return UF* - W. Q. Union
 */
UF *UF_init(CEL size);

/**
 * @brief Libera a memória alocada para a W.Q.Union
 *
 * @param uf - Estrutura a ser desalocada
 */
void UF_free(UF *uf);

/**
 * @brief Union entre dois (duas) vértices (ou componentes conexas)
 *
 * @param uf - WQUnion
 * @param a  - Index da primeira vértice
 * @param b  - Index da segunda vértice
 */
void UF_union(UF *uf, CEL a, CEL b);

/**
 * @brief Retorna se dois vértices estão ou não conectados
 *
 * @param uf - Union
 * @param a - vértice a
 * @param b - vértice b
 * @return int - 0 caso seja falso, 1 caso contrário
 */
int UF_connected(UF *uf, CEL a, CEL b);

/**
 * @brief Retorna a componente conexa da vértice
 *
 * @param uf - Union
 * @param f - Vértice
 * @return CEL - Componente conexa da vértice f
 */
CEL UF_find(UF *uf, CEL f);

#endif /* UF_H_ */