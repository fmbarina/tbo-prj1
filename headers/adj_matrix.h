#ifndef ADJ_MATRIX_H_
#define ADJ_MATRIX_H_

#include "bytes.h"

typedef struct adj_matrix_st Adj_matrix;

Adj_matrix *adj_mat_init(unsigned long size);

void adj_mat_free(Adj_matrix *mat);

unsigned char adj_mat_get(Adj_matrix *mat, unsigned long i, unsigned long j);

void adj_mat_set(Adj_matrix *mat, unsigned long i, unsigned long j, unsigned char v);

#endif /* ADJ_MATRIX_H_ */