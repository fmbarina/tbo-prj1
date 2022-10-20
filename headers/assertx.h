#ifndef ASSERTX_H_
#define ASSERTX_H_

/**
 * @brief Garante que condição é verdadeira.
 * Se for falsa, imprime um erro em stdout e termina o programa.
 *
 * @param cond Condição a ser verificada.
 * @param err Erro a ser impresso.
 */
void assertx(int cond, char *err);

#endif /* ASSERTX_H_ */