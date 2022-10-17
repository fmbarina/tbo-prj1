#ifndef ADJ_MATRIX_H_
#define ADJ_MATRIX_H_

#include <stdio.h>

typedef struct adj_matrix_st Adj_matrix;

Adj_matrix *adj_mat_init(long dim);

void adj_mat_free(Adj_matrix *m);

void adj_mat_connect(Adj_matrix *m, long i, long j, double w);

void adj_mat_fprint(Adj_matrix *m, FILE *f);

#endif /* ADJ_MATRIX_H_ */