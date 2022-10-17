#ifndef FILE_OP_H_
#define FILE_OP_H_

#include <stdio.h>

#include "vertex.h"

/**
 * @brief função para abrir arquivo
 *
 * @param argv
 * @return FILE*
 */
FILE *file_open(char *path, char *mode);

/**
 * @brief Lê o arquivo e retorna o dado em string.
 *
 * @param f - Arquivo a ser lido.
 * @return char* - Dado lido do arquivo.
 */
char *file_read_data(FILE *f);

/**
 * @brief Pula uma linha do arquivo (joga fora)
 *
 * @param f - Arquivo
 */
void file_skip_data(FILE *f);

/**
 * @brief Le uma posição da TSP no arquivo.
 *
 * @param f - Arquivo a ser lido
 * @return Vertex* - Ponteiro para a posição lida.
 */
Vertex *file_read_vertex(FILE *f);

/**
 * @brief Escreve o Cabeçalho dos arquivos de saida.
 *
 * @param f - Arquivo a ser escrito
 * @param name - Nome
 * @param dim  - Tamanho
 */
void file_write_template(FILE *f, char *name, char *dim, char *type);

#endif /* FILE_OP_H_ */