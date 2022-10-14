#ifndef ADJ_MATRIX_H_
#define ADJ_MATRIX_H_

#include "bytes.h"

typedef struct adj_matrix_st Adj_matrix;

Adj_matrix *adj_mat_init(long size);

void adj_mat_free(Adj_matrix *m);

void adj_mat_connect(Adj_matrix *m, long i, long j);

#endif /* ADJ_MATRIX_H_ */