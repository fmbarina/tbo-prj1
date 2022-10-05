#ifndef ASSERTR_H_
#define ASSERTR_H_

/**
 * @brief Retorna se condição é verdadeira.
 * Se for falsa, imprime um erro em stdout.
 *
 * @param cond Condição a ser verificada.
 * @param err Erro a ser impresso.
 * @return int Resultado de avaliação booleana de cond.
 */
int assertr(int cond, char *err);

/**
 * @brief Garante que condição é verdadeira.
 * Se for falsa, imprime um erro em stdout e termina o programa.
 *
 * @param cond Condição a ser verificada.
 * @param err Erro a ser impresso.
 */
void assertx(int cond, char *err);

#endif /* ASSERTR_H_ */