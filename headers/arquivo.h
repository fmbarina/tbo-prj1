#ifndef ARQUIVO_H_
#define ARQUIVO_H_

#include <stdio.h>

#include "posicao.h"

char *arq_le_dado(FILE *f);

void arq_pula_dado(FILE *f);

Posicao *arq_le_pos(FILE *f);

void *arq_esc_header(FILE *f, char* name, char* dim);

#endif /* ARQUIVO_H_ */