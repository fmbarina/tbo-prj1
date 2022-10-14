#include "adj_matrix.h"

#include <stdlib.h>

#include "bytes.h"

// clang-format off
/* Economizando linhas rs / TODO: tem como fazer isso sem extensao do gcc? */
#define swap(x, y) __extension__({ long tmp = x; x = y; y = tmp; })
#define conv(s, i, j) (s * (i - 1) + j - i - 1)
// clang-format on

/* Using a vector to represent a diagonal matrix of size M x N, such that
 * matrix[i][j] = N * (i - 1) + (j - i) - 1
 * mat[line][col]->vec[idx] = columns * (line - 1) + (col - line) - 1 (diag)
 */

struct adj_matrix_st
{
    unsigned int size;
    Bytes *vet;
};

static unsigned char adj_mat_get(Adj_matrix *m, long i, long j)
{
    return bytes_get(m->vet, conv(m->size, i, j));
}

static void adj_mat_set(Adj_matrix *m, long i, long j, unsigned char v)
{
    bytes_set(m->vet, conv(m->size, i, j), v);
}

Adj_matrix *adj_mat_init(long size)
{
    Adj_matrix *m = (Adj_matrix *)malloc(sizeof(struct adj_matrix_st));
    m->vet = bytes_init(size * (size - 1) / 2);
    m->size = size;
    return m;
}

void adj_mat_free(Adj_matrix *m)
{
    bytes_free(m->vet);
    free(m);
}

void adj_mat_connect(Adj_matrix *m, long i, long j)
{
    if (i == j) return;
    if (i > j) swap(i, j);

    if (!adj_mat_get(m, i, j)) adj_mat_set(m, i, j, 1);
}