#ifndef FILE_OP_H_
#define FILE_OP_H_

#include <stdio.h>

#include "vertex.h"

/**
 * @brief Funcoes auxiliares relacionadas a operacoes de arquivos 
 * para a resolucao do TSP.
 */

/**
 * @brief Abre um arquivo.
 *
 * @param path Caminho do arquivo.
 * @return FILE* Ponteiro do arquivo aberto.
 */
FILE *file_open(char *path, char *mode);

/**
 * @brief Le um dado de um arquivo no formato TSP <NOME_DADO: VALOR\n> e
 * retorna o valor lido em uma nova string alocada, newline nao incluso. 
 *
 * @param f Arquivo a ser lido.
 * @return char* Dado lido do arquivo.
 */
char *file_read_data(FILE *f);

/**
 * @brief Pula um dado do arquivo (pula uma linha, descartando o dado).
 *
 * @param f Arquivo.
 */
void file_skip_data(FILE *f);

/**
 * @brief Le um vertice de um arquivo no formato TSP <ID VALOR_X VALOR_Y\n> 
 * e aloca sua memoria, retornando o vertice ja criado.
 *
 * @param f Arquivo de onde ler o vertice.
 * @return Vertex* - Ponteiro para a posição lida.
 */
Vertex *file_read_vertex(FILE *f);

/**
 * @brief Escreve o cabecalho dos arquivos de saida do TSP (mst, tour).
 *
 * @param f Arquivo onde escrever o cabecalho.
 * @param name Nome do problema TSP.
 * @param dim Quantidade de elementos do problema TSP.
 */
void file_write_template(FILE *f, char *name, char *dim, char *type);

#endif /* FILE_OP_H_ */