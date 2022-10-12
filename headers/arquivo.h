#ifndef ARQUIVO_H_
#define ARQUIVO_H_

#include <stdio.h>

#include "posicao.h"

/**
 * @brief Lê o arquivo e retorna o dado em string.
 * 
 * @param f - Arquivo a ser lido.
 * @return char* - Dado lido do arquivo.
 */
char *arq_le_dado(FILE *f);

/**
 * @brief Pula uma linha do arquivo (joga fora)
 * 
 * @param f - Arquivo
 */
void arq_pula_dado(FILE *f);

/**
 * @brief Le uma posição da TSP no arquivo.
 * 
 * @param f - Arquivo a ser lido
 * @return Posicao* - Ponteiro para a posição lida.
 */
Posicao *arq_le_pos(FILE *f);

/**
 * @brief Escreve o Cabeçalho dos arquivos de saida.
 * 
 * @param f - Arquivo a ser escrito
 * @param name - Nome
 * @param dim  - Tamanho
 */
void arq_esc_header(FILE *f, char* name, char* dim);

#endif /* ARQUIVO_H_ */