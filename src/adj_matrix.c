#include "adj_matrix.h"

#include <stdlib.h>
#include "bytes.h"

/* Economizando linhas rs TODO: tem como fazer isso sem ext gcc? */
#define swap(x, y) __extension__({ unsigned long tmp = x; x = y; y = tmp; })

struct adj_matrix_st
{
    unsigned int size;
    Bytes *mat;
};

Adj_matrix *adj_mat_init(unsigned long size)
{
    Adj_matrix *mat = (Adj_matrix *)malloc(sizeof(struct adj_matrix_st));
    mat->mat = bytes_init(size * (size - 1) / 2);
    mat->size = size;
    return mat;
}

void adj_mat_free(Adj_matrix *mat)
{
    bytes_free(mat->mat);
    free(mat);
}

unsigned char adj_mat_get(Adj_matrix *mat, unsigned long i, unsigned long j)
{
    if (i == j) return 0;
    if (i > j) swap(i, j);

    unsigned char *vet = bytes_contents(mat->mat);
    /* pos = total columns * (line - 1) + (col - line) - 1 (diag)  */
    return vet[vet[0] * (i - 1) + (j - i) - 1];
}

void adj_mat_set(Adj_matrix *mat, unsigned long i, unsigned long j, unsigned char v)
{
    if (i == j) return;
    if (i > j) swap(i, j);

    unsigned char *vet = bytes_contents(mat->mat);
    /* pos = total columns * (line - 1) + (col - line) - 1 (diag)  */
    vet[vet[0] * (i - 1) + (j - i) - 1] = v;
}

void adj_mat_connect(Adj_matrix *mat, unsigned long i, unsigned long j)
{
    if (i == j) return;
    if (i > j) swap(i, j);

    if (!adj_mat_get(mat, i, j))
        adj_mat_set(mat, i, j, 1);
}