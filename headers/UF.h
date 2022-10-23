#ifndef UF_H_
#define UF_H_

#define UF_CEL int

/**
 * @brief Weighted Quick Union com compressao de caminho.
 *
 */

typedef struct uf_st UF;

/**
 * @brief Aloca a memória de um UF.
 *
 * @param size Quantidade de elementos.
 * @return UF* Union Find criado.
 */
UF *UF_init(UF_CEL size);

/**
 * @brief Libera a memória de um UF.
 *
 * @param uf Estrutura UF a ser liberada.
 */
void UF_free(UF *uf);

/**
 * @brief Realiza a Union entre dois elementos/componentes conexas de um UF.
 *
 * @param uf UF.
 * @param a Index do primeiro elemento.
 * @param b Index do segundo elemento.
 */
void UF_union(UF *uf, UF_CEL a, UF_CEL b);

/**
 * @brief Retorna se dois elementos de um UF estão conectados.
 *
 * @param uf UF.
 * @param a Index do primeiro elemento.
 * @param b Index do segundo elemento.
 * @return int Verdadeiro (1) se estao conectados, falso (0) caso contrario.
 */
int UF_connected(UF *uf, UF_CEL a, UF_CEL b);

/**
 * @brief Recupera a componente conexa de um elemento de um UF.
 *
 * @param uf UF.
 * @param f Index do elemento.
 * @return num Componente conexa do elemento f.
 */
UF_CEL UF_find(UF *uf, UF_CEL f);

#endif /* UF_H_ */